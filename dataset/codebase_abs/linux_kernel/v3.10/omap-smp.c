void T_1 * F_1 ( void )
{
return V_1 ;
}
static void T_2 F_2 ( unsigned int V_2 )
{
if ( F_3 () && ( F_4 () != V_3 ) )
F_5 ( V_4 ,
4 , 0 , 0 , 0 , 0 , 0 ) ;
F_6 ( & V_5 ) ;
F_7 ( & V_5 ) ;
}
static int T_2 F_8 ( unsigned int V_2 , struct V_6 * V_7 )
{
static struct V_8 * V_9 ;
static bool V_10 ;
static struct V_11 * V_12 ;
void T_1 * V_13 = F_9 () ;
F_6 ( & V_5 ) ;
if ( F_10 () )
F_11 ( 0x200 , 0xfffffdff ) ;
else
F_12 ( 0x20 , V_13 + V_14 ) ;
if ( ! V_9 && ! V_12 ) {
V_9 = F_13 ( L_1 ) ;
V_12 = F_14 ( L_2 ) ;
}
if ( V_10 && V_12 && V_9 ) {
if ( F_15 ( V_15 ) ) {
F_16 () ;
F_17 () ;
}
F_18 ( V_9 ) ;
F_19 ( V_12 , V_16 ) ;
F_20 ( V_9 ) ;
if ( F_15 ( V_15 ) ) {
while ( F_21 () ) {
F_22 ( 1 ) ;
F_23 () ;
}
F_24 () ;
F_25 () ;
}
} else {
F_26 () ;
V_10 = true ;
}
F_27 ( F_28 ( V_2 ) ) ;
F_7 ( & V_5 ) ;
return 0 ;
}
static void T_3 F_29 ( void )
{
unsigned int V_17 = 0 , V_18 = 1 , V_19 ;
V_19 = F_30 () & V_20 ;
if ( V_19 == V_21 ) {
V_1 = F_31 ( F_32 () ) ;
F_33 ( ! V_1 ) ;
V_18 = F_34 ( V_1 ) ;
} else if ( V_19 == V_22 ) {
V_18 = V_23 ;
}
if ( V_18 > V_24 ) {
F_35 ( L_3 ,
V_18 , V_24 ) ;
V_18 = V_24 ;
}
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
F_36 ( V_17 , true ) ;
}
static void T_3 F_37 ( unsigned int V_25 )
{
void * V_26 = V_27 ;
void T_1 * V_13 = F_9 () ;
if ( V_1 )
F_38 ( V_1 ) ;
if ( F_39 () ) {
V_26 = V_28 ;
V_29 |= V_15 ;
}
if ( F_10 () )
F_40 ( F_41 ( V_26 ) ) ;
else
F_12 ( F_41 ( V_30 ) ,
V_13 + V_31 ) ;
}
