/*
input: an array of integers, a target sum, and a result array of 2 elements

output: boolean value to see if two numbers in the given integer array add up to the target sum, if yes, store the numbers pair in the result array

sort:

    mergesort

    split the integer array in two equal parts, recursively until the array contain only one element
        base case: when the length of array is 1:
            return the array

            mid point of the array length//2
            L side is beginning to mid
            R side is mid to end

            sort both the L and R
            merge the sorted L and R with a merge helper function
            return the merged array

    merge function:
        create a merged list
        idx1 set to 0
        inx2 set to 0

        while both of the indexes are smaller than the length of our lists
            compare L list at index 0 to R list at indx 0
                if L list is smaller:
                    add the number at the left[idx2] to merged
                    we + 1 to idx1
                else 
                    add the number at the right[idx2]
                    we + 1 to idx2
        check for the remaining length of the list, 
            append current index to end to our merged list

twosum:
    given a sorted list of numbers
    
    create a difference hash set `diff`

    iterate through the numbers
        see if the number is in `diff`, if its not
            find the difference between the number and the target
            add the difference to `diff
        if it is in `diff`
            store the (target - current `diff` number, `diff` number) in to `result`
    
    return False
*/