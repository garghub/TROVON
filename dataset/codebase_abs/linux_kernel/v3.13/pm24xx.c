static int F_1 ( void )
{
T_1 V_1 ;
F_2 ( V_2 ) ;
F_3 ( 0xffffffff , V_3 , V_4 ) ;
F_3 ( 0xffffffff , V_3 , V_5 ) ;
F_3 ( 0xffffffff , V_6 , V_7 ) ;
F_4 ( V_8 , V_9 ) ;
F_4 ( V_10 , V_9 ) ;
V_1 = F_5 ( V_11 ) | V_12 ;
F_6 ( V_1 , V_11 ) ;
F_7 ( 0 ) ;
if ( F_8 () )
goto V_13;
F_9 ( F_10 ( V_14 ) ,
F_11 ( V_14 ) ,
F_11 ( V_15 ) ) ;
V_13:
F_12 () ;
F_13 ( V_2 ) ;
F_3 ( 0xffffffff , V_3 , V_4 ) ;
F_3 ( 0xffffffff , V_3 , V_5 ) ;
F_14 ( 0x4 | 0x1 , V_6 , V_7 ) ;
V_1 = F_15 ( V_16 , V_17 ) ;
if ( V_1 & 0x01 )
F_3 ( 0x01 , V_16 ,
V_17 ) ;
if ( V_1 & 0x20 )
F_3 ( 0x20 , V_16 ,
V_17 ) ;
F_3 ( 0x0 , V_16 , V_17 ) ;
F_4 ( V_10 , V_18 ) ;
F_4 ( V_8 , V_18 ) ;
return 0 ;
}
static int F_16 ( void )
{
if ( ! F_17 () )
return 0 ;
if ( V_19 )
return 0 ;
return 1 ;
}
static void F_18 ( void )
{
const int V_20 = 0 ;
if ( F_16 () ) {
F_3 ( 0xffffffff , V_3 , V_4 ) ;
F_3 ( 0xffffffff , V_3 , V_5 ) ;
F_3 ( 0xffffffff , V_6 , V_7 ) ;
F_4 ( V_10 , V_9 ) ;
} else {
F_4 ( V_10 , V_18 ) ;
}
asm("mcr p15, 0, %0, c7, c0, 4" : : "r" (zero) : "memory", "cc");
F_4 ( V_10 , V_18 ) ;
}
static int F_19 ( void )
{
if ( F_20 () )
return 0 ;
if ( F_21 ( V_2 ) )
return 0 ;
if ( F_22 () )
return 0 ;
return 1 ;
}
static void F_23 ( void )
{
if ( ! F_19 () ) {
if ( F_8 () )
return;
F_18 () ;
return;
}
if ( F_8 () )
return;
F_1 () ;
}
static void T_2 F_24 ( void )
{
int V_21 , V_22 ;
struct V_23 * V_24 ;
F_3 ( V_25 , V_16 ,
V_26 ) ;
V_22 = F_25 ( V_8 ) ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ )
F_26 ( V_8 , V_21 , V_9 ) ;
F_27 ( V_8 , V_9 ) ;
F_27 ( V_10 , V_9 ) ;
V_24 = F_28 ( V_27 ) ;
F_4 ( V_24 , V_28 ) ;
V_24 = F_28 ( V_29 ) ;
F_4 ( V_24 , V_28 ) ;
F_29 ( V_30 , NULL ) ;
F_30 ( V_31 , V_32 ) ;
#ifdef F_31
V_33 = F_1 ;
#endif
F_3 ( 15 << V_34 , V_35 ,
V_36 ) ;
F_3 ( 2 << V_34 , V_35 ,
V_37 ) ;
F_3 ( V_38 |
( 0x1 << V_39 ) |
V_40 |
( 0x1 << V_41 ) |
( 0x0 << V_42 ) ,
V_35 , V_43 ) ;
F_3 ( V_44 | V_45 ,
V_6 , V_46 ) ;
}
int T_2 F_32 ( void )
{
T_1 V_1 ;
F_33 ( V_47 L_1 ) ;
V_1 = F_15 ( V_16 , V_48 ) ;
F_33 ( V_47 L_2 , ( V_1 >> 4 ) & 0x0f , V_1 & 0x0f ) ;
V_10 = F_34 ( L_3 ) ;
if ( ! V_10 )
F_35 ( L_4 ) ;
V_8 = F_34 ( L_5 ) ;
if ( ! V_8 )
F_35 ( L_6 ) ;
V_31 = F_36 ( L_7 ) ;
if ( ! V_31 )
F_35 ( L_8 ) ;
V_32 = F_36 ( L_9 ) ;
if ( ! V_32 )
F_35 ( L_10 ) ;
V_27 = F_36 ( L_11 ) ;
if ( ! V_27 )
F_35 ( L_12 ) ;
V_29 = F_36 ( L_13 ) ;
if ( ! V_29 )
F_35 ( L_14 ) ;
V_2 = F_37 ( NULL , L_15 ) ;
if ( F_38 ( V_2 ) ) {
F_33 ( V_49 L_16 ) ;
return - V_50 ;
}
if ( F_39 () ) {
V_51 = F_37 ( NULL , L_17 ) ;
if ( F_38 ( V_51 ) ) {
F_33 ( V_49 L_18 ) ;
F_40 ( V_2 ) ;
return - V_50 ;
}
}
F_24 () ;
F_9 = F_41 ( V_52 ,
V_53 ) ;
V_54 = F_23 ;
return 0 ;
}
