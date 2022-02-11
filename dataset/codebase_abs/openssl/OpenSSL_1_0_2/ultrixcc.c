main ()
{
F_1 ( 5 ) ;
F_1 ( 0 ) ;
}
int F_1 ( T_1 )
int T_1 ;
{
switch ( T_1 & 7 ) {
case 7 :
printf ( L_1 ) ;
case 6 :
printf ( L_2 ) ;
case 5 :
printf ( L_3 ) ;
case 4 :
printf ( L_4 ) ;
case 3 :
printf ( L_5 ) ;
case 2 :
printf ( L_6 ) ;
case 1 :
printf ( L_7 ) ;
#ifdef F_2
case 0 :
;
#endif
}
}
