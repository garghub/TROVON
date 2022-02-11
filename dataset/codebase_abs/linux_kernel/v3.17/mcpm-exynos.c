static int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_3 = V_1 + ( V_2 * V_4 ) ;
F_2 ( L_1 , V_5 , V_1 , V_2 ) ;
if ( V_1 >= V_4 ||
V_2 >= V_6 )
return - V_7 ;
F_3 () ;
F_4 ( & V_8 ) ;
V_9 [ V_1 ] [ V_2 ] ++ ;
if ( V_9 [ V_1 ] [ V_2 ] == 1 ) {
bool V_10 =
( F_5 ( V_2 ) == 1 ) ;
if ( V_10 )
F_6 ( V_2 ) ;
F_7 ( V_3 ) ;
} else if ( V_9 [ V_1 ] [ V_2 ] != 2 ) {
F_8 () ;
}
F_9 ( & V_8 ) ;
F_10 () ;
return 0 ;
}
static void F_11 ( void )
{
unsigned int V_11 , V_1 , V_2 ;
bool V_12 = false , V_13 = false ;
unsigned int V_3 ;
V_11 = F_12 () ;
V_1 = F_13 ( V_11 , 0 ) ;
V_2 = F_13 ( V_11 , 1 ) ;
V_3 = V_1 + ( V_2 * V_4 ) ;
F_2 ( L_1 , V_5 , V_1 , V_2 ) ;
F_14 ( V_1 >= V_4 ||
V_2 >= V_6 ) ;
F_15 ( V_1 , V_2 ) ;
F_4 ( & V_8 ) ;
F_14 ( F_16 ( V_2 ) != V_14 ) ;
V_9 [ V_1 ] [ V_2 ] -- ;
if ( V_9 [ V_1 ] [ V_2 ] == 0 ) {
F_17 ( V_3 ) ;
if ( F_18 ( V_2 ) ) {
F_19 ( V_2 ) ;
V_12 = true ;
}
} else if ( V_9 [ V_1 ] [ V_2 ] == 1 ) {
V_13 = true ;
} else {
F_8 () ;
}
if ( V_12 && F_20 ( V_1 , V_2 ) ) {
F_9 ( & V_8 ) ;
if ( F_21 () == V_15 ) {
asm volatile(
"mcr p15, 1, %0, c15, c0, 3\n\t"
"isb\n\t"
"dsb"
: : "r" (0x400));
}
F_22 ( V_16 ) ;
F_23 ( V_11 ) ;
F_24 ( V_2 , V_17 ) ;
} else {
F_9 ( & V_8 ) ;
F_22 ( V_18 ) ;
}
F_25 ( V_1 , V_2 ) ;
if ( ! V_13 )
F_26 () ;
}
static int F_27 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_19 = 100 ;
unsigned int V_3 = V_1 + ( V_2 * V_4 ) ;
F_2 ( L_1 , V_5 , V_1 , V_2 ) ;
F_14 ( V_1 >= V_4 ||
V_2 >= V_6 ) ;
while ( V_19 -- ) {
if ( F_28 ( V_9 [ V_1 ] [ V_2 ] ) == 0 ) {
if ( ( F_29 ( V_3 ) == 0 ) )
return 0 ;
}
F_30 ( 1 ) ;
}
return - V_20 ;
}
static void F_31 ( void )
{
unsigned int V_11 , V_1 , V_2 ;
V_11 = F_12 () ;
V_1 = F_13 ( V_11 , 0 ) ;
V_2 = F_13 ( V_11 , 1 ) ;
F_4 ( & V_8 ) ;
if ( V_9 [ V_1 ] [ V_2 ] == 0 )
V_9 [ V_1 ] [ V_2 ] = 1 ;
F_9 ( & V_8 ) ;
}
static void F_32 ( T_1 V_21 )
{
unsigned int V_11 , V_3 ;
F_11 () ;
V_11 = F_12 () ;
V_3 = F_33 ( V_11 ) ;
F_7 ( V_3 ) ;
}
static void T_2 F_34 ( void )
{
unsigned int V_11 , V_1 , V_2 ;
V_11 = F_12 () ;
V_1 = F_13 ( V_11 , 0 ) ;
V_2 = F_13 ( V_11 , 1 ) ;
F_2 ( L_1 , V_5 , V_1 , V_2 ) ;
F_14 ( V_1 >= V_4 ||
V_2 >= V_6 ) ;
V_9 [ V_1 ] [ V_2 ] = 1 ;
}
static void T_3 F_35 ( unsigned int V_22 )
{
asm volatile ("\n"
"cmp r0, #1\n"
"bxne lr\n"
"b cci_enable_port_for_self");
}
static void T_2 F_36 ( void )
{
if ( F_21 () == V_15 ) {
asm volatile(
"mcr p15, 1, %0, c15, c0, 3\n\t"
"isb\n\t"
"dsb"
: : "r" (0x400));
}
F_22 ( V_16 ) ;
}
static int T_2 F_37 ( void )
{
struct V_23 * V_24 ;
void T_4 * V_25 ;
unsigned int V_26 , V_27 ;
int V_28 ;
V_24 = F_38 ( NULL , V_29 ) ;
if ( ! V_24 )
return - V_30 ;
F_39 ( V_24 ) ;
if ( ! F_40 () )
return - V_30 ;
V_24 = F_41 ( NULL , NULL ,
L_2 ) ;
if ( ! V_24 )
return - V_30 ;
V_25 = F_42 ( V_24 , 0 ) ;
F_39 ( V_24 ) ;
if ( ! V_25 ) {
F_43 ( L_3 ) ;
return - V_31 ;
}
F_44 ( V_32 , V_33 ) ;
F_34 () ;
V_28 = F_45 ( & V_34 ) ;
if ( ! V_28 )
V_28 = F_46 ( F_35 ) ;
if ( ! V_28 )
V_28 = F_47 ( F_36 ) ;
if ( V_28 ) {
F_48 ( V_25 ) ;
return V_28 ;
}
F_49 () ;
F_50 ( L_4 ) ;
for ( V_27 = 0 ; V_27 < V_6 ; V_27 ++ ) {
V_26 = F_51 ( F_52 ( V_27 ) ) ;
V_26 |= V_35 |
V_36 |
V_37 ;
F_44 ( V_26 , F_52 ( V_27 ) ) ;
}
F_53 ( 0xe59f0000 , V_25 ) ;
F_53 ( 0xe12fff10 , V_25 + 4 ) ;
F_53 ( F_54 ( V_38 ) , V_25 + 8 ) ;
F_48 ( V_25 ) ;
return V_28 ;
}
