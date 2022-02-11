static int F_1 ( struct V_1 * V_2 , T_1 type , T_1 V_3 )
{
return 0 ;
}
static unsigned int F_2 ( struct V_4 * V_5 )
{
return V_5 -> V_6 ;
}
static int F_3 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_4 ( struct V_7 * V_8 , struct V_4 * V_5 )
{
F_5 ( V_8 , L_1 ) ;
}
struct V_9 * F_6 ( const char * V_10 , T_1 type ,
T_1 V_3 )
{
return F_7 ( V_10 , & V_11 , type , V_3 ) ;
}
int F_8 ( struct V_12 * V_5 )
{
struct V_4 * V_13 = & V_5 -> V_13 ;
V_13 -> V_14 = & V_11 ;
V_13 -> V_15 &= ~ V_16 ;
V_13 -> V_15 |= V_17 ;
return F_9 ( V_13 ) ;
}
int F_10 ( struct V_12 * V_5 )
{
return F_11 ( & V_5 -> V_13 ) ;
}
