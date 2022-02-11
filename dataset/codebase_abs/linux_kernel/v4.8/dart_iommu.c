static inline void F_1 ( void )
{
unsigned long V_1 = 0 ;
unsigned int V_2 , V_3 ;
unsigned long V_4 ;
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
F_3 ( L_1 ) ;
V_4 = 0 ;
V_3 = V_7 ? V_8 : V_9 ;
V_10:
V_1 = 0 ;
V_2 = F_4 ( V_11 ) ;
V_2 |= V_3 ;
F_5 ( V_11 , V_2 ) ;
while ( ( F_4 ( V_11 ) & V_3 ) && V_1 < ( 1L << V_4 ) )
V_1 ++ ;
if ( V_1 == ( 1L << V_4 ) ) {
if ( V_4 < 4 ) {
V_4 ++ ;
V_2 = F_4 ( V_11 ) ;
V_2 &= ~ V_3 ;
F_5 ( V_11 , V_2 ) ;
goto V_10;
} else
F_6 ( L_2
L_3 ) ;
}
F_7 ( & V_6 , V_5 ) ;
}
static inline void F_8 ( unsigned long V_12 )
{
unsigned int V_2 ;
unsigned int V_1 , V_4 ;
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
V_2 = V_13 | V_14 |
( V_12 & V_15 ) ;
F_5 ( V_11 , V_2 ) ;
V_4 = 0 ;
V_16:
V_1 = 0 ;
while ( ( F_4 ( V_11 ) & V_14 ) && V_1 < ( 1L << V_4 ) ) {
F_9 () ;
V_1 ++ ;
}
if ( V_1 == ( 1L << V_4 ) ) {
if ( V_4 < 4 ) {
V_4 ++ ;
goto V_16;
} else
F_6 ( L_2
L_4 ) ;
}
F_7 ( & V_6 , V_5 ) ;
}
static void F_10 ( unsigned int * V_17 , unsigned int V_18 )
{
unsigned long V_19 = ( unsigned long ) V_17 ;
unsigned long V_20 = V_19 + ( V_18 + 1 ) * sizeof( unsigned int ) ;
unsigned int V_21 ;
F_11 ( V_19 , V_20 ) ;
asm volatile(" sync;"
" isync;"
" dcbf 0,%1;"
" sync;"
" isync;"
" lwz %0,0(%1);"
" isync" : "=r" (tmp) : "r" (end) : "memory");
}
static void F_12 ( struct V_22 * V_23 )
{
F_13 () ;
if ( V_24 ) {
F_1 () ;
V_24 = 0 ;
}
}
static int F_14 ( struct V_22 * V_23 , long V_25 ,
long V_26 , unsigned long V_27 ,
enum V_28 V_29 ,
unsigned long V_30 )
{
unsigned int * V_31 , * V_32 ;
unsigned int V_33 ;
long V_1 ;
F_3 ( L_5 , V_25 , V_26 , V_27 ) ;
V_32 = V_31 = ( ( unsigned int * ) V_23 -> V_34 ) + V_25 ;
V_1 = V_26 ;
while ( V_1 -- ) {
V_33 = F_15 ( V_27 ) >> V_35 ;
* ( V_31 ++ ) = V_36 | ( V_33 & V_37 ) ;
V_27 += V_38 ;
}
F_10 ( V_32 , V_26 ) ;
if ( V_7 ) {
V_33 = V_25 ;
while ( V_26 -- )
F_8 ( V_33 ++ ) ;
} else {
V_24 = 1 ;
}
return 0 ;
}
static void F_16 ( struct V_22 * V_23 , long V_25 , long V_26 )
{
unsigned int * V_31 , * V_32 ;
long V_39 = V_26 ;
F_3 ( L_6 , V_25 , V_26 ) ;
V_32 = V_31 = ( ( unsigned int * ) V_23 -> V_34 ) + V_25 ;
while ( V_26 -- )
* ( V_31 ++ ) = V_40 ;
F_10 ( V_32 , V_39 ) ;
}
static void F_17 ( void )
{
unsigned long V_21 ;
V_41 = 1UL << 21 ;
V_42 = F_18 ( F_19 ( 1UL << 24 ,
1UL << 24 , 0x80000000L ) ) ;
F_20 ( ( void * ) V_42 ) ;
V_21 = F_21 ( V_38 , V_38 ) ;
V_40 = V_36 | ( ( V_21 >> V_35 ) &
V_37 ) ;
F_22 ( V_43 L_7 , V_42 ) ;
}
static int T_1 F_23 ( struct V_44 * V_45 )
{
unsigned int V_46 ;
unsigned long V_17 , V_47 ;
struct V_48 V_49 ;
if ( V_50 )
return - V_51 ;
if ( ! V_52 && F_24 () <= 0x40000000ull )
return - V_51 ;
if ( F_25 ( V_45 , 0 , & V_49 ) )
F_6 ( L_8 ) ;
V_53 = F_26 ( V_49 . V_19 , F_27 ( & V_49 ) ) ;
if ( V_53 == NULL )
F_6 ( L_9 ) ;
F_17 () ;
for ( V_46 = 0 ; V_46 < V_41 / 4 ; V_46 ++ )
V_42 [ V_46 ] = V_40 ;
F_10 ( V_42 , V_41 / sizeof( V_54 ) ) ;
V_17 = ( ( unsigned long ) V_42 ) >> V_35 ;
V_47 = V_41 >> V_35 ;
if ( V_7 ) {
V_47 &= V_55 ;
F_5 ( V_56 , V_17 ) ;
F_5 ( V_57 , V_47 ) ;
F_5 ( V_11 , V_13 ) ;
} else {
V_47 &= V_58 ;
F_5 ( V_11 ,
V_59 |
( V_17 << V_60 ) |
( V_47 << V_61 ) ) ;
}
F_1 () ;
F_22 ( V_43 L_10 ,
V_7 ? L_11 : L_12 ) ;
return 0 ;
}
static void F_28 ( void )
{
V_62 . V_63 = 0 ;
V_62 . V_64 = 0 ;
V_62 . V_65 = V_41 / sizeof( V_54 ) ;
V_62 . V_66 = V_67 ;
V_62 . V_34 = ( unsigned long ) V_42 ;
V_62 . V_68 = 0 ;
V_62 . V_69 = 1 ;
V_62 . V_70 = & V_71 ;
F_29 ( & V_62 , - 1 ) ;
F_30 ( V_62 . V_65 - 1 , V_62 . V_72 ) ;
}
static void F_31 ( struct V_73 * V_74 )
{
if ( V_7 )
F_32 ( & V_74 -> V_74 , V_75 ) ;
F_33 ( & V_74 -> V_74 , & V_62 ) ;
}
static void F_34 ( struct V_76 * V_77 )
{
if ( ! V_78 ) {
V_78 = 1 ;
F_28 () ;
}
}
static bool F_35 ( struct V_79 * V_74 )
{
struct V_44 * V_80 = F_36 ( V_74 -> V_81 ) ;
while( V_80 ) {
if ( F_37 ( V_80 , L_13 ) ||
F_37 ( V_80 , L_14 ) ) {
F_38 ( V_80 ) ;
return true ;
}
V_80 = F_39 ( V_80 ) ;
}
return false ;
}
static int F_40 ( struct V_79 * V_74 , T_2 V_82 )
{
if ( ! V_74 -> V_82 || ! F_41 ( V_74 , V_82 ) )
return - V_83 ;
if ( F_35 ( V_74 ) && V_82 >= F_42 ( 40 ) ) {
F_43 ( V_74 , L_15 ) ;
F_44 ( V_74 , & V_84 ) ;
} else {
F_43 ( V_74 , L_16 ) ;
F_44 ( V_74 , & V_85 ) ;
}
* V_74 -> V_82 = V_82 ;
return 0 ;
}
void T_1 F_45 ( struct V_86 * V_87 )
{
struct V_44 * V_88 ;
V_88 = F_46 ( NULL , L_17 , L_18 ) ;
if ( V_88 == NULL ) {
V_88 = F_46 ( NULL , L_17 , L_19 ) ;
if ( V_88 == NULL )
return;
V_7 = 1 ;
}
if ( F_23 ( V_88 ) != 0 )
goto V_89;
if ( V_7 )
V_90 . V_91 = F_40 ;
V_87 -> V_92 = F_31 ;
V_87 -> V_93 = F_34 ;
F_47 ( & V_85 ) ;
return;
V_89:
V_87 -> V_92 = NULL ;
V_87 -> V_93 = NULL ;
F_47 ( & V_84 ) ;
}
static void F_48 ( void )
{
F_10 ( V_42 , V_41 / sizeof( V_54 ) ) ;
F_1 () ;
}
static int T_1 F_49 ( void )
{
if ( ! V_42 )
return 0 ;
V_90 . V_94 = F_48 ;
return 0 ;
}
