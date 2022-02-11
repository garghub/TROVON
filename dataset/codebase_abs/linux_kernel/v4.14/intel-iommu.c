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
#ifdef F_97
if ( F_98 ( V_102 -> V_88 ) )
return NULL ;
#endif
V_104 = F_99 ( V_102 ) ;
V_96 = & V_104 -> V_96 ;
V_103 = F_100 ( V_102 -> V_88 ) ;
} else if ( F_101 ( V_96 ) )
V_96 = & F_102 ( V_96 ) -> V_96 ;
F_79 () ;
F_80 (iommu, drhd) {
if ( V_102 && V_103 != V_78 -> V_103 )
continue;
F_103 (drhd->devices,
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
static void F_104 ( struct V_39 * V_42 ,
void * V_114 , int V_59 )
{
if ( ! V_42 -> V_81 )
F_105 ( V_114 , V_59 ) ;
}
static int F_106 ( struct V_31 * V_32 , T_6 V_88 , T_6 V_89 )
{
struct V_22 * V_23 ;
int V_84 = 0 ;
unsigned long V_33 ;
F_107 ( & V_32 -> V_115 , V_33 ) ;
V_23 = F_88 ( V_32 , V_88 , V_89 , 0 ) ;
if ( V_23 )
V_84 = F_25 ( V_23 ) ;
F_108 ( & V_32 -> V_115 , V_33 ) ;
return V_84 ;
}
static void F_109 ( struct V_31 * V_32 )
{
int V_80 ;
unsigned long V_33 ;
struct V_22 * V_23 ;
F_107 ( & V_32 -> V_115 , V_33 ) ;
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
F_108 ( & V_32 -> V_115 , V_33 ) ;
}
static struct V_27 * F_110 ( struct V_39 * V_42 ,
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
F_104 ( V_42 , V_121 , V_124 ) ;
V_122 = ( ( T_7 ) F_16 ( V_121 ) << V_12 ) | V_125 | V_126 ;
if ( F_111 ( & V_28 -> V_29 , 0ULL , V_122 ) )
F_57 ( V_121 ) ;
else
F_104 ( V_42 , V_28 , sizeof( * V_28 ) ) ;
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
static struct V_27 * F_112 ( struct V_39 * V_42 ,
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
static void F_113 ( struct V_39 * V_42 ,
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
V_131 = V_28 = F_112 ( V_42 , V_129 , 1 , & V_127 ) ;
if ( ! V_28 ) {
V_129 = F_10 ( V_129 + 1 , V_127 + 1 ) ;
continue;
}
do {
F_34 ( V_28 ) ;
V_129 += F_11 ( V_127 ) ;
V_28 ++ ;
} while ( V_129 <= V_130 && ! F_40 ( V_28 ) );
F_104 ( V_42 , V_131 ,
( void * ) V_28 - ( void * ) V_131 ) ;
} while ( V_129 && V_129 <= V_130 );
}
static void F_114 ( struct V_39 * V_42 , int V_5 ,
int V_132 , struct V_27 * V_28 ,
unsigned long V_6 , unsigned long V_129 ,
unsigned long V_130 )
{
V_6 = F_115 ( V_129 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_133 ;
struct V_27 * V_134 ;
if ( ! F_38 ( V_28 ) || F_39 ( V_28 ) )
goto V_135;
V_133 = V_6 & F_8 ( V_5 ) ;
V_134 = F_90 ( F_35 ( V_28 ) ) ;
if ( V_5 > 2 ) {
F_114 ( V_42 , V_5 - 1 , V_132 ,
V_134 , V_133 , V_129 ,
V_130 ) ;
}
if ( V_5 < V_132 && ! ( V_129 > V_133 ||
V_130 < V_133 + F_9 ( V_5 ) - 1 ) ) {
F_34 ( V_28 ) ;
F_104 ( V_42 , V_28 , sizeof( * V_28 ) ) ;
F_57 ( V_134 ) ;
}
V_135:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_40 ( ++ V_28 ) && V_6 <= V_130 );
}
static void F_116 ( struct V_39 * V_42 ,
unsigned long V_129 ,
unsigned long V_130 ,
int V_132 )
{
F_75 ( ! F_68 ( V_42 , V_129 ) ) ;
F_75 ( ! F_68 ( V_42 , V_130 ) ) ;
F_75 ( V_129 > V_130 ) ;
F_113 ( V_42 , V_129 , V_130 ) ;
F_114 ( V_42 , F_1 ( V_42 -> V_1 ) , V_132 ,
V_42 -> V_120 , 0 , V_129 , V_130 ) ;
if ( V_129 == 0 && V_130 == F_117 ( V_42 -> V_136 ) ) {
F_57 ( V_42 -> V_120 ) ;
V_42 -> V_120 = NULL ;
}
}
static struct V_14 * F_118 ( struct V_39 * V_42 ,
int V_5 , struct V_27 * V_28 ,
struct V_14 * V_137 )
{
struct V_14 * V_15 ;
V_15 = F_119 ( F_35 ( V_28 ) >> V_11 ) ;
V_15 -> V_137 = V_137 ;
V_137 = V_15 ;
if ( V_5 == 1 )
return V_137 ;
V_28 = F_56 ( V_15 ) ;
do {
if ( F_38 ( V_28 ) && ! F_39 ( V_28 ) )
V_137 = F_118 ( V_42 , V_5 - 1 ,
V_28 , V_137 ) ;
V_28 ++ ;
} while ( ! F_40 ( V_28 ) );
return V_137 ;
}
static struct V_14 * F_120 ( struct V_39 * V_42 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_129 ,
unsigned long V_130 ,
struct V_14 * V_137 )
{
struct V_27 * V_131 = NULL , * V_138 = NULL ;
V_6 = F_115 ( V_129 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_133 ;
if ( ! F_38 ( V_28 ) )
goto V_135;
V_133 = V_6 & F_8 ( V_5 ) ;
if ( V_129 <= V_133 &&
V_130 >= V_133 + F_9 ( V_5 ) - 1 ) {
if ( V_5 > 1 && ! F_39 ( V_28 ) )
V_137 = F_118 ( V_42 , V_5 - 1 , V_28 , V_137 ) ;
F_34 ( V_28 ) ;
if ( ! V_131 )
V_131 = V_28 ;
V_138 = V_28 ;
} else if ( V_5 > 1 ) {
V_137 = F_120 ( V_42 , V_5 - 1 ,
F_90 ( F_35 ( V_28 ) ) ,
V_133 , V_129 , V_130 ,
V_137 ) ;
}
V_135:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_40 ( ++ V_28 ) && V_6 <= V_130 );
if ( V_131 )
F_104 ( V_42 , V_131 ,
( void * ) ++ V_138 - ( void * ) V_131 ) ;
return V_137 ;
}
static struct V_14 * F_121 ( struct V_39 * V_42 ,
unsigned long V_129 ,
unsigned long V_130 )
{
struct V_14 * V_137 = NULL ;
F_75 ( ! F_68 ( V_42 , V_129 ) ) ;
F_75 ( ! F_68 ( V_42 , V_130 ) ) ;
F_75 ( V_129 > V_130 ) ;
V_137 = F_120 ( V_42 , F_1 ( V_42 -> V_1 ) ,
V_42 -> V_120 , 0 , V_129 , V_130 , NULL ) ;
if ( V_129 == 0 && V_130 == F_117 ( V_42 -> V_136 ) ) {
struct V_14 * V_139 = F_17 ( V_42 -> V_120 ) ;
V_139 -> V_137 = V_137 ;
V_137 = V_139 ;
V_42 -> V_120 = NULL ;
}
return V_137 ;
}
static void F_122 ( struct V_14 * V_137 )
{
struct V_14 * V_15 ;
while ( ( V_15 = V_137 ) ) {
V_137 = V_15 -> V_137 ;
F_57 ( F_56 ( V_15 ) ) ;
}
}
static void F_123 ( unsigned long V_140 )
{
struct V_14 * V_137 = (struct V_14 * ) V_140 ;
F_122 ( V_137 ) ;
}
static int F_124 ( struct V_31 * V_32 )
{
struct V_17 * V_91 ;
unsigned long V_33 ;
V_91 = (struct V_17 * ) F_54 ( V_32 -> V_61 ) ;
if ( ! V_91 ) {
F_125 ( L_20 ,
V_32 -> V_141 ) ;
return - V_142 ;
}
F_91 ( V_32 , V_91 , V_143 ) ;
F_107 ( & V_32 -> V_115 , V_33 ) ;
V_32 -> V_17 = V_91 ;
F_108 ( & V_32 -> V_115 , V_33 ) ;
return 0 ;
}
static void F_126 ( struct V_31 * V_32 )
{
V_24 V_114 ;
T_2 V_144 ;
unsigned long V_145 ;
V_114 = F_92 ( V_32 -> V_17 ) ;
if ( F_89 ( V_32 ) )
V_114 |= V_146 ;
F_127 ( & V_32 -> V_147 , V_145 ) ;
F_128 ( V_32 -> V_36 + V_148 , V_114 ) ;
F_129 ( V_32 -> V_149 | V_150 , V_32 -> V_36 + V_151 ) ;
F_130 ( V_32 , V_37 ,
F_44 , ( V_144 & V_152 ) , V_144 ) ;
F_131 ( & V_32 -> V_147 , V_145 ) ;
}
static void F_132 ( struct V_31 * V_32 )
{
T_2 V_29 ;
unsigned long V_145 ;
if ( ! V_153 && ! F_133 ( V_32 -> V_72 ) )
return;
F_127 ( & V_32 -> V_147 , V_145 ) ;
F_129 ( V_32 -> V_149 | V_154 , V_32 -> V_36 + V_151 ) ;
F_130 ( V_32 , V_37 ,
F_44 , ( ! ( V_29 & V_155 ) ) , V_29 ) ;
F_131 ( & V_32 -> V_147 , V_145 ) ;
}
static void F_134 ( struct V_31 * V_32 ,
T_4 V_56 , T_4 V_156 , T_6 V_157 ,
V_24 type )
{
V_24 V_29 = 0 ;
unsigned long V_145 ;
switch ( type ) {
case V_158 :
V_29 = V_158 ;
break;
case V_159 :
V_29 = V_159 | F_135 ( V_56 ) ;
break;
case V_160 :
V_29 = V_160 | F_135 ( V_56 )
| F_136 ( V_156 ) | F_137 ( V_157 ) ;
break;
default:
F_138 () ;
}
V_29 |= V_161 ;
F_127 ( & V_32 -> V_147 , V_145 ) ;
F_128 ( V_32 -> V_36 + V_162 , V_29 ) ;
F_130 ( V_32 , V_162 ,
V_163 , ( ! ( V_29 & V_161 ) ) , V_29 ) ;
F_131 ( & V_32 -> V_147 , V_145 ) ;
}
static void F_139 ( struct V_31 * V_32 , T_4 V_56 ,
V_24 V_114 , unsigned int V_164 , V_24 type )
{
int V_165 = F_140 ( V_32 -> V_82 ) ;
V_24 V_29 = 0 , V_166 = 0 ;
unsigned long V_145 ;
switch ( type ) {
case V_167 :
V_29 = V_167 | V_168 ;
break;
case V_169 :
V_29 = V_169 | V_168 | F_141 ( V_56 ) ;
break;
case V_170 :
V_29 = V_170 | V_168 | F_141 ( V_56 ) ;
V_166 = V_164 | V_114 ;
break;
default:
F_138 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_142 ( V_32 -> V_72 ) )
V_29 |= V_171 ;
F_127 ( & V_32 -> V_147 , V_145 ) ;
if ( V_166 )
F_128 ( V_32 -> V_36 + V_165 , V_166 ) ;
F_128 ( V_32 -> V_36 + V_165 + 8 , V_29 ) ;
F_130 ( V_32 , V_165 + 8 ,
V_163 , ( ! ( V_29 & V_168 ) ) , V_29 ) ;
F_131 ( & V_32 -> V_147 , V_145 ) ;
if ( F_143 ( V_29 ) == 0 )
F_125 ( L_21 ) ;
if ( F_143 ( V_29 ) != F_144 ( type ) )
F_145 ( L_22 ,
( unsigned long long ) F_144 ( type ) ,
( unsigned long long ) F_143 ( V_29 ) ) ;
}
static struct V_172 *
F_146 ( struct V_39 * V_42 , struct V_31 * V_32 ,
T_6 V_88 , T_6 V_89 )
{
struct V_172 * V_173 ;
F_147 ( & V_174 ) ;
if ( ! V_32 -> V_175 )
return NULL ;
F_148 (info, &domain->devices, link)
if ( V_173 -> V_32 == V_32 && V_173 -> V_88 == V_88 &&
V_173 -> V_89 == V_89 ) {
if ( V_173 -> V_176 && V_173 -> V_96 )
return V_173 ;
break;
}
return NULL ;
}
static void F_149 ( struct V_39 * V_42 )
{
struct V_172 * V_173 ;
bool V_177 = false ;
F_147 ( & V_174 ) ;
F_148 (info, &domain->devices, link) {
struct V_100 * V_102 ;
if ( ! V_173 -> V_96 || ! F_95 ( V_173 -> V_96 ) )
continue;
V_102 = F_96 ( V_173 -> V_96 ) ;
if ( V_102 -> V_178 ) {
V_177 = true ;
break;
}
}
V_42 -> V_177 = V_177 ;
}
static void F_150 ( struct V_172 * V_173 )
{
struct V_100 * V_102 ;
F_147 ( & V_174 ) ;
if ( ! V_173 || ! F_95 ( V_173 -> V_96 ) )
return;
V_102 = F_96 ( V_173 -> V_96 ) ;
#ifdef F_151
if ( V_173 -> V_179 && ! F_152 ( V_102 , V_173 -> V_179 & ~ 1 ) )
V_173 -> V_180 = 1 ;
if ( V_173 -> V_181 && ! F_153 ( V_102 ) && ! F_154 ( V_102 , 32 ) )
V_173 -> V_182 = 1 ;
#endif
if ( V_173 -> V_176 && ! F_155 ( V_102 , V_12 ) ) {
V_173 -> V_178 = 1 ;
F_149 ( V_173 -> V_42 ) ;
V_173 -> V_183 = F_156 ( V_102 ) ;
}
}
static void F_157 ( struct V_172 * V_173 )
{
struct V_100 * V_102 ;
F_147 ( & V_174 ) ;
if ( ! F_95 ( V_173 -> V_96 ) )
return;
V_102 = F_96 ( V_173 -> V_96 ) ;
if ( V_173 -> V_178 ) {
F_158 ( V_102 ) ;
V_173 -> V_178 = 0 ;
F_149 ( V_173 -> V_42 ) ;
}
#ifdef F_151
if ( V_173 -> V_182 ) {
F_159 ( V_102 ) ;
V_173 -> V_182 = 0 ;
}
if ( V_173 -> V_180 ) {
F_160 ( V_102 ) ;
V_173 -> V_180 = 0 ;
}
#endif
}
static void F_161 ( struct V_39 * V_42 ,
V_24 V_114 , unsigned V_85 )
{
T_4 V_184 , V_185 ;
unsigned long V_33 ;
struct V_172 * V_173 ;
if ( ! V_42 -> V_177 )
return;
F_107 ( & V_174 , V_33 ) ;
F_148 (info, &domain->devices, link) {
if ( ! V_173 -> V_178 )
continue;
V_184 = V_173 -> V_88 << 8 | V_173 -> V_89 ;
V_185 = V_173 -> V_183 ;
F_162 ( V_173 -> V_32 , V_184 , V_185 , V_114 , V_85 ) ;
}
F_108 ( & V_174 , V_33 ) ;
}
static void F_163 ( struct V_31 * V_32 ,
struct V_39 * V_42 ,
unsigned long V_6 , unsigned int V_186 ,
int V_187 , int V_188 )
{
unsigned int V_85 = F_164 ( F_165 ( V_186 ) ) ;
T_7 V_114 = ( T_7 ) V_6 << V_12 ;
T_4 V_56 = V_42 -> V_189 [ V_32 -> V_190 ] ;
F_75 ( V_186 == 0 ) ;
if ( V_187 )
V_187 = 1 << 6 ;
if ( ! F_166 ( V_32 -> V_72 ) || V_85 > F_167 ( V_32 -> V_72 ) )
V_32 -> V_191 . V_192 ( V_32 , V_56 , 0 , 0 ,
V_169 ) ;
else
V_32 -> V_191 . V_192 ( V_32 , V_56 , V_114 | V_187 , V_85 ,
V_170 ) ;
if ( ! F_168 ( V_32 -> V_72 ) || ! V_188 )
F_161 ( F_50 ( V_32 , V_56 ) ,
V_114 , V_85 ) ;
}
static void F_169 ( struct V_193 * V_194 )
{
struct V_39 * V_42 ;
int V_58 ;
V_42 = F_46 ( V_194 , struct V_39 , V_194 ) ;
F_76 (idx, domain) {
struct V_31 * V_32 = V_76 [ V_58 ] ;
T_4 V_56 = V_42 -> V_189 [ V_32 -> V_190 ] ;
V_32 -> V_191 . V_192 ( V_32 , V_56 , 0 , 0 , V_169 ) ;
if ( ! F_168 ( V_32 -> V_72 ) )
F_161 ( F_50 ( V_32 , V_56 ) ,
0 , V_9 ) ;
}
}
static void F_170 ( struct V_31 * V_32 )
{
T_2 V_195 ;
unsigned long V_33 ;
F_127 ( & V_32 -> V_147 , V_33 ) ;
V_195 = F_44 ( V_32 -> V_36 + V_196 ) ;
V_195 &= ~ V_197 ;
F_129 ( V_195 , V_32 -> V_36 + V_196 ) ;
F_130 ( V_32 , V_196 ,
F_44 , ! ( V_195 & V_198 ) , V_195 ) ;
F_131 ( & V_32 -> V_147 , V_33 ) ;
}
static void F_171 ( struct V_31 * V_32 )
{
T_2 V_144 ;
unsigned long V_33 ;
F_127 ( & V_32 -> V_147 , V_33 ) ;
V_32 -> V_149 |= V_199 ;
F_129 ( V_32 -> V_149 , V_32 -> V_36 + V_151 ) ;
F_130 ( V_32 , V_37 ,
F_44 , ( V_144 & V_38 ) , V_144 ) ;
F_131 ( & V_32 -> V_147 , V_33 ) ;
}
static void F_172 ( struct V_31 * V_32 )
{
T_2 V_144 ;
unsigned long V_145 ;
F_127 ( & V_32 -> V_147 , V_145 ) ;
V_32 -> V_149 &= ~ V_199 ;
F_129 ( V_32 -> V_149 , V_32 -> V_36 + V_151 ) ;
F_130 ( V_32 , V_37 ,
F_44 , ( ! ( V_144 & V_38 ) ) , V_144 ) ;
F_131 ( & V_32 -> V_147 , V_145 ) ;
}
static int F_173 ( struct V_31 * V_32 )
{
T_2 V_200 , V_201 ;
T_5 V_59 ;
V_200 = F_174 ( V_32 -> V_72 ) ;
F_145 ( L_23 ,
V_32 -> V_141 , V_200 ) ;
V_201 = F_175 ( V_200 ) ;
F_176 ( & V_32 -> V_115 ) ;
V_32 -> V_202 = F_177 ( V_201 , sizeof( unsigned long ) , V_203 ) ;
if ( ! V_32 -> V_202 ) {
F_125 ( L_24 ,
V_32 -> V_141 ) ;
return - V_142 ;
}
V_59 = ( F_178 ( V_200 , 256 ) >> 8 ) * sizeof( struct V_39 * * ) ;
V_32 -> V_57 = F_52 ( V_59 , V_203 ) ;
if ( V_32 -> V_57 ) {
V_59 = 256 * sizeof( struct V_39 * ) ;
V_32 -> V_57 [ 0 ] = F_52 ( V_59 , V_203 ) ;
}
if ( ! V_32 -> V_57 || ! V_32 -> V_57 [ 0 ] ) {
F_125 ( L_25 ,
V_32 -> V_141 ) ;
F_179 ( V_32 -> V_202 ) ;
F_179 ( V_32 -> V_57 ) ;
V_32 -> V_202 = NULL ;
V_32 -> V_57 = NULL ;
return - V_142 ;
}
F_180 ( 0 , V_32 -> V_202 ) ;
return 0 ;
}
static void F_181 ( struct V_31 * V_32 )
{
struct V_172 * V_173 , * V_99 ;
unsigned long V_33 ;
if ( ! V_32 -> V_57 || ! V_32 -> V_202 )
return;
V_204:
F_107 ( & V_174 , V_33 ) ;
F_182 (info, tmp, &device_domain_list, global) {
struct V_39 * V_42 ;
if ( V_173 -> V_32 != V_32 )
continue;
if ( ! V_173 -> V_96 || ! V_173 -> V_42 )
continue;
V_42 = V_173 -> V_42 ;
F_183 ( V_173 ) ;
if ( ! F_67 ( V_42 ) ) {
F_108 ( & V_174 , V_33 ) ;
F_184 ( V_42 ) ;
goto V_204;
}
}
F_108 ( & V_174 , V_33 ) ;
if ( V_32 -> V_149 & V_199 )
F_172 ( V_32 ) ;
}
static void F_185 ( struct V_31 * V_32 )
{
if ( ( V_32 -> V_57 ) && ( V_32 -> V_202 ) ) {
int V_205 = F_178 ( F_174 ( V_32 -> V_72 ) , 256 ) >> 8 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_205 ; V_80 ++ )
F_179 ( V_32 -> V_57 [ V_80 ] ) ;
F_179 ( V_32 -> V_57 ) ;
F_179 ( V_32 -> V_202 ) ;
V_32 -> V_57 = NULL ;
V_32 -> V_202 = NULL ;
}
V_76 [ V_32 -> V_190 ] = NULL ;
F_109 ( V_32 ) ;
#ifdef F_151
if ( V_180 ( V_32 ) ) {
if ( F_186 ( V_32 -> V_82 ) )
F_187 ( V_32 ) ;
F_188 ( V_32 ) ;
}
#endif
}
static struct V_39 * F_189 ( int V_33 )
{
struct V_39 * V_42 ;
V_42 = F_59 () ;
if ( ! V_42 )
return NULL ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_123 = - 1 ;
V_42 -> V_33 = V_33 ;
V_42 -> V_177 = false ;
F_190 ( & V_42 -> V_107 ) ;
return V_42 ;
}
static int F_191 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
unsigned long V_200 ;
int V_206 ;
F_147 ( & V_174 ) ;
F_147 ( & V_32 -> V_115 ) ;
V_42 -> V_207 [ V_32 -> V_190 ] += 1 ;
V_42 -> V_208 += 1 ;
if ( V_42 -> V_207 [ V_32 -> V_190 ] == 1 ) {
V_200 = F_174 ( V_32 -> V_72 ) ;
V_206 = F_192 ( V_32 -> V_202 , V_200 ) ;
if ( V_206 >= V_200 ) {
F_125 ( L_26 , V_32 -> V_141 ) ;
V_42 -> V_207 [ V_32 -> V_190 ] -= 1 ;
V_42 -> V_208 -= 1 ;
return - V_209 ;
}
F_180 ( V_206 , V_32 -> V_202 ) ;
F_51 ( V_32 , V_206 , V_42 ) ;
V_42 -> V_189 [ V_32 -> V_190 ] = V_206 ;
V_42 -> V_123 = V_32 -> V_61 ;
F_87 ( V_42 ) ;
}
return 0 ;
}
static int F_193 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
int V_206 , V_210 = V_211 ;
F_147 ( & V_174 ) ;
F_147 ( & V_32 -> V_115 ) ;
V_42 -> V_207 [ V_32 -> V_190 ] -= 1 ;
V_210 = -- V_42 -> V_208 ;
if ( V_42 -> V_207 [ V_32 -> V_190 ] == 0 ) {
V_206 = V_42 -> V_189 [ V_32 -> V_190 ] ;
F_194 ( V_206 , V_32 -> V_202 ) ;
F_51 ( V_32 , V_206 , NULL ) ;
F_87 ( V_42 ) ;
V_42 -> V_189 [ V_32 -> V_190 ] = 0 ;
}
return V_210 ;
}
static int F_195 ( void )
{
struct V_100 * V_102 = NULL ;
struct V_212 * V_212 ;
int V_80 ;
F_196 ( & V_213 , V_124 , V_214 ,
V_215 ) ;
F_197 ( & V_213 . V_216 ,
& V_217 ) ;
V_212 = F_198 ( & V_213 , F_199 ( V_218 ) ,
F_199 ( V_219 ) ) ;
if ( ! V_212 ) {
F_125 ( L_27 ) ;
return - V_220 ;
}
F_200 (pdev) {
struct V_221 * V_222 ;
for ( V_80 = 0 ; V_80 < V_223 ; V_80 ++ ) {
V_222 = & V_102 -> V_221 [ V_80 ] ;
if ( ! V_222 -> V_33 || ! ( V_222 -> V_33 & V_224 ) )
continue;
V_212 = F_198 ( & V_213 ,
F_199 ( V_222 -> V_225 ) ,
F_199 ( V_222 -> V_112 ) ) ;
if ( ! V_212 ) {
F_125 ( L_28 ) ;
return - V_220 ;
}
}
}
return 0 ;
}
static void F_201 ( struct V_39 * V_42 )
{
F_202 ( & V_213 , & V_42 -> V_194 ) ;
}
static inline int F_203 ( int V_136 )
{
int V_1 ;
int V_222 = ( V_136 - 12 ) % 9 ;
if ( V_222 == 0 )
V_1 = V_136 ;
else
V_1 = V_136 + 9 - V_222 ;
if ( V_1 > 64 )
V_1 = 64 ;
return V_1 ;
}
static int F_204 ( struct V_39 * V_42 , struct V_31 * V_32 ,
int V_226 )
{
int V_227 , V_1 ;
unsigned long V_71 ;
int V_228 ;
F_196 ( & V_42 -> V_194 , V_124 , V_214 ,
V_215 ) ;
V_228 = F_205 ( & V_42 -> V_194 ,
F_169 , F_123 ) ;
if ( V_228 )
return V_228 ;
F_201 ( V_42 ) ;
if ( V_226 > F_206 ( V_32 -> V_72 ) )
V_226 = F_206 ( V_32 -> V_72 ) ;
V_42 -> V_136 = V_226 ;
V_227 = F_203 ( V_226 ) ;
V_1 = F_4 ( V_227 ) ;
V_71 = F_70 ( V_32 -> V_72 ) ;
if ( ! F_71 ( V_1 , & V_71 ) ) {
F_145 ( L_29 , V_1 ) ;
V_1 = F_207 ( & V_71 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_220 ;
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
return - V_142 ;
F_91 ( V_32 , V_42 -> V_120 , V_229 ) ;
return 0 ;
}
static void F_184 ( struct V_39 * V_42 )
{
struct V_14 * V_137 = NULL ;
if ( ! V_42 )
return;
F_79 () ;
F_208 ( V_42 ) ;
F_81 () ;
F_209 ( & V_42 -> V_194 ) ;
V_137 = F_121 ( V_42 , 0 , F_117 ( V_42 -> V_136 ) ) ;
F_122 ( V_137 ) ;
F_61 ( V_42 ) ;
}
static int F_210 ( struct V_39 * V_42 ,
struct V_31 * V_32 ,
T_6 V_88 , T_6 V_89 )
{
T_4 V_56 = V_42 -> V_189 [ V_32 -> V_190 ] ;
int V_230 = V_231 ;
struct V_172 * V_173 = NULL ;
struct V_22 * V_23 ;
unsigned long V_33 ;
struct V_27 * V_120 ;
int V_84 , V_1 ;
F_53 ( V_56 == 0 ) ;
if ( V_232 && F_66 ( V_42 ) )
V_230 = V_233 ;
F_145 ( L_30 ,
V_88 , F_211 ( V_89 ) , F_212 ( V_89 ) ) ;
F_75 ( ! V_42 -> V_120 ) ;
F_107 ( & V_174 , V_33 ) ;
F_213 ( & V_32 -> V_115 ) ;
V_84 = - V_142 ;
V_23 = F_88 ( V_32 , V_88 , V_89 , 1 ) ;
if ( ! V_23 )
goto V_234;
V_84 = 0 ;
if ( F_25 ( V_23 ) )
goto V_234;
if ( F_23 ( V_23 ) ) {
T_4 V_235 = F_32 ( V_23 ) ;
if ( V_235 >= 0 && V_235 < F_174 ( V_32 -> V_72 ) ) {
V_32 -> V_191 . V_236 ( V_32 , V_235 ,
( ( ( T_4 ) V_88 ) << 8 ) | V_89 ,
V_237 ,
V_160 ) ;
V_32 -> V_191 . V_192 ( V_32 , V_235 , 0 , 0 ,
V_169 ) ;
}
}
V_120 = V_42 -> V_120 ;
F_33 ( V_23 ) ;
F_31 ( V_23 , V_56 ) ;
if ( V_230 != V_233 ) {
for ( V_1 = V_42 -> V_1 ; V_1 != V_32 -> V_1 ; V_1 -- ) {
V_84 = - V_142 ;
V_120 = F_90 ( F_35 ( V_120 ) ) ;
if ( ! F_38 ( V_120 ) )
goto V_234;
}
V_173 = F_146 ( V_42 , V_32 , V_88 , V_89 ) ;
if ( V_173 && V_173 -> V_176 )
V_230 = V_238 ;
else
V_230 = V_231 ;
F_29 ( V_23 , F_92 ( V_120 ) ) ;
F_30 ( V_23 , V_32 -> V_1 ) ;
} else {
F_30 ( V_23 , V_32 -> V_239 ) ;
}
F_28 ( V_23 , V_230 ) ;
F_27 ( V_23 ) ;
F_26 ( V_23 ) ;
F_104 ( V_42 , V_23 , sizeof( * V_23 ) ) ;
if ( F_168 ( V_32 -> V_72 ) ) {
V_32 -> V_191 . V_236 ( V_32 , 0 ,
( ( ( T_4 ) V_88 ) << 8 ) | V_89 ,
V_237 ,
V_160 ) ;
V_32 -> V_191 . V_192 ( V_32 , V_56 , 0 , 0 , V_169 ) ;
} else {
F_132 ( V_32 ) ;
}
F_150 ( V_173 ) ;
V_84 = 0 ;
V_234:
F_214 ( & V_32 -> V_115 ) ;
F_108 ( & V_174 , V_33 ) ;
return V_84 ;
}
static int F_215 ( struct V_100 * V_102 ,
T_4 V_240 , void * V_241 )
{
struct V_242 * V_140 = V_241 ;
return F_210 ( V_140 -> V_42 , V_140 -> V_32 ,
F_216 ( V_240 ) , V_240 & 0xff ) ;
}
static int
F_217 ( struct V_39 * V_42 , struct V_95 * V_96 )
{
struct V_31 * V_32 ;
T_6 V_88 , V_89 ;
struct V_242 V_140 ;
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return - V_220 ;
if ( ! F_95 ( V_96 ) )
return F_210 ( V_42 , V_32 , V_88 , V_89 ) ;
V_140 . V_42 = V_42 ;
V_140 . V_32 = V_32 ;
return F_218 ( F_96 ( V_96 ) ,
& F_215 , & V_140 ) ;
}
static int F_219 ( struct V_100 * V_102 ,
T_4 V_240 , void * V_241 )
{
struct V_31 * V_32 = V_241 ;
return ! F_106 ( V_32 , F_216 ( V_240 ) , V_240 & 0xff ) ;
}
static int F_220 ( struct V_95 * V_96 )
{
struct V_31 * V_32 ;
T_6 V_88 , V_89 ;
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return - V_220 ;
if ( ! F_95 ( V_96 ) )
return F_106 ( V_32 , V_88 , V_89 ) ;
return ! F_218 ( F_96 ( V_96 ) ,
F_219 , V_32 ) ;
}
static inline unsigned long F_221 ( unsigned long V_243 ,
T_5 V_59 )
{
V_243 &= ~ V_244 ;
return F_222 ( V_243 + V_59 ) >> V_12 ;
}
static inline int F_223 ( struct V_39 * V_42 ,
unsigned long V_245 ,
unsigned long V_246 ,
unsigned long V_186 )
{
int V_247 , V_5 = 1 ;
unsigned long V_248 ;
V_247 = V_42 -> V_87 ;
V_248 = V_245 | V_246 ;
while ( V_247 && ! ( V_248 & ~ V_249 ) ) {
V_186 >>= V_250 ;
if ( ! V_186 )
break;
V_248 >>= V_250 ;
V_5 ++ ;
V_247 -- ;
}
return V_5 ;
}
static int F_224 ( struct V_39 * V_42 , unsigned long V_245 ,
struct V_251 * V_252 , unsigned long V_253 ,
unsigned long V_254 , int V_255 )
{
struct V_27 * V_131 = NULL , * V_28 = NULL ;
T_1 V_256 ( V_122 ) ;
unsigned long V_257 = 0 ;
unsigned int V_258 = 0 ;
unsigned long V_259 = 0 ;
F_75 ( ! F_68 ( V_42 , V_245 + V_254 - 1 ) ) ;
if ( ( V_255 & ( V_125 | V_126 ) ) == 0 )
return - V_44 ;
V_255 &= V_125 | V_126 | V_260 ;
if ( ! V_252 ) {
V_257 = V_254 ;
V_122 = ( ( T_1 ) V_253 << V_12 ) | V_255 ;
}
while ( V_254 > 0 ) {
T_7 V_99 ;
if ( ! V_257 ) {
V_257 = F_221 ( V_252 -> V_119 , V_252 -> V_261 ) ;
V_252 -> V_262 = ( ( V_263 ) V_245 << V_12 ) + V_252 -> V_119 ;
V_252 -> V_264 = V_252 -> V_261 ;
V_122 = F_225 ( F_226 ( V_252 ) ) | V_255 ;
V_253 = V_122 >> V_12 ;
}
if ( ! V_28 ) {
V_258 = F_223 ( V_42 , V_245 , V_253 , V_257 ) ;
V_131 = V_28 = F_110 ( V_42 , V_245 , & V_258 ) ;
if ( ! V_28 )
return - V_142 ;
if ( V_258 > 1 ) {
unsigned long V_265 , V_266 ;
V_122 |= V_30 ;
V_259 = F_11 ( V_258 ) ;
V_265 = V_257 / V_259 ;
V_266 = V_245 + V_265 * V_259 - 1 ;
F_116 ( V_42 , V_245 , V_266 ,
V_258 + 1 ) ;
} else {
V_122 &= ~ ( T_7 ) V_30 ;
}
}
V_99 = F_227 ( & V_28 -> V_29 , 0ULL , V_122 ) ;
if ( V_99 ) {
static int V_267 = 5 ;
F_228 ( L_31 ,
V_245 , V_99 , ( unsigned long long ) V_122 ) ;
if ( V_267 ) {
V_267 -- ;
F_229 ( NULL ) ;
}
F_53 ( 1 ) ;
}
V_259 = F_11 ( V_258 ) ;
F_75 ( V_254 < V_259 ) ;
F_75 ( V_257 < V_259 ) ;
V_254 -= V_259 ;
V_245 += V_259 ;
V_253 += V_259 ;
V_122 += V_259 * V_124 ;
V_257 -= V_259 ;
V_28 ++ ;
if ( ! V_254 || F_40 ( V_28 ) ||
( V_258 > 1 && V_257 < V_259 ) ) {
F_104 ( V_42 , V_131 ,
( void * ) V_28 - ( void * ) V_131 ) ;
V_28 = NULL ;
}
if ( ! V_257 && V_254 )
V_252 = F_230 ( V_252 ) ;
}
return 0 ;
}
static inline int F_231 ( struct V_39 * V_42 , unsigned long V_245 ,
struct V_251 * V_252 , unsigned long V_254 ,
int V_255 )
{
return F_224 ( V_42 , V_245 , V_252 , 0 , V_254 , V_255 ) ;
}
static inline int F_232 ( struct V_39 * V_42 , unsigned long V_245 ,
unsigned long V_253 , unsigned long V_254 ,
int V_255 )
{
return F_224 ( V_42 , V_245 , NULL , V_253 , V_254 , V_255 ) ;
}
static void F_233 ( struct V_31 * V_32 , T_6 V_88 , T_6 V_89 )
{
unsigned long V_33 ;
struct V_22 * V_23 ;
T_4 V_235 ;
if ( ! V_32 )
return;
F_107 ( & V_32 -> V_115 , V_33 ) ;
V_23 = F_88 ( V_32 , V_88 , V_89 , 0 ) ;
if ( ! V_23 ) {
F_108 ( & V_32 -> V_115 , V_33 ) ;
return;
}
V_235 = F_32 ( V_23 ) ;
F_33 ( V_23 ) ;
F_91 ( V_32 , V_23 , sizeof( * V_23 ) ) ;
F_108 ( & V_32 -> V_115 , V_33 ) ;
V_32 -> V_191 . V_236 ( V_32 ,
V_235 ,
( ( ( T_4 ) V_88 ) << 8 ) | V_89 ,
V_237 ,
V_160 ) ;
V_32 -> V_191 . V_192 ( V_32 ,
V_235 ,
0 ,
0 ,
V_169 ) ;
}
static inline void F_234 ( struct V_172 * V_173 )
{
F_147 ( & V_174 ) ;
F_235 ( & V_173 -> V_268 ) ;
F_235 ( & V_173 -> V_269 ) ;
if ( V_173 -> V_96 )
V_173 -> V_96 -> V_97 . V_32 = NULL ;
}
static void F_208 ( struct V_39 * V_42 )
{
struct V_172 * V_173 , * V_99 ;
unsigned long V_33 ;
F_107 ( & V_174 , V_33 ) ;
F_182 (info, tmp, &domain->devices, link)
F_183 ( V_173 ) ;
F_108 ( & V_174 , V_33 ) ;
}
static struct V_39 * F_236 ( struct V_95 * V_96 )
{
struct V_172 * V_173 ;
V_173 = V_96 -> V_97 . V_32 ;
if ( F_237 ( V_173 ) )
return V_173 -> V_42 ;
return NULL ;
}
static inline struct V_172 *
F_238 ( int V_103 , int V_88 , int V_89 )
{
struct V_172 * V_173 ;
F_148 (info, &device_domain_list, global)
if ( V_173 -> V_32 -> V_103 == V_103 && V_173 -> V_88 == V_88 &&
V_173 -> V_89 == V_89 )
return V_173 ;
return NULL ;
}
static struct V_39 * F_239 ( struct V_31 * V_32 ,
int V_88 , int V_89 ,
struct V_95 * V_96 ,
struct V_39 * V_42 )
{
struct V_39 * V_79 = NULL ;
struct V_172 * V_173 ;
unsigned long V_33 ;
int V_84 ;
V_173 = F_63 () ;
if ( ! V_173 )
return NULL ;
V_173 -> V_88 = V_88 ;
V_173 -> V_89 = V_89 ;
V_173 -> V_176 = V_173 -> V_179 = V_173 -> V_181 = 0 ;
V_173 -> V_178 = V_173 -> V_180 = V_173 -> V_182 = 0 ;
V_173 -> V_183 = 0 ;
V_173 -> V_96 = V_96 ;
V_173 -> V_42 = V_42 ;
V_173 -> V_32 = V_32 ;
if ( V_96 && F_95 ( V_96 ) ) {
struct V_100 * V_102 = F_96 ( V_173 -> V_96 ) ;
if ( F_240 ( V_32 -> V_82 ) &&
F_241 ( V_102 , V_270 ) &&
F_242 ( V_102 ) )
V_173 -> V_176 = 1 ;
if ( F_89 ( V_32 ) ) {
if ( V_180 ( V_32 ) ) {
int V_271 = F_243 ( V_102 ) ;
if ( V_271 >= 0 )
V_173 -> V_179 = V_271 | 1 ;
}
if ( V_173 -> V_176 && F_186 ( V_32 -> V_82 ) &&
F_241 ( V_102 , V_272 ) )
V_173 -> V_181 = 1 ;
}
}
F_107 ( & V_174 , V_33 ) ;
if ( V_96 )
V_79 = F_236 ( V_96 ) ;
if ( ! V_79 ) {
struct V_172 * V_273 ;
V_273 = F_238 ( V_32 -> V_103 , V_88 , V_89 ) ;
if ( V_273 ) {
V_79 = V_273 -> V_42 ;
V_273 -> V_96 = V_96 ;
}
}
if ( V_79 ) {
F_108 ( & V_174 , V_33 ) ;
F_64 ( V_173 ) ;
return V_79 ;
}
F_213 ( & V_32 -> V_115 ) ;
V_84 = F_191 ( V_42 , V_32 ) ;
F_214 ( & V_32 -> V_115 ) ;
if ( V_84 ) {
F_108 ( & V_174 , V_33 ) ;
F_64 ( V_173 ) ;
return NULL ;
}
F_244 ( & V_173 -> V_268 , & V_42 -> V_107 ) ;
F_244 ( & V_173 -> V_269 , & V_274 ) ;
if ( V_96 )
V_96 -> V_97 . V_32 = V_173 ;
F_108 ( & V_174 , V_33 ) ;
if ( V_96 && F_217 ( V_42 , V_96 ) ) {
F_125 ( L_32 , F_245 ( V_96 ) ) ;
F_246 ( V_42 , V_96 ) ;
return NULL ;
}
return V_42 ;
}
static int F_247 ( struct V_100 * V_102 , T_4 V_240 , void * V_241 )
{
* ( T_4 * ) V_241 = V_240 ;
return 0 ;
}
static struct V_39 * F_248 ( struct V_95 * V_96 , int V_136 )
{
struct V_172 * V_173 = NULL ;
struct V_39 * V_42 = NULL ;
struct V_31 * V_32 ;
T_4 V_275 , V_276 ;
unsigned long V_33 ;
T_6 V_88 , V_89 ;
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return NULL ;
V_275 = ( ( T_4 ) V_88 << 8 ) | V_89 ;
if ( F_95 ( V_96 ) ) {
struct V_100 * V_102 = F_96 ( V_96 ) ;
F_218 ( V_102 , F_247 , & V_276 ) ;
F_107 ( & V_174 , V_33 ) ;
V_173 = F_238 ( F_100 ( V_102 -> V_88 ) ,
F_216 ( V_276 ) ,
V_276 & 0xff ) ;
if ( V_173 ) {
V_32 = V_173 -> V_32 ;
V_42 = V_173 -> V_42 ;
}
F_108 ( & V_174 , V_33 ) ;
if ( V_173 )
goto V_108;
}
V_42 = F_189 ( 0 ) ;
if ( ! V_42 )
return NULL ;
if ( F_204 ( V_42 , V_32 , V_136 ) ) {
F_184 ( V_42 ) ;
return NULL ;
}
V_108:
return V_42 ;
}
static struct V_39 * F_249 ( struct V_95 * V_96 ,
struct V_39 * V_42 )
{
struct V_31 * V_32 ;
struct V_39 * V_99 ;
T_4 V_275 , V_276 ;
T_6 V_88 , V_89 ;
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return NULL ;
V_275 = ( ( T_4 ) V_88 << 8 ) | V_89 ;
if ( F_95 ( V_96 ) ) {
struct V_100 * V_102 = F_96 ( V_96 ) ;
F_218 ( V_102 , F_247 , & V_276 ) ;
if ( V_275 != V_276 ) {
V_99 = F_239 ( V_32 , F_216 ( V_276 ) ,
V_276 & 0xff , NULL , V_42 ) ;
if ( ! V_99 || V_99 != V_42 )
return V_99 ;
}
}
V_99 = F_239 ( V_32 , V_88 , V_89 , V_96 , V_42 ) ;
if ( ! V_99 || V_99 != V_42 )
return V_99 ;
return V_42 ;
}
static struct V_39 * F_250 ( struct V_95 * V_96 , int V_136 )
{
struct V_39 * V_42 , * V_99 ;
V_42 = F_236 ( V_96 ) ;
if ( V_42 )
goto V_108;
V_42 = F_248 ( V_96 , V_136 ) ;
if ( ! V_42 )
goto V_108;
V_99 = F_249 ( V_96 , V_42 ) ;
if ( ! V_99 || V_42 != V_99 ) {
F_184 ( V_42 ) ;
V_42 = V_99 ;
}
V_108:
return V_42 ;
}
static int F_251 ( struct V_39 * V_42 ,
unsigned long long V_225 ,
unsigned long long V_112 )
{
unsigned long V_277 = V_225 >> V_12 ;
unsigned long V_278 = V_112 >> V_12 ;
if ( ! F_198 ( & V_42 -> V_194 , F_12 ( V_277 ) ,
F_12 ( V_278 ) ) ) {
F_125 ( L_33 ) ;
return - V_142 ;
}
F_145 ( L_34 , V_225 , V_112 ) ;
F_113 ( V_42 , V_277 , V_278 ) ;
return F_232 ( V_42 , V_277 , V_277 ,
V_278 - V_277 + 1 ,
V_125 | V_126 ) ;
}
static int F_252 ( struct V_95 * V_96 ,
struct V_39 * V_42 ,
unsigned long long V_225 ,
unsigned long long V_112 )
{
if ( V_42 == V_279 && V_232 ) {
F_253 ( L_35 ,
F_245 ( V_96 ) , V_225 , V_112 ) ;
return 0 ;
}
F_48 ( L_36 ,
F_245 ( V_96 ) , V_225 , V_112 ) ;
if ( V_112 < V_225 ) {
F_254 ( 1 , L_37
L_38 ,
F_255 ( V_280 ) ,
F_255 ( V_281 ) ,
F_255 ( V_282 ) ) ;
return - V_283 ;
}
if ( V_112 >> F_2 ( V_42 -> V_1 ) ) {
F_254 ( 1 , L_39
L_38 ,
F_2 ( V_42 -> V_1 ) ,
F_255 ( V_280 ) ,
F_255 ( V_281 ) ,
F_255 ( V_282 ) ) ;
return - V_283 ;
}
return F_251 ( V_42 , V_225 , V_112 ) ;
}
static int F_256 ( struct V_95 * V_96 ,
unsigned long long V_225 ,
unsigned long long V_112 )
{
struct V_39 * V_42 ;
int V_84 ;
V_42 = F_250 ( V_96 , V_73 ) ;
if ( ! V_42 )
return - V_142 ;
V_84 = F_252 ( V_96 , V_42 , V_225 , V_112 ) ;
if ( V_84 )
F_184 ( V_42 ) ;
return V_84 ;
}
static inline int F_257 ( struct V_284 * V_285 ,
struct V_95 * V_96 )
{
if ( V_96 -> V_97 . V_32 == V_98 )
return 0 ;
return F_256 ( V_96 , V_285 -> V_286 ,
V_285 -> V_287 ) ;
}
static inline void F_258 ( void )
{
struct V_100 * V_102 ;
int V_84 ;
V_102 = F_259 ( V_288 << 8 , NULL ) ;
if ( ! V_102 )
return;
F_48 ( L_40 ) ;
V_84 = F_256 ( & V_102 -> V_96 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_84 )
F_125 ( L_41 ) ;
F_260 ( V_102 ) ;
}
static inline void F_258 ( void )
{
return;
}
static int T_3 F_261 ( int V_289 )
{
int V_123 , V_84 = 0 ;
V_279 = F_189 ( V_67 ) ;
if ( ! V_279 )
return - V_290 ;
if ( F_262 ( V_279 , V_73 ) ) {
F_184 ( V_279 ) ;
return - V_290 ;
}
F_145 ( L_42 ) ;
if ( V_289 )
return 0 ;
F_263 (nid) {
unsigned long V_129 , V_266 ;
int V_80 ;
F_264 (i, nid, &start_pfn, &end_pfn, NULL) {
V_84 = F_251 ( V_279 ,
F_265 ( V_129 ) , F_265 ( V_266 ) ) ;
if ( V_84 )
return V_84 ;
}
}
return 0 ;
}
static int F_266 ( struct V_95 * V_96 )
{
struct V_172 * V_173 ;
if ( F_237 ( ! V_53 ) )
return 0 ;
V_173 = V_96 -> V_97 . V_32 ;
if ( V_173 && V_173 != V_98 )
return ( V_173 -> V_42 == V_279 ) ;
return 0 ;
}
static int F_267 ( struct V_39 * V_42 , struct V_95 * V_96 )
{
struct V_39 * V_291 ;
struct V_31 * V_32 ;
T_6 V_88 , V_89 ;
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return - V_220 ;
V_291 = F_239 ( V_32 , V_88 , V_89 , V_96 , V_42 ) ;
if ( V_291 != V_42 )
return - V_292 ;
return 0 ;
}
static bool F_268 ( struct V_95 * V_96 )
{
struct V_284 * V_285 ;
struct V_95 * V_99 ;
int V_80 ;
F_79 () ;
F_269 (rmrr) {
F_103 (rmrr->devices,
rmrr->devices_cnt, i, tmp)
if ( V_99 == V_96 ) {
F_81 () ;
return true ;
}
}
F_81 () ;
return false ;
}
static bool F_270 ( struct V_95 * V_96 )
{
if ( ! F_268 ( V_96 ) )
return false ;
if ( F_95 ( V_96 ) ) {
struct V_100 * V_102 = F_96 ( V_96 ) ;
if ( F_271 ( V_102 ) || F_272 ( V_102 ) )
return false ;
}
return true ;
}
static int F_273 ( struct V_95 * V_96 , int V_293 )
{
if ( F_95 ( V_96 ) ) {
struct V_100 * V_102 = F_96 ( V_96 ) ;
if ( F_270 ( V_96 ) )
return 0 ;
if ( ( V_53 & V_294 ) && F_274 ( V_102 ) )
return 1 ;
if ( ( V_53 & V_54 ) && F_272 ( V_102 ) )
return 1 ;
if ( ! ( V_53 & V_295 ) )
return 0 ;
if ( ! F_275 ( V_102 ) ) {
if ( ! F_276 ( V_102 -> V_88 ) )
return 0 ;
if ( V_102 -> V_296 >> 8 == V_297 )
return 0 ;
} else if ( F_277 ( V_102 ) == V_298 )
return 0 ;
} else {
if ( F_268 ( V_96 ) )
return 0 ;
}
if ( ! V_293 ) {
V_24 V_299 = * V_96 -> V_299 ;
if ( V_96 -> V_300 &&
V_96 -> V_300 < V_299 )
V_299 = V_96 -> V_300 ;
return V_299 >= F_278 ( V_96 ) ;
}
return 1 ;
}
static int T_3 F_279 ( struct V_95 * V_96 , int V_289 )
{
int V_84 ;
if ( ! F_273 ( V_96 , 1 ) )
return 0 ;
V_84 = F_267 ( V_279 , V_96 ) ;
if ( ! V_84 )
F_48 ( L_43 ,
V_289 ? L_44 : L_45 , F_245 ( V_96 ) ) ;
else if ( V_84 == - V_220 )
V_84 = 0 ;
return V_84 ;
}
static int T_3 F_280 ( int V_289 )
{
struct V_100 * V_102 = NULL ;
struct V_77 * V_78 ;
struct V_31 * V_32 ;
struct V_95 * V_96 ;
int V_80 ;
int V_84 = 0 ;
F_200 (pdev) {
V_84 = F_279 ( & V_102 -> V_96 , V_289 ) ;
if ( V_84 )
return V_84 ;
}
F_80 (iommu, drhd)
F_103 (drhd->devices, drhd->devices_cnt, i, dev) {
struct V_301 * V_302 ;
struct V_303 * V_304 ;
if ( V_96 -> V_88 != & V_305 )
continue;
V_304 = F_281 ( V_96 ) ;
F_282 ( & V_304 -> V_306 ) ;
F_148 (pn, &adev->physical_node_list, node) {
V_84 = F_279 ( V_302 -> V_96 , V_289 ) ;
if ( V_84 )
break;
}
F_283 ( & V_304 -> V_306 ) ;
if ( V_84 )
return V_84 ;
}
return 0 ;
}
static void F_284 ( struct V_31 * V_32 )
{
if ( ! V_32 -> V_175 ) {
F_285 ( - 1 , V_32 ) ;
F_286 ( V_32 ) ;
}
if ( F_287 ( V_32 ) ) {
V_32 -> V_191 . V_236 = F_134 ;
V_32 -> V_191 . V_192 = F_139 ;
F_48 ( L_46 ,
V_32 -> V_141 ) ;
} else {
V_32 -> V_191 . V_236 = V_307 ;
V_32 -> V_191 . V_192 = V_308 ;
F_48 ( L_47 , V_32 -> V_141 ) ;
}
}
static int F_288 ( struct V_31 * V_32 ,
struct V_17 * V_309 ,
struct V_22 * * V_310 ,
int V_88 , bool V_311 )
{
int V_312 , V_313 = 0 , V_58 , V_89 , V_84 = 0 , V_56 ;
struct V_22 * V_314 = NULL , V_315 ;
struct V_22 * V_316 = NULL ;
struct V_17 V_18 ;
T_1 V_317 ;
V_312 = V_311 ? V_88 * 2 : V_88 ;
memcpy ( & V_18 , V_309 , sizeof( V_18 ) ) ;
for ( V_89 = 0 ; V_89 < 256 ; V_89 ++ ) {
V_58 = ( V_311 ? V_89 * 2 : V_89 ) % 256 ;
if ( V_58 == 0 ) {
if ( V_314 ) {
V_310 [ V_312 ] = V_314 ;
F_91 ( V_32 , V_314 ,
V_124 ) ;
V_313 = 1 ;
}
if ( V_316 )
F_289 ( V_316 ) ;
V_84 = 0 ;
if ( V_89 < 0x80 )
V_317 = F_18 ( & V_18 ) ;
else
V_317 = F_19 ( & V_18 ) ;
if ( ! V_317 ) {
if ( V_311 && V_89 == 0 ) {
V_89 = 0x7f ;
continue;
} else {
goto V_108;
}
}
V_84 = - V_142 ;
V_316 = F_290 ( V_317 , V_229 ,
V_318 ) ;
if ( ! V_316 )
goto V_108;
V_314 = F_54 ( V_32 -> V_61 ) ;
if ( ! V_314 )
goto V_319;
V_84 = 0 ;
}
memcpy ( & V_315 , V_316 + V_58 , sizeof( V_315 ) ) ;
if ( ! F_24 ( & V_315 ) )
continue;
V_56 = F_32 ( & V_315 ) ;
if ( V_56 >= 0 && V_56 < F_174 ( V_32 -> V_72 ) )
F_180 ( V_56 , V_32 -> V_202 ) ;
F_20 ( & V_315 ) ;
F_22 ( & V_315 ) ;
V_314 [ V_58 ] = V_315 ;
}
V_310 [ V_312 + V_313 ] = V_314 ;
F_91 ( V_32 , V_314 , V_124 ) ;
V_319:
F_291 ( V_316 ) ;
V_108:
return V_84 ;
}
static int F_292 ( struct V_31 * V_32 )
{
struct V_22 * * V_320 ;
struct V_17 * V_321 ;
T_1 V_322 ;
int V_323 ;
unsigned long V_33 ;
V_24 V_324 ;
int V_88 , V_84 ;
bool V_325 , V_311 ;
V_324 = V_163 ( V_32 -> V_36 + V_148 ) ;
V_311 = ! ! ( V_324 & V_146 ) ;
V_325 = ! ! F_293 ( V_32 -> V_82 ) ;
if ( V_325 != V_311 )
return - V_44 ;
V_322 = V_324 & V_20 ;
if ( ! V_322 )
return - V_44 ;
V_321 = F_290 ( V_322 , V_229 , V_318 ) ;
if ( ! V_321 )
return - V_142 ;
V_323 = V_311 ? 512 : 256 ;
V_84 = - V_142 ;
V_320 = F_52 ( V_323 * sizeof( void * ) , V_203 ) ;
if ( ! V_320 )
goto V_319;
for ( V_88 = 0 ; V_88 < 256 ; V_88 ++ ) {
V_84 = F_288 ( V_32 , & V_321 [ V_88 ] ,
V_320 , V_88 , V_311 ) ;
if ( V_84 ) {
F_125 ( L_48 ,
V_32 -> V_141 , V_88 ) ;
continue;
}
}
F_107 ( & V_32 -> V_115 , V_33 ) ;
for ( V_88 = 0 ; V_88 < 256 ; V_88 ++ ) {
int V_58 = V_311 ? V_88 * 2 : V_88 ;
V_24 V_29 ;
if ( V_320 [ V_58 ] ) {
V_29 = F_92 ( V_320 [ V_58 ] ) | 1 ;
V_32 -> V_17 [ V_88 ] . V_19 = V_29 ;
}
if ( ! V_311 || ! V_320 [ V_58 + 1 ] )
continue;
V_29 = F_92 ( V_320 [ V_58 + 1 ] ) | 1 ;
V_32 -> V_17 [ V_88 ] . V_21 = V_29 ;
}
F_108 ( & V_32 -> V_115 , V_33 ) ;
F_179 ( V_320 ) ;
F_91 ( V_32 , V_32 -> V_17 , V_229 ) ;
V_84 = 0 ;
V_319:
F_291 ( V_321 ) ;
return V_84 ;
}
static int T_3 F_294 ( void )
{
struct V_77 * V_78 ;
struct V_284 * V_285 ;
bool V_326 = false ;
struct V_95 * V_96 ;
struct V_31 * V_32 ;
int V_80 , V_84 ;
F_295 (drhd) {
if ( V_75 < V_327 ) {
V_75 ++ ;
continue;
}
F_296 ( L_49 , V_327 ) ;
}
if ( V_75 < V_327 )
V_75 = V_327 ;
V_76 = F_177 ( V_75 , sizeof( struct V_31 * ) ,
V_203 ) ;
if ( ! V_76 ) {
F_125 ( L_50 ) ;
V_84 = - V_142 ;
goto error;
}
F_80 (iommu, drhd) {
V_76 [ V_32 -> V_190 ] = V_32 ;
F_284 ( V_32 ) ;
V_84 = F_173 ( V_32 ) ;
if ( V_84 )
goto V_328;
F_43 ( V_32 ) ;
if ( F_41 ( V_32 ) && ! F_297 () ) {
F_172 ( V_32 ) ;
F_42 ( V_32 ) ;
F_253 ( L_51 ,
V_32 -> V_141 ) ;
}
V_84 = F_124 ( V_32 ) ;
if ( V_84 )
goto V_328;
if ( F_41 ( V_32 ) ) {
F_48 ( L_52 ) ;
V_84 = F_292 ( V_32 ) ;
if ( V_84 ) {
F_125 ( L_53 ,
V_32 -> V_141 ) ;
F_172 ( V_32 ) ;
F_42 ( V_32 ) ;
} else {
F_48 ( L_54 ,
V_32 -> V_141 ) ;
V_326 = true ;
}
}
if ( ! F_298 ( V_32 -> V_82 ) )
V_232 = 0 ;
#ifdef F_151
if ( V_180 ( V_32 ) )
F_299 ( V_32 ) ;
#endif
}
F_80 (iommu, drhd) {
F_132 ( V_32 ) ;
F_126 ( V_32 ) ;
V_32 -> V_191 . V_236 ( V_32 , 0 , 0 , 0 , V_158 ) ;
V_32 -> V_191 . V_192 ( V_32 , 0 , 0 , 0 , V_167 ) ;
}
if ( V_329 )
V_53 |= V_295 ;
#ifdef F_300
V_53 |= V_54 ;
#endif
F_301 () ;
if ( V_53 ) {
V_84 = F_261 ( V_232 ) ;
if ( V_84 )
goto V_328;
}
if ( V_326 )
goto V_330;
if ( V_53 ) {
V_84 = F_280 ( V_232 ) ;
if ( V_84 ) {
F_228 ( L_55 ) ;
goto V_328;
}
}
F_48 ( L_56 ) ;
F_269 (rmrr) {
F_103 (rmrr->devices, rmrr->devices_cnt,
i, dev) {
V_84 = F_257 ( V_285 , V_96 ) ;
if ( V_84 )
F_125 ( L_57 ) ;
}
}
F_258 () ;
V_330:
F_302 (iommu, drhd) {
if ( V_78 -> V_331 ) {
if ( V_332 )
F_170 ( V_32 ) ;
continue;
}
F_132 ( V_32 ) ;
#ifdef F_151
if ( V_180 ( V_32 ) && F_186 ( V_32 -> V_82 ) ) {
V_84 = F_303 ( V_32 ) ;
if ( V_84 )
goto V_328;
}
#endif
V_84 = F_304 ( V_32 ) ;
if ( V_84 )
goto V_328;
if ( ! F_41 ( V_32 ) )
F_171 ( V_32 ) ;
F_170 ( V_32 ) ;
}
return 0 ;
V_328:
F_80 (iommu, drhd) {
F_181 ( V_32 ) ;
F_185 ( V_32 ) ;
}
F_179 ( V_76 ) ;
error:
return V_84 ;
}
static unsigned long F_305 ( struct V_95 * V_96 ,
struct V_39 * V_42 ,
unsigned long V_333 , T_7 V_299 )
{
unsigned long V_334 = 0 ;
V_299 = F_3 ( T_7 , F_306 ( V_42 -> V_136 ) , V_299 ) ;
V_333 = F_165 ( V_333 ) ;
if ( ! V_47 && V_299 > F_307 ( 32 ) ) {
V_334 = F_308 ( & V_42 -> V_194 , V_333 ,
F_199 ( F_307 ( 32 ) ) ) ;
if ( V_334 )
return V_334 ;
}
V_334 = F_308 ( & V_42 -> V_194 , V_333 , F_199 ( V_299 ) ) ;
if ( F_309 ( ! V_334 ) ) {
F_125 ( L_58 ,
V_333 , F_245 ( V_96 ) ) ;
return 0 ;
}
return V_334 ;
}
static struct V_39 * F_310 ( struct V_95 * V_96 )
{
struct V_39 * V_42 , * V_99 ;
struct V_284 * V_285 ;
struct V_95 * V_335 ;
int V_80 , V_84 ;
V_42 = F_236 ( V_96 ) ;
if ( V_42 )
goto V_108;
V_42 = F_248 ( V_96 , V_73 ) ;
if ( ! V_42 )
goto V_108;
F_79 () ;
F_269 (rmrr) {
F_103 (rmrr->devices, rmrr->devices_cnt,
i, i_dev) {
if ( V_335 != V_96 )
continue;
V_84 = F_252 ( V_96 , V_42 ,
V_285 -> V_286 ,
V_285 -> V_287 ) ;
if ( V_84 )
F_311 ( V_96 , L_57 ) ;
}
}
F_81 () ;
V_99 = F_249 ( V_96 , V_42 ) ;
if ( ! V_99 || V_42 != V_99 ) {
F_184 ( V_42 ) ;
V_42 = V_99 ;
}
V_108:
if ( ! V_42 )
F_125 ( L_59 , F_245 ( V_96 ) ) ;
return V_42 ;
}
static int F_312 ( struct V_95 * V_96 )
{
int V_79 ;
if ( F_93 ( V_96 ) )
return 1 ;
if ( ! V_53 )
return 0 ;
V_79 = F_266 ( V_96 ) ;
if ( V_79 ) {
if ( F_273 ( V_96 , 0 ) )
return 1 ;
else {
F_246 ( V_279 , V_96 ) ;
F_48 ( L_60 ,
F_245 ( V_96 ) ) ;
return 0 ;
}
} else {
if ( F_273 ( V_96 , 0 ) ) {
int V_84 ;
V_84 = F_267 ( V_279 , V_96 ) ;
if ( ! V_84 ) {
F_48 ( L_61 ,
F_245 ( V_96 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_263 F_313 ( struct V_95 * V_96 , T_1 V_336 ,
T_5 V_59 , int V_337 , V_24 V_299 )
{
struct V_39 * V_42 ;
T_1 V_338 ;
unsigned long V_334 ;
int V_255 = 0 ;
int V_84 ;
struct V_31 * V_32 ;
unsigned long V_339 = V_336 >> V_11 ;
F_75 ( V_337 == V_340 ) ;
if ( F_312 ( V_96 ) )
return V_336 ;
V_42 = F_310 ( V_96 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_74 ( V_42 ) ;
V_59 = F_221 ( V_336 , V_59 ) ;
V_334 = F_305 ( V_96 , V_42 , F_12 ( V_59 ) , V_299 ) ;
if ( ! V_334 )
goto error;
if ( V_337 == V_341 || V_337 == V_342 || \
! F_314 ( V_32 -> V_72 ) )
V_255 |= V_125 ;
if ( V_337 == V_343 || V_337 == V_342 )
V_255 |= V_126 ;
V_84 = F_232 ( V_42 , F_13 ( V_334 ) ,
F_13 ( V_339 ) , V_59 , V_255 ) ;
if ( V_84 )
goto error;
if ( F_168 ( V_32 -> V_72 ) )
F_163 ( V_32 , V_42 ,
F_13 ( V_334 ) ,
V_59 , 0 , 1 ) ;
else
F_132 ( V_32 ) ;
V_338 = ( T_1 ) V_334 << V_11 ;
V_338 += V_336 & ~ V_244 ;
return V_338 ;
error:
if ( V_334 )
F_315 ( & V_42 -> V_194 , V_334 , F_12 ( V_59 ) ) ;
F_125 ( L_62 ,
F_245 ( V_96 ) , V_59 , ( unsigned long long ) V_336 , V_337 ) ;
return 0 ;
}
static V_263 F_316 ( struct V_95 * V_96 , struct V_14 * V_14 ,
unsigned long V_119 , T_5 V_59 ,
enum V_344 V_337 ,
unsigned long V_345 )
{
return F_313 ( V_96 , F_225 ( V_14 ) + V_119 , V_59 ,
V_337 , * V_96 -> V_299 ) ;
}
static void F_317 ( struct V_95 * V_96 , V_263 V_346 , T_5 V_59 )
{
struct V_39 * V_42 ;
unsigned long V_129 , V_130 ;
unsigned long V_333 ;
unsigned long V_334 ;
struct V_31 * V_32 ;
struct V_14 * V_137 ;
if ( F_312 ( V_96 ) )
return;
V_42 = F_236 ( V_96 ) ;
F_75 ( ! V_42 ) ;
V_32 = F_74 ( V_42 ) ;
V_334 = F_199 ( V_346 ) ;
V_333 = F_221 ( V_346 , V_59 ) ;
V_129 = F_13 ( V_334 ) ;
V_130 = V_129 + V_333 - 1 ;
F_145 ( L_63 ,
F_245 ( V_96 ) , V_129 , V_130 ) ;
V_137 = F_121 ( V_42 , V_129 , V_130 ) ;
if ( V_48 ) {
F_163 ( V_32 , V_42 , V_129 ,
V_333 , ! V_137 , 0 ) ;
F_315 ( & V_42 -> V_194 , V_334 , F_12 ( V_333 ) ) ;
F_122 ( V_137 ) ;
} else {
F_318 ( & V_42 -> V_194 , V_334 , V_333 ,
( unsigned long ) V_137 ) ;
}
}
static void F_319 ( struct V_95 * V_96 , V_263 V_346 ,
T_5 V_59 , enum V_344 V_337 ,
unsigned long V_345 )
{
F_317 ( V_96 , V_346 , V_59 ) ;
}
static void * F_320 ( struct V_95 * V_96 , T_5 V_59 ,
V_263 * V_347 , T_8 V_33 ,
unsigned long V_345 )
{
struct V_14 * V_14 = NULL ;
int V_348 ;
V_59 = F_222 ( V_59 ) ;
V_348 = F_321 ( V_59 ) ;
if ( ! F_312 ( V_96 ) )
V_33 &= ~ ( V_349 | V_350 ) ;
else if ( V_96 -> V_300 < F_278 ( V_96 ) ) {
if ( V_96 -> V_300 < F_307 ( 32 ) )
V_33 |= V_349 ;
else
V_33 |= V_350 ;
}
if ( F_322 ( V_33 ) ) {
unsigned int V_210 = V_59 >> V_11 ;
V_14 = F_323 ( V_96 , V_210 , V_348 , V_33 ) ;
if ( V_14 && F_312 ( V_96 ) &&
F_225 ( V_14 ) + V_59 > V_96 -> V_300 ) {
F_324 ( V_96 , V_14 , V_210 ) ;
V_14 = NULL ;
}
}
if ( ! V_14 )
V_14 = F_325 ( V_33 , V_348 ) ;
if ( ! V_14 )
return NULL ;
memset ( F_56 ( V_14 ) , 0 , V_59 ) ;
* V_347 = F_313 ( V_96 , F_225 ( V_14 ) , V_59 ,
V_342 ,
V_96 -> V_300 ) ;
if ( * V_347 )
return F_56 ( V_14 ) ;
if ( ! F_324 ( V_96 , V_14 , V_59 >> V_11 ) )
F_326 ( V_14 , V_348 ) ;
return NULL ;
}
static void F_327 ( struct V_95 * V_96 , T_5 V_59 , void * V_62 ,
V_263 V_347 , unsigned long V_345 )
{
int V_348 ;
struct V_14 * V_14 = F_17 ( V_62 ) ;
V_59 = F_222 ( V_59 ) ;
V_348 = F_321 ( V_59 ) ;
F_317 ( V_96 , V_347 , V_59 ) ;
if ( ! F_324 ( V_96 , V_14 , V_59 >> V_11 ) )
F_326 ( V_14 , V_348 ) ;
}
static void F_328 ( struct V_95 * V_96 , struct V_251 * V_351 ,
int V_352 , enum V_344 V_337 ,
unsigned long V_345 )
{
V_263 V_353 = F_329 ( V_351 ) & V_244 ;
unsigned long V_333 = 0 ;
struct V_251 * V_252 ;
int V_80 ;
F_330 (sglist, sg, nelems, i) {
V_333 += F_221 ( F_329 ( V_252 ) , F_331 ( V_252 ) ) ;
}
F_317 ( V_96 , V_353 , V_333 << V_12 ) ;
}
static int F_332 ( struct V_95 * V_354 ,
struct V_251 * V_351 , int V_352 , int V_337 )
{
int V_80 ;
struct V_251 * V_252 ;
F_330 (sglist, sg, nelems, i) {
F_75 ( ! F_226 ( V_252 ) ) ;
V_252 -> V_262 = F_225 ( F_226 ( V_252 ) ) + V_252 -> V_119 ;
V_252 -> V_264 = V_252 -> V_261 ;
}
return V_352 ;
}
static int F_333 ( struct V_95 * V_96 , struct V_251 * V_351 , int V_352 ,
enum V_344 V_337 , unsigned long V_345 )
{
int V_80 ;
struct V_39 * V_42 ;
T_5 V_59 = 0 ;
int V_255 = 0 ;
unsigned long V_334 ;
int V_84 ;
struct V_251 * V_252 ;
unsigned long V_355 ;
struct V_31 * V_32 ;
F_75 ( V_337 == V_340 ) ;
if ( F_312 ( V_96 ) )
return F_332 ( V_96 , V_351 , V_352 , V_337 ) ;
V_42 = F_310 ( V_96 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_74 ( V_42 ) ;
F_330 (sglist, sg, nelems, i)
V_59 += F_221 ( V_252 -> V_119 , V_252 -> V_261 ) ;
V_334 = F_305 ( V_96 , V_42 , F_12 ( V_59 ) ,
* V_96 -> V_299 ) ;
if ( ! V_334 ) {
V_351 -> V_264 = 0 ;
return 0 ;
}
if ( V_337 == V_341 || V_337 == V_342 || \
! F_314 ( V_32 -> V_72 ) )
V_255 |= V_125 ;
if ( V_337 == V_343 || V_337 == V_342 )
V_255 |= V_126 ;
V_355 = F_13 ( V_334 ) ;
V_84 = F_231 ( V_42 , V_355 , V_351 , V_59 , V_255 ) ;
if ( F_309 ( V_84 ) ) {
F_116 ( V_42 , V_355 ,
V_355 + V_59 - 1 ,
F_1 ( V_42 -> V_1 ) + 1 ) ;
F_315 ( & V_42 -> V_194 , V_334 , F_12 ( V_59 ) ) ;
return 0 ;
}
if ( F_168 ( V_32 -> V_72 ) )
F_163 ( V_32 , V_42 , V_355 , V_59 , 0 , 1 ) ;
else
F_132 ( V_32 ) ;
return V_352 ;
}
static int F_334 ( struct V_95 * V_96 , V_263 V_356 )
{
return ! V_356 ;
}
static inline int F_335 ( void )
{
int V_84 = 0 ;
V_64 = F_336 ( L_64 ,
sizeof( struct V_39 ) ,
0 ,
V_357 ,
NULL ) ;
if ( ! V_64 ) {
F_125 ( L_65 ) ;
V_84 = - V_142 ;
}
return V_84 ;
}
static inline int F_337 ( void )
{
int V_84 = 0 ;
V_65 = F_336 ( L_66 ,
sizeof( struct V_172 ) ,
0 ,
V_357 ,
NULL ) ;
if ( ! V_65 ) {
F_125 ( L_67 ) ;
V_84 = - V_142 ;
}
return V_84 ;
}
static int T_3 F_338 ( void )
{
int V_84 ;
V_84 = F_339 () ;
if ( V_84 )
return V_84 ;
V_84 = F_335 () ;
if ( V_84 )
goto V_358;
V_84 = F_337 () ;
if ( ! V_84 )
return V_84 ;
F_340 ( V_64 ) ;
V_358:
F_341 () ;
return - V_142 ;
}
static void T_3 F_342 ( void )
{
F_340 ( V_65 ) ;
F_340 ( V_64 ) ;
F_341 () ;
}
static void F_343 ( struct V_100 * V_102 )
{
struct V_77 * V_78 ;
T_2 V_359 ;
int V_360 ;
V_360 = F_344 ( V_102 -> V_88 , F_345 ( 0 , 0 ) , 0xb0 , & V_359 ) ;
if ( V_360 ) {
F_346 ( & V_102 -> V_96 , L_68 ) ;
return;
}
V_359 &= 0xffff0000 ;
V_78 = F_347 ( V_102 ) ;
if ( F_348 ( ! V_78 || V_78 -> V_361 - V_359 != 0xa000 ,
V_362 ,
L_69 ) )
V_102 -> V_96 . V_97 . V_32 = V_98 ;
}
static void T_3 F_349 ( void )
{
struct V_77 * V_78 ;
struct V_95 * V_96 ;
int V_80 ;
F_295 (drhd) {
if ( ! V_78 -> V_113 ) {
F_103 (drhd->devices,
drhd->devices_cnt, i, dev)
break;
if ( V_80 == V_78 -> V_363 )
V_78 -> V_331 = 1 ;
}
}
F_350 (drhd) {
if ( V_78 -> V_113 )
continue;
F_103 (drhd->devices,
drhd->devices_cnt, i, dev)
if ( ! F_95 ( V_96 ) || ! F_272 ( F_96 ( V_96 ) ) )
break;
if ( V_80 < V_78 -> V_363 )
continue;
if ( V_46 ) {
V_364 = 1 ;
} else {
V_78 -> V_331 = 1 ;
F_103 (drhd->devices,
drhd->devices_cnt, i, dev)
V_96 -> V_97 . V_32 = V_98 ;
}
}
}
static int F_351 ( void )
{
struct V_77 * V_78 ;
struct V_31 * V_32 = NULL ;
F_80 (iommu, drhd)
if ( V_32 -> V_175 )
F_352 ( V_32 ) ;
F_302 (iommu, drhd) {
if ( V_78 -> V_331 ) {
if ( V_332 )
F_170 ( V_32 ) ;
continue;
}
F_132 ( V_32 ) ;
F_126 ( V_32 ) ;
V_32 -> V_191 . V_236 ( V_32 , 0 , 0 , 0 ,
V_158 ) ;
V_32 -> V_191 . V_192 ( V_32 , 0 , 0 , 0 , V_167 ) ;
F_171 ( V_32 ) ;
F_170 ( V_32 ) ;
}
return 0 ;
}
static void F_353 ( void )
{
struct V_77 * V_78 ;
struct V_31 * V_32 ;
F_80 (iommu, drhd) {
V_32 -> V_191 . V_236 ( V_32 , 0 , 0 , 0 ,
V_158 ) ;
V_32 -> V_191 . V_192 ( V_32 , 0 , 0 , 0 ,
V_167 ) ;
}
}
static int F_354 ( void )
{
struct V_77 * V_78 ;
struct V_31 * V_32 = NULL ;
unsigned long V_145 ;
F_80 (iommu, drhd) {
V_32 -> V_365 = F_52 ( sizeof( T_2 ) * V_366 ,
V_60 ) ;
if ( ! V_32 -> V_365 )
goto V_367;
}
F_353 () ;
F_80 (iommu, drhd) {
F_172 ( V_32 ) ;
F_127 ( & V_32 -> V_147 , V_145 ) ;
V_32 -> V_365 [ V_368 ] =
F_44 ( V_32 -> V_36 + V_369 ) ;
V_32 -> V_365 [ V_370 ] =
F_44 ( V_32 -> V_36 + V_371 ) ;
V_32 -> V_365 [ V_372 ] =
F_44 ( V_32 -> V_36 + V_373 ) ;
V_32 -> V_365 [ V_374 ] =
F_44 ( V_32 -> V_36 + V_375 ) ;
F_131 ( & V_32 -> V_147 , V_145 ) ;
}
return 0 ;
V_367:
F_80 (iommu, drhd)
F_179 ( V_32 -> V_365 ) ;
return - V_142 ;
}
static void F_355 ( void )
{
struct V_77 * V_78 ;
struct V_31 * V_32 = NULL ;
unsigned long V_145 ;
if ( F_351 () ) {
if ( V_332 )
F_356 ( L_70 ) ;
else
F_254 ( 1 , L_71 ) ;
return;
}
F_80 (iommu, drhd) {
F_127 ( & V_32 -> V_147 , V_145 ) ;
F_129 ( V_32 -> V_365 [ V_368 ] ,
V_32 -> V_36 + V_369 ) ;
F_129 ( V_32 -> V_365 [ V_370 ] ,
V_32 -> V_36 + V_371 ) ;
F_129 ( V_32 -> V_365 [ V_372 ] ,
V_32 -> V_36 + V_373 ) ;
F_129 ( V_32 -> V_365 [ V_374 ] ,
V_32 -> V_36 + V_375 ) ;
F_131 ( & V_32 -> V_147 , V_145 ) ;
}
F_80 (iommu, drhd)
F_179 ( V_32 -> V_365 ) ;
}
static void T_3 F_357 ( void )
{
F_358 ( & V_376 ) ;
}
static inline void F_357 ( void ) {}
int T_3 F_359 ( struct V_377 * V_378 , void * V_379 )
{
struct V_380 * V_285 ;
int V_255 = V_125 | V_126 ;
struct V_284 * V_381 ;
T_5 V_261 ;
V_381 = F_52 ( sizeof( * V_381 ) , V_203 ) ;
if ( ! V_381 )
goto V_108;
V_381 -> V_382 = V_378 ;
V_285 = (struct V_380 * ) V_378 ;
V_381 -> V_286 = V_285 -> V_286 ;
V_381 -> V_287 = V_285 -> V_287 ;
V_261 = V_285 -> V_287 - V_285 -> V_286 + 1 ;
V_381 -> V_383 = F_360 ( V_285 -> V_286 , V_261 , V_255 ,
V_384 ) ;
if ( ! V_381 -> V_383 )
goto V_385;
V_381 -> V_107 = F_361 ( ( void * ) ( V_285 + 1 ) ,
( ( void * ) V_285 ) + V_285 -> V_378 . V_261 ,
& V_381 -> V_363 ) ;
if ( V_381 -> V_363 && V_381 -> V_107 == NULL )
goto V_386;
F_244 ( & V_381 -> V_387 , & V_388 ) ;
return 0 ;
V_386:
F_179 ( V_381 -> V_383 ) ;
V_385:
F_179 ( V_381 ) ;
V_108:
return - V_142 ;
}
static struct V_389 * F_362 ( struct V_390 * V_391 )
{
struct V_389 * V_392 ;
struct V_390 * V_99 ;
F_363 (atsru, &dmar_atsr_units, list) {
V_99 = (struct V_390 * ) V_392 -> V_382 ;
if ( V_391 -> V_103 != V_99 -> V_103 )
continue;
if ( V_391 -> V_378 . V_261 != V_99 -> V_378 . V_261 )
continue;
if ( memcmp ( V_391 , V_99 , V_391 -> V_378 . V_261 ) == 0 )
return V_392 ;
}
return NULL ;
}
int F_364 ( struct V_377 * V_382 , void * V_379 )
{
struct V_390 * V_391 ;
struct V_389 * V_392 ;
if ( V_393 >= V_394 && ! V_395 )
return 0 ;
V_391 = F_46 ( V_382 , struct V_390 , V_378 ) ;
V_392 = F_362 ( V_391 ) ;
if ( V_392 )
return 0 ;
V_392 = F_52 ( sizeof( * V_392 ) + V_382 -> V_261 , V_203 ) ;
if ( ! V_392 )
return - V_142 ;
V_392 -> V_382 = ( void * ) ( V_392 + 1 ) ;
memcpy ( V_392 -> V_382 , V_382 , V_382 -> V_261 ) ;
V_392 -> V_113 = V_391 -> V_33 & 0x1 ;
if ( ! V_392 -> V_113 ) {
V_392 -> V_107 = F_361 ( ( void * ) ( V_391 + 1 ) ,
( void * ) V_391 + V_391 -> V_378 . V_261 ,
& V_392 -> V_363 ) ;
if ( V_392 -> V_363 && V_392 -> V_107 == NULL ) {
F_179 ( V_392 ) ;
return - V_142 ;
}
}
F_365 ( & V_392 -> V_387 , & V_396 ) ;
return 0 ;
}
static void F_366 ( struct V_389 * V_392 )
{
F_367 ( & V_392 -> V_107 , & V_392 -> V_363 ) ;
F_179 ( V_392 ) ;
}
int F_368 ( struct V_377 * V_382 , void * V_379 )
{
struct V_390 * V_391 ;
struct V_389 * V_392 ;
V_391 = F_46 ( V_382 , struct V_390 , V_378 ) ;
V_392 = F_362 ( V_391 ) ;
if ( V_392 ) {
F_369 ( & V_392 -> V_387 ) ;
F_370 () ;
F_366 ( V_392 ) ;
}
return 0 ;
}
int F_371 ( struct V_377 * V_382 , void * V_379 )
{
int V_80 ;
struct V_95 * V_96 ;
struct V_390 * V_391 ;
struct V_389 * V_392 ;
V_391 = F_46 ( V_382 , struct V_390 , V_378 ) ;
V_392 = F_362 ( V_391 ) ;
if ( ! V_392 )
return 0 ;
if ( ! V_392 -> V_113 && V_392 -> V_107 && V_392 -> V_363 ) {
F_103 (atsru->devices, atsru->devices_cnt,
i, dev)
return - V_292 ;
}
return 0 ;
}
static int F_372 ( struct V_77 * V_397 )
{
int V_398 , V_84 = 0 ;
struct V_31 * V_32 = V_397 -> V_32 ;
if ( V_76 [ V_32 -> V_190 ] )
return 0 ;
if ( V_232 && ! F_298 ( V_32 -> V_82 ) ) {
F_253 ( L_72 ,
V_32 -> V_141 ) ;
return - V_399 ;
}
if ( ! F_83 ( V_32 -> V_82 ) &&
F_82 ( V_32 ) ) {
F_253 ( L_73 ,
V_32 -> V_141 ) ;
return - V_399 ;
}
V_398 = F_84 ( V_32 ) - 1 ;
if ( V_398 >= 0 && ! ( F_85 ( V_32 -> V_72 ) & ( 1 << V_398 ) ) ) {
F_253 ( L_74 ,
V_32 -> V_141 ) ;
return - V_399 ;
}
if ( V_32 -> V_149 & V_199 )
F_172 ( V_32 ) ;
V_76 [ V_32 -> V_190 ] = V_32 ;
V_84 = F_173 ( V_32 ) ;
if ( V_84 == 0 )
V_84 = F_124 ( V_32 ) ;
if ( V_84 )
goto V_108;
#ifdef F_151
if ( V_180 ( V_32 ) )
F_299 ( V_32 ) ;
#endif
if ( V_397 -> V_331 ) {
if ( V_332 )
F_170 ( V_32 ) ;
return 0 ;
}
F_284 ( V_32 ) ;
F_132 ( V_32 ) ;
#ifdef F_151
if ( V_180 ( V_32 ) && F_186 ( V_32 -> V_82 ) ) {
V_84 = F_303 ( V_32 ) ;
if ( V_84 )
goto V_400;
}
#endif
V_84 = F_304 ( V_32 ) ;
if ( V_84 )
goto V_400;
F_126 ( V_32 ) ;
V_32 -> V_191 . V_236 ( V_32 , 0 , 0 , 0 , V_158 ) ;
V_32 -> V_191 . V_192 ( V_32 , 0 , 0 , 0 , V_167 ) ;
F_171 ( V_32 ) ;
F_170 ( V_32 ) ;
return 0 ;
V_400:
F_181 ( V_32 ) ;
V_108:
F_185 ( V_32 ) ;
return V_84 ;
}
int F_373 ( struct V_77 * V_397 , bool V_401 )
{
int V_84 = 0 ;
struct V_31 * V_32 = V_397 -> V_32 ;
if ( ! V_395 )
return 0 ;
if ( V_32 == NULL )
return - V_44 ;
if ( V_401 ) {
V_84 = F_372 ( V_397 ) ;
} else {
F_181 ( V_32 ) ;
F_185 ( V_32 ) ;
}
return V_84 ;
}
static void F_374 ( void )
{
struct V_284 * V_381 , * V_402 ;
struct V_389 * V_392 , * V_403 ;
F_182 (rmrru, rmrr_n, &dmar_rmrr_units, list) {
F_235 ( & V_381 -> V_387 ) ;
F_367 ( & V_381 -> V_107 , & V_381 -> V_363 ) ;
F_179 ( V_381 -> V_383 ) ;
F_179 ( V_381 ) ;
}
F_182 (atsru, atsr_n, &dmar_atsr_units, list) {
F_235 ( & V_392 -> V_387 ) ;
F_366 ( V_392 ) ;
}
}
int F_242 ( struct V_100 * V_96 )
{
int V_80 , V_84 = 1 ;
struct V_404 * V_88 ;
struct V_100 * V_405 = NULL ;
struct V_95 * V_99 ;
struct V_390 * V_391 ;
struct V_389 * V_392 ;
V_96 = F_99 ( V_96 ) ;
for ( V_88 = V_96 -> V_88 ; V_88 ; V_88 = V_88 -> V_118 ) {
V_405 = V_88 -> V_406 ;
if ( ! V_405 )
return 1 ;
if ( ! F_275 ( V_405 ) ||
F_277 ( V_405 ) == V_298 )
return 0 ;
if ( F_277 ( V_405 ) == V_407 )
break;
}
F_79 () ;
F_363 (atsru, &dmar_atsr_units, list) {
V_391 = F_46 ( V_392 -> V_382 , struct V_390 , V_378 ) ;
if ( V_391 -> V_103 != F_100 ( V_96 -> V_88 ) )
continue;
F_375 (atsru->devices, atsru->devices_cnt, i, tmp)
if ( V_99 == & V_405 -> V_96 )
goto V_108;
if ( V_392 -> V_113 )
goto V_108;
}
V_84 = 0 ;
V_108:
F_81 () ;
return V_84 ;
}
int F_376 ( struct V_408 * V_173 )
{
int V_84 = 0 ;
struct V_284 * V_381 ;
struct V_389 * V_392 ;
struct V_390 * V_391 ;
struct V_380 * V_285 ;
if ( ! V_395 && V_393 >= V_394 )
return 0 ;
F_148 (rmrru, &dmar_rmrr_units, list) {
V_285 = F_46 ( V_381 -> V_382 ,
struct V_380 , V_378 ) ;
if ( V_173 -> V_409 == V_410 ) {
V_84 = F_377 ( V_173 , ( void * ) ( V_285 + 1 ) ,
( ( void * ) V_285 ) + V_285 -> V_378 . V_261 ,
V_285 -> V_103 , V_381 -> V_107 ,
V_381 -> V_363 ) ;
if( V_84 < 0 )
return V_84 ;
} else if ( V_173 -> V_409 == V_411 ) {
F_378 ( V_173 , V_285 -> V_103 ,
V_381 -> V_107 , V_381 -> V_363 ) ;
}
}
F_148 (atsru, &dmar_atsr_units, list) {
if ( V_392 -> V_113 )
continue;
V_391 = F_46 ( V_392 -> V_382 , struct V_390 , V_378 ) ;
if ( V_173 -> V_409 == V_410 ) {
V_84 = F_377 ( V_173 , ( void * ) ( V_391 + 1 ) ,
( void * ) V_391 + V_391 -> V_378 . V_261 ,
V_391 -> V_103 , V_392 -> V_107 ,
V_392 -> V_363 ) ;
if ( V_84 > 0 )
break;
else if( V_84 < 0 )
return V_84 ;
} else if ( V_173 -> V_409 == V_411 ) {
if ( F_378 ( V_173 , V_391 -> V_103 ,
V_392 -> V_107 , V_392 -> V_363 ) )
break;
}
}
return 0 ;
}
static int F_379 ( struct V_412 * V_413 ,
unsigned long V_414 , void * V_140 )
{
struct V_95 * V_96 = V_140 ;
struct V_39 * V_42 ;
if ( F_93 ( V_96 ) )
return 0 ;
if ( V_414 != V_411 )
return 0 ;
V_42 = F_236 ( V_96 ) ;
if ( ! V_42 )
return 0 ;
F_246 ( V_42 , V_96 ) ;
if ( ! F_67 ( V_42 ) && F_380 ( & V_42 -> V_107 ) )
F_184 ( V_42 ) ;
return 0 ;
}
static int F_381 ( struct V_412 * V_413 ,
unsigned long V_29 , void * V_415 )
{
struct V_416 * V_417 = V_415 ;
unsigned long long V_225 , V_112 ;
unsigned long V_355 , V_278 ;
switch ( V_29 ) {
case V_418 :
V_225 = V_417 -> V_129 << V_11 ;
V_112 = ( ( V_417 -> V_129 + V_417 -> V_254 ) << V_11 ) - 1 ;
if ( F_251 ( V_279 , V_225 , V_112 ) ) {
F_253 ( L_75 ,
V_225 , V_112 ) ;
return V_419 ;
}
break;
case V_420 :
case V_421 :
V_355 = F_13 ( V_417 -> V_129 ) ;
V_278 = F_13 ( V_417 -> V_129 + V_417 -> V_254 - 1 ) ;
while ( V_355 <= V_278 ) {
struct V_212 * V_212 ;
struct V_77 * V_78 ;
struct V_31 * V_32 ;
struct V_14 * V_137 ;
V_212 = F_382 ( & V_279 -> V_194 , V_355 ) ;
if ( V_212 == NULL ) {
F_145 ( L_76 ,
V_355 ) ;
break;
}
V_212 = F_383 ( & V_279 -> V_194 , V_212 ,
V_355 , V_278 ) ;
if ( V_212 == NULL ) {
F_253 ( L_77 ,
V_355 , V_278 ) ;
return V_419 ;
}
V_137 = F_121 ( V_279 , V_212 -> V_422 ,
V_212 -> V_423 ) ;
F_79 () ;
F_80 (iommu, drhd)
F_163 ( V_32 , V_279 ,
V_212 -> V_422 , F_384 ( V_212 ) ,
! V_137 , 0 ) ;
F_81 () ;
F_122 ( V_137 ) ;
V_355 = V_212 -> V_423 + 1 ;
F_385 ( V_212 ) ;
}
break;
}
return V_424 ;
}
static void F_386 ( unsigned int V_425 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_75 ; V_80 ++ ) {
struct V_31 * V_32 = V_76 [ V_80 ] ;
struct V_39 * V_42 ;
int V_56 ;
if ( ! V_32 )
continue;
for ( V_56 = 0 ; V_56 < F_174 ( V_32 -> V_72 ) ; V_56 ++ ) {
V_42 = F_50 ( V_32 , ( T_4 ) V_56 ) ;
if ( ! V_42 )
continue;
F_387 ( V_425 , & V_42 -> V_194 ) ;
}
}
}
static int F_388 ( unsigned int V_425 )
{
F_386 ( V_425 ) ;
return 0 ;
}
static void F_389 ( void )
{
struct V_31 * V_32 = NULL ;
struct V_77 * V_78 ;
F_302 (iommu, drhd)
F_172 ( V_32 ) ;
}
static inline struct V_31 * F_390 ( struct V_95 * V_96 )
{
struct V_426 * V_427 = F_391 ( V_96 ) ;
return F_46 ( V_427 , struct V_31 , V_32 ) ;
}
static T_9 F_392 ( struct V_95 * V_96 ,
struct V_428 * V_429 ,
char * V_430 )
{
struct V_31 * V_32 = F_390 ( V_96 ) ;
T_2 V_431 = F_44 ( V_32 -> V_36 + V_432 ) ;
return sprintf ( V_430 , L_78 ,
F_393 ( V_431 ) , F_394 ( V_431 ) ) ;
}
static T_9 F_395 ( struct V_95 * V_96 ,
struct V_428 * V_429 ,
char * V_430 )
{
struct V_31 * V_32 = F_390 ( V_96 ) ;
return sprintf ( V_430 , L_79 , V_32 -> V_433 ) ;
}
static T_9 F_396 ( struct V_95 * V_96 ,
struct V_428 * V_429 ,
char * V_430 )
{
struct V_31 * V_32 = F_390 ( V_96 ) ;
return sprintf ( V_430 , L_79 , V_32 -> V_72 ) ;
}
static T_9 F_397 ( struct V_95 * V_96 ,
struct V_428 * V_429 ,
char * V_430 )
{
struct V_31 * V_32 = F_390 ( V_96 ) ;
return sprintf ( V_430 , L_79 , V_32 -> V_82 ) ;
}
static T_9 F_398 ( struct V_95 * V_96 ,
struct V_428 * V_429 ,
char * V_430 )
{
struct V_31 * V_32 = F_390 ( V_96 ) ;
return sprintf ( V_430 , L_80 , F_174 ( V_32 -> V_72 ) ) ;
}
static T_9 F_399 ( struct V_95 * V_96 ,
struct V_428 * V_429 ,
char * V_430 )
{
struct V_31 * V_32 = F_390 ( V_96 ) ;
return sprintf ( V_430 , L_81 , F_400 ( V_32 -> V_202 ,
F_174 ( V_32 -> V_72 ) ) ) ;
}
int T_3 F_401 ( void )
{
int V_84 = - V_220 ;
struct V_77 * V_78 ;
struct V_31 * V_32 ;
V_332 = F_402 () ;
if ( F_338 () ) {
if ( V_332 )
F_356 ( L_82 ) ;
return - V_142 ;
}
F_403 ( & V_434 ) ;
if ( F_404 () ) {
if ( V_332 )
F_356 ( L_83 ) ;
goto V_435;
}
if ( F_405 () < 0 ) {
if ( V_332 )
F_356 ( L_84 ) ;
goto V_435;
}
if ( V_436 || V_45 ) {
if ( V_55 ) {
F_302 (iommu, drhd)
F_170 ( V_32 ) ;
}
F_389 () ;
goto V_435;
}
if ( F_380 ( & V_388 ) )
F_48 ( L_85 ) ;
if ( F_380 ( & V_396 ) )
F_48 ( L_86 ) ;
if ( F_195 () ) {
if ( V_332 )
F_356 ( L_87 ) ;
goto V_437;
}
F_349 () ;
V_84 = F_294 () ;
if ( V_84 ) {
if ( V_332 )
F_356 ( L_88 ) ;
F_125 ( L_89 ) ;
goto V_437;
}
F_406 ( & V_434 ) ;
F_48 ( L_90 ) ;
#ifdef F_407
V_438 = 0 ;
#endif
V_439 = & V_440 ;
F_357 () ;
F_80 (iommu, drhd) {
F_408 ( & V_32 -> V_32 , NULL ,
V_441 ,
L_91 , V_32 -> V_141 ) ;
F_409 ( & V_32 -> V_32 , & V_442 ) ;
F_410 ( & V_32 -> V_32 ) ;
}
F_411 ( & V_443 , & V_442 ) ;
F_412 ( & V_443 , & V_444 ) ;
if ( V_279 && ! V_232 )
F_413 ( & V_445 ) ;
F_414 ( V_446 , L_92 , NULL ,
F_388 ) ;
V_395 = 1 ;
return 0 ;
V_437:
F_209 ( & V_213 ) ;
V_435:
F_374 () ;
F_406 ( & V_434 ) ;
F_342 () ;
return V_84 ;
}
static int F_415 ( struct V_100 * V_102 , T_4 V_240 , void * V_241 )
{
struct V_31 * V_32 = V_241 ;
F_233 ( V_32 , F_216 ( V_240 ) , V_240 & 0xff ) ;
return 0 ;
}
static void F_416 ( struct V_31 * V_32 , struct V_95 * V_96 )
{
if ( ! V_32 || ! V_96 || ! F_95 ( V_96 ) )
return;
F_218 ( F_96 ( V_96 ) , & F_415 , V_32 ) ;
}
static void F_183 ( struct V_172 * V_173 )
{
struct V_31 * V_32 ;
unsigned long V_33 ;
F_147 ( & V_174 ) ;
if ( F_53 ( ! V_173 ) )
return;
V_32 = V_173 -> V_32 ;
if ( V_173 -> V_96 ) {
F_157 ( V_173 ) ;
F_416 ( V_32 , V_173 -> V_96 ) ;
}
F_234 ( V_173 ) ;
F_107 ( & V_32 -> V_115 , V_33 ) ;
F_193 ( V_173 -> V_42 , V_32 ) ;
F_108 ( & V_32 -> V_115 , V_33 ) ;
F_64 ( V_173 ) ;
}
static void F_246 ( struct V_39 * V_42 ,
struct V_95 * V_96 )
{
struct V_172 * V_173 ;
unsigned long V_33 ;
F_107 ( & V_174 , V_33 ) ;
V_173 = V_96 -> V_97 . V_32 ;
F_183 ( V_173 ) ;
F_108 ( & V_174 , V_33 ) ;
}
static int F_262 ( struct V_39 * V_42 , int V_226 )
{
int V_227 ;
F_196 ( & V_42 -> V_194 , V_124 , V_214 ,
V_215 ) ;
F_201 ( V_42 ) ;
V_42 -> V_136 = V_226 ;
V_227 = F_203 ( V_226 ) ;
V_42 -> V_1 = F_4 ( V_227 ) ;
V_42 -> V_81 = 0 ;
V_42 -> V_86 = 0 ;
V_42 -> V_87 = 0 ;
V_42 -> V_447 = 0 ;
V_42 -> V_120 = (struct V_27 * ) F_54 ( V_42 -> V_123 ) ;
if ( ! V_42 -> V_120 )
return - V_142 ;
F_104 ( V_42 , V_42 -> V_120 , V_229 ) ;
return 0 ;
}
static struct V_40 * F_417 ( unsigned type )
{
struct V_39 * V_39 ;
struct V_40 * V_42 ;
if ( type != V_448 )
return NULL ;
V_39 = F_189 ( V_66 ) ;
if ( ! V_39 ) {
F_125 ( L_93 ) ;
return NULL ;
}
if ( F_262 ( V_39 , V_73 ) ) {
F_125 ( L_94 ) ;
F_184 ( V_39 ) ;
return NULL ;
}
F_87 ( V_39 ) ;
V_42 = & V_39 -> V_42 ;
V_42 -> V_449 . V_450 = 0 ;
V_42 -> V_449 . V_451 = F_418 ( V_39 -> V_136 ) ;
V_42 -> V_449 . V_452 = true ;
return V_42 ;
}
static void F_419 ( struct V_40 * V_42 )
{
F_184 ( F_45 ( V_42 ) ) ;
}
static int F_420 ( struct V_40 * V_42 ,
struct V_95 * V_96 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_31 * V_32 ;
int V_68 ;
T_6 V_88 , V_89 ;
if ( F_270 ( V_96 ) ) {
F_421 ( V_96 , L_95 ) ;
return - V_453 ;
}
if ( F_309 ( F_220 ( V_96 ) ) ) {
struct V_39 * V_454 ;
V_454 = F_236 ( V_96 ) ;
if ( V_454 ) {
F_79 () ;
F_246 ( V_454 , V_96 ) ;
F_81 () ;
if ( ! F_67 ( V_454 ) &&
F_380 ( & V_454 -> V_107 ) )
F_184 ( V_454 ) ;
}
}
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return - V_220 ;
V_68 = F_2 ( V_32 -> V_1 ) ;
if ( V_68 > F_206 ( V_32 -> V_72 ) )
V_68 = F_206 ( V_32 -> V_72 ) ;
if ( V_39 -> V_447 > ( 1LL << V_68 ) ) {
F_125 ( L_96
L_97 ,
V_455 , V_68 , V_39 -> V_447 ) ;
return - V_290 ;
}
V_39 -> V_136 = V_68 ;
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
return F_267 ( V_39 , V_96 ) ;
}
static void F_422 ( struct V_40 * V_42 ,
struct V_95 * V_96 )
{
F_246 ( F_45 ( V_42 ) , V_96 ) ;
}
static int F_423 ( struct V_40 * V_42 ,
unsigned long V_212 , T_1 V_456 ,
T_5 V_59 , int V_457 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
V_24 V_447 ;
int V_255 = 0 ;
int V_84 ;
if ( V_457 & V_458 )
V_255 |= V_125 ;
if ( V_457 & V_459 )
V_255 |= V_126 ;
if ( ( V_457 & V_460 ) && V_39 -> V_86 )
V_255 |= V_260 ;
V_447 = V_212 + V_59 ;
if ( V_39 -> V_447 < V_447 ) {
V_24 V_112 ;
V_112 = F_418 ( V_39 -> V_136 ) + 1 ;
if ( V_112 < V_447 ) {
F_125 ( L_96
L_97 ,
V_455 , V_39 -> V_136 , V_447 ) ;
return - V_290 ;
}
V_39 -> V_447 = V_447 ;
}
V_59 = F_221 ( V_456 , V_59 ) ;
V_84 = F_232 ( V_39 , V_212 >> V_12 ,
V_456 >> V_12 , V_59 , V_255 ) ;
return V_84 ;
}
static T_5 F_424 ( struct V_40 * V_42 ,
unsigned long V_212 , T_5 V_59 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_14 * V_137 = NULL ;
struct V_31 * V_32 ;
unsigned long V_129 , V_130 ;
unsigned int V_461 ;
int V_74 , V_5 = 0 ;
F_75 ( ! F_110 ( V_39 , V_212 >> V_12 , & V_5 ) ) ;
if ( V_59 < V_124 << F_6 ( V_5 ) )
V_59 = V_124 << F_6 ( V_5 ) ;
V_129 = V_212 >> V_12 ;
V_130 = ( V_212 + V_59 - 1 ) >> V_12 ;
V_137 = F_121 ( V_39 , V_129 , V_130 ) ;
V_461 = V_130 - V_129 + 1 ;
F_76 (iommu_id, dmar_domain) {
V_32 = V_76 [ V_74 ] ;
F_163 ( V_76 [ V_74 ] , V_39 ,
V_129 , V_461 , ! V_137 , 0 ) ;
}
F_122 ( V_137 ) ;
if ( V_39 -> V_447 == V_212 + V_59 )
V_39 -> V_447 = V_212 ;
return V_59 ;
}
static T_1 F_425 ( struct V_40 * V_42 ,
V_263 V_212 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_27 * V_28 ;
int V_5 = 0 ;
V_24 V_462 = 0 ;
V_28 = F_110 ( V_39 , V_212 >> V_12 , & V_5 ) ;
if ( V_28 )
V_462 = F_35 ( V_28 ) ;
return V_462 ;
}
static bool F_426 ( enum V_463 V_72 )
{
if ( V_72 == V_464 )
return F_82 ( NULL ) == 1 ;
if ( V_72 == V_465 )
return V_466 == 1 ;
return false ;
}
static int F_427 ( struct V_95 * V_96 )
{
struct V_31 * V_32 ;
struct V_467 * V_468 ;
T_6 V_88 , V_89 ;
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return - V_220 ;
F_428 ( & V_32 -> V_32 , V_96 ) ;
V_468 = F_429 ( V_96 ) ;
if ( F_430 ( V_468 ) )
return F_431 ( V_468 ) ;
F_432 ( V_468 ) ;
return 0 ;
}
static void F_433 ( struct V_95 * V_96 )
{
struct V_31 * V_32 ;
T_6 V_88 , V_89 ;
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ! V_32 )
return;
F_434 ( V_96 ) ;
F_435 ( & V_32 -> V_32 , V_96 ) ;
}
static void F_436 ( struct V_95 * V_95 ,
struct V_469 * V_470 )
{
struct V_471 * V_36 ;
struct V_284 * V_285 ;
struct V_95 * V_335 ;
int V_80 ;
F_79 () ;
F_269 (rmrr) {
F_103 (rmrr->devices, rmrr->devices_cnt,
i, i_dev) {
if ( V_335 != V_95 )
continue;
F_437 ( & V_285 -> V_383 -> V_387 , V_470 ) ;
}
}
F_81 () ;
V_36 = F_360 ( V_218 ,
V_219 - V_218 + 1 ,
0 , V_472 ) ;
if ( ! V_36 )
return;
F_437 ( & V_36 -> V_387 , V_470 ) ;
}
static void F_438 ( struct V_95 * V_96 ,
struct V_469 * V_470 )
{
struct V_471 * V_92 , * V_135 ;
F_182 (entry, next, head, list) {
if ( V_92 -> type == V_473 )
F_179 ( V_92 ) ;
}
}
static inline unsigned long F_439 ( struct V_31 * V_32 )
{
if ( F_440 ( V_32 -> V_82 ) < 5 )
return 0 ;
return F_441 ( ( unsigned long * ) & V_32 -> V_474 ,
V_475 ) - 5 ;
}
int F_442 ( struct V_31 * V_32 , struct V_476 * V_477 )
{
struct V_172 * V_173 ;
struct V_22 * V_23 ;
struct V_39 * V_42 ;
unsigned long V_33 ;
V_24 V_478 ;
int V_84 ;
V_42 = F_310 ( V_477 -> V_96 ) ;
if ( ! V_42 )
return - V_44 ;
F_107 ( & V_174 , V_33 ) ;
F_213 ( & V_32 -> V_115 ) ;
V_84 = - V_44 ;
V_173 = V_477 -> V_96 -> V_97 . V_32 ;
if ( ! V_173 || ! V_173 -> V_179 )
goto V_108;
V_23 = F_88 ( V_32 , V_173 -> V_88 , V_173 -> V_89 , 0 ) ;
if ( F_53 ( ! V_23 ) )
goto V_108;
V_478 = V_23 [ 0 ] . V_19 ;
V_477 -> V_56 = V_42 -> V_189 [ V_32 -> V_190 ] ;
V_477 -> V_184 = F_443 ( V_173 -> V_88 , V_173 -> V_89 ) ;
if ( ! ( V_478 & V_479 ) ) {
if ( V_32 -> V_480 )
V_23 [ 1 ] . V_21 = ( V_24 ) F_92 ( V_32 -> V_480 ) ;
V_23 [ 1 ] . V_19 = ( V_24 ) F_92 ( V_32 -> V_481 ) |
F_439 ( V_32 ) ;
F_444 () ;
if ( ( V_478 & V_482 ) == ( V_233 << 2 ) ) {
V_478 &= ~ V_482 ;
if ( V_173 -> V_176 )
V_478 |= V_483 << 2 ;
else
V_478 |= V_484 << 2 ;
}
V_478 |= V_479 ;
if ( V_32 -> V_480 )
V_478 |= V_485 ;
if ( V_173 -> V_181 )
V_478 |= V_486 ;
V_23 [ 0 ] . V_19 = V_478 ;
F_444 () ;
V_32 -> V_191 . V_236 ( V_32 , V_477 -> V_56 , V_477 -> V_184 ,
V_237 ,
V_160 ) ;
}
if ( ! V_173 -> V_180 )
F_150 ( V_173 ) ;
if ( V_173 -> V_178 ) {
V_477 -> V_487 = 1 ;
V_477 -> V_185 = V_173 -> V_183 ;
if ( V_477 -> V_185 >= V_488 )
V_477 -> V_185 = 0 ;
}
V_84 = 0 ;
V_108:
F_214 ( & V_32 -> V_115 ) ;
F_108 ( & V_174 , V_33 ) ;
return V_84 ;
}
struct V_31 * F_445 ( struct V_95 * V_96 )
{
struct V_31 * V_32 ;
T_6 V_88 , V_89 ;
if ( F_93 ( V_96 ) ) {
F_421 ( V_96 ,
L_98 ) ;
return NULL ;
}
V_32 = F_94 ( V_96 , & V_88 , & V_89 ) ;
if ( ( ! V_32 ) ) {
F_311 ( V_96 , L_99 ) ;
return NULL ;
}
if ( ! V_32 -> V_481 ) {
F_311 ( V_96 , L_100 ) ;
return NULL ;
}
return V_32 ;
}
static void F_446 ( struct V_100 * V_96 )
{
F_48 ( L_101 ) ;
V_46 = 0 ;
}
static void F_447 ( struct V_100 * V_96 )
{
F_48 ( L_102 ) ;
V_153 = 1 ;
}
static void F_448 ( struct V_100 * V_96 )
{
unsigned short V_489 ;
if ( F_449 ( V_96 , V_490 , & V_489 ) )
return;
if ( ! ( V_489 & V_491 ) ) {
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
T_10 V_492 ;
V_102 = F_450 ( V_493 , 0x3a3e , NULL ) ;
if ( ! V_102 )
return;
F_260 ( V_102 ) ;
V_102 = F_450 ( V_493 , 0x342e , NULL ) ;
if ( ! V_102 )
return;
if ( F_451 ( V_102 , 0x188 , & V_492 ) ) {
F_260 ( V_102 ) ;
return;
}
F_260 ( V_102 ) ;
if ( V_492 & 1 )
return;
V_492 &= 0x1c ;
if ( V_492 == 0x10 )
return;
if ( ! V_492 ) {
F_254 ( 1 , L_105
L_38 ,
F_255 ( V_280 ) ,
F_255 ( V_281 ) ,
F_255 ( V_282 ) ) ;
V_53 |= V_294 ;
return;
}
F_253 ( L_106 ,
V_492 ) ;
}
