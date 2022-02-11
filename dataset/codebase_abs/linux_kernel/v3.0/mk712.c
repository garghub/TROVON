static T_1 F_1 ( int V_1 , void * V_2 )
{
unsigned char V_3 ;
static int V_4 = 1 ;
static unsigned short V_5 ;
static unsigned short V_6 ;
F_2 ( & V_7 ) ;
V_3 = F_3 ( V_8 + V_9 ) ;
if ( ~ V_3 & V_10 ) {
V_4 = 1 ;
goto V_11;
}
if ( ~ V_3 & V_12 ) {
V_4 = 1 ;
F_4 ( V_13 , V_14 , 0 ) ;
goto V_11;
}
if ( V_4 ) {
V_4 = 0 ;
goto V_11;
}
F_4 ( V_13 , V_14 , 1 ) ;
F_5 ( V_13 , V_15 , V_5 ) ;
F_5 ( V_13 , V_16 , V_6 ) ;
V_11:
V_5 = F_6 ( V_8 + V_17 ) & 0x0fff ;
V_6 = F_6 ( V_8 + V_18 ) & 0x0fff ;
F_7 ( V_13 ) ;
F_8 ( & V_7 ) ;
return V_19 ;
}
static int F_9 ( struct V_20 * V_21 )
{
unsigned long V_22 ;
F_10 ( & V_7 , V_22 ) ;
F_11 ( 0 , V_8 + V_23 ) ;
F_11 ( V_24 | V_25 |
V_26 |
V_27 |
V_28 , V_8 + V_23 ) ;
F_11 ( 10 , V_8 + V_29 ) ;
F_12 ( & V_7 , V_22 ) ;
return 0 ;
}
static void F_13 ( struct V_20 * V_21 )
{
unsigned long V_22 ;
F_10 ( & V_7 , V_22 ) ;
F_11 ( 0 , V_8 + V_23 ) ;
F_12 ( & V_7 , V_22 ) ;
}
static int T_2 F_14 ( void )
{
int V_30 ;
if ( ! F_15 ( V_8 , 8 , L_1 ) ) {
F_16 ( V_31 L_2 ) ;
return - V_32 ;
}
F_11 ( 0 , V_8 + V_23 ) ;
if ( ( F_6 ( V_8 + V_17 ) & 0xf000 ) ||
( F_6 ( V_8 + V_18 ) & 0xf000 ) ||
( F_6 ( V_8 + V_9 ) & 0xf333 ) ) {
F_16 ( V_31 L_3 ) ;
V_30 = - V_32 ;
goto V_33;
}
V_13 = F_17 () ;
if ( ! V_13 ) {
F_16 ( V_34 L_4 ) ;
V_30 = - V_35 ;
goto V_33;
}
V_13 -> V_36 = L_5 ;
V_13 -> V_37 = L_6 ;
V_13 -> V_38 . V_39 = V_40 ;
V_13 -> V_38 . V_41 = 0x0005 ;
V_13 -> V_38 . V_42 = 0x0001 ;
V_13 -> V_38 . V_43 = 0x0100 ;
V_13 -> V_44 = F_9 ;
V_13 -> V_45 = F_13 ;
V_13 -> V_46 [ 0 ] = F_18 ( V_47 ) | F_18 ( V_48 ) ;
V_13 -> V_49 [ F_19 ( V_14 ) ] = F_18 ( V_14 ) ;
F_20 ( V_13 , V_15 , 0 , 0xfff , 88 , 0 ) ;
F_20 ( V_13 , V_16 , 0 , 0xfff , 88 , 0 ) ;
if ( F_21 ( V_50 , F_1 , 0 , L_1 , V_13 ) ) {
F_16 ( V_31 L_7 ) ;
V_30 = - V_51 ;
goto V_33;
}
V_30 = F_22 ( V_13 ) ;
if ( V_30 )
goto V_52;
return 0 ;
V_52: F_23 ( V_50 , V_13 ) ;
V_33: F_24 ( V_13 ) ;
F_25 ( V_8 , 8 ) ;
return V_30 ;
}
static void T_3 F_26 ( void )
{
F_27 ( V_13 ) ;
F_23 ( V_50 , V_13 ) ;
F_25 ( V_8 , 8 ) ;
}
