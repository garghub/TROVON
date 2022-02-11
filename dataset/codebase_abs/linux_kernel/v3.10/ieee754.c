int F_1 ( int V_1 , const char * V_2 , ... )
{
struct V_3 V_4 ;
if ( ! F_2 () )
return V_1 ;
V_4 . V_2 = V_2 ;
V_4 . V_5 = V_6 ;
V_4 . V_7 . V_8 = V_1 ;
va_start ( V_4 . V_9 , V_2 ) ;
F_3 ( & V_4 ) ;
va_end ( V_4 . V_9 ) ;
return V_4 . V_7 . V_8 ;
}
T_1 F_4 ( T_1 V_1 , const char * V_2 , ... )
{
struct V_3 V_4 ;
if ( ! F_2 () )
return V_1 ;
V_4 . V_2 = V_2 ;
V_4 . V_5 = V_10 ;
V_4 . V_7 . V_11 = V_1 ;
va_start ( V_4 . V_9 , V_2 ) ;
F_3 ( & V_4 ) ;
va_end ( V_4 . V_9 ) ;
return V_4 . V_7 . V_11 ;
}
