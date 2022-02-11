static void F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 , V_5 , V_6 ;
T_1 V_7 ;
V_3 = F_2 ( V_8 ) ;
V_4 = F_2 ( V_9 ) ;
V_5 = F_2 ( V_10 ) ;
V_6 = 100 * ( V_3 - V_11 ) /
( V_12 - V_11 ) ;
V_2 -> V_13 = V_6 ;
V_2 -> V_14 = 0 ;
V_2 -> time = ( 2 * V_3 ) ;
V_2 -> V_15 = ( V_3 > V_16 ) ?
V_17 : V_18 ;
V_7 = F_3 ( V_19 ) ;
if ( V_7 & V_20 ) {
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = 0x80 ;
} else if ( V_5 < 8 ) {
V_2 -> V_21 = V_24 ;
V_2 -> V_23 = 0x08 ;
V_2 -> V_15 = 0x01 ;
} else if ( V_6 <= V_25 ) {
V_2 -> V_21 = V_26 ;
V_2 -> V_23 = 0x04 ;
} else if ( V_6 <= V_27 ) {
V_2 -> V_21 = V_28 ;
V_2 -> V_23 = 0x02 ;
} else {
V_2 -> V_21 = V_29 ;
V_2 -> V_23 = 0x01 ;
}
}
static T_2 F_4 ( int V_30 , void * V_31 )
{
if ( ! V_32 )
F_5 ( V_33 ) ;
return V_34 ;
}
static int T_3 F_6 ( void )
{
int V_35 ;
V_35 = F_7 ( V_36 , F_4 ,
V_37 , V_38 , NULL ) ;
if ( F_8 ( V_35 < 0 ) ) {
F_9 (KERN_ERR MODNAME L_1 ,
HP680_BTN_IRQ) ;
return V_35 ;
}
V_39 = F_1 ;
return V_35 ;
}
static void T_4 F_10 ( void )
{
F_11 ( V_36 , 0 ) ;
}
