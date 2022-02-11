static int F_1 ( struct V_1 * V_2 ) { return 0 ; }
static void F_2 ( struct V_1 * V_2 ) { }
static int T_1 F_3 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
int V_5 , V_6 = V_2 -> V_6 -> V_7 ;
V_4 -- ;
if ( V_6 == V_8 && V_3 == 4 && V_4 == 0 )
return - 1 ;
if ( V_6 == V_8 && V_3 == 4 && V_4 == 3 ) {
V_5 = F_4 ( V_9 ) ;
goto V_10;
}
if ( V_4 == 0 ) {
V_5 = F_4 ( ( V_6 == V_8 ? V_11 :
V_12 ) + V_3 ) ;
goto V_10;
}
if ( V_6 == V_13 ) {
V_5 = F_4 ( V_14 + ( ( V_3 + ( V_4 - 1 ) ) % 2 ) ) ;
} else {
if ( V_3 == 0 )
V_3 = 3 ;
V_5 = F_4 ( V_14 + ( ( 3 - V_3 ) + ( V_4 - 1 ) % 3 ) ) ;
}
V_10:
F_5 ( V_15 L_1 , V_6 , V_3 , V_4 , V_5 ) ;
return V_5 ;
}
void T_1 F_6 ( struct V_1 * V_2 , int V_5 )
{
F_7 ( V_2 , V_16 , V_5 ) ;
}
int T_1 F_8 ( void )
{
V_17 = & F_1 ;
V_18 = & F_2 ;
V_19 = ( V_19 | V_20 ) &
~ ( V_21 | V_22 ) ;
V_8 = F_9 ( V_23 ) & 0xff ;
V_13 = F_10 ( V_23 ) & 0xff ;
F_5 ( V_24 L_2
L_3 , V_13 , V_8 ) ;
V_25 = & V_26 ;
F_11 ( V_8 ) ;
F_11 ( V_13 ) ;
F_12 ( V_27 , F_3 ) ;
F_13 () ;
return 1 ;
}
