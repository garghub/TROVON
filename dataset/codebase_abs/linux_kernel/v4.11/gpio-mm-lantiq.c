static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( V_5 , V_6 ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 . V_9 ) ;
F_3 ( V_5 | V_10 , V_6 ) ;
F_5 ( & V_4 , V_3 ) ;
}
static void F_6 ( struct V_11 * V_12 , unsigned V_13 , int V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
if ( V_14 )
V_2 -> V_7 |= ( 1 << V_13 ) ;
else
V_2 -> V_7 &= ~ ( 1 << V_13 ) ;
F_1 ( V_2 ) ;
}
static int F_8 ( struct V_11 * V_12 , unsigned V_13 , int V_14 )
{
F_6 ( V_12 , V_13 , V_14 ) ;
return 0 ;
}
static void F_9 ( struct V_15 * V_16 )
{
struct V_1 * V_2 =
F_10 ( V_16 , struct V_1 , V_8 ) ;
F_3 ( F_11 ( V_2 -> V_8 . V_9 ) | 0x1 , V_17 ) ;
F_1 ( V_2 ) ;
}
static int F_12 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
T_1 V_7 ;
V_2 = F_13 ( & V_19 -> V_20 , sizeof( * V_2 ) , V_21 ) ;
if ( ! V_2 )
return - V_22 ;
F_14 ( V_19 , V_2 ) ;
V_2 -> V_8 . V_12 . V_23 = 16 ;
V_2 -> V_8 . V_12 . V_24 = F_8 ;
V_2 -> V_8 . V_12 . V_25 = F_6 ;
V_2 -> V_8 . V_26 = F_9 ;
if ( ! F_15 ( V_19 -> V_20 . V_27 , L_1 , & V_7 ) )
V_2 -> V_7 = V_7 ;
return F_16 ( V_19 -> V_20 . V_27 , & V_2 -> V_8 , V_2 ) ;
}
static int F_17 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_18 ( V_19 ) ;
F_19 ( & V_2 -> V_8 ) ;
return 0 ;
}
static int T_2 F_20 ( void )
{
return F_21 ( & V_28 ) ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_28 ) ;
}
