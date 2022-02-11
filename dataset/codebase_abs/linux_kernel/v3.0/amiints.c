void T_1 F_1 ( void )
{
if ( F_2 ( V_1 , V_2 , 0 , L_1 , NULL ) )
F_3 ( L_2 , 1 ) ;
if ( F_2 ( V_3 , V_4 , 0 , L_3 , NULL ) )
F_3 ( L_2 , 3 ) ;
if ( F_2 ( V_5 , V_6 , 0 , L_4 , NULL ) )
F_3 ( L_2 , 4 ) ;
if ( F_2 ( V_7 , V_8 , 0 , L_5 , NULL ) )
F_3 ( L_2 , 5 ) ;
F_4 ( & V_9 , V_10 , V_11 ) ;
if ( F_5 ( V_12 ) )
V_13 . V_14 = V_15 ;
V_16 . V_17 = 0x7fff ;
V_16 . V_18 = 0x7fff ;
V_16 . V_17 = V_19 | V_20 ;
F_6 ( & V_21 ) ;
F_6 ( & V_22 ) ;
}
static void F_7 ( unsigned int V_23 )
{
V_16 . V_17 = V_19 | ( 1 << ( V_23 - V_10 ) ) ;
}
static void F_8 ( unsigned int V_23 )
{
V_16 . V_17 = 1 << ( V_23 - V_10 ) ;
}
static T_2 V_2 ( int V_23 , void * V_24 )
{
unsigned short V_25 = V_16 . V_26 & V_16 . V_27 ;
if ( V_25 & V_28 ) {
V_16 . V_18 = V_28 ;
F_9 ( V_29 ) ;
}
if ( V_25 & V_30 ) {
V_16 . V_18 = V_30 ;
F_9 ( V_31 ) ;
}
if ( V_25 & V_32 ) {
V_16 . V_18 = V_32 ;
F_9 ( V_33 ) ;
}
return V_34 ;
}
static T_2 V_4 ( int V_23 , void * V_24 )
{
unsigned short V_25 = V_16 . V_26 & V_16 . V_27 ;
if ( V_25 & V_35 ) {
V_16 . V_18 = V_35 ;
F_9 ( V_36 ) ;
}
if ( V_25 & V_37 ) {
V_16 . V_18 = V_37 ;
F_9 ( V_38 ) ;
}
if ( V_25 & V_39 ) {
V_16 . V_18 = V_39 ;
F_9 ( V_40 ) ;
}
return V_34 ;
}
static T_2 V_6 ( int V_23 , void * V_24 )
{
unsigned short V_25 = V_16 . V_26 & V_16 . V_27 ;
if ( V_25 & V_41 ) {
V_16 . V_18 = V_41 ;
F_9 ( V_42 ) ;
}
if ( V_25 & V_43 ) {
V_16 . V_18 = V_43 ;
F_9 ( V_44 ) ;
}
if ( V_25 & V_45 ) {
V_16 . V_18 = V_45 ;
F_9 ( V_46 ) ;
}
if ( V_25 & V_47 ) {
V_16 . V_18 = V_47 ;
F_9 ( V_48 ) ;
}
return V_34 ;
}
static T_2 V_8 ( int V_23 , void * V_24 )
{
unsigned short V_25 = V_16 . V_26 & V_16 . V_27 ;
if ( V_25 & V_49 ) {
F_9 ( V_50 ) ;
}
if ( V_25 & V_51 ) {
V_16 . V_18 = V_51 ;
F_9 ( V_52 ) ;
}
return V_34 ;
}
