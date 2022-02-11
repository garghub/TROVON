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
static T_2
F_31 ( struct V_2 * V_3 , struct V_58 * V_58 , unsigned long V_49 ,
T_1 V_4 , enum V_46 V_47 ,
unsigned long V_59 )
{
return F_24 ( V_3 , F_32 ( V_58 ) + V_49 , V_4 ,
V_47 ) ;
}
static void
F_33 ( struct V_2 * V_3 , T_2 V_21 , T_1 V_4 ,
enum V_46 V_47 , unsigned long V_59 )
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
V_1 -> V_60 ++ ;
V_1 -> V_61 += V_4 >> V_6 ;
#endif
F_20 ( V_1 , V_21 , V_4 ) ;
F_11 ( V_1 , V_21 , ( V_4 >> V_6 ) ) ;
F_29 ( & V_1 -> V_53 , V_48 ) ;
}
static void *
F_34 ( struct V_2 * V_3 , T_1 V_4 , T_2 * V_62 , T_6 V_63 ,
unsigned long V_59 )
{
void * V_64 ;
#if 0
if(!hwdev) {
*dma_handle = 0;
return 0;
}
#endif
V_64 = ( void * ) F_35 ( V_63 , F_36 ( V_4 ) ) ;
if ( V_64 ) {
memset ( V_64 , 0 , V_4 ) ;
* V_62 = F_24 ( V_3 , V_64 , V_4 , V_65 ) ;
}
return V_64 ;
}
static void
F_37 ( struct V_2 * V_3 , T_1 V_4 , void * V_66 ,
T_2 V_62 , unsigned long V_59 )
{
F_33 ( V_3 , V_62 , V_4 , 0 , 0 ) ;
F_38 ( ( unsigned long ) V_66 , F_36 ( V_4 ) ) ;
}
static int
F_39 ( struct V_2 * V_3 , struct V_67 * V_68 , int V_69 ,
enum V_46 V_47 , unsigned long V_59 )
{
struct V_1 * V_1 ;
int V_70 , V_71 = 0 ;
unsigned long V_48 ;
unsigned long V_51 = V_52 [ ( int ) V_47 ] ;
unsigned long V_72 = 0 , V_73 = 0 ;
int V_74 ;
F_4 ( ! V_3 ) ;
V_1 = F_25 ( V_3 ) ;
F_40 ( L_11 , V_12 , V_69 ) ;
if ( V_69 == 1 ) {
F_41 ( V_68 ) = F_24 ( V_3 ,
F_42 ( V_68 ) , V_68 -> V_75 ,
V_47 ) ;
F_43 ( V_68 ) = V_68 -> V_75 ;
return 1 ;
}
for( V_74 = 0 ; V_74 < V_69 ; V_74 ++ )
V_72 += V_68 [ V_74 ] . V_75 ;
F_26 ( & V_1 -> V_53 , V_48 ) ;
#ifdef F_2
V_1 -> V_76 ++ ;
#endif
V_70 = F_44 ( V_1 , V_3 , V_68 , V_69 , F_1 ) ;
V_71 = F_45 ( V_1 , V_68 , V_69 , V_51 , F_15 ) ;
F_29 ( & V_1 -> V_53 , V_48 ) ;
F_4 ( V_70 != V_71 ) ;
F_40 ( L_12 , V_12 , V_71 ) ;
for ( V_74 = 0 ; V_74 < V_71 ; V_74 ++ )
V_73 += F_43 ( V_68 + V_74 ) ;
F_4 ( V_73 != V_72 ) ;
return V_71 ;
}
static void
F_46 ( struct V_2 * V_3 , struct V_67 * V_68 , int V_69 ,
enum V_46 V_47 , unsigned long V_59 )
{
struct V_1 * V_1 ;
F_4 ( ! V_3 ) ;
V_1 = F_25 ( V_3 ) ;
F_40 ( L_13 ,
V_12 , V_69 , F_42 ( V_68 ) , V_68 -> V_75 ) ;
#ifdef F_2
V_1 -> V_77 ++ ;
#endif
while( F_43 ( V_68 ) && V_69 -- ) {
#ifdef F_2
V_1 -> V_78 += F_43 ( V_68 ) >> V_79 ;
#endif
F_33 ( V_3 , F_41 ( V_68 ) ,
F_43 ( V_68 ) , V_47 , 0 ) ;
++ V_68 ;
}
F_40 ( L_14 , V_12 , V_69 ) ;
}
static int F_47 ( struct V_80 * V_81 , void * V_82 )
{
struct V_1 * V_1 = V_83 ;
while ( V_1 != NULL ) {
unsigned int V_84 = V_1 -> V_85 << 3 ;
#ifdef F_2
unsigned long V_86 = 0 , V_87 , V_88 ;
int V_89 ;
#endif
F_48 ( V_81 , L_15 , V_1 -> V_90 ) ;
F_48 ( V_81 , L_16 ,
( V_1 -> V_91 ? L_17 : L_18 ) ) ;
F_48 ( V_81 , L_19 ,
V_84 * 8 , V_84 ) ;
#ifdef F_2
F_48 ( V_81 , L_20 ,
V_84 - V_1 -> V_20 , V_1 -> V_20 ,
( int ) ( V_1 -> V_20 * 100 / V_84 ) ) ;
#endif
F_48 ( V_81 , L_21 ,
V_1 -> V_85 , V_84 ) ;
#ifdef F_2
V_87 = V_88 = V_1 -> V_17 [ 0 ] ;
for( V_89 = 0 ; V_89 < V_19 ; ++ V_89 ) {
V_86 += V_1 -> V_17 [ V_89 ] ;
if( V_1 -> V_17 [ V_89 ] > V_88 )
V_88 = V_1 -> V_17 [ V_89 ] ;
if( V_1 -> V_17 [ V_89 ] < V_87 )
V_87 = V_1 -> V_17 [ V_89 ] ;
}
V_86 /= V_19 ;
F_48 ( V_81 , L_22 ,
V_87 , V_86 , V_88 ) ;
F_48 ( V_81 , L_23 ,
V_1 -> V_54 , V_1 -> V_55 ,
( int ) ( ( V_1 -> V_55 * 1000 ) / V_1 -> V_54 ) ) ;
V_87 = V_1 -> V_60 - V_1 -> V_77 ;
V_88 = V_1 -> V_61 - V_1 -> V_78 ;
F_48 ( V_81 , L_24 ,
V_87 , V_88 , ( int ) ( ( V_88 * 1000 ) / V_87 ) ) ;
F_48 ( V_81 , L_25 ,
V_1 -> V_76 , V_1 -> V_92 ,
( int ) ( ( V_1 -> V_92 * 1000 ) / V_1 -> V_76 ) ) ;
F_48 ( V_81 , L_26 ,
V_1 -> V_77 , V_1 -> V_78 ,
( int ) ( ( V_1 -> V_78 * 1000 ) / V_1 -> V_77 ) ) ;
#endif
V_1 = V_1 -> V_93 ;
}
return 0 ;
}
static int F_49 ( struct V_94 * V_94 , struct V_95 * V_95 )
{
return F_50 ( V_95 , & F_47 , NULL ) ;
}
static int F_51 ( struct V_80 * V_81 , void * V_82 )
{
struct V_1 * V_1 = V_83 ;
while ( V_1 != NULL ) {
F_52 ( V_81 , L_27 , V_96 , 32 , 4 , V_1 -> V_97 ,
V_1 -> V_85 , false ) ;
F_53 ( V_81 , '\n' ) ;
V_1 = V_1 -> V_93 ;
break;
}
return 0 ;
}
static int F_54 ( struct V_94 * V_94 , struct V_95 * V_95 )
{
return F_50 ( V_95 , & F_51 , NULL ) ;
}
static struct V_1 * F_55 ( int V_98 )
{
int V_74 ;
struct V_1 * V_1 ;
V_1 = V_83 ;
for ( V_74 = 0 ; V_74 < V_99 ; V_74 ++ ) {
if ( V_1 -> V_98 == V_98 )
return V_1 ;
V_1 = V_1 -> V_93 ;
}
return NULL ;
}
void * F_56 ( const struct V_100 * V_3 )
{
V_3 = F_57 ( V_3 , V_101 ) ;
if ( ! V_3 )
return NULL ;
return F_55 ( V_3 -> V_98 ) ;
}
void F_58 ( struct V_100 * V_102 , V_32 V_23 )
{
unsigned int V_41 ;
struct V_100 * V_3 = F_59 ( V_102 ) ;
struct V_1 * V_1 = F_56 ( V_3 ) ;
T_7 * V_103 ;
V_1 -> V_91 = 1 ;
V_103 = V_1 -> V_97 ;
V_41 = F_13 ( V_23 ) >> 3 ;
while ( V_41 < V_1 -> V_85 ) {
V_103 [ V_41 ] |= 0xff ;
V_41 += F_13 ( V_104 ) >> 3 ;
}
}
static void
F_60 ( struct V_1 * V_1 )
{
int V_74 ;
unsigned int V_105 ;
V_32 V_106 ;
V_106 = ( V_32 ) ( V_107 / F_61 ( & V_108 ) ) ;
if ( V_106 < ( 1 << ( 20 - V_79 ) ) ) {
V_106 = 1 << ( 20 - V_79 ) ;
#ifdef F_9
} else if ( V_106 > ( 1 << ( 30 - V_79 ) ) ) {
V_106 = 1 << ( 30 - V_79 ) ;
#endif
}
V_105 = F_36 ( V_106 << V_79 ) ;
V_106 = 1 << ( V_105 + V_79 ) ;
V_1 -> V_43 = ( V_106 / V_10 ) * sizeof( T_4 ) ;
F_4 ( V_1 -> V_43 > 8 * 1024 * 1024 ) ;
F_4 ( ( 1 << F_36 ( V_1 -> V_43 ) ) != ( V_1 -> V_43 >> V_79 ) ) ;
F_62 ( L_28 ,
V_12 , V_1 -> V_38 ,
( unsigned long ) V_107 >> ( 20 - V_79 ) ,
V_106 >> 20 ,
V_105 + V_79 ) ;
V_1 -> V_42 = ( T_4 * ) F_35 ( V_109 ,
F_36 ( V_1 -> V_43 ) ) ;
if( NULL == V_1 -> V_42 ) {
F_10 ( L_29 , V_12 ) ;
}
memset ( V_1 -> V_42 , 0 , V_1 -> V_43 ) ;
F_4 ( ( ( ( unsigned long ) V_1 -> V_42 ) & V_110 ) != ( unsigned long ) V_1 -> V_42 ) ;
F_62 ( L_30 , V_1 -> V_42 ) ;
V_1 -> V_85 = ( V_1 -> V_43 / sizeof( T_4 ) ) >> 3 ;
F_62 ( L_31 , V_12 , V_1 -> V_85 ) ;
V_1 -> V_97 = ( T_7 * ) F_35 ( V_109 ,
F_36 ( V_1 -> V_85 ) ) ;
if( NULL == V_1 -> V_97 ) {
F_10 ( L_32 , V_12 ) ;
}
memset ( V_1 -> V_97 , 0 , V_1 -> V_85 ) ;
V_1 -> V_14 = 16 ;
F_63 ( & V_1 -> V_53 ) ;
V_1 -> V_35 = F_36 ( V_106 ) + V_79 - V_111 ;
F_62 ( L_33 , V_1 -> V_35 ) ;
F_19 ( V_112 << V_1 -> V_35 ,
& V_1 -> V_38 -> V_113 ) ;
F_19 ( F_17 ( V_1 -> V_42 ) ,
& V_1 -> V_38 -> V_114 ) ;
F_19 ( V_115 , & V_1 -> V_38 -> V_116 ) ;
F_19 ( 0 , & V_1 -> V_38 -> V_117 ) ;
F_19 ( 0 , & V_1 -> V_38 -> V_118 ) ;
for( V_74 = 1 << V_111 ; V_74 ; V_74 -- ) {
F_19 ( ( V_119 | ( V_74 << V_1 -> V_35 ) ) ,
& V_1 -> V_38 -> V_39 ) ;
}
}
static void T_8
F_64 ( struct V_120 * V_121 , char * V_90 , void T_9 * V_122 )
{
int V_123 ;
V_121 -> V_124 = NULL ;
V_121 -> V_48 = V_125 ;
V_121 -> V_126 = ( unsigned long ) ( ( signed ) F_65 ( V_122 ) << 16 ) ;
V_121 -> V_127 = ( unsigned long ) ( ( signed ) ( F_65 ( V_122 + 4 ) << 16 ) - 1 ) ;
V_121 -> V_90 = V_90 ;
if ( V_121 -> V_127 + 1 == V_121 -> V_126 )
return;
V_123 = F_66 ( & V_128 , V_121 ) ;
if ( V_123 < 0 ) {
F_22 ( V_129 L_34 ,
V_12 , ( unsigned long ) V_121 -> V_126 , ( unsigned long ) V_121 -> V_127 ) ;
}
}
static void T_8 F_67 ( struct V_1 * V_1 )
{
struct V_120 * V_121 = V_1 -> V_130 ;
char * V_90 = F_68 ( 14 , V_109 ) ;
snprintf ( V_90 , 14 , L_35 , V_1 -> V_98 ) ;
F_64 ( V_121 , V_90 , & V_1 -> V_38 -> V_131 ) ;
F_64 ( V_121 + 1 , V_90 , & V_1 -> V_38 -> V_132 ) ;
}
static int F_69 ( struct V_120 * V_121 , unsigned long V_4 ,
unsigned long V_87 , unsigned long V_88 , unsigned long V_133 )
{
if ( V_88 <= V_87 )
return - V_134 ;
V_121 -> V_126 = ( V_88 - V_4 + 1 ) & ~ ( V_133 - 1 ) ;
V_121 -> V_127 = V_121 -> V_126 + V_4 ;
if ( ! F_66 ( & V_128 , V_121 ) )
return 0 ;
return F_69 ( V_121 , V_4 , V_87 , V_88 - V_4 , V_133 ) ;
}
static int F_70 ( struct V_120 * V_121 , unsigned long V_4 ,
unsigned long V_87 , unsigned long V_88 , unsigned long V_133 )
{
unsigned long V_126 , V_135 ;
if ( ! V_121 -> V_124 )
return F_69 ( V_121 , V_4 , V_87 , V_88 , V_133 ) ;
V_126 = ( V_121 -> V_126 - V_4 ) & ~ ( V_133 - 1 ) ;
V_135 = V_121 -> V_127 - V_126 + 1 ;
if ( V_126 >= V_87 ) {
if ( ! F_71 ( V_121 , V_126 , V_135 ) )
return 0 ;
}
V_126 = V_121 -> V_126 ;
V_135 = ( ( V_4 + V_121 -> V_127 + V_133 ) & ~ ( V_133 - 1 ) ) - V_126 ;
if ( V_126 + V_135 <= V_88 ) {
if ( ! F_71 ( V_121 , V_126 , V_135 ) )
return 0 ;
}
return - V_134 ;
}
int F_72 ( const struct V_100 * V_3 ,
struct V_120 * V_121 , unsigned long V_4 ,
unsigned long V_87 , unsigned long V_88 , unsigned long V_133 )
{
struct V_120 * V_124 = & V_128 ;
struct V_1 * V_1 = F_56 ( V_3 ) ;
if ( ! V_1 )
goto V_136;
V_124 = V_1 -> V_130 ;
if ( V_124 -> V_124 &&
! F_73 ( V_124 , V_121 , V_4 , V_87 , V_88 , V_133 , NULL , NULL ) )
return 0 ;
if ( ( V_124 + 1 ) -> V_124 &&
! F_73 ( V_124 + 1 , V_121 , V_4 , V_87 , V_88 , V_133 ,
NULL , NULL ) )
return 0 ;
if ( ! F_70 ( V_124 , V_4 , V_87 , V_88 , V_133 ) ) {
F_74 ( ( ( V_124 -> V_126 ) >> 16 ) | 0xffff0000 ,
& V_1 -> V_38 -> V_131 ) ;
F_74 ( ( ( V_124 -> V_127 ) >> 16 ) | 0xffff0000 ,
& V_1 -> V_38 -> V_137 ) ;
} else if ( ! F_70 ( V_124 + 1 , V_4 , V_87 , V_88 , V_133 ) ) {
V_124 ++ ;
F_74 ( ( ( V_124 -> V_126 ) >> 16 ) | 0xffff0000 ,
& V_1 -> V_38 -> V_132 ) ;
F_74 ( ( ( V_124 -> V_127 ) >> 16 ) | 0xffff0000 ,
& V_1 -> V_38 -> V_138 ) ;
} else {
return - V_134 ;
}
V_136:
return F_73 ( V_124 , V_121 , V_4 , V_87 , V_88 , V_133 , NULL , NULL ) ;
}
int F_75 ( const struct V_100 * V_3 ,
struct V_120 * V_121 )
{
struct V_120 * V_124 ;
struct V_1 * V_1 = F_56 ( V_3 ) ;
if ( ! V_1 ) {
V_124 = & V_128 ;
} else if ( ( V_1 -> V_130 -> V_126 <= V_121 -> V_126 ) &&
( V_121 -> V_127 <= V_1 -> V_130 -> V_127 ) ) {
V_124 = V_1 -> V_130 ;
} else if ( ( ( V_1 -> V_130 + 1 ) -> V_126 <= V_121 -> V_126 ) &&
( V_121 -> V_127 <= ( V_1 -> V_130 + 1 ) -> V_127 ) ) {
V_124 = V_1 -> V_130 + 1 ;
} else {
return - V_134 ;
}
return F_66 ( V_124 , V_121 ) ;
}
static int T_8 F_76 ( struct V_100 * V_3 )
{
int V_74 ;
struct V_1 * V_1 , * * V_139 = & V_83 ;
V_1 = F_77 ( sizeof( struct V_1 ) , V_109 ) ;
if ( V_1 == NULL ) {
F_22 (KERN_ERR MODULE_NAME L_36 ) ;
return - V_140 ;
}
V_1 -> V_90 = V_3 -> V_141 . V_142 == V_143 ? L_37 : L_38 ;
F_22 ( V_144 L_39 , V_1 -> V_90 ,
( unsigned long ) V_3 -> V_145 . V_126 ) ;
for ( V_74 = 0 ; V_74 < V_99 ; V_74 ++ ) {
V_139 = & ( * V_139 ) -> V_93 ;
}
* V_139 = V_1 ;
V_1 -> V_98 = V_3 -> V_98 ;
V_1 -> V_38 = F_78 ( V_3 -> V_145 . V_126 , 4096 ) ;
if ( ! V_1 -> V_38 ) {
F_79 ( V_1 ) ;
return - V_140 ;
}
F_60 ( V_1 ) ;
F_67 ( V_1 ) ;
V_146 = & V_147 ;
V_3 -> V_3 . V_148 = F_77 ( sizeof( struct V_149 ) , V_109 ) ;
F_4 ( V_3 -> V_3 . V_148 == NULL ) ;
F_80 ( V_3 -> V_3 . V_148 ) -> V_150 = V_1 ;
#ifdef F_81
if ( V_99 == 0 ) {
F_82 ( V_151 , 0 , V_152 ,
& V_153 ) ;
F_82 ( V_151 L_40 , 0 , V_152 ,
& V_154 ) ;
}
#endif
V_99 ++ ;
F_83 () ;
return 0 ;
}
void T_8 F_84 ( void )
{
F_85 ( & V_108 ) ;
}
