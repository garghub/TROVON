static void F_1 ( void )
{
struct V_1 * V_2 = F_2 ( V_3 ) ;
F_3 ( & V_4 ) ;
V_2 -> V_5 . V_6 &= ~ V_7 ;
}
static void F_4 ( struct V_8 * V_9 )
{
V_9 -> V_10 = 0xfff ;
V_9 -> V_11 = 1 ;
V_9 -> V_12 = 1 ;
V_9 -> V_13 = 1 ;
V_9 -> V_14 = 1 ;
V_9 -> V_15 = V_16 ;
V_9 -> V_17 = 1 ;
}
void F_5 ( void )
{
struct V_18 * V_19 = V_3 ;
if ( ! V_19 -> V_20 . V_21 )
return;
F_1 () ;
F_6 ( V_19 -> V_20 . V_21 ) ;
V_19 -> V_20 . V_21 = NULL ;
}
