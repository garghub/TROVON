static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
T_1 V_5 ;
int V_6 ;
switch ( V_4 -> V_7 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
V_6 = F_3 ( V_4 -> V_7 ) ;
V_5 = V_4 -> V_13 & ~ 0x87 ;
V_5 |= ( V_4 -> V_14 ) ? 0x80 : 0 ;
V_5 |= ( 0x7 - ( V_4 -> V_14 >> 5 ) ) & 0x7 ;
F_4 ( V_4 -> V_15 , V_16 + V_6 , V_5 ) ;
break;
case V_17 :
V_5 = V_4 -> V_13 & ~ 0x80 ;
V_5 |= ( V_4 -> V_14 ) ? 0x80 : 0 ;
F_4 ( V_4 -> V_15 , V_18 , V_5 ) ;
break;
case V_19 :
case V_20 :
V_6 = F_5 ( V_4 -> V_7 ) ;
V_5 = ( V_4 -> V_14 * 0x5f / V_21 ) & 0x7f ;
V_5 |= ( V_4 -> V_13 & V_22 ) ? 0x80 : 0 ;
F_4 ( V_4 -> V_15 , V_23 + V_6 , V_5 ) ;
break;
case V_24 :
V_5 = V_4 -> V_14 & 0xfe ;
F_4 ( V_4 -> V_15 , V_25 , V_5 ) ;
break;
}
}
static void F_6 ( struct V_26 * V_27 ,
enum V_28 V_29 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_27 , struct V_3 , V_30 ) ;
V_4 -> V_14 = V_29 ;
F_7 ( & V_4 -> V_2 ) ;
}
static int T_2 F_8 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 . V_36 ;
struct V_3 * V_4 ;
int V_7 , V_37 ;
if ( V_34 == NULL )
return 0 ;
V_7 = V_32 -> V_7 ;
if ( ! ( ( V_7 >= V_8 && V_7 <= V_17 ) ||
( V_7 >= V_19 && V_7 <= V_24 ) ) ) {
F_9 ( & V_32 -> V_35 , L_1 , V_7 ) ;
return - V_38 ;
}
V_4 = F_10 ( sizeof( struct V_3 ) , V_39 ) ;
if ( V_4 == NULL ) {
F_9 ( & V_32 -> V_35 , L_2 , V_7 ) ;
return - V_40 ;
}
V_4 -> V_30 . V_41 = V_34 -> V_41 ;
V_4 -> V_30 . V_42 = V_34 -> V_42 ;
V_4 -> V_30 . V_43 = F_6 ;
V_4 -> V_30 . V_44 = V_45 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_13 = V_34 -> V_13 ;
V_4 -> V_15 = V_32 -> V_35 . V_46 ;
V_4 -> V_14 = V_45 ;
F_11 ( & V_4 -> V_2 , F_1 ) ;
V_37 = F_12 ( V_4 -> V_15 , & V_4 -> V_30 ) ;
if ( V_37 ) {
F_9 ( & V_32 -> V_35 , L_3 , V_7 ) ;
goto V_47;
}
F_13 ( V_32 , V_4 ) ;
return 0 ;
V_47:
F_14 ( V_4 ) ;
return V_37 ;
}
static int T_3 F_15 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_16 ( V_32 ) ;
F_17 ( & V_4 -> V_30 ) ;
F_14 ( V_4 ) ;
return 0 ;
}
