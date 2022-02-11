void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = 0 ;
}
void F_2 ( int V_6 , int V_7 , const char * V_8 , ... )
{
struct V_9 V_10 ;
T_1 args ;
va_start ( args , V_8 ) ;
V_10 . V_8 = V_8 ;
V_10 . V_11 = & args ;
F_3 ( V_12 L_1 , V_6 , V_7 , & V_10 ) ;
va_end ( args ) ;
}
