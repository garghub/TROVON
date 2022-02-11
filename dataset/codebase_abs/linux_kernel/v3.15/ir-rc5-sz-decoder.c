static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 , V_10 , system ;
T_2 V_11 ;
if ( ! F_2 ( V_2 , V_12 ) )
return 0 ;
if ( ! F_3 ( V_4 ) ) {
if ( V_4 . V_13 )
V_6 -> V_14 = V_15 ;
return 0 ;
}
if ( ! F_4 ( V_4 . V_16 , V_17 , V_17 / 2 ) )
goto V_18;
V_19:
F_5 ( 2 , L_1 ,
V_6 -> V_14 , F_6 ( V_4 . V_16 ) , F_7 ( V_4 . V_20 ) ) ;
if ( ! F_4 ( V_4 . V_16 , V_17 , V_17 / 2 ) )
return 0 ;
switch ( V_6 -> V_14 ) {
case V_15 :
if ( ! V_4 . V_20 )
break;
V_6 -> V_14 = V_21 ;
V_6 -> V_22 = 1 ;
V_6 -> V_23 = V_24 ;
F_8 ( & V_4 , V_25 ) ;
goto V_19;
case V_21 :
if ( ! F_9 ( V_4 . V_16 , V_25 , V_17 / 2 ) )
break;
V_6 -> V_26 <<= 1 ;
if ( ! V_4 . V_20 )
V_6 -> V_26 |= 1 ;
V_6 -> V_22 ++ ;
V_6 -> V_14 = V_27 ;
return 0 ;
case V_27 :
if ( ! F_10 ( & V_4 , & V_2 -> V_7 -> V_28 ) )
break;
if ( V_6 -> V_22 == V_6 -> V_23 )
V_6 -> V_14 = V_29 ;
else
V_6 -> V_14 = V_21 ;
F_8 ( & V_4 , V_30 ) ;
goto V_19;
case V_29 :
if ( V_4 . V_20 )
break;
V_10 = ( V_6 -> V_26 & 0x0003F ) >> 0 ;
system = ( V_6 -> V_26 & 0x02FC0 ) >> 6 ;
V_9 = ( V_6 -> V_26 & 0x01000 ) ? 1 : 0 ;
V_11 = system << 6 | V_10 ;
F_5 ( 1 , L_2 ,
V_11 , V_9 ) ;
F_11 ( V_2 , V_11 , V_9 ) ;
V_6 -> V_14 = V_15 ;
return 0 ;
}
V_18:
F_5 ( 1 , L_3 ,
V_6 -> V_14 , F_6 ( V_4 . V_16 ) , F_7 ( V_4 . V_20 ) ) ;
V_6 -> V_14 = V_15 ;
return - V_31 ;
}
static int T_3 F_12 ( void )
{
F_13 ( & V_32 ) ;
F_14 ( V_33 L_4 ) ;
return 0 ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_32 ) ;
}
