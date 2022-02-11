void F_1 ( void (* F_2)( const char * , T_1 ) ,
void (* F_3)( const char * , int , T_2 ) ,
void (* F_4)( const char * , int ) ,
void (* F_5)( const char * , int ) )
{
V_1 = F_2 ;
V_2 = F_3 ;
V_3 = F_4 ;
V_4 = F_5 ;
}
void
F_6 ( const char * V_5 , ... )
{
T_1 V_6 ;
va_start ( V_6 , V_5 ) ;
(* V_1)( V_5 , V_6 ) ;
va_end ( V_6 ) ;
}
void
F_7 ( const char * V_7 , int V_8 ,
T_2 V_9 )
{
(* V_2)( V_7 , V_8 , V_9 ) ;
}
void
F_8 ( const char * V_7 , int V_8 )
{
(* V_3)( V_7 , V_8 ) ;
}
void
F_9 ( const char * V_7 , int V_8 )
{
(* V_4)( V_7 , V_8 ) ;
}
