import Data.List

solve :: [String] -> [Int]
solve input = ((map (solver 12)) . (map (map num))) input

solver :: Int -> [Int] -> Int
solver 1 [y] = y
solver 1 (y:ys) = max y (solver 1 ys)
solver x ys = max*10^(x-1) + solver (x-1) zs 
             where max = maximum (take (length ys - x + 1) ys)
                   zs = tail (dropWhile (/=max) ys)

f :: [Int] -> Int -> (Int,Int)
f [x] k = (x,k)
f (y:ys) k | y >= fst (f ys (k+1)) = (y,k)
           | otherwise = f ys (k+1)

num :: Char -> Int
num x = read [x] :: Int

day03p2 :: FilePath -> IO()
day03p2 file = do
                xs <- readFile file
                putStr ((show . sum . solve . lines) xs)
