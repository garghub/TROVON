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
if ( ! V_1 )
return V_53 ;
F_4 ( V_4 <= 0 ) ;
V_49 = ( ( unsigned long ) V_45 ) & ~ V_36 ;
V_4 = F_6 ( V_4 + V_49 , V_10 ) ;
F_26 ( & V_1 -> V_54 , V_48 ) ;
#ifdef F_2
V_1 -> V_55 ++ ;
V_1 -> V_56 += V_4 >> V_6 ;
#endif
V_41 = F_1 ( V_1 , V_3 , V_4 ) ;
V_23 = ( T_2 ) F_27 ( V_41 ) ;
V_50 = & ( V_1 -> V_42 [ V_41 ] ) ;
F_28 ( L_8 ,
V_12 , V_45 , ( long ) V_23 | V_49 , V_4 ) ;
if( ( V_4 % V_57 ) || ( ( unsigned long ) V_45 % V_57 ) )
V_51 |= V_58 ;
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
F_29 ( & V_1 -> V_54 , V_48 ) ;
return F_30 ( V_23 , V_49 ) ;
}
static T_2
F_31 ( struct V_2 * V_3 , struct V_59 * V_59 , unsigned long V_49 ,
T_1 V_4 , enum V_46 V_47 ,
unsigned long V_60 )
{
return F_24 ( V_3 , F_32 ( V_59 ) + V_49 , V_4 ,
V_47 ) ;
}
static void
F_33 ( struct V_2 * V_3 , T_2 V_21 , T_1 V_4 ,
enum V_46 V_47 , unsigned long V_60 )
{
struct V_1 * V_1 ;
unsigned long V_48 ;
T_2 V_49 = V_21 & ~ V_36 ;
F_4 ( ! V_3 ) ;
V_1 = F_25 ( V_3 ) ;
if ( ! V_1 ) {
F_34 ( ! V_1 ) ;
return;
}
F_28 ( L_10 ,
V_12 , ( long ) V_21 , V_4 ) ;
V_21 ^= V_49 ;
V_4 += V_49 ;
V_4 = F_6 ( V_4 , V_10 ) ;
F_26 ( & V_1 -> V_54 , V_48 ) ;
#ifdef F_2
V_1 -> V_61 ++ ;
V_1 -> V_62 += V_4 >> V_6 ;
#endif
F_20 ( V_1 , V_21 , V_4 ) ;
F_11 ( V_1 , V_21 , ( V_4 >> V_6 ) ) ;
F_29 ( & V_1 -> V_54 , V_48 ) ;
}
static void *
F_35 ( struct V_2 * V_3 , T_1 V_4 , T_2 * V_63 , T_6 V_64 ,
unsigned long V_60 )
{
void * V_65 ;
#if 0
if(!hwdev) {
*dma_handle = 0;
return 0;
}
#endif
V_65 = ( void * ) F_36 ( V_64 , F_37 ( V_4 ) ) ;
if ( V_65 ) {
memset ( V_65 , 0 , V_4 ) ;
* V_63 = F_24 ( V_3 , V_65 , V_4 , V_66 ) ;
}
return V_65 ;
}
static void
F_38 ( struct V_2 * V_3 , T_1 V_4 , void * V_67 ,
T_2 V_63 , unsigned long V_60 )
{
F_33 ( V_3 , V_63 , V_4 , 0 , 0 ) ;
F_39 ( ( unsigned long ) V_67 , F_37 ( V_4 ) ) ;
}
static int
F_40 ( struct V_2 * V_3 , struct V_68 * V_69 , int V_70 ,
enum V_46 V_47 , unsigned long V_60 )
{
struct V_1 * V_1 ;
int V_71 , V_72 = 0 ;
unsigned long V_48 ;
unsigned long V_51 = V_52 [ ( int ) V_47 ] ;
unsigned long V_73 = 0 , V_74 = 0 ;
int V_75 ;
F_4 ( ! V_3 ) ;
V_1 = F_25 ( V_3 ) ;
if ( ! V_1 )
return 0 ;
F_41 ( L_11 , V_12 , V_70 ) ;
if ( V_70 == 1 ) {
F_42 ( V_69 ) = F_24 ( V_3 ,
F_43 ( V_69 ) , V_69 -> V_76 ,
V_47 ) ;
F_44 ( V_69 ) = V_69 -> V_76 ;
return 1 ;
}
for( V_75 = 0 ; V_75 < V_70 ; V_75 ++ )
V_73 += V_69 [ V_75 ] . V_76 ;
F_26 ( & V_1 -> V_54 , V_48 ) ;
#ifdef F_2
V_1 -> V_77 ++ ;
#endif
V_71 = F_45 ( V_1 , V_3 , V_69 , V_70 , F_1 ) ;
V_72 = F_46 ( V_1 , V_69 , V_70 , V_51 , F_15 ) ;
F_29 ( & V_1 -> V_54 , V_48 ) ;
F_4 ( V_71 != V_72 ) ;
F_41 ( L_12 , V_12 , V_72 ) ;
for ( V_75 = 0 ; V_75 < V_72 ; V_75 ++ )
V_74 += F_44 ( V_69 + V_75 ) ;
F_4 ( V_74 != V_73 ) ;
return V_72 ;
}
static void
F_47 ( struct V_2 * V_3 , struct V_68 * V_69 , int V_70 ,
enum V_46 V_47 , unsigned long V_60 )
{
struct V_1 * V_1 ;
F_4 ( ! V_3 ) ;
V_1 = F_25 ( V_3 ) ;
if ( ! V_1 ) {
F_34 ( ! V_1 ) ;
return;
}
F_41 ( L_13 ,
V_12 , V_70 , F_43 ( V_69 ) , V_69 -> V_76 ) ;
#ifdef F_2
V_1 -> V_78 ++ ;
#endif
while( F_44 ( V_69 ) && V_70 -- ) {
#ifdef F_2
V_1 -> V_79 += F_44 ( V_69 ) >> V_80 ;
#endif
F_33 ( V_3 , F_42 ( V_69 ) ,
F_44 ( V_69 ) , V_47 , 0 ) ;
++ V_69 ;
}
F_41 ( L_14 , V_12 , V_70 ) ;
}
static int F_48 ( struct V_2 * V_3 , T_2 V_81 )
{
return V_81 == V_53 ;
}
static int F_49 ( struct V_82 * V_83 , void * V_84 )
{
struct V_1 * V_1 = V_85 ;
while ( V_1 != NULL ) {
unsigned int V_86 = V_1 -> V_87 << 3 ;
#ifdef F_2
unsigned long V_88 = 0 , V_89 , V_90 ;
int V_91 ;
#endif
F_50 ( V_83 , L_15 , V_1 -> V_92 ) ;
F_50 ( V_83 , L_16 ,
( V_1 -> V_93 ? L_17 : L_18 ) ) ;
F_50 ( V_83 , L_19 ,
V_86 * 8 , V_86 ) ;
#ifdef F_2
F_50 ( V_83 , L_20 ,
V_86 - V_1 -> V_20 , V_1 -> V_20 ,
( int ) ( V_1 -> V_20 * 100 / V_86 ) ) ;
#endif
F_50 ( V_83 , L_21 ,
V_1 -> V_87 , V_86 ) ;
#ifdef F_2
V_89 = V_90 = V_1 -> V_17 [ 0 ] ;
for( V_91 = 0 ; V_91 < V_19 ; ++ V_91 ) {
V_88 += V_1 -> V_17 [ V_91 ] ;
if( V_1 -> V_17 [ V_91 ] > V_90 )
V_90 = V_1 -> V_17 [ V_91 ] ;
if( V_1 -> V_17 [ V_91 ] < V_89 )
V_89 = V_1 -> V_17 [ V_91 ] ;
}
V_88 /= V_19 ;
F_50 ( V_83 , L_22 ,
V_89 , V_88 , V_90 ) ;
F_50 ( V_83 , L_23 ,
V_1 -> V_55 , V_1 -> V_56 ,
( int ) ( ( V_1 -> V_56 * 1000 ) / V_1 -> V_55 ) ) ;
V_89 = V_1 -> V_61 - V_1 -> V_78 ;
V_90 = V_1 -> V_62 - V_1 -> V_79 ;
F_50 ( V_83 , L_24 ,
V_89 , V_90 , ( int ) ( ( V_90 * 1000 ) / V_89 ) ) ;
F_50 ( V_83 , L_25 ,
V_1 -> V_77 , V_1 -> V_94 ,
( int ) ( ( V_1 -> V_94 * 1000 ) / V_1 -> V_77 ) ) ;
F_50 ( V_83 , L_26 ,
V_1 -> V_78 , V_1 -> V_79 ,
( int ) ( ( V_1 -> V_79 * 1000 ) / V_1 -> V_78 ) ) ;
#endif
V_1 = V_1 -> V_95 ;
}
return 0 ;
}
static int F_51 ( struct V_96 * V_96 , struct V_97 * V_97 )
{
return F_52 ( V_97 , & F_49 , NULL ) ;
}
static int F_53 ( struct V_82 * V_83 , void * V_84 )
{
struct V_1 * V_1 = V_85 ;
while ( V_1 != NULL ) {
F_54 ( V_83 , L_27 , V_98 , 32 , 4 , V_1 -> V_99 ,
V_1 -> V_87 , false ) ;
F_55 ( V_83 , '\n' ) ;
V_1 = V_1 -> V_95 ;
break;
}
return 0 ;
}
static int F_56 ( struct V_96 * V_96 , struct V_97 * V_97 )
{
return F_52 ( V_97 , & F_53 , NULL ) ;
}
static struct V_1 * F_57 ( int V_100 )
{
int V_75 ;
struct V_1 * V_1 ;
V_1 = V_85 ;
for ( V_75 = 0 ; V_75 < V_101 ; V_75 ++ ) {
if ( V_1 -> V_100 == V_100 )
return V_1 ;
V_1 = V_1 -> V_95 ;
}
return NULL ;
}
void * F_58 ( const struct V_102 * V_3 )
{
V_3 = F_59 ( V_3 , V_103 ) ;
if ( ! V_3 )
return NULL ;
return F_57 ( V_3 -> V_100 ) ;
}
void F_60 ( struct V_102 * V_104 , V_32 V_23 )
{
unsigned int V_41 ;
struct V_102 * V_3 = F_61 ( V_104 ) ;
struct V_1 * V_1 = F_58 ( V_3 ) ;
T_7 * V_105 ;
V_1 -> V_93 = 1 ;
V_105 = V_1 -> V_99 ;
V_41 = F_13 ( V_23 ) >> 3 ;
while ( V_41 < V_1 -> V_87 ) {
V_105 [ V_41 ] |= 0xff ;
V_41 += F_13 ( V_106 ) >> 3 ;
}
}
static void
F_62 ( struct V_1 * V_1 )
{
int V_75 ;
unsigned int V_107 ;
V_32 V_108 ;
V_108 = ( V_32 ) ( V_109 / F_63 ( & V_110 ) ) ;
if ( V_108 < ( 1 << ( 20 - V_80 ) ) ) {
V_108 = 1 << ( 20 - V_80 ) ;
#ifdef F_9
} else if ( V_108 > ( 1 << ( 30 - V_80 ) ) ) {
V_108 = 1 << ( 30 - V_80 ) ;
#endif
}
V_107 = F_37 ( V_108 << V_80 ) ;
V_108 = 1 << ( V_107 + V_80 ) ;
V_1 -> V_43 = ( V_108 / V_10 ) * sizeof( T_4 ) ;
F_4 ( V_1 -> V_43 > 8 * 1024 * 1024 ) ;
F_4 ( ( 1 << F_37 ( V_1 -> V_43 ) ) != ( V_1 -> V_43 >> V_80 ) ) ;
F_64 ( L_28 ,
V_12 , V_1 -> V_38 ,
( unsigned long ) V_109 >> ( 20 - V_80 ) ,
V_108 >> 20 ,
V_107 + V_80 ) ;
V_1 -> V_42 = ( T_4 * ) F_36 ( V_111 ,
F_37 ( V_1 -> V_43 ) ) ;
if( NULL == V_1 -> V_42 ) {
F_10 ( L_29 , V_12 ) ;
}
memset ( V_1 -> V_42 , 0 , V_1 -> V_43 ) ;
F_4 ( ( ( ( unsigned long ) V_1 -> V_42 ) & V_112 ) != ( unsigned long ) V_1 -> V_42 ) ;
F_64 ( L_30 , V_1 -> V_42 ) ;
V_1 -> V_87 = ( V_1 -> V_43 / sizeof( T_4 ) ) >> 3 ;
F_64 ( L_31 , V_12 , V_1 -> V_87 ) ;
V_1 -> V_99 = ( T_7 * ) F_36 ( V_111 ,
F_37 ( V_1 -> V_87 ) ) ;
if( NULL == V_1 -> V_99 ) {
F_10 ( L_32 , V_12 ) ;
}
memset ( V_1 -> V_99 , 0 , V_1 -> V_87 ) ;
V_1 -> V_14 = 16 ;
F_65 ( & V_1 -> V_54 ) ;
V_1 -> V_35 = F_37 ( V_108 ) + V_80 - V_113 ;
F_64 ( L_33 , V_1 -> V_35 ) ;
F_19 ( V_114 << V_1 -> V_35 ,
& V_1 -> V_38 -> V_115 ) ;
F_19 ( F_17 ( V_1 -> V_42 ) ,
& V_1 -> V_38 -> V_116 ) ;
F_19 ( V_117 , & V_1 -> V_38 -> V_118 ) ;
F_19 ( 0 , & V_1 -> V_38 -> V_119 ) ;
F_19 ( 0 , & V_1 -> V_38 -> V_120 ) ;
for( V_75 = 1 << V_113 ; V_75 ; V_75 -- ) {
F_19 ( ( V_121 | ( V_75 << V_1 -> V_35 ) ) ,
& V_1 -> V_38 -> V_39 ) ;
}
}
static void T_8
F_66 ( struct V_122 * V_123 , char * V_92 , void T_9 * V_124 )
{
int V_125 ;
V_123 -> V_126 = NULL ;
V_123 -> V_48 = V_127 ;
V_123 -> V_128 = ( unsigned long ) ( ( signed ) F_67 ( V_124 ) << 16 ) ;
V_123 -> V_129 = ( unsigned long ) ( ( signed ) ( F_67 ( V_124 + 4 ) << 16 ) - 1 ) ;
V_123 -> V_92 = V_92 ;
if ( V_123 -> V_129 + 1 == V_123 -> V_128 )
return;
V_125 = F_68 ( & V_130 , V_123 ) ;
if ( V_125 < 0 ) {
F_22 ( V_131 L_34 ,
V_12 , ( unsigned long ) V_123 -> V_128 , ( unsigned long ) V_123 -> V_129 ) ;
}
}
static void T_8 F_69 ( struct V_1 * V_1 )
{
struct V_122 * V_123 = V_1 -> V_132 ;
char * V_92 = F_70 ( 14 , V_111 ) ;
snprintf ( V_92 , 14 , L_35 , V_1 -> V_100 ) ;
F_66 ( V_123 , V_92 , & V_1 -> V_38 -> V_133 ) ;
F_66 ( V_123 + 1 , V_92 , & V_1 -> V_38 -> V_134 ) ;
}
static int F_71 ( struct V_122 * V_123 , unsigned long V_4 ,
unsigned long V_89 , unsigned long V_90 , unsigned long V_135 )
{
if ( V_90 <= V_89 )
return - V_136 ;
V_123 -> V_128 = ( V_90 - V_4 + 1 ) & ~ ( V_135 - 1 ) ;
V_123 -> V_129 = V_123 -> V_128 + V_4 ;
if ( ! F_68 ( & V_130 , V_123 ) )
return 0 ;
return F_71 ( V_123 , V_4 , V_89 , V_90 - V_4 , V_135 ) ;
}
static int F_72 ( struct V_122 * V_123 , unsigned long V_4 ,
unsigned long V_89 , unsigned long V_90 , unsigned long V_135 )
{
unsigned long V_128 , V_137 ;
if ( ! V_123 -> V_126 )
return F_71 ( V_123 , V_4 , V_89 , V_90 , V_135 ) ;
V_128 = ( V_123 -> V_128 - V_4 ) & ~ ( V_135 - 1 ) ;
V_137 = V_123 -> V_129 - V_128 + 1 ;
if ( V_128 >= V_89 ) {
if ( ! F_73 ( V_123 , V_128 , V_137 ) )
return 0 ;
}
V_128 = V_123 -> V_128 ;
V_137 = ( ( V_4 + V_123 -> V_129 + V_135 ) & ~ ( V_135 - 1 ) ) - V_128 ;
if ( V_128 + V_137 <= V_90 ) {
if ( ! F_73 ( V_123 , V_128 , V_137 ) )
return 0 ;
}
return - V_136 ;
}
int F_74 ( const struct V_102 * V_3 ,
struct V_122 * V_123 , unsigned long V_4 ,
unsigned long V_89 , unsigned long V_90 , unsigned long V_135 )
{
struct V_122 * V_126 = & V_130 ;
struct V_1 * V_1 = F_58 ( V_3 ) ;
if ( ! V_1 )
goto V_138;
V_126 = V_1 -> V_132 ;
if ( V_126 -> V_126 &&
! F_75 ( V_126 , V_123 , V_4 , V_89 , V_90 , V_135 , NULL , NULL ) )
return 0 ;
if ( ( V_126 + 1 ) -> V_126 &&
! F_75 ( V_126 + 1 , V_123 , V_4 , V_89 , V_90 , V_135 ,
NULL , NULL ) )
return 0 ;
if ( ! F_72 ( V_126 , V_4 , V_89 , V_90 , V_135 ) ) {
F_76 ( ( ( V_126 -> V_128 ) >> 16 ) | 0xffff0000 ,
& V_1 -> V_38 -> V_133 ) ;
F_76 ( ( ( V_126 -> V_129 ) >> 16 ) | 0xffff0000 ,
& V_1 -> V_38 -> V_139 ) ;
} else if ( ! F_72 ( V_126 + 1 , V_4 , V_89 , V_90 , V_135 ) ) {
V_126 ++ ;
F_76 ( ( ( V_126 -> V_128 ) >> 16 ) | 0xffff0000 ,
& V_1 -> V_38 -> V_134 ) ;
F_76 ( ( ( V_126 -> V_129 ) >> 16 ) | 0xffff0000 ,
& V_1 -> V_38 -> V_140 ) ;
} else {
return - V_136 ;
}
V_138:
return F_75 ( V_126 , V_123 , V_4 , V_89 , V_90 , V_135 , NULL , NULL ) ;
}
int F_77 ( const struct V_102 * V_3 ,
struct V_122 * V_123 )
{
struct V_122 * V_126 ;
struct V_1 * V_1 = F_58 ( V_3 ) ;
if ( ! V_1 ) {
V_126 = & V_130 ;
} else if ( ( V_1 -> V_132 -> V_128 <= V_123 -> V_128 ) &&
( V_123 -> V_129 <= V_1 -> V_132 -> V_129 ) ) {
V_126 = V_1 -> V_132 ;
} else if ( ( ( V_1 -> V_132 + 1 ) -> V_128 <= V_123 -> V_128 ) &&
( V_123 -> V_129 <= ( V_1 -> V_132 + 1 ) -> V_129 ) ) {
V_126 = V_1 -> V_132 + 1 ;
} else {
return - V_136 ;
}
return F_68 ( V_126 , V_123 ) ;
}
static int T_8 F_78 ( struct V_102 * V_3 )
{
int V_75 ;
struct V_1 * V_1 , * * V_141 = & V_85 ;
V_1 = F_79 ( sizeof( struct V_1 ) , V_111 ) ;
if ( V_1 == NULL ) {
F_22 (KERN_ERR MODULE_NAME L_36 ) ;
return - V_142 ;
}
V_1 -> V_92 = V_3 -> V_143 . V_144 == V_145 ? L_37 : L_38 ;
F_22 ( V_146 L_39 , V_1 -> V_92 ,
( unsigned long ) V_3 -> V_147 . V_128 ) ;
for ( V_75 = 0 ; V_75 < V_101 ; V_75 ++ ) {
V_141 = & ( * V_141 ) -> V_95 ;
}
* V_141 = V_1 ;
V_1 -> V_100 = V_3 -> V_100 ;
V_1 -> V_38 = F_80 ( V_3 -> V_147 . V_128 , 4096 ) ;
if ( ! V_1 -> V_38 ) {
F_81 ( V_1 ) ;
return - V_142 ;
}
F_62 ( V_1 ) ;
F_69 ( V_1 ) ;
V_148 = & V_149 ;
V_3 -> V_3 . V_150 = F_79 ( sizeof( struct V_151 ) , V_111 ) ;
F_4 ( V_3 -> V_3 . V_150 == NULL ) ;
F_82 ( V_3 -> V_3 . V_150 ) -> V_152 = V_1 ;
#ifdef F_83
if ( V_101 == 0 ) {
F_84 ( V_153 , 0 , V_154 ,
& V_155 ) ;
F_84 ( V_153 L_40 , 0 , V_154 ,
& V_156 ) ;
}
#endif
V_101 ++ ;
F_85 () ;
return 0 ;
}
void T_8 F_86 ( void )
{
F_87 ( & V_110 ) ;
}
