void F_1 ( T_1 )
int * T_1 ;
{
( * T_1 ) ++ ;
}
main ()
{
int V_1 = 0 ;
#ifdef F_2
int V_2 ;
#endif
while ( V_1 < 3 ) {
fprintf ( V_3 , L_1 , V_1 ) ;
F_1 ( & V_1 ) ;
#ifdef F_2
V_2 += V_1 ;
#endif
}
}
