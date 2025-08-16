#include <iostream>

#ifdef __has_include
    #if __has_include(<span>)
        #include <span>
    #elif
        #error "Missing <span>"
    #endif
#elif
    #error "Missing __has_include"
#endif

using namespace std;

template<typename T, size_t N>
constexpr void show_second_element( span<T,N> seq )
{
    if ( N > 1 )
    {
        cout << "second element from " << seq.size() << " elements is " << seq[1] << "\n";
    }
    else
    {
        cout << "array has no second element \n";
    }
}

void legacy_function( int** array, const uint size )
{
    if ( *array != NULL )
    {
        free( *array );
    }
    *array = (int*) malloc( size*sizeof(int) );
    for ( uint i = 0; i < size; ++i )
    {
        (*array)[i] = i;
    }
}

int main()
{
    constexpr int statInt[]{1,2,3,4,5};
    show_second_element( span{statInt} );

    int* legacyArray = nullptr;
    legacy_function( &legacyArray, 3 );
    span<int> array( legacyArray, 3 );
    show_second_element( array );
    for ( const auto& elem : array )
    {
        cout << elem << " ";
    }
    cout << endl;
    free( legacyArray );
    return 0;
};
