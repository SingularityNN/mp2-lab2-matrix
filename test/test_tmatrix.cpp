#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> b(a);
	ASSERT_TRUE(b == a);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> b(a);
	ASSERT_TRUE(&a != &b);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> a(3);
	ASSERT_NO_THROW(a.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> a(3);
	a[0][0] = 1;
	ASSERT_EQ(1, a[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> a(3);
	ASSERT_ANY_THROW(a[0].at(-1));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> a(3);
	ASSERT_ANY_THROW(a[0].at(5));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> a(3);
	ASSERT_NO_THROW(a = a);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> b(3);
	ASSERT_NO_THROW(a = b);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> b(2);
	a = b;
	ASSERT_EQ(a.size(), b.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> b(2);
	ASSERT_NO_THROW(a = b);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> b(3);
	a[0][0] = 1;
	b[0][0] = 1;
	ASSERT_TRUE(a == b);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> a(3);
	ASSERT_TRUE(a == a);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> b(2);
	ASSERT_FALSE(a == b);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> b(3);
	ASSERT_NO_THROW(a = a + b);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> b(2);
	ASSERT_ANY_THROW(a = a + b);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> b(3);
	ASSERT_NO_THROW(a = a - b);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> b(2);
	ASSERT_ANY_THROW(a = a - b);
}

