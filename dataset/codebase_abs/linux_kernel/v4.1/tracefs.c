bool F_1 ( void )
{
return F_2 () != NULL ;
}
const char * F_2 ( void )
{
const char * V_1 ;
if ( V_2 )
return ( const char * ) V_3 ;
V_1 = F_3 ( L_1 , ( long ) V_4 ,
V_3 , V_5 + 1 ,
V_6 ) ;
if ( V_1 )
V_2 = true ;
return V_1 ;
}
char * F_4 ( const char * V_7 )
{
if ( F_2 () )
goto V_8;
if ( V_7 == NULL ) {
V_7 = getenv ( V_9 ) ;
if ( V_7 == NULL )
V_7 = V_10 ;
}
if ( F_5 ( NULL , V_7 , L_1 , 0 , NULL ) < 0 )
return NULL ;
V_2 = true ;
strncpy ( V_3 , V_7 , sizeof( V_3 ) ) ;
V_8:
return V_3 ;
}
