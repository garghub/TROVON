static void T_1 F_1 ( void )
{
unsigned long V_1 , V_2 ;
if ( V_3 . V_4 )
F_2 ( L_1 ) ;
V_1 = V_5 ;
V_2 = ( V_5 + V_6 ) ;
while ( V_1 < V_2 ) {
__asm__ __volatile__("sta %%g0, [%0] %1\n\t" : :
"r" (begin), "i" (ASI_CONTROL));
V_1 += V_3 . V_7 ;
}
}
static void F_3 ( void )
{
unsigned long V_2 = V_6 ;
__asm__ __volatile__(
"1: addcc %0, -4096, %0\n\t"
" bne 1b\n\t"
" sta %%g0, [%0] %2"
: "=&r" (end)
: "0" (end), "i" (ASI_HWFLUSHCONTEXT)
: "cc");
}
static void F_4 ( unsigned long V_8 )
{
if ( F_5 ( V_8 ) != V_9 ) {
unsigned long V_10 = V_6 ;
__asm__ __volatile__(
"1: addcc %0, -4096, %0\n\t"
" bne 1b\n\t"
" sta %%g0, [%2 + %0] %3"
: "=&r" (vac_size)
: "0" (vac_size), "r" (addr), "i" (ASI_HWFLUSHSEG)
: "cc");
}
}
static void F_6 ( unsigned long V_8 )
{
V_8 &= V_11 ;
if ( ( int ) F_7 ( V_8 ) < 0 )
__asm__ __volatile__("sta %%g0, [%0] %1"
: : "r" (addr), "i" (ASI_HWFLUSHPAGE));
}
static void F_8 ( void )
{
unsigned long V_12 = V_6 ;
unsigned long V_13 = V_3 . V_7 ;
__asm__ __volatile__(
"add %2, %2, %%g1\n\t"
"add %2, %%g1, %%g2\n\t"
"add %2, %%g2, %%g3\n\t"
"add %2, %%g3, %%g4\n\t"
"add %2, %%g4, %%g5\n\t"
"add %2, %%g5, %%o4\n\t"
"add %2, %%o4, %%o5\n"
"1:\n\t"
"subcc %0, %%o5, %0\n\t"
"sta %%g0, [%0] %3\n\t"
"sta %%g0, [%0 + %2] %3\n\t"
"sta %%g0, [%0 + %%g1] %3\n\t"
"sta %%g0, [%0 + %%g2] %3\n\t"
"sta %%g0, [%0 + %%g3] %3\n\t"
"sta %%g0, [%0 + %%g4] %3\n\t"
"sta %%g0, [%0 + %%g5] %3\n\t"
"bg 1b\n\t"
" sta %%g0, [%1 + %%o4] %3\n"
: "=&r" (nbytes)
: "0" (nbytes), "r" (lsize), "i" (ASI_FLUSHCTX)
: "g1", "g2", "g3", "g4", "g5", "o4", "o5", "cc");
}
static void F_9 ( unsigned long V_8 )
{
if ( F_5 ( V_8 ) != V_9 ) {
unsigned long V_12 = V_6 ;
unsigned long V_13 = V_3 . V_7 ;
__asm__ __volatile__(
"add %2, %2, %%g1\n\t"
"add %2, %%g1, %%g2\n\t"
"add %2, %%g2, %%g3\n\t"
"add %2, %%g3, %%g4\n\t"
"add %2, %%g4, %%g5\n\t"
"add %2, %%g5, %%o4\n\t"
"add %2, %%o4, %%o5\n"
"1:\n\t"
"subcc %1, %%o5, %1\n\t"
"sta %%g0, [%0] %6\n\t"
"sta %%g0, [%0 + %2] %6\n\t"
"sta %%g0, [%0 + %%g1] %6\n\t"
"sta %%g0, [%0 + %%g2] %6\n\t"
"sta %%g0, [%0 + %%g3] %6\n\t"
"sta %%g0, [%0 + %%g4] %6\n\t"
"sta %%g0, [%0 + %%g5] %6\n\t"
"sta %%g0, [%0 + %%o4] %6\n\t"
"bg 1b\n\t"
" add %0, %%o5, %0\n"
: "=&r" (addr), "=&r" (nbytes), "=&r" (lsize)
: "0" (addr), "1" (nbytes), "2" (lsize),
"i" (ASI_FLUSHSEG)
: "g1", "g2", "g3", "g4", "g5", "o4", "o5", "cc");
}
}
static void F_10 ( unsigned long V_8 )
{
V_8 &= V_11 ;
if ( ( F_7 ( V_8 ) & ( V_14 | V_15 ) ) ==
V_15 ) {
unsigned long V_16 = V_17 ;
unsigned long V_13 = V_3 . V_7 ;
__asm__ __volatile__(
"add %2, %2, %%g1\n\t"
"add %2, %%g1, %%g2\n\t"
"add %2, %%g2, %%g3\n\t"
"add %2, %%g3, %%g4\n\t"
"add %2, %%g4, %%g5\n\t"
"add %2, %%g5, %%o4\n\t"
"add %2, %%o4, %%o5\n"
"1:\n\t"
"subcc %1, %%o5, %1\n\t"
"sta %%g0, [%0] %6\n\t"
"sta %%g0, [%0 + %2] %6\n\t"
"sta %%g0, [%0 + %%g1] %6\n\t"
"sta %%g0, [%0 + %%g2] %6\n\t"
"sta %%g0, [%0 + %%g3] %6\n\t"
"sta %%g0, [%0 + %%g4] %6\n\t"
"sta %%g0, [%0 + %%g5] %6\n\t"
"sta %%g0, [%0 + %%o4] %6\n\t"
"bg 1b\n\t"
" add %0, %%o5, %0\n"
: "=&r" (addr), "=&r" (left), "=&r" (lsize)
: "0" (addr), "1" (left), "2" (lsize),
"i" (ASI_FLUSHPG)
: "g1", "g2", "g3", "g4", "g5", "o4", "o5", "cc");
}
}
void F_11 ( void )
{
volatile int V_18 ;
V_18 = F_12 () ;
F_13 ( V_18 ) ;
V_18 = F_14 () ;
}
static inline void F_15 ( unsigned char V_19 )
{
unsigned long V_20 ;
F_16 ( 0 , V_19 ) ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 += V_17 )
F_17 ( V_20 , 0 ) ;
F_16 ( 0 , V_9 ) ;
}
static inline void F_18 ( unsigned long V_22 )
{
unsigned long V_20 ;
unsigned char V_23 , V_24 ;
V_23 = F_12 () ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
F_13 ( V_24 ) ;
for ( V_20 = 0 ; V_20 < 0x20000000 ; V_20 += V_21 )
F_16 ( V_20 , V_9 ) ;
for ( V_20 = 0xe0000000 ; V_20 < V_26 ; V_20 += V_21 )
F_16 ( V_20 , V_9 ) ;
for ( V_20 = V_22 ; V_20 < V_27 ; V_20 += V_21 )
F_16 ( V_20 , V_9 ) ;
for ( V_20 = V_28 ; V_20 ; V_20 += V_21 )
F_16 ( V_20 , V_9 ) ;
}
F_13 ( V_23 ) ;
}
void T_1 F_19 ( void )
{
F_20 () ;
if ( ( V_29 -> V_30 == ( V_31 | V_32 ) ) ||
( V_29 -> V_30 == ( V_31 | V_33 ) ) ) {
V_3 . V_34 = 65536 ;
V_3 . V_7 = 16 ;
} else {
V_3 . V_34 =
F_21 ( V_35 , L_2 , 65536 ) ;
V_3 . V_7 =
F_21 ( V_35 , L_3 , 16 ) ;
}
V_3 . V_36 =
F_21 ( V_35 , L_4 , 0 ) ;
if ( V_3 . V_36 == 0 )
V_3 . V_36 =
F_21 ( V_35 , L_5 , 0 ) ;
if ( V_3 . V_34 != 65536 ) {
F_22 ( L_6
L_7 ) ;
F_23 () ;
}
switch ( V_3 . V_7 ) {
case 16 :
V_3 . V_37 = 4 ;
break;
case 32 :
V_3 . V_37 = 5 ;
break;
default:
F_22 ( L_8 ,
V_3 . V_7 ) ;
F_23 () ;
}
F_1 () ;
F_24 () ;
}
static void T_1 F_25 ( void )
{
unsigned long * V_38 , * V_39 ;
switch ( V_40 ) {
case 128 :
break;
case 256 :
F_26 ( V_41 ,
V_42 ) ;
F_26 ( V_43 ,
V_44 ) ;
break;
case 512 :
F_26 ( V_45 ,
V_42 ) ;
F_26 ( V_46 ,
V_44 ) ;
break;
default:
F_22 ( L_9 ,
V_40 ) ;
F_23 () ;
}
switch ( V_25 ) {
case 8 :
break;
case 16 :
F_26 ( V_47 ,
V_48 ) ;
break;
default:
F_22 ( L_10 ,
V_25 ) ;
F_23 () ;
}
if ( V_3 . V_36 != 0 ) {
F_26 ( V_49 , V_50 ) ;
F_26 ( V_51 , V_52 ) ;
} else {
switch ( V_3 . V_7 ) {
case 16 :
break;
case 32 :
F_26 ( V_53 , V_54 ) ;
break;
default:
F_22 ( L_11 ,
V_3 . V_7 ) ;
F_23 () ;
}
}
}
static void T_1 F_27 ( void )
{
if ( ( V_29 -> V_30 == ( V_31 | V_32 ) ) ||
( V_29 -> V_30 == ( V_31 | V_33 ) ) ) {
V_40 = 128 ;
V_25 = 8 ;
} else {
V_40 =
F_21 ( V_35 , L_12 , 128 ) ;
V_25 =
F_21 ( V_35 , L_13 , 0x8 ) ;
}
F_25 () ;
}
void T_1 F_28 ( void )
{
T_2 V_55 ;
struct V_56 V_57 [ 1 ] ;
V_55 = F_29 ( V_35 ) ;
V_55 = F_30 ( V_35 , L_14 ) ;
if ( ! V_55 )
return;
if ( F_31 ( V_55 , L_15 , ( char * ) V_57 , sizeof( V_57 ) ) <= 0 )
return;
V_58 = F_32 ( V_57 [ 0 ] . V_59 , V_57 [ 0 ] . V_60 ) ;
}
static inline void F_33 ( void )
{
if ( ( V_29 -> V_30 == ( V_31 | V_61 ) ) ||
( V_29 -> V_30 == ( V_31 | V_62 ) ) ||
( V_29 -> V_30 == ( V_31 | V_63 ) ) ) {
F_34 ( L_16 ) ;
F_35 ( ( unsigned int ) & V_64 ) ;
F_17 ( ( ( unsigned long ) & V_64 ) ,
( F_7 ( ( unsigned long ) & V_64 ) | V_14 ) ) ;
}
}
static int F_36 ( struct V_65 * V_66 , T_3 * V_67 , unsigned long V_68 ,
unsigned long V_8 , int V_69 )
{
unsigned long V_70 , V_2 ;
* V_67 = V_8 ;
V_2 = F_37 ( ( V_8 + V_69 ) ) ;
while ( V_8 < V_2 ) {
V_70 = V_68 ;
F_35 ( V_70 ) ;
V_70 -= V_71 ;
V_70 >>= V_72 ;
V_70 |= ( V_15 | V_73 |
V_14 | V_74 ) ;
F_17 ( V_8 , V_70 ) ;
V_8 += V_17 ;
V_68 += V_17 ;
}
return 0 ;
}
static void F_38 ( struct V_65 * V_66 , unsigned long V_75 , int V_69 )
{
}
static void T_1 F_39 ( void )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ ) {
V_78 [ V_76 ] . V_19 = V_76 ;
V_78 [ V_76 ] . V_79 = NULL ;
V_78 [ V_76 ] . V_80 = NULL ;
V_78 [ V_76 ] . V_20 = 0 ;
V_78 [ V_76 ] . V_81 = 0 ;
V_78 [ V_76 ] . V_24 = 0 ;
V_78 [ V_76 ] . V_82 = NULL ;
V_78 [ V_76 ] . V_83 = NULL ;
}
V_78 [ V_9 ] . V_81 = 1 ;
}
static inline void F_40 ( unsigned long V_20 , unsigned long V_84 ,
unsigned long V_85 )
{
unsigned long V_86 , V_2 ;
V_2 = V_20 + V_21 ;
for ( V_86 = V_20 ; V_86 < V_2 ; V_86 += V_17 )
if ( F_7 ( V_86 ) & V_15 )
F_17 ( V_86 , ( F_7 ( V_86 ) | V_84 ) &
~ V_85 ) ;
}
static inline void F_41 ( unsigned long V_22 )
{
unsigned long V_20 ;
unsigned char V_19 , V_24 ;
for ( V_20 = V_27 ;
V_20 < V_28 ;
V_20 += V_21 ) {
V_19 = F_5 ( V_20 ) ;
if ( V_19 != V_9 ) {
V_78 [ V_19 ] . V_81 = 1 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ )
F_42 ( V_24 , V_20 , V_19 ) ;
F_40 ( V_20 , V_74 , 0 ) ;
}
}
for ( V_20 = V_26 ; V_20 < V_22 ; V_20 += V_21 ) {
V_19 = F_5 ( V_20 ) ;
V_78 [ V_19 ] . V_81 = 1 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ )
F_42 ( V_24 , V_20 , V_19 ) ;
F_40 ( V_20 , V_74 , V_14 ) ;
}
}
static void T_1 F_43 ( unsigned long V_86 , unsigned long V_2 )
{
int V_76 , V_24 ;
while ( V_86 < V_2 ) {
for ( V_76 = 0 ; V_76 < V_9 ; V_76 ++ )
if ( ! V_78 [ V_76 ] . V_81 )
break;
V_78 [ V_76 ] . V_81 = 1 ;
F_15 ( V_76 ) ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ )
F_42 ( V_24 , V_86 , V_78 [ V_76 ] . V_19 ) ;
V_86 += V_21 ;
}
}
static inline void F_44 ( void )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_87 ; V_76 ++ ) {
V_88 [ V_76 ] . V_89 . V_79 =
V_88 [ V_76 ] . V_89 . V_80 =
& V_88 [ V_76 ] . V_89 ;
V_88 [ V_76 ] . V_90 = 0 ;
}
V_91 . V_89 . V_79 = V_91 . V_89 . V_80 =
& V_91 . V_89 ;
V_91 . V_90 = 0 ;
V_92 . V_89 . V_82 = V_92 . V_89 . V_83 =
& V_92 . V_89 ;
V_92 . V_90 = 0 ;
V_93 . V_89 . V_79 = V_93 . V_89 . V_80 =
& V_93 . V_89 ;
V_93 . V_90 = 0 ;
V_94 . V_89 . V_79 = V_94 . V_89 . V_80 =
& V_94 . V_89 ;
V_94 . V_90 = 0 ;
}
static void F_45 ( struct V_95 * V_96 ,
struct V_97 * V_98 )
{
struct V_97 * V_99 = & V_96 -> V_89 ;
V_98 -> V_80 = V_99 ;
( V_98 -> V_79 = V_99 -> V_79 ) -> V_80 = V_98 ;
V_99 -> V_79 = V_98 ;
V_96 -> V_90 ++ ;
}
static inline void F_46 ( struct V_97 * V_98 )
{
struct V_95 * V_96 = & V_92 ;
struct V_97 * V_99 = & V_96 -> V_89 ;
V_98 -> V_82 = V_99 ;
( V_98 -> V_83 = V_99 -> V_83 ) -> V_82 = V_98 ;
V_99 -> V_83 = V_98 ;
}
static void F_47 ( struct V_95 * V_96 ,
struct V_97 * V_98 )
{
struct V_97 * V_99 = & V_96 -> V_89 ;
unsigned long V_8 = V_98 -> V_20 ;
while ( ( V_99 -> V_79 != & V_96 -> V_89 ) && ( V_99 -> V_79 -> V_20 < V_8 ) )
V_99 = V_99 -> V_79 ;
V_98 -> V_80 = V_99 ;
( V_98 -> V_79 = V_99 -> V_79 ) -> V_80 = V_98 ;
V_99 -> V_79 = V_98 ;
V_96 -> V_90 ++ ;
F_46 ( V_98 ) ;
}
static inline void F_48 ( struct V_95 * V_96 ,
struct V_97 * V_98 )
{
struct V_97 * V_79 = V_98 -> V_79 ;
( V_79 -> V_80 = V_98 -> V_80 ) -> V_79 = V_79 ;
V_96 -> V_90 -- ;
}
static void F_49 ( struct V_97 * V_98 )
{
struct V_97 * V_79 = V_98 -> V_82 ;
( V_79 -> V_83 = V_98 -> V_83 ) -> V_82 = V_79 ;
}
static void F_50 ( int V_24 , struct V_97 * V_98 )
{
F_48 ( V_88 + V_24 , V_98 ) ;
F_49 ( V_98 ) ;
F_45 ( & V_91 , V_98 ) ;
}
static void F_51 ( struct V_97 * V_98 ,
struct V_95 * V_96 )
{
F_48 ( V_96 , V_98 ) ;
F_45 ( & V_94 , V_98 ) ;
}
static void T_1 F_52 ( int V_100 )
{
int V_76 ;
while ( V_100 ) {
for ( V_76 = 0 ; V_76 < V_9 ; V_76 ++ )
if ( ! V_78 [ V_76 ] . V_81 )
break;
V_78 [ V_76 ] . V_81 = 1 ;
F_15 ( V_76 ) ;
F_45 ( & V_94 , & V_78 [ V_76 ] ) ;
V_100 -- ;
}
}
static void T_1 F_53 ( void )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_9 ; V_76 ++ ) {
if ( V_78 [ V_76 ] . V_81 )
continue;
F_15 ( V_76 ) ;
F_45 ( & V_91 , & V_78 [ V_76 ] ) ;
}
}
static void F_54 ( struct V_97 * V_101 )
{
int V_23 , V_24 ;
V_23 = F_12 () ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
F_13 ( V_24 ) ;
F_16 ( V_101 -> V_20 , V_9 ) ;
}
F_13 ( V_23 ) ;
}
static void F_55 ( struct V_97 * V_101 )
{
int V_23 , V_24 ;
V_23 = F_12 () ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
F_13 ( V_24 ) ;
F_16 ( V_101 -> V_20 , V_101 -> V_19 ) ;
}
F_13 ( V_23 ) ;
}
static void F_56 ( struct V_95 * V_102 , unsigned char V_24 )
{
struct V_97 * V_99 = & V_102 -> V_89 ;
unsigned long V_103 ;
F_57 ( V_103 ) ;
if ( V_99 -> V_79 != V_99 ) {
struct V_97 * V_98 = V_99 -> V_79 ;
int V_23 = F_12 () ;
F_58 () ;
F_13 ( V_24 ) ;
F_59 () ;
do {
struct V_97 * V_79 = V_98 -> V_79 ;
F_60 ( V_98 ) ;
F_50 ( V_24 , V_98 ) ;
V_98 = V_79 ;
} while ( V_98 != V_99 );
F_13 ( V_23 ) ;
}
F_61 ( V_103 ) ;
}
static struct V_97 * F_62 ( void )
{
struct V_97 * V_104 ;
if ( V_94 . V_90 ) {
V_104 = V_94 . V_89 . V_79 ;
return V_104 ;
}
V_104 = V_93 . V_89 . V_80 ;
F_63 ( V_104 -> V_20 ) ;
F_54 ( V_104 ) ;
F_51 ( V_104 , & V_93 ) ;
V_104 = V_94 . V_89 . V_79 ;
return V_104 ;
}
static struct V_97 * F_64 ( void )
{
struct V_97 * V_98 ;
unsigned char V_24 ;
int V_23 ;
if ( V_91 . V_90 ) {
V_98 = V_91 . V_89 . V_79 ;
goto V_105;
}
if ( V_106 ) {
V_98 = F_62 () ;
V_106 -- ;
goto V_107;
}
V_98 = V_92 . V_89 . V_82 ;
V_24 = V_98 -> V_24 ;
V_23 = F_12 () ;
F_58 () ;
F_13 ( V_24 ) ;
F_63 ( V_98 -> V_20 ) ;
F_60 ( V_98 ) ;
F_48 ( V_88 + V_24 , V_98 ) ;
F_49 ( V_98 ) ;
F_13 ( V_23 ) ;
return V_98 ;
V_105:
F_48 ( & V_91 , V_98 ) ;
return V_98 ;
V_107:
F_48 ( & V_94 , V_98 ) ;
return V_98 ;
}
void F_65 ( void )
{
struct V_97 * V_98 ;
if ( V_106 >= V_108 )
return;
if ( V_91 . V_90 ) {
V_98 = V_91 . V_89 . V_79 ;
F_48 ( & V_91 , V_98 ) ;
F_45 ( & V_94 , V_98 ) ;
V_106 ++ ;
}
}
static void F_66 ( unsigned long V_8 )
{
struct V_97 * V_109 ;
unsigned long V_103 ;
F_57 ( V_103 ) ;
V_8 &= V_110 ;
V_109 = F_64 () ;
V_108 -- ;
V_109 -> V_20 = V_8 ;
F_58 () ;
F_55 ( V_109 ) ;
F_61 ( V_103 ) ;
}
static void F_67 ( unsigned long V_8 )
{
struct V_97 * V_98 ;
unsigned long V_103 ;
unsigned char V_19 ;
F_57 ( V_103 ) ;
V_8 &= V_110 ;
V_19 = F_5 ( V_8 ) ;
V_98 = & V_78 [ V_19 ] ;
F_58 () ;
F_63 ( V_8 ) ;
F_54 ( V_98 ) ;
F_45 ( & V_91 , V_98 ) ;
V_108 ++ ;
F_61 ( V_103 ) ;
}
static inline void F_68 ( int V_98 )
{
int V_86 , V_2 ;
V_98 &= ~ 31 ;
V_86 = V_98 ;
for ( V_2 = ( V_86 + 32 ) ; V_86 < V_2 ; V_86 ++ )
if ( V_111 [ V_86 ] != V_112 )
return;
F_67 ( F_69 ( V_98 ) ) ;
}
static struct V_113 * F_70 ( int V_55 )
{
unsigned long V_8 , V_114 ;
int V_98 ;
V_114 = F_71 ( V_115 , V_116 ) ;
if ( ! V_114 )
return NULL ;
for ( V_98 = V_117 ; V_98 < V_118 ; V_98 ++ )
if ( V_111 [ V_98 ] == V_112 )
break;
if ( V_98 == V_118 ) {
F_72 ( V_114 , V_116 ) ;
return NULL ;
}
if ( V_98 >= V_117 )
V_117 = V_98 + 1 ;
V_8 = F_69 ( V_98 ) ;
V_111 [ V_98 ] = (union V_119 * ) V_8 ;
if( F_5 ( V_8 ) == V_9 )
F_66 ( V_8 ) ;
F_35 ( V_114 ) ;
F_35 ( V_114 + V_17 ) ;
F_17 ( V_8 , F_73 ( V_114 ) ) ;
F_17 ( V_8 + V_17 , F_73 ( V_114 + V_17 ) ) ;
#ifdef F_74
memset ( ( void * ) V_8 , 0 , V_17 << V_116 ) ;
#endif
return (struct V_113 * ) V_8 ;
}
static void F_75 ( struct V_113 * V_120 )
{
unsigned long V_121 = ( unsigned long ) V_120 ;
unsigned long V_114 = F_76 ( F_7 ( V_121 ) ) ;
int V_98 = F_77 ( V_121 ) ;
F_35 ( V_121 ) ;
F_35 ( V_121 + V_17 ) ;
F_17 ( V_121 , 0 ) ;
F_17 ( V_121 + V_17 , 0 ) ;
V_111 [ V_98 ] = V_112 ;
if ( V_98 < V_117 )
V_117 = V_98 ;
F_72 ( V_114 , V_116 ) ;
F_68 ( V_98 ) ;
}
static void T_1 F_78 ( void )
{
int V_98 ;
if ( sizeof( union V_122 ) != ( V_17 << V_116 ) ) {
extern void V_123 ( void ) ;
V_123 () ;
}
for ( V_98 = 0 ; V_98 < V_118 ; V_98 ++ )
V_111 [ V_98 ] = V_112 ;
V_117 = 0 ;
}
static char * F_79 ( char * V_20 , unsigned long V_124 )
{
unsigned long V_125 , V_126 ;
unsigned long V_127 ;
unsigned long V_128 ;
unsigned long V_129 ;
unsigned long V_130 ;
unsigned long V_131 ;
unsigned long V_103 ;
V_127 = ( ( ( unsigned long ) V_20 & ~ V_11 ) +
V_124 + ( V_17 - 1 ) ) >> V_72 ;
F_57 ( V_103 ) ;
V_125 = F_80 ( V_132 , V_133 ,
0 , V_127 , 0 ) ;
if ( V_125 >= V_133 )
goto V_134;
V_131 = ( ( V_125 + V_127 ) << V_72 ) + V_135 ;
V_131 = F_81 ( V_131 ) ;
while ( V_131 > V_136 ) {
F_66 ( V_136 ) ;
V_136 += V_21 ;
}
V_128 = ( ( unsigned long ) V_20 ) & V_11 ;
for ( V_126 = V_125 ; V_126 < V_125 + V_127 ; V_126 ++ ) {
V_129 = ( ( V_128 - V_71 ) >> V_72 ) ;
V_129 |= F_82 ( V_137 ) ;
V_129 |= V_14 ;
F_83 ( V_126 , V_132 ) ;
V_130 = ( V_126 << V_72 ) + V_135 ;
F_35 ( V_128 ) ;
F_17 ( V_130 , V_129 ) ;
V_128 += V_17 ;
}
F_61 ( V_103 ) ;
return ( char * ) ( ( V_125 << V_72 ) + V_135 +
( ( ( unsigned long ) V_20 ) & ~ V_11 ) ) ;
V_134:
F_61 ( V_103 ) ;
F_34 ( L_17 , V_20 , V_124 ) ;
F_2 ( L_18 ) ;
return NULL ;
}
static void F_84 ( char * V_20 , unsigned long V_124 )
{
unsigned long V_128 , V_127 ;
unsigned long V_103 ;
int V_126 , V_131 ;
V_128 = ( unsigned long ) V_20 & V_11 ;
V_127 = ( ( ( unsigned long ) V_20 & ~ V_11 ) +
V_124 + ( V_17 - 1 ) ) >> V_72 ;
F_57 ( V_103 ) ;
while ( V_127 != 0 ) {
-- V_127 ;
F_17 ( V_128 , 0 ) ;
F_85 ( ( V_128 - V_135 ) >> V_72 ,
V_132 ) ;
V_128 += V_17 ;
}
V_126 = ( V_136 - V_135 ) >> V_72 ;
while ( V_126 >= 0 && ! V_132 [ V_126 >> 5 ] )
V_126 -= 32 ;
V_126 += 32 ;
V_131 = V_135 + ( V_126 << V_72 ) ;
V_131 = F_81 ( V_131 ) + V_21 ;
while ( V_131 < V_136 ) {
V_136 -= V_21 ;
F_67 ( V_136 ) ;
}
F_61 ( V_103 ) ;
}
static T_4 F_86 ( struct V_65 * V_66 , char * V_138 , unsigned long V_69 )
{
unsigned long V_70 ;
V_70 = ( ( unsigned long ) V_138 ) & V_11 ;
if ( ! F_87 ( V_70 ) ) {
F_35 ( V_70 ) ;
return ( T_4 ) V_138 ;
}
return ( T_4 ) F_79 ( V_138 , V_69 ) ;
}
static void F_88 ( struct V_65 * V_66 , struct V_139 * V_140 , int V_141 )
{
while ( V_141 != 0 ) {
-- V_141 ;
V_140 -> V_142 = ( T_4 ) F_79 ( F_89 ( V_140 ) , V_140 -> V_143 ) ;
V_140 -> V_144 = V_140 -> V_143 ;
V_140 = F_90 ( V_140 ) ;
}
}
static void F_91 ( struct V_65 * V_66 , T_4 V_138 , unsigned long V_69 )
{
if ( V_138 < V_135 )
return;
F_84 ( ( char * ) V_138 , V_69 ) ;
}
static void F_92 ( struct V_65 * V_66 , struct V_139 * V_140 , int V_141 )
{
while ( V_141 != 0 ) {
-- V_141 ;
F_84 ( ( char * ) V_140 -> V_142 , V_140 -> V_143 ) ;
V_140 = F_90 ( V_140 ) ;
}
}
static void T_1 F_93 ( void )
{
unsigned long V_145 ;
unsigned long V_146 ;
int V_147 ;
F_78 () ;
V_145 = V_148 ;
V_146 = ( V_145 +
( V_149 * V_118 ) ) ;
if ( V_146 >= V_150 ) {
F_22 ( L_19 ) ;
F_23 () ;
}
V_135 = V_136 =
F_81 ( V_146 ) ;
V_151 = V_150 ;
V_147 = ( V_151 - V_135 ) >> V_72 ;
V_147 = ( V_147 + 7 ) >> 3 ;
V_147 = F_94 ( V_147 ) ;
V_133 = V_147 << 3 ;
V_132 = F_95 ( V_147 , V_152 , 0UL ) ;
memset ( ( void * ) V_132 , 0 , V_147 ) ;
V_153 . V_154 = & V_155 ;
V_153 . V_156 = V_145 ;
V_153 . V_157 = V_146 ;
V_153 . V_158 = V_159 ;
V_153 . V_160 = V_161 | V_162 | V_163 ;
F_96 ( & V_155 , & V_153 ) ;
}
static void F_97 ( void )
{
unsigned long V_1 , V_2 ;
F_58 () ;
V_1 = ( V_26 + V_21 ) ;
V_2 = ( V_1 + V_6 ) ;
if ( V_3 . V_7 == 32 ) {
while ( V_1 < V_2 ) {
__asm__ __volatile__(
"ld [%0 + 0x00], %%g0\n\t"
"ld [%0 + 0x20], %%g0\n\t"
"ld [%0 + 0x40], %%g0\n\t"
"ld [%0 + 0x60], %%g0\n\t"
"ld [%0 + 0x80], %%g0\n\t"
"ld [%0 + 0xa0], %%g0\n\t"
"ld [%0 + 0xc0], %%g0\n\t"
"ld [%0 + 0xe0], %%g0\n\t"
"ld [%0 + 0x100], %%g0\n\t"
"ld [%0 + 0x120], %%g0\n\t"
"ld [%0 + 0x140], %%g0\n\t"
"ld [%0 + 0x160], %%g0\n\t"
"ld [%0 + 0x180], %%g0\n\t"
"ld [%0 + 0x1a0], %%g0\n\t"
"ld [%0 + 0x1c0], %%g0\n\t"
"ld [%0 + 0x1e0], %%g0\n"
: : "r" (begin));
V_1 += 512 ;
}
} else {
while ( V_1 < V_2 ) {
__asm__ __volatile__(
"ld [%0 + 0x00], %%g0\n\t"
"ld [%0 + 0x10], %%g0\n\t"
"ld [%0 + 0x20], %%g0\n\t"
"ld [%0 + 0x30], %%g0\n\t"
"ld [%0 + 0x40], %%g0\n\t"
"ld [%0 + 0x50], %%g0\n\t"
"ld [%0 + 0x60], %%g0\n\t"
"ld [%0 + 0x70], %%g0\n\t"
"ld [%0 + 0x80], %%g0\n\t"
"ld [%0 + 0x90], %%g0\n\t"
"ld [%0 + 0xa0], %%g0\n\t"
"ld [%0 + 0xb0], %%g0\n\t"
"ld [%0 + 0xc0], %%g0\n\t"
"ld [%0 + 0xd0], %%g0\n\t"
"ld [%0 + 0xe0], %%g0\n\t"
"ld [%0 + 0xf0], %%g0\n"
: : "r" (begin));
V_1 += 256 ;
}
}
}
static void F_98 ( struct V_164 * V_165 )
{
int V_166 = V_165 -> V_167 ;
if ( V_166 != V_168 ) {
F_58 () ;
if ( V_88 [ V_166 ] . V_90 ) {
struct V_97 * V_99 = & V_88 [ V_166 ] . V_89 ;
unsigned long V_103 ;
F_57 ( V_103 ) ;
if ( V_99 -> V_79 != V_99 ) {
struct V_97 * V_98 = V_99 -> V_79 ;
int V_23 = F_12 () ;
F_13 ( V_166 ) ;
F_59 () ;
do {
struct V_97 * V_79 = V_98 -> V_79 ;
F_60 ( V_98 ) ;
F_50 ( V_166 , V_98 ) ;
V_98 = V_79 ;
} while ( V_98 != V_99 );
F_13 ( V_23 ) ;
}
F_61 ( V_103 ) ;
}
}
}
static void F_99 ( struct V_169 * V_170 , unsigned long V_86 , unsigned long V_2 )
{
struct V_164 * V_165 = V_170 -> V_154 ;
int V_166 = V_165 -> V_167 ;
if ( V_166 != V_168 ) {
struct V_97 * V_99 = & V_88 [ V_166 ] . V_89 ;
struct V_97 * V_98 ;
unsigned long V_103 ;
F_58 () ;
F_57 ( V_103 ) ;
for ( V_98 = V_99 -> V_79 ;
( V_98 != V_99 ) && ( ( V_98 -> V_20 + V_21 ) < V_86 ) ;
V_98 = V_98 -> V_79 )
;
if ( ( V_98 != V_99 ) && ( V_98 -> V_20 < V_2 ) ) {
int V_171 = F_12 () ;
F_13 ( V_166 ) ;
do {
struct V_97 * V_79 = V_98 -> V_79 ;
unsigned long V_172 ;
V_172 = V_98 -> V_20 + V_21 ;
if ( V_2 < V_172 )
V_172 = V_2 ;
if ( ( V_172 - V_98 -> V_20 ) <= ( V_17 << 3 ) ) {
unsigned long V_70 = V_98 -> V_20 ;
while ( V_70 < V_172 ) {
F_35 ( V_70 ) ;
V_70 += V_17 ;
}
} else {
F_63 ( V_98 -> V_20 ) ;
F_60 ( V_98 ) ;
F_50 ( V_166 , V_98 ) ;
}
V_98 = V_79 ;
} while ( ( V_98 != V_99 ) && ( V_98 -> V_20 < V_2 ) );
F_13 ( V_171 ) ;
}
F_61 ( V_103 ) ;
}
}
static void F_100 ( struct V_169 * V_170 , unsigned long V_70 )
{
struct V_164 * V_165 = V_170 -> V_154 ;
int V_166 = V_165 -> V_167 ;
if ( V_166 != V_168 ) {
int V_171 = F_12 () ;
unsigned long V_103 ;
F_58 () ;
F_57 ( V_103 ) ;
F_13 ( V_166 ) ;
F_35 ( V_70 ) ;
F_13 ( V_171 ) ;
F_61 ( V_103 ) ;
}
}
static void F_101 ( unsigned long V_70 )
{
unsigned long V_103 ;
F_57 ( V_103 ) ;
F_35 ( V_70 ) ;
F_61 ( V_103 ) ;
}
static void F_102 ( struct V_164 * V_165 , unsigned long V_173 )
{
}
static void F_103 ( void )
{
struct V_97 * V_104 , * V_174 ;
unsigned long V_103 ;
int V_23 , V_24 ;
F_57 ( V_103 ) ;
V_104 = V_93 . V_89 . V_79 ;
V_23 = F_12 () ;
F_58 () ;
while ( V_93 . V_90 ) {
V_174 = V_104 -> V_79 ;
F_63 ( V_104 -> V_20 ) ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
F_13 ( V_24 ) ;
F_16 ( V_104 -> V_20 , V_9 ) ;
}
F_51 ( V_104 , & V_93 ) ;
V_104 = V_174 ;
}
F_13 ( V_23 ) ;
F_61 ( V_103 ) ;
}
static void F_104 ( struct V_164 * V_165 )
{
int V_166 = V_165 -> V_167 ;
if ( V_166 != V_168 ) {
struct V_97 * V_99 = & V_88 [ V_166 ] . V_89 ;
unsigned long V_103 ;
F_57 ( V_103 ) ;
if ( V_99 -> V_79 != V_99 ) {
struct V_97 * V_98 = V_99 -> V_79 ;
int V_23 = F_12 () ;
F_13 ( V_166 ) ;
F_59 () ;
do {
struct V_97 * V_79 = V_98 -> V_79 ;
F_60 ( V_98 ) ;
F_50 ( V_166 , V_98 ) ;
V_98 = V_79 ;
} while ( V_98 != V_99 );
F_13 ( V_23 ) ;
}
F_61 ( V_103 ) ;
}
}
static void F_105 ( struct V_169 * V_170 , unsigned long V_86 , unsigned long V_2 )
{
struct V_164 * V_165 = V_170 -> V_154 ;
int V_166 = V_165 -> V_167 ;
if ( V_166 != V_168 ) {
struct V_97 * V_99 = & V_88 [ V_166 ] . V_89 ;
struct V_97 * V_98 ;
unsigned long V_103 ;
F_57 ( V_103 ) ;
for ( V_98 = V_99 -> V_79 ;
( V_98 != V_99 ) && ( ( V_98 -> V_20 + V_21 ) < V_86 ) ;
V_98 = V_98 -> V_79 )
;
if ( ( V_98 != V_99 ) && ( V_98 -> V_20 < V_2 ) ) {
int V_171 = F_12 () ;
F_13 ( V_166 ) ;
do {
struct V_97 * V_79 = V_98 -> V_79 ;
F_63 ( V_98 -> V_20 ) ;
F_60 ( V_98 ) ;
F_50 ( V_166 , V_98 ) ;
V_98 = V_79 ;
} while ( ( V_98 != V_99 ) && ( V_98 -> V_20 < V_2 ) );
F_13 ( V_171 ) ;
}
F_61 ( V_103 ) ;
}
}
static void F_106 ( struct V_169 * V_170 , unsigned long V_70 )
{
struct V_164 * V_165 = V_170 -> V_154 ;
int V_166 = V_165 -> V_167 ;
if ( V_166 != V_168 ) {
int V_23 = F_12 () ;
unsigned long V_103 ;
F_57 ( V_103 ) ;
F_13 ( V_166 ) ;
V_70 &= V_11 ;
F_35 ( V_70 ) ;
F_17 ( V_70 , 0 ) ;
F_13 ( V_23 ) ;
F_61 ( V_103 ) ;
}
}
static inline void F_107 ( unsigned long V_175 , unsigned long V_176 )
{
unsigned long V_177 , V_178 ;
V_178 = V_179 | V_180 | V_181 |
V_182 | V_14 ;
V_177 = ( ( V_175 >> V_72 ) & V_183 ) ;
V_177 |= ( ( V_178 | V_74 ) & ~ ( V_179 ) ) ;
F_17 ( V_176 , V_177 ) ;
}
static void F_108 ( unsigned int V_184 , unsigned long V_185 ,
unsigned long V_186 , unsigned int V_69 )
{
while ( V_69 != 0 ) {
V_69 -= V_17 ;
F_107 ( V_185 , V_186 ) ;
V_186 += V_17 ;
V_185 += V_17 ;
}
}
static void F_109 ( unsigned long V_176 , unsigned int V_69 )
{
while ( V_69 != 0 ) {
V_69 -= V_17 ;
F_17 ( V_176 , 0 ) ;
V_176 += V_17 ;
}
}
static void F_110 ( struct V_164 * V_187 , struct V_164 * V_165 )
{
struct V_188 * V_189 ;
V_189 = V_190 . V_79 ;
if ( V_189 != & V_190 ) {
F_111 ( V_189 ) ;
F_112 ( V_189 ) ;
V_165 -> V_167 = V_189 -> V_191 ;
V_189 -> V_192 = V_165 ;
return;
}
V_189 = V_193 . V_79 ;
if ( V_189 -> V_192 == V_187 )
V_189 = V_189 -> V_79 ;
F_111 ( V_189 ) ;
F_112 ( V_189 ) ;
V_189 -> V_192 -> V_167 = V_168 ;
V_189 -> V_192 = V_165 ;
V_165 -> V_167 = V_189 -> V_191 ;
F_56 ( & V_88 [ V_189 -> V_191 ] ,
V_189 -> V_191 ) ;
}
static void F_113 ( struct V_164 * V_187 , struct V_164 * V_165 , struct V_194 * V_195 , int V_196 )
{
struct V_188 * V_24 ;
int V_197 = 0 ;
if ( V_165 -> V_167 == V_168 ) {
V_197 = 1 ;
F_110 ( V_187 , V_165 ) ;
} else {
V_24 = V_198 + V_165 -> V_167 ;
F_111 ( V_24 ) ;
F_112 ( V_24 ) ;
}
if ( V_197 || V_187 != V_165 )
F_13 ( V_165 -> V_167 ) ;
}
static void F_114 ( struct V_164 * V_165 )
{
struct V_188 * V_199 ;
if ( V_165 -> V_167 != V_168 ) {
F_56 ( & V_88 [ V_165 -> V_167 ] , V_165 -> V_167 ) ;
V_199 = V_198 + V_165 -> V_167 ;
F_111 ( V_199 ) ;
F_115 ( V_199 ) ;
V_165 -> V_167 = V_168 ;
}
}
static void F_116 ( struct V_200 * V_201 )
{
int V_202 , V_76 ;
V_202 = 0 ;
for ( V_76 = 0 ; V_76 < V_25 ; V_76 ++ )
V_202 += V_88 [ V_76 ] . V_90 ;
F_117 ( V_201 ,
L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30 ,
V_3 . V_34 ,
( V_3 . V_36 ? L_31 : L_32 ) ,
V_3 . V_7 ,
V_25 ,
( V_9 + 1 ) ,
V_93 . V_90 ,
V_94 . V_90 ,
V_202 ,
V_91 . V_90 ,
V_106 ,
V_108 ) ;
}
static void F_118 ( T_5 * V_203 , T_5 V_129 )
{
* V_203 = V_129 ;
}
static void F_119 ( T_6 * V_204 , T_7 * V_205 )
{
}
static void F_120 ( T_7 * V_205 , T_5 * V_203 )
{
V_205 -> V_206 [ 0 ] = V_207 | ( unsigned long ) V_203 ;
}
static void F_121 ( T_7 * V_205 , struct V_70 * V_203 )
{
if ( F_122 ( V_203 ) == NULL ) F_123 () ;
V_205 -> V_206 [ 0 ] = V_207 | ( unsigned long ) F_122 ( V_203 ) ;
}
static int F_124 ( T_5 V_129 )
{
return ( ( F_125 ( V_129 ) & ( V_179 | V_74 ) ) != 0 ) ;
}
static void F_126 ( T_5 * V_203 ) { * V_203 = F_127 ( 0 ) ; }
static int F_128 ( T_7 V_208 )
{
return ( ( ( F_129 ( V_208 ) & ~ V_11 ) != V_207 ) ||
( ! F_87 ( F_129 ( V_208 ) ) ) ) ;
}
static int F_130 ( T_7 V_208 )
{
return ( ( F_129 ( V_208 ) & V_209 ) != 0 ) ;
}
static void F_131 ( T_7 * V_205 ) {
memset ( ( void * ) V_205 , 0 , sizeof( T_7 ) ) ;
}
static int F_132 ( T_6 V_210 ) { return 0 ; }
static int F_133 ( T_6 V_210 ) { return 0 ; }
static int F_134 ( T_6 V_210 ) { return 1 ; }
static void F_135 ( T_6 * V_204 ) { }
static T_5 F_136 ( T_5 V_129 )
{
V_129 = F_127 ( F_125 ( V_129 ) | V_211 ) ;
if ( F_125 ( V_129 ) & V_212 )
V_129 = F_127 ( F_125 ( V_129 ) | V_213 ) ;
return V_129 ;
}
static T_5 F_137 ( T_5 V_129 )
{
V_129 = F_127 ( F_125 ( V_129 ) | V_212 ) ;
if ( F_125 ( V_129 ) & V_211 )
V_129 = F_127 ( F_125 ( V_129 ) | V_213 ) ;
return V_129 ;
}
static T_5 F_138 ( T_5 V_129 )
{
V_129 = F_127 ( F_125 ( V_129 ) | V_214 ) ;
if ( F_125 ( V_129 ) & V_215 )
V_129 = F_127 ( F_125 ( V_129 ) | V_216 ) ;
return V_129 ;
}
static T_5 F_139 ( struct V_70 * V_70 , T_8 V_217 )
{
return F_127 ( F_140 ( V_70 ) | F_82 ( V_217 ) ) ;
}
static T_5 F_141 ( unsigned long V_218 , T_8 V_217 )
{
return F_127 ( ( V_218 >> V_72 ) | F_82 ( V_217 ) ) ;
}
static T_5 F_142 ( unsigned long V_70 , T_8 V_217 , int V_219 )
{
return F_127 ( ( ( V_70 - V_71 ) >> V_72 ) | F_82 ( V_217 ) ) ;
}
static unsigned long F_143 ( T_5 V_129 )
{
return F_125 ( V_129 ) & V_183 ;
}
static T_5 F_144 ( unsigned long V_220 )
{
return F_127 ( V_220 | V_221 ) ;
}
static unsigned long F_145 ( T_5 V_129 )
{
return F_125 ( V_129 ) & ( ( 1UL << V_222 ) - 1 ) ;
}
static inline unsigned long F_146 ( T_7 V_208 )
{
return ( F_129 ( V_208 ) & V_11 ) ;
}
static struct V_70 * F_147 ( T_7 V_208 )
{
return F_148 ( F_146 ( V_208 ) ) ;
}
static unsigned long F_149 ( T_6 V_210 ) { return 0 ; }
static inline T_6 * F_150 ( struct V_164 * V_165 , unsigned long V_223 )
{
return V_165 -> V_210 + ( V_223 >> V_224 ) ;
}
static T_7 * F_151 ( T_6 * V_225 , unsigned long V_223 )
{
return ( T_7 * ) V_225 ;
}
T_5 * F_152 ( T_7 * V_225 , unsigned long V_223 )
{
return ( T_5 * ) F_146 ( * V_225 ) +
( ( V_223 >> V_72 ) & ( V_226 - 1 ) ) ;
}
static unsigned long F_153 ( T_9 V_98 )
{
return ( V_98 . V_227 & V_228 ) ;
}
static unsigned long F_154 ( T_9 V_98 )
{
return ( V_98 . V_227 >> V_229 ) & V_230 ;
}
static T_9 F_155 ( unsigned long type , unsigned long V_231 )
{
return ( T_9 ) {
( V_231 & V_230 ) << V_229
| ( type & V_228 ) } ;
}
static void F_156 ( T_5 * V_129 )
{
F_157 ( ( unsigned long ) V_129 ) ;
}
static void F_158 ( T_6 * V_210 )
{
F_157 ( ( unsigned long ) V_210 ) ;
}
static T_6 * F_159 ( void )
{
unsigned long * V_232 ;
if ( ( V_232 = V_233 ) != NULL ) {
V_233 = ( unsigned long * ) ( * V_232 ) ;
V_232 [ 0 ] = V_232 [ 1 ] ;
V_234 -- ;
} else {
T_6 * V_235 ;
V_232 = ( unsigned long * ) F_160 ( V_115 ) ;
memset ( V_232 , 0 , ( V_26 / V_236 ) * sizeof( T_6 ) ) ;
V_235 = F_150 ( & V_155 , 0 ) ;
memcpy ( ( ( T_6 * ) V_232 ) + V_237 , V_235 + V_237 ,
( V_238 - V_237 ) * sizeof( T_6 ) ) ;
}
return ( T_6 * ) V_232 ;
}
static void F_161 ( T_6 * V_210 )
{
* ( unsigned long * ) V_210 = ( unsigned long ) V_233 ;
V_233 = ( unsigned long * ) V_210 ;
V_234 ++ ;
}
static inline T_5 *
F_162 ( struct V_164 * V_165 , unsigned long V_223 )
{
unsigned long * V_232 ;
if ( ( V_232 = ( unsigned long * ) V_239 ) != NULL ) {
V_239 = ( unsigned long * ) ( * V_232 ) ;
V_232 [ 0 ] = V_232 [ 1 ] ;
V_234 -- ;
}
return ( T_5 * ) V_232 ;
}
static T_5 * F_163 ( struct V_164 * V_165 , unsigned long V_223 )
{
T_5 * V_129 ;
if ( ( V_129 = F_162 ( V_165 , V_223 ) ) != NULL )
return V_129 ;
V_129 = ( T_5 * ) F_164 ( V_115 | V_240 ) ;
return V_129 ;
}
static T_10 F_165 ( struct V_164 * V_165 , unsigned long V_223 )
{
T_5 * V_129 ;
struct V_70 * V_70 ;
V_129 = F_163 ( V_165 , V_223 ) ;
if ( V_129 == NULL )
return NULL ;
V_70 = F_148 ( V_129 ) ;
F_166 ( V_70 ) ;
return V_70 ;
}
static inline void F_167 ( T_5 * V_129 )
{
* ( unsigned long * ) V_129 = ( unsigned long ) V_239 ;
V_239 = ( unsigned long * ) V_129 ;
V_234 ++ ;
}
static void F_168 ( T_10 V_129 )
{
F_169 ( V_129 ) ;
F_167 ( F_122 ( V_129 ) ) ;
}
static T_7 * F_170 ( struct V_164 * V_165 , unsigned long V_223 )
{
F_123 () ;
return NULL ;
}
static void F_171 ( T_7 * V_208 ) { }
static void F_172 ( int V_241 , int V_131 )
{
if ( V_234 > V_131 ) {
do {
if ( V_233 )
F_158 ( F_159 () ) ;
if ( V_239 )
F_156 ( F_162 ( NULL , 0 ) ) ;
} while ( V_234 > V_241 );
}
}
void F_173 ( struct V_169 * V_170 , unsigned long V_223 , T_5 * V_203 )
{
unsigned long V_103 ;
int V_19 ;
if ( V_170 -> V_154 -> V_167 == V_168 )
return;
F_57 ( V_103 ) ;
V_223 &= V_11 ;
if ( ( V_19 = F_5 ( V_223 ) ) == V_9 ) {
struct V_97 * V_98 = F_64 () ;
struct V_164 * V_165 = V_170 -> V_154 ;
unsigned long V_86 , V_2 ;
V_98 -> V_20 = V_86 = ( V_223 & V_110 ) ;
V_98 -> V_24 = V_165 -> V_167 ;
F_47 ( V_88 + V_165 -> V_167 , V_98 ) ;
F_16 ( V_98 -> V_20 , V_98 -> V_19 ) ;
V_2 = V_86 + V_21 ;
while ( V_86 < V_2 ) {
#ifdef F_174
T_6 * V_204 = F_150 ( V_165 , V_86 ) ;
T_5 * V_203 ;
if ( ! V_204 )
goto V_242;
V_203 = F_152 ( ( T_7 * ) V_204 , V_86 ) ;
if ( ! V_203 || ! ( F_125 ( * V_203 ) & V_179 ) )
goto V_242;
F_17 ( V_86 , F_125 ( * V_203 ) ) ;
goto V_79;
V_242:
#endif
F_17 ( V_86 , 0 ) ;
#ifdef F_174
V_79:
#endif
V_86 += V_17 ;
}
#ifndef F_174
F_17 ( V_223 , F_125 ( * V_203 ) ) ;
#endif
F_61 ( V_103 ) ;
return;
} else {
struct V_97 * V_98 = & V_78 [ V_19 ] ;
F_49 ( V_98 ) ;
F_46 ( V_98 ) ;
}
F_17 ( V_223 , F_125 ( * V_203 ) ) ;
F_61 ( V_103 ) ;
}
void T_1 F_175 ( void )
{
int V_76 , V_243 ;
unsigned long V_22 , V_20 ;
extern struct V_244 V_245 ;
unsigned long V_246 , V_247 ;
V_22 = ( unsigned long ) & V_248 ;
V_22 = F_81 ( V_22 ) ;
V_247 = 0 ;
V_249 = F_176 ( & V_247 ) ;
V_246 = V_249 ;
F_27 () ;
V_9 = ( V_40 - 1 ) ;
F_39 () ;
F_44 () ;
F_41 ( V_22 ) ;
F_18 ( V_22 ) ;
F_52 ( V_250 ) ;
F_43 ( V_245 . V_86 , V_251 ) ;
F_43 ( V_252 , V_253 ) ;
F_93 () ;
F_53 () ;
F_13 ( 0 ) ;
memset ( V_254 , 0 , V_17 ) ;
memset ( V_255 , 0 , V_17 ) ;
memset ( V_256 , 0 , V_17 ) ;
memset ( V_257 , 0 , V_17 ) ;
memset ( V_258 , 0 , V_17 ) ;
V_20 = V_259 ;
V_254 [ V_20 >> V_224 ] = F_177 ( V_207 | ( unsigned long ) V_255 ) ;
V_20 += V_236 ;
V_254 [ V_20 >> V_224 ] = F_177 ( V_207 | ( unsigned long ) V_256 ) ;
V_20 += V_236 ;
V_254 [ V_20 >> V_224 ] = F_177 ( V_207 | ( unsigned long ) V_257 ) ;
V_20 += V_236 ;
V_254 [ V_20 >> V_224 ] = F_177 ( V_207 | ( unsigned long ) V_258 ) ;
F_33 () ;
F_178 ( V_25 ) ;
{
unsigned long V_260 [ V_261 ] ;
unsigned long V_262 [ V_261 ] ;
unsigned long V_127 ;
int V_263 ;
for ( V_263 = 0 ; V_263 < V_261 ; V_263 ++ )
V_260 [ V_263 ] = V_262 [ V_263 ] = 0 ;
V_127 = V_264 - V_265 ;
V_260 [ V_266 ] = V_127 ;
V_262 [ V_266 ] = V_127 - V_247 ;
V_127 = V_267 - V_264 ;
V_260 [ V_268 ] = V_127 ;
V_262 [ V_268 ] = V_127 - F_179 () ;
F_180 ( 0 , V_260 , V_265 , V_262 ) ;
}
V_243 = 0 ;
for ( V_76 = 0 ; V_76 < V_40 ; V_76 ++ )
if ( V_78 [ V_76 ] . V_81 )
V_243 ++ ;
V_108 = V_40 - V_243 - 40 - 1 ;
F_34 ( L_33 , V_243 ) ;
}
static T_8 F_181 ( T_8 V_269 )
{
V_269 |= F_182 ( V_182 | V_14 ) ;
return V_269 ;
}
void T_1 F_183 ( void )
{
extern void V_270 ( void ) ;
F_34 ( L_34 ) ;
F_184 ( V_271 , V_224 ) ;
F_185 ( V_272 , V_236 ) ;
F_185 ( V_273 , V_274 ) ;
F_184 ( V_275 , V_276 ) ;
F_184 ( V_277 , V_278 ) ;
F_184 ( V_279 , V_26 / V_236 ) ;
F_186 ( V_280 , F_82 ( V_281 ) ) ;
V_159 = F_82 ( V_282 ) ;
F_186 ( V_283 , F_82 ( V_284 ) ) ;
F_186 ( V_285 , F_82 ( V_286 ) ) ;
F_186 ( V_287 , F_82 ( V_137 ) ) ;
V_287 = F_82 ( V_137 ) ;
F_187 ( V_288 , F_181 , V_289 ) ;
F_187 ( V_290 , V_270 , V_289 ) ;
F_187 ( V_291 , F_172 , V_289 ) ;
F_187 ( V_292 , F_97 , V_289 ) ;
if ( V_3 . V_36 ) {
F_187 ( F_35 , F_6 , V_289 ) ;
F_187 ( F_63 , F_4 , V_289 ) ;
F_187 ( F_59 , F_3 , V_289 ) ;
} else {
F_187 ( F_35 , F_10 , V_289 ) ;
F_187 ( F_63 , F_9 , V_289 ) ;
F_187 ( F_59 , F_8 , V_289 ) ;
}
F_187 ( V_293 , F_104 , V_289 ) ;
F_187 ( V_294 , F_98 , V_289 ) ;
F_187 ( V_295 , F_114 , V_289 ) ;
F_187 ( V_296 , F_113 , V_289 ) ;
F_187 ( V_297 , F_100 , V_289 ) ;
F_187 ( V_298 , F_106 , V_289 ) ;
F_187 ( V_299 , F_105 , V_289 ) ;
F_187 ( V_300 , F_99 , V_289 ) ;
F_187 ( V_301 , F_101 , V_289 ) ;
F_187 ( V_302 , F_103 , V_289 ) ;
F_187 ( V_303 , F_102 , V_304 ) ;
F_187 ( V_305 , F_118 , V_306 ) ;
F_187 ( V_307 , F_143 , V_289 ) ;
#if 0
BTFIXUPSET_CALL(pmd_page, sun4c_pmd_page, BTFIXUPCALL_ANDNINT(PAGE_SIZE - 1));
#else
F_187 ( V_308 , F_147 , V_289 ) ;
#endif
F_187 ( V_309 , F_120 , V_289 ) ;
F_187 ( V_310 , F_121 , V_289 ) ;
F_187 ( V_311 , F_124 , V_289 ) ;
F_187 ( V_312 , F_126 , V_313 ) ;
F_187 ( V_314 , F_128 , V_289 ) ;
F_187 ( V_315 , F_130 , V_289 ) ;
F_187 ( V_316 , F_131 , V_313 ) ;
F_187 ( V_317 , F_132 , F_188 ( 0 ) ) ;
F_187 ( V_318 , F_133 , F_188 ( 0 ) ) ;
F_187 ( V_319 , F_134 , F_188 ( 1 ) ) ;
F_187 ( V_320 , F_135 , V_304 ) ;
F_187 ( V_321 , F_139 , V_289 ) ;
F_187 ( V_322 , F_141 , V_289 ) ;
F_187 ( V_323 , F_142 , V_289 ) ;
F_186 ( V_324 , V_325 ) ;
F_187 ( V_326 , F_151 , V_289 ) ;
F_187 ( V_327 , F_152 , V_289 ) ;
F_187 ( V_328 , F_167 , V_289 ) ;
F_187 ( V_329 , F_168 , V_289 ) ;
F_187 ( V_330 , F_163 , V_289 ) ;
F_187 ( V_331 , F_165 , V_289 ) ;
F_187 ( V_332 , F_171 , V_304 ) ;
F_187 ( V_333 , F_170 , V_334 ) ;
F_187 ( V_335 , F_161 , V_289 ) ;
F_187 ( V_336 , F_159 , V_289 ) ;
F_189 ( V_337 , V_211 ) ;
F_189 ( V_338 , V_212 ) ;
F_189 ( V_339 , V_214 ) ;
F_189 ( V_340 , V_221 ) ;
F_189 ( V_341 , V_211 | V_213 ) ;
F_189 ( V_342 , V_212 | V_213 ) ;
F_189 ( V_343 , V_214 | V_216 ) ;
F_187 ( V_344 , F_136 , V_289 ) ;
F_187 ( V_345 , F_137 , V_289 ) ;
F_187 ( V_346 , F_138 , V_289 ) ;
F_187 ( V_347 , F_173 , V_289 ) ;
F_187 ( V_348 , F_145 , V_289 ) ;
F_187 ( V_349 , F_144 , V_289 ) ;
F_187 ( V_350 , F_79 , V_289 ) ;
F_187 ( V_351 , F_84 , V_289 ) ;
F_187 ( V_352 , F_86 , V_289 ) ;
F_187 ( V_353 , F_88 , V_289 ) ;
F_187 ( V_354 , F_91 , V_289 ) ;
F_187 ( V_355 , F_92 , V_289 ) ;
F_187 ( V_356 , F_36 , V_289 ) ;
F_187 ( V_357 , F_38 , V_289 ) ;
F_187 ( V_358 , F_108 , V_289 ) ;
F_187 ( V_359 , F_109 , V_289 ) ;
F_187 ( V_360 , F_153 , V_289 ) ;
F_187 ( V_361 , F_154 , V_289 ) ;
F_187 ( V_362 , F_155 , V_289 ) ;
F_187 ( V_363 , F_70 , V_289 ) ;
F_187 ( V_364 , F_75 , V_289 ) ;
F_187 ( V_365 , F_116 , V_289 ) ;
F_187 ( V_366 , F_119 , V_304 ) ;
F_187 ( V_367 , F_149 , V_334 ) ;
}
