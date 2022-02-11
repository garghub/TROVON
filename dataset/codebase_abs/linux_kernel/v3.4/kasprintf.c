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
char * F_4 ( T_1 V_1 , const char * V_2 , ... )
{
T_2 V_3 ;
char * V_5 ;
va_start ( V_3 , V_2 ) ;
V_5 = F_1 ( V_1 , V_2 , V_3 ) ;
va_end ( V_3 ) ;
return V_5 ;
}
