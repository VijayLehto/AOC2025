solve :: [String] -> Int
solve input = solveRec input 50 0

solveRec :: [String] -> Int -> Int -> Int
solveRec [] start answer = answer
solveRec (x:xs) start answer | newStart == 0 = solveRec xs newStart (answer + 1)
                             | otherwise = solveRec xs newStart answer
        where newStart = (start + f x) `mod` 100
              f :: String -> Int
              f ('L':xs) = (-1) * (read xs :: Int)
              f ('R':xs) = (read xs :: Int)

day01 :: FilePath -> IO()
day01 file = do
		xs <- readFile file
		putStr ((show . solve . lines) xs)
