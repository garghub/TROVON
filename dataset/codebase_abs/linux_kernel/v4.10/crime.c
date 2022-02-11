void T_1 F_1 ( void )
{
unsigned int V_1 , V_2 ;
const int V_3 = 2 * sizeof( unsigned long ) ;
F_2 ( ( unsigned long ) F_3 ( V_4 , 0x2000000 ) ) ;
V_5 = F_3 ( V_6 , sizeof( struct V_7 ) ) ;
V_8 = F_3 ( V_9 , sizeof( struct V_10 ) ) ;
V_1 = V_5 -> V_1 ;
V_2 = V_1 & V_11 ;
V_1 = ( V_1 & V_12 ) >> 4 ;
F_4 ( V_13 L_1 ,
V_1 , V_2 , V_3 , ( unsigned long ) V_6 ) ;
}
T_2 F_5 ( unsigned int V_14 , void * V_15 )
{
unsigned long V_16 , V_17 ;
int V_18 = 0 ;
V_16 = V_5 -> V_19 & V_20 ;
V_17 = V_5 -> V_21 & V_22 ;
F_4 ( L_2 , V_17 , V_16 ) ;
if ( V_16 & V_23 )
F_4 ( L_3 ) ;
if ( V_16 & V_24 ) {
unsigned long V_25 =
V_5 -> V_26 & V_27 ;
unsigned long V_28 =
V_5 -> V_29 & V_30 ;
F_4 ( L_4 , V_25 , V_28 ) ;
}
if ( V_16 & V_31 ) {
V_18 = 1 ;
F_4 ( L_5 ) ;
}
if ( V_16 & V_32 ) {
V_18 = 1 ;
F_4 ( L_6 ) ;
}
if ( V_16 & V_33 )
F_4 ( L_7 ) ;
if ( V_16 & V_34 )
F_4 ( L_8 ) ;
if ( V_16 & V_35 )
F_4 ( L_9 ) ;
if ( V_16 & V_36 )
F_4 ( L_10 ) ;
if ( V_16 & V_37 )
F_4 ( L_11 , ( V_16 & V_38 ) >> 8 ) ;
if ( V_16 & V_39 )
F_4 ( L_12 , V_16 & V_40 ) ;
V_5 -> V_19 = 0 ;
if ( V_18 ) {
F_4 ( L_13 ) ;
F_6 ( L_14 ) ;
} else
F_4 ( L_15 ) ;
return V_41 ;
}
T_2 F_7 ( unsigned int V_14 , void * V_15 )
{
unsigned long V_16 = V_5 -> V_42 & V_43 ;
unsigned long V_17 = V_5 -> V_44 & V_45 ;
V_17 <<= 2 ;
F_4 ( L_16 , V_17 , V_16 ) ;
V_5 -> V_42 = 0 ;
return V_41 ;
}
