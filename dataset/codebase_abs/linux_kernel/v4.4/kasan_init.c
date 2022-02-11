static void T_1 F_1 ( T_2 * V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
T_3 * V_4 ;
unsigned long V_5 ;
if ( F_2 ( * V_1 ) )
F_3 ( & V_6 , V_1 , V_7 ) ;
V_4 = F_4 ( V_1 , V_2 ) ;
do {
V_5 = V_2 + V_8 ;
F_5 ( V_4 , F_6 ( F_7 ( V_9 ) ,
V_10 ) ) ;
} while ( V_4 ++ , V_2 = V_5 , V_2 != V_3 && F_8 ( * V_4 ) );
}
static void T_1 F_9 ( T_4 * V_11 ,
unsigned long V_2 ,
unsigned long V_3 )
{
T_2 * V_1 ;
unsigned long V_5 ;
if ( F_10 ( * V_11 ) )
F_11 ( & V_6 , V_11 , V_12 ) ;
V_1 = F_12 ( V_11 , V_2 ) ;
do {
V_5 = F_13 ( V_2 , V_3 ) ;
F_1 ( V_1 , V_2 , V_5 ) ;
} while ( V_1 ++ , V_2 = V_5 , V_2 != V_3 && F_2 ( * V_1 ) );
}
static void T_1 F_14 ( T_5 * V_13 ,
unsigned long V_2 ,
unsigned long V_3 )
{
T_4 * V_11 ;
unsigned long V_5 ;
if ( F_15 ( * V_13 ) )
F_16 ( & V_6 , V_13 , V_14 ) ;
V_11 = F_17 ( V_13 , V_2 ) ;
do {
V_5 = F_18 ( V_2 , V_3 ) ;
F_9 ( V_11 , V_2 , V_5 ) ;
} while ( V_11 ++ , V_2 = V_5 , V_2 != V_3 && F_10 ( * V_11 ) );
}
static void T_1 F_19 ( void )
{
unsigned long V_2 = V_15 ;
unsigned long V_3 = V_16 ;
unsigned long V_5 ;
T_5 * V_13 ;
V_13 = F_20 ( V_2 ) ;
do {
V_5 = F_21 ( V_2 , V_3 ) ;
F_14 ( V_13 , V_2 , V_5 ) ;
} while ( V_13 ++ , V_2 = V_5 , V_2 != V_3 );
}
T_6 void T_1 F_22 ( void )
{
F_23 ( V_17 != V_16 - ( 1UL << 61 ) ) ;
F_23 ( ! F_24 ( V_15 , V_18 ) ) ;
F_23 ( ! F_24 ( V_16 , V_18 ) ) ;
F_19 () ;
}
static void T_1 F_25 ( unsigned long V_19 ,
unsigned long V_3 )
{
for (; V_19 < V_3 ; V_19 += V_18 )
F_26 ( F_20 ( V_19 ) , F_27 ( 0 ) ) ;
}
static void T_1 F_28 ( unsigned long V_20 )
{
asm(
" msr ttbr1_el1, %0\n"
" isb"
:
: "r" (ttbr1));
}
void T_1 F_29 ( void )
{
struct V_21 * V_22 ;
memcpy ( V_23 , V_24 , sizeof( V_23 ) ) ;
F_28 ( F_30 ( V_23 ) ) ;
F_31 () ;
F_25 ( V_15 , V_16 ) ;
F_32 ( ( void * ) V_15 ,
F_33 ( ( void * ) V_25 ) ) ;
F_34 (memory, reg) {
void * V_19 = ( void * ) F_35 ( V_22 -> V_26 ) ;
void * V_3 = ( void * ) F_35 ( V_22 -> V_26 + V_22 -> V_27 ) ;
if ( V_19 >= V_3 )
break;
F_36 ( ( unsigned long ) F_33 ( V_19 ) ,
( unsigned long ) F_33 ( V_3 ) + 1 ,
F_37 ( F_7 ( V_19 ) ) ) ;
}
memset ( V_9 , 0 , V_8 ) ;
F_28 ( F_30 ( V_24 ) ) ;
F_31 () ;
V_28 . V_29 = 0 ;
F_38 ( L_1 ) ;
}
