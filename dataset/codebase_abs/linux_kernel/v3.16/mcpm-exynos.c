static int F_1 ( unsigned int V_1 , int V_2 )
{
unsigned int V_3 = 100 ;
unsigned int V_4 ;
if ( V_2 ) {
F_2 ( V_1 ) ;
V_4 = V_5 ;
} else {
F_3 ( V_1 ) ;
V_4 = 0 ;
}
while ( V_3 -- ) {
if ( F_4 ( V_1 ) == V_4 )
return 0 ;
F_5 () ;
}
F_6 ( L_1 , V_1 ,
V_2 ? L_2 : L_3 ) ;
return - V_6 ;
}
static int F_7 ( unsigned int V_7 , unsigned int V_1 )
{
unsigned int V_8 = V_7 + ( V_1 * V_9 ) ;
int V_10 = 0 ;
F_6 ( L_4 , V_11 , V_7 , V_1 ) ;
if ( V_7 >= V_9 ||
V_1 >= V_12 )
return - V_13 ;
F_8 () ;
F_9 ( & V_14 ) ;
V_15 [ V_7 ] [ V_1 ] ++ ;
if ( V_15 [ V_7 ] [ V_1 ] == 1 ) {
bool V_16 =
( F_10 ( V_1 ) == 1 ) ;
if ( V_16 )
V_10 = F_1 ( V_1 , 1 ) ;
if ( ! V_10 )
F_11 ( V_8 ) ;
else
F_1 ( V_1 , 0 ) ;
} else if ( V_15 [ V_7 ] [ V_1 ] != 2 ) {
F_12 () ;
}
F_13 ( & V_14 ) ;
F_14 () ;
return V_10 ;
}
static void F_15 ( void )
{
unsigned int V_17 , V_7 , V_1 ;
bool V_18 = false , V_19 = false ;
unsigned int V_8 ;
V_17 = F_16 () ;
V_7 = F_17 ( V_17 , 0 ) ;
V_1 = F_17 ( V_17 , 1 ) ;
V_8 = V_7 + ( V_1 * V_9 ) ;
F_6 ( L_4 , V_11 , V_7 , V_1 ) ;
F_18 ( V_7 >= V_9 ||
V_1 >= V_12 ) ;
F_19 ( V_7 , V_1 ) ;
F_9 ( & V_14 ) ;
F_18 ( F_20 ( V_1 ) != V_20 ) ;
V_15 [ V_7 ] [ V_1 ] -- ;
if ( V_15 [ V_7 ] [ V_1 ] == 0 ) {
F_21 ( V_8 ) ;
if ( F_22 ( V_1 ) )
V_18 = true ;
} else if ( V_15 [ V_7 ] [ V_1 ] == 1 ) {
V_19 = true ;
} else {
F_12 () ;
}
if ( V_18 && F_23 ( V_7 , V_1 ) ) {
F_13 ( & V_14 ) ;
if ( F_24 () == V_21 ) {
asm volatile(
"mcr p15, 1, %0, c15, c0, 3\n\t"
"isb\n\t"
"dsb"
: : "r" (0x400));
}
F_25 ( V_22 ) ;
F_26 ( V_17 ) ;
F_27 ( V_1 , V_23 ) ;
} else {
F_13 ( & V_14 ) ;
F_25 ( V_24 ) ;
}
F_28 ( V_7 , V_1 ) ;
if ( ! V_19 )
F_29 () ;
}
static int F_30 ( unsigned int V_7 , unsigned int V_1 )
{
unsigned int V_3 = 100 ;
unsigned int V_8 = V_7 + ( V_1 * V_9 ) ;
F_6 ( L_4 , V_11 , V_7 , V_1 ) ;
F_18 ( V_7 >= V_9 ||
V_1 >= V_12 ) ;
while ( V_3 -- ) {
if ( F_31 ( V_15 [ V_7 ] [ V_1 ] ) == 0 ) {
if ( ( F_32 ( V_8 ) == 0 ) )
return 0 ;
}
F_33 ( 1 ) ;
}
return - V_6 ;
}
static void T_1 F_34 ( void )
{
unsigned int V_17 , V_7 , V_1 ;
V_17 = F_16 () ;
V_7 = F_17 ( V_17 , 0 ) ;
V_1 = F_17 ( V_17 , 1 ) ;
F_6 ( L_4 , V_11 , V_7 , V_1 ) ;
F_18 ( V_7 >= V_9 ||
V_1 >= V_12 ) ;
V_15 [ V_7 ] [ V_1 ] = 1 ;
}
static void T_2 F_35 ( unsigned int V_25 )
{
asm volatile ("\n"
"cmp r0, #1\n"
"bxne lr\n"
"b cci_enable_port_for_self");
}
static int T_1 F_36 ( void )
{
struct V_26 * V_27 ;
void T_3 * V_28 ;
int V_29 ;
V_27 = F_37 ( NULL , V_30 ) ;
if ( ! V_27 )
return - V_31 ;
F_38 ( V_27 ) ;
if ( ! F_39 () )
return - V_31 ;
V_27 = F_40 ( NULL , NULL ,
L_5 ) ;
if ( ! V_27 )
return - V_31 ;
V_28 = F_41 ( V_27 , 0 ) ;
F_38 ( V_27 ) ;
if ( ! V_28 ) {
F_42 ( L_6 ) ;
return - V_32 ;
}
F_43 ( V_33 , V_34 ) ;
F_34 () ;
V_29 = F_44 ( & V_35 ) ;
if ( ! V_29 )
V_29 = F_45 ( F_35 ) ;
if ( V_29 ) {
F_46 ( V_28 ) ;
return V_29 ;
}
F_47 () ;
F_48 ( L_7 ) ;
F_43 ( 0xe59f0000 , V_28 ) ;
F_43 ( 0xe12fff10 , V_28 + 4 ) ;
F_43 ( F_49 ( V_36 ) , V_28 + 8 ) ;
F_46 ( V_28 ) ;
return V_29 ;
}
