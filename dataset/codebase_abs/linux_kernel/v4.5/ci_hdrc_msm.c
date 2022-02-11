static void F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_5 . V_7 ;
switch ( V_3 ) {
case V_8 :
F_2 ( V_5 , L_1 ) ;
F_3 ( 0 , V_9 ) ;
F_3 ( 0x8 , V_10 ) ;
F_4 ( V_2 -> V_11 ) ;
break;
case V_12 :
F_2 ( V_5 , L_2 ) ;
F_5 ( V_2 -> V_11 , V_13 ) ;
break;
default:
F_2 ( V_5 , L_3 ) ;
break;
}
}
static int F_6 ( struct V_14 * V_15 )
{
struct V_14 * V_16 ;
struct V_11 * V_17 ;
F_2 ( & V_15 -> V_5 , L_4 ) ;
V_17 = F_7 ( & V_15 -> V_5 , L_5 , 0 ) ;
if ( F_8 ( V_17 ) )
return F_9 ( V_17 ) ;
V_18 . V_11 = V_17 ;
V_16 = F_10 ( & V_15 -> V_5 ,
V_15 -> V_19 , V_15 -> V_20 ,
& V_18 ) ;
if ( F_8 ( V_16 ) ) {
F_11 ( & V_15 -> V_5 , L_6 ) ;
return F_9 ( V_16 ) ;
}
F_12 ( V_15 , V_16 ) ;
F_13 ( & V_15 -> V_5 ) ;
F_14 ( & V_15 -> V_5 ) ;
return 0 ;
}
static int F_15 ( struct V_14 * V_15 )
{
struct V_14 * V_16 = F_16 ( V_15 ) ;
F_17 ( & V_15 -> V_5 ) ;
F_18 ( V_16 ) ;
return 0 ;
}
