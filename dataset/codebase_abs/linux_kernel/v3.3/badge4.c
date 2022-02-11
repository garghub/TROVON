static int T_1 F_1 ( void )
{
F_2 () ;
return F_3 ( V_1 , F_4 ( V_1 ) ) ;
}
static int T_1 F_5 ( char * V_2 )
{
V_3 = 1 ;
return 1 ;
}
static int T_1 F_6 ( void )
{
int V_4 ;
if ( ! F_7 () )
return - V_5 ;
V_6 = ( V_7 | V_8 |
V_9 | V_10 |
V_11 | V_12 |
V_13 | V_14 |
V_15 | V_16 |
V_17 ) ;
V_18 &= ~ V_19 ;
V_18 |= ( V_7 | V_8 |
V_9 | V_10 |
V_11 | V_12 |
V_13 | V_14 |
V_15 | V_16 |
V_17 ) ;
V_6 = ( V_20 | V_21 ) ;
V_18 |= ( V_20 | V_21 ) ;
V_6 = ( V_22 | V_23 ) ;
V_18 |= ( V_22 | V_23 ) ;
V_6 = V_24 ;
V_18 |= V_24 ;
V_18 &= ~ ( V_25 | V_26 ) ;
V_6 = V_27 ;
V_18 |= V_27 ;
V_6 = V_28 ;
V_18 |= V_28 ;
F_8 (KERN_DEBUG __FILE__ L_1 ,
!!(GPLR & BADGE4_GPIO_SDTYP1),
!!(GPLR & BADGE4_GPIO_SDTYP0)) ;
V_29 = 0 ;
V_30 = 0 ;
V_31 = 0 ;
V_32 = 0 ;
V_30 |= V_33 ;
V_30 |= V_34 ;
V_29 |= V_35 ;
V_29 |= ( V_36 & ( V_37 | V_38 ) ) ;
V_4 = F_1 () ;
if ( V_4 < 0 )
F_8 ( V_39
L_2 ,
V_40 , V_4 ) ;
F_9 ( V_41 , V_3 ) ;
F_10 ( & V_42 , & V_43 , 1 ) ;
return 0 ;
}
void F_9 ( unsigned V_44 , int V_45 )
{
unsigned long V_46 ;
unsigned V_47 ;
F_11 ( V_46 ) ;
V_47 = V_48 ;
if ( V_45 ) {
V_48 |= V_44 ;
} else {
V_48 &= ~ V_44 ;
}
if ( ( ! V_47 ) && ( V_48 ) ) {
F_8 ( V_49 L_3 , V_40 ) ;
V_50 = V_28 ;
} else if ( ( V_47 ) && ( ! V_48 ) ) {
F_8 ( V_49 L_4 , V_40 ) ;
V_6 = V_28 ;
}
F_12 ( V_46 ) ;
}
static void
F_13 ( struct V_51 * V_52 , T_2 V_53 , T_2 V_54 )
{
if ( ! V_53 ) {
V_55 |= V_56 ;
}
}
static void T_1 F_14 ( void )
{
F_15 () ;
F_16 ( V_57 , F_4 ( V_57 ) ) ;
F_17 ( & V_58 ) ;
F_18 ( 0 , 3 ) ;
F_18 ( 1 , 1 ) ;
}
