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
V_56 -> V_65 = 1 ;
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
V_69 -> V_77 [ V_64 ] -> V_79 -> V_79 >= V_73 )
return V_69 -> V_49 ;
}
if ( V_69 -> V_80 )
return V_69 -> V_49 ;
}
return NULL ;
}
static void F_76 ( struct V_55 * V_56 ,
void * V_81 , int V_82 )
{
if ( ! V_56 -> V_65 )
F_77 ( V_81 , V_82 ) ;
}
static struct V_20 * F_78 ( struct V_48 * V_49 ,
T_2 V_73 , T_2 V_74 )
{
struct V_15 * V_16 ;
struct V_20 * V_21 ;
unsigned long V_83 ;
unsigned long V_58 ;
F_79 ( & V_49 -> V_84 , V_58 ) ;
V_16 = & V_49 -> V_15 [ V_73 ] ;
V_21 = F_19 ( V_16 ) ;
if ( ! V_21 ) {
V_21 = (struct V_20 * )
F_43 ( V_49 -> V_40 ) ;
if ( ! V_21 ) {
F_80 ( & V_49 -> V_84 , V_58 ) ;
return NULL ;
}
F_81 ( V_49 , ( void * ) V_21 , V_85 ) ;
V_83 = F_82 ( ( void * ) V_21 ) ;
F_18 ( V_16 , V_83 ) ;
F_17 ( V_16 ) ;
F_81 ( V_49 , V_16 , sizeof( * V_16 ) ) ;
}
F_80 ( & V_49 -> V_84 , V_58 ) ;
return & V_21 [ V_74 ] ;
}
static int F_83 ( struct V_48 * V_49 , T_2 V_73 , T_2 V_74 )
{
struct V_15 * V_16 ;
struct V_20 * V_21 ;
int V_86 ;
unsigned long V_58 ;
F_79 ( & V_49 -> V_84 , V_58 ) ;
V_16 = & V_49 -> V_15 [ V_73 ] ;
V_21 = F_19 ( V_16 ) ;
if ( ! V_21 ) {
V_86 = 0 ;
goto V_87;
}
V_86 = F_21 ( & V_21 [ V_74 ] ) ;
V_87:
F_80 ( & V_49 -> V_84 , V_58 ) ;
return V_86 ;
}
static void F_84 ( struct V_48 * V_49 , T_2 V_73 , T_2 V_74 )
{
struct V_15 * V_16 ;
struct V_20 * V_21 ;
unsigned long V_58 ;
F_79 ( & V_49 -> V_84 , V_58 ) ;
V_16 = & V_49 -> V_15 [ V_73 ] ;
V_21 = F_19 ( V_16 ) ;
if ( V_21 ) {
F_28 ( & V_21 [ V_74 ] ) ;
F_81 ( V_49 , & V_21 [ V_74 ] , \
sizeof( * V_21 ) ) ;
}
F_80 ( & V_49 -> V_84 , V_58 ) ;
}
static void F_85 ( struct V_48 * V_49 )
{
struct V_15 * V_16 ;
int V_64 ;
unsigned long V_58 ;
struct V_20 * V_21 ;
F_79 ( & V_49 -> V_84 , V_58 ) ;
if ( ! V_49 -> V_15 ) {
goto V_87;
}
for ( V_64 = 0 ; V_64 < V_88 ; V_64 ++ ) {
V_16 = & V_49 -> V_15 [ V_64 ] ;
V_21 = F_19 ( V_16 ) ;
if ( V_21 )
F_46 ( V_21 ) ;
}
F_46 ( V_49 -> V_15 ) ;
V_49 -> V_15 = NULL ;
V_87:
F_80 ( & V_49 -> V_84 , V_58 ) ;
}
static struct V_25 * F_86 ( struct V_55 * V_56 ,
unsigned long V_5 , int V_89 )
{
int V_90 = F_2 ( V_56 -> V_1 ) - V_10 ;
struct V_25 * V_91 , * V_26 = NULL ;
int V_4 = F_1 ( V_56 -> V_1 ) ;
int V_92 ;
F_62 ( ! V_56 -> V_93 ) ;
F_62 ( V_90 < V_94 && V_5 > > V_90 ) ;
V_91 = V_56 -> V_93 ;
while ( V_4 > 0 ) {
void * V_95 ;
V_92 = F_5 ( V_5 , V_4 ) ;
V_26 = & V_91 [ V_92 ] ;
if ( ! V_89 && ( F_39 ( V_26 ) || ! F_38 ( V_26 ) ) )
break;
if ( V_4 == V_89 )
break;
if ( ! F_38 ( V_26 ) ) {
V_31 V_96 ;
V_95 = F_43 ( V_56 -> V_97 ) ;
if ( ! V_95 )
return NULL ;
F_76 ( V_56 , V_95 , V_98 ) ;
V_96 = ( ( V_31 ) F_14 ( V_95 ) << V_10 ) | V_27 | V_28 ;
if ( F_87 ( & V_26 -> V_17 , 0ULL , V_96 ) ) {
F_46 ( V_95 ) ;
} else {
F_34 ( V_26 ) ;
F_76 ( V_56 , V_26 , sizeof( * V_26 ) ) ;
}
}
V_91 = F_20 ( F_34 ( V_26 ) ) ;
V_4 -- ;
}
return V_26 ;
}
static struct V_25 * F_88 ( struct V_55 * V_56 ,
unsigned long V_5 ,
int V_4 , int * V_99 )
{
struct V_25 * V_91 , * V_26 = NULL ;
int V_100 = F_1 ( V_56 -> V_1 ) ;
int V_92 ;
V_91 = V_56 -> V_93 ;
while ( V_4 <= V_100 ) {
V_92 = F_5 ( V_5 , V_100 ) ;
V_26 = & V_91 [ V_92 ] ;
if ( V_4 == V_100 )
return V_26 ;
if ( ! F_38 ( V_26 ) ) {
* V_99 = V_100 ;
break;
}
if ( V_26 -> V_17 & V_101 ) {
* V_99 = V_100 ;
return V_26 ;
}
V_91 = F_20 ( F_34 ( V_26 ) ) ;
V_100 -- ;
}
return NULL ;
}
static int F_89 ( struct V_55 * V_56 ,
unsigned long V_102 ,
unsigned long V_103 )
{
int V_90 = F_2 ( V_56 -> V_1 ) - V_10 ;
unsigned int V_99 = 1 ;
struct V_25 * V_104 , * V_26 ;
int V_105 ;
F_62 ( V_90 < V_94 && V_102 > > V_90 ) ;
F_62 ( V_90 < V_94 && V_103 > > V_90 ) ;
F_62 ( V_102 > V_103 ) ;
do {
V_99 = 1 ;
V_104 = V_26 = F_88 ( V_56 , V_102 , 1 , & V_99 ) ;
if ( ! V_26 ) {
V_102 = F_8 ( V_102 + 1 , V_99 + 1 ) ;
continue;
}
do {
F_29 ( V_26 ) ;
V_102 += F_9 ( V_99 ) ;
V_26 ++ ;
} while ( V_102 <= V_103 && ! F_40 ( V_26 ) );
F_76 ( V_56 , V_104 ,
( void * ) V_26 - ( void * ) V_104 ) ;
} while ( V_102 && V_102 <= V_103 );
V_105 = ( V_99 - 1 ) * 9 ;
return V_105 ;
}
static void F_90 ( struct V_55 * V_56 ,
unsigned long V_102 ,
unsigned long V_103 )
{
int V_90 = F_2 ( V_56 -> V_1 ) - V_10 ;
struct V_25 * V_104 , * V_26 ;
int V_100 = F_1 ( V_56 -> V_1 ) ;
int V_4 ;
unsigned long V_106 ;
int V_99 = 2 ;
F_62 ( V_90 < V_94 && V_102 > > V_90 ) ;
F_62 ( V_90 < V_94 && V_103 > > V_90 ) ;
F_62 ( V_102 > V_103 ) ;
V_4 = 2 ;
while ( V_4 <= V_100 ) {
V_106 = F_8 ( V_102 , V_4 ) ;
if ( V_106 + F_7 ( V_4 ) - 1 > V_103 )
return;
do {
V_99 = V_4 ;
V_104 = V_26 = F_88 ( V_56 , V_106 , V_4 , & V_99 ) ;
if ( V_99 > V_4 )
V_4 = V_99 + 1 ;
if ( ! V_26 ) {
V_106 = F_8 ( V_106 + 1 , V_4 + 1 ) ;
continue;
}
do {
if ( F_38 ( V_26 ) ) {
F_46 ( F_20 ( F_34 ( V_26 ) ) ) ;
F_29 ( V_26 ) ;
}
V_26 ++ ;
V_106 += F_7 ( V_4 ) ;
} while ( ! F_40 ( V_26 ) &&
V_106 + F_7 ( V_4 ) - 1 <= V_103 );
F_76 ( V_56 , V_104 ,
( void * ) V_26 - ( void * ) V_104 ) ;
} while ( V_106 && V_106 + F_7 ( V_4 ) - 1 <= V_103 );
V_4 ++ ;
}
if ( V_102 == 0 && V_103 == F_91 ( V_56 -> V_107 ) ) {
F_46 ( V_56 -> V_93 ) ;
V_56 -> V_93 = NULL ;
}
}
static int F_92 ( struct V_48 * V_49 )
{
struct V_15 * V_16 ;
unsigned long V_58 ;
V_16 = (struct V_15 * ) F_43 ( V_49 -> V_40 ) ;
if ( ! V_16 )
return - V_108 ;
F_81 ( V_49 , V_16 , V_109 ) ;
F_79 ( & V_49 -> V_84 , V_58 ) ;
V_49 -> V_15 = V_16 ;
F_80 ( & V_49 -> V_84 , V_58 ) ;
return 0 ;
}
static void F_93 ( struct V_48 * V_49 )
{
void * V_81 ;
T_3 V_110 ;
unsigned long V_111 ;
V_81 = V_49 -> V_15 ;
F_94 ( & V_49 -> V_112 , V_111 ) ;
F_95 ( V_49 -> V_113 + V_114 , F_82 ( V_81 ) ) ;
F_96 ( V_49 -> V_115 | V_116 , V_49 -> V_113 + V_117 ) ;
F_97 ( V_49 , V_118 ,
V_119 , ( V_110 & V_120 ) , V_110 ) ;
F_98 ( & V_49 -> V_112 , V_111 ) ;
}
static void F_99 ( struct V_48 * V_49 )
{
T_3 V_17 ;
unsigned long V_111 ;
if ( ! V_121 && ! F_100 ( V_49 -> V_52 ) )
return;
F_94 ( & V_49 -> V_112 , V_111 ) ;
F_96 ( V_49 -> V_115 | V_122 , V_49 -> V_113 + V_117 ) ;
F_97 ( V_49 , V_118 ,
V_119 , ( ! ( V_17 & V_123 ) ) , V_17 ) ;
F_98 ( & V_49 -> V_112 , V_111 ) ;
}
static void F_101 ( struct V_48 * V_49 ,
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
V_17 = V_128 | F_102 ( V_124 ) ;
break;
case V_129 :
V_17 = V_129 | F_102 ( V_124 )
| F_103 ( V_125 ) | F_104 ( V_126 ) ;
break;
default:
F_105 () ;
}
V_17 |= V_130 ;
F_94 ( & V_49 -> V_112 , V_111 ) ;
F_95 ( V_49 -> V_113 + V_131 , V_17 ) ;
F_97 ( V_49 , V_131 ,
V_132 , ( ! ( V_17 & V_130 ) ) , V_17 ) ;
F_98 ( & V_49 -> V_112 , V_111 ) ;
}
static void F_106 ( struct V_48 * V_49 , T_4 V_124 ,
V_23 V_81 , unsigned int V_133 , V_23 type )
{
int V_134 = F_107 ( V_49 -> V_66 ) ;
V_23 V_17 = 0 , V_135 = 0 ;
unsigned long V_111 ;
switch ( type ) {
case V_136 :
V_17 = V_136 | V_137 ;
break;
case V_138 :
V_17 = V_138 | V_137 | F_108 ( V_124 ) ;
break;
case V_139 :
V_17 = V_139 | V_137 | F_108 ( V_124 ) ;
V_135 = V_133 | V_81 ;
break;
default:
F_105 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_109 ( V_49 -> V_52 ) )
V_17 |= V_140 ;
F_94 ( & V_49 -> V_112 , V_111 ) ;
if ( V_135 )
F_95 ( V_49 -> V_113 + V_134 , V_135 ) ;
F_95 ( V_49 -> V_113 + V_134 + 8 , V_17 ) ;
F_97 ( V_49 , V_134 + 8 ,
V_132 , ( ! ( V_17 & V_137 ) ) , V_17 ) ;
F_98 ( & V_49 -> V_112 , V_111 ) ;
if ( F_110 ( V_17 ) == 0 )
F_42 ( V_141 L_14 ) ;
if ( F_110 ( V_17 ) != F_111 ( type ) )
F_112 ( L_15 ,
( unsigned long long ) F_111 ( type ) ,
( unsigned long long ) F_110 ( V_17 ) ) ;
}
static struct V_142 * F_113 (
struct V_55 * V_56 , int V_72 , T_2 V_73 , T_2 V_74 )
{
int V_143 = 0 ;
unsigned long V_58 ;
struct V_142 * V_144 ;
struct V_48 * V_49 = F_74 ( V_72 , V_73 , V_74 ) ;
if ( ! F_114 ( V_49 -> V_66 ) )
return NULL ;
if ( ! V_49 -> V_145 )
return NULL ;
F_79 ( & V_146 , V_58 ) ;
F_115 (info, &domain->devices, link)
if ( V_144 -> V_73 == V_73 && V_144 -> V_74 == V_74 ) {
V_143 = 1 ;
break;
}
F_80 ( & V_146 , V_58 ) ;
if ( ! V_143 || ! V_144 -> V_147 )
return NULL ;
if ( ! F_116 ( V_144 -> V_147 , V_148 ) )
return NULL ;
if ( ! F_117 ( V_144 -> V_147 ) )
return NULL ;
V_144 -> V_49 = V_49 ;
return V_144 ;
}
static void F_118 ( struct V_142 * V_144 )
{
if ( ! V_144 )
return;
F_119 ( V_144 -> V_147 , V_10 ) ;
}
static void F_120 ( struct V_142 * V_144 )
{
if ( ! V_144 -> V_147 || ! F_121 ( V_144 -> V_147 ) )
return;
F_122 ( V_144 -> V_147 ) ;
}
static void F_123 ( struct V_55 * V_56 ,
V_23 V_81 , unsigned V_70 )
{
T_4 V_149 , V_150 ;
unsigned long V_58 ;
struct V_142 * V_144 ;
F_79 ( & V_146 , V_58 ) ;
F_115 (info, &domain->devices, link) {
if ( ! V_144 -> V_147 || ! F_121 ( V_144 -> V_147 ) )
continue;
V_149 = V_144 -> V_73 << 8 | V_144 -> V_74 ;
V_150 = F_124 ( V_144 -> V_147 ) ;
F_125 ( V_144 -> V_49 , V_149 , V_150 , V_81 , V_70 ) ;
}
F_80 ( & V_146 , V_58 ) ;
}
static void F_126 ( struct V_48 * V_49 , T_4 V_124 ,
unsigned long V_5 , unsigned int V_151 , int V_152 )
{
unsigned int V_70 = F_127 ( F_128 ( V_151 ) ) ;
V_31 V_81 = ( V_31 ) V_5 << V_10 ;
F_62 ( V_151 == 0 ) ;
if ( ! F_129 ( V_49 -> V_52 ) || V_70 > F_130 ( V_49 -> V_52 ) )
V_49 -> V_153 . V_154 ( V_49 , V_124 , 0 , 0 ,
V_138 ) ;
else
V_49 -> V_153 . V_154 ( V_49 , V_124 , V_81 , V_70 ,
V_139 ) ;
if ( ! F_131 ( V_49 -> V_52 ) || ! V_152 )
F_123 ( V_49 -> V_155 [ V_124 ] , V_81 , V_70 ) ;
}
static void F_132 ( struct V_48 * V_49 )
{
T_3 V_156 ;
unsigned long V_58 ;
F_94 ( & V_49 -> V_112 , V_58 ) ;
V_156 = V_119 ( V_49 -> V_113 + V_157 ) ;
V_156 &= ~ V_158 ;
F_96 ( V_156 , V_49 -> V_113 + V_157 ) ;
F_97 ( V_49 , V_157 ,
V_119 , ! ( V_156 & V_159 ) , V_156 ) ;
F_98 ( & V_49 -> V_112 , V_58 ) ;
}
static int F_133 ( struct V_48 * V_49 )
{
T_3 V_110 ;
unsigned long V_58 ;
F_94 ( & V_49 -> V_112 , V_58 ) ;
V_49 -> V_115 |= V_160 ;
F_96 ( V_49 -> V_115 , V_49 -> V_113 + V_117 ) ;
F_97 ( V_49 , V_118 ,
V_119 , ( V_110 & V_161 ) , V_110 ) ;
F_98 ( & V_49 -> V_112 , V_58 ) ;
return 0 ;
}
static int F_134 ( struct V_48 * V_49 )
{
T_3 V_110 ;
unsigned long V_111 ;
F_94 ( & V_49 -> V_112 , V_111 ) ;
V_49 -> V_115 &= ~ V_160 ;
F_96 ( V_49 -> V_115 , V_49 -> V_113 + V_117 ) ;
F_97 ( V_49 , V_118 ,
V_119 , ( ! ( V_110 & V_161 ) ) , V_110 ) ;
F_98 ( & V_49 -> V_112 , V_111 ) ;
return 0 ;
}
static int F_135 ( struct V_48 * V_49 )
{
unsigned long V_162 ;
unsigned long V_163 ;
V_162 = F_136 ( V_49 -> V_52 ) ;
F_112 ( L_16 , V_49 -> V_164 ,
V_162 ) ;
V_163 = F_137 ( V_162 ) ;
F_138 ( & V_49 -> V_84 ) ;
V_49 -> V_165 = F_139 ( V_163 , sizeof( unsigned long ) , V_166 ) ;
if ( ! V_49 -> V_165 ) {
F_42 ( V_141 L_17 ) ;
return - V_108 ;
}
V_49 -> V_155 = F_139 ( V_162 , sizeof( struct V_55 * ) ,
V_166 ) ;
if ( ! V_49 -> V_155 ) {
F_42 ( V_141 L_18 ) ;
return - V_108 ;
}
if ( F_131 ( V_49 -> V_52 ) )
F_140 ( 0 , V_49 -> V_165 ) ;
return 0 ;
}
void F_141 ( struct V_48 * V_49 )
{
struct V_55 * V_56 ;
int V_64 ;
unsigned long V_58 ;
if ( ( V_49 -> V_155 ) && ( V_49 -> V_165 ) ) {
F_65 (i, iommu->domain_ids, cap_ndoms(iommu->cap)) {
V_56 = V_49 -> V_155 [ V_64 ] ;
F_142 ( V_64 , V_49 -> V_165 ) ;
F_79 ( & V_56 -> V_167 , V_58 ) ;
if ( -- V_56 -> V_168 == 0 ) {
if ( V_56 -> V_58 & V_59 )
F_143 ( V_56 ) ;
else
F_144 ( V_56 ) ;
}
F_80 ( & V_56 -> V_167 , V_58 ) ;
}
}
if ( V_49 -> V_115 & V_160 )
F_134 ( V_49 ) ;
if ( V_49 -> V_169 ) {
F_145 ( V_49 -> V_169 , NULL ) ;
F_146 ( V_49 -> V_169 , V_49 ) ;
F_147 ( V_49 -> V_169 ) ;
}
F_148 ( V_49 -> V_155 ) ;
F_148 ( V_49 -> V_165 ) ;
V_63 [ V_49 -> V_164 ] = NULL ;
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
V_56 -> V_97 = - 1 ;
memset ( V_56 -> V_61 , 0 , sizeof( V_56 -> V_61 ) ) ;
V_56 -> V_58 = 0 ;
return V_56 ;
}
static int F_150 ( struct V_55 * V_56 ,
struct V_48 * V_49 )
{
int V_170 ;
unsigned long V_162 ;
unsigned long V_58 ;
V_162 = F_136 ( V_49 -> V_52 ) ;
F_79 ( & V_49 -> V_84 , V_58 ) ;
V_170 = F_151 ( V_49 -> V_165 , V_162 ) ;
if ( V_170 >= V_162 ) {
F_80 ( & V_49 -> V_84 , V_58 ) ;
F_42 ( V_141 L_19 ) ;
return - V_108 ;
}
V_56 -> V_171 = V_170 ;
F_140 ( V_170 , V_49 -> V_165 ) ;
F_140 ( V_49 -> V_164 , V_56 -> V_61 ) ;
V_49 -> V_155 [ V_170 ] = V_56 ;
F_80 ( & V_49 -> V_84 , V_58 ) ;
return 0 ;
}
static void F_152 ( struct V_55 * V_56 ,
struct V_48 * V_49 )
{
unsigned long V_58 ;
int V_170 , V_162 ;
int V_143 = 0 ;
F_79 ( & V_49 -> V_84 , V_58 ) ;
V_162 = F_136 ( V_49 -> V_52 ) ;
F_65 (num, iommu->domain_ids, ndomains) {
if ( V_49 -> V_155 [ V_170 ] == V_56 ) {
V_143 = 1 ;
break;
}
}
if ( V_143 ) {
F_142 ( V_170 , V_49 -> V_165 ) ;
F_142 ( V_49 -> V_164 , V_56 -> V_61 ) ;
V_49 -> V_155 [ V_170 ] = NULL ;
}
F_80 ( & V_49 -> V_84 , V_58 ) ;
}
static int F_153 ( void )
{
struct V_172 * V_173 = NULL ;
struct V_46 * V_46 ;
int V_64 ;
F_154 ( & V_174 , V_175 ) ;
F_155 ( & V_174 . V_176 ,
& V_177 ) ;
V_46 = F_156 ( & V_174 , F_157 ( V_178 ) ,
F_157 ( V_179 ) ) ;
if ( ! V_46 ) {
F_42 ( V_141 L_20 ) ;
return - V_180 ;
}
F_158 (pdev) {
struct V_181 * V_182 ;
for ( V_64 = 0 ; V_64 < V_183 ; V_64 ++ ) {
V_182 = & V_173 -> V_181 [ V_64 ] ;
if ( ! V_182 -> V_58 || ! ( V_182 -> V_58 & V_184 ) )
continue;
V_46 = F_156 ( & V_174 ,
F_157 ( V_182 -> V_185 ) ,
F_157 ( V_182 -> V_186 ) ) ;
if ( ! V_46 ) {
F_42 ( V_141 L_21 ) ;
return - V_180 ;
}
}
}
return 0 ;
}
static void F_159 ( struct V_55 * V_56 )
{
F_160 ( & V_174 , & V_56 -> V_187 ) ;
}
static inline int F_161 ( int V_107 )
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
static int F_162 ( struct V_55 * V_56 , int V_188 )
{
struct V_48 * V_49 ;
int V_189 , V_1 ;
unsigned long V_51 ;
F_154 ( & V_56 -> V_187 , V_175 ) ;
F_138 ( & V_56 -> V_167 ) ;
F_159 ( V_56 ) ;
V_49 = F_61 ( V_56 ) ;
if ( V_188 > F_163 ( V_49 -> V_52 ) )
V_188 = F_163 ( V_49 -> V_52 ) ;
V_56 -> V_107 = V_188 ;
V_189 = F_161 ( V_188 ) ;
V_1 = F_3 ( V_189 ) ;
V_51 = F_57 ( V_49 -> V_52 ) ;
if ( ! F_58 ( V_1 , & V_51 ) ) {
F_112 ( L_22 , V_1 ) ;
V_1 = F_164 ( & V_51 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_180 ;
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
V_56 -> V_168 = 1 ;
V_56 -> V_97 = V_49 -> V_40 ;
V_56 -> V_93 = (struct V_25 * ) F_43 ( V_56 -> V_97 ) ;
if ( ! V_56 -> V_93 )
return - V_108 ;
F_81 ( V_49 , V_56 -> V_93 , V_190 ) ;
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
F_168 ( & V_56 -> V_187 ) ;
F_89 ( V_56 , 0 , F_91 ( V_56 -> V_107 ) ) ;
F_90 ( V_56 , 0 , F_91 ( V_56 -> V_107 ) ) ;
F_70 (iommu, drhd)
if ( F_58 ( V_49 -> V_164 , V_56 -> V_61 ) )
F_152 ( V_56 , V_49 ) ;
F_50 ( V_56 ) ;
}
static int F_169 ( struct V_55 * V_56 , int V_72 ,
T_2 V_73 , T_2 V_74 , int V_191 )
{
struct V_20 * V_21 ;
unsigned long V_58 ;
struct V_48 * V_49 ;
struct V_25 * V_93 ;
unsigned long V_170 ;
unsigned long V_162 ;
int V_171 ;
int V_1 ;
struct V_142 * V_144 = NULL ;
F_112 ( L_23 ,
V_73 , F_170 ( V_74 ) , F_171 ( V_74 ) ) ;
F_62 ( ! V_56 -> V_93 ) ;
F_62 ( V_191 != V_192 &&
V_191 != V_193 ) ;
V_49 = F_74 ( V_72 , V_73 , V_74 ) ;
if ( ! V_49 )
return - V_180 ;
V_21 = F_78 ( V_49 , V_73 , V_74 ) ;
if ( ! V_21 )
return - V_108 ;
F_79 ( & V_49 -> V_84 , V_58 ) ;
if ( F_21 ( V_21 ) ) {
F_80 ( & V_49 -> V_84 , V_58 ) ;
return 0 ;
}
V_171 = V_56 -> V_171 ;
V_93 = V_56 -> V_93 ;
if ( V_56 -> V_58 & V_59 ||
V_56 -> V_58 & V_60 ) {
int V_143 = 0 ;
V_162 = F_136 ( V_49 -> V_52 ) ;
F_65 (num, iommu->domain_ids, ndomains) {
if ( V_49 -> V_155 [ V_170 ] == V_56 ) {
V_171 = V_170 ;
V_143 = 1 ;
break;
}
}
if ( V_143 == 0 ) {
V_170 = F_151 ( V_49 -> V_165 , V_162 ) ;
if ( V_170 >= V_162 ) {
F_80 ( & V_49 -> V_84 , V_58 ) ;
F_42 ( V_141 L_19 ) ;
return - V_194 ;
}
F_140 ( V_170 , V_49 -> V_165 ) ;
V_49 -> V_155 [ V_170 ] = V_56 ;
V_171 = V_170 ;
}
if ( V_191 != V_192 ) {
for ( V_1 = V_56 -> V_1 ; V_1 != V_49 -> V_1 ; V_1 -- ) {
V_93 = F_20 ( F_34 ( V_93 ) ) ;
if ( ! F_38 ( V_93 ) ) {
F_80 ( & V_49 -> V_84 , V_58 ) ;
return - V_108 ;
}
}
}
}
F_27 ( V_21 , V_171 ) ;
if ( V_191 != V_192 ) {
V_144 = F_113 ( V_56 , V_72 , V_73 , V_74 ) ;
V_191 = V_144 ? V_195 :
V_193 ;
}
if ( F_172 ( V_191 == V_192 ) )
F_26 ( V_21 , V_49 -> V_196 ) ;
else {
F_25 ( V_21 , F_82 ( V_93 ) ) ;
F_26 ( V_21 , V_49 -> V_1 ) ;
}
F_24 ( V_21 , V_191 ) ;
F_23 ( V_21 ) ;
F_22 ( V_21 ) ;
F_76 ( V_56 , V_21 , sizeof( * V_21 ) ) ;
if ( F_131 ( V_49 -> V_52 ) ) {
V_49 -> V_153 . V_197 ( V_49 , 0 ,
( ( ( T_4 ) V_73 ) << 8 ) | V_74 ,
V_198 ,
V_129 ) ;
V_49 -> V_153 . V_154 ( V_49 , V_56 -> V_171 , 0 , 0 , V_138 ) ;
} else {
F_99 ( V_49 ) ;
}
F_118 ( V_144 ) ;
F_80 ( & V_49 -> V_84 , V_58 ) ;
F_79 ( & V_56 -> V_167 , V_58 ) ;
if ( ! F_173 ( V_49 -> V_164 , V_56 -> V_61 ) ) {
V_56 -> V_168 ++ ;
if ( V_56 -> V_168 == 1 )
V_56 -> V_97 = V_49 -> V_40 ;
F_73 ( V_56 ) ;
}
F_80 ( & V_56 -> V_167 , V_58 ) ;
return 0 ;
}
static int
F_174 ( struct V_55 * V_56 , struct V_172 * V_173 ,
int V_191 )
{
int V_86 ;
struct V_172 * V_106 , * V_91 ;
V_86 = F_169 ( V_56 , F_175 ( V_173 -> V_73 ) ,
V_173 -> V_73 -> V_78 , V_173 -> V_74 ,
V_191 ) ;
if ( V_86 )
return V_86 ;
V_106 = F_176 ( V_173 ) ;
if ( ! V_106 )
return 0 ;
V_91 = V_173 -> V_73 -> V_199 ;
while ( V_91 != V_106 ) {
V_86 = F_169 ( V_56 ,
F_175 ( V_91 -> V_73 ) ,
V_91 -> V_73 -> V_78 ,
V_91 -> V_74 , V_191 ) ;
if ( V_86 )
return V_86 ;
V_91 = V_91 -> V_73 -> V_199 ;
}
if ( F_177 ( V_106 ) )
return F_169 ( V_56 ,
F_175 ( V_106 -> V_79 ) ,
V_106 -> V_79 -> V_78 , 0 ,
V_191 ) ;
else
return F_169 ( V_56 ,
F_175 ( V_106 -> V_73 ) ,
V_106 -> V_73 -> V_78 ,
V_106 -> V_74 ,
V_191 ) ;
}
static int F_178 ( struct V_172 * V_173 )
{
int V_86 ;
struct V_172 * V_106 , * V_91 ;
struct V_48 * V_49 ;
V_49 = F_74 ( F_175 ( V_173 -> V_73 ) , V_173 -> V_73 -> V_78 ,
V_173 -> V_74 ) ;
if ( ! V_49 )
return - V_180 ;
V_86 = F_83 ( V_49 , V_173 -> V_73 -> V_78 , V_173 -> V_74 ) ;
if ( ! V_86 )
return V_86 ;
V_106 = F_176 ( V_173 ) ;
if ( ! V_106 )
return V_86 ;
V_91 = V_173 -> V_73 -> V_199 ;
while ( V_91 != V_106 ) {
V_86 = F_83 ( V_49 , V_91 -> V_73 -> V_78 ,
V_91 -> V_74 ) ;
if ( ! V_86 )
return V_86 ;
V_91 = V_91 -> V_73 -> V_199 ;
}
if ( F_177 ( V_106 ) )
return F_83 ( V_49 , V_106 -> V_79 -> V_78 ,
0 ) ;
else
return F_83 ( V_49 , V_106 -> V_73 -> V_78 ,
V_106 -> V_74 ) ;
}
static inline unsigned long F_179 ( unsigned long V_200 ,
T_5 V_82 )
{
V_200 &= ~ V_201 ;
return F_180 ( V_200 + V_82 ) >> V_10 ;
}
static inline int F_181 ( struct V_55 * V_56 ,
unsigned long V_202 ,
unsigned long V_203 ,
unsigned long V_151 )
{
int V_204 , V_4 = 1 ;
unsigned long V_205 ;
V_204 = V_56 -> V_71 ;
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
static int F_182 ( struct V_55 * V_56 , unsigned long V_202 ,
struct V_208 * V_209 , unsigned long V_210 ,
unsigned long V_211 , int V_30 )
{
struct V_25 * V_104 = NULL , * V_26 = NULL ;
T_6 V_212 ( V_96 ) ;
int V_90 = F_2 ( V_56 -> V_1 ) - V_10 ;
unsigned long V_213 ;
unsigned int V_214 = 0 ;
unsigned long V_215 = 0 ;
F_62 ( V_90 < V_94 && ( V_202 + V_211 - 1 ) > > V_90 ) ;
if ( ( V_30 & ( V_27 | V_28 ) ) == 0 )
return - V_33 ;
V_30 &= V_27 | V_28 | V_29 ;
if ( V_209 )
V_213 = 0 ;
else {
V_213 = V_211 + 1 ;
V_96 = ( ( T_6 ) V_210 << V_10 ) | V_30 ;
}
while ( V_211 > 0 ) {
V_31 V_106 ;
if ( ! V_213 ) {
V_213 = F_179 ( V_209 -> V_92 , V_209 -> V_216 ) ;
V_209 -> V_217 = ( ( V_218 ) V_202 << V_10 ) + V_209 -> V_92 ;
V_209 -> V_219 = V_209 -> V_216 ;
V_96 = F_183 ( F_184 ( V_209 ) ) | V_30 ;
V_210 = V_96 >> V_10 ;
}
if ( ! V_26 ) {
V_214 = F_181 ( V_56 , V_202 , V_210 , V_213 ) ;
V_104 = V_26 = F_86 ( V_56 , V_202 , V_214 ) ;
if ( ! V_26 )
return - V_108 ;
if ( V_214 > 1 )
V_96 |= V_101 ;
else
V_96 &= ~ ( V_31 ) V_101 ;
}
V_106 = F_185 ( & V_26 -> V_17 , 0ULL , V_96 ) ;
if ( V_106 ) {
static int V_220 = 5 ;
F_42 ( V_221 L_24 ,
V_202 , V_106 , ( unsigned long long ) V_96 ) ;
if ( V_220 ) {
V_220 -- ;
F_186 ( NULL ) ;
}
F_187 ( 1 ) ;
}
V_215 = F_9 ( V_214 ) ;
F_62 ( V_211 < V_215 ) ;
F_62 ( V_213 < V_215 ) ;
V_211 -= V_215 ;
V_202 += V_215 ;
V_210 += V_215 ;
V_96 += V_215 * V_98 ;
V_213 -= V_215 ;
V_26 ++ ;
if ( ! V_211 || F_40 ( V_26 ) ||
( V_214 > 1 && V_213 < V_215 ) ) {
F_76 ( V_56 , V_104 ,
( void * ) V_26 - ( void * ) V_104 ) ;
V_26 = NULL ;
}
if ( ! V_213 && V_211 )
V_209 = F_188 ( V_209 ) ;
}
return 0 ;
}
static inline int F_189 ( struct V_55 * V_56 , unsigned long V_202 ,
struct V_208 * V_209 , unsigned long V_211 ,
int V_30 )
{
return F_182 ( V_56 , V_202 , V_209 , 0 , V_211 , V_30 ) ;
}
static inline int F_190 ( struct V_55 * V_56 , unsigned long V_202 ,
unsigned long V_210 , unsigned long V_211 ,
int V_30 )
{
return F_182 ( V_56 , V_202 , NULL , V_210 , V_211 , V_30 ) ;
}
static void F_191 ( struct V_48 * V_49 , T_2 V_73 , T_2 V_74 )
{
if ( ! V_49 )
return;
F_84 ( V_49 , V_73 , V_74 ) ;
V_49 -> V_153 . V_197 ( V_49 , 0 , 0 , 0 ,
V_127 ) ;
V_49 -> V_153 . V_154 ( V_49 , 0 , 0 , 0 , V_136 ) ;
}
static inline void F_192 ( struct V_142 * V_144 )
{
F_193 ( & V_146 ) ;
F_194 ( & V_144 -> V_222 ) ;
F_194 ( & V_144 -> V_223 ) ;
if ( V_144 -> V_147 )
V_144 -> V_147 -> V_147 . V_224 . V_49 = NULL ;
}
static void F_167 ( struct V_55 * V_56 )
{
struct V_142 * V_144 ;
unsigned long V_58 ;
struct V_48 * V_49 ;
F_79 ( & V_146 , V_58 ) ;
while ( ! F_195 ( & V_56 -> V_77 ) ) {
V_144 = F_196 ( V_56 -> V_77 . V_225 ,
struct V_142 , V_222 ) ;
F_192 ( V_144 ) ;
F_80 ( & V_146 , V_58 ) ;
F_120 ( V_144 ) ;
V_49 = F_74 ( V_144 -> V_72 , V_144 -> V_73 , V_144 -> V_74 ) ;
F_191 ( V_49 , V_144 -> V_73 , V_144 -> V_74 ) ;
F_53 ( V_144 ) ;
F_79 ( & V_146 , V_58 ) ;
}
F_80 ( & V_146 , V_58 ) ;
}
static struct V_55 *
F_197 ( struct V_172 * V_173 )
{
struct V_142 * V_144 ;
V_144 = V_173 -> V_147 . V_224 . V_49 ;
if ( V_144 )
return V_144 -> V_56 ;
return NULL ;
}
static struct V_55 * F_198 ( struct V_172 * V_173 , int V_107 )
{
struct V_55 * V_56 , * V_143 = NULL ;
struct V_48 * V_49 ;
struct V_68 * V_69 ;
struct V_142 * V_144 , * V_106 ;
struct V_172 * V_226 ;
unsigned long V_58 ;
int V_73 = 0 , V_74 = 0 ;
int V_72 ;
int V_86 ;
V_56 = F_197 ( V_173 ) ;
if ( V_56 )
return V_56 ;
V_72 = F_175 ( V_173 -> V_73 ) ;
V_226 = F_176 ( V_173 ) ;
if ( V_226 ) {
if ( F_177 ( V_226 ) ) {
V_73 = V_226 -> V_79 -> V_78 ;
V_74 = 0 ;
} else {
V_73 = V_226 -> V_73 -> V_78 ;
V_74 = V_226 -> V_74 ;
}
F_79 ( & V_146 , V_58 ) ;
F_115 (info, &device_domain_list, global) {
if ( V_144 -> V_72 == V_72 &&
V_144 -> V_73 == V_73 && V_144 -> V_74 == V_74 ) {
V_143 = V_144 -> V_56 ;
break;
}
}
F_80 ( & V_146 , V_58 ) ;
if ( V_143 ) {
V_56 = V_143 ;
goto V_227;
}
}
V_56 = F_149 () ;
if ( ! V_56 )
goto error;
V_69 = F_199 ( V_173 ) ;
if ( ! V_69 ) {
F_42 ( V_141 L_25 ,
F_200 ( V_173 ) ) ;
return NULL ;
}
V_49 = V_69 -> V_49 ;
V_86 = F_150 ( V_56 , V_49 ) ;
if ( V_86 ) {
F_50 ( V_56 ) ;
goto error;
}
if ( F_162 ( V_56 , V_107 ) ) {
F_144 ( V_56 ) ;
goto error;
}
if ( V_226 ) {
V_144 = F_52 () ;
if ( ! V_144 ) {
F_144 ( V_56 ) ;
goto error;
}
V_144 -> V_72 = V_72 ;
V_144 -> V_73 = V_73 ;
V_144 -> V_74 = V_74 ;
V_144 -> V_147 = NULL ;
V_144 -> V_56 = V_56 ;
V_56 -> V_58 |= V_228 ;
V_143 = NULL ;
F_79 ( & V_146 , V_58 ) ;
F_115 (tmp, &device_domain_list, global) {
if ( V_106 -> V_72 == V_72 &&
V_106 -> V_73 == V_73 && V_106 -> V_74 == V_74 ) {
V_143 = V_106 -> V_56 ;
break;
}
}
if ( V_143 ) {
F_80 ( & V_146 , V_58 ) ;
F_53 ( V_144 ) ;
F_144 ( V_56 ) ;
V_56 = V_143 ;
} else {
F_201 ( & V_144 -> V_222 , & V_56 -> V_77 ) ;
F_201 ( & V_144 -> V_223 , & V_229 ) ;
F_80 ( & V_146 , V_58 ) ;
}
}
V_227:
V_144 = F_52 () ;
if ( ! V_144 )
goto error;
V_144 -> V_72 = V_72 ;
V_144 -> V_73 = V_173 -> V_73 -> V_78 ;
V_144 -> V_74 = V_173 -> V_74 ;
V_144 -> V_147 = V_173 ;
V_144 -> V_56 = V_56 ;
F_79 ( & V_146 , V_58 ) ;
V_143 = F_197 ( V_173 ) ;
if ( V_143 != NULL ) {
F_80 ( & V_146 , V_58 ) ;
if ( V_143 != V_56 ) {
F_144 ( V_56 ) ;
V_56 = V_143 ;
}
F_53 ( V_144 ) ;
return V_56 ;
}
F_201 ( & V_144 -> V_222 , & V_56 -> V_77 ) ;
F_201 ( & V_144 -> V_223 , & V_229 ) ;
V_173 -> V_147 . V_224 . V_49 = V_144 ;
F_80 ( & V_146 , V_58 ) ;
return V_56 ;
error:
return F_197 ( V_173 ) ;
}
static int F_202 ( struct V_55 * V_56 ,
unsigned long long V_185 ,
unsigned long long V_186 )
{
unsigned long V_230 = V_185 >> V_10 ;
unsigned long V_231 = V_186 >> V_10 ;
if ( ! F_156 ( & V_56 -> V_187 , F_10 ( V_230 ) ,
F_10 ( V_231 ) ) ) {
F_42 ( V_141 L_26 ) ;
return - V_108 ;
}
F_112 ( L_27 ,
V_185 , V_186 , V_56 -> V_171 ) ;
F_89 ( V_56 , V_230 , V_231 ) ;
return F_190 ( V_56 , V_230 , V_230 ,
V_231 - V_230 + 1 ,
V_27 | V_28 ) ;
}
static int F_203 ( struct V_172 * V_173 ,
unsigned long long V_185 ,
unsigned long long V_186 )
{
struct V_55 * V_56 ;
int V_86 ;
V_56 = F_198 ( V_173 , V_54 ) ;
if ( ! V_56 )
return - V_108 ;
if ( V_56 == V_232 && V_233 ) {
F_42 ( L_28 ,
F_200 ( V_173 ) , V_185 , V_186 ) ;
return 0 ;
}
F_42 ( V_35
L_29 ,
F_200 ( V_173 ) , V_185 , V_186 ) ;
if ( V_186 < V_185 ) {
F_204 ( 1 , L_30
L_31 ,
F_205 ( V_234 ) ,
F_205 ( V_235 ) ,
F_205 ( V_236 ) ) ;
V_86 = - V_237 ;
goto error;
}
if ( V_186 >> F_2 ( V_56 -> V_1 ) ) {
F_204 ( 1 , L_32
L_31 ,
F_2 ( V_56 -> V_1 ) ,
F_205 ( V_234 ) ,
F_205 ( V_235 ) ,
F_205 ( V_236 ) ) ;
V_86 = - V_237 ;
goto error;
}
V_86 = F_202 ( V_56 , V_185 , V_186 ) ;
if ( V_86 )
goto error;
V_86 = F_174 ( V_56 , V_173 , V_193 ) ;
if ( V_86 )
goto error;
return 0 ;
error:
F_144 ( V_56 ) ;
return V_86 ;
}
static inline int F_206 ( struct V_238 * V_239 ,
struct V_172 * V_173 )
{
if ( V_173 -> V_147 . V_224 . V_49 == V_240 )
return 0 ;
return F_203 ( V_173 , V_239 -> V_241 ,
V_239 -> V_242 ) ;
}
static inline void F_207 ( void )
{
struct V_172 * V_173 ;
int V_86 ;
V_173 = F_208 ( V_243 << 8 , NULL ) ;
if ( ! V_173 )
return;
F_42 ( V_35 L_33 ) ;
V_86 = F_203 ( V_173 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_86 )
F_42 ( V_141 L_34
L_35 ) ;
}
static inline void F_207 ( void )
{
return;
}
static int T_1 F_209 ( int V_244 )
{
struct V_68 * V_69 ;
struct V_48 * V_49 ;
int V_97 , V_86 = 0 ;
V_232 = F_149 () ;
if ( ! V_232 )
return - V_194 ;
F_112 ( L_36 , V_232 -> V_171 ) ;
F_70 (iommu, drhd) {
V_86 = F_150 ( V_232 , V_49 ) ;
if ( V_86 ) {
F_144 ( V_232 ) ;
return - V_194 ;
}
}
if ( F_210 ( V_232 , V_54 ) ) {
F_144 ( V_232 ) ;
return - V_194 ;
}
V_232 -> V_58 = V_60 ;
if ( V_244 )
return 0 ;
F_211 (nid) {
unsigned long V_102 , V_245 ;
int V_64 ;
F_212 (i, nid, &start_pfn, &end_pfn, NULL) {
V_86 = F_202 ( V_232 ,
F_213 ( V_102 ) , F_213 ( V_245 ) ) ;
if ( V_86 )
return V_86 ;
}
}
return 0 ;
}
static int F_214 ( struct V_172 * V_173 )
{
struct V_142 * V_144 ;
if ( F_215 ( ! V_246 ) )
return 0 ;
V_144 = V_173 -> V_147 . V_224 . V_49 ;
if ( V_144 && V_144 != V_240 )
return ( V_144 -> V_56 == V_232 ) ;
return 0 ;
}
static int F_216 ( struct V_55 * V_56 ,
struct V_172 * V_173 ,
int V_191 )
{
struct V_142 * V_144 ;
unsigned long V_58 ;
int V_86 ;
V_144 = F_52 () ;
if ( ! V_144 )
return - V_108 ;
V_144 -> V_72 = F_175 ( V_173 -> V_73 ) ;
V_144 -> V_73 = V_173 -> V_73 -> V_78 ;
V_144 -> V_74 = V_173 -> V_74 ;
V_144 -> V_147 = V_173 ;
V_144 -> V_56 = V_56 ;
F_79 ( & V_146 , V_58 ) ;
F_201 ( & V_144 -> V_222 , & V_56 -> V_77 ) ;
F_201 ( & V_144 -> V_223 , & V_229 ) ;
V_173 -> V_147 . V_224 . V_49 = V_144 ;
F_80 ( & V_146 , V_58 ) ;
V_86 = F_174 ( V_56 , V_173 , V_191 ) ;
if ( V_86 ) {
F_79 ( & V_146 , V_58 ) ;
F_192 ( V_144 ) ;
F_80 ( & V_146 , V_58 ) ;
F_53 ( V_144 ) ;
return V_86 ;
}
return 0 ;
}
static int F_217 ( struct V_172 * V_173 , int V_247 )
{
if ( ( V_246 & V_248 ) && F_218 ( V_173 ) )
return 1 ;
if ( ( V_246 & V_249 ) && F_219 ( V_173 ) )
return 1 ;
if ( ! ( V_246 & V_250 ) )
return 0 ;
if ( ! F_177 ( V_173 ) ) {
if ( ! F_220 ( V_173 -> V_73 ) )
return 0 ;
if ( V_173 -> V_251 >> 8 == V_252 )
return 0 ;
} else if ( V_173 -> V_253 == V_254 )
return 0 ;
if ( ! V_247 ) {
V_23 V_255 = V_173 -> V_255 ;
if ( V_173 -> V_147 . V_256 &&
V_173 -> V_147 . V_256 < V_255 )
V_255 = V_173 -> V_147 . V_256 ;
return V_255 >= F_221 ( & V_173 -> V_147 ) ;
}
return 1 ;
}
static int T_1 F_222 ( int V_244 )
{
struct V_172 * V_173 = NULL ;
int V_86 ;
V_86 = F_209 ( V_244 ) ;
if ( V_86 )
return - V_194 ;
F_158 (pdev) {
if ( F_217 ( V_173 , 1 ) ) {
V_86 = F_216 ( V_232 , V_173 ,
V_244 ? V_192 :
V_193 ) ;
if ( V_86 ) {
if ( V_86 == - V_180 )
continue;
return V_86 ;
}
F_223 ( L_37 ,
V_244 ? L_38 : L_39 , F_200 ( V_173 ) ) ;
}
}
return 0 ;
}
static int T_1 F_224 ( void )
{
struct V_68 * V_69 ;
struct V_238 * V_239 ;
struct V_172 * V_173 ;
struct V_48 * V_49 ;
int V_64 , V_86 ;
F_75 (drhd) {
if ( V_62 < V_257 ) {
V_62 ++ ;
continue;
}
F_225 ( V_141 L_40 ,
V_257 ) ;
}
V_63 = F_139 ( V_62 , sizeof( struct V_48 * ) ,
V_166 ) ;
if ( ! V_63 ) {
F_42 ( V_141 L_41 ) ;
V_86 = - V_108 ;
goto error;
}
V_258 = F_226 ( V_62 *
sizeof( struct V_259 ) , V_166 ) ;
if ( ! V_258 ) {
V_86 = - V_108 ;
goto error;
}
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
V_63 [ V_49 -> V_164 ] = V_49 ;
V_86 = F_135 ( V_49 ) ;
if ( V_86 )
goto error;
V_86 = F_92 ( V_49 ) ;
if ( V_86 ) {
F_42 ( V_141 L_42 ) ;
goto error;
}
if ( ! F_227 ( V_49 -> V_66 ) )
V_233 = 0 ;
}
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
if ( V_49 -> V_145 )
continue;
F_228 ( - 1 , V_49 ) ;
F_229 ( V_49 ) ;
}
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
if ( F_230 ( V_49 ) ) {
V_49 -> V_153 . V_197 = F_101 ;
V_49 -> V_153 . V_154 = F_106 ;
F_42 ( V_35 L_43
L_44 ,
V_49 -> V_164 ,
( unsigned long long ) V_69 -> V_260 ) ;
} else {
V_49 -> V_153 . V_197 = V_261 ;
V_49 -> V_153 . V_154 = V_262 ;
F_42 ( V_35 L_45
L_44 ,
V_49 -> V_164 ,
( unsigned long long ) V_69 -> V_260 ) ;
}
}
if ( V_263 )
V_246 |= V_250 ;
#ifdef F_231
V_246 |= V_249 ;
#endif
F_232 () ;
if ( V_246 ) {
V_86 = F_222 ( V_233 ) ;
if ( V_86 ) {
F_42 ( V_221 L_46 ) ;
goto error;
}
}
F_42 ( V_35 L_47 ) ;
F_233 (rmrr) {
for ( V_64 = 0 ; V_64 < V_239 -> V_76 ; V_64 ++ ) {
V_173 = V_239 -> V_77 [ V_64 ] ;
if ( ! V_173 )
continue;
V_86 = F_206 ( V_239 , V_173 ) ;
if ( V_86 )
F_42 ( V_141
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
V_86 = F_234 ( V_49 ) ;
if ( V_86 )
goto error;
F_93 ( V_49 ) ;
V_49 -> V_153 . V_197 ( V_49 , 0 , 0 , 0 , V_127 ) ;
V_49 -> V_153 . V_154 ( V_49 , 0 , 0 , 0 , V_136 ) ;
V_86 = F_133 ( V_49 ) ;
if ( V_86 )
goto error;
F_132 ( V_49 ) ;
}
return 0 ;
error:
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
F_235 ( V_49 ) ;
}
F_148 ( V_63 ) ;
return V_86 ;
}
static struct V_46 * F_236 ( struct V_265 * V_147 ,
struct V_55 * V_56 ,
unsigned long V_266 , V_31 V_255 )
{
struct V_172 * V_173 = F_237 ( V_147 ) ;
struct V_46 * V_46 = NULL ;
V_255 = F_238 ( V_31 , F_239 ( V_56 -> V_107 ) , V_255 ) ;
if ( ! V_37 && V_255 > F_240 ( 32 ) ) {
V_46 = F_241 ( & V_56 -> V_187 , V_266 ,
F_157 ( F_240 ( 32 ) ) , 1 ) ;
if ( V_46 )
return V_46 ;
}
V_46 = F_241 ( & V_56 -> V_187 , V_266 , F_157 ( V_255 ) , 1 ) ;
if ( F_172 ( ! V_46 ) ) {
F_42 ( V_141 L_49 ,
V_266 , F_200 ( V_173 ) ) ;
return NULL ;
}
return V_46 ;
}
static struct V_55 * F_242 ( struct V_172 * V_173 )
{
struct V_55 * V_56 ;
int V_86 ;
V_56 = F_198 ( V_173 ,
V_54 ) ;
if ( ! V_56 ) {
F_42 ( V_141
L_50 , F_200 ( V_173 ) ) ;
return NULL ;
}
if ( F_172 ( ! F_178 ( V_173 ) ) ) {
V_86 = F_174 ( V_56 , V_173 ,
V_193 ) ;
if ( V_86 ) {
F_42 ( V_141
L_51 ,
F_200 ( V_173 ) ) ;
return NULL ;
}
}
return V_56 ;
}
static inline struct V_55 * F_243 ( struct V_172 * V_147 )
{
struct V_142 * V_144 ;
V_144 = V_147 -> V_147 . V_224 . V_49 ;
if ( F_215 ( V_144 ) )
return V_144 -> V_56 ;
return F_242 ( V_147 ) ;
}
static int F_244 ( struct V_172 * V_173 )
{
return V_173 -> V_147 . V_224 . V_49 == V_240 ;
}
static int F_245 ( struct V_265 * V_147 )
{
struct V_172 * V_173 ;
int V_143 ;
if ( F_172 ( V_147 -> V_73 != & V_267 ) )
return 1 ;
V_173 = F_237 ( V_147 ) ;
if ( F_244 ( V_173 ) )
return 1 ;
if ( ! V_246 )
return 0 ;
V_143 = F_214 ( V_173 ) ;
if ( V_143 ) {
if ( F_217 ( V_173 , 0 ) )
return 1 ;
else {
F_246 ( V_232 , V_173 ) ;
F_42 ( V_35 L_52 ,
F_200 ( V_173 ) ) ;
return 0 ;
}
} else {
if ( F_217 ( V_173 , 0 ) ) {
int V_86 ;
V_86 = F_216 ( V_232 , V_173 ,
V_233 ?
V_192 :
V_193 ) ;
if ( ! V_86 ) {
F_42 ( V_35 L_53 ,
F_200 ( V_173 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_218 F_247 ( struct V_265 * V_268 , T_6 V_269 ,
T_5 V_82 , int V_270 , V_23 V_255 )
{
struct V_172 * V_173 = F_237 ( V_268 ) ;
struct V_55 * V_56 ;
T_6 V_271 ;
struct V_46 * V_46 ;
int V_30 = 0 ;
int V_86 ;
struct V_48 * V_49 ;
unsigned long V_272 = V_269 >> V_9 ;
F_62 ( V_270 == V_273 ) ;
if ( F_245 ( V_268 ) )
return V_269 ;
V_56 = F_243 ( V_173 ) ;
if ( ! V_56 )
return 0 ;
V_49 = F_61 ( V_56 ) ;
V_82 = F_179 ( V_269 , V_82 ) ;
V_46 = F_236 ( V_268 , V_56 , F_10 ( V_82 ) , V_255 ) ;
if ( ! V_46 )
goto error;
if ( V_270 == V_274 || V_270 == V_275 || \
! F_248 ( V_49 -> V_52 ) )
V_30 |= V_27 ;
if ( V_270 == V_276 || V_270 == V_275 )
V_30 |= V_28 ;
V_86 = F_190 ( V_56 , F_11 ( V_46 -> V_277 ) ,
F_11 ( V_272 ) , V_82 , V_30 ) ;
if ( V_86 )
goto error;
if ( F_131 ( V_49 -> V_52 ) )
F_126 ( V_49 , V_56 -> V_171 , F_11 ( V_46 -> V_277 ) , V_82 , 1 ) ;
else
F_99 ( V_49 ) ;
V_271 = ( T_6 ) V_46 -> V_277 << V_9 ;
V_271 += V_269 & ~ V_201 ;
return V_271 ;
error:
if ( V_46 )
F_249 ( & V_56 -> V_187 , V_46 ) ;
F_42 ( V_141 L_54 ,
F_200 ( V_173 ) , V_82 , ( unsigned long long ) V_269 , V_270 ) ;
return 0 ;
}
static V_218 F_250 ( struct V_265 * V_147 , struct V_12 * V_12 ,
unsigned long V_92 , T_5 V_82 ,
enum V_278 V_270 ,
struct V_279 * V_280 )
{
return F_247 ( V_147 , F_183 ( V_12 ) + V_92 , V_82 ,
V_270 , F_237 ( V_147 ) -> V_255 ) ;
}
static void F_251 ( void )
{
int V_64 , V_281 ;
V_282 = 0 ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
struct V_48 * V_49 = V_63 [ V_64 ] ;
if ( ! V_49 )
continue;
if ( ! V_258 [ V_64 ] . V_225 )
continue;
if ( ! F_131 ( V_49 -> V_52 ) )
V_49 -> V_153 . V_154 ( V_49 , 0 , 0 , 0 ,
V_136 ) ;
for ( V_281 = 0 ; V_281 < V_258 [ V_64 ] . V_225 ; V_281 ++ ) {
unsigned long V_70 ;
struct V_46 * V_46 = V_258 [ V_64 ] . V_46 [ V_281 ] ;
struct V_55 * V_56 = V_258 [ V_64 ] . V_56 [ V_281 ] ;
if ( F_131 ( V_49 -> V_52 ) )
F_126 ( V_49 , V_56 -> V_171 ,
V_46 -> V_277 , V_46 -> V_283 - V_46 -> V_277 + 1 , 0 ) ;
else {
V_70 = F_127 ( F_11 ( V_46 -> V_283 - V_46 -> V_277 + 1 ) ) ;
F_123 ( V_258 [ V_64 ] . V_56 [ V_281 ] ,
( V_31 ) V_46 -> V_277 << V_9 , V_70 ) ;
}
F_249 ( & V_258 [ V_64 ] . V_56 [ V_281 ] -> V_187 , V_46 ) ;
}
V_258 [ V_64 ] . V_225 = 0 ;
}
V_284 = 0 ;
}
static void F_166 ( unsigned long V_285 )
{
unsigned long V_58 ;
F_79 ( & V_286 , V_58 ) ;
F_251 () ;
F_80 ( & V_286 , V_58 ) ;
}
static void F_252 ( struct V_55 * V_287 , struct V_46 * V_46 )
{
unsigned long V_58 ;
int V_225 , V_57 ;
struct V_48 * V_49 ;
F_79 ( & V_286 , V_58 ) ;
if ( V_284 == V_288 )
F_251 () ;
V_49 = F_61 ( V_287 ) ;
V_57 = V_49 -> V_164 ;
V_225 = V_258 [ V_57 ] . V_225 ;
V_258 [ V_57 ] . V_56 [ V_225 ] = V_287 ;
V_258 [ V_57 ] . V_46 [ V_225 ] = V_46 ;
V_258 [ V_57 ] . V_225 ++ ;
if ( ! V_282 ) {
F_253 ( & V_289 , V_290 + F_254 ( 10 ) ) ;
V_282 = 1 ;
}
V_284 ++ ;
F_80 ( & V_286 , V_58 ) ;
}
static void F_255 ( struct V_265 * V_147 , V_218 V_291 ,
T_5 V_82 , enum V_278 V_270 ,
struct V_279 * V_280 )
{
struct V_172 * V_173 = F_237 ( V_147 ) ;
struct V_55 * V_56 ;
unsigned long V_102 , V_103 ;
struct V_46 * V_46 ;
struct V_48 * V_49 ;
if ( F_245 ( V_147 ) )
return;
V_56 = F_197 ( V_173 ) ;
F_62 ( ! V_56 ) ;
V_49 = F_61 ( V_56 ) ;
V_46 = F_256 ( & V_56 -> V_187 , F_157 ( V_291 ) ) ;
if ( F_257 ( ! V_46 , L_55 ,
( unsigned long long ) V_291 ) )
return;
V_102 = F_11 ( V_46 -> V_277 ) ;
V_103 = F_11 ( V_46 -> V_283 + 1 ) - 1 ;
F_112 ( L_56 ,
F_200 ( V_173 ) , V_102 , V_103 ) ;
F_89 ( V_56 , V_102 , V_103 ) ;
F_90 ( V_56 , V_102 , V_103 ) ;
if ( V_38 ) {
F_126 ( V_49 , V_56 -> V_171 , V_102 ,
V_103 - V_102 + 1 , 0 ) ;
F_249 ( & V_56 -> V_187 , V_46 ) ;
} else {
F_252 ( V_56 , V_46 ) ;
}
}
static void * F_258 ( struct V_265 * V_268 , T_5 V_82 ,
V_218 * V_292 , T_7 V_58 ,
struct V_279 * V_280 )
{
void * V_41 ;
int V_105 ;
V_82 = F_180 ( V_82 ) ;
V_105 = F_259 ( V_82 ) ;
if ( ! F_245 ( V_268 ) )
V_58 &= ~ ( V_293 | V_294 ) ;
else if ( V_268 -> V_256 < F_221 ( V_268 ) ) {
if ( V_268 -> V_256 < F_240 ( 32 ) )
V_58 |= V_293 ;
else
V_58 |= V_294 ;
}
V_41 = ( void * ) F_260 ( V_58 , V_105 ) ;
if ( ! V_41 )
return NULL ;
memset ( V_41 , 0 , V_82 ) ;
* V_292 = F_247 ( V_268 , F_261 ( V_41 ) , V_82 ,
V_275 ,
V_268 -> V_256 ) ;
if ( * V_292 )
return V_41 ;
F_262 ( ( unsigned long ) V_41 , V_105 ) ;
return NULL ;
}
static void F_263 ( struct V_265 * V_268 , T_5 V_82 , void * V_41 ,
V_218 V_292 , struct V_279 * V_280 )
{
int V_105 ;
V_82 = F_180 ( V_82 ) ;
V_105 = F_259 ( V_82 ) ;
F_255 ( V_268 , V_292 , V_82 , V_275 , NULL ) ;
F_262 ( ( unsigned long ) V_41 , V_105 ) ;
}
static void F_264 ( struct V_265 * V_268 , struct V_208 * V_295 ,
int V_296 , enum V_278 V_270 ,
struct V_279 * V_280 )
{
struct V_172 * V_173 = F_237 ( V_268 ) ;
struct V_55 * V_56 ;
unsigned long V_102 , V_103 ;
struct V_46 * V_46 ;
struct V_48 * V_49 ;
if ( F_245 ( V_268 ) )
return;
V_56 = F_197 ( V_173 ) ;
F_62 ( ! V_56 ) ;
V_49 = F_61 ( V_56 ) ;
V_46 = F_256 ( & V_56 -> V_187 , F_157 ( V_295 [ 0 ] . V_217 ) ) ;
if ( F_257 ( ! V_46 , L_57 ,
( unsigned long long ) V_295 [ 0 ] . V_217 ) )
return;
V_102 = F_11 ( V_46 -> V_277 ) ;
V_103 = F_11 ( V_46 -> V_283 + 1 ) - 1 ;
F_89 ( V_56 , V_102 , V_103 ) ;
F_90 ( V_56 , V_102 , V_103 ) ;
if ( V_38 ) {
F_126 ( V_49 , V_56 -> V_171 , V_102 ,
V_103 - V_102 + 1 , 0 ) ;
F_249 ( & V_56 -> V_187 , V_46 ) ;
} else {
F_252 ( V_56 , V_46 ) ;
}
}
static int F_265 ( struct V_265 * V_297 ,
struct V_208 * V_295 , int V_296 , int V_270 )
{
int V_64 ;
struct V_208 * V_209 ;
F_266 (sglist, sg, nelems, i) {
F_62 ( ! F_184 ( V_209 ) ) ;
V_209 -> V_217 = F_183 ( F_184 ( V_209 ) ) + V_209 -> V_92 ;
V_209 -> V_219 = V_209 -> V_216 ;
}
return V_296 ;
}
static int F_267 ( struct V_265 * V_268 , struct V_208 * V_295 , int V_296 ,
enum V_278 V_270 , struct V_279 * V_280 )
{
int V_64 ;
struct V_172 * V_173 = F_237 ( V_268 ) ;
struct V_55 * V_56 ;
T_5 V_82 = 0 ;
int V_30 = 0 ;
struct V_46 * V_46 = NULL ;
int V_86 ;
struct V_208 * V_209 ;
unsigned long V_298 ;
struct V_48 * V_49 ;
F_62 ( V_270 == V_273 ) ;
if ( F_245 ( V_268 ) )
return F_265 ( V_268 , V_295 , V_296 , V_270 ) ;
V_56 = F_243 ( V_173 ) ;
if ( ! V_56 )
return 0 ;
V_49 = F_61 ( V_56 ) ;
F_266 (sglist, sg, nelems, i)
V_82 += F_179 ( V_209 -> V_92 , V_209 -> V_216 ) ;
V_46 = F_236 ( V_268 , V_56 , F_10 ( V_82 ) ,
V_173 -> V_255 ) ;
if ( ! V_46 ) {
V_295 -> V_219 = 0 ;
return 0 ;
}
if ( V_270 == V_274 || V_270 == V_275 || \
! F_248 ( V_49 -> V_52 ) )
V_30 |= V_27 ;
if ( V_270 == V_276 || V_270 == V_275 )
V_30 |= V_28 ;
V_298 = F_11 ( V_46 -> V_277 ) ;
V_86 = F_189 ( V_56 , V_298 , V_295 , V_82 , V_30 ) ;
if ( F_172 ( V_86 ) ) {
F_89 ( V_56 , V_298 ,
V_298 + V_82 - 1 ) ;
F_90 ( V_56 , V_298 ,
V_298 + V_82 - 1 ) ;
F_249 ( & V_56 -> V_187 , V_46 ) ;
return 0 ;
}
if ( F_131 ( V_49 -> V_52 ) )
F_126 ( V_49 , V_56 -> V_171 , V_298 , V_82 , 1 ) ;
else
F_99 ( V_49 ) ;
return V_296 ;
}
static int F_268 ( struct V_265 * V_147 , V_218 V_299 )
{
return ! V_299 ;
}
static inline int F_269 ( void )
{
int V_86 = 0 ;
V_44 = F_270 ( L_58 ,
sizeof( struct V_55 ) ,
0 ,
V_300 ,
NULL ) ;
if ( ! V_44 ) {
F_42 ( V_141 L_59 ) ;
V_86 = - V_108 ;
}
return V_86 ;
}
static inline int F_271 ( void )
{
int V_86 = 0 ;
V_45 = F_270 ( L_60 ,
sizeof( struct V_142 ) ,
0 ,
V_300 ,
NULL ) ;
if ( ! V_45 ) {
F_42 ( V_141 L_61 ) ;
V_86 = - V_108 ;
}
return V_86 ;
}
static inline int F_272 ( void )
{
int V_86 = 0 ;
V_47 = F_270 ( L_62 ,
sizeof( struct V_46 ) ,
0 ,
V_300 ,
NULL ) ;
if ( ! V_47 ) {
F_42 ( V_141 L_63 ) ;
V_86 = - V_108 ;
}
return V_86 ;
}
static int T_1 F_273 ( void )
{
int V_86 ;
V_86 = F_272 () ;
if ( V_86 )
return V_86 ;
V_86 = F_269 () ;
if ( V_86 )
goto V_301;
V_86 = F_271 () ;
if ( ! V_86 )
return V_86 ;
F_274 ( V_44 ) ;
V_301:
F_274 ( V_47 ) ;
return - V_108 ;
}
static void T_1 F_275 ( void )
{
F_274 ( V_45 ) ;
F_274 ( V_44 ) ;
F_274 ( V_47 ) ;
}
static void F_276 ( struct V_172 * V_173 )
{
struct V_68 * V_69 ;
T_3 V_302 ;
int V_303 ;
V_303 = F_277 ( V_173 -> V_73 , F_278 ( 0 , 0 ) , 0xb0 , & V_302 ) ;
if ( V_303 ) {
F_279 ( & V_173 -> V_147 , L_64 ) ;
return;
}
V_302 &= 0xffff0000 ;
V_69 = F_199 ( V_173 ) ;
if ( F_280 ( ! V_69 || V_69 -> V_260 - V_302 != 0xa000 ,
V_304 ,
L_65 ) )
V_173 -> V_147 . V_224 . V_49 = V_240 ;
}
static void T_1 F_281 ( void )
{
struct V_68 * V_69 ;
F_75 (drhd) {
if ( ! V_69 -> V_80 ) {
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
if ( V_69 -> V_75 || V_69 -> V_80 )
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
V_69 -> V_77 [ V_64 ] -> V_147 . V_224 . V_49 = V_240 ;
}
}
}
}
static int F_282 ( void )
{
struct V_68 * V_69 ;
struct V_48 * V_49 = NULL ;
F_70 (iommu, drhd)
if ( V_49 -> V_145 )
F_283 ( V_49 ) ;
F_284 (iommu, drhd) {
if ( V_69 -> V_75 ) {
if ( V_264 )
F_132 ( V_49 ) ;
continue;
}
F_99 ( V_49 ) ;
F_93 ( V_49 ) ;
V_49 -> V_153 . V_197 ( V_49 , 0 , 0 , 0 ,
V_127 ) ;
V_49 -> V_153 . V_154 ( V_49 , 0 , 0 , 0 ,
V_136 ) ;
if ( F_133 ( V_49 ) )
return 1 ;
F_132 ( V_49 ) ;
}
return 0 ;
}
static void F_285 ( void )
{
struct V_68 * V_69 ;
struct V_48 * V_49 ;
F_70 (iommu, drhd) {
V_49 -> V_153 . V_197 ( V_49 , 0 , 0 , 0 ,
V_127 ) ;
V_49 -> V_153 . V_154 ( V_49 , 0 , 0 , 0 ,
V_136 ) ;
}
}
static int F_286 ( void )
{
struct V_68 * V_69 ;
struct V_48 * V_49 = NULL ;
unsigned long V_111 ;
F_70 (iommu, drhd) {
V_49 -> V_306 = F_226 ( sizeof( T_3 ) * V_307 ,
V_42 ) ;
if ( ! V_49 -> V_306 )
goto V_308;
}
F_285 () ;
F_70 (iommu, drhd) {
F_134 ( V_49 ) ;
F_94 ( & V_49 -> V_112 , V_111 ) ;
V_49 -> V_306 [ V_309 ] =
V_119 ( V_49 -> V_113 + V_310 ) ;
V_49 -> V_306 [ V_311 ] =
V_119 ( V_49 -> V_113 + V_312 ) ;
V_49 -> V_306 [ V_313 ] =
V_119 ( V_49 -> V_113 + V_314 ) ;
V_49 -> V_306 [ V_315 ] =
V_119 ( V_49 -> V_113 + V_316 ) ;
F_98 ( & V_49 -> V_112 , V_111 ) ;
}
return 0 ;
V_308:
F_70 (iommu, drhd)
F_148 ( V_49 -> V_306 ) ;
return - V_108 ;
}
static void F_287 ( void )
{
struct V_68 * V_69 ;
struct V_48 * V_49 = NULL ;
unsigned long V_111 ;
if ( F_282 () ) {
if ( V_264 )
F_288 ( L_66 ) ;
else
F_204 ( 1 , L_67 ) ;
return;
}
F_70 (iommu, drhd) {
F_94 ( & V_49 -> V_112 , V_111 ) ;
F_96 ( V_49 -> V_306 [ V_309 ] ,
V_49 -> V_113 + V_310 ) ;
F_96 ( V_49 -> V_306 [ V_311 ] ,
V_49 -> V_113 + V_312 ) ;
F_96 ( V_49 -> V_306 [ V_313 ] ,
V_49 -> V_113 + V_314 ) ;
F_96 ( V_49 -> V_306 [ V_315 ] ,
V_49 -> V_113 + V_316 ) ;
F_98 ( & V_49 -> V_112 , V_111 ) ;
}
F_70 (iommu, drhd)
F_148 ( V_49 -> V_306 ) ;
}
static void T_1 F_289 ( void )
{
F_290 ( & V_317 ) ;
}
static inline void F_289 ( void ) {}
static void T_1 F_291 ( struct V_238 * V_239 )
{
F_201 ( & V_239 -> V_318 , & V_319 ) ;
}
int T_1 F_292 ( struct V_320 * V_321 )
{
struct V_322 * V_239 ;
struct V_238 * V_323 ;
V_323 = F_226 ( sizeof( * V_323 ) , V_166 ) ;
if ( ! V_323 )
return - V_108 ;
V_323 -> V_324 = V_321 ;
V_239 = (struct V_322 * ) V_321 ;
V_323 -> V_241 = V_239 -> V_241 ;
V_323 -> V_242 = V_239 -> V_242 ;
F_291 ( V_323 ) ;
return 0 ;
}
static int T_1
F_293 ( struct V_238 * V_323 )
{
struct V_322 * V_239 ;
int V_86 ;
V_239 = (struct V_322 * ) V_323 -> V_324 ;
V_86 = F_294 ( ( void * ) ( V_239 + 1 ) ,
( ( void * ) V_239 ) + V_239 -> V_321 . V_216 ,
& V_323 -> V_76 , & V_323 -> V_77 , V_239 -> V_72 ) ;
if ( V_86 || ( V_323 -> V_76 == 0 ) ) {
F_194 ( & V_323 -> V_318 ) ;
F_148 ( V_323 ) ;
}
return V_86 ;
}
int T_1 F_295 ( struct V_320 * V_324 )
{
struct V_325 * V_326 ;
struct V_327 * V_328 ;
V_326 = F_296 ( V_324 , struct V_325 , V_321 ) ;
V_328 = F_226 ( sizeof( * V_328 ) , V_166 ) ;
if ( ! V_328 )
return - V_108 ;
V_328 -> V_324 = V_324 ;
V_328 -> V_80 = V_326 -> V_58 & 0x1 ;
F_201 ( & V_328 -> V_318 , & V_329 ) ;
return 0 ;
}
static int T_1 F_297 ( struct V_327 * V_328 )
{
int V_303 ;
struct V_325 * V_326 ;
if ( V_328 -> V_80 )
return 0 ;
V_326 = F_296 ( V_328 -> V_324 , struct V_325 , V_321 ) ;
V_303 = F_294 ( ( void * ) ( V_326 + 1 ) ,
( void * ) V_326 + V_326 -> V_321 . V_216 ,
& V_328 -> V_76 , & V_328 -> V_77 ,
V_326 -> V_72 ) ;
if ( V_303 || ! V_328 -> V_76 ) {
F_194 ( & V_328 -> V_318 ) ;
F_148 ( V_328 ) ;
}
return V_303 ;
}
int F_117 ( struct V_172 * V_147 )
{
int V_64 ;
struct V_330 * V_73 ;
struct V_325 * V_326 ;
struct V_327 * V_328 ;
V_147 = F_298 ( V_147 ) ;
F_115 (atsru, &dmar_atsr_units, list) {
V_326 = F_296 ( V_328 -> V_324 , struct V_325 , V_321 ) ;
if ( V_326 -> V_72 == F_175 ( V_147 -> V_73 ) )
goto V_143;
}
return 0 ;
V_143:
for ( V_73 = V_147 -> V_73 ; V_73 ; V_73 = V_73 -> V_91 ) {
struct V_172 * V_331 = V_73 -> V_199 ;
if ( ! V_331 || ! F_177 ( V_331 ) ||
V_331 -> V_253 == V_254 )
return 0 ;
if ( V_331 -> V_253 == V_332 ) {
for ( V_64 = 0 ; V_64 < V_328 -> V_76 ; V_64 ++ )
if ( V_328 -> V_77 [ V_64 ] == V_331 )
return 1 ;
break;
}
}
if ( V_328 -> V_80 )
return 1 ;
return 0 ;
}
int T_1 F_299 ( void )
{
struct V_238 * V_239 , * V_333 ;
struct V_327 * V_326 , * V_334 ;
int V_86 = 0 ;
F_300 (rmrr, rmrr_n, &dmar_rmrr_units, list) {
V_86 = F_293 ( V_239 ) ;
if ( V_86 )
return V_86 ;
}
F_300 (atsr, atsr_n, &dmar_atsr_units, list) {
V_86 = F_297 ( V_326 ) ;
if ( V_86 )
return V_86 ;
}
return V_86 ;
}
static int F_301 ( struct V_335 * V_336 ,
unsigned long V_337 , void * V_285 )
{
struct V_265 * V_147 = V_285 ;
struct V_172 * V_173 = F_237 ( V_147 ) ;
struct V_55 * V_56 ;
if ( F_245 ( V_147 ) )
return 0 ;
V_56 = F_197 ( V_173 ) ;
if ( ! V_56 )
return 0 ;
if ( V_337 == V_338 && ! V_263 ) {
F_246 ( V_56 , V_173 ) ;
if ( ! ( V_56 -> V_58 & V_59 ) &&
! ( V_56 -> V_58 & V_60 ) &&
F_195 ( & V_56 -> V_77 ) )
F_144 ( V_56 ) ;
}
return 0 ;
}
int T_1 F_302 ( void )
{
int V_86 = 0 ;
V_264 = F_303 () ;
if ( F_304 () ) {
if ( V_264 )
F_288 ( L_68 ) ;
return - V_180 ;
}
if ( F_305 () < 0 ) {
if ( V_264 )
F_288 ( L_69 ) ;
return - V_180 ;
}
if ( V_339 || V_34 )
return - V_180 ;
if ( F_273 () ) {
if ( V_264 )
F_288 ( L_70 ) ;
return - V_180 ;
}
if ( F_195 ( & V_319 ) )
F_42 ( V_35 L_71 ) ;
if ( F_195 ( & V_329 ) )
F_42 ( V_35 L_72 ) ;
if ( F_153 () ) {
if ( V_264 )
F_288 ( L_73 ) ;
return - V_180 ;
}
F_281 () ;
V_86 = F_224 () ;
if ( V_86 ) {
if ( V_264 )
F_288 ( L_74 ) ;
F_42 ( V_141 L_75 ) ;
F_168 ( & V_174 ) ;
F_275 () ;
return V_86 ;
}
F_42 ( V_35
L_76 ) ;
F_306 ( & V_289 ) ;
#ifdef F_307
V_340 = 0 ;
#endif
V_341 = & V_342 ;
F_289 () ;
F_308 ( & V_267 , & V_343 ) ;
F_309 ( & V_267 , & V_344 ) ;
V_345 = 1 ;
return 0 ;
}
static void F_310 ( struct V_48 * V_49 ,
struct V_172 * V_173 )
{
struct V_172 * V_106 , * V_91 ;
if ( ! V_49 || ! V_173 )
return;
V_106 = F_176 ( V_173 ) ;
if ( V_106 ) {
V_91 = V_173 -> V_73 -> V_199 ;
while ( V_91 != V_106 ) {
F_191 ( V_49 , V_91 -> V_73 -> V_78 ,
V_91 -> V_74 ) ;
V_91 = V_91 -> V_73 -> V_199 ;
}
if ( F_177 ( V_106 ) )
F_191 ( V_49 ,
V_106 -> V_79 -> V_78 , 0 ) ;
else
F_191 ( V_49 , V_106 -> V_73 -> V_78 ,
V_106 -> V_74 ) ;
}
}
static void F_246 ( struct V_55 * V_56 ,
struct V_172 * V_173 )
{
struct V_142 * V_144 ;
struct V_48 * V_49 ;
unsigned long V_58 ;
int V_143 = 0 ;
struct V_346 * V_347 , * V_106 ;
V_49 = F_74 ( F_175 ( V_173 -> V_73 ) , V_173 -> V_73 -> V_78 ,
V_173 -> V_74 ) ;
if ( ! V_49 )
return;
F_79 ( & V_146 , V_58 ) ;
F_311 (entry, tmp, &domain->devices) {
V_144 = F_196 ( V_347 , struct V_142 , V_222 ) ;
if ( V_144 -> V_72 == F_175 ( V_173 -> V_73 ) &&
V_144 -> V_73 == V_173 -> V_73 -> V_78 &&
V_144 -> V_74 == V_173 -> V_74 ) {
F_192 ( V_144 ) ;
F_80 ( & V_146 , V_58 ) ;
F_120 ( V_144 ) ;
F_191 ( V_49 , V_144 -> V_73 , V_144 -> V_74 ) ;
F_310 ( V_49 , V_173 ) ;
F_53 ( V_144 ) ;
F_79 ( & V_146 , V_58 ) ;
if ( V_143 )
break;
else
continue;
}
if ( V_49 == F_74 ( V_144 -> V_72 , V_144 -> V_73 ,
V_144 -> V_74 ) )
V_143 = 1 ;
}
F_80 ( & V_146 , V_58 ) ;
if ( V_143 == 0 ) {
unsigned long V_348 ;
F_79 ( & V_56 -> V_167 , V_348 ) ;
F_142 ( V_49 -> V_164 , V_56 -> V_61 ) ;
V_56 -> V_168 -- ;
F_73 ( V_56 ) ;
F_80 ( & V_56 -> V_167 , V_348 ) ;
if ( ! ( V_56 -> V_58 & V_59 ) &&
! ( V_56 -> V_58 & V_60 ) ) {
F_79 ( & V_49 -> V_84 , V_348 ) ;
F_142 ( V_56 -> V_171 , V_49 -> V_165 ) ;
V_49 -> V_155 [ V_56 -> V_171 ] = NULL ;
F_80 ( & V_49 -> V_84 , V_348 ) ;
}
}
}
static void F_312 ( struct V_55 * V_56 )
{
struct V_142 * V_144 ;
struct V_48 * V_49 ;
unsigned long V_349 , V_350 ;
F_79 ( & V_146 , V_349 ) ;
while ( ! F_195 ( & V_56 -> V_77 ) ) {
V_144 = F_196 ( V_56 -> V_77 . V_225 ,
struct V_142 , V_222 ) ;
F_192 ( V_144 ) ;
F_80 ( & V_146 , V_349 ) ;
F_120 ( V_144 ) ;
V_49 = F_74 ( V_144 -> V_72 , V_144 -> V_73 , V_144 -> V_74 ) ;
F_191 ( V_49 , V_144 -> V_73 , V_144 -> V_74 ) ;
F_310 ( V_49 , V_144 -> V_147 ) ;
F_79 ( & V_56 -> V_167 , V_350 ) ;
if ( F_313 ( V_49 -> V_164 ,
V_56 -> V_61 ) ) {
V_56 -> V_168 -- ;
F_73 ( V_56 ) ;
}
F_80 ( & V_56 -> V_167 , V_350 ) ;
F_53 ( V_144 ) ;
F_79 ( & V_146 , V_349 ) ;
}
F_80 ( & V_146 , V_349 ) ;
}
static struct V_55 * F_314 ( void )
{
struct V_55 * V_56 ;
V_56 = F_48 () ;
if ( ! V_56 )
return NULL ;
V_56 -> V_171 = V_351 ++ ;
V_56 -> V_97 = - 1 ;
memset ( V_56 -> V_61 , 0 , sizeof( V_56 -> V_61 ) ) ;
V_56 -> V_58 = V_59 ;
return V_56 ;
}
static int F_210 ( struct V_55 * V_56 , int V_188 )
{
int V_189 ;
F_154 ( & V_56 -> V_187 , V_175 ) ;
F_138 ( & V_56 -> V_167 ) ;
F_159 ( V_56 ) ;
V_56 -> V_107 = V_188 ;
V_189 = F_161 ( V_188 ) ;
V_56 -> V_1 = F_3 ( V_189 ) ;
F_165 ( & V_56 -> V_77 ) ;
V_56 -> V_168 = 0 ;
V_56 -> V_65 = 0 ;
V_56 -> V_67 = 0 ;
V_56 -> V_71 = 0 ;
V_56 -> V_352 = 0 ;
V_56 -> V_97 = - 1 ;
V_56 -> V_93 = (struct V_25 * ) F_43 ( V_56 -> V_97 ) ;
if ( ! V_56 -> V_93 )
return - V_108 ;
F_76 ( V_56 , V_56 -> V_93 , V_190 ) ;
return 0 ;
}
static void F_315 ( struct V_55 * V_56 )
{
unsigned long V_58 ;
struct V_68 * V_69 ;
struct V_48 * V_49 ;
unsigned long V_64 ;
unsigned long V_162 ;
F_75 (drhd) {
if ( V_69 -> V_75 )
continue;
V_49 = V_69 -> V_49 ;
V_162 = F_136 ( V_49 -> V_52 ) ;
F_65 (i, iommu->domain_ids, ndomains) {
if ( V_49 -> V_155 [ V_64 ] == V_56 ) {
F_79 ( & V_49 -> V_84 , V_58 ) ;
F_142 ( V_64 , V_49 -> V_165 ) ;
V_49 -> V_155 [ V_64 ] = NULL ;
F_80 ( & V_49 -> V_84 , V_58 ) ;
break;
}
}
}
}
static void F_143 ( struct V_55 * V_56 )
{
if ( ! V_56 )
return;
F_312 ( V_56 ) ;
F_168 ( & V_56 -> V_187 ) ;
F_89 ( V_56 , 0 , F_91 ( V_56 -> V_107 ) ) ;
F_90 ( V_56 , 0 , F_91 ( V_56 -> V_107 ) ) ;
F_315 ( V_56 ) ;
F_50 ( V_56 ) ;
}
static int F_316 ( struct V_353 * V_56 )
{
struct V_55 * V_55 ;
V_55 = F_314 () ;
if ( ! V_55 ) {
F_42 ( V_141
L_77 ) ;
return - V_108 ;
}
if ( F_210 ( V_55 , V_54 ) ) {
F_42 ( V_141
L_78 ) ;
F_143 ( V_55 ) ;
return - V_108 ;
}
F_73 ( V_55 ) ;
V_56 -> V_354 = V_55 ;
return 0 ;
}
static void F_317 ( struct V_353 * V_56 )
{
struct V_55 * V_55 = V_56 -> V_354 ;
V_56 -> V_354 = NULL ;
F_143 ( V_55 ) ;
}
static int F_318 ( struct V_353 * V_56 ,
struct V_265 * V_147 )
{
struct V_55 * V_55 = V_56 -> V_354 ;
struct V_172 * V_173 = F_237 ( V_147 ) ;
struct V_48 * V_49 ;
int V_90 ;
if ( F_172 ( F_178 ( V_173 ) ) ) {
struct V_55 * V_355 ;
V_355 = F_197 ( V_173 ) ;
if ( V_355 ) {
if ( V_55 -> V_58 & V_59 ||
V_55 -> V_58 & V_60 )
F_246 ( V_355 , V_173 ) ;
else
F_167 ( V_355 ) ;
}
}
V_49 = F_74 ( F_175 ( V_173 -> V_73 ) , V_173 -> V_73 -> V_78 ,
V_173 -> V_74 ) ;
if ( ! V_49 )
return - V_180 ;
V_90 = F_2 ( V_49 -> V_1 ) ;
if ( V_90 > F_163 ( V_49 -> V_52 ) )
V_90 = F_163 ( V_49 -> V_52 ) ;
if ( V_55 -> V_352 > ( 1LL << V_90 ) ) {
F_42 ( V_141 L_79
L_80 ,
V_356 , V_90 , V_55 -> V_352 ) ;
return - V_194 ;
}
V_55 -> V_107 = V_90 ;
while ( V_49 -> V_1 < V_55 -> V_1 ) {
struct V_25 * V_26 ;
V_26 = V_55 -> V_93 ;
if ( F_38 ( V_26 ) ) {
V_55 -> V_93 = (struct V_25 * )
F_20 ( F_34 ( V_26 ) ) ;
F_46 ( V_26 ) ;
}
V_55 -> V_1 -- ;
}
return F_216 ( V_55 , V_173 , V_193 ) ;
}
static void F_319 ( struct V_353 * V_56 ,
struct V_265 * V_147 )
{
struct V_55 * V_55 = V_56 -> V_354 ;
struct V_172 * V_173 = F_237 ( V_147 ) ;
F_246 ( V_55 , V_173 ) ;
}
static int F_320 ( struct V_353 * V_56 ,
unsigned long V_46 , T_6 V_357 ,
T_5 V_82 , int V_358 )
{
struct V_55 * V_55 = V_56 -> V_354 ;
V_23 V_352 ;
int V_30 = 0 ;
int V_86 ;
if ( V_358 & V_359 )
V_30 |= V_27 ;
if ( V_358 & V_360 )
V_30 |= V_28 ;
if ( ( V_358 & V_361 ) && V_55 -> V_67 )
V_30 |= V_29 ;
V_352 = V_46 + V_82 ;
if ( V_55 -> V_352 < V_352 ) {
V_23 V_186 ;
V_186 = F_321 ( V_55 -> V_107 ) + 1 ;
if ( V_186 < V_352 ) {
F_42 ( V_141 L_79
L_80 ,
V_356 , V_55 -> V_107 , V_352 ) ;
return - V_194 ;
}
V_55 -> V_352 = V_352 ;
}
V_82 = F_179 ( V_357 , V_82 ) ;
V_86 = F_190 ( V_55 , V_46 >> V_10 ,
V_357 >> V_10 , V_82 , V_30 ) ;
return V_86 ;
}
static T_5 F_322 ( struct V_353 * V_56 ,
unsigned long V_46 , T_5 V_82 )
{
struct V_55 * V_55 = V_56 -> V_354 ;
int V_105 ;
V_105 = F_89 ( V_55 , V_46 >> V_10 ,
( V_46 + V_82 - 1 ) >> V_10 ) ;
if ( V_55 -> V_352 == V_46 + V_82 )
V_55 -> V_352 = V_46 ;
return V_190 << V_105 ;
}
static T_6 F_323 ( struct V_353 * V_56 ,
unsigned long V_46 )
{
struct V_55 * V_55 = V_56 -> V_354 ;
struct V_25 * V_26 ;
V_23 V_362 = 0 ;
V_26 = F_86 ( V_55 , V_46 >> V_10 , 0 ) ;
if ( V_26 )
V_362 = F_34 ( V_26 ) ;
return V_362 ;
}
static int F_324 ( struct V_353 * V_56 ,
unsigned long V_52 )
{
struct V_55 * V_55 = V_56 -> V_354 ;
if ( V_52 == V_363 )
return V_55 -> V_67 ;
if ( V_52 == V_364 )
return V_365 ;
return 0 ;
}
static int F_325 ( struct V_265 * V_147 , unsigned int * V_366 )
{
struct V_172 * V_173 = F_237 ( V_147 ) ;
struct V_172 * V_331 ;
union {
struct {
T_2 V_74 ;
T_2 V_73 ;
T_4 V_72 ;
} V_367 ;
T_3 V_368 ;
} V_171 ;
if ( F_245 ( V_147 ) )
return - V_180 ;
V_171 . V_367 . V_72 = F_175 ( V_173 -> V_73 ) ;
V_171 . V_367 . V_73 = V_173 -> V_73 -> V_78 ;
V_171 . V_367 . V_74 = V_173 -> V_74 ;
if ( ! F_74 ( V_171 . V_367 . V_72 , V_171 . V_367 . V_73 , V_171 . V_367 . V_74 ) )
return - V_180 ;
V_331 = F_176 ( V_173 ) ;
if ( V_331 ) {
if ( F_177 ( V_331 ) ) {
V_171 . V_367 . V_73 = V_331 -> V_79 -> V_78 ;
V_171 . V_367 . V_74 = 0 ;
} else {
V_171 . V_367 . V_73 = V_331 -> V_73 -> V_78 ;
V_171 . V_367 . V_74 = V_331 -> V_74 ;
}
}
if ( ! V_173 -> V_369 && V_370 )
V_171 . V_367 . V_74 = F_278 ( F_170 ( V_171 . V_367 . V_74 ) , 0 ) ;
* V_366 = V_171 . V_368 ;
return 0 ;
}
static void T_8 F_326 ( struct V_172 * V_147 )
{
F_42 ( V_35 L_81 ) ;
V_121 = 1 ;
if ( V_147 -> V_371 == 0x07 ) {
F_42 ( V_35 L_82 ) ;
V_36 = 0 ;
}
}
static void T_8 F_327 ( struct V_172 * V_147 )
{
unsigned short V_372 ;
if ( F_328 ( V_147 , V_373 , & V_372 ) )
return;
if ( ! ( V_372 & V_374 ) ) {
F_42 ( V_35 L_83 ) ;
V_36 = 0 ;
} else if ( V_36 ) {
F_42 ( V_35 L_84 ) ;
V_38 = 1 ;
}
}
static void T_1 F_232 ( void )
{
struct V_172 * V_173 ;
T_9 V_375 ;
V_173 = F_329 ( V_376 , 0x3a3e , NULL ) ;
if ( ! V_173 )
return;
F_330 ( V_173 ) ;
V_173 = F_329 ( V_376 , 0x342e , NULL ) ;
if ( ! V_173 )
return;
if ( F_331 ( V_173 , 0x188 , & V_375 ) ) {
F_330 ( V_173 ) ;
return;
}
F_330 ( V_173 ) ;
if ( V_375 & 1 )
return;
V_375 &= 0x1c ;
if ( V_375 == 0x10 )
return;
if ( ! V_375 ) {
F_204 ( 1 , L_85
L_31 ,
F_205 ( V_234 ) ,
F_205 ( V_235 ) ,
F_205 ( V_236 ) ) ;
V_246 |= V_248 ;
return;
}
F_42 ( V_377 L_86 ,
V_375 ) ;
}
