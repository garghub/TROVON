static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static void T_1 F_4 ( void )
{
#ifdef F_5
void T_2 * V_2 = F_6 ( V_3 , V_4 ) ;
if ( V_2 ) {
F_7 ( 0 , V_2 + V_5 ) ;
F_7 ( 0 , V_2 + V_6 ) ;
F_8 ( V_2 , 0x00400000 , 0xfe0fffff ) ;
} else {
F_9 ( L_1 ) ;
}
#endif
}
static void T_1 F_10 ( void )
{
int V_7 = F_11 ( & V_8 ) ;
if ( V_7 )
F_9 ( L_2 , V_7 ) ;
}
static void T_1 F_12 ( void )
{
F_13 ( 0 , 29 , F_6 ( V_9 , V_4 ) ,
F_6 ( V_10 , V_11 ) ) ;
F_10 () ;
F_4 () ;
}
static int F_14 ( struct V_12 * V_13 )
{
unsigned long V_14 = 1024 * 768 * 2 ;
V_13 -> V_15 = F_15 ( L_3 ) ;
if ( ! V_13 -> V_15 )
return - V_16 ;
return F_16 ( V_13 , V_14 ) ;
}
static void T_1 F_17 ( void )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < F_3 ( V_18 ) ; V_17 ++ )
F_18 ( V_18 [ V_17 ] , & V_19 ) ;
F_19 ( & V_20 ) ;
F_20 ( & V_21 ) ;
}
static void T_1 F_21 ( void )
{
int V_17 , V_22 ;
V_23 = F_6 ( V_24 , V_25 ) ;
if ( F_22 ( ! V_23 ) )
return;
V_22 = F_23 ( V_23 ) ;
if ( V_22 > V_26 ) {
F_24 ( L_4 ,
V_22 , V_26 ) ;
V_22 = V_26 ;
}
for ( V_17 = 0 ; V_17 < V_22 ; ++ V_17 )
F_25 ( V_17 , true ) ;
}
static void T_1 F_26 ( unsigned int V_27 )
{
F_27 ( V_23 ) ;
}
