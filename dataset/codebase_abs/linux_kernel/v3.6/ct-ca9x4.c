static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static void T_1 F_4 ( void )
{
int V_2 = F_5 ( & V_3 ) ;
if ( V_2 )
F_6 ( L_1 , V_2 ) ;
}
static void T_1 F_7 ( void )
{
F_8 ( 0 , 29 , F_9 ( V_4 , V_5 ) ,
F_9 ( V_6 , V_7 ) ) ;
F_4 () ;
}
static void F_10 ( struct V_8 * V_9 )
{
T_2 V_10 = F_11 () ;
F_12 ( V_11 | F_13 ( V_10 ) , V_10 ) ;
F_12 ( V_12 | F_13 ( V_13 ) , 2 ) ;
}
static int F_14 ( struct V_8 * V_9 )
{
unsigned long V_14 = 1024 * 768 * 2 ;
V_9 -> V_15 = F_15 ( L_2 ) ;
if ( ! V_9 -> V_15 )
return - V_16 ;
return F_16 ( V_9 , V_14 ) ;
}
static void T_1 F_17 ( void )
{
int V_17 ;
struct V_18 * V_18 ;
#ifdef F_18
void T_3 * V_19 = F_9 ( V_20 , V_5 ) ;
F_19 ( 0 , V_19 + V_21 ) ;
F_19 ( 0 , V_19 + V_22 ) ;
F_20 ( V_19 , 0x00400000 , 0xfe0fffff ) ;
#endif
V_23 . V_10 = F_11 () ;
V_18 = F_21 ( L_3 , & V_23 ) ;
F_22 ( V_18 , NULL , L_4 ) ;
for ( V_17 = 0 ; V_17 < F_3 ( V_24 ) ; V_17 ++ )
F_23 ( V_24 [ V_17 ] , & V_25 ) ;
F_24 ( & V_26 ) ;
}
static void T_1 F_25 ( void )
{
int V_17 , V_27 ;
V_28 = F_9 ( V_29 , V_30 ) ;
if ( F_26 ( ! V_28 ) )
return;
V_27 = F_27 ( V_28 ) ;
if ( V_27 > V_31 ) {
F_28 ( L_5 ,
V_27 , V_31 ) ;
V_27 = V_31 ;
}
for ( V_17 = 0 ; V_17 < V_27 ; ++ V_17 )
F_29 ( V_17 , true ) ;
F_30 ( V_32 ) ;
}
static void T_1 F_31 ( unsigned int V_33 )
{
F_32 ( V_28 ) ;
}
