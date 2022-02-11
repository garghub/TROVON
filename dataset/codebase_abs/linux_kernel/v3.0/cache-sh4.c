static void F_1 ( void * args )
{
struct V_1 * V_2 = args ;
unsigned long V_3 , V_4 ;
unsigned long V_5 , V_6 ;
int V_7 ;
V_3 = V_2 -> V_8 ;
V_4 = V_2 -> V_9 ;
if ( ( ( V_4 - V_3 ) >> V_10 ) >= V_11 ) {
F_2 ( NULL ) ;
return;
}
V_3 &= ~ ( V_12 - 1 ) ;
V_4 += V_12 - 1 ;
V_4 &= ~ ( V_12 - 1 ) ;
F_3 ( V_5 ) ;
F_4 () ;
for ( V_6 = V_3 ; V_6 < V_4 ; V_6 += V_12 ) {
unsigned long V_13 ;
int V_14 , V_15 ;
F_5 ( V_6 ) ;
V_13 = V_16 | ( V_6 &
V_17 -> V_18 . V_19 ) ;
V_15 = V_20 . V_18 . V_21 ;
for ( V_7 = 0 ; V_7 < V_17 -> V_18 . V_22 ; V_7 ++ ) {
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
F_6 ( 0 , V_13 + ( V_14 * V_23 ) ) ;
V_13 += V_17 -> V_18 . V_24 ;
}
}
F_7 () ;
F_8 ( V_5 ) ;
}
static inline void F_9 ( unsigned long V_3 , unsigned long V_25 )
{
unsigned long V_5 , V_26 = 0 ;
if ( ( V_20 . V_5 & V_27 ) ||
( V_3 < V_28 ) )
V_26 = V_29 ;
F_3 ( V_5 ) ;
F_10 ( V_3 , V_25 , V_26 ) ;
F_8 ( V_5 ) ;
}
static void F_11 ( void * V_30 )
{
struct V_31 * V_31 = V_30 ;
unsigned long V_32 = ( unsigned long ) F_12 ( V_31 ) ;
#ifndef F_13
struct V_33 * V_34 = F_14 ( V_31 ) ;
if ( V_34 && ! F_15 ( V_34 ) )
F_16 ( V_35 , & V_31 -> V_5 ) ;
else
#endif
F_9 ( V_28 |
( V_32 & V_36 ) , F_17 ( V_31 ) ) ;
F_18 () ;
}
static void F_19 ( void )
{
unsigned long V_5 , V_37 ;
F_3 ( V_5 ) ;
F_4 () ;
V_37 = F_20 ( V_38 ) ;
V_37 |= V_39 ;
F_6 ( V_37 , V_38 ) ;
F_7 () ;
F_8 ( V_5 ) ;
}
static void F_21 ( void )
{
unsigned long V_32 , V_40 , V_41 ;
V_40 = V_28 +
( V_42 . V_43 . V_44 <<
V_42 . V_43 . V_45 ) *
V_42 . V_43 . V_22 ;
V_41 = 1 << V_42 . V_43 . V_45 ;
for ( V_32 = V_28 ; V_32 < V_40 ; ) {
F_6 ( 0 , V_32 ) ; V_32 += V_41 ;
F_6 ( 0 , V_32 ) ; V_32 += V_41 ;
F_6 ( 0 , V_32 ) ; V_32 += V_41 ;
F_6 ( 0 , V_32 ) ; V_32 += V_41 ;
F_6 ( 0 , V_32 ) ; V_32 += V_41 ;
F_6 ( 0 , V_32 ) ; V_32 += V_41 ;
F_6 ( 0 , V_32 ) ; V_32 += V_41 ;
F_6 ( 0 , V_32 ) ; V_32 += V_41 ;
}
}
static void F_22 ( void * V_46 )
{
F_21 () ;
F_19 () ;
}
static void F_23 ( void * V_30 )
{
struct V_47 * V_48 = V_30 ;
if ( F_24 ( F_25 () , V_48 ) == V_49 )
return;
F_21 () ;
}
static void F_26 ( void * args )
{
struct V_1 * V_2 = args ;
struct V_50 * V_51 ;
struct V_31 * V_31 ;
unsigned long V_52 , V_53 , V_25 ;
int V_54 = 0 ;
T_1 * V_55 ;
T_2 * V_56 ;
T_3 * V_57 ;
T_4 * V_58 ;
void * V_59 ;
V_51 = V_2 -> V_51 ;
V_52 = V_2 -> V_8 & V_60 ;
V_53 = V_2 -> V_9 ;
V_25 = V_53 << V_10 ;
V_31 = F_27 ( V_53 ) ;
if ( F_24 ( F_25 () , V_51 -> V_61 ) == V_49 )
return;
V_55 = F_28 ( V_51 -> V_61 , V_52 ) ;
V_56 = F_29 ( V_55 , V_52 ) ;
V_57 = F_30 ( V_56 , V_52 ) ;
V_58 = F_31 ( V_57 , V_52 ) ;
if ( ! ( F_32 ( * V_58 ) & V_62 ) )
return;
if ( ( V_51 -> V_61 == V_63 -> V_64 ) )
V_59 = NULL ;
else {
V_54 = ( V_42 . V_43 . V_21 &&
F_33 ( V_35 , & V_31 -> V_5 ) &&
F_34 ( V_31 ) ) ;
if ( V_54 )
V_59 = F_35 ( V_31 , V_52 ) ;
else
V_59 = F_36 ( V_31 , V_65 ) ;
V_52 = ( unsigned long ) V_59 ;
}
F_9 ( V_28 |
( V_52 & V_36 ) , V_25 ) ;
if ( V_51 -> V_66 & V_67 )
F_19 () ;
if ( V_59 ) {
if ( V_54 )
F_37 ( V_59 ) ;
else
F_38 ( V_59 , V_65 ) ;
}
}
static void F_39 ( void * args )
{
struct V_1 * V_2 = args ;
struct V_50 * V_51 ;
unsigned long V_3 , V_4 ;
V_51 = V_2 -> V_51 ;
V_3 = V_2 -> V_8 ;
V_4 = V_2 -> V_9 ;
if ( F_24 ( F_25 () , V_51 -> V_61 ) == V_49 )
return;
if ( V_20 . V_43 . V_21 == 0 )
return;
F_21 () ;
if ( V_51 -> V_66 & V_67 )
F_19 () ;
}
static void F_10 ( unsigned long V_32 , unsigned long V_25 ,
unsigned long V_26 )
{
int V_68 ;
unsigned long V_69 = V_32 ;
struct V_70 * V_43 ;
unsigned long V_24 ;
unsigned long V_71 , V_72 , V_73 ;
unsigned long V_74 ;
V_43 = & V_20 . V_43 ;
V_68 = V_43 -> V_22 ;
V_24 = V_43 -> V_24 ;
asm volatile("mov.l 1f, %0\n\t"
"add %1, %0\n\t"
"jmp @%0\n\t"
"nop\n\t"
".balign 4\n\t"
"1: .long 2f\n\t"
"2:\n" : "=&r" (temp_pc) : "r" (exec_offset));
do {
V_72 = V_69 + V_23 ;
V_71 = V_69 ;
V_73 = V_25 ;
do {
* ( volatile unsigned long * ) V_71 = V_73 ;
* ( volatile unsigned long * ) ( V_71 + 32 ) = V_73 ;
V_71 += 64 ;
V_73 += 64 ;
} while ( V_71 < V_72 );
V_69 += V_24 ;
} while ( -- V_68 != 0 );
}
void T_5 F_40 ( void )
{
F_41 ( L_1 ,
F_20 ( V_75 ) ,
F_20 ( V_76 ) ,
F_20 ( V_77 ) ) ;
V_78 = F_1 ;
V_79 = F_11 ;
F_2 = F_22 ;
V_80 = F_23 ;
V_81 = F_23 ;
V_82 = F_26 ;
V_83 = F_39 ;
F_42 () ;
}
