static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 ;
T_2 V_10 , V_11 , V_12 ;
if ( ! F_2 ( V_2 , V_13 ) )
return 0 ;
if ( ! F_3 ( V_4 ) ) {
if ( V_4 . V_14 ) {
F_4 ( 1 , L_1 ) ;
V_6 -> V_15 = V_16 ;
}
return 0 ;
}
F_4 ( 2 , L_2 ,
V_6 -> V_15 , F_5 ( V_4 . V_17 ) , F_6 ( V_4 . V_18 ) ) ;
switch ( V_6 -> V_15 ) {
case V_16 :
if ( ! V_4 . V_18 )
break;
if ( F_7 ( V_4 . V_17 , V_19 , V_20 / 2 ) ) {
V_6 -> V_21 = 0 ;
V_6 -> V_15 = V_22 ;
return 0 ;
}
break;
case V_22 :
if ( V_4 . V_18 )
break;
if ( F_7 ( V_4 . V_17 , V_23 , V_20 / 2 ) ) {
V_6 -> V_15 = V_24 ;
return 0 ;
}
break;
case V_24 :
if ( ! V_4 . V_18 )
break;
if ( ! F_7 ( V_4 . V_17 , V_25 , V_20 / 2 ) )
break;
V_6 -> V_15 = V_26 ;
return 0 ;
case V_26 :
if ( V_4 . V_18 )
break;
if ( ! V_6 -> V_21 && F_8 ( V_4 . V_17 , V_27 , V_20 / 2 ) ) {
if ( ! V_2 -> V_28 ) {
F_4 ( 1 , L_3 ) ;
} else {
F_9 ( V_2 ) ;
F_4 ( 1 , L_4 ) ;
V_6 -> V_15 = V_16 ;
}
return 0 ;
}
V_6 -> V_29 <<= 1 ;
if ( F_7 ( V_4 . V_17 , V_30 , V_20 / 2 ) )
V_6 -> V_29 |= 1 ;
else if ( ! F_7 ( V_4 . V_17 , V_31 , V_20 / 2 ) )
break;
V_6 -> V_21 ++ ;
if ( V_6 -> V_21 == V_32 )
V_6 -> V_15 = V_33 ;
else
V_6 -> V_15 = V_24 ;
return 0 ;
case V_33 :
if ( ! V_4 . V_18 )
break;
if ( ! F_7 ( V_4 . V_17 , V_34 , V_20 / 2 ) )
break;
V_6 -> V_15 = V_35 ;
return 0 ;
case V_35 :
if ( V_4 . V_18 )
break;
if ( ! F_8 ( V_4 . V_17 , V_36 , V_20 / 2 ) )
break;
V_10 = F_10 ( ( V_6 -> V_29 >> 29 ) & 0x1fff ) >> 3 ;
V_11 = F_11 ( ( V_6 -> V_29 >> 8 ) & 0xff ) ;
V_12 = F_11 ( ( V_6 -> V_29 >> 0 ) & 0xff ) ;
if ( ( V_11 ^ V_12 ) != 0xff ) {
F_4 ( 1 , L_5 ,
V_6 -> V_29 ) ;
V_6 -> V_15 = V_16 ;
return 0 ;
}
V_9 = V_10 << 8 | V_11 ;
F_4 ( 1 , L_6 , V_9 ) ;
F_12 ( V_2 , V_9 , 0 ) ;
V_6 -> V_15 = V_16 ;
return 0 ;
}
F_4 ( 1 , L_7 ,
V_6 -> V_21 , V_6 -> V_15 , F_5 ( V_4 . V_17 ) , F_6 ( V_4 . V_18 ) ) ;
V_6 -> V_15 = V_16 ;
return - V_37 ;
}
static int T_3 F_13 ( void )
{
F_14 ( & V_38 ) ;
F_15 ( V_39 L_8 ) ;
return 0 ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_38 ) ;
}
