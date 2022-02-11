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
static void F_146 ( struct V_39 * V_42 )
{
struct V_167 * V_168 ;
bool V_172 = false ;
F_144 ( & V_169 ) ;
F_145 (info, &domain->devices, link) {
struct V_99 * V_101 ;
if ( ! V_168 -> V_95 || ! F_95 ( V_168 -> V_95 ) )
continue;
V_101 = F_96 ( V_168 -> V_95 ) ;
if ( V_101 -> V_173 ) {
V_172 = true ;
break;
}
}
V_42 -> V_172 = V_172 ;
}
static void F_147 ( struct V_167 * V_168 )
{
struct V_99 * V_101 ;
F_144 ( & V_169 ) ;
if ( ! V_168 || ! F_95 ( V_168 -> V_95 ) )
return;
V_101 = F_96 ( V_168 -> V_95 ) ;
#ifdef F_148
if ( V_168 -> V_174 && ! F_149 ( V_101 , V_168 -> V_174 & ~ 1 ) )
V_168 -> V_175 = 1 ;
if ( V_168 -> V_176 && ! F_150 ( V_101 ) && ! F_151 ( V_101 , 32 ) )
V_168 -> V_177 = 1 ;
#endif
if ( V_168 -> V_171 && ! F_152 ( V_101 , V_12 ) ) {
V_168 -> V_173 = 1 ;
F_146 ( V_168 -> V_42 ) ;
V_168 -> V_178 = F_153 ( V_101 ) ;
}
}
static void F_154 ( struct V_167 * V_168 )
{
struct V_99 * V_101 ;
F_144 ( & V_169 ) ;
if ( ! F_95 ( V_168 -> V_95 ) )
return;
V_101 = F_96 ( V_168 -> V_95 ) ;
if ( V_168 -> V_173 ) {
F_155 ( V_101 ) ;
V_168 -> V_173 = 0 ;
F_146 ( V_168 -> V_42 ) ;
}
#ifdef F_148
if ( V_168 -> V_177 ) {
F_156 ( V_101 ) ;
V_168 -> V_177 = 0 ;
}
if ( V_168 -> V_175 ) {
F_157 ( V_101 ) ;
V_168 -> V_175 = 0 ;
}
#endif
}
static void F_158 ( struct V_39 * V_42 ,
V_24 V_111 , unsigned V_84 )
{
T_4 V_179 , V_180 ;
unsigned long V_33 ;
struct V_167 * V_168 ;
if ( ! V_42 -> V_172 )
return;
F_104 ( & V_169 , V_33 ) ;
F_145 (info, &domain->devices, link) {
if ( ! V_168 -> V_173 )
continue;
V_179 = V_168 -> V_87 << 8 | V_168 -> V_88 ;
V_180 = V_168 -> V_178 ;
F_159 ( V_168 -> V_32 , V_179 , V_180 , V_111 , V_84 ) ;
}
F_105 ( & V_169 , V_33 ) ;
}
static void F_160 ( struct V_31 * V_32 ,
struct V_39 * V_42 ,
unsigned long V_6 , unsigned int V_181 ,
int V_182 , int V_183 )
{
unsigned int V_84 = F_161 ( F_162 ( V_181 ) ) ;
T_7 V_111 = ( T_7 ) V_6 << V_12 ;
T_4 V_55 = V_42 -> V_184 [ V_32 -> V_185 ] ;
F_75 ( V_181 == 0 ) ;
if ( V_182 )
V_182 = 1 << 6 ;
if ( ! F_163 ( V_32 -> V_71 ) || V_84 > F_164 ( V_32 -> V_71 ) )
V_32 -> V_186 . V_187 ( V_32 , V_55 , 0 , 0 ,
V_164 ) ;
else
V_32 -> V_186 . V_187 ( V_32 , V_55 , V_111 | V_182 , V_84 ,
V_165 ) ;
if ( ! F_165 ( V_32 -> V_71 ) || ! V_183 )
F_158 ( F_50 ( V_32 , V_55 ) ,
V_111 , V_84 ) ;
}
static void F_166 ( struct V_31 * V_32 )
{
T_2 V_188 ;
unsigned long V_33 ;
F_124 ( & V_32 -> V_142 , V_33 ) ;
V_188 = F_44 ( V_32 -> V_36 + V_189 ) ;
V_188 &= ~ V_190 ;
F_126 ( V_188 , V_32 -> V_36 + V_189 ) ;
F_127 ( V_32 , V_189 ,
F_44 , ! ( V_188 & V_191 ) , V_188 ) ;
F_128 ( & V_32 -> V_142 , V_33 ) ;
}
static void F_167 ( struct V_31 * V_32 )
{
T_2 V_139 ;
unsigned long V_33 ;
F_124 ( & V_32 -> V_142 , V_33 ) ;
V_32 -> V_144 |= V_192 ;
F_126 ( V_32 -> V_144 , V_32 -> V_36 + V_146 ) ;
F_127 ( V_32 , V_37 ,
F_44 , ( V_139 & V_38 ) , V_139 ) ;
F_128 ( & V_32 -> V_142 , V_33 ) ;
}
static void F_168 ( struct V_31 * V_32 )
{
T_2 V_139 ;
unsigned long V_140 ;
F_124 ( & V_32 -> V_142 , V_140 ) ;
V_32 -> V_144 &= ~ V_192 ;
F_126 ( V_32 -> V_144 , V_32 -> V_36 + V_146 ) ;
F_127 ( V_32 , V_37 ,
F_44 , ( ! ( V_139 & V_38 ) ) , V_139 ) ;
F_128 ( & V_32 -> V_142 , V_140 ) ;
}
static int F_169 ( struct V_31 * V_32 )
{
T_2 V_193 , V_194 ;
T_5 V_58 ;
V_193 = F_170 ( V_32 -> V_71 ) ;
F_142 ( L_21 ,
V_32 -> V_136 , V_193 ) ;
V_194 = F_171 ( V_193 ) ;
F_172 ( & V_32 -> V_112 ) ;
V_32 -> V_195 = F_173 ( V_194 , sizeof( unsigned long ) , V_196 ) ;
if ( ! V_32 -> V_195 ) {
F_122 ( L_22 ,
V_32 -> V_136 ) ;
return - V_137 ;
}
V_58 = ( F_174 ( V_193 , 256 ) >> 8 ) * sizeof( struct V_39 * * ) ;
V_32 -> V_56 = F_52 ( V_58 , V_196 ) ;
if ( V_32 -> V_56 ) {
V_58 = 256 * sizeof( struct V_39 * ) ;
V_32 -> V_56 [ 0 ] = F_52 ( V_58 , V_196 ) ;
}
if ( ! V_32 -> V_56 || ! V_32 -> V_56 [ 0 ] ) {
F_122 ( L_23 ,
V_32 -> V_136 ) ;
F_175 ( V_32 -> V_195 ) ;
F_175 ( V_32 -> V_56 ) ;
V_32 -> V_195 = NULL ;
V_32 -> V_56 = NULL ;
return - V_137 ;
}
F_176 ( 0 , V_32 -> V_195 ) ;
return 0 ;
}
static void F_177 ( struct V_31 * V_32 )
{
struct V_167 * V_168 , * V_98 ;
unsigned long V_33 ;
if ( ! V_32 -> V_56 || ! V_32 -> V_195 )
return;
F_104 ( & V_169 , V_33 ) ;
F_178 (info, tmp, &device_domain_list, global) {
struct V_39 * V_42 ;
if ( V_168 -> V_32 != V_32 )
continue;
if ( ! V_168 -> V_95 || ! V_168 -> V_42 )
continue;
V_42 = V_168 -> V_42 ;
F_179 ( V_42 , V_168 -> V_95 ) ;
if ( ! F_67 ( V_42 ) )
F_180 ( V_42 ) ;
}
F_105 ( & V_169 , V_33 ) ;
if ( V_32 -> V_144 & V_192 )
F_168 ( V_32 ) ;
}
static void F_181 ( struct V_31 * V_32 )
{
if ( ( V_32 -> V_56 ) && ( V_32 -> V_195 ) ) {
int V_197 = F_174 ( F_170 ( V_32 -> V_71 ) , 256 ) >> 8 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_197 ; V_79 ++ )
F_175 ( V_32 -> V_56 [ V_79 ] ) ;
F_175 ( V_32 -> V_56 ) ;
F_175 ( V_32 -> V_195 ) ;
V_32 -> V_56 = NULL ;
V_32 -> V_195 = NULL ;
}
V_75 [ V_32 -> V_185 ] = NULL ;
F_107 ( V_32 ) ;
#ifdef F_148
if ( V_175 ( V_32 ) ) {
if ( F_182 ( V_32 -> V_81 ) )
F_183 ( V_32 ) ;
F_184 ( V_32 ) ;
}
#endif
}
static struct V_39 * F_185 ( int V_33 )
{
struct V_39 * V_42 ;
V_42 = F_59 () ;
if ( ! V_42 )
return NULL ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_120 = - 1 ;
V_42 -> V_33 = V_33 ;
V_42 -> V_172 = false ;
F_186 ( & V_42 -> V_103 ) ;
return V_42 ;
}
static int F_187 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
unsigned long V_193 ;
int V_198 ;
F_144 ( & V_169 ) ;
F_144 ( & V_32 -> V_112 ) ;
V_42 -> V_199 [ V_32 -> V_185 ] += 1 ;
V_42 -> V_200 += 1 ;
if ( V_42 -> V_199 [ V_32 -> V_185 ] == 1 ) {
V_193 = F_170 ( V_32 -> V_71 ) ;
V_198 = F_188 ( V_32 -> V_195 , V_193 ) ;
if ( V_198 >= V_193 ) {
F_122 ( L_24 , V_32 -> V_136 ) ;
V_42 -> V_199 [ V_32 -> V_185 ] -= 1 ;
V_42 -> V_200 -= 1 ;
return - V_201 ;
}
F_176 ( V_198 , V_32 -> V_195 ) ;
F_51 ( V_32 , V_198 , V_42 ) ;
V_42 -> V_184 [ V_32 -> V_185 ] = V_198 ;
V_42 -> V_120 = V_32 -> V_60 ;
F_87 ( V_42 ) ;
}
return 0 ;
}
static int F_189 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
int V_198 , V_202 = V_203 ;
F_144 ( & V_169 ) ;
F_144 ( & V_32 -> V_112 ) ;
V_42 -> V_199 [ V_32 -> V_185 ] -= 1 ;
V_202 = -- V_42 -> V_200 ;
if ( V_42 -> V_199 [ V_32 -> V_185 ] == 0 ) {
V_198 = V_42 -> V_184 [ V_32 -> V_185 ] ;
F_190 ( V_198 , V_32 -> V_195 ) ;
F_51 ( V_32 , V_198 , NULL ) ;
F_87 ( V_42 ) ;
V_42 -> V_184 [ V_32 -> V_185 ] = 0 ;
}
return V_202 ;
}
static int F_191 ( void )
{
struct V_99 * V_101 = NULL ;
struct V_204 * V_204 ;
int V_79 ;
F_192 ( & V_205 , V_121 , V_206 ,
V_207 ) ;
F_193 ( & V_205 . V_208 ,
& V_209 ) ;
V_204 = F_194 ( & V_205 , F_195 ( V_210 ) ,
F_195 ( V_211 ) ) ;
if ( ! V_204 ) {
F_122 ( L_25 ) ;
return - V_212 ;
}
F_196 (pdev) {
struct V_213 * V_214 ;
for ( V_79 = 0 ; V_79 < V_215 ; V_79 ++ ) {
V_214 = & V_101 -> V_213 [ V_79 ] ;
if ( ! V_214 -> V_33 || ! ( V_214 -> V_33 & V_216 ) )
continue;
V_204 = F_194 ( & V_205 ,
F_195 ( V_214 -> V_217 ) ,
F_195 ( V_214 -> V_108 ) ) ;
if ( ! V_204 ) {
F_122 ( L_26 ) ;
return - V_212 ;
}
}
}
return 0 ;
}
static void F_197 ( struct V_39 * V_42 )
{
F_198 ( & V_205 , & V_42 -> V_218 ) ;
}
static inline int F_199 ( int V_132 )
{
int V_1 ;
int V_214 = ( V_132 - 12 ) % 9 ;
if ( V_214 == 0 )
V_1 = V_132 ;
else
V_1 = V_132 + 9 - V_214 ;
if ( V_1 > 64 )
V_1 = 64 ;
return V_1 ;
}
static int F_200 ( struct V_39 * V_42 , struct V_31 * V_32 ,
int V_219 )
{
int V_220 , V_1 ;
unsigned long V_70 ;
F_192 ( & V_42 -> V_218 , V_121 , V_206 ,
V_207 ) ;
F_197 ( V_42 ) ;
if ( V_219 > F_201 ( V_32 -> V_71 ) )
V_219 = F_201 ( V_32 -> V_71 ) ;
V_42 -> V_132 = V_219 ;
V_220 = F_199 ( V_219 ) ;
V_1 = F_4 ( V_220 ) ;
V_70 = F_70 ( V_32 -> V_71 ) ;
if ( ! F_71 ( V_1 , & V_70 ) ) {
F_142 ( L_27 , V_1 ) ;
V_1 = F_202 ( & V_70 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_212 ;
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
F_91 ( V_32 , V_42 -> V_117 , V_221 ) ;
return 0 ;
}
static void F_180 ( struct V_39 * V_42 )
{
struct V_14 * V_133 = NULL ;
if ( ! V_42 )
return;
if ( ! V_48 ) {
int V_222 ;
F_203 (cpu)
F_204 ( V_222 ) ;
}
F_79 () ;
F_205 ( V_42 ) ;
F_81 () ;
F_206 ( & V_42 -> V_218 ) ;
V_133 = F_119 ( V_42 , 0 , F_115 ( V_42 -> V_132 ) ) ;
F_120 ( V_133 ) ;
F_61 ( V_42 ) ;
}
static int F_207 ( struct V_39 * V_42 ,
struct V_31 * V_32 ,
T_6 V_87 , T_6 V_88 )
{
T_4 V_55 = V_42 -> V_184 [ V_32 -> V_185 ] ;
int V_223 = V_224 ;
struct V_167 * V_168 = NULL ;
struct V_22 * V_23 ;
unsigned long V_33 ;
struct V_27 * V_117 ;
int V_83 , V_1 ;
F_53 ( V_55 == 0 ) ;
if ( V_225 && F_66 ( V_42 ) )
V_223 = V_226 ;
F_142 ( L_28 ,
V_87 , F_208 ( V_88 ) , F_209 ( V_88 ) ) ;
F_75 ( ! V_42 -> V_117 ) ;
F_104 ( & V_169 , V_33 ) ;
F_210 ( & V_32 -> V_112 ) ;
V_83 = - V_137 ;
V_23 = F_88 ( V_32 , V_87 , V_88 , 1 ) ;
if ( ! V_23 )
goto V_227;
V_83 = 0 ;
if ( F_25 ( V_23 ) )
goto V_227;
V_117 = V_42 -> V_117 ;
F_33 ( V_23 ) ;
F_31 ( V_23 , V_55 ) ;
if ( V_223 != V_226 ) {
for ( V_1 = V_42 -> V_1 ; V_1 != V_32 -> V_1 ; V_1 -- ) {
V_83 = - V_137 ;
V_117 = F_90 ( F_35 ( V_117 ) ) ;
if ( ! F_38 ( V_117 ) )
goto V_227;
}
V_168 = F_143 ( V_42 , V_32 , V_87 , V_88 ) ;
if ( V_168 && V_168 -> V_171 )
V_223 = V_228 ;
else
V_223 = V_224 ;
F_29 ( V_23 , F_92 ( V_117 ) ) ;
F_30 ( V_23 , V_32 -> V_1 ) ;
} else {
F_30 ( V_23 , V_32 -> V_229 ) ;
}
F_28 ( V_23 , V_223 ) ;
F_27 ( V_23 ) ;
F_26 ( V_23 ) ;
F_101 ( V_42 , V_23 , sizeof( * V_23 ) ) ;
if ( F_165 ( V_32 -> V_71 ) ) {
V_32 -> V_186 . V_230 ( V_32 , 0 ,
( ( ( T_4 ) V_87 ) << 8 ) | V_88 ,
V_231 ,
V_155 ) ;
V_32 -> V_186 . V_187 ( V_32 , V_55 , 0 , 0 , V_164 ) ;
} else {
F_129 ( V_32 ) ;
}
F_147 ( V_168 ) ;
V_83 = 0 ;
V_227:
F_211 ( & V_32 -> V_112 ) ;
F_105 ( & V_169 , V_33 ) ;
return V_83 ;
}
static int F_212 ( struct V_99 * V_101 ,
T_4 V_232 , void * V_233 )
{
struct V_234 * V_235 = V_233 ;
return F_207 ( V_235 -> V_42 , V_235 -> V_32 ,
F_213 ( V_232 ) , V_232 & 0xff ) ;
}
static int
F_214 ( struct V_39 * V_42 , struct V_94 * V_95 )
{
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
struct V_234 V_235 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_212 ;
if ( ! F_95 ( V_95 ) )
return F_207 ( V_42 , V_32 , V_87 , V_88 ) ;
V_235 . V_42 = V_42 ;
V_235 . V_32 = V_32 ;
return F_215 ( F_96 ( V_95 ) ,
& F_212 , & V_235 ) ;
}
static int F_216 ( struct V_99 * V_101 ,
T_4 V_232 , void * V_233 )
{
struct V_31 * V_32 = V_233 ;
return ! F_103 ( V_32 , F_213 ( V_232 ) , V_232 & 0xff ) ;
}
static int F_217 ( struct V_94 * V_95 )
{
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_212 ;
if ( ! F_95 ( V_95 ) )
return F_103 ( V_32 , V_87 , V_88 ) ;
return ! F_215 ( F_96 ( V_95 ) ,
F_216 , V_32 ) ;
}
static inline unsigned long F_218 ( unsigned long V_236 ,
T_5 V_58 )
{
V_236 &= ~ V_237 ;
return F_219 ( V_236 + V_58 ) >> V_12 ;
}
static inline int F_220 ( struct V_39 * V_42 ,
unsigned long V_238 ,
unsigned long V_239 ,
unsigned long V_181 )
{
int V_240 , V_5 = 1 ;
unsigned long V_241 ;
V_240 = V_42 -> V_86 ;
V_241 = V_238 | V_239 ;
while ( V_240 && ! ( V_241 & ~ V_242 ) ) {
V_181 >>= V_243 ;
if ( ! V_181 )
break;
V_241 >>= V_243 ;
V_5 ++ ;
V_240 -- ;
}
return V_5 ;
}
static int F_221 ( struct V_39 * V_42 , unsigned long V_238 ,
struct V_244 * V_245 , unsigned long V_246 ,
unsigned long V_247 , int V_248 )
{
struct V_27 * V_128 = NULL , * V_28 = NULL ;
T_1 V_249 ( V_119 ) ;
unsigned long V_250 = 0 ;
unsigned int V_251 = 0 ;
unsigned long V_252 = 0 ;
F_75 ( ! F_68 ( V_42 , V_238 + V_247 - 1 ) ) ;
if ( ( V_248 & ( V_122 | V_123 ) ) == 0 )
return - V_44 ;
V_248 &= V_122 | V_123 | V_253 ;
if ( ! V_245 ) {
V_250 = V_247 ;
V_119 = ( ( T_1 ) V_246 << V_12 ) | V_248 ;
}
while ( V_247 > 0 ) {
T_7 V_98 ;
if ( ! V_250 ) {
V_250 = F_218 ( V_245 -> V_116 , V_245 -> V_254 ) ;
V_245 -> V_255 = ( ( V_256 ) V_238 << V_12 ) + V_245 -> V_116 ;
V_245 -> V_257 = V_245 -> V_254 ;
V_119 = F_222 ( F_223 ( V_245 ) ) | V_248 ;
V_246 = V_119 >> V_12 ;
}
if ( ! V_28 ) {
V_251 = F_220 ( V_42 , V_238 , V_246 , V_250 ) ;
V_128 = V_28 = F_108 ( V_42 , V_238 , & V_251 ) ;
if ( ! V_28 )
return - V_137 ;
if ( V_251 > 1 ) {
unsigned long V_258 , V_259 ;
V_119 |= V_30 ;
V_252 = F_11 ( V_251 ) ;
V_258 = V_250 / V_252 ;
V_259 = V_238 + V_258 * V_252 - 1 ;
F_114 ( V_42 , V_238 , V_259 ) ;
} else {
V_119 &= ~ ( T_7 ) V_30 ;
}
}
V_98 = F_224 ( & V_28 -> V_29 , 0ULL , V_119 ) ;
if ( V_98 ) {
static int V_260 = 5 ;
F_225 ( L_29 ,
V_238 , V_98 , ( unsigned long long ) V_119 ) ;
if ( V_260 ) {
V_260 -- ;
F_226 ( NULL ) ;
}
F_53 ( 1 ) ;
}
V_252 = F_11 ( V_251 ) ;
F_75 ( V_247 < V_252 ) ;
F_75 ( V_250 < V_252 ) ;
V_247 -= V_252 ;
V_238 += V_252 ;
V_246 += V_252 ;
V_119 += V_252 * V_121 ;
V_250 -= V_252 ;
V_28 ++ ;
if ( ! V_247 || F_40 ( V_28 ) ||
( V_251 > 1 && V_250 < V_252 ) ) {
F_101 ( V_42 , V_128 ,
( void * ) V_28 - ( void * ) V_128 ) ;
V_28 = NULL ;
}
if ( ! V_250 && V_247 )
V_245 = F_227 ( V_245 ) ;
}
return 0 ;
}
static inline int F_228 ( struct V_39 * V_42 , unsigned long V_238 ,
struct V_244 * V_245 , unsigned long V_247 ,
int V_248 )
{
return F_221 ( V_42 , V_238 , V_245 , 0 , V_247 , V_248 ) ;
}
static inline int F_229 ( struct V_39 * V_42 , unsigned long V_238 ,
unsigned long V_246 , unsigned long V_247 ,
int V_248 )
{
return F_221 ( V_42 , V_238 , NULL , V_246 , V_247 , V_248 ) ;
}
static void F_230 ( struct V_31 * V_32 , T_6 V_87 , T_6 V_88 )
{
if ( ! V_32 )
return;
F_106 ( V_32 , V_87 , V_88 ) ;
V_32 -> V_186 . V_230 ( V_32 , 0 , 0 , 0 ,
V_153 ) ;
V_32 -> V_186 . V_187 ( V_32 , 0 , 0 , 0 , V_162 ) ;
}
static inline void F_231 ( struct V_167 * V_168 )
{
F_144 ( & V_169 ) ;
F_232 ( & V_168 -> V_261 ) ;
F_232 ( & V_168 -> V_262 ) ;
if ( V_168 -> V_95 )
V_168 -> V_95 -> V_96 . V_32 = NULL ;
}
static void F_205 ( struct V_39 * V_42 )
{
struct V_167 * V_168 , * V_98 ;
unsigned long V_33 ;
F_104 ( & V_169 , V_33 ) ;
F_178 (info, tmp, &domain->devices, link)
F_233 ( V_168 ) ;
F_105 ( & V_169 , V_33 ) ;
}
static struct V_39 * F_234 ( struct V_94 * V_95 )
{
struct V_167 * V_168 ;
V_168 = V_95 -> V_96 . V_32 ;
if ( V_168 )
return V_168 -> V_42 ;
return NULL ;
}
static inline struct V_167 *
F_235 ( int V_102 , int V_87 , int V_88 )
{
struct V_167 * V_168 ;
F_145 (info, &device_domain_list, global)
if ( V_168 -> V_32 -> V_102 == V_102 && V_168 -> V_87 == V_87 &&
V_168 -> V_88 == V_88 )
return V_168 ;
return NULL ;
}
static struct V_39 * F_236 ( struct V_31 * V_32 ,
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
V_168 -> V_171 = V_168 -> V_174 = V_168 -> V_176 = 0 ;
V_168 -> V_173 = V_168 -> V_175 = V_168 -> V_177 = 0 ;
V_168 -> V_178 = 0 ;
V_168 -> V_95 = V_95 ;
V_168 -> V_42 = V_42 ;
V_168 -> V_32 = V_32 ;
if ( V_95 && F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_168 -> V_95 ) ;
if ( F_237 ( V_32 -> V_81 ) &&
F_238 ( V_101 , V_263 ) &&
F_239 ( V_101 ) )
V_168 -> V_171 = 1 ;
if ( F_89 ( V_32 ) ) {
if ( V_175 ( V_32 ) ) {
int V_264 = F_240 ( V_101 ) ;
if ( V_264 >= 0 )
V_168 -> V_174 = V_264 | 1 ;
}
if ( V_168 -> V_171 && F_182 ( V_32 -> V_81 ) &&
F_238 ( V_101 , V_265 ) )
V_168 -> V_176 = 1 ;
}
}
F_104 ( & V_169 , V_33 ) ;
if ( V_95 )
V_78 = F_234 ( V_95 ) ;
if ( ! V_78 ) {
struct V_167 * V_266 ;
V_266 = F_235 ( V_32 -> V_102 , V_87 , V_88 ) ;
if ( V_266 ) {
V_78 = V_266 -> V_42 ;
V_266 -> V_95 = V_95 ;
}
}
if ( V_78 ) {
F_105 ( & V_169 , V_33 ) ;
F_64 ( V_168 ) ;
return V_78 ;
}
F_210 ( & V_32 -> V_112 ) ;
V_83 = F_187 ( V_42 , V_32 ) ;
F_211 ( & V_32 -> V_112 ) ;
if ( V_83 ) {
F_105 ( & V_169 , V_33 ) ;
F_64 ( V_168 ) ;
return NULL ;
}
F_241 ( & V_168 -> V_261 , & V_42 -> V_103 ) ;
F_241 ( & V_168 -> V_262 , & V_267 ) ;
if ( V_95 )
V_95 -> V_96 . V_32 = V_168 ;
F_105 ( & V_169 , V_33 ) ;
if ( V_95 && F_214 ( V_42 , V_95 ) ) {
F_122 ( L_30 , F_242 ( V_95 ) ) ;
F_179 ( V_42 , V_95 ) ;
return NULL ;
}
return V_42 ;
}
static int F_243 ( struct V_99 * V_101 , T_4 V_232 , void * V_233 )
{
* ( T_4 * ) V_233 = V_232 ;
return 0 ;
}
static struct V_39 * F_244 ( struct V_94 * V_95 , int V_132 )
{
struct V_167 * V_168 = NULL ;
struct V_39 * V_42 , * V_98 ;
struct V_31 * V_32 ;
T_4 V_268 , V_269 ;
unsigned long V_33 ;
T_6 V_87 , V_88 ;
V_42 = F_234 ( V_95 ) ;
if ( V_42 )
return V_42 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return NULL ;
V_268 = ( ( T_4 ) V_87 << 8 ) | V_88 ;
if ( F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_95 ) ;
F_215 ( V_101 , F_243 , & V_269 ) ;
F_104 ( & V_169 , V_33 ) ;
V_168 = F_235 ( F_97 ( V_101 -> V_87 ) ,
F_213 ( V_269 ) ,
V_269 & 0xff ) ;
if ( V_168 ) {
V_32 = V_168 -> V_32 ;
V_42 = V_168 -> V_42 ;
}
F_105 ( & V_169 , V_33 ) ;
if ( V_168 )
goto V_270;
}
V_42 = F_185 ( 0 ) ;
if ( ! V_42 )
return NULL ;
if ( F_200 ( V_42 , V_32 , V_132 ) ) {
F_180 ( V_42 ) ;
return NULL ;
}
if ( F_95 ( V_95 ) && V_268 != V_269 ) {
V_98 = F_236 ( V_32 , F_213 ( V_269 ) ,
V_269 & 0xff , NULL , V_42 ) ;
if ( ! V_98 || V_98 != V_42 ) {
F_180 ( V_42 ) ;
V_42 = V_98 ;
}
if ( ! V_42 )
return NULL ;
}
V_270:
V_98 = F_236 ( V_32 , V_87 , V_88 , V_95 , V_42 ) ;
if ( ! V_98 || V_98 != V_42 ) {
F_180 ( V_42 ) ;
V_42 = V_98 ;
}
return V_42 ;
}
static int F_245 ( struct V_39 * V_42 ,
unsigned long long V_217 ,
unsigned long long V_108 )
{
unsigned long V_271 = V_217 >> V_12 ;
unsigned long V_272 = V_108 >> V_12 ;
if ( ! F_194 ( & V_42 -> V_218 , F_12 ( V_271 ) ,
F_12 ( V_272 ) ) ) {
F_122 ( L_31 ) ;
return - V_137 ;
}
F_142 ( L_32 , V_217 , V_108 ) ;
F_111 ( V_42 , V_271 , V_272 ) ;
return F_229 ( V_42 , V_271 , V_271 ,
V_272 - V_271 + 1 ,
V_122 | V_123 ) ;
}
static int F_246 ( struct V_94 * V_95 ,
struct V_39 * V_42 ,
unsigned long long V_217 ,
unsigned long long V_108 )
{
if ( V_42 == V_273 && V_225 ) {
F_247 ( L_33 ,
F_242 ( V_95 ) , V_217 , V_108 ) ;
return 0 ;
}
F_48 ( L_34 ,
F_242 ( V_95 ) , V_217 , V_108 ) ;
if ( V_108 < V_217 ) {
F_248 ( 1 , L_35
L_36 ,
F_249 ( V_274 ) ,
F_249 ( V_275 ) ,
F_249 ( V_276 ) ) ;
return - V_277 ;
}
if ( V_108 >> F_2 ( V_42 -> V_1 ) ) {
F_248 ( 1 , L_37
L_36 ,
F_2 ( V_42 -> V_1 ) ,
F_249 ( V_274 ) ,
F_249 ( V_275 ) ,
F_249 ( V_276 ) ) ;
return - V_277 ;
}
return F_245 ( V_42 , V_217 , V_108 ) ;
}
static int F_250 ( struct V_94 * V_95 ,
unsigned long long V_217 ,
unsigned long long V_108 )
{
struct V_39 * V_42 ;
int V_83 ;
V_42 = F_244 ( V_95 , V_72 ) ;
if ( ! V_42 )
return - V_137 ;
V_83 = F_246 ( V_95 , V_42 , V_217 , V_108 ) ;
if ( V_83 )
F_180 ( V_42 ) ;
return V_83 ;
}
static inline int F_251 ( struct V_278 * V_279 ,
struct V_94 * V_95 )
{
if ( V_95 -> V_96 . V_32 == V_97 )
return 0 ;
return F_250 ( V_95 , V_279 -> V_280 ,
V_279 -> V_281 ) ;
}
static inline void F_252 ( void )
{
struct V_99 * V_101 ;
int V_83 ;
V_101 = F_253 ( V_282 << 8 , NULL ) ;
if ( ! V_101 )
return;
F_48 ( L_38 ) ;
V_83 = F_250 ( & V_101 -> V_95 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_83 )
F_122 ( L_39 ) ;
F_254 ( V_101 ) ;
}
static inline void F_252 ( void )
{
return;
}
static int T_3 F_255 ( int V_283 )
{
int V_120 , V_83 = 0 ;
V_273 = F_185 ( V_66 ) ;
if ( ! V_273 )
return - V_284 ;
if ( F_256 ( V_273 , V_72 ) ) {
F_180 ( V_273 ) ;
return - V_284 ;
}
F_142 ( L_40 ) ;
if ( V_283 )
return 0 ;
F_257 (nid) {
unsigned long V_126 , V_259 ;
int V_79 ;
F_258 (i, nid, &start_pfn, &end_pfn, NULL) {
V_83 = F_245 ( V_273 ,
F_259 ( V_126 ) , F_259 ( V_259 ) ) ;
if ( V_83 )
return V_83 ;
}
}
return 0 ;
}
static int F_260 ( struct V_94 * V_95 )
{
struct V_167 * V_168 ;
if ( F_261 ( ! V_53 ) )
return 0 ;
V_168 = V_95 -> V_96 . V_32 ;
if ( V_168 && V_168 != V_97 )
return ( V_168 -> V_42 == V_273 ) ;
return 0 ;
}
static int F_262 ( struct V_39 * V_42 , struct V_94 * V_95 )
{
struct V_39 * V_285 ;
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_212 ;
V_285 = F_236 ( V_32 , V_87 , V_88 , V_95 , V_42 ) ;
if ( V_285 != V_42 )
return - V_286 ;
return 0 ;
}
static bool F_263 ( struct V_94 * V_95 )
{
struct V_278 * V_279 ;
struct V_94 * V_98 ;
int V_79 ;
F_79 () ;
F_264 (rmrr) {
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
static bool F_265 ( struct V_94 * V_95 )
{
if ( ! F_263 ( V_95 ) )
return false ;
if ( F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_95 ) ;
if ( F_266 ( V_101 ) || F_267 ( V_101 ) )
return false ;
}
return true ;
}
static int F_268 ( struct V_94 * V_95 , int V_287 )
{
if ( F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_95 ) ;
if ( F_265 ( V_95 ) )
return 0 ;
if ( ( V_53 & V_288 ) && F_269 ( V_101 ) )
return 1 ;
if ( ( V_53 & V_54 ) && F_267 ( V_101 ) )
return 1 ;
if ( ! ( V_53 & V_289 ) )
return 0 ;
if ( ! F_270 ( V_101 ) ) {
if ( ! F_271 ( V_101 -> V_87 ) )
return 0 ;
if ( V_101 -> V_290 >> 8 == V_291 )
return 0 ;
} else if ( F_272 ( V_101 ) == V_292 )
return 0 ;
} else {
if ( F_263 ( V_95 ) )
return 0 ;
}
if ( ! V_287 ) {
V_24 V_293 = * V_95 -> V_293 ;
if ( V_95 -> V_294 &&
V_95 -> V_294 < V_293 )
V_293 = V_95 -> V_294 ;
return V_293 >= F_273 ( V_95 ) ;
}
return 1 ;
}
static int T_3 F_274 ( struct V_94 * V_95 , int V_283 )
{
int V_83 ;
if ( ! F_268 ( V_95 , 1 ) )
return 0 ;
V_83 = F_262 ( V_273 , V_95 ) ;
if ( ! V_83 )
F_48 ( L_41 ,
V_283 ? L_42 : L_43 , F_242 ( V_95 ) ) ;
else if ( V_83 == - V_212 )
V_83 = 0 ;
return V_83 ;
}
static int T_3 F_275 ( int V_283 )
{
struct V_99 * V_101 = NULL ;
struct V_76 * V_77 ;
struct V_31 * V_32 ;
struct V_94 * V_95 ;
int V_79 ;
int V_83 = 0 ;
F_196 (pdev) {
V_83 = F_274 ( & V_101 -> V_95 , V_283 ) ;
if ( V_83 )
return V_83 ;
}
F_80 (iommu, drhd)
F_100 (drhd->devices, drhd->devices_cnt, i, dev) {
struct V_295 * V_296 ;
struct V_297 * V_298 ;
if ( V_95 -> V_87 != & V_299 )
continue;
V_298 = F_276 ( V_95 ) ;
F_277 ( & V_298 -> V_300 ) ;
F_145 (pn, &adev->physical_node_list, node) {
V_83 = F_274 ( V_296 -> V_95 , V_283 ) ;
if ( V_83 )
break;
}
F_278 ( & V_298 -> V_300 ) ;
if ( V_83 )
return V_83 ;
}
return 0 ;
}
static void F_279 ( struct V_31 * V_32 )
{
if ( ! V_32 -> V_170 ) {
F_280 ( - 1 , V_32 ) ;
F_281 ( V_32 ) ;
}
if ( F_282 ( V_32 ) ) {
V_32 -> V_186 . V_230 = F_131 ;
V_32 -> V_186 . V_187 = F_136 ;
F_48 ( L_44 ,
V_32 -> V_136 ) ;
} else {
V_32 -> V_186 . V_230 = V_301 ;
V_32 -> V_186 . V_187 = V_302 ;
F_48 ( L_45 , V_32 -> V_136 ) ;
}
}
static int F_283 ( struct V_31 * V_32 ,
struct V_17 * V_303 ,
struct V_22 * * V_304 ,
int V_87 , bool V_305 )
{
int V_306 , V_307 = 0 , V_57 , V_88 , V_83 = 0 , V_55 ;
struct V_22 * V_308 = NULL , V_309 ;
struct V_22 * V_310 = NULL ;
struct V_17 V_18 ;
T_1 V_311 ;
V_306 = V_305 ? V_87 * 2 : V_87 ;
memcpy ( & V_18 , V_303 , sizeof( V_18 ) ) ;
for ( V_88 = 0 ; V_88 < 256 ; V_88 ++ ) {
V_57 = ( V_305 ? V_88 * 2 : V_88 ) % 256 ;
if ( V_57 == 0 ) {
if ( V_308 ) {
V_304 [ V_306 ] = V_308 ;
F_91 ( V_32 , V_308 ,
V_121 ) ;
V_307 = 1 ;
}
if ( V_310 )
F_284 ( V_310 ) ;
V_83 = 0 ;
if ( V_88 < 0x80 )
V_311 = F_18 ( & V_18 ) ;
else
V_311 = F_19 ( & V_18 ) ;
if ( ! V_311 ) {
if ( V_305 && V_88 == 0 ) {
V_88 = 0x7f ;
continue;
} else {
goto V_104;
}
}
V_83 = - V_137 ;
V_310 = F_285 ( V_311 , V_221 ,
V_312 ) ;
if ( ! V_310 )
goto V_104;
V_308 = F_54 ( V_32 -> V_60 ) ;
if ( ! V_308 )
goto V_313;
V_83 = 0 ;
}
memcpy ( & V_309 , V_310 + V_57 , sizeof( V_309 ) ) ;
if ( ! F_24 ( & V_309 ) )
continue;
V_55 = F_32 ( & V_309 ) ;
if ( V_55 >= 0 && V_55 < F_170 ( V_32 -> V_71 ) )
F_176 ( V_55 , V_32 -> V_195 ) ;
F_20 ( & V_309 ) ;
F_22 ( & V_309 ) ;
V_308 [ V_57 ] = V_309 ;
}
V_304 [ V_306 + V_307 ] = V_308 ;
F_91 ( V_32 , V_308 , V_121 ) ;
V_313:
F_286 ( V_310 ) ;
V_104:
return V_83 ;
}
static int F_287 ( struct V_31 * V_32 )
{
struct V_22 * * V_314 ;
struct V_17 * V_315 ;
T_1 V_316 ;
int V_317 ;
unsigned long V_33 ;
V_24 V_318 ;
int V_87 , V_83 ;
bool V_319 , V_305 ;
V_318 = V_158 ( V_32 -> V_36 + V_143 ) ;
V_305 = ! ! ( V_318 & V_141 ) ;
V_319 = ! ! F_288 ( V_32 -> V_81 ) ;
if ( V_319 != V_305 )
return - V_44 ;
V_316 = V_318 & V_20 ;
if ( ! V_316 )
return - V_44 ;
V_315 = F_285 ( V_316 , V_221 , V_312 ) ;
if ( ! V_315 )
return - V_137 ;
V_317 = V_305 ? 512 : 256 ;
V_83 = - V_137 ;
V_314 = F_52 ( V_317 * sizeof( void * ) , V_196 ) ;
if ( ! V_314 )
goto V_313;
for ( V_87 = 0 ; V_87 < 256 ; V_87 ++ ) {
V_83 = F_283 ( V_32 , & V_315 [ V_87 ] ,
V_314 , V_87 , V_305 ) ;
if ( V_83 ) {
F_122 ( L_46 ,
V_32 -> V_136 , V_87 ) ;
continue;
}
}
F_104 ( & V_32 -> V_112 , V_33 ) ;
for ( V_87 = 0 ; V_87 < 256 ; V_87 ++ ) {
int V_57 = V_305 ? V_87 * 2 : V_87 ;
V_24 V_29 ;
if ( V_314 [ V_57 ] ) {
V_29 = F_92 ( V_314 [ V_57 ] ) | 1 ;
V_32 -> V_17 [ V_87 ] . V_19 = V_29 ;
}
if ( ! V_305 || ! V_314 [ V_57 + 1 ] )
continue;
V_29 = F_92 ( V_314 [ V_57 + 1 ] ) | 1 ;
V_32 -> V_17 [ V_87 ] . V_21 = V_29 ;
}
F_105 ( & V_32 -> V_112 , V_33 ) ;
F_175 ( V_314 ) ;
F_91 ( V_32 , V_32 -> V_17 , V_221 ) ;
V_83 = 0 ;
V_313:
F_286 ( V_315 ) ;
return V_83 ;
}
static int T_3 F_289 ( void )
{
struct V_76 * V_77 ;
struct V_278 * V_279 ;
bool V_320 = false ;
struct V_94 * V_95 ;
struct V_31 * V_32 ;
int V_79 , V_83 , V_222 ;
F_290 (drhd) {
if ( V_74 < V_321 ) {
V_74 ++ ;
continue;
}
F_291 ( L_47 , V_321 ) ;
}
if ( V_74 < V_321 )
V_74 = V_321 ;
V_75 = F_173 ( V_74 , sizeof( struct V_31 * ) ,
V_196 ) ;
if ( ! V_75 ) {
F_122 ( L_48 ) ;
V_83 = - V_137 ;
goto error;
}
F_203 (cpu) {
struct V_322 * V_323 = F_292 ( & V_324 ,
V_222 ) ;
V_323 -> V_325 = F_52 ( V_74 *
sizeof( struct V_326 ) ,
V_196 ) ;
if ( ! V_323 -> V_325 ) {
V_83 = - V_137 ;
goto V_327;
}
F_172 ( & V_323 -> V_112 ) ;
F_293 ( & V_323 -> V_328 , F_204 , V_222 ) ;
}
F_80 (iommu, drhd) {
V_75 [ V_32 -> V_185 ] = V_32 ;
F_279 ( V_32 ) ;
V_83 = F_169 ( V_32 ) ;
if ( V_83 )
goto V_329;
F_43 ( V_32 ) ;
if ( F_41 ( V_32 ) && ! F_294 () ) {
F_168 ( V_32 ) ;
F_42 ( V_32 ) ;
F_247 ( L_49 ,
V_32 -> V_136 ) ;
}
V_83 = F_121 ( V_32 ) ;
if ( V_83 )
goto V_329;
if ( F_41 ( V_32 ) ) {
F_48 ( L_50 ) ;
V_83 = F_287 ( V_32 ) ;
if ( V_83 ) {
F_122 ( L_51 ,
V_32 -> V_136 ) ;
F_168 ( V_32 ) ;
F_42 ( V_32 ) ;
} else {
F_48 ( L_52 ,
V_32 -> V_136 ) ;
V_320 = true ;
}
}
if ( ! F_295 ( V_32 -> V_81 ) )
V_225 = 0 ;
#ifdef F_148
if ( V_175 ( V_32 ) )
F_296 ( V_32 ) ;
#endif
}
F_80 (iommu, drhd) {
F_129 ( V_32 ) ;
F_123 ( V_32 ) ;
V_32 -> V_186 . V_230 ( V_32 , 0 , 0 , 0 , V_153 ) ;
V_32 -> V_186 . V_187 ( V_32 , 0 , 0 , 0 , V_162 ) ;
}
if ( V_330 )
V_53 |= V_289 ;
#ifdef F_297
V_53 |= V_54 ;
#endif
if ( V_53 ) {
V_83 = F_255 ( V_225 ) ;
if ( V_83 )
goto V_329;
}
F_298 () ;
if ( V_320 )
goto V_331;
if ( V_53 ) {
V_83 = F_275 ( V_225 ) ;
if ( V_83 ) {
F_225 ( L_53 ) ;
goto V_329;
}
}
F_48 ( L_54 ) ;
F_264 (rmrr) {
F_100 (rmrr->devices, rmrr->devices_cnt,
i, dev) {
V_83 = F_251 ( V_279 , V_95 ) ;
if ( V_83 )
F_122 ( L_55 ) ;
}
}
F_252 () ;
V_331:
F_299 (iommu, drhd) {
if ( V_77 -> V_332 ) {
if ( V_333 )
F_166 ( V_32 ) ;
continue;
}
F_129 ( V_32 ) ;
#ifdef F_148
if ( V_175 ( V_32 ) && F_182 ( V_32 -> V_81 ) ) {
V_83 = F_300 ( V_32 ) ;
if ( V_83 )
goto V_329;
}
#endif
V_83 = F_301 ( V_32 ) ;
if ( V_83 )
goto V_329;
if ( ! F_41 ( V_32 ) )
F_167 ( V_32 ) ;
F_166 ( V_32 ) ;
}
return 0 ;
V_329:
F_80 (iommu, drhd) {
F_177 ( V_32 ) ;
F_181 ( V_32 ) ;
}
V_327:
F_203 (cpu)
F_175 ( F_292 ( & V_324 , V_222 ) -> V_325 ) ;
F_175 ( V_75 ) ;
error:
return V_83 ;
}
static unsigned long F_302 ( struct V_94 * V_95 ,
struct V_39 * V_42 ,
unsigned long V_334 , T_7 V_293 )
{
unsigned long V_335 = 0 ;
V_293 = F_3 ( T_7 , F_303 ( V_42 -> V_132 ) , V_293 ) ;
V_334 = F_162 ( V_334 ) ;
if ( ! V_47 && V_293 > F_304 ( 32 ) ) {
V_335 = F_305 ( & V_42 -> V_218 , V_334 ,
F_195 ( F_304 ( 32 ) ) ) ;
if ( V_335 )
return V_335 ;
}
V_335 = F_305 ( & V_42 -> V_218 , V_334 , F_195 ( V_293 ) ) ;
if ( F_306 ( ! V_335 ) ) {
F_122 ( L_56 ,
V_334 , F_242 ( V_95 ) ) ;
return 0 ;
}
return V_335 ;
}
static struct V_39 * F_307 ( struct V_94 * V_95 )
{
struct V_278 * V_279 ;
struct V_39 * V_42 ;
struct V_94 * V_336 ;
int V_79 , V_83 ;
V_42 = F_244 ( V_95 , V_72 ) ;
if ( ! V_42 ) {
F_122 ( L_57 ,
F_242 ( V_95 ) ) ;
return NULL ;
}
F_79 () ;
F_264 (rmrr) {
F_100 (rmrr->devices, rmrr->devices_cnt,
i, i_dev) {
if ( V_336 != V_95 )
continue;
V_83 = F_246 ( V_95 , V_42 ,
V_279 -> V_280 ,
V_279 -> V_281 ) ;
if ( V_83 )
F_308 ( V_95 , L_55 ) ;
}
}
F_81 () ;
return V_42 ;
}
static inline struct V_39 * F_309 ( struct V_94 * V_95 )
{
struct V_167 * V_168 ;
V_168 = V_95 -> V_96 . V_32 ;
if ( F_261 ( V_168 ) )
return V_168 -> V_42 ;
return F_307 ( V_95 ) ;
}
static int F_310 ( struct V_94 * V_95 )
{
int V_78 ;
if ( F_93 ( V_95 ) )
return 1 ;
if ( ! V_53 )
return 0 ;
V_78 = F_260 ( V_95 ) ;
if ( V_78 ) {
if ( F_268 ( V_95 , 0 ) )
return 1 ;
else {
F_179 ( V_273 , V_95 ) ;
F_48 ( L_58 ,
F_242 ( V_95 ) ) ;
return 0 ;
}
} else {
if ( F_268 ( V_95 , 0 ) ) {
int V_83 ;
V_83 = F_262 ( V_273 , V_95 ) ;
if ( ! V_83 ) {
F_48 ( L_59 ,
F_242 ( V_95 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_256 F_311 ( struct V_94 * V_95 , T_1 V_337 ,
T_5 V_58 , int V_338 , V_24 V_293 )
{
struct V_39 * V_42 ;
T_1 V_339 ;
unsigned long V_335 ;
int V_248 = 0 ;
int V_83 ;
struct V_31 * V_32 ;
unsigned long V_340 = V_337 >> V_11 ;
F_75 ( V_338 == V_341 ) ;
if ( F_310 ( V_95 ) )
return V_337 ;
V_42 = F_309 ( V_95 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_74 ( V_42 ) ;
V_58 = F_218 ( V_337 , V_58 ) ;
V_335 = F_302 ( V_95 , V_42 , F_12 ( V_58 ) , V_293 ) ;
if ( ! V_335 )
goto error;
if ( V_338 == V_342 || V_338 == V_343 || \
! F_312 ( V_32 -> V_71 ) )
V_248 |= V_122 ;
if ( V_338 == V_344 || V_338 == V_343 )
V_248 |= V_123 ;
V_83 = F_229 ( V_42 , F_13 ( V_335 ) ,
F_13 ( V_340 ) , V_58 , V_248 ) ;
if ( V_83 )
goto error;
if ( F_165 ( V_32 -> V_71 ) )
F_160 ( V_32 , V_42 ,
F_13 ( V_335 ) ,
V_58 , 0 , 1 ) ;
else
F_129 ( V_32 ) ;
V_339 = ( T_1 ) V_335 << V_11 ;
V_339 += V_337 & ~ V_237 ;
return V_339 ;
error:
if ( V_335 )
F_313 ( & V_42 -> V_218 , V_335 , F_12 ( V_58 ) ) ;
F_122 ( L_60 ,
F_242 ( V_95 ) , V_58 , ( unsigned long long ) V_337 , V_338 ) ;
return 0 ;
}
static V_256 F_314 ( struct V_94 * V_95 , struct V_14 * V_14 ,
unsigned long V_116 , T_5 V_58 ,
enum V_345 V_338 ,
unsigned long V_346 )
{
return F_311 ( V_95 , F_222 ( V_14 ) + V_116 , V_58 ,
V_338 , * V_95 -> V_293 ) ;
}
static void F_315 ( struct V_322 * V_347 )
{
int V_79 , V_348 ;
V_347 -> V_349 = 0 ;
for ( V_79 = 0 ; V_79 < V_74 ; V_79 ++ ) {
struct V_31 * V_32 = V_75 [ V_79 ] ;
struct V_326 * V_350 =
& V_347 -> V_325 [ V_79 ] ;
if ( ! V_32 )
continue;
if ( ! V_350 -> V_131 )
continue;
if ( ! F_165 ( V_32 -> V_71 ) )
V_32 -> V_186 . V_187 ( V_32 , 0 , 0 , 0 ,
V_162 ) ;
for ( V_348 = 0 ; V_348 < V_350 -> V_131 ; V_348 ++ ) {
unsigned long V_84 ;
struct V_351 * V_91 =
& V_350 -> V_352 [ V_348 ] ;
unsigned long V_335 = V_91 -> V_335 ;
unsigned long V_334 = V_91 -> V_334 ;
struct V_39 * V_42 = V_91 -> V_42 ;
struct V_14 * V_133 = V_91 -> V_133 ;
if ( F_165 ( V_32 -> V_71 ) )
F_160 ( V_32 , V_42 ,
F_13 ( V_335 ) ,
V_334 , ! V_133 , 0 ) ;
else {
V_84 = F_161 ( V_334 ) ;
F_158 ( V_42 ,
( T_7 ) V_335 << V_11 , V_84 ) ;
}
F_313 ( & V_42 -> V_218 , V_335 , V_334 ) ;
if ( V_133 )
F_120 ( V_133 ) ;
}
V_350 -> V_131 = 0 ;
}
V_347 -> V_58 = 0 ;
}
static void F_204 ( unsigned long V_353 )
{
struct V_322 * V_347 = F_292 ( & V_324 , V_353 ) ;
unsigned long V_33 ;
F_104 ( & V_347 -> V_112 , V_33 ) ;
F_315 ( V_347 ) ;
F_105 ( & V_347 -> V_112 , V_33 ) ;
}
static void F_316 ( struct V_39 * V_41 , unsigned long V_335 ,
unsigned long V_334 , struct V_14 * V_133 )
{
unsigned long V_33 ;
int V_354 , V_73 ;
struct V_31 * V_32 ;
struct V_351 * V_91 ;
struct V_322 * V_347 ;
unsigned int V_353 ;
V_353 = F_317 () ;
V_347 = F_292 ( & V_324 , V_353 ) ;
if ( V_347 -> V_58 == V_355 ) {
int V_222 ;
F_318 (cpu)
F_204 ( V_222 ) ;
}
F_104 ( & V_347 -> V_112 , V_33 ) ;
V_32 = F_74 ( V_41 ) ;
V_73 = V_32 -> V_185 ;
V_354 = V_347 -> V_325 [ V_73 ] . V_131 ;
++ ( V_347 -> V_325 [ V_73 ] . V_131 ) ;
V_91 = & V_347 -> V_325 [ V_73 ] . V_352 [ V_354 ] ;
V_91 -> V_42 = V_41 ;
V_91 -> V_335 = V_335 ;
V_91 -> V_334 = V_334 ;
V_91 -> V_133 = V_133 ;
if ( ! V_347 -> V_349 ) {
F_319 ( & V_347 -> V_328 , V_356 + F_320 ( 10 ) ) ;
V_347 -> V_349 = 1 ;
}
V_347 -> V_58 ++ ;
F_105 ( & V_347 -> V_112 , V_33 ) ;
F_321 () ;
}
static void F_322 ( struct V_94 * V_95 , V_256 V_357 , T_5 V_58 )
{
struct V_39 * V_42 ;
unsigned long V_126 , V_127 ;
unsigned long V_334 ;
unsigned long V_335 ;
struct V_31 * V_32 ;
struct V_14 * V_133 ;
if ( F_310 ( V_95 ) )
return;
V_42 = F_234 ( V_95 ) ;
F_75 ( ! V_42 ) ;
V_32 = F_74 ( V_42 ) ;
V_335 = F_195 ( V_357 ) ;
V_334 = F_218 ( V_357 , V_58 ) ;
V_126 = F_13 ( V_335 ) ;
V_127 = V_126 + V_334 - 1 ;
F_142 ( L_61 ,
F_242 ( V_95 ) , V_126 , V_127 ) ;
V_133 = F_119 ( V_42 , V_126 , V_127 ) ;
if ( V_48 ) {
F_160 ( V_32 , V_42 , V_126 ,
V_334 , ! V_133 , 0 ) ;
F_313 ( & V_42 -> V_218 , V_335 , F_12 ( V_334 ) ) ;
F_120 ( V_133 ) ;
} else {
F_316 ( V_42 , V_335 , V_334 , V_133 ) ;
}
}
static void F_323 ( struct V_94 * V_95 , V_256 V_357 ,
T_5 V_58 , enum V_345 V_338 ,
unsigned long V_346 )
{
F_322 ( V_95 , V_357 , V_58 ) ;
}
static void * F_324 ( struct V_94 * V_95 , T_5 V_58 ,
V_256 * V_358 , T_8 V_33 ,
unsigned long V_346 )
{
struct V_14 * V_14 = NULL ;
int V_359 ;
V_58 = F_219 ( V_58 ) ;
V_359 = F_325 ( V_58 ) ;
if ( ! F_310 ( V_95 ) )
V_33 &= ~ ( V_360 | V_361 ) ;
else if ( V_95 -> V_294 < F_273 ( V_95 ) ) {
if ( V_95 -> V_294 < F_304 ( 32 ) )
V_33 |= V_360 ;
else
V_33 |= V_361 ;
}
if ( F_326 ( V_33 ) ) {
unsigned int V_202 = V_58 >> V_11 ;
V_14 = F_327 ( V_95 , V_202 , V_359 ) ;
if ( V_14 && F_310 ( V_95 ) &&
F_222 ( V_14 ) + V_58 > V_95 -> V_294 ) {
F_328 ( V_95 , V_14 , V_202 ) ;
V_14 = NULL ;
}
}
if ( ! V_14 )
V_14 = F_329 ( V_33 , V_359 ) ;
if ( ! V_14 )
return NULL ;
memset ( F_56 ( V_14 ) , 0 , V_58 ) ;
* V_358 = F_311 ( V_95 , F_222 ( V_14 ) , V_58 ,
V_343 ,
V_95 -> V_294 ) ;
if ( * V_358 )
return F_56 ( V_14 ) ;
if ( ! F_328 ( V_95 , V_14 , V_58 >> V_11 ) )
F_330 ( V_14 , V_359 ) ;
return NULL ;
}
static void F_331 ( struct V_94 * V_95 , T_5 V_58 , void * V_61 ,
V_256 V_358 , unsigned long V_346 )
{
int V_359 ;
struct V_14 * V_14 = F_17 ( V_61 ) ;
V_58 = F_219 ( V_58 ) ;
V_359 = F_325 ( V_58 ) ;
F_322 ( V_95 , V_358 , V_58 ) ;
if ( ! F_328 ( V_95 , V_14 , V_58 >> V_11 ) )
F_330 ( V_14 , V_359 ) ;
}
static void F_332 ( struct V_94 * V_95 , struct V_244 * V_362 ,
int V_363 , enum V_345 V_338 ,
unsigned long V_346 )
{
V_256 V_364 = F_333 ( V_362 ) & V_237 ;
unsigned long V_334 = 0 ;
struct V_244 * V_245 ;
int V_79 ;
F_334 (sglist, sg, nelems, i) {
V_334 += F_218 ( F_333 ( V_245 ) , F_335 ( V_245 ) ) ;
}
F_322 ( V_95 , V_364 , V_334 << V_12 ) ;
}
static int F_336 ( struct V_94 * V_365 ,
struct V_244 * V_362 , int V_363 , int V_338 )
{
int V_79 ;
struct V_244 * V_245 ;
F_334 (sglist, sg, nelems, i) {
F_75 ( ! F_223 ( V_245 ) ) ;
V_245 -> V_255 = F_222 ( F_223 ( V_245 ) ) + V_245 -> V_116 ;
V_245 -> V_257 = V_245 -> V_254 ;
}
return V_363 ;
}
static int F_337 ( struct V_94 * V_95 , struct V_244 * V_362 , int V_363 ,
enum V_345 V_338 , unsigned long V_346 )
{
int V_79 ;
struct V_39 * V_42 ;
T_5 V_58 = 0 ;
int V_248 = 0 ;
unsigned long V_335 ;
int V_83 ;
struct V_244 * V_245 ;
unsigned long V_366 ;
struct V_31 * V_32 ;
F_75 ( V_338 == V_341 ) ;
if ( F_310 ( V_95 ) )
return F_336 ( V_95 , V_362 , V_363 , V_338 ) ;
V_42 = F_309 ( V_95 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_74 ( V_42 ) ;
F_334 (sglist, sg, nelems, i)
V_58 += F_218 ( V_245 -> V_116 , V_245 -> V_254 ) ;
V_335 = F_302 ( V_95 , V_42 , F_12 ( V_58 ) ,
* V_95 -> V_293 ) ;
if ( ! V_335 ) {
V_362 -> V_257 = 0 ;
return 0 ;
}
if ( V_338 == V_342 || V_338 == V_343 || \
! F_312 ( V_32 -> V_71 ) )
V_248 |= V_122 ;
if ( V_338 == V_344 || V_338 == V_343 )
V_248 |= V_123 ;
V_366 = F_13 ( V_335 ) ;
V_83 = F_228 ( V_42 , V_366 , V_362 , V_58 , V_248 ) ;
if ( F_306 ( V_83 ) ) {
F_114 ( V_42 , V_366 ,
V_366 + V_58 - 1 ) ;
F_313 ( & V_42 -> V_218 , V_335 , F_12 ( V_58 ) ) ;
return 0 ;
}
if ( F_165 ( V_32 -> V_71 ) )
F_160 ( V_32 , V_42 , V_366 , V_58 , 0 , 1 ) ;
else
F_129 ( V_32 ) ;
return V_363 ;
}
static int F_338 ( struct V_94 * V_95 , V_256 V_367 )
{
return ! V_367 ;
}
static inline int F_339 ( void )
{
int V_83 = 0 ;
V_63 = F_340 ( L_62 ,
sizeof( struct V_39 ) ,
0 ,
V_368 ,
NULL ) ;
if ( ! V_63 ) {
F_122 ( L_63 ) ;
V_83 = - V_137 ;
}
return V_83 ;
}
static inline int F_341 ( void )
{
int V_83 = 0 ;
V_64 = F_340 ( L_64 ,
sizeof( struct V_167 ) ,
0 ,
V_368 ,
NULL ) ;
if ( ! V_64 ) {
F_122 ( L_65 ) ;
V_83 = - V_137 ;
}
return V_83 ;
}
static int T_3 F_342 ( void )
{
int V_83 ;
V_83 = F_343 () ;
if ( V_83 )
return V_83 ;
V_83 = F_339 () ;
if ( V_83 )
goto V_369;
V_83 = F_341 () ;
if ( ! V_83 )
return V_83 ;
F_344 ( V_63 ) ;
V_369:
F_345 () ;
return - V_137 ;
}
static void T_3 F_346 ( void )
{
F_344 ( V_64 ) ;
F_344 ( V_63 ) ;
F_345 () ;
}
static void F_347 ( struct V_99 * V_101 )
{
struct V_76 * V_77 ;
T_2 V_370 ;
int V_371 ;
V_371 = F_348 ( V_101 -> V_87 , F_349 ( 0 , 0 ) , 0xb0 , & V_370 ) ;
if ( V_371 ) {
F_350 ( & V_101 -> V_95 , L_66 ) ;
return;
}
V_370 &= 0xffff0000 ;
V_77 = F_351 ( V_101 ) ;
if ( F_352 ( ! V_77 || V_77 -> V_372 - V_370 != 0xa000 ,
V_373 ,
L_67 ) )
V_101 -> V_95 . V_96 . V_32 = V_97 ;
}
static void T_3 F_353 ( void )
{
struct V_76 * V_77 ;
struct V_94 * V_95 ;
int V_79 ;
F_290 (drhd) {
if ( ! V_77 -> V_110 ) {
F_100 (drhd->devices,
drhd->devices_cnt, i, dev)
break;
if ( V_79 == V_77 -> V_374 )
V_77 -> V_332 = 1 ;
}
}
F_354 (drhd) {
if ( V_77 -> V_110 )
continue;
F_100 (drhd->devices,
drhd->devices_cnt, i, dev)
if ( ! F_95 ( V_95 ) || ! F_267 ( F_96 ( V_95 ) ) )
break;
if ( V_79 < V_77 -> V_374 )
continue;
if ( V_46 ) {
V_375 = 1 ;
} else {
V_77 -> V_332 = 1 ;
F_100 (drhd->devices,
drhd->devices_cnt, i, dev)
V_95 -> V_96 . V_32 = V_97 ;
}
}
}
static int F_355 ( void )
{
struct V_76 * V_77 ;
struct V_31 * V_32 = NULL ;
F_80 (iommu, drhd)
if ( V_32 -> V_170 )
F_356 ( V_32 ) ;
F_299 (iommu, drhd) {
if ( V_77 -> V_332 ) {
if ( V_333 )
F_166 ( V_32 ) ;
continue;
}
F_129 ( V_32 ) ;
F_123 ( V_32 ) ;
V_32 -> V_186 . V_230 ( V_32 , 0 , 0 , 0 ,
V_153 ) ;
V_32 -> V_186 . V_187 ( V_32 , 0 , 0 , 0 , V_162 ) ;
F_167 ( V_32 ) ;
F_166 ( V_32 ) ;
}
return 0 ;
}
static void F_357 ( void )
{
struct V_76 * V_77 ;
struct V_31 * V_32 ;
F_80 (iommu, drhd) {
V_32 -> V_186 . V_230 ( V_32 , 0 , 0 , 0 ,
V_153 ) ;
V_32 -> V_186 . V_187 ( V_32 , 0 , 0 , 0 ,
V_162 ) ;
}
}
static int F_358 ( void )
{
struct V_76 * V_77 ;
struct V_31 * V_32 = NULL ;
unsigned long V_140 ;
F_80 (iommu, drhd) {
V_32 -> V_376 = F_52 ( sizeof( T_2 ) * V_377 ,
V_59 ) ;
if ( ! V_32 -> V_376 )
goto V_378;
}
F_357 () ;
F_80 (iommu, drhd) {
F_168 ( V_32 ) ;
F_124 ( & V_32 -> V_142 , V_140 ) ;
V_32 -> V_376 [ V_379 ] =
F_44 ( V_32 -> V_36 + V_380 ) ;
V_32 -> V_376 [ V_381 ] =
F_44 ( V_32 -> V_36 + V_382 ) ;
V_32 -> V_376 [ V_383 ] =
F_44 ( V_32 -> V_36 + V_384 ) ;
V_32 -> V_376 [ V_385 ] =
F_44 ( V_32 -> V_36 + V_386 ) ;
F_128 ( & V_32 -> V_142 , V_140 ) ;
}
return 0 ;
V_378:
F_80 (iommu, drhd)
F_175 ( V_32 -> V_376 ) ;
return - V_137 ;
}
static void F_359 ( void )
{
struct V_76 * V_77 ;
struct V_31 * V_32 = NULL ;
unsigned long V_140 ;
if ( F_355 () ) {
if ( V_333 )
F_360 ( L_68 ) ;
else
F_248 ( 1 , L_69 ) ;
return;
}
F_80 (iommu, drhd) {
F_124 ( & V_32 -> V_142 , V_140 ) ;
F_126 ( V_32 -> V_376 [ V_379 ] ,
V_32 -> V_36 + V_380 ) ;
F_126 ( V_32 -> V_376 [ V_381 ] ,
V_32 -> V_36 + V_382 ) ;
F_126 ( V_32 -> V_376 [ V_383 ] ,
V_32 -> V_36 + V_384 ) ;
F_126 ( V_32 -> V_376 [ V_385 ] ,
V_32 -> V_36 + V_386 ) ;
F_128 ( & V_32 -> V_142 , V_140 ) ;
}
F_80 (iommu, drhd)
F_175 ( V_32 -> V_376 ) ;
}
static void T_3 F_361 ( void )
{
F_362 ( & V_387 ) ;
}
static inline void F_361 ( void ) {}
int T_3 F_363 ( struct V_388 * V_389 , void * V_390 )
{
struct V_391 * V_279 ;
struct V_278 * V_392 ;
V_392 = F_52 ( sizeof( * V_392 ) , V_196 ) ;
if ( ! V_392 )
return - V_137 ;
V_392 -> V_393 = V_389 ;
V_279 = (struct V_391 * ) V_389 ;
V_392 -> V_280 = V_279 -> V_280 ;
V_392 -> V_281 = V_279 -> V_281 ;
V_392 -> V_103 = F_364 ( ( void * ) ( V_279 + 1 ) ,
( ( void * ) V_279 ) + V_279 -> V_389 . V_254 ,
& V_392 -> V_374 ) ;
if ( V_392 -> V_374 && V_392 -> V_103 == NULL ) {
F_175 ( V_392 ) ;
return - V_137 ;
}
F_241 ( & V_392 -> V_394 , & V_395 ) ;
return 0 ;
}
static struct V_396 * F_365 ( struct V_397 * V_398 )
{
struct V_396 * V_399 ;
struct V_397 * V_98 ;
F_366 (atsru, &dmar_atsr_units, list) {
V_98 = (struct V_397 * ) V_399 -> V_393 ;
if ( V_398 -> V_102 != V_98 -> V_102 )
continue;
if ( V_398 -> V_389 . V_254 != V_98 -> V_389 . V_254 )
continue;
if ( memcmp ( V_398 , V_98 , V_398 -> V_389 . V_254 ) == 0 )
return V_399 ;
}
return NULL ;
}
int F_367 ( struct V_388 * V_393 , void * V_390 )
{
struct V_397 * V_398 ;
struct V_396 * V_399 ;
if ( V_400 != V_401 && ! V_402 )
return 0 ;
V_398 = F_46 ( V_393 , struct V_397 , V_389 ) ;
V_399 = F_365 ( V_398 ) ;
if ( V_399 )
return 0 ;
V_399 = F_52 ( sizeof( * V_399 ) + V_393 -> V_254 , V_196 ) ;
if ( ! V_399 )
return - V_137 ;
V_399 -> V_393 = ( void * ) ( V_399 + 1 ) ;
memcpy ( V_399 -> V_393 , V_393 , V_393 -> V_254 ) ;
V_399 -> V_110 = V_398 -> V_33 & 0x1 ;
if ( ! V_399 -> V_110 ) {
V_399 -> V_103 = F_364 ( ( void * ) ( V_398 + 1 ) ,
( void * ) V_398 + V_398 -> V_389 . V_254 ,
& V_399 -> V_374 ) ;
if ( V_399 -> V_374 && V_399 -> V_103 == NULL ) {
F_175 ( V_399 ) ;
return - V_137 ;
}
}
F_368 ( & V_399 -> V_394 , & V_403 ) ;
return 0 ;
}
static void F_369 ( struct V_396 * V_399 )
{
F_370 ( & V_399 -> V_103 , & V_399 -> V_374 ) ;
F_175 ( V_399 ) ;
}
int F_371 ( struct V_388 * V_393 , void * V_390 )
{
struct V_397 * V_398 ;
struct V_396 * V_399 ;
V_398 = F_46 ( V_393 , struct V_397 , V_389 ) ;
V_399 = F_365 ( V_398 ) ;
if ( V_399 ) {
F_372 ( & V_399 -> V_394 ) ;
F_373 () ;
F_369 ( V_399 ) ;
}
return 0 ;
}
int F_374 ( struct V_388 * V_393 , void * V_390 )
{
int V_79 ;
struct V_94 * V_95 ;
struct V_397 * V_398 ;
struct V_396 * V_399 ;
V_398 = F_46 ( V_393 , struct V_397 , V_389 ) ;
V_399 = F_365 ( V_398 ) ;
if ( ! V_399 )
return 0 ;
if ( ! V_399 -> V_110 && V_399 -> V_103 && V_399 -> V_374 ) {
F_100 (atsru->devices, atsru->devices_cnt,
i, dev)
return - V_286 ;
}
return 0 ;
}
static int F_375 ( struct V_76 * V_404 )
{
int V_405 , V_83 = 0 ;
struct V_31 * V_32 = V_404 -> V_32 ;
if ( V_75 [ V_32 -> V_185 ] )
return 0 ;
if ( V_225 && ! F_295 ( V_32 -> V_81 ) ) {
F_247 ( L_70 ,
V_32 -> V_136 ) ;
return - V_406 ;
}
if ( ! F_83 ( V_32 -> V_81 ) &&
F_82 ( V_32 ) ) {
F_247 ( L_71 ,
V_32 -> V_136 ) ;
return - V_406 ;
}
V_405 = F_84 ( V_32 ) - 1 ;
if ( V_405 >= 0 && ! ( F_85 ( V_32 -> V_71 ) & ( 1 << V_405 ) ) ) {
F_247 ( L_72 ,
V_32 -> V_136 ) ;
return - V_406 ;
}
if ( V_32 -> V_144 & V_192 )
F_168 ( V_32 ) ;
V_75 [ V_32 -> V_185 ] = V_32 ;
V_83 = F_169 ( V_32 ) ;
if ( V_83 == 0 )
V_83 = F_121 ( V_32 ) ;
if ( V_83 )
goto V_104;
#ifdef F_148
if ( V_175 ( V_32 ) )
F_296 ( V_32 ) ;
#endif
if ( V_404 -> V_332 ) {
if ( V_333 )
F_166 ( V_32 ) ;
return 0 ;
}
F_279 ( V_32 ) ;
F_129 ( V_32 ) ;
#ifdef F_148
if ( V_175 ( V_32 ) && F_182 ( V_32 -> V_81 ) ) {
V_83 = F_300 ( V_32 ) ;
if ( V_83 )
goto V_407;
}
#endif
V_83 = F_301 ( V_32 ) ;
if ( V_83 )
goto V_407;
F_123 ( V_32 ) ;
V_32 -> V_186 . V_230 ( V_32 , 0 , 0 , 0 , V_153 ) ;
V_32 -> V_186 . V_187 ( V_32 , 0 , 0 , 0 , V_162 ) ;
F_167 ( V_32 ) ;
F_166 ( V_32 ) ;
return 0 ;
V_407:
F_177 ( V_32 ) ;
V_104:
F_181 ( V_32 ) ;
return V_83 ;
}
int F_376 ( struct V_76 * V_404 , bool V_408 )
{
int V_83 = 0 ;
struct V_31 * V_32 = V_404 -> V_32 ;
if ( ! V_402 )
return 0 ;
if ( V_32 == NULL )
return - V_44 ;
if ( V_408 ) {
V_83 = F_375 ( V_404 ) ;
} else {
F_177 ( V_32 ) ;
F_181 ( V_32 ) ;
}
return V_83 ;
}
static void F_377 ( void )
{
struct V_278 * V_392 , * V_409 ;
struct V_396 * V_399 , * V_410 ;
F_178 (rmrru, rmrr_n, &dmar_rmrr_units, list) {
F_232 ( & V_392 -> V_394 ) ;
F_370 ( & V_392 -> V_103 , & V_392 -> V_374 ) ;
F_175 ( V_392 ) ;
}
F_178 (atsru, atsr_n, &dmar_atsr_units, list) {
F_232 ( & V_399 -> V_394 ) ;
F_369 ( V_399 ) ;
}
}
int F_239 ( struct V_99 * V_95 )
{
int V_79 , V_83 = 1 ;
struct V_411 * V_87 ;
struct V_99 * V_412 = NULL ;
struct V_94 * V_98 ;
struct V_397 * V_398 ;
struct V_396 * V_399 ;
V_95 = F_378 ( V_95 ) ;
for ( V_87 = V_95 -> V_87 ; V_87 ; V_87 = V_87 -> V_115 ) {
V_412 = V_87 -> V_413 ;
if ( ! V_412 )
return 1 ;
if ( ! F_270 ( V_412 ) ||
F_272 ( V_412 ) == V_292 )
return 0 ;
if ( F_272 ( V_412 ) == V_414 )
break;
}
F_79 () ;
F_366 (atsru, &dmar_atsr_units, list) {
V_398 = F_46 ( V_399 -> V_393 , struct V_397 , V_389 ) ;
if ( V_398 -> V_102 != F_97 ( V_95 -> V_87 ) )
continue;
F_379 (atsru->devices, atsru->devices_cnt, i, tmp)
if ( V_98 == & V_412 -> V_95 )
goto V_104;
if ( V_399 -> V_110 )
goto V_104;
}
V_83 = 0 ;
V_104:
F_81 () ;
return V_83 ;
}
int F_380 ( struct V_415 * V_168 )
{
int V_83 = 0 ;
struct V_278 * V_392 ;
struct V_396 * V_399 ;
struct V_397 * V_398 ;
struct V_391 * V_279 ;
if ( ! V_402 && V_400 != V_401 )
return 0 ;
F_145 (rmrru, &dmar_rmrr_units, list) {
V_279 = F_46 ( V_392 -> V_393 ,
struct V_391 , V_389 ) ;
if ( V_168 -> V_416 == V_417 ) {
V_83 = F_381 ( V_168 , ( void * ) ( V_279 + 1 ) ,
( ( void * ) V_279 ) + V_279 -> V_389 . V_254 ,
V_279 -> V_102 , V_392 -> V_103 ,
V_392 -> V_374 ) ;
if( V_83 < 0 )
return V_83 ;
} else if ( V_168 -> V_416 == V_418 ) {
F_382 ( V_168 , V_279 -> V_102 ,
V_392 -> V_103 , V_392 -> V_374 ) ;
}
}
F_145 (atsru, &dmar_atsr_units, list) {
if ( V_399 -> V_110 )
continue;
V_398 = F_46 ( V_399 -> V_393 , struct V_397 , V_389 ) ;
if ( V_168 -> V_416 == V_417 ) {
V_83 = F_381 ( V_168 , ( void * ) ( V_398 + 1 ) ,
( void * ) V_398 + V_398 -> V_389 . V_254 ,
V_398 -> V_102 , V_399 -> V_103 ,
V_399 -> V_374 ) ;
if ( V_83 > 0 )
break;
else if( V_83 < 0 )
return V_83 ;
} else if ( V_168 -> V_416 == V_418 ) {
if ( F_382 ( V_168 , V_398 -> V_102 ,
V_399 -> V_103 , V_399 -> V_374 ) )
break;
}
}
return 0 ;
}
static int F_383 ( struct V_419 * V_420 ,
unsigned long V_421 , void * V_235 )
{
struct V_94 * V_95 = V_235 ;
struct V_39 * V_42 ;
if ( F_93 ( V_95 ) )
return 0 ;
if ( V_421 != V_418 )
return 0 ;
V_42 = F_234 ( V_95 ) ;
if ( ! V_42 )
return 0 ;
F_179 ( V_42 , V_95 ) ;
if ( ! F_67 ( V_42 ) && F_384 ( & V_42 -> V_103 ) )
F_180 ( V_42 ) ;
return 0 ;
}
static int F_385 ( struct V_419 * V_420 ,
unsigned long V_29 , void * V_422 )
{
struct V_423 * V_424 = V_422 ;
unsigned long long V_217 , V_108 ;
unsigned long V_366 , V_272 ;
switch ( V_29 ) {
case V_425 :
V_217 = V_424 -> V_126 << V_11 ;
V_108 = ( ( V_424 -> V_126 + V_424 -> V_247 ) << V_11 ) - 1 ;
if ( F_245 ( V_273 , V_217 , V_108 ) ) {
F_247 ( L_73 ,
V_217 , V_108 ) ;
return V_426 ;
}
break;
case V_427 :
case V_428 :
V_366 = F_13 ( V_424 -> V_126 ) ;
V_272 = F_13 ( V_424 -> V_126 + V_424 -> V_247 - 1 ) ;
while ( V_366 <= V_272 ) {
struct V_204 * V_204 ;
struct V_76 * V_77 ;
struct V_31 * V_32 ;
struct V_14 * V_133 ;
V_204 = F_386 ( & V_273 -> V_218 , V_366 ) ;
if ( V_204 == NULL ) {
F_142 ( L_74 ,
V_366 ) ;
break;
}
V_204 = F_387 ( & V_273 -> V_218 , V_204 ,
V_366 , V_272 ) ;
if ( V_204 == NULL ) {
F_247 ( L_75 ,
V_366 , V_272 ) ;
return V_426 ;
}
V_133 = F_119 ( V_273 , V_204 -> V_429 ,
V_204 -> V_430 ) ;
F_79 () ;
F_80 (iommu, drhd)
F_160 ( V_32 , V_273 ,
V_204 -> V_429 , F_388 ( V_204 ) ,
! V_133 , 0 ) ;
F_81 () ;
F_120 ( V_133 ) ;
V_366 = V_204 -> V_430 + 1 ;
F_389 ( V_204 ) ;
}
break;
}
return V_431 ;
}
static void F_390 ( unsigned int V_222 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_74 ; V_79 ++ ) {
struct V_31 * V_32 = V_75 [ V_79 ] ;
struct V_39 * V_42 ;
int V_55 ;
if ( ! V_32 )
continue;
for ( V_55 = 0 ; V_55 < F_170 ( V_32 -> V_71 ) ; V_55 ++ ) {
V_42 = F_50 ( V_32 , ( T_4 ) V_55 ) ;
if ( ! V_42 )
continue;
F_391 ( V_222 , & V_42 -> V_218 ) ;
}
}
}
static int F_392 ( struct V_419 * V_432 ,
unsigned long V_421 , void * V_422 )
{
unsigned int V_222 = ( unsigned long ) V_422 ;
switch ( V_421 ) {
case V_433 :
case V_434 :
F_390 ( V_222 ) ;
F_204 ( V_222 ) ;
break;
}
return V_431 ;
}
static T_9 F_393 ( struct V_94 * V_95 ,
struct V_435 * V_436 ,
char * V_437 )
{
struct V_31 * V_32 = F_394 ( V_95 ) ;
T_2 V_438 = F_44 ( V_32 -> V_36 + V_439 ) ;
return sprintf ( V_437 , L_76 ,
F_395 ( V_438 ) , F_396 ( V_438 ) ) ;
}
static T_9 F_397 ( struct V_94 * V_95 ,
struct V_435 * V_436 ,
char * V_437 )
{
struct V_31 * V_32 = F_394 ( V_95 ) ;
return sprintf ( V_437 , L_77 , V_32 -> V_440 ) ;
}
static T_9 F_398 ( struct V_94 * V_95 ,
struct V_435 * V_436 ,
char * V_437 )
{
struct V_31 * V_32 = F_394 ( V_95 ) ;
return sprintf ( V_437 , L_77 , V_32 -> V_71 ) ;
}
static T_9 F_399 ( struct V_94 * V_95 ,
struct V_435 * V_436 ,
char * V_437 )
{
struct V_31 * V_32 = F_394 ( V_95 ) ;
return sprintf ( V_437 , L_77 , V_32 -> V_81 ) ;
}
static T_9 F_400 ( struct V_94 * V_95 ,
struct V_435 * V_436 ,
char * V_437 )
{
struct V_31 * V_32 = F_394 ( V_95 ) ;
return sprintf ( V_437 , L_78 , F_170 ( V_32 -> V_71 ) ) ;
}
static T_9 F_401 ( struct V_94 * V_95 ,
struct V_435 * V_436 ,
char * V_437 )
{
struct V_31 * V_32 = F_394 ( V_95 ) ;
return sprintf ( V_437 , L_79 , F_402 ( V_32 -> V_195 ,
F_170 ( V_32 -> V_71 ) ) ) ;
}
int T_3 F_403 ( void )
{
int V_83 = - V_212 ;
struct V_76 * V_77 ;
struct V_31 * V_32 ;
V_333 = F_404 () ;
if ( F_342 () ) {
if ( V_333 )
F_360 ( L_80 ) ;
return - V_137 ;
}
F_405 ( & V_441 ) ;
if ( F_406 () ) {
if ( V_333 )
F_360 ( L_81 ) ;
goto V_442;
}
if ( F_407 () < 0 ) {
if ( V_333 )
F_360 ( L_82 ) ;
goto V_442;
}
if ( V_443 || V_45 )
goto V_442;
if ( F_384 ( & V_395 ) )
F_48 ( L_83 ) ;
if ( F_384 ( & V_403 ) )
F_48 ( L_84 ) ;
if ( F_191 () ) {
if ( V_333 )
F_360 ( L_85 ) ;
goto V_444;
}
F_353 () ;
V_83 = F_289 () ;
if ( V_83 ) {
if ( V_333 )
F_360 ( L_86 ) ;
F_122 ( L_87 ) ;
goto V_444;
}
F_408 ( & V_441 ) ;
F_48 ( L_88 ) ;
#ifdef F_409
V_445 = 0 ;
#endif
V_446 = & V_447 ;
F_361 () ;
F_80 (iommu, drhd)
V_32 -> V_448 = F_410 ( NULL , V_32 ,
V_449 ,
L_89 , V_32 -> V_136 ) ;
F_411 ( & V_450 , & V_451 ) ;
F_412 ( & V_450 , & V_452 ) ;
if ( V_273 && ! V_225 )
F_413 ( & V_453 ) ;
F_414 ( & V_454 ) ;
V_402 = 1 ;
return 0 ;
V_444:
F_206 ( & V_205 ) ;
V_442:
F_377 () ;
F_408 ( & V_441 ) ;
F_346 () ;
return V_83 ;
}
static int F_415 ( struct V_99 * V_101 , T_4 V_232 , void * V_233 )
{
struct V_31 * V_32 = V_233 ;
F_230 ( V_32 , F_213 ( V_232 ) , V_232 & 0xff ) ;
return 0 ;
}
static void F_416 ( struct V_31 * V_32 , struct V_94 * V_95 )
{
if ( ! V_32 || ! V_95 || ! F_95 ( V_95 ) )
return;
F_215 ( F_96 ( V_95 ) , & F_415 , V_32 ) ;
}
static void F_233 ( struct V_167 * V_168 )
{
struct V_31 * V_32 ;
unsigned long V_33 ;
F_144 ( & V_169 ) ;
if ( F_53 ( ! V_168 ) )
return;
V_32 = V_168 -> V_32 ;
if ( V_168 -> V_95 ) {
F_154 ( V_168 ) ;
F_416 ( V_32 , V_168 -> V_95 ) ;
}
F_231 ( V_168 ) ;
F_104 ( & V_32 -> V_112 , V_33 ) ;
F_189 ( V_168 -> V_42 , V_32 ) ;
F_105 ( & V_32 -> V_112 , V_33 ) ;
F_64 ( V_168 ) ;
}
static void F_179 ( struct V_39 * V_42 ,
struct V_94 * V_95 )
{
struct V_167 * V_168 ;
unsigned long V_33 ;
F_104 ( & V_169 , V_33 ) ;
V_168 = V_95 -> V_96 . V_32 ;
F_233 ( V_168 ) ;
F_105 ( & V_169 , V_33 ) ;
}
static int F_256 ( struct V_39 * V_42 , int V_219 )
{
int V_220 ;
F_192 ( & V_42 -> V_218 , V_121 , V_206 ,
V_207 ) ;
F_197 ( V_42 ) ;
V_42 -> V_132 = V_219 ;
V_220 = F_199 ( V_219 ) ;
V_42 -> V_1 = F_4 ( V_220 ) ;
V_42 -> V_80 = 0 ;
V_42 -> V_85 = 0 ;
V_42 -> V_86 = 0 ;
V_42 -> V_455 = 0 ;
V_42 -> V_117 = (struct V_27 * ) F_54 ( V_42 -> V_120 ) ;
if ( ! V_42 -> V_117 )
return - V_137 ;
F_101 ( V_42 , V_42 -> V_117 , V_221 ) ;
return 0 ;
}
static struct V_40 * F_417 ( unsigned type )
{
struct V_39 * V_39 ;
struct V_40 * V_42 ;
if ( type != V_456 )
return NULL ;
V_39 = F_185 ( V_65 ) ;
if ( ! V_39 ) {
F_122 ( L_90 ) ;
return NULL ;
}
if ( F_256 ( V_39 , V_72 ) ) {
F_122 ( L_91 ) ;
F_180 ( V_39 ) ;
return NULL ;
}
F_87 ( V_39 ) ;
V_42 = & V_39 -> V_42 ;
V_42 -> V_457 . V_458 = 0 ;
V_42 -> V_457 . V_459 = F_418 ( V_39 -> V_132 ) ;
V_42 -> V_457 . V_460 = true ;
return V_42 ;
}
static void F_419 ( struct V_40 * V_42 )
{
F_180 ( F_45 ( V_42 ) ) ;
}
static int F_420 ( struct V_40 * V_42 ,
struct V_94 * V_95 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_31 * V_32 ;
int V_67 ;
T_6 V_87 , V_88 ;
if ( F_265 ( V_95 ) ) {
F_421 ( V_95 , L_92 ) ;
return - V_461 ;
}
if ( F_306 ( F_217 ( V_95 ) ) ) {
struct V_39 * V_462 ;
V_462 = F_234 ( V_95 ) ;
if ( V_462 ) {
F_79 () ;
F_179 ( V_462 , V_95 ) ;
F_81 () ;
if ( ! F_67 ( V_462 ) &&
F_384 ( & V_462 -> V_103 ) )
F_180 ( V_462 ) ;
}
}
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_212 ;
V_67 = F_2 ( V_32 -> V_1 ) ;
if ( V_67 > F_201 ( V_32 -> V_71 ) )
V_67 = F_201 ( V_32 -> V_71 ) ;
if ( V_39 -> V_455 > ( 1LL << V_67 ) ) {
F_122 ( L_93
L_94 ,
V_463 , V_67 , V_39 -> V_455 ) ;
return - V_284 ;
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
return F_262 ( V_39 , V_95 ) ;
}
static void F_422 ( struct V_40 * V_42 ,
struct V_94 * V_95 )
{
F_179 ( F_45 ( V_42 ) , V_95 ) ;
}
static int F_423 ( struct V_40 * V_42 ,
unsigned long V_204 , T_1 V_464 ,
T_5 V_58 , int V_465 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
V_24 V_455 ;
int V_248 = 0 ;
int V_83 ;
if ( V_465 & V_466 )
V_248 |= V_122 ;
if ( V_465 & V_467 )
V_248 |= V_123 ;
if ( ( V_465 & V_468 ) && V_39 -> V_85 )
V_248 |= V_253 ;
V_455 = V_204 + V_58 ;
if ( V_39 -> V_455 < V_455 ) {
V_24 V_108 ;
V_108 = F_418 ( V_39 -> V_132 ) + 1 ;
if ( V_108 < V_455 ) {
F_122 ( L_93
L_94 ,
V_463 , V_39 -> V_132 , V_455 ) ;
return - V_284 ;
}
V_39 -> V_455 = V_455 ;
}
V_58 = F_218 ( V_464 , V_58 ) ;
V_83 = F_229 ( V_39 , V_204 >> V_12 ,
V_464 >> V_12 , V_58 , V_248 ) ;
return V_83 ;
}
static T_5 F_424 ( struct V_40 * V_42 ,
unsigned long V_204 , T_5 V_58 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_14 * V_133 = NULL ;
struct V_31 * V_32 ;
unsigned long V_126 , V_127 ;
unsigned int V_469 ;
int V_73 , V_5 = 0 ;
F_75 ( ! F_108 ( V_39 , V_204 >> V_12 , & V_5 ) ) ;
if ( V_58 < V_121 << F_6 ( V_5 ) )
V_58 = V_121 << F_6 ( V_5 ) ;
V_126 = V_204 >> V_12 ;
V_127 = ( V_204 + V_58 - 1 ) >> V_12 ;
V_133 = F_119 ( V_39 , V_126 , V_127 ) ;
V_469 = V_127 - V_126 + 1 ;
F_76 (iommu_id, dmar_domain) {
V_32 = V_75 [ V_73 ] ;
F_160 ( V_75 [ V_73 ] , V_39 ,
V_126 , V_469 , ! V_133 , 0 ) ;
}
F_120 ( V_133 ) ;
if ( V_39 -> V_455 == V_204 + V_58 )
V_39 -> V_455 = V_204 ;
return V_58 ;
}
static T_1 F_425 ( struct V_40 * V_42 ,
V_256 V_204 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_27 * V_28 ;
int V_5 = 0 ;
V_24 V_470 = 0 ;
V_28 = F_108 ( V_39 , V_204 >> V_12 , & V_5 ) ;
if ( V_28 )
V_470 = F_35 ( V_28 ) ;
return V_470 ;
}
static bool F_426 ( enum V_471 V_71 )
{
if ( V_71 == V_472 )
return F_82 ( NULL ) == 1 ;
if ( V_71 == V_473 )
return V_474 == 1 ;
return false ;
}
static int F_427 ( struct V_94 * V_95 )
{
struct V_31 * V_32 ;
struct V_475 * V_476 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_212 ;
F_428 ( V_32 -> V_448 , V_95 ) ;
V_476 = F_429 ( V_95 ) ;
if ( F_430 ( V_476 ) )
return F_431 ( V_476 ) ;
F_432 ( V_476 ) ;
return 0 ;
}
static void F_433 ( struct V_94 * V_95 )
{
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return;
F_434 ( V_95 ) ;
F_435 ( V_32 -> V_448 , V_95 ) ;
}
int F_436 ( struct V_31 * V_32 , struct V_477 * V_478 )
{
struct V_167 * V_168 ;
struct V_22 * V_23 ;
struct V_39 * V_42 ;
unsigned long V_33 ;
V_24 V_479 ;
int V_83 ;
V_42 = F_309 ( V_478 -> V_95 ) ;
if ( ! V_42 )
return - V_44 ;
F_104 ( & V_169 , V_33 ) ;
F_210 ( & V_32 -> V_112 ) ;
V_83 = - V_44 ;
V_168 = V_478 -> V_95 -> V_96 . V_32 ;
if ( ! V_168 || ! V_168 -> V_174 )
goto V_104;
V_23 = F_88 ( V_32 , V_168 -> V_87 , V_168 -> V_88 , 0 ) ;
if ( F_53 ( ! V_23 ) )
goto V_104;
V_479 = V_23 [ 0 ] . V_19 ;
V_478 -> V_55 = V_42 -> V_184 [ V_32 -> V_185 ] ;
V_478 -> V_179 = F_437 ( V_168 -> V_87 , V_168 -> V_88 ) ;
if ( ! ( V_479 & V_480 ) ) {
V_23 [ 1 ] . V_21 = ( V_24 ) F_92 ( V_32 -> V_481 ) ;
V_23 [ 1 ] . V_19 = ( V_24 ) F_92 ( V_32 -> V_482 ) | F_438 ( V_32 -> V_81 ) ;
F_439 () ;
if ( ( V_479 & V_483 ) == ( V_226 << 2 ) ) {
V_479 &= ~ V_483 ;
if ( V_168 -> V_171 )
V_479 |= V_484 << 2 ;
else
V_479 |= V_485 << 2 ;
}
V_479 |= V_480 ;
if ( V_32 -> V_481 )
V_479 |= V_486 ;
if ( V_168 -> V_176 )
V_479 |= V_487 ;
V_23 [ 0 ] . V_19 = V_479 ;
F_439 () ;
V_32 -> V_186 . V_230 ( V_32 , V_478 -> V_55 , V_478 -> V_179 ,
V_231 ,
V_155 ) ;
}
if ( ! V_168 -> V_175 )
F_147 ( V_168 ) ;
if ( V_168 -> V_173 ) {
V_478 -> V_488 = 1 ;
V_478 -> V_180 = V_168 -> V_178 ;
if ( V_478 -> V_180 >= V_489 )
V_478 -> V_180 = 0 ;
}
V_83 = 0 ;
V_104:
F_211 ( & V_32 -> V_112 ) ;
F_105 ( & V_169 , V_33 ) ;
return V_83 ;
}
struct V_31 * F_440 ( struct V_94 * V_95 )
{
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
if ( F_93 ( V_95 ) ) {
F_421 ( V_95 ,
L_95 ) ;
return NULL ;
}
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ( ! V_32 ) ) {
F_308 ( V_95 , L_96 ) ;
return NULL ;
}
if ( ! V_32 -> V_482 ) {
F_308 ( V_95 , L_97 ) ;
return NULL ;
}
return V_32 ;
}
static void F_441 ( struct V_99 * V_95 )
{
F_48 ( L_98 ) ;
V_46 = 0 ;
}
static void F_442 ( struct V_99 * V_95 )
{
F_48 ( L_99 ) ;
V_148 = 1 ;
}
static void F_443 ( struct V_99 * V_95 )
{
unsigned short V_490 ;
if ( F_444 ( V_95 , V_491 , & V_490 ) )
return;
if ( ! ( V_490 & V_492 ) ) {
F_48 ( L_100 ) ;
V_46 = 0 ;
} else if ( V_46 ) {
F_48 ( L_101 ) ;
V_48 = 1 ;
}
}
static void T_3 F_298 ( void )
{
struct V_99 * V_101 ;
T_10 V_493 ;
V_101 = F_445 ( V_494 , 0x3a3e , NULL ) ;
if ( ! V_101 )
return;
F_254 ( V_101 ) ;
V_101 = F_445 ( V_494 , 0x342e , NULL ) ;
if ( ! V_101 )
return;
if ( F_446 ( V_101 , 0x188 , & V_493 ) ) {
F_254 ( V_101 ) ;
return;
}
F_254 ( V_101 ) ;
if ( V_493 & 1 )
return;
V_493 &= 0x1c ;
if ( V_493 == 0x10 )
return;
if ( ! V_493 ) {
F_248 ( 1 , L_102
L_36 ,
F_249 ( V_274 ) ,
F_249 ( V_275 ) ,
F_249 ( V_276 ) ) ;
V_53 |= V_288 ;
return;
}
F_247 ( L_103 ,
V_493 ) ;
}
