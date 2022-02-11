static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 ;
T_2 V_10 ;
T_3 V_11 , V_12 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_13 ) {
F_3 ( 1 , L_1 ) ;
V_6 -> V_14 = V_15 ;
}
return 0 ;
}
F_3 ( 2 , L_2 ,
V_6 -> V_14 , F_4 ( V_4 . V_16 ) , F_5 ( V_4 . V_17 ) ) ;
switch ( V_6 -> V_14 ) {
case V_15 :
if ( ! V_4 . V_17 )
break;
if ( F_6 ( V_4 . V_16 , V_18 , V_19 / 2 ) ) {
V_6 -> V_20 = 0 ;
V_6 -> V_14 = V_21 ;
return 0 ;
}
break;
case V_21 :
if ( V_4 . V_17 )
break;
if ( F_6 ( V_4 . V_16 , V_22 , V_19 / 2 ) ) {
V_6 -> V_14 = V_23 ;
return 0 ;
}
break;
case V_23 :
if ( ! V_4 . V_17 )
break;
if ( ! F_6 ( V_4 . V_16 , V_24 , V_19 / 2 ) )
break;
V_6 -> V_14 = V_25 ;
return 0 ;
case V_25 :
if ( V_4 . V_17 )
break;
if ( ! V_6 -> V_20 && F_7 ( V_4 . V_16 , V_26 , V_19 / 2 ) ) {
if ( ! V_2 -> V_27 ) {
F_3 ( 1 , L_3 ) ;
} else {
F_8 ( V_2 ) ;
F_3 ( 1 , L_4 ) ;
V_6 -> V_14 = V_15 ;
}
return 0 ;
}
V_6 -> V_28 <<= 1 ;
if ( F_6 ( V_4 . V_16 , V_29 , V_19 / 2 ) )
V_6 -> V_28 |= 1 ;
else if ( ! F_6 ( V_4 . V_16 , V_30 , V_19 / 2 ) )
break;
V_6 -> V_20 ++ ;
if ( V_6 -> V_20 == V_31 )
V_6 -> V_14 = V_32 ;
else
V_6 -> V_14 = V_23 ;
return 0 ;
case V_32 :
if ( ! V_4 . V_17 )
break;
if ( ! F_6 ( V_4 . V_16 , V_33 , V_19 / 2 ) )
break;
V_6 -> V_14 = V_34 ;
return 0 ;
case V_34 :
if ( V_4 . V_17 )
break;
if ( ! F_7 ( V_4 . V_16 , V_35 , V_19 / 2 ) )
break;
V_10 = F_9 ( ( V_6 -> V_28 >> 29 ) & 0x1fff ) >> 3 ;
V_11 = F_10 ( ( V_6 -> V_28 >> 8 ) & 0xff ) ;
V_12 = F_10 ( ( V_6 -> V_28 >> 0 ) & 0xff ) ;
if ( ( V_11 ^ V_12 ) != 0xff ) {
F_3 ( 1 , L_5 ,
V_6 -> V_28 ) ;
V_6 -> V_14 = V_15 ;
return 0 ;
}
V_9 = V_10 << 8 | V_11 ;
F_3 ( 1 , L_6 , V_9 ) ;
F_11 ( V_2 , V_36 , V_9 , 0 ) ;
V_6 -> V_14 = V_15 ;
return 0 ;
}
F_3 ( 1 , L_7 ,
V_6 -> V_20 , V_6 -> V_14 , F_4 ( V_4 . V_16 ) , F_5 ( V_4 . V_17 ) ) ;
V_6 -> V_14 = V_15 ;
return - V_37 ;
}
static int F_12 ( enum V_38 V_39 , T_1 V_9 ,
struct V_3 * V_40 , unsigned int V_41 )
{
struct V_3 * V_42 = V_40 ;
int V_43 ;
T_4 V_7 ;
V_7 = ( ( T_4 ) ( F_9 ( V_9 >> 8 ) & 0xfff8 ) << ( 8 + 8 + 13 - 3 ) ) |
( ( T_4 ) ( F_9 ( ~ V_9 >> 8 ) & 0xfff8 ) << ( 8 + 8 + 0 - 3 ) ) |
( ( F_10 ( V_9 ) & 0xff ) << 8 ) |
( F_10 ( ~ V_9 ) & 0xff ) ;
V_43 = F_13 ( & V_42 , V_41 , & V_44 , V_31 , V_7 ) ;
if ( V_43 < 0 )
return V_43 ;
return V_42 - V_40 ;
}
static int T_5 F_14 ( void )
{
F_15 ( & V_45 ) ;
F_16 ( V_46 L_8 ) ;
return 0 ;
}
static void T_6 F_17 ( void )
{
F_18 ( & V_45 ) ;
}
