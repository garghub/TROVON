static int F_1 ( void * V_1 , unsigned V_2 )
{
if ( V_2 == V_3 )
F_2 ( V_4 , 1 ) ;
return 0 ;
}
static void F_3 ( void * V_1 , unsigned V_2 )
{
if ( V_2 == V_3 )
F_2 ( V_4 , 0 ) ;
}
static int T_1 F_4 ( void )
{
F_5 () ;
return F_6 ( V_5 , F_7 ( V_5 ) ) ;
}
static int T_1 F_8 ( char * V_6 )
{
V_7 = 1 ;
return 1 ;
}
static int T_1 F_9 ( void )
{
int V_8 ;
if ( ! F_10 () )
return - V_9 ;
V_10 = ( V_11 | V_12 |
V_13 | V_14 |
V_15 | V_16 |
V_17 | V_18 |
V_19 | V_20 |
V_21 ) ;
V_22 &= ~ V_23 ;
V_22 |= ( V_11 | V_12 |
V_13 | V_14 |
V_15 | V_16 |
V_17 | V_18 |
V_19 | V_20 |
V_21 ) ;
V_10 = ( V_24 | V_25 ) ;
V_22 |= ( V_24 | V_25 ) ;
V_10 = ( V_26 | V_27 ) ;
V_22 |= ( V_26 | V_27 ) ;
V_10 = V_28 ;
V_22 |= V_28 ;
V_22 &= ~ ( V_29 | V_30 ) ;
V_10 = V_31 ;
V_22 |= V_31 ;
V_10 = V_32 ;
V_22 |= V_32 ;
F_11 (KERN_DEBUG __FILE__ L_1 ,
!!(GPLR & BADGE4_GPIO_SDTYP1),
!!(GPLR & BADGE4_GPIO_SDTYP0)) ;
V_33 = 0 ;
V_34 = 0 ;
V_35 = 0 ;
V_36 = 0 ;
V_34 |= V_37 ;
V_34 |= V_38 ;
V_33 |= V_39 ;
V_33 |= ( V_40 & ( V_41 | V_42 ) ) ;
V_8 = F_4 () ;
if ( V_8 < 0 )
F_11 ( V_43
L_2 ,
V_44 , V_8 ) ;
F_2 ( V_45 , V_7 ) ;
F_12 ( & V_46 , & V_47 , 1 ) ;
return 0 ;
}
void F_2 ( unsigned V_48 , int V_49 )
{
unsigned long V_50 ;
unsigned V_51 ;
F_13 ( V_50 ) ;
V_51 = V_52 ;
if ( V_49 ) {
V_52 |= V_48 ;
} else {
V_52 &= ~ V_48 ;
}
if ( ( ! V_51 ) && ( V_52 ) ) {
F_11 ( V_53 L_3 , V_44 ) ;
V_54 = V_32 ;
} else if ( ( V_51 ) && ( ! V_52 ) ) {
F_11 ( V_53 L_4 , V_44 ) ;
V_10 = V_32 ;
}
F_14 ( V_50 ) ;
}
static void
F_15 ( struct V_55 * V_56 , T_2 V_57 , T_2 V_58 )
{
if ( ! V_57 ) {
V_59 |= V_60 ;
}
}
static void T_1 F_16 ( void )
{
F_17 () ;
F_18 ( V_61 , F_7 ( V_61 ) ) ;
F_19 ( & V_62 ) ;
F_20 ( 0 , 3 ) ;
F_20 ( 1 , 1 ) ;
}
