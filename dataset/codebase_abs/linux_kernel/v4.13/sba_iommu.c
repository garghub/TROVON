static void
F_1 ( char * V_1 )
{
F_2 ( L_1 , ( void * ) V_1 ) ;
F_2 ( L_2 , F_3 ( V_1 + V_2 ) ) ;
F_2 ( L_3 , F_3 ( V_1 + V_3 ) ) ;
F_2 ( L_4 , F_3 ( V_1 + V_4 ) ) ;
F_2 ( L_5 , F_3 ( V_1 + V_5 ) ) ;
F_2 ( L_6 ) ;
}
static void
F_4 ( struct V_6 * V_6 , char * V_7 , T_1 V_8 )
{
T_2 * V_9 = & V_6 -> V_10 [ V_8 & ~ ( V_11 - 1 ) ] ;
unsigned long * V_12 = ( unsigned long * ) & V_6 -> V_13 [ ( V_8 >> 3 ) & - sizeof( unsigned long )] ;
T_1 V_14 ;
F_5 ( V_15 L_7 ,
V_7 , V_12 , V_8 & ( V_11 - 1 ) , * V_12 ) ;
V_14 = 0 ;
while ( V_14 < V_11 ) {
F_5 ( V_15 L_8 ,
( V_14 == ( V_8 & ( V_11 - 1 ) ) )
? L_9 : L_10 ,
V_14 , V_9 , ( unsigned long long ) * V_9 ) ;
V_14 ++ ;
V_9 ++ ;
}
F_5 ( V_15 L_11 , V_7 ) ;
}
static int
F_6 ( struct V_6 * V_6 , char * V_7 )
{
T_2 * V_16 = ( T_2 * ) & ( V_6 -> V_13 [ V_6 -> V_17 ] ) ;
T_2 * V_12 = ( T_2 * ) V_6 -> V_13 ;
T_2 * V_18 = V_6 -> V_10 ;
T_1 V_8 = 0 ;
while ( V_12 < V_16 ) {
T_2 V_19 ;
int V_14 ;
V_19 = * V_12 ;
V_14 = 64 ;
while ( V_14 ) {
T_3 V_20 = ( ( T_3 ) ( ( * V_18 >> ( 63 ) ) & 0x1 ) ) ;
if ( ( V_19 & 0x1 ) ^ V_20 )
{
F_4 ( V_6 , V_7 , V_8 ) ;
return ( 1 ) ;
}
V_14 -- ;
V_19 >>= 1 ;
V_18 ++ ;
V_8 ++ ;
}
V_12 ++ ;
}
return 0 ;
}
static void
F_7 ( struct V_6 * V_6 , struct V_21 * V_22 , int V_23 )
{
while ( V_23 -- > 0 ) {
F_5 ( V_15 L_12 , V_23 ,
V_22 -> V_24 , V_22 -> V_25 ,
F_8 ( V_22 ) ) ;
V_22 = F_9 ( V_22 ) ;
}
}
static void
F_10 ( struct V_6 * V_6 , struct V_21 * V_22 , int V_23 )
{
struct V_21 * V_26 = V_22 ;
int V_27 = V_23 ;
while ( V_27 -- > 0 ) {
if ( F_8 ( V_26 ) == 0x0UL )
F_7 ( NULL , V_22 , V_23 ) ;
V_26 = F_9 ( V_26 ) ;
}
}
static T_4 int
F_11 ( unsigned long V_28 )
{
long double V_29 = V_28 - 1 ;
long V_30 ;
V_30 = F_12 ( V_29 ) ;
V_30 = V_30 - V_31 - 0xffff + 1 ;
if ( V_30 < 0 )
V_30 = 0 ;
return V_30 ;
}
static unsigned long F_13 ( struct V_6 * V_6 , unsigned long * V_32 ,
unsigned int V_33 )
{
return ( ( ( unsigned long ) V_32 - ( unsigned long ) V_6 -> V_13 ) << 3 )
+ V_33 ;
}
static T_4 unsigned long
F_14 ( struct V_6 * V_6 , struct V_34 * V_35 ,
unsigned long V_36 , int V_37 )
{
unsigned long * V_32 ;
unsigned long * V_38 = ( unsigned long * ) & ( V_6 -> V_13 [ V_6 -> V_17 ] ) ;
unsigned long V_39 , V_8 = ~ 0UL , V_40 ;
unsigned long V_41 ;
unsigned long V_42 ;
int V_43 ;
ASSERT ( ( ( unsigned long ) V_6 -> V_44 & (sizeof( unsigned long ) - 1UL ) ) == 0 ) ;
ASSERT ( V_32 < V_38 ) ;
V_41 = ( unsigned long long ) F_15 ( V_35 ) + 1 ;
V_41 = F_16 ( V_41 , 1ULL << V_31 ) >> V_31 ;
F_17 ( V_6 -> V_45 & ~ V_46 ) ;
V_42 = V_6 -> V_45 >> V_31 ;
F_18 ( & V_6 -> V_47 , V_39 ) ;
if ( F_19 ( V_37 ) ) {
V_32 = V_6 -> V_44 ;
} else {
V_32 = ( V_48 * ) V_6 -> V_13 ;
V_6 -> V_49 = 0 ;
}
V_36 = 1UL << F_11 ( V_36 << V_31 ) ;
if ( F_19 ( V_36 == 1 ) ) {
unsigned int V_33 ;
for(; V_32 < V_38 ; V_32 ++ ) {
if ( F_19 ( * V_32 != ~ 0UL ) ) {
V_33 = F_20 ( * V_32 ) ;
* V_32 |= ( 1UL << V_33 ) ;
V_8 = F_13 ( V_6 , V_32 , V_33 ) ;
V_6 -> V_49 = V_33 + V_36 ;
goto V_50;
}
}
goto V_51;
}
if ( F_19 ( V_36 <= V_11 / 2 ) ) {
unsigned long V_52 = 1 << F_11 ( V_36 << V_31 ) ;
T_1 V_33 = F_21 ( V_6 -> V_49 , V_52 ) ;
unsigned long V_53 , V_54 ;
V_54 = F_22 ( V_36 ) ;
V_53 = V_54 << V_33 ;
F_23 ( L_13 , V_55 , V_52 , V_32 ) ;
for(; V_32 < V_38 ; V_32 ++ )
{
F_23 ( L_14 , V_32 , V_53 , * V_32 ) ;
ASSERT ( 0 != V_53 ) ;
for (; V_53 ; V_53 <<= V_52 , V_33 += V_52 ) {
V_40 = F_13 ( V_6 , V_32 , V_33 ) ;
V_43 = F_24 ( V_40 , V_36 ,
V_42 ,
V_41 ) ;
if ( ( 0 == ( ( * V_32 ) & V_53 ) ) && ! V_43 ) {
* V_32 |= V_53 ;
V_8 = V_40 ;
V_6 -> V_49 = V_33 + V_36 ;
goto V_50;
}
}
V_33 = 0 ;
V_53 = V_54 ;
}
} else {
int V_56 , V_57 , V_58 ;
unsigned long * V_59 ;
V_56 = V_36 >> 6 ;
V_57 = V_36 - ( V_56 * V_11 ) ;
V_59 = V_38 - V_56 ;
for (; V_32 < V_59 ; V_32 ++ ) {
V_40 = F_13 ( V_6 , V_32 , 0 ) ;
V_43 = F_24 ( V_40 , V_36 ,
V_42 , V_41 ) ;
if ( V_43 )
goto V_60;
for ( V_58 = 0 ; V_58 < V_56 ; V_58 ++ ) {
if ( V_32 [ V_58 ] != 0 )
goto V_60;
}
if ( V_57 && V_32 [ V_58 ] && ( F_25 ( V_32 [ V_58 ] ) < V_57 ) )
continue;
for ( V_58 = 0 ; V_58 < V_56 ; V_58 ++ )
V_32 [ V_58 ] = ~ 0UL ;
V_32 [ V_58 ] |= F_22 ( V_57 ) ;
V_8 = V_40 ;
V_32 += V_56 ;
V_6 -> V_49 = V_57 ;
goto V_50;
V_60:
;
}
}
V_51:
F_26 ( V_6 -> V_13 ) ;
V_6 -> V_44 = ( unsigned long * ) V_6 -> V_13 ;
V_6 -> V_49 = 0 ;
F_27 ( & V_6 -> V_47 , V_39 ) ;
return ( V_8 ) ;
V_50:
V_6 -> V_44 = V_32 ;
F_27 ( & V_6 -> V_47 , V_39 ) ;
return ( V_8 ) ;
}
static int
F_28 ( struct V_6 * V_6 , struct V_34 * V_35 , T_5 V_28 )
{
unsigned int V_61 = V_28 >> V_31 ;
#ifdef F_29
unsigned long V_62 ;
#endif
unsigned long V_8 ;
ASSERT ( V_61 ) ;
ASSERT ( 0 == ( V_28 & ~ V_46 ) ) ;
#ifdef F_29
V_62 = F_30 () ;
#endif
V_8 = F_14 ( V_6 , V_35 , V_61 , 1 ) ;
if ( F_31 ( V_8 >= ( V_6 -> V_17 << 3 ) ) ) {
V_8 = F_14 ( V_6 , V_35 , V_61 , 0 ) ;
if ( F_31 ( V_8 >= ( V_6 -> V_17 << 3 ) ) ) {
#if V_63 > 0
unsigned long V_39 ;
F_18 ( & V_6 -> V_64 , V_39 ) ;
if ( V_6 -> V_65 > 0 ) {
struct V_66 * V_29 ;
int V_67 = V_6 -> V_65 ;
V_29 = & ( V_6 -> V_68 [ V_6 -> V_65 - 1 ] ) ;
F_32 ( & V_6 -> V_47 ) ;
while ( V_67 -- ) {
F_33 ( V_6 , V_29 -> V_69 , V_29 -> V_28 ) ;
F_34 ( V_6 , V_29 -> V_69 , V_29 -> V_28 ) ;
V_29 -- ;
}
V_6 -> V_65 = 0 ;
F_3 ( V_6 -> V_70 + V_71 ) ;
F_35 ( & V_6 -> V_47 ) ;
}
F_27 ( & V_6 -> V_64 , V_39 ) ;
V_8 = F_14 ( V_6 , V_35 , V_61 , 0 ) ;
if ( F_31 ( V_8 >= ( V_6 -> V_17 << 3 ) ) ) {
F_5 ( V_72 L_15
L_16 ,
V_55 , V_6 -> V_70 , V_6 -> V_17 ,
V_61 , F_15 ( V_35 ) ) ;
return - 1 ;
}
#else
F_5 ( V_72 L_15
L_16 ,
V_55 , V_6 -> V_70 , V_6 -> V_17 ,
V_61 , F_15 ( V_35 ) ) ;
return - 1 ;
#endif
}
}
#ifdef F_29
V_6 -> V_73 [ V_6 -> V_74 ++ ] = ( F_30 () - V_62 ) / V_61 ;
V_6 -> V_74 &= V_75 - 1 ;
#endif
F_36 ( & ( V_6 -> V_10 [ V_8 ] ) ) ;
#ifdef F_37
if( 0x00 != ( ( V_76 * ) V_6 -> V_10 ) [ V_8 * V_77 + 7 ] ) {
F_4 ( V_6 , L_17 , V_8 ) ;
}
#endif
F_23 ( L_18 ,
V_55 , V_28 , V_61 , V_8 ,
( T_1 ) ( ( unsigned long ) V_6 -> V_44 - ( unsigned long ) V_6 -> V_13 ) ,
V_6 -> V_49 ) ;
return ( V_8 ) ;
}
static T_4 void
F_34 ( struct V_6 * V_6 , T_6 V_69 , T_5 V_28 )
{
unsigned long V_78 = F_38 ( V_6 , V_69 ) ;
unsigned int V_8 = F_39 ( V_78 ) ;
unsigned int V_79 = V_8 >> 3 ;
unsigned long * V_32 = ( unsigned long * ) & ( ( V_6 ) -> V_13 [ V_79 & ~ V_80 ] ) ;
int V_81 = V_28 >> V_31 ;
unsigned long V_82 ;
V_81 = 1UL << F_11 ( V_81 << V_31 ) ;
for (; V_81 > 0 ; V_32 ++ ) {
if ( F_31 ( V_81 > V_11 ) ) {
* V_32 = 0UL ;
V_81 -= V_11 ;
V_8 += V_11 ;
} else {
V_82 = F_22 ( V_81 ) << ( V_8 & ( V_11 - 1 ) ) ;
V_81 = 0 ;
F_23 ( L_19 , V_55 , ( T_1 ) V_69 , V_28 ,
V_81 , V_82 , V_8 , V_32 , * V_32 ) ;
ASSERT ( V_82 != 0 ) ;
ASSERT ( V_81 ) ;
ASSERT ( ( * V_32 & V_82 ) == V_82 ) ;
* V_32 &= ~ V_82 ;
}
}
}
void T_4
F_40 ( T_2 * V_83 , unsigned long V_84 )
{
* V_83 = ( ( V_84 & ~ 0xE000000000000FFFULL ) | 0x80000000000000FFULL ) ;
}
static void
F_41 ( void * V_85 , T_5 V_28 )
{
unsigned long V_86 , V_59 ;
V_86 = F_42 ( ( unsigned long ) V_85 ) ;
V_59 = ( unsigned long ) V_85 + V_28 ;
while ( V_86 + V_87 <= V_59 ) {
struct V_88 * V_88 = F_43 ( ( void * ) V_86 ) ;
F_44 ( V_89 , & V_88 -> V_39 ) ;
V_86 += V_87 ;
}
}
static T_4 void
F_33 ( struct V_6 * V_6 , T_6 V_69 , T_5 V_90 )
{
T_3 V_78 = ( T_3 ) F_38 ( V_6 , V_69 ) ;
int V_91 = F_39 ( V_78 ) ;
ASSERT ( V_90 > 0 ) ;
ASSERT ( 0 == ( V_90 & ~ V_46 ) ) ;
#ifdef F_37
if ( ! ( V_6 -> V_10 [ V_91 ] >> 60 ) ) {
F_4 ( V_6 , L_20 , F_39 ( V_78 ) ) ;
}
#endif
if ( V_90 <= V_92 )
{
ASSERT ( V_91 < V_6 -> V_93 ) ;
V_78 |= V_31 ;
#ifndef F_45
V_6 -> V_10 [ V_91 ] &= ~ ( 0x80000000000000FFULL ) ;
#else
V_6 -> V_10 [ V_91 ] = ( 0x80000000000000FFULL | V_94 ) ;
#endif
} else {
T_3 V_95 = F_11 ( V_90 ) + V_31 ;
V_78 |= V_95 ;
ASSERT ( V_95 <= 31 ) ;
do {
ASSERT ( V_6 -> V_10 [ V_91 ] >> 63 ) ;
#ifndef F_45
V_6 -> V_10 [ V_91 ] &= ~ ( 0x80000000000000FFULL ) ;
#else
V_6 -> V_10 [ V_91 ] = ( 0x80000000000000FFULL | V_94 ) ;
#endif
V_91 ++ ;
V_90 -= V_92 ;
} while ( V_90 > 0 );
}
F_46 ( V_78 | V_6 -> V_45 , V_6 -> V_70 + V_71 ) ;
}
static T_6 F_47 ( struct V_34 * V_35 , struct V_88 * V_88 ,
unsigned long V_96 , T_5 V_28 ,
enum V_97 V_98 ,
unsigned long V_99 )
{
struct V_6 * V_6 ;
void * V_85 = F_48 ( V_88 ) + V_96 ;
T_6 V_78 ;
T_6 V_100 ;
T_2 * V_101 ;
int V_8 ;
#ifdef F_37
unsigned long V_39 ;
#endif
#ifdef F_49
unsigned long V_102 = F_50 ( V_85 ) ;
#endif
#ifdef F_49
ASSERT ( F_51 ( V_35 ) -> V_103 ) ;
if ( F_19 ( ( V_102 & ~ F_51 ( V_35 ) -> V_103 ) == 0 ) ) {
F_52 ( L_21
L_22 ,
F_51 ( V_35 ) -> V_103 , V_102 ) ;
return V_102 ;
}
#endif
V_6 = F_53 ( V_35 ) ;
ASSERT ( V_6 ) ;
F_26 ( V_6 -> V_44 ) ;
ASSERT ( V_28 > 0 ) ;
ASSERT ( V_28 <= V_104 ) ;
V_100 = ( ( T_6 ) ( long ) V_85 ) & ~ V_46 ;
V_28 = ( V_28 + V_100 + ~ V_46 ) & V_46 ;
#ifdef F_37
F_18 ( & V_6 -> V_47 , V_39 ) ;
if ( F_6 ( V_6 , L_23 ) )
F_54 ( L_24 ) ;
F_27 ( & V_6 -> V_47 , V_39 ) ;
#endif
V_8 = F_28 ( V_6 , V_35 , V_28 ) ;
if ( V_8 < 0 )
return 0 ;
V_78 = ( T_6 ) V_8 << V_31 ;
F_55 ( L_25 , V_55 , V_85 , ( long ) V_78 | V_100 ) ;
V_101 = & ( V_6 -> V_10 [ V_8 ] ) ;
while ( V_28 > 0 ) {
ASSERT ( ( ( V_76 * ) V_101 ) [ 7 ] == 0 ) ;
F_40 ( V_101 , ( unsigned long ) V_85 ) ;
F_55 ( L_26 , V_101 , * V_101 ) ;
V_85 += V_92 ;
V_28 -= V_92 ;
V_101 ++ ;
}
F_56 () ;
#ifdef F_37
F_18 ( & V_6 -> V_47 , V_39 ) ;
F_6 ( V_6 , L_27 ) ;
F_27 ( & V_6 -> V_47 , V_39 ) ;
#endif
return F_57 ( V_6 , V_78 , V_100 ) ;
}
static T_6 F_58 ( struct V_34 * V_35 , void * V_85 ,
T_5 V_28 , enum V_97 V_98 ,
unsigned long V_99 )
{
return F_47 ( V_35 , F_43 ( V_85 ) ,
( unsigned long ) V_85 & ~ V_105 , V_28 , V_98 , V_99 ) ;
}
static T_4 void
F_59 ( struct V_6 * V_6 , T_6 V_69 , T_5 V_28 )
{
T_3 V_78 = ( T_3 ) F_38 ( V_6 , V_69 ) ;
int V_91 = F_39 ( V_78 ) ;
void * V_85 ;
if ( V_28 <= V_92 ) {
V_85 = F_60 ( V_6 -> V_10 [ V_91 ] &
~ 0xE000000000000FFFULL ) ;
F_41 ( V_85 , V_28 ) ;
} else {
do {
V_85 = F_60 ( V_6 -> V_10 [ V_91 ] &
~ 0xE000000000000FFFULL ) ;
F_41 ( V_85 , F_61 ( V_28 , V_92 ) ) ;
V_91 ++ ;
V_28 -= V_92 ;
} while ( V_28 > 0 );
}
}
static void F_62 ( struct V_34 * V_35 , T_6 V_69 , T_5 V_28 ,
enum V_97 V_98 , unsigned long V_99 )
{
struct V_6 * V_6 ;
#if V_63 > 0
struct V_66 * V_29 ;
#endif
unsigned long V_39 ;
T_6 V_100 ;
V_6 = F_53 ( V_35 ) ;
ASSERT ( V_6 ) ;
#ifdef F_49
if ( F_19 ( ( V_69 & V_6 -> V_106 ) != V_6 -> V_45 ) ) {
F_52 ( L_28 ,
V_69 ) ;
#ifdef F_63
if ( V_98 == V_107 ) {
F_41 ( F_60 ( V_69 ) , V_28 ) ;
}
#endif
return;
}
#endif
V_100 = V_69 & ~ V_46 ;
F_55 ( L_29 , V_55 , ( long ) V_69 , V_28 ) ;
V_69 ^= V_100 ;
V_28 += V_100 ;
V_28 = F_21 ( V_28 , V_92 ) ;
#ifdef F_63
if ( V_98 == V_107 )
F_59 ( V_6 , V_69 , V_28 ) ;
#endif
#if V_63 > 0
F_18 ( & V_6 -> V_64 , V_39 ) ;
V_29 = & ( V_6 -> V_68 [ V_6 -> V_65 ] ) ;
V_29 -> V_69 = V_69 ;
V_29 -> V_28 = V_28 ;
if ( F_31 ( ++ ( V_6 -> V_65 ) >= V_63 ) ) {
int V_67 = V_6 -> V_65 ;
F_32 ( & V_6 -> V_47 ) ;
while ( V_67 -- ) {
F_33 ( V_6 , V_29 -> V_69 , V_29 -> V_28 ) ;
F_34 ( V_6 , V_29 -> V_69 , V_29 -> V_28 ) ;
V_29 -- ;
}
V_6 -> V_65 = 0 ;
F_3 ( V_6 -> V_70 + V_71 ) ;
F_35 ( & V_6 -> V_47 ) ;
}
F_27 ( & V_6 -> V_64 , V_39 ) ;
#else
F_18 ( & V_6 -> V_47 , V_39 ) ;
F_33 ( V_6 , V_69 , V_28 ) ;
F_34 ( V_6 , V_69 , V_28 ) ;
F_3 ( V_6 -> V_70 + V_71 ) ;
F_27 ( & V_6 -> V_47 , V_39 ) ;
#endif
}
void F_64 ( struct V_34 * V_35 , T_6 V_69 , T_5 V_28 ,
enum V_97 V_98 , unsigned long V_99 )
{
F_62 ( V_35 , V_69 , V_28 , V_98 , V_99 ) ;
}
static void *
F_65 ( struct V_34 * V_35 , T_5 V_28 , T_6 * V_108 ,
T_7 V_39 , unsigned long V_99 )
{
struct V_6 * V_6 ;
void * V_85 ;
V_6 = F_53 ( V_35 ) ;
ASSERT ( V_6 ) ;
#ifdef F_66
{
struct V_88 * V_88 ;
V_88 = F_67 ( V_6 -> V_109 , V_39 , F_68 ( V_28 ) ) ;
if ( F_31 ( ! V_88 ) )
return NULL ;
V_85 = F_48 ( V_88 ) ;
}
#else
V_85 = ( void * ) F_69 ( V_39 , F_68 ( V_28 ) ) ;
#endif
if ( F_31 ( ! V_85 ) )
return NULL ;
memset ( V_85 , 0 , V_28 ) ;
* V_108 = F_50 ( V_85 ) ;
#ifdef F_49
ASSERT ( V_35 -> V_110 ) ;
if ( F_19 ( ( * V_108 & ~ V_35 -> V_110 ) == 0 ) ) {
F_52 ( L_30 ,
V_35 -> V_110 , * V_108 ) ;
return V_85 ;
}
#endif
* V_108 = F_58 ( & V_6 -> V_111 -> V_35 , V_85 ,
V_28 , 0 , 0 ) ;
return V_85 ;
}
static void F_70 ( struct V_34 * V_35 , T_5 V_28 , void * V_112 ,
T_6 V_108 , unsigned long V_99 )
{
F_64 ( V_35 , V_108 , V_28 , 0 , 0 ) ;
F_71 ( ( unsigned long ) V_112 , F_68 ( V_28 ) ) ;
}
static T_4 int
F_72 (
struct V_6 * V_6 ,
struct V_21 * V_22 ,
int V_23 )
{
struct V_21 * V_113 = V_22 ;
int V_114 = 0 ;
T_2 * V_115 = NULL ;
unsigned long V_116 = 0 ;
while ( V_23 -- > 0 ) {
int V_67 = V_22 -> V_25 ;
V_22 -> V_25 = 0 ;
#ifdef F_73
if ( V_117 )
F_5 ( L_31 ,
V_23 , V_22 -> V_24 , V_67 ,
F_8 ( V_22 ) ) ;
#else
F_74 ( L_32 ,
V_23 , V_22 -> V_24 , V_67 ,
F_8 ( V_22 ) ) ;
#endif
if ( V_22 -> V_24 & V_118 ) {
T_3 V_8 = V_22 -> V_24 & ~ V_118 ;
V_116 = ( unsigned long ) V_8 & ~ V_46 ;
V_22 -> V_24 = 0 ;
if ( V_114 )
V_113 = F_9 ( V_113 ) ;
V_113 -> V_24 = V_8 | V_6 -> V_45 ;
V_115 = & ( V_6 -> V_10 [ V_8 >> V_31 ] ) ;
V_114 ++ ;
}
if ( V_67 ) {
unsigned long V_112 = ( unsigned long ) F_8 ( V_22 ) ;
ASSERT ( V_115 ) ;
V_113 -> V_25 += V_67 ;
V_67 += V_116 ;
V_116 = 0 ;
V_67 = F_21 ( V_67 , V_92 ) ;
do {
F_40 ( V_115 , V_112 ) ;
V_112 += V_92 ;
V_67 -= V_92 ;
V_115 ++ ;
} while ( V_67 > 0 );
}
V_22 = F_9 ( V_22 ) ;
}
F_56 () ;
#ifdef F_73
V_117 = 0 ;
#endif
return ( V_114 ) ;
}
static T_4 int
F_75 ( struct V_6 * V_6 , struct V_34 * V_35 ,
struct V_21 * V_22 ,
int V_23 )
{
struct V_21 * V_119 ;
unsigned long V_120 ;
unsigned long V_121 ;
struct V_21 * V_113 ;
unsigned long V_116 , V_122 ;
int V_114 = 0 ;
unsigned int V_123 = F_76 ( V_35 ) ;
int V_124 ;
while ( V_23 > 0 ) {
unsigned long V_112 = ( unsigned long ) F_8 ( V_22 ) ;
V_113 = V_119 = V_22 ;
V_122 = V_120 = V_121 = V_22 -> V_125 ;
V_121 += V_112 ;
V_116 = V_112 & ~ V_46 ;
V_22 -> V_24 = V_22 -> V_25 = 0 ;
while ( -- V_23 > 0 ) {
unsigned long V_112 ;
V_22 = F_9 ( V_22 ) ;
V_22 -> V_24 = V_22 -> V_25 = 0 ;
ASSERT ( V_22 -> V_125 <= V_104 ) ;
if ( ( ( V_122 + V_116 + V_22 -> V_125 + ~ V_46 ) & V_46 )
> V_104 )
break;
if ( V_122 + V_22 -> V_125 > V_123 )
break;
V_112 = ( unsigned long ) F_8 ( V_22 ) ;
if ( V_121 == V_112 )
{
V_120 += V_22 -> V_125 ;
V_121 += V_22 -> V_125 ;
V_122 += V_22 -> V_125 ;
continue;
}
#ifdef F_73
V_117 = ( V_120 > V_92 ) ;
#endif
V_119 -> V_25 = V_120 ;
V_119 = V_22 ;
V_120 = V_22 -> V_125 ;
if ( F_77 ( V_121 , V_112 ) )
{
V_121 = V_120 + V_112 ;
V_122 += V_120 ;
continue;
} else {
break;
}
}
V_119 -> V_25 = V_120 ;
V_122 = ( V_122 + V_116 + ~ V_46 ) & V_46 ;
ASSERT ( V_122 <= V_104 ) ;
V_124 = F_28 ( V_6 , V_35 , V_122 ) ;
if ( V_124 < 0 ) {
V_113 -> V_25 = 0 ;
return - 1 ;
}
V_113 -> V_24 = ( T_6 ) ( V_118 | ( V_124 << V_31 )
| V_116 ) ;
V_114 ++ ;
}
return V_114 ;
}
static int F_78 ( struct V_34 * V_35 , struct V_21 * V_126 ,
int V_23 , enum V_97 V_98 ,
unsigned long V_99 )
{
struct V_6 * V_6 ;
int V_127 , V_128 = 0 ;
#ifdef F_37
unsigned long V_39 ;
#endif
#ifdef F_79
struct V_21 * V_129 ;
#endif
F_74 ( L_33 , V_55 , V_23 ) ;
V_6 = F_53 ( V_35 ) ;
ASSERT ( V_6 ) ;
#ifdef F_79
ASSERT ( F_51 ( V_35 ) -> V_103 ) ;
if ( F_19 ( ( V_6 -> V_103 & ~ F_51 ( V_35 ) -> V_103 ) == 0 ) ) {
F_80 (sglist, sg, nents, filled) {
V_129 -> V_25 = V_129 -> V_125 ;
V_129 -> V_24 = F_50 ( F_8 ( V_129 ) ) ;
}
return V_128 ;
}
#endif
if ( V_23 == 1 ) {
V_126 -> V_25 = V_126 -> V_125 ;
V_126 -> V_24 = F_58 ( V_35 , F_8 ( V_126 ) , V_126 -> V_125 , V_98 , V_99 ) ;
return 1 ;
}
#ifdef F_37
F_18 ( & V_6 -> V_47 , V_39 ) ;
if ( F_6 ( V_6 , L_34 ) )
{
F_7 ( V_6 , V_126 , V_23 ) ;
F_54 ( L_34 ) ;
}
F_27 ( & V_6 -> V_47 , V_39 ) ;
#endif
F_26 ( V_6 -> V_44 ) ;
V_127 = F_75 ( V_6 , V_35 , V_126 , V_23 ) ;
if ( V_127 < 0 ) {
F_81 ( V_35 , V_126 , V_23 , V_98 , V_99 ) ;
return 0 ;
}
V_128 = F_72 ( V_6 , V_126 , V_23 ) ;
#ifdef F_37
F_18 ( & V_6 -> V_47 , V_39 ) ;
if ( F_6 ( V_6 , L_35 ) )
{
F_7 ( V_6 , V_126 , V_23 ) ;
F_54 ( L_36 ) ;
}
F_27 ( & V_6 -> V_47 , V_39 ) ;
#endif
ASSERT ( V_127 == V_128 ) ;
F_74 ( L_37 , V_55 , V_128 ) ;
return V_128 ;
}
static void F_81 ( struct V_34 * V_35 , struct V_21 * V_126 ,
int V_23 , enum V_97 V_98 ,
unsigned long V_99 )
{
#ifdef F_37
struct V_6 * V_6 ;
unsigned long V_39 ;
#endif
F_74 ( L_38 ,
V_55 , V_23 , F_8 ( V_126 ) , V_126 -> V_125 ) ;
#ifdef F_37
V_6 = F_53 ( V_35 ) ;
ASSERT ( V_6 ) ;
F_18 ( & V_6 -> V_47 , V_39 ) ;
F_6 ( V_6 , L_39 ) ;
F_27 ( & V_6 -> V_47 , V_39 ) ;
#endif
while ( V_23 && V_126 -> V_25 ) {
F_64 ( V_35 , V_126 -> V_24 ,
V_126 -> V_25 , V_98 , V_99 ) ;
V_126 = F_9 ( V_126 ) ;
V_23 -- ;
}
F_74 ( L_40 , V_55 , V_23 ) ;
#ifdef F_37
F_18 ( & V_6 -> V_47 , V_39 ) ;
F_6 ( V_6 , L_41 ) ;
F_27 ( & V_6 -> V_47 , V_39 ) ;
#endif
}
static void
F_82 ( struct V_6 * V_6 )
{
int V_130 ;
int V_131 = 0 ;
struct V_132 * V_34 = NULL ;
#ifdef F_45
unsigned long V_133 ;
#endif
V_6 -> V_45 = F_3 ( V_6 -> V_70 + V_2 ) & ~ 0x1UL ;
V_6 -> V_106 = F_3 ( V_6 -> V_70 + V_3 ) | 0xFFFFFFFF00000000UL ;
V_6 -> V_134 = ~ V_6 -> V_106 + 1 ;
F_2 ( L_42 ,
V_55 , V_6 -> V_70 , V_6 -> V_45 , V_6 -> V_106 ,
V_6 -> V_134 >> 20 ) ;
switch ( V_92 ) {
case 4 * 1024 : V_130 = 0 ; break;
case 8 * 1024 : V_130 = 1 ; break;
case 16 * 1024 : V_130 = 2 ; break;
case 64 * 1024 : V_130 = 3 ; break;
default:
F_54 ( V_135 L_43 ,
V_92 >> 10 ) ;
break;
}
F_46 ( V_130 , V_6 -> V_70 + V_4 ) ;
V_6 -> V_93 = ( V_6 -> V_134 / V_92 ) * V_77 ;
V_6 -> V_10 = ( void * ) F_69 ( V_136 ,
F_68 ( V_6 -> V_93 ) ) ;
if ( ! V_6 -> V_10 )
F_54 ( V_135 L_44 ) ;
memset ( V_6 -> V_10 , 0 , V_6 -> V_93 ) ;
F_2 ( L_45 , V_55 ,
V_92 >> 10 , V_6 -> V_10 , V_6 -> V_93 ) ;
ASSERT ( F_16 ( ( unsigned long ) V_6 -> V_10 , 4 * 1024 ) == ( unsigned long ) V_6 -> V_10 ) ;
F_46 ( F_50 ( V_6 -> V_10 ) , V_6 -> V_70 + V_5 ) ;
F_83 (device)
V_131 |= F_84 ( V_34 , V_137 ) ;
if ( V_131 && V_138 ) {
F_5 (KERN_INFO PFX L_46 ,
ioc->iov_size/2 >> 20 , ioc->ibase + ioc->iov_size/2 ) ;
V_6 -> V_93 /= 2 ;
( ( T_2 * ) V_6 -> V_10 ) [ F_39 ( V_6 -> V_134 / 2 ) ] = V_139 ;
}
#ifdef F_45
if ( ! V_94 ) {
char * V_140 = L_47 ;
int V_141 = 16 ;
void * V_142 , * V_85 ;
V_85 = ( void * ) F_69 ( V_136 , F_68 ( V_92 ) ) ;
if ( ! V_85 )
F_54 ( V_135 L_48 ) ;
V_142 = V_85 ;
for ( ; ( T_2 ) V_142 < V_85 + V_92 ; V_142 += V_141 )
memcpy ( V_142 , V_140 , V_141 ) ;
V_94 = F_50 ( V_85 ) ;
F_2 ( L_49 , V_55 , V_94 ) ;
}
for ( V_133 = 0 ; V_133 < ( V_6 -> V_93 / V_77 ) ; V_133 ++ )
( ( T_2 * ) V_6 -> V_10 ) [ V_133 ] = ( 0x80000000000000FF | V_94 ) ;
#endif
F_46 ( V_6 -> V_45 | ( F_11 ( V_6 -> V_134 ) + V_31 ) , V_6 -> V_70 + V_71 ) ;
F_3 ( V_6 -> V_70 + V_71 ) ;
F_46 ( V_6 -> V_45 | 1 , V_6 -> V_70 + V_2 ) ;
F_3 ( V_6 -> V_70 + V_2 ) ;
}
static void T_8
F_85 ( struct V_6 * V_6 )
{
F_86 ( & V_6 -> V_47 ) ;
#if V_63 > 0
F_86 ( & V_6 -> V_64 ) ;
#endif
V_6 -> V_17 = V_6 -> V_93 / V_77 ;
V_6 -> V_17 >>= 3 ;
F_2 ( L_50 , V_55 , V_6 -> V_17 ) ;
V_6 -> V_13 = ( char * ) F_69 ( V_136 ,
F_68 ( V_6 -> V_17 ) ) ;
if ( ! V_6 -> V_13 )
F_54 ( V_135 L_51 ) ;
memset ( V_6 -> V_13 , 0 , V_6 -> V_17 ) ;
V_6 -> V_44 = ( unsigned long * ) V_6 -> V_13 ;
#ifdef F_37
V_6 -> V_13 [ 0 ] = 0x1 ;
V_6 -> V_10 [ 0 ] = 0x8000000000000000ULL | V_139 ;
#endif
#ifdef F_45
V_6 -> V_13 [ V_6 -> V_17 - 1 ] |= 0x80UL ;
V_6 -> V_10 [ ( V_6 -> V_93 / V_77 ) - 1 ] = ( 0x80000000000000FF
| V_94 ) ;
#endif
F_2 ( L_52 , V_55 ,
V_6 -> V_17 , ( void * ) V_6 -> V_13 ) ;
}
static void T_8
F_87 ( struct V_6 * V_6 )
{
struct V_132 * V_143 = NULL ;
struct V_144 * V_145 = NULL ;
V_143 = F_88 ( sizeof( * V_143 ) , V_136 ) ;
if ( ! V_143 )
F_54 ( V_135 L_53 ) ;
V_145 = F_88 ( sizeof( * V_145 ) , V_136 ) ;
if ( ! V_145 )
F_54 ( V_135 L_54 ) ;
V_145 -> V_146 = V_6 ;
V_143 -> V_147 = V_145 ;
V_143 -> V_103 = 0xFFFFFFFFUL ;
#ifdef F_89
V_143 -> V_35 . V_148 = & V_149 ;
#endif
V_6 -> V_111 = V_143 ;
}
static void T_8
F_90 ( struct V_6 * V_6 )
{
unsigned long V_150 ;
unsigned int V_58 ;
if ( V_6 -> V_151 < 0x20 )
F_54 ( V_135 L_55 ) ;
V_6 -> V_103 = ( 0x1UL << 39 ) - 1 ;
for ( V_58 = 0 ; V_58 < ( 8 * 8 ) ; V_58 += 8 ) {
V_150 = F_3 ( V_6 -> V_70 + V_152 + V_58 ) ;
V_150 &= ~ V_153 ;
F_46 ( V_150 , V_6 -> V_70 + V_152 + V_58 ) ;
}
}
static void F_91 ( unsigned long V_1 , struct V_6 * V_6 )
{
struct V_154 * V_155 ;
V_6 -> V_156 = V_157 ;
V_157 = V_6 ;
V_6 -> V_70 = F_92 ( V_1 , 0x1000 ) ;
V_6 -> V_158 = F_3 ( V_6 -> V_70 + V_159 ) ;
V_6 -> V_151 = F_3 ( V_6 -> V_70 + V_160 ) & 0xFFUL ;
V_6 -> V_103 = 0xFFFFFFFFFFFFFFFFUL ;
for ( V_155 = V_161 ; V_155 < V_161 + F_93 ( V_161 ) ; V_155 ++ ) {
if ( V_6 -> V_158 == V_155 -> V_158 ) {
V_6 -> V_162 = V_155 -> V_162 ;
if ( V_155 -> V_163 )
( V_155 -> V_163 ) ( V_6 ) ;
}
}
V_92 = ( 1 << V_31 ) ;
V_46 = ~ ( V_92 - 1 ) ;
F_2 ( L_56 , V_55 ,
V_87 >> 10 , V_92 >> 10 ) ;
if ( ! V_6 -> V_162 ) {
V_6 -> V_162 = F_94 ( 24 , V_136 ) ;
if ( V_6 -> V_162 )
sprintf ( ( char * ) V_6 -> V_162 , L_57 ,
V_6 -> V_158 & 0xFFFF , ( V_6 -> V_158 >> 16 ) & 0xFFFF ) ;
else
V_6 -> V_162 = L_58 ;
}
F_82 ( V_6 ) ;
F_85 ( V_6 ) ;
F_87 ( V_6 ) ;
if ( ( long ) ~ V_46 > ( long ) V_164 )
V_164 = ~ V_46 ;
F_5 (KERN_INFO PFX
L_59 ,
ioc->name, (ioc->rev >> 4) & 0xF , ioc->rev & 0xF ,
hpa, ioc->iov_size >> 20 , ioc->ibase) ;
}
static void *
F_95 ( struct V_165 * V_166 , T_9 * V_167 )
{
struct V_6 * V_6 ;
T_9 V_168 = * V_167 ;
for ( V_6 = V_157 ; V_6 ; V_6 = V_6 -> V_156 )
if ( ! V_168 -- )
return V_6 ;
return NULL ;
}
static void *
F_96 ( struct V_165 * V_166 , void * V_169 , T_9 * V_167 )
{
struct V_6 * V_6 = V_169 ;
++ * V_167 ;
return V_6 -> V_156 ;
}
static void
F_97 ( struct V_165 * V_166 , void * V_169 )
{
}
static int
F_98 ( struct V_165 * V_166 , void * V_169 )
{
struct V_6 * V_6 = V_169 ;
unsigned long * V_32 = ( unsigned long * ) V_6 -> V_13 ;
int V_58 , V_170 = 0 ;
F_99 ( V_166 , L_60 ,
V_6 -> V_162 , ( ( V_6 -> V_151 >> 4 ) & 0xF ) , ( V_6 -> V_151 & 0xF ) ) ;
#ifdef F_66
if ( V_6 -> V_109 != V_171 )
F_99 ( V_166 , L_61 , V_6 -> V_109 ) ;
#endif
F_99 ( V_166 , L_62 , ( ( V_6 -> V_93 >> 3 ) * V_92 ) / ( 1024 * 1024 ) ) ;
F_99 ( V_166 , L_63 , V_92 / 1024 ) ;
for ( V_58 = 0 ; V_58 < ( V_6 -> V_17 / sizeof( unsigned long ) ) ; ++ V_58 , ++ V_32 )
V_170 += F_100 ( * V_32 ) ;
F_99 ( V_166 , L_64 , V_6 -> V_93 >> 3 ) ;
F_99 ( V_166 , L_65 , V_170 ) ;
#ifdef F_29
{
unsigned long V_58 = 0 , V_172 = 0 , F_61 , V_173 ;
F_61 = V_173 = V_6 -> V_73 [ 0 ] ;
for ( V_58 = 0 ; V_58 < V_75 ; V_58 ++ ) {
V_172 += V_6 -> V_73 [ V_58 ] ;
if ( V_6 -> V_73 [ V_58 ] > V_173 ) V_173 = V_6 -> V_73 [ V_58 ] ;
if ( V_6 -> V_73 [ V_58 ] < F_61 ) F_61 = V_6 -> V_73 [ V_58 ] ;
}
V_172 /= V_75 ;
F_99 ( V_166 , L_66 ,
F_61 , V_172 , V_173 ) ;
}
#endif
#ifndef F_49
F_99 ( V_166 , L_67 ) ;
#endif
return 0 ;
}
static int
F_101 ( struct V_174 * V_174 , struct V_175 * V_175 )
{
return F_102 ( V_175 , & V_176 ) ;
}
static void T_8
F_103 ( void )
{
struct V_177 * V_98 ;
V_98 = F_104 ( L_68 , NULL ) ;
if ( ! V_98 )
return;
F_105 ( V_157 -> V_162 , 0 , V_98 , & V_178 ) ;
}
static void
F_106 ( struct V_179 * V_148 )
{
T_10 V_180 , V_181 ;
T_11 V_182 ;
struct V_6 * V_6 ;
if ( ! F_107 ( V_148 ) )
F_54 ( V_135 L_69 , V_148 -> V_183 ) ;
if ( F_107 ( V_148 ) -> V_146 )
return;
V_180 = F_108 ( F_107 ( V_148 ) -> V_184 ) ;
if ( ! V_180 )
return;
do {
for ( V_6 = V_157 ; V_6 ; V_6 = V_6 -> V_156 )
if ( V_6 -> V_180 == V_180 ) {
F_107 ( V_148 ) -> V_146 = V_6 ;
return;
}
V_182 = F_109 ( V_180 , & V_181 ) ;
V_180 = V_181 ;
} while ( F_110 ( V_182 ) );
F_5 ( V_72 L_70 , F_111 ( V_148 ) , V_148 -> V_183 ) ;
}
static void T_8
F_112 ( struct V_6 * V_6 , T_10 V_180 )
{
#ifdef F_66
unsigned int V_109 ;
V_109 = F_113 ( V_180 ) ;
if ( V_109 != V_171 && ! F_114 ( V_109 ) )
V_109 = V_171 ;
V_6 -> V_109 = V_109 ;
#endif
}
static void F_115 ( struct V_6 * V_6 )
{
T_10 V_180 = V_6 -> V_180 ;
T_11 V_182 ;
T_2 V_1 , V_125 ;
struct V_185 * V_186 ;
V_187 = V_6 -> V_156 ;
V_182 = F_116 ( V_180 , & V_1 , & V_125 ) ;
if ( F_117 ( V_182 ) )
goto V_188;
V_182 = F_118 ( V_180 , & V_186 ) ;
if ( F_117 ( V_182 ) )
goto V_188;
if ( strncmp ( L_71 , V_186 -> V_189 . string , 7 ) == 0 ) {
V_1 += V_190 ;
if ( ! V_31 )
V_31 = F_61 ( V_191 , 16 ) ;
}
F_119 ( V_186 ) ;
if ( ! V_31 )
V_31 = 12 ;
F_91 ( V_1 , V_6 ) ;
F_112 ( V_6 , V_180 ) ;
return;
V_188:
F_119 ( V_6 ) ;
}
static int F_120 ( struct V_192 * V_34 ,
const struct V_193 * V_194 )
{
struct V_6 * V_6 ;
V_6 = F_88 ( sizeof( * V_6 ) , V_136 ) ;
if ( ! V_6 )
return - V_195 ;
V_6 -> V_156 = V_187 ;
V_187 = V_6 ;
V_6 -> V_180 = V_34 -> V_180 ;
return 1 ;
}
static int T_8 F_121 ( void )
{
return F_122 ( & V_196 ) ;
}
static int T_8
F_123 ( void )
{
if ( ! F_124 ( L_72 ) && ! F_124 ( L_73 ) )
return 0 ;
#if F_125 ( V_197 )
if ( F_126 () ) {
V_198 = & V_199 ;
if ( F_127 ( 64 * ( 1 << 20 ) ) != 0 )
F_54 ( L_74
L_75 ) ;
F_128 ( L_76 ) ;
return 0 ;
}
#endif
while ( V_187 )
F_115 ( V_187 ) ;
if ( ! V_157 ) {
#ifdef V_197
V_198 = & V_199 ;
if ( F_127 ( 64 * ( 1 << 20 ) ) != 0 )
F_54 ( L_77
L_78 ) ;
F_128 ( L_76 ) ;
#else
F_54 ( L_79 ) ;
#endif
return 0 ;
}
#if F_125 ( V_197 ) || F_125 ( V_200 )
if ( F_124 ( L_73 ) ) {
extern void V_201 ( void ) ;
V_201 () ;
}
#endif
#ifdef F_89
{
struct V_179 * V_202 = NULL ;
while ( ( V_202 = F_129 ( V_202 ) ) != NULL )
F_106 ( V_202 ) ;
}
#endif
#ifdef F_130
F_103 () ;
#endif
return 0 ;
}
static int T_8
F_131 ( char * V_203 )
{
V_138 = 0 ;
return 1 ;
}
static int F_132 ( struct V_34 * V_35 , T_2 V_53 )
{
return ( ( V_53 & 0xFFFFFFFFUL ) == 0xFFFFFFFFUL ) ;
}
static int F_133 ( struct V_34 * V_35 , T_6 V_204 )
{
return 0 ;
}
static int T_8
F_134 ( char * V_203 )
{
unsigned long V_205 ;
V_205 = F_135 ( V_203 , & V_203 ) ;
switch ( V_205 ) {
case 4096 :
case 8192 :
case 16384 :
case 65536 :
V_31 = F_136 ( V_205 ) - 1 ;
break;
default:
F_5 ( L_80 ,
V_55 , V_205 ) ;
}
return 1 ;
}
void F_137 ( void )
{
V_198 = & V_206 ;
}
