/*
most_frequent_element_from_array -- this program perform quick sort of the given array
in the array and it's frequency
Copyright (C) <2016>  <Elena Filenko>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <iostream>

using namespace std;

///
/// Quick sort implementation with pivot as a middle of the array
///

///
/// \brief partition
/// \param array -- pointer to the the array
/// \param beg -- index where array begins
/// \param end -- index where array ends
/// \return
///
int partition( int* array, int beg, int end )
{
    int i = beg;
    int j = end;
    int pivot = array[ (i + j )/2 ];

    while( i <= j )
    {
        while( array[ i ] <= pivot )
            ++i;

        while( array[ j ] > pivot )
            --j;

        if( i < j )
        {
            int tmp = array[ j ];
            array[ j ] = array[ i ];
            array[ i ] = tmp;
            ++i;
            --j;
        }
    }
}

///
/// \brief quick_sort
/// \param array -- pointer to the the array
/// \param beg -- index where array begins
/// \param end -- index where array ends
///
void quick_sort( int* array, int beg, int end )
{
    int i = beg;
    int j = end;
    int pivot = array[ ( beg + end)/2 ];


    do
    {
        while( (array[ i ] < pivot ) && ( i < end ) )
            ++i;

        while( (array[ j ] > pivot) && ( j > beg) )
            --j;

        if( i <= j )
        {
            int tmp = array[ j ];
            array[ j ] = array[ i ];
            array[ i ] = tmp;
            ++i;
            --j;
        }

    } while( i <= j );


    if( beg < j )
        quick_sort( array, beg, j );
    if( i < end )
        quick_sort( array, i, end );
}



int main(int argc, char *argv[])
{
    // Test 1
    int array_1[ 20 ] = { 2, -1, 9, 0, 34, 11, 7, 12, 2, -5,
                        1, 4, -10, 11, 2, 3, 5, -2, -7, 0 };

    quick_sort( array_1, 0, 19 );

    for( int i = 0; i < 20; i++ )
        cout << array_1[ i ] << ",  ";
    cout << endl << endl;


    // Test 2
    int array_2[ 10 ] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    quick_sort( array_2, 0, 9 );

    for( int i = 0; i < 9; i++ )
        cout << array_2[ i ] << ",  ";
    cout << endl << endl;

    // Test 3
    int array_3[ 2 ] = { -20, -40 };

    quick_sort( array_3, 0, 1 );

    for( int i = 0; i < 2; i++ )
        cout << array_3[ i ] << ",  ";
    cout << endl << endl;

    // Test 4
    int array_4[ 1 ] = { -20 };

    quick_sort( array_4, 0, 0 );

    for( int i = 0; i < 1; i++ )
        cout << array_4[ i ] << ",  ";
    cout << endl << endl;

    return 0;
}
