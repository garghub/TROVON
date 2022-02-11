static T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned char V_4 )
{
switch ( V_4 ) {
case V_5 :
case V_6 :
F_2 ( V_7 , 0 ) ;
F_2 ( V_8 , 1 ) ;
break;
case V_9 :
F_2 ( V_7 , 0 ) ;
F_2 ( V_8 , 0 ) ;
break;
}
return V_10 | V_11 | V_12 |
V_13 | V_14 ;
}
static void F_3 ( void )
{
int V_15 ;
V_15 = F_4 ( V_8 , L_1 ) ;
if ( ! V_15 )
V_15 = F_4 ( V_7 ,
L_2 ) ;
if ( V_15 ) {
F_5 ( L_3 ) ;
return;
}
F_2 ( V_7 , 0 ) ;
F_2 ( V_8 , 1 ) ;
if ( F_6 () )
F_7 ( & V_16 , 0x10480180 ) ;
else
F_7 ( & V_16 , 0 ) ;
}
void F_8 ( void )
{
V_16 . V_17 = V_18 ;
V_8 = V_19 ;
V_7 = V_20 ;
F_3 () ;
}
void T_2 F_9 ( void )
{
T_1 V_21 = 0 ;
if ( F_6 () )
V_21 = 0x10480180 ;
if ( ! F_10 () )
V_22 . V_23 |= V_24 ;
if ( ! F_11 () )
F_12 ( & V_22 , V_21 ) ;
F_13 ( & V_25 , V_21 ) ;
if ( F_14 () || F_11 () ) {
if ( F_14 () ) {
V_16 . V_17 = V_26 ;
V_8 = V_27 ;
V_7 = V_28 ;
} else if ( F_11 () ) {
V_16 . V_17 = V_29 ;
V_16 . V_30 = true ;
V_8 = V_31 ;
V_7 = V_32 ;
}
F_3 () ;
}
}
