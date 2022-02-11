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
static void F_9 ( struct V_13 * V_14 )
{
if ( V_9 )
return;
if ( V_14 -> V_15 < 3 ) {
F_10 ( L_1
L_2 ) ;
F_8 () ;
}
}
static void F_11 ( struct V_13 * V_14 )
{
if ( V_9 )
return;
F_10 ( L_3
L_4
L_5 ) ;
F_8 () ;
}
static int F_12 ( void )
{
T_2 V_16 , V_17 ;
unsigned long V_18 , V_19 ;
F_13 () ;
V_16 = V_10 . V_11 ( & V_10 ) ;
F_14 ( & V_18 ) ;
V_17 = V_10 . V_11 ( & V_10 ) ;
V_19 = ( V_17 - V_16 ) & V_2 ;
if ( V_19 < ( V_20 * 19 ) / 20 ||
V_19 > ( V_20 * 21 ) / 20 ) {
F_15 ( L_6 ,
100UL * V_19 / V_20 ) ;
return - 1 ;
}
return 0 ;
}
static int T_3 F_16 ( void )
{
T_2 V_16 , V_17 ;
unsigned int V_21 , V_22 = 0 ;
if ( ! V_1 )
return - V_23 ;
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ ) {
F_17 ( 100 * V_22 ) ;
V_16 = V_10 . V_11 ( & V_10 ) ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ ) {
V_17 = V_10 . V_11 ( & V_10 ) ;
if ( V_17 == V_16 )
continue;
if ( V_17 > V_16 )
break;
if ( ( V_17 < V_16 ) && ( ( V_17 ) < 0xFFF ) )
break;
F_15 ( L_7 ,
V_16 , V_17 ) ;
V_1 = 0 ;
return - V_26 ;
}
if ( V_21 == V_25 ) {
F_15 ( L_8 ,
V_16 ) ;
V_1 = 0 ;
return - V_23 ;
}
}
if ( F_12 () != 0 ) {
V_1 = 0 ;
return - V_23 ;
}
return F_18 ( & V_10 ,
V_27 ) ;
}
static int T_3 F_19 ( char * V_28 )
{
unsigned int V_29 ;
int V_30 ;
V_30 = F_20 ( V_28 , 16 , & V_29 ) ;
if ( V_30 )
return V_30 ;
F_15 ( L_9 , V_1 ,
V_29 ) ;
V_1 = V_29 ;
return 1 ;
}
