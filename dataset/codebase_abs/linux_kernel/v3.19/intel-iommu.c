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
V_18 -> V_19 &= ~ V_21 ;
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
V_23 -> V_24 &= ~ V_21 ;
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
if ( ! V_18 ) {
F_106 ( L_14 ,
V_54 -> V_119 ) ;
return - V_120 ;
}
F_87 ( V_54 , V_18 , V_121 ) ;
F_85 ( & V_54 -> V_94 , V_48 ) ;
V_54 -> V_17 = V_18 ;
F_86 ( & V_54 -> V_94 , V_48 ) ;
return 0 ;
}
static void F_107 ( struct V_53 * V_54 )
{
void * V_91 ;
T_5 V_122 ;
unsigned long V_123 ;
V_91 = V_54 -> V_17 ;
F_108 ( & V_54 -> V_124 , V_123 ) ;
F_109 ( V_54 -> V_125 + V_126 , F_88 ( V_91 ) ) ;
F_110 ( V_54 -> V_127 | V_128 , V_54 -> V_125 + V_129 ) ;
F_111 ( V_54 , V_130 ,
V_131 , ( V_122 & V_132 ) , V_122 ) ;
F_112 ( & V_54 -> V_124 , V_123 ) ;
}
static void F_113 ( struct V_53 * V_54 )
{
T_5 V_19 ;
unsigned long V_123 ;
if ( ! V_133 && ! F_114 ( V_54 -> V_57 ) )
return;
F_108 ( & V_54 -> V_124 , V_123 ) ;
F_110 ( V_54 -> V_127 | V_134 , V_54 -> V_125 + V_129 ) ;
F_111 ( V_54 , V_130 ,
V_131 , ( ! ( V_19 & V_135 ) ) , V_19 ) ;
F_112 ( & V_54 -> V_124 , V_123 ) ;
}
static void F_115 ( struct V_53 * V_54 ,
T_3 V_136 , T_3 V_137 , T_2 V_138 ,
V_25 type )
{
V_25 V_19 = 0 ;
unsigned long V_123 ;
switch ( type ) {
case V_139 :
V_19 = V_139 ;
break;
case V_140 :
V_19 = V_140 | F_116 ( V_136 ) ;
break;
case V_141 :
V_19 = V_141 | F_116 ( V_136 )
| F_117 ( V_137 ) | F_118 ( V_138 ) ;
break;
default:
F_119 () ;
}
V_19 |= V_142 ;
F_108 ( & V_54 -> V_124 , V_123 ) ;
F_109 ( V_54 -> V_125 + V_143 , V_19 ) ;
F_111 ( V_54 , V_143 ,
V_144 , ( ! ( V_19 & V_142 ) ) , V_19 ) ;
F_112 ( & V_54 -> V_124 , V_123 ) ;
}
static void F_120 ( struct V_53 * V_54 , T_3 V_136 ,
V_25 V_91 , unsigned int V_145 , V_25 type )
{
int V_146 = F_121 ( V_54 -> V_68 ) ;
V_25 V_19 = 0 , V_147 = 0 ;
unsigned long V_123 ;
switch ( type ) {
case V_148 :
V_19 = V_148 | V_149 ;
break;
case V_150 :
V_19 = V_150 | V_149 | F_122 ( V_136 ) ;
break;
case V_151 :
V_19 = V_151 | V_149 | F_122 ( V_136 ) ;
V_147 = V_145 | V_91 ;
break;
default:
F_119 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_123 ( V_54 -> V_57 ) )
V_19 |= V_152 ;
F_108 ( & V_54 -> V_124 , V_123 ) ;
if ( V_147 )
F_109 ( V_54 -> V_125 + V_146 , V_147 ) ;
F_109 ( V_54 -> V_125 + V_146 + 8 , V_19 ) ;
F_111 ( V_54 , V_146 + 8 ,
V_144 , ( ! ( V_19 & V_149 ) ) , V_19 ) ;
F_112 ( & V_54 -> V_124 , V_123 ) ;
if ( F_124 ( V_19 ) == 0 )
F_39 ( V_153 L_15 ) ;
if ( F_124 ( V_19 ) != F_125 ( type ) )
F_126 ( L_16 ,
( unsigned long long ) F_125 ( type ) ,
( unsigned long long ) F_124 ( V_19 ) ) ;
}
static struct V_154 *
F_127 ( struct V_46 * V_47 , struct V_53 * V_54 ,
T_2 V_76 , T_2 V_77 )
{
int V_66 = 0 ;
unsigned long V_48 ;
struct V_154 * V_155 ;
struct V_79 * V_81 ;
if ( ! F_128 ( V_54 -> V_68 ) )
return NULL ;
if ( ! V_54 -> V_156 )
return NULL ;
F_85 ( & V_157 , V_48 ) ;
F_129 (info, &domain->devices, link)
if ( V_155 -> V_54 == V_54 && V_155 -> V_76 == V_76 &&
V_155 -> V_77 == V_77 ) {
V_66 = 1 ;
break;
}
F_86 ( & V_157 , V_48 ) ;
if ( ! V_66 || ! V_155 -> V_75 || ! F_77 ( V_155 -> V_75 ) )
return NULL ;
V_81 = F_78 ( V_155 -> V_75 ) ;
if ( ! F_130 ( V_81 , V_158 ) )
return NULL ;
if ( ! F_131 ( V_81 ) )
return NULL ;
return V_155 ;
}
static void F_132 ( struct V_154 * V_155 )
{
if ( ! V_155 || ! F_77 ( V_155 -> V_75 ) )
return;
F_133 ( F_78 ( V_155 -> V_75 ) , V_12 ) ;
}
static void F_134 ( struct V_154 * V_155 )
{
if ( ! V_155 -> V_75 || ! F_77 ( V_155 -> V_75 ) ||
! F_135 ( F_78 ( V_155 -> V_75 ) ) )
return;
F_136 ( F_78 ( V_155 -> V_75 ) ) ;
}
static void F_137 ( struct V_46 * V_47 ,
V_25 V_91 , unsigned V_71 )
{
T_3 V_159 , V_160 ;
unsigned long V_48 ;
struct V_154 * V_155 ;
F_85 ( & V_157 , V_48 ) ;
F_129 (info, &domain->devices, link) {
struct V_79 * V_81 ;
if ( ! V_155 -> V_75 || ! F_77 ( V_155 -> V_75 ) )
continue;
V_81 = F_78 ( V_155 -> V_75 ) ;
if ( ! F_135 ( V_81 ) )
continue;
V_159 = V_155 -> V_76 << 8 | V_155 -> V_77 ;
V_160 = F_138 ( V_81 ) ;
F_139 ( V_155 -> V_54 , V_159 , V_160 , V_91 , V_71 ) ;
}
F_86 ( & V_157 , V_48 ) ;
}
static void F_140 ( struct V_53 * V_54 , T_3 V_136 ,
unsigned long V_6 , unsigned int V_161 , int V_162 , int V_163 )
{
unsigned int V_71 = F_141 ( F_142 ( V_161 ) ) ;
T_4 V_91 = ( T_4 ) V_6 << V_12 ;
F_62 ( V_161 == 0 ) ;
if ( V_162 )
V_162 = 1 << 6 ;
if ( ! F_143 ( V_54 -> V_57 ) || V_71 > F_144 ( V_54 -> V_57 ) )
V_54 -> V_164 . V_165 ( V_54 , V_136 , 0 , 0 ,
V_150 ) ;
else
V_54 -> V_164 . V_165 ( V_54 , V_136 , V_91 | V_162 , V_71 ,
V_151 ) ;
if ( ! F_145 ( V_54 -> V_57 ) || ! V_163 )
F_137 ( V_54 -> V_166 [ V_136 ] , V_91 , V_71 ) ;
}
static void F_146 ( struct V_53 * V_54 )
{
T_5 V_167 ;
unsigned long V_48 ;
F_108 ( & V_54 -> V_124 , V_48 ) ;
V_167 = V_131 ( V_54 -> V_125 + V_168 ) ;
V_167 &= ~ V_169 ;
F_110 ( V_167 , V_54 -> V_125 + V_168 ) ;
F_111 ( V_54 , V_168 ,
V_131 , ! ( V_167 & V_170 ) , V_167 ) ;
F_112 ( & V_54 -> V_124 , V_48 ) ;
}
static void F_147 ( struct V_53 * V_54 )
{
T_5 V_122 ;
unsigned long V_48 ;
F_108 ( & V_54 -> V_124 , V_48 ) ;
V_54 -> V_127 |= V_171 ;
F_110 ( V_54 -> V_127 , V_54 -> V_125 + V_129 ) ;
F_111 ( V_54 , V_130 ,
V_131 , ( V_122 & V_172 ) , V_122 ) ;
F_112 ( & V_54 -> V_124 , V_48 ) ;
}
static void F_148 ( struct V_53 * V_54 )
{
T_5 V_122 ;
unsigned long V_123 ;
F_108 ( & V_54 -> V_124 , V_123 ) ;
V_54 -> V_127 &= ~ V_171 ;
F_110 ( V_54 -> V_127 , V_54 -> V_125 + V_129 ) ;
F_111 ( V_54 , V_130 ,
V_131 , ( ! ( V_122 & V_172 ) ) , V_122 ) ;
F_112 ( & V_54 -> V_124 , V_123 ) ;
}
static int F_149 ( struct V_53 * V_54 )
{
unsigned long V_173 ;
unsigned long V_174 ;
V_173 = F_150 ( V_54 -> V_57 ) ;
F_126 ( L_17 ,
V_54 -> V_175 , V_173 ) ;
V_174 = F_151 ( V_173 ) ;
F_152 ( & V_54 -> V_94 ) ;
V_54 -> V_176 = F_153 ( V_174 , sizeof( unsigned long ) , V_177 ) ;
if ( ! V_54 -> V_176 ) {
F_106 ( L_18 ,
V_54 -> V_175 ) ;
return - V_120 ;
}
V_54 -> V_166 = F_153 ( V_173 , sizeof( struct V_46 * ) ,
V_177 ) ;
if ( ! V_54 -> V_166 ) {
F_106 ( L_19 ,
V_54 -> V_175 ) ;
F_154 ( V_54 -> V_176 ) ;
V_54 -> V_176 = NULL ;
return - V_120 ;
}
if ( F_145 ( V_54 -> V_57 ) )
F_155 ( 0 , V_54 -> V_176 ) ;
return 0 ;
}
static void F_156 ( struct V_53 * V_54 )
{
struct V_46 * V_47 ;
int V_65 ;
if ( ( V_54 -> V_166 ) && ( V_54 -> V_176 ) ) {
F_65 (i, iommu->domain_ids, cap_ndoms(iommu->cap)) {
if ( F_145 ( V_54 -> V_57 ) && V_65 == 0 )
continue;
V_47 = V_54 -> V_166 [ V_65 ] ;
F_157 ( V_65 , V_54 -> V_176 ) ;
if ( F_158 ( V_47 , V_54 ) == 0 &&
! F_53 ( V_47 ) )
F_159 ( V_47 ) ;
}
}
if ( V_54 -> V_127 & V_171 )
F_148 ( V_54 ) ;
}
static void F_160 ( struct V_53 * V_54 )
{
if ( ( V_54 -> V_166 ) && ( V_54 -> V_176 ) ) {
F_154 ( V_54 -> V_166 ) ;
F_154 ( V_54 -> V_176 ) ;
V_54 -> V_166 = NULL ;
V_54 -> V_176 = NULL ;
}
V_62 [ V_54 -> V_175 ] = NULL ;
F_91 ( V_54 ) ;
}
static struct V_46 * F_161 ( int V_48 )
{
static T_6 V_178 = F_162 ( 0 ) ;
struct V_46 * V_47 ;
V_47 = F_45 () ;
if ( ! V_47 )
return NULL ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
V_47 -> V_103 = - 1 ;
V_47 -> V_48 = V_48 ;
F_152 ( & V_47 -> V_179 ) ;
F_163 ( & V_47 -> V_83 ) ;
if ( V_48 & V_49 )
V_47 -> V_180 = F_164 ( & V_178 ) ;
return V_47 ;
}
static int F_165 ( struct V_46 * V_47 ,
struct V_53 * V_54 )
{
int V_181 ;
unsigned long V_173 ;
V_173 = F_150 ( V_54 -> V_57 ) ;
V_181 = F_166 ( V_54 -> V_176 , V_173 ) ;
if ( V_181 < V_173 ) {
F_155 ( V_181 , V_54 -> V_176 ) ;
V_54 -> V_166 [ V_181 ] = V_47 ;
} else {
V_181 = - V_182 ;
}
return V_181 ;
}
static int F_167 ( struct V_46 * V_47 ,
struct V_53 * V_54 )
{
int V_181 ;
unsigned long V_48 ;
F_85 ( & V_54 -> V_94 , V_48 ) ;
V_181 = F_165 ( V_47 , V_54 ) ;
F_86 ( & V_54 -> V_94 , V_48 ) ;
if ( V_181 < 0 )
F_106 ( L_20 ) ;
return V_181 ;
}
static int F_168 ( struct V_46 * V_47 ,
struct V_53 * V_54 )
{
int V_181 ;
unsigned long V_173 ;
V_173 = F_150 ( V_54 -> V_57 ) ;
F_65 (num, iommu->domain_ids, ndomains)
if ( V_54 -> V_166 [ V_181 ] == V_47 )
return V_181 ;
return F_165 ( V_47 , V_54 ) ;
}
static void F_169 ( struct V_46 * V_47 ,
struct V_53 * V_54 )
{
unsigned long V_48 ;
int V_181 , V_173 ;
F_85 ( & V_54 -> V_94 , V_48 ) ;
if ( F_54 ( V_47 ) ) {
V_173 = F_150 ( V_54 -> V_57 ) ;
F_65 (num, iommu->domain_ids, ndomains) {
if ( V_54 -> V_166 [ V_181 ] == V_47 ) {
F_157 ( V_181 , V_54 -> V_176 ) ;
V_54 -> V_166 [ V_181 ] = NULL ;
break;
}
}
} else {
F_157 ( V_47 -> V_180 , V_54 -> V_176 ) ;
V_54 -> V_166 [ V_47 -> V_180 ] = NULL ;
}
F_86 ( & V_54 -> V_94 , V_48 ) ;
}
static void F_170 ( struct V_46 * V_47 ,
struct V_53 * V_54 )
{
unsigned long V_48 ;
F_85 ( & V_47 -> V_179 , V_48 ) ;
if ( ! F_171 ( V_54 -> V_175 , V_47 -> V_60 ) ) {
V_47 -> V_183 ++ ;
if ( V_47 -> V_183 == 1 )
V_47 -> V_103 = V_54 -> V_38 ;
F_75 ( V_47 ) ;
}
F_86 ( & V_47 -> V_179 , V_48 ) ;
}
static int F_158 ( struct V_46 * V_47 ,
struct V_53 * V_54 )
{
unsigned long V_48 ;
int V_184 = V_185 ;
F_85 ( & V_47 -> V_179 , V_48 ) ;
if ( F_172 ( V_54 -> V_175 , V_47 -> V_60 ) ) {
V_184 = -- V_47 -> V_183 ;
F_75 ( V_47 ) ;
}
F_86 ( & V_47 -> V_179 , V_48 ) ;
return V_184 ;
}
static int F_173 ( void )
{
struct V_79 * V_81 = NULL ;
struct V_44 * V_44 ;
int V_65 ;
F_174 ( & V_186 , V_187 ) ;
F_175 ( & V_186 . V_188 ,
& V_189 ) ;
V_44 = F_176 ( & V_186 , F_177 ( V_190 ) ,
F_177 ( V_191 ) ) ;
if ( ! V_44 ) {
F_39 ( V_153 L_21 ) ;
return - V_192 ;
}
F_178 (pdev) {
struct V_193 * V_194 ;
for ( V_65 = 0 ; V_65 < V_195 ; V_65 ++ ) {
V_194 = & V_81 -> V_193 [ V_65 ] ;
if ( ! V_194 -> V_48 || ! ( V_194 -> V_48 & V_196 ) )
continue;
V_44 = F_176 ( & V_186 ,
F_177 ( V_194 -> V_197 ) ,
F_177 ( V_194 -> V_88 ) ) ;
if ( ! V_44 ) {
F_39 ( V_153 L_22 ) ;
return - V_192 ;
}
}
}
return 0 ;
}
static void F_179 ( struct V_46 * V_47 )
{
F_180 ( & V_186 , & V_47 -> V_198 ) ;
}
static inline int F_181 ( int V_115 )
{
int V_1 ;
int V_194 = ( V_115 - 12 ) % 9 ;
if ( V_194 == 0 )
V_1 = V_115 ;
else
V_1 = V_115 + 9 - V_194 ;
if ( V_1 > 64 )
V_1 = 64 ;
return V_1 ;
}
static int F_182 ( struct V_46 * V_47 , int V_199 )
{
struct V_53 * V_54 ;
int V_200 , V_1 ;
unsigned long V_56 ;
F_174 ( & V_47 -> V_198 , V_187 ) ;
F_179 ( V_47 ) ;
V_54 = F_61 ( V_47 ) ;
if ( V_199 > F_183 ( V_54 -> V_57 ) )
V_199 = F_183 ( V_54 -> V_57 ) ;
V_47 -> V_115 = V_199 ;
V_200 = F_181 ( V_199 ) ;
V_1 = F_4 ( V_200 ) ;
V_56 = F_57 ( V_54 -> V_57 ) ;
if ( ! F_58 ( V_1 , & V_56 ) ) {
F_126 ( L_23 , V_1 ) ;
V_1 = F_184 ( & V_56 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_192 ;
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
return - V_120 ;
F_87 ( V_54 , V_47 -> V_100 , V_201 ) ;
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
F_185 ( 0 ) ;
F_186 ( V_47 ) ;
F_187 ( & V_47 -> V_198 ) ;
V_116 = F_103 ( V_47 , 0 , F_99 ( V_47 -> V_115 ) ) ;
F_67 () ;
F_68 (iommu, drhd)
F_169 ( V_47 , V_54 ) ;
F_69 () ;
F_104 ( V_116 ) ;
F_47 ( V_47 ) ;
}
static int F_188 ( struct V_46 * V_47 ,
struct V_53 * V_54 ,
T_2 V_76 , T_2 V_77 , int V_202 )
{
struct V_22 * V_23 ;
unsigned long V_48 ;
struct V_27 * V_100 ;
int V_180 ;
int V_1 ;
struct V_154 * V_155 = NULL ;
F_126 ( L_24 ,
V_76 , F_189 ( V_77 ) , F_190 ( V_77 ) ) ;
F_62 ( ! V_47 -> V_100 ) ;
F_62 ( V_202 != V_203 &&
V_202 != V_204 ) ;
V_23 = F_84 ( V_54 , V_76 , V_77 ) ;
if ( ! V_23 )
return - V_120 ;
F_85 ( & V_54 -> V_94 , V_48 ) ;
if ( F_23 ( V_23 ) ) {
F_86 ( & V_54 -> V_94 , V_48 ) ;
return 0 ;
}
V_180 = V_47 -> V_180 ;
V_100 = V_47 -> V_100 ;
if ( F_54 ( V_47 ) ) {
if ( F_53 ( V_47 ) ) {
V_180 = F_168 ( V_47 , V_54 ) ;
if ( V_180 < 0 ) {
F_86 ( & V_54 -> V_94 , V_48 ) ;
F_106 ( L_20 ) ;
return - V_205 ;
}
}
if ( V_202 != V_203 ) {
for ( V_1 = V_47 -> V_1 ; V_1 != V_54 -> V_1 ; V_1 -- ) {
V_100 = F_22 ( F_32 ( V_100 ) ) ;
if ( ! F_35 ( V_100 ) ) {
F_86 ( & V_54 -> V_94 , V_48 ) ;
return - V_120 ;
}
}
}
}
F_29 ( V_23 , V_180 ) ;
if ( V_202 != V_203 ) {
V_155 = F_127 ( V_47 , V_54 , V_76 , V_77 ) ;
V_202 = V_155 ? V_206 :
V_204 ;
}
if ( F_191 ( V_202 == V_203 ) )
F_28 ( V_23 , V_54 -> V_207 ) ;
else {
F_27 ( V_23 , F_88 ( V_100 ) ) ;
F_28 ( V_23 , V_54 -> V_1 ) ;
}
F_26 ( V_23 , V_202 ) ;
F_25 ( V_23 ) ;
F_24 ( V_23 ) ;
F_82 ( V_47 , V_23 , sizeof( * V_23 ) ) ;
if ( F_145 ( V_54 -> V_57 ) ) {
V_54 -> V_164 . V_208 ( V_54 , 0 ,
( ( ( T_3 ) V_76 ) << 8 ) | V_77 ,
V_209 ,
V_141 ) ;
V_54 -> V_164 . V_165 ( V_54 , V_180 , 0 , 0 , V_150 ) ;
} else {
F_113 ( V_54 ) ;
}
F_132 ( V_155 ) ;
F_86 ( & V_54 -> V_94 , V_48 ) ;
F_170 ( V_47 , V_54 ) ;
return 0 ;
}
static int F_192 ( struct V_79 * V_81 ,
T_3 V_210 , void * V_211 )
{
struct V_212 * V_213 = V_211 ;
return F_188 ( V_213 -> V_47 , V_213 -> V_54 ,
F_193 ( V_210 ) , V_210 & 0xff ,
V_213 -> V_202 ) ;
}
static int
F_194 ( struct V_46 * V_47 , struct V_74 * V_75 ,
int V_202 )
{
struct V_53 * V_54 ;
T_2 V_76 , V_77 ;
struct V_212 V_213 ;
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return - V_192 ;
if ( ! F_77 ( V_75 ) )
return F_188 ( V_47 , V_54 , V_76 , V_77 ,
V_202 ) ;
V_213 . V_47 = V_47 ;
V_213 . V_54 = V_54 ;
V_213 . V_202 = V_202 ;
return F_195 ( F_78 ( V_75 ) ,
& F_192 , & V_213 ) ;
}
static int F_196 ( struct V_79 * V_81 ,
T_3 V_210 , void * V_211 )
{
struct V_53 * V_54 = V_211 ;
return ! F_89 ( V_54 , F_193 ( V_210 ) , V_210 & 0xff ) ;
}
static int F_197 ( struct V_74 * V_75 )
{
struct V_53 * V_54 ;
T_2 V_76 , V_77 ;
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return - V_192 ;
if ( ! F_77 ( V_75 ) )
return F_89 ( V_54 , V_76 , V_77 ) ;
return ! F_195 ( F_78 ( V_75 ) ,
F_196 , V_54 ) ;
}
static inline unsigned long F_198 ( unsigned long V_214 ,
T_7 V_92 )
{
V_214 &= ~ V_215 ;
return F_199 ( V_214 + V_92 ) >> V_12 ;
}
static inline int F_200 ( struct V_46 * V_47 ,
unsigned long V_216 ,
unsigned long V_217 ,
unsigned long V_161 )
{
int V_218 , V_5 = 1 ;
unsigned long V_219 ;
V_218 = V_47 -> V_73 ;
V_219 = V_216 | V_217 ;
while ( V_218 && ! ( V_219 & ~ V_220 ) ) {
V_161 >>= V_221 ;
if ( ! V_161 )
break;
V_219 >>= V_221 ;
V_5 ++ ;
V_218 -- ;
}
return V_5 ;
}
static int F_201 ( struct V_46 * V_47 , unsigned long V_216 ,
struct V_222 * V_223 , unsigned long V_224 ,
unsigned long V_225 , int V_226 )
{
struct V_27 * V_111 = NULL , * V_28 = NULL ;
T_8 V_227 ( V_102 ) ;
unsigned long V_228 = 0 ;
unsigned int V_229 = 0 ;
unsigned long V_230 = 0 ;
F_62 ( ! F_55 ( V_47 , V_216 + V_225 - 1 ) ) ;
if ( ( V_226 & ( V_105 | V_106 ) ) == 0 )
return - V_31 ;
V_226 &= V_105 | V_106 | V_231 ;
if ( ! V_223 ) {
V_228 = V_225 ;
V_102 = ( ( T_8 ) V_224 << V_12 ) | V_226 ;
}
while ( V_225 > 0 ) {
T_4 V_78 ;
if ( ! V_228 ) {
V_228 = F_198 ( V_223 -> V_99 , V_223 -> V_232 ) ;
V_223 -> V_233 = ( ( V_234 ) V_216 << V_12 ) + V_223 -> V_99 ;
V_223 -> V_235 = V_223 -> V_232 ;
V_102 = F_202 ( F_203 ( V_223 ) ) | V_226 ;
V_224 = V_102 >> V_12 ;
}
if ( ! V_28 ) {
V_229 = F_200 ( V_47 , V_216 , V_224 , V_228 ) ;
V_111 = V_28 = F_92 ( V_47 , V_216 , & V_229 ) ;
if ( ! V_28 )
return - V_120 ;
if ( V_229 > 1 ) {
V_102 |= V_29 ;
V_230 = F_11 ( V_229 ) ;
F_98 ( V_47 , V_216 ,
V_216 + V_230 - 1 ) ;
} else {
V_102 &= ~ ( T_4 ) V_29 ;
}
}
V_78 = F_204 ( & V_28 -> V_19 , 0ULL , V_102 ) ;
if ( V_78 ) {
static int V_236 = 5 ;
F_39 ( V_237 L_25 ,
V_216 , V_78 , ( unsigned long long ) V_102 ) ;
if ( V_236 ) {
V_236 -- ;
F_205 ( NULL ) ;
}
F_206 ( 1 ) ;
}
V_230 = F_11 ( V_229 ) ;
F_62 ( V_225 < V_230 ) ;
F_62 ( V_228 < V_230 ) ;
V_225 -= V_230 ;
V_216 += V_230 ;
V_224 += V_230 ;
V_102 += V_230 * V_104 ;
V_228 -= V_230 ;
V_28 ++ ;
if ( ! V_225 || F_37 ( V_28 ) ||
( V_229 > 1 && V_228 < V_230 ) ) {
F_82 ( V_47 , V_111 ,
( void * ) V_28 - ( void * ) V_111 ) ;
V_28 = NULL ;
}
if ( ! V_228 && V_225 )
V_223 = F_207 ( V_223 ) ;
}
return 0 ;
}
static inline int F_208 ( struct V_46 * V_47 , unsigned long V_216 ,
struct V_222 * V_223 , unsigned long V_225 ,
int V_226 )
{
return F_201 ( V_47 , V_216 , V_223 , 0 , V_225 , V_226 ) ;
}
static inline int F_209 ( struct V_46 * V_47 , unsigned long V_216 ,
unsigned long V_224 , unsigned long V_225 ,
int V_226 )
{
return F_201 ( V_47 , V_216 , NULL , V_224 , V_225 , V_226 ) ;
}
static void F_210 ( struct V_53 * V_54 , T_2 V_76 , T_2 V_77 )
{
if ( ! V_54 )
return;
F_90 ( V_54 , V_76 , V_77 ) ;
V_54 -> V_164 . V_208 ( V_54 , 0 , 0 , 0 ,
V_139 ) ;
V_54 -> V_164 . V_165 ( V_54 , 0 , 0 , 0 , V_148 ) ;
}
static inline void F_211 ( struct V_154 * V_155 )
{
F_212 ( & V_157 ) ;
F_213 ( & V_155 -> V_238 ) ;
F_213 ( & V_155 -> V_239 ) ;
if ( V_155 -> V_75 )
V_155 -> V_75 -> V_240 . V_54 = NULL ;
}
static void F_186 ( struct V_46 * V_47 )
{
struct V_154 * V_155 , * V_78 ;
unsigned long V_48 ;
F_85 ( & V_157 , V_48 ) ;
F_214 (info, tmp, &domain->devices, link) {
F_211 ( V_155 ) ;
F_86 ( & V_157 , V_48 ) ;
F_134 ( V_155 ) ;
F_210 ( V_155 -> V_54 , V_155 -> V_76 , V_155 -> V_77 ) ;
if ( F_53 ( V_47 ) ) {
F_215 ( V_155 -> V_54 , V_155 -> V_75 ) ;
F_158 ( V_47 , V_155 -> V_54 ) ;
}
F_50 ( V_155 ) ;
F_85 ( & V_157 , V_48 ) ;
}
F_86 ( & V_157 , V_48 ) ;
}
static struct V_46 * F_216 ( struct V_74 * V_75 )
{
struct V_154 * V_155 ;
V_155 = V_75 -> V_240 . V_54 ;
if ( V_155 )
return V_155 -> V_47 ;
return NULL ;
}
static inline struct V_154 *
F_217 ( int V_82 , int V_76 , int V_77 )
{
struct V_154 * V_155 ;
F_129 (info, &device_domain_list, global)
if ( V_155 -> V_54 -> V_82 == V_82 && V_155 -> V_76 == V_76 &&
V_155 -> V_77 == V_77 )
return V_155 ;
return NULL ;
}
static struct V_46 * F_218 ( struct V_53 * V_54 ,
int V_76 , int V_77 ,
struct V_74 * V_75 ,
struct V_46 * V_47 )
{
struct V_46 * V_66 = NULL ;
struct V_154 * V_155 ;
unsigned long V_48 ;
V_155 = F_49 () ;
if ( ! V_155 )
return NULL ;
V_155 -> V_76 = V_76 ;
V_155 -> V_77 = V_77 ;
V_155 -> V_75 = V_75 ;
V_155 -> V_47 = V_47 ;
V_155 -> V_54 = V_54 ;
F_85 ( & V_157 , V_48 ) ;
if ( V_75 )
V_66 = F_216 ( V_75 ) ;
else {
struct V_154 * V_241 ;
V_241 = F_217 ( V_54 -> V_82 , V_76 , V_77 ) ;
if ( V_241 )
V_66 = V_241 -> V_47 ;
}
if ( V_66 ) {
F_86 ( & V_157 , V_48 ) ;
F_50 ( V_155 ) ;
return V_66 ;
}
F_219 ( & V_155 -> V_238 , & V_47 -> V_83 ) ;
F_219 ( & V_155 -> V_239 , & V_242 ) ;
if ( V_75 )
V_75 -> V_240 . V_54 = V_155 ;
F_86 ( & V_157 , V_48 ) ;
return V_47 ;
}
static int F_220 ( struct V_79 * V_81 , T_3 V_210 , void * V_211 )
{
* ( T_3 * ) V_211 = V_210 ;
return 0 ;
}
static struct V_46 * F_221 ( struct V_74 * V_75 , int V_115 )
{
struct V_46 * V_47 , * V_78 ;
struct V_53 * V_54 ;
struct V_154 * V_155 ;
T_3 V_243 ;
unsigned long V_48 ;
T_2 V_76 , V_77 ;
V_47 = F_216 ( V_75 ) ;
if ( V_47 )
return V_47 ;
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return NULL ;
if ( F_77 ( V_75 ) ) {
struct V_79 * V_81 = F_78 ( V_75 ) ;
F_195 ( V_81 , F_220 , & V_243 ) ;
F_85 ( & V_157 , V_48 ) ;
V_155 = F_217 ( F_79 ( V_81 -> V_76 ) ,
F_193 ( V_243 ) ,
V_243 & 0xff ) ;
if ( V_155 ) {
V_54 = V_155 -> V_54 ;
V_47 = V_155 -> V_47 ;
}
F_86 ( & V_157 , V_48 ) ;
if ( V_155 )
goto V_244;
}
V_47 = F_161 ( 0 ) ;
if ( ! V_47 )
return NULL ;
V_47 -> V_180 = F_167 ( V_47 , V_54 ) ;
if ( V_47 -> V_180 < 0 ) {
F_47 ( V_47 ) ;
return NULL ;
}
F_170 ( V_47 , V_54 ) ;
if ( F_182 ( V_47 , V_115 ) ) {
F_159 ( V_47 ) ;
return NULL ;
}
if ( F_77 ( V_75 ) ) {
V_78 = F_218 ( V_54 , F_193 ( V_243 ) ,
V_243 & 0xff , NULL , V_47 ) ;
if ( ! V_78 || V_78 != V_47 ) {
F_159 ( V_47 ) ;
V_47 = V_78 ;
}
if ( ! V_47 )
return NULL ;
}
V_244:
V_78 = F_218 ( V_54 , V_76 , V_77 , V_75 , V_47 ) ;
if ( ! V_78 || V_78 != V_47 ) {
F_159 ( V_47 ) ;
V_47 = V_78 ;
}
return V_47 ;
}
static int F_222 ( struct V_46 * V_47 ,
unsigned long long V_197 ,
unsigned long long V_88 )
{
unsigned long V_245 = V_197 >> V_12 ;
unsigned long V_246 = V_88 >> V_12 ;
if ( ! F_176 ( & V_47 -> V_198 , F_12 ( V_245 ) ,
F_12 ( V_246 ) ) ) {
F_39 ( V_153 L_26 ) ;
return - V_120 ;
}
F_126 ( L_27 ,
V_197 , V_88 , V_47 -> V_180 ) ;
F_95 ( V_47 , V_245 , V_246 ) ;
return F_209 ( V_47 , V_245 , V_245 ,
V_246 - V_245 + 1 ,
V_105 | V_106 ) ;
}
static int F_223 ( struct V_74 * V_75 ,
unsigned long long V_197 ,
unsigned long long V_88 )
{
struct V_46 * V_47 ;
int V_70 ;
V_47 = F_221 ( V_75 , V_58 ) ;
if ( ! V_47 )
return - V_120 ;
if ( V_47 == V_247 && V_248 ) {
F_39 ( L_28 ,
F_224 ( V_75 ) , V_197 , V_88 ) ;
return 0 ;
}
F_39 ( V_33
L_29 ,
F_224 ( V_75 ) , V_197 , V_88 ) ;
if ( V_88 < V_197 ) {
F_225 ( 1 , L_30
L_31 ,
F_226 ( V_249 ) ,
F_226 ( V_250 ) ,
F_226 ( V_251 ) ) ;
V_70 = - V_252 ;
goto error;
}
if ( V_88 >> F_2 ( V_47 -> V_1 ) ) {
F_225 ( 1 , L_32
L_31 ,
F_2 ( V_47 -> V_1 ) ,
F_226 ( V_249 ) ,
F_226 ( V_250 ) ,
F_226 ( V_251 ) ) ;
V_70 = - V_252 ;
goto error;
}
V_70 = F_222 ( V_47 , V_197 , V_88 ) ;
if ( V_70 )
goto error;
V_70 = F_194 ( V_47 , V_75 , V_204 ) ;
if ( V_70 )
goto error;
return 0 ;
error:
F_159 ( V_47 ) ;
return V_70 ;
}
static inline int F_227 ( struct V_253 * V_254 ,
struct V_74 * V_75 )
{
if ( V_75 -> V_240 . V_54 == V_255 )
return 0 ;
return F_223 ( V_75 , V_254 -> V_256 ,
V_254 -> V_257 ) ;
}
static inline void F_228 ( void )
{
struct V_79 * V_81 ;
int V_70 ;
V_81 = F_229 ( V_258 << 8 , NULL ) ;
if ( ! V_81 )
return;
F_39 ( V_33 L_33 ) ;
V_70 = F_223 ( & V_81 -> V_75 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_70 )
F_39 ( V_153 L_34
L_35 ) ;
F_230 ( V_81 ) ;
}
static inline void F_228 ( void )
{
return;
}
static int T_1 F_231 ( int V_259 )
{
struct V_63 * V_64 ;
struct V_53 * V_54 ;
int V_103 , V_70 = 0 ;
bool V_260 = true ;
V_247 = F_161 ( V_50 ) ;
if ( ! V_247 )
return - V_205 ;
F_68 (iommu, drhd) {
V_70 = F_167 ( V_247 , V_54 ) ;
if ( V_70 < 0 ) {
F_159 ( V_247 ) ;
return - V_205 ;
} else if ( V_260 ) {
V_247 -> V_180 = V_70 ;
V_260 = false ;
} else if ( V_247 -> V_180 != V_70 ) {
F_159 ( V_247 ) ;
return - V_205 ;
}
F_170 ( V_247 , V_54 ) ;
}
if ( F_232 ( V_247 , V_58 ) ) {
F_159 ( V_247 ) ;
return - V_205 ;
}
F_126 ( L_36 ,
V_247 -> V_180 ) ;
if ( V_259 )
return 0 ;
F_233 (nid) {
unsigned long V_109 , V_261 ;
int V_65 ;
F_234 (i, nid, &start_pfn, &end_pfn, NULL) {
V_70 = F_222 ( V_247 ,
F_235 ( V_109 ) , F_235 ( V_261 ) ) ;
if ( V_70 )
return V_70 ;
}
}
return 0 ;
}
static int F_236 ( struct V_74 * V_75 )
{
struct V_154 * V_155 ;
if ( F_237 ( ! V_262 ) )
return 0 ;
V_155 = V_75 -> V_240 . V_54 ;
if ( V_155 && V_155 != V_255 )
return ( V_155 -> V_47 == V_247 ) ;
return 0 ;
}
static int F_238 ( struct V_46 * V_47 ,
struct V_74 * V_75 , int V_202 )
{
struct V_46 * V_263 ;
struct V_53 * V_54 ;
T_2 V_76 , V_77 ;
int V_70 ;
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return - V_192 ;
V_263 = F_218 ( V_54 , V_76 , V_77 , V_75 , V_47 ) ;
if ( V_263 != V_47 )
return - V_264 ;
V_70 = F_194 ( V_47 , V_75 , V_202 ) ;
if ( V_70 ) {
F_239 ( V_47 , V_75 ) ;
return V_70 ;
}
return 0 ;
}
static bool F_240 ( struct V_74 * V_75 )
{
struct V_253 * V_254 ;
struct V_74 * V_78 ;
int V_65 ;
F_67 () ;
F_241 (rmrr) {
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
static bool F_242 ( struct V_74 * V_75 )
{
if ( ! F_240 ( V_75 ) )
return false ;
if ( F_77 ( V_75 ) ) {
struct V_79 * V_81 = F_78 ( V_75 ) ;
if ( ( V_81 -> V_265 >> 8 ) == V_266 )
return false ;
}
return true ;
}
static int F_243 ( struct V_74 * V_75 , int V_267 )
{
if ( F_77 ( V_75 ) ) {
struct V_79 * V_81 = F_78 ( V_75 ) ;
if ( F_242 ( V_75 ) )
return 0 ;
if ( ( V_262 & V_268 ) && F_244 ( V_81 ) )
return 1 ;
if ( ( V_262 & V_269 ) && F_245 ( V_81 ) )
return 1 ;
if ( ! ( V_262 & V_270 ) )
return 0 ;
if ( ! F_246 ( V_81 ) ) {
if ( ! F_247 ( V_81 -> V_76 ) )
return 0 ;
if ( V_81 -> V_265 >> 8 == V_271 )
return 0 ;
} else if ( F_248 ( V_81 ) == V_272 )
return 0 ;
} else {
if ( F_240 ( V_75 ) )
return 0 ;
}
if ( ! V_267 ) {
V_25 V_273 = * V_75 -> V_273 ;
if ( V_75 -> V_274 &&
V_75 -> V_274 < V_273 )
V_273 = V_75 -> V_274 ;
return V_273 >= F_249 ( V_75 ) ;
}
return 1 ;
}
static int T_1 F_250 ( struct V_74 * V_75 , int V_259 )
{
int V_70 ;
if ( ! F_243 ( V_75 , 1 ) )
return 0 ;
V_70 = F_238 ( V_247 , V_75 ,
V_259 ? V_203 :
V_204 ) ;
if ( ! V_70 )
F_251 ( L_37 ,
V_259 ? L_38 : L_39 , F_224 ( V_75 ) ) ;
else if ( V_70 == - V_192 )
V_70 = 0 ;
return V_70 ;
}
static int T_1 F_252 ( int V_259 )
{
struct V_79 * V_81 = NULL ;
struct V_63 * V_64 ;
struct V_53 * V_54 ;
struct V_74 * V_75 ;
int V_65 ;
int V_70 = 0 ;
V_70 = F_231 ( V_259 ) ;
if ( V_70 )
return - V_205 ;
F_178 (pdev) {
V_70 = F_250 ( & V_81 -> V_75 , V_259 ) ;
if ( V_70 )
return V_70 ;
}
F_68 (iommu, drhd)
F_81 (drhd->devices, drhd->devices_cnt, i, dev) {
struct V_275 * V_276 ;
struct V_277 * V_278 ;
if ( V_75 -> V_76 != & V_279 )
continue;
V_278 = F_253 ( V_75 ) ;
F_254 ( & V_278 -> V_280 ) ;
F_129 (pn, &adev->physical_node_list, node) {
V_70 = F_250 ( V_276 -> V_75 , V_259 ) ;
if ( V_70 )
break;
}
F_255 ( & V_278 -> V_280 ) ;
if ( V_70 )
return V_70 ;
}
return 0 ;
}
static void F_256 ( struct V_53 * V_54 )
{
if ( ! V_54 -> V_156 ) {
F_257 ( - 1 , V_54 ) ;
F_258 ( V_54 ) ;
}
if ( F_259 ( V_54 ) ) {
V_54 -> V_164 . V_208 = F_115 ;
V_54 -> V_164 . V_165 = F_120 ;
F_251 ( L_40 ,
V_54 -> V_119 ) ;
} else {
V_54 -> V_164 . V_208 = V_281 ;
V_54 -> V_164 . V_165 = V_282 ;
F_251 ( L_41 , V_54 -> V_119 ) ;
}
}
static int T_1 F_260 ( void )
{
struct V_63 * V_64 ;
struct V_253 * V_254 ;
struct V_74 * V_75 ;
struct V_53 * V_54 ;
int V_65 , V_70 ;
F_261 (drhd) {
if ( V_61 < V_283 ) {
V_61 ++ ;
continue;
}
F_262 ( V_153 L_42 ,
V_283 ) ;
}
if ( V_61 < V_283 )
V_61 = V_283 ;
V_62 = F_153 ( V_61 , sizeof( struct V_53 * ) ,
V_177 ) ;
if ( ! V_62 ) {
F_39 ( V_153 L_43 ) ;
V_70 = - V_120 ;
goto error;
}
V_284 = F_263 ( V_61 *
sizeof( struct V_285 ) , V_177 ) ;
if ( ! V_284 ) {
V_70 = - V_120 ;
goto V_286;
}
F_68 (iommu, drhd) {
V_62 [ V_54 -> V_175 ] = V_54 ;
V_70 = F_149 ( V_54 ) ;
if ( V_70 )
goto V_287;
V_70 = F_105 ( V_54 ) ;
if ( V_70 )
goto V_287;
if ( ! F_264 ( V_54 -> V_68 ) )
V_248 = 0 ;
}
F_68 (iommu, drhd)
F_256 ( V_54 ) ;
if ( V_288 )
V_262 |= V_270 ;
#ifdef F_265
V_262 |= V_269 ;
#endif
F_266 () ;
if ( V_262 ) {
V_70 = F_252 ( V_248 ) ;
if ( V_70 ) {
F_39 ( V_237 L_44 ) ;
goto V_287;
}
}
F_39 ( V_33 L_45 ) ;
F_241 (rmrr) {
F_81 (rmrr->devices, rmrr->devices_cnt,
i, dev) {
V_70 = F_227 ( V_254 , V_75 ) ;
if ( V_70 )
F_39 ( V_153
L_46 ) ;
}
}
F_228 () ;
F_267 (iommu, drhd) {
if ( V_64 -> V_289 ) {
if ( V_290 )
F_146 ( V_54 ) ;
continue;
}
F_113 ( V_54 ) ;
V_70 = F_268 ( V_54 ) ;
if ( V_70 )
goto V_287;
F_107 ( V_54 ) ;
V_54 -> V_164 . V_208 ( V_54 , 0 , 0 , 0 , V_139 ) ;
V_54 -> V_164 . V_165 ( V_54 , 0 , 0 , 0 , V_148 ) ;
F_147 ( V_54 ) ;
F_146 ( V_54 ) ;
}
return 0 ;
V_287:
F_68 (iommu, drhd) {
F_156 ( V_54 ) ;
F_160 ( V_54 ) ;
}
F_154 ( V_284 ) ;
V_286:
F_154 ( V_62 ) ;
error:
return V_70 ;
}
static struct V_44 * F_269 ( struct V_74 * V_75 ,
struct V_46 * V_47 ,
unsigned long V_291 , T_4 V_273 )
{
struct V_44 * V_44 = NULL ;
V_273 = F_3 ( T_4 , F_270 ( V_47 -> V_115 ) , V_273 ) ;
if ( ! V_35 && V_273 > F_271 ( 32 ) ) {
V_44 = F_272 ( & V_47 -> V_198 , V_291 ,
F_177 ( F_271 ( 32 ) ) , 1 ) ;
if ( V_44 )
return V_44 ;
}
V_44 = F_272 ( & V_47 -> V_198 , V_291 , F_177 ( V_273 ) , 1 ) ;
if ( F_191 ( ! V_44 ) ) {
F_39 ( V_153 L_47 ,
V_291 , F_224 ( V_75 ) ) ;
return NULL ;
}
return V_44 ;
}
static struct V_46 * F_273 ( struct V_74 * V_75 )
{
struct V_46 * V_47 ;
int V_70 ;
V_47 = F_221 ( V_75 , V_58 ) ;
if ( ! V_47 ) {
F_39 ( V_153 L_48 ,
F_224 ( V_75 ) ) ;
return NULL ;
}
if ( F_191 ( ! F_197 ( V_75 ) ) ) {
V_70 = F_194 ( V_47 , V_75 , V_204 ) ;
if ( V_70 ) {
F_39 ( V_153 L_49 ,
F_224 ( V_75 ) ) ;
return NULL ;
}
}
return V_47 ;
}
static inline struct V_46 * F_274 ( struct V_74 * V_75 )
{
struct V_154 * V_155 ;
V_155 = V_75 -> V_240 . V_54 ;
if ( F_237 ( V_155 ) )
return V_155 -> V_47 ;
return F_273 ( V_75 ) ;
}
static int F_275 ( struct V_74 * V_75 )
{
return V_75 -> V_240 . V_54 == V_255 ;
}
static int F_276 ( struct V_74 * V_75 )
{
int V_66 ;
if ( F_275 ( V_75 ) )
return 1 ;
if ( ! V_262 )
return 0 ;
V_66 = F_236 ( V_75 ) ;
if ( V_66 ) {
if ( F_243 ( V_75 , 0 ) )
return 1 ;
else {
F_239 ( V_247 , V_75 ) ;
F_39 ( V_33 L_50 ,
F_224 ( V_75 ) ) ;
return 0 ;
}
} else {
if ( F_243 ( V_75 , 0 ) ) {
int V_70 ;
V_70 = F_238 ( V_247 , V_75 ,
V_248 ?
V_203 :
V_204 ) ;
if ( ! V_70 ) {
F_39 ( V_33 L_51 ,
F_224 ( V_75 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_234 F_277 ( struct V_74 * V_75 , T_8 V_292 ,
T_7 V_92 , int V_293 , V_25 V_273 )
{
struct V_46 * V_47 ;
T_8 V_294 ;
struct V_44 * V_44 ;
int V_226 = 0 ;
int V_70 ;
struct V_53 * V_54 ;
unsigned long V_295 = V_292 >> V_11 ;
F_62 ( V_293 == V_296 ) ;
if ( F_276 ( V_75 ) )
return V_292 ;
V_47 = F_274 ( V_75 ) ;
if ( ! V_47 )
return 0 ;
V_54 = F_61 ( V_47 ) ;
V_92 = F_198 ( V_292 , V_92 ) ;
V_44 = F_269 ( V_75 , V_47 , F_12 ( V_92 ) , V_273 ) ;
if ( ! V_44 )
goto error;
if ( V_293 == V_297 || V_293 == V_298 || \
! F_278 ( V_54 -> V_57 ) )
V_226 |= V_105 ;
if ( V_293 == V_299 || V_293 == V_298 )
V_226 |= V_106 ;
V_70 = F_209 ( V_47 , F_13 ( V_44 -> V_300 ) ,
F_13 ( V_295 ) , V_92 , V_226 ) ;
if ( V_70 )
goto error;
if ( F_145 ( V_54 -> V_57 ) )
F_140 ( V_54 , V_47 -> V_180 , F_13 ( V_44 -> V_300 ) , V_92 , 0 , 1 ) ;
else
F_113 ( V_54 ) ;
V_294 = ( T_8 ) V_44 -> V_300 << V_11 ;
V_294 += V_292 & ~ V_215 ;
return V_294 ;
error:
if ( V_44 )
F_279 ( & V_47 -> V_198 , V_44 ) ;
F_39 ( V_153 L_52 ,
F_224 ( V_75 ) , V_92 , ( unsigned long long ) V_292 , V_293 ) ;
return 0 ;
}
static V_234 F_280 ( struct V_74 * V_75 , struct V_14 * V_14 ,
unsigned long V_99 , T_7 V_92 ,
enum V_301 V_293 ,
struct V_302 * V_303 )
{
return F_277 ( V_75 , F_202 ( V_14 ) + V_99 , V_92 ,
V_293 , * V_75 -> V_273 ) ;
}
static void F_281 ( void )
{
int V_65 , V_304 ;
V_305 = 0 ;
for ( V_65 = 0 ; V_65 < V_61 ; V_65 ++ ) {
struct V_53 * V_54 = V_62 [ V_65 ] ;
if ( ! V_54 )
continue;
if ( ! V_284 [ V_65 ] . V_114 )
continue;
if ( ! F_145 ( V_54 -> V_57 ) )
V_54 -> V_164 . V_165 ( V_54 , 0 , 0 , 0 ,
V_148 ) ;
for ( V_304 = 0 ; V_304 < V_284 [ V_65 ] . V_114 ; V_304 ++ ) {
unsigned long V_71 ;
struct V_44 * V_44 = V_284 [ V_65 ] . V_44 [ V_304 ] ;
struct V_46 * V_47 = V_284 [ V_65 ] . V_47 [ V_304 ] ;
if ( F_145 ( V_54 -> V_57 ) )
F_140 ( V_54 , V_47 -> V_180 ,
V_44 -> V_300 , F_282 ( V_44 ) ,
! V_284 [ V_65 ] . V_116 [ V_304 ] , 0 ) ;
else {
V_71 = F_141 ( F_13 ( F_282 ( V_44 ) ) ) ;
F_137 ( V_284 [ V_65 ] . V_47 [ V_304 ] ,
( T_4 ) V_44 -> V_300 << V_11 , V_71 ) ;
}
F_279 ( & V_284 [ V_65 ] . V_47 [ V_304 ] -> V_198 , V_44 ) ;
if ( V_284 [ V_65 ] . V_116 [ V_304 ] )
F_104 ( V_284 [ V_65 ] . V_116 [ V_304 ] ) ;
}
V_284 [ V_65 ] . V_114 = 0 ;
}
V_306 = 0 ;
}
static void F_185 ( unsigned long V_213 )
{
unsigned long V_48 ;
F_85 ( & V_307 , V_48 ) ;
F_281 () ;
F_86 ( & V_307 , V_48 ) ;
}
static void F_283 ( struct V_46 * V_308 , struct V_44 * V_44 , struct V_14 * V_116 )
{
unsigned long V_48 ;
int V_114 , V_59 ;
struct V_53 * V_54 ;
F_85 ( & V_307 , V_48 ) ;
if ( V_306 == V_309 )
F_281 () ;
V_54 = F_61 ( V_308 ) ;
V_59 = V_54 -> V_175 ;
V_114 = V_284 [ V_59 ] . V_114 ;
V_284 [ V_59 ] . V_47 [ V_114 ] = V_308 ;
V_284 [ V_59 ] . V_44 [ V_114 ] = V_44 ;
V_284 [ V_59 ] . V_116 [ V_114 ] = V_116 ;
V_284 [ V_59 ] . V_114 ++ ;
if ( ! V_305 ) {
F_284 ( & V_310 , V_311 + F_285 ( 10 ) ) ;
V_305 = 1 ;
}
V_306 ++ ;
F_86 ( & V_307 , V_48 ) ;
}
static void F_286 ( struct V_74 * V_75 , V_234 V_312 )
{
struct V_46 * V_47 ;
unsigned long V_109 , V_110 ;
struct V_44 * V_44 ;
struct V_53 * V_54 ;
struct V_14 * V_116 ;
if ( F_276 ( V_75 ) )
return;
V_47 = F_216 ( V_75 ) ;
F_62 ( ! V_47 ) ;
V_54 = F_61 ( V_47 ) ;
V_44 = F_287 ( & V_47 -> V_198 , F_177 ( V_312 ) ) ;
if ( F_288 ( ! V_44 , L_53 ,
( unsigned long long ) V_312 ) )
return;
V_109 = F_13 ( V_44 -> V_300 ) ;
V_110 = F_13 ( V_44 -> V_313 + 1 ) - 1 ;
F_126 ( L_54 ,
F_224 ( V_75 ) , V_109 , V_110 ) ;
V_116 = F_103 ( V_47 , V_109 , V_110 ) ;
if ( V_36 ) {
F_140 ( V_54 , V_47 -> V_180 , V_109 ,
V_110 - V_109 + 1 , ! V_116 , 0 ) ;
F_279 ( & V_47 -> V_198 , V_44 ) ;
F_104 ( V_116 ) ;
} else {
F_283 ( V_47 , V_44 , V_116 ) ;
}
}
static void F_289 ( struct V_74 * V_75 , V_234 V_312 ,
T_7 V_92 , enum V_301 V_293 ,
struct V_302 * V_303 )
{
F_286 ( V_75 , V_312 ) ;
}
static void * F_290 ( struct V_74 * V_75 , T_7 V_92 ,
V_234 * V_314 , T_9 V_48 ,
struct V_302 * V_303 )
{
struct V_14 * V_14 = NULL ;
int V_315 ;
V_92 = F_199 ( V_92 ) ;
V_315 = F_291 ( V_92 ) ;
if ( ! F_276 ( V_75 ) )
V_48 &= ~ ( V_316 | V_317 ) ;
else if ( V_75 -> V_274 < F_249 ( V_75 ) ) {
if ( V_75 -> V_274 < F_271 ( 32 ) )
V_48 |= V_316 ;
else
V_48 |= V_317 ;
}
if ( V_48 & V_318 ) {
unsigned int V_184 = V_92 >> V_11 ;
V_14 = F_292 ( V_75 , V_184 , V_315 ) ;
if ( V_14 && F_276 ( V_75 ) &&
F_202 ( V_14 ) + V_92 > V_75 -> V_274 ) {
F_293 ( V_75 , V_14 , V_184 ) ;
V_14 = NULL ;
}
}
if ( ! V_14 )
V_14 = F_294 ( V_48 , V_315 ) ;
if ( ! V_14 )
return NULL ;
memset ( F_42 ( V_14 ) , 0 , V_92 ) ;
* V_314 = F_277 ( V_75 , F_202 ( V_14 ) , V_92 ,
V_298 ,
V_75 -> V_274 ) ;
if ( * V_314 )
return F_42 ( V_14 ) ;
if ( ! F_293 ( V_75 , V_14 , V_92 >> V_11 ) )
F_295 ( V_14 , V_315 ) ;
return NULL ;
}
static void F_296 ( struct V_74 * V_75 , T_7 V_92 , void * V_39 ,
V_234 V_314 , struct V_302 * V_303 )
{
int V_315 ;
struct V_14 * V_14 = F_17 ( V_39 ) ;
V_92 = F_199 ( V_92 ) ;
V_315 = F_291 ( V_92 ) ;
F_286 ( V_75 , V_314 ) ;
if ( ! F_293 ( V_75 , V_14 , V_92 >> V_11 ) )
F_295 ( V_14 , V_315 ) ;
}
static void F_297 ( struct V_74 * V_75 , struct V_222 * V_319 ,
int V_320 , enum V_301 V_293 ,
struct V_302 * V_303 )
{
F_286 ( V_75 , V_319 [ 0 ] . V_233 ) ;
}
static int F_298 ( struct V_74 * V_321 ,
struct V_222 * V_319 , int V_320 , int V_293 )
{
int V_65 ;
struct V_222 * V_223 ;
F_299 (sglist, sg, nelems, i) {
F_62 ( ! F_203 ( V_223 ) ) ;
V_223 -> V_233 = F_202 ( F_203 ( V_223 ) ) + V_223 -> V_99 ;
V_223 -> V_235 = V_223 -> V_232 ;
}
return V_320 ;
}
static int F_300 ( struct V_74 * V_75 , struct V_222 * V_319 , int V_320 ,
enum V_301 V_293 , struct V_302 * V_303 )
{
int V_65 ;
struct V_46 * V_47 ;
T_7 V_92 = 0 ;
int V_226 = 0 ;
struct V_44 * V_44 = NULL ;
int V_70 ;
struct V_222 * V_223 ;
unsigned long V_322 ;
struct V_53 * V_54 ;
F_62 ( V_293 == V_296 ) ;
if ( F_276 ( V_75 ) )
return F_298 ( V_75 , V_319 , V_320 , V_293 ) ;
V_47 = F_274 ( V_75 ) ;
if ( ! V_47 )
return 0 ;
V_54 = F_61 ( V_47 ) ;
F_299 (sglist, sg, nelems, i)
V_92 += F_198 ( V_223 -> V_99 , V_223 -> V_232 ) ;
V_44 = F_269 ( V_75 , V_47 , F_12 ( V_92 ) ,
* V_75 -> V_273 ) ;
if ( ! V_44 ) {
V_319 -> V_235 = 0 ;
return 0 ;
}
if ( V_293 == V_297 || V_293 == V_298 || \
! F_278 ( V_54 -> V_57 ) )
V_226 |= V_105 ;
if ( V_293 == V_299 || V_293 == V_298 )
V_226 |= V_106 ;
V_322 = F_13 ( V_44 -> V_300 ) ;
V_70 = F_208 ( V_47 , V_322 , V_319 , V_92 , V_226 ) ;
if ( F_191 ( V_70 ) ) {
F_98 ( V_47 , V_322 ,
V_322 + V_92 - 1 ) ;
F_279 ( & V_47 -> V_198 , V_44 ) ;
return 0 ;
}
if ( F_145 ( V_54 -> V_57 ) )
F_140 ( V_54 , V_47 -> V_180 , V_322 , V_92 , 0 , 1 ) ;
else
F_113 ( V_54 ) ;
return V_320 ;
}
static int F_301 ( struct V_74 * V_75 , V_234 V_323 )
{
return ! V_323 ;
}
static inline int F_302 ( void )
{
int V_70 = 0 ;
V_42 = F_303 ( L_55 ,
sizeof( struct V_46 ) ,
0 ,
V_324 ,
NULL ) ;
if ( ! V_42 ) {
F_39 ( V_153 L_56 ) ;
V_70 = - V_120 ;
}
return V_70 ;
}
static inline int F_304 ( void )
{
int V_70 = 0 ;
V_43 = F_303 ( L_57 ,
sizeof( struct V_154 ) ,
0 ,
V_324 ,
NULL ) ;
if ( ! V_43 ) {
F_39 ( V_153 L_58 ) ;
V_70 = - V_120 ;
}
return V_70 ;
}
static inline int F_305 ( void )
{
int V_70 = 0 ;
V_45 = F_303 ( L_59 ,
sizeof( struct V_44 ) ,
0 ,
V_324 ,
NULL ) ;
if ( ! V_45 ) {
F_39 ( V_153 L_60 ) ;
V_70 = - V_120 ;
}
return V_70 ;
}
static int T_1 F_306 ( void )
{
int V_70 ;
V_70 = F_305 () ;
if ( V_70 )
return V_70 ;
V_70 = F_302 () ;
if ( V_70 )
goto V_325;
V_70 = F_304 () ;
if ( ! V_70 )
return V_70 ;
F_307 ( V_42 ) ;
V_325:
F_307 ( V_45 ) ;
return - V_120 ;
}
static void T_1 F_308 ( void )
{
F_307 ( V_43 ) ;
F_307 ( V_42 ) ;
F_307 ( V_45 ) ;
}
static void F_309 ( struct V_79 * V_81 )
{
struct V_63 * V_64 ;
T_5 V_326 ;
int V_327 ;
V_327 = F_310 ( V_81 -> V_76 , F_311 ( 0 , 0 ) , 0xb0 , & V_326 ) ;
if ( V_327 ) {
F_312 ( & V_81 -> V_75 , L_61 ) ;
return;
}
V_326 &= 0xffff0000 ;
V_64 = F_313 ( V_81 ) ;
if ( F_314 ( ! V_64 || V_64 -> V_328 - V_326 != 0xa000 ,
V_329 ,
L_62 ) )
V_81 -> V_75 . V_240 . V_54 = V_255 ;
}
static void T_1 F_315 ( void )
{
struct V_63 * V_64 ;
struct V_74 * V_75 ;
int V_65 ;
F_261 (drhd) {
if ( ! V_64 -> V_90 ) {
F_81 (drhd->devices,
drhd->devices_cnt, i, dev)
break;
if ( V_65 == V_64 -> V_330 )
V_64 -> V_289 = 1 ;
}
}
F_316 (drhd) {
if ( V_64 -> V_90 )
continue;
F_81 (drhd->devices,
drhd->devices_cnt, i, dev)
if ( ! F_77 ( V_75 ) || ! F_245 ( F_78 ( V_75 ) ) )
break;
if ( V_65 < V_64 -> V_330 )
continue;
if ( V_34 ) {
V_331 = 1 ;
} else {
V_64 -> V_289 = 1 ;
F_81 (drhd->devices,
drhd->devices_cnt, i, dev)
V_75 -> V_240 . V_54 = V_255 ;
}
}
}
static int F_317 ( void )
{
struct V_63 * V_64 ;
struct V_53 * V_54 = NULL ;
F_68 (iommu, drhd)
if ( V_54 -> V_156 )
F_318 ( V_54 ) ;
F_267 (iommu, drhd) {
if ( V_64 -> V_289 ) {
if ( V_290 )
F_146 ( V_54 ) ;
continue;
}
F_113 ( V_54 ) ;
F_107 ( V_54 ) ;
V_54 -> V_164 . V_208 ( V_54 , 0 , 0 , 0 ,
V_139 ) ;
V_54 -> V_164 . V_165 ( V_54 , 0 , 0 , 0 , V_148 ) ;
F_147 ( V_54 ) ;
F_146 ( V_54 ) ;
}
return 0 ;
}
static void F_319 ( void )
{
struct V_63 * V_64 ;
struct V_53 * V_54 ;
F_68 (iommu, drhd) {
V_54 -> V_164 . V_208 ( V_54 , 0 , 0 , 0 ,
V_139 ) ;
V_54 -> V_164 . V_165 ( V_54 , 0 , 0 , 0 ,
V_148 ) ;
}
}
static int F_320 ( void )
{
struct V_63 * V_64 ;
struct V_53 * V_54 = NULL ;
unsigned long V_123 ;
F_68 (iommu, drhd) {
V_54 -> V_332 = F_263 ( sizeof( T_5 ) * V_333 ,
V_40 ) ;
if ( ! V_54 -> V_332 )
goto V_334;
}
F_319 () ;
F_68 (iommu, drhd) {
F_148 ( V_54 ) ;
F_108 ( & V_54 -> V_124 , V_123 ) ;
V_54 -> V_332 [ V_335 ] =
V_131 ( V_54 -> V_125 + V_336 ) ;
V_54 -> V_332 [ V_337 ] =
V_131 ( V_54 -> V_125 + V_338 ) ;
V_54 -> V_332 [ V_339 ] =
V_131 ( V_54 -> V_125 + V_340 ) ;
V_54 -> V_332 [ V_341 ] =
V_131 ( V_54 -> V_125 + V_342 ) ;
F_112 ( & V_54 -> V_124 , V_123 ) ;
}
return 0 ;
V_334:
F_68 (iommu, drhd)
F_154 ( V_54 -> V_332 ) ;
return - V_120 ;
}
static void F_321 ( void )
{
struct V_63 * V_64 ;
struct V_53 * V_54 = NULL ;
unsigned long V_123 ;
if ( F_317 () ) {
if ( V_290 )
F_322 ( L_63 ) ;
else
F_225 ( 1 , L_64 ) ;
return;
}
F_68 (iommu, drhd) {
F_108 ( & V_54 -> V_124 , V_123 ) ;
F_110 ( V_54 -> V_332 [ V_335 ] ,
V_54 -> V_125 + V_336 ) ;
F_110 ( V_54 -> V_332 [ V_337 ] ,
V_54 -> V_125 + V_338 ) ;
F_110 ( V_54 -> V_332 [ V_339 ] ,
V_54 -> V_125 + V_340 ) ;
F_110 ( V_54 -> V_332 [ V_341 ] ,
V_54 -> V_125 + V_342 ) ;
F_112 ( & V_54 -> V_124 , V_123 ) ;
}
F_68 (iommu, drhd)
F_154 ( V_54 -> V_332 ) ;
}
static void T_1 F_323 ( void )
{
F_324 ( & V_343 ) ;
}
static inline void F_323 ( void ) {}
int T_1 F_325 ( struct V_344 * V_345 , void * V_346 )
{
struct V_347 * V_254 ;
struct V_253 * V_348 ;
V_348 = F_263 ( sizeof( * V_348 ) , V_177 ) ;
if ( ! V_348 )
return - V_120 ;
V_348 -> V_349 = V_345 ;
V_254 = (struct V_347 * ) V_345 ;
V_348 -> V_256 = V_254 -> V_256 ;
V_348 -> V_257 = V_254 -> V_257 ;
V_348 -> V_83 = F_326 ( ( void * ) ( V_254 + 1 ) ,
( ( void * ) V_254 ) + V_254 -> V_345 . V_232 ,
& V_348 -> V_330 ) ;
if ( V_348 -> V_330 && V_348 -> V_83 == NULL ) {
F_154 ( V_348 ) ;
return - V_120 ;
}
F_219 ( & V_348 -> V_350 , & V_351 ) ;
return 0 ;
}
static struct V_352 * F_327 ( struct V_353 * V_354 )
{
struct V_352 * V_355 ;
struct V_353 * V_78 ;
F_328 (atsru, &dmar_atsr_units, list) {
V_78 = (struct V_353 * ) V_355 -> V_349 ;
if ( V_354 -> V_82 != V_78 -> V_82 )
continue;
if ( V_354 -> V_345 . V_232 != V_78 -> V_345 . V_232 )
continue;
if ( memcmp ( V_354 , V_78 , V_354 -> V_345 . V_232 ) == 0 )
return V_355 ;
}
return NULL ;
}
int F_329 ( struct V_344 * V_349 , void * V_346 )
{
struct V_353 * V_354 ;
struct V_352 * V_355 ;
if ( V_356 != V_357 && ! V_358 )
return 0 ;
V_354 = F_330 ( V_349 , struct V_353 , V_345 ) ;
V_355 = F_327 ( V_354 ) ;
if ( V_355 )
return 0 ;
V_355 = F_263 ( sizeof( * V_355 ) + V_349 -> V_232 , V_177 ) ;
if ( ! V_355 )
return - V_120 ;
V_355 -> V_349 = ( void * ) ( V_355 + 1 ) ;
memcpy ( V_355 -> V_349 , V_349 , V_349 -> V_232 ) ;
V_355 -> V_90 = V_354 -> V_48 & 0x1 ;
if ( ! V_355 -> V_90 ) {
V_355 -> V_83 = F_326 ( ( void * ) ( V_354 + 1 ) ,
( void * ) V_354 + V_354 -> V_345 . V_232 ,
& V_355 -> V_330 ) ;
if ( V_355 -> V_330 && V_355 -> V_83 == NULL ) {
F_154 ( V_355 ) ;
return - V_120 ;
}
}
F_331 ( & V_355 -> V_350 , & V_359 ) ;
return 0 ;
}
static void F_332 ( struct V_352 * V_355 )
{
F_333 ( & V_355 -> V_83 , & V_355 -> V_330 ) ;
F_154 ( V_355 ) ;
}
int F_334 ( struct V_344 * V_349 , void * V_346 )
{
struct V_353 * V_354 ;
struct V_352 * V_355 ;
V_354 = F_330 ( V_349 , struct V_353 , V_345 ) ;
V_355 = F_327 ( V_354 ) ;
if ( V_355 ) {
F_335 ( & V_355 -> V_350 ) ;
F_336 () ;
F_332 ( V_355 ) ;
}
return 0 ;
}
int F_337 ( struct V_344 * V_349 , void * V_346 )
{
int V_65 ;
struct V_74 * V_75 ;
struct V_353 * V_354 ;
struct V_352 * V_355 ;
V_354 = F_330 ( V_349 , struct V_353 , V_345 ) ;
V_355 = F_327 ( V_354 ) ;
if ( ! V_355 )
return 0 ;
if ( ! V_355 -> V_90 && V_355 -> V_83 && V_355 -> V_330 )
F_81 (atsru->devices, atsru->devices_cnt,
i, dev)
return - V_264 ;
return 0 ;
}
static int F_338 ( struct V_63 * V_360 )
{
int V_361 , V_70 = 0 ;
struct V_53 * V_54 = V_360 -> V_54 ;
if ( V_62 [ V_54 -> V_175 ] )
return 0 ;
if ( V_248 && ! F_264 ( V_54 -> V_68 ) ) {
F_339 ( L_65 ,
V_54 -> V_119 ) ;
return - V_362 ;
}
if ( ! F_71 ( V_54 -> V_68 ) &&
F_70 ( V_54 ) ) {
F_339 ( L_66 ,
V_54 -> V_119 ) ;
return - V_362 ;
}
V_361 = F_72 ( V_54 ) - 1 ;
if ( V_361 >= 0 && ! ( F_73 ( V_54 -> V_57 ) & ( 1 << V_361 ) ) ) {
F_339 ( L_67 ,
V_54 -> V_119 ) ;
return - V_362 ;
}
if ( V_54 -> V_127 & V_171 )
F_148 ( V_54 ) ;
V_62 [ V_54 -> V_175 ] = V_54 ;
V_70 = F_149 ( V_54 ) ;
if ( V_70 == 0 )
V_70 = F_105 ( V_54 ) ;
if ( V_70 )
goto V_84;
if ( V_360 -> V_289 ) {
if ( V_290 )
F_146 ( V_54 ) ;
return 0 ;
}
F_256 ( V_54 ) ;
F_113 ( V_54 ) ;
V_70 = F_268 ( V_54 ) ;
if ( V_70 )
goto V_363;
F_107 ( V_54 ) ;
V_54 -> V_164 . V_208 ( V_54 , 0 , 0 , 0 , V_139 ) ;
V_54 -> V_164 . V_165 ( V_54 , 0 , 0 , 0 , V_148 ) ;
F_147 ( V_54 ) ;
if ( V_247 ) {
V_70 = F_167 ( V_247 , V_54 ) ;
if ( V_70 < 0 || V_247 -> V_180 != V_70 )
goto V_363;
F_170 ( V_247 , V_54 ) ;
}
F_146 ( V_54 ) ;
return 0 ;
V_363:
F_156 ( V_54 ) ;
V_84:
F_160 ( V_54 ) ;
return V_70 ;
}
int F_340 ( struct V_63 * V_360 , bool V_364 )
{
int V_70 = 0 ;
struct V_53 * V_54 = V_360 -> V_54 ;
if ( ! V_358 )
return 0 ;
if ( V_54 == NULL )
return - V_31 ;
if ( V_364 ) {
V_70 = F_338 ( V_360 ) ;
} else {
F_156 ( V_54 ) ;
F_160 ( V_54 ) ;
}
return V_70 ;
}
static void F_341 ( void )
{
struct V_253 * V_348 , * V_365 ;
struct V_352 * V_355 , * V_366 ;
F_214 (rmrru, rmrr_n, &dmar_rmrr_units, list) {
F_213 ( & V_348 -> V_350 ) ;
F_333 ( & V_348 -> V_83 , & V_348 -> V_330 ) ;
F_154 ( V_348 ) ;
}
F_214 (atsru, atsr_n, &dmar_atsr_units, list) {
F_213 ( & V_355 -> V_350 ) ;
F_332 ( V_355 ) ;
}
}
int F_131 ( struct V_79 * V_75 )
{
int V_65 , V_70 = 1 ;
struct V_367 * V_76 ;
struct V_79 * V_368 = NULL ;
struct V_74 * V_78 ;
struct V_353 * V_354 ;
struct V_352 * V_355 ;
V_75 = F_342 ( V_75 ) ;
for ( V_76 = V_75 -> V_76 ; V_76 ; V_76 = V_76 -> V_98 ) {
V_368 = V_76 -> V_369 ;
if ( ! V_368 || ! F_246 ( V_368 ) ||
F_248 ( V_368 ) == V_272 )
return 0 ;
if ( F_248 ( V_368 ) == V_370 )
break;
}
if ( ! V_368 )
return 0 ;
F_67 () ;
F_328 (atsru, &dmar_atsr_units, list) {
V_354 = F_330 ( V_355 -> V_349 , struct V_353 , V_345 ) ;
if ( V_354 -> V_82 != F_79 ( V_75 -> V_76 ) )
continue;
F_343 (atsru->devices, atsru->devices_cnt, i, tmp)
if ( V_78 == & V_368 -> V_75 )
goto V_84;
if ( V_355 -> V_90 )
goto V_84;
}
V_70 = 0 ;
V_84:
F_69 () ;
return V_70 ;
}
int F_344 ( struct V_371 * V_155 )
{
int V_70 = 0 ;
struct V_253 * V_348 ;
struct V_352 * V_355 ;
struct V_353 * V_354 ;
struct V_347 * V_254 ;
if ( ! V_358 && V_356 != V_357 )
return 0 ;
F_129 (rmrru, &dmar_rmrr_units, list) {
V_254 = F_330 ( V_348 -> V_349 ,
struct V_347 , V_345 ) ;
if ( V_155 -> V_372 == V_373 ) {
V_70 = F_345 ( V_155 , ( void * ) ( V_254 + 1 ) ,
( ( void * ) V_254 ) + V_254 -> V_345 . V_232 ,
V_254 -> V_82 , V_348 -> V_83 ,
V_348 -> V_330 ) ;
if( V_70 < 0 )
return V_70 ;
} else if ( V_155 -> V_372 == V_374 ) {
F_346 ( V_155 , V_254 -> V_82 ,
V_348 -> V_83 , V_348 -> V_330 ) ;
}
}
F_129 (atsru, &dmar_atsr_units, list) {
if ( V_355 -> V_90 )
continue;
V_354 = F_330 ( V_355 -> V_349 , struct V_353 , V_345 ) ;
if ( V_155 -> V_372 == V_373 ) {
V_70 = F_345 ( V_155 , ( void * ) ( V_354 + 1 ) ,
( void * ) V_354 + V_354 -> V_345 . V_232 ,
V_354 -> V_82 , V_355 -> V_83 ,
V_355 -> V_330 ) ;
if ( V_70 > 0 )
break;
else if( V_70 < 0 )
return V_70 ;
} else if ( V_155 -> V_372 == V_374 ) {
if ( F_346 ( V_155 , V_354 -> V_82 ,
V_355 -> V_83 , V_355 -> V_330 ) )
break;
}
}
return 0 ;
}
static int F_347 ( struct V_375 * V_376 ,
unsigned long V_377 , void * V_213 )
{
struct V_74 * V_75 = V_213 ;
struct V_46 * V_47 ;
if ( F_275 ( V_75 ) )
return 0 ;
if ( V_377 != V_378 )
return 0 ;
V_47 = F_216 ( V_75 ) ;
if ( ! V_47 )
return 0 ;
F_348 ( & V_379 ) ;
F_239 ( V_47 , V_75 ) ;
if ( ! F_54 ( V_47 ) && F_349 ( & V_47 -> V_83 ) )
F_159 ( V_47 ) ;
F_350 ( & V_379 ) ;
return 0 ;
}
static int F_351 ( struct V_375 * V_376 ,
unsigned long V_19 , void * V_380 )
{
struct V_381 * V_382 = V_380 ;
unsigned long long V_197 , V_88 ;
unsigned long V_322 , V_246 ;
switch ( V_19 ) {
case V_383 :
V_197 = V_382 -> V_109 << V_11 ;
V_88 = ( ( V_382 -> V_109 + V_382 -> V_225 ) << V_11 ) - 1 ;
if ( F_222 ( V_247 , V_197 , V_88 ) ) {
F_339 ( L_68 ,
V_197 , V_88 ) ;
return V_384 ;
}
break;
case V_385 :
case V_386 :
V_322 = F_13 ( V_382 -> V_109 ) ;
V_246 = F_13 ( V_382 -> V_109 + V_382 -> V_225 - 1 ) ;
while ( V_322 <= V_246 ) {
struct V_44 * V_44 ;
struct V_63 * V_64 ;
struct V_53 * V_54 ;
struct V_14 * V_116 ;
V_44 = F_287 ( & V_247 -> V_198 , V_322 ) ;
if ( V_44 == NULL ) {
F_126 ( L_69 ,
V_322 ) ;
break;
}
V_44 = F_352 ( & V_247 -> V_198 , V_44 ,
V_322 , V_246 ) ;
if ( V_44 == NULL ) {
F_339 ( L_70 ,
V_322 , V_246 ) ;
return V_384 ;
}
V_116 = F_103 ( V_247 , V_44 -> V_300 ,
V_44 -> V_313 ) ;
F_67 () ;
F_68 (iommu, drhd)
F_140 ( V_54 , V_247 -> V_180 ,
V_44 -> V_300 , F_282 ( V_44 ) ,
! V_116 , 0 ) ;
F_69 () ;
F_104 ( V_116 ) ;
V_322 = V_44 -> V_313 + 1 ;
F_52 ( V_44 ) ;
}
break;
}
return V_387 ;
}
static T_10 F_353 ( struct V_74 * V_75 ,
struct V_388 * V_389 ,
char * V_390 )
{
struct V_53 * V_54 = F_354 ( V_75 ) ;
T_5 V_391 = V_131 ( V_54 -> V_125 + V_392 ) ;
return sprintf ( V_390 , L_71 ,
F_355 ( V_391 ) , F_356 ( V_391 ) ) ;
}
static T_10 F_357 ( struct V_74 * V_75 ,
struct V_388 * V_389 ,
char * V_390 )
{
struct V_53 * V_54 = F_354 ( V_75 ) ;
return sprintf ( V_390 , L_72 , V_54 -> V_393 ) ;
}
static T_10 F_358 ( struct V_74 * V_75 ,
struct V_388 * V_389 ,
char * V_390 )
{
struct V_53 * V_54 = F_354 ( V_75 ) ;
return sprintf ( V_390 , L_72 , V_54 -> V_57 ) ;
}
static T_10 F_359 ( struct V_74 * V_75 ,
struct V_388 * V_389 ,
char * V_390 )
{
struct V_53 * V_54 = F_354 ( V_75 ) ;
return sprintf ( V_390 , L_72 , V_54 -> V_68 ) ;
}
int T_1 F_360 ( void )
{
int V_70 = - V_192 ;
struct V_63 * V_64 ;
struct V_53 * V_54 ;
V_290 = F_361 () ;
if ( F_306 () ) {
if ( V_290 )
F_322 ( L_73 ) ;
return - V_120 ;
}
F_362 ( & V_379 ) ;
if ( F_363 () ) {
if ( V_290 )
F_322 ( L_74 ) ;
goto V_394;
}
F_68 (iommu, drhd)
if ( V_54 -> V_127 & V_171 )
F_148 ( V_54 ) ;
if ( F_364 () < 0 ) {
if ( V_290 )
F_322 ( L_75 ) ;
goto V_394;
}
if ( V_395 || V_32 )
goto V_394;
if ( F_349 ( & V_351 ) )
F_39 ( V_33 L_76 ) ;
if ( F_349 ( & V_359 ) )
F_39 ( V_33 L_77 ) ;
if ( F_173 () ) {
if ( V_290 )
F_322 ( L_78 ) ;
goto V_396;
}
F_315 () ;
V_70 = F_260 () ;
if ( V_70 ) {
if ( V_290 )
F_322 ( L_79 ) ;
F_39 ( V_153 L_80 ) ;
goto V_396;
}
F_365 ( & V_379 ) ;
F_39 ( V_33
L_81 ) ;
F_366 ( & V_310 ) ;
#ifdef F_367
V_397 = 0 ;
#endif
V_398 = & V_399 ;
F_323 () ;
F_68 (iommu, drhd)
V_54 -> V_400 = F_368 ( NULL , V_54 ,
V_401 ,
V_54 -> V_119 ) ;
F_369 ( & V_402 , & V_403 ) ;
F_370 ( & V_402 , & V_404 ) ;
if ( V_247 && ! V_248 )
F_371 ( & V_405 ) ;
V_358 = 1 ;
return 0 ;
V_396:
F_187 ( & V_186 ) ;
V_394:
F_341 () ;
F_365 ( & V_379 ) ;
F_308 () ;
return V_70 ;
}
static int F_372 ( struct V_79 * V_81 , T_3 V_210 , void * V_211 )
{
struct V_53 * V_54 = V_211 ;
F_210 ( V_54 , F_193 ( V_210 ) , V_210 & 0xff ) ;
return 0 ;
}
static void F_215 ( struct V_53 * V_54 ,
struct V_74 * V_75 )
{
if ( ! V_54 || ! V_75 || ! F_77 ( V_75 ) )
return;
F_195 ( F_78 ( V_75 ) , & F_372 , V_54 ) ;
}
static void F_239 ( struct V_46 * V_47 ,
struct V_74 * V_75 )
{
struct V_154 * V_155 , * V_78 ;
struct V_53 * V_54 ;
unsigned long V_48 ;
int V_66 = 0 ;
T_2 V_76 , V_77 ;
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return;
F_85 ( & V_157 , V_48 ) ;
F_214 (info, tmp, &domain->devices, link) {
if ( V_155 -> V_54 == V_54 && V_155 -> V_76 == V_76 &&
V_155 -> V_77 == V_77 ) {
F_211 ( V_155 ) ;
F_86 ( & V_157 , V_48 ) ;
F_134 ( V_155 ) ;
F_210 ( V_54 , V_155 -> V_76 , V_155 -> V_77 ) ;
F_215 ( V_54 , V_75 ) ;
F_50 ( V_155 ) ;
F_85 ( & V_157 , V_48 ) ;
if ( V_66 )
break;
else
continue;
}
if ( V_155 -> V_54 == V_54 )
V_66 = 1 ;
}
F_86 ( & V_157 , V_48 ) ;
if ( V_66 == 0 ) {
F_158 ( V_47 , V_54 ) ;
if ( ! F_54 ( V_47 ) )
F_169 ( V_47 , V_54 ) ;
}
}
static int F_232 ( struct V_46 * V_47 , int V_199 )
{
int V_200 ;
F_174 ( & V_47 -> V_198 , V_187 ) ;
F_179 ( V_47 ) ;
V_47 -> V_115 = V_199 ;
V_200 = F_181 ( V_199 ) ;
V_47 -> V_1 = F_4 ( V_200 ) ;
V_47 -> V_67 = 0 ;
V_47 -> V_72 = 0 ;
V_47 -> V_73 = 0 ;
V_47 -> V_406 = 0 ;
V_47 -> V_100 = (struct V_27 * ) F_40 ( V_47 -> V_103 ) ;
if ( ! V_47 -> V_100 )
return - V_120 ;
F_82 ( V_47 , V_47 -> V_100 , V_201 ) ;
return 0 ;
}
static int F_373 ( struct V_407 * V_47 )
{
struct V_46 * V_46 ;
V_46 = F_161 ( V_49 ) ;
if ( ! V_46 ) {
F_39 ( V_153
L_82 ) ;
return - V_120 ;
}
if ( F_232 ( V_46 , V_58 ) ) {
F_39 ( V_153
L_83 ) ;
F_159 ( V_46 ) ;
return - V_120 ;
}
F_75 ( V_46 ) ;
V_47 -> V_408 = V_46 ;
V_47 -> V_409 . V_410 = 0 ;
V_47 -> V_409 . V_411 = F_374 ( V_46 -> V_115 ) ;
V_47 -> V_409 . V_412 = true ;
return 0 ;
}
static void F_375 ( struct V_407 * V_47 )
{
struct V_46 * V_46 = V_47 -> V_408 ;
V_47 -> V_408 = NULL ;
F_159 ( V_46 ) ;
}
static int F_376 ( struct V_407 * V_47 ,
struct V_74 * V_75 )
{
struct V_46 * V_46 = V_47 -> V_408 ;
struct V_53 * V_54 ;
int V_51 ;
T_2 V_76 , V_77 ;
if ( F_242 ( V_75 ) ) {
F_377 ( V_75 , L_84 ) ;
return - V_413 ;
}
if ( F_191 ( F_197 ( V_75 ) ) ) {
struct V_46 * V_414 ;
V_414 = F_216 ( V_75 ) ;
if ( V_414 ) {
if ( F_54 ( V_46 ) )
F_239 ( V_414 , V_75 ) ;
else
F_186 ( V_414 ) ;
if ( ! F_54 ( V_414 ) &&
F_349 ( & V_414 -> V_83 ) )
F_159 ( V_414 ) ;
}
}
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return - V_192 ;
V_51 = F_2 ( V_54 -> V_1 ) ;
if ( V_51 > F_183 ( V_54 -> V_57 ) )
V_51 = F_183 ( V_54 -> V_57 ) ;
if ( V_46 -> V_406 > ( 1LL << V_51 ) ) {
F_39 ( V_153 L_85
L_86 ,
V_415 , V_51 , V_46 -> V_406 ) ;
return - V_205 ;
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
return F_238 ( V_46 , V_75 , V_204 ) ;
}
static void F_378 ( struct V_407 * V_47 ,
struct V_74 * V_75 )
{
struct V_46 * V_46 = V_47 -> V_408 ;
F_239 ( V_46 , V_75 ) ;
}
static int F_379 ( struct V_407 * V_47 ,
unsigned long V_44 , T_8 V_416 ,
T_7 V_92 , int V_417 )
{
struct V_46 * V_46 = V_47 -> V_408 ;
V_25 V_406 ;
int V_226 = 0 ;
int V_70 ;
if ( V_417 & V_418 )
V_226 |= V_105 ;
if ( V_417 & V_419 )
V_226 |= V_106 ;
if ( ( V_417 & V_420 ) && V_46 -> V_72 )
V_226 |= V_231 ;
V_406 = V_44 + V_92 ;
if ( V_46 -> V_406 < V_406 ) {
V_25 V_88 ;
V_88 = F_374 ( V_46 -> V_115 ) + 1 ;
if ( V_88 < V_406 ) {
F_39 ( V_153 L_85
L_86 ,
V_415 , V_46 -> V_115 , V_406 ) ;
return - V_205 ;
}
V_46 -> V_406 = V_406 ;
}
V_92 = F_198 ( V_416 , V_92 ) ;
V_70 = F_209 ( V_46 , V_44 >> V_12 ,
V_416 >> V_12 , V_92 , V_226 ) ;
return V_70 ;
}
static T_7 F_380 ( struct V_407 * V_47 ,
unsigned long V_44 , T_7 V_92 )
{
struct V_46 * V_46 = V_47 -> V_408 ;
struct V_14 * V_116 = NULL ;
struct V_53 * V_54 ;
unsigned long V_109 , V_110 ;
unsigned int V_421 ;
int V_59 , V_181 , V_173 , V_5 = 0 ;
if ( ! F_92 ( V_46 , V_44 >> V_12 , & V_5 ) )
F_119 () ;
if ( V_92 < V_104 << F_6 ( V_5 ) )
V_92 = V_104 << F_6 ( V_5 ) ;
V_109 = V_44 >> V_12 ;
V_110 = ( V_44 + V_92 - 1 ) >> V_12 ;
V_116 = F_103 ( V_46 , V_109 , V_110 ) ;
V_421 = V_110 - V_109 + 1 ;
F_65 (iommu_id, dmar_domain->iommu_bmp, g_num_of_iommus) {
V_54 = V_62 [ V_59 ] ;
V_173 = F_150 ( V_54 -> V_57 ) ;
F_65 (num, iommu->domain_ids, ndomains) {
if ( V_54 -> V_166 [ V_181 ] == V_46 )
F_140 ( V_54 , V_181 , V_109 ,
V_421 , ! V_116 , 0 ) ;
}
}
F_104 ( V_116 ) ;
if ( V_46 -> V_406 == V_44 + V_92 )
V_46 -> V_406 = V_44 ;
return V_92 ;
}
static T_8 F_381 ( struct V_407 * V_47 ,
V_234 V_44 )
{
struct V_46 * V_46 = V_47 -> V_408 ;
struct V_27 * V_28 ;
int V_5 = 0 ;
V_25 V_422 = 0 ;
V_28 = F_92 ( V_46 , V_44 >> V_12 , & V_5 ) ;
if ( V_28 )
V_422 = F_32 ( V_28 ) ;
return V_422 ;
}
static bool F_382 ( enum V_423 V_57 )
{
if ( V_57 == V_424 )
return F_70 ( NULL ) == 1 ;
if ( V_57 == V_425 )
return V_426 == 1 ;
return false ;
}
static int F_383 ( struct V_74 * V_75 )
{
struct V_53 * V_54 ;
struct V_427 * V_428 ;
T_2 V_76 , V_77 ;
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return - V_192 ;
F_384 ( V_54 -> V_400 , V_75 ) ;
V_428 = F_385 ( V_75 ) ;
if ( F_386 ( V_428 ) )
return F_387 ( V_428 ) ;
F_388 ( V_428 ) ;
return 0 ;
}
static void F_389 ( struct V_74 * V_75 )
{
struct V_53 * V_54 ;
T_2 V_76 , V_77 ;
V_54 = F_76 ( V_75 , & V_76 , & V_77 ) ;
if ( ! V_54 )
return;
F_390 ( V_75 ) ;
F_391 ( V_54 -> V_400 , V_75 ) ;
}
static void F_392 ( struct V_79 * V_75 )
{
F_39 ( V_33 L_87 ) ;
V_34 = 0 ;
}
static void F_393 ( struct V_79 * V_75 )
{
F_39 ( V_33 L_88 ) ;
V_133 = 1 ;
}
static void F_394 ( struct V_79 * V_75 )
{
unsigned short V_429 ;
if ( F_395 ( V_75 , V_430 , & V_429 ) )
return;
if ( ! ( V_429 & V_431 ) ) {
F_39 ( V_33 L_89 ) ;
V_34 = 0 ;
} else if ( V_34 ) {
F_39 ( V_33 L_90 ) ;
V_36 = 1 ;
}
}
static void T_1 F_266 ( void )
{
struct V_79 * V_81 ;
T_11 V_432 ;
V_81 = F_396 ( V_433 , 0x3a3e , NULL ) ;
if ( ! V_81 )
return;
F_230 ( V_81 ) ;
V_81 = F_396 ( V_433 , 0x342e , NULL ) ;
if ( ! V_81 )
return;
if ( F_397 ( V_81 , 0x188 , & V_432 ) ) {
F_230 ( V_81 ) ;
return;
}
F_230 ( V_81 ) ;
if ( V_432 & 1 )
return;
V_432 &= 0x1c ;
if ( V_432 == 0x10 )
return;
if ( ! V_432 ) {
F_225 ( 1 , L_91
L_31 ,
F_226 ( V_249 ) ,
F_226 ( V_250 ) ,
F_226 ( V_251 ) ) ;
V_262 |= V_268 ;
return;
}
F_39 ( V_434 L_92 ,
V_432 ) ;
}
