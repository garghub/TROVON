static T_1 F_1 ( int V_1 , void * V_2 )
{
char V_3 ;
unsigned int V_4 = V_5 -> V_6 . error ;
unsigned int V_7 = V_5 -> V_6 . V_8 ;
if ( V_4 & V_9 )
V_3 = 'M' ;
else if ( V_4 & V_10 )
V_3 = 'C' ;
else
V_3 = 'X' ;
if ( V_4 & V_11 ) {
F_2 ( L_1 , V_7 , V_3 ) ;
V_4 &= ~ V_11 ;
}
if ( V_4 & V_12 ) {
F_2 ( L_2 , V_7 , V_3 ) ;
V_4 &= ~ V_12 ;
}
if ( V_4 & V_13 ) {
F_2 ( L_3 , V_7 , V_3 ) ;
V_4 &= ~ V_13 ;
}
if ( V_4 & V_14 ) {
F_2 ( L_4 , V_7 , V_3 ) ;
V_4 &= ~ V_14 ;
}
if ( V_4 & V_15 ) {
F_2 ( L_5 , V_7 , V_3 ) ;
V_4 &= ~ V_15 ;
}
if ( V_4 & V_16 ) {
F_2 ( L_6 , V_7 , V_3 ) ;
V_4 &= ~ V_16 ;
}
if ( V_4 & V_17 ) {
F_2 ( L_7 , V_7 , V_3 ) ;
V_4 &= ~ V_17 ;
}
if ( V_4 & V_18 ) {
F_2 ( L_8 , V_7 , V_3 ) ;
V_4 &= ~ V_18 ;
}
if ( V_4 & V_19 ) {
F_2 ( L_9 ) ;
V_4 &= ~ V_19 ;
}
if ( V_4 & V_20 ) {
F_2 ( L_10 ) ;
V_4 &= ~ V_20 ;
}
V_5 -> V_6 . error = V_4 ;
return V_21 ;
}
static int T_2 F_3 ( void )
{
V_22 = 0x1000 ;
V_5 -> V_6 . V_8 = 0 ;
V_5 -> V_6 . error = 0 ;
V_5 -> V_6 . V_23 = 0xff008500 ;
F_2 ( L_11 , V_5 -> V_6 . V_24 ) ;
F_4 ( F_5 ( V_25 , F_1 , 0 ,
L_12 , NULL ) ) ;
V_26 . V_27 = V_28 . V_27 ;
V_29 = V_30 ;
F_6 ( & V_31 ) ;
return 0 ;
}
