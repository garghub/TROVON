void F_1 ( const char * V_1 )
{
if ( V_2 )
return;
F_2 () ;
#ifndef F_3
F_4 () ;
#endif
F_5 () ;
if ( F_6 ( NULL , V_1 ,
V_3 |
V_4 ) <= 0 ) {
T_1 * V_5 ;
F_7 () ;
if ( ( V_5 = F_8 ( V_6 , V_7 ) ) != NULL ) {
F_9 ( V_5 , L_1 ) ;
F_10 ( V_5 ) ;
F_11 ( V_5 ) ;
}
exit ( 1 ) ;
}
return;
}
void F_12 ()
{
V_2 = 1 ;
}
