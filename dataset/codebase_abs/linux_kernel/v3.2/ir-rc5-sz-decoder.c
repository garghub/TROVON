static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 , V_10 , system ;
T_2 V_11 ;
if ( ! ( V_2 -> V_7 -> V_12 & V_13 ) )
return 0 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_14 )
V_6 -> V_15 = V_16 ;
return 0 ;
}
if ( ! F_3 ( V_4 . V_17 , V_18 , V_18 / 2 ) )
goto V_19;
V_20:
F_4 ( 2 , L_1 ,
V_6 -> V_15 , F_5 ( V_4 . V_17 ) , F_6 ( V_4 . V_21 ) ) ;
if ( ! F_3 ( V_4 . V_17 , V_18 , V_18 / 2 ) )
return 0 ;
switch ( V_6 -> V_15 ) {
case V_16 :
if ( ! V_4 . V_21 )
break;
V_6 -> V_15 = V_22 ;
V_6 -> V_23 = 1 ;
V_6 -> V_24 = V_25 ;
F_7 ( & V_4 , V_26 ) ;
goto V_20;
case V_22 :
if ( ! F_8 ( V_4 . V_17 , V_26 , V_18 / 2 ) )
break;
V_6 -> V_27 <<= 1 ;
if ( ! V_4 . V_21 )
V_6 -> V_27 |= 1 ;
V_6 -> V_23 ++ ;
V_6 -> V_15 = V_28 ;
return 0 ;
case V_28 :
if ( ! F_9 ( & V_4 , & V_2 -> V_7 -> V_29 ) )
break;
if ( V_6 -> V_23 == V_6 -> V_24 )
V_6 -> V_15 = V_30 ;
else
V_6 -> V_15 = V_22 ;
F_7 ( & V_4 , V_31 ) ;
goto V_20;
case V_30 :
if ( V_4 . V_21 )
break;
V_10 = ( V_6 -> V_27 & 0x0003F ) >> 0 ;
system = ( V_6 -> V_27 & 0x02FC0 ) >> 6 ;
V_9 = ( V_6 -> V_27 & 0x01000 ) ? 1 : 0 ;
V_11 = system << 6 | V_10 ;
F_4 ( 1 , L_2 ,
V_11 , V_9 ) ;
F_10 ( V_2 , V_11 , V_9 ) ;
V_6 -> V_15 = V_16 ;
return 0 ;
}
V_19:
F_4 ( 1 , L_3 ,
V_6 -> V_15 , F_5 ( V_4 . V_17 ) , F_6 ( V_4 . V_21 ) ) ;
V_6 -> V_15 = V_16 ;
return - V_32 ;
}
static int T_3 F_11 ( void )
{
F_12 ( & V_33 ) ;
F_13 ( V_34 L_4 ) ;
return 0 ;
}
static void T_4 F_14 ( void )
{
F_15 ( & V_33 ) ;
}
