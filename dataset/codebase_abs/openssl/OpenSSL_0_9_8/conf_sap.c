void F_1 ( const char * V_1 )
{
if ( V_2 )
return;
F_2 () ;
#ifndef F_3
F_4 () ;
#endif
F_5 () ;
if ( F_6 ( NULL , NULL ,
V_3 ) <= 0 )
{
T_1 * V_4 ;
F_7 () ;
if ( ( V_4 = F_8 ( V_5 , V_6 ) ) != NULL )
{
F_9 ( V_4 , L_1 ) ;
F_10 ( V_4 ) ;
F_11 ( V_4 ) ;
}
exit ( 1 ) ;
}
return;
}
void F_12 ()
{
V_2 = 1 ;
}
