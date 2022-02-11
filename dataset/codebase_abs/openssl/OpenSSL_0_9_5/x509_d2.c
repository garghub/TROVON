int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( V_1 , F_3 () ) ;
if ( V_2 == NULL ) return ( 0 ) ;
F_4 ( V_2 , NULL , V_3 ) ;
V_2 = F_2 ( V_1 , F_5 () ) ;
if ( V_2 == NULL ) return ( 0 ) ;
F_6 ( V_2 , NULL , V_3 ) ;
F_7 () ;
return ( 1 ) ;
}
int F_8 ( T_1 * V_1 , const char * V_4 ,
const char * V_5 )
{
T_2 * V_2 ;
if ( V_4 != NULL )
{
V_2 = F_2 ( V_1 , F_3 () ) ;
if ( V_2 == NULL ) return ( 0 ) ;
if ( F_4 ( V_2 , V_4 , V_6 ) != 1 )
return ( 0 ) ;
}
if ( V_5 != NULL )
{
V_2 = F_2 ( V_1 , F_5 () ) ;
if ( V_2 == NULL ) return ( 0 ) ;
if ( F_6 ( V_2 , V_5 , V_6 ) != 1 )
return ( 0 ) ;
}
if ( ( V_5 == NULL ) && ( V_4 == NULL ) )
return ( 0 ) ;
return ( 1 ) ;
}
