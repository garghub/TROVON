static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( F_3 ( V_2 -> V_4 . V_5 + V_3 ) ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_5 ( F_6 ( V_6 ) , V_2 -> V_4 . V_5 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
F_8 ( V_2 -> V_4 . V_7 + V_3 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
F_10 ( V_2 -> V_4 . V_7 + V_3 ) ;
}
static inline T_1 F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( F_3 ( V_2 -> V_4 . V_7 + V_3 ) ) ;
}
static struct V_8 * F_12 ( struct V_8 * V_2 )
{
T_2 V_4 = ( T_2 ) V_2 ;
V_4 &= ~ V_9 ;
return (struct V_8 * ) V_4 ;
}
static int F_13 ( struct V_8 * V_10 )
{
return ( ( T_2 ) V_10 >> V_11 ) & ( V_12 - 1 ) ;
}
static inline void F_14 ( struct V_13 * V_14 )
{
struct V_8 * V_15 = V_14 -> V_16 + 1 ;
V_14 -> V_16 = F_12 ( V_15 ) ;
if ( V_15 != V_14 -> V_16 )
V_14 -> V_17 ^= V_18 ;
}
static inline int F_15 ( struct V_1 * V_19 ,
enum V_20 V_21 ,
unsigned int V_22 ,
int V_23 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
T_1 V_24 ;
T_3 V_25 ;
V_14 -> V_26 = V_19 -> V_4 . V_7 + V_27 ;
V_14 -> V_5 = F_1 ( V_19 , V_28 ) & ( V_12 - 1 ) ;
F_7 ( V_19 , V_29 ) ;
V_25 = F_1 ( V_19 , V_30 ) & ( V_12 - 1 ) ;
V_14 -> V_16 = V_14 -> V_26 + V_25 ;
V_14 -> V_17 = ( F_1 ( V_19 , V_30 ) & V_12 ) ?
V_18 : 0 ;
V_14 -> V_31 = V_12 - 1 -
F_16 ( V_12 , V_14 -> V_5 , V_25 ) ;
V_14 -> V_32 = F_1 ( V_19 , V_33 ) ;
#ifdef F_17
V_14 -> V_34 = 0 ;
V_14 -> V_21 = V_21 ;
#endif
V_24 = ( F_1 ( V_19 , V_35 ) & 0x00ffffff ) |
( V_22 << 28 ) |
( V_23 << 26 ) |
( ( V_21 & 0x3 ) << 24 ) ;
F_4 ( V_19 , V_35 , V_24 ) ;
return 0 ;
}
static inline unsigned int F_18 ( struct V_1 * V_19 )
{
return ( F_1 ( V_19 , V_35 ) >> 28 ) & 0x7 ;
}
static inline void F_19 ( struct V_1 * V_19 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
T_3 V_25 = F_1 ( V_19 , V_30 ) & ( V_12 - 1 ) ;
T_3 V_5 = F_1 ( V_19 , V_28 ) & ( V_12 - 1 ) ;
F_20 ( ! V_14 -> V_34 ) ;
if ( V_25 != F_13 ( V_14 -> V_16 ) )
F_21 ( L_1 ) ;
if ( V_5 != V_14 -> V_5 )
F_21 ( L_2 ) ;
if ( V_14 -> V_5 != F_13 ( V_14 -> V_16 ) )
F_21 ( L_3 ) ;
}
static inline struct V_8 * F_22 ( struct V_1
* V_19 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
F_20 ( ! V_14 -> V_34 ) ;
if ( ! V_14 -> V_31 )
return NULL ;
#ifdef F_17
V_14 -> V_34 = 1 ;
#endif
F_23 ( V_14 -> V_16 ) ;
return V_14 -> V_16 ;
}
static inline struct V_8 * F_24 ( struct V_1
* V_19 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
T_3 V_36 , V_37 ;
F_20 ( ! V_14 -> V_34 ) ;
if ( ! V_14 -> V_31 ) {
V_37 = V_14 -> V_5 ;
V_14 -> V_5 = F_11 ( V_19 , V_29 ) &
( V_12 - 1 ) ;
V_36 = F_16 ( V_12 , V_37 , V_14 -> V_5 ) ;
V_14 -> V_31 += V_36 ;
if ( ! V_36 )
return NULL ;
}
#ifdef F_17
V_14 -> V_34 = 1 ;
#endif
F_23 ( V_14 -> V_16 ) ;
return V_14 -> V_16 ;
}
static inline void F_25 ( struct V_13 * V_14 )
{
F_20 ( V_14 -> V_34 ) ;
F_20 ( ! ( F_2 ( V_14 -> V_16 -> V_38 ) & ~ V_39 ) ) ;
F_20 ( V_14 -> V_31 >= 1 ) ;
}
static inline void F_26 ( struct V_1 * V_19 , T_3 V_40 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
struct V_8 * V_41 ;
F_25 ( V_14 ) ;
F_20 ( V_14 -> V_21 == V_42 ) ;
F_27 () ;
V_41 = V_14 -> V_16 ;
V_41 -> V_43 = V_40 | V_14 -> V_17 ;
F_28 ( V_41 ) ;
F_14 ( V_14 ) ;
V_14 -> V_31 -- ;
#ifdef F_17
V_14 -> V_34 = 0 ;
#endif
}
static inline void F_29 ( struct V_1 * V_19 )
{
F_9 ( V_19 , V_29 ) ;
}
static inline T_3 F_30 ( struct V_1 * V_19 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
T_3 V_36 , V_37 = V_14 -> V_5 ;
V_14 -> V_5 = F_11 ( V_19 , V_29 ) & ( V_12 - 1 ) ;
F_7 ( V_19 , V_29 ) ;
V_36 = F_16 ( V_12 , V_37 , V_14 -> V_5 ) ;
V_14 -> V_31 += V_36 ;
return V_36 ;
}
static inline void F_31 ( struct V_1 * V_19 , T_3 V_32 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
V_14 -> V_32 = V_32 ;
F_4 ( V_19 , V_33 , V_32 ) ;
}
static inline T_3 F_32 ( struct V_1 * V_19 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
return V_14 -> V_31 ;
}
static inline T_3 F_33 ( struct V_1 * V_19 )
{
struct V_13 * V_14 = & V_19 -> V_14 ;
return V_12 - 1 - V_14 -> V_31 ;
}
static const struct V_44 * F_34 (
const struct V_44 * V_2 )
{
T_2 V_4 = ( T_2 ) V_2 ;
V_4 &= ~ V_45 ;
return ( const struct V_44 * ) V_4 ;
}
static inline int F_35 ( const struct V_44 * V_10 )
{
return ( ( T_2 ) V_10 >> V_46 ) & ( V_47 - 1 ) ;
}
static const struct V_44 * F_36 ( const struct V_44 * V_10 )
{
return F_34 ( V_10 + 1 ) ;
}
static inline void F_37 ( struct V_1 * V_19 , T_3 V_48 )
{
F_4 ( V_19 , V_35 , ( F_1 ( V_19 , V_35 ) & 0xff0fffff ) |
( ( V_48 & ( V_47 - 1 ) ) << 20 ) ) ;
}
static inline int F_38 ( struct V_1 * V_19 ,
const struct V_49 * V_50 ,
enum V_51 V_52 ,
enum V_53 V_21 ,
enum V_54 V_55 , T_3 V_56 )
{
struct V_57 * V_58 = & V_19 -> V_58 ;
T_1 V_24 ;
F_4 ( V_19 , V_59 , 0 ) ;
F_4 ( V_19 , V_60 , 0 ) ;
F_4 ( V_19 , V_61 , 0 ) ;
V_58 -> V_26 = V_19 -> V_4 . V_7 + V_62 ;
V_58 -> V_25 = F_1 ( V_19 , V_63 ) & ( V_47 - 1 ) ;
V_58 -> V_5 = F_1 ( V_19 , V_64 ) & ( V_47 - 1 ) ;
V_58 -> V_16 = V_58 -> V_26 + V_58 -> V_5 ;
V_58 -> V_65 = F_16 ( V_47 , V_58 -> V_5 , V_58 -> V_25 ) ;
V_58 -> V_17 = ( F_1 ( V_19 , V_63 ) & V_47 ) ?
V_66 : 0 ;
V_58 -> V_32 = F_1 ( V_19 , V_67 ) ;
#ifdef F_17
V_58 -> V_52 = V_52 ;
V_58 -> V_21 = V_21 ;
V_58 -> V_55 = V_55 ;
#endif
for ( V_24 = 0 ; V_24 < V_47 ; V_24 ++ )
F_8 ( F_39 ( V_58 -> V_26 , V_24 ) ) ;
V_24 = ( F_1 ( V_19 , V_35 ) & 0xff000f00 ) |
( ( V_56 & ( V_47 - 1 ) ) << 20 ) |
( ( V_52 & 1 ) << 18 ) |
( ( V_55 & 3 ) << 16 ) |
0xa0 |
( 0 ? 0x40 : 0 ) |
( 0 ? 0x10 : 0 ) ;
F_4 ( V_19 , V_35 , V_24 ) ;
F_37 ( V_19 , V_56 ) ;
return 0 ;
}
static inline void F_40 ( struct V_1 * V_19 )
{
#ifdef F_17
struct V_57 * V_58 = & V_19 -> V_58 ;
if ( V_58 -> V_55 != V_68 &&
V_58 -> V_5 != F_35 ( V_58 -> V_16 ) )
F_21 ( L_4 ) ;
#endif
}
static inline const struct V_44 * F_41 (
struct V_1 * V_19 )
{
struct V_57 * V_58 = & V_19 -> V_58 ;
if ( ! V_58 -> V_65 )
return NULL ;
return V_58 -> V_16 ;
}
static inline T_3 F_42 ( struct V_1 * V_19 )
{
struct V_57 * V_58 = & V_19 -> V_58 ;
F_20 ( V_58 -> V_65 ) ;
V_58 -> V_16 = F_36 ( V_58 -> V_16 ) ;
return -- V_58 -> V_65 ;
}
static inline void F_43 ( struct V_1 * V_19 )
{
struct V_57 * V_58 = & V_19 -> V_58 ;
struct V_44 * V_69 = F_39 ( V_58 -> V_26 , V_58 -> V_25 ) ;
F_20 ( V_58 -> V_21 == V_70 ) ;
#ifndef F_44
F_45 ( V_69 ) ;
#endif
if ( ( F_46 ( & V_69 -> V_71 ) & V_66 ) == V_58 -> V_17 ) {
V_58 -> V_25 = ( V_58 -> V_25 + 1 ) & ( V_47 - 1 ) ;
if ( ! V_58 -> V_25 )
V_58 -> V_17 ^= V_66 ;
V_58 -> V_65 ++ ;
}
}
static inline void F_47 ( struct V_1 * V_19 ,
const struct V_44 * V_72 ,
int V_73 )
{
T_4 struct V_57 * V_58 = & V_19 -> V_58 ;
int V_74 = F_35 ( V_72 ) ;
F_20 ( V_58 -> V_55 == V_68 ) ;
F_20 ( ( V_58 -> V_26 + V_74 ) == V_72 ) ;
F_20 ( V_74 < V_47 ) ;
F_4 ( V_19 , V_75 , ( 0 << 8 ) |
( ( V_73 ? 1 : 0 ) << 6 ) |
V_74 ) ;
}
static inline void F_48 ( struct V_1 * V_19 , T_1 V_76 )
{
T_4 struct V_57 * V_58 = & V_19 -> V_58 ;
F_20 ( V_58 -> V_55 == V_68 ) ;
F_4 ( V_19 , V_75 , ( 1 << 8 ) |
( V_76 << 16 ) ) ;
}
static inline void F_49 ( struct V_1 * V_19 , T_1 V_77 )
{
F_4 ( V_19 , V_59 , V_77 ) ;
}
static inline void F_50 ( struct V_1 * V_19 , T_1 V_78 )
{
F_4 ( V_19 , V_60 , V_78 ) ;
}
static inline void F_51 ( struct V_1 * V_19 , T_3 V_32 )
{
F_4 ( V_19 , V_67 , V_32 ) ;
}
static union V_79 * F_52 ( union V_79 * V_2 )
{
T_2 V_4 = ( T_2 ) V_2 ;
V_4 &= ~ V_80 ;
return (union V_79 * ) V_4 ;
}
static inline int F_53 ( const union V_79 * V_10 )
{
return ( ( T_2 ) V_10 >> V_81 ) & ( V_82 - 1 ) ;
}
static inline union V_79 * F_54 ( union V_79 * V_10 )
{
return F_52 ( V_10 + 1 ) ;
}
static inline int F_55 ( struct V_1 * V_19 , enum V_83 V_21 ,
enum V_84 V_55 )
{
struct V_85 * V_86 = & V_19 -> V_86 ;
T_1 V_24 ;
V_86 -> V_26 = V_19 -> V_4 . V_7 + V_87 ;
V_86 -> V_25 = F_1 ( V_19 , V_88 ) & ( V_82 - 1 ) ;
V_86 -> V_5 = F_1 ( V_19 , V_89 ) & ( V_82 - 1 ) ;
V_86 -> V_16 = V_86 -> V_26 + V_86 -> V_5 ;
V_86 -> V_65 = F_16 ( V_82 , V_86 -> V_5 , V_86 -> V_25 ) ;
V_86 -> V_17 = ( F_1 ( V_19 , V_88 ) & V_82 )
? V_90 : 0 ;
V_86 -> V_32 = F_1 ( V_19 , V_91 ) ;
#ifdef F_17
V_86 -> V_21 = V_21 ;
V_86 -> V_55 = V_55 ;
#endif
V_24 = ( F_1 ( V_19 , V_35 ) & 0xfffff0ff ) |
( ( V_55 & 1 ) << 8 ) ;
F_4 ( V_19 , V_35 , V_24 ) ;
return 0 ;
}
static inline void F_56 ( struct V_1 * V_19 )
{
struct V_85 * V_86 = & V_19 -> V_86 ;
if ( V_86 -> V_5 != F_53 ( V_86 -> V_16 ) )
F_21 ( L_5 ) ;
}
static inline const union V_79 * F_57 ( struct V_1 * V_19 )
{
struct V_85 * V_86 = & V_19 -> V_86 ;
if ( ! V_86 -> V_65 )
return NULL ;
return V_86 -> V_16 ;
}
static inline int F_58 ( struct V_1 * V_19 )
{
struct V_85 * V_86 = & V_19 -> V_86 ;
F_20 ( V_86 -> V_65 ) ;
V_86 -> V_16 = F_54 ( V_86 -> V_16 ) ;
return -- V_86 -> V_65 ;
}
static inline void F_59 ( struct V_1 * V_19 )
{
struct V_85 * V_86 = & V_19 -> V_86 ;
union V_79 * V_69 = F_39 ( V_86 -> V_26 , V_86 -> V_25 ) ;
F_20 ( V_86 -> V_21 == V_92 ) ;
if ( ( F_46 ( & V_69 -> V_71 ) & V_90 ) == V_86 -> V_17 ) {
V_86 -> V_25 = ( V_86 -> V_25 + 1 ) & ( V_82 - 1 ) ;
if ( ! V_86 -> V_25 )
V_86 -> V_17 ^= V_90 ;
V_86 -> V_65 ++ ;
V_69 = F_54 ( V_69 ) ;
}
F_45 ( V_69 ) ;
}
static inline void F_60 ( struct V_1 * V_19 , T_3 V_93 )
{
struct V_85 * V_86 = & V_19 -> V_86 ;
F_20 ( V_86 -> V_55 == V_94 ) ;
V_86 -> V_5 = ( V_86 -> V_5 + V_93 ) & ( V_82 - 1 ) ;
F_4 ( V_19 , V_89 , V_86 -> V_5 ) ;
}
static inline void F_61 ( struct V_1 * V_19 )
{
struct V_85 * V_86 = & V_19 -> V_86 ;
F_20 ( V_86 -> V_55 == V_94 ) ;
V_86 -> V_5 = F_53 ( V_86 -> V_16 ) ;
F_4 ( V_19 , V_89 , V_86 -> V_5 ) ;
}
static inline void F_62 ( struct V_1 * V_19 , T_3 V_32 )
{
F_4 ( V_19 , V_91 , V_32 ) ;
}
static inline int F_63 ( struct V_1 * V_19 )
{
struct V_95 * V_96 = & V_19 -> V_96 ;
V_96 -> V_97 = V_19 -> V_4 . V_7 + V_98 ;
V_96 -> V_99 = V_19 -> V_4 . V_7 + V_100 ;
V_96 -> V_101 = ( F_46 ( & V_96 -> V_97 -> V_43 ) & V_102 )
? 0 : 1 ;
V_96 -> V_17 = V_96 -> V_101 ? V_102 : 0 ;
#ifdef F_17
V_96 -> V_103 = V_104 ;
#endif
return 0 ;
}
static inline void F_64 ( struct V_1 * V_19 )
{
#ifdef F_17
struct V_95 * V_96 = & V_19 -> V_96 ;
F_20 ( V_96 -> V_103 == V_104 ) ;
if ( V_96 -> V_103 != V_104 )
F_21 ( L_6 ) ;
#endif
}
static inline union V_105 * F_65 ( struct V_1 * V_19 )
{
struct V_95 * V_96 = & V_19 -> V_96 ;
F_20 ( V_96 -> V_103 == V_104 ) ;
#ifdef F_17
V_96 -> V_103 = V_106 ;
#endif
F_23 ( V_96 -> V_97 ) ;
return V_96 -> V_97 ;
}
static inline void F_66 ( struct V_1 * V_19 , T_3 V_40 )
{
struct V_95 * V_96 = & V_19 -> V_96 ;
union V_107 * V_99 = V_96 -> V_99 + V_96 -> V_101 ;
F_20 ( V_96 -> V_103 == V_106 ) ;
F_27 () ;
V_96 -> V_97 -> V_43 = V_40 | V_96 -> V_17 ;
F_28 ( V_96 -> V_97 ) ;
F_45 ( V_99 ) ;
#ifdef F_17
V_96 -> V_103 = V_108 ;
#endif
}
static inline union V_107 * V_107 ( struct V_1 * V_19 )
{
struct V_95 * V_96 = & V_19 -> V_96 ;
union V_107 * V_99 = V_96 -> V_99 + V_96 -> V_101 ;
F_20 ( V_96 -> V_103 == V_108 ) ;
if ( ! F_46 ( & V_99 -> V_71 ) ) {
F_45 ( V_99 ) ;
return NULL ;
}
V_96 -> V_101 ^= 1 ;
V_96 -> V_17 ^= V_102 ;
#ifdef F_17
V_96 -> V_103 = V_104 ;
#endif
return V_99 ;
}
static inline int F_67 ( struct V_1 * V_19 ,
union V_107 * * V_109 )
{
int V_110 = V_111 ;
do {
* V_109 = V_107 ( V_19 ) ;
if ( * V_109 )
break;
F_68 ( 1 ) ;
} while ( -- V_110 );
return V_110 ;
}
static inline void F_69 ( struct V_112 * V_113 , T_1 V_114 )
{
F_70 ( V_114 , & V_113 -> V_115 ) ;
}
static inline void F_71 ( struct V_112 * V_113 , T_1 V_114 )
{
F_72 ( V_114 , & V_113 -> V_115 ) ;
}
static inline int F_73 ( struct V_112 * V_113 , T_1 V_114 )
{
return V_113 -> V_115 & V_114 ;
}
static inline int F_74 ( struct V_112 * V_113 , T_1 V_114 )
{
return ! ( V_113 -> V_115 & V_114 ) ;
}
static inline struct V_116 * F_75 ( void )
{
return & F_76 ( V_117 ) ;
}
static inline void F_77 ( void )
{
F_78 ( V_117 ) ;
}
int F_79 ( void )
{
V_118 = F_80 ( L_7 , 0 , 1 ) ;
if ( ! V_118 )
return - V_119 ;
return 0 ;
}
int F_81 ( T_1 V_120 )
{
V_121 = V_120 ;
V_122 = F_82 ( V_121 * 2 * sizeof( struct V_112 * ) ) ;
if ( ! V_122 )
return - V_119 ;
F_83 ( L_8 ,
V_122 , V_121 * 2 ) ;
return 0 ;
}
static struct V_112 * F_84 ( T_1 V_74 )
{
struct V_112 * V_113 ;
#ifdef F_17
if ( F_85 ( V_74 >= V_121 * 2 ) )
return NULL ;
#endif
V_113 = V_122 [ V_74 ] ;
F_20 ( ! V_113 || V_74 == V_113 -> V_74 ) ;
return V_113 ;
}
static struct V_112 * F_86 ( T_1 V_38 )
{
return F_84 ( V_38 * 2 ) ;
}
static struct V_112 * F_87 ( T_1 V_123 )
{
#if V_124 == 64
return F_84 ( V_123 ) ;
#else
return (struct V_112 * ) V_123 ;
#endif
}
static T_1 F_88 ( struct V_112 * V_113 )
{
#if V_124 == 64
return V_113 -> V_74 ;
#else
return ( T_1 ) V_113 ;
#endif
}
static T_5 F_89 ( int V_125 , void * V_126 )
{
struct V_116 * V_2 = V_126 ;
T_1 V_127 = V_128 | V_2 -> V_129 ;
T_1 V_130 = F_1 ( & V_2 -> V_2 , V_131 ) & V_2 -> V_129 ;
if ( F_90 ( ! V_130 ) )
return V_132 ;
if ( V_130 & V_133 )
F_91 ( V_2 , V_134 ) ;
V_127 |= F_92 ( V_2 , V_130 ) ;
F_4 ( & V_2 -> V_2 , V_131 , V_127 ) ;
return V_135 ;
}
static int F_93 ( struct V_1 * V_2 )
{
const union V_79 * V_136 ;
V_137:
V_136 = F_57 ( V_2 ) ;
if ( ! V_136 ) {
T_6 V_138 , V_139 = V_140 ;
do {
V_138 = V_140 ;
} while ( ( V_139 + 10000 ) > V_138 );
V_136 = F_57 ( V_2 ) ;
if ( ! V_136 )
return 0 ;
}
if ( ( V_136 -> V_71 & V_141 ) != V_142 ) {
F_94 ( L_9 , V_136 -> V_71 ) ;
return - 1 ;
}
F_58 ( V_2 ) ;
F_60 ( V_2 , 1 ) ;
goto V_137;
}
static int F_95 ( struct V_116 * V_19 ,
const struct V_49 * V_143 ,
const struct V_144 * V_145 )
{
struct V_1 * V_2 ;
int V_146 ;
T_1 V_147 ;
V_2 = & V_19 -> V_2 ;
#ifdef F_44
V_19 -> V_148 = ( ( V_149 >= V_150 ) ? 1 : 0 ) ;
#else
V_19 -> V_148 = 0 ;
#endif
V_2 -> V_4 . V_7 = V_143 -> V_151 [ V_152 ] ;
V_2 -> V_4 . V_5 = V_143 -> V_151 [ V_153 ] ;
if ( F_15 ( V_2 , V_42 ,
V_19 -> V_148 ? 3 : 0 , 1 ) ) {
F_96 ( V_143 -> V_154 , L_10 ) ;
goto V_155;
}
if ( F_38 ( V_2 , V_143 , V_156 , V_70 ,
V_68 , V_157 ) ) {
F_96 ( V_143 -> V_154 , L_11 ) ;
goto V_158;
}
if ( F_55 ( V_2 , V_92 , V_94 ) ) {
F_96 ( V_143 -> V_154 , L_12 ) ;
goto V_159;
}
if ( F_63 ( V_2 ) ) {
F_96 ( V_143 -> V_154 , L_13 ) ;
goto V_160;
}
F_51 ( V_2 , V_161 ) ;
F_62 ( V_2 , V_162 ) ;
F_4 ( V_2 , V_163 , V_164 ) ;
V_19 -> V_145 = F_97 ( 2 * sizeof( * V_145 ) , V_165 ) ;
if ( ! V_19 -> V_145 )
goto V_166;
F_98 ( & V_19 -> V_145 [ 1 ] ) ;
if ( V_145 )
V_19 -> V_145 [ 0 ] = * V_145 ;
else
F_99 ( & V_19 -> V_145 [ 0 ] ) ;
F_100 ( & V_19 -> V_167 ) ;
F_101 ( & V_19 -> V_168 ) ;
F_102 ( & V_19 -> V_169 , V_170 ) ;
F_102 ( & V_19 -> V_171 , V_172 ) ;
V_19 -> V_173 = 0 ;
V_19 -> V_77 = V_174 | V_175 |
V_176 | V_177 |
F_103 ( 0xab ) | V_178 ;
V_147 = 0xffffffff ;
F_4 ( V_2 , V_179 , V_147 ) ;
V_19 -> V_129 = 0 ;
F_4 ( V_2 , V_180 , 0 ) ;
F_4 ( V_2 , V_131 , 0xffffffff ) ;
snprintf ( V_19 -> V_181 , V_182 , V_183 , V_143 -> V_184 ) ;
if ( F_104 ( V_143 -> V_125 , F_89 , 0 , V_19 -> V_181 , V_19 ) ) {
F_96 ( V_143 -> V_154 , L_14 ) ;
goto V_185;
}
if ( V_143 -> V_184 != - 1 && F_105 ( V_143 -> V_125 ) &&
F_106 ( V_143 -> V_125 , F_107 ( V_143 -> V_184 ) ) ) {
F_96 ( V_143 -> V_154 , L_15 ) ;
goto V_186;
}
V_147 &= ~ V_187 ;
F_4 ( V_2 , V_179 , V_147 ) ;
V_146 = F_33 ( V_2 ) ;
if ( V_146 ) {
F_96 ( V_143 -> V_154 , L_16 ) ;
goto V_188;
}
V_147 &= ~ ( V_133 | V_189 ) ;
F_4 ( V_2 , V_179 , V_147 ) ;
if ( F_41 ( V_2 ) ) {
F_96 ( V_143 -> V_154 , L_17 ) ;
F_48 ( V_2 , 0xffff ) ;
}
if ( F_57 ( V_2 ) && F_93 ( V_2 ) ) {
const union V_79 * V_10 = F_57 ( V_2 ) ;
F_96 ( V_143 -> V_154 , L_18 ,
V_10 -> V_71 , V_10 -> V_190 . V_191 , F_108 ( & V_10 -> V_190 . V_192 ) ) ;
goto V_193;
}
V_19 -> V_50 = V_143 ;
F_4 ( V_2 , V_179 , 0 ) ;
F_4 ( V_2 , V_194 , 0 ) ;
F_49 ( V_2 , V_19 -> V_77 ) ;
return 0 ;
V_193:
V_188:
V_186:
F_109 ( V_143 -> V_125 , V_19 ) ;
V_185:
F_110 ( V_19 -> V_145 ) ;
V_166:
F_64 ( V_2 ) ;
V_160:
F_56 ( V_2 ) ;
V_159:
F_40 ( V_2 ) ;
V_158:
F_19 ( V_2 ) ;
V_155:
return - V_195 ;
}
struct V_116 * F_111 ( const struct V_49 * V_143 ,
const struct V_144 * V_145 )
{
struct V_116 * V_19 ;
int V_196 ;
V_19 = & F_112 ( V_117 , V_143 -> V_184 ) ;
V_196 = F_95 ( V_19 , V_143 , V_145 ) ;
if ( V_196 )
return NULL ;
F_113 ( & V_197 ) ;
F_114 ( V_143 -> V_184 , & V_198 ) ;
V_199 [ V_143 -> V_184 ] = V_143 -> V_200 ;
V_201 [ V_143 -> V_184 ] = V_19 ;
F_115 ( & V_197 ) ;
return V_19 ;
}
static void F_116 ( struct V_116 * V_202 )
{
const struct V_49 * V_203 ;
F_49 ( & V_202 -> V_2 , 0 ) ;
F_30 ( & V_202 -> V_2 ) ;
F_30 ( & V_202 -> V_2 ) ;
V_203 = V_202 -> V_50 ;
F_109 ( V_203 -> V_125 , V_202 ) ;
F_110 ( V_202 -> V_145 ) ;
F_64 ( & V_202 -> V_2 ) ;
F_56 ( & V_202 -> V_2 ) ;
F_40 ( & V_202 -> V_2 ) ;
F_19 ( & V_202 -> V_2 ) ;
V_202 -> V_50 = NULL ;
}
const struct V_49 * F_117 ( void )
{
struct V_116 * V_202 = F_75 () ;
const struct V_49 * V_203 ;
int V_184 ;
V_203 = V_202 -> V_50 ;
V_184 = V_203 -> V_184 ;
F_116 ( V_202 ) ;
F_113 ( & V_197 ) ;
F_118 ( V_184 , & V_198 ) ;
F_115 ( & V_197 ) ;
F_77 () ;
return V_203 ;
}
static inline void F_119 ( struct V_116 * V_2 , struct V_112 * V_113 ,
const union V_79 * V_136 , T_3 V_71 )
{
switch ( V_71 ) {
case V_204 :
F_20 ( F_73 ( V_113 , V_205 ) ) ;
F_71 ( V_113 , V_205 ) ;
break;
case V_206 :
F_20 ( V_113 -> V_103 == V_207 ||
V_113 -> V_103 == V_208 ) ;
F_20 ( F_73 ( V_113 , V_209 ) ) ;
F_71 ( V_113 , V_209 ) ;
if ( V_136 -> V_113 . V_210 & V_211 )
F_69 ( V_113 , V_212 ) ;
if ( V_136 -> V_113 . V_210 & V_213 )
F_69 ( V_113 , V_205 ) ;
V_113 -> V_103 = V_214 ;
break;
case V_215 :
F_20 ( V_113 -> V_103 == V_208 ) ;
F_20 ( F_74 ( V_113 , V_209 ) ) ;
V_113 -> V_103 = V_207 ;
}
}
static void V_170 ( struct V_216 * V_217 )
{
struct V_116 * V_2 = F_120 ( V_217 , struct V_116 ,
V_169 ) ;
struct V_144 V_99 , V_143 ;
union V_107 * V_109 ;
struct V_218 * V_219 ;
F_113 ( & V_2 -> V_168 ) ;
F_65 ( & V_2 -> V_2 ) ;
F_66 ( & V_2 -> V_2 , V_220 ) ;
if ( ! F_67 ( & V_2 -> V_2 , & V_109 ) ) {
F_115 ( & V_2 -> V_168 ) ;
F_121 ( V_2 -> V_50 -> V_154 , L_19 ) ;
return;
}
F_122 ( & V_99 , (struct V_144 * ) & V_109 -> V_221 . V_103 ,
& V_2 -> V_145 [ 0 ] ) ;
F_123 ( & V_143 , & V_99 , & V_2 -> V_145 [ 1 ] ) ;
F_124 ( & V_2 -> V_145 [ 1 ] , & V_99 ) ;
F_125 (cgr, &p->cgr_cbs, node)
if ( V_219 -> V_222 && F_126 ( & V_143 , V_219 -> V_223 ) )
V_219 -> V_222 ( V_2 , V_219 , F_126 ( & V_99 , V_219 -> V_223 ) ) ;
F_115 ( & V_2 -> V_168 ) ;
}
static void V_172 ( struct V_216 * V_217 )
{
struct V_116 * V_2 = F_120 ( V_217 , struct V_116 ,
V_171 ) ;
const union V_79 * V_136 ;
struct V_112 * V_113 ;
T_3 V_71 , V_93 = 0 ;
F_127 () ;
while ( 1 ) {
F_59 ( & V_2 -> V_2 ) ;
V_136 = F_57 ( & V_2 -> V_2 ) ;
if ( ! V_136 )
break;
V_71 = V_136 -> V_71 & V_141 ;
if ( V_71 & 0x20 ) {
switch ( V_71 ) {
case V_142 :
break;
case V_206 :
case V_204 :
V_113 = F_86 ( F_128 ( & V_136 -> V_113 ) ) ;
if ( F_85 ( ! V_113 ) )
break;
F_119 ( V_2 , V_113 , V_136 , V_71 ) ;
if ( V_113 -> V_222 . V_210 )
V_113 -> V_222 . V_210 ( V_2 , V_113 , V_136 ) ;
break;
case V_215 :
V_113 = F_87 ( F_2 ( V_136 -> V_113 . V_224 ) ) ;
F_119 ( V_2 , V_113 , V_136 , V_71 ) ;
if ( V_113 -> V_222 . V_210 )
V_113 -> V_222 . V_210 ( V_2 , V_113 , V_136 ) ;
break;
case V_225 :
F_129 ( L_20 ) ;
break;
default:
F_21 ( L_21 , V_71 ) ;
}
} else {
V_113 = F_87 ( F_2 ( V_136 -> V_190 . V_123 ) ) ;
V_113 -> V_222 . V_190 ( V_2 , V_113 , V_136 ) ;
}
V_93 ++ ;
F_58 ( & V_2 -> V_2 ) ;
}
F_60 ( & V_2 -> V_2 , V_93 ) ;
F_130 () ;
}
static T_1 F_92 ( struct V_116 * V_2 , T_1 V_130 )
{
if ( V_130 & V_226 ) {
F_131 ( F_132 () , V_118 ,
& V_2 -> V_169 ) ;
}
if ( V_130 & V_227 ) {
F_30 ( & V_2 -> V_2 ) ;
F_31 ( & V_2 -> V_2 , 0 ) ;
F_133 ( & V_228 ) ;
}
if ( V_130 & V_189 ) {
F_131 ( F_132 () , V_118 ,
& V_2 -> V_171 ) ;
}
return V_130 ;
}
static T_7 void F_134 ( struct V_116 * V_2 , struct V_112 * V_113 )
{
V_2 -> V_229 = NULL ;
F_71 ( V_113 , V_230 ) ;
F_133 ( & V_228 ) ;
}
static inline unsigned int F_91 ( struct V_116 * V_2 ,
unsigned int V_231 )
{
const struct V_44 * V_72 ;
struct V_112 * V_113 ;
enum V_232 V_69 ;
unsigned int V_233 = 0 ;
do {
F_43 ( & V_2 -> V_2 ) ;
V_72 = F_41 ( & V_2 -> V_2 ) ;
if ( ! V_72 )
break;
if ( V_72 -> V_234 & V_235 ) {
V_113 = V_2 -> V_229 ;
if ( V_72 -> V_234 & V_236 )
F_71 ( V_113 , V_212 ) ;
V_69 = V_113 -> V_222 . V_58 ( V_2 , V_113 , V_72 ) ;
if ( V_69 == V_237 )
break;
if ( V_72 -> V_234 & V_238 )
F_134 ( V_2 , V_113 ) ;
} else {
V_113 = F_87 ( F_2 ( V_72 -> V_224 ) ) ;
V_69 = V_113 -> V_222 . V_58 ( V_2 , V_113 , V_72 ) ;
if ( V_69 == V_237 )
break;
}
F_20 ( ( V_72 -> V_234 & V_239 ) ||
( V_69 != V_240 ) ) ;
if ( V_69 != V_241 )
F_47 ( & V_2 -> V_2 , V_72 ,
V_69 == V_240 ) ;
F_42 ( & V_2 -> V_2 ) ;
} while ( ++ V_233 < V_231 && V_69 != V_242 );
return V_233 ;
}
void F_135 ( struct V_116 * V_2 , T_1 V_173 )
{
unsigned long V_243 ;
F_136 ( V_243 ) ;
F_70 ( V_173 & V_244 , & V_2 -> V_129 ) ;
F_4 ( & V_2 -> V_2 , V_180 , V_2 -> V_129 ) ;
F_137 ( V_243 ) ;
}
void F_138 ( struct V_116 * V_2 , T_1 V_173 )
{
unsigned long V_243 ;
T_1 V_245 ;
F_136 ( V_243 ) ;
V_173 &= V_244 ;
F_72 ( V_173 , & V_2 -> V_129 ) ;
F_4 ( & V_2 -> V_2 , V_180 , V_2 -> V_129 ) ;
V_245 = F_1 ( & V_2 -> V_2 , V_180 ) ;
F_4 ( & V_2 -> V_2 , V_131 , ~ V_245 ) ;
F_137 ( V_243 ) ;
}
const T_8 * F_139 ( void )
{
return & V_198 ;
}
T_9 F_140 ( int V_184 )
{
if ( V_184 < 0 ) {
struct V_116 * V_19 = F_75 () ;
V_184 = V_19 -> V_50 -> V_184 ;
F_77 () ;
}
F_85 ( ! F_141 ( V_184 , & V_198 ) ) ;
return V_199 [ V_184 ] ;
}
struct V_116 * F_142 ( int V_184 )
{
return V_201 [ V_184 ] ;
}
int F_143 ( struct V_116 * V_2 , unsigned int V_233 )
{
return F_91 ( V_2 , V_233 ) ;
}
void F_144 ( struct V_116 * V_2 , T_1 V_246 )
{
unsigned long V_243 ;
F_136 ( V_243 ) ;
V_246 &= V_2 -> V_50 -> V_246 ;
V_2 -> V_77 |= V_246 ;
F_49 ( & V_2 -> V_2 , V_2 -> V_77 ) ;
F_137 ( V_243 ) ;
}
static const char * F_145 ( T_3 V_247 )
{
switch ( V_247 ) {
case V_248 :
return L_22 ;
case V_249 :
return L_23 ;
case V_250 :
return L_24 ;
case V_251 :
return L_25 ;
case V_252 :
return L_26 ;
case V_253 :
return L_27 ;
case V_254 :
return L_28 ;
}
return L_29 ;
}
int F_146 ( T_1 V_38 , T_1 V_115 , struct V_112 * V_113 )
{
if ( V_115 & V_255 ) {
int V_146 = F_147 ( & V_38 ) ;
if ( V_146 )
return V_146 ;
}
V_113 -> V_38 = V_38 ;
V_113 -> V_115 = V_115 ;
V_113 -> V_103 = V_256 ;
V_113 -> V_257 = 0 ;
if ( V_38 == 0 || V_38 >= V_121 ) {
F_148 ( 1 , L_30 , V_38 ) ;
return - V_258 ;
}
V_113 -> V_74 = V_38 * 2 ;
if ( V_115 & V_259 )
V_113 -> V_74 ++ ;
F_85 ( V_122 [ V_113 -> V_74 ] ) ;
V_122 [ V_113 -> V_74 ] = V_113 ;
return 0 ;
}
void F_149 ( struct V_112 * V_113 )
{
switch ( V_113 -> V_103 ) {
case V_207 :
case V_256 :
if ( F_73 ( V_113 , V_255 ) )
F_150 ( V_113 -> V_38 ) ;
F_20 ( V_122 [ V_113 -> V_74 ] ) ;
V_122 [ V_113 -> V_74 ] = NULL ;
return;
default:
break;
}
F_20 ( NULL == L_31 ) ;
}
T_1 F_151 ( struct V_112 * V_113 )
{
return V_113 -> V_38 ;
}
int F_152 ( struct V_112 * V_113 , T_1 V_115 , struct V_260 * V_261 )
{
union V_105 * V_262 ;
union V_107 * V_109 ;
struct V_116 * V_2 ;
T_3 V_69 , V_40 ;
int V_146 = 0 ;
V_40 = ( V_115 & V_263 )
? V_264 : V_265 ;
if ( V_113 -> V_103 != V_256 &&
V_113 -> V_103 != V_207 )
return - V_258 ;
#ifdef F_17
if ( F_73 ( V_113 , V_259 ) )
return - V_258 ;
#endif
if ( V_261 && ( F_153 ( V_261 -> V_266 ) & V_267 ) ) {
if ( F_153 ( V_261 -> V_266 ) & V_268 )
return - V_258 ;
}
V_2 = F_75 () ;
if ( F_73 ( V_113 , V_209 ) ||
( V_113 -> V_103 != V_256 &&
V_113 -> V_103 != V_207 ) ) {
V_146 = - V_269 ;
goto V_270;
}
V_262 = F_65 ( & V_2 -> V_2 ) ;
if ( V_261 )
V_262 -> V_271 = * V_261 ;
F_154 ( & V_262 -> V_113 , V_113 -> V_38 ) ;
V_262 -> V_271 . V_272 = 0 ;
if ( F_74 ( V_113 , V_273 ) ) {
T_10 V_274 ;
V_262 -> V_271 . V_266 |= F_155 ( V_275 ) ;
V_262 -> V_271 . V_276 . V_224 = F_6 ( F_88 ( V_113 ) ) ;
if ( ! ( F_153 ( V_262 -> V_271 . V_266 ) &
V_277 ) ) {
V_262 -> V_271 . V_266 |=
F_155 ( V_277 ) ;
memset ( & V_262 -> V_271 . V_276 . V_278 , 0 ,
sizeof( V_262 -> V_271 . V_276 . V_278 ) ) ;
} else {
struct V_116 * V_2 = V_279 ;
V_274 = F_156 ( V_2 -> V_50 -> V_154 , V_113 ,
sizeof( * V_113 ) , V_280 ) ;
if ( F_157 ( V_2 -> V_50 -> V_154 , V_274 ) ) {
F_96 ( V_2 -> V_50 -> V_154 , L_32 ) ;
V_146 = - V_195 ;
goto V_270;
}
F_158 ( & V_262 -> V_271 . V_276 , V_274 ) ;
}
}
if ( V_115 & V_281 ) {
int V_282 = 0 ;
if ( ! ( F_153 ( V_262 -> V_271 . V_266 ) &
V_283 ) ) {
V_262 -> V_271 . V_266 |=
F_155 ( V_283 ) ;
V_282 = 4 ;
}
F_159 ( & V_262 -> V_271 . V_276 , V_2 -> V_50 -> V_200 , V_282 ) ;
}
F_66 ( & V_2 -> V_2 , V_40 ) ;
if ( ! F_67 ( & V_2 -> V_2 , & V_109 ) ) {
F_96 ( V_2 -> V_50 -> V_154 , L_33 ) ;
V_146 = - V_284 ;
goto V_270;
}
F_20 ( ( V_109 -> V_71 & V_285 ) == V_40 ) ;
V_69 = V_109 -> V_247 ;
if ( V_69 != V_249 ) {
V_146 = - V_195 ;
goto V_270;
}
if ( V_261 ) {
if ( F_153 ( V_261 -> V_266 ) & V_286 ) {
if ( F_153 ( V_261 -> V_276 . V_287 ) & V_288 )
F_69 ( V_113 , V_289 ) ;
else
F_71 ( V_113 , V_289 ) ;
}
if ( F_153 ( V_261 -> V_266 ) & V_290 )
V_113 -> V_257 = V_261 -> V_276 . V_291 ;
}
V_113 -> V_103 = ( V_115 & V_263 ) ?
V_208 : V_207 ;
V_270:
F_77 () ;
return V_146 ;
}
int F_160 ( struct V_112 * V_113 )
{
union V_105 * V_262 ;
union V_107 * V_109 ;
struct V_116 * V_2 ;
int V_146 = 0 ;
if ( V_113 -> V_103 != V_207 )
return - V_258 ;
#ifdef F_17
if ( F_73 ( V_113 , V_259 ) )
return - V_258 ;
#endif
V_2 = F_75 () ;
if ( F_73 ( V_113 , V_209 ) ||
V_113 -> V_103 != V_207 ) {
V_146 = - V_269 ;
goto V_270;
}
V_262 = F_65 ( & V_2 -> V_2 ) ;
F_154 ( & V_262 -> V_113 , V_113 -> V_38 ) ;
F_66 ( & V_2 -> V_2 , V_292 ) ;
if ( ! F_67 ( & V_2 -> V_2 , & V_109 ) ) {
F_96 ( V_2 -> V_50 -> V_154 , L_34 ) ;
V_146 = - V_284 ;
goto V_270;
}
F_20 ( ( V_109 -> V_71 & V_285 ) == V_293 ) ;
if ( V_109 -> V_247 != V_249 ) {
V_146 = - V_195 ;
goto V_270;
}
V_113 -> V_103 = V_208 ;
V_270:
F_77 () ;
return V_146 ;
}
int F_161 ( struct V_112 * V_113 , T_1 * V_115 )
{
union V_105 * V_262 ;
union V_107 * V_109 ;
struct V_116 * V_2 ;
int V_146 ;
T_3 V_69 ;
if ( V_113 -> V_103 != V_207 &&
V_113 -> V_103 != V_208 )
return - V_258 ;
#ifdef F_17
if ( F_73 ( V_113 , V_259 ) )
return - V_258 ;
#endif
V_2 = F_75 () ;
if ( F_73 ( V_113 , V_209 ) ||
V_113 -> V_103 == V_214 ||
V_113 -> V_103 == V_256 ) {
V_146 = - V_269 ;
goto V_270;
}
V_262 = F_65 ( & V_2 -> V_2 ) ;
F_154 ( & V_262 -> V_113 , V_113 -> V_38 ) ;
F_66 ( & V_2 -> V_2 , V_294 ) ;
if ( ! F_67 ( & V_2 -> V_2 , & V_109 ) ) {
F_121 ( V_2 -> V_50 -> V_154 , L_35 ) ;
V_146 = - V_284 ;
goto V_270;
}
F_20 ( ( V_109 -> V_71 & V_285 ) == V_295 ) ;
V_69 = V_109 -> V_247 ;
if ( V_69 == V_249 ) {
V_146 = 0 ;
if ( V_109 -> V_296 . V_210 & V_297 )
F_69 ( V_113 , V_212 ) ;
if ( V_109 -> V_296 . V_210 & V_298 )
F_69 ( V_113 , V_205 ) ;
if ( V_115 )
* V_115 = V_113 -> V_115 ;
V_113 -> V_103 = V_214 ;
if ( V_113 -> V_222 . V_210 ) {
union V_79 V_136 ;
V_136 . V_71 = V_142 ;
V_136 . V_113 . V_210 = V_109 -> V_296 . V_210 ;
F_154 ( & V_136 . V_113 , V_113 -> V_38 ) ;
V_136 . V_113 . V_224 = F_6 ( F_88 ( V_113 ) ) ;
V_113 -> V_222 . V_210 ( V_2 , V_113 , & V_136 ) ;
}
} else if ( V_69 == V_253 ) {
V_146 = 1 ;
F_69 ( V_113 , V_209 ) ;
} else {
V_146 = - V_195 ;
}
V_270:
F_77 () ;
return V_146 ;
}
int F_162 ( struct V_112 * V_113 )
{
union V_105 * V_262 ;
union V_107 * V_109 ;
struct V_116 * V_2 ;
int V_146 = 0 ;
if ( V_113 -> V_103 != V_214 )
return - V_258 ;
#ifdef F_17
if ( F_73 ( V_113 , V_259 ) )
return - V_258 ;
#endif
V_2 = F_75 () ;
if ( F_73 ( V_113 , V_299 ) ||
V_113 -> V_103 != V_214 ) {
V_146 = - V_269 ;
goto V_270;
}
V_262 = F_65 ( & V_2 -> V_2 ) ;
F_154 ( & V_262 -> V_113 , V_113 -> V_38 ) ;
F_66 ( & V_2 -> V_2 , V_300 ) ;
if ( ! F_67 ( & V_2 -> V_2 , & V_109 ) ) {
V_146 = - V_284 ;
goto V_270;
}
F_20 ( ( V_109 -> V_71 & V_285 ) == V_301 ) ;
if ( V_109 -> V_247 != V_249 ) {
V_146 = - V_195 ;
goto V_270;
}
V_113 -> V_103 = V_256 ;
V_270:
F_77 () ;
return V_146 ;
}
int F_163 ( struct V_112 * V_113 , struct V_302 * V_276 )
{
union V_105 * V_262 ;
union V_107 * V_109 ;
struct V_116 * V_2 = F_75 () ;
int V_146 = 0 ;
V_262 = F_65 ( & V_2 -> V_2 ) ;
F_154 ( & V_262 -> V_113 , V_113 -> V_38 ) ;
F_66 ( & V_2 -> V_2 , V_303 ) ;
if ( ! F_67 ( & V_2 -> V_2 , & V_109 ) ) {
V_146 = - V_284 ;
goto V_270;
}
F_20 ( ( V_109 -> V_71 & V_285 ) == V_304 ) ;
if ( V_109 -> V_247 == V_249 )
* V_276 = V_109 -> V_305 . V_276 ;
else
V_146 = - V_195 ;
V_270:
F_77 () ;
return V_146 ;
}
static int F_164 ( struct V_112 * V_113 ,
struct V_306 * V_307 )
{
union V_105 * V_262 ;
union V_107 * V_109 ;
struct V_116 * V_2 = F_75 () ;
int V_146 = 0 ;
V_262 = F_65 ( & V_2 -> V_2 ) ;
F_154 ( & V_262 -> V_113 , V_113 -> V_38 ) ;
F_66 ( & V_2 -> V_2 , V_308 ) ;
if ( ! F_67 ( & V_2 -> V_2 , & V_109 ) ) {
V_146 = - V_284 ;
goto V_270;
}
F_20 ( ( V_109 -> V_71 & V_285 ) == V_309 ) ;
if ( V_109 -> V_247 == V_249 )
* V_307 = V_109 -> V_310 ;
else if ( V_109 -> V_247 == V_250 )
V_146 = - V_311 ;
else
V_146 = - V_195 ;
V_270:
F_77 () ;
return V_146 ;
}
static int F_165 ( struct V_218 * V_219 ,
struct V_312 * V_313 )
{
union V_105 * V_262 ;
union V_107 * V_109 ;
struct V_116 * V_2 = F_75 () ;
int V_146 = 0 ;
V_262 = F_65 ( & V_2 -> V_2 ) ;
V_262 -> V_219 . V_291 = V_219 -> V_223 ;
F_66 ( & V_2 -> V_2 , V_314 ) ;
if ( ! F_67 ( & V_2 -> V_2 , & V_109 ) ) {
V_146 = - V_284 ;
goto V_270;
}
F_20 ( ( V_109 -> V_71 & V_285 ) == V_314 ) ;
if ( V_109 -> V_247 == V_249 )
* V_313 = V_109 -> V_315 ;
else {
F_96 ( V_2 -> V_50 -> V_154 , L_36 ,
F_145 ( V_109 -> V_247 ) ) ;
V_146 = - V_195 ;
}
V_270:
F_77 () ;
return V_146 ;
}
int F_166 ( struct V_218 * V_219 , bool * V_247 )
{
struct V_312 V_316 ;
int V_196 ;
V_196 = F_165 ( V_219 , & V_316 ) ;
if ( V_196 )
return V_196 ;
* V_247 = ! ! V_316 . V_219 . V_317 ;
return 0 ;
}
static int F_167 ( struct V_116 * V_2 , struct V_112 * V_113 , T_1 V_78 )
{
unsigned long V_243 ;
int V_146 = - V_269 ;
F_136 ( V_243 ) ;
if ( V_2 -> V_229 )
goto V_270;
if ( F_73 ( V_113 , V_230 ) )
goto V_270;
F_69 ( V_113 , V_230 ) ;
V_2 -> V_229 = V_113 ;
F_50 ( & V_2 -> V_2 , V_78 ) ;
V_146 = 0 ;
V_270:
F_137 ( V_243 ) ;
return V_146 ;
}
static int F_168 ( struct V_116 * * V_2 , struct V_112 * V_113 , T_1 V_78 )
{
int V_146 ;
* V_2 = F_75 () ;
V_146 = F_167 ( * V_2 , V_113 , V_78 ) ;
F_77 () ;
return V_146 ;
}
static int F_169 ( struct V_116 * * V_2 , struct V_112 * V_113 ,
T_1 V_78 , T_1 V_115 )
{
int V_146 = 0 ;
if ( V_115 & V_318 )
V_146 = F_170 ( V_228 ,
! F_168 ( V_2 , V_113 , V_78 ) ) ;
else
F_171 ( V_228 , ! F_168 ( V_2 , V_113 , V_78 ) ) ;
return V_146 ;
}
int F_172 ( struct V_112 * V_113 , T_1 V_115 , T_1 V_78 )
{
struct V_116 * V_2 ;
int V_146 ;
if ( V_113 -> V_103 != V_207 &&
V_113 -> V_103 != V_214 )
return - V_258 ;
if ( V_78 & V_319 )
return - V_258 ;
if ( F_73 ( V_113 , V_230 ) )
return - V_269 ;
V_78 = ( V_78 & ~ V_319 ) | V_113 -> V_38 ;
if ( V_115 & V_320 )
V_146 = F_169 ( & V_2 , V_113 , V_78 , V_115 ) ;
else
V_146 = F_168 ( & V_2 , V_113 , V_78 ) ;
if ( V_146 )
return V_146 ;
if ( V_115 & V_321 ) {
if ( V_115 & V_318 )
F_170 ( V_228 ,
! F_73 ( V_113 , V_230 ) ) ;
else
F_171 ( V_228 ,
! F_73 ( V_113 , V_230 ) ) ;
}
return 0 ;
}
static void F_173 ( struct V_116 * V_2 , T_3 V_322 )
{
if ( V_322 )
F_29 ( & V_2 -> V_2 ) ;
else
F_30 ( & V_2 -> V_2 ) ;
}
int F_174 ( struct V_112 * V_113 , const struct V_323 * V_192 )
{
struct V_116 * V_2 ;
struct V_8 * V_324 ;
unsigned long V_243 ;
T_3 V_322 ;
V_2 = F_75 () ;
F_136 ( V_243 ) ;
if ( V_2 -> V_148 ) {
V_324 = F_24 ( & V_2 -> V_2 ) ;
} else {
V_322 = F_32 ( & V_2 -> V_2 ) ;
if ( V_322 < 2 )
F_173 ( V_2 , V_322 ) ;
V_324 = F_22 ( & V_2 -> V_2 ) ;
}
if ( F_90 ( ! V_324 ) )
goto V_270;
F_154 ( V_324 , V_113 -> V_38 ) ;
V_324 -> V_123 = F_6 ( F_88 ( V_113 ) ) ;
V_324 -> V_192 = * V_192 ;
F_26 ( & V_2 -> V_2 , V_325 ) ;
V_270:
F_137 ( V_243 ) ;
F_77 () ;
return 0 ;
}
static int F_175 ( struct V_218 * V_219 , T_1 V_115 ,
struct V_326 * V_261 )
{
union V_105 * V_262 ;
union V_107 * V_109 ;
struct V_116 * V_2 = F_75 () ;
T_3 V_71 = V_327 ;
int V_146 = 0 ;
V_262 = F_65 ( & V_2 -> V_2 ) ;
if ( V_261 )
V_262 -> V_328 = * V_261 ;
V_262 -> V_328 . V_291 = V_219 -> V_223 ;
if ( V_115 & V_329 )
V_71 = V_330 ;
F_66 ( & V_2 -> V_2 , V_71 ) ;
if ( ! F_67 ( & V_2 -> V_2 , & V_109 ) ) {
V_146 = - V_284 ;
goto V_270;
}
F_20 ( ( V_109 -> V_71 & V_285 ) == V_71 ) ;
if ( V_109 -> V_247 != V_249 )
V_146 = - V_195 ;
V_270:
F_77 () ;
return V_146 ;
}
static void F_176 ( struct V_331 * V_219 , int V_25 , T_1 V_6 )
{
if ( V_149 >= V_150 )
V_219 -> V_332 = F_155 ( V_25 |
V_333 ) ;
else
V_219 -> V_334 = F_6 ( V_6 | F_177 ( V_25 ) ) ;
}
static void F_178 ( struct V_331 * V_219 , int V_25 , T_1 V_6 )
{
if ( V_149 >= V_150 )
V_219 -> V_332 = F_155 ( V_25 ) ;
else
V_219 -> V_334 = F_6 ( V_6 & ~ F_177 ( V_25 ) ) ;
}
void F_179 ( void )
{
struct V_218 V_219 ;
int V_335 = 0 ;
for ( V_219 . V_223 = 0 ; V_219 . V_223 < V_336 ; V_219 . V_223 ++ ) {
if ( F_175 ( & V_219 , V_329 , NULL ) )
V_335 ++ ;
}
if ( V_335 )
F_94 ( L_37 ,
V_335 , ( V_335 > 1 ) ? L_38 : L_39 ) ;
}
int F_180 ( struct V_218 * V_219 , T_1 V_115 ,
struct V_326 * V_261 )
{
struct V_312 V_337 ;
int V_146 ;
struct V_116 * V_2 ;
if ( V_219 -> V_223 >= V_336 )
return - V_258 ;
F_127 () ;
V_2 = F_75 () ;
V_338 [ V_219 -> V_223 ] = F_132 () ;
F_130 () ;
V_219 -> V_339 = V_2 -> V_50 -> V_200 ;
F_113 ( & V_2 -> V_168 ) ;
if ( V_261 ) {
struct V_326 V_340 = * V_261 ;
V_146 = F_165 ( V_219 , & V_337 ) ;
if ( V_146 )
goto V_270;
F_176 ( & V_340 . V_219 , F_181 ( V_2 ) ,
F_2 ( V_337 . V_219 . V_334 ) ) ;
V_340 . V_266 |= F_155 ( V_341 ) ;
if ( V_115 & V_329 )
V_146 = F_175 ( V_219 , V_329 ,
& V_340 ) ;
else
V_146 = F_175 ( V_219 , 0 , & V_340 ) ;
if ( V_146 )
goto V_270;
}
F_182 ( & V_219 -> V_342 , & V_2 -> V_167 ) ;
V_146 = F_165 ( V_219 , & V_337 ) ;
if ( V_146 ) {
F_96 ( V_2 -> V_50 -> V_154 , L_40 ) ;
V_146 = 0 ;
goto V_270;
}
if ( V_219 -> V_222 && V_337 . V_219 . V_343 &&
F_126 ( & V_2 -> V_145 [ 1 ] , V_219 -> V_223 ) )
V_219 -> V_222 ( V_2 , V_219 , 1 ) ;
V_270:
F_115 ( & V_2 -> V_168 ) ;
F_77 () ;
return V_146 ;
}
int F_183 ( struct V_218 * V_219 )
{
unsigned long V_243 ;
struct V_312 V_337 ;
struct V_326 V_340 ;
int V_146 = 0 ;
struct V_218 * V_344 ;
struct V_116 * V_2 = F_75 () ;
if ( V_219 -> V_339 != V_2 -> V_50 -> V_200 ) {
F_96 ( V_2 -> V_50 -> V_154 , L_41 ) ;
F_184 ( V_2 -> V_50 -> V_154 , L_42 ,
V_219 -> V_339 , V_2 -> V_50 -> V_200 ) ;
V_146 = - V_258 ;
goto V_345;
}
memset ( & V_340 , 0 , sizeof( struct V_326 ) ) ;
F_185 ( & V_2 -> V_168 , V_243 ) ;
F_186 ( & V_219 -> V_342 ) ;
F_125 (i, &p->cgr_cbs, node)
if ( V_344 -> V_223 == V_219 -> V_223 && V_344 -> V_222 )
goto V_346;
V_146 = F_165 ( V_219 , & V_337 ) ;
if ( V_146 ) {
F_182 ( & V_219 -> V_342 , & V_2 -> V_167 ) ;
goto V_346;
}
V_340 . V_266 = F_155 ( V_341 ) ;
F_178 ( & V_340 . V_219 , F_181 ( V_2 ) ,
F_2 ( V_337 . V_219 . V_334 ) ) ;
V_146 = F_175 ( V_219 , 0 , & V_340 ) ;
if ( V_146 )
F_182 ( & V_219 -> V_342 , & V_2 -> V_167 ) ;
V_346:
F_187 ( & V_2 -> V_168 , V_243 ) ;
V_345:
F_77 () ;
return V_146 ;
}
static int F_188 ( void * V_2 )
{
struct V_347 * V_347 = (struct V_347 * ) V_2 ;
int V_146 ;
V_146 = F_183 ( V_347 -> V_219 ) ;
F_189 ( & V_347 -> V_348 ) ;
return V_146 ;
}
void F_190 ( struct V_218 * V_219 )
{
struct V_349 * V_350 ;
struct V_347 V_347 ;
F_127 () ;
if ( V_338 [ V_219 -> V_223 ] != F_132 () ) {
F_191 ( & V_347 . V_348 ) ;
V_347 . V_219 = V_219 ;
V_350 = F_192 ( F_188 , & V_347 ,
L_43 ) ;
if ( F_193 ( V_350 ) )
goto V_270;
F_194 ( V_350 , V_338 [ V_219 -> V_223 ] ) ;
F_195 ( V_350 ) ;
F_196 ( & V_347 . V_348 ) ;
F_130 () ;
return;
}
V_270:
F_183 ( V_219 ) ;
F_130 () ;
}
static int F_197 ( struct V_1 * V_2 , int V_351 )
{
const union V_79 * V_136 ;
int V_352 = 0 ;
F_59 ( V_2 ) ;
V_136 = F_57 ( V_2 ) ;
while ( V_136 ) {
if ( ( V_136 -> V_71 & V_141 ) == V_351 )
V_352 = 1 ;
F_58 ( V_2 ) ;
F_61 ( V_2 ) ;
F_59 ( V_2 ) ;
V_136 = F_57 ( V_2 ) ;
}
return V_352 ;
}
static int F_198 ( struct V_1 * V_2 , T_1 V_38 , int V_353 ,
bool V_354 )
{
const struct V_44 * V_58 ;
int V_352 = 0 ;
do {
F_43 ( V_2 ) ;
V_58 = F_41 ( V_2 ) ;
if ( ! V_58 )
F_199 () ;
} while ( V_354 && ! V_58 );
while ( V_58 ) {
if ( F_128 ( V_58 ) == V_38 && ( V_58 -> V_234 & V_353 ) )
V_352 = 1 ;
F_47 ( V_2 , V_58 , 0 ) ;
F_43 ( V_2 ) ;
F_42 ( V_2 ) ;
V_58 = F_41 ( V_2 ) ;
}
return V_352 ;
}
static int F_200 ( T_1 V_38 )
{
struct V_116 * V_2 ;
struct V_355 * V_154 ;
union V_105 * V_262 ;
union V_107 * V_109 ;
int V_356 , V_357 = 0 , V_146 = 0 ;
T_1 V_200 , V_282 , V_69 ;
T_3 V_103 ;
V_2 = F_75 () ;
V_154 = V_2 -> V_50 -> V_154 ;
V_262 = F_65 ( & V_2 -> V_2 ) ;
F_154 ( & V_262 -> V_113 , V_38 ) ;
F_66 ( & V_2 -> V_2 , V_308 ) ;
if ( ! F_67 ( & V_2 -> V_2 , & V_109 ) ) {
F_96 ( V_154 , L_44 ) ;
V_146 = - V_284 ;
goto V_270;
}
F_20 ( ( V_109 -> V_71 & V_285 ) == V_309 ) ;
V_103 = V_109 -> V_310 . V_103 & V_358 ;
if ( V_103 == V_359 )
goto V_270;
V_262 = F_65 ( & V_2 -> V_2 ) ;
F_154 ( & V_262 -> V_113 , V_38 ) ;
F_66 ( & V_2 -> V_2 , V_303 ) ;
if ( ! F_67 ( & V_2 -> V_2 , & V_109 ) ) {
F_96 ( V_154 , L_45 ) ;
V_146 = - V_284 ;
goto V_270;
}
F_20 ( ( V_109 -> V_71 & V_285 ) == V_304 ) ;
V_200 = F_201 ( & V_109 -> V_305 . V_276 ) ;
V_282 = F_202 ( & V_109 -> V_305 . V_276 ) ;
switch ( V_103 ) {
case V_360 :
case V_361 :
case V_362 :
case V_363 :
V_356 = 0 ;
V_262 = F_65 ( & V_2 -> V_2 ) ;
F_154 ( & V_262 -> V_113 , V_38 ) ;
F_66 ( & V_2 -> V_2 , V_294 ) ;
if ( ! F_67 ( & V_2 -> V_2 , & V_109 ) ) {
F_96 ( V_154 , L_44 ) ;
V_146 = - V_284 ;
goto V_270;
}
F_20 ( ( V_109 -> V_71 & V_285 ) ==
V_295 ) ;
V_69 = V_109 -> V_247 ;
if ( V_69 == V_253 ) {
int V_364 = 0 ;
T_9 V_365 = 0 ;
V_357 = 1 ;
if ( V_200 >= V_366 &&
V_200 < V_366 + 15 ) {
V_365 = ( V_200 -
V_366 + 1 ) << 4 | V_282 ;
} else if ( V_200 < V_366 ) {
V_365 = V_282 ;
} else {
F_96 ( V_154 , L_46 ,
V_38 , V_200 ) ;
V_146 = - V_269 ;
goto V_270;
}
if ( V_200 < V_366 )
F_49 ( & V_2 -> V_2 ,
V_367 |
V_178 ) ;
else
F_49 ( & V_2 -> V_2 ,
V_367 |
F_203
( V_200 ) ) ;
do {
F_204 ( & V_2 -> V_2 ) ;
V_364 = F_205 ( & V_2 -> V_2 , V_368 ) ;
F_199 () ;
} while ( ! V_364 );
}
if ( V_69 != V_249 &&
V_69 != V_253 ) {
F_96 ( V_154 , L_47 ,
V_38 , V_69 ) ;
V_146 = - V_195 ;
goto V_270;
}
if ( ! ( V_109 -> V_296 . V_210 & V_298 ) ) {
V_356 = 1 ;
}
if ( V_357 || V_109 -> V_296 . V_210 & V_297 ) {
do {
T_1 V_78 = V_38 | F_206 ( 3 ) ;
F_50 ( & V_2 -> V_2 , V_78 ) ;
} while ( F_207 ( & V_2 -> V_2 , V_38 , V_369 ) );
}
F_49 ( & V_2 -> V_2 , 0 ) ;
while ( ! V_356 ) {
V_356 = F_205 ( & V_2 -> V_2 , V_370 ) ;
F_199 () ;
}
V_262 = F_65 ( & V_2 -> V_2 ) ;
F_154 ( & V_262 -> V_113 , V_38 ) ;
F_66 ( & V_2 -> V_2 , V_300 ) ;
if ( ! F_67 ( & V_2 -> V_2 , & V_109 ) ) {
V_146 = - V_284 ;
goto V_270;
}
F_20 ( ( V_109 -> V_71 & V_285 ) ==
V_301 ) ;
if ( V_109 -> V_247 != V_249 ) {
F_96 ( V_154 , L_48 ,
V_38 , V_109 -> V_247 ) ;
V_146 = - V_195 ;
goto V_270;
}
break;
case V_371 :
V_262 = F_65 ( & V_2 -> V_2 ) ;
F_154 ( & V_262 -> V_113 , V_38 ) ;
F_66 ( & V_2 -> V_2 , V_300 ) ;
if ( ! F_67 ( & V_2 -> V_2 , & V_109 ) ) {
V_146 = - V_284 ;
goto V_270;
}
F_20 ( ( V_109 -> V_71 & V_285 ) ==
V_301 ) ;
if ( V_109 -> V_247 ) {
F_96 ( V_154 , L_49 ,
V_38 , V_109 -> V_247 ) ;
V_146 = - V_195 ;
goto V_270;
}
break;
case V_359 :
break;
default:
V_146 = - V_195 ;
}
V_270:
F_77 () ;
return V_146 ;
}
const struct V_49 * F_208 (
struct V_116 * V_19 )
{
return V_19 -> V_50 ;
}
static int F_209 ( struct V_372 * V_2 , T_1 * V_247 , T_1 V_373 )
{
unsigned long V_4 ;
V_4 = F_210 ( V_2 , V_373 ) ;
if ( ! V_4 )
return - V_119 ;
* V_247 = V_4 & ~ V_374 ;
return 0 ;
}
int F_211 ( T_1 * V_247 , T_1 V_272 )
{
return F_209 ( V_375 , V_247 , V_272 ) ;
}
int F_212 ( T_1 * V_247 , T_1 V_272 )
{
return F_209 ( V_376 , V_247 , V_272 ) ;
}
int F_213 ( T_1 * V_247 , T_1 V_272 )
{
return F_209 ( V_377 , V_247 , V_272 ) ;
}
int F_150 ( T_1 V_38 )
{
int V_146 = F_200 ( V_38 ) ;
if ( V_146 ) {
F_83 ( L_50 , V_38 ) ;
return V_146 ;
}
F_214 ( V_375 , V_38 | V_374 , 1 ) ;
return 0 ;
}
static int F_215 ( T_1 V_378 )
{
struct V_112 V_113 = {
. V_38 = V_379
} ;
int V_196 ;
do {
struct V_306 V_307 ;
V_196 = F_164 ( & V_113 , & V_307 ) ;
if ( V_196 == - V_311 )
return 0 ;
else if ( F_85 ( V_196 ) )
return V_196 ;
if ( ( V_307 . V_103 & V_358 ) != V_359 ) {
struct V_302 V_276 ;
V_196 = F_163 ( & V_113 , & V_276 ) ;
if ( F_85 ( V_196 ) )
return V_196 ;
if ( F_201 ( & V_276 ) == V_378 ) {
V_196 = F_200 ( V_113 . V_38 ) ;
if ( V_196 )
return V_196 ;
}
}
V_113 . V_38 ++ ;
} while ( 1 );
}
int F_216 ( T_1 V_378 )
{
int V_146 ;
V_146 = F_215 ( V_378 ) ;
if ( V_146 ) {
F_83 ( L_51 , V_378 ) ;
return V_146 ;
}
F_214 ( V_376 , V_378 | V_374 , 1 ) ;
return 0 ;
}
static int F_217 ( T_1 V_223 )
{
struct V_112 V_113 = {
. V_38 = V_379
} ;
int V_196 ;
do {
struct V_306 V_307 ;
V_196 = F_164 ( & V_113 , & V_307 ) ;
if ( V_196 == - V_311 )
return 0 ;
else if ( F_85 ( V_196 ) )
return V_196 ;
if ( ( V_307 . V_103 & V_358 ) != V_359 ) {
struct V_302 V_276 ;
V_196 = F_163 ( & V_113 , & V_276 ) ;
if ( F_85 ( V_196 ) )
return V_196 ;
if ( F_153 ( V_276 . V_287 ) & V_288 &&
V_276 . V_291 == V_223 ) {
F_94 ( L_52 ,
V_223 , V_113 . V_38 ) ;
return - V_195 ;
}
}
V_113 . V_38 ++ ;
} while ( 1 );
}
int F_218 ( T_1 V_223 )
{
int V_146 ;
V_146 = F_217 ( V_223 ) ;
if ( V_146 ) {
F_83 ( L_53 , V_223 ) ;
return V_146 ;
}
F_214 ( V_377 , V_223 | V_374 , 1 ) ;
return 0 ;
}
