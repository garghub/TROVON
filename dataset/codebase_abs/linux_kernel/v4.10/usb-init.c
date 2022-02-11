static void F_1 ( int V_1 , int V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
V_4 = F_2 ( V_1 , V_2 ) ;
V_3 = F_3 ( V_4 , V_5 ) ;
V_3 = V_6 | V_7 |
V_8 | V_9 ;
F_4 ( V_4 , V_5 , V_3 ) ;
}
static void F_5 ( int V_1 , int V_2 )
{
T_2 V_4 ;
T_1 V_3 ;
V_4 = F_2 ( V_1 , V_2 ) ;
V_3 = F_3 ( V_4 , V_10 ) ;
V_3 &= ~ ( V_11 | V_12 | V_13 ) ;
F_4 ( V_4 , V_10 , V_3 ) ;
F_6 ( 100 ) ;
V_3 = F_3 ( V_4 , V_14 ) ;
V_3 &= ~ ( V_15 ) ;
V_3 |= 0x4 ;
F_4 ( V_4 , V_14 , V_3 ) ;
}
static int T_3 F_7 ( void )
{
if ( F_8 () )
return 0 ;
F_9 ( L_1 ) ;
F_5 ( 0 , 0 ) ;
F_5 ( 0 , 3 ) ;
F_1 ( 0 , 0 ) ;
F_1 ( 0 , 3 ) ;
return 0 ;
}
static void F_10 ( struct V_16 * V_17 )
{
V_17 -> V_17 . V_18 = & V_19 ;
V_17 -> V_17 . V_20 = F_11 ( 32 ) ;
switch ( V_17 -> V_21 ) {
case 0x10 :
V_17 -> V_22 = V_23 ;
break;
case 0x11 :
V_17 -> V_22 = V_24 ;
break;
case 0x12 :
V_17 -> V_22 = V_25 ;
break;
case 0x13 :
V_17 -> V_22 = V_26 ;
break;
case 0x14 :
V_17 -> V_22 = V_27 ;
break;
case 0x15 :
V_17 -> V_22 = V_28 ;
break;
}
}
