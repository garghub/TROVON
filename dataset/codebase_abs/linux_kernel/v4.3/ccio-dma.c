static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , T_1 V_4 )
{
unsigned int V_5 = V_4 >> V_6 ;
unsigned int V_7 ;
unsigned long V_8 ;
#ifdef F_2
unsigned long V_9 = F_3 ( 16 ) ;
#endif
F_4 ( V_5 == 0 ) ;
F_4 ( ( V_5 * V_10 ) > V_11 ) ;
F_5 ( L_1 ,
V_12 , V_4 , V_5 ) ;
V_8 = F_6 ( ( unsigned long long ) F_7 ( V_3 ) + 1 ,
1ULL << V_6 ) >> V_6 ;
if ( V_5 <= 8 ) {
#if 0
unsigned long mask = ~(~0UL >> pages_needed);
CCIO_FIND_FREE_MAPPING(ioc, res_idx, mask, 8);
#else
F_8 ( V_1 , V_7 , 0xff , 8 ) ;
#endif
} else if ( V_5 <= 16 ) {
F_8 ( V_1 , V_7 , 0xffff , 16 ) ;
} else if ( V_5 <= 32 ) {
F_8 ( V_1 , V_7 , ~ ( unsigned int ) 0 , 32 ) ;
#ifdef F_9
} else if ( V_5 <= 64 ) {
F_8 ( V_1 , V_7 , ~ 0UL , 64 ) ;
#endif
} else {
F_10 ( L_2 ,
__FILE__ , V_12 , V_5 ) ;
}
F_10 ( L_3 , __FILE__ ,
V_12 ) ;
V_13:
F_5 ( L_4 ,
V_12 , V_7 , V_1 -> V_14 ) ;
#ifdef F_2
{
unsigned long V_15 = F_3 ( 16 ) ;
unsigned long V_16 = V_15 - V_9 ;
V_9 = ( V_15 < V_9 ) ? - ( V_16 ) : ( V_16 ) ;
}
V_1 -> V_17 [ V_1 -> V_18 ++ ] = V_9 ;
V_1 -> V_18 &= V_19 - 1 ;
V_1 -> V_20 += V_5 ;
#endif
return V_7 << 3 ;
}
static void
F_11 ( struct V_1 * V_1 , T_2 V_21 , unsigned long V_22 )
{
unsigned long V_23 = F_12 ( V_21 ) ;
unsigned int V_7 = F_13 ( V_23 ) >> 3 ;
F_4 ( V_22 == 0 ) ;
F_4 ( ( V_22 * V_10 ) > V_11 ) ;
F_4 ( V_22 > V_24 ) ;
F_5 ( L_5 ,
V_12 , V_7 , V_22 ) ;
#ifdef F_2
V_1 -> V_20 -= V_22 ;
#endif
if( V_22 <= 8 ) {
#if 0
unsigned long mask = ~(~0UL >> pages_mapped);
CCIO_FREE_MAPPINGS(ioc, res_idx, mask, 8);
#else
F_14 ( V_1 , V_7 , 0xffUL , 8 ) ;
#endif
} else if( V_22 <= 16 ) {
F_14 ( V_1 , V_7 , 0xffffUL , 16 ) ;
} else if( V_22 <= 32 ) {
F_14 ( V_1 , V_7 , ~ ( unsigned int ) 0 , 32 ) ;
#ifdef F_9
} else if( V_22 <= 64 ) {
F_14 ( V_1 , V_7 , ~ 0UL , 64 ) ;
#endif
} else {
F_10 ( L_6 , __FILE__ ,
V_12 ) ;
}
}
static void T_3
F_15 ( T_4 * V_25 , T_5 V_26 , unsigned long V_27 ,
unsigned long V_28 )
{
register unsigned long V_29 ;
register unsigned long V_30 ;
F_4 ( V_26 != V_31 ) ;
F_16 ( V_26 , 1 ) ;
V_29 = F_17 ( V_27 ) ;
asm volatile("depw %1,31,12,%0" : "+r" (pa) : "r" (hints));
( ( V_32 * ) V_25 ) [ 1 ] = ( V_32 ) V_29 ;
#ifdef F_9
asm volatile ("extrd,u %1,15,4,%0" : "=r" (ci) : "r" (pa));
asm volatile ("extrd,u %1,31,16,%0" : "+r" (pa) : "r" (pa));
asm volatile ("depd %1,35,4,%0" : "+r" (pa) : "r" (ci));
#else
V_29 = 0 ;
#endif
asm volatile ("lci %%r0(%%sr1, %1), %0" : "=r" (ci) : "r" (vba));
asm volatile ("extru %1,19,12,%0" : "+r" (ci) : "r" (ci));
asm volatile ("depw %1,15,12,%0" : "+r" (pa) : "r" (ci));
( ( V_32 * ) V_25 ) [ 0 ] = ( V_32 ) V_29 ;
asm volatile("fdc %%r0(%0)" : : "r" (pdir_ptr));
asm volatile("sync");
}
static T_3 void
F_18 ( struct V_1 * V_1 , T_2 V_23 , T_1 V_33 )
{
V_32 V_34 = 1 << V_1 -> V_35 ;
V_23 &= V_36 ;
V_33 += V_34 ;
while( V_33 > V_34 ) {
F_19 ( V_37 | V_23 , & V_1 -> V_38 -> V_39 ) ;
V_23 += V_34 ;
V_33 -= V_34 ;
}
}
static T_3 void
F_20 ( struct V_1 * V_1 , T_2 V_21 , T_1 V_33 )
{
V_32 V_23 = ( V_32 ) F_12 ( V_21 ) ;
T_1 V_40 ;
V_40 = V_33 = F_6 ( V_33 , V_10 ) ;
while( V_33 > 0 ) {
unsigned int V_41 = F_13 ( V_23 ) ;
char * V_25 = ( char * ) & ( V_1 -> V_42 [ V_41 ] ) ;
F_4 ( V_41 >= ( V_1 -> V_43 / sizeof( T_4 ) ) ) ;
V_25 [ 7 ] = 0 ;
asm volatile("fdc %%r0(%0)" : : "r" (pdir_ptr[7]));
V_23 += V_10 ;
V_33 -= V_10 ;
}
asm volatile("sync");
F_18 ( V_1 , F_12 ( V_21 ) , V_40 ) ;
}
static int
F_21 ( struct V_2 * V_3 , T_4 V_44 )
{
if( V_3 == NULL ) {
F_22 (KERN_ERR MODULE_NAME L_7 ) ;
F_23 () ;
return 0 ;
}
return ( int ) ( V_44 == 0xffffffffUL ) ;
}
static T_2
F_24 ( struct V_2 * V_3 , void * V_45 , T_1 V_4 ,
enum V_46 V_47 )
{
int V_41 ;
struct V_1 * V_1 ;
unsigned long V_48 ;
T_2 V_23 ;
T_2 V_49 ;
T_4 * V_50 ;
unsigned long V_51 = V_52 [ ( int ) V_47 ] ;
F_4 ( ! V_3 ) ;
V_1 = F_25 ( V_3 ) ;
F_4 ( V_4 <= 0 ) ;
V_49 = ( ( unsigned long ) V_45 ) & ~ V_36 ;
V_4 = F_6 ( V_4 + V_49 , V_10 ) ;
F_26 ( & V_1 -> V_53 , V_48 ) ;
#ifdef F_2
V_1 -> V_54 ++ ;
V_1 -> V_55 += V_4 >> V_6 ;
#endif
V_41 = F_1 ( V_1 , V_3 , V_4 ) ;
V_23 = ( T_2 ) F_27 ( V_41 ) ;
V_50 = & ( V_1 -> V_42 [ V_41 ] ) ;
F_28 ( L_8 ,
V_12 , V_45 , ( long ) V_23 | V_49 , V_4 ) ;
if( ( V_4 % V_56 ) || ( ( unsigned long ) V_45 % V_56 ) )
V_51 |= V_57 ;
while( V_4 > 0 ) {
F_15 ( V_50 , V_31 , ( unsigned long ) V_45 , V_51 ) ;
F_28 ( L_9 ,
V_50 ,
( V_32 ) ( ( ( V_32 * ) V_50 ) [ 0 ] ) ,
( V_32 ) ( ( ( V_32 * ) V_50 ) [ 1 ] ) ) ;
++ V_50 ;
V_45 += V_10 ;
V_4 -= V_10 ;
}
F_29 ( & V_1 -> V_53 , V_48 ) ;
return F_30 ( V_23 , V_49 ) ;
}
static void
F_31 ( struct V_2 * V_3 , T_2 V_21 , T_1 V_4 ,
enum V_46 V_47 )
{
struct V_1 * V_1 ;
unsigned long V_48 ;
T_2 V_49 = V_21 & ~ V_36 ;
F_4 ( ! V_3 ) ;
V_1 = F_25 ( V_3 ) ;
F_28 ( L_10 ,
V_12 , ( long ) V_21 , V_4 ) ;
V_21 ^= V_49 ;
V_4 += V_49 ;
V_4 = F_6 ( V_4 , V_10 ) ;
F_26 ( & V_1 -> V_53 , V_48 ) ;
#ifdef F_2
V_1 -> V_58 ++ ;
V_1 -> V_59 += V_4 >> V_6 ;
#endif
F_20 ( V_1 , V_21 , V_4 ) ;
F_11 ( V_1 , V_21 , ( V_4 >> V_6 ) ) ;
F_29 ( & V_1 -> V_53 , V_48 ) ;
}
static void *
F_32 ( struct V_2 * V_3 , T_1 V_4 , T_2 * V_60 , T_6 V_61 )
{
void * V_62 ;
#if 0
if(!hwdev) {
*dma_handle = 0;
return 0;
}
#endif
V_62 = ( void * ) F_33 ( V_61 , F_34 ( V_4 ) ) ;
if ( V_62 ) {
memset ( V_62 , 0 , V_4 ) ;
* V_60 = F_24 ( V_3 , V_62 , V_4 , V_63 ) ;
}
return V_62 ;
}
static void
F_35 ( struct V_2 * V_3 , T_1 V_4 , void * V_64 ,
T_2 V_60 )
{
F_31 ( V_3 , V_60 , V_4 , 0 ) ;
F_36 ( ( unsigned long ) V_64 , F_34 ( V_4 ) ) ;
}
static int
F_37 ( struct V_2 * V_3 , struct V_65 * V_66 , int V_67 ,
enum V_46 V_47 )
{
struct V_1 * V_1 ;
int V_68 , V_69 = 0 ;
unsigned long V_48 ;
unsigned long V_51 = V_52 [ ( int ) V_47 ] ;
unsigned long V_70 = 0 , V_71 = 0 ;
int V_72 ;
F_4 ( ! V_3 ) ;
V_1 = F_25 ( V_3 ) ;
F_38 ( L_11 , V_12 , V_67 ) ;
if ( V_67 == 1 ) {
F_39 ( V_66 ) = F_24 ( V_3 ,
F_40 ( V_66 ) , V_66 -> V_73 ,
V_47 ) ;
F_41 ( V_66 ) = V_66 -> V_73 ;
return 1 ;
}
for( V_72 = 0 ; V_72 < V_67 ; V_72 ++ )
V_70 += V_66 [ V_72 ] . V_73 ;
F_26 ( & V_1 -> V_53 , V_48 ) ;
#ifdef F_2
V_1 -> V_74 ++ ;
#endif
V_68 = F_42 ( V_1 , V_3 , V_66 , V_67 , F_1 ) ;
V_69 = F_43 ( V_1 , V_66 , V_67 , V_51 , F_15 ) ;
F_29 ( & V_1 -> V_53 , V_48 ) ;
F_4 ( V_68 != V_69 ) ;
F_38 ( L_12 , V_12 , V_69 ) ;
for ( V_72 = 0 ; V_72 < V_69 ; V_72 ++ )
V_71 += F_41 ( V_66 + V_72 ) ;
F_4 ( V_71 != V_70 ) ;
return V_69 ;
}
static void
F_44 ( struct V_2 * V_3 , struct V_65 * V_66 , int V_67 ,
enum V_46 V_47 )
{
struct V_1 * V_1 ;
F_4 ( ! V_3 ) ;
V_1 = F_25 ( V_3 ) ;
F_38 ( L_13 ,
V_12 , V_67 , F_40 ( V_66 ) , V_66 -> V_73 ) ;
#ifdef F_2
V_1 -> V_75 ++ ;
#endif
while( F_41 ( V_66 ) && V_67 -- ) {
#ifdef F_2
V_1 -> V_76 += F_41 ( V_66 ) >> V_77 ;
#endif
F_31 ( V_3 , F_39 ( V_66 ) ,
F_41 ( V_66 ) , V_47 ) ;
++ V_66 ;
}
F_38 ( L_14 , V_12 , V_67 ) ;
}
static int F_45 ( struct V_78 * V_79 , void * V_80 )
{
struct V_1 * V_1 = V_81 ;
while ( V_1 != NULL ) {
unsigned int V_82 = V_1 -> V_83 << 3 ;
#ifdef F_2
unsigned long V_84 = 0 , V_85 , V_86 ;
int V_87 ;
#endif
F_46 ( V_79 , L_15 , V_1 -> V_88 ) ;
F_46 ( V_79 , L_16 ,
( V_1 -> V_89 ? L_17 : L_18 ) ) ;
F_46 ( V_79 , L_19 ,
V_82 * 8 , V_82 ) ;
#ifdef F_2
F_46 ( V_79 , L_20 ,
V_82 - V_1 -> V_20 , V_1 -> V_20 ,
( int ) ( V_1 -> V_20 * 100 / V_82 ) ) ;
#endif
F_46 ( V_79 , L_21 ,
V_1 -> V_83 , V_82 ) ;
#ifdef F_2
V_85 = V_86 = V_1 -> V_17 [ 0 ] ;
for( V_87 = 0 ; V_87 < V_19 ; ++ V_87 ) {
V_84 += V_1 -> V_17 [ V_87 ] ;
if( V_1 -> V_17 [ V_87 ] > V_86 )
V_86 = V_1 -> V_17 [ V_87 ] ;
if( V_1 -> V_17 [ V_87 ] < V_85 )
V_85 = V_1 -> V_17 [ V_87 ] ;
}
V_84 /= V_19 ;
F_46 ( V_79 , L_22 ,
V_85 , V_84 , V_86 ) ;
F_46 ( V_79 , L_23 ,
V_1 -> V_54 , V_1 -> V_55 ,
( int ) ( ( V_1 -> V_55 * 1000 ) / V_1 -> V_54 ) ) ;
V_85 = V_1 -> V_58 - V_1 -> V_75 ;
V_86 = V_1 -> V_59 - V_1 -> V_76 ;
F_46 ( V_79 , L_24 ,
V_85 , V_86 , ( int ) ( ( V_86 * 1000 ) / V_85 ) ) ;
F_46 ( V_79 , L_25 ,
V_1 -> V_74 , V_1 -> V_90 ,
( int ) ( ( V_1 -> V_90 * 1000 ) / V_1 -> V_74 ) ) ;
F_46 ( V_79 , L_26 ,
V_1 -> V_75 , V_1 -> V_76 ,
( int ) ( ( V_1 -> V_76 * 1000 ) / V_1 -> V_75 ) ) ;
#endif
V_1 = V_1 -> V_91 ;
}
return 0 ;
}
static int F_47 ( struct V_92 * V_92 , struct V_93 * V_93 )
{
return F_48 ( V_93 , & F_45 , NULL ) ;
}
static int F_49 ( struct V_78 * V_79 , void * V_80 )
{
struct V_1 * V_1 = V_81 ;
while ( V_1 != NULL ) {
F_50 ( V_79 , L_27 , V_94 , 32 , 4 , V_1 -> V_95 ,
V_1 -> V_83 , false ) ;
F_51 ( V_79 , '\n' ) ;
V_1 = V_1 -> V_91 ;
break;
}
return 0 ;
}
static int F_52 ( struct V_92 * V_92 , struct V_93 * V_93 )
{
return F_48 ( V_93 , & F_49 , NULL ) ;
}
static struct V_1 * F_53 ( int V_96 )
{
int V_72 ;
struct V_1 * V_1 ;
V_1 = V_81 ;
for ( V_72 = 0 ; V_72 < V_97 ; V_72 ++ ) {
if ( V_1 -> V_96 == V_96 )
return V_1 ;
V_1 = V_1 -> V_91 ;
}
return NULL ;
}
void * F_54 ( const struct V_98 * V_3 )
{
V_3 = F_55 ( V_3 , V_99 ) ;
if ( ! V_3 )
return NULL ;
return F_53 ( V_3 -> V_96 ) ;
}
void F_56 ( struct V_98 * V_100 , V_32 V_23 )
{
unsigned int V_41 ;
struct V_98 * V_3 = F_57 ( V_100 ) ;
struct V_1 * V_1 = F_54 ( V_3 ) ;
T_7 * V_101 ;
V_1 -> V_89 = 1 ;
V_101 = V_1 -> V_95 ;
V_41 = F_13 ( V_23 ) >> 3 ;
while ( V_41 < V_1 -> V_83 ) {
V_101 [ V_41 ] |= 0xff ;
V_41 += F_13 ( V_102 ) >> 3 ;
}
}
static void
F_58 ( struct V_1 * V_1 )
{
int V_72 ;
unsigned int V_103 ;
V_32 V_104 ;
V_104 = ( V_32 ) ( V_105 / F_59 ( & V_106 ) ) ;
if ( V_104 < ( 1 << ( 20 - V_77 ) ) ) {
V_104 = 1 << ( 20 - V_77 ) ;
#ifdef F_9
} else if ( V_104 > ( 1 << ( 30 - V_77 ) ) ) {
V_104 = 1 << ( 30 - V_77 ) ;
#endif
}
V_103 = F_34 ( V_104 << V_77 ) ;
V_104 = 1 << ( V_103 + V_77 ) ;
V_1 -> V_43 = ( V_104 / V_10 ) * sizeof( T_4 ) ;
F_4 ( V_1 -> V_43 > 8 * 1024 * 1024 ) ;
F_4 ( ( 1 << F_34 ( V_1 -> V_43 ) ) != ( V_1 -> V_43 >> V_77 ) ) ;
F_60 ( L_28 ,
V_12 , V_1 -> V_38 ,
( unsigned long ) V_105 >> ( 20 - V_77 ) ,
V_104 >> 20 ,
V_103 + V_77 ) ;
V_1 -> V_42 = ( T_4 * ) F_33 ( V_107 ,
F_34 ( V_1 -> V_43 ) ) ;
if( NULL == V_1 -> V_42 ) {
F_10 ( L_29 , V_12 ) ;
}
memset ( V_1 -> V_42 , 0 , V_1 -> V_43 ) ;
F_4 ( ( ( ( unsigned long ) V_1 -> V_42 ) & V_108 ) != ( unsigned long ) V_1 -> V_42 ) ;
F_60 ( L_30 , V_1 -> V_42 ) ;
V_1 -> V_83 = ( V_1 -> V_43 / sizeof( T_4 ) ) >> 3 ;
F_60 ( L_31 , V_12 , V_1 -> V_83 ) ;
V_1 -> V_95 = ( T_7 * ) F_33 ( V_107 ,
F_34 ( V_1 -> V_83 ) ) ;
if( NULL == V_1 -> V_95 ) {
F_10 ( L_32 , V_12 ) ;
}
memset ( V_1 -> V_95 , 0 , V_1 -> V_83 ) ;
V_1 -> V_14 = 16 ;
F_61 ( & V_1 -> V_53 ) ;
V_1 -> V_35 = F_34 ( V_104 ) + V_77 - V_109 ;
F_60 ( L_33 , V_1 -> V_35 ) ;
F_19 ( V_110 << V_1 -> V_35 ,
& V_1 -> V_38 -> V_111 ) ;
F_19 ( F_17 ( V_1 -> V_42 ) ,
& V_1 -> V_38 -> V_112 ) ;
F_19 ( V_113 , & V_1 -> V_38 -> V_114 ) ;
F_19 ( 0 , & V_1 -> V_38 -> V_115 ) ;
F_19 ( 0 , & V_1 -> V_38 -> V_116 ) ;
for( V_72 = 1 << V_109 ; V_72 ; V_72 -- ) {
F_19 ( ( V_117 | ( V_72 << V_1 -> V_35 ) ) ,
& V_1 -> V_38 -> V_39 ) ;
}
}
static void T_8
F_62 ( struct V_118 * V_119 , char * V_88 , void T_9 * V_120 )
{
int V_121 ;
V_119 -> V_122 = NULL ;
V_119 -> V_48 = V_123 ;
V_119 -> V_124 = ( unsigned long ) ( ( signed ) F_63 ( V_120 ) << 16 ) ;
V_119 -> V_125 = ( unsigned long ) ( ( signed ) ( F_63 ( V_120 + 4 ) << 16 ) - 1 ) ;
V_119 -> V_88 = V_88 ;
if ( V_119 -> V_125 + 1 == V_119 -> V_124 )
return;
V_121 = F_64 ( & V_126 , V_119 ) ;
if ( V_121 < 0 ) {
F_22 ( V_127 L_34 ,
V_12 , ( unsigned long ) V_119 -> V_124 , ( unsigned long ) V_119 -> V_125 ) ;
}
}
static void T_8 F_65 ( struct V_1 * V_1 )
{
struct V_118 * V_119 = V_1 -> V_128 ;
char * V_88 = F_66 ( 14 , V_107 ) ;
snprintf ( V_88 , 14 , L_35 , V_1 -> V_96 ) ;
F_62 ( V_119 , V_88 , & V_1 -> V_38 -> V_129 ) ;
F_62 ( V_119 + 1 , V_88 , & V_1 -> V_38 -> V_130 ) ;
}
static int F_67 ( struct V_118 * V_119 , unsigned long V_4 ,
unsigned long V_85 , unsigned long V_86 , unsigned long V_131 )
{
if ( V_86 <= V_85 )
return - V_132 ;
V_119 -> V_124 = ( V_86 - V_4 + 1 ) & ~ ( V_131 - 1 ) ;
V_119 -> V_125 = V_119 -> V_124 + V_4 ;
if ( ! F_64 ( & V_126 , V_119 ) )
return 0 ;
return F_67 ( V_119 , V_4 , V_85 , V_86 - V_4 , V_131 ) ;
}
static int F_68 ( struct V_118 * V_119 , unsigned long V_4 ,
unsigned long V_85 , unsigned long V_86 , unsigned long V_131 )
{
unsigned long V_124 , V_133 ;
if ( ! V_119 -> V_122 )
return F_67 ( V_119 , V_4 , V_85 , V_86 , V_131 ) ;
V_124 = ( V_119 -> V_124 - V_4 ) & ~ ( V_131 - 1 ) ;
V_133 = V_119 -> V_125 - V_124 + 1 ;
if ( V_124 >= V_85 ) {
if ( ! F_69 ( V_119 , V_124 , V_133 ) )
return 0 ;
}
V_124 = V_119 -> V_124 ;
V_133 = ( ( V_4 + V_119 -> V_125 + V_131 ) & ~ ( V_131 - 1 ) ) - V_124 ;
if ( V_124 + V_133 <= V_86 ) {
if ( ! F_69 ( V_119 , V_124 , V_133 ) )
return 0 ;
}
return - V_132 ;
}
int F_70 ( const struct V_98 * V_3 ,
struct V_118 * V_119 , unsigned long V_4 ,
unsigned long V_85 , unsigned long V_86 , unsigned long V_131 )
{
struct V_118 * V_122 = & V_126 ;
struct V_1 * V_1 = F_54 ( V_3 ) ;
if ( ! V_1 )
goto V_134;
V_122 = V_1 -> V_128 ;
if ( V_122 -> V_122 &&
! F_71 ( V_122 , V_119 , V_4 , V_85 , V_86 , V_131 , NULL , NULL ) )
return 0 ;
if ( ( V_122 + 1 ) -> V_122 &&
! F_71 ( V_122 + 1 , V_119 , V_4 , V_85 , V_86 , V_131 ,
NULL , NULL ) )
return 0 ;
if ( ! F_68 ( V_122 , V_4 , V_85 , V_86 , V_131 ) ) {
F_72 ( ( ( V_122 -> V_124 ) >> 16 ) | 0xffff0000 ,
& V_1 -> V_38 -> V_129 ) ;
F_72 ( ( ( V_122 -> V_125 ) >> 16 ) | 0xffff0000 ,
& V_1 -> V_38 -> V_135 ) ;
} else if ( ! F_68 ( V_122 + 1 , V_4 , V_85 , V_86 , V_131 ) ) {
V_122 ++ ;
F_72 ( ( ( V_122 -> V_124 ) >> 16 ) | 0xffff0000 ,
& V_1 -> V_38 -> V_130 ) ;
F_72 ( ( ( V_122 -> V_125 ) >> 16 ) | 0xffff0000 ,
& V_1 -> V_38 -> V_136 ) ;
} else {
return - V_132 ;
}
V_134:
return F_71 ( V_122 , V_119 , V_4 , V_85 , V_86 , V_131 , NULL , NULL ) ;
}
int F_73 ( const struct V_98 * V_3 ,
struct V_118 * V_119 )
{
struct V_118 * V_122 ;
struct V_1 * V_1 = F_54 ( V_3 ) ;
if ( ! V_1 ) {
V_122 = & V_126 ;
} else if ( ( V_1 -> V_128 -> V_124 <= V_119 -> V_124 ) &&
( V_119 -> V_125 <= V_1 -> V_128 -> V_125 ) ) {
V_122 = V_1 -> V_128 ;
} else if ( ( ( V_1 -> V_128 + 1 ) -> V_124 <= V_119 -> V_124 ) &&
( V_119 -> V_125 <= ( V_1 -> V_128 + 1 ) -> V_125 ) ) {
V_122 = V_1 -> V_128 + 1 ;
} else {
return - V_132 ;
}
return F_64 ( V_122 , V_119 ) ;
}
static int T_8 F_74 ( struct V_98 * V_3 )
{
int V_72 ;
struct V_1 * V_1 , * * V_137 = & V_81 ;
V_1 = F_75 ( sizeof( struct V_1 ) , V_107 ) ;
if ( V_1 == NULL ) {
F_22 (KERN_ERR MODULE_NAME L_36 ) ;
return 1 ;
}
V_1 -> V_88 = V_3 -> V_138 . V_139 == V_140 ? L_37 : L_38 ;
F_22 ( V_141 L_39 , V_1 -> V_88 ,
( unsigned long ) V_3 -> V_142 . V_124 ) ;
for ( V_72 = 0 ; V_72 < V_97 ; V_72 ++ ) {
V_137 = & ( * V_137 ) -> V_91 ;
}
* V_137 = V_1 ;
V_1 -> V_96 = V_3 -> V_96 ;
V_1 -> V_38 = F_76 ( V_3 -> V_142 . V_124 , 4096 ) ;
F_58 ( V_1 ) ;
F_65 ( V_1 ) ;
V_143 = & V_144 ;
V_3 -> V_3 . V_145 = F_75 ( sizeof( struct V_146 ) , V_107 ) ;
F_4 ( V_3 -> V_3 . V_145 == NULL ) ;
F_77 ( V_3 -> V_3 . V_145 ) -> V_147 = V_1 ;
#ifdef F_78
if ( V_97 == 0 ) {
F_79 ( V_148 , 0 , V_149 ,
& V_150 ) ;
F_79 ( V_148 L_40 , 0 , V_149 ,
& V_151 ) ;
}
#endif
V_97 ++ ;
F_80 () ;
return 0 ;
}
void T_8 F_81 ( void )
{
F_82 ( & V_106 ) ;
}
