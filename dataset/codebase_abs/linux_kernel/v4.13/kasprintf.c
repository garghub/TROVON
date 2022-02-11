char * F_1 ( T_1 V_1 , const char * V_2 , T_2 V_3 )
{
unsigned int V_4 , V_5 ;
char * V_6 ;
T_2 V_7 ;
F_2 ( V_7 , V_3 ) ;
V_4 = vsnprintf ( NULL , 0 , V_2 , V_7 ) ;
va_end ( V_7 ) ;
V_6 = F_3 ( V_4 + 1 , V_1 ) ;
if ( ! V_6 )
return NULL ;
V_5 = vsnprintf ( V_6 , V_4 + 1 , V_2 , V_3 ) ;
F_4 ( V_4 != V_5 , L_1 ,
V_4 , V_5 , V_2 ) ;
return V_6 ;
}
const char * F_5 ( T_1 V_1 , const char * V_2 , T_2 V_3 )
{
if ( ! strchr ( V_2 , '%' ) )
return F_6 ( V_2 , V_1 ) ;
if ( ! strcmp ( V_2 , L_2 ) )
return F_6 ( va_arg ( V_3 , const char * ) , V_1 ) ;
return F_1 ( V_1 , V_2 , V_3 ) ;
}
char * F_7 ( T_1 V_1 , const char * V_2 , ... )
{
T_2 V_3 ;
char * V_6 ;
va_start ( V_3 , V_2 ) ;
V_6 = F_1 ( V_1 , V_2 , V_3 ) ;
va_end ( V_3 ) ;
return V_6 ;
}
