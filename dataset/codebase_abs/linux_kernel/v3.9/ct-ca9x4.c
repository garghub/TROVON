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
static int F_10 ( struct V_8 * V_9 )
{
unsigned long V_10 = 1024 * 768 * 2 ;
V_9 -> V_11 = F_11 ( L_2 ) ;
if ( ! V_9 -> V_11 )
return - V_12 ;
return F_12 ( V_9 , V_10 ) ;
}
static void T_1 F_13 ( void )
{
int V_13 ;
#ifdef F_14
void T_2 * V_14 = F_9 ( V_15 , V_5 ) ;
F_15 ( 0 , V_14 + V_16 ) ;
F_15 ( 0 , V_14 + V_17 ) ;
F_16 ( V_14 , 0x00400000 , 0xfe0fffff ) ;
#endif
for ( V_13 = 0 ; V_13 < F_3 ( V_18 ) ; V_13 ++ )
F_17 ( V_18 [ V_13 ] , & V_19 ) ;
F_18 ( & V_20 ) ;
F_18 ( & V_21 ) ;
F_19 ( F_20 ( F_21 ( & V_21 . V_22 ) ,
NULL , L_3 ) ) ;
}
static void T_1 F_22 ( void )
{
int V_13 , V_23 ;
V_24 = F_9 ( V_25 , V_26 ) ;
if ( F_19 ( ! V_24 ) )
return;
V_23 = F_23 ( V_24 ) ;
if ( V_23 > V_27 ) {
F_24 ( L_4 ,
V_23 , V_27 ) ;
V_23 = V_27 ;
}
for ( V_13 = 0 ; V_13 < V_23 ; ++ V_13 )
F_25 ( V_13 , true ) ;
}
static void T_1 F_26 ( unsigned int V_28 )
{
F_27 ( V_24 ) ;
}
