solve :: [String] -> [Int]
solve input = ((map (solver 12)) . (map (map num))) input

solver :: Int -> [Int] -> Int
solver 1 [y] = y
solver 1 (y:ys) = max y (solver 1 ys)
solver x (y:ys) | x > n = 0
                | x == n = y*10^(x-1) + solver (x-1) ys
                | otherwise = max ((solver (x-1) ys) + y*10^(x-1))  (solver x ys)
                where n = length (y:ys)

num :: Char -> Int
num x = read [x] :: Int

day03 :: FilePath -> IO()
day03 file = do
		xs <- readFile file
		putStr ((show . sum . solve . lines) xs)
