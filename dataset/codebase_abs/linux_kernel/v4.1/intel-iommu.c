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
static inline void F_20 ( struct V_17 * V_18 )
{
V_18 -> V_19 &= ( ( ( V_20 ) - 1 ) << 2 ) | 1 ;
}
static inline void F_21 ( struct V_17 * V_18 ,
unsigned long V_21 )
{
V_18 -> V_19 &= ( ( ( V_20 ) - 1 ) << 4 ) | 3 ;
V_18 -> V_19 |= ( V_21 & 3 ) << 2 ;
}
static inline void F_22 ( struct V_17 * V_18 ,
unsigned long V_21 )
{
V_18 -> V_19 &= ~ V_22 ;
V_18 -> V_19 |= V_21 & V_22 ;
}
static inline void F_23 ( struct V_17 * V_18 ,
unsigned long V_21 )
{
V_18 -> V_23 |= V_21 & 7 ;
}
static inline void F_24 ( struct V_17 * V_18 ,
unsigned long V_21 )
{
V_18 -> V_23 |= ( V_21 & ( ( 1 << 16 ) - 1 ) ) << 8 ;
}
static inline void F_25 ( struct V_17 * V_18 )
{
V_18 -> V_19 = 0 ;
V_18 -> V_23 = 0 ;
}
static inline void F_26 ( struct V_24 * V_25 )
{
V_25 -> V_26 = 0 ;
}
static inline V_20 F_27 ( struct V_24 * V_25 )
{
#ifdef F_28
return V_25 -> V_26 & V_22 ;
#else
return F_29 ( & V_25 -> V_26 , 0ULL , 0ULL ) & V_22 ;
#endif
}
static inline bool F_30 ( struct V_24 * V_25 )
{
return ( V_25 -> V_26 & 3 ) != 0 ;
}
static inline bool F_31 ( struct V_24 * V_25 )
{
return ( V_25 -> V_26 & V_27 ) ;
}
static inline int F_32 ( struct V_24 * V_25 )
{
return ! ( ( unsigned long ) V_25 & ~ V_22 ) ;
}
static struct V_28 * F_33 ( struct V_29 * V_30 )
{
return F_34 ( V_30 , struct V_28 , V_31 ) ;
}
static int T_1 F_35 ( char * V_32 )
{
if ( ! V_32 )
return - V_33 ;
while ( * V_32 ) {
if ( ! strncmp ( V_32 , L_1 , 2 ) ) {
V_34 = 0 ;
F_36 ( V_35 L_2 ) ;
} else if ( ! strncmp ( V_32 , L_3 , 3 ) ) {
V_34 = 1 ;
F_36 ( V_35 L_4 ) ;
} else if ( ! strncmp ( V_32 , L_5 , 8 ) ) {
V_36 = 0 ;
F_36 ( V_35
L_6 ) ;
} else if ( ! strncmp ( V_32 , L_7 , 8 ) ) {
F_36 ( V_35
L_8 ) ;
V_37 = 1 ;
} else if ( ! strncmp ( V_32 , L_9 , 6 ) ) {
F_36 ( V_35
L_10 ) ;
V_38 = 1 ;
} else if ( ! strncmp ( V_32 , L_11 , 6 ) ) {
F_36 ( V_35
L_12 ) ;
V_39 = 0 ;
} else if ( ! strncmp ( V_32 , L_13 , 7 ) ) {
F_36 ( V_35
L_14 ) ;
V_40 = 0 ;
}
V_32 += strcspn ( V_32 , L_15 ) ;
while ( * V_32 == ',' )
V_32 ++ ;
}
return 0 ;
}
static inline void * F_37 ( int V_41 )
{
struct V_14 * V_14 ;
void * V_42 = NULL ;
V_14 = F_38 ( V_41 , V_43 | V_44 , 0 ) ;
if ( V_14 )
V_42 = F_39 ( V_14 ) ;
return V_42 ;
}
static inline void F_40 ( void * V_42 )
{
F_41 ( ( unsigned long ) V_42 ) ;
}
static inline void * F_42 ( void )
{
return F_43 ( V_45 , V_43 ) ;
}
static void F_44 ( void * V_42 )
{
F_45 ( V_45 , V_42 ) ;
}
static inline void * F_46 ( void )
{
return F_43 ( V_46 , V_43 ) ;
}
static inline void F_47 ( void * V_42 )
{
F_45 ( V_46 , V_42 ) ;
}
static inline int F_48 ( struct V_28 * V_31 )
{
return V_31 -> V_47 & V_48 ;
}
static inline int F_49 ( struct V_28 * V_31 )
{
return V_31 -> V_47 & ( V_48 |
V_49 ) ;
}
static inline int F_50 ( struct V_28 * V_31 ,
unsigned long V_6 )
{
int V_50 = F_2 ( V_31 -> V_1 ) - V_12 ;
return ! ( V_50 < V_51 && V_6 > > V_50 ) ;
}
static int F_51 ( struct V_52 * V_53 , int V_54 )
{
unsigned long V_55 ;
int V_1 = - 1 ;
V_55 = F_52 ( V_53 -> V_56 ) ;
for ( V_1 = F_4 ( V_54 ) ;
V_1 >= 0 ; V_1 -- ) {
if ( F_53 ( V_1 , & V_55 ) )
break;
}
return V_1 ;
}
int F_54 ( struct V_52 * V_53 )
{
return F_51 ( V_53 , V_3 ) ;
}
int F_55 ( struct V_52 * V_53 )
{
return F_51 ( V_53 , V_57 ) ;
}
static struct V_52 * F_56 ( struct V_28 * V_31 )
{
int V_58 ;
F_57 ( F_49 ( V_31 ) ) ;
V_58 = F_58 ( V_31 -> V_59 , V_60 ) ;
if ( V_58 < 0 || V_58 >= V_60 )
return NULL ;
return V_61 [ V_58 ] ;
}
static void F_59 ( struct V_28 * V_31 )
{
struct V_62 * V_63 ;
struct V_52 * V_53 ;
bool V_64 = false ;
int V_65 ;
V_31 -> V_66 = 1 ;
F_60 (i, domain->iommu_bmp, g_num_of_iommus) {
V_64 = true ;
if ( ! F_61 ( V_61 [ V_65 ] -> V_67 ) ) {
V_31 -> V_66 = 0 ;
break;
}
}
if ( V_64 )
return;
F_62 () ;
F_63 (iommu, drhd) {
if ( ! F_61 ( V_53 -> V_67 ) ) {
V_31 -> V_66 = 0 ;
break;
}
}
F_64 () ;
}
static int F_65 ( struct V_52 * V_68 )
{
struct V_62 * V_63 ;
struct V_52 * V_53 ;
int V_69 = 1 ;
F_62 () ;
F_63 (iommu, drhd) {
if ( V_53 != V_68 ) {
if ( ! F_66 ( V_53 -> V_67 ) ) {
V_69 = 0 ;
break;
}
}
}
F_64 () ;
return V_69 ;
}
static int F_67 ( struct V_52 * V_68 )
{
struct V_62 * V_63 ;
struct V_52 * V_53 ;
int V_70 = 0xf ;
if ( ! V_39 ) {
return 0 ;
}
F_62 () ;
F_63 (iommu, drhd) {
if ( V_53 != V_68 ) {
V_70 &= F_68 ( V_53 -> V_56 ) ;
if ( ! V_70 )
break;
}
}
F_64 () ;
return F_69 ( V_70 ) ;
}
static void F_70 ( struct V_28 * V_31 )
{
F_59 ( V_31 ) ;
V_31 -> V_71 = F_65 ( NULL ) ;
V_31 -> V_72 = F_67 ( NULL ) ;
}
static inline struct V_17 * F_71 ( struct V_52 * V_53 ,
T_2 V_73 , T_2 V_74 , int V_75 )
{
struct V_76 * V_77 = & V_53 -> V_76 [ V_73 ] ;
struct V_17 * V_18 ;
V_20 * V_78 ;
if ( F_72 ( V_53 ) ) {
if ( V_74 >= 0x80 ) {
V_74 -= 0x80 ;
V_78 = & V_77 -> V_23 ;
}
V_74 *= 2 ;
}
V_78 = & V_77 -> V_19 ;
if ( * V_78 & 1 )
V_18 = F_73 ( * V_78 & V_22 ) ;
else {
unsigned long V_79 ;
if ( ! V_75 )
return NULL ;
V_18 = F_37 ( V_53 -> V_41 ) ;
if ( ! V_18 )
return NULL ;
F_74 ( V_53 , ( void * ) V_18 , V_80 ) ;
V_79 = F_75 ( ( void * ) V_18 ) ;
* V_78 = V_79 | 1 ;
F_74 ( V_53 , V_78 , sizeof( * V_78 ) ) ;
}
return & V_18 [ V_74 ] ;
}
static int F_76 ( struct V_81 * V_82 )
{
return V_82 -> V_83 . V_53 == V_84 ;
}
static struct V_52 * F_77 ( struct V_81 * V_82 , T_2 * V_73 , T_2 * V_74 )
{
struct V_62 * V_63 = NULL ;
struct V_52 * V_53 ;
struct V_81 * V_85 ;
struct V_86 * V_87 , * V_88 = NULL ;
T_3 V_89 = 0 ;
int V_65 ;
if ( F_76 ( V_82 ) )
return NULL ;
if ( F_78 ( V_82 ) ) {
V_88 = F_79 ( V_82 ) ;
V_89 = F_80 ( V_88 -> V_73 ) ;
} else if ( F_81 ( V_82 ) )
V_82 = & F_82 ( V_82 ) -> V_82 ;
F_62 () ;
F_63 (iommu, drhd) {
if ( V_88 && V_89 != V_63 -> V_89 )
continue;
F_83 (drhd->devices,
drhd->devices_cnt, i, tmp) {
if ( V_85 == V_82 ) {
* V_73 = V_63 -> V_90 [ V_65 ] . V_73 ;
* V_74 = V_63 -> V_90 [ V_65 ] . V_74 ;
goto V_91;
}
if ( ! V_88 || ! F_78 ( V_85 ) )
continue;
V_87 = F_79 ( V_85 ) ;
if ( V_87 -> V_92 &&
V_87 -> V_92 -> V_93 <= V_88 -> V_73 -> V_93 &&
V_87 -> V_92 -> V_94 . V_95 >= V_88 -> V_73 -> V_93 )
goto V_96;
}
if ( V_88 && V_63 -> V_97 ) {
V_96:
* V_73 = V_88 -> V_73 -> V_93 ;
* V_74 = V_88 -> V_74 ;
goto V_91;
}
}
V_53 = NULL ;
V_91:
F_64 () ;
return V_53 ;
}
static void F_84 ( struct V_28 * V_31 ,
void * V_98 , int V_99 )
{
if ( ! V_31 -> V_66 )
F_85 ( V_98 , V_99 ) ;
}
static int F_86 ( struct V_52 * V_53 , T_2 V_73 , T_2 V_74 )
{
struct V_17 * V_18 ;
int V_69 = 0 ;
unsigned long V_47 ;
F_87 ( & V_53 -> V_100 , V_47 ) ;
V_18 = F_71 ( V_53 , V_73 , V_74 , 0 ) ;
if ( V_18 )
V_69 = F_18 ( V_18 ) ;
F_88 ( & V_53 -> V_100 , V_47 ) ;
return V_69 ;
}
static void F_89 ( struct V_52 * V_53 , T_2 V_73 , T_2 V_74 )
{
struct V_17 * V_18 ;
unsigned long V_47 ;
F_87 ( & V_53 -> V_100 , V_47 ) ;
V_18 = F_71 ( V_53 , V_73 , V_74 , 0 ) ;
if ( V_18 ) {
F_25 ( V_18 ) ;
F_74 ( V_53 , V_18 , sizeof( * V_18 ) ) ;
}
F_88 ( & V_53 -> V_100 , V_47 ) ;
}
static void F_90 ( struct V_52 * V_53 )
{
int V_65 ;
unsigned long V_47 ;
struct V_17 * V_18 ;
F_87 ( & V_53 -> V_100 , V_47 ) ;
if ( ! V_53 -> V_76 ) {
goto V_91;
}
for ( V_65 = 0 ; V_65 < V_101 ; V_65 ++ ) {
V_18 = F_71 ( V_53 , V_65 , 0 , 0 ) ;
if ( V_18 )
F_40 ( V_18 ) ;
if ( ! F_72 ( V_53 ) )
continue;
V_18 = F_71 ( V_53 , V_65 , 0x80 , 0 ) ;
if ( V_18 )
F_40 ( V_18 ) ;
}
F_40 ( V_53 -> V_76 ) ;
V_53 -> V_76 = NULL ;
V_91:
F_88 ( & V_53 -> V_100 , V_47 ) ;
}
static struct V_24 * F_91 ( struct V_28 * V_31 ,
unsigned long V_6 , int * V_102 )
{
struct V_24 * V_103 , * V_25 = NULL ;
int V_5 = F_1 ( V_31 -> V_1 ) ;
int V_104 ;
F_57 ( ! V_31 -> V_105 ) ;
if ( ! F_50 ( V_31 , V_6 ) )
return NULL ;
V_103 = V_31 -> V_105 ;
while ( 1 ) {
void * V_106 ;
V_104 = F_7 ( V_6 , V_5 ) ;
V_25 = & V_103 [ V_104 ] ;
if ( ! * V_102 && ( F_31 ( V_25 ) || ! F_30 ( V_25 ) ) )
break;
if ( V_5 == * V_102 )
break;
if ( ! F_30 ( V_25 ) ) {
T_4 V_107 ;
V_106 = F_37 ( V_31 -> V_108 ) ;
if ( ! V_106 )
return NULL ;
F_84 ( V_31 , V_106 , V_109 ) ;
V_107 = ( ( T_4 ) F_16 ( V_106 ) << V_12 ) | V_110 | V_111 ;
if ( F_92 ( & V_25 -> V_26 , 0ULL , V_107 ) )
F_40 ( V_106 ) ;
else
F_84 ( V_31 , V_25 , sizeof( * V_25 ) ) ;
}
if ( V_5 == 1 )
break;
V_103 = F_73 ( F_27 ( V_25 ) ) ;
V_5 -- ;
}
if ( ! * V_102 )
* V_102 = V_5 ;
return V_25 ;
}
static struct V_24 * F_93 ( struct V_28 * V_31 ,
unsigned long V_6 ,
int V_5 , int * V_112 )
{
struct V_24 * V_103 , * V_25 = NULL ;
int V_113 = F_1 ( V_31 -> V_1 ) ;
int V_104 ;
V_103 = V_31 -> V_105 ;
while ( V_5 <= V_113 ) {
V_104 = F_7 ( V_6 , V_113 ) ;
V_25 = & V_103 [ V_104 ] ;
if ( V_5 == V_113 )
return V_25 ;
if ( ! F_30 ( V_25 ) ) {
* V_112 = V_113 ;
break;
}
if ( F_31 ( V_25 ) ) {
* V_112 = V_113 ;
return V_25 ;
}
V_103 = F_73 ( F_27 ( V_25 ) ) ;
V_113 -- ;
}
return NULL ;
}
static void F_94 ( struct V_28 * V_31 ,
unsigned long V_114 ,
unsigned long V_115 )
{
unsigned int V_112 = 1 ;
struct V_24 * V_116 , * V_25 ;
F_57 ( ! F_50 ( V_31 , V_114 ) ) ;
F_57 ( ! F_50 ( V_31 , V_115 ) ) ;
F_57 ( V_114 > V_115 ) ;
do {
V_112 = 1 ;
V_116 = V_25 = F_93 ( V_31 , V_114 , 1 , & V_112 ) ;
if ( ! V_25 ) {
V_114 = F_10 ( V_114 + 1 , V_112 + 1 ) ;
continue;
}
do {
F_26 ( V_25 ) ;
V_114 += F_11 ( V_112 ) ;
V_25 ++ ;
} while ( V_114 <= V_115 && ! F_32 ( V_25 ) );
F_84 ( V_31 , V_116 ,
( void * ) V_25 - ( void * ) V_116 ) ;
} while ( V_114 && V_114 <= V_115 );
}
static void F_95 ( struct V_28 * V_31 , int V_5 ,
struct V_24 * V_25 , unsigned long V_6 ,
unsigned long V_114 , unsigned long V_115 )
{
V_6 = F_96 ( V_114 , V_6 ) ;
V_25 = & V_25 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_117 ;
struct V_24 * V_118 ;
if ( ! F_30 ( V_25 ) || F_31 ( V_25 ) )
goto V_119;
V_117 = V_6 & F_8 ( V_5 - 1 ) ;
V_118 = F_73 ( F_27 ( V_25 ) ) ;
if ( V_5 > 2 )
F_95 ( V_31 , V_5 - 1 , V_118 ,
V_117 , V_114 , V_115 ) ;
if ( ! ( V_114 > V_117 ||
V_115 < V_117 + F_9 ( V_5 ) - 1 ) ) {
F_26 ( V_25 ) ;
F_84 ( V_31 , V_25 , sizeof( * V_25 ) ) ;
F_40 ( V_118 ) ;
}
V_119:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_32 ( ++ V_25 ) && V_6 <= V_115 );
}
static void F_97 ( struct V_28 * V_31 ,
unsigned long V_114 ,
unsigned long V_115 )
{
F_57 ( ! F_50 ( V_31 , V_114 ) ) ;
F_57 ( ! F_50 ( V_31 , V_115 ) ) ;
F_57 ( V_114 > V_115 ) ;
F_94 ( V_31 , V_114 , V_115 ) ;
F_95 ( V_31 , F_1 ( V_31 -> V_1 ) ,
V_31 -> V_105 , 0 , V_114 , V_115 ) ;
if ( V_114 == 0 && V_115 == F_98 ( V_31 -> V_120 ) ) {
F_40 ( V_31 -> V_105 ) ;
V_31 -> V_105 = NULL ;
}
}
static struct V_14 * F_99 ( struct V_28 * V_31 ,
int V_5 , struct V_24 * V_25 ,
struct V_14 * V_121 )
{
struct V_14 * V_15 ;
V_15 = F_100 ( F_27 ( V_25 ) >> V_11 ) ;
V_15 -> V_121 = V_121 ;
V_121 = V_15 ;
if ( V_5 == 1 )
return V_121 ;
V_25 = F_39 ( V_15 ) ;
do {
if ( F_30 ( V_25 ) && ! F_31 ( V_25 ) )
V_121 = F_99 ( V_31 , V_5 - 1 ,
V_25 , V_121 ) ;
V_25 ++ ;
} while ( ! F_32 ( V_25 ) );
return V_121 ;
}
static struct V_14 * F_101 ( struct V_28 * V_31 , int V_5 ,
struct V_24 * V_25 , unsigned long V_6 ,
unsigned long V_114 ,
unsigned long V_115 ,
struct V_14 * V_121 )
{
struct V_24 * V_116 = NULL , * V_122 = NULL ;
V_6 = F_96 ( V_114 , V_6 ) ;
V_25 = & V_25 [ F_7 ( V_6 , V_5 ) ] ;
do {
unsigned long V_117 ;
if ( ! F_30 ( V_25 ) )
goto V_119;
V_117 = V_6 & F_8 ( V_5 ) ;
if ( V_114 <= V_117 &&
V_115 >= V_117 + F_9 ( V_5 ) - 1 ) {
if ( V_5 > 1 && ! F_31 ( V_25 ) )
V_121 = F_99 ( V_31 , V_5 - 1 , V_25 , V_121 ) ;
F_26 ( V_25 ) ;
if ( ! V_116 )
V_116 = V_25 ;
V_122 = V_25 ;
} else if ( V_5 > 1 ) {
V_121 = F_101 ( V_31 , V_5 - 1 ,
F_73 ( F_27 ( V_25 ) ) ,
V_117 , V_114 , V_115 ,
V_121 ) ;
}
V_119:
V_6 += F_9 ( V_5 ) ;
} while ( ! F_32 ( ++ V_25 ) && V_6 <= V_115 );
if ( V_116 )
F_84 ( V_31 , V_116 ,
( void * ) ++ V_122 - ( void * ) V_116 ) ;
return V_121 ;
}
struct V_14 * F_102 ( struct V_28 * V_31 ,
unsigned long V_114 ,
unsigned long V_115 )
{
struct V_14 * V_121 = NULL ;
F_57 ( ! F_50 ( V_31 , V_114 ) ) ;
F_57 ( ! F_50 ( V_31 , V_115 ) ) ;
F_57 ( V_114 > V_115 ) ;
V_121 = F_101 ( V_31 , F_1 ( V_31 -> V_1 ) ,
V_31 -> V_105 , 0 , V_114 , V_115 , NULL ) ;
if ( V_114 == 0 && V_115 == F_98 ( V_31 -> V_120 ) ) {
struct V_14 * V_123 = F_17 ( V_31 -> V_105 ) ;
V_123 -> V_121 = V_121 ;
V_121 = V_123 ;
V_31 -> V_105 = NULL ;
}
return V_121 ;
}
void F_103 ( struct V_14 * V_121 )
{
struct V_14 * V_15 ;
while ( ( V_15 = V_121 ) ) {
V_121 = V_15 -> V_121 ;
F_40 ( F_39 ( V_15 ) ) ;
}
}
static int F_104 ( struct V_52 * V_53 )
{
struct V_76 * V_77 ;
unsigned long V_47 ;
V_77 = (struct V_76 * ) F_37 ( V_53 -> V_41 ) ;
if ( ! V_77 ) {
F_105 ( L_16 ,
V_53 -> V_124 ) ;
return - V_125 ;
}
F_74 ( V_53 , V_77 , V_126 ) ;
F_87 ( & V_53 -> V_100 , V_47 ) ;
V_53 -> V_76 = V_77 ;
F_88 ( & V_53 -> V_100 , V_47 ) ;
return 0 ;
}
static void F_106 ( struct V_52 * V_53 )
{
V_20 V_98 ;
T_5 V_127 ;
unsigned long V_128 ;
V_98 = F_75 ( V_53 -> V_76 ) ;
if ( F_72 ( V_53 ) )
V_98 |= V_129 ;
F_107 ( & V_53 -> V_130 , V_128 ) ;
F_108 ( V_53 -> V_131 + V_132 , V_98 ) ;
F_109 ( V_53 -> V_133 | V_134 , V_53 -> V_131 + V_135 ) ;
F_110 ( V_53 , V_136 ,
V_137 , ( V_127 & V_138 ) , V_127 ) ;
F_111 ( & V_53 -> V_130 , V_128 ) ;
}
static void F_112 ( struct V_52 * V_53 )
{
T_5 V_26 ;
unsigned long V_128 ;
if ( ! V_139 && ! F_113 ( V_53 -> V_56 ) )
return;
F_107 ( & V_53 -> V_130 , V_128 ) ;
F_109 ( V_53 -> V_133 | V_140 , V_53 -> V_131 + V_135 ) ;
F_110 ( V_53 , V_136 ,
V_137 , ( ! ( V_26 & V_141 ) ) , V_26 ) ;
F_111 ( & V_53 -> V_130 , V_128 ) ;
}
static void F_114 ( struct V_52 * V_53 ,
T_3 V_142 , T_3 V_143 , T_2 V_144 ,
V_20 type )
{
V_20 V_26 = 0 ;
unsigned long V_128 ;
switch ( type ) {
case V_145 :
V_26 = V_145 ;
break;
case V_146 :
V_26 = V_146 | F_115 ( V_142 ) ;
break;
case V_147 :
V_26 = V_147 | F_115 ( V_142 )
| F_116 ( V_143 ) | F_117 ( V_144 ) ;
break;
default:
F_118 () ;
}
V_26 |= V_148 ;
F_107 ( & V_53 -> V_130 , V_128 ) ;
F_108 ( V_53 -> V_131 + V_149 , V_26 ) ;
F_110 ( V_53 , V_149 ,
V_150 , ( ! ( V_26 & V_148 ) ) , V_26 ) ;
F_111 ( & V_53 -> V_130 , V_128 ) ;
}
static void F_119 ( struct V_52 * V_53 , T_3 V_142 ,
V_20 V_98 , unsigned int V_151 , V_20 type )
{
int V_152 = F_120 ( V_53 -> V_67 ) ;
V_20 V_26 = 0 , V_153 = 0 ;
unsigned long V_128 ;
switch ( type ) {
case V_154 :
V_26 = V_154 | V_155 ;
break;
case V_156 :
V_26 = V_156 | V_155 | F_121 ( V_142 ) ;
break;
case V_157 :
V_26 = V_157 | V_155 | F_121 ( V_142 ) ;
V_153 = V_151 | V_98 ;
break;
default:
F_118 () ;
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if ( F_122 ( V_53 -> V_56 ) )
V_26 |= V_158 ;
F_107 ( & V_53 -> V_130 , V_128 ) ;
if ( V_153 )
F_108 ( V_53 -> V_131 + V_152 , V_153 ) ;
F_108 ( V_53 -> V_131 + V_152 + 8 , V_26 ) ;
F_110 ( V_53 , V_152 + 8 ,
V_150 , ( ! ( V_26 & V_155 ) ) , V_26 ) ;
F_111 ( & V_53 -> V_130 , V_128 ) ;
if ( F_123 ( V_26 ) == 0 )
F_36 ( V_159 L_17 ) ;
if ( F_123 ( V_26 ) != F_124 ( type ) )
F_125 ( L_18 ,
( unsigned long long ) F_124 ( type ) ,
( unsigned long long ) F_123 ( V_26 ) ) ;
}
static struct V_160 *
F_126 ( struct V_28 * V_31 , struct V_52 * V_53 ,
T_2 V_73 , T_2 V_74 )
{
bool V_64 = false ;
unsigned long V_47 ;
struct V_160 * V_161 ;
struct V_86 * V_88 ;
if ( ! F_127 ( V_53 -> V_67 ) )
return NULL ;
if ( ! V_53 -> V_162 )
return NULL ;
F_87 ( & V_163 , V_47 ) ;
F_128 (info, &domain->devices, link)
if ( V_161 -> V_53 == V_53 && V_161 -> V_73 == V_73 &&
V_161 -> V_74 == V_74 ) {
V_64 = true ;
break;
}
F_88 ( & V_163 , V_47 ) ;
if ( ! V_64 || ! V_161 -> V_82 || ! F_78 ( V_161 -> V_82 ) )
return NULL ;
V_88 = F_79 ( V_161 -> V_82 ) ;
if ( ! F_129 ( V_88 , V_164 ) )
return NULL ;
if ( ! F_130 ( V_88 ) )
return NULL ;
return V_161 ;
}
static void F_131 ( struct V_160 * V_161 )
{
if ( ! V_161 || ! F_78 ( V_161 -> V_82 ) )
return;
F_132 ( F_79 ( V_161 -> V_82 ) , V_12 ) ;
}
static void F_133 ( struct V_160 * V_161 )
{
if ( ! V_161 -> V_82 || ! F_78 ( V_161 -> V_82 ) ||
! F_134 ( F_79 ( V_161 -> V_82 ) ) )
return;
F_135 ( F_79 ( V_161 -> V_82 ) ) ;
}
static void F_136 ( struct V_28 * V_31 ,
V_20 V_98 , unsigned V_70 )
{
T_3 V_165 , V_166 ;
unsigned long V_47 ;
struct V_160 * V_161 ;
F_87 ( & V_163 , V_47 ) ;
F_128 (info, &domain->devices, link) {
struct V_86 * V_88 ;
if ( ! V_161 -> V_82 || ! F_78 ( V_161 -> V_82 ) )
continue;
V_88 = F_79 ( V_161 -> V_82 ) ;
if ( ! F_134 ( V_88 ) )
continue;
V_165 = V_161 -> V_73 << 8 | V_161 -> V_74 ;
V_166 = F_137 ( V_88 ) ;
F_138 ( V_161 -> V_53 , V_165 , V_166 , V_98 , V_70 ) ;
}
F_88 ( & V_163 , V_47 ) ;
}
static void F_139 ( struct V_52 * V_53 , T_3 V_142 ,
unsigned long V_6 , unsigned int V_167 , int V_168 , int V_169 )
{
unsigned int V_70 = F_140 ( F_141 ( V_167 ) ) ;
T_4 V_98 = ( T_4 ) V_6 << V_12 ;
F_57 ( V_167 == 0 ) ;
if ( V_168 )
V_168 = 1 << 6 ;
if ( ! F_142 ( V_53 -> V_56 ) || V_70 > F_143 ( V_53 -> V_56 ) )
V_53 -> V_170 . V_171 ( V_53 , V_142 , 0 , 0 ,
V_156 ) ;
else
V_53 -> V_170 . V_171 ( V_53 , V_142 , V_98 | V_168 , V_70 ,
V_157 ) ;
if ( ! F_144 ( V_53 -> V_56 ) || ! V_169 )
F_136 ( V_53 -> V_172 [ V_142 ] , V_98 , V_70 ) ;
}
static void F_145 ( struct V_52 * V_53 )
{
T_5 V_173 ;
unsigned long V_47 ;
F_107 ( & V_53 -> V_130 , V_47 ) ;
V_173 = V_137 ( V_53 -> V_131 + V_174 ) ;
V_173 &= ~ V_175 ;
F_109 ( V_173 , V_53 -> V_131 + V_174 ) ;
F_110 ( V_53 , V_174 ,
V_137 , ! ( V_173 & V_176 ) , V_173 ) ;
F_111 ( & V_53 -> V_130 , V_47 ) ;
}
static void F_146 ( struct V_52 * V_53 )
{
T_5 V_127 ;
unsigned long V_47 ;
F_107 ( & V_53 -> V_130 , V_47 ) ;
V_53 -> V_133 |= V_177 ;
F_109 ( V_53 -> V_133 , V_53 -> V_131 + V_135 ) ;
F_110 ( V_53 , V_136 ,
V_137 , ( V_127 & V_178 ) , V_127 ) ;
F_111 ( & V_53 -> V_130 , V_47 ) ;
}
static void F_147 ( struct V_52 * V_53 )
{
T_5 V_127 ;
unsigned long V_128 ;
F_107 ( & V_53 -> V_130 , V_128 ) ;
V_53 -> V_133 &= ~ V_177 ;
F_109 ( V_53 -> V_133 , V_53 -> V_131 + V_135 ) ;
F_110 ( V_53 , V_136 ,
V_137 , ( ! ( V_127 & V_178 ) ) , V_127 ) ;
F_111 ( & V_53 -> V_130 , V_128 ) ;
}
static int F_148 ( struct V_52 * V_53 )
{
unsigned long V_179 ;
unsigned long V_180 ;
V_179 = F_149 ( V_53 -> V_56 ) ;
F_125 ( L_19 ,
V_53 -> V_181 , V_179 ) ;
V_180 = F_150 ( V_179 ) ;
F_151 ( & V_53 -> V_100 ) ;
V_53 -> V_182 = F_152 ( V_180 , sizeof( unsigned long ) , V_183 ) ;
if ( ! V_53 -> V_182 ) {
F_105 ( L_20 ,
V_53 -> V_181 ) ;
return - V_125 ;
}
V_53 -> V_172 = F_152 ( V_179 , sizeof( struct V_28 * ) ,
V_183 ) ;
if ( ! V_53 -> V_172 ) {
F_105 ( L_21 ,
V_53 -> V_181 ) ;
F_153 ( V_53 -> V_182 ) ;
V_53 -> V_182 = NULL ;
return - V_125 ;
}
if ( F_144 ( V_53 -> V_56 ) )
F_154 ( 0 , V_53 -> V_182 ) ;
return 0 ;
}
static void F_155 ( struct V_52 * V_53 )
{
struct V_28 * V_31 ;
int V_65 ;
if ( ( V_53 -> V_172 ) && ( V_53 -> V_182 ) ) {
F_60 (i, iommu->domain_ids, cap_ndoms(iommu->cap)) {
if ( F_144 ( V_53 -> V_56 ) && V_65 == 0 )
continue;
V_31 = V_53 -> V_172 [ V_65 ] ;
F_156 ( V_65 , V_53 -> V_182 ) ;
if ( F_157 ( V_31 , V_53 ) == 0 &&
! F_48 ( V_31 ) )
F_158 ( V_31 ) ;
}
}
if ( V_53 -> V_133 & V_177 )
F_147 ( V_53 ) ;
}
static void F_159 ( struct V_52 * V_53 )
{
if ( ( V_53 -> V_172 ) && ( V_53 -> V_182 ) ) {
F_153 ( V_53 -> V_172 ) ;
F_153 ( V_53 -> V_182 ) ;
V_53 -> V_172 = NULL ;
V_53 -> V_182 = NULL ;
}
V_61 [ V_53 -> V_181 ] = NULL ;
F_90 ( V_53 ) ;
}
static struct V_28 * F_160 ( int V_47 )
{
static T_6 V_184 = F_161 ( 0 ) ;
struct V_28 * V_31 ;
V_31 = F_42 () ;
if ( ! V_31 )
return NULL ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_108 = - 1 ;
V_31 -> V_47 = V_47 ;
F_151 ( & V_31 -> V_185 ) ;
F_162 ( & V_31 -> V_90 ) ;
if ( V_47 & V_48 )
V_31 -> V_186 = F_163 ( & V_184 ) ;
return V_31 ;
}
static int F_164 ( struct V_28 * V_31 ,
struct V_52 * V_53 )
{
int V_187 ;
unsigned long V_179 ;
V_179 = F_149 ( V_53 -> V_56 ) ;
V_187 = F_165 ( V_53 -> V_182 , V_179 ) ;
if ( V_187 < V_179 ) {
F_154 ( V_187 , V_53 -> V_182 ) ;
V_53 -> V_172 [ V_187 ] = V_31 ;
} else {
V_187 = - V_188 ;
}
return V_187 ;
}
static int F_166 ( struct V_28 * V_31 ,
struct V_52 * V_53 )
{
int V_187 ;
unsigned long V_47 ;
F_87 ( & V_53 -> V_100 , V_47 ) ;
V_187 = F_164 ( V_31 , V_53 ) ;
F_88 ( & V_53 -> V_100 , V_47 ) ;
if ( V_187 < 0 )
F_105 ( L_22 ) ;
return V_187 ;
}
static int F_167 ( struct V_28 * V_31 ,
struct V_52 * V_53 )
{
int V_187 ;
unsigned long V_179 ;
V_179 = F_149 ( V_53 -> V_56 ) ;
F_60 (num, iommu->domain_ids, ndomains)
if ( V_53 -> V_172 [ V_187 ] == V_31 )
return V_187 ;
return F_164 ( V_31 , V_53 ) ;
}
static void F_168 ( struct V_28 * V_31 ,
struct V_52 * V_53 )
{
unsigned long V_47 ;
int V_187 , V_179 ;
F_87 ( & V_53 -> V_100 , V_47 ) ;
if ( F_49 ( V_31 ) ) {
V_179 = F_149 ( V_53 -> V_56 ) ;
F_60 (num, iommu->domain_ids, ndomains) {
if ( V_53 -> V_172 [ V_187 ] == V_31 ) {
F_156 ( V_187 , V_53 -> V_182 ) ;
V_53 -> V_172 [ V_187 ] = NULL ;
break;
}
}
} else {
F_156 ( V_31 -> V_186 , V_53 -> V_182 ) ;
V_53 -> V_172 [ V_31 -> V_186 ] = NULL ;
}
F_88 ( & V_53 -> V_100 , V_47 ) ;
}
static void F_169 ( struct V_28 * V_31 ,
struct V_52 * V_53 )
{
unsigned long V_47 ;
F_87 ( & V_31 -> V_185 , V_47 ) ;
if ( ! F_170 ( V_53 -> V_181 , V_31 -> V_59 ) ) {
V_31 -> V_189 ++ ;
if ( V_31 -> V_189 == 1 )
V_31 -> V_108 = V_53 -> V_41 ;
F_70 ( V_31 ) ;
}
F_88 ( & V_31 -> V_185 , V_47 ) ;
}
static int F_157 ( struct V_28 * V_31 ,
struct V_52 * V_53 )
{
unsigned long V_47 ;
int V_190 = V_191 ;
F_87 ( & V_31 -> V_185 , V_47 ) ;
if ( F_171 ( V_53 -> V_181 , V_31 -> V_59 ) ) {
V_190 = -- V_31 -> V_189 ;
F_70 ( V_31 ) ;
}
F_88 ( & V_31 -> V_185 , V_47 ) ;
return V_190 ;
}
static int F_172 ( void )
{
struct V_86 * V_88 = NULL ;
struct V_192 * V_192 ;
int V_65 ;
F_173 ( & V_193 , V_109 , V_194 ,
V_195 ) ;
F_174 ( & V_193 . V_196 ,
& V_197 ) ;
V_192 = F_175 ( & V_193 , F_176 ( V_198 ) ,
F_176 ( V_199 ) ) ;
if ( ! V_192 ) {
F_36 ( V_159 L_23 ) ;
return - V_200 ;
}
F_177 (pdev) {
struct V_201 * V_202 ;
for ( V_65 = 0 ; V_65 < V_203 ; V_65 ++ ) {
V_202 = & V_88 -> V_201 [ V_65 ] ;
if ( ! V_202 -> V_47 || ! ( V_202 -> V_47 & V_204 ) )
continue;
V_192 = F_175 ( & V_193 ,
F_176 ( V_202 -> V_205 ) ,
F_176 ( V_202 -> V_95 ) ) ;
if ( ! V_192 ) {
F_36 ( V_159 L_24 ) ;
return - V_200 ;
}
}
}
return 0 ;
}
static void F_178 ( struct V_28 * V_31 )
{
F_179 ( & V_193 , & V_31 -> V_206 ) ;
}
static inline int F_180 ( int V_120 )
{
int V_1 ;
int V_202 = ( V_120 - 12 ) % 9 ;
if ( V_202 == 0 )
V_1 = V_120 ;
else
V_1 = V_120 + 9 - V_202 ;
if ( V_1 > 64 )
V_1 = 64 ;
return V_1 ;
}
static int F_181 ( struct V_28 * V_31 , int V_207 )
{
struct V_52 * V_53 ;
int V_208 , V_1 ;
unsigned long V_55 ;
F_173 ( & V_31 -> V_206 , V_109 , V_194 ,
V_195 ) ;
F_178 ( V_31 ) ;
V_53 = F_56 ( V_31 ) ;
if ( V_207 > F_182 ( V_53 -> V_56 ) )
V_207 = F_182 ( V_53 -> V_56 ) ;
V_31 -> V_120 = V_207 ;
V_208 = F_180 ( V_207 ) ;
V_1 = F_4 ( V_208 ) ;
V_55 = F_52 ( V_53 -> V_56 ) ;
if ( ! F_53 ( V_1 , & V_55 ) ) {
F_125 ( L_25 , V_1 ) ;
V_1 = F_183 ( & V_55 , 5 , V_1 ) ;
if ( V_1 >= 5 )
return - V_200 ;
}
V_31 -> V_1 = V_1 ;
if ( F_61 ( V_53 -> V_67 ) )
V_31 -> V_66 = 1 ;
else
V_31 -> V_66 = 0 ;
if ( F_66 ( V_53 -> V_67 ) )
V_31 -> V_71 = 1 ;
else
V_31 -> V_71 = 0 ;
if ( V_39 )
V_31 -> V_72 = F_69 ( F_68 ( V_53 -> V_56 ) ) ;
else
V_31 -> V_72 = 0 ;
V_31 -> V_108 = V_53 -> V_41 ;
V_31 -> V_105 = (struct V_24 * ) F_37 ( V_31 -> V_108 ) ;
if ( ! V_31 -> V_105 )
return - V_125 ;
F_74 ( V_53 , V_31 -> V_105 , V_209 ) ;
return 0 ;
}
static void F_158 ( struct V_28 * V_31 )
{
struct V_14 * V_121 = NULL ;
int V_65 ;
if ( ! V_31 )
return;
if ( ! V_38 )
F_184 ( 0 ) ;
F_185 ( V_31 ) ;
F_186 ( & V_31 -> V_206 ) ;
V_121 = F_102 ( V_31 , 0 , F_98 ( V_31 -> V_120 ) ) ;
F_62 () ;
F_60 (i, domain->iommu_bmp, g_num_of_iommus)
F_168 ( V_31 , V_61 [ V_65 ] ) ;
F_64 () ;
F_103 ( V_121 ) ;
F_44 ( V_31 ) ;
}
static int F_187 ( struct V_28 * V_31 ,
struct V_52 * V_53 ,
T_2 V_73 , T_2 V_74 , int V_210 )
{
struct V_17 * V_18 ;
unsigned long V_47 ;
struct V_24 * V_105 ;
int V_186 ;
int V_1 ;
struct V_160 * V_161 = NULL ;
F_125 ( L_26 ,
V_73 , F_188 ( V_74 ) , F_189 ( V_74 ) ) ;
F_57 ( ! V_31 -> V_105 ) ;
F_57 ( V_210 != V_211 &&
V_210 != V_212 ) ;
F_87 ( & V_53 -> V_100 , V_47 ) ;
V_18 = F_71 ( V_53 , V_73 , V_74 , 1 ) ;
F_88 ( & V_53 -> V_100 , V_47 ) ;
if ( ! V_18 )
return - V_125 ;
F_87 ( & V_53 -> V_100 , V_47 ) ;
if ( F_18 ( V_18 ) ) {
F_88 ( & V_53 -> V_100 , V_47 ) ;
return 0 ;
}
V_186 = V_31 -> V_186 ;
V_105 = V_31 -> V_105 ;
if ( F_49 ( V_31 ) ) {
if ( F_48 ( V_31 ) ) {
V_186 = F_167 ( V_31 , V_53 ) ;
if ( V_186 < 0 ) {
F_88 ( & V_53 -> V_100 , V_47 ) ;
F_105 ( L_22 ) ;
return - V_213 ;
}
}
if ( V_210 != V_211 ) {
for ( V_1 = V_31 -> V_1 ; V_1 != V_53 -> V_1 ; V_1 -- ) {
V_105 = F_73 ( F_27 ( V_105 ) ) ;
if ( ! F_30 ( V_105 ) ) {
F_88 ( & V_53 -> V_100 , V_47 ) ;
return - V_125 ;
}
}
}
}
F_24 ( V_18 , V_186 ) ;
if ( V_210 != V_211 ) {
V_161 = F_126 ( V_31 , V_53 , V_73 , V_74 ) ;
V_210 = V_161 ? V_214 :
V_212 ;
}
if ( F_190 ( V_210 == V_211 ) )
F_23 ( V_18 , V_53 -> V_215 ) ;
else {
F_22 ( V_18 , F_75 ( V_105 ) ) ;
F_23 ( V_18 , V_53 -> V_1 ) ;
}
F_21 ( V_18 , V_210 ) ;
F_20 ( V_18 ) ;
F_19 ( V_18 ) ;
F_84 ( V_31 , V_18 , sizeof( * V_18 ) ) ;
if ( F_144 ( V_53 -> V_56 ) ) {
V_53 -> V_170 . V_216 ( V_53 , 0 ,
( ( ( T_3 ) V_73 ) << 8 ) | V_74 ,
V_217 ,
V_147 ) ;
V_53 -> V_170 . V_171 ( V_53 , V_186 , 0 , 0 , V_156 ) ;
} else {
F_112 ( V_53 ) ;
}
F_131 ( V_161 ) ;
F_88 ( & V_53 -> V_100 , V_47 ) ;
F_169 ( V_31 , V_53 ) ;
return 0 ;
}
static int F_191 ( struct V_86 * V_88 ,
T_3 V_218 , void * V_219 )
{
struct V_220 * V_221 = V_219 ;
return F_187 ( V_221 -> V_31 , V_221 -> V_53 ,
F_192 ( V_218 ) , V_218 & 0xff ,
V_221 -> V_210 ) ;
}
static int
F_193 ( struct V_28 * V_31 , struct V_81 * V_82 ,
int V_210 )
{
struct V_52 * V_53 ;
T_2 V_73 , V_74 ;
struct V_220 V_221 ;
V_53 = F_77 ( V_82 , & V_73 , & V_74 ) ;
if ( ! V_53 )
return - V_200 ;
if ( ! F_78 ( V_82 ) )
return F_187 ( V_31 , V_53 , V_73 , V_74 ,
V_210 ) ;
V_221 . V_31 = V_31 ;
V_221 . V_53 = V_53 ;
V_221 . V_210 = V_210 ;
return F_194 ( F_79 ( V_82 ) ,
& F_191 , & V_221 ) ;
}
static int F_195 ( struct V_86 * V_88 ,
T_3 V_218 , void * V_219 )
{
struct V_52 * V_53 = V_219 ;
return ! F_86 ( V_53 , F_192 ( V_218 ) , V_218 & 0xff ) ;
}
static int F_196 ( struct V_81 * V_82 )
{
struct V_52 * V_53 ;
T_2 V_73 , V_74 ;
V_53 = F_77 ( V_82 , & V_73 , & V_74 ) ;
if ( ! V_53 )
return - V_200 ;
if ( ! F_78 ( V_82 ) )
return F_86 ( V_53 , V_73 , V_74 ) ;
return ! F_194 ( F_79 ( V_82 ) ,
F_195 , V_53 ) ;
}
static inline unsigned long F_197 ( unsigned long V_222 ,
T_7 V_99 )
{
V_222 &= ~ V_223 ;
return F_198 ( V_222 + V_99 ) >> V_12 ;
}
static inline int F_199 ( struct V_28 * V_31 ,
unsigned long V_224 ,
unsigned long V_225 ,
unsigned long V_167 )
{
int V_226 , V_5 = 1 ;
unsigned long V_227 ;
V_226 = V_31 -> V_72 ;
V_227 = V_224 | V_225 ;
while ( V_226 && ! ( V_227 & ~ V_228 ) ) {
V_167 >>= V_229 ;
if ( ! V_167 )
break;
V_227 >>= V_229 ;
V_5 ++ ;
V_226 -- ;
}
return V_5 ;
}
static int F_200 ( struct V_28 * V_31 , unsigned long V_224 ,
struct V_230 * V_231 , unsigned long V_232 ,
unsigned long V_233 , int V_234 )
{
struct V_24 * V_116 = NULL , * V_25 = NULL ;
T_8 V_235 ( V_107 ) ;
unsigned long V_236 = 0 ;
unsigned int V_237 = 0 ;
unsigned long V_238 = 0 ;
F_57 ( ! F_50 ( V_31 , V_224 + V_233 - 1 ) ) ;
if ( ( V_234 & ( V_110 | V_111 ) ) == 0 )
return - V_33 ;
V_234 &= V_110 | V_111 | V_239 ;
if ( ! V_231 ) {
V_236 = V_233 ;
V_107 = ( ( T_8 ) V_232 << V_12 ) | V_234 ;
}
while ( V_233 > 0 ) {
T_4 V_85 ;
if ( ! V_236 ) {
V_236 = F_197 ( V_231 -> V_104 , V_231 -> V_240 ) ;
V_231 -> V_241 = ( ( V_242 ) V_224 << V_12 ) + V_231 -> V_104 ;
V_231 -> V_243 = V_231 -> V_240 ;
V_107 = F_201 ( F_202 ( V_231 ) ) | V_234 ;
V_232 = V_107 >> V_12 ;
}
if ( ! V_25 ) {
V_237 = F_199 ( V_31 , V_224 , V_232 , V_236 ) ;
V_116 = V_25 = F_91 ( V_31 , V_224 , & V_237 ) ;
if ( ! V_25 )
return - V_125 ;
if ( V_237 > 1 ) {
V_107 |= V_27 ;
V_238 = F_11 ( V_237 ) ;
F_97 ( V_31 , V_224 ,
V_224 + V_238 - 1 ) ;
} else {
V_107 &= ~ ( T_4 ) V_27 ;
}
}
V_85 = F_203 ( & V_25 -> V_26 , 0ULL , V_107 ) ;
if ( V_85 ) {
static int V_244 = 5 ;
F_36 ( V_245 L_27 ,
V_224 , V_85 , ( unsigned long long ) V_107 ) ;
if ( V_244 ) {
V_244 -- ;
F_204 ( NULL ) ;
}
F_205 ( 1 ) ;
}
V_238 = F_11 ( V_237 ) ;
F_57 ( V_233 < V_238 ) ;
F_57 ( V_236 < V_238 ) ;
V_233 -= V_238 ;
V_224 += V_238 ;
V_232 += V_238 ;
V_107 += V_238 * V_109 ;
V_236 -= V_238 ;
V_25 ++ ;
if ( ! V_233 || F_32 ( V_25 ) ||
( V_237 > 1 && V_236 < V_238 ) ) {
F_84 ( V_31 , V_116 ,
( void * ) V_25 - ( void * ) V_116 ) ;
V_25 = NULL ;
}
if ( ! V_236 && V_233 )
V_231 = F_206 ( V_231 ) ;
}
return 0 ;
}
static inline int F_207 ( struct V_28 * V_31 , unsigned long V_224 ,
struct V_230 * V_231 , unsigned long V_233 ,
int V_234 )
{
return F_200 ( V_31 , V_224 , V_231 , 0 , V_233 , V_234 ) ;
}
static inline int F_208 ( struct V_28 * V_31 , unsigned long V_224 ,
unsigned long V_232 , unsigned long V_233 ,
int V_234 )
{
return F_200 ( V_31 , V_224 , NULL , V_232 , V_233 , V_234 ) ;
}
static void F_209 ( struct V_52 * V_53 , T_2 V_73 , T_2 V_74 )
{
if ( ! V_53 )
return;
F_89 ( V_53 , V_73 , V_74 ) ;
V_53 -> V_170 . V_216 ( V_53 , 0 , 0 , 0 ,
V_145 ) ;
V_53 -> V_170 . V_171 ( V_53 , 0 , 0 , 0 , V_154 ) ;
}
static inline void F_210 ( struct V_160 * V_161 )
{
F_211 ( & V_163 ) ;
F_212 ( & V_161 -> V_246 ) ;
F_212 ( & V_161 -> V_247 ) ;
if ( V_161 -> V_82 )
V_161 -> V_82 -> V_83 . V_53 = NULL ;
}
static void F_185 ( struct V_28 * V_31 )
{
struct V_160 * V_161 , * V_85 ;
unsigned long V_47 ;
F_87 ( & V_163 , V_47 ) ;
F_213 (info, tmp, &domain->devices, link) {
F_210 ( V_161 ) ;
F_88 ( & V_163 , V_47 ) ;
F_133 ( V_161 ) ;
F_209 ( V_161 -> V_53 , V_161 -> V_73 , V_161 -> V_74 ) ;
if ( F_48 ( V_31 ) ) {
F_214 ( V_161 -> V_53 , V_161 -> V_82 ) ;
F_157 ( V_31 , V_161 -> V_53 ) ;
}
F_47 ( V_161 ) ;
F_87 ( & V_163 , V_47 ) ;
}
F_88 ( & V_163 , V_47 ) ;
}
static struct V_28 * F_215 ( struct V_81 * V_82 )
{
struct V_160 * V_161 ;
V_161 = V_82 -> V_83 . V_53 ;
if ( V_161 )
return V_161 -> V_31 ;
return NULL ;
}
static inline struct V_160 *
F_216 ( int V_89 , int V_73 , int V_74 )
{
struct V_160 * V_161 ;
F_128 (info, &device_domain_list, global)
if ( V_161 -> V_53 -> V_89 == V_89 && V_161 -> V_73 == V_73 &&
V_161 -> V_74 == V_74 )
return V_161 ;
return NULL ;
}
static struct V_28 * F_217 ( struct V_52 * V_53 ,
int V_73 , int V_74 ,
struct V_81 * V_82 ,
struct V_28 * V_31 )
{
struct V_28 * V_64 = NULL ;
struct V_160 * V_161 ;
unsigned long V_47 ;
V_161 = F_46 () ;
if ( ! V_161 )
return NULL ;
V_161 -> V_73 = V_73 ;
V_161 -> V_74 = V_74 ;
V_161 -> V_82 = V_82 ;
V_161 -> V_31 = V_31 ;
V_161 -> V_53 = V_53 ;
F_87 ( & V_163 , V_47 ) ;
if ( V_82 )
V_64 = F_215 ( V_82 ) ;
else {
struct V_160 * V_248 ;
V_248 = F_216 ( V_53 -> V_89 , V_73 , V_74 ) ;
if ( V_248 )
V_64 = V_248 -> V_31 ;
}
if ( V_64 ) {
F_88 ( & V_163 , V_47 ) ;
F_47 ( V_161 ) ;
return V_64 ;
}
F_218 ( & V_161 -> V_246 , & V_31 -> V_90 ) ;
F_218 ( & V_161 -> V_247 , & V_249 ) ;
if ( V_82 )
V_82 -> V_83 . V_53 = V_161 ;
F_88 ( & V_163 , V_47 ) ;
return V_31 ;
}
static int F_219 ( struct V_86 * V_88 , T_3 V_218 , void * V_219 )
{
* ( T_3 * ) V_219 = V_218 ;
return 0 ;
}
static struct V_28 * F_220 ( struct V_81 * V_82 , int V_120 )
{
struct V_28 * V_31 , * V_85 ;
struct V_52 * V_53 ;
struct V_160 * V_161 ;
T_3 V_250 ;
unsigned long V_47 ;
T_2 V_73 , V_74 ;
V_31 = F_215 ( V_82 ) ;
if ( V_31 )
return V_31 ;
V_53 = F_77 ( V_82 , & V_73 , & V_74 ) ;
if ( ! V_53 )
return NULL ;
if ( F_78 ( V_82 ) ) {
struct V_86 * V_88 = F_79 ( V_82 ) ;
F_194 ( V_88 , F_219 , & V_250 ) ;
F_87 ( & V_163 , V_47 ) ;
V_161 = F_216 ( F_80 ( V_88 -> V_73 ) ,
F_192 ( V_250 ) ,
V_250 & 0xff ) ;
if ( V_161 ) {
V_53 = V_161 -> V_53 ;
V_31 = V_161 -> V_31 ;
}
F_88 ( & V_163 , V_47 ) ;
if ( V_161 )
goto V_251;
}
V_31 = F_160 ( 0 ) ;
if ( ! V_31 )
return NULL ;
V_31 -> V_186 = F_166 ( V_31 , V_53 ) ;
if ( V_31 -> V_186 < 0 ) {
F_44 ( V_31 ) ;
return NULL ;
}
F_169 ( V_31 , V_53 ) ;
if ( F_181 ( V_31 , V_120 ) ) {
F_158 ( V_31 ) ;
return NULL ;
}
if ( F_78 ( V_82 ) ) {
V_85 = F_217 ( V_53 , F_192 ( V_250 ) ,
V_250 & 0xff , NULL , V_31 ) ;
if ( ! V_85 || V_85 != V_31 ) {
F_158 ( V_31 ) ;
V_31 = V_85 ;
}
if ( ! V_31 )
return NULL ;
}
V_251:
V_85 = F_217 ( V_53 , V_73 , V_74 , V_82 , V_31 ) ;
if ( ! V_85 || V_85 != V_31 ) {
F_158 ( V_31 ) ;
V_31 = V_85 ;
}
return V_31 ;
}
static int F_221 ( struct V_28 * V_31 ,
unsigned long long V_205 ,
unsigned long long V_95 )
{
unsigned long V_252 = V_205 >> V_12 ;
unsigned long V_253 = V_95 >> V_12 ;
if ( ! F_175 ( & V_31 -> V_206 , F_12 ( V_252 ) ,
F_12 ( V_253 ) ) ) {
F_36 ( V_159 L_28 ) ;
return - V_125 ;
}
F_125 ( L_29 ,
V_205 , V_95 , V_31 -> V_186 ) ;
F_94 ( V_31 , V_252 , V_253 ) ;
return F_208 ( V_31 , V_252 , V_252 ,
V_253 - V_252 + 1 ,
V_110 | V_111 ) ;
}
static int F_222 ( struct V_81 * V_82 ,
unsigned long long V_205 ,
unsigned long long V_95 )
{
struct V_28 * V_31 ;
int V_69 ;
V_31 = F_220 ( V_82 , V_57 ) ;
if ( ! V_31 )
return - V_125 ;
if ( V_31 == V_254 && V_255 ) {
F_36 ( L_30 ,
F_223 ( V_82 ) , V_205 , V_95 ) ;
return 0 ;
}
F_36 ( V_35
L_31 ,
F_223 ( V_82 ) , V_205 , V_95 ) ;
if ( V_95 < V_205 ) {
F_224 ( 1 , L_32
L_33 ,
F_225 ( V_256 ) ,
F_225 ( V_257 ) ,
F_225 ( V_258 ) ) ;
V_69 = - V_259 ;
goto error;
}
if ( V_95 >> F_2 ( V_31 -> V_1 ) ) {
F_224 ( 1 , L_34
L_33 ,
F_2 ( V_31 -> V_1 ) ,
F_225 ( V_256 ) ,
F_225 ( V_257 ) ,
F_225 ( V_258 ) ) ;
V_69 = - V_259 ;
goto error;
}
V_69 = F_221 ( V_31 , V_205 , V_95 ) ;
if ( V_69 )
goto error;
V_69 = F_193 ( V_31 , V_82 , V_212 ) ;
if ( V_69 )
goto error;
return 0 ;
error:
F_158 ( V_31 ) ;
return V_69 ;
}
static inline int F_226 ( struct V_260 * V_261 ,
struct V_81 * V_82 )
{
if ( V_82 -> V_83 . V_53 == V_84 )
return 0 ;
return F_222 ( V_82 , V_261 -> V_262 ,
V_261 -> V_263 ) ;
}
static inline void F_227 ( void )
{
struct V_86 * V_88 ;
int V_69 ;
V_88 = F_228 ( V_264 << 8 , NULL ) ;
if ( ! V_88 )
return;
F_36 ( V_35 L_35 ) ;
V_69 = F_222 ( & V_88 -> V_82 , 0 , 16 * 1024 * 1024 - 1 ) ;
if ( V_69 )
F_36 ( V_159 L_36
L_37 ) ;
F_229 ( V_88 ) ;
}
static inline void F_227 ( void )
{
return;
}
static int T_1 F_230 ( int V_265 )
{
struct V_62 * V_63 ;
struct V_52 * V_53 ;
int V_108 , V_69 = 0 ;
bool V_266 = true ;
V_254 = F_160 ( V_49 ) ;
if ( ! V_254 )
return - V_213 ;
F_63 (iommu, drhd) {
V_69 = F_166 ( V_254 , V_53 ) ;
if ( V_69 < 0 ) {
F_158 ( V_254 ) ;
return - V_213 ;
} else if ( V_266 ) {
V_254 -> V_186 = V_69 ;
V_266 = false ;
} else if ( V_254 -> V_186 != V_69 ) {
F_158 ( V_254 ) ;
return - V_213 ;
}
F_169 ( V_254 , V_53 ) ;
}
if ( F_231 ( V_254 , V_57 ) ) {
F_158 ( V_254 ) ;
return - V_213 ;
}
F_125 ( L_38 ,
V_254 -> V_186 ) ;
if ( V_265 )
return 0 ;
F_232 (nid) {
unsigned long V_114 , V_267 ;
int V_65 ;
F_233 (i, nid, &start_pfn, &end_pfn, NULL) {
V_69 = F_221 ( V_254 ,
F_234 ( V_114 ) , F_234 ( V_267 ) ) ;
if ( V_69 )
return V_69 ;
}
}
return 0 ;
}
static int F_235 ( struct V_81 * V_82 )
{
struct V_160 * V_161 ;
if ( F_236 ( ! V_268 ) )
return 0 ;
V_161 = V_82 -> V_83 . V_53 ;
if ( V_161 && V_161 != V_84 )
return ( V_161 -> V_31 == V_254 ) ;
return 0 ;
}
static int F_237 ( struct V_28 * V_31 ,
struct V_81 * V_82 , int V_210 )
{
struct V_28 * V_269 ;
struct V_52 * V_53 ;
T_2 V_73 , V_74 ;
int V_69 ;
V_53 = F_77 ( V_82 , & V_73 , & V_74 ) ;
if ( ! V_53 )
return - V_200 ;
V_269 = F_217 ( V_53 , V_73 , V_74 , V_82 , V_31 ) ;
if ( V_269 != V_31 )
return - V_270 ;
V_69 = F_193 ( V_31 , V_82 , V_210 ) ;
if ( V_69 ) {
F_238 ( V_31 , V_82 ) ;
return V_69 ;
}
return 0 ;
}
static bool F_239 ( struct V_81 * V_82 )
{
struct V_260 * V_261 ;
struct V_81 * V_85 ;
int V_65 ;
F_62 () ;
F_240 (rmrr) {
F_83 (rmrr->devices,
rmrr->devices_cnt, i, tmp)
if ( V_85 == V_82 ) {
F_64 () ;
return true ;
}
}
F_64 () ;
return false ;
}
static bool F_241 ( struct V_81 * V_82 )
{
if ( ! F_239 ( V_82 ) )
return false ;
if ( F_78 ( V_82 ) ) {
struct V_86 * V_88 = F_79 ( V_82 ) ;
if ( F_242 ( V_88 ) || F_243 ( V_88 ) )
return false ;
}
return true ;
}
static int F_244 ( struct V_81 * V_82 , int V_271 )
{
if ( F_78 ( V_82 ) ) {
struct V_86 * V_88 = F_79 ( V_82 ) ;
if ( F_241 ( V_82 ) )
return 0 ;
if ( ( V_268 & V_272 ) && F_245 ( V_88 ) )
return 1 ;
if ( ( V_268 & V_273 ) && F_243 ( V_88 ) )
return 1 ;
if ( ! ( V_268 & V_274 ) )
return 0 ;
if ( ! F_246 ( V_88 ) ) {
if ( ! F_247 ( V_88 -> V_73 ) )
return 0 ;
if ( V_88 -> V_275 >> 8 == V_276 )
return 0 ;
} else if ( F_248 ( V_88 ) == V_277 )
return 0 ;
} else {
if ( F_239 ( V_82 ) )
return 0 ;
}
if ( ! V_271 ) {
V_20 V_278 = * V_82 -> V_278 ;
if ( V_82 -> V_279 &&
V_82 -> V_279 < V_278 )
V_278 = V_82 -> V_279 ;
return V_278 >= F_249 ( V_82 ) ;
}
return 1 ;
}
static int T_1 F_250 ( struct V_81 * V_82 , int V_265 )
{
int V_69 ;
if ( ! F_244 ( V_82 , 1 ) )
return 0 ;
V_69 = F_237 ( V_254 , V_82 ,
V_265 ? V_211 :
V_212 ) ;
if ( ! V_69 )
F_251 ( L_39 ,
V_265 ? L_40 : L_41 , F_223 ( V_82 ) ) ;
else if ( V_69 == - V_200 )
V_69 = 0 ;
return V_69 ;
}
static int T_1 F_252 ( int V_265 )
{
struct V_86 * V_88 = NULL ;
struct V_62 * V_63 ;
struct V_52 * V_53 ;
struct V_81 * V_82 ;
int V_65 ;
int V_69 = 0 ;
V_69 = F_230 ( V_265 ) ;
if ( V_69 )
return - V_213 ;
F_177 (pdev) {
V_69 = F_250 ( & V_88 -> V_82 , V_265 ) ;
if ( V_69 )
return V_69 ;
}
F_63 (iommu, drhd)
F_83 (drhd->devices, drhd->devices_cnt, i, dev) {
struct V_280 * V_281 ;
struct V_282 * V_283 ;
if ( V_82 -> V_73 != & V_284 )
continue;
V_283 = F_253 ( V_82 ) ;
F_254 ( & V_283 -> V_285 ) ;
F_128 (pn, &adev->physical_node_list, node) {
V_69 = F_250 ( V_281 -> V_82 , V_265 ) ;
if ( V_69 )
break;
}
F_255 ( & V_283 -> V_285 ) ;
if ( V_69 )
return V_69 ;
}
return 0 ;
}
static void F_256 ( struct V_52 * V_53 )
{
if ( ! V_53 -> V_162 ) {
F_257 ( - 1 , V_53 ) ;
F_258 ( V_53 ) ;
}
if ( F_259 ( V_53 ) ) {
V_53 -> V_170 . V_216 = F_114 ;
V_53 -> V_170 . V_171 = F_119 ;
F_251 ( L_42 ,
V_53 -> V_124 ) ;
} else {
V_53 -> V_170 . V_216 = V_286 ;
V_53 -> V_170 . V_171 = V_287 ;
F_251 ( L_43 , V_53 -> V_124 ) ;
}
}
static int T_1 F_260 ( void )
{
struct V_62 * V_63 ;
struct V_260 * V_261 ;
struct V_81 * V_82 ;
struct V_52 * V_53 ;
int V_65 , V_69 ;
F_261 (drhd) {
if ( V_60 < V_288 ) {
V_60 ++ ;
continue;
}
F_262 ( V_159 L_44 ,
V_288 ) ;
}
if ( V_60 < V_288 )
V_60 = V_288 ;
V_61 = F_152 ( V_60 , sizeof( struct V_52 * ) ,
V_183 ) ;
if ( ! V_61 ) {
F_36 ( V_159 L_45 ) ;
V_69 = - V_125 ;
goto error;
}
V_289 = F_263 ( V_60 *
sizeof( struct V_290 ) , V_183 ) ;
if ( ! V_289 ) {
V_69 = - V_125 ;
goto V_291;
}
F_63 (iommu, drhd) {
V_61 [ V_53 -> V_181 ] = V_53 ;
V_69 = F_148 ( V_53 ) ;
if ( V_69 )
goto V_292;
V_69 = F_104 ( V_53 ) ;
if ( V_69 )
goto V_292;
if ( ! F_264 ( V_53 -> V_67 ) )
V_255 = 0 ;
}
F_63 (iommu, drhd)
F_256 ( V_53 ) ;
if ( V_293 )
V_268 |= V_274 ;
#ifdef F_265
V_268 |= V_273 ;
#endif
F_266 () ;
if ( V_268 ) {
V_69 = F_252 ( V_255 ) ;
if ( V_69 ) {
F_36 ( V_245 L_46 ) ;
goto V_292;
}
}
F_36 ( V_35 L_47 ) ;
F_240 (rmrr) {
F_83 (rmrr->devices, rmrr->devices_cnt,
i, dev) {
V_69 = F_226 ( V_261 , V_82 ) ;
if ( V_69 )
F_36 ( V_159
L_48 ) ;
}
}
F_227 () ;
F_267 (iommu, drhd) {
if ( V_63 -> V_294 ) {
if ( V_295 )
F_145 ( V_53 ) ;
continue;
}
F_112 ( V_53 ) ;
V_69 = F_268 ( V_53 ) ;
if ( V_69 )
goto V_292;
F_106 ( V_53 ) ;
V_53 -> V_170 . V_216 ( V_53 , 0 , 0 , 0 , V_145 ) ;
V_53 -> V_170 . V_171 ( V_53 , 0 , 0 , 0 , V_154 ) ;
F_146 ( V_53 ) ;
F_145 ( V_53 ) ;
}
return 0 ;
V_292:
F_63 (iommu, drhd) {
F_155 ( V_53 ) ;
F_159 ( V_53 ) ;
}
F_153 ( V_289 ) ;
V_291:
F_153 ( V_61 ) ;
error:
return V_69 ;
}
static struct V_192 * F_269 ( struct V_81 * V_82 ,
struct V_28 * V_31 ,
unsigned long V_296 , T_4 V_278 )
{
struct V_192 * V_192 = NULL ;
V_278 = F_3 ( T_4 , F_270 ( V_31 -> V_120 ) , V_278 ) ;
if ( ! V_37 && V_278 > F_271 ( 32 ) ) {
V_192 = F_272 ( & V_31 -> V_206 , V_296 ,
F_176 ( F_271 ( 32 ) ) , 1 ) ;
if ( V_192 )
return V_192 ;
}
V_192 = F_272 ( & V_31 -> V_206 , V_296 , F_176 ( V_278 ) , 1 ) ;
if ( F_190 ( ! V_192 ) ) {
F_36 ( V_159 L_49 ,
V_296 , F_223 ( V_82 ) ) ;
return NULL ;
}
return V_192 ;
}
static struct V_28 * F_273 ( struct V_81 * V_82 )
{
struct V_28 * V_31 ;
int V_69 ;
V_31 = F_220 ( V_82 , V_57 ) ;
if ( ! V_31 ) {
F_36 ( V_159 L_50 ,
F_223 ( V_82 ) ) ;
return NULL ;
}
if ( F_190 ( ! F_196 ( V_82 ) ) ) {
V_69 = F_193 ( V_31 , V_82 , V_212 ) ;
if ( V_69 ) {
F_36 ( V_159 L_51 ,
F_223 ( V_82 ) ) ;
return NULL ;
}
}
return V_31 ;
}
static inline struct V_28 * F_274 ( struct V_81 * V_82 )
{
struct V_160 * V_161 ;
V_161 = V_82 -> V_83 . V_53 ;
if ( F_236 ( V_161 ) )
return V_161 -> V_31 ;
return F_273 ( V_82 ) ;
}
static int F_275 ( struct V_81 * V_82 )
{
int V_64 ;
if ( F_76 ( V_82 ) )
return 1 ;
if ( ! V_268 )
return 0 ;
V_64 = F_235 ( V_82 ) ;
if ( V_64 ) {
if ( F_244 ( V_82 , 0 ) )
return 1 ;
else {
F_238 ( V_254 , V_82 ) ;
F_36 ( V_35 L_52 ,
F_223 ( V_82 ) ) ;
return 0 ;
}
} else {
if ( F_244 ( V_82 , 0 ) ) {
int V_69 ;
V_69 = F_237 ( V_254 , V_82 ,
V_255 ?
V_211 :
V_212 ) ;
if ( ! V_69 ) {
F_36 ( V_35 L_53 ,
F_223 ( V_82 ) ) ;
return 1 ;
}
}
}
return 0 ;
}
static V_242 F_276 ( struct V_81 * V_82 , T_8 V_297 ,
T_7 V_99 , int V_298 , V_20 V_278 )
{
struct V_28 * V_31 ;
T_8 V_299 ;
struct V_192 * V_192 ;
int V_234 = 0 ;
int V_69 ;
struct V_52 * V_53 ;
unsigned long V_300 = V_297 >> V_11 ;
F_57 ( V_298 == V_301 ) ;
if ( F_275 ( V_82 ) )
return V_297 ;
V_31 = F_274 ( V_82 ) ;
if ( ! V_31 )
return 0 ;
V_53 = F_56 ( V_31 ) ;
V_99 = F_197 ( V_297 , V_99 ) ;
V_192 = F_269 ( V_82 , V_31 , F_12 ( V_99 ) , V_278 ) ;
if ( ! V_192 )
goto error;
if ( V_298 == V_302 || V_298 == V_303 || \
! F_277 ( V_53 -> V_56 ) )
V_234 |= V_110 ;
if ( V_298 == V_304 || V_298 == V_303 )
V_234 |= V_111 ;
V_69 = F_208 ( V_31 , F_13 ( V_192 -> V_305 ) ,
F_13 ( V_300 ) , V_99 , V_234 ) ;
if ( V_69 )
goto error;
if ( F_144 ( V_53 -> V_56 ) )
F_139 ( V_53 , V_31 -> V_186 , F_13 ( V_192 -> V_305 ) , V_99 , 0 , 1 ) ;
else
F_112 ( V_53 ) ;
V_299 = ( T_8 ) V_192 -> V_305 << V_11 ;
V_299 += V_297 & ~ V_223 ;
return V_299 ;
error:
if ( V_192 )
F_278 ( & V_31 -> V_206 , V_192 ) ;
F_36 ( V_159 L_54 ,
F_223 ( V_82 ) , V_99 , ( unsigned long long ) V_297 , V_298 ) ;
return 0 ;
}
static V_242 F_279 ( struct V_81 * V_82 , struct V_14 * V_14 ,
unsigned long V_104 , T_7 V_99 ,
enum V_306 V_298 ,
struct V_307 * V_308 )
{
return F_276 ( V_82 , F_201 ( V_14 ) + V_104 , V_99 ,
V_298 , * V_82 -> V_278 ) ;
}
static void F_280 ( void )
{
int V_65 , V_309 ;
V_310 = 0 ;
for ( V_65 = 0 ; V_65 < V_60 ; V_65 ++ ) {
struct V_52 * V_53 = V_61 [ V_65 ] ;
if ( ! V_53 )
continue;
if ( ! V_289 [ V_65 ] . V_119 )
continue;
if ( ! F_144 ( V_53 -> V_56 ) )
V_53 -> V_170 . V_171 ( V_53 , 0 , 0 , 0 ,
V_154 ) ;
for ( V_309 = 0 ; V_309 < V_289 [ V_65 ] . V_119 ; V_309 ++ ) {
unsigned long V_70 ;
struct V_192 * V_192 = V_289 [ V_65 ] . V_192 [ V_309 ] ;
struct V_28 * V_31 = V_289 [ V_65 ] . V_31 [ V_309 ] ;
if ( F_144 ( V_53 -> V_56 ) )
F_139 ( V_53 , V_31 -> V_186 ,
V_192 -> V_305 , F_281 ( V_192 ) ,
! V_289 [ V_65 ] . V_121 [ V_309 ] , 0 ) ;
else {
V_70 = F_140 ( F_13 ( F_281 ( V_192 ) ) ) ;
F_136 ( V_289 [ V_65 ] . V_31 [ V_309 ] ,
( T_4 ) V_192 -> V_305 << V_11 , V_70 ) ;
}
F_278 ( & V_289 [ V_65 ] . V_31 [ V_309 ] -> V_206 , V_192 ) ;
if ( V_289 [ V_65 ] . V_121 [ V_309 ] )
F_103 ( V_289 [ V_65 ] . V_121 [ V_309 ] ) ;
}
V_289 [ V_65 ] . V_119 = 0 ;
}
V_311 = 0 ;
}
static void F_184 ( unsigned long V_221 )
{
unsigned long V_47 ;
F_87 ( & V_312 , V_47 ) ;
F_280 () ;
F_88 ( & V_312 , V_47 ) ;
}
static void F_282 ( struct V_28 * V_30 , struct V_192 * V_192 , struct V_14 * V_121 )
{
unsigned long V_47 ;
int V_119 , V_58 ;
struct V_52 * V_53 ;
F_87 ( & V_312 , V_47 ) ;
if ( V_311 == V_313 )
F_280 () ;
V_53 = F_56 ( V_30 ) ;
V_58 = V_53 -> V_181 ;
V_119 = V_289 [ V_58 ] . V_119 ;
V_289 [ V_58 ] . V_31 [ V_119 ] = V_30 ;
V_289 [ V_58 ] . V_192 [ V_119 ] = V_192 ;
V_289 [ V_58 ] . V_121 [ V_119 ] = V_121 ;
V_289 [ V_58 ] . V_119 ++ ;
if ( ! V_310 ) {
F_283 ( & V_314 , V_315 + F_284 ( 10 ) ) ;
V_310 = 1 ;
}
V_311 ++ ;
F_88 ( & V_312 , V_47 ) ;
}
static void F_285 ( struct V_81 * V_82 , V_242 V_316 )
{
struct V_28 * V_31 ;
unsigned long V_114 , V_115 ;
struct V_192 * V_192 ;
struct V_52 * V_53 ;
struct V_14 * V_121 ;
if ( F_275 ( V_82 ) )
return;
V_31 = F_215 ( V_82 ) ;
F_57 ( ! V_31 ) ;
V_53 = F_56 ( V_31 ) ;
V_192 = F_286 ( & V_31 -> V_206 , F_176 ( V_316 ) ) ;
if ( F_287 ( ! V_192 , L_55 ,
( unsigned long long ) V_316 ) )
return;
V_114 = F_13 ( V_192 -> V_305 ) ;
V_115 = F_13 ( V_192 -> V_317 + 1 ) - 1 ;
F_125 ( L_56 ,
F_223 ( V_82 ) , V_114 , V_115 ) ;
V_121 = F_102 ( V_31 , V_114 , V_115 ) ;
if ( V_38 ) {
F_139 ( V_53 , V_31 -> V_186 , V_114 ,
V_115 - V_114 + 1 , ! V_121 , 0 ) ;
F_278 ( & V_31 -> V_206 , V_192 ) ;
F_103 ( V_121 ) ;
} else {
F_282 ( V_31 , V_192 , V_121 ) ;
}
}
static void F_288 ( struct V_81 * V_82 , V_242 V_316 ,
T_7 V_99 , enum V_306 V_298 ,
struct V_307 * V_308 )
{
F_285 ( V_82 , V_316 ) ;
}
static void * F_289 ( struct V_81 * V_82 , T_7 V_99 ,
V_242 * V_318 , T_9 V_47 ,
struct V_307 * V_308 )
{
struct V_14 * V_14 = NULL ;
int V_319 ;
V_99 = F_198 ( V_99 ) ;
V_319 = F_290 ( V_99 ) ;
if ( ! F_275 ( V_82 ) )
V_47 &= ~ ( V_320 | V_321 ) ;
else if ( V_82 -> V_279 < F_249 ( V_82 ) ) {
if ( V_82 -> V_279 < F_271 ( 32 ) )
V_47 |= V_320 ;
else
V_47 |= V_321 ;
}
if ( V_47 & V_322 ) {
unsigned int V_190 = V_99 >> V_11 ;
V_14 = F_291 ( V_82 , V_190 , V_319 ) ;
if ( V_14 && F_275 ( V_82 ) &&
F_201 ( V_14 ) + V_99 > V_82 -> V_279 ) {
F_292 ( V_82 , V_14 , V_190 ) ;
V_14 = NULL ;
}
}
if ( ! V_14 )
V_14 = F_293 ( V_47 , V_319 ) ;
if ( ! V_14 )
return NULL ;
memset ( F_39 ( V_14 ) , 0 , V_99 ) ;
* V_318 = F_276 ( V_82 , F_201 ( V_14 ) , V_99 ,
V_303 ,
V_82 -> V_279 ) ;
if ( * V_318 )
return F_39 ( V_14 ) ;
if ( ! F_292 ( V_82 , V_14 , V_99 >> V_11 ) )
F_294 ( V_14 , V_319 ) ;
return NULL ;
}
static void F_295 ( struct V_81 * V_82 , T_7 V_99 , void * V_42 ,
V_242 V_318 , struct V_307 * V_308 )
{
int V_319 ;
struct V_14 * V_14 = F_17 ( V_42 ) ;
V_99 = F_198 ( V_99 ) ;
V_319 = F_290 ( V_99 ) ;
F_285 ( V_82 , V_318 ) ;
if ( ! F_292 ( V_82 , V_14 , V_99 >> V_11 ) )
F_294 ( V_14 , V_319 ) ;
}
static void F_296 ( struct V_81 * V_82 , struct V_230 * V_323 ,
int V_324 , enum V_306 V_298 ,
struct V_307 * V_308 )
{
F_285 ( V_82 , V_323 [ 0 ] . V_241 ) ;
}
static int F_297 ( struct V_81 * V_325 ,
struct V_230 * V_323 , int V_324 , int V_298 )
{
int V_65 ;
struct V_230 * V_231 ;
F_298 (sglist, sg, nelems, i) {
F_57 ( ! F_202 ( V_231 ) ) ;
V_231 -> V_241 = F_201 ( F_202 ( V_231 ) ) + V_231 -> V_104 ;
V_231 -> V_243 = V_231 -> V_240 ;
}
return V_324 ;
}
static int F_299 ( struct V_81 * V_82 , struct V_230 * V_323 , int V_324 ,
enum V_306 V_298 , struct V_307 * V_308 )
{
int V_65 ;
struct V_28 * V_31 ;
T_7 V_99 = 0 ;
int V_234 = 0 ;
struct V_192 * V_192 = NULL ;
int V_69 ;
struct V_230 * V_231 ;
unsigned long V_326 ;
struct V_52 * V_53 ;
F_57 ( V_298 == V_301 ) ;
if ( F_275 ( V_82 ) )
return F_297 ( V_82 , V_323 , V_324 , V_298 ) ;
V_31 = F_274 ( V_82 ) ;
if ( ! V_31 )
return 0 ;
V_53 = F_56 ( V_31 ) ;
F_298 (sglist, sg, nelems, i)
V_99 += F_197 ( V_231 -> V_104 , V_231 -> V_240 ) ;
V_192 = F_269 ( V_82 , V_31 , F_12 ( V_99 ) ,
* V_82 -> V_278 ) ;
if ( ! V_192 ) {
V_323 -> V_243 = 0 ;
return 0 ;
}
if ( V_298 == V_302 || V_298 == V_303 || \
! F_277 ( V_53 -> V_56 ) )
V_234 |= V_110 ;
if ( V_298 == V_304 || V_298 == V_303 )
V_234 |= V_111 ;
V_326 = F_13 ( V_192 -> V_305 ) ;
V_69 = F_207 ( V_31 , V_326 , V_323 , V_99 , V_234 ) ;
if ( F_190 ( V_69 ) ) {
F_97 ( V_31 , V_326 ,
V_326 + V_99 - 1 ) ;
F_278 ( & V_31 -> V_206 , V_192 ) ;
return 0 ;
}
if ( F_144 ( V_53 -> V_56 ) )
F_139 ( V_53 , V_31 -> V_186 , V_326 , V_99 , 0 , 1 ) ;
else
F_112 ( V_53 ) ;
return V_324 ;
}
static int F_300 ( struct V_81 * V_82 , V_242 V_327 )
{
return ! V_327 ;
}
static inline int F_301 ( void )
{
int V_69 = 0 ;
V_45 = F_302 ( L_57 ,
sizeof( struct V_28 ) ,
0 ,
V_328 ,
NULL ) ;
if ( ! V_45 ) {
F_36 ( V_159 L_58 ) ;
V_69 = - V_125 ;
}
return V_69 ;
}
static inline int F_303 ( void )
{
int V_69 = 0 ;
V_46 = F_302 ( L_59 ,
sizeof( struct V_160 ) ,
0 ,
V_328 ,
NULL ) ;
if ( ! V_46 ) {
F_36 ( V_159 L_60 ) ;
V_69 = - V_125 ;
}
return V_69 ;
}
static int T_1 F_304 ( void )
{
int V_69 ;
V_69 = F_305 () ;
if ( V_69 )
return V_69 ;
V_69 = F_301 () ;
if ( V_69 )
goto V_329;
V_69 = F_303 () ;
if ( ! V_69 )
return V_69 ;
F_306 ( V_45 ) ;
V_329:
F_307 () ;
return - V_125 ;
}
static void T_1 F_308 ( void )
{
F_306 ( V_46 ) ;
F_306 ( V_45 ) ;
F_307 () ;
}
static void F_309 ( struct V_86 * V_88 )
{
struct V_62 * V_63 ;
T_5 V_330 ;
int V_331 ;
V_331 = F_310 ( V_88 -> V_73 , F_311 ( 0 , 0 ) , 0xb0 , & V_330 ) ;
if ( V_331 ) {
F_312 ( & V_88 -> V_82 , L_61 ) ;
return;
}
V_330 &= 0xffff0000 ;
V_63 = F_313 ( V_88 ) ;
if ( F_314 ( ! V_63 || V_63 -> V_332 - V_330 != 0xa000 ,
V_333 ,
L_62 ) )
V_88 -> V_82 . V_83 . V_53 = V_84 ;
}
static void T_1 F_315 ( void )
{
struct V_62 * V_63 ;
struct V_81 * V_82 ;
int V_65 ;
F_261 (drhd) {
if ( ! V_63 -> V_97 ) {
F_83 (drhd->devices,
drhd->devices_cnt, i, dev)
break;
if ( V_65 == V_63 -> V_334 )
V_63 -> V_294 = 1 ;
}
}
F_316 (drhd) {
if ( V_63 -> V_97 )
continue;
F_83 (drhd->devices,
drhd->devices_cnt, i, dev)
if ( ! F_78 ( V_82 ) || ! F_243 ( F_79 ( V_82 ) ) )
break;
if ( V_65 < V_63 -> V_334 )
continue;
if ( V_36 ) {
V_335 = 1 ;
} else {
V_63 -> V_294 = 1 ;
F_83 (drhd->devices,
drhd->devices_cnt, i, dev)
V_82 -> V_83 . V_53 = V_84 ;
}
}
}
static int F_317 ( void )
{
struct V_62 * V_63 ;
struct V_52 * V_53 = NULL ;
F_63 (iommu, drhd)
if ( V_53 -> V_162 )
F_318 ( V_53 ) ;
F_267 (iommu, drhd) {
if ( V_63 -> V_294 ) {
if ( V_295 )
F_145 ( V_53 ) ;
continue;
}
F_112 ( V_53 ) ;
F_106 ( V_53 ) ;
V_53 -> V_170 . V_216 ( V_53 , 0 , 0 , 0 ,
V_145 ) ;
V_53 -> V_170 . V_171 ( V_53 , 0 , 0 , 0 , V_154 ) ;
F_146 ( V_53 ) ;
F_145 ( V_53 ) ;
}
return 0 ;
}
static void F_319 ( void )
{
struct V_62 * V_63 ;
struct V_52 * V_53 ;
F_63 (iommu, drhd) {
V_53 -> V_170 . V_216 ( V_53 , 0 , 0 , 0 ,
V_145 ) ;
V_53 -> V_170 . V_171 ( V_53 , 0 , 0 , 0 ,
V_154 ) ;
}
}
static int F_320 ( void )
{
struct V_62 * V_63 ;
struct V_52 * V_53 = NULL ;
unsigned long V_128 ;
F_63 (iommu, drhd) {
V_53 -> V_336 = F_263 ( sizeof( T_5 ) * V_337 ,
V_43 ) ;
if ( ! V_53 -> V_336 )
goto V_338;
}
F_319 () ;
F_63 (iommu, drhd) {
F_147 ( V_53 ) ;
F_107 ( & V_53 -> V_130 , V_128 ) ;
V_53 -> V_336 [ V_339 ] =
V_137 ( V_53 -> V_131 + V_340 ) ;
V_53 -> V_336 [ V_341 ] =
V_137 ( V_53 -> V_131 + V_342 ) ;
V_53 -> V_336 [ V_343 ] =
V_137 ( V_53 -> V_131 + V_344 ) ;
V_53 -> V_336 [ V_345 ] =
V_137 ( V_53 -> V_131 + V_346 ) ;
F_111 ( & V_53 -> V_130 , V_128 ) ;
}
return 0 ;
V_338:
F_63 (iommu, drhd)
F_153 ( V_53 -> V_336 ) ;
return - V_125 ;
}
static void F_321 ( void )
{
struct V_62 * V_63 ;
struct V_52 * V_53 = NULL ;
unsigned long V_128 ;
if ( F_317 () ) {
if ( V_295 )
F_322 ( L_63 ) ;
else
F_224 ( 1 , L_64 ) ;
return;
}
F_63 (iommu, drhd) {
F_107 ( & V_53 -> V_130 , V_128 ) ;
F_109 ( V_53 -> V_336 [ V_339 ] ,
V_53 -> V_131 + V_340 ) ;
F_109 ( V_53 -> V_336 [ V_341 ] ,
V_53 -> V_131 + V_342 ) ;
F_109 ( V_53 -> V_336 [ V_343 ] ,
V_53 -> V_131 + V_344 ) ;
F_109 ( V_53 -> V_336 [ V_345 ] ,
V_53 -> V_131 + V_346 ) ;
F_111 ( & V_53 -> V_130 , V_128 ) ;
}
F_63 (iommu, drhd)
F_153 ( V_53 -> V_336 ) ;
}
static void T_1 F_323 ( void )
{
F_324 ( & V_347 ) ;
}
static inline void F_323 ( void ) {}
int T_1 F_325 ( struct V_348 * V_349 , void * V_350 )
{
struct V_351 * V_261 ;
struct V_260 * V_352 ;
V_352 = F_263 ( sizeof( * V_352 ) , V_183 ) ;
if ( ! V_352 )
return - V_125 ;
V_352 -> V_353 = V_349 ;
V_261 = (struct V_351 * ) V_349 ;
V_352 -> V_262 = V_261 -> V_262 ;
V_352 -> V_263 = V_261 -> V_263 ;
V_352 -> V_90 = F_326 ( ( void * ) ( V_261 + 1 ) ,
( ( void * ) V_261 ) + V_261 -> V_349 . V_240 ,
& V_352 -> V_334 ) ;
if ( V_352 -> V_334 && V_352 -> V_90 == NULL ) {
F_153 ( V_352 ) ;
return - V_125 ;
}
F_218 ( & V_352 -> V_354 , & V_355 ) ;
return 0 ;
}
static struct V_356 * F_327 ( struct V_357 * V_358 )
{
struct V_356 * V_359 ;
struct V_357 * V_85 ;
F_328 (atsru, &dmar_atsr_units, list) {
V_85 = (struct V_357 * ) V_359 -> V_353 ;
if ( V_358 -> V_89 != V_85 -> V_89 )
continue;
if ( V_358 -> V_349 . V_240 != V_85 -> V_349 . V_240 )
continue;
if ( memcmp ( V_358 , V_85 , V_358 -> V_349 . V_240 ) == 0 )
return V_359 ;
}
return NULL ;
}
int F_329 ( struct V_348 * V_353 , void * V_350 )
{
struct V_357 * V_358 ;
struct V_356 * V_359 ;
if ( V_360 != V_361 && ! V_362 )
return 0 ;
V_358 = F_34 ( V_353 , struct V_357 , V_349 ) ;
V_359 = F_327 ( V_358 ) ;
if ( V_359 )
return 0 ;
V_359 = F_263 ( sizeof( * V_359 ) + V_353 -> V_240 , V_183 ) ;
if ( ! V_359 )
return - V_125 ;
V_359 -> V_353 = ( void * ) ( V_359 + 1 ) ;
memcpy ( V_359 -> V_353 , V_353 , V_353 -> V_240 ) ;
V_359 -> V_97 = V_358 -> V_47 & 0x1 ;
if ( ! V_359 -> V_97 ) {
V_359 -> V_90 = F_326 ( ( void * ) ( V_358 + 1 ) ,
( void * ) V_358 + V_358 -> V_349 . V_240 ,
& V_359 -> V_334 ) ;
if ( V_359 -> V_334 && V_359 -> V_90 == NULL ) {
F_153 ( V_359 ) ;
return - V_125 ;
}
}
F_330 ( & V_359 -> V_354 , & V_363 ) ;
return 0 ;
}
static void F_331 ( struct V_356 * V_359 )
{
F_332 ( & V_359 -> V_90 , & V_359 -> V_334 ) ;
F_153 ( V_359 ) ;
}
int F_333 ( struct V_348 * V_353 , void * V_350 )
{
struct V_357 * V_358 ;
struct V_356 * V_359 ;
V_358 = F_34 ( V_353 , struct V_357 , V_349 ) ;
V_359 = F_327 ( V_358 ) ;
if ( V_359 ) {
F_334 ( & V_359 -> V_354 ) ;
F_335 () ;
F_331 ( V_359 ) ;
}
return 0 ;
}
int F_336 ( struct V_348 * V_353 , void * V_350 )
{
int V_65 ;
struct V_81 * V_82 ;
struct V_357 * V_358 ;
struct V_356 * V_359 ;
V_358 = F_34 ( V_353 , struct V_357 , V_349 ) ;
V_359 = F_327 ( V_358 ) ;
if ( ! V_359 )
return 0 ;
if ( ! V_359 -> V_97 && V_359 -> V_90 && V_359 -> V_334 )
F_83 (atsru->devices, atsru->devices_cnt,
i, dev)
return - V_270 ;
return 0 ;
}
static int F_337 ( struct V_62 * V_364 )
{
int V_365 , V_69 = 0 ;
struct V_52 * V_53 = V_364 -> V_53 ;
if ( V_61 [ V_53 -> V_181 ] )
return 0 ;
if ( V_255 && ! F_264 ( V_53 -> V_67 ) ) {
F_338 ( L_65 ,
V_53 -> V_124 ) ;
return - V_366 ;
}
if ( ! F_66 ( V_53 -> V_67 ) &&
F_65 ( V_53 ) ) {
F_338 ( L_66 ,
V_53 -> V_124 ) ;
return - V_366 ;
}
V_365 = F_67 ( V_53 ) - 1 ;
if ( V_365 >= 0 && ! ( F_68 ( V_53 -> V_56 ) & ( 1 << V_365 ) ) ) {
F_338 ( L_67 ,
V_53 -> V_124 ) ;
return - V_366 ;
}
if ( V_53 -> V_133 & V_177 )
F_147 ( V_53 ) ;
V_61 [ V_53 -> V_181 ] = V_53 ;
V_69 = F_148 ( V_53 ) ;
if ( V_69 == 0 )
V_69 = F_104 ( V_53 ) ;
if ( V_69 )
goto V_91;
if ( V_364 -> V_294 ) {
if ( V_295 )
F_145 ( V_53 ) ;
return 0 ;
}
F_256 ( V_53 ) ;
F_112 ( V_53 ) ;
V_69 = F_268 ( V_53 ) ;
if ( V_69 )
goto V_367;
F_106 ( V_53 ) ;
V_53 -> V_170 . V_216 ( V_53 , 0 , 0 , 0 , V_145 ) ;
V_53 -> V_170 . V_171 ( V_53 , 0 , 0 , 0 , V_154 ) ;
F_146 ( V_53 ) ;
if ( V_254 ) {
V_69 = F_166 ( V_254 , V_53 ) ;
if ( V_69 < 0 || V_254 -> V_186 != V_69 )
goto V_367;
F_169 ( V_254 , V_53 ) ;
}
F_145 ( V_53 ) ;
return 0 ;
V_367:
F_155 ( V_53 ) ;
V_91:
F_159 ( V_53 ) ;
return V_69 ;
}
int F_339 ( struct V_62 * V_364 , bool V_368 )
{
int V_69 = 0 ;
struct V_52 * V_53 = V_364 -> V_53 ;
if ( ! V_362 )
return 0 ;
if ( V_53 == NULL )
return - V_33 ;
if ( V_368 ) {
V_69 = F_337 ( V_364 ) ;
} else {
F_155 ( V_53 ) ;
F_159 ( V_53 ) ;
}
return V_69 ;
}
static void F_340 ( void )
{
struct V_260 * V_352 , * V_369 ;
struct V_356 * V_359 , * V_370 ;
F_213 (rmrru, rmrr_n, &dmar_rmrr_units, list) {
F_212 ( & V_352 -> V_354 ) ;
F_332 ( & V_352 -> V_90 , & V_352 -> V_334 ) ;
F_153 ( V_352 ) ;
}
F_213 (atsru, atsr_n, &dmar_atsr_units, list) {
F_212 ( & V_359 -> V_354 ) ;
F_331 ( V_359 ) ;
}
}
int F_130 ( struct V_86 * V_82 )
{
int V_65 , V_69 = 1 ;
struct V_371 * V_73 ;
struct V_86 * V_372 = NULL ;
struct V_81 * V_85 ;
struct V_357 * V_358 ;
struct V_356 * V_359 ;
V_82 = F_341 ( V_82 ) ;
for ( V_73 = V_82 -> V_73 ; V_73 ; V_73 = V_73 -> V_103 ) {
V_372 = V_73 -> V_373 ;
if ( ! V_372 || ! F_246 ( V_372 ) ||
F_248 ( V_372 ) == V_277 )
return 0 ;
if ( F_248 ( V_372 ) == V_374 )
break;
}
if ( ! V_372 )
return 0 ;
F_62 () ;
F_328 (atsru, &dmar_atsr_units, list) {
V_358 = F_34 ( V_359 -> V_353 , struct V_357 , V_349 ) ;
if ( V_358 -> V_89 != F_80 ( V_82 -> V_73 ) )
continue;
F_342 (atsru->devices, atsru->devices_cnt, i, tmp)
if ( V_85 == & V_372 -> V_82 )
goto V_91;
if ( V_359 -> V_97 )
goto V_91;
}
V_69 = 0 ;
V_91:
F_64 () ;
return V_69 ;
}
int F_343 ( struct V_375 * V_161 )
{
int V_69 = 0 ;
struct V_260 * V_352 ;
struct V_356 * V_359 ;
struct V_357 * V_358 ;
struct V_351 * V_261 ;
if ( ! V_362 && V_360 != V_361 )
return 0 ;
F_128 (rmrru, &dmar_rmrr_units, list) {
V_261 = F_34 ( V_352 -> V_353 ,
struct V_351 , V_349 ) ;
if ( V_161 -> V_376 == V_377 ) {
V_69 = F_344 ( V_161 , ( void * ) ( V_261 + 1 ) ,
( ( void * ) V_261 ) + V_261 -> V_349 . V_240 ,
V_261 -> V_89 , V_352 -> V_90 ,
V_352 -> V_334 ) ;
if( V_69 < 0 )
return V_69 ;
} else if ( V_161 -> V_376 == V_378 ) {
F_345 ( V_161 , V_261 -> V_89 ,
V_352 -> V_90 , V_352 -> V_334 ) ;
}
}
F_128 (atsru, &dmar_atsr_units, list) {
if ( V_359 -> V_97 )
continue;
V_358 = F_34 ( V_359 -> V_353 , struct V_357 , V_349 ) ;
if ( V_161 -> V_376 == V_377 ) {
V_69 = F_344 ( V_161 , ( void * ) ( V_358 + 1 ) ,
( void * ) V_358 + V_358 -> V_349 . V_240 ,
V_358 -> V_89 , V_359 -> V_90 ,
V_359 -> V_334 ) ;
if ( V_69 > 0 )
break;
else if( V_69 < 0 )
return V_69 ;
} else if ( V_161 -> V_376 == V_378 ) {
if ( F_345 ( V_161 , V_358 -> V_89 ,
V_359 -> V_90 , V_359 -> V_334 ) )
break;
}
}
return 0 ;
}
static int F_346 ( struct V_379 * V_380 ,
unsigned long V_381 , void * V_221 )
{
struct V_81 * V_82 = V_221 ;
struct V_28 * V_31 ;
if ( F_76 ( V_82 ) )
return 0 ;
if ( V_381 != V_382 )
return 0 ;
V_31 = F_215 ( V_82 ) ;
if ( ! V_31 )
return 0 ;
F_347 ( & V_383 ) ;
F_238 ( V_31 , V_82 ) ;
if ( ! F_49 ( V_31 ) && F_348 ( & V_31 -> V_90 ) )
F_158 ( V_31 ) ;
F_349 ( & V_383 ) ;
return 0 ;
}
static int F_350 ( struct V_379 * V_380 ,
unsigned long V_26 , void * V_384 )
{
struct V_385 * V_386 = V_384 ;
unsigned long long V_205 , V_95 ;
unsigned long V_326 , V_253 ;
switch ( V_26 ) {
case V_387 :
V_205 = V_386 -> V_114 << V_11 ;
V_95 = ( ( V_386 -> V_114 + V_386 -> V_233 ) << V_11 ) - 1 ;
if ( F_221 ( V_254 , V_205 , V_95 ) ) {
F_338 ( L_68 ,
V_205 , V_95 ) ;
return V_388 ;
}
break;
case V_389 :
case V_390 :
V_326 = F_13 ( V_386 -> V_114 ) ;
V_253 = F_13 ( V_386 -> V_114 + V_386 -> V_233 - 1 ) ;
while ( V_326 <= V_253 ) {
struct V_192 * V_192 ;
struct V_62 * V_63 ;
struct V_52 * V_53 ;
struct V_14 * V_121 ;
V_192 = F_286 ( & V_254 -> V_206 , V_326 ) ;
if ( V_192 == NULL ) {
F_125 ( L_69 ,
V_326 ) ;
break;
}
V_192 = F_351 ( & V_254 -> V_206 , V_192 ,
V_326 , V_253 ) ;
if ( V_192 == NULL ) {
F_338 ( L_70 ,
V_326 , V_253 ) ;
return V_388 ;
}
V_121 = F_102 ( V_254 , V_192 -> V_305 ,
V_192 -> V_317 ) ;
F_62 () ;
F_63 (iommu, drhd)
F_139 ( V_53 , V_254 -> V_186 ,
V_192 -> V_305 , F_281 ( V_192 ) ,
! V_121 , 0 ) ;
F_64 () ;
F_103 ( V_121 ) ;
V_326 = V_192 -> V_317 + 1 ;
F_352 ( V_192 ) ;
}
break;
}
return V_391 ;
}
static T_10 F_353 ( struct V_81 * V_82 ,
struct V_392 * V_393 ,
char * V_394 )
{
struct V_52 * V_53 = F_354 ( V_82 ) ;
T_5 V_395 = V_137 ( V_53 -> V_131 + V_396 ) ;
return sprintf ( V_394 , L_71 ,
F_355 ( V_395 ) , F_356 ( V_395 ) ) ;
}
static T_10 F_357 ( struct V_81 * V_82 ,
struct V_392 * V_393 ,
char * V_394 )
{
struct V_52 * V_53 = F_354 ( V_82 ) ;
return sprintf ( V_394 , L_72 , V_53 -> V_397 ) ;
}
static T_10 F_358 ( struct V_81 * V_82 ,
struct V_392 * V_393 ,
char * V_394 )
{
struct V_52 * V_53 = F_354 ( V_82 ) ;
return sprintf ( V_394 , L_72 , V_53 -> V_56 ) ;
}
static T_10 F_359 ( struct V_81 * V_82 ,
struct V_392 * V_393 ,
char * V_394 )
{
struct V_52 * V_53 = F_354 ( V_82 ) ;
return sprintf ( V_394 , L_72 , V_53 -> V_67 ) ;
}
int T_1 F_360 ( void )
{
int V_69 = - V_200 ;
struct V_62 * V_63 ;
struct V_52 * V_53 ;
V_295 = F_361 () ;
if ( F_304 () ) {
if ( V_295 )
F_322 ( L_73 ) ;
return - V_125 ;
}
F_362 ( & V_383 ) ;
if ( F_363 () ) {
if ( V_295 )
F_322 ( L_74 ) ;
goto V_398;
}
F_63 (iommu, drhd)
if ( V_53 -> V_133 & V_177 )
F_147 ( V_53 ) ;
if ( F_364 () < 0 ) {
if ( V_295 )
F_322 ( L_75 ) ;
goto V_398;
}
if ( V_399 || V_34 )
goto V_398;
if ( F_348 ( & V_355 ) )
F_36 ( V_35 L_76 ) ;
if ( F_348 ( & V_363 ) )
F_36 ( V_35 L_77 ) ;
if ( F_172 () ) {
if ( V_295 )
F_322 ( L_78 ) ;
goto V_400;
}
F_315 () ;
V_69 = F_260 () ;
if ( V_69 ) {
if ( V_295 )
F_322 ( L_79 ) ;
F_36 ( V_159 L_80 ) ;
goto V_400;
}
F_365 ( & V_383 ) ;
F_36 ( V_35
L_81 ) ;
F_366 ( & V_314 ) ;
#ifdef F_367
V_401 = 0 ;
#endif
V_402 = & V_403 ;
F_323 () ;
F_63 (iommu, drhd)
V_53 -> V_404 = F_368 ( NULL , V_53 ,
V_405 ,
V_53 -> V_124 ) ;
F_369 ( & V_406 , & V_407 ) ;
F_370 ( & V_406 , & V_408 ) ;
if ( V_254 && ! V_255 )
F_371 ( & V_409 ) ;
V_362 = 1 ;
return 0 ;
V_400:
F_186 ( & V_193 ) ;
V_398:
F_340 () ;
F_365 ( & V_383 ) ;
F_308 () ;
return V_69 ;
}
static int F_372 ( struct V_86 * V_88 , T_3 V_218 , void * V_219 )
{
struct V_52 * V_53 = V_219 ;
F_209 ( V_53 , F_192 ( V_218 ) , V_218 & 0xff ) ;
return 0 ;
}
static void F_214 ( struct V_52 * V_53 ,
struct V_81 * V_82 )
{
if ( ! V_53 || ! V_82 || ! F_78 ( V_82 ) )
return;
F_194 ( F_79 ( V_82 ) , & F_372 , V_53 ) ;
}
static void F_238 ( struct V_28 * V_31 ,
struct V_81 * V_82 )
{
struct V_160 * V_161 , * V_85 ;
struct V_52 * V_53 ;
unsigned long V_47 ;
bool V_64 = false ;
T_2 V_73 , V_74 ;
V_53 = F_77 ( V_82 , & V_73 , & V_74 ) ;
if ( ! V_53 )
return;
F_87 ( & V_163 , V_47 ) ;
F_213 (info, tmp, &domain->devices, link) {
if ( V_161 -> V_53 == V_53 && V_161 -> V_73 == V_73 &&
V_161 -> V_74 == V_74 ) {
F_210 ( V_161 ) ;
F_88 ( & V_163 , V_47 ) ;
F_133 ( V_161 ) ;
F_209 ( V_53 , V_161 -> V_73 , V_161 -> V_74 ) ;
F_214 ( V_53 , V_82 ) ;
F_47 ( V_161 ) ;
F_87 ( & V_163 , V_47 ) ;
if ( V_64 )
break;
else
continue;
}
if ( V_161 -> V_53 == V_53 )
V_64 = true ;
}
F_88 ( & V_163 , V_47 ) ;
if ( V_64 == 0 ) {
F_157 ( V_31 , V_53 ) ;
if ( ! F_49 ( V_31 ) )
F_168 ( V_31 , V_53 ) ;
}
}
static int F_231 ( struct V_28 * V_31 , int V_207 )
{
int V_208 ;
F_173 ( & V_31 -> V_206 , V_109 , V_194 ,
V_195 ) ;
F_178 ( V_31 ) ;
V_31 -> V_120 = V_207 ;
V_208 = F_180 ( V_207 ) ;
V_31 -> V_1 = F_4 ( V_208 ) ;
V_31 -> V_66 = 0 ;
V_31 -> V_71 = 0 ;
V_31 -> V_72 = 0 ;
V_31 -> V_410 = 0 ;
V_31 -> V_105 = (struct V_24 * ) F_37 ( V_31 -> V_108 ) ;
if ( ! V_31 -> V_105 )
return - V_125 ;
F_84 ( V_31 , V_31 -> V_105 , V_209 ) ;
return 0 ;
}
static struct V_29 * F_373 ( unsigned type )
{
struct V_28 * V_28 ;
struct V_29 * V_31 ;
if ( type != V_411 )
return NULL ;
V_28 = F_160 ( V_48 ) ;
if ( ! V_28 ) {
F_36 ( V_159
L_82 ) ;
return NULL ;
}
if ( F_231 ( V_28 , V_57 ) ) {
F_36 ( V_159
L_83 ) ;
F_158 ( V_28 ) ;
return NULL ;
}
F_70 ( V_28 ) ;
V_31 = & V_28 -> V_31 ;
V_31 -> V_412 . V_413 = 0 ;
V_31 -> V_412 . V_414 = F_374 ( V_28 -> V_120 ) ;
V_31 -> V_412 . V_415 = true ;
return V_31 ;
}
static void F_375 ( struct V_29 * V_31 )
{
F_158 ( F_33 ( V_31 ) ) ;
}
static int F_376 ( struct V_29 * V_31 ,
struct V_81 * V_82 )
{
struct V_28 * V_28 = F_33 ( V_31 ) ;
struct V_52 * V_53 ;
int V_50 ;
T_2 V_73 , V_74 ;
if ( F_241 ( V_82 ) ) {
F_377 ( V_82 , L_84 ) ;
return - V_416 ;
}
if ( F_190 ( F_196 ( V_82 ) ) ) {
struct V_28 * V_417 ;
V_417 = F_215 ( V_82 ) ;
if ( V_417 ) {
if ( F_49 ( V_28 ) )
F_238 ( V_417 , V_82 ) ;
else
F_185 ( V_417 ) ;
if ( ! F_49 ( V_417 ) &&
F_348 ( & V_417 -> V_90 ) )
F_158 ( V_417 ) ;
}
}
V_53 = F_77 ( V_82 , & V_73 , & V_74 ) ;
if ( ! V_53 )
return - V_200 ;
V_50 = F_2 ( V_53 -> V_1 ) ;
if ( V_50 > F_182 ( V_53 -> V_56 ) )
V_50 = F_182 ( V_53 -> V_56 ) ;
if ( V_28 -> V_410 > ( 1LL << V_50 ) ) {
F_36 ( V_159 L_85
L_86 ,
V_418 , V_50 , V_28 -> V_410 ) ;
return - V_213 ;
}
V_28 -> V_120 = V_50 ;
while ( V_53 -> V_1 < V_28 -> V_1 ) {
struct V_24 * V_25 ;
V_25 = V_28 -> V_105 ;
if ( F_30 ( V_25 ) ) {
V_28 -> V_105 = (struct V_24 * )
F_73 ( F_27 ( V_25 ) ) ;
F_40 ( V_25 ) ;
}
V_28 -> V_1 -- ;
}
return F_237 ( V_28 , V_82 , V_212 ) ;
}
static void F_378 ( struct V_29 * V_31 ,
struct V_81 * V_82 )
{
F_238 ( F_33 ( V_31 ) , V_82 ) ;
}
static int F_379 ( struct V_29 * V_31 ,
unsigned long V_192 , T_8 V_419 ,
T_7 V_99 , int V_420 )
{
struct V_28 * V_28 = F_33 ( V_31 ) ;
V_20 V_410 ;
int V_234 = 0 ;
int V_69 ;
if ( V_420 & V_421 )
V_234 |= V_110 ;
if ( V_420 & V_422 )
V_234 |= V_111 ;
if ( ( V_420 & V_423 ) && V_28 -> V_71 )
V_234 |= V_239 ;
V_410 = V_192 + V_99 ;
if ( V_28 -> V_410 < V_410 ) {
V_20 V_95 ;
V_95 = F_374 ( V_28 -> V_120 ) + 1 ;
if ( V_95 < V_410 ) {
F_36 ( V_159 L_85
L_86 ,
V_418 , V_28 -> V_120 , V_410 ) ;
return - V_213 ;
}
V_28 -> V_410 = V_410 ;
}
V_99 = F_197 ( V_419 , V_99 ) ;
V_69 = F_208 ( V_28 , V_192 >> V_12 ,
V_419 >> V_12 , V_99 , V_234 ) ;
return V_69 ;
}
static T_7 F_380 ( struct V_29 * V_31 ,
unsigned long V_192 , T_7 V_99 )
{
struct V_28 * V_28 = F_33 ( V_31 ) ;
struct V_14 * V_121 = NULL ;
struct V_52 * V_53 ;
unsigned long V_114 , V_115 ;
unsigned int V_424 ;
int V_58 , V_187 , V_179 , V_5 = 0 ;
if ( ! F_91 ( V_28 , V_192 >> V_12 , & V_5 ) )
F_118 () ;
if ( V_99 < V_109 << F_6 ( V_5 ) )
V_99 = V_109 << F_6 ( V_5 ) ;
V_114 = V_192 >> V_12 ;
V_115 = ( V_192 + V_99 - 1 ) >> V_12 ;
V_121 = F_102 ( V_28 , V_114 , V_115 ) ;
V_424 = V_115 - V_114 + 1 ;
F_60 (iommu_id, dmar_domain->iommu_bmp, g_num_of_iommus) {
V_53 = V_61 [ V_58 ] ;
V_179 = F_149 ( V_53 -> V_56 ) ;
F_60 (num, iommu->domain_ids, ndomains) {
if ( V_53 -> V_172 [ V_187 ] == V_28 )
F_139 ( V_53 , V_187 , V_114 ,
V_424 , ! V_121 , 0 ) ;
}
}
F_103 ( V_121 ) ;
if ( V_28 -> V_410 == V_192 + V_99 )
V_28 -> V_410 = V_192 ;
return V_99 ;
}
static T_8 F_381 ( struct V_29 * V_31 ,
V_242 V_192 )
{
struct V_28 * V_28 = F_33 ( V_31 ) ;
struct V_24 * V_25 ;
int V_5 = 0 ;
V_20 V_425 = 0 ;
V_25 = F_91 ( V_28 , V_192 >> V_12 , & V_5 ) ;
if ( V_25 )
V_425 = F_27 ( V_25 ) ;
return V_425 ;
}
static bool F_382 ( enum V_426 V_56 )
{
if ( V_56 == V_427 )
return F_65 ( NULL ) == 1 ;
if ( V_56 == V_428 )
return V_429 == 1 ;
return false ;
}
static int F_383 ( struct V_81 * V_82 )
{
struct V_52 * V_53 ;
struct V_430 * V_431 ;
T_2 V_73 , V_74 ;
V_53 = F_77 ( V_82 , & V_73 , & V_74 ) ;
if ( ! V_53 )
return - V_200 ;
F_384 ( V_53 -> V_404 , V_82 ) ;
V_431 = F_385 ( V_82 ) ;
if ( F_386 ( V_431 ) )
return F_387 ( V_431 ) ;
F_388 ( V_431 ) ;
return 0 ;
}
static void F_389 ( struct V_81 * V_82 )
{
struct V_52 * V_53 ;
T_2 V_73 , V_74 ;
V_53 = F_77 ( V_82 , & V_73 , & V_74 ) ;
if ( ! V_53 )
return;
F_390 ( V_82 ) ;
F_391 ( V_53 -> V_404 , V_82 ) ;
}
static void F_392 ( struct V_86 * V_82 )
{
F_36 ( V_35 L_87 ) ;
V_36 = 0 ;
}
static void F_393 ( struct V_86 * V_82 )
{
F_36 ( V_35 L_88 ) ;
V_139 = 1 ;
}
static void F_394 ( struct V_86 * V_82 )
{
unsigned short V_432 ;
if ( F_395 ( V_82 , V_433 , & V_432 ) )
return;
if ( ! ( V_432 & V_434 ) ) {
F_36 ( V_35 L_89 ) ;
V_36 = 0 ;
} else if ( V_36 ) {
F_36 ( V_35 L_90 ) ;
V_38 = 1 ;
}
}
static void T_1 F_266 ( void )
{
struct V_86 * V_88 ;
T_11 V_435 ;
V_88 = F_396 ( V_436 , 0x3a3e , NULL ) ;
if ( ! V_88 )
return;
F_229 ( V_88 ) ;
V_88 = F_396 ( V_436 , 0x342e , NULL ) ;
if ( ! V_88 )
return;
if ( F_397 ( V_88 , 0x188 , & V_435 ) ) {
F_229 ( V_88 ) ;
return;
}
F_229 ( V_88 ) ;
if ( V_435 & 1 )
return;
V_435 &= 0x1c ;
if ( V_435 == 0x10 )
return;
if ( ! V_435 ) {
F_224 ( 1 , L_91
L_33 ,
F_225 ( V_256 ) ,
F_225 ( V_257 ) ,
F_225 ( V_258 ) ) ;
V_268 |= V_272 ;
return;
}
F_36 ( V_437 L_92 ,
V_435 ) ;
}
