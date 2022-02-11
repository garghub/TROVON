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
static int F_7 ( unsigned int V_2 , struct V_8 * V_9 )
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
V_14 = F_13 ( V_15 ) ;
V_16 = ( unsigned long ) V_11 ;
F_14 ( V_11 , V_17 ) ;
F_15 () ;
F_3 ( 1 ) ;
F_3 ( 2 ) ;
F_3 ( 3 ) ;
}
static void T_1 F_16 ( void )
{
V_11 = F_17 ( V_18 ) ;
F_18 ( F_19 ( V_11 ) ) ;
}
static int F_20 ( int V_2 )
{
unsigned long V_19 = 3 << ( V_2 * 8 ) ;
if ( ( F_21 ( V_11 + 8 ) & V_19 ) == V_19 )
return 1 ;
return 0 ;
}
static int F_22 ( unsigned int V_2 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < 1000 ; V_20 ++ ) {
if ( F_20 ( V_2 ) )
return F_3 ( V_2 ) ;
F_23 ( 1 ) ;
}
return 0 ;
}
static void F_24 ( unsigned int V_2 )
{
F_25 () ;
F_26 () ;
F_14 ( V_11 , V_21 ) ;
while ( 1 )
F_27 () ;
}
static int F_28 ( unsigned int V_2 )
{
return V_2 == 0 ? - V_22 : 0 ;
}
