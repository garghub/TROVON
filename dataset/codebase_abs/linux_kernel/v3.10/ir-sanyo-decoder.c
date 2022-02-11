static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 ;
T_2 V_10 , V_11 , V_12 ;
if ( ! ( V_2 -> V_13 & V_14 ) )
return 0 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_15 ) {
F_3 ( 1 , L_1 ) ;
V_6 -> V_16 = V_17 ;
}
return 0 ;
}
F_3 ( 2 , L_2 ,
V_6 -> V_16 , F_4 ( V_4 . V_18 ) , F_5 ( V_4 . V_19 ) ) ;
switch ( V_6 -> V_16 ) {
case V_17 :
if ( ! V_4 . V_19 )
break;
if ( F_6 ( V_4 . V_18 , V_20 , V_21 / 2 ) ) {
V_6 -> V_22 = 0 ;
V_6 -> V_16 = V_23 ;
return 0 ;
}
break;
case V_23 :
if ( V_4 . V_19 )
break;
if ( F_6 ( V_4 . V_18 , V_24 , V_21 / 2 ) ) {
V_6 -> V_16 = V_25 ;
return 0 ;
}
break;
case V_25 :
if ( ! V_4 . V_19 )
break;
if ( ! F_6 ( V_4 . V_18 , V_26 , V_21 / 2 ) )
break;
V_6 -> V_16 = V_27 ;
return 0 ;
case V_27 :
if ( V_4 . V_19 )
break;
if ( ! V_6 -> V_22 && F_7 ( V_4 . V_18 , V_28 , V_21 / 2 ) ) {
if ( ! V_2 -> V_29 ) {
F_3 ( 1 , L_3 ) ;
} else {
F_8 ( V_2 ) ;
F_3 ( 1 , L_4 ) ;
V_6 -> V_16 = V_17 ;
}
return 0 ;
}
V_6 -> V_30 <<= 1 ;
if ( F_6 ( V_4 . V_18 , V_31 , V_21 / 2 ) )
V_6 -> V_30 |= 1 ;
else if ( ! F_6 ( V_4 . V_18 , V_32 , V_21 / 2 ) )
break;
V_6 -> V_22 ++ ;
if ( V_6 -> V_22 == V_33 )
V_6 -> V_16 = V_34 ;
else
V_6 -> V_16 = V_25 ;
return 0 ;
case V_34 :
if ( ! V_4 . V_19 )
break;
if ( ! F_6 ( V_4 . V_18 , V_35 , V_21 / 2 ) )
break;
V_6 -> V_16 = V_36 ;
return 0 ;
case V_36 :
if ( V_4 . V_19 )
break;
if ( ! F_7 ( V_4 . V_18 , V_37 , V_21 / 2 ) )
break;
V_10 = F_9 ( ( V_6 -> V_30 >> 29 ) & 0x1fff ) >> 3 ;
V_11 = F_10 ( ( V_6 -> V_30 >> 8 ) & 0xff ) ;
V_12 = F_10 ( ( V_6 -> V_30 >> 0 ) & 0xff ) ;
if ( ( V_11 ^ V_12 ) != 0xff ) {
F_3 ( 1 , L_5 ,
V_6 -> V_30 ) ;
V_6 -> V_16 = V_17 ;
return 0 ;
}
V_9 = V_10 << 8 | V_11 ;
F_3 ( 1 , L_6 , V_9 ) ;
F_11 ( V_2 , V_9 , 0 ) ;
V_6 -> V_16 = V_17 ;
return 0 ;
}
F_3 ( 1 , L_7 ,
V_6 -> V_22 , V_6 -> V_16 , F_4 ( V_4 . V_18 ) , F_5 ( V_4 . V_19 ) ) ;
V_6 -> V_16 = V_17 ;
return - V_38 ;
}
static int T_3 F_12 ( void )
{
F_13 ( & V_39 ) ;
F_14 ( V_40 L_8 ) ;
return 0 ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_39 ) ;
}
