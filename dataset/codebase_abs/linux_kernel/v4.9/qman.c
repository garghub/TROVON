static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_4 ( V_6 , V_2 -> V_4 . V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
F_6 ( V_2 -> V_4 . V_7 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
F_8 ( V_2 -> V_4 . V_7 + V_3 ) ;
}
static inline T_1 F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_7 + V_3 ) ;
}
static struct V_8 * F_10 ( struct V_8 * V_2 )
{
T_2 V_4 = ( T_2 ) V_2 ;
V_4 &= ~ V_9 ;
return (struct V_8 * ) V_4 ;
}
static int F_11 ( struct V_8 * V_10 )
{
return ( ( T_2 ) V_10 >> V_11 ) & ( V_12 - 1 ) ;
}
static inline void F_12 ( struct V_13 * V_14 )
{
struct V_8 * V_15 = V_14 -> V_16 + 1 ;
V_14 -> V_16 = F_10 ( V_15 ) ;
if ( V_15 != V_14 -> V_16 )
V_14 -> V_17 ^= V_18 ;
}
static inline int F_13 ( struct V_1 * V_19 ,
enum V_20 V_21 ,
unsigned int V_22 ,
int V_23 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
T_1 V_24 ;
T_3 V_25 ;
V_14 -> V_26 = V_19 -> V_4 . V_7 + V_27 ;
V_14 -> V_5 = F_1 ( V_19 , V_28 ) & ( V_12 - 1 ) ;
F_5 ( V_19 , V_29 ) ;
V_25 = F_1 ( V_19 , V_30 ) & ( V_12 - 1 ) ;
V_14 -> V_16 = V_14 -> V_26 + V_25 ;
V_14 -> V_17 = ( F_1 ( V_19 , V_30 ) & V_12 ) ?
V_18 : 0 ;
V_14 -> V_31 = V_12 - 1 -
F_14 ( V_12 , V_14 -> V_5 , V_25 ) ;
V_14 -> V_32 = F_1 ( V_19 , V_33 ) ;
#ifdef F_15
V_14 -> V_34 = 0 ;
V_14 -> V_21 = V_21 ;
#endif
V_24 = ( F_1 ( V_19 , V_35 ) & 0x00ffffff ) |
( V_22 << 28 ) |
( V_23 << 26 ) |
( ( V_21 & 0x3 ) << 24 ) ;
F_3 ( V_19 , V_35 , V_24 ) ;
return 0 ;
}
static inline unsigned int F_16 ( struct V_1 * V_19 )
{
return ( F_1 ( V_19 , V_35 ) >> 28 ) & 0x7 ;
}
static inline void F_17 ( struct V_1 * V_19 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
T_3 V_25 = F_1 ( V_19 , V_30 ) & ( V_12 - 1 ) ;
T_3 V_5 = F_1 ( V_19 , V_28 ) & ( V_12 - 1 ) ;
F_18 ( ! V_14 -> V_34 ) ;
if ( V_25 != F_11 ( V_14 -> V_16 ) )
F_19 ( L_1 ) ;
if ( V_5 != V_14 -> V_5 )
F_19 ( L_2 ) ;
if ( V_14 -> V_5 != F_11 ( V_14 -> V_16 ) )
F_19 ( L_3 ) ;
}
static inline struct V_8 * F_20 ( struct V_1
* V_19 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
F_18 ( ! V_14 -> V_34 ) ;
if ( ! V_14 -> V_31 )
return NULL ;
#ifdef F_15
V_14 -> V_34 = 1 ;
#endif
F_21 ( V_14 -> V_16 ) ;
return V_14 -> V_16 ;
}
static inline struct V_8 * F_22 ( struct V_1
* V_19 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
T_3 V_36 , V_37 ;
F_18 ( ! V_14 -> V_34 ) ;
if ( ! V_14 -> V_31 ) {
V_37 = V_14 -> V_5 ;
V_14 -> V_5 = F_9 ( V_19 , V_29 ) &
( V_12 - 1 ) ;
V_36 = F_14 ( V_12 , V_37 , V_14 -> V_5 ) ;
V_14 -> V_31 += V_36 ;
if ( ! V_36 )
return NULL ;
}
#ifdef F_15
V_14 -> V_34 = 1 ;
#endif
F_21 ( V_14 -> V_16 ) ;
return V_14 -> V_16 ;
}
static inline void F_23 ( struct V_13 * V_14 )
{
F_18 ( V_14 -> V_34 ) ;
F_18 ( V_14 -> V_16 -> V_38 == ( V_14 -> V_16 -> V_38 & 0x00ffffff ) ) ;
F_18 ( V_14 -> V_16 -> V_39 == ( V_14 -> V_16 -> V_39 & 0x00ffffff ) ) ;
F_18 ( V_14 -> V_31 >= 1 ) ;
}
static inline void F_24 ( struct V_1 * V_19 , T_3 V_40 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
struct V_8 * V_41 ;
F_23 ( V_14 ) ;
F_18 ( V_14 -> V_21 == V_42 ) ;
F_25 () ;
V_41 = V_14 -> V_16 ;
V_41 -> V_43 = V_40 | V_14 -> V_17 ;
F_26 ( V_41 ) ;
F_12 ( V_14 ) ;
V_14 -> V_31 -- ;
#ifdef F_15
V_14 -> V_34 = 0 ;
#endif
}
static inline void F_27 ( struct V_1 * V_19 )
{
F_7 ( V_19 , V_29 ) ;
}
static inline T_3 F_28 ( struct V_1 * V_19 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
T_3 V_36 , V_37 = V_14 -> V_5 ;
V_14 -> V_5 = F_9 ( V_19 , V_29 ) & ( V_12 - 1 ) ;
F_5 ( V_19 , V_29 ) ;
V_36 = F_14 ( V_12 , V_37 , V_14 -> V_5 ) ;
V_14 -> V_31 += V_36 ;
return V_36 ;
}
static inline void F_29 ( struct V_1 * V_19 , T_3 V_32 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
V_14 -> V_32 = V_32 ;
F_3 ( V_19 , V_33 , V_32 ) ;
}
static inline T_3 F_30 ( struct V_1 * V_19 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
return V_14 -> V_31 ;
}
static inline T_3 F_31 ( struct V_1 * V_19 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
return V_12 - 1 - V_14 -> V_31 ;
}
static const struct V_44 * F_32 (
const struct V_44 * V_2 )
{
T_2 V_4 = ( T_2 ) V_2 ;
V_4 &= ~ V_45 ;
return ( const struct V_44 * ) V_4 ;
}
static inline int F_33 ( const struct V_44 * V_10 )
{
return ( ( T_2 ) V_10 >> V_46 ) & ( V_47 - 1 ) ;
}
static const struct V_44 * F_34 ( const struct V_44 * V_10 )
{
return F_32 ( V_10 + 1 ) ;
}
static inline void F_35 ( struct V_1 * V_19 , T_3 V_48 )
{
F_3 ( V_19 , V_35 , ( F_1 ( V_19 , V_35 ) & 0xff0fffff ) |
( ( V_48 & ( V_47 - 1 ) ) << 20 ) ) ;
}
static inline int F_36 ( struct V_1 * V_19 ,
const struct V_49 * V_50 ,
enum V_51 V_52 ,
enum V_53 V_21 ,
enum V_54 V_55 , T_3 V_56 )
{
struct V_57 * V_58 = & V_19 -> V_58 ;
T_1 V_24 ;
F_3 ( V_19 , V_59 , 0 ) ;
F_3 ( V_19 , V_60 , 0 ) ;
F_3 ( V_19 , V_61 , 0 ) ;
V_58 -> V_26 = V_19 -> V_4 . V_7 + V_62 ;
V_58 -> V_25 = F_1 ( V_19 , V_63 ) & ( V_47 - 1 ) ;
V_58 -> V_5 = F_1 ( V_19 , V_64 ) & ( V_47 - 1 ) ;
V_58 -> V_16 = V_58 -> V_26 + V_58 -> V_5 ;
V_58 -> V_65 = F_14 ( V_47 , V_58 -> V_5 , V_58 -> V_25 ) ;
V_58 -> V_17 = ( F_1 ( V_19 , V_63 ) & V_47 ) ?
V_66 : 0 ;
V_58 -> V_32 = F_1 ( V_19 , V_67 ) ;
#ifdef F_15
V_58 -> V_52 = V_52 ;
V_58 -> V_21 = V_21 ;
V_58 -> V_55 = V_55 ;
#endif
for ( V_24 = 0 ; V_24 < V_47 ; V_24 ++ )
F_6 ( F_37 ( V_58 -> V_26 , V_24 ) ) ;
V_24 = ( F_1 ( V_19 , V_35 ) & 0xff000f00 ) |
( ( V_56 & ( V_47 - 1 ) ) << 20 ) |
( ( V_52 & 1 ) << 18 ) |
( ( V_55 & 3 ) << 16 ) |
0xa0 |
( 0 ? 0x40 : 0 ) |
( 0 ? 0x10 : 0 ) ;
F_3 ( V_19 , V_35 , V_24 ) ;
F_35 ( V_19 , V_56 ) ;
return 0 ;
}
static inline void F_38 ( struct V_1 * V_19 )
{
#ifdef F_15
struct V_57 * V_58 = & V_19 -> V_58 ;
if ( V_58 -> V_55 != V_68 &&
V_58 -> V_5 != F_33 ( V_58 -> V_16 ) )
F_19 ( L_4 ) ;
#endif
}
static inline const struct V_44 * F_39 (
struct V_1 * V_19 )
{
struct V_57 * V_58 = & V_19 -> V_58 ;
if ( ! V_58 -> V_65 )
return NULL ;
return V_58 -> V_16 ;
}
static inline T_3 F_40 ( struct V_1 * V_19 )
{
struct V_57 * V_58 = & V_19 -> V_58 ;
F_18 ( V_58 -> V_65 ) ;
V_58 -> V_16 = F_34 ( V_58 -> V_16 ) ;
return -- V_58 -> V_65 ;
}
static inline void F_41 ( struct V_1 * V_19 )
{
struct V_57 * V_58 = & V_19 -> V_58 ;
struct V_44 * V_69 = F_37 ( V_58 -> V_26 , V_58 -> V_25 ) ;
F_18 ( V_58 -> V_21 == V_70 ) ;
#ifndef F_42
F_43 ( V_69 ) ;
#endif
if ( ( F_44 ( & V_69 -> V_71 ) & V_66 ) == V_58 -> V_17 ) {
V_58 -> V_25 = ( V_58 -> V_25 + 1 ) & ( V_47 - 1 ) ;
if ( ! V_58 -> V_25 )
V_58 -> V_17 ^= V_66 ;
V_58 -> V_65 ++ ;
}
}
static inline void F_45 ( struct V_1 * V_19 ,
const struct V_44 * V_72 ,
int V_73 )
{
T_4 struct V_57 * V_58 = & V_19 -> V_58 ;
int V_74 = F_33 ( V_72 ) ;
F_18 ( V_58 -> V_55 == V_68 ) ;
F_18 ( ( V_58 -> V_26 + V_74 ) == V_72 ) ;
F_18 ( V_74 < V_47 ) ;
F_3 ( V_19 , V_75 , ( 0 << 8 ) |
( ( V_73 ? 1 : 0 ) << 6 ) |
V_74 ) ;
}
static inline void F_46 ( struct V_1 * V_19 , T_1 V_76 )
{
T_4 struct V_57 * V_58 = & V_19 -> V_58 ;
F_18 ( V_58 -> V_55 == V_68 ) ;
F_3 ( V_19 , V_75 , ( 1 << 8 ) |
( V_76 << 16 ) ) ;
}
static inline void F_47 ( struct V_1 * V_19 , T_1 V_77 )
{
F_3 ( V_19 , V_59 , V_77 ) ;
}
static inline void F_48 ( struct V_1 * V_19 , T_1 V_78 )
{
F_3 ( V_19 , V_60 , V_78 ) ;
}
static inline void F_49 ( struct V_1 * V_19 , T_3 V_32 )
{
F_3 ( V_19 , V_67 , V_32 ) ;
}
static union V_79 * F_50 ( union V_79 * V_2 )
{
T_2 V_4 = ( T_2 ) V_2 ;
V_4 &= ~ V_80 ;
return (union V_79 * ) V_4 ;
}
static inline int F_51 ( const union V_79 * V_10 )
{
return ( ( T_2 ) V_10 >> V_81 ) & ( V_82 - 1 ) ;
}
static inline union V_79 * F_52 ( union V_79 * V_10 )
{
return F_50 ( V_10 + 1 ) ;
}
static inline int F_53 ( struct V_1 * V_19 , enum V_83 V_21 ,
enum V_84 V_55 )
{
struct V_85 * V_86 = & V_19 -> V_86 ;
T_1 V_24 ;
V_86 -> V_26 = V_19 -> V_4 . V_7 + V_87 ;
V_86 -> V_25 = F_1 ( V_19 , V_88 ) & ( V_82 - 1 ) ;
V_86 -> V_5 = F_1 ( V_19 , V_89 ) & ( V_82 - 1 ) ;
V_86 -> V_16 = V_86 -> V_26 + V_86 -> V_5 ;
V_86 -> V_65 = F_14 ( V_82 , V_86 -> V_5 , V_86 -> V_25 ) ;
V_86 -> V_17 = ( F_1 ( V_19 , V_88 ) & V_82 )
? V_90 : 0 ;
V_86 -> V_32 = F_1 ( V_19 , V_91 ) ;
#ifdef F_15
V_86 -> V_21 = V_21 ;
V_86 -> V_55 = V_55 ;
#endif
V_24 = ( F_1 ( V_19 , V_35 ) & 0xfffff0ff ) |
( ( V_55 & 1 ) << 8 ) ;
F_3 ( V_19 , V_35 , V_24 ) ;
return 0 ;
}
static inline void F_54 ( struct V_1 * V_19 )
{
struct V_85 * V_86 = & V_19 -> V_86 ;
if ( V_86 -> V_5 != F_51 ( V_86 -> V_16 ) )
F_19 ( L_5 ) ;
}
static inline const union V_79 * F_55 ( struct V_1 * V_19 )
{
struct V_85 * V_86 = & V_19 -> V_86 ;
if ( ! V_86 -> V_65 )
return NULL ;
return V_86 -> V_16 ;
}
static inline int F_56 ( struct V_1 * V_19 )
{
struct V_85 * V_86 = & V_19 -> V_86 ;
F_18 ( V_86 -> V_65 ) ;
V_86 -> V_16 = F_52 ( V_86 -> V_16 ) ;
return -- V_86 -> V_65 ;
}
static inline void F_57 ( struct V_1 * V_19 )
{
struct V_85 * V_86 = & V_19 -> V_86 ;
union V_79 * V_69 = F_37 ( V_86 -> V_26 , V_86 -> V_25 ) ;
F_18 ( V_86 -> V_21 == V_92 ) ;
if ( ( F_44 ( & V_69 -> V_71 ) & V_90 ) == V_86 -> V_17 ) {
V_86 -> V_25 = ( V_86 -> V_25 + 1 ) & ( V_82 - 1 ) ;
if ( ! V_86 -> V_25 )
V_86 -> V_17 ^= V_90 ;
V_86 -> V_65 ++ ;
V_69 = F_52 ( V_69 ) ;
}
F_43 ( V_69 ) ;
}
static inline void F_58 ( struct V_1 * V_19 , T_3 V_93 )
{
struct V_85 * V_86 = & V_19 -> V_86 ;
F_18 ( V_86 -> V_55 == V_94 ) ;
V_86 -> V_5 = ( V_86 -> V_5 + V_93 ) & ( V_82 - 1 ) ;
F_3 ( V_19 , V_89 , V_86 -> V_5 ) ;
}
static inline void F_59 ( struct V_1 * V_19 )
{
struct V_85 * V_86 = & V_19 -> V_86 ;
F_18 ( V_86 -> V_55 == V_94 ) ;
V_86 -> V_5 = F_51 ( V_86 -> V_16 ) ;
F_3 ( V_19 , V_89 , V_86 -> V_5 ) ;
}
static inline void F_60 ( struct V_1 * V_19 , T_3 V_32 )
{
F_3 ( V_19 , V_91 , V_32 ) ;
}
static inline int F_61 ( struct V_1 * V_19 )
{
struct V_95 * V_96 = & V_19 -> V_96 ;
V_96 -> V_97 = V_19 -> V_4 . V_7 + V_98 ;
V_96 -> V_99 = V_19 -> V_4 . V_7 + V_100 ;
V_96 -> V_101 = ( F_44 ( & V_96 -> V_97 -> V_43 ) & V_102 )
? 0 : 1 ;
V_96 -> V_17 = V_96 -> V_101 ? V_102 : 0 ;
#ifdef F_15
V_96 -> V_103 = V_104 ;
#endif
return 0 ;
}
static inline void F_62 ( struct V_1 * V_19 )
{
#ifdef F_15
struct V_95 * V_96 = & V_19 -> V_96 ;
F_18 ( V_96 -> V_103 == V_104 ) ;
if ( V_96 -> V_103 != V_104 )
F_19 ( L_6 ) ;
#endif
}
static inline union V_105 * F_63 ( struct V_1 * V_19 )
{
struct V_95 * V_96 = & V_19 -> V_96 ;
F_18 ( V_96 -> V_103 == V_104 ) ;
#ifdef F_15
V_96 -> V_103 = V_106 ;
#endif
F_21 ( V_96 -> V_97 ) ;
return V_96 -> V_97 ;
}
static inline void F_64 ( struct V_1 * V_19 , T_3 V_40 )
{
struct V_95 * V_96 = & V_19 -> V_96 ;
union V_107 * V_99 = V_96 -> V_99 + V_96 -> V_101 ;
F_18 ( V_96 -> V_103 == V_106 ) ;
F_25 () ;
V_96 -> V_97 -> V_43 = V_40 | V_96 -> V_17 ;
F_26 ( V_96 -> V_97 ) ;
F_43 ( V_99 ) ;
#ifdef F_15
V_96 -> V_103 = V_108 ;
#endif
}
static inline union V_107 * V_107 ( struct V_1 * V_19 )
{
struct V_95 * V_96 = & V_19 -> V_96 ;
union V_107 * V_99 = V_96 -> V_99 + V_96 -> V_101 ;
F_18 ( V_96 -> V_103 == V_108 ) ;
if ( ! F_44 ( & V_99 -> V_71 ) ) {
F_43 ( V_99 ) ;
return NULL ;
}
V_96 -> V_101 ^= 1 ;
V_96 -> V_17 ^= V_102 ;
#ifdef F_15
V_96 -> V_103 = V_104 ;
#endif
return V_99 ;
}
static inline int F_65 ( struct V_1 * V_19 ,
union V_107 * * V_109 )
{
int V_110 = V_111 ;
do {
* V_109 = V_107 ( V_19 ) ;
if ( * V_109 )
break;
F_66 ( 1 ) ;
} while ( -- V_110 );
return V_110 ;
}
static inline void F_67 ( struct V_112 * V_113 , T_1 V_114 )
{
F_68 ( V_114 , & V_113 -> V_115 ) ;
}
static inline void F_69 ( struct V_112 * V_113 , T_1 V_114 )
{
F_70 ( V_114 , & V_113 -> V_115 ) ;
}
static inline int F_71 ( struct V_112 * V_113 , T_1 V_114 )
{
return V_113 -> V_115 & V_114 ;
}
static inline int F_72 ( struct V_112 * V_113 , T_1 V_114 )
{
return ! ( V_113 -> V_115 & V_114 ) ;
}
static inline struct V_116 * F_73 ( void )
{
return & F_74 ( V_117 ) ;
}
static inline void F_75 ( void )
{
F_76 ( V_117 ) ;
}
int F_77 ( void )
{
V_118 = F_78 ( L_7 , 0 , 1 ) ;
if ( ! V_118 )
return - V_119 ;
return 0 ;
}
int F_79 ( T_1 V_120 )
{
V_121 = V_120 ;
V_122 = F_80 ( V_121 * 2 * sizeof( struct V_112 * ) ) ;
if ( ! V_122 )
return - V_119 ;
F_81 ( L_8 ,
V_122 , V_121 * 2 ) ;
return 0 ;
}
static struct V_112 * F_82 ( T_1 V_74 )
{
struct V_112 * V_113 ;
#ifdef F_15
if ( F_83 ( V_74 >= V_121 * 2 ) )
return NULL ;
#endif
V_113 = V_122 [ V_74 ] ;
F_18 ( ! V_113 || V_74 == V_113 -> V_74 ) ;
return V_113 ;
}
static struct V_112 * F_84 ( T_1 V_39 )
{
return F_82 ( V_39 * 2 ) ;
}
static struct V_112 * F_85 ( T_1 V_123 )
{
#if V_124 == 64
return F_82 ( V_123 ) ;
#else
return (struct V_112 * ) V_123 ;
#endif
}
static T_1 F_86 ( struct V_112 * V_113 )
{
#if V_124 == 64
return V_113 -> V_74 ;
#else
return ( T_1 ) V_113 ;
#endif
}
static T_5 F_87 ( int V_125 , void * V_126 )
{
struct V_116 * V_2 = V_126 ;
T_1 V_127 = V_128 | V_2 -> V_129 ;
T_1 V_130 = F_1 ( & V_2 -> V_2 , V_131 ) & V_2 -> V_129 ;
if ( F_88 ( ! V_130 ) )
return V_132 ;
if ( V_130 & V_133 )
F_89 ( V_2 , V_134 ) ;
V_127 |= F_90 ( V_2 , V_130 ) ;
F_3 ( & V_2 -> V_2 , V_131 , V_127 ) ;
return V_135 ;
}
static int F_91 ( struct V_1 * V_2 )
{
const union V_79 * V_136 ;
V_137:
V_136 = F_55 ( V_2 ) ;
if ( ! V_136 ) {
T_6 V_138 , V_139 = V_140 ;
do {
V_138 = V_140 ;
} while ( ( V_139 + 10000 ) > V_138 );
V_136 = F_55 ( V_2 ) ;
if ( ! V_136 )
return 0 ;
}
if ( ( V_136 -> V_71 & V_141 ) != V_142 ) {
F_92 ( L_9 , V_136 -> V_71 ) ;
return - 1 ;
}
F_56 ( V_2 ) ;
F_58 ( V_2 , 1 ) ;
goto V_137;
}
static int F_93 ( struct V_116 * V_19 ,
const struct V_49 * V_143 ,
const struct V_144 * V_145 )
{
struct V_1 * V_2 ;
char V_146 [ 16 ] ;
int V_147 ;
T_1 V_148 ;
V_2 = & V_19 -> V_2 ;
#ifdef F_42
V_19 -> V_149 = ( ( V_150 >= V_151 ) ? 1 : 0 ) ;
#else
V_19 -> V_149 = 0 ;
#endif
V_2 -> V_4 . V_7 = V_143 -> V_152 [ V_153 ] ;
V_2 -> V_4 . V_5 = V_143 -> V_152 [ V_154 ] ;
if ( F_13 ( V_2 , V_42 ,
V_19 -> V_149 ? 3 : 0 , 1 ) ) {
F_94 ( V_143 -> V_155 , L_10 ) ;
goto V_156;
}
if ( F_36 ( V_2 , V_143 , V_157 , V_70 ,
V_68 , V_158 ) ) {
F_94 ( V_143 -> V_155 , L_11 ) ;
goto V_159;
}
if ( F_53 ( V_2 , V_92 , V_94 ) ) {
F_94 ( V_143 -> V_155 , L_12 ) ;
goto V_160;
}
if ( F_61 ( V_2 ) ) {
F_94 ( V_143 -> V_155 , L_13 ) ;
goto V_161;
}
F_49 ( V_2 , V_162 ) ;
F_60 ( V_2 , V_163 ) ;
F_3 ( V_2 , V_164 , V_165 ) ;
V_19 -> V_145 = F_95 ( 2 * sizeof( * V_145 ) , V_166 ) ;
if ( ! V_19 -> V_145 )
goto V_167;
F_96 ( & V_19 -> V_145 [ 1 ] ) ;
if ( V_145 )
V_19 -> V_145 [ 0 ] = * V_145 ;
else
F_97 ( & V_19 -> V_145 [ 0 ] ) ;
F_98 ( & V_19 -> V_168 ) ;
F_99 ( & V_19 -> V_169 ) ;
F_100 ( & V_19 -> V_170 , V_171 ) ;
F_100 ( & V_19 -> V_172 , V_173 ) ;
V_19 -> V_174 = 0 ;
V_19 -> V_77 = V_175 | V_176 |
V_177 | V_178 |
F_101 ( 0xab ) | V_179 ;
sprintf ( V_146 , L_14 , V_143 -> V_180 ) ;
V_19 -> V_181 = F_102 ( V_146 , - 1 ) ;
if ( ! V_19 -> V_181 )
goto V_182;
if ( F_103 ( & V_19 -> V_181 -> V_155 , F_104 ( 40 ) ) )
goto V_183;
V_147 = F_105 ( V_19 -> V_181 ) ;
if ( V_147 )
goto V_183;
V_148 = 0xffffffff ;
F_3 ( V_2 , V_184 , V_148 ) ;
V_19 -> V_129 = 0 ;
F_3 ( V_2 , V_185 , 0 ) ;
F_3 ( V_2 , V_131 , 0xffffffff ) ;
snprintf ( V_19 -> V_186 , V_187 , V_188 , V_143 -> V_189 ) ;
if ( F_106 ( V_143 -> V_125 , F_87 , 0 , V_19 -> V_186 , V_19 ) ) {
F_94 ( V_143 -> V_155 , L_15 ) ;
goto V_190;
}
if ( V_143 -> V_189 != - 1 && F_107 ( V_143 -> V_125 ) &&
F_108 ( V_143 -> V_125 , F_109 ( V_143 -> V_189 ) ) ) {
F_94 ( V_143 -> V_155 , L_16 ) ;
goto V_191;
}
V_148 &= ~ V_192 ;
F_3 ( V_2 , V_184 , V_148 ) ;
V_147 = F_31 ( V_2 ) ;
if ( V_147 ) {
F_94 ( V_143 -> V_155 , L_17 ) ;
goto V_193;
}
V_148 &= ~ ( V_133 | V_194 ) ;
F_3 ( V_2 , V_184 , V_148 ) ;
if ( F_39 ( V_2 ) ) {
F_94 ( V_143 -> V_155 , L_18 ) ;
F_46 ( V_2 , 0xffff ) ;
}
if ( F_55 ( V_2 ) && F_91 ( V_2 ) ) {
const union V_79 * V_10 = F_55 ( V_2 ) ;
F_94 ( V_143 -> V_155 , L_19 ,
V_10 -> V_71 , V_10 -> V_195 . V_196 , V_10 -> V_195 . V_197 . V_198 ) ;
goto V_199;
}
V_19 -> V_50 = V_143 ;
F_3 ( V_2 , V_184 , 0 ) ;
F_3 ( V_2 , V_200 , 0 ) ;
F_47 ( V_2 , V_19 -> V_77 ) ;
return 0 ;
V_199:
V_193:
V_191:
F_110 ( V_143 -> V_125 , V_19 ) ;
V_190:
F_111 ( V_19 -> V_181 ) ;
V_183:
F_112 ( V_19 -> V_181 ) ;
V_182:
F_113 ( V_19 -> V_145 ) ;
V_167:
F_62 ( V_2 ) ;
V_161:
F_54 ( V_2 ) ;
V_160:
F_38 ( V_2 ) ;
V_159:
F_17 ( V_2 ) ;
V_156:
return - V_201 ;
}
struct V_116 * F_114 ( const struct V_49 * V_143 ,
const struct V_144 * V_145 )
{
struct V_116 * V_19 ;
int V_202 ;
V_19 = & F_115 ( V_117 , V_143 -> V_189 ) ;
V_202 = F_93 ( V_19 , V_143 , V_145 ) ;
if ( V_202 )
return NULL ;
F_116 ( & V_203 ) ;
F_117 ( V_143 -> V_189 , & V_204 ) ;
V_205 [ V_143 -> V_189 ] = V_143 -> V_180 ;
V_206 [ V_143 -> V_189 ] = V_19 ;
F_118 ( & V_203 ) ;
return V_19 ;
}
static void F_119 ( struct V_116 * V_207 )
{
const struct V_49 * V_208 ;
F_47 ( & V_207 -> V_2 , 0 ) ;
F_28 ( & V_207 -> V_2 ) ;
F_28 ( & V_207 -> V_2 ) ;
V_208 = V_207 -> V_50 ;
F_110 ( V_208 -> V_125 , V_207 ) ;
F_113 ( V_207 -> V_145 ) ;
F_62 ( & V_207 -> V_2 ) ;
F_54 ( & V_207 -> V_2 ) ;
F_38 ( & V_207 -> V_2 ) ;
F_17 ( & V_207 -> V_2 ) ;
F_111 ( V_207 -> V_181 ) ;
F_112 ( V_207 -> V_181 ) ;
V_207 -> V_50 = NULL ;
}
const struct V_49 * F_120 ( void )
{
struct V_116 * V_207 = F_73 () ;
const struct V_49 * V_208 ;
int V_189 ;
V_208 = V_207 -> V_50 ;
V_189 = V_208 -> V_189 ;
F_119 ( V_207 ) ;
F_116 ( & V_203 ) ;
F_121 ( V_189 , & V_204 ) ;
F_118 ( & V_203 ) ;
F_75 () ;
return V_208 ;
}
static inline void F_122 ( struct V_116 * V_2 , struct V_112 * V_113 ,
const union V_79 * V_136 , T_3 V_71 )
{
switch ( V_71 ) {
case V_209 :
F_18 ( F_71 ( V_113 , V_210 ) ) ;
F_69 ( V_113 , V_210 ) ;
break;
case V_211 :
F_18 ( V_113 -> V_103 == V_212 ||
V_113 -> V_103 == V_213 ) ;
F_18 ( F_71 ( V_113 , V_214 ) ) ;
F_69 ( V_113 , V_214 ) ;
if ( V_136 -> V_113 . V_215 & V_216 )
F_67 ( V_113 , V_217 ) ;
if ( V_136 -> V_113 . V_215 & V_218 )
F_67 ( V_113 , V_210 ) ;
V_113 -> V_103 = V_219 ;
break;
case V_220 :
F_18 ( V_113 -> V_103 == V_213 ) ;
F_18 ( F_72 ( V_113 , V_214 ) ) ;
V_113 -> V_103 = V_212 ;
}
}
static void V_171 ( struct V_221 * V_222 )
{
struct V_116 * V_2 = F_123 ( V_222 , struct V_116 ,
V_170 ) ;
struct V_144 V_99 , V_143 ;
union V_107 * V_109 ;
struct V_223 * V_224 ;
F_116 ( & V_2 -> V_169 ) ;
F_63 ( & V_2 -> V_2 ) ;
F_64 ( & V_2 -> V_2 , V_225 ) ;
if ( ! F_65 ( & V_2 -> V_2 , & V_109 ) ) {
F_118 ( & V_2 -> V_169 ) ;
F_124 ( V_2 -> V_50 -> V_155 , L_20 ) ;
return;
}
F_125 ( & V_99 , (struct V_144 * ) & V_109 -> V_226 . V_103 ,
& V_2 -> V_145 [ 0 ] ) ;
F_126 ( & V_143 , & V_99 , & V_2 -> V_145 [ 1 ] ) ;
F_127 ( & V_2 -> V_145 [ 1 ] , & V_99 ) ;
F_128 (cgr, &p->cgr_cbs, node)
if ( V_224 -> V_227 && F_129 ( & V_143 , V_224 -> V_228 ) )
V_224 -> V_227 ( V_2 , V_224 , F_129 ( & V_99 , V_224 -> V_228 ) ) ;
F_118 ( & V_2 -> V_169 ) ;
}
static void V_173 ( struct V_221 * V_222 )
{
struct V_116 * V_2 = F_123 ( V_222 , struct V_116 ,
V_172 ) ;
const union V_79 * V_136 ;
struct V_112 * V_113 ;
T_3 V_71 , V_93 = 0 ;
F_130 () ;
while ( 1 ) {
F_57 ( & V_2 -> V_2 ) ;
V_136 = F_55 ( & V_2 -> V_2 ) ;
if ( ! V_136 )
break;
V_71 = V_136 -> V_71 & V_141 ;
if ( V_71 & 0x20 ) {
switch ( V_71 ) {
case V_142 :
break;
case V_211 :
case V_209 :
V_113 = F_84 ( V_136 -> V_113 . V_39 ) ;
if ( F_83 ( ! V_113 ) )
break;
F_122 ( V_2 , V_113 , V_136 , V_71 ) ;
if ( V_113 -> V_227 . V_215 )
V_113 -> V_227 . V_215 ( V_2 , V_113 , V_136 ) ;
break;
case V_220 :
V_113 = F_85 ( V_136 -> V_113 . V_229 ) ;
F_122 ( V_2 , V_113 , V_136 , V_71 ) ;
if ( V_113 -> V_227 . V_215 )
V_113 -> V_227 . V_215 ( V_2 , V_113 , V_136 ) ;
break;
case V_230 :
F_131 ( L_21 ) ;
break;
default:
F_19 ( L_22 , V_71 ) ;
}
} else {
V_113 = F_85 ( V_136 -> V_195 . V_123 ) ;
V_113 -> V_227 . V_195 ( V_2 , V_113 , V_136 ) ;
}
V_93 ++ ;
F_56 ( & V_2 -> V_2 ) ;
}
F_58 ( & V_2 -> V_2 , V_93 ) ;
F_132 () ;
}
static T_1 F_90 ( struct V_116 * V_2 , T_1 V_130 )
{
if ( V_130 & V_231 ) {
F_133 ( F_134 () , V_118 ,
& V_2 -> V_170 ) ;
}
if ( V_130 & V_232 ) {
F_28 ( & V_2 -> V_2 ) ;
F_29 ( & V_2 -> V_2 , 0 ) ;
F_135 ( & V_233 ) ;
}
if ( V_130 & V_194 ) {
F_133 ( F_134 () , V_118 ,
& V_2 -> V_172 ) ;
}
return V_130 ;
}
static T_7 void F_136 ( struct V_116 * V_2 , struct V_112 * V_113 )
{
V_2 -> V_234 = NULL ;
F_69 ( V_113 , V_235 ) ;
F_135 ( & V_233 ) ;
}
static inline unsigned int F_89 ( struct V_116 * V_2 ,
unsigned int V_236 )
{
const struct V_44 * V_72 ;
struct V_112 * V_113 ;
enum V_237 V_69 ;
unsigned int V_238 = 0 ;
do {
F_41 ( & V_2 -> V_2 ) ;
V_72 = F_39 ( & V_2 -> V_2 ) ;
if ( ! V_72 )
break;
if ( V_72 -> V_239 & V_240 ) {
V_113 = V_2 -> V_234 ;
if ( V_72 -> V_239 & V_241 )
F_69 ( V_113 , V_217 ) ;
V_69 = V_113 -> V_227 . V_58 ( V_2 , V_113 , V_72 ) ;
if ( V_69 == V_242 )
break;
if ( V_72 -> V_239 & V_243 )
F_136 ( V_2 , V_113 ) ;
} else {
V_113 = F_85 ( V_72 -> V_229 ) ;
V_69 = V_113 -> V_227 . V_58 ( V_2 , V_113 , V_72 ) ;
if ( V_69 == V_242 )
break;
}
F_18 ( ( V_72 -> V_239 & V_244 ) ||
( V_69 != V_245 ) ) ;
if ( V_69 != V_246 )
F_45 ( & V_2 -> V_2 , V_72 ,
V_69 == V_245 ) ;
F_40 ( & V_2 -> V_2 ) ;
} while ( ++ V_238 < V_236 && V_69 != V_247 );
return V_238 ;
}
void F_137 ( struct V_116 * V_2 , T_1 V_174 )
{
unsigned long V_248 ;
F_138 ( V_248 ) ;
F_68 ( V_174 & V_249 , & V_2 -> V_129 ) ;
F_3 ( & V_2 -> V_2 , V_185 , V_2 -> V_129 ) ;
F_139 ( V_248 ) ;
}
void F_140 ( struct V_116 * V_2 , T_1 V_174 )
{
unsigned long V_248 ;
T_1 V_250 ;
F_138 ( V_248 ) ;
V_174 &= V_249 ;
F_70 ( V_174 , & V_2 -> V_129 ) ;
F_3 ( & V_2 -> V_2 , V_185 , V_2 -> V_129 ) ;
V_250 = F_1 ( & V_2 -> V_2 , V_185 ) ;
F_3 ( & V_2 -> V_2 , V_131 , ~ V_250 ) ;
F_139 ( V_248 ) ;
}
const T_8 * F_141 ( void )
{
return & V_204 ;
}
T_9 F_142 ( int V_189 )
{
if ( V_189 < 0 ) {
struct V_116 * V_19 = F_73 () ;
V_189 = V_19 -> V_50 -> V_189 ;
F_75 () ;
}
F_83 ( ! F_143 ( V_189 , & V_204 ) ) ;
return V_205 [ V_189 ] ;
}
struct V_116 * F_144 ( int V_189 )
{
return V_206 [ V_189 ] ;
}
int F_145 ( struct V_116 * V_2 , unsigned int V_238 )
{
return F_89 ( V_2 , V_238 ) ;
}
void F_146 ( struct V_116 * V_2 , T_1 V_251 )
{
unsigned long V_248 ;
F_138 ( V_248 ) ;
V_251 &= V_2 -> V_50 -> V_251 ;
V_2 -> V_77 |= V_251 ;
F_47 ( & V_2 -> V_2 , V_2 -> V_77 ) ;
F_139 ( V_248 ) ;
}
static const char * F_147 ( T_3 V_252 )
{
switch ( V_252 ) {
case V_253 :
return L_23 ;
case V_254 :
return L_24 ;
case V_255 :
return L_25 ;
case V_256 :
return L_26 ;
case V_257 :
return L_27 ;
case V_258 :
return L_28 ;
case V_259 :
return L_29 ;
}
return L_30 ;
}
int F_148 ( T_1 V_39 , T_1 V_115 , struct V_112 * V_113 )
{
if ( V_115 & V_260 ) {
int V_147 = F_149 ( & V_39 ) ;
if ( V_147 )
return V_147 ;
}
V_113 -> V_39 = V_39 ;
V_113 -> V_115 = V_115 ;
V_113 -> V_103 = V_261 ;
V_113 -> V_262 = 0 ;
if ( V_39 == 0 || V_39 >= V_121 ) {
F_150 ( 1 , L_31 , V_39 ) ;
return - V_263 ;
}
V_113 -> V_74 = V_39 * 2 ;
if ( V_115 & V_264 )
V_113 -> V_74 ++ ;
F_83 ( V_122 [ V_113 -> V_74 ] ) ;
V_122 [ V_113 -> V_74 ] = V_113 ;
return 0 ;
}
void F_151 ( struct V_112 * V_113 )
{
switch ( V_113 -> V_103 ) {
case V_212 :
case V_261 :
if ( F_71 ( V_113 , V_260 ) )
F_152 ( V_113 -> V_39 ) ;
F_18 ( V_122 [ V_113 -> V_74 ] ) ;
V_122 [ V_113 -> V_74 ] = NULL ;
return;
default:
break;
}
F_18 ( NULL == L_32 ) ;
}
T_1 F_153 ( struct V_112 * V_113 )
{
return V_113 -> V_39 ;
}
int F_154 ( struct V_112 * V_113 , T_1 V_115 , struct V_265 * V_266 )
{
union V_105 * V_267 ;
union V_107 * V_109 ;
struct V_116 * V_2 ;
T_3 V_69 , V_40 ;
int V_147 = 0 ;
V_40 = ( V_115 & V_268 )
? V_269 : V_270 ;
if ( V_113 -> V_103 != V_261 &&
V_113 -> V_103 != V_212 )
return - V_263 ;
#ifdef F_15
if ( F_71 ( V_113 , V_264 ) )
return - V_263 ;
#endif
if ( V_266 && ( V_266 -> V_271 & V_272 ) ) {
if ( V_266 -> V_271 & V_273 )
return - V_263 ;
}
V_2 = F_73 () ;
if ( F_71 ( V_113 , V_214 ) ||
( V_113 -> V_103 != V_261 &&
V_113 -> V_103 != V_212 ) ) {
V_147 = - V_274 ;
goto V_275;
}
V_267 = F_63 ( & V_2 -> V_2 ) ;
if ( V_266 )
V_267 -> V_276 = * V_266 ;
V_267 -> V_276 . V_39 = V_113 -> V_39 ;
V_267 -> V_276 . V_277 = 0 ;
if ( F_72 ( V_113 , V_278 ) ) {
T_10 V_279 ;
V_267 -> V_276 . V_271 |= V_280 ;
V_267 -> V_276 . V_281 . V_282 = F_86 ( V_113 ) ;
if ( ! ( V_267 -> V_276 . V_271 & V_283 ) ) {
V_267 -> V_276 . V_271 |= V_283 ;
memset ( & V_267 -> V_276 . V_281 . V_284 , 0 ,
sizeof( V_267 -> V_276 . V_281 . V_284 ) ) ;
} else {
V_279 = F_155 ( & V_2 -> V_181 -> V_155 , V_113 , sizeof( * V_113 ) ,
V_285 ) ;
F_156 ( & V_267 -> V_276 . V_281 , V_279 ) ;
}
}
if ( V_115 & V_286 ) {
int V_287 = 0 ;
if ( ! ( V_267 -> V_276 . V_271 & V_288 ) ) {
V_267 -> V_276 . V_271 |= V_288 ;
V_287 = 4 ;
}
F_157 ( & V_267 -> V_276 . V_281 , V_2 -> V_50 -> V_180 , V_287 ) ;
}
F_64 ( & V_2 -> V_2 , V_40 ) ;
if ( ! F_65 ( & V_2 -> V_2 , & V_109 ) ) {
F_94 ( V_2 -> V_50 -> V_155 , L_33 ) ;
V_147 = - V_289 ;
goto V_275;
}
F_18 ( ( V_109 -> V_71 & V_290 ) == V_40 ) ;
V_69 = V_109 -> V_252 ;
if ( V_69 != V_254 ) {
V_147 = - V_201 ;
goto V_275;
}
if ( V_266 ) {
if ( V_266 -> V_271 & V_291 ) {
if ( V_266 -> V_281 . V_292 & V_293 )
F_67 ( V_113 , V_294 ) ;
else
F_69 ( V_113 , V_294 ) ;
}
if ( V_266 -> V_271 & V_295 )
V_113 -> V_262 = V_266 -> V_281 . V_296 ;
}
V_113 -> V_103 = ( V_115 & V_268 ) ?
V_213 : V_212 ;
V_275:
F_75 () ;
return V_147 ;
}
int F_158 ( struct V_112 * V_113 )
{
union V_105 * V_267 ;
union V_107 * V_109 ;
struct V_116 * V_2 ;
int V_147 = 0 ;
if ( V_113 -> V_103 != V_212 )
return - V_263 ;
#ifdef F_15
if ( F_71 ( V_113 , V_264 ) )
return - V_263 ;
#endif
V_2 = F_73 () ;
if ( F_71 ( V_113 , V_214 ) ||
V_113 -> V_103 != V_212 ) {
V_147 = - V_274 ;
goto V_275;
}
V_267 = F_63 ( & V_2 -> V_2 ) ;
V_267 -> V_297 . V_39 = V_113 -> V_39 ;
F_64 ( & V_2 -> V_2 , V_298 ) ;
if ( ! F_65 ( & V_2 -> V_2 , & V_109 ) ) {
F_94 ( V_2 -> V_50 -> V_155 , L_34 ) ;
V_147 = - V_289 ;
goto V_275;
}
F_18 ( ( V_109 -> V_71 & V_290 ) == V_299 ) ;
if ( V_109 -> V_252 != V_254 ) {
V_147 = - V_201 ;
goto V_275;
}
V_113 -> V_103 = V_213 ;
V_275:
F_75 () ;
return V_147 ;
}
int F_159 ( struct V_112 * V_113 , T_1 * V_115 )
{
union V_105 * V_267 ;
union V_107 * V_109 ;
struct V_116 * V_2 ;
int V_147 ;
T_3 V_69 ;
if ( V_113 -> V_103 != V_212 &&
V_113 -> V_103 != V_213 )
return - V_263 ;
#ifdef F_15
if ( F_71 ( V_113 , V_264 ) )
return - V_263 ;
#endif
V_2 = F_73 () ;
if ( F_71 ( V_113 , V_214 ) ||
V_113 -> V_103 == V_219 ||
V_113 -> V_103 == V_261 ) {
V_147 = - V_274 ;
goto V_275;
}
V_267 = F_63 ( & V_2 -> V_2 ) ;
V_267 -> V_297 . V_39 = V_113 -> V_39 ;
F_64 ( & V_2 -> V_2 , V_300 ) ;
if ( ! F_65 ( & V_2 -> V_2 , & V_109 ) ) {
F_124 ( V_2 -> V_50 -> V_155 , L_35 ) ;
V_147 = - V_289 ;
goto V_275;
}
F_18 ( ( V_109 -> V_71 & V_290 ) == V_301 ) ;
V_69 = V_109 -> V_252 ;
if ( V_69 == V_254 ) {
V_147 = 0 ;
if ( V_109 -> V_297 . V_215 & V_302 )
F_67 ( V_113 , V_217 ) ;
if ( V_109 -> V_297 . V_215 & V_303 )
F_67 ( V_113 , V_210 ) ;
if ( V_115 )
* V_115 = V_113 -> V_115 ;
V_113 -> V_103 = V_219 ;
if ( V_113 -> V_227 . V_215 ) {
union V_79 V_136 ;
V_136 . V_71 = V_142 ;
V_136 . V_113 . V_215 = V_109 -> V_297 . V_215 ;
V_136 . V_113 . V_39 = V_113 -> V_39 ;
V_136 . V_113 . V_229 = F_86 ( V_113 ) ;
V_113 -> V_227 . V_215 ( V_2 , V_113 , & V_136 ) ;
}
} else if ( V_69 == V_258 ) {
V_147 = 1 ;
F_67 ( V_113 , V_214 ) ;
} else {
V_147 = - V_201 ;
}
V_275:
F_75 () ;
return V_147 ;
}
int F_160 ( struct V_112 * V_113 )
{
union V_105 * V_267 ;
union V_107 * V_109 ;
struct V_116 * V_2 ;
int V_147 = 0 ;
if ( V_113 -> V_103 != V_219 )
return - V_263 ;
#ifdef F_15
if ( F_71 ( V_113 , V_264 ) )
return - V_263 ;
#endif
V_2 = F_73 () ;
if ( F_71 ( V_113 , V_304 ) ||
V_113 -> V_103 != V_219 ) {
V_147 = - V_274 ;
goto V_275;
}
V_267 = F_63 ( & V_2 -> V_2 ) ;
V_267 -> V_297 . V_39 = V_113 -> V_39 ;
F_64 ( & V_2 -> V_2 , V_305 ) ;
if ( ! F_65 ( & V_2 -> V_2 , & V_109 ) ) {
V_147 = - V_289 ;
goto V_275;
}
F_18 ( ( V_109 -> V_71 & V_290 ) == V_306 ) ;
if ( V_109 -> V_252 != V_254 ) {
V_147 = - V_201 ;
goto V_275;
}
V_113 -> V_103 = V_261 ;
V_275:
F_75 () ;
return V_147 ;
}
int F_161 ( struct V_112 * V_113 , struct V_307 * V_281 )
{
union V_105 * V_267 ;
union V_107 * V_109 ;
struct V_116 * V_2 = F_73 () ;
int V_147 = 0 ;
V_267 = F_63 ( & V_2 -> V_2 ) ;
V_267 -> V_308 . V_39 = V_113 -> V_39 ;
F_64 ( & V_2 -> V_2 , V_309 ) ;
if ( ! F_65 ( & V_2 -> V_2 , & V_109 ) ) {
V_147 = - V_289 ;
goto V_275;
}
F_18 ( ( V_109 -> V_71 & V_290 ) == V_310 ) ;
if ( V_109 -> V_252 == V_254 )
* V_281 = V_109 -> V_308 . V_281 ;
else
V_147 = - V_201 ;
V_275:
F_75 () ;
return V_147 ;
}
static int F_162 ( struct V_112 * V_113 ,
struct V_311 * V_312 )
{
union V_105 * V_267 ;
union V_107 * V_109 ;
struct V_116 * V_2 = F_73 () ;
int V_147 = 0 ;
V_267 = F_63 ( & V_2 -> V_2 ) ;
V_267 -> V_308 . V_39 = V_113 -> V_39 ;
F_64 ( & V_2 -> V_2 , V_313 ) ;
if ( ! F_65 ( & V_2 -> V_2 , & V_109 ) ) {
V_147 = - V_289 ;
goto V_275;
}
F_18 ( ( V_109 -> V_71 & V_290 ) == V_314 ) ;
if ( V_109 -> V_252 == V_254 )
* V_312 = V_109 -> V_315 ;
else if ( V_109 -> V_252 == V_255 )
V_147 = - V_316 ;
else
V_147 = - V_201 ;
V_275:
F_75 () ;
return V_147 ;
}
static int F_163 ( struct V_223 * V_224 ,
struct V_317 * V_318 )
{
union V_105 * V_267 ;
union V_107 * V_109 ;
struct V_116 * V_2 = F_73 () ;
int V_147 = 0 ;
V_267 = F_63 ( & V_2 -> V_2 ) ;
V_267 -> V_319 . V_296 = V_224 -> V_228 ;
F_64 ( & V_2 -> V_2 , V_320 ) ;
if ( ! F_65 ( & V_2 -> V_2 , & V_109 ) ) {
V_147 = - V_289 ;
goto V_275;
}
F_18 ( ( V_109 -> V_71 & V_290 ) == V_320 ) ;
if ( V_109 -> V_252 == V_254 )
* V_318 = V_109 -> V_319 ;
else {
F_94 ( V_2 -> V_50 -> V_155 , L_36 ,
F_147 ( V_109 -> V_252 ) ) ;
V_147 = - V_201 ;
}
V_275:
F_75 () ;
return V_147 ;
}
int F_164 ( struct V_223 * V_224 , bool * V_252 )
{
struct V_317 V_321 ;
int V_202 ;
V_202 = F_163 ( V_224 , & V_321 ) ;
if ( V_202 )
return V_202 ;
* V_252 = ! ! V_321 . V_224 . V_322 ;
return 0 ;
}
static int F_165 ( struct V_116 * V_2 , struct V_112 * V_113 , T_1 V_78 )
{
unsigned long V_248 ;
int V_147 = - V_274 ;
F_138 ( V_248 ) ;
if ( V_2 -> V_234 )
goto V_275;
if ( F_71 ( V_113 , V_235 ) )
goto V_275;
F_67 ( V_113 , V_235 ) ;
V_2 -> V_234 = V_113 ;
F_48 ( & V_2 -> V_2 , V_78 ) ;
V_147 = 0 ;
V_275:
F_139 ( V_248 ) ;
return V_147 ;
}
static int F_166 ( struct V_116 * * V_2 , struct V_112 * V_113 , T_1 V_78 )
{
int V_147 ;
* V_2 = F_73 () ;
V_147 = F_165 ( * V_2 , V_113 , V_78 ) ;
F_75 () ;
return V_147 ;
}
static int F_167 ( struct V_116 * * V_2 , struct V_112 * V_113 ,
T_1 V_78 , T_1 V_115 )
{
int V_147 = 0 ;
if ( V_115 & V_323 )
V_147 = F_168 ( V_233 ,
! F_166 ( V_2 , V_113 , V_78 ) ) ;
else
F_169 ( V_233 , ! F_166 ( V_2 , V_113 , V_78 ) ) ;
return V_147 ;
}
int F_170 ( struct V_112 * V_113 , T_1 V_115 , T_1 V_78 )
{
struct V_116 * V_2 ;
int V_147 ;
if ( V_113 -> V_103 != V_212 &&
V_113 -> V_103 != V_219 )
return - V_263 ;
if ( V_78 & V_324 )
return - V_263 ;
if ( F_71 ( V_113 , V_235 ) )
return - V_274 ;
V_78 = ( V_78 & ~ V_324 ) | V_113 -> V_39 ;
if ( V_115 & V_325 )
V_147 = F_167 ( & V_2 , V_113 , V_78 , V_115 ) ;
else
V_147 = F_166 ( & V_2 , V_113 , V_78 ) ;
if ( V_147 )
return V_147 ;
if ( V_115 & V_326 ) {
if ( V_115 & V_323 )
F_168 ( V_233 ,
! F_71 ( V_113 , V_235 ) ) ;
else
F_169 ( V_233 ,
! F_71 ( V_113 , V_235 ) ) ;
}
return 0 ;
}
static void F_171 ( struct V_116 * V_2 , T_3 V_327 )
{
if ( V_327 )
F_27 ( & V_2 -> V_2 ) ;
else
F_28 ( & V_2 -> V_2 ) ;
}
int F_172 ( struct V_112 * V_113 , const struct V_328 * V_197 )
{
struct V_116 * V_2 ;
struct V_8 * V_329 ;
unsigned long V_248 ;
T_3 V_327 ;
V_2 = F_73 () ;
F_138 ( V_248 ) ;
if ( V_2 -> V_149 ) {
V_329 = F_22 ( & V_2 -> V_2 ) ;
} else {
V_327 = F_30 ( & V_2 -> V_2 ) ;
if ( V_327 < 2 )
F_171 ( V_2 , V_327 ) ;
V_329 = F_20 ( & V_2 -> V_2 ) ;
}
if ( F_88 ( ! V_329 ) )
goto V_275;
V_329 -> V_39 = V_113 -> V_39 ;
V_329 -> V_123 = F_86 ( V_113 ) ;
V_329 -> V_197 = * V_197 ;
F_24 ( & V_2 -> V_2 , V_330 ) ;
V_275:
F_139 ( V_248 ) ;
F_75 () ;
return 0 ;
}
static int F_173 ( struct V_223 * V_224 , T_1 V_115 ,
struct V_331 * V_266 )
{
union V_105 * V_267 ;
union V_107 * V_109 ;
struct V_116 * V_2 = F_73 () ;
T_3 V_71 = V_332 ;
int V_147 = 0 ;
V_267 = F_63 ( & V_2 -> V_2 ) ;
if ( V_266 )
V_267 -> V_333 = * V_266 ;
V_267 -> V_333 . V_296 = V_224 -> V_228 ;
if ( V_115 & V_334 )
V_71 = V_335 ;
F_64 ( & V_2 -> V_2 , V_71 ) ;
if ( ! F_65 ( & V_2 -> V_2 , & V_109 ) ) {
V_147 = - V_289 ;
goto V_275;
}
F_18 ( ( V_109 -> V_71 & V_290 ) == V_71 ) ;
if ( V_109 -> V_252 != V_254 )
V_147 = - V_201 ;
V_275:
F_75 () ;
return V_147 ;
}
void F_174 ( void )
{
struct V_223 V_224 ;
int V_336 = 0 ;
for ( V_224 . V_228 = 0 ; V_224 . V_228 < V_337 ; V_224 . V_228 ++ ) {
if ( F_173 ( & V_224 , V_334 , NULL ) )
V_336 ++ ;
}
if ( V_336 )
F_92 ( L_37 ,
V_336 , ( V_336 > 1 ) ? L_38 : L_39 ) ;
}
int F_175 ( struct V_223 * V_224 , T_1 V_115 ,
struct V_331 * V_266 )
{
struct V_317 V_338 ;
struct V_331 V_339 = {} ;
int V_147 ;
struct V_116 * V_2 ;
if ( V_224 -> V_228 >= V_337 )
return - V_263 ;
F_130 () ;
V_2 = F_73 () ;
V_340 [ V_224 -> V_228 ] = F_134 () ;
F_132 () ;
V_224 -> V_341 = V_2 -> V_50 -> V_180 ;
F_116 ( & V_2 -> V_169 ) ;
if ( V_266 ) {
V_147 = F_163 ( V_224 , & V_338 ) ;
if ( V_147 )
goto V_275;
if ( V_266 )
V_339 = * V_266 ;
if ( ( V_150 & 0xFF00 ) >= V_151 )
V_339 . V_224 . V_342 =
V_343 | F_176 ( V_2 ) ;
else
V_339 . V_224 . V_344 = V_338 . V_224 . V_344 |
F_177 ( V_2 ) ;
V_339 . V_271 |= V_345 ;
if ( V_266 && ( V_115 & V_334 ) )
V_147 = F_173 ( V_224 , V_334 ,
& V_339 ) ;
else
V_147 = F_173 ( V_224 , 0 , & V_339 ) ;
if ( V_147 )
goto V_275;
}
F_178 ( & V_224 -> V_346 , & V_2 -> V_168 ) ;
V_147 = F_163 ( V_224 , & V_338 ) ;
if ( V_147 ) {
F_94 ( V_2 -> V_50 -> V_155 , L_40 ) ;
V_147 = 0 ;
goto V_275;
}
if ( V_224 -> V_227 && V_338 . V_224 . V_347 &&
F_129 ( & V_2 -> V_145 [ 1 ] , V_224 -> V_228 ) )
V_224 -> V_227 ( V_2 , V_224 , 1 ) ;
V_275:
F_118 ( & V_2 -> V_169 ) ;
F_75 () ;
return V_147 ;
}
int F_179 ( struct V_223 * V_224 )
{
unsigned long V_248 ;
struct V_317 V_338 ;
struct V_331 V_339 ;
int V_147 = 0 ;
struct V_223 * V_348 ;
struct V_116 * V_2 = F_73 () ;
if ( V_224 -> V_341 != V_2 -> V_50 -> V_180 ) {
F_94 ( V_2 -> V_50 -> V_155 , L_41 ) ;
F_180 ( V_2 -> V_50 -> V_155 , L_42 ,
V_224 -> V_341 , V_2 -> V_50 -> V_180 ) ;
V_147 = - V_263 ;
goto V_349;
}
memset ( & V_339 , 0 , sizeof( struct V_331 ) ) ;
F_181 ( & V_2 -> V_169 , V_248 ) ;
F_182 ( & V_224 -> V_346 ) ;
F_128 (i, &p->cgr_cbs, node)
if ( V_348 -> V_228 == V_224 -> V_228 && V_348 -> V_227 )
goto V_350;
V_147 = F_163 ( V_224 , & V_338 ) ;
if ( V_147 ) {
F_178 ( & V_224 -> V_346 , & V_2 -> V_168 ) ;
goto V_350;
}
V_339 . V_271 = V_345 ;
if ( ( V_150 & 0xFF00 ) >= V_151 )
V_339 . V_224 . V_342 = F_176 ( V_2 ) ;
else
V_339 . V_224 . V_344 = V_338 . V_224 . V_344 &
~ ( F_177 ( V_2 ) ) ;
V_147 = F_173 ( V_224 , 0 , & V_339 ) ;
if ( V_147 )
F_178 ( & V_224 -> V_346 , & V_2 -> V_168 ) ;
V_350:
F_183 ( & V_2 -> V_169 , V_248 ) ;
V_349:
F_75 () ;
return V_147 ;
}
static int F_184 ( void * V_2 )
{
struct V_351 * V_351 = (struct V_351 * ) V_2 ;
int V_147 ;
V_147 = F_179 ( V_351 -> V_224 ) ;
F_185 ( & V_351 -> V_352 ) ;
return V_147 ;
}
void F_186 ( struct V_223 * V_224 )
{
struct V_353 * V_354 ;
struct V_351 V_351 ;
F_130 () ;
if ( V_340 [ V_224 -> V_228 ] != F_134 () ) {
F_187 ( & V_351 . V_352 ) ;
V_351 . V_224 = V_224 ;
V_354 = F_188 ( F_184 , & V_351 ,
L_43 ) ;
if ( F_189 ( V_354 ) )
goto V_275;
F_190 ( V_354 , V_340 [ V_224 -> V_228 ] ) ;
F_191 ( V_354 ) ;
F_192 ( & V_351 . V_352 ) ;
F_132 () ;
return;
}
V_275:
F_179 ( V_224 ) ;
F_132 () ;
}
static int F_193 ( struct V_1 * V_2 , int V_355 )
{
const union V_79 * V_136 ;
int V_356 = 0 ;
F_57 ( V_2 ) ;
V_136 = F_55 ( V_2 ) ;
while ( V_136 ) {
if ( ( V_136 -> V_71 & V_141 ) == V_355 )
V_356 = 1 ;
F_56 ( V_2 ) ;
F_59 ( V_2 ) ;
F_57 ( V_2 ) ;
V_136 = F_55 ( V_2 ) ;
}
return V_356 ;
}
static int F_194 ( struct V_1 * V_2 , T_1 V_39 , int V_357 ,
bool V_358 )
{
const struct V_44 * V_58 ;
int V_356 = 0 ;
do {
F_41 ( V_2 ) ;
V_58 = F_39 ( V_2 ) ;
if ( ! V_58 )
F_195 () ;
} while ( V_358 && ! V_58 );
while ( V_58 ) {
if ( V_58 -> V_39 == V_39 && ( V_58 -> V_239 & V_357 ) )
V_356 = 1 ;
F_45 ( V_2 , V_58 , 0 ) ;
F_41 ( V_2 ) ;
F_40 ( V_2 ) ;
V_58 = F_39 ( V_2 ) ;
}
return V_356 ;
}
static int F_196 ( T_1 V_39 )
{
struct V_116 * V_2 ;
struct V_359 * V_155 ;
union V_105 * V_267 ;
union V_107 * V_109 ;
int V_360 , V_361 = 0 , V_147 = 0 ;
T_1 V_180 , V_287 , V_69 ;
T_3 V_103 ;
V_2 = F_73 () ;
V_155 = V_2 -> V_50 -> V_155 ;
V_267 = F_63 ( & V_2 -> V_2 ) ;
V_267 -> V_315 . V_39 = V_39 ;
F_64 ( & V_2 -> V_2 , V_313 ) ;
if ( ! F_65 ( & V_2 -> V_2 , & V_109 ) ) {
F_94 ( V_155 , L_44 ) ;
V_147 = - V_289 ;
goto V_275;
}
F_18 ( ( V_109 -> V_71 & V_290 ) == V_314 ) ;
V_103 = V_109 -> V_315 . V_103 & V_362 ;
if ( V_103 == V_363 )
goto V_275;
V_267 = F_63 ( & V_2 -> V_2 ) ;
V_267 -> V_308 . V_39 = V_39 ;
F_64 ( & V_2 -> V_2 , V_309 ) ;
if ( ! F_65 ( & V_2 -> V_2 , & V_109 ) ) {
F_94 ( V_155 , L_45 ) ;
V_147 = - V_289 ;
goto V_275;
}
F_18 ( ( V_109 -> V_71 & V_290 ) == V_310 ) ;
V_180 = F_197 ( & V_109 -> V_308 . V_281 ) ;
V_287 = F_198 ( & V_109 -> V_308 . V_281 ) ;
switch ( V_103 ) {
case V_364 :
case V_365 :
case V_366 :
case V_367 :
V_360 = 0 ;
V_267 = F_63 ( & V_2 -> V_2 ) ;
V_267 -> V_297 . V_39 = V_39 ;
F_64 ( & V_2 -> V_2 , V_300 ) ;
if ( ! F_65 ( & V_2 -> V_2 , & V_109 ) ) {
F_94 ( V_155 , L_44 ) ;
V_147 = - V_289 ;
goto V_275;
}
F_18 ( ( V_109 -> V_71 & V_290 ) ==
V_301 ) ;
V_69 = V_109 -> V_252 ;
if ( V_69 == V_258 ) {
int V_368 = 0 ;
T_9 V_369 = 0 ;
V_361 = 1 ;
if ( V_180 >= V_370 &&
V_180 < V_370 + 15 ) {
V_369 = ( V_180 -
V_370 + 1 ) << 4 | V_287 ;
} else if ( V_180 < V_370 ) {
V_369 = V_287 ;
} else {
F_94 ( V_155 , L_46 ,
V_39 , V_180 ) ;
V_147 = - V_274 ;
goto V_275;
}
if ( V_180 < V_370 )
F_47 ( & V_2 -> V_2 ,
V_371 |
V_179 ) ;
else
F_47 ( & V_2 -> V_2 ,
V_371 |
F_199
( V_180 ) ) ;
do {
F_200 ( & V_2 -> V_2 ) ;
V_368 = F_201 ( & V_2 -> V_2 , V_372 ) ;
F_195 () ;
} while ( ! V_368 );
}
if ( V_69 != V_254 &&
V_69 != V_258 ) {
F_94 ( V_155 , L_47 ,
V_39 , V_69 ) ;
V_147 = - V_201 ;
goto V_275;
}
if ( ! ( V_109 -> V_297 . V_215 & V_303 ) ) {
V_360 = 1 ;
}
if ( V_361 || V_109 -> V_297 . V_215 & V_302 ) {
do {
T_1 V_78 = V_39 | F_202 ( 3 ) ;
F_48 ( & V_2 -> V_2 , V_78 ) ;
} while ( F_203 ( & V_2 -> V_2 , V_39 , V_373 ) );
}
F_47 ( & V_2 -> V_2 , 0 ) ;
while ( ! V_360 ) {
V_360 = F_201 ( & V_2 -> V_2 , V_374 ) ;
F_195 () ;
}
V_267 = F_63 ( & V_2 -> V_2 ) ;
V_267 -> V_297 . V_39 = V_39 ;
F_64 ( & V_2 -> V_2 , V_305 ) ;
if ( ! F_65 ( & V_2 -> V_2 , & V_109 ) ) {
V_147 = - V_289 ;
goto V_275;
}
F_18 ( ( V_109 -> V_71 & V_290 ) ==
V_306 ) ;
if ( V_109 -> V_252 != V_254 ) {
F_94 ( V_155 , L_48 ,
V_39 , V_109 -> V_252 ) ;
V_147 = - V_201 ;
goto V_275;
}
break;
case V_375 :
V_267 = F_63 ( & V_2 -> V_2 ) ;
V_267 -> V_297 . V_39 = V_39 ;
F_64 ( & V_2 -> V_2 , V_305 ) ;
if ( ! F_65 ( & V_2 -> V_2 , & V_109 ) ) {
V_147 = - V_289 ;
goto V_275;
}
F_18 ( ( V_109 -> V_71 & V_290 ) ==
V_306 ) ;
if ( V_109 -> V_252 ) {
F_94 ( V_155 , L_49 ,
V_39 , V_109 -> V_252 ) ;
V_147 = - V_201 ;
goto V_275;
}
break;
case V_363 :
break;
default:
V_147 = - V_201 ;
}
V_275:
F_75 () ;
return V_147 ;
}
const struct V_49 * F_204 (
struct V_116 * V_19 )
{
return V_19 -> V_50 ;
}
static int F_205 ( struct V_376 * V_2 , T_1 * V_252 , T_1 V_377 )
{
unsigned long V_4 ;
V_4 = F_206 ( V_2 , V_377 ) ;
if ( ! V_4 )
return - V_119 ;
* V_252 = V_4 & ~ V_378 ;
return 0 ;
}
int F_207 ( T_1 * V_252 , T_1 V_277 )
{
return F_205 ( V_379 , V_252 , V_277 ) ;
}
int F_208 ( T_1 * V_252 , T_1 V_277 )
{
return F_205 ( V_380 , V_252 , V_277 ) ;
}
int F_209 ( T_1 * V_252 , T_1 V_277 )
{
return F_205 ( V_381 , V_252 , V_277 ) ;
}
int F_152 ( T_1 V_39 )
{
int V_147 = F_196 ( V_39 ) ;
if ( V_147 ) {
F_81 ( L_50 , V_39 ) ;
return V_147 ;
}
F_210 ( V_379 , V_39 | V_378 , 1 ) ;
return 0 ;
}
static int F_211 ( T_1 V_382 )
{
struct V_112 V_113 = {
. V_39 = V_383
} ;
int V_202 ;
do {
struct V_311 V_312 ;
V_202 = F_162 ( & V_113 , & V_312 ) ;
if ( V_202 )
return 0 ;
if ( ( V_312 . V_103 & V_362 ) != V_363 ) {
struct V_307 V_281 ;
V_202 = F_161 ( & V_113 , & V_281 ) ;
if ( F_83 ( V_202 ) )
return 0 ;
if ( F_197 ( & V_281 ) == V_382 ) {
V_202 = F_196 ( V_113 . V_39 ) ;
if ( V_202 )
return V_202 ;
}
}
V_113 . V_39 ++ ;
} while ( 1 );
}
int F_212 ( T_1 V_382 )
{
int V_147 ;
V_147 = F_211 ( V_382 ) ;
if ( V_147 ) {
F_81 ( L_51 , V_382 ) ;
return V_147 ;
}
F_210 ( V_380 , V_382 | V_378 , 1 ) ;
return 0 ;
}
static int F_213 ( T_1 V_228 )
{
struct V_112 V_113 = {
. V_39 = 1
} ;
int V_202 ;
do {
struct V_311 V_312 ;
V_202 = F_162 ( & V_113 , & V_312 ) ;
if ( V_202 )
return 0 ;
if ( ( V_312 . V_103 & V_362 ) != V_363 ) {
struct V_307 V_281 ;
V_202 = F_161 ( & V_113 , & V_281 ) ;
if ( F_83 ( V_202 ) )
return 0 ;
if ( ( V_281 . V_292 & V_293 ) &&
V_281 . V_296 == V_228 ) {
F_92 ( L_52 ,
V_228 , V_113 . V_39 ) ;
return - V_201 ;
}
}
V_113 . V_39 ++ ;
} while ( 1 );
}
int F_214 ( T_1 V_228 )
{
int V_147 ;
V_147 = F_213 ( V_228 ) ;
if ( V_147 ) {
F_81 ( L_53 , V_228 ) ;
return V_147 ;
}
F_210 ( V_381 , V_228 | V_378 , 1 ) ;
return 0 ;
}
