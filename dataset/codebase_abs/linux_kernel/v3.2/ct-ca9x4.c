static void T_1 F_1 ( void )
{
#ifdef F_2
V_1 = F_3 ( V_2 ) ;
#endif
F_4 ( V_3 , F_5 ( V_3 ) ) ;
}
static void T_1 F_6 ( void )
{
F_7 ( 0 , 29 , F_3 ( V_4 ) ,
F_3 ( V_5 ) ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
F_9 ( V_8 | V_9 , 0 ) ;
F_9 ( V_10 | V_9 , 2 ) ;
}
static int F_10 ( struct V_6 * V_7 )
{
unsigned long V_11 = 1024 * 768 * 2 ;
V_7 -> V_12 = F_11 ( L_1 ) ;
if ( ! V_7 -> V_12 )
return - V_13 ;
return F_12 ( V_7 , V_11 ) ;
}
static long F_13 ( struct V_14 * V_14 , unsigned long V_15 )
{
return V_15 ;
}
static int F_14 ( struct V_14 * V_14 , unsigned long V_15 )
{
return F_9 ( V_16 | V_9 | 1 , V_15 ) ;
}
static void T_1 F_15 ( void )
{
F_16 ( V_17 , F_5 ( V_17 ) ) ;
}
static void T_1 F_17 ( void )
{
int V_18 ;
#ifdef F_18
void T_2 * V_19 = F_3 ( V_20 ) ;
F_19 ( 0 , V_19 + V_21 ) ;
F_19 ( 0 , V_19 + V_22 ) ;
F_20 ( V_19 , 0x00400000 , 0xfe0fffff ) ;
#endif
for ( V_18 = 0 ; V_18 < F_5 ( V_23 ) ; V_18 ++ )
F_21 ( V_23 [ V_18 ] , & V_24 ) ;
F_22 ( & V_25 ) ;
}
static void F_23 ( void )
{
int V_18 , V_26 = F_24 ( F_3 ( V_27 ) ) ;
if ( V_26 > V_28 ) {
F_25 ( L_2 ,
V_26 , V_28 ) ;
V_26 = V_28 ;
}
for ( V_18 = 0 ; V_18 < V_26 ; ++ V_18 )
F_26 ( V_18 , true ) ;
F_27 ( V_29 ) ;
}
static void F_28 ( unsigned int V_30 )
{
F_29 ( F_3 ( V_27 ) ) ;
}
