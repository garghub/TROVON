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
}
V_43 += strcspn ( V_43 , L_17 ) ;
while ( * V_43 == ',' )
V_43 ++ ;
}
return 0 ;
}
static struct V_39 * F_50 ( struct V_31 * V_32 , T_4 V_55 )
{
struct V_39 * * V_56 ;
int V_57 = V_55 >> 8 ;
V_56 = V_32 -> V_56 [ V_57 ] ;
if ( ! V_56 )
return NULL ;
return V_56 [ V_55 & 0xff ] ;
}
static void F_51 ( struct V_31 * V_32 , T_4 V_55 ,
struct V_39 * V_42 )
{
struct V_39 * * V_56 ;
int V_57 = V_55 >> 8 ;
if ( ! V_32 -> V_56 [ V_57 ] ) {
T_5 V_58 = 256 * sizeof( struct V_39 * ) ;
V_32 -> V_56 [ V_57 ] = F_52 ( V_58 , V_59 ) ;
}
V_56 = V_32 -> V_56 [ V_57 ] ;
if ( F_53 ( ! V_56 ) )
return;
else
V_56 [ V_55 & 0xff ] = V_42 ;
}
static inline void * F_54 ( int V_60 )
{
struct V_14 * V_14 ;
void * V_61 = NULL ;
V_14 = F_55 ( V_60 , V_59 | V_62 , 0 ) ;
if ( V_14 )
V_61 = F_56 ( V_14 ) ;
return V_61 ;
}
static inline void F_57 ( void * V_61 )
{
F_58 ( ( unsigned long ) V_61 ) ;
}
static inline void * F_59 ( void )
{
return F_60 ( V_63 , V_59 ) ;
}
static void F_61 ( void * V_61 )
{
F_62 ( V_63 , V_61 ) ;
}
static inline void * F_63 ( void )
{
return F_60 ( V_64 , V_59 ) ;
}
static inline void F_64 ( void * V_61 )
{
F_62 ( V_64 , V_61 ) ;
}
static inline int F_65 ( struct V_39 * V_42 )
{
return V_42 -> V_33 & V_65 ;
}
static inline int F_66 ( struct V_39 * V_42 )
{
return V_42 -> V_33 & V_66 ;
}
static inline int F_67 ( struct V_39 * V_42 )
{
return V_42 -> V_33 & ( V_65 |
V_66 ) ;
}
static inline int F_68 ( struct V_39 * V_42 ,
unsigned long V_6 )
{
int V_67 = F_2 ( V_42 -> V_1 ) - V_12 ;
return ! ( V_67 < V_68 && V_6 > > V_67 ) ;
}
static int F_69 ( struct V_31 * V_32 , int V_69 )
{
unsigned long V_70 ;
int V_1 = - 1 ;
V_70 = F_70 ( V_32 -> V_71 ) ;
for ( V_1 = F_4 ( V_69 ) ;
V_1 >= 0 ; V_1 -- ) {
if ( F_71 ( V_1 , & V_70 ) )
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
return F_69 ( V_32 , V_72 ) ;
}
static struct V_31 * F_74 ( struct V_39 * V_42 )
{
int V_73 ;
F_75 ( F_67 ( V_42 ) ) ;
F_76 (iommu_id, domain)
break;
if ( V_73 < 0 || V_73 >= V_74 )
return NULL ;
return V_75 [ V_73 ] ;
}
static void F_77 ( struct V_39 * V_42 )
{
struct V_76 * V_77 ;
struct V_31 * V_32 ;
bool V_78 = false ;
int V_79 ;
V_42 -> V_80 = 1 ;
F_76 (i, domain) {
V_78 = true ;
if ( ! F_78 ( V_75 [ V_79 ] -> V_81 ) ) {
V_42 -> V_80 = 0 ;
break;
}
}
if ( V_78 )
return;
F_79 () ;
F_80 (iommu, drhd) {
if ( ! F_78 ( V_32 -> V_81 ) ) {
V_42 -> V_80 = 0 ;
break;
}
}
F_81 () ;
}
static int F_82 ( struct V_31 * V_82 )
{
struct V_76 * V_77 ;
struct V_31 * V_32 ;
int V_83 = 1 ;
F_79 () ;
F_80 (iommu, drhd) {
if ( V_32 != V_82 ) {
if ( ! F_83 ( V_32 -> V_81 ) ) {
V_83 = 0 ;
break;
}
}
}
F_81 () ;
return V_83 ;
}
static int F_84 ( struct V_31 * V_82 )
{
struct V_76 * V_77 ;
struct V_31 * V_32 ;
int V_84 = 0xf ;
if ( ! V_49 ) {
return 0 ;
}
F_79 () ;
F_80 (iommu, drhd) {
if ( V_32 != V_82 ) {
V_84 &= F_85 ( V_32 -> V_71 ) ;
if ( ! V_84 )
break;
}
}
F_81 () ;
return F_86 ( V_84 ) ;
}
static void F_87 ( struct V_39 * V_42 )
{
F_77 ( V_42 ) ;
V_42 -> V_85 = F_82 ( NULL ) ;
V_42 -> V_86 = F_84 ( NULL ) ;
}
static inline struct V_22 * F_88 ( struct V_31 * V_32 ,
T_6 V_87 , T_6 V_88 , int V_89 )
{
struct V_17 * V_90 = & V_32 -> V_17 [ V_87 ] ;
struct V_22 * V_23 ;
V_24 * V_91 ;
V_91 = & V_90 -> V_19 ;
if ( F_89 ( V_32 ) ) {
if ( V_88 >= 0x80 ) {
V_88 -= 0x80 ;
V_91 = & V_90 -> V_21 ;
}
V_88 *= 2 ;
}
if ( * V_91 & 1 )
V_23 = F_90 ( * V_91 & V_20 ) ;
else {
unsigned long V_92 ;
if ( ! V_89 )
return NULL ;
V_23 = F_54 ( V_32 -> V_60 ) ;
if ( ! V_23 )
return NULL ;
F_91 ( V_32 , ( void * ) V_23 , V_93 ) ;
V_92 = F_92 ( ( void * ) V_23 ) ;
* V_91 = V_92 | 1 ;
F_91 ( V_32 , V_91 , sizeof( * V_91 ) ) ;
}
return & V_23 [ V_88 ] ;
}
static int F_93 ( struct V_94 * V_95 )
{
return V_95 -> V_96 . V_32 == V_97 ;
}
static struct V_31 * F_94 ( struct V_94 * V_95 , T_6 * V_87 , T_6 * V_88 )
{
struct V_76 * V_77 = NULL ;
struct V_31 * V_32 ;
struct V_94 * V_98 ;
struct V_99 * V_100 , * V_101 = NULL ;
T_4 V_102 = 0 ;
int V_79 ;
if ( F_93 ( V_95 ) )
return NULL ;
if ( F_95 ( V_95 ) ) {
V_101 = F_96 ( V_95 ) ;
V_102 = F_97 ( V_101 -> V_87 ) ;
} else if ( F_98 ( V_95 ) )
V_95 = & F_99 ( V_95 ) -> V_95 ;
F_79 () ;
F_80 (iommu, drhd) {
if ( V_101 && V_102 != V_77 -> V_102 )
continue;
F_100 (drhd->devices,
drhd->devices_cnt, i, tmp) {
if ( V_98 == V_95 ) {
* V_87 = V_77 -> V_103 [ V_79 ] . V_87 ;
* V_88 = V_77 -> V_103 [ V_79 ] . V_88 ;
goto V_104;
}
if ( ! V_101 || ! F_95 ( V_98 ) )
continue;
V_100 = F_96 ( V_98 ) ;
if ( V_100 -> V_105 &&
V_100 -> V_105 -> V_106 <= V_101 -> V_87 -> V_106 &&
V_100 -> V_105 -> V_107 . V_108 >= V_101 -> V_87 -> V_106 )
goto V_109;
}
if ( V_101 && V_77 -> V_110 ) {
V_109:
* V_87 = V_101 -> V_87 -> V_106 ;
* V_88 = V_101 -> V_88 ;
goto V_104;
}
}
V_32 = NULL ;
V_104:
F_81 () ;
return V_32 ;
}
static void F_101 ( struct V_39 * V_42 ,
void * V_111 , int V_58 )
{
if ( ! V_42 -> V_80 )
F_102 ( V_111 , V_58 ) ;
}
static int F_103 ( struct V_31 * V_32 , T_6 V_87 , T_6 V_88 )
{
struct V_22 * V_23 ;
int V_83 = 0 ;
unsigned long V_33 ;
F_104 ( & V_32 -> V_112 , V_33 ) ;
V_23 = F_88 ( V_32 , V_87 , V_88 , 0 ) ;
if ( V_23 )
V_83 = F_25 ( V_23 ) ;
F_105 ( & V_32 -> V_112 , V_33 ) ;
return V_83 ;
}
static void F_106 ( struct V_31 * V_32 , T_6 V_87 , T_6 V_88 )
{
struct V_22 * V_23 ;
unsigned long V_33 ;
F_104 ( & V_32 -> V_112 , V_33 ) ;
V_23 = F_88 ( V_32 , V_87 , V_88 , 0 ) ;
if ( V_23 ) {
F_33 ( V_23 ) ;
F_91 ( V_32 , V_23 , sizeof( * V_23 ) ) ;
}
F_105 ( & V_32 -> V_112 , V_33 ) ;
}
static void F_107 ( struct V_31 * V_32 )
{
int V_79 ;
unsigned long V_33 ;
struct V_22 * V_23 ;
F_104 ( & V_32 -> V_112 , V_33 ) ;
if ( ! V_32 -> V_17 ) {
goto V_104;
}
for ( V_79 = 0 ; V_79 < V_113 ; V_79 ++ ) {
V_23 = F_88 ( V_32 , V_79 , 0 , 0 ) ;
if ( V_23 )
F_57 ( V_23 ) ;
if ( ! F_89 ( V_32 ) )
continue;
V_23 = F_88 ( V_32 , V_79 , 0x80 , 0 ) ;
if ( V_23 )
F_57 ( V_23 ) ;
}
F_57 ( V_32 -> V_17 ) ;
V_32 -> V_17 = NULL ;
V_104:
F_105 ( & V_32 -> V_112 , V_33 ) ;
}
static struct V_27 * F_108 ( struct V_39 * V_42 ,
unsigned long V_6 , int * V_114 )
{
struct V_27 * V_115 , * V_28 = NULL ;
int V_5 = F_1 ( V_42 -> V_1 ) ;
int V_116 ;
F_75 ( ! V_42 -> V_117 ) ;
if ( ! F_68 ( V_42 , V_6 ) )
return NULL ;
V_115 = V_42 -> V_117 ;
while ( 1 ) {
void * V_118 ;
V_116 = F_7 ( V_6 , V_5 ) ;
V_28 = & V_115 [ V_116 ] ;
if ( ! * V_114 && ( F_39 ( V_28 ) || ! F_38 ( V_28 ) ) )
break;
if ( V_5 == * V_114 )
break;
if ( ! F_38 ( V_28 ) ) {
T_7 V_119 ;
V_118 = F_54 ( V_42 -> V_120 ) ;
if ( ! V_118 )
return NULL ;
F_101 ( V_42 , V_118 , V_121 ) ;
V_119 = ( ( T_7 ) F_16 ( V_118 ) << V_12 ) | V_122 | V_123 ;
if ( F_109 ( & V_28 -> V_29 , 0ULL , V_119 ) )
F_57 ( V_118 ) ;
else
F_101 ( V_42 , V_28 , sizeof( * V_28 ) ) ;
}
if ( V_5 == 1 )
break;
V_115 = F_90 ( F_35 ( V_28 ) ) ;
V_5 -- ;
}
if ( ! * V_114 )
* V_114 = V_5 ;
return V_28 ;
}
static struct V_27 * F_110 ( struct V_39 * V_42 ,
unsigned long V_6 ,
int V_5 , int * V_124 )
{
struct V_27 * V_115 , * V_28 = NULL ;
int V_125 = F_1 ( V_42 -> V_1 ) ;
int V_116 ;
V_115 = V_42 -> V_117 ;
while ( V_5 <= V_125 ) {
V_116 = F_7 ( V_6 , V_125 ) ;
V_28 = & V_115 [ V_116 ] ;
if ( V_5 == V_125 )
return V_28 ;
if ( ! F_38 ( V_28 ) ) {
* V_124 = V_125 ;
break;
}
if ( F_39 ( V_28 ) ) {
* V_124 = V_125 ;
return V_28 ;
}
V_115 = F_90 ( F_35 ( V_28 ) ) ;
V_125 -- ;
}
return NULL ;
}
static void F_111 ( struct V_39 * V_42 ,
unsigned long V_126 ,
unsigned long V_127 )
{
unsigned int V_124 = 1 ;
struct V_27 * V_128 , * V_28 ;
F_75 ( ! F_68 ( V_42 , V_126 ) ) ;
F_75 ( ! F_68 ( V_42 , V_127 ) ) ;
F_75 ( V_126 > V_127 ) ;
do {
V_124 = 1 ;
V_128 = V_28 = F_110 ( V_42 , V_126 , 1 , & V_124 ) ;
if ( ! V_28 ) {
V_126 = F_10 ( V_126 + 1 , V_124 + 1 ) ;
continue;
}
do {
F_34 ( V_28 ) ;
V_126 += F_11 ( V_124 ) ;
V_28 ++ ;
} while ( V_126 <= V_127 && ! F_40 ( V_28 ) );
F_101 ( V_42 , V_128 ,
( void * ) V_28 - ( void * ) V_128 ) ;
} while ( V_126 && V_126 <= V_127 );
}
static void F_112 ( struct V_39 * V_42 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_126 , unsigned long V_127 )
{
V_6 = F_113 ( V_126 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_129 ;
struct V_27 * V_130 ;
if ( ! F_38 ( V_28 ) || F_39 ( V_28 ) )
goto V_131;
V_129 = V_6 & F_8 ( V_5 - 1 ) ;
V_130 = F_90 ( F_35 ( V_28 ) ) ;
if ( V_5 > 2 )
F_112 ( V_42 , V_5 - 1 , V_130 ,
V_129 , V_126 , V_127 ) ;
if ( ! ( V_126 > V_129 ||
V_127 < V_129 + F_9 ( V_5 ) - 1 ) ) {
F_34 ( V_28 ) ;
F_101 ( V_42 , V_28 , sizeof( * V_28 ) ) ;
F_57 ( V_130 ) ;
}
V_131:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_40 ( ++ V_28 ) && V_6 <= V_127 );
}
static void F_114 ( struct V_39 * V_42 ,
unsigned long V_126 ,
unsigned long V_127 )
{
F_75 ( ! F_68 ( V_42 , V_126 ) ) ;
F_75 ( ! F_68 ( V_42 , V_127 ) ) ;
F_75 ( V_126 > V_127 ) ;
F_111 ( V_42 , V_126 , V_127 ) ;
F_112 ( V_42 , F_1 ( V_42 -> V_1 ) ,
V_42 -> V_117 , 0 , V_126 , V_127 ) ;
if ( V_126 == 0 && V_127 == F_115 ( V_42 -> V_132 ) ) {
F_57 ( V_42 -> V_117 ) ;
V_42 -> V_117 = NULL ;
}
}
static struct V_14 * F_116 ( struct V_39 * V_42 ,
int V_5 , struct V_27 * V_28 ,
struct V_14 * V_133 )
{
struct V_14 * V_15 ;
V_15 = F_117 ( F_35 ( V_28 ) >> V_11 ) ;
V_15 -> V_133 = V_133 ;
V_133 = V_15 ;
if ( V_5 == 1 )
return V_133 ;
V_28 = F_56 ( V_15 ) ;
do {
if ( F_38 ( V_28 ) && ! F_39 ( V_28 ) )
V_133 = F_116 ( V_42 , V_5 - 1 ,
V_28 , V_133 ) ;
V_28 ++ ;
} while ( ! F_40 ( V_28 ) );
return V_133 ;
}
static struct V_14 * F_118 ( struct V_39 * V_42 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_126 ,
unsigned long V_127 ,
struct V_14 * V_133 )
{
struct V_27 * V_128 = NULL , * V_134 = NULL ;
V_6 = F_113 ( V_126 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_129 ;
if ( ! F_38 ( V_28 ) )
goto V_131;
V_129 = V_6 & F_8 ( V_5 ) ;
if ( V_126 <= V_129 &&
V_127 >= V_129 + F_9 ( V_5 ) - 1 ) {
if ( V_5 > 1 && ! F_39 ( V_28 ) )
V_133 = F_116 ( V_42 , V_5 - 1 , V_28 , V_133 ) ;
F_34 ( V_28 ) ;
if ( ! V_128 )
V_128 = V_28 ;
V_134 = V_28 ;
} else if ( V_5 > 1 ) {
V_133 = F_118 ( V_42 , V_5 - 1 ,
F_90 ( F_35 ( V_28 ) ) ,
V_129 , V_126 , V_127 ,
V_133 ) ;
}
V_131:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_40 ( ++ V_28 ) && V_6 <= V_127 );
if ( V_128 )
F_101 ( V_42 , V_128 ,
( void * ) ++ V_134 - ( void * ) V_128 ) ;
return V_133 ;
}
static struct V_14 * F_119 ( struct V_39 * V_42 ,
unsigned long V_126 ,
unsigned long V_127 )
{
struct V_14 * V_133 = NULL ;
F_75 ( ! F_68 ( V_42 , V_126 ) ) ;
F_75 ( ! F_68 ( V_42 , V_127 ) ) ;
F_75 ( V_126 > V_127 ) ;
V_133 = F_118 ( V_42 , F_1 ( V_42 -> V_1 ) ,
V_42 -> V_117 , 0 , V_126 , V_127 , NULL ) ;
if ( V_126 == 0 && V_127 == F_115 ( V_42 -> V_132 ) ) {
struct V_14 * V_135 = F_17 ( V_42 -> V_117 ) ;
V_135 -> V_133 = V_133 ;
V_133 = V_135 ;
V_42 -> V_117 = NULL ;
}
return V_133 ;
}
static void F_120 ( struct V_14 * V_133 )
{
struct V_14 * V_15 ;
while ( ( V_15 = V_133 ) ) {
V_133 = V_15 -> V_133 ;
F_57 ( F_56 ( V_15 ) ) ;
}
}
static int F_121 ( struct V_31 * V_32 )
{
struct V_17 * V_90 ;
unsigned long V_33 ;
V_90 = (struct V_17 * ) F_54 ( V_32 -> V_60 ) ;
if ( ! V_90 ) {
F_122 ( L_18 ,
V_32 -> V_136 ) ;
return - V_137 ;
}
F_91 ( V_32 , V_90 , V_138 ) ;
F_104 ( & V_32 -> V_112 , V_33 ) ;
V_32 -> V_17 = V_90 ;
F_105 ( & V_32 -> V_112 , V_33 ) ;
return 0 ;
}
static void F_123 ( struct V_31 * V_32 )
{
V_24 V_111 ;
T_2 V_139 ;
unsigned long V_140 ;
V_111 = F_92 ( V_32 -> V_17 ) ;
if ( F_89 ( V_32 ) )
V_111 |= V_141 ;
F_124 ( & V_32 -> V_142 , V_140 ) ;
F_125 ( V_32 -> V_36 + V_143 , V_111 ) ;
F_126 ( V_32 -> V_144 | V_145 , V_32 -> V_36 + V_146 ) ;
F_127 ( V_32 , V_37 ,
F_44 , ( V_139 & V_147 ) , V_139 ) ;
F_128 ( & V_32 -> V_142 , V_140 ) ;
}
static void F_129 ( struct V_31 * V_32 )
{
T_2 V_29 ;
unsigned long V_140 ;
if ( ! V_148 && ! F_130 ( V_32 -> V_71 ) )
return;
F_124 ( & V_32 -> V_142 , V_140 ) ;
F_126 ( V_32 -> V_144 | V_149 , V_32 -> V_36 + V_146 ) ;
F_127 ( V_32 , V_37 ,
F_44 , ( ! ( V_29 & V_150 ) ) , V_29 ) ;
F_128 ( & V_32 -> V_142 , V_140 ) ;
}
static void F_131 ( struct V_31 * V_32 ,
T_4 V_55 , T_4 V_151 , T_6 V_152 ,
V_24 type )
{
V_24 V_29 = 0 ;
unsigned long V_140 ;
switch ( type ) {
case V_153 :
V_29 = V_153 ;
break;
case V_154 :
V_29 = V_154 | F_132 ( V_55 ) ;
break;
case V_155 :
V_29 = V_155 | F_132 ( V_55 )
| F_133 ( V_151 ) | F_134 ( V_152 ) ;
break;
default:
F_135 () ;
}
V_29 |= V_156 ;
F_124 ( & V_32 -> V_142 , V_140 ) ;
F_125 ( V_32 -> V_36 + V_157 , V_29 ) ;
F_127 ( V_32 , V_157 ,
V_158 , ( ! ( V_29 & V_156 ) ) , V_29 ) ;
F_128 ( & V_32 -> V_142 , V_140 ) ;
}
static void F_136 ( struct V_31 * V_32 , T_4 V_55 ,
V_24 V_111 , unsigned int V_159 , V_24 type )
{
int V_160 = F_137 ( V_32 -> V_81 ) ;
V_24 V_29 = 0 , V_161 = 0 ;
unsigned long V_140 ;
switch ( type ) {
case V_162 :
V_29 = V_162 | V_163 ;
break;
case V_164 :
V_29 = V_164 | V_163 | F_138 ( V_55 ) ;
break;
case V_165 :
V_29 = V_165 | V_163 | F_138 ( V_55 ) ;
V_161 = V_159 | V_111 ;
break;
default:
F_135 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_139 ( V_32 -> V_71 ) )
V_29 |= V_166 ;
F_124 ( & V_32 -> V_142 , V_140 ) ;
if ( V_161 )
F_125 ( V_32 -> V_36 + V_160 , V_161 ) ;
F_125 ( V_32 -> V_36 + V_160 + 8 , V_29 ) ;
F_127 ( V_32 , V_160 + 8 ,
V_158 , ( ! ( V_29 & V_163 ) ) , V_29 ) ;
F_128 ( & V_32 -> V_142 , V_140 ) ;
if ( F_140 ( V_29 ) == 0 )
F_122 ( L_19 ) ;
if ( F_140 ( V_29 ) != F_141 ( type ) )
F_142 ( L_20 ,
( unsigned long long ) F_141 ( type ) ,
( unsigned long long ) F_140 ( V_29 ) ) ;
}
static struct V_167 *
F_143 ( struct V_39 * V_42 , struct V_31 * V_32 ,
T_6 V_87 , T_6 V_88 )
{
struct V_167 * V_168 ;
F_144 ( & V_169 ) ;
if ( ! V_32 -> V_170 )
return NULL ;
F_145 (info, &domain->devices, link)
if ( V_168 -> V_32 == V_32 && V_168 -> V_87 == V_87 &&
V_168 -> V_88 == V_88 ) {
if ( V_168 -> V_171 && V_168 -> V_95 )
return V_168 ;
break;
}
return NULL ;
}
static void F_146 ( struct V_167 * V_168 )
{
struct V_99 * V_101 ;
if ( ! V_168 || ! F_95 ( V_168 -> V_95 ) )
return;
V_101 = F_96 ( V_168 -> V_95 ) ;
#ifdef F_147
if ( V_168 -> V_172 && ! F_148 ( V_101 , V_168 -> V_172 & ~ 1 ) )
V_168 -> V_173 = 1 ;
if ( V_168 -> V_174 && ! F_149 ( V_101 ) && ! F_150 ( V_101 , 32 ) )
V_168 -> V_175 = 1 ;
#endif
if ( V_168 -> V_171 && ! F_151 ( V_101 , V_12 ) ) {
V_168 -> V_176 = 1 ;
V_168 -> V_177 = F_152 ( V_101 ) ;
}
}
static void F_153 ( struct V_167 * V_168 )
{
struct V_99 * V_101 ;
if ( F_95 ( V_168 -> V_95 ) )
return;
V_101 = F_96 ( V_168 -> V_95 ) ;
if ( V_168 -> V_176 ) {
F_154 ( V_101 ) ;
V_168 -> V_176 = 0 ;
}
#ifdef F_147
if ( V_168 -> V_175 ) {
F_155 ( V_101 ) ;
V_168 -> V_175 = 0 ;
}
if ( V_168 -> V_173 ) {
F_156 ( V_101 ) ;
V_168 -> V_173 = 0 ;
}
#endif
}
static void F_157 ( struct V_39 * V_42 ,
V_24 V_111 , unsigned V_84 )
{
T_4 V_178 , V_179 ;
unsigned long V_33 ;
struct V_167 * V_168 ;
F_104 ( & V_169 , V_33 ) ;
F_145 (info, &domain->devices, link) {
if ( ! V_168 -> V_176 )
continue;
V_178 = V_168 -> V_87 << 8 | V_168 -> V_88 ;
V_179 = V_168 -> V_177 ;
F_158 ( V_168 -> V_32 , V_178 , V_179 , V_111 , V_84 ) ;
}
F_105 ( & V_169 , V_33 ) ;
}
static void F_159 ( struct V_31 * V_32 ,
struct V_39 * V_42 ,
unsigned long V_6 , unsigned int V_180 ,
int V_181 , int V_182 )
{
unsigned int V_84 = F_160 ( F_161 ( V_180 ) ) ;
T_7 V_111 = ( T_7 ) V_6 << V_12 ;
T_4 V_55 = V_42 -> V_183 [ V_32 -> V_184 ] ;
F_75 ( V_180 == 0 ) ;
if ( V_181 )
V_181 = 1 << 6 ;
if ( ! F_162 ( V_32 -> V_71 ) || V_84 > F_163 ( V_32 -> V_71 ) )
V_32 -> V_185 . V_186 ( V_32 , V_55 , 0 , 0 ,
V_164 ) ;
else
V_32 -> V_185 . V_186 ( V_32 , V_55 , V_111 | V_181 , V_84 ,
V_165 ) ;
if ( ! F_164 ( V_32 -> V_71 ) || ! V_182 )
F_157 ( F_50 ( V_32 , V_55 ) ,
V_111 , V_84 ) ;
}
static void F_165 ( struct V_31 * V_32 )
{
T_2 V_187 ;
unsigned long V_33 ;
F_124 ( & V_32 -> V_142 , V_33 ) ;
V_187 = F_44 ( V_32 -> V_36 + V_188 ) ;
V_187 &= ~ V_189 ;
F_126 ( V_187 , V_32 -> V_36 + V_188 ) ;
F_127 ( V_32 , V_188 ,
F_44 , ! ( V_187 & V_190 ) , V_187 ) ;
F_128 ( & V_32 -> V_142 , V_33 ) ;
}
static void F_166 ( struct V_31 * V_32 )
{
T_2 V_139 ;
unsigned long V_33 ;
F_124 ( & V_32 -> V_142 , V_33 ) ;
V_32 -> V_144 |= V_191 ;
F_126 ( V_32 -> V_144 , V_32 -> V_36 + V_146 ) ;
F_127 ( V_32 , V_37 ,
F_44 , ( V_139 & V_38 ) , V_139 ) ;
F_128 ( & V_32 -> V_142 , V_33 ) ;
}
static void F_167 ( struct V_31 * V_32 )
{
T_2 V_139 ;
unsigned long V_140 ;
F_124 ( & V_32 -> V_142 , V_140 ) ;
V_32 -> V_144 &= ~ V_191 ;
F_126 ( V_32 -> V_144 , V_32 -> V_36 + V_146 ) ;
F_127 ( V_32 , V_37 ,
F_44 , ( ! ( V_139 & V_38 ) ) , V_139 ) ;
F_128 ( & V_32 -> V_142 , V_140 ) ;
}
static int F_168 ( struct V_31 * V_32 )
{
T_2 V_192 , V_193 ;
T_5 V_58 ;
V_192 = F_169 ( V_32 -> V_71 ) ;
F_142 ( L_21 ,
V_32 -> V_136 , V_192 ) ;
V_193 = F_170 ( V_192 ) ;
F_171 ( & V_32 -> V_112 ) ;
V_32 -> V_194 = F_172 ( V_193 , sizeof( unsigned long ) , V_195 ) ;
if ( ! V_32 -> V_194 ) {
F_122 ( L_22 ,
V_32 -> V_136 ) ;
return - V_137 ;
}
V_58 = ( ( V_192 >> 8 ) + 1 ) * sizeof( struct V_39 * * ) ;
V_32 -> V_56 = F_52 ( V_58 , V_195 ) ;
if ( V_32 -> V_56 ) {
V_58 = 256 * sizeof( struct V_39 * ) ;
V_32 -> V_56 [ 0 ] = F_52 ( V_58 , V_195 ) ;
}
if ( ! V_32 -> V_56 || ! V_32 -> V_56 [ 0 ] ) {
F_122 ( L_23 ,
V_32 -> V_136 ) ;
F_173 ( V_32 -> V_194 ) ;
F_173 ( V_32 -> V_56 ) ;
V_32 -> V_194 = NULL ;
V_32 -> V_56 = NULL ;
return - V_137 ;
}
F_174 ( 0 , V_32 -> V_194 ) ;
return 0 ;
}
static void F_175 ( struct V_31 * V_32 )
{
struct V_167 * V_168 , * V_98 ;
unsigned long V_33 ;
if ( ! V_32 -> V_56 || ! V_32 -> V_194 )
return;
F_104 ( & V_169 , V_33 ) ;
F_176 (info, tmp, &device_domain_list, global) {
struct V_39 * V_42 ;
if ( V_168 -> V_32 != V_32 )
continue;
if ( ! V_168 -> V_95 || ! V_168 -> V_42 )
continue;
V_42 = V_168 -> V_42 ;
F_177 ( V_42 , V_168 -> V_95 ) ;
if ( ! F_67 ( V_42 ) )
F_178 ( V_42 ) ;
}
F_105 ( & V_169 , V_33 ) ;
if ( V_32 -> V_144 & V_191 )
F_167 ( V_32 ) ;
}
static void F_179 ( struct V_31 * V_32 )
{
if ( ( V_32 -> V_56 ) && ( V_32 -> V_194 ) ) {
int V_196 = ( F_169 ( V_32 -> V_71 ) >> 8 ) + 1 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_196 ; V_79 ++ )
F_173 ( V_32 -> V_56 [ V_79 ] ) ;
F_173 ( V_32 -> V_56 ) ;
F_173 ( V_32 -> V_194 ) ;
V_32 -> V_56 = NULL ;
V_32 -> V_194 = NULL ;
}
V_75 [ V_32 -> V_184 ] = NULL ;
F_107 ( V_32 ) ;
#ifdef F_147
if ( V_173 ( V_32 ) ) {
if ( F_180 ( V_32 -> V_81 ) )
F_181 ( V_32 ) ;
F_182 ( V_32 ) ;
}
#endif
}
static struct V_39 * F_183 ( int V_33 )
{
struct V_39 * V_42 ;
V_42 = F_59 () ;
if ( ! V_42 )
return NULL ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_120 = - 1 ;
V_42 -> V_33 = V_33 ;
F_184 ( & V_42 -> V_103 ) ;
return V_42 ;
}
static int F_185 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
unsigned long V_192 ;
int V_197 ;
F_144 ( & V_169 ) ;
F_144 ( & V_32 -> V_112 ) ;
V_42 -> V_198 [ V_32 -> V_184 ] += 1 ;
V_42 -> V_199 += 1 ;
if ( V_42 -> V_198 [ V_32 -> V_184 ] == 1 ) {
V_192 = F_169 ( V_32 -> V_71 ) ;
V_197 = F_186 ( V_32 -> V_194 , V_192 ) ;
if ( V_197 >= V_192 ) {
F_122 ( L_24 , V_32 -> V_136 ) ;
V_42 -> V_198 [ V_32 -> V_184 ] -= 1 ;
V_42 -> V_199 -= 1 ;
return - V_200 ;
}
F_174 ( V_197 , V_32 -> V_194 ) ;
F_51 ( V_32 , V_197 , V_42 ) ;
V_42 -> V_183 [ V_32 -> V_184 ] = V_197 ;
V_42 -> V_120 = V_32 -> V_60 ;
F_87 ( V_42 ) ;
}
return 0 ;
}
static int F_187 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
int V_197 , V_201 = V_202 ;
F_144 ( & V_169 ) ;
F_144 ( & V_32 -> V_112 ) ;
V_42 -> V_198 [ V_32 -> V_184 ] -= 1 ;
V_201 = -- V_42 -> V_199 ;
if ( V_42 -> V_198 [ V_32 -> V_184 ] == 0 ) {
V_197 = V_42 -> V_183 [ V_32 -> V_184 ] ;
F_188 ( V_197 , V_32 -> V_194 ) ;
F_51 ( V_32 , V_197 , NULL ) ;
F_87 ( V_42 ) ;
V_42 -> V_183 [ V_32 -> V_184 ] = 0 ;
}
return V_201 ;
}
static int F_189 ( void )
{
struct V_99 * V_101 = NULL ;
struct V_203 * V_203 ;
int V_79 ;
F_190 ( & V_204 , V_121 , V_205 ,
V_206 ) ;
F_191 ( & V_204 . V_207 ,
& V_208 ) ;
V_203 = F_192 ( & V_204 , F_193 ( V_209 ) ,
F_193 ( V_210 ) ) ;
if ( ! V_203 ) {
F_122 ( L_25 ) ;
return - V_211 ;
}
F_194 (pdev) {
struct V_212 * V_213 ;
for ( V_79 = 0 ; V_79 < V_214 ; V_79 ++ ) {
V_213 = & V_101 -> V_212 [ V_79 ] ;
if ( ! V_213 -> V_33 || ! ( V_213 -> V_33 & V_215 ) )
continue;
V_203 = F_192 ( & V_204 ,
F_193 ( V_213 -> V_216 ) ,
F_193 ( V_213 -> V_108 ) ) ;
if ( ! V_203 ) {
F_122 ( L_26 ) ;
return - V_211 ;
}
}
}
return 0 ;
}
static void F_195 ( struct V_39 * V_42 )
{
F_196 ( & V_204 , & V_42 -> V_217 ) ;
}
static inline int F_197 ( int V_132 )
{
int V_1 ;
int V_213 = ( V_132 - 12 ) % 9 ;
if ( V_213 == 0 )
V_1 = V_132 ;
else
V_1 = V_132 + 9 - V_213 ;
if ( V_1 > 64 )
V_1 = 64 ;
return V_1 ;
}
static int F_198 ( struct V_39 * V_42 , struct V_31 * V_32 ,
int V_218 )
{
int V_219 , V_1 ;
unsigned long V_70 ;
F_190 ( & V_42 -> V_217 , V_121 , V_205 ,
V_206 ) ;
F_195 ( V_42 ) ;
if ( V_218 > F_199 ( V_32 -> V_71 ) )
V_218 = F_199 ( V_32 -> V_71 ) ;
V_42 -> V_132 = V_218 ;
V_219 = F_197 ( V_218 ) ;
V_1 = F_4 ( V_219 ) ;
V_70 = F_70 ( V_32 -> V_71 ) ;
if ( ! F_71 ( V_1 , & V_70 ) ) {
F_142 ( L_27 , V_1 ) ;
V_1 = F_200 ( & V_70 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_211 ;
}
V_42 -> V_1 = V_1 ;
if ( F_78 ( V_32 -> V_81 ) )
V_42 -> V_80 = 1 ;
else
V_42 -> V_80 = 0 ;
if ( F_83 ( V_32 -> V_81 ) )
V_42 -> V_85 = 1 ;
else
V_42 -> V_85 = 0 ;
if ( V_49 )
V_42 -> V_86 = F_86 ( F_85 ( V_32 -> V_71 ) ) ;
else
V_42 -> V_86 = 0 ;
V_42 -> V_120 = V_32 -> V_60 ;
V_42 -> V_117 = (struct V_27 * ) F_54 ( V_42 -> V_120 ) ;
if ( ! V_42 -> V_117 )
return - V_137 ;
F_91 ( V_32 , V_42 -> V_117 , V_220 ) ;
return 0 ;
}
static void F_178 ( struct V_39 * V_42 )
{
struct V_14 * V_133 = NULL ;
if ( ! V_42 )
return;
if ( ! V_48 )
F_201 ( 0 ) ;
F_79 () ;
F_202 ( V_42 ) ;
F_81 () ;
F_203 ( & V_42 -> V_217 ) ;
V_133 = F_119 ( V_42 , 0 , F_115 ( V_42 -> V_132 ) ) ;
F_120 ( V_133 ) ;
F_61 ( V_42 ) ;
}
static int F_204 ( struct V_39 * V_42 ,
struct V_31 * V_32 ,
T_6 V_87 , T_6 V_88 )
{
T_4 V_55 = V_42 -> V_183 [ V_32 -> V_184 ] ;
int V_221 = V_222 ;
struct V_167 * V_168 = NULL ;
struct V_22 * V_23 ;
unsigned long V_33 ;
struct V_27 * V_117 ;
int V_83 , V_1 ;
F_53 ( V_55 == 0 ) ;
if ( V_223 && F_66 ( V_42 ) )
V_221 = V_224 ;
F_142 ( L_28 ,
V_87 , F_205 ( V_88 ) , F_206 ( V_88 ) ) ;
F_75 ( ! V_42 -> V_117 ) ;
F_104 ( & V_169 , V_33 ) ;
F_207 ( & V_32 -> V_112 ) ;
V_83 = - V_137 ;
V_23 = F_88 ( V_32 , V_87 , V_88 , 1 ) ;
if ( ! V_23 )
goto V_225;
V_83 = 0 ;
if ( F_25 ( V_23 ) )
goto V_225;
V_117 = V_42 -> V_117 ;
F_33 ( V_23 ) ;
F_31 ( V_23 , V_55 ) ;
if ( V_221 != V_224 ) {
for ( V_1 = V_42 -> V_1 ; V_1 != V_32 -> V_1 ; V_1 -- ) {
V_83 = - V_137 ;
V_117 = F_90 ( F_35 ( V_117 ) ) ;
if ( ! F_38 ( V_117 ) )
goto V_225;
}
V_168 = F_143 ( V_42 , V_32 , V_87 , V_88 ) ;
if ( V_168 && V_168 -> V_171 )
V_221 = V_226 ;
else
V_221 = V_222 ;
F_29 ( V_23 , F_92 ( V_117 ) ) ;
F_30 ( V_23 , V_32 -> V_1 ) ;
} else {
F_30 ( V_23 , V_32 -> V_227 ) ;
}
F_28 ( V_23 , V_221 ) ;
F_27 ( V_23 ) ;
F_26 ( V_23 ) ;
F_101 ( V_42 , V_23 , sizeof( * V_23 ) ) ;
if ( F_164 ( V_32 -> V_71 ) ) {
V_32 -> V_185 . V_228 ( V_32 , 0 ,
( ( ( T_4 ) V_87 ) << 8 ) | V_88 ,
V_229 ,
V_155 ) ;
V_32 -> V_185 . V_186 ( V_32 , V_55 , 0 , 0 , V_164 ) ;
} else {
F_129 ( V_32 ) ;
}
F_146 ( V_168 ) ;
V_83 = 0 ;
V_225:
F_208 ( & V_32 -> V_112 ) ;
F_105 ( & V_169 , V_33 ) ;
return 0 ;
}
static int F_209 ( struct V_99 * V_101 ,
T_4 V_230 , void * V_231 )
{
struct V_232 * V_233 = V_231 ;
return F_204 ( V_233 -> V_42 , V_233 -> V_32 ,
F_210 ( V_230 ) , V_230 & 0xff ) ;
}
static int
F_211 ( struct V_39 * V_42 , struct V_94 * V_95 )
{
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
struct V_232 V_233 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_211 ;
if ( ! F_95 ( V_95 ) )
return F_204 ( V_42 , V_32 , V_87 , V_88 ) ;
V_233 . V_42 = V_42 ;
V_233 . V_32 = V_32 ;
return F_212 ( F_96 ( V_95 ) ,
& F_209 , & V_233 ) ;
}
static int F_213 ( struct V_99 * V_101 ,
T_4 V_230 , void * V_231 )
{
struct V_31 * V_32 = V_231 ;
return ! F_103 ( V_32 , F_210 ( V_230 ) , V_230 & 0xff ) ;
}
static int F_214 ( struct V_94 * V_95 )
{
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_211 ;
if ( ! F_95 ( V_95 ) )
return F_103 ( V_32 , V_87 , V_88 ) ;
return ! F_212 ( F_96 ( V_95 ) ,
F_213 , V_32 ) ;
}
static inline unsigned long F_215 ( unsigned long V_234 ,
T_5 V_58 )
{
V_234 &= ~ V_235 ;
return F_216 ( V_234 + V_58 ) >> V_12 ;
}
static inline int F_217 ( struct V_39 * V_42 ,
unsigned long V_236 ,
unsigned long V_237 ,
unsigned long V_180 )
{
int V_238 , V_5 = 1 ;
unsigned long V_239 ;
V_238 = V_42 -> V_86 ;
V_239 = V_236 | V_237 ;
while ( V_238 && ! ( V_239 & ~ V_240 ) ) {
V_180 >>= V_241 ;
if ( ! V_180 )
break;
V_239 >>= V_241 ;
V_5 ++ ;
V_238 -- ;
}
return V_5 ;
}
static int F_218 ( struct V_39 * V_42 , unsigned long V_236 ,
struct V_242 * V_243 , unsigned long V_244 ,
unsigned long V_245 , int V_246 )
{
struct V_27 * V_128 = NULL , * V_28 = NULL ;
T_1 V_247 ( V_119 ) ;
unsigned long V_248 = 0 ;
unsigned int V_249 = 0 ;
unsigned long V_250 = 0 ;
F_75 ( ! F_68 ( V_42 , V_236 + V_245 - 1 ) ) ;
if ( ( V_246 & ( V_122 | V_123 ) ) == 0 )
return - V_44 ;
V_246 &= V_122 | V_123 | V_251 ;
if ( ! V_243 ) {
V_248 = V_245 ;
V_119 = ( ( T_1 ) V_244 << V_12 ) | V_246 ;
}
while ( V_245 > 0 ) {
T_7 V_98 ;
if ( ! V_248 ) {
V_248 = F_215 ( V_243 -> V_116 , V_243 -> V_252 ) ;
V_243 -> V_253 = ( ( V_254 ) V_236 << V_12 ) + V_243 -> V_116 ;
V_243 -> V_255 = V_243 -> V_252 ;
V_119 = F_219 ( F_220 ( V_243 ) ) | V_246 ;
V_244 = V_119 >> V_12 ;
}
if ( ! V_28 ) {
V_249 = F_217 ( V_42 , V_236 , V_244 , V_248 ) ;
V_128 = V_28 = F_108 ( V_42 , V_236 , & V_249 ) ;
if ( ! V_28 )
return - V_137 ;
if ( V_249 > 1 ) {
unsigned long V_256 , V_257 ;
V_119 |= V_30 ;
V_250 = F_11 ( V_249 ) ;
V_256 = V_248 / V_250 ;
V_257 = V_236 + V_256 * V_250 - 1 ;
F_114 ( V_42 , V_236 , V_257 ) ;
} else {
V_119 &= ~ ( T_7 ) V_30 ;
}
}
V_98 = F_221 ( & V_28 -> V_29 , 0ULL , V_119 ) ;
if ( V_98 ) {
static int V_258 = 5 ;
F_222 ( L_29 ,
V_236 , V_98 , ( unsigned long long ) V_119 ) ;
if ( V_258 ) {
V_258 -- ;
F_223 ( NULL ) ;
}
F_53 ( 1 ) ;
}
V_250 = F_11 ( V_249 ) ;
F_75 ( V_245 < V_250 ) ;
F_75 ( V_248 < V_250 ) ;
V_245 -= V_250 ;
V_236 += V_250 ;
V_244 += V_250 ;
V_119 += V_250 * V_121 ;
V_248 -= V_250 ;
V_28 ++ ;
if ( ! V_245 || F_40 ( V_28 ) ||
( V_249 > 1 && V_248 < V_250 ) ) {
F_101 ( V_42 , V_128 ,
( void * ) V_28 - ( void * ) V_128 ) ;
V_28 = NULL ;
}
if ( ! V_248 && V_245 )
V_243 = F_224 ( V_243 ) ;
}
return 0 ;
}
static inline int F_225 ( struct V_39 * V_42 , unsigned long V_236 ,
struct V_242 * V_243 , unsigned long V_245 ,
int V_246 )
{
return F_218 ( V_42 , V_236 , V_243 , 0 , V_245 , V_246 ) ;
}
static inline int F_226 ( struct V_39 * V_42 , unsigned long V_236 ,
unsigned long V_244 , unsigned long V_245 ,
int V_246 )
{
return F_218 ( V_42 , V_236 , NULL , V_244 , V_245 , V_246 ) ;
}
static void F_227 ( struct V_31 * V_32 , T_6 V_87 , T_6 V_88 )
{
if ( ! V_32 )
return;
F_106 ( V_32 , V_87 , V_88 ) ;
V_32 -> V_185 . V_228 ( V_32 , 0 , 0 , 0 ,
V_153 ) ;
V_32 -> V_185 . V_186 ( V_32 , 0 , 0 , 0 , V_162 ) ;
}
static inline void F_228 ( struct V_167 * V_168 )
{
F_144 ( & V_169 ) ;
F_229 ( & V_168 -> V_259 ) ;
F_229 ( & V_168 -> V_260 ) ;
if ( V_168 -> V_95 )
V_168 -> V_95 -> V_96 . V_32 = NULL ;
}
static void F_202 ( struct V_39 * V_42 )
{
struct V_167 * V_168 , * V_98 ;
unsigned long V_33 ;
F_104 ( & V_169 , V_33 ) ;
F_176 (info, tmp, &domain->devices, link)
F_230 ( V_168 ) ;
F_105 ( & V_169 , V_33 ) ;
}
static struct V_39 * F_231 ( struct V_94 * V_95 )
{
struct V_167 * V_168 ;
V_168 = V_95 -> V_96 . V_32 ;
if ( V_168 )
return V_168 -> V_42 ;
return NULL ;
}
static inline struct V_167 *
F_232 ( int V_102 , int V_87 , int V_88 )
{
struct V_167 * V_168 ;
F_145 (info, &device_domain_list, global)
if ( V_168 -> V_32 -> V_102 == V_102 && V_168 -> V_87 == V_87 &&
V_168 -> V_88 == V_88 )
return V_168 ;
return NULL ;
}
static struct V_39 * F_233 ( struct V_31 * V_32 ,
int V_87 , int V_88 ,
struct V_94 * V_95 ,
struct V_39 * V_42 )
{
struct V_39 * V_78 = NULL ;
struct V_167 * V_168 ;
unsigned long V_33 ;
int V_83 ;
V_168 = F_63 () ;
if ( ! V_168 )
return NULL ;
V_168 -> V_87 = V_87 ;
V_168 -> V_88 = V_88 ;
V_168 -> V_171 = V_168 -> V_172 = V_168 -> V_174 = 0 ;
V_168 -> V_176 = V_168 -> V_173 = V_168 -> V_175 = 0 ;
V_168 -> V_177 = 0 ;
V_168 -> V_95 = V_95 ;
V_168 -> V_42 = V_42 ;
V_168 -> V_32 = V_32 ;
if ( V_95 && F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_168 -> V_95 ) ;
if ( F_234 ( V_32 -> V_81 ) &&
F_235 ( V_101 , V_261 ) &&
F_236 ( V_101 ) )
V_168 -> V_171 = 1 ;
if ( F_89 ( V_32 ) ) {
if ( V_173 ( V_32 ) ) {
int V_262 = F_237 ( V_101 ) ;
if ( V_262 >= 0 )
V_168 -> V_172 = V_262 | 1 ;
}
if ( V_168 -> V_171 && F_180 ( V_32 -> V_81 ) &&
F_235 ( V_101 , V_263 ) )
V_168 -> V_174 = 1 ;
}
}
F_104 ( & V_169 , V_33 ) ;
if ( V_95 )
V_78 = F_231 ( V_95 ) ;
if ( ! V_78 ) {
struct V_167 * V_264 ;
V_264 = F_232 ( V_32 -> V_102 , V_87 , V_88 ) ;
if ( V_264 ) {
V_78 = V_264 -> V_42 ;
V_264 -> V_95 = V_95 ;
}
}
if ( V_78 ) {
F_105 ( & V_169 , V_33 ) ;
F_64 ( V_168 ) ;
return V_78 ;
}
F_207 ( & V_32 -> V_112 ) ;
V_83 = F_185 ( V_42 , V_32 ) ;
F_208 ( & V_32 -> V_112 ) ;
if ( V_83 ) {
F_105 ( & V_169 , V_33 ) ;
F_64 ( V_168 ) ;
return NULL ;
}
F_238 ( & V_168 -> V_259 , & V_42 -> V_103 ) ;
F_238 ( & V_168 -> V_260 , & V_265 ) ;
if ( V_95 )
V_95 -> V_96 . V_32 = V_168 ;
F_105 ( & V_169 , V_33 ) ;
if ( V_95 && F_211 ( V_42 , V_95 ) ) {
F_122 ( L_30 , F_239 ( V_95 ) ) ;
F_177 ( V_42 , V_95 ) ;
return NULL ;
}
return V_42 ;
}
static int F_240 ( struct V_99 * V_101 , T_4 V_230 , void * V_231 )
{
* ( T_4 * ) V_231 = V_230 ;
return 0 ;
}
static struct V_39 * F_241 ( struct V_94 * V_95 , int V_132 )
{
struct V_167 * V_168 = NULL ;
struct V_39 * V_42 , * V_98 ;
struct V_31 * V_32 ;
T_4 V_266 , V_267 ;
unsigned long V_33 ;
T_6 V_87 , V_88 ;
V_42 = F_231 ( V_95 ) ;
if ( V_42 )
return V_42 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return NULL ;
V_266 = ( ( T_4 ) V_87 << 8 ) | V_88 ;
if ( F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_95 ) ;
F_212 ( V_101 , F_240 , & V_267 ) ;
F_104 ( & V_169 , V_33 ) ;
V_168 = F_232 ( F_97 ( V_101 -> V_87 ) ,
F_210 ( V_267 ) ,
V_267 & 0xff ) ;
if ( V_168 ) {
V_32 = V_168 -> V_32 ;
V_42 = V_168 -> V_42 ;
}
F_105 ( & V_169 , V_33 ) ;
if ( V_168 )
goto V_268;
}
V_42 = F_183 ( 0 ) ;
if ( ! V_42 )
return NULL ;
if ( F_198 ( V_42 , V_32 , V_132 ) ) {
F_178 ( V_42 ) ;
return NULL ;
}
if ( V_266 != V_267 && F_95 ( V_95 ) ) {
V_98 = F_233 ( V_32 , F_210 ( V_267 ) ,
V_267 & 0xff , NULL , V_42 ) ;
if ( ! V_98 || V_98 != V_42 ) {
F_178 ( V_42 ) ;
V_42 = V_98 ;
}
if ( ! V_42 )
return NULL ;
}
V_268:
V_98 = F_233 ( V_32 , V_87 , V_88 , V_95 , V_42 ) ;
if ( ! V_98 || V_98 != V_42 ) {
F_178 ( V_42 ) ;
V_42 = V_98 ;
}
return V_42 ;
}
static int F_242 ( struct V_39 * V_42 ,
unsigned long long V_216 ,
unsigned long long V_108 )
{
unsigned long V_269 = V_216 >> V_12 ;
unsigned long V_270 = V_108 >> V_12 ;
if ( ! F_192 ( & V_42 -> V_217 , F_12 ( V_269 ) ,
F_12 ( V_270 ) ) ) {
F_122 ( L_31 ) ;
return - V_137 ;
}
F_142 ( L_32 , V_216 , V_108 ) ;
F_111 ( V_42 , V_269 , V_270 ) ;
return F_226 ( V_42 , V_269 , V_269 ,
V_270 - V_269 + 1 ,
V_122 | V_123 ) ;
}
static int F_243 ( struct V_94 * V_95 ,
struct V_39 * V_42 ,
unsigned long long V_216 ,
unsigned long long V_108 )
{
if ( V_42 == V_271 && V_223 ) {
F_244 ( L_33 ,
F_239 ( V_95 ) , V_216 , V_108 ) ;
return 0 ;
}
F_48 ( L_34 ,
F_239 ( V_95 ) , V_216 , V_108 ) ;
if ( V_108 < V_216 ) {
F_245 ( 1 , L_35
L_36 ,
F_246 ( V_272 ) ,
F_246 ( V_273 ) ,
F_246 ( V_274 ) ) ;
return - V_275 ;
}
if ( V_108 >> F_2 ( V_42 -> V_1 ) ) {
F_245 ( 1 , L_37
L_36 ,
F_2 ( V_42 -> V_1 ) ,
F_246 ( V_272 ) ,
F_246 ( V_273 ) ,
F_246 ( V_274 ) ) ;
return - V_275 ;
}
return F_242 ( V_42 , V_216 , V_108 ) ;
}
static int F_247 ( struct V_94 * V_95 ,
unsigned long long V_216 ,
unsigned long long V_108 )
{
struct V_39 * V_42 ;
int V_83 ;
V_42 = F_241 ( V_95 , V_72 ) ;
if ( ! V_42 )
return - V_137 ;
V_83 = F_243 ( V_95 , V_42 , V_216 , V_108 ) ;
if ( V_83 )
F_178 ( V_42 ) ;
return V_83 ;
}
static inline int F_248 ( struct V_276 * V_277 ,
struct V_94 * V_95 )
{
if ( V_95 -> V_96 . V_32 == V_97 )
return 0 ;
return F_247 ( V_95 , V_277 -> V_278 ,
V_277 -> V_279 ) ;
}
static inline void F_249 ( void )
{
struct V_99 * V_101 ;
int V_83 ;
V_101 = F_250 ( V_280 << 8 , NULL ) ;
if ( ! V_101 )
return;
F_48 ( L_38 ) ;
V_83 = F_247 ( & V_101 -> V_95 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_83 )
F_122 ( L_39 ) ;
F_251 ( V_101 ) ;
}
static inline void F_249 ( void )
{
return;
}
static int T_3 F_252 ( int V_281 )
{
int V_120 , V_83 = 0 ;
V_271 = F_183 ( V_66 ) ;
if ( ! V_271 )
return - V_282 ;
if ( F_253 ( V_271 , V_72 ) ) {
F_178 ( V_271 ) ;
return - V_282 ;
}
F_142 ( L_40 ) ;
if ( V_281 )
return 0 ;
F_254 (nid) {
unsigned long V_126 , V_257 ;
int V_79 ;
F_255 (i, nid, &start_pfn, &end_pfn, NULL) {
V_83 = F_242 ( V_271 ,
F_256 ( V_126 ) , F_256 ( V_257 ) ) ;
if ( V_83 )
return V_83 ;
}
}
return 0 ;
}
static int F_257 ( struct V_94 * V_95 )
{
struct V_167 * V_168 ;
if ( F_258 ( ! V_53 ) )
return 0 ;
V_168 = V_95 -> V_96 . V_32 ;
if ( V_168 && V_168 != V_97 )
return ( V_168 -> V_42 == V_271 ) ;
return 0 ;
}
static int F_259 ( struct V_39 * V_42 , struct V_94 * V_95 )
{
struct V_39 * V_283 ;
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_211 ;
V_283 = F_233 ( V_32 , V_87 , V_88 , V_95 , V_42 ) ;
if ( V_283 != V_42 )
return - V_284 ;
return 0 ;
}
static bool F_260 ( struct V_94 * V_95 )
{
struct V_276 * V_277 ;
struct V_94 * V_98 ;
int V_79 ;
F_79 () ;
F_261 (rmrr) {
F_100 (rmrr->devices,
rmrr->devices_cnt, i, tmp)
if ( V_98 == V_95 ) {
F_81 () ;
return true ;
}
}
F_81 () ;
return false ;
}
static bool F_262 ( struct V_94 * V_95 )
{
if ( ! F_260 ( V_95 ) )
return false ;
if ( F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_95 ) ;
if ( F_263 ( V_101 ) || F_264 ( V_101 ) )
return false ;
}
return true ;
}
static int F_265 ( struct V_94 * V_95 , int V_285 )
{
if ( F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_95 ) ;
if ( F_262 ( V_95 ) )
return 0 ;
if ( ( V_53 & V_286 ) && F_266 ( V_101 ) )
return 1 ;
if ( ( V_53 & V_54 ) && F_264 ( V_101 ) )
return 1 ;
if ( ! ( V_53 & V_287 ) )
return 0 ;
if ( ! F_267 ( V_101 ) ) {
if ( ! F_268 ( V_101 -> V_87 ) )
return 0 ;
if ( V_101 -> V_288 >> 8 == V_289 )
return 0 ;
} else if ( F_269 ( V_101 ) == V_290 )
return 0 ;
} else {
if ( F_260 ( V_95 ) )
return 0 ;
}
if ( ! V_285 ) {
V_24 V_291 = * V_95 -> V_291 ;
if ( V_95 -> V_292 &&
V_95 -> V_292 < V_291 )
V_291 = V_95 -> V_292 ;
return V_291 >= F_270 ( V_95 ) ;
}
return 1 ;
}
static int T_3 F_271 ( struct V_94 * V_95 , int V_281 )
{
int V_83 ;
if ( ! F_265 ( V_95 , 1 ) )
return 0 ;
V_83 = F_259 ( V_271 , V_95 ) ;
if ( ! V_83 )
F_48 ( L_41 ,
V_281 ? L_42 : L_43 , F_239 ( V_95 ) ) ;
else if ( V_83 == - V_211 )
V_83 = 0 ;
return V_83 ;
}
static int T_3 F_272 ( int V_281 )
{
struct V_99 * V_101 = NULL ;
struct V_76 * V_77 ;
struct V_31 * V_32 ;
struct V_94 * V_95 ;
int V_79 ;
int V_83 = 0 ;
F_194 (pdev) {
V_83 = F_271 ( & V_101 -> V_95 , V_281 ) ;
if ( V_83 )
return V_83 ;
}
F_80 (iommu, drhd)
F_100 (drhd->devices, drhd->devices_cnt, i, dev) {
struct V_293 * V_294 ;
struct V_295 * V_296 ;
if ( V_95 -> V_87 != & V_297 )
continue;
V_296 = F_273 ( V_95 ) ;
F_274 ( & V_296 -> V_298 ) ;
F_145 (pn, &adev->physical_node_list, node) {
V_83 = F_271 ( V_294 -> V_95 , V_281 ) ;
if ( V_83 )
break;
}
F_275 ( & V_296 -> V_298 ) ;
if ( V_83 )
return V_83 ;
}
return 0 ;
}
static void F_276 ( struct V_31 * V_32 )
{
if ( ! V_32 -> V_170 ) {
F_277 ( - 1 , V_32 ) ;
F_278 ( V_32 ) ;
}
if ( F_279 ( V_32 ) ) {
V_32 -> V_185 . V_228 = F_131 ;
V_32 -> V_185 . V_186 = F_136 ;
F_48 ( L_44 ,
V_32 -> V_136 ) ;
} else {
V_32 -> V_185 . V_228 = V_299 ;
V_32 -> V_185 . V_186 = V_300 ;
F_48 ( L_45 , V_32 -> V_136 ) ;
}
}
static int F_280 ( struct V_31 * V_32 ,
struct V_17 * V_301 ,
struct V_22 * * V_302 ,
int V_87 , bool V_303 )
{
int V_304 , V_305 = 0 , V_57 , V_88 , V_83 = 0 , V_55 ;
struct V_22 * V_306 = NULL , V_307 ;
struct V_22 * V_308 = NULL ;
struct V_17 V_18 ;
T_1 V_309 ;
V_304 = V_303 ? V_87 * 2 : V_87 ;
memcpy ( & V_18 , V_301 , sizeof( V_18 ) ) ;
for ( V_88 = 0 ; V_88 < 256 ; V_88 ++ ) {
V_57 = ( V_303 ? V_88 * 2 : V_88 ) % 256 ;
if ( V_57 == 0 ) {
if ( V_306 ) {
V_302 [ V_304 ] = V_306 ;
F_91 ( V_32 , V_306 ,
V_121 ) ;
V_305 = 1 ;
}
if ( V_308 )
F_281 ( V_308 ) ;
V_83 = 0 ;
if ( V_88 < 0x80 )
V_309 = F_18 ( & V_18 ) ;
else
V_309 = F_19 ( & V_18 ) ;
if ( ! V_309 ) {
if ( V_303 && V_88 == 0 ) {
V_88 = 0x7f ;
continue;
} else {
goto V_104;
}
}
V_83 = - V_137 ;
V_308 = F_282 ( V_309 , V_220 ,
V_310 ) ;
if ( ! V_308 )
goto V_104;
V_306 = F_54 ( V_32 -> V_60 ) ;
if ( ! V_306 )
goto V_311;
V_83 = 0 ;
}
memcpy ( & V_307 , V_308 + V_57 , sizeof( V_307 ) ) ;
if ( ! F_24 ( & V_307 ) )
continue;
V_55 = F_32 ( & V_307 ) ;
if ( V_55 >= 0 && V_55 < F_169 ( V_32 -> V_71 ) )
F_174 ( V_55 , V_32 -> V_194 ) ;
F_20 ( & V_307 ) ;
F_22 ( & V_307 ) ;
V_306 [ V_57 ] = V_307 ;
}
V_302 [ V_304 + V_305 ] = V_306 ;
F_91 ( V_32 , V_306 , V_121 ) ;
V_311:
F_283 ( V_308 ) ;
V_104:
return V_83 ;
}
static int F_284 ( struct V_31 * V_32 )
{
struct V_22 * * V_312 ;
struct V_17 * V_313 ;
T_1 V_314 ;
int V_315 ;
unsigned long V_33 ;
V_24 V_316 ;
int V_87 , V_83 ;
bool V_317 , V_303 ;
V_316 = V_158 ( V_32 -> V_36 + V_143 ) ;
V_303 = ! ! ( V_316 & V_141 ) ;
V_317 = ! ! F_285 ( V_32 -> V_81 ) ;
if ( V_317 != V_303 )
return - V_44 ;
V_314 = V_316 & V_20 ;
if ( ! V_314 )
return - V_44 ;
V_313 = F_282 ( V_314 , V_220 , V_310 ) ;
if ( ! V_313 )
return - V_137 ;
V_315 = V_303 ? 512 : 256 ;
V_83 = - V_137 ;
V_312 = F_52 ( V_315 * sizeof( void * ) , V_195 ) ;
if ( ! V_312 )
goto V_311;
for ( V_87 = 0 ; V_87 < 256 ; V_87 ++ ) {
V_83 = F_280 ( V_32 , & V_313 [ V_87 ] ,
V_312 , V_87 , V_303 ) ;
if ( V_83 ) {
F_122 ( L_46 ,
V_32 -> V_136 , V_87 ) ;
continue;
}
}
F_104 ( & V_32 -> V_112 , V_33 ) ;
for ( V_87 = 0 ; V_87 < 256 ; V_87 ++ ) {
int V_57 = V_303 ? V_87 * 2 : V_87 ;
V_24 V_29 ;
if ( V_312 [ V_57 ] ) {
V_29 = F_92 ( V_312 [ V_57 ] ) | 1 ;
V_32 -> V_17 [ V_87 ] . V_19 = V_29 ;
}
if ( ! V_303 || ! V_312 [ V_57 + 1 ] )
continue;
V_29 = F_92 ( V_312 [ V_57 + 1 ] ) | 1 ;
V_32 -> V_17 [ V_87 ] . V_21 = V_29 ;
}
F_105 ( & V_32 -> V_112 , V_33 ) ;
F_173 ( V_312 ) ;
F_91 ( V_32 , V_32 -> V_17 , V_220 ) ;
V_83 = 0 ;
V_311:
F_283 ( V_313 ) ;
return V_83 ;
}
static int T_3 F_286 ( void )
{
struct V_76 * V_77 ;
struct V_276 * V_277 ;
bool V_318 = false ;
struct V_94 * V_95 ;
struct V_31 * V_32 ;
int V_79 , V_83 ;
F_287 (drhd) {
if ( V_74 < V_319 ) {
V_74 ++ ;
continue;
}
F_288 ( L_47 , V_319 ) ;
}
if ( V_74 < V_319 )
V_74 = V_319 ;
V_75 = F_172 ( V_74 , sizeof( struct V_31 * ) ,
V_195 ) ;
if ( ! V_75 ) {
F_122 ( L_48 ) ;
V_83 = - V_137 ;
goto error;
}
V_320 = F_52 ( V_74 *
sizeof( struct V_321 ) , V_195 ) ;
if ( ! V_320 ) {
V_83 = - V_137 ;
goto V_322;
}
F_80 (iommu, drhd) {
V_75 [ V_32 -> V_184 ] = V_32 ;
F_276 ( V_32 ) ;
V_83 = F_168 ( V_32 ) ;
if ( V_83 )
goto V_323;
F_43 ( V_32 ) ;
if ( F_41 ( V_32 ) && ! F_289 () ) {
F_167 ( V_32 ) ;
F_42 ( V_32 ) ;
F_244 ( L_49 ,
V_32 -> V_136 ) ;
}
V_83 = F_121 ( V_32 ) ;
if ( V_83 )
goto V_323;
if ( F_41 ( V_32 ) ) {
F_48 ( L_50 ) ;
V_83 = F_284 ( V_32 ) ;
if ( V_83 ) {
F_122 ( L_51 ,
V_32 -> V_136 ) ;
F_167 ( V_32 ) ;
F_42 ( V_32 ) ;
} else {
F_48 ( L_52 ,
V_32 -> V_136 ) ;
V_318 = true ;
}
}
F_129 ( V_32 ) ;
F_123 ( V_32 ) ;
V_32 -> V_185 . V_228 ( V_32 , 0 , 0 , 0 , V_153 ) ;
V_32 -> V_185 . V_186 ( V_32 , 0 , 0 , 0 , V_162 ) ;
if ( ! F_290 ( V_32 -> V_81 ) )
V_223 = 0 ;
#ifdef F_147
if ( V_173 ( V_32 ) )
F_291 ( V_32 ) ;
#endif
}
if ( V_324 )
V_53 |= V_287 ;
#ifdef F_292
V_53 |= V_54 ;
#endif
if ( V_53 ) {
V_83 = F_252 ( V_223 ) ;
if ( V_83 )
goto V_323;
}
F_293 () ;
if ( V_318 )
goto V_325;
if ( V_53 ) {
V_83 = F_272 ( V_223 ) ;
if ( V_83 ) {
F_222 ( L_53 ) ;
goto V_323;
}
}
F_48 ( L_54 ) ;
F_261 (rmrr) {
F_100 (rmrr->devices, rmrr->devices_cnt,
i, dev) {
V_83 = F_248 ( V_277 , V_95 ) ;
if ( V_83 )
F_122 ( L_55 ) ;
}
}
F_249 () ;
V_325:
F_294 (iommu, drhd) {
if ( V_77 -> V_326 ) {
if ( V_327 )
F_165 ( V_32 ) ;
continue;
}
F_129 ( V_32 ) ;
#ifdef F_147
if ( V_173 ( V_32 ) && F_180 ( V_32 -> V_81 ) ) {
V_83 = F_295 ( V_32 ) ;
if ( V_83 )
goto V_323;
}
#endif
V_83 = F_296 ( V_32 ) ;
if ( V_83 )
goto V_323;
if ( ! F_41 ( V_32 ) )
F_166 ( V_32 ) ;
F_165 ( V_32 ) ;
}
return 0 ;
V_323:
F_80 (iommu, drhd) {
F_175 ( V_32 ) ;
F_179 ( V_32 ) ;
}
F_173 ( V_320 ) ;
V_322:
F_173 ( V_75 ) ;
error:
return V_83 ;
}
static struct V_203 * F_297 ( struct V_94 * V_95 ,
struct V_39 * V_42 ,
unsigned long V_328 , T_7 V_291 )
{
struct V_203 * V_203 = NULL ;
V_291 = F_3 ( T_7 , F_298 ( V_42 -> V_132 ) , V_291 ) ;
V_328 = F_161 ( V_328 ) ;
if ( ! V_47 && V_291 > F_299 ( 32 ) ) {
V_203 = F_300 ( & V_42 -> V_217 , V_328 ,
F_193 ( F_299 ( 32 ) ) , 1 ) ;
if ( V_203 )
return V_203 ;
}
V_203 = F_300 ( & V_42 -> V_217 , V_328 , F_193 ( V_291 ) , 1 ) ;
if ( F_301 ( ! V_203 ) ) {
F_122 ( L_56 ,
V_328 , F_239 ( V_95 ) ) ;
return NULL ;
}
return V_203 ;
}
static struct V_39 * F_302 ( struct V_94 * V_95 )
{
struct V_276 * V_277 ;
struct V_39 * V_42 ;
struct V_94 * V_329 ;
int V_79 , V_83 ;
V_42 = F_241 ( V_95 , V_72 ) ;
if ( ! V_42 ) {
F_122 ( L_57 ,
F_239 ( V_95 ) ) ;
return NULL ;
}
F_79 () ;
F_261 (rmrr) {
F_100 (rmrr->devices, rmrr->devices_cnt,
i, i_dev) {
if ( V_329 != V_95 )
continue;
V_83 = F_243 ( V_95 , V_42 ,
V_277 -> V_278 ,
V_277 -> V_279 ) ;
if ( V_83 )
F_303 ( V_95 , L_55 ) ;
}
}
F_81 () ;
return V_42 ;
}
static inline struct V_39 * F_304 ( struct V_94 * V_95 )
{
struct V_167 * V_168 ;
V_168 = V_95 -> V_96 . V_32 ;
if ( F_258 ( V_168 ) )
return V_168 -> V_42 ;
return F_302 ( V_95 ) ;
}
static int F_305 ( struct V_94 * V_95 )
{
int V_78 ;
if ( F_93 ( V_95 ) )
return 1 ;
if ( ! V_53 )
return 0 ;
V_78 = F_257 ( V_95 ) ;
if ( V_78 ) {
if ( F_265 ( V_95 , 0 ) )
return 1 ;
else {
F_177 ( V_271 , V_95 ) ;
F_48 ( L_58 ,
F_239 ( V_95 ) ) ;
return 0 ;
}
} else {
if ( F_265 ( V_95 , 0 ) ) {
int V_83 ;
V_83 = F_259 ( V_271 , V_95 ) ;
if ( ! V_83 ) {
F_48 ( L_59 ,
F_239 ( V_95 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_254 F_306 ( struct V_94 * V_95 , T_1 V_330 ,
T_5 V_58 , int V_331 , V_24 V_291 )
{
struct V_39 * V_42 ;
T_1 V_332 ;
struct V_203 * V_203 ;
int V_246 = 0 ;
int V_83 ;
struct V_31 * V_32 ;
unsigned long V_333 = V_330 >> V_11 ;
F_75 ( V_331 == V_334 ) ;
if ( F_305 ( V_95 ) )
return V_330 ;
V_42 = F_304 ( V_95 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_74 ( V_42 ) ;
V_58 = F_215 ( V_330 , V_58 ) ;
V_203 = F_297 ( V_95 , V_42 , F_12 ( V_58 ) , V_291 ) ;
if ( ! V_203 )
goto error;
if ( V_331 == V_335 || V_331 == V_336 || \
! F_307 ( V_32 -> V_71 ) )
V_246 |= V_122 ;
if ( V_331 == V_337 || V_331 == V_336 )
V_246 |= V_123 ;
V_83 = F_226 ( V_42 , F_13 ( V_203 -> V_338 ) ,
F_13 ( V_333 ) , V_58 , V_246 ) ;
if ( V_83 )
goto error;
if ( F_164 ( V_32 -> V_71 ) )
F_159 ( V_32 , V_42 ,
F_13 ( V_203 -> V_338 ) ,
V_58 , 0 , 1 ) ;
else
F_129 ( V_32 ) ;
V_332 = ( T_1 ) V_203 -> V_338 << V_11 ;
V_332 += V_330 & ~ V_235 ;
return V_332 ;
error:
if ( V_203 )
F_308 ( & V_42 -> V_217 , V_203 ) ;
F_122 ( L_60 ,
F_239 ( V_95 ) , V_58 , ( unsigned long long ) V_330 , V_331 ) ;
return 0 ;
}
static V_254 F_309 ( struct V_94 * V_95 , struct V_14 * V_14 ,
unsigned long V_116 , T_5 V_58 ,
enum V_339 V_331 ,
struct V_340 * V_341 )
{
return F_306 ( V_95 , F_219 ( V_14 ) + V_116 , V_58 ,
V_331 , * V_95 -> V_291 ) ;
}
static void F_310 ( void )
{
int V_79 , V_342 ;
V_343 = 0 ;
for ( V_79 = 0 ; V_79 < V_74 ; V_79 ++ ) {
struct V_31 * V_32 = V_75 [ V_79 ] ;
if ( ! V_32 )
continue;
if ( ! V_320 [ V_79 ] . V_131 )
continue;
if ( ! F_164 ( V_32 -> V_71 ) )
V_32 -> V_185 . V_186 ( V_32 , 0 , 0 , 0 ,
V_162 ) ;
for ( V_342 = 0 ; V_342 < V_320 [ V_79 ] . V_131 ; V_342 ++ ) {
unsigned long V_84 ;
struct V_203 * V_203 = V_320 [ V_79 ] . V_203 [ V_342 ] ;
struct V_39 * V_42 = V_320 [ V_79 ] . V_42 [ V_342 ] ;
if ( F_164 ( V_32 -> V_71 ) )
F_159 ( V_32 , V_42 ,
V_203 -> V_338 , F_311 ( V_203 ) ,
! V_320 [ V_79 ] . V_133 [ V_342 ] , 0 ) ;
else {
V_84 = F_160 ( F_13 ( F_311 ( V_203 ) ) ) ;
F_157 ( V_320 [ V_79 ] . V_42 [ V_342 ] ,
( T_7 ) V_203 -> V_338 << V_11 , V_84 ) ;
}
F_308 ( & V_320 [ V_79 ] . V_42 [ V_342 ] -> V_217 , V_203 ) ;
if ( V_320 [ V_79 ] . V_133 [ V_342 ] )
F_120 ( V_320 [ V_79 ] . V_133 [ V_342 ] ) ;
}
V_320 [ V_79 ] . V_131 = 0 ;
}
V_344 = 0 ;
}
static void F_201 ( unsigned long V_233 )
{
unsigned long V_33 ;
F_104 ( & V_345 , V_33 ) ;
F_310 () ;
F_105 ( & V_345 , V_33 ) ;
}
static void F_312 ( struct V_39 * V_41 , struct V_203 * V_203 , struct V_14 * V_133 )
{
unsigned long V_33 ;
int V_131 , V_73 ;
struct V_31 * V_32 ;
F_104 ( & V_345 , V_33 ) ;
if ( V_344 == V_346 )
F_310 () ;
V_32 = F_74 ( V_41 ) ;
V_73 = V_32 -> V_184 ;
V_131 = V_320 [ V_73 ] . V_131 ;
V_320 [ V_73 ] . V_42 [ V_131 ] = V_41 ;
V_320 [ V_73 ] . V_203 [ V_131 ] = V_203 ;
V_320 [ V_73 ] . V_133 [ V_131 ] = V_133 ;
V_320 [ V_73 ] . V_131 ++ ;
if ( ! V_343 ) {
F_313 ( & V_347 , V_348 + F_314 ( 10 ) ) ;
V_343 = 1 ;
}
V_344 ++ ;
F_105 ( & V_345 , V_33 ) ;
}
static void F_315 ( struct V_94 * V_95 , V_254 V_349 )
{
struct V_39 * V_42 ;
unsigned long V_126 , V_127 ;
struct V_203 * V_203 ;
struct V_31 * V_32 ;
struct V_14 * V_133 ;
if ( F_305 ( V_95 ) )
return;
V_42 = F_231 ( V_95 ) ;
F_75 ( ! V_42 ) ;
V_32 = F_74 ( V_42 ) ;
V_203 = F_316 ( & V_42 -> V_217 , F_193 ( V_349 ) ) ;
if ( F_317 ( ! V_203 , L_61 ,
( unsigned long long ) V_349 ) )
return;
V_126 = F_13 ( V_203 -> V_338 ) ;
V_127 = F_13 ( V_203 -> V_350 + 1 ) - 1 ;
F_142 ( L_62 ,
F_239 ( V_95 ) , V_126 , V_127 ) ;
V_133 = F_119 ( V_42 , V_126 , V_127 ) ;
if ( V_48 ) {
F_159 ( V_32 , V_42 , V_126 ,
V_127 - V_126 + 1 , ! V_133 , 0 ) ;
F_308 ( & V_42 -> V_217 , V_203 ) ;
F_120 ( V_133 ) ;
} else {
F_312 ( V_42 , V_203 , V_133 ) ;
}
}
static void F_318 ( struct V_94 * V_95 , V_254 V_349 ,
T_5 V_58 , enum V_339 V_331 ,
struct V_340 * V_341 )
{
F_315 ( V_95 , V_349 ) ;
}
static void * F_319 ( struct V_94 * V_95 , T_5 V_58 ,
V_254 * V_351 , T_8 V_33 ,
struct V_340 * V_341 )
{
struct V_14 * V_14 = NULL ;
int V_352 ;
V_58 = F_216 ( V_58 ) ;
V_352 = F_320 ( V_58 ) ;
if ( ! F_305 ( V_95 ) )
V_33 &= ~ ( V_353 | V_354 ) ;
else if ( V_95 -> V_292 < F_270 ( V_95 ) ) {
if ( V_95 -> V_292 < F_299 ( 32 ) )
V_33 |= V_353 ;
else
V_33 |= V_354 ;
}
if ( F_321 ( V_33 ) ) {
unsigned int V_201 = V_58 >> V_11 ;
V_14 = F_322 ( V_95 , V_201 , V_352 ) ;
if ( V_14 && F_305 ( V_95 ) &&
F_219 ( V_14 ) + V_58 > V_95 -> V_292 ) {
F_323 ( V_95 , V_14 , V_201 ) ;
V_14 = NULL ;
}
}
if ( ! V_14 )
V_14 = F_324 ( V_33 , V_352 ) ;
if ( ! V_14 )
return NULL ;
memset ( F_56 ( V_14 ) , 0 , V_58 ) ;
* V_351 = F_306 ( V_95 , F_219 ( V_14 ) , V_58 ,
V_336 ,
V_95 -> V_292 ) ;
if ( * V_351 )
return F_56 ( V_14 ) ;
if ( ! F_323 ( V_95 , V_14 , V_58 >> V_11 ) )
F_325 ( V_14 , V_352 ) ;
return NULL ;
}
static void F_326 ( struct V_94 * V_95 , T_5 V_58 , void * V_61 ,
V_254 V_351 , struct V_340 * V_341 )
{
int V_352 ;
struct V_14 * V_14 = F_17 ( V_61 ) ;
V_58 = F_216 ( V_58 ) ;
V_352 = F_320 ( V_58 ) ;
F_315 ( V_95 , V_351 ) ;
if ( ! F_323 ( V_95 , V_14 , V_58 >> V_11 ) )
F_325 ( V_14 , V_352 ) ;
}
static void F_327 ( struct V_94 * V_95 , struct V_242 * V_355 ,
int V_356 , enum V_339 V_331 ,
struct V_340 * V_341 )
{
F_315 ( V_95 , V_355 [ 0 ] . V_253 ) ;
}
static int F_328 ( struct V_94 * V_357 ,
struct V_242 * V_355 , int V_356 , int V_331 )
{
int V_79 ;
struct V_242 * V_243 ;
F_329 (sglist, sg, nelems, i) {
F_75 ( ! F_220 ( V_243 ) ) ;
V_243 -> V_253 = F_219 ( F_220 ( V_243 ) ) + V_243 -> V_116 ;
V_243 -> V_255 = V_243 -> V_252 ;
}
return V_356 ;
}
static int F_330 ( struct V_94 * V_95 , struct V_242 * V_355 , int V_356 ,
enum V_339 V_331 , struct V_340 * V_341 )
{
int V_79 ;
struct V_39 * V_42 ;
T_5 V_58 = 0 ;
int V_246 = 0 ;
struct V_203 * V_203 = NULL ;
int V_83 ;
struct V_242 * V_243 ;
unsigned long V_358 ;
struct V_31 * V_32 ;
F_75 ( V_331 == V_334 ) ;
if ( F_305 ( V_95 ) )
return F_328 ( V_95 , V_355 , V_356 , V_331 ) ;
V_42 = F_304 ( V_95 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_74 ( V_42 ) ;
F_329 (sglist, sg, nelems, i)
V_58 += F_215 ( V_243 -> V_116 , V_243 -> V_252 ) ;
V_203 = F_297 ( V_95 , V_42 , F_12 ( V_58 ) ,
* V_95 -> V_291 ) ;
if ( ! V_203 ) {
V_355 -> V_255 = 0 ;
return 0 ;
}
if ( V_331 == V_335 || V_331 == V_336 || \
! F_307 ( V_32 -> V_71 ) )
V_246 |= V_122 ;
if ( V_331 == V_337 || V_331 == V_336 )
V_246 |= V_123 ;
V_358 = F_13 ( V_203 -> V_338 ) ;
V_83 = F_225 ( V_42 , V_358 , V_355 , V_58 , V_246 ) ;
if ( F_301 ( V_83 ) ) {
F_114 ( V_42 , V_358 ,
V_358 + V_58 - 1 ) ;
F_308 ( & V_42 -> V_217 , V_203 ) ;
return 0 ;
}
if ( F_164 ( V_32 -> V_71 ) )
F_159 ( V_32 , V_42 , V_358 , V_58 , 0 , 1 ) ;
else
F_129 ( V_32 ) ;
return V_356 ;
}
static int F_331 ( struct V_94 * V_95 , V_254 V_359 )
{
return ! V_359 ;
}
static inline int F_332 ( void )
{
int V_83 = 0 ;
V_63 = F_333 ( L_63 ,
sizeof( struct V_39 ) ,
0 ,
V_360 ,
NULL ) ;
if ( ! V_63 ) {
F_122 ( L_64 ) ;
V_83 = - V_137 ;
}
return V_83 ;
}
static inline int F_334 ( void )
{
int V_83 = 0 ;
V_64 = F_333 ( L_65 ,
sizeof( struct V_167 ) ,
0 ,
V_360 ,
NULL ) ;
if ( ! V_64 ) {
F_122 ( L_66 ) ;
V_83 = - V_137 ;
}
return V_83 ;
}
static int T_3 F_335 ( void )
{
int V_83 ;
V_83 = F_336 () ;
if ( V_83 )
return V_83 ;
V_83 = F_332 () ;
if ( V_83 )
goto V_361;
V_83 = F_334 () ;
if ( ! V_83 )
return V_83 ;
F_337 ( V_63 ) ;
V_361:
F_338 () ;
return - V_137 ;
}
static void T_3 F_339 ( void )
{
F_337 ( V_64 ) ;
F_337 ( V_63 ) ;
F_338 () ;
}
static void F_340 ( struct V_99 * V_101 )
{
struct V_76 * V_77 ;
T_2 V_362 ;
int V_363 ;
V_363 = F_341 ( V_101 -> V_87 , F_342 ( 0 , 0 ) , 0xb0 , & V_362 ) ;
if ( V_363 ) {
F_343 ( & V_101 -> V_95 , L_67 ) ;
return;
}
V_362 &= 0xffff0000 ;
V_77 = F_344 ( V_101 ) ;
if ( F_345 ( ! V_77 || V_77 -> V_364 - V_362 != 0xa000 ,
V_365 ,
L_68 ) )
V_101 -> V_95 . V_96 . V_32 = V_97 ;
}
static void T_3 F_346 ( void )
{
struct V_76 * V_77 ;
struct V_94 * V_95 ;
int V_79 ;
F_287 (drhd) {
if ( ! V_77 -> V_110 ) {
F_100 (drhd->devices,
drhd->devices_cnt, i, dev)
break;
if ( V_79 == V_77 -> V_366 )
V_77 -> V_326 = 1 ;
}
}
F_347 (drhd) {
if ( V_77 -> V_110 )
continue;
F_100 (drhd->devices,
drhd->devices_cnt, i, dev)
if ( ! F_95 ( V_95 ) || ! F_264 ( F_96 ( V_95 ) ) )
break;
if ( V_79 < V_77 -> V_366 )
continue;
if ( V_46 ) {
V_367 = 1 ;
} else {
V_77 -> V_326 = 1 ;
F_100 (drhd->devices,
drhd->devices_cnt, i, dev)
V_95 -> V_96 . V_32 = V_97 ;
}
}
}
static int F_348 ( void )
{
struct V_76 * V_77 ;
struct V_31 * V_32 = NULL ;
F_80 (iommu, drhd)
if ( V_32 -> V_170 )
F_349 ( V_32 ) ;
F_294 (iommu, drhd) {
if ( V_77 -> V_326 ) {
if ( V_327 )
F_165 ( V_32 ) ;
continue;
}
F_129 ( V_32 ) ;
F_123 ( V_32 ) ;
V_32 -> V_185 . V_228 ( V_32 , 0 , 0 , 0 ,
V_153 ) ;
V_32 -> V_185 . V_186 ( V_32 , 0 , 0 , 0 , V_162 ) ;
F_166 ( V_32 ) ;
F_165 ( V_32 ) ;
}
return 0 ;
}
static void F_350 ( void )
{
struct V_76 * V_77 ;
struct V_31 * V_32 ;
F_80 (iommu, drhd) {
V_32 -> V_185 . V_228 ( V_32 , 0 , 0 , 0 ,
V_153 ) ;
V_32 -> V_185 . V_186 ( V_32 , 0 , 0 , 0 ,
V_162 ) ;
}
}
static int F_351 ( void )
{
struct V_76 * V_77 ;
struct V_31 * V_32 = NULL ;
unsigned long V_140 ;
F_80 (iommu, drhd) {
V_32 -> V_368 = F_52 ( sizeof( T_2 ) * V_369 ,
V_59 ) ;
if ( ! V_32 -> V_368 )
goto V_370;
}
F_350 () ;
F_80 (iommu, drhd) {
F_167 ( V_32 ) ;
F_124 ( & V_32 -> V_142 , V_140 ) ;
V_32 -> V_368 [ V_371 ] =
F_44 ( V_32 -> V_36 + V_372 ) ;
V_32 -> V_368 [ V_373 ] =
F_44 ( V_32 -> V_36 + V_374 ) ;
V_32 -> V_368 [ V_375 ] =
F_44 ( V_32 -> V_36 + V_376 ) ;
V_32 -> V_368 [ V_377 ] =
F_44 ( V_32 -> V_36 + V_378 ) ;
F_128 ( & V_32 -> V_142 , V_140 ) ;
}
return 0 ;
V_370:
F_80 (iommu, drhd)
F_173 ( V_32 -> V_368 ) ;
return - V_137 ;
}
static void F_352 ( void )
{
struct V_76 * V_77 ;
struct V_31 * V_32 = NULL ;
unsigned long V_140 ;
if ( F_348 () ) {
if ( V_327 )
F_353 ( L_69 ) ;
else
F_245 ( 1 , L_70 ) ;
return;
}
F_80 (iommu, drhd) {
F_124 ( & V_32 -> V_142 , V_140 ) ;
F_126 ( V_32 -> V_368 [ V_371 ] ,
V_32 -> V_36 + V_372 ) ;
F_126 ( V_32 -> V_368 [ V_373 ] ,
V_32 -> V_36 + V_374 ) ;
F_126 ( V_32 -> V_368 [ V_375 ] ,
V_32 -> V_36 + V_376 ) ;
F_126 ( V_32 -> V_368 [ V_377 ] ,
V_32 -> V_36 + V_378 ) ;
F_128 ( & V_32 -> V_142 , V_140 ) ;
}
F_80 (iommu, drhd)
F_173 ( V_32 -> V_368 ) ;
}
static void T_3 F_354 ( void )
{
F_355 ( & V_379 ) ;
}
static inline void F_354 ( void ) {}
int T_3 F_356 ( struct V_380 * V_381 , void * V_382 )
{
struct V_383 * V_277 ;
struct V_276 * V_384 ;
V_384 = F_52 ( sizeof( * V_384 ) , V_195 ) ;
if ( ! V_384 )
return - V_137 ;
V_384 -> V_385 = V_381 ;
V_277 = (struct V_383 * ) V_381 ;
V_384 -> V_278 = V_277 -> V_278 ;
V_384 -> V_279 = V_277 -> V_279 ;
V_384 -> V_103 = F_357 ( ( void * ) ( V_277 + 1 ) ,
( ( void * ) V_277 ) + V_277 -> V_381 . V_252 ,
& V_384 -> V_366 ) ;
if ( V_384 -> V_366 && V_384 -> V_103 == NULL ) {
F_173 ( V_384 ) ;
return - V_137 ;
}
F_238 ( & V_384 -> V_386 , & V_387 ) ;
return 0 ;
}
static struct V_388 * F_358 ( struct V_389 * V_390 )
{
struct V_388 * V_391 ;
struct V_389 * V_98 ;
F_359 (atsru, &dmar_atsr_units, list) {
V_98 = (struct V_389 * ) V_391 -> V_385 ;
if ( V_390 -> V_102 != V_98 -> V_102 )
continue;
if ( V_390 -> V_381 . V_252 != V_98 -> V_381 . V_252 )
continue;
if ( memcmp ( V_390 , V_98 , V_390 -> V_381 . V_252 ) == 0 )
return V_391 ;
}
return NULL ;
}
int F_360 ( struct V_380 * V_385 , void * V_382 )
{
struct V_389 * V_390 ;
struct V_388 * V_391 ;
if ( V_392 != V_393 && ! V_394 )
return 0 ;
V_390 = F_46 ( V_385 , struct V_389 , V_381 ) ;
V_391 = F_358 ( V_390 ) ;
if ( V_391 )
return 0 ;
V_391 = F_52 ( sizeof( * V_391 ) + V_385 -> V_252 , V_195 ) ;
if ( ! V_391 )
return - V_137 ;
V_391 -> V_385 = ( void * ) ( V_391 + 1 ) ;
memcpy ( V_391 -> V_385 , V_385 , V_385 -> V_252 ) ;
V_391 -> V_110 = V_390 -> V_33 & 0x1 ;
if ( ! V_391 -> V_110 ) {
V_391 -> V_103 = F_357 ( ( void * ) ( V_390 + 1 ) ,
( void * ) V_390 + V_390 -> V_381 . V_252 ,
& V_391 -> V_366 ) ;
if ( V_391 -> V_366 && V_391 -> V_103 == NULL ) {
F_173 ( V_391 ) ;
return - V_137 ;
}
}
F_361 ( & V_391 -> V_386 , & V_395 ) ;
return 0 ;
}
static void F_362 ( struct V_388 * V_391 )
{
F_363 ( & V_391 -> V_103 , & V_391 -> V_366 ) ;
F_173 ( V_391 ) ;
}
int F_364 ( struct V_380 * V_385 , void * V_382 )
{
struct V_389 * V_390 ;
struct V_388 * V_391 ;
V_390 = F_46 ( V_385 , struct V_389 , V_381 ) ;
V_391 = F_358 ( V_390 ) ;
if ( V_391 ) {
F_365 ( & V_391 -> V_386 ) ;
F_366 () ;
F_362 ( V_391 ) ;
}
return 0 ;
}
int F_367 ( struct V_380 * V_385 , void * V_382 )
{
int V_79 ;
struct V_94 * V_95 ;
struct V_389 * V_390 ;
struct V_388 * V_391 ;
V_390 = F_46 ( V_385 , struct V_389 , V_381 ) ;
V_391 = F_358 ( V_390 ) ;
if ( ! V_391 )
return 0 ;
if ( ! V_391 -> V_110 && V_391 -> V_103 && V_391 -> V_366 )
F_100 (atsru->devices, atsru->devices_cnt,
i, dev)
return - V_284 ;
return 0 ;
}
static int F_368 ( struct V_76 * V_396 )
{
int V_397 , V_83 = 0 ;
struct V_31 * V_32 = V_396 -> V_32 ;
if ( V_75 [ V_32 -> V_184 ] )
return 0 ;
if ( V_223 && ! F_290 ( V_32 -> V_81 ) ) {
F_244 ( L_71 ,
V_32 -> V_136 ) ;
return - V_398 ;
}
if ( ! F_83 ( V_32 -> V_81 ) &&
F_82 ( V_32 ) ) {
F_244 ( L_72 ,
V_32 -> V_136 ) ;
return - V_398 ;
}
V_397 = F_84 ( V_32 ) - 1 ;
if ( V_397 >= 0 && ! ( F_85 ( V_32 -> V_71 ) & ( 1 << V_397 ) ) ) {
F_244 ( L_73 ,
V_32 -> V_136 ) ;
return - V_398 ;
}
if ( V_32 -> V_144 & V_191 )
F_167 ( V_32 ) ;
V_75 [ V_32 -> V_184 ] = V_32 ;
V_83 = F_168 ( V_32 ) ;
if ( V_83 == 0 )
V_83 = F_121 ( V_32 ) ;
if ( V_83 )
goto V_104;
#ifdef F_147
if ( V_173 ( V_32 ) )
F_291 ( V_32 ) ;
#endif
if ( V_396 -> V_326 ) {
if ( V_327 )
F_165 ( V_32 ) ;
return 0 ;
}
F_276 ( V_32 ) ;
F_129 ( V_32 ) ;
#ifdef F_147
if ( V_173 ( V_32 ) && F_180 ( V_32 -> V_81 ) ) {
V_83 = F_295 ( V_32 ) ;
if ( V_83 )
goto V_399;
}
#endif
V_83 = F_296 ( V_32 ) ;
if ( V_83 )
goto V_399;
F_123 ( V_32 ) ;
V_32 -> V_185 . V_228 ( V_32 , 0 , 0 , 0 , V_153 ) ;
V_32 -> V_185 . V_186 ( V_32 , 0 , 0 , 0 , V_162 ) ;
F_166 ( V_32 ) ;
F_165 ( V_32 ) ;
return 0 ;
V_399:
F_175 ( V_32 ) ;
V_104:
F_179 ( V_32 ) ;
return V_83 ;
}
int F_369 ( struct V_76 * V_396 , bool V_400 )
{
int V_83 = 0 ;
struct V_31 * V_32 = V_396 -> V_32 ;
if ( ! V_394 )
return 0 ;
if ( V_32 == NULL )
return - V_44 ;
if ( V_400 ) {
V_83 = F_368 ( V_396 ) ;
} else {
F_175 ( V_32 ) ;
F_179 ( V_32 ) ;
}
return V_83 ;
}
static void F_370 ( void )
{
struct V_276 * V_384 , * V_401 ;
struct V_388 * V_391 , * V_402 ;
F_176 (rmrru, rmrr_n, &dmar_rmrr_units, list) {
F_229 ( & V_384 -> V_386 ) ;
F_363 ( & V_384 -> V_103 , & V_384 -> V_366 ) ;
F_173 ( V_384 ) ;
}
F_176 (atsru, atsr_n, &dmar_atsr_units, list) {
F_229 ( & V_391 -> V_386 ) ;
F_362 ( V_391 ) ;
}
}
int F_236 ( struct V_99 * V_95 )
{
int V_79 , V_83 = 1 ;
struct V_403 * V_87 ;
struct V_99 * V_404 = NULL ;
struct V_94 * V_98 ;
struct V_389 * V_390 ;
struct V_388 * V_391 ;
V_95 = F_371 ( V_95 ) ;
for ( V_87 = V_95 -> V_87 ; V_87 ; V_87 = V_87 -> V_115 ) {
V_404 = V_87 -> V_405 ;
if ( ! V_404 )
return 1 ;
if ( ! F_267 ( V_404 ) ||
F_269 ( V_404 ) == V_290 )
return 0 ;
if ( F_269 ( V_404 ) == V_406 )
break;
}
F_79 () ;
F_359 (atsru, &dmar_atsr_units, list) {
V_390 = F_46 ( V_391 -> V_385 , struct V_389 , V_381 ) ;
if ( V_390 -> V_102 != F_97 ( V_95 -> V_87 ) )
continue;
F_372 (atsru->devices, atsru->devices_cnt, i, tmp)
if ( V_98 == & V_404 -> V_95 )
goto V_104;
if ( V_391 -> V_110 )
goto V_104;
}
V_83 = 0 ;
V_104:
F_81 () ;
return V_83 ;
}
int F_373 ( struct V_407 * V_168 )
{
int V_83 = 0 ;
struct V_276 * V_384 ;
struct V_388 * V_391 ;
struct V_389 * V_390 ;
struct V_383 * V_277 ;
if ( ! V_394 && V_392 != V_393 )
return 0 ;
F_145 (rmrru, &dmar_rmrr_units, list) {
V_277 = F_46 ( V_384 -> V_385 ,
struct V_383 , V_381 ) ;
if ( V_168 -> V_408 == V_409 ) {
V_83 = F_374 ( V_168 , ( void * ) ( V_277 + 1 ) ,
( ( void * ) V_277 ) + V_277 -> V_381 . V_252 ,
V_277 -> V_102 , V_384 -> V_103 ,
V_384 -> V_366 ) ;
if( V_83 < 0 )
return V_83 ;
} else if ( V_168 -> V_408 == V_410 ) {
F_375 ( V_168 , V_277 -> V_102 ,
V_384 -> V_103 , V_384 -> V_366 ) ;
}
}
F_145 (atsru, &dmar_atsr_units, list) {
if ( V_391 -> V_110 )
continue;
V_390 = F_46 ( V_391 -> V_385 , struct V_389 , V_381 ) ;
if ( V_168 -> V_408 == V_409 ) {
V_83 = F_374 ( V_168 , ( void * ) ( V_390 + 1 ) ,
( void * ) V_390 + V_390 -> V_381 . V_252 ,
V_390 -> V_102 , V_391 -> V_103 ,
V_391 -> V_366 ) ;
if ( V_83 > 0 )
break;
else if( V_83 < 0 )
return V_83 ;
} else if ( V_168 -> V_408 == V_410 ) {
if ( F_375 ( V_168 , V_390 -> V_102 ,
V_391 -> V_103 , V_391 -> V_366 ) )
break;
}
}
return 0 ;
}
static int F_376 ( struct V_411 * V_412 ,
unsigned long V_413 , void * V_233 )
{
struct V_94 * V_95 = V_233 ;
struct V_39 * V_42 ;
if ( F_93 ( V_95 ) )
return 0 ;
if ( V_413 != V_414 )
return 0 ;
V_42 = F_231 ( V_95 ) ;
if ( ! V_42 )
return 0 ;
F_177 ( V_42 , V_95 ) ;
if ( ! F_67 ( V_42 ) && F_377 ( & V_42 -> V_103 ) )
F_178 ( V_42 ) ;
return 0 ;
}
static int F_378 ( struct V_411 * V_412 ,
unsigned long V_29 , void * V_415 )
{
struct V_416 * V_417 = V_415 ;
unsigned long long V_216 , V_108 ;
unsigned long V_358 , V_270 ;
switch ( V_29 ) {
case V_418 :
V_216 = V_417 -> V_126 << V_11 ;
V_108 = ( ( V_417 -> V_126 + V_417 -> V_245 ) << V_11 ) - 1 ;
if ( F_242 ( V_271 , V_216 , V_108 ) ) {
F_244 ( L_74 ,
V_216 , V_108 ) ;
return V_419 ;
}
break;
case V_420 :
case V_421 :
V_358 = F_13 ( V_417 -> V_126 ) ;
V_270 = F_13 ( V_417 -> V_126 + V_417 -> V_245 - 1 ) ;
while ( V_358 <= V_270 ) {
struct V_203 * V_203 ;
struct V_76 * V_77 ;
struct V_31 * V_32 ;
struct V_14 * V_133 ;
V_203 = F_316 ( & V_271 -> V_217 , V_358 ) ;
if ( V_203 == NULL ) {
F_142 ( L_75 ,
V_358 ) ;
break;
}
V_203 = F_379 ( & V_271 -> V_217 , V_203 ,
V_358 , V_270 ) ;
if ( V_203 == NULL ) {
F_244 ( L_76 ,
V_358 , V_270 ) ;
return V_419 ;
}
V_133 = F_119 ( V_271 , V_203 -> V_338 ,
V_203 -> V_350 ) ;
F_79 () ;
F_80 (iommu, drhd)
F_159 ( V_32 , V_271 ,
V_203 -> V_338 , F_311 ( V_203 ) ,
! V_133 , 0 ) ;
F_81 () ;
F_120 ( V_133 ) ;
V_358 = V_203 -> V_350 + 1 ;
F_380 ( V_203 ) ;
}
break;
}
return V_422 ;
}
static T_9 F_381 ( struct V_94 * V_95 ,
struct V_423 * V_424 ,
char * V_425 )
{
struct V_31 * V_32 = F_382 ( V_95 ) ;
T_2 V_426 = F_44 ( V_32 -> V_36 + V_427 ) ;
return sprintf ( V_425 , L_77 ,
F_383 ( V_426 ) , F_384 ( V_426 ) ) ;
}
static T_9 F_385 ( struct V_94 * V_95 ,
struct V_423 * V_424 ,
char * V_425 )
{
struct V_31 * V_32 = F_382 ( V_95 ) ;
return sprintf ( V_425 , L_78 , V_32 -> V_428 ) ;
}
static T_9 F_386 ( struct V_94 * V_95 ,
struct V_423 * V_424 ,
char * V_425 )
{
struct V_31 * V_32 = F_382 ( V_95 ) ;
return sprintf ( V_425 , L_78 , V_32 -> V_71 ) ;
}
static T_9 F_387 ( struct V_94 * V_95 ,
struct V_423 * V_424 ,
char * V_425 )
{
struct V_31 * V_32 = F_382 ( V_95 ) ;
return sprintf ( V_425 , L_78 , V_32 -> V_81 ) ;
}
static T_9 F_388 ( struct V_94 * V_95 ,
struct V_423 * V_424 ,
char * V_425 )
{
struct V_31 * V_32 = F_382 ( V_95 ) ;
return sprintf ( V_425 , L_79 , F_169 ( V_32 -> V_71 ) ) ;
}
static T_9 F_389 ( struct V_94 * V_95 ,
struct V_423 * V_424 ,
char * V_425 )
{
struct V_31 * V_32 = F_382 ( V_95 ) ;
return sprintf ( V_425 , L_80 , F_390 ( V_32 -> V_194 ,
F_169 ( V_32 -> V_71 ) ) ) ;
}
int T_3 F_391 ( void )
{
int V_83 = - V_211 ;
struct V_76 * V_77 ;
struct V_31 * V_32 ;
V_327 = F_392 () ;
if ( F_335 () ) {
if ( V_327 )
F_353 ( L_81 ) ;
return - V_137 ;
}
F_393 ( & V_429 ) ;
if ( F_394 () ) {
if ( V_327 )
F_353 ( L_82 ) ;
goto V_430;
}
if ( F_395 () < 0 ) {
if ( V_327 )
F_353 ( L_83 ) ;
goto V_430;
}
if ( V_431 || V_45 )
goto V_430;
if ( F_377 ( & V_387 ) )
F_48 ( L_84 ) ;
if ( F_377 ( & V_395 ) )
F_48 ( L_85 ) ;
if ( F_189 () ) {
if ( V_327 )
F_353 ( L_86 ) ;
goto V_432;
}
F_346 () ;
V_83 = F_286 () ;
if ( V_83 ) {
if ( V_327 )
F_353 ( L_87 ) ;
F_122 ( L_88 ) ;
goto V_432;
}
F_396 ( & V_429 ) ;
F_48 ( L_89 ) ;
F_397 ( & V_347 ) ;
#ifdef F_398
V_433 = 0 ;
#endif
V_434 = & V_435 ;
F_354 () ;
F_80 (iommu, drhd)
V_32 -> V_436 = F_399 ( NULL , V_32 ,
V_437 ,
L_90 , V_32 -> V_136 ) ;
F_400 ( & V_438 , & V_439 ) ;
F_401 ( & V_438 , & V_440 ) ;
if ( V_271 && ! V_223 )
F_402 ( & V_441 ) ;
V_394 = 1 ;
return 0 ;
V_432:
F_203 ( & V_204 ) ;
V_430:
F_370 () ;
F_396 ( & V_429 ) ;
F_339 () ;
return V_83 ;
}
static int F_403 ( struct V_99 * V_101 , T_4 V_230 , void * V_231 )
{
struct V_31 * V_32 = V_231 ;
F_227 ( V_32 , F_210 ( V_230 ) , V_230 & 0xff ) ;
return 0 ;
}
static void F_404 ( struct V_31 * V_32 , struct V_94 * V_95 )
{
if ( ! V_32 || ! V_95 || ! F_95 ( V_95 ) )
return;
F_212 ( F_96 ( V_95 ) , & F_403 , V_32 ) ;
}
static void F_230 ( struct V_167 * V_168 )
{
struct V_31 * V_32 ;
unsigned long V_33 ;
F_144 ( & V_169 ) ;
if ( F_53 ( ! V_168 ) )
return;
V_32 = V_168 -> V_32 ;
if ( V_168 -> V_95 ) {
F_153 ( V_168 ) ;
F_404 ( V_32 , V_168 -> V_95 ) ;
}
F_228 ( V_168 ) ;
F_104 ( & V_32 -> V_112 , V_33 ) ;
F_187 ( V_168 -> V_42 , V_32 ) ;
F_105 ( & V_32 -> V_112 , V_33 ) ;
F_64 ( V_168 ) ;
}
static void F_177 ( struct V_39 * V_42 ,
struct V_94 * V_95 )
{
struct V_167 * V_168 ;
unsigned long V_33 ;
F_104 ( & V_169 , V_33 ) ;
V_168 = V_95 -> V_96 . V_32 ;
F_230 ( V_168 ) ;
F_105 ( & V_169 , V_33 ) ;
}
static int F_253 ( struct V_39 * V_42 , int V_218 )
{
int V_219 ;
F_190 ( & V_42 -> V_217 , V_121 , V_205 ,
V_206 ) ;
F_195 ( V_42 ) ;
V_42 -> V_132 = V_218 ;
V_219 = F_197 ( V_218 ) ;
V_42 -> V_1 = F_4 ( V_219 ) ;
V_42 -> V_80 = 0 ;
V_42 -> V_85 = 0 ;
V_42 -> V_86 = 0 ;
V_42 -> V_442 = 0 ;
V_42 -> V_117 = (struct V_27 * ) F_54 ( V_42 -> V_120 ) ;
if ( ! V_42 -> V_117 )
return - V_137 ;
F_101 ( V_42 , V_42 -> V_117 , V_220 ) ;
return 0 ;
}
static struct V_40 * F_405 ( unsigned type )
{
struct V_39 * V_39 ;
struct V_40 * V_42 ;
if ( type != V_443 )
return NULL ;
V_39 = F_183 ( V_65 ) ;
if ( ! V_39 ) {
F_122 ( L_91 ) ;
return NULL ;
}
if ( F_253 ( V_39 , V_72 ) ) {
F_122 ( L_92 ) ;
F_178 ( V_39 ) ;
return NULL ;
}
F_87 ( V_39 ) ;
V_42 = & V_39 -> V_42 ;
V_42 -> V_444 . V_445 = 0 ;
V_42 -> V_444 . V_446 = F_406 ( V_39 -> V_132 ) ;
V_42 -> V_444 . V_447 = true ;
return V_42 ;
}
static void F_407 ( struct V_40 * V_42 )
{
F_178 ( F_45 ( V_42 ) ) ;
}
static int F_408 ( struct V_40 * V_42 ,
struct V_94 * V_95 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_31 * V_32 ;
int V_67 ;
T_6 V_87 , V_88 ;
if ( F_262 ( V_95 ) ) {
F_409 ( V_95 , L_93 ) ;
return - V_448 ;
}
if ( F_301 ( F_214 ( V_95 ) ) ) {
struct V_39 * V_449 ;
V_449 = F_231 ( V_95 ) ;
if ( V_449 ) {
F_79 () ;
F_177 ( V_449 , V_95 ) ;
F_81 () ;
if ( ! F_67 ( V_449 ) &&
F_377 ( & V_449 -> V_103 ) )
F_178 ( V_449 ) ;
}
}
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_211 ;
V_67 = F_2 ( V_32 -> V_1 ) ;
if ( V_67 > F_199 ( V_32 -> V_71 ) )
V_67 = F_199 ( V_32 -> V_71 ) ;
if ( V_39 -> V_442 > ( 1LL << V_67 ) ) {
F_122 ( L_94
L_95 ,
V_450 , V_67 , V_39 -> V_442 ) ;
return - V_282 ;
}
V_39 -> V_132 = V_67 ;
while ( V_32 -> V_1 < V_39 -> V_1 ) {
struct V_27 * V_28 ;
V_28 = V_39 -> V_117 ;
if ( F_38 ( V_28 ) ) {
V_39 -> V_117 = (struct V_27 * )
F_90 ( F_35 ( V_28 ) ) ;
F_57 ( V_28 ) ;
}
V_39 -> V_1 -- ;
}
return F_259 ( V_39 , V_95 ) ;
}
static void F_410 ( struct V_40 * V_42 ,
struct V_94 * V_95 )
{
F_177 ( F_45 ( V_42 ) , V_95 ) ;
}
static int F_411 ( struct V_40 * V_42 ,
unsigned long V_203 , T_1 V_451 ,
T_5 V_58 , int V_452 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
V_24 V_442 ;
int V_246 = 0 ;
int V_83 ;
if ( V_452 & V_453 )
V_246 |= V_122 ;
if ( V_452 & V_454 )
V_246 |= V_123 ;
if ( ( V_452 & V_455 ) && V_39 -> V_85 )
V_246 |= V_251 ;
V_442 = V_203 + V_58 ;
if ( V_39 -> V_442 < V_442 ) {
V_24 V_108 ;
V_108 = F_406 ( V_39 -> V_132 ) + 1 ;
if ( V_108 < V_442 ) {
F_122 ( L_94
L_95 ,
V_450 , V_39 -> V_132 , V_442 ) ;
return - V_282 ;
}
V_39 -> V_442 = V_442 ;
}
V_58 = F_215 ( V_451 , V_58 ) ;
V_83 = F_226 ( V_39 , V_203 >> V_12 ,
V_451 >> V_12 , V_58 , V_246 ) ;
return V_83 ;
}
static T_5 F_412 ( struct V_40 * V_42 ,
unsigned long V_203 , T_5 V_58 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_14 * V_133 = NULL ;
struct V_31 * V_32 ;
unsigned long V_126 , V_127 ;
unsigned int V_456 ;
int V_73 , V_5 = 0 ;
F_75 ( ! F_108 ( V_39 , V_203 >> V_12 , & V_5 ) ) ;
if ( V_58 < V_121 << F_6 ( V_5 ) )
V_58 = V_121 << F_6 ( V_5 ) ;
V_126 = V_203 >> V_12 ;
V_127 = ( V_203 + V_58 - 1 ) >> V_12 ;
V_133 = F_119 ( V_39 , V_126 , V_127 ) ;
V_456 = V_127 - V_126 + 1 ;
F_76 (iommu_id, dmar_domain) {
V_32 = V_75 [ V_73 ] ;
F_159 ( V_75 [ V_73 ] , V_39 ,
V_126 , V_456 , ! V_133 , 0 ) ;
}
F_120 ( V_133 ) ;
if ( V_39 -> V_442 == V_203 + V_58 )
V_39 -> V_442 = V_203 ;
return V_58 ;
}
static T_1 F_413 ( struct V_40 * V_42 ,
V_254 V_203 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_27 * V_28 ;
int V_5 = 0 ;
V_24 V_457 = 0 ;
V_28 = F_108 ( V_39 , V_203 >> V_12 , & V_5 ) ;
if ( V_28 )
V_457 = F_35 ( V_28 ) ;
return V_457 ;
}
static bool F_414 ( enum V_458 V_71 )
{
if ( V_71 == V_459 )
return F_82 ( NULL ) == 1 ;
if ( V_71 == V_460 )
return V_461 == 1 ;
return false ;
}
static int F_415 ( struct V_94 * V_95 )
{
struct V_31 * V_32 ;
struct V_462 * V_463 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_211 ;
F_416 ( V_32 -> V_436 , V_95 ) ;
V_463 = F_417 ( V_95 ) ;
if ( F_418 ( V_463 ) )
return F_419 ( V_463 ) ;
F_420 ( V_463 ) ;
return 0 ;
}
static void F_421 ( struct V_94 * V_95 )
{
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return;
F_422 ( V_95 ) ;
F_423 ( V_32 -> V_436 , V_95 ) ;
}
int F_424 ( struct V_31 * V_32 , struct V_464 * V_465 )
{
struct V_167 * V_168 ;
struct V_22 * V_23 ;
struct V_39 * V_42 ;
unsigned long V_33 ;
V_24 V_466 ;
int V_83 ;
V_42 = F_304 ( V_465 -> V_95 ) ;
if ( ! V_42 )
return - V_44 ;
F_104 ( & V_169 , V_33 ) ;
F_207 ( & V_32 -> V_112 ) ;
V_83 = - V_44 ;
V_168 = V_465 -> V_95 -> V_96 . V_32 ;
if ( ! V_168 || ! V_168 -> V_172 )
goto V_104;
V_23 = F_88 ( V_32 , V_168 -> V_87 , V_168 -> V_88 , 0 ) ;
if ( F_53 ( ! V_23 ) )
goto V_104;
V_466 = V_23 [ 0 ] . V_19 ;
V_465 -> V_55 = V_42 -> V_183 [ V_32 -> V_184 ] ;
V_465 -> V_178 = F_425 ( V_168 -> V_87 , V_168 -> V_88 ) ;
if ( ! ( V_466 & V_467 ) ) {
V_23 [ 1 ] . V_21 = ( V_24 ) F_92 ( V_32 -> V_468 ) ;
V_23 [ 1 ] . V_19 = ( V_24 ) F_92 ( V_32 -> V_469 ) | F_426 ( V_32 -> V_81 ) ;
F_427 () ;
if ( ( V_466 & V_470 ) == ( V_224 << 2 ) ) {
V_466 &= ~ V_470 ;
if ( V_168 -> V_171 )
V_466 |= V_471 << 2 ;
else
V_466 |= V_472 << 2 ;
}
V_466 |= V_467 ;
if ( V_32 -> V_468 )
V_466 |= V_473 ;
if ( V_168 -> V_174 )
V_466 |= V_474 ;
V_23 [ 0 ] . V_19 = V_466 ;
F_427 () ;
V_32 -> V_185 . V_228 ( V_32 , V_465 -> V_55 , V_465 -> V_178 ,
V_229 ,
V_155 ) ;
}
if ( ! V_168 -> V_173 )
F_146 ( V_168 ) ;
if ( V_168 -> V_176 ) {
V_465 -> V_475 = 1 ;
V_465 -> V_179 = V_168 -> V_177 ;
if ( V_465 -> V_179 >= V_476 )
V_465 -> V_179 = 0 ;
}
V_83 = 0 ;
V_104:
F_208 ( & V_32 -> V_112 ) ;
F_105 ( & V_169 , V_33 ) ;
return V_83 ;
}
struct V_31 * F_428 ( struct V_94 * V_95 )
{
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
if ( F_93 ( V_95 ) ) {
F_409 ( V_95 ,
L_96 ) ;
return NULL ;
}
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ( ! V_32 ) ) {
F_303 ( V_95 , L_97 ) ;
return NULL ;
}
if ( ! V_32 -> V_469 ) {
F_303 ( V_95 , L_98 ) ;
return NULL ;
}
return V_32 ;
}
static void F_429 ( struct V_99 * V_95 )
{
F_48 ( L_99 ) ;
V_46 = 0 ;
}
static void F_430 ( struct V_99 * V_95 )
{
F_48 ( L_100 ) ;
V_148 = 1 ;
}
static void F_431 ( struct V_99 * V_95 )
{
unsigned short V_477 ;
if ( F_432 ( V_95 , V_478 , & V_477 ) )
return;
if ( ! ( V_477 & V_479 ) ) {
F_48 ( L_101 ) ;
V_46 = 0 ;
} else if ( V_46 ) {
F_48 ( L_102 ) ;
V_48 = 1 ;
}
}
static void T_3 F_293 ( void )
{
struct V_99 * V_101 ;
T_10 V_480 ;
V_101 = F_433 ( V_481 , 0x3a3e , NULL ) ;
if ( ! V_101 )
return;
F_251 ( V_101 ) ;
V_101 = F_433 ( V_481 , 0x342e , NULL ) ;
if ( ! V_101 )
return;
if ( F_434 ( V_101 , 0x188 , & V_480 ) ) {
F_251 ( V_101 ) ;
return;
}
F_251 ( V_101 ) ;
if ( V_480 & 1 )
return;
V_480 &= 0x1c ;
if ( V_480 == 0x10 )
return;
if ( ! V_480 ) {
F_245 ( 1 , L_103
L_36 ,
F_246 ( V_272 ) ,
F_246 ( V_273 ) ,
F_246 ( V_274 ) ) ;
V_53 |= V_286 ;
return;
}
F_244 ( L_104 ,
V_480 ) ;
}
