static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 ;
T_2 V_10 , V_11 , V_12 , V_13 ;
bool V_14 = false ;
if ( ! ( V_2 -> V_7 -> V_15 & V_16 ) )
return 0 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_17 )
V_6 -> V_18 = V_19 ;
return 0 ;
}
F_3 ( 2 , L_1 ,
V_6 -> V_18 , F_4 ( V_4 . V_20 ) , F_5 ( V_4 . V_21 ) ) ;
switch ( V_6 -> V_18 ) {
case V_19 :
if ( ! V_4 . V_21 )
break;
if ( F_6 ( V_4 . V_20 , V_22 , V_23 * 2 ) ) {
V_6 -> V_24 = false ;
V_6 -> V_25 = false ;
} else if ( F_6 ( V_4 . V_20 , V_26 , V_23 / 2 ) )
V_6 -> V_24 = true ;
else
break;
V_6 -> V_27 = 0 ;
V_6 -> V_18 = V_28 ;
return 0 ;
case V_28 :
if ( V_4 . V_21 )
break;
if ( F_6 ( V_4 . V_20 , V_29 , V_23 ) ) {
V_6 -> V_18 = V_30 ;
return 0 ;
} else if ( F_6 ( V_4 . V_20 , V_31 , V_23 / 2 ) ) {
if ( ! V_2 -> V_32 ) {
F_3 ( 1 , L_2 ) ;
} else {
F_7 ( V_2 ) ;
F_3 ( 1 , L_3 ) ;
V_6 -> V_18 = V_33 ;
}
return 0 ;
}
break;
case V_30 :
if ( ! V_4 . V_21 )
break;
if ( ! F_6 ( V_4 . V_20 , V_34 , V_23 / 2 ) )
break;
V_6 -> V_18 = V_35 ;
return 0 ;
case V_35 :
if ( V_4 . V_21 )
break;
if ( V_6 -> V_25 && V_6 -> V_27 == V_36 &&
F_8 ( V_4 . V_20 ,
V_37 , V_23 / 2 ) ) {
F_3 ( 1 , L_3 ) ;
F_7 ( V_2 ) ;
V_6 -> V_18 = V_19 ;
return 0 ;
} else if ( V_6 -> V_27 > V_36 )
V_6 -> V_25 = false ;
V_6 -> V_38 <<= 1 ;
if ( F_6 ( V_4 . V_20 , V_39 , V_23 / 2 ) )
V_6 -> V_38 |= 1 ;
else if ( ! F_6 ( V_4 . V_20 , V_40 , V_23 / 2 ) )
break;
V_6 -> V_27 ++ ;
if ( V_6 -> V_27 == V_41 )
V_6 -> V_18 = V_33 ;
else
V_6 -> V_18 = V_30 ;
return 0 ;
case V_33 :
if ( ! V_4 . V_21 )
break;
if ( ! F_6 ( V_4 . V_20 , V_42 , V_23 / 2 ) )
break;
V_6 -> V_18 = V_43 ;
return 0 ;
case V_43 :
if ( V_4 . V_21 )
break;
if ( ! F_8 ( V_4 . V_20 , V_37 , V_23 / 2 ) )
break;
V_10 = F_9 ( ( V_6 -> V_38 >> 24 ) & 0xff ) ;
V_11 = F_9 ( ( V_6 -> V_38 >> 16 ) & 0xff ) ;
V_12 = F_9 ( ( V_6 -> V_38 >> 8 ) & 0xff ) ;
V_13 = F_9 ( ( V_6 -> V_38 >> 0 ) & 0xff ) ;
if ( ( V_12 ^ V_13 ) != 0xff ) {
F_3 ( 1 , L_4 ,
V_6 -> V_38 ) ;
V_14 = true ;
}
if ( V_14 ) {
V_9 = V_6 -> V_38 ;
F_3 ( 1 , L_5 , V_9 ) ;
} else if ( ( V_10 ^ V_11 ) != 0xff ) {
V_9 = V_10 << 16 |
V_11 << 8 |
V_12 ;
F_3 ( 1 , L_6 , V_9 ) ;
} else {
V_9 = V_10 << 8 | V_12 ;
F_3 ( 1 , L_7 , V_9 ) ;
}
if ( V_6 -> V_24 )
V_6 -> V_25 = true ;
F_10 ( V_2 , V_9 , 0 ) ;
V_6 -> V_18 = V_19 ;
return 0 ;
}
F_3 ( 1 , L_8 ,
V_6 -> V_27 , V_6 -> V_18 , F_4 ( V_4 . V_20 ) , F_5 ( V_4 . V_21 ) ) ;
V_6 -> V_18 = V_19 ;
return - V_44 ;
}
static int T_3 F_11 ( void )
{
F_12 ( & V_45 ) ;
F_13 ( V_46 L_9 ) ;
return 0 ;
}
static void T_4 F_14 ( void )
{
F_15 ( & V_45 ) ;
}
