static bool F_1 ( unsigned int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_4 [ V_1 ] [ V_2 ] )
return false ;
return true ;
}
static void F_2 ( unsigned int V_1 , unsigned int V_5 )
{
unsigned long V_6 ;
if ( ! V_7 )
F_3 () ;
V_6 = F_4 ( V_7 + V_8 ) ;
if ( V_5 )
V_6 |= 1 << V_1 ;
else
V_6 &= ~ ( 1 << V_1 ) ;
F_5 ( V_6 , V_7 + V_8 ) ;
do {
F_6 () ;
} while ( V_6 != F_4 ( V_7 + V_8 ) );
}
static int F_7 ( unsigned int V_9 , unsigned int V_1 )
{
unsigned long V_6 ;
void T_1 * V_10 , * V_11 ;
if ( ! V_12 )
return - V_13 ;
if ( V_1 >= V_14 || V_9 >= V_3 )
return - V_15 ;
F_8 ( & V_16 ) ;
if ( V_4 [ V_1 ] [ V_9 ] )
goto V_17;
V_10 = V_12 + F_9 ( V_1 ) ;
V_11 = V_12 + F_10 ( V_1 ) ;
if ( F_1 ( V_1 ) ) {
V_6 = V_18 ;
F_5 ( V_6 , V_10 ) ;
do {
F_6 () ;
V_6 = F_4 ( V_11 ) ;
} while ( V_6 & V_19 );
}
V_6 = F_11 ( V_9 ) | F_12 ( V_9 ) | \
F_13 ( V_9 ) ;
F_5 ( V_6 , V_10 ) ;
do {
F_6 () ;
} while ( V_6 == F_4 ( V_11 ) );
F_14 ( 20 ) ;
V_17:
V_4 [ V_1 ] [ V_9 ] ++ ;
F_15 ( & V_16 ) ;
return 0 ;
}
static void F_16 ( void )
{
unsigned int V_20 , V_9 , V_1 ;
bool V_21 = false , V_22 = false ;
V_20 = F_17 () ;
V_9 = F_18 ( V_20 , 0 ) ;
V_1 = F_18 ( V_20 , 1 ) ;
F_19 ( V_9 , V_1 ) ;
F_20 ( & V_16 ) ;
F_21 ( F_22 ( V_1 ) != V_23 ) ;
V_4 [ V_1 ] [ V_9 ] -- ;
if ( V_4 [ V_1 ] [ V_9 ] == 1 ) {
V_21 = true ;
} else if ( V_4 [ V_1 ] [ V_9 ] > 1 ) {
F_23 ( L_1 , V_1 , V_9 ) ;
F_3 () ;
}
V_22 = F_1 ( V_1 ) ;
if ( V_22 && F_24 ( V_9 , V_1 ) ) {
F_25 ( & V_16 ) ;
asm volatile(
"mcr p15, 1, %0, c15, c0, 3 \n\t"
"isb \n\t"
"dsb "
: : "r" (0x400) );
F_26 ( V_24 ) ;
F_2 ( V_1 , 0 ) ;
F_27 ( V_1 , V_25 ) ;
} else {
F_25 ( & V_16 ) ;
F_26 ( V_26 ) ;
}
F_28 ( V_9 , V_1 ) ;
if ( ! V_21 )
F_29 () ;
}
static int F_30 ( unsigned int V_9 , unsigned int V_1 )
{
unsigned int V_6 , V_27 , V_28 ;
int V_29 = - V_30 ;
F_21 ( V_1 >= V_14 ||
V_9 >= V_3 ) ;
V_28 = V_31 / V_32 ;
F_8 ( & V_16 ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
if ( V_4 [ V_1 ] [ V_9 ] ) {
V_29 = - V_33 ;
goto V_34;
}
F_6 () ;
V_6 = F_4 ( V_12 + F_10 ( V_1 ) ) ;
if ( V_6 & F_31 ( V_9 ) )
break;
F_15 ( & V_16 ) ;
F_32 ( V_32 ) ;
F_8 ( & V_16 ) ;
}
if ( V_27 >= V_28 )
goto V_34;
V_6 = F_11 ( V_9 ) | F_12 ( V_9 ) | \
F_13 ( V_9 ) ;
F_5 ( V_6 , V_12 + F_33 ( V_1 ) ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
F_6 () ;
V_6 = F_4 ( V_12 + F_10 ( V_1 ) ) ;
if ( V_6 & F_34 ( V_9 ) )
break;
}
if ( V_27 >= V_28 )
goto V_34;
F_15 ( & V_16 ) ;
return 0 ;
V_34:
F_15 ( & V_16 ) ;
return V_29 ;
}
static void F_35 ( void )
{
unsigned int V_20 , V_9 , V_1 ;
V_20 = F_17 () ;
V_9 = F_18 ( V_20 , 0 ) ;
V_1 = F_18 ( V_20 , 1 ) ;
F_20 ( & V_16 ) ;
if ( ! V_4 [ V_1 ] [ V_9 ] )
V_4 [ V_1 ] [ V_9 ] = 1 ;
F_25 ( & V_16 ) ;
}
static void T_2 F_36 ( unsigned int V_35 )
{
asm volatile (" \n"
" cmp r0, #0 \n"
" bxeq lr \n"
" adr r2, 2f \n"
" ldmia r2, {r1, r3} \n"
" sub r0, r2, r1 \n"
" ldr r2, [r0, r3] \n"
" mrc p15, 0, r0, c0, c0, 5 \n"
" ubfx r1, r0, #8, #8 \n"
" mov r0, #1 \n"
" mov r3, r0, lsl r1 \n"
" ldr r0, [r2, #"__stringify(FAB_SF_MODE)"] \n"
" tst r0, r3 \n"
" bxne lr \n"
" orr r1, r0, r3 \n"
" str r1, [r2, #"__stringify(FAB_SF_MODE)"] \n"
"1: ldr r0, [r2, #"__stringify(FAB_SF_MODE)"] \n"
" tst r0, r3 \n"
" beq 1b \n"
" bx lr \n"
" .align 2 \n"
"2: .word . \n"
" .word fabric_phys_addr \n"
);
}
static bool T_3 F_37 ( void )
{
unsigned int V_20 , V_9 , V_1 ;
V_20 = F_17 () ;
V_9 = F_18 ( V_20 , 0 ) ;
V_1 = F_18 ( V_20 , 1 ) ;
if ( V_1 >= V_14 ||
V_9 >= V_3 ) {
F_23 ( L_2 , V_36 ) ;
return false ;
}
F_2 ( V_1 , 1 ) ;
V_4 [ V_1 ] [ V_9 ] = 1 ;
return true ;
}
static int T_3 F_38 ( void )
{
struct V_37 * V_38 , * V_39 , * V_40 ;
struct V_41 V_42 ;
void T_1 * V_43 ;
int V_29 = - V_13 ;
V_38 = F_39 ( NULL , NULL , L_3 ) ;
if ( ! V_38 )
goto V_34;
V_29 = F_40 ( V_38 , L_4 ,
& V_44 [ 0 ] , 4 ) ;
if ( V_29 )
goto V_34;
V_39 = F_39 ( NULL , NULL , L_5 ) ;
if ( ! V_39 )
goto V_34;
V_40 = F_39 ( NULL , NULL , L_6 ) ;
if ( ! V_40 )
goto V_34;
V_29 = F_41 ( V_44 [ 0 ] , V_44 [ 1 ] ) ;
if ( V_29 )
goto V_34;
V_43 = F_42 ( V_44 [ 2 ] , V_44 [ 3 ] ) ;
if ( ! V_43 ) {
F_23 ( L_7 ) ;
V_29 = - V_45 ;
goto V_46;
}
V_12 = F_43 ( V_39 , 0 ) ;
if ( ! V_12 ) {
F_23 ( L_8 ) ;
V_29 = - V_45 ;
goto V_47;
}
V_29 = F_44 ( V_40 , 0 , & V_42 ) ;
if ( V_29 ) {
F_23 ( L_9 ) ;
goto V_48;
}
V_49 = V_42 . V_50 ;
F_45 ( & V_49 ) ;
V_7 = F_43 ( V_40 , 0 ) ;
if ( ! V_7 ) {
F_23 ( L_10 ) ;
V_29 = - V_45 ;
goto V_48;
}
if ( ! F_37 () ) {
V_29 = - V_15 ;
goto V_51;
}
V_29 = F_46 ( & V_52 ) ;
if ( V_29 ) {
goto V_51;
}
F_5 ( V_44 [ 0 ] , V_43 ) ;
F_5 ( 0xa5a5a5a5 , V_43 + 4 ) ;
F_5 ( F_47 ( V_53 ) , V_43 + 8 ) ;
F_5 ( 0 , V_43 + 12 ) ;
F_48 ( V_43 ) ;
F_49 ( F_36 ) ;
F_50 () ;
F_51 ( L_11 ) ;
return V_29 ;
V_51:
F_48 ( V_7 ) ;
V_48:
F_48 ( V_12 ) ;
V_47:
F_48 ( V_43 ) ;
V_46:
F_52 ( V_44 [ 0 ] , V_44 [ 1 ] ) ;
V_34:
return V_29 ;
}
