static void F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_5 . V_7 ;
int V_8 ;
switch ( V_3 ) {
case V_9 :
F_2 ( V_5 , L_1 ) ;
F_3 ( 0 , V_10 ) ;
F_3 ( 0 , V_11 ) ;
break;
case V_12 :
F_2 ( V_5 , L_2 ) ;
V_8 = F_4 ( V_2 -> V_13 , V_14 ) ;
V_8 &= ~ V_15 ;
V_8 |= V_16 ;
F_5 ( V_2 -> V_13 , V_8 , V_14 ) ;
break;
default:
F_2 ( V_5 , L_3 ) ;
break;
}
}
static int T_1 F_6 ( struct V_17 * V_18 )
{
struct V_17 * V_19 ;
F_2 ( & V_18 -> V_5 , L_4 ) ;
V_19 = F_7 ( & V_18 -> V_5 ,
V_18 -> V_20 , V_18 -> V_21 ,
& V_22 ) ;
if ( F_8 ( V_19 ) ) {
F_9 ( & V_18 -> V_5 , L_5 ) ;
return F_10 ( V_19 ) ;
}
F_11 ( V_18 , V_19 ) ;
F_12 ( & V_18 -> V_5 ) ;
F_13 ( & V_18 -> V_5 ) ;
return 0 ;
}
static int T_2 F_14 ( struct V_17 * V_18 )
{
struct V_17 * V_19 = F_15 ( V_18 ) ;
F_16 ( & V_18 -> V_5 ) ;
F_17 ( V_19 ) ;
return 0 ;
}
