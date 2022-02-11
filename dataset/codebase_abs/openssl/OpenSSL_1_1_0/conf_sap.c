void F_1 ( const char * V_1 )
{
T_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
if ( V_1 != NULL )
V_2 . V_1 = F_2 ( V_1 ) ;
F_3 ( V_3 , & V_2 ) ;
}
void F_4 ( const char * V_1 )
{
if ( V_4 )
return;
F_5 () ;
#ifndef F_6
F_7 () ;
#endif
F_8 () ;
#ifndef F_9
F_10 ( NULL , V_1 ,
V_5 |
V_6 ) ;
#endif
V_4 = 1 ;
}
void F_11 ( void )
{
V_4 = 1 ;
}
