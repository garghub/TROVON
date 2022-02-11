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
}
V_43 += strcspn ( V_43 , L_15 ) ;
while ( * V_43 == ',' )
V_43 ++ ;
}
return 0 ;
}
static struct V_39 * F_50 ( struct V_31 * V_32 , T_4 V_52 )
{
struct V_39 * * V_53 ;
int V_54 = V_52 >> 8 ;
V_53 = V_32 -> V_53 [ V_54 ] ;
if ( ! V_53 )
return NULL ;
return V_53 [ V_52 & 0xff ] ;
}
static void F_51 ( struct V_31 * V_32 , T_4 V_52 ,
struct V_39 * V_42 )
{
struct V_39 * * V_53 ;
int V_54 = V_52 >> 8 ;
if ( ! V_32 -> V_53 [ V_54 ] ) {
T_5 V_55 = 256 * sizeof( struct V_39 * ) ;
V_32 -> V_53 [ V_54 ] = F_52 ( V_55 , V_56 ) ;
}
V_53 = V_32 -> V_53 [ V_54 ] ;
if ( F_53 ( ! V_53 ) )
return;
else
V_53 [ V_52 & 0xff ] = V_42 ;
}
static inline void * F_54 ( int V_57 )
{
struct V_14 * V_14 ;
void * V_58 = NULL ;
V_14 = F_55 ( V_57 , V_56 | V_59 , 0 ) ;
if ( V_14 )
V_58 = F_56 ( V_14 ) ;
return V_58 ;
}
static inline void F_57 ( void * V_58 )
{
F_58 ( ( unsigned long ) V_58 ) ;
}
static inline void * F_59 ( void )
{
return F_60 ( V_60 , V_56 ) ;
}
static void F_61 ( void * V_58 )
{
F_62 ( V_60 , V_58 ) ;
}
static inline void * F_63 ( void )
{
return F_60 ( V_61 , V_56 ) ;
}
static inline void F_64 ( void * V_58 )
{
F_62 ( V_61 , V_58 ) ;
}
static inline int F_65 ( struct V_39 * V_42 )
{
return V_42 -> V_33 & V_62 ;
}
static inline int F_66 ( struct V_39 * V_42 )
{
return V_42 -> V_33 & V_63 ;
}
static inline int F_67 ( struct V_39 * V_42 )
{
return V_42 -> V_33 & ( V_62 |
V_63 ) ;
}
static inline int F_68 ( struct V_39 * V_42 ,
unsigned long V_6 )
{
int V_64 = F_2 ( V_42 -> V_1 ) - V_12 ;
return ! ( V_64 < V_65 && V_6 > > V_64 ) ;
}
static int F_69 ( struct V_31 * V_32 , int V_66 )
{
unsigned long V_67 ;
int V_1 = - 1 ;
V_67 = F_70 ( V_32 -> V_68 ) ;
for ( V_1 = F_4 ( V_66 ) ;
V_1 >= 0 ; V_1 -- ) {
if ( F_71 ( V_1 , & V_67 ) )
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
return F_69 ( V_32 , V_69 ) ;
}
static struct V_31 * F_74 ( struct V_39 * V_42 )
{
int V_70 ;
F_75 ( F_67 ( V_42 ) ) ;
F_76 (iommu_id, domain)
break;
if ( V_70 < 0 || V_70 >= V_71 )
return NULL ;
return V_72 [ V_70 ] ;
}
static void F_77 ( struct V_39 * V_42 )
{
struct V_73 * V_74 ;
struct V_31 * V_32 ;
bool V_75 = false ;
int V_76 ;
V_42 -> V_77 = 1 ;
F_76 (i, domain) {
V_75 = true ;
if ( ! F_78 ( V_72 [ V_76 ] -> V_78 ) ) {
V_42 -> V_77 = 0 ;
break;
}
}
if ( V_75 )
return;
F_79 () ;
F_80 (iommu, drhd) {
if ( ! F_78 ( V_32 -> V_78 ) ) {
V_42 -> V_77 = 0 ;
break;
}
}
F_81 () ;
}
static int F_82 ( struct V_31 * V_79 )
{
struct V_73 * V_74 ;
struct V_31 * V_32 ;
int V_80 = 1 ;
F_79 () ;
F_80 (iommu, drhd) {
if ( V_32 != V_79 ) {
if ( ! F_83 ( V_32 -> V_78 ) ) {
V_80 = 0 ;
break;
}
}
}
F_81 () ;
return V_80 ;
}
static int F_84 ( struct V_31 * V_79 )
{
struct V_73 * V_74 ;
struct V_31 * V_32 ;
int V_81 = 0xf ;
if ( ! V_49 ) {
return 0 ;
}
F_79 () ;
F_80 (iommu, drhd) {
if ( V_32 != V_79 ) {
V_81 &= F_85 ( V_32 -> V_68 ) ;
if ( ! V_81 )
break;
}
}
F_81 () ;
return F_86 ( V_81 ) ;
}
static void F_87 ( struct V_39 * V_42 )
{
F_77 ( V_42 ) ;
V_42 -> V_82 = F_82 ( NULL ) ;
V_42 -> V_83 = F_84 ( NULL ) ;
}
static inline struct V_22 * F_88 ( struct V_31 * V_32 ,
T_6 V_84 , T_6 V_85 , int V_86 )
{
struct V_17 * V_87 = & V_32 -> V_17 [ V_84 ] ;
struct V_22 * V_23 ;
V_24 * V_88 ;
V_88 = & V_87 -> V_19 ;
if ( F_89 ( V_32 ) ) {
if ( V_85 >= 0x80 ) {
V_85 -= 0x80 ;
V_88 = & V_87 -> V_21 ;
}
V_85 *= 2 ;
}
if ( * V_88 & 1 )
V_23 = F_90 ( * V_88 & V_20 ) ;
else {
unsigned long V_89 ;
if ( ! V_86 )
return NULL ;
V_23 = F_54 ( V_32 -> V_57 ) ;
if ( ! V_23 )
return NULL ;
F_91 ( V_32 , ( void * ) V_23 , V_90 ) ;
V_89 = F_92 ( ( void * ) V_23 ) ;
* V_88 = V_89 | 1 ;
F_91 ( V_32 , V_88 , sizeof( * V_88 ) ) ;
}
return & V_23 [ V_85 ] ;
}
static int F_93 ( struct V_91 * V_92 )
{
return V_92 -> V_93 . V_32 == V_94 ;
}
static struct V_31 * F_94 ( struct V_91 * V_92 , T_6 * V_84 , T_6 * V_85 )
{
struct V_73 * V_74 = NULL ;
struct V_31 * V_32 ;
struct V_91 * V_95 ;
struct V_96 * V_97 , * V_98 = NULL ;
T_4 V_99 = 0 ;
int V_76 ;
if ( F_93 ( V_92 ) )
return NULL ;
if ( F_95 ( V_92 ) ) {
V_98 = F_96 ( V_92 ) ;
V_99 = F_97 ( V_98 -> V_84 ) ;
} else if ( F_98 ( V_92 ) )
V_92 = & F_99 ( V_92 ) -> V_92 ;
F_79 () ;
F_80 (iommu, drhd) {
if ( V_98 && V_99 != V_74 -> V_99 )
continue;
F_100 (drhd->devices,
drhd->devices_cnt, i, tmp) {
if ( V_95 == V_92 ) {
* V_84 = V_74 -> V_100 [ V_76 ] . V_84 ;
* V_85 = V_74 -> V_100 [ V_76 ] . V_85 ;
goto V_101;
}
if ( ! V_98 || ! F_95 ( V_95 ) )
continue;
V_97 = F_96 ( V_95 ) ;
if ( V_97 -> V_102 &&
V_97 -> V_102 -> V_103 <= V_98 -> V_84 -> V_103 &&
V_97 -> V_102 -> V_104 . V_105 >= V_98 -> V_84 -> V_103 )
goto V_106;
}
if ( V_98 && V_74 -> V_107 ) {
V_106:
* V_84 = V_98 -> V_84 -> V_103 ;
* V_85 = V_98 -> V_85 ;
goto V_101;
}
}
V_32 = NULL ;
V_101:
F_81 () ;
return V_32 ;
}
static void F_101 ( struct V_39 * V_42 ,
void * V_108 , int V_55 )
{
if ( ! V_42 -> V_77 )
F_102 ( V_108 , V_55 ) ;
}
static int F_103 ( struct V_31 * V_32 , T_6 V_84 , T_6 V_85 )
{
struct V_22 * V_23 ;
int V_80 = 0 ;
unsigned long V_33 ;
F_104 ( & V_32 -> V_109 , V_33 ) ;
V_23 = F_88 ( V_32 , V_84 , V_85 , 0 ) ;
if ( V_23 )
V_80 = F_25 ( V_23 ) ;
F_105 ( & V_32 -> V_109 , V_33 ) ;
return V_80 ;
}
static void F_106 ( struct V_31 * V_32 , T_6 V_84 , T_6 V_85 )
{
struct V_22 * V_23 ;
unsigned long V_33 ;
F_104 ( & V_32 -> V_109 , V_33 ) ;
V_23 = F_88 ( V_32 , V_84 , V_85 , 0 ) ;
if ( V_23 ) {
F_33 ( V_23 ) ;
F_91 ( V_32 , V_23 , sizeof( * V_23 ) ) ;
}
F_105 ( & V_32 -> V_109 , V_33 ) ;
}
static void F_107 ( struct V_31 * V_32 )
{
int V_76 ;
unsigned long V_33 ;
struct V_22 * V_23 ;
F_104 ( & V_32 -> V_109 , V_33 ) ;
if ( ! V_32 -> V_17 ) {
goto V_101;
}
for ( V_76 = 0 ; V_76 < V_110 ; V_76 ++ ) {
V_23 = F_88 ( V_32 , V_76 , 0 , 0 ) ;
if ( V_23 )
F_57 ( V_23 ) ;
if ( ! F_89 ( V_32 ) )
continue;
V_23 = F_88 ( V_32 , V_76 , 0x80 , 0 ) ;
if ( V_23 )
F_57 ( V_23 ) ;
}
F_57 ( V_32 -> V_17 ) ;
V_32 -> V_17 = NULL ;
V_101:
F_105 ( & V_32 -> V_109 , V_33 ) ;
}
static struct V_27 * F_108 ( struct V_39 * V_42 ,
unsigned long V_6 , int * V_111 )
{
struct V_27 * V_112 , * V_28 = NULL ;
int V_5 = F_1 ( V_42 -> V_1 ) ;
int V_113 ;
F_75 ( ! V_42 -> V_114 ) ;
if ( ! F_68 ( V_42 , V_6 ) )
return NULL ;
V_112 = V_42 -> V_114 ;
while ( 1 ) {
void * V_115 ;
V_113 = F_7 ( V_6 , V_5 ) ;
V_28 = & V_112 [ V_113 ] ;
if ( ! * V_111 && ( F_39 ( V_28 ) || ! F_38 ( V_28 ) ) )
break;
if ( V_5 == * V_111 )
break;
if ( ! F_38 ( V_28 ) ) {
T_7 V_116 ;
V_115 = F_54 ( V_42 -> V_117 ) ;
if ( ! V_115 )
return NULL ;
F_101 ( V_42 , V_115 , V_118 ) ;
V_116 = ( ( T_7 ) F_16 ( V_115 ) << V_12 ) | V_119 | V_120 ;
if ( F_109 ( & V_28 -> V_29 , 0ULL , V_116 ) )
F_57 ( V_115 ) ;
else
F_101 ( V_42 , V_28 , sizeof( * V_28 ) ) ;
}
if ( V_5 == 1 )
break;
V_112 = F_90 ( F_35 ( V_28 ) ) ;
V_5 -- ;
}
if ( ! * V_111 )
* V_111 = V_5 ;
return V_28 ;
}
static struct V_27 * F_110 ( struct V_39 * V_42 ,
unsigned long V_6 ,
int V_5 , int * V_121 )
{
struct V_27 * V_112 , * V_28 = NULL ;
int V_122 = F_1 ( V_42 -> V_1 ) ;
int V_113 ;
V_112 = V_42 -> V_114 ;
while ( V_5 <= V_122 ) {
V_113 = F_7 ( V_6 , V_122 ) ;
V_28 = & V_112 [ V_113 ] ;
if ( V_5 == V_122 )
return V_28 ;
if ( ! F_38 ( V_28 ) ) {
* V_121 = V_122 ;
break;
}
if ( F_39 ( V_28 ) ) {
* V_121 = V_122 ;
return V_28 ;
}
V_112 = F_90 ( F_35 ( V_28 ) ) ;
V_122 -- ;
}
return NULL ;
}
static void F_111 ( struct V_39 * V_42 ,
unsigned long V_123 ,
unsigned long V_124 )
{
unsigned int V_121 = 1 ;
struct V_27 * V_125 , * V_28 ;
F_75 ( ! F_68 ( V_42 , V_123 ) ) ;
F_75 ( ! F_68 ( V_42 , V_124 ) ) ;
F_75 ( V_123 > V_124 ) ;
do {
V_121 = 1 ;
V_125 = V_28 = F_110 ( V_42 , V_123 , 1 , & V_121 ) ;
if ( ! V_28 ) {
V_123 = F_10 ( V_123 + 1 , V_121 + 1 ) ;
continue;
}
do {
F_34 ( V_28 ) ;
V_123 += F_11 ( V_121 ) ;
V_28 ++ ;
} while ( V_123 <= V_124 && ! F_40 ( V_28 ) );
F_101 ( V_42 , V_125 ,
( void * ) V_28 - ( void * ) V_125 ) ;
} while ( V_123 && V_123 <= V_124 );
}
static void F_112 ( struct V_39 * V_42 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_123 , unsigned long V_124 )
{
V_6 = F_113 ( V_123 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_126 ;
struct V_27 * V_127 ;
if ( ! F_38 ( V_28 ) || F_39 ( V_28 ) )
goto V_128;
V_126 = V_6 & F_8 ( V_5 - 1 ) ;
V_127 = F_90 ( F_35 ( V_28 ) ) ;
if ( V_5 > 2 )
F_112 ( V_42 , V_5 - 1 , V_127 ,
V_126 , V_123 , V_124 ) ;
if ( ! ( V_123 > V_126 ||
V_124 < V_126 + F_9 ( V_5 ) - 1 ) ) {
F_34 ( V_28 ) ;
F_101 ( V_42 , V_28 , sizeof( * V_28 ) ) ;
F_57 ( V_127 ) ;
}
V_128:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_40 ( ++ V_28 ) && V_6 <= V_124 );
}
static void F_114 ( struct V_39 * V_42 ,
unsigned long V_123 ,
unsigned long V_124 )
{
F_75 ( ! F_68 ( V_42 , V_123 ) ) ;
F_75 ( ! F_68 ( V_42 , V_124 ) ) ;
F_75 ( V_123 > V_124 ) ;
F_111 ( V_42 , V_123 , V_124 ) ;
F_112 ( V_42 , F_1 ( V_42 -> V_1 ) ,
V_42 -> V_114 , 0 , V_123 , V_124 ) ;
if ( V_123 == 0 && V_124 == F_115 ( V_42 -> V_129 ) ) {
F_57 ( V_42 -> V_114 ) ;
V_42 -> V_114 = NULL ;
}
}
static struct V_14 * F_116 ( struct V_39 * V_42 ,
int V_5 , struct V_27 * V_28 ,
struct V_14 * V_130 )
{
struct V_14 * V_15 ;
V_15 = F_117 ( F_35 ( V_28 ) >> V_11 ) ;
V_15 -> V_130 = V_130 ;
V_130 = V_15 ;
if ( V_5 == 1 )
return V_130 ;
V_28 = F_56 ( V_15 ) ;
do {
if ( F_38 ( V_28 ) && ! F_39 ( V_28 ) )
V_130 = F_116 ( V_42 , V_5 - 1 ,
V_28 , V_130 ) ;
V_28 ++ ;
} while ( ! F_40 ( V_28 ) );
return V_130 ;
}
static struct V_14 * F_118 ( struct V_39 * V_42 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_123 ,
unsigned long V_124 ,
struct V_14 * V_130 )
{
struct V_27 * V_125 = NULL , * V_131 = NULL ;
V_6 = F_113 ( V_123 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_126 ;
if ( ! F_38 ( V_28 ) )
goto V_128;
V_126 = V_6 & F_8 ( V_5 ) ;
if ( V_123 <= V_126 &&
V_124 >= V_126 + F_9 ( V_5 ) - 1 ) {
if ( V_5 > 1 && ! F_39 ( V_28 ) )
V_130 = F_116 ( V_42 , V_5 - 1 , V_28 , V_130 ) ;
F_34 ( V_28 ) ;
if ( ! V_125 )
V_125 = V_28 ;
V_131 = V_28 ;
} else if ( V_5 > 1 ) {
V_130 = F_118 ( V_42 , V_5 - 1 ,
F_90 ( F_35 ( V_28 ) ) ,
V_126 , V_123 , V_124 ,
V_130 ) ;
}
V_128:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_40 ( ++ V_28 ) && V_6 <= V_124 );
if ( V_125 )
F_101 ( V_42 , V_125 ,
( void * ) ++ V_131 - ( void * ) V_125 ) ;
return V_130 ;
}
static struct V_14 * F_119 ( struct V_39 * V_42 ,
unsigned long V_123 ,
unsigned long V_124 )
{
struct V_14 * V_130 = NULL ;
F_75 ( ! F_68 ( V_42 , V_123 ) ) ;
F_75 ( ! F_68 ( V_42 , V_124 ) ) ;
F_75 ( V_123 > V_124 ) ;
V_130 = F_118 ( V_42 , F_1 ( V_42 -> V_1 ) ,
V_42 -> V_114 , 0 , V_123 , V_124 , NULL ) ;
if ( V_123 == 0 && V_124 == F_115 ( V_42 -> V_129 ) ) {
struct V_14 * V_132 = F_17 ( V_42 -> V_114 ) ;
V_132 -> V_130 = V_130 ;
V_130 = V_132 ;
V_42 -> V_114 = NULL ;
}
return V_130 ;
}
static void F_120 ( struct V_14 * V_130 )
{
struct V_14 * V_15 ;
while ( ( V_15 = V_130 ) ) {
V_130 = V_15 -> V_130 ;
F_57 ( F_56 ( V_15 ) ) ;
}
}
static int F_121 ( struct V_31 * V_32 )
{
struct V_17 * V_87 ;
unsigned long V_33 ;
V_87 = (struct V_17 * ) F_54 ( V_32 -> V_57 ) ;
if ( ! V_87 ) {
F_122 ( L_16 ,
V_32 -> V_133 ) ;
return - V_134 ;
}
F_91 ( V_32 , V_87 , V_135 ) ;
F_104 ( & V_32 -> V_109 , V_33 ) ;
V_32 -> V_17 = V_87 ;
F_105 ( & V_32 -> V_109 , V_33 ) ;
return 0 ;
}
static void F_123 ( struct V_31 * V_32 )
{
V_24 V_108 ;
T_2 V_136 ;
unsigned long V_137 ;
V_108 = F_92 ( V_32 -> V_17 ) ;
if ( F_89 ( V_32 ) )
V_108 |= V_138 ;
F_124 ( & V_32 -> V_139 , V_137 ) ;
F_125 ( V_32 -> V_36 + V_140 , V_108 ) ;
F_126 ( V_32 -> V_141 | V_142 , V_32 -> V_36 + V_143 ) ;
F_127 ( V_32 , V_37 ,
F_44 , ( V_136 & V_144 ) , V_136 ) ;
F_128 ( & V_32 -> V_139 , V_137 ) ;
}
static void F_129 ( struct V_31 * V_32 )
{
T_2 V_29 ;
unsigned long V_137 ;
if ( ! V_145 && ! F_130 ( V_32 -> V_68 ) )
return;
F_124 ( & V_32 -> V_139 , V_137 ) ;
F_126 ( V_32 -> V_141 | V_146 , V_32 -> V_36 + V_143 ) ;
F_127 ( V_32 , V_37 ,
F_44 , ( ! ( V_29 & V_147 ) ) , V_29 ) ;
F_128 ( & V_32 -> V_139 , V_137 ) ;
}
static void F_131 ( struct V_31 * V_32 ,
T_4 V_52 , T_4 V_148 , T_6 V_149 ,
V_24 type )
{
V_24 V_29 = 0 ;
unsigned long V_137 ;
switch ( type ) {
case V_150 :
V_29 = V_150 ;
break;
case V_151 :
V_29 = V_151 | F_132 ( V_52 ) ;
break;
case V_152 :
V_29 = V_152 | F_132 ( V_52 )
| F_133 ( V_148 ) | F_134 ( V_149 ) ;
break;
default:
F_135 () ;
}
V_29 |= V_153 ;
F_124 ( & V_32 -> V_139 , V_137 ) ;
F_125 ( V_32 -> V_36 + V_154 , V_29 ) ;
F_127 ( V_32 , V_154 ,
V_155 , ( ! ( V_29 & V_153 ) ) , V_29 ) ;
F_128 ( & V_32 -> V_139 , V_137 ) ;
}
static void F_136 ( struct V_31 * V_32 , T_4 V_52 ,
V_24 V_108 , unsigned int V_156 , V_24 type )
{
int V_157 = F_137 ( V_32 -> V_78 ) ;
V_24 V_29 = 0 , V_158 = 0 ;
unsigned long V_137 ;
switch ( type ) {
case V_159 :
V_29 = V_159 | V_160 ;
break;
case V_161 :
V_29 = V_161 | V_160 | F_138 ( V_52 ) ;
break;
case V_162 :
V_29 = V_162 | V_160 | F_138 ( V_52 ) ;
V_158 = V_156 | V_108 ;
break;
default:
F_135 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_139 ( V_32 -> V_68 ) )
V_29 |= V_163 ;
F_124 ( & V_32 -> V_139 , V_137 ) ;
if ( V_158 )
F_125 ( V_32 -> V_36 + V_157 , V_158 ) ;
F_125 ( V_32 -> V_36 + V_157 + 8 , V_29 ) ;
F_127 ( V_32 , V_157 + 8 ,
V_155 , ( ! ( V_29 & V_160 ) ) , V_29 ) ;
F_128 ( & V_32 -> V_139 , V_137 ) ;
if ( F_140 ( V_29 ) == 0 )
F_122 ( L_17 ) ;
if ( F_140 ( V_29 ) != F_141 ( type ) )
F_142 ( L_18 ,
( unsigned long long ) F_141 ( type ) ,
( unsigned long long ) F_140 ( V_29 ) ) ;
}
static struct V_164 *
F_143 ( struct V_39 * V_42 , struct V_31 * V_32 ,
T_6 V_84 , T_6 V_85 )
{
bool V_75 = false ;
struct V_164 * V_165 ;
struct V_96 * V_98 ;
F_144 ( & V_166 ) ;
if ( ! F_145 ( V_32 -> V_78 ) )
return NULL ;
if ( ! V_32 -> V_167 )
return NULL ;
F_146 (info, &domain->devices, link)
if ( V_165 -> V_32 == V_32 && V_165 -> V_84 == V_84 &&
V_165 -> V_85 == V_85 ) {
V_75 = true ;
break;
}
if ( ! V_75 || ! V_165 -> V_92 || ! F_95 ( V_165 -> V_92 ) )
return NULL ;
V_98 = F_96 ( V_165 -> V_92 ) ;
if ( ! F_147 ( V_98 , V_168 ) )
return NULL ;
if ( ! F_148 ( V_98 ) )
return NULL ;
return V_165 ;
}
static void F_149 ( struct V_164 * V_165 )
{
struct V_96 * V_98 ;
if ( ! V_165 || ! F_95 ( V_165 -> V_92 ) )
return;
V_98 = F_96 ( V_165 -> V_92 ) ;
if ( F_150 ( V_98 , V_12 ) )
return;
V_165 -> V_169 . V_170 = 1 ;
V_165 -> V_169 . V_171 = F_151 ( V_98 ) ;
}
static void F_152 ( struct V_164 * V_165 )
{
if ( ! V_165 -> V_169 . V_170 )
return;
F_153 ( F_96 ( V_165 -> V_92 ) ) ;
V_165 -> V_169 . V_170 = 0 ;
}
static void F_154 ( struct V_39 * V_42 ,
V_24 V_108 , unsigned V_81 )
{
T_4 V_172 , V_171 ;
unsigned long V_33 ;
struct V_164 * V_165 ;
F_104 ( & V_166 , V_33 ) ;
F_146 (info, &domain->devices, link) {
if ( ! V_165 -> V_169 . V_170 )
continue;
V_172 = V_165 -> V_84 << 8 | V_165 -> V_85 ;
V_171 = V_165 -> V_169 . V_171 ;
F_155 ( V_165 -> V_32 , V_172 , V_171 , V_108 , V_81 ) ;
}
F_105 ( & V_166 , V_33 ) ;
}
static void F_156 ( struct V_31 * V_32 ,
struct V_39 * V_42 ,
unsigned long V_6 , unsigned int V_173 ,
int V_174 , int V_175 )
{
unsigned int V_81 = F_157 ( F_158 ( V_173 ) ) ;
T_7 V_108 = ( T_7 ) V_6 << V_12 ;
T_4 V_52 = V_42 -> V_176 [ V_32 -> V_177 ] ;
F_75 ( V_173 == 0 ) ;
if ( V_174 )
V_174 = 1 << 6 ;
if ( ! F_159 ( V_32 -> V_68 ) || V_81 > F_160 ( V_32 -> V_68 ) )
V_32 -> V_178 . V_179 ( V_32 , V_52 , 0 , 0 ,
V_161 ) ;
else
V_32 -> V_178 . V_179 ( V_32 , V_52 , V_108 | V_174 , V_81 ,
V_162 ) ;
if ( ! F_161 ( V_32 -> V_68 ) || ! V_175 )
F_154 ( F_50 ( V_32 , V_52 ) ,
V_108 , V_81 ) ;
}
static void F_162 ( struct V_31 * V_32 )
{
T_2 V_180 ;
unsigned long V_33 ;
F_124 ( & V_32 -> V_139 , V_33 ) ;
V_180 = F_44 ( V_32 -> V_36 + V_181 ) ;
V_180 &= ~ V_182 ;
F_126 ( V_180 , V_32 -> V_36 + V_181 ) ;
F_127 ( V_32 , V_181 ,
F_44 , ! ( V_180 & V_183 ) , V_180 ) ;
F_128 ( & V_32 -> V_139 , V_33 ) ;
}
static void F_163 ( struct V_31 * V_32 )
{
T_2 V_136 ;
unsigned long V_33 ;
F_124 ( & V_32 -> V_139 , V_33 ) ;
V_32 -> V_141 |= V_184 ;
F_126 ( V_32 -> V_141 , V_32 -> V_36 + V_143 ) ;
F_127 ( V_32 , V_37 ,
F_44 , ( V_136 & V_38 ) , V_136 ) ;
F_128 ( & V_32 -> V_139 , V_33 ) ;
}
static void F_164 ( struct V_31 * V_32 )
{
T_2 V_136 ;
unsigned long V_137 ;
F_124 ( & V_32 -> V_139 , V_137 ) ;
V_32 -> V_141 &= ~ V_184 ;
F_126 ( V_32 -> V_141 , V_32 -> V_36 + V_143 ) ;
F_127 ( V_32 , V_37 ,
F_44 , ( ! ( V_136 & V_38 ) ) , V_136 ) ;
F_128 ( & V_32 -> V_139 , V_137 ) ;
}
static int F_165 ( struct V_31 * V_32 )
{
T_2 V_185 , V_186 ;
T_5 V_55 ;
V_185 = F_166 ( V_32 -> V_68 ) ;
F_142 ( L_19 ,
V_32 -> V_133 , V_185 ) ;
V_186 = F_167 ( V_185 ) ;
F_168 ( & V_32 -> V_109 ) ;
V_32 -> V_187 = F_169 ( V_186 , sizeof( unsigned long ) , V_188 ) ;
if ( ! V_32 -> V_187 ) {
F_122 ( L_20 ,
V_32 -> V_133 ) ;
return - V_134 ;
}
V_55 = ( ( V_185 >> 8 ) + 1 ) * sizeof( struct V_39 * * ) ;
V_32 -> V_53 = F_52 ( V_55 , V_188 ) ;
if ( V_32 -> V_53 ) {
V_55 = 256 * sizeof( struct V_39 * ) ;
V_32 -> V_53 [ 0 ] = F_52 ( V_55 , V_188 ) ;
}
if ( ! V_32 -> V_53 || ! V_32 -> V_53 [ 0 ] ) {
F_122 ( L_21 ,
V_32 -> V_133 ) ;
F_170 ( V_32 -> V_187 ) ;
F_170 ( V_32 -> V_53 ) ;
V_32 -> V_187 = NULL ;
V_32 -> V_53 = NULL ;
return - V_134 ;
}
F_171 ( 0 , V_32 -> V_187 ) ;
return 0 ;
}
static void F_172 ( struct V_31 * V_32 )
{
struct V_164 * V_165 , * V_95 ;
unsigned long V_33 ;
if ( ! V_32 -> V_53 || ! V_32 -> V_187 )
return;
F_104 ( & V_166 , V_33 ) ;
F_173 (info, tmp, &device_domain_list, global) {
struct V_39 * V_42 ;
if ( V_165 -> V_32 != V_32 )
continue;
if ( ! V_165 -> V_92 || ! V_165 -> V_42 )
continue;
V_42 = V_165 -> V_42 ;
F_174 ( V_42 , V_165 -> V_92 ) ;
if ( ! F_67 ( V_42 ) )
F_175 ( V_42 ) ;
}
F_105 ( & V_166 , V_33 ) ;
if ( V_32 -> V_141 & V_184 )
F_164 ( V_32 ) ;
}
static void F_176 ( struct V_31 * V_32 )
{
if ( ( V_32 -> V_53 ) && ( V_32 -> V_187 ) ) {
int V_189 = ( F_166 ( V_32 -> V_68 ) >> 8 ) + 1 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_189 ; V_76 ++ )
F_170 ( V_32 -> V_53 [ V_76 ] ) ;
F_170 ( V_32 -> V_53 ) ;
F_170 ( V_32 -> V_187 ) ;
V_32 -> V_53 = NULL ;
V_32 -> V_187 = NULL ;
}
V_72 [ V_32 -> V_177 ] = NULL ;
F_107 ( V_32 ) ;
}
static struct V_39 * F_177 ( int V_33 )
{
struct V_39 * V_42 ;
V_42 = F_59 () ;
if ( ! V_42 )
return NULL ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_117 = - 1 ;
V_42 -> V_33 = V_33 ;
F_178 ( & V_42 -> V_100 ) ;
return V_42 ;
}
static int F_179 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
unsigned long V_185 ;
int V_190 ;
F_144 ( & V_166 ) ;
F_144 ( & V_32 -> V_109 ) ;
V_42 -> V_191 [ V_32 -> V_177 ] += 1 ;
V_42 -> V_192 += 1 ;
if ( V_42 -> V_191 [ V_32 -> V_177 ] == 1 ) {
V_185 = F_166 ( V_32 -> V_68 ) ;
V_190 = F_180 ( V_32 -> V_187 , V_185 ) ;
if ( V_190 >= V_185 ) {
F_122 ( L_22 , V_32 -> V_133 ) ;
V_42 -> V_191 [ V_32 -> V_177 ] -= 1 ;
V_42 -> V_192 -= 1 ;
return - V_193 ;
}
F_171 ( V_190 , V_32 -> V_187 ) ;
F_51 ( V_32 , V_190 , V_42 ) ;
V_42 -> V_176 [ V_32 -> V_177 ] = V_190 ;
V_42 -> V_117 = V_32 -> V_57 ;
F_87 ( V_42 ) ;
}
return 0 ;
}
static int F_181 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
int V_190 , V_194 = V_195 ;
F_144 ( & V_166 ) ;
F_144 ( & V_32 -> V_109 ) ;
V_42 -> V_191 [ V_32 -> V_177 ] -= 1 ;
V_194 = -- V_42 -> V_192 ;
if ( V_42 -> V_191 [ V_32 -> V_177 ] == 0 ) {
V_190 = V_42 -> V_176 [ V_32 -> V_177 ] ;
F_182 ( V_190 , V_32 -> V_187 ) ;
F_51 ( V_32 , V_190 , NULL ) ;
F_87 ( V_42 ) ;
V_42 -> V_176 [ V_32 -> V_177 ] = 0 ;
}
return V_194 ;
}
static int F_183 ( void )
{
struct V_96 * V_98 = NULL ;
struct V_196 * V_196 ;
int V_76 ;
F_184 ( & V_197 , V_118 , V_198 ,
V_199 ) ;
F_185 ( & V_197 . V_200 ,
& V_201 ) ;
V_196 = F_186 ( & V_197 , F_187 ( V_202 ) ,
F_187 ( V_203 ) ) ;
if ( ! V_196 ) {
F_122 ( L_23 ) ;
return - V_204 ;
}
F_188 (pdev) {
struct V_205 * V_206 ;
for ( V_76 = 0 ; V_76 < V_207 ; V_76 ++ ) {
V_206 = & V_98 -> V_205 [ V_76 ] ;
if ( ! V_206 -> V_33 || ! ( V_206 -> V_33 & V_208 ) )
continue;
V_196 = F_186 ( & V_197 ,
F_187 ( V_206 -> V_209 ) ,
F_187 ( V_206 -> V_105 ) ) ;
if ( ! V_196 ) {
F_122 ( L_24 ) ;
return - V_204 ;
}
}
}
return 0 ;
}
static void F_189 ( struct V_39 * V_42 )
{
F_190 ( & V_197 , & V_42 -> V_210 ) ;
}
static inline int F_191 ( int V_129 )
{
int V_1 ;
int V_206 = ( V_129 - 12 ) % 9 ;
if ( V_206 == 0 )
V_1 = V_129 ;
else
V_1 = V_129 + 9 - V_206 ;
if ( V_1 > 64 )
V_1 = 64 ;
return V_1 ;
}
static int F_192 ( struct V_39 * V_42 , struct V_31 * V_32 ,
int V_211 )
{
int V_212 , V_1 ;
unsigned long V_67 ;
F_184 ( & V_42 -> V_210 , V_118 , V_198 ,
V_199 ) ;
F_189 ( V_42 ) ;
if ( V_211 > F_193 ( V_32 -> V_68 ) )
V_211 = F_193 ( V_32 -> V_68 ) ;
V_42 -> V_129 = V_211 ;
V_212 = F_191 ( V_211 ) ;
V_1 = F_4 ( V_212 ) ;
V_67 = F_70 ( V_32 -> V_68 ) ;
if ( ! F_71 ( V_1 , & V_67 ) ) {
F_142 ( L_25 , V_1 ) ;
V_1 = F_194 ( & V_67 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_204 ;
}
V_42 -> V_1 = V_1 ;
if ( F_78 ( V_32 -> V_78 ) )
V_42 -> V_77 = 1 ;
else
V_42 -> V_77 = 0 ;
if ( F_83 ( V_32 -> V_78 ) )
V_42 -> V_82 = 1 ;
else
V_42 -> V_82 = 0 ;
if ( V_49 )
V_42 -> V_83 = F_86 ( F_85 ( V_32 -> V_68 ) ) ;
else
V_42 -> V_83 = 0 ;
V_42 -> V_117 = V_32 -> V_57 ;
V_42 -> V_114 = (struct V_27 * ) F_54 ( V_42 -> V_117 ) ;
if ( ! V_42 -> V_114 )
return - V_134 ;
F_91 ( V_32 , V_42 -> V_114 , V_213 ) ;
return 0 ;
}
static void F_175 ( struct V_39 * V_42 )
{
struct V_14 * V_130 = NULL ;
if ( ! V_42 )
return;
if ( ! V_48 )
F_195 ( 0 ) ;
F_79 () ;
F_196 ( V_42 ) ;
F_81 () ;
F_197 ( & V_42 -> V_210 ) ;
V_130 = F_119 ( V_42 , 0 , F_115 ( V_42 -> V_129 ) ) ;
F_120 ( V_130 ) ;
F_61 ( V_42 ) ;
}
static int F_198 ( struct V_39 * V_42 ,
struct V_31 * V_32 ,
T_6 V_84 , T_6 V_85 )
{
T_4 V_52 = V_42 -> V_176 [ V_32 -> V_177 ] ;
int V_214 = V_215 ;
struct V_164 * V_165 = NULL ;
struct V_22 * V_23 ;
unsigned long V_33 ;
struct V_27 * V_114 ;
int V_80 , V_1 ;
F_53 ( V_52 == 0 ) ;
if ( V_216 && F_66 ( V_42 ) )
V_214 = V_217 ;
F_142 ( L_26 ,
V_84 , F_199 ( V_85 ) , F_200 ( V_85 ) ) ;
F_75 ( ! V_42 -> V_114 ) ;
F_104 ( & V_166 , V_33 ) ;
F_201 ( & V_32 -> V_109 ) ;
V_80 = - V_134 ;
V_23 = F_88 ( V_32 , V_84 , V_85 , 1 ) ;
if ( ! V_23 )
goto V_218;
V_80 = 0 ;
if ( F_25 ( V_23 ) )
goto V_218;
V_114 = V_42 -> V_114 ;
F_33 ( V_23 ) ;
F_31 ( V_23 , V_52 ) ;
if ( V_214 != V_217 ) {
for ( V_1 = V_42 -> V_1 ; V_1 != V_32 -> V_1 ; V_1 -- ) {
V_80 = - V_134 ;
V_114 = F_90 ( F_35 ( V_114 ) ) ;
if ( ! F_38 ( V_114 ) )
goto V_218;
}
V_165 = F_143 ( V_42 , V_32 , V_84 , V_85 ) ;
V_214 = V_165 ? V_219 :
V_215 ;
F_29 ( V_23 , F_92 ( V_114 ) ) ;
F_30 ( V_23 , V_32 -> V_1 ) ;
} else {
F_30 ( V_23 , V_32 -> V_220 ) ;
}
F_28 ( V_23 , V_214 ) ;
F_27 ( V_23 ) ;
F_26 ( V_23 ) ;
F_101 ( V_42 , V_23 , sizeof( * V_23 ) ) ;
if ( F_161 ( V_32 -> V_68 ) ) {
V_32 -> V_178 . V_221 ( V_32 , 0 ,
( ( ( T_4 ) V_84 ) << 8 ) | V_85 ,
V_222 ,
V_152 ) ;
V_32 -> V_178 . V_179 ( V_32 , V_52 , 0 , 0 , V_161 ) ;
} else {
F_129 ( V_32 ) ;
}
F_149 ( V_165 ) ;
V_80 = 0 ;
V_218:
F_202 ( & V_32 -> V_109 ) ;
F_105 ( & V_166 , V_33 ) ;
return 0 ;
}
static int F_203 ( struct V_96 * V_98 ,
T_4 V_223 , void * V_224 )
{
struct V_225 * V_226 = V_224 ;
return F_198 ( V_226 -> V_42 , V_226 -> V_32 ,
F_204 ( V_223 ) , V_223 & 0xff ) ;
}
static int
F_205 ( struct V_39 * V_42 , struct V_91 * V_92 )
{
struct V_31 * V_32 ;
T_6 V_84 , V_85 ;
struct V_225 V_226 ;
V_32 = F_94 ( V_92 , & V_84 , & V_85 ) ;
if ( ! V_32 )
return - V_204 ;
if ( ! F_95 ( V_92 ) )
return F_198 ( V_42 , V_32 , V_84 , V_85 ) ;
V_226 . V_42 = V_42 ;
V_226 . V_32 = V_32 ;
return F_206 ( F_96 ( V_92 ) ,
& F_203 , & V_226 ) ;
}
static int F_207 ( struct V_96 * V_98 ,
T_4 V_223 , void * V_224 )
{
struct V_31 * V_32 = V_224 ;
return ! F_103 ( V_32 , F_204 ( V_223 ) , V_223 & 0xff ) ;
}
static int F_208 ( struct V_91 * V_92 )
{
struct V_31 * V_32 ;
T_6 V_84 , V_85 ;
V_32 = F_94 ( V_92 , & V_84 , & V_85 ) ;
if ( ! V_32 )
return - V_204 ;
if ( ! F_95 ( V_92 ) )
return F_103 ( V_32 , V_84 , V_85 ) ;
return ! F_206 ( F_96 ( V_92 ) ,
F_207 , V_32 ) ;
}
static inline unsigned long F_209 ( unsigned long V_227 ,
T_5 V_55 )
{
V_227 &= ~ V_228 ;
return F_210 ( V_227 + V_55 ) >> V_12 ;
}
static inline int F_211 ( struct V_39 * V_42 ,
unsigned long V_229 ,
unsigned long V_230 ,
unsigned long V_173 )
{
int V_231 , V_5 = 1 ;
unsigned long V_232 ;
V_231 = V_42 -> V_83 ;
V_232 = V_229 | V_230 ;
while ( V_231 && ! ( V_232 & ~ V_233 ) ) {
V_173 >>= V_234 ;
if ( ! V_173 )
break;
V_232 >>= V_234 ;
V_5 ++ ;
V_231 -- ;
}
return V_5 ;
}
static int F_212 ( struct V_39 * V_42 , unsigned long V_229 ,
struct V_235 * V_236 , unsigned long V_237 ,
unsigned long V_238 , int V_239 )
{
struct V_27 * V_125 = NULL , * V_28 = NULL ;
T_1 V_240 ( V_116 ) ;
unsigned long V_241 = 0 ;
unsigned int V_242 = 0 ;
unsigned long V_243 = 0 ;
F_75 ( ! F_68 ( V_42 , V_229 + V_238 - 1 ) ) ;
if ( ( V_239 & ( V_119 | V_120 ) ) == 0 )
return - V_44 ;
V_239 &= V_119 | V_120 | V_244 ;
if ( ! V_236 ) {
V_241 = V_238 ;
V_116 = ( ( T_1 ) V_237 << V_12 ) | V_239 ;
}
while ( V_238 > 0 ) {
T_7 V_95 ;
if ( ! V_241 ) {
V_241 = F_209 ( V_236 -> V_113 , V_236 -> V_245 ) ;
V_236 -> V_246 = ( ( V_247 ) V_229 << V_12 ) + V_236 -> V_113 ;
V_236 -> V_248 = V_236 -> V_245 ;
V_116 = ( F_213 ( V_236 ) & V_228 ) | V_239 ;
V_237 = V_116 >> V_12 ;
}
if ( ! V_28 ) {
V_242 = F_211 ( V_42 , V_229 , V_237 , V_241 ) ;
V_125 = V_28 = F_108 ( V_42 , V_229 , & V_242 ) ;
if ( ! V_28 )
return - V_134 ;
if ( V_242 > 1 ) {
unsigned long V_249 , V_250 ;
V_116 |= V_30 ;
V_243 = F_11 ( V_242 ) ;
V_249 = V_241 / V_243 ;
V_250 = V_229 + V_249 * V_243 - 1 ;
F_114 ( V_42 , V_229 , V_250 ) ;
} else {
V_116 &= ~ ( T_7 ) V_30 ;
}
}
V_95 = F_214 ( & V_28 -> V_29 , 0ULL , V_116 ) ;
if ( V_95 ) {
static int V_251 = 5 ;
F_215 ( L_27 ,
V_229 , V_95 , ( unsigned long long ) V_116 ) ;
if ( V_251 ) {
V_251 -- ;
F_216 ( NULL ) ;
}
F_53 ( 1 ) ;
}
V_243 = F_11 ( V_242 ) ;
F_75 ( V_238 < V_243 ) ;
F_75 ( V_241 < V_243 ) ;
V_238 -= V_243 ;
V_229 += V_243 ;
V_237 += V_243 ;
V_116 += V_243 * V_118 ;
V_241 -= V_243 ;
V_28 ++ ;
if ( ! V_238 || F_40 ( V_28 ) ||
( V_242 > 1 && V_241 < V_243 ) ) {
F_101 ( V_42 , V_125 ,
( void * ) V_28 - ( void * ) V_125 ) ;
V_28 = NULL ;
}
if ( ! V_241 && V_238 )
V_236 = F_217 ( V_236 ) ;
}
return 0 ;
}
static inline int F_218 ( struct V_39 * V_42 , unsigned long V_229 ,
struct V_235 * V_236 , unsigned long V_238 ,
int V_239 )
{
return F_212 ( V_42 , V_229 , V_236 , 0 , V_238 , V_239 ) ;
}
static inline int F_219 ( struct V_39 * V_42 , unsigned long V_229 ,
unsigned long V_237 , unsigned long V_238 ,
int V_239 )
{
return F_212 ( V_42 , V_229 , NULL , V_237 , V_238 , V_239 ) ;
}
static void F_220 ( struct V_31 * V_32 , T_6 V_84 , T_6 V_85 )
{
if ( ! V_32 )
return;
F_106 ( V_32 , V_84 , V_85 ) ;
V_32 -> V_178 . V_221 ( V_32 , 0 , 0 , 0 ,
V_150 ) ;
V_32 -> V_178 . V_179 ( V_32 , 0 , 0 , 0 , V_159 ) ;
}
static inline void F_221 ( struct V_164 * V_165 )
{
F_144 ( & V_166 ) ;
F_222 ( & V_165 -> V_252 ) ;
F_222 ( & V_165 -> V_253 ) ;
if ( V_165 -> V_92 )
V_165 -> V_92 -> V_93 . V_32 = NULL ;
}
static void F_196 ( struct V_39 * V_42 )
{
struct V_164 * V_165 , * V_95 ;
unsigned long V_33 ;
F_104 ( & V_166 , V_33 ) ;
F_173 (info, tmp, &domain->devices, link)
F_223 ( V_165 ) ;
F_105 ( & V_166 , V_33 ) ;
}
static struct V_39 * F_224 ( struct V_91 * V_92 )
{
struct V_164 * V_165 ;
V_165 = V_92 -> V_93 . V_32 ;
if ( V_165 )
return V_165 -> V_42 ;
return NULL ;
}
static inline struct V_164 *
F_225 ( int V_99 , int V_84 , int V_85 )
{
struct V_164 * V_165 ;
F_146 (info, &device_domain_list, global)
if ( V_165 -> V_32 -> V_99 == V_99 && V_165 -> V_84 == V_84 &&
V_165 -> V_85 == V_85 )
return V_165 ;
return NULL ;
}
static struct V_39 * F_226 ( struct V_31 * V_32 ,
int V_84 , int V_85 ,
struct V_91 * V_92 ,
struct V_39 * V_42 )
{
struct V_39 * V_75 = NULL ;
struct V_164 * V_165 ;
unsigned long V_33 ;
int V_80 ;
V_165 = F_63 () ;
if ( ! V_165 )
return NULL ;
V_165 -> V_84 = V_84 ;
V_165 -> V_85 = V_85 ;
V_165 -> V_169 . V_170 = 0 ;
V_165 -> V_169 . V_171 = 0 ;
V_165 -> V_92 = V_92 ;
V_165 -> V_42 = V_42 ;
V_165 -> V_32 = V_32 ;
F_104 ( & V_166 , V_33 ) ;
if ( V_92 )
V_75 = F_224 ( V_92 ) ;
if ( ! V_75 ) {
struct V_164 * V_254 ;
V_254 = F_225 ( V_32 -> V_99 , V_84 , V_85 ) ;
if ( V_254 ) {
V_75 = V_254 -> V_42 ;
V_254 -> V_92 = V_92 ;
}
}
if ( V_75 ) {
F_105 ( & V_166 , V_33 ) ;
F_64 ( V_165 ) ;
return V_75 ;
}
F_201 ( & V_32 -> V_109 ) ;
V_80 = F_179 ( V_42 , V_32 ) ;
F_202 ( & V_32 -> V_109 ) ;
if ( V_80 ) {
F_105 ( & V_166 , V_33 ) ;
F_64 ( V_165 ) ;
return NULL ;
}
F_227 ( & V_165 -> V_252 , & V_42 -> V_100 ) ;
F_227 ( & V_165 -> V_253 , & V_255 ) ;
if ( V_92 )
V_92 -> V_93 . V_32 = V_165 ;
F_105 ( & V_166 , V_33 ) ;
if ( V_92 && F_205 ( V_42 , V_92 ) ) {
F_122 ( L_28 , F_228 ( V_92 ) ) ;
F_174 ( V_42 , V_92 ) ;
return NULL ;
}
return V_42 ;
}
static int F_229 ( struct V_96 * V_98 , T_4 V_223 , void * V_224 )
{
* ( T_4 * ) V_224 = V_223 ;
return 0 ;
}
static struct V_39 * F_230 ( struct V_91 * V_92 , int V_129 )
{
struct V_164 * V_165 = NULL ;
struct V_39 * V_42 , * V_95 ;
struct V_31 * V_32 ;
T_4 V_256 , V_257 ;
unsigned long V_33 ;
T_6 V_84 , V_85 ;
V_42 = F_224 ( V_92 ) ;
if ( V_42 )
return V_42 ;
V_32 = F_94 ( V_92 , & V_84 , & V_85 ) ;
if ( ! V_32 )
return NULL ;
V_256 = ( ( T_4 ) V_84 << 8 ) | V_85 ;
if ( F_95 ( V_92 ) ) {
struct V_96 * V_98 = F_96 ( V_92 ) ;
F_206 ( V_98 , F_229 , & V_257 ) ;
F_104 ( & V_166 , V_33 ) ;
V_165 = F_225 ( F_97 ( V_98 -> V_84 ) ,
F_204 ( V_257 ) ,
V_257 & 0xff ) ;
if ( V_165 ) {
V_32 = V_165 -> V_32 ;
V_42 = V_165 -> V_42 ;
}
F_105 ( & V_166 , V_33 ) ;
if ( V_165 )
goto V_258;
}
V_42 = F_177 ( 0 ) ;
if ( ! V_42 )
return NULL ;
if ( F_192 ( V_42 , V_32 , V_129 ) ) {
F_175 ( V_42 ) ;
return NULL ;
}
if ( V_256 != V_257 && F_95 ( V_92 ) ) {
V_95 = F_226 ( V_32 , F_204 ( V_257 ) ,
V_257 & 0xff , NULL , V_42 ) ;
if ( ! V_95 || V_95 != V_42 ) {
F_175 ( V_42 ) ;
V_42 = V_95 ;
}
if ( ! V_42 )
return NULL ;
}
V_258:
V_95 = F_226 ( V_32 , V_84 , V_85 , V_92 , V_42 ) ;
if ( ! V_95 || V_95 != V_42 ) {
F_175 ( V_42 ) ;
V_42 = V_95 ;
}
return V_42 ;
}
static int F_231 ( struct V_39 * V_42 ,
unsigned long long V_209 ,
unsigned long long V_105 )
{
unsigned long V_259 = V_209 >> V_12 ;
unsigned long V_260 = V_105 >> V_12 ;
if ( ! F_186 ( & V_42 -> V_210 , F_12 ( V_259 ) ,
F_12 ( V_260 ) ) ) {
F_122 ( L_29 ) ;
return - V_134 ;
}
F_142 ( L_30 , V_209 , V_105 ) ;
F_111 ( V_42 , V_259 , V_260 ) ;
return F_219 ( V_42 , V_259 , V_259 ,
V_260 - V_259 + 1 ,
V_119 | V_120 ) ;
}
static int F_232 ( struct V_91 * V_92 ,
unsigned long long V_209 ,
unsigned long long V_105 )
{
struct V_39 * V_42 ;
int V_80 ;
V_42 = F_230 ( V_92 , V_69 ) ;
if ( ! V_42 )
return - V_134 ;
if ( V_42 == V_261 && V_216 ) {
F_233 ( L_31 ,
F_228 ( V_92 ) , V_209 , V_105 ) ;
return 0 ;
}
F_48 ( L_32 ,
F_228 ( V_92 ) , V_209 , V_105 ) ;
if ( V_105 < V_209 ) {
F_234 ( 1 , L_33
L_34 ,
F_235 ( V_262 ) ,
F_235 ( V_263 ) ,
F_235 ( V_264 ) ) ;
V_80 = - V_265 ;
goto error;
}
if ( V_105 >> F_2 ( V_42 -> V_1 ) ) {
F_234 ( 1 , L_35
L_34 ,
F_2 ( V_42 -> V_1 ) ,
F_235 ( V_262 ) ,
F_235 ( V_263 ) ,
F_235 ( V_264 ) ) ;
V_80 = - V_265 ;
goto error;
}
V_80 = F_231 ( V_42 , V_209 , V_105 ) ;
if ( V_80 )
goto error;
return 0 ;
error:
F_175 ( V_42 ) ;
return V_80 ;
}
static inline int F_236 ( struct V_266 * V_267 ,
struct V_91 * V_92 )
{
if ( V_92 -> V_93 . V_32 == V_94 )
return 0 ;
return F_232 ( V_92 , V_267 -> V_268 ,
V_267 -> V_269 ) ;
}
static inline void F_237 ( void )
{
struct V_96 * V_98 ;
int V_80 ;
V_98 = F_238 ( V_270 << 8 , NULL ) ;
if ( ! V_98 )
return;
F_48 ( L_36 ) ;
V_80 = F_232 ( & V_98 -> V_92 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_80 )
F_122 ( L_37 ) ;
F_239 ( V_98 ) ;
}
static inline void F_237 ( void )
{
return;
}
static int T_3 F_240 ( int V_271 )
{
int V_117 , V_80 = 0 ;
V_261 = F_177 ( V_63 ) ;
if ( ! V_261 )
return - V_272 ;
if ( F_241 ( V_261 , V_69 ) ) {
F_175 ( V_261 ) ;
return - V_272 ;
}
F_142 ( L_38 ) ;
if ( V_271 )
return 0 ;
F_242 (nid) {
unsigned long V_123 , V_250 ;
int V_76 ;
F_243 (i, nid, &start_pfn, &end_pfn, NULL) {
V_80 = F_231 ( V_261 ,
F_244 ( V_123 ) , F_244 ( V_250 ) ) ;
if ( V_80 )
return V_80 ;
}
}
return 0 ;
}
static int F_245 ( struct V_91 * V_92 )
{
struct V_164 * V_165 ;
if ( F_246 ( ! V_273 ) )
return 0 ;
V_165 = V_92 -> V_93 . V_32 ;
if ( V_165 && V_165 != V_94 )
return ( V_165 -> V_42 == V_261 ) ;
return 0 ;
}
static int F_247 ( struct V_39 * V_42 , struct V_91 * V_92 )
{
struct V_39 * V_274 ;
struct V_31 * V_32 ;
T_6 V_84 , V_85 ;
V_32 = F_94 ( V_92 , & V_84 , & V_85 ) ;
if ( ! V_32 )
return - V_204 ;
V_274 = F_226 ( V_32 , V_84 , V_85 , V_92 , V_42 ) ;
if ( V_274 != V_42 )
return - V_275 ;
return 0 ;
}
static bool F_248 ( struct V_91 * V_92 )
{
struct V_266 * V_267 ;
struct V_91 * V_95 ;
int V_76 ;
F_79 () ;
F_249 (rmrr) {
F_100 (rmrr->devices,
rmrr->devices_cnt, i, tmp)
if ( V_95 == V_92 ) {
F_81 () ;
return true ;
}
}
F_81 () ;
return false ;
}
static bool F_250 ( struct V_91 * V_92 )
{
if ( ! F_248 ( V_92 ) )
return false ;
if ( F_95 ( V_92 ) ) {
struct V_96 * V_98 = F_96 ( V_92 ) ;
if ( F_251 ( V_98 ) || F_252 ( V_98 ) )
return false ;
}
return true ;
}
static int F_253 ( struct V_91 * V_92 , int V_276 )
{
if ( F_95 ( V_92 ) ) {
struct V_96 * V_98 = F_96 ( V_92 ) ;
if ( F_250 ( V_92 ) )
return 0 ;
if ( ( V_273 & V_277 ) && F_254 ( V_98 ) )
return 1 ;
if ( ( V_273 & V_278 ) && F_252 ( V_98 ) )
return 1 ;
if ( ! ( V_273 & V_279 ) )
return 0 ;
if ( ! F_255 ( V_98 ) ) {
if ( ! F_256 ( V_98 -> V_84 ) )
return 0 ;
if ( V_98 -> V_280 >> 8 == V_281 )
return 0 ;
} else if ( F_257 ( V_98 ) == V_282 )
return 0 ;
} else {
if ( F_248 ( V_92 ) )
return 0 ;
}
if ( ! V_276 ) {
V_24 V_283 = * V_92 -> V_283 ;
if ( V_92 -> V_284 &&
V_92 -> V_284 < V_283 )
V_283 = V_92 -> V_284 ;
return V_283 >= F_258 ( V_92 ) ;
}
return 1 ;
}
static int T_3 F_259 ( struct V_91 * V_92 , int V_271 )
{
int V_80 ;
if ( ! F_253 ( V_92 , 1 ) )
return 0 ;
V_80 = F_247 ( V_261 , V_92 ) ;
if ( ! V_80 )
F_48 ( L_39 ,
V_271 ? L_40 : L_41 , F_228 ( V_92 ) ) ;
else if ( V_80 == - V_204 )
V_80 = 0 ;
return V_80 ;
}
static int T_3 F_260 ( int V_271 )
{
struct V_96 * V_98 = NULL ;
struct V_73 * V_74 ;
struct V_31 * V_32 ;
struct V_91 * V_92 ;
int V_76 ;
int V_80 = 0 ;
F_188 (pdev) {
V_80 = F_259 ( & V_98 -> V_92 , V_271 ) ;
if ( V_80 )
return V_80 ;
}
F_80 (iommu, drhd)
F_100 (drhd->devices, drhd->devices_cnt, i, dev) {
struct V_285 * V_286 ;
struct V_287 * V_288 ;
if ( V_92 -> V_84 != & V_289 )
continue;
V_288 = F_261 ( V_92 ) ;
F_262 ( & V_288 -> V_290 ) ;
F_146 (pn, &adev->physical_node_list, node) {
V_80 = F_259 ( V_286 -> V_92 , V_271 ) ;
if ( V_80 )
break;
}
F_263 ( & V_288 -> V_290 ) ;
if ( V_80 )
return V_80 ;
}
return 0 ;
}
static void F_264 ( struct V_31 * V_32 )
{
if ( ! V_32 -> V_167 ) {
F_265 ( - 1 , V_32 ) ;
F_266 ( V_32 ) ;
}
if ( F_267 ( V_32 ) ) {
V_32 -> V_178 . V_221 = F_131 ;
V_32 -> V_178 . V_179 = F_136 ;
F_48 ( L_42 ,
V_32 -> V_133 ) ;
} else {
V_32 -> V_178 . V_221 = V_291 ;
V_32 -> V_178 . V_179 = V_292 ;
F_48 ( L_43 , V_32 -> V_133 ) ;
}
}
static int F_268 ( struct V_31 * V_32 ,
struct V_17 T_8 * V_293 ,
struct V_22 * * V_294 ,
int V_84 , bool V_295 )
{
int V_296 , V_297 = 0 , V_54 , V_85 , V_80 = 0 , V_52 ;
struct V_22 T_8 * V_298 = NULL ;
struct V_22 * V_299 = NULL , V_300 ;
struct V_17 V_18 ;
T_1 V_301 ;
V_296 = V_295 ? V_84 * 2 : V_84 ;
F_269 ( & V_18 , V_293 , sizeof( V_18 ) ) ;
for ( V_85 = 0 ; V_85 < 256 ; V_85 ++ ) {
V_54 = ( V_295 ? V_85 * 2 : V_85 ) % 256 ;
if ( V_54 == 0 ) {
if ( V_299 ) {
V_294 [ V_296 ] = V_299 ;
F_91 ( V_32 , V_299 ,
V_118 ) ;
V_297 = 1 ;
}
if ( V_298 )
F_270 ( V_298 ) ;
V_80 = 0 ;
if ( V_85 < 0x80 )
V_301 = F_18 ( & V_18 ) ;
else
V_301 = F_19 ( & V_18 ) ;
if ( ! V_301 ) {
if ( V_295 && V_85 == 0 ) {
V_85 = 0x7f ;
continue;
} else {
goto V_101;
}
}
V_80 = - V_134 ;
V_298 = F_271 ( V_301 , V_213 ) ;
if ( ! V_298 )
goto V_101;
V_299 = F_54 ( V_32 -> V_57 ) ;
if ( ! V_299 )
goto V_302;
V_80 = 0 ;
}
F_269 ( & V_300 , V_298 + V_54 , sizeof( V_300 ) ) ;
if ( ! F_24 ( & V_300 ) )
continue;
V_52 = F_32 ( & V_300 ) ;
if ( V_52 >= 0 && V_52 < F_166 ( V_32 -> V_68 ) )
F_171 ( V_52 , V_32 -> V_187 ) ;
F_20 ( & V_300 ) ;
F_22 ( & V_300 ) ;
V_299 [ V_54 ] = V_300 ;
}
V_294 [ V_296 + V_297 ] = V_299 ;
F_91 ( V_32 , V_299 , V_118 ) ;
V_302:
F_270 ( V_298 ) ;
V_101:
return V_80 ;
}
static int F_272 ( struct V_31 * V_32 )
{
struct V_17 T_8 * V_303 ;
struct V_22 * * V_304 ;
T_1 V_305 ;
int V_306 ;
unsigned long V_33 ;
V_24 V_307 ;
int V_84 , V_80 ;
bool V_308 , V_295 ;
V_307 = V_155 ( V_32 -> V_36 + V_140 ) ;
V_295 = ! ! ( V_307 & V_138 ) ;
V_308 = ! ! F_273 ( V_32 -> V_78 ) ;
if ( V_308 != V_295 )
return - V_44 ;
V_305 = V_307 & V_20 ;
if ( ! V_305 )
return - V_44 ;
V_303 = F_271 ( V_305 , V_213 ) ;
if ( ! V_303 )
return - V_134 ;
V_306 = V_295 ? 512 : 256 ;
V_80 = - V_134 ;
V_304 = F_52 ( V_306 * sizeof( void * ) , V_188 ) ;
if ( ! V_304 )
goto V_302;
for ( V_84 = 0 ; V_84 < 256 ; V_84 ++ ) {
V_80 = F_268 ( V_32 , & V_303 [ V_84 ] ,
V_304 , V_84 , V_295 ) ;
if ( V_80 ) {
F_122 ( L_44 ,
V_32 -> V_133 , V_84 ) ;
continue;
}
}
F_104 ( & V_32 -> V_109 , V_33 ) ;
for ( V_84 = 0 ; V_84 < 256 ; V_84 ++ ) {
int V_54 = V_295 ? V_84 * 2 : V_84 ;
V_24 V_29 ;
if ( V_304 [ V_54 ] ) {
V_29 = F_92 ( V_304 [ V_54 ] ) | 1 ;
V_32 -> V_17 [ V_84 ] . V_19 = V_29 ;
}
if ( ! V_295 || ! V_304 [ V_54 + 1 ] )
continue;
V_29 = F_92 ( V_304 [ V_54 + 1 ] ) | 1 ;
V_32 -> V_17 [ V_84 ] . V_21 = V_29 ;
}
F_105 ( & V_32 -> V_109 , V_33 ) ;
F_170 ( V_304 ) ;
F_91 ( V_32 , V_32 -> V_17 , V_213 ) ;
V_80 = 0 ;
V_302:
F_270 ( V_303 ) ;
return V_80 ;
}
static int T_3 F_274 ( void )
{
struct V_73 * V_74 ;
struct V_266 * V_267 ;
bool V_309 = false ;
struct V_91 * V_92 ;
struct V_31 * V_32 ;
int V_76 , V_80 ;
F_275 (drhd) {
if ( V_71 < V_310 ) {
V_71 ++ ;
continue;
}
F_276 ( L_45 , V_310 ) ;
}
if ( V_71 < V_310 )
V_71 = V_310 ;
V_72 = F_169 ( V_71 , sizeof( struct V_31 * ) ,
V_188 ) ;
if ( ! V_72 ) {
F_122 ( L_46 ) ;
V_80 = - V_134 ;
goto error;
}
V_311 = F_52 ( V_71 *
sizeof( struct V_312 ) , V_188 ) ;
if ( ! V_311 ) {
V_80 = - V_134 ;
goto V_313;
}
F_80 (iommu, drhd) {
V_72 [ V_32 -> V_177 ] = V_32 ;
F_264 ( V_32 ) ;
V_80 = F_165 ( V_32 ) ;
if ( V_80 )
goto V_314;
F_43 ( V_32 ) ;
if ( F_41 ( V_32 ) && ! F_277 () ) {
F_164 ( V_32 ) ;
F_42 ( V_32 ) ;
F_233 ( L_47 ,
V_32 -> V_133 ) ;
}
V_80 = F_121 ( V_32 ) ;
if ( V_80 )
goto V_314;
if ( F_41 ( V_32 ) ) {
F_48 ( L_48 ) ;
V_80 = F_272 ( V_32 ) ;
if ( V_80 ) {
F_122 ( L_49 ,
V_32 -> V_133 ) ;
F_164 ( V_32 ) ;
F_42 ( V_32 ) ;
} else {
F_48 ( L_50 ,
V_32 -> V_133 ) ;
V_309 = true ;
}
}
F_129 ( V_32 ) ;
F_123 ( V_32 ) ;
V_32 -> V_178 . V_221 ( V_32 , 0 , 0 , 0 , V_150 ) ;
V_32 -> V_178 . V_179 ( V_32 , 0 , 0 , 0 , V_159 ) ;
if ( ! F_278 ( V_32 -> V_78 ) )
V_216 = 0 ;
}
if ( V_315 )
V_273 |= V_279 ;
#ifdef F_279
V_273 |= V_278 ;
#endif
if ( V_273 ) {
V_80 = F_240 ( V_216 ) ;
if ( V_80 )
goto V_314;
}
F_280 () ;
if ( V_309 )
goto V_316;
if ( V_273 ) {
V_80 = F_260 ( V_216 ) ;
if ( V_80 ) {
F_215 ( L_51 ) ;
goto V_314;
}
}
F_48 ( L_52 ) ;
F_249 (rmrr) {
F_100 (rmrr->devices, rmrr->devices_cnt,
i, dev) {
V_80 = F_236 ( V_267 , V_92 ) ;
if ( V_80 )
F_122 ( L_53 ) ;
}
}
F_237 () ;
V_316:
F_281 (iommu, drhd) {
if ( V_74 -> V_317 ) {
if ( V_318 )
F_162 ( V_32 ) ;
continue;
}
F_129 ( V_32 ) ;
V_80 = F_282 ( V_32 ) ;
if ( V_80 )
goto V_314;
if ( ! F_41 ( V_32 ) )
F_163 ( V_32 ) ;
F_162 ( V_32 ) ;
}
return 0 ;
V_314:
F_80 (iommu, drhd) {
F_172 ( V_32 ) ;
F_176 ( V_32 ) ;
}
F_170 ( V_311 ) ;
V_313:
F_170 ( V_72 ) ;
error:
return V_80 ;
}
static struct V_196 * F_283 ( struct V_91 * V_92 ,
struct V_39 * V_42 ,
unsigned long V_319 , T_7 V_283 )
{
struct V_196 * V_196 = NULL ;
V_283 = F_3 ( T_7 , F_284 ( V_42 -> V_129 ) , V_283 ) ;
V_319 = F_158 ( V_319 ) ;
if ( ! V_47 && V_283 > F_285 ( 32 ) ) {
V_196 = F_286 ( & V_42 -> V_210 , V_319 ,
F_187 ( F_285 ( 32 ) ) , 1 ) ;
if ( V_196 )
return V_196 ;
}
V_196 = F_286 ( & V_42 -> V_210 , V_319 , F_187 ( V_283 ) , 1 ) ;
if ( F_287 ( ! V_196 ) ) {
F_122 ( L_54 ,
V_319 , F_228 ( V_92 ) ) ;
return NULL ;
}
return V_196 ;
}
static struct V_39 * F_288 ( struct V_91 * V_92 )
{
struct V_39 * V_42 ;
V_42 = F_230 ( V_92 , V_69 ) ;
if ( ! V_42 ) {
F_122 ( L_55 ,
F_228 ( V_92 ) ) ;
return NULL ;
}
return V_42 ;
}
static inline struct V_39 * F_289 ( struct V_91 * V_92 )
{
struct V_164 * V_165 ;
V_165 = V_92 -> V_93 . V_32 ;
if ( F_246 ( V_165 ) )
return V_165 -> V_42 ;
return F_288 ( V_92 ) ;
}
static int F_290 ( struct V_91 * V_92 )
{
int V_75 ;
if ( F_93 ( V_92 ) )
return 1 ;
if ( ! V_273 )
return 0 ;
V_75 = F_245 ( V_92 ) ;
if ( V_75 ) {
if ( F_253 ( V_92 , 0 ) )
return 1 ;
else {
F_174 ( V_261 , V_92 ) ;
F_48 ( L_56 ,
F_228 ( V_92 ) ) ;
return 0 ;
}
} else {
if ( F_253 ( V_92 , 0 ) ) {
int V_80 ;
V_80 = F_247 ( V_261 , V_92 ) ;
if ( ! V_80 ) {
F_48 ( L_57 ,
F_228 ( V_92 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_247 F_291 ( struct V_91 * V_92 , T_1 V_320 ,
T_5 V_55 , int V_321 , V_24 V_283 )
{
struct V_39 * V_42 ;
T_1 V_322 ;
struct V_196 * V_196 ;
int V_239 = 0 ;
int V_80 ;
struct V_31 * V_32 ;
unsigned long V_323 = V_320 >> V_11 ;
F_75 ( V_321 == V_324 ) ;
if ( F_290 ( V_92 ) )
return V_320 ;
V_42 = F_289 ( V_92 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_74 ( V_42 ) ;
V_55 = F_209 ( V_320 , V_55 ) ;
V_196 = F_283 ( V_92 , V_42 , F_12 ( V_55 ) , V_283 ) ;
if ( ! V_196 )
goto error;
if ( V_321 == V_325 || V_321 == V_326 || \
! F_292 ( V_32 -> V_68 ) )
V_239 |= V_119 ;
if ( V_321 == V_327 || V_321 == V_326 )
V_239 |= V_120 ;
V_80 = F_219 ( V_42 , F_13 ( V_196 -> V_328 ) ,
F_13 ( V_323 ) , V_55 , V_239 ) ;
if ( V_80 )
goto error;
if ( F_161 ( V_32 -> V_68 ) )
F_156 ( V_32 , V_42 ,
F_13 ( V_196 -> V_328 ) ,
V_55 , 0 , 1 ) ;
else
F_129 ( V_32 ) ;
V_322 = ( T_1 ) V_196 -> V_328 << V_11 ;
V_322 += V_320 & ~ V_228 ;
return V_322 ;
error:
if ( V_196 )
F_293 ( & V_42 -> V_210 , V_196 ) ;
F_122 ( L_58 ,
F_228 ( V_92 ) , V_55 , ( unsigned long long ) V_320 , V_321 ) ;
return 0 ;
}
static V_247 F_294 ( struct V_91 * V_92 , struct V_14 * V_14 ,
unsigned long V_113 , T_5 V_55 ,
enum V_329 V_321 ,
struct V_330 * V_331 )
{
return F_291 ( V_92 , F_295 ( V_14 ) + V_113 , V_55 ,
V_321 , * V_92 -> V_283 ) ;
}
static void F_296 ( void )
{
int V_76 , V_332 ;
V_333 = 0 ;
for ( V_76 = 0 ; V_76 < V_71 ; V_76 ++ ) {
struct V_31 * V_32 = V_72 [ V_76 ] ;
if ( ! V_32 )
continue;
if ( ! V_311 [ V_76 ] . V_128 )
continue;
if ( ! F_161 ( V_32 -> V_68 ) )
V_32 -> V_178 . V_179 ( V_32 , 0 , 0 , 0 ,
V_159 ) ;
for ( V_332 = 0 ; V_332 < V_311 [ V_76 ] . V_128 ; V_332 ++ ) {
unsigned long V_81 ;
struct V_196 * V_196 = V_311 [ V_76 ] . V_196 [ V_332 ] ;
struct V_39 * V_42 = V_311 [ V_76 ] . V_42 [ V_332 ] ;
if ( F_161 ( V_32 -> V_68 ) )
F_156 ( V_32 , V_42 ,
V_196 -> V_328 , F_297 ( V_196 ) ,
! V_311 [ V_76 ] . V_130 [ V_332 ] , 0 ) ;
else {
V_81 = F_157 ( F_13 ( F_297 ( V_196 ) ) ) ;
F_154 ( V_311 [ V_76 ] . V_42 [ V_332 ] ,
( T_7 ) V_196 -> V_328 << V_11 , V_81 ) ;
}
F_293 ( & V_311 [ V_76 ] . V_42 [ V_332 ] -> V_210 , V_196 ) ;
if ( V_311 [ V_76 ] . V_130 [ V_332 ] )
F_120 ( V_311 [ V_76 ] . V_130 [ V_332 ] ) ;
}
V_311 [ V_76 ] . V_128 = 0 ;
}
V_334 = 0 ;
}
static void F_195 ( unsigned long V_226 )
{
unsigned long V_33 ;
F_104 ( & V_335 , V_33 ) ;
F_296 () ;
F_105 ( & V_335 , V_33 ) ;
}
static void F_298 ( struct V_39 * V_41 , struct V_196 * V_196 , struct V_14 * V_130 )
{
unsigned long V_33 ;
int V_128 , V_70 ;
struct V_31 * V_32 ;
F_104 ( & V_335 , V_33 ) ;
if ( V_334 == V_336 )
F_296 () ;
V_32 = F_74 ( V_41 ) ;
V_70 = V_32 -> V_177 ;
V_128 = V_311 [ V_70 ] . V_128 ;
V_311 [ V_70 ] . V_42 [ V_128 ] = V_41 ;
V_311 [ V_70 ] . V_196 [ V_128 ] = V_196 ;
V_311 [ V_70 ] . V_130 [ V_128 ] = V_130 ;
V_311 [ V_70 ] . V_128 ++ ;
if ( ! V_333 ) {
F_299 ( & V_337 , V_338 + F_300 ( 10 ) ) ;
V_333 = 1 ;
}
V_334 ++ ;
F_105 ( & V_335 , V_33 ) ;
}
static void F_301 ( struct V_91 * V_92 , V_247 V_339 )
{
struct V_39 * V_42 ;
unsigned long V_123 , V_124 ;
struct V_196 * V_196 ;
struct V_31 * V_32 ;
struct V_14 * V_130 ;
if ( F_290 ( V_92 ) )
return;
V_42 = F_224 ( V_92 ) ;
F_75 ( ! V_42 ) ;
V_32 = F_74 ( V_42 ) ;
V_196 = F_302 ( & V_42 -> V_210 , F_187 ( V_339 ) ) ;
if ( F_303 ( ! V_196 , L_59 ,
( unsigned long long ) V_339 ) )
return;
V_123 = F_13 ( V_196 -> V_328 ) ;
V_124 = F_13 ( V_196 -> V_340 + 1 ) - 1 ;
F_142 ( L_60 ,
F_228 ( V_92 ) , V_123 , V_124 ) ;
V_130 = F_119 ( V_42 , V_123 , V_124 ) ;
if ( V_48 ) {
F_156 ( V_32 , V_42 , V_123 ,
V_124 - V_123 + 1 , ! V_130 , 0 ) ;
F_293 ( & V_42 -> V_210 , V_196 ) ;
F_120 ( V_130 ) ;
} else {
F_298 ( V_42 , V_196 , V_130 ) ;
}
}
static void F_304 ( struct V_91 * V_92 , V_247 V_339 ,
T_5 V_55 , enum V_329 V_321 ,
struct V_330 * V_331 )
{
F_301 ( V_92 , V_339 ) ;
}
static void * F_305 ( struct V_91 * V_92 , T_5 V_55 ,
V_247 * V_341 , T_9 V_33 ,
struct V_330 * V_331 )
{
struct V_14 * V_14 = NULL ;
int V_342 ;
V_55 = F_210 ( V_55 ) ;
V_342 = F_306 ( V_55 ) ;
if ( ! F_290 ( V_92 ) )
V_33 &= ~ ( V_343 | V_344 ) ;
else if ( V_92 -> V_284 < F_258 ( V_92 ) ) {
if ( V_92 -> V_284 < F_285 ( 32 ) )
V_33 |= V_343 ;
else
V_33 |= V_344 ;
}
if ( V_33 & V_345 ) {
unsigned int V_194 = V_55 >> V_11 ;
V_14 = F_307 ( V_92 , V_194 , V_342 ) ;
if ( V_14 && F_290 ( V_92 ) &&
F_295 ( V_14 ) + V_55 > V_92 -> V_284 ) {
F_308 ( V_92 , V_14 , V_194 ) ;
V_14 = NULL ;
}
}
if ( ! V_14 )
V_14 = F_309 ( V_33 , V_342 ) ;
if ( ! V_14 )
return NULL ;
memset ( F_56 ( V_14 ) , 0 , V_55 ) ;
* V_341 = F_291 ( V_92 , F_295 ( V_14 ) , V_55 ,
V_326 ,
V_92 -> V_284 ) ;
if ( * V_341 )
return F_56 ( V_14 ) ;
if ( ! F_308 ( V_92 , V_14 , V_55 >> V_11 ) )
F_310 ( V_14 , V_342 ) ;
return NULL ;
}
static void F_311 ( struct V_91 * V_92 , T_5 V_55 , void * V_58 ,
V_247 V_341 , struct V_330 * V_331 )
{
int V_342 ;
struct V_14 * V_14 = F_17 ( V_58 ) ;
V_55 = F_210 ( V_55 ) ;
V_342 = F_306 ( V_55 ) ;
F_301 ( V_92 , V_341 ) ;
if ( ! F_308 ( V_92 , V_14 , V_55 >> V_11 ) )
F_310 ( V_14 , V_342 ) ;
}
static void F_312 ( struct V_91 * V_92 , struct V_235 * V_346 ,
int V_347 , enum V_329 V_321 ,
struct V_330 * V_331 )
{
F_301 ( V_92 , V_346 [ 0 ] . V_246 ) ;
}
static int F_313 ( struct V_91 * V_348 ,
struct V_235 * V_346 , int V_347 , int V_321 )
{
int V_76 ;
struct V_235 * V_236 ;
F_314 (sglist, sg, nelems, i) {
F_75 ( ! F_315 ( V_236 ) ) ;
V_236 -> V_246 = F_213 ( V_236 ) ;
V_236 -> V_248 = V_236 -> V_245 ;
}
return V_347 ;
}
static int F_316 ( struct V_91 * V_92 , struct V_235 * V_346 , int V_347 ,
enum V_329 V_321 , struct V_330 * V_331 )
{
int V_76 ;
struct V_39 * V_42 ;
T_5 V_55 = 0 ;
int V_239 = 0 ;
struct V_196 * V_196 = NULL ;
int V_80 ;
struct V_235 * V_236 ;
unsigned long V_349 ;
struct V_31 * V_32 ;
F_75 ( V_321 == V_324 ) ;
if ( F_290 ( V_92 ) )
return F_313 ( V_92 , V_346 , V_347 , V_321 ) ;
V_42 = F_289 ( V_92 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_74 ( V_42 ) ;
F_314 (sglist, sg, nelems, i)
V_55 += F_209 ( V_236 -> V_113 , V_236 -> V_245 ) ;
V_196 = F_283 ( V_92 , V_42 , F_12 ( V_55 ) ,
* V_92 -> V_283 ) ;
if ( ! V_196 ) {
V_346 -> V_248 = 0 ;
return 0 ;
}
if ( V_321 == V_325 || V_321 == V_326 || \
! F_292 ( V_32 -> V_68 ) )
V_239 |= V_119 ;
if ( V_321 == V_327 || V_321 == V_326 )
V_239 |= V_120 ;
V_349 = F_13 ( V_196 -> V_328 ) ;
V_80 = F_218 ( V_42 , V_349 , V_346 , V_55 , V_239 ) ;
if ( F_287 ( V_80 ) ) {
F_114 ( V_42 , V_349 ,
V_349 + V_55 - 1 ) ;
F_293 ( & V_42 -> V_210 , V_196 ) ;
return 0 ;
}
if ( F_161 ( V_32 -> V_68 ) )
F_156 ( V_32 , V_42 , V_349 , V_55 , 0 , 1 ) ;
else
F_129 ( V_32 ) ;
return V_347 ;
}
static int F_317 ( struct V_91 * V_92 , V_247 V_350 )
{
return ! V_350 ;
}
static inline int F_318 ( void )
{
int V_80 = 0 ;
V_60 = F_319 ( L_61 ,
sizeof( struct V_39 ) ,
0 ,
V_351 ,
NULL ) ;
if ( ! V_60 ) {
F_122 ( L_62 ) ;
V_80 = - V_134 ;
}
return V_80 ;
}
static inline int F_320 ( void )
{
int V_80 = 0 ;
V_61 = F_319 ( L_63 ,
sizeof( struct V_164 ) ,
0 ,
V_351 ,
NULL ) ;
if ( ! V_61 ) {
F_122 ( L_64 ) ;
V_80 = - V_134 ;
}
return V_80 ;
}
static int T_3 F_321 ( void )
{
int V_80 ;
V_80 = F_322 () ;
if ( V_80 )
return V_80 ;
V_80 = F_318 () ;
if ( V_80 )
goto V_352;
V_80 = F_320 () ;
if ( ! V_80 )
return V_80 ;
F_323 ( V_60 ) ;
V_352:
F_324 () ;
return - V_134 ;
}
static void T_3 F_325 ( void )
{
F_323 ( V_61 ) ;
F_323 ( V_60 ) ;
F_324 () ;
}
static void F_326 ( struct V_96 * V_98 )
{
struct V_73 * V_74 ;
T_2 V_353 ;
int V_354 ;
V_354 = F_327 ( V_98 -> V_84 , F_328 ( 0 , 0 ) , 0xb0 , & V_353 ) ;
if ( V_354 ) {
F_329 ( & V_98 -> V_92 , L_65 ) ;
return;
}
V_353 &= 0xffff0000 ;
V_74 = F_330 ( V_98 ) ;
if ( F_331 ( ! V_74 || V_74 -> V_355 - V_353 != 0xa000 ,
V_356 ,
L_66 ) )
V_98 -> V_92 . V_93 . V_32 = V_94 ;
}
static void T_3 F_332 ( void )
{
struct V_73 * V_74 ;
struct V_91 * V_92 ;
int V_76 ;
F_275 (drhd) {
if ( ! V_74 -> V_107 ) {
F_100 (drhd->devices,
drhd->devices_cnt, i, dev)
break;
if ( V_76 == V_74 -> V_357 )
V_74 -> V_317 = 1 ;
}
}
F_333 (drhd) {
if ( V_74 -> V_107 )
continue;
F_100 (drhd->devices,
drhd->devices_cnt, i, dev)
if ( ! F_95 ( V_92 ) || ! F_252 ( F_96 ( V_92 ) ) )
break;
if ( V_76 < V_74 -> V_357 )
continue;
if ( V_46 ) {
V_358 = 1 ;
} else {
V_74 -> V_317 = 1 ;
F_100 (drhd->devices,
drhd->devices_cnt, i, dev)
V_92 -> V_93 . V_32 = V_94 ;
}
}
}
static int F_334 ( void )
{
struct V_73 * V_74 ;
struct V_31 * V_32 = NULL ;
F_80 (iommu, drhd)
if ( V_32 -> V_167 )
F_335 ( V_32 ) ;
F_281 (iommu, drhd) {
if ( V_74 -> V_317 ) {
if ( V_318 )
F_162 ( V_32 ) ;
continue;
}
F_129 ( V_32 ) ;
F_123 ( V_32 ) ;
V_32 -> V_178 . V_221 ( V_32 , 0 , 0 , 0 ,
V_150 ) ;
V_32 -> V_178 . V_179 ( V_32 , 0 , 0 , 0 , V_159 ) ;
F_163 ( V_32 ) ;
F_162 ( V_32 ) ;
}
return 0 ;
}
static void F_336 ( void )
{
struct V_73 * V_74 ;
struct V_31 * V_32 ;
F_80 (iommu, drhd) {
V_32 -> V_178 . V_221 ( V_32 , 0 , 0 , 0 ,
V_150 ) ;
V_32 -> V_178 . V_179 ( V_32 , 0 , 0 , 0 ,
V_159 ) ;
}
}
static int F_337 ( void )
{
struct V_73 * V_74 ;
struct V_31 * V_32 = NULL ;
unsigned long V_137 ;
F_80 (iommu, drhd) {
V_32 -> V_359 = F_52 ( sizeof( T_2 ) * V_360 ,
V_56 ) ;
if ( ! V_32 -> V_359 )
goto V_361;
}
F_336 () ;
F_80 (iommu, drhd) {
F_164 ( V_32 ) ;
F_124 ( & V_32 -> V_139 , V_137 ) ;
V_32 -> V_359 [ V_362 ] =
F_44 ( V_32 -> V_36 + V_363 ) ;
V_32 -> V_359 [ V_364 ] =
F_44 ( V_32 -> V_36 + V_365 ) ;
V_32 -> V_359 [ V_366 ] =
F_44 ( V_32 -> V_36 + V_367 ) ;
V_32 -> V_359 [ V_368 ] =
F_44 ( V_32 -> V_36 + V_369 ) ;
F_128 ( & V_32 -> V_139 , V_137 ) ;
}
return 0 ;
V_361:
F_80 (iommu, drhd)
F_170 ( V_32 -> V_359 ) ;
return - V_134 ;
}
static void F_338 ( void )
{
struct V_73 * V_74 ;
struct V_31 * V_32 = NULL ;
unsigned long V_137 ;
if ( F_334 () ) {
if ( V_318 )
F_339 ( L_67 ) ;
else
F_234 ( 1 , L_68 ) ;
return;
}
F_80 (iommu, drhd) {
F_124 ( & V_32 -> V_139 , V_137 ) ;
F_126 ( V_32 -> V_359 [ V_362 ] ,
V_32 -> V_36 + V_363 ) ;
F_126 ( V_32 -> V_359 [ V_364 ] ,
V_32 -> V_36 + V_365 ) ;
F_126 ( V_32 -> V_359 [ V_366 ] ,
V_32 -> V_36 + V_367 ) ;
F_126 ( V_32 -> V_359 [ V_368 ] ,
V_32 -> V_36 + V_369 ) ;
F_128 ( & V_32 -> V_139 , V_137 ) ;
}
F_80 (iommu, drhd)
F_170 ( V_32 -> V_359 ) ;
}
static void T_3 F_340 ( void )
{
F_341 ( & V_370 ) ;
}
static inline void F_340 ( void ) {}
int T_3 F_342 ( struct V_371 * V_372 , void * V_373 )
{
struct V_374 * V_267 ;
struct V_266 * V_375 ;
V_375 = F_52 ( sizeof( * V_375 ) , V_188 ) ;
if ( ! V_375 )
return - V_134 ;
V_375 -> V_376 = V_372 ;
V_267 = (struct V_374 * ) V_372 ;
V_375 -> V_268 = V_267 -> V_268 ;
V_375 -> V_269 = V_267 -> V_269 ;
V_375 -> V_100 = F_343 ( ( void * ) ( V_267 + 1 ) ,
( ( void * ) V_267 ) + V_267 -> V_372 . V_245 ,
& V_375 -> V_357 ) ;
if ( V_375 -> V_357 && V_375 -> V_100 == NULL ) {
F_170 ( V_375 ) ;
return - V_134 ;
}
F_227 ( & V_375 -> V_377 , & V_378 ) ;
return 0 ;
}
static struct V_379 * F_344 ( struct V_380 * V_381 )
{
struct V_379 * V_382 ;
struct V_380 * V_95 ;
F_345 (atsru, &dmar_atsr_units, list) {
V_95 = (struct V_380 * ) V_382 -> V_376 ;
if ( V_381 -> V_99 != V_95 -> V_99 )
continue;
if ( V_381 -> V_372 . V_245 != V_95 -> V_372 . V_245 )
continue;
if ( memcmp ( V_381 , V_95 , V_381 -> V_372 . V_245 ) == 0 )
return V_382 ;
}
return NULL ;
}
int F_346 ( struct V_371 * V_376 , void * V_373 )
{
struct V_380 * V_381 ;
struct V_379 * V_382 ;
if ( V_383 != V_384 && ! V_385 )
return 0 ;
V_381 = F_46 ( V_376 , struct V_380 , V_372 ) ;
V_382 = F_344 ( V_381 ) ;
if ( V_382 )
return 0 ;
V_382 = F_52 ( sizeof( * V_382 ) + V_376 -> V_245 , V_188 ) ;
if ( ! V_382 )
return - V_134 ;
V_382 -> V_376 = ( void * ) ( V_382 + 1 ) ;
memcpy ( V_382 -> V_376 , V_376 , V_376 -> V_245 ) ;
V_382 -> V_107 = V_381 -> V_33 & 0x1 ;
if ( ! V_382 -> V_107 ) {
V_382 -> V_100 = F_343 ( ( void * ) ( V_381 + 1 ) ,
( void * ) V_381 + V_381 -> V_372 . V_245 ,
& V_382 -> V_357 ) ;
if ( V_382 -> V_357 && V_382 -> V_100 == NULL ) {
F_170 ( V_382 ) ;
return - V_134 ;
}
}
F_347 ( & V_382 -> V_377 , & V_386 ) ;
return 0 ;
}
static void F_348 ( struct V_379 * V_382 )
{
F_349 ( & V_382 -> V_100 , & V_382 -> V_357 ) ;
F_170 ( V_382 ) ;
}
int F_350 ( struct V_371 * V_376 , void * V_373 )
{
struct V_380 * V_381 ;
struct V_379 * V_382 ;
V_381 = F_46 ( V_376 , struct V_380 , V_372 ) ;
V_382 = F_344 ( V_381 ) ;
if ( V_382 ) {
F_351 ( & V_382 -> V_377 ) ;
F_352 () ;
F_348 ( V_382 ) ;
}
return 0 ;
}
int F_353 ( struct V_371 * V_376 , void * V_373 )
{
int V_76 ;
struct V_91 * V_92 ;
struct V_380 * V_381 ;
struct V_379 * V_382 ;
V_381 = F_46 ( V_376 , struct V_380 , V_372 ) ;
V_382 = F_344 ( V_381 ) ;
if ( ! V_382 )
return 0 ;
if ( ! V_382 -> V_107 && V_382 -> V_100 && V_382 -> V_357 )
F_100 (atsru->devices, atsru->devices_cnt,
i, dev)
return - V_275 ;
return 0 ;
}
static int F_354 ( struct V_73 * V_387 )
{
int V_388 , V_80 = 0 ;
struct V_31 * V_32 = V_387 -> V_32 ;
if ( V_72 [ V_32 -> V_177 ] )
return 0 ;
if ( V_216 && ! F_278 ( V_32 -> V_78 ) ) {
F_233 ( L_69 ,
V_32 -> V_133 ) ;
return - V_389 ;
}
if ( ! F_83 ( V_32 -> V_78 ) &&
F_82 ( V_32 ) ) {
F_233 ( L_70 ,
V_32 -> V_133 ) ;
return - V_389 ;
}
V_388 = F_84 ( V_32 ) - 1 ;
if ( V_388 >= 0 && ! ( F_85 ( V_32 -> V_68 ) & ( 1 << V_388 ) ) ) {
F_233 ( L_71 ,
V_32 -> V_133 ) ;
return - V_389 ;
}
if ( V_32 -> V_141 & V_184 )
F_164 ( V_32 ) ;
V_72 [ V_32 -> V_177 ] = V_32 ;
V_80 = F_165 ( V_32 ) ;
if ( V_80 == 0 )
V_80 = F_121 ( V_32 ) ;
if ( V_80 )
goto V_101;
if ( V_387 -> V_317 ) {
if ( V_318 )
F_162 ( V_32 ) ;
return 0 ;
}
F_264 ( V_32 ) ;
F_129 ( V_32 ) ;
V_80 = F_282 ( V_32 ) ;
if ( V_80 )
goto V_390;
F_123 ( V_32 ) ;
V_32 -> V_178 . V_221 ( V_32 , 0 , 0 , 0 , V_150 ) ;
V_32 -> V_178 . V_179 ( V_32 , 0 , 0 , 0 , V_159 ) ;
F_163 ( V_32 ) ;
F_162 ( V_32 ) ;
return 0 ;
V_390:
F_172 ( V_32 ) ;
V_101:
F_176 ( V_32 ) ;
return V_80 ;
}
int F_355 ( struct V_73 * V_387 , bool V_391 )
{
int V_80 = 0 ;
struct V_31 * V_32 = V_387 -> V_32 ;
if ( ! V_385 )
return 0 ;
if ( V_32 == NULL )
return - V_44 ;
if ( V_391 ) {
V_80 = F_354 ( V_387 ) ;
} else {
F_172 ( V_32 ) ;
F_176 ( V_32 ) ;
}
return V_80 ;
}
static void F_356 ( void )
{
struct V_266 * V_375 , * V_392 ;
struct V_379 * V_382 , * V_393 ;
F_173 (rmrru, rmrr_n, &dmar_rmrr_units, list) {
F_222 ( & V_375 -> V_377 ) ;
F_349 ( & V_375 -> V_100 , & V_375 -> V_357 ) ;
F_170 ( V_375 ) ;
}
F_173 (atsru, atsr_n, &dmar_atsr_units, list) {
F_222 ( & V_382 -> V_377 ) ;
F_348 ( V_382 ) ;
}
}
int F_148 ( struct V_96 * V_92 )
{
int V_76 , V_80 = 1 ;
struct V_394 * V_84 ;
struct V_96 * V_395 = NULL ;
struct V_91 * V_95 ;
struct V_380 * V_381 ;
struct V_379 * V_382 ;
V_92 = F_357 ( V_92 ) ;
for ( V_84 = V_92 -> V_84 ; V_84 ; V_84 = V_84 -> V_112 ) {
V_395 = V_84 -> V_396 ;
if ( ! V_395 || ! F_255 ( V_395 ) ||
F_257 ( V_395 ) == V_282 )
return 0 ;
if ( F_257 ( V_395 ) == V_397 )
break;
}
if ( ! V_395 )
return 0 ;
F_79 () ;
F_345 (atsru, &dmar_atsr_units, list) {
V_381 = F_46 ( V_382 -> V_376 , struct V_380 , V_372 ) ;
if ( V_381 -> V_99 != F_97 ( V_92 -> V_84 ) )
continue;
F_358 (atsru->devices, atsru->devices_cnt, i, tmp)
if ( V_95 == & V_395 -> V_92 )
goto V_101;
if ( V_382 -> V_107 )
goto V_101;
}
V_80 = 0 ;
V_101:
F_81 () ;
return V_80 ;
}
int F_359 ( struct V_398 * V_165 )
{
int V_80 = 0 ;
struct V_266 * V_375 ;
struct V_379 * V_382 ;
struct V_380 * V_381 ;
struct V_374 * V_267 ;
if ( ! V_385 && V_383 != V_384 )
return 0 ;
F_146 (rmrru, &dmar_rmrr_units, list) {
V_267 = F_46 ( V_375 -> V_376 ,
struct V_374 , V_372 ) ;
if ( V_165 -> V_399 == V_400 ) {
V_80 = F_360 ( V_165 , ( void * ) ( V_267 + 1 ) ,
( ( void * ) V_267 ) + V_267 -> V_372 . V_245 ,
V_267 -> V_99 , V_375 -> V_100 ,
V_375 -> V_357 ) ;
if( V_80 < 0 )
return V_80 ;
} else if ( V_165 -> V_399 == V_401 ) {
F_361 ( V_165 , V_267 -> V_99 ,
V_375 -> V_100 , V_375 -> V_357 ) ;
}
}
F_146 (atsru, &dmar_atsr_units, list) {
if ( V_382 -> V_107 )
continue;
V_381 = F_46 ( V_382 -> V_376 , struct V_380 , V_372 ) ;
if ( V_165 -> V_399 == V_400 ) {
V_80 = F_360 ( V_165 , ( void * ) ( V_381 + 1 ) ,
( void * ) V_381 + V_381 -> V_372 . V_245 ,
V_381 -> V_99 , V_382 -> V_100 ,
V_382 -> V_357 ) ;
if ( V_80 > 0 )
break;
else if( V_80 < 0 )
return V_80 ;
} else if ( V_165 -> V_399 == V_401 ) {
if ( F_361 ( V_165 , V_381 -> V_99 ,
V_382 -> V_100 , V_382 -> V_357 ) )
break;
}
}
return 0 ;
}
static int F_362 ( struct V_402 * V_403 ,
unsigned long V_404 , void * V_226 )
{
struct V_91 * V_92 = V_226 ;
struct V_39 * V_42 ;
if ( F_93 ( V_92 ) )
return 0 ;
if ( V_404 != V_405 )
return 0 ;
V_42 = F_224 ( V_92 ) ;
if ( ! V_42 )
return 0 ;
F_174 ( V_42 , V_92 ) ;
if ( ! F_67 ( V_42 ) && F_363 ( & V_42 -> V_100 ) )
F_175 ( V_42 ) ;
return 0 ;
}
static int F_364 ( struct V_402 * V_403 ,
unsigned long V_29 , void * V_406 )
{
struct V_407 * V_408 = V_406 ;
unsigned long long V_209 , V_105 ;
unsigned long V_349 , V_260 ;
switch ( V_29 ) {
case V_409 :
V_209 = V_408 -> V_123 << V_11 ;
V_105 = ( ( V_408 -> V_123 + V_408 -> V_238 ) << V_11 ) - 1 ;
if ( F_231 ( V_261 , V_209 , V_105 ) ) {
F_233 ( L_72 ,
V_209 , V_105 ) ;
return V_410 ;
}
break;
case V_411 :
case V_412 :
V_349 = F_13 ( V_408 -> V_123 ) ;
V_260 = F_13 ( V_408 -> V_123 + V_408 -> V_238 - 1 ) ;
while ( V_349 <= V_260 ) {
struct V_196 * V_196 ;
struct V_73 * V_74 ;
struct V_31 * V_32 ;
struct V_14 * V_130 ;
V_196 = F_302 ( & V_261 -> V_210 , V_349 ) ;
if ( V_196 == NULL ) {
F_142 ( L_73 ,
V_349 ) ;
break;
}
V_196 = F_365 ( & V_261 -> V_210 , V_196 ,
V_349 , V_260 ) ;
if ( V_196 == NULL ) {
F_233 ( L_74 ,
V_349 , V_260 ) ;
return V_410 ;
}
V_130 = F_119 ( V_261 , V_196 -> V_328 ,
V_196 -> V_340 ) ;
F_79 () ;
F_80 (iommu, drhd)
F_156 ( V_32 , V_261 ,
V_196 -> V_328 , F_297 ( V_196 ) ,
! V_130 , 0 ) ;
F_81 () ;
F_120 ( V_130 ) ;
V_349 = V_196 -> V_340 + 1 ;
F_366 ( V_196 ) ;
}
break;
}
return V_413 ;
}
static T_10 F_367 ( struct V_91 * V_92 ,
struct V_414 * V_415 ,
char * V_416 )
{
struct V_31 * V_32 = F_368 ( V_92 ) ;
T_2 V_417 = F_44 ( V_32 -> V_36 + V_418 ) ;
return sprintf ( V_416 , L_75 ,
F_369 ( V_417 ) , F_370 ( V_417 ) ) ;
}
static T_10 F_371 ( struct V_91 * V_92 ,
struct V_414 * V_415 ,
char * V_416 )
{
struct V_31 * V_32 = F_368 ( V_92 ) ;
return sprintf ( V_416 , L_76 , V_32 -> V_419 ) ;
}
static T_10 F_372 ( struct V_91 * V_92 ,
struct V_414 * V_415 ,
char * V_416 )
{
struct V_31 * V_32 = F_368 ( V_92 ) ;
return sprintf ( V_416 , L_76 , V_32 -> V_68 ) ;
}
static T_10 F_373 ( struct V_91 * V_92 ,
struct V_414 * V_415 ,
char * V_416 )
{
struct V_31 * V_32 = F_368 ( V_92 ) ;
return sprintf ( V_416 , L_76 , V_32 -> V_78 ) ;
}
static T_10 F_374 ( struct V_91 * V_92 ,
struct V_414 * V_415 ,
char * V_416 )
{
struct V_31 * V_32 = F_368 ( V_92 ) ;
return sprintf ( V_416 , L_77 , F_166 ( V_32 -> V_68 ) ) ;
}
static T_10 F_375 ( struct V_91 * V_92 ,
struct V_414 * V_415 ,
char * V_416 )
{
struct V_31 * V_32 = F_368 ( V_92 ) ;
return sprintf ( V_416 , L_78 , F_376 ( V_32 -> V_187 ,
F_166 ( V_32 -> V_68 ) ) ) ;
}
int T_3 F_377 ( void )
{
int V_80 = - V_204 ;
struct V_73 * V_74 ;
struct V_31 * V_32 ;
V_318 = F_378 () ;
if ( F_321 () ) {
if ( V_318 )
F_339 ( L_79 ) ;
return - V_134 ;
}
F_379 ( & V_420 ) ;
if ( F_380 () ) {
if ( V_318 )
F_339 ( L_80 ) ;
goto V_421;
}
if ( F_381 () < 0 ) {
if ( V_318 )
F_339 ( L_81 ) ;
goto V_421;
}
if ( V_422 || V_45 )
goto V_421;
if ( F_363 ( & V_378 ) )
F_48 ( L_82 ) ;
if ( F_363 ( & V_386 ) )
F_48 ( L_83 ) ;
if ( F_183 () ) {
if ( V_318 )
F_339 ( L_84 ) ;
goto V_423;
}
F_332 () ;
V_80 = F_274 () ;
if ( V_80 ) {
if ( V_318 )
F_339 ( L_85 ) ;
F_122 ( L_86 ) ;
goto V_423;
}
F_382 ( & V_420 ) ;
F_48 ( L_87 ) ;
F_383 ( & V_337 ) ;
#ifdef F_384
V_424 = 0 ;
#endif
V_425 = & V_426 ;
F_340 () ;
F_80 (iommu, drhd)
V_32 -> V_427 = F_385 ( NULL , V_32 ,
V_428 ,
L_88 , V_32 -> V_133 ) ;
F_386 ( & V_429 , & V_430 ) ;
F_387 ( & V_429 , & V_431 ) ;
if ( V_261 && ! V_216 )
F_388 ( & V_432 ) ;
V_385 = 1 ;
return 0 ;
V_423:
F_197 ( & V_197 ) ;
V_421:
F_356 () ;
F_382 ( & V_420 ) ;
F_325 () ;
return V_80 ;
}
static int F_389 ( struct V_96 * V_98 , T_4 V_223 , void * V_224 )
{
struct V_31 * V_32 = V_224 ;
F_220 ( V_32 , F_204 ( V_223 ) , V_223 & 0xff ) ;
return 0 ;
}
static void F_390 ( struct V_31 * V_32 , struct V_91 * V_92 )
{
if ( ! V_32 || ! V_92 || ! F_95 ( V_92 ) )
return;
F_206 ( F_96 ( V_92 ) , & F_389 , V_32 ) ;
}
static void F_223 ( struct V_164 * V_165 )
{
struct V_31 * V_32 ;
unsigned long V_33 ;
F_144 ( & V_166 ) ;
if ( F_53 ( ! V_165 ) )
return;
V_32 = V_165 -> V_32 ;
if ( V_165 -> V_92 ) {
F_152 ( V_165 ) ;
F_390 ( V_32 , V_165 -> V_92 ) ;
}
F_221 ( V_165 ) ;
F_104 ( & V_32 -> V_109 , V_33 ) ;
F_181 ( V_165 -> V_42 , V_32 ) ;
F_105 ( & V_32 -> V_109 , V_33 ) ;
F_64 ( V_165 ) ;
}
static void F_174 ( struct V_39 * V_42 ,
struct V_91 * V_92 )
{
struct V_164 * V_165 ;
unsigned long V_33 ;
F_104 ( & V_166 , V_33 ) ;
V_165 = V_92 -> V_93 . V_32 ;
F_223 ( V_165 ) ;
F_105 ( & V_166 , V_33 ) ;
}
static int F_241 ( struct V_39 * V_42 , int V_211 )
{
int V_212 ;
F_184 ( & V_42 -> V_210 , V_118 , V_198 ,
V_199 ) ;
F_189 ( V_42 ) ;
V_42 -> V_129 = V_211 ;
V_212 = F_191 ( V_211 ) ;
V_42 -> V_1 = F_4 ( V_212 ) ;
V_42 -> V_77 = 0 ;
V_42 -> V_82 = 0 ;
V_42 -> V_83 = 0 ;
V_42 -> V_433 = 0 ;
V_42 -> V_114 = (struct V_27 * ) F_54 ( V_42 -> V_117 ) ;
if ( ! V_42 -> V_114 )
return - V_134 ;
F_101 ( V_42 , V_42 -> V_114 , V_213 ) ;
return 0 ;
}
static struct V_40 * F_391 ( unsigned type )
{
struct V_39 * V_39 ;
struct V_40 * V_42 ;
if ( type != V_434 )
return NULL ;
V_39 = F_177 ( V_62 ) ;
if ( ! V_39 ) {
F_122 ( L_89 ) ;
return NULL ;
}
if ( F_241 ( V_39 , V_69 ) ) {
F_122 ( L_90 ) ;
F_175 ( V_39 ) ;
return NULL ;
}
F_87 ( V_39 ) ;
V_42 = & V_39 -> V_42 ;
V_42 -> V_435 . V_436 = 0 ;
V_42 -> V_435 . V_437 = F_392 ( V_39 -> V_129 ) ;
V_42 -> V_435 . V_438 = true ;
return V_42 ;
}
static void F_393 ( struct V_40 * V_42 )
{
F_175 ( F_45 ( V_42 ) ) ;
}
static int F_394 ( struct V_40 * V_42 ,
struct V_91 * V_92 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_31 * V_32 ;
int V_64 ;
T_6 V_84 , V_85 ;
if ( F_250 ( V_92 ) ) {
F_395 ( V_92 , L_91 ) ;
return - V_439 ;
}
if ( F_287 ( F_208 ( V_92 ) ) ) {
struct V_39 * V_440 ;
V_440 = F_224 ( V_92 ) ;
if ( V_440 ) {
F_79 () ;
F_174 ( V_440 , V_92 ) ;
F_81 () ;
if ( ! F_67 ( V_440 ) &&
F_363 ( & V_440 -> V_100 ) )
F_175 ( V_440 ) ;
}
}
V_32 = F_94 ( V_92 , & V_84 , & V_85 ) ;
if ( ! V_32 )
return - V_204 ;
V_64 = F_2 ( V_32 -> V_1 ) ;
if ( V_64 > F_193 ( V_32 -> V_68 ) )
V_64 = F_193 ( V_32 -> V_68 ) ;
if ( V_39 -> V_433 > ( 1LL << V_64 ) ) {
F_122 ( L_92
L_93 ,
V_441 , V_64 , V_39 -> V_433 ) ;
return - V_272 ;
}
V_39 -> V_129 = V_64 ;
while ( V_32 -> V_1 < V_39 -> V_1 ) {
struct V_27 * V_28 ;
V_28 = V_39 -> V_114 ;
if ( F_38 ( V_28 ) ) {
V_39 -> V_114 = (struct V_27 * )
F_90 ( F_35 ( V_28 ) ) ;
F_57 ( V_28 ) ;
}
V_39 -> V_1 -- ;
}
return F_247 ( V_39 , V_92 ) ;
}
static void F_396 ( struct V_40 * V_42 ,
struct V_91 * V_92 )
{
F_174 ( F_45 ( V_42 ) , V_92 ) ;
}
static int F_397 ( struct V_40 * V_42 ,
unsigned long V_196 , T_1 V_442 ,
T_5 V_55 , int V_443 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
V_24 V_433 ;
int V_239 = 0 ;
int V_80 ;
if ( V_443 & V_444 )
V_239 |= V_119 ;
if ( V_443 & V_445 )
V_239 |= V_120 ;
if ( ( V_443 & V_446 ) && V_39 -> V_82 )
V_239 |= V_244 ;
V_433 = V_196 + V_55 ;
if ( V_39 -> V_433 < V_433 ) {
V_24 V_105 ;
V_105 = F_392 ( V_39 -> V_129 ) + 1 ;
if ( V_105 < V_433 ) {
F_122 ( L_92
L_93 ,
V_441 , V_39 -> V_129 , V_433 ) ;
return - V_272 ;
}
V_39 -> V_433 = V_433 ;
}
V_55 = F_209 ( V_442 , V_55 ) ;
V_80 = F_219 ( V_39 , V_196 >> V_12 ,
V_442 >> V_12 , V_55 , V_239 ) ;
return V_80 ;
}
static T_5 F_398 ( struct V_40 * V_42 ,
unsigned long V_196 , T_5 V_55 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_14 * V_130 = NULL ;
struct V_31 * V_32 ;
unsigned long V_123 , V_124 ;
unsigned int V_447 ;
int V_70 , V_5 = 0 ;
F_75 ( ! F_108 ( V_39 , V_196 >> V_12 , & V_5 ) ) ;
if ( V_55 < V_118 << F_6 ( V_5 ) )
V_55 = V_118 << F_6 ( V_5 ) ;
V_123 = V_196 >> V_12 ;
V_124 = ( V_196 + V_55 - 1 ) >> V_12 ;
V_130 = F_119 ( V_39 , V_123 , V_124 ) ;
V_447 = V_124 - V_123 + 1 ;
F_76 (iommu_id, dmar_domain) {
V_32 = V_72 [ V_70 ] ;
F_156 ( V_72 [ V_70 ] , V_39 ,
V_123 , V_447 , ! V_130 , 0 ) ;
}
F_120 ( V_130 ) ;
if ( V_39 -> V_433 == V_196 + V_55 )
V_39 -> V_433 = V_196 ;
return V_55 ;
}
static T_1 F_399 ( struct V_40 * V_42 ,
V_247 V_196 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_27 * V_28 ;
int V_5 = 0 ;
V_24 V_448 = 0 ;
V_28 = F_108 ( V_39 , V_196 >> V_12 , & V_5 ) ;
if ( V_28 )
V_448 = F_35 ( V_28 ) ;
return V_448 ;
}
static bool F_400 ( enum V_449 V_68 )
{
if ( V_68 == V_450 )
return F_82 ( NULL ) == 1 ;
if ( V_68 == V_451 )
return V_452 == 1 ;
return false ;
}
static int F_401 ( struct V_91 * V_92 )
{
struct V_31 * V_32 ;
struct V_453 * V_454 ;
T_6 V_84 , V_85 ;
V_32 = F_94 ( V_92 , & V_84 , & V_85 ) ;
if ( ! V_32 )
return - V_204 ;
F_402 ( V_32 -> V_427 , V_92 ) ;
V_454 = F_403 ( V_92 ) ;
if ( F_404 ( V_454 ) )
return F_405 ( V_454 ) ;
F_406 ( V_454 ) ;
return 0 ;
}
static void F_407 ( struct V_91 * V_92 )
{
struct V_31 * V_32 ;
T_6 V_84 , V_85 ;
V_32 = F_94 ( V_92 , & V_84 , & V_85 ) ;
if ( ! V_32 )
return;
F_408 ( V_92 ) ;
F_409 ( V_32 -> V_427 , V_92 ) ;
}
static void F_410 ( struct V_96 * V_92 )
{
F_48 ( L_94 ) ;
V_46 = 0 ;
}
static void F_411 ( struct V_96 * V_92 )
{
F_48 ( L_95 ) ;
V_145 = 1 ;
}
static void F_412 ( struct V_96 * V_92 )
{
unsigned short V_455 ;
if ( F_413 ( V_92 , V_456 , & V_455 ) )
return;
if ( ! ( V_455 & V_457 ) ) {
F_48 ( L_96 ) ;
V_46 = 0 ;
} else if ( V_46 ) {
F_48 ( L_97 ) ;
V_48 = 1 ;
}
}
static void T_3 F_280 ( void )
{
struct V_96 * V_98 ;
T_11 V_458 ;
V_98 = F_414 ( V_459 , 0x3a3e , NULL ) ;
if ( ! V_98 )
return;
F_239 ( V_98 ) ;
V_98 = F_414 ( V_459 , 0x342e , NULL ) ;
if ( ! V_98 )
return;
if ( F_415 ( V_98 , 0x188 , & V_458 ) ) {
F_239 ( V_98 ) ;
return;
}
F_239 ( V_98 ) ;
if ( V_458 & 1 )
return;
V_458 &= 0x1c ;
if ( V_458 == 0x10 )
return;
if ( ! V_458 ) {
F_234 ( 1 , L_98
L_34 ,
F_235 ( V_262 ) ,
F_235 ( V_263 ) ,
F_235 ( V_264 ) ) ;
V_273 |= V_277 ;
return;
}
F_233 ( L_99 ,
V_458 ) ;
}
