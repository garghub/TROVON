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
int V_9 , error ;
if ( ! F_4 ( V_10 ) || V_8 )
return - V_11 ;
if ( V_4 >= sizeof( V_6 ) || V_4 == 0 )
return - V_12 ;
if ( F_5 ( V_6 , V_3 , V_4 ) != 0 )
return - V_13 ;
V_6 [ V_4 ] = '\0' ;
if ( ( sscanf ( V_6 , L_1 , & V_9 ) != 1 ) || ( V_9 != 1 ) )
return - V_12 ;
error = F_6 () ;
if ( ! error ) {
V_8 = 1 ;
F_7 ( L_2 ) ;
} else
F_8 ( L_3 ) ;
return V_4 ;
}
int T_5 F_9 ( void )
{
int error = 0 ;
V_14 = F_10 ( L_4 , V_15 | V_16 ,
NULL , NULL , & V_17 ) ;
if ( ! V_14 || F_11 ( V_14 ) )
error = - V_13 ;
return error ;
}
