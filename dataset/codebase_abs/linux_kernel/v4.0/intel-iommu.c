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
static inline int F_51 ( struct V_44 * V_45 )
{
return V_45 -> V_46 & V_47 ;
}
static inline int F_52 ( struct V_44 * V_45 )
{
return V_45 -> V_46 & ( V_47 |
V_48 ) ;
}
static inline int F_53 ( struct V_44 * V_45 ,
unsigned long V_6 )
{
int V_49 = F_2 ( V_45 -> V_1 ) - V_12 ;
return ! ( V_49 < V_50 && V_6 > > V_49 ) ;
}
static int F_54 ( struct V_51 * V_52 , int V_53 )
{
unsigned long V_54 ;
int V_1 = - 1 ;
V_54 = F_55 ( V_52 -> V_55 ) ;
for ( V_1 = F_4 ( V_53 ) ;
V_1 >= 0 ; V_1 -- ) {
if ( F_56 ( V_1 , & V_54 ) )
break;
}
return V_1 ;
}
int F_57 ( struct V_51 * V_52 )
{
return F_54 ( V_52 , V_3 ) ;
}
int F_58 ( struct V_51 * V_52 )
{
return F_54 ( V_52 , V_56 ) ;
}
static struct V_51 * F_59 ( struct V_44 * V_45 )
{
int V_57 ;
F_60 ( F_52 ( V_45 ) ) ;
V_57 = F_61 ( V_45 -> V_58 , V_59 ) ;
if ( V_57 < 0 || V_57 >= V_59 )
return NULL ;
return V_60 [ V_57 ] ;
}
static void F_62 ( struct V_44 * V_45 )
{
struct V_61 * V_62 ;
struct V_51 * V_52 ;
int V_63 , V_64 = 0 ;
V_45 -> V_65 = 1 ;
F_63 (i, domain->iommu_bmp, g_num_of_iommus) {
V_64 = 1 ;
if ( ! F_64 ( V_60 [ V_63 ] -> V_66 ) ) {
V_45 -> V_65 = 0 ;
break;
}
}
if ( V_64 )
return;
F_65 () ;
F_66 (iommu, drhd) {
if ( ! F_64 ( V_52 -> V_66 ) ) {
V_45 -> V_65 = 0 ;
break;
}
}
F_67 () ;
}
static int F_68 ( struct V_51 * V_67 )
{
struct V_61 * V_62 ;
struct V_51 * V_52 ;
int V_68 = 1 ;
F_65 () ;
F_66 (iommu, drhd) {
if ( V_52 != V_67 ) {
if ( ! F_69 ( V_52 -> V_66 ) ) {
V_68 = 0 ;
break;
}
}
}
F_67 () ;
return V_68 ;
}
static int F_70 ( struct V_51 * V_67 )
{
struct V_61 * V_62 ;
struct V_51 * V_52 ;
int V_69 = 0xf ;
if ( ! V_37 ) {
return 0 ;
}
F_65 () ;
F_66 (iommu, drhd) {
if ( V_52 != V_67 ) {
V_69 &= F_71 ( V_52 -> V_55 ) ;
if ( ! V_69 )
break;
}
}
F_67 () ;
return F_72 ( V_69 ) ;
}
static void F_73 ( struct V_44 * V_45 )
{
F_62 ( V_45 ) ;
V_45 -> V_70 = F_68 ( NULL ) ;
V_45 -> V_71 = F_70 ( NULL ) ;
}
static struct V_51 * F_74 ( struct V_72 * V_73 , T_2 * V_74 , T_2 * V_75 )
{
struct V_61 * V_62 = NULL ;
struct V_51 * V_52 ;
struct V_72 * V_76 ;
struct V_77 * V_78 , * V_79 = NULL ;
T_3 V_80 = 0 ;
int V_63 ;
if ( F_75 ( V_73 ) ) {
V_79 = F_76 ( V_73 ) ;
V_80 = F_77 ( V_79 -> V_74 ) ;
} else if ( F_78 ( V_73 ) )
V_73 = & F_78 ( V_73 ) -> V_73 ;
F_65 () ;
F_66 (iommu, drhd) {
if ( V_79 && V_80 != V_62 -> V_80 )
continue;
F_79 (drhd->devices,
drhd->devices_cnt, i, tmp) {
if ( V_76 == V_73 ) {
* V_74 = V_62 -> V_81 [ V_63 ] . V_74 ;
* V_75 = V_62 -> V_81 [ V_63 ] . V_75 ;
goto V_82;
}
if ( ! V_79 || ! F_75 ( V_76 ) )
continue;
V_78 = F_76 ( V_76 ) ;
if ( V_78 -> V_83 &&
V_78 -> V_83 -> V_84 <= V_79 -> V_74 -> V_84 &&
V_78 -> V_83 -> V_85 . V_86 >= V_79 -> V_74 -> V_84 )
goto V_87;
}
if ( V_79 && V_62 -> V_88 ) {
V_87:
* V_74 = V_79 -> V_74 -> V_84 ;
* V_75 = V_79 -> V_75 ;
goto V_82;
}
}
V_52 = NULL ;
V_82:
F_67 () ;
return V_52 ;
}
static void F_80 ( struct V_44 * V_45 ,
void * V_89 , int V_90 )
{
if ( ! V_45 -> V_65 )
F_81 ( V_89 , V_90 ) ;
}
static struct V_22 * F_82 ( struct V_51 * V_52 ,
T_2 V_74 , T_2 V_75 )
{
struct V_17 * V_18 ;
struct V_22 * V_23 ;
unsigned long V_91 ;
unsigned long V_46 ;
F_83 ( & V_52 -> V_92 , V_46 ) ;
V_18 = & V_52 -> V_17 [ V_74 ] ;
V_23 = F_21 ( V_18 ) ;
if ( ! V_23 ) {
V_23 = (struct V_22 * )
F_40 ( V_52 -> V_38 ) ;
if ( ! V_23 ) {
F_84 ( & V_52 -> V_92 , V_46 ) ;
return NULL ;
}
F_85 ( V_52 , ( void * ) V_23 , V_93 ) ;
V_91 = F_86 ( ( void * ) V_23 ) ;
F_20 ( V_18 , V_91 ) ;
F_19 ( V_18 ) ;
F_85 ( V_52 , V_18 , sizeof( * V_18 ) ) ;
}
F_84 ( & V_52 -> V_92 , V_46 ) ;
return & V_23 [ V_75 ] ;
}
static int F_87 ( struct V_51 * V_52 , T_2 V_74 , T_2 V_75 )
{
struct V_17 * V_18 ;
struct V_22 * V_23 ;
int V_68 ;
unsigned long V_46 ;
F_83 ( & V_52 -> V_92 , V_46 ) ;
V_18 = & V_52 -> V_17 [ V_74 ] ;
V_23 = F_21 ( V_18 ) ;
if ( ! V_23 ) {
V_68 = 0 ;
goto V_82;
}
V_68 = F_23 ( & V_23 [ V_75 ] ) ;
V_82:
F_84 ( & V_52 -> V_92 , V_46 ) ;
return V_68 ;
}
static void F_88 ( struct V_51 * V_52 , T_2 V_74 , T_2 V_75 )
{
struct V_17 * V_18 ;
struct V_22 * V_23 ;
unsigned long V_46 ;
F_83 ( & V_52 -> V_92 , V_46 ) ;
V_18 = & V_52 -> V_17 [ V_74 ] ;
V_23 = F_21 ( V_18 ) ;
if ( V_23 ) {
F_30 ( & V_23 [ V_75 ] ) ;
F_85 ( V_52 , & V_23 [ V_75 ] , \
sizeof( * V_23 ) ) ;
}
F_84 ( & V_52 -> V_92 , V_46 ) ;
}
static void F_89 ( struct V_51 * V_52 )
{
struct V_17 * V_18 ;
int V_63 ;
unsigned long V_46 ;
struct V_22 * V_23 ;
F_83 ( & V_52 -> V_92 , V_46 ) ;
if ( ! V_52 -> V_17 ) {
goto V_82;
}
for ( V_63 = 0 ; V_63 < V_94 ; V_63 ++ ) {
V_18 = & V_52 -> V_17 [ V_63 ] ;
V_23 = F_21 ( V_18 ) ;
if ( V_23 )
F_43 ( V_23 ) ;
}
F_43 ( V_52 -> V_17 ) ;
V_52 -> V_17 = NULL ;
V_82:
F_84 ( & V_52 -> V_92 , V_46 ) ;
}
static struct V_27 * F_90 ( struct V_44 * V_45 ,
unsigned long V_6 , int * V_95 )
{
struct V_27 * V_96 , * V_28 = NULL ;
int V_5 = F_1 ( V_45 -> V_1 ) ;
int V_97 ;
F_60 ( ! V_45 -> V_98 ) ;
if ( ! F_53 ( V_45 , V_6 ) )
return NULL ;
V_96 = V_45 -> V_98 ;
while ( 1 ) {
void * V_99 ;
V_97 = F_7 ( V_6 , V_5 ) ;
V_28 = & V_96 [ V_97 ] ;
if ( ! * V_95 && ( F_36 ( V_28 ) || ! F_35 ( V_28 ) ) )
break;
if ( V_5 == * V_95 )
break;
if ( ! F_35 ( V_28 ) ) {
T_4 V_100 ;
V_99 = F_40 ( V_45 -> V_101 ) ;
if ( ! V_99 )
return NULL ;
F_80 ( V_45 , V_99 , V_102 ) ;
V_100 = ( ( T_4 ) F_16 ( V_99 ) << V_12 ) | V_103 | V_104 ;
if ( F_91 ( & V_28 -> V_19 , 0ULL , V_100 ) )
F_43 ( V_99 ) ;
else
F_80 ( V_45 , V_28 , sizeof( * V_28 ) ) ;
}
if ( V_5 == 1 )
break;
V_96 = F_22 ( F_32 ( V_28 ) ) ;
V_5 -- ;
}
if ( ! * V_95 )
* V_95 = V_5 ;
return V_28 ;
}
static struct V_27 * F_92 ( struct V_44 * V_45 ,
unsigned long V_6 ,
int V_5 , int * V_105 )
{
struct V_27 * V_96 , * V_28 = NULL ;
int V_106 = F_1 ( V_45 -> V_1 ) ;
int V_97 ;
V_96 = V_45 -> V_98 ;
while ( V_5 <= V_106 ) {
V_97 = F_7 ( V_6 , V_106 ) ;
V_28 = & V_96 [ V_97 ] ;
if ( V_5 == V_106 )
return V_28 ;
if ( ! F_35 ( V_28 ) ) {
* V_105 = V_106 ;
break;
}
if ( F_36 ( V_28 ) ) {
* V_105 = V_106 ;
return V_28 ;
}
V_96 = F_22 ( F_32 ( V_28 ) ) ;
V_106 -- ;
}
return NULL ;
}
static void F_93 ( struct V_44 * V_45 ,
unsigned long V_107 ,
unsigned long V_108 )
{
unsigned int V_105 = 1 ;
struct V_27 * V_109 , * V_28 ;
F_60 ( ! F_53 ( V_45 , V_107 ) ) ;
F_60 ( ! F_53 ( V_45 , V_108 ) ) ;
F_60 ( V_107 > V_108 ) ;
do {
V_105 = 1 ;
V_109 = V_28 = F_92 ( V_45 , V_107 , 1 , & V_105 ) ;
if ( ! V_28 ) {
V_107 = F_10 ( V_107 + 1 , V_105 + 1 ) ;
continue;
}
do {
F_31 ( V_28 ) ;
V_107 += F_11 ( V_105 ) ;
V_28 ++ ;
} while ( V_107 <= V_108 && ! F_37 ( V_28 ) );
F_80 ( V_45 , V_109 ,
( void * ) V_28 - ( void * ) V_109 ) ;
} while ( V_107 && V_107 <= V_108 );
}
static void F_94 ( struct V_44 * V_45 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_107 , unsigned long V_108 )
{
V_6 = F_95 ( V_107 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_110 ;
struct V_27 * V_111 ;
if ( ! F_35 ( V_28 ) || F_36 ( V_28 ) )
goto V_112;
V_110 = V_6 & F_8 ( V_5 - 1 ) ;
V_111 = F_22 ( F_32 ( V_28 ) ) ;
if ( V_5 > 2 )
F_94 ( V_45 , V_5 - 1 , V_111 ,
V_110 , V_107 , V_108 ) ;
if ( ! ( V_107 > V_110 ||
V_108 < V_110 + F_9 ( V_5 ) - 1 ) ) {
F_31 ( V_28 ) ;
F_80 ( V_45 , V_28 , sizeof( * V_28 ) ) ;
F_43 ( V_111 ) ;
}
V_112:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_37 ( ++ V_28 ) && V_6 <= V_108 );
}
static void F_96 ( struct V_44 * V_45 ,
unsigned long V_107 ,
unsigned long V_108 )
{
F_60 ( ! F_53 ( V_45 , V_107 ) ) ;
F_60 ( ! F_53 ( V_45 , V_108 ) ) ;
F_60 ( V_107 > V_108 ) ;
F_93 ( V_45 , V_107 , V_108 ) ;
F_94 ( V_45 , F_1 ( V_45 -> V_1 ) ,
V_45 -> V_98 , 0 , V_107 , V_108 ) ;
if ( V_107 == 0 && V_108 == F_97 ( V_45 -> V_113 ) ) {
F_43 ( V_45 -> V_98 ) ;
V_45 -> V_98 = NULL ;
}
}
static struct V_14 * F_98 ( struct V_44 * V_45 ,
int V_5 , struct V_27 * V_28 ,
struct V_14 * V_114 )
{
struct V_14 * V_15 ;
V_15 = F_99 ( F_32 ( V_28 ) >> V_11 ) ;
V_15 -> V_114 = V_114 ;
V_114 = V_15 ;
if ( V_5 == 1 )
return V_114 ;
V_28 = F_42 ( V_15 ) ;
do {
if ( F_35 ( V_28 ) && ! F_36 ( V_28 ) )
V_114 = F_98 ( V_45 , V_5 - 1 ,
V_28 , V_114 ) ;
V_28 ++ ;
} while ( ! F_37 ( V_28 ) );
return V_114 ;
}
static struct V_14 * F_100 ( struct V_44 * V_45 , int V_5 ,
struct V_27 * V_28 , unsigned long V_6 ,
unsigned long V_107 ,
unsigned long V_108 ,
struct V_14 * V_114 )
{
struct V_27 * V_109 = NULL , * V_115 = NULL ;
V_6 = F_95 ( V_107 , V_6 ) ;
V_28 = & V_28 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_110 ;
if ( ! F_35 ( V_28 ) )
goto V_112;
V_110 = V_6 & F_8 ( V_5 ) ;
if ( V_107 <= V_110 &&
V_108 >= V_110 + F_9 ( V_5 ) - 1 ) {
if ( V_5 > 1 && ! F_36 ( V_28 ) )
V_114 = F_98 ( V_45 , V_5 - 1 , V_28 , V_114 ) ;
F_31 ( V_28 ) ;
if ( ! V_109 )
V_109 = V_28 ;
V_115 = V_28 ;
} else if ( V_5 > 1 ) {
V_114 = F_100 ( V_45 , V_5 - 1 ,
F_22 ( F_32 ( V_28 ) ) ,
V_110 , V_107 , V_108 ,
V_114 ) ;
}
V_112:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_37 ( ++ V_28 ) && V_6 <= V_108 );
if ( V_109 )
F_80 ( V_45 , V_109 ,
( void * ) ++ V_115 - ( void * ) V_109 ) ;
return V_114 ;
}
struct V_14 * F_101 ( struct V_44 * V_45 ,
unsigned long V_107 ,
unsigned long V_108 )
{
struct V_14 * V_114 = NULL ;
F_60 ( ! F_53 ( V_45 , V_107 ) ) ;
F_60 ( ! F_53 ( V_45 , V_108 ) ) ;
F_60 ( V_107 > V_108 ) ;
V_114 = F_100 ( V_45 , F_1 ( V_45 -> V_1 ) ,
V_45 -> V_98 , 0 , V_107 , V_108 , NULL ) ;
if ( V_107 == 0 && V_108 == F_97 ( V_45 -> V_113 ) ) {
struct V_14 * V_116 = F_17 ( V_45 -> V_98 ) ;
V_116 -> V_114 = V_114 ;
V_114 = V_116 ;
V_45 -> V_98 = NULL ;
}
return V_114 ;
}
void F_102 ( struct V_14 * V_114 )
{
struct V_14 * V_15 ;
while ( ( V_15 = V_114 ) ) {
V_114 = V_15 -> V_114 ;
F_43 ( F_42 ( V_15 ) ) ;
}
}
static int F_103 ( struct V_51 * V_52 )
{
struct V_17 * V_18 ;
unsigned long V_46 ;
V_18 = (struct V_17 * ) F_40 ( V_52 -> V_38 ) ;
if ( ! V_18 ) {
F_104 ( L_14 ,
V_52 -> V_117 ) ;
return - V_118 ;
}
F_85 ( V_52 , V_18 , V_119 ) ;
F_83 ( & V_52 -> V_92 , V_46 ) ;
V_52 -> V_17 = V_18 ;
F_84 ( & V_52 -> V_92 , V_46 ) ;
return 0 ;
}
static void F_105 ( struct V_51 * V_52 )
{
void * V_89 ;
T_5 V_120 ;
unsigned long V_121 ;
V_89 = V_52 -> V_17 ;
F_106 ( & V_52 -> V_122 , V_121 ) ;
F_107 ( V_52 -> V_123 + V_124 , F_86 ( V_89 ) ) ;
F_108 ( V_52 -> V_125 | V_126 , V_52 -> V_123 + V_127 ) ;
F_109 ( V_52 , V_128 ,
V_129 , ( V_120 & V_130 ) , V_120 ) ;
F_110 ( & V_52 -> V_122 , V_121 ) ;
}
static void F_111 ( struct V_51 * V_52 )
{
T_5 V_19 ;
unsigned long V_121 ;
if ( ! V_131 && ! F_112 ( V_52 -> V_55 ) )
return;
F_106 ( & V_52 -> V_122 , V_121 ) ;
F_108 ( V_52 -> V_125 | V_132 , V_52 -> V_123 + V_127 ) ;
F_109 ( V_52 , V_128 ,
V_129 , ( ! ( V_19 & V_133 ) ) , V_19 ) ;
F_110 ( & V_52 -> V_122 , V_121 ) ;
}
static void F_113 ( struct V_51 * V_52 ,
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
V_19 = V_138 | F_114 ( V_134 ) ;
break;
case V_139 :
V_19 = V_139 | F_114 ( V_134 )
| F_115 ( V_135 ) | F_116 ( V_136 ) ;
break;
default:
F_117 () ;
}
V_19 |= V_140 ;
F_106 ( & V_52 -> V_122 , V_121 ) ;
F_107 ( V_52 -> V_123 + V_141 , V_19 ) ;
F_109 ( V_52 , V_141 ,
V_142 , ( ! ( V_19 & V_140 ) ) , V_19 ) ;
F_110 ( & V_52 -> V_122 , V_121 ) ;
}
static void F_118 ( struct V_51 * V_52 , T_3 V_134 ,
V_25 V_89 , unsigned int V_143 , V_25 type )
{
int V_144 = F_119 ( V_52 -> V_66 ) ;
V_25 V_19 = 0 , V_145 = 0 ;
unsigned long V_121 ;
switch ( type ) {
case V_146 :
V_19 = V_146 | V_147 ;
break;
case V_148 :
V_19 = V_148 | V_147 | F_120 ( V_134 ) ;
break;
case V_149 :
V_19 = V_149 | V_147 | F_120 ( V_134 ) ;
V_145 = V_143 | V_89 ;
break;
default:
F_117 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_121 ( V_52 -> V_55 ) )
V_19 |= V_150 ;
F_106 ( & V_52 -> V_122 , V_121 ) ;
if ( V_145 )
F_107 ( V_52 -> V_123 + V_144 , V_145 ) ;
F_107 ( V_52 -> V_123 + V_144 + 8 , V_19 ) ;
F_109 ( V_52 , V_144 + 8 ,
V_142 , ( ! ( V_19 & V_147 ) ) , V_19 ) ;
F_110 ( & V_52 -> V_122 , V_121 ) ;
if ( F_122 ( V_19 ) == 0 )
F_39 ( V_151 L_15 ) ;
if ( F_122 ( V_19 ) != F_123 ( type ) )
F_124 ( L_16 ,
( unsigned long long ) F_123 ( type ) ,
( unsigned long long ) F_122 ( V_19 ) ) ;
}
static struct V_152 *
F_125 ( struct V_44 * V_45 , struct V_51 * V_52 ,
T_2 V_74 , T_2 V_75 )
{
int V_64 = 0 ;
unsigned long V_46 ;
struct V_152 * V_153 ;
struct V_77 * V_79 ;
if ( ! F_126 ( V_52 -> V_66 ) )
return NULL ;
if ( ! V_52 -> V_154 )
return NULL ;
F_83 ( & V_155 , V_46 ) ;
F_127 (info, &domain->devices, link)
if ( V_153 -> V_52 == V_52 && V_153 -> V_74 == V_74 &&
V_153 -> V_75 == V_75 ) {
V_64 = 1 ;
break;
}
F_84 ( & V_155 , V_46 ) ;
if ( ! V_64 || ! V_153 -> V_73 || ! F_75 ( V_153 -> V_73 ) )
return NULL ;
V_79 = F_76 ( V_153 -> V_73 ) ;
if ( ! F_128 ( V_79 , V_156 ) )
return NULL ;
if ( ! F_129 ( V_79 ) )
return NULL ;
return V_153 ;
}
static void F_130 ( struct V_152 * V_153 )
{
if ( ! V_153 || ! F_75 ( V_153 -> V_73 ) )
return;
F_131 ( F_76 ( V_153 -> V_73 ) , V_12 ) ;
}
static void F_132 ( struct V_152 * V_153 )
{
if ( ! V_153 -> V_73 || ! F_75 ( V_153 -> V_73 ) ||
! F_133 ( F_76 ( V_153 -> V_73 ) ) )
return;
F_134 ( F_76 ( V_153 -> V_73 ) ) ;
}
static void F_135 ( struct V_44 * V_45 ,
V_25 V_89 , unsigned V_69 )
{
T_3 V_157 , V_158 ;
unsigned long V_46 ;
struct V_152 * V_153 ;
F_83 ( & V_155 , V_46 ) ;
F_127 (info, &domain->devices, link) {
struct V_77 * V_79 ;
if ( ! V_153 -> V_73 || ! F_75 ( V_153 -> V_73 ) )
continue;
V_79 = F_76 ( V_153 -> V_73 ) ;
if ( ! F_133 ( V_79 ) )
continue;
V_157 = V_153 -> V_74 << 8 | V_153 -> V_75 ;
V_158 = F_136 ( V_79 ) ;
F_137 ( V_153 -> V_52 , V_157 , V_158 , V_89 , V_69 ) ;
}
F_84 ( & V_155 , V_46 ) ;
}
static void F_138 ( struct V_51 * V_52 , T_3 V_134 ,
unsigned long V_6 , unsigned int V_159 , int V_160 , int V_161 )
{
unsigned int V_69 = F_139 ( F_140 ( V_159 ) ) ;
T_4 V_89 = ( T_4 ) V_6 << V_12 ;
F_60 ( V_159 == 0 ) ;
if ( V_160 )
V_160 = 1 << 6 ;
if ( ! F_141 ( V_52 -> V_55 ) || V_69 > F_142 ( V_52 -> V_55 ) )
V_52 -> V_162 . V_163 ( V_52 , V_134 , 0 , 0 ,
V_148 ) ;
else
V_52 -> V_162 . V_163 ( V_52 , V_134 , V_89 | V_160 , V_69 ,
V_149 ) ;
if ( ! F_143 ( V_52 -> V_55 ) || ! V_161 )
F_135 ( V_52 -> V_164 [ V_134 ] , V_89 , V_69 ) ;
}
static void F_144 ( struct V_51 * V_52 )
{
T_5 V_165 ;
unsigned long V_46 ;
F_106 ( & V_52 -> V_122 , V_46 ) ;
V_165 = V_129 ( V_52 -> V_123 + V_166 ) ;
V_165 &= ~ V_167 ;
F_108 ( V_165 , V_52 -> V_123 + V_166 ) ;
F_109 ( V_52 , V_166 ,
V_129 , ! ( V_165 & V_168 ) , V_165 ) ;
F_110 ( & V_52 -> V_122 , V_46 ) ;
}
static void F_145 ( struct V_51 * V_52 )
{
T_5 V_120 ;
unsigned long V_46 ;
F_106 ( & V_52 -> V_122 , V_46 ) ;
V_52 -> V_125 |= V_169 ;
F_108 ( V_52 -> V_125 , V_52 -> V_123 + V_127 ) ;
F_109 ( V_52 , V_128 ,
V_129 , ( V_120 & V_170 ) , V_120 ) ;
F_110 ( & V_52 -> V_122 , V_46 ) ;
}
static void F_146 ( struct V_51 * V_52 )
{
T_5 V_120 ;
unsigned long V_121 ;
F_106 ( & V_52 -> V_122 , V_121 ) ;
V_52 -> V_125 &= ~ V_169 ;
F_108 ( V_52 -> V_125 , V_52 -> V_123 + V_127 ) ;
F_109 ( V_52 , V_128 ,
V_129 , ( ! ( V_120 & V_170 ) ) , V_120 ) ;
F_110 ( & V_52 -> V_122 , V_121 ) ;
}
static int F_147 ( struct V_51 * V_52 )
{
unsigned long V_171 ;
unsigned long V_172 ;
V_171 = F_148 ( V_52 -> V_55 ) ;
F_124 ( L_17 ,
V_52 -> V_173 , V_171 ) ;
V_172 = F_149 ( V_171 ) ;
F_150 ( & V_52 -> V_92 ) ;
V_52 -> V_174 = F_151 ( V_172 , sizeof( unsigned long ) , V_175 ) ;
if ( ! V_52 -> V_174 ) {
F_104 ( L_18 ,
V_52 -> V_173 ) ;
return - V_118 ;
}
V_52 -> V_164 = F_151 ( V_171 , sizeof( struct V_44 * ) ,
V_175 ) ;
if ( ! V_52 -> V_164 ) {
F_104 ( L_19 ,
V_52 -> V_173 ) ;
F_152 ( V_52 -> V_174 ) ;
V_52 -> V_174 = NULL ;
return - V_118 ;
}
if ( F_143 ( V_52 -> V_55 ) )
F_153 ( 0 , V_52 -> V_174 ) ;
return 0 ;
}
static void F_154 ( struct V_51 * V_52 )
{
struct V_44 * V_45 ;
int V_63 ;
if ( ( V_52 -> V_164 ) && ( V_52 -> V_174 ) ) {
F_63 (i, iommu->domain_ids, cap_ndoms(iommu->cap)) {
if ( F_143 ( V_52 -> V_55 ) && V_63 == 0 )
continue;
V_45 = V_52 -> V_164 [ V_63 ] ;
F_155 ( V_63 , V_52 -> V_174 ) ;
if ( F_156 ( V_45 , V_52 ) == 0 &&
! F_51 ( V_45 ) )
F_157 ( V_45 ) ;
}
}
if ( V_52 -> V_125 & V_169 )
F_146 ( V_52 ) ;
}
static void F_158 ( struct V_51 * V_52 )
{
if ( ( V_52 -> V_164 ) && ( V_52 -> V_174 ) ) {
F_152 ( V_52 -> V_164 ) ;
F_152 ( V_52 -> V_174 ) ;
V_52 -> V_164 = NULL ;
V_52 -> V_174 = NULL ;
}
V_60 [ V_52 -> V_173 ] = NULL ;
F_89 ( V_52 ) ;
}
static struct V_44 * F_159 ( int V_46 )
{
static T_6 V_176 = F_160 ( 0 ) ;
struct V_44 * V_45 ;
V_45 = F_45 () ;
if ( ! V_45 )
return NULL ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_101 = - 1 ;
V_45 -> V_46 = V_46 ;
F_150 ( & V_45 -> V_177 ) ;
F_161 ( & V_45 -> V_81 ) ;
if ( V_46 & V_47 )
V_45 -> V_178 = F_162 ( & V_176 ) ;
return V_45 ;
}
static int F_163 ( struct V_44 * V_45 ,
struct V_51 * V_52 )
{
int V_179 ;
unsigned long V_171 ;
V_171 = F_148 ( V_52 -> V_55 ) ;
V_179 = F_164 ( V_52 -> V_174 , V_171 ) ;
if ( V_179 < V_171 ) {
F_153 ( V_179 , V_52 -> V_174 ) ;
V_52 -> V_164 [ V_179 ] = V_45 ;
} else {
V_179 = - V_180 ;
}
return V_179 ;
}
static int F_165 ( struct V_44 * V_45 ,
struct V_51 * V_52 )
{
int V_179 ;
unsigned long V_46 ;
F_83 ( & V_52 -> V_92 , V_46 ) ;
V_179 = F_163 ( V_45 , V_52 ) ;
F_84 ( & V_52 -> V_92 , V_46 ) ;
if ( V_179 < 0 )
F_104 ( L_20 ) ;
return V_179 ;
}
static int F_166 ( struct V_44 * V_45 ,
struct V_51 * V_52 )
{
int V_179 ;
unsigned long V_171 ;
V_171 = F_148 ( V_52 -> V_55 ) ;
F_63 (num, iommu->domain_ids, ndomains)
if ( V_52 -> V_164 [ V_179 ] == V_45 )
return V_179 ;
return F_163 ( V_45 , V_52 ) ;
}
static void F_167 ( struct V_44 * V_45 ,
struct V_51 * V_52 )
{
unsigned long V_46 ;
int V_179 , V_171 ;
F_83 ( & V_52 -> V_92 , V_46 ) ;
if ( F_52 ( V_45 ) ) {
V_171 = F_148 ( V_52 -> V_55 ) ;
F_63 (num, iommu->domain_ids, ndomains) {
if ( V_52 -> V_164 [ V_179 ] == V_45 ) {
F_155 ( V_179 , V_52 -> V_174 ) ;
V_52 -> V_164 [ V_179 ] = NULL ;
break;
}
}
} else {
F_155 ( V_45 -> V_178 , V_52 -> V_174 ) ;
V_52 -> V_164 [ V_45 -> V_178 ] = NULL ;
}
F_84 ( & V_52 -> V_92 , V_46 ) ;
}
static void F_168 ( struct V_44 * V_45 ,
struct V_51 * V_52 )
{
unsigned long V_46 ;
F_83 ( & V_45 -> V_177 , V_46 ) ;
if ( ! F_169 ( V_52 -> V_173 , V_45 -> V_58 ) ) {
V_45 -> V_181 ++ ;
if ( V_45 -> V_181 == 1 )
V_45 -> V_101 = V_52 -> V_38 ;
F_73 ( V_45 ) ;
}
F_84 ( & V_45 -> V_177 , V_46 ) ;
}
static int F_156 ( struct V_44 * V_45 ,
struct V_51 * V_52 )
{
unsigned long V_46 ;
int V_182 = V_183 ;
F_83 ( & V_45 -> V_177 , V_46 ) ;
if ( F_170 ( V_52 -> V_173 , V_45 -> V_58 ) ) {
V_182 = -- V_45 -> V_181 ;
F_73 ( V_45 ) ;
}
F_84 ( & V_45 -> V_177 , V_46 ) ;
return V_182 ;
}
static int F_171 ( void )
{
struct V_77 * V_79 = NULL ;
struct V_184 * V_184 ;
int V_63 ;
F_172 ( & V_185 , V_102 , V_186 ,
V_187 ) ;
F_173 ( & V_185 . V_188 ,
& V_189 ) ;
V_184 = F_174 ( & V_185 , F_175 ( V_190 ) ,
F_175 ( V_191 ) ) ;
if ( ! V_184 ) {
F_39 ( V_151 L_21 ) ;
return - V_192 ;
}
F_176 (pdev) {
struct V_193 * V_194 ;
for ( V_63 = 0 ; V_63 < V_195 ; V_63 ++ ) {
V_194 = & V_79 -> V_193 [ V_63 ] ;
if ( ! V_194 -> V_46 || ! ( V_194 -> V_46 & V_196 ) )
continue;
V_184 = F_174 ( & V_185 ,
F_175 ( V_194 -> V_197 ) ,
F_175 ( V_194 -> V_86 ) ) ;
if ( ! V_184 ) {
F_39 ( V_151 L_22 ) ;
return - V_192 ;
}
}
}
return 0 ;
}
static void F_177 ( struct V_44 * V_45 )
{
F_178 ( & V_185 , & V_45 -> V_198 ) ;
}
static inline int F_179 ( int V_113 )
{
int V_1 ;
int V_194 = ( V_113 - 12 ) % 9 ;
if ( V_194 == 0 )
V_1 = V_113 ;
else
V_1 = V_113 + 9 - V_194 ;
if ( V_1 > 64 )
V_1 = 64 ;
return V_1 ;
}
static int F_180 ( struct V_44 * V_45 , int V_199 )
{
struct V_51 * V_52 ;
int V_200 , V_1 ;
unsigned long V_54 ;
F_172 ( & V_45 -> V_198 , V_102 , V_186 ,
V_187 ) ;
F_177 ( V_45 ) ;
V_52 = F_59 ( V_45 ) ;
if ( V_199 > F_181 ( V_52 -> V_55 ) )
V_199 = F_181 ( V_52 -> V_55 ) ;
V_45 -> V_113 = V_199 ;
V_200 = F_179 ( V_199 ) ;
V_1 = F_4 ( V_200 ) ;
V_54 = F_55 ( V_52 -> V_55 ) ;
if ( ! F_56 ( V_1 , & V_54 ) ) {
F_124 ( L_23 , V_1 ) ;
V_1 = F_182 ( & V_54 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_192 ;
}
V_45 -> V_1 = V_1 ;
if ( F_64 ( V_52 -> V_66 ) )
V_45 -> V_65 = 1 ;
else
V_45 -> V_65 = 0 ;
if ( F_69 ( V_52 -> V_66 ) )
V_45 -> V_70 = 1 ;
else
V_45 -> V_70 = 0 ;
if ( V_37 )
V_45 -> V_71 = F_72 ( F_71 ( V_52 -> V_55 ) ) ;
else
V_45 -> V_71 = 0 ;
V_45 -> V_101 = V_52 -> V_38 ;
V_45 -> V_98 = (struct V_27 * ) F_40 ( V_45 -> V_101 ) ;
if ( ! V_45 -> V_98 )
return - V_118 ;
F_85 ( V_52 , V_45 -> V_98 , V_201 ) ;
return 0 ;
}
static void F_157 ( struct V_44 * V_45 )
{
struct V_14 * V_114 = NULL ;
int V_63 ;
if ( ! V_45 )
return;
if ( ! V_36 )
F_183 ( 0 ) ;
F_184 ( V_45 ) ;
F_185 ( & V_45 -> V_198 ) ;
V_114 = F_101 ( V_45 , 0 , F_97 ( V_45 -> V_113 ) ) ;
F_65 () ;
F_63 (i, domain->iommu_bmp, g_num_of_iommus)
F_167 ( V_45 , V_60 [ V_63 ] ) ;
F_67 () ;
F_102 ( V_114 ) ;
F_47 ( V_45 ) ;
}
static int F_186 ( struct V_44 * V_45 ,
struct V_51 * V_52 ,
T_2 V_74 , T_2 V_75 , int V_202 )
{
struct V_22 * V_23 ;
unsigned long V_46 ;
struct V_27 * V_98 ;
int V_178 ;
int V_1 ;
struct V_152 * V_153 = NULL ;
F_124 ( L_24 ,
V_74 , F_187 ( V_75 ) , F_188 ( V_75 ) ) ;
F_60 ( ! V_45 -> V_98 ) ;
F_60 ( V_202 != V_203 &&
V_202 != V_204 ) ;
V_23 = F_82 ( V_52 , V_74 , V_75 ) ;
if ( ! V_23 )
return - V_118 ;
F_83 ( & V_52 -> V_92 , V_46 ) ;
if ( F_23 ( V_23 ) ) {
F_84 ( & V_52 -> V_92 , V_46 ) ;
return 0 ;
}
V_178 = V_45 -> V_178 ;
V_98 = V_45 -> V_98 ;
if ( F_52 ( V_45 ) ) {
if ( F_51 ( V_45 ) ) {
V_178 = F_166 ( V_45 , V_52 ) ;
if ( V_178 < 0 ) {
F_84 ( & V_52 -> V_92 , V_46 ) ;
F_104 ( L_20 ) ;
return - V_205 ;
}
}
if ( V_202 != V_203 ) {
for ( V_1 = V_45 -> V_1 ; V_1 != V_52 -> V_1 ; V_1 -- ) {
V_98 = F_22 ( F_32 ( V_98 ) ) ;
if ( ! F_35 ( V_98 ) ) {
F_84 ( & V_52 -> V_92 , V_46 ) ;
return - V_118 ;
}
}
}
}
F_29 ( V_23 , V_178 ) ;
if ( V_202 != V_203 ) {
V_153 = F_125 ( V_45 , V_52 , V_74 , V_75 ) ;
V_202 = V_153 ? V_206 :
V_204 ;
}
if ( F_189 ( V_202 == V_203 ) )
F_28 ( V_23 , V_52 -> V_207 ) ;
else {
F_27 ( V_23 , F_86 ( V_98 ) ) ;
F_28 ( V_23 , V_52 -> V_1 ) ;
}
F_26 ( V_23 , V_202 ) ;
F_25 ( V_23 ) ;
F_24 ( V_23 ) ;
F_80 ( V_45 , V_23 , sizeof( * V_23 ) ) ;
if ( F_143 ( V_52 -> V_55 ) ) {
V_52 -> V_162 . V_208 ( V_52 , 0 ,
( ( ( T_3 ) V_74 ) << 8 ) | V_75 ,
V_209 ,
V_139 ) ;
V_52 -> V_162 . V_163 ( V_52 , V_178 , 0 , 0 , V_148 ) ;
} else {
F_111 ( V_52 ) ;
}
F_130 ( V_153 ) ;
F_84 ( & V_52 -> V_92 , V_46 ) ;
F_168 ( V_45 , V_52 ) ;
return 0 ;
}
static int F_190 ( struct V_77 * V_79 ,
T_3 V_210 , void * V_211 )
{
struct V_212 * V_213 = V_211 ;
return F_186 ( V_213 -> V_45 , V_213 -> V_52 ,
F_191 ( V_210 ) , V_210 & 0xff ,
V_213 -> V_202 ) ;
}
static int
F_192 ( struct V_44 * V_45 , struct V_72 * V_73 ,
int V_202 )
{
struct V_51 * V_52 ;
T_2 V_74 , V_75 ;
struct V_212 V_213 ;
V_52 = F_74 ( V_73 , & V_74 , & V_75 ) ;
if ( ! V_52 )
return - V_192 ;
if ( ! F_75 ( V_73 ) )
return F_186 ( V_45 , V_52 , V_74 , V_75 ,
V_202 ) ;
V_213 . V_45 = V_45 ;
V_213 . V_52 = V_52 ;
V_213 . V_202 = V_202 ;
return F_193 ( F_76 ( V_73 ) ,
& F_190 , & V_213 ) ;
}
static int F_194 ( struct V_77 * V_79 ,
T_3 V_210 , void * V_211 )
{
struct V_51 * V_52 = V_211 ;
return ! F_87 ( V_52 , F_191 ( V_210 ) , V_210 & 0xff ) ;
}
static int F_195 ( struct V_72 * V_73 )
{
struct V_51 * V_52 ;
T_2 V_74 , V_75 ;
V_52 = F_74 ( V_73 , & V_74 , & V_75 ) ;
if ( ! V_52 )
return - V_192 ;
if ( ! F_75 ( V_73 ) )
return F_87 ( V_52 , V_74 , V_75 ) ;
return ! F_193 ( F_76 ( V_73 ) ,
F_194 , V_52 ) ;
}
static inline unsigned long F_196 ( unsigned long V_214 ,
T_7 V_90 )
{
V_214 &= ~ V_215 ;
return F_197 ( V_214 + V_90 ) >> V_12 ;
}
static inline int F_198 ( struct V_44 * V_45 ,
unsigned long V_216 ,
unsigned long V_217 ,
unsigned long V_159 )
{
int V_218 , V_5 = 1 ;
unsigned long V_219 ;
V_218 = V_45 -> V_71 ;
V_219 = V_216 | V_217 ;
while ( V_218 && ! ( V_219 & ~ V_220 ) ) {
V_159 >>= V_221 ;
if ( ! V_159 )
break;
V_219 >>= V_221 ;
V_5 ++ ;
V_218 -- ;
}
return V_5 ;
}
static int F_199 ( struct V_44 * V_45 , unsigned long V_216 ,
struct V_222 * V_223 , unsigned long V_224 ,
unsigned long V_225 , int V_226 )
{
struct V_27 * V_109 = NULL , * V_28 = NULL ;
T_8 V_227 ( V_100 ) ;
unsigned long V_228 = 0 ;
unsigned int V_229 = 0 ;
unsigned long V_230 = 0 ;
F_60 ( ! F_53 ( V_45 , V_216 + V_225 - 1 ) ) ;
if ( ( V_226 & ( V_103 | V_104 ) ) == 0 )
return - V_31 ;
V_226 &= V_103 | V_104 | V_231 ;
if ( ! V_223 ) {
V_228 = V_225 ;
V_100 = ( ( T_8 ) V_224 << V_12 ) | V_226 ;
}
while ( V_225 > 0 ) {
T_4 V_76 ;
if ( ! V_228 ) {
V_228 = F_196 ( V_223 -> V_97 , V_223 -> V_232 ) ;
V_223 -> V_233 = ( ( V_234 ) V_216 << V_12 ) + V_223 -> V_97 ;
V_223 -> V_235 = V_223 -> V_232 ;
V_100 = F_200 ( F_201 ( V_223 ) ) | V_226 ;
V_224 = V_100 >> V_12 ;
}
if ( ! V_28 ) {
V_229 = F_198 ( V_45 , V_216 , V_224 , V_228 ) ;
V_109 = V_28 = F_90 ( V_45 , V_216 , & V_229 ) ;
if ( ! V_28 )
return - V_118 ;
if ( V_229 > 1 ) {
V_100 |= V_29 ;
V_230 = F_11 ( V_229 ) ;
F_96 ( V_45 , V_216 ,
V_216 + V_230 - 1 ) ;
} else {
V_100 &= ~ ( T_4 ) V_29 ;
}
}
V_76 = F_202 ( & V_28 -> V_19 , 0ULL , V_100 ) ;
if ( V_76 ) {
static int V_236 = 5 ;
F_39 ( V_237 L_25 ,
V_216 , V_76 , ( unsigned long long ) V_100 ) ;
if ( V_236 ) {
V_236 -- ;
F_203 ( NULL ) ;
}
F_204 ( 1 ) ;
}
V_230 = F_11 ( V_229 ) ;
F_60 ( V_225 < V_230 ) ;
F_60 ( V_228 < V_230 ) ;
V_225 -= V_230 ;
V_216 += V_230 ;
V_224 += V_230 ;
V_100 += V_230 * V_102 ;
V_228 -= V_230 ;
V_28 ++ ;
if ( ! V_225 || F_37 ( V_28 ) ||
( V_229 > 1 && V_228 < V_230 ) ) {
F_80 ( V_45 , V_109 ,
( void * ) V_28 - ( void * ) V_109 ) ;
V_28 = NULL ;
}
if ( ! V_228 && V_225 )
V_223 = F_205 ( V_223 ) ;
}
return 0 ;
}
static inline int F_206 ( struct V_44 * V_45 , unsigned long V_216 ,
struct V_222 * V_223 , unsigned long V_225 ,
int V_226 )
{
return F_199 ( V_45 , V_216 , V_223 , 0 , V_225 , V_226 ) ;
}
static inline int F_207 ( struct V_44 * V_45 , unsigned long V_216 ,
unsigned long V_224 , unsigned long V_225 ,
int V_226 )
{
return F_199 ( V_45 , V_216 , NULL , V_224 , V_225 , V_226 ) ;
}
static void F_208 ( struct V_51 * V_52 , T_2 V_74 , T_2 V_75 )
{
if ( ! V_52 )
return;
F_88 ( V_52 , V_74 , V_75 ) ;
V_52 -> V_162 . V_208 ( V_52 , 0 , 0 , 0 ,
V_137 ) ;
V_52 -> V_162 . V_163 ( V_52 , 0 , 0 , 0 , V_146 ) ;
}
static inline void F_209 ( struct V_152 * V_153 )
{
F_210 ( & V_155 ) ;
F_211 ( & V_153 -> V_238 ) ;
F_211 ( & V_153 -> V_239 ) ;
if ( V_153 -> V_73 )
V_153 -> V_73 -> V_240 . V_52 = NULL ;
}
static void F_184 ( struct V_44 * V_45 )
{
struct V_152 * V_153 , * V_76 ;
unsigned long V_46 ;
F_83 ( & V_155 , V_46 ) ;
F_212 (info, tmp, &domain->devices, link) {
F_209 ( V_153 ) ;
F_84 ( & V_155 , V_46 ) ;
F_132 ( V_153 ) ;
F_208 ( V_153 -> V_52 , V_153 -> V_74 , V_153 -> V_75 ) ;
if ( F_51 ( V_45 ) ) {
F_213 ( V_153 -> V_52 , V_153 -> V_73 ) ;
F_156 ( V_45 , V_153 -> V_52 ) ;
}
F_50 ( V_153 ) ;
F_83 ( & V_155 , V_46 ) ;
}
F_84 ( & V_155 , V_46 ) ;
}
static struct V_44 * F_214 ( struct V_72 * V_73 )
{
struct V_152 * V_153 ;
V_153 = V_73 -> V_240 . V_52 ;
if ( V_153 )
return V_153 -> V_45 ;
return NULL ;
}
static inline struct V_152 *
F_215 ( int V_80 , int V_74 , int V_75 )
{
struct V_152 * V_153 ;
F_127 (info, &device_domain_list, global)
if ( V_153 -> V_52 -> V_80 == V_80 && V_153 -> V_74 == V_74 &&
V_153 -> V_75 == V_75 )
return V_153 ;
return NULL ;
}
static struct V_44 * F_216 ( struct V_51 * V_52 ,
int V_74 , int V_75 ,
struct V_72 * V_73 ,
struct V_44 * V_45 )
{
struct V_44 * V_64 = NULL ;
struct V_152 * V_153 ;
unsigned long V_46 ;
V_153 = F_49 () ;
if ( ! V_153 )
return NULL ;
V_153 -> V_74 = V_74 ;
V_153 -> V_75 = V_75 ;
V_153 -> V_73 = V_73 ;
V_153 -> V_45 = V_45 ;
V_153 -> V_52 = V_52 ;
F_83 ( & V_155 , V_46 ) ;
if ( V_73 )
V_64 = F_214 ( V_73 ) ;
else {
struct V_152 * V_241 ;
V_241 = F_215 ( V_52 -> V_80 , V_74 , V_75 ) ;
if ( V_241 )
V_64 = V_241 -> V_45 ;
}
if ( V_64 ) {
F_84 ( & V_155 , V_46 ) ;
F_50 ( V_153 ) ;
return V_64 ;
}
F_217 ( & V_153 -> V_238 , & V_45 -> V_81 ) ;
F_217 ( & V_153 -> V_239 , & V_242 ) ;
if ( V_73 )
V_73 -> V_240 . V_52 = V_153 ;
F_84 ( & V_155 , V_46 ) ;
return V_45 ;
}
static int F_218 ( struct V_77 * V_79 , T_3 V_210 , void * V_211 )
{
* ( T_3 * ) V_211 = V_210 ;
return 0 ;
}
static struct V_44 * F_219 ( struct V_72 * V_73 , int V_113 )
{
struct V_44 * V_45 , * V_76 ;
struct V_51 * V_52 ;
struct V_152 * V_153 ;
T_3 V_243 ;
unsigned long V_46 ;
T_2 V_74 , V_75 ;
V_45 = F_214 ( V_73 ) ;
if ( V_45 )
return V_45 ;
V_52 = F_74 ( V_73 , & V_74 , & V_75 ) ;
if ( ! V_52 )
return NULL ;
if ( F_75 ( V_73 ) ) {
struct V_77 * V_79 = F_76 ( V_73 ) ;
F_193 ( V_79 , F_218 , & V_243 ) ;
F_83 ( & V_155 , V_46 ) ;
V_153 = F_215 ( F_77 ( V_79 -> V_74 ) ,
F_191 ( V_243 ) ,
V_243 & 0xff ) ;
if ( V_153 ) {
V_52 = V_153 -> V_52 ;
V_45 = V_153 -> V_45 ;
}
F_84 ( & V_155 , V_46 ) ;
if ( V_153 )
goto V_244;
}
V_45 = F_159 ( 0 ) ;
if ( ! V_45 )
return NULL ;
V_45 -> V_178 = F_165 ( V_45 , V_52 ) ;
if ( V_45 -> V_178 < 0 ) {
F_47 ( V_45 ) ;
return NULL ;
}
F_168 ( V_45 , V_52 ) ;
if ( F_180 ( V_45 , V_113 ) ) {
F_157 ( V_45 ) ;
return NULL ;
}
if ( F_75 ( V_73 ) ) {
V_76 = F_216 ( V_52 , F_191 ( V_243 ) ,
V_243 & 0xff , NULL , V_45 ) ;
if ( ! V_76 || V_76 != V_45 ) {
F_157 ( V_45 ) ;
V_45 = V_76 ;
}
if ( ! V_45 )
return NULL ;
}
V_244:
V_76 = F_216 ( V_52 , V_74 , V_75 , V_73 , V_45 ) ;
if ( ! V_76 || V_76 != V_45 ) {
F_157 ( V_45 ) ;
V_45 = V_76 ;
}
return V_45 ;
}
static int F_220 ( struct V_44 * V_45 ,
unsigned long long V_197 ,
unsigned long long V_86 )
{
unsigned long V_245 = V_197 >> V_12 ;
unsigned long V_246 = V_86 >> V_12 ;
if ( ! F_174 ( & V_45 -> V_198 , F_12 ( V_245 ) ,
F_12 ( V_246 ) ) ) {
F_39 ( V_151 L_26 ) ;
return - V_118 ;
}
F_124 ( L_27 ,
V_197 , V_86 , V_45 -> V_178 ) ;
F_93 ( V_45 , V_245 , V_246 ) ;
return F_207 ( V_45 , V_245 , V_245 ,
V_246 - V_245 + 1 ,
V_103 | V_104 ) ;
}
static int F_221 ( struct V_72 * V_73 ,
unsigned long long V_197 ,
unsigned long long V_86 )
{
struct V_44 * V_45 ;
int V_68 ;
V_45 = F_219 ( V_73 , V_56 ) ;
if ( ! V_45 )
return - V_118 ;
if ( V_45 == V_247 && V_248 ) {
F_39 ( L_28 ,
F_222 ( V_73 ) , V_197 , V_86 ) ;
return 0 ;
}
F_39 ( V_33
L_29 ,
F_222 ( V_73 ) , V_197 , V_86 ) ;
if ( V_86 < V_197 ) {
F_223 ( 1 , L_30
L_31 ,
F_224 ( V_249 ) ,
F_224 ( V_250 ) ,
F_224 ( V_251 ) ) ;
V_68 = - V_252 ;
goto error;
}
if ( V_86 >> F_2 ( V_45 -> V_1 ) ) {
F_223 ( 1 , L_32
L_31 ,
F_2 ( V_45 -> V_1 ) ,
F_224 ( V_249 ) ,
F_224 ( V_250 ) ,
F_224 ( V_251 ) ) ;
V_68 = - V_252 ;
goto error;
}
V_68 = F_220 ( V_45 , V_197 , V_86 ) ;
if ( V_68 )
goto error;
V_68 = F_192 ( V_45 , V_73 , V_204 ) ;
if ( V_68 )
goto error;
return 0 ;
error:
F_157 ( V_45 ) ;
return V_68 ;
}
static inline int F_225 ( struct V_253 * V_254 ,
struct V_72 * V_73 )
{
if ( V_73 -> V_240 . V_52 == V_255 )
return 0 ;
return F_221 ( V_73 , V_254 -> V_256 ,
V_254 -> V_257 ) ;
}
static inline void F_226 ( void )
{
struct V_77 * V_79 ;
int V_68 ;
V_79 = F_227 ( V_258 << 8 , NULL ) ;
if ( ! V_79 )
return;
F_39 ( V_33 L_33 ) ;
V_68 = F_221 ( & V_79 -> V_73 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_68 )
F_39 ( V_151 L_34
L_35 ) ;
F_228 ( V_79 ) ;
}
static inline void F_226 ( void )
{
return;
}
static int T_1 F_229 ( int V_259 )
{
struct V_61 * V_62 ;
struct V_51 * V_52 ;
int V_101 , V_68 = 0 ;
bool V_260 = true ;
V_247 = F_159 ( V_48 ) ;
if ( ! V_247 )
return - V_205 ;
F_66 (iommu, drhd) {
V_68 = F_165 ( V_247 , V_52 ) ;
if ( V_68 < 0 ) {
F_157 ( V_247 ) ;
return - V_205 ;
} else if ( V_260 ) {
V_247 -> V_178 = V_68 ;
V_260 = false ;
} else if ( V_247 -> V_178 != V_68 ) {
F_157 ( V_247 ) ;
return - V_205 ;
}
F_168 ( V_247 , V_52 ) ;
}
if ( F_230 ( V_247 , V_56 ) ) {
F_157 ( V_247 ) ;
return - V_205 ;
}
F_124 ( L_36 ,
V_247 -> V_178 ) ;
if ( V_259 )
return 0 ;
F_231 (nid) {
unsigned long V_107 , V_261 ;
int V_63 ;
F_232 (i, nid, &start_pfn, &end_pfn, NULL) {
V_68 = F_220 ( V_247 ,
F_233 ( V_107 ) , F_233 ( V_261 ) ) ;
if ( V_68 )
return V_68 ;
}
}
return 0 ;
}
static int F_234 ( struct V_72 * V_73 )
{
struct V_152 * V_153 ;
if ( F_235 ( ! V_262 ) )
return 0 ;
V_153 = V_73 -> V_240 . V_52 ;
if ( V_153 && V_153 != V_255 )
return ( V_153 -> V_45 == V_247 ) ;
return 0 ;
}
static int F_236 ( struct V_44 * V_45 ,
struct V_72 * V_73 , int V_202 )
{
struct V_44 * V_263 ;
struct V_51 * V_52 ;
T_2 V_74 , V_75 ;
int V_68 ;
V_52 = F_74 ( V_73 , & V_74 , & V_75 ) ;
if ( ! V_52 )
return - V_192 ;
V_263 = F_216 ( V_52 , V_74 , V_75 , V_73 , V_45 ) ;
if ( V_263 != V_45 )
return - V_264 ;
V_68 = F_192 ( V_45 , V_73 , V_202 ) ;
if ( V_68 ) {
F_237 ( V_45 , V_73 ) ;
return V_68 ;
}
return 0 ;
}
static bool F_238 ( struct V_72 * V_73 )
{
struct V_253 * V_254 ;
struct V_72 * V_76 ;
int V_63 ;
F_65 () ;
F_239 (rmrr) {
F_79 (rmrr->devices,
rmrr->devices_cnt, i, tmp)
if ( V_76 == V_73 ) {
F_67 () ;
return true ;
}
}
F_67 () ;
return false ;
}
static bool F_240 ( struct V_72 * V_73 )
{
if ( ! F_238 ( V_73 ) )
return false ;
if ( F_75 ( V_73 ) ) {
struct V_77 * V_79 = F_76 ( V_73 ) ;
if ( ( V_79 -> V_265 >> 8 ) == V_266 )
return false ;
}
return true ;
}
static int F_241 ( struct V_72 * V_73 , int V_267 )
{
if ( F_75 ( V_73 ) ) {
struct V_77 * V_79 = F_76 ( V_73 ) ;
if ( F_240 ( V_73 ) )
return 0 ;
if ( ( V_262 & V_268 ) && F_242 ( V_79 ) )
return 1 ;
if ( ( V_262 & V_269 ) && F_243 ( V_79 ) )
return 1 ;
if ( ! ( V_262 & V_270 ) )
return 0 ;
if ( ! F_244 ( V_79 ) ) {
if ( ! F_245 ( V_79 -> V_74 ) )
return 0 ;
if ( V_79 -> V_265 >> 8 == V_271 )
return 0 ;
} else if ( F_246 ( V_79 ) == V_272 )
return 0 ;
} else {
if ( F_238 ( V_73 ) )
return 0 ;
}
if ( ! V_267 ) {
V_25 V_273 = * V_73 -> V_273 ;
if ( V_73 -> V_274 &&
V_73 -> V_274 < V_273 )
V_273 = V_73 -> V_274 ;
return V_273 >= F_247 ( V_73 ) ;
}
return 1 ;
}
static int T_1 F_248 ( struct V_72 * V_73 , int V_259 )
{
int V_68 ;
if ( ! F_241 ( V_73 , 1 ) )
return 0 ;
V_68 = F_236 ( V_247 , V_73 ,
V_259 ? V_203 :
V_204 ) ;
if ( ! V_68 )
F_249 ( L_37 ,
V_259 ? L_38 : L_39 , F_222 ( V_73 ) ) ;
else if ( V_68 == - V_192 )
V_68 = 0 ;
return V_68 ;
}
static int T_1 F_250 ( int V_259 )
{
struct V_77 * V_79 = NULL ;
struct V_61 * V_62 ;
struct V_51 * V_52 ;
struct V_72 * V_73 ;
int V_63 ;
int V_68 = 0 ;
V_68 = F_229 ( V_259 ) ;
if ( V_68 )
return - V_205 ;
F_176 (pdev) {
V_68 = F_248 ( & V_79 -> V_73 , V_259 ) ;
if ( V_68 )
return V_68 ;
}
F_66 (iommu, drhd)
F_79 (drhd->devices, drhd->devices_cnt, i, dev) {
struct V_275 * V_276 ;
struct V_277 * V_278 ;
if ( V_73 -> V_74 != & V_279 )
continue;
V_278 = F_251 ( V_73 ) ;
F_252 ( & V_278 -> V_280 ) ;
F_127 (pn, &adev->physical_node_list, node) {
V_68 = F_248 ( V_276 -> V_73 , V_259 ) ;
if ( V_68 )
break;
}
F_253 ( & V_278 -> V_280 ) ;
if ( V_68 )
return V_68 ;
}
return 0 ;
}
static void F_254 ( struct V_51 * V_52 )
{
if ( ! V_52 -> V_154 ) {
F_255 ( - 1 , V_52 ) ;
F_256 ( V_52 ) ;
}
if ( F_257 ( V_52 ) ) {
V_52 -> V_162 . V_208 = F_113 ;
V_52 -> V_162 . V_163 = F_118 ;
F_249 ( L_40 ,
V_52 -> V_117 ) ;
} else {
V_52 -> V_162 . V_208 = V_281 ;
V_52 -> V_162 . V_163 = V_282 ;
F_249 ( L_41 , V_52 -> V_117 ) ;
}
}
static int T_1 F_258 ( void )
{
struct V_61 * V_62 ;
struct V_253 * V_254 ;
struct V_72 * V_73 ;
struct V_51 * V_52 ;
int V_63 , V_68 ;
F_259 (drhd) {
if ( V_59 < V_283 ) {
V_59 ++ ;
continue;
}
F_260 ( V_151 L_42 ,
V_283 ) ;
}
if ( V_59 < V_283 )
V_59 = V_283 ;
V_60 = F_151 ( V_59 , sizeof( struct V_51 * ) ,
V_175 ) ;
if ( ! V_60 ) {
F_39 ( V_151 L_43 ) ;
V_68 = - V_118 ;
goto error;
}
V_284 = F_261 ( V_59 *
sizeof( struct V_285 ) , V_175 ) ;
if ( ! V_284 ) {
V_68 = - V_118 ;
goto V_286;
}
F_66 (iommu, drhd) {
V_60 [ V_52 -> V_173 ] = V_52 ;
V_68 = F_147 ( V_52 ) ;
if ( V_68 )
goto V_287;
V_68 = F_103 ( V_52 ) ;
if ( V_68 )
goto V_287;
if ( ! F_262 ( V_52 -> V_66 ) )
V_248 = 0 ;
}
F_66 (iommu, drhd)
F_254 ( V_52 ) ;
if ( V_288 )
V_262 |= V_270 ;
#ifdef F_263
V_262 |= V_269 ;
#endif
F_264 () ;
if ( V_262 ) {
V_68 = F_250 ( V_248 ) ;
if ( V_68 ) {
F_39 ( V_237 L_44 ) ;
goto V_287;
}
}
F_39 ( V_33 L_45 ) ;
F_239 (rmrr) {
F_79 (rmrr->devices, rmrr->devices_cnt,
i, dev) {
V_68 = F_225 ( V_254 , V_73 ) ;
if ( V_68 )
F_39 ( V_151
L_46 ) ;
}
}
F_226 () ;
F_265 (iommu, drhd) {
if ( V_62 -> V_289 ) {
if ( V_290 )
F_144 ( V_52 ) ;
continue;
}
F_111 ( V_52 ) ;
V_68 = F_266 ( V_52 ) ;
if ( V_68 )
goto V_287;
F_105 ( V_52 ) ;
V_52 -> V_162 . V_208 ( V_52 , 0 , 0 , 0 , V_137 ) ;
V_52 -> V_162 . V_163 ( V_52 , 0 , 0 , 0 , V_146 ) ;
F_145 ( V_52 ) ;
F_144 ( V_52 ) ;
}
return 0 ;
V_287:
F_66 (iommu, drhd) {
F_154 ( V_52 ) ;
F_158 ( V_52 ) ;
}
F_152 ( V_284 ) ;
V_286:
F_152 ( V_60 ) ;
error:
return V_68 ;
}
static struct V_184 * F_267 ( struct V_72 * V_73 ,
struct V_44 * V_45 ,
unsigned long V_291 , T_4 V_273 )
{
struct V_184 * V_184 = NULL ;
V_273 = F_3 ( T_4 , F_268 ( V_45 -> V_113 ) , V_273 ) ;
if ( ! V_35 && V_273 > F_269 ( 32 ) ) {
V_184 = F_270 ( & V_45 -> V_198 , V_291 ,
F_175 ( F_269 ( 32 ) ) , 1 ) ;
if ( V_184 )
return V_184 ;
}
V_184 = F_270 ( & V_45 -> V_198 , V_291 , F_175 ( V_273 ) , 1 ) ;
if ( F_189 ( ! V_184 ) ) {
F_39 ( V_151 L_47 ,
V_291 , F_222 ( V_73 ) ) ;
return NULL ;
}
return V_184 ;
}
static struct V_44 * F_271 ( struct V_72 * V_73 )
{
struct V_44 * V_45 ;
int V_68 ;
V_45 = F_219 ( V_73 , V_56 ) ;
if ( ! V_45 ) {
F_39 ( V_151 L_48 ,
F_222 ( V_73 ) ) ;
return NULL ;
}
if ( F_189 ( ! F_195 ( V_73 ) ) ) {
V_68 = F_192 ( V_45 , V_73 , V_204 ) ;
if ( V_68 ) {
F_39 ( V_151 L_49 ,
F_222 ( V_73 ) ) ;
return NULL ;
}
}
return V_45 ;
}
static inline struct V_44 * F_272 ( struct V_72 * V_73 )
{
struct V_152 * V_153 ;
V_153 = V_73 -> V_240 . V_52 ;
if ( F_235 ( V_153 ) )
return V_153 -> V_45 ;
return F_271 ( V_73 ) ;
}
static int F_273 ( struct V_72 * V_73 )
{
return V_73 -> V_240 . V_52 == V_255 ;
}
static int F_274 ( struct V_72 * V_73 )
{
int V_64 ;
if ( F_273 ( V_73 ) )
return 1 ;
if ( ! V_262 )
return 0 ;
V_64 = F_234 ( V_73 ) ;
if ( V_64 ) {
if ( F_241 ( V_73 , 0 ) )
return 1 ;
else {
F_237 ( V_247 , V_73 ) ;
F_39 ( V_33 L_50 ,
F_222 ( V_73 ) ) ;
return 0 ;
}
} else {
if ( F_241 ( V_73 , 0 ) ) {
int V_68 ;
V_68 = F_236 ( V_247 , V_73 ,
V_248 ?
V_203 :
V_204 ) ;
if ( ! V_68 ) {
F_39 ( V_33 L_51 ,
F_222 ( V_73 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_234 F_275 ( struct V_72 * V_73 , T_8 V_292 ,
T_7 V_90 , int V_293 , V_25 V_273 )
{
struct V_44 * V_45 ;
T_8 V_294 ;
struct V_184 * V_184 ;
int V_226 = 0 ;
int V_68 ;
struct V_51 * V_52 ;
unsigned long V_295 = V_292 >> V_11 ;
F_60 ( V_293 == V_296 ) ;
if ( F_274 ( V_73 ) )
return V_292 ;
V_45 = F_272 ( V_73 ) ;
if ( ! V_45 )
return 0 ;
V_52 = F_59 ( V_45 ) ;
V_90 = F_196 ( V_292 , V_90 ) ;
V_184 = F_267 ( V_73 , V_45 , F_12 ( V_90 ) , V_273 ) ;
if ( ! V_184 )
goto error;
if ( V_293 == V_297 || V_293 == V_298 || \
! F_276 ( V_52 -> V_55 ) )
V_226 |= V_103 ;
if ( V_293 == V_299 || V_293 == V_298 )
V_226 |= V_104 ;
V_68 = F_207 ( V_45 , F_13 ( V_184 -> V_300 ) ,
F_13 ( V_295 ) , V_90 , V_226 ) ;
if ( V_68 )
goto error;
if ( F_143 ( V_52 -> V_55 ) )
F_138 ( V_52 , V_45 -> V_178 , F_13 ( V_184 -> V_300 ) , V_90 , 0 , 1 ) ;
else
F_111 ( V_52 ) ;
V_294 = ( T_8 ) V_184 -> V_300 << V_11 ;
V_294 += V_292 & ~ V_215 ;
return V_294 ;
error:
if ( V_184 )
F_277 ( & V_45 -> V_198 , V_184 ) ;
F_39 ( V_151 L_52 ,
F_222 ( V_73 ) , V_90 , ( unsigned long long ) V_292 , V_293 ) ;
return 0 ;
}
static V_234 F_278 ( struct V_72 * V_73 , struct V_14 * V_14 ,
unsigned long V_97 , T_7 V_90 ,
enum V_301 V_293 ,
struct V_302 * V_303 )
{
return F_275 ( V_73 , F_200 ( V_14 ) + V_97 , V_90 ,
V_293 , * V_73 -> V_273 ) ;
}
static void F_279 ( void )
{
int V_63 , V_304 ;
V_305 = 0 ;
for ( V_63 = 0 ; V_63 < V_59 ; V_63 ++ ) {
struct V_51 * V_52 = V_60 [ V_63 ] ;
if ( ! V_52 )
continue;
if ( ! V_284 [ V_63 ] . V_112 )
continue;
if ( ! F_143 ( V_52 -> V_55 ) )
V_52 -> V_162 . V_163 ( V_52 , 0 , 0 , 0 ,
V_146 ) ;
for ( V_304 = 0 ; V_304 < V_284 [ V_63 ] . V_112 ; V_304 ++ ) {
unsigned long V_69 ;
struct V_184 * V_184 = V_284 [ V_63 ] . V_184 [ V_304 ] ;
struct V_44 * V_45 = V_284 [ V_63 ] . V_45 [ V_304 ] ;
if ( F_143 ( V_52 -> V_55 ) )
F_138 ( V_52 , V_45 -> V_178 ,
V_184 -> V_300 , F_280 ( V_184 ) ,
! V_284 [ V_63 ] . V_114 [ V_304 ] , 0 ) ;
else {
V_69 = F_139 ( F_13 ( F_280 ( V_184 ) ) ) ;
F_135 ( V_284 [ V_63 ] . V_45 [ V_304 ] ,
( T_4 ) V_184 -> V_300 << V_11 , V_69 ) ;
}
F_277 ( & V_284 [ V_63 ] . V_45 [ V_304 ] -> V_198 , V_184 ) ;
if ( V_284 [ V_63 ] . V_114 [ V_304 ] )
F_102 ( V_284 [ V_63 ] . V_114 [ V_304 ] ) ;
}
V_284 [ V_63 ] . V_112 = 0 ;
}
V_306 = 0 ;
}
static void F_183 ( unsigned long V_213 )
{
unsigned long V_46 ;
F_83 ( & V_307 , V_46 ) ;
F_279 () ;
F_84 ( & V_307 , V_46 ) ;
}
static void F_281 ( struct V_44 * V_308 , struct V_184 * V_184 , struct V_14 * V_114 )
{
unsigned long V_46 ;
int V_112 , V_57 ;
struct V_51 * V_52 ;
F_83 ( & V_307 , V_46 ) ;
if ( V_306 == V_309 )
F_279 () ;
V_52 = F_59 ( V_308 ) ;
V_57 = V_52 -> V_173 ;
V_112 = V_284 [ V_57 ] . V_112 ;
V_284 [ V_57 ] . V_45 [ V_112 ] = V_308 ;
V_284 [ V_57 ] . V_184 [ V_112 ] = V_184 ;
V_284 [ V_57 ] . V_114 [ V_112 ] = V_114 ;
V_284 [ V_57 ] . V_112 ++ ;
if ( ! V_305 ) {
F_282 ( & V_310 , V_311 + F_283 ( 10 ) ) ;
V_305 = 1 ;
}
V_306 ++ ;
F_84 ( & V_307 , V_46 ) ;
}
static void F_284 ( struct V_72 * V_73 , V_234 V_312 )
{
struct V_44 * V_45 ;
unsigned long V_107 , V_108 ;
struct V_184 * V_184 ;
struct V_51 * V_52 ;
struct V_14 * V_114 ;
if ( F_274 ( V_73 ) )
return;
V_45 = F_214 ( V_73 ) ;
F_60 ( ! V_45 ) ;
V_52 = F_59 ( V_45 ) ;
V_184 = F_285 ( & V_45 -> V_198 , F_175 ( V_312 ) ) ;
if ( F_286 ( ! V_184 , L_53 ,
( unsigned long long ) V_312 ) )
return;
V_107 = F_13 ( V_184 -> V_300 ) ;
V_108 = F_13 ( V_184 -> V_313 + 1 ) - 1 ;
F_124 ( L_54 ,
F_222 ( V_73 ) , V_107 , V_108 ) ;
V_114 = F_101 ( V_45 , V_107 , V_108 ) ;
if ( V_36 ) {
F_138 ( V_52 , V_45 -> V_178 , V_107 ,
V_108 - V_107 + 1 , ! V_114 , 0 ) ;
F_277 ( & V_45 -> V_198 , V_184 ) ;
F_102 ( V_114 ) ;
} else {
F_281 ( V_45 , V_184 , V_114 ) ;
}
}
static void F_287 ( struct V_72 * V_73 , V_234 V_312 ,
T_7 V_90 , enum V_301 V_293 ,
struct V_302 * V_303 )
{
F_284 ( V_73 , V_312 ) ;
}
static void * F_288 ( struct V_72 * V_73 , T_7 V_90 ,
V_234 * V_314 , T_9 V_46 ,
struct V_302 * V_303 )
{
struct V_14 * V_14 = NULL ;
int V_315 ;
V_90 = F_197 ( V_90 ) ;
V_315 = F_289 ( V_90 ) ;
if ( ! F_274 ( V_73 ) )
V_46 &= ~ ( V_316 | V_317 ) ;
else if ( V_73 -> V_274 < F_247 ( V_73 ) ) {
if ( V_73 -> V_274 < F_269 ( 32 ) )
V_46 |= V_316 ;
else
V_46 |= V_317 ;
}
if ( V_46 & V_318 ) {
unsigned int V_182 = V_90 >> V_11 ;
V_14 = F_290 ( V_73 , V_182 , V_315 ) ;
if ( V_14 && F_274 ( V_73 ) &&
F_200 ( V_14 ) + V_90 > V_73 -> V_274 ) {
F_291 ( V_73 , V_14 , V_182 ) ;
V_14 = NULL ;
}
}
if ( ! V_14 )
V_14 = F_292 ( V_46 , V_315 ) ;
if ( ! V_14 )
return NULL ;
memset ( F_42 ( V_14 ) , 0 , V_90 ) ;
* V_314 = F_275 ( V_73 , F_200 ( V_14 ) , V_90 ,
V_298 ,
V_73 -> V_274 ) ;
if ( * V_314 )
return F_42 ( V_14 ) ;
if ( ! F_291 ( V_73 , V_14 , V_90 >> V_11 ) )
F_293 ( V_14 , V_315 ) ;
return NULL ;
}
static void F_294 ( struct V_72 * V_73 , T_7 V_90 , void * V_39 ,
V_234 V_314 , struct V_302 * V_303 )
{
int V_315 ;
struct V_14 * V_14 = F_17 ( V_39 ) ;
V_90 = F_197 ( V_90 ) ;
V_315 = F_289 ( V_90 ) ;
F_284 ( V_73 , V_314 ) ;
if ( ! F_291 ( V_73 , V_14 , V_90 >> V_11 ) )
F_293 ( V_14 , V_315 ) ;
}
static void F_295 ( struct V_72 * V_73 , struct V_222 * V_319 ,
int V_320 , enum V_301 V_293 ,
struct V_302 * V_303 )
{
F_284 ( V_73 , V_319 [ 0 ] . V_233 ) ;
}
static int F_296 ( struct V_72 * V_321 ,
struct V_222 * V_319 , int V_320 , int V_293 )
{
int V_63 ;
struct V_222 * V_223 ;
F_297 (sglist, sg, nelems, i) {
F_60 ( ! F_201 ( V_223 ) ) ;
V_223 -> V_233 = F_200 ( F_201 ( V_223 ) ) + V_223 -> V_97 ;
V_223 -> V_235 = V_223 -> V_232 ;
}
return V_320 ;
}
static int F_298 ( struct V_72 * V_73 , struct V_222 * V_319 , int V_320 ,
enum V_301 V_293 , struct V_302 * V_303 )
{
int V_63 ;
struct V_44 * V_45 ;
T_7 V_90 = 0 ;
int V_226 = 0 ;
struct V_184 * V_184 = NULL ;
int V_68 ;
struct V_222 * V_223 ;
unsigned long V_322 ;
struct V_51 * V_52 ;
F_60 ( V_293 == V_296 ) ;
if ( F_274 ( V_73 ) )
return F_296 ( V_73 , V_319 , V_320 , V_293 ) ;
V_45 = F_272 ( V_73 ) ;
if ( ! V_45 )
return 0 ;
V_52 = F_59 ( V_45 ) ;
F_297 (sglist, sg, nelems, i)
V_90 += F_196 ( V_223 -> V_97 , V_223 -> V_232 ) ;
V_184 = F_267 ( V_73 , V_45 , F_12 ( V_90 ) ,
* V_73 -> V_273 ) ;
if ( ! V_184 ) {
V_319 -> V_235 = 0 ;
return 0 ;
}
if ( V_293 == V_297 || V_293 == V_298 || \
! F_276 ( V_52 -> V_55 ) )
V_226 |= V_103 ;
if ( V_293 == V_299 || V_293 == V_298 )
V_226 |= V_104 ;
V_322 = F_13 ( V_184 -> V_300 ) ;
V_68 = F_206 ( V_45 , V_322 , V_319 , V_90 , V_226 ) ;
if ( F_189 ( V_68 ) ) {
F_96 ( V_45 , V_322 ,
V_322 + V_90 - 1 ) ;
F_277 ( & V_45 -> V_198 , V_184 ) ;
return 0 ;
}
if ( F_143 ( V_52 -> V_55 ) )
F_138 ( V_52 , V_45 -> V_178 , V_322 , V_90 , 0 , 1 ) ;
else
F_111 ( V_52 ) ;
return V_320 ;
}
static int F_299 ( struct V_72 * V_73 , V_234 V_323 )
{
return ! V_323 ;
}
static inline int F_300 ( void )
{
int V_68 = 0 ;
V_42 = F_301 ( L_55 ,
sizeof( struct V_44 ) ,
0 ,
V_324 ,
NULL ) ;
if ( ! V_42 ) {
F_39 ( V_151 L_56 ) ;
V_68 = - V_118 ;
}
return V_68 ;
}
static inline int F_302 ( void )
{
int V_68 = 0 ;
V_43 = F_301 ( L_57 ,
sizeof( struct V_152 ) ,
0 ,
V_324 ,
NULL ) ;
if ( ! V_43 ) {
F_39 ( V_151 L_58 ) ;
V_68 = - V_118 ;
}
return V_68 ;
}
static int T_1 F_303 ( void )
{
int V_68 ;
V_68 = F_304 () ;
if ( V_68 )
return V_68 ;
V_68 = F_300 () ;
if ( V_68 )
goto V_325;
V_68 = F_302 () ;
if ( ! V_68 )
return V_68 ;
F_305 ( V_42 ) ;
V_325:
F_306 () ;
return - V_118 ;
}
static void T_1 F_307 ( void )
{
F_305 ( V_43 ) ;
F_305 ( V_42 ) ;
F_306 () ;
}
static void F_308 ( struct V_77 * V_79 )
{
struct V_61 * V_62 ;
T_5 V_326 ;
int V_327 ;
V_327 = F_309 ( V_79 -> V_74 , F_310 ( 0 , 0 ) , 0xb0 , & V_326 ) ;
if ( V_327 ) {
F_311 ( & V_79 -> V_73 , L_59 ) ;
return;
}
V_326 &= 0xffff0000 ;
V_62 = F_312 ( V_79 ) ;
if ( F_313 ( ! V_62 || V_62 -> V_328 - V_326 != 0xa000 ,
V_329 ,
L_60 ) )
V_79 -> V_73 . V_240 . V_52 = V_255 ;
}
static void T_1 F_314 ( void )
{
struct V_61 * V_62 ;
struct V_72 * V_73 ;
int V_63 ;
F_259 (drhd) {
if ( ! V_62 -> V_88 ) {
F_79 (drhd->devices,
drhd->devices_cnt, i, dev)
break;
if ( V_63 == V_62 -> V_330 )
V_62 -> V_289 = 1 ;
}
}
F_315 (drhd) {
if ( V_62 -> V_88 )
continue;
F_79 (drhd->devices,
drhd->devices_cnt, i, dev)
if ( ! F_75 ( V_73 ) || ! F_243 ( F_76 ( V_73 ) ) )
break;
if ( V_63 < V_62 -> V_330 )
continue;
if ( V_34 ) {
V_331 = 1 ;
} else {
V_62 -> V_289 = 1 ;
F_79 (drhd->devices,
drhd->devices_cnt, i, dev)
V_73 -> V_240 . V_52 = V_255 ;
}
}
}
static int F_316 ( void )
{
struct V_61 * V_62 ;
struct V_51 * V_52 = NULL ;
F_66 (iommu, drhd)
if ( V_52 -> V_154 )
F_317 ( V_52 ) ;
F_265 (iommu, drhd) {
if ( V_62 -> V_289 ) {
if ( V_290 )
F_144 ( V_52 ) ;
continue;
}
F_111 ( V_52 ) ;
F_105 ( V_52 ) ;
V_52 -> V_162 . V_208 ( V_52 , 0 , 0 , 0 ,
V_137 ) ;
V_52 -> V_162 . V_163 ( V_52 , 0 , 0 , 0 , V_146 ) ;
F_145 ( V_52 ) ;
F_144 ( V_52 ) ;
}
return 0 ;
}
static void F_318 ( void )
{
struct V_61 * V_62 ;
struct V_51 * V_52 ;
F_66 (iommu, drhd) {
V_52 -> V_162 . V_208 ( V_52 , 0 , 0 , 0 ,
V_137 ) ;
V_52 -> V_162 . V_163 ( V_52 , 0 , 0 , 0 ,
V_146 ) ;
}
}
static int F_319 ( void )
{
struct V_61 * V_62 ;
struct V_51 * V_52 = NULL ;
unsigned long V_121 ;
F_66 (iommu, drhd) {
V_52 -> V_332 = F_261 ( sizeof( T_5 ) * V_333 ,
V_40 ) ;
if ( ! V_52 -> V_332 )
goto V_334;
}
F_318 () ;
F_66 (iommu, drhd) {
F_146 ( V_52 ) ;
F_106 ( & V_52 -> V_122 , V_121 ) ;
V_52 -> V_332 [ V_335 ] =
V_129 ( V_52 -> V_123 + V_336 ) ;
V_52 -> V_332 [ V_337 ] =
V_129 ( V_52 -> V_123 + V_338 ) ;
V_52 -> V_332 [ V_339 ] =
V_129 ( V_52 -> V_123 + V_340 ) ;
V_52 -> V_332 [ V_341 ] =
V_129 ( V_52 -> V_123 + V_342 ) ;
F_110 ( & V_52 -> V_122 , V_121 ) ;
}
return 0 ;
V_334:
F_66 (iommu, drhd)
F_152 ( V_52 -> V_332 ) ;
return - V_118 ;
}
static void F_320 ( void )
{
struct V_61 * V_62 ;
struct V_51 * V_52 = NULL ;
unsigned long V_121 ;
if ( F_316 () ) {
if ( V_290 )
F_321 ( L_61 ) ;
else
F_223 ( 1 , L_62 ) ;
return;
}
F_66 (iommu, drhd) {
F_106 ( & V_52 -> V_122 , V_121 ) ;
F_108 ( V_52 -> V_332 [ V_335 ] ,
V_52 -> V_123 + V_336 ) ;
F_108 ( V_52 -> V_332 [ V_337 ] ,
V_52 -> V_123 + V_338 ) ;
F_108 ( V_52 -> V_332 [ V_339 ] ,
V_52 -> V_123 + V_340 ) ;
F_108 ( V_52 -> V_332 [ V_341 ] ,
V_52 -> V_123 + V_342 ) ;
F_110 ( & V_52 -> V_122 , V_121 ) ;
}
F_66 (iommu, drhd)
F_152 ( V_52 -> V_332 ) ;
}
static void T_1 F_322 ( void )
{
F_323 ( & V_343 ) ;
}
static inline void F_322 ( void ) {}
int T_1 F_324 ( struct V_344 * V_345 , void * V_346 )
{
struct V_347 * V_254 ;
struct V_253 * V_348 ;
V_348 = F_261 ( sizeof( * V_348 ) , V_175 ) ;
if ( ! V_348 )
return - V_118 ;
V_348 -> V_349 = V_345 ;
V_254 = (struct V_347 * ) V_345 ;
V_348 -> V_256 = V_254 -> V_256 ;
V_348 -> V_257 = V_254 -> V_257 ;
V_348 -> V_81 = F_325 ( ( void * ) ( V_254 + 1 ) ,
( ( void * ) V_254 ) + V_254 -> V_345 . V_232 ,
& V_348 -> V_330 ) ;
if ( V_348 -> V_330 && V_348 -> V_81 == NULL ) {
F_152 ( V_348 ) ;
return - V_118 ;
}
F_217 ( & V_348 -> V_350 , & V_351 ) ;
return 0 ;
}
static struct V_352 * F_326 ( struct V_353 * V_354 )
{
struct V_352 * V_355 ;
struct V_353 * V_76 ;
F_327 (atsru, &dmar_atsr_units, list) {
V_76 = (struct V_353 * ) V_355 -> V_349 ;
if ( V_354 -> V_80 != V_76 -> V_80 )
continue;
if ( V_354 -> V_345 . V_232 != V_76 -> V_345 . V_232 )
continue;
if ( memcmp ( V_354 , V_76 , V_354 -> V_345 . V_232 ) == 0 )
return V_355 ;
}
return NULL ;
}
int F_328 ( struct V_344 * V_349 , void * V_346 )
{
struct V_353 * V_354 ;
struct V_352 * V_355 ;
if ( V_356 != V_357 && ! V_358 )
return 0 ;
V_354 = F_329 ( V_349 , struct V_353 , V_345 ) ;
V_355 = F_326 ( V_354 ) ;
if ( V_355 )
return 0 ;
V_355 = F_261 ( sizeof( * V_355 ) + V_349 -> V_232 , V_175 ) ;
if ( ! V_355 )
return - V_118 ;
V_355 -> V_349 = ( void * ) ( V_355 + 1 ) ;
memcpy ( V_355 -> V_349 , V_349 , V_349 -> V_232 ) ;
V_355 -> V_88 = V_354 -> V_46 & 0x1 ;
if ( ! V_355 -> V_88 ) {
V_355 -> V_81 = F_325 ( ( void * ) ( V_354 + 1 ) ,
( void * ) V_354 + V_354 -> V_345 . V_232 ,
& V_355 -> V_330 ) ;
if ( V_355 -> V_330 && V_355 -> V_81 == NULL ) {
F_152 ( V_355 ) ;
return - V_118 ;
}
}
F_330 ( & V_355 -> V_350 , & V_359 ) ;
return 0 ;
}
static void F_331 ( struct V_352 * V_355 )
{
F_332 ( & V_355 -> V_81 , & V_355 -> V_330 ) ;
F_152 ( V_355 ) ;
}
int F_333 ( struct V_344 * V_349 , void * V_346 )
{
struct V_353 * V_354 ;
struct V_352 * V_355 ;
V_354 = F_329 ( V_349 , struct V_353 , V_345 ) ;
V_355 = F_326 ( V_354 ) ;
if ( V_355 ) {
F_334 ( & V_355 -> V_350 ) ;
F_335 () ;
F_331 ( V_355 ) ;
}
return 0 ;
}
int F_336 ( struct V_344 * V_349 , void * V_346 )
{
int V_63 ;
struct V_72 * V_73 ;
struct V_353 * V_354 ;
struct V_352 * V_355 ;
V_354 = F_329 ( V_349 , struct V_353 , V_345 ) ;
V_355 = F_326 ( V_354 ) ;
if ( ! V_355 )
return 0 ;
if ( ! V_355 -> V_88 && V_355 -> V_81 && V_355 -> V_330 )
F_79 (atsru->devices, atsru->devices_cnt,
i, dev)
return - V_264 ;
return 0 ;
}
static int F_337 ( struct V_61 * V_360 )
{
int V_361 , V_68 = 0 ;
struct V_51 * V_52 = V_360 -> V_52 ;
if ( V_60 [ V_52 -> V_173 ] )
return 0 ;
if ( V_248 && ! F_262 ( V_52 -> V_66 ) ) {
F_338 ( L_63 ,
V_52 -> V_117 ) ;
return - V_362 ;
}
if ( ! F_69 ( V_52 -> V_66 ) &&
F_68 ( V_52 ) ) {
F_338 ( L_64 ,
V_52 -> V_117 ) ;
return - V_362 ;
}
V_361 = F_70 ( V_52 ) - 1 ;
if ( V_361 >= 0 && ! ( F_71 ( V_52 -> V_55 ) & ( 1 << V_361 ) ) ) {
F_338 ( L_65 ,
V_52 -> V_117 ) ;
return - V_362 ;
}
if ( V_52 -> V_125 & V_169 )
F_146 ( V_52 ) ;
V_60 [ V_52 -> V_173 ] = V_52 ;
V_68 = F_147 ( V_52 ) ;
if ( V_68 == 0 )
V_68 = F_103 ( V_52 ) ;
if ( V_68 )
goto V_82;
if ( V_360 -> V_289 ) {
if ( V_290 )
F_144 ( V_52 ) ;
return 0 ;
}
F_254 ( V_52 ) ;
F_111 ( V_52 ) ;
V_68 = F_266 ( V_52 ) ;
if ( V_68 )
goto V_363;
F_105 ( V_52 ) ;
V_52 -> V_162 . V_208 ( V_52 , 0 , 0 , 0 , V_137 ) ;
V_52 -> V_162 . V_163 ( V_52 , 0 , 0 , 0 , V_146 ) ;
F_145 ( V_52 ) ;
if ( V_247 ) {
V_68 = F_165 ( V_247 , V_52 ) ;
if ( V_68 < 0 || V_247 -> V_178 != V_68 )
goto V_363;
F_168 ( V_247 , V_52 ) ;
}
F_144 ( V_52 ) ;
return 0 ;
V_363:
F_154 ( V_52 ) ;
V_82:
F_158 ( V_52 ) ;
return V_68 ;
}
int F_339 ( struct V_61 * V_360 , bool V_364 )
{
int V_68 = 0 ;
struct V_51 * V_52 = V_360 -> V_52 ;
if ( ! V_358 )
return 0 ;
if ( V_52 == NULL )
return - V_31 ;
if ( V_364 ) {
V_68 = F_337 ( V_360 ) ;
} else {
F_154 ( V_52 ) ;
F_158 ( V_52 ) ;
}
return V_68 ;
}
static void F_340 ( void )
{
struct V_253 * V_348 , * V_365 ;
struct V_352 * V_355 , * V_366 ;
F_212 (rmrru, rmrr_n, &dmar_rmrr_units, list) {
F_211 ( & V_348 -> V_350 ) ;
F_332 ( & V_348 -> V_81 , & V_348 -> V_330 ) ;
F_152 ( V_348 ) ;
}
F_212 (atsru, atsr_n, &dmar_atsr_units, list) {
F_211 ( & V_355 -> V_350 ) ;
F_331 ( V_355 ) ;
}
}
int F_129 ( struct V_77 * V_73 )
{
int V_63 , V_68 = 1 ;
struct V_367 * V_74 ;
struct V_77 * V_368 = NULL ;
struct V_72 * V_76 ;
struct V_353 * V_354 ;
struct V_352 * V_355 ;
V_73 = F_341 ( V_73 ) ;
for ( V_74 = V_73 -> V_74 ; V_74 ; V_74 = V_74 -> V_96 ) {
V_368 = V_74 -> V_369 ;
if ( ! V_368 || ! F_244 ( V_368 ) ||
F_246 ( V_368 ) == V_272 )
return 0 ;
if ( F_246 ( V_368 ) == V_370 )
break;
}
if ( ! V_368 )
return 0 ;
F_65 () ;
F_327 (atsru, &dmar_atsr_units, list) {
V_354 = F_329 ( V_355 -> V_349 , struct V_353 , V_345 ) ;
if ( V_354 -> V_80 != F_77 ( V_73 -> V_74 ) )
continue;
F_342 (atsru->devices, atsru->devices_cnt, i, tmp)
if ( V_76 == & V_368 -> V_73 )
goto V_82;
if ( V_355 -> V_88 )
goto V_82;
}
V_68 = 0 ;
V_82:
F_67 () ;
return V_68 ;
}
int F_343 ( struct V_371 * V_153 )
{
int V_68 = 0 ;
struct V_253 * V_348 ;
struct V_352 * V_355 ;
struct V_353 * V_354 ;
struct V_347 * V_254 ;
if ( ! V_358 && V_356 != V_357 )
return 0 ;
F_127 (rmrru, &dmar_rmrr_units, list) {
V_254 = F_329 ( V_348 -> V_349 ,
struct V_347 , V_345 ) ;
if ( V_153 -> V_372 == V_373 ) {
V_68 = F_344 ( V_153 , ( void * ) ( V_254 + 1 ) ,
( ( void * ) V_254 ) + V_254 -> V_345 . V_232 ,
V_254 -> V_80 , V_348 -> V_81 ,
V_348 -> V_330 ) ;
if( V_68 < 0 )
return V_68 ;
} else if ( V_153 -> V_372 == V_374 ) {
F_345 ( V_153 , V_254 -> V_80 ,
V_348 -> V_81 , V_348 -> V_330 ) ;
}
}
F_127 (atsru, &dmar_atsr_units, list) {
if ( V_355 -> V_88 )
continue;
V_354 = F_329 ( V_355 -> V_349 , struct V_353 , V_345 ) ;
if ( V_153 -> V_372 == V_373 ) {
V_68 = F_344 ( V_153 , ( void * ) ( V_354 + 1 ) ,
( void * ) V_354 + V_354 -> V_345 . V_232 ,
V_354 -> V_80 , V_355 -> V_81 ,
V_355 -> V_330 ) ;
if ( V_68 > 0 )
break;
else if( V_68 < 0 )
return V_68 ;
} else if ( V_153 -> V_372 == V_374 ) {
if ( F_345 ( V_153 , V_354 -> V_80 ,
V_355 -> V_81 , V_355 -> V_330 ) )
break;
}
}
return 0 ;
}
static int F_346 ( struct V_375 * V_376 ,
unsigned long V_377 , void * V_213 )
{
struct V_72 * V_73 = V_213 ;
struct V_44 * V_45 ;
if ( F_273 ( V_73 ) )
return 0 ;
if ( V_377 != V_378 )
return 0 ;
V_45 = F_214 ( V_73 ) ;
if ( ! V_45 )
return 0 ;
F_347 ( & V_379 ) ;
F_237 ( V_45 , V_73 ) ;
if ( ! F_52 ( V_45 ) && F_348 ( & V_45 -> V_81 ) )
F_157 ( V_45 ) ;
F_349 ( & V_379 ) ;
return 0 ;
}
static int F_350 ( struct V_375 * V_376 ,
unsigned long V_19 , void * V_380 )
{
struct V_381 * V_382 = V_380 ;
unsigned long long V_197 , V_86 ;
unsigned long V_322 , V_246 ;
switch ( V_19 ) {
case V_383 :
V_197 = V_382 -> V_107 << V_11 ;
V_86 = ( ( V_382 -> V_107 + V_382 -> V_225 ) << V_11 ) - 1 ;
if ( F_220 ( V_247 , V_197 , V_86 ) ) {
F_338 ( L_66 ,
V_197 , V_86 ) ;
return V_384 ;
}
break;
case V_385 :
case V_386 :
V_322 = F_13 ( V_382 -> V_107 ) ;
V_246 = F_13 ( V_382 -> V_107 + V_382 -> V_225 - 1 ) ;
while ( V_322 <= V_246 ) {
struct V_184 * V_184 ;
struct V_61 * V_62 ;
struct V_51 * V_52 ;
struct V_14 * V_114 ;
V_184 = F_285 ( & V_247 -> V_198 , V_322 ) ;
if ( V_184 == NULL ) {
F_124 ( L_67 ,
V_322 ) ;
break;
}
V_184 = F_351 ( & V_247 -> V_198 , V_184 ,
V_322 , V_246 ) ;
if ( V_184 == NULL ) {
F_338 ( L_68 ,
V_322 , V_246 ) ;
return V_384 ;
}
V_114 = F_101 ( V_247 , V_184 -> V_300 ,
V_184 -> V_313 ) ;
F_65 () ;
F_66 (iommu, drhd)
F_138 ( V_52 , V_247 -> V_178 ,
V_184 -> V_300 , F_280 ( V_184 ) ,
! V_114 , 0 ) ;
F_67 () ;
F_102 ( V_114 ) ;
V_322 = V_184 -> V_313 + 1 ;
F_352 ( V_184 ) ;
}
break;
}
return V_387 ;
}
static T_10 F_353 ( struct V_72 * V_73 ,
struct V_388 * V_389 ,
char * V_390 )
{
struct V_51 * V_52 = F_354 ( V_73 ) ;
T_5 V_391 = V_129 ( V_52 -> V_123 + V_392 ) ;
return sprintf ( V_390 , L_69 ,
F_355 ( V_391 ) , F_356 ( V_391 ) ) ;
}
static T_10 F_357 ( struct V_72 * V_73 ,
struct V_388 * V_389 ,
char * V_390 )
{
struct V_51 * V_52 = F_354 ( V_73 ) ;
return sprintf ( V_390 , L_70 , V_52 -> V_393 ) ;
}
static T_10 F_358 ( struct V_72 * V_73 ,
struct V_388 * V_389 ,
char * V_390 )
{
struct V_51 * V_52 = F_354 ( V_73 ) ;
return sprintf ( V_390 , L_70 , V_52 -> V_55 ) ;
}
static T_10 F_359 ( struct V_72 * V_73 ,
struct V_388 * V_389 ,
char * V_390 )
{
struct V_51 * V_52 = F_354 ( V_73 ) ;
return sprintf ( V_390 , L_70 , V_52 -> V_66 ) ;
}
int T_1 F_360 ( void )
{
int V_68 = - V_192 ;
struct V_61 * V_62 ;
struct V_51 * V_52 ;
V_290 = F_361 () ;
if ( F_303 () ) {
if ( V_290 )
F_321 ( L_71 ) ;
return - V_118 ;
}
F_362 ( & V_379 ) ;
if ( F_363 () ) {
if ( V_290 )
F_321 ( L_72 ) ;
goto V_394;
}
F_66 (iommu, drhd)
if ( V_52 -> V_125 & V_169 )
F_146 ( V_52 ) ;
if ( F_364 () < 0 ) {
if ( V_290 )
F_321 ( L_73 ) ;
goto V_394;
}
if ( V_395 || V_32 )
goto V_394;
if ( F_348 ( & V_351 ) )
F_39 ( V_33 L_74 ) ;
if ( F_348 ( & V_359 ) )
F_39 ( V_33 L_75 ) ;
if ( F_171 () ) {
if ( V_290 )
F_321 ( L_76 ) ;
goto V_396;
}
F_314 () ;
V_68 = F_258 () ;
if ( V_68 ) {
if ( V_290 )
F_321 ( L_77 ) ;
F_39 ( V_151 L_78 ) ;
goto V_396;
}
F_365 ( & V_379 ) ;
F_39 ( V_33
L_79 ) ;
F_366 ( & V_310 ) ;
#ifdef F_367
V_397 = 0 ;
#endif
V_398 = & V_399 ;
F_322 () ;
F_66 (iommu, drhd)
V_52 -> V_400 = F_368 ( NULL , V_52 ,
V_401 ,
V_52 -> V_117 ) ;
F_369 ( & V_402 , & V_403 ) ;
F_370 ( & V_402 , & V_404 ) ;
if ( V_247 && ! V_248 )
F_371 ( & V_405 ) ;
V_358 = 1 ;
return 0 ;
V_396:
F_185 ( & V_185 ) ;
V_394:
F_340 () ;
F_365 ( & V_379 ) ;
F_307 () ;
return V_68 ;
}
static int F_372 ( struct V_77 * V_79 , T_3 V_210 , void * V_211 )
{
struct V_51 * V_52 = V_211 ;
F_208 ( V_52 , F_191 ( V_210 ) , V_210 & 0xff ) ;
return 0 ;
}
static void F_213 ( struct V_51 * V_52 ,
struct V_72 * V_73 )
{
if ( ! V_52 || ! V_73 || ! F_75 ( V_73 ) )
return;
F_193 ( F_76 ( V_73 ) , & F_372 , V_52 ) ;
}
static void F_237 ( struct V_44 * V_45 ,
struct V_72 * V_73 )
{
struct V_152 * V_153 , * V_76 ;
struct V_51 * V_52 ;
unsigned long V_46 ;
int V_64 = 0 ;
T_2 V_74 , V_75 ;
V_52 = F_74 ( V_73 , & V_74 , & V_75 ) ;
if ( ! V_52 )
return;
F_83 ( & V_155 , V_46 ) ;
F_212 (info, tmp, &domain->devices, link) {
if ( V_153 -> V_52 == V_52 && V_153 -> V_74 == V_74 &&
V_153 -> V_75 == V_75 ) {
F_209 ( V_153 ) ;
F_84 ( & V_155 , V_46 ) ;
F_132 ( V_153 ) ;
F_208 ( V_52 , V_153 -> V_74 , V_153 -> V_75 ) ;
F_213 ( V_52 , V_73 ) ;
F_50 ( V_153 ) ;
F_83 ( & V_155 , V_46 ) ;
if ( V_64 )
break;
else
continue;
}
if ( V_153 -> V_52 == V_52 )
V_64 = 1 ;
}
F_84 ( & V_155 , V_46 ) ;
if ( V_64 == 0 ) {
F_156 ( V_45 , V_52 ) ;
if ( ! F_52 ( V_45 ) )
F_167 ( V_45 , V_52 ) ;
}
}
static int F_230 ( struct V_44 * V_45 , int V_199 )
{
int V_200 ;
F_172 ( & V_45 -> V_198 , V_102 , V_186 ,
V_187 ) ;
F_177 ( V_45 ) ;
V_45 -> V_113 = V_199 ;
V_200 = F_179 ( V_199 ) ;
V_45 -> V_1 = F_4 ( V_200 ) ;
V_45 -> V_65 = 0 ;
V_45 -> V_70 = 0 ;
V_45 -> V_71 = 0 ;
V_45 -> V_406 = 0 ;
V_45 -> V_98 = (struct V_27 * ) F_40 ( V_45 -> V_101 ) ;
if ( ! V_45 -> V_98 )
return - V_118 ;
F_80 ( V_45 , V_45 -> V_98 , V_201 ) ;
return 0 ;
}
static int F_373 ( struct V_407 * V_45 )
{
struct V_44 * V_44 ;
V_44 = F_159 ( V_47 ) ;
if ( ! V_44 ) {
F_39 ( V_151
L_80 ) ;
return - V_118 ;
}
if ( F_230 ( V_44 , V_56 ) ) {
F_39 ( V_151
L_81 ) ;
F_157 ( V_44 ) ;
return - V_118 ;
}
F_73 ( V_44 ) ;
V_45 -> V_408 = V_44 ;
V_45 -> V_409 . V_410 = 0 ;
V_45 -> V_409 . V_411 = F_374 ( V_44 -> V_113 ) ;
V_45 -> V_409 . V_412 = true ;
return 0 ;
}
static void F_375 ( struct V_407 * V_45 )
{
struct V_44 * V_44 = V_45 -> V_408 ;
V_45 -> V_408 = NULL ;
F_157 ( V_44 ) ;
}
static int F_376 ( struct V_407 * V_45 ,
struct V_72 * V_73 )
{
struct V_44 * V_44 = V_45 -> V_408 ;
struct V_51 * V_52 ;
int V_49 ;
T_2 V_74 , V_75 ;
if ( F_240 ( V_73 ) ) {
F_377 ( V_73 , L_82 ) ;
return - V_413 ;
}
if ( F_189 ( F_195 ( V_73 ) ) ) {
struct V_44 * V_414 ;
V_414 = F_214 ( V_73 ) ;
if ( V_414 ) {
if ( F_52 ( V_44 ) )
F_237 ( V_414 , V_73 ) ;
else
F_184 ( V_414 ) ;
if ( ! F_52 ( V_414 ) &&
F_348 ( & V_414 -> V_81 ) )
F_157 ( V_414 ) ;
}
}
V_52 = F_74 ( V_73 , & V_74 , & V_75 ) ;
if ( ! V_52 )
return - V_192 ;
V_49 = F_2 ( V_52 -> V_1 ) ;
if ( V_49 > F_181 ( V_52 -> V_55 ) )
V_49 = F_181 ( V_52 -> V_55 ) ;
if ( V_44 -> V_406 > ( 1LL << V_49 ) ) {
F_39 ( V_151 L_83
L_84 ,
V_415 , V_49 , V_44 -> V_406 ) ;
return - V_205 ;
}
V_44 -> V_113 = V_49 ;
while ( V_52 -> V_1 < V_44 -> V_1 ) {
struct V_27 * V_28 ;
V_28 = V_44 -> V_98 ;
if ( F_35 ( V_28 ) ) {
V_44 -> V_98 = (struct V_27 * )
F_22 ( F_32 ( V_28 ) ) ;
F_43 ( V_28 ) ;
}
V_44 -> V_1 -- ;
}
return F_236 ( V_44 , V_73 , V_204 ) ;
}
static void F_378 ( struct V_407 * V_45 ,
struct V_72 * V_73 )
{
struct V_44 * V_44 = V_45 -> V_408 ;
F_237 ( V_44 , V_73 ) ;
}
static int F_379 ( struct V_407 * V_45 ,
unsigned long V_184 , T_8 V_416 ,
T_7 V_90 , int V_417 )
{
struct V_44 * V_44 = V_45 -> V_408 ;
V_25 V_406 ;
int V_226 = 0 ;
int V_68 ;
if ( V_417 & V_418 )
V_226 |= V_103 ;
if ( V_417 & V_419 )
V_226 |= V_104 ;
if ( ( V_417 & V_420 ) && V_44 -> V_70 )
V_226 |= V_231 ;
V_406 = V_184 + V_90 ;
if ( V_44 -> V_406 < V_406 ) {
V_25 V_86 ;
V_86 = F_374 ( V_44 -> V_113 ) + 1 ;
if ( V_86 < V_406 ) {
F_39 ( V_151 L_83
L_84 ,
V_415 , V_44 -> V_113 , V_406 ) ;
return - V_205 ;
}
V_44 -> V_406 = V_406 ;
}
V_90 = F_196 ( V_416 , V_90 ) ;
V_68 = F_207 ( V_44 , V_184 >> V_12 ,
V_416 >> V_12 , V_90 , V_226 ) ;
return V_68 ;
}
static T_7 F_380 ( struct V_407 * V_45 ,
unsigned long V_184 , T_7 V_90 )
{
struct V_44 * V_44 = V_45 -> V_408 ;
struct V_14 * V_114 = NULL ;
struct V_51 * V_52 ;
unsigned long V_107 , V_108 ;
unsigned int V_421 ;
int V_57 , V_179 , V_171 , V_5 = 0 ;
if ( ! F_90 ( V_44 , V_184 >> V_12 , & V_5 ) )
F_117 () ;
if ( V_90 < V_102 << F_6 ( V_5 ) )
V_90 = V_102 << F_6 ( V_5 ) ;
V_107 = V_184 >> V_12 ;
V_108 = ( V_184 + V_90 - 1 ) >> V_12 ;
V_114 = F_101 ( V_44 , V_107 , V_108 ) ;
V_421 = V_108 - V_107 + 1 ;
F_63 (iommu_id, dmar_domain->iommu_bmp, g_num_of_iommus) {
V_52 = V_60 [ V_57 ] ;
V_171 = F_148 ( V_52 -> V_55 ) ;
F_63 (num, iommu->domain_ids, ndomains) {
if ( V_52 -> V_164 [ V_179 ] == V_44 )
F_138 ( V_52 , V_179 , V_107 ,
V_421 , ! V_114 , 0 ) ;
}
}
F_102 ( V_114 ) ;
if ( V_44 -> V_406 == V_184 + V_90 )
V_44 -> V_406 = V_184 ;
return V_90 ;
}
static T_8 F_381 ( struct V_407 * V_45 ,
V_234 V_184 )
{
struct V_44 * V_44 = V_45 -> V_408 ;
struct V_27 * V_28 ;
int V_5 = 0 ;
V_25 V_422 = 0 ;
V_28 = F_90 ( V_44 , V_184 >> V_12 , & V_5 ) ;
if ( V_28 )
V_422 = F_32 ( V_28 ) ;
return V_422 ;
}
static bool F_382 ( enum V_423 V_55 )
{
if ( V_55 == V_424 )
return F_68 ( NULL ) == 1 ;
if ( V_55 == V_425 )
return V_426 == 1 ;
return false ;
}
static int F_383 ( struct V_72 * V_73 )
{
struct V_51 * V_52 ;
struct V_427 * V_428 ;
T_2 V_74 , V_75 ;
V_52 = F_74 ( V_73 , & V_74 , & V_75 ) ;
if ( ! V_52 )
return - V_192 ;
F_384 ( V_52 -> V_400 , V_73 ) ;
V_428 = F_385 ( V_73 ) ;
if ( F_386 ( V_428 ) )
return F_387 ( V_428 ) ;
F_388 ( V_428 ) ;
return 0 ;
}
static void F_389 ( struct V_72 * V_73 )
{
struct V_51 * V_52 ;
T_2 V_74 , V_75 ;
V_52 = F_74 ( V_73 , & V_74 , & V_75 ) ;
if ( ! V_52 )
return;
F_390 ( V_73 ) ;
F_391 ( V_52 -> V_400 , V_73 ) ;
}
static void F_392 ( struct V_77 * V_73 )
{
F_39 ( V_33 L_85 ) ;
V_34 = 0 ;
}
static void F_393 ( struct V_77 * V_73 )
{
F_39 ( V_33 L_86 ) ;
V_131 = 1 ;
}
static void F_394 ( struct V_77 * V_73 )
{
unsigned short V_429 ;
if ( F_395 ( V_73 , V_430 , & V_429 ) )
return;
if ( ! ( V_429 & V_431 ) ) {
F_39 ( V_33 L_87 ) ;
V_34 = 0 ;
} else if ( V_34 ) {
F_39 ( V_33 L_88 ) ;
V_36 = 1 ;
}
}
static void T_1 F_264 ( void )
{
struct V_77 * V_79 ;
T_11 V_432 ;
V_79 = F_396 ( V_433 , 0x3a3e , NULL ) ;
if ( ! V_79 )
return;
F_228 ( V_79 ) ;
V_79 = F_396 ( V_433 , 0x342e , NULL ) ;
if ( ! V_79 )
return;
if ( F_397 ( V_79 , 0x188 , & V_432 ) ) {
F_228 ( V_79 ) ;
return;
}
F_228 ( V_79 ) ;
if ( V_432 & 1 )
return;
V_432 &= 0x1c ;
if ( V_432 == 0x10 )
return;
if ( ! V_432 ) {
F_223 ( 1 , L_89
L_31 ,
F_224 ( V_249 ) ,
F_224 ( V_250 ) ,
F_224 ( V_251 ) ) ;
V_262 |= V_268 ;
return;
}
F_39 ( V_434 L_90 ,
V_432 ) ;
}
