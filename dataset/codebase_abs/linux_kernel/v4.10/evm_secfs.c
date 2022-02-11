static T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
char V_6 [ 80 ] ;
T_1 V_7 ;
if ( * V_5 != 0 )
return 0 ;
sprintf ( V_6 , L_1 , V_8 ) ;
V_7 = F_2 ( V_3 , V_4 , V_5 , V_6 , strlen ( V_6 ) ) ;
return V_7 ;
}
static T_1 F_3 ( struct V_1 * V_1 , const char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
char V_6 [ 80 ] ;
int V_9 ;
if ( ! F_4 ( V_10 ) || ( V_8 & V_11 ) )
return - V_12 ;
if ( V_4 >= sizeof( V_6 ) || V_4 == 0 )
return - V_13 ;
if ( F_5 ( V_6 , V_3 , V_4 ) != 0 )
return - V_14 ;
V_6 [ V_4 ] = '\0' ;
if ( ( sscanf ( V_6 , L_1 , & V_9 ) != 1 ) || ( V_9 != 1 ) )
return - V_13 ;
F_6 () ;
return V_4 ;
}
int T_5 F_7 ( void )
{
int error = 0 ;
V_15 = F_8 ( L_2 , V_16 | V_17 ,
NULL , NULL , & V_18 ) ;
if ( ! V_15 || F_9 ( V_15 ) )
error = - V_14 ;
return error ;
}
