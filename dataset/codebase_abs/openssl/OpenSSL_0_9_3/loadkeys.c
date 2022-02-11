T_1 * F_1 ( const char * V_1 )
{
T_2 * V_2 = fopen ( V_1 , L_1 ) ;
T_3 * V_3 ;
T_1 * V_4 ;
if ( ! V_2 )
return NULL ;
V_3 = ( T_3 * ) F_2 ( ( char * (*)() ) V_5 ,
V_6 ,
V_2 , NULL , NULL ) ;
if ( V_3 == NULL )
{
F_3 ( V_7 ) ;
return NULL ;
}
fclose ( V_2 ) ;
V_4 = F_4 ( V_3 ) ;
F_5 ( V_3 ) ;
if ( V_4 == NULL )
F_3 ( V_7 ) ;
return V_4 ;
}
T_1 * F_6 ( const char * V_8 )
{
T_2 * V_2 = fopen ( V_8 , L_1 ) ;
T_1 * V_4 ;
if ( ! V_2 )
return NULL ;
V_4 = ( T_1 * ) F_2 ( ( char * (*)() ) V_9 ,
V_10 ,
V_2 ,
NULL , NULL ) ;
fclose ( V_2 ) ;
if ( V_4 == NULL )
F_3 ( V_7 ) ;
return V_4 ;
}
