static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , int V_4 )
{
T_2 V_5 ;
T_2 V_6 ;
T_2 V_7 = 0 ;
V_5 = F_2 ( V_2 -> V_8 ) ;
switch ( V_3 ) {
case V_9 :
V_7 = V_10 ;
break;
case V_11 :
case V_12 :
case V_13 :
case V_14 :
V_7 = V_15 ;
break;
case V_16 :
default:
V_7 = V_17 ;
break;
} ;
V_6 = 0x3 << ( V_4 * 2 ) | F_3 ( V_4 + 6 ) ;
V_7 <<= V_4 * 2 ;
if ( V_2 -> V_18 ) {
if ( V_4 == 0 )
V_7 |= V_19 ;
else
V_7 |= V_20 ;
}
V_5 &= ~ V_6 ;
V_5 |= V_7 ;
F_4 ( V_5 , V_2 -> V_8 ) ;
}
static int F_5 ( struct V_21 * V_22 , void * V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) V_23 ;
return V_22 -> V_26 == V_25 &&
V_22 -> V_27 == & V_28 . V_27 ;
}
void F_6 ( struct V_21 * V_22 , T_1 V_3 , int V_4 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 ;
V_25 = F_7 ( V_22 -> V_26 , L_1 ) ;
if ( ! V_25 ) {
F_8 ( V_22 , L_2 ) ;
return;
}
V_22 = F_9 ( & V_29 , NULL , V_25 , F_5 ) ;
V_2 = F_10 ( V_22 ) ;
V_2 -> F_6 ( V_2 , V_3 , V_4 ) ;
}
static int F_11 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
const struct V_34 * V_35 ;
struct V_1 * V_2 ;
V_35 = F_12 ( V_36 , V_31 -> V_22 . V_26 ) ;
if ( ! V_35 )
return - V_37 ;
V_2 = F_13 ( & V_31 -> V_22 , sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 ) {
F_8 ( & V_31 -> V_22 , L_3 ) ;
return - V_39 ;
}
V_2 -> F_6 = V_35 -> V_23 ;
V_33 = F_14 ( V_31 , V_40 , L_4 ) ;
V_2 -> V_8 = F_15 ( & V_31 -> V_22 , V_33 ) ;
if ( F_16 ( V_2 -> V_8 ) )
return F_17 ( V_2 -> V_8 ) ;
if ( F_18 ( V_31 -> V_22 . V_26 , L_5 , NULL ) )
V_2 -> V_18 = true ;
F_19 ( & V_31 -> V_22 , V_2 ) ;
return 0 ;
}
