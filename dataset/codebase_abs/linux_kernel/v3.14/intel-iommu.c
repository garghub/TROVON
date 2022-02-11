static inline int F_1 ( int V_1 )
{
return V_1 + 2 ;
}
static inline int F_2 ( int V_1 )
{
return F_3 ( int , 30 + V_1 * V_2 , V_3 ) ;
}
static inline int F_4 ( int V_4 )
{
return F_5 ( V_4 - 30 , V_2 ) ;
}
static inline unsigned int F_6 ( int V_5 )
{
return ( V_5 - 1 ) * V_2 ;
}
static inline int F_7 ( unsigned long V_6 , int V_5 )
{
return ( V_6 >> F_6 ( V_5 ) ) & V_7 ;
}
static inline unsigned long F_8 ( int V_5 )
{
return - 1UL << F_6 ( V_5 ) ;
}
static inline unsigned long F_9 ( int V_5 )
{
return 1UL << F_6 ( V_5 ) ;
}
static inline unsigned long F_10 ( unsigned long V_6 , int V_5 )
{
return ( V_6 + F_9 ( V_5 ) - 1 ) & F_8 ( V_5 ) ;
}
static inline unsigned long F_11 ( unsigned int V_8 )
{
return 1 << F_3 ( int , ( V_8 - 1 ) * V_2 , V_9 ) ;
}
static inline unsigned long F_12 ( unsigned long V_10 )
{
return V_10 >> ( V_11 - V_12 ) ;
}
static inline unsigned long F_13 ( unsigned long V_13 )
{
return V_13 << ( V_11 - V_12 ) ;
}
static inline unsigned long F_14 ( struct V_14 * V_15 )
{
return F_13 ( F_15 ( V_15 ) ) ;
}
static inline unsigned long F_16 ( void * V_16 )
{
return F_14 ( F_17 ( V_16 ) ) ;
}
static inline bool F_18 ( struct V_17 * V_18 )
{
return ( V_18 -> V_19 & 1 ) ;
}
static inline void F_19 ( struct V_17 * V_18 )
{
V_18 -> V_19 |= 1 ;
}
static inline void F_20 ( struct V_17 * V_18 , unsigned long V_20 )
{
V_18 -> V_19 |= V_20 & V_21 ;
}
static inline struct V_22 *
F_21 ( struct V_17 * V_18 )
{
return (struct V_22 * )
( F_18 ( V_18 ) ? F_22 (
V_18 -> V_19 & V_21 ) :
NULL ) ;
}
static inline bool F_23 ( struct V_22 * V_23 )
{
return ( V_23 -> V_24 & 1 ) ;
}
static inline void F_24 ( struct V_22 * V_23 )
{
V_23 -> V_24 |= 1 ;
}
static inline void F_25 ( struct V_22 * V_23 )
{
V_23 -> V_24 &= ( ( ( V_25 ) - 1 ) << 2 ) | 1 ;
}
static inline void F_26 ( struct V_22 * V_23 ,
unsigned long V_20 )
{
V_23 -> V_24 &= ( ( ( V_25 ) - 1 ) << 4 ) | 3 ;
V_23 -> V_24 |= ( V_20 & 3 ) << 2 ;
}
static inline void F_27 ( struct V_22 * V_23 ,
unsigned long V_20 )
{
V_23 -> V_24 |= V_20 & V_21 ;
}
static inline void F_28 ( struct V_22 * V_23 ,
unsigned long V_20 )
{
V_23 -> V_26 |= V_20 & 7 ;
}
static inline void F_29 ( struct V_22 * V_23 ,
unsigned long V_20 )
{
V_23 -> V_26 |= ( V_20 & ( ( 1 << 16 ) - 1 ) ) << 8 ;
}
static inline void F_30 ( struct V_22 * V_23 )
{
V_23 -> V_24 = 0 ;
V_23 -> V_26 = 0 ;
}
static inline void F_31 ( struct V_27 * V_28 )
{
V_28 -> V_19 = 0 ;
}
static inline V_25 F_32 ( struct V_27 * V_28 )
{
#ifdef F_33
return V_28 -> V_19 & V_21 ;
#else
return F_34 ( & V_28 -> V_19 , 0ULL , 0ULL ) & V_21 ;
#endif
}
static inline bool F_35 ( struct V_27 * V_28 )
{
return ( V_28 -> V_19 & 3 ) != 0 ;
}
static inline bool F_36 ( struct V_27 * V_28 )
{
return ( V_28 -> V_19 & ( 1 << 7 ) ) ;
}
static inline int F_37 ( struct V_27 * V_28 )
{
return ! ( ( unsigned long ) V_28 & ~ V_21 ) ;
}
static int T_1 F_38 ( char * V_29 )
{
if ( ! V_29 )
return - V_30 ;
while ( * V_29 ) {
if ( ! strncmp ( V_29 , L_1 , 2 ) ) {
V_31 = 0 ;
F_39 ( V_32 L_2 ) ;
} else if ( ! strncmp ( V_29 , L_3 , 3 ) ) {
V_31 = 1 ;
F_39 ( V_32 L_4 ) ;
} else if ( ! strncmp ( V_29 , L_5 , 8 ) ) {
V_33 = 0 ;
F_39 ( V_32
L_6 ) ;
} else if ( ! strncmp ( V_29 , L_7 , 8 ) ) {
F_39 ( V_32
L_8 ) ;
V_34 = 1 ;
} else if ( ! strncmp ( V_29 , L_9 , 6 ) ) {
F_39 ( V_32
L_10 ) ;
V_35 = 1 ;
} else if ( ! strncmp ( V_29 , L_11 , 6 ) ) {
F_39 ( V_32
L_12 ) ;
V_36 = 0 ;
}
V_29 += strcspn ( V_29 , L_13 ) ;
while ( * V_29 == ',' )
V_29 ++ ;
}
return 0 ;
}
static inline void * F_40 ( int V_37 )
{
struct V_14 * V_14 ;
void * V_38 = NULL ;
V_14 = F_41 ( V_37 , V_39 | V_40 , 0 ) ;
if ( V_14 )
V_38 = F_42 ( V_14 ) ;
return V_38 ;
}
static inline void F_43 ( void * V_38 )
{
F_44 ( ( unsigned long ) V_38 ) ;
}
static inline void * F_45 ( void )
{
return F_46 ( V_41 , V_39 ) ;
}
static void F_47 ( void * V_38 )
{
F_48 ( V_41 , V_38 ) ;
}
static inline void * F_49 ( void )
{
return F_46 ( V_42 , V_39 ) ;
}
static inline void F_50 ( void * V_38 )
{
F_48 ( V_42 , V_38 ) ;
}
struct V_43 * F_51 ( void )
{
return F_46 ( V_44 , V_39 ) ;
}
void F_52 ( struct V_43 * V_43 )
{
F_48 ( V_44 , V_43 ) ;
}
static int F_53 ( struct V_45 * V_46 , int V_47 )
{
unsigned long V_48 ;
int V_1 = - 1 ;
V_48 = F_54 ( V_46 -> V_49 ) ;
for ( V_1 = F_4 ( V_47 ) ;
V_1 >= 0 ; V_1 -- ) {
if ( F_55 ( V_1 , & V_48 ) )
break;
}
return V_1 ;
}
int F_56 ( struct V_45 * V_46 )
{
return F_53 ( V_46 , V_3 ) ;
}
int F_57 ( struct V_45 * V_46 )
{
return F_53 ( V_46 , V_50 ) ;
}
static struct V_45 * F_58 ( struct V_51 * V_52 )
{
int V_53 ;
F_59 ( V_52 -> V_54 & V_55 ) ;
F_59 ( V_52 -> V_54 & V_56 ) ;
V_53 = F_60 ( V_52 -> V_57 , V_58 ) ;
if ( V_53 < 0 || V_53 >= V_58 )
return NULL ;
return V_59 [ V_53 ] ;
}
static void F_61 ( struct V_51 * V_52 )
{
int V_60 ;
V_60 = F_60 ( V_52 -> V_57 , V_58 ) ;
V_52 -> V_61 = V_60 < V_58 ? 1 : 0 ;
F_62 (i, domain->iommu_bmp, g_num_of_iommus) {
if ( ! F_63 ( V_59 [ V_60 ] -> V_62 ) ) {
V_52 -> V_61 = 0 ;
break;
}
}
}
static void F_64 ( struct V_51 * V_52 )
{
int V_60 ;
V_52 -> V_63 = 1 ;
F_62 (i, domain->iommu_bmp, g_num_of_iommus) {
if ( ! F_65 ( V_59 [ V_60 ] -> V_62 ) ) {
V_52 -> V_63 = 0 ;
break;
}
}
}
static void F_66 ( struct V_51 * V_52 )
{
struct V_64 * V_65 ;
struct V_45 * V_46 = NULL ;
int V_66 = 0xf ;
if ( ! V_36 ) {
V_52 -> V_67 = 0 ;
return;
}
F_67 (iommu, drhd) {
V_66 &= F_68 ( V_46 -> V_49 ) ;
if ( ! V_66 ) {
break;
}
}
V_52 -> V_67 = F_69 ( V_66 ) ;
}
static void F_70 ( struct V_51 * V_52 )
{
F_61 ( V_52 ) ;
F_64 ( V_52 ) ;
F_66 ( V_52 ) ;
}
static struct V_45 * F_71 ( int V_68 , T_2 V_69 , T_2 V_70 )
{
struct V_64 * V_65 = NULL ;
int V_60 ;
F_72 (drhd) {
if ( V_68 != V_65 -> V_68 )
continue;
for ( V_60 = 0 ; V_60 < V_65 -> V_71 ; V_60 ++ ) {
if ( V_65 -> V_72 [ V_60 ] &&
V_65 -> V_72 [ V_60 ] -> V_69 -> V_73 == V_69 &&
V_65 -> V_72 [ V_60 ] -> V_70 == V_70 )
return V_65 -> V_46 ;
if ( V_65 -> V_72 [ V_60 ] &&
V_65 -> V_72 [ V_60 ] -> V_74 &&
V_65 -> V_72 [ V_60 ] -> V_74 -> V_73 <= V_69 &&
V_65 -> V_72 [ V_60 ] -> V_74 -> V_75 . V_76 >= V_69 )
return V_65 -> V_46 ;
}
if ( V_65 -> V_77 )
return V_65 -> V_46 ;
}
return NULL ;
}
static void F_73 ( struct V_51 * V_52 ,
void * V_78 , int V_79 )
{
if ( ! V_52 -> V_61 )
F_74 ( V_78 , V_79 ) ;
}
static struct V_22 * F_75 ( struct V_45 * V_46 ,
T_2 V_69 , T_2 V_70 )
{
struct V_17 * V_18 ;
struct V_22 * V_23 ;
unsigned long V_80 ;
unsigned long V_54 ;
F_76 ( & V_46 -> V_81 , V_54 ) ;
V_18 = & V_46 -> V_17 [ V_69 ] ;
V_23 = F_21 ( V_18 ) ;
if ( ! V_23 ) {
V_23 = (struct V_22 * )
F_40 ( V_46 -> V_37 ) ;
if ( ! V_23 ) {
F_77 ( & V_46 -> V_81 , V_54 ) ;
return NULL ;
}
F_78 ( V_46 , ( void * ) V_23 , V_82 ) ;
V_80 = F_79 ( ( void * ) V_23 ) ;
F_20 ( V_18 , V_80 ) ;
F_19 ( V_18 ) ;
F_78 ( V_46 , V_18 , sizeof( * V_18 ) ) ;
}
F_77 ( & V_46 -> V_81 , V_54 ) ;
return & V_23 [ V_70 ] ;
}
static int F_80 ( struct V_45 * V_46 , T_2 V_69 , T_2 V_70 )
{
struct V_17 * V_18 ;
struct V_22 * V_23 ;
int V_83 ;
unsigned long V_54 ;
F_76 ( & V_46 -> V_81 , V_54 ) ;
V_18 = & V_46 -> V_17 [ V_69 ] ;
V_23 = F_21 ( V_18 ) ;
if ( ! V_23 ) {
V_83 = 0 ;
goto V_84;
}
V_83 = F_23 ( & V_23 [ V_70 ] ) ;
V_84:
F_77 ( & V_46 -> V_81 , V_54 ) ;
return V_83 ;
}
static void F_81 ( struct V_45 * V_46 , T_2 V_69 , T_2 V_70 )
{
struct V_17 * V_18 ;
struct V_22 * V_23 ;
unsigned long V_54 ;
F_76 ( & V_46 -> V_81 , V_54 ) ;
V_18 = & V_46 -> V_17 [ V_69 ] ;
V_23 = F_21 ( V_18 ) ;
if ( V_23 ) {
F_30 ( & V_23 [ V_70 ] ) ;
F_78 ( V_46 , & V_23 [ V_70 ] , \
sizeof( * V_23 ) ) ;
}
F_77 ( & V_46 -> V_81 , V_54 ) ;
}
static void F_82 ( struct V_45 * V_46 )
{
struct V_17 * V_18 ;
int V_60 ;
unsigned long V_54 ;
struct V_22 * V_23 ;
F_76 ( & V_46 -> V_81 , V_54 ) ;
if ( ! V_46 -> V_17 ) {
goto V_84;
}
for ( V_60 = 0 ; V_60 < V_85 ; V_60 ++ ) {
V_18 = & V_46 -> V_17 [ V_60 ] ;
V_23 = F_21 ( V_18 ) ;
if ( V_23 )
F_43 ( V_23 ) ;
}
F_43 ( V_46 -> V_17 ) ;
V_46 -> V_17 = NULL ;
V_84:
F_77 ( & V_46 -> V_81 , V_54 ) ;
}
static struct V_27 * F_83 ( struct V_51 * V_52 ,
unsigned long V_6 , int V_86 )
{
int V_87 = F_2 ( V_52 -> V_1 ) - V_12 ;
struct V_27 * V_88 , * V_28 = NULL ;
int V_5 = F_1 ( V_52 -> V_1 ) ;
int V_89 ;
F_59 ( ! V_52 -> V_90 ) ;
if ( V_87 < V_91 && V_6 > > V_87 )
return NULL ;
V_88 = V_52 -> V_90 ;
while ( V_5 > 0 ) {
void * V_92 ;
V_89 = F_7 ( V_6 , V_5 ) ;
V_28 = & V_88 [ V_89 ] ;
if ( ! V_86 && ( F_36 ( V_28 ) || ! F_35 ( V_28 ) ) )
break;
if ( V_5 == V_86 )
break;
if ( ! F_35 ( V_28 ) ) {
T_3 V_93 ;
V_92 = F_40 ( V_52 -> V_94 ) ;
if ( ! V_92 )
return NULL ;
F_73 ( V_52 , V_92 , V_95 ) ;
V_93 = ( ( T_3 ) F_16 ( V_92 ) << V_12 ) | V_96 | V_97 ;
if ( F_84 ( & V_28 -> V_19 , 0ULL , V_93 ) ) {
F_43 ( V_92 ) ;
} else {
F_32 ( V_28 ) ;
F_73 ( V_52 , V_28 , sizeof( * V_28 ) ) ;
}
}
V_88 = F_22 ( F_32 ( V_28 ) ) ;
V_5 -- ;
}
return V_28 ;
}
static struct V_27 * F_85 ( struct V_51 * V_52 ,
unsigned long V_6 ,
int V_5 , int * V_98 )
{
struct V_27 * V_88 , * V_28 = NULL ;
int V_99 = F_1 ( V_52 -> V_1 ) ;
int V_89 ;
V_88 = V_52 -> V_90 ;
while ( V_5 <= V_99 ) {
V_89 = F_7 ( V_6 , V_99 ) ;
V_28 = & V_88 [ V_89 ] ;
if ( V_5 == V_99 )
return V_28 ;
if ( ! F_35 ( V_28 ) ) {
* V_98 = V_99 ;
break;
}
if ( V_28 -> V_19 & V_100 ) {
* V_98 = V_99 ;
return V_28 ;
}
V_88 = F_22 ( F_32 ( V_28 ) ) ;
V_99 -- ;
}
return NULL ;
}
static int F_86 ( struct V_51 * V_52 ,
unsigned long V_101 ,
unsigned long V_102 )
{
int V_87 = F_2 ( V_52 -> V_1 ) - V_12 ;
unsigned int V_98 = 1 ;
struct V_27 * V_103 , * V_28 ;
F_59 ( V_87 < V_91 && V_101 > > V_87 ) ;
F_59 ( V_87 < V_91 && V_102 > > V_87 ) ;
F_59 ( V_101 > V_102 ) ;
do {
V_98 = 1 ;
V_103 = V_28 = F_85 ( V_52 , V_101 , 1 , & V_98 ) ;
if ( ! V_28 ) {
V_101 = F_10 ( V_101 + 1 , V_98 + 1 ) ;
continue;
}
do {
F_31 ( V_28 ) ;
V_101 += F_11 ( V_98 ) ;
V_28 ++ ;
} while ( V_101 <= V_102 && ! F_37 ( V_28 ) );
F_73 ( V_52 , V_103 ,
( void * ) V_28 - ( void * ) V_103 ) ;
} while ( V_101 && V_101 <= V_102 );
return F_3 ( int , ( V_98 - 1 ) * 9 , V_9 ) ;
}
static void F_87 ( struct V_51 * V_52 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_101 , unsigned long V_102 )
{
V_6 = F_88 ( V_101 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_104 ;
struct V_27 * V_105 ;
if ( ! F_35 ( V_28 ) || F_36 ( V_28 ) )
goto V_106;
V_104 = V_6 & F_8 ( V_5 - 1 ) ;
V_105 = F_22 ( F_32 ( V_28 ) ) ;
if ( V_5 > 2 )
F_87 ( V_52 , V_5 - 1 , V_105 ,
V_104 , V_101 , V_102 ) ;
if ( ! ( V_101 > V_104 ||
V_102 < V_104 + F_9 ( V_5 ) - 1 ) ) {
F_31 ( V_28 ) ;
F_73 ( V_52 , V_28 , sizeof( * V_28 ) ) ;
F_43 ( V_105 ) ;
}
V_106:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_37 ( ++ V_28 ) && V_6 <= V_102 );
}
static void F_89 ( struct V_51 * V_52 ,
unsigned long V_101 ,
unsigned long V_102 )
{
int V_87 = F_2 ( V_52 -> V_1 ) - V_12 ;
F_59 ( V_87 < V_91 && V_101 > > V_87 ) ;
F_59 ( V_87 < V_91 && V_102 > > V_87 ) ;
F_59 ( V_101 > V_102 ) ;
F_87 ( V_52 , F_1 ( V_52 -> V_1 ) ,
V_52 -> V_90 , 0 , V_101 , V_102 ) ;
if ( V_101 == 0 && V_102 == F_90 ( V_52 -> V_107 ) ) {
F_43 ( V_52 -> V_90 ) ;
V_52 -> V_90 = NULL ;
}
}
static int F_91 ( struct V_45 * V_46 )
{
struct V_17 * V_18 ;
unsigned long V_54 ;
V_18 = (struct V_17 * ) F_40 ( V_46 -> V_37 ) ;
if ( ! V_18 )
return - V_108 ;
F_78 ( V_46 , V_18 , V_109 ) ;
F_76 ( & V_46 -> V_81 , V_54 ) ;
V_46 -> V_17 = V_18 ;
F_77 ( & V_46 -> V_81 , V_54 ) ;
return 0 ;
}
static void F_92 ( struct V_45 * V_46 )
{
void * V_78 ;
T_4 V_110 ;
unsigned long V_111 ;
V_78 = V_46 -> V_17 ;
F_93 ( & V_46 -> V_112 , V_111 ) ;
F_94 ( V_46 -> V_113 + V_114 , F_79 ( V_78 ) ) ;
F_95 ( V_46 -> V_115 | V_116 , V_46 -> V_113 + V_117 ) ;
F_96 ( V_46 , V_118 ,
V_119 , ( V_110 & V_120 ) , V_110 ) ;
F_97 ( & V_46 -> V_112 , V_111 ) ;
}
static void F_98 ( struct V_45 * V_46 )
{
T_4 V_19 ;
unsigned long V_111 ;
if ( ! V_121 && ! F_99 ( V_46 -> V_49 ) )
return;
F_93 ( & V_46 -> V_112 , V_111 ) ;
F_95 ( V_46 -> V_115 | V_122 , V_46 -> V_113 + V_117 ) ;
F_96 ( V_46 , V_118 ,
V_119 , ( ! ( V_19 & V_123 ) ) , V_19 ) ;
F_97 ( & V_46 -> V_112 , V_111 ) ;
}
static void F_100 ( struct V_45 * V_46 ,
T_5 V_124 , T_5 V_125 , T_2 V_126 ,
V_25 type )
{
V_25 V_19 = 0 ;
unsigned long V_111 ;
switch ( type ) {
case V_127 :
V_19 = V_127 ;
break;
case V_128 :
V_19 = V_128 | F_101 ( V_124 ) ;
break;
case V_129 :
V_19 = V_129 | F_101 ( V_124 )
| F_102 ( V_125 ) | F_103 ( V_126 ) ;
break;
default:
F_104 () ;
}
V_19 |= V_130 ;
F_93 ( & V_46 -> V_112 , V_111 ) ;
F_94 ( V_46 -> V_113 + V_131 , V_19 ) ;
F_96 ( V_46 , V_131 ,
V_132 , ( ! ( V_19 & V_130 ) ) , V_19 ) ;
F_97 ( & V_46 -> V_112 , V_111 ) ;
}
static void F_105 ( struct V_45 * V_46 , T_5 V_124 ,
V_25 V_78 , unsigned int V_133 , V_25 type )
{
int V_134 = F_106 ( V_46 -> V_62 ) ;
V_25 V_19 = 0 , V_135 = 0 ;
unsigned long V_111 ;
switch ( type ) {
case V_136 :
V_19 = V_136 | V_137 ;
break;
case V_138 :
V_19 = V_138 | V_137 | F_107 ( V_124 ) ;
break;
case V_139 :
V_19 = V_139 | V_137 | F_107 ( V_124 ) ;
V_135 = V_133 | V_78 ;
break;
default:
F_104 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_108 ( V_46 -> V_49 ) )
V_19 |= V_140 ;
F_93 ( & V_46 -> V_112 , V_111 ) ;
if ( V_135 )
F_94 ( V_46 -> V_113 + V_134 , V_135 ) ;
F_94 ( V_46 -> V_113 + V_134 + 8 , V_19 ) ;
F_96 ( V_46 , V_134 + 8 ,
V_132 , ( ! ( V_19 & V_137 ) ) , V_19 ) ;
F_97 ( & V_46 -> V_112 , V_111 ) ;
if ( F_109 ( V_19 ) == 0 )
F_39 ( V_141 L_14 ) ;
if ( F_109 ( V_19 ) != F_110 ( type ) )
F_111 ( L_15 ,
( unsigned long long ) F_110 ( type ) ,
( unsigned long long ) F_109 ( V_19 ) ) ;
}
static struct V_142 * F_112 (
struct V_51 * V_52 , int V_68 , T_2 V_69 , T_2 V_70 )
{
int V_143 = 0 ;
unsigned long V_54 ;
struct V_142 * V_144 ;
struct V_45 * V_46 = F_71 ( V_68 , V_69 , V_70 ) ;
if ( ! F_113 ( V_46 -> V_62 ) )
return NULL ;
if ( ! V_46 -> V_145 )
return NULL ;
F_76 ( & V_146 , V_54 ) ;
F_114 (info, &domain->devices, link)
if ( V_144 -> V_69 == V_69 && V_144 -> V_70 == V_70 ) {
V_143 = 1 ;
break;
}
F_77 ( & V_146 , V_54 ) ;
if ( ! V_143 || ! V_144 -> V_147 )
return NULL ;
if ( ! F_115 ( V_144 -> V_147 , V_148 ) )
return NULL ;
if ( ! F_116 ( V_144 -> V_147 ) )
return NULL ;
V_144 -> V_46 = V_46 ;
return V_144 ;
}
static void F_117 ( struct V_142 * V_144 )
{
if ( ! V_144 )
return;
F_118 ( V_144 -> V_147 , V_12 ) ;
}
static void F_119 ( struct V_142 * V_144 )
{
if ( ! V_144 -> V_147 || ! F_120 ( V_144 -> V_147 ) )
return;
F_121 ( V_144 -> V_147 ) ;
}
static void F_122 ( struct V_51 * V_52 ,
V_25 V_78 , unsigned V_66 )
{
T_5 V_149 , V_150 ;
unsigned long V_54 ;
struct V_142 * V_144 ;
F_76 ( & V_146 , V_54 ) ;
F_114 (info, &domain->devices, link) {
if ( ! V_144 -> V_147 || ! F_120 ( V_144 -> V_147 ) )
continue;
V_149 = V_144 -> V_69 << 8 | V_144 -> V_70 ;
V_150 = F_123 ( V_144 -> V_147 ) ;
F_124 ( V_144 -> V_46 , V_149 , V_150 , V_78 , V_66 ) ;
}
F_77 ( & V_146 , V_54 ) ;
}
static void F_125 ( struct V_45 * V_46 , T_5 V_124 ,
unsigned long V_6 , unsigned int V_151 , int V_152 )
{
unsigned int V_66 = F_126 ( F_127 ( V_151 ) ) ;
T_3 V_78 = ( T_3 ) V_6 << V_12 ;
F_59 ( V_151 == 0 ) ;
if ( ! F_128 ( V_46 -> V_49 ) || V_66 > F_129 ( V_46 -> V_49 ) )
V_46 -> V_153 . V_154 ( V_46 , V_124 , 0 , 0 ,
V_138 ) ;
else
V_46 -> V_153 . V_154 ( V_46 , V_124 , V_78 , V_66 ,
V_139 ) ;
if ( ! F_130 ( V_46 -> V_49 ) || ! V_152 )
F_122 ( V_46 -> V_155 [ V_124 ] , V_78 , V_66 ) ;
}
static void F_131 ( struct V_45 * V_46 )
{
T_4 V_156 ;
unsigned long V_54 ;
F_93 ( & V_46 -> V_112 , V_54 ) ;
V_156 = V_119 ( V_46 -> V_113 + V_157 ) ;
V_156 &= ~ V_158 ;
F_95 ( V_156 , V_46 -> V_113 + V_157 ) ;
F_96 ( V_46 , V_157 ,
V_119 , ! ( V_156 & V_159 ) , V_156 ) ;
F_97 ( & V_46 -> V_112 , V_54 ) ;
}
static int F_132 ( struct V_45 * V_46 )
{
T_4 V_110 ;
unsigned long V_54 ;
F_93 ( & V_46 -> V_112 , V_54 ) ;
V_46 -> V_115 |= V_160 ;
F_95 ( V_46 -> V_115 , V_46 -> V_113 + V_117 ) ;
F_96 ( V_46 , V_118 ,
V_119 , ( V_110 & V_161 ) , V_110 ) ;
F_97 ( & V_46 -> V_112 , V_54 ) ;
return 0 ;
}
static int F_133 ( struct V_45 * V_46 )
{
T_4 V_110 ;
unsigned long V_111 ;
F_93 ( & V_46 -> V_112 , V_111 ) ;
V_46 -> V_115 &= ~ V_160 ;
F_95 ( V_46 -> V_115 , V_46 -> V_113 + V_117 ) ;
F_96 ( V_46 , V_118 ,
V_119 , ( ! ( V_110 & V_161 ) ) , V_110 ) ;
F_97 ( & V_46 -> V_112 , V_111 ) ;
return 0 ;
}
static int F_134 ( struct V_45 * V_46 )
{
unsigned long V_162 ;
unsigned long V_163 ;
V_162 = F_135 ( V_46 -> V_49 ) ;
F_111 ( L_16 ,
V_46 -> V_164 , V_162 ) ;
V_163 = F_136 ( V_162 ) ;
F_137 ( & V_46 -> V_81 ) ;
V_46 -> V_165 = F_138 ( V_163 , sizeof( unsigned long ) , V_166 ) ;
if ( ! V_46 -> V_165 ) {
F_139 ( L_17 ,
V_46 -> V_164 ) ;
return - V_108 ;
}
V_46 -> V_155 = F_138 ( V_162 , sizeof( struct V_51 * ) ,
V_166 ) ;
if ( ! V_46 -> V_155 ) {
F_139 ( L_18 ,
V_46 -> V_164 ) ;
F_140 ( V_46 -> V_165 ) ;
V_46 -> V_165 = NULL ;
return - V_108 ;
}
if ( F_130 ( V_46 -> V_49 ) )
F_141 ( 0 , V_46 -> V_165 ) ;
return 0 ;
}
static void F_142 ( struct V_45 * V_46 )
{
struct V_51 * V_52 ;
int V_60 , V_167 ;
unsigned long V_54 ;
if ( ( V_46 -> V_155 ) && ( V_46 -> V_165 ) ) {
F_62 (i, iommu->domain_ids, cap_ndoms(iommu->cap)) {
V_52 = V_46 -> V_155 [ V_60 ] ;
F_143 ( V_60 , V_46 -> V_165 ) ;
F_76 ( & V_52 -> V_168 , V_54 ) ;
V_167 = -- V_52 -> V_169 ;
F_77 ( & V_52 -> V_168 , V_54 ) ;
if ( V_167 == 0 ) {
if ( V_52 -> V_54 & V_55 )
F_144 ( V_52 ) ;
else
F_145 ( V_52 ) ;
}
}
}
if ( V_46 -> V_115 & V_160 )
F_133 ( V_46 ) ;
F_140 ( V_46 -> V_155 ) ;
F_140 ( V_46 -> V_165 ) ;
V_46 -> V_155 = NULL ;
V_46 -> V_165 = NULL ;
V_59 [ V_46 -> V_164 ] = NULL ;
for ( V_60 = 0 ; V_60 < V_58 ; V_60 ++ ) {
if ( V_59 [ V_60 ] )
break;
}
if ( V_60 == V_58 )
F_140 ( V_59 ) ;
F_82 ( V_46 ) ;
}
static struct V_51 * F_146 ( void )
{
struct V_51 * V_52 ;
V_52 = F_45 () ;
if ( ! V_52 )
return NULL ;
V_52 -> V_94 = - 1 ;
memset ( V_52 -> V_57 , 0 , sizeof( V_52 -> V_57 ) ) ;
V_52 -> V_54 = 0 ;
return V_52 ;
}
static int F_147 ( struct V_51 * V_52 ,
struct V_45 * V_46 )
{
int V_170 ;
unsigned long V_162 ;
unsigned long V_54 ;
V_162 = F_135 ( V_46 -> V_49 ) ;
F_76 ( & V_46 -> V_81 , V_54 ) ;
V_170 = F_148 ( V_46 -> V_165 , V_162 ) ;
if ( V_170 >= V_162 ) {
F_77 ( & V_46 -> V_81 , V_54 ) ;
F_39 ( V_141 L_19 ) ;
return - V_108 ;
}
V_52 -> V_171 = V_170 ;
F_141 ( V_170 , V_46 -> V_165 ) ;
F_141 ( V_46 -> V_164 , V_52 -> V_57 ) ;
V_46 -> V_155 [ V_170 ] = V_52 ;
F_77 ( & V_46 -> V_81 , V_54 ) ;
return 0 ;
}
static void F_149 ( struct V_51 * V_52 ,
struct V_45 * V_46 )
{
unsigned long V_54 ;
int V_170 , V_162 ;
int V_143 = 0 ;
F_76 ( & V_46 -> V_81 , V_54 ) ;
V_162 = F_135 ( V_46 -> V_49 ) ;
F_62 (num, iommu->domain_ids, ndomains) {
if ( V_46 -> V_155 [ V_170 ] == V_52 ) {
V_143 = 1 ;
break;
}
}
if ( V_143 ) {
F_143 ( V_170 , V_46 -> V_165 ) ;
F_143 ( V_46 -> V_164 , V_52 -> V_57 ) ;
V_46 -> V_155 [ V_170 ] = NULL ;
}
F_77 ( & V_46 -> V_81 , V_54 ) ;
}
static int F_150 ( void )
{
struct V_172 * V_173 = NULL ;
struct V_43 * V_43 ;
int V_60 ;
F_151 ( & V_174 , V_175 ) ;
F_152 ( & V_174 . V_176 ,
& V_177 ) ;
V_43 = F_153 ( & V_174 , F_154 ( V_178 ) ,
F_154 ( V_179 ) ) ;
if ( ! V_43 ) {
F_39 ( V_141 L_20 ) ;
return - V_180 ;
}
F_155 (pdev) {
struct V_181 * V_182 ;
for ( V_60 = 0 ; V_60 < V_183 ; V_60 ++ ) {
V_182 = & V_173 -> V_181 [ V_60 ] ;
if ( ! V_182 -> V_54 || ! ( V_182 -> V_54 & V_184 ) )
continue;
V_43 = F_153 ( & V_174 ,
F_154 ( V_182 -> V_185 ) ,
F_154 ( V_182 -> V_76 ) ) ;
if ( ! V_43 ) {
F_39 ( V_141 L_21 ) ;
return - V_180 ;
}
}
}
return 0 ;
}
static void F_156 ( struct V_51 * V_52 )
{
F_157 ( & V_174 , & V_52 -> V_186 ) ;
}
static inline int F_158 ( int V_107 )
{
int V_1 ;
int V_182 = ( V_107 - 12 ) % 9 ;
if ( V_182 == 0 )
V_1 = V_107 ;
else
V_1 = V_107 + 9 - V_182 ;
if ( V_1 > 64 )
V_1 = 64 ;
return V_1 ;
}
static int F_159 ( struct V_51 * V_52 , int V_187 )
{
struct V_45 * V_46 ;
int V_188 , V_1 ;
unsigned long V_48 ;
F_151 ( & V_52 -> V_186 , V_175 ) ;
F_137 ( & V_52 -> V_168 ) ;
F_156 ( V_52 ) ;
V_46 = F_58 ( V_52 ) ;
if ( V_187 > F_160 ( V_46 -> V_49 ) )
V_187 = F_160 ( V_46 -> V_49 ) ;
V_52 -> V_107 = V_187 ;
V_188 = F_158 ( V_187 ) ;
V_1 = F_4 ( V_188 ) ;
V_48 = F_54 ( V_46 -> V_49 ) ;
if ( ! F_55 ( V_1 , & V_48 ) ) {
F_111 ( L_22 , V_1 ) ;
V_1 = F_161 ( & V_48 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_180 ;
}
V_52 -> V_1 = V_1 ;
F_162 ( & V_52 -> V_72 ) ;
if ( F_63 ( V_46 -> V_62 ) )
V_52 -> V_61 = 1 ;
else
V_52 -> V_61 = 0 ;
if ( F_65 ( V_46 -> V_62 ) )
V_52 -> V_63 = 1 ;
else
V_52 -> V_63 = 0 ;
V_52 -> V_67 = F_69 ( F_68 ( V_46 -> V_49 ) ) ;
V_52 -> V_169 = 1 ;
V_52 -> V_94 = V_46 -> V_37 ;
V_52 -> V_90 = (struct V_27 * ) F_40 ( V_52 -> V_94 ) ;
if ( ! V_52 -> V_90 )
return - V_108 ;
F_78 ( V_46 , V_52 -> V_90 , V_189 ) ;
return 0 ;
}
static void F_145 ( struct V_51 * V_52 )
{
struct V_64 * V_65 ;
struct V_45 * V_46 ;
if ( ! V_52 )
return;
if ( ! V_35 )
F_163 ( 0 ) ;
F_164 ( V_52 ) ;
F_165 ( & V_52 -> V_186 ) ;
F_86 ( V_52 , 0 , F_90 ( V_52 -> V_107 ) ) ;
F_89 ( V_52 , 0 , F_90 ( V_52 -> V_107 ) ) ;
F_67 (iommu, drhd)
if ( F_55 ( V_46 -> V_164 , V_52 -> V_57 ) )
F_149 ( V_52 , V_46 ) ;
F_47 ( V_52 ) ;
}
static int F_166 ( struct V_51 * V_52 , int V_68 ,
T_2 V_69 , T_2 V_70 , int V_190 )
{
struct V_22 * V_23 ;
unsigned long V_54 ;
struct V_45 * V_46 ;
struct V_27 * V_90 ;
unsigned long V_170 ;
unsigned long V_162 ;
int V_171 ;
int V_1 ;
struct V_142 * V_144 = NULL ;
F_111 ( L_23 ,
V_69 , F_167 ( V_70 ) , F_168 ( V_70 ) ) ;
F_59 ( ! V_52 -> V_90 ) ;
F_59 ( V_190 != V_191 &&
V_190 != V_192 ) ;
V_46 = F_71 ( V_68 , V_69 , V_70 ) ;
if ( ! V_46 )
return - V_180 ;
V_23 = F_75 ( V_46 , V_69 , V_70 ) ;
if ( ! V_23 )
return - V_108 ;
F_76 ( & V_46 -> V_81 , V_54 ) ;
if ( F_23 ( V_23 ) ) {
F_77 ( & V_46 -> V_81 , V_54 ) ;
return 0 ;
}
V_171 = V_52 -> V_171 ;
V_90 = V_52 -> V_90 ;
if ( V_52 -> V_54 & V_55 ||
V_52 -> V_54 & V_56 ) {
int V_143 = 0 ;
V_162 = F_135 ( V_46 -> V_49 ) ;
F_62 (num, iommu->domain_ids, ndomains) {
if ( V_46 -> V_155 [ V_170 ] == V_52 ) {
V_171 = V_170 ;
V_143 = 1 ;
break;
}
}
if ( V_143 == 0 ) {
V_170 = F_148 ( V_46 -> V_165 , V_162 ) ;
if ( V_170 >= V_162 ) {
F_77 ( & V_46 -> V_81 , V_54 ) ;
F_39 ( V_141 L_19 ) ;
return - V_193 ;
}
F_141 ( V_170 , V_46 -> V_165 ) ;
V_46 -> V_155 [ V_170 ] = V_52 ;
V_171 = V_170 ;
}
if ( V_190 != V_191 ) {
for ( V_1 = V_52 -> V_1 ; V_1 != V_46 -> V_1 ; V_1 -- ) {
V_90 = F_22 ( F_32 ( V_90 ) ) ;
if ( ! F_35 ( V_90 ) ) {
F_77 ( & V_46 -> V_81 , V_54 ) ;
return - V_108 ;
}
}
}
}
F_29 ( V_23 , V_171 ) ;
if ( V_190 != V_191 ) {
V_144 = F_112 ( V_52 , V_68 , V_69 , V_70 ) ;
V_190 = V_144 ? V_194 :
V_192 ;
}
if ( F_169 ( V_190 == V_191 ) )
F_28 ( V_23 , V_46 -> V_195 ) ;
else {
F_27 ( V_23 , F_79 ( V_90 ) ) ;
F_28 ( V_23 , V_46 -> V_1 ) ;
}
F_26 ( V_23 , V_190 ) ;
F_25 ( V_23 ) ;
F_24 ( V_23 ) ;
F_73 ( V_52 , V_23 , sizeof( * V_23 ) ) ;
if ( F_130 ( V_46 -> V_49 ) ) {
V_46 -> V_153 . V_196 ( V_46 , 0 ,
( ( ( T_5 ) V_69 ) << 8 ) | V_70 ,
V_197 ,
V_129 ) ;
V_46 -> V_153 . V_154 ( V_46 , V_52 -> V_171 , 0 , 0 , V_138 ) ;
} else {
F_98 ( V_46 ) ;
}
F_117 ( V_144 ) ;
F_77 ( & V_46 -> V_81 , V_54 ) ;
F_76 ( & V_52 -> V_168 , V_54 ) ;
if ( ! F_170 ( V_46 -> V_164 , V_52 -> V_57 ) ) {
V_52 -> V_169 ++ ;
if ( V_52 -> V_169 == 1 )
V_52 -> V_94 = V_46 -> V_37 ;
F_70 ( V_52 ) ;
}
F_77 ( & V_52 -> V_168 , V_54 ) ;
return 0 ;
}
static int
F_171 ( struct V_51 * V_52 , struct V_172 * V_173 ,
int V_190 )
{
int V_83 ;
struct V_172 * V_198 , * V_88 ;
V_83 = F_166 ( V_52 , F_172 ( V_173 -> V_69 ) ,
V_173 -> V_69 -> V_73 , V_173 -> V_70 ,
V_190 ) ;
if ( V_83 )
return V_83 ;
V_198 = F_173 ( V_173 ) ;
if ( ! V_198 )
return 0 ;
V_88 = V_173 -> V_69 -> V_199 ;
while ( V_88 != V_198 ) {
V_83 = F_166 ( V_52 ,
F_172 ( V_88 -> V_69 ) ,
V_88 -> V_69 -> V_73 ,
V_88 -> V_70 , V_190 ) ;
if ( V_83 )
return V_83 ;
V_88 = V_88 -> V_69 -> V_199 ;
}
if ( F_174 ( V_198 ) )
return F_166 ( V_52 ,
F_172 ( V_198 -> V_74 ) ,
V_198 -> V_74 -> V_73 , 0 ,
V_190 ) ;
else
return F_166 ( V_52 ,
F_172 ( V_198 -> V_69 ) ,
V_198 -> V_69 -> V_73 ,
V_198 -> V_70 ,
V_190 ) ;
}
static int F_175 ( struct V_172 * V_173 )
{
int V_83 ;
struct V_172 * V_198 , * V_88 ;
struct V_45 * V_46 ;
V_46 = F_71 ( F_172 ( V_173 -> V_69 ) , V_173 -> V_69 -> V_73 ,
V_173 -> V_70 ) ;
if ( ! V_46 )
return - V_180 ;
V_83 = F_80 ( V_46 , V_173 -> V_69 -> V_73 , V_173 -> V_70 ) ;
if ( ! V_83 )
return V_83 ;
V_198 = F_173 ( V_173 ) ;
if ( ! V_198 )
return V_83 ;
V_88 = V_173 -> V_69 -> V_199 ;
while ( V_88 != V_198 ) {
V_83 = F_80 ( V_46 , V_88 -> V_69 -> V_73 ,
V_88 -> V_70 ) ;
if ( ! V_83 )
return V_83 ;
V_88 = V_88 -> V_69 -> V_199 ;
}
if ( F_174 ( V_198 ) )
return F_80 ( V_46 , V_198 -> V_74 -> V_73 ,
0 ) ;
else
return F_80 ( V_46 , V_198 -> V_69 -> V_73 ,
V_198 -> V_70 ) ;
}
static inline unsigned long F_176 ( unsigned long V_200 ,
T_6 V_79 )
{
V_200 &= ~ V_201 ;
return F_177 ( V_200 + V_79 ) >> V_12 ;
}
static inline int F_178 ( struct V_51 * V_52 ,
unsigned long V_202 ,
unsigned long V_203 ,
unsigned long V_151 )
{
int V_204 , V_5 = 1 ;
unsigned long V_205 ;
V_204 = V_52 -> V_67 ;
V_205 = V_202 | V_203 ;
while ( V_204 && ! ( V_205 & ~ V_206 ) ) {
V_151 >>= V_207 ;
if ( ! V_151 )
break;
V_205 >>= V_207 ;
V_5 ++ ;
V_204 -- ;
}
return V_5 ;
}
static int F_179 ( struct V_51 * V_52 , unsigned long V_202 ,
struct V_208 * V_209 , unsigned long V_210 ,
unsigned long V_211 , int V_212 )
{
struct V_27 * V_103 = NULL , * V_28 = NULL ;
T_7 V_213 ( V_93 ) ;
int V_87 = F_2 ( V_52 -> V_1 ) - V_12 ;
unsigned long V_214 ;
unsigned int V_215 = 0 ;
unsigned long V_216 = 0 ;
F_59 ( V_87 < V_91 && ( V_202 + V_211 - 1 ) > > V_87 ) ;
if ( ( V_212 & ( V_96 | V_97 ) ) == 0 )
return - V_30 ;
V_212 &= V_96 | V_97 | V_217 ;
if ( V_209 )
V_214 = 0 ;
else {
V_214 = V_211 + 1 ;
V_93 = ( ( T_7 ) V_210 << V_12 ) | V_212 ;
}
while ( V_211 > 0 ) {
T_3 V_198 ;
if ( ! V_214 ) {
V_214 = F_176 ( V_209 -> V_89 , V_209 -> V_218 ) ;
V_209 -> V_219 = ( ( V_220 ) V_202 << V_12 ) + V_209 -> V_89 ;
V_209 -> V_221 = V_209 -> V_218 ;
V_93 = F_180 ( F_181 ( V_209 ) ) | V_212 ;
V_210 = V_93 >> V_12 ;
}
if ( ! V_28 ) {
V_215 = F_178 ( V_52 , V_202 , V_210 , V_214 ) ;
V_103 = V_28 = F_83 ( V_52 , V_202 , V_215 ) ;
if ( ! V_28 )
return - V_108 ;
if ( V_215 > 1 ) {
V_93 |= V_100 ;
F_86 ( V_52 , V_202 ,
V_202 + F_11 ( V_215 ) - 1 ) ;
F_89 ( V_52 , V_202 ,
V_202 + F_11 ( V_215 ) - 1 ) ;
} else {
V_93 &= ~ ( T_3 ) V_100 ;
}
}
V_198 = F_182 ( & V_28 -> V_19 , 0ULL , V_93 ) ;
if ( V_198 ) {
static int V_222 = 5 ;
F_39 ( V_223 L_24 ,
V_202 , V_198 , ( unsigned long long ) V_93 ) ;
if ( V_222 ) {
V_222 -- ;
F_183 ( NULL ) ;
}
F_184 ( 1 ) ;
}
V_216 = F_11 ( V_215 ) ;
F_59 ( V_211 < V_216 ) ;
F_59 ( V_214 < V_216 ) ;
V_211 -= V_216 ;
V_202 += V_216 ;
V_210 += V_216 ;
V_93 += V_216 * V_95 ;
V_214 -= V_216 ;
V_28 ++ ;
if ( ! V_211 || F_37 ( V_28 ) ||
( V_215 > 1 && V_214 < V_216 ) ) {
F_73 ( V_52 , V_103 ,
( void * ) V_28 - ( void * ) V_103 ) ;
V_28 = NULL ;
}
if ( ! V_214 && V_211 )
V_209 = F_185 ( V_209 ) ;
}
return 0 ;
}
static inline int F_186 ( struct V_51 * V_52 , unsigned long V_202 ,
struct V_208 * V_209 , unsigned long V_211 ,
int V_212 )
{
return F_179 ( V_52 , V_202 , V_209 , 0 , V_211 , V_212 ) ;
}
static inline int F_187 ( struct V_51 * V_52 , unsigned long V_202 ,
unsigned long V_210 , unsigned long V_211 ,
int V_212 )
{
return F_179 ( V_52 , V_202 , NULL , V_210 , V_211 , V_212 ) ;
}
static void F_188 ( struct V_45 * V_46 , T_2 V_69 , T_2 V_70 )
{
if ( ! V_46 )
return;
F_81 ( V_46 , V_69 , V_70 ) ;
V_46 -> V_153 . V_196 ( V_46 , 0 , 0 , 0 ,
V_127 ) ;
V_46 -> V_153 . V_154 ( V_46 , 0 , 0 , 0 , V_136 ) ;
}
static inline void F_189 ( struct V_142 * V_144 )
{
F_190 ( & V_146 ) ;
F_191 ( & V_144 -> V_224 ) ;
F_191 ( & V_144 -> V_225 ) ;
if ( V_144 -> V_147 )
V_144 -> V_147 -> V_147 . V_226 . V_46 = NULL ;
}
static void F_164 ( struct V_51 * V_52 )
{
struct V_142 * V_144 ;
unsigned long V_54 ;
struct V_45 * V_46 ;
F_76 ( & V_146 , V_54 ) ;
while ( ! F_192 ( & V_52 -> V_72 ) ) {
V_144 = F_193 ( V_52 -> V_72 . V_106 ,
struct V_142 , V_224 ) ;
F_189 ( V_144 ) ;
F_77 ( & V_146 , V_54 ) ;
F_119 ( V_144 ) ;
V_46 = F_71 ( V_144 -> V_68 , V_144 -> V_69 , V_144 -> V_70 ) ;
F_188 ( V_46 , V_144 -> V_69 , V_144 -> V_70 ) ;
F_50 ( V_144 ) ;
F_76 ( & V_146 , V_54 ) ;
}
F_77 ( & V_146 , V_54 ) ;
}
static struct V_51 *
F_194 ( struct V_172 * V_173 )
{
struct V_142 * V_144 ;
V_144 = V_173 -> V_147 . V_226 . V_46 ;
if ( V_144 )
return V_144 -> V_52 ;
return NULL ;
}
static struct V_51 * F_195 ( struct V_172 * V_173 , int V_107 )
{
struct V_51 * V_52 , * V_143 = NULL ;
struct V_45 * V_46 ;
struct V_64 * V_65 ;
struct V_142 * V_144 , * V_198 ;
struct V_172 * V_227 ;
unsigned long V_54 ;
int V_69 = 0 , V_70 = 0 ;
int V_68 ;
int V_83 ;
V_52 = F_194 ( V_173 ) ;
if ( V_52 )
return V_52 ;
V_68 = F_172 ( V_173 -> V_69 ) ;
V_227 = F_173 ( V_173 ) ;
if ( V_227 ) {
if ( F_174 ( V_227 ) ) {
V_69 = V_227 -> V_74 -> V_73 ;
V_70 = 0 ;
} else {
V_69 = V_227 -> V_69 -> V_73 ;
V_70 = V_227 -> V_70 ;
}
F_76 ( & V_146 , V_54 ) ;
F_114 (info, &device_domain_list, global) {
if ( V_144 -> V_68 == V_68 &&
V_144 -> V_69 == V_69 && V_144 -> V_70 == V_70 ) {
V_143 = V_144 -> V_52 ;
break;
}
}
F_77 ( & V_146 , V_54 ) ;
if ( V_143 ) {
V_52 = V_143 ;
goto V_228;
}
}
V_52 = F_146 () ;
if ( ! V_52 )
goto error;
V_65 = F_196 ( V_173 ) ;
if ( ! V_65 ) {
F_39 ( V_141 L_25 ,
F_197 ( V_173 ) ) ;
F_47 ( V_52 ) ;
return NULL ;
}
V_46 = V_65 -> V_46 ;
V_83 = F_147 ( V_52 , V_46 ) ;
if ( V_83 ) {
F_47 ( V_52 ) ;
goto error;
}
if ( F_159 ( V_52 , V_107 ) ) {
F_145 ( V_52 ) ;
goto error;
}
if ( V_227 ) {
V_144 = F_49 () ;
if ( ! V_144 ) {
F_145 ( V_52 ) ;
goto error;
}
V_144 -> V_68 = V_68 ;
V_144 -> V_69 = V_69 ;
V_144 -> V_70 = V_70 ;
V_144 -> V_147 = NULL ;
V_144 -> V_52 = V_52 ;
V_52 -> V_54 |= V_229 ;
V_143 = NULL ;
F_76 ( & V_146 , V_54 ) ;
F_114 (tmp, &device_domain_list, global) {
if ( V_198 -> V_68 == V_68 &&
V_198 -> V_69 == V_69 && V_198 -> V_70 == V_70 ) {
V_143 = V_198 -> V_52 ;
break;
}
}
if ( V_143 ) {
F_77 ( & V_146 , V_54 ) ;
F_50 ( V_144 ) ;
F_145 ( V_52 ) ;
V_52 = V_143 ;
} else {
F_198 ( & V_144 -> V_224 , & V_52 -> V_72 ) ;
F_198 ( & V_144 -> V_225 , & V_230 ) ;
F_77 ( & V_146 , V_54 ) ;
}
}
V_228:
V_144 = F_49 () ;
if ( ! V_144 )
goto error;
V_144 -> V_68 = V_68 ;
V_144 -> V_69 = V_173 -> V_69 -> V_73 ;
V_144 -> V_70 = V_173 -> V_70 ;
V_144 -> V_147 = V_173 ;
V_144 -> V_52 = V_52 ;
F_76 ( & V_146 , V_54 ) ;
V_143 = F_194 ( V_173 ) ;
if ( V_143 != NULL ) {
F_77 ( & V_146 , V_54 ) ;
if ( V_143 != V_52 ) {
F_145 ( V_52 ) ;
V_52 = V_143 ;
}
F_50 ( V_144 ) ;
return V_52 ;
}
F_198 ( & V_144 -> V_224 , & V_52 -> V_72 ) ;
F_198 ( & V_144 -> V_225 , & V_230 ) ;
V_173 -> V_147 . V_226 . V_46 = V_144 ;
F_77 ( & V_146 , V_54 ) ;
return V_52 ;
error:
return F_194 ( V_173 ) ;
}
static int F_199 ( struct V_51 * V_52 ,
unsigned long long V_185 ,
unsigned long long V_76 )
{
unsigned long V_231 = V_185 >> V_12 ;
unsigned long V_232 = V_76 >> V_12 ;
if ( ! F_153 ( & V_52 -> V_186 , F_12 ( V_231 ) ,
F_12 ( V_232 ) ) ) {
F_39 ( V_141 L_26 ) ;
return - V_108 ;
}
F_111 ( L_27 ,
V_185 , V_76 , V_52 -> V_171 ) ;
F_86 ( V_52 , V_231 , V_232 ) ;
return F_187 ( V_52 , V_231 , V_231 ,
V_232 - V_231 + 1 ,
V_96 | V_97 ) ;
}
static int F_200 ( struct V_172 * V_173 ,
unsigned long long V_185 ,
unsigned long long V_76 )
{
struct V_51 * V_52 ;
int V_83 ;
V_52 = F_195 ( V_173 , V_50 ) ;
if ( ! V_52 )
return - V_108 ;
if ( V_52 == V_233 && V_234 ) {
F_39 ( L_28 ,
F_197 ( V_173 ) , V_185 , V_76 ) ;
return 0 ;
}
F_39 ( V_32
L_29 ,
F_197 ( V_173 ) , V_185 , V_76 ) ;
if ( V_76 < V_185 ) {
F_201 ( 1 , L_30
L_31 ,
F_202 ( V_235 ) ,
F_202 ( V_236 ) ,
F_202 ( V_237 ) ) ;
V_83 = - V_238 ;
goto error;
}
if ( V_76 >> F_2 ( V_52 -> V_1 ) ) {
F_201 ( 1 , L_32
L_31 ,
F_2 ( V_52 -> V_1 ) ,
F_202 ( V_235 ) ,
F_202 ( V_236 ) ,
F_202 ( V_237 ) ) ;
V_83 = - V_238 ;
goto error;
}
V_83 = F_199 ( V_52 , V_185 , V_76 ) ;
if ( V_83 )
goto error;
V_83 = F_171 ( V_52 , V_173 , V_192 ) ;
if ( V_83 )
goto error;
return 0 ;
error:
F_145 ( V_52 ) ;
return V_83 ;
}
static inline int F_203 ( struct V_239 * V_240 ,
struct V_172 * V_173 )
{
if ( V_173 -> V_147 . V_226 . V_46 == V_241 )
return 0 ;
return F_200 ( V_173 , V_240 -> V_242 ,
V_240 -> V_243 ) ;
}
static inline void F_204 ( void )
{
struct V_172 * V_173 ;
int V_83 ;
V_173 = F_205 ( V_244 << 8 , NULL ) ;
if ( ! V_173 )
return;
F_39 ( V_32 L_33 ) ;
V_83 = F_200 ( V_173 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_83 )
F_39 ( V_141 L_34
L_35 ) ;
}
static inline void F_204 ( void )
{
return;
}
static int T_1 F_206 ( int V_245 )
{
struct V_64 * V_65 ;
struct V_45 * V_46 ;
int V_94 , V_83 = 0 ;
V_233 = F_146 () ;
if ( ! V_233 )
return - V_193 ;
F_67 (iommu, drhd) {
V_83 = F_147 ( V_233 , V_46 ) ;
if ( V_83 ) {
F_145 ( V_233 ) ;
return - V_193 ;
}
}
if ( F_207 ( V_233 , V_50 ) ) {
F_145 ( V_233 ) ;
return - V_193 ;
}
V_233 -> V_54 = V_56 ;
F_111 ( L_36 ,
V_233 -> V_171 ) ;
if ( V_245 )
return 0 ;
F_208 (nid) {
unsigned long V_101 , V_246 ;
int V_60 ;
F_209 (i, nid, &start_pfn, &end_pfn, NULL) {
V_83 = F_199 ( V_233 ,
F_210 ( V_101 ) , F_210 ( V_246 ) ) ;
if ( V_83 )
return V_83 ;
}
}
return 0 ;
}
static int F_211 ( struct V_172 * V_173 )
{
struct V_142 * V_144 ;
if ( F_212 ( ! V_247 ) )
return 0 ;
V_144 = V_173 -> V_147 . V_226 . V_46 ;
if ( V_144 && V_144 != V_241 )
return ( V_144 -> V_52 == V_233 ) ;
return 0 ;
}
static int F_213 ( struct V_51 * V_52 ,
struct V_172 * V_173 ,
int V_190 )
{
struct V_142 * V_144 ;
unsigned long V_54 ;
int V_83 ;
V_144 = F_49 () ;
if ( ! V_144 )
return - V_108 ;
V_144 -> V_68 = F_172 ( V_173 -> V_69 ) ;
V_144 -> V_69 = V_173 -> V_69 -> V_73 ;
V_144 -> V_70 = V_173 -> V_70 ;
V_144 -> V_147 = V_173 ;
V_144 -> V_52 = V_52 ;
F_76 ( & V_146 , V_54 ) ;
F_198 ( & V_144 -> V_224 , & V_52 -> V_72 ) ;
F_198 ( & V_144 -> V_225 , & V_230 ) ;
V_173 -> V_147 . V_226 . V_46 = V_144 ;
F_77 ( & V_146 , V_54 ) ;
V_83 = F_171 ( V_52 , V_173 , V_190 ) ;
if ( V_83 ) {
F_76 ( & V_146 , V_54 ) ;
F_189 ( V_144 ) ;
F_77 ( & V_146 , V_54 ) ;
F_50 ( V_144 ) ;
return V_83 ;
}
return 0 ;
}
static bool F_214 ( struct V_172 * V_147 )
{
struct V_239 * V_240 ;
int V_60 ;
F_215 (rmrr) {
for ( V_60 = 0 ; V_60 < V_240 -> V_71 ; V_60 ++ ) {
if ( V_240 -> V_72 [ V_60 ] == V_147 )
return true ;
}
}
return false ;
}
static int F_216 ( struct V_172 * V_173 , int V_248 )
{
if ( F_214 ( V_173 ) &&
( V_173 -> V_249 >> 8 ) != V_250 )
return 0 ;
if ( ( V_247 & V_251 ) && F_217 ( V_173 ) )
return 1 ;
if ( ( V_247 & V_252 ) && F_218 ( V_173 ) )
return 1 ;
if ( ! ( V_247 & V_253 ) )
return 0 ;
if ( ! F_174 ( V_173 ) ) {
if ( ! F_219 ( V_173 -> V_69 ) )
return 0 ;
if ( V_173 -> V_249 >> 8 == V_254 )
return 0 ;
} else if ( F_220 ( V_173 ) == V_255 )
return 0 ;
if ( ! V_248 ) {
V_25 V_256 = V_173 -> V_256 ;
if ( V_173 -> V_147 . V_257 &&
V_173 -> V_147 . V_257 < V_256 )
V_256 = V_173 -> V_147 . V_257 ;
return V_256 >= F_221 ( & V_173 -> V_147 ) ;
}
return 1 ;
}
static int T_1 F_222 ( int V_245 )
{
struct V_172 * V_173 = NULL ;
int V_83 ;
V_83 = F_206 ( V_245 ) ;
if ( V_83 )
return - V_193 ;
F_155 (pdev) {
if ( F_216 ( V_173 , 1 ) ) {
V_83 = F_213 ( V_233 , V_173 ,
V_245 ? V_191 :
V_192 ) ;
if ( V_83 ) {
if ( V_83 == - V_180 )
continue;
return V_83 ;
}
F_223 ( L_37 ,
V_245 ? L_38 : L_39 , F_197 ( V_173 ) ) ;
}
}
return 0 ;
}
static int T_1 F_224 ( void )
{
struct V_64 * V_65 ;
struct V_239 * V_240 ;
struct V_172 * V_173 ;
struct V_45 * V_46 ;
int V_60 , V_83 ;
F_225 (drhd) {
if ( V_58 < V_258 ) {
V_58 ++ ;
continue;
}
F_226 ( V_141 L_40 ,
V_258 ) ;
}
V_59 = F_138 ( V_58 , sizeof( struct V_45 * ) ,
V_166 ) ;
if ( ! V_59 ) {
F_39 ( V_141 L_41 ) ;
V_83 = - V_108 ;
goto error;
}
V_259 = F_227 ( V_58 *
sizeof( struct V_260 ) , V_166 ) ;
if ( ! V_259 ) {
V_83 = - V_108 ;
goto error;
}
F_67 (iommu, drhd) {
V_59 [ V_46 -> V_164 ] = V_46 ;
V_83 = F_134 ( V_46 ) ;
if ( V_83 )
goto error;
V_83 = F_91 ( V_46 ) ;
if ( V_83 ) {
F_39 ( V_141 L_42 ) ;
goto error;
}
if ( ! F_228 ( V_46 -> V_62 ) )
V_234 = 0 ;
}
F_67 (iommu, drhd) {
if ( V_46 -> V_145 )
continue;
F_229 ( - 1 , V_46 ) ;
F_230 ( V_46 ) ;
}
F_67 (iommu, drhd) {
if ( F_231 ( V_46 ) ) {
V_46 -> V_153 . V_196 = F_100 ;
V_46 -> V_153 . V_154 = F_105 ;
F_39 ( V_32 L_43
L_44 ,
V_46 -> V_164 ,
( unsigned long long ) V_65 -> V_261 ) ;
} else {
V_46 -> V_153 . V_196 = V_262 ;
V_46 -> V_153 . V_154 = V_263 ;
F_39 ( V_32 L_45
L_44 ,
V_46 -> V_164 ,
( unsigned long long ) V_65 -> V_261 ) ;
}
}
if ( V_264 )
V_247 |= V_253 ;
#ifdef F_232
V_247 |= V_252 ;
#endif
F_233 () ;
if ( V_247 ) {
V_83 = F_222 ( V_234 ) ;
if ( V_83 ) {
F_39 ( V_223 L_46 ) ;
goto error;
}
}
F_39 ( V_32 L_47 ) ;
F_215 (rmrr) {
for ( V_60 = 0 ; V_60 < V_240 -> V_71 ; V_60 ++ ) {
V_173 = V_240 -> V_72 [ V_60 ] ;
if ( ! V_173 )
continue;
V_83 = F_203 ( V_240 , V_173 ) ;
if ( V_83 )
F_39 ( V_141
L_48 ) ;
}
}
F_204 () ;
F_234 (iommu, drhd) {
if ( V_65 -> V_265 ) {
if ( V_266 )
F_131 ( V_46 ) ;
continue;
}
F_98 ( V_46 ) ;
V_83 = F_235 ( V_46 ) ;
if ( V_83 )
goto error;
F_92 ( V_46 ) ;
V_46 -> V_153 . V_196 ( V_46 , 0 , 0 , 0 , V_127 ) ;
V_46 -> V_153 . V_154 ( V_46 , 0 , 0 , 0 , V_136 ) ;
V_83 = F_132 ( V_46 ) ;
if ( V_83 )
goto error;
F_131 ( V_46 ) ;
}
return 0 ;
error:
F_67 (iommu, drhd)
F_142 ( V_46 ) ;
F_140 ( V_259 ) ;
F_140 ( V_59 ) ;
return V_83 ;
}
static struct V_43 * F_236 ( struct V_267 * V_147 ,
struct V_51 * V_52 ,
unsigned long V_268 , T_3 V_256 )
{
struct V_172 * V_173 = F_237 ( V_147 ) ;
struct V_43 * V_43 = NULL ;
V_256 = F_3 ( T_3 , F_238 ( V_52 -> V_107 ) , V_256 ) ;
if ( ! V_34 && V_256 > F_239 ( 32 ) ) {
V_43 = F_240 ( & V_52 -> V_186 , V_268 ,
F_154 ( F_239 ( 32 ) ) , 1 ) ;
if ( V_43 )
return V_43 ;
}
V_43 = F_240 ( & V_52 -> V_186 , V_268 , F_154 ( V_256 ) , 1 ) ;
if ( F_169 ( ! V_43 ) ) {
F_39 ( V_141 L_49 ,
V_268 , F_197 ( V_173 ) ) ;
return NULL ;
}
return V_43 ;
}
static struct V_51 * F_241 ( struct V_172 * V_173 )
{
struct V_51 * V_52 ;
int V_83 ;
V_52 = F_195 ( V_173 ,
V_50 ) ;
if ( ! V_52 ) {
F_39 ( V_141
L_50 , F_197 ( V_173 ) ) ;
return NULL ;
}
if ( F_169 ( ! F_175 ( V_173 ) ) ) {
V_83 = F_171 ( V_52 , V_173 ,
V_192 ) ;
if ( V_83 ) {
F_39 ( V_141
L_51 ,
F_197 ( V_173 ) ) ;
return NULL ;
}
}
return V_52 ;
}
static inline struct V_51 * F_242 ( struct V_172 * V_147 )
{
struct V_142 * V_144 ;
V_144 = V_147 -> V_147 . V_226 . V_46 ;
if ( F_212 ( V_144 ) )
return V_144 -> V_52 ;
return F_241 ( V_147 ) ;
}
static int F_243 ( struct V_172 * V_173 )
{
return V_173 -> V_147 . V_226 . V_46 == V_241 ;
}
static int F_244 ( struct V_267 * V_147 )
{
struct V_172 * V_173 ;
int V_143 ;
if ( F_169 ( ! F_245 ( V_147 ) ) )
return 1 ;
V_173 = F_237 ( V_147 ) ;
if ( F_243 ( V_173 ) )
return 1 ;
if ( ! V_247 )
return 0 ;
V_143 = F_211 ( V_173 ) ;
if ( V_143 ) {
if ( F_216 ( V_173 , 0 ) )
return 1 ;
else {
F_246 ( V_233 , V_173 ) ;
F_39 ( V_32 L_52 ,
F_197 ( V_173 ) ) ;
return 0 ;
}
} else {
if ( F_216 ( V_173 , 0 ) ) {
int V_83 ;
V_83 = F_213 ( V_233 , V_173 ,
V_234 ?
V_191 :
V_192 ) ;
if ( ! V_83 ) {
F_39 ( V_32 L_53 ,
F_197 ( V_173 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_220 F_247 ( struct V_267 * V_269 , T_7 V_270 ,
T_6 V_79 , int V_271 , V_25 V_256 )
{
struct V_172 * V_173 = F_237 ( V_269 ) ;
struct V_51 * V_52 ;
T_7 V_272 ;
struct V_43 * V_43 ;
int V_212 = 0 ;
int V_83 ;
struct V_45 * V_46 ;
unsigned long V_273 = V_270 >> V_11 ;
F_59 ( V_271 == V_274 ) ;
if ( F_244 ( V_269 ) )
return V_270 ;
V_52 = F_242 ( V_173 ) ;
if ( ! V_52 )
return 0 ;
V_46 = F_58 ( V_52 ) ;
V_79 = F_176 ( V_270 , V_79 ) ;
V_43 = F_236 ( V_269 , V_52 , F_12 ( V_79 ) , V_256 ) ;
if ( ! V_43 )
goto error;
if ( V_271 == V_275 || V_271 == V_276 || \
! F_248 ( V_46 -> V_49 ) )
V_212 |= V_96 ;
if ( V_271 == V_277 || V_271 == V_276 )
V_212 |= V_97 ;
V_83 = F_187 ( V_52 , F_13 ( V_43 -> V_278 ) ,
F_13 ( V_273 ) , V_79 , V_212 ) ;
if ( V_83 )
goto error;
if ( F_130 ( V_46 -> V_49 ) )
F_125 ( V_46 , V_52 -> V_171 , F_13 ( V_43 -> V_278 ) , V_79 , 1 ) ;
else
F_98 ( V_46 ) ;
V_272 = ( T_7 ) V_43 -> V_278 << V_11 ;
V_272 += V_270 & ~ V_201 ;
return V_272 ;
error:
if ( V_43 )
F_249 ( & V_52 -> V_186 , V_43 ) ;
F_39 ( V_141 L_54 ,
F_197 ( V_173 ) , V_79 , ( unsigned long long ) V_270 , V_271 ) ;
return 0 ;
}
static V_220 F_250 ( struct V_267 * V_147 , struct V_14 * V_14 ,
unsigned long V_89 , T_6 V_79 ,
enum V_279 V_271 ,
struct V_280 * V_281 )
{
return F_247 ( V_147 , F_180 ( V_14 ) + V_89 , V_79 ,
V_271 , F_237 ( V_147 ) -> V_256 ) ;
}
static void F_251 ( void )
{
int V_60 , V_282 ;
V_283 = 0 ;
for ( V_60 = 0 ; V_60 < V_58 ; V_60 ++ ) {
struct V_45 * V_46 = V_59 [ V_60 ] ;
if ( ! V_46 )
continue;
if ( ! V_259 [ V_60 ] . V_106 )
continue;
if ( ! F_130 ( V_46 -> V_49 ) )
V_46 -> V_153 . V_154 ( V_46 , 0 , 0 , 0 ,
V_136 ) ;
for ( V_282 = 0 ; V_282 < V_259 [ V_60 ] . V_106 ; V_282 ++ ) {
unsigned long V_66 ;
struct V_43 * V_43 = V_259 [ V_60 ] . V_43 [ V_282 ] ;
struct V_51 * V_52 = V_259 [ V_60 ] . V_52 [ V_282 ] ;
if ( F_130 ( V_46 -> V_49 ) )
F_125 ( V_46 , V_52 -> V_171 ,
V_43 -> V_278 , V_43 -> V_284 - V_43 -> V_278 + 1 , 0 ) ;
else {
V_66 = F_126 ( F_13 ( V_43 -> V_284 - V_43 -> V_278 + 1 ) ) ;
F_122 ( V_259 [ V_60 ] . V_52 [ V_282 ] ,
( T_3 ) V_43 -> V_278 << V_11 , V_66 ) ;
}
F_249 ( & V_259 [ V_60 ] . V_52 [ V_282 ] -> V_186 , V_43 ) ;
}
V_259 [ V_60 ] . V_106 = 0 ;
}
V_285 = 0 ;
}
static void F_163 ( unsigned long V_286 )
{
unsigned long V_54 ;
F_76 ( & V_287 , V_54 ) ;
F_251 () ;
F_77 ( & V_287 , V_54 ) ;
}
static void F_252 ( struct V_51 * V_288 , struct V_43 * V_43 )
{
unsigned long V_54 ;
int V_106 , V_53 ;
struct V_45 * V_46 ;
F_76 ( & V_287 , V_54 ) ;
if ( V_285 == V_289 )
F_251 () ;
V_46 = F_58 ( V_288 ) ;
V_53 = V_46 -> V_164 ;
V_106 = V_259 [ V_53 ] . V_106 ;
V_259 [ V_53 ] . V_52 [ V_106 ] = V_288 ;
V_259 [ V_53 ] . V_43 [ V_106 ] = V_43 ;
V_259 [ V_53 ] . V_106 ++ ;
if ( ! V_283 ) {
F_253 ( & V_290 , V_291 + F_254 ( 10 ) ) ;
V_283 = 1 ;
}
V_285 ++ ;
F_77 ( & V_287 , V_54 ) ;
}
static void F_255 ( struct V_267 * V_147 , V_220 V_292 ,
T_6 V_79 , enum V_279 V_271 ,
struct V_280 * V_281 )
{
struct V_172 * V_173 = F_237 ( V_147 ) ;
struct V_51 * V_52 ;
unsigned long V_101 , V_102 ;
struct V_43 * V_43 ;
struct V_45 * V_46 ;
if ( F_244 ( V_147 ) )
return;
V_52 = F_194 ( V_173 ) ;
F_59 ( ! V_52 ) ;
V_46 = F_58 ( V_52 ) ;
V_43 = F_256 ( & V_52 -> V_186 , F_154 ( V_292 ) ) ;
if ( F_257 ( ! V_43 , L_55 ,
( unsigned long long ) V_292 ) )
return;
V_101 = F_13 ( V_43 -> V_278 ) ;
V_102 = F_13 ( V_43 -> V_284 + 1 ) - 1 ;
F_111 ( L_56 ,
F_197 ( V_173 ) , V_101 , V_102 ) ;
F_86 ( V_52 , V_101 , V_102 ) ;
F_89 ( V_52 , V_101 , V_102 ) ;
if ( V_35 ) {
F_125 ( V_46 , V_52 -> V_171 , V_101 ,
V_102 - V_101 + 1 , 0 ) ;
F_249 ( & V_52 -> V_186 , V_43 ) ;
} else {
F_252 ( V_52 , V_43 ) ;
}
}
static void * F_258 ( struct V_267 * V_269 , T_6 V_79 ,
V_220 * V_293 , T_8 V_54 ,
struct V_280 * V_281 )
{
void * V_38 ;
int V_294 ;
V_79 = F_177 ( V_79 ) ;
V_294 = F_259 ( V_79 ) ;
if ( ! F_244 ( V_269 ) )
V_54 &= ~ ( V_295 | V_296 ) ;
else if ( V_269 -> V_257 < F_221 ( V_269 ) ) {
if ( V_269 -> V_257 < F_239 ( 32 ) )
V_54 |= V_295 ;
else
V_54 |= V_296 ;
}
V_38 = ( void * ) F_260 ( V_54 , V_294 ) ;
if ( ! V_38 )
return NULL ;
memset ( V_38 , 0 , V_79 ) ;
* V_293 = F_247 ( V_269 , F_261 ( V_38 ) , V_79 ,
V_276 ,
V_269 -> V_257 ) ;
if ( * V_293 )
return V_38 ;
F_262 ( ( unsigned long ) V_38 , V_294 ) ;
return NULL ;
}
static void F_263 ( struct V_267 * V_269 , T_6 V_79 , void * V_38 ,
V_220 V_293 , struct V_280 * V_281 )
{
int V_294 ;
V_79 = F_177 ( V_79 ) ;
V_294 = F_259 ( V_79 ) ;
F_255 ( V_269 , V_293 , V_79 , V_276 , NULL ) ;
F_262 ( ( unsigned long ) V_38 , V_294 ) ;
}
static void F_264 ( struct V_267 * V_269 , struct V_208 * V_297 ,
int V_298 , enum V_279 V_271 ,
struct V_280 * V_281 )
{
struct V_172 * V_173 = F_237 ( V_269 ) ;
struct V_51 * V_52 ;
unsigned long V_101 , V_102 ;
struct V_43 * V_43 ;
struct V_45 * V_46 ;
if ( F_244 ( V_269 ) )
return;
V_52 = F_194 ( V_173 ) ;
F_59 ( ! V_52 ) ;
V_46 = F_58 ( V_52 ) ;
V_43 = F_256 ( & V_52 -> V_186 , F_154 ( V_297 [ 0 ] . V_219 ) ) ;
if ( F_257 ( ! V_43 , L_57 ,
( unsigned long long ) V_297 [ 0 ] . V_219 ) )
return;
V_101 = F_13 ( V_43 -> V_278 ) ;
V_102 = F_13 ( V_43 -> V_284 + 1 ) - 1 ;
F_86 ( V_52 , V_101 , V_102 ) ;
F_89 ( V_52 , V_101 , V_102 ) ;
if ( V_35 ) {
F_125 ( V_46 , V_52 -> V_171 , V_101 ,
V_102 - V_101 + 1 , 0 ) ;
F_249 ( & V_52 -> V_186 , V_43 ) ;
} else {
F_252 ( V_52 , V_43 ) ;
}
}
static int F_265 ( struct V_267 * V_299 ,
struct V_208 * V_297 , int V_298 , int V_271 )
{
int V_60 ;
struct V_208 * V_209 ;
F_266 (sglist, sg, nelems, i) {
F_59 ( ! F_181 ( V_209 ) ) ;
V_209 -> V_219 = F_180 ( F_181 ( V_209 ) ) + V_209 -> V_89 ;
V_209 -> V_221 = V_209 -> V_218 ;
}
return V_298 ;
}
static int F_267 ( struct V_267 * V_269 , struct V_208 * V_297 , int V_298 ,
enum V_279 V_271 , struct V_280 * V_281 )
{
int V_60 ;
struct V_172 * V_173 = F_237 ( V_269 ) ;
struct V_51 * V_52 ;
T_6 V_79 = 0 ;
int V_212 = 0 ;
struct V_43 * V_43 = NULL ;
int V_83 ;
struct V_208 * V_209 ;
unsigned long V_300 ;
struct V_45 * V_46 ;
F_59 ( V_271 == V_274 ) ;
if ( F_244 ( V_269 ) )
return F_265 ( V_269 , V_297 , V_298 , V_271 ) ;
V_52 = F_242 ( V_173 ) ;
if ( ! V_52 )
return 0 ;
V_46 = F_58 ( V_52 ) ;
F_266 (sglist, sg, nelems, i)
V_79 += F_176 ( V_209 -> V_89 , V_209 -> V_218 ) ;
V_43 = F_236 ( V_269 , V_52 , F_12 ( V_79 ) ,
V_173 -> V_256 ) ;
if ( ! V_43 ) {
V_297 -> V_221 = 0 ;
return 0 ;
}
if ( V_271 == V_275 || V_271 == V_276 || \
! F_248 ( V_46 -> V_49 ) )
V_212 |= V_96 ;
if ( V_271 == V_277 || V_271 == V_276 )
V_212 |= V_97 ;
V_300 = F_13 ( V_43 -> V_278 ) ;
V_83 = F_186 ( V_52 , V_300 , V_297 , V_79 , V_212 ) ;
if ( F_169 ( V_83 ) ) {
F_86 ( V_52 , V_300 ,
V_300 + V_79 - 1 ) ;
F_89 ( V_52 , V_300 ,
V_300 + V_79 - 1 ) ;
F_249 ( & V_52 -> V_186 , V_43 ) ;
return 0 ;
}
if ( F_130 ( V_46 -> V_49 ) )
F_125 ( V_46 , V_52 -> V_171 , V_300 , V_79 , 1 ) ;
else
F_98 ( V_46 ) ;
return V_298 ;
}
static int F_268 ( struct V_267 * V_147 , V_220 V_301 )
{
return ! V_301 ;
}
static inline int F_269 ( void )
{
int V_83 = 0 ;
V_41 = F_270 ( L_58 ,
sizeof( struct V_51 ) ,
0 ,
V_302 ,
NULL ) ;
if ( ! V_41 ) {
F_39 ( V_141 L_59 ) ;
V_83 = - V_108 ;
}
return V_83 ;
}
static inline int F_271 ( void )
{
int V_83 = 0 ;
V_42 = F_270 ( L_60 ,
sizeof( struct V_142 ) ,
0 ,
V_302 ,
NULL ) ;
if ( ! V_42 ) {
F_39 ( V_141 L_61 ) ;
V_83 = - V_108 ;
}
return V_83 ;
}
static inline int F_272 ( void )
{
int V_83 = 0 ;
V_44 = F_270 ( L_62 ,
sizeof( struct V_43 ) ,
0 ,
V_302 ,
NULL ) ;
if ( ! V_44 ) {
F_39 ( V_141 L_63 ) ;
V_83 = - V_108 ;
}
return V_83 ;
}
static int T_1 F_273 ( void )
{
int V_83 ;
V_83 = F_272 () ;
if ( V_83 )
return V_83 ;
V_83 = F_269 () ;
if ( V_83 )
goto V_303;
V_83 = F_271 () ;
if ( ! V_83 )
return V_83 ;
F_274 ( V_41 ) ;
V_303:
F_274 ( V_44 ) ;
return - V_108 ;
}
static void T_1 F_275 ( void )
{
F_274 ( V_42 ) ;
F_274 ( V_41 ) ;
F_274 ( V_44 ) ;
}
static void F_276 ( struct V_172 * V_173 )
{
struct V_64 * V_65 ;
T_4 V_304 ;
int V_305 ;
V_305 = F_277 ( V_173 -> V_69 , F_278 ( 0 , 0 ) , 0xb0 , & V_304 ) ;
if ( V_305 ) {
F_279 ( & V_173 -> V_147 , L_64 ) ;
return;
}
V_304 &= 0xffff0000 ;
V_65 = F_196 ( V_173 ) ;
if ( F_280 ( ! V_65 || V_65 -> V_261 - V_304 != 0xa000 ,
V_306 ,
L_65 ) )
V_173 -> V_147 . V_226 . V_46 = V_241 ;
}
static void T_1 F_281 ( void )
{
struct V_64 * V_65 ;
F_225 (drhd) {
if ( ! V_65 -> V_77 ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < V_65 -> V_71 ; V_60 ++ )
if ( V_65 -> V_72 [ V_60 ] != NULL )
break;
if ( V_60 == V_65 -> V_71 )
V_65 -> V_265 = 1 ;
}
}
F_72 (drhd) {
int V_60 ;
if ( V_65 -> V_77 )
continue;
for ( V_60 = 0 ; V_60 < V_65 -> V_71 ; V_60 ++ )
if ( V_65 -> V_72 [ V_60 ] &&
! F_218 ( V_65 -> V_72 [ V_60 ] ) )
break;
if ( V_60 < V_65 -> V_71 )
continue;
if ( V_33 ) {
V_307 = 1 ;
} else {
V_65 -> V_265 = 1 ;
for ( V_60 = 0 ; V_60 < V_65 -> V_71 ; V_60 ++ ) {
if ( ! V_65 -> V_72 [ V_60 ] )
continue;
V_65 -> V_72 [ V_60 ] -> V_147 . V_226 . V_46 = V_241 ;
}
}
}
}
static int F_282 ( void )
{
struct V_64 * V_65 ;
struct V_45 * V_46 = NULL ;
F_67 (iommu, drhd)
if ( V_46 -> V_145 )
F_283 ( V_46 ) ;
F_234 (iommu, drhd) {
if ( V_65 -> V_265 ) {
if ( V_266 )
F_131 ( V_46 ) ;
continue;
}
F_98 ( V_46 ) ;
F_92 ( V_46 ) ;
V_46 -> V_153 . V_196 ( V_46 , 0 , 0 , 0 ,
V_127 ) ;
V_46 -> V_153 . V_154 ( V_46 , 0 , 0 , 0 ,
V_136 ) ;
if ( F_132 ( V_46 ) )
return 1 ;
F_131 ( V_46 ) ;
}
return 0 ;
}
static void F_284 ( void )
{
struct V_64 * V_65 ;
struct V_45 * V_46 ;
F_67 (iommu, drhd) {
V_46 -> V_153 . V_196 ( V_46 , 0 , 0 , 0 ,
V_127 ) ;
V_46 -> V_153 . V_154 ( V_46 , 0 , 0 , 0 ,
V_136 ) ;
}
}
static int F_285 ( void )
{
struct V_64 * V_65 ;
struct V_45 * V_46 = NULL ;
unsigned long V_111 ;
F_67 (iommu, drhd) {
V_46 -> V_308 = F_227 ( sizeof( T_4 ) * V_309 ,
V_39 ) ;
if ( ! V_46 -> V_308 )
goto V_310;
}
F_284 () ;
F_67 (iommu, drhd) {
F_133 ( V_46 ) ;
F_93 ( & V_46 -> V_112 , V_111 ) ;
V_46 -> V_308 [ V_311 ] =
V_119 ( V_46 -> V_113 + V_312 ) ;
V_46 -> V_308 [ V_313 ] =
V_119 ( V_46 -> V_113 + V_314 ) ;
V_46 -> V_308 [ V_315 ] =
V_119 ( V_46 -> V_113 + V_316 ) ;
V_46 -> V_308 [ V_317 ] =
V_119 ( V_46 -> V_113 + V_318 ) ;
F_97 ( & V_46 -> V_112 , V_111 ) ;
}
return 0 ;
V_310:
F_67 (iommu, drhd)
F_140 ( V_46 -> V_308 ) ;
return - V_108 ;
}
static void F_286 ( void )
{
struct V_64 * V_65 ;
struct V_45 * V_46 = NULL ;
unsigned long V_111 ;
if ( F_282 () ) {
if ( V_266 )
F_287 ( L_66 ) ;
else
F_201 ( 1 , L_67 ) ;
return;
}
F_67 (iommu, drhd) {
F_93 ( & V_46 -> V_112 , V_111 ) ;
F_95 ( V_46 -> V_308 [ V_311 ] ,
V_46 -> V_113 + V_312 ) ;
F_95 ( V_46 -> V_308 [ V_313 ] ,
V_46 -> V_113 + V_314 ) ;
F_95 ( V_46 -> V_308 [ V_315 ] ,
V_46 -> V_113 + V_316 ) ;
F_95 ( V_46 -> V_308 [ V_317 ] ,
V_46 -> V_113 + V_318 ) ;
F_97 ( & V_46 -> V_112 , V_111 ) ;
}
F_67 (iommu, drhd)
F_140 ( V_46 -> V_308 ) ;
}
static void T_1 F_288 ( void )
{
F_289 ( & V_319 ) ;
}
static inline void F_288 ( void ) {}
static void T_1 F_290 ( struct V_239 * V_240 )
{
F_198 ( & V_240 -> V_320 , & V_321 ) ;
}
int T_1 F_291 ( struct V_322 * V_323 )
{
struct V_324 * V_240 ;
struct V_239 * V_325 ;
V_325 = F_227 ( sizeof( * V_325 ) , V_166 ) ;
if ( ! V_325 )
return - V_108 ;
V_325 -> V_326 = V_323 ;
V_240 = (struct V_324 * ) V_323 ;
V_325 -> V_242 = V_240 -> V_242 ;
V_325 -> V_243 = V_240 -> V_243 ;
F_290 ( V_325 ) ;
return 0 ;
}
static int T_1
F_292 ( struct V_239 * V_325 )
{
struct V_324 * V_240 ;
V_240 = (struct V_324 * ) V_325 -> V_326 ;
return F_293 ( ( void * ) ( V_240 + 1 ) ,
( ( void * ) V_240 ) + V_240 -> V_323 . V_218 ,
& V_325 -> V_71 , & V_325 -> V_72 ,
V_240 -> V_68 ) ;
}
int T_1 F_294 ( struct V_322 * V_326 )
{
struct V_327 * V_328 ;
struct V_329 * V_330 ;
V_328 = F_295 ( V_326 , struct V_327 , V_323 ) ;
V_330 = F_227 ( sizeof( * V_330 ) , V_166 ) ;
if ( ! V_330 )
return - V_108 ;
V_330 -> V_326 = V_326 ;
V_330 -> V_77 = V_328 -> V_54 & 0x1 ;
F_198 ( & V_330 -> V_320 , & V_331 ) ;
return 0 ;
}
static int T_1 F_296 ( struct V_329 * V_330 )
{
struct V_327 * V_328 ;
if ( V_330 -> V_77 )
return 0 ;
V_328 = F_295 ( V_330 -> V_326 , struct V_327 , V_323 ) ;
return F_293 ( ( void * ) ( V_328 + 1 ) ,
( void * ) V_328 + V_328 -> V_323 . V_218 ,
& V_330 -> V_71 , & V_330 -> V_72 ,
V_328 -> V_68 ) ;
}
static void F_297 ( struct V_329 * V_330 )
{
F_298 ( & V_330 -> V_72 , & V_330 -> V_71 ) ;
F_140 ( V_330 ) ;
}
static void F_299 ( void )
{
struct V_239 * V_325 , * V_332 ;
struct V_329 * V_330 , * V_333 ;
F_300 (rmrru, rmrr_n, &dmar_rmrr_units, list) {
F_191 ( & V_325 -> V_320 ) ;
F_298 ( & V_325 -> V_72 , & V_325 -> V_71 ) ;
F_140 ( V_325 ) ;
}
F_300 (atsru, atsr_n, &dmar_atsr_units, list) {
F_191 ( & V_330 -> V_320 ) ;
F_297 ( V_330 ) ;
}
}
int F_116 ( struct V_172 * V_147 )
{
int V_60 ;
struct V_334 * V_69 ;
struct V_327 * V_328 ;
struct V_329 * V_330 ;
V_147 = F_301 ( V_147 ) ;
F_114 (atsru, &dmar_atsr_units, list) {
V_328 = F_295 ( V_330 -> V_326 , struct V_327 , V_323 ) ;
if ( V_328 -> V_68 == F_172 ( V_147 -> V_69 ) )
goto V_143;
}
return 0 ;
V_143:
for ( V_69 = V_147 -> V_69 ; V_69 ; V_69 = V_69 -> V_88 ) {
struct V_172 * V_335 = V_69 -> V_199 ;
if ( ! V_335 || ! F_174 ( V_335 ) ||
F_220 ( V_335 ) == V_255 )
return 0 ;
if ( F_220 ( V_335 ) == V_336 ) {
for ( V_60 = 0 ; V_60 < V_330 -> V_71 ; V_60 ++ )
if ( V_330 -> V_72 [ V_60 ] == V_335 )
return 1 ;
break;
}
}
if ( V_330 -> V_77 )
return 1 ;
return 0 ;
}
int T_1 F_302 ( void )
{
struct V_239 * V_240 ;
struct V_329 * V_328 ;
int V_83 = 0 ;
F_114 (rmrr, &dmar_rmrr_units, list) {
V_83 = F_292 ( V_240 ) ;
if ( V_83 )
return V_83 ;
}
F_114 (atsr, &dmar_atsr_units, list) {
V_83 = F_296 ( V_328 ) ;
if ( V_83 )
return V_83 ;
}
return V_83 ;
}
static int F_303 ( struct V_337 * V_338 ,
unsigned long V_339 , void * V_286 )
{
struct V_267 * V_147 = V_286 ;
struct V_172 * V_173 = F_237 ( V_147 ) ;
struct V_51 * V_52 ;
if ( F_244 ( V_147 ) )
return 0 ;
V_52 = F_194 ( V_173 ) ;
if ( ! V_52 )
return 0 ;
if ( V_339 == V_340 && ! V_264 ) {
F_246 ( V_52 , V_173 ) ;
if ( ! ( V_52 -> V_54 & V_55 ) &&
! ( V_52 -> V_54 & V_56 ) &&
F_192 ( & V_52 -> V_72 ) )
F_145 ( V_52 ) ;
}
return 0 ;
}
int T_1 F_304 ( void )
{
int V_83 = - V_180 ;
struct V_64 * V_65 ;
struct V_45 * V_46 ;
V_266 = F_305 () ;
if ( F_306 () ) {
if ( V_266 )
F_287 ( L_68 ) ;
goto V_341;
}
F_67 (iommu, drhd)
if ( V_46 -> V_115 & V_160 )
F_133 ( V_46 ) ;
if ( F_307 () < 0 ) {
if ( V_266 )
F_287 ( L_69 ) ;
goto V_341;
}
if ( V_342 || V_31 )
goto V_341;
if ( F_273 () ) {
if ( V_266 )
F_287 ( L_70 ) ;
goto V_341;
}
if ( F_192 ( & V_321 ) )
F_39 ( V_32 L_71 ) ;
if ( F_192 ( & V_331 ) )
F_39 ( V_32 L_72 ) ;
if ( F_150 () ) {
if ( V_266 )
F_287 ( L_73 ) ;
goto V_343;
}
F_281 () ;
V_83 = F_224 () ;
if ( V_83 ) {
if ( V_266 )
F_287 ( L_74 ) ;
F_39 ( V_141 L_75 ) ;
goto V_344;
}
F_39 ( V_32
L_76 ) ;
F_308 ( & V_290 ) ;
#ifdef F_309
V_345 = 0 ;
#endif
V_346 = & V_347 ;
F_288 () ;
F_310 ( & V_348 , & V_349 ) ;
F_311 ( & V_348 , & V_350 ) ;
V_351 = 1 ;
return 0 ;
V_344:
F_165 ( & V_174 ) ;
V_343:
F_275 () ;
V_341:
F_299 () ;
return V_83 ;
}
static void F_312 ( struct V_45 * V_46 ,
struct V_172 * V_173 )
{
struct V_172 * V_198 , * V_88 ;
if ( ! V_46 || ! V_173 )
return;
V_198 = F_173 ( V_173 ) ;
if ( V_198 ) {
V_88 = V_173 -> V_69 -> V_199 ;
while ( V_88 != V_198 ) {
F_188 ( V_46 , V_88 -> V_69 -> V_73 ,
V_88 -> V_70 ) ;
V_88 = V_88 -> V_69 -> V_199 ;
}
if ( F_174 ( V_198 ) )
F_188 ( V_46 ,
V_198 -> V_74 -> V_73 , 0 ) ;
else
F_188 ( V_46 , V_198 -> V_69 -> V_73 ,
V_198 -> V_70 ) ;
}
}
static void F_246 ( struct V_51 * V_52 ,
struct V_172 * V_173 )
{
struct V_142 * V_144 , * V_198 ;
struct V_45 * V_46 ;
unsigned long V_54 ;
int V_143 = 0 ;
V_46 = F_71 ( F_172 ( V_173 -> V_69 ) , V_173 -> V_69 -> V_73 ,
V_173 -> V_70 ) ;
if ( ! V_46 )
return;
F_76 ( & V_146 , V_54 ) ;
F_300 (info, tmp, &domain->devices, link) {
if ( V_144 -> V_68 == F_172 ( V_173 -> V_69 ) &&
V_144 -> V_69 == V_173 -> V_69 -> V_73 &&
V_144 -> V_70 == V_173 -> V_70 ) {
F_189 ( V_144 ) ;
F_77 ( & V_146 , V_54 ) ;
F_119 ( V_144 ) ;
F_188 ( V_46 , V_144 -> V_69 , V_144 -> V_70 ) ;
F_312 ( V_46 , V_173 ) ;
F_50 ( V_144 ) ;
F_76 ( & V_146 , V_54 ) ;
if ( V_143 )
break;
else
continue;
}
if ( V_46 == F_71 ( V_144 -> V_68 , V_144 -> V_69 ,
V_144 -> V_70 ) )
V_143 = 1 ;
}
F_77 ( & V_146 , V_54 ) ;
if ( V_143 == 0 ) {
unsigned long V_352 ;
F_76 ( & V_52 -> V_168 , V_352 ) ;
F_143 ( V_46 -> V_164 , V_52 -> V_57 ) ;
V_52 -> V_169 -- ;
F_70 ( V_52 ) ;
F_77 ( & V_52 -> V_168 , V_352 ) ;
if ( ! ( V_52 -> V_54 & V_55 ) &&
! ( V_52 -> V_54 & V_56 ) ) {
F_76 ( & V_46 -> V_81 , V_352 ) ;
F_143 ( V_52 -> V_171 , V_46 -> V_165 ) ;
V_46 -> V_155 [ V_52 -> V_171 ] = NULL ;
F_77 ( & V_46 -> V_81 , V_352 ) ;
}
}
}
static void F_313 ( struct V_51 * V_52 )
{
struct V_142 * V_144 ;
struct V_45 * V_46 ;
unsigned long V_353 , V_354 ;
F_76 ( & V_146 , V_353 ) ;
while ( ! F_192 ( & V_52 -> V_72 ) ) {
V_144 = F_193 ( V_52 -> V_72 . V_106 ,
struct V_142 , V_224 ) ;
F_189 ( V_144 ) ;
F_77 ( & V_146 , V_353 ) ;
F_119 ( V_144 ) ;
V_46 = F_71 ( V_144 -> V_68 , V_144 -> V_69 , V_144 -> V_70 ) ;
F_188 ( V_46 , V_144 -> V_69 , V_144 -> V_70 ) ;
F_312 ( V_46 , V_144 -> V_147 ) ;
F_76 ( & V_52 -> V_168 , V_354 ) ;
if ( F_314 ( V_46 -> V_164 ,
V_52 -> V_57 ) ) {
V_52 -> V_169 -- ;
F_70 ( V_52 ) ;
}
F_77 ( & V_52 -> V_168 , V_354 ) ;
F_50 ( V_144 ) ;
F_76 ( & V_146 , V_353 ) ;
}
F_77 ( & V_146 , V_353 ) ;
}
static struct V_51 * F_315 ( void )
{
struct V_51 * V_52 ;
V_52 = F_45 () ;
if ( ! V_52 )
return NULL ;
V_52 -> V_171 = F_316 ( & V_355 ) ;
V_52 -> V_94 = - 1 ;
memset ( V_52 -> V_57 , 0 , sizeof( V_52 -> V_57 ) ) ;
V_52 -> V_54 = V_55 ;
return V_52 ;
}
static int F_207 ( struct V_51 * V_52 , int V_187 )
{
int V_188 ;
F_151 ( & V_52 -> V_186 , V_175 ) ;
F_137 ( & V_52 -> V_168 ) ;
F_156 ( V_52 ) ;
V_52 -> V_107 = V_187 ;
V_188 = F_158 ( V_187 ) ;
V_52 -> V_1 = F_4 ( V_188 ) ;
F_162 ( & V_52 -> V_72 ) ;
V_52 -> V_169 = 0 ;
V_52 -> V_61 = 0 ;
V_52 -> V_63 = 0 ;
V_52 -> V_67 = 0 ;
V_52 -> V_356 = 0 ;
V_52 -> V_94 = - 1 ;
V_52 -> V_90 = (struct V_27 * ) F_40 ( V_52 -> V_94 ) ;
if ( ! V_52 -> V_90 )
return - V_108 ;
F_73 ( V_52 , V_52 -> V_90 , V_189 ) ;
return 0 ;
}
static void F_317 ( struct V_51 * V_52 )
{
unsigned long V_54 ;
struct V_64 * V_65 ;
struct V_45 * V_46 ;
unsigned long V_60 ;
unsigned long V_162 ;
F_67 (iommu, drhd) {
V_162 = F_135 ( V_46 -> V_49 ) ;
F_62 (i, iommu->domain_ids, ndomains) {
if ( V_46 -> V_155 [ V_60 ] == V_52 ) {
F_76 ( & V_46 -> V_81 , V_54 ) ;
F_143 ( V_60 , V_46 -> V_165 ) ;
V_46 -> V_155 [ V_60 ] = NULL ;
F_77 ( & V_46 -> V_81 , V_54 ) ;
break;
}
}
}
}
static void F_144 ( struct V_51 * V_52 )
{
if ( ! V_52 )
return;
F_313 ( V_52 ) ;
F_165 ( & V_52 -> V_186 ) ;
F_86 ( V_52 , 0 , F_90 ( V_52 -> V_107 ) ) ;
F_89 ( V_52 , 0 , F_90 ( V_52 -> V_107 ) ) ;
F_317 ( V_52 ) ;
F_47 ( V_52 ) ;
}
static int F_318 ( struct V_357 * V_52 )
{
struct V_51 * V_51 ;
V_51 = F_315 () ;
if ( ! V_51 ) {
F_39 ( V_141
L_77 ) ;
return - V_108 ;
}
if ( F_207 ( V_51 , V_50 ) ) {
F_39 ( V_141
L_78 ) ;
F_144 ( V_51 ) ;
return - V_108 ;
}
F_70 ( V_51 ) ;
V_52 -> V_358 = V_51 ;
V_52 -> V_359 . V_360 = 0 ;
V_52 -> V_359 . V_361 = F_319 ( V_51 -> V_107 ) ;
V_52 -> V_359 . V_362 = true ;
return 0 ;
}
static void F_320 ( struct V_357 * V_52 )
{
struct V_51 * V_51 = V_52 -> V_358 ;
V_52 -> V_358 = NULL ;
F_144 ( V_51 ) ;
}
static int F_321 ( struct V_357 * V_52 ,
struct V_267 * V_147 )
{
struct V_51 * V_51 = V_52 -> V_358 ;
struct V_172 * V_173 = F_237 ( V_147 ) ;
struct V_45 * V_46 ;
int V_87 ;
if ( F_169 ( F_175 ( V_173 ) ) ) {
struct V_51 * V_363 ;
V_363 = F_194 ( V_173 ) ;
if ( V_363 ) {
if ( V_51 -> V_54 & V_55 ||
V_51 -> V_54 & V_56 )
F_246 ( V_363 , V_173 ) ;
else
F_164 ( V_363 ) ;
}
}
V_46 = F_71 ( F_172 ( V_173 -> V_69 ) , V_173 -> V_69 -> V_73 ,
V_173 -> V_70 ) ;
if ( ! V_46 )
return - V_180 ;
V_87 = F_2 ( V_46 -> V_1 ) ;
if ( V_87 > F_160 ( V_46 -> V_49 ) )
V_87 = F_160 ( V_46 -> V_49 ) ;
if ( V_51 -> V_356 > ( 1LL << V_87 ) ) {
F_39 ( V_141 L_79
L_80 ,
V_364 , V_87 , V_51 -> V_356 ) ;
return - V_193 ;
}
V_51 -> V_107 = V_87 ;
while ( V_46 -> V_1 < V_51 -> V_1 ) {
struct V_27 * V_28 ;
V_28 = V_51 -> V_90 ;
if ( F_35 ( V_28 ) ) {
V_51 -> V_90 = (struct V_27 * )
F_22 ( F_32 ( V_28 ) ) ;
F_43 ( V_28 ) ;
}
V_51 -> V_1 -- ;
}
return F_213 ( V_51 , V_173 , V_192 ) ;
}
static void F_322 ( struct V_357 * V_52 ,
struct V_267 * V_147 )
{
struct V_51 * V_51 = V_52 -> V_358 ;
struct V_172 * V_173 = F_237 ( V_147 ) ;
F_246 ( V_51 , V_173 ) ;
}
static int F_323 ( struct V_357 * V_52 ,
unsigned long V_43 , T_7 V_365 ,
T_6 V_79 , int V_366 )
{
struct V_51 * V_51 = V_52 -> V_358 ;
V_25 V_356 ;
int V_212 = 0 ;
int V_83 ;
if ( V_366 & V_367 )
V_212 |= V_96 ;
if ( V_366 & V_368 )
V_212 |= V_97 ;
if ( ( V_366 & V_369 ) && V_51 -> V_63 )
V_212 |= V_217 ;
V_356 = V_43 + V_79 ;
if ( V_51 -> V_356 < V_356 ) {
V_25 V_76 ;
V_76 = F_319 ( V_51 -> V_107 ) + 1 ;
if ( V_76 < V_356 ) {
F_39 ( V_141 L_79
L_80 ,
V_364 , V_51 -> V_107 , V_356 ) ;
return - V_193 ;
}
V_51 -> V_356 = V_356 ;
}
V_79 = F_176 ( V_365 , V_79 ) ;
V_83 = F_187 ( V_51 , V_43 >> V_12 ,
V_365 >> V_12 , V_79 , V_212 ) ;
return V_83 ;
}
static T_6 F_324 ( struct V_357 * V_52 ,
unsigned long V_43 , T_6 V_79 )
{
struct V_51 * V_51 = V_52 -> V_358 ;
int V_294 ;
V_294 = F_86 ( V_51 , V_43 >> V_12 ,
( V_43 + V_79 - 1 ) >> V_12 ) ;
if ( V_51 -> V_356 == V_43 + V_79 )
V_51 -> V_356 = V_43 ;
return V_189 << V_294 ;
}
static T_7 F_325 ( struct V_357 * V_52 ,
V_220 V_43 )
{
struct V_51 * V_51 = V_52 -> V_358 ;
struct V_27 * V_28 ;
V_25 V_370 = 0 ;
V_28 = F_83 ( V_51 , V_43 >> V_12 , 0 ) ;
if ( V_28 )
V_370 = F_32 ( V_28 ) ;
return V_370 ;
}
static int F_326 ( struct V_357 * V_52 ,
unsigned long V_49 )
{
struct V_51 * V_51 = V_52 -> V_358 ;
if ( V_49 == V_371 )
return V_51 -> V_63 ;
if ( V_49 == V_372 )
return V_373 ;
return 0 ;
}
static int F_327 ( struct V_267 * V_147 )
{
struct V_172 * V_173 = F_237 ( V_147 ) ;
struct V_172 * V_335 , * V_374 = NULL ;
struct V_375 * V_376 ;
int V_83 ;
if ( ! F_71 ( F_172 ( V_173 -> V_69 ) ,
V_173 -> V_69 -> V_73 , V_173 -> V_70 ) )
return - V_180 ;
V_335 = F_173 ( V_173 ) ;
if ( V_335 ) {
if ( F_174 ( V_335 ) )
V_374 = F_328 (
F_172 ( V_173 -> V_69 ) ,
V_335 -> V_74 -> V_73 , 0 ) ;
if ( ! V_374 )
V_374 = F_329 ( V_335 ) ;
} else
V_374 = F_329 ( V_173 ) ;
F_330 ( & V_374 , F_331 ( V_374 ) ) ;
if ( V_374 -> V_377 &&
! F_332 ( V_374 , V_378 ) ) {
T_2 V_60 , V_379 = F_167 ( V_374 -> V_70 ) ;
for ( V_60 = 0 ; V_60 < 8 ; V_60 ++ ) {
struct V_172 * V_198 ;
V_198 = F_333 ( V_374 -> V_69 , F_278 ( V_379 , V_60 ) ) ;
if ( ! V_198 )
continue;
if ( ! F_332 ( V_198 , V_378 ) ) {
F_330 ( & V_374 , V_198 ) ;
break;
}
F_334 ( V_198 ) ;
}
}
while ( ! F_219 ( V_374 -> V_69 ) ) {
struct V_334 * V_69 = V_374 -> V_69 ;
while ( ! V_69 -> V_199 ) {
if ( ! F_219 ( V_69 ) )
V_69 = V_69 -> V_88 ;
else
goto V_380;
}
if ( F_335 ( V_69 -> V_199 , NULL , V_378 ) )
break;
F_330 ( & V_374 , F_329 ( V_69 -> V_199 ) ) ;
}
V_380:
V_376 = F_336 ( & V_374 -> V_147 ) ;
F_334 ( V_374 ) ;
if ( ! V_376 ) {
V_376 = F_337 () ;
if ( F_338 ( V_376 ) )
return F_339 ( V_376 ) ;
}
V_83 = F_340 ( V_376 , V_147 ) ;
F_341 ( V_376 ) ;
return V_83 ;
}
static void F_342 ( struct V_267 * V_147 )
{
F_343 ( V_147 ) ;
}
static void F_344 ( struct V_172 * V_147 )
{
F_39 ( V_32 L_81 ) ;
V_33 = 0 ;
}
static void F_345 ( struct V_172 * V_147 )
{
F_39 ( V_32 L_82 ) ;
V_121 = 1 ;
}
static void F_346 ( struct V_172 * V_147 )
{
unsigned short V_381 ;
if ( F_347 ( V_147 , V_382 , & V_381 ) )
return;
if ( ! ( V_381 & V_383 ) ) {
F_39 ( V_32 L_83 ) ;
V_33 = 0 ;
} else if ( V_33 ) {
F_39 ( V_32 L_84 ) ;
V_35 = 1 ;
}
}
static void T_1 F_233 ( void )
{
struct V_172 * V_173 ;
T_9 V_384 ;
V_173 = F_348 ( V_385 , 0x3a3e , NULL ) ;
if ( ! V_173 )
return;
F_334 ( V_173 ) ;
V_173 = F_348 ( V_385 , 0x342e , NULL ) ;
if ( ! V_173 )
return;
if ( F_349 ( V_173 , 0x188 , & V_384 ) ) {
F_334 ( V_173 ) ;
return;
}
F_334 ( V_173 ) ;
if ( V_384 & 1 )
return;
V_384 &= 0x1c ;
if ( V_384 == 0x10 )
return;
if ( ! V_384 ) {
F_201 ( 1 , L_85
L_31 ,
F_202 ( V_235 ) ,
F_202 ( V_236 ) ,
F_202 ( V_237 ) ) ;
V_247 |= V_251 ;
return;
}
F_39 ( V_386 L_86 ,
V_384 ) ;
}
