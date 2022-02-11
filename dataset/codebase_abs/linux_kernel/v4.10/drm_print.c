void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 -> V_5 , L_1 , V_4 ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_4 ( V_6 , V_2 -> V_5 , L_2 V_7 L_3 , V_4 ) ;
}
void F_5 ( struct V_1 * V_2 , const char * V_8 , ... )
{
struct V_3 V_4 ;
T_1 args ;
va_start ( args , V_8 ) ;
V_4 . V_9 = V_8 ;
V_4 . V_10 = & args ;
V_2 -> V_11 ( V_2 , & V_4 ) ;
va_end ( args ) ;
}
