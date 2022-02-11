T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 , T_1 V_6 )
{
T_1 V_7 ;
V_5 &= V_6 ;
F_4 ( & V_2 -> V_8 ) ;
V_7 = F_2 ( V_2 -> V_4 + V_3 ) ;
V_7 &= ~ V_6 ;
V_7 |= V_5 ;
F_5 ( V_7 , V_2 -> V_4 + V_3 ) ;
F_6 ( & V_2 -> V_8 ) ;
}
static int T_2 F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = & V_10 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
void * V_4 ;
struct V_1 * V_16 ;
V_4 = F_8 ( V_14 , 0 ) ;
if ( ! V_4 )
return - V_17 ;
V_16 = F_9 ( V_12 , sizeof( * V_16 ) , V_18 ) ;
if ( ! V_16 )
return - V_19 ;
V_16 -> V_4 = V_4 ;
F_10 ( & V_16 -> V_8 ) ;
F_11 ( V_10 , V_16 ) ;
F_12 ( V_14 , V_20 , NULL , V_12 ) ;
return 0 ;
}
static int T_3 F_13 ( struct V_9 * V_10 )
{
struct V_1 * V_16 ;
V_16 = F_14 ( V_10 ) ;
F_15 ( V_16 -> V_4 ) ;
return 0 ;
}
static int T_4 F_16 ( void )
{
return F_17 ( & V_21 ) ;
}
static void T_5 F_18 ( void )
{
F_19 ( & V_21 ) ;
}
