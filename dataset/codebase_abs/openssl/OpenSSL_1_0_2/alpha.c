void F_1 ( T_1 , T_2 )
TYPE * T_1 ;
TYPE T_2 ;
{
printf ( L_1 , T_1 [ 0 ] , T_2 ) ;
}
main ()
{
TYPE V_1 [ 5 ] = { 1L , 2L , 3L , 4L , 5L } ;
TYPE * V_2 ;
int V_3 ;
V_2 = V_1 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
F_1 ( V_2 , * ( V_2 ++ ) ) ;
}
}
