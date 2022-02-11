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
static inline bool F_18 ( struct V_17 * V_18 )
{
return ( V_18 -> V_19 & 1 ) ;
}
static inline void F_19 ( struct V_17 * V_18 )
{
V_18 -> V_19 |= 1 ;
}
static inline void F_20 ( struct V_17 * V_18 , unsigned long V_20 )
{
V_18 -> V_19 |= V_20 & V_21 ;
}
static inline struct V_22 *
F_21 ( struct V_17 * V_18 )
{
return (struct V_22 * )
( F_18 ( V_18 ) ? F_22 (
V_18 -> V_19 & V_21 ) :
NULL ) ;
}
static inline bool F_23 ( struct V_22 * V_23 )
{
return ( V_23 -> V_24 & 1 ) ;
}
static inline void F_24 ( struct V_22 * V_23 )
{
V_23 -> V_24 |= 1 ;
}
static inline void F_25 ( struct V_22 * V_23 )
{
V_23 -> V_24 &= ( ( ( V_25 ) - 1 ) << 2 ) | 1 ;
}
static inline void F_26 ( struct V_22 * V_23 ,
unsigned long V_20 )
{
V_23 -> V_24 &= ( ( ( V_25 ) - 1 ) << 4 ) | 3 ;
V_23 -> V_24 |= ( V_20 & 3 ) << 2 ;
}
static inline void F_27 ( struct V_22 * V_23 ,
unsigned long V_20 )
{
V_23 -> V_24 |= V_20 & V_21 ;
}
static inline void F_28 ( struct V_22 * V_23 ,
unsigned long V_20 )
{
V_23 -> V_26 |= V_20 & 7 ;
}
static inline void F_29 ( struct V_22 * V_23 ,
unsigned long V_20 )
{
V_23 -> V_26 |= ( V_20 & ( ( 1 << 16 ) - 1 ) ) << 8 ;
}
static inline void F_30 ( struct V_22 * V_23 )
{
V_23 -> V_24 = 0 ;
V_23 -> V_26 = 0 ;
}
static inline void F_31 ( struct V_27 * V_28 )
{
V_28 -> V_19 = 0 ;
}
static inline V_25 F_32 ( struct V_27 * V_28 )
{
#ifdef F_33
return V_28 -> V_19 & V_21 ;
#else
return F_34 ( & V_28 -> V_19 , 0ULL , 0ULL ) & V_21 ;
#endif
}
static inline bool F_35 ( struct V_27 * V_28 )
{
return ( V_28 -> V_19 & 3 ) != 0 ;
}
static inline bool F_36 ( struct V_27 * V_28 )
{
return ( V_28 -> V_19 & V_29 ) ;
}
static inline int F_37 ( struct V_27 * V_28 )
{
return ! ( ( unsigned long ) V_28 & ~ V_21 ) ;
}
static int T_1 F_38 ( char * V_30 )
{
if ( ! V_30 )
return - V_31 ;
while ( * V_30 ) {
if ( ! strncmp ( V_30 , L_1 , 2 ) ) {
V_32 = 0 ;
F_39 ( V_33 L_2 ) ;
} else if ( ! strncmp ( V_30 , L_3 , 3 ) ) {
V_32 = 1 ;
F_39 ( V_33 L_4 ) ;
} else if ( ! strncmp ( V_30 , L_5 , 8 ) ) {
V_34 = 0 ;
F_39 ( V_33
L_6 ) ;
} else if ( ! strncmp ( V_30 , L_7 , 8 ) ) {
F_39 ( V_33
L_8 ) ;
V_35 = 1 ;
} else if ( ! strncmp ( V_30 , L_9 , 6 ) ) {
F_39 ( V_33
L_10 ) ;
V_36 = 1 ;
} else if ( ! strncmp ( V_30 , L_11 , 6 ) ) {
F_39 ( V_33
L_12 ) ;
V_37 = 0 ;
}
V_30 += strcspn ( V_30 , L_13 ) ;
while ( * V_30 == ',' )
V_30 ++ ;
}
return 0 ;
}
static inline void * F_40 ( int V_38 )
{
struct V_14 * V_14 ;
void * V_39 = NULL ;
V_14 = F_41 ( V_38 , V_40 | V_41 , 0 ) ;
if ( V_14 )
V_39 = F_42 ( V_14 ) ;
return V_39 ;
}
static inline void F_43 ( void * V_39 )
{
F_44 ( ( unsigned long ) V_39 ) ;
}
static inline void * F_45 ( void )
{
return F_46 ( V_42 , V_40 ) ;
}
static void F_47 ( void * V_39 )
{
F_48 ( V_42 , V_39 ) ;
}
static inline void * F_49 ( void )
{
return F_46 ( V_43 , V_40 ) ;
}
static inline void F_50 ( void * V_39 )
{
F_48 ( V_43 , V_39 ) ;
}
struct V_44 * F_51 ( void )
{
return F_46 ( V_45 , V_40 ) ;
}
void F_52 ( struct V_44 * V_44 )
{
F_48 ( V_45 , V_44 ) ;
}
static inline int F_53 ( struct V_46 * V_47 )
{
return V_47 -> V_48 & V_49 ;
}
static inline int F_54 ( struct V_46 * V_47 )
{
return V_47 -> V_48 & ( V_49 |
V_50 ) ;
}
static inline int F_55 ( struct V_46 * V_47 ,
unsigned long V_6 )
{
int V_51 = F_2 ( V_47 -> V_1 ) - V_12 ;
return ! ( V_51 < V_52 && V_6 > > V_51 ) ;
}
static int F_56 ( struct V_53 * V_54 , int V_55 )
{
unsigned long V_56 ;
int V_1 = - 1 ;
V_56 = F_57 ( V_54 -> V_57 ) ;
for ( V_1 = F_4 ( V_55 ) ;
V_1 >= 0 ; V_1 -- ) {
if ( F_58 ( V_1 , & V_56 ) )
break;
}
return V_1 ;
}
int F_59 ( struct V_53 * V_54 )
{
return F_56 ( V_54 , V_3 ) ;
}
int F_60 ( struct V_53 * V_54 )
{
return F_56 ( V_54 , V_58 ) ;
}
static struct V_53 * F_61 ( struct V_46 * V_47 )
{
int V_59 ;
F_62 ( F_54 ( V_47 ) ) ;
V_59 = F_63 ( V_47 -> V_60 , V_61 ) ;
if ( V_59 < 0 || V_59 >= V_61 )
return NULL ;
return V_62 [ V_59 ] ;
}
static void F_64 ( struct V_46 * V_47 )
{
struct V_63 * V_64 ;
struct V_53 * V_54 ;
int V_65 , V_66 = 0 ;
V_47 -> V_67 = 1 ;
F_65 (i, domain->iommu_bmp, g_num_of_iommus) {
V_66 = 1 ;
if ( ! F_66 ( V_62 [ V_65 ] -> V_68 ) ) {
V_47 -> V_67 = 0 ;
break;
}
}
if ( V_66 )
return;
F_67 () ;
F_68 (iommu, drhd) {
if ( ! F_66 ( V_54 -> V_68 ) ) {
V_47 -> V_67 = 0 ;
break;
}
}
F_69 () ;
}
static int F_70 ( struct V_53 * V_69 )
{
struct V_63 * V_64 ;
struct V_53 * V_54 ;
int V_70 = 1 ;
F_67 () ;
F_68 (iommu, drhd) {
if ( V_54 != V_69 ) {
if ( ! F_71 ( V_54 -> V_68 ) ) {
V_70 = 0 ;
break;
}
}
}
F_69 () ;
return V_70 ;
}
static int F_72 ( struct V_53 * V_69 )
{
struct V_63 * V_64 ;
struct V_53 * V_54 ;
int V_71 = 0xf ;
if ( ! V_37 ) {
return 0 ;
}
F_67 () ;
F_68 (iommu, drhd) {
if ( V_54 != V_69 ) {
V_71 &= F_73 ( V_54 -> V_57 ) ;
if ( ! V_71 )
break;
}
}
F_69 () ;
return F_74 ( V_71 ) ;
}
static void F_75 ( struct V_46 * V_47 )
{
F_64 ( V_47 ) ;
V_47 -> V_72 = F_70 ( NULL ) ;
V_47 -> V_73 = F_72 ( NULL ) ;
}
static struct V_53 * F_76 ( struct V_74 * V_75 , T_2 * V_76 , T_2 * V_77 )
{
struct V_63 * V_64 = NULL ;
struct V_53 * V_54 ;
struct V_74 * V_78 ;
struct V_79 * V_80 , * V_81 = NULL ;
T_3 V_82 = 0 ;
int V_65 ;
if ( F_77 ( V_75 ) ) {
V_81 = F_78 ( V_75 ) ;
V_82 = F_79 ( V_81 -> V_76 ) ;
} else if ( F_80 ( V_75 ) )
V_75 = & F_80 ( V_75 ) -> V_75 ;
F_67 () ;
F_68 (iommu, drhd) {
if ( V_81 && V_82 != V_64 -> V_82 )
continue;
F_81 (drhd->devices,
drhd->devices_cnt, i, tmp) {
if ( V_78 == V_75 ) {
* V_76 = V_64 -> V_83 [ V_65 ] . V_76 ;
* V_77 = V_64 -> V_83 [ V_65 ] . V_77 ;
goto V_84;
}
if ( ! V_81 || ! F_77 ( V_78 ) )
continue;
V_80 = F_78 ( V_78 ) ;
if ( V_80 -> V_85 &&
V_80 -> V_85 -> V_86 <= V_81 -> V_76 -> V_86 &&
V_80 -> V_85 -> V_87 . V_88 >= V_81 -> V_76 -> V_86 )
goto V_89;
}
if ( V_81 && V_64 -> V_90 ) {
V_89:
* V_76 = V_81 -> V_76 -> V_86 ;
* V_77 = V_81 -> V_77 ;
goto V_84;
}
}
V_54 = NULL ;
V_84:
F_69 () ;
return V_54 ;
}
static void F_82 ( struct V_46 * V_47 ,
void * V_91 , int V_92 )
{
if ( ! V_47 -> V_67 )
F_83 ( V_91 , V_92 ) ;
}
static struct V_22 * F_84 ( struct V_53 * V_54 ,
T_2 V_76 , T_2 V_77 )
{
struct V_17 * V_18 ;
struct V_22 * V_23 ;
unsigned long V_93 ;
unsigned long V_48 ;
F_85 ( & V_54 -> V_94 , V_48 ) ;
V_18 = & V_54 -> V_17 [ V_76 ] ;
V_23 = F_21 ( V_18 ) ;
if ( ! V_23 ) {
V_23 = (struct V_22 * )
F_40 ( V_54 -> V_38 ) ;
if ( ! V_23 ) {
F_86 ( & V_54 -> V_94 , V_48 ) ;
return NULL ;
}
F_87 ( V_54 , ( void * ) V_23 , V_95 ) ;
V_93 = F_88 ( ( void * ) V_23 ) ;
F_20 ( V_18 , V_93 ) ;
F_19 ( V_18 ) ;
F_87 ( V_54 , V_18 , sizeof( * V_18 ) ) ;
}
F_86 ( & V_54 -> V_94 , V_48 ) ;
return & V_23 [ V_77 ] ;
}
static int F_89 ( struct V_53 * V_54 , T_2 V_76 , T_2 V_77 )
{
struct V_17 * V_18 ;
struct V_22 * V_23 ;
int V_70 ;
unsigned long V_48 ;
F_85 ( & V_54 -> V_94 , V_48 ) ;
V_18 = & V_54 -> V_17 [ V_76 ] ;
V_23 = F_21 ( V_18 ) ;
if ( ! V_23 ) {
V_70 = 0 ;
goto V_84;
}
V_70 = F_23 ( & V_23 [ V_77 ] ) ;
V_84:
F_86 ( & V_54 -> V_94 , V_48 ) ;
return V_70 ;
}
static void F_90 ( struct V_53 * V_54 , T_2 V_76 , T_2 V_77 )
{
struct V_17 * V_18 ;
struct V_22 * V_23 ;
unsigned long V_48 ;
F_85 ( & V_54 -> V_94 , V_48 ) ;
V_18 = & V_54 -> V_17 [ V_76 ] ;
V_23 = F_21 ( V_18 ) ;
if ( V_23 ) {
F_30 ( & V_23 [ V_77 ] ) ;
F_87 ( V_54 , & V_23 [ V_77 ] , \
sizeof( * V_23 ) ) ;
}
F_86 ( & V_54 -> V_94 , V_48 ) ;
}
static void F_91 ( struct V_53 * V_54 )
{
struct V_17 * V_18 ;
int V_65 ;
unsigned long V_48 ;
struct V_22 * V_23 ;
F_85 ( & V_54 -> V_94 , V_48 ) ;
if ( ! V_54 -> V_17 ) {
goto V_84;
}
for ( V_65 = 0 ; V_65 < V_96 ; V_65 ++ ) {
V_18 = & V_54 -> V_17 [ V_65 ] ;
V_23 = F_21 ( V_18 ) ;
if ( V_23 )
F_43 ( V_23 ) ;
}
F_43 ( V_54 -> V_17 ) ;
V_54 -> V_17 = NULL ;
V_84:
F_86 ( & V_54 -> V_94 , V_48 ) ;
}
static struct V_27 * F_92 ( struct V_46 * V_47 ,
unsigned long V_6 , int * V_97 )
{
struct V_27 * V_98 , * V_28 = NULL ;
int V_5 = F_1 ( V_47 -> V_1 ) ;
int V_99 ;
F_62 ( ! V_47 -> V_100 ) ;
if ( ! F_55 ( V_47 , V_6 ) )
return NULL ;
V_98 = V_47 -> V_100 ;
while ( 1 ) {
void * V_101 ;
V_99 = F_7 ( V_6 , V_5 ) ;
V_28 = & V_98 [ V_99 ] ;
if ( ! * V_97 && ( F_36 ( V_28 ) || ! F_35 ( V_28 ) ) )
break;
if ( V_5 == * V_97 )
break;
if ( ! F_35 ( V_28 ) ) {
T_4 V_102 ;
V_101 = F_40 ( V_47 -> V_103 ) ;
if ( ! V_101 )
return NULL ;
F_82 ( V_47 , V_101 , V_104 ) ;
V_102 = ( ( T_4 ) F_16 ( V_101 ) << V_12 ) | V_105 | V_106 ;
if ( F_93 ( & V_28 -> V_19 , 0ULL , V_102 ) )
F_43 ( V_101 ) ;
else
F_82 ( V_47 , V_28 , sizeof( * V_28 ) ) ;
}
if ( V_5 == 1 )
break;
V_98 = F_22 ( F_32 ( V_28 ) ) ;
V_5 -- ;
}
if ( ! * V_97 )
* V_97 = V_5 ;
return V_28 ;
}
static struct V_27 * F_94 ( struct V_46 * V_47 ,
unsigned long V_6 ,
int V_5 , int * V_107 )
{
struct V_27 * V_98 , * V_28 = NULL ;
int V_108 = F_1 ( V_47 -> V_1 ) ;
int V_99 ;
V_98 = V_47 -> V_100 ;
while ( V_5 <= V_108 ) {
V_99 = F_7 ( V_6 , V_108 ) ;
V_28 = & V_98 [ V_99 ] ;
if ( V_5 == V_108 )
return V_28 ;
if ( ! F_35 ( V_28 ) ) {
* V_107 = V_108 ;
break;
}
if ( F_36 ( V_28 ) ) {
* V_107 = V_108 ;
return V_28 ;
}
V_98 = F_22 ( F_32 ( V_28 ) ) ;
V_108 -- ;
}
return NULL ;
}
static void F_95 ( struct V_46 * V_47 ,
unsigned long V_109 ,
unsigned long V_110 )
{
unsigned int V_107 = 1 ;
struct V_27 * V_111 , * V_28 ;
F_62 ( ! F_55 ( V_47 , V_109 ) ) ;
F_62 ( ! F_55 ( V_47 , V_110 ) ) ;
F_62 ( V_109 > V_110 ) ;
do {
V_107 = 1 ;
V_111 = V_28 = F_94 ( V_47 , V_109 , 1 , & V_107 ) ;
if ( ! V_28 ) {
V_109 = F_10 ( V_109 + 1 , V_107 + 1 ) ;
continue;
}
do {
F_31 ( V_28 ) ;
V_109 += F_11 ( V_107 ) ;
V_28 ++ ;
} while ( V_109 <= V_110 && ! F_37 ( V_28 ) );
F_82 ( V_47 , V_111 ,
( void * ) V_28 - ( void * ) V_111 ) ;
} while ( V_109 && V_109 <= V_110 );
}
static void F_96 ( struct V_46 * V_47 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_109 , unsigned long V_110 )
{
V_6 = F_97 ( V_109 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_112 ;
struct V_27 * V_113 ;
if ( ! F_35 ( V_28 ) || F_36 ( V_28 ) )
goto V_114;
V_112 = V_6 & F_8 ( V_5 - 1 ) ;
V_113 = F_22 ( F_32 ( V_28 ) ) ;
if ( V_5 > 2 )
F_96 ( V_47 , V_5 - 1 , V_113 ,
V_112 , V_109 , V_110 ) ;
if ( ! ( V_109 > V_112 ||
V_110 < V_112 + F_9 ( V_5 ) - 1 ) ) {
F_31 ( V_28 ) ;
F_82 ( V_47 , V_28 , sizeof( * V_28 ) ) ;
F_43 ( V_113 ) ;
}
V_114:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_37 ( ++ V_28 ) && V_6 <= V_110 );
}
static void F_98 ( struct V_46 * V_47 ,
unsigned long V_109 ,
unsigned long V_110 )
{
F_62 ( ! F_55 ( V_47 , V_109 ) ) ;
F_62 ( ! F_55 ( V_47 , V_110 ) ) ;
F_62 ( V_109 > V_110 ) ;
F_95 ( V_47 , V_109 , V_110 ) ;
F_96 ( V_47 , F_1 ( V_47 -> V_1 ) ,
V_47 -> V_100 , 0 , V_109 , V_110 ) ;
if ( V_109 == 0 && V_110 == F_99 ( V_47 -> V_115 ) ) {
F_43 ( V_47 -> V_100 ) ;
V_47 -> V_100 = NULL ;
}
}
static struct V_14 * F_100 ( struct V_46 * V_47 ,
int V_5 , struct V_27 * V_28 ,
struct V_14 * V_116 )
{
struct V_14 * V_15 ;
V_15 = F_101 ( F_32 ( V_28 ) >> V_11 ) ;
V_15 -> V_116 = V_116 ;
V_116 = V_15 ;
if ( V_5 == 1 )
return V_116 ;
V_28 = F_42 ( V_15 ) ;
do {
if ( F_35 ( V_28 ) && ! F_36 ( V_28 ) )
V_116 = F_100 ( V_47 , V_5 - 1 ,
V_28 , V_116 ) ;
V_28 ++ ;
} while ( ! F_37 ( V_28 ) );
return V_116 ;
}
static struct V_14 * F_102 ( struct V_46 * V_47 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_109 ,
unsigned long V_110 ,
struct V_14 * V_116 )
{
struct V_27 * V_111 = NULL , * V_117 = NULL ;
V_6 = F_97 ( V_109 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_112 ;
if ( ! F_35 ( V_28 ) )
goto V_114;
V_112 = V_6 & F_8 ( V_5 ) ;
if ( V_109 <= V_112 &&
V_110 >= V_112 + F_9 ( V_5 ) - 1 ) {
if ( V_5 > 1 && ! F_36 ( V_28 ) )
V_116 = F_100 ( V_47 , V_5 - 1 , V_28 , V_116 ) ;
F_31 ( V_28 ) ;
if ( ! V_111 )
V_111 = V_28 ;
V_117 = V_28 ;
} else if ( V_5 > 1 ) {
V_116 = F_102 ( V_47 , V_5 - 1 ,
F_22 ( F_32 ( V_28 ) ) ,
V_112 , V_109 , V_110 ,
V_116 ) ;
}
V_114:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_37 ( ++ V_28 ) && V_6 <= V_110 );
if ( V_111 )
F_82 ( V_47 , V_111 ,
( void * ) ++ V_117 - ( void * ) V_111 ) ;
return V_116 ;
}
struct V_14 * F_103 ( struct V_46 * V_47 ,
unsigned long V_109 ,
unsigned long V_110 )
{
struct V_14 * V_116 = NULL ;
F_62 ( ! F_55 ( V_47 , V_109 ) ) ;
F_62 ( ! F_55 ( V_47 , V_110 ) ) ;
F_62 ( V_109 > V_110 ) ;
V_116 = F_102 ( V_47 , F_1 ( V_47 -> V_1 ) ,
V_47 -> V_100 , 0 , V_109 , V_110 , NULL ) ;
if ( V_109 == 0 && V_110 == F_99 ( V_47 -> V_115 ) ) {
struct V_14 * V_118 = F_17 ( V_47 -> V_100 ) ;
V_118 -> V_116 = V_116 ;
V_116 = V_118 ;
V_47 -> V_100 = NULL ;
}
return V_116 ;
}
void F_104 ( struct V_14 * V_116 )
{
struct V_14 * V_15 ;
while ( ( V_15 = V_116 ) ) {
V_116 = V_15 -> V_116 ;
F_43 ( F_42 ( V_15 ) ) ;
}
}
static int F_105 ( struct V_53 * V_54 )
{
struct V_17 * V_18 ;
unsigned long V_48 ;
V_18 = (struct V_17 * ) F_40 ( V_54 -> V_38 ) ;
if ( ! V_18 )
return - V_119 ;
F_87 ( V_54 , V_18 , V_120 ) ;
F_85 ( & V_54 -> V_94 , V_48 ) ;
V_54 -> V_17 = V_18 ;
F_86 ( & V_54 -> V_94 , V_48 ) ;
return 0 ;
}
static void F_106 ( struct V_53 * V_54 )
{
void * V_91 ;
T_5 V_121 ;
unsigned long V_122 ;
V_91 = V_54 -> V_17 ;
F_107 ( & V_54 -> V_123 , V_122 ) ;
F_108 ( V_54 -> V_124 + V_125 , F_88 ( V_91 ) ) ;
F_109 ( V_54 -> V_126 | V_127 , V_54 -> V_124 + V_128 ) ;
F_110 ( V_54 , V_129 ,
V_130 , ( V_121 & V_131 ) , V_121 ) ;
F_111 ( & V_54 -> V_123 , V_122 ) ;
}
static void F_112 ( struct V_53 * V_54 )
{
T_5 V_19 ;
unsigned long V_122 ;
if ( ! V_132 && ! F_113 ( V_54 -> V_57 ) )
return;
F_107 ( & V_54 -> V_123 , V_122 ) ;
F_109 ( V_54 -> V_126 | V_133 , V_54 -> V_124 + V_128 ) ;
F_110 ( V_54 , V_129 ,
V_130 , ( ! ( V_19 & V_134 ) ) , V_19 ) ;
F_111 ( & V_54 -> V_123 , V_122 ) ;
}
static void F_114 ( struct V_53 * V_54 ,
T_3 V_135 , T_3 V_136 , T_2 V_137 ,
V_25 type )
{
V_25 V_19 = 0 ;
unsigned long V_122 ;
switch ( type ) {
case V_138 :
V_19 = V_138 ;
break;
case V_139 :
V_19 = V_139 | F_115 ( V_135 ) ;
break;
case V_140 :
V_19 = V_140 | F_115 ( V_135 )
| F_116 ( V_136 ) | F_117 ( V_137 ) ;
break;
default:
F_118 () ;
}
V_19 |= V_141 ;
F_107 ( & V_54 -> V_123 , V_122 ) ;
F_108 ( V_54 -> V_124 + V_142 , V_19 ) ;
F_110 ( V_54 , V_142 ,
V_143 , ( ! ( V_19 & V_141 ) ) , V_19 ) ;
F_111 ( & V_54 -> V_123 , V_122 ) ;
}
static void F_119 ( struct V_53 * V_54 , T_3 V_135 ,
V_25 V_91 , unsigned int V_144 , V_25 type )
{
int V_145 = F_120 ( V_54 -> V_68 ) ;
V_25 V_19 = 0 , V_146 = 0 ;
unsigned long V_122 ;
switch ( type ) {
case V_147 :
V_19 = V_147 | V_148 ;
break;
case V_149 :
V_19 = V_149 | V_148 | F_121 ( V_135 ) ;
break;
case V_150 :
V_19 = V_150 | V_148 | F_121 ( V_135 ) ;
V_146 = V_144 | V_91 ;
break;
default:
F_118 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_122 ( V_54 -> V_57 ) )
V_19 |= V_151 ;
F_107 ( & V_54 -> V_123 , V_122 ) ;
if ( V_146 )
F_108 ( V_54 -> V_124 + V_145 , V_146 ) ;
F_108 ( V_54 -> V_124 + V_145 + 8 , V_19 ) ;
F_110 ( V_54 , V_145 + 8 ,
V_143 , ( ! ( V_19 & V_148 ) ) , V_19 ) ;
F_111 ( & V_54 -> V_123 , V_122 ) ;
if ( F_123 ( V_19 ) == 0 )
F_39 ( V_152 L_14 ) ;
if ( F_123 ( V_19 ) != F_124 ( type ) )
F_125 ( L_15 ,
( unsigned long long ) F_124 ( type ) ,
( unsigned long long ) F_123 ( V_19 ) ) ;
}
static struct V_153 *
F_126 ( struct V_46 * V_47 , struct V_53 * V_54 ,
T_2 V_76 , T_2 V_77 )
{
int V_66 = 0 ;
unsigned long V_48 ;
struct V_153 * V_154 ;
struct V_79 * V_81 ;
if ( ! F_127 ( V_54 -> V_68 ) )
return NULL ;
if ( ! V_54 -> V_155 )
return NULL ;
F_85 ( & V_156 , V_48 ) ;
F_128 (info, &domain->devices, link)
if ( V_154 -> V_54 == V_54 && V_154 -> V_76 == V_76 &&
V_154 -> V_77 == V_77 ) {
V_66 = 1 ;
break;
}
F_86 ( & V_156 , V_48 ) ;
if ( ! V_66 || ! V_154 -> V_75 || ! F_77 ( V_154 -> V_75 ) )
return NULL ;
V_81 = F_78 ( V_154 -> V_75 ) ;
if ( ! F_129 ( V_81 , V_157 ) )
return NULL ;
if ( ! F_130 ( V_81 ) )
return NULL ;
return V_154 ;
}
static void F_131 ( struct V_153 * V_154 )
{
if ( ! V_154 || ! F_77 ( V_154 -> V_75 ) )
return;
F_132 ( F_78 ( V_154 -> V_75 ) , V_12 ) ;
}
static void F_133 ( struct V_153 * V_154 )
{
if ( ! V_154 -> V_75 || ! F_77 ( V_154 -> V_75 ) ||
! F_134 ( F_78 ( V_154 -> V_75 ) ) )
return;
F_135 ( F_78 ( V_154 -> V_75 ) ) ;
}
static void F_136 ( struct V_46 * V_47 ,
V_25 V_91 , unsigned V_71 )
{
T_3 V_158 , V_159 ;
unsigned long V_48 ;
struct V_153 * V_154 ;
F_85 ( & V_156 , V_48 ) ;
F_128 (info, &domain->devices, link) {
struct V_79 * V_81 ;
if ( ! V_154 -> V_75 || ! F_77 ( V_154 -> V_75 ) )
continue;
V_81 = F_78 ( V_154 -> V_75 ) ;
if ( ! F_134 ( V_81 ) )
continue;
V_158 = V_154 -> V_76 << 8 | V_154 -> V_77 ;
V_159 = F_137 ( V_81 ) ;
F_138 ( V_154 -> V_54 , V_158 , V_159 , V_91 , V_71 ) ;
}
F_86 ( & V_156 , V_48 ) ;
}
static void F_139 ( struct V_53 * V_54 , T_3 V_135 ,
unsigned long V_6 , unsigned int V_160 , int V_161 , int V_162 )
{
unsigned int V_71 = F_140 ( F_141 ( V_160 ) ) ;
T_4 V_91 = ( T_4 ) V_6 << V_12 ;
F_62 ( V_160 == 0 ) ;
if ( V_161 )
V_161 = 1 << 6 ;
if ( ! F_142 ( V_54 -> V_57 ) || V_71 > F_143 ( V_54 -> V_57 ) )
V_54 -> V_163 . V_164 ( V_54 , V_135 , 0 , 0 ,
V_149 ) ;
else
V_54 -> V_163 . V_164 ( V_54 , V_135 , V_91 | V_161 , V_71 ,
V_150 ) ;
if ( ! F_144 ( V_54 -> V_57 ) || ! V_162 )
F_136 ( V_54 -> V_165 [ V_135 ] , V_91 , V_71 ) ;
}
static void F_145 ( struct V_53 * V_54 )
{
T_5 V_166 ;
unsigned long V_48 ;
F_107 ( & V_54 -> V_123 , V_48 ) ;
V_166 = V_130 ( V_54 -> V_124 + V_167 ) ;
V_166 &= ~ V_168 ;
F_109 ( V_166 , V_54 -> V_124 + V_167 ) ;
F_110 ( V_54 , V_167 ,
V_130 , ! ( V_166 & V_169 ) , V_166 ) ;
F_111 ( & V_54 -> V_123 , V_48 ) ;
}
static void F_146 ( struct V_53 * V_54 )
{
T_5 V_121 ;
unsigned long V_48 ;
F_107 ( & V_54 -> V_123 , V_48 ) ;
V_54 -> V_126 |= V_170 ;
F_109 ( V_54 -> V_126 , V_54 -> V_124 + V_128 ) ;
F_110 ( V_54 , V_129 ,
V_130 , ( V_121 & V_171 ) , V_121 ) ;
F_111 ( & V_54 -> V_123 , V_48 ) ;
}
static void F_147 ( struct V_53 * V_54 )
{
T_5 V_121 ;
unsigned long V_122 ;
F_107 ( & V_54 -> V_123 , V_122 ) ;
V_54 -> V_126 &= ~ V_170 ;
F_109 ( V_54 -> V_126 , V_54 -> V_124 + V_128 ) ;
F_110 ( V_54 , V_129 ,
V_130 , ( ! ( V_121 & V_171 ) ) , V_121 ) ;
F_111 ( & V_54 -> V_123 , V_122 ) ;
}
static int F_148 ( struct V_53 * V_54 )
{
unsigned long V_172 ;
unsigned long V_173 ;
V_172 = F_149 ( V_54 -> V_57 ) ;
F_125 ( L_16 ,
V_54 -> V_174 , V_172 ) ;
V_173 = F_150 ( V_172 ) ;
F_151 ( & V_54 -> V_94 ) ;
V_54 -> V_175 = F_152 ( V_173 , sizeof( unsigned long ) , V_176 ) ;
if ( ! V_54 -> V_175 ) {
F_153 ( L_17 ,
V_54 -> V_174 ) ;
return - V_119 ;
}
V_54 -> V_165 = F_152 ( V_172 , sizeof( struct V_46 * ) ,
V_176 ) ;
if ( ! V_54 -> V_165 ) {
F_153 ( L_18 ,
V_54 -> V_174 ) ;
F_154 ( V_54 -> V_175 ) ;
V_54 -> V_175 = NULL ;
return - V_119 ;
}
if ( F_144 ( V_54 -> V_57 ) )
F_155 ( 0 , V_54 -> V_175 ) ;
return 0 ;
}
static void F_156 ( struct V_53 * V_54 )
{
struct V_46 * V_47 ;
int V_65 ;
if ( ( V_54 -> V_165 ) && ( V_54 -> V_175 ) ) {
F_65 (i, iommu->domain_ids, cap_ndoms(iommu->cap)) {
if ( F_144 ( V_54 -> V_57 ) && V_65 == 0 )
continue;
V_47 = V_54 -> V_165 [ V_65 ] ;
F_157 ( V_65 , V_54 -> V_175 ) ;
if ( F_158 ( V_47 , V_54 ) == 0 &&
! F_53 ( V_47 ) )
F_159 ( V_47 ) ;
}
}
if ( V_54 -> V_126 & V_170 )
F_147 ( V_54 ) ;
F_154 ( V_54 -> V_165 ) ;
F_154 ( V_54 -> V_175 ) ;
V_54 -> V_165 = NULL ;
V_54 -> V_175 = NULL ;
V_62 [ V_54 -> V_174 ] = NULL ;
F_91 ( V_54 ) ;
}
static struct V_46 * F_160 ( int V_48 )
{
static T_6 V_177 = F_161 ( 0 ) ;
struct V_46 * V_47 ;
V_47 = F_45 () ;
if ( ! V_47 )
return NULL ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
V_47 -> V_103 = - 1 ;
V_47 -> V_48 = V_48 ;
F_151 ( & V_47 -> V_178 ) ;
F_162 ( & V_47 -> V_83 ) ;
if ( V_48 & V_49 )
V_47 -> V_179 = F_163 ( & V_177 ) ;
return V_47 ;
}
static int F_164 ( struct V_46 * V_47 ,
struct V_53 * V_54 )
{
int V_180 ;
unsigned long V_172 ;
V_172 = F_149 ( V_54 -> V_57 ) ;
V_180 = F_165 ( V_54 -> V_175 , V_172 ) ;
if ( V_180 < V_172 ) {
F_155 ( V_180 , V_54 -> V_175 ) ;
V_54 -> V_165 [ V_180 ] = V_47 ;
} else {
V_180 = - V_181 ;
}
return V_180 ;
}
static int F_166 ( struct V_46 * V_47 ,
struct V_53 * V_54 )
{
int V_180 ;
unsigned long V_48 ;
F_85 ( & V_54 -> V_94 , V_48 ) ;
V_180 = F_164 ( V_47 , V_54 ) ;
F_86 ( & V_54 -> V_94 , V_48 ) ;
if ( V_180 < 0 )
F_153 ( L_19 ) ;
return V_180 ;
}
static int F_167 ( struct V_46 * V_47 ,
struct V_53 * V_54 )
{
int V_180 ;
unsigned long V_172 ;
V_172 = F_149 ( V_54 -> V_57 ) ;
F_65 (num, iommu->domain_ids, ndomains)
if ( V_54 -> V_165 [ V_180 ] == V_47 )
return V_180 ;
return F_164 ( V_47 , V_54 ) ;
}
static void F_168 ( struct V_46 * V_47 ,
struct V_53 * V_54 )
{
unsigned long V_48 ;
int V_180 , V_172 ;
F_85 ( & V_54 -> V_94 , V_48 ) ;
if ( F_54 ( V_47 ) ) {
V_172 = F_149 ( V_54 -> V_57 ) ;
F_65 (num, iommu->domain_ids, ndomains) {
if ( V_54 -> V_165 [ V_180 ] == V_47 ) {
F_157 ( V_180 , V_54 -> V_175 ) ;
V_54 -> V_165 [ V_180 ] = NULL ;
break;
}
}
} else {
F_157 ( V_47 -> V_179 , V_54 -> V_175 ) ;
V_54 -> V_165 [ V_47 -> V_179 ] = NULL ;
}
F_86 ( & V_54 -> V_94 , V_48 ) ;
}
static void F_169 ( struct V_46 * V_47 ,
struct V_53 * V_54 )
{
unsigned long V_48 ;
F_85 ( & V_47 -> V_178 , V_48 ) ;
if ( ! F_170 ( V_54 -> V_174 , V_47 -> V_60 ) ) {
V_47 -> V_182 ++ ;
if ( V_47 -> V_182 == 1 )
V_47 -> V_103 = V_54 -> V_38 ;
F_75 ( V_47 ) ;
}
F_86 ( & V_47 -> V_178 , V_48 ) ;
}
static int F_158 ( struct V_46 * V_47 ,
struct V_53 * V_54 )
{
unsigned long V_48 ;
int V_183 = V_184 ;
F_85 ( & V_47 -> V_178 , V_48 ) ;
if ( F_171 ( V_54 -> V_174 , V_47 -> V_60 ) ) {
V_183 = -- V_47 -> V_182 ;
F_75 ( V_47 ) ;
}
F_86 ( & V_47 -> V_178 , V_48 ) ;
return V_183 ;
}
static int F_172 ( void )
{
struct V_79 * V_81 = NULL ;
struct V_44 * V_44 ;
int V_65 ;
F_173 ( & V_185 , V_186 ) ;
F_174 ( & V_185 . V_187 ,
& V_188 ) ;
V_44 = F_175 ( & V_185 , F_176 ( V_189 ) ,
F_176 ( V_190 ) ) ;
if ( ! V_44 ) {
F_39 ( V_152 L_20 ) ;
return - V_191 ;
}
F_177 (pdev) {
struct V_192 * V_193 ;
for ( V_65 = 0 ; V_65 < V_194 ; V_65 ++ ) {
V_193 = & V_81 -> V_192 [ V_65 ] ;
if ( ! V_193 -> V_48 || ! ( V_193 -> V_48 & V_195 ) )
continue;
V_44 = F_175 ( & V_185 ,
F_176 ( V_193 -> V_196 ) ,
F_176 ( V_193 -> V_88 ) ) ;
if ( ! V_44 ) {
F_39 ( V_152 L_21 ) ;
return - V_191 ;
}
}
}
return 0 ;
}
static void F_178 ( struct V_46 * V_47 )
{
F_179 ( & V_185 , & V_47 -> V_197 ) ;
}
static inline int F_180 ( int V_115 )
{
int V_1 ;
int V_193 = ( V_115 - 12 ) % 9 ;
if ( V_193 == 0 )
V_1 = V_115 ;
else
V_1 = V_115 + 9 - V_193 ;
if ( V_1 > 64 )
V_1 = 64 ;
return V_1 ;
}
static int F_181 ( struct V_46 * V_47 , int V_198 )
{
struct V_53 * V_54 ;
int V_199 , V_1 ;
unsigned long V_56 ;
F_173 ( & V_47 -> V_197 , V_186 ) ;
F_178 ( V_47 ) ;
V_54 = F_61 ( V_47 ) ;
if ( V_198 > F_182 ( V_54 -> V_57 ) )
V_198 = F_182 ( V_54 -> V_57 ) ;
V_47 -> V_115 = V_198 ;
V_199 = F_180 ( V_198 ) ;
V_1 = F_4 ( V_199 ) ;
V_56 = F_57 ( V_54 -> V_57 ) ;
if ( ! F_58 ( V_1 , & V_56 ) ) {
F_125 ( L_22 , V_1 ) ;
V_1 = F_183 ( & V_56 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_191 ;
}
V_47 -> V_1 = V_1 ;
if ( F_66 ( V_54 -> V_68 ) )
V_47 -> V_67 = 1 ;
else
V_47 -> V_67 = 0 ;
if ( F_71 ( V_54 -> V_68 ) )
V_47 -> V_72 = 1 ;
else
V_47 -> V_72 = 0 ;
if ( V_37 )
V_47 -> V_73 = F_74 ( F_73 ( V_54 -> V_57 ) ) ;
else
V_47 -> V_73 = 0 ;
V_47 -> V_103 = V_54 -> V_38 ;
V_47 -> V_100 = (struct V_27 * ) F_40 ( V_47 -> V_103 ) ;
if ( ! V_47 -> V_100 )
return - V_119 ;
F_87 ( V_54 , V_47 -> V_100 , V_200 ) ;
return 0 ;
}
static void F_159 ( struct V_46 * V_47 )
{
struct V_63 * V_64 ;
struct V_53 * V_54 ;
struct V_14 * V_116 = NULL ;
if ( ! V_47 )
return;
if ( ! V_36 )
F_184 ( 0 ) ;
F_185 ( V_47 ) ;
F_186 ( & V_47 -> V_197 ) ;
V_116 = F_103 ( V_47 , 0 , F_99 ( V_47 -> V_115 ) ) ;
F_67 () ;
F_68 (iommu, drhd)
F_168 ( V_47 , V_54 ) ;
F_69 () ;
F_104 ( V_116 ) ;
F_47 ( V_47 ) ;
}
static int F_187 ( struct V_46 * V_47 ,
struct V_53 * V_54 ,
T_2 V_76 , T_2 V_77 , int V_201 )
{
struct V_22 * V_23 ;
unsigned long V_48 ;
struct V_27 * V_100 ;
int V_179 ;
int V_1 ;
struct V_153 * V_154 = NULL ;
F_125 ( L_23 ,
V_76 , F_188 ( V_77 ) , F_189 ( V_77 ) ) ;
F_62 ( ! V_47 -> V_100 ) ;
F_62 ( V_201 != V_202 &&
V_201 != V_203 ) ;
V_23 = F_84 ( V_54 , V_76 , V_77 ) ;
if ( ! V_23 )
return - V_119 ;
F_85 ( & V_54 -> V_94 , V_48 ) ;
if ( F_23 ( V_23 ) ) {
F_86 ( & V_54 -> V_94 , V_48 ) ;
return 0 ;
}
V_179 = V_47 -> V_179 ;
V_100 = V_47 -> V_100 ;
if ( F_54 ( V_47 ) ) {
if ( F_53 ( V_47 ) ) {
V_179 = F_167 ( V_47 , V_54 ) ;
if ( V_179 < 0 ) {
F_86 ( & V_54 -> V_94 , V_48 ) ;
F_153 ( L_19 ) ;
return - V_204 ;
}
}
if ( V_201 != V_202 ) {
for ( V_1 = V_47 -> V_1 ; V_1 != V_54 -> V_1 ; V_1 -- ) {
V_100 = F_22 ( F_32 ( V_100 ) ) ;
if ( ! F_35 ( V_100 ) ) {
F_86 ( & V_54 -> V_94 , V_48 ) ;
return - V_119 ;
}
}
}
}
F_29 ( V_23 , V_179 ) ;
if ( V_201 != V_202 ) {
V_154 = F_126 ( V_47 , V_54 , V_76 , V_77 ) ;
V_201 = V_154 ? V_205 :
V_203 ;
}
if ( F_190 ( V_201 == V_202 ) )
F_28 ( V_23 , V_54 -> V_206 ) ;
else {
F_27 ( V_23 , F_88 ( V_100 ) ) ;
F_28 ( V_23 , V_54 -> V_1 ) ;
}
F_26 ( V_23 , V_201 ) ;
F_25 ( V_23 ) ;
F_24 ( V_23 ) ;
F_82 ( V_47 , V_23 , sizeof( * V_23 ) ) ;
if ( F_144 ( V_54 -> V_57 ) ) {
V_54 -> V_163 . V_207 ( V_54 , 0 ,
( ( ( T_3 ) V_76 ) << 8 ) | V_77 ,
V_208 ,
V_140 ) ;
V_54 -> V_163 . V_164 ( V_54 , V_179 , 0 , 0 , V_149 ) ;
} else {
F_112 ( V_54 ) ;
}
F_131 ( V_154 ) ;
F_86 ( & V_54 -> V_94 , V_48 ) ;
F_169 ( V_47 , V_54 ) ;
return 0 ;
}
static int F_191 ( struct V_79 * V_81 ,
T_3 V_209 , void * V_210 )
{
struct V_211 * V_212 = V_210 ;
return F_187 ( V_212 -> V_47 , V_212 -> V_54 ,
F_192 ( V_209 ) , V_209 & 0xff ,
V_212 -> V_201 ) ;
}
static int
F_193 ( struct V_46 * V_47 , struct V_74 * V_75 ,
int V_201 )
{
struct V_53 * V_54 ;
T_2 V_76 , V_77 ;
struct V_211 V_212 ;
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return - V_191 ;
if ( ! F_77 ( V_75 ) )
return F_187 ( V_47 , V_54 , V_76 , V_77 ,
V_201 ) ;
V_212 . V_47 = V_47 ;
V_212 . V_54 = V_54 ;
V_212 . V_201 = V_201 ;
return F_194 ( F_78 ( V_75 ) ,
& F_191 , & V_212 ) ;
}
static int F_195 ( struct V_79 * V_81 ,
T_3 V_209 , void * V_210 )
{
struct V_53 * V_54 = V_210 ;
return ! F_89 ( V_54 , F_192 ( V_209 ) , V_209 & 0xff ) ;
}
static int F_196 ( struct V_74 * V_75 )
{
struct V_53 * V_54 ;
T_2 V_76 , V_77 ;
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return - V_191 ;
if ( ! F_77 ( V_75 ) )
return F_89 ( V_54 , V_76 , V_77 ) ;
return ! F_194 ( F_78 ( V_75 ) ,
F_195 , V_54 ) ;
}
static inline unsigned long F_197 ( unsigned long V_213 ,
T_7 V_92 )
{
V_213 &= ~ V_214 ;
return F_198 ( V_213 + V_92 ) >> V_12 ;
}
static inline int F_199 ( struct V_46 * V_47 ,
unsigned long V_215 ,
unsigned long V_216 ,
unsigned long V_160 )
{
int V_217 , V_5 = 1 ;
unsigned long V_218 ;
V_217 = V_47 -> V_73 ;
V_218 = V_215 | V_216 ;
while ( V_217 && ! ( V_218 & ~ V_219 ) ) {
V_160 >>= V_220 ;
if ( ! V_160 )
break;
V_218 >>= V_220 ;
V_5 ++ ;
V_217 -- ;
}
return V_5 ;
}
static int F_200 ( struct V_46 * V_47 , unsigned long V_215 ,
struct V_221 * V_222 , unsigned long V_223 ,
unsigned long V_224 , int V_225 )
{
struct V_27 * V_111 = NULL , * V_28 = NULL ;
T_8 V_226 ( V_102 ) ;
unsigned long V_227 ;
unsigned int V_228 = 0 ;
unsigned long V_229 = 0 ;
F_62 ( ! F_55 ( V_47 , V_215 + V_224 - 1 ) ) ;
if ( ( V_225 & ( V_105 | V_106 ) ) == 0 )
return - V_31 ;
V_225 &= V_105 | V_106 | V_230 ;
if ( V_222 )
V_227 = 0 ;
else {
V_227 = V_224 + 1 ;
V_102 = ( ( T_8 ) V_223 << V_12 ) | V_225 ;
}
while ( V_224 > 0 ) {
T_4 V_78 ;
if ( ! V_227 ) {
V_227 = F_197 ( V_222 -> V_99 , V_222 -> V_231 ) ;
V_222 -> V_232 = ( ( V_233 ) V_215 << V_12 ) + V_222 -> V_99 ;
V_222 -> V_234 = V_222 -> V_231 ;
V_102 = F_201 ( F_202 ( V_222 ) ) | V_225 ;
V_223 = V_102 >> V_12 ;
}
if ( ! V_28 ) {
V_228 = F_199 ( V_47 , V_215 , V_223 , V_227 ) ;
V_111 = V_28 = F_92 ( V_47 , V_215 , & V_228 ) ;
if ( ! V_28 )
return - V_119 ;
if ( V_228 > 1 ) {
V_102 |= V_29 ;
V_229 = F_11 ( V_228 ) ;
F_98 ( V_47 , V_215 ,
V_215 + V_229 - 1 ) ;
} else {
V_102 &= ~ ( T_4 ) V_29 ;
}
}
V_78 = F_203 ( & V_28 -> V_19 , 0ULL , V_102 ) ;
if ( V_78 ) {
static int V_235 = 5 ;
F_39 ( V_236 L_24 ,
V_215 , V_78 , ( unsigned long long ) V_102 ) ;
if ( V_235 ) {
V_235 -- ;
F_204 ( NULL ) ;
}
F_205 ( 1 ) ;
}
V_229 = F_11 ( V_228 ) ;
F_62 ( V_224 < V_229 ) ;
F_62 ( V_227 < V_229 ) ;
V_224 -= V_229 ;
V_215 += V_229 ;
V_223 += V_229 ;
V_102 += V_229 * V_104 ;
V_227 -= V_229 ;
V_28 ++ ;
if ( ! V_224 || F_37 ( V_28 ) ||
( V_228 > 1 && V_227 < V_229 ) ) {
F_82 ( V_47 , V_111 ,
( void * ) V_28 - ( void * ) V_111 ) ;
V_28 = NULL ;
}
if ( ! V_227 && V_224 )
V_222 = F_206 ( V_222 ) ;
}
return 0 ;
}
static inline int F_207 ( struct V_46 * V_47 , unsigned long V_215 ,
struct V_221 * V_222 , unsigned long V_224 ,
int V_225 )
{
return F_200 ( V_47 , V_215 , V_222 , 0 , V_224 , V_225 ) ;
}
static inline int F_208 ( struct V_46 * V_47 , unsigned long V_215 ,
unsigned long V_223 , unsigned long V_224 ,
int V_225 )
{
return F_200 ( V_47 , V_215 , NULL , V_223 , V_224 , V_225 ) ;
}
static void F_209 ( struct V_53 * V_54 , T_2 V_76 , T_2 V_77 )
{
if ( ! V_54 )
return;
F_90 ( V_54 , V_76 , V_77 ) ;
V_54 -> V_163 . V_207 ( V_54 , 0 , 0 , 0 ,
V_138 ) ;
V_54 -> V_163 . V_164 ( V_54 , 0 , 0 , 0 , V_147 ) ;
}
static inline void F_210 ( struct V_153 * V_154 )
{
F_211 ( & V_156 ) ;
F_212 ( & V_154 -> V_237 ) ;
F_212 ( & V_154 -> V_238 ) ;
if ( V_154 -> V_75 )
V_154 -> V_75 -> V_239 . V_54 = NULL ;
}
static void F_185 ( struct V_46 * V_47 )
{
struct V_153 * V_154 , * V_78 ;
unsigned long V_48 ;
F_85 ( & V_156 , V_48 ) ;
F_213 (info, tmp, &domain->devices, link) {
F_210 ( V_154 ) ;
F_86 ( & V_156 , V_48 ) ;
F_133 ( V_154 ) ;
F_209 ( V_154 -> V_54 , V_154 -> V_76 , V_154 -> V_77 ) ;
if ( F_53 ( V_47 ) ) {
F_214 ( V_154 -> V_54 , V_154 -> V_75 ) ;
F_158 ( V_47 , V_154 -> V_54 ) ;
}
F_50 ( V_154 ) ;
F_85 ( & V_156 , V_48 ) ;
}
F_86 ( & V_156 , V_48 ) ;
}
static struct V_46 * F_215 ( struct V_74 * V_75 )
{
struct V_153 * V_154 ;
V_154 = V_75 -> V_239 . V_54 ;
if ( V_154 )
return V_154 -> V_47 ;
return NULL ;
}
static inline struct V_153 *
F_216 ( int V_82 , int V_76 , int V_77 )
{
struct V_153 * V_154 ;
F_128 (info, &device_domain_list, global)
if ( V_154 -> V_54 -> V_82 == V_82 && V_154 -> V_76 == V_76 &&
V_154 -> V_77 == V_77 )
return V_154 ;
return NULL ;
}
static struct V_46 * F_217 ( struct V_53 * V_54 ,
int V_76 , int V_77 ,
struct V_74 * V_75 ,
struct V_46 * V_47 )
{
struct V_46 * V_66 = NULL ;
struct V_153 * V_154 ;
unsigned long V_48 ;
V_154 = F_49 () ;
if ( ! V_154 )
return NULL ;
V_154 -> V_76 = V_76 ;
V_154 -> V_77 = V_77 ;
V_154 -> V_75 = V_75 ;
V_154 -> V_47 = V_47 ;
V_154 -> V_54 = V_54 ;
F_85 ( & V_156 , V_48 ) ;
if ( V_75 )
V_66 = F_215 ( V_75 ) ;
else {
struct V_153 * V_240 ;
V_240 = F_216 ( V_54 -> V_82 , V_76 , V_77 ) ;
if ( V_240 )
V_66 = V_240 -> V_47 ;
}
if ( V_66 ) {
F_86 ( & V_156 , V_48 ) ;
F_50 ( V_154 ) ;
return V_66 ;
}
F_218 ( & V_154 -> V_237 , & V_47 -> V_83 ) ;
F_218 ( & V_154 -> V_238 , & V_241 ) ;
if ( V_75 )
V_75 -> V_239 . V_54 = V_154 ;
F_86 ( & V_156 , V_48 ) ;
return V_47 ;
}
static int F_219 ( struct V_79 * V_81 , T_3 V_209 , void * V_210 )
{
* ( T_3 * ) V_210 = V_209 ;
return 0 ;
}
static struct V_46 * F_220 ( struct V_74 * V_75 , int V_115 )
{
struct V_46 * V_47 , * V_78 ;
struct V_53 * V_54 ;
struct V_153 * V_154 ;
T_3 V_242 ;
unsigned long V_48 ;
T_2 V_76 , V_77 ;
V_47 = F_215 ( V_75 ) ;
if ( V_47 )
return V_47 ;
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return NULL ;
if ( F_77 ( V_75 ) ) {
struct V_79 * V_81 = F_78 ( V_75 ) ;
F_194 ( V_81 , F_219 , & V_242 ) ;
F_85 ( & V_156 , V_48 ) ;
V_154 = F_216 ( F_79 ( V_81 -> V_76 ) ,
F_192 ( V_242 ) ,
V_242 & 0xff ) ;
if ( V_154 ) {
V_54 = V_154 -> V_54 ;
V_47 = V_154 -> V_47 ;
}
F_86 ( & V_156 , V_48 ) ;
if ( V_154 )
goto V_243;
}
V_47 = F_160 ( 0 ) ;
if ( ! V_47 )
return NULL ;
V_47 -> V_179 = F_166 ( V_47 , V_54 ) ;
if ( V_47 -> V_179 < 0 ) {
F_47 ( V_47 ) ;
return NULL ;
}
F_169 ( V_47 , V_54 ) ;
if ( F_181 ( V_47 , V_115 ) ) {
F_159 ( V_47 ) ;
return NULL ;
}
if ( F_77 ( V_75 ) ) {
V_78 = F_217 ( V_54 , F_192 ( V_242 ) ,
V_242 & 0xff , NULL , V_47 ) ;
if ( ! V_78 || V_78 != V_47 ) {
F_159 ( V_47 ) ;
V_47 = V_78 ;
}
if ( ! V_47 )
return NULL ;
}
V_243:
V_78 = F_217 ( V_54 , V_76 , V_77 , V_75 , V_47 ) ;
if ( ! V_78 || V_78 != V_47 ) {
F_159 ( V_47 ) ;
V_47 = V_78 ;
}
return V_47 ;
}
static int F_221 ( struct V_46 * V_47 ,
unsigned long long V_196 ,
unsigned long long V_88 )
{
unsigned long V_244 = V_196 >> V_12 ;
unsigned long V_245 = V_88 >> V_12 ;
if ( ! F_175 ( & V_47 -> V_197 , F_12 ( V_244 ) ,
F_12 ( V_245 ) ) ) {
F_39 ( V_152 L_25 ) ;
return - V_119 ;
}
F_125 ( L_26 ,
V_196 , V_88 , V_47 -> V_179 ) ;
F_95 ( V_47 , V_244 , V_245 ) ;
return F_208 ( V_47 , V_244 , V_244 ,
V_245 - V_244 + 1 ,
V_105 | V_106 ) ;
}
static int F_222 ( struct V_74 * V_75 ,
unsigned long long V_196 ,
unsigned long long V_88 )
{
struct V_46 * V_47 ;
int V_70 ;
V_47 = F_220 ( V_75 , V_58 ) ;
if ( ! V_47 )
return - V_119 ;
if ( V_47 == V_246 && V_247 ) {
F_39 ( L_27 ,
F_223 ( V_75 ) , V_196 , V_88 ) ;
return 0 ;
}
F_39 ( V_33
L_28 ,
F_223 ( V_75 ) , V_196 , V_88 ) ;
if ( V_88 < V_196 ) {
F_224 ( 1 , L_29
L_30 ,
F_225 ( V_248 ) ,
F_225 ( V_249 ) ,
F_225 ( V_250 ) ) ;
V_70 = - V_251 ;
goto error;
}
if ( V_88 >> F_2 ( V_47 -> V_1 ) ) {
F_224 ( 1 , L_31
L_30 ,
F_2 ( V_47 -> V_1 ) ,
F_225 ( V_248 ) ,
F_225 ( V_249 ) ,
F_225 ( V_250 ) ) ;
V_70 = - V_251 ;
goto error;
}
V_70 = F_221 ( V_47 , V_196 , V_88 ) ;
if ( V_70 )
goto error;
V_70 = F_193 ( V_47 , V_75 , V_203 ) ;
if ( V_70 )
goto error;
return 0 ;
error:
F_159 ( V_47 ) ;
return V_70 ;
}
static inline int F_226 ( struct V_252 * V_253 ,
struct V_74 * V_75 )
{
if ( V_75 -> V_239 . V_54 == V_254 )
return 0 ;
return F_222 ( V_75 , V_253 -> V_255 ,
V_253 -> V_256 ) ;
}
static inline void F_227 ( void )
{
struct V_79 * V_81 ;
int V_70 ;
V_81 = F_228 ( V_257 << 8 , NULL ) ;
if ( ! V_81 )
return;
F_39 ( V_33 L_32 ) ;
V_70 = F_222 ( & V_81 -> V_75 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_70 )
F_39 ( V_152 L_33
L_34 ) ;
F_229 ( V_81 ) ;
}
static inline void F_227 ( void )
{
return;
}
static int T_1 F_230 ( int V_258 )
{
struct V_63 * V_64 ;
struct V_53 * V_54 ;
int V_103 , V_70 = 0 ;
bool V_259 = true ;
V_246 = F_160 ( V_50 ) ;
if ( ! V_246 )
return - V_204 ;
F_68 (iommu, drhd) {
V_70 = F_166 ( V_246 , V_54 ) ;
if ( V_70 < 0 ) {
F_159 ( V_246 ) ;
return - V_204 ;
} else if ( V_259 ) {
V_246 -> V_179 = V_70 ;
V_259 = false ;
} else if ( V_246 -> V_179 != V_70 ) {
F_159 ( V_246 ) ;
return - V_204 ;
}
F_169 ( V_246 , V_54 ) ;
}
if ( F_231 ( V_246 , V_58 ) ) {
F_159 ( V_246 ) ;
return - V_204 ;
}
F_125 ( L_35 ,
V_246 -> V_179 ) ;
if ( V_258 )
return 0 ;
F_232 (nid) {
unsigned long V_109 , V_260 ;
int V_65 ;
F_233 (i, nid, &start_pfn, &end_pfn, NULL) {
V_70 = F_221 ( V_246 ,
F_234 ( V_109 ) , F_234 ( V_260 ) ) ;
if ( V_70 )
return V_70 ;
}
}
return 0 ;
}
static int F_235 ( struct V_74 * V_75 )
{
struct V_153 * V_154 ;
if ( F_236 ( ! V_261 ) )
return 0 ;
V_154 = V_75 -> V_239 . V_54 ;
if ( V_154 && V_154 != V_254 )
return ( V_154 -> V_47 == V_246 ) ;
return 0 ;
}
static int F_237 ( struct V_46 * V_47 ,
struct V_74 * V_75 , int V_201 )
{
struct V_46 * V_262 ;
struct V_53 * V_54 ;
T_2 V_76 , V_77 ;
int V_70 ;
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return - V_191 ;
V_262 = F_217 ( V_54 , V_76 , V_77 , V_75 , V_47 ) ;
if ( V_262 != V_47 )
return - V_263 ;
V_70 = F_193 ( V_47 , V_75 , V_201 ) ;
if ( V_70 ) {
F_238 ( V_47 , V_75 ) ;
return V_70 ;
}
return 0 ;
}
static bool F_239 ( struct V_74 * V_75 )
{
struct V_252 * V_253 ;
struct V_74 * V_78 ;
int V_65 ;
F_67 () ;
F_240 (rmrr) {
F_81 (rmrr->devices,
rmrr->devices_cnt, i, tmp)
if ( V_78 == V_75 ) {
F_69 () ;
return true ;
}
}
F_69 () ;
return false ;
}
static bool F_241 ( struct V_74 * V_75 )
{
if ( ! F_239 ( V_75 ) )
return false ;
if ( F_77 ( V_75 ) ) {
struct V_79 * V_81 = F_78 ( V_75 ) ;
if ( ( V_81 -> V_264 >> 8 ) == V_265 )
return false ;
}
return true ;
}
static int F_242 ( struct V_74 * V_75 , int V_266 )
{
if ( F_77 ( V_75 ) ) {
struct V_79 * V_81 = F_78 ( V_75 ) ;
if ( F_241 ( V_75 ) )
return 0 ;
if ( ( V_261 & V_267 ) && F_243 ( V_81 ) )
return 1 ;
if ( ( V_261 & V_268 ) && F_244 ( V_81 ) )
return 1 ;
if ( ! ( V_261 & V_269 ) )
return 0 ;
if ( ! F_245 ( V_81 ) ) {
if ( ! F_246 ( V_81 -> V_76 ) )
return 0 ;
if ( V_81 -> V_264 >> 8 == V_270 )
return 0 ;
} else if ( F_247 ( V_81 ) == V_271 )
return 0 ;
} else {
if ( F_239 ( V_75 ) )
return 0 ;
}
if ( ! V_266 ) {
V_25 V_272 = * V_75 -> V_272 ;
if ( V_75 -> V_273 &&
V_75 -> V_273 < V_272 )
V_272 = V_75 -> V_273 ;
return V_272 >= F_248 ( V_75 ) ;
}
return 1 ;
}
static int T_1 F_249 ( struct V_74 * V_75 , int V_258 )
{
int V_70 ;
if ( ! F_242 ( V_75 , 1 ) )
return 0 ;
V_70 = F_237 ( V_246 , V_75 ,
V_258 ? V_202 :
V_203 ) ;
if ( ! V_70 )
F_250 ( L_36 ,
V_258 ? L_37 : L_38 , F_223 ( V_75 ) ) ;
else if ( V_70 == - V_191 )
V_70 = 0 ;
return V_70 ;
}
static int T_1 F_251 ( int V_258 )
{
struct V_79 * V_81 = NULL ;
struct V_63 * V_64 ;
struct V_53 * V_54 ;
struct V_74 * V_75 ;
int V_65 ;
int V_70 = 0 ;
V_70 = F_230 ( V_258 ) ;
if ( V_70 )
return - V_204 ;
F_177 (pdev) {
V_70 = F_249 ( & V_81 -> V_75 , V_258 ) ;
if ( V_70 )
return V_70 ;
}
F_68 (iommu, drhd)
F_81 (drhd->devices, drhd->devices_cnt, i, dev) {
struct V_274 * V_275 ;
struct V_276 * V_277 ;
if ( V_75 -> V_76 != & V_278 )
continue;
V_277 = F_252 ( V_75 ) ;
F_253 ( & V_277 -> V_279 ) ;
F_128 (pn, &adev->physical_node_list, node) {
V_70 = F_249 ( V_275 -> V_75 , V_258 ) ;
if ( V_70 )
break;
}
F_254 ( & V_277 -> V_279 ) ;
if ( V_70 )
return V_70 ;
}
return 0 ;
}
static int T_1 F_255 ( void )
{
struct V_63 * V_64 ;
struct V_252 * V_253 ;
struct V_74 * V_75 ;
struct V_53 * V_54 ;
int V_65 , V_70 ;
F_256 (drhd) {
if ( V_61 < V_280 ) {
V_61 ++ ;
continue;
}
F_257 ( V_152 L_39 ,
V_280 ) ;
}
V_62 = F_152 ( V_61 , sizeof( struct V_53 * ) ,
V_176 ) ;
if ( ! V_62 ) {
F_39 ( V_152 L_40 ) ;
V_70 = - V_119 ;
goto error;
}
V_281 = F_258 ( V_61 *
sizeof( struct V_282 ) , V_176 ) ;
if ( ! V_281 ) {
V_70 = - V_119 ;
goto V_283;
}
F_68 (iommu, drhd) {
V_62 [ V_54 -> V_174 ] = V_54 ;
V_70 = F_148 ( V_54 ) ;
if ( V_70 )
goto V_284;
V_70 = F_105 ( V_54 ) ;
if ( V_70 ) {
F_39 ( V_152 L_41 ) ;
goto V_284;
}
if ( ! F_259 ( V_54 -> V_68 ) )
V_247 = 0 ;
}
F_68 (iommu, drhd) {
if ( V_54 -> V_155 )
continue;
F_260 ( - 1 , V_54 ) ;
F_261 ( V_54 ) ;
}
F_68 (iommu, drhd) {
if ( F_262 ( V_54 ) ) {
V_54 -> V_163 . V_207 = F_114 ;
V_54 -> V_163 . V_164 = F_119 ;
F_39 ( V_33 L_42
L_43 ,
V_54 -> V_174 ,
( unsigned long long ) V_64 -> V_285 ) ;
} else {
V_54 -> V_163 . V_207 = V_286 ;
V_54 -> V_163 . V_164 = V_287 ;
F_39 ( V_33 L_44
L_43 ,
V_54 -> V_174 ,
( unsigned long long ) V_64 -> V_285 ) ;
}
}
if ( V_288 )
V_261 |= V_269 ;
#ifdef F_263
V_261 |= V_268 ;
#endif
F_264 () ;
if ( V_261 ) {
V_70 = F_251 ( V_247 ) ;
if ( V_70 ) {
F_39 ( V_236 L_45 ) ;
goto V_284;
}
}
F_39 ( V_33 L_46 ) ;
F_240 (rmrr) {
F_81 (rmrr->devices, rmrr->devices_cnt,
i, dev) {
V_70 = F_226 ( V_253 , V_75 ) ;
if ( V_70 )
F_39 ( V_152
L_47 ) ;
}
}
F_227 () ;
F_265 (iommu, drhd) {
if ( V_64 -> V_289 ) {
if ( V_290 )
F_145 ( V_54 ) ;
continue;
}
F_112 ( V_54 ) ;
V_70 = F_266 ( V_54 ) ;
if ( V_70 )
goto V_284;
F_106 ( V_54 ) ;
V_54 -> V_163 . V_207 ( V_54 , 0 , 0 , 0 , V_138 ) ;
V_54 -> V_163 . V_164 ( V_54 , 0 , 0 , 0 , V_147 ) ;
F_146 ( V_54 ) ;
F_145 ( V_54 ) ;
}
return 0 ;
V_284:
F_68 (iommu, drhd)
F_156 ( V_54 ) ;
F_154 ( V_281 ) ;
V_283:
F_154 ( V_62 ) ;
error:
return V_70 ;
}
static struct V_44 * F_267 ( struct V_74 * V_75 ,
struct V_46 * V_47 ,
unsigned long V_291 , T_4 V_272 )
{
struct V_44 * V_44 = NULL ;
V_272 = F_3 ( T_4 , F_268 ( V_47 -> V_115 ) , V_272 ) ;
if ( ! V_35 && V_272 > F_269 ( 32 ) ) {
V_44 = F_270 ( & V_47 -> V_197 , V_291 ,
F_176 ( F_269 ( 32 ) ) , 1 ) ;
if ( V_44 )
return V_44 ;
}
V_44 = F_270 ( & V_47 -> V_197 , V_291 , F_176 ( V_272 ) , 1 ) ;
if ( F_190 ( ! V_44 ) ) {
F_39 ( V_152 L_48 ,
V_291 , F_223 ( V_75 ) ) ;
return NULL ;
}
return V_44 ;
}
static struct V_46 * F_271 ( struct V_74 * V_75 )
{
struct V_46 * V_47 ;
int V_70 ;
V_47 = F_220 ( V_75 , V_58 ) ;
if ( ! V_47 ) {
F_39 ( V_152 L_49 ,
F_223 ( V_75 ) ) ;
return NULL ;
}
if ( F_190 ( ! F_196 ( V_75 ) ) ) {
V_70 = F_193 ( V_47 , V_75 , V_203 ) ;
if ( V_70 ) {
F_39 ( V_152 L_50 ,
F_223 ( V_75 ) ) ;
return NULL ;
}
}
return V_47 ;
}
static inline struct V_46 * F_272 ( struct V_74 * V_75 )
{
struct V_153 * V_154 ;
V_154 = V_75 -> V_239 . V_54 ;
if ( F_236 ( V_154 ) )
return V_154 -> V_47 ;
return F_271 ( V_75 ) ;
}
static int F_273 ( struct V_74 * V_75 )
{
return V_75 -> V_239 . V_54 == V_254 ;
}
static int F_274 ( struct V_74 * V_75 )
{
int V_66 ;
if ( F_273 ( V_75 ) )
return 1 ;
if ( ! V_261 )
return 0 ;
V_66 = F_235 ( V_75 ) ;
if ( V_66 ) {
if ( F_242 ( V_75 , 0 ) )
return 1 ;
else {
F_238 ( V_246 , V_75 ) ;
F_39 ( V_33 L_51 ,
F_223 ( V_75 ) ) ;
return 0 ;
}
} else {
if ( F_242 ( V_75 , 0 ) ) {
int V_70 ;
V_70 = F_237 ( V_246 , V_75 ,
V_247 ?
V_202 :
V_203 ) ;
if ( ! V_70 ) {
F_39 ( V_33 L_52 ,
F_223 ( V_75 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_233 F_275 ( struct V_74 * V_75 , T_8 V_292 ,
T_7 V_92 , int V_293 , V_25 V_272 )
{
struct V_46 * V_47 ;
T_8 V_294 ;
struct V_44 * V_44 ;
int V_225 = 0 ;
int V_70 ;
struct V_53 * V_54 ;
unsigned long V_295 = V_292 >> V_11 ;
F_62 ( V_293 == V_296 ) ;
if ( F_274 ( V_75 ) )
return V_292 ;
V_47 = F_272 ( V_75 ) ;
if ( ! V_47 )
return 0 ;
V_54 = F_61 ( V_47 ) ;
V_92 = F_197 ( V_292 , V_92 ) ;
V_44 = F_267 ( V_75 , V_47 , F_12 ( V_92 ) , V_272 ) ;
if ( ! V_44 )
goto error;
if ( V_293 == V_297 || V_293 == V_298 || \
! F_276 ( V_54 -> V_57 ) )
V_225 |= V_105 ;
if ( V_293 == V_299 || V_293 == V_298 )
V_225 |= V_106 ;
V_70 = F_208 ( V_47 , F_13 ( V_44 -> V_300 ) ,
F_13 ( V_295 ) , V_92 , V_225 ) ;
if ( V_70 )
goto error;
if ( F_144 ( V_54 -> V_57 ) )
F_139 ( V_54 , V_47 -> V_179 , F_13 ( V_44 -> V_300 ) , V_92 , 0 , 1 ) ;
else
F_112 ( V_54 ) ;
V_294 = ( T_8 ) V_44 -> V_300 << V_11 ;
V_294 += V_292 & ~ V_214 ;
return V_294 ;
error:
if ( V_44 )
F_277 ( & V_47 -> V_197 , V_44 ) ;
F_39 ( V_152 L_53 ,
F_223 ( V_75 ) , V_92 , ( unsigned long long ) V_292 , V_293 ) ;
return 0 ;
}
static V_233 F_278 ( struct V_74 * V_75 , struct V_14 * V_14 ,
unsigned long V_99 , T_7 V_92 ,
enum V_301 V_293 ,
struct V_302 * V_303 )
{
return F_275 ( V_75 , F_201 ( V_14 ) + V_99 , V_92 ,
V_293 , * V_75 -> V_272 ) ;
}
static void F_279 ( void )
{
int V_65 , V_304 ;
V_305 = 0 ;
for ( V_65 = 0 ; V_65 < V_61 ; V_65 ++ ) {
struct V_53 * V_54 = V_62 [ V_65 ] ;
if ( ! V_54 )
continue;
if ( ! V_281 [ V_65 ] . V_114 )
continue;
if ( ! F_144 ( V_54 -> V_57 ) )
V_54 -> V_163 . V_164 ( V_54 , 0 , 0 , 0 ,
V_147 ) ;
for ( V_304 = 0 ; V_304 < V_281 [ V_65 ] . V_114 ; V_304 ++ ) {
unsigned long V_71 ;
struct V_44 * V_44 = V_281 [ V_65 ] . V_44 [ V_304 ] ;
struct V_46 * V_47 = V_281 [ V_65 ] . V_47 [ V_304 ] ;
if ( F_144 ( V_54 -> V_57 ) )
F_139 ( V_54 , V_47 -> V_179 ,
V_44 -> V_300 , F_280 ( V_44 ) ,
! V_281 [ V_65 ] . V_116 [ V_304 ] , 0 ) ;
else {
V_71 = F_140 ( F_13 ( F_280 ( V_44 ) ) ) ;
F_136 ( V_281 [ V_65 ] . V_47 [ V_304 ] ,
( T_4 ) V_44 -> V_300 << V_11 , V_71 ) ;
}
F_277 ( & V_281 [ V_65 ] . V_47 [ V_304 ] -> V_197 , V_44 ) ;
if ( V_281 [ V_65 ] . V_116 [ V_304 ] )
F_104 ( V_281 [ V_65 ] . V_116 [ V_304 ] ) ;
}
V_281 [ V_65 ] . V_114 = 0 ;
}
V_306 = 0 ;
}
static void F_184 ( unsigned long V_212 )
{
unsigned long V_48 ;
F_85 ( & V_307 , V_48 ) ;
F_279 () ;
F_86 ( & V_307 , V_48 ) ;
}
static void F_281 ( struct V_46 * V_308 , struct V_44 * V_44 , struct V_14 * V_116 )
{
unsigned long V_48 ;
int V_114 , V_59 ;
struct V_53 * V_54 ;
F_85 ( & V_307 , V_48 ) ;
if ( V_306 == V_309 )
F_279 () ;
V_54 = F_61 ( V_308 ) ;
V_59 = V_54 -> V_174 ;
V_114 = V_281 [ V_59 ] . V_114 ;
V_281 [ V_59 ] . V_47 [ V_114 ] = V_308 ;
V_281 [ V_59 ] . V_44 [ V_114 ] = V_44 ;
V_281 [ V_59 ] . V_116 [ V_114 ] = V_116 ;
V_281 [ V_59 ] . V_114 ++ ;
if ( ! V_305 ) {
F_282 ( & V_310 , V_311 + F_283 ( 10 ) ) ;
V_305 = 1 ;
}
V_306 ++ ;
F_86 ( & V_307 , V_48 ) ;
}
static void F_284 ( struct V_74 * V_75 , V_233 V_312 )
{
struct V_46 * V_47 ;
unsigned long V_109 , V_110 ;
struct V_44 * V_44 ;
struct V_53 * V_54 ;
struct V_14 * V_116 ;
if ( F_274 ( V_75 ) )
return;
V_47 = F_215 ( V_75 ) ;
F_62 ( ! V_47 ) ;
V_54 = F_61 ( V_47 ) ;
V_44 = F_285 ( & V_47 -> V_197 , F_176 ( V_312 ) ) ;
if ( F_286 ( ! V_44 , L_54 ,
( unsigned long long ) V_312 ) )
return;
V_109 = F_13 ( V_44 -> V_300 ) ;
V_110 = F_13 ( V_44 -> V_313 + 1 ) - 1 ;
F_125 ( L_55 ,
F_223 ( V_75 ) , V_109 , V_110 ) ;
V_116 = F_103 ( V_47 , V_109 , V_110 ) ;
if ( V_36 ) {
F_139 ( V_54 , V_47 -> V_179 , V_109 ,
V_110 - V_109 + 1 , ! V_116 , 0 ) ;
F_277 ( & V_47 -> V_197 , V_44 ) ;
F_104 ( V_116 ) ;
} else {
F_281 ( V_47 , V_44 , V_116 ) ;
}
}
static void F_287 ( struct V_74 * V_75 , V_233 V_312 ,
T_7 V_92 , enum V_301 V_293 ,
struct V_302 * V_303 )
{
F_284 ( V_75 , V_312 ) ;
}
static void * F_288 ( struct V_74 * V_75 , T_7 V_92 ,
V_233 * V_314 , T_9 V_48 ,
struct V_302 * V_303 )
{
struct V_14 * V_14 = NULL ;
int V_315 ;
V_92 = F_198 ( V_92 ) ;
V_315 = F_289 ( V_92 ) ;
if ( ! F_274 ( V_75 ) )
V_48 &= ~ ( V_316 | V_317 ) ;
else if ( V_75 -> V_273 < F_248 ( V_75 ) ) {
if ( V_75 -> V_273 < F_269 ( 32 ) )
V_48 |= V_316 ;
else
V_48 |= V_317 ;
}
if ( V_48 & V_318 ) {
unsigned int V_183 = V_92 >> V_11 ;
V_14 = F_290 ( V_75 , V_183 , V_315 ) ;
if ( V_14 && F_274 ( V_75 ) &&
F_201 ( V_14 ) + V_92 > V_75 -> V_273 ) {
F_291 ( V_75 , V_14 , V_183 ) ;
V_14 = NULL ;
}
}
if ( ! V_14 )
V_14 = F_292 ( V_48 , V_315 ) ;
if ( ! V_14 )
return NULL ;
memset ( F_42 ( V_14 ) , 0 , V_92 ) ;
* V_314 = F_275 ( V_75 , F_201 ( V_14 ) , V_92 ,
V_298 ,
V_75 -> V_273 ) ;
if ( * V_314 )
return F_42 ( V_14 ) ;
if ( ! F_291 ( V_75 , V_14 , V_92 >> V_11 ) )
F_293 ( V_14 , V_315 ) ;
return NULL ;
}
static void F_294 ( struct V_74 * V_75 , T_7 V_92 , void * V_39 ,
V_233 V_314 , struct V_302 * V_303 )
{
int V_315 ;
struct V_14 * V_14 = F_17 ( V_39 ) ;
V_92 = F_198 ( V_92 ) ;
V_315 = F_289 ( V_92 ) ;
F_284 ( V_75 , V_314 ) ;
if ( ! F_291 ( V_75 , V_14 , V_92 >> V_11 ) )
F_293 ( V_14 , V_315 ) ;
}
static void F_295 ( struct V_74 * V_75 , struct V_221 * V_319 ,
int V_320 , enum V_301 V_293 ,
struct V_302 * V_303 )
{
F_284 ( V_75 , V_319 [ 0 ] . V_232 ) ;
}
static int F_296 ( struct V_74 * V_321 ,
struct V_221 * V_319 , int V_320 , int V_293 )
{
int V_65 ;
struct V_221 * V_222 ;
F_297 (sglist, sg, nelems, i) {
F_62 ( ! F_202 ( V_222 ) ) ;
V_222 -> V_232 = F_201 ( F_202 ( V_222 ) ) + V_222 -> V_99 ;
V_222 -> V_234 = V_222 -> V_231 ;
}
return V_320 ;
}
static int F_298 ( struct V_74 * V_75 , struct V_221 * V_319 , int V_320 ,
enum V_301 V_293 , struct V_302 * V_303 )
{
int V_65 ;
struct V_46 * V_47 ;
T_7 V_92 = 0 ;
int V_225 = 0 ;
struct V_44 * V_44 = NULL ;
int V_70 ;
struct V_221 * V_222 ;
unsigned long V_322 ;
struct V_53 * V_54 ;
F_62 ( V_293 == V_296 ) ;
if ( F_274 ( V_75 ) )
return F_296 ( V_75 , V_319 , V_320 , V_293 ) ;
V_47 = F_272 ( V_75 ) ;
if ( ! V_47 )
return 0 ;
V_54 = F_61 ( V_47 ) ;
F_297 (sglist, sg, nelems, i)
V_92 += F_197 ( V_222 -> V_99 , V_222 -> V_231 ) ;
V_44 = F_267 ( V_75 , V_47 , F_12 ( V_92 ) ,
* V_75 -> V_272 ) ;
if ( ! V_44 ) {
V_319 -> V_234 = 0 ;
return 0 ;
}
if ( V_293 == V_297 || V_293 == V_298 || \
! F_276 ( V_54 -> V_57 ) )
V_225 |= V_105 ;
if ( V_293 == V_299 || V_293 == V_298 )
V_225 |= V_106 ;
V_322 = F_13 ( V_44 -> V_300 ) ;
V_70 = F_207 ( V_47 , V_322 , V_319 , V_92 , V_225 ) ;
if ( F_190 ( V_70 ) ) {
F_98 ( V_47 , V_322 ,
V_322 + V_92 - 1 ) ;
F_277 ( & V_47 -> V_197 , V_44 ) ;
return 0 ;
}
if ( F_144 ( V_54 -> V_57 ) )
F_139 ( V_54 , V_47 -> V_179 , V_322 , V_92 , 0 , 1 ) ;
else
F_112 ( V_54 ) ;
return V_320 ;
}
static int F_299 ( struct V_74 * V_75 , V_233 V_323 )
{
return ! V_323 ;
}
static inline int F_300 ( void )
{
int V_70 = 0 ;
V_42 = F_301 ( L_56 ,
sizeof( struct V_46 ) ,
0 ,
V_324 ,
NULL ) ;
if ( ! V_42 ) {
F_39 ( V_152 L_57 ) ;
V_70 = - V_119 ;
}
return V_70 ;
}
static inline int F_302 ( void )
{
int V_70 = 0 ;
V_43 = F_301 ( L_58 ,
sizeof( struct V_153 ) ,
0 ,
V_324 ,
NULL ) ;
if ( ! V_43 ) {
F_39 ( V_152 L_59 ) ;
V_70 = - V_119 ;
}
return V_70 ;
}
static inline int F_303 ( void )
{
int V_70 = 0 ;
V_45 = F_301 ( L_60 ,
sizeof( struct V_44 ) ,
0 ,
V_324 ,
NULL ) ;
if ( ! V_45 ) {
F_39 ( V_152 L_61 ) ;
V_70 = - V_119 ;
}
return V_70 ;
}
static int T_1 F_304 ( void )
{
int V_70 ;
V_70 = F_303 () ;
if ( V_70 )
return V_70 ;
V_70 = F_300 () ;
if ( V_70 )
goto V_325;
V_70 = F_302 () ;
if ( ! V_70 )
return V_70 ;
F_305 ( V_42 ) ;
V_325:
F_305 ( V_45 ) ;
return - V_119 ;
}
static void T_1 F_306 ( void )
{
F_305 ( V_43 ) ;
F_305 ( V_42 ) ;
F_305 ( V_45 ) ;
}
static void F_307 ( struct V_79 * V_81 )
{
struct V_63 * V_64 ;
T_5 V_326 ;
int V_327 ;
V_327 = F_308 ( V_81 -> V_76 , F_309 ( 0 , 0 ) , 0xb0 , & V_326 ) ;
if ( V_327 ) {
F_310 ( & V_81 -> V_75 , L_62 ) ;
return;
}
V_326 &= 0xffff0000 ;
V_64 = F_311 ( V_81 ) ;
if ( F_312 ( ! V_64 || V_64 -> V_285 - V_326 != 0xa000 ,
V_328 ,
L_63 ) )
V_81 -> V_75 . V_239 . V_54 = V_254 ;
}
static void T_1 F_313 ( void )
{
struct V_63 * V_64 ;
struct V_74 * V_75 ;
int V_65 ;
F_256 (drhd) {
if ( ! V_64 -> V_90 ) {
F_81 (drhd->devices,
drhd->devices_cnt, i, dev)
break;
if ( V_65 == V_64 -> V_329 )
V_64 -> V_289 = 1 ;
}
}
F_314 (drhd) {
if ( V_64 -> V_90 )
continue;
F_81 (drhd->devices,
drhd->devices_cnt, i, dev)
if ( ! F_77 ( V_75 ) || ! F_244 ( F_78 ( V_75 ) ) )
break;
if ( V_65 < V_64 -> V_329 )
continue;
if ( V_34 ) {
V_330 = 1 ;
} else {
V_64 -> V_289 = 1 ;
F_81 (drhd->devices,
drhd->devices_cnt, i, dev)
V_75 -> V_239 . V_54 = V_254 ;
}
}
}
static int F_315 ( void )
{
struct V_63 * V_64 ;
struct V_53 * V_54 = NULL ;
F_68 (iommu, drhd)
if ( V_54 -> V_155 )
F_316 ( V_54 ) ;
F_265 (iommu, drhd) {
if ( V_64 -> V_289 ) {
if ( V_290 )
F_145 ( V_54 ) ;
continue;
}
F_112 ( V_54 ) ;
F_106 ( V_54 ) ;
V_54 -> V_163 . V_207 ( V_54 , 0 , 0 , 0 ,
V_138 ) ;
V_54 -> V_163 . V_164 ( V_54 , 0 , 0 , 0 , V_147 ) ;
F_146 ( V_54 ) ;
F_145 ( V_54 ) ;
}
return 0 ;
}
static void F_317 ( void )
{
struct V_63 * V_64 ;
struct V_53 * V_54 ;
F_68 (iommu, drhd) {
V_54 -> V_163 . V_207 ( V_54 , 0 , 0 , 0 ,
V_138 ) ;
V_54 -> V_163 . V_164 ( V_54 , 0 , 0 , 0 ,
V_147 ) ;
}
}
static int F_318 ( void )
{
struct V_63 * V_64 ;
struct V_53 * V_54 = NULL ;
unsigned long V_122 ;
F_68 (iommu, drhd) {
V_54 -> V_331 = F_258 ( sizeof( T_5 ) * V_332 ,
V_40 ) ;
if ( ! V_54 -> V_331 )
goto V_333;
}
F_317 () ;
F_68 (iommu, drhd) {
F_147 ( V_54 ) ;
F_107 ( & V_54 -> V_123 , V_122 ) ;
V_54 -> V_331 [ V_334 ] =
V_130 ( V_54 -> V_124 + V_335 ) ;
V_54 -> V_331 [ V_336 ] =
V_130 ( V_54 -> V_124 + V_337 ) ;
V_54 -> V_331 [ V_338 ] =
V_130 ( V_54 -> V_124 + V_339 ) ;
V_54 -> V_331 [ V_340 ] =
V_130 ( V_54 -> V_124 + V_341 ) ;
F_111 ( & V_54 -> V_123 , V_122 ) ;
}
return 0 ;
V_333:
F_68 (iommu, drhd)
F_154 ( V_54 -> V_331 ) ;
return - V_119 ;
}
static void F_319 ( void )
{
struct V_63 * V_64 ;
struct V_53 * V_54 = NULL ;
unsigned long V_122 ;
if ( F_315 () ) {
if ( V_290 )
F_320 ( L_64 ) ;
else
F_224 ( 1 , L_65 ) ;
return;
}
F_68 (iommu, drhd) {
F_107 ( & V_54 -> V_123 , V_122 ) ;
F_109 ( V_54 -> V_331 [ V_334 ] ,
V_54 -> V_124 + V_335 ) ;
F_109 ( V_54 -> V_331 [ V_336 ] ,
V_54 -> V_124 + V_337 ) ;
F_109 ( V_54 -> V_331 [ V_338 ] ,
V_54 -> V_124 + V_339 ) ;
F_109 ( V_54 -> V_331 [ V_340 ] ,
V_54 -> V_124 + V_341 ) ;
F_111 ( & V_54 -> V_123 , V_122 ) ;
}
F_68 (iommu, drhd)
F_154 ( V_54 -> V_331 ) ;
}
static void T_1 F_321 ( void )
{
F_322 ( & V_342 ) ;
}
static inline void F_321 ( void ) {}
int T_1 F_323 ( struct V_343 * V_344 )
{
struct V_345 * V_253 ;
struct V_252 * V_346 ;
V_346 = F_258 ( sizeof( * V_346 ) , V_176 ) ;
if ( ! V_346 )
return - V_119 ;
V_346 -> V_347 = V_344 ;
V_253 = (struct V_345 * ) V_344 ;
V_346 -> V_255 = V_253 -> V_255 ;
V_346 -> V_256 = V_253 -> V_256 ;
V_346 -> V_83 = F_324 ( ( void * ) ( V_253 + 1 ) ,
( ( void * ) V_253 ) + V_253 -> V_344 . V_231 ,
& V_346 -> V_329 ) ;
if ( V_346 -> V_329 && V_346 -> V_83 == NULL ) {
F_154 ( V_346 ) ;
return - V_119 ;
}
F_218 ( & V_346 -> V_348 , & V_349 ) ;
return 0 ;
}
int T_1 F_325 ( struct V_343 * V_347 )
{
struct V_350 * V_351 ;
struct V_352 * V_353 ;
V_351 = F_326 ( V_347 , struct V_350 , V_344 ) ;
V_353 = F_258 ( sizeof( * V_353 ) , V_176 ) ;
if ( ! V_353 )
return - V_119 ;
V_353 -> V_347 = V_347 ;
V_353 -> V_90 = V_351 -> V_48 & 0x1 ;
if ( ! V_353 -> V_90 ) {
V_353 -> V_83 = F_324 ( ( void * ) ( V_351 + 1 ) ,
( void * ) V_351 + V_351 -> V_344 . V_231 ,
& V_353 -> V_329 ) ;
if ( V_353 -> V_329 && V_353 -> V_83 == NULL ) {
F_154 ( V_353 ) ;
return - V_119 ;
}
}
F_327 ( & V_353 -> V_348 , & V_354 ) ;
return 0 ;
}
static void F_328 ( struct V_352 * V_353 )
{
F_329 ( & V_353 -> V_83 , & V_353 -> V_329 ) ;
F_154 ( V_353 ) ;
}
static void F_330 ( void )
{
struct V_252 * V_346 , * V_355 ;
struct V_352 * V_353 , * V_356 ;
F_213 (rmrru, rmrr_n, &dmar_rmrr_units, list) {
F_212 ( & V_346 -> V_348 ) ;
F_329 ( & V_346 -> V_83 , & V_346 -> V_329 ) ;
F_154 ( V_346 ) ;
}
F_213 (atsru, atsr_n, &dmar_atsr_units, list) {
F_212 ( & V_353 -> V_348 ) ;
F_328 ( V_353 ) ;
}
}
int F_130 ( struct V_79 * V_75 )
{
int V_65 , V_70 = 1 ;
struct V_357 * V_76 ;
struct V_79 * V_358 = NULL ;
struct V_74 * V_78 ;
struct V_350 * V_351 ;
struct V_352 * V_353 ;
V_75 = F_331 ( V_75 ) ;
for ( V_76 = V_75 -> V_76 ; V_76 ; V_76 = V_76 -> V_98 ) {
V_358 = V_76 -> V_359 ;
if ( ! V_358 || ! F_245 ( V_358 ) ||
F_247 ( V_358 ) == V_271 )
return 0 ;
if ( F_247 ( V_358 ) == V_360 )
break;
}
if ( ! V_358 )
return 0 ;
F_67 () ;
F_332 (atsru, &dmar_atsr_units, list) {
V_351 = F_326 ( V_353 -> V_347 , struct V_350 , V_344 ) ;
if ( V_351 -> V_82 != F_79 ( V_75 -> V_76 ) )
continue;
F_333 (atsru->devices, atsru->devices_cnt, i, tmp)
if ( V_78 == & V_358 -> V_75 )
goto V_84;
if ( V_353 -> V_90 )
goto V_84;
}
V_70 = 0 ;
V_84:
F_69 () ;
return V_70 ;
}
int F_334 ( struct V_361 * V_154 )
{
int V_70 = 0 ;
struct V_252 * V_346 ;
struct V_352 * V_353 ;
struct V_350 * V_351 ;
struct V_345 * V_253 ;
if ( ! V_362 && V_363 != V_364 )
return 0 ;
F_128 (rmrru, &dmar_rmrr_units, list) {
V_253 = F_326 ( V_346 -> V_347 ,
struct V_345 , V_344 ) ;
if ( V_154 -> V_365 == V_366 ) {
V_70 = F_335 ( V_154 , ( void * ) ( V_253 + 1 ) ,
( ( void * ) V_253 ) + V_253 -> V_344 . V_231 ,
V_253 -> V_82 , V_346 -> V_83 ,
V_346 -> V_329 ) ;
if( V_70 < 0 )
return V_70 ;
} else if ( V_154 -> V_365 == V_367 ) {
F_336 ( V_154 , V_253 -> V_82 ,
V_346 -> V_83 , V_346 -> V_329 ) ;
}
}
F_128 (atsru, &dmar_atsr_units, list) {
if ( V_353 -> V_90 )
continue;
V_351 = F_326 ( V_353 -> V_347 , struct V_350 , V_344 ) ;
if ( V_154 -> V_365 == V_366 ) {
V_70 = F_335 ( V_154 , ( void * ) ( V_351 + 1 ) ,
( void * ) V_351 + V_351 -> V_344 . V_231 ,
V_351 -> V_82 , V_353 -> V_83 ,
V_353 -> V_329 ) ;
if ( V_70 > 0 )
break;
else if( V_70 < 0 )
return V_70 ;
} else if ( V_154 -> V_365 == V_367 ) {
if ( F_336 ( V_154 , V_351 -> V_82 ,
V_353 -> V_83 , V_353 -> V_329 ) )
break;
}
}
return 0 ;
}
static int F_337 ( struct V_368 * V_369 ,
unsigned long V_370 , void * V_212 )
{
struct V_74 * V_75 = V_212 ;
struct V_46 * V_47 ;
if ( F_273 ( V_75 ) )
return 0 ;
if ( V_370 != V_371 )
return 0 ;
if ( V_370 == V_367 && V_75 -> V_372 != NULL )
return 0 ;
V_47 = F_215 ( V_75 ) ;
if ( ! V_47 )
return 0 ;
F_338 ( & V_373 ) ;
F_238 ( V_47 , V_75 ) ;
if ( ! F_54 ( V_47 ) && F_339 ( & V_47 -> V_83 ) )
F_159 ( V_47 ) ;
F_340 ( & V_373 ) ;
return 0 ;
}
static int F_341 ( struct V_368 * V_369 ,
unsigned long V_19 , void * V_374 )
{
struct V_375 * V_376 = V_374 ;
unsigned long long V_196 , V_88 ;
unsigned long V_322 , V_245 ;
switch ( V_19 ) {
case V_377 :
V_196 = V_376 -> V_109 << V_11 ;
V_88 = ( ( V_376 -> V_109 + V_376 -> V_224 ) << V_11 ) - 1 ;
if ( F_221 ( V_246 , V_196 , V_88 ) ) {
F_342 ( L_66 ,
V_196 , V_88 ) ;
return V_378 ;
}
break;
case V_379 :
case V_380 :
V_322 = F_13 ( V_376 -> V_109 ) ;
V_245 = F_13 ( V_376 -> V_109 + V_376 -> V_224 - 1 ) ;
while ( V_322 <= V_245 ) {
struct V_44 * V_44 ;
struct V_63 * V_64 ;
struct V_53 * V_54 ;
struct V_14 * V_116 ;
V_44 = F_285 ( & V_246 -> V_197 , V_322 ) ;
if ( V_44 == NULL ) {
F_125 ( L_67 ,
V_322 ) ;
break;
}
V_44 = F_343 ( & V_246 -> V_197 , V_44 ,
V_322 , V_245 ) ;
if ( V_44 == NULL ) {
F_342 ( L_68 ,
V_322 , V_245 ) ;
return V_378 ;
}
V_116 = F_103 ( V_246 , V_44 -> V_300 ,
V_44 -> V_313 ) ;
F_67 () ;
F_68 (iommu, drhd)
F_139 ( V_54 , V_246 -> V_179 ,
V_44 -> V_300 , F_280 ( V_44 ) ,
! V_116 , 0 ) ;
F_69 () ;
F_104 ( V_116 ) ;
V_322 = V_44 -> V_313 + 1 ;
F_52 ( V_44 ) ;
}
break;
}
return V_381 ;
}
static T_10 F_344 ( struct V_74 * V_75 ,
struct V_382 * V_383 ,
char * V_384 )
{
struct V_53 * V_54 = F_345 ( V_75 ) ;
T_5 V_385 = V_130 ( V_54 -> V_124 + V_386 ) ;
return sprintf ( V_384 , L_69 ,
F_346 ( V_385 ) , F_347 ( V_385 ) ) ;
}
static T_10 F_348 ( struct V_74 * V_75 ,
struct V_382 * V_383 ,
char * V_384 )
{
struct V_53 * V_54 = F_345 ( V_75 ) ;
return sprintf ( V_384 , L_70 , V_54 -> V_387 ) ;
}
static T_10 F_349 ( struct V_74 * V_75 ,
struct V_382 * V_383 ,
char * V_384 )
{
struct V_53 * V_54 = F_345 ( V_75 ) ;
return sprintf ( V_384 , L_70 , V_54 -> V_57 ) ;
}
static T_10 F_350 ( struct V_74 * V_75 ,
struct V_382 * V_383 ,
char * V_384 )
{
struct V_53 * V_54 = F_345 ( V_75 ) ;
return sprintf ( V_384 , L_70 , V_54 -> V_68 ) ;
}
int T_1 F_351 ( void )
{
int V_70 = - V_191 ;
struct V_63 * V_64 ;
struct V_53 * V_54 ;
V_290 = F_352 () ;
if ( F_304 () ) {
if ( V_290 )
F_320 ( L_71 ) ;
return - V_119 ;
}
F_353 ( & V_373 ) ;
if ( F_354 () ) {
if ( V_290 )
F_320 ( L_72 ) ;
goto V_388;
}
F_68 (iommu, drhd)
if ( V_54 -> V_126 & V_170 )
F_147 ( V_54 ) ;
if ( F_355 () < 0 ) {
if ( V_290 )
F_320 ( L_73 ) ;
goto V_388;
}
if ( V_389 || V_32 )
goto V_388;
if ( F_339 ( & V_349 ) )
F_39 ( V_33 L_74 ) ;
if ( F_339 ( & V_354 ) )
F_39 ( V_33 L_75 ) ;
if ( F_172 () ) {
if ( V_290 )
F_320 ( L_76 ) ;
goto V_390;
}
F_313 () ;
V_70 = F_255 () ;
if ( V_70 ) {
if ( V_290 )
F_320 ( L_77 ) ;
F_39 ( V_152 L_78 ) ;
goto V_390;
}
F_356 ( & V_373 ) ;
F_39 ( V_33
L_79 ) ;
F_357 ( & V_310 ) ;
#ifdef F_358
V_391 = 0 ;
#endif
V_392 = & V_393 ;
F_321 () ;
F_68 (iommu, drhd)
V_54 -> V_394 = F_359 ( NULL , V_54 ,
V_395 ,
V_54 -> V_396 ) ;
F_360 ( & V_397 , & V_398 ) ;
F_361 ( & V_397 , & V_399 ) ;
if ( V_246 && ! V_247 )
F_362 ( & V_400 ) ;
V_362 = 1 ;
return 0 ;
V_390:
F_186 ( & V_185 ) ;
V_388:
F_330 () ;
F_356 ( & V_373 ) ;
F_306 () ;
return V_70 ;
}
static int F_363 ( struct V_79 * V_81 , T_3 V_209 , void * V_210 )
{
struct V_53 * V_54 = V_210 ;
F_209 ( V_54 , F_192 ( V_209 ) , V_209 & 0xff ) ;
return 0 ;
}
static void F_214 ( struct V_53 * V_54 ,
struct V_74 * V_75 )
{
if ( ! V_54 || ! V_75 || ! F_77 ( V_75 ) )
return;
F_194 ( F_78 ( V_75 ) , & F_363 , V_54 ) ;
}
static void F_238 ( struct V_46 * V_47 ,
struct V_74 * V_75 )
{
struct V_153 * V_154 , * V_78 ;
struct V_53 * V_54 ;
unsigned long V_48 ;
int V_66 = 0 ;
T_2 V_76 , V_77 ;
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return;
F_85 ( & V_156 , V_48 ) ;
F_213 (info, tmp, &domain->devices, link) {
if ( V_154 -> V_54 == V_54 && V_154 -> V_76 == V_76 &&
V_154 -> V_77 == V_77 ) {
F_210 ( V_154 ) ;
F_86 ( & V_156 , V_48 ) ;
F_133 ( V_154 ) ;
F_209 ( V_54 , V_154 -> V_76 , V_154 -> V_77 ) ;
F_214 ( V_54 , V_75 ) ;
F_50 ( V_154 ) ;
F_85 ( & V_156 , V_48 ) ;
if ( V_66 )
break;
else
continue;
}
if ( V_154 -> V_54 == V_54 )
V_66 = 1 ;
}
F_86 ( & V_156 , V_48 ) ;
if ( V_66 == 0 ) {
F_158 ( V_47 , V_54 ) ;
if ( ! F_54 ( V_47 ) )
F_168 ( V_47 , V_54 ) ;
}
}
static int F_231 ( struct V_46 * V_47 , int V_198 )
{
int V_199 ;
F_173 ( & V_47 -> V_197 , V_186 ) ;
F_178 ( V_47 ) ;
V_47 -> V_115 = V_198 ;
V_199 = F_180 ( V_198 ) ;
V_47 -> V_1 = F_4 ( V_199 ) ;
V_47 -> V_67 = 0 ;
V_47 -> V_72 = 0 ;
V_47 -> V_73 = 0 ;
V_47 -> V_401 = 0 ;
V_47 -> V_100 = (struct V_27 * ) F_40 ( V_47 -> V_103 ) ;
if ( ! V_47 -> V_100 )
return - V_119 ;
F_82 ( V_47 , V_47 -> V_100 , V_200 ) ;
return 0 ;
}
static int F_364 ( struct V_402 * V_47 )
{
struct V_46 * V_46 ;
V_46 = F_160 ( V_49 ) ;
if ( ! V_46 ) {
F_39 ( V_152
L_80 ) ;
return - V_119 ;
}
if ( F_231 ( V_46 , V_58 ) ) {
F_39 ( V_152
L_81 ) ;
F_159 ( V_46 ) ;
return - V_119 ;
}
F_75 ( V_46 ) ;
V_47 -> V_403 = V_46 ;
V_47 -> V_404 . V_405 = 0 ;
V_47 -> V_404 . V_406 = F_365 ( V_46 -> V_115 ) ;
V_47 -> V_404 . V_407 = true ;
return 0 ;
}
static void F_366 ( struct V_402 * V_47 )
{
struct V_46 * V_46 = V_47 -> V_403 ;
V_47 -> V_403 = NULL ;
F_159 ( V_46 ) ;
}
static int F_367 ( struct V_402 * V_47 ,
struct V_74 * V_75 )
{
struct V_46 * V_46 = V_47 -> V_403 ;
struct V_53 * V_54 ;
int V_51 ;
T_2 V_76 , V_77 ;
if ( F_241 ( V_75 ) ) {
F_368 ( V_75 , L_82 ) ;
return - V_408 ;
}
if ( F_190 ( F_196 ( V_75 ) ) ) {
struct V_46 * V_409 ;
V_409 = F_215 ( V_75 ) ;
if ( V_409 ) {
if ( F_54 ( V_46 ) )
F_238 ( V_409 , V_75 ) ;
else
F_185 ( V_409 ) ;
}
}
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return - V_191 ;
V_51 = F_2 ( V_54 -> V_1 ) ;
if ( V_51 > F_182 ( V_54 -> V_57 ) )
V_51 = F_182 ( V_54 -> V_57 ) ;
if ( V_46 -> V_401 > ( 1LL << V_51 ) ) {
F_39 ( V_152 L_83
L_84 ,
V_410 , V_51 , V_46 -> V_401 ) ;
return - V_204 ;
}
V_46 -> V_115 = V_51 ;
while ( V_54 -> V_1 < V_46 -> V_1 ) {
struct V_27 * V_28 ;
V_28 = V_46 -> V_100 ;
if ( F_35 ( V_28 ) ) {
V_46 -> V_100 = (struct V_27 * )
F_22 ( F_32 ( V_28 ) ) ;
F_43 ( V_28 ) ;
}
V_46 -> V_1 -- ;
}
return F_237 ( V_46 , V_75 , V_203 ) ;
}
static void F_369 ( struct V_402 * V_47 ,
struct V_74 * V_75 )
{
struct V_46 * V_46 = V_47 -> V_403 ;
F_238 ( V_46 , V_75 ) ;
}
static int F_370 ( struct V_402 * V_47 ,
unsigned long V_44 , T_8 V_411 ,
T_7 V_92 , int V_412 )
{
struct V_46 * V_46 = V_47 -> V_403 ;
V_25 V_401 ;
int V_225 = 0 ;
int V_70 ;
if ( V_412 & V_413 )
V_225 |= V_105 ;
if ( V_412 & V_414 )
V_225 |= V_106 ;
if ( ( V_412 & V_415 ) && V_46 -> V_72 )
V_225 |= V_230 ;
V_401 = V_44 + V_92 ;
if ( V_46 -> V_401 < V_401 ) {
V_25 V_88 ;
V_88 = F_365 ( V_46 -> V_115 ) + 1 ;
if ( V_88 < V_401 ) {
F_39 ( V_152 L_83
L_84 ,
V_410 , V_46 -> V_115 , V_401 ) ;
return - V_204 ;
}
V_46 -> V_401 = V_401 ;
}
V_92 = F_197 ( V_411 , V_92 ) ;
V_70 = F_208 ( V_46 , V_44 >> V_12 ,
V_411 >> V_12 , V_92 , V_225 ) ;
return V_70 ;
}
static T_7 F_371 ( struct V_402 * V_47 ,
unsigned long V_44 , T_7 V_92 )
{
struct V_46 * V_46 = V_47 -> V_403 ;
struct V_14 * V_116 = NULL ;
struct V_53 * V_54 ;
unsigned long V_109 , V_110 ;
unsigned int V_416 ;
int V_59 , V_180 , V_172 , V_5 = 0 ;
if ( ! F_92 ( V_46 , V_44 >> V_12 , & V_5 ) )
F_118 () ;
if ( V_92 < V_104 << F_6 ( V_5 ) )
V_92 = V_104 << F_6 ( V_5 ) ;
V_109 = V_44 >> V_12 ;
V_110 = ( V_44 + V_92 - 1 ) >> V_12 ;
V_116 = F_103 ( V_46 , V_109 , V_110 ) ;
V_416 = V_110 - V_109 + 1 ;
F_65 (iommu_id, dmar_domain->iommu_bmp, g_num_of_iommus) {
V_54 = V_62 [ V_59 ] ;
V_172 = F_149 ( V_54 -> V_57 ) ;
F_65 (num, iommu->domain_ids, ndomains) {
if ( V_54 -> V_165 [ V_180 ] == V_46 )
F_139 ( V_54 , V_180 , V_109 ,
V_416 , ! V_116 , 0 ) ;
}
}
F_104 ( V_116 ) ;
if ( V_46 -> V_401 == V_44 + V_92 )
V_46 -> V_401 = V_44 ;
return V_92 ;
}
static T_8 F_372 ( struct V_402 * V_47 ,
V_233 V_44 )
{
struct V_46 * V_46 = V_47 -> V_403 ;
struct V_27 * V_28 ;
int V_5 = 0 ;
V_25 V_417 = 0 ;
V_28 = F_92 ( V_46 , V_44 >> V_12 , & V_5 ) ;
if ( V_28 )
V_417 = F_32 ( V_28 ) ;
return V_417 ;
}
static bool F_373 ( enum V_418 V_57 )
{
if ( V_57 == V_419 )
return F_70 ( NULL ) == 1 ;
if ( V_57 == V_420 )
return V_421 == 1 ;
return false ;
}
static int F_374 ( struct V_74 * V_75 )
{
struct V_53 * V_54 ;
struct V_422 * V_423 ;
T_2 V_76 , V_77 ;
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return - V_191 ;
F_375 ( V_54 -> V_394 , V_75 ) ;
V_423 = F_376 ( V_75 ) ;
if ( F_377 ( V_423 ) )
return F_378 ( V_423 ) ;
F_379 ( V_423 ) ;
return 0 ;
}
static void F_380 ( struct V_74 * V_75 )
{
struct V_53 * V_54 ;
T_2 V_76 , V_77 ;
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return;
F_381 ( V_75 ) ;
F_382 ( V_54 -> V_394 , V_75 ) ;
}
static void F_383 ( struct V_79 * V_75 )
{
F_39 ( V_33 L_85 ) ;
V_34 = 0 ;
}
static void F_384 ( struct V_79 * V_75 )
{
F_39 ( V_33 L_86 ) ;
V_132 = 1 ;
}
static void F_385 ( struct V_79 * V_75 )
{
unsigned short V_424 ;
if ( F_386 ( V_75 , V_425 , & V_424 ) )
return;
if ( ! ( V_424 & V_426 ) ) {
F_39 ( V_33 L_87 ) ;
V_34 = 0 ;
} else if ( V_34 ) {
F_39 ( V_33 L_88 ) ;
V_36 = 1 ;
}
}
static void T_1 F_264 ( void )
{
struct V_79 * V_81 ;
T_11 V_427 ;
V_81 = F_387 ( V_428 , 0x3a3e , NULL ) ;
if ( ! V_81 )
return;
F_229 ( V_81 ) ;
V_81 = F_387 ( V_428 , 0x342e , NULL ) ;
if ( ! V_81 )
return;
if ( F_388 ( V_81 , 0x188 , & V_427 ) ) {
F_229 ( V_81 ) ;
return;
}
F_229 ( V_81 ) ;
if ( V_427 & 1 )
return;
V_427 &= 0x1c ;
if ( V_427 == 0x10 )
return;
if ( ! V_427 ) {
F_224 ( 1 , L_89
L_30 ,
F_225 ( V_248 ) ,
F_225 ( V_249 ) ,
F_225 ( V_250 ) ) ;
V_261 |= V_267 ;
return;
}
F_39 ( V_429 L_90 ,
V_427 ) ;
}
