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
static inline int F_39 ( struct V_25 * V_26 )
{
return ! ( ( unsigned long ) V_26 & ~ V_19 ) ;
}
static int T_1 F_40 ( char * V_32 )
{
if ( ! V_32 )
return - V_33 ;
while ( * V_32 ) {
if ( ! strncmp ( V_32 , L_1 , 2 ) ) {
V_34 = 0 ;
F_41 ( V_35 L_2 ) ;
} else if ( ! strncmp ( V_32 , L_3 , 3 ) ) {
V_34 = 1 ;
F_41 ( V_35 L_4 ) ;
} else if ( ! strncmp ( V_32 , L_5 , 8 ) ) {
V_36 = 0 ;
F_41 ( V_35
L_6 ) ;
} else if ( ! strncmp ( V_32 , L_7 , 8 ) ) {
F_41 ( V_35
L_8 ) ;
V_37 = 1 ;
} else if ( ! strncmp ( V_32 , L_9 , 6 ) ) {
F_41 ( V_35
L_10 ) ;
V_38 = 1 ;
} else if ( ! strncmp ( V_32 , L_11 , 6 ) ) {
F_41 ( V_35
L_12 ) ;
V_39 = 0 ;
}
V_32 += strcspn ( V_32 , L_13 ) ;
while ( * V_32 == ',' )
V_32 ++ ;
}
return 0 ;
}
static inline void * F_42 ( int V_40 )
{
struct V_12 * V_12 ;
void * V_41 = NULL ;
V_12 = F_43 ( V_40 , V_42 | V_43 , 0 ) ;
if ( V_12 )
V_41 = F_44 ( V_12 ) ;
return V_41 ;
}
static inline void F_45 ( void * V_41 )
{
F_46 ( ( unsigned long ) V_41 ) ;
}
static inline void * F_47 ( void )
{
return F_48 ( V_44 , V_42 ) ;
}
static void F_49 ( void * V_41 )
{
F_50 ( V_44 , V_41 ) ;
}
static inline void * F_51 ( void )
{
return F_48 ( V_45 , V_42 ) ;
}
static inline void F_52 ( void * V_41 )
{
F_50 ( V_45 , V_41 ) ;
}
struct V_46 * F_53 ( void )
{
return F_48 ( V_47 , V_42 ) ;
}
void F_54 ( struct V_46 * V_46 )
{
F_50 ( V_47 , V_46 ) ;
}
static int F_55 ( struct V_48 * V_49 , int V_50 )
{
unsigned long V_51 ;
int V_1 = - 1 ;
V_51 = F_56 ( V_49 -> V_52 ) ;
for ( V_1 = F_3 ( V_50 ) ;
V_1 >= 0 ; V_1 -- ) {
if ( F_57 ( V_1 , & V_51 ) )
break;
}
return V_1 ;
}
int F_58 ( struct V_48 * V_49 )
{
return F_55 ( V_49 , V_53 ) ;
}
int F_59 ( struct V_48 * V_49 )
{
return F_55 ( V_49 , V_54 ) ;
}
static struct V_48 * F_60 ( struct V_55 * V_56 )
{
int V_57 ;
F_61 ( V_56 -> V_58 & V_59 ) ;
F_61 ( V_56 -> V_58 & V_60 ) ;
V_57 = F_62 ( & V_56 -> V_61 , V_62 ) ;
if ( V_57 < 0 || V_57 >= V_62 )
return NULL ;
return V_63 [ V_57 ] ;
}
static void F_63 ( struct V_55 * V_56 )
{
int V_64 ;
V_56 -> V_65 = 1 ;
F_64 (i, &domain->iommu_bmp, g_num_of_iommus) {
if ( ! F_65 ( V_63 [ V_64 ] -> V_66 ) ) {
V_56 -> V_65 = 0 ;
break;
}
}
}
static void F_66 ( struct V_55 * V_56 )
{
int V_64 ;
V_56 -> V_67 = 1 ;
F_64 (i, &domain->iommu_bmp, g_num_of_iommus) {
if ( ! F_67 ( V_63 [ V_64 ] -> V_66 ) ) {
V_56 -> V_67 = 0 ;
break;
}
}
}
static void F_68 ( struct V_55 * V_56 )
{
int V_64 , V_68 = 0xf ;
if ( ! V_39 ) {
V_56 -> V_69 = 0 ;
return;
}
V_56 -> V_69 = 4 ;
F_64 (i, &domain->iommu_bmp, g_num_of_iommus) {
V_68 |= F_69 ( V_63 [ V_64 ] -> V_52 ) ;
if ( ! V_68 ) {
break;
}
}
V_56 -> V_69 = F_70 ( V_68 ) ;
}
static void F_71 ( struct V_55 * V_56 )
{
F_63 ( V_56 ) ;
F_66 ( V_56 ) ;
F_68 ( V_56 ) ;
}
static struct V_48 * F_72 ( int V_70 , T_2 V_71 , T_2 V_72 )
{
struct V_73 * V_74 = NULL ;
int V_64 ;
F_73 (drhd) {
if ( V_74 -> V_75 )
continue;
if ( V_70 != V_74 -> V_70 )
continue;
for ( V_64 = 0 ; V_64 < V_74 -> V_76 ; V_64 ++ ) {
if ( V_74 -> V_77 [ V_64 ] &&
V_74 -> V_77 [ V_64 ] -> V_71 -> V_78 == V_71 &&
V_74 -> V_77 [ V_64 ] -> V_72 == V_72 )
return V_74 -> V_49 ;
if ( V_74 -> V_77 [ V_64 ] &&
V_74 -> V_77 [ V_64 ] -> V_79 &&
V_74 -> V_77 [ V_64 ] -> V_79 -> V_78 <= V_71 &&
V_74 -> V_77 [ V_64 ] -> V_79 -> V_79 >= V_71 )
return V_74 -> V_49 ;
}
if ( V_74 -> V_80 )
return V_74 -> V_49 ;
}
return NULL ;
}
static void F_74 ( struct V_55 * V_56 ,
void * V_81 , int V_82 )
{
if ( ! V_56 -> V_65 )
F_75 ( V_81 , V_82 ) ;
}
static struct V_20 * F_76 ( struct V_48 * V_49 ,
T_2 V_71 , T_2 V_72 )
{
struct V_15 * V_16 ;
struct V_20 * V_21 ;
unsigned long V_83 ;
unsigned long V_58 ;
F_77 ( & V_49 -> V_84 , V_58 ) ;
V_16 = & V_49 -> V_15 [ V_71 ] ;
V_21 = F_19 ( V_16 ) ;
if ( ! V_21 ) {
V_21 = (struct V_20 * )
F_42 ( V_49 -> V_40 ) ;
if ( ! V_21 ) {
F_78 ( & V_49 -> V_84 , V_58 ) ;
return NULL ;
}
F_79 ( V_49 , ( void * ) V_21 , V_85 ) ;
V_83 = F_80 ( ( void * ) V_21 ) ;
F_18 ( V_16 , V_83 ) ;
F_17 ( V_16 ) ;
F_79 ( V_49 , V_16 , sizeof( * V_16 ) ) ;
}
F_78 ( & V_49 -> V_84 , V_58 ) ;
return & V_21 [ V_72 ] ;
}
static int F_81 ( struct V_48 * V_49 , T_2 V_71 , T_2 V_72 )
{
struct V_15 * V_16 ;
struct V_20 * V_21 ;
int V_86 ;
unsigned long V_58 ;
F_77 ( & V_49 -> V_84 , V_58 ) ;
V_16 = & V_49 -> V_15 [ V_71 ] ;
V_21 = F_19 ( V_16 ) ;
if ( ! V_21 ) {
V_86 = 0 ;
goto V_87;
}
V_86 = F_21 ( & V_21 [ V_72 ] ) ;
V_87:
F_78 ( & V_49 -> V_84 , V_58 ) ;
return V_86 ;
}
static void F_82 ( struct V_48 * V_49 , T_2 V_71 , T_2 V_72 )
{
struct V_15 * V_16 ;
struct V_20 * V_21 ;
unsigned long V_58 ;
F_77 ( & V_49 -> V_84 , V_58 ) ;
V_16 = & V_49 -> V_15 [ V_71 ] ;
V_21 = F_19 ( V_16 ) ;
if ( V_21 ) {
F_28 ( & V_21 [ V_72 ] ) ;
F_79 ( V_49 , & V_21 [ V_72 ] , \
sizeof( * V_21 ) ) ;
}
F_78 ( & V_49 -> V_84 , V_58 ) ;
}
static void F_83 ( struct V_48 * V_49 )
{
struct V_15 * V_16 ;
int V_64 ;
unsigned long V_58 ;
struct V_20 * V_21 ;
F_77 ( & V_49 -> V_84 , V_58 ) ;
if ( ! V_49 -> V_15 ) {
goto V_87;
}
for ( V_64 = 0 ; V_64 < V_88 ; V_64 ++ ) {
V_16 = & V_49 -> V_15 [ V_64 ] ;
V_21 = F_19 ( V_16 ) ;
if ( V_21 )
F_45 ( V_21 ) ;
}
F_45 ( V_49 -> V_15 ) ;
V_49 -> V_15 = NULL ;
V_87:
F_78 ( & V_49 -> V_84 , V_58 ) ;
}
static struct V_25 * F_84 ( struct V_55 * V_56 ,
unsigned long V_5 , int V_89 )
{
int V_90 = F_2 ( V_56 -> V_1 ) - V_10 ;
struct V_25 * V_91 , * V_26 = NULL ;
int V_4 = F_1 ( V_56 -> V_1 ) ;
int V_92 , V_93 ;
F_61 ( ! V_56 -> V_94 ) ;
F_61 ( V_90 < V_95 && V_5 > > V_90 ) ;
V_91 = V_56 -> V_94 ;
if ( ! V_89 )
V_93 = 1 ;
else
V_93 = V_89 ;
while ( V_4 > 0 ) {
void * V_96 ;
V_92 = F_5 ( V_5 , V_4 ) ;
V_26 = & V_91 [ V_92 ] ;
if ( ! V_89 && ( V_26 -> V_17 & V_97 ) )
break;
if ( V_4 == V_93 )
break;
if ( ! F_38 ( V_26 ) ) {
V_31 V_98 ;
V_96 = F_42 ( V_56 -> V_99 ) ;
if ( ! V_96 )
return NULL ;
F_74 ( V_56 , V_96 , V_100 ) ;
V_98 = ( ( V_31 ) F_14 ( V_96 ) << V_10 ) | V_27 | V_28 ;
if ( F_85 ( & V_26 -> V_17 , 0ULL , V_98 ) ) {
F_45 ( V_96 ) ;
} else {
F_34 ( V_26 ) ;
F_74 ( V_56 , V_26 , sizeof( * V_26 ) ) ;
}
}
V_91 = F_20 ( F_34 ( V_26 ) ) ;
V_4 -- ;
}
return V_26 ;
}
static struct V_25 * F_86 ( struct V_55 * V_56 ,
unsigned long V_5 ,
int V_4 , int * V_101 )
{
struct V_25 * V_91 , * V_26 = NULL ;
int V_102 = F_1 ( V_56 -> V_1 ) ;
int V_92 ;
V_91 = V_56 -> V_94 ;
while ( V_4 <= V_102 ) {
V_92 = F_5 ( V_5 , V_102 ) ;
V_26 = & V_91 [ V_92 ] ;
if ( V_4 == V_102 )
return V_26 ;
if ( ! F_38 ( V_26 ) ) {
* V_101 = V_102 ;
break;
}
if ( V_26 -> V_17 & V_97 ) {
* V_101 = V_102 ;
return V_26 ;
}
V_91 = F_20 ( F_34 ( V_26 ) ) ;
V_102 -- ;
}
return NULL ;
}
static void F_87 ( struct V_55 * V_56 ,
unsigned long V_103 ,
unsigned long V_104 )
{
int V_90 = F_2 ( V_56 -> V_1 ) - V_10 ;
unsigned int V_101 = 1 ;
struct V_25 * V_105 , * V_26 ;
F_61 ( V_90 < V_95 && V_103 > > V_90 ) ;
F_61 ( V_90 < V_95 && V_104 > > V_90 ) ;
F_61 ( V_103 > V_104 ) ;
do {
V_101 = 1 ;
V_105 = V_26 = F_86 ( V_56 , V_103 , 1 , & V_101 ) ;
if ( ! V_26 ) {
V_103 = F_8 ( V_103 + 1 , V_101 + 1 ) ;
continue;
}
do {
F_29 ( V_26 ) ;
V_103 += F_9 ( V_101 ) ;
V_26 ++ ;
} while ( V_103 <= V_104 && ! F_39 ( V_26 ) );
F_74 ( V_56 , V_105 ,
( void * ) V_26 - ( void * ) V_105 ) ;
} while ( V_103 && V_103 <= V_104 );
}
static void F_88 ( struct V_55 * V_56 ,
unsigned long V_103 ,
unsigned long V_104 )
{
int V_90 = F_2 ( V_56 -> V_1 ) - V_10 ;
struct V_25 * V_105 , * V_26 ;
int V_102 = F_1 ( V_56 -> V_1 ) ;
int V_4 ;
unsigned long V_106 ;
int V_101 = 2 ;
F_61 ( V_90 < V_95 && V_103 > > V_90 ) ;
F_61 ( V_90 < V_95 && V_104 > > V_90 ) ;
F_61 ( V_103 > V_104 ) ;
V_4 = 2 ;
while ( V_4 <= V_102 ) {
V_106 = F_8 ( V_103 , V_4 ) ;
if ( V_106 + F_7 ( V_4 ) - 1 > V_104 )
return;
do {
V_101 = V_4 ;
V_105 = V_26 = F_86 ( V_56 , V_106 , V_4 , & V_101 ) ;
if ( V_101 > V_4 )
V_4 = V_101 + 1 ;
if ( ! V_26 ) {
V_106 = F_8 ( V_106 + 1 , V_4 + 1 ) ;
continue;
}
do {
if ( F_38 ( V_26 ) ) {
F_45 ( F_20 ( F_34 ( V_26 ) ) ) ;
F_29 ( V_26 ) ;
}
V_26 ++ ;
V_106 += F_7 ( V_4 ) ;
} while ( ! F_39 ( V_26 ) &&
V_106 + F_7 ( V_4 ) - 1 <= V_104 );
F_74 ( V_56 , V_105 ,
( void * ) V_26 - ( void * ) V_105 ) ;
} while ( V_106 && V_106 + F_7 ( V_4 ) - 1 <= V_104 );
V_4 ++ ;
}
if ( V_103 == 0 && V_104 == F_89 ( V_56 -> V_107 ) ) {
F_45 ( V_56 -> V_94 ) ;
V_56 -> V_94 = NULL ;
}
}
static int F_90 ( struct V_48 * V_49 )
{
struct V_15 * V_16 ;
unsigned long V_58 ;
V_16 = (struct V_15 * ) F_42 ( V_49 -> V_40 ) ;
if ( ! V_16 )
return - V_108 ;
F_79 ( V_49 , V_16 , V_109 ) ;
F_77 ( & V_49 -> V_84 , V_58 ) ;
V_49 -> V_15 = V_16 ;
F_78 ( & V_49 -> V_84 , V_58 ) ;
return 0 ;
}
static void F_91 ( struct V_48 * V_49 )
{
void * V_81 ;
T_3 V_110 ;
unsigned long V_111 ;
V_81 = V_49 -> V_15 ;
F_77 ( & V_49 -> V_112 , V_111 ) ;
F_92 ( V_49 -> V_113 + V_114 , F_80 ( V_81 ) ) ;
F_93 ( V_49 -> V_115 | V_116 , V_49 -> V_113 + V_117 ) ;
F_94 ( V_49 , V_118 ,
V_119 , ( V_110 & V_120 ) , V_110 ) ;
F_78 ( & V_49 -> V_112 , V_111 ) ;
}
static void F_95 ( struct V_48 * V_49 )
{
T_3 V_17 ;
unsigned long V_111 ;
if ( ! V_121 && ! F_96 ( V_49 -> V_52 ) )
return;
F_77 ( & V_49 -> V_112 , V_111 ) ;
F_93 ( V_49 -> V_115 | V_122 , V_49 -> V_113 + V_117 ) ;
F_94 ( V_49 , V_118 ,
V_119 , ( ! ( V_17 & V_123 ) ) , V_17 ) ;
F_78 ( & V_49 -> V_112 , V_111 ) ;
}
static void F_97 ( struct V_48 * V_49 ,
T_4 V_124 , T_4 V_125 , T_2 V_126 ,
V_23 type )
{
V_23 V_17 = 0 ;
unsigned long V_111 ;
switch ( type ) {
case V_127 :
V_17 = V_127 ;
break;
case V_128 :
V_17 = V_128 | F_98 ( V_124 ) ;
break;
case V_129 :
V_17 = V_129 | F_98 ( V_124 )
| F_99 ( V_125 ) | F_100 ( V_126 ) ;
break;
default:
F_101 () ;
}
V_17 |= V_130 ;
F_77 ( & V_49 -> V_112 , V_111 ) ;
F_92 ( V_49 -> V_113 + V_131 , V_17 ) ;
F_94 ( V_49 , V_131 ,
V_132 , ( ! ( V_17 & V_130 ) ) , V_17 ) ;
F_78 ( & V_49 -> V_112 , V_111 ) ;
}
static void F_102 ( struct V_48 * V_49 , T_4 V_124 ,
V_23 V_81 , unsigned int V_133 , V_23 type )
{
int V_134 = F_103 ( V_49 -> V_66 ) ;
V_23 V_17 = 0 , V_135 = 0 ;
unsigned long V_111 ;
switch ( type ) {
case V_136 :
V_17 = V_136 | V_137 ;
break;
case V_138 :
V_17 = V_138 | V_137 | F_104 ( V_124 ) ;
break;
case V_139 :
V_17 = V_139 | V_137 | F_104 ( V_124 ) ;
V_135 = V_133 | V_81 ;
break;
default:
F_101 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_105 ( V_49 -> V_52 ) )
V_17 |= V_140 ;
F_77 ( & V_49 -> V_112 , V_111 ) ;
if ( V_135 )
F_92 ( V_49 -> V_113 + V_134 , V_135 ) ;
F_92 ( V_49 -> V_113 + V_134 + 8 , V_17 ) ;
F_94 ( V_49 , V_134 + 8 ,
V_132 , ( ! ( V_17 & V_137 ) ) , V_17 ) ;
F_78 ( & V_49 -> V_112 , V_111 ) ;
if ( F_106 ( V_17 ) == 0 )
F_41 ( V_141 L_14 ) ;
if ( F_106 ( V_17 ) != F_107 ( type ) )
F_108 ( L_15 ,
( unsigned long long ) F_107 ( type ) ,
( unsigned long long ) F_106 ( V_17 ) ) ;
}
static struct V_142 * F_109 (
struct V_55 * V_56 , int V_70 , T_2 V_71 , T_2 V_72 )
{
int V_143 = 0 ;
unsigned long V_58 ;
struct V_142 * V_144 ;
struct V_48 * V_49 = F_72 ( V_70 , V_71 , V_72 ) ;
if ( ! F_110 ( V_49 -> V_66 ) )
return NULL ;
if ( ! V_49 -> V_145 )
return NULL ;
F_77 ( & V_146 , V_58 ) ;
F_111 (info, &domain->devices, link)
if ( V_144 -> V_71 == V_71 && V_144 -> V_72 == V_72 ) {
V_143 = 1 ;
break;
}
F_78 ( & V_146 , V_58 ) ;
if ( ! V_143 || ! V_144 -> V_147 )
return NULL ;
if ( ! F_112 ( V_144 -> V_147 , V_148 ) )
return NULL ;
if ( ! F_113 ( V_144 -> V_147 ) )
return NULL ;
V_144 -> V_49 = V_49 ;
return V_144 ;
}
static void F_114 ( struct V_142 * V_144 )
{
if ( ! V_144 )
return;
F_115 ( V_144 -> V_147 , V_10 ) ;
}
static void F_116 ( struct V_142 * V_144 )
{
if ( ! V_144 -> V_147 || ! F_117 ( V_144 -> V_147 ) )
return;
F_118 ( V_144 -> V_147 ) ;
}
static void F_119 ( struct V_55 * V_56 ,
V_23 V_81 , unsigned V_68 )
{
T_4 V_149 , V_150 ;
unsigned long V_58 ;
struct V_142 * V_144 ;
F_77 ( & V_146 , V_58 ) ;
F_111 (info, &domain->devices, link) {
if ( ! V_144 -> V_147 || ! F_117 ( V_144 -> V_147 ) )
continue;
V_149 = V_144 -> V_71 << 8 | V_144 -> V_72 ;
V_150 = F_120 ( V_144 -> V_147 ) ;
F_121 ( V_144 -> V_49 , V_149 , V_150 , V_81 , V_68 ) ;
}
F_78 ( & V_146 , V_58 ) ;
}
static void F_122 ( struct V_48 * V_49 , T_4 V_124 ,
unsigned long V_5 , unsigned int V_151 , int V_152 )
{
unsigned int V_68 = F_123 ( F_124 ( V_151 ) ) ;
V_31 V_81 = ( V_31 ) V_5 << V_10 ;
F_61 ( V_151 == 0 ) ;
if ( ! F_125 ( V_49 -> V_52 ) || V_68 > F_126 ( V_49 -> V_52 ) )
V_49 -> V_153 . V_154 ( V_49 , V_124 , 0 , 0 ,
V_138 ) ;
else
V_49 -> V_153 . V_154 ( V_49 , V_124 , V_81 , V_68 ,
V_139 ) ;
if ( ! F_127 ( V_49 -> V_52 ) || ! V_152 )
F_119 ( V_49 -> V_155 [ V_124 ] , V_81 , V_68 ) ;
}
static void F_128 ( struct V_48 * V_49 )
{
T_3 V_156 ;
unsigned long V_58 ;
F_77 ( & V_49 -> V_112 , V_58 ) ;
V_156 = V_119 ( V_49 -> V_113 + V_157 ) ;
V_156 &= ~ V_158 ;
F_93 ( V_156 , V_49 -> V_113 + V_157 ) ;
F_94 ( V_49 , V_157 ,
V_119 , ! ( V_156 & V_159 ) , V_156 ) ;
F_78 ( & V_49 -> V_112 , V_58 ) ;
}
static int F_129 ( struct V_48 * V_49 )
{
T_3 V_110 ;
unsigned long V_58 ;
F_77 ( & V_49 -> V_112 , V_58 ) ;
V_49 -> V_115 |= V_160 ;
F_93 ( V_49 -> V_115 , V_49 -> V_113 + V_117 ) ;
F_94 ( V_49 , V_118 ,
V_119 , ( V_110 & V_161 ) , V_110 ) ;
F_78 ( & V_49 -> V_112 , V_58 ) ;
return 0 ;
}
static int F_130 ( struct V_48 * V_49 )
{
T_3 V_110 ;
unsigned long V_111 ;
F_77 ( & V_49 -> V_112 , V_111 ) ;
V_49 -> V_115 &= ~ V_160 ;
F_93 ( V_49 -> V_115 , V_49 -> V_113 + V_117 ) ;
F_94 ( V_49 , V_118 ,
V_119 , ( ! ( V_110 & V_161 ) ) , V_110 ) ;
F_78 ( & V_49 -> V_112 , V_111 ) ;
return 0 ;
}
static int F_131 ( struct V_48 * V_49 )
{
unsigned long V_162 ;
unsigned long V_163 ;
V_162 = F_132 ( V_49 -> V_52 ) ;
F_108 ( L_16 , V_49 -> V_164 ,
V_162 ) ;
V_163 = F_133 ( V_162 ) ;
F_134 ( & V_49 -> V_84 ) ;
V_49 -> V_165 = F_135 ( V_163 , sizeof( unsigned long ) , V_166 ) ;
if ( ! V_49 -> V_165 ) {
F_41 ( V_141 L_17 ) ;
return - V_108 ;
}
V_49 -> V_155 = F_135 ( V_162 , sizeof( struct V_55 * ) ,
V_166 ) ;
if ( ! V_49 -> V_155 ) {
F_41 ( V_141 L_18 ) ;
return - V_108 ;
}
if ( F_127 ( V_49 -> V_52 ) )
F_136 ( 0 , V_49 -> V_165 ) ;
return 0 ;
}
void F_137 ( struct V_48 * V_49 )
{
struct V_55 * V_56 ;
int V_64 ;
unsigned long V_58 ;
if ( ( V_49 -> V_155 ) && ( V_49 -> V_165 ) ) {
F_64 (i, iommu->domain_ids, cap_ndoms(iommu->cap)) {
V_56 = V_49 -> V_155 [ V_64 ] ;
F_138 ( V_64 , V_49 -> V_165 ) ;
F_77 ( & V_56 -> V_167 , V_58 ) ;
if ( -- V_56 -> V_168 == 0 ) {
if ( V_56 -> V_58 & V_59 )
F_139 ( V_56 ) ;
else
F_140 ( V_56 ) ;
}
F_78 ( & V_56 -> V_167 , V_58 ) ;
}
}
if ( V_49 -> V_115 & V_160 )
F_130 ( V_49 ) ;
if ( V_49 -> V_169 ) {
F_141 ( V_49 -> V_169 , NULL ) ;
F_142 ( V_49 -> V_169 , V_49 ) ;
F_143 ( V_49 -> V_169 ) ;
}
F_144 ( V_49 -> V_155 ) ;
F_144 ( V_49 -> V_165 ) ;
V_63 [ V_49 -> V_164 ] = NULL ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
if ( V_63 [ V_64 ] )
break;
}
if ( V_64 == V_62 )
F_144 ( V_63 ) ;
F_83 ( V_49 ) ;
}
static struct V_55 * F_145 ( void )
{
struct V_55 * V_56 ;
V_56 = F_47 () ;
if ( ! V_56 )
return NULL ;
V_56 -> V_99 = - 1 ;
memset ( & V_56 -> V_61 , 0 , sizeof( unsigned long ) ) ;
V_56 -> V_58 = 0 ;
return V_56 ;
}
static int F_146 ( struct V_55 * V_56 ,
struct V_48 * V_49 )
{
int V_170 ;
unsigned long V_162 ;
unsigned long V_58 ;
V_162 = F_132 ( V_49 -> V_52 ) ;
F_77 ( & V_49 -> V_84 , V_58 ) ;
V_170 = F_147 ( V_49 -> V_165 , V_162 ) ;
if ( V_170 >= V_162 ) {
F_78 ( & V_49 -> V_84 , V_58 ) ;
F_41 ( V_141 L_19 ) ;
return - V_108 ;
}
V_56 -> V_171 = V_170 ;
F_136 ( V_170 , V_49 -> V_165 ) ;
F_136 ( V_49 -> V_164 , & V_56 -> V_61 ) ;
V_49 -> V_155 [ V_170 ] = V_56 ;
F_78 ( & V_49 -> V_84 , V_58 ) ;
return 0 ;
}
static void F_148 ( struct V_55 * V_56 ,
struct V_48 * V_49 )
{
unsigned long V_58 ;
int V_170 , V_162 ;
int V_143 = 0 ;
F_77 ( & V_49 -> V_84 , V_58 ) ;
V_162 = F_132 ( V_49 -> V_52 ) ;
F_64 (num, iommu->domain_ids, ndomains) {
if ( V_49 -> V_155 [ V_170 ] == V_56 ) {
V_143 = 1 ;
break;
}
}
if ( V_143 ) {
F_138 ( V_170 , V_49 -> V_165 ) ;
F_138 ( V_49 -> V_164 , & V_56 -> V_61 ) ;
V_49 -> V_155 [ V_170 ] = NULL ;
}
F_78 ( & V_49 -> V_84 , V_58 ) ;
}
static int F_149 ( void )
{
struct V_172 * V_173 = NULL ;
struct V_46 * V_46 ;
int V_64 ;
F_150 ( & V_174 , V_175 ) ;
F_151 ( & V_174 . V_176 ,
& V_177 ) ;
V_46 = F_152 ( & V_174 , F_153 ( V_178 ) ,
F_153 ( V_179 ) ) ;
if ( ! V_46 ) {
F_41 ( V_141 L_20 ) ;
return - V_180 ;
}
F_154 (pdev) {
struct V_181 * V_182 ;
for ( V_64 = 0 ; V_64 < V_183 ; V_64 ++ ) {
V_182 = & V_173 -> V_181 [ V_64 ] ;
if ( ! V_182 -> V_58 || ! ( V_182 -> V_58 & V_184 ) )
continue;
V_46 = F_152 ( & V_174 ,
F_153 ( V_182 -> V_185 ) ,
F_153 ( V_182 -> V_186 ) ) ;
if ( ! V_46 ) {
F_41 ( V_141 L_21 ) ;
return - V_180 ;
}
}
}
return 0 ;
}
static void F_155 ( struct V_55 * V_56 )
{
F_156 ( & V_174 , & V_56 -> V_187 ) ;
}
static inline int F_157 ( int V_107 )
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
static int F_158 ( struct V_55 * V_56 , int V_188 )
{
struct V_48 * V_49 ;
int V_189 , V_1 ;
unsigned long V_51 ;
F_150 ( & V_56 -> V_187 , V_175 ) ;
F_134 ( & V_56 -> V_167 ) ;
F_155 ( V_56 ) ;
V_49 = F_60 ( V_56 ) ;
if ( V_188 > F_159 ( V_49 -> V_52 ) )
V_188 = F_159 ( V_49 -> V_52 ) ;
V_56 -> V_107 = V_188 ;
V_189 = F_157 ( V_188 ) ;
V_1 = F_3 ( V_189 ) ;
V_51 = F_56 ( V_49 -> V_52 ) ;
if ( ! F_57 ( V_1 , & V_51 ) ) {
F_108 ( L_22 , V_1 ) ;
V_1 = F_160 ( & V_51 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_180 ;
}
V_56 -> V_1 = V_1 ;
F_161 ( & V_56 -> V_77 ) ;
if ( F_65 ( V_49 -> V_66 ) )
V_56 -> V_65 = 1 ;
else
V_56 -> V_65 = 0 ;
if ( F_67 ( V_49 -> V_66 ) )
V_56 -> V_67 = 1 ;
else
V_56 -> V_67 = 0 ;
V_56 -> V_69 = F_70 ( F_69 ( V_49 -> V_52 ) ) ;
V_56 -> V_168 = 1 ;
V_56 -> V_99 = V_49 -> V_40 ;
V_56 -> V_94 = (struct V_25 * ) F_42 ( V_56 -> V_99 ) ;
if ( ! V_56 -> V_94 )
return - V_108 ;
F_79 ( V_49 , V_56 -> V_94 , V_190 ) ;
return 0 ;
}
static void F_140 ( struct V_55 * V_56 )
{
struct V_73 * V_74 ;
struct V_48 * V_49 ;
if ( ! V_56 )
return;
if ( ! V_38 )
F_162 ( 0 ) ;
F_163 ( V_56 ) ;
F_164 ( & V_56 -> V_187 ) ;
F_87 ( V_56 , 0 , F_89 ( V_56 -> V_107 ) ) ;
F_88 ( V_56 , 0 , F_89 ( V_56 -> V_107 ) ) ;
F_165 (iommu, drhd)
if ( F_57 ( V_49 -> V_164 , & V_56 -> V_61 ) )
F_148 ( V_56 , V_49 ) ;
F_49 ( V_56 ) ;
}
static int F_166 ( struct V_55 * V_56 , int V_70 ,
T_2 V_71 , T_2 V_72 , int V_191 )
{
struct V_20 * V_21 ;
unsigned long V_58 ;
struct V_48 * V_49 ;
struct V_25 * V_94 ;
unsigned long V_170 ;
unsigned long V_162 ;
int V_171 ;
int V_1 ;
struct V_142 * V_144 = NULL ;
F_108 ( L_23 ,
V_71 , F_167 ( V_72 ) , F_168 ( V_72 ) ) ;
F_61 ( ! V_56 -> V_94 ) ;
F_61 ( V_191 != V_192 &&
V_191 != V_193 ) ;
V_49 = F_72 ( V_70 , V_71 , V_72 ) ;
if ( ! V_49 )
return - V_180 ;
V_21 = F_76 ( V_49 , V_71 , V_72 ) ;
if ( ! V_21 )
return - V_108 ;
F_77 ( & V_49 -> V_84 , V_58 ) ;
if ( F_21 ( V_21 ) ) {
F_78 ( & V_49 -> V_84 , V_58 ) ;
return 0 ;
}
V_171 = V_56 -> V_171 ;
V_94 = V_56 -> V_94 ;
if ( V_56 -> V_58 & V_59 ||
V_56 -> V_58 & V_60 ) {
int V_143 = 0 ;
V_162 = F_132 ( V_49 -> V_52 ) ;
F_64 (num, iommu->domain_ids, ndomains) {
if ( V_49 -> V_155 [ V_170 ] == V_56 ) {
V_171 = V_170 ;
V_143 = 1 ;
break;
}
}
if ( V_143 == 0 ) {
V_170 = F_147 ( V_49 -> V_165 , V_162 ) ;
if ( V_170 >= V_162 ) {
F_78 ( & V_49 -> V_84 , V_58 ) ;
F_41 ( V_141 L_19 ) ;
return - V_194 ;
}
F_136 ( V_170 , V_49 -> V_165 ) ;
V_49 -> V_155 [ V_170 ] = V_56 ;
V_171 = V_170 ;
}
if ( V_191 != V_192 ) {
for ( V_1 = V_56 -> V_1 ; V_1 != V_49 -> V_1 ; V_1 -- ) {
V_94 = F_20 ( F_34 ( V_94 ) ) ;
if ( ! F_38 ( V_94 ) ) {
F_78 ( & V_49 -> V_84 , V_58 ) ;
return - V_108 ;
}
}
}
}
F_27 ( V_21 , V_171 ) ;
if ( V_191 != V_192 ) {
V_144 = F_109 ( V_56 , V_70 , V_71 , V_72 ) ;
V_191 = V_144 ? V_195 :
V_193 ;
}
if ( F_169 ( V_191 == V_192 ) )
F_26 ( V_21 , V_49 -> V_196 ) ;
else {
F_25 ( V_21 , F_80 ( V_94 ) ) ;
F_26 ( V_21 , V_49 -> V_1 ) ;
}
F_24 ( V_21 , V_191 ) ;
F_23 ( V_21 ) ;
F_22 ( V_21 ) ;
F_74 ( V_56 , V_21 , sizeof( * V_21 ) ) ;
if ( F_127 ( V_49 -> V_52 ) ) {
V_49 -> V_153 . V_197 ( V_49 , 0 ,
( ( ( T_4 ) V_71 ) << 8 ) | V_72 ,
V_198 ,
V_129 ) ;
V_49 -> V_153 . V_154 ( V_49 , V_56 -> V_171 , 0 , 0 , V_138 ) ;
} else {
F_95 ( V_49 ) ;
}
F_114 ( V_144 ) ;
F_78 ( & V_49 -> V_84 , V_58 ) ;
F_77 ( & V_56 -> V_167 , V_58 ) ;
if ( ! F_170 ( V_49 -> V_164 , & V_56 -> V_61 ) ) {
V_56 -> V_168 ++ ;
if ( V_56 -> V_168 == 1 )
V_56 -> V_99 = V_49 -> V_40 ;
F_71 ( V_56 ) ;
}
F_78 ( & V_56 -> V_167 , V_58 ) ;
return 0 ;
}
static int
F_171 ( struct V_55 * V_56 , struct V_172 * V_173 ,
int V_191 )
{
int V_86 ;
struct V_172 * V_106 , * V_91 ;
V_86 = F_166 ( V_56 , F_172 ( V_173 -> V_71 ) ,
V_173 -> V_71 -> V_78 , V_173 -> V_72 ,
V_191 ) ;
if ( V_86 )
return V_86 ;
V_106 = F_173 ( V_173 ) ;
if ( ! V_106 )
return 0 ;
V_91 = V_173 -> V_71 -> V_199 ;
while ( V_91 != V_106 ) {
V_86 = F_166 ( V_56 ,
F_172 ( V_91 -> V_71 ) ,
V_91 -> V_71 -> V_78 ,
V_91 -> V_72 , V_191 ) ;
if ( V_86 )
return V_86 ;
V_91 = V_91 -> V_71 -> V_199 ;
}
if ( F_174 ( V_106 ) )
return F_166 ( V_56 ,
F_172 ( V_106 -> V_79 ) ,
V_106 -> V_79 -> V_78 , 0 ,
V_191 ) ;
else
return F_166 ( V_56 ,
F_172 ( V_106 -> V_71 ) ,
V_106 -> V_71 -> V_78 ,
V_106 -> V_72 ,
V_191 ) ;
}
static int F_175 ( struct V_172 * V_173 )
{
int V_86 ;
struct V_172 * V_106 , * V_91 ;
struct V_48 * V_49 ;
V_49 = F_72 ( F_172 ( V_173 -> V_71 ) , V_173 -> V_71 -> V_78 ,
V_173 -> V_72 ) ;
if ( ! V_49 )
return - V_180 ;
V_86 = F_81 ( V_49 , V_173 -> V_71 -> V_78 , V_173 -> V_72 ) ;
if ( ! V_86 )
return V_86 ;
V_106 = F_173 ( V_173 ) ;
if ( ! V_106 )
return V_86 ;
V_91 = V_173 -> V_71 -> V_199 ;
while ( V_91 != V_106 ) {
V_86 = F_81 ( V_49 , V_91 -> V_71 -> V_78 ,
V_91 -> V_72 ) ;
if ( ! V_86 )
return V_86 ;
V_91 = V_91 -> V_71 -> V_199 ;
}
if ( F_174 ( V_106 ) )
return F_81 ( V_49 , V_106 -> V_79 -> V_78 ,
0 ) ;
else
return F_81 ( V_49 , V_106 -> V_71 -> V_78 ,
V_106 -> V_72 ) ;
}
static inline unsigned long F_176 ( unsigned long V_200 ,
T_5 V_82 )
{
V_200 &= ~ V_201 ;
return F_177 ( V_200 + V_82 ) >> V_10 ;
}
static inline int F_178 ( struct V_55 * V_56 ,
unsigned long V_202 ,
unsigned long V_203 ,
unsigned long V_151 )
{
int V_204 , V_4 = 1 ;
unsigned long V_205 ;
V_204 = V_56 -> V_69 ;
V_205 = V_202 | V_203 ;
while ( V_204 && ! ( V_205 & ~ V_206 ) ) {
V_151 >>= V_207 ;
if ( ! V_151 )
break;
V_205 >>= V_207 ;
V_4 ++ ;
V_204 -- ;
}
return V_4 ;
}
static int F_179 ( struct V_55 * V_56 , unsigned long V_202 ,
struct V_208 * V_209 , unsigned long V_210 ,
unsigned long V_211 , int V_30 )
{
struct V_25 * V_105 = NULL , * V_26 = NULL ;
T_6 V_212 ( V_98 ) ;
int V_90 = F_2 ( V_56 -> V_1 ) - V_10 ;
unsigned long V_213 ;
unsigned int V_214 = 0 ;
unsigned long V_215 = 0 ;
F_61 ( V_90 < V_95 && ( V_202 + V_211 - 1 ) > > V_90 ) ;
if ( ( V_30 & ( V_27 | V_28 ) ) == 0 )
return - V_33 ;
V_30 &= V_27 | V_28 | V_29 ;
if ( V_209 )
V_213 = 0 ;
else {
V_213 = V_211 + 1 ;
V_98 = ( ( T_6 ) V_210 << V_10 ) | V_30 ;
}
while ( V_211 > 0 ) {
V_31 V_106 ;
if ( ! V_213 ) {
V_213 = F_176 ( V_209 -> V_92 , V_209 -> V_216 ) ;
V_209 -> V_217 = ( ( V_218 ) V_202 << V_10 ) + V_209 -> V_92 ;
V_209 -> V_219 = V_209 -> V_216 ;
V_98 = F_180 ( F_181 ( V_209 ) ) | V_30 ;
V_210 = V_98 >> V_10 ;
}
if ( ! V_26 ) {
V_214 = F_178 ( V_56 , V_202 , V_210 , V_213 ) ;
V_105 = V_26 = F_84 ( V_56 , V_202 , V_214 ) ;
if ( ! V_26 )
return - V_108 ;
if ( V_214 > 1 )
V_98 |= V_97 ;
else
V_98 &= ~ ( V_31 ) V_97 ;
}
V_106 = F_182 ( & V_26 -> V_17 , 0ULL , V_98 ) ;
if ( V_106 ) {
static int V_220 = 5 ;
F_41 ( V_221 L_24 ,
V_202 , V_106 , ( unsigned long long ) V_98 ) ;
if ( V_220 ) {
V_220 -- ;
F_183 ( NULL ) ;
}
F_184 ( 1 ) ;
}
V_215 = F_9 ( V_214 ) ;
F_61 ( V_211 < V_215 ) ;
F_61 ( V_213 < V_215 ) ;
V_211 -= V_215 ;
V_202 += V_215 ;
V_210 += V_215 ;
V_98 += V_215 * V_100 ;
V_213 -= V_215 ;
V_26 ++ ;
if ( ! V_211 || F_39 ( V_26 ) ||
( V_214 > 1 && V_213 < V_215 ) ) {
F_74 ( V_56 , V_105 ,
( void * ) V_26 - ( void * ) V_105 ) ;
V_26 = NULL ;
}
if ( ! V_213 && V_211 )
V_209 = F_185 ( V_209 ) ;
}
return 0 ;
}
static inline int F_186 ( struct V_55 * V_56 , unsigned long V_202 ,
struct V_208 * V_209 , unsigned long V_211 ,
int V_30 )
{
return F_179 ( V_56 , V_202 , V_209 , 0 , V_211 , V_30 ) ;
}
static inline int F_187 ( struct V_55 * V_56 , unsigned long V_202 ,
unsigned long V_210 , unsigned long V_211 ,
int V_30 )
{
return F_179 ( V_56 , V_202 , NULL , V_210 , V_211 , V_30 ) ;
}
static void F_188 ( struct V_48 * V_49 , T_2 V_71 , T_2 V_72 )
{
if ( ! V_49 )
return;
F_82 ( V_49 , V_71 , V_72 ) ;
V_49 -> V_153 . V_197 ( V_49 , 0 , 0 , 0 ,
V_127 ) ;
V_49 -> V_153 . V_154 ( V_49 , 0 , 0 , 0 , V_136 ) ;
}
static void F_163 ( struct V_55 * V_56 )
{
struct V_142 * V_144 ;
unsigned long V_58 ;
struct V_48 * V_49 ;
F_77 ( & V_146 , V_58 ) ;
while ( ! F_189 ( & V_56 -> V_77 ) ) {
V_144 = F_190 ( V_56 -> V_77 . V_222 ,
struct V_142 , V_223 ) ;
F_191 ( & V_144 -> V_223 ) ;
F_191 ( & V_144 -> V_224 ) ;
if ( V_144 -> V_147 )
V_144 -> V_147 -> V_147 . V_225 . V_49 = NULL ;
F_78 ( & V_146 , V_58 ) ;
F_116 ( V_144 ) ;
V_49 = F_72 ( V_144 -> V_70 , V_144 -> V_71 , V_144 -> V_72 ) ;
F_188 ( V_49 , V_144 -> V_71 , V_144 -> V_72 ) ;
F_52 ( V_144 ) ;
F_77 ( & V_146 , V_58 ) ;
}
F_78 ( & V_146 , V_58 ) ;
}
static struct V_55 *
F_192 ( struct V_172 * V_173 )
{
struct V_142 * V_144 ;
V_144 = V_173 -> V_147 . V_225 . V_49 ;
if ( V_144 )
return V_144 -> V_56 ;
return NULL ;
}
static struct V_55 * F_193 ( struct V_172 * V_173 , int V_107 )
{
struct V_55 * V_56 , * V_143 = NULL ;
struct V_48 * V_49 ;
struct V_73 * V_74 ;
struct V_142 * V_144 , * V_106 ;
struct V_172 * V_226 ;
unsigned long V_58 ;
int V_71 = 0 , V_72 = 0 ;
int V_70 ;
int V_86 ;
V_56 = F_192 ( V_173 ) ;
if ( V_56 )
return V_56 ;
V_70 = F_172 ( V_173 -> V_71 ) ;
V_226 = F_173 ( V_173 ) ;
if ( V_226 ) {
if ( F_174 ( V_226 ) ) {
V_71 = V_226 -> V_79 -> V_78 ;
V_72 = 0 ;
} else {
V_71 = V_226 -> V_71 -> V_78 ;
V_72 = V_226 -> V_72 ;
}
F_77 ( & V_146 , V_58 ) ;
F_111 (info, &device_domain_list, global) {
if ( V_144 -> V_70 == V_70 &&
V_144 -> V_71 == V_71 && V_144 -> V_72 == V_72 ) {
V_143 = V_144 -> V_56 ;
break;
}
}
F_78 ( & V_146 , V_58 ) ;
if ( V_143 ) {
V_56 = V_143 ;
goto V_227;
}
}
V_56 = F_145 () ;
if ( ! V_56 )
goto error;
V_74 = F_194 ( V_173 ) ;
if ( ! V_74 ) {
F_41 ( V_141 L_25 ,
F_195 ( V_173 ) ) ;
return NULL ;
}
V_49 = V_74 -> V_49 ;
V_86 = F_146 ( V_56 , V_49 ) ;
if ( V_86 ) {
F_49 ( V_56 ) ;
goto error;
}
if ( F_158 ( V_56 , V_107 ) ) {
F_140 ( V_56 ) ;
goto error;
}
if ( V_226 ) {
V_144 = F_51 () ;
if ( ! V_144 ) {
F_140 ( V_56 ) ;
goto error;
}
V_144 -> V_70 = V_70 ;
V_144 -> V_71 = V_71 ;
V_144 -> V_72 = V_72 ;
V_144 -> V_147 = NULL ;
V_144 -> V_56 = V_56 ;
V_56 -> V_58 |= V_228 ;
V_143 = NULL ;
F_77 ( & V_146 , V_58 ) ;
F_111 (tmp, &device_domain_list, global) {
if ( V_106 -> V_70 == V_70 &&
V_106 -> V_71 == V_71 && V_106 -> V_72 == V_72 ) {
V_143 = V_106 -> V_56 ;
break;
}
}
if ( V_143 ) {
F_78 ( & V_146 , V_58 ) ;
F_52 ( V_144 ) ;
F_140 ( V_56 ) ;
V_56 = V_143 ;
} else {
F_196 ( & V_144 -> V_223 , & V_56 -> V_77 ) ;
F_196 ( & V_144 -> V_224 , & V_229 ) ;
F_78 ( & V_146 , V_58 ) ;
}
}
V_227:
V_144 = F_51 () ;
if ( ! V_144 )
goto error;
V_144 -> V_70 = V_70 ;
V_144 -> V_71 = V_173 -> V_71 -> V_78 ;
V_144 -> V_72 = V_173 -> V_72 ;
V_144 -> V_147 = V_173 ;
V_144 -> V_56 = V_56 ;
F_77 ( & V_146 , V_58 ) ;
V_143 = F_192 ( V_173 ) ;
if ( V_143 != NULL ) {
F_78 ( & V_146 , V_58 ) ;
if ( V_143 != V_56 ) {
F_140 ( V_56 ) ;
V_56 = V_143 ;
}
F_52 ( V_144 ) ;
return V_56 ;
}
F_196 ( & V_144 -> V_223 , & V_56 -> V_77 ) ;
F_196 ( & V_144 -> V_224 , & V_229 ) ;
V_173 -> V_147 . V_225 . V_49 = V_144 ;
F_78 ( & V_146 , V_58 ) ;
return V_56 ;
error:
return F_192 ( V_173 ) ;
}
static int F_197 ( struct V_55 * V_56 ,
unsigned long long V_185 ,
unsigned long long V_186 )
{
unsigned long V_230 = V_185 >> V_10 ;
unsigned long V_231 = V_186 >> V_10 ;
if ( ! F_152 ( & V_56 -> V_187 , F_10 ( V_230 ) ,
F_10 ( V_231 ) ) ) {
F_41 ( V_141 L_26 ) ;
return - V_108 ;
}
F_108 ( L_27 ,
V_185 , V_186 , V_56 -> V_171 ) ;
F_87 ( V_56 , V_230 , V_231 ) ;
return F_187 ( V_56 , V_230 , V_230 ,
V_231 - V_230 + 1 ,
V_27 | V_28 ) ;
}
static int F_198 ( struct V_172 * V_173 ,
unsigned long long V_185 ,
unsigned long long V_186 )
{
struct V_55 * V_56 ;
int V_86 ;
V_56 = F_193 ( V_173 , V_54 ) ;
if ( ! V_56 )
return - V_108 ;
if ( V_56 == V_232 && V_233 ) {
F_41 ( L_28 ,
F_195 ( V_173 ) , V_185 , V_186 ) ;
return 0 ;
}
F_41 ( V_35
L_29 ,
F_195 ( V_173 ) , V_185 , V_186 ) ;
if ( V_186 < V_185 ) {
F_199 ( 1 , L_30
L_31 ,
F_200 ( V_234 ) ,
F_200 ( V_235 ) ,
F_200 ( V_236 ) ) ;
V_86 = - V_237 ;
goto error;
}
if ( V_186 >> F_2 ( V_56 -> V_1 ) ) {
F_199 ( 1 , L_32
L_31 ,
F_2 ( V_56 -> V_1 ) ,
F_200 ( V_234 ) ,
F_200 ( V_235 ) ,
F_200 ( V_236 ) ) ;
V_86 = - V_237 ;
goto error;
}
V_86 = F_197 ( V_56 , V_185 , V_186 ) ;
if ( V_86 )
goto error;
V_86 = F_171 ( V_56 , V_173 , V_193 ) ;
if ( V_86 )
goto error;
return 0 ;
error:
F_140 ( V_56 ) ;
return V_86 ;
}
static inline int F_201 ( struct V_238 * V_239 ,
struct V_172 * V_173 )
{
if ( V_173 -> V_147 . V_225 . V_49 == V_240 )
return 0 ;
return F_198 ( V_173 , V_239 -> V_241 ,
V_239 -> V_242 ) ;
}
static inline void F_202 ( void )
{
struct V_172 * V_173 ;
int V_86 ;
V_173 = F_203 ( V_243 << 8 , NULL ) ;
if ( ! V_173 )
return;
F_41 ( V_35 L_33 ) ;
V_86 = F_198 ( V_173 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_86 )
F_41 ( V_141 L_34
L_35 ) ;
}
static inline void F_202 ( void )
{
return;
}
static int T_1 F_204 ( unsigned long V_103 ,
unsigned long V_244 , void * V_245 )
{
int * V_86 = V_245 ;
* V_86 = F_197 ( V_232 ,
( V_31 ) V_103 << V_9 ,
( V_31 ) V_244 << V_9 ) ;
return * V_86 ;
}
static int T_1 F_205 ( int V_246 )
{
struct V_73 * V_74 ;
struct V_48 * V_49 ;
int V_99 , V_86 = 0 ;
V_232 = F_145 () ;
if ( ! V_232 )
return - V_194 ;
F_108 ( L_36 , V_232 -> V_171 ) ;
F_165 (iommu, drhd) {
V_86 = F_146 ( V_232 , V_49 ) ;
if ( V_86 ) {
F_140 ( V_232 ) ;
return - V_194 ;
}
}
if ( F_206 ( V_232 , V_54 ) ) {
F_140 ( V_232 ) ;
return - V_194 ;
}
V_232 -> V_58 = V_60 ;
if ( V_246 )
return 0 ;
F_207 (nid) {
F_208 ( V_99 , F_204 , & V_86 ) ;
if ( V_86 )
return V_86 ;
}
return 0 ;
}
static int F_209 ( struct V_172 * V_173 )
{
struct V_142 * V_144 ;
if ( F_210 ( ! V_247 ) )
return 0 ;
V_144 = V_173 -> V_147 . V_225 . V_49 ;
if ( V_144 && V_144 != V_240 )
return ( V_144 -> V_56 == V_232 ) ;
return 0 ;
}
static int F_211 ( struct V_55 * V_56 ,
struct V_172 * V_173 ,
int V_191 )
{
struct V_142 * V_144 ;
unsigned long V_58 ;
int V_86 ;
V_144 = F_51 () ;
if ( ! V_144 )
return - V_108 ;
V_86 = F_171 ( V_56 , V_173 , V_191 ) ;
if ( V_86 ) {
F_52 ( V_144 ) ;
return V_86 ;
}
V_144 -> V_70 = F_172 ( V_173 -> V_71 ) ;
V_144 -> V_71 = V_173 -> V_71 -> V_78 ;
V_144 -> V_72 = V_173 -> V_72 ;
V_144 -> V_147 = V_173 ;
V_144 -> V_56 = V_56 ;
F_77 ( & V_146 , V_58 ) ;
F_196 ( & V_144 -> V_223 , & V_56 -> V_77 ) ;
F_196 ( & V_144 -> V_224 , & V_229 ) ;
V_173 -> V_147 . V_225 . V_49 = V_144 ;
F_78 ( & V_146 , V_58 ) ;
return 0 ;
}
static int F_212 ( struct V_172 * V_173 , int V_248 )
{
if ( ( V_247 & V_249 ) && F_213 ( V_173 ) )
return 1 ;
if ( ( V_247 & V_250 ) && F_214 ( V_173 ) )
return 1 ;
if ( ! ( V_247 & V_251 ) )
return 0 ;
if ( ! F_174 ( V_173 ) ) {
if ( ! F_215 ( V_173 -> V_71 ) )
return 0 ;
if ( V_173 -> V_252 >> 8 == V_253 )
return 0 ;
} else if ( V_173 -> V_254 == V_255 )
return 0 ;
if ( ! V_248 ) {
V_23 V_256 = V_173 -> V_256 ;
if ( V_173 -> V_147 . V_257 &&
V_173 -> V_147 . V_257 < V_256 )
V_256 = V_173 -> V_147 . V_257 ;
return V_256 >= F_216 ( & V_173 -> V_147 ) ;
}
return 1 ;
}
static int T_1 F_217 ( int V_246 )
{
struct V_172 * V_173 = NULL ;
int V_86 ;
V_86 = F_205 ( V_246 ) ;
if ( V_86 )
return - V_194 ;
F_154 (pdev) {
if ( F_218 ( V_173 ) )
continue;
if ( F_212 ( V_173 , 1 ) ) {
F_41 ( V_35 L_37 ,
V_246 ? L_38 : L_39 , F_195 ( V_173 ) ) ;
V_86 = F_211 ( V_232 , V_173 ,
V_246 ? V_192 :
V_193 ) ;
if ( V_86 )
return V_86 ;
}
}
return 0 ;
}
static int T_1 F_219 ( void )
{
struct V_73 * V_74 ;
struct V_238 * V_239 ;
struct V_172 * V_173 ;
struct V_48 * V_49 ;
int V_64 , V_86 ;
F_73 (drhd) {
V_62 ++ ;
}
V_63 = F_135 ( V_62 , sizeof( struct V_48 * ) ,
V_166 ) ;
if ( ! V_63 ) {
F_41 ( V_141 L_40 ) ;
V_86 = - V_108 ;
goto error;
}
V_258 = F_220 ( V_62 *
sizeof( struct V_259 ) , V_166 ) ;
if ( ! V_258 ) {
V_86 = - V_108 ;
goto error;
}
F_73 (drhd) {
if ( V_74 -> V_75 )
continue;
V_49 = V_74 -> V_49 ;
V_63 [ V_49 -> V_164 ] = V_49 ;
V_86 = F_131 ( V_49 ) ;
if ( V_86 )
goto error;
V_86 = F_90 ( V_49 ) ;
if ( V_86 ) {
F_41 ( V_141 L_41 ) ;
goto error;
}
if ( ! F_221 ( V_49 -> V_66 ) )
V_233 = 0 ;
}
F_73 (drhd) {
if ( V_74 -> V_75 )
continue;
V_49 = V_74 -> V_49 ;
if ( V_49 -> V_145 )
continue;
F_222 ( - 1 , V_49 ) ;
F_223 ( V_49 ) ;
}
F_73 (drhd) {
if ( V_74 -> V_75 )
continue;
V_49 = V_74 -> V_49 ;
if ( F_224 ( V_49 ) ) {
V_49 -> V_153 . V_197 = F_97 ;
V_49 -> V_153 . V_154 = F_102 ;
F_41 ( V_35 L_42
L_43 ,
V_49 -> V_164 ,
( unsigned long long ) V_74 -> V_260 ) ;
} else {
V_49 -> V_153 . V_197 = V_261 ;
V_49 -> V_153 . V_154 = V_262 ;
F_41 ( V_35 L_44
L_43 ,
V_49 -> V_164 ,
( unsigned long long ) V_74 -> V_260 ) ;
}
}
if ( V_263 )
V_247 |= V_251 ;
#ifdef F_225
V_247 |= V_250 ;
#endif
F_226 () ;
if ( V_247 ) {
V_86 = F_217 ( V_233 ) ;
if ( V_86 ) {
F_41 ( V_221 L_45 ) ;
goto error;
}
}
F_41 ( V_35 L_46 ) ;
F_227 (rmrr) {
for ( V_64 = 0 ; V_64 < V_239 -> V_76 ; V_64 ++ ) {
V_173 = V_239 -> V_77 [ V_64 ] ;
if ( ! V_173 )
continue;
V_86 = F_201 ( V_239 , V_173 ) ;
if ( V_86 )
F_41 ( V_141
L_47 ) ;
}
}
F_202 () ;
F_73 (drhd) {
if ( V_74 -> V_75 ) {
if ( V_264 )
F_128 ( V_74 -> V_49 ) ;
continue;
}
V_49 = V_74 -> V_49 ;
F_95 ( V_49 ) ;
V_86 = F_228 ( V_49 ) ;
if ( V_86 )
goto error;
F_91 ( V_49 ) ;
V_49 -> V_153 . V_197 ( V_49 , 0 , 0 , 0 , V_127 ) ;
V_49 -> V_153 . V_154 ( V_49 , 0 , 0 , 0 , V_136 ) ;
V_86 = F_129 ( V_49 ) ;
if ( V_86 )
goto error;
F_128 ( V_49 ) ;
}
return 0 ;
error:
F_73 (drhd) {
if ( V_74 -> V_75 )
continue;
V_49 = V_74 -> V_49 ;
F_229 ( V_49 ) ;
}
F_144 ( V_63 ) ;
return V_86 ;
}
static struct V_46 * F_230 ( struct V_265 * V_147 ,
struct V_55 * V_56 ,
unsigned long V_266 , V_31 V_256 )
{
struct V_172 * V_173 = F_231 ( V_147 ) ;
struct V_46 * V_46 = NULL ;
V_256 = F_232 ( V_31 , F_233 ( V_56 -> V_107 ) , V_256 ) ;
if ( ! V_37 && V_256 > F_234 ( 32 ) ) {
V_46 = F_235 ( & V_56 -> V_187 , V_266 ,
F_153 ( F_234 ( 32 ) ) , 1 ) ;
if ( V_46 )
return V_46 ;
}
V_46 = F_235 ( & V_56 -> V_187 , V_266 , F_153 ( V_256 ) , 1 ) ;
if ( F_169 ( ! V_46 ) ) {
F_41 ( V_141 L_48 ,
V_266 , F_195 ( V_173 ) ) ;
return NULL ;
}
return V_46 ;
}
static struct V_55 * F_236 ( struct V_172 * V_173 )
{
struct V_55 * V_56 ;
int V_86 ;
V_56 = F_193 ( V_173 ,
V_54 ) ;
if ( ! V_56 ) {
F_41 ( V_141
L_49 , F_195 ( V_173 ) ) ;
return NULL ;
}
if ( F_169 ( ! F_175 ( V_173 ) ) ) {
V_86 = F_171 ( V_56 , V_173 ,
V_193 ) ;
if ( V_86 ) {
F_41 ( V_141
L_50 ,
F_195 ( V_173 ) ) ;
return NULL ;
}
}
return V_56 ;
}
static inline struct V_55 * F_237 ( struct V_172 * V_147 )
{
struct V_142 * V_144 ;
V_144 = V_147 -> V_147 . V_225 . V_49 ;
if ( F_210 ( V_144 ) )
return V_144 -> V_56 ;
return F_236 ( V_147 ) ;
}
static int F_238 ( struct V_172 * V_173 )
{
return V_173 -> V_147 . V_225 . V_49 == V_240 ;
}
static int F_239 ( struct V_265 * V_147 )
{
struct V_172 * V_173 ;
int V_143 ;
if ( F_169 ( V_147 -> V_71 != & V_267 ) )
return 1 ;
V_173 = F_231 ( V_147 ) ;
if ( F_238 ( V_173 ) )
return 1 ;
if ( ! V_247 )
return 0 ;
V_143 = F_209 ( V_173 ) ;
if ( V_143 ) {
if ( F_212 ( V_173 , 0 ) )
return 1 ;
else {
F_240 ( V_232 , V_173 ) ;
F_41 ( V_35 L_51 ,
F_195 ( V_173 ) ) ;
return 0 ;
}
} else {
if ( F_212 ( V_173 , 0 ) ) {
int V_86 ;
V_86 = F_211 ( V_232 , V_173 ,
V_233 ?
V_192 :
V_193 ) ;
if ( ! V_86 ) {
F_41 ( V_35 L_52 ,
F_195 ( V_173 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_218 F_241 ( struct V_265 * V_268 , T_6 V_269 ,
T_5 V_82 , int V_270 , V_23 V_256 )
{
struct V_172 * V_173 = F_231 ( V_268 ) ;
struct V_55 * V_56 ;
T_6 V_271 ;
struct V_46 * V_46 ;
int V_30 = 0 ;
int V_86 ;
struct V_48 * V_49 ;
unsigned long V_272 = V_269 >> V_9 ;
F_61 ( V_270 == V_273 ) ;
if ( F_239 ( V_268 ) )
return V_269 ;
V_56 = F_237 ( V_173 ) ;
if ( ! V_56 )
return 0 ;
V_49 = F_60 ( V_56 ) ;
V_82 = F_176 ( V_269 , V_82 ) ;
V_46 = F_230 ( V_268 , V_56 , F_10 ( V_82 ) , V_256 ) ;
if ( ! V_46 )
goto error;
if ( V_270 == V_274 || V_270 == V_275 || \
! F_242 ( V_49 -> V_52 ) )
V_30 |= V_27 ;
if ( V_270 == V_276 || V_270 == V_275 )
V_30 |= V_28 ;
V_86 = F_187 ( V_56 , F_11 ( V_46 -> V_277 ) ,
F_11 ( V_272 ) , V_82 , V_30 ) ;
if ( V_86 )
goto error;
if ( F_127 ( V_49 -> V_52 ) )
F_122 ( V_49 , V_56 -> V_171 , F_11 ( V_46 -> V_277 ) , V_82 , 1 ) ;
else
F_95 ( V_49 ) ;
V_271 = ( T_6 ) V_46 -> V_277 << V_9 ;
V_271 += V_269 & ~ V_201 ;
return V_271 ;
error:
if ( V_46 )
F_243 ( & V_56 -> V_187 , V_46 ) ;
F_41 ( V_141 L_53 ,
F_195 ( V_173 ) , V_82 , ( unsigned long long ) V_269 , V_270 ) ;
return 0 ;
}
static V_218 F_244 ( struct V_265 * V_147 , struct V_12 * V_12 ,
unsigned long V_92 , T_5 V_82 ,
enum V_278 V_270 ,
struct V_279 * V_280 )
{
return F_241 ( V_147 , F_180 ( V_12 ) + V_92 , V_82 ,
V_270 , F_231 ( V_147 ) -> V_256 ) ;
}
static void F_245 ( void )
{
int V_64 , V_281 ;
V_282 = 0 ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
struct V_48 * V_49 = V_63 [ V_64 ] ;
if ( ! V_49 )
continue;
if ( ! V_258 [ V_64 ] . V_222 )
continue;
if ( ! F_127 ( V_49 -> V_52 ) )
V_49 -> V_153 . V_154 ( V_49 , 0 , 0 , 0 ,
V_136 ) ;
for ( V_281 = 0 ; V_281 < V_258 [ V_64 ] . V_222 ; V_281 ++ ) {
unsigned long V_68 ;
struct V_46 * V_46 = V_258 [ V_64 ] . V_46 [ V_281 ] ;
struct V_55 * V_56 = V_258 [ V_64 ] . V_56 [ V_281 ] ;
if ( F_127 ( V_49 -> V_52 ) )
F_122 ( V_49 , V_56 -> V_171 ,
V_46 -> V_277 , V_46 -> V_283 - V_46 -> V_277 + 1 , 0 ) ;
else {
V_68 = F_123 ( F_11 ( V_46 -> V_283 - V_46 -> V_277 + 1 ) ) ;
F_119 ( V_258 [ V_64 ] . V_56 [ V_281 ] ,
( V_31 ) V_46 -> V_277 << V_9 , V_68 ) ;
}
F_243 ( & V_258 [ V_64 ] . V_56 [ V_281 ] -> V_187 , V_46 ) ;
}
V_258 [ V_64 ] . V_222 = 0 ;
}
V_284 = 0 ;
}
static void F_162 ( unsigned long V_285 )
{
unsigned long V_58 ;
F_77 ( & V_286 , V_58 ) ;
F_245 () ;
F_78 ( & V_286 , V_58 ) ;
}
static void F_246 ( struct V_55 * V_287 , struct V_46 * V_46 )
{
unsigned long V_58 ;
int V_222 , V_57 ;
struct V_48 * V_49 ;
F_77 ( & V_286 , V_58 ) ;
if ( V_284 == V_288 )
F_245 () ;
V_49 = F_60 ( V_287 ) ;
V_57 = V_49 -> V_164 ;
V_222 = V_258 [ V_57 ] . V_222 ;
V_258 [ V_57 ] . V_56 [ V_222 ] = V_287 ;
V_258 [ V_57 ] . V_46 [ V_222 ] = V_46 ;
V_258 [ V_57 ] . V_222 ++ ;
if ( ! V_282 ) {
F_247 ( & V_289 , V_290 + F_248 ( 10 ) ) ;
V_282 = 1 ;
}
V_284 ++ ;
F_78 ( & V_286 , V_58 ) ;
}
static void F_249 ( struct V_265 * V_147 , V_218 V_291 ,
T_5 V_82 , enum V_278 V_270 ,
struct V_279 * V_280 )
{
struct V_172 * V_173 = F_231 ( V_147 ) ;
struct V_55 * V_56 ;
unsigned long V_103 , V_104 ;
struct V_46 * V_46 ;
struct V_48 * V_49 ;
if ( F_239 ( V_147 ) )
return;
V_56 = F_192 ( V_173 ) ;
F_61 ( ! V_56 ) ;
V_49 = F_60 ( V_56 ) ;
V_46 = F_250 ( & V_56 -> V_187 , F_153 ( V_291 ) ) ;
if ( F_251 ( ! V_46 , L_54 ,
( unsigned long long ) V_291 ) )
return;
V_103 = F_11 ( V_46 -> V_277 ) ;
V_104 = F_11 ( V_46 -> V_283 + 1 ) - 1 ;
F_108 ( L_55 ,
F_195 ( V_173 ) , V_103 , V_104 ) ;
F_87 ( V_56 , V_103 , V_104 ) ;
F_88 ( V_56 , V_103 , V_104 ) ;
if ( V_38 ) {
F_122 ( V_49 , V_56 -> V_171 , V_103 ,
V_104 - V_103 + 1 , 0 ) ;
F_243 ( & V_56 -> V_187 , V_46 ) ;
} else {
F_246 ( V_56 , V_46 ) ;
}
}
static void * F_252 ( struct V_265 * V_268 , T_5 V_82 ,
V_218 * V_292 , T_7 V_58 )
{
void * V_41 ;
int V_293 ;
V_82 = F_177 ( V_82 ) ;
V_293 = F_253 ( V_82 ) ;
if ( ! F_239 ( V_268 ) )
V_58 &= ~ ( V_294 | V_295 ) ;
else if ( V_268 -> V_257 < F_216 ( V_268 ) ) {
if ( V_268 -> V_257 < F_234 ( 32 ) )
V_58 |= V_294 ;
else
V_58 |= V_295 ;
}
V_41 = ( void * ) F_254 ( V_58 , V_293 ) ;
if ( ! V_41 )
return NULL ;
memset ( V_41 , 0 , V_82 ) ;
* V_292 = F_241 ( V_268 , F_255 ( V_41 ) , V_82 ,
V_275 ,
V_268 -> V_257 ) ;
if ( * V_292 )
return V_41 ;
F_256 ( ( unsigned long ) V_41 , V_293 ) ;
return NULL ;
}
static void F_257 ( struct V_265 * V_268 , T_5 V_82 , void * V_41 ,
V_218 V_292 )
{
int V_293 ;
V_82 = F_177 ( V_82 ) ;
V_293 = F_253 ( V_82 ) ;
F_249 ( V_268 , V_292 , V_82 , V_275 , NULL ) ;
F_256 ( ( unsigned long ) V_41 , V_293 ) ;
}
static void F_258 ( struct V_265 * V_268 , struct V_208 * V_296 ,
int V_297 , enum V_278 V_270 ,
struct V_279 * V_280 )
{
struct V_172 * V_173 = F_231 ( V_268 ) ;
struct V_55 * V_56 ;
unsigned long V_103 , V_104 ;
struct V_46 * V_46 ;
struct V_48 * V_49 ;
if ( F_239 ( V_268 ) )
return;
V_56 = F_192 ( V_173 ) ;
F_61 ( ! V_56 ) ;
V_49 = F_60 ( V_56 ) ;
V_46 = F_250 ( & V_56 -> V_187 , F_153 ( V_296 [ 0 ] . V_217 ) ) ;
if ( F_251 ( ! V_46 , L_56 ,
( unsigned long long ) V_296 [ 0 ] . V_217 ) )
return;
V_103 = F_11 ( V_46 -> V_277 ) ;
V_104 = F_11 ( V_46 -> V_283 + 1 ) - 1 ;
F_87 ( V_56 , V_103 , V_104 ) ;
F_88 ( V_56 , V_103 , V_104 ) ;
if ( V_38 ) {
F_122 ( V_49 , V_56 -> V_171 , V_103 ,
V_104 - V_103 + 1 , 0 ) ;
F_243 ( & V_56 -> V_187 , V_46 ) ;
} else {
F_246 ( V_56 , V_46 ) ;
}
}
static int F_259 ( struct V_265 * V_298 ,
struct V_208 * V_296 , int V_297 , int V_270 )
{
int V_64 ;
struct V_208 * V_209 ;
F_260 (sglist, sg, nelems, i) {
F_61 ( ! F_181 ( V_209 ) ) ;
V_209 -> V_217 = F_180 ( F_181 ( V_209 ) ) + V_209 -> V_92 ;
V_209 -> V_219 = V_209 -> V_216 ;
}
return V_297 ;
}
static int F_261 ( struct V_265 * V_268 , struct V_208 * V_296 , int V_297 ,
enum V_278 V_270 , struct V_279 * V_280 )
{
int V_64 ;
struct V_172 * V_173 = F_231 ( V_268 ) ;
struct V_55 * V_56 ;
T_5 V_82 = 0 ;
int V_30 = 0 ;
struct V_46 * V_46 = NULL ;
int V_86 ;
struct V_208 * V_209 ;
unsigned long V_299 ;
struct V_48 * V_49 ;
F_61 ( V_270 == V_273 ) ;
if ( F_239 ( V_268 ) )
return F_259 ( V_268 , V_296 , V_297 , V_270 ) ;
V_56 = F_237 ( V_173 ) ;
if ( ! V_56 )
return 0 ;
V_49 = F_60 ( V_56 ) ;
F_260 (sglist, sg, nelems, i)
V_82 += F_176 ( V_209 -> V_92 , V_209 -> V_216 ) ;
V_46 = F_230 ( V_268 , V_56 , F_10 ( V_82 ) ,
V_173 -> V_256 ) ;
if ( ! V_46 ) {
V_296 -> V_219 = 0 ;
return 0 ;
}
if ( V_270 == V_274 || V_270 == V_275 || \
! F_242 ( V_49 -> V_52 ) )
V_30 |= V_27 ;
if ( V_270 == V_276 || V_270 == V_275 )
V_30 |= V_28 ;
V_299 = F_11 ( V_46 -> V_277 ) ;
V_86 = F_186 ( V_56 , V_299 , V_296 , V_82 , V_30 ) ;
if ( F_169 ( V_86 ) ) {
F_87 ( V_56 , V_299 ,
V_299 + V_82 - 1 ) ;
F_88 ( V_56 , V_299 ,
V_299 + V_82 - 1 ) ;
F_243 ( & V_56 -> V_187 , V_46 ) ;
return 0 ;
}
if ( F_127 ( V_49 -> V_52 ) )
F_122 ( V_49 , V_56 -> V_171 , V_299 , V_82 , 1 ) ;
else
F_95 ( V_49 ) ;
return V_297 ;
}
static int F_262 ( struct V_265 * V_147 , V_218 V_300 )
{
return ! V_300 ;
}
static inline int F_263 ( void )
{
int V_86 = 0 ;
V_44 = F_264 ( L_57 ,
sizeof( struct V_55 ) ,
0 ,
V_301 ,
NULL ) ;
if ( ! V_44 ) {
F_41 ( V_141 L_58 ) ;
V_86 = - V_108 ;
}
return V_86 ;
}
static inline int F_265 ( void )
{
int V_86 = 0 ;
V_45 = F_264 ( L_59 ,
sizeof( struct V_142 ) ,
0 ,
V_301 ,
NULL ) ;
if ( ! V_45 ) {
F_41 ( V_141 L_60 ) ;
V_86 = - V_108 ;
}
return V_86 ;
}
static inline int F_266 ( void )
{
int V_86 = 0 ;
V_47 = F_264 ( L_61 ,
sizeof( struct V_46 ) ,
0 ,
V_301 ,
NULL ) ;
if ( ! V_47 ) {
F_41 ( V_141 L_62 ) ;
V_86 = - V_108 ;
}
return V_86 ;
}
static int T_1 F_267 ( void )
{
int V_86 ;
V_86 = F_266 () ;
if ( V_86 )
return V_86 ;
V_86 = F_263 () ;
if ( V_86 )
goto V_302;
V_86 = F_265 () ;
if ( ! V_86 )
return V_86 ;
F_268 ( V_44 ) ;
V_302:
F_268 ( V_47 ) ;
return - V_108 ;
}
static void T_1 F_269 ( void )
{
F_268 ( V_45 ) ;
F_268 ( V_44 ) ;
F_268 ( V_47 ) ;
}
static void F_270 ( struct V_172 * V_173 )
{
struct V_73 * V_74 ;
T_3 V_303 ;
int V_304 ;
V_304 = F_271 ( V_173 -> V_71 , F_272 ( 0 , 0 ) , 0xb0 , & V_303 ) ;
if ( V_304 ) {
F_273 ( & V_173 -> V_147 , L_63 ) ;
return;
}
V_303 &= 0xffff0000 ;
V_74 = F_194 ( V_173 ) ;
if ( F_274 ( ! V_74 || V_74 -> V_260 - V_303 != 0xa000 ,
V_305 ,
L_64 ) )
V_173 -> V_147 . V_225 . V_49 = V_240 ;
}
static void T_1 F_275 ( void )
{
struct V_73 * V_74 ;
F_73 (drhd) {
if ( ! V_74 -> V_80 ) {
int V_64 ;
for ( V_64 = 0 ; V_64 < V_74 -> V_76 ; V_64 ++ )
if ( V_74 -> V_77 [ V_64 ] != NULL )
break;
if ( V_64 == V_74 -> V_76 )
V_74 -> V_75 = 1 ;
}
}
if ( V_36 )
return;
F_73 (drhd) {
int V_64 ;
if ( V_74 -> V_75 || V_74 -> V_80 )
continue;
for ( V_64 = 0 ; V_64 < V_74 -> V_76 ; V_64 ++ )
if ( V_74 -> V_77 [ V_64 ] &&
! F_214 ( V_74 -> V_77 [ V_64 ] ) )
break;
if ( V_64 < V_74 -> V_76 )
continue;
V_74 -> V_75 = 1 ;
for ( V_64 = 0 ; V_64 < V_74 -> V_76 ; V_64 ++ ) {
if ( ! V_74 -> V_77 [ V_64 ] )
continue;
V_74 -> V_77 [ V_64 ] -> V_147 . V_225 . V_49 = V_240 ;
}
}
}
static int F_276 ( void )
{
struct V_73 * V_74 ;
struct V_48 * V_49 = NULL ;
F_165 (iommu, drhd)
if ( V_49 -> V_145 )
F_277 ( V_49 ) ;
F_278 (iommu, drhd) {
if ( V_74 -> V_75 ) {
if ( V_264 )
F_128 ( V_49 ) ;
continue;
}
F_95 ( V_49 ) ;
F_91 ( V_49 ) ;
V_49 -> V_153 . V_197 ( V_49 , 0 , 0 , 0 ,
V_127 ) ;
V_49 -> V_153 . V_154 ( V_49 , 0 , 0 , 0 ,
V_136 ) ;
if ( F_129 ( V_49 ) )
return 1 ;
F_128 ( V_49 ) ;
}
return 0 ;
}
static void F_279 ( void )
{
struct V_73 * V_74 ;
struct V_48 * V_49 ;
F_165 (iommu, drhd) {
V_49 -> V_153 . V_197 ( V_49 , 0 , 0 , 0 ,
V_127 ) ;
V_49 -> V_153 . V_154 ( V_49 , 0 , 0 , 0 ,
V_136 ) ;
}
}
static int F_280 ( void )
{
struct V_73 * V_74 ;
struct V_48 * V_49 = NULL ;
unsigned long V_111 ;
F_165 (iommu, drhd) {
V_49 -> V_306 = F_220 ( sizeof( T_3 ) * V_307 ,
V_42 ) ;
if ( ! V_49 -> V_306 )
goto V_308;
}
F_279 () ;
F_165 (iommu, drhd) {
F_130 ( V_49 ) ;
F_77 ( & V_49 -> V_112 , V_111 ) ;
V_49 -> V_306 [ V_309 ] =
V_119 ( V_49 -> V_113 + V_310 ) ;
V_49 -> V_306 [ V_311 ] =
V_119 ( V_49 -> V_113 + V_312 ) ;
V_49 -> V_306 [ V_313 ] =
V_119 ( V_49 -> V_113 + V_314 ) ;
V_49 -> V_306 [ V_315 ] =
V_119 ( V_49 -> V_113 + V_316 ) ;
F_78 ( & V_49 -> V_112 , V_111 ) ;
}
return 0 ;
V_308:
F_165 (iommu, drhd)
F_144 ( V_49 -> V_306 ) ;
return - V_108 ;
}
static void F_281 ( void )
{
struct V_73 * V_74 ;
struct V_48 * V_49 = NULL ;
unsigned long V_111 ;
if ( F_276 () ) {
if ( V_264 )
F_282 ( L_65 ) ;
else
F_199 ( 1 , L_66 ) ;
return;
}
F_165 (iommu, drhd) {
F_77 ( & V_49 -> V_112 , V_111 ) ;
F_93 ( V_49 -> V_306 [ V_309 ] ,
V_49 -> V_113 + V_310 ) ;
F_93 ( V_49 -> V_306 [ V_311 ] ,
V_49 -> V_113 + V_312 ) ;
F_93 ( V_49 -> V_306 [ V_313 ] ,
V_49 -> V_113 + V_314 ) ;
F_93 ( V_49 -> V_306 [ V_315 ] ,
V_49 -> V_113 + V_316 ) ;
F_78 ( & V_49 -> V_112 , V_111 ) ;
}
F_165 (iommu, drhd)
F_144 ( V_49 -> V_306 ) ;
}
static void T_1 F_283 ( void )
{
F_284 ( & V_317 ) ;
}
static inline void F_283 ( void ) {}
static int F_285 ( struct V_318 * V_319 ,
unsigned long V_320 , void * V_285 )
{
struct V_265 * V_147 = V_285 ;
struct V_172 * V_173 = F_231 ( V_147 ) ;
struct V_55 * V_56 ;
if ( F_239 ( V_147 ) )
return 0 ;
V_56 = F_192 ( V_173 ) ;
if ( ! V_56 )
return 0 ;
if ( V_320 == V_321 && ! V_263 ) {
F_240 ( V_56 , V_173 ) ;
if ( ! ( V_56 -> V_58 & V_59 ) &&
! ( V_56 -> V_58 & V_60 ) &&
F_189 ( & V_56 -> V_77 ) )
F_140 ( V_56 ) ;
}
return 0 ;
}
int T_1 F_286 ( void )
{
int V_86 = 0 ;
V_264 = F_287 () ;
if ( F_288 () ) {
if ( V_264 )
F_282 ( L_67 ) ;
return - V_180 ;
}
if ( F_289 () ) {
if ( V_264 )
F_282 ( L_68 ) ;
return - V_180 ;
}
if ( V_322 || V_34 )
return - V_180 ;
if ( F_267 () ) {
if ( V_264 )
F_282 ( L_69 ) ;
return - V_180 ;
}
if ( F_149 () ) {
if ( V_264 )
F_282 ( L_70 ) ;
return - V_180 ;
}
F_275 () ;
V_86 = F_219 () ;
if ( V_86 ) {
if ( V_264 )
F_282 ( L_71 ) ;
F_41 ( V_141 L_72 ) ;
F_164 ( & V_174 ) ;
F_269 () ;
return V_86 ;
}
F_41 ( V_35
L_73 ) ;
F_290 ( & V_289 ) ;
#ifdef F_291
V_323 = 0 ;
#endif
V_324 = & V_325 ;
F_283 () ;
F_292 ( & V_326 ) ;
F_293 ( & V_267 , & V_327 ) ;
return 0 ;
}
static void F_294 ( struct V_48 * V_49 ,
struct V_172 * V_173 )
{
struct V_172 * V_106 , * V_91 ;
if ( ! V_49 || ! V_173 )
return;
V_106 = F_173 ( V_173 ) ;
if ( V_106 ) {
V_91 = V_173 -> V_71 -> V_199 ;
while ( V_91 != V_106 ) {
F_188 ( V_49 , V_91 -> V_71 -> V_78 ,
V_91 -> V_72 ) ;
V_91 = V_91 -> V_71 -> V_199 ;
}
if ( F_174 ( V_106 ) )
F_188 ( V_49 ,
V_106 -> V_79 -> V_78 , 0 ) ;
else
F_188 ( V_49 , V_106 -> V_71 -> V_78 ,
V_106 -> V_72 ) ;
}
}
static void F_240 ( struct V_55 * V_56 ,
struct V_172 * V_173 )
{
struct V_142 * V_144 ;
struct V_48 * V_49 ;
unsigned long V_58 ;
int V_143 = 0 ;
struct V_328 * V_329 , * V_106 ;
V_49 = F_72 ( F_172 ( V_173 -> V_71 ) , V_173 -> V_71 -> V_78 ,
V_173 -> V_72 ) ;
if ( ! V_49 )
return;
F_77 ( & V_146 , V_58 ) ;
F_295 (entry, tmp, &domain->devices) {
V_144 = F_190 ( V_329 , struct V_142 , V_223 ) ;
if ( V_144 -> V_70 == F_172 ( V_173 -> V_71 ) &&
V_144 -> V_71 == V_173 -> V_71 -> V_78 &&
V_144 -> V_72 == V_173 -> V_72 ) {
F_191 ( & V_144 -> V_223 ) ;
F_191 ( & V_144 -> V_224 ) ;
if ( V_144 -> V_147 )
V_144 -> V_147 -> V_147 . V_225 . V_49 = NULL ;
F_78 ( & V_146 , V_58 ) ;
F_116 ( V_144 ) ;
F_188 ( V_49 , V_144 -> V_71 , V_144 -> V_72 ) ;
F_294 ( V_49 , V_173 ) ;
F_52 ( V_144 ) ;
F_77 ( & V_146 , V_58 ) ;
if ( V_143 )
break;
else
continue;
}
if ( V_49 == F_72 ( V_144 -> V_70 , V_144 -> V_71 ,
V_144 -> V_72 ) )
V_143 = 1 ;
}
if ( V_143 == 0 ) {
unsigned long V_330 ;
F_77 ( & V_56 -> V_167 , V_330 ) ;
F_138 ( V_49 -> V_164 , & V_56 -> V_61 ) ;
V_56 -> V_168 -- ;
F_71 ( V_56 ) ;
F_78 ( & V_56 -> V_167 , V_330 ) ;
if ( ! ( V_56 -> V_58 & V_59 ) &&
! ( V_56 -> V_58 & V_60 ) ) {
F_77 ( & V_49 -> V_84 , V_330 ) ;
F_138 ( V_56 -> V_171 , V_49 -> V_165 ) ;
V_49 -> V_155 [ V_56 -> V_171 ] = NULL ;
F_78 ( & V_49 -> V_84 , V_330 ) ;
}
}
F_78 ( & V_146 , V_58 ) ;
}
static void F_296 ( struct V_55 * V_56 )
{
struct V_142 * V_144 ;
struct V_48 * V_49 ;
unsigned long V_331 , V_332 ;
F_77 ( & V_146 , V_331 ) ;
while ( ! F_189 ( & V_56 -> V_77 ) ) {
V_144 = F_190 ( V_56 -> V_77 . V_222 ,
struct V_142 , V_223 ) ;
F_191 ( & V_144 -> V_223 ) ;
F_191 ( & V_144 -> V_224 ) ;
if ( V_144 -> V_147 )
V_144 -> V_147 -> V_147 . V_225 . V_49 = NULL ;
F_78 ( & V_146 , V_331 ) ;
F_116 ( V_144 ) ;
V_49 = F_72 ( V_144 -> V_70 , V_144 -> V_71 , V_144 -> V_72 ) ;
F_188 ( V_49 , V_144 -> V_71 , V_144 -> V_72 ) ;
F_294 ( V_49 , V_144 -> V_147 ) ;
F_77 ( & V_56 -> V_167 , V_332 ) ;
if ( F_297 ( V_49 -> V_164 ,
& V_56 -> V_61 ) ) {
V_56 -> V_168 -- ;
F_71 ( V_56 ) ;
}
F_78 ( & V_56 -> V_167 , V_332 ) ;
F_52 ( V_144 ) ;
F_77 ( & V_146 , V_331 ) ;
}
F_78 ( & V_146 , V_331 ) ;
}
static struct V_55 * F_298 ( void )
{
struct V_55 * V_56 ;
V_56 = F_47 () ;
if ( ! V_56 )
return NULL ;
V_56 -> V_171 = V_333 ++ ;
V_56 -> V_99 = - 1 ;
memset ( & V_56 -> V_61 , 0 , sizeof( unsigned long ) ) ;
V_56 -> V_58 = V_59 ;
return V_56 ;
}
static int F_206 ( struct V_55 * V_56 , int V_188 )
{
int V_189 ;
F_150 ( & V_56 -> V_187 , V_175 ) ;
F_134 ( & V_56 -> V_167 ) ;
F_155 ( V_56 ) ;
V_56 -> V_107 = V_188 ;
V_189 = F_157 ( V_188 ) ;
V_56 -> V_1 = F_3 ( V_189 ) ;
F_161 ( & V_56 -> V_77 ) ;
V_56 -> V_168 = 0 ;
V_56 -> V_65 = 0 ;
V_56 -> V_67 = 0 ;
V_56 -> V_69 = 0 ;
V_56 -> V_334 = 0 ;
V_56 -> V_99 = - 1 ;
V_56 -> V_94 = (struct V_25 * ) F_42 ( V_56 -> V_99 ) ;
if ( ! V_56 -> V_94 )
return - V_108 ;
F_74 ( V_56 , V_56 -> V_94 , V_190 ) ;
return 0 ;
}
static void F_299 ( struct V_55 * V_56 )
{
unsigned long V_58 ;
struct V_73 * V_74 ;
struct V_48 * V_49 ;
unsigned long V_64 ;
unsigned long V_162 ;
F_73 (drhd) {
if ( V_74 -> V_75 )
continue;
V_49 = V_74 -> V_49 ;
V_162 = F_132 ( V_49 -> V_52 ) ;
F_64 (i, iommu->domain_ids, ndomains) {
if ( V_49 -> V_155 [ V_64 ] == V_56 ) {
F_77 ( & V_49 -> V_84 , V_58 ) ;
F_138 ( V_64 , V_49 -> V_165 ) ;
V_49 -> V_155 [ V_64 ] = NULL ;
F_78 ( & V_49 -> V_84 , V_58 ) ;
break;
}
}
}
}
static void F_139 ( struct V_55 * V_56 )
{
if ( ! V_56 )
return;
F_296 ( V_56 ) ;
F_164 ( & V_56 -> V_187 ) ;
F_87 ( V_56 , 0 , F_89 ( V_56 -> V_107 ) ) ;
F_88 ( V_56 , 0 , F_89 ( V_56 -> V_107 ) ) ;
F_299 ( V_56 ) ;
F_49 ( V_56 ) ;
}
static int F_300 ( struct V_335 * V_56 )
{
struct V_55 * V_55 ;
V_55 = F_298 () ;
if ( ! V_55 ) {
F_41 ( V_141
L_74 ) ;
return - V_108 ;
}
if ( F_206 ( V_55 , V_54 ) ) {
F_41 ( V_141
L_75 ) ;
F_139 ( V_55 ) ;
return - V_108 ;
}
V_56 -> V_336 = V_55 ;
return 0 ;
}
static void F_301 ( struct V_335 * V_56 )
{
struct V_55 * V_55 = V_56 -> V_336 ;
V_56 -> V_336 = NULL ;
F_139 ( V_55 ) ;
}
static int F_302 ( struct V_335 * V_56 ,
struct V_265 * V_147 )
{
struct V_55 * V_55 = V_56 -> V_336 ;
struct V_172 * V_173 = F_231 ( V_147 ) ;
struct V_48 * V_49 ;
int V_90 ;
if ( F_169 ( F_175 ( V_173 ) ) ) {
struct V_55 * V_337 ;
V_337 = F_192 ( V_173 ) ;
if ( V_337 ) {
if ( V_55 -> V_58 & V_59 ||
V_55 -> V_58 & V_60 )
F_240 ( V_337 , V_173 ) ;
else
F_163 ( V_337 ) ;
}
}
V_49 = F_72 ( F_172 ( V_173 -> V_71 ) , V_173 -> V_71 -> V_78 ,
V_173 -> V_72 ) ;
if ( ! V_49 )
return - V_180 ;
V_90 = F_2 ( V_49 -> V_1 ) ;
if ( V_90 > F_159 ( V_49 -> V_52 ) )
V_90 = F_159 ( V_49 -> V_52 ) ;
if ( V_55 -> V_334 > ( 1LL << V_90 ) ) {
F_41 ( V_141 L_76
L_77 ,
V_338 , V_90 , V_55 -> V_334 ) ;
return - V_194 ;
}
V_55 -> V_107 = V_90 ;
while ( V_49 -> V_1 < V_55 -> V_1 ) {
struct V_25 * V_26 ;
V_26 = V_55 -> V_94 ;
if ( F_38 ( V_26 ) ) {
V_55 -> V_94 = (struct V_25 * )
F_20 ( F_34 ( V_26 ) ) ;
F_45 ( V_26 ) ;
}
V_55 -> V_1 -- ;
}
return F_211 ( V_55 , V_173 , V_193 ) ;
}
static void F_303 ( struct V_335 * V_56 ,
struct V_265 * V_147 )
{
struct V_55 * V_55 = V_56 -> V_336 ;
struct V_172 * V_173 = F_231 ( V_147 ) ;
F_240 ( V_55 , V_173 ) ;
}
static int F_304 ( struct V_335 * V_56 ,
unsigned long V_46 , T_6 V_339 ,
int V_340 , int V_341 )
{
struct V_55 * V_55 = V_56 -> V_336 ;
V_23 V_334 ;
int V_30 = 0 ;
T_5 V_82 ;
int V_86 ;
if ( V_341 & V_342 )
V_30 |= V_27 ;
if ( V_341 & V_343 )
V_30 |= V_28 ;
if ( ( V_341 & V_344 ) && V_55 -> V_67 )
V_30 |= V_29 ;
V_82 = V_190 << V_340 ;
V_334 = V_46 + V_82 ;
if ( V_55 -> V_334 < V_334 ) {
V_23 V_186 ;
V_186 = F_305 ( V_55 -> V_107 ) + 1 ;
if ( V_186 < V_334 ) {
F_41 ( V_141 L_76
L_77 ,
V_338 , V_55 -> V_107 , V_334 ) ;
return - V_194 ;
}
V_55 -> V_334 = V_334 ;
}
V_82 = F_176 ( V_339 , V_82 ) ;
V_86 = F_187 ( V_55 , V_46 >> V_10 ,
V_339 >> V_10 , V_82 , V_30 ) ;
return V_86 ;
}
static int F_306 ( struct V_335 * V_56 ,
unsigned long V_46 , int V_340 )
{
struct V_55 * V_55 = V_56 -> V_336 ;
T_5 V_82 = V_190 << V_340 ;
F_87 ( V_55 , V_46 >> V_10 ,
( V_46 + V_82 - 1 ) >> V_10 ) ;
if ( V_55 -> V_334 == V_46 + V_82 )
V_55 -> V_334 = V_46 ;
return V_340 ;
}
static T_6 F_307 ( struct V_335 * V_56 ,
unsigned long V_46 )
{
struct V_55 * V_55 = V_56 -> V_336 ;
struct V_25 * V_26 ;
V_23 V_345 = 0 ;
V_26 = F_84 ( V_55 , V_46 >> V_10 , 0 ) ;
if ( V_26 )
V_345 = F_34 ( V_26 ) ;
return V_345 ;
}
static int F_308 ( struct V_335 * V_56 ,
unsigned long V_52 )
{
struct V_55 * V_55 = V_56 -> V_336 ;
if ( V_52 == V_346 )
return V_55 -> V_67 ;
if ( V_52 == V_347 )
return V_348 ;
return 0 ;
}
static void T_8 F_309 ( struct V_172 * V_147 )
{
F_41 ( V_35 L_78 ) ;
V_121 = 1 ;
if ( V_147 -> V_349 == 0x07 ) {
F_41 ( V_35 L_79 ) ;
V_36 = 0 ;
}
}
static void T_8 F_310 ( struct V_172 * V_147 )
{
unsigned short V_350 ;
if ( F_311 ( V_147 , V_351 , & V_350 ) )
return;
if ( ! ( V_350 & V_352 ) ) {
F_41 ( V_35 L_80 ) ;
V_36 = 0 ;
}
}
static void T_1 F_226 ( void )
{
struct V_172 * V_173 ;
T_9 V_353 ;
V_173 = F_312 ( V_354 , 0x3a3e , NULL ) ;
if ( ! V_173 )
return;
F_313 ( V_173 ) ;
V_173 = F_312 ( V_354 , 0x342e , NULL ) ;
if ( ! V_173 )
return;
if ( F_314 ( V_173 , 0x188 , & V_353 ) ) {
F_313 ( V_173 ) ;
return;
}
F_313 ( V_173 ) ;
if ( V_353 & 1 )
return;
V_353 &= 0x1c ;
if ( V_353 == 0x10 )
return;
if ( ! V_353 ) {
F_199 ( 1 , L_81
L_31 ,
F_200 ( V_234 ) ,
F_200 ( V_235 ) ,
F_200 ( V_236 ) ) ;
V_247 |= V_249 ;
return;
}
F_41 ( V_355 L_82 ,
V_353 ) ;
}
