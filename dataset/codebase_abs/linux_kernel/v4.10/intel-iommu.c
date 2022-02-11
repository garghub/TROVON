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
struct V_99 * V_103 ;
V_101 = F_96 ( V_95 ) ;
V_103 = F_97 ( V_101 ) ;
V_95 = & V_103 -> V_95 ;
V_102 = F_98 ( V_101 -> V_87 ) ;
} else if ( F_99 ( V_95 ) )
V_95 = & F_100 ( V_95 ) -> V_95 ;
F_79 () ;
F_80 (iommu, drhd) {
if ( V_101 && V_102 != V_77 -> V_102 )
continue;
F_101 (drhd->devices,
drhd->devices_cnt, i, tmp) {
if ( V_98 == V_95 ) {
if ( V_101 -> V_104 )
goto V_105;
* V_87 = V_77 -> V_106 [ V_79 ] . V_87 ;
* V_88 = V_77 -> V_106 [ V_79 ] . V_88 ;
goto V_107;
}
if ( ! V_101 || ! F_95 ( V_98 ) )
continue;
V_100 = F_96 ( V_98 ) ;
if ( V_100 -> V_108 &&
V_100 -> V_108 -> V_109 <= V_101 -> V_87 -> V_109 &&
V_100 -> V_108 -> V_110 . V_111 >= V_101 -> V_87 -> V_109 )
goto V_105;
}
if ( V_101 && V_77 -> V_112 ) {
V_105:
* V_87 = V_101 -> V_87 -> V_109 ;
* V_88 = V_101 -> V_88 ;
goto V_107;
}
}
V_32 = NULL ;
V_107:
F_81 () ;
return V_32 ;
}
static void F_102 ( struct V_39 * V_42 ,
void * V_113 , int V_58 )
{
if ( ! V_42 -> V_80 )
F_103 ( V_113 , V_58 ) ;
}
static int F_104 ( struct V_31 * V_32 , T_6 V_87 , T_6 V_88 )
{
struct V_22 * V_23 ;
int V_83 = 0 ;
unsigned long V_33 ;
F_105 ( & V_32 -> V_114 , V_33 ) ;
V_23 = F_88 ( V_32 , V_87 , V_88 , 0 ) ;
if ( V_23 )
V_83 = F_25 ( V_23 ) ;
F_106 ( & V_32 -> V_114 , V_33 ) ;
return V_83 ;
}
static void F_107 ( struct V_31 * V_32 , T_6 V_87 , T_6 V_88 )
{
struct V_22 * V_23 ;
unsigned long V_33 ;
F_105 ( & V_32 -> V_114 , V_33 ) ;
V_23 = F_88 ( V_32 , V_87 , V_88 , 0 ) ;
if ( V_23 ) {
F_33 ( V_23 ) ;
F_91 ( V_32 , V_23 , sizeof( * V_23 ) ) ;
}
F_106 ( & V_32 -> V_114 , V_33 ) ;
}
static void F_108 ( struct V_31 * V_32 )
{
int V_79 ;
unsigned long V_33 ;
struct V_22 * V_23 ;
F_105 ( & V_32 -> V_114 , V_33 ) ;
if ( ! V_32 -> V_17 ) {
goto V_107;
}
for ( V_79 = 0 ; V_79 < V_115 ; V_79 ++ ) {
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
V_107:
F_106 ( & V_32 -> V_114 , V_33 ) ;
}
static struct V_27 * F_109 ( struct V_39 * V_42 ,
unsigned long V_6 , int * V_116 )
{
struct V_27 * V_117 , * V_28 = NULL ;
int V_5 = F_1 ( V_42 -> V_1 ) ;
int V_118 ;
F_75 ( ! V_42 -> V_119 ) ;
if ( ! F_68 ( V_42 , V_6 ) )
return NULL ;
V_117 = V_42 -> V_119 ;
while ( 1 ) {
void * V_120 ;
V_118 = F_7 ( V_6 , V_5 ) ;
V_28 = & V_117 [ V_118 ] ;
if ( ! * V_116 && ( F_39 ( V_28 ) || ! F_38 ( V_28 ) ) )
break;
if ( V_5 == * V_116 )
break;
if ( ! F_38 ( V_28 ) ) {
T_7 V_121 ;
V_120 = F_54 ( V_42 -> V_122 ) ;
if ( ! V_120 )
return NULL ;
F_102 ( V_42 , V_120 , V_123 ) ;
V_121 = ( ( T_7 ) F_16 ( V_120 ) << V_12 ) | V_124 | V_125 ;
if ( F_110 ( & V_28 -> V_29 , 0ULL , V_121 ) )
F_57 ( V_120 ) ;
else
F_102 ( V_42 , V_28 , sizeof( * V_28 ) ) ;
}
if ( V_5 == 1 )
break;
V_117 = F_90 ( F_35 ( V_28 ) ) ;
V_5 -- ;
}
if ( ! * V_116 )
* V_116 = V_5 ;
return V_28 ;
}
static struct V_27 * F_111 ( struct V_39 * V_42 ,
unsigned long V_6 ,
int V_5 , int * V_126 )
{
struct V_27 * V_117 , * V_28 = NULL ;
int V_127 = F_1 ( V_42 -> V_1 ) ;
int V_118 ;
V_117 = V_42 -> V_119 ;
while ( V_5 <= V_127 ) {
V_118 = F_7 ( V_6 , V_127 ) ;
V_28 = & V_117 [ V_118 ] ;
if ( V_5 == V_127 )
return V_28 ;
if ( ! F_38 ( V_28 ) ) {
* V_126 = V_127 ;
break;
}
if ( F_39 ( V_28 ) ) {
* V_126 = V_127 ;
return V_28 ;
}
V_117 = F_90 ( F_35 ( V_28 ) ) ;
V_127 -- ;
}
return NULL ;
}
static void F_112 ( struct V_39 * V_42 ,
unsigned long V_128 ,
unsigned long V_129 )
{
unsigned int V_126 = 1 ;
struct V_27 * V_130 , * V_28 ;
F_75 ( ! F_68 ( V_42 , V_128 ) ) ;
F_75 ( ! F_68 ( V_42 , V_129 ) ) ;
F_75 ( V_128 > V_129 ) ;
do {
V_126 = 1 ;
V_130 = V_28 = F_111 ( V_42 , V_128 , 1 , & V_126 ) ;
if ( ! V_28 ) {
V_128 = F_10 ( V_128 + 1 , V_126 + 1 ) ;
continue;
}
do {
F_34 ( V_28 ) ;
V_128 += F_11 ( V_126 ) ;
V_28 ++ ;
} while ( V_128 <= V_129 && ! F_40 ( V_28 ) );
F_102 ( V_42 , V_130 ,
( void * ) V_28 - ( void * ) V_130 ) ;
} while ( V_128 && V_128 <= V_129 );
}
static void F_113 ( struct V_39 * V_42 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_128 , unsigned long V_129 )
{
V_6 = F_114 ( V_128 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_131 ;
struct V_27 * V_132 ;
if ( ! F_38 ( V_28 ) || F_39 ( V_28 ) )
goto V_133;
V_131 = V_6 & F_8 ( V_5 - 1 ) ;
V_132 = F_90 ( F_35 ( V_28 ) ) ;
if ( V_5 > 2 )
F_113 ( V_42 , V_5 - 1 , V_132 ,
V_131 , V_128 , V_129 ) ;
if ( ! ( V_128 > V_131 ||
V_129 < V_131 + F_9 ( V_5 ) - 1 ) ) {
F_34 ( V_28 ) ;
F_102 ( V_42 , V_28 , sizeof( * V_28 ) ) ;
F_57 ( V_132 ) ;
}
V_133:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_40 ( ++ V_28 ) && V_6 <= V_129 );
}
static void F_115 ( struct V_39 * V_42 ,
unsigned long V_128 ,
unsigned long V_129 )
{
F_75 ( ! F_68 ( V_42 , V_128 ) ) ;
F_75 ( ! F_68 ( V_42 , V_129 ) ) ;
F_75 ( V_128 > V_129 ) ;
F_112 ( V_42 , V_128 , V_129 ) ;
F_113 ( V_42 , F_1 ( V_42 -> V_1 ) ,
V_42 -> V_119 , 0 , V_128 , V_129 ) ;
if ( V_128 == 0 && V_129 == F_116 ( V_42 -> V_134 ) ) {
F_57 ( V_42 -> V_119 ) ;
V_42 -> V_119 = NULL ;
}
}
static struct V_14 * F_117 ( struct V_39 * V_42 ,
int V_5 , struct V_27 * V_28 ,
struct V_14 * V_135 )
{
struct V_14 * V_15 ;
V_15 = F_118 ( F_35 ( V_28 ) >> V_11 ) ;
V_15 -> V_135 = V_135 ;
V_135 = V_15 ;
if ( V_5 == 1 )
return V_135 ;
V_28 = F_56 ( V_15 ) ;
do {
if ( F_38 ( V_28 ) && ! F_39 ( V_28 ) )
V_135 = F_117 ( V_42 , V_5 - 1 ,
V_28 , V_135 ) ;
V_28 ++ ;
} while ( ! F_40 ( V_28 ) );
return V_135 ;
}
static struct V_14 * F_119 ( struct V_39 * V_42 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_128 ,
unsigned long V_129 ,
struct V_14 * V_135 )
{
struct V_27 * V_130 = NULL , * V_136 = NULL ;
V_6 = F_114 ( V_128 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_131 ;
if ( ! F_38 ( V_28 ) )
goto V_133;
V_131 = V_6 & F_8 ( V_5 ) ;
if ( V_128 <= V_131 &&
V_129 >= V_131 + F_9 ( V_5 ) - 1 ) {
if ( V_5 > 1 && ! F_39 ( V_28 ) )
V_135 = F_117 ( V_42 , V_5 - 1 , V_28 , V_135 ) ;
F_34 ( V_28 ) ;
if ( ! V_130 )
V_130 = V_28 ;
V_136 = V_28 ;
} else if ( V_5 > 1 ) {
V_135 = F_119 ( V_42 , V_5 - 1 ,
F_90 ( F_35 ( V_28 ) ) ,
V_131 , V_128 , V_129 ,
V_135 ) ;
}
V_133:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_40 ( ++ V_28 ) && V_6 <= V_129 );
if ( V_130 )
F_102 ( V_42 , V_130 ,
( void * ) ++ V_136 - ( void * ) V_130 ) ;
return V_135 ;
}
static struct V_14 * F_120 ( struct V_39 * V_42 ,
unsigned long V_128 ,
unsigned long V_129 )
{
struct V_14 * V_135 = NULL ;
F_75 ( ! F_68 ( V_42 , V_128 ) ) ;
F_75 ( ! F_68 ( V_42 , V_129 ) ) ;
F_75 ( V_128 > V_129 ) ;
V_135 = F_119 ( V_42 , F_1 ( V_42 -> V_1 ) ,
V_42 -> V_119 , 0 , V_128 , V_129 , NULL ) ;
if ( V_128 == 0 && V_129 == F_116 ( V_42 -> V_134 ) ) {
struct V_14 * V_137 = F_17 ( V_42 -> V_119 ) ;
V_137 -> V_135 = V_135 ;
V_135 = V_137 ;
V_42 -> V_119 = NULL ;
}
return V_135 ;
}
static void F_121 ( struct V_14 * V_135 )
{
struct V_14 * V_15 ;
while ( ( V_15 = V_135 ) ) {
V_135 = V_15 -> V_135 ;
F_57 ( F_56 ( V_15 ) ) ;
}
}
static int F_122 ( struct V_31 * V_32 )
{
struct V_17 * V_90 ;
unsigned long V_33 ;
V_90 = (struct V_17 * ) F_54 ( V_32 -> V_60 ) ;
if ( ! V_90 ) {
F_123 ( L_18 ,
V_32 -> V_138 ) ;
return - V_139 ;
}
F_91 ( V_32 , V_90 , V_140 ) ;
F_105 ( & V_32 -> V_114 , V_33 ) ;
V_32 -> V_17 = V_90 ;
F_106 ( & V_32 -> V_114 , V_33 ) ;
return 0 ;
}
static void F_124 ( struct V_31 * V_32 )
{
V_24 V_113 ;
T_2 V_141 ;
unsigned long V_142 ;
V_113 = F_92 ( V_32 -> V_17 ) ;
if ( F_89 ( V_32 ) )
V_113 |= V_143 ;
F_125 ( & V_32 -> V_144 , V_142 ) ;
F_126 ( V_32 -> V_36 + V_145 , V_113 ) ;
F_127 ( V_32 -> V_146 | V_147 , V_32 -> V_36 + V_148 ) ;
F_128 ( V_32 , V_37 ,
F_44 , ( V_141 & V_149 ) , V_141 ) ;
F_129 ( & V_32 -> V_144 , V_142 ) ;
}
static void F_130 ( struct V_31 * V_32 )
{
T_2 V_29 ;
unsigned long V_142 ;
if ( ! V_150 && ! F_131 ( V_32 -> V_71 ) )
return;
F_125 ( & V_32 -> V_144 , V_142 ) ;
F_127 ( V_32 -> V_146 | V_151 , V_32 -> V_36 + V_148 ) ;
F_128 ( V_32 , V_37 ,
F_44 , ( ! ( V_29 & V_152 ) ) , V_29 ) ;
F_129 ( & V_32 -> V_144 , V_142 ) ;
}
static void F_132 ( struct V_31 * V_32 ,
T_4 V_55 , T_4 V_153 , T_6 V_154 ,
V_24 type )
{
V_24 V_29 = 0 ;
unsigned long V_142 ;
switch ( type ) {
case V_155 :
V_29 = V_155 ;
break;
case V_156 :
V_29 = V_156 | F_133 ( V_55 ) ;
break;
case V_157 :
V_29 = V_157 | F_133 ( V_55 )
| F_134 ( V_153 ) | F_135 ( V_154 ) ;
break;
default:
F_136 () ;
}
V_29 |= V_158 ;
F_125 ( & V_32 -> V_144 , V_142 ) ;
F_126 ( V_32 -> V_36 + V_159 , V_29 ) ;
F_128 ( V_32 , V_159 ,
V_160 , ( ! ( V_29 & V_158 ) ) , V_29 ) ;
F_129 ( & V_32 -> V_144 , V_142 ) ;
}
static void F_137 ( struct V_31 * V_32 , T_4 V_55 ,
V_24 V_113 , unsigned int V_161 , V_24 type )
{
int V_162 = F_138 ( V_32 -> V_81 ) ;
V_24 V_29 = 0 , V_163 = 0 ;
unsigned long V_142 ;
switch ( type ) {
case V_164 :
V_29 = V_164 | V_165 ;
break;
case V_166 :
V_29 = V_166 | V_165 | F_139 ( V_55 ) ;
break;
case V_167 :
V_29 = V_167 | V_165 | F_139 ( V_55 ) ;
V_163 = V_161 | V_113 ;
break;
default:
F_136 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_140 ( V_32 -> V_71 ) )
V_29 |= V_168 ;
F_125 ( & V_32 -> V_144 , V_142 ) ;
if ( V_163 )
F_126 ( V_32 -> V_36 + V_162 , V_163 ) ;
F_126 ( V_32 -> V_36 + V_162 + 8 , V_29 ) ;
F_128 ( V_32 , V_162 + 8 ,
V_160 , ( ! ( V_29 & V_165 ) ) , V_29 ) ;
F_129 ( & V_32 -> V_144 , V_142 ) ;
if ( F_141 ( V_29 ) == 0 )
F_123 ( L_19 ) ;
if ( F_141 ( V_29 ) != F_142 ( type ) )
F_143 ( L_20 ,
( unsigned long long ) F_142 ( type ) ,
( unsigned long long ) F_141 ( V_29 ) ) ;
}
static struct V_169 *
F_144 ( struct V_39 * V_42 , struct V_31 * V_32 ,
T_6 V_87 , T_6 V_88 )
{
struct V_169 * V_170 ;
F_145 ( & V_171 ) ;
if ( ! V_32 -> V_172 )
return NULL ;
F_146 (info, &domain->devices, link)
if ( V_170 -> V_32 == V_32 && V_170 -> V_87 == V_87 &&
V_170 -> V_88 == V_88 ) {
if ( V_170 -> V_173 && V_170 -> V_95 )
return V_170 ;
break;
}
return NULL ;
}
static void F_147 ( struct V_39 * V_42 )
{
struct V_169 * V_170 ;
bool V_174 = false ;
F_145 ( & V_171 ) ;
F_146 (info, &domain->devices, link) {
struct V_99 * V_101 ;
if ( ! V_170 -> V_95 || ! F_95 ( V_170 -> V_95 ) )
continue;
V_101 = F_96 ( V_170 -> V_95 ) ;
if ( V_101 -> V_175 ) {
V_174 = true ;
break;
}
}
V_42 -> V_174 = V_174 ;
}
static void F_148 ( struct V_169 * V_170 )
{
struct V_99 * V_101 ;
F_145 ( & V_171 ) ;
if ( ! V_170 || ! F_95 ( V_170 -> V_95 ) )
return;
V_101 = F_96 ( V_170 -> V_95 ) ;
#ifdef F_149
if ( V_170 -> V_176 && ! F_150 ( V_101 , V_170 -> V_176 & ~ 1 ) )
V_170 -> V_177 = 1 ;
if ( V_170 -> V_178 && ! F_151 ( V_101 ) && ! F_152 ( V_101 , 32 ) )
V_170 -> V_179 = 1 ;
#endif
if ( V_170 -> V_173 && ! F_153 ( V_101 , V_12 ) ) {
V_170 -> V_175 = 1 ;
F_147 ( V_170 -> V_42 ) ;
V_170 -> V_180 = F_154 ( V_101 ) ;
}
}
static void F_155 ( struct V_169 * V_170 )
{
struct V_99 * V_101 ;
F_145 ( & V_171 ) ;
if ( ! F_95 ( V_170 -> V_95 ) )
return;
V_101 = F_96 ( V_170 -> V_95 ) ;
if ( V_170 -> V_175 ) {
F_156 ( V_101 ) ;
V_170 -> V_175 = 0 ;
F_147 ( V_170 -> V_42 ) ;
}
#ifdef F_149
if ( V_170 -> V_179 ) {
F_157 ( V_101 ) ;
V_170 -> V_179 = 0 ;
}
if ( V_170 -> V_177 ) {
F_158 ( V_101 ) ;
V_170 -> V_177 = 0 ;
}
#endif
}
static void F_159 ( struct V_39 * V_42 ,
V_24 V_113 , unsigned V_84 )
{
T_4 V_181 , V_182 ;
unsigned long V_33 ;
struct V_169 * V_170 ;
if ( ! V_42 -> V_174 )
return;
F_105 ( & V_171 , V_33 ) ;
F_146 (info, &domain->devices, link) {
if ( ! V_170 -> V_175 )
continue;
V_181 = V_170 -> V_87 << 8 | V_170 -> V_88 ;
V_182 = V_170 -> V_180 ;
F_160 ( V_170 -> V_32 , V_181 , V_182 , V_113 , V_84 ) ;
}
F_106 ( & V_171 , V_33 ) ;
}
static void F_161 ( struct V_31 * V_32 ,
struct V_39 * V_42 ,
unsigned long V_6 , unsigned int V_183 ,
int V_184 , int V_185 )
{
unsigned int V_84 = F_162 ( F_163 ( V_183 ) ) ;
T_7 V_113 = ( T_7 ) V_6 << V_12 ;
T_4 V_55 = V_42 -> V_186 [ V_32 -> V_187 ] ;
F_75 ( V_183 == 0 ) ;
if ( V_184 )
V_184 = 1 << 6 ;
if ( ! F_164 ( V_32 -> V_71 ) || V_84 > F_165 ( V_32 -> V_71 ) )
V_32 -> V_188 . V_189 ( V_32 , V_55 , 0 , 0 ,
V_166 ) ;
else
V_32 -> V_188 . V_189 ( V_32 , V_55 , V_113 | V_184 , V_84 ,
V_167 ) ;
if ( ! F_166 ( V_32 -> V_71 ) || ! V_185 )
F_159 ( F_50 ( V_32 , V_55 ) ,
V_113 , V_84 ) ;
}
static void F_167 ( struct V_31 * V_32 )
{
T_2 V_190 ;
unsigned long V_33 ;
F_125 ( & V_32 -> V_144 , V_33 ) ;
V_190 = F_44 ( V_32 -> V_36 + V_191 ) ;
V_190 &= ~ V_192 ;
F_127 ( V_190 , V_32 -> V_36 + V_191 ) ;
F_128 ( V_32 , V_191 ,
F_44 , ! ( V_190 & V_193 ) , V_190 ) ;
F_129 ( & V_32 -> V_144 , V_33 ) ;
}
static void F_168 ( struct V_31 * V_32 )
{
T_2 V_141 ;
unsigned long V_33 ;
F_125 ( & V_32 -> V_144 , V_33 ) ;
V_32 -> V_146 |= V_194 ;
F_127 ( V_32 -> V_146 , V_32 -> V_36 + V_148 ) ;
F_128 ( V_32 , V_37 ,
F_44 , ( V_141 & V_38 ) , V_141 ) ;
F_129 ( & V_32 -> V_144 , V_33 ) ;
}
static void F_169 ( struct V_31 * V_32 )
{
T_2 V_141 ;
unsigned long V_142 ;
F_125 ( & V_32 -> V_144 , V_142 ) ;
V_32 -> V_146 &= ~ V_194 ;
F_127 ( V_32 -> V_146 , V_32 -> V_36 + V_148 ) ;
F_128 ( V_32 , V_37 ,
F_44 , ( ! ( V_141 & V_38 ) ) , V_141 ) ;
F_129 ( & V_32 -> V_144 , V_142 ) ;
}
static int F_170 ( struct V_31 * V_32 )
{
T_2 V_195 , V_196 ;
T_5 V_58 ;
V_195 = F_171 ( V_32 -> V_71 ) ;
F_143 ( L_21 ,
V_32 -> V_138 , V_195 ) ;
V_196 = F_172 ( V_195 ) ;
F_173 ( & V_32 -> V_114 ) ;
V_32 -> V_197 = F_174 ( V_196 , sizeof( unsigned long ) , V_198 ) ;
if ( ! V_32 -> V_197 ) {
F_123 ( L_22 ,
V_32 -> V_138 ) ;
return - V_139 ;
}
V_58 = ( F_175 ( V_195 , 256 ) >> 8 ) * sizeof( struct V_39 * * ) ;
V_32 -> V_56 = F_52 ( V_58 , V_198 ) ;
if ( V_32 -> V_56 ) {
V_58 = 256 * sizeof( struct V_39 * ) ;
V_32 -> V_56 [ 0 ] = F_52 ( V_58 , V_198 ) ;
}
if ( ! V_32 -> V_56 || ! V_32 -> V_56 [ 0 ] ) {
F_123 ( L_23 ,
V_32 -> V_138 ) ;
F_176 ( V_32 -> V_197 ) ;
F_176 ( V_32 -> V_56 ) ;
V_32 -> V_197 = NULL ;
V_32 -> V_56 = NULL ;
return - V_139 ;
}
F_177 ( 0 , V_32 -> V_197 ) ;
return 0 ;
}
static void F_178 ( struct V_31 * V_32 )
{
struct V_169 * V_170 , * V_98 ;
unsigned long V_33 ;
if ( ! V_32 -> V_56 || ! V_32 -> V_197 )
return;
V_199:
F_105 ( & V_171 , V_33 ) ;
F_179 (info, tmp, &device_domain_list, global) {
struct V_39 * V_42 ;
if ( V_170 -> V_32 != V_32 )
continue;
if ( ! V_170 -> V_95 || ! V_170 -> V_42 )
continue;
V_42 = V_170 -> V_42 ;
F_180 ( V_170 ) ;
if ( ! F_67 ( V_42 ) ) {
F_106 ( & V_171 , V_33 ) ;
F_181 ( V_42 ) ;
goto V_199;
}
}
F_106 ( & V_171 , V_33 ) ;
if ( V_32 -> V_146 & V_194 )
F_169 ( V_32 ) ;
}
static void F_182 ( struct V_31 * V_32 )
{
if ( ( V_32 -> V_56 ) && ( V_32 -> V_197 ) ) {
int V_200 = F_175 ( F_171 ( V_32 -> V_71 ) , 256 ) >> 8 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_200 ; V_79 ++ )
F_176 ( V_32 -> V_56 [ V_79 ] ) ;
F_176 ( V_32 -> V_56 ) ;
F_176 ( V_32 -> V_197 ) ;
V_32 -> V_56 = NULL ;
V_32 -> V_197 = NULL ;
}
V_75 [ V_32 -> V_187 ] = NULL ;
F_108 ( V_32 ) ;
#ifdef F_149
if ( V_177 ( V_32 ) ) {
if ( F_183 ( V_32 -> V_81 ) )
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
V_42 -> V_122 = - 1 ;
V_42 -> V_33 = V_33 ;
V_42 -> V_174 = false ;
F_187 ( & V_42 -> V_106 ) ;
return V_42 ;
}
static int F_188 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
unsigned long V_195 ;
int V_201 ;
F_145 ( & V_171 ) ;
F_145 ( & V_32 -> V_114 ) ;
V_42 -> V_202 [ V_32 -> V_187 ] += 1 ;
V_42 -> V_203 += 1 ;
if ( V_42 -> V_202 [ V_32 -> V_187 ] == 1 ) {
V_195 = F_171 ( V_32 -> V_71 ) ;
V_201 = F_189 ( V_32 -> V_197 , V_195 ) ;
if ( V_201 >= V_195 ) {
F_123 ( L_24 , V_32 -> V_138 ) ;
V_42 -> V_202 [ V_32 -> V_187 ] -= 1 ;
V_42 -> V_203 -= 1 ;
return - V_204 ;
}
F_177 ( V_201 , V_32 -> V_197 ) ;
F_51 ( V_32 , V_201 , V_42 ) ;
V_42 -> V_186 [ V_32 -> V_187 ] = V_201 ;
V_42 -> V_122 = V_32 -> V_60 ;
F_87 ( V_42 ) ;
}
return 0 ;
}
static int F_190 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
int V_201 , V_205 = V_206 ;
F_145 ( & V_171 ) ;
F_145 ( & V_32 -> V_114 ) ;
V_42 -> V_202 [ V_32 -> V_187 ] -= 1 ;
V_205 = -- V_42 -> V_203 ;
if ( V_42 -> V_202 [ V_32 -> V_187 ] == 0 ) {
V_201 = V_42 -> V_186 [ V_32 -> V_187 ] ;
F_191 ( V_201 , V_32 -> V_197 ) ;
F_51 ( V_32 , V_201 , NULL ) ;
F_87 ( V_42 ) ;
V_42 -> V_186 [ V_32 -> V_187 ] = 0 ;
}
return V_205 ;
}
static int F_192 ( void )
{
struct V_99 * V_101 = NULL ;
struct V_207 * V_207 ;
int V_79 ;
F_193 ( & V_208 , V_123 , V_209 ,
V_210 ) ;
F_194 ( & V_208 . V_211 ,
& V_212 ) ;
V_207 = F_195 ( & V_208 , F_196 ( V_213 ) ,
F_196 ( V_214 ) ) ;
if ( ! V_207 ) {
F_123 ( L_25 ) ;
return - V_215 ;
}
F_197 (pdev) {
struct V_216 * V_217 ;
for ( V_79 = 0 ; V_79 < V_218 ; V_79 ++ ) {
V_217 = & V_101 -> V_216 [ V_79 ] ;
if ( ! V_217 -> V_33 || ! ( V_217 -> V_33 & V_219 ) )
continue;
V_207 = F_195 ( & V_208 ,
F_196 ( V_217 -> V_220 ) ,
F_196 ( V_217 -> V_111 ) ) ;
if ( ! V_207 ) {
F_123 ( L_26 ) ;
return - V_215 ;
}
}
}
return 0 ;
}
static void F_198 ( struct V_39 * V_42 )
{
F_199 ( & V_208 , & V_42 -> V_221 ) ;
}
static inline int F_200 ( int V_134 )
{
int V_1 ;
int V_217 = ( V_134 - 12 ) % 9 ;
if ( V_217 == 0 )
V_1 = V_134 ;
else
V_1 = V_134 + 9 - V_217 ;
if ( V_1 > 64 )
V_1 = 64 ;
return V_1 ;
}
static int F_201 ( struct V_39 * V_42 , struct V_31 * V_32 ,
int V_222 )
{
int V_223 , V_1 ;
unsigned long V_70 ;
F_193 ( & V_42 -> V_221 , V_123 , V_209 ,
V_210 ) ;
F_198 ( V_42 ) ;
if ( V_222 > F_202 ( V_32 -> V_71 ) )
V_222 = F_202 ( V_32 -> V_71 ) ;
V_42 -> V_134 = V_222 ;
V_223 = F_200 ( V_222 ) ;
V_1 = F_4 ( V_223 ) ;
V_70 = F_70 ( V_32 -> V_71 ) ;
if ( ! F_71 ( V_1 , & V_70 ) ) {
F_143 ( L_27 , V_1 ) ;
V_1 = F_203 ( & V_70 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_215 ;
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
V_42 -> V_122 = V_32 -> V_60 ;
V_42 -> V_119 = (struct V_27 * ) F_54 ( V_42 -> V_122 ) ;
if ( ! V_42 -> V_119 )
return - V_139 ;
F_91 ( V_32 , V_42 -> V_119 , V_224 ) ;
return 0 ;
}
static void F_181 ( struct V_39 * V_42 )
{
struct V_14 * V_135 = NULL ;
if ( ! V_42 )
return;
if ( ! V_48 ) {
int V_225 ;
F_204 (cpu)
F_205 ( V_225 ) ;
}
F_79 () ;
F_206 ( V_42 ) ;
F_81 () ;
F_207 ( & V_42 -> V_221 ) ;
V_135 = F_120 ( V_42 , 0 , F_116 ( V_42 -> V_134 ) ) ;
F_121 ( V_135 ) ;
F_61 ( V_42 ) ;
}
static int F_208 ( struct V_39 * V_42 ,
struct V_31 * V_32 ,
T_6 V_87 , T_6 V_88 )
{
T_4 V_55 = V_42 -> V_186 [ V_32 -> V_187 ] ;
int V_226 = V_227 ;
struct V_169 * V_170 = NULL ;
struct V_22 * V_23 ;
unsigned long V_33 ;
struct V_27 * V_119 ;
int V_83 , V_1 ;
F_53 ( V_55 == 0 ) ;
if ( V_228 && F_66 ( V_42 ) )
V_226 = V_229 ;
F_143 ( L_28 ,
V_87 , F_209 ( V_88 ) , F_210 ( V_88 ) ) ;
F_75 ( ! V_42 -> V_119 ) ;
F_105 ( & V_171 , V_33 ) ;
F_211 ( & V_32 -> V_114 ) ;
V_83 = - V_139 ;
V_23 = F_88 ( V_32 , V_87 , V_88 , 1 ) ;
if ( ! V_23 )
goto V_230;
V_83 = 0 ;
if ( F_25 ( V_23 ) )
goto V_230;
if ( F_23 ( V_23 ) ) {
T_4 V_231 = F_32 ( V_23 ) ;
if ( V_231 >= 0 && V_231 < F_171 ( V_32 -> V_71 ) )
V_32 -> V_188 . V_232 ( V_32 , V_231 ,
( ( ( T_4 ) V_87 ) << 8 ) | V_88 ,
V_233 ,
V_157 ) ;
}
V_119 = V_42 -> V_119 ;
F_33 ( V_23 ) ;
F_31 ( V_23 , V_55 ) ;
if ( V_226 != V_229 ) {
for ( V_1 = V_42 -> V_1 ; V_1 != V_32 -> V_1 ; V_1 -- ) {
V_83 = - V_139 ;
V_119 = F_90 ( F_35 ( V_119 ) ) ;
if ( ! F_38 ( V_119 ) )
goto V_230;
}
V_170 = F_144 ( V_42 , V_32 , V_87 , V_88 ) ;
if ( V_170 && V_170 -> V_173 )
V_226 = V_234 ;
else
V_226 = V_227 ;
F_29 ( V_23 , F_92 ( V_119 ) ) ;
F_30 ( V_23 , V_32 -> V_1 ) ;
} else {
F_30 ( V_23 , V_32 -> V_235 ) ;
}
F_28 ( V_23 , V_226 ) ;
F_27 ( V_23 ) ;
F_26 ( V_23 ) ;
F_102 ( V_42 , V_23 , sizeof( * V_23 ) ) ;
if ( F_166 ( V_32 -> V_71 ) ) {
V_32 -> V_188 . V_232 ( V_32 , 0 ,
( ( ( T_4 ) V_87 ) << 8 ) | V_88 ,
V_233 ,
V_157 ) ;
V_32 -> V_188 . V_189 ( V_32 , V_55 , 0 , 0 , V_166 ) ;
} else {
F_130 ( V_32 ) ;
}
F_148 ( V_170 ) ;
V_83 = 0 ;
V_230:
F_212 ( & V_32 -> V_114 ) ;
F_106 ( & V_171 , V_33 ) ;
return V_83 ;
}
static int F_213 ( struct V_99 * V_101 ,
T_4 V_236 , void * V_237 )
{
struct V_238 * V_239 = V_237 ;
return F_208 ( V_239 -> V_42 , V_239 -> V_32 ,
F_214 ( V_236 ) , V_236 & 0xff ) ;
}
static int
F_215 ( struct V_39 * V_42 , struct V_94 * V_95 )
{
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
struct V_238 V_239 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_215 ;
if ( ! F_95 ( V_95 ) )
return F_208 ( V_42 , V_32 , V_87 , V_88 ) ;
V_239 . V_42 = V_42 ;
V_239 . V_32 = V_32 ;
return F_216 ( F_96 ( V_95 ) ,
& F_213 , & V_239 ) ;
}
static int F_217 ( struct V_99 * V_101 ,
T_4 V_236 , void * V_237 )
{
struct V_31 * V_32 = V_237 ;
return ! F_104 ( V_32 , F_214 ( V_236 ) , V_236 & 0xff ) ;
}
static int F_218 ( struct V_94 * V_95 )
{
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_215 ;
if ( ! F_95 ( V_95 ) )
return F_104 ( V_32 , V_87 , V_88 ) ;
return ! F_216 ( F_96 ( V_95 ) ,
F_217 , V_32 ) ;
}
static inline unsigned long F_219 ( unsigned long V_240 ,
T_5 V_58 )
{
V_240 &= ~ V_241 ;
return F_220 ( V_240 + V_58 ) >> V_12 ;
}
static inline int F_221 ( struct V_39 * V_42 ,
unsigned long V_242 ,
unsigned long V_243 ,
unsigned long V_183 )
{
int V_244 , V_5 = 1 ;
unsigned long V_245 ;
V_244 = V_42 -> V_86 ;
V_245 = V_242 | V_243 ;
while ( V_244 && ! ( V_245 & ~ V_246 ) ) {
V_183 >>= V_247 ;
if ( ! V_183 )
break;
V_245 >>= V_247 ;
V_5 ++ ;
V_244 -- ;
}
return V_5 ;
}
static int F_222 ( struct V_39 * V_42 , unsigned long V_242 ,
struct V_248 * V_249 , unsigned long V_250 ,
unsigned long V_251 , int V_252 )
{
struct V_27 * V_130 = NULL , * V_28 = NULL ;
T_1 V_253 ( V_121 ) ;
unsigned long V_254 = 0 ;
unsigned int V_255 = 0 ;
unsigned long V_256 = 0 ;
F_75 ( ! F_68 ( V_42 , V_242 + V_251 - 1 ) ) ;
if ( ( V_252 & ( V_124 | V_125 ) ) == 0 )
return - V_44 ;
V_252 &= V_124 | V_125 | V_257 ;
if ( ! V_249 ) {
V_254 = V_251 ;
V_121 = ( ( T_1 ) V_250 << V_12 ) | V_252 ;
}
while ( V_251 > 0 ) {
T_7 V_98 ;
if ( ! V_254 ) {
V_254 = F_219 ( V_249 -> V_118 , V_249 -> V_258 ) ;
V_249 -> V_259 = ( ( V_260 ) V_242 << V_12 ) + V_249 -> V_118 ;
V_249 -> V_261 = V_249 -> V_258 ;
V_121 = F_223 ( F_224 ( V_249 ) ) | V_252 ;
V_250 = V_121 >> V_12 ;
}
if ( ! V_28 ) {
V_255 = F_221 ( V_42 , V_242 , V_250 , V_254 ) ;
V_130 = V_28 = F_109 ( V_42 , V_242 , & V_255 ) ;
if ( ! V_28 )
return - V_139 ;
if ( V_255 > 1 ) {
unsigned long V_262 , V_263 ;
V_121 |= V_30 ;
V_256 = F_11 ( V_255 ) ;
V_262 = V_254 / V_256 ;
V_263 = V_242 + V_262 * V_256 - 1 ;
F_115 ( V_42 , V_242 , V_263 ) ;
} else {
V_121 &= ~ ( T_7 ) V_30 ;
}
}
V_98 = F_225 ( & V_28 -> V_29 , 0ULL , V_121 ) ;
if ( V_98 ) {
static int V_264 = 5 ;
F_226 ( L_29 ,
V_242 , V_98 , ( unsigned long long ) V_121 ) ;
if ( V_264 ) {
V_264 -- ;
F_227 ( NULL ) ;
}
F_53 ( 1 ) ;
}
V_256 = F_11 ( V_255 ) ;
F_75 ( V_251 < V_256 ) ;
F_75 ( V_254 < V_256 ) ;
V_251 -= V_256 ;
V_242 += V_256 ;
V_250 += V_256 ;
V_121 += V_256 * V_123 ;
V_254 -= V_256 ;
V_28 ++ ;
if ( ! V_251 || F_40 ( V_28 ) ||
( V_255 > 1 && V_254 < V_256 ) ) {
F_102 ( V_42 , V_130 ,
( void * ) V_28 - ( void * ) V_130 ) ;
V_28 = NULL ;
}
if ( ! V_254 && V_251 )
V_249 = F_228 ( V_249 ) ;
}
return 0 ;
}
static inline int F_229 ( struct V_39 * V_42 , unsigned long V_242 ,
struct V_248 * V_249 , unsigned long V_251 ,
int V_252 )
{
return F_222 ( V_42 , V_242 , V_249 , 0 , V_251 , V_252 ) ;
}
static inline int F_230 ( struct V_39 * V_42 , unsigned long V_242 ,
unsigned long V_250 , unsigned long V_251 ,
int V_252 )
{
return F_222 ( V_42 , V_242 , NULL , V_250 , V_251 , V_252 ) ;
}
static void F_231 ( struct V_31 * V_32 , T_6 V_87 , T_6 V_88 )
{
if ( ! V_32 )
return;
F_107 ( V_32 , V_87 , V_88 ) ;
V_32 -> V_188 . V_232 ( V_32 , 0 , 0 , 0 ,
V_155 ) ;
V_32 -> V_188 . V_189 ( V_32 , 0 , 0 , 0 , V_164 ) ;
}
static inline void F_232 ( struct V_169 * V_170 )
{
F_145 ( & V_171 ) ;
F_233 ( & V_170 -> V_265 ) ;
F_233 ( & V_170 -> V_266 ) ;
if ( V_170 -> V_95 )
V_170 -> V_95 -> V_96 . V_32 = NULL ;
}
static void F_206 ( struct V_39 * V_42 )
{
struct V_169 * V_170 , * V_98 ;
unsigned long V_33 ;
F_105 ( & V_171 , V_33 ) ;
F_179 (info, tmp, &domain->devices, link)
F_180 ( V_170 ) ;
F_106 ( & V_171 , V_33 ) ;
}
static struct V_39 * F_234 ( struct V_94 * V_95 )
{
struct V_169 * V_170 ;
V_170 = V_95 -> V_96 . V_32 ;
if ( V_170 )
return V_170 -> V_42 ;
return NULL ;
}
static inline struct V_169 *
F_235 ( int V_102 , int V_87 , int V_88 )
{
struct V_169 * V_170 ;
F_146 (info, &device_domain_list, global)
if ( V_170 -> V_32 -> V_102 == V_102 && V_170 -> V_87 == V_87 &&
V_170 -> V_88 == V_88 )
return V_170 ;
return NULL ;
}
static struct V_39 * F_236 ( struct V_31 * V_32 ,
int V_87 , int V_88 ,
struct V_94 * V_95 ,
struct V_39 * V_42 )
{
struct V_39 * V_78 = NULL ;
struct V_169 * V_170 ;
unsigned long V_33 ;
int V_83 ;
V_170 = F_63 () ;
if ( ! V_170 )
return NULL ;
V_170 -> V_87 = V_87 ;
V_170 -> V_88 = V_88 ;
V_170 -> V_173 = V_170 -> V_176 = V_170 -> V_178 = 0 ;
V_170 -> V_175 = V_170 -> V_177 = V_170 -> V_179 = 0 ;
V_170 -> V_180 = 0 ;
V_170 -> V_95 = V_95 ;
V_170 -> V_42 = V_42 ;
V_170 -> V_32 = V_32 ;
if ( V_95 && F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_170 -> V_95 ) ;
if ( F_237 ( V_32 -> V_81 ) &&
F_238 ( V_101 , V_267 ) &&
F_239 ( V_101 ) )
V_170 -> V_173 = 1 ;
if ( F_89 ( V_32 ) ) {
if ( V_177 ( V_32 ) ) {
int V_268 = F_240 ( V_101 ) ;
if ( V_268 >= 0 )
V_170 -> V_176 = V_268 | 1 ;
}
if ( V_170 -> V_173 && F_183 ( V_32 -> V_81 ) &&
F_238 ( V_101 , V_269 ) )
V_170 -> V_178 = 1 ;
}
}
F_105 ( & V_171 , V_33 ) ;
if ( V_95 )
V_78 = F_234 ( V_95 ) ;
if ( ! V_78 ) {
struct V_169 * V_270 ;
V_270 = F_235 ( V_32 -> V_102 , V_87 , V_88 ) ;
if ( V_270 ) {
V_78 = V_270 -> V_42 ;
V_270 -> V_95 = V_95 ;
}
}
if ( V_78 ) {
F_106 ( & V_171 , V_33 ) ;
F_64 ( V_170 ) ;
return V_78 ;
}
F_211 ( & V_32 -> V_114 ) ;
V_83 = F_188 ( V_42 , V_32 ) ;
F_212 ( & V_32 -> V_114 ) ;
if ( V_83 ) {
F_106 ( & V_171 , V_33 ) ;
F_64 ( V_170 ) ;
return NULL ;
}
F_241 ( & V_170 -> V_265 , & V_42 -> V_106 ) ;
F_241 ( & V_170 -> V_266 , & V_271 ) ;
if ( V_95 )
V_95 -> V_96 . V_32 = V_170 ;
F_106 ( & V_171 , V_33 ) ;
if ( V_95 && F_215 ( V_42 , V_95 ) ) {
F_123 ( L_30 , F_242 ( V_95 ) ) ;
F_243 ( V_42 , V_95 ) ;
return NULL ;
}
return V_42 ;
}
static int F_244 ( struct V_99 * V_101 , T_4 V_236 , void * V_237 )
{
* ( T_4 * ) V_237 = V_236 ;
return 0 ;
}
static struct V_39 * F_245 ( struct V_94 * V_95 , int V_134 )
{
struct V_169 * V_170 = NULL ;
struct V_39 * V_42 = NULL ;
struct V_31 * V_32 ;
T_4 V_272 , V_273 ;
unsigned long V_33 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return NULL ;
V_272 = ( ( T_4 ) V_87 << 8 ) | V_88 ;
if ( F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_95 ) ;
F_216 ( V_101 , F_244 , & V_273 ) ;
F_105 ( & V_171 , V_33 ) ;
V_170 = F_235 ( F_98 ( V_101 -> V_87 ) ,
F_214 ( V_273 ) ,
V_273 & 0xff ) ;
if ( V_170 ) {
V_32 = V_170 -> V_32 ;
V_42 = V_170 -> V_42 ;
}
F_106 ( & V_171 , V_33 ) ;
if ( V_170 )
goto V_107;
}
V_42 = F_186 ( 0 ) ;
if ( ! V_42 )
return NULL ;
if ( F_201 ( V_42 , V_32 , V_134 ) ) {
F_181 ( V_42 ) ;
return NULL ;
}
V_107:
return V_42 ;
}
static struct V_39 * F_246 ( struct V_94 * V_95 ,
struct V_39 * V_42 )
{
struct V_31 * V_32 ;
struct V_39 * V_98 ;
T_4 V_272 , V_273 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return NULL ;
V_272 = ( ( T_4 ) V_87 << 8 ) | V_88 ;
if ( F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_95 ) ;
F_216 ( V_101 , F_244 , & V_273 ) ;
if ( V_272 != V_273 ) {
V_98 = F_236 ( V_32 , F_214 ( V_273 ) ,
V_273 & 0xff , NULL , V_42 ) ;
if ( ! V_98 || V_98 != V_42 )
return V_98 ;
}
}
V_98 = F_236 ( V_32 , V_87 , V_88 , V_95 , V_42 ) ;
if ( ! V_98 || V_98 != V_42 )
return V_98 ;
return V_42 ;
}
static struct V_39 * F_247 ( struct V_94 * V_95 , int V_134 )
{
struct V_39 * V_42 , * V_98 ;
V_42 = F_234 ( V_95 ) ;
if ( V_42 )
goto V_107;
V_42 = F_245 ( V_95 , V_134 ) ;
if ( ! V_42 )
goto V_107;
V_98 = F_246 ( V_95 , V_42 ) ;
if ( ! V_98 || V_42 != V_98 ) {
F_181 ( V_42 ) ;
V_42 = V_98 ;
}
V_107:
return V_42 ;
}
static int F_248 ( struct V_39 * V_42 ,
unsigned long long V_220 ,
unsigned long long V_111 )
{
unsigned long V_274 = V_220 >> V_12 ;
unsigned long V_275 = V_111 >> V_12 ;
if ( ! F_195 ( & V_42 -> V_221 , F_12 ( V_274 ) ,
F_12 ( V_275 ) ) ) {
F_123 ( L_31 ) ;
return - V_139 ;
}
F_143 ( L_32 , V_220 , V_111 ) ;
F_112 ( V_42 , V_274 , V_275 ) ;
return F_230 ( V_42 , V_274 , V_274 ,
V_275 - V_274 + 1 ,
V_124 | V_125 ) ;
}
static int F_249 ( struct V_94 * V_95 ,
struct V_39 * V_42 ,
unsigned long long V_220 ,
unsigned long long V_111 )
{
if ( V_42 == V_276 && V_228 ) {
F_250 ( L_33 ,
F_242 ( V_95 ) , V_220 , V_111 ) ;
return 0 ;
}
F_48 ( L_34 ,
F_242 ( V_95 ) , V_220 , V_111 ) ;
if ( V_111 < V_220 ) {
F_251 ( 1 , L_35
L_36 ,
F_252 ( V_277 ) ,
F_252 ( V_278 ) ,
F_252 ( V_279 ) ) ;
return - V_280 ;
}
if ( V_111 >> F_2 ( V_42 -> V_1 ) ) {
F_251 ( 1 , L_37
L_36 ,
F_2 ( V_42 -> V_1 ) ,
F_252 ( V_277 ) ,
F_252 ( V_278 ) ,
F_252 ( V_279 ) ) ;
return - V_280 ;
}
return F_248 ( V_42 , V_220 , V_111 ) ;
}
static int F_253 ( struct V_94 * V_95 ,
unsigned long long V_220 ,
unsigned long long V_111 )
{
struct V_39 * V_42 ;
int V_83 ;
V_42 = F_247 ( V_95 , V_72 ) ;
if ( ! V_42 )
return - V_139 ;
V_83 = F_249 ( V_95 , V_42 , V_220 , V_111 ) ;
if ( V_83 )
F_181 ( V_42 ) ;
return V_83 ;
}
static inline int F_254 ( struct V_281 * V_282 ,
struct V_94 * V_95 )
{
if ( V_95 -> V_96 . V_32 == V_97 )
return 0 ;
return F_253 ( V_95 , V_282 -> V_283 ,
V_282 -> V_284 ) ;
}
static inline void F_255 ( void )
{
struct V_99 * V_101 ;
int V_83 ;
V_101 = F_256 ( V_285 << 8 , NULL ) ;
if ( ! V_101 )
return;
F_48 ( L_38 ) ;
V_83 = F_253 ( & V_101 -> V_95 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_83 )
F_123 ( L_39 ) ;
F_257 ( V_101 ) ;
}
static inline void F_255 ( void )
{
return;
}
static int T_3 F_258 ( int V_286 )
{
int V_122 , V_83 = 0 ;
V_276 = F_186 ( V_66 ) ;
if ( ! V_276 )
return - V_287 ;
if ( F_259 ( V_276 , V_72 ) ) {
F_181 ( V_276 ) ;
return - V_287 ;
}
F_143 ( L_40 ) ;
if ( V_286 )
return 0 ;
F_260 (nid) {
unsigned long V_128 , V_263 ;
int V_79 ;
F_261 (i, nid, &start_pfn, &end_pfn, NULL) {
V_83 = F_248 ( V_276 ,
F_262 ( V_128 ) , F_262 ( V_263 ) ) ;
if ( V_83 )
return V_83 ;
}
}
return 0 ;
}
static int F_263 ( struct V_94 * V_95 )
{
struct V_169 * V_170 ;
if ( F_264 ( ! V_53 ) )
return 0 ;
V_170 = V_95 -> V_96 . V_32 ;
if ( V_170 && V_170 != V_97 )
return ( V_170 -> V_42 == V_276 ) ;
return 0 ;
}
static int F_265 ( struct V_39 * V_42 , struct V_94 * V_95 )
{
struct V_39 * V_288 ;
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_215 ;
V_288 = F_236 ( V_32 , V_87 , V_88 , V_95 , V_42 ) ;
if ( V_288 != V_42 )
return - V_289 ;
return 0 ;
}
static bool F_266 ( struct V_94 * V_95 )
{
struct V_281 * V_282 ;
struct V_94 * V_98 ;
int V_79 ;
F_79 () ;
F_267 (rmrr) {
F_101 (rmrr->devices,
rmrr->devices_cnt, i, tmp)
if ( V_98 == V_95 ) {
F_81 () ;
return true ;
}
}
F_81 () ;
return false ;
}
static bool F_268 ( struct V_94 * V_95 )
{
if ( ! F_266 ( V_95 ) )
return false ;
if ( F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_95 ) ;
if ( F_269 ( V_101 ) || F_270 ( V_101 ) )
return false ;
}
return true ;
}
static int F_271 ( struct V_94 * V_95 , int V_290 )
{
if ( F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_95 ) ;
if ( F_268 ( V_95 ) )
return 0 ;
if ( ( V_53 & V_291 ) && F_272 ( V_101 ) )
return 1 ;
if ( ( V_53 & V_54 ) && F_270 ( V_101 ) )
return 1 ;
if ( ! ( V_53 & V_292 ) )
return 0 ;
if ( ! F_273 ( V_101 ) ) {
if ( ! F_274 ( V_101 -> V_87 ) )
return 0 ;
if ( V_101 -> V_293 >> 8 == V_294 )
return 0 ;
} else if ( F_275 ( V_101 ) == V_295 )
return 0 ;
} else {
if ( F_266 ( V_95 ) )
return 0 ;
}
if ( ! V_290 ) {
V_24 V_296 = * V_95 -> V_296 ;
if ( V_95 -> V_297 &&
V_95 -> V_297 < V_296 )
V_296 = V_95 -> V_297 ;
return V_296 >= F_276 ( V_95 ) ;
}
return 1 ;
}
static int T_3 F_277 ( struct V_94 * V_95 , int V_286 )
{
int V_83 ;
if ( ! F_271 ( V_95 , 1 ) )
return 0 ;
V_83 = F_265 ( V_276 , V_95 ) ;
if ( ! V_83 )
F_48 ( L_41 ,
V_286 ? L_42 : L_43 , F_242 ( V_95 ) ) ;
else if ( V_83 == - V_215 )
V_83 = 0 ;
return V_83 ;
}
static int T_3 F_278 ( int V_286 )
{
struct V_99 * V_101 = NULL ;
struct V_76 * V_77 ;
struct V_31 * V_32 ;
struct V_94 * V_95 ;
int V_79 ;
int V_83 = 0 ;
F_197 (pdev) {
V_83 = F_277 ( & V_101 -> V_95 , V_286 ) ;
if ( V_83 )
return V_83 ;
}
F_80 (iommu, drhd)
F_101 (drhd->devices, drhd->devices_cnt, i, dev) {
struct V_298 * V_299 ;
struct V_300 * V_301 ;
if ( V_95 -> V_87 != & V_302 )
continue;
V_301 = F_279 ( V_95 ) ;
F_280 ( & V_301 -> V_303 ) ;
F_146 (pn, &adev->physical_node_list, node) {
V_83 = F_277 ( V_299 -> V_95 , V_286 ) ;
if ( V_83 )
break;
}
F_281 ( & V_301 -> V_303 ) ;
if ( V_83 )
return V_83 ;
}
return 0 ;
}
static void F_282 ( struct V_31 * V_32 )
{
if ( ! V_32 -> V_172 ) {
F_283 ( - 1 , V_32 ) ;
F_284 ( V_32 ) ;
}
if ( F_285 ( V_32 ) ) {
V_32 -> V_188 . V_232 = F_132 ;
V_32 -> V_188 . V_189 = F_137 ;
F_48 ( L_44 ,
V_32 -> V_138 ) ;
} else {
V_32 -> V_188 . V_232 = V_304 ;
V_32 -> V_188 . V_189 = V_305 ;
F_48 ( L_45 , V_32 -> V_138 ) ;
}
}
static int F_286 ( struct V_31 * V_32 ,
struct V_17 * V_306 ,
struct V_22 * * V_307 ,
int V_87 , bool V_308 )
{
int V_309 , V_310 = 0 , V_57 , V_88 , V_83 = 0 , V_55 ;
struct V_22 * V_311 = NULL , V_312 ;
struct V_22 * V_313 = NULL ;
struct V_17 V_18 ;
T_1 V_314 ;
V_309 = V_308 ? V_87 * 2 : V_87 ;
memcpy ( & V_18 , V_306 , sizeof( V_18 ) ) ;
for ( V_88 = 0 ; V_88 < 256 ; V_88 ++ ) {
V_57 = ( V_308 ? V_88 * 2 : V_88 ) % 256 ;
if ( V_57 == 0 ) {
if ( V_311 ) {
V_307 [ V_309 ] = V_311 ;
F_91 ( V_32 , V_311 ,
V_123 ) ;
V_310 = 1 ;
}
if ( V_313 )
F_287 ( V_313 ) ;
V_83 = 0 ;
if ( V_88 < 0x80 )
V_314 = F_18 ( & V_18 ) ;
else
V_314 = F_19 ( & V_18 ) ;
if ( ! V_314 ) {
if ( V_308 && V_88 == 0 ) {
V_88 = 0x7f ;
continue;
} else {
goto V_107;
}
}
V_83 = - V_139 ;
V_313 = F_288 ( V_314 , V_224 ,
V_315 ) ;
if ( ! V_313 )
goto V_107;
V_311 = F_54 ( V_32 -> V_60 ) ;
if ( ! V_311 )
goto V_316;
V_83 = 0 ;
}
memcpy ( & V_312 , V_313 + V_57 , sizeof( V_312 ) ) ;
if ( ! F_24 ( & V_312 ) )
continue;
V_55 = F_32 ( & V_312 ) ;
if ( V_55 >= 0 && V_55 < F_171 ( V_32 -> V_71 ) )
F_177 ( V_55 , V_32 -> V_197 ) ;
F_20 ( & V_312 ) ;
F_22 ( & V_312 ) ;
V_311 [ V_57 ] = V_312 ;
}
V_307 [ V_309 + V_310 ] = V_311 ;
F_91 ( V_32 , V_311 , V_123 ) ;
V_316:
F_289 ( V_313 ) ;
V_107:
return V_83 ;
}
static int F_290 ( struct V_31 * V_32 )
{
struct V_22 * * V_317 ;
struct V_17 * V_318 ;
T_1 V_319 ;
int V_320 ;
unsigned long V_33 ;
V_24 V_321 ;
int V_87 , V_83 ;
bool V_322 , V_308 ;
V_321 = V_160 ( V_32 -> V_36 + V_145 ) ;
V_308 = ! ! ( V_321 & V_143 ) ;
V_322 = ! ! F_291 ( V_32 -> V_81 ) ;
if ( V_322 != V_308 )
return - V_44 ;
V_319 = V_321 & V_20 ;
if ( ! V_319 )
return - V_44 ;
V_318 = F_288 ( V_319 , V_224 , V_315 ) ;
if ( ! V_318 )
return - V_139 ;
V_320 = V_308 ? 512 : 256 ;
V_83 = - V_139 ;
V_317 = F_52 ( V_320 * sizeof( void * ) , V_198 ) ;
if ( ! V_317 )
goto V_316;
for ( V_87 = 0 ; V_87 < 256 ; V_87 ++ ) {
V_83 = F_286 ( V_32 , & V_318 [ V_87 ] ,
V_317 , V_87 , V_308 ) ;
if ( V_83 ) {
F_123 ( L_46 ,
V_32 -> V_138 , V_87 ) ;
continue;
}
}
F_105 ( & V_32 -> V_114 , V_33 ) ;
for ( V_87 = 0 ; V_87 < 256 ; V_87 ++ ) {
int V_57 = V_308 ? V_87 * 2 : V_87 ;
V_24 V_29 ;
if ( V_317 [ V_57 ] ) {
V_29 = F_92 ( V_317 [ V_57 ] ) | 1 ;
V_32 -> V_17 [ V_87 ] . V_19 = V_29 ;
}
if ( ! V_308 || ! V_317 [ V_57 + 1 ] )
continue;
V_29 = F_92 ( V_317 [ V_57 + 1 ] ) | 1 ;
V_32 -> V_17 [ V_87 ] . V_21 = V_29 ;
}
F_106 ( & V_32 -> V_114 , V_33 ) ;
F_176 ( V_317 ) ;
F_91 ( V_32 , V_32 -> V_17 , V_224 ) ;
V_83 = 0 ;
V_316:
F_289 ( V_318 ) ;
return V_83 ;
}
static int T_3 F_292 ( void )
{
struct V_76 * V_77 ;
struct V_281 * V_282 ;
bool V_323 = false ;
struct V_94 * V_95 ;
struct V_31 * V_32 ;
int V_79 , V_83 , V_225 ;
F_293 (drhd) {
if ( V_74 < V_324 ) {
V_74 ++ ;
continue;
}
F_294 ( L_47 , V_324 ) ;
}
if ( V_74 < V_324 )
V_74 = V_324 ;
V_75 = F_174 ( V_74 , sizeof( struct V_31 * ) ,
V_198 ) ;
if ( ! V_75 ) {
F_123 ( L_48 ) ;
V_83 = - V_139 ;
goto error;
}
F_204 (cpu) {
struct V_325 * V_326 = F_295 ( & V_327 ,
V_225 ) ;
V_326 -> V_328 = F_52 ( V_74 *
sizeof( struct V_329 ) ,
V_198 ) ;
if ( ! V_326 -> V_328 ) {
V_83 = - V_139 ;
goto V_330;
}
F_173 ( & V_326 -> V_114 ) ;
F_296 ( & V_326 -> V_331 , F_205 , V_225 ) ;
}
F_80 (iommu, drhd) {
V_75 [ V_32 -> V_187 ] = V_32 ;
F_282 ( V_32 ) ;
V_83 = F_170 ( V_32 ) ;
if ( V_83 )
goto V_332;
F_43 ( V_32 ) ;
if ( F_41 ( V_32 ) && ! F_297 () ) {
F_169 ( V_32 ) ;
F_42 ( V_32 ) ;
F_250 ( L_49 ,
V_32 -> V_138 ) ;
}
V_83 = F_122 ( V_32 ) ;
if ( V_83 )
goto V_332;
if ( F_41 ( V_32 ) ) {
F_48 ( L_50 ) ;
V_83 = F_290 ( V_32 ) ;
if ( V_83 ) {
F_123 ( L_51 ,
V_32 -> V_138 ) ;
F_169 ( V_32 ) ;
F_42 ( V_32 ) ;
} else {
F_48 ( L_52 ,
V_32 -> V_138 ) ;
V_323 = true ;
}
}
if ( ! F_298 ( V_32 -> V_81 ) )
V_228 = 0 ;
#ifdef F_149
if ( V_177 ( V_32 ) )
F_299 ( V_32 ) ;
#endif
}
F_80 (iommu, drhd) {
F_130 ( V_32 ) ;
F_124 ( V_32 ) ;
V_32 -> V_188 . V_232 ( V_32 , 0 , 0 , 0 , V_155 ) ;
V_32 -> V_188 . V_189 ( V_32 , 0 , 0 , 0 , V_164 ) ;
}
if ( V_333 )
V_53 |= V_292 ;
#ifdef F_300
V_53 |= V_54 ;
#endif
if ( V_53 ) {
V_83 = F_258 ( V_228 ) ;
if ( V_83 )
goto V_332;
}
F_301 () ;
if ( V_323 )
goto V_334;
if ( V_53 ) {
V_83 = F_278 ( V_228 ) ;
if ( V_83 ) {
F_226 ( L_53 ) ;
goto V_332;
}
}
F_48 ( L_54 ) ;
F_267 (rmrr) {
F_101 (rmrr->devices, rmrr->devices_cnt,
i, dev) {
V_83 = F_254 ( V_282 , V_95 ) ;
if ( V_83 )
F_123 ( L_55 ) ;
}
}
F_255 () ;
V_334:
F_302 (iommu, drhd) {
if ( V_77 -> V_335 ) {
if ( V_336 )
F_167 ( V_32 ) ;
continue;
}
F_130 ( V_32 ) ;
#ifdef F_149
if ( V_177 ( V_32 ) && F_183 ( V_32 -> V_81 ) ) {
V_83 = F_303 ( V_32 ) ;
if ( V_83 )
goto V_332;
}
#endif
V_83 = F_304 ( V_32 ) ;
if ( V_83 )
goto V_332;
if ( ! F_41 ( V_32 ) )
F_168 ( V_32 ) ;
F_167 ( V_32 ) ;
}
return 0 ;
V_332:
F_80 (iommu, drhd) {
F_178 ( V_32 ) ;
F_182 ( V_32 ) ;
}
V_330:
F_204 (cpu)
F_176 ( F_295 ( & V_327 , V_225 ) -> V_328 ) ;
F_176 ( V_75 ) ;
error:
return V_83 ;
}
static unsigned long F_305 ( struct V_94 * V_95 ,
struct V_39 * V_42 ,
unsigned long V_337 , T_7 V_296 )
{
unsigned long V_338 = 0 ;
V_296 = F_3 ( T_7 , F_306 ( V_42 -> V_134 ) , V_296 ) ;
V_337 = F_163 ( V_337 ) ;
if ( ! V_47 && V_296 > F_307 ( 32 ) ) {
V_338 = F_308 ( & V_42 -> V_221 , V_337 ,
F_196 ( F_307 ( 32 ) ) ) ;
if ( V_338 )
return V_338 ;
}
V_338 = F_308 ( & V_42 -> V_221 , V_337 , F_196 ( V_296 ) ) ;
if ( F_309 ( ! V_338 ) ) {
F_123 ( L_56 ,
V_337 , F_242 ( V_95 ) ) ;
return 0 ;
}
return V_338 ;
}
static struct V_39 * F_310 ( struct V_94 * V_95 )
{
struct V_39 * V_42 , * V_98 ;
struct V_281 * V_282 ;
struct V_94 * V_339 ;
int V_79 , V_83 ;
V_42 = F_234 ( V_95 ) ;
if ( V_42 )
goto V_107;
V_42 = F_245 ( V_95 , V_72 ) ;
if ( ! V_42 )
goto V_107;
F_79 () ;
F_267 (rmrr) {
F_101 (rmrr->devices, rmrr->devices_cnt,
i, i_dev) {
if ( V_339 != V_95 )
continue;
V_83 = F_249 ( V_95 , V_42 ,
V_282 -> V_283 ,
V_282 -> V_284 ) ;
if ( V_83 )
F_311 ( V_95 , L_55 ) ;
}
}
F_81 () ;
V_98 = F_246 ( V_95 , V_42 ) ;
if ( ! V_98 || V_42 != V_98 ) {
F_181 ( V_42 ) ;
V_42 = V_98 ;
}
V_107:
if ( ! V_42 )
F_123 ( L_57 , F_242 ( V_95 ) ) ;
return V_42 ;
}
static inline struct V_39 * F_312 ( struct V_94 * V_95 )
{
struct V_169 * V_170 ;
V_170 = V_95 -> V_96 . V_32 ;
if ( F_264 ( V_170 ) )
return V_170 -> V_42 ;
return F_310 ( V_95 ) ;
}
static int F_313 ( struct V_94 * V_95 )
{
int V_78 ;
if ( F_93 ( V_95 ) )
return 1 ;
if ( ! V_53 )
return 0 ;
V_78 = F_263 ( V_95 ) ;
if ( V_78 ) {
if ( F_271 ( V_95 , 0 ) )
return 1 ;
else {
F_243 ( V_276 , V_95 ) ;
F_48 ( L_58 ,
F_242 ( V_95 ) ) ;
return 0 ;
}
} else {
if ( F_271 ( V_95 , 0 ) ) {
int V_83 ;
V_83 = F_265 ( V_276 , V_95 ) ;
if ( ! V_83 ) {
F_48 ( L_59 ,
F_242 ( V_95 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_260 F_314 ( struct V_94 * V_95 , T_1 V_340 ,
T_5 V_58 , int V_341 , V_24 V_296 )
{
struct V_39 * V_42 ;
T_1 V_342 ;
unsigned long V_338 ;
int V_252 = 0 ;
int V_83 ;
struct V_31 * V_32 ;
unsigned long V_343 = V_340 >> V_11 ;
F_75 ( V_341 == V_344 ) ;
if ( F_313 ( V_95 ) )
return V_340 ;
V_42 = F_312 ( V_95 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_74 ( V_42 ) ;
V_58 = F_219 ( V_340 , V_58 ) ;
V_338 = F_305 ( V_95 , V_42 , F_12 ( V_58 ) , V_296 ) ;
if ( ! V_338 )
goto error;
if ( V_341 == V_345 || V_341 == V_346 || \
! F_315 ( V_32 -> V_71 ) )
V_252 |= V_124 ;
if ( V_341 == V_347 || V_341 == V_346 )
V_252 |= V_125 ;
V_83 = F_230 ( V_42 , F_13 ( V_338 ) ,
F_13 ( V_343 ) , V_58 , V_252 ) ;
if ( V_83 )
goto error;
if ( F_166 ( V_32 -> V_71 ) )
F_161 ( V_32 , V_42 ,
F_13 ( V_338 ) ,
V_58 , 0 , 1 ) ;
else
F_130 ( V_32 ) ;
V_342 = ( T_1 ) V_338 << V_11 ;
V_342 += V_340 & ~ V_241 ;
return V_342 ;
error:
if ( V_338 )
F_316 ( & V_42 -> V_221 , V_338 , F_12 ( V_58 ) ) ;
F_123 ( L_60 ,
F_242 ( V_95 ) , V_58 , ( unsigned long long ) V_340 , V_341 ) ;
return 0 ;
}
static V_260 F_317 ( struct V_94 * V_95 , struct V_14 * V_14 ,
unsigned long V_118 , T_5 V_58 ,
enum V_348 V_341 ,
unsigned long V_349 )
{
return F_314 ( V_95 , F_223 ( V_14 ) + V_118 , V_58 ,
V_341 , * V_95 -> V_296 ) ;
}
static void F_318 ( struct V_325 * V_350 )
{
int V_79 , V_351 ;
V_350 -> V_352 = 0 ;
for ( V_79 = 0 ; V_79 < V_74 ; V_79 ++ ) {
struct V_31 * V_32 = V_75 [ V_79 ] ;
struct V_329 * V_353 =
& V_350 -> V_328 [ V_79 ] ;
if ( ! V_32 )
continue;
if ( ! V_353 -> V_133 )
continue;
if ( ! F_166 ( V_32 -> V_71 ) )
V_32 -> V_188 . V_189 ( V_32 , 0 , 0 , 0 ,
V_164 ) ;
for ( V_351 = 0 ; V_351 < V_353 -> V_133 ; V_351 ++ ) {
unsigned long V_84 ;
struct V_354 * V_91 =
& V_353 -> V_355 [ V_351 ] ;
unsigned long V_338 = V_91 -> V_338 ;
unsigned long V_337 = V_91 -> V_337 ;
struct V_39 * V_42 = V_91 -> V_42 ;
struct V_14 * V_135 = V_91 -> V_135 ;
if ( F_166 ( V_32 -> V_71 ) )
F_161 ( V_32 , V_42 ,
F_13 ( V_338 ) ,
V_337 , ! V_135 , 0 ) ;
else {
V_84 = F_162 ( V_337 ) ;
F_159 ( V_42 ,
( T_7 ) V_338 << V_11 , V_84 ) ;
}
F_316 ( & V_42 -> V_221 , V_338 , V_337 ) ;
if ( V_135 )
F_121 ( V_135 ) ;
}
V_353 -> V_133 = 0 ;
}
V_350 -> V_58 = 0 ;
}
static void F_205 ( unsigned long V_356 )
{
struct V_325 * V_350 = F_295 ( & V_327 , V_356 ) ;
unsigned long V_33 ;
F_105 ( & V_350 -> V_114 , V_33 ) ;
F_318 ( V_350 ) ;
F_106 ( & V_350 -> V_114 , V_33 ) ;
}
static void F_319 ( struct V_39 * V_41 , unsigned long V_338 ,
unsigned long V_337 , struct V_14 * V_135 )
{
unsigned long V_33 ;
int V_357 , V_73 ;
struct V_31 * V_32 ;
struct V_354 * V_91 ;
struct V_325 * V_350 ;
unsigned int V_356 ;
V_356 = F_320 () ;
V_350 = F_295 ( & V_327 , V_356 ) ;
if ( V_350 -> V_58 == V_358 ) {
int V_225 ;
F_321 (cpu)
F_205 ( V_225 ) ;
}
F_105 ( & V_350 -> V_114 , V_33 ) ;
V_32 = F_74 ( V_41 ) ;
V_73 = V_32 -> V_187 ;
V_357 = V_350 -> V_328 [ V_73 ] . V_133 ;
++ ( V_350 -> V_328 [ V_73 ] . V_133 ) ;
V_91 = & V_350 -> V_328 [ V_73 ] . V_355 [ V_357 ] ;
V_91 -> V_42 = V_41 ;
V_91 -> V_338 = V_338 ;
V_91 -> V_337 = V_337 ;
V_91 -> V_135 = V_135 ;
if ( ! V_350 -> V_352 ) {
F_322 ( & V_350 -> V_331 , V_359 + F_323 ( 10 ) ) ;
V_350 -> V_352 = 1 ;
}
V_350 -> V_58 ++ ;
F_106 ( & V_350 -> V_114 , V_33 ) ;
F_324 () ;
}
static void F_325 ( struct V_94 * V_95 , V_260 V_360 , T_5 V_58 )
{
struct V_39 * V_42 ;
unsigned long V_128 , V_129 ;
unsigned long V_337 ;
unsigned long V_338 ;
struct V_31 * V_32 ;
struct V_14 * V_135 ;
if ( F_313 ( V_95 ) )
return;
V_42 = F_234 ( V_95 ) ;
F_75 ( ! V_42 ) ;
V_32 = F_74 ( V_42 ) ;
V_338 = F_196 ( V_360 ) ;
V_337 = F_219 ( V_360 , V_58 ) ;
V_128 = F_13 ( V_338 ) ;
V_129 = V_128 + V_337 - 1 ;
F_143 ( L_61 ,
F_242 ( V_95 ) , V_128 , V_129 ) ;
V_135 = F_120 ( V_42 , V_128 , V_129 ) ;
if ( V_48 ) {
F_161 ( V_32 , V_42 , V_128 ,
V_337 , ! V_135 , 0 ) ;
F_316 ( & V_42 -> V_221 , V_338 , F_12 ( V_337 ) ) ;
F_121 ( V_135 ) ;
} else {
F_319 ( V_42 , V_338 , V_337 , V_135 ) ;
}
}
static void F_326 ( struct V_94 * V_95 , V_260 V_360 ,
T_5 V_58 , enum V_348 V_341 ,
unsigned long V_349 )
{
F_325 ( V_95 , V_360 , V_58 ) ;
}
static void * F_327 ( struct V_94 * V_95 , T_5 V_58 ,
V_260 * V_361 , T_8 V_33 ,
unsigned long V_349 )
{
struct V_14 * V_14 = NULL ;
int V_362 ;
V_58 = F_220 ( V_58 ) ;
V_362 = F_328 ( V_58 ) ;
if ( ! F_313 ( V_95 ) )
V_33 &= ~ ( V_363 | V_364 ) ;
else if ( V_95 -> V_297 < F_276 ( V_95 ) ) {
if ( V_95 -> V_297 < F_307 ( 32 ) )
V_33 |= V_363 ;
else
V_33 |= V_364 ;
}
if ( F_329 ( V_33 ) ) {
unsigned int V_205 = V_58 >> V_11 ;
V_14 = F_330 ( V_95 , V_205 , V_362 ) ;
if ( V_14 && F_313 ( V_95 ) &&
F_223 ( V_14 ) + V_58 > V_95 -> V_297 ) {
F_331 ( V_95 , V_14 , V_205 ) ;
V_14 = NULL ;
}
}
if ( ! V_14 )
V_14 = F_332 ( V_33 , V_362 ) ;
if ( ! V_14 )
return NULL ;
memset ( F_56 ( V_14 ) , 0 , V_58 ) ;
* V_361 = F_314 ( V_95 , F_223 ( V_14 ) , V_58 ,
V_346 ,
V_95 -> V_297 ) ;
if ( * V_361 )
return F_56 ( V_14 ) ;
if ( ! F_331 ( V_95 , V_14 , V_58 >> V_11 ) )
F_333 ( V_14 , V_362 ) ;
return NULL ;
}
static void F_334 ( struct V_94 * V_95 , T_5 V_58 , void * V_61 ,
V_260 V_361 , unsigned long V_349 )
{
int V_362 ;
struct V_14 * V_14 = F_17 ( V_61 ) ;
V_58 = F_220 ( V_58 ) ;
V_362 = F_328 ( V_58 ) ;
F_325 ( V_95 , V_361 , V_58 ) ;
if ( ! F_331 ( V_95 , V_14 , V_58 >> V_11 ) )
F_333 ( V_14 , V_362 ) ;
}
static void F_335 ( struct V_94 * V_95 , struct V_248 * V_365 ,
int V_366 , enum V_348 V_341 ,
unsigned long V_349 )
{
V_260 V_367 = F_336 ( V_365 ) & V_241 ;
unsigned long V_337 = 0 ;
struct V_248 * V_249 ;
int V_79 ;
F_337 (sglist, sg, nelems, i) {
V_337 += F_219 ( F_336 ( V_249 ) , F_338 ( V_249 ) ) ;
}
F_325 ( V_95 , V_367 , V_337 << V_12 ) ;
}
static int F_339 ( struct V_94 * V_368 ,
struct V_248 * V_365 , int V_366 , int V_341 )
{
int V_79 ;
struct V_248 * V_249 ;
F_337 (sglist, sg, nelems, i) {
F_75 ( ! F_224 ( V_249 ) ) ;
V_249 -> V_259 = F_223 ( F_224 ( V_249 ) ) + V_249 -> V_118 ;
V_249 -> V_261 = V_249 -> V_258 ;
}
return V_366 ;
}
static int F_340 ( struct V_94 * V_95 , struct V_248 * V_365 , int V_366 ,
enum V_348 V_341 , unsigned long V_349 )
{
int V_79 ;
struct V_39 * V_42 ;
T_5 V_58 = 0 ;
int V_252 = 0 ;
unsigned long V_338 ;
int V_83 ;
struct V_248 * V_249 ;
unsigned long V_369 ;
struct V_31 * V_32 ;
F_75 ( V_341 == V_344 ) ;
if ( F_313 ( V_95 ) )
return F_339 ( V_95 , V_365 , V_366 , V_341 ) ;
V_42 = F_312 ( V_95 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_74 ( V_42 ) ;
F_337 (sglist, sg, nelems, i)
V_58 += F_219 ( V_249 -> V_118 , V_249 -> V_258 ) ;
V_338 = F_305 ( V_95 , V_42 , F_12 ( V_58 ) ,
* V_95 -> V_296 ) ;
if ( ! V_338 ) {
V_365 -> V_261 = 0 ;
return 0 ;
}
if ( V_341 == V_345 || V_341 == V_346 || \
! F_315 ( V_32 -> V_71 ) )
V_252 |= V_124 ;
if ( V_341 == V_347 || V_341 == V_346 )
V_252 |= V_125 ;
V_369 = F_13 ( V_338 ) ;
V_83 = F_229 ( V_42 , V_369 , V_365 , V_58 , V_252 ) ;
if ( F_309 ( V_83 ) ) {
F_115 ( V_42 , V_369 ,
V_369 + V_58 - 1 ) ;
F_316 ( & V_42 -> V_221 , V_338 , F_12 ( V_58 ) ) ;
return 0 ;
}
if ( F_166 ( V_32 -> V_71 ) )
F_161 ( V_32 , V_42 , V_369 , V_58 , 0 , 1 ) ;
else
F_130 ( V_32 ) ;
return V_366 ;
}
static int F_341 ( struct V_94 * V_95 , V_260 V_370 )
{
return ! V_370 ;
}
static inline int F_342 ( void )
{
int V_83 = 0 ;
V_63 = F_343 ( L_62 ,
sizeof( struct V_39 ) ,
0 ,
V_371 ,
NULL ) ;
if ( ! V_63 ) {
F_123 ( L_63 ) ;
V_83 = - V_139 ;
}
return V_83 ;
}
static inline int F_344 ( void )
{
int V_83 = 0 ;
V_64 = F_343 ( L_64 ,
sizeof( struct V_169 ) ,
0 ,
V_371 ,
NULL ) ;
if ( ! V_64 ) {
F_123 ( L_65 ) ;
V_83 = - V_139 ;
}
return V_83 ;
}
static int T_3 F_345 ( void )
{
int V_83 ;
V_83 = F_346 () ;
if ( V_83 )
return V_83 ;
V_83 = F_342 () ;
if ( V_83 )
goto V_372;
V_83 = F_344 () ;
if ( ! V_83 )
return V_83 ;
F_347 ( V_63 ) ;
V_372:
F_348 () ;
return - V_139 ;
}
static void T_3 F_349 ( void )
{
F_347 ( V_64 ) ;
F_347 ( V_63 ) ;
F_348 () ;
}
static void F_350 ( struct V_99 * V_101 )
{
struct V_76 * V_77 ;
T_2 V_373 ;
int V_374 ;
V_374 = F_351 ( V_101 -> V_87 , F_352 ( 0 , 0 ) , 0xb0 , & V_373 ) ;
if ( V_374 ) {
F_353 ( & V_101 -> V_95 , L_66 ) ;
return;
}
V_373 &= 0xffff0000 ;
V_77 = F_354 ( V_101 ) ;
if ( F_355 ( ! V_77 || V_77 -> V_375 - V_373 != 0xa000 ,
V_376 ,
L_67 ) )
V_101 -> V_95 . V_96 . V_32 = V_97 ;
}
static void T_3 F_356 ( void )
{
struct V_76 * V_77 ;
struct V_94 * V_95 ;
int V_79 ;
F_293 (drhd) {
if ( ! V_77 -> V_112 ) {
F_101 (drhd->devices,
drhd->devices_cnt, i, dev)
break;
if ( V_79 == V_77 -> V_377 )
V_77 -> V_335 = 1 ;
}
}
F_357 (drhd) {
if ( V_77 -> V_112 )
continue;
F_101 (drhd->devices,
drhd->devices_cnt, i, dev)
if ( ! F_95 ( V_95 ) || ! F_270 ( F_96 ( V_95 ) ) )
break;
if ( V_79 < V_77 -> V_377 )
continue;
if ( V_46 ) {
V_378 = 1 ;
} else {
V_77 -> V_335 = 1 ;
F_101 (drhd->devices,
drhd->devices_cnt, i, dev)
V_95 -> V_96 . V_32 = V_97 ;
}
}
}
static int F_358 ( void )
{
struct V_76 * V_77 ;
struct V_31 * V_32 = NULL ;
F_80 (iommu, drhd)
if ( V_32 -> V_172 )
F_359 ( V_32 ) ;
F_302 (iommu, drhd) {
if ( V_77 -> V_335 ) {
if ( V_336 )
F_167 ( V_32 ) ;
continue;
}
F_130 ( V_32 ) ;
F_124 ( V_32 ) ;
V_32 -> V_188 . V_232 ( V_32 , 0 , 0 , 0 ,
V_155 ) ;
V_32 -> V_188 . V_189 ( V_32 , 0 , 0 , 0 , V_164 ) ;
F_168 ( V_32 ) ;
F_167 ( V_32 ) ;
}
return 0 ;
}
static void F_360 ( void )
{
struct V_76 * V_77 ;
struct V_31 * V_32 ;
F_80 (iommu, drhd) {
V_32 -> V_188 . V_232 ( V_32 , 0 , 0 , 0 ,
V_155 ) ;
V_32 -> V_188 . V_189 ( V_32 , 0 , 0 , 0 ,
V_164 ) ;
}
}
static int F_361 ( void )
{
struct V_76 * V_77 ;
struct V_31 * V_32 = NULL ;
unsigned long V_142 ;
F_80 (iommu, drhd) {
V_32 -> V_379 = F_52 ( sizeof( T_2 ) * V_380 ,
V_59 ) ;
if ( ! V_32 -> V_379 )
goto V_381;
}
F_360 () ;
F_80 (iommu, drhd) {
F_169 ( V_32 ) ;
F_125 ( & V_32 -> V_144 , V_142 ) ;
V_32 -> V_379 [ V_382 ] =
F_44 ( V_32 -> V_36 + V_383 ) ;
V_32 -> V_379 [ V_384 ] =
F_44 ( V_32 -> V_36 + V_385 ) ;
V_32 -> V_379 [ V_386 ] =
F_44 ( V_32 -> V_36 + V_387 ) ;
V_32 -> V_379 [ V_388 ] =
F_44 ( V_32 -> V_36 + V_389 ) ;
F_129 ( & V_32 -> V_144 , V_142 ) ;
}
return 0 ;
V_381:
F_80 (iommu, drhd)
F_176 ( V_32 -> V_379 ) ;
return - V_139 ;
}
static void F_362 ( void )
{
struct V_76 * V_77 ;
struct V_31 * V_32 = NULL ;
unsigned long V_142 ;
if ( F_358 () ) {
if ( V_336 )
F_363 ( L_68 ) ;
else
F_251 ( 1 , L_69 ) ;
return;
}
F_80 (iommu, drhd) {
F_125 ( & V_32 -> V_144 , V_142 ) ;
F_127 ( V_32 -> V_379 [ V_382 ] ,
V_32 -> V_36 + V_383 ) ;
F_127 ( V_32 -> V_379 [ V_384 ] ,
V_32 -> V_36 + V_385 ) ;
F_127 ( V_32 -> V_379 [ V_386 ] ,
V_32 -> V_36 + V_387 ) ;
F_127 ( V_32 -> V_379 [ V_388 ] ,
V_32 -> V_36 + V_389 ) ;
F_129 ( & V_32 -> V_144 , V_142 ) ;
}
F_80 (iommu, drhd)
F_176 ( V_32 -> V_379 ) ;
}
static void T_3 F_364 ( void )
{
F_365 ( & V_390 ) ;
}
static inline void F_364 ( void ) {}
int T_3 F_366 ( struct V_391 * V_392 , void * V_393 )
{
struct V_394 * V_282 ;
struct V_281 * V_395 ;
V_395 = F_52 ( sizeof( * V_395 ) , V_198 ) ;
if ( ! V_395 )
return - V_139 ;
V_395 -> V_396 = V_392 ;
V_282 = (struct V_394 * ) V_392 ;
V_395 -> V_283 = V_282 -> V_283 ;
V_395 -> V_284 = V_282 -> V_284 ;
V_395 -> V_106 = F_367 ( ( void * ) ( V_282 + 1 ) ,
( ( void * ) V_282 ) + V_282 -> V_392 . V_258 ,
& V_395 -> V_377 ) ;
if ( V_395 -> V_377 && V_395 -> V_106 == NULL ) {
F_176 ( V_395 ) ;
return - V_139 ;
}
F_241 ( & V_395 -> V_397 , & V_398 ) ;
return 0 ;
}
static struct V_399 * F_368 ( struct V_400 * V_401 )
{
struct V_399 * V_402 ;
struct V_400 * V_98 ;
F_369 (atsru, &dmar_atsr_units, list) {
V_98 = (struct V_400 * ) V_402 -> V_396 ;
if ( V_401 -> V_102 != V_98 -> V_102 )
continue;
if ( V_401 -> V_392 . V_258 != V_98 -> V_392 . V_258 )
continue;
if ( memcmp ( V_401 , V_98 , V_401 -> V_392 . V_258 ) == 0 )
return V_402 ;
}
return NULL ;
}
int F_370 ( struct V_391 * V_396 , void * V_393 )
{
struct V_400 * V_401 ;
struct V_399 * V_402 ;
if ( V_403 != V_404 && ! V_405 )
return 0 ;
V_401 = F_46 ( V_396 , struct V_400 , V_392 ) ;
V_402 = F_368 ( V_401 ) ;
if ( V_402 )
return 0 ;
V_402 = F_52 ( sizeof( * V_402 ) + V_396 -> V_258 , V_198 ) ;
if ( ! V_402 )
return - V_139 ;
V_402 -> V_396 = ( void * ) ( V_402 + 1 ) ;
memcpy ( V_402 -> V_396 , V_396 , V_396 -> V_258 ) ;
V_402 -> V_112 = V_401 -> V_33 & 0x1 ;
if ( ! V_402 -> V_112 ) {
V_402 -> V_106 = F_367 ( ( void * ) ( V_401 + 1 ) ,
( void * ) V_401 + V_401 -> V_392 . V_258 ,
& V_402 -> V_377 ) ;
if ( V_402 -> V_377 && V_402 -> V_106 == NULL ) {
F_176 ( V_402 ) ;
return - V_139 ;
}
}
F_371 ( & V_402 -> V_397 , & V_406 ) ;
return 0 ;
}
static void F_372 ( struct V_399 * V_402 )
{
F_373 ( & V_402 -> V_106 , & V_402 -> V_377 ) ;
F_176 ( V_402 ) ;
}
int F_374 ( struct V_391 * V_396 , void * V_393 )
{
struct V_400 * V_401 ;
struct V_399 * V_402 ;
V_401 = F_46 ( V_396 , struct V_400 , V_392 ) ;
V_402 = F_368 ( V_401 ) ;
if ( V_402 ) {
F_375 ( & V_402 -> V_397 ) ;
F_376 () ;
F_372 ( V_402 ) ;
}
return 0 ;
}
int F_377 ( struct V_391 * V_396 , void * V_393 )
{
int V_79 ;
struct V_94 * V_95 ;
struct V_400 * V_401 ;
struct V_399 * V_402 ;
V_401 = F_46 ( V_396 , struct V_400 , V_392 ) ;
V_402 = F_368 ( V_401 ) ;
if ( ! V_402 )
return 0 ;
if ( ! V_402 -> V_112 && V_402 -> V_106 && V_402 -> V_377 ) {
F_101 (atsru->devices, atsru->devices_cnt,
i, dev)
return - V_289 ;
}
return 0 ;
}
static int F_378 ( struct V_76 * V_407 )
{
int V_408 , V_83 = 0 ;
struct V_31 * V_32 = V_407 -> V_32 ;
if ( V_75 [ V_32 -> V_187 ] )
return 0 ;
if ( V_228 && ! F_298 ( V_32 -> V_81 ) ) {
F_250 ( L_70 ,
V_32 -> V_138 ) ;
return - V_409 ;
}
if ( ! F_83 ( V_32 -> V_81 ) &&
F_82 ( V_32 ) ) {
F_250 ( L_71 ,
V_32 -> V_138 ) ;
return - V_409 ;
}
V_408 = F_84 ( V_32 ) - 1 ;
if ( V_408 >= 0 && ! ( F_85 ( V_32 -> V_71 ) & ( 1 << V_408 ) ) ) {
F_250 ( L_72 ,
V_32 -> V_138 ) ;
return - V_409 ;
}
if ( V_32 -> V_146 & V_194 )
F_169 ( V_32 ) ;
V_75 [ V_32 -> V_187 ] = V_32 ;
V_83 = F_170 ( V_32 ) ;
if ( V_83 == 0 )
V_83 = F_122 ( V_32 ) ;
if ( V_83 )
goto V_107;
#ifdef F_149
if ( V_177 ( V_32 ) )
F_299 ( V_32 ) ;
#endif
if ( V_407 -> V_335 ) {
if ( V_336 )
F_167 ( V_32 ) ;
return 0 ;
}
F_282 ( V_32 ) ;
F_130 ( V_32 ) ;
#ifdef F_149
if ( V_177 ( V_32 ) && F_183 ( V_32 -> V_81 ) ) {
V_83 = F_303 ( V_32 ) ;
if ( V_83 )
goto V_410;
}
#endif
V_83 = F_304 ( V_32 ) ;
if ( V_83 )
goto V_410;
F_124 ( V_32 ) ;
V_32 -> V_188 . V_232 ( V_32 , 0 , 0 , 0 , V_155 ) ;
V_32 -> V_188 . V_189 ( V_32 , 0 , 0 , 0 , V_164 ) ;
F_168 ( V_32 ) ;
F_167 ( V_32 ) ;
return 0 ;
V_410:
F_178 ( V_32 ) ;
V_107:
F_182 ( V_32 ) ;
return V_83 ;
}
int F_379 ( struct V_76 * V_407 , bool V_411 )
{
int V_83 = 0 ;
struct V_31 * V_32 = V_407 -> V_32 ;
if ( ! V_405 )
return 0 ;
if ( V_32 == NULL )
return - V_44 ;
if ( V_411 ) {
V_83 = F_378 ( V_407 ) ;
} else {
F_178 ( V_32 ) ;
F_182 ( V_32 ) ;
}
return V_83 ;
}
static void F_380 ( void )
{
struct V_281 * V_395 , * V_412 ;
struct V_399 * V_402 , * V_413 ;
F_179 (rmrru, rmrr_n, &dmar_rmrr_units, list) {
F_233 ( & V_395 -> V_397 ) ;
F_373 ( & V_395 -> V_106 , & V_395 -> V_377 ) ;
F_176 ( V_395 ) ;
}
F_179 (atsru, atsr_n, &dmar_atsr_units, list) {
F_233 ( & V_402 -> V_397 ) ;
F_372 ( V_402 ) ;
}
}
int F_239 ( struct V_99 * V_95 )
{
int V_79 , V_83 = 1 ;
struct V_414 * V_87 ;
struct V_99 * V_415 = NULL ;
struct V_94 * V_98 ;
struct V_400 * V_401 ;
struct V_399 * V_402 ;
V_95 = F_97 ( V_95 ) ;
for ( V_87 = V_95 -> V_87 ; V_87 ; V_87 = V_87 -> V_117 ) {
V_415 = V_87 -> V_416 ;
if ( ! V_415 )
return 1 ;
if ( ! F_273 ( V_415 ) ||
F_275 ( V_415 ) == V_295 )
return 0 ;
if ( F_275 ( V_415 ) == V_417 )
break;
}
F_79 () ;
F_369 (atsru, &dmar_atsr_units, list) {
V_401 = F_46 ( V_402 -> V_396 , struct V_400 , V_392 ) ;
if ( V_401 -> V_102 != F_98 ( V_95 -> V_87 ) )
continue;
F_381 (atsru->devices, atsru->devices_cnt, i, tmp)
if ( V_98 == & V_415 -> V_95 )
goto V_107;
if ( V_402 -> V_112 )
goto V_107;
}
V_83 = 0 ;
V_107:
F_81 () ;
return V_83 ;
}
int F_382 ( struct V_418 * V_170 )
{
int V_83 = 0 ;
struct V_281 * V_395 ;
struct V_399 * V_402 ;
struct V_400 * V_401 ;
struct V_394 * V_282 ;
if ( ! V_405 && V_403 != V_404 )
return 0 ;
F_146 (rmrru, &dmar_rmrr_units, list) {
V_282 = F_46 ( V_395 -> V_396 ,
struct V_394 , V_392 ) ;
if ( V_170 -> V_419 == V_420 ) {
V_83 = F_383 ( V_170 , ( void * ) ( V_282 + 1 ) ,
( ( void * ) V_282 ) + V_282 -> V_392 . V_258 ,
V_282 -> V_102 , V_395 -> V_106 ,
V_395 -> V_377 ) ;
if( V_83 < 0 )
return V_83 ;
} else if ( V_170 -> V_419 == V_421 ) {
F_384 ( V_170 , V_282 -> V_102 ,
V_395 -> V_106 , V_395 -> V_377 ) ;
}
}
F_146 (atsru, &dmar_atsr_units, list) {
if ( V_402 -> V_112 )
continue;
V_401 = F_46 ( V_402 -> V_396 , struct V_400 , V_392 ) ;
if ( V_170 -> V_419 == V_420 ) {
V_83 = F_383 ( V_170 , ( void * ) ( V_401 + 1 ) ,
( void * ) V_401 + V_401 -> V_392 . V_258 ,
V_401 -> V_102 , V_402 -> V_106 ,
V_402 -> V_377 ) ;
if ( V_83 > 0 )
break;
else if( V_83 < 0 )
return V_83 ;
} else if ( V_170 -> V_419 == V_421 ) {
if ( F_384 ( V_170 , V_401 -> V_102 ,
V_402 -> V_106 , V_402 -> V_377 ) )
break;
}
}
return 0 ;
}
static int F_385 ( struct V_422 * V_423 ,
unsigned long V_424 , void * V_239 )
{
struct V_94 * V_95 = V_239 ;
struct V_39 * V_42 ;
if ( F_93 ( V_95 ) )
return 0 ;
if ( V_424 != V_421 )
return 0 ;
V_42 = F_234 ( V_95 ) ;
if ( ! V_42 )
return 0 ;
F_243 ( V_42 , V_95 ) ;
if ( ! F_67 ( V_42 ) && F_386 ( & V_42 -> V_106 ) )
F_181 ( V_42 ) ;
return 0 ;
}
static int F_387 ( struct V_422 * V_423 ,
unsigned long V_29 , void * V_425 )
{
struct V_426 * V_427 = V_425 ;
unsigned long long V_220 , V_111 ;
unsigned long V_369 , V_275 ;
switch ( V_29 ) {
case V_428 :
V_220 = V_427 -> V_128 << V_11 ;
V_111 = ( ( V_427 -> V_128 + V_427 -> V_251 ) << V_11 ) - 1 ;
if ( F_248 ( V_276 , V_220 , V_111 ) ) {
F_250 ( L_73 ,
V_220 , V_111 ) ;
return V_429 ;
}
break;
case V_430 :
case V_431 :
V_369 = F_13 ( V_427 -> V_128 ) ;
V_275 = F_13 ( V_427 -> V_128 + V_427 -> V_251 - 1 ) ;
while ( V_369 <= V_275 ) {
struct V_207 * V_207 ;
struct V_76 * V_77 ;
struct V_31 * V_32 ;
struct V_14 * V_135 ;
V_207 = F_388 ( & V_276 -> V_221 , V_369 ) ;
if ( V_207 == NULL ) {
F_143 ( L_74 ,
V_369 ) ;
break;
}
V_207 = F_389 ( & V_276 -> V_221 , V_207 ,
V_369 , V_275 ) ;
if ( V_207 == NULL ) {
F_250 ( L_75 ,
V_369 , V_275 ) ;
return V_429 ;
}
V_135 = F_120 ( V_276 , V_207 -> V_432 ,
V_207 -> V_433 ) ;
F_79 () ;
F_80 (iommu, drhd)
F_161 ( V_32 , V_276 ,
V_207 -> V_432 , F_390 ( V_207 ) ,
! V_135 , 0 ) ;
F_81 () ;
F_121 ( V_135 ) ;
V_369 = V_207 -> V_433 + 1 ;
F_391 ( V_207 ) ;
}
break;
}
return V_434 ;
}
static void F_392 ( unsigned int V_225 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_74 ; V_79 ++ ) {
struct V_31 * V_32 = V_75 [ V_79 ] ;
struct V_39 * V_42 ;
int V_55 ;
if ( ! V_32 )
continue;
for ( V_55 = 0 ; V_55 < F_171 ( V_32 -> V_71 ) ; V_55 ++ ) {
V_42 = F_50 ( V_32 , ( T_4 ) V_55 ) ;
if ( ! V_42 )
continue;
F_393 ( V_225 , & V_42 -> V_221 ) ;
}
}
}
static int F_394 ( unsigned int V_225 )
{
F_392 ( V_225 ) ;
F_205 ( V_225 ) ;
return 0 ;
}
static T_9 F_395 ( struct V_94 * V_95 ,
struct V_435 * V_436 ,
char * V_437 )
{
struct V_31 * V_32 = F_396 ( V_95 ) ;
T_2 V_438 = F_44 ( V_32 -> V_36 + V_439 ) ;
return sprintf ( V_437 , L_76 ,
F_397 ( V_438 ) , F_398 ( V_438 ) ) ;
}
static T_9 F_399 ( struct V_94 * V_95 ,
struct V_435 * V_436 ,
char * V_437 )
{
struct V_31 * V_32 = F_396 ( V_95 ) ;
return sprintf ( V_437 , L_77 , V_32 -> V_440 ) ;
}
static T_9 F_400 ( struct V_94 * V_95 ,
struct V_435 * V_436 ,
char * V_437 )
{
struct V_31 * V_32 = F_396 ( V_95 ) ;
return sprintf ( V_437 , L_77 , V_32 -> V_71 ) ;
}
static T_9 F_401 ( struct V_94 * V_95 ,
struct V_435 * V_436 ,
char * V_437 )
{
struct V_31 * V_32 = F_396 ( V_95 ) ;
return sprintf ( V_437 , L_77 , V_32 -> V_81 ) ;
}
static T_9 F_402 ( struct V_94 * V_95 ,
struct V_435 * V_436 ,
char * V_437 )
{
struct V_31 * V_32 = F_396 ( V_95 ) ;
return sprintf ( V_437 , L_78 , F_171 ( V_32 -> V_71 ) ) ;
}
static T_9 F_403 ( struct V_94 * V_95 ,
struct V_435 * V_436 ,
char * V_437 )
{
struct V_31 * V_32 = F_396 ( V_95 ) ;
return sprintf ( V_437 , L_79 , F_404 ( V_32 -> V_197 ,
F_171 ( V_32 -> V_71 ) ) ) ;
}
int T_3 F_405 ( void )
{
int V_83 = - V_215 ;
struct V_76 * V_77 ;
struct V_31 * V_32 ;
V_336 = F_406 () ;
if ( F_345 () ) {
if ( V_336 )
F_363 ( L_80 ) ;
return - V_139 ;
}
F_407 ( & V_441 ) ;
if ( F_408 () ) {
if ( V_336 )
F_363 ( L_81 ) ;
goto V_442;
}
if ( F_409 () < 0 ) {
if ( V_336 )
F_363 ( L_82 ) ;
goto V_442;
}
if ( V_443 || V_45 )
goto V_442;
if ( F_386 ( & V_398 ) )
F_48 ( L_83 ) ;
if ( F_386 ( & V_406 ) )
F_48 ( L_84 ) ;
if ( F_192 () ) {
if ( V_336 )
F_363 ( L_85 ) ;
goto V_444;
}
F_356 () ;
V_83 = F_292 () ;
if ( V_83 ) {
if ( V_336 )
F_363 ( L_86 ) ;
F_123 ( L_87 ) ;
goto V_444;
}
F_410 ( & V_441 ) ;
F_48 ( L_88 ) ;
#ifdef F_411
V_445 = 0 ;
#endif
V_446 = & V_447 ;
F_364 () ;
F_80 (iommu, drhd)
V_32 -> V_448 = F_412 ( NULL , V_32 ,
V_449 ,
L_89 , V_32 -> V_138 ) ;
F_413 ( & V_450 , & V_451 ) ;
F_414 ( & V_450 , & V_452 ) ;
if ( V_276 && ! V_228 )
F_415 ( & V_453 ) ;
F_416 ( V_454 , L_90 , NULL ,
F_394 ) ;
V_405 = 1 ;
return 0 ;
V_444:
F_207 ( & V_208 ) ;
V_442:
F_380 () ;
F_410 ( & V_441 ) ;
F_349 () ;
return V_83 ;
}
static int F_417 ( struct V_99 * V_101 , T_4 V_236 , void * V_237 )
{
struct V_31 * V_32 = V_237 ;
F_231 ( V_32 , F_214 ( V_236 ) , V_236 & 0xff ) ;
return 0 ;
}
static void F_418 ( struct V_31 * V_32 , struct V_94 * V_95 )
{
if ( ! V_32 || ! V_95 || ! F_95 ( V_95 ) )
return;
F_216 ( F_96 ( V_95 ) , & F_417 , V_32 ) ;
}
static void F_180 ( struct V_169 * V_170 )
{
struct V_31 * V_32 ;
unsigned long V_33 ;
F_145 ( & V_171 ) ;
if ( F_53 ( ! V_170 ) )
return;
V_32 = V_170 -> V_32 ;
if ( V_170 -> V_95 ) {
F_155 ( V_170 ) ;
F_418 ( V_32 , V_170 -> V_95 ) ;
}
F_232 ( V_170 ) ;
F_105 ( & V_32 -> V_114 , V_33 ) ;
F_190 ( V_170 -> V_42 , V_32 ) ;
F_106 ( & V_32 -> V_114 , V_33 ) ;
F_64 ( V_170 ) ;
}
static void F_243 ( struct V_39 * V_42 ,
struct V_94 * V_95 )
{
struct V_169 * V_170 ;
unsigned long V_33 ;
F_105 ( & V_171 , V_33 ) ;
V_170 = V_95 -> V_96 . V_32 ;
F_180 ( V_170 ) ;
F_106 ( & V_171 , V_33 ) ;
}
static int F_259 ( struct V_39 * V_42 , int V_222 )
{
int V_223 ;
F_193 ( & V_42 -> V_221 , V_123 , V_209 ,
V_210 ) ;
F_198 ( V_42 ) ;
V_42 -> V_134 = V_222 ;
V_223 = F_200 ( V_222 ) ;
V_42 -> V_1 = F_4 ( V_223 ) ;
V_42 -> V_80 = 0 ;
V_42 -> V_85 = 0 ;
V_42 -> V_86 = 0 ;
V_42 -> V_455 = 0 ;
V_42 -> V_119 = (struct V_27 * ) F_54 ( V_42 -> V_122 ) ;
if ( ! V_42 -> V_119 )
return - V_139 ;
F_102 ( V_42 , V_42 -> V_119 , V_224 ) ;
return 0 ;
}
static struct V_40 * F_419 ( unsigned type )
{
struct V_39 * V_39 ;
struct V_40 * V_42 ;
if ( type != V_456 )
return NULL ;
V_39 = F_186 ( V_65 ) ;
if ( ! V_39 ) {
F_123 ( L_91 ) ;
return NULL ;
}
if ( F_259 ( V_39 , V_72 ) ) {
F_123 ( L_92 ) ;
F_181 ( V_39 ) ;
return NULL ;
}
F_87 ( V_39 ) ;
V_42 = & V_39 -> V_42 ;
V_42 -> V_457 . V_458 = 0 ;
V_42 -> V_457 . V_459 = F_420 ( V_39 -> V_134 ) ;
V_42 -> V_457 . V_460 = true ;
return V_42 ;
}
static void F_421 ( struct V_40 * V_42 )
{
F_181 ( F_45 ( V_42 ) ) ;
}
static int F_422 ( struct V_40 * V_42 ,
struct V_94 * V_95 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_31 * V_32 ;
int V_67 ;
T_6 V_87 , V_88 ;
if ( F_268 ( V_95 ) ) {
F_423 ( V_95 , L_93 ) ;
return - V_461 ;
}
if ( F_309 ( F_218 ( V_95 ) ) ) {
struct V_39 * V_462 ;
V_462 = F_234 ( V_95 ) ;
if ( V_462 ) {
F_79 () ;
F_243 ( V_462 , V_95 ) ;
F_81 () ;
if ( ! F_67 ( V_462 ) &&
F_386 ( & V_462 -> V_106 ) )
F_181 ( V_462 ) ;
}
}
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_215 ;
V_67 = F_2 ( V_32 -> V_1 ) ;
if ( V_67 > F_202 ( V_32 -> V_71 ) )
V_67 = F_202 ( V_32 -> V_71 ) ;
if ( V_39 -> V_455 > ( 1LL << V_67 ) ) {
F_123 ( L_94
L_95 ,
V_463 , V_67 , V_39 -> V_455 ) ;
return - V_287 ;
}
V_39 -> V_134 = V_67 ;
while ( V_32 -> V_1 < V_39 -> V_1 ) {
struct V_27 * V_28 ;
V_28 = V_39 -> V_119 ;
if ( F_38 ( V_28 ) ) {
V_39 -> V_119 = (struct V_27 * )
F_90 ( F_35 ( V_28 ) ) ;
F_57 ( V_28 ) ;
}
V_39 -> V_1 -- ;
}
return F_265 ( V_39 , V_95 ) ;
}
static void F_424 ( struct V_40 * V_42 ,
struct V_94 * V_95 )
{
F_243 ( F_45 ( V_42 ) , V_95 ) ;
}
static int F_425 ( struct V_40 * V_42 ,
unsigned long V_207 , T_1 V_464 ,
T_5 V_58 , int V_465 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
V_24 V_455 ;
int V_252 = 0 ;
int V_83 ;
if ( V_465 & V_466 )
V_252 |= V_124 ;
if ( V_465 & V_467 )
V_252 |= V_125 ;
if ( ( V_465 & V_468 ) && V_39 -> V_85 )
V_252 |= V_257 ;
V_455 = V_207 + V_58 ;
if ( V_39 -> V_455 < V_455 ) {
V_24 V_111 ;
V_111 = F_420 ( V_39 -> V_134 ) + 1 ;
if ( V_111 < V_455 ) {
F_123 ( L_94
L_95 ,
V_463 , V_39 -> V_134 , V_455 ) ;
return - V_287 ;
}
V_39 -> V_455 = V_455 ;
}
V_58 = F_219 ( V_464 , V_58 ) ;
V_83 = F_230 ( V_39 , V_207 >> V_12 ,
V_464 >> V_12 , V_58 , V_252 ) ;
return V_83 ;
}
static T_5 F_426 ( struct V_40 * V_42 ,
unsigned long V_207 , T_5 V_58 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_14 * V_135 = NULL ;
struct V_31 * V_32 ;
unsigned long V_128 , V_129 ;
unsigned int V_469 ;
int V_73 , V_5 = 0 ;
F_75 ( ! F_109 ( V_39 , V_207 >> V_12 , & V_5 ) ) ;
if ( V_58 < V_123 << F_6 ( V_5 ) )
V_58 = V_123 << F_6 ( V_5 ) ;
V_128 = V_207 >> V_12 ;
V_129 = ( V_207 + V_58 - 1 ) >> V_12 ;
V_135 = F_120 ( V_39 , V_128 , V_129 ) ;
V_469 = V_129 - V_128 + 1 ;
F_76 (iommu_id, dmar_domain) {
V_32 = V_75 [ V_73 ] ;
F_161 ( V_75 [ V_73 ] , V_39 ,
V_128 , V_469 , ! V_135 , 0 ) ;
}
F_121 ( V_135 ) ;
if ( V_39 -> V_455 == V_207 + V_58 )
V_39 -> V_455 = V_207 ;
return V_58 ;
}
static T_1 F_427 ( struct V_40 * V_42 ,
V_260 V_207 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_27 * V_28 ;
int V_5 = 0 ;
V_24 V_470 = 0 ;
V_28 = F_109 ( V_39 , V_207 >> V_12 , & V_5 ) ;
if ( V_28 )
V_470 = F_35 ( V_28 ) ;
return V_470 ;
}
static bool F_428 ( enum V_471 V_71 )
{
if ( V_71 == V_472 )
return F_82 ( NULL ) == 1 ;
if ( V_71 == V_473 )
return V_474 == 1 ;
return false ;
}
static int F_429 ( struct V_94 * V_95 )
{
struct V_31 * V_32 ;
struct V_475 * V_476 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_215 ;
F_430 ( V_32 -> V_448 , V_95 ) ;
V_476 = F_431 ( V_95 ) ;
if ( F_432 ( V_476 ) )
return F_433 ( V_476 ) ;
F_434 ( V_476 ) ;
return 0 ;
}
static void F_435 ( struct V_94 * V_95 )
{
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return;
F_436 ( V_95 ) ;
F_437 ( V_32 -> V_448 , V_95 ) ;
}
static inline unsigned long F_438 ( struct V_31 * V_32 )
{
if ( F_439 ( V_32 -> V_81 ) < 5 )
return 0 ;
return F_440 ( ( unsigned long * ) & V_32 -> V_477 ,
V_478 ) - 5 ;
}
int F_441 ( struct V_31 * V_32 , struct V_479 * V_480 )
{
struct V_169 * V_170 ;
struct V_22 * V_23 ;
struct V_39 * V_42 ;
unsigned long V_33 ;
V_24 V_481 ;
int V_83 ;
V_42 = F_312 ( V_480 -> V_95 ) ;
if ( ! V_42 )
return - V_44 ;
F_105 ( & V_171 , V_33 ) ;
F_211 ( & V_32 -> V_114 ) ;
V_83 = - V_44 ;
V_170 = V_480 -> V_95 -> V_96 . V_32 ;
if ( ! V_170 || ! V_170 -> V_176 )
goto V_107;
V_23 = F_88 ( V_32 , V_170 -> V_87 , V_170 -> V_88 , 0 ) ;
if ( F_53 ( ! V_23 ) )
goto V_107;
V_481 = V_23 [ 0 ] . V_19 ;
V_480 -> V_55 = V_42 -> V_186 [ V_32 -> V_187 ] ;
V_480 -> V_181 = F_442 ( V_170 -> V_87 , V_170 -> V_88 ) ;
if ( ! ( V_481 & V_482 ) ) {
V_23 [ 1 ] . V_21 = ( V_24 ) F_92 ( V_32 -> V_483 ) ;
V_23 [ 1 ] . V_19 = ( V_24 ) F_92 ( V_32 -> V_484 ) |
F_438 ( V_32 ) ;
F_443 () ;
if ( ( V_481 & V_485 ) == ( V_229 << 2 ) ) {
V_481 &= ~ V_485 ;
if ( V_170 -> V_173 )
V_481 |= V_486 << 2 ;
else
V_481 |= V_487 << 2 ;
}
V_481 |= V_482 ;
if ( V_32 -> V_483 )
V_481 |= V_488 ;
if ( V_170 -> V_178 )
V_481 |= V_489 ;
V_23 [ 0 ] . V_19 = V_481 ;
F_443 () ;
V_32 -> V_188 . V_232 ( V_32 , V_480 -> V_55 , V_480 -> V_181 ,
V_233 ,
V_157 ) ;
}
if ( ! V_170 -> V_177 )
F_148 ( V_170 ) ;
if ( V_170 -> V_175 ) {
V_480 -> V_490 = 1 ;
V_480 -> V_182 = V_170 -> V_180 ;
if ( V_480 -> V_182 >= V_491 )
V_480 -> V_182 = 0 ;
}
V_83 = 0 ;
V_107:
F_212 ( & V_32 -> V_114 ) ;
F_106 ( & V_171 , V_33 ) ;
return V_83 ;
}
struct V_31 * F_444 ( struct V_94 * V_95 )
{
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
if ( F_93 ( V_95 ) ) {
F_423 ( V_95 ,
L_96 ) ;
return NULL ;
}
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ( ! V_32 ) ) {
F_311 ( V_95 , L_97 ) ;
return NULL ;
}
if ( ! V_32 -> V_484 ) {
F_311 ( V_95 , L_98 ) ;
return NULL ;
}
return V_32 ;
}
static void F_445 ( struct V_99 * V_95 )
{
F_48 ( L_99 ) ;
V_46 = 0 ;
}
static void F_446 ( struct V_99 * V_95 )
{
F_48 ( L_100 ) ;
V_150 = 1 ;
}
static void F_447 ( struct V_99 * V_95 )
{
unsigned short V_492 ;
if ( F_448 ( V_95 , V_493 , & V_492 ) )
return;
if ( ! ( V_492 & V_494 ) ) {
F_48 ( L_101 ) ;
V_46 = 0 ;
} else if ( V_46 ) {
F_48 ( L_102 ) ;
V_48 = 1 ;
}
}
static void T_3 F_301 ( void )
{
struct V_99 * V_101 ;
T_10 V_495 ;
V_101 = F_449 ( V_496 , 0x3a3e , NULL ) ;
if ( ! V_101 )
return;
F_257 ( V_101 ) ;
V_101 = F_449 ( V_496 , 0x342e , NULL ) ;
if ( ! V_101 )
return;
if ( F_450 ( V_101 , 0x188 , & V_495 ) ) {
F_257 ( V_101 ) ;
return;
}
F_257 ( V_101 ) ;
if ( V_495 & 1 )
return;
V_495 &= 0x1c ;
if ( V_495 == 0x10 )
return;
if ( ! V_495 ) {
F_251 ( 1 , L_103
L_36 ,
F_252 ( V_277 ) ,
F_252 ( V_278 ) ,
F_252 ( V_279 ) ) ;
V_53 |= V_291 ;
return;
}
F_250 ( L_104 ,
V_495 ) ;
}
