#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> mt(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(3);
	TMatrix<int> m1(m);
	EXPECT_EQ(m, m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m;
	TMatrix<int> m1(m);
	EXPECT_EQ(0, &m == &m1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(3);
	EXPECT_EQ(3, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(3);
	m[1][1] = 1;
	m[1][2] = 2;
	int tmp = m[1][2];
	EXPECT_EQ(m[1][1], 1);
	EXPECT_EQ(tmp, 2);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(3);
	ASSERT_ANY_THROW(m[-1][1] = 1);
	ASSERT_ANY_THROW(m[1][-1] = 1);
	ASSERT_ANY_THROW(m[-1][-1] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(3);
	ASSERT_ANY_THROW(m[100][1] = 1);
	ASSERT_ANY_THROW(m[1][100] = 1);
	ASSERT_ANY_THROW(m[100][100] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> mt(3);
	ASSERT_NO_THROW(mt = mt);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> mt(3);
	TMatrix<int> mt1(3);
	ASSERT_NO_THROW(mt = mt1);
	mt = mt1;
	EXPECT_EQ(mt, mt1);
}

TEST(TMatrix, assign_operator_changes_matrix_size)
{
	TMatrix<int> mt(3);
	TMatrix<int> mt1(5);
	mt = mt1;
	EXPECT_EQ(mt.GetSize(), mt1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> mt(3);
	TMatrix<int> mt1(5);
	ASSERT_NO_THROW(mt = mt1);
	mt = mt1;
	EXPECT_EQ(mt, mt1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> mt(3);
	TMatrix<int> mt1(3);
	for (int i = 0; i < mt.GetSize(); i++)
	{
		for (int j = i; j < mt.GetSize(); j++)
		{
			mt[i][j] = 1;
			mt1[i][j] = 1;
		}
	}
	EXPECT_EQ(1, mt == mt1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> mt(3);
	EXPECT_EQ(1, mt == mt);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> mt(3);
	TMatrix<int> mt1(5);
	EXPECT_EQ(0, mt == mt1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> mt(3);
	TMatrix<int> mt1(3);
	TMatrix<int> mt2(3);
	TMatrix<int> mt_res(3);
	for (int i = 0; i < mt.GetSize(); i++)
	{
		for (int j = i; j < mt.GetSize(); j++)
		{
			mt[i][j] = 1;
			mt1[i][j] = 1;
			mt_res[i][j] = 2;
		}
	}
	ASSERT_NO_THROW(mt + mt1);
	mt2 = mt + mt1;
	EXPECT_EQ(mt2, mt_res);

}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> mt(3);
	TMatrix<int> mt1(5);
	ASSERT_ANY_THROW(mt + mt1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> mt(3);
	TMatrix<int> mt1(3);
	TMatrix<int> mt2(3);
	TMatrix<int> mt_res(3);
	for (int i = 0; i < mt.GetSize(); i++)
	{
		for (int j = i; j < mt.GetSize(); j++)
		{
			mt[i][j] = 2;
			mt1[i][j] = 1;
			mt_res[i][j] = 1;
		}
	}
	ASSERT_NO_THROW(mt - mt1);
	mt2 = mt - mt1;
	EXPECT_EQ(mt2, mt_res);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> mt(3);
	TMatrix<int> mt1(5);
	ASSERT_ANY_THROW(mt - mt1);
}

