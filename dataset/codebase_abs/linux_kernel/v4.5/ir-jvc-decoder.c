static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_9 )
V_6 -> V_10 = V_11 ;
return 0 ;
}
if ( ! F_3 ( V_4 . V_12 , V_13 , V_13 / 2 ) )
goto V_14;
F_4 ( 2 , L_1 ,
V_6 -> V_10 , F_5 ( V_4 . V_12 ) , F_6 ( V_4 . V_15 ) ) ;
V_16:
switch ( V_6 -> V_10 ) {
case V_11 :
if ( ! V_4 . V_15 )
break;
if ( ! F_7 ( V_4 . V_12 , V_17 , V_13 / 2 ) )
break;
V_6 -> V_18 = 0 ;
V_6 -> V_19 = true ;
V_6 -> V_20 = ! V_6 -> V_20 ;
V_6 -> V_10 = V_21 ;
return 0 ;
case V_21 :
if ( V_4 . V_15 )
break;
if ( ! F_7 ( V_4 . V_12 , V_22 , V_13 / 2 ) )
break;
V_6 -> V_10 = V_23 ;
return 0 ;
case V_23 :
if ( ! V_4 . V_15 )
break;
if ( ! F_7 ( V_4 . V_12 , V_24 , V_13 / 2 ) )
break;
V_6 -> V_10 = V_25 ;
return 0 ;
case V_25 :
if ( V_4 . V_15 )
break;
V_6 -> V_26 <<= 1 ;
if ( F_7 ( V_4 . V_12 , V_27 , V_13 / 2 ) ) {
V_6 -> V_26 |= 1 ;
F_8 ( & V_4 , V_27 ) ;
} else if ( F_7 ( V_4 . V_12 , V_28 , V_13 / 2 ) )
F_8 ( & V_4 , V_28 ) ;
else
break;
V_6 -> V_18 ++ ;
if ( V_6 -> V_18 == V_29 )
V_6 -> V_10 = V_30 ;
else
V_6 -> V_10 = V_23 ;
return 0 ;
case V_30 :
if ( ! V_4 . V_15 )
break;
if ( ! F_7 ( V_4 . V_12 , V_31 , V_13 / 2 ) )
break;
V_6 -> V_10 = V_32 ;
return 0 ;
case V_32 :
if ( V_4 . V_15 )
break;
if ( ! F_3 ( V_4 . V_12 , V_33 , V_13 / 2 ) )
break;
if ( V_6 -> V_19 ) {
T_1 V_34 ;
V_34 = ( F_9 ( ( V_6 -> V_26 >> 8 ) & 0xff ) << 8 ) |
( F_9 ( ( V_6 -> V_26 >> 0 ) & 0xff ) << 0 ) ;
F_4 ( 1 , L_2 , V_34 ) ;
F_10 ( V_2 , V_35 , V_34 , V_6 -> V_20 ) ;
V_6 -> V_19 = false ;
V_6 -> V_36 = V_6 -> V_26 ;
} else if ( V_6 -> V_26 == V_6 -> V_36 ) {
F_4 ( 1 , L_3 ) ;
F_11 ( V_2 ) ;
} else {
F_4 ( 1 , L_4 ) ;
break;
}
V_6 -> V_18 = 0 ;
V_6 -> V_10 = V_37 ;
return 0 ;
case V_37 :
if ( ! V_4 . V_15 )
break;
if ( F_7 ( V_4 . V_12 , V_17 , V_13 / 2 ) )
V_6 -> V_10 = V_11 ;
else
V_6 -> V_10 = V_23 ;
goto V_16;
}
V_14:
F_4 ( 1 , L_5 ,
V_6 -> V_10 , F_5 ( V_4 . V_12 ) , F_6 ( V_4 . V_15 ) ) ;
V_6 -> V_10 = V_11 ;
return - V_38 ;
}
static int T_2 F_12 ( void )
{
F_13 ( & V_39 ) ;
F_14 ( V_40 L_6 ) ;
return 0 ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_39 ) ;
}
