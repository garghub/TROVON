main ()
{
unsigned long V_1 [ 4 ] ;
F_1 ( V_1 , V_2 , V_3 ) ;
fprintf ( V_4 , L_1 , V_2 [ 3 ] , V_2 [ 2 ] , V_2 [ 1 ] , V_2 [ 0 ] ) ;
fprintf ( V_4 , L_2 , V_3 [ 3 ] , V_3 [ 2 ] , V_3 [ 1 ] , V_3 [ 0 ] ) ;
fprintf ( V_4 , L_3 , V_1 [ 3 ] , V_1 [ 2 ] , V_1 [ 1 ] , V_1 [ 0 ] ) ;
fprintf ( V_4 , L_4 , V_5 [ 3 ] , V_5 [ 2 ] , V_5 [ 1 ] , V_5 [ 0 ] ) ;
}
int F_1 ( V_1 , V_2 , V_3 )
unsigned long * V_1 , * V_2 , * V_3 ;
{
register unsigned long V_6 , V_7 , * V_8 , * V_9 , * V_10 ;
int V_11 , V_12 ;
#ifdef F_2
unsigned long V_13 ;
#endif
V_8 = V_2 ;
V_9 = V_3 ;
V_10 = V_1 ;
V_12 = 0 ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ )
{
V_6 = * ( V_8 ++ ) ;
V_7 = * ( V_9 ++ ) ;
V_6 = ( V_6 - V_7 ) ;
#ifdef F_2
V_13 = V_6 ;
#endif
* ( V_10 ++ ) = V_6 & 0xffffffff ;
}
}
