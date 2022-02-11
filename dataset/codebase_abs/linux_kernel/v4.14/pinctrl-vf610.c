static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_5 , bool V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_10 ;
const struct V_11 * V_12 ;
T_1 V_13 ;
V_12 = & V_10 -> V_14 [ V_5 ] ;
if ( V_12 -> V_15 == - 1 )
return - V_16 ;
V_13 = F_3 ( V_8 -> V_17 + V_12 -> V_15 ) ;
if ( V_6 )
V_13 &= ~ 0x2 ;
else
V_13 |= 0x2 ;
F_4 ( V_13 , V_8 -> V_17 + V_12 -> V_15 ) ;
return 0 ;
}
static int F_5 ( struct V_18 * V_19 )
{
return F_6 ( V_19 , & V_20 ) ;
}
static int T_2 F_7 ( void )
{
return F_8 ( & V_21 ) ;
}
