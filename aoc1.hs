import Data.List (words)
import Data.List (sort)

separateLists :: [(Int, Int)] -> ([Int], [Int])
separateLists = unzip

parseLines :: String -> (Int, Int)
parseLines line = 
            let [x, y] = map read (words line)  
            in (x, y)

calculateDistance :: [Int] -> [Int] -> Int
calculateDistance list1 list2 = sum $ zipWith distance (sort list1) (sort list2)
  where
    distance x y = abs (x - y)

countInList :: Int -> [Int] -> Int
countInList x list = length (filter (==x) list)

similarity :: [Int] -> [Int] -> Int
similarity list1 list2 = sum $ map (\x -> x * countInList x list2) list1

main :: IO ()
main = do
  -- contents <- readFile "test.txt"
  contents <- readFile "input/input1.txt"

  let pairs = map parseLines (lines contents)

  let (list1, list2) = separateLists pairs

  let result = calculateDistance list1 list2
  
  putStrLn $ "Distance: " ++ show result  

  let result = similarity list1 list2
  
  putStrLn $ "Similarity: " ++ show result
