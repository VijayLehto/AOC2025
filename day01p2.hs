solve :: [String] -> Int
solve input = solveRec input 50 0

solveRec :: [String] -> Int -> Int -> Int
solveRec [] start answer = answer
solveRec (x:xs) start answer = solveRec xs newStart (answer + count)
        where newStart = (start + f x) `mod` 100
              f :: String -> Int
              f ('L':xs) = (-1) * (read xs :: Int)
              f ('R':xs) = (read xs :: Int)
              passOnce | (r == 0) || (start == 0) || (d == 0) = 0
                       | ((newStart > start) /= (f x > 0)) || (newStart == 0) = 1
                       | otherwise = 0
              count = (abs d) + passOnce
              (d,r) = ((f x) `quot` 100, (f x) `mod` 100)

day01p2 :: FilePath -> IO()
day01p2 file = do
		xs <- readFile file
		putStr ((show . solve . lines) xs)
