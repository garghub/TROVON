static int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_3 = V_1 + ( V_2 * V_4 ) ;
F_2 ( L_1 , V_5 , V_1 , V_2 ) ;
if ( V_1 >= V_4 ||
V_2 >= V_6 )
return - V_7 ;
F_3 ( V_3 ) ;
return 0 ;
}
static int F_4 ( unsigned int V_2 )
{
F_2 ( L_2 , V_5 , V_2 ) ;
if ( V_2 >= V_6 )
return - V_7 ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_6 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_3 = V_1 + ( V_2 * V_4 ) ;
F_2 ( L_1 , V_5 , V_1 , V_2 ) ;
F_7 ( V_1 >= V_4 ||
V_2 >= V_6 ) ;
F_8 ( V_3 ) ;
}
static void F_9 ( unsigned int V_2 )
{
F_2 ( L_2 , V_5 , V_2 ) ;
F_7 ( V_2 >= V_6 ) ;
F_10 ( V_2 ) ;
}
static void F_11 ( void )
{
F_12 ( V_8 ) ;
}
static void F_13 ( void )
{
if ( F_14 () == V_9 ) {
asm volatile(
"mcr p15, 1, %0, c15, c0, 3\n\t"
"isb\n\t"
"dsb"
: : "r" (0x400));
}
F_12 ( V_10 ) ;
F_15 ( F_16 () ) ;
}
static int F_17 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_11 = 100 ;
unsigned int V_3 = V_1 + ( V_2 * V_4 ) ;
F_2 ( L_1 , V_5 , V_1 , V_2 ) ;
F_7 ( V_1 >= V_4 ||
V_2 >= V_6 ) ;
while ( V_11 -- ) {
if ( ( F_18 ( V_3 ) == 0 ) )
return 0 ;
F_19 ( 1 ) ;
}
return - V_12 ;
}
static void F_20 ( unsigned int V_1 , unsigned int V_2 )
{
F_1 ( V_1 , V_2 ) ;
}
static void T_1 F_21 ( unsigned int V_13 )
{
asm volatile ("\n"
"cmp r0, #1\n"
"bxne lr\n"
"b cci_enable_port_for_self");
}
static void F_22 ( void )
{
F_23 ( 0xe59f0000 , V_14 ) ;
F_23 ( 0xe12fff10 , V_14 + 4 ) ;
F_23 ( F_24 ( V_15 ) , V_14 + 8 ) ;
}
static int T_2 F_25 ( void )
{
struct V_16 * V_17 ;
unsigned int V_18 , V_19 ;
int V_20 ;
V_17 = F_26 ( NULL , V_21 ) ;
if ( ! V_17 )
return - V_22 ;
F_27 ( V_17 ) ;
if ( ! F_28 () )
return - V_22 ;
V_17 = F_29 ( NULL , NULL ,
L_3 ) ;
if ( ! V_17 )
return - V_22 ;
V_14 = F_30 ( V_17 , 0 ) ;
F_27 ( V_17 ) ;
if ( ! V_14 ) {
F_31 ( L_4 ) ;
return - V_23 ;
}
F_32 ( V_24 , V_25 ) ;
V_20 = F_33 ( & V_26 ) ;
if ( ! V_20 )
V_20 = F_34 ( F_21 ) ;
if ( ! V_20 )
V_20 = F_35 ( F_13 ) ;
if ( V_20 ) {
F_36 ( V_14 ) ;
return V_20 ;
}
F_37 () ;
F_38 ( L_5 ) ;
for ( V_19 = 0 ; V_19 < V_6 ; V_19 ++ ) {
V_18 = F_39 ( F_40 ( V_19 ) ) ;
V_18 |= V_27 |
V_28 |
V_29 ;
F_32 ( V_18 , F_40 ( V_19 ) ) ;
}
F_22 () ;
F_41 ( & V_30 ) ;
return V_20 ;
}
