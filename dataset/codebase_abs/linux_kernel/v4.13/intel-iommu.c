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
static T_1 F_18 ( struct V_17 * V_18 )
{
if ( ! ( V_18 -> V_19 & 1 ) )
return 0 ;
return V_18 -> V_19 & V_20 ;
}
static T_1 F_19 ( struct V_17 * V_18 )
{
if ( ! ( V_18 -> V_21 & 1 ) )
return 0 ;
return V_18 -> V_21 & V_20 ;
}
static inline void F_20 ( struct V_22 * V_23 )
{
V_23 -> V_19 &= ~ ( 1ULL << 11 ) ;
}
static inline bool F_21 ( struct V_22 * V_23 )
{
return ! ! ( V_23 -> V_19 & ( 1ULL << 11 ) ) ;
}
static inline void F_22 ( struct V_22 * V_23 )
{
V_23 -> V_21 |= ( 1ull << 3 ) ;
}
static inline bool F_23 ( struct V_22 * V_23 )
{
return ! ! ( V_23 -> V_21 & ( 1ULL << 3 ) ) ;
}
static inline bool F_24 ( struct V_22 * V_23 )
{
return ( V_23 -> V_19 & 1 ) ;
}
static inline bool F_25 ( struct V_22 * V_23 )
{
return F_21 ( V_23 ) ?
F_24 ( V_23 ) :
F_24 ( V_23 ) && ! F_23 ( V_23 ) ;
}
static inline void F_26 ( struct V_22 * V_23 )
{
V_23 -> V_19 |= 1 ;
}
static inline void F_27 ( struct V_22 * V_23 )
{
V_23 -> V_19 &= ( ( ( V_24 ) - 1 ) << 2 ) | 1 ;
}
static inline void F_28 ( struct V_22 * V_23 ,
unsigned long V_25 )
{
V_23 -> V_19 &= ( ( ( V_24 ) - 1 ) << 4 ) | 3 ;
V_23 -> V_19 |= ( V_25 & 3 ) << 2 ;
}
static inline void F_29 ( struct V_22 * V_23 ,
unsigned long V_25 )
{
V_23 -> V_19 &= ~ V_20 ;
V_23 -> V_19 |= V_25 & V_20 ;
}
static inline void F_30 ( struct V_22 * V_23 ,
unsigned long V_25 )
{
V_23 -> V_21 |= V_25 & 7 ;
}
static inline void F_31 ( struct V_22 * V_23 ,
unsigned long V_25 )
{
V_23 -> V_21 |= ( V_25 & ( ( 1 << 16 ) - 1 ) ) << 8 ;
}
static inline int F_32 ( struct V_22 * V_26 )
{
return ( ( V_26 -> V_21 >> 8 ) & 0xffff ) ;
}
static inline void F_33 ( struct V_22 * V_23 )
{
V_23 -> V_19 = 0 ;
V_23 -> V_21 = 0 ;
}
static inline void F_34 ( struct V_27 * V_28 )
{
V_28 -> V_29 = 0 ;
}
static inline V_24 F_35 ( struct V_27 * V_28 )
{
#ifdef F_36
return V_28 -> V_29 & V_20 ;
#else
return F_37 ( & V_28 -> V_29 , 0ULL , 0ULL ) & V_20 ;
#endif
}
static inline bool F_38 ( struct V_27 * V_28 )
{
return ( V_28 -> V_29 & 3 ) != 0 ;
}
static inline bool F_39 ( struct V_27 * V_28 )
{
return ( V_28 -> V_29 & V_30 ) ;
}
static inline int F_40 ( struct V_27 * V_28 )
{
return ! ( ( unsigned long ) V_28 & ~ V_20 ) ;
}
static bool F_41 ( struct V_31 * V_32 )
{
return ( V_32 -> V_33 & V_34 ) ;
}
static void F_42 ( struct V_31 * V_32 )
{
V_32 -> V_33 &= ~ V_34 ;
}
static void F_43 ( struct V_31 * V_32 )
{
T_2 V_35 ;
V_35 = F_44 ( V_32 -> V_36 + V_37 ) ;
if ( V_35 & V_38 )
V_32 -> V_33 |= V_34 ;
}
static struct V_39 * F_45 ( struct V_40 * V_41 )
{
return F_46 ( V_41 , struct V_39 , V_42 ) ;
}
static int T_3 F_47 ( char * V_43 )
{
if ( ! V_43 )
return - V_44 ;
while ( * V_43 ) {
if ( ! strncmp ( V_43 , L_1 , 2 ) ) {
V_45 = 0 ;
F_48 ( L_2 ) ;
} else if ( ! strncmp ( V_43 , L_3 , 3 ) ) {
V_45 = 1 ;
F_48 ( L_4 ) ;
} else if ( ! strncmp ( V_43 , L_5 , 8 ) ) {
V_46 = 0 ;
F_48 ( L_6 ) ;
} else if ( ! strncmp ( V_43 , L_7 , 8 ) ) {
F_48 ( L_8 ) ;
V_47 = 1 ;
} else if ( ! strncmp ( V_43 , L_9 , 6 ) ) {
F_48 ( L_10 ) ;
V_48 = 1 ;
} else if ( ! strncmp ( V_43 , L_11 , 6 ) ) {
F_48 ( L_12 ) ;
V_49 = 0 ;
} else if ( ! strncmp ( V_43 , L_13 , 7 ) ) {
F_49 ( V_50
L_14 ) ;
V_51 = 0 ;
} else if ( ! strncmp ( V_43 , L_15 , 7 ) ) {
F_49 ( V_50
L_16 ) ;
V_52 = 1 ;
V_53 |= V_54 ;
} else if ( ! strncmp ( V_43 , L_17 , 13 ) ) {
F_49 ( V_50
L_18 ) ;
V_55 = 1 ;
}
V_43 += strcspn ( V_43 , L_19 ) ;
while ( * V_43 == ',' )
V_43 ++ ;
}
return 0 ;
}
static struct V_39 * F_50 ( struct V_31 * V_32 , T_4 V_56 )
{
struct V_39 * * V_57 ;
int V_58 = V_56 >> 8 ;
V_57 = V_32 -> V_57 [ V_58 ] ;
if ( ! V_57 )
return NULL ;
return V_57 [ V_56 & 0xff ] ;
}
static void F_51 ( struct V_31 * V_32 , T_4 V_56 ,
struct V_39 * V_42 )
{
struct V_39 * * V_57 ;
int V_58 = V_56 >> 8 ;
if ( ! V_32 -> V_57 [ V_58 ] ) {
T_5 V_59 = 256 * sizeof( struct V_39 * ) ;
V_32 -> V_57 [ V_58 ] = F_52 ( V_59 , V_60 ) ;
}
V_57 = V_32 -> V_57 [ V_58 ] ;
if ( F_53 ( ! V_57 ) )
return;
else
V_57 [ V_56 & 0xff ] = V_42 ;
}
static inline void * F_54 ( int V_61 )
{
struct V_14 * V_14 ;
void * V_62 = NULL ;
V_14 = F_55 ( V_61 , V_60 | V_63 , 0 ) ;
if ( V_14 )
V_62 = F_56 ( V_14 ) ;
return V_62 ;
}
static inline void F_57 ( void * V_62 )
{
F_58 ( ( unsigned long ) V_62 ) ;
}
static inline void * F_59 ( void )
{
return F_60 ( V_64 , V_60 ) ;
}
static void F_61 ( void * V_62 )
{
F_62 ( V_64 , V_62 ) ;
}
static inline void * F_63 ( void )
{
return F_60 ( V_65 , V_60 ) ;
}
static inline void F_64 ( void * V_62 )
{
F_62 ( V_65 , V_62 ) ;
}
static inline int F_65 ( struct V_39 * V_42 )
{
return V_42 -> V_33 & V_66 ;
}
static inline int F_66 ( struct V_39 * V_42 )
{
return V_42 -> V_33 & V_67 ;
}
static inline int F_67 ( struct V_39 * V_42 )
{
return V_42 -> V_33 & ( V_66 |
V_67 ) ;
}
static inline int F_68 ( struct V_39 * V_42 ,
unsigned long V_6 )
{
int V_68 = F_2 ( V_42 -> V_1 ) - V_12 ;
return ! ( V_68 < V_69 && V_6 > > V_68 ) ;
}
static int F_69 ( struct V_31 * V_32 , int V_70 )
{
unsigned long V_71 ;
int V_1 = - 1 ;
V_71 = F_70 ( V_32 -> V_72 ) ;
for ( V_1 = F_4 ( V_70 ) ;
V_1 >= 0 ; V_1 -- ) {
if ( F_71 ( V_1 , & V_71 ) )
break;
}
return V_1 ;
}
int F_72 ( struct V_31 * V_32 )
{
return F_69 ( V_32 , V_3 ) ;
}
int F_73 ( struct V_31 * V_32 )
{
return F_69 ( V_32 , V_73 ) ;
}
static struct V_31 * F_74 ( struct V_39 * V_42 )
{
int V_74 ;
F_75 ( F_67 ( V_42 ) ) ;
F_76 (iommu_id, domain)
break;
if ( V_74 < 0 || V_74 >= V_75 )
return NULL ;
return V_76 [ V_74 ] ;
}
static void F_77 ( struct V_39 * V_42 )
{
struct V_77 * V_78 ;
struct V_31 * V_32 ;
bool V_79 = false ;
int V_80 ;
V_42 -> V_81 = 1 ;
F_76 (i, domain) {
V_79 = true ;
if ( ! F_78 ( V_76 [ V_80 ] -> V_82 ) ) {
V_42 -> V_81 = 0 ;
break;
}
}
if ( V_79 )
return;
F_79 () ;
F_80 (iommu, drhd) {
if ( ! F_78 ( V_32 -> V_82 ) ) {
V_42 -> V_81 = 0 ;
break;
}
}
F_81 () ;
}
static int F_82 ( struct V_31 * V_83 )
{
struct V_77 * V_78 ;
struct V_31 * V_32 ;
int V_84 = 1 ;
F_79 () ;
F_80 (iommu, drhd) {
if ( V_32 != V_83 ) {
if ( ! F_83 ( V_32 -> V_82 ) ) {
V_84 = 0 ;
break;
}
}
}
F_81 () ;
return V_84 ;
}
static int F_84 ( struct V_31 * V_83 )
{
struct V_77 * V_78 ;
struct V_31 * V_32 ;
int V_85 = 0xf ;
if ( ! V_49 ) {
return 0 ;
}
F_79 () ;
F_80 (iommu, drhd) {
if ( V_32 != V_83 ) {
V_85 &= F_85 ( V_32 -> V_72 ) ;
if ( ! V_85 )
break;
}
}
F_81 () ;
return F_86 ( V_85 ) ;
}
static void F_87 ( struct V_39 * V_42 )
{
F_77 ( V_42 ) ;
V_42 -> V_86 = F_82 ( NULL ) ;
V_42 -> V_87 = F_84 ( NULL ) ;
}
static inline struct V_22 * F_88 ( struct V_31 * V_32 ,
T_6 V_88 , T_6 V_89 , int V_90 )
{
struct V_17 * V_91 = & V_32 -> V_17 [ V_88 ] ;
struct V_22 * V_23 ;
V_24 * V_92 ;
V_92 = & V_91 -> V_19 ;
if ( F_89 ( V_32 ) ) {
if ( V_89 >= 0x80 ) {
V_89 -= 0x80 ;
V_92 = & V_91 -> V_21 ;
}
V_89 *= 2 ;
}
if ( * V_92 & 1 )
V_23 = F_90 ( * V_92 & V_20 ) ;
else {
unsigned long V_93 ;
if ( ! V_90 )
return NULL ;
V_23 = F_54 ( V_32 -> V_61 ) ;
if ( ! V_23 )
return NULL ;
F_91 ( V_32 , ( void * ) V_23 , V_94 ) ;
V_93 = F_92 ( ( void * ) V_23 ) ;
* V_92 = V_93 | 1 ;
F_91 ( V_32 , V_92 , sizeof( * V_92 ) ) ;
}
return & V_23 [ V_89 ] ;
}
static int F_93 ( struct V_95 * V_96 )
{
return V_96 -> V_97 . V_32 == V_98 ;
}
static struct V_31 * F_94 ( struct V_95 * V_96 , T_6 * V_88 , T_6 * V_89 )
{
struct V_77 * V_78 = NULL ;
struct V_31 * V_32 ;
struct V_95 * V_99 ;
struct V_100 * V_101 , * V_102 = NULL ;
T_4 V_103 = 0 ;
int V_80 ;
if ( F_93 ( V_96 ) )
return NULL ;
if ( F_95 ( V_96 ) ) {
struct V_100 * V_104 ;
V_102 = F_96 ( V_96 ) ;
V_104 = F_97 ( V_102 ) ;
V_96 = & V_104 -> V_96 ;
V_103 = F_98 ( V_102 -> V_88 ) ;
} else if ( F_99 ( V_96 ) )
V_96 = & F_100 ( V_96 ) -> V_96 ;
F_79 () ;
F_80 (iommu, drhd) {
if ( V_102 && V_103 != V_78 -> V_103 )
continue;
F_101 (drhd->devices,
drhd->devices_cnt, i, tmp) {
if ( V_99 == V_96 ) {
if ( V_102 && V_102 -> V_105 )
goto V_106;
* V_88 = V_78 -> V_107 [ V_80 ] . V_88 ;
* V_89 = V_78 -> V_107 [ V_80 ] . V_89 ;
goto V_108;
}
if ( ! V_102 || ! F_95 ( V_99 ) )
continue;
V_101 = F_96 ( V_99 ) ;
if ( V_101 -> V_109 &&
V_101 -> V_109 -> V_110 <= V_102 -> V_88 -> V_110 &&
V_101 -> V_109 -> V_111 . V_112 >= V_102 -> V_88 -> V_110 )
goto V_106;
}
if ( V_102 && V_78 -> V_113 ) {
V_106:
* V_88 = V_102 -> V_88 -> V_110 ;
* V_89 = V_102 -> V_89 ;
goto V_108;
}
}
V_32 = NULL ;
V_108:
F_81 () ;
return V_32 ;
}
static void F_102 ( struct V_39 * V_42 ,
void * V_114 , int V_59 )
{
if ( ! V_42 -> V_81 )
F_103 ( V_114 , V_59 ) ;
}
static int F_104 ( struct V_31 * V_32 , T_6 V_88 , T_6 V_89 )
{
struct V_22 * V_23 ;
int V_84 = 0 ;
unsigned long V_33 ;
F_105 ( & V_32 -> V_115 , V_33 ) ;
V_23 = F_88 ( V_32 , V_88 , V_89 , 0 ) ;
if ( V_23 )
V_84 = F_25 ( V_23 ) ;
F_106 ( & V_32 -> V_115 , V_33 ) ;
return V_84 ;
}
static void F_107 ( struct V_31 * V_32 , T_6 V_88 , T_6 V_89 )
{
struct V_22 * V_23 ;
unsigned long V_33 ;
F_105 ( & V_32 -> V_115 , V_33 ) ;
V_23 = F_88 ( V_32 , V_88 , V_89 , 0 ) ;
if ( V_23 ) {
F_33 ( V_23 ) ;
F_91 ( V_32 , V_23 , sizeof( * V_23 ) ) ;
}
F_106 ( & V_32 -> V_115 , V_33 ) ;
}
static void F_108 ( struct V_31 * V_32 )
{
int V_80 ;
unsigned long V_33 ;
struct V_22 * V_23 ;
F_105 ( & V_32 -> V_115 , V_33 ) ;
if ( ! V_32 -> V_17 ) {
goto V_108;
}
for ( V_80 = 0 ; V_80 < V_116 ; V_80 ++ ) {
V_23 = F_88 ( V_32 , V_80 , 0 , 0 ) ;
if ( V_23 )
F_57 ( V_23 ) ;
if ( ! F_89 ( V_32 ) )
continue;
V_23 = F_88 ( V_32 , V_80 , 0x80 , 0 ) ;
if ( V_23 )
F_57 ( V_23 ) ;
}
F_57 ( V_32 -> V_17 ) ;
V_32 -> V_17 = NULL ;
V_108:
F_106 ( & V_32 -> V_115 , V_33 ) ;
}
static struct V_27 * F_109 ( struct V_39 * V_42 ,
unsigned long V_6 , int * V_117 )
{
struct V_27 * V_118 , * V_28 = NULL ;
int V_5 = F_1 ( V_42 -> V_1 ) ;
int V_119 ;
F_75 ( ! V_42 -> V_120 ) ;
if ( ! F_68 ( V_42 , V_6 ) )
return NULL ;
V_118 = V_42 -> V_120 ;
while ( 1 ) {
void * V_121 ;
V_119 = F_7 ( V_6 , V_5 ) ;
V_28 = & V_118 [ V_119 ] ;
if ( ! * V_117 && ( F_39 ( V_28 ) || ! F_38 ( V_28 ) ) )
break;
if ( V_5 == * V_117 )
break;
if ( ! F_38 ( V_28 ) ) {
T_7 V_122 ;
V_121 = F_54 ( V_42 -> V_123 ) ;
if ( ! V_121 )
return NULL ;
F_102 ( V_42 , V_121 , V_124 ) ;
V_122 = ( ( T_7 ) F_16 ( V_121 ) << V_12 ) | V_125 | V_126 ;
if ( F_110 ( & V_28 -> V_29 , 0ULL , V_122 ) )
F_57 ( V_121 ) ;
else
F_102 ( V_42 , V_28 , sizeof( * V_28 ) ) ;
}
if ( V_5 == 1 )
break;
V_118 = F_90 ( F_35 ( V_28 ) ) ;
V_5 -- ;
}
if ( ! * V_117 )
* V_117 = V_5 ;
return V_28 ;
}
static struct V_27 * F_111 ( struct V_39 * V_42 ,
unsigned long V_6 ,
int V_5 , int * V_127 )
{
struct V_27 * V_118 , * V_28 = NULL ;
int V_128 = F_1 ( V_42 -> V_1 ) ;
int V_119 ;
V_118 = V_42 -> V_120 ;
while ( V_5 <= V_128 ) {
V_119 = F_7 ( V_6 , V_128 ) ;
V_28 = & V_118 [ V_119 ] ;
if ( V_5 == V_128 )
return V_28 ;
if ( ! F_38 ( V_28 ) ) {
* V_127 = V_128 ;
break;
}
if ( F_39 ( V_28 ) ) {
* V_127 = V_128 ;
return V_28 ;
}
V_118 = F_90 ( F_35 ( V_28 ) ) ;
V_128 -- ;
}
return NULL ;
}
static void F_112 ( struct V_39 * V_42 ,
unsigned long V_129 ,
unsigned long V_130 )
{
unsigned int V_127 = 1 ;
struct V_27 * V_131 , * V_28 ;
F_75 ( ! F_68 ( V_42 , V_129 ) ) ;
F_75 ( ! F_68 ( V_42 , V_130 ) ) ;
F_75 ( V_129 > V_130 ) ;
do {
V_127 = 1 ;
V_131 = V_28 = F_111 ( V_42 , V_129 , 1 , & V_127 ) ;
if ( ! V_28 ) {
V_129 = F_10 ( V_129 + 1 , V_127 + 1 ) ;
continue;
}
do {
F_34 ( V_28 ) ;
V_129 += F_11 ( V_127 ) ;
V_28 ++ ;
} while ( V_129 <= V_130 && ! F_40 ( V_28 ) );
F_102 ( V_42 , V_131 ,
( void * ) V_28 - ( void * ) V_131 ) ;
} while ( V_129 && V_129 <= V_130 );
}
static void F_113 ( struct V_39 * V_42 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_129 , unsigned long V_130 )
{
V_6 = F_114 ( V_129 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_132 ;
struct V_27 * V_133 ;
if ( ! F_38 ( V_28 ) || F_39 ( V_28 ) )
goto V_134;
V_132 = V_6 & F_8 ( V_5 ) ;
V_133 = F_90 ( F_35 ( V_28 ) ) ;
if ( V_5 > 2 )
F_113 ( V_42 , V_5 - 1 , V_133 ,
V_132 , V_129 , V_130 ) ;
if ( ! ( V_129 > V_132 ||
V_130 < V_132 + F_9 ( V_5 ) - 1 ) ) {
F_34 ( V_28 ) ;
F_102 ( V_42 , V_28 , sizeof( * V_28 ) ) ;
F_57 ( V_133 ) ;
}
V_134:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_40 ( ++ V_28 ) && V_6 <= V_130 );
}
static void F_115 ( struct V_39 * V_42 ,
unsigned long V_129 ,
unsigned long V_130 )
{
F_75 ( ! F_68 ( V_42 , V_129 ) ) ;
F_75 ( ! F_68 ( V_42 , V_130 ) ) ;
F_75 ( V_129 > V_130 ) ;
F_112 ( V_42 , V_129 , V_130 ) ;
F_113 ( V_42 , F_1 ( V_42 -> V_1 ) ,
V_42 -> V_120 , 0 , V_129 , V_130 ) ;
if ( V_129 == 0 && V_130 == F_116 ( V_42 -> V_135 ) ) {
F_57 ( V_42 -> V_120 ) ;
V_42 -> V_120 = NULL ;
}
}
static struct V_14 * F_117 ( struct V_39 * V_42 ,
int V_5 , struct V_27 * V_28 ,
struct V_14 * V_136 )
{
struct V_14 * V_15 ;
V_15 = F_118 ( F_35 ( V_28 ) >> V_11 ) ;
V_15 -> V_136 = V_136 ;
V_136 = V_15 ;
if ( V_5 == 1 )
return V_136 ;
V_28 = F_56 ( V_15 ) ;
do {
if ( F_38 ( V_28 ) && ! F_39 ( V_28 ) )
V_136 = F_117 ( V_42 , V_5 - 1 ,
V_28 , V_136 ) ;
V_28 ++ ;
} while ( ! F_40 ( V_28 ) );
return V_136 ;
}
static struct V_14 * F_119 ( struct V_39 * V_42 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_129 ,
unsigned long V_130 ,
struct V_14 * V_136 )
{
struct V_27 * V_131 = NULL , * V_137 = NULL ;
V_6 = F_114 ( V_129 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_132 ;
if ( ! F_38 ( V_28 ) )
goto V_134;
V_132 = V_6 & F_8 ( V_5 ) ;
if ( V_129 <= V_132 &&
V_130 >= V_132 + F_9 ( V_5 ) - 1 ) {
if ( V_5 > 1 && ! F_39 ( V_28 ) )
V_136 = F_117 ( V_42 , V_5 - 1 , V_28 , V_136 ) ;
F_34 ( V_28 ) ;
if ( ! V_131 )
V_131 = V_28 ;
V_137 = V_28 ;
} else if ( V_5 > 1 ) {
V_136 = F_119 ( V_42 , V_5 - 1 ,
F_90 ( F_35 ( V_28 ) ) ,
V_132 , V_129 , V_130 ,
V_136 ) ;
}
V_134:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_40 ( ++ V_28 ) && V_6 <= V_130 );
if ( V_131 )
F_102 ( V_42 , V_131 ,
( void * ) ++ V_137 - ( void * ) V_131 ) ;
return V_136 ;
}
static struct V_14 * F_120 ( struct V_39 * V_42 ,
unsigned long V_129 ,
unsigned long V_130 )
{
struct V_14 * V_136 = NULL ;
F_75 ( ! F_68 ( V_42 , V_129 ) ) ;
F_75 ( ! F_68 ( V_42 , V_130 ) ) ;
F_75 ( V_129 > V_130 ) ;
V_136 = F_119 ( V_42 , F_1 ( V_42 -> V_1 ) ,
V_42 -> V_120 , 0 , V_129 , V_130 , NULL ) ;
if ( V_129 == 0 && V_130 == F_116 ( V_42 -> V_135 ) ) {
struct V_14 * V_138 = F_17 ( V_42 -> V_120 ) ;
V_138 -> V_136 = V_136 ;
V_136 = V_138 ;
V_42 -> V_120 = NULL ;
}
return V_136 ;
}
static void F_121 ( struct V_14 * V_136 )
{
struct V_14 * V_15 ;
while ( ( V_15 = V_136 ) ) {
V_136 = V_15 -> V_136 ;
F_57 ( F_56 ( V_15 ) ) ;
}
}
static int F_122 ( struct V_31 * V_32 )
{
struct V_17 * V_91 ;
unsigned long V_33 ;
V_91 = (struct V_17 * ) F_54 ( V_32 -> V_61 ) ;
if ( ! V_91 ) {
F_123 ( L_20 ,
V_32 -> V_139 ) ;
return - V_140 ;
}
F_91 ( V_32 , V_91 , V_141 ) ;
F_105 ( & V_32 -> V_115 , V_33 ) ;
V_32 -> V_17 = V_91 ;
F_106 ( & V_32 -> V_115 , V_33 ) ;
return 0 ;
}
static void F_124 ( struct V_31 * V_32 )
{
V_24 V_114 ;
T_2 V_142 ;
unsigned long V_143 ;
V_114 = F_92 ( V_32 -> V_17 ) ;
if ( F_89 ( V_32 ) )
V_114 |= V_144 ;
F_125 ( & V_32 -> V_145 , V_143 ) ;
F_126 ( V_32 -> V_36 + V_146 , V_114 ) ;
F_127 ( V_32 -> V_147 | V_148 , V_32 -> V_36 + V_149 ) ;
F_128 ( V_32 , V_37 ,
F_44 , ( V_142 & V_150 ) , V_142 ) ;
F_129 ( & V_32 -> V_145 , V_143 ) ;
}
static void F_130 ( struct V_31 * V_32 )
{
T_2 V_29 ;
unsigned long V_143 ;
if ( ! V_151 && ! F_131 ( V_32 -> V_72 ) )
return;
F_125 ( & V_32 -> V_145 , V_143 ) ;
F_127 ( V_32 -> V_147 | V_152 , V_32 -> V_36 + V_149 ) ;
F_128 ( V_32 , V_37 ,
F_44 , ( ! ( V_29 & V_153 ) ) , V_29 ) ;
F_129 ( & V_32 -> V_145 , V_143 ) ;
}
static void F_132 ( struct V_31 * V_32 ,
T_4 V_56 , T_4 V_154 , T_6 V_155 ,
V_24 type )
{
V_24 V_29 = 0 ;
unsigned long V_143 ;
switch ( type ) {
case V_156 :
V_29 = V_156 ;
break;
case V_157 :
V_29 = V_157 | F_133 ( V_56 ) ;
break;
case V_158 :
V_29 = V_158 | F_133 ( V_56 )
| F_134 ( V_154 ) | F_135 ( V_155 ) ;
break;
default:
F_136 () ;
}
V_29 |= V_159 ;
F_125 ( & V_32 -> V_145 , V_143 ) ;
F_126 ( V_32 -> V_36 + V_160 , V_29 ) ;
F_128 ( V_32 , V_160 ,
V_161 , ( ! ( V_29 & V_159 ) ) , V_29 ) ;
F_129 ( & V_32 -> V_145 , V_143 ) ;
}
static void F_137 ( struct V_31 * V_32 , T_4 V_56 ,
V_24 V_114 , unsigned int V_162 , V_24 type )
{
int V_163 = F_138 ( V_32 -> V_82 ) ;
V_24 V_29 = 0 , V_164 = 0 ;
unsigned long V_143 ;
switch ( type ) {
case V_165 :
V_29 = V_165 | V_166 ;
break;
case V_167 :
V_29 = V_167 | V_166 | F_139 ( V_56 ) ;
break;
case V_168 :
V_29 = V_168 | V_166 | F_139 ( V_56 ) ;
V_164 = V_162 | V_114 ;
break;
default:
F_136 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_140 ( V_32 -> V_72 ) )
V_29 |= V_169 ;
F_125 ( & V_32 -> V_145 , V_143 ) ;
if ( V_164 )
F_126 ( V_32 -> V_36 + V_163 , V_164 ) ;
F_126 ( V_32 -> V_36 + V_163 + 8 , V_29 ) ;
F_128 ( V_32 , V_163 + 8 ,
V_161 , ( ! ( V_29 & V_166 ) ) , V_29 ) ;
F_129 ( & V_32 -> V_145 , V_143 ) ;
if ( F_141 ( V_29 ) == 0 )
F_123 ( L_21 ) ;
if ( F_141 ( V_29 ) != F_142 ( type ) )
F_143 ( L_22 ,
( unsigned long long ) F_142 ( type ) ,
( unsigned long long ) F_141 ( V_29 ) ) ;
}
static struct V_170 *
F_144 ( struct V_39 * V_42 , struct V_31 * V_32 ,
T_6 V_88 , T_6 V_89 )
{
struct V_170 * V_171 ;
F_145 ( & V_172 ) ;
if ( ! V_32 -> V_173 )
return NULL ;
F_146 (info, &domain->devices, link)
if ( V_171 -> V_32 == V_32 && V_171 -> V_88 == V_88 &&
V_171 -> V_89 == V_89 ) {
if ( V_171 -> V_174 && V_171 -> V_96 )
return V_171 ;
break;
}
return NULL ;
}
static void F_147 ( struct V_39 * V_42 )
{
struct V_170 * V_171 ;
bool V_175 = false ;
F_145 ( & V_172 ) ;
F_146 (info, &domain->devices, link) {
struct V_100 * V_102 ;
if ( ! V_171 -> V_96 || ! F_95 ( V_171 -> V_96 ) )
continue;
V_102 = F_96 ( V_171 -> V_96 ) ;
if ( V_102 -> V_176 ) {
V_175 = true ;
break;
}
}
V_42 -> V_175 = V_175 ;
}
static void F_148 ( struct V_170 * V_171 )
{
struct V_100 * V_102 ;
F_145 ( & V_172 ) ;
if ( ! V_171 || ! F_95 ( V_171 -> V_96 ) )
return;
V_102 = F_96 ( V_171 -> V_96 ) ;
#ifdef F_149
if ( V_171 -> V_177 && ! F_150 ( V_102 , V_171 -> V_177 & ~ 1 ) )
V_171 -> V_178 = 1 ;
if ( V_171 -> V_179 && ! F_151 ( V_102 ) && ! F_152 ( V_102 , 32 ) )
V_171 -> V_180 = 1 ;
#endif
if ( V_171 -> V_174 && ! F_153 ( V_102 , V_12 ) ) {
V_171 -> V_176 = 1 ;
F_147 ( V_171 -> V_42 ) ;
V_171 -> V_181 = F_154 ( V_102 ) ;
}
}
static void F_155 ( struct V_170 * V_171 )
{
struct V_100 * V_102 ;
F_145 ( & V_172 ) ;
if ( ! F_95 ( V_171 -> V_96 ) )
return;
V_102 = F_96 ( V_171 -> V_96 ) ;
if ( V_171 -> V_176 ) {
F_156 ( V_102 ) ;
V_171 -> V_176 = 0 ;
F_147 ( V_171 -> V_42 ) ;
}
#ifdef F_149
if ( V_171 -> V_180 ) {
F_157 ( V_102 ) ;
V_171 -> V_180 = 0 ;
}
if ( V_171 -> V_178 ) {
F_158 ( V_102 ) ;
V_171 -> V_178 = 0 ;
}
#endif
}
static void F_159 ( struct V_39 * V_42 ,
V_24 V_114 , unsigned V_85 )
{
T_4 V_182 , V_183 ;
unsigned long V_33 ;
struct V_170 * V_171 ;
if ( ! V_42 -> V_175 )
return;
F_105 ( & V_172 , V_33 ) ;
F_146 (info, &domain->devices, link) {
if ( ! V_171 -> V_176 )
continue;
V_182 = V_171 -> V_88 << 8 | V_171 -> V_89 ;
V_183 = V_171 -> V_181 ;
F_160 ( V_171 -> V_32 , V_182 , V_183 , V_114 , V_85 ) ;
}
F_106 ( & V_172 , V_33 ) ;
}
static void F_161 ( struct V_31 * V_32 ,
struct V_39 * V_42 ,
unsigned long V_6 , unsigned int V_184 ,
int V_185 , int V_186 )
{
unsigned int V_85 = F_162 ( F_163 ( V_184 ) ) ;
T_7 V_114 = ( T_7 ) V_6 << V_12 ;
T_4 V_56 = V_42 -> V_187 [ V_32 -> V_188 ] ;
F_75 ( V_184 == 0 ) ;
if ( V_185 )
V_185 = 1 << 6 ;
if ( ! F_164 ( V_32 -> V_72 ) || V_85 > F_165 ( V_32 -> V_72 ) )
V_32 -> V_189 . V_190 ( V_32 , V_56 , 0 , 0 ,
V_167 ) ;
else
V_32 -> V_189 . V_190 ( V_32 , V_56 , V_114 | V_185 , V_85 ,
V_168 ) ;
if ( ! F_166 ( V_32 -> V_72 ) || ! V_186 )
F_159 ( F_50 ( V_32 , V_56 ) ,
V_114 , V_85 ) ;
}
static void F_167 ( struct V_31 * V_32 )
{
T_2 V_191 ;
unsigned long V_33 ;
F_125 ( & V_32 -> V_145 , V_33 ) ;
V_191 = F_44 ( V_32 -> V_36 + V_192 ) ;
V_191 &= ~ V_193 ;
F_127 ( V_191 , V_32 -> V_36 + V_192 ) ;
F_128 ( V_32 , V_192 ,
F_44 , ! ( V_191 & V_194 ) , V_191 ) ;
F_129 ( & V_32 -> V_145 , V_33 ) ;
}
static void F_168 ( struct V_31 * V_32 )
{
T_2 V_142 ;
unsigned long V_33 ;
F_125 ( & V_32 -> V_145 , V_33 ) ;
V_32 -> V_147 |= V_195 ;
F_127 ( V_32 -> V_147 , V_32 -> V_36 + V_149 ) ;
F_128 ( V_32 , V_37 ,
F_44 , ( V_142 & V_38 ) , V_142 ) ;
F_129 ( & V_32 -> V_145 , V_33 ) ;
}
static void F_169 ( struct V_31 * V_32 )
{
T_2 V_142 ;
unsigned long V_143 ;
F_125 ( & V_32 -> V_145 , V_143 ) ;
V_32 -> V_147 &= ~ V_195 ;
F_127 ( V_32 -> V_147 , V_32 -> V_36 + V_149 ) ;
F_128 ( V_32 , V_37 ,
F_44 , ( ! ( V_142 & V_38 ) ) , V_142 ) ;
F_129 ( & V_32 -> V_145 , V_143 ) ;
}
static int F_170 ( struct V_31 * V_32 )
{
T_2 V_196 , V_197 ;
T_5 V_59 ;
V_196 = F_171 ( V_32 -> V_72 ) ;
F_143 ( L_23 ,
V_32 -> V_139 , V_196 ) ;
V_197 = F_172 ( V_196 ) ;
F_173 ( & V_32 -> V_115 ) ;
V_32 -> V_198 = F_174 ( V_197 , sizeof( unsigned long ) , V_199 ) ;
if ( ! V_32 -> V_198 ) {
F_123 ( L_24 ,
V_32 -> V_139 ) ;
return - V_140 ;
}
V_59 = ( F_175 ( V_196 , 256 ) >> 8 ) * sizeof( struct V_39 * * ) ;
V_32 -> V_57 = F_52 ( V_59 , V_199 ) ;
if ( V_32 -> V_57 ) {
V_59 = 256 * sizeof( struct V_39 * ) ;
V_32 -> V_57 [ 0 ] = F_52 ( V_59 , V_199 ) ;
}
if ( ! V_32 -> V_57 || ! V_32 -> V_57 [ 0 ] ) {
F_123 ( L_25 ,
V_32 -> V_139 ) ;
F_176 ( V_32 -> V_198 ) ;
F_176 ( V_32 -> V_57 ) ;
V_32 -> V_198 = NULL ;
V_32 -> V_57 = NULL ;
return - V_140 ;
}
F_177 ( 0 , V_32 -> V_198 ) ;
return 0 ;
}
static void F_178 ( struct V_31 * V_32 )
{
struct V_170 * V_171 , * V_99 ;
unsigned long V_33 ;
if ( ! V_32 -> V_57 || ! V_32 -> V_198 )
return;
V_200:
F_105 ( & V_172 , V_33 ) ;
F_179 (info, tmp, &device_domain_list, global) {
struct V_39 * V_42 ;
if ( V_171 -> V_32 != V_32 )
continue;
if ( ! V_171 -> V_96 || ! V_171 -> V_42 )
continue;
V_42 = V_171 -> V_42 ;
F_180 ( V_171 ) ;
if ( ! F_67 ( V_42 ) ) {
F_106 ( & V_172 , V_33 ) ;
F_181 ( V_42 ) ;
goto V_200;
}
}
F_106 ( & V_172 , V_33 ) ;
if ( V_32 -> V_147 & V_195 )
F_169 ( V_32 ) ;
}
static void F_182 ( struct V_31 * V_32 )
{
if ( ( V_32 -> V_57 ) && ( V_32 -> V_198 ) ) {
int V_201 = F_175 ( F_171 ( V_32 -> V_72 ) , 256 ) >> 8 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_201 ; V_80 ++ )
F_176 ( V_32 -> V_57 [ V_80 ] ) ;
F_176 ( V_32 -> V_57 ) ;
F_176 ( V_32 -> V_198 ) ;
V_32 -> V_57 = NULL ;
V_32 -> V_198 = NULL ;
}
V_76 [ V_32 -> V_188 ] = NULL ;
F_108 ( V_32 ) ;
#ifdef F_149
if ( V_178 ( V_32 ) ) {
if ( F_183 ( V_32 -> V_82 ) )
F_184 ( V_32 ) ;
F_185 ( V_32 ) ;
}
#endif
}
static struct V_39 * F_186 ( int V_33 )
{
struct V_39 * V_42 ;
V_42 = F_59 () ;
if ( ! V_42 )
return NULL ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_123 = - 1 ;
V_42 -> V_33 = V_33 ;
V_42 -> V_175 = false ;
F_187 ( & V_42 -> V_107 ) ;
return V_42 ;
}
static int F_188 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
unsigned long V_196 ;
int V_202 ;
F_145 ( & V_172 ) ;
F_145 ( & V_32 -> V_115 ) ;
V_42 -> V_203 [ V_32 -> V_188 ] += 1 ;
V_42 -> V_204 += 1 ;
if ( V_42 -> V_203 [ V_32 -> V_188 ] == 1 ) {
V_196 = F_171 ( V_32 -> V_72 ) ;
V_202 = F_189 ( V_32 -> V_198 , V_196 ) ;
if ( V_202 >= V_196 ) {
F_123 ( L_26 , V_32 -> V_139 ) ;
V_42 -> V_203 [ V_32 -> V_188 ] -= 1 ;
V_42 -> V_204 -= 1 ;
return - V_205 ;
}
F_177 ( V_202 , V_32 -> V_198 ) ;
F_51 ( V_32 , V_202 , V_42 ) ;
V_42 -> V_187 [ V_32 -> V_188 ] = V_202 ;
V_42 -> V_123 = V_32 -> V_61 ;
F_87 ( V_42 ) ;
}
return 0 ;
}
static int F_190 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
int V_202 , V_206 = V_207 ;
F_145 ( & V_172 ) ;
F_145 ( & V_32 -> V_115 ) ;
V_42 -> V_203 [ V_32 -> V_188 ] -= 1 ;
V_206 = -- V_42 -> V_204 ;
if ( V_42 -> V_203 [ V_32 -> V_188 ] == 0 ) {
V_202 = V_42 -> V_187 [ V_32 -> V_188 ] ;
F_191 ( V_202 , V_32 -> V_198 ) ;
F_51 ( V_32 , V_202 , NULL ) ;
F_87 ( V_42 ) ;
V_42 -> V_187 [ V_32 -> V_188 ] = 0 ;
}
return V_206 ;
}
static int F_192 ( void )
{
struct V_100 * V_102 = NULL ;
struct V_208 * V_208 ;
int V_80 ;
F_193 ( & V_209 , V_124 , V_210 ,
V_211 ) ;
F_194 ( & V_209 . V_212 ,
& V_213 ) ;
V_208 = F_195 ( & V_209 , F_196 ( V_214 ) ,
F_196 ( V_215 ) ) ;
if ( ! V_208 ) {
F_123 ( L_27 ) ;
return - V_216 ;
}
F_197 (pdev) {
struct V_217 * V_218 ;
for ( V_80 = 0 ; V_80 < V_219 ; V_80 ++ ) {
V_218 = & V_102 -> V_217 [ V_80 ] ;
if ( ! V_218 -> V_33 || ! ( V_218 -> V_33 & V_220 ) )
continue;
V_208 = F_195 ( & V_209 ,
F_196 ( V_218 -> V_221 ) ,
F_196 ( V_218 -> V_112 ) ) ;
if ( ! V_208 ) {
F_123 ( L_28 ) ;
return - V_216 ;
}
}
}
return 0 ;
}
static void F_198 ( struct V_39 * V_42 )
{
F_199 ( & V_209 , & V_42 -> V_222 ) ;
}
static inline int F_200 ( int V_135 )
{
int V_1 ;
int V_218 = ( V_135 - 12 ) % 9 ;
if ( V_218 == 0 )
V_1 = V_135 ;
else
V_1 = V_135 + 9 - V_218 ;
if ( V_1 > 64 )
V_1 = 64 ;
return V_1 ;
}
static int F_201 ( struct V_39 * V_42 , struct V_31 * V_32 ,
int V_223 )
{
int V_224 , V_1 ;
unsigned long V_71 ;
F_193 ( & V_42 -> V_222 , V_124 , V_210 ,
V_211 ) ;
F_198 ( V_42 ) ;
if ( V_223 > F_202 ( V_32 -> V_72 ) )
V_223 = F_202 ( V_32 -> V_72 ) ;
V_42 -> V_135 = V_223 ;
V_224 = F_200 ( V_223 ) ;
V_1 = F_4 ( V_224 ) ;
V_71 = F_70 ( V_32 -> V_72 ) ;
if ( ! F_71 ( V_1 , & V_71 ) ) {
F_143 ( L_29 , V_1 ) ;
V_1 = F_203 ( & V_71 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_216 ;
}
V_42 -> V_1 = V_1 ;
if ( F_78 ( V_32 -> V_82 ) )
V_42 -> V_81 = 1 ;
else
V_42 -> V_81 = 0 ;
if ( F_83 ( V_32 -> V_82 ) )
V_42 -> V_86 = 1 ;
else
V_42 -> V_86 = 0 ;
if ( V_49 )
V_42 -> V_87 = F_86 ( F_85 ( V_32 -> V_72 ) ) ;
else
V_42 -> V_87 = 0 ;
V_42 -> V_123 = V_32 -> V_61 ;
V_42 -> V_120 = (struct V_27 * ) F_54 ( V_42 -> V_123 ) ;
if ( ! V_42 -> V_120 )
return - V_140 ;
F_91 ( V_32 , V_42 -> V_120 , V_225 ) ;
return 0 ;
}
static void F_181 ( struct V_39 * V_42 )
{
struct V_14 * V_136 = NULL ;
if ( ! V_42 )
return;
if ( ! V_48 ) {
int V_226 ;
F_204 (cpu)
F_205 ( V_226 ) ;
}
F_79 () ;
F_206 ( V_42 ) ;
F_81 () ;
F_207 ( & V_42 -> V_222 ) ;
V_136 = F_120 ( V_42 , 0 , F_116 ( V_42 -> V_135 ) ) ;
F_121 ( V_136 ) ;
F_61 ( V_42 ) ;
}
static int F_208 ( struct V_39 * V_42 ,
struct V_31 * V_32 ,
T_6 V_88 , T_6 V_89 )
{
T_4 V_56 = V_42 -> V_187 [ V_32 -> V_188 ] ;
int V_227 = V_228 ;
struct V_170 * V_171 = NULL ;
struct V_22 * V_23 ;
unsigned long V_33 ;
struct V_27 * V_120 ;
int V_84 , V_1 ;
F_53 ( V_56 == 0 ) ;
if ( V_229 && F_66 ( V_42 ) )
V_227 = V_230 ;
F_143 ( L_30 ,
V_88 , F_209 ( V_89 ) , F_210 ( V_89 ) ) ;
F_75 ( ! V_42 -> V_120 ) ;
F_105 ( & V_172 , V_33 ) ;
F_211 ( & V_32 -> V_115 ) ;
V_84 = - V_140 ;
V_23 = F_88 ( V_32 , V_88 , V_89 , 1 ) ;
if ( ! V_23 )
goto V_231;
V_84 = 0 ;
if ( F_25 ( V_23 ) )
goto V_231;
if ( F_23 ( V_23 ) ) {
T_4 V_232 = F_32 ( V_23 ) ;
if ( V_232 >= 0 && V_232 < F_171 ( V_32 -> V_72 ) ) {
V_32 -> V_189 . V_233 ( V_32 , V_232 ,
( ( ( T_4 ) V_88 ) << 8 ) | V_89 ,
V_234 ,
V_158 ) ;
V_32 -> V_189 . V_190 ( V_32 , V_232 , 0 , 0 ,
V_167 ) ;
}
}
V_120 = V_42 -> V_120 ;
F_33 ( V_23 ) ;
F_31 ( V_23 , V_56 ) ;
if ( V_227 != V_230 ) {
for ( V_1 = V_42 -> V_1 ; V_1 != V_32 -> V_1 ; V_1 -- ) {
V_84 = - V_140 ;
V_120 = F_90 ( F_35 ( V_120 ) ) ;
if ( ! F_38 ( V_120 ) )
goto V_231;
}
V_171 = F_144 ( V_42 , V_32 , V_88 , V_89 ) ;
if ( V_171 && V_171 -> V_174 )
V_227 = V_235 ;
else
V_227 = V_228 ;
F_29 ( V_23 , F_92 ( V_120 ) ) ;
F_30 ( V_23 , V_32 -> V_1 ) ;
} else {
F_30 ( V_23 , V_32 -> V_236 ) ;
}
F_28 ( V_23 , V_227 ) ;
F_27 ( V_23 ) ;
F_26 ( V_23 ) ;
F_102 ( V_42 , V_23 , sizeof( * V_23 ) ) ;
if ( F_166 ( V_32 -> V_72 ) ) {
V_32 -> V_189 . V_233 ( V_32 , 0 ,
( ( ( T_4 ) V_88 ) << 8 ) | V_89 ,
V_234 ,
V_158 ) ;
V_32 -> V_189 . V_190 ( V_32 , V_56 , 0 , 0 , V_167 ) ;
} else {
F_130 ( V_32 ) ;
}
F_148 ( V_171 ) ;
V_84 = 0 ;
V_231:
F_212 ( & V_32 -> V_115 ) ;
F_106 ( & V_172 , V_33 ) ;
return V_84 ;
}
static int F_213 ( struct V_100 * V_102 ,
T_4 V_237 , void * V_238 )
{
struct V_239 * V_240 = V_238 ;
return F_208 ( V_240 -> V_42 , V_240 -> V_32 ,
F_214 ( V_237 ) , V_237 & 0xff ) ;
}
static int
F_215 ( struct V_39 * V_42 , struct V_95 * V_96 )
{
struct V_31 * V_32 ;
T_6 V_88 , V_89 ;
struct V_239 V_240 ;
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return - V_216 ;
if ( ! F_95 ( V_96 ) )
return F_208 ( V_42 , V_32 , V_88 , V_89 ) ;
V_240 . V_42 = V_42 ;
V_240 . V_32 = V_32 ;
return F_216 ( F_96 ( V_96 ) ,
& F_213 , & V_240 ) ;
}
static int F_217 ( struct V_100 * V_102 ,
T_4 V_237 , void * V_238 )
{
struct V_31 * V_32 = V_238 ;
return ! F_104 ( V_32 , F_214 ( V_237 ) , V_237 & 0xff ) ;
}
static int F_218 ( struct V_95 * V_96 )
{
struct V_31 * V_32 ;
T_6 V_88 , V_89 ;
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return - V_216 ;
if ( ! F_95 ( V_96 ) )
return F_104 ( V_32 , V_88 , V_89 ) ;
return ! F_216 ( F_96 ( V_96 ) ,
F_217 , V_32 ) ;
}
static inline unsigned long F_219 ( unsigned long V_241 ,
T_5 V_59 )
{
V_241 &= ~ V_242 ;
return F_220 ( V_241 + V_59 ) >> V_12 ;
}
static inline int F_221 ( struct V_39 * V_42 ,
unsigned long V_243 ,
unsigned long V_244 ,
unsigned long V_184 )
{
int V_245 , V_5 = 1 ;
unsigned long V_246 ;
V_245 = V_42 -> V_87 ;
V_246 = V_243 | V_244 ;
while ( V_245 && ! ( V_246 & ~ V_247 ) ) {
V_184 >>= V_248 ;
if ( ! V_184 )
break;
V_246 >>= V_248 ;
V_5 ++ ;
V_245 -- ;
}
return V_5 ;
}
static int F_222 ( struct V_39 * V_42 , unsigned long V_243 ,
struct V_249 * V_250 , unsigned long V_251 ,
unsigned long V_252 , int V_253 )
{
struct V_27 * V_131 = NULL , * V_28 = NULL ;
T_1 V_254 ( V_122 ) ;
unsigned long V_255 = 0 ;
unsigned int V_256 = 0 ;
unsigned long V_257 = 0 ;
F_75 ( ! F_68 ( V_42 , V_243 + V_252 - 1 ) ) ;
if ( ( V_253 & ( V_125 | V_126 ) ) == 0 )
return - V_44 ;
V_253 &= V_125 | V_126 | V_258 ;
if ( ! V_250 ) {
V_255 = V_252 ;
V_122 = ( ( T_1 ) V_251 << V_12 ) | V_253 ;
}
while ( V_252 > 0 ) {
T_7 V_99 ;
if ( ! V_255 ) {
V_255 = F_219 ( V_250 -> V_119 , V_250 -> V_259 ) ;
V_250 -> V_260 = ( ( V_261 ) V_243 << V_12 ) + V_250 -> V_119 ;
V_250 -> V_262 = V_250 -> V_259 ;
V_122 = F_223 ( F_224 ( V_250 ) ) | V_253 ;
V_251 = V_122 >> V_12 ;
}
if ( ! V_28 ) {
V_256 = F_221 ( V_42 , V_243 , V_251 , V_255 ) ;
V_131 = V_28 = F_109 ( V_42 , V_243 , & V_256 ) ;
if ( ! V_28 )
return - V_140 ;
if ( V_256 > 1 ) {
unsigned long V_263 , V_264 ;
V_122 |= V_30 ;
V_257 = F_11 ( V_256 ) ;
V_263 = V_255 / V_257 ;
V_264 = V_243 + V_263 * V_257 - 1 ;
F_115 ( V_42 , V_243 , V_264 ) ;
} else {
V_122 &= ~ ( T_7 ) V_30 ;
}
}
V_99 = F_225 ( & V_28 -> V_29 , 0ULL , V_122 ) ;
if ( V_99 ) {
static int V_265 = 5 ;
F_226 ( L_31 ,
V_243 , V_99 , ( unsigned long long ) V_122 ) ;
if ( V_265 ) {
V_265 -- ;
F_227 ( NULL ) ;
}
F_53 ( 1 ) ;
}
V_257 = F_11 ( V_256 ) ;
F_75 ( V_252 < V_257 ) ;
F_75 ( V_255 < V_257 ) ;
V_252 -= V_257 ;
V_243 += V_257 ;
V_251 += V_257 ;
V_122 += V_257 * V_124 ;
V_255 -= V_257 ;
V_28 ++ ;
if ( ! V_252 || F_40 ( V_28 ) ||
( V_256 > 1 && V_255 < V_257 ) ) {
F_102 ( V_42 , V_131 ,
( void * ) V_28 - ( void * ) V_131 ) ;
V_28 = NULL ;
}
if ( ! V_255 && V_252 )
V_250 = F_228 ( V_250 ) ;
}
return 0 ;
}
static inline int F_229 ( struct V_39 * V_42 , unsigned long V_243 ,
struct V_249 * V_250 , unsigned long V_252 ,
int V_253 )
{
return F_222 ( V_42 , V_243 , V_250 , 0 , V_252 , V_253 ) ;
}
static inline int F_230 ( struct V_39 * V_42 , unsigned long V_243 ,
unsigned long V_251 , unsigned long V_252 ,
int V_253 )
{
return F_222 ( V_42 , V_243 , NULL , V_251 , V_252 , V_253 ) ;
}
static void F_231 ( struct V_31 * V_32 , T_6 V_88 , T_6 V_89 )
{
if ( ! V_32 )
return;
F_107 ( V_32 , V_88 , V_89 ) ;
V_32 -> V_189 . V_233 ( V_32 , 0 , 0 , 0 ,
V_156 ) ;
V_32 -> V_189 . V_190 ( V_32 , 0 , 0 , 0 , V_165 ) ;
}
static inline void F_232 ( struct V_170 * V_171 )
{
F_145 ( & V_172 ) ;
F_233 ( & V_171 -> V_266 ) ;
F_233 ( & V_171 -> V_267 ) ;
if ( V_171 -> V_96 )
V_171 -> V_96 -> V_97 . V_32 = NULL ;
}
static void F_206 ( struct V_39 * V_42 )
{
struct V_170 * V_171 , * V_99 ;
unsigned long V_33 ;
F_105 ( & V_172 , V_33 ) ;
F_179 (info, tmp, &domain->devices, link)
F_180 ( V_171 ) ;
F_106 ( & V_172 , V_33 ) ;
}
static struct V_39 * F_234 ( struct V_95 * V_96 )
{
struct V_170 * V_171 ;
V_171 = V_96 -> V_97 . V_32 ;
if ( F_235 ( V_171 ) )
return V_171 -> V_42 ;
return NULL ;
}
static inline struct V_170 *
F_236 ( int V_103 , int V_88 , int V_89 )
{
struct V_170 * V_171 ;
F_146 (info, &device_domain_list, global)
if ( V_171 -> V_32 -> V_103 == V_103 && V_171 -> V_88 == V_88 &&
V_171 -> V_89 == V_89 )
return V_171 ;
return NULL ;
}
static struct V_39 * F_237 ( struct V_31 * V_32 ,
int V_88 , int V_89 ,
struct V_95 * V_96 ,
struct V_39 * V_42 )
{
struct V_39 * V_79 = NULL ;
struct V_170 * V_171 ;
unsigned long V_33 ;
int V_84 ;
V_171 = F_63 () ;
if ( ! V_171 )
return NULL ;
V_171 -> V_88 = V_88 ;
V_171 -> V_89 = V_89 ;
V_171 -> V_174 = V_171 -> V_177 = V_171 -> V_179 = 0 ;
V_171 -> V_176 = V_171 -> V_178 = V_171 -> V_180 = 0 ;
V_171 -> V_181 = 0 ;
V_171 -> V_96 = V_96 ;
V_171 -> V_42 = V_42 ;
V_171 -> V_32 = V_32 ;
if ( V_96 && F_95 ( V_96 ) ) {
struct V_100 * V_102 = F_96 ( V_171 -> V_96 ) ;
if ( F_238 ( V_32 -> V_82 ) &&
F_239 ( V_102 , V_268 ) &&
F_240 ( V_102 ) )
V_171 -> V_174 = 1 ;
if ( F_89 ( V_32 ) ) {
if ( V_178 ( V_32 ) ) {
int V_269 = F_241 ( V_102 ) ;
if ( V_269 >= 0 )
V_171 -> V_177 = V_269 | 1 ;
}
if ( V_171 -> V_174 && F_183 ( V_32 -> V_82 ) &&
F_239 ( V_102 , V_270 ) )
V_171 -> V_179 = 1 ;
}
}
F_105 ( & V_172 , V_33 ) ;
if ( V_96 )
V_79 = F_234 ( V_96 ) ;
if ( ! V_79 ) {
struct V_170 * V_271 ;
V_271 = F_236 ( V_32 -> V_103 , V_88 , V_89 ) ;
if ( V_271 ) {
V_79 = V_271 -> V_42 ;
V_271 -> V_96 = V_96 ;
}
}
if ( V_79 ) {
F_106 ( & V_172 , V_33 ) ;
F_64 ( V_171 ) ;
return V_79 ;
}
F_211 ( & V_32 -> V_115 ) ;
V_84 = F_188 ( V_42 , V_32 ) ;
F_212 ( & V_32 -> V_115 ) ;
if ( V_84 ) {
F_106 ( & V_172 , V_33 ) ;
F_64 ( V_171 ) ;
return NULL ;
}
F_242 ( & V_171 -> V_266 , & V_42 -> V_107 ) ;
F_242 ( & V_171 -> V_267 , & V_272 ) ;
if ( V_96 )
V_96 -> V_97 . V_32 = V_171 ;
F_106 ( & V_172 , V_33 ) ;
if ( V_96 && F_215 ( V_42 , V_96 ) ) {
F_123 ( L_32 , F_243 ( V_96 ) ) ;
F_244 ( V_42 , V_96 ) ;
return NULL ;
}
return V_42 ;
}
static int F_245 ( struct V_100 * V_102 , T_4 V_237 , void * V_238 )
{
* ( T_4 * ) V_238 = V_237 ;
return 0 ;
}
static struct V_39 * F_246 ( struct V_95 * V_96 , int V_135 )
{
struct V_170 * V_171 = NULL ;
struct V_39 * V_42 = NULL ;
struct V_31 * V_32 ;
T_4 V_273 , V_274 ;
unsigned long V_33 ;
T_6 V_88 , V_89 ;
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return NULL ;
V_273 = ( ( T_4 ) V_88 << 8 ) | V_89 ;
if ( F_95 ( V_96 ) ) {
struct V_100 * V_102 = F_96 ( V_96 ) ;
F_216 ( V_102 , F_245 , & V_274 ) ;
F_105 ( & V_172 , V_33 ) ;
V_171 = F_236 ( F_98 ( V_102 -> V_88 ) ,
F_214 ( V_274 ) ,
V_274 & 0xff ) ;
if ( V_171 ) {
V_32 = V_171 -> V_32 ;
V_42 = V_171 -> V_42 ;
}
F_106 ( & V_172 , V_33 ) ;
if ( V_171 )
goto V_108;
}
V_42 = F_186 ( 0 ) ;
if ( ! V_42 )
return NULL ;
if ( F_201 ( V_42 , V_32 , V_135 ) ) {
F_181 ( V_42 ) ;
return NULL ;
}
V_108:
return V_42 ;
}
static struct V_39 * F_247 ( struct V_95 * V_96 ,
struct V_39 * V_42 )
{
struct V_31 * V_32 ;
struct V_39 * V_99 ;
T_4 V_273 , V_274 ;
T_6 V_88 , V_89 ;
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return NULL ;
V_273 = ( ( T_4 ) V_88 << 8 ) | V_89 ;
if ( F_95 ( V_96 ) ) {
struct V_100 * V_102 = F_96 ( V_96 ) ;
F_216 ( V_102 , F_245 , & V_274 ) ;
if ( V_273 != V_274 ) {
V_99 = F_237 ( V_32 , F_214 ( V_274 ) ,
V_274 & 0xff , NULL , V_42 ) ;
if ( ! V_99 || V_99 != V_42 )
return V_99 ;
}
}
V_99 = F_237 ( V_32 , V_88 , V_89 , V_96 , V_42 ) ;
if ( ! V_99 || V_99 != V_42 )
return V_99 ;
return V_42 ;
}
static struct V_39 * F_248 ( struct V_95 * V_96 , int V_135 )
{
struct V_39 * V_42 , * V_99 ;
V_42 = F_234 ( V_96 ) ;
if ( V_42 )
goto V_108;
V_42 = F_246 ( V_96 , V_135 ) ;
if ( ! V_42 )
goto V_108;
V_99 = F_247 ( V_96 , V_42 ) ;
if ( ! V_99 || V_42 != V_99 ) {
F_181 ( V_42 ) ;
V_42 = V_99 ;
}
V_108:
return V_42 ;
}
static int F_249 ( struct V_39 * V_42 ,
unsigned long long V_221 ,
unsigned long long V_112 )
{
unsigned long V_275 = V_221 >> V_12 ;
unsigned long V_276 = V_112 >> V_12 ;
if ( ! F_195 ( & V_42 -> V_222 , F_12 ( V_275 ) ,
F_12 ( V_276 ) ) ) {
F_123 ( L_33 ) ;
return - V_140 ;
}
F_143 ( L_34 , V_221 , V_112 ) ;
F_112 ( V_42 , V_275 , V_276 ) ;
return F_230 ( V_42 , V_275 , V_275 ,
V_276 - V_275 + 1 ,
V_125 | V_126 ) ;
}
static int F_250 ( struct V_95 * V_96 ,
struct V_39 * V_42 ,
unsigned long long V_221 ,
unsigned long long V_112 )
{
if ( V_42 == V_277 && V_229 ) {
F_251 ( L_35 ,
F_243 ( V_96 ) , V_221 , V_112 ) ;
return 0 ;
}
F_48 ( L_36 ,
F_243 ( V_96 ) , V_221 , V_112 ) ;
if ( V_112 < V_221 ) {
F_252 ( 1 , L_37
L_38 ,
F_253 ( V_278 ) ,
F_253 ( V_279 ) ,
F_253 ( V_280 ) ) ;
return - V_281 ;
}
if ( V_112 >> F_2 ( V_42 -> V_1 ) ) {
F_252 ( 1 , L_39
L_38 ,
F_2 ( V_42 -> V_1 ) ,
F_253 ( V_278 ) ,
F_253 ( V_279 ) ,
F_253 ( V_280 ) ) ;
return - V_281 ;
}
return F_249 ( V_42 , V_221 , V_112 ) ;
}
static int F_254 ( struct V_95 * V_96 ,
unsigned long long V_221 ,
unsigned long long V_112 )
{
struct V_39 * V_42 ;
int V_84 ;
V_42 = F_248 ( V_96 , V_73 ) ;
if ( ! V_42 )
return - V_140 ;
V_84 = F_250 ( V_96 , V_42 , V_221 , V_112 ) ;
if ( V_84 )
F_181 ( V_42 ) ;
return V_84 ;
}
static inline int F_255 ( struct V_282 * V_283 ,
struct V_95 * V_96 )
{
if ( V_96 -> V_97 . V_32 == V_98 )
return 0 ;
return F_254 ( V_96 , V_283 -> V_284 ,
V_283 -> V_285 ) ;
}
static inline void F_256 ( void )
{
struct V_100 * V_102 ;
int V_84 ;
V_102 = F_257 ( V_286 << 8 , NULL ) ;
if ( ! V_102 )
return;
F_48 ( L_40 ) ;
V_84 = F_254 ( & V_102 -> V_96 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_84 )
F_123 ( L_41 ) ;
F_258 ( V_102 ) ;
}
static inline void F_256 ( void )
{
return;
}
static int T_3 F_259 ( int V_287 )
{
int V_123 , V_84 = 0 ;
V_277 = F_186 ( V_67 ) ;
if ( ! V_277 )
return - V_288 ;
if ( F_260 ( V_277 , V_73 ) ) {
F_181 ( V_277 ) ;
return - V_288 ;
}
F_143 ( L_42 ) ;
if ( V_287 )
return 0 ;
F_261 (nid) {
unsigned long V_129 , V_264 ;
int V_80 ;
F_262 (i, nid, &start_pfn, &end_pfn, NULL) {
V_84 = F_249 ( V_277 ,
F_263 ( V_129 ) , F_263 ( V_264 ) ) ;
if ( V_84 )
return V_84 ;
}
}
return 0 ;
}
static int F_264 ( struct V_95 * V_96 )
{
struct V_170 * V_171 ;
if ( F_235 ( ! V_53 ) )
return 0 ;
V_171 = V_96 -> V_97 . V_32 ;
if ( V_171 && V_171 != V_98 )
return ( V_171 -> V_42 == V_277 ) ;
return 0 ;
}
static int F_265 ( struct V_39 * V_42 , struct V_95 * V_96 )
{
struct V_39 * V_289 ;
struct V_31 * V_32 ;
T_6 V_88 , V_89 ;
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return - V_216 ;
V_289 = F_237 ( V_32 , V_88 , V_89 , V_96 , V_42 ) ;
if ( V_289 != V_42 )
return - V_290 ;
return 0 ;
}
static bool F_266 ( struct V_95 * V_96 )
{
struct V_282 * V_283 ;
struct V_95 * V_99 ;
int V_80 ;
F_79 () ;
F_267 (rmrr) {
F_101 (rmrr->devices,
rmrr->devices_cnt, i, tmp)
if ( V_99 == V_96 ) {
F_81 () ;
return true ;
}
}
F_81 () ;
return false ;
}
static bool F_268 ( struct V_95 * V_96 )
{
if ( ! F_266 ( V_96 ) )
return false ;
if ( F_95 ( V_96 ) ) {
struct V_100 * V_102 = F_96 ( V_96 ) ;
if ( F_269 ( V_102 ) || F_270 ( V_102 ) )
return false ;
}
return true ;
}
static int F_271 ( struct V_95 * V_96 , int V_291 )
{
if ( F_95 ( V_96 ) ) {
struct V_100 * V_102 = F_96 ( V_96 ) ;
if ( F_268 ( V_96 ) )
return 0 ;
if ( ( V_53 & V_292 ) && F_272 ( V_102 ) )
return 1 ;
if ( ( V_53 & V_54 ) && F_270 ( V_102 ) )
return 1 ;
if ( ! ( V_53 & V_293 ) )
return 0 ;
if ( ! F_273 ( V_102 ) ) {
if ( ! F_274 ( V_102 -> V_88 ) )
return 0 ;
if ( V_102 -> V_294 >> 8 == V_295 )
return 0 ;
} else if ( F_275 ( V_102 ) == V_296 )
return 0 ;
} else {
if ( F_266 ( V_96 ) )
return 0 ;
}
if ( ! V_291 ) {
V_24 V_297 = * V_96 -> V_297 ;
if ( V_96 -> V_298 &&
V_96 -> V_298 < V_297 )
V_297 = V_96 -> V_298 ;
return V_297 >= F_276 ( V_96 ) ;
}
return 1 ;
}
static int T_3 F_277 ( struct V_95 * V_96 , int V_287 )
{
int V_84 ;
if ( ! F_271 ( V_96 , 1 ) )
return 0 ;
V_84 = F_265 ( V_277 , V_96 ) ;
if ( ! V_84 )
F_48 ( L_43 ,
V_287 ? L_44 : L_45 , F_243 ( V_96 ) ) ;
else if ( V_84 == - V_216 )
V_84 = 0 ;
return V_84 ;
}
static int T_3 F_278 ( int V_287 )
{
struct V_100 * V_102 = NULL ;
struct V_77 * V_78 ;
struct V_31 * V_32 ;
struct V_95 * V_96 ;
int V_80 ;
int V_84 = 0 ;
F_197 (pdev) {
V_84 = F_277 ( & V_102 -> V_96 , V_287 ) ;
if ( V_84 )
return V_84 ;
}
F_80 (iommu, drhd)
F_101 (drhd->devices, drhd->devices_cnt, i, dev) {
struct V_299 * V_300 ;
struct V_301 * V_302 ;
if ( V_96 -> V_88 != & V_303 )
continue;
V_302 = F_279 ( V_96 ) ;
F_280 ( & V_302 -> V_304 ) ;
F_146 (pn, &adev->physical_node_list, node) {
V_84 = F_277 ( V_300 -> V_96 , V_287 ) ;
if ( V_84 )
break;
}
F_281 ( & V_302 -> V_304 ) ;
if ( V_84 )
return V_84 ;
}
return 0 ;
}
static void F_282 ( struct V_31 * V_32 )
{
if ( ! V_32 -> V_173 ) {
F_283 ( - 1 , V_32 ) ;
F_284 ( V_32 ) ;
}
if ( F_285 ( V_32 ) ) {
V_32 -> V_189 . V_233 = F_132 ;
V_32 -> V_189 . V_190 = F_137 ;
F_48 ( L_46 ,
V_32 -> V_139 ) ;
} else {
V_32 -> V_189 . V_233 = V_305 ;
V_32 -> V_189 . V_190 = V_306 ;
F_48 ( L_47 , V_32 -> V_139 ) ;
}
}
static int F_286 ( struct V_31 * V_32 ,
struct V_17 * V_307 ,
struct V_22 * * V_308 ,
int V_88 , bool V_309 )
{
int V_310 , V_311 = 0 , V_58 , V_89 , V_84 = 0 , V_56 ;
struct V_22 * V_312 = NULL , V_313 ;
struct V_22 * V_314 = NULL ;
struct V_17 V_18 ;
T_1 V_315 ;
V_310 = V_309 ? V_88 * 2 : V_88 ;
memcpy ( & V_18 , V_307 , sizeof( V_18 ) ) ;
for ( V_89 = 0 ; V_89 < 256 ; V_89 ++ ) {
V_58 = ( V_309 ? V_89 * 2 : V_89 ) % 256 ;
if ( V_58 == 0 ) {
if ( V_312 ) {
V_308 [ V_310 ] = V_312 ;
F_91 ( V_32 , V_312 ,
V_124 ) ;
V_311 = 1 ;
}
if ( V_314 )
F_287 ( V_314 ) ;
V_84 = 0 ;
if ( V_89 < 0x80 )
V_315 = F_18 ( & V_18 ) ;
else
V_315 = F_19 ( & V_18 ) ;
if ( ! V_315 ) {
if ( V_309 && V_89 == 0 ) {
V_89 = 0x7f ;
continue;
} else {
goto V_108;
}
}
V_84 = - V_140 ;
V_314 = F_288 ( V_315 , V_225 ,
V_316 ) ;
if ( ! V_314 )
goto V_108;
V_312 = F_54 ( V_32 -> V_61 ) ;
if ( ! V_312 )
goto V_317;
V_84 = 0 ;
}
memcpy ( & V_313 , V_314 + V_58 , sizeof( V_313 ) ) ;
if ( ! F_24 ( & V_313 ) )
continue;
V_56 = F_32 ( & V_313 ) ;
if ( V_56 >= 0 && V_56 < F_171 ( V_32 -> V_72 ) )
F_177 ( V_56 , V_32 -> V_198 ) ;
F_20 ( & V_313 ) ;
F_22 ( & V_313 ) ;
V_312 [ V_58 ] = V_313 ;
}
V_308 [ V_310 + V_311 ] = V_312 ;
F_91 ( V_32 , V_312 , V_124 ) ;
V_317:
F_289 ( V_314 ) ;
V_108:
return V_84 ;
}
static int F_290 ( struct V_31 * V_32 )
{
struct V_22 * * V_318 ;
struct V_17 * V_319 ;
T_1 V_320 ;
int V_321 ;
unsigned long V_33 ;
V_24 V_322 ;
int V_88 , V_84 ;
bool V_323 , V_309 ;
V_322 = V_161 ( V_32 -> V_36 + V_146 ) ;
V_309 = ! ! ( V_322 & V_144 ) ;
V_323 = ! ! F_291 ( V_32 -> V_82 ) ;
if ( V_323 != V_309 )
return - V_44 ;
V_320 = V_322 & V_20 ;
if ( ! V_320 )
return - V_44 ;
V_319 = F_288 ( V_320 , V_225 , V_316 ) ;
if ( ! V_319 )
return - V_140 ;
V_321 = V_309 ? 512 : 256 ;
V_84 = - V_140 ;
V_318 = F_52 ( V_321 * sizeof( void * ) , V_199 ) ;
if ( ! V_318 )
goto V_317;
for ( V_88 = 0 ; V_88 < 256 ; V_88 ++ ) {
V_84 = F_286 ( V_32 , & V_319 [ V_88 ] ,
V_318 , V_88 , V_309 ) ;
if ( V_84 ) {
F_123 ( L_48 ,
V_32 -> V_139 , V_88 ) ;
continue;
}
}
F_105 ( & V_32 -> V_115 , V_33 ) ;
for ( V_88 = 0 ; V_88 < 256 ; V_88 ++ ) {
int V_58 = V_309 ? V_88 * 2 : V_88 ;
V_24 V_29 ;
if ( V_318 [ V_58 ] ) {
V_29 = F_92 ( V_318 [ V_58 ] ) | 1 ;
V_32 -> V_17 [ V_88 ] . V_19 = V_29 ;
}
if ( ! V_309 || ! V_318 [ V_58 + 1 ] )
continue;
V_29 = F_92 ( V_318 [ V_58 + 1 ] ) | 1 ;
V_32 -> V_17 [ V_88 ] . V_21 = V_29 ;
}
F_106 ( & V_32 -> V_115 , V_33 ) ;
F_176 ( V_318 ) ;
F_91 ( V_32 , V_32 -> V_17 , V_225 ) ;
V_84 = 0 ;
V_317:
F_289 ( V_319 ) ;
return V_84 ;
}
static int T_3 F_292 ( void )
{
struct V_77 * V_78 ;
struct V_282 * V_283 ;
bool V_324 = false ;
struct V_95 * V_96 ;
struct V_31 * V_32 ;
int V_80 , V_84 , V_226 ;
F_293 (drhd) {
if ( V_75 < V_325 ) {
V_75 ++ ;
continue;
}
F_294 ( L_49 , V_325 ) ;
}
if ( V_75 < V_325 )
V_75 = V_325 ;
V_76 = F_174 ( V_75 , sizeof( struct V_31 * ) ,
V_199 ) ;
if ( ! V_76 ) {
F_123 ( L_50 ) ;
V_84 = - V_140 ;
goto error;
}
F_204 (cpu) {
struct V_326 * V_327 = F_295 ( & V_328 ,
V_226 ) ;
V_327 -> V_329 = F_52 ( V_75 *
sizeof( struct V_330 ) ,
V_199 ) ;
if ( ! V_327 -> V_329 ) {
V_84 = - V_140 ;
goto V_331;
}
F_173 ( & V_327 -> V_115 ) ;
F_296 ( & V_327 -> V_332 , F_205 , V_226 ) ;
}
F_80 (iommu, drhd) {
V_76 [ V_32 -> V_188 ] = V_32 ;
F_282 ( V_32 ) ;
V_84 = F_170 ( V_32 ) ;
if ( V_84 )
goto V_333;
F_43 ( V_32 ) ;
if ( F_41 ( V_32 ) && ! F_297 () ) {
F_169 ( V_32 ) ;
F_42 ( V_32 ) ;
F_251 ( L_51 ,
V_32 -> V_139 ) ;
}
V_84 = F_122 ( V_32 ) ;
if ( V_84 )
goto V_333;
if ( F_41 ( V_32 ) ) {
F_48 ( L_52 ) ;
V_84 = F_290 ( V_32 ) ;
if ( V_84 ) {
F_123 ( L_53 ,
V_32 -> V_139 ) ;
F_169 ( V_32 ) ;
F_42 ( V_32 ) ;
} else {
F_48 ( L_54 ,
V_32 -> V_139 ) ;
V_324 = true ;
}
}
if ( ! F_298 ( V_32 -> V_82 ) )
V_229 = 0 ;
#ifdef F_149
if ( V_178 ( V_32 ) )
F_299 ( V_32 ) ;
#endif
}
F_80 (iommu, drhd) {
F_130 ( V_32 ) ;
F_124 ( V_32 ) ;
V_32 -> V_189 . V_233 ( V_32 , 0 , 0 , 0 , V_156 ) ;
V_32 -> V_189 . V_190 ( V_32 , 0 , 0 , 0 , V_165 ) ;
}
if ( V_334 )
V_53 |= V_293 ;
#ifdef F_300
V_53 |= V_54 ;
#endif
F_301 () ;
if ( V_53 ) {
V_84 = F_259 ( V_229 ) ;
if ( V_84 )
goto V_333;
}
if ( V_324 )
goto V_335;
if ( V_53 ) {
V_84 = F_278 ( V_229 ) ;
if ( V_84 ) {
F_226 ( L_55 ) ;
goto V_333;
}
}
F_48 ( L_56 ) ;
F_267 (rmrr) {
F_101 (rmrr->devices, rmrr->devices_cnt,
i, dev) {
V_84 = F_255 ( V_283 , V_96 ) ;
if ( V_84 )
F_123 ( L_57 ) ;
}
}
F_256 () ;
V_335:
F_302 (iommu, drhd) {
if ( V_78 -> V_336 ) {
if ( V_337 )
F_167 ( V_32 ) ;
continue;
}
F_130 ( V_32 ) ;
#ifdef F_149
if ( V_178 ( V_32 ) && F_183 ( V_32 -> V_82 ) ) {
V_84 = F_303 ( V_32 ) ;
if ( V_84 )
goto V_333;
}
#endif
V_84 = F_304 ( V_32 ) ;
if ( V_84 )
goto V_333;
if ( ! F_41 ( V_32 ) )
F_168 ( V_32 ) ;
F_167 ( V_32 ) ;
}
return 0 ;
V_333:
F_80 (iommu, drhd) {
F_178 ( V_32 ) ;
F_182 ( V_32 ) ;
}
V_331:
F_204 (cpu)
F_176 ( F_295 ( & V_328 , V_226 ) -> V_329 ) ;
F_176 ( V_76 ) ;
error:
return V_84 ;
}
static unsigned long F_305 ( struct V_95 * V_96 ,
struct V_39 * V_42 ,
unsigned long V_338 , T_7 V_297 )
{
unsigned long V_339 = 0 ;
V_297 = F_3 ( T_7 , F_306 ( V_42 -> V_135 ) , V_297 ) ;
V_338 = F_163 ( V_338 ) ;
if ( ! V_47 && V_297 > F_307 ( 32 ) ) {
V_339 = F_308 ( & V_42 -> V_222 , V_338 ,
F_196 ( F_307 ( 32 ) ) ) ;
if ( V_339 )
return V_339 ;
}
V_339 = F_308 ( & V_42 -> V_222 , V_338 , F_196 ( V_297 ) ) ;
if ( F_309 ( ! V_339 ) ) {
F_123 ( L_58 ,
V_338 , F_243 ( V_96 ) ) ;
return 0 ;
}
return V_339 ;
}
static struct V_39 * F_310 ( struct V_95 * V_96 )
{
struct V_39 * V_42 , * V_99 ;
struct V_282 * V_283 ;
struct V_95 * V_340 ;
int V_80 , V_84 ;
V_42 = F_234 ( V_96 ) ;
if ( V_42 )
goto V_108;
V_42 = F_246 ( V_96 , V_73 ) ;
if ( ! V_42 )
goto V_108;
F_79 () ;
F_267 (rmrr) {
F_101 (rmrr->devices, rmrr->devices_cnt,
i, i_dev) {
if ( V_340 != V_96 )
continue;
V_84 = F_250 ( V_96 , V_42 ,
V_283 -> V_284 ,
V_283 -> V_285 ) ;
if ( V_84 )
F_311 ( V_96 , L_57 ) ;
}
}
F_81 () ;
V_99 = F_247 ( V_96 , V_42 ) ;
if ( ! V_99 || V_42 != V_99 ) {
F_181 ( V_42 ) ;
V_42 = V_99 ;
}
V_108:
if ( ! V_42 )
F_123 ( L_59 , F_243 ( V_96 ) ) ;
return V_42 ;
}
static int F_312 ( struct V_95 * V_96 )
{
int V_79 ;
if ( F_93 ( V_96 ) )
return 1 ;
if ( ! V_53 )
return 0 ;
V_79 = F_264 ( V_96 ) ;
if ( V_79 ) {
if ( F_271 ( V_96 , 0 ) )
return 1 ;
else {
F_244 ( V_277 , V_96 ) ;
F_48 ( L_60 ,
F_243 ( V_96 ) ) ;
return 0 ;
}
} else {
if ( F_271 ( V_96 , 0 ) ) {
int V_84 ;
V_84 = F_265 ( V_277 , V_96 ) ;
if ( ! V_84 ) {
F_48 ( L_61 ,
F_243 ( V_96 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_261 F_313 ( struct V_95 * V_96 , T_1 V_341 ,
T_5 V_59 , int V_342 , V_24 V_297 )
{
struct V_39 * V_42 ;
T_1 V_343 ;
unsigned long V_339 ;
int V_253 = 0 ;
int V_84 ;
struct V_31 * V_32 ;
unsigned long V_344 = V_341 >> V_11 ;
F_75 ( V_342 == V_345 ) ;
if ( F_312 ( V_96 ) )
return V_341 ;
V_42 = F_310 ( V_96 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_74 ( V_42 ) ;
V_59 = F_219 ( V_341 , V_59 ) ;
V_339 = F_305 ( V_96 , V_42 , F_12 ( V_59 ) , V_297 ) ;
if ( ! V_339 )
goto error;
if ( V_342 == V_346 || V_342 == V_347 || \
! F_314 ( V_32 -> V_72 ) )
V_253 |= V_125 ;
if ( V_342 == V_348 || V_342 == V_347 )
V_253 |= V_126 ;
V_84 = F_230 ( V_42 , F_13 ( V_339 ) ,
F_13 ( V_344 ) , V_59 , V_253 ) ;
if ( V_84 )
goto error;
if ( F_166 ( V_32 -> V_72 ) )
F_161 ( V_32 , V_42 ,
F_13 ( V_339 ) ,
V_59 , 0 , 1 ) ;
else
F_130 ( V_32 ) ;
V_343 = ( T_1 ) V_339 << V_11 ;
V_343 += V_341 & ~ V_242 ;
return V_343 ;
error:
if ( V_339 )
F_315 ( & V_42 -> V_222 , V_339 , F_12 ( V_59 ) ) ;
F_123 ( L_62 ,
F_243 ( V_96 ) , V_59 , ( unsigned long long ) V_341 , V_342 ) ;
return 0 ;
}
static V_261 F_316 ( struct V_95 * V_96 , struct V_14 * V_14 ,
unsigned long V_119 , T_5 V_59 ,
enum V_349 V_342 ,
unsigned long V_350 )
{
return F_313 ( V_96 , F_223 ( V_14 ) + V_119 , V_59 ,
V_342 , * V_96 -> V_297 ) ;
}
static void F_317 ( struct V_326 * V_351 )
{
int V_80 , V_352 ;
V_351 -> V_353 = 0 ;
for ( V_80 = 0 ; V_80 < V_75 ; V_80 ++ ) {
struct V_31 * V_32 = V_76 [ V_80 ] ;
struct V_330 * V_354 =
& V_351 -> V_329 [ V_80 ] ;
if ( ! V_32 )
continue;
if ( ! V_354 -> V_134 )
continue;
if ( ! F_166 ( V_32 -> V_72 ) )
V_32 -> V_189 . V_190 ( V_32 , 0 , 0 , 0 ,
V_165 ) ;
for ( V_352 = 0 ; V_352 < V_354 -> V_134 ; V_352 ++ ) {
unsigned long V_85 ;
struct V_355 * V_92 =
& V_354 -> V_356 [ V_352 ] ;
unsigned long V_339 = V_92 -> V_339 ;
unsigned long V_338 = V_92 -> V_338 ;
struct V_39 * V_42 = V_92 -> V_42 ;
struct V_14 * V_136 = V_92 -> V_136 ;
if ( F_166 ( V_32 -> V_72 ) )
F_161 ( V_32 , V_42 ,
F_13 ( V_339 ) ,
V_338 , ! V_136 , 0 ) ;
else {
V_85 = F_162 ( V_338 ) ;
F_159 ( V_42 ,
( T_7 ) V_339 << V_11 , V_85 ) ;
}
F_315 ( & V_42 -> V_222 , V_339 , V_338 ) ;
if ( V_136 )
F_121 ( V_136 ) ;
}
V_354 -> V_134 = 0 ;
}
V_351 -> V_59 = 0 ;
}
static void F_205 ( unsigned long V_357 )
{
struct V_326 * V_351 = F_295 ( & V_328 , V_357 ) ;
unsigned long V_33 ;
F_105 ( & V_351 -> V_115 , V_33 ) ;
F_317 ( V_351 ) ;
F_106 ( & V_351 -> V_115 , V_33 ) ;
}
static void F_318 ( struct V_39 * V_41 , unsigned long V_339 ,
unsigned long V_338 , struct V_14 * V_136 )
{
unsigned long V_33 ;
int V_358 , V_74 ;
struct V_31 * V_32 ;
struct V_355 * V_92 ;
struct V_326 * V_351 ;
V_351 = F_319 ( & V_328 ) ;
if ( V_351 -> V_59 == V_359 ) {
int V_226 ;
F_320 (cpu)
F_205 ( V_226 ) ;
}
F_105 ( & V_351 -> V_115 , V_33 ) ;
V_32 = F_74 ( V_41 ) ;
V_74 = V_32 -> V_188 ;
V_358 = V_351 -> V_329 [ V_74 ] . V_134 ;
++ ( V_351 -> V_329 [ V_74 ] . V_134 ) ;
V_92 = & V_351 -> V_329 [ V_74 ] . V_356 [ V_358 ] ;
V_92 -> V_42 = V_41 ;
V_92 -> V_339 = V_339 ;
V_92 -> V_338 = V_338 ;
V_92 -> V_136 = V_136 ;
if ( ! V_351 -> V_353 ) {
F_321 ( & V_351 -> V_332 , V_360 + F_322 ( 10 ) ) ;
V_351 -> V_353 = 1 ;
}
V_351 -> V_59 ++ ;
F_106 ( & V_351 -> V_115 , V_33 ) ;
}
static void F_323 ( struct V_95 * V_96 , V_261 V_361 , T_5 V_59 )
{
struct V_39 * V_42 ;
unsigned long V_129 , V_130 ;
unsigned long V_338 ;
unsigned long V_339 ;
struct V_31 * V_32 ;
struct V_14 * V_136 ;
if ( F_312 ( V_96 ) )
return;
V_42 = F_234 ( V_96 ) ;
F_75 ( ! V_42 ) ;
V_32 = F_74 ( V_42 ) ;
V_339 = F_196 ( V_361 ) ;
V_338 = F_219 ( V_361 , V_59 ) ;
V_129 = F_13 ( V_339 ) ;
V_130 = V_129 + V_338 - 1 ;
F_143 ( L_63 ,
F_243 ( V_96 ) , V_129 , V_130 ) ;
V_136 = F_120 ( V_42 , V_129 , V_130 ) ;
if ( V_48 ) {
F_161 ( V_32 , V_42 , V_129 ,
V_338 , ! V_136 , 0 ) ;
F_315 ( & V_42 -> V_222 , V_339 , F_12 ( V_338 ) ) ;
F_121 ( V_136 ) ;
} else {
F_318 ( V_42 , V_339 , V_338 , V_136 ) ;
}
}
static void F_324 ( struct V_95 * V_96 , V_261 V_361 ,
T_5 V_59 , enum V_349 V_342 ,
unsigned long V_350 )
{
F_323 ( V_96 , V_361 , V_59 ) ;
}
static void * F_325 ( struct V_95 * V_96 , T_5 V_59 ,
V_261 * V_362 , T_8 V_33 ,
unsigned long V_350 )
{
struct V_14 * V_14 = NULL ;
int V_363 ;
V_59 = F_220 ( V_59 ) ;
V_363 = F_326 ( V_59 ) ;
if ( ! F_312 ( V_96 ) )
V_33 &= ~ ( V_364 | V_365 ) ;
else if ( V_96 -> V_298 < F_276 ( V_96 ) ) {
if ( V_96 -> V_298 < F_307 ( 32 ) )
V_33 |= V_364 ;
else
V_33 |= V_365 ;
}
if ( F_327 ( V_33 ) ) {
unsigned int V_206 = V_59 >> V_11 ;
V_14 = F_328 ( V_96 , V_206 , V_363 , V_33 ) ;
if ( V_14 && F_312 ( V_96 ) &&
F_223 ( V_14 ) + V_59 > V_96 -> V_298 ) {
F_329 ( V_96 , V_14 , V_206 ) ;
V_14 = NULL ;
}
}
if ( ! V_14 )
V_14 = F_330 ( V_33 , V_363 ) ;
if ( ! V_14 )
return NULL ;
memset ( F_56 ( V_14 ) , 0 , V_59 ) ;
* V_362 = F_313 ( V_96 , F_223 ( V_14 ) , V_59 ,
V_347 ,
V_96 -> V_298 ) ;
if ( * V_362 )
return F_56 ( V_14 ) ;
if ( ! F_329 ( V_96 , V_14 , V_59 >> V_11 ) )
F_331 ( V_14 , V_363 ) ;
return NULL ;
}
static void F_332 ( struct V_95 * V_96 , T_5 V_59 , void * V_62 ,
V_261 V_362 , unsigned long V_350 )
{
int V_363 ;
struct V_14 * V_14 = F_17 ( V_62 ) ;
V_59 = F_220 ( V_59 ) ;
V_363 = F_326 ( V_59 ) ;
F_323 ( V_96 , V_362 , V_59 ) ;
if ( ! F_329 ( V_96 , V_14 , V_59 >> V_11 ) )
F_331 ( V_14 , V_363 ) ;
}
static void F_333 ( struct V_95 * V_96 , struct V_249 * V_366 ,
int V_367 , enum V_349 V_342 ,
unsigned long V_350 )
{
V_261 V_368 = F_334 ( V_366 ) & V_242 ;
unsigned long V_338 = 0 ;
struct V_249 * V_250 ;
int V_80 ;
F_335 (sglist, sg, nelems, i) {
V_338 += F_219 ( F_334 ( V_250 ) , F_336 ( V_250 ) ) ;
}
F_323 ( V_96 , V_368 , V_338 << V_12 ) ;
}
static int F_337 ( struct V_95 * V_369 ,
struct V_249 * V_366 , int V_367 , int V_342 )
{
int V_80 ;
struct V_249 * V_250 ;
F_335 (sglist, sg, nelems, i) {
F_75 ( ! F_224 ( V_250 ) ) ;
V_250 -> V_260 = F_223 ( F_224 ( V_250 ) ) + V_250 -> V_119 ;
V_250 -> V_262 = V_250 -> V_259 ;
}
return V_367 ;
}
static int F_338 ( struct V_95 * V_96 , struct V_249 * V_366 , int V_367 ,
enum V_349 V_342 , unsigned long V_350 )
{
int V_80 ;
struct V_39 * V_42 ;
T_5 V_59 = 0 ;
int V_253 = 0 ;
unsigned long V_339 ;
int V_84 ;
struct V_249 * V_250 ;
unsigned long V_370 ;
struct V_31 * V_32 ;
F_75 ( V_342 == V_345 ) ;
if ( F_312 ( V_96 ) )
return F_337 ( V_96 , V_366 , V_367 , V_342 ) ;
V_42 = F_310 ( V_96 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_74 ( V_42 ) ;
F_335 (sglist, sg, nelems, i)
V_59 += F_219 ( V_250 -> V_119 , V_250 -> V_259 ) ;
V_339 = F_305 ( V_96 , V_42 , F_12 ( V_59 ) ,
* V_96 -> V_297 ) ;
if ( ! V_339 ) {
V_366 -> V_262 = 0 ;
return 0 ;
}
if ( V_342 == V_346 || V_342 == V_347 || \
! F_314 ( V_32 -> V_72 ) )
V_253 |= V_125 ;
if ( V_342 == V_348 || V_342 == V_347 )
V_253 |= V_126 ;
V_370 = F_13 ( V_339 ) ;
V_84 = F_229 ( V_42 , V_370 , V_366 , V_59 , V_253 ) ;
if ( F_309 ( V_84 ) ) {
F_115 ( V_42 , V_370 ,
V_370 + V_59 - 1 ) ;
F_315 ( & V_42 -> V_222 , V_339 , F_12 ( V_59 ) ) ;
return 0 ;
}
if ( F_166 ( V_32 -> V_72 ) )
F_161 ( V_32 , V_42 , V_370 , V_59 , 0 , 1 ) ;
else
F_130 ( V_32 ) ;
return V_367 ;
}
static int F_339 ( struct V_95 * V_96 , V_261 V_371 )
{
return ! V_371 ;
}
static inline int F_340 ( void )
{
int V_84 = 0 ;
V_64 = F_341 ( L_64 ,
sizeof( struct V_39 ) ,
0 ,
V_372 ,
NULL ) ;
if ( ! V_64 ) {
F_123 ( L_65 ) ;
V_84 = - V_140 ;
}
return V_84 ;
}
static inline int F_342 ( void )
{
int V_84 = 0 ;
V_65 = F_341 ( L_66 ,
sizeof( struct V_170 ) ,
0 ,
V_372 ,
NULL ) ;
if ( ! V_65 ) {
F_123 ( L_67 ) ;
V_84 = - V_140 ;
}
return V_84 ;
}
static int T_3 F_343 ( void )
{
int V_84 ;
V_84 = F_344 () ;
if ( V_84 )
return V_84 ;
V_84 = F_340 () ;
if ( V_84 )
goto V_373;
V_84 = F_342 () ;
if ( ! V_84 )
return V_84 ;
F_345 ( V_64 ) ;
V_373:
F_346 () ;
return - V_140 ;
}
static void T_3 F_347 ( void )
{
F_345 ( V_65 ) ;
F_345 ( V_64 ) ;
F_346 () ;
}
static void F_348 ( struct V_100 * V_102 )
{
struct V_77 * V_78 ;
T_2 V_374 ;
int V_375 ;
V_375 = F_349 ( V_102 -> V_88 , F_350 ( 0 , 0 ) , 0xb0 , & V_374 ) ;
if ( V_375 ) {
F_351 ( & V_102 -> V_96 , L_68 ) ;
return;
}
V_374 &= 0xffff0000 ;
V_78 = F_352 ( V_102 ) ;
if ( F_353 ( ! V_78 || V_78 -> V_376 - V_374 != 0xa000 ,
V_377 ,
L_69 ) )
V_102 -> V_96 . V_97 . V_32 = V_98 ;
}
static void T_3 F_354 ( void )
{
struct V_77 * V_78 ;
struct V_95 * V_96 ;
int V_80 ;
F_293 (drhd) {
if ( ! V_78 -> V_113 ) {
F_101 (drhd->devices,
drhd->devices_cnt, i, dev)
break;
if ( V_80 == V_78 -> V_378 )
V_78 -> V_336 = 1 ;
}
}
F_355 (drhd) {
if ( V_78 -> V_113 )
continue;
F_101 (drhd->devices,
drhd->devices_cnt, i, dev)
if ( ! F_95 ( V_96 ) || ! F_270 ( F_96 ( V_96 ) ) )
break;
if ( V_80 < V_78 -> V_378 )
continue;
if ( V_46 ) {
V_379 = 1 ;
} else {
V_78 -> V_336 = 1 ;
F_101 (drhd->devices,
drhd->devices_cnt, i, dev)
V_96 -> V_97 . V_32 = V_98 ;
}
}
}
static int F_356 ( void )
{
struct V_77 * V_78 ;
struct V_31 * V_32 = NULL ;
F_80 (iommu, drhd)
if ( V_32 -> V_173 )
F_357 ( V_32 ) ;
F_302 (iommu, drhd) {
if ( V_78 -> V_336 ) {
if ( V_337 )
F_167 ( V_32 ) ;
continue;
}
F_130 ( V_32 ) ;
F_124 ( V_32 ) ;
V_32 -> V_189 . V_233 ( V_32 , 0 , 0 , 0 ,
V_156 ) ;
V_32 -> V_189 . V_190 ( V_32 , 0 , 0 , 0 , V_165 ) ;
F_168 ( V_32 ) ;
F_167 ( V_32 ) ;
}
return 0 ;
}
static void F_358 ( void )
{
struct V_77 * V_78 ;
struct V_31 * V_32 ;
F_80 (iommu, drhd) {
V_32 -> V_189 . V_233 ( V_32 , 0 , 0 , 0 ,
V_156 ) ;
V_32 -> V_189 . V_190 ( V_32 , 0 , 0 , 0 ,
V_165 ) ;
}
}
static int F_359 ( void )
{
struct V_77 * V_78 ;
struct V_31 * V_32 = NULL ;
unsigned long V_143 ;
F_80 (iommu, drhd) {
V_32 -> V_380 = F_52 ( sizeof( T_2 ) * V_381 ,
V_60 ) ;
if ( ! V_32 -> V_380 )
goto V_382;
}
F_358 () ;
F_80 (iommu, drhd) {
F_169 ( V_32 ) ;
F_125 ( & V_32 -> V_145 , V_143 ) ;
V_32 -> V_380 [ V_383 ] =
F_44 ( V_32 -> V_36 + V_384 ) ;
V_32 -> V_380 [ V_385 ] =
F_44 ( V_32 -> V_36 + V_386 ) ;
V_32 -> V_380 [ V_387 ] =
F_44 ( V_32 -> V_36 + V_388 ) ;
V_32 -> V_380 [ V_389 ] =
F_44 ( V_32 -> V_36 + V_390 ) ;
F_129 ( & V_32 -> V_145 , V_143 ) ;
}
return 0 ;
V_382:
F_80 (iommu, drhd)
F_176 ( V_32 -> V_380 ) ;
return - V_140 ;
}
static void F_360 ( void )
{
struct V_77 * V_78 ;
struct V_31 * V_32 = NULL ;
unsigned long V_143 ;
if ( F_356 () ) {
if ( V_337 )
F_361 ( L_70 ) ;
else
F_252 ( 1 , L_71 ) ;
return;
}
F_80 (iommu, drhd) {
F_125 ( & V_32 -> V_145 , V_143 ) ;
F_127 ( V_32 -> V_380 [ V_383 ] ,
V_32 -> V_36 + V_384 ) ;
F_127 ( V_32 -> V_380 [ V_385 ] ,
V_32 -> V_36 + V_386 ) ;
F_127 ( V_32 -> V_380 [ V_387 ] ,
V_32 -> V_36 + V_388 ) ;
F_127 ( V_32 -> V_380 [ V_389 ] ,
V_32 -> V_36 + V_390 ) ;
F_129 ( & V_32 -> V_145 , V_143 ) ;
}
F_80 (iommu, drhd)
F_176 ( V_32 -> V_380 ) ;
}
static void T_3 F_362 ( void )
{
F_363 ( & V_391 ) ;
}
static inline void F_362 ( void ) {}
int T_3 F_364 ( struct V_392 * V_393 , void * V_394 )
{
struct V_395 * V_283 ;
int V_253 = V_125 | V_126 ;
struct V_282 * V_396 ;
T_5 V_259 ;
V_396 = F_52 ( sizeof( * V_396 ) , V_199 ) ;
if ( ! V_396 )
goto V_108;
V_396 -> V_397 = V_393 ;
V_283 = (struct V_395 * ) V_393 ;
V_396 -> V_284 = V_283 -> V_284 ;
V_396 -> V_285 = V_283 -> V_285 ;
V_259 = V_283 -> V_285 - V_283 -> V_284 + 1 ;
V_396 -> V_398 = F_365 ( V_283 -> V_284 , V_259 , V_253 ,
V_399 ) ;
if ( ! V_396 -> V_398 )
goto V_400;
V_396 -> V_107 = F_366 ( ( void * ) ( V_283 + 1 ) ,
( ( void * ) V_283 ) + V_283 -> V_393 . V_259 ,
& V_396 -> V_378 ) ;
if ( V_396 -> V_378 && V_396 -> V_107 == NULL )
goto V_401;
F_242 ( & V_396 -> V_402 , & V_403 ) ;
return 0 ;
V_401:
F_176 ( V_396 -> V_398 ) ;
V_400:
F_176 ( V_396 ) ;
V_108:
return - V_140 ;
}
static struct V_404 * F_367 ( struct V_405 * V_406 )
{
struct V_404 * V_407 ;
struct V_405 * V_99 ;
F_368 (atsru, &dmar_atsr_units, list) {
V_99 = (struct V_405 * ) V_407 -> V_397 ;
if ( V_406 -> V_103 != V_99 -> V_103 )
continue;
if ( V_406 -> V_393 . V_259 != V_99 -> V_393 . V_259 )
continue;
if ( memcmp ( V_406 , V_99 , V_406 -> V_393 . V_259 ) == 0 )
return V_407 ;
}
return NULL ;
}
int F_369 ( struct V_392 * V_397 , void * V_394 )
{
struct V_405 * V_406 ;
struct V_404 * V_407 ;
if ( V_408 >= V_409 && ! V_410 )
return 0 ;
V_406 = F_46 ( V_397 , struct V_405 , V_393 ) ;
V_407 = F_367 ( V_406 ) ;
if ( V_407 )
return 0 ;
V_407 = F_52 ( sizeof( * V_407 ) + V_397 -> V_259 , V_199 ) ;
if ( ! V_407 )
return - V_140 ;
V_407 -> V_397 = ( void * ) ( V_407 + 1 ) ;
memcpy ( V_407 -> V_397 , V_397 , V_397 -> V_259 ) ;
V_407 -> V_113 = V_406 -> V_33 & 0x1 ;
if ( ! V_407 -> V_113 ) {
V_407 -> V_107 = F_366 ( ( void * ) ( V_406 + 1 ) ,
( void * ) V_406 + V_406 -> V_393 . V_259 ,
& V_407 -> V_378 ) ;
if ( V_407 -> V_378 && V_407 -> V_107 == NULL ) {
F_176 ( V_407 ) ;
return - V_140 ;
}
}
F_370 ( & V_407 -> V_402 , & V_411 ) ;
return 0 ;
}
static void F_371 ( struct V_404 * V_407 )
{
F_372 ( & V_407 -> V_107 , & V_407 -> V_378 ) ;
F_176 ( V_407 ) ;
}
int F_373 ( struct V_392 * V_397 , void * V_394 )
{
struct V_405 * V_406 ;
struct V_404 * V_407 ;
V_406 = F_46 ( V_397 , struct V_405 , V_393 ) ;
V_407 = F_367 ( V_406 ) ;
if ( V_407 ) {
F_374 ( & V_407 -> V_402 ) ;
F_375 () ;
F_371 ( V_407 ) ;
}
return 0 ;
}
int F_376 ( struct V_392 * V_397 , void * V_394 )
{
int V_80 ;
struct V_95 * V_96 ;
struct V_405 * V_406 ;
struct V_404 * V_407 ;
V_406 = F_46 ( V_397 , struct V_405 , V_393 ) ;
V_407 = F_367 ( V_406 ) ;
if ( ! V_407 )
return 0 ;
if ( ! V_407 -> V_113 && V_407 -> V_107 && V_407 -> V_378 ) {
F_101 (atsru->devices, atsru->devices_cnt,
i, dev)
return - V_290 ;
}
return 0 ;
}
static int F_377 ( struct V_77 * V_412 )
{
int V_413 , V_84 = 0 ;
struct V_31 * V_32 = V_412 -> V_32 ;
if ( V_76 [ V_32 -> V_188 ] )
return 0 ;
if ( V_229 && ! F_298 ( V_32 -> V_82 ) ) {
F_251 ( L_72 ,
V_32 -> V_139 ) ;
return - V_414 ;
}
if ( ! F_83 ( V_32 -> V_82 ) &&
F_82 ( V_32 ) ) {
F_251 ( L_73 ,
V_32 -> V_139 ) ;
return - V_414 ;
}
V_413 = F_84 ( V_32 ) - 1 ;
if ( V_413 >= 0 && ! ( F_85 ( V_32 -> V_72 ) & ( 1 << V_413 ) ) ) {
F_251 ( L_74 ,
V_32 -> V_139 ) ;
return - V_414 ;
}
if ( V_32 -> V_147 & V_195 )
F_169 ( V_32 ) ;
V_76 [ V_32 -> V_188 ] = V_32 ;
V_84 = F_170 ( V_32 ) ;
if ( V_84 == 0 )
V_84 = F_122 ( V_32 ) ;
if ( V_84 )
goto V_108;
#ifdef F_149
if ( V_178 ( V_32 ) )
F_299 ( V_32 ) ;
#endif
if ( V_412 -> V_336 ) {
if ( V_337 )
F_167 ( V_32 ) ;
return 0 ;
}
F_282 ( V_32 ) ;
F_130 ( V_32 ) ;
#ifdef F_149
if ( V_178 ( V_32 ) && F_183 ( V_32 -> V_82 ) ) {
V_84 = F_303 ( V_32 ) ;
if ( V_84 )
goto V_415;
}
#endif
V_84 = F_304 ( V_32 ) ;
if ( V_84 )
goto V_415;
F_124 ( V_32 ) ;
V_32 -> V_189 . V_233 ( V_32 , 0 , 0 , 0 , V_156 ) ;
V_32 -> V_189 . V_190 ( V_32 , 0 , 0 , 0 , V_165 ) ;
F_168 ( V_32 ) ;
F_167 ( V_32 ) ;
return 0 ;
V_415:
F_178 ( V_32 ) ;
V_108:
F_182 ( V_32 ) ;
return V_84 ;
}
int F_378 ( struct V_77 * V_412 , bool V_416 )
{
int V_84 = 0 ;
struct V_31 * V_32 = V_412 -> V_32 ;
if ( ! V_410 )
return 0 ;
if ( V_32 == NULL )
return - V_44 ;
if ( V_416 ) {
V_84 = F_377 ( V_412 ) ;
} else {
F_178 ( V_32 ) ;
F_182 ( V_32 ) ;
}
return V_84 ;
}
static void F_379 ( void )
{
struct V_282 * V_396 , * V_417 ;
struct V_404 * V_407 , * V_418 ;
F_179 (rmrru, rmrr_n, &dmar_rmrr_units, list) {
F_233 ( & V_396 -> V_402 ) ;
F_372 ( & V_396 -> V_107 , & V_396 -> V_378 ) ;
F_176 ( V_396 -> V_398 ) ;
F_176 ( V_396 ) ;
}
F_179 (atsru, atsr_n, &dmar_atsr_units, list) {
F_233 ( & V_407 -> V_402 ) ;
F_371 ( V_407 ) ;
}
}
int F_240 ( struct V_100 * V_96 )
{
int V_80 , V_84 = 1 ;
struct V_419 * V_88 ;
struct V_100 * V_420 = NULL ;
struct V_95 * V_99 ;
struct V_405 * V_406 ;
struct V_404 * V_407 ;
V_96 = F_97 ( V_96 ) ;
for ( V_88 = V_96 -> V_88 ; V_88 ; V_88 = V_88 -> V_118 ) {
V_420 = V_88 -> V_421 ;
if ( ! V_420 )
return 1 ;
if ( ! F_273 ( V_420 ) ||
F_275 ( V_420 ) == V_296 )
return 0 ;
if ( F_275 ( V_420 ) == V_422 )
break;
}
F_79 () ;
F_368 (atsru, &dmar_atsr_units, list) {
V_406 = F_46 ( V_407 -> V_397 , struct V_405 , V_393 ) ;
if ( V_406 -> V_103 != F_98 ( V_96 -> V_88 ) )
continue;
F_380 (atsru->devices, atsru->devices_cnt, i, tmp)
if ( V_99 == & V_420 -> V_96 )
goto V_108;
if ( V_407 -> V_113 )
goto V_108;
}
V_84 = 0 ;
V_108:
F_81 () ;
return V_84 ;
}
int F_381 ( struct V_423 * V_171 )
{
int V_84 = 0 ;
struct V_282 * V_396 ;
struct V_404 * V_407 ;
struct V_405 * V_406 ;
struct V_395 * V_283 ;
if ( ! V_410 && V_408 >= V_409 )
return 0 ;
F_146 (rmrru, &dmar_rmrr_units, list) {
V_283 = F_46 ( V_396 -> V_397 ,
struct V_395 , V_393 ) ;
if ( V_171 -> V_424 == V_425 ) {
V_84 = F_382 ( V_171 , ( void * ) ( V_283 + 1 ) ,
( ( void * ) V_283 ) + V_283 -> V_393 . V_259 ,
V_283 -> V_103 , V_396 -> V_107 ,
V_396 -> V_378 ) ;
if( V_84 < 0 )
return V_84 ;
} else if ( V_171 -> V_424 == V_426 ) {
F_383 ( V_171 , V_283 -> V_103 ,
V_396 -> V_107 , V_396 -> V_378 ) ;
}
}
F_146 (atsru, &dmar_atsr_units, list) {
if ( V_407 -> V_113 )
continue;
V_406 = F_46 ( V_407 -> V_397 , struct V_405 , V_393 ) ;
if ( V_171 -> V_424 == V_425 ) {
V_84 = F_382 ( V_171 , ( void * ) ( V_406 + 1 ) ,
( void * ) V_406 + V_406 -> V_393 . V_259 ,
V_406 -> V_103 , V_407 -> V_107 ,
V_407 -> V_378 ) ;
if ( V_84 > 0 )
break;
else if( V_84 < 0 )
return V_84 ;
} else if ( V_171 -> V_424 == V_426 ) {
if ( F_383 ( V_171 , V_406 -> V_103 ,
V_407 -> V_107 , V_407 -> V_378 ) )
break;
}
}
return 0 ;
}
static int F_384 ( struct V_427 * V_428 ,
unsigned long V_429 , void * V_240 )
{
struct V_95 * V_96 = V_240 ;
struct V_39 * V_42 ;
if ( F_93 ( V_96 ) )
return 0 ;
if ( V_429 != V_426 )
return 0 ;
V_42 = F_234 ( V_96 ) ;
if ( ! V_42 )
return 0 ;
F_244 ( V_42 , V_96 ) ;
if ( ! F_67 ( V_42 ) && F_385 ( & V_42 -> V_107 ) )
F_181 ( V_42 ) ;
return 0 ;
}
static int F_386 ( struct V_427 * V_428 ,
unsigned long V_29 , void * V_430 )
{
struct V_431 * V_432 = V_430 ;
unsigned long long V_221 , V_112 ;
unsigned long V_370 , V_276 ;
switch ( V_29 ) {
case V_433 :
V_221 = V_432 -> V_129 << V_11 ;
V_112 = ( ( V_432 -> V_129 + V_432 -> V_252 ) << V_11 ) - 1 ;
if ( F_249 ( V_277 , V_221 , V_112 ) ) {
F_251 ( L_75 ,
V_221 , V_112 ) ;
return V_434 ;
}
break;
case V_435 :
case V_436 :
V_370 = F_13 ( V_432 -> V_129 ) ;
V_276 = F_13 ( V_432 -> V_129 + V_432 -> V_252 - 1 ) ;
while ( V_370 <= V_276 ) {
struct V_208 * V_208 ;
struct V_77 * V_78 ;
struct V_31 * V_32 ;
struct V_14 * V_136 ;
V_208 = F_387 ( & V_277 -> V_222 , V_370 ) ;
if ( V_208 == NULL ) {
F_143 ( L_76 ,
V_370 ) ;
break;
}
V_208 = F_388 ( & V_277 -> V_222 , V_208 ,
V_370 , V_276 ) ;
if ( V_208 == NULL ) {
F_251 ( L_77 ,
V_370 , V_276 ) ;
return V_434 ;
}
V_136 = F_120 ( V_277 , V_208 -> V_437 ,
V_208 -> V_438 ) ;
F_79 () ;
F_80 (iommu, drhd)
F_161 ( V_32 , V_277 ,
V_208 -> V_437 , F_389 ( V_208 ) ,
! V_136 , 0 ) ;
F_81 () ;
F_121 ( V_136 ) ;
V_370 = V_208 -> V_438 + 1 ;
F_390 ( V_208 ) ;
}
break;
}
return V_439 ;
}
static void F_391 ( unsigned int V_226 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_75 ; V_80 ++ ) {
struct V_31 * V_32 = V_76 [ V_80 ] ;
struct V_39 * V_42 ;
int V_56 ;
if ( ! V_32 )
continue;
for ( V_56 = 0 ; V_56 < F_171 ( V_32 -> V_72 ) ; V_56 ++ ) {
V_42 = F_50 ( V_32 , ( T_4 ) V_56 ) ;
if ( ! V_42 )
continue;
F_392 ( V_226 , & V_42 -> V_222 ) ;
}
}
}
static int F_393 ( unsigned int V_226 )
{
F_391 ( V_226 ) ;
F_205 ( V_226 ) ;
return 0 ;
}
static void F_394 ( void )
{
struct V_31 * V_32 = NULL ;
struct V_77 * V_78 ;
F_302 (iommu, drhd)
F_169 ( V_32 ) ;
}
static inline struct V_31 * F_395 ( struct V_95 * V_96 )
{
struct V_440 * V_441 = F_396 ( V_96 ) ;
return F_46 ( V_441 , struct V_31 , V_32 ) ;
}
static T_9 F_397 ( struct V_95 * V_96 ,
struct V_442 * V_443 ,
char * V_444 )
{
struct V_31 * V_32 = F_395 ( V_96 ) ;
T_2 V_445 = F_44 ( V_32 -> V_36 + V_446 ) ;
return sprintf ( V_444 , L_78 ,
F_398 ( V_445 ) , F_399 ( V_445 ) ) ;
}
static T_9 F_400 ( struct V_95 * V_96 ,
struct V_442 * V_443 ,
char * V_444 )
{
struct V_31 * V_32 = F_395 ( V_96 ) ;
return sprintf ( V_444 , L_79 , V_32 -> V_447 ) ;
}
static T_9 F_401 ( struct V_95 * V_96 ,
struct V_442 * V_443 ,
char * V_444 )
{
struct V_31 * V_32 = F_395 ( V_96 ) ;
return sprintf ( V_444 , L_79 , V_32 -> V_72 ) ;
}
static T_9 F_402 ( struct V_95 * V_96 ,
struct V_442 * V_443 ,
char * V_444 )
{
struct V_31 * V_32 = F_395 ( V_96 ) ;
return sprintf ( V_444 , L_79 , V_32 -> V_82 ) ;
}
static T_9 F_403 ( struct V_95 * V_96 ,
struct V_442 * V_443 ,
char * V_444 )
{
struct V_31 * V_32 = F_395 ( V_96 ) ;
return sprintf ( V_444 , L_80 , F_171 ( V_32 -> V_72 ) ) ;
}
static T_9 F_404 ( struct V_95 * V_96 ,
struct V_442 * V_443 ,
char * V_444 )
{
struct V_31 * V_32 = F_395 ( V_96 ) ;
return sprintf ( V_444 , L_81 , F_405 ( V_32 -> V_198 ,
F_171 ( V_32 -> V_72 ) ) ) ;
}
int T_3 F_406 ( void )
{
int V_84 = - V_216 ;
struct V_77 * V_78 ;
struct V_31 * V_32 ;
V_337 = F_407 () ;
if ( F_343 () ) {
if ( V_337 )
F_361 ( L_82 ) ;
return - V_140 ;
}
F_408 ( & V_448 ) ;
if ( F_409 () ) {
if ( V_337 )
F_361 ( L_83 ) ;
goto V_449;
}
if ( F_410 () < 0 ) {
if ( V_337 )
F_361 ( L_84 ) ;
goto V_449;
}
if ( V_450 || V_45 ) {
if ( V_55 ) {
F_302 (iommu, drhd)
F_167 ( V_32 ) ;
}
F_394 () ;
goto V_449;
}
if ( F_385 ( & V_403 ) )
F_48 ( L_85 ) ;
if ( F_385 ( & V_411 ) )
F_48 ( L_86 ) ;
if ( F_192 () ) {
if ( V_337 )
F_361 ( L_87 ) ;
goto V_451;
}
F_354 () ;
V_84 = F_292 () ;
if ( V_84 ) {
if ( V_337 )
F_361 ( L_88 ) ;
F_123 ( L_89 ) ;
goto V_451;
}
F_411 ( & V_448 ) ;
F_48 ( L_90 ) ;
#ifdef F_412
V_452 = 0 ;
#endif
V_453 = & V_454 ;
F_362 () ;
F_80 (iommu, drhd) {
F_413 ( & V_32 -> V_32 , NULL ,
V_455 ,
L_91 , V_32 -> V_139 ) ;
F_414 ( & V_32 -> V_32 , & V_456 ) ;
F_415 ( & V_32 -> V_32 ) ;
}
F_416 ( & V_457 , & V_456 ) ;
F_417 ( & V_457 , & V_458 ) ;
if ( V_277 && ! V_229 )
F_418 ( & V_459 ) ;
F_419 ( V_460 , L_92 , NULL ,
F_393 ) ;
V_410 = 1 ;
return 0 ;
V_451:
F_207 ( & V_209 ) ;
V_449:
F_379 () ;
F_411 ( & V_448 ) ;
F_347 () ;
return V_84 ;
}
static int F_420 ( struct V_100 * V_102 , T_4 V_237 , void * V_238 )
{
struct V_31 * V_32 = V_238 ;
F_231 ( V_32 , F_214 ( V_237 ) , V_237 & 0xff ) ;
return 0 ;
}
static void F_421 ( struct V_31 * V_32 , struct V_95 * V_96 )
{
if ( ! V_32 || ! V_96 || ! F_95 ( V_96 ) )
return;
F_216 ( F_96 ( V_96 ) , & F_420 , V_32 ) ;
}
static void F_180 ( struct V_170 * V_171 )
{
struct V_31 * V_32 ;
unsigned long V_33 ;
F_145 ( & V_172 ) ;
if ( F_53 ( ! V_171 ) )
return;
V_32 = V_171 -> V_32 ;
if ( V_171 -> V_96 ) {
F_155 ( V_171 ) ;
F_421 ( V_32 , V_171 -> V_96 ) ;
}
F_232 ( V_171 ) ;
F_105 ( & V_32 -> V_115 , V_33 ) ;
F_190 ( V_171 -> V_42 , V_32 ) ;
F_106 ( & V_32 -> V_115 , V_33 ) ;
F_64 ( V_171 ) ;
}
static void F_244 ( struct V_39 * V_42 ,
struct V_95 * V_96 )
{
struct V_170 * V_171 ;
unsigned long V_33 ;
F_105 ( & V_172 , V_33 ) ;
V_171 = V_96 -> V_97 . V_32 ;
F_180 ( V_171 ) ;
F_106 ( & V_172 , V_33 ) ;
}
static int F_260 ( struct V_39 * V_42 , int V_223 )
{
int V_224 ;
F_193 ( & V_42 -> V_222 , V_124 , V_210 ,
V_211 ) ;
F_198 ( V_42 ) ;
V_42 -> V_135 = V_223 ;
V_224 = F_200 ( V_223 ) ;
V_42 -> V_1 = F_4 ( V_224 ) ;
V_42 -> V_81 = 0 ;
V_42 -> V_86 = 0 ;
V_42 -> V_87 = 0 ;
V_42 -> V_461 = 0 ;
V_42 -> V_120 = (struct V_27 * ) F_54 ( V_42 -> V_123 ) ;
if ( ! V_42 -> V_120 )
return - V_140 ;
F_102 ( V_42 , V_42 -> V_120 , V_225 ) ;
return 0 ;
}
static struct V_40 * F_422 ( unsigned type )
{
struct V_39 * V_39 ;
struct V_40 * V_42 ;
if ( type != V_462 )
return NULL ;
V_39 = F_186 ( V_66 ) ;
if ( ! V_39 ) {
F_123 ( L_93 ) ;
return NULL ;
}
if ( F_260 ( V_39 , V_73 ) ) {
F_123 ( L_94 ) ;
F_181 ( V_39 ) ;
return NULL ;
}
F_87 ( V_39 ) ;
V_42 = & V_39 -> V_42 ;
V_42 -> V_463 . V_464 = 0 ;
V_42 -> V_463 . V_465 = F_423 ( V_39 -> V_135 ) ;
V_42 -> V_463 . V_466 = true ;
return V_42 ;
}
static void F_424 ( struct V_40 * V_42 )
{
F_181 ( F_45 ( V_42 ) ) ;
}
static int F_425 ( struct V_40 * V_42 ,
struct V_95 * V_96 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_31 * V_32 ;
int V_68 ;
T_6 V_88 , V_89 ;
if ( F_268 ( V_96 ) ) {
F_426 ( V_96 , L_95 ) ;
return - V_467 ;
}
if ( F_309 ( F_218 ( V_96 ) ) ) {
struct V_39 * V_468 ;
V_468 = F_234 ( V_96 ) ;
if ( V_468 ) {
F_79 () ;
F_244 ( V_468 , V_96 ) ;
F_81 () ;
if ( ! F_67 ( V_468 ) &&
F_385 ( & V_468 -> V_107 ) )
F_181 ( V_468 ) ;
}
}
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return - V_216 ;
V_68 = F_2 ( V_32 -> V_1 ) ;
if ( V_68 > F_202 ( V_32 -> V_72 ) )
V_68 = F_202 ( V_32 -> V_72 ) ;
if ( V_39 -> V_461 > ( 1LL << V_68 ) ) {
F_123 ( L_96
L_97 ,
V_469 , V_68 , V_39 -> V_461 ) ;
return - V_288 ;
}
V_39 -> V_135 = V_68 ;
while ( V_32 -> V_1 < V_39 -> V_1 ) {
struct V_27 * V_28 ;
V_28 = V_39 -> V_120 ;
if ( F_38 ( V_28 ) ) {
V_39 -> V_120 = (struct V_27 * )
F_90 ( F_35 ( V_28 ) ) ;
F_57 ( V_28 ) ;
}
V_39 -> V_1 -- ;
}
return F_265 ( V_39 , V_96 ) ;
}
static void F_427 ( struct V_40 * V_42 ,
struct V_95 * V_96 )
{
F_244 ( F_45 ( V_42 ) , V_96 ) ;
}
static int F_428 ( struct V_40 * V_42 ,
unsigned long V_208 , T_1 V_470 ,
T_5 V_59 , int V_471 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
V_24 V_461 ;
int V_253 = 0 ;
int V_84 ;
if ( V_471 & V_472 )
V_253 |= V_125 ;
if ( V_471 & V_473 )
V_253 |= V_126 ;
if ( ( V_471 & V_474 ) && V_39 -> V_86 )
V_253 |= V_258 ;
V_461 = V_208 + V_59 ;
if ( V_39 -> V_461 < V_461 ) {
V_24 V_112 ;
V_112 = F_423 ( V_39 -> V_135 ) + 1 ;
if ( V_112 < V_461 ) {
F_123 ( L_96
L_97 ,
V_469 , V_39 -> V_135 , V_461 ) ;
return - V_288 ;
}
V_39 -> V_461 = V_461 ;
}
V_59 = F_219 ( V_470 , V_59 ) ;
V_84 = F_230 ( V_39 , V_208 >> V_12 ,
V_470 >> V_12 , V_59 , V_253 ) ;
return V_84 ;
}
static T_5 F_429 ( struct V_40 * V_42 ,
unsigned long V_208 , T_5 V_59 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_14 * V_136 = NULL ;
struct V_31 * V_32 ;
unsigned long V_129 , V_130 ;
unsigned int V_475 ;
int V_74 , V_5 = 0 ;
F_75 ( ! F_109 ( V_39 , V_208 >> V_12 , & V_5 ) ) ;
if ( V_59 < V_124 << F_6 ( V_5 ) )
V_59 = V_124 << F_6 ( V_5 ) ;
V_129 = V_208 >> V_12 ;
V_130 = ( V_208 + V_59 - 1 ) >> V_12 ;
V_136 = F_120 ( V_39 , V_129 , V_130 ) ;
V_475 = V_130 - V_129 + 1 ;
F_76 (iommu_id, dmar_domain) {
V_32 = V_76 [ V_74 ] ;
F_161 ( V_76 [ V_74 ] , V_39 ,
V_129 , V_475 , ! V_136 , 0 ) ;
}
F_121 ( V_136 ) ;
if ( V_39 -> V_461 == V_208 + V_59 )
V_39 -> V_461 = V_208 ;
return V_59 ;
}
static T_1 F_430 ( struct V_40 * V_42 ,
V_261 V_208 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_27 * V_28 ;
int V_5 = 0 ;
V_24 V_476 = 0 ;
V_28 = F_109 ( V_39 , V_208 >> V_12 , & V_5 ) ;
if ( V_28 )
V_476 = F_35 ( V_28 ) ;
return V_476 ;
}
static bool F_431 ( enum V_477 V_72 )
{
if ( V_72 == V_478 )
return F_82 ( NULL ) == 1 ;
if ( V_72 == V_479 )
return V_480 == 1 ;
return false ;
}
static int F_432 ( struct V_95 * V_96 )
{
struct V_31 * V_32 ;
struct V_481 * V_482 ;
T_6 V_88 , V_89 ;
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return - V_216 ;
F_433 ( & V_32 -> V_32 , V_96 ) ;
V_482 = F_434 ( V_96 ) ;
if ( F_435 ( V_482 ) )
return F_436 ( V_482 ) ;
F_437 ( V_482 ) ;
return 0 ;
}
static void F_438 ( struct V_95 * V_96 )
{
struct V_31 * V_32 ;
T_6 V_88 , V_89 ;
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return;
F_439 ( V_96 ) ;
F_440 ( & V_32 -> V_32 , V_96 ) ;
}
static void F_441 ( struct V_95 * V_95 ,
struct V_483 * V_484 )
{
struct V_485 * V_36 ;
struct V_282 * V_283 ;
struct V_95 * V_340 ;
int V_80 ;
F_79 () ;
F_267 (rmrr) {
F_101 (rmrr->devices, rmrr->devices_cnt,
i, i_dev) {
if ( V_340 != V_95 )
continue;
F_442 ( & V_283 -> V_398 -> V_402 , V_484 ) ;
}
}
F_81 () ;
V_36 = F_365 ( V_214 ,
V_215 - V_214 + 1 ,
0 , V_486 ) ;
if ( ! V_36 )
return;
F_442 ( & V_36 -> V_402 , V_484 ) ;
}
static void F_443 ( struct V_95 * V_96 ,
struct V_483 * V_484 )
{
struct V_485 * V_92 , * V_134 ;
F_179 (entry, next, head, list) {
if ( V_92 -> type == V_487 )
F_176 ( V_92 ) ;
}
}
static inline unsigned long F_444 ( struct V_31 * V_32 )
{
if ( F_445 ( V_32 -> V_82 ) < 5 )
return 0 ;
return F_446 ( ( unsigned long * ) & V_32 -> V_488 ,
V_489 ) - 5 ;
}
int F_447 ( struct V_31 * V_32 , struct V_490 * V_491 )
{
struct V_170 * V_171 ;
struct V_22 * V_23 ;
struct V_39 * V_42 ;
unsigned long V_33 ;
V_24 V_492 ;
int V_84 ;
V_42 = F_310 ( V_491 -> V_96 ) ;
if ( ! V_42 )
return - V_44 ;
F_105 ( & V_172 , V_33 ) ;
F_211 ( & V_32 -> V_115 ) ;
V_84 = - V_44 ;
V_171 = V_491 -> V_96 -> V_97 . V_32 ;
if ( ! V_171 || ! V_171 -> V_177 )
goto V_108;
V_23 = F_88 ( V_32 , V_171 -> V_88 , V_171 -> V_89 , 0 ) ;
if ( F_53 ( ! V_23 ) )
goto V_108;
V_492 = V_23 [ 0 ] . V_19 ;
V_491 -> V_56 = V_42 -> V_187 [ V_32 -> V_188 ] ;
V_491 -> V_182 = F_448 ( V_171 -> V_88 , V_171 -> V_89 ) ;
if ( ! ( V_492 & V_493 ) ) {
V_23 [ 1 ] . V_21 = ( V_24 ) F_92 ( V_32 -> V_494 ) ;
V_23 [ 1 ] . V_19 = ( V_24 ) F_92 ( V_32 -> V_495 ) |
F_444 ( V_32 ) ;
F_449 () ;
if ( ( V_492 & V_496 ) == ( V_230 << 2 ) ) {
V_492 &= ~ V_496 ;
if ( V_171 -> V_174 )
V_492 |= V_497 << 2 ;
else
V_492 |= V_498 << 2 ;
}
V_492 |= V_493 ;
if ( V_32 -> V_494 )
V_492 |= V_499 ;
if ( V_171 -> V_179 )
V_492 |= V_500 ;
V_23 [ 0 ] . V_19 = V_492 ;
F_449 () ;
V_32 -> V_189 . V_233 ( V_32 , V_491 -> V_56 , V_491 -> V_182 ,
V_234 ,
V_158 ) ;
}
if ( ! V_171 -> V_178 )
F_148 ( V_171 ) ;
if ( V_171 -> V_176 ) {
V_491 -> V_501 = 1 ;
V_491 -> V_183 = V_171 -> V_181 ;
if ( V_491 -> V_183 >= V_502 )
V_491 -> V_183 = 0 ;
}
V_84 = 0 ;
V_108:
F_212 ( & V_32 -> V_115 ) ;
F_106 ( & V_172 , V_33 ) ;
return V_84 ;
}
struct V_31 * F_450 ( struct V_95 * V_96 )
{
struct V_31 * V_32 ;
T_6 V_88 , V_89 ;
if ( F_93 ( V_96 ) ) {
F_426 ( V_96 ,
L_98 ) ;
return NULL ;
}
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ( ! V_32 ) ) {
F_311 ( V_96 , L_99 ) ;
return NULL ;
}
if ( ! V_32 -> V_495 ) {
F_311 ( V_96 , L_100 ) ;
return NULL ;
}
return V_32 ;
}
static void F_451 ( struct V_100 * V_96 )
{
F_48 ( L_101 ) ;
V_46 = 0 ;
}
static void F_452 ( struct V_100 * V_96 )
{
F_48 ( L_102 ) ;
V_151 = 1 ;
}
static void F_453 ( struct V_100 * V_96 )
{
unsigned short V_503 ;
if ( F_454 ( V_96 , V_504 , & V_503 ) )
return;
if ( ! ( V_503 & V_505 ) ) {
F_48 ( L_103 ) ;
V_46 = 0 ;
} else if ( V_46 ) {
F_48 ( L_104 ) ;
V_48 = 1 ;
}
}
static void T_3 F_301 ( void )
{
struct V_100 * V_102 ;
T_10 V_506 ;
V_102 = F_455 ( V_507 , 0x3a3e , NULL ) ;
if ( ! V_102 )
return;
F_258 ( V_102 ) ;
V_102 = F_455 ( V_507 , 0x342e , NULL ) ;
if ( ! V_102 )
return;
if ( F_456 ( V_102 , 0x188 , & V_506 ) ) {
F_258 ( V_102 ) ;
return;
}
F_258 ( V_102 ) ;
if ( V_506 & 1 )
return;
V_506 &= 0x1c ;
if ( V_506 == 0x10 )
return;
if ( ! V_506 ) {
F_252 ( 1 , L_105
L_38 ,
F_253 ( V_278 ) ,
F_253 ( V_279 ) ,
F_253 ( V_280 ) ) ;
V_53 |= V_292 ;
return;
}
F_251 ( L_106 ,
V_506 ) ;
}
