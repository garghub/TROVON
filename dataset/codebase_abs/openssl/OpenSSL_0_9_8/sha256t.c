int main ( int V_1 , char * V_2 [] )
{
printf ( L_1 ) ;
return ( 0 ) ;
}
int main ()
{ unsigned char V_3 [ V_4 ] ;
int V_5 ;
T_1 V_6 ;
fprintf ( stdout , L_2 ) ;
F_1 ( L_3 , 3 , V_3 , NULL , F_2 () , NULL ) ;
if ( memcmp ( V_3 , V_7 , sizeof( V_7 ) ) )
{ fflush ( stdout ) ;
fprintf ( V_8 , L_4 ) ;
return 1 ;
}
else
fprintf ( stdout , L_5 ) ; fflush ( stdout ) ;
F_1 ( L_6cdefdefgL_7efghfghiL_7ghijhijkL_8ijkljklmL_7klmnlmnoL_7mnopnopqL_9\nTEST 2 of 3 failed.\nL_10.L_11aaaaaaaaL_7aaaaaaaaL_7aaaaaaaaL_7aaaaaaaaL_12aaaaaaaaL_7aaaaaaaaL_7aaaaaaaaL_7aaaaaaaaL_12aaaaaaaaL_7aaaaaaaaL_7aaaaaaaaL_7aaaaaaaaL_12aaaaaaaaL_7aaaaaaaaL_7aaaaaaaaL_7aaaaaaaaL_12aaaaaaaaL_7aaaaaaaaL_7aaaaaaaaL_7aaaaaaaaL_13\nTEST 3 of 3 failed.\nL_10.L_14 passed.\nL_14Testing SHA-224 L_15abcL_16\nTEST 1 of 3 failed.\nL_10.L_17abcdbcdeL_7cdefdefgL_7efghfghiL_7ghijhijkL_8ijkljklmL_7klmnlmnoL_7mnopnopqL_18\nTEST 2 of 3 failed.\nL_10.L_19aaaaaaaaL_7aaaaaaaaL_7aaaaaaaaL_7aaaaaaaaL_12aaaaaaaaL_7aaaaaaaaL_7aaaaaaaaL_7aaaaaaaaL_20\nTEST 3 of 3 failed.\nL_10.L_14 passed.\n"
