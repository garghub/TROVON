static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 ;
T_2 V_10 , V_11 , V_12 , V_13 ;
bool V_14 = false ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_15 )
V_6 -> V_16 = V_17 ;
return 0 ;
}
F_3 ( 2 , L_1 ,
V_6 -> V_16 , F_4 ( V_4 . V_18 ) , F_5 ( V_4 . V_19 ) ) ;
switch ( V_6 -> V_16 ) {
case V_17 :
if ( ! V_4 . V_19 )
break;
if ( F_6 ( V_4 . V_18 , V_20 , V_21 * 2 ) ) {
V_6 -> V_22 = false ;
V_6 -> V_23 = false ;
} else if ( F_6 ( V_4 . V_18 , V_24 , V_21 / 2 ) )
V_6 -> V_22 = true ;
else
break;
V_6 -> V_25 = 0 ;
V_6 -> V_16 = V_26 ;
return 0 ;
case V_26 :
if ( V_4 . V_19 )
break;
if ( F_6 ( V_4 . V_18 , V_27 , V_21 ) ) {
V_6 -> V_16 = V_28 ;
return 0 ;
} else if ( F_6 ( V_4 . V_18 , V_29 , V_21 / 2 ) ) {
if ( ! V_2 -> V_30 ) {
F_3 ( 1 , L_2 ) ;
} else {
F_7 ( V_2 ) ;
F_3 ( 1 , L_3 ) ;
V_6 -> V_16 = V_31 ;
}
return 0 ;
}
break;
case V_28 :
if ( ! V_4 . V_19 )
break;
if ( ! F_6 ( V_4 . V_18 , V_32 , V_21 / 2 ) )
break;
V_6 -> V_16 = V_33 ;
return 0 ;
case V_33 :
if ( V_4 . V_19 )
break;
if ( V_6 -> V_23 && V_6 -> V_25 == V_34 &&
F_8 ( V_4 . V_18 ,
V_35 , V_21 / 2 ) ) {
F_3 ( 1 , L_3 ) ;
F_7 ( V_2 ) ;
V_6 -> V_16 = V_17 ;
return 0 ;
} else if ( V_6 -> V_25 > V_34 )
V_6 -> V_23 = false ;
V_6 -> V_36 <<= 1 ;
if ( F_6 ( V_4 . V_18 , V_37 , V_21 / 2 ) )
V_6 -> V_36 |= 1 ;
else if ( ! F_6 ( V_4 . V_18 , V_38 , V_21 / 2 ) )
break;
V_6 -> V_25 ++ ;
if ( V_6 -> V_25 == V_39 )
V_6 -> V_16 = V_31 ;
else
V_6 -> V_16 = V_28 ;
return 0 ;
case V_31 :
if ( ! V_4 . V_19 )
break;
if ( ! F_6 ( V_4 . V_18 , V_40 , V_21 / 2 ) )
break;
V_6 -> V_16 = V_41 ;
return 0 ;
case V_41 :
if ( V_4 . V_19 )
break;
if ( ! F_8 ( V_4 . V_18 , V_35 , V_21 / 2 ) )
break;
V_10 = F_9 ( ( V_6 -> V_36 >> 24 ) & 0xff ) ;
V_11 = F_9 ( ( V_6 -> V_36 >> 16 ) & 0xff ) ;
V_12 = F_9 ( ( V_6 -> V_36 >> 8 ) & 0xff ) ;
V_13 = F_9 ( ( V_6 -> V_36 >> 0 ) & 0xff ) ;
if ( ( V_12 ^ V_13 ) != 0xff ) {
F_3 ( 1 , L_4 ,
V_6 -> V_36 ) ;
V_14 = true ;
}
if ( V_14 ) {
V_9 = V_6 -> V_36 ;
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
if ( V_6 -> V_22 )
V_6 -> V_23 = true ;
F_10 ( V_2 , V_42 , V_9 , 0 ) ;
V_6 -> V_16 = V_17 ;
return 0 ;
}
F_3 ( 1 , L_8 ,
V_6 -> V_25 , V_6 -> V_16 , F_4 ( V_4 . V_18 ) , F_5 ( V_4 . V_19 ) ) ;
V_6 -> V_16 = V_17 ;
return - V_43 ;
}
static int T_3 F_11 ( void )
{
F_12 ( & V_44 ) ;
F_13 ( V_45 L_9 ) ;
return 0 ;
}
static void T_4 F_14 ( void )
{
F_15 ( & V_44 ) ;
}
