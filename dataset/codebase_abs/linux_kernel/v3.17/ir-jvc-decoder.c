static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
if ( ! ( V_2 -> V_9 & V_10 ) )
return 0 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_11 )
V_6 -> V_12 = V_13 ;
return 0 ;
}
if ( ! F_3 ( V_4 . V_14 , V_15 , V_15 / 2 ) )
goto V_16;
F_4 ( 2 , L_1 ,
V_6 -> V_12 , F_5 ( V_4 . V_14 ) , F_6 ( V_4 . V_17 ) ) ;
V_18:
switch ( V_6 -> V_12 ) {
case V_13 :
if ( ! V_4 . V_17 )
break;
if ( ! F_7 ( V_4 . V_14 , V_19 , V_15 / 2 ) )
break;
V_6 -> V_20 = 0 ;
V_6 -> V_21 = true ;
V_6 -> V_22 = ! V_6 -> V_22 ;
V_6 -> V_12 = V_23 ;
return 0 ;
case V_23 :
if ( V_4 . V_17 )
break;
if ( ! F_7 ( V_4 . V_14 , V_24 , V_15 / 2 ) )
break;
V_6 -> V_12 = V_25 ;
return 0 ;
case V_25 :
if ( ! V_4 . V_17 )
break;
if ( ! F_7 ( V_4 . V_14 , V_26 , V_15 / 2 ) )
break;
V_6 -> V_12 = V_27 ;
return 0 ;
case V_27 :
if ( V_4 . V_17 )
break;
V_6 -> V_28 <<= 1 ;
if ( F_7 ( V_4 . V_14 , V_29 , V_15 / 2 ) ) {
V_6 -> V_28 |= 1 ;
F_8 ( & V_4 , V_29 ) ;
} else if ( F_7 ( V_4 . V_14 , V_30 , V_15 / 2 ) )
F_8 ( & V_4 , V_30 ) ;
else
break;
V_6 -> V_20 ++ ;
if ( V_6 -> V_20 == V_31 )
V_6 -> V_12 = V_32 ;
else
V_6 -> V_12 = V_25 ;
return 0 ;
case V_32 :
if ( ! V_4 . V_17 )
break;
if ( ! F_7 ( V_4 . V_14 , V_33 , V_15 / 2 ) )
break;
V_6 -> V_12 = V_34 ;
return 0 ;
case V_34 :
if ( V_4 . V_17 )
break;
if ( ! F_3 ( V_4 . V_14 , V_35 , V_15 / 2 ) )
break;
if ( V_6 -> V_21 ) {
T_1 V_36 ;
V_36 = ( F_9 ( ( V_6 -> V_28 >> 8 ) & 0xff ) << 8 ) |
( F_9 ( ( V_6 -> V_28 >> 0 ) & 0xff ) << 0 ) ;
F_4 ( 1 , L_2 , V_36 ) ;
F_10 ( V_2 , V_37 , V_36 , V_6 -> V_22 ) ;
V_6 -> V_21 = false ;
V_6 -> V_38 = V_6 -> V_28 ;
} else if ( V_6 -> V_28 == V_6 -> V_38 ) {
F_4 ( 1 , L_3 ) ;
F_11 ( V_2 ) ;
} else {
F_4 ( 1 , L_4 ) ;
break;
}
V_6 -> V_20 = 0 ;
V_6 -> V_12 = V_39 ;
return 0 ;
case V_39 :
if ( ! V_4 . V_17 )
break;
if ( F_7 ( V_4 . V_14 , V_19 , V_15 / 2 ) )
V_6 -> V_12 = V_13 ;
else
V_6 -> V_12 = V_25 ;
goto V_18;
}
V_16:
F_4 ( 1 , L_5 ,
V_6 -> V_12 , F_5 ( V_4 . V_14 ) , F_6 ( V_4 . V_17 ) ) ;
V_6 -> V_12 = V_13 ;
return - V_40 ;
}
static int T_2 F_12 ( void )
{
F_13 ( & V_41 ) ;
F_14 ( V_42 L_6 ) ;
return 0 ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_41 ) ;
}
