static inline int F_1 ( int V_1 )
{
return V_1 + 2 ;
}
static inline int F_2 ( int V_1 )
{
return 30 + V_1 * V_2 ;
}
static inline int F_3 ( int V_3 )
{
return ( V_3 - 30 ) / V_2 ;
}
static inline unsigned int F_4 ( int V_4 )
{
return ( V_4 - 1 ) * V_2 ;
}
static inline int F_5 ( unsigned long V_5 , int V_4 )
{
return ( V_5 >> F_4 ( V_4 ) ) & V_6 ;
}
static inline unsigned long F_6 ( int V_4 )
{
return - 1UL << F_4 ( V_4 ) ;
}
static inline unsigned long F_7 ( int V_4 )
{
return 1UL << F_4 ( V_4 ) ;
}
static inline unsigned long F_8 ( unsigned long V_5 , int V_4 )
{
return ( V_5 + F_7 ( V_4 ) - 1 ) & F_6 ( V_4 ) ;
}
static inline unsigned long F_9 ( unsigned int V_7 )
{
return 1 << ( ( V_7 - 1 ) * V_2 ) ;
}
static inline unsigned long F_10 ( unsigned long V_8 )
{
return V_8 >> ( V_9 - V_10 ) ;
}
static inline unsigned long F_11 ( unsigned long V_11 )
{
return V_11 << ( V_9 - V_10 ) ;
}
static inline unsigned long F_12 ( struct V_12 * V_13 )
{
return F_11 ( F_13 ( V_13 ) ) ;
}
static inline unsigned long F_14 ( void * V_14 )
{
return F_12 ( F_15 ( V_14 ) ) ;
}
static inline bool F_16 ( struct V_15 * V_16 )
{
return ( V_16 -> V_17 & 1 ) ;
}
static inline void F_17 ( struct V_15 * V_16 )
{
V_16 -> V_17 |= 1 ;
}
static inline void F_18 ( struct V_15 * V_16 , unsigned long V_18 )
{
V_16 -> V_17 |= V_18 & V_19 ;
}
static inline struct V_20 *
F_19 ( struct V_15 * V_16 )
{
return (struct V_20 * )
( F_16 ( V_16 ) ? F_20 (
V_16 -> V_17 & V_19 ) :
NULL ) ;
}
static inline bool F_21 ( struct V_20 * V_21 )
{
return ( V_21 -> V_22 & 1 ) ;
}
static inline void F_22 ( struct V_20 * V_21 )
{
V_21 -> V_22 |= 1 ;
}
static inline void F_23 ( struct V_20 * V_21 )
{
V_21 -> V_22 &= ( ( ( V_23 ) - 1 ) << 2 ) | 1 ;
}
static inline void F_24 ( struct V_20 * V_21 ,
unsigned long V_18 )
{
V_21 -> V_22 &= ( ( ( V_23 ) - 1 ) << 4 ) | 3 ;
V_21 -> V_22 |= ( V_18 & 3 ) << 2 ;
}
static inline void F_25 ( struct V_20 * V_21 ,
unsigned long V_18 )
{
V_21 -> V_22 |= V_18 & V_19 ;
}
static inline void F_26 ( struct V_20 * V_21 ,
unsigned long V_18 )
{
V_21 -> V_24 |= V_18 & 7 ;
}
static inline void F_27 ( struct V_20 * V_21 ,
unsigned long V_18 )
{
V_21 -> V_24 |= ( V_18 & ( ( 1 << 16 ) - 1 ) ) << 8 ;
}
static inline void F_28 ( struct V_20 * V_21 )
{
V_21 -> V_22 = 0 ;
V_21 -> V_24 = 0 ;
}
static inline void F_29 ( struct V_25 * V_26 )
{
V_26 -> V_17 = 0 ;
}
static inline void F_30 ( struct V_25 * V_26 )
{
V_26 -> V_17 |= V_27 ;
}
static inline void F_31 ( struct V_25 * V_26 )
{
V_26 -> V_17 |= V_28 ;
}
static inline void F_32 ( struct V_25 * V_26 )
{
V_26 -> V_17 |= V_29 ;
}
static inline void F_33 ( struct V_25 * V_26 , unsigned long V_30 )
{
V_26 -> V_17 = ( V_26 -> V_17 & ~ 3 ) | ( V_30 & 3 ) ;
}
static inline V_23 F_34 ( struct V_25 * V_26 )
{
#ifdef F_35
return V_26 -> V_17 & V_19 ;
#else
return F_36 ( & V_26 -> V_17 , 0ULL , 0ULL ) & V_19 ;
#endif
}
static inline void F_37 ( struct V_25 * V_26 , unsigned long V_5 )
{
V_26 -> V_17 |= ( V_31 ) V_5 << V_10 ;
}
static inline bool F_38 ( struct V_25 * V_26 )
{
return ( V_26 -> V_17 & 3 ) != 0 ;
}
static inline bool F_39 ( struct V_25 * V_26 )
{
return ( V_26 -> V_17 & ( 1 << 7 ) ) ;
}
static inline int F_40 ( struct V_25 * V_26 )
{
return ! ( ( unsigned long ) V_26 & ~ V_19 ) ;
}
static int T_1 F_41 ( char * V_32 )
{
if ( ! V_32 )
return - V_33 ;
while ( * V_32 ) {
if ( ! strncmp ( V_32 , L_1 , 2 ) ) {
V_34 = 0 ;
F_42 ( V_35 L_2 ) ;
} else if ( ! strncmp ( V_32 , L_3 , 3 ) ) {
V_34 = 1 ;
F_42 ( V_35 L_4 ) ;
} else if ( ! strncmp ( V_32 , L_5 , 8 ) ) {
V_36 = 0 ;
F_42 ( V_35
L_6 ) ;
} else if ( ! strncmp ( V_32 , L_7 , 8 ) ) {
F_42 ( V_35
L_8 ) ;
V_37 = 1 ;
} else if ( ! strncmp ( V_32 , L_9 , 6 ) ) {
F_42 ( V_35
L_10 ) ;
V_38 = 1 ;
} else if ( ! strncmp ( V_32 , L_11 , 6 ) ) {
F_42 ( V_35
L_12 ) ;
V_39 = 0 ;
}
V_32 += strcspn ( V_32 , L_13 ) ;
while ( * V_32 == ',' )
V_32 ++ ;
}
return 0 ;
}
static inline void * F_43 ( int V_40 )
{
struct V_12 * V_12 ;
void * V_41 = NULL ;
V_12 = F_44 ( V_40 , V_42 | V_43 , 0 ) ;
if ( V_12 )
V_41 = F_45 ( V_12 ) ;
return V_41 ;
}
static inline void F_46 ( void * V_41 )
{
F_47 ( ( unsigned long ) V_41 ) ;
}
static inline void * F_48 ( void )
{
return F_49 ( V_44 , V_42 ) ;
}
static void F_50 ( void * V_41 )
{
F_51 ( V_44 , V_41 ) ;
}
static inline void * F_52 ( void )
{
return F_49 ( V_45 , V_42 ) ;
}
static inline void F_53 ( void * V_41 )
{
F_51 ( V_45 , V_41 ) ;
}
struct V_46 * F_54 ( void )
{
return F_49 ( V_47 , V_42 ) ;
}
void F_55 ( struct V_46 * V_46 )
{
F_51 ( V_47 , V_46 ) ;
}
static int F_56 ( struct V_48 * V_49 , int V_50 )
{
unsigned long V_51 ;
int V_1 = - 1 ;
V_51 = F_57 ( V_49 -> V_52 ) ;
for ( V_1 = F_3 ( V_50 ) ;
V_1 >= 0 ; V_1 -- ) {
if ( F_58 ( V_1 , & V_51 ) )
break;
}
return V_1 ;
}
int F_59 ( struct V_48 * V_49 )
{
return F_56 ( V_49 , V_53 ) ;
}
int F_60 ( struct V_48 * V_49 )
{
return F_56 ( V_49 , V_54 ) ;
}
static struct V_48 * F_61 ( struct V_55 * V_56 )
{
int V_57 ;
F_62 ( V_56 -> V_58 & V_59 ) ;
F_62 ( V_56 -> V_58 & V_60 ) ;
V_57 = F_63 ( V_56 -> V_61 , V_62 ) ;
if ( V_57 < 0 || V_57 >= V_62 )
return NULL ;
return V_63 [ V_57 ] ;
}
static void F_64 ( struct V_55 * V_56 )
{
int V_64 ;
V_64 = F_63 ( V_56 -> V_61 , V_62 ) ;
V_56 -> V_65 = V_64 < V_62 ? 1 : 0 ;
F_65 (i, domain->iommu_bmp, g_num_of_iommus) {
if ( ! F_66 ( V_63 [ V_64 ] -> V_66 ) ) {
V_56 -> V_65 = 0 ;
break;
}
}
}
static void F_67 ( struct V_55 * V_56 )
{
int V_64 ;
V_56 -> V_67 = 1 ;
F_65 (i, domain->iommu_bmp, g_num_of_iommus) {
if ( ! F_68 ( V_63 [ V_64 ] -> V_66 ) ) {
V_56 -> V_67 = 0 ;
break;
}
}
}
static void F_69 ( struct V_55 * V_56 )
{
struct V_68 * V_69 ;
struct V_48 * V_49 = NULL ;
int V_70 = 0xf ;
if ( ! V_39 ) {
V_56 -> V_71 = 0 ;
return;
}
F_70 (iommu, drhd) {
V_70 &= F_71 ( V_49 -> V_52 ) ;
if ( ! V_70 ) {
break;
}
}
V_56 -> V_71 = F_72 ( V_70 ) ;
}
static void F_73 ( struct V_55 * V_56 )
{
F_64 ( V_56 ) ;
F_67 ( V_56 ) ;
F_69 ( V_56 ) ;
}
static struct V_48 * F_74 ( int V_72 , T_2 V_73 , T_2 V_74 )
{
struct V_68 * V_69 = NULL ;
int V_64 ;
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
if ( V_72 != V_69 -> V_72 )
continue;
for ( V_64 = 0 ; V_64 < V_69 -> V_76 ; V_64 ++ ) {
if ( V_69 -> V_77 [ V_64 ] &&
V_69 -> V_77 [ V_64 ] -> V_73 -> V_78 == V_73 &&
V_69 -> V_77 [ V_64 ] -> V_74 == V_74 )
return V_69 -> V_49 ;
if ( V_69 -> V_77 [ V_64 ] &&
V_69 -> V_77 [ V_64 ] -> V_79 &&
V_69 -> V_77 [ V_64 ] -> V_79 -> V_78 <= V_73 &&
V_69 -> V_77 [ V_64 ] -> V_79 -> V_80 . V_81 >= V_73 )
return V_69 -> V_49 ;
}
if ( V_69 -> V_82 )
return V_69 -> V_49 ;
}
return NULL ;
}
static void F_76 ( struct V_55 * V_56 ,
void * V_83 , int V_84 )
{
if ( ! V_56 -> V_65 )
F_77 ( V_83 , V_84 ) ;
}
static struct V_20 * F_78 ( struct V_48 * V_49 ,
T_2 V_73 , T_2 V_74 )
{
struct V_15 * V_16 ;
struct V_20 * V_21 ;
unsigned long V_85 ;
unsigned long V_58 ;
F_79 ( & V_49 -> V_86 , V_58 ) ;
V_16 = & V_49 -> V_15 [ V_73 ] ;
V_21 = F_19 ( V_16 ) ;
if ( ! V_21 ) {
V_21 = (struct V_20 * )
F_43 ( V_49 -> V_40 ) ;
if ( ! V_21 ) {
F_80 ( & V_49 -> V_86 , V_58 ) ;
return NULL ;
}
F_81 ( V_49 , ( void * ) V_21 , V_87 ) ;
V_85 = F_82 ( ( void * ) V_21 ) ;
F_18 ( V_16 , V_85 ) ;
F_17 ( V_16 ) ;
F_81 ( V_49 , V_16 , sizeof( * V_16 ) ) ;
}
F_80 ( & V_49 -> V_86 , V_58 ) ;
return & V_21 [ V_74 ] ;
}
static int F_83 ( struct V_48 * V_49 , T_2 V_73 , T_2 V_74 )
{
struct V_15 * V_16 ;
struct V_20 * V_21 ;
int V_88 ;
unsigned long V_58 ;
F_79 ( & V_49 -> V_86 , V_58 ) ;
V_16 = & V_49 -> V_15 [ V_73 ] ;
V_21 = F_19 ( V_16 ) ;
if ( ! V_21 ) {
V_88 = 0 ;
goto V_89;
}
V_88 = F_21 ( & V_21 [ V_74 ] ) ;
V_89:
F_80 ( & V_49 -> V_86 , V_58 ) ;
return V_88 ;
}
static void F_84 ( struct V_48 * V_49 , T_2 V_73 , T_2 V_74 )
{
struct V_15 * V_16 ;
struct V_20 * V_21 ;
unsigned long V_58 ;
F_79 ( & V_49 -> V_86 , V_58 ) ;
V_16 = & V_49 -> V_15 [ V_73 ] ;
V_21 = F_19 ( V_16 ) ;
if ( V_21 ) {
F_28 ( & V_21 [ V_74 ] ) ;
F_81 ( V_49 , & V_21 [ V_74 ] , \
sizeof( * V_21 ) ) ;
}
F_80 ( & V_49 -> V_86 , V_58 ) ;
}
static void F_85 ( struct V_48 * V_49 )
{
struct V_15 * V_16 ;
int V_64 ;
unsigned long V_58 ;
struct V_20 * V_21 ;
F_79 ( & V_49 -> V_86 , V_58 ) ;
if ( ! V_49 -> V_15 ) {
goto V_89;
}
for ( V_64 = 0 ; V_64 < V_90 ; V_64 ++ ) {
V_16 = & V_49 -> V_15 [ V_64 ] ;
V_21 = F_19 ( V_16 ) ;
if ( V_21 )
F_46 ( V_21 ) ;
}
F_46 ( V_49 -> V_15 ) ;
V_49 -> V_15 = NULL ;
V_89:
F_80 ( & V_49 -> V_86 , V_58 ) ;
}
static struct V_25 * F_86 ( struct V_55 * V_56 ,
unsigned long V_5 , int V_91 )
{
int V_92 = F_2 ( V_56 -> V_1 ) - V_10 ;
struct V_25 * V_93 , * V_26 = NULL ;
int V_4 = F_1 ( V_56 -> V_1 ) ;
int V_94 ;
F_62 ( ! V_56 -> V_95 ) ;
F_62 ( V_92 < V_96 && V_5 > > V_92 ) ;
V_93 = V_56 -> V_95 ;
while ( V_4 > 0 ) {
void * V_97 ;
V_94 = F_5 ( V_5 , V_4 ) ;
V_26 = & V_93 [ V_94 ] ;
if ( ! V_91 && ( F_39 ( V_26 ) || ! F_38 ( V_26 ) ) )
break;
if ( V_4 == V_91 )
break;
if ( ! F_38 ( V_26 ) ) {
V_31 V_98 ;
V_97 = F_43 ( V_56 -> V_99 ) ;
if ( ! V_97 )
return NULL ;
F_76 ( V_56 , V_97 , V_100 ) ;
V_98 = ( ( V_31 ) F_14 ( V_97 ) << V_10 ) | V_27 | V_28 ;
if ( F_87 ( & V_26 -> V_17 , 0ULL , V_98 ) ) {
F_46 ( V_97 ) ;
} else {
F_34 ( V_26 ) ;
F_76 ( V_56 , V_26 , sizeof( * V_26 ) ) ;
}
}
V_93 = F_20 ( F_34 ( V_26 ) ) ;
V_4 -- ;
}
return V_26 ;
}
static struct V_25 * F_88 ( struct V_55 * V_56 ,
unsigned long V_5 ,
int V_4 , int * V_101 )
{
struct V_25 * V_93 , * V_26 = NULL ;
int V_102 = F_1 ( V_56 -> V_1 ) ;
int V_94 ;
V_93 = V_56 -> V_95 ;
while ( V_4 <= V_102 ) {
V_94 = F_5 ( V_5 , V_102 ) ;
V_26 = & V_93 [ V_94 ] ;
if ( V_4 == V_102 )
return V_26 ;
if ( ! F_38 ( V_26 ) ) {
* V_101 = V_102 ;
break;
}
if ( V_26 -> V_17 & V_103 ) {
* V_101 = V_102 ;
return V_26 ;
}
V_93 = F_20 ( F_34 ( V_26 ) ) ;
V_102 -- ;
}
return NULL ;
}
static int F_89 ( struct V_55 * V_56 ,
unsigned long V_104 ,
unsigned long V_105 )
{
int V_92 = F_2 ( V_56 -> V_1 ) - V_10 ;
unsigned int V_101 = 1 ;
struct V_25 * V_106 , * V_26 ;
int V_107 ;
F_62 ( V_92 < V_96 && V_104 > > V_92 ) ;
F_62 ( V_92 < V_96 && V_105 > > V_92 ) ;
F_62 ( V_104 > V_105 ) ;
do {
V_101 = 1 ;
V_106 = V_26 = F_88 ( V_56 , V_104 , 1 , & V_101 ) ;
if ( ! V_26 ) {
V_104 = F_8 ( V_104 + 1 , V_101 + 1 ) ;
continue;
}
do {
F_29 ( V_26 ) ;
V_104 += F_9 ( V_101 ) ;
V_26 ++ ;
} while ( V_104 <= V_105 && ! F_40 ( V_26 ) );
F_76 ( V_56 , V_106 ,
( void * ) V_26 - ( void * ) V_106 ) ;
} while ( V_104 && V_104 <= V_105 );
V_107 = ( V_101 - 1 ) * 9 ;
return V_107 ;
}
static void F_90 ( struct V_55 * V_56 , int V_4 ,
struct V_25 * V_26 , unsigned long V_5 ,
unsigned long V_104 , unsigned long V_105 )
{
V_5 = F_91 ( V_104 , V_5 ) ;
V_26 = & V_26 [ F_5 ( V_5 , V_4 ) ] ;
do {
unsigned long V_108 ;
struct V_25 * V_109 ;
if ( ! F_38 ( V_26 ) || F_39 ( V_26 ) )
goto V_110;
V_108 = V_5 & F_6 ( V_4 - 1 ) ;
V_109 = F_20 ( F_34 ( V_26 ) ) ;
if ( V_4 > 2 )
F_90 ( V_56 , V_4 - 1 , V_109 ,
V_108 , V_104 , V_105 ) ;
if ( ! ( V_104 > V_108 ||
V_105 < V_108 + F_7 ( V_4 ) ) ) {
F_29 ( V_26 ) ;
F_76 ( V_56 , V_26 , sizeof( * V_26 ) ) ;
F_46 ( V_109 ) ;
}
V_110:
V_5 += F_7 ( V_4 ) ;
} while ( ! F_40 ( ++ V_26 ) && V_5 <= V_105 );
}
static void F_92 ( struct V_55 * V_56 ,
unsigned long V_104 ,
unsigned long V_105 )
{
int V_92 = F_2 ( V_56 -> V_1 ) - V_10 ;
F_62 ( V_92 < V_96 && V_104 > > V_92 ) ;
F_62 ( V_92 < V_96 && V_105 > > V_92 ) ;
F_62 ( V_104 > V_105 ) ;
F_90 ( V_56 , F_1 ( V_56 -> V_1 ) ,
V_56 -> V_95 , 0 , V_104 , V_105 ) ;
if ( V_104 == 0 && V_105 == F_93 ( V_56 -> V_111 ) ) {
F_46 ( V_56 -> V_95 ) ;
V_56 -> V_95 = NULL ;
}
}
static int F_94 ( struct V_48 * V_49 )
{
struct V_15 * V_16 ;
unsigned long V_58 ;
V_16 = (struct V_15 * ) F_43 ( V_49 -> V_40 ) ;
if ( ! V_16 )
return - V_112 ;
F_81 ( V_49 , V_16 , V_113 ) ;
F_79 ( & V_49 -> V_86 , V_58 ) ;
V_49 -> V_15 = V_16 ;
F_80 ( & V_49 -> V_86 , V_58 ) ;
return 0 ;
}
static void F_95 ( struct V_48 * V_49 )
{
void * V_83 ;
T_3 V_114 ;
unsigned long V_115 ;
V_83 = V_49 -> V_15 ;
F_96 ( & V_49 -> V_116 , V_115 ) ;
F_97 ( V_49 -> V_117 + V_118 , F_82 ( V_83 ) ) ;
F_98 ( V_49 -> V_119 | V_120 , V_49 -> V_117 + V_121 ) ;
F_99 ( V_49 , V_122 ,
V_123 , ( V_114 & V_124 ) , V_114 ) ;
F_100 ( & V_49 -> V_116 , V_115 ) ;
}
static void F_101 ( struct V_48 * V_49 )
{
T_3 V_17 ;
unsigned long V_115 ;
if ( ! V_125 && ! F_102 ( V_49 -> V_52 ) )
return;
F_96 ( & V_49 -> V_116 , V_115 ) ;
F_98 ( V_49 -> V_119 | V_126 , V_49 -> V_117 + V_121 ) ;
F_99 ( V_49 , V_122 ,
V_123 , ( ! ( V_17 & V_127 ) ) , V_17 ) ;
F_100 ( & V_49 -> V_116 , V_115 ) ;
}
static void F_103 ( struct V_48 * V_49 ,
T_4 V_128 , T_4 V_129 , T_2 V_130 ,
V_23 type )
{
V_23 V_17 = 0 ;
unsigned long V_115 ;
switch ( type ) {
case V_131 :
V_17 = V_131 ;
break;
case V_132 :
V_17 = V_132 | F_104 ( V_128 ) ;
break;
case V_133 :
V_17 = V_133 | F_104 ( V_128 )
| F_105 ( V_129 ) | F_106 ( V_130 ) ;
break;
default:
F_107 () ;
}
V_17 |= V_134 ;
F_96 ( & V_49 -> V_116 , V_115 ) ;
F_97 ( V_49 -> V_117 + V_135 , V_17 ) ;
F_99 ( V_49 , V_135 ,
V_136 , ( ! ( V_17 & V_134 ) ) , V_17 ) ;
F_100 ( & V_49 -> V_116 , V_115 ) ;
}
static void F_108 ( struct V_48 * V_49 , T_4 V_128 ,
V_23 V_83 , unsigned int V_137 , V_23 type )
{
int V_138 = F_109 ( V_49 -> V_66 ) ;
V_23 V_17 = 0 , V_139 = 0 ;
unsigned long V_115 ;
switch ( type ) {
case V_140 :
V_17 = V_140 | V_141 ;
break;
case V_142 :
V_17 = V_142 | V_141 | F_110 ( V_128 ) ;
break;
case V_143 :
V_17 = V_143 | V_141 | F_110 ( V_128 ) ;
V_139 = V_137 | V_83 ;
break;
default:
F_107 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_111 ( V_49 -> V_52 ) )
V_17 |= V_144 ;
F_96 ( & V_49 -> V_116 , V_115 ) ;
if ( V_139 )
F_97 ( V_49 -> V_117 + V_138 , V_139 ) ;
F_97 ( V_49 -> V_117 + V_138 + 8 , V_17 ) ;
F_99 ( V_49 , V_138 + 8 ,
V_136 , ( ! ( V_17 & V_141 ) ) , V_17 ) ;
F_100 ( & V_49 -> V_116 , V_115 ) ;
if ( F_112 ( V_17 ) == 0 )
F_42 ( V_145 L_14 ) ;
if ( F_112 ( V_17 ) != F_113 ( type ) )
F_114 ( L_15 ,
( unsigned long long ) F_113 ( type ) ,
( unsigned long long ) F_112 ( V_17 ) ) ;
}
static struct V_146 * F_115 (
struct V_55 * V_56 , int V_72 , T_2 V_73 , T_2 V_74 )
{
int V_147 = 0 ;
unsigned long V_58 ;
struct V_146 * V_148 ;
struct V_48 * V_49 = F_74 ( V_72 , V_73 , V_74 ) ;
if ( ! F_116 ( V_49 -> V_66 ) )
return NULL ;
if ( ! V_49 -> V_149 )
return NULL ;
F_79 ( & V_150 , V_58 ) ;
F_117 (info, &domain->devices, link)
if ( V_148 -> V_73 == V_73 && V_148 -> V_74 == V_74 ) {
V_147 = 1 ;
break;
}
F_80 ( & V_150 , V_58 ) ;
if ( ! V_147 || ! V_148 -> V_151 )
return NULL ;
if ( ! F_118 ( V_148 -> V_151 , V_152 ) )
return NULL ;
if ( ! F_119 ( V_148 -> V_151 ) )
return NULL ;
V_148 -> V_49 = V_49 ;
return V_148 ;
}
static void F_120 ( struct V_146 * V_148 )
{
if ( ! V_148 )
return;
F_121 ( V_148 -> V_151 , V_10 ) ;
}
static void F_122 ( struct V_146 * V_148 )
{
if ( ! V_148 -> V_151 || ! F_123 ( V_148 -> V_151 ) )
return;
F_124 ( V_148 -> V_151 ) ;
}
static void F_125 ( struct V_55 * V_56 ,
V_23 V_83 , unsigned V_70 )
{
T_4 V_153 , V_154 ;
unsigned long V_58 ;
struct V_146 * V_148 ;
F_79 ( & V_150 , V_58 ) ;
F_117 (info, &domain->devices, link) {
if ( ! V_148 -> V_151 || ! F_123 ( V_148 -> V_151 ) )
continue;
V_153 = V_148 -> V_73 << 8 | V_148 -> V_74 ;
V_154 = F_126 ( V_148 -> V_151 ) ;
F_127 ( V_148 -> V_49 , V_153 , V_154 , V_83 , V_70 ) ;
}
F_80 ( & V_150 , V_58 ) ;
}
static void F_128 ( struct V_48 * V_49 , T_4 V_128 ,
unsigned long V_5 , unsigned int V_155 , int V_156 )
{
unsigned int V_70 = F_129 ( F_130 ( V_155 ) ) ;
V_31 V_83 = ( V_31 ) V_5 << V_10 ;
F_62 ( V_155 == 0 ) ;
if ( ! F_131 ( V_49 -> V_52 ) || V_70 > F_132 ( V_49 -> V_52 ) )
V_49 -> V_157 . V_158 ( V_49 , V_128 , 0 , 0 ,
V_142 ) ;
else
V_49 -> V_157 . V_158 ( V_49 , V_128 , V_83 , V_70 ,
V_143 ) ;
if ( ! F_133 ( V_49 -> V_52 ) || ! V_156 )
F_125 ( V_49 -> V_159 [ V_128 ] , V_83 , V_70 ) ;
}
static void F_134 ( struct V_48 * V_49 )
{
T_3 V_160 ;
unsigned long V_58 ;
F_96 ( & V_49 -> V_116 , V_58 ) ;
V_160 = V_123 ( V_49 -> V_117 + V_161 ) ;
V_160 &= ~ V_162 ;
F_98 ( V_160 , V_49 -> V_117 + V_161 ) ;
F_99 ( V_49 , V_161 ,
V_123 , ! ( V_160 & V_163 ) , V_160 ) ;
F_100 ( & V_49 -> V_116 , V_58 ) ;
}
static int F_135 ( struct V_48 * V_49 )
{
T_3 V_114 ;
unsigned long V_58 ;
F_96 ( & V_49 -> V_116 , V_58 ) ;
V_49 -> V_119 |= V_164 ;
F_98 ( V_49 -> V_119 , V_49 -> V_117 + V_121 ) ;
F_99 ( V_49 , V_122 ,
V_123 , ( V_114 & V_165 ) , V_114 ) ;
F_100 ( & V_49 -> V_116 , V_58 ) ;
return 0 ;
}
static int F_136 ( struct V_48 * V_49 )
{
T_3 V_114 ;
unsigned long V_115 ;
F_96 ( & V_49 -> V_116 , V_115 ) ;
V_49 -> V_119 &= ~ V_164 ;
F_98 ( V_49 -> V_119 , V_49 -> V_117 + V_121 ) ;
F_99 ( V_49 , V_122 ,
V_123 , ( ! ( V_114 & V_165 ) ) , V_114 ) ;
F_100 ( & V_49 -> V_116 , V_115 ) ;
return 0 ;
}
static int F_137 ( struct V_48 * V_49 )
{
unsigned long V_166 ;
unsigned long V_167 ;
V_166 = F_138 ( V_49 -> V_52 ) ;
F_114 ( L_16 , V_49 -> V_168 ,
V_166 ) ;
V_167 = F_139 ( V_166 ) ;
F_140 ( & V_49 -> V_86 ) ;
V_49 -> V_169 = F_141 ( V_167 , sizeof( unsigned long ) , V_170 ) ;
if ( ! V_49 -> V_169 ) {
F_42 ( V_145 L_17 ) ;
return - V_112 ;
}
V_49 -> V_159 = F_141 ( V_166 , sizeof( struct V_55 * ) ,
V_170 ) ;
if ( ! V_49 -> V_159 ) {
F_42 ( V_145 L_18 ) ;
return - V_112 ;
}
if ( F_133 ( V_49 -> V_52 ) )
F_142 ( 0 , V_49 -> V_169 ) ;
return 0 ;
}
void F_143 ( struct V_48 * V_49 )
{
struct V_55 * V_56 ;
int V_64 ;
unsigned long V_58 ;
if ( ( V_49 -> V_159 ) && ( V_49 -> V_169 ) ) {
F_65 (i, iommu->domain_ids, cap_ndoms(iommu->cap)) {
V_56 = V_49 -> V_159 [ V_64 ] ;
F_144 ( V_64 , V_49 -> V_169 ) ;
F_79 ( & V_56 -> V_171 , V_58 ) ;
if ( -- V_56 -> V_172 == 0 ) {
if ( V_56 -> V_58 & V_59 )
F_145 ( V_56 ) ;
else
F_146 ( V_56 ) ;
}
F_80 ( & V_56 -> V_171 , V_58 ) ;
}
}
if ( V_49 -> V_119 & V_164 )
F_136 ( V_49 ) ;
if ( V_49 -> V_173 ) {
F_147 ( V_49 -> V_173 , NULL ) ;
F_148 ( V_49 -> V_173 , V_49 ) ;
F_149 ( V_49 -> V_173 ) ;
}
F_150 ( V_49 -> V_159 ) ;
F_150 ( V_49 -> V_169 ) ;
V_63 [ V_49 -> V_168 ] = NULL ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
if ( V_63 [ V_64 ] )
break;
}
if ( V_64 == V_62 )
F_150 ( V_63 ) ;
F_85 ( V_49 ) ;
}
static struct V_55 * F_151 ( void )
{
struct V_55 * V_56 ;
V_56 = F_48 () ;
if ( ! V_56 )
return NULL ;
V_56 -> V_99 = - 1 ;
memset ( V_56 -> V_61 , 0 , sizeof( V_56 -> V_61 ) ) ;
V_56 -> V_58 = 0 ;
return V_56 ;
}
static int F_152 ( struct V_55 * V_56 ,
struct V_48 * V_49 )
{
int V_174 ;
unsigned long V_166 ;
unsigned long V_58 ;
V_166 = F_138 ( V_49 -> V_52 ) ;
F_79 ( & V_49 -> V_86 , V_58 ) ;
V_174 = F_153 ( V_49 -> V_169 , V_166 ) ;
if ( V_174 >= V_166 ) {
F_80 ( & V_49 -> V_86 , V_58 ) ;
F_42 ( V_145 L_19 ) ;
return - V_112 ;
}
V_56 -> V_175 = V_174 ;
F_142 ( V_174 , V_49 -> V_169 ) ;
F_142 ( V_49 -> V_168 , V_56 -> V_61 ) ;
V_49 -> V_159 [ V_174 ] = V_56 ;
F_80 ( & V_49 -> V_86 , V_58 ) ;
return 0 ;
}
static void F_154 ( struct V_55 * V_56 ,
struct V_48 * V_49 )
{
unsigned long V_58 ;
int V_174 , V_166 ;
int V_147 = 0 ;
F_79 ( & V_49 -> V_86 , V_58 ) ;
V_166 = F_138 ( V_49 -> V_52 ) ;
F_65 (num, iommu->domain_ids, ndomains) {
if ( V_49 -> V_159 [ V_174 ] == V_56 ) {
V_147 = 1 ;
break;
}
}
if ( V_147 ) {
F_144 ( V_174 , V_49 -> V_169 ) ;
F_144 ( V_49 -> V_168 , V_56 -> V_61 ) ;
V_49 -> V_159 [ V_174 ] = NULL ;
}
F_80 ( & V_49 -> V_86 , V_58 ) ;
}
static int F_155 ( void )
{
struct V_176 * V_177 = NULL ;
struct V_46 * V_46 ;
int V_64 ;
F_156 ( & V_178 , V_179 ) ;
F_157 ( & V_178 . V_180 ,
& V_181 ) ;
V_46 = F_158 ( & V_178 , F_159 ( V_182 ) ,
F_159 ( V_183 ) ) ;
if ( ! V_46 ) {
F_42 ( V_145 L_20 ) ;
return - V_184 ;
}
F_160 (pdev) {
struct V_185 * V_186 ;
for ( V_64 = 0 ; V_64 < V_187 ; V_64 ++ ) {
V_186 = & V_177 -> V_185 [ V_64 ] ;
if ( ! V_186 -> V_58 || ! ( V_186 -> V_58 & V_188 ) )
continue;
V_46 = F_158 ( & V_178 ,
F_159 ( V_186 -> V_189 ) ,
F_159 ( V_186 -> V_81 ) ) ;
if ( ! V_46 ) {
F_42 ( V_145 L_21 ) ;
return - V_184 ;
}
}
}
return 0 ;
}
static void F_161 ( struct V_55 * V_56 )
{
F_162 ( & V_178 , & V_56 -> V_190 ) ;
}
static inline int F_163 ( int V_111 )
{
int V_1 ;
int V_186 = ( V_111 - 12 ) % 9 ;
if ( V_186 == 0 )
V_1 = V_111 ;
else
V_1 = V_111 + 9 - V_186 ;
if ( V_1 > 64 )
V_1 = 64 ;
return V_1 ;
}
static int F_164 ( struct V_55 * V_56 , int V_191 )
{
struct V_48 * V_49 ;
int V_192 , V_1 ;
unsigned long V_51 ;
F_156 ( & V_56 -> V_190 , V_179 ) ;
F_140 ( & V_56 -> V_171 ) ;
F_161 ( V_56 ) ;
V_49 = F_61 ( V_56 ) ;
if ( V_191 > F_165 ( V_49 -> V_52 ) )
V_191 = F_165 ( V_49 -> V_52 ) ;
V_56 -> V_111 = V_191 ;
V_192 = F_163 ( V_191 ) ;
V_1 = F_3 ( V_192 ) ;
V_51 = F_57 ( V_49 -> V_52 ) ;
if ( ! F_58 ( V_1 , & V_51 ) ) {
F_114 ( L_22 , V_1 ) ;
V_1 = F_166 ( & V_51 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_184 ;
}
V_56 -> V_1 = V_1 ;
F_167 ( & V_56 -> V_77 ) ;
if ( F_66 ( V_49 -> V_66 ) )
V_56 -> V_65 = 1 ;
else
V_56 -> V_65 = 0 ;
if ( F_68 ( V_49 -> V_66 ) )
V_56 -> V_67 = 1 ;
else
V_56 -> V_67 = 0 ;
V_56 -> V_71 = F_72 ( F_71 ( V_49 -> V_52 ) ) ;
V_56 -> V_172 = 1 ;
V_56 -> V_99 = V_49 -> V_40 ;
V_56 -> V_95 = (struct V_25 * ) F_43 ( V_56 -> V_99 ) ;
if ( ! V_56 -> V_95 )
return - V_112 ;
F_81 ( V_49 , V_56 -> V_95 , V_193 ) ;
return 0 ;
}
static void F_146 ( struct V_55 * V_56 )
{
struct V_68 * V_69 ;
struct V_48 * V_49 ;
if ( ! V_56 )
return;
if ( ! V_38 )
F_168 ( 0 ) ;
F_169 ( V_56 ) ;
F_170 ( & V_56 -> V_190 ) ;
F_89 ( V_56 , 0 , F_93 ( V_56 -> V_111 ) ) ;
F_92 ( V_56 , 0 , F_93 ( V_56 -> V_111 ) ) ;
F_70 (iommu, drhd)
if ( F_58 ( V_49 -> V_168 , V_56 -> V_61 ) )
F_154 ( V_56 , V_49 ) ;
F_50 ( V_56 ) ;
}
static int F_171 ( struct V_55 * V_56 , int V_72 ,
T_2 V_73 , T_2 V_74 , int V_194 )
{
struct V_20 * V_21 ;
unsigned long V_58 ;
struct V_48 * V_49 ;
struct V_25 * V_95 ;
unsigned long V_174 ;
unsigned long V_166 ;
int V_175 ;
int V_1 ;
struct V_146 * V_148 = NULL ;
F_114 ( L_23 ,
V_73 , F_172 ( V_74 ) , F_173 ( V_74 ) ) ;
F_62 ( ! V_56 -> V_95 ) ;
F_62 ( V_194 != V_195 &&
V_194 != V_196 ) ;
V_49 = F_74 ( V_72 , V_73 , V_74 ) ;
if ( ! V_49 )
return - V_184 ;
V_21 = F_78 ( V_49 , V_73 , V_74 ) ;
if ( ! V_21 )
return - V_112 ;
F_79 ( & V_49 -> V_86 , V_58 ) ;
if ( F_21 ( V_21 ) ) {
F_80 ( & V_49 -> V_86 , V_58 ) ;
return 0 ;
}
V_175 = V_56 -> V_175 ;
V_95 = V_56 -> V_95 ;
if ( V_56 -> V_58 & V_59 ||
V_56 -> V_58 & V_60 ) {
int V_147 = 0 ;
V_166 = F_138 ( V_49 -> V_52 ) ;
F_65 (num, iommu->domain_ids, ndomains) {
if ( V_49 -> V_159 [ V_174 ] == V_56 ) {
V_175 = V_174 ;
V_147 = 1 ;
break;
}
}
if ( V_147 == 0 ) {
V_174 = F_153 ( V_49 -> V_169 , V_166 ) ;
if ( V_174 >= V_166 ) {
F_80 ( & V_49 -> V_86 , V_58 ) ;
F_42 ( V_145 L_19 ) ;
return - V_197 ;
}
F_142 ( V_174 , V_49 -> V_169 ) ;
V_49 -> V_159 [ V_174 ] = V_56 ;
V_175 = V_174 ;
}
if ( V_194 != V_195 ) {
for ( V_1 = V_56 -> V_1 ; V_1 != V_49 -> V_1 ; V_1 -- ) {
V_95 = F_20 ( F_34 ( V_95 ) ) ;
if ( ! F_38 ( V_95 ) ) {
F_80 ( & V_49 -> V_86 , V_58 ) ;
return - V_112 ;
}
}
}
}
F_27 ( V_21 , V_175 ) ;
if ( V_194 != V_195 ) {
V_148 = F_115 ( V_56 , V_72 , V_73 , V_74 ) ;
V_194 = V_148 ? V_198 :
V_196 ;
}
if ( F_174 ( V_194 == V_195 ) )
F_26 ( V_21 , V_49 -> V_199 ) ;
else {
F_25 ( V_21 , F_82 ( V_95 ) ) ;
F_26 ( V_21 , V_49 -> V_1 ) ;
}
F_24 ( V_21 , V_194 ) ;
F_23 ( V_21 ) ;
F_22 ( V_21 ) ;
F_76 ( V_56 , V_21 , sizeof( * V_21 ) ) ;
if ( F_133 ( V_49 -> V_52 ) ) {
V_49 -> V_157 . V_200 ( V_49 , 0 ,
( ( ( T_4 ) V_73 ) << 8 ) | V_74 ,
V_201 ,
V_133 ) ;
V_49 -> V_157 . V_158 ( V_49 , V_56 -> V_175 , 0 , 0 , V_142 ) ;
} else {
F_101 ( V_49 ) ;
}
F_120 ( V_148 ) ;
F_80 ( & V_49 -> V_86 , V_58 ) ;
F_79 ( & V_56 -> V_171 , V_58 ) ;
if ( ! F_175 ( V_49 -> V_168 , V_56 -> V_61 ) ) {
V_56 -> V_172 ++ ;
if ( V_56 -> V_172 == 1 )
V_56 -> V_99 = V_49 -> V_40 ;
F_73 ( V_56 ) ;
}
F_80 ( & V_56 -> V_171 , V_58 ) ;
return 0 ;
}
static int
F_176 ( struct V_55 * V_56 , struct V_176 * V_177 ,
int V_194 )
{
int V_88 ;
struct V_176 * V_202 , * V_93 ;
V_88 = F_171 ( V_56 , F_177 ( V_177 -> V_73 ) ,
V_177 -> V_73 -> V_78 , V_177 -> V_74 ,
V_194 ) ;
if ( V_88 )
return V_88 ;
V_202 = F_178 ( V_177 ) ;
if ( ! V_202 )
return 0 ;
V_93 = V_177 -> V_73 -> V_203 ;
while ( V_93 != V_202 ) {
V_88 = F_171 ( V_56 ,
F_177 ( V_93 -> V_73 ) ,
V_93 -> V_73 -> V_78 ,
V_93 -> V_74 , V_194 ) ;
if ( V_88 )
return V_88 ;
V_93 = V_93 -> V_73 -> V_203 ;
}
if ( F_179 ( V_202 ) )
return F_171 ( V_56 ,
F_177 ( V_202 -> V_79 ) ,
V_202 -> V_79 -> V_78 , 0 ,
V_194 ) ;
else
return F_171 ( V_56 ,
F_177 ( V_202 -> V_73 ) ,
V_202 -> V_73 -> V_78 ,
V_202 -> V_74 ,
V_194 ) ;
}
static int F_180 ( struct V_176 * V_177 )
{
int V_88 ;
struct V_176 * V_202 , * V_93 ;
struct V_48 * V_49 ;
V_49 = F_74 ( F_177 ( V_177 -> V_73 ) , V_177 -> V_73 -> V_78 ,
V_177 -> V_74 ) ;
if ( ! V_49 )
return - V_184 ;
V_88 = F_83 ( V_49 , V_177 -> V_73 -> V_78 , V_177 -> V_74 ) ;
if ( ! V_88 )
return V_88 ;
V_202 = F_178 ( V_177 ) ;
if ( ! V_202 )
return V_88 ;
V_93 = V_177 -> V_73 -> V_203 ;
while ( V_93 != V_202 ) {
V_88 = F_83 ( V_49 , V_93 -> V_73 -> V_78 ,
V_93 -> V_74 ) ;
if ( ! V_88 )
return V_88 ;
V_93 = V_93 -> V_73 -> V_203 ;
}
if ( F_179 ( V_202 ) )
return F_83 ( V_49 , V_202 -> V_79 -> V_78 ,
0 ) ;
else
return F_83 ( V_49 , V_202 -> V_73 -> V_78 ,
V_202 -> V_74 ) ;
}
static inline unsigned long F_181 ( unsigned long V_204 ,
T_5 V_84 )
{
V_204 &= ~ V_205 ;
return F_182 ( V_204 + V_84 ) >> V_10 ;
}
static inline int F_183 ( struct V_55 * V_56 ,
unsigned long V_206 ,
unsigned long V_207 ,
unsigned long V_155 )
{
int V_208 , V_4 = 1 ;
unsigned long V_209 ;
V_208 = V_56 -> V_71 ;
V_209 = V_206 | V_207 ;
while ( V_208 && ! ( V_209 & ~ V_210 ) ) {
V_155 >>= V_211 ;
if ( ! V_155 )
break;
V_209 >>= V_211 ;
V_4 ++ ;
V_208 -- ;
}
return V_4 ;
}
static int F_184 ( struct V_55 * V_56 , unsigned long V_206 ,
struct V_212 * V_213 , unsigned long V_214 ,
unsigned long V_215 , int V_30 )
{
struct V_25 * V_106 = NULL , * V_26 = NULL ;
T_6 V_216 ( V_98 ) ;
int V_92 = F_2 ( V_56 -> V_1 ) - V_10 ;
unsigned long V_217 ;
unsigned int V_218 = 0 ;
unsigned long V_219 = 0 ;
F_62 ( V_92 < V_96 && ( V_206 + V_215 - 1 ) > > V_92 ) ;
if ( ( V_30 & ( V_27 | V_28 ) ) == 0 )
return - V_33 ;
V_30 &= V_27 | V_28 | V_29 ;
if ( V_213 )
V_217 = 0 ;
else {
V_217 = V_215 + 1 ;
V_98 = ( ( T_6 ) V_214 << V_10 ) | V_30 ;
}
while ( V_215 > 0 ) {
V_31 V_202 ;
if ( ! V_217 ) {
V_217 = F_181 ( V_213 -> V_94 , V_213 -> V_220 ) ;
V_213 -> V_221 = ( ( V_222 ) V_206 << V_10 ) + V_213 -> V_94 ;
V_213 -> V_223 = V_213 -> V_220 ;
V_98 = F_185 ( F_186 ( V_213 ) ) | V_30 ;
V_214 = V_98 >> V_10 ;
}
if ( ! V_26 ) {
V_218 = F_183 ( V_56 , V_206 , V_214 , V_217 ) ;
V_106 = V_26 = F_86 ( V_56 , V_206 , V_218 ) ;
if ( ! V_26 )
return - V_112 ;
if ( V_218 > 1 ) {
V_98 |= V_103 ;
F_89 ( V_56 , V_206 ,
V_206 + F_9 ( V_218 ) - 1 ) ;
F_92 ( V_56 , V_206 ,
V_206 + F_9 ( V_218 ) - 1 ) ;
} else {
V_98 &= ~ ( V_31 ) V_103 ;
}
}
V_202 = F_187 ( & V_26 -> V_17 , 0ULL , V_98 ) ;
if ( V_202 ) {
static int V_224 = 5 ;
F_42 ( V_225 L_24 ,
V_206 , V_202 , ( unsigned long long ) V_98 ) ;
if ( V_224 ) {
V_224 -- ;
F_188 ( NULL ) ;
}
F_189 ( 1 ) ;
}
V_219 = F_9 ( V_218 ) ;
F_62 ( V_215 < V_219 ) ;
F_62 ( V_217 < V_219 ) ;
V_215 -= V_219 ;
V_206 += V_219 ;
V_214 += V_219 ;
V_98 += V_219 * V_100 ;
V_217 -= V_219 ;
V_26 ++ ;
if ( ! V_215 || F_40 ( V_26 ) ||
( V_218 > 1 && V_217 < V_219 ) ) {
F_76 ( V_56 , V_106 ,
( void * ) V_26 - ( void * ) V_106 ) ;
V_26 = NULL ;
}
if ( ! V_217 && V_215 )
V_213 = F_190 ( V_213 ) ;
}
return 0 ;
}
static inline int F_191 ( struct V_55 * V_56 , unsigned long V_206 ,
struct V_212 * V_213 , unsigned long V_215 ,
int V_30 )
{
return F_184 ( V_56 , V_206 , V_213 , 0 , V_215 , V_30 ) ;
}
static inline int F_192 ( struct V_55 * V_56 , unsigned long V_206 ,
unsigned long V_214 , unsigned long V_215 ,
int V_30 )
{
return F_184 ( V_56 , V_206 , NULL , V_214 , V_215 , V_30 ) ;
}
static void F_193 ( struct V_48 * V_49 , T_2 V_73 , T_2 V_74 )
{
if ( ! V_49 )
return;
F_84 ( V_49 , V_73 , V_74 ) ;
V_49 -> V_157 . V_200 ( V_49 , 0 , 0 , 0 ,
V_131 ) ;
V_49 -> V_157 . V_158 ( V_49 , 0 , 0 , 0 , V_140 ) ;
}
static inline void F_194 ( struct V_146 * V_148 )
{
F_195 ( & V_150 ) ;
F_196 ( & V_148 -> V_226 ) ;
F_196 ( & V_148 -> V_227 ) ;
if ( V_148 -> V_151 )
V_148 -> V_151 -> V_151 . V_228 . V_49 = NULL ;
}
static void F_169 ( struct V_55 * V_56 )
{
struct V_146 * V_148 ;
unsigned long V_58 ;
struct V_48 * V_49 ;
F_79 ( & V_150 , V_58 ) ;
while ( ! F_197 ( & V_56 -> V_77 ) ) {
V_148 = F_198 ( V_56 -> V_77 . V_110 ,
struct V_146 , V_226 ) ;
F_194 ( V_148 ) ;
F_80 ( & V_150 , V_58 ) ;
F_122 ( V_148 ) ;
V_49 = F_74 ( V_148 -> V_72 , V_148 -> V_73 , V_148 -> V_74 ) ;
F_193 ( V_49 , V_148 -> V_73 , V_148 -> V_74 ) ;
F_53 ( V_148 ) ;
F_79 ( & V_150 , V_58 ) ;
}
F_80 ( & V_150 , V_58 ) ;
}
static struct V_55 *
F_199 ( struct V_176 * V_177 )
{
struct V_146 * V_148 ;
V_148 = V_177 -> V_151 . V_228 . V_49 ;
if ( V_148 )
return V_148 -> V_56 ;
return NULL ;
}
static struct V_55 * F_200 ( struct V_176 * V_177 , int V_111 )
{
struct V_55 * V_56 , * V_147 = NULL ;
struct V_48 * V_49 ;
struct V_68 * V_69 ;
struct V_146 * V_148 , * V_202 ;
struct V_176 * V_229 ;
unsigned long V_58 ;
int V_73 = 0 , V_74 = 0 ;
int V_72 ;
int V_88 ;
V_56 = F_199 ( V_177 ) ;
if ( V_56 )
return V_56 ;
V_72 = F_177 ( V_177 -> V_73 ) ;
V_229 = F_178 ( V_177 ) ;
if ( V_229 ) {
if ( F_179 ( V_229 ) ) {
V_73 = V_229 -> V_79 -> V_78 ;
V_74 = 0 ;
} else {
V_73 = V_229 -> V_73 -> V_78 ;
V_74 = V_229 -> V_74 ;
}
F_79 ( & V_150 , V_58 ) ;
F_117 (info, &device_domain_list, global) {
if ( V_148 -> V_72 == V_72 &&
V_148 -> V_73 == V_73 && V_148 -> V_74 == V_74 ) {
V_147 = V_148 -> V_56 ;
break;
}
}
F_80 ( & V_150 , V_58 ) ;
if ( V_147 ) {
V_56 = V_147 ;
goto V_230;
}
}
V_56 = F_151 () ;
if ( ! V_56 )
goto error;
V_69 = F_201 ( V_177 ) ;
if ( ! V_69 ) {
F_42 ( V_145 L_25 ,
F_202 ( V_177 ) ) ;
F_50 ( V_56 ) ;
return NULL ;
}
V_49 = V_69 -> V_49 ;
V_88 = F_152 ( V_56 , V_49 ) ;
if ( V_88 ) {
F_50 ( V_56 ) ;
goto error;
}
if ( F_164 ( V_56 , V_111 ) ) {
F_146 ( V_56 ) ;
goto error;
}
if ( V_229 ) {
V_148 = F_52 () ;
if ( ! V_148 ) {
F_146 ( V_56 ) ;
goto error;
}
V_148 -> V_72 = V_72 ;
V_148 -> V_73 = V_73 ;
V_148 -> V_74 = V_74 ;
V_148 -> V_151 = NULL ;
V_148 -> V_56 = V_56 ;
V_56 -> V_58 |= V_231 ;
V_147 = NULL ;
F_79 ( & V_150 , V_58 ) ;
F_117 (tmp, &device_domain_list, global) {
if ( V_202 -> V_72 == V_72 &&
V_202 -> V_73 == V_73 && V_202 -> V_74 == V_74 ) {
V_147 = V_202 -> V_56 ;
break;
}
}
if ( V_147 ) {
F_80 ( & V_150 , V_58 ) ;
F_53 ( V_148 ) ;
F_146 ( V_56 ) ;
V_56 = V_147 ;
} else {
F_203 ( & V_148 -> V_226 , & V_56 -> V_77 ) ;
F_203 ( & V_148 -> V_227 , & V_232 ) ;
F_80 ( & V_150 , V_58 ) ;
}
}
V_230:
V_148 = F_52 () ;
if ( ! V_148 )
goto error;
V_148 -> V_72 = V_72 ;
V_148 -> V_73 = V_177 -> V_73 -> V_78 ;
V_148 -> V_74 = V_177 -> V_74 ;
V_148 -> V_151 = V_177 ;
V_148 -> V_56 = V_56 ;
F_79 ( & V_150 , V_58 ) ;
V_147 = F_199 ( V_177 ) ;
if ( V_147 != NULL ) {
F_80 ( & V_150 , V_58 ) ;
if ( V_147 != V_56 ) {
F_146 ( V_56 ) ;
V_56 = V_147 ;
}
F_53 ( V_148 ) ;
return V_56 ;
}
F_203 ( & V_148 -> V_226 , & V_56 -> V_77 ) ;
F_203 ( & V_148 -> V_227 , & V_232 ) ;
V_177 -> V_151 . V_228 . V_49 = V_148 ;
F_80 ( & V_150 , V_58 ) ;
return V_56 ;
error:
return F_199 ( V_177 ) ;
}
static int F_204 ( struct V_55 * V_56 ,
unsigned long long V_189 ,
unsigned long long V_81 )
{
unsigned long V_233 = V_189 >> V_10 ;
unsigned long V_234 = V_81 >> V_10 ;
if ( ! F_158 ( & V_56 -> V_190 , F_10 ( V_233 ) ,
F_10 ( V_234 ) ) ) {
F_42 ( V_145 L_26 ) ;
return - V_112 ;
}
F_114 ( L_27 ,
V_189 , V_81 , V_56 -> V_175 ) ;
F_89 ( V_56 , V_233 , V_234 ) ;
return F_192 ( V_56 , V_233 , V_233 ,
V_234 - V_233 + 1 ,
V_27 | V_28 ) ;
}
static int F_205 ( struct V_176 * V_177 ,
unsigned long long V_189 ,
unsigned long long V_81 )
{
struct V_55 * V_56 ;
int V_88 ;
V_56 = F_200 ( V_177 , V_54 ) ;
if ( ! V_56 )
return - V_112 ;
if ( V_56 == V_235 && V_236 ) {
F_42 ( L_28 ,
F_202 ( V_177 ) , V_189 , V_81 ) ;
return 0 ;
}
F_42 ( V_35
L_29 ,
F_202 ( V_177 ) , V_189 , V_81 ) ;
if ( V_81 < V_189 ) {
F_206 ( 1 , L_30
L_31 ,
F_207 ( V_237 ) ,
F_207 ( V_238 ) ,
F_207 ( V_239 ) ) ;
V_88 = - V_240 ;
goto error;
}
if ( V_81 >> F_2 ( V_56 -> V_1 ) ) {
F_206 ( 1 , L_32
L_31 ,
F_2 ( V_56 -> V_1 ) ,
F_207 ( V_237 ) ,
F_207 ( V_238 ) ,
F_207 ( V_239 ) ) ;
V_88 = - V_240 ;
goto error;
}
V_88 = F_204 ( V_56 , V_189 , V_81 ) ;
if ( V_88 )
goto error;
V_88 = F_176 ( V_56 , V_177 , V_196 ) ;
if ( V_88 )
goto error;
return 0 ;
error:
F_146 ( V_56 ) ;
return V_88 ;
}
static inline int F_208 ( struct V_241 * V_242 ,
struct V_176 * V_177 )
{
if ( V_177 -> V_151 . V_228 . V_49 == V_243 )
return 0 ;
return F_205 ( V_177 , V_242 -> V_244 ,
V_242 -> V_245 ) ;
}
static inline void F_209 ( void )
{
struct V_176 * V_177 ;
int V_88 ;
V_177 = F_210 ( V_246 << 8 , NULL ) ;
if ( ! V_177 )
return;
F_42 ( V_35 L_33 ) ;
V_88 = F_205 ( V_177 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_88 )
F_42 ( V_145 L_34
L_35 ) ;
}
static inline void F_209 ( void )
{
return;
}
static int T_1 F_211 ( int V_247 )
{
struct V_68 * V_69 ;
struct V_48 * V_49 ;
int V_99 , V_88 = 0 ;
V_235 = F_151 () ;
if ( ! V_235 )
return - V_197 ;
F_114 ( L_36 , V_235 -> V_175 ) ;
F_70 (iommu, drhd) {
V_88 = F_152 ( V_235 , V_49 ) ;
if ( V_88 ) {
F_146 ( V_235 ) ;
return - V_197 ;
}
}
if ( F_212 ( V_235 , V_54 ) ) {
F_146 ( V_235 ) ;
return - V_197 ;
}
V_235 -> V_58 = V_60 ;
if ( V_247 )
return 0 ;
F_213 (nid) {
unsigned long V_104 , V_248 ;
int V_64 ;
F_214 (i, nid, &start_pfn, &end_pfn, NULL) {
V_88 = F_204 ( V_235 ,
F_215 ( V_104 ) , F_215 ( V_248 ) ) ;
if ( V_88 )
return V_88 ;
}
}
return 0 ;
}
static int F_216 ( struct V_176 * V_177 )
{
struct V_146 * V_148 ;
if ( F_217 ( ! V_249 ) )
return 0 ;
V_148 = V_177 -> V_151 . V_228 . V_49 ;
if ( V_148 && V_148 != V_243 )
return ( V_148 -> V_56 == V_235 ) ;
return 0 ;
}
static int F_218 ( struct V_55 * V_56 ,
struct V_176 * V_177 ,
int V_194 )
{
struct V_146 * V_148 ;
unsigned long V_58 ;
int V_88 ;
V_148 = F_52 () ;
if ( ! V_148 )
return - V_112 ;
V_148 -> V_72 = F_177 ( V_177 -> V_73 ) ;
V_148 -> V_73 = V_177 -> V_73 -> V_78 ;
V_148 -> V_74 = V_177 -> V_74 ;
V_148 -> V_151 = V_177 ;
V_148 -> V_56 = V_56 ;
F_79 ( & V_150 , V_58 ) ;
F_203 ( & V_148 -> V_226 , & V_56 -> V_77 ) ;
F_203 ( & V_148 -> V_227 , & V_232 ) ;
V_177 -> V_151 . V_228 . V_49 = V_148 ;
F_80 ( & V_150 , V_58 ) ;
V_88 = F_176 ( V_56 , V_177 , V_194 ) ;
if ( V_88 ) {
F_79 ( & V_150 , V_58 ) ;
F_194 ( V_148 ) ;
F_80 ( & V_150 , V_58 ) ;
F_53 ( V_148 ) ;
return V_88 ;
}
return 0 ;
}
static bool F_219 ( struct V_176 * V_151 )
{
struct V_241 * V_242 ;
int V_64 ;
F_220 (rmrr) {
for ( V_64 = 0 ; V_64 < V_242 -> V_76 ; V_64 ++ ) {
if ( V_242 -> V_77 [ V_64 ] == V_151 )
return true ;
}
}
return false ;
}
static int F_221 ( struct V_176 * V_177 , int V_250 )
{
if ( F_219 ( V_177 ) &&
( V_177 -> V_251 >> 8 ) != V_252 )
return 0 ;
if ( ( V_249 & V_253 ) && F_222 ( V_177 ) )
return 1 ;
if ( ( V_249 & V_254 ) && F_223 ( V_177 ) )
return 1 ;
if ( ! ( V_249 & V_255 ) )
return 0 ;
if ( ! F_179 ( V_177 ) ) {
if ( ! F_224 ( V_177 -> V_73 ) )
return 0 ;
if ( V_177 -> V_251 >> 8 == V_256 )
return 0 ;
} else if ( F_225 ( V_177 ) == V_257 )
return 0 ;
if ( ! V_250 ) {
V_23 V_258 = V_177 -> V_258 ;
if ( V_177 -> V_151 . V_259 &&
V_177 -> V_151 . V_259 < V_258 )
V_258 = V_177 -> V_151 . V_259 ;
return V_258 >= F_226 ( & V_177 -> V_151 ) ;
}
return 1 ;
}
static int T_1 F_227 ( int V_247 )
{
struct V_176 * V_177 = NULL ;
int V_88 ;
V_88 = F_211 ( V_247 ) ;
if ( V_88 )
return - V_197 ;
F_160 (pdev) {
if ( F_221 ( V_177 , 1 ) ) {
V_88 = F_218 ( V_235 , V_177 ,
V_247 ? V_195 :
V_196 ) ;
if ( V_88 ) {
if ( V_88 == - V_184 )
continue;
return V_88 ;
}
F_228 ( L_37 ,
V_247 ? L_38 : L_39 , F_202 ( V_177 ) ) ;
}
}
return 0 ;
}
static int T_1 F_229 ( void )
{
struct V_68 * V_69 ;
struct V_241 * V_242 ;
struct V_176 * V_177 ;
struct V_48 * V_49 ;
int V_64 , V_88 ;
F_75 (drhd) {
if ( V_62 < V_260 ) {
V_62 ++ ;
continue;
}
F_230 ( V_145 L_40 ,
V_260 ) ;
}
V_63 = F_141 ( V_62 , sizeof( struct V_48 * ) ,
V_170 ) ;
if ( ! V_63 ) {
F_42 ( V_145 L_41 ) ;
V_88 = - V_112 ;
goto error;
}
V_261 = F_231 ( V_62 *
sizeof( struct V_262 ) , V_170 ) ;
if ( ! V_261 ) {
V_88 = - V_112 ;
goto error;
}
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
V_63 [ V_49 -> V_168 ] = V_49 ;
V_88 = F_137 ( V_49 ) ;
if ( V_88 )
goto error;
V_88 = F_94 ( V_49 ) ;
if ( V_88 ) {
F_42 ( V_145 L_42 ) ;
goto error;
}
if ( ! F_232 ( V_49 -> V_66 ) )
V_236 = 0 ;
}
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
if ( V_49 -> V_149 )
continue;
F_233 ( - 1 , V_49 ) ;
F_234 ( V_49 ) ;
}
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
if ( F_235 ( V_49 ) ) {
V_49 -> V_157 . V_200 = F_103 ;
V_49 -> V_157 . V_158 = F_108 ;
F_42 ( V_35 L_43
L_44 ,
V_49 -> V_168 ,
( unsigned long long ) V_69 -> V_263 ) ;
} else {
V_49 -> V_157 . V_200 = V_264 ;
V_49 -> V_157 . V_158 = V_265 ;
F_42 ( V_35 L_45
L_44 ,
V_49 -> V_168 ,
( unsigned long long ) V_69 -> V_263 ) ;
}
}
if ( V_266 )
V_249 |= V_255 ;
#ifdef F_236
V_249 |= V_254 ;
#endif
F_237 () ;
if ( V_249 ) {
V_88 = F_227 ( V_236 ) ;
if ( V_88 ) {
F_42 ( V_225 L_46 ) ;
goto error;
}
}
F_42 ( V_35 L_47 ) ;
F_220 (rmrr) {
for ( V_64 = 0 ; V_64 < V_242 -> V_76 ; V_64 ++ ) {
V_177 = V_242 -> V_77 [ V_64 ] ;
if ( ! V_177 )
continue;
V_88 = F_208 ( V_242 , V_177 ) ;
if ( V_88 )
F_42 ( V_145
L_48 ) ;
}
}
F_209 () ;
F_75 (drhd) {
if ( V_69 -> V_75 ) {
if ( V_267 )
F_134 ( V_69 -> V_49 ) ;
continue;
}
V_49 = V_69 -> V_49 ;
F_101 ( V_49 ) ;
V_88 = F_238 ( V_49 ) ;
if ( V_88 )
goto error;
F_95 ( V_49 ) ;
V_49 -> V_157 . V_200 ( V_49 , 0 , 0 , 0 , V_131 ) ;
V_49 -> V_157 . V_158 ( V_49 , 0 , 0 , 0 , V_140 ) ;
V_88 = F_135 ( V_49 ) ;
if ( V_88 )
goto error;
F_134 ( V_49 ) ;
}
return 0 ;
error:
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
F_239 ( V_49 ) ;
}
F_150 ( V_63 ) ;
return V_88 ;
}
static struct V_46 * F_240 ( struct V_268 * V_151 ,
struct V_55 * V_56 ,
unsigned long V_269 , V_31 V_258 )
{
struct V_176 * V_177 = F_241 ( V_151 ) ;
struct V_46 * V_46 = NULL ;
V_258 = F_242 ( V_31 , F_243 ( V_56 -> V_111 ) , V_258 ) ;
if ( ! V_37 && V_258 > F_244 ( 32 ) ) {
V_46 = F_245 ( & V_56 -> V_190 , V_269 ,
F_159 ( F_244 ( 32 ) ) , 1 ) ;
if ( V_46 )
return V_46 ;
}
V_46 = F_245 ( & V_56 -> V_190 , V_269 , F_159 ( V_258 ) , 1 ) ;
if ( F_174 ( ! V_46 ) ) {
F_42 ( V_145 L_49 ,
V_269 , F_202 ( V_177 ) ) ;
return NULL ;
}
return V_46 ;
}
static struct V_55 * F_246 ( struct V_176 * V_177 )
{
struct V_55 * V_56 ;
int V_88 ;
V_56 = F_200 ( V_177 ,
V_54 ) ;
if ( ! V_56 ) {
F_42 ( V_145
L_50 , F_202 ( V_177 ) ) ;
return NULL ;
}
if ( F_174 ( ! F_180 ( V_177 ) ) ) {
V_88 = F_176 ( V_56 , V_177 ,
V_196 ) ;
if ( V_88 ) {
F_42 ( V_145
L_51 ,
F_202 ( V_177 ) ) ;
return NULL ;
}
}
return V_56 ;
}
static inline struct V_55 * F_247 ( struct V_176 * V_151 )
{
struct V_146 * V_148 ;
V_148 = V_151 -> V_151 . V_228 . V_49 ;
if ( F_217 ( V_148 ) )
return V_148 -> V_56 ;
return F_246 ( V_151 ) ;
}
static int F_248 ( struct V_176 * V_177 )
{
return V_177 -> V_151 . V_228 . V_49 == V_243 ;
}
static int F_249 ( struct V_268 * V_151 )
{
struct V_176 * V_177 ;
int V_147 ;
if ( F_174 ( V_151 -> V_73 != & V_270 ) )
return 1 ;
V_177 = F_241 ( V_151 ) ;
if ( F_248 ( V_177 ) )
return 1 ;
if ( ! V_249 )
return 0 ;
V_147 = F_216 ( V_177 ) ;
if ( V_147 ) {
if ( F_221 ( V_177 , 0 ) )
return 1 ;
else {
F_250 ( V_235 , V_177 ) ;
F_42 ( V_35 L_52 ,
F_202 ( V_177 ) ) ;
return 0 ;
}
} else {
if ( F_221 ( V_177 , 0 ) ) {
int V_88 ;
V_88 = F_218 ( V_235 , V_177 ,
V_236 ?
V_195 :
V_196 ) ;
if ( ! V_88 ) {
F_42 ( V_35 L_53 ,
F_202 ( V_177 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_222 F_251 ( struct V_268 * V_271 , T_6 V_272 ,
T_5 V_84 , int V_273 , V_23 V_258 )
{
struct V_176 * V_177 = F_241 ( V_271 ) ;
struct V_55 * V_56 ;
T_6 V_274 ;
struct V_46 * V_46 ;
int V_30 = 0 ;
int V_88 ;
struct V_48 * V_49 ;
unsigned long V_275 = V_272 >> V_9 ;
F_62 ( V_273 == V_276 ) ;
if ( F_249 ( V_271 ) )
return V_272 ;
V_56 = F_247 ( V_177 ) ;
if ( ! V_56 )
return 0 ;
V_49 = F_61 ( V_56 ) ;
V_84 = F_181 ( V_272 , V_84 ) ;
V_46 = F_240 ( V_271 , V_56 , F_10 ( V_84 ) , V_258 ) ;
if ( ! V_46 )
goto error;
if ( V_273 == V_277 || V_273 == V_278 || \
! F_252 ( V_49 -> V_52 ) )
V_30 |= V_27 ;
if ( V_273 == V_279 || V_273 == V_278 )
V_30 |= V_28 ;
V_88 = F_192 ( V_56 , F_11 ( V_46 -> V_280 ) ,
F_11 ( V_275 ) , V_84 , V_30 ) ;
if ( V_88 )
goto error;
if ( F_133 ( V_49 -> V_52 ) )
F_128 ( V_49 , V_56 -> V_175 , F_11 ( V_46 -> V_280 ) , V_84 , 1 ) ;
else
F_101 ( V_49 ) ;
V_274 = ( T_6 ) V_46 -> V_280 << V_9 ;
V_274 += V_272 & ~ V_205 ;
return V_274 ;
error:
if ( V_46 )
F_253 ( & V_56 -> V_190 , V_46 ) ;
F_42 ( V_145 L_54 ,
F_202 ( V_177 ) , V_84 , ( unsigned long long ) V_272 , V_273 ) ;
return 0 ;
}
static V_222 F_254 ( struct V_268 * V_151 , struct V_12 * V_12 ,
unsigned long V_94 , T_5 V_84 ,
enum V_281 V_273 ,
struct V_282 * V_283 )
{
return F_251 ( V_151 , F_185 ( V_12 ) + V_94 , V_84 ,
V_273 , F_241 ( V_151 ) -> V_258 ) ;
}
static void F_255 ( void )
{
int V_64 , V_284 ;
V_285 = 0 ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
struct V_48 * V_49 = V_63 [ V_64 ] ;
if ( ! V_49 )
continue;
if ( ! V_261 [ V_64 ] . V_110 )
continue;
if ( ! F_133 ( V_49 -> V_52 ) )
V_49 -> V_157 . V_158 ( V_49 , 0 , 0 , 0 ,
V_140 ) ;
for ( V_284 = 0 ; V_284 < V_261 [ V_64 ] . V_110 ; V_284 ++ ) {
unsigned long V_70 ;
struct V_46 * V_46 = V_261 [ V_64 ] . V_46 [ V_284 ] ;
struct V_55 * V_56 = V_261 [ V_64 ] . V_56 [ V_284 ] ;
if ( F_133 ( V_49 -> V_52 ) )
F_128 ( V_49 , V_56 -> V_175 ,
V_46 -> V_280 , V_46 -> V_286 - V_46 -> V_280 + 1 , 0 ) ;
else {
V_70 = F_129 ( F_11 ( V_46 -> V_286 - V_46 -> V_280 + 1 ) ) ;
F_125 ( V_261 [ V_64 ] . V_56 [ V_284 ] ,
( V_31 ) V_46 -> V_280 << V_9 , V_70 ) ;
}
F_253 ( & V_261 [ V_64 ] . V_56 [ V_284 ] -> V_190 , V_46 ) ;
}
V_261 [ V_64 ] . V_110 = 0 ;
}
V_287 = 0 ;
}
static void F_168 ( unsigned long V_288 )
{
unsigned long V_58 ;
F_79 ( & V_289 , V_58 ) ;
F_255 () ;
F_80 ( & V_289 , V_58 ) ;
}
static void F_256 ( struct V_55 * V_290 , struct V_46 * V_46 )
{
unsigned long V_58 ;
int V_110 , V_57 ;
struct V_48 * V_49 ;
F_79 ( & V_289 , V_58 ) ;
if ( V_287 == V_291 )
F_255 () ;
V_49 = F_61 ( V_290 ) ;
V_57 = V_49 -> V_168 ;
V_110 = V_261 [ V_57 ] . V_110 ;
V_261 [ V_57 ] . V_56 [ V_110 ] = V_290 ;
V_261 [ V_57 ] . V_46 [ V_110 ] = V_46 ;
V_261 [ V_57 ] . V_110 ++ ;
if ( ! V_285 ) {
F_257 ( & V_292 , V_293 + F_258 ( 10 ) ) ;
V_285 = 1 ;
}
V_287 ++ ;
F_80 ( & V_289 , V_58 ) ;
}
static void F_259 ( struct V_268 * V_151 , V_222 V_294 ,
T_5 V_84 , enum V_281 V_273 ,
struct V_282 * V_283 )
{
struct V_176 * V_177 = F_241 ( V_151 ) ;
struct V_55 * V_56 ;
unsigned long V_104 , V_105 ;
struct V_46 * V_46 ;
struct V_48 * V_49 ;
if ( F_249 ( V_151 ) )
return;
V_56 = F_199 ( V_177 ) ;
F_62 ( ! V_56 ) ;
V_49 = F_61 ( V_56 ) ;
V_46 = F_260 ( & V_56 -> V_190 , F_159 ( V_294 ) ) ;
if ( F_261 ( ! V_46 , L_55 ,
( unsigned long long ) V_294 ) )
return;
V_104 = F_11 ( V_46 -> V_280 ) ;
V_105 = F_11 ( V_46 -> V_286 + 1 ) - 1 ;
F_114 ( L_56 ,
F_202 ( V_177 ) , V_104 , V_105 ) ;
F_89 ( V_56 , V_104 , V_105 ) ;
F_92 ( V_56 , V_104 , V_105 ) ;
if ( V_38 ) {
F_128 ( V_49 , V_56 -> V_175 , V_104 ,
V_105 - V_104 + 1 , 0 ) ;
F_253 ( & V_56 -> V_190 , V_46 ) ;
} else {
F_256 ( V_56 , V_46 ) ;
}
}
static void * F_262 ( struct V_268 * V_271 , T_5 V_84 ,
V_222 * V_295 , T_7 V_58 ,
struct V_282 * V_283 )
{
void * V_41 ;
int V_107 ;
V_84 = F_182 ( V_84 ) ;
V_107 = F_263 ( V_84 ) ;
if ( ! F_249 ( V_271 ) )
V_58 &= ~ ( V_296 | V_297 ) ;
else if ( V_271 -> V_259 < F_226 ( V_271 ) ) {
if ( V_271 -> V_259 < F_244 ( 32 ) )
V_58 |= V_296 ;
else
V_58 |= V_297 ;
}
V_41 = ( void * ) F_264 ( V_58 , V_107 ) ;
if ( ! V_41 )
return NULL ;
memset ( V_41 , 0 , V_84 ) ;
* V_295 = F_251 ( V_271 , F_265 ( V_41 ) , V_84 ,
V_278 ,
V_271 -> V_259 ) ;
if ( * V_295 )
return V_41 ;
F_266 ( ( unsigned long ) V_41 , V_107 ) ;
return NULL ;
}
static void F_267 ( struct V_268 * V_271 , T_5 V_84 , void * V_41 ,
V_222 V_295 , struct V_282 * V_283 )
{
int V_107 ;
V_84 = F_182 ( V_84 ) ;
V_107 = F_263 ( V_84 ) ;
F_259 ( V_271 , V_295 , V_84 , V_278 , NULL ) ;
F_266 ( ( unsigned long ) V_41 , V_107 ) ;
}
static void F_268 ( struct V_268 * V_271 , struct V_212 * V_298 ,
int V_299 , enum V_281 V_273 ,
struct V_282 * V_283 )
{
struct V_176 * V_177 = F_241 ( V_271 ) ;
struct V_55 * V_56 ;
unsigned long V_104 , V_105 ;
struct V_46 * V_46 ;
struct V_48 * V_49 ;
if ( F_249 ( V_271 ) )
return;
V_56 = F_199 ( V_177 ) ;
F_62 ( ! V_56 ) ;
V_49 = F_61 ( V_56 ) ;
V_46 = F_260 ( & V_56 -> V_190 , F_159 ( V_298 [ 0 ] . V_221 ) ) ;
if ( F_261 ( ! V_46 , L_57 ,
( unsigned long long ) V_298 [ 0 ] . V_221 ) )
return;
V_104 = F_11 ( V_46 -> V_280 ) ;
V_105 = F_11 ( V_46 -> V_286 + 1 ) - 1 ;
F_89 ( V_56 , V_104 , V_105 ) ;
F_92 ( V_56 , V_104 , V_105 ) ;
if ( V_38 ) {
F_128 ( V_49 , V_56 -> V_175 , V_104 ,
V_105 - V_104 + 1 , 0 ) ;
F_253 ( & V_56 -> V_190 , V_46 ) ;
} else {
F_256 ( V_56 , V_46 ) ;
}
}
static int F_269 ( struct V_268 * V_300 ,
struct V_212 * V_298 , int V_299 , int V_273 )
{
int V_64 ;
struct V_212 * V_213 ;
F_270 (sglist, sg, nelems, i) {
F_62 ( ! F_186 ( V_213 ) ) ;
V_213 -> V_221 = F_185 ( F_186 ( V_213 ) ) + V_213 -> V_94 ;
V_213 -> V_223 = V_213 -> V_220 ;
}
return V_299 ;
}
static int F_271 ( struct V_268 * V_271 , struct V_212 * V_298 , int V_299 ,
enum V_281 V_273 , struct V_282 * V_283 )
{
int V_64 ;
struct V_176 * V_177 = F_241 ( V_271 ) ;
struct V_55 * V_56 ;
T_5 V_84 = 0 ;
int V_30 = 0 ;
struct V_46 * V_46 = NULL ;
int V_88 ;
struct V_212 * V_213 ;
unsigned long V_301 ;
struct V_48 * V_49 ;
F_62 ( V_273 == V_276 ) ;
if ( F_249 ( V_271 ) )
return F_269 ( V_271 , V_298 , V_299 , V_273 ) ;
V_56 = F_247 ( V_177 ) ;
if ( ! V_56 )
return 0 ;
V_49 = F_61 ( V_56 ) ;
F_270 (sglist, sg, nelems, i)
V_84 += F_181 ( V_213 -> V_94 , V_213 -> V_220 ) ;
V_46 = F_240 ( V_271 , V_56 , F_10 ( V_84 ) ,
V_177 -> V_258 ) ;
if ( ! V_46 ) {
V_298 -> V_223 = 0 ;
return 0 ;
}
if ( V_273 == V_277 || V_273 == V_278 || \
! F_252 ( V_49 -> V_52 ) )
V_30 |= V_27 ;
if ( V_273 == V_279 || V_273 == V_278 )
V_30 |= V_28 ;
V_301 = F_11 ( V_46 -> V_280 ) ;
V_88 = F_191 ( V_56 , V_301 , V_298 , V_84 , V_30 ) ;
if ( F_174 ( V_88 ) ) {
F_89 ( V_56 , V_301 ,
V_301 + V_84 - 1 ) ;
F_92 ( V_56 , V_301 ,
V_301 + V_84 - 1 ) ;
F_253 ( & V_56 -> V_190 , V_46 ) ;
return 0 ;
}
if ( F_133 ( V_49 -> V_52 ) )
F_128 ( V_49 , V_56 -> V_175 , V_301 , V_84 , 1 ) ;
else
F_101 ( V_49 ) ;
return V_299 ;
}
static int F_272 ( struct V_268 * V_151 , V_222 V_302 )
{
return ! V_302 ;
}
static inline int F_273 ( void )
{
int V_88 = 0 ;
V_44 = F_274 ( L_58 ,
sizeof( struct V_55 ) ,
0 ,
V_303 ,
NULL ) ;
if ( ! V_44 ) {
F_42 ( V_145 L_59 ) ;
V_88 = - V_112 ;
}
return V_88 ;
}
static inline int F_275 ( void )
{
int V_88 = 0 ;
V_45 = F_274 ( L_60 ,
sizeof( struct V_146 ) ,
0 ,
V_303 ,
NULL ) ;
if ( ! V_45 ) {
F_42 ( V_145 L_61 ) ;
V_88 = - V_112 ;
}
return V_88 ;
}
static inline int F_276 ( void )
{
int V_88 = 0 ;
V_47 = F_274 ( L_62 ,
sizeof( struct V_46 ) ,
0 ,
V_303 ,
NULL ) ;
if ( ! V_47 ) {
F_42 ( V_145 L_63 ) ;
V_88 = - V_112 ;
}
return V_88 ;
}
static int T_1 F_277 ( void )
{
int V_88 ;
V_88 = F_276 () ;
if ( V_88 )
return V_88 ;
V_88 = F_273 () ;
if ( V_88 )
goto V_304;
V_88 = F_275 () ;
if ( ! V_88 )
return V_88 ;
F_278 ( V_44 ) ;
V_304:
F_278 ( V_47 ) ;
return - V_112 ;
}
static void T_1 F_279 ( void )
{
F_278 ( V_45 ) ;
F_278 ( V_44 ) ;
F_278 ( V_47 ) ;
}
static void F_280 ( struct V_176 * V_177 )
{
struct V_68 * V_69 ;
T_3 V_305 ;
int V_306 ;
V_306 = F_281 ( V_177 -> V_73 , F_282 ( 0 , 0 ) , 0xb0 , & V_305 ) ;
if ( V_306 ) {
F_283 ( & V_177 -> V_151 , L_64 ) ;
return;
}
V_305 &= 0xffff0000 ;
V_69 = F_201 ( V_177 ) ;
if ( F_284 ( ! V_69 || V_69 -> V_263 - V_305 != 0xa000 ,
V_307 ,
L_65 ) )
V_177 -> V_151 . V_228 . V_49 = V_243 ;
}
static void T_1 F_285 ( void )
{
struct V_68 * V_69 ;
F_75 (drhd) {
if ( ! V_69 -> V_82 ) {
int V_64 ;
for ( V_64 = 0 ; V_64 < V_69 -> V_76 ; V_64 ++ )
if ( V_69 -> V_77 [ V_64 ] != NULL )
break;
if ( V_64 == V_69 -> V_76 )
V_69 -> V_75 = 1 ;
}
}
F_75 (drhd) {
int V_64 ;
if ( V_69 -> V_75 || V_69 -> V_82 )
continue;
for ( V_64 = 0 ; V_64 < V_69 -> V_76 ; V_64 ++ )
if ( V_69 -> V_77 [ V_64 ] &&
! F_223 ( V_69 -> V_77 [ V_64 ] ) )
break;
if ( V_64 < V_69 -> V_76 )
continue;
if ( V_36 ) {
V_308 = 1 ;
} else {
V_69 -> V_75 = 1 ;
for ( V_64 = 0 ; V_64 < V_69 -> V_76 ; V_64 ++ ) {
if ( ! V_69 -> V_77 [ V_64 ] )
continue;
V_69 -> V_77 [ V_64 ] -> V_151 . V_228 . V_49 = V_243 ;
}
}
}
}
static int F_286 ( void )
{
struct V_68 * V_69 ;
struct V_48 * V_49 = NULL ;
F_70 (iommu, drhd)
if ( V_49 -> V_149 )
F_287 ( V_49 ) ;
F_288 (iommu, drhd) {
if ( V_69 -> V_75 ) {
if ( V_267 )
F_134 ( V_49 ) ;
continue;
}
F_101 ( V_49 ) ;
F_95 ( V_49 ) ;
V_49 -> V_157 . V_200 ( V_49 , 0 , 0 , 0 ,
V_131 ) ;
V_49 -> V_157 . V_158 ( V_49 , 0 , 0 , 0 ,
V_140 ) ;
if ( F_135 ( V_49 ) )
return 1 ;
F_134 ( V_49 ) ;
}
return 0 ;
}
static void F_289 ( void )
{
struct V_68 * V_69 ;
struct V_48 * V_49 ;
F_70 (iommu, drhd) {
V_49 -> V_157 . V_200 ( V_49 , 0 , 0 , 0 ,
V_131 ) ;
V_49 -> V_157 . V_158 ( V_49 , 0 , 0 , 0 ,
V_140 ) ;
}
}
static int F_290 ( void )
{
struct V_68 * V_69 ;
struct V_48 * V_49 = NULL ;
unsigned long V_115 ;
F_70 (iommu, drhd) {
V_49 -> V_309 = F_231 ( sizeof( T_3 ) * V_310 ,
V_42 ) ;
if ( ! V_49 -> V_309 )
goto V_311;
}
F_289 () ;
F_70 (iommu, drhd) {
F_136 ( V_49 ) ;
F_96 ( & V_49 -> V_116 , V_115 ) ;
V_49 -> V_309 [ V_312 ] =
V_123 ( V_49 -> V_117 + V_313 ) ;
V_49 -> V_309 [ V_314 ] =
V_123 ( V_49 -> V_117 + V_315 ) ;
V_49 -> V_309 [ V_316 ] =
V_123 ( V_49 -> V_117 + V_317 ) ;
V_49 -> V_309 [ V_318 ] =
V_123 ( V_49 -> V_117 + V_319 ) ;
F_100 ( & V_49 -> V_116 , V_115 ) ;
}
return 0 ;
V_311:
F_70 (iommu, drhd)
F_150 ( V_49 -> V_309 ) ;
return - V_112 ;
}
static void F_291 ( void )
{
struct V_68 * V_69 ;
struct V_48 * V_49 = NULL ;
unsigned long V_115 ;
if ( F_286 () ) {
if ( V_267 )
F_292 ( L_66 ) ;
else
F_206 ( 1 , L_67 ) ;
return;
}
F_70 (iommu, drhd) {
F_96 ( & V_49 -> V_116 , V_115 ) ;
F_98 ( V_49 -> V_309 [ V_312 ] ,
V_49 -> V_117 + V_313 ) ;
F_98 ( V_49 -> V_309 [ V_314 ] ,
V_49 -> V_117 + V_315 ) ;
F_98 ( V_49 -> V_309 [ V_316 ] ,
V_49 -> V_117 + V_317 ) ;
F_98 ( V_49 -> V_309 [ V_318 ] ,
V_49 -> V_117 + V_319 ) ;
F_100 ( & V_49 -> V_116 , V_115 ) ;
}
F_70 (iommu, drhd)
F_150 ( V_49 -> V_309 ) ;
}
static void T_1 F_293 ( void )
{
F_294 ( & V_320 ) ;
}
static inline void F_293 ( void ) {}
static void T_1 F_295 ( struct V_241 * V_242 )
{
F_203 ( & V_242 -> V_321 , & V_322 ) ;
}
int T_1 F_296 ( struct V_323 * V_324 )
{
struct V_325 * V_242 ;
struct V_241 * V_326 ;
V_326 = F_231 ( sizeof( * V_326 ) , V_170 ) ;
if ( ! V_326 )
return - V_112 ;
V_326 -> V_327 = V_324 ;
V_242 = (struct V_325 * ) V_324 ;
V_326 -> V_244 = V_242 -> V_244 ;
V_326 -> V_245 = V_242 -> V_245 ;
F_295 ( V_326 ) ;
return 0 ;
}
static int T_1
F_297 ( struct V_241 * V_326 )
{
struct V_325 * V_242 ;
int V_88 ;
V_242 = (struct V_325 * ) V_326 -> V_327 ;
V_88 = F_298 ( ( void * ) ( V_242 + 1 ) ,
( ( void * ) V_242 ) + V_242 -> V_324 . V_220 ,
& V_326 -> V_76 , & V_326 -> V_77 , V_242 -> V_72 ) ;
if ( V_88 || ( V_326 -> V_76 == 0 ) ) {
F_196 ( & V_326 -> V_321 ) ;
F_150 ( V_326 ) ;
}
return V_88 ;
}
int T_1 F_299 ( struct V_323 * V_327 )
{
struct V_328 * V_329 ;
struct V_330 * V_331 ;
V_329 = F_300 ( V_327 , struct V_328 , V_324 ) ;
V_331 = F_231 ( sizeof( * V_331 ) , V_170 ) ;
if ( ! V_331 )
return - V_112 ;
V_331 -> V_327 = V_327 ;
V_331 -> V_82 = V_329 -> V_58 & 0x1 ;
F_203 ( & V_331 -> V_321 , & V_332 ) ;
return 0 ;
}
static int T_1 F_301 ( struct V_330 * V_331 )
{
int V_306 ;
struct V_328 * V_329 ;
if ( V_331 -> V_82 )
return 0 ;
V_329 = F_300 ( V_331 -> V_327 , struct V_328 , V_324 ) ;
V_306 = F_298 ( ( void * ) ( V_329 + 1 ) ,
( void * ) V_329 + V_329 -> V_324 . V_220 ,
& V_331 -> V_76 , & V_331 -> V_77 ,
V_329 -> V_72 ) ;
if ( V_306 || ! V_331 -> V_76 ) {
F_196 ( & V_331 -> V_321 ) ;
F_150 ( V_331 ) ;
}
return V_306 ;
}
int F_119 ( struct V_176 * V_151 )
{
int V_64 ;
struct V_333 * V_73 ;
struct V_328 * V_329 ;
struct V_330 * V_331 ;
V_151 = F_302 ( V_151 ) ;
F_117 (atsru, &dmar_atsr_units, list) {
V_329 = F_300 ( V_331 -> V_327 , struct V_328 , V_324 ) ;
if ( V_329 -> V_72 == F_177 ( V_151 -> V_73 ) )
goto V_147;
}
return 0 ;
V_147:
for ( V_73 = V_151 -> V_73 ; V_73 ; V_73 = V_73 -> V_93 ) {
struct V_176 * V_334 = V_73 -> V_203 ;
if ( ! V_334 || ! F_179 ( V_334 ) ||
F_225 ( V_334 ) == V_257 )
return 0 ;
if ( F_225 ( V_334 ) == V_335 ) {
for ( V_64 = 0 ; V_64 < V_331 -> V_76 ; V_64 ++ )
if ( V_331 -> V_77 [ V_64 ] == V_334 )
return 1 ;
break;
}
}
if ( V_331 -> V_82 )
return 1 ;
return 0 ;
}
int T_1 F_303 ( void )
{
struct V_241 * V_242 , * V_336 ;
struct V_330 * V_329 , * V_337 ;
int V_88 = 0 ;
F_304 (rmrr, rmrr_n, &dmar_rmrr_units, list) {
V_88 = F_297 ( V_242 ) ;
if ( V_88 )
return V_88 ;
}
F_304 (atsr, atsr_n, &dmar_atsr_units, list) {
V_88 = F_301 ( V_329 ) ;
if ( V_88 )
return V_88 ;
}
return V_88 ;
}
static int F_305 ( struct V_338 * V_339 ,
unsigned long V_340 , void * V_288 )
{
struct V_268 * V_151 = V_288 ;
struct V_176 * V_177 = F_241 ( V_151 ) ;
struct V_55 * V_56 ;
if ( F_249 ( V_151 ) )
return 0 ;
V_56 = F_199 ( V_177 ) ;
if ( ! V_56 )
return 0 ;
if ( V_340 == V_341 && ! V_266 ) {
F_250 ( V_56 , V_177 ) ;
if ( ! ( V_56 -> V_58 & V_59 ) &&
! ( V_56 -> V_58 & V_60 ) &&
F_197 ( & V_56 -> V_77 ) )
F_146 ( V_56 ) ;
}
return 0 ;
}
int T_1 F_306 ( void )
{
int V_88 = 0 ;
struct V_68 * V_69 ;
V_267 = F_307 () ;
if ( F_308 () ) {
if ( V_267 )
F_292 ( L_68 ) ;
return - V_184 ;
}
F_75 (drhd) {
struct V_48 * V_49 ;
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
if ( V_49 -> V_119 & V_164 )
F_136 ( V_49 ) ;
}
if ( F_309 () < 0 ) {
if ( V_267 )
F_292 ( L_69 ) ;
return - V_184 ;
}
if ( V_342 || V_34 )
return - V_184 ;
if ( F_277 () ) {
if ( V_267 )
F_292 ( L_70 ) ;
return - V_184 ;
}
if ( F_197 ( & V_322 ) )
F_42 ( V_35 L_71 ) ;
if ( F_197 ( & V_332 ) )
F_42 ( V_35 L_72 ) ;
if ( F_155 () ) {
if ( V_267 )
F_292 ( L_73 ) ;
return - V_184 ;
}
F_285 () ;
V_88 = F_229 () ;
if ( V_88 ) {
if ( V_267 )
F_292 ( L_74 ) ;
F_42 ( V_145 L_75 ) ;
F_170 ( & V_178 ) ;
F_279 () ;
return V_88 ;
}
F_42 ( V_35
L_76 ) ;
F_310 ( & V_292 ) ;
#ifdef F_311
V_343 = 0 ;
#endif
V_344 = & V_345 ;
F_293 () ;
F_312 ( & V_270 , & V_346 ) ;
F_313 ( & V_270 , & V_347 ) ;
V_348 = 1 ;
return 0 ;
}
static void F_314 ( struct V_48 * V_49 ,
struct V_176 * V_177 )
{
struct V_176 * V_202 , * V_93 ;
if ( ! V_49 || ! V_177 )
return;
V_202 = F_178 ( V_177 ) ;
if ( V_202 ) {
V_93 = V_177 -> V_73 -> V_203 ;
while ( V_93 != V_202 ) {
F_193 ( V_49 , V_93 -> V_73 -> V_78 ,
V_93 -> V_74 ) ;
V_93 = V_93 -> V_73 -> V_203 ;
}
if ( F_179 ( V_202 ) )
F_193 ( V_49 ,
V_202 -> V_79 -> V_78 , 0 ) ;
else
F_193 ( V_49 , V_202 -> V_73 -> V_78 ,
V_202 -> V_74 ) ;
}
}
static void F_250 ( struct V_55 * V_56 ,
struct V_176 * V_177 )
{
struct V_146 * V_148 ;
struct V_48 * V_49 ;
unsigned long V_58 ;
int V_147 = 0 ;
struct V_349 * V_350 , * V_202 ;
V_49 = F_74 ( F_177 ( V_177 -> V_73 ) , V_177 -> V_73 -> V_78 ,
V_177 -> V_74 ) ;
if ( ! V_49 )
return;
F_79 ( & V_150 , V_58 ) ;
F_315 (entry, tmp, &domain->devices) {
V_148 = F_198 ( V_350 , struct V_146 , V_226 ) ;
if ( V_148 -> V_72 == F_177 ( V_177 -> V_73 ) &&
V_148 -> V_73 == V_177 -> V_73 -> V_78 &&
V_148 -> V_74 == V_177 -> V_74 ) {
F_194 ( V_148 ) ;
F_80 ( & V_150 , V_58 ) ;
F_122 ( V_148 ) ;
F_193 ( V_49 , V_148 -> V_73 , V_148 -> V_74 ) ;
F_314 ( V_49 , V_177 ) ;
F_53 ( V_148 ) ;
F_79 ( & V_150 , V_58 ) ;
if ( V_147 )
break;
else
continue;
}
if ( V_49 == F_74 ( V_148 -> V_72 , V_148 -> V_73 ,
V_148 -> V_74 ) )
V_147 = 1 ;
}
F_80 ( & V_150 , V_58 ) ;
if ( V_147 == 0 ) {
unsigned long V_351 ;
F_79 ( & V_56 -> V_171 , V_351 ) ;
F_144 ( V_49 -> V_168 , V_56 -> V_61 ) ;
V_56 -> V_172 -- ;
F_73 ( V_56 ) ;
F_80 ( & V_56 -> V_171 , V_351 ) ;
if ( ! ( V_56 -> V_58 & V_59 ) &&
! ( V_56 -> V_58 & V_60 ) ) {
F_79 ( & V_49 -> V_86 , V_351 ) ;
F_144 ( V_56 -> V_175 , V_49 -> V_169 ) ;
V_49 -> V_159 [ V_56 -> V_175 ] = NULL ;
F_80 ( & V_49 -> V_86 , V_351 ) ;
}
}
}
static void F_316 ( struct V_55 * V_56 )
{
struct V_146 * V_148 ;
struct V_48 * V_49 ;
unsigned long V_352 , V_353 ;
F_79 ( & V_150 , V_352 ) ;
while ( ! F_197 ( & V_56 -> V_77 ) ) {
V_148 = F_198 ( V_56 -> V_77 . V_110 ,
struct V_146 , V_226 ) ;
F_194 ( V_148 ) ;
F_80 ( & V_150 , V_352 ) ;
F_122 ( V_148 ) ;
V_49 = F_74 ( V_148 -> V_72 , V_148 -> V_73 , V_148 -> V_74 ) ;
F_193 ( V_49 , V_148 -> V_73 , V_148 -> V_74 ) ;
F_314 ( V_49 , V_148 -> V_151 ) ;
F_79 ( & V_56 -> V_171 , V_353 ) ;
if ( F_317 ( V_49 -> V_168 ,
V_56 -> V_61 ) ) {
V_56 -> V_172 -- ;
F_73 ( V_56 ) ;
}
F_80 ( & V_56 -> V_171 , V_353 ) ;
F_53 ( V_148 ) ;
F_79 ( & V_150 , V_352 ) ;
}
F_80 ( & V_150 , V_352 ) ;
}
static struct V_55 * F_318 ( void )
{
struct V_55 * V_56 ;
V_56 = F_48 () ;
if ( ! V_56 )
return NULL ;
V_56 -> V_175 = V_354 ++ ;
V_56 -> V_99 = - 1 ;
memset ( V_56 -> V_61 , 0 , sizeof( V_56 -> V_61 ) ) ;
V_56 -> V_58 = V_59 ;
return V_56 ;
}
static int F_212 ( struct V_55 * V_56 , int V_191 )
{
int V_192 ;
F_156 ( & V_56 -> V_190 , V_179 ) ;
F_140 ( & V_56 -> V_171 ) ;
F_161 ( V_56 ) ;
V_56 -> V_111 = V_191 ;
V_192 = F_163 ( V_191 ) ;
V_56 -> V_1 = F_3 ( V_192 ) ;
F_167 ( & V_56 -> V_77 ) ;
V_56 -> V_172 = 0 ;
V_56 -> V_65 = 0 ;
V_56 -> V_67 = 0 ;
V_56 -> V_71 = 0 ;
V_56 -> V_355 = 0 ;
V_56 -> V_99 = - 1 ;
V_56 -> V_95 = (struct V_25 * ) F_43 ( V_56 -> V_99 ) ;
if ( ! V_56 -> V_95 )
return - V_112 ;
F_76 ( V_56 , V_56 -> V_95 , V_193 ) ;
return 0 ;
}
static void F_319 ( struct V_55 * V_56 )
{
unsigned long V_58 ;
struct V_68 * V_69 ;
struct V_48 * V_49 ;
unsigned long V_64 ;
unsigned long V_166 ;
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
V_166 = F_138 ( V_49 -> V_52 ) ;
F_65 (i, iommu->domain_ids, ndomains) {
if ( V_49 -> V_159 [ V_64 ] == V_56 ) {
F_79 ( & V_49 -> V_86 , V_58 ) ;
F_144 ( V_64 , V_49 -> V_169 ) ;
V_49 -> V_159 [ V_64 ] = NULL ;
F_80 ( & V_49 -> V_86 , V_58 ) ;
break;
}
}
}
}
static void F_145 ( struct V_55 * V_56 )
{
if ( ! V_56 )
return;
F_316 ( V_56 ) ;
F_170 ( & V_56 -> V_190 ) ;
F_89 ( V_56 , 0 , F_93 ( V_56 -> V_111 ) ) ;
F_92 ( V_56 , 0 , F_93 ( V_56 -> V_111 ) ) ;
F_319 ( V_56 ) ;
F_50 ( V_56 ) ;
}
static int F_320 ( struct V_356 * V_56 )
{
struct V_55 * V_55 ;
V_55 = F_318 () ;
if ( ! V_55 ) {
F_42 ( V_145
L_77 ) ;
return - V_112 ;
}
if ( F_212 ( V_55 , V_54 ) ) {
F_42 ( V_145
L_78 ) ;
F_145 ( V_55 ) ;
return - V_112 ;
}
F_73 ( V_55 ) ;
V_56 -> V_357 = V_55 ;
V_56 -> V_358 . V_359 = 0 ;
V_56 -> V_358 . V_360 = F_321 ( V_55 -> V_111 ) ;
V_56 -> V_358 . V_361 = true ;
return 0 ;
}
static void F_322 ( struct V_356 * V_56 )
{
struct V_55 * V_55 = V_56 -> V_357 ;
V_56 -> V_357 = NULL ;
F_145 ( V_55 ) ;
}
static int F_323 ( struct V_356 * V_56 ,
struct V_268 * V_151 )
{
struct V_55 * V_55 = V_56 -> V_357 ;
struct V_176 * V_177 = F_241 ( V_151 ) ;
struct V_48 * V_49 ;
int V_92 ;
if ( F_174 ( F_180 ( V_177 ) ) ) {
struct V_55 * V_362 ;
V_362 = F_199 ( V_177 ) ;
if ( V_362 ) {
if ( V_55 -> V_58 & V_59 ||
V_55 -> V_58 & V_60 )
F_250 ( V_362 , V_177 ) ;
else
F_169 ( V_362 ) ;
}
}
V_49 = F_74 ( F_177 ( V_177 -> V_73 ) , V_177 -> V_73 -> V_78 ,
V_177 -> V_74 ) ;
if ( ! V_49 )
return - V_184 ;
V_92 = F_2 ( V_49 -> V_1 ) ;
if ( V_92 > F_165 ( V_49 -> V_52 ) )
V_92 = F_165 ( V_49 -> V_52 ) ;
if ( V_55 -> V_355 > ( 1LL << V_92 ) ) {
F_42 ( V_145 L_79
L_80 ,
V_363 , V_92 , V_55 -> V_355 ) ;
return - V_197 ;
}
V_55 -> V_111 = V_92 ;
while ( V_49 -> V_1 < V_55 -> V_1 ) {
struct V_25 * V_26 ;
V_26 = V_55 -> V_95 ;
if ( F_38 ( V_26 ) ) {
V_55 -> V_95 = (struct V_25 * )
F_20 ( F_34 ( V_26 ) ) ;
F_46 ( V_26 ) ;
}
V_55 -> V_1 -- ;
}
return F_218 ( V_55 , V_177 , V_196 ) ;
}
static void F_324 ( struct V_356 * V_56 ,
struct V_268 * V_151 )
{
struct V_55 * V_55 = V_56 -> V_357 ;
struct V_176 * V_177 = F_241 ( V_151 ) ;
F_250 ( V_55 , V_177 ) ;
}
static int F_325 ( struct V_356 * V_56 ,
unsigned long V_46 , T_6 V_364 ,
T_5 V_84 , int V_365 )
{
struct V_55 * V_55 = V_56 -> V_357 ;
V_23 V_355 ;
int V_30 = 0 ;
int V_88 ;
if ( V_365 & V_366 )
V_30 |= V_27 ;
if ( V_365 & V_367 )
V_30 |= V_28 ;
if ( ( V_365 & V_368 ) && V_55 -> V_67 )
V_30 |= V_29 ;
V_355 = V_46 + V_84 ;
if ( V_55 -> V_355 < V_355 ) {
V_23 V_81 ;
V_81 = F_321 ( V_55 -> V_111 ) + 1 ;
if ( V_81 < V_355 ) {
F_42 ( V_145 L_79
L_80 ,
V_363 , V_55 -> V_111 , V_355 ) ;
return - V_197 ;
}
V_55 -> V_355 = V_355 ;
}
V_84 = F_181 ( V_364 , V_84 ) ;
V_88 = F_192 ( V_55 , V_46 >> V_10 ,
V_364 >> V_10 , V_84 , V_30 ) ;
return V_88 ;
}
static T_5 F_326 ( struct V_356 * V_56 ,
unsigned long V_46 , T_5 V_84 )
{
struct V_55 * V_55 = V_56 -> V_357 ;
int V_107 ;
V_107 = F_89 ( V_55 , V_46 >> V_10 ,
( V_46 + V_84 - 1 ) >> V_10 ) ;
if ( V_55 -> V_355 == V_46 + V_84 )
V_55 -> V_355 = V_46 ;
return V_193 << V_107 ;
}
static T_6 F_327 ( struct V_356 * V_56 ,
V_222 V_46 )
{
struct V_55 * V_55 = V_56 -> V_357 ;
struct V_25 * V_26 ;
V_23 V_369 = 0 ;
V_26 = F_86 ( V_55 , V_46 >> V_10 , 0 ) ;
if ( V_26 )
V_369 = F_34 ( V_26 ) ;
return V_369 ;
}
static int F_328 ( struct V_356 * V_56 ,
unsigned long V_52 )
{
struct V_55 * V_55 = V_56 -> V_357 ;
if ( V_52 == V_370 )
return V_55 -> V_67 ;
if ( V_52 == V_371 )
return V_372 ;
return 0 ;
}
static int F_329 ( struct V_268 * V_151 )
{
struct V_176 * V_177 = F_241 ( V_151 ) ;
struct V_176 * V_334 , * V_373 = NULL ;
struct V_374 * V_375 ;
int V_88 ;
if ( ! F_74 ( F_177 ( V_177 -> V_73 ) ,
V_177 -> V_73 -> V_78 , V_177 -> V_74 ) )
return - V_184 ;
V_334 = F_178 ( V_177 ) ;
if ( V_334 ) {
if ( F_179 ( V_334 ) )
V_373 = F_330 (
F_177 ( V_177 -> V_73 ) ,
V_334 -> V_79 -> V_78 , 0 ) ;
if ( ! V_373 )
V_373 = F_331 ( V_334 ) ;
} else
V_373 = F_331 ( V_177 ) ;
F_332 ( & V_373 , F_333 ( V_373 ) ) ;
if ( V_373 -> V_376 &&
! F_334 ( V_373 , V_377 ) ) {
T_2 V_64 , V_378 = F_172 ( V_373 -> V_74 ) ;
for ( V_64 = 0 ; V_64 < 8 ; V_64 ++ ) {
struct V_176 * V_202 ;
V_202 = F_335 ( V_373 -> V_73 , F_282 ( V_378 , V_64 ) ) ;
if ( ! V_202 )
continue;
if ( ! F_334 ( V_202 , V_377 ) ) {
F_332 ( & V_373 , V_202 ) ;
break;
}
F_336 ( V_202 ) ;
}
}
while ( ! F_224 ( V_373 -> V_73 ) ) {
struct V_333 * V_73 = V_373 -> V_73 ;
while ( ! V_73 -> V_203 ) {
if ( ! F_224 ( V_73 ) )
V_73 = V_73 -> V_93 ;
else
goto V_379;
}
if ( F_337 ( V_73 -> V_203 , NULL , V_377 ) )
break;
F_332 ( & V_373 , F_331 ( V_73 -> V_203 ) ) ;
}
V_379:
V_375 = F_338 ( & V_373 -> V_151 ) ;
F_336 ( V_373 ) ;
if ( ! V_375 ) {
V_375 = F_339 () ;
if ( F_340 ( V_375 ) )
return F_341 ( V_375 ) ;
}
V_88 = F_342 ( V_375 , V_151 ) ;
F_343 ( V_375 ) ;
return V_88 ;
}
static void F_344 ( struct V_268 * V_151 )
{
F_345 ( V_151 ) ;
}
static void F_346 ( struct V_176 * V_151 )
{
F_42 ( V_35 L_81 ) ;
V_36 = 0 ;
}
static void F_347 ( struct V_176 * V_151 )
{
F_42 ( V_35 L_82 ) ;
V_125 = 1 ;
}
static void F_348 ( struct V_176 * V_151 )
{
unsigned short V_380 ;
if ( F_349 ( V_151 , V_381 , & V_380 ) )
return;
if ( ! ( V_380 & V_382 ) ) {
F_42 ( V_35 L_83 ) ;
V_36 = 0 ;
} else if ( V_36 ) {
F_42 ( V_35 L_84 ) ;
V_38 = 1 ;
}
}
static void T_1 F_237 ( void )
{
struct V_176 * V_177 ;
T_8 V_383 ;
V_177 = F_350 ( V_384 , 0x3a3e , NULL ) ;
if ( ! V_177 )
return;
F_336 ( V_177 ) ;
V_177 = F_350 ( V_384 , 0x342e , NULL ) ;
if ( ! V_177 )
return;
if ( F_351 ( V_177 , 0x188 , & V_383 ) ) {
F_336 ( V_177 ) ;
return;
}
F_336 ( V_177 ) ;
if ( V_383 & 1 )
return;
V_383 &= 0x1c ;
if ( V_383 == 0x10 )
return;
if ( ! V_383 ) {
F_206 ( 1 , L_85
L_31 ,
F_207 ( V_237 ) ,
F_207 ( V_238 ) ,
F_207 ( V_239 ) ) ;
V_249 |= V_253 ;
return;
}
F_42 ( V_385 L_86 ,
V_383 ) ;
}
