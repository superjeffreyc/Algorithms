
/*
 * https://leetcode.com/problems/rotate-array/ 
 */

import java.util.Arrays;

public class RotateArray {
	public static void main(String[] args) {
		int[] nums = { 1, 2, 3, 4, 5, 6, 7 };
		rotate(nums, 3);
	}

	/*
	 * This function takes O(n) space and O(n) time
	 */
	public static void rotate(int[] nums, int k) {
		int[] array = new int[nums.length];
		int j = 0;

		for (int i = k; i < nums.length; i++) {
			array[i] = nums[j];
			j++;
		}

		for (int i = 0; i < k; i++) {
			array[i] = nums[j];
			j++;
		}

		System.out.println(Arrays.toString(array));
	}

	// TODO: O(1) space and O(nk) time
	// TODO: O(1) space and O(n) time

}