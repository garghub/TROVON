static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 ;
T_2 V_10 , V_11 , V_12 , V_13 ;
if ( ! ( V_2 -> V_7 -> V_14 & V_15 ) )
return 0 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_16 ) {
F_3 ( 1 , L_1 ) ;
V_6 -> V_17 = V_18 ;
}
return 0 ;
}
F_3 ( 2 , L_2 ,
V_6 -> V_17 , F_4 ( V_4 . V_19 ) , F_5 ( V_4 . V_20 ) ) ;
switch ( V_6 -> V_17 ) {
case V_18 :
if ( ! V_4 . V_20 )
break;
if ( F_6 ( V_4 . V_19 , V_21 , V_22 / 2 ) ) {
V_6 -> V_23 = 0 ;
V_6 -> V_17 = V_24 ;
return 0 ;
}
break;
case V_24 :
if ( V_4 . V_20 )
break;
if ( F_6 ( V_4 . V_19 , V_25 , V_22 / 2 ) ) {
V_6 -> V_17 = V_26 ;
return 0 ;
}
break;
case V_26 :
if ( ! V_4 . V_20 )
break;
if ( ! F_6 ( V_4 . V_19 , V_27 , V_22 / 2 ) )
break;
V_6 -> V_17 = V_28 ;
return 0 ;
case V_28 :
if ( V_4 . V_20 )
break;
if ( ! V_6 -> V_23 && F_7 ( V_4 . V_19 , V_29 , V_22 / 2 ) ) {
if ( ! V_2 -> V_30 ) {
F_3 ( 1 , L_3 ) ;
} else {
F_8 ( V_2 ) ;
F_3 ( 1 , L_4 ) ;
V_6 -> V_17 = V_18 ;
}
return 0 ;
}
V_6 -> V_31 <<= 1 ;
if ( F_6 ( V_4 . V_19 , V_32 , V_22 / 2 ) )
V_6 -> V_31 |= 1 ;
else if ( ! F_6 ( V_4 . V_19 , V_33 , V_22 / 2 ) )
break;
V_6 -> V_23 ++ ;
if ( V_6 -> V_23 == V_34 )
V_6 -> V_17 = V_35 ;
else
V_6 -> V_17 = V_26 ;
return 0 ;
case V_35 :
if ( ! V_4 . V_20 )
break;
if ( ! F_6 ( V_4 . V_19 , V_36 , V_22 / 2 ) )
break;
V_6 -> V_17 = V_37 ;
return 0 ;
case V_37 :
if ( V_4 . V_20 )
break;
if ( ! F_7 ( V_4 . V_19 , V_38 , V_22 / 2 ) )
break;
V_10 = F_9 ( ( V_6 -> V_31 >> 29 ) & 0x1fff ) >> 3 ;
V_11 = F_9 ( ( V_6 -> V_31 >> 16 ) & 0x1fff ) >> 3 ;
V_12 = F_10 ( ( V_6 -> V_31 >> 8 ) & 0xff ) ;
V_13 = F_10 ( ( V_6 -> V_31 >> 0 ) & 0xff ) ;
if ( ( V_12 ^ V_13 ) != 0xff ) {
F_3 ( 1 , L_5 ,
V_6 -> V_31 ) ;
V_6 -> V_17 = V_18 ;
return 0 ;
}
V_9 = V_10 << 8 | V_12 ;
F_3 ( 1 , L_6 , V_9 ) ;
F_11 ( V_2 , V_9 , 0 ) ;
V_6 -> V_17 = V_18 ;
return 0 ;
}
F_3 ( 1 , L_7 ,
V_6 -> V_23 , V_6 -> V_17 , F_4 ( V_4 . V_19 ) , F_5 ( V_4 . V_20 ) ) ;
V_6 -> V_17 = V_18 ;
return - V_39 ;
}
static int T_3 F_12 ( void )
{
F_13 ( & V_40 ) ;
F_14 ( V_41 L_8 ) ;
return 0 ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_40 ) ;
}
