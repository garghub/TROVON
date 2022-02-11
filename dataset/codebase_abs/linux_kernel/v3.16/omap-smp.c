void T_1 * F_1 ( void )
{
return V_1 ;
}
static void F_2 ( unsigned int V_2 )
{
if ( F_3 () && ( F_4 () != V_3 ) )
F_5 ( V_4 ,
4 , 0 , 0 , 0 , 0 , 0 ) ;
if ( F_6 () || F_7 () )
F_8 () ;
F_9 ( & V_5 ) ;
F_10 ( & V_5 ) ;
}
static int F_11 ( unsigned int V_2 , struct V_6 * V_7 )
{
static struct V_8 * V_9 ;
static bool V_10 ;
static struct V_11 * V_12 ;
void T_1 * V_13 = F_12 () ;
F_9 ( & V_5 ) ;
if ( F_13 () )
F_14 ( 0x200 , 0xfffffdff ) ;
else
F_15 ( 0x20 , V_13 + V_14 ) ;
if ( ! V_9 && ! V_12 ) {
V_9 = F_16 ( L_1 ) ;
V_12 = F_17 ( L_2 ) ;
}
if ( V_10 && V_12 && V_9 ) {
if ( F_18 ( V_15 ) ) {
F_19 () ;
F_20 () ;
}
F_21 ( V_9 ) ;
F_22 ( V_12 , V_16 ) ;
F_23 ( V_9 ) ;
if ( F_18 ( V_15 ) ) {
while ( F_24 () ) {
F_25 ( 1 ) ;
F_26 () ;
}
F_27 () ;
F_28 () ;
}
} else {
F_29 () ;
V_10 = true ;
}
F_30 ( F_31 ( V_2 ) ) ;
F_10 ( & V_5 ) ;
return 0 ;
}
static void T_2 F_32 ( void )
{
unsigned int V_17 = 0 , V_18 = 1 , V_19 ;
V_19 = F_33 () & V_20 ;
if ( V_19 == V_21 ) {
V_1 = F_34 ( F_35 () ) ;
F_36 ( ! V_1 ) ;
V_18 = F_37 ( V_1 ) ;
} else if ( V_19 == V_22 ) {
V_18 = V_23 ;
}
if ( V_18 > V_24 ) {
F_38 ( L_3 ,
V_18 , V_24 ) ;
V_18 = V_24 ;
}
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
F_39 ( V_17 , true ) ;
}
static void T_2 F_40 ( unsigned int V_25 )
{
void * V_26 = V_27 ;
void T_1 * V_13 = F_12 () ;
if ( V_1 )
F_41 ( V_1 ) ;
if ( F_42 () )
V_26 = V_28 ;
if ( F_13 () )
F_43 ( F_44 ( V_26 ) ) ;
else
F_15 ( F_44 ( V_29 ) ,
V_13 + V_30 ) ;
}
