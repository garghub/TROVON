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
F_11 ( V_10 | V_11 , 0 ) ;
F_11 ( V_12 | V_11 , 2 ) ;
}
static int F_12 ( struct V_8 * V_9 )
{
unsigned long V_13 = 1024 * 768 * 2 ;
V_9 -> V_14 = F_13 ( L_2 ) ;
if ( ! V_9 -> V_14 )
return - V_15 ;
return F_14 ( V_9 , V_13 ) ;
}
static long F_15 ( struct V_16 * V_16 , unsigned long V_17 )
{
return V_17 ;
}
static int F_16 ( struct V_16 * V_16 , unsigned long V_17 )
{
return F_11 ( V_18 | V_11 | 1 , V_17 ) ;
}
static void T_1 F_17 ( void )
{
F_18 ( V_19 , F_3 ( V_19 ) ) ;
}
static void T_1 F_19 ( void )
{
int V_20 ;
#ifdef F_20
void T_2 * V_21 = F_9 ( V_22 , V_5 ) ;
F_21 ( 0 , V_21 + V_23 ) ;
F_21 ( 0 , V_21 + V_24 ) ;
F_22 ( V_21 , 0x00400000 , 0xfe0fffff ) ;
#endif
for ( V_20 = 0 ; V_20 < F_3 ( V_25 ) ; V_20 ++ )
F_23 ( V_25 [ V_20 ] , & V_26 ) ;
F_24 ( & V_27 ) ;
}
static void T_1 F_25 ( void )
{
int V_20 , V_28 ;
V_29 = F_9 ( V_30 , V_31 ) ;
if ( F_26 ( ! V_29 ) )
return;
V_28 = F_27 ( V_29 ) ;
if ( V_28 > V_32 ) {
F_28 ( L_3 ,
V_28 , V_32 ) ;
V_28 = V_32 ;
}
for ( V_20 = 0 ; V_20 < V_28 ; ++ V_20 )
F_29 ( V_20 , true ) ;
F_30 ( V_33 ) ;
}
static void T_1 F_31 ( unsigned int V_34 )
{
F_32 ( V_29 ) ;
}
