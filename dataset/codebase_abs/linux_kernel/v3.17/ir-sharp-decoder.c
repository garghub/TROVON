static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
T_1 V_9 , V_10 , V_11 , V_12 , V_13 ;
if ( ! ( V_2 -> V_14 & V_15 ) )
return 0 ;
if ( ! F_2 ( V_4 ) ) {
if ( V_4 . V_16 )
V_6 -> V_17 = V_18 ;
return 0 ;
}
F_3 ( 2 , L_1 ,
V_6 -> V_17 , F_4 ( V_4 . V_19 ) , F_5 ( V_4 . V_20 ) ) ;
switch ( V_6 -> V_17 ) {
case V_18 :
if ( ! V_4 . V_20 )
break;
if ( ! F_6 ( V_4 . V_19 , V_21 ,
V_21 / 2 ) )
break;
V_6 -> V_22 = 0 ;
V_6 -> V_23 = V_4 . V_19 ;
V_6 -> V_17 = V_24 ;
return 0 ;
case V_25 :
if ( ! V_4 . V_20 )
break;
if ( ! F_6 ( V_4 . V_19 , V_21 ,
V_21 / 2 ) )
break;
V_6 -> V_23 = V_4 . V_19 ;
V_6 -> V_17 = V_24 ;
return 0 ;
case V_24 :
if ( V_4 . V_20 )
break;
V_6 -> V_26 <<= 1 ;
if ( F_6 ( V_6 -> V_23 + V_4 . V_19 , V_27 ,
V_21 * 2 ) )
V_6 -> V_26 |= 1 ;
else if ( ! F_6 ( V_6 -> V_23 + V_4 . V_19 ,
V_28 , V_21 * 2 ) )
break;
V_6 -> V_22 ++ ;
if ( V_6 -> V_22 == V_29 ||
V_6 -> V_22 == V_29 * 2 )
V_6 -> V_17 = V_30 ;
else
V_6 -> V_17 = V_25 ;
return 0 ;
case V_30 :
if ( ! V_4 . V_20 )
break;
if ( ! F_6 ( V_4 . V_19 , V_21 ,
V_21 / 2 ) )
break;
if ( V_6 -> V_22 == V_29 ) {
if ( ( V_6 -> V_26 & 0x3 ) != 0x2 )
break;
V_6 -> V_17 = V_31 ;
} else {
V_6 -> V_17 = V_32 ;
}
return 0 ;
case V_31 :
if ( V_4 . V_20 )
break;
if ( ! F_6 ( V_4 . V_19 , V_33 ,
V_33 / 4 ) )
break;
V_6 -> V_17 = V_25 ;
return 0 ;
case V_32 :
if ( V_4 . V_20 )
break;
if ( ! F_7 ( V_4 . V_19 , V_34 ,
V_21 / 2 ) )
break;
V_9 = ( V_6 -> V_26 >> 15 ) & 0x7fff ;
V_10 = V_6 -> V_26 & 0x7fff ;
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
F_9 ( V_2 , V_35 , V_13 , 0 ) ;
V_6 -> V_17 = V_18 ;
return 0 ;
}
F_3 ( 1 , L_4 ,
V_6 -> V_22 , V_6 -> V_17 , F_4 ( V_4 . V_19 ) ,
F_5 ( V_4 . V_20 ) ) ;
V_6 -> V_17 = V_18 ;
return - V_36 ;
}
static int T_2 F_10 ( void )
{
F_11 ( & V_37 ) ;
F_12 ( L_5 ) ;
return 0 ;
}
static void T_3 F_13 ( void )
{
F_14 ( & V_37 ) ;
}
