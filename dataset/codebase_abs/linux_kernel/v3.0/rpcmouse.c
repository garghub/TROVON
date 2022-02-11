static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
short V_5 , V_6 , V_7 , V_8 , V_9 ;
V_5 = ( short ) F_2 ( V_10 ) ;
V_6 = ( short ) F_2 ( V_11 ) ;
V_9 = ( short ) ( F_3 ( 0xe0310000 ) ^ 0x70 ) ;
V_7 = V_5 - V_12 ;
V_8 = V_6 - V_13 ;
V_12 = V_5 ;
V_13 = V_6 ;
F_4 ( V_4 , V_14 , V_7 ) ;
F_4 ( V_4 , V_15 , - V_8 ) ;
F_5 ( V_4 , V_16 , V_9 & 0x40 ) ;
F_5 ( V_4 , V_17 , V_9 & 0x20 ) ;
F_5 ( V_4 , V_18 , V_9 & 0x10 ) ;
F_6 ( V_4 ) ;
return V_19 ;
}
static int T_2 F_7 ( void )
{
int V_20 ;
V_21 = F_8 () ;
if ( ! V_21 )
return - V_22 ;
V_21 -> V_23 = L_1 ;
V_21 -> V_24 = L_2 ;
V_21 -> V_25 . V_26 = V_27 ;
V_21 -> V_25 . V_28 = 0x0005 ;
V_21 -> V_25 . V_29 = 0x0001 ;
V_21 -> V_25 . V_30 = 0x0100 ;
V_21 -> V_31 [ 0 ] = F_9 ( V_32 ) | F_9 ( V_33 ) ;
V_21 -> V_34 [ F_10 ( V_16 ) ] = F_9 ( V_16 ) |
F_9 ( V_17 ) | F_9 ( V_18 ) ;
V_21 -> V_35 [ 0 ] = F_9 ( V_14 ) | F_9 ( V_15 ) ;
V_12 = ( short ) F_2 ( V_10 ) ;
V_13 = ( short ) F_2 ( V_11 ) ;
if ( F_11 ( V_36 , F_1 , V_37 , L_3 , V_21 ) ) {
F_12 ( V_38 L_4 ) ;
V_20 = - V_39 ;
goto V_40;
}
V_20 = F_13 ( V_21 ) ;
if ( V_20 )
goto V_41;
return 0 ;
V_41:
F_14 ( V_36 , V_21 ) ;
V_40:
F_15 ( V_21 ) ;
return V_20 ;
}
static void T_3 F_16 ( void )
{
F_14 ( V_36 , V_21 ) ;
F_17 ( V_21 ) ;
}
