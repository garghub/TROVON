void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 -> V_5 , L_1 , V_4 ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_4 ( V_6 , V_2 -> V_5 , L_2 V_7 L_3 , V_4 ) ;
}
void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_6 ( L_4 , V_2 -> V_8 , V_4 ) ;
}
void F_7 ( struct V_1 * V_2 , const char * V_9 , ... )
{
struct V_3 V_4 ;
T_1 args ;
va_start ( args , V_9 ) ;
V_4 . V_10 = V_9 ;
V_4 . V_11 = & args ;
V_2 -> V_12 ( V_2 , & V_4 ) ;
va_end ( args ) ;
}
