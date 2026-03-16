import pytest

from problems.recursive.mix_recursive_problems import binarySearch


@pytest.mark.parametrize(
    "needle, arr, expected",
    [
        # Empty array
        (1, [], -1),
        # Single element - match
        (1, [1], 0),
        # Single element - no match
        (2, [1], -1),
        # Two elements - first position
        (1, [1, 2], 0),
        # Two elements - second position
        (2, [1, 2], 1),
        # Not found - below minimum
        (0, [1, 2, 3, 4, 5], -1),
        # # Not found - above maximum
        (6, [1, 2, 3, 4, 5], -1),
        # Not found - in middle of range
        (7, [1, 2, 3, 9, 10], -1),
        # Found - first element
        (1, [1, 2, 3, 4, 5], 0),
        # Found - last element
        (5, [1, 2, 3, 4, 5], 4),
        # Found - exact middle (odd length)
        (3, [1, 2, 3, 4, 5], 2),
        # Found - one of centers (even length)
        (3, [1, 2, 3, 4], 2),
    ],
)
def test_binary_search_basic_extremes(needle, arr, expected):
    """Test basic edge cases for binary search: empty arrays, single elements,
    elements at boundaries, and middle positions."""
    assert binarySearch(needle, arr) == expected


def test_binary_search_with_custom_bounds_full_range():
    """Test binary search with explicit full range bounds."""
    arr = [1, 2, 3, 4, 5]
    assert binarySearch(3, arr, left=0, right=len(arr) - 1) == 2


def test_binary_search_with_custom_bounds_left_half():
    """Test search in left half only - target outside bounds."""
    arr = [1, 2, 3, 4, 5]
    assert binarySearch(4, arr, left=0, right=2) == -1


def test_binary_search_with_custom_bounds_right_half():
    """Test search in right half only - both miss and hit cases."""
    arr = [1, 2, 3, 4, 5]
    assert binarySearch(2, arr, left=2, right=4) == -1  # below left bound
    assert binarySearch(4, arr, left=2, right=4) == 3  # found in range
