static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 , V_10 , V_11 , V_12 , V_13 ;
if ( ! F_2 ( V_2 , V_14 ) )
return 0 ;
if ( ! F_3 ( V_4 ) ) {
if ( V_4 . V_15 )
V_6 -> V_16 = V_17 ;
return 0 ;
}
F_4 ( 2 , L_1 ,
V_6 -> V_16 , F_5 ( V_4 . V_18 ) , F_6 ( V_4 . V_19 ) ) ;
switch ( V_6 -> V_16 ) {
case V_17 :
if ( ! V_4 . V_19 )
break;
if ( ! F_7 ( V_4 . V_18 , V_20 ,
V_20 / 2 ) )
break;
V_6 -> V_21 = 0 ;
V_6 -> V_22 = V_4 . V_18 ;
V_6 -> V_16 = V_23 ;
return 0 ;
case V_24 :
if ( ! V_4 . V_19 )
break;
if ( ! F_7 ( V_4 . V_18 , V_20 ,
V_20 / 2 ) )
break;
V_6 -> V_22 = V_4 . V_18 ;
V_6 -> V_16 = V_23 ;
return 0 ;
case V_23 :
if ( V_4 . V_19 )
break;
V_6 -> V_25 <<= 1 ;
if ( F_7 ( V_6 -> V_22 + V_4 . V_18 , V_26 ,
V_20 * 2 ) )
V_6 -> V_25 |= 1 ;
else if ( ! F_7 ( V_6 -> V_22 + V_4 . V_18 ,
V_27 , V_20 * 2 ) )
break;
V_6 -> V_21 ++ ;
if ( V_6 -> V_21 == V_28 ||
V_6 -> V_21 == V_28 * 2 )
V_6 -> V_16 = V_29 ;
else
V_6 -> V_16 = V_24 ;
return 0 ;
case V_29 :
if ( ! V_4 . V_19 )
break;
if ( ! F_7 ( V_4 . V_18 , V_20 ,
V_20 / 2 ) )
break;
if ( V_6 -> V_21 == V_28 ) {
if ( ( V_6 -> V_25 & 0x3 ) != 0x2 )
break;
V_6 -> V_16 = V_30 ;
} else {
V_6 -> V_16 = V_31 ;
}
return 0 ;
case V_30 :
if ( V_4 . V_19 )
break;
if ( ! F_7 ( V_4 . V_18 , V_32 ,
V_32 / 4 ) )
break;
V_6 -> V_16 = V_24 ;
return 0 ;
case V_31 :
if ( V_4 . V_19 )
break;
if ( ! F_8 ( V_4 . V_18 , V_33 ,
V_20 / 2 ) )
break;
V_9 = ( V_6 -> V_25 >> 15 ) & 0x7fff ;
V_10 = V_6 -> V_25 & 0x7fff ;
if ( ( V_9 ^ V_10 ) != 0x3ff ) {
F_4 ( 1 ,
L_2 ,
V_9 , V_10 ) ;
break;
}
V_11 = F_9 ( ( V_9 >> 7 ) & 0xf8 ) ;
V_12 = F_9 ( ( V_9 >> 2 ) & 0xff ) ;
V_13 = V_11 << 8 | V_12 ;
F_4 ( 1 , L_3 , V_13 ) ;
F_10 ( V_2 , V_13 , 0 ) ;
V_6 -> V_16 = V_17 ;
return 0 ;
}
F_4 ( 1 , L_4 ,
V_6 -> V_21 , V_6 -> V_16 , F_5 ( V_4 . V_18 ) ,
F_6 ( V_4 . V_19 ) ) ;
V_6 -> V_16 = V_17 ;
return - V_34 ;
}
static int T_2 F_11 ( void )
{
F_12 ( & V_35 ) ;
F_13 ( L_5 ) ;
return 0 ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_35 ) ;
}
