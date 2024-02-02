class TwoSumFinder:
    def find_indices(self, numbers, target):
        num_dict = {} 

        for i, num in enumerate(numbers):
            complement = target - num

            if complement in num_dict:
                return num_dict[complement], i
            else:
                num_dict[num] = i

        return None 

numbers = [10, 20, 10, 40, 50, 60, 70]
target = 50

two_sum_finder = TwoSumFinder()
result = two_sum_finder.find_indices(numbers, target)

if result:
    print(f"Output: {result[0]}, {result[1]}")
else:
    print("No pair found.")
