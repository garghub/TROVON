static int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
F_2 ( L_1 , V_3 , V_1 , V_2 ) ;
if ( V_2 >= V_4 || V_1 >= V_5 [ V_2 ] )
return - V_6 ;
F_3 ( V_2 , V_1 ,
F_4 ( V_7 ) ) ;
F_5 ( V_2 , V_1 , true ) ;
return 0 ;
}
static int F_6 ( unsigned int V_2 )
{
F_2 ( L_2 , V_3 , V_2 ) ;
if ( V_2 >= V_4 )
return - V_6 ;
F_7 ( V_2 , false ) ;
return 0 ;
}
static void F_8 ( unsigned int V_1 , unsigned int V_2 )
{
F_2 ( L_1 , V_3 , V_1 , V_2 ) ;
F_9 ( V_2 >= V_4 || V_1 >= V_8 ) ;
F_5 ( V_2 , V_1 , true ) ;
F_10 ( 0 ) ;
}
static void F_11 ( unsigned int V_2 )
{
F_2 ( L_2 , V_3 , V_2 ) ;
F_9 ( V_2 >= V_4 ) ;
F_7 ( V_2 , true ) ;
F_12 ( true ) ;
}
static void F_13 ( void )
{
F_14 ( V_9 ) ;
}
static void F_15 ( void )
{
if ( F_16 () == V_10 ) {
asm volatile(
"mcr p15, 1, %0, c15, c0, 3 \n\t"
"isb \n\t"
"dsb "
: : "r" (0x400) );
}
F_14 ( V_11 ) ;
F_17 ( F_18 () ) ;
}
static int F_19 ( unsigned int V_1 , unsigned int V_2 )
{
T_1 V_12 = V_2 ?
F_20 ( V_1 )
: F_21 ( V_1 ) ;
return ! ( F_22 ( V_13 + V_14 ) & V_12 ) ;
}
static int F_23 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned V_15 ;
F_2 ( L_1 , V_3 , V_1 , V_2 ) ;
F_9 ( V_2 >= V_4 || V_1 >= V_8 ) ;
for ( V_15 = 0 ; V_15 < V_16 / V_17 ; ++ V_15 ) {
F_2 ( L_3 ,
V_3 , V_1 , V_2 ,
F_22 ( V_13 + V_14 ) ) ;
if ( F_19 ( V_1 , V_2 ) ||
F_24 ( V_1 , V_2 ) )
return 0 ;
F_25 ( V_17 ) ;
}
return - V_18 ;
}
static void F_26 ( unsigned int V_1 , unsigned int V_2 )
{
F_3 ( V_2 , V_1 , F_4 ( V_7 ) ) ;
}
static void F_27 ( unsigned int V_1 , unsigned int V_2 )
{
F_2 ( L_1 , V_3 , V_1 , V_2 ) ;
F_9 ( V_2 >= V_4 || V_1 >= V_8 ) ;
F_5 ( V_2 , V_1 , false ) ;
F_3 ( V_2 , V_1 , 0 ) ;
}
static void F_28 ( unsigned int V_2 )
{
F_2 ( L_2 , V_3 , V_2 ) ;
F_9 ( V_2 >= V_4 ) ;
F_7 ( V_2 , false ) ;
F_12 ( false ) ;
}
static void T_2 F_29 ( unsigned int V_19 )
{
asm volatile (" \n"
" cmp r0, #1 \n"
" bxne lr \n"
" b cci_enable_port_for_self ");
}
static int T_3 F_30 ( void )
{
unsigned int V_20 , V_1 , V_2 ;
int V_21 , V_22 ;
T_1 V_23 , V_24 , V_25 ;
struct V_26 * V_27 ;
V_27 = F_31 ( NULL , NULL ,
L_4 ) ;
V_13 = F_32 ( V_27 , 0 ) ;
if ( ! V_13 )
return - V_28 ;
V_23 = F_22 ( V_13 + V_29 ) & 0xf ;
V_24 = F_22 ( V_13 + V_30 ) & 0xf ;
if ( V_23 >= V_4 || V_24 >= V_4 )
return - V_6 ;
V_25 = F_22 ( V_13 + V_31 ) ;
V_5 [ V_23 ] = ( V_25 >> 16 ) & 0xf ;
V_5 [ V_24 ] = ( V_25 >> 20 ) & 0xf ;
V_22 = F_33 ( V_27 , 0 ) ;
V_21 = F_34 ( V_13 + V_32 , V_23 , V_22 ) ;
if ( V_21 )
return V_21 ;
if ( ! F_35 () )
return - V_28 ;
V_20 = F_18 () ;
V_1 = F_36 ( V_20 , 0 ) ;
V_2 = F_36 ( V_20 , 1 ) ;
F_2 ( L_1 , V_3 , V_1 , V_2 ) ;
if ( V_2 >= V_4 || V_1 >= V_5 [ V_2 ] ) {
F_37 ( L_5 , V_3 ) ;
return - V_6 ;
}
V_21 = F_38 ( & V_33 ) ;
if ( ! V_21 ) {
F_39 ( F_29 ) ;
F_9 ( F_40 ( F_15 ) != 0 ) ;
F_41 ( L_6 ) ;
}
return V_21 ;
}
