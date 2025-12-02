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

takeHalf :: Int -> String -> String
takeHalf k x | d == 0 = "0"
             | otherwise = take (d + k*m) x
           where n = length(x)
                 (d,m) = n `divMod` 2

double :: Int -> Int
double x = read ((show x) ++ (show x)) :: Int

palindromes :: (Int,Int) -> [Int]
palindromes (x,y) = [double z | z <- [min..max], p (double z)]
                  where (w,v) = (show x, show y)
                        halfw = read (takeHalf 0 w) :: Int
                        halfv = (read (takeHalf 1 v) :: Int) + 1
                        min = minimum [halfw, halfv]
                        max = maximum [halfw, halfv]
                        p z = (z <= y) && (z >= x)

day02 :: FilePath -> IO()
day02 file = do
        xs <- readFile file
        putStr ((show . sum . concat . (map palindromes) . (map (pairStrToInt . converter)) . (wordsWhen (==','))) xs)
