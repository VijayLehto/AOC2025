import Data.List

converter :: String -> (String,String)
converter (x:xs) | x == '-' = ("",xs)
                 | otherwise = (x:fst new, snd new)
                 where new = converter xs

pairStrToInt :: (String,String) -> (Int,Int)
pairStrToInt (x,y) = (read x :: Int, read y :: Int)

wordsWhen :: (Char -> Bool) -> String -> [String]
wordsWhen p s =  case dropWhile p s of
                      "" -> []
                      s' -> w : wordsWhen p s''
                            where (w, s'') = break p s'

isPalindrome :: Int -> Bool
isPalindrome x = take halfn str == drop halfn str
                where str = show x
                      n = length(str)
                      halfn = n `div` 2

takeNth :: Int -> Int -> String -> String
takeNth n k x | d == 0 = "0"
              | otherwise = take (d + k) x
           where l = length(x)
                 (d,m) = l `divMod` n

repeated :: Int -> Int -> Int
repeated 1 x = x
repeated n x = read ((show x) ++ (show (repeated (n-1) x))) :: Int

kPalindromes :: Int -> (Int,Int) -> [Int]
kPalindromes n (x,y) = [repeated n z | z <- [min..max], p (repeated n z)]
                  where (w,v) = (show x, show y)
                        nw = read (takeNth n 0 w) :: Int
                        nv = (read (takeNth n 1 v) :: Int) + 1
                        min = minimum [nw, nv]
                        max = maximum [nw, nv]
                        p z = (z <= y) && (z >= x)

palindromes :: (Int,Int) -> [Int]
palindromes (x,y) = (nub . concat) [kPalindromes k (x,y) | k <-[2..n]]
                where n = length (show y)

day02 :: FilePath -> IO()
day02 file = do
        xs <- readFile file
        putStr ((show . sum . concat . (map (palindromes)) . (map (pairStrToInt . converter)) . (wordsWhen (==','))) xs)
