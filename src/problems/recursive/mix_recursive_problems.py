def binarySearch(needle: int, arr: list[int], left=None, right=None) -> int:
    if arr is None or len(arr) == 0:
        return -1
    if left is None:
        left = 0
    if right is None:
        right = len(arr) - 1

    if left > right:
        return -1

    mid = (left + right) // 2

    if needle == arr[mid]:
        return mid
    elif needle < arr[mid]:
        return binarySearch(needle, arr, left, mid - 1)
    elif needle > arr[mid]:
        return binarySearch(needle, arr, mid + 1, right)
