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
return ( V_28 -> V_19 & ( 1 << 7 ) ) ;
}
static inline int F_37 ( struct V_27 * V_28 )
{
return ! ( ( unsigned long ) V_28 & ~ V_21 ) ;
}
static int T_1 F_38 ( char * V_29 )
{
if ( ! V_29 )
return - V_30 ;
while ( * V_29 ) {
if ( ! strncmp ( V_29 , L_1 , 2 ) ) {
V_31 = 0 ;
F_39 ( V_32 L_2 ) ;
} else if ( ! strncmp ( V_29 , L_3 , 3 ) ) {
V_31 = 1 ;
F_39 ( V_32 L_4 ) ;
} else if ( ! strncmp ( V_29 , L_5 , 8 ) ) {
V_33 = 0 ;
F_39 ( V_32
L_6 ) ;
} else if ( ! strncmp ( V_29 , L_7 , 8 ) ) {
F_39 ( V_32
L_8 ) ;
V_34 = 1 ;
} else if ( ! strncmp ( V_29 , L_9 , 6 ) ) {
F_39 ( V_32
L_10 ) ;
V_35 = 1 ;
} else if ( ! strncmp ( V_29 , L_11 , 6 ) ) {
F_39 ( V_32
L_12 ) ;
V_36 = 0 ;
}
V_29 += strcspn ( V_29 , L_13 ) ;
while ( * V_29 == ',' )
V_29 ++ ;
}
return 0 ;
}
static inline void * F_40 ( int V_37 )
{
struct V_14 * V_14 ;
void * V_38 = NULL ;
V_14 = F_41 ( V_37 , V_39 | V_40 , 0 ) ;
if ( V_14 )
V_38 = F_42 ( V_14 ) ;
return V_38 ;
}
static inline void F_43 ( void * V_38 )
{
F_44 ( ( unsigned long ) V_38 ) ;
}
static inline void * F_45 ( void )
{
return F_46 ( V_41 , V_39 ) ;
}
static void F_47 ( void * V_38 )
{
F_48 ( V_41 , V_38 ) ;
}
static inline void * F_49 ( void )
{
return F_46 ( V_42 , V_39 ) ;
}
static inline void F_50 ( void * V_38 )
{
F_48 ( V_42 , V_38 ) ;
}
struct V_43 * F_51 ( void )
{
return F_46 ( V_44 , V_39 ) ;
}
void F_52 ( struct V_43 * V_43 )
{
F_48 ( V_44 , V_43 ) ;
}
static int F_53 ( struct V_45 * V_46 , int V_47 )
{
unsigned long V_48 ;
int V_1 = - 1 ;
V_48 = F_54 ( V_46 -> V_49 ) ;
for ( V_1 = F_4 ( V_47 ) ;
V_1 >= 0 ; V_1 -- ) {
if ( F_55 ( V_1 , & V_48 ) )
break;
}
return V_1 ;
}
int F_56 ( struct V_45 * V_46 )
{
return F_53 ( V_46 , V_3 ) ;
}
int F_57 ( struct V_45 * V_46 )
{
return F_53 ( V_46 , V_50 ) ;
}
static struct V_45 * F_58 ( struct V_51 * V_52 )
{
int V_53 ;
F_59 ( V_52 -> V_54 & V_55 ) ;
F_59 ( V_52 -> V_54 & V_56 ) ;
V_53 = F_60 ( V_52 -> V_57 , V_58 ) ;
if ( V_53 < 0 || V_53 >= V_58 )
return NULL ;
return V_59 [ V_53 ] ;
}
static void F_61 ( struct V_51 * V_52 )
{
struct V_60 * V_61 ;
struct V_45 * V_46 ;
int V_62 , V_63 = 0 ;
V_52 -> V_64 = 1 ;
F_62 (i, domain->iommu_bmp, g_num_of_iommus) {
V_63 = 1 ;
if ( ! F_63 ( V_59 [ V_62 ] -> V_65 ) ) {
V_52 -> V_64 = 0 ;
break;
}
}
if ( V_63 )
return;
F_64 () ;
F_65 (iommu, drhd) {
if ( ! F_63 ( V_46 -> V_65 ) ) {
V_52 -> V_64 = 0 ;
break;
}
}
F_66 () ;
}
static void F_67 ( struct V_51 * V_52 )
{
int V_62 ;
V_52 -> V_66 = 1 ;
F_62 (i, domain->iommu_bmp, g_num_of_iommus) {
if ( ! F_68 ( V_59 [ V_62 ] -> V_65 ) ) {
V_52 -> V_66 = 0 ;
break;
}
}
}
static void F_69 ( struct V_51 * V_52 )
{
struct V_60 * V_61 ;
struct V_45 * V_46 = NULL ;
int V_67 = 0xf ;
if ( ! V_36 ) {
V_52 -> V_68 = 0 ;
return;
}
F_64 () ;
F_65 (iommu, drhd) {
V_67 &= F_70 ( V_46 -> V_49 ) ;
if ( ! V_67 ) {
break;
}
}
F_66 () ;
V_52 -> V_68 = F_71 ( V_67 ) ;
}
static void F_72 ( struct V_51 * V_52 )
{
F_61 ( V_52 ) ;
F_67 ( V_52 ) ;
F_69 ( V_52 ) ;
}
static struct V_45 * F_73 ( struct V_69 * V_70 , T_2 * V_71 , T_2 * V_72 )
{
struct V_60 * V_61 = NULL ;
struct V_45 * V_46 ;
struct V_69 * V_73 ;
struct V_74 * V_75 , * V_76 = NULL ;
T_3 V_77 ;
int V_62 ;
if ( F_74 ( V_70 ) ) {
V_76 = F_75 ( V_70 ) ;
V_77 = F_76 ( V_76 -> V_71 ) ;
} else if ( F_77 ( V_70 ) )
V_70 = & F_77 ( V_70 ) -> V_70 ;
F_64 () ;
F_65 (iommu, drhd) {
if ( V_76 && V_77 != V_61 -> V_77 )
continue;
F_78 (drhd->devices,
drhd->devices_cnt, i, tmp) {
if ( V_73 == V_70 ) {
* V_71 = V_61 -> V_78 [ V_62 ] . V_71 ;
* V_72 = V_61 -> V_78 [ V_62 ] . V_72 ;
goto V_79;
}
if ( ! V_76 || ! F_74 ( V_73 ) )
continue;
V_75 = F_75 ( V_73 ) ;
if ( V_75 -> V_80 &&
V_75 -> V_80 -> V_81 <= V_76 -> V_71 -> V_81 &&
V_75 -> V_80 -> V_82 . V_83 >= V_76 -> V_71 -> V_81 )
goto V_84;
}
if ( V_76 && V_61 -> V_85 ) {
V_84:
* V_71 = V_76 -> V_71 -> V_81 ;
* V_72 = V_76 -> V_72 ;
goto V_79;
}
}
V_46 = NULL ;
V_79:
F_66 () ;
return V_46 ;
}
static void F_79 ( struct V_51 * V_52 ,
void * V_86 , int V_87 )
{
if ( ! V_52 -> V_64 )
F_80 ( V_86 , V_87 ) ;
}
static struct V_22 * F_81 ( struct V_45 * V_46 ,
T_2 V_71 , T_2 V_72 )
{
struct V_17 * V_18 ;
struct V_22 * V_23 ;
unsigned long V_88 ;
unsigned long V_54 ;
F_82 ( & V_46 -> V_89 , V_54 ) ;
V_18 = & V_46 -> V_17 [ V_71 ] ;
V_23 = F_21 ( V_18 ) ;
if ( ! V_23 ) {
V_23 = (struct V_22 * )
F_40 ( V_46 -> V_37 ) ;
if ( ! V_23 ) {
F_83 ( & V_46 -> V_89 , V_54 ) ;
return NULL ;
}
F_84 ( V_46 , ( void * ) V_23 , V_90 ) ;
V_88 = F_85 ( ( void * ) V_23 ) ;
F_20 ( V_18 , V_88 ) ;
F_19 ( V_18 ) ;
F_84 ( V_46 , V_18 , sizeof( * V_18 ) ) ;
}
F_83 ( & V_46 -> V_89 , V_54 ) ;
return & V_23 [ V_72 ] ;
}
static int F_86 ( struct V_45 * V_46 , T_2 V_71 , T_2 V_72 )
{
struct V_17 * V_18 ;
struct V_22 * V_23 ;
int V_91 ;
unsigned long V_54 ;
F_82 ( & V_46 -> V_89 , V_54 ) ;
V_18 = & V_46 -> V_17 [ V_71 ] ;
V_23 = F_21 ( V_18 ) ;
if ( ! V_23 ) {
V_91 = 0 ;
goto V_79;
}
V_91 = F_23 ( & V_23 [ V_72 ] ) ;
V_79:
F_83 ( & V_46 -> V_89 , V_54 ) ;
return V_91 ;
}
static void F_87 ( struct V_45 * V_46 , T_2 V_71 , T_2 V_72 )
{
struct V_17 * V_18 ;
struct V_22 * V_23 ;
unsigned long V_54 ;
F_82 ( & V_46 -> V_89 , V_54 ) ;
V_18 = & V_46 -> V_17 [ V_71 ] ;
V_23 = F_21 ( V_18 ) ;
if ( V_23 ) {
F_30 ( & V_23 [ V_72 ] ) ;
F_84 ( V_46 , & V_23 [ V_72 ] , \
sizeof( * V_23 ) ) ;
}
F_83 ( & V_46 -> V_89 , V_54 ) ;
}
static void F_88 ( struct V_45 * V_46 )
{
struct V_17 * V_18 ;
int V_62 ;
unsigned long V_54 ;
struct V_22 * V_23 ;
F_82 ( & V_46 -> V_89 , V_54 ) ;
if ( ! V_46 -> V_17 ) {
goto V_79;
}
for ( V_62 = 0 ; V_62 < V_92 ; V_62 ++ ) {
V_18 = & V_46 -> V_17 [ V_62 ] ;
V_23 = F_21 ( V_18 ) ;
if ( V_23 )
F_43 ( V_23 ) ;
}
F_43 ( V_46 -> V_17 ) ;
V_46 -> V_17 = NULL ;
V_79:
F_83 ( & V_46 -> V_89 , V_54 ) ;
}
static struct V_27 * F_89 ( struct V_51 * V_52 ,
unsigned long V_6 , int * V_93 )
{
int V_94 = F_2 ( V_52 -> V_1 ) - V_12 ;
struct V_27 * V_95 , * V_28 = NULL ;
int V_5 = F_1 ( V_52 -> V_1 ) ;
int V_96 ;
F_59 ( ! V_52 -> V_97 ) ;
if ( V_94 < V_98 && V_6 > > V_94 )
return NULL ;
V_95 = V_52 -> V_97 ;
while ( 1 ) {
void * V_99 ;
V_96 = F_7 ( V_6 , V_5 ) ;
V_28 = & V_95 [ V_96 ] ;
if ( ! * V_93 && ( F_36 ( V_28 ) || ! F_35 ( V_28 ) ) )
break;
if ( V_5 == * V_93 )
break;
if ( ! F_35 ( V_28 ) ) {
T_4 V_100 ;
V_99 = F_40 ( V_52 -> V_101 ) ;
if ( ! V_99 )
return NULL ;
F_79 ( V_52 , V_99 , V_102 ) ;
V_100 = ( ( T_4 ) F_16 ( V_99 ) << V_12 ) | V_103 | V_104 ;
if ( F_90 ( & V_28 -> V_19 , 0ULL , V_100 ) ) {
F_43 ( V_99 ) ;
} else {
F_32 ( V_28 ) ;
F_79 ( V_52 , V_28 , sizeof( * V_28 ) ) ;
}
}
if ( V_5 == 1 )
break;
V_95 = F_22 ( F_32 ( V_28 ) ) ;
V_5 -- ;
}
if ( ! * V_93 )
* V_93 = V_5 ;
return V_28 ;
}
static struct V_27 * F_91 ( struct V_51 * V_52 ,
unsigned long V_6 ,
int V_5 , int * V_105 )
{
struct V_27 * V_95 , * V_28 = NULL ;
int V_106 = F_1 ( V_52 -> V_1 ) ;
int V_96 ;
V_95 = V_52 -> V_97 ;
while ( V_5 <= V_106 ) {
V_96 = F_7 ( V_6 , V_106 ) ;
V_28 = & V_95 [ V_96 ] ;
if ( V_5 == V_106 )
return V_28 ;
if ( ! F_35 ( V_28 ) ) {
* V_105 = V_106 ;
break;
}
if ( V_28 -> V_19 & V_107 ) {
* V_105 = V_106 ;
return V_28 ;
}
V_95 = F_22 ( F_32 ( V_28 ) ) ;
V_106 -- ;
}
return NULL ;
}
static void F_92 ( struct V_51 * V_52 ,
unsigned long V_108 ,
unsigned long V_109 )
{
int V_94 = F_2 ( V_52 -> V_1 ) - V_12 ;
unsigned int V_105 = 1 ;
struct V_27 * V_110 , * V_28 ;
F_59 ( V_94 < V_98 && V_108 > > V_94 ) ;
F_59 ( V_94 < V_98 && V_109 > > V_94 ) ;
F_59 ( V_108 > V_109 ) ;
do {
V_105 = 1 ;
V_110 = V_28 = F_91 ( V_52 , V_108 , 1 , & V_105 ) ;
if ( ! V_28 ) {
V_108 = F_10 ( V_108 + 1 , V_105 + 1 ) ;
continue;
}
do {
F_31 ( V_28 ) ;
V_108 += F_11 ( V_105 ) ;
V_28 ++ ;
} while ( V_108 <= V_109 && ! F_37 ( V_28 ) );
F_79 ( V_52 , V_110 ,
( void * ) V_28 - ( void * ) V_110 ) ;
} while ( V_108 && V_108 <= V_109 );
}
static void F_93 ( struct V_51 * V_52 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_108 , unsigned long V_109 )
{
V_6 = F_94 ( V_108 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_111 ;
struct V_27 * V_112 ;
if ( ! F_35 ( V_28 ) || F_36 ( V_28 ) )
goto V_113;
V_111 = V_6 & F_8 ( V_5 - 1 ) ;
V_112 = F_22 ( F_32 ( V_28 ) ) ;
if ( V_5 > 2 )
F_93 ( V_52 , V_5 - 1 , V_112 ,
V_111 , V_108 , V_109 ) ;
if ( ! ( V_108 > V_111 ||
V_109 < V_111 + F_9 ( V_5 ) - 1 ) ) {
F_31 ( V_28 ) ;
F_79 ( V_52 , V_28 , sizeof( * V_28 ) ) ;
F_43 ( V_112 ) ;
}
V_113:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_37 ( ++ V_28 ) && V_6 <= V_109 );
}
static void F_95 ( struct V_51 * V_52 ,
unsigned long V_108 ,
unsigned long V_109 )
{
int V_94 = F_2 ( V_52 -> V_1 ) - V_12 ;
F_59 ( V_94 < V_98 && V_108 > > V_94 ) ;
F_59 ( V_94 < V_98 && V_109 > > V_94 ) ;
F_59 ( V_108 > V_109 ) ;
F_93 ( V_52 , F_1 ( V_52 -> V_1 ) ,
V_52 -> V_97 , 0 , V_108 , V_109 ) ;
if ( V_108 == 0 && V_109 == F_96 ( V_52 -> V_114 ) ) {
F_43 ( V_52 -> V_97 ) ;
V_52 -> V_97 = NULL ;
}
}
static struct V_14 * F_97 ( struct V_51 * V_52 ,
int V_5 , struct V_27 * V_28 ,
struct V_14 * V_115 )
{
struct V_14 * V_15 ;
V_15 = F_98 ( F_32 ( V_28 ) >> V_11 ) ;
V_15 -> V_115 = V_115 ;
V_115 = V_15 ;
if ( V_5 == 1 )
return V_115 ;
V_28 = F_42 ( V_15 ) ;
do {
if ( F_35 ( V_28 ) && ! F_36 ( V_28 ) )
V_115 = F_97 ( V_52 , V_5 - 1 ,
V_28 , V_115 ) ;
V_28 ++ ;
} while ( ! F_37 ( V_28 ) );
return V_115 ;
}
static struct V_14 * F_99 ( struct V_51 * V_52 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_108 ,
unsigned long V_109 ,
struct V_14 * V_115 )
{
struct V_27 * V_110 = NULL , * V_116 = NULL ;
V_6 = F_94 ( V_108 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_111 ;
if ( ! F_35 ( V_28 ) )
goto V_113;
V_111 = V_6 & F_8 ( V_5 ) ;
if ( V_108 <= V_111 &&
V_109 >= V_111 + F_9 ( V_5 ) - 1 ) {
if ( V_5 > 1 && ! F_36 ( V_28 ) )
V_115 = F_97 ( V_52 , V_5 - 1 , V_28 , V_115 ) ;
F_31 ( V_28 ) ;
if ( ! V_110 )
V_110 = V_28 ;
V_116 = V_28 ;
} else if ( V_5 > 1 ) {
V_115 = F_99 ( V_52 , V_5 - 1 ,
F_22 ( F_32 ( V_28 ) ) ,
V_111 , V_108 , V_109 ,
V_115 ) ;
}
V_113:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_37 ( ++ V_28 ) && V_6 <= V_109 );
if ( V_110 )
F_79 ( V_52 , V_110 ,
( void * ) ++ V_116 - ( void * ) V_110 ) ;
return V_115 ;
}
struct V_14 * F_100 ( struct V_51 * V_52 ,
unsigned long V_108 ,
unsigned long V_109 )
{
int V_94 = F_2 ( V_52 -> V_1 ) - V_12 ;
struct V_14 * V_115 = NULL ;
F_59 ( V_94 < V_98 && V_108 > > V_94 ) ;
F_59 ( V_94 < V_98 && V_109 > > V_94 ) ;
F_59 ( V_108 > V_109 ) ;
V_115 = F_99 ( V_52 , F_1 ( V_52 -> V_1 ) ,
V_52 -> V_97 , 0 , V_108 , V_109 , NULL ) ;
if ( V_108 == 0 && V_109 == F_96 ( V_52 -> V_114 ) ) {
struct V_14 * V_117 = F_17 ( V_52 -> V_97 ) ;
V_117 -> V_115 = V_115 ;
V_115 = V_117 ;
V_52 -> V_97 = NULL ;
}
return V_115 ;
}
void F_101 ( struct V_14 * V_115 )
{
struct V_14 * V_15 ;
while ( ( V_15 = V_115 ) ) {
V_115 = V_15 -> V_115 ;
F_43 ( F_42 ( V_15 ) ) ;
}
}
static int F_102 ( struct V_45 * V_46 )
{
struct V_17 * V_18 ;
unsigned long V_54 ;
V_18 = (struct V_17 * ) F_40 ( V_46 -> V_37 ) ;
if ( ! V_18 )
return - V_118 ;
F_84 ( V_46 , V_18 , V_119 ) ;
F_82 ( & V_46 -> V_89 , V_54 ) ;
V_46 -> V_17 = V_18 ;
F_83 ( & V_46 -> V_89 , V_54 ) ;
return 0 ;
}
static void F_103 ( struct V_45 * V_46 )
{
void * V_86 ;
T_5 V_120 ;
unsigned long V_121 ;
V_86 = V_46 -> V_17 ;
F_104 ( & V_46 -> V_122 , V_121 ) ;
F_105 ( V_46 -> V_123 + V_124 , F_85 ( V_86 ) ) ;
F_106 ( V_46 -> V_125 | V_126 , V_46 -> V_123 + V_127 ) ;
F_107 ( V_46 , V_128 ,
V_129 , ( V_120 & V_130 ) , V_120 ) ;
F_108 ( & V_46 -> V_122 , V_121 ) ;
}
static void F_109 ( struct V_45 * V_46 )
{
T_5 V_19 ;
unsigned long V_121 ;
if ( ! V_131 && ! F_110 ( V_46 -> V_49 ) )
return;
F_104 ( & V_46 -> V_122 , V_121 ) ;
F_106 ( V_46 -> V_125 | V_132 , V_46 -> V_123 + V_127 ) ;
F_107 ( V_46 , V_128 ,
V_129 , ( ! ( V_19 & V_133 ) ) , V_19 ) ;
F_108 ( & V_46 -> V_122 , V_121 ) ;
}
static void F_111 ( struct V_45 * V_46 ,
T_3 V_134 , T_3 V_135 , T_2 V_136 ,
V_25 type )
{
V_25 V_19 = 0 ;
unsigned long V_121 ;
switch ( type ) {
case V_137 :
V_19 = V_137 ;
break;
case V_138 :
V_19 = V_138 | F_112 ( V_134 ) ;
break;
case V_139 :
V_19 = V_139 | F_112 ( V_134 )
| F_113 ( V_135 ) | F_114 ( V_136 ) ;
break;
default:
F_115 () ;
}
V_19 |= V_140 ;
F_104 ( & V_46 -> V_122 , V_121 ) ;
F_105 ( V_46 -> V_123 + V_141 , V_19 ) ;
F_107 ( V_46 , V_141 ,
V_142 , ( ! ( V_19 & V_140 ) ) , V_19 ) ;
F_108 ( & V_46 -> V_122 , V_121 ) ;
}
static void F_116 ( struct V_45 * V_46 , T_3 V_134 ,
V_25 V_86 , unsigned int V_143 , V_25 type )
{
int V_144 = F_117 ( V_46 -> V_65 ) ;
V_25 V_19 = 0 , V_145 = 0 ;
unsigned long V_121 ;
switch ( type ) {
case V_146 :
V_19 = V_146 | V_147 ;
break;
case V_148 :
V_19 = V_148 | V_147 | F_118 ( V_134 ) ;
break;
case V_149 :
V_19 = V_149 | V_147 | F_118 ( V_134 ) ;
V_145 = V_143 | V_86 ;
break;
default:
F_115 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_119 ( V_46 -> V_49 ) )
V_19 |= V_150 ;
F_104 ( & V_46 -> V_122 , V_121 ) ;
if ( V_145 )
F_105 ( V_46 -> V_123 + V_144 , V_145 ) ;
F_105 ( V_46 -> V_123 + V_144 + 8 , V_19 ) ;
F_107 ( V_46 , V_144 + 8 ,
V_142 , ( ! ( V_19 & V_147 ) ) , V_19 ) ;
F_108 ( & V_46 -> V_122 , V_121 ) ;
if ( F_120 ( V_19 ) == 0 )
F_39 ( V_151 L_14 ) ;
if ( F_120 ( V_19 ) != F_121 ( type ) )
F_122 ( L_15 ,
( unsigned long long ) F_121 ( type ) ,
( unsigned long long ) F_120 ( V_19 ) ) ;
}
static struct V_152 *
F_123 ( struct V_51 * V_52 , struct V_45 * V_46 ,
T_2 V_71 , T_2 V_72 )
{
int V_63 = 0 ;
unsigned long V_54 ;
struct V_152 * V_153 ;
struct V_74 * V_76 ;
if ( ! F_124 ( V_46 -> V_65 ) )
return NULL ;
if ( ! V_46 -> V_154 )
return NULL ;
F_82 ( & V_155 , V_54 ) ;
F_125 (info, &domain->devices, link)
if ( V_153 -> V_71 == V_71 && V_153 -> V_72 == V_72 ) {
V_63 = 1 ;
break;
}
F_83 ( & V_155 , V_54 ) ;
if ( ! V_63 || ! V_153 -> V_70 || ! F_74 ( V_153 -> V_70 ) )
return NULL ;
V_76 = F_75 ( V_153 -> V_70 ) ;
if ( ! F_126 ( V_76 , V_156 ) )
return NULL ;
if ( ! F_127 ( V_76 ) )
return NULL ;
return V_153 ;
}
static void F_128 ( struct V_152 * V_153 )
{
if ( ! V_153 || ! F_74 ( V_153 -> V_70 ) )
return;
F_129 ( F_75 ( V_153 -> V_70 ) , V_12 ) ;
}
static void F_130 ( struct V_152 * V_153 )
{
if ( ! V_153 -> V_70 || ! F_74 ( V_153 -> V_70 ) ||
! F_131 ( F_75 ( V_153 -> V_70 ) ) )
return;
F_132 ( F_75 ( V_153 -> V_70 ) ) ;
}
static void F_133 ( struct V_51 * V_52 ,
V_25 V_86 , unsigned V_67 )
{
T_3 V_157 , V_158 ;
unsigned long V_54 ;
struct V_152 * V_153 ;
F_82 ( & V_155 , V_54 ) ;
F_125 (info, &domain->devices, link) {
struct V_74 * V_76 ;
if ( ! V_153 -> V_70 || ! F_74 ( V_153 -> V_70 ) )
continue;
V_76 = F_75 ( V_153 -> V_70 ) ;
if ( ! F_131 ( V_76 ) )
continue;
V_157 = V_153 -> V_71 << 8 | V_153 -> V_72 ;
V_158 = F_134 ( V_76 ) ;
F_135 ( V_153 -> V_46 , V_157 , V_158 , V_86 , V_67 ) ;
}
F_83 ( & V_155 , V_54 ) ;
}
static void F_136 ( struct V_45 * V_46 , T_3 V_134 ,
unsigned long V_6 , unsigned int V_159 , int V_160 , int V_161 )
{
unsigned int V_67 = F_137 ( F_138 ( V_159 ) ) ;
T_4 V_86 = ( T_4 ) V_6 << V_12 ;
F_59 ( V_159 == 0 ) ;
if ( V_160 )
V_160 = 1 << 6 ;
if ( ! F_139 ( V_46 -> V_49 ) || V_67 > F_140 ( V_46 -> V_49 ) )
V_46 -> V_162 . V_163 ( V_46 , V_134 , 0 , 0 ,
V_148 ) ;
else
V_46 -> V_162 . V_163 ( V_46 , V_134 , V_86 | V_160 , V_67 ,
V_149 ) ;
if ( ! F_141 ( V_46 -> V_49 ) || ! V_161 )
F_133 ( V_46 -> V_164 [ V_134 ] , V_86 , V_67 ) ;
}
static void F_142 ( struct V_45 * V_46 )
{
T_5 V_165 ;
unsigned long V_54 ;
F_104 ( & V_46 -> V_122 , V_54 ) ;
V_165 = V_129 ( V_46 -> V_123 + V_166 ) ;
V_165 &= ~ V_167 ;
F_106 ( V_165 , V_46 -> V_123 + V_166 ) ;
F_107 ( V_46 , V_166 ,
V_129 , ! ( V_165 & V_168 ) , V_165 ) ;
F_108 ( & V_46 -> V_122 , V_54 ) ;
}
static int F_143 ( struct V_45 * V_46 )
{
T_5 V_120 ;
unsigned long V_54 ;
F_104 ( & V_46 -> V_122 , V_54 ) ;
V_46 -> V_125 |= V_169 ;
F_106 ( V_46 -> V_125 , V_46 -> V_123 + V_127 ) ;
F_107 ( V_46 , V_128 ,
V_129 , ( V_120 & V_170 ) , V_120 ) ;
F_108 ( & V_46 -> V_122 , V_54 ) ;
return 0 ;
}
static int F_144 ( struct V_45 * V_46 )
{
T_5 V_120 ;
unsigned long V_121 ;
F_104 ( & V_46 -> V_122 , V_121 ) ;
V_46 -> V_125 &= ~ V_169 ;
F_106 ( V_46 -> V_125 , V_46 -> V_123 + V_127 ) ;
F_107 ( V_46 , V_128 ,
V_129 , ( ! ( V_120 & V_170 ) ) , V_120 ) ;
F_108 ( & V_46 -> V_122 , V_121 ) ;
return 0 ;
}
static int F_145 ( struct V_45 * V_46 )
{
unsigned long V_171 ;
unsigned long V_172 ;
V_171 = F_146 ( V_46 -> V_49 ) ;
F_122 ( L_16 ,
V_46 -> V_173 , V_171 ) ;
V_172 = F_147 ( V_171 ) ;
F_148 ( & V_46 -> V_89 ) ;
V_46 -> V_174 = F_149 ( V_172 , sizeof( unsigned long ) , V_175 ) ;
if ( ! V_46 -> V_174 ) {
F_150 ( L_17 ,
V_46 -> V_173 ) ;
return - V_118 ;
}
V_46 -> V_164 = F_149 ( V_171 , sizeof( struct V_51 * ) ,
V_175 ) ;
if ( ! V_46 -> V_164 ) {
F_150 ( L_18 ,
V_46 -> V_173 ) ;
F_151 ( V_46 -> V_174 ) ;
V_46 -> V_174 = NULL ;
return - V_118 ;
}
if ( F_141 ( V_46 -> V_49 ) )
F_152 ( 0 , V_46 -> V_174 ) ;
return 0 ;
}
static void F_153 ( struct V_45 * V_46 )
{
struct V_51 * V_52 ;
int V_62 , V_176 ;
unsigned long V_54 ;
if ( ( V_46 -> V_164 ) && ( V_46 -> V_174 ) ) {
F_62 (i, iommu->domain_ids, cap_ndoms(iommu->cap)) {
if ( F_141 ( V_46 -> V_49 ) && V_62 == 0 )
continue;
V_52 = V_46 -> V_164 [ V_62 ] ;
F_154 ( V_62 , V_46 -> V_174 ) ;
F_82 ( & V_52 -> V_177 , V_54 ) ;
V_176 = -- V_52 -> V_178 ;
F_83 ( & V_52 -> V_177 , V_54 ) ;
if ( V_176 == 0 )
F_155 ( V_52 ) ;
}
}
if ( V_46 -> V_125 & V_169 )
F_144 ( V_46 ) ;
F_151 ( V_46 -> V_164 ) ;
F_151 ( V_46 -> V_174 ) ;
V_46 -> V_164 = NULL ;
V_46 -> V_174 = NULL ;
V_59 [ V_46 -> V_173 ] = NULL ;
F_88 ( V_46 ) ;
}
static struct V_51 * F_156 ( bool V_179 )
{
static T_6 V_180 = F_157 ( 0 ) ;
struct V_51 * V_52 ;
V_52 = F_45 () ;
if ( ! V_52 )
return NULL ;
V_52 -> V_101 = - 1 ;
V_52 -> V_178 = 0 ;
memset ( V_52 -> V_57 , 0 , sizeof( V_52 -> V_57 ) ) ;
V_52 -> V_54 = 0 ;
F_148 ( & V_52 -> V_177 ) ;
F_158 ( & V_52 -> V_78 ) ;
if ( V_179 ) {
V_52 -> V_181 = F_159 ( & V_180 ) ;
V_52 -> V_54 = V_55 ;
}
return V_52 ;
}
static int F_160 ( struct V_51 * V_52 ,
struct V_45 * V_46 )
{
int V_182 ;
unsigned long V_171 ;
unsigned long V_54 ;
V_171 = F_146 ( V_46 -> V_49 ) ;
F_82 ( & V_46 -> V_89 , V_54 ) ;
V_182 = F_161 ( V_46 -> V_174 , V_171 ) ;
if ( V_182 >= V_171 ) {
F_83 ( & V_46 -> V_89 , V_54 ) ;
F_39 ( V_151 L_19 ) ;
return - V_118 ;
}
V_52 -> V_181 = V_182 ;
V_52 -> V_178 ++ ;
F_152 ( V_182 , V_46 -> V_174 ) ;
F_152 ( V_46 -> V_173 , V_52 -> V_57 ) ;
V_46 -> V_164 [ V_182 ] = V_52 ;
F_83 ( & V_46 -> V_89 , V_54 ) ;
return 0 ;
}
static void F_162 ( struct V_51 * V_52 ,
struct V_45 * V_46 )
{
unsigned long V_54 ;
int V_182 , V_171 ;
F_82 ( & V_46 -> V_89 , V_54 ) ;
V_171 = F_146 ( V_46 -> V_49 ) ;
F_62 (num, iommu->domain_ids, ndomains) {
if ( V_46 -> V_164 [ V_182 ] == V_52 ) {
F_154 ( V_182 , V_46 -> V_174 ) ;
V_46 -> V_164 [ V_182 ] = NULL ;
break;
}
}
F_83 ( & V_46 -> V_89 , V_54 ) ;
}
static int F_163 ( void )
{
struct V_74 * V_76 = NULL ;
struct V_43 * V_43 ;
int V_62 ;
F_164 ( & V_183 , V_184 ) ;
F_165 ( & V_183 . V_185 ,
& V_186 ) ;
V_43 = F_166 ( & V_183 , F_167 ( V_187 ) ,
F_167 ( V_188 ) ) ;
if ( ! V_43 ) {
F_39 ( V_151 L_20 ) ;
return - V_189 ;
}
F_168 (pdev) {
struct V_190 * V_191 ;
for ( V_62 = 0 ; V_62 < V_192 ; V_62 ++ ) {
V_191 = & V_76 -> V_190 [ V_62 ] ;
if ( ! V_191 -> V_54 || ! ( V_191 -> V_54 & V_193 ) )
continue;
V_43 = F_166 ( & V_183 ,
F_167 ( V_191 -> V_194 ) ,
F_167 ( V_191 -> V_83 ) ) ;
if ( ! V_43 ) {
F_39 ( V_151 L_21 ) ;
return - V_189 ;
}
}
}
return 0 ;
}
static void F_169 ( struct V_51 * V_52 )
{
F_170 ( & V_183 , & V_52 -> V_195 ) ;
}
static inline int F_171 ( int V_114 )
{
int V_1 ;
int V_191 = ( V_114 - 12 ) % 9 ;
if ( V_191 == 0 )
V_1 = V_114 ;
else
V_1 = V_114 + 9 - V_191 ;
if ( V_1 > 64 )
V_1 = 64 ;
return V_1 ;
}
static int F_172 ( struct V_51 * V_52 , int V_196 )
{
struct V_45 * V_46 ;
int V_197 , V_1 ;
unsigned long V_48 ;
F_164 ( & V_52 -> V_195 , V_184 ) ;
F_169 ( V_52 ) ;
V_46 = F_58 ( V_52 ) ;
if ( V_196 > F_173 ( V_46 -> V_49 ) )
V_196 = F_173 ( V_46 -> V_49 ) ;
V_52 -> V_114 = V_196 ;
V_197 = F_171 ( V_196 ) ;
V_1 = F_4 ( V_197 ) ;
V_48 = F_54 ( V_46 -> V_49 ) ;
if ( ! F_55 ( V_1 , & V_48 ) ) {
F_122 ( L_22 , V_1 ) ;
V_1 = F_174 ( & V_48 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_189 ;
}
V_52 -> V_1 = V_1 ;
if ( F_63 ( V_46 -> V_65 ) )
V_52 -> V_64 = 1 ;
else
V_52 -> V_64 = 0 ;
if ( F_68 ( V_46 -> V_65 ) )
V_52 -> V_66 = 1 ;
else
V_52 -> V_66 = 0 ;
if ( V_36 )
V_52 -> V_68 = F_71 ( F_70 ( V_46 -> V_49 ) ) ;
else
V_52 -> V_68 = 0 ;
V_52 -> V_101 = V_46 -> V_37 ;
V_52 -> V_97 = (struct V_27 * ) F_40 ( V_52 -> V_101 ) ;
if ( ! V_52 -> V_97 )
return - V_118 ;
F_84 ( V_46 , V_52 -> V_97 , V_198 ) ;
return 0 ;
}
static void F_155 ( struct V_51 * V_52 )
{
struct V_60 * V_61 ;
struct V_45 * V_46 ;
struct V_14 * V_115 = NULL ;
if ( ! V_52 )
return;
if ( ! V_35 )
F_175 ( 0 ) ;
F_176 ( V_52 ) ;
F_177 ( & V_52 -> V_195 ) ;
V_115 = F_100 ( V_52 , 0 , F_96 ( V_52 -> V_114 ) ) ;
F_64 () ;
F_65 (iommu, drhd)
if ( V_52 -> V_54 & V_55 ||
F_55 ( V_46 -> V_173 , V_52 -> V_57 ) )
F_162 ( V_52 , V_46 ) ;
F_66 () ;
F_101 ( V_115 ) ;
F_47 ( V_52 ) ;
}
static int F_178 ( struct V_51 * V_52 ,
struct V_45 * V_46 ,
T_2 V_71 , T_2 V_72 , int V_199 )
{
struct V_22 * V_23 ;
unsigned long V_54 ;
struct V_27 * V_97 ;
unsigned long V_182 ;
unsigned long V_171 ;
int V_181 ;
int V_1 ;
struct V_152 * V_153 = NULL ;
F_122 ( L_23 ,
V_71 , F_179 ( V_72 ) , F_180 ( V_72 ) ) ;
F_59 ( ! V_52 -> V_97 ) ;
F_59 ( V_199 != V_200 &&
V_199 != V_201 ) ;
V_23 = F_81 ( V_46 , V_71 , V_72 ) ;
if ( ! V_23 )
return - V_118 ;
F_82 ( & V_46 -> V_89 , V_54 ) ;
if ( F_23 ( V_23 ) ) {
F_83 ( & V_46 -> V_89 , V_54 ) ;
return 0 ;
}
V_181 = V_52 -> V_181 ;
V_97 = V_52 -> V_97 ;
if ( V_52 -> V_54 & V_55 ||
V_52 -> V_54 & V_56 ) {
int V_63 = 0 ;
V_171 = F_146 ( V_46 -> V_49 ) ;
F_62 (num, iommu->domain_ids, ndomains) {
if ( V_46 -> V_164 [ V_182 ] == V_52 ) {
V_181 = V_182 ;
V_63 = 1 ;
break;
}
}
if ( V_63 == 0 ) {
V_182 = F_161 ( V_46 -> V_174 , V_171 ) ;
if ( V_182 >= V_171 ) {
F_83 ( & V_46 -> V_89 , V_54 ) ;
F_39 ( V_151 L_19 ) ;
return - V_202 ;
}
F_152 ( V_182 , V_46 -> V_174 ) ;
V_46 -> V_164 [ V_182 ] = V_52 ;
V_181 = V_182 ;
}
if ( V_199 != V_200 ) {
for ( V_1 = V_52 -> V_1 ; V_1 != V_46 -> V_1 ; V_1 -- ) {
V_97 = F_22 ( F_32 ( V_97 ) ) ;
if ( ! F_35 ( V_97 ) ) {
F_83 ( & V_46 -> V_89 , V_54 ) ;
return - V_118 ;
}
}
}
}
F_29 ( V_23 , V_181 ) ;
if ( V_199 != V_200 ) {
V_153 = F_123 ( V_52 , V_46 , V_71 , V_72 ) ;
V_199 = V_153 ? V_203 :
V_201 ;
}
if ( F_181 ( V_199 == V_200 ) )
F_28 ( V_23 , V_46 -> V_204 ) ;
else {
F_27 ( V_23 , F_85 ( V_97 ) ) ;
F_28 ( V_23 , V_46 -> V_1 ) ;
}
F_26 ( V_23 , V_199 ) ;
F_25 ( V_23 ) ;
F_24 ( V_23 ) ;
F_79 ( V_52 , V_23 , sizeof( * V_23 ) ) ;
if ( F_141 ( V_46 -> V_49 ) ) {
V_46 -> V_162 . V_205 ( V_46 , 0 ,
( ( ( T_3 ) V_71 ) << 8 ) | V_72 ,
V_206 ,
V_139 ) ;
V_46 -> V_162 . V_163 ( V_46 , V_52 -> V_181 , 0 , 0 , V_148 ) ;
} else {
F_109 ( V_46 ) ;
}
F_128 ( V_153 ) ;
F_83 ( & V_46 -> V_89 , V_54 ) ;
F_82 ( & V_52 -> V_177 , V_54 ) ;
if ( ! F_182 ( V_46 -> V_173 , V_52 -> V_57 ) ) {
V_52 -> V_178 ++ ;
if ( V_52 -> V_178 == 1 )
V_52 -> V_101 = V_46 -> V_37 ;
F_72 ( V_52 ) ;
}
F_83 ( & V_52 -> V_177 , V_54 ) ;
return 0 ;
}
static int
F_183 ( struct V_51 * V_52 , struct V_69 * V_70 ,
int V_199 )
{
int V_91 ;
struct V_74 * V_76 , * V_73 , * V_95 ;
struct V_45 * V_46 ;
T_2 V_71 , V_72 ;
V_46 = F_73 ( V_70 , & V_71 , & V_72 ) ;
if ( ! V_46 )
return - V_189 ;
V_91 = F_178 ( V_52 , V_46 , V_71 , V_72 ,
V_199 ) ;
if ( V_91 || ! F_74 ( V_70 ) )
return V_91 ;
V_76 = F_75 ( V_70 ) ;
V_73 = F_184 ( V_76 ) ;
if ( ! V_73 )
return 0 ;
V_95 = V_76 -> V_71 -> V_207 ;
while ( V_95 != V_73 ) {
V_91 = F_178 ( V_52 , V_46 ,
V_95 -> V_71 -> V_81 ,
V_95 -> V_72 , V_199 ) ;
if ( V_91 )
return V_91 ;
V_95 = V_95 -> V_71 -> V_207 ;
}
if ( F_185 ( V_73 ) )
return F_178 ( V_52 , V_46 ,
V_73 -> V_80 -> V_81 , 0 ,
V_199 ) ;
else
return F_178 ( V_52 , V_46 ,
V_73 -> V_71 -> V_81 ,
V_73 -> V_72 ,
V_199 ) ;
}
static int F_186 ( struct V_69 * V_70 )
{
int V_91 ;
struct V_74 * V_76 , * V_73 , * V_95 ;
struct V_45 * V_46 ;
T_2 V_71 , V_72 ;
V_46 = F_73 ( V_70 , & V_71 , & V_72 ) ;
if ( ! V_46 )
return - V_189 ;
V_91 = F_86 ( V_46 , V_71 , V_72 ) ;
if ( ! V_91 || ! F_74 ( V_70 ) )
return V_91 ;
V_76 = F_75 ( V_70 ) ;
V_73 = F_184 ( V_76 ) ;
if ( ! V_73 )
return V_91 ;
V_95 = V_76 -> V_71 -> V_207 ;
while ( V_95 != V_73 ) {
V_91 = F_86 ( V_46 , V_95 -> V_71 -> V_81 ,
V_95 -> V_72 ) ;
if ( ! V_91 )
return V_91 ;
V_95 = V_95 -> V_71 -> V_207 ;
}
if ( F_185 ( V_73 ) )
return F_86 ( V_46 , V_73 -> V_80 -> V_81 ,
0 ) ;
else
return F_86 ( V_46 , V_73 -> V_71 -> V_81 ,
V_73 -> V_72 ) ;
}
static inline unsigned long F_187 ( unsigned long V_208 ,
T_7 V_87 )
{
V_208 &= ~ V_209 ;
return F_188 ( V_208 + V_87 ) >> V_12 ;
}
static inline int F_189 ( struct V_51 * V_52 ,
unsigned long V_210 ,
unsigned long V_211 ,
unsigned long V_159 )
{
int V_212 , V_5 = 1 ;
unsigned long V_213 ;
V_212 = V_52 -> V_68 ;
V_213 = V_210 | V_211 ;
while ( V_212 && ! ( V_213 & ~ V_214 ) ) {
V_159 >>= V_215 ;
if ( ! V_159 )
break;
V_213 >>= V_215 ;
V_5 ++ ;
V_212 -- ;
}
return V_5 ;
}
static int F_190 ( struct V_51 * V_52 , unsigned long V_210 ,
struct V_216 * V_217 , unsigned long V_218 ,
unsigned long V_219 , int V_220 )
{
struct V_27 * V_110 = NULL , * V_28 = NULL ;
T_8 V_221 ( V_100 ) ;
int V_94 = F_2 ( V_52 -> V_1 ) - V_12 ;
unsigned long V_222 ;
unsigned int V_223 = 0 ;
unsigned long V_224 = 0 ;
F_59 ( V_94 < V_98 && ( V_210 + V_219 - 1 ) > > V_94 ) ;
if ( ( V_220 & ( V_103 | V_104 ) ) == 0 )
return - V_30 ;
V_220 &= V_103 | V_104 | V_225 ;
if ( V_217 )
V_222 = 0 ;
else {
V_222 = V_219 + 1 ;
V_100 = ( ( T_8 ) V_218 << V_12 ) | V_220 ;
}
while ( V_219 > 0 ) {
T_4 V_73 ;
if ( ! V_222 ) {
V_222 = F_187 ( V_217 -> V_96 , V_217 -> V_226 ) ;
V_217 -> V_227 = ( ( V_228 ) V_210 << V_12 ) + V_217 -> V_96 ;
V_217 -> V_229 = V_217 -> V_226 ;
V_100 = F_191 ( F_192 ( V_217 ) ) | V_220 ;
V_218 = V_100 >> V_12 ;
}
if ( ! V_28 ) {
V_223 = F_189 ( V_52 , V_210 , V_218 , V_222 ) ;
V_110 = V_28 = F_89 ( V_52 , V_210 , & V_223 ) ;
if ( ! V_28 )
return - V_118 ;
if ( V_223 > 1 ) {
V_100 |= V_107 ;
F_92 ( V_52 , V_210 ,
V_210 + F_11 ( V_223 ) - 1 ) ;
F_95 ( V_52 , V_210 ,
V_210 + F_11 ( V_223 ) - 1 ) ;
} else {
V_100 &= ~ ( T_4 ) V_107 ;
}
}
V_73 = F_193 ( & V_28 -> V_19 , 0ULL , V_100 ) ;
if ( V_73 ) {
static int V_230 = 5 ;
F_39 ( V_231 L_24 ,
V_210 , V_73 , ( unsigned long long ) V_100 ) ;
if ( V_230 ) {
V_230 -- ;
F_194 ( NULL ) ;
}
F_195 ( 1 ) ;
}
V_224 = F_11 ( V_223 ) ;
F_59 ( V_219 < V_224 ) ;
F_59 ( V_222 < V_224 ) ;
V_219 -= V_224 ;
V_210 += V_224 ;
V_218 += V_224 ;
V_100 += V_224 * V_102 ;
V_222 -= V_224 ;
V_28 ++ ;
if ( ! V_219 || F_37 ( V_28 ) ||
( V_223 > 1 && V_222 < V_224 ) ) {
F_79 ( V_52 , V_110 ,
( void * ) V_28 - ( void * ) V_110 ) ;
V_28 = NULL ;
}
if ( ! V_222 && V_219 )
V_217 = F_196 ( V_217 ) ;
}
return 0 ;
}
static inline int F_197 ( struct V_51 * V_52 , unsigned long V_210 ,
struct V_216 * V_217 , unsigned long V_219 ,
int V_220 )
{
return F_190 ( V_52 , V_210 , V_217 , 0 , V_219 , V_220 ) ;
}
static inline int F_198 ( struct V_51 * V_52 , unsigned long V_210 ,
unsigned long V_218 , unsigned long V_219 ,
int V_220 )
{
return F_190 ( V_52 , V_210 , NULL , V_218 , V_219 , V_220 ) ;
}
static void F_199 ( struct V_45 * V_46 , T_2 V_71 , T_2 V_72 )
{
if ( ! V_46 )
return;
F_87 ( V_46 , V_71 , V_72 ) ;
V_46 -> V_162 . V_205 ( V_46 , 0 , 0 , 0 ,
V_137 ) ;
V_46 -> V_162 . V_163 ( V_46 , 0 , 0 , 0 , V_146 ) ;
}
static inline void F_200 ( struct V_152 * V_153 )
{
F_201 ( & V_155 ) ;
F_202 ( & V_153 -> V_232 ) ;
F_202 ( & V_153 -> V_233 ) ;
if ( V_153 -> V_70 )
V_153 -> V_70 -> V_234 . V_46 = NULL ;
}
static void F_176 ( struct V_51 * V_52 )
{
struct V_152 * V_153 ;
unsigned long V_54 , V_235 ;
F_82 ( & V_155 , V_54 ) ;
while ( ! F_203 ( & V_52 -> V_78 ) ) {
V_153 = F_204 ( V_52 -> V_78 . V_113 ,
struct V_152 , V_232 ) ;
F_200 ( V_153 ) ;
F_83 ( & V_155 , V_54 ) ;
F_130 ( V_153 ) ;
F_199 ( V_153 -> V_46 , V_153 -> V_71 , V_153 -> V_72 ) ;
if ( V_52 -> V_54 & V_55 ) {
F_205 ( V_153 -> V_46 , V_153 -> V_70 ) ;
F_82 ( & V_52 -> V_177 , V_235 ) ;
if ( F_206 ( V_153 -> V_46 -> V_173 ,
V_52 -> V_57 ) ) {
V_52 -> V_178 -- ;
F_72 ( V_52 ) ;
}
F_83 ( & V_52 -> V_177 , V_235 ) ;
}
F_50 ( V_153 ) ;
F_82 ( & V_155 , V_54 ) ;
}
F_83 ( & V_155 , V_54 ) ;
}
static struct V_51 * F_207 ( struct V_69 * V_70 )
{
struct V_152 * V_153 ;
V_153 = V_70 -> V_234 . V_46 ;
if ( V_153 )
return V_153 -> V_52 ;
return NULL ;
}
static inline struct V_152 *
F_208 ( int V_77 , int V_71 , int V_72 )
{
struct V_152 * V_153 ;
F_125 (info, &device_domain_list, global)
if ( V_153 -> V_46 -> V_77 == V_77 && V_153 -> V_71 == V_71 &&
V_153 -> V_72 == V_72 )
return V_153 ;
return NULL ;
}
static struct V_51 * F_209 ( struct V_45 * V_46 ,
int V_71 , int V_72 ,
struct V_69 * V_70 ,
struct V_51 * V_52 )
{
struct V_51 * V_63 = NULL ;
struct V_152 * V_153 ;
unsigned long V_54 ;
V_153 = F_49 () ;
if ( ! V_153 )
return NULL ;
V_153 -> V_71 = V_71 ;
V_153 -> V_72 = V_72 ;
V_153 -> V_70 = V_70 ;
V_153 -> V_52 = V_52 ;
V_153 -> V_46 = V_46 ;
if ( ! V_70 )
V_52 -> V_54 |= V_236 ;
F_82 ( & V_155 , V_54 ) ;
if ( V_70 )
V_63 = F_207 ( V_70 ) ;
else {
struct V_152 * V_237 ;
V_237 = F_208 ( V_46 -> V_77 , V_71 , V_72 ) ;
if ( V_237 )
V_63 = V_237 -> V_52 ;
}
if ( V_63 ) {
F_83 ( & V_155 , V_54 ) ;
F_50 ( V_153 ) ;
return V_63 ;
}
F_210 ( & V_153 -> V_232 , & V_52 -> V_78 ) ;
F_210 ( & V_153 -> V_233 , & V_238 ) ;
if ( V_70 )
V_70 -> V_234 . V_46 = V_153 ;
F_83 ( & V_155 , V_54 ) ;
return V_52 ;
}
static struct V_51 * F_211 ( struct V_69 * V_70 , int V_114 )
{
struct V_51 * V_52 , * free = NULL ;
struct V_45 * V_46 = NULL ;
struct V_152 * V_153 ;
struct V_74 * V_239 = NULL ;
unsigned long V_54 ;
T_2 V_71 , V_72 , V_240 , V_241 ;
V_52 = F_207 ( V_70 ) ;
if ( V_52 )
return V_52 ;
if ( F_74 ( V_70 ) ) {
struct V_74 * V_76 = F_75 ( V_70 ) ;
T_3 V_77 ;
V_77 = F_76 ( V_76 -> V_71 ) ;
V_239 = F_184 ( V_76 ) ;
if ( V_239 ) {
if ( F_185 ( V_239 ) ) {
V_240 = V_239 -> V_80 -> V_81 ;
V_241 = 0 ;
} else {
V_240 = V_239 -> V_71 -> V_81 ;
V_241 = V_239 -> V_72 ;
}
F_82 ( & V_155 , V_54 ) ;
V_153 = F_208 ( V_77 ,
V_240 ,
V_241 ) ;
if ( V_153 ) {
V_46 = V_153 -> V_46 ;
V_52 = V_153 -> V_52 ;
}
F_83 ( & V_155 , V_54 ) ;
if ( V_153 )
goto V_242;
}
}
V_46 = F_73 ( V_70 , & V_71 , & V_72 ) ;
if ( ! V_46 )
goto error;
V_52 = F_156 ( false ) ;
if ( ! V_52 )
goto error;
if ( F_160 ( V_52 , V_46 ) ) {
F_47 ( V_52 ) ;
V_52 = NULL ;
goto error;
}
free = V_52 ;
if ( F_172 ( V_52 , V_114 ) )
goto error;
if ( V_239 ) {
V_52 = F_209 ( V_46 , V_240 , V_241 ,
NULL , V_52 ) ;
if ( ! V_52 )
goto error;
}
V_242:
V_52 = F_209 ( V_46 , V_71 , V_72 , V_70 , V_52 ) ;
error:
if ( free != V_52 )
F_155 ( free ) ;
return V_52 ;
}
static int F_212 ( struct V_51 * V_52 ,
unsigned long long V_194 ,
unsigned long long V_83 )
{
unsigned long V_243 = V_194 >> V_12 ;
unsigned long V_244 = V_83 >> V_12 ;
if ( ! F_166 ( & V_52 -> V_195 , F_12 ( V_243 ) ,
F_12 ( V_244 ) ) ) {
F_39 ( V_151 L_25 ) ;
return - V_118 ;
}
F_122 ( L_26 ,
V_194 , V_83 , V_52 -> V_181 ) ;
F_92 ( V_52 , V_243 , V_244 ) ;
return F_198 ( V_52 , V_243 , V_243 ,
V_244 - V_243 + 1 ,
V_103 | V_104 ) ;
}
static int F_213 ( struct V_69 * V_70 ,
unsigned long long V_194 ,
unsigned long long V_83 )
{
struct V_51 * V_52 ;
int V_91 ;
V_52 = F_211 ( V_70 , V_50 ) ;
if ( ! V_52 )
return - V_118 ;
if ( V_52 == V_245 && V_246 ) {
F_39 ( L_27 ,
F_214 ( V_70 ) , V_194 , V_83 ) ;
return 0 ;
}
F_39 ( V_32
L_28 ,
F_214 ( V_70 ) , V_194 , V_83 ) ;
if ( V_83 < V_194 ) {
F_215 ( 1 , L_29
L_30 ,
F_216 ( V_247 ) ,
F_216 ( V_248 ) ,
F_216 ( V_249 ) ) ;
V_91 = - V_250 ;
goto error;
}
if ( V_83 >> F_2 ( V_52 -> V_1 ) ) {
F_215 ( 1 , L_31
L_30 ,
F_2 ( V_52 -> V_1 ) ,
F_216 ( V_247 ) ,
F_216 ( V_248 ) ,
F_216 ( V_249 ) ) ;
V_91 = - V_250 ;
goto error;
}
V_91 = F_212 ( V_52 , V_194 , V_83 ) ;
if ( V_91 )
goto error;
V_91 = F_183 ( V_52 , V_70 , V_201 ) ;
if ( V_91 )
goto error;
return 0 ;
error:
F_155 ( V_52 ) ;
return V_91 ;
}
static inline int F_217 ( struct V_251 * V_252 ,
struct V_69 * V_70 )
{
if ( V_70 -> V_234 . V_46 == V_253 )
return 0 ;
return F_213 ( V_70 , V_252 -> V_254 ,
V_252 -> V_255 ) ;
}
static inline void F_218 ( void )
{
struct V_74 * V_76 ;
int V_91 ;
V_76 = F_219 ( V_256 << 8 , NULL ) ;
if ( ! V_76 )
return;
F_39 ( V_32 L_32 ) ;
V_91 = F_213 ( & V_76 -> V_70 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_91 )
F_39 ( V_151 L_33
L_34 ) ;
}
static inline void F_218 ( void )
{
return;
}
static int T_1 F_220 ( int V_257 )
{
struct V_60 * V_61 ;
struct V_45 * V_46 ;
int V_101 , V_91 = 0 ;
V_245 = F_156 ( false ) ;
if ( ! V_245 )
return - V_202 ;
V_245 -> V_54 = V_56 ;
F_65 (iommu, drhd) {
V_91 = F_160 ( V_245 , V_46 ) ;
if ( V_91 ) {
F_155 ( V_245 ) ;
return - V_202 ;
}
}
if ( F_221 ( V_245 , V_50 ) ) {
F_155 ( V_245 ) ;
return - V_202 ;
}
F_122 ( L_35 ,
V_245 -> V_181 ) ;
if ( V_257 )
return 0 ;
F_222 (nid) {
unsigned long V_108 , V_258 ;
int V_62 ;
F_223 (i, nid, &start_pfn, &end_pfn, NULL) {
V_91 = F_212 ( V_245 ,
F_224 ( V_108 ) , F_224 ( V_258 ) ) ;
if ( V_91 )
return V_91 ;
}
}
return 0 ;
}
static int F_225 ( struct V_69 * V_70 )
{
struct V_152 * V_153 ;
if ( F_226 ( ! V_259 ) )
return 0 ;
V_153 = V_70 -> V_234 . V_46 ;
if ( V_153 && V_153 != V_253 )
return ( V_153 -> V_52 == V_245 ) ;
return 0 ;
}
static int F_227 ( struct V_51 * V_52 ,
struct V_69 * V_70 , int V_199 )
{
struct V_51 * V_260 ;
struct V_45 * V_46 ;
T_2 V_71 , V_72 ;
int V_91 ;
V_46 = F_73 ( V_70 , & V_71 , & V_72 ) ;
if ( ! V_46 )
return - V_189 ;
V_260 = F_209 ( V_46 , V_71 , V_72 , V_70 , V_52 ) ;
if ( V_260 != V_52 )
return - V_261 ;
V_91 = F_183 ( V_52 , V_70 , V_199 ) ;
if ( V_91 ) {
F_228 ( V_52 , V_70 ) ;
return V_91 ;
}
return 0 ;
}
static bool F_229 ( struct V_69 * V_70 )
{
struct V_251 * V_252 ;
struct V_69 * V_73 ;
int V_62 ;
F_64 () ;
F_230 (rmrr) {
F_78 (rmrr->devices,
rmrr->devices_cnt, i, tmp)
if ( V_73 == V_70 ) {
F_66 () ;
return true ;
}
}
F_66 () ;
return false ;
}
static int F_231 ( struct V_69 * V_70 , int V_262 )
{
if ( F_74 ( V_70 ) ) {
struct V_74 * V_76 = F_75 ( V_70 ) ;
if ( F_229 ( V_70 ) &&
( V_76 -> V_263 >> 8 ) != V_264 )
return 0 ;
if ( ( V_259 & V_265 ) && F_232 ( V_76 ) )
return 1 ;
if ( ( V_259 & V_266 ) && F_233 ( V_76 ) )
return 1 ;
if ( ! ( V_259 & V_267 ) )
return 0 ;
if ( ! F_185 ( V_76 ) ) {
if ( ! F_234 ( V_76 -> V_71 ) )
return 0 ;
if ( V_76 -> V_263 >> 8 == V_268 )
return 0 ;
} else if ( F_235 ( V_76 ) == V_269 )
return 0 ;
} else {
if ( F_229 ( V_70 ) )
return 0 ;
}
if ( ! V_262 ) {
V_25 V_270 = * V_70 -> V_270 ;
if ( V_70 -> V_271 &&
V_70 -> V_271 < V_270 )
V_270 = V_70 -> V_271 ;
return V_270 >= F_236 ( V_70 ) ;
}
return 1 ;
}
static int T_1 F_237 ( struct V_69 * V_70 , int V_257 )
{
int V_91 ;
if ( ! F_231 ( V_70 , 1 ) )
return 0 ;
V_91 = F_227 ( V_245 , V_70 ,
V_257 ? V_200 :
V_201 ) ;
if ( ! V_91 )
F_238 ( L_36 ,
V_257 ? L_37 : L_38 , F_214 ( V_70 ) ) ;
else if ( V_91 == - V_189 )
V_91 = 0 ;
return V_91 ;
}
static int T_1 F_239 ( int V_257 )
{
struct V_74 * V_76 = NULL ;
struct V_60 * V_61 ;
struct V_45 * V_46 ;
struct V_69 * V_70 ;
int V_62 ;
int V_91 = 0 ;
V_91 = F_220 ( V_257 ) ;
if ( V_91 )
return - V_202 ;
F_168 (pdev) {
V_91 = F_237 ( & V_76 -> V_70 , V_257 ) ;
if ( V_91 )
return V_91 ;
}
F_65 (iommu, drhd)
F_78 (drhd->devices, drhd->devices_cnt, i, dev) {
struct V_272 * V_273 ;
struct V_274 * V_275 ;
if ( V_70 -> V_71 != & V_276 )
continue;
V_275 = F_240 ( V_70 ) ;
F_241 ( & V_275 -> V_277 ) ;
F_125 (pn, &adev->physical_node_list, node) {
V_91 = F_237 ( V_273 -> V_70 , V_257 ) ;
if ( V_91 )
break;
}
F_242 ( & V_275 -> V_277 ) ;
if ( V_91 )
return V_91 ;
}
return 0 ;
}
static int T_1 F_243 ( void )
{
struct V_60 * V_61 ;
struct V_251 * V_252 ;
struct V_69 * V_70 ;
struct V_45 * V_46 ;
int V_62 , V_91 ;
F_244 (drhd) {
if ( V_58 < V_278 ) {
V_58 ++ ;
continue;
}
F_245 ( V_151 L_39 ,
V_278 ) ;
}
V_59 = F_149 ( V_58 , sizeof( struct V_45 * ) ,
V_175 ) ;
if ( ! V_59 ) {
F_39 ( V_151 L_40 ) ;
V_91 = - V_118 ;
goto error;
}
V_279 = F_246 ( V_58 *
sizeof( struct V_280 ) , V_175 ) ;
if ( ! V_279 ) {
V_91 = - V_118 ;
goto V_281;
}
F_65 (iommu, drhd) {
V_59 [ V_46 -> V_173 ] = V_46 ;
V_91 = F_145 ( V_46 ) ;
if ( V_91 )
goto V_282;
V_91 = F_102 ( V_46 ) ;
if ( V_91 ) {
F_39 ( V_151 L_41 ) ;
goto V_282;
}
if ( ! F_247 ( V_46 -> V_65 ) )
V_246 = 0 ;
}
F_65 (iommu, drhd) {
if ( V_46 -> V_154 )
continue;
F_248 ( - 1 , V_46 ) ;
F_249 ( V_46 ) ;
}
F_65 (iommu, drhd) {
if ( F_250 ( V_46 ) ) {
V_46 -> V_162 . V_205 = F_111 ;
V_46 -> V_162 . V_163 = F_116 ;
F_39 ( V_32 L_42
L_43 ,
V_46 -> V_173 ,
( unsigned long long ) V_61 -> V_283 ) ;
} else {
V_46 -> V_162 . V_205 = V_284 ;
V_46 -> V_162 . V_163 = V_285 ;
F_39 ( V_32 L_44
L_43 ,
V_46 -> V_173 ,
( unsigned long long ) V_61 -> V_283 ) ;
}
}
if ( V_286 )
V_259 |= V_267 ;
#ifdef F_251
V_259 |= V_266 ;
#endif
F_252 () ;
if ( V_259 ) {
V_91 = F_239 ( V_246 ) ;
if ( V_91 ) {
F_39 ( V_231 L_45 ) ;
goto V_282;
}
}
F_39 ( V_32 L_46 ) ;
F_230 (rmrr) {
F_78 (rmrr->devices, rmrr->devices_cnt,
i, dev) {
V_91 = F_217 ( V_252 , V_70 ) ;
if ( V_91 )
F_39 ( V_151
L_47 ) ;
}
}
F_218 () ;
F_253 (iommu, drhd) {
if ( V_61 -> V_287 ) {
if ( V_288 )
F_142 ( V_46 ) ;
continue;
}
F_109 ( V_46 ) ;
V_91 = F_254 ( V_46 ) ;
if ( V_91 )
goto V_282;
F_103 ( V_46 ) ;
V_46 -> V_162 . V_205 ( V_46 , 0 , 0 , 0 , V_137 ) ;
V_46 -> V_162 . V_163 ( V_46 , 0 , 0 , 0 , V_146 ) ;
V_91 = F_143 ( V_46 ) ;
if ( V_91 )
goto V_282;
F_142 ( V_46 ) ;
}
return 0 ;
V_282:
F_65 (iommu, drhd)
F_153 ( V_46 ) ;
F_151 ( V_279 ) ;
V_281:
F_151 ( V_59 ) ;
error:
return V_91 ;
}
static struct V_43 * F_255 ( struct V_69 * V_70 ,
struct V_51 * V_52 ,
unsigned long V_289 , T_4 V_270 )
{
struct V_43 * V_43 = NULL ;
V_270 = F_3 ( T_4 , F_256 ( V_52 -> V_114 ) , V_270 ) ;
if ( ! V_34 && V_270 > F_257 ( 32 ) ) {
V_43 = F_258 ( & V_52 -> V_195 , V_289 ,
F_167 ( F_257 ( 32 ) ) , 1 ) ;
if ( V_43 )
return V_43 ;
}
V_43 = F_258 ( & V_52 -> V_195 , V_289 , F_167 ( V_270 ) , 1 ) ;
if ( F_181 ( ! V_43 ) ) {
F_39 ( V_151 L_48 ,
V_289 , F_214 ( V_70 ) ) ;
return NULL ;
}
return V_43 ;
}
static struct V_51 * F_259 ( struct V_69 * V_70 )
{
struct V_51 * V_52 ;
int V_91 ;
V_52 = F_211 ( V_70 , V_50 ) ;
if ( ! V_52 ) {
F_39 ( V_151 L_49 ,
F_214 ( V_70 ) ) ;
return NULL ;
}
if ( F_181 ( ! F_186 ( V_70 ) ) ) {
V_91 = F_183 ( V_52 , V_70 , V_201 ) ;
if ( V_91 ) {
F_39 ( V_151 L_50 ,
F_214 ( V_70 ) ) ;
return NULL ;
}
}
return V_52 ;
}
static inline struct V_51 * F_260 ( struct V_69 * V_70 )
{
struct V_152 * V_153 ;
V_153 = V_70 -> V_234 . V_46 ;
if ( F_226 ( V_153 ) )
return V_153 -> V_52 ;
return F_259 ( V_70 ) ;
}
static int F_261 ( struct V_69 * V_70 )
{
return V_70 -> V_234 . V_46 == V_253 ;
}
static int F_262 ( struct V_69 * V_70 )
{
int V_63 ;
if ( F_261 ( V_70 ) )
return 1 ;
if ( ! V_259 )
return 0 ;
V_63 = F_225 ( V_70 ) ;
if ( V_63 ) {
if ( F_231 ( V_70 , 0 ) )
return 1 ;
else {
F_228 ( V_245 , V_70 ) ;
F_39 ( V_32 L_51 ,
F_214 ( V_70 ) ) ;
return 0 ;
}
} else {
if ( F_231 ( V_70 , 0 ) ) {
int V_91 ;
V_91 = F_227 ( V_245 , V_70 ,
V_246 ?
V_200 :
V_201 ) ;
if ( ! V_91 ) {
F_39 ( V_32 L_52 ,
F_214 ( V_70 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_228 F_263 ( struct V_69 * V_70 , T_8 V_290 ,
T_7 V_87 , int V_291 , V_25 V_270 )
{
struct V_51 * V_52 ;
T_8 V_292 ;
struct V_43 * V_43 ;
int V_220 = 0 ;
int V_91 ;
struct V_45 * V_46 ;
unsigned long V_293 = V_290 >> V_11 ;
F_59 ( V_291 == V_294 ) ;
if ( F_262 ( V_70 ) )
return V_290 ;
V_52 = F_260 ( V_70 ) ;
if ( ! V_52 )
return 0 ;
V_46 = F_58 ( V_52 ) ;
V_87 = F_187 ( V_290 , V_87 ) ;
V_43 = F_255 ( V_70 , V_52 , F_12 ( V_87 ) , V_270 ) ;
if ( ! V_43 )
goto error;
if ( V_291 == V_295 || V_291 == V_296 || \
! F_264 ( V_46 -> V_49 ) )
V_220 |= V_103 ;
if ( V_291 == V_297 || V_291 == V_296 )
V_220 |= V_104 ;
V_91 = F_198 ( V_52 , F_13 ( V_43 -> V_298 ) ,
F_13 ( V_293 ) , V_87 , V_220 ) ;
if ( V_91 )
goto error;
if ( F_141 ( V_46 -> V_49 ) )
F_136 ( V_46 , V_52 -> V_181 , F_13 ( V_43 -> V_298 ) , V_87 , 0 , 1 ) ;
else
F_109 ( V_46 ) ;
V_292 = ( T_8 ) V_43 -> V_298 << V_11 ;
V_292 += V_290 & ~ V_209 ;
return V_292 ;
error:
if ( V_43 )
F_265 ( & V_52 -> V_195 , V_43 ) ;
F_39 ( V_151 L_53 ,
F_214 ( V_70 ) , V_87 , ( unsigned long long ) V_290 , V_291 ) ;
return 0 ;
}
static V_228 F_266 ( struct V_69 * V_70 , struct V_14 * V_14 ,
unsigned long V_96 , T_7 V_87 ,
enum V_299 V_291 ,
struct V_300 * V_301 )
{
return F_263 ( V_70 , F_191 ( V_14 ) + V_96 , V_87 ,
V_291 , * V_70 -> V_270 ) ;
}
static void F_267 ( void )
{
int V_62 , V_302 ;
V_303 = 0 ;
for ( V_62 = 0 ; V_62 < V_58 ; V_62 ++ ) {
struct V_45 * V_46 = V_59 [ V_62 ] ;
if ( ! V_46 )
continue;
if ( ! V_279 [ V_62 ] . V_113 )
continue;
if ( ! F_141 ( V_46 -> V_49 ) )
V_46 -> V_162 . V_163 ( V_46 , 0 , 0 , 0 ,
V_146 ) ;
for ( V_302 = 0 ; V_302 < V_279 [ V_62 ] . V_113 ; V_302 ++ ) {
unsigned long V_67 ;
struct V_43 * V_43 = V_279 [ V_62 ] . V_43 [ V_302 ] ;
struct V_51 * V_52 = V_279 [ V_62 ] . V_52 [ V_302 ] ;
if ( F_141 ( V_46 -> V_49 ) )
F_136 ( V_46 , V_52 -> V_181 ,
V_43 -> V_298 , V_43 -> V_304 - V_43 -> V_298 + 1 ,
! V_279 [ V_62 ] . V_115 [ V_302 ] , 0 ) ;
else {
V_67 = F_137 ( F_13 ( V_43 -> V_304 - V_43 -> V_298 + 1 ) ) ;
F_133 ( V_279 [ V_62 ] . V_52 [ V_302 ] ,
( T_4 ) V_43 -> V_298 << V_11 , V_67 ) ;
}
F_265 ( & V_279 [ V_62 ] . V_52 [ V_302 ] -> V_195 , V_43 ) ;
if ( V_279 [ V_62 ] . V_115 [ V_302 ] )
F_101 ( V_279 [ V_62 ] . V_115 [ V_302 ] ) ;
}
V_279 [ V_62 ] . V_113 = 0 ;
}
V_305 = 0 ;
}
static void F_175 ( unsigned long V_306 )
{
unsigned long V_54 ;
F_82 ( & V_307 , V_54 ) ;
F_267 () ;
F_83 ( & V_307 , V_54 ) ;
}
static void F_268 ( struct V_51 * V_308 , struct V_43 * V_43 , struct V_14 * V_115 )
{
unsigned long V_54 ;
int V_113 , V_53 ;
struct V_45 * V_46 ;
F_82 ( & V_307 , V_54 ) ;
if ( V_305 == V_309 )
F_267 () ;
V_46 = F_58 ( V_308 ) ;
V_53 = V_46 -> V_173 ;
V_113 = V_279 [ V_53 ] . V_113 ;
V_279 [ V_53 ] . V_52 [ V_113 ] = V_308 ;
V_279 [ V_53 ] . V_43 [ V_113 ] = V_43 ;
V_279 [ V_53 ] . V_115 [ V_113 ] = V_115 ;
V_279 [ V_53 ] . V_113 ++ ;
if ( ! V_303 ) {
F_269 ( & V_310 , V_311 + F_270 ( 10 ) ) ;
V_303 = 1 ;
}
V_305 ++ ;
F_83 ( & V_307 , V_54 ) ;
}
static void F_271 ( struct V_69 * V_70 , V_228 V_312 ,
T_7 V_87 , enum V_299 V_291 ,
struct V_300 * V_301 )
{
struct V_51 * V_52 ;
unsigned long V_108 , V_109 ;
struct V_43 * V_43 ;
struct V_45 * V_46 ;
struct V_14 * V_115 ;
if ( F_262 ( V_70 ) )
return;
V_52 = F_207 ( V_70 ) ;
F_59 ( ! V_52 ) ;
V_46 = F_58 ( V_52 ) ;
V_43 = F_272 ( & V_52 -> V_195 , F_167 ( V_312 ) ) ;
if ( F_273 ( ! V_43 , L_54 ,
( unsigned long long ) V_312 ) )
return;
V_108 = F_13 ( V_43 -> V_298 ) ;
V_109 = F_13 ( V_43 -> V_304 + 1 ) - 1 ;
F_122 ( L_55 ,
F_214 ( V_70 ) , V_108 , V_109 ) ;
V_115 = F_100 ( V_52 , V_108 , V_109 ) ;
if ( V_35 ) {
F_136 ( V_46 , V_52 -> V_181 , V_108 ,
V_109 - V_108 + 1 , ! V_115 , 0 ) ;
F_265 ( & V_52 -> V_195 , V_43 ) ;
F_101 ( V_115 ) ;
} else {
F_268 ( V_52 , V_43 , V_115 ) ;
}
}
static void * F_274 ( struct V_69 * V_70 , T_7 V_87 ,
V_228 * V_313 , T_9 V_54 ,
struct V_300 * V_301 )
{
struct V_14 * V_14 = NULL ;
int V_314 ;
V_87 = F_188 ( V_87 ) ;
V_314 = F_275 ( V_87 ) ;
if ( ! F_262 ( V_70 ) )
V_54 &= ~ ( V_315 | V_316 ) ;
else if ( V_70 -> V_271 < F_236 ( V_70 ) ) {
if ( V_70 -> V_271 < F_257 ( 32 ) )
V_54 |= V_315 ;
else
V_54 |= V_316 ;
}
if ( V_54 & V_317 ) {
unsigned int V_176 = V_87 >> V_11 ;
V_14 = F_276 ( V_70 , V_176 , V_314 ) ;
if ( V_14 && F_262 ( V_70 ) &&
F_191 ( V_14 ) + V_87 > V_70 -> V_271 ) {
F_277 ( V_70 , V_14 , V_176 ) ;
V_14 = NULL ;
}
}
if ( ! V_14 )
V_14 = F_278 ( V_54 , V_314 ) ;
if ( ! V_14 )
return NULL ;
memset ( F_42 ( V_14 ) , 0 , V_87 ) ;
* V_313 = F_263 ( V_70 , F_191 ( V_14 ) , V_87 ,
V_296 ,
V_70 -> V_271 ) ;
if ( * V_313 )
return F_42 ( V_14 ) ;
if ( ! F_277 ( V_70 , V_14 , V_87 >> V_11 ) )
F_279 ( V_14 , V_314 ) ;
return NULL ;
}
static void F_280 ( struct V_69 * V_70 , T_7 V_87 , void * V_38 ,
V_228 V_313 , struct V_300 * V_301 )
{
int V_314 ;
struct V_14 * V_14 = F_17 ( V_38 ) ;
V_87 = F_188 ( V_87 ) ;
V_314 = F_275 ( V_87 ) ;
F_271 ( V_70 , V_313 , V_87 , V_296 , NULL ) ;
if ( ! F_277 ( V_70 , V_14 , V_87 >> V_11 ) )
F_279 ( V_14 , V_314 ) ;
}
static void F_281 ( struct V_69 * V_70 , struct V_216 * V_318 ,
int V_319 , enum V_299 V_291 ,
struct V_300 * V_301 )
{
struct V_51 * V_52 ;
unsigned long V_108 , V_109 ;
struct V_43 * V_43 ;
struct V_45 * V_46 ;
struct V_14 * V_115 ;
if ( F_262 ( V_70 ) )
return;
V_52 = F_207 ( V_70 ) ;
F_59 ( ! V_52 ) ;
V_46 = F_58 ( V_52 ) ;
V_43 = F_272 ( & V_52 -> V_195 , F_167 ( V_318 [ 0 ] . V_227 ) ) ;
if ( F_273 ( ! V_43 , L_56 ,
( unsigned long long ) V_318 [ 0 ] . V_227 ) )
return;
V_108 = F_13 ( V_43 -> V_298 ) ;
V_109 = F_13 ( V_43 -> V_304 + 1 ) - 1 ;
V_115 = F_100 ( V_52 , V_108 , V_109 ) ;
if ( V_35 ) {
F_136 ( V_46 , V_52 -> V_181 , V_108 ,
V_109 - V_108 + 1 , ! V_115 , 0 ) ;
F_265 ( & V_52 -> V_195 , V_43 ) ;
F_101 ( V_115 ) ;
} else {
F_268 ( V_52 , V_43 , V_115 ) ;
}
}
static int F_282 ( struct V_69 * V_320 ,
struct V_216 * V_318 , int V_319 , int V_291 )
{
int V_62 ;
struct V_216 * V_217 ;
F_283 (sglist, sg, nelems, i) {
F_59 ( ! F_192 ( V_217 ) ) ;
V_217 -> V_227 = F_191 ( F_192 ( V_217 ) ) + V_217 -> V_96 ;
V_217 -> V_229 = V_217 -> V_226 ;
}
return V_319 ;
}
static int F_284 ( struct V_69 * V_70 , struct V_216 * V_318 , int V_319 ,
enum V_299 V_291 , struct V_300 * V_301 )
{
int V_62 ;
struct V_51 * V_52 ;
T_7 V_87 = 0 ;
int V_220 = 0 ;
struct V_43 * V_43 = NULL ;
int V_91 ;
struct V_216 * V_217 ;
unsigned long V_321 ;
struct V_45 * V_46 ;
F_59 ( V_291 == V_294 ) ;
if ( F_262 ( V_70 ) )
return F_282 ( V_70 , V_318 , V_319 , V_291 ) ;
V_52 = F_260 ( V_70 ) ;
if ( ! V_52 )
return 0 ;
V_46 = F_58 ( V_52 ) ;
F_283 (sglist, sg, nelems, i)
V_87 += F_187 ( V_217 -> V_96 , V_217 -> V_226 ) ;
V_43 = F_255 ( V_70 , V_52 , F_12 ( V_87 ) ,
* V_70 -> V_270 ) ;
if ( ! V_43 ) {
V_318 -> V_229 = 0 ;
return 0 ;
}
if ( V_291 == V_295 || V_291 == V_296 || \
! F_264 ( V_46 -> V_49 ) )
V_220 |= V_103 ;
if ( V_291 == V_297 || V_291 == V_296 )
V_220 |= V_104 ;
V_321 = F_13 ( V_43 -> V_298 ) ;
V_91 = F_197 ( V_52 , V_321 , V_318 , V_87 , V_220 ) ;
if ( F_181 ( V_91 ) ) {
F_92 ( V_52 , V_321 ,
V_321 + V_87 - 1 ) ;
F_95 ( V_52 , V_321 ,
V_321 + V_87 - 1 ) ;
F_265 ( & V_52 -> V_195 , V_43 ) ;
return 0 ;
}
if ( F_141 ( V_46 -> V_49 ) )
F_136 ( V_46 , V_52 -> V_181 , V_321 , V_87 , 0 , 1 ) ;
else
F_109 ( V_46 ) ;
return V_319 ;
}
static int F_285 ( struct V_69 * V_70 , V_228 V_322 )
{
return ! V_322 ;
}
static inline int F_286 ( void )
{
int V_91 = 0 ;
V_41 = F_287 ( L_57 ,
sizeof( struct V_51 ) ,
0 ,
V_323 ,
NULL ) ;
if ( ! V_41 ) {
F_39 ( V_151 L_58 ) ;
V_91 = - V_118 ;
}
return V_91 ;
}
static inline int F_288 ( void )
{
int V_91 = 0 ;
V_42 = F_287 ( L_59 ,
sizeof( struct V_152 ) ,
0 ,
V_323 ,
NULL ) ;
if ( ! V_42 ) {
F_39 ( V_151 L_60 ) ;
V_91 = - V_118 ;
}
return V_91 ;
}
static inline int F_289 ( void )
{
int V_91 = 0 ;
V_44 = F_287 ( L_61 ,
sizeof( struct V_43 ) ,
0 ,
V_323 ,
NULL ) ;
if ( ! V_44 ) {
F_39 ( V_151 L_62 ) ;
V_91 = - V_118 ;
}
return V_91 ;
}
static int T_1 F_290 ( void )
{
int V_91 ;
V_91 = F_289 () ;
if ( V_91 )
return V_91 ;
V_91 = F_286 () ;
if ( V_91 )
goto V_324;
V_91 = F_288 () ;
if ( ! V_91 )
return V_91 ;
F_291 ( V_41 ) ;
V_324:
F_291 ( V_44 ) ;
return - V_118 ;
}
static void T_1 F_292 ( void )
{
F_291 ( V_42 ) ;
F_291 ( V_41 ) ;
F_291 ( V_44 ) ;
}
static void F_293 ( struct V_74 * V_76 )
{
struct V_60 * V_61 ;
T_5 V_325 ;
int V_326 ;
V_326 = F_294 ( V_76 -> V_71 , F_295 ( 0 , 0 ) , 0xb0 , & V_325 ) ;
if ( V_326 ) {
F_296 ( & V_76 -> V_70 , L_63 ) ;
return;
}
V_325 &= 0xffff0000 ;
V_61 = F_297 ( V_76 ) ;
if ( F_298 ( ! V_61 || V_61 -> V_283 - V_325 != 0xa000 ,
V_327 ,
L_64 ) )
V_76 -> V_70 . V_234 . V_46 = V_253 ;
}
static void T_1 F_299 ( void )
{
struct V_60 * V_61 ;
struct V_69 * V_70 ;
int V_62 ;
F_244 (drhd) {
if ( ! V_61 -> V_85 ) {
F_78 (drhd->devices,
drhd->devices_cnt, i, dev)
break;
if ( V_62 == V_61 -> V_328 )
V_61 -> V_287 = 1 ;
}
}
F_300 (drhd) {
if ( V_61 -> V_85 )
continue;
F_78 (drhd->devices,
drhd->devices_cnt, i, dev)
if ( ! F_74 ( V_70 ) || ! F_233 ( F_75 ( V_70 ) ) )
break;
if ( V_62 < V_61 -> V_328 )
continue;
if ( V_33 ) {
V_329 = 1 ;
} else {
V_61 -> V_287 = 1 ;
F_78 (drhd->devices,
drhd->devices_cnt, i, dev)
V_70 -> V_234 . V_46 = V_253 ;
}
}
}
static int F_301 ( void )
{
struct V_60 * V_61 ;
struct V_45 * V_46 = NULL ;
F_65 (iommu, drhd)
if ( V_46 -> V_154 )
F_302 ( V_46 ) ;
F_253 (iommu, drhd) {
if ( V_61 -> V_287 ) {
if ( V_288 )
F_142 ( V_46 ) ;
continue;
}
F_109 ( V_46 ) ;
F_103 ( V_46 ) ;
V_46 -> V_162 . V_205 ( V_46 , 0 , 0 , 0 ,
V_137 ) ;
V_46 -> V_162 . V_163 ( V_46 , 0 , 0 , 0 ,
V_146 ) ;
if ( F_143 ( V_46 ) )
return 1 ;
F_142 ( V_46 ) ;
}
return 0 ;
}
static void F_303 ( void )
{
struct V_60 * V_61 ;
struct V_45 * V_46 ;
F_65 (iommu, drhd) {
V_46 -> V_162 . V_205 ( V_46 , 0 , 0 , 0 ,
V_137 ) ;
V_46 -> V_162 . V_163 ( V_46 , 0 , 0 , 0 ,
V_146 ) ;
}
}
static int F_304 ( void )
{
struct V_60 * V_61 ;
struct V_45 * V_46 = NULL ;
unsigned long V_121 ;
F_65 (iommu, drhd) {
V_46 -> V_330 = F_246 ( sizeof( T_5 ) * V_331 ,
V_39 ) ;
if ( ! V_46 -> V_330 )
goto V_332;
}
F_303 () ;
F_65 (iommu, drhd) {
F_144 ( V_46 ) ;
F_104 ( & V_46 -> V_122 , V_121 ) ;
V_46 -> V_330 [ V_333 ] =
V_129 ( V_46 -> V_123 + V_334 ) ;
V_46 -> V_330 [ V_335 ] =
V_129 ( V_46 -> V_123 + V_336 ) ;
V_46 -> V_330 [ V_337 ] =
V_129 ( V_46 -> V_123 + V_338 ) ;
V_46 -> V_330 [ V_339 ] =
V_129 ( V_46 -> V_123 + V_340 ) ;
F_108 ( & V_46 -> V_122 , V_121 ) ;
}
return 0 ;
V_332:
F_65 (iommu, drhd)
F_151 ( V_46 -> V_330 ) ;
return - V_118 ;
}
static void F_305 ( void )
{
struct V_60 * V_61 ;
struct V_45 * V_46 = NULL ;
unsigned long V_121 ;
if ( F_301 () ) {
if ( V_288 )
F_306 ( L_65 ) ;
else
F_215 ( 1 , L_66 ) ;
return;
}
F_65 (iommu, drhd) {
F_104 ( & V_46 -> V_122 , V_121 ) ;
F_106 ( V_46 -> V_330 [ V_333 ] ,
V_46 -> V_123 + V_334 ) ;
F_106 ( V_46 -> V_330 [ V_335 ] ,
V_46 -> V_123 + V_336 ) ;
F_106 ( V_46 -> V_330 [ V_337 ] ,
V_46 -> V_123 + V_338 ) ;
F_106 ( V_46 -> V_330 [ V_339 ] ,
V_46 -> V_123 + V_340 ) ;
F_108 ( & V_46 -> V_122 , V_121 ) ;
}
F_65 (iommu, drhd)
F_151 ( V_46 -> V_330 ) ;
}
static void T_1 F_307 ( void )
{
F_308 ( & V_341 ) ;
}
static inline void F_307 ( void ) {}
int T_1 F_309 ( struct V_342 * V_343 )
{
struct V_344 * V_252 ;
struct V_251 * V_345 ;
V_345 = F_246 ( sizeof( * V_345 ) , V_175 ) ;
if ( ! V_345 )
return - V_118 ;
V_345 -> V_346 = V_343 ;
V_252 = (struct V_344 * ) V_343 ;
V_345 -> V_254 = V_252 -> V_254 ;
V_345 -> V_255 = V_252 -> V_255 ;
V_345 -> V_78 = F_310 ( ( void * ) ( V_252 + 1 ) ,
( ( void * ) V_252 ) + V_252 -> V_343 . V_226 ,
& V_345 -> V_328 ) ;
if ( V_345 -> V_328 && V_345 -> V_78 == NULL ) {
F_151 ( V_345 ) ;
return - V_118 ;
}
F_210 ( & V_345 -> V_347 , & V_348 ) ;
return 0 ;
}
int T_1 F_311 ( struct V_342 * V_346 )
{
struct V_349 * V_350 ;
struct V_351 * V_352 ;
V_350 = F_312 ( V_346 , struct V_349 , V_343 ) ;
V_352 = F_246 ( sizeof( * V_352 ) , V_175 ) ;
if ( ! V_352 )
return - V_118 ;
V_352 -> V_346 = V_346 ;
V_352 -> V_85 = V_350 -> V_54 & 0x1 ;
if ( ! V_352 -> V_85 ) {
V_352 -> V_78 = F_310 ( ( void * ) ( V_350 + 1 ) ,
( void * ) V_350 + V_350 -> V_343 . V_226 ,
& V_352 -> V_328 ) ;
if ( V_352 -> V_328 && V_352 -> V_78 == NULL ) {
F_151 ( V_352 ) ;
return - V_118 ;
}
}
F_313 ( & V_352 -> V_347 , & V_353 ) ;
return 0 ;
}
static void F_314 ( struct V_351 * V_352 )
{
F_315 ( & V_352 -> V_78 , & V_352 -> V_328 ) ;
F_151 ( V_352 ) ;
}
static void F_316 ( void )
{
struct V_251 * V_345 , * V_354 ;
struct V_351 * V_352 , * V_355 ;
F_317 (rmrru, rmrr_n, &dmar_rmrr_units, list) {
F_202 ( & V_345 -> V_347 ) ;
F_315 ( & V_345 -> V_78 , & V_345 -> V_328 ) ;
F_151 ( V_345 ) ;
}
F_317 (atsru, atsr_n, &dmar_atsr_units, list) {
F_202 ( & V_352 -> V_347 ) ;
F_314 ( V_352 ) ;
}
}
int F_127 ( struct V_74 * V_70 )
{
int V_62 , V_91 = 1 ;
struct V_356 * V_71 ;
struct V_74 * V_357 = NULL ;
struct V_69 * V_73 ;
struct V_349 * V_350 ;
struct V_351 * V_352 ;
V_70 = F_318 ( V_70 ) ;
for ( V_71 = V_70 -> V_71 ; V_71 ; V_71 = V_71 -> V_95 ) {
V_357 = V_71 -> V_207 ;
if ( ! V_357 || ! F_185 ( V_357 ) ||
F_235 ( V_357 ) == V_269 )
return 0 ;
if ( F_235 ( V_357 ) == V_358 )
break;
}
if ( ! V_357 )
return 0 ;
F_64 () ;
F_319 (atsru, &dmar_atsr_units, list) {
V_350 = F_312 ( V_352 -> V_346 , struct V_349 , V_343 ) ;
if ( V_350 -> V_77 != F_76 ( V_70 -> V_71 ) )
continue;
F_320 (atsru->devices, atsru->devices_cnt, i, tmp)
if ( V_73 == & V_357 -> V_70 )
goto V_79;
if ( V_352 -> V_85 )
goto V_79;
}
V_91 = 0 ;
V_79:
F_66 () ;
return V_91 ;
}
int F_321 ( struct V_359 * V_153 )
{
int V_91 = 0 ;
struct V_251 * V_345 ;
struct V_351 * V_352 ;
struct V_349 * V_350 ;
struct V_344 * V_252 ;
if ( ! V_360 && V_361 != V_362 )
return 0 ;
F_125 (rmrru, &dmar_rmrr_units, list) {
V_252 = F_312 ( V_345 -> V_346 ,
struct V_344 , V_343 ) ;
if ( V_153 -> V_363 == V_364 ) {
V_91 = F_322 ( V_153 , ( void * ) ( V_252 + 1 ) ,
( ( void * ) V_252 ) + V_252 -> V_343 . V_226 ,
V_252 -> V_77 , V_345 -> V_78 ,
V_345 -> V_328 ) ;
if( V_91 < 0 )
return V_91 ;
} else if ( V_153 -> V_363 == V_365 ) {
F_323 ( V_153 , V_252 -> V_77 ,
V_345 -> V_78 , V_345 -> V_328 ) ;
}
}
F_125 (atsru, &dmar_atsr_units, list) {
if ( V_352 -> V_85 )
continue;
V_350 = F_312 ( V_352 -> V_346 , struct V_349 , V_343 ) ;
if ( V_153 -> V_363 == V_364 ) {
V_91 = F_322 ( V_153 , ( void * ) ( V_350 + 1 ) ,
( void * ) V_350 + V_350 -> V_343 . V_226 ,
V_350 -> V_77 , V_352 -> V_78 ,
V_352 -> V_328 ) ;
if ( V_91 > 0 )
break;
else if( V_91 < 0 )
return V_91 ;
} else if ( V_153 -> V_363 == V_365 ) {
if ( F_323 ( V_153 , V_350 -> V_77 ,
V_352 -> V_78 , V_352 -> V_328 ) )
break;
}
}
return 0 ;
}
static int F_324 ( struct V_366 * V_367 ,
unsigned long V_368 , void * V_306 )
{
struct V_69 * V_70 = V_306 ;
struct V_51 * V_52 ;
if ( F_261 ( V_70 ) )
return 0 ;
if ( V_368 != V_369 &&
V_368 != V_365 )
return 0 ;
V_52 = F_207 ( V_70 ) ;
if ( ! V_52 )
return 0 ;
F_325 ( & V_370 ) ;
F_228 ( V_52 , V_70 ) ;
if ( ! ( V_52 -> V_54 & V_55 ) &&
! ( V_52 -> V_54 & V_56 ) &&
F_203 ( & V_52 -> V_78 ) )
F_155 ( V_52 ) ;
F_326 ( & V_370 ) ;
return 0 ;
}
static int F_327 ( struct V_366 * V_367 ,
unsigned long V_19 , void * V_371 )
{
struct V_372 * V_373 = V_371 ;
unsigned long long V_194 , V_83 ;
unsigned long V_321 , V_244 ;
switch ( V_19 ) {
case V_374 :
V_194 = V_373 -> V_108 << V_11 ;
V_83 = ( ( V_373 -> V_108 + V_373 -> V_219 ) << V_11 ) - 1 ;
if ( F_212 ( V_245 , V_194 , V_83 ) ) {
F_328 ( L_67 ,
V_194 , V_83 ) ;
return V_375 ;
}
break;
case V_376 :
case V_377 :
V_321 = F_13 ( V_373 -> V_108 ) ;
V_244 = F_13 ( V_373 -> V_108 + V_373 -> V_219 - 1 ) ;
while ( V_321 <= V_244 ) {
struct V_43 * V_43 ;
struct V_60 * V_61 ;
struct V_45 * V_46 ;
struct V_14 * V_115 ;
V_43 = F_272 ( & V_245 -> V_195 , V_321 ) ;
if ( V_43 == NULL ) {
F_122 ( L_68 ,
V_321 ) ;
break;
}
V_43 = F_329 ( & V_245 -> V_195 , V_43 ,
V_321 , V_244 ) ;
if ( V_43 == NULL ) {
F_328 ( L_69 ,
V_321 , V_244 ) ;
return V_375 ;
}
V_115 = F_100 ( V_245 , V_43 -> V_298 ,
V_43 -> V_304 ) ;
F_64 () ;
F_65 (iommu, drhd)
F_136 ( V_46 , V_245 -> V_181 ,
V_43 -> V_298 ,
V_43 -> V_304 - V_43 -> V_298 + 1 ,
! V_115 , 0 ) ;
F_66 () ;
F_101 ( V_115 ) ;
V_321 = V_43 -> V_304 + 1 ;
F_52 ( V_43 ) ;
}
break;
}
return V_378 ;
}
int T_1 F_330 ( void )
{
int V_91 = - V_189 ;
struct V_60 * V_61 ;
struct V_45 * V_46 ;
V_288 = F_331 () ;
if ( F_290 () ) {
if ( V_288 )
F_306 ( L_70 ) ;
return - V_118 ;
}
F_332 ( & V_370 ) ;
if ( F_333 () ) {
if ( V_288 )
F_306 ( L_71 ) ;
goto V_379;
}
F_65 (iommu, drhd)
if ( V_46 -> V_125 & V_169 )
F_144 ( V_46 ) ;
if ( F_334 () < 0 ) {
if ( V_288 )
F_306 ( L_72 ) ;
goto V_379;
}
if ( V_380 || V_31 )
goto V_379;
if ( F_203 ( & V_348 ) )
F_39 ( V_32 L_73 ) ;
if ( F_203 ( & V_353 ) )
F_39 ( V_32 L_74 ) ;
if ( F_163 () ) {
if ( V_288 )
F_306 ( L_75 ) ;
goto V_381;
}
F_299 () ;
V_91 = F_243 () ;
if ( V_91 ) {
if ( V_288 )
F_306 ( L_76 ) ;
F_39 ( V_151 L_77 ) ;
goto V_381;
}
F_335 ( & V_370 ) ;
F_39 ( V_32
L_78 ) ;
F_336 ( & V_310 ) ;
#ifdef F_337
V_382 = 0 ;
#endif
V_383 = & V_384 ;
F_307 () ;
F_338 ( & V_385 , & V_386 ) ;
F_339 ( & V_385 , & V_387 ) ;
if ( V_245 && ! V_246 )
F_340 ( & V_388 ) ;
V_360 = 1 ;
return 0 ;
V_381:
F_177 ( & V_183 ) ;
V_379:
F_316 () ;
F_335 ( & V_370 ) ;
F_292 () ;
return V_91 ;
}
static void F_205 ( struct V_45 * V_46 ,
struct V_69 * V_70 )
{
struct V_74 * V_73 , * V_95 , * V_76 ;
if ( ! V_46 || ! V_70 || ! F_74 ( V_70 ) )
return;
V_76 = F_75 ( V_70 ) ;
V_73 = F_184 ( V_76 ) ;
if ( V_73 ) {
V_95 = V_76 -> V_71 -> V_207 ;
while ( V_95 != V_73 ) {
F_199 ( V_46 , V_95 -> V_71 -> V_81 ,
V_95 -> V_72 ) ;
V_95 = V_95 -> V_71 -> V_207 ;
}
if ( F_185 ( V_73 ) )
F_199 ( V_46 ,
V_73 -> V_80 -> V_81 , 0 ) ;
else
F_199 ( V_46 , V_73 -> V_71 -> V_81 ,
V_73 -> V_72 ) ;
}
}
static void F_228 ( struct V_51 * V_52 ,
struct V_69 * V_70 )
{
struct V_152 * V_153 , * V_73 ;
struct V_45 * V_46 ;
unsigned long V_54 ;
int V_63 = 0 ;
T_2 V_71 , V_72 ;
V_46 = F_73 ( V_70 , & V_71 , & V_72 ) ;
if ( ! V_46 )
return;
F_82 ( & V_155 , V_54 ) ;
F_317 (info, tmp, &domain->devices, link) {
if ( V_153 -> V_46 == V_46 && V_153 -> V_71 == V_71 &&
V_153 -> V_72 == V_72 ) {
F_200 ( V_153 ) ;
F_83 ( & V_155 , V_54 ) ;
F_130 ( V_153 ) ;
F_199 ( V_46 , V_153 -> V_71 , V_153 -> V_72 ) ;
F_205 ( V_46 , V_70 ) ;
F_50 ( V_153 ) ;
F_82 ( & V_155 , V_54 ) ;
if ( V_63 )
break;
else
continue;
}
if ( V_153 -> V_46 == V_46 )
V_63 = 1 ;
}
F_83 ( & V_155 , V_54 ) ;
if ( V_63 == 0 ) {
unsigned long V_389 ;
F_82 ( & V_52 -> V_177 , V_389 ) ;
F_154 ( V_46 -> V_173 , V_52 -> V_57 ) ;
V_52 -> V_178 -- ;
F_72 ( V_52 ) ;
F_83 ( & V_52 -> V_177 , V_389 ) ;
if ( ! ( V_52 -> V_54 & V_55 ) &&
! ( V_52 -> V_54 & V_56 ) ) {
F_82 ( & V_46 -> V_89 , V_389 ) ;
F_154 ( V_52 -> V_181 , V_46 -> V_174 ) ;
V_46 -> V_164 [ V_52 -> V_181 ] = NULL ;
F_83 ( & V_46 -> V_89 , V_389 ) ;
}
}
}
static int F_221 ( struct V_51 * V_52 , int V_196 )
{
int V_197 ;
F_164 ( & V_52 -> V_195 , V_184 ) ;
F_169 ( V_52 ) ;
V_52 -> V_114 = V_196 ;
V_197 = F_171 ( V_196 ) ;
V_52 -> V_1 = F_4 ( V_197 ) ;
V_52 -> V_64 = 0 ;
V_52 -> V_66 = 0 ;
V_52 -> V_68 = 0 ;
V_52 -> V_390 = 0 ;
V_52 -> V_101 = - 1 ;
V_52 -> V_97 = (struct V_27 * ) F_40 ( V_52 -> V_101 ) ;
if ( ! V_52 -> V_97 )
return - V_118 ;
F_79 ( V_52 , V_52 -> V_97 , V_198 ) ;
return 0 ;
}
static int F_341 ( struct V_391 * V_52 )
{
struct V_51 * V_51 ;
V_51 = F_156 ( true ) ;
if ( ! V_51 ) {
F_39 ( V_151
L_79 ) ;
return - V_118 ;
}
if ( F_221 ( V_51 , V_50 ) ) {
F_39 ( V_151
L_80 ) ;
F_155 ( V_51 ) ;
return - V_118 ;
}
F_72 ( V_51 ) ;
V_52 -> V_392 = V_51 ;
V_52 -> V_393 . V_394 = 0 ;
V_52 -> V_393 . V_395 = F_342 ( V_51 -> V_114 ) ;
V_52 -> V_393 . V_396 = true ;
return 0 ;
}
static void F_343 ( struct V_391 * V_52 )
{
struct V_51 * V_51 = V_52 -> V_392 ;
V_52 -> V_392 = NULL ;
F_155 ( V_51 ) ;
}
static int F_344 ( struct V_391 * V_52 ,
struct V_69 * V_70 )
{
struct V_51 * V_51 = V_52 -> V_392 ;
struct V_45 * V_46 ;
int V_94 ;
T_2 V_71 , V_72 ;
if ( F_181 ( F_186 ( V_70 ) ) ) {
struct V_51 * V_397 ;
V_397 = F_207 ( V_70 ) ;
if ( V_397 ) {
if ( V_51 -> V_54 & V_55 ||
V_51 -> V_54 & V_56 )
F_228 ( V_397 , V_70 ) ;
else
F_176 ( V_397 ) ;
}
}
V_46 = F_73 ( V_70 , & V_71 , & V_72 ) ;
if ( ! V_46 )
return - V_189 ;
V_94 = F_2 ( V_46 -> V_1 ) ;
if ( V_94 > F_173 ( V_46 -> V_49 ) )
V_94 = F_173 ( V_46 -> V_49 ) ;
if ( V_51 -> V_390 > ( 1LL << V_94 ) ) {
F_39 ( V_151 L_81
L_82 ,
V_398 , V_94 , V_51 -> V_390 ) ;
return - V_202 ;
}
V_51 -> V_114 = V_94 ;
while ( V_46 -> V_1 < V_51 -> V_1 ) {
struct V_27 * V_28 ;
V_28 = V_51 -> V_97 ;
if ( F_35 ( V_28 ) ) {
V_51 -> V_97 = (struct V_27 * )
F_22 ( F_32 ( V_28 ) ) ;
F_43 ( V_28 ) ;
}
V_51 -> V_1 -- ;
}
return F_227 ( V_51 , V_70 , V_201 ) ;
}
static void F_345 ( struct V_391 * V_52 ,
struct V_69 * V_70 )
{
struct V_51 * V_51 = V_52 -> V_392 ;
F_228 ( V_51 , V_70 ) ;
}
static int F_346 ( struct V_391 * V_52 ,
unsigned long V_43 , T_8 V_399 ,
T_7 V_87 , int V_400 )
{
struct V_51 * V_51 = V_52 -> V_392 ;
V_25 V_390 ;
int V_220 = 0 ;
int V_91 ;
if ( V_400 & V_401 )
V_220 |= V_103 ;
if ( V_400 & V_402 )
V_220 |= V_104 ;
if ( ( V_400 & V_403 ) && V_51 -> V_66 )
V_220 |= V_225 ;
V_390 = V_43 + V_87 ;
if ( V_51 -> V_390 < V_390 ) {
V_25 V_83 ;
V_83 = F_342 ( V_51 -> V_114 ) + 1 ;
if ( V_83 < V_390 ) {
F_39 ( V_151 L_81
L_82 ,
V_398 , V_51 -> V_114 , V_390 ) ;
return - V_202 ;
}
V_51 -> V_390 = V_390 ;
}
V_87 = F_187 ( V_399 , V_87 ) ;
V_91 = F_198 ( V_51 , V_43 >> V_12 ,
V_399 >> V_12 , V_87 , V_220 ) ;
return V_91 ;
}
static T_7 F_347 ( struct V_391 * V_52 ,
unsigned long V_43 , T_7 V_87 )
{
struct V_51 * V_51 = V_52 -> V_392 ;
struct V_14 * V_115 = NULL ;
struct V_45 * V_46 ;
unsigned long V_108 , V_109 ;
unsigned int V_404 ;
int V_53 , V_182 , V_171 , V_5 = 0 ;
if ( ! F_89 ( V_51 , V_43 >> V_12 , & V_5 ) )
F_115 () ;
if ( V_87 < V_102 << F_6 ( V_5 ) )
V_87 = V_102 << F_6 ( V_5 ) ;
V_108 = V_43 >> V_12 ;
V_109 = ( V_43 + V_87 - 1 ) >> V_12 ;
V_115 = F_100 ( V_51 , V_108 , V_109 ) ;
V_404 = V_109 - V_108 + 1 ;
F_62 (iommu_id, dmar_domain->iommu_bmp, g_num_of_iommus) {
V_46 = V_59 [ V_53 ] ;
V_171 = F_146 ( V_46 -> V_49 ) ;
F_62 (num, iommu->domain_ids, ndomains) {
if ( V_46 -> V_164 [ V_182 ] == V_51 )
F_136 ( V_46 , V_182 , V_108 ,
V_404 , ! V_115 , 0 ) ;
}
}
F_101 ( V_115 ) ;
if ( V_51 -> V_390 == V_43 + V_87 )
V_51 -> V_390 = V_43 ;
return V_87 ;
}
static T_8 F_348 ( struct V_391 * V_52 ,
V_228 V_43 )
{
struct V_51 * V_51 = V_52 -> V_392 ;
struct V_27 * V_28 ;
int V_5 = 0 ;
V_25 V_405 = 0 ;
V_28 = F_89 ( V_51 , V_43 >> V_12 , & V_5 ) ;
if ( V_28 )
V_405 = F_32 ( V_28 ) ;
return V_405 ;
}
static int F_349 ( struct V_391 * V_52 ,
unsigned long V_49 )
{
struct V_51 * V_51 = V_52 -> V_392 ;
if ( V_49 == V_406 )
return V_51 -> V_66 ;
if ( V_49 == V_407 )
return V_408 ;
return 0 ;
}
static int F_350 ( struct V_69 * V_70 )
{
struct V_74 * V_76 = F_75 ( V_70 ) ;
struct V_74 * V_357 , * V_409 = NULL ;
struct V_410 * V_411 ;
int V_91 ;
T_2 V_71 , V_72 ;
if ( ! F_73 ( V_70 , & V_71 , & V_72 ) )
return - V_189 ;
V_357 = F_184 ( V_76 ) ;
if ( V_357 ) {
if ( F_185 ( V_357 ) )
V_409 = F_351 (
F_76 ( V_76 -> V_71 ) ,
V_357 -> V_80 -> V_81 , 0 ) ;
if ( ! V_409 )
V_409 = F_352 ( V_357 ) ;
} else
V_409 = F_352 ( V_76 ) ;
F_353 ( & V_409 , F_354 ( V_409 ) ) ;
if ( V_409 -> V_412 &&
! F_355 ( V_409 , V_413 ) ) {
T_2 V_62 , V_414 = F_179 ( V_409 -> V_72 ) ;
for ( V_62 = 0 ; V_62 < 8 ; V_62 ++ ) {
struct V_74 * V_73 ;
V_73 = F_356 ( V_409 -> V_71 , F_295 ( V_414 , V_62 ) ) ;
if ( ! V_73 )
continue;
if ( ! F_355 ( V_73 , V_413 ) ) {
F_353 ( & V_409 , V_73 ) ;
break;
}
F_357 ( V_73 ) ;
}
}
while ( ! F_234 ( V_409 -> V_71 ) ) {
struct V_356 * V_71 = V_409 -> V_71 ;
while ( ! V_71 -> V_207 ) {
if ( ! F_234 ( V_71 ) )
V_71 = V_71 -> V_95 ;
else
goto V_415;
}
if ( F_358 ( V_71 -> V_207 , NULL , V_413 ) )
break;
F_353 ( & V_409 , F_352 ( V_71 -> V_207 ) ) ;
}
V_415:
V_411 = F_359 ( & V_409 -> V_70 ) ;
F_357 ( V_409 ) ;
if ( ! V_411 ) {
V_411 = F_360 () ;
if ( F_361 ( V_411 ) )
return F_362 ( V_411 ) ;
}
V_91 = F_363 ( V_411 , V_70 ) ;
F_364 ( V_411 ) ;
return V_91 ;
}
static void F_365 ( struct V_69 * V_70 )
{
F_366 ( V_70 ) ;
}
static void F_367 ( struct V_74 * V_70 )
{
F_39 ( V_32 L_83 ) ;
V_33 = 0 ;
}
static void F_368 ( struct V_74 * V_70 )
{
F_39 ( V_32 L_84 ) ;
V_131 = 1 ;
}
static void F_369 ( struct V_74 * V_70 )
{
unsigned short V_416 ;
if ( F_370 ( V_70 , V_417 , & V_416 ) )
return;
if ( ! ( V_416 & V_418 ) ) {
F_39 ( V_32 L_85 ) ;
V_33 = 0 ;
} else if ( V_33 ) {
F_39 ( V_32 L_86 ) ;
V_35 = 1 ;
}
}
static void T_1 F_252 ( void )
{
struct V_74 * V_76 ;
T_10 V_419 ;
V_76 = F_371 ( V_420 , 0x3a3e , NULL ) ;
if ( ! V_76 )
return;
F_357 ( V_76 ) ;
V_76 = F_371 ( V_420 , 0x342e , NULL ) ;
if ( ! V_76 )
return;
if ( F_372 ( V_76 , 0x188 , & V_419 ) ) {
F_357 ( V_76 ) ;
return;
}
F_357 ( V_76 ) ;
if ( V_419 & 1 )
return;
V_419 &= 0x1c ;
if ( V_419 == 0x10 )
return;
if ( ! V_419 ) {
F_215 ( 1 , L_87
L_30 ,
F_216 ( V_247 ) ,
F_216 ( V_248 ) ,
F_216 ( V_249 ) ) ;
V_259 |= V_265 ;
return;
}
F_39 ( V_421 L_88 ,
V_419 ) ;
}
