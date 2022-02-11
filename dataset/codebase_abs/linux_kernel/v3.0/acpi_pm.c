static inline T_1 F_1 ( void )
{
return F_2 ( V_1 ) & V_2 ;
}
T_1 F_3 ( void )
{
T_1 V_3 = 0 , V_4 = 0 , V_5 = 0 ;
do {
V_3 = F_1 () ;
V_4 = F_1 () ;
V_5 = F_1 () ;
} while ( F_4 ( ( V_3 > V_4 && V_3 < V_5 ) || ( V_4 > V_5 && V_4 < V_3 )
|| ( V_5 > V_3 && V_5 < V_4 ) ) );
return V_4 ;
}
static T_2 F_5 ( struct V_6 * V_7 )
{
return ( T_2 ) F_1 () ;
}
static int T_3 F_6 ( char * V_8 )
{
V_9 = 1 ;
return 1 ;
}
static T_2 F_7 ( struct V_6 * V_7 )
{
return ( T_2 ) F_3 () ;
}
static inline void F_8 ( void )
{
V_10 . V_11 = F_7 ;
V_10 . V_12 = 120 ;
}
static void T_4 F_9 ( struct V_13 * V_14 )
{
if ( V_9 )
return;
if ( V_14 -> V_15 < 3 ) {
F_10 ( V_16 L_1
L_2
L_3
L_4 ) ;
F_8 () ;
}
}
static void T_4 F_11 ( struct V_13 * V_14 )
{
if ( V_9 )
return;
F_10 ( V_16 L_5
L_6
L_7
L_8
L_9
L_10 ) ;
F_8 () ;
}
static int F_12 ( void )
{
T_2 V_17 , V_18 ;
unsigned long V_19 , V_20 ;
F_13 () ;
V_17 = V_10 . V_11 ( & V_10 ) ;
F_14 ( & V_19 ) ;
V_18 = V_10 . V_11 ( & V_10 ) ;
V_20 = ( V_18 - V_17 ) & V_2 ;
if ( V_20 < ( V_21 * 19 ) / 20 ||
V_20 > ( V_21 * 21 ) / 20 ) {
F_10 ( V_22 L_11
L_12 ,
100UL * V_20 / V_21 ) ;
return - 1 ;
}
return 0 ;
}
static int T_3 F_15 ( void )
{
T_2 V_17 , V_18 ;
unsigned int V_23 , V_24 = 0 ;
if ( ! V_1 )
return - V_25 ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
F_16 ( 100 * V_24 ) ;
V_17 = V_10 . V_11 ( & V_10 ) ;
for ( V_23 = 0 ; V_23 < V_27 ; V_23 ++ ) {
V_18 = V_10 . V_11 ( & V_10 ) ;
if ( V_18 == V_17 )
continue;
if ( V_18 > V_17 )
break;
if ( ( V_18 < V_17 ) && ( ( V_18 ) < 0xFFF ) )
break;
F_10 ( V_22 L_13
L_14 ,
V_17 , V_18 ) ;
V_1 = 0 ;
return - V_28 ;
}
if ( V_23 == V_27 ) {
F_10 ( V_22 L_15
L_16 , V_17 ) ;
V_1 = 0 ;
return - V_25 ;
}
}
if ( F_12 () != 0 ) {
V_1 = 0 ;
return - V_25 ;
}
return F_17 ( & V_10 ,
V_29 ) ;
}
static int T_3 F_18 ( char * V_30 )
{
unsigned long V_31 ;
if ( F_19 ( V_30 , 16 , & V_31 ) )
return - V_28 ;
#ifdef F_20
if ( V_31 > V_32 )
return - V_33 ;
#endif
F_10 ( V_22 L_17 ,
V_1 , V_31 ) ;
V_1 = V_31 ;
return 1 ;
}
