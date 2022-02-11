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
static void F_90 ( struct V_55 * V_56 ,
unsigned long V_104 ,
unsigned long V_105 )
{
int V_92 = F_2 ( V_56 -> V_1 ) - V_10 ;
struct V_25 * V_106 , * V_26 ;
int V_102 = F_1 ( V_56 -> V_1 ) ;
int V_4 ;
unsigned long V_108 ;
int V_101 = 2 ;
F_62 ( V_92 < V_96 && V_104 > > V_92 ) ;
F_62 ( V_92 < V_96 && V_105 > > V_92 ) ;
F_62 ( V_104 > V_105 ) ;
V_4 = 2 ;
while ( V_4 <= V_102 ) {
V_108 = F_8 ( V_104 , V_4 ) ;
if ( V_108 + F_7 ( V_4 ) - 1 > V_105 )
return;
do {
V_101 = V_4 ;
V_106 = V_26 = F_88 ( V_56 , V_108 , V_4 , & V_101 ) ;
if ( V_101 > V_4 )
V_4 = V_101 + 1 ;
if ( ! V_26 ) {
V_108 = F_8 ( V_108 + 1 , V_4 + 1 ) ;
continue;
}
do {
if ( F_38 ( V_26 ) ) {
F_46 ( F_20 ( F_34 ( V_26 ) ) ) ;
F_29 ( V_26 ) ;
}
V_26 ++ ;
V_108 += F_7 ( V_4 ) ;
} while ( ! F_40 ( V_26 ) &&
V_108 + F_7 ( V_4 ) - 1 <= V_105 );
F_76 ( V_56 , V_106 ,
( void * ) V_26 - ( void * ) V_106 ) ;
} while ( V_108 && V_108 + F_7 ( V_4 ) - 1 <= V_105 );
V_4 ++ ;
}
if ( V_104 == 0 && V_105 == F_91 ( V_56 -> V_109 ) ) {
F_46 ( V_56 -> V_95 ) ;
V_56 -> V_95 = NULL ;
}
}
static int F_92 ( struct V_48 * V_49 )
{
struct V_15 * V_16 ;
unsigned long V_58 ;
V_16 = (struct V_15 * ) F_43 ( V_49 -> V_40 ) ;
if ( ! V_16 )
return - V_110 ;
F_81 ( V_49 , V_16 , V_111 ) ;
F_79 ( & V_49 -> V_86 , V_58 ) ;
V_49 -> V_15 = V_16 ;
F_80 ( & V_49 -> V_86 , V_58 ) ;
return 0 ;
}
static void F_93 ( struct V_48 * V_49 )
{
void * V_83 ;
T_3 V_112 ;
unsigned long V_113 ;
V_83 = V_49 -> V_15 ;
F_94 ( & V_49 -> V_114 , V_113 ) ;
F_95 ( V_49 -> V_115 + V_116 , F_82 ( V_83 ) ) ;
F_96 ( V_49 -> V_117 | V_118 , V_49 -> V_115 + V_119 ) ;
F_97 ( V_49 , V_120 ,
V_121 , ( V_112 & V_122 ) , V_112 ) ;
F_98 ( & V_49 -> V_114 , V_113 ) ;
}
static void F_99 ( struct V_48 * V_49 )
{
T_3 V_17 ;
unsigned long V_113 ;
if ( ! V_123 && ! F_100 ( V_49 -> V_52 ) )
return;
F_94 ( & V_49 -> V_114 , V_113 ) ;
F_96 ( V_49 -> V_117 | V_124 , V_49 -> V_115 + V_119 ) ;
F_97 ( V_49 , V_120 ,
V_121 , ( ! ( V_17 & V_125 ) ) , V_17 ) ;
F_98 ( & V_49 -> V_114 , V_113 ) ;
}
static void F_101 ( struct V_48 * V_49 ,
T_4 V_126 , T_4 V_127 , T_2 V_128 ,
V_23 type )
{
V_23 V_17 = 0 ;
unsigned long V_113 ;
switch ( type ) {
case V_129 :
V_17 = V_129 ;
break;
case V_130 :
V_17 = V_130 | F_102 ( V_126 ) ;
break;
case V_131 :
V_17 = V_131 | F_102 ( V_126 )
| F_103 ( V_127 ) | F_104 ( V_128 ) ;
break;
default:
F_105 () ;
}
V_17 |= V_132 ;
F_94 ( & V_49 -> V_114 , V_113 ) ;
F_95 ( V_49 -> V_115 + V_133 , V_17 ) ;
F_97 ( V_49 , V_133 ,
V_134 , ( ! ( V_17 & V_132 ) ) , V_17 ) ;
F_98 ( & V_49 -> V_114 , V_113 ) ;
}
static void F_106 ( struct V_48 * V_49 , T_4 V_126 ,
V_23 V_83 , unsigned int V_135 , V_23 type )
{
int V_136 = F_107 ( V_49 -> V_66 ) ;
V_23 V_17 = 0 , V_137 = 0 ;
unsigned long V_113 ;
switch ( type ) {
case V_138 :
V_17 = V_138 | V_139 ;
break;
case V_140 :
V_17 = V_140 | V_139 | F_108 ( V_126 ) ;
break;
case V_141 :
V_17 = V_141 | V_139 | F_108 ( V_126 ) ;
V_137 = V_135 | V_83 ;
break;
default:
F_105 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_109 ( V_49 -> V_52 ) )
V_17 |= V_142 ;
F_94 ( & V_49 -> V_114 , V_113 ) ;
if ( V_137 )
F_95 ( V_49 -> V_115 + V_136 , V_137 ) ;
F_95 ( V_49 -> V_115 + V_136 + 8 , V_17 ) ;
F_97 ( V_49 , V_136 + 8 ,
V_134 , ( ! ( V_17 & V_139 ) ) , V_17 ) ;
F_98 ( & V_49 -> V_114 , V_113 ) ;
if ( F_110 ( V_17 ) == 0 )
F_42 ( V_143 L_14 ) ;
if ( F_110 ( V_17 ) != F_111 ( type ) )
F_112 ( L_15 ,
( unsigned long long ) F_111 ( type ) ,
( unsigned long long ) F_110 ( V_17 ) ) ;
}
static struct V_144 * F_113 (
struct V_55 * V_56 , int V_72 , T_2 V_73 , T_2 V_74 )
{
int V_145 = 0 ;
unsigned long V_58 ;
struct V_144 * V_146 ;
struct V_48 * V_49 = F_74 ( V_72 , V_73 , V_74 ) ;
if ( ! F_114 ( V_49 -> V_66 ) )
return NULL ;
if ( ! V_49 -> V_147 )
return NULL ;
F_79 ( & V_148 , V_58 ) ;
F_115 (info, &domain->devices, link)
if ( V_146 -> V_73 == V_73 && V_146 -> V_74 == V_74 ) {
V_145 = 1 ;
break;
}
F_80 ( & V_148 , V_58 ) ;
if ( ! V_145 || ! V_146 -> V_149 )
return NULL ;
if ( ! F_116 ( V_146 -> V_149 , V_150 ) )
return NULL ;
if ( ! F_117 ( V_146 -> V_149 ) )
return NULL ;
V_146 -> V_49 = V_49 ;
return V_146 ;
}
static void F_118 ( struct V_144 * V_146 )
{
if ( ! V_146 )
return;
F_119 ( V_146 -> V_149 , V_10 ) ;
}
static void F_120 ( struct V_144 * V_146 )
{
if ( ! V_146 -> V_149 || ! F_121 ( V_146 -> V_149 ) )
return;
F_122 ( V_146 -> V_149 ) ;
}
static void F_123 ( struct V_55 * V_56 ,
V_23 V_83 , unsigned V_70 )
{
T_4 V_151 , V_152 ;
unsigned long V_58 ;
struct V_144 * V_146 ;
F_79 ( & V_148 , V_58 ) ;
F_115 (info, &domain->devices, link) {
if ( ! V_146 -> V_149 || ! F_121 ( V_146 -> V_149 ) )
continue;
V_151 = V_146 -> V_73 << 8 | V_146 -> V_74 ;
V_152 = F_124 ( V_146 -> V_149 ) ;
F_125 ( V_146 -> V_49 , V_151 , V_152 , V_83 , V_70 ) ;
}
F_80 ( & V_148 , V_58 ) ;
}
static void F_126 ( struct V_48 * V_49 , T_4 V_126 ,
unsigned long V_5 , unsigned int V_153 , int V_154 )
{
unsigned int V_70 = F_127 ( F_128 ( V_153 ) ) ;
V_31 V_83 = ( V_31 ) V_5 << V_10 ;
F_62 ( V_153 == 0 ) ;
if ( ! F_129 ( V_49 -> V_52 ) || V_70 > F_130 ( V_49 -> V_52 ) )
V_49 -> V_155 . V_156 ( V_49 , V_126 , 0 , 0 ,
V_140 ) ;
else
V_49 -> V_155 . V_156 ( V_49 , V_126 , V_83 , V_70 ,
V_141 ) ;
if ( ! F_131 ( V_49 -> V_52 ) || ! V_154 )
F_123 ( V_49 -> V_157 [ V_126 ] , V_83 , V_70 ) ;
}
static void F_132 ( struct V_48 * V_49 )
{
T_3 V_158 ;
unsigned long V_58 ;
F_94 ( & V_49 -> V_114 , V_58 ) ;
V_158 = V_121 ( V_49 -> V_115 + V_159 ) ;
V_158 &= ~ V_160 ;
F_96 ( V_158 , V_49 -> V_115 + V_159 ) ;
F_97 ( V_49 , V_159 ,
V_121 , ! ( V_158 & V_161 ) , V_158 ) ;
F_98 ( & V_49 -> V_114 , V_58 ) ;
}
static int F_133 ( struct V_48 * V_49 )
{
T_3 V_112 ;
unsigned long V_58 ;
F_94 ( & V_49 -> V_114 , V_58 ) ;
V_49 -> V_117 |= V_162 ;
F_96 ( V_49 -> V_117 , V_49 -> V_115 + V_119 ) ;
F_97 ( V_49 , V_120 ,
V_121 , ( V_112 & V_163 ) , V_112 ) ;
F_98 ( & V_49 -> V_114 , V_58 ) ;
return 0 ;
}
static int F_134 ( struct V_48 * V_49 )
{
T_3 V_112 ;
unsigned long V_113 ;
F_94 ( & V_49 -> V_114 , V_113 ) ;
V_49 -> V_117 &= ~ V_162 ;
F_96 ( V_49 -> V_117 , V_49 -> V_115 + V_119 ) ;
F_97 ( V_49 , V_120 ,
V_121 , ( ! ( V_112 & V_163 ) ) , V_112 ) ;
F_98 ( & V_49 -> V_114 , V_113 ) ;
return 0 ;
}
static int F_135 ( struct V_48 * V_49 )
{
unsigned long V_164 ;
unsigned long V_165 ;
V_164 = F_136 ( V_49 -> V_52 ) ;
F_112 ( L_16 , V_49 -> V_166 ,
V_164 ) ;
V_165 = F_137 ( V_164 ) ;
F_138 ( & V_49 -> V_86 ) ;
V_49 -> V_167 = F_139 ( V_165 , sizeof( unsigned long ) , V_168 ) ;
if ( ! V_49 -> V_167 ) {
F_42 ( V_143 L_17 ) ;
return - V_110 ;
}
V_49 -> V_157 = F_139 ( V_164 , sizeof( struct V_55 * ) ,
V_168 ) ;
if ( ! V_49 -> V_157 ) {
F_42 ( V_143 L_18 ) ;
return - V_110 ;
}
if ( F_131 ( V_49 -> V_52 ) )
F_140 ( 0 , V_49 -> V_167 ) ;
return 0 ;
}
void F_141 ( struct V_48 * V_49 )
{
struct V_55 * V_56 ;
int V_64 ;
unsigned long V_58 ;
if ( ( V_49 -> V_157 ) && ( V_49 -> V_167 ) ) {
F_65 (i, iommu->domain_ids, cap_ndoms(iommu->cap)) {
V_56 = V_49 -> V_157 [ V_64 ] ;
F_142 ( V_64 , V_49 -> V_167 ) ;
F_79 ( & V_56 -> V_169 , V_58 ) ;
if ( -- V_56 -> V_170 == 0 ) {
if ( V_56 -> V_58 & V_59 )
F_143 ( V_56 ) ;
else
F_144 ( V_56 ) ;
}
F_80 ( & V_56 -> V_169 , V_58 ) ;
}
}
if ( V_49 -> V_117 & V_162 )
F_134 ( V_49 ) ;
if ( V_49 -> V_171 ) {
F_145 ( V_49 -> V_171 , NULL ) ;
F_146 ( V_49 -> V_171 , V_49 ) ;
F_147 ( V_49 -> V_171 ) ;
}
F_148 ( V_49 -> V_157 ) ;
F_148 ( V_49 -> V_167 ) ;
V_63 [ V_49 -> V_166 ] = NULL ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
if ( V_63 [ V_64 ] )
break;
}
if ( V_64 == V_62 )
F_148 ( V_63 ) ;
F_85 ( V_49 ) ;
}
static struct V_55 * F_149 ( void )
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
static int F_150 ( struct V_55 * V_56 ,
struct V_48 * V_49 )
{
int V_172 ;
unsigned long V_164 ;
unsigned long V_58 ;
V_164 = F_136 ( V_49 -> V_52 ) ;
F_79 ( & V_49 -> V_86 , V_58 ) ;
V_172 = F_151 ( V_49 -> V_167 , V_164 ) ;
if ( V_172 >= V_164 ) {
F_80 ( & V_49 -> V_86 , V_58 ) ;
F_42 ( V_143 L_19 ) ;
return - V_110 ;
}
V_56 -> V_173 = V_172 ;
F_140 ( V_172 , V_49 -> V_167 ) ;
F_140 ( V_49 -> V_166 , V_56 -> V_61 ) ;
V_49 -> V_157 [ V_172 ] = V_56 ;
F_80 ( & V_49 -> V_86 , V_58 ) ;
return 0 ;
}
static void F_152 ( struct V_55 * V_56 ,
struct V_48 * V_49 )
{
unsigned long V_58 ;
int V_172 , V_164 ;
int V_145 = 0 ;
F_79 ( & V_49 -> V_86 , V_58 ) ;
V_164 = F_136 ( V_49 -> V_52 ) ;
F_65 (num, iommu->domain_ids, ndomains) {
if ( V_49 -> V_157 [ V_172 ] == V_56 ) {
V_145 = 1 ;
break;
}
}
if ( V_145 ) {
F_142 ( V_172 , V_49 -> V_167 ) ;
F_142 ( V_49 -> V_166 , V_56 -> V_61 ) ;
V_49 -> V_157 [ V_172 ] = NULL ;
}
F_80 ( & V_49 -> V_86 , V_58 ) ;
}
static int F_153 ( void )
{
struct V_174 * V_175 = NULL ;
struct V_46 * V_46 ;
int V_64 ;
F_154 ( & V_176 , V_177 ) ;
F_155 ( & V_176 . V_178 ,
& V_179 ) ;
V_46 = F_156 ( & V_176 , F_157 ( V_180 ) ,
F_157 ( V_181 ) ) ;
if ( ! V_46 ) {
F_42 ( V_143 L_20 ) ;
return - V_182 ;
}
F_158 (pdev) {
struct V_183 * V_184 ;
for ( V_64 = 0 ; V_64 < V_185 ; V_64 ++ ) {
V_184 = & V_175 -> V_183 [ V_64 ] ;
if ( ! V_184 -> V_58 || ! ( V_184 -> V_58 & V_186 ) )
continue;
V_46 = F_156 ( & V_176 ,
F_157 ( V_184 -> V_187 ) ,
F_157 ( V_184 -> V_81 ) ) ;
if ( ! V_46 ) {
F_42 ( V_143 L_21 ) ;
return - V_182 ;
}
}
}
return 0 ;
}
static void F_159 ( struct V_55 * V_56 )
{
F_160 ( & V_176 , & V_56 -> V_188 ) ;
}
static inline int F_161 ( int V_109 )
{
int V_1 ;
int V_184 = ( V_109 - 12 ) % 9 ;
if ( V_184 == 0 )
V_1 = V_109 ;
else
V_1 = V_109 + 9 - V_184 ;
if ( V_1 > 64 )
V_1 = 64 ;
return V_1 ;
}
static int F_162 ( struct V_55 * V_56 , int V_189 )
{
struct V_48 * V_49 ;
int V_190 , V_1 ;
unsigned long V_51 ;
F_154 ( & V_56 -> V_188 , V_177 ) ;
F_138 ( & V_56 -> V_169 ) ;
F_159 ( V_56 ) ;
V_49 = F_61 ( V_56 ) ;
if ( V_189 > F_163 ( V_49 -> V_52 ) )
V_189 = F_163 ( V_49 -> V_52 ) ;
V_56 -> V_109 = V_189 ;
V_190 = F_161 ( V_189 ) ;
V_1 = F_3 ( V_190 ) ;
V_51 = F_57 ( V_49 -> V_52 ) ;
if ( ! F_58 ( V_1 , & V_51 ) ) {
F_112 ( L_22 , V_1 ) ;
V_1 = F_164 ( & V_51 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_182 ;
}
V_56 -> V_1 = V_1 ;
F_165 ( & V_56 -> V_77 ) ;
if ( F_66 ( V_49 -> V_66 ) )
V_56 -> V_65 = 1 ;
else
V_56 -> V_65 = 0 ;
if ( F_68 ( V_49 -> V_66 ) )
V_56 -> V_67 = 1 ;
else
V_56 -> V_67 = 0 ;
V_56 -> V_71 = F_72 ( F_71 ( V_49 -> V_52 ) ) ;
V_56 -> V_170 = 1 ;
V_56 -> V_99 = V_49 -> V_40 ;
V_56 -> V_95 = (struct V_25 * ) F_43 ( V_56 -> V_99 ) ;
if ( ! V_56 -> V_95 )
return - V_110 ;
F_81 ( V_49 , V_56 -> V_95 , V_191 ) ;
return 0 ;
}
static void F_144 ( struct V_55 * V_56 )
{
struct V_68 * V_69 ;
struct V_48 * V_49 ;
if ( ! V_56 )
return;
if ( ! V_38 )
F_166 ( 0 ) ;
F_167 ( V_56 ) ;
F_168 ( & V_56 -> V_188 ) ;
F_89 ( V_56 , 0 , F_91 ( V_56 -> V_109 ) ) ;
F_90 ( V_56 , 0 , F_91 ( V_56 -> V_109 ) ) ;
F_70 (iommu, drhd)
if ( F_58 ( V_49 -> V_166 , V_56 -> V_61 ) )
F_152 ( V_56 , V_49 ) ;
F_50 ( V_56 ) ;
}
static int F_169 ( struct V_55 * V_56 , int V_72 ,
T_2 V_73 , T_2 V_74 , int V_192 )
{
struct V_20 * V_21 ;
unsigned long V_58 ;
struct V_48 * V_49 ;
struct V_25 * V_95 ;
unsigned long V_172 ;
unsigned long V_164 ;
int V_173 ;
int V_1 ;
struct V_144 * V_146 = NULL ;
F_112 ( L_23 ,
V_73 , F_170 ( V_74 ) , F_171 ( V_74 ) ) ;
F_62 ( ! V_56 -> V_95 ) ;
F_62 ( V_192 != V_193 &&
V_192 != V_194 ) ;
V_49 = F_74 ( V_72 , V_73 , V_74 ) ;
if ( ! V_49 )
return - V_182 ;
V_21 = F_78 ( V_49 , V_73 , V_74 ) ;
if ( ! V_21 )
return - V_110 ;
F_79 ( & V_49 -> V_86 , V_58 ) ;
if ( F_21 ( V_21 ) ) {
F_80 ( & V_49 -> V_86 , V_58 ) ;
return 0 ;
}
V_173 = V_56 -> V_173 ;
V_95 = V_56 -> V_95 ;
if ( V_56 -> V_58 & V_59 ||
V_56 -> V_58 & V_60 ) {
int V_145 = 0 ;
V_164 = F_136 ( V_49 -> V_52 ) ;
F_65 (num, iommu->domain_ids, ndomains) {
if ( V_49 -> V_157 [ V_172 ] == V_56 ) {
V_173 = V_172 ;
V_145 = 1 ;
break;
}
}
if ( V_145 == 0 ) {
V_172 = F_151 ( V_49 -> V_167 , V_164 ) ;
if ( V_172 >= V_164 ) {
F_80 ( & V_49 -> V_86 , V_58 ) ;
F_42 ( V_143 L_19 ) ;
return - V_195 ;
}
F_140 ( V_172 , V_49 -> V_167 ) ;
V_49 -> V_157 [ V_172 ] = V_56 ;
V_173 = V_172 ;
}
if ( V_192 != V_193 ) {
for ( V_1 = V_56 -> V_1 ; V_1 != V_49 -> V_1 ; V_1 -- ) {
V_95 = F_20 ( F_34 ( V_95 ) ) ;
if ( ! F_38 ( V_95 ) ) {
F_80 ( & V_49 -> V_86 , V_58 ) ;
return - V_110 ;
}
}
}
}
F_27 ( V_21 , V_173 ) ;
if ( V_192 != V_193 ) {
V_146 = F_113 ( V_56 , V_72 , V_73 , V_74 ) ;
V_192 = V_146 ? V_196 :
V_194 ;
}
if ( F_172 ( V_192 == V_193 ) )
F_26 ( V_21 , V_49 -> V_197 ) ;
else {
F_25 ( V_21 , F_82 ( V_95 ) ) ;
F_26 ( V_21 , V_49 -> V_1 ) ;
}
F_24 ( V_21 , V_192 ) ;
F_23 ( V_21 ) ;
F_22 ( V_21 ) ;
F_76 ( V_56 , V_21 , sizeof( * V_21 ) ) ;
if ( F_131 ( V_49 -> V_52 ) ) {
V_49 -> V_155 . V_198 ( V_49 , 0 ,
( ( ( T_4 ) V_73 ) << 8 ) | V_74 ,
V_199 ,
V_131 ) ;
V_49 -> V_155 . V_156 ( V_49 , V_56 -> V_173 , 0 , 0 , V_140 ) ;
} else {
F_99 ( V_49 ) ;
}
F_118 ( V_146 ) ;
F_80 ( & V_49 -> V_86 , V_58 ) ;
F_79 ( & V_56 -> V_169 , V_58 ) ;
if ( ! F_173 ( V_49 -> V_166 , V_56 -> V_61 ) ) {
V_56 -> V_170 ++ ;
if ( V_56 -> V_170 == 1 )
V_56 -> V_99 = V_49 -> V_40 ;
F_73 ( V_56 ) ;
}
F_80 ( & V_56 -> V_169 , V_58 ) ;
return 0 ;
}
static int
F_174 ( struct V_55 * V_56 , struct V_174 * V_175 ,
int V_192 )
{
int V_88 ;
struct V_174 * V_108 , * V_93 ;
V_88 = F_169 ( V_56 , F_175 ( V_175 -> V_73 ) ,
V_175 -> V_73 -> V_78 , V_175 -> V_74 ,
V_192 ) ;
if ( V_88 )
return V_88 ;
V_108 = F_176 ( V_175 ) ;
if ( ! V_108 )
return 0 ;
V_93 = V_175 -> V_73 -> V_200 ;
while ( V_93 != V_108 ) {
V_88 = F_169 ( V_56 ,
F_175 ( V_93 -> V_73 ) ,
V_93 -> V_73 -> V_78 ,
V_93 -> V_74 , V_192 ) ;
if ( V_88 )
return V_88 ;
V_93 = V_93 -> V_73 -> V_200 ;
}
if ( F_177 ( V_108 ) )
return F_169 ( V_56 ,
F_175 ( V_108 -> V_79 ) ,
V_108 -> V_79 -> V_78 , 0 ,
V_192 ) ;
else
return F_169 ( V_56 ,
F_175 ( V_108 -> V_73 ) ,
V_108 -> V_73 -> V_78 ,
V_108 -> V_74 ,
V_192 ) ;
}
static int F_178 ( struct V_174 * V_175 )
{
int V_88 ;
struct V_174 * V_108 , * V_93 ;
struct V_48 * V_49 ;
V_49 = F_74 ( F_175 ( V_175 -> V_73 ) , V_175 -> V_73 -> V_78 ,
V_175 -> V_74 ) ;
if ( ! V_49 )
return - V_182 ;
V_88 = F_83 ( V_49 , V_175 -> V_73 -> V_78 , V_175 -> V_74 ) ;
if ( ! V_88 )
return V_88 ;
V_108 = F_176 ( V_175 ) ;
if ( ! V_108 )
return V_88 ;
V_93 = V_175 -> V_73 -> V_200 ;
while ( V_93 != V_108 ) {
V_88 = F_83 ( V_49 , V_93 -> V_73 -> V_78 ,
V_93 -> V_74 ) ;
if ( ! V_88 )
return V_88 ;
V_93 = V_93 -> V_73 -> V_200 ;
}
if ( F_177 ( V_108 ) )
return F_83 ( V_49 , V_108 -> V_79 -> V_78 ,
0 ) ;
else
return F_83 ( V_49 , V_108 -> V_73 -> V_78 ,
V_108 -> V_74 ) ;
}
static inline unsigned long F_179 ( unsigned long V_201 ,
T_5 V_84 )
{
V_201 &= ~ V_202 ;
return F_180 ( V_201 + V_84 ) >> V_10 ;
}
static inline int F_181 ( struct V_55 * V_56 ,
unsigned long V_203 ,
unsigned long V_204 ,
unsigned long V_153 )
{
int V_205 , V_4 = 1 ;
unsigned long V_206 ;
V_205 = V_56 -> V_71 ;
V_206 = V_203 | V_204 ;
while ( V_205 && ! ( V_206 & ~ V_207 ) ) {
V_153 >>= V_208 ;
if ( ! V_153 )
break;
V_206 >>= V_208 ;
V_4 ++ ;
V_205 -- ;
}
return V_4 ;
}
static int F_182 ( struct V_55 * V_56 , unsigned long V_203 ,
struct V_209 * V_210 , unsigned long V_211 ,
unsigned long V_212 , int V_30 )
{
struct V_25 * V_106 = NULL , * V_26 = NULL ;
T_6 V_213 ( V_98 ) ;
int V_92 = F_2 ( V_56 -> V_1 ) - V_10 ;
unsigned long V_214 ;
unsigned int V_215 = 0 ;
unsigned long V_216 = 0 ;
F_62 ( V_92 < V_96 && ( V_203 + V_212 - 1 ) > > V_92 ) ;
if ( ( V_30 & ( V_27 | V_28 ) ) == 0 )
return - V_33 ;
V_30 &= V_27 | V_28 | V_29 ;
if ( V_210 )
V_214 = 0 ;
else {
V_214 = V_212 + 1 ;
V_98 = ( ( T_6 ) V_211 << V_10 ) | V_30 ;
}
while ( V_212 > 0 ) {
V_31 V_108 ;
if ( ! V_214 ) {
V_214 = F_179 ( V_210 -> V_94 , V_210 -> V_217 ) ;
V_210 -> V_218 = ( ( V_219 ) V_203 << V_10 ) + V_210 -> V_94 ;
V_210 -> V_220 = V_210 -> V_217 ;
V_98 = F_183 ( F_184 ( V_210 ) ) | V_30 ;
V_211 = V_98 >> V_10 ;
}
if ( ! V_26 ) {
V_215 = F_181 ( V_56 , V_203 , V_211 , V_214 ) ;
V_106 = V_26 = F_86 ( V_56 , V_203 , V_215 ) ;
if ( ! V_26 )
return - V_110 ;
if ( V_215 > 1 )
V_98 |= V_103 ;
else
V_98 &= ~ ( V_31 ) V_103 ;
}
V_108 = F_185 ( & V_26 -> V_17 , 0ULL , V_98 ) ;
if ( V_108 ) {
static int V_221 = 5 ;
F_42 ( V_222 L_24 ,
V_203 , V_108 , ( unsigned long long ) V_98 ) ;
if ( V_221 ) {
V_221 -- ;
F_186 ( NULL ) ;
}
F_187 ( 1 ) ;
}
V_216 = F_9 ( V_215 ) ;
F_62 ( V_212 < V_216 ) ;
F_62 ( V_214 < V_216 ) ;
V_212 -= V_216 ;
V_203 += V_216 ;
V_211 += V_216 ;
V_98 += V_216 * V_100 ;
V_214 -= V_216 ;
V_26 ++ ;
if ( ! V_212 || F_40 ( V_26 ) ||
( V_215 > 1 && V_214 < V_216 ) ) {
F_76 ( V_56 , V_106 ,
( void * ) V_26 - ( void * ) V_106 ) ;
V_26 = NULL ;
}
if ( ! V_214 && V_212 )
V_210 = F_188 ( V_210 ) ;
}
return 0 ;
}
static inline int F_189 ( struct V_55 * V_56 , unsigned long V_203 ,
struct V_209 * V_210 , unsigned long V_212 ,
int V_30 )
{
return F_182 ( V_56 , V_203 , V_210 , 0 , V_212 , V_30 ) ;
}
static inline int F_190 ( struct V_55 * V_56 , unsigned long V_203 ,
unsigned long V_211 , unsigned long V_212 ,
int V_30 )
{
return F_182 ( V_56 , V_203 , NULL , V_211 , V_212 , V_30 ) ;
}
static void F_191 ( struct V_48 * V_49 , T_2 V_73 , T_2 V_74 )
{
if ( ! V_49 )
return;
F_84 ( V_49 , V_73 , V_74 ) ;
V_49 -> V_155 . V_198 ( V_49 , 0 , 0 , 0 ,
V_129 ) ;
V_49 -> V_155 . V_156 ( V_49 , 0 , 0 , 0 , V_138 ) ;
}
static inline void F_192 ( struct V_144 * V_146 )
{
F_193 ( & V_148 ) ;
F_194 ( & V_146 -> V_223 ) ;
F_194 ( & V_146 -> V_224 ) ;
if ( V_146 -> V_149 )
V_146 -> V_149 -> V_149 . V_225 . V_49 = NULL ;
}
static void F_167 ( struct V_55 * V_56 )
{
struct V_144 * V_146 ;
unsigned long V_58 ;
struct V_48 * V_49 ;
F_79 ( & V_148 , V_58 ) ;
while ( ! F_195 ( & V_56 -> V_77 ) ) {
V_146 = F_196 ( V_56 -> V_77 . V_226 ,
struct V_144 , V_223 ) ;
F_192 ( V_146 ) ;
F_80 ( & V_148 , V_58 ) ;
F_120 ( V_146 ) ;
V_49 = F_74 ( V_146 -> V_72 , V_146 -> V_73 , V_146 -> V_74 ) ;
F_191 ( V_49 , V_146 -> V_73 , V_146 -> V_74 ) ;
F_53 ( V_146 ) ;
F_79 ( & V_148 , V_58 ) ;
}
F_80 ( & V_148 , V_58 ) ;
}
static struct V_55 *
F_197 ( struct V_174 * V_175 )
{
struct V_144 * V_146 ;
V_146 = V_175 -> V_149 . V_225 . V_49 ;
if ( V_146 )
return V_146 -> V_56 ;
return NULL ;
}
static struct V_55 * F_198 ( struct V_174 * V_175 , int V_109 )
{
struct V_55 * V_56 , * V_145 = NULL ;
struct V_48 * V_49 ;
struct V_68 * V_69 ;
struct V_144 * V_146 , * V_108 ;
struct V_174 * V_227 ;
unsigned long V_58 ;
int V_73 = 0 , V_74 = 0 ;
int V_72 ;
int V_88 ;
V_56 = F_197 ( V_175 ) ;
if ( V_56 )
return V_56 ;
V_72 = F_175 ( V_175 -> V_73 ) ;
V_227 = F_176 ( V_175 ) ;
if ( V_227 ) {
if ( F_177 ( V_227 ) ) {
V_73 = V_227 -> V_79 -> V_78 ;
V_74 = 0 ;
} else {
V_73 = V_227 -> V_73 -> V_78 ;
V_74 = V_227 -> V_74 ;
}
F_79 ( & V_148 , V_58 ) ;
F_115 (info, &device_domain_list, global) {
if ( V_146 -> V_72 == V_72 &&
V_146 -> V_73 == V_73 && V_146 -> V_74 == V_74 ) {
V_145 = V_146 -> V_56 ;
break;
}
}
F_80 ( & V_148 , V_58 ) ;
if ( V_145 ) {
V_56 = V_145 ;
goto V_228;
}
}
V_56 = F_149 () ;
if ( ! V_56 )
goto error;
V_69 = F_199 ( V_175 ) ;
if ( ! V_69 ) {
F_42 ( V_143 L_25 ,
F_200 ( V_175 ) ) ;
F_50 ( V_56 ) ;
return NULL ;
}
V_49 = V_69 -> V_49 ;
V_88 = F_150 ( V_56 , V_49 ) ;
if ( V_88 ) {
F_50 ( V_56 ) ;
goto error;
}
if ( F_162 ( V_56 , V_109 ) ) {
F_144 ( V_56 ) ;
goto error;
}
if ( V_227 ) {
V_146 = F_52 () ;
if ( ! V_146 ) {
F_144 ( V_56 ) ;
goto error;
}
V_146 -> V_72 = V_72 ;
V_146 -> V_73 = V_73 ;
V_146 -> V_74 = V_74 ;
V_146 -> V_149 = NULL ;
V_146 -> V_56 = V_56 ;
V_56 -> V_58 |= V_229 ;
V_145 = NULL ;
F_79 ( & V_148 , V_58 ) ;
F_115 (tmp, &device_domain_list, global) {
if ( V_108 -> V_72 == V_72 &&
V_108 -> V_73 == V_73 && V_108 -> V_74 == V_74 ) {
V_145 = V_108 -> V_56 ;
break;
}
}
if ( V_145 ) {
F_80 ( & V_148 , V_58 ) ;
F_53 ( V_146 ) ;
F_144 ( V_56 ) ;
V_56 = V_145 ;
} else {
F_201 ( & V_146 -> V_223 , & V_56 -> V_77 ) ;
F_201 ( & V_146 -> V_224 , & V_230 ) ;
F_80 ( & V_148 , V_58 ) ;
}
}
V_228:
V_146 = F_52 () ;
if ( ! V_146 )
goto error;
V_146 -> V_72 = V_72 ;
V_146 -> V_73 = V_175 -> V_73 -> V_78 ;
V_146 -> V_74 = V_175 -> V_74 ;
V_146 -> V_149 = V_175 ;
V_146 -> V_56 = V_56 ;
F_79 ( & V_148 , V_58 ) ;
V_145 = F_197 ( V_175 ) ;
if ( V_145 != NULL ) {
F_80 ( & V_148 , V_58 ) ;
if ( V_145 != V_56 ) {
F_144 ( V_56 ) ;
V_56 = V_145 ;
}
F_53 ( V_146 ) ;
return V_56 ;
}
F_201 ( & V_146 -> V_223 , & V_56 -> V_77 ) ;
F_201 ( & V_146 -> V_224 , & V_230 ) ;
V_175 -> V_149 . V_225 . V_49 = V_146 ;
F_80 ( & V_148 , V_58 ) ;
return V_56 ;
error:
return F_197 ( V_175 ) ;
}
static int F_202 ( struct V_55 * V_56 ,
unsigned long long V_187 ,
unsigned long long V_81 )
{
unsigned long V_231 = V_187 >> V_10 ;
unsigned long V_232 = V_81 >> V_10 ;
if ( ! F_156 ( & V_56 -> V_188 , F_10 ( V_231 ) ,
F_10 ( V_232 ) ) ) {
F_42 ( V_143 L_26 ) ;
return - V_110 ;
}
F_112 ( L_27 ,
V_187 , V_81 , V_56 -> V_173 ) ;
F_89 ( V_56 , V_231 , V_232 ) ;
return F_190 ( V_56 , V_231 , V_231 ,
V_232 - V_231 + 1 ,
V_27 | V_28 ) ;
}
static int F_203 ( struct V_174 * V_175 ,
unsigned long long V_187 ,
unsigned long long V_81 )
{
struct V_55 * V_56 ;
int V_88 ;
V_56 = F_198 ( V_175 , V_54 ) ;
if ( ! V_56 )
return - V_110 ;
if ( V_56 == V_233 && V_234 ) {
F_42 ( L_28 ,
F_200 ( V_175 ) , V_187 , V_81 ) ;
return 0 ;
}
F_42 ( V_35
L_29 ,
F_200 ( V_175 ) , V_187 , V_81 ) ;
if ( V_81 < V_187 ) {
F_204 ( 1 , L_30
L_31 ,
F_205 ( V_235 ) ,
F_205 ( V_236 ) ,
F_205 ( V_237 ) ) ;
V_88 = - V_238 ;
goto error;
}
if ( V_81 >> F_2 ( V_56 -> V_1 ) ) {
F_204 ( 1 , L_32
L_31 ,
F_2 ( V_56 -> V_1 ) ,
F_205 ( V_235 ) ,
F_205 ( V_236 ) ,
F_205 ( V_237 ) ) ;
V_88 = - V_238 ;
goto error;
}
V_88 = F_202 ( V_56 , V_187 , V_81 ) ;
if ( V_88 )
goto error;
V_88 = F_174 ( V_56 , V_175 , V_194 ) ;
if ( V_88 )
goto error;
return 0 ;
error:
F_144 ( V_56 ) ;
return V_88 ;
}
static inline int F_206 ( struct V_239 * V_240 ,
struct V_174 * V_175 )
{
if ( V_175 -> V_149 . V_225 . V_49 == V_241 )
return 0 ;
return F_203 ( V_175 , V_240 -> V_242 ,
V_240 -> V_243 ) ;
}
static inline void F_207 ( void )
{
struct V_174 * V_175 ;
int V_88 ;
V_175 = F_208 ( V_244 << 8 , NULL ) ;
if ( ! V_175 )
return;
F_42 ( V_35 L_33 ) ;
V_88 = F_203 ( V_175 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_88 )
F_42 ( V_143 L_34
L_35 ) ;
}
static inline void F_207 ( void )
{
return;
}
static int T_1 F_209 ( int V_245 )
{
struct V_68 * V_69 ;
struct V_48 * V_49 ;
int V_99 , V_88 = 0 ;
V_233 = F_149 () ;
if ( ! V_233 )
return - V_195 ;
F_112 ( L_36 , V_233 -> V_173 ) ;
F_70 (iommu, drhd) {
V_88 = F_150 ( V_233 , V_49 ) ;
if ( V_88 ) {
F_144 ( V_233 ) ;
return - V_195 ;
}
}
if ( F_210 ( V_233 , V_54 ) ) {
F_144 ( V_233 ) ;
return - V_195 ;
}
V_233 -> V_58 = V_60 ;
if ( V_245 )
return 0 ;
F_211 (nid) {
unsigned long V_104 , V_246 ;
int V_64 ;
F_212 (i, nid, &start_pfn, &end_pfn, NULL) {
V_88 = F_202 ( V_233 ,
F_213 ( V_104 ) , F_213 ( V_246 ) ) ;
if ( V_88 )
return V_88 ;
}
}
return 0 ;
}
static int F_214 ( struct V_174 * V_175 )
{
struct V_144 * V_146 ;
if ( F_215 ( ! V_247 ) )
return 0 ;
V_146 = V_175 -> V_149 . V_225 . V_49 ;
if ( V_146 && V_146 != V_241 )
return ( V_146 -> V_56 == V_233 ) ;
return 0 ;
}
static int F_216 ( struct V_55 * V_56 ,
struct V_174 * V_175 ,
int V_192 )
{
struct V_144 * V_146 ;
unsigned long V_58 ;
int V_88 ;
V_146 = F_52 () ;
if ( ! V_146 )
return - V_110 ;
V_146 -> V_72 = F_175 ( V_175 -> V_73 ) ;
V_146 -> V_73 = V_175 -> V_73 -> V_78 ;
V_146 -> V_74 = V_175 -> V_74 ;
V_146 -> V_149 = V_175 ;
V_146 -> V_56 = V_56 ;
F_79 ( & V_148 , V_58 ) ;
F_201 ( & V_146 -> V_223 , & V_56 -> V_77 ) ;
F_201 ( & V_146 -> V_224 , & V_230 ) ;
V_175 -> V_149 . V_225 . V_49 = V_146 ;
F_80 ( & V_148 , V_58 ) ;
V_88 = F_174 ( V_56 , V_175 , V_192 ) ;
if ( V_88 ) {
F_79 ( & V_148 , V_58 ) ;
F_192 ( V_146 ) ;
F_80 ( & V_148 , V_58 ) ;
F_53 ( V_146 ) ;
return V_88 ;
}
return 0 ;
}
static int F_217 ( struct V_174 * V_175 , int V_248 )
{
if ( ( V_247 & V_249 ) && F_218 ( V_175 ) )
return 1 ;
if ( ( V_247 & V_250 ) && F_219 ( V_175 ) )
return 1 ;
if ( ! ( V_247 & V_251 ) )
return 0 ;
if ( ! F_177 ( V_175 ) ) {
if ( ! F_220 ( V_175 -> V_73 ) )
return 0 ;
if ( V_175 -> V_252 >> 8 == V_253 )
return 0 ;
} else if ( F_221 ( V_175 ) == V_254 )
return 0 ;
if ( ! V_248 ) {
V_23 V_255 = V_175 -> V_255 ;
if ( V_175 -> V_149 . V_256 &&
V_175 -> V_149 . V_256 < V_255 )
V_255 = V_175 -> V_149 . V_256 ;
return V_255 >= F_222 ( & V_175 -> V_149 ) ;
}
return 1 ;
}
static int T_1 F_223 ( int V_245 )
{
struct V_174 * V_175 = NULL ;
int V_88 ;
V_88 = F_209 ( V_245 ) ;
if ( V_88 )
return - V_195 ;
F_158 (pdev) {
if ( F_217 ( V_175 , 1 ) ) {
V_88 = F_216 ( V_233 , V_175 ,
V_245 ? V_193 :
V_194 ) ;
if ( V_88 ) {
if ( V_88 == - V_182 )
continue;
return V_88 ;
}
F_224 ( L_37 ,
V_245 ? L_38 : L_39 , F_200 ( V_175 ) ) ;
}
}
return 0 ;
}
static int T_1 F_225 ( void )
{
struct V_68 * V_69 ;
struct V_239 * V_240 ;
struct V_174 * V_175 ;
struct V_48 * V_49 ;
int V_64 , V_88 ;
F_75 (drhd) {
if ( V_62 < V_257 ) {
V_62 ++ ;
continue;
}
F_226 ( V_143 L_40 ,
V_257 ) ;
}
V_63 = F_139 ( V_62 , sizeof( struct V_48 * ) ,
V_168 ) ;
if ( ! V_63 ) {
F_42 ( V_143 L_41 ) ;
V_88 = - V_110 ;
goto error;
}
V_258 = F_227 ( V_62 *
sizeof( struct V_259 ) , V_168 ) ;
if ( ! V_258 ) {
V_88 = - V_110 ;
goto error;
}
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
V_63 [ V_49 -> V_166 ] = V_49 ;
V_88 = F_135 ( V_49 ) ;
if ( V_88 )
goto error;
V_88 = F_92 ( V_49 ) ;
if ( V_88 ) {
F_42 ( V_143 L_42 ) ;
goto error;
}
if ( ! F_228 ( V_49 -> V_66 ) )
V_234 = 0 ;
}
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
if ( V_49 -> V_147 )
continue;
F_229 ( - 1 , V_49 ) ;
F_230 ( V_49 ) ;
}
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
if ( F_231 ( V_49 ) ) {
V_49 -> V_155 . V_198 = F_101 ;
V_49 -> V_155 . V_156 = F_106 ;
F_42 ( V_35 L_43
L_44 ,
V_49 -> V_166 ,
( unsigned long long ) V_69 -> V_260 ) ;
} else {
V_49 -> V_155 . V_198 = V_261 ;
V_49 -> V_155 . V_156 = V_262 ;
F_42 ( V_35 L_45
L_44 ,
V_49 -> V_166 ,
( unsigned long long ) V_69 -> V_260 ) ;
}
}
if ( V_263 )
V_247 |= V_251 ;
#ifdef F_232
V_247 |= V_250 ;
#endif
F_233 () ;
if ( V_247 ) {
V_88 = F_223 ( V_234 ) ;
if ( V_88 ) {
F_42 ( V_222 L_46 ) ;
goto error;
}
}
F_42 ( V_35 L_47 ) ;
F_234 (rmrr) {
for ( V_64 = 0 ; V_64 < V_240 -> V_76 ; V_64 ++ ) {
V_175 = V_240 -> V_77 [ V_64 ] ;
if ( ! V_175 )
continue;
V_88 = F_206 ( V_240 , V_175 ) ;
if ( V_88 )
F_42 ( V_143
L_48 ) ;
}
}
F_207 () ;
F_75 (drhd) {
if ( V_69 -> V_75 ) {
if ( V_264 )
F_132 ( V_69 -> V_49 ) ;
continue;
}
V_49 = V_69 -> V_49 ;
F_99 ( V_49 ) ;
V_88 = F_235 ( V_49 ) ;
if ( V_88 )
goto error;
F_93 ( V_49 ) ;
V_49 -> V_155 . V_198 ( V_49 , 0 , 0 , 0 , V_129 ) ;
V_49 -> V_155 . V_156 ( V_49 , 0 , 0 , 0 , V_138 ) ;
V_88 = F_133 ( V_49 ) ;
if ( V_88 )
goto error;
F_132 ( V_49 ) ;
}
return 0 ;
error:
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
F_236 ( V_49 ) ;
}
F_148 ( V_63 ) ;
return V_88 ;
}
static struct V_46 * F_237 ( struct V_265 * V_149 ,
struct V_55 * V_56 ,
unsigned long V_266 , V_31 V_255 )
{
struct V_174 * V_175 = F_238 ( V_149 ) ;
struct V_46 * V_46 = NULL ;
V_255 = F_239 ( V_31 , F_240 ( V_56 -> V_109 ) , V_255 ) ;
if ( ! V_37 && V_255 > F_241 ( 32 ) ) {
V_46 = F_242 ( & V_56 -> V_188 , V_266 ,
F_157 ( F_241 ( 32 ) ) , 1 ) ;
if ( V_46 )
return V_46 ;
}
V_46 = F_242 ( & V_56 -> V_188 , V_266 , F_157 ( V_255 ) , 1 ) ;
if ( F_172 ( ! V_46 ) ) {
F_42 ( V_143 L_49 ,
V_266 , F_200 ( V_175 ) ) ;
return NULL ;
}
return V_46 ;
}
static struct V_55 * F_243 ( struct V_174 * V_175 )
{
struct V_55 * V_56 ;
int V_88 ;
V_56 = F_198 ( V_175 ,
V_54 ) ;
if ( ! V_56 ) {
F_42 ( V_143
L_50 , F_200 ( V_175 ) ) ;
return NULL ;
}
if ( F_172 ( ! F_178 ( V_175 ) ) ) {
V_88 = F_174 ( V_56 , V_175 ,
V_194 ) ;
if ( V_88 ) {
F_42 ( V_143
L_51 ,
F_200 ( V_175 ) ) ;
return NULL ;
}
}
return V_56 ;
}
static inline struct V_55 * F_244 ( struct V_174 * V_149 )
{
struct V_144 * V_146 ;
V_146 = V_149 -> V_149 . V_225 . V_49 ;
if ( F_215 ( V_146 ) )
return V_146 -> V_56 ;
return F_243 ( V_149 ) ;
}
static int F_245 ( struct V_174 * V_175 )
{
return V_175 -> V_149 . V_225 . V_49 == V_241 ;
}
static int F_246 ( struct V_265 * V_149 )
{
struct V_174 * V_175 ;
int V_145 ;
if ( F_172 ( V_149 -> V_73 != & V_267 ) )
return 1 ;
V_175 = F_238 ( V_149 ) ;
if ( F_245 ( V_175 ) )
return 1 ;
if ( ! V_247 )
return 0 ;
V_145 = F_214 ( V_175 ) ;
if ( V_145 ) {
if ( F_217 ( V_175 , 0 ) )
return 1 ;
else {
F_247 ( V_233 , V_175 ) ;
F_42 ( V_35 L_52 ,
F_200 ( V_175 ) ) ;
return 0 ;
}
} else {
if ( F_217 ( V_175 , 0 ) ) {
int V_88 ;
V_88 = F_216 ( V_233 , V_175 ,
V_234 ?
V_193 :
V_194 ) ;
if ( ! V_88 ) {
F_42 ( V_35 L_53 ,
F_200 ( V_175 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_219 F_248 ( struct V_265 * V_268 , T_6 V_269 ,
T_5 V_84 , int V_270 , V_23 V_255 )
{
struct V_174 * V_175 = F_238 ( V_268 ) ;
struct V_55 * V_56 ;
T_6 V_271 ;
struct V_46 * V_46 ;
int V_30 = 0 ;
int V_88 ;
struct V_48 * V_49 ;
unsigned long V_272 = V_269 >> V_9 ;
F_62 ( V_270 == V_273 ) ;
if ( F_246 ( V_268 ) )
return V_269 ;
V_56 = F_244 ( V_175 ) ;
if ( ! V_56 )
return 0 ;
V_49 = F_61 ( V_56 ) ;
V_84 = F_179 ( V_269 , V_84 ) ;
V_46 = F_237 ( V_268 , V_56 , F_10 ( V_84 ) , V_255 ) ;
if ( ! V_46 )
goto error;
if ( V_270 == V_274 || V_270 == V_275 || \
! F_249 ( V_49 -> V_52 ) )
V_30 |= V_27 ;
if ( V_270 == V_276 || V_270 == V_275 )
V_30 |= V_28 ;
V_88 = F_190 ( V_56 , F_11 ( V_46 -> V_277 ) ,
F_11 ( V_272 ) , V_84 , V_30 ) ;
if ( V_88 )
goto error;
if ( F_131 ( V_49 -> V_52 ) )
F_126 ( V_49 , V_56 -> V_173 , F_11 ( V_46 -> V_277 ) , V_84 , 1 ) ;
else
F_99 ( V_49 ) ;
V_271 = ( T_6 ) V_46 -> V_277 << V_9 ;
V_271 += V_269 & ~ V_202 ;
return V_271 ;
error:
if ( V_46 )
F_250 ( & V_56 -> V_188 , V_46 ) ;
F_42 ( V_143 L_54 ,
F_200 ( V_175 ) , V_84 , ( unsigned long long ) V_269 , V_270 ) ;
return 0 ;
}
static V_219 F_251 ( struct V_265 * V_149 , struct V_12 * V_12 ,
unsigned long V_94 , T_5 V_84 ,
enum V_278 V_270 ,
struct V_279 * V_280 )
{
return F_248 ( V_149 , F_183 ( V_12 ) + V_94 , V_84 ,
V_270 , F_238 ( V_149 ) -> V_255 ) ;
}
static void F_252 ( void )
{
int V_64 , V_281 ;
V_282 = 0 ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
struct V_48 * V_49 = V_63 [ V_64 ] ;
if ( ! V_49 )
continue;
if ( ! V_258 [ V_64 ] . V_226 )
continue;
if ( ! F_131 ( V_49 -> V_52 ) )
V_49 -> V_155 . V_156 ( V_49 , 0 , 0 , 0 ,
V_138 ) ;
for ( V_281 = 0 ; V_281 < V_258 [ V_64 ] . V_226 ; V_281 ++ ) {
unsigned long V_70 ;
struct V_46 * V_46 = V_258 [ V_64 ] . V_46 [ V_281 ] ;
struct V_55 * V_56 = V_258 [ V_64 ] . V_56 [ V_281 ] ;
if ( F_131 ( V_49 -> V_52 ) )
F_126 ( V_49 , V_56 -> V_173 ,
V_46 -> V_277 , V_46 -> V_283 - V_46 -> V_277 + 1 , 0 ) ;
else {
V_70 = F_127 ( F_11 ( V_46 -> V_283 - V_46 -> V_277 + 1 ) ) ;
F_123 ( V_258 [ V_64 ] . V_56 [ V_281 ] ,
( V_31 ) V_46 -> V_277 << V_9 , V_70 ) ;
}
F_250 ( & V_258 [ V_64 ] . V_56 [ V_281 ] -> V_188 , V_46 ) ;
}
V_258 [ V_64 ] . V_226 = 0 ;
}
V_284 = 0 ;
}
static void F_166 ( unsigned long V_285 )
{
unsigned long V_58 ;
F_79 ( & V_286 , V_58 ) ;
F_252 () ;
F_80 ( & V_286 , V_58 ) ;
}
static void F_253 ( struct V_55 * V_287 , struct V_46 * V_46 )
{
unsigned long V_58 ;
int V_226 , V_57 ;
struct V_48 * V_49 ;
F_79 ( & V_286 , V_58 ) ;
if ( V_284 == V_288 )
F_252 () ;
V_49 = F_61 ( V_287 ) ;
V_57 = V_49 -> V_166 ;
V_226 = V_258 [ V_57 ] . V_226 ;
V_258 [ V_57 ] . V_56 [ V_226 ] = V_287 ;
V_258 [ V_57 ] . V_46 [ V_226 ] = V_46 ;
V_258 [ V_57 ] . V_226 ++ ;
if ( ! V_282 ) {
F_254 ( & V_289 , V_290 + F_255 ( 10 ) ) ;
V_282 = 1 ;
}
V_284 ++ ;
F_80 ( & V_286 , V_58 ) ;
}
static void F_256 ( struct V_265 * V_149 , V_219 V_291 ,
T_5 V_84 , enum V_278 V_270 ,
struct V_279 * V_280 )
{
struct V_174 * V_175 = F_238 ( V_149 ) ;
struct V_55 * V_56 ;
unsigned long V_104 , V_105 ;
struct V_46 * V_46 ;
struct V_48 * V_49 ;
if ( F_246 ( V_149 ) )
return;
V_56 = F_197 ( V_175 ) ;
F_62 ( ! V_56 ) ;
V_49 = F_61 ( V_56 ) ;
V_46 = F_257 ( & V_56 -> V_188 , F_157 ( V_291 ) ) ;
if ( F_258 ( ! V_46 , L_55 ,
( unsigned long long ) V_291 ) )
return;
V_104 = F_11 ( V_46 -> V_277 ) ;
V_105 = F_11 ( V_46 -> V_283 + 1 ) - 1 ;
F_112 ( L_56 ,
F_200 ( V_175 ) , V_104 , V_105 ) ;
F_89 ( V_56 , V_104 , V_105 ) ;
F_90 ( V_56 , V_104 , V_105 ) ;
if ( V_38 ) {
F_126 ( V_49 , V_56 -> V_173 , V_104 ,
V_105 - V_104 + 1 , 0 ) ;
F_250 ( & V_56 -> V_188 , V_46 ) ;
} else {
F_253 ( V_56 , V_46 ) ;
}
}
static void * F_259 ( struct V_265 * V_268 , T_5 V_84 ,
V_219 * V_292 , T_7 V_58 ,
struct V_279 * V_280 )
{
void * V_41 ;
int V_107 ;
V_84 = F_180 ( V_84 ) ;
V_107 = F_260 ( V_84 ) ;
if ( ! F_246 ( V_268 ) )
V_58 &= ~ ( V_293 | V_294 ) ;
else if ( V_268 -> V_256 < F_222 ( V_268 ) ) {
if ( V_268 -> V_256 < F_241 ( 32 ) )
V_58 |= V_293 ;
else
V_58 |= V_294 ;
}
V_41 = ( void * ) F_261 ( V_58 , V_107 ) ;
if ( ! V_41 )
return NULL ;
memset ( V_41 , 0 , V_84 ) ;
* V_292 = F_248 ( V_268 , F_262 ( V_41 ) , V_84 ,
V_275 ,
V_268 -> V_256 ) ;
if ( * V_292 )
return V_41 ;
F_263 ( ( unsigned long ) V_41 , V_107 ) ;
return NULL ;
}
static void F_264 ( struct V_265 * V_268 , T_5 V_84 , void * V_41 ,
V_219 V_292 , struct V_279 * V_280 )
{
int V_107 ;
V_84 = F_180 ( V_84 ) ;
V_107 = F_260 ( V_84 ) ;
F_256 ( V_268 , V_292 , V_84 , V_275 , NULL ) ;
F_263 ( ( unsigned long ) V_41 , V_107 ) ;
}
static void F_265 ( struct V_265 * V_268 , struct V_209 * V_295 ,
int V_296 , enum V_278 V_270 ,
struct V_279 * V_280 )
{
struct V_174 * V_175 = F_238 ( V_268 ) ;
struct V_55 * V_56 ;
unsigned long V_104 , V_105 ;
struct V_46 * V_46 ;
struct V_48 * V_49 ;
if ( F_246 ( V_268 ) )
return;
V_56 = F_197 ( V_175 ) ;
F_62 ( ! V_56 ) ;
V_49 = F_61 ( V_56 ) ;
V_46 = F_257 ( & V_56 -> V_188 , F_157 ( V_295 [ 0 ] . V_218 ) ) ;
if ( F_258 ( ! V_46 , L_57 ,
( unsigned long long ) V_295 [ 0 ] . V_218 ) )
return;
V_104 = F_11 ( V_46 -> V_277 ) ;
V_105 = F_11 ( V_46 -> V_283 + 1 ) - 1 ;
F_89 ( V_56 , V_104 , V_105 ) ;
F_90 ( V_56 , V_104 , V_105 ) ;
if ( V_38 ) {
F_126 ( V_49 , V_56 -> V_173 , V_104 ,
V_105 - V_104 + 1 , 0 ) ;
F_250 ( & V_56 -> V_188 , V_46 ) ;
} else {
F_253 ( V_56 , V_46 ) ;
}
}
static int F_266 ( struct V_265 * V_297 ,
struct V_209 * V_295 , int V_296 , int V_270 )
{
int V_64 ;
struct V_209 * V_210 ;
F_267 (sglist, sg, nelems, i) {
F_62 ( ! F_184 ( V_210 ) ) ;
V_210 -> V_218 = F_183 ( F_184 ( V_210 ) ) + V_210 -> V_94 ;
V_210 -> V_220 = V_210 -> V_217 ;
}
return V_296 ;
}
static int F_268 ( struct V_265 * V_268 , struct V_209 * V_295 , int V_296 ,
enum V_278 V_270 , struct V_279 * V_280 )
{
int V_64 ;
struct V_174 * V_175 = F_238 ( V_268 ) ;
struct V_55 * V_56 ;
T_5 V_84 = 0 ;
int V_30 = 0 ;
struct V_46 * V_46 = NULL ;
int V_88 ;
struct V_209 * V_210 ;
unsigned long V_298 ;
struct V_48 * V_49 ;
F_62 ( V_270 == V_273 ) ;
if ( F_246 ( V_268 ) )
return F_266 ( V_268 , V_295 , V_296 , V_270 ) ;
V_56 = F_244 ( V_175 ) ;
if ( ! V_56 )
return 0 ;
V_49 = F_61 ( V_56 ) ;
F_267 (sglist, sg, nelems, i)
V_84 += F_179 ( V_210 -> V_94 , V_210 -> V_217 ) ;
V_46 = F_237 ( V_268 , V_56 , F_10 ( V_84 ) ,
V_175 -> V_255 ) ;
if ( ! V_46 ) {
V_295 -> V_220 = 0 ;
return 0 ;
}
if ( V_270 == V_274 || V_270 == V_275 || \
! F_249 ( V_49 -> V_52 ) )
V_30 |= V_27 ;
if ( V_270 == V_276 || V_270 == V_275 )
V_30 |= V_28 ;
V_298 = F_11 ( V_46 -> V_277 ) ;
V_88 = F_189 ( V_56 , V_298 , V_295 , V_84 , V_30 ) ;
if ( F_172 ( V_88 ) ) {
F_89 ( V_56 , V_298 ,
V_298 + V_84 - 1 ) ;
F_90 ( V_56 , V_298 ,
V_298 + V_84 - 1 ) ;
F_250 ( & V_56 -> V_188 , V_46 ) ;
return 0 ;
}
if ( F_131 ( V_49 -> V_52 ) )
F_126 ( V_49 , V_56 -> V_173 , V_298 , V_84 , 1 ) ;
else
F_99 ( V_49 ) ;
return V_296 ;
}
static int F_269 ( struct V_265 * V_149 , V_219 V_299 )
{
return ! V_299 ;
}
static inline int F_270 ( void )
{
int V_88 = 0 ;
V_44 = F_271 ( L_58 ,
sizeof( struct V_55 ) ,
0 ,
V_300 ,
NULL ) ;
if ( ! V_44 ) {
F_42 ( V_143 L_59 ) ;
V_88 = - V_110 ;
}
return V_88 ;
}
static inline int F_272 ( void )
{
int V_88 = 0 ;
V_45 = F_271 ( L_60 ,
sizeof( struct V_144 ) ,
0 ,
V_300 ,
NULL ) ;
if ( ! V_45 ) {
F_42 ( V_143 L_61 ) ;
V_88 = - V_110 ;
}
return V_88 ;
}
static inline int F_273 ( void )
{
int V_88 = 0 ;
V_47 = F_271 ( L_62 ,
sizeof( struct V_46 ) ,
0 ,
V_300 ,
NULL ) ;
if ( ! V_47 ) {
F_42 ( V_143 L_63 ) ;
V_88 = - V_110 ;
}
return V_88 ;
}
static int T_1 F_274 ( void )
{
int V_88 ;
V_88 = F_273 () ;
if ( V_88 )
return V_88 ;
V_88 = F_270 () ;
if ( V_88 )
goto V_301;
V_88 = F_272 () ;
if ( ! V_88 )
return V_88 ;
F_275 ( V_44 ) ;
V_301:
F_275 ( V_47 ) ;
return - V_110 ;
}
static void T_1 F_276 ( void )
{
F_275 ( V_45 ) ;
F_275 ( V_44 ) ;
F_275 ( V_47 ) ;
}
static void F_277 ( struct V_174 * V_175 )
{
struct V_68 * V_69 ;
T_3 V_302 ;
int V_303 ;
V_303 = F_278 ( V_175 -> V_73 , F_279 ( 0 , 0 ) , 0xb0 , & V_302 ) ;
if ( V_303 ) {
F_280 ( & V_175 -> V_149 , L_64 ) ;
return;
}
V_302 &= 0xffff0000 ;
V_69 = F_199 ( V_175 ) ;
if ( F_281 ( ! V_69 || V_69 -> V_260 - V_302 != 0xa000 ,
V_304 ,
L_65 ) )
V_175 -> V_149 . V_225 . V_49 = V_241 ;
}
static void T_1 F_282 ( void )
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
! F_219 ( V_69 -> V_77 [ V_64 ] ) )
break;
if ( V_64 < V_69 -> V_76 )
continue;
if ( V_36 ) {
V_305 = 1 ;
} else {
V_69 -> V_75 = 1 ;
for ( V_64 = 0 ; V_64 < V_69 -> V_76 ; V_64 ++ ) {
if ( ! V_69 -> V_77 [ V_64 ] )
continue;
V_69 -> V_77 [ V_64 ] -> V_149 . V_225 . V_49 = V_241 ;
}
}
}
}
static int F_283 ( void )
{
struct V_68 * V_69 ;
struct V_48 * V_49 = NULL ;
F_70 (iommu, drhd)
if ( V_49 -> V_147 )
F_284 ( V_49 ) ;
F_285 (iommu, drhd) {
if ( V_69 -> V_75 ) {
if ( V_264 )
F_132 ( V_49 ) ;
continue;
}
F_99 ( V_49 ) ;
F_93 ( V_49 ) ;
V_49 -> V_155 . V_198 ( V_49 , 0 , 0 , 0 ,
V_129 ) ;
V_49 -> V_155 . V_156 ( V_49 , 0 , 0 , 0 ,
V_138 ) ;
if ( F_133 ( V_49 ) )
return 1 ;
F_132 ( V_49 ) ;
}
return 0 ;
}
static void F_286 ( void )
{
struct V_68 * V_69 ;
struct V_48 * V_49 ;
F_70 (iommu, drhd) {
V_49 -> V_155 . V_198 ( V_49 , 0 , 0 , 0 ,
V_129 ) ;
V_49 -> V_155 . V_156 ( V_49 , 0 , 0 , 0 ,
V_138 ) ;
}
}
static int F_287 ( void )
{
struct V_68 * V_69 ;
struct V_48 * V_49 = NULL ;
unsigned long V_113 ;
F_70 (iommu, drhd) {
V_49 -> V_306 = F_227 ( sizeof( T_3 ) * V_307 ,
V_42 ) ;
if ( ! V_49 -> V_306 )
goto V_308;
}
F_286 () ;
F_70 (iommu, drhd) {
F_134 ( V_49 ) ;
F_94 ( & V_49 -> V_114 , V_113 ) ;
V_49 -> V_306 [ V_309 ] =
V_121 ( V_49 -> V_115 + V_310 ) ;
V_49 -> V_306 [ V_311 ] =
V_121 ( V_49 -> V_115 + V_312 ) ;
V_49 -> V_306 [ V_313 ] =
V_121 ( V_49 -> V_115 + V_314 ) ;
V_49 -> V_306 [ V_315 ] =
V_121 ( V_49 -> V_115 + V_316 ) ;
F_98 ( & V_49 -> V_114 , V_113 ) ;
}
return 0 ;
V_308:
F_70 (iommu, drhd)
F_148 ( V_49 -> V_306 ) ;
return - V_110 ;
}
static void F_288 ( void )
{
struct V_68 * V_69 ;
struct V_48 * V_49 = NULL ;
unsigned long V_113 ;
if ( F_283 () ) {
if ( V_264 )
F_289 ( L_66 ) ;
else
F_204 ( 1 , L_67 ) ;
return;
}
F_70 (iommu, drhd) {
F_94 ( & V_49 -> V_114 , V_113 ) ;
F_96 ( V_49 -> V_306 [ V_309 ] ,
V_49 -> V_115 + V_310 ) ;
F_96 ( V_49 -> V_306 [ V_311 ] ,
V_49 -> V_115 + V_312 ) ;
F_96 ( V_49 -> V_306 [ V_313 ] ,
V_49 -> V_115 + V_314 ) ;
F_96 ( V_49 -> V_306 [ V_315 ] ,
V_49 -> V_115 + V_316 ) ;
F_98 ( & V_49 -> V_114 , V_113 ) ;
}
F_70 (iommu, drhd)
F_148 ( V_49 -> V_306 ) ;
}
static void T_1 F_290 ( void )
{
F_291 ( & V_317 ) ;
}
static inline void F_290 ( void ) {}
static void T_1 F_292 ( struct V_239 * V_240 )
{
F_201 ( & V_240 -> V_318 , & V_319 ) ;
}
int T_1 F_293 ( struct V_320 * V_321 )
{
struct V_322 * V_240 ;
struct V_239 * V_323 ;
V_323 = F_227 ( sizeof( * V_323 ) , V_168 ) ;
if ( ! V_323 )
return - V_110 ;
V_323 -> V_324 = V_321 ;
V_240 = (struct V_322 * ) V_321 ;
V_323 -> V_242 = V_240 -> V_242 ;
V_323 -> V_243 = V_240 -> V_243 ;
F_292 ( V_323 ) ;
return 0 ;
}
static int T_1
F_294 ( struct V_239 * V_323 )
{
struct V_322 * V_240 ;
int V_88 ;
V_240 = (struct V_322 * ) V_323 -> V_324 ;
V_88 = F_295 ( ( void * ) ( V_240 + 1 ) ,
( ( void * ) V_240 ) + V_240 -> V_321 . V_217 ,
& V_323 -> V_76 , & V_323 -> V_77 , V_240 -> V_72 ) ;
if ( V_88 || ( V_323 -> V_76 == 0 ) ) {
F_194 ( & V_323 -> V_318 ) ;
F_148 ( V_323 ) ;
}
return V_88 ;
}
int T_1 F_296 ( struct V_320 * V_324 )
{
struct V_325 * V_326 ;
struct V_327 * V_328 ;
V_326 = F_297 ( V_324 , struct V_325 , V_321 ) ;
V_328 = F_227 ( sizeof( * V_328 ) , V_168 ) ;
if ( ! V_328 )
return - V_110 ;
V_328 -> V_324 = V_324 ;
V_328 -> V_82 = V_326 -> V_58 & 0x1 ;
F_201 ( & V_328 -> V_318 , & V_329 ) ;
return 0 ;
}
static int T_1 F_298 ( struct V_327 * V_328 )
{
int V_303 ;
struct V_325 * V_326 ;
if ( V_328 -> V_82 )
return 0 ;
V_326 = F_297 ( V_328 -> V_324 , struct V_325 , V_321 ) ;
V_303 = F_295 ( ( void * ) ( V_326 + 1 ) ,
( void * ) V_326 + V_326 -> V_321 . V_217 ,
& V_328 -> V_76 , & V_328 -> V_77 ,
V_326 -> V_72 ) ;
if ( V_303 || ! V_328 -> V_76 ) {
F_194 ( & V_328 -> V_318 ) ;
F_148 ( V_328 ) ;
}
return V_303 ;
}
int F_117 ( struct V_174 * V_149 )
{
int V_64 ;
struct V_330 * V_73 ;
struct V_325 * V_326 ;
struct V_327 * V_328 ;
V_149 = F_299 ( V_149 ) ;
F_115 (atsru, &dmar_atsr_units, list) {
V_326 = F_297 ( V_328 -> V_324 , struct V_325 , V_321 ) ;
if ( V_326 -> V_72 == F_175 ( V_149 -> V_73 ) )
goto V_145;
}
return 0 ;
V_145:
for ( V_73 = V_149 -> V_73 ; V_73 ; V_73 = V_73 -> V_93 ) {
struct V_174 * V_331 = V_73 -> V_200 ;
if ( ! V_331 || ! F_177 ( V_331 ) ||
F_221 ( V_331 ) == V_254 )
return 0 ;
if ( F_221 ( V_331 ) == V_332 ) {
for ( V_64 = 0 ; V_64 < V_328 -> V_76 ; V_64 ++ )
if ( V_328 -> V_77 [ V_64 ] == V_331 )
return 1 ;
break;
}
}
if ( V_328 -> V_82 )
return 1 ;
return 0 ;
}
int T_1 F_300 ( void )
{
struct V_239 * V_240 , * V_333 ;
struct V_327 * V_326 , * V_334 ;
int V_88 = 0 ;
F_301 (rmrr, rmrr_n, &dmar_rmrr_units, list) {
V_88 = F_294 ( V_240 ) ;
if ( V_88 )
return V_88 ;
}
F_301 (atsr, atsr_n, &dmar_atsr_units, list) {
V_88 = F_298 ( V_326 ) ;
if ( V_88 )
return V_88 ;
}
return V_88 ;
}
static int F_302 ( struct V_335 * V_336 ,
unsigned long V_337 , void * V_285 )
{
struct V_265 * V_149 = V_285 ;
struct V_174 * V_175 = F_238 ( V_149 ) ;
struct V_55 * V_56 ;
if ( F_246 ( V_149 ) )
return 0 ;
V_56 = F_197 ( V_175 ) ;
if ( ! V_56 )
return 0 ;
if ( V_337 == V_338 && ! V_263 ) {
F_247 ( V_56 , V_175 ) ;
if ( ! ( V_56 -> V_58 & V_59 ) &&
! ( V_56 -> V_58 & V_60 ) &&
F_195 ( & V_56 -> V_77 ) )
F_144 ( V_56 ) ;
}
return 0 ;
}
int T_1 F_303 ( void )
{
int V_88 = 0 ;
V_264 = F_304 () ;
if ( F_305 () ) {
if ( V_264 )
F_289 ( L_68 ) ;
return - V_182 ;
}
if ( F_306 () < 0 ) {
if ( V_264 )
F_289 ( L_69 ) ;
return - V_182 ;
}
if ( V_339 || V_34 )
return - V_182 ;
if ( F_274 () ) {
if ( V_264 )
F_289 ( L_70 ) ;
return - V_182 ;
}
if ( F_195 ( & V_319 ) )
F_42 ( V_35 L_71 ) ;
if ( F_195 ( & V_329 ) )
F_42 ( V_35 L_72 ) ;
if ( F_153 () ) {
if ( V_264 )
F_289 ( L_73 ) ;
return - V_182 ;
}
F_282 () ;
V_88 = F_225 () ;
if ( V_88 ) {
if ( V_264 )
F_289 ( L_74 ) ;
F_42 ( V_143 L_75 ) ;
F_168 ( & V_176 ) ;
F_276 () ;
return V_88 ;
}
F_42 ( V_35
L_76 ) ;
F_307 ( & V_289 ) ;
#ifdef F_308
V_340 = 0 ;
#endif
V_341 = & V_342 ;
F_290 () ;
F_309 ( & V_267 , & V_343 ) ;
F_310 ( & V_267 , & V_344 ) ;
V_345 = 1 ;
return 0 ;
}
static void F_311 ( struct V_48 * V_49 ,
struct V_174 * V_175 )
{
struct V_174 * V_108 , * V_93 ;
if ( ! V_49 || ! V_175 )
return;
V_108 = F_176 ( V_175 ) ;
if ( V_108 ) {
V_93 = V_175 -> V_73 -> V_200 ;
while ( V_93 != V_108 ) {
F_191 ( V_49 , V_93 -> V_73 -> V_78 ,
V_93 -> V_74 ) ;
V_93 = V_93 -> V_73 -> V_200 ;
}
if ( F_177 ( V_108 ) )
F_191 ( V_49 ,
V_108 -> V_79 -> V_78 , 0 ) ;
else
F_191 ( V_49 , V_108 -> V_73 -> V_78 ,
V_108 -> V_74 ) ;
}
}
static void F_247 ( struct V_55 * V_56 ,
struct V_174 * V_175 )
{
struct V_144 * V_146 ;
struct V_48 * V_49 ;
unsigned long V_58 ;
int V_145 = 0 ;
struct V_346 * V_347 , * V_108 ;
V_49 = F_74 ( F_175 ( V_175 -> V_73 ) , V_175 -> V_73 -> V_78 ,
V_175 -> V_74 ) ;
if ( ! V_49 )
return;
F_79 ( & V_148 , V_58 ) ;
F_312 (entry, tmp, &domain->devices) {
V_146 = F_196 ( V_347 , struct V_144 , V_223 ) ;
if ( V_146 -> V_72 == F_175 ( V_175 -> V_73 ) &&
V_146 -> V_73 == V_175 -> V_73 -> V_78 &&
V_146 -> V_74 == V_175 -> V_74 ) {
F_192 ( V_146 ) ;
F_80 ( & V_148 , V_58 ) ;
F_120 ( V_146 ) ;
F_191 ( V_49 , V_146 -> V_73 , V_146 -> V_74 ) ;
F_311 ( V_49 , V_175 ) ;
F_53 ( V_146 ) ;
F_79 ( & V_148 , V_58 ) ;
if ( V_145 )
break;
else
continue;
}
if ( V_49 == F_74 ( V_146 -> V_72 , V_146 -> V_73 ,
V_146 -> V_74 ) )
V_145 = 1 ;
}
F_80 ( & V_148 , V_58 ) ;
if ( V_145 == 0 ) {
unsigned long V_348 ;
F_79 ( & V_56 -> V_169 , V_348 ) ;
F_142 ( V_49 -> V_166 , V_56 -> V_61 ) ;
V_56 -> V_170 -- ;
F_73 ( V_56 ) ;
F_80 ( & V_56 -> V_169 , V_348 ) ;
if ( ! ( V_56 -> V_58 & V_59 ) &&
! ( V_56 -> V_58 & V_60 ) ) {
F_79 ( & V_49 -> V_86 , V_348 ) ;
F_142 ( V_56 -> V_173 , V_49 -> V_167 ) ;
V_49 -> V_157 [ V_56 -> V_173 ] = NULL ;
F_80 ( & V_49 -> V_86 , V_348 ) ;
}
}
}
static void F_313 ( struct V_55 * V_56 )
{
struct V_144 * V_146 ;
struct V_48 * V_49 ;
unsigned long V_349 , V_350 ;
F_79 ( & V_148 , V_349 ) ;
while ( ! F_195 ( & V_56 -> V_77 ) ) {
V_146 = F_196 ( V_56 -> V_77 . V_226 ,
struct V_144 , V_223 ) ;
F_192 ( V_146 ) ;
F_80 ( & V_148 , V_349 ) ;
F_120 ( V_146 ) ;
V_49 = F_74 ( V_146 -> V_72 , V_146 -> V_73 , V_146 -> V_74 ) ;
F_191 ( V_49 , V_146 -> V_73 , V_146 -> V_74 ) ;
F_311 ( V_49 , V_146 -> V_149 ) ;
F_79 ( & V_56 -> V_169 , V_350 ) ;
if ( F_314 ( V_49 -> V_166 ,
V_56 -> V_61 ) ) {
V_56 -> V_170 -- ;
F_73 ( V_56 ) ;
}
F_80 ( & V_56 -> V_169 , V_350 ) ;
F_53 ( V_146 ) ;
F_79 ( & V_148 , V_349 ) ;
}
F_80 ( & V_148 , V_349 ) ;
}
static struct V_55 * F_315 ( void )
{
struct V_55 * V_56 ;
V_56 = F_48 () ;
if ( ! V_56 )
return NULL ;
V_56 -> V_173 = V_351 ++ ;
V_56 -> V_99 = - 1 ;
memset ( V_56 -> V_61 , 0 , sizeof( V_56 -> V_61 ) ) ;
V_56 -> V_58 = V_59 ;
return V_56 ;
}
static int F_210 ( struct V_55 * V_56 , int V_189 )
{
int V_190 ;
F_154 ( & V_56 -> V_188 , V_177 ) ;
F_138 ( & V_56 -> V_169 ) ;
F_159 ( V_56 ) ;
V_56 -> V_109 = V_189 ;
V_190 = F_161 ( V_189 ) ;
V_56 -> V_1 = F_3 ( V_190 ) ;
F_165 ( & V_56 -> V_77 ) ;
V_56 -> V_170 = 0 ;
V_56 -> V_65 = 0 ;
V_56 -> V_67 = 0 ;
V_56 -> V_71 = 0 ;
V_56 -> V_352 = 0 ;
V_56 -> V_99 = - 1 ;
V_56 -> V_95 = (struct V_25 * ) F_43 ( V_56 -> V_99 ) ;
if ( ! V_56 -> V_95 )
return - V_110 ;
F_76 ( V_56 , V_56 -> V_95 , V_191 ) ;
return 0 ;
}
static void F_316 ( struct V_55 * V_56 )
{
unsigned long V_58 ;
struct V_68 * V_69 ;
struct V_48 * V_49 ;
unsigned long V_64 ;
unsigned long V_164 ;
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
V_164 = F_136 ( V_49 -> V_52 ) ;
F_65 (i, iommu->domain_ids, ndomains) {
if ( V_49 -> V_157 [ V_64 ] == V_56 ) {
F_79 ( & V_49 -> V_86 , V_58 ) ;
F_142 ( V_64 , V_49 -> V_167 ) ;
V_49 -> V_157 [ V_64 ] = NULL ;
F_80 ( & V_49 -> V_86 , V_58 ) ;
break;
}
}
}
}
static void F_143 ( struct V_55 * V_56 )
{
if ( ! V_56 )
return;
F_313 ( V_56 ) ;
F_168 ( & V_56 -> V_188 ) ;
F_89 ( V_56 , 0 , F_91 ( V_56 -> V_109 ) ) ;
F_90 ( V_56 , 0 , F_91 ( V_56 -> V_109 ) ) ;
F_316 ( V_56 ) ;
F_50 ( V_56 ) ;
}
static int F_317 ( struct V_353 * V_56 )
{
struct V_55 * V_55 ;
V_55 = F_315 () ;
if ( ! V_55 ) {
F_42 ( V_143
L_77 ) ;
return - V_110 ;
}
if ( F_210 ( V_55 , V_54 ) ) {
F_42 ( V_143
L_78 ) ;
F_143 ( V_55 ) ;
return - V_110 ;
}
F_73 ( V_55 ) ;
V_56 -> V_354 = V_55 ;
V_56 -> V_355 . V_356 = 0 ;
V_56 -> V_355 . V_357 = F_318 ( V_55 -> V_109 ) ;
V_56 -> V_355 . V_358 = true ;
return 0 ;
}
static void F_319 ( struct V_353 * V_56 )
{
struct V_55 * V_55 = V_56 -> V_354 ;
V_56 -> V_354 = NULL ;
F_143 ( V_55 ) ;
}
static int F_320 ( struct V_353 * V_56 ,
struct V_265 * V_149 )
{
struct V_55 * V_55 = V_56 -> V_354 ;
struct V_174 * V_175 = F_238 ( V_149 ) ;
struct V_48 * V_49 ;
int V_92 ;
if ( F_172 ( F_178 ( V_175 ) ) ) {
struct V_55 * V_359 ;
V_359 = F_197 ( V_175 ) ;
if ( V_359 ) {
if ( V_55 -> V_58 & V_59 ||
V_55 -> V_58 & V_60 )
F_247 ( V_359 , V_175 ) ;
else
F_167 ( V_359 ) ;
}
}
V_49 = F_74 ( F_175 ( V_175 -> V_73 ) , V_175 -> V_73 -> V_78 ,
V_175 -> V_74 ) ;
if ( ! V_49 )
return - V_182 ;
V_92 = F_2 ( V_49 -> V_1 ) ;
if ( V_92 > F_163 ( V_49 -> V_52 ) )
V_92 = F_163 ( V_49 -> V_52 ) ;
if ( V_55 -> V_352 > ( 1LL << V_92 ) ) {
F_42 ( V_143 L_79
L_80 ,
V_360 , V_92 , V_55 -> V_352 ) ;
return - V_195 ;
}
V_55 -> V_109 = V_92 ;
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
return F_216 ( V_55 , V_175 , V_194 ) ;
}
static void F_321 ( struct V_353 * V_56 ,
struct V_265 * V_149 )
{
struct V_55 * V_55 = V_56 -> V_354 ;
struct V_174 * V_175 = F_238 ( V_149 ) ;
F_247 ( V_55 , V_175 ) ;
}
static int F_322 ( struct V_353 * V_56 ,
unsigned long V_46 , T_6 V_361 ,
T_5 V_84 , int V_362 )
{
struct V_55 * V_55 = V_56 -> V_354 ;
V_23 V_352 ;
int V_30 = 0 ;
int V_88 ;
if ( V_362 & V_363 )
V_30 |= V_27 ;
if ( V_362 & V_364 )
V_30 |= V_28 ;
if ( ( V_362 & V_365 ) && V_55 -> V_67 )
V_30 |= V_29 ;
V_352 = V_46 + V_84 ;
if ( V_55 -> V_352 < V_352 ) {
V_23 V_81 ;
V_81 = F_318 ( V_55 -> V_109 ) + 1 ;
if ( V_81 < V_352 ) {
F_42 ( V_143 L_79
L_80 ,
V_360 , V_55 -> V_109 , V_352 ) ;
return - V_195 ;
}
V_55 -> V_352 = V_352 ;
}
V_84 = F_179 ( V_361 , V_84 ) ;
V_88 = F_190 ( V_55 , V_46 >> V_10 ,
V_361 >> V_10 , V_84 , V_30 ) ;
return V_88 ;
}
static T_5 F_323 ( struct V_353 * V_56 ,
unsigned long V_46 , T_5 V_84 )
{
struct V_55 * V_55 = V_56 -> V_354 ;
int V_107 ;
V_107 = F_89 ( V_55 , V_46 >> V_10 ,
( V_46 + V_84 - 1 ) >> V_10 ) ;
if ( V_55 -> V_352 == V_46 + V_84 )
V_55 -> V_352 = V_46 ;
return V_191 << V_107 ;
}
static T_6 F_324 ( struct V_353 * V_56 ,
unsigned long V_46 )
{
struct V_55 * V_55 = V_56 -> V_354 ;
struct V_25 * V_26 ;
V_23 V_366 = 0 ;
V_26 = F_86 ( V_55 , V_46 >> V_10 , 0 ) ;
if ( V_26 )
V_366 = F_34 ( V_26 ) ;
return V_366 ;
}
static int F_325 ( struct V_353 * V_56 ,
unsigned long V_52 )
{
struct V_55 * V_55 = V_56 -> V_354 ;
if ( V_52 == V_367 )
return V_55 -> V_67 ;
if ( V_52 == V_368 )
return V_369 ;
return 0 ;
}
static void F_326 ( struct V_174 * * V_370 , struct V_174 * V_371 )
{
F_327 ( * V_370 ) ;
* V_370 = V_371 ;
}
static int F_328 ( struct V_265 * V_149 )
{
struct V_174 * V_175 = F_238 ( V_149 ) ;
struct V_174 * V_331 , * V_372 = NULL ;
struct V_373 * V_374 ;
int V_88 ;
if ( ! F_74 ( F_175 ( V_175 -> V_73 ) ,
V_175 -> V_73 -> V_78 , V_175 -> V_74 ) )
return - V_182 ;
V_331 = F_176 ( V_175 ) ;
if ( V_331 ) {
if ( F_177 ( V_331 ) )
V_372 = F_329 (
F_175 ( V_175 -> V_73 ) ,
V_331 -> V_79 -> V_78 , 0 ) ;
if ( ! V_372 )
V_372 = F_330 ( V_331 ) ;
} else
V_372 = F_330 ( V_175 ) ;
F_326 ( & V_372 , F_331 ( V_372 ) ) ;
if ( V_372 -> V_375 &&
! F_332 ( V_372 , V_376 ) )
F_326 ( & V_372 ,
F_333 ( V_372 -> V_73 ,
F_279 ( F_170 ( V_372 -> V_74 ) ,
0 ) ) ) ;
while ( ! F_220 ( V_372 -> V_73 ) ) {
struct V_330 * V_73 = V_372 -> V_73 ;
while ( ! V_73 -> V_200 ) {
if ( ! F_220 ( V_73 ) )
V_73 = V_73 -> V_93 ;
else
goto V_377;
}
if ( F_334 ( V_73 -> V_200 , NULL , V_376 ) )
break;
F_326 ( & V_372 , F_330 ( V_73 -> V_200 ) ) ;
}
V_377:
V_374 = F_335 ( & V_372 -> V_149 ) ;
F_327 ( V_372 ) ;
if ( ! V_374 ) {
V_374 = F_336 () ;
if ( F_337 ( V_374 ) )
return F_338 ( V_374 ) ;
}
V_88 = F_339 ( V_374 , V_149 ) ;
F_340 ( V_374 ) ;
return V_88 ;
}
static void F_341 ( struct V_265 * V_149 )
{
F_342 ( V_149 ) ;
}
static void T_8 F_343 ( struct V_174 * V_149 )
{
F_42 ( V_35 L_81 ) ;
V_123 = 1 ;
if ( V_149 -> V_378 == 0x07 ) {
F_42 ( V_35 L_82 ) ;
V_36 = 0 ;
}
}
static void T_8 F_344 ( struct V_174 * V_149 )
{
unsigned short V_379 ;
if ( F_345 ( V_149 , V_380 , & V_379 ) )
return;
if ( ! ( V_379 & V_381 ) ) {
F_42 ( V_35 L_83 ) ;
V_36 = 0 ;
} else if ( V_36 ) {
F_42 ( V_35 L_84 ) ;
V_38 = 1 ;
}
}
static void T_1 F_233 ( void )
{
struct V_174 * V_175 ;
T_9 V_382 ;
V_175 = F_346 ( V_383 , 0x3a3e , NULL ) ;
if ( ! V_175 )
return;
F_327 ( V_175 ) ;
V_175 = F_346 ( V_383 , 0x342e , NULL ) ;
if ( ! V_175 )
return;
if ( F_347 ( V_175 , 0x188 , & V_382 ) ) {
F_327 ( V_175 ) ;
return;
}
F_327 ( V_175 ) ;
if ( V_382 & 1 )
return;
V_382 &= 0x1c ;
if ( V_382 == 0x10 )
return;
if ( ! V_382 ) {
F_204 ( 1 , L_85
L_31 ,
F_205 ( V_235 ) ,
F_205 ( V_236 ) ,
F_205 ( V_237 ) ) ;
V_247 |= V_249 ;
return;
}
F_42 ( V_384 L_86 ,
V_382 ) ;
}
