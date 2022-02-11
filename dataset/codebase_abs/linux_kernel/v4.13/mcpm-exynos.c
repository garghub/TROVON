static int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_3 = V_1 + ( V_2 * V_4 ) ;
F_2 ( L_1 , V_5 , V_1 , V_2 ) ;
if ( V_1 >= V_4 ||
V_2 >= V_6 )
return - V_7 ;
if ( ! F_3 ( V_3 ) ) {
F_4 ( V_3 ) ;
if ( V_2 &&
V_2 == F_5 ( F_6 ( 0 ) , 1 ) ) {
while ( ! F_7 ( V_8 ) )
F_8 ( 10 ) ;
F_9 ( F_10 ( V_1 ) ,
V_9 ) ;
}
}
return 0 ;
}
static int F_11 ( unsigned int V_2 )
{
F_2 ( L_2 , V_5 , V_2 ) ;
if ( V_2 >= V_6 )
return - V_7 ;
F_12 ( V_2 ) ;
return 0 ;
}
static void F_13 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_3 = V_1 + ( V_2 * V_4 ) ;
F_2 ( L_1 , V_5 , V_1 , V_2 ) ;
F_14 ( V_1 >= V_4 ||
V_2 >= V_6 ) ;
F_15 ( V_3 ) ;
}
static void F_16 ( unsigned int V_2 )
{
F_2 ( L_2 , V_5 , V_2 ) ;
F_14 ( V_2 >= V_6 ) ;
F_17 ( V_2 ) ;
}
static void F_18 ( void )
{
F_19 ( V_10 ) ;
}
static void F_20 ( void )
{
if ( F_21 () == V_11 ) {
asm volatile(
"mcr p15, 1, %0, c15, c0, 3\n\t"
"isb\n\t"
"dsb"
: : "r" (0x400));
}
F_19 ( V_12 ) ;
F_22 ( F_23 () ) ;
}
static int F_24 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_13 = 100 ;
unsigned int V_3 = V_1 + ( V_2 * V_4 ) ;
F_2 ( L_1 , V_5 , V_1 , V_2 ) ;
F_14 ( V_1 >= V_4 ||
V_2 >= V_6 ) ;
while ( V_13 -- ) {
if ( ( F_3 ( V_3 ) == 0 ) )
return 0 ;
F_25 ( 1 ) ;
}
return - V_14 ;
}
static void F_26 ( unsigned int V_1 , unsigned int V_2 )
{
F_1 ( V_1 , V_2 ) ;
}
static void T_1 F_27 ( unsigned int V_15 )
{
asm volatile ("\n"
"cmp r0, #1\n"
"bxne lr\n"
"b cci_enable_port_for_self");
}
static void F_28 ( void )
{
F_29 ( 0xe59f0000 , V_16 ) ;
F_29 ( 0xe12fff10 , V_16 + 4 ) ;
F_29 ( F_30 ( V_17 ) , V_16 + 8 ) ;
}
static int T_2 F_31 ( void )
{
struct V_18 * V_19 ;
unsigned int V_20 , V_21 ;
int V_22 ;
V_19 = F_32 ( NULL , V_23 ) ;
if ( ! V_19 )
return - V_24 ;
F_33 ( V_19 ) ;
if ( ! F_34 () )
return - V_24 ;
V_19 = F_35 ( NULL , NULL ,
L_3 ) ;
if ( ! V_19 )
return - V_24 ;
V_16 = F_36 ( V_19 , 0 ) ;
F_33 ( V_19 ) ;
if ( ! V_16 ) {
F_37 ( L_4 ) ;
return - V_25 ;
}
F_9 ( V_26 , V_27 ) ;
V_22 = F_38 ( & V_28 ) ;
if ( ! V_22 )
V_22 = F_39 ( F_27 ) ;
if ( ! V_22 )
V_22 = F_40 ( F_20 ) ;
if ( V_22 ) {
F_41 ( V_16 ) ;
return V_22 ;
}
F_42 () ;
F_43 ( L_5 ) ;
for ( V_21 = 0 ; V_21 < V_6 ; V_21 ++ ) {
V_20 = F_7 ( F_44 ( V_21 ) ) ;
V_20 |= V_29 |
V_30 |
V_31 ;
F_9 ( V_20 , F_44 ( V_21 ) ) ;
}
F_28 () ;
F_45 ( & V_32 ) ;
return V_22 ;
}
