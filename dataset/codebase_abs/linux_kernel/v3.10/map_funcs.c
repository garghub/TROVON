static T_1 T_2 F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static void T_2 F_3 ( struct V_1 * V_2 , const T_1 V_4 , unsigned long V_3 )
{
F_4 ( V_2 , V_4 , V_3 ) ;
}
static void T_2 F_5 ( struct V_1 * V_2 , void * V_5 , unsigned long V_6 , T_3 V_7 )
{
F_6 ( V_2 , V_5 , V_6 , V_7 ) ;
}
static void T_2 F_7 ( struct V_1 * V_2 , unsigned long V_5 , const void * V_6 , T_3 V_7 )
{
F_8 ( V_2 , V_5 , V_6 , V_7 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( ! F_11 ( V_2 -> V_8 ) ) ;
V_2 -> V_9 = F_1 ;
V_2 -> V_10 = F_3 ;
V_2 -> V_11 = F_5 ;
V_2 -> V_12 = F_7 ;
}
