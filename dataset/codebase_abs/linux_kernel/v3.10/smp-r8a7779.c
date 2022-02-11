void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static int F_3 ( unsigned int V_2 )
{
struct V_3 * V_4 = NULL ;
int V_5 = - V_6 ;
V_2 = F_4 ( V_2 ) ;
if ( V_2 < F_5 ( V_7 ) )
V_4 = V_7 [ V_2 ] ;
if ( V_4 )
V_5 = F_6 ( V_4 ) ;
return V_5 ? V_5 : 1 ;
}
static int T_2 F_7 ( unsigned int V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = NULL ;
int V_5 = - V_6 ;
V_2 = F_4 ( V_2 ) ;
if ( V_2 < F_5 ( V_7 ) )
V_4 = V_7 [ V_2 ] ;
if ( V_4 )
V_5 = F_8 ( V_4 ) ;
return V_5 ;
}
static void T_1 F_9 ( unsigned int V_10 )
{
F_10 ( V_11 ) ;
F_11 ( F_12 ( V_12 ) , V_13 ) ;
F_13 ( V_11 , V_14 ) ;
F_14 () ;
F_3 ( 1 ) ;
F_3 ( 2 ) ;
F_3 ( 3 ) ;
}
static void T_1 F_15 ( void )
{
V_11 = F_16 ( V_15 ) ;
F_17 ( F_18 ( V_11 ) ) ;
}
static int F_19 ( int V_2 )
{
unsigned long V_16 = 3 << ( V_2 * 8 ) ;
if ( ( F_20 ( V_11 + 8 ) & V_16 ) == V_16 )
return 1 ;
return 0 ;
}
static int F_21 ( unsigned int V_2 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < 1000 ; V_17 ++ ) {
if ( F_19 ( V_2 ) )
return F_3 ( V_2 ) ;
F_22 ( 1 ) ;
}
return 0 ;
}
static void F_23 ( unsigned int V_2 )
{
F_24 () ;
F_25 () ;
F_13 ( V_11 , V_18 ) ;
while ( 1 )
F_26 () ;
}
static int F_27 ( unsigned int V_2 )
{
return V_2 == 0 ? - V_19 : 0 ;
}
