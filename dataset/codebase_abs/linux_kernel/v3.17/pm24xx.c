static int F_1 ( void )
{
T_1 V_1 ;
F_2 ( V_2 ) ;
F_3 ( V_3 , V_4 , ~ 0 ) ;
F_3 ( V_3 , V_5 , ~ 0 ) ;
F_3 ( V_6 , V_7 , ~ 0 ) ;
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
F_3 ( V_3 , V_4 , ~ 0 ) ;
F_3 ( V_3 , V_5 , ~ 0 ) ;
F_3 ( V_6 , V_7 , 0x4 | 0x1 ) ;
F_3 ( V_16 , V_17 ,
0x1 ) ;
F_3 ( V_16 , V_17 ,
0x20 ) ;
F_4 ( V_10 , V_18 ) ;
F_4 ( V_8 , V_18 ) ;
return 0 ;
}
static int F_14 ( void )
{
if ( ! F_15 () )
return 0 ;
if ( V_19 )
return 0 ;
return 1 ;
}
static void F_16 ( void )
{
const int V_20 = 0 ;
if ( F_14 () ) {
F_3 ( V_3 , V_4 , ~ 0 ) ;
F_3 ( V_3 , V_5 , ~ 0 ) ;
F_3 ( V_6 , V_7 , ~ 0 ) ;
F_4 ( V_10 , V_9 ) ;
} else {
F_4 ( V_10 , V_18 ) ;
}
asm("mcr p15, 0, %0, c7, c0, 4" : : "r" (zero) : "memory", "cc");
F_4 ( V_10 , V_18 ) ;
}
static int F_17 ( void )
{
if ( F_18 () )
return 0 ;
if ( F_19 ( V_2 ) )
return 0 ;
if ( F_20 () )
return 0 ;
return 1 ;
}
static void F_21 ( void )
{
if ( ! F_17 () ) {
if ( F_8 () )
return;
F_16 () ;
return;
}
if ( F_8 () )
return;
F_1 () ;
}
static void T_2 F_22 ( void )
{
int V_21 , V_22 ;
struct V_23 * V_24 ;
F_23 ( V_25 , V_16 ,
V_26 ) ;
V_22 = F_24 ( V_8 ) ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ )
F_25 ( V_8 , V_21 , V_9 ) ;
F_26 ( V_8 , V_9 ) ;
F_26 ( V_10 , V_9 ) ;
V_24 = F_27 ( V_27 ) ;
F_4 ( V_24 , V_28 ) ;
V_24 = F_27 ( V_29 ) ;
F_4 ( V_24 , V_28 ) ;
F_28 ( V_30 , NULL ) ;
F_29 ( V_31 , V_32 ) ;
F_30 ( F_1 ) ;
F_23 ( 15 << V_33 , V_34 ,
V_35 ) ;
F_23 ( 2 << V_33 , V_34 ,
V_36 ) ;
F_23 ( V_37 |
( 0x1 << V_38 ) |
V_39 |
( 0x1 << V_40 ) |
( 0x0 << V_41 ) ,
V_34 , V_42 ) ;
F_23 ( V_43 | V_44 ,
V_6 , V_45 ) ;
F_31 ( V_46 , V_34 ,
V_47 ) ;
}
int T_2 F_32 ( void )
{
T_1 V_1 ;
F_33 ( V_48 L_1 ) ;
V_1 = F_34 ( V_16 , V_49 ) ;
F_33 ( V_48 L_2 , ( V_1 >> 4 ) & 0x0f , V_1 & 0x0f ) ;
V_10 = F_35 ( L_3 ) ;
if ( ! V_10 )
F_36 ( L_4 ) ;
V_8 = F_35 ( L_5 ) ;
if ( ! V_8 )
F_36 ( L_6 ) ;
V_31 = F_37 ( L_7 ) ;
if ( ! V_31 )
F_36 ( L_8 ) ;
V_32 = F_37 ( L_9 ) ;
if ( ! V_32 )
F_36 ( L_10 ) ;
V_27 = F_37 ( L_11 ) ;
if ( ! V_27 )
F_36 ( L_12 ) ;
V_29 = F_37 ( L_13 ) ;
if ( ! V_29 )
F_36 ( L_14 ) ;
V_2 = F_38 ( NULL , L_15 ) ;
if ( F_39 ( V_2 ) ) {
F_33 ( V_50 L_16 ) ;
return - V_51 ;
}
if ( F_40 () ) {
V_52 = F_38 ( NULL , L_17 ) ;
if ( F_39 ( V_52 ) ) {
F_33 ( V_50 L_18 ) ;
F_41 ( V_2 ) ;
return - V_51 ;
}
}
F_22 () ;
F_9 = F_42 ( V_53 ,
V_54 ) ;
V_55 = F_21 ;
return 0 ;
}
