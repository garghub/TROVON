static int T_1 F_1 ( char * V_1 )
{
int V_2 ;
if ( F_2 ( & V_1 , & V_2 ) ) {
if ( V_2 < 1 || V_2 >= V_3 )
goto V_4;
V_5 = V_2 ;
return 0 ;
}
V_4:
return - V_6 ;
}
static void F_3 ( void )
{
int V_7 ;
unsigned int V_8 = F_4 () ;
if ( F_5 ( V_8 >= V_3 ) )
return;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
F_6 ( V_7 , V_7 == 0 ) ;
F_7 ( V_7 , V_7 == 0 ) ;
}
V_9 [ V_8 ] = 0 ;
V_10 [ 0 ] = V_8 ;
for ( V_7 = 0 ; V_7 < V_5 ; V_7 ++ ) {
F_6 ( V_7 , true ) ;
F_7 ( V_7 , true ) ;
V_9 [ V_7 ] = V_7 ;
V_10 [ V_7 ] = V_7 ;
}
}
static void F_8 ( int V_11 , unsigned int V_12 )
{
F_9 ( V_11 , V_12 ) ;
}
static void F_10 ( const struct V_13 * V_14 , unsigned int V_12 )
{
unsigned int V_11 ;
F_11 (cpu, *mask)
F_8 ( V_11 , V_12 ) ;
}
static void F_12 ( void )
{
unsigned int V_15 ;
V_15 = F_13 ( V_16 ) ;
F_14 ( ( V_17 ) V_18 ) ;
V_15 |= V_19 ;
F_15 ( V_15 ) ;
F_16 () ;
}
static void F_17 ( void )
{
F_18 ( F_19 () + V_20 / V_21 ) ;
F_20 () ;
}
static void F_21 ( int V_11 , struct V_22 * V_23 )
{
V_24 [ V_11 ] = ( unsigned long ) F_22 ( V_23 ) ;
F_23 () ;
V_25 [ V_11 ] = F_24 ( V_23 ) ;
}
static T_2 F_25 ( int V_26 , void * V_27 )
{
F_26 () ;
return V_28 ;
}
static T_2 F_27 ( int V_26 , void * V_27 )
{
F_28 () ;
return V_28 ;
}
static void F_29 ( unsigned int V_29 )
{
if ( F_30 ( V_30 , F_25 ,
V_31 | V_32 , L_1 ,
F_25 ) ) {
F_31 ( L_2 ) ;
}
if ( F_30 ( V_33 , F_27 ,
V_31 | V_32 , L_3 ,
F_27 ) ) {
F_31 ( L_4 ) ;
}
}
