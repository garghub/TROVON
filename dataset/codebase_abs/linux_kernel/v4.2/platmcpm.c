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
static int F_7 ( unsigned int V_9 , struct V_10 * V_11 )
{
unsigned int V_12 , V_13 , V_1 ;
unsigned long V_6 ;
void T_1 * V_14 , * V_15 ;
V_12 = F_8 ( V_9 ) ;
V_13 = F_9 ( V_12 , 0 ) ;
V_1 = F_9 ( V_12 , 1 ) ;
if ( ! V_16 )
return - V_17 ;
if ( V_1 >= V_18 || V_13 >= V_3 )
return - V_19 ;
F_10 ( & V_20 ) ;
if ( V_4 [ V_1 ] [ V_13 ] )
goto V_21;
V_14 = V_16 + F_11 ( V_1 ) ;
V_15 = V_16 + F_12 ( V_1 ) ;
if ( F_1 ( V_1 ) ) {
V_6 = V_22 ;
F_5 ( V_6 , V_14 ) ;
do {
F_6 () ;
V_6 = F_4 ( V_15 ) ;
} while ( V_6 & V_23 );
F_2 ( V_1 , 1 ) ;
}
V_6 = F_13 ( V_13 ) | F_14 ( V_13 ) | \
F_15 ( V_13 ) ;
F_5 ( V_6 , V_14 ) ;
do {
F_6 () ;
} while ( V_6 == F_4 ( V_15 ) );
F_16 ( 20 ) ;
F_17 ( F_18 ( V_9 ) ) ;
V_21:
V_4 [ V_1 ] [ V_13 ] ++ ;
F_19 ( & V_20 ) ;
return 0 ;
}
static void F_20 ( unsigned int V_9 )
{
unsigned int V_12 , V_13 , V_1 ;
bool V_24 ;
V_12 = F_8 ( V_9 ) ;
V_13 = F_9 ( V_12 , 0 ) ;
V_1 = F_9 ( V_12 , 1 ) ;
F_21 ( & V_20 ) ;
V_4 [ V_1 ] [ V_13 ] -- ;
if ( V_4 [ V_1 ] [ V_13 ] == 1 ) {
F_22 ( & V_20 ) ;
return;
} else if ( V_4 [ V_1 ] [ V_13 ] > 1 ) {
F_23 ( L_1 , V_1 , V_13 ) ;
F_3 () ;
}
V_24 = F_1 ( V_1 ) ;
F_22 ( & V_20 ) ;
if ( V_24 ) {
asm volatile(
"mcr p15, 1, %0, c15, c0, 3 \n\t"
"isb \n\t"
"dsb "
: : "r" (0x400) );
F_24 ( V_25 ) ;
} else {
F_24 ( V_26 ) ;
}
for (; ; )
F_25 () ;
}
static int F_26 ( unsigned int V_9 )
{
unsigned int V_12 , V_13 , V_1 ;
unsigned int V_6 , V_27 , V_28 ;
V_12 = F_8 ( V_9 ) ;
V_13 = F_9 ( V_12 , 0 ) ;
V_1 = F_9 ( V_12 , 1 ) ;
F_27 ( V_1 >= V_18 ||
V_13 >= V_3 ) ;
V_28 = V_29 / V_30 ;
F_10 ( & V_20 ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
if ( V_4 [ V_1 ] [ V_13 ] )
goto V_31;
F_6 () ;
V_6 = F_4 ( V_16 + F_12 ( V_1 ) ) ;
if ( V_6 & F_28 ( V_13 ) )
break;
F_19 ( & V_20 ) ;
F_29 ( V_30 ) ;
F_10 ( & V_20 ) ;
}
if ( V_27 >= V_28 )
goto V_31;
V_6 = F_13 ( V_13 ) | F_14 ( V_13 ) | \
F_15 ( V_13 ) ;
F_5 ( V_6 , V_16 + F_30 ( V_1 ) ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
F_6 () ;
V_6 = F_4 ( V_16 + F_12 ( V_1 ) ) ;
if ( V_6 & F_31 ( V_13 ) )
break;
}
if ( V_27 >= V_28 )
goto V_31;
if ( F_1 ( V_1 ) )
F_2 ( V_1 , 0 ) ;
F_19 ( & V_20 ) ;
return 1 ;
V_31:
F_19 ( & V_20 ) ;
return 0 ;
}
static bool T_2 F_32 ( void )
{
unsigned int V_12 , V_13 , V_1 ;
V_12 = F_33 () ;
V_13 = F_9 ( V_12 , 0 ) ;
V_1 = F_9 ( V_12 , 1 ) ;
if ( V_1 >= V_18 ||
V_13 >= V_3 ) {
F_23 ( L_2 , V_32 ) ;
return false ;
}
F_2 ( V_1 , 1 ) ;
V_4 [ V_1 ] [ V_13 ] = 1 ;
return true ;
}
static int T_2 F_34 ( void )
{
struct V_33 * V_34 , * V_35 , * V_36 ;
struct V_37 V_38 ;
void T_1 * V_39 ;
int V_40 = - V_17 ;
V_34 = F_35 ( NULL , NULL , L_3 ) ;
if ( ! V_34 )
goto V_31;
V_40 = F_36 ( V_34 , L_4 ,
& V_41 [ 0 ] , 4 ) ;
if ( V_40 )
goto V_31;
V_35 = F_35 ( NULL , NULL , L_5 ) ;
if ( ! V_35 )
goto V_31;
V_36 = F_35 ( NULL , NULL , L_6 ) ;
if ( ! V_36 )
goto V_31;
V_40 = F_37 ( V_41 [ 0 ] , V_41 [ 1 ] ) ;
if ( V_40 )
goto V_31;
V_39 = F_38 ( V_41 [ 2 ] , V_41 [ 3 ] ) ;
if ( ! V_39 ) {
F_23 ( L_7 ) ;
V_40 = - V_42 ;
goto V_43;
}
V_16 = F_39 ( V_35 , 0 ) ;
if ( ! V_16 ) {
F_23 ( L_8 ) ;
V_40 = - V_42 ;
goto V_44;
}
V_40 = F_40 ( V_36 , 0 , & V_38 ) ;
if ( V_40 ) {
F_23 ( L_9 ) ;
goto V_45;
}
V_46 = V_38 . V_47 ;
F_41 ( & V_46 ) ;
V_7 = F_39 ( V_36 , 0 ) ;
if ( ! V_7 ) {
F_23 ( L_10 ) ;
V_40 = - V_42 ;
goto V_45;
}
if ( ! F_32 () ) {
V_40 = - V_19 ;
goto V_48;
}
F_5 ( V_41 [ 0 ] , V_39 ) ;
F_5 ( 0xa5a5a5a5 , V_39 + 4 ) ;
F_5 ( F_42 ( V_49 ) , V_39 + 8 ) ;
F_5 ( 0 , V_39 + 12 ) ;
F_43 ( V_39 ) ;
F_44 ( & V_50 ) ;
return V_40 ;
V_48:
F_43 ( V_7 ) ;
V_45:
F_43 ( V_16 ) ;
V_44:
F_43 ( V_39 ) ;
V_43:
F_45 ( V_41 [ 0 ] , V_41 [ 1 ] ) ;
V_31:
return V_40 ;
}
