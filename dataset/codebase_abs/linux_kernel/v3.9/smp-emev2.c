static void F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 ) ;
V_3 = F_3 ( V_5 + 8 ) ;
V_3 &= ~ V_2 ;
V_3 |= V_1 ;
F_4 ( V_3 , V_5 + 8 ) ;
F_5 ( & V_4 ) ;
}
static unsigned int T_1 F_6 ( void )
{
if ( ! V_5 ) {
V_5 = F_7 ( V_6 , V_7 ) ;
F_8 () ;
}
F_9 ( ! V_5 ) ;
return V_5 ? F_10 ( V_5 ) : 1 ;
}
static int F_11 ( unsigned int V_8 )
{
return 0 ;
}
static int T_2 F_12 ( unsigned int V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < 1000 ; V_9 ++ ) {
if ( F_13 ( V_8 ) )
return F_11 ( V_8 ) ;
F_14 ( 1 ) ;
}
return 0 ;
}
static void T_3 F_15 ( unsigned int V_8 )
{
F_16 ( 0 ) ;
}
static int T_3 F_17 ( unsigned int V_8 , struct V_10 * V_11 )
{
V_8 = F_18 ( V_8 ) ;
F_1 ( 0 , 3 << ( V_8 * 8 ) ) ;
F_19 ( F_20 ( V_12 ) ) ;
F_21 ( F_22 ( V_8 ) ) ;
return 0 ;
}
static void T_1 F_23 ( unsigned int V_13 )
{
int V_8 = F_18 ( 0 ) ;
F_24 ( V_5 ) ;
F_1 ( 0 , 3 << ( V_8 * 8 ) ) ;
}
static void T_1 F_25 ( void )
{
unsigned int V_14 = F_6 () ;
F_26 ( V_14 ) ;
}
