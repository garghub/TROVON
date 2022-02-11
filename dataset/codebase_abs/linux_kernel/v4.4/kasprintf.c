char * F_1 ( T_1 V_1 , const char * V_2 , T_2 V_3 )
{
unsigned int V_4 ;
char * V_5 ;
T_2 V_6 ;
F_2 ( V_6 , V_3 ) ;
V_4 = vsnprintf ( NULL , 0 , V_2 , V_6 ) ;
va_end ( V_6 ) ;
V_5 = F_3 ( V_4 + 1 , V_1 ) ;
if ( ! V_5 )
return NULL ;
vsnprintf ( V_5 , V_4 + 1 , V_2 , V_3 ) ;
return V_5 ;
}
const char * F_4 ( T_1 V_1 , const char * V_2 , T_2 V_3 )
{
if ( ! strchr ( V_2 , '%' ) )
return F_5 ( V_2 , V_1 ) ;
if ( ! strcmp ( V_2 , L_1 ) )
return F_5 ( va_arg ( V_3 , const char * ) , V_1 ) ;
return F_1 ( V_1 , V_2 , V_3 ) ;
}
char * F_6 ( T_1 V_1 , const char * V_2 , ... )
{
T_2 V_3 ;
char * V_5 ;
va_start ( V_3 , V_2 ) ;
V_5 = F_1 ( V_1 , V_2 , V_3 ) ;
va_end ( V_3 ) ;
return V_5 ;
}
