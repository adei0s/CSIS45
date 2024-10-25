/*
input: array of integers, target sum, result array

sort the input array, find there are two numbers in the array that add up to the target sum

output: bool indicating if a pair is found, and edit result array in place with the two numbers


sort:
    mergesort

    split the array into two equal parts, recursively until the subarray contain only one element
        base case: when subarray has size of one
            return the sub array

            find the mid point of array
            create L side subarray that is from beggining to mid
            R side array is from mid to end

        merge two sorted subarray into one array using a merge helper function

    merge helper function:
        given two sorted arrays, merge into one

        set index 1 to 0
        set index 2 to 0
        and create the result array `merged`

        while both indexes are less than length of their array
            compare arr1 and arr2 at idx 0:
                whichever's smaller, add the number to `merged`
                increase corresponding index +1
        append the remaining array to `merged`

twosum:

    hash set `diff`

    iterate through the numbers array
        for each num:
            find the difference between the num and the target sum.
            see if that difference is in my `diff` set
            if it is:
                my result is the diff number, current number
                modify given `result` array with the two numbers
    if it reaches the end:
        return False
*/

//mergesort: