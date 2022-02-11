static int F_1 ( void )
{
T_1 V_1 , V_2 ;
V_1 = F_2 ( V_3 , V_4 ) ;
V_2 = F_2 ( V_3 , V_5 ) ;
return ( V_1 | V_2 ) ? 1 : 0 ;
}
static int F_3 ( void )
{
T_1 V_6 ;
F_4 ( V_7 ) ;
F_5 ( 0xffffffff , V_3 , V_8 ) ;
F_5 ( 0xffffffff , V_3 , V_9 ) ;
F_5 ( 0xffffffff , V_10 , V_11 ) ;
F_6 ( V_12 , V_13 ) ;
F_6 ( V_14 , V_13 ) ;
V_6 = F_7 ( V_15 ) | V_16 ;
F_8 ( V_6 , V_15 ) ;
F_9 ( 0 ) ;
if ( F_10 () )
goto V_17;
F_11 ( F_12 ( V_18 ) ,
F_13 ( V_18 ) ,
F_13 ( V_19 ) ) ;
V_17:
F_14 () ;
F_15 ( V_7 ) ;
F_5 ( 0xffffffff , V_3 , V_8 ) ;
F_5 ( 0xffffffff , V_3 , V_9 ) ;
F_16 ( 0x4 | 0x1 , V_10 , V_11 ) ;
V_6 = F_17 ( V_20 , V_21 ) ;
if ( V_6 & 0x01 )
F_5 ( 0x01 , V_20 ,
V_21 ) ;
if ( V_6 & 0x20 )
F_5 ( 0x20 , V_20 ,
V_21 ) ;
F_5 ( 0x0 , V_20 , V_21 ) ;
F_6 ( V_14 , V_22 ) ;
F_6 ( V_12 , V_22 ) ;
return 0 ;
}
static int F_18 ( void )
{
T_1 V_6 ;
V_6 = F_2 ( V_3 , V_4 ) ;
if ( V_6 & ( V_23 | V_24 |
V_25 | V_26 |
V_27 | V_28 ) )
return 0 ;
V_6 = F_2 ( V_3 , V_5 ) ;
if ( V_6 & V_29 )
return 0 ;
if ( V_30 )
return 0 ;
return 1 ;
}
static void F_19 ( void )
{
const int V_31 = 0 ;
if ( F_18 () ) {
F_5 ( 0xffffffff , V_3 , V_8 ) ;
F_5 ( 0xffffffff , V_3 , V_9 ) ;
F_5 ( 0xffffffff , V_10 , V_11 ) ;
F_6 ( V_14 , V_13 ) ;
} else {
F_6 ( V_14 , V_22 ) ;
}
asm("mcr p15, 0, %0, c7, c0, 4" : : "r" (zero) : "memory", "cc");
F_6 ( V_14 , V_22 ) ;
}
static int F_20 ( void )
{
if ( F_1 () )
return 0 ;
if ( F_21 ( V_7 ) )
return 0 ;
if ( F_22 () )
return 0 ;
return 1 ;
}
static void F_23 ( void )
{
if ( ! F_20 () ) {
if ( F_10 () )
return;
F_19 () ;
return;
}
if ( F_10 () )
return;
F_3 () ;
}
static void T_2 F_24 ( void )
{
int V_32 , V_33 ;
struct V_34 * V_35 ;
F_5 ( V_36 , V_20 ,
V_37 ) ;
V_33 = F_25 ( V_12 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
F_26 ( V_12 , V_32 , V_13 ) ;
F_27 ( V_12 , V_13 ) ;
F_27 ( V_14 , V_13 ) ;
V_35 = F_28 ( V_38 ) ;
F_6 ( V_35 , V_39 ) ;
V_35 = F_28 ( V_40 ) ;
F_6 ( V_35 , V_39 ) ;
F_29 ( V_41 , NULL ) ;
F_30 ( V_42 , V_43 ) ;
#ifdef F_31
V_44 = F_3 ;
#endif
F_5 ( 15 << V_45 , V_46 ,
V_47 ) ;
F_5 ( 2 << V_45 , V_46 ,
V_48 ) ;
F_5 ( V_49 |
( 0x1 << V_50 ) |
V_51 |
( 0x1 << V_52 ) |
( 0x0 << V_53 ) ,
V_46 , V_54 ) ;
F_5 ( V_55 | V_56 ,
V_10 , V_57 ) ;
}
int T_2 F_32 ( void )
{
T_1 V_6 ;
F_33 ( V_58 L_1 ) ;
V_6 = F_17 ( V_20 , V_59 ) ;
F_33 ( V_58 L_2 , ( V_6 >> 4 ) & 0x0f , V_6 & 0x0f ) ;
V_14 = F_34 ( L_3 ) ;
if ( ! V_14 )
F_35 ( L_4 ) ;
V_12 = F_34 ( L_5 ) ;
if ( ! V_12 )
F_35 ( L_6 ) ;
V_42 = F_36 ( L_7 ) ;
if ( ! V_42 )
F_35 ( L_8 ) ;
V_43 = F_36 ( L_9 ) ;
if ( ! V_43 )
F_35 ( L_10 ) ;
V_38 = F_36 ( L_11 ) ;
if ( ! V_38 )
F_35 ( L_12 ) ;
V_40 = F_36 ( L_13 ) ;
if ( ! V_40 )
F_35 ( L_14 ) ;
V_7 = F_37 ( NULL , L_15 ) ;
if ( F_38 ( V_7 ) ) {
F_33 ( V_60 L_16 ) ;
return - V_61 ;
}
if ( F_39 () ) {
V_62 = F_37 ( NULL , L_17 ) ;
if ( F_38 ( V_62 ) ) {
F_33 ( V_60 L_18 ) ;
F_40 ( V_7 ) ;
return - V_61 ;
}
}
F_24 () ;
F_11 = F_41 ( V_63 ,
V_64 ) ;
V_65 = F_23 ;
return 0 ;
}
