static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return 0 ;
if ( ! F_3 ( V_4 ) ) {
if ( V_4 . V_10 )
V_6 -> V_11 = V_12 ;
return 0 ;
}
if ( ! F_4 ( V_4 . V_13 , V_14 , V_14 / 2 ) )
goto V_15;
F_5 ( 2 , L_1 ,
V_6 -> V_11 , F_6 ( V_4 . V_13 ) , F_7 ( V_4 . V_16 ) ) ;
V_17:
switch ( V_6 -> V_11 ) {
case V_12 :
if ( ! V_4 . V_16 )
break;
if ( ! F_8 ( V_4 . V_13 , V_18 , V_14 / 2 ) )
break;
V_6 -> V_19 = 0 ;
V_6 -> V_20 = true ;
V_6 -> V_21 = ! V_6 -> V_21 ;
V_6 -> V_11 = V_22 ;
return 0 ;
case V_22 :
if ( V_4 . V_16 )
break;
if ( ! F_8 ( V_4 . V_13 , V_23 , V_14 / 2 ) )
break;
V_6 -> V_11 = V_24 ;
return 0 ;
case V_24 :
if ( ! V_4 . V_16 )
break;
if ( ! F_8 ( V_4 . V_13 , V_25 , V_14 / 2 ) )
break;
V_6 -> V_11 = V_26 ;
return 0 ;
case V_26 :
if ( V_4 . V_16 )
break;
V_6 -> V_27 <<= 1 ;
if ( F_8 ( V_4 . V_13 , V_28 , V_14 / 2 ) ) {
V_6 -> V_27 |= 1 ;
F_9 ( & V_4 , V_28 ) ;
} else if ( F_8 ( V_4 . V_13 , V_29 , V_14 / 2 ) )
F_9 ( & V_4 , V_29 ) ;
else
break;
V_6 -> V_19 ++ ;
if ( V_6 -> V_19 == V_30 )
V_6 -> V_11 = V_31 ;
else
V_6 -> V_11 = V_24 ;
return 0 ;
case V_31 :
if ( ! V_4 . V_16 )
break;
if ( ! F_8 ( V_4 . V_13 , V_32 , V_14 / 2 ) )
break;
V_6 -> V_11 = V_33 ;
return 0 ;
case V_33 :
if ( V_4 . V_16 )
break;
if ( ! F_4 ( V_4 . V_13 , V_34 , V_14 / 2 ) )
break;
if ( V_6 -> V_20 ) {
T_1 V_35 ;
V_35 = ( F_10 ( ( V_6 -> V_27 >> 8 ) & 0xff ) << 8 ) |
( F_10 ( ( V_6 -> V_27 >> 0 ) & 0xff ) << 0 ) ;
F_5 ( 1 , L_2 , V_35 ) ;
F_11 ( V_2 , V_35 , V_6 -> V_21 ) ;
V_6 -> V_20 = false ;
V_6 -> V_36 = V_6 -> V_27 ;
} else if ( V_6 -> V_27 == V_6 -> V_36 ) {
F_5 ( 1 , L_3 ) ;
F_12 ( V_2 ) ;
} else {
F_5 ( 1 , L_4 ) ;
break;
}
V_6 -> V_19 = 0 ;
V_6 -> V_11 = V_37 ;
return 0 ;
case V_37 :
if ( ! V_4 . V_16 )
break;
if ( F_8 ( V_4 . V_13 , V_18 , V_14 / 2 ) )
V_6 -> V_11 = V_12 ;
else
V_6 -> V_11 = V_24 ;
goto V_17;
}
V_15:
F_5 ( 1 , L_5 ,
V_6 -> V_11 , F_6 ( V_4 . V_13 ) , F_7 ( V_4 . V_16 ) ) ;
V_6 -> V_11 = V_12 ;
return - V_38 ;
}
static int T_2 F_13 ( void )
{
F_14 ( & V_39 ) ;
F_15 ( V_40 L_6 ) ;
return 0 ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_39 ) ;
}
