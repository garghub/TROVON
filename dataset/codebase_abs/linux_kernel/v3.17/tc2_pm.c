static int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
F_2 ( L_1 , V_3 , V_1 , V_2 ) ;
if ( V_2 >= V_4 || V_1 >= V_5 [ V_2 ] )
return - V_6 ;
F_3 () ;
F_4 ( & V_7 ) ;
if ( F_5 ( V_2 ) )
F_6 ( V_2 , false ) ;
V_8 [ V_1 ] [ V_2 ] ++ ;
if ( V_8 [ V_1 ] [ V_2 ] == 1 ) {
F_7 ( V_2 , V_1 ,
F_8 ( V_9 ) ) ;
F_9 ( V_2 , V_1 , true ) ;
} else if ( V_8 [ V_1 ] [ V_2 ] != 2 ) {
F_10 () ;
}
F_11 ( & V_7 ) ;
F_12 () ;
return 0 ;
}
static void F_13 ( T_1 V_10 )
{
unsigned int V_11 , V_1 , V_2 ;
bool V_12 = false , V_13 = false ;
V_11 = F_14 () ;
V_1 = F_15 ( V_11 , 0 ) ;
V_2 = F_15 ( V_11 , 1 ) ;
F_2 ( L_1 , V_3 , V_1 , V_2 ) ;
F_16 ( V_2 >= V_4 || V_1 >= V_14 ) ;
F_17 ( V_1 , V_2 ) ;
F_4 ( & V_7 ) ;
F_16 ( F_18 ( V_2 ) != V_15 ) ;
V_8 [ V_1 ] [ V_2 ] -- ;
if ( V_8 [ V_1 ] [ V_2 ] == 0 ) {
F_9 ( V_2 , V_1 , true ) ;
if ( F_5 ( V_2 ) ) {
F_6 ( V_2 , true ) ;
F_19 ( true ) ;
V_12 = true ;
}
} else if ( V_8 [ V_1 ] [ V_2 ] == 1 ) {
V_13 = true ;
} else
F_10 () ;
if ( ! V_13 )
F_20 () ;
if ( V_12 && F_21 ( V_1 , V_2 ) ) {
F_11 ( & V_7 ) ;
if ( F_22 () == V_16 ) {
asm volatile(
"mcr p15, 1, %0, c15, c0, 3 \n\t"
"isb \n\t"
"dsb "
: : "r" (0x400) );
}
F_23 ( V_17 ) ;
F_24 ( V_11 ) ;
F_25 ( V_2 , V_18 ) ;
} else {
if ( V_12 ) {
F_6 ( V_2 , false ) ;
F_19 ( false ) ;
}
F_11 ( & V_7 ) ;
F_23 ( V_19 ) ;
}
F_26 ( V_1 , V_2 ) ;
if ( ! V_13 )
F_27 () ;
}
static void F_28 ( void )
{
F_13 ( 0 ) ;
}
static int F_29 ( unsigned int V_1 , unsigned int V_2 )
{
T_2 V_20 = V_2 ?
F_30 ( V_1 )
: F_31 ( V_1 ) ;
return ! ( F_32 ( V_21 + V_22 ) & V_20 ) ;
}
static int F_33 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned V_23 ;
F_2 ( L_1 , V_3 , V_1 , V_2 ) ;
F_16 ( V_2 >= V_4 || V_1 >= V_14 ) ;
for ( V_23 = 0 ; V_23 < V_24 / V_25 ; ++ V_23 ) {
if ( F_34 ( V_8 [ V_1 ] [ V_2 ] ) == 0 ) {
F_2 ( L_2 ,
V_3 , V_1 , V_2 ,
F_32 ( V_21 + V_22 ) ) ;
if ( F_29 ( V_1 , V_2 ) ||
F_35 ( V_1 , V_2 ) )
return 0 ;
}
F_36 ( V_25 ) ;
}
return - V_26 ;
}
static void F_37 ( T_1 V_10 )
{
unsigned int V_11 , V_1 , V_2 ;
V_11 = F_14 () ;
V_1 = F_15 ( V_11 , 0 ) ;
V_2 = F_15 ( V_11 , 1 ) ;
F_7 ( V_2 , V_1 , F_8 ( V_9 ) ) ;
F_13 ( V_10 ) ;
}
static void F_38 ( void )
{
unsigned int V_11 , V_1 , V_2 ;
unsigned long V_27 ;
V_11 = F_14 () ;
V_1 = F_15 ( V_11 , 0 ) ;
V_2 = F_15 ( V_11 , 1 ) ;
F_2 ( L_1 , V_3 , V_1 , V_2 ) ;
F_16 ( V_2 >= V_4 || V_1 >= V_14 ) ;
F_39 ( V_27 ) ;
F_4 ( & V_7 ) ;
if ( F_5 ( V_2 ) ) {
F_6 ( V_2 , false ) ;
F_19 ( false ) ;
}
if ( ! V_8 [ V_1 ] [ V_2 ] )
V_8 [ V_1 ] [ V_2 ] = 1 ;
F_9 ( V_2 , V_1 , false ) ;
F_7 ( V_2 , V_1 , 0 ) ;
F_11 ( & V_7 ) ;
F_40 ( V_27 ) ;
}
static bool T_3 F_41 ( void )
{
unsigned int V_11 , V_1 , V_2 ;
V_11 = F_14 () ;
V_1 = F_15 ( V_11 , 0 ) ;
V_2 = F_15 ( V_11 , 1 ) ;
F_2 ( L_1 , V_3 , V_1 , V_2 ) ;
if ( V_2 >= V_4 || V_1 >= V_5 [ V_2 ] ) {
F_42 ( L_3 , V_3 ) ;
return false ;
}
V_8 [ V_1 ] [ V_2 ] = 1 ;
return true ;
}
static void T_4 F_43 ( unsigned int V_28 )
{
asm volatile (" \n"
" cmp r0, #1 \n"
" bxne lr \n"
" b cci_enable_port_for_self ");
}
static void T_3 F_44 ( void )
{
F_45 ( L_4 ) ;
if ( F_22 () == V_16 ) {
asm volatile(
"mcr p15, 1, %0, c15, c0, 3 \n\t"
"isb \n\t"
"dsb "
: : "r" (0x400) );
}
F_23 ( V_17 ) ;
F_24 ( F_14 () ) ;
}
static int T_3 F_46 ( void )
{
int V_29 , V_30 ;
T_2 V_31 , V_32 , V_33 ;
struct V_34 * V_35 ;
V_35 = F_47 ( NULL , NULL ,
L_5 ) ;
V_21 = F_48 ( V_35 , 0 ) ;
if ( ! V_21 )
return - V_36 ;
V_31 = F_32 ( V_21 + V_37 ) & 0xf ;
V_32 = F_32 ( V_21 + V_38 ) & 0xf ;
if ( V_31 >= V_4 || V_32 >= V_4 )
return - V_6 ;
V_33 = F_32 ( V_21 + V_39 ) ;
V_5 [ V_31 ] = ( V_33 >> 16 ) & 0xf ;
V_5 [ V_32 ] = ( V_33 >> 20 ) & 0xf ;
V_30 = F_49 ( V_35 , 0 ) ;
V_29 = F_50 ( V_21 + V_40 , V_31 , V_30 ) ;
if ( V_29 )
return V_29 ;
if ( ! F_51 () )
return - V_36 ;
if ( ! F_41 () )
return - V_6 ;
V_29 = F_52 ( & V_41 ) ;
if ( ! V_29 ) {
F_53 ( F_43 ) ;
F_16 ( F_54 ( F_44 ) != 0 ) ;
F_45 ( L_6 ) ;
}
return V_29 ;
}
