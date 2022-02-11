static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
switch ( V_2 -> V_5 . V_6 ) {
case 0x71 : V_4 = 9 ; break;
case 0x72 : V_4 = 8 ; break;
case 0x73 : V_4 = 1 ; break;
case 0x74 : V_4 = 7 ; break;
case 0x75 : V_4 = ( V_2 -> V_7 == 4 ) ? 5 : 6 ; break;
case 0x76 : V_4 = 10 ; break;
case 0x77 : V_4 = 11 ; break;
case 0x7a : V_4 = 13 ; break;
case 0x7b : V_4 = 13 ; break;
case 0x7c : V_4 = 3 ; break;
case 0x7d : V_4 = 4 ; break;
case 0x7f : V_4 = 13 ; break;
default: return;
}
F_2 ( V_3 , V_4 , & V_2 -> V_4 ) ;
switch ( V_2 -> V_5 . V_6 ) {
case 0x73 : V_4 = 2 ; break;
case 0x76 : V_4 = 0 ; break;
default: return;
}
F_2 ( V_3 , V_4 , & V_2 -> V_8 ) ;
}
static int T_1 F_3 ( struct V_1 * V_2 )
{
struct V_9 V_9 ;
int V_10 ;
V_11 . V_12 = F_4 ( V_2 -> V_13 . V_14 + V_15 ) & 0xf ;
V_11 . V_16 = ( V_11 . V_12 == 1 ) ? L_1 : L_2 ;
V_11 . V_13 = V_17 ;
F_5 ( V_18 L_3 ,
V_11 . V_16 , V_11 . V_12 , ( unsigned long ) V_2 -> V_13 . V_14 ) ;
V_10 = - V_19 ;
V_2 -> V_4 = F_6 ( & V_9 , V_20 ) ;
if ( V_2 -> V_4 < 0 ) {
F_5 ( V_21 L_4 , V_22 ) ;
goto V_23;
}
V_11 . V_24 = ( ( V_25 ) V_9 . V_26 ) | V_9 . V_27 ;
V_10 = F_7 ( V_9 . V_4 , V_28 , 0 , L_5 , & V_11 ) ;
if ( V_10 < 0 )
goto V_23;
F_8 ( ( 1 << ( 31 - V_20 ) ) , V_29 ) ;
V_10 = F_9 ( V_2 , & V_11 ) ;
if ( V_10 )
goto V_23;
F_10 ( V_2 , & V_11 , F_1 ) ;
F_10 ( F_11 ( V_2 ) , & V_11 , F_1 ) ;
#ifdef F_12
F_13 ( V_30 , V_31 ,
V_32 ) ;
#endif
V_23:
return V_10 ;
}
