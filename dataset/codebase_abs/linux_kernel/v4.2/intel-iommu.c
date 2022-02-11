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
static inline void * F_50 ( int V_52 )
{
struct V_14 * V_14 ;
void * V_53 = NULL ;
V_14 = F_51 ( V_52 , V_54 | V_55 , 0 ) ;
if ( V_14 )
V_53 = F_52 ( V_14 ) ;
return V_53 ;
}
static inline void F_53 ( void * V_53 )
{
F_54 ( ( unsigned long ) V_53 ) ;
}
static inline void * F_55 ( void )
{
return F_56 ( V_56 , V_54 ) ;
}
static void F_57 ( void * V_53 )
{
F_58 ( V_56 , V_53 ) ;
}
static inline void * F_59 ( void )
{
return F_56 ( V_57 , V_54 ) ;
}
static inline void F_60 ( void * V_53 )
{
F_58 ( V_57 , V_53 ) ;
}
static inline int F_61 ( struct V_39 * V_42 )
{
return V_42 -> V_33 & V_58 ;
}
static inline int F_62 ( struct V_39 * V_42 )
{
return V_42 -> V_33 & ( V_58 |
V_59 ) ;
}
static inline int F_63 ( struct V_39 * V_42 ,
unsigned long V_6 )
{
int V_60 = F_2 ( V_42 -> V_1 ) - V_12 ;
return ! ( V_60 < V_61 && V_6 > > V_60 ) ;
}
static int F_64 ( struct V_31 * V_32 , int V_62 )
{
unsigned long V_63 ;
int V_1 = - 1 ;
V_63 = F_65 ( V_32 -> V_64 ) ;
for ( V_1 = F_4 ( V_62 ) ;
V_1 >= 0 ; V_1 -- ) {
if ( F_66 ( V_1 , & V_63 ) )
break;
}
return V_1 ;
}
int F_67 ( struct V_31 * V_32 )
{
return F_64 ( V_32 , V_3 ) ;
}
int F_68 ( struct V_31 * V_32 )
{
return F_64 ( V_32 , V_65 ) ;
}
static struct V_31 * F_69 ( struct V_39 * V_42 )
{
int V_66 ;
F_70 ( F_62 ( V_42 ) ) ;
V_66 = F_71 ( V_42 -> V_67 , V_68 ) ;
if ( V_66 < 0 || V_66 >= V_68 )
return NULL ;
return V_69 [ V_66 ] ;
}
static void F_72 ( struct V_39 * V_42 )
{
struct V_70 * V_71 ;
struct V_31 * V_32 ;
bool V_72 = false ;
int V_73 ;
V_42 -> V_74 = 1 ;
F_73 (i, domain->iommu_bmp, g_num_of_iommus) {
V_72 = true ;
if ( ! F_74 ( V_69 [ V_73 ] -> V_75 ) ) {
V_42 -> V_74 = 0 ;
break;
}
}
if ( V_72 )
return;
F_75 () ;
F_76 (iommu, drhd) {
if ( ! F_74 ( V_32 -> V_75 ) ) {
V_42 -> V_74 = 0 ;
break;
}
}
F_77 () ;
}
static int F_78 ( struct V_31 * V_76 )
{
struct V_70 * V_71 ;
struct V_31 * V_32 ;
int V_77 = 1 ;
F_75 () ;
F_76 (iommu, drhd) {
if ( V_32 != V_76 ) {
if ( ! F_79 ( V_32 -> V_75 ) ) {
V_77 = 0 ;
break;
}
}
}
F_77 () ;
return V_77 ;
}
static int F_80 ( struct V_31 * V_76 )
{
struct V_70 * V_71 ;
struct V_31 * V_32 ;
int V_78 = 0xf ;
if ( ! V_49 ) {
return 0 ;
}
F_75 () ;
F_76 (iommu, drhd) {
if ( V_32 != V_76 ) {
V_78 &= F_81 ( V_32 -> V_64 ) ;
if ( ! V_78 )
break;
}
}
F_77 () ;
return F_82 ( V_78 ) ;
}
static void F_83 ( struct V_39 * V_42 )
{
F_72 ( V_42 ) ;
V_42 -> V_79 = F_78 ( NULL ) ;
V_42 -> V_80 = F_80 ( NULL ) ;
}
static inline struct V_22 * F_84 ( struct V_31 * V_32 ,
T_4 V_81 , T_4 V_82 , int V_83 )
{
struct V_17 * V_84 = & V_32 -> V_17 [ V_81 ] ;
struct V_22 * V_23 ;
V_24 * V_85 ;
if ( F_85 ( V_32 ) ) {
if ( V_82 >= 0x80 ) {
V_82 -= 0x80 ;
V_85 = & V_84 -> V_21 ;
}
V_82 *= 2 ;
}
V_85 = & V_84 -> V_19 ;
if ( * V_85 & 1 )
V_23 = F_86 ( * V_85 & V_20 ) ;
else {
unsigned long V_86 ;
if ( ! V_83 )
return NULL ;
V_23 = F_50 ( V_32 -> V_52 ) ;
if ( ! V_23 )
return NULL ;
F_87 ( V_32 , ( void * ) V_23 , V_87 ) ;
V_86 = F_88 ( ( void * ) V_23 ) ;
* V_85 = V_86 | 1 ;
F_87 ( V_32 , V_85 , sizeof( * V_85 ) ) ;
}
return & V_23 [ V_82 ] ;
}
static int F_89 ( struct V_88 * V_89 )
{
return V_89 -> V_90 . V_32 == V_91 ;
}
static struct V_31 * F_90 ( struct V_88 * V_89 , T_4 * V_81 , T_4 * V_82 )
{
struct V_70 * V_71 = NULL ;
struct V_31 * V_32 ;
struct V_88 * V_92 ;
struct V_93 * V_94 , * V_95 = NULL ;
T_5 V_96 = 0 ;
int V_73 ;
if ( F_89 ( V_89 ) )
return NULL ;
if ( F_91 ( V_89 ) ) {
V_95 = F_92 ( V_89 ) ;
V_96 = F_93 ( V_95 -> V_81 ) ;
} else if ( F_94 ( V_89 ) )
V_89 = & F_95 ( V_89 ) -> V_89 ;
F_75 () ;
F_76 (iommu, drhd) {
if ( V_95 && V_96 != V_71 -> V_96 )
continue;
F_96 (drhd->devices,
drhd->devices_cnt, i, tmp) {
if ( V_92 == V_89 ) {
* V_81 = V_71 -> V_97 [ V_73 ] . V_81 ;
* V_82 = V_71 -> V_97 [ V_73 ] . V_82 ;
goto V_98;
}
if ( ! V_95 || ! F_91 ( V_92 ) )
continue;
V_94 = F_92 ( V_92 ) ;
if ( V_94 -> V_99 &&
V_94 -> V_99 -> V_100 <= V_95 -> V_81 -> V_100 &&
V_94 -> V_99 -> V_101 . V_102 >= V_95 -> V_81 -> V_100 )
goto V_103;
}
if ( V_95 && V_71 -> V_104 ) {
V_103:
* V_81 = V_95 -> V_81 -> V_100 ;
* V_82 = V_95 -> V_82 ;
goto V_98;
}
}
V_32 = NULL ;
V_98:
F_77 () ;
return V_32 ;
}
static void F_97 ( struct V_39 * V_42 ,
void * V_105 , int V_106 )
{
if ( ! V_42 -> V_74 )
F_98 ( V_105 , V_106 ) ;
}
static int F_99 ( struct V_31 * V_32 , T_4 V_81 , T_4 V_82 )
{
struct V_22 * V_23 ;
int V_77 = 0 ;
unsigned long V_33 ;
F_100 ( & V_32 -> V_107 , V_33 ) ;
V_23 = F_84 ( V_32 , V_81 , V_82 , 0 ) ;
if ( V_23 )
V_77 = F_25 ( V_23 ) ;
F_101 ( & V_32 -> V_107 , V_33 ) ;
return V_77 ;
}
static void F_102 ( struct V_31 * V_32 , T_4 V_81 , T_4 V_82 )
{
struct V_22 * V_23 ;
unsigned long V_33 ;
F_100 ( & V_32 -> V_107 , V_33 ) ;
V_23 = F_84 ( V_32 , V_81 , V_82 , 0 ) ;
if ( V_23 ) {
F_33 ( V_23 ) ;
F_87 ( V_32 , V_23 , sizeof( * V_23 ) ) ;
}
F_101 ( & V_32 -> V_107 , V_33 ) ;
}
static void F_103 ( struct V_31 * V_32 )
{
int V_73 ;
unsigned long V_33 ;
struct V_22 * V_23 ;
F_100 ( & V_32 -> V_107 , V_33 ) ;
if ( ! V_32 -> V_17 ) {
goto V_98;
}
for ( V_73 = 0 ; V_73 < V_108 ; V_73 ++ ) {
V_23 = F_84 ( V_32 , V_73 , 0 , 0 ) ;
if ( V_23 )
F_53 ( V_23 ) ;
if ( ! F_85 ( V_32 ) )
continue;
V_23 = F_84 ( V_32 , V_73 , 0x80 , 0 ) ;
if ( V_23 )
F_53 ( V_23 ) ;
}
F_53 ( V_32 -> V_17 ) ;
V_32 -> V_17 = NULL ;
V_98:
F_101 ( & V_32 -> V_107 , V_33 ) ;
}
static struct V_27 * F_104 ( struct V_39 * V_42 ,
unsigned long V_6 , int * V_109 )
{
struct V_27 * V_110 , * V_28 = NULL ;
int V_5 = F_1 ( V_42 -> V_1 ) ;
int V_111 ;
F_70 ( ! V_42 -> V_112 ) ;
if ( ! F_63 ( V_42 , V_6 ) )
return NULL ;
V_110 = V_42 -> V_112 ;
while ( 1 ) {
void * V_113 ;
V_111 = F_7 ( V_6 , V_5 ) ;
V_28 = & V_110 [ V_111 ] ;
if ( ! * V_109 && ( F_39 ( V_28 ) || ! F_38 ( V_28 ) ) )
break;
if ( V_5 == * V_109 )
break;
if ( ! F_38 ( V_28 ) ) {
T_6 V_114 ;
V_113 = F_50 ( V_42 -> V_115 ) ;
if ( ! V_113 )
return NULL ;
F_97 ( V_42 , V_113 , V_116 ) ;
V_114 = ( ( T_6 ) F_16 ( V_113 ) << V_12 ) | V_117 | V_118 ;
if ( F_105 ( & V_28 -> V_29 , 0ULL , V_114 ) )
F_53 ( V_113 ) ;
else
F_97 ( V_42 , V_28 , sizeof( * V_28 ) ) ;
}
if ( V_5 == 1 )
break;
V_110 = F_86 ( F_35 ( V_28 ) ) ;
V_5 -- ;
}
if ( ! * V_109 )
* V_109 = V_5 ;
return V_28 ;
}
static struct V_27 * F_106 ( struct V_39 * V_42 ,
unsigned long V_6 ,
int V_5 , int * V_119 )
{
struct V_27 * V_110 , * V_28 = NULL ;
int V_120 = F_1 ( V_42 -> V_1 ) ;
int V_111 ;
V_110 = V_42 -> V_112 ;
while ( V_5 <= V_120 ) {
V_111 = F_7 ( V_6 , V_120 ) ;
V_28 = & V_110 [ V_111 ] ;
if ( V_5 == V_120 )
return V_28 ;
if ( ! F_38 ( V_28 ) ) {
* V_119 = V_120 ;
break;
}
if ( F_39 ( V_28 ) ) {
* V_119 = V_120 ;
return V_28 ;
}
V_110 = F_86 ( F_35 ( V_28 ) ) ;
V_120 -- ;
}
return NULL ;
}
static void F_107 ( struct V_39 * V_42 ,
unsigned long V_121 ,
unsigned long V_122 )
{
unsigned int V_119 = 1 ;
struct V_27 * V_123 , * V_28 ;
F_70 ( ! F_63 ( V_42 , V_121 ) ) ;
F_70 ( ! F_63 ( V_42 , V_122 ) ) ;
F_70 ( V_121 > V_122 ) ;
do {
V_119 = 1 ;
V_123 = V_28 = F_106 ( V_42 , V_121 , 1 , & V_119 ) ;
if ( ! V_28 ) {
V_121 = F_10 ( V_121 + 1 , V_119 + 1 ) ;
continue;
}
do {
F_34 ( V_28 ) ;
V_121 += F_11 ( V_119 ) ;
V_28 ++ ;
} while ( V_121 <= V_122 && ! F_40 ( V_28 ) );
F_97 ( V_42 , V_123 ,
( void * ) V_28 - ( void * ) V_123 ) ;
} while ( V_121 && V_121 <= V_122 );
}
static void F_108 ( struct V_39 * V_42 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_121 , unsigned long V_122 )
{
V_6 = F_109 ( V_121 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_124 ;
struct V_27 * V_125 ;
if ( ! F_38 ( V_28 ) || F_39 ( V_28 ) )
goto V_126;
V_124 = V_6 & F_8 ( V_5 - 1 ) ;
V_125 = F_86 ( F_35 ( V_28 ) ) ;
if ( V_5 > 2 )
F_108 ( V_42 , V_5 - 1 , V_125 ,
V_124 , V_121 , V_122 ) ;
if ( ! ( V_121 > V_124 ||
V_122 < V_124 + F_9 ( V_5 ) - 1 ) ) {
F_34 ( V_28 ) ;
F_97 ( V_42 , V_28 , sizeof( * V_28 ) ) ;
F_53 ( V_125 ) ;
}
V_126:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_40 ( ++ V_28 ) && V_6 <= V_122 );
}
static void F_110 ( struct V_39 * V_42 ,
unsigned long V_121 ,
unsigned long V_122 )
{
F_70 ( ! F_63 ( V_42 , V_121 ) ) ;
F_70 ( ! F_63 ( V_42 , V_122 ) ) ;
F_70 ( V_121 > V_122 ) ;
F_107 ( V_42 , V_121 , V_122 ) ;
F_108 ( V_42 , F_1 ( V_42 -> V_1 ) ,
V_42 -> V_112 , 0 , V_121 , V_122 ) ;
if ( V_121 == 0 && V_122 == F_111 ( V_42 -> V_127 ) ) {
F_53 ( V_42 -> V_112 ) ;
V_42 -> V_112 = NULL ;
}
}
static struct V_14 * F_112 ( struct V_39 * V_42 ,
int V_5 , struct V_27 * V_28 ,
struct V_14 * V_128 )
{
struct V_14 * V_15 ;
V_15 = F_113 ( F_35 ( V_28 ) >> V_11 ) ;
V_15 -> V_128 = V_128 ;
V_128 = V_15 ;
if ( V_5 == 1 )
return V_128 ;
V_28 = F_52 ( V_15 ) ;
do {
if ( F_38 ( V_28 ) && ! F_39 ( V_28 ) )
V_128 = F_112 ( V_42 , V_5 - 1 ,
V_28 , V_128 ) ;
V_28 ++ ;
} while ( ! F_40 ( V_28 ) );
return V_128 ;
}
static struct V_14 * F_114 ( struct V_39 * V_42 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_121 ,
unsigned long V_122 ,
struct V_14 * V_128 )
{
struct V_27 * V_123 = NULL , * V_129 = NULL ;
V_6 = F_109 ( V_121 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_124 ;
if ( ! F_38 ( V_28 ) )
goto V_126;
V_124 = V_6 & F_8 ( V_5 ) ;
if ( V_121 <= V_124 &&
V_122 >= V_124 + F_9 ( V_5 ) - 1 ) {
if ( V_5 > 1 && ! F_39 ( V_28 ) )
V_128 = F_112 ( V_42 , V_5 - 1 , V_28 , V_128 ) ;
F_34 ( V_28 ) ;
if ( ! V_123 )
V_123 = V_28 ;
V_129 = V_28 ;
} else if ( V_5 > 1 ) {
V_128 = F_114 ( V_42 , V_5 - 1 ,
F_86 ( F_35 ( V_28 ) ) ,
V_124 , V_121 , V_122 ,
V_128 ) ;
}
V_126:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_40 ( ++ V_28 ) && V_6 <= V_122 );
if ( V_123 )
F_97 ( V_42 , V_123 ,
( void * ) ++ V_129 - ( void * ) V_123 ) ;
return V_128 ;
}
struct V_14 * F_115 ( struct V_39 * V_42 ,
unsigned long V_121 ,
unsigned long V_122 )
{
struct V_14 * V_128 = NULL ;
F_70 ( ! F_63 ( V_42 , V_121 ) ) ;
F_70 ( ! F_63 ( V_42 , V_122 ) ) ;
F_70 ( V_121 > V_122 ) ;
V_128 = F_114 ( V_42 , F_1 ( V_42 -> V_1 ) ,
V_42 -> V_112 , 0 , V_121 , V_122 , NULL ) ;
if ( V_121 == 0 && V_122 == F_111 ( V_42 -> V_127 ) ) {
struct V_14 * V_130 = F_17 ( V_42 -> V_112 ) ;
V_130 -> V_128 = V_128 ;
V_128 = V_130 ;
V_42 -> V_112 = NULL ;
}
return V_128 ;
}
void F_116 ( struct V_14 * V_128 )
{
struct V_14 * V_15 ;
while ( ( V_15 = V_128 ) ) {
V_128 = V_15 -> V_128 ;
F_53 ( F_52 ( V_15 ) ) ;
}
}
static int F_117 ( struct V_31 * V_32 )
{
struct V_17 * V_84 ;
unsigned long V_33 ;
V_84 = (struct V_17 * ) F_50 ( V_32 -> V_52 ) ;
if ( ! V_84 ) {
F_118 ( L_16 ,
V_32 -> V_131 ) ;
return - V_132 ;
}
F_87 ( V_32 , V_84 , V_133 ) ;
F_100 ( & V_32 -> V_107 , V_33 ) ;
V_32 -> V_17 = V_84 ;
F_101 ( & V_32 -> V_107 , V_33 ) ;
return 0 ;
}
static void F_119 ( struct V_31 * V_32 )
{
V_24 V_105 ;
T_2 V_134 ;
unsigned long V_135 ;
V_105 = F_88 ( V_32 -> V_17 ) ;
if ( F_85 ( V_32 ) )
V_105 |= V_136 ;
F_120 ( & V_32 -> V_137 , V_135 ) ;
F_121 ( V_32 -> V_36 + V_138 , V_105 ) ;
F_122 ( V_32 -> V_139 | V_140 , V_32 -> V_36 + V_141 ) ;
F_123 ( V_32 , V_37 ,
F_44 , ( V_134 & V_142 ) , V_134 ) ;
F_124 ( & V_32 -> V_137 , V_135 ) ;
}
static void F_125 ( struct V_31 * V_32 )
{
T_2 V_29 ;
unsigned long V_135 ;
if ( ! V_143 && ! F_126 ( V_32 -> V_64 ) )
return;
F_120 ( & V_32 -> V_137 , V_135 ) ;
F_122 ( V_32 -> V_139 | V_144 , V_32 -> V_36 + V_141 ) ;
F_123 ( V_32 , V_37 ,
F_44 , ( ! ( V_29 & V_145 ) ) , V_29 ) ;
F_124 ( & V_32 -> V_137 , V_135 ) ;
}
static void F_127 ( struct V_31 * V_32 ,
T_5 V_146 , T_5 V_147 , T_4 V_148 ,
V_24 type )
{
V_24 V_29 = 0 ;
unsigned long V_135 ;
switch ( type ) {
case V_149 :
V_29 = V_149 ;
break;
case V_150 :
V_29 = V_150 | F_128 ( V_146 ) ;
break;
case V_151 :
V_29 = V_151 | F_128 ( V_146 )
| F_129 ( V_147 ) | F_130 ( V_148 ) ;
break;
default:
F_131 () ;
}
V_29 |= V_152 ;
F_120 ( & V_32 -> V_137 , V_135 ) ;
F_121 ( V_32 -> V_36 + V_153 , V_29 ) ;
F_123 ( V_32 , V_153 ,
V_154 , ( ! ( V_29 & V_152 ) ) , V_29 ) ;
F_124 ( & V_32 -> V_137 , V_135 ) ;
}
static void F_132 ( struct V_31 * V_32 , T_5 V_146 ,
V_24 V_105 , unsigned int V_155 , V_24 type )
{
int V_156 = F_133 ( V_32 -> V_75 ) ;
V_24 V_29 = 0 , V_157 = 0 ;
unsigned long V_135 ;
switch ( type ) {
case V_158 :
V_29 = V_158 | V_159 ;
break;
case V_160 :
V_29 = V_160 | V_159 | F_134 ( V_146 ) ;
break;
case V_161 :
V_29 = V_161 | V_159 | F_134 ( V_146 ) ;
V_157 = V_155 | V_105 ;
break;
default:
F_131 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_135 ( V_32 -> V_64 ) )
V_29 |= V_162 ;
F_120 ( & V_32 -> V_137 , V_135 ) ;
if ( V_157 )
F_121 ( V_32 -> V_36 + V_156 , V_157 ) ;
F_121 ( V_32 -> V_36 + V_156 + 8 , V_29 ) ;
F_123 ( V_32 , V_156 + 8 ,
V_154 , ( ! ( V_29 & V_159 ) ) , V_29 ) ;
F_124 ( & V_32 -> V_137 , V_135 ) ;
if ( F_136 ( V_29 ) == 0 )
F_118 ( L_17 ) ;
if ( F_136 ( V_29 ) != F_137 ( type ) )
F_138 ( L_18 ,
( unsigned long long ) F_137 ( type ) ,
( unsigned long long ) F_136 ( V_29 ) ) ;
}
static struct V_163 *
F_139 ( struct V_39 * V_42 , struct V_31 * V_32 ,
T_4 V_81 , T_4 V_82 )
{
bool V_72 = false ;
unsigned long V_33 ;
struct V_163 * V_164 ;
struct V_93 * V_95 ;
if ( ! F_140 ( V_32 -> V_75 ) )
return NULL ;
if ( ! V_32 -> V_165 )
return NULL ;
F_100 ( & V_166 , V_33 ) ;
F_141 (info, &domain->devices, link)
if ( V_164 -> V_32 == V_32 && V_164 -> V_81 == V_81 &&
V_164 -> V_82 == V_82 ) {
V_72 = true ;
break;
}
F_101 ( & V_166 , V_33 ) ;
if ( ! V_72 || ! V_164 -> V_89 || ! F_91 ( V_164 -> V_89 ) )
return NULL ;
V_95 = F_92 ( V_164 -> V_89 ) ;
if ( ! F_142 ( V_95 , V_167 ) )
return NULL ;
if ( ! F_143 ( V_95 ) )
return NULL ;
return V_164 ;
}
static void F_144 ( struct V_163 * V_164 )
{
if ( ! V_164 || ! F_91 ( V_164 -> V_89 ) )
return;
F_145 ( F_92 ( V_164 -> V_89 ) , V_12 ) ;
}
static void F_146 ( struct V_163 * V_164 )
{
if ( ! V_164 -> V_89 || ! F_91 ( V_164 -> V_89 ) ||
! F_147 ( F_92 ( V_164 -> V_89 ) ) )
return;
F_148 ( F_92 ( V_164 -> V_89 ) ) ;
}
static void F_149 ( struct V_39 * V_42 ,
V_24 V_105 , unsigned V_78 )
{
T_5 V_168 , V_169 ;
unsigned long V_33 ;
struct V_163 * V_164 ;
F_100 ( & V_166 , V_33 ) ;
F_141 (info, &domain->devices, link) {
struct V_93 * V_95 ;
if ( ! V_164 -> V_89 || ! F_91 ( V_164 -> V_89 ) )
continue;
V_95 = F_92 ( V_164 -> V_89 ) ;
if ( ! F_147 ( V_95 ) )
continue;
V_168 = V_164 -> V_81 << 8 | V_164 -> V_82 ;
V_169 = F_150 ( V_95 ) ;
F_151 ( V_164 -> V_32 , V_168 , V_169 , V_105 , V_78 ) ;
}
F_101 ( & V_166 , V_33 ) ;
}
static void F_152 ( struct V_31 * V_32 , T_5 V_146 ,
unsigned long V_6 , unsigned int V_170 , int V_171 , int V_172 )
{
unsigned int V_78 = F_153 ( F_154 ( V_170 ) ) ;
T_6 V_105 = ( T_6 ) V_6 << V_12 ;
F_70 ( V_170 == 0 ) ;
if ( V_171 )
V_171 = 1 << 6 ;
if ( ! F_155 ( V_32 -> V_64 ) || V_78 > F_156 ( V_32 -> V_64 ) )
V_32 -> V_173 . V_174 ( V_32 , V_146 , 0 , 0 ,
V_160 ) ;
else
V_32 -> V_173 . V_174 ( V_32 , V_146 , V_105 | V_171 , V_78 ,
V_161 ) ;
if ( ! F_157 ( V_32 -> V_64 ) || ! V_172 )
F_149 ( V_32 -> V_175 [ V_146 ] , V_105 , V_78 ) ;
}
static void F_158 ( struct V_31 * V_32 )
{
T_2 V_176 ;
unsigned long V_33 ;
F_120 ( & V_32 -> V_137 , V_33 ) ;
V_176 = F_44 ( V_32 -> V_36 + V_177 ) ;
V_176 &= ~ V_178 ;
F_122 ( V_176 , V_32 -> V_36 + V_177 ) ;
F_123 ( V_32 , V_177 ,
F_44 , ! ( V_176 & V_179 ) , V_176 ) ;
F_124 ( & V_32 -> V_137 , V_33 ) ;
}
static void F_159 ( struct V_31 * V_32 )
{
T_2 V_134 ;
unsigned long V_33 ;
F_120 ( & V_32 -> V_137 , V_33 ) ;
V_32 -> V_139 |= V_180 ;
F_122 ( V_32 -> V_139 , V_32 -> V_36 + V_141 ) ;
F_123 ( V_32 , V_37 ,
F_44 , ( V_134 & V_38 ) , V_134 ) ;
F_124 ( & V_32 -> V_137 , V_33 ) ;
}
static void F_160 ( struct V_31 * V_32 )
{
T_2 V_134 ;
unsigned long V_135 ;
F_120 ( & V_32 -> V_137 , V_135 ) ;
V_32 -> V_139 &= ~ V_180 ;
F_122 ( V_32 -> V_139 , V_32 -> V_36 + V_141 ) ;
F_123 ( V_32 , V_37 ,
F_44 , ( ! ( V_134 & V_38 ) ) , V_134 ) ;
F_124 ( & V_32 -> V_137 , V_135 ) ;
}
static int F_161 ( struct V_31 * V_32 )
{
unsigned long V_181 ;
unsigned long V_182 ;
V_181 = F_162 ( V_32 -> V_64 ) ;
F_138 ( L_19 ,
V_32 -> V_131 , V_181 ) ;
V_182 = F_163 ( V_181 ) ;
F_164 ( & V_32 -> V_107 ) ;
V_32 -> V_183 = F_165 ( V_182 , sizeof( unsigned long ) , V_184 ) ;
if ( ! V_32 -> V_183 ) {
F_118 ( L_20 ,
V_32 -> V_131 ) ;
return - V_132 ;
}
V_32 -> V_175 = F_165 ( V_181 , sizeof( struct V_39 * ) ,
V_184 ) ;
if ( ! V_32 -> V_175 ) {
F_118 ( L_21 ,
V_32 -> V_131 ) ;
F_166 ( V_32 -> V_183 ) ;
V_32 -> V_183 = NULL ;
return - V_132 ;
}
if ( F_157 ( V_32 -> V_64 ) )
F_167 ( 0 , V_32 -> V_183 ) ;
return 0 ;
}
static void F_168 ( struct V_31 * V_32 )
{
struct V_39 * V_42 ;
int V_73 ;
if ( ( V_32 -> V_175 ) && ( V_32 -> V_183 ) ) {
F_73 (i, iommu->domain_ids, cap_ndoms(iommu->cap)) {
if ( F_157 ( V_32 -> V_64 ) && V_73 == 0 )
continue;
V_42 = V_32 -> V_175 [ V_73 ] ;
F_169 ( V_73 , V_32 -> V_183 ) ;
if ( F_170 ( V_42 , V_32 ) == 0 &&
! F_61 ( V_42 ) )
F_171 ( V_42 ) ;
}
}
if ( V_32 -> V_139 & V_180 )
F_160 ( V_32 ) ;
}
static void F_172 ( struct V_31 * V_32 )
{
if ( ( V_32 -> V_175 ) && ( V_32 -> V_183 ) ) {
F_166 ( V_32 -> V_175 ) ;
F_166 ( V_32 -> V_183 ) ;
V_32 -> V_175 = NULL ;
V_32 -> V_183 = NULL ;
}
V_69 [ V_32 -> V_185 ] = NULL ;
F_103 ( V_32 ) ;
}
static struct V_39 * F_173 ( int V_33 )
{
static T_7 V_186 = F_174 ( 0 ) ;
struct V_39 * V_42 ;
V_42 = F_55 () ;
if ( ! V_42 )
return NULL ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_115 = - 1 ;
V_42 -> V_33 = V_33 ;
F_164 ( & V_42 -> V_187 ) ;
F_175 ( & V_42 -> V_97 ) ;
if ( V_33 & V_58 )
V_42 -> V_188 = F_176 ( & V_186 ) ;
return V_42 ;
}
static int F_177 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
int V_189 ;
unsigned long V_181 ;
V_181 = F_162 ( V_32 -> V_64 ) ;
V_189 = F_178 ( V_32 -> V_183 , V_181 ) ;
if ( V_189 < V_181 ) {
F_167 ( V_189 , V_32 -> V_183 ) ;
V_32 -> V_175 [ V_189 ] = V_42 ;
} else {
V_189 = - V_190 ;
}
return V_189 ;
}
static int F_179 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
int V_189 ;
unsigned long V_33 ;
F_100 ( & V_32 -> V_107 , V_33 ) ;
V_189 = F_177 ( V_42 , V_32 ) ;
F_101 ( & V_32 -> V_107 , V_33 ) ;
if ( V_189 < 0 )
F_118 ( L_22 , V_32 -> V_131 ) ;
return V_189 ;
}
static int F_180 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
int V_189 ;
unsigned long V_181 ;
V_181 = F_162 ( V_32 -> V_64 ) ;
F_73 (num, iommu->domain_ids, ndomains)
if ( V_32 -> V_175 [ V_189 ] == V_42 )
return V_189 ;
return F_177 ( V_42 , V_32 ) ;
}
static void F_181 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
unsigned long V_33 ;
int V_189 , V_181 ;
F_100 ( & V_32 -> V_107 , V_33 ) ;
if ( F_62 ( V_42 ) ) {
V_181 = F_162 ( V_32 -> V_64 ) ;
F_73 (num, iommu->domain_ids, ndomains) {
if ( V_32 -> V_175 [ V_189 ] == V_42 ) {
F_169 ( V_189 , V_32 -> V_183 ) ;
V_32 -> V_175 [ V_189 ] = NULL ;
break;
}
}
} else {
F_169 ( V_42 -> V_188 , V_32 -> V_183 ) ;
V_32 -> V_175 [ V_42 -> V_188 ] = NULL ;
}
F_101 ( & V_32 -> V_107 , V_33 ) ;
}
static void F_182 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
unsigned long V_33 ;
F_100 ( & V_42 -> V_187 , V_33 ) ;
if ( ! F_183 ( V_32 -> V_185 , V_42 -> V_67 ) ) {
V_42 -> V_191 ++ ;
if ( V_42 -> V_191 == 1 )
V_42 -> V_115 = V_32 -> V_52 ;
F_83 ( V_42 ) ;
}
F_101 ( & V_42 -> V_187 , V_33 ) ;
}
static int F_170 ( struct V_39 * V_42 ,
struct V_31 * V_32 )
{
unsigned long V_33 ;
int V_192 = V_193 ;
F_100 ( & V_42 -> V_187 , V_33 ) ;
if ( F_184 ( V_32 -> V_185 , V_42 -> V_67 ) ) {
V_192 = -- V_42 -> V_191 ;
F_83 ( V_42 ) ;
}
F_101 ( & V_42 -> V_187 , V_33 ) ;
return V_192 ;
}
static int F_185 ( void )
{
struct V_93 * V_95 = NULL ;
struct V_194 * V_194 ;
int V_73 ;
F_186 ( & V_195 , V_116 , V_196 ,
V_197 ) ;
F_187 ( & V_195 . V_198 ,
& V_199 ) ;
V_194 = F_188 ( & V_195 , F_189 ( V_200 ) ,
F_189 ( V_201 ) ) ;
if ( ! V_194 ) {
F_118 ( L_23 ) ;
return - V_202 ;
}
F_190 (pdev) {
struct V_203 * V_204 ;
for ( V_73 = 0 ; V_73 < V_205 ; V_73 ++ ) {
V_204 = & V_95 -> V_203 [ V_73 ] ;
if ( ! V_204 -> V_33 || ! ( V_204 -> V_33 & V_206 ) )
continue;
V_194 = F_188 ( & V_195 ,
F_189 ( V_204 -> V_207 ) ,
F_189 ( V_204 -> V_102 ) ) ;
if ( ! V_194 ) {
F_118 ( L_24 ) ;
return - V_202 ;
}
}
}
return 0 ;
}
static void F_191 ( struct V_39 * V_42 )
{
F_192 ( & V_195 , & V_42 -> V_208 ) ;
}
static inline int F_193 ( int V_127 )
{
int V_1 ;
int V_204 = ( V_127 - 12 ) % 9 ;
if ( V_204 == 0 )
V_1 = V_127 ;
else
V_1 = V_127 + 9 - V_204 ;
if ( V_1 > 64 )
V_1 = 64 ;
return V_1 ;
}
static int F_194 ( struct V_39 * V_42 , int V_209 )
{
struct V_31 * V_32 ;
int V_210 , V_1 ;
unsigned long V_63 ;
F_186 ( & V_42 -> V_208 , V_116 , V_196 ,
V_197 ) ;
F_191 ( V_42 ) ;
V_32 = F_69 ( V_42 ) ;
if ( V_209 > F_195 ( V_32 -> V_64 ) )
V_209 = F_195 ( V_32 -> V_64 ) ;
V_42 -> V_127 = V_209 ;
V_210 = F_193 ( V_209 ) ;
V_1 = F_4 ( V_210 ) ;
V_63 = F_65 ( V_32 -> V_64 ) ;
if ( ! F_66 ( V_1 , & V_63 ) ) {
F_138 ( L_25 , V_1 ) ;
V_1 = F_196 ( & V_63 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_202 ;
}
V_42 -> V_1 = V_1 ;
if ( F_74 ( V_32 -> V_75 ) )
V_42 -> V_74 = 1 ;
else
V_42 -> V_74 = 0 ;
if ( F_79 ( V_32 -> V_75 ) )
V_42 -> V_79 = 1 ;
else
V_42 -> V_79 = 0 ;
if ( V_49 )
V_42 -> V_80 = F_82 ( F_81 ( V_32 -> V_64 ) ) ;
else
V_42 -> V_80 = 0 ;
V_42 -> V_115 = V_32 -> V_52 ;
V_42 -> V_112 = (struct V_27 * ) F_50 ( V_42 -> V_115 ) ;
if ( ! V_42 -> V_112 )
return - V_132 ;
F_87 ( V_32 , V_42 -> V_112 , V_211 ) ;
return 0 ;
}
static void F_171 ( struct V_39 * V_42 )
{
struct V_70 * V_71 ;
struct V_31 * V_32 ;
struct V_14 * V_128 = NULL ;
if ( ! V_42 )
return;
if ( ! V_48 )
F_197 ( 0 ) ;
F_198 ( V_42 ) ;
F_199 ( & V_42 -> V_208 ) ;
V_128 = F_115 ( V_42 , 0 , F_111 ( V_42 -> V_127 ) ) ;
F_75 () ;
F_76 (iommu, drhd)
if ( F_61 ( V_42 ) ||
F_66 ( V_32 -> V_185 , V_42 -> V_67 ) )
F_181 ( V_42 , V_32 ) ;
F_77 () ;
F_116 ( V_128 ) ;
F_57 ( V_42 ) ;
}
static int F_200 ( struct V_39 * V_42 ,
struct V_31 * V_32 ,
T_4 V_81 , T_4 V_82 , int V_212 )
{
struct V_22 * V_23 ;
unsigned long V_33 ;
struct V_27 * V_112 ;
int V_188 ;
int V_1 ;
struct V_163 * V_164 = NULL ;
F_138 ( L_26 ,
V_81 , F_201 ( V_82 ) , F_202 ( V_82 ) ) ;
F_70 ( ! V_42 -> V_112 ) ;
F_70 ( V_212 != V_213 &&
V_212 != V_214 ) ;
F_100 ( & V_32 -> V_107 , V_33 ) ;
V_23 = F_84 ( V_32 , V_81 , V_82 , 1 ) ;
F_101 ( & V_32 -> V_107 , V_33 ) ;
if ( ! V_23 )
return - V_132 ;
F_100 ( & V_32 -> V_107 , V_33 ) ;
if ( F_25 ( V_23 ) ) {
F_101 ( & V_32 -> V_107 , V_33 ) ;
return 0 ;
}
F_33 ( V_23 ) ;
V_188 = V_42 -> V_188 ;
V_112 = V_42 -> V_112 ;
if ( F_62 ( V_42 ) ) {
if ( F_61 ( V_42 ) ) {
V_188 = F_180 ( V_42 , V_32 ) ;
if ( V_188 < 0 ) {
F_101 ( & V_32 -> V_107 , V_33 ) ;
F_118 ( L_22 , V_32 -> V_131 ) ;
return - V_215 ;
}
}
if ( V_212 != V_213 ) {
for ( V_1 = V_42 -> V_1 ; V_1 != V_32 -> V_1 ; V_1 -- ) {
V_112 = F_86 ( F_35 ( V_112 ) ) ;
if ( ! F_38 ( V_112 ) ) {
F_101 ( & V_32 -> V_107 , V_33 ) ;
return - V_132 ;
}
}
}
}
F_31 ( V_23 , V_188 ) ;
if ( V_212 != V_213 ) {
V_164 = F_139 ( V_42 , V_32 , V_81 , V_82 ) ;
V_212 = V_164 ? V_216 :
V_214 ;
}
if ( F_203 ( V_212 == V_213 ) )
F_30 ( V_23 , V_32 -> V_217 ) ;
else {
F_29 ( V_23 , F_88 ( V_112 ) ) ;
F_30 ( V_23 , V_32 -> V_1 ) ;
}
F_28 ( V_23 , V_212 ) ;
F_27 ( V_23 ) ;
F_26 ( V_23 ) ;
F_97 ( V_42 , V_23 , sizeof( * V_23 ) ) ;
if ( F_157 ( V_32 -> V_64 ) ) {
V_32 -> V_173 . V_218 ( V_32 , 0 ,
( ( ( T_5 ) V_81 ) << 8 ) | V_82 ,
V_219 ,
V_151 ) ;
V_32 -> V_173 . V_174 ( V_32 , V_188 , 0 , 0 , V_160 ) ;
} else {
F_125 ( V_32 ) ;
}
F_144 ( V_164 ) ;
F_101 ( & V_32 -> V_107 , V_33 ) ;
F_182 ( V_42 , V_32 ) ;
return 0 ;
}
static int F_204 ( struct V_93 * V_95 ,
T_5 V_220 , void * V_221 )
{
struct V_222 * V_223 = V_221 ;
return F_200 ( V_223 -> V_42 , V_223 -> V_32 ,
F_205 ( V_220 ) , V_220 & 0xff ,
V_223 -> V_212 ) ;
}
static int
F_206 ( struct V_39 * V_42 , struct V_88 * V_89 ,
int V_212 )
{
struct V_31 * V_32 ;
T_4 V_81 , V_82 ;
struct V_222 V_223 ;
V_32 = F_90 ( V_89 , & V_81 , & V_82 ) ;
if ( ! V_32 )
return - V_202 ;
if ( ! F_91 ( V_89 ) )
return F_200 ( V_42 , V_32 , V_81 , V_82 ,
V_212 ) ;
V_223 . V_42 = V_42 ;
V_223 . V_32 = V_32 ;
V_223 . V_212 = V_212 ;
return F_207 ( F_92 ( V_89 ) ,
& F_204 , & V_223 ) ;
}
static int F_208 ( struct V_93 * V_95 ,
T_5 V_220 , void * V_221 )
{
struct V_31 * V_32 = V_221 ;
return ! F_99 ( V_32 , F_205 ( V_220 ) , V_220 & 0xff ) ;
}
static int F_209 ( struct V_88 * V_89 )
{
struct V_31 * V_32 ;
T_4 V_81 , V_82 ;
V_32 = F_90 ( V_89 , & V_81 , & V_82 ) ;
if ( ! V_32 )
return - V_202 ;
if ( ! F_91 ( V_89 ) )
return F_99 ( V_32 , V_81 , V_82 ) ;
return ! F_207 ( F_92 ( V_89 ) ,
F_208 , V_32 ) ;
}
static inline unsigned long F_210 ( unsigned long V_224 ,
T_8 V_106 )
{
V_224 &= ~ V_225 ;
return F_211 ( V_224 + V_106 ) >> V_12 ;
}
static inline int F_212 ( struct V_39 * V_42 ,
unsigned long V_226 ,
unsigned long V_227 ,
unsigned long V_170 )
{
int V_228 , V_5 = 1 ;
unsigned long V_229 ;
V_228 = V_42 -> V_80 ;
V_229 = V_226 | V_227 ;
while ( V_228 && ! ( V_229 & ~ V_230 ) ) {
V_170 >>= V_231 ;
if ( ! V_170 )
break;
V_229 >>= V_231 ;
V_5 ++ ;
V_228 -- ;
}
return V_5 ;
}
static int F_213 ( struct V_39 * V_42 , unsigned long V_226 ,
struct V_232 * V_233 , unsigned long V_234 ,
unsigned long V_235 , int V_236 )
{
struct V_27 * V_123 = NULL , * V_28 = NULL ;
T_1 V_237 ( V_114 ) ;
unsigned long V_238 = 0 ;
unsigned int V_239 = 0 ;
unsigned long V_240 = 0 ;
F_70 ( ! F_63 ( V_42 , V_226 + V_235 - 1 ) ) ;
if ( ( V_236 & ( V_117 | V_118 ) ) == 0 )
return - V_44 ;
V_236 &= V_117 | V_118 | V_241 ;
if ( ! V_233 ) {
V_238 = V_235 ;
V_114 = ( ( T_1 ) V_234 << V_12 ) | V_236 ;
}
while ( V_235 > 0 ) {
T_6 V_92 ;
if ( ! V_238 ) {
V_238 = F_210 ( V_233 -> V_111 , V_233 -> V_242 ) ;
V_233 -> V_243 = ( ( V_244 ) V_226 << V_12 ) + V_233 -> V_111 ;
V_233 -> V_245 = V_233 -> V_242 ;
V_114 = F_214 ( F_215 ( V_233 ) ) | V_236 ;
V_234 = V_114 >> V_12 ;
}
if ( ! V_28 ) {
V_239 = F_212 ( V_42 , V_226 , V_234 , V_238 ) ;
V_123 = V_28 = F_104 ( V_42 , V_226 , & V_239 ) ;
if ( ! V_28 )
return - V_132 ;
if ( V_239 > 1 ) {
V_114 |= V_30 ;
V_240 = F_11 ( V_239 ) ;
F_110 ( V_42 , V_226 ,
V_226 + V_240 - 1 ) ;
} else {
V_114 &= ~ ( T_6 ) V_30 ;
}
}
V_92 = F_216 ( & V_28 -> V_29 , 0ULL , V_114 ) ;
if ( V_92 ) {
static int V_246 = 5 ;
F_217 ( L_27 ,
V_226 , V_92 , ( unsigned long long ) V_114 ) ;
if ( V_246 ) {
V_246 -- ;
F_218 ( NULL ) ;
}
F_219 ( 1 ) ;
}
V_240 = F_11 ( V_239 ) ;
F_70 ( V_235 < V_240 ) ;
F_70 ( V_238 < V_240 ) ;
V_235 -= V_240 ;
V_226 += V_240 ;
V_234 += V_240 ;
V_114 += V_240 * V_116 ;
V_238 -= V_240 ;
V_28 ++ ;
if ( ! V_235 || F_40 ( V_28 ) ||
( V_239 > 1 && V_238 < V_240 ) ) {
F_97 ( V_42 , V_123 ,
( void * ) V_28 - ( void * ) V_123 ) ;
V_28 = NULL ;
}
if ( ! V_238 && V_235 )
V_233 = F_220 ( V_233 ) ;
}
return 0 ;
}
static inline int F_221 ( struct V_39 * V_42 , unsigned long V_226 ,
struct V_232 * V_233 , unsigned long V_235 ,
int V_236 )
{
return F_213 ( V_42 , V_226 , V_233 , 0 , V_235 , V_236 ) ;
}
static inline int F_222 ( struct V_39 * V_42 , unsigned long V_226 ,
unsigned long V_234 , unsigned long V_235 ,
int V_236 )
{
return F_213 ( V_42 , V_226 , NULL , V_234 , V_235 , V_236 ) ;
}
static void F_223 ( struct V_31 * V_32 , T_4 V_81 , T_4 V_82 )
{
if ( ! V_32 )
return;
F_102 ( V_32 , V_81 , V_82 ) ;
V_32 -> V_173 . V_218 ( V_32 , 0 , 0 , 0 ,
V_149 ) ;
V_32 -> V_173 . V_174 ( V_32 , 0 , 0 , 0 , V_158 ) ;
}
static inline void F_224 ( struct V_163 * V_164 )
{
F_225 ( & V_166 ) ;
F_226 ( & V_164 -> V_247 ) ;
F_226 ( & V_164 -> V_248 ) ;
if ( V_164 -> V_89 )
V_164 -> V_89 -> V_90 . V_32 = NULL ;
}
static void F_198 ( struct V_39 * V_42 )
{
struct V_163 * V_164 , * V_92 ;
unsigned long V_33 ;
F_100 ( & V_166 , V_33 ) ;
F_227 (info, tmp, &domain->devices, link) {
F_224 ( V_164 ) ;
F_101 ( & V_166 , V_33 ) ;
F_146 ( V_164 ) ;
F_223 ( V_164 -> V_32 , V_164 -> V_81 , V_164 -> V_82 ) ;
if ( F_61 ( V_42 ) ) {
F_228 ( V_164 -> V_32 , V_164 -> V_89 ) ;
F_170 ( V_42 , V_164 -> V_32 ) ;
}
F_60 ( V_164 ) ;
F_100 ( & V_166 , V_33 ) ;
}
F_101 ( & V_166 , V_33 ) ;
}
static struct V_39 * F_229 ( struct V_88 * V_89 )
{
struct V_163 * V_164 ;
V_164 = V_89 -> V_90 . V_32 ;
if ( V_164 )
return V_164 -> V_42 ;
return NULL ;
}
static inline struct V_163 *
F_230 ( int V_96 , int V_81 , int V_82 )
{
struct V_163 * V_164 ;
F_141 (info, &device_domain_list, global)
if ( V_164 -> V_32 -> V_96 == V_96 && V_164 -> V_81 == V_81 &&
V_164 -> V_82 == V_82 )
return V_164 ;
return NULL ;
}
static struct V_39 * F_231 ( struct V_31 * V_32 ,
int V_81 , int V_82 ,
struct V_88 * V_89 ,
struct V_39 * V_42 )
{
struct V_39 * V_72 = NULL ;
struct V_163 * V_164 ;
unsigned long V_33 ;
V_164 = F_59 () ;
if ( ! V_164 )
return NULL ;
V_164 -> V_81 = V_81 ;
V_164 -> V_82 = V_82 ;
V_164 -> V_89 = V_89 ;
V_164 -> V_42 = V_42 ;
V_164 -> V_32 = V_32 ;
F_100 ( & V_166 , V_33 ) ;
if ( V_89 )
V_72 = F_229 ( V_89 ) ;
else {
struct V_163 * V_249 ;
V_249 = F_230 ( V_32 -> V_96 , V_81 , V_82 ) ;
if ( V_249 )
V_72 = V_249 -> V_42 ;
}
if ( V_72 ) {
F_101 ( & V_166 , V_33 ) ;
F_60 ( V_164 ) ;
return V_72 ;
}
F_232 ( & V_164 -> V_247 , & V_42 -> V_97 ) ;
F_232 ( & V_164 -> V_248 , & V_250 ) ;
if ( V_89 )
V_89 -> V_90 . V_32 = V_164 ;
F_101 ( & V_166 , V_33 ) ;
return V_42 ;
}
static int F_233 ( struct V_93 * V_95 , T_5 V_220 , void * V_221 )
{
* ( T_5 * ) V_221 = V_220 ;
return 0 ;
}
static struct V_39 * F_234 ( struct V_88 * V_89 , int V_127 )
{
struct V_39 * V_42 , * V_92 ;
struct V_31 * V_32 ;
struct V_163 * V_164 ;
T_5 V_251 ;
unsigned long V_33 ;
T_4 V_81 , V_82 ;
V_42 = F_229 ( V_89 ) ;
if ( V_42 )
return V_42 ;
V_32 = F_90 ( V_89 , & V_81 , & V_82 ) ;
if ( ! V_32 )
return NULL ;
if ( F_91 ( V_89 ) ) {
struct V_93 * V_95 = F_92 ( V_89 ) ;
F_207 ( V_95 , F_233 , & V_251 ) ;
F_100 ( & V_166 , V_33 ) ;
V_164 = F_230 ( F_93 ( V_95 -> V_81 ) ,
F_205 ( V_251 ) ,
V_251 & 0xff ) ;
if ( V_164 ) {
V_32 = V_164 -> V_32 ;
V_42 = V_164 -> V_42 ;
}
F_101 ( & V_166 , V_33 ) ;
if ( V_164 )
goto V_252;
}
V_42 = F_173 ( 0 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_188 = F_179 ( V_42 , V_32 ) ;
if ( V_42 -> V_188 < 0 ) {
F_57 ( V_42 ) ;
return NULL ;
}
F_182 ( V_42 , V_32 ) ;
if ( F_194 ( V_42 , V_127 ) ) {
F_171 ( V_42 ) ;
return NULL ;
}
if ( F_91 ( V_89 ) ) {
V_92 = F_231 ( V_32 , F_205 ( V_251 ) ,
V_251 & 0xff , NULL , V_42 ) ;
if ( ! V_92 || V_92 != V_42 ) {
F_171 ( V_42 ) ;
V_42 = V_92 ;
}
if ( ! V_42 )
return NULL ;
}
V_252:
V_92 = F_231 ( V_32 , V_81 , V_82 , V_89 , V_42 ) ;
if ( ! V_92 || V_92 != V_42 ) {
F_171 ( V_42 ) ;
V_42 = V_92 ;
}
return V_42 ;
}
static int F_235 ( struct V_39 * V_42 ,
unsigned long long V_207 ,
unsigned long long V_102 )
{
unsigned long V_253 = V_207 >> V_12 ;
unsigned long V_254 = V_102 >> V_12 ;
if ( ! F_188 ( & V_42 -> V_208 , F_12 ( V_253 ) ,
F_12 ( V_254 ) ) ) {
F_118 ( L_28 ) ;
return - V_132 ;
}
F_138 ( L_29 ,
V_207 , V_102 , V_42 -> V_188 ) ;
F_107 ( V_42 , V_253 , V_254 ) ;
return F_222 ( V_42 , V_253 , V_253 ,
V_254 - V_253 + 1 ,
V_117 | V_118 ) ;
}
static int F_236 ( struct V_88 * V_89 ,
unsigned long long V_207 ,
unsigned long long V_102 )
{
struct V_39 * V_42 ;
int V_77 ;
V_42 = F_234 ( V_89 , V_65 ) ;
if ( ! V_42 )
return - V_132 ;
if ( V_42 == V_255 && V_256 ) {
F_237 ( L_30 ,
F_238 ( V_89 ) , V_207 , V_102 ) ;
return 0 ;
}
F_48 ( L_31 ,
F_238 ( V_89 ) , V_207 , V_102 ) ;
if ( V_102 < V_207 ) {
F_239 ( 1 , L_32
L_33 ,
F_240 ( V_257 ) ,
F_240 ( V_258 ) ,
F_240 ( V_259 ) ) ;
V_77 = - V_260 ;
goto error;
}
if ( V_102 >> F_2 ( V_42 -> V_1 ) ) {
F_239 ( 1 , L_34
L_33 ,
F_2 ( V_42 -> V_1 ) ,
F_240 ( V_257 ) ,
F_240 ( V_258 ) ,
F_240 ( V_259 ) ) ;
V_77 = - V_260 ;
goto error;
}
V_77 = F_235 ( V_42 , V_207 , V_102 ) ;
if ( V_77 )
goto error;
V_77 = F_206 ( V_42 , V_89 , V_214 ) ;
if ( V_77 )
goto error;
return 0 ;
error:
F_171 ( V_42 ) ;
return V_77 ;
}
static inline int F_241 ( struct V_261 * V_262 ,
struct V_88 * V_89 )
{
if ( V_89 -> V_90 . V_32 == V_91 )
return 0 ;
return F_236 ( V_89 , V_262 -> V_263 ,
V_262 -> V_264 ) ;
}
static inline void F_242 ( void )
{
struct V_93 * V_95 ;
int V_77 ;
V_95 = F_243 ( V_265 << 8 , NULL ) ;
if ( ! V_95 )
return;
F_48 ( L_35 ) ;
V_77 = F_236 ( & V_95 -> V_89 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_77 )
F_118 ( L_36 ) ;
F_244 ( V_95 ) ;
}
static inline void F_242 ( void )
{
return;
}
static int T_3 F_245 ( int V_266 )
{
struct V_70 * V_71 ;
struct V_31 * V_32 ;
int V_115 , V_77 = 0 ;
bool V_267 = true ;
V_255 = F_173 ( V_59 ) ;
if ( ! V_255 )
return - V_215 ;
F_76 (iommu, drhd) {
V_77 = F_179 ( V_255 , V_32 ) ;
if ( V_77 < 0 ) {
F_171 ( V_255 ) ;
return - V_215 ;
} else if ( V_267 ) {
V_255 -> V_188 = V_77 ;
V_267 = false ;
} else if ( V_255 -> V_188 != V_77 ) {
F_171 ( V_255 ) ;
return - V_215 ;
}
F_182 ( V_255 , V_32 ) ;
}
if ( F_246 ( V_255 , V_65 ) ) {
F_171 ( V_255 ) ;
return - V_215 ;
}
F_138 ( L_37 ,
V_255 -> V_188 ) ;
if ( V_266 )
return 0 ;
F_247 (nid) {
unsigned long V_121 , V_268 ;
int V_73 ;
F_248 (i, nid, &start_pfn, &end_pfn, NULL) {
V_77 = F_235 ( V_255 ,
F_249 ( V_121 ) , F_249 ( V_268 ) ) ;
if ( V_77 )
return V_77 ;
}
}
return 0 ;
}
static int F_250 ( struct V_88 * V_89 )
{
struct V_163 * V_164 ;
if ( F_251 ( ! V_269 ) )
return 0 ;
V_164 = V_89 -> V_90 . V_32 ;
if ( V_164 && V_164 != V_91 )
return ( V_164 -> V_42 == V_255 ) ;
return 0 ;
}
static int F_252 ( struct V_39 * V_42 ,
struct V_88 * V_89 , int V_212 )
{
struct V_39 * V_270 ;
struct V_31 * V_32 ;
T_4 V_81 , V_82 ;
int V_77 ;
V_32 = F_90 ( V_89 , & V_81 , & V_82 ) ;
if ( ! V_32 )
return - V_202 ;
V_270 = F_231 ( V_32 , V_81 , V_82 , V_89 , V_42 ) ;
if ( V_270 != V_42 )
return - V_271 ;
V_77 = F_206 ( V_42 , V_89 , V_212 ) ;
if ( V_77 ) {
F_253 ( V_42 , V_89 ) ;
return V_77 ;
}
return 0 ;
}
static bool F_254 ( struct V_88 * V_89 )
{
struct V_261 * V_262 ;
struct V_88 * V_92 ;
int V_73 ;
F_75 () ;
F_255 (rmrr) {
F_96 (rmrr->devices,
rmrr->devices_cnt, i, tmp)
if ( V_92 == V_89 ) {
F_77 () ;
return true ;
}
}
F_77 () ;
return false ;
}
static bool F_256 ( struct V_88 * V_89 )
{
if ( ! F_254 ( V_89 ) )
return false ;
if ( F_91 ( V_89 ) ) {
struct V_93 * V_95 = F_92 ( V_89 ) ;
if ( F_257 ( V_95 ) || F_258 ( V_95 ) )
return false ;
}
return true ;
}
static int F_259 ( struct V_88 * V_89 , int V_272 )
{
if ( F_91 ( V_89 ) ) {
struct V_93 * V_95 = F_92 ( V_89 ) ;
if ( F_256 ( V_89 ) )
return 0 ;
if ( ( V_269 & V_273 ) && F_260 ( V_95 ) )
return 1 ;
if ( ( V_269 & V_274 ) && F_258 ( V_95 ) )
return 1 ;
if ( ! ( V_269 & V_275 ) )
return 0 ;
if ( ! F_261 ( V_95 ) ) {
if ( ! F_262 ( V_95 -> V_81 ) )
return 0 ;
if ( V_95 -> V_276 >> 8 == V_277 )
return 0 ;
} else if ( F_263 ( V_95 ) == V_278 )
return 0 ;
} else {
if ( F_254 ( V_89 ) )
return 0 ;
}
if ( ! V_272 ) {
V_24 V_279 = * V_89 -> V_279 ;
if ( V_89 -> V_280 &&
V_89 -> V_280 < V_279 )
V_279 = V_89 -> V_280 ;
return V_279 >= F_264 ( V_89 ) ;
}
return 1 ;
}
static int T_3 F_265 ( struct V_88 * V_89 , int V_266 )
{
int V_77 ;
if ( ! F_259 ( V_89 , 1 ) )
return 0 ;
V_77 = F_252 ( V_255 , V_89 ,
V_266 ? V_213 :
V_214 ) ;
if ( ! V_77 )
F_48 ( L_38 ,
V_266 ? L_39 : L_40 , F_238 ( V_89 ) ) ;
else if ( V_77 == - V_202 )
V_77 = 0 ;
return V_77 ;
}
static int T_3 F_266 ( int V_266 )
{
struct V_93 * V_95 = NULL ;
struct V_70 * V_71 ;
struct V_31 * V_32 ;
struct V_88 * V_89 ;
int V_73 ;
int V_77 = 0 ;
F_190 (pdev) {
V_77 = F_265 ( & V_95 -> V_89 , V_266 ) ;
if ( V_77 )
return V_77 ;
}
F_76 (iommu, drhd)
F_96 (drhd->devices, drhd->devices_cnt, i, dev) {
struct V_281 * V_282 ;
struct V_283 * V_284 ;
if ( V_89 -> V_81 != & V_285 )
continue;
V_284 = F_267 ( V_89 ) ;
F_268 ( & V_284 -> V_286 ) ;
F_141 (pn, &adev->physical_node_list, node) {
V_77 = F_265 ( V_282 -> V_89 , V_266 ) ;
if ( V_77 )
break;
}
F_269 ( & V_284 -> V_286 ) ;
if ( V_77 )
return V_77 ;
}
return 0 ;
}
static void F_270 ( struct V_31 * V_32 )
{
if ( ! V_32 -> V_165 ) {
F_271 ( - 1 , V_32 ) ;
F_272 ( V_32 ) ;
}
if ( F_273 ( V_32 ) ) {
V_32 -> V_173 . V_218 = F_127 ;
V_32 -> V_173 . V_174 = F_132 ;
F_48 ( L_41 ,
V_32 -> V_131 ) ;
} else {
V_32 -> V_173 . V_218 = V_287 ;
V_32 -> V_173 . V_174 = V_288 ;
F_48 ( L_42 , V_32 -> V_131 ) ;
}
}
static int F_274 ( struct V_31 * V_32 ,
struct V_17 * V_289 ,
struct V_22 * * V_290 ,
int V_81 , bool V_291 )
{
struct V_22 * V_292 = NULL , * V_293 = NULL , V_294 ;
int V_295 , V_296 = 0 , V_297 , V_82 , V_77 = 0 , V_146 ;
T_1 V_298 ;
V_295 = V_291 ? V_81 * 2 : V_81 ;
for ( V_82 = 0 ; V_82 < 256 ; V_82 ++ ) {
V_297 = ( V_291 ? V_82 * 2 : V_82 ) % 256 ;
if ( V_297 == 0 ) {
if ( V_293 ) {
V_290 [ V_295 ] = V_293 ;
F_87 ( V_32 , V_293 ,
V_116 ) ;
V_296 = 1 ;
}
if ( V_292 )
F_275 ( V_292 ) ;
V_77 = 0 ;
if ( V_82 < 0x80 )
V_298 = F_18 ( V_289 ) ;
else
V_298 = F_19 ( V_289 ) ;
if ( ! V_298 ) {
if ( V_291 && V_82 == 0 ) {
V_82 = 0x7f ;
continue;
} else {
goto V_98;
}
}
V_77 = - V_132 ;
V_292 = F_276 ( V_298 , V_211 ) ;
if ( ! V_292 )
goto V_98;
V_293 = F_50 ( V_32 -> V_52 ) ;
if ( ! V_293 )
goto V_299;
V_77 = 0 ;
}
V_294 = V_292 [ V_297 ] ;
if ( ! F_24 ( & V_294 ) )
continue;
V_146 = F_32 ( & V_294 ) ;
if ( V_146 >= 0 && V_146 < F_162 ( V_32 -> V_64 ) )
F_167 ( V_146 , V_32 -> V_183 ) ;
F_20 ( & V_294 ) ;
F_22 ( & V_294 ) ;
V_293 [ V_297 ] = V_294 ;
}
V_290 [ V_295 + V_296 ] = V_293 ;
F_87 ( V_32 , V_293 , V_116 ) ;
V_299:
F_275 ( V_292 ) ;
V_98:
return V_77 ;
}
static int F_277 ( struct V_31 * V_32 )
{
struct V_22 * * V_300 ;
struct V_17 * V_301 ;
T_1 V_302 ;
int V_303 ;
unsigned long V_33 ;
V_24 V_304 ;
int V_81 , V_77 ;
bool V_305 , V_291 ;
V_304 = V_154 ( V_32 -> V_36 + V_138 ) ;
V_291 = ! ! ( V_304 & V_136 ) ;
V_305 = ! ! F_278 ( V_32 -> V_75 ) ;
if ( V_305 != V_291 )
return - V_44 ;
V_302 = V_304 & V_20 ;
if ( ! V_302 )
return - V_44 ;
V_301 = F_276 ( V_302 , V_211 ) ;
if ( ! V_301 )
return - V_132 ;
V_303 = V_291 ? 512 : 256 ;
V_77 = - V_132 ;
V_300 = F_279 ( V_303 * sizeof( void * ) , V_184 ) ;
if ( ! V_300 )
goto V_299;
for ( V_81 = 0 ; V_81 < 256 ; V_81 ++ ) {
V_77 = F_274 ( V_32 , & V_301 [ V_81 ] ,
V_300 , V_81 , V_291 ) ;
if ( V_77 ) {
F_118 ( L_43 ,
V_32 -> V_131 , V_81 ) ;
continue;
}
}
F_100 ( & V_32 -> V_107 , V_33 ) ;
for ( V_81 = 0 ; V_81 < 256 ; V_81 ++ ) {
int V_297 = V_291 ? V_81 * 2 : V_81 ;
V_24 V_29 ;
if ( V_300 [ V_297 ] ) {
V_29 = F_88 ( V_300 [ V_297 ] ) | 1 ;
V_32 -> V_17 [ V_81 ] . V_19 = V_29 ;
}
if ( ! V_291 || ! V_300 [ V_297 + 1 ] )
continue;
V_29 = F_88 ( V_300 [ V_297 + 1 ] ) | 1 ;
V_32 -> V_17 [ V_81 ] . V_21 = V_29 ;
}
F_101 ( & V_32 -> V_107 , V_33 ) ;
F_166 ( V_300 ) ;
F_87 ( V_32 , V_32 -> V_17 , V_211 ) ;
V_77 = 0 ;
V_299:
F_275 ( V_301 ) ;
return V_77 ;
}
static int T_3 F_280 ( void )
{
struct V_70 * V_71 ;
struct V_261 * V_262 ;
bool V_306 = false ;
struct V_88 * V_89 ;
struct V_31 * V_32 ;
int V_73 , V_77 ;
F_281 (drhd) {
if ( V_68 < V_307 ) {
V_68 ++ ;
continue;
}
F_282 ( L_44 , V_307 ) ;
}
if ( V_68 < V_307 )
V_68 = V_307 ;
V_69 = F_165 ( V_68 , sizeof( struct V_31 * ) ,
V_184 ) ;
if ( ! V_69 ) {
F_118 ( L_45 ) ;
V_77 = - V_132 ;
goto error;
}
V_308 = F_279 ( V_68 *
sizeof( struct V_309 ) , V_184 ) ;
if ( ! V_308 ) {
V_77 = - V_132 ;
goto V_310;
}
F_76 (iommu, drhd) {
V_69 [ V_32 -> V_185 ] = V_32 ;
F_270 ( V_32 ) ;
V_77 = F_161 ( V_32 ) ;
if ( V_77 )
goto V_311;
F_43 ( V_32 ) ;
if ( F_41 ( V_32 ) && ! F_283 () ) {
F_160 ( V_32 ) ;
F_42 ( V_32 ) ;
F_237 ( L_46 ,
V_32 -> V_131 ) ;
}
V_77 = F_117 ( V_32 ) ;
if ( V_77 )
goto V_311;
if ( F_41 ( V_32 ) ) {
F_48 ( L_47 ) ;
V_77 = F_277 ( V_32 ) ;
if ( V_77 ) {
F_118 ( L_48 ,
V_32 -> V_131 ) ;
F_160 ( V_32 ) ;
F_42 ( V_32 ) ;
} else {
F_48 ( L_49 ,
V_32 -> V_131 ) ;
V_306 = true ;
}
}
F_125 ( V_32 ) ;
F_119 ( V_32 ) ;
V_32 -> V_173 . V_218 ( V_32 , 0 , 0 , 0 , V_149 ) ;
V_32 -> V_173 . V_174 ( V_32 , 0 , 0 , 0 , V_158 ) ;
if ( ! F_284 ( V_32 -> V_75 ) )
V_256 = 0 ;
}
if ( V_312 )
V_269 |= V_275 ;
#ifdef F_285
V_269 |= V_274 ;
#endif
if ( V_269 ) {
V_77 = F_245 ( V_256 ) ;
if ( V_77 )
goto V_311;
}
F_286 () ;
if ( V_306 )
goto V_313;
if ( V_269 ) {
V_77 = F_266 ( V_256 ) ;
if ( V_77 ) {
F_217 ( L_50 ) ;
goto V_311;
}
}
F_48 ( L_51 ) ;
F_255 (rmrr) {
F_96 (rmrr->devices, rmrr->devices_cnt,
i, dev) {
V_77 = F_241 ( V_262 , V_89 ) ;
if ( V_77 )
F_118 ( L_52 ) ;
}
}
F_242 () ;
V_313:
F_287 (iommu, drhd) {
if ( V_71 -> V_314 ) {
if ( V_315 )
F_158 ( V_32 ) ;
continue;
}
F_125 ( V_32 ) ;
V_77 = F_288 ( V_32 ) ;
if ( V_77 )
goto V_311;
if ( ! F_41 ( V_32 ) )
F_159 ( V_32 ) ;
F_158 ( V_32 ) ;
}
return 0 ;
V_311:
F_76 (iommu, drhd) {
F_168 ( V_32 ) ;
F_172 ( V_32 ) ;
}
F_166 ( V_308 ) ;
V_310:
F_166 ( V_69 ) ;
error:
return V_77 ;
}
static struct V_194 * F_289 ( struct V_88 * V_89 ,
struct V_39 * V_42 ,
unsigned long V_316 , T_6 V_279 )
{
struct V_194 * V_194 = NULL ;
V_279 = F_3 ( T_6 , F_290 ( V_42 -> V_127 ) , V_279 ) ;
if ( ! V_47 && V_279 > F_291 ( 32 ) ) {
V_194 = F_292 ( & V_42 -> V_208 , V_316 ,
F_189 ( F_291 ( 32 ) ) , 1 ) ;
if ( V_194 )
return V_194 ;
}
V_194 = F_292 ( & V_42 -> V_208 , V_316 , F_189 ( V_279 ) , 1 ) ;
if ( F_203 ( ! V_194 ) ) {
F_118 ( L_53 ,
V_316 , F_238 ( V_89 ) ) ;
return NULL ;
}
return V_194 ;
}
static struct V_39 * F_293 ( struct V_88 * V_89 )
{
struct V_39 * V_42 ;
int V_77 ;
V_42 = F_234 ( V_89 , V_65 ) ;
if ( ! V_42 ) {
F_118 ( L_54 ,
F_238 ( V_89 ) ) ;
return NULL ;
}
if ( F_203 ( ! F_209 ( V_89 ) ) ) {
V_77 = F_206 ( V_42 , V_89 , V_214 ) ;
if ( V_77 ) {
F_118 ( L_55 ,
F_238 ( V_89 ) ) ;
return NULL ;
}
}
return V_42 ;
}
static inline struct V_39 * F_294 ( struct V_88 * V_89 )
{
struct V_163 * V_164 ;
V_164 = V_89 -> V_90 . V_32 ;
if ( F_251 ( V_164 ) )
return V_164 -> V_42 ;
return F_293 ( V_89 ) ;
}
static int F_295 ( struct V_88 * V_89 )
{
int V_72 ;
if ( F_89 ( V_89 ) )
return 1 ;
if ( ! V_269 )
return 0 ;
V_72 = F_250 ( V_89 ) ;
if ( V_72 ) {
if ( F_259 ( V_89 , 0 ) )
return 1 ;
else {
F_253 ( V_255 , V_89 ) ;
F_48 ( L_56 ,
F_238 ( V_89 ) ) ;
return 0 ;
}
} else {
if ( F_259 ( V_89 , 0 ) ) {
int V_77 ;
V_77 = F_252 ( V_255 , V_89 ,
V_256 ?
V_213 :
V_214 ) ;
if ( ! V_77 ) {
F_48 ( L_57 ,
F_238 ( V_89 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_244 F_296 ( struct V_88 * V_89 , T_1 V_317 ,
T_8 V_106 , int V_318 , V_24 V_279 )
{
struct V_39 * V_42 ;
T_1 V_319 ;
struct V_194 * V_194 ;
int V_236 = 0 ;
int V_77 ;
struct V_31 * V_32 ;
unsigned long V_320 = V_317 >> V_11 ;
F_70 ( V_318 == V_321 ) ;
if ( F_295 ( V_89 ) )
return V_317 ;
V_42 = F_294 ( V_89 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_69 ( V_42 ) ;
V_106 = F_210 ( V_317 , V_106 ) ;
V_194 = F_289 ( V_89 , V_42 , F_12 ( V_106 ) , V_279 ) ;
if ( ! V_194 )
goto error;
if ( V_318 == V_322 || V_318 == V_323 || \
! F_297 ( V_32 -> V_64 ) )
V_236 |= V_117 ;
if ( V_318 == V_324 || V_318 == V_323 )
V_236 |= V_118 ;
V_77 = F_222 ( V_42 , F_13 ( V_194 -> V_325 ) ,
F_13 ( V_320 ) , V_106 , V_236 ) ;
if ( V_77 )
goto error;
if ( F_157 ( V_32 -> V_64 ) )
F_152 ( V_32 , V_42 -> V_188 , F_13 ( V_194 -> V_325 ) , V_106 , 0 , 1 ) ;
else
F_125 ( V_32 ) ;
V_319 = ( T_1 ) V_194 -> V_325 << V_11 ;
V_319 += V_317 & ~ V_225 ;
return V_319 ;
error:
if ( V_194 )
F_298 ( & V_42 -> V_208 , V_194 ) ;
F_118 ( L_58 ,
F_238 ( V_89 ) , V_106 , ( unsigned long long ) V_317 , V_318 ) ;
return 0 ;
}
static V_244 F_299 ( struct V_88 * V_89 , struct V_14 * V_14 ,
unsigned long V_111 , T_8 V_106 ,
enum V_326 V_318 ,
struct V_327 * V_328 )
{
return F_296 ( V_89 , F_214 ( V_14 ) + V_111 , V_106 ,
V_318 , * V_89 -> V_279 ) ;
}
static void F_300 ( void )
{
int V_73 , V_329 ;
V_330 = 0 ;
for ( V_73 = 0 ; V_73 < V_68 ; V_73 ++ ) {
struct V_31 * V_32 = V_69 [ V_73 ] ;
if ( ! V_32 )
continue;
if ( ! V_308 [ V_73 ] . V_126 )
continue;
if ( ! F_157 ( V_32 -> V_64 ) )
V_32 -> V_173 . V_174 ( V_32 , 0 , 0 , 0 ,
V_158 ) ;
for ( V_329 = 0 ; V_329 < V_308 [ V_73 ] . V_126 ; V_329 ++ ) {
unsigned long V_78 ;
struct V_194 * V_194 = V_308 [ V_73 ] . V_194 [ V_329 ] ;
struct V_39 * V_42 = V_308 [ V_73 ] . V_42 [ V_329 ] ;
if ( F_157 ( V_32 -> V_64 ) )
F_152 ( V_32 , V_42 -> V_188 ,
V_194 -> V_325 , F_301 ( V_194 ) ,
! V_308 [ V_73 ] . V_128 [ V_329 ] , 0 ) ;
else {
V_78 = F_153 ( F_13 ( F_301 ( V_194 ) ) ) ;
F_149 ( V_308 [ V_73 ] . V_42 [ V_329 ] ,
( T_6 ) V_194 -> V_325 << V_11 , V_78 ) ;
}
F_298 ( & V_308 [ V_73 ] . V_42 [ V_329 ] -> V_208 , V_194 ) ;
if ( V_308 [ V_73 ] . V_128 [ V_329 ] )
F_116 ( V_308 [ V_73 ] . V_128 [ V_329 ] ) ;
}
V_308 [ V_73 ] . V_126 = 0 ;
}
V_331 = 0 ;
}
static void F_197 ( unsigned long V_223 )
{
unsigned long V_33 ;
F_100 ( & V_332 , V_33 ) ;
F_300 () ;
F_101 ( & V_332 , V_33 ) ;
}
static void F_302 ( struct V_39 * V_41 , struct V_194 * V_194 , struct V_14 * V_128 )
{
unsigned long V_33 ;
int V_126 , V_66 ;
struct V_31 * V_32 ;
F_100 ( & V_332 , V_33 ) ;
if ( V_331 == V_333 )
F_300 () ;
V_32 = F_69 ( V_41 ) ;
V_66 = V_32 -> V_185 ;
V_126 = V_308 [ V_66 ] . V_126 ;
V_308 [ V_66 ] . V_42 [ V_126 ] = V_41 ;
V_308 [ V_66 ] . V_194 [ V_126 ] = V_194 ;
V_308 [ V_66 ] . V_128 [ V_126 ] = V_128 ;
V_308 [ V_66 ] . V_126 ++ ;
if ( ! V_330 ) {
F_303 ( & V_334 , V_335 + F_304 ( 10 ) ) ;
V_330 = 1 ;
}
V_331 ++ ;
F_101 ( & V_332 , V_33 ) ;
}
static void F_305 ( struct V_88 * V_89 , V_244 V_336 )
{
struct V_39 * V_42 ;
unsigned long V_121 , V_122 ;
struct V_194 * V_194 ;
struct V_31 * V_32 ;
struct V_14 * V_128 ;
if ( F_295 ( V_89 ) )
return;
V_42 = F_229 ( V_89 ) ;
F_70 ( ! V_42 ) ;
V_32 = F_69 ( V_42 ) ;
V_194 = F_306 ( & V_42 -> V_208 , F_189 ( V_336 ) ) ;
if ( F_307 ( ! V_194 , L_59 ,
( unsigned long long ) V_336 ) )
return;
V_121 = F_13 ( V_194 -> V_325 ) ;
V_122 = F_13 ( V_194 -> V_337 + 1 ) - 1 ;
F_138 ( L_60 ,
F_238 ( V_89 ) , V_121 , V_122 ) ;
V_128 = F_115 ( V_42 , V_121 , V_122 ) ;
if ( V_48 ) {
F_152 ( V_32 , V_42 -> V_188 , V_121 ,
V_122 - V_121 + 1 , ! V_128 , 0 ) ;
F_298 ( & V_42 -> V_208 , V_194 ) ;
F_116 ( V_128 ) ;
} else {
F_302 ( V_42 , V_194 , V_128 ) ;
}
}
static void F_308 ( struct V_88 * V_89 , V_244 V_336 ,
T_8 V_106 , enum V_326 V_318 ,
struct V_327 * V_328 )
{
F_305 ( V_89 , V_336 ) ;
}
static void * F_309 ( struct V_88 * V_89 , T_8 V_106 ,
V_244 * V_338 , T_9 V_33 ,
struct V_327 * V_328 )
{
struct V_14 * V_14 = NULL ;
int V_339 ;
V_106 = F_211 ( V_106 ) ;
V_339 = F_310 ( V_106 ) ;
if ( ! F_295 ( V_89 ) )
V_33 &= ~ ( V_340 | V_341 ) ;
else if ( V_89 -> V_280 < F_264 ( V_89 ) ) {
if ( V_89 -> V_280 < F_291 ( 32 ) )
V_33 |= V_340 ;
else
V_33 |= V_341 ;
}
if ( V_33 & V_342 ) {
unsigned int V_192 = V_106 >> V_11 ;
V_14 = F_311 ( V_89 , V_192 , V_339 ) ;
if ( V_14 && F_295 ( V_89 ) &&
F_214 ( V_14 ) + V_106 > V_89 -> V_280 ) {
F_312 ( V_89 , V_14 , V_192 ) ;
V_14 = NULL ;
}
}
if ( ! V_14 )
V_14 = F_313 ( V_33 , V_339 ) ;
if ( ! V_14 )
return NULL ;
memset ( F_52 ( V_14 ) , 0 , V_106 ) ;
* V_338 = F_296 ( V_89 , F_214 ( V_14 ) , V_106 ,
V_323 ,
V_89 -> V_280 ) ;
if ( * V_338 )
return F_52 ( V_14 ) ;
if ( ! F_312 ( V_89 , V_14 , V_106 >> V_11 ) )
F_314 ( V_14 , V_339 ) ;
return NULL ;
}
static void F_315 ( struct V_88 * V_89 , T_8 V_106 , void * V_53 ,
V_244 V_338 , struct V_327 * V_328 )
{
int V_339 ;
struct V_14 * V_14 = F_17 ( V_53 ) ;
V_106 = F_211 ( V_106 ) ;
V_339 = F_310 ( V_106 ) ;
F_305 ( V_89 , V_338 ) ;
if ( ! F_312 ( V_89 , V_14 , V_106 >> V_11 ) )
F_314 ( V_14 , V_339 ) ;
}
static void F_316 ( struct V_88 * V_89 , struct V_232 * V_343 ,
int V_344 , enum V_326 V_318 ,
struct V_327 * V_328 )
{
F_305 ( V_89 , V_343 [ 0 ] . V_243 ) ;
}
static int F_317 ( struct V_88 * V_345 ,
struct V_232 * V_343 , int V_344 , int V_318 )
{
int V_73 ;
struct V_232 * V_233 ;
F_318 (sglist, sg, nelems, i) {
F_70 ( ! F_215 ( V_233 ) ) ;
V_233 -> V_243 = F_214 ( F_215 ( V_233 ) ) + V_233 -> V_111 ;
V_233 -> V_245 = V_233 -> V_242 ;
}
return V_344 ;
}
static int F_319 ( struct V_88 * V_89 , struct V_232 * V_343 , int V_344 ,
enum V_326 V_318 , struct V_327 * V_328 )
{
int V_73 ;
struct V_39 * V_42 ;
T_8 V_106 = 0 ;
int V_236 = 0 ;
struct V_194 * V_194 = NULL ;
int V_77 ;
struct V_232 * V_233 ;
unsigned long V_346 ;
struct V_31 * V_32 ;
F_70 ( V_318 == V_321 ) ;
if ( F_295 ( V_89 ) )
return F_317 ( V_89 , V_343 , V_344 , V_318 ) ;
V_42 = F_294 ( V_89 ) ;
if ( ! V_42 )
return 0 ;
V_32 = F_69 ( V_42 ) ;
F_318 (sglist, sg, nelems, i)
V_106 += F_210 ( V_233 -> V_111 , V_233 -> V_242 ) ;
V_194 = F_289 ( V_89 , V_42 , F_12 ( V_106 ) ,
* V_89 -> V_279 ) ;
if ( ! V_194 ) {
V_343 -> V_245 = 0 ;
return 0 ;
}
if ( V_318 == V_322 || V_318 == V_323 || \
! F_297 ( V_32 -> V_64 ) )
V_236 |= V_117 ;
if ( V_318 == V_324 || V_318 == V_323 )
V_236 |= V_118 ;
V_346 = F_13 ( V_194 -> V_325 ) ;
V_77 = F_221 ( V_42 , V_346 , V_343 , V_106 , V_236 ) ;
if ( F_203 ( V_77 ) ) {
F_110 ( V_42 , V_346 ,
V_346 + V_106 - 1 ) ;
F_298 ( & V_42 -> V_208 , V_194 ) ;
return 0 ;
}
if ( F_157 ( V_32 -> V_64 ) )
F_152 ( V_32 , V_42 -> V_188 , V_346 , V_106 , 0 , 1 ) ;
else
F_125 ( V_32 ) ;
return V_344 ;
}
static int F_320 ( struct V_88 * V_89 , V_244 V_347 )
{
return ! V_347 ;
}
static inline int F_321 ( void )
{
int V_77 = 0 ;
V_56 = F_322 ( L_61 ,
sizeof( struct V_39 ) ,
0 ,
V_348 ,
NULL ) ;
if ( ! V_56 ) {
F_118 ( L_62 ) ;
V_77 = - V_132 ;
}
return V_77 ;
}
static inline int F_323 ( void )
{
int V_77 = 0 ;
V_57 = F_322 ( L_63 ,
sizeof( struct V_163 ) ,
0 ,
V_348 ,
NULL ) ;
if ( ! V_57 ) {
F_118 ( L_64 ) ;
V_77 = - V_132 ;
}
return V_77 ;
}
static int T_3 F_324 ( void )
{
int V_77 ;
V_77 = F_325 () ;
if ( V_77 )
return V_77 ;
V_77 = F_321 () ;
if ( V_77 )
goto V_349;
V_77 = F_323 () ;
if ( ! V_77 )
return V_77 ;
F_326 ( V_56 ) ;
V_349:
F_327 () ;
return - V_132 ;
}
static void T_3 F_328 ( void )
{
F_326 ( V_57 ) ;
F_326 ( V_56 ) ;
F_327 () ;
}
static void F_329 ( struct V_93 * V_95 )
{
struct V_70 * V_71 ;
T_2 V_350 ;
int V_351 ;
V_351 = F_330 ( V_95 -> V_81 , F_331 ( 0 , 0 ) , 0xb0 , & V_350 ) ;
if ( V_351 ) {
F_332 ( & V_95 -> V_89 , L_65 ) ;
return;
}
V_350 &= 0xffff0000 ;
V_71 = F_333 ( V_95 ) ;
if ( F_334 ( ! V_71 || V_71 -> V_352 - V_350 != 0xa000 ,
V_353 ,
L_66 ) )
V_95 -> V_89 . V_90 . V_32 = V_91 ;
}
static void T_3 F_335 ( void )
{
struct V_70 * V_71 ;
struct V_88 * V_89 ;
int V_73 ;
F_281 (drhd) {
if ( ! V_71 -> V_104 ) {
F_96 (drhd->devices,
drhd->devices_cnt, i, dev)
break;
if ( V_73 == V_71 -> V_354 )
V_71 -> V_314 = 1 ;
}
}
F_336 (drhd) {
if ( V_71 -> V_104 )
continue;
F_96 (drhd->devices,
drhd->devices_cnt, i, dev)
if ( ! F_91 ( V_89 ) || ! F_258 ( F_92 ( V_89 ) ) )
break;
if ( V_73 < V_71 -> V_354 )
continue;
if ( V_46 ) {
V_355 = 1 ;
} else {
V_71 -> V_314 = 1 ;
F_96 (drhd->devices,
drhd->devices_cnt, i, dev)
V_89 -> V_90 . V_32 = V_91 ;
}
}
}
static int F_337 ( void )
{
struct V_70 * V_71 ;
struct V_31 * V_32 = NULL ;
F_76 (iommu, drhd)
if ( V_32 -> V_165 )
F_338 ( V_32 ) ;
F_287 (iommu, drhd) {
if ( V_71 -> V_314 ) {
if ( V_315 )
F_158 ( V_32 ) ;
continue;
}
F_125 ( V_32 ) ;
F_119 ( V_32 ) ;
V_32 -> V_173 . V_218 ( V_32 , 0 , 0 , 0 ,
V_149 ) ;
V_32 -> V_173 . V_174 ( V_32 , 0 , 0 , 0 , V_158 ) ;
F_159 ( V_32 ) ;
F_158 ( V_32 ) ;
}
return 0 ;
}
static void F_339 ( void )
{
struct V_70 * V_71 ;
struct V_31 * V_32 ;
F_76 (iommu, drhd) {
V_32 -> V_173 . V_218 ( V_32 , 0 , 0 , 0 ,
V_149 ) ;
V_32 -> V_173 . V_174 ( V_32 , 0 , 0 , 0 ,
V_158 ) ;
}
}
static int F_340 ( void )
{
struct V_70 * V_71 ;
struct V_31 * V_32 = NULL ;
unsigned long V_135 ;
F_76 (iommu, drhd) {
V_32 -> V_356 = F_279 ( sizeof( T_2 ) * V_357 ,
V_54 ) ;
if ( ! V_32 -> V_356 )
goto V_358;
}
F_339 () ;
F_76 (iommu, drhd) {
F_160 ( V_32 ) ;
F_120 ( & V_32 -> V_137 , V_135 ) ;
V_32 -> V_356 [ V_359 ] =
F_44 ( V_32 -> V_36 + V_360 ) ;
V_32 -> V_356 [ V_361 ] =
F_44 ( V_32 -> V_36 + V_362 ) ;
V_32 -> V_356 [ V_363 ] =
F_44 ( V_32 -> V_36 + V_364 ) ;
V_32 -> V_356 [ V_365 ] =
F_44 ( V_32 -> V_36 + V_366 ) ;
F_124 ( & V_32 -> V_137 , V_135 ) ;
}
return 0 ;
V_358:
F_76 (iommu, drhd)
F_166 ( V_32 -> V_356 ) ;
return - V_132 ;
}
static void F_341 ( void )
{
struct V_70 * V_71 ;
struct V_31 * V_32 = NULL ;
unsigned long V_135 ;
if ( F_337 () ) {
if ( V_315 )
F_342 ( L_67 ) ;
else
F_239 ( 1 , L_68 ) ;
return;
}
F_76 (iommu, drhd) {
F_120 ( & V_32 -> V_137 , V_135 ) ;
F_122 ( V_32 -> V_356 [ V_359 ] ,
V_32 -> V_36 + V_360 ) ;
F_122 ( V_32 -> V_356 [ V_361 ] ,
V_32 -> V_36 + V_362 ) ;
F_122 ( V_32 -> V_356 [ V_363 ] ,
V_32 -> V_36 + V_364 ) ;
F_122 ( V_32 -> V_356 [ V_365 ] ,
V_32 -> V_36 + V_366 ) ;
F_124 ( & V_32 -> V_137 , V_135 ) ;
}
F_76 (iommu, drhd)
F_166 ( V_32 -> V_356 ) ;
}
static void T_3 F_343 ( void )
{
F_344 ( & V_367 ) ;
}
static inline void F_343 ( void ) {}
int T_3 F_345 ( struct V_368 * V_369 , void * V_370 )
{
struct V_371 * V_262 ;
struct V_261 * V_372 ;
V_372 = F_279 ( sizeof( * V_372 ) , V_184 ) ;
if ( ! V_372 )
return - V_132 ;
V_372 -> V_373 = V_369 ;
V_262 = (struct V_371 * ) V_369 ;
V_372 -> V_263 = V_262 -> V_263 ;
V_372 -> V_264 = V_262 -> V_264 ;
V_372 -> V_97 = F_346 ( ( void * ) ( V_262 + 1 ) ,
( ( void * ) V_262 ) + V_262 -> V_369 . V_242 ,
& V_372 -> V_354 ) ;
if ( V_372 -> V_354 && V_372 -> V_97 == NULL ) {
F_166 ( V_372 ) ;
return - V_132 ;
}
F_232 ( & V_372 -> V_374 , & V_375 ) ;
return 0 ;
}
static struct V_376 * F_347 ( struct V_377 * V_378 )
{
struct V_376 * V_379 ;
struct V_377 * V_92 ;
F_348 (atsru, &dmar_atsr_units, list) {
V_92 = (struct V_377 * ) V_379 -> V_373 ;
if ( V_378 -> V_96 != V_92 -> V_96 )
continue;
if ( V_378 -> V_369 . V_242 != V_92 -> V_369 . V_242 )
continue;
if ( memcmp ( V_378 , V_92 , V_378 -> V_369 . V_242 ) == 0 )
return V_379 ;
}
return NULL ;
}
int F_349 ( struct V_368 * V_373 , void * V_370 )
{
struct V_377 * V_378 ;
struct V_376 * V_379 ;
if ( V_380 != V_381 && ! V_382 )
return 0 ;
V_378 = F_46 ( V_373 , struct V_377 , V_369 ) ;
V_379 = F_347 ( V_378 ) ;
if ( V_379 )
return 0 ;
V_379 = F_279 ( sizeof( * V_379 ) + V_373 -> V_242 , V_184 ) ;
if ( ! V_379 )
return - V_132 ;
V_379 -> V_373 = ( void * ) ( V_379 + 1 ) ;
memcpy ( V_379 -> V_373 , V_373 , V_373 -> V_242 ) ;
V_379 -> V_104 = V_378 -> V_33 & 0x1 ;
if ( ! V_379 -> V_104 ) {
V_379 -> V_97 = F_346 ( ( void * ) ( V_378 + 1 ) ,
( void * ) V_378 + V_378 -> V_369 . V_242 ,
& V_379 -> V_354 ) ;
if ( V_379 -> V_354 && V_379 -> V_97 == NULL ) {
F_166 ( V_379 ) ;
return - V_132 ;
}
}
F_350 ( & V_379 -> V_374 , & V_383 ) ;
return 0 ;
}
static void F_351 ( struct V_376 * V_379 )
{
F_352 ( & V_379 -> V_97 , & V_379 -> V_354 ) ;
F_166 ( V_379 ) ;
}
int F_353 ( struct V_368 * V_373 , void * V_370 )
{
struct V_377 * V_378 ;
struct V_376 * V_379 ;
V_378 = F_46 ( V_373 , struct V_377 , V_369 ) ;
V_379 = F_347 ( V_378 ) ;
if ( V_379 ) {
F_354 ( & V_379 -> V_374 ) ;
F_355 () ;
F_351 ( V_379 ) ;
}
return 0 ;
}
int F_356 ( struct V_368 * V_373 , void * V_370 )
{
int V_73 ;
struct V_88 * V_89 ;
struct V_377 * V_378 ;
struct V_376 * V_379 ;
V_378 = F_46 ( V_373 , struct V_377 , V_369 ) ;
V_379 = F_347 ( V_378 ) ;
if ( ! V_379 )
return 0 ;
if ( ! V_379 -> V_104 && V_379 -> V_97 && V_379 -> V_354 )
F_96 (atsru->devices, atsru->devices_cnt,
i, dev)
return - V_271 ;
return 0 ;
}
static int F_357 ( struct V_70 * V_384 )
{
int V_385 , V_77 = 0 ;
struct V_31 * V_32 = V_384 -> V_32 ;
if ( V_69 [ V_32 -> V_185 ] )
return 0 ;
if ( V_256 && ! F_284 ( V_32 -> V_75 ) ) {
F_237 ( L_69 ,
V_32 -> V_131 ) ;
return - V_386 ;
}
if ( ! F_79 ( V_32 -> V_75 ) &&
F_78 ( V_32 ) ) {
F_237 ( L_70 ,
V_32 -> V_131 ) ;
return - V_386 ;
}
V_385 = F_80 ( V_32 ) - 1 ;
if ( V_385 >= 0 && ! ( F_81 ( V_32 -> V_64 ) & ( 1 << V_385 ) ) ) {
F_237 ( L_71 ,
V_32 -> V_131 ) ;
return - V_386 ;
}
if ( V_32 -> V_139 & V_180 )
F_160 ( V_32 ) ;
V_69 [ V_32 -> V_185 ] = V_32 ;
V_77 = F_161 ( V_32 ) ;
if ( V_77 == 0 )
V_77 = F_117 ( V_32 ) ;
if ( V_77 )
goto V_98;
if ( V_384 -> V_314 ) {
if ( V_315 )
F_158 ( V_32 ) ;
return 0 ;
}
F_270 ( V_32 ) ;
F_125 ( V_32 ) ;
V_77 = F_288 ( V_32 ) ;
if ( V_77 )
goto V_387;
F_119 ( V_32 ) ;
V_32 -> V_173 . V_218 ( V_32 , 0 , 0 , 0 , V_149 ) ;
V_32 -> V_173 . V_174 ( V_32 , 0 , 0 , 0 , V_158 ) ;
F_159 ( V_32 ) ;
if ( V_255 ) {
V_77 = F_179 ( V_255 , V_32 ) ;
if ( V_77 < 0 || V_255 -> V_188 != V_77 )
goto V_387;
F_182 ( V_255 , V_32 ) ;
}
F_158 ( V_32 ) ;
return 0 ;
V_387:
F_168 ( V_32 ) ;
V_98:
F_172 ( V_32 ) ;
return V_77 ;
}
int F_358 ( struct V_70 * V_384 , bool V_388 )
{
int V_77 = 0 ;
struct V_31 * V_32 = V_384 -> V_32 ;
if ( ! V_382 )
return 0 ;
if ( V_32 == NULL )
return - V_44 ;
if ( V_388 ) {
V_77 = F_357 ( V_384 ) ;
} else {
F_168 ( V_32 ) ;
F_172 ( V_32 ) ;
}
return V_77 ;
}
static void F_359 ( void )
{
struct V_261 * V_372 , * V_389 ;
struct V_376 * V_379 , * V_390 ;
F_227 (rmrru, rmrr_n, &dmar_rmrr_units, list) {
F_226 ( & V_372 -> V_374 ) ;
F_352 ( & V_372 -> V_97 , & V_372 -> V_354 ) ;
F_166 ( V_372 ) ;
}
F_227 (atsru, atsr_n, &dmar_atsr_units, list) {
F_226 ( & V_379 -> V_374 ) ;
F_351 ( V_379 ) ;
}
}
int F_143 ( struct V_93 * V_89 )
{
int V_73 , V_77 = 1 ;
struct V_391 * V_81 ;
struct V_93 * V_392 = NULL ;
struct V_88 * V_92 ;
struct V_377 * V_378 ;
struct V_376 * V_379 ;
V_89 = F_360 ( V_89 ) ;
for ( V_81 = V_89 -> V_81 ; V_81 ; V_81 = V_81 -> V_110 ) {
V_392 = V_81 -> V_393 ;
if ( ! V_392 || ! F_261 ( V_392 ) ||
F_263 ( V_392 ) == V_278 )
return 0 ;
if ( F_263 ( V_392 ) == V_394 )
break;
}
if ( ! V_392 )
return 0 ;
F_75 () ;
F_348 (atsru, &dmar_atsr_units, list) {
V_378 = F_46 ( V_379 -> V_373 , struct V_377 , V_369 ) ;
if ( V_378 -> V_96 != F_93 ( V_89 -> V_81 ) )
continue;
F_361 (atsru->devices, atsru->devices_cnt, i, tmp)
if ( V_92 == & V_392 -> V_89 )
goto V_98;
if ( V_379 -> V_104 )
goto V_98;
}
V_77 = 0 ;
V_98:
F_77 () ;
return V_77 ;
}
int F_362 ( struct V_395 * V_164 )
{
int V_77 = 0 ;
struct V_261 * V_372 ;
struct V_376 * V_379 ;
struct V_377 * V_378 ;
struct V_371 * V_262 ;
if ( ! V_382 && V_380 != V_381 )
return 0 ;
F_141 (rmrru, &dmar_rmrr_units, list) {
V_262 = F_46 ( V_372 -> V_373 ,
struct V_371 , V_369 ) ;
if ( V_164 -> V_396 == V_397 ) {
V_77 = F_363 ( V_164 , ( void * ) ( V_262 + 1 ) ,
( ( void * ) V_262 ) + V_262 -> V_369 . V_242 ,
V_262 -> V_96 , V_372 -> V_97 ,
V_372 -> V_354 ) ;
if( V_77 < 0 )
return V_77 ;
} else if ( V_164 -> V_396 == V_398 ) {
F_364 ( V_164 , V_262 -> V_96 ,
V_372 -> V_97 , V_372 -> V_354 ) ;
}
}
F_141 (atsru, &dmar_atsr_units, list) {
if ( V_379 -> V_104 )
continue;
V_378 = F_46 ( V_379 -> V_373 , struct V_377 , V_369 ) ;
if ( V_164 -> V_396 == V_397 ) {
V_77 = F_363 ( V_164 , ( void * ) ( V_378 + 1 ) ,
( void * ) V_378 + V_378 -> V_369 . V_242 ,
V_378 -> V_96 , V_379 -> V_97 ,
V_379 -> V_354 ) ;
if ( V_77 > 0 )
break;
else if( V_77 < 0 )
return V_77 ;
} else if ( V_164 -> V_396 == V_398 ) {
if ( F_364 ( V_164 , V_378 -> V_96 ,
V_379 -> V_97 , V_379 -> V_354 ) )
break;
}
}
return 0 ;
}
static int F_365 ( struct V_399 * V_400 ,
unsigned long V_401 , void * V_223 )
{
struct V_88 * V_89 = V_223 ;
struct V_39 * V_42 ;
if ( F_89 ( V_89 ) )
return 0 ;
if ( V_401 != V_402 )
return 0 ;
V_42 = F_229 ( V_89 ) ;
if ( ! V_42 )
return 0 ;
F_366 ( & V_403 ) ;
F_253 ( V_42 , V_89 ) ;
if ( ! F_62 ( V_42 ) && F_367 ( & V_42 -> V_97 ) )
F_171 ( V_42 ) ;
F_368 ( & V_403 ) ;
return 0 ;
}
static int F_369 ( struct V_399 * V_400 ,
unsigned long V_29 , void * V_404 )
{
struct V_405 * V_406 = V_404 ;
unsigned long long V_207 , V_102 ;
unsigned long V_346 , V_254 ;
switch ( V_29 ) {
case V_407 :
V_207 = V_406 -> V_121 << V_11 ;
V_102 = ( ( V_406 -> V_121 + V_406 -> V_235 ) << V_11 ) - 1 ;
if ( F_235 ( V_255 , V_207 , V_102 ) ) {
F_237 ( L_72 ,
V_207 , V_102 ) ;
return V_408 ;
}
break;
case V_409 :
case V_410 :
V_346 = F_13 ( V_406 -> V_121 ) ;
V_254 = F_13 ( V_406 -> V_121 + V_406 -> V_235 - 1 ) ;
while ( V_346 <= V_254 ) {
struct V_194 * V_194 ;
struct V_70 * V_71 ;
struct V_31 * V_32 ;
struct V_14 * V_128 ;
V_194 = F_306 ( & V_255 -> V_208 , V_346 ) ;
if ( V_194 == NULL ) {
F_138 ( L_73 ,
V_346 ) ;
break;
}
V_194 = F_370 ( & V_255 -> V_208 , V_194 ,
V_346 , V_254 ) ;
if ( V_194 == NULL ) {
F_237 ( L_74 ,
V_346 , V_254 ) ;
return V_408 ;
}
V_128 = F_115 ( V_255 , V_194 -> V_325 ,
V_194 -> V_337 ) ;
F_75 () ;
F_76 (iommu, drhd)
F_152 ( V_32 , V_255 -> V_188 ,
V_194 -> V_325 , F_301 ( V_194 ) ,
! V_128 , 0 ) ;
F_77 () ;
F_116 ( V_128 ) ;
V_346 = V_194 -> V_337 + 1 ;
F_371 ( V_194 ) ;
}
break;
}
return V_411 ;
}
static T_10 F_372 ( struct V_88 * V_89 ,
struct V_412 * V_413 ,
char * V_414 )
{
struct V_31 * V_32 = F_373 ( V_89 ) ;
T_2 V_415 = F_44 ( V_32 -> V_36 + V_416 ) ;
return sprintf ( V_414 , L_75 ,
F_374 ( V_415 ) , F_375 ( V_415 ) ) ;
}
static T_10 F_376 ( struct V_88 * V_89 ,
struct V_412 * V_413 ,
char * V_414 )
{
struct V_31 * V_32 = F_373 ( V_89 ) ;
return sprintf ( V_414 , L_76 , V_32 -> V_417 ) ;
}
static T_10 F_377 ( struct V_88 * V_89 ,
struct V_412 * V_413 ,
char * V_414 )
{
struct V_31 * V_32 = F_373 ( V_89 ) ;
return sprintf ( V_414 , L_76 , V_32 -> V_64 ) ;
}
static T_10 F_378 ( struct V_88 * V_89 ,
struct V_412 * V_413 ,
char * V_414 )
{
struct V_31 * V_32 = F_373 ( V_89 ) ;
return sprintf ( V_414 , L_76 , V_32 -> V_75 ) ;
}
int T_3 F_379 ( void )
{
int V_77 = - V_202 ;
struct V_70 * V_71 ;
struct V_31 * V_32 ;
V_315 = F_380 () ;
if ( F_324 () ) {
if ( V_315 )
F_342 ( L_77 ) ;
return - V_132 ;
}
F_381 ( & V_403 ) ;
if ( F_382 () ) {
if ( V_315 )
F_342 ( L_78 ) ;
goto V_418;
}
if ( F_383 () < 0 ) {
if ( V_315 )
F_342 ( L_79 ) ;
goto V_418;
}
if ( V_419 || V_45 )
goto V_418;
if ( F_367 ( & V_375 ) )
F_48 ( L_80 ) ;
if ( F_367 ( & V_383 ) )
F_48 ( L_81 ) ;
if ( F_185 () ) {
if ( V_315 )
F_342 ( L_82 ) ;
goto V_420;
}
F_335 () ;
V_77 = F_280 () ;
if ( V_77 ) {
if ( V_315 )
F_342 ( L_83 ) ;
F_118 ( L_84 ) ;
goto V_420;
}
F_384 ( & V_403 ) ;
F_48 ( L_85 ) ;
F_385 ( & V_334 ) ;
#ifdef F_386
V_421 = 0 ;
#endif
V_422 = & V_423 ;
F_343 () ;
F_76 (iommu, drhd)
V_32 -> V_424 = F_387 ( NULL , V_32 ,
V_425 ,
V_32 -> V_131 ) ;
F_388 ( & V_426 , & V_427 ) ;
F_389 ( & V_426 , & V_428 ) ;
if ( V_255 && ! V_256 )
F_390 ( & V_429 ) ;
V_382 = 1 ;
return 0 ;
V_420:
F_199 ( & V_195 ) ;
V_418:
F_359 () ;
F_384 ( & V_403 ) ;
F_328 () ;
return V_77 ;
}
static int F_391 ( struct V_93 * V_95 , T_5 V_220 , void * V_221 )
{
struct V_31 * V_32 = V_221 ;
F_223 ( V_32 , F_205 ( V_220 ) , V_220 & 0xff ) ;
return 0 ;
}
static void F_228 ( struct V_31 * V_32 ,
struct V_88 * V_89 )
{
if ( ! V_32 || ! V_89 || ! F_91 ( V_89 ) )
return;
F_207 ( F_92 ( V_89 ) , & F_391 , V_32 ) ;
}
static void F_253 ( struct V_39 * V_42 ,
struct V_88 * V_89 )
{
struct V_163 * V_164 , * V_92 ;
struct V_31 * V_32 ;
unsigned long V_33 ;
bool V_72 = false ;
T_4 V_81 , V_82 ;
V_32 = F_90 ( V_89 , & V_81 , & V_82 ) ;
if ( ! V_32 )
return;
F_100 ( & V_166 , V_33 ) ;
F_227 (info, tmp, &domain->devices, link) {
if ( V_164 -> V_32 == V_32 && V_164 -> V_81 == V_81 &&
V_164 -> V_82 == V_82 ) {
F_224 ( V_164 ) ;
F_101 ( & V_166 , V_33 ) ;
F_146 ( V_164 ) ;
F_223 ( V_32 , V_164 -> V_81 , V_164 -> V_82 ) ;
F_228 ( V_32 , V_89 ) ;
F_60 ( V_164 ) ;
F_100 ( & V_166 , V_33 ) ;
if ( V_72 )
break;
else
continue;
}
if ( V_164 -> V_32 == V_32 )
V_72 = true ;
}
F_101 ( & V_166 , V_33 ) ;
if ( V_72 == 0 ) {
F_170 ( V_42 , V_32 ) ;
if ( ! F_62 ( V_42 ) )
F_181 ( V_42 , V_32 ) ;
}
}
static int F_246 ( struct V_39 * V_42 , int V_209 )
{
int V_210 ;
F_186 ( & V_42 -> V_208 , V_116 , V_196 ,
V_197 ) ;
F_191 ( V_42 ) ;
V_42 -> V_127 = V_209 ;
V_210 = F_193 ( V_209 ) ;
V_42 -> V_1 = F_4 ( V_210 ) ;
V_42 -> V_74 = 0 ;
V_42 -> V_79 = 0 ;
V_42 -> V_80 = 0 ;
V_42 -> V_430 = 0 ;
V_42 -> V_112 = (struct V_27 * ) F_50 ( V_42 -> V_115 ) ;
if ( ! V_42 -> V_112 )
return - V_132 ;
F_97 ( V_42 , V_42 -> V_112 , V_211 ) ;
return 0 ;
}
static struct V_40 * F_392 ( unsigned type )
{
struct V_39 * V_39 ;
struct V_40 * V_42 ;
if ( type != V_431 )
return NULL ;
V_39 = F_173 ( V_58 ) ;
if ( ! V_39 ) {
F_118 ( L_86 ) ;
return NULL ;
}
if ( F_246 ( V_39 , V_65 ) ) {
F_118 ( L_87 ) ;
F_171 ( V_39 ) ;
return NULL ;
}
F_83 ( V_39 ) ;
V_42 = & V_39 -> V_42 ;
V_42 -> V_432 . V_433 = 0 ;
V_42 -> V_432 . V_434 = F_393 ( V_39 -> V_127 ) ;
V_42 -> V_432 . V_435 = true ;
return V_42 ;
}
static void F_394 ( struct V_40 * V_42 )
{
F_171 ( F_45 ( V_42 ) ) ;
}
static int F_395 ( struct V_40 * V_42 ,
struct V_88 * V_89 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_31 * V_32 ;
int V_60 ;
T_4 V_81 , V_82 ;
if ( F_256 ( V_89 ) ) {
F_396 ( V_89 , L_88 ) ;
return - V_436 ;
}
if ( F_203 ( F_209 ( V_89 ) ) ) {
struct V_39 * V_437 ;
V_437 = F_229 ( V_89 ) ;
if ( V_437 ) {
if ( F_62 ( V_39 ) )
F_253 ( V_437 , V_89 ) ;
else
F_198 ( V_437 ) ;
if ( ! F_62 ( V_437 ) &&
F_367 ( & V_437 -> V_97 ) )
F_171 ( V_437 ) ;
}
}
V_32 = F_90 ( V_89 , & V_81 , & V_82 ) ;
if ( ! V_32 )
return - V_202 ;
V_60 = F_2 ( V_32 -> V_1 ) ;
if ( V_60 > F_195 ( V_32 -> V_64 ) )
V_60 = F_195 ( V_32 -> V_64 ) ;
if ( V_39 -> V_430 > ( 1LL << V_60 ) ) {
F_118 ( L_89
L_90 ,
V_438 , V_60 , V_39 -> V_430 ) ;
return - V_215 ;
}
V_39 -> V_127 = V_60 ;
while ( V_32 -> V_1 < V_39 -> V_1 ) {
struct V_27 * V_28 ;
V_28 = V_39 -> V_112 ;
if ( F_38 ( V_28 ) ) {
V_39 -> V_112 = (struct V_27 * )
F_86 ( F_35 ( V_28 ) ) ;
F_53 ( V_28 ) ;
}
V_39 -> V_1 -- ;
}
return F_252 ( V_39 , V_89 , V_214 ) ;
}
static void F_397 ( struct V_40 * V_42 ,
struct V_88 * V_89 )
{
F_253 ( F_45 ( V_42 ) , V_89 ) ;
}
static int F_398 ( struct V_40 * V_42 ,
unsigned long V_194 , T_1 V_439 ,
T_8 V_106 , int V_440 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
V_24 V_430 ;
int V_236 = 0 ;
int V_77 ;
if ( V_440 & V_441 )
V_236 |= V_117 ;
if ( V_440 & V_442 )
V_236 |= V_118 ;
if ( ( V_440 & V_443 ) && V_39 -> V_79 )
V_236 |= V_241 ;
V_430 = V_194 + V_106 ;
if ( V_39 -> V_430 < V_430 ) {
V_24 V_102 ;
V_102 = F_393 ( V_39 -> V_127 ) + 1 ;
if ( V_102 < V_430 ) {
F_118 ( L_89
L_90 ,
V_438 , V_39 -> V_127 , V_430 ) ;
return - V_215 ;
}
V_39 -> V_430 = V_430 ;
}
V_106 = F_210 ( V_439 , V_106 ) ;
V_77 = F_222 ( V_39 , V_194 >> V_12 ,
V_439 >> V_12 , V_106 , V_236 ) ;
return V_77 ;
}
static T_8 F_399 ( struct V_40 * V_42 ,
unsigned long V_194 , T_8 V_106 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_14 * V_128 = NULL ;
struct V_31 * V_32 ;
unsigned long V_121 , V_122 ;
unsigned int V_444 ;
int V_66 , V_189 , V_181 , V_5 = 0 ;
if ( ! F_104 ( V_39 , V_194 >> V_12 , & V_5 ) )
F_131 () ;
if ( V_106 < V_116 << F_6 ( V_5 ) )
V_106 = V_116 << F_6 ( V_5 ) ;
V_121 = V_194 >> V_12 ;
V_122 = ( V_194 + V_106 - 1 ) >> V_12 ;
V_128 = F_115 ( V_39 , V_121 , V_122 ) ;
V_444 = V_122 - V_121 + 1 ;
F_73 (iommu_id, dmar_domain->iommu_bmp, g_num_of_iommus) {
V_32 = V_69 [ V_66 ] ;
V_181 = F_162 ( V_32 -> V_64 ) ;
F_73 (num, iommu->domain_ids, ndomains) {
if ( V_32 -> V_175 [ V_189 ] == V_39 )
F_152 ( V_32 , V_189 , V_121 ,
V_444 , ! V_128 , 0 ) ;
}
}
F_116 ( V_128 ) ;
if ( V_39 -> V_430 == V_194 + V_106 )
V_39 -> V_430 = V_194 ;
return V_106 ;
}
static T_1 F_400 ( struct V_40 * V_42 ,
V_244 V_194 )
{
struct V_39 * V_39 = F_45 ( V_42 ) ;
struct V_27 * V_28 ;
int V_5 = 0 ;
V_24 V_445 = 0 ;
V_28 = F_104 ( V_39 , V_194 >> V_12 , & V_5 ) ;
if ( V_28 )
V_445 = F_35 ( V_28 ) ;
return V_445 ;
}
static bool F_401 ( enum V_446 V_64 )
{
if ( V_64 == V_447 )
return F_78 ( NULL ) == 1 ;
if ( V_64 == V_448 )
return V_449 == 1 ;
return false ;
}
static int F_402 ( struct V_88 * V_89 )
{
struct V_31 * V_32 ;
struct V_450 * V_451 ;
T_4 V_81 , V_82 ;
V_32 = F_90 ( V_89 , & V_81 , & V_82 ) ;
if ( ! V_32 )
return - V_202 ;
F_403 ( V_32 -> V_424 , V_89 ) ;
V_451 = F_404 ( V_89 ) ;
if ( F_405 ( V_451 ) )
return F_406 ( V_451 ) ;
F_407 ( V_451 ) ;
return 0 ;
}
static void F_408 ( struct V_88 * V_89 )
{
struct V_31 * V_32 ;
T_4 V_81 , V_82 ;
V_32 = F_90 ( V_89 , & V_81 , & V_82 ) ;
if ( ! V_32 )
return;
F_409 ( V_89 ) ;
F_410 ( V_32 -> V_424 , V_89 ) ;
}
static void F_411 ( struct V_93 * V_89 )
{
F_48 ( L_91 ) ;
V_46 = 0 ;
}
static void F_412 ( struct V_93 * V_89 )
{
F_48 ( L_92 ) ;
V_143 = 1 ;
}
static void F_413 ( struct V_93 * V_89 )
{
unsigned short V_452 ;
if ( F_414 ( V_89 , V_453 , & V_452 ) )
return;
if ( ! ( V_452 & V_454 ) ) {
F_48 ( L_93 ) ;
V_46 = 0 ;
} else if ( V_46 ) {
F_48 ( L_94 ) ;
V_48 = 1 ;
}
}
static void T_3 F_286 ( void )
{
struct V_93 * V_95 ;
T_11 V_455 ;
V_95 = F_415 ( V_456 , 0x3a3e , NULL ) ;
if ( ! V_95 )
return;
F_244 ( V_95 ) ;
V_95 = F_415 ( V_456 , 0x342e , NULL ) ;
if ( ! V_95 )
return;
if ( F_416 ( V_95 , 0x188 , & V_455 ) ) {
F_244 ( V_95 ) ;
return;
}
F_244 ( V_95 ) ;
if ( V_455 & 1 )
return;
V_455 &= 0x1c ;
if ( V_455 == 0x10 )
return;
if ( ! V_455 ) {
F_239 ( 1 , L_95
L_33 ,
F_240 ( V_257 ) ,
F_240 ( V_258 ) ,
F_240 ( V_259 ) ) ;
V_269 |= V_273 ;
return;
}
F_237 ( L_96 ,
V_455 ) ;
}
