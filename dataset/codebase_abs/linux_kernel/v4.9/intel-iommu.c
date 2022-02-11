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
V_226 = V_231 ;
else
V_226 = V_227 ;
F_29 ( V_23 , F_92 ( V_119 ) ) ;
F_30 ( V_23 , V_32 -> V_1 ) ;
} else {
F_30 ( V_23 , V_32 -> V_232 ) ;
}
F_28 ( V_23 , V_226 ) ;
F_27 ( V_23 ) ;
F_26 ( V_23 ) ;
F_102 ( V_42 , V_23 , sizeof( * V_23 ) ) ;
if ( F_166 ( V_32 -> V_71 ) ) {
V_32 -> V_188 . V_233 ( V_32 , 0 ,
( ( ( T_4 ) V_87 ) << 8 ) | V_88 ,
V_234 ,
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
T_4 V_235 , void * V_236 )
{
struct V_237 * V_238 = V_236 ;
return F_208 ( V_238 -> V_42 , V_238 -> V_32 ,
F_214 ( V_235 ) , V_235 & 0xff ) ;
}
static int
F_215 ( struct V_39 * V_42 , struct V_94 * V_95 )
{
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
struct V_237 V_238 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_215 ;
if ( ! F_95 ( V_95 ) )
return F_208 ( V_42 , V_32 , V_87 , V_88 ) ;
V_238 . V_42 = V_42 ;
V_238 . V_32 = V_32 ;
return F_216 ( F_96 ( V_95 ) ,
& F_213 , & V_238 ) ;
}
static int F_217 ( struct V_99 * V_101 ,
T_4 V_235 , void * V_236 )
{
struct V_31 * V_32 = V_236 ;
return ! F_104 ( V_32 , F_214 ( V_235 ) , V_235 & 0xff ) ;
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
static inline unsigned long F_219 ( unsigned long V_239 ,
T_5 V_58 )
{
V_239 &= ~ V_240 ;
return F_220 ( V_239 + V_58 ) >> V_12 ;
}
static inline int F_221 ( struct V_39 * V_42 ,
unsigned long V_241 ,
unsigned long V_242 ,
unsigned long V_183 )
{
int V_243 , V_5 = 1 ;
unsigned long V_244 ;
V_243 = V_42 -> V_86 ;
V_244 = V_241 | V_242 ;
while ( V_243 && ! ( V_244 & ~ V_245 ) ) {
V_183 >>= V_246 ;
if ( ! V_183 )
break;
V_244 >>= V_246 ;
V_5 ++ ;
V_243 -- ;
}
return V_5 ;
}
static int F_222 ( struct V_39 * V_42 , unsigned long V_241 ,
struct V_247 * V_248 , unsigned long V_249 ,
unsigned long V_250 , int V_251 )
{
struct V_27 * V_130 = NULL , * V_28 = NULL ;
T_1 V_252 ( V_121 ) ;
unsigned long V_253 = 0 ;
unsigned int V_254 = 0 ;
unsigned long V_255 = 0 ;
F_75 ( ! F_68 ( V_42 , V_241 + V_250 - 1 ) ) ;
if ( ( V_251 & ( V_124 | V_125 ) ) == 0 )
return - V_44 ;
V_251 &= V_124 | V_125 | V_256 ;
if ( ! V_248 ) {
V_253 = V_250 ;
V_121 = ( ( T_1 ) V_249 << V_12 ) | V_251 ;
}
while ( V_250 > 0 ) {
T_7 V_98 ;
if ( ! V_253 ) {
V_253 = F_219 ( V_248 -> V_118 , V_248 -> V_257 ) ;
V_248 -> V_258 = ( ( V_259 ) V_241 << V_12 ) + V_248 -> V_118 ;
V_248 -> V_260 = V_248 -> V_257 ;
V_121 = F_223 ( F_224 ( V_248 ) ) | V_251 ;
V_249 = V_121 >> V_12 ;
}
if ( ! V_28 ) {
V_254 = F_221 ( V_42 , V_241 , V_249 , V_253 ) ;
V_130 = V_28 = F_109 ( V_42 , V_241 , & V_254 ) ;
if ( ! V_28 )
return - V_139 ;
if ( V_254 > 1 ) {
unsigned long V_261 , V_262 ;
V_121 |= V_30 ;
V_255 = F_11 ( V_254 ) ;
V_261 = V_253 / V_255 ;
V_262 = V_241 + V_261 * V_255 - 1 ;
F_115 ( V_42 , V_241 , V_262 ) ;
} else {
V_121 &= ~ ( T_7 ) V_30 ;
}
}
V_98 = F_225 ( & V_28 -> V_29 , 0ULL , V_121 ) ;
if ( V_98 ) {
static int V_263 = 5 ;
F_226 ( L_29 ,
V_241 , V_98 , ( unsigned long long ) V_121 ) ;
if ( V_263 ) {
V_263 -- ;
F_227 ( NULL ) ;
}
F_53 ( 1 ) ;
}
V_255 = F_11 ( V_254 ) ;
F_75 ( V_250 < V_255 ) ;
F_75 ( V_253 < V_255 ) ;
V_250 -= V_255 ;
V_241 += V_255 ;
V_249 += V_255 ;
V_121 += V_255 * V_123 ;
V_253 -= V_255 ;
V_28 ++ ;
if ( ! V_250 || F_40 ( V_28 ) ||
( V_254 > 1 && V_253 < V_255 ) ) {
F_102 ( V_42 , V_130 ,
( void * ) V_28 - ( void * ) V_130 ) ;
V_28 = NULL ;
}
if ( ! V_253 && V_250 )
V_248 = F_228 ( V_248 ) ;
}
return 0 ;
}
static inline int F_229 ( struct V_39 * V_42 , unsigned long V_241 ,
struct V_247 * V_248 , unsigned long V_250 ,
int V_251 )
{
return F_222 ( V_42 , V_241 , V_248 , 0 , V_250 , V_251 ) ;
}
static inline int F_230 ( struct V_39 * V_42 , unsigned long V_241 ,
unsigned long V_249 , unsigned long V_250 ,
int V_251 )
{
return F_222 ( V_42 , V_241 , NULL , V_249 , V_250 , V_251 ) ;
}
static void F_231 ( struct V_31 * V_32 , T_6 V_87 , T_6 V_88 )
{
if ( ! V_32 )
return;
F_107 ( V_32 , V_87 , V_88 ) ;
V_32 -> V_188 . V_233 ( V_32 , 0 , 0 , 0 ,
V_155 ) ;
V_32 -> V_188 . V_189 ( V_32 , 0 , 0 , 0 , V_164 ) ;
}
static inline void F_232 ( struct V_169 * V_170 )
{
F_145 ( & V_171 ) ;
F_233 ( & V_170 -> V_264 ) ;
F_233 ( & V_170 -> V_265 ) ;
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
F_238 ( V_101 , V_266 ) &&
F_239 ( V_101 ) )
V_170 -> V_173 = 1 ;
if ( F_89 ( V_32 ) ) {
if ( V_177 ( V_32 ) ) {
int V_267 = F_240 ( V_101 ) ;
if ( V_267 >= 0 )
V_170 -> V_176 = V_267 | 1 ;
}
if ( V_170 -> V_173 && F_183 ( V_32 -> V_81 ) &&
F_238 ( V_101 , V_268 ) )
V_170 -> V_178 = 1 ;
}
}
F_105 ( & V_171 , V_33 ) ;
if ( V_95 )
V_78 = F_234 ( V_95 ) ;
if ( ! V_78 ) {
struct V_169 * V_269 ;
V_269 = F_235 ( V_32 -> V_102 , V_87 , V_88 ) ;
if ( V_269 ) {
V_78 = V_269 -> V_42 ;
V_269 -> V_95 = V_95 ;
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
F_241 ( & V_170 -> V_264 , & V_42 -> V_106 ) ;
F_241 ( & V_170 -> V_265 , & V_270 ) ;
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
static int F_244 ( struct V_99 * V_101 , T_4 V_235 , void * V_236 )
{
* ( T_4 * ) V_236 = V_235 ;
return 0 ;
}
static struct V_39 * F_245 ( struct V_94 * V_95 , int V_134 )
{
struct V_169 * V_170 = NULL ;
struct V_39 * V_42 = NULL ;
struct V_31 * V_32 ;
T_4 V_271 , V_272 ;
unsigned long V_33 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return NULL ;
V_271 = ( ( T_4 ) V_87 << 8 ) | V_88 ;
if ( F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_95 ) ;
F_216 ( V_101 , F_244 , & V_272 ) ;
F_105 ( & V_171 , V_33 ) ;
V_170 = F_235 ( F_98 ( V_101 -> V_87 ) ,
F_214 ( V_272 ) ,
V_272 & 0xff ) ;
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
T_4 V_271 , V_272 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return NULL ;
V_271 = ( ( T_4 ) V_87 << 8 ) | V_88 ;
if ( F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_95 ) ;
F_216 ( V_101 , F_244 , & V_272 ) ;
if ( V_271 != V_272 ) {
V_98 = F_236 ( V_32 , F_214 ( V_272 ) ,
V_272 & 0xff , NULL , V_42 ) ;
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
unsigned long V_273 = V_220 >> V_12 ;
unsigned long V_274 = V_111 >> V_12 ;
if ( ! F_195 ( & V_42 -> V_221 , F_12 ( V_273 ) ,
F_12 ( V_274 ) ) ) {
F_123 ( L_31 ) ;
return - V_139 ;
}
F_143 ( L_32 , V_220 , V_111 ) ;
F_112 ( V_42 , V_273 , V_274 ) ;
return F_230 ( V_42 , V_273 , V_273 ,
V_274 - V_273 + 1 ,
V_124 | V_125 ) ;
}
static int F_249 ( struct V_94 * V_95 ,
struct V_39 * V_42 ,
unsigned long long V_220 ,
unsigned long long V_111 )
{
if ( V_42 == V_275 && V_228 ) {
F_250 ( L_33 ,
F_242 ( V_95 ) , V_220 , V_111 ) ;
return 0 ;
}
F_48 ( L_34 ,
F_242 ( V_95 ) , V_220 , V_111 ) ;
if ( V_111 < V_220 ) {
F_251 ( 1 , L_35
L_36 ,
F_252 ( V_276 ) ,
F_252 ( V_277 ) ,
F_252 ( V_278 ) ) ;
return - V_279 ;
}
if ( V_111 >> F_2 ( V_42 -> V_1 ) ) {
F_251 ( 1 , L_37
L_36 ,
F_2 ( V_42 -> V_1 ) ,
F_252 ( V_276 ) ,
F_252 ( V_277 ) ,
F_252 ( V_278 ) ) ;
return - V_279 ;
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
static inline int F_254 ( struct V_280 * V_281 ,
struct V_94 * V_95 )
{
if ( V_95 -> V_96 . V_32 == V_97 )
return 0 ;
return F_253 ( V_95 , V_281 -> V_282 ,
V_281 -> V_283 ) ;
}
static inline void F_255 ( void )
{
struct V_99 * V_101 ;
int V_83 ;
V_101 = F_256 ( V_284 << 8 , NULL ) ;
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
static int T_3 F_258 ( int V_285 )
{
int V_122 , V_83 = 0 ;
V_275 = F_186 ( V_66 ) ;
if ( ! V_275 )
return - V_286 ;
if ( F_259 ( V_275 , V_72 ) ) {
F_181 ( V_275 ) ;
return - V_286 ;
}
F_143 ( L_40 ) ;
if ( V_285 )
return 0 ;
F_260 (nid) {
unsigned long V_128 , V_262 ;
int V_79 ;
F_261 (i, nid, &start_pfn, &end_pfn, NULL) {
V_83 = F_248 ( V_275 ,
F_262 ( V_128 ) , F_262 ( V_262 ) ) ;
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
return ( V_170 -> V_42 == V_275 ) ;
return 0 ;
}
static int F_265 ( struct V_39 * V_42 , struct V_94 * V_95 )
{
struct V_39 * V_287 ;
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_215 ;
V_287 = F_236 ( V_32 , V_87 , V_88 , V_95 , V_42 ) ;
if ( V_287 != V_42 )
return - V_288 ;
return 0 ;
}
static bool F_266 ( struct V_94 * V_95 )
{
struct V_280 * V_281 ;
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
static int F_271 ( struct V_94 * V_95 , int V_289 )
{
if ( F_95 ( V_95 ) ) {
struct V_99 * V_101 = F_96 ( V_95 ) ;
if ( F_268 ( V_95 ) )
return 0 ;
if ( ( V_53 & V_290 ) && F_272 ( V_101 ) )
return 1 ;
if ( ( V_53 & V_54 ) && F_270 ( V_101 ) )
return 1 ;
if ( ! ( V_53 & V_291 ) )
return 0 ;
if ( ! F_273 ( V_101 ) ) {
if ( ! F_274 ( V_101 -> V_87 ) )
return 0 ;
if ( V_101 -> V_292 >> 8 == V_293 )
return 0 ;
} else if ( F_275 ( V_101 ) == V_294 )
return 0 ;
} else {
if ( F_266 ( V_95 ) )
return 0 ;
}
if ( ! V_289 ) {
V_24 V_295 = * V_95 -> V_295 ;
if ( V_95 -> V_296 &&
V_95 -> V_296 < V_295 )
V_295 = V_95 -> V_296 ;
return V_295 >= F_276 ( V_95 ) ;
}
return 1 ;
}
static int T_3 F_277 ( struct V_94 * V_95 , int V_285 )
{
int V_83 ;
if ( ! F_271 ( V_95 , 1 ) )
return 0 ;
V_83 = F_265 ( V_275 , V_95 ) ;
if ( ! V_83 )
F_48 ( L_41 ,
V_285 ? L_42 : L_43 , F_242 ( V_95 ) ) ;
else if ( V_83 == - V_215 )
V_83 = 0 ;
return V_83 ;
}
static int T_3 F_278 ( int V_285 )
{
struct V_99 * V_101 = NULL ;
struct V_76 * V_77 ;
struct V_31 * V_32 ;
struct V_94 * V_95 ;
int V_79 ;
int V_83 = 0 ;
F_197 (pdev) {
V_83 = F_277 ( & V_101 -> V_95 , V_285 ) ;
if ( V_83 )
return V_83 ;
}
F_80 (iommu, drhd)
F_101 (drhd->devices, drhd->devices_cnt, i, dev) {
struct V_297 * V_298 ;
struct V_299 * V_300 ;
if ( V_95 -> V_87 != & V_301 )
continue;
V_300 = F_279 ( V_95 ) ;
F_280 ( & V_300 -> V_302 ) ;
F_146 (pn, &adev->physical_node_list, node) {
V_83 = F_277 ( V_298 -> V_95 , V_285 ) ;
if ( V_83 )
break;
}
F_281 ( & V_300 -> V_302 ) ;
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
V_32 -> V_188 . V_233 = F_132 ;
V_32 -> V_188 . V_189 = F_137 ;
F_48 ( L_44 ,
V_32 -> V_138 ) ;
} else {
V_32 -> V_188 . V_233 = V_303 ;
V_32 -> V_188 . V_189 = V_304 ;
F_48 ( L_45 , V_32 -> V_138 ) ;
}
}
static int F_286 ( struct V_31 * V_32 ,
struct V_17 * V_305 ,
struct V_22 * * V_306 ,
int V_87 , bool V_307 )
{
int V_308 , V_309 = 0 , V_57 , V_88 , V_83 = 0 , V_55 ;
struct V_22 * V_310 = NULL , V_311 ;
struct V_22 * V_312 = NULL ;
struct V_17 V_18 ;
T_1 V_313 ;
V_308 = V_307 ? V_87 * 2 : V_87 ;
memcpy ( & V_18 , V_305 , sizeof( V_18 ) ) ;
for ( V_88 = 0 ; V_88 < 256 ; V_88 ++ ) {
V_57 = ( V_307 ? V_88 * 2 : V_88 ) % 256 ;
if ( V_57 == 0 ) {
if ( V_310 ) {
V_306 [ V_308 ] = V_310 ;
F_91 ( V_32 , V_310 ,
V_123 ) ;
V_309 = 1 ;
}
if ( V_312 )
F_287 ( V_312 ) ;
V_83 = 0 ;
if ( V_88 < 0x80 )
V_313 = F_18 ( & V_18 ) ;
else
V_313 = F_19 ( & V_18 ) ;
if ( ! V_313 ) {
if ( V_307 && V_88 == 0 ) {
V_88 = 0x7f ;
continue;
} else {
goto V_107;
}
}
V_83 = - V_139 ;
V_312 = F_288 ( V_313 , V_224 ,
V_314 ) ;
if ( ! V_312 )
goto V_107;
V_310 = F_54 ( V_32 -> V_60 ) ;
if ( ! V_310 )
goto V_315;
V_83 = 0 ;
}
memcpy ( & V_311 , V_312 + V_57 , sizeof( V_311 ) ) ;
if ( ! F_24 ( & V_311 ) )
continue;
V_55 = F_32 ( & V_311 ) ;
if ( V_55 >= 0 && V_55 < F_171 ( V_32 -> V_71 ) )
F_177 ( V_55 , V_32 -> V_197 ) ;
F_20 ( & V_311 ) ;
F_22 ( & V_311 ) ;
V_310 [ V_57 ] = V_311 ;
}
V_306 [ V_308 + V_309 ] = V_310 ;
F_91 ( V_32 , V_310 , V_123 ) ;
V_315:
F_289 ( V_312 ) ;
V_107:
return V_83 ;
}
static int F_290 ( struct V_31 * V_32 )
{
struct V_22 * * V_316 ;
struct V_17 * V_317 ;
T_1 V_318 ;
int V_319 ;
unsigned long V_33 ;
V_24 V_320 ;
int V_87 , V_83 ;
bool V_321 , V_307 ;
V_320 = V_160 ( V_32 -> V_36 + V_145 ) ;
V_307 = ! ! ( V_320 & V_143 ) ;
V_321 = ! ! F_291 ( V_32 -> V_81 ) ;
if ( V_321 != V_307 )
return - V_44 ;
V_318 = V_320 & V_20 ;
if ( ! V_318 )
return - V_44 ;
V_317 = F_288 ( V_318 , V_224 , V_314 ) ;
if ( ! V_317 )
return - V_139 ;
V_319 = V_307 ? 512 : 256 ;
V_83 = - V_139 ;
V_316 = F_52 ( V_319 * sizeof( void * ) , V_198 ) ;
if ( ! V_316 )
goto V_315;
for ( V_87 = 0 ; V_87 < 256 ; V_87 ++ ) {
V_83 = F_286 ( V_32 , & V_317 [ V_87 ] ,
V_316 , V_87 , V_307 ) ;
if ( V_83 ) {
F_123 ( L_46 ,
V_32 -> V_138 , V_87 ) ;
continue;
}
}
F_105 ( & V_32 -> V_114 , V_33 ) ;
for ( V_87 = 0 ; V_87 < 256 ; V_87 ++ ) {
int V_57 = V_307 ? V_87 * 2 : V_87 ;
V_24 V_29 ;
if ( V_316 [ V_57 ] ) {
V_29 = F_92 ( V_316 [ V_57 ] ) | 1 ;
V_32 -> V_17 [ V_87 ] . V_19 = V_29 ;
}
if ( ! V_307 || ! V_316 [ V_57 + 1 ] )
continue;
V_29 = F_92 ( V_316 [ V_57 + 1 ] ) | 1 ;
V_32 -> V_17 [ V_87 ] . V_21 = V_29 ;
}
F_106 ( & V_32 -> V_114 , V_33 ) ;
F_176 ( V_316 ) ;
F_91 ( V_32 , V_32 -> V_17 , V_224 ) ;
V_83 = 0 ;
V_315:
F_289 ( V_317 ) ;
return V_83 ;
}
static int T_3 F_292 ( void )
{
struct V_76 * V_77 ;
struct V_280 * V_281 ;
bool V_322 = false ;
struct V_94 * V_95 ;
struct V_31 * V_32 ;
int V_79 , V_83 , V_225 ;
F_293 (drhd) {
if ( V_74 < V_323 ) {
V_74 ++ ;
continue;
}
F_294 ( L_47 , V_323 ) ;
}
if ( V_74 < V_323 )
V_74 = V_323 ;
V_75 = F_174 ( V_74 , sizeof( struct V_31 * ) ,
V_198 ) ;
if ( ! V_75 ) {
F_123 ( L_48 ) ;
V_83 = - V_139 ;
goto error;
}
F_204 (cpu) {
struct V_324 * V_325 = F_295 ( & V_326 ,
V_225 ) ;
V_325 -> V_327 = F_52 ( V_74 *
sizeof( struct V_328 ) ,
V_198 ) ;
if ( ! V_325 -> V_327 ) {
V_83 = - V_139 ;
goto V_329;
}
F_173 ( & V_325 -> V_114 ) ;
F_296 ( & V_325 -> V_330 , F_205 , V_225 ) ;
}
F_80 (iommu, drhd) {
V_75 [ V_32 -> V_187 ] = V_32 ;
F_282 ( V_32 ) ;
V_83 = F_170 ( V_32 ) ;
if ( V_83 )
goto V_331;
F_43 ( V_32 ) ;
if ( F_41 ( V_32 ) && ! F_297 () ) {
F_169 ( V_32 ) ;
F_42 ( V_32 ) ;
F_250 ( L_49 ,
V_32 -> V_138 ) ;
}
V_83 = F_122 ( V_32 ) ;
if ( V_83 )
goto V_331;
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
V_322 = true ;
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
V_32 -> V_188 . V_233 ( V_32 , 0 , 0 , 0 , V_155 ) ;
V_32 -> V_188 . V_189 ( V_32 , 0 , 0 , 0 , V_164 ) ;
}
if ( V_332 )
V_53 |= V_291 ;
#ifdef F_300
V_53 |= V_54 ;
#endif
if ( V_53 ) {
V_83 = F_258 ( V_228 ) ;
if ( V_83 )
goto V_331;
}
F_301 () ;
if ( V_322 )
goto V_333;
if ( V_53 ) {
V_83 = F_278 ( V_228 ) ;
if ( V_83 ) {
F_226 ( L_53 ) ;
goto V_331;
}
}
F_48 ( L_54 ) ;
F_267 (rmrr) {
F_101 (rmrr->devices, rmrr->devices_cnt,
i, dev) {
V_83 = F_254 ( V_281 , V_95 ) ;
if ( V_83 )
F_123 ( L_55 ) ;
}
}
F_255 () ;
V_333:
F_302 (iommu, drhd) {
if ( V_77 -> V_334 ) {
if ( V_335 )
F_167 ( V_32 ) ;
continue;
}
F_130 ( V_32 ) ;
#ifdef F_149
if ( V_177 ( V_32 ) && F_183 ( V_32 -> V_81 ) ) {
V_83 = F_303 ( V_32 ) ;
if ( V_83 )
goto V_331;
}
#endif
V_83 = F_304 ( V_32 ) ;
if ( V_83 )
goto V_331;
if ( ! F_41 ( V_32 ) )
F_168 ( V_32 ) ;
F_167 ( V_32 ) ;
}
return 0 ;
V_331:
F_80 (iommu, drhd) {
F_178 ( V_32 ) ;
F_182 ( V_32 ) ;
}
V_329:
F_204 (cpu)
F_176 ( F_295 ( & V_326 , V_225 ) -> V_327 ) ;
F_176 ( V_75 ) ;
error:
return V_83 ;
}
static unsigned long F_305 ( struct V_94 * V_95 ,
struct V_39 * V_42 ,
unsigned long V_336 , T_7 V_295 )
{
unsigned long V_337 = 0 ;
V_295 = F_3 ( T_7 , F_306 ( V_42 -> V_134 ) , V_295 ) ;
V_336 = F_163 ( V_336 ) ;
if ( ! V_47 && V_295 > F_307 ( 32 ) ) {
V_337 = F_308 ( & V_42 -> V_221 , V_336 ,
F_196 ( F_307 ( 32 ) ) ) ;
if ( V_337 )
return V_337 ;
}
V_337 = F_308 ( & V_42 -> V_221 , V_336 , F_196 ( V_295 ) ) ;
if ( F_309 ( ! V_337 ) ) {
F_123 ( L_56 ,
V_336 , F_242 ( V_95 ) ) ;
return 0 ;
}
return V_337 ;
}
static struct V_39 * F_310 ( struct V_94 * V_95 )
{
struct V_39 * V_42 , * V_98 ;
struct V_280 * V_281 ;
struct V_94 * V_338 ;
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
if ( V_338 != V_95 )
continue;
V_83 = F_249 ( V_95 , V_42 ,
V_281 -> V_282 ,
V_281 -> V_283 ) ;
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
F_243 ( V_275 , V_95 ) ;
F_48 ( L_58 ,
F_242 ( V_95 ) ) ;
return 0 ;
}
} else {
if ( F_271 ( V_95 , 0 ) ) {
int V_83 ;
V_83 = F_265 ( V_275 , V_95 ) ;
if ( ! V_83 ) {
F_48 ( L_59 ,
F_242 ( V_95 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_259 F_314 ( struct V_94 * V_95 , T_1 V_339 ,
T_5 V_58 , int V_340 , V_24 V_295 )
{
struct V_39 * V_42 ;
T_1 V_341 ;
unsigned long V_337 ;
int V_251 = 0 ;
int V_83 ;
struct V_31 * V_32 ;
unsigned long V_342 = V_339 >> V_11 ;
F_75 ( V_340 == V_343 ) ;
if ( F_313 ( V_95 ) )
return V_339 ;
V_42 = F_312 ( V_95 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_74 ( V_42 ) ;
V_58 = F_219 ( V_339 , V_58 ) ;
V_337 = F_305 ( V_95 , V_42 , F_12 ( V_58 ) , V_295 ) ;
if ( ! V_337 )
goto error;
if ( V_340 == V_344 || V_340 == V_345 || \
! F_315 ( V_32 -> V_71 ) )
V_251 |= V_124 ;
if ( V_340 == V_346 || V_340 == V_345 )
V_251 |= V_125 ;
V_83 = F_230 ( V_42 , F_13 ( V_337 ) ,
F_13 ( V_342 ) , V_58 , V_251 ) ;
if ( V_83 )
goto error;
if ( F_166 ( V_32 -> V_71 ) )
F_161 ( V_32 , V_42 ,
F_13 ( V_337 ) ,
V_58 , 0 , 1 ) ;
else
F_130 ( V_32 ) ;
V_341 = ( T_1 ) V_337 << V_11 ;
V_341 += V_339 & ~ V_240 ;
return V_341 ;
error:
if ( V_337 )
F_316 ( & V_42 -> V_221 , V_337 , F_12 ( V_58 ) ) ;
F_123 ( L_60 ,
F_242 ( V_95 ) , V_58 , ( unsigned long long ) V_339 , V_340 ) ;
return 0 ;
}
static V_259 F_317 ( struct V_94 * V_95 , struct V_14 * V_14 ,
unsigned long V_118 , T_5 V_58 ,
enum V_347 V_340 ,
unsigned long V_348 )
{
return F_314 ( V_95 , F_223 ( V_14 ) + V_118 , V_58 ,
V_340 , * V_95 -> V_295 ) ;
}
static void F_318 ( struct V_324 * V_349 )
{
int V_79 , V_350 ;
V_349 -> V_351 = 0 ;
for ( V_79 = 0 ; V_79 < V_74 ; V_79 ++ ) {
struct V_31 * V_32 = V_75 [ V_79 ] ;
struct V_328 * V_352 =
& V_349 -> V_327 [ V_79 ] ;
if ( ! V_32 )
continue;
if ( ! V_352 -> V_133 )
continue;
if ( ! F_166 ( V_32 -> V_71 ) )
V_32 -> V_188 . V_189 ( V_32 , 0 , 0 , 0 ,
V_164 ) ;
for ( V_350 = 0 ; V_350 < V_352 -> V_133 ; V_350 ++ ) {
unsigned long V_84 ;
struct V_353 * V_91 =
& V_352 -> V_354 [ V_350 ] ;
unsigned long V_337 = V_91 -> V_337 ;
unsigned long V_336 = V_91 -> V_336 ;
struct V_39 * V_42 = V_91 -> V_42 ;
struct V_14 * V_135 = V_91 -> V_135 ;
if ( F_166 ( V_32 -> V_71 ) )
F_161 ( V_32 , V_42 ,
F_13 ( V_337 ) ,
V_336 , ! V_135 , 0 ) ;
else {
V_84 = F_162 ( V_336 ) ;
F_159 ( V_42 ,
( T_7 ) V_337 << V_11 , V_84 ) ;
}
F_316 ( & V_42 -> V_221 , V_337 , V_336 ) ;
if ( V_135 )
F_121 ( V_135 ) ;
}
V_352 -> V_133 = 0 ;
}
V_349 -> V_58 = 0 ;
}
static void F_205 ( unsigned long V_355 )
{
struct V_324 * V_349 = F_295 ( & V_326 , V_355 ) ;
unsigned long V_33 ;
F_105 ( & V_349 -> V_114 , V_33 ) ;
F_318 ( V_349 ) ;
F_106 ( & V_349 -> V_114 , V_33 ) ;
}
static void F_319 ( struct V_39 * V_41 , unsigned long V_337 ,
unsigned long V_336 , struct V_14 * V_135 )
{
unsigned long V_33 ;
int V_356 , V_73 ;
struct V_31 * V_32 ;
struct V_353 * V_91 ;
struct V_324 * V_349 ;
unsigned int V_355 ;
V_355 = F_320 () ;
V_349 = F_295 ( & V_326 , V_355 ) ;
if ( V_349 -> V_58 == V_357 ) {
int V_225 ;
F_321 (cpu)
F_205 ( V_225 ) ;
}
F_105 ( & V_349 -> V_114 , V_33 ) ;
V_32 = F_74 ( V_41 ) ;
V_73 = V_32 -> V_187 ;
V_356 = V_349 -> V_327 [ V_73 ] . V_133 ;
++ ( V_349 -> V_327 [ V_73 ] . V_133 ) ;
V_91 = & V_349 -> V_327 [ V_73 ] . V_354 [ V_356 ] ;
V_91 -> V_42 = V_41 ;
V_91 -> V_337 = V_337 ;
V_91 -> V_336 = V_336 ;
V_91 -> V_135 = V_135 ;
if ( ! V_349 -> V_351 ) {
F_322 ( & V_349 -> V_330 , V_358 + F_323 ( 10 ) ) ;
V_349 -> V_351 = 1 ;
}
V_349 -> V_58 ++ ;
F_106 ( & V_349 -> V_114 , V_33 ) ;
F_324 () ;
}
static void F_325 ( struct V_94 * V_95 , V_259 V_359 , T_5 V_58 )
{
struct V_39 * V_42 ;
unsigned long V_128 , V_129 ;
unsigned long V_336 ;
unsigned long V_337 ;
struct V_31 * V_32 ;
struct V_14 * V_135 ;
if ( F_313 ( V_95 ) )
return;
V_42 = F_234 ( V_95 ) ;
F_75 ( ! V_42 ) ;
V_32 = F_74 ( V_42 ) ;
V_337 = F_196 ( V_359 ) ;
V_336 = F_219 ( V_359 , V_58 ) ;
V_128 = F_13 ( V_337 ) ;
V_129 = V_128 + V_336 - 1 ;
F_143 ( L_61 ,
F_242 ( V_95 ) , V_128 , V_129 ) ;
V_135 = F_120 ( V_42 , V_128 , V_129 ) ;
if ( V_48 ) {
F_161 ( V_32 , V_42 , V_128 ,
V_336 , ! V_135 , 0 ) ;
F_316 ( & V_42 -> V_221 , V_337 , F_12 ( V_336 ) ) ;
F_121 ( V_135 ) ;
} else {
F_319 ( V_42 , V_337 , V_336 , V_135 ) ;
}
}
static void F_326 ( struct V_94 * V_95 , V_259 V_359 ,
T_5 V_58 , enum V_347 V_340 ,
unsigned long V_348 )
{
F_325 ( V_95 , V_359 , V_58 ) ;
}
static void * F_327 ( struct V_94 * V_95 , T_5 V_58 ,
V_259 * V_360 , T_8 V_33 ,
unsigned long V_348 )
{
struct V_14 * V_14 = NULL ;
int V_361 ;
V_58 = F_220 ( V_58 ) ;
V_361 = F_328 ( V_58 ) ;
if ( ! F_313 ( V_95 ) )
V_33 &= ~ ( V_362 | V_363 ) ;
else if ( V_95 -> V_296 < F_276 ( V_95 ) ) {
if ( V_95 -> V_296 < F_307 ( 32 ) )
V_33 |= V_362 ;
else
V_33 |= V_363 ;
}
if ( F_329 ( V_33 ) ) {
unsigned int V_205 = V_58 >> V_11 ;
V_14 = F_330 ( V_95 , V_205 , V_361 ) ;
if ( V_14 && F_313 ( V_95 ) &&
F_223 ( V_14 ) + V_58 > V_95 -> V_296 ) {
F_331 ( V_95 , V_14 , V_205 ) ;
V_14 = NULL ;
}
}
if ( ! V_14 )
V_14 = F_332 ( V_33 , V_361 ) ;
if ( ! V_14 )
return NULL ;
memset ( F_56 ( V_14 ) , 0 , V_58 ) ;
* V_360 = F_314 ( V_95 , F_223 ( V_14 ) , V_58 ,
V_345 ,
V_95 -> V_296 ) ;
if ( * V_360 )
return F_56 ( V_14 ) ;
if ( ! F_331 ( V_95 , V_14 , V_58 >> V_11 ) )
F_333 ( V_14 , V_361 ) ;
return NULL ;
}
static void F_334 ( struct V_94 * V_95 , T_5 V_58 , void * V_61 ,
V_259 V_360 , unsigned long V_348 )
{
int V_361 ;
struct V_14 * V_14 = F_17 ( V_61 ) ;
V_58 = F_220 ( V_58 ) ;
V_361 = F_328 ( V_58 ) ;
F_325 ( V_95 , V_360 , V_58 ) ;
if ( ! F_331 ( V_95 , V_14 , V_58 >> V_11 ) )
F_333 ( V_14 , V_361 ) ;
}
static void F_335 ( struct V_94 * V_95 , struct V_247 * V_364 ,
int V_365 , enum V_347 V_340 ,
unsigned long V_348 )
{
V_259 V_366 = F_336 ( V_364 ) & V_240 ;
unsigned long V_336 = 0 ;
struct V_247 * V_248 ;
int V_79 ;
F_337 (sglist, sg, nelems, i) {
V_336 += F_219 ( F_336 ( V_248 ) , F_338 ( V_248 ) ) ;
}
F_325 ( V_95 , V_366 , V_336 << V_12 ) ;
}
static int F_339 ( struct V_94 * V_367 ,
struct V_247 * V_364 , int V_365 , int V_340 )
{
int V_79 ;
struct V_247 * V_248 ;
F_337 (sglist, sg, nelems, i) {
F_75 ( ! F_224 ( V_248 ) ) ;
V_248 -> V_258 = F_223 ( F_224 ( V_248 ) ) + V_248 -> V_118 ;
V_248 -> V_260 = V_248 -> V_257 ;
}
return V_365 ;
}
static int F_340 ( struct V_94 * V_95 , struct V_247 * V_364 , int V_365 ,
enum V_347 V_340 , unsigned long V_348 )
{
int V_79 ;
struct V_39 * V_42 ;
T_5 V_58 = 0 ;
int V_251 = 0 ;
unsigned long V_337 ;
int V_83 ;
struct V_247 * V_248 ;
unsigned long V_368 ;
struct V_31 * V_32 ;
F_75 ( V_340 == V_343 ) ;
if ( F_313 ( V_95 ) )
return F_339 ( V_95 , V_364 , V_365 , V_340 ) ;
V_42 = F_312 ( V_95 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_74 ( V_42 ) ;
F_337 (sglist, sg, nelems, i)
V_58 += F_219 ( V_248 -> V_118 , V_248 -> V_257 ) ;
V_337 = F_305 ( V_95 , V_42 , F_12 ( V_58 ) ,
* V_95 -> V_295 ) ;
if ( ! V_337 ) {
V_364 -> V_260 = 0 ;
return 0 ;
}
if ( V_340 == V_344 || V_340 == V_345 || \
! F_315 ( V_32 -> V_71 ) )
V_251 |= V_124 ;
if ( V_340 == V_346 || V_340 == V_345 )
V_251 |= V_125 ;
V_368 = F_13 ( V_337 ) ;
V_83 = F_229 ( V_42 , V_368 , V_364 , V_58 , V_251 ) ;
if ( F_309 ( V_83 ) ) {
F_115 ( V_42 , V_368 ,
V_368 + V_58 - 1 ) ;
F_316 ( & V_42 -> V_221 , V_337 , F_12 ( V_58 ) ) ;
return 0 ;
}
if ( F_166 ( V_32 -> V_71 ) )
F_161 ( V_32 , V_42 , V_368 , V_58 , 0 , 1 ) ;
else
F_130 ( V_32 ) ;
return V_365 ;
}
static int F_341 ( struct V_94 * V_95 , V_259 V_369 )
{
return ! V_369 ;
}
static inline int F_342 ( void )
{
int V_83 = 0 ;
V_63 = F_343 ( L_62 ,
sizeof( struct V_39 ) ,
0 ,
V_370 ,
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
V_370 ,
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
goto V_371;
V_83 = F_344 () ;
if ( ! V_83 )
return V_83 ;
F_347 ( V_63 ) ;
V_371:
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
T_2 V_372 ;
int V_373 ;
V_373 = F_351 ( V_101 -> V_87 , F_352 ( 0 , 0 ) , 0xb0 , & V_372 ) ;
if ( V_373 ) {
F_353 ( & V_101 -> V_95 , L_66 ) ;
return;
}
V_372 &= 0xffff0000 ;
V_77 = F_354 ( V_101 ) ;
if ( F_355 ( ! V_77 || V_77 -> V_374 - V_372 != 0xa000 ,
V_375 ,
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
if ( V_79 == V_77 -> V_376 )
V_77 -> V_334 = 1 ;
}
}
F_357 (drhd) {
if ( V_77 -> V_112 )
continue;
F_101 (drhd->devices,
drhd->devices_cnt, i, dev)
if ( ! F_95 ( V_95 ) || ! F_270 ( F_96 ( V_95 ) ) )
break;
if ( V_79 < V_77 -> V_376 )
continue;
if ( V_46 ) {
V_377 = 1 ;
} else {
V_77 -> V_334 = 1 ;
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
if ( V_77 -> V_334 ) {
if ( V_335 )
F_167 ( V_32 ) ;
continue;
}
F_130 ( V_32 ) ;
F_124 ( V_32 ) ;
V_32 -> V_188 . V_233 ( V_32 , 0 , 0 , 0 ,
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
V_32 -> V_188 . V_233 ( V_32 , 0 , 0 , 0 ,
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
V_32 -> V_378 = F_52 ( sizeof( T_2 ) * V_379 ,
V_59 ) ;
if ( ! V_32 -> V_378 )
goto V_380;
}
F_360 () ;
F_80 (iommu, drhd) {
F_169 ( V_32 ) ;
F_125 ( & V_32 -> V_144 , V_142 ) ;
V_32 -> V_378 [ V_381 ] =
F_44 ( V_32 -> V_36 + V_382 ) ;
V_32 -> V_378 [ V_383 ] =
F_44 ( V_32 -> V_36 + V_384 ) ;
V_32 -> V_378 [ V_385 ] =
F_44 ( V_32 -> V_36 + V_386 ) ;
V_32 -> V_378 [ V_387 ] =
F_44 ( V_32 -> V_36 + V_388 ) ;
F_129 ( & V_32 -> V_144 , V_142 ) ;
}
return 0 ;
V_380:
F_80 (iommu, drhd)
F_176 ( V_32 -> V_378 ) ;
return - V_139 ;
}
static void F_362 ( void )
{
struct V_76 * V_77 ;
struct V_31 * V_32 = NULL ;
unsigned long V_142 ;
if ( F_358 () ) {
if ( V_335 )
F_363 ( L_68 ) ;
else
F_251 ( 1 , L_69 ) ;
return;
}
F_80 (iommu, drhd) {
F_125 ( & V_32 -> V_144 , V_142 ) ;
F_127 ( V_32 -> V_378 [ V_381 ] ,
V_32 -> V_36 + V_382 ) ;
F_127 ( V_32 -> V_378 [ V_383 ] ,
V_32 -> V_36 + V_384 ) ;
F_127 ( V_32 -> V_378 [ V_385 ] ,
V_32 -> V_36 + V_386 ) ;
F_127 ( V_32 -> V_378 [ V_387 ] ,
V_32 -> V_36 + V_388 ) ;
F_129 ( & V_32 -> V_144 , V_142 ) ;
}
F_80 (iommu, drhd)
F_176 ( V_32 -> V_378 ) ;
}
static void T_3 F_364 ( void )
{
F_365 ( & V_389 ) ;
}
static inline void F_364 ( void ) {}
int T_3 F_366 ( struct V_390 * V_391 , void * V_392 )
{
struct V_393 * V_281 ;
struct V_280 * V_394 ;
V_394 = F_52 ( sizeof( * V_394 ) , V_198 ) ;
if ( ! V_394 )
return - V_139 ;
V_394 -> V_395 = V_391 ;
V_281 = (struct V_393 * ) V_391 ;
V_394 -> V_282 = V_281 -> V_282 ;
V_394 -> V_283 = V_281 -> V_283 ;
V_394 -> V_106 = F_367 ( ( void * ) ( V_281 + 1 ) ,
( ( void * ) V_281 ) + V_281 -> V_391 . V_257 ,
& V_394 -> V_376 ) ;
if ( V_394 -> V_376 && V_394 -> V_106 == NULL ) {
F_176 ( V_394 ) ;
return - V_139 ;
}
F_241 ( & V_394 -> V_396 , & V_397 ) ;
return 0 ;
}
static struct V_398 * F_368 ( struct V_399 * V_400 )
{
struct V_398 * V_401 ;
struct V_399 * V_98 ;
F_369 (atsru, &dmar_atsr_units, list) {
V_98 = (struct V_399 * ) V_401 -> V_395 ;
if ( V_400 -> V_102 != V_98 -> V_102 )
continue;
if ( V_400 -> V_391 . V_257 != V_98 -> V_391 . V_257 )
continue;
if ( memcmp ( V_400 , V_98 , V_400 -> V_391 . V_257 ) == 0 )
return V_401 ;
}
return NULL ;
}
int F_370 ( struct V_390 * V_395 , void * V_392 )
{
struct V_399 * V_400 ;
struct V_398 * V_401 ;
if ( V_402 != V_403 && ! V_404 )
return 0 ;
V_400 = F_46 ( V_395 , struct V_399 , V_391 ) ;
V_401 = F_368 ( V_400 ) ;
if ( V_401 )
return 0 ;
V_401 = F_52 ( sizeof( * V_401 ) + V_395 -> V_257 , V_198 ) ;
if ( ! V_401 )
return - V_139 ;
V_401 -> V_395 = ( void * ) ( V_401 + 1 ) ;
memcpy ( V_401 -> V_395 , V_395 , V_395 -> V_257 ) ;
V_401 -> V_112 = V_400 -> V_33 & 0x1 ;
if ( ! V_401 -> V_112 ) {
V_401 -> V_106 = F_367 ( ( void * ) ( V_400 + 1 ) ,
( void * ) V_400 + V_400 -> V_391 . V_257 ,
& V_401 -> V_376 ) ;
if ( V_401 -> V_376 && V_401 -> V_106 == NULL ) {
F_176 ( V_401 ) ;
return - V_139 ;
}
}
F_371 ( & V_401 -> V_396 , & V_405 ) ;
return 0 ;
}
static void F_372 ( struct V_398 * V_401 )
{
F_373 ( & V_401 -> V_106 , & V_401 -> V_376 ) ;
F_176 ( V_401 ) ;
}
int F_374 ( struct V_390 * V_395 , void * V_392 )
{
struct V_399 * V_400 ;
struct V_398 * V_401 ;
V_400 = F_46 ( V_395 , struct V_399 , V_391 ) ;
V_401 = F_368 ( V_400 ) ;
if ( V_401 ) {
F_375 ( & V_401 -> V_396 ) ;
F_376 () ;
F_372 ( V_401 ) ;
}
return 0 ;
}
int F_377 ( struct V_390 * V_395 , void * V_392 )
{
int V_79 ;
struct V_94 * V_95 ;
struct V_399 * V_400 ;
struct V_398 * V_401 ;
V_400 = F_46 ( V_395 , struct V_399 , V_391 ) ;
V_401 = F_368 ( V_400 ) ;
if ( ! V_401 )
return 0 ;
if ( ! V_401 -> V_112 && V_401 -> V_106 && V_401 -> V_376 ) {
F_101 (atsru->devices, atsru->devices_cnt,
i, dev)
return - V_288 ;
}
return 0 ;
}
static int F_378 ( struct V_76 * V_406 )
{
int V_407 , V_83 = 0 ;
struct V_31 * V_32 = V_406 -> V_32 ;
if ( V_75 [ V_32 -> V_187 ] )
return 0 ;
if ( V_228 && ! F_298 ( V_32 -> V_81 ) ) {
F_250 ( L_70 ,
V_32 -> V_138 ) ;
return - V_408 ;
}
if ( ! F_83 ( V_32 -> V_81 ) &&
F_82 ( V_32 ) ) {
F_250 ( L_71 ,
V_32 -> V_138 ) ;
return - V_408 ;
}
V_407 = F_84 ( V_32 ) - 1 ;
if ( V_407 >= 0 && ! ( F_85 ( V_32 -> V_71 ) & ( 1 << V_407 ) ) ) {
F_250 ( L_72 ,
V_32 -> V_138 ) ;
return - V_408 ;
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
if ( V_406 -> V_334 ) {
if ( V_335 )
F_167 ( V_32 ) ;
return 0 ;
}
F_282 ( V_32 ) ;
F_130 ( V_32 ) ;
#ifdef F_149
if ( V_177 ( V_32 ) && F_183 ( V_32 -> V_81 ) ) {
V_83 = F_303 ( V_32 ) ;
if ( V_83 )
goto V_409;
}
#endif
V_83 = F_304 ( V_32 ) ;
if ( V_83 )
goto V_409;
F_124 ( V_32 ) ;
V_32 -> V_188 . V_233 ( V_32 , 0 , 0 , 0 , V_155 ) ;
V_32 -> V_188 . V_189 ( V_32 , 0 , 0 , 0 , V_164 ) ;
F_168 ( V_32 ) ;
F_167 ( V_32 ) ;
return 0 ;
V_409:
F_178 ( V_32 ) ;
V_107:
F_182 ( V_32 ) ;
return V_83 ;
}
int F_379 ( struct V_76 * V_406 , bool V_410 )
{
int V_83 = 0 ;
struct V_31 * V_32 = V_406 -> V_32 ;
if ( ! V_404 )
return 0 ;
if ( V_32 == NULL )
return - V_44 ;
if ( V_410 ) {
V_83 = F_378 ( V_406 ) ;
} else {
F_178 ( V_32 ) ;
F_182 ( V_32 ) ;
}
return V_83 ;
}
static void F_380 ( void )
{
struct V_280 * V_394 , * V_411 ;
struct V_398 * V_401 , * V_412 ;
F_179 (rmrru, rmrr_n, &dmar_rmrr_units, list) {
F_233 ( & V_394 -> V_396 ) ;
F_373 ( & V_394 -> V_106 , & V_394 -> V_376 ) ;
F_176 ( V_394 ) ;
}
F_179 (atsru, atsr_n, &dmar_atsr_units, list) {
F_233 ( & V_401 -> V_396 ) ;
F_372 ( V_401 ) ;
}
}
int F_239 ( struct V_99 * V_95 )
{
int V_79 , V_83 = 1 ;
struct V_413 * V_87 ;
struct V_99 * V_414 = NULL ;
struct V_94 * V_98 ;
struct V_399 * V_400 ;
struct V_398 * V_401 ;
V_95 = F_97 ( V_95 ) ;
for ( V_87 = V_95 -> V_87 ; V_87 ; V_87 = V_87 -> V_117 ) {
V_414 = V_87 -> V_415 ;
if ( ! V_414 )
return 1 ;
if ( ! F_273 ( V_414 ) ||
F_275 ( V_414 ) == V_294 )
return 0 ;
if ( F_275 ( V_414 ) == V_416 )
break;
}
F_79 () ;
F_369 (atsru, &dmar_atsr_units, list) {
V_400 = F_46 ( V_401 -> V_395 , struct V_399 , V_391 ) ;
if ( V_400 -> V_102 != F_98 ( V_95 -> V_87 ) )
continue;
F_381 (atsru->devices, atsru->devices_cnt, i, tmp)
if ( V_98 == & V_414 -> V_95 )
goto V_107;
if ( V_401 -> V_112 )
goto V_107;
}
V_83 = 0 ;
V_107:
F_81 () ;
return V_83 ;
}
int F_382 ( struct V_417 * V_170 )
{
int V_83 = 0 ;
struct V_280 * V_394 ;
struct V_398 * V_401 ;
struct V_399 * V_400 ;
struct V_393 * V_281 ;
if ( ! V_404 && V_402 != V_403 )
return 0 ;
F_146 (rmrru, &dmar_rmrr_units, list) {
V_281 = F_46 ( V_394 -> V_395 ,
struct V_393 , V_391 ) ;
if ( V_170 -> V_418 == V_419 ) {
V_83 = F_383 ( V_170 , ( void * ) ( V_281 + 1 ) ,
( ( void * ) V_281 ) + V_281 -> V_391 . V_257 ,
V_281 -> V_102 , V_394 -> V_106 ,
V_394 -> V_376 ) ;
if( V_83 < 0 )
return V_83 ;
} else if ( V_170 -> V_418 == V_420 ) {
F_384 ( V_170 , V_281 -> V_102 ,
V_394 -> V_106 , V_394 -> V_376 ) ;
}
}
F_146 (atsru, &dmar_atsr_units, list) {
if ( V_401 -> V_112 )
continue;
V_400 = F_46 ( V_401 -> V_395 , struct V_399 , V_391 ) ;
if ( V_170 -> V_418 == V_419 ) {
V_83 = F_383 ( V_170 , ( void * ) ( V_400 + 1 ) ,
( void * ) V_400 + V_400 -> V_391 . V_257 ,
V_400 -> V_102 , V_401 -> V_106 ,
V_401 -> V_376 ) ;
if ( V_83 > 0 )
break;
else if( V_83 < 0 )
return V_83 ;
} else if ( V_170 -> V_418 == V_420 ) {
if ( F_384 ( V_170 , V_400 -> V_102 ,
V_401 -> V_106 , V_401 -> V_376 ) )
break;
}
}
return 0 ;
}
static int F_385 ( struct V_421 * V_422 ,
unsigned long V_423 , void * V_238 )
{
struct V_94 * V_95 = V_238 ;
struct V_39 * V_42 ;
if ( F_93 ( V_95 ) )
return 0 ;
if ( V_423 != V_420 )
return 0 ;
V_42 = F_234 ( V_95 ) ;
if ( ! V_42 )
return 0 ;
F_243 ( V_42 , V_95 ) ;
if ( ! F_67 ( V_42 ) && F_386 ( & V_42 -> V_106 ) )
F_181 ( V_42 ) ;
return 0 ;
}
static int F_387 ( struct V_421 * V_422 ,
unsigned long V_29 , void * V_424 )
{
struct V_425 * V_426 = V_424 ;
unsigned long long V_220 , V_111 ;
unsigned long V_368 , V_274 ;
switch ( V_29 ) {
case V_427 :
V_220 = V_426 -> V_128 << V_11 ;
V_111 = ( ( V_426 -> V_128 + V_426 -> V_250 ) << V_11 ) - 1 ;
if ( F_248 ( V_275 , V_220 , V_111 ) ) {
F_250 ( L_73 ,
V_220 , V_111 ) ;
return V_428 ;
}
break;
case V_429 :
case V_430 :
V_368 = F_13 ( V_426 -> V_128 ) ;
V_274 = F_13 ( V_426 -> V_128 + V_426 -> V_250 - 1 ) ;
while ( V_368 <= V_274 ) {
struct V_207 * V_207 ;
struct V_76 * V_77 ;
struct V_31 * V_32 ;
struct V_14 * V_135 ;
V_207 = F_388 ( & V_275 -> V_221 , V_368 ) ;
if ( V_207 == NULL ) {
F_143 ( L_74 ,
V_368 ) ;
break;
}
V_207 = F_389 ( & V_275 -> V_221 , V_207 ,
V_368 , V_274 ) ;
if ( V_207 == NULL ) {
F_250 ( L_75 ,
V_368 , V_274 ) ;
return V_428 ;
}
V_135 = F_120 ( V_275 , V_207 -> V_431 ,
V_207 -> V_432 ) ;
F_79 () ;
F_80 (iommu, drhd)
F_161 ( V_32 , V_275 ,
V_207 -> V_431 , F_390 ( V_207 ) ,
! V_135 , 0 ) ;
F_81 () ;
F_121 ( V_135 ) ;
V_368 = V_207 -> V_432 + 1 ;
F_391 ( V_207 ) ;
}
break;
}
return V_433 ;
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
static int F_394 ( struct V_421 * V_434 ,
unsigned long V_423 , void * V_424 )
{
unsigned int V_225 = ( unsigned long ) V_424 ;
switch ( V_423 ) {
case V_435 :
case V_436 :
F_392 ( V_225 ) ;
F_205 ( V_225 ) ;
break;
}
return V_433 ;
}
static T_9 F_395 ( struct V_94 * V_95 ,
struct V_437 * V_438 ,
char * V_439 )
{
struct V_31 * V_32 = F_396 ( V_95 ) ;
T_2 V_440 = F_44 ( V_32 -> V_36 + V_441 ) ;
return sprintf ( V_439 , L_76 ,
F_397 ( V_440 ) , F_398 ( V_440 ) ) ;
}
static T_9 F_399 ( struct V_94 * V_95 ,
struct V_437 * V_438 ,
char * V_439 )
{
struct V_31 * V_32 = F_396 ( V_95 ) ;
return sprintf ( V_439 , L_77 , V_32 -> V_442 ) ;
}
static T_9 F_400 ( struct V_94 * V_95 ,
struct V_437 * V_438 ,
char * V_439 )
{
struct V_31 * V_32 = F_396 ( V_95 ) ;
return sprintf ( V_439 , L_77 , V_32 -> V_71 ) ;
}
static T_9 F_401 ( struct V_94 * V_95 ,
struct V_437 * V_438 ,
char * V_439 )
{
struct V_31 * V_32 = F_396 ( V_95 ) ;
return sprintf ( V_439 , L_77 , V_32 -> V_81 ) ;
}
static T_9 F_402 ( struct V_94 * V_95 ,
struct V_437 * V_438 ,
char * V_439 )
{
struct V_31 * V_32 = F_396 ( V_95 ) ;
return sprintf ( V_439 , L_78 , F_171 ( V_32 -> V_71 ) ) ;
}
static T_9 F_403 ( struct V_94 * V_95 ,
struct V_437 * V_438 ,
char * V_439 )
{
struct V_31 * V_32 = F_396 ( V_95 ) ;
return sprintf ( V_439 , L_79 , F_404 ( V_32 -> V_197 ,
F_171 ( V_32 -> V_71 ) ) ) ;
}
int T_3 F_405 ( void )
{
int V_83 = - V_215 ;
struct V_76 * V_77 ;
struct V_31 * V_32 ;
V_335 = F_406 () ;
if ( F_345 () ) {
if ( V_335 )
F_363 ( L_80 ) ;
return - V_139 ;
}
F_407 ( & V_443 ) ;
if ( F_408 () ) {
if ( V_335 )
F_363 ( L_81 ) ;
goto V_444;
}
if ( F_409 () < 0 ) {
if ( V_335 )
F_363 ( L_82 ) ;
goto V_444;
}
if ( V_445 || V_45 )
goto V_444;
if ( F_386 ( & V_397 ) )
F_48 ( L_83 ) ;
if ( F_386 ( & V_405 ) )
F_48 ( L_84 ) ;
if ( F_192 () ) {
if ( V_335 )
F_363 ( L_85 ) ;
goto V_446;
}
F_356 () ;
V_83 = F_292 () ;
if ( V_83 ) {
if ( V_335 )
F_363 ( L_86 ) ;
F_123 ( L_87 ) ;
goto V_446;
}
F_410 ( & V_443 ) ;
F_48 ( L_88 ) ;
#ifdef F_411
V_447 = 0 ;
#endif
V_448 = & V_449 ;
F_364 () ;
F_80 (iommu, drhd)
V_32 -> V_450 = F_412 ( NULL , V_32 ,
V_451 ,
L_89 , V_32 -> V_138 ) ;
F_413 ( & V_452 , & V_453 ) ;
F_414 ( & V_452 , & V_454 ) ;
if ( V_275 && ! V_228 )
F_415 ( & V_455 ) ;
F_416 ( & V_456 ) ;
V_404 = 1 ;
return 0 ;
V_446:
F_207 ( & V_208 ) ;
V_444:
F_380 () ;
F_410 ( & V_443 ) ;
F_349 () ;
return V_83 ;
}
static int F_417 ( struct V_99 * V_101 , T_4 V_235 , void * V_236 )
{
struct V_31 * V_32 = V_236 ;
F_231 ( V_32 , F_214 ( V_235 ) , V_235 & 0xff ) ;
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
V_42 -> V_457 = 0 ;
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
if ( type != V_458 )
return NULL ;
V_39 = F_186 ( V_65 ) ;
if ( ! V_39 ) {
F_123 ( L_90 ) ;
return NULL ;
}
if ( F_259 ( V_39 , V_72 ) ) {
F_123 ( L_91 ) ;
F_181 ( V_39 ) ;
return NULL ;
}
F_87 ( V_39 ) ;
V_42 = & V_39 -> V_42 ;
V_42 -> V_459 . V_460 = 0 ;
V_42 -> V_459 . V_461 = F_420 ( V_39 -> V_134 ) ;
V_42 -> V_459 . V_462 = true ;
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
F_423 ( V_95 , L_92 ) ;
return - V_463 ;
}
if ( F_309 ( F_218 ( V_95 ) ) ) {
struct V_39 * V_464 ;
V_464 = F_234 ( V_95 ) ;
if ( V_464 ) {
F_79 () ;
F_243 ( V_464 , V_95 ) ;
F_81 () ;
if ( ! F_67 ( V_464 ) &&
F_386 ( & V_464 -> V_106 ) )
F_181 ( V_464 ) ;
}
}
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_215 ;
V_67 = F_2 ( V_32 -> V_1 ) ;
if ( V_67 > F_202 ( V_32 -> V_71 ) )
V_67 = F_202 ( V_32 -> V_71 ) ;
if ( V_39 -> V_457 > ( 1LL << V_67 ) ) {
F_123 ( L_93
L_94 ,
V_465 , V_67 , V_39 -> V_457 ) ;
return - V_286 ;
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
unsigned long V_207 , T_1 V_466 ,
T_5 V_58 , int V_467 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
V_24 V_457 ;
int V_251 = 0 ;
int V_83 ;
if ( V_467 & V_468 )
V_251 |= V_124 ;
if ( V_467 & V_469 )
V_251 |= V_125 ;
if ( ( V_467 & V_470 ) && V_39 -> V_85 )
V_251 |= V_256 ;
V_457 = V_207 + V_58 ;
if ( V_39 -> V_457 < V_457 ) {
V_24 V_111 ;
V_111 = F_420 ( V_39 -> V_134 ) + 1 ;
if ( V_111 < V_457 ) {
F_123 ( L_93
L_94 ,
V_465 , V_39 -> V_134 , V_457 ) ;
return - V_286 ;
}
V_39 -> V_457 = V_457 ;
}
V_58 = F_219 ( V_466 , V_58 ) ;
V_83 = F_230 ( V_39 , V_207 >> V_12 ,
V_466 >> V_12 , V_58 , V_251 ) ;
return V_83 ;
}
static T_5 F_426 ( struct V_40 * V_42 ,
unsigned long V_207 , T_5 V_58 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_14 * V_135 = NULL ;
struct V_31 * V_32 ;
unsigned long V_128 , V_129 ;
unsigned int V_471 ;
int V_73 , V_5 = 0 ;
F_75 ( ! F_109 ( V_39 , V_207 >> V_12 , & V_5 ) ) ;
if ( V_58 < V_123 << F_6 ( V_5 ) )
V_58 = V_123 << F_6 ( V_5 ) ;
V_128 = V_207 >> V_12 ;
V_129 = ( V_207 + V_58 - 1 ) >> V_12 ;
V_135 = F_120 ( V_39 , V_128 , V_129 ) ;
V_471 = V_129 - V_128 + 1 ;
F_76 (iommu_id, dmar_domain) {
V_32 = V_75 [ V_73 ] ;
F_161 ( V_75 [ V_73 ] , V_39 ,
V_128 , V_471 , ! V_135 , 0 ) ;
}
F_121 ( V_135 ) ;
if ( V_39 -> V_457 == V_207 + V_58 )
V_39 -> V_457 = V_207 ;
return V_58 ;
}
static T_1 F_427 ( struct V_40 * V_42 ,
V_259 V_207 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_27 * V_28 ;
int V_5 = 0 ;
V_24 V_472 = 0 ;
V_28 = F_109 ( V_39 , V_207 >> V_12 , & V_5 ) ;
if ( V_28 )
V_472 = F_35 ( V_28 ) ;
return V_472 ;
}
static bool F_428 ( enum V_473 V_71 )
{
if ( V_71 == V_474 )
return F_82 ( NULL ) == 1 ;
if ( V_71 == V_475 )
return V_476 == 1 ;
return false ;
}
static int F_429 ( struct V_94 * V_95 )
{
struct V_31 * V_32 ;
struct V_477 * V_478 ;
T_6 V_87 , V_88 ;
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ! V_32 )
return - V_215 ;
F_430 ( V_32 -> V_450 , V_95 ) ;
V_478 = F_431 ( V_95 ) ;
if ( F_432 ( V_478 ) )
return F_433 ( V_478 ) ;
F_434 ( V_478 ) ;
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
F_437 ( V_32 -> V_450 , V_95 ) ;
}
int F_438 ( struct V_31 * V_32 , struct V_479 * V_480 )
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
V_480 -> V_181 = F_439 ( V_170 -> V_87 , V_170 -> V_88 ) ;
if ( ! ( V_481 & V_482 ) ) {
V_23 [ 1 ] . V_21 = ( V_24 ) F_92 ( V_32 -> V_483 ) ;
V_23 [ 1 ] . V_19 = ( V_24 ) F_92 ( V_32 -> V_484 ) | F_440 ( V_32 -> V_81 ) ;
F_441 () ;
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
F_441 () ;
V_32 -> V_188 . V_233 ( V_32 , V_480 -> V_55 , V_480 -> V_181 ,
V_234 ,
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
struct V_31 * F_442 ( struct V_94 * V_95 )
{
struct V_31 * V_32 ;
T_6 V_87 , V_88 ;
if ( F_93 ( V_95 ) ) {
F_423 ( V_95 ,
L_95 ) ;
return NULL ;
}
V_32 = F_94 ( V_95 , & V_87 , & V_88 ) ;
if ( ( ! V_32 ) ) {
F_311 ( V_95 , L_96 ) ;
return NULL ;
}
if ( ! V_32 -> V_484 ) {
F_311 ( V_95 , L_97 ) ;
return NULL ;
}
return V_32 ;
}
static void F_443 ( struct V_99 * V_95 )
{
F_48 ( L_98 ) ;
V_46 = 0 ;
}
static void F_444 ( struct V_99 * V_95 )
{
F_48 ( L_99 ) ;
V_150 = 1 ;
}
static void F_445 ( struct V_99 * V_95 )
{
unsigned short V_492 ;
if ( F_446 ( V_95 , V_493 , & V_492 ) )
return;
if ( ! ( V_492 & V_494 ) ) {
F_48 ( L_100 ) ;
V_46 = 0 ;
} else if ( V_46 ) {
F_48 ( L_101 ) ;
V_48 = 1 ;
}
}
static void T_3 F_301 ( void )
{
struct V_99 * V_101 ;
T_10 V_495 ;
V_101 = F_447 ( V_496 , 0x3a3e , NULL ) ;
if ( ! V_101 )
return;
F_257 ( V_101 ) ;
V_101 = F_447 ( V_496 , 0x342e , NULL ) ;
if ( ! V_101 )
return;
if ( F_448 ( V_101 , 0x188 , & V_495 ) ) {
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
F_251 ( 1 , L_102
L_36 ,
F_252 ( V_276 ) ,
F_252 ( V_277 ) ,
F_252 ( V_278 ) ) ;
V_53 |= V_290 ;
return;
}
F_250 ( L_103 ,
V_495 ) ;
}
