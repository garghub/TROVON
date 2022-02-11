static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_7 ) ;
T_1 V_8 ;
int V_9 , V_10 = - V_11 ;
switch ( V_6 -> V_12 ) {
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
V_9 = F_3 ( V_6 -> V_12 ) ;
V_8 = V_6 -> V_18 & ~ 0x87 ;
V_8 |= V_4 ? 0x80 : 0 ;
V_8 |= ( 0x7 - ( V_4 >> 5 ) ) & 0x7 ;
V_10 = F_4 ( V_6 -> V_19 , V_20 + V_9 ,
V_8 ) ;
break;
case V_21 :
V_8 = V_6 -> V_18 & ~ 0x80 ;
V_8 |= V_4 ? 0x80 : 0 ;
V_10 = F_4 ( V_6 -> V_19 , V_22 , V_8 ) ;
break;
case V_23 :
case V_24 :
V_9 = F_5 ( V_6 -> V_12 ) ;
V_8 = ( V_4 * 0x5f / V_25 ) & 0x7f ;
V_8 |= ( V_6 -> V_18 & V_26 ) ? 0x80 : 0 ;
V_10 = F_4 ( V_6 -> V_19 , V_27 + V_9 ,
V_8 ) ;
break;
case V_28 :
V_8 = V_4 & 0xfe ;
V_10 = F_4 ( V_6 -> V_19 , V_29 , V_8 ) ;
break;
}
return V_10 ;
}
static int F_6 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = F_7 ( & V_31 -> V_34 ) ;
struct V_5 * V_6 ;
int V_12 , V_10 ;
if ( V_33 == NULL )
return 0 ;
V_12 = V_31 -> V_12 ;
if ( ! ( ( V_12 >= V_13 && V_12 <= V_21 ) ||
( V_12 >= V_23 && V_12 <= V_28 ) ) ) {
F_8 ( & V_31 -> V_34 , L_1 , V_12 ) ;
return - V_11 ;
}
V_6 = F_9 ( & V_31 -> V_34 , sizeof( struct V_5 ) , V_35 ) ;
if ( ! V_6 )
return - V_36 ;
V_6 -> V_7 . V_37 = V_33 -> V_37 ;
V_6 -> V_7 . V_38 = V_33 -> V_38 ;
V_6 -> V_7 . V_39 = F_1 ;
V_6 -> V_7 . V_40 = V_41 ;
V_6 -> V_12 = V_12 ;
V_6 -> V_18 = V_33 -> V_18 ;
V_6 -> V_19 = V_31 -> V_34 . V_42 ;
V_10 = F_10 ( V_6 -> V_19 , & V_6 -> V_7 ) ;
if ( V_10 ) {
F_8 ( & V_31 -> V_34 , L_2 , V_12 ) ;
return V_10 ;
}
F_11 ( V_31 , V_6 ) ;
return 0 ;
}
static int F_12 ( struct V_30 * V_31 )
{
struct V_5 * V_6 = F_13 ( V_31 ) ;
F_14 ( & V_6 -> V_7 ) ;
return 0 ;
}
