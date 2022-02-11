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
V_6 = V_18 << ( V_4 * 2 ) | F_3 ( V_4 + 6 ) ;
V_7 <<= V_4 * 2 ;
if ( V_2 -> V_19 ) {
if ( V_4 == 0 )
V_7 |= V_20 ;
else
V_7 |= V_21 ;
}
V_5 &= ~ V_6 ;
V_5 |= V_7 ;
F_4 ( V_5 , V_2 -> V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
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
switch ( V_4 ) {
case 0 :
V_6 = V_18 ;
break;
case 1 :
V_6 = V_18 << 4 ;
V_7 <<= 4 ;
break;
default:
F_6 ( V_2 -> V_22 , L_1 ) ;
return;
}
if ( V_2 -> V_19 )
F_6 ( V_2 -> V_22 , L_2 ) ;
V_5 &= ~ V_6 ;
V_5 |= V_7 ;
F_4 ( V_5 , V_2 -> V_8 ) ;
}
static int F_7 ( struct V_23 * V_22 , void * V_24 )
{
struct V_25 * V_26 = (struct V_25 * ) V_24 ;
return V_22 -> V_27 == V_26 &&
V_22 -> V_28 == & V_29 . V_28 ;
}
void F_8 ( struct V_23 * V_22 , T_1 V_3 , int V_4 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
V_26 = F_9 ( V_22 -> V_27 , L_3 ) ;
if ( ! V_26 ) {
F_6 ( V_22 , L_4 ) ;
return;
}
V_22 = F_10 ( & V_30 , NULL , V_26 , F_7 ) ;
V_2 = F_11 ( V_22 ) ;
V_2 -> F_8 ( V_2 , V_3 , V_4 ) ;
}
static int F_12 ( struct V_31 * V_32 )
{
struct V_33 * V_34 ;
const struct V_35 * V_36 ;
struct V_1 * V_2 ;
V_36 = F_13 ( V_37 , V_32 -> V_22 . V_27 ) ;
if ( ! V_36 )
return - V_38 ;
V_2 = F_14 ( & V_32 -> V_22 , sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 ) {
F_6 ( & V_32 -> V_22 , L_5 ) ;
return - V_40 ;
}
V_2 -> V_22 = & V_32 -> V_22 ;
V_2 -> F_8 = V_36 -> V_24 ;
V_34 = F_15 ( V_32 , V_41 , L_6 ) ;
V_2 -> V_8 = F_16 ( & V_32 -> V_22 , V_34 ) ;
if ( F_17 ( V_2 -> V_8 ) )
return F_18 ( V_2 -> V_8 ) ;
if ( F_19 ( V_32 -> V_22 . V_27 , L_7 , NULL ) )
V_2 -> V_19 = true ;
F_20 ( & V_32 -> V_22 , V_2 ) ;
return 0 ;
}
