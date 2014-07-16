main = print e001



isMultipleOf x y = x `mod` y == 0

sumOfMultiplesOf3And5 range = sum [ x | x <- range, x `isMultipleOf` 3 || x `isMultipleOf` 5]

e001 = sumOfMultiplesOf3And5 [1..999]