static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 , V_10 , V_11 , V_12 , V_13 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_14 )
V_6 -> V_15 = V_16 ;
return 0 ;
}
F_3 ( 2 , L_1 ,
V_6 -> V_15 , F_4 ( V_4 . V_17 ) , F_5 ( V_4 . V_18 ) ) ;
switch ( V_6 -> V_15 ) {
case V_16 :
if ( ! V_4 . V_18 )
break;
if ( ! F_6 ( V_4 . V_17 , V_19 ,
V_19 / 2 ) )
break;
V_6 -> V_20 = 0 ;
V_6 -> V_21 = V_4 . V_17 ;
V_6 -> V_15 = V_22 ;
return 0 ;
case V_23 :
if ( ! V_4 . V_18 )
break;
if ( ! F_6 ( V_4 . V_17 , V_19 ,
V_19 / 2 ) )
break;
V_6 -> V_21 = V_4 . V_17 ;
V_6 -> V_15 = V_22 ;
return 0 ;
case V_22 :
if ( V_4 . V_18 )
break;
V_6 -> V_24 <<= 1 ;
if ( F_6 ( V_6 -> V_21 + V_4 . V_17 , V_25 ,
V_19 * 2 ) )
V_6 -> V_24 |= 1 ;
else if ( ! F_6 ( V_6 -> V_21 + V_4 . V_17 ,
V_26 , V_19 * 2 ) )
break;
V_6 -> V_20 ++ ;
if ( V_6 -> V_20 == V_27 ||
V_6 -> V_20 == V_27 * 2 )
V_6 -> V_15 = V_28 ;
else
V_6 -> V_15 = V_23 ;
return 0 ;
case V_28 :
if ( ! V_4 . V_18 )
break;
if ( ! F_6 ( V_4 . V_17 , V_19 ,
V_19 / 2 ) )
break;
if ( V_6 -> V_20 == V_27 ) {
if ( ( V_6 -> V_24 & 0x3 ) != 0x2 &&
( V_6 -> V_24 & 0x3 ) != 0x0 )
break;
V_6 -> V_15 = V_29 ;
} else {
V_6 -> V_15 = V_30 ;
}
return 0 ;
case V_29 :
if ( V_4 . V_18 )
break;
if ( ! F_6 ( V_4 . V_17 , V_31 ,
V_31 / 4 ) )
break;
V_6 -> V_15 = V_23 ;
return 0 ;
case V_30 :
if ( V_4 . V_18 )
break;
if ( ! F_7 ( V_4 . V_17 , V_32 ,
V_19 / 2 ) )
break;
V_9 = ( V_6 -> V_24 >> 15 ) & 0x7fff ;
V_10 = V_6 -> V_24 & 0x7fff ;
if ( ( V_9 ^ V_10 ) != 0x3ff ) {
F_3 ( 1 ,
L_2 ,
V_9 , V_10 ) ;
break;
}
V_11 = F_8 ( ( V_9 >> 7 ) & 0xf8 ) ;
V_12 = F_8 ( ( V_9 >> 2 ) & 0xff ) ;
V_13 = V_11 << 8 | V_12 ;
F_3 ( 1 , L_3 , V_13 ) ;
F_9 ( V_2 , V_33 , V_13 , 0 ) ;
V_6 -> V_15 = V_16 ;
return 0 ;
}
F_3 ( 1 , L_4 ,
V_6 -> V_20 , V_6 -> V_15 , F_4 ( V_4 . V_17 ) ,
F_5 ( V_4 . V_18 ) ) ;
V_6 -> V_15 = V_16 ;
return - V_34 ;
}
static int T_2 F_10 ( void )
{
F_11 ( & V_35 ) ;
F_12 ( L_5 ) ;
return 0 ;
}
static void T_3 F_13 ( void )
{
F_14 ( & V_35 ) ;
}
