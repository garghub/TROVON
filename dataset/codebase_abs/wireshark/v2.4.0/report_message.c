void F_1 ( void (* F_2)( const char * , T_1 ) ,
void (* F_3)( const char * , T_1 ) ,
void (* F_4)( const char * , int , T_2 ) ,
void (* F_5)( const char * , int ) ,
void (* F_6)( const char * , int ) )
{
V_1 = F_2 ;
V_2 = F_3 ;
V_3 = F_4 ;
V_4 = F_5 ;
V_5 = F_6 ;
}
void
F_7 ( const char * V_6 , ... )
{
T_1 V_7 ;
va_start ( V_7 , V_6 ) ;
(* V_1)( V_6 , V_7 ) ;
va_end ( V_7 ) ;
}
void
F_8 ( const char * V_6 , ... )
{
T_1 V_7 ;
va_start ( V_7 , V_6 ) ;
(* V_2)( V_6 , V_7 ) ;
va_end ( V_7 ) ;
}
void
F_9 ( const char * V_8 , int V_9 ,
T_2 V_10 )
{
(* V_3)( V_8 , V_9 , V_10 ) ;
}
void
F_10 ( const char * V_8 , int V_9 )
{
(* V_4)( V_8 , V_9 ) ;
}
void
F_11 ( const char * V_8 , int V_9 )
{
(* V_5)( V_8 , V_9 ) ;
}
