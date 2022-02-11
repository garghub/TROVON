static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 ;
T_2 V_10 , V_11 , V_12 , V_13 ;
bool V_14 = false ;
if ( ! F_2 ( V_2 , V_15 ) )
return 0 ;
if ( ! F_3 ( V_4 ) ) {
if ( V_4 . V_16 )
V_6 -> V_17 = V_18 ;
return 0 ;
}
F_4 ( 2 , L_1 ,
V_6 -> V_17 , F_5 ( V_4 . V_19 ) , F_6 ( V_4 . V_20 ) ) ;
switch ( V_6 -> V_17 ) {
case V_18 :
if ( ! V_4 . V_20 )
break;
if ( F_7 ( V_4 . V_19 , V_21 , V_22 * 2 ) ) {
V_6 -> V_23 = false ;
V_6 -> V_24 = false ;
} else if ( F_7 ( V_4 . V_19 , V_25 , V_22 / 2 ) )
V_6 -> V_23 = true ;
else
break;
V_6 -> V_26 = 0 ;
V_6 -> V_17 = V_27 ;
return 0 ;
case V_27 :
if ( V_4 . V_20 )
break;
if ( F_7 ( V_4 . V_19 , V_28 , V_22 ) ) {
V_6 -> V_17 = V_29 ;
return 0 ;
} else if ( F_7 ( V_4 . V_19 , V_30 , V_22 / 2 ) ) {
if ( ! V_2 -> V_31 ) {
F_4 ( 1 , L_2 ) ;
} else {
F_8 ( V_2 ) ;
F_4 ( 1 , L_3 ) ;
V_6 -> V_17 = V_32 ;
}
return 0 ;
}
break;
case V_29 :
if ( ! V_4 . V_20 )
break;
if ( ! F_7 ( V_4 . V_19 , V_33 , V_22 / 2 ) )
break;
V_6 -> V_17 = V_34 ;
return 0 ;
case V_34 :
if ( V_4 . V_20 )
break;
if ( V_6 -> V_24 && V_6 -> V_26 == V_35 &&
F_9 ( V_4 . V_19 ,
V_36 , V_22 / 2 ) ) {
F_4 ( 1 , L_3 ) ;
F_8 ( V_2 ) ;
V_6 -> V_17 = V_18 ;
return 0 ;
} else if ( V_6 -> V_26 > V_35 )
V_6 -> V_24 = false ;
V_6 -> V_37 <<= 1 ;
if ( F_7 ( V_4 . V_19 , V_38 , V_22 / 2 ) )
V_6 -> V_37 |= 1 ;
else if ( ! F_7 ( V_4 . V_19 , V_39 , V_22 / 2 ) )
break;
V_6 -> V_26 ++ ;
if ( V_6 -> V_26 == V_40 )
V_6 -> V_17 = V_32 ;
else
V_6 -> V_17 = V_29 ;
return 0 ;
case V_32 :
if ( ! V_4 . V_20 )
break;
if ( ! F_7 ( V_4 . V_19 , V_41 , V_22 / 2 ) )
break;
V_6 -> V_17 = V_42 ;
return 0 ;
case V_42 :
if ( V_4 . V_20 )
break;
if ( ! F_9 ( V_4 . V_19 , V_36 , V_22 / 2 ) )
break;
V_10 = F_10 ( ( V_6 -> V_37 >> 24 ) & 0xff ) ;
V_11 = F_10 ( ( V_6 -> V_37 >> 16 ) & 0xff ) ;
V_12 = F_10 ( ( V_6 -> V_37 >> 8 ) & 0xff ) ;
V_13 = F_10 ( ( V_6 -> V_37 >> 0 ) & 0xff ) ;
if ( ( V_12 ^ V_13 ) != 0xff ) {
F_4 ( 1 , L_4 ,
V_6 -> V_37 ) ;
V_14 = true ;
}
if ( V_14 ) {
V_9 = V_6 -> V_37 ;
F_4 ( 1 , L_5 , V_9 ) ;
} else if ( ( V_10 ^ V_11 ) != 0xff ) {
V_9 = V_10 << 16 |
V_11 << 8 |
V_12 ;
F_4 ( 1 , L_6 , V_9 ) ;
} else {
V_9 = V_10 << 8 | V_12 ;
F_4 ( 1 , L_7 , V_9 ) ;
}
if ( V_6 -> V_23 )
V_6 -> V_24 = true ;
F_11 ( V_2 , V_9 , 0 ) ;
V_6 -> V_17 = V_18 ;
return 0 ;
}
F_4 ( 1 , L_8 ,
V_6 -> V_26 , V_6 -> V_17 , F_5 ( V_4 . V_19 ) , F_6 ( V_4 . V_20 ) ) ;
V_6 -> V_17 = V_18 ;
return - V_43 ;
}
static int T_3 F_12 ( void )
{
F_13 ( & V_44 ) ;
F_14 ( V_45 L_9 ) ;
return 0 ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_44 ) ;
}
