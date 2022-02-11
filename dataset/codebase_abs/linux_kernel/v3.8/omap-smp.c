void T_1 * F_1 ( void )
{
return V_1 ;
}
static void T_2 F_2 ( unsigned int V_2 )
{
if ( F_3 () && ( F_4 () != V_3 ) )
F_5 ( V_4 ,
4 , 0 , 0 , 0 , 0 , 0 ) ;
F_6 ( 0 ) ;
F_7 ( & V_5 ) ;
F_8 ( & V_5 ) ;
}
static int T_2 F_9 ( unsigned int V_2 , struct V_6 * V_7 )
{
static struct V_8 * V_9 ;
static bool V_10 ;
void T_1 * V_11 = F_10 () ;
F_7 ( & V_5 ) ;
if ( F_11 () )
F_12 ( 0x200 , 0xfffffdff ) ;
else
F_13 ( 0x20 , V_11 + V_12 ) ;
F_14 () ;
F_15 () ;
if ( ! V_9 )
V_9 = F_16 ( L_1 ) ;
if ( V_10 ) {
if ( F_17 ( V_13 ) ) {
F_18 () ;
F_19 () ;
}
F_20 ( V_9 ) ;
F_21 ( V_9 ) ;
if ( F_17 ( V_13 ) ) {
while ( F_22 () ) {
F_23 ( 1 ) ;
F_24 () ;
}
F_25 () ;
F_26 () ;
}
} else {
F_27 () ;
V_10 = true ;
}
F_28 ( F_29 ( V_2 ) , 0 ) ;
F_8 ( & V_5 ) ;
return 0 ;
}
static void T_3 F_30 ( void )
{
void * V_14 = V_15 ;
void T_1 * V_11 = F_10 () ;
if ( F_31 () ) {
V_14 = V_16 ;
V_17 |= V_13 ;
}
if ( F_11 () )
F_32 ( F_33 ( V_14 ) ) ;
else
F_13 ( F_33 ( V_18 ) ,
V_11 + V_19 ) ;
F_15 () ;
F_27 () ;
F_34 () ;
}
static void T_3 F_35 ( void )
{
unsigned int V_20 = 0 , V_21 = 1 , V_22 ;
V_22 = F_36 ( V_23 ) & V_24 ;
if ( V_22 == V_25 ) {
V_1 = F_37 ( V_26 ) ;
F_38 ( ! V_1 ) ;
V_21 = F_39 ( V_1 ) ;
} else if ( V_22 == V_27 ) {
V_21 = V_28 ;
}
if ( V_21 > V_29 ) {
F_40 ( L_2 ,
V_21 , V_29 ) ;
V_21 = V_29 ;
}
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ )
F_41 ( V_20 , true ) ;
F_42 ( F_28 ) ;
}
static void T_3 F_43 ( unsigned int V_30 )
{
if ( V_1 )
F_44 ( V_1 ) ;
F_30 () ;
}
