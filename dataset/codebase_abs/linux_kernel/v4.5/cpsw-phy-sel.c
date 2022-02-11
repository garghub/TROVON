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
default:
F_3 ( V_2 -> V_16 ,
L_1 ,
F_4 ( V_3 ) ) ;
case V_17 :
V_7 = V_18 ;
break;
} ;
V_6 = V_19 << ( V_4 * 2 ) | F_5 ( V_4 + 6 ) ;
V_7 <<= V_4 * 2 ;
if ( V_2 -> V_20 ) {
if ( V_4 == 0 )
V_7 |= V_21 ;
else
V_7 |= V_22 ;
}
V_5 &= ~ V_6 ;
V_5 |= V_7 ;
F_6 ( V_5 , V_2 -> V_8 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
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
default:
F_3 ( V_2 -> V_16 ,
L_1 ,
F_4 ( V_3 ) ) ;
case V_17 :
V_7 = V_18 ;
break;
} ;
switch ( V_4 ) {
case 0 :
V_6 = V_19 ;
break;
case 1 :
V_6 = V_19 << 4 ;
V_7 <<= 4 ;
break;
default:
F_8 ( V_2 -> V_16 , L_2 ) ;
return;
}
if ( V_2 -> V_20 )
F_8 ( V_2 -> V_16 , L_3 ) ;
V_5 &= ~ V_6 ;
V_5 |= V_7 ;
F_6 ( V_5 , V_2 -> V_8 ) ;
}
static int F_9 ( struct V_23 * V_16 , void * V_24 )
{
struct V_25 * V_26 = (struct V_25 * ) V_24 ;
return V_16 -> V_27 == V_26 &&
V_16 -> V_28 == & V_29 . V_28 ;
}
void F_10 ( struct V_23 * V_16 , T_1 V_3 , int V_4 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
V_26 = F_11 ( V_16 -> V_27 , L_4 ) ;
if ( ! V_26 ) {
F_8 ( V_16 , L_5 ) ;
return;
}
V_16 = F_12 ( & V_30 , NULL , V_26 , F_9 ) ;
V_2 = F_13 ( V_16 ) ;
V_2 -> F_10 ( V_2 , V_3 , V_4 ) ;
}
static int F_14 ( struct V_31 * V_32 )
{
struct V_33 * V_34 ;
const struct V_35 * V_36 ;
struct V_1 * V_2 ;
V_36 = F_15 ( V_37 , V_32 -> V_16 . V_27 ) ;
if ( ! V_36 )
return - V_38 ;
V_2 = F_16 ( & V_32 -> V_16 , sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 ) {
F_8 ( & V_32 -> V_16 , L_6 ) ;
return - V_40 ;
}
V_2 -> V_16 = & V_32 -> V_16 ;
V_2 -> F_10 = V_36 -> V_24 ;
V_34 = F_17 ( V_32 , V_41 , L_7 ) ;
V_2 -> V_8 = F_18 ( & V_32 -> V_16 , V_34 ) ;
if ( F_19 ( V_2 -> V_8 ) )
return F_20 ( V_2 -> V_8 ) ;
if ( F_21 ( V_32 -> V_16 . V_27 , L_8 , NULL ) )
V_2 -> V_20 = true ;
F_22 ( & V_32 -> V_16 , V_2 ) ;
return 0 ;
}
