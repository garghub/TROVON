T_1 * F_1 ( const char * V_1 )
{
T_2 * V_2 = fopen ( V_1 , L_1 ) ;
T_3 * V_3 ;
T_1 * V_4 ;
if ( ! V_2 )
return NULL ;
V_3 = F_2 ( V_2 , NULL , 0 , NULL ) ;
if ( V_3 == NULL )
{
F_3 ( V_5 ) ;
return NULL ;
}
fclose ( V_2 ) ;
V_4 = F_4 ( V_3 ) ;
F_5 ( V_3 ) ;
if ( V_4 == NULL )
F_3 ( V_5 ) ;
return V_4 ;
}
T_1 * F_6 ( const char * V_6 )
{
T_2 * V_2 = fopen ( V_6 , L_1 ) ;
T_1 * V_4 ;
if ( ! V_2 )
return NULL ;
V_4 = F_7 ( V_2 , NULL , 0 , NULL ) ;
fclose ( V_2 ) ;
if ( V_4 == NULL )
F_3 ( V_5 ) ;
return V_4 ;
}
