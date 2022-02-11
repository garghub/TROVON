static inline bool F_1 ( const struct V_1 * V_2 )
{
int V_3 = V_2 -> V_3 ;
if ( F_2 ( F_3 ( V_2 , V_4 ) ) )
V_3 += sizeof( struct V_5 ) ;
return V_3 <= V_6 ;
}
static void F_4 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
int V_14 = F_6 ( V_12 -> V_15 ) ;
int V_16 = F_7 ( V_8 -> V_17 ) ;
unsigned long long V_18 ;
unsigned int V_19 ;
unsigned int V_20 = ( ( unsigned int ) V_8 -> V_21 ) |
( ( ( unsigned int ) V_8 -> V_22 ) << 14 ) ;
V_18 = V_23 |
F_8 ( V_16 ) |
F_9 ( V_8 -> V_17 ) |
F_10 ( ( (struct V_9 * ) V_8 -> V_24 ) -> V_25 ) |
F_11 ( V_8 -> V_26 ) |
F_12 ( V_8 -> V_27 ) |
F_13 ( V_28 ) |
F_14 ( V_8 -> V_29 >> 10 ) ;
V_19 = F_15 ( 0 ) |
V_30 |
F_16 ( V_8 -> V_22 ) ;
if ( F_6 ( V_12 -> V_15 ) ) {
struct V_31 * V_32 =
(struct V_31 * ) V_2 -> V_33 ;
F_17 ( V_32 , 0 ) ;
F_18 ( V_32 ) = F_19 ( F_20 ( V_34 ,
V_20 ) ) ;
V_32 -> V_35 = V_8 -> V_36 . V_37 ;
V_32 -> V_38 = V_8 -> V_39 . V_37 ;
V_32 -> V_40 = V_8 -> V_36 . V_41 . V_42 ;
V_32 -> V_43 = V_8 -> V_39 . V_41 . V_42 ;
V_32 -> V_18 = F_21 ( V_18 ) ;
V_32 -> V_44 = F_19 ( F_22 (
V_8 -> V_13 -> V_45 [ V_8 -> V_46 ] ,
V_8 -> V_24 ) ) ;
V_19 |= V_47 ;
V_32 -> V_19 = F_19 ( V_19 ) ;
F_23 ( 1 << V_48 | 1 << V_49 ,
L_1 ,
V_8 , & V_32 -> V_40 , F_24 ( V_32 -> V_35 ) ,
& V_32 -> V_43 , F_24 ( V_32 -> V_38 ) ,
V_8 -> V_21 , V_8 -> V_22 ) ;
} else {
struct V_50 * V_32 =
(struct V_50 * ) V_2 -> V_33 ;
T_1 V_51 = ( F_25 () & ~ 7UL ) - 1 ;
F_17 ( V_32 , 0 ) ;
F_18 ( V_32 ) = F_19 ( F_20 ( V_34 ,
V_20 ) ) ;
V_32 -> V_35 = V_8 -> V_36 . V_37 ;
V_32 -> V_38 = V_8 -> V_39 . V_37 ;
V_32 -> V_40 = V_8 -> V_36 . V_41 . V_42 ;
V_32 -> V_43 = V_8 -> V_39 . V_41 . V_42 ;
V_32 -> V_18 = F_21 ( V_18 ) ;
V_32 -> V_44 = F_21 ( F_26 (
F_22 (
V_8 -> V_13 -> V_45 [ V_8 -> V_46 ] ,
V_8 -> V_24 ) ) ) ;
V_32 -> V_52 = F_19 ( V_51 ) ;
V_19 |= V_53 ;
V_19 |= V_54 ;
V_32 -> V_19 = F_19 ( V_19 ) ;
F_23 ( 1 << V_48 | 1 << V_49 ,
L_2 ,
V_8 , & V_32 -> V_40 , F_24 ( V_32 -> V_35 ) ,
& V_32 -> V_43 , F_24 ( V_32 -> V_38 ) ,
V_8 -> V_21 , V_8 -> V_22 ) ;
}
F_27 ( V_2 , V_55 , V_8 -> V_46 ) ;
F_28 ( L_3 ,
( & V_8 -> V_36 ) , ( & V_8 -> V_39 ) , V_14 ? 4 : 5 , V_8 ,
V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_21 , V_8 -> V_22 ) ;
F_29 ( V_8 -> V_13 -> V_45 [ V_8 -> V_46 ] , V_2 , V_8 -> V_24 ) ;
}
static void F_30 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
int V_14 = F_6 ( V_12 -> V_15 ) ;
int V_16 = F_7 ( V_8 -> V_17 ) ;
unsigned long long V_18 ;
unsigned int V_19 ;
unsigned int V_20 = ( ( unsigned int ) V_8 -> V_21 ) |
( ( ( unsigned int ) V_8 -> V_22 ) << 14 ) ;
V_18 = V_23 |
F_8 ( V_16 ) |
F_9 ( V_8 -> V_17 ) |
F_10 ( ( (struct V_9 * ) V_8 -> V_24 ) -> V_25 ) |
F_11 ( V_8 -> V_26 ) |
F_12 ( V_8 -> V_27 ) |
F_13 ( V_28 ) |
F_14 ( V_8 -> V_29 >> 10 ) ;
V_19 = F_15 ( 0 ) |
V_30 |
V_58 |
F_16 ( V_8 -> V_22 ) ;
if ( V_14 ) {
struct V_59 * V_32 =
(struct V_59 * ) V_2 -> V_33 ;
F_17 ( V_32 , 0 ) ;
F_18 ( V_32 ) = F_19 ( F_20 ( V_60 ,
V_20 ) ) ;
V_32 -> V_35 = V_8 -> V_61 . V_62 ;
V_32 -> V_38 = V_8 -> V_63 . V_62 ;
V_32 -> V_64 = * ( V_65 * ) ( V_8 -> V_61 . V_66 . V_67 ) ;
V_32 -> V_68 = * ( V_65 * ) ( V_8 -> V_61 . V_66 . V_67 +
8 ) ;
V_32 -> V_69 = * ( V_65 * ) ( V_8 -> V_63 . V_66 . V_67 ) ;
V_32 -> V_70 = * ( V_65 * ) ( V_8 -> V_63 . V_66 . V_67 +
8 ) ;
V_32 -> V_18 = F_21 ( V_18 ) ;
V_19 |= V_47 ;
V_32 -> V_19 = F_19 ( V_19 ) ;
V_32 -> V_44 = F_19 ( F_22 (
V_8 -> V_13 -> V_45 [ V_8 -> V_46 ] ,
V_8 -> V_24 ) ) ;
} else {
struct V_71 * V_32 =
(struct V_71 * ) V_2 -> V_33 ;
F_17 ( V_32 , 0 ) ;
F_18 ( V_32 ) = F_19 ( F_20 ( V_60 ,
V_20 ) ) ;
V_32 -> V_35 = V_8 -> V_61 . V_62 ;
V_32 -> V_38 = V_8 -> V_63 . V_62 ;
V_32 -> V_64 = * ( V_65 * ) ( V_8 -> V_61 . V_66 . V_67 ) ;
V_32 -> V_68 = * ( V_65 * ) ( V_8 -> V_61 . V_66 . V_67 +
8 ) ;
V_32 -> V_69 = * ( V_65 * ) ( V_8 -> V_63 . V_66 . V_67 ) ;
V_32 -> V_70 = * ( V_65 * ) ( V_8 -> V_63 . V_66 . V_67 +
8 ) ;
V_32 -> V_18 = F_21 ( V_18 ) ;
V_19 |= V_54 ;
V_32 -> V_19 = F_19 ( V_19 ) ;
V_32 -> V_44 = F_21 ( F_26 ( F_22 (
V_8 -> V_13 -> V_45 [ V_8 -> V_46 ] ,
V_8 -> V_24 ) ) ) ;
}
F_27 ( V_2 , V_55 , V_8 -> V_46 ) ;
F_31 ( L_4 ,
V_14 ? 4 : 5 , V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_21 ,
& V_8 -> V_61 . V_66 , F_24 ( V_8 -> V_36 . V_37 ) ,
& V_8 -> V_63 . V_66 , F_24 ( V_8 -> V_39 . V_37 ) ,
V_8 -> V_22 ) ;
F_29 ( V_8 -> V_13 -> V_45 [ V_8 -> V_46 ] , V_2 , V_8 -> V_24 ) ;
}
static void F_32 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_72 ;
struct V_73 * V_32 = (struct V_73 * ) V_2 -> V_33 ;
unsigned int V_74 = V_8 -> V_74 ;
F_23 ( 1 << V_48 | 1 << V_49 ,
L_5 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 ) ;
V_8 -> V_72 = NULL ;
F_27 ( V_2 , V_75 , V_8 -> V_46 ) ;
F_17 ( V_32 , V_74 ) ;
F_18 ( V_32 ) = F_19 ( F_20 ( V_76 , V_74 ) ) ;
V_32 -> V_52 = 0 ;
F_33 ( V_8 , V_2 ) ;
if ( V_8 -> V_56 >= V_77 )
F_34 ( V_8 , 1 ) ;
}
static void F_35 ( void * V_78 , struct V_1 * V_2 )
{
struct V_7 * V_8 = (struct V_7 * ) V_78 ;
struct V_79 * V_32 ;
F_23 ( 1 << V_48 | 1 << V_49 ,
L_6 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 ) ;
V_32 = (struct V_79 * ) V_2 -> V_80 ;
V_32 -> V_81 = V_82 ;
F_36 ( V_8 -> V_13 -> V_45 [ V_8 -> V_46 ] , V_2 ) ;
}
static void F_37 ( struct V_7 * V_8 )
{
struct V_79 * V_32 ;
struct V_1 * V_2 = V_8 -> V_79 ;
if ( F_38 ( V_8 -> V_56 == V_83 ) || ! V_2 || ! V_8 -> V_13 )
return;
if ( ! F_39 ( V_8 , V_84 ) ) {
F_40 ( V_8 ) ;
F_41 ( V_8 , V_84 ) ;
}
F_42 ( V_8 , V_83 ) ;
F_41 ( V_8 , V_85 ) ;
F_43 ( V_8 ) ;
V_8 -> V_79 = NULL ;
V_32 = (struct V_79 * ) V_2 -> V_33 ;
F_27 ( V_2 , V_75 , V_8 -> V_46 ) ;
V_32 -> V_81 = V_86 ;
F_44 ( V_2 , V_8 , F_35 ) ;
F_17 ( V_32 , V_8 -> V_74 ) ;
F_18 ( V_32 ) = F_19 ( F_20 ( V_87 , V_8 -> V_74 ) ) ;
V_32 -> V_88 = F_45 ( V_8 -> V_89 ) ;
V_32 -> V_90 = ! F_39 ( V_8 , V_84 ) ;
F_23 ( 1 << V_48 | 1 << V_49 ,
L_7 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 , V_8 -> V_89 ,
V_32 -> V_90 ) ;
F_29 ( V_8 -> V_13 -> V_45 [ V_8 -> V_46 ] , V_2 , V_8 -> V_24 ) ;
}
static void F_46 ( struct V_7 * V_8 , int V_91 )
{
struct V_1 * V_2 = V_8 -> V_92 ;
struct V_92 * V_93 = (struct V_92 * ) V_2 -> V_33 ;
F_23 ( 1 << V_48 | 1 << V_49 ,
L_8 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 , V_91 ) ;
V_8 -> V_92 = NULL ;
F_27 ( V_2 , V_75 , V_8 -> V_46 ) ;
F_17 ( V_93 , V_8 -> V_74 ) ;
F_18 ( V_93 ) = F_19 ( F_20 ( V_94 , V_8 -> V_74 ) ) ;
V_93 -> V_81 = V_91 ;
F_36 ( V_8 -> V_13 -> V_45 [ V_8 -> V_46 ] , V_2 ) ;
}
static T_1 F_47 ( struct V_7 * V_8 , T_1 V_95 )
{
struct V_1 * V_2 ;
struct V_96 * V_32 ;
F_23 ( 1 << V_48 | 1 << V_97 ,
L_9 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 , V_95 ) ;
V_2 = F_48 ( sizeof( * V_32 ) , 0 , V_98 ) ;
if ( ! V_2 ) {
F_31 ( L_10 , V_8 , V_95 ) ;
return 0 ;
}
V_32 = (struct V_96 * ) V_2 -> V_33 ;
F_27 ( V_2 , V_99 , V_8 -> V_46 ) ;
F_17 ( V_32 , V_8 -> V_74 ) ;
F_18 ( V_32 ) = F_19 ( F_20 ( V_100 ,
V_8 -> V_74 ) ) ;
V_32 -> V_101 = F_19 ( F_49 ( V_95 )
| V_102 ) ;
F_36 ( V_8 -> V_13 -> V_45 [ V_8 -> V_46 ] , V_2 ) ;
return V_95 ;
}
static inline unsigned int F_50 ( unsigned int V_103 )
{
V_103 -- ;
return ( 3 * V_103 ) / 2 + ( V_103 & 1 ) + 2 ;
}
static inline unsigned int F_51 ( const struct V_1 * V_2 )
{
unsigned int V_104 , V_105 ;
if ( F_1 ( V_2 ) )
return F_52 ( V_2 -> V_3 , 8 ) ;
V_104 = F_53 ( V_2 ) / 8 ;
V_105 = F_54 ( V_2 ) -> V_106 ;
if ( F_55 ( V_2 ) != F_56 ( V_2 ) )
V_105 ++ ;
return V_104 + F_50 ( V_105 ) ;
}
static inline int F_57 ( int * V_107 , int * V_108 )
{
int V_109 , V_110 , V_111 ;
V_109 = V_112 ;
V_111 = F_58 ( struct V_113 , V_114 [ V_109 ] ) ;
V_110 = F_52 ( V_111 , 16 ) ;
V_111 = V_110 * 16 ;
if ( V_107 )
* V_107 = V_109 ;
if ( V_108 )
* V_108 = V_111 ;
return V_110 ;
}
static inline int F_40 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
struct V_113 * V_115 ;
int V_109 , V_110 , V_111 ;
V_110 = F_57 ( & V_109 , & V_111 ) ;
V_2 = F_48 ( V_111 , 0 , V_98 ) ;
V_115 = (struct V_113 * ) V_2 -> V_33 ;
V_115 -> V_116 =
F_45 ( F_59 ( V_117 ) | F_60 ( V_109 ) ) ;
V_115 -> V_118 =
F_45 ( F_61 ( V_110 ) | F_62 ( V_8 -> V_74 ) ) ;
V_115 -> V_114 [ 0 ] . V_119 = V_120 ;
V_115 -> V_114 [ 0 ] . V_121 = F_45 ( V_8 -> V_13 -> V_122 ) ;
V_115 -> V_114 [ 1 ] . V_119 = V_123 ;
V_115 -> V_114 [ 1 ] . V_121 = F_45 ( V_8 -> V_26 ) ;
V_115 -> V_114 [ 2 ] . V_119 = V_124 ;
V_115 -> V_114 [ 2 ] . V_121 = F_45 ( V_8 -> V_26 ) ;
V_115 -> V_114 [ 3 ] . V_119 = V_125 ;
V_115 -> V_114 [ 3 ] . V_121 = F_45 ( V_8 -> V_22 ) ;
V_115 -> V_114 [ 4 ] . V_119 = V_126 ;
V_115 -> V_114 [ 4 ] . V_121 = F_45 ( V_8 -> V_89 ) ;
V_115 -> V_114 [ 5 ] . V_119 = V_127 ;
V_115 -> V_114 [ 5 ] . V_121 = F_45 ( V_8 -> V_128 ) ;
V_115 -> V_114 [ 6 ] . V_119 = V_129 ;
V_115 -> V_114 [ 6 ] . V_121 = F_45 ( V_8 -> V_130 ) ;
V_115 -> V_114 [ 7 ] . V_119 = V_131 ;
V_115 -> V_114 [ 7 ] . V_121 = F_45 ( V_8 -> V_132 ) ;
V_115 -> V_114 [ 8 ] . V_119 = 0 ;
V_115 -> V_114 [ 8 ] . V_121 = 0 ;
V_115 -> V_114 [ 8 ] . V_119 = V_133 ;
V_115 -> V_114 [ 8 ] . V_121 = 16384 ;
F_27 ( V_2 , V_75 , V_8 -> V_46 ) ;
F_23 ( 1 << V_48 | 1 << V_49 ,
L_11 ,
V_8 , V_8 -> V_74 , 0 , V_8 -> V_26 , V_8 -> V_22 ,
V_8 -> V_89 , V_8 -> V_128 , V_8 -> V_130 ,
V_8 -> V_132 ) ;
F_36 ( V_8 -> V_13 -> V_45 [ V_8 -> V_46 ] , V_2 ) ;
return V_110 ;
}
static inline void F_63 ( struct V_7 * V_8 , struct V_1 * V_2 ,
int V_134 , int V_3 , T_1 V_95 , int V_135 )
{
struct V_5 * V_32 ;
unsigned int V_136 = F_64 ( V_2 ) & 3 ;
unsigned int V_137 = 0 , V_121 ;
bool V_138 = F_1 ( V_2 ) ;
V_32 = (struct V_5 * ) F_65 ( V_2 , sizeof( * V_32 ) ) ;
if ( V_138 ) {
V_32 -> V_139 = F_45 ( F_59 ( V_140 ) |
V_141 |
F_66 ( V_134 ) ) ;
V_32 -> V_118 = F_45 ( F_62 ( V_8 -> V_74 ) |
F_61 ( V_95 ) ) ;
} else {
V_32 -> V_139 =
F_19 ( F_59 ( V_140 ) |
V_141 |
F_66 ( 0 ) ) ;
V_32 -> V_118 =
F_19 ( F_62 ( V_8 -> V_74 ) |
F_61 ( V_95 ) ) ;
}
if ( V_136 )
V_137 = F_67 ( V_142 ) |
F_68 ( V_136 ) ;
V_121 = F_69 ( & V_8 -> V_143 ) ? 0 : 1 ;
V_32 -> V_144 = F_45 ( V_137 |
F_70 ( V_121 ) ) ;
V_32 -> V_145 = F_45 ( V_3 ) ;
if ( ! F_39 ( V_8 , V_84 ) )
F_41 ( V_8 , V_84 ) ;
}
static void F_71 ( void * V_78 , struct V_1 * V_2 )
{
F_72 ( V_2 ) ;
}
static int F_34 ( struct V_7 * V_8 , int V_146 )
{
int V_147 = 0 ;
struct V_1 * V_2 ;
if ( F_38 ( V_8 -> V_56 < V_77 ||
V_8 -> V_56 == V_148 || V_8 -> V_56 >= V_83 ) ) {
F_23 ( 1 << V_48 | 1 << V_49 |
1 << V_149 ,
L_12 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 ) ;
return 0 ;
}
while ( V_8 -> V_150 && ( V_2 = F_69 ( & V_8 -> V_143 ) ) != NULL ) {
int V_134 = V_2 -> V_3 ;
int V_3 = V_2 -> V_3 ;
unsigned int V_151 ;
int V_110 = 0 ;
F_73 ( V_2 ) ;
if ( F_1 ( V_2 ) )
V_151 = F_52 ( V_134 , 16 ) ;
else
V_151 = F_52 (
8 * F_51 ( V_2 ) ,
16 ) ;
if ( F_2 ( F_3 ( V_2 , V_4 ) ) )
V_151 += F_52 (
sizeof( struct V_5 ) ,
16 ) ;
if ( ! F_39 ( V_8 , V_84 ) ) {
V_110 = F_40 ( V_8 ) ;
V_8 -> V_150 -= V_110 ;
V_8 -> V_152 += V_110 ;
F_41 ( V_8 , V_84 ) ;
}
if ( V_8 -> V_150 < V_151 ) {
F_23 ( 1 << V_149 ,
L_13 ,
V_8 , V_2 -> V_3 , V_2 -> V_153 ,
V_151 , V_8 -> V_150 ) ;
break;
}
F_74 ( V_2 , & V_8 -> V_143 ) ;
F_27 ( V_2 , V_75 , V_8 -> V_46 ) ;
V_2 -> V_154 = V_151 + V_110 ;
V_8 -> V_150 -= V_151 ;
V_8 -> V_152 += V_151 ;
F_75 ( V_8 , V_2 ) ;
F_23 ( 1 << V_149 ,
L_14 ,
V_8 , V_2 -> V_3 , V_2 -> V_153 , V_151 ,
V_8 -> V_150 , V_8 -> V_152 ) ;
if ( F_2 ( F_3 ( V_2 , V_4 ) ) ) {
V_3 += F_76 ( F_64 ( V_2 ) ) ;
F_63 ( V_8 , V_2 , V_134 , V_3 , V_151 ,
V_146 ) ;
V_8 -> V_89 += V_3 ;
F_77 ( V_2 , V_4 ) ;
} else if ( F_3 ( V_2 , V_155 ) &&
( V_8 -> V_152 >= ( V_8 -> V_156 / 2 ) ) ) {
struct V_73 * V_32 =
(struct V_73 * ) V_2 -> V_80 ;
V_32 -> V_157 . V_158 |= F_45 ( V_141 ) ;
}
V_147 += V_2 -> V_159 ;
F_44 ( V_2 , V_8 , F_71 ) ;
F_23 ( 1 << V_48 | 1 << V_149 ,
L_15 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 , V_2 , V_3 ) ;
F_29 ( V_8 -> V_13 -> V_45 [ V_8 -> V_46 ] , V_2 , V_8 -> V_24 ) ;
}
return V_147 ;
}
static inline void F_78 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
if ( F_39 ( V_8 , V_160 ) ) {
F_79 ( V_12 -> V_161 , V_8 -> V_21 ) ;
F_80 ( V_8 , V_160 ) ;
F_81 ( V_8 ) ;
}
}
static void F_82 ( struct V_162 * V_13 , struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_163 * V_32 = (struct V_163 * ) V_2 -> V_80 ;
unsigned short V_164 = F_24 ( V_32 -> V_164 ) ;
unsigned int V_74 = F_83 ( V_32 ) ;
unsigned int V_21 = F_84 ( F_85 ( V_32 -> V_165 ) ) ;
struct V_11 * V_12 = F_5 ( V_13 ) ;
struct V_166 * V_167 = V_12 -> V_161 ;
T_1 V_168 = F_86 ( V_32 -> V_168 ) ;
V_8 = F_87 ( V_167 , V_21 ) ;
if ( F_38 ( ! V_8 ) ) {
F_88 ( L_16 , V_21 , V_13 ) ;
goto V_169;
}
if ( V_8 -> V_21 != V_21 ) {
F_88 ( L_17 ,
V_21 , V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 , V_8 -> V_21 ) ;
goto V_169;
}
F_28 ( L_18 ,
( & V_8 -> V_36 ) , ( & V_8 -> V_39 ) ,
V_21 , V_74 , V_8 , V_8 -> V_56 , V_8 -> V_57 , V_168 ) ;
F_89 ( V_170 ) ;
F_90 ( V_8 ) ;
V_8 -> V_74 = V_74 ;
F_91 ( V_12 -> V_161 , V_8 , V_74 ) ;
F_41 ( V_8 , V_171 ) ;
F_78 ( V_8 ) ;
F_92 ( & V_8 -> V_172 ) ;
if ( F_38 ( V_8 -> V_56 != V_173 ) )
F_31 ( L_19 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 ) ;
if ( V_8 -> V_174 . V_175 ) {
F_93 ( & V_8 -> V_174 ) ;
V_8 -> V_174 . V_175 = NULL ;
}
V_8 -> V_176 = V_8 -> V_177 = V_8 -> V_128 = V_168 ;
if ( V_8 -> V_29 > ( V_178 << 10 ) )
V_8 -> V_177 -= V_8 -> V_29 - ( V_178 << 10 ) ;
V_8 -> V_132 = V_12 -> V_179 [ F_94 ( V_164 ) ] - 40 ;
if ( F_95 ( V_164 ) )
V_8 -> V_132 -= 12 ;
if ( V_8 -> V_132 < 128 )
V_8 -> V_132 = 128 ;
F_23 ( 1 << V_48 | 1 << V_49 ,
L_20 ,
V_8 , F_94 ( V_164 ) , V_8 -> V_132 ) ;
F_96 ( V_8 , F_85 ( V_32 -> V_180 ) , F_24 ( V_32 -> V_164 ) ) ;
if ( F_38 ( F_39 ( V_8 , V_181 ) ) )
F_37 ( V_8 ) ;
else {
if ( F_97 ( & V_8 -> V_143 ) )
F_34 ( V_8 , 0 ) ;
F_98 ( V_8 ) ;
}
F_99 ( & V_8 -> V_172 ) ;
V_169:
F_100 ( V_2 ) ;
}
static int F_101 ( int V_182 )
{
switch ( V_182 ) {
case V_183 :
return - V_184 ;
case V_185 :
return - V_186 ;
case V_187 :
return - V_188 ;
case V_189 :
return - V_190 ;
case V_191 :
return - V_192 ;
default:
return - V_193 ;
}
}
static void F_102 ( unsigned long V_80 )
{
struct V_1 * V_2 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) V_80 ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
void (* F_103)( struct V_7 * , struct V_1 * ,
struct V_9 * );
int V_14 = F_6 ( V_12 -> V_15 ) , V_194 , V_195 ;
F_23 ( 1 << V_48 | 1 << V_49 ,
L_21 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 ) ;
F_90 ( V_8 ) ;
F_92 ( & V_8 -> V_172 ) ;
if ( V_14 ) {
V_194 = sizeof( struct V_31 ) ;
V_195 = sizeof( struct V_59 ) ;
} else {
V_194 = sizeof( struct V_50 ) ;
V_195 = sizeof( struct V_71 ) ;
}
if ( V_8 -> V_196 == V_197 ) {
F_103 = F_4 ;
V_2 = F_48 ( V_194 , 0 , V_98 ) ;
#if F_104 ( V_198 )
} else {
F_103 = F_30 ;
V_2 = F_48 ( V_195 , 0 , V_98 ) ;
#endif
}
if ( ! V_2 )
F_105 ( V_8 , - V_190 ) ;
else {
V_2 -> V_199 = (struct V_200 * ) V_8 ;
F_44 ( V_2 , V_8 ,
V_201 ) ;
F_103 ( V_8 , V_2 , V_8 -> V_24 ) ;
}
F_99 ( & V_8 -> V_172 ) ;
F_81 ( V_8 ) ;
}
static inline bool F_106 ( unsigned int V_182 )
{
return V_182 == V_202 ||
V_182 == V_203 ||
V_182 == V_204 ;
}
static void F_107 ( struct V_162 * V_13 , struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_205 * V_93 = (struct V_205 * ) V_2 -> V_80 ;
unsigned int V_74 = F_83 ( V_93 ) ;
unsigned int V_21 =
F_84 ( F_108 ( F_86 ( V_93 -> V_206 ) ) ) ;
unsigned int V_182 = F_109 ( F_86 ( V_93 -> V_206 ) ) ;
struct V_11 * V_12 = F_5 ( V_13 ) ;
struct V_166 * V_167 = V_12 -> V_161 ;
V_8 = F_87 ( V_167 , V_21 ) ;
if ( F_38 ( ! V_8 ) ) {
F_88 ( L_22 , V_21 , V_74 ) ;
goto V_169;
}
F_28 ( L_23
L_24 , ( & V_8 -> V_36 ) , ( & V_8 -> V_39 ) ,
V_21 , V_74 , V_182 , V_8 , V_8 -> V_56 , V_8 -> V_57 ) ;
if ( F_106 ( V_182 ) )
goto V_169;
F_89 ( V_170 ) ;
if ( V_182 && V_182 != V_189 &&
V_182 != V_191 &&
V_182 != V_185 )
F_110 ( V_12 -> V_161 , V_8 -> V_46 , F_83 ( V_93 ) ) ;
F_90 ( V_8 ) ;
F_92 ( & V_8 -> V_172 ) ;
if ( V_182 == V_191 &&
V_8 -> V_174 . V_175 != F_102 ) {
V_8 -> V_174 . V_175 = F_102 ;
F_111 ( & V_8 -> V_174 , V_207 + V_208 / 2 ) ;
} else
F_105 ( V_8 ,
F_101 ( V_182 ) ) ;
F_99 ( & V_8 -> V_172 ) ;
F_81 ( V_8 ) ;
V_169:
F_100 ( V_2 ) ;
}
static void F_112 ( struct V_162 * V_13 , struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_209 * V_32 = (struct V_209 * ) V_2 -> V_80 ;
unsigned int V_74 = F_83 ( V_32 ) ;
struct V_11 * V_12 = F_5 ( V_13 ) ;
struct V_166 * V_167 = V_12 -> V_161 ;
V_8 = F_113 ( V_167 , V_74 ) ;
if ( F_38 ( ! V_8 ) ) {
F_88 ( L_25 , V_74 ) ;
goto V_169;
}
F_28 ( L_21 ,
( & V_8 -> V_36 ) , ( & V_8 -> V_39 ) ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 ) ;
F_114 ( V_8 ) ;
V_169:
F_100 ( V_2 ) ;
}
static void F_115 ( struct V_162 * V_13 , struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_210 * V_93 = (struct V_210 * ) V_2 -> V_80 ;
unsigned int V_74 = F_83 ( V_93 ) ;
struct V_11 * V_12 = F_5 ( V_13 ) ;
struct V_166 * V_167 = V_12 -> V_161 ;
V_8 = F_113 ( V_167 , V_74 ) ;
if ( F_38 ( ! V_8 ) ) {
F_88 ( L_25 , V_74 ) ;
goto V_169;
}
F_28 ( L_21 ,
( & V_8 -> V_36 ) , ( & V_8 -> V_39 ) ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 ) ;
F_116 ( V_8 , F_85 ( V_93 -> V_89 ) ) ;
V_169:
F_100 ( V_2 ) ;
}
static int F_117 ( struct V_7 * V_8 , int V_211 ,
int * V_212 )
{
switch ( V_211 ) {
case V_213 :
case V_183 :
return V_8 -> V_56 > V_77 ?
- V_214 : - V_215 ;
case V_216 :
case V_217 :
case V_218 :
case V_219 :
return - V_188 ;
default:
return - V_193 ;
}
}
static void F_118 ( struct V_162 * V_13 , struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_220 * V_32 = (struct V_220 * ) V_2 -> V_80 ;
unsigned int V_74 = F_83 ( V_32 ) ;
struct V_11 * V_12 = F_5 ( V_13 ) ;
struct V_166 * V_167 = V_12 -> V_161 ;
int V_91 = V_82 ;
V_8 = F_113 ( V_167 , V_74 ) ;
if ( F_38 ( ! V_8 ) ) {
F_88 ( L_25 , V_74 ) ;
goto V_169;
}
F_28 ( L_26 ,
( & V_8 -> V_36 ) , ( & V_8 -> V_39 ) ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 , V_32 -> V_182 ) ;
if ( F_106 ( V_32 -> V_182 ) )
goto V_169;
F_90 ( V_8 ) ;
F_92 ( & V_8 -> V_172 ) ;
F_80 ( V_8 , V_221 ) ;
if ( ! F_39 ( V_8 , V_84 ) ) {
F_40 ( V_8 ) ;
F_41 ( V_8 , V_84 ) ;
}
F_41 ( V_8 , V_221 ) ;
F_42 ( V_8 , V_83 ) ;
F_46 ( V_8 , V_91 ) ;
if ( ! F_39 ( V_8 , V_85 ) ) {
V_8 -> V_222 = F_117 ( V_8 , V_32 -> V_182 , & V_91 ) ;
F_119 ( V_8 ) ;
}
F_99 ( & V_8 -> V_172 ) ;
F_81 ( V_8 ) ;
V_169:
F_100 ( V_2 ) ;
}
static void F_120 ( struct V_162 * V_13 , struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_223 * V_93 = (struct V_223 * ) V_2 -> V_80 ;
unsigned int V_74 = F_83 ( V_93 ) ;
struct V_11 * V_12 = F_5 ( V_13 ) ;
struct V_166 * V_167 = V_12 -> V_161 ;
V_8 = F_113 ( V_167 , V_74 ) ;
if ( ! V_8 )
goto V_169;
if ( V_8 )
F_28 ( L_26 ,
( & V_8 -> V_36 ) , ( & V_8 -> V_39 ) , V_8 ,
V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 , V_93 -> V_182 ) ;
if ( V_93 -> V_182 == V_224 )
goto V_169;
F_121 ( V_8 ) ;
V_169:
F_100 ( V_2 ) ;
}
static void F_122 ( struct V_162 * V_13 , struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_225 * V_226 = (struct V_225 * ) V_2 -> V_80 ;
unsigned int V_74 = F_83 ( V_226 ) ;
struct V_11 * V_12 = F_5 ( V_13 ) ;
struct V_166 * V_167 = V_12 -> V_161 ;
V_8 = F_113 ( V_167 , V_74 ) ;
if ( ! V_8 ) {
F_88 ( L_25 , V_74 ) ;
} else {
F_88 ( L_27 , V_8 , V_74 ) ;
F_92 ( & V_8 -> V_172 ) ;
F_37 ( V_8 ) ;
F_99 ( & V_8 -> V_172 ) ;
}
F_100 ( V_2 ) ;
}
static void F_123 ( struct V_162 * V_13 , struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_227 * V_226 = (struct V_227 * ) V_2 -> V_80 ;
unsigned short V_228 = F_124 ( V_226 -> V_228 ) ;
unsigned int V_74 = F_83 ( V_226 ) ;
struct V_11 * V_12 = F_5 ( V_13 ) ;
struct V_166 * V_167 = V_12 -> V_161 ;
V_8 = F_113 ( V_167 , V_74 ) ;
if ( F_38 ( ! V_8 ) ) {
F_88 ( L_28 , V_74 ) ;
goto V_169;
}
F_23 ( 1 << V_48 | 1 << V_97 ,
L_29 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 , V_2 , V_2 -> V_3 ,
V_228 ) ;
F_92 ( & V_8 -> V_172 ) ;
if ( F_38 ( V_8 -> V_56 >= V_229 ) ) {
F_23 ( 1 << V_48 | 1 << V_49 ,
L_30 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 ) ;
if ( V_8 -> V_56 != V_83 )
goto V_230;
else
goto V_231;
}
F_125 ( V_2 ) = F_85 ( V_226 -> V_232 ) ;
F_126 ( V_2 ) = 0 ;
F_73 ( V_2 ) ;
F_127 ( V_2 , sizeof( * V_226 ) ) ;
F_128 ( V_2 , F_24 ( V_226 -> V_3 ) ) ;
if ( ! V_8 -> V_233 ) {
unsigned char * V_234 ;
unsigned int V_235 , V_134 , V_145 ;
F_23 ( 1 << V_48 | 1 << V_97 ,
L_31 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 , V_2 ) ;
V_8 -> V_233 = V_2 ;
F_129 ( V_2 , V_236 ) ;
if ( F_125 ( V_2 ) != V_8 -> V_128 ) {
F_31 ( L_32 ,
V_8 -> V_74 , F_125 ( V_2 ) ,
V_8 -> V_128 ) ;
goto V_230;
}
V_234 = V_2 -> V_80 ;
V_235 = F_24 ( V_226 -> V_3 ) ;
V_134 = F_85 ( * ( unsigned int * ) ( V_234 + 4 ) ) & 0xFFFFFF ;
V_145 = F_130 ( V_228 ) ;
if ( F_6 ( V_12 -> V_15 ) )
V_145 -= 40 ;
if ( ( V_235 + V_134 ) != V_145 ) {
F_31 ( L_33
L_34 ,
V_8 -> V_74 , V_145 , V_235 , V_134 ,
F_125 ( V_2 ) ) ;
goto V_230;
}
F_131 ( V_2 ) = ( V_235 + V_134 + 3 ) & ( ~ 0x3 ) ;
if ( V_134 )
F_131 ( V_2 ) += V_8 -> V_237 ;
V_8 -> V_128 += F_131 ( V_2 ) ;
F_23 ( 1 << V_48 | 1 << V_97 ,
L_35 ,
V_8 , V_2 , * V_234 , V_235 , V_134 ,
F_85 ( * ( ( unsigned int * ) ( V_234 + 16 ) ) ) ,
F_85 ( * ( ( unsigned int * ) ( V_234 + 24 ) ) ) ) ;
} else {
struct V_1 * V_238 = V_8 -> V_233 ;
F_129 ( V_238 , V_239 ) ;
F_23 ( 1 << V_48 | 1 << V_97 ,
L_36 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_2 , V_238 ) ;
}
F_132 ( & V_8 -> V_240 , V_2 ) ;
F_99 ( & V_8 -> V_172 ) ;
return;
V_230:
F_37 ( V_8 ) ;
V_231:
F_99 ( & V_8 -> V_172 ) ;
V_169:
F_100 ( V_2 ) ;
}
static void F_133 ( struct V_162 * V_13 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_1 * V_238 ;
struct V_241 * V_93 = (struct V_241 * ) V_2 -> V_80 ;
unsigned int V_74 = F_83 ( V_93 ) ;
struct V_11 * V_12 = F_5 ( V_13 ) ;
struct V_166 * V_167 = V_12 -> V_161 ;
unsigned int V_182 = F_85 ( V_93 -> V_242 ) ;
V_8 = F_113 ( V_167 , V_74 ) ;
if ( F_38 ( ! V_8 ) ) {
F_88 ( L_25 , V_74 ) ;
goto V_169;
}
F_23 ( 1 << V_48 | 1 << V_97 ,
L_37 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_2 , V_182 , V_8 -> V_233 ) ;
F_92 ( & V_8 -> V_172 ) ;
if ( F_38 ( V_8 -> V_56 >= V_229 ) ) {
F_23 ( 1 << V_48 | 1 << V_49 ,
L_30 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 ) ;
if ( V_8 -> V_56 != V_83 )
goto V_230;
else
goto V_231;
}
if ( ! V_8 -> V_233 ) {
F_88 ( L_38 , V_8 -> V_74 ) ;
goto V_230;
}
V_238 = V_8 -> V_233 ;
V_8 -> V_233 = NULL ;
F_134 ( V_238 ) = F_85 ( V_93 -> V_243 ) ;
if ( F_24 ( V_93 -> V_3 ) != F_131 ( V_238 ) )
F_31 ( L_39 ,
V_8 -> V_74 , F_24 ( V_93 -> V_3 ) , F_131 ( V_238 ) ) ;
if ( V_182 & ( 1 << V_244 ) ) {
F_31 ( L_40 ,
V_8 , V_238 , V_182 , F_126 ( V_238 ) ) ;
F_129 ( V_238 , V_245 ) ;
}
if ( V_182 & ( 1 << V_246 ) ) {
F_31 ( L_41 ,
V_8 , V_238 , V_182 , F_126 ( V_238 ) ) ;
F_129 ( V_238 , V_247 ) ;
}
if ( V_182 & ( 1 << V_248 ) ) {
F_23 ( 1 << V_97 ,
L_42 ,
V_8 , V_238 , V_182 ) ;
F_129 ( V_238 , V_249 ) ;
}
if ( ( V_182 & ( 1 << V_250 ) ) &&
! F_3 ( V_238 , V_239 ) ) {
F_23 ( 1 << V_97 ,
L_43 ,
V_8 , V_238 , V_182 ) ;
F_129 ( V_238 , V_251 ) ;
}
F_23 ( 1 << V_97 ,
L_44 ,
V_8 , V_238 , F_126 ( V_238 ) ) ;
F_129 ( V_238 , V_252 ) ;
F_135 ( V_8 ) ;
F_99 ( & V_8 -> V_172 ) ;
goto V_169;
V_230:
F_37 ( V_8 ) ;
V_231:
F_99 ( & V_8 -> V_172 ) ;
V_169:
F_100 ( V_2 ) ;
}
static void F_136 ( struct V_162 * V_13 , struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_253 * V_93 = (struct V_253 * ) V_2 -> V_80 ;
unsigned int V_74 = F_83 ( V_93 ) ;
struct V_11 * V_12 = F_5 ( V_13 ) ;
struct V_166 * V_167 = V_12 -> V_161 ;
V_8 = F_113 ( V_167 , V_74 ) ;
if ( F_38 ( ! V_8 ) )
F_88 ( L_25 , V_74 ) ;
else {
F_23 ( 1 << V_48 | 1 << V_49 ,
L_21 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 ) ;
F_137 ( V_8 , V_93 -> V_95 , F_85 ( V_93 -> V_254 ) ,
V_93 -> V_255 ) ;
}
F_100 ( V_2 ) ;
}
static void F_138 ( struct V_162 * V_13 , struct V_1 * V_2 )
{
struct V_256 * V_93 = (struct V_256 * ) V_2 -> V_80 ;
unsigned int V_74 = F_83 ( V_93 ) ;
struct V_11 * V_12 = F_5 ( V_13 ) ;
struct V_166 * V_167 = V_12 -> V_161 ;
struct V_7 * V_8 ;
V_8 = F_113 ( V_167 , V_74 ) ;
if ( ! V_8 )
F_88 ( L_28 , V_74 ) ;
F_23 ( 1 << V_48 | 1 << V_49 ,
L_45 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 , V_93 -> V_182 ) ;
if ( V_93 -> V_182 != V_257 )
F_88 ( L_46 ,
V_8 , V_74 , V_93 -> V_182 ) ;
F_100 ( V_2 ) ;
}
static int F_139 ( struct V_7 * V_8 )
{
V_8 -> V_72 = F_48 ( sizeof( struct V_73 ) ,
0 , V_258 ) ;
if ( ! V_8 -> V_72 )
return - V_190 ;
V_8 -> V_79 = F_48 ( sizeof( struct V_79 ) ,
0 , V_258 ) ;
if ( ! V_8 -> V_79 )
goto V_259;
V_8 -> V_92 = F_48 ( sizeof( struct V_92 ) ,
0 , V_258 ) ;
if ( ! V_8 -> V_92 )
goto V_259;
return 0 ;
V_259:
F_140 ( V_8 ) ;
return - V_190 ;
}
static inline void F_141 ( struct V_7 * V_8 )
{
if ( V_8 -> V_24 ) {
F_142 ( V_8 -> V_24 ) ;
V_8 -> V_24 = NULL ;
F_81 ( V_8 ) ;
}
}
static void F_143 ( struct V_7 * V_8 )
{
struct V_11 * V_12 ;
#if F_104 ( V_198 )
struct V_260 * V_261 = V_8 -> V_13 -> V_45 [ V_8 -> V_46 ] ;
#endif
F_23 ( 1 << V_48 | 1 << V_49 ,
L_21 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 ) ;
F_140 ( V_8 ) ;
if ( V_8 -> V_150 != V_8 -> V_156 ) {
F_144 ( V_8 ) ;
F_145 ( V_8 ) ;
}
F_141 ( V_8 ) ;
#if F_104 ( V_198 )
if ( V_8 -> V_196 == V_262 )
F_146 ( V_261 ,
( const T_1 * ) & V_8 -> V_61 . V_66 , 1 ) ;
#endif
if ( F_39 ( V_8 , V_160 ) )
F_78 ( V_8 ) ;
else if ( F_39 ( V_8 , V_171 ) ) {
V_12 = F_5 ( V_8 -> V_13 ) ;
F_110 ( V_12 -> V_161 , 0 , V_8 -> V_74 ) ;
F_80 ( V_8 , V_171 ) ;
F_81 ( V_8 ) ;
}
V_8 -> V_263 = NULL ;
V_8 -> V_13 = NULL ;
}
static int F_147 ( struct V_7 * V_8 )
{
struct V_162 * V_13 = V_8 -> V_13 ;
struct V_11 * V_12 = F_5 ( V_13 ) ;
struct V_260 * V_261 = V_13 -> V_45 [ V_8 -> V_46 ] ;
struct V_1 * V_2 = NULL ;
struct V_264 * V_103 = NULL ;
void * V_39 ;
unsigned int V_265 ;
unsigned int V_194 , V_195 ;
int V_14 = F_6 ( V_12 -> V_15 ) ;
unsigned int V_266 ;
unsigned int V_267 , V_268 ;
F_23 ( 1 << V_48 | 1 << V_49 ,
L_21 ,
V_8 , V_8 -> V_56 , V_8 -> V_57 , V_8 -> V_74 ) ;
if ( V_8 -> V_196 == V_197 )
V_39 = & V_8 -> V_39 . V_41 . V_42 ;
#if F_104 ( V_198 )
else if ( V_8 -> V_196 == V_262 )
V_39 = & V_8 -> V_63 . V_66 ;
#endif
else {
F_88 ( L_47 , V_8 -> V_196 ) ;
goto V_269;
}
V_103 = F_148 ( V_8 -> V_263 , V_39 ) ;
if ( ! V_103 ) {
F_88 ( L_48 , V_261 -> V_270 ) ;
goto V_269;
}
V_8 -> V_21 = F_149 ( V_12 -> V_161 , V_8 ) ;
if ( V_8 -> V_21 < 0 ) {
F_88 ( L_49 , V_261 -> V_270 ) ;
return - V_271 ;
}
F_41 ( V_8 , V_160 ) ;
F_90 ( V_8 ) ;
V_8 -> V_24 = F_150 ( V_12 -> V_24 , V_103 , V_261 , 0 ) ;
if ( ! V_8 -> V_24 ) {
F_88 ( L_50 , V_261 -> V_270 ) ;
goto V_272;
}
F_90 ( V_8 ) ;
#if F_104 ( V_198 )
if ( V_8 -> V_196 == V_262 )
F_151 ( V_261 , ( const T_1 * ) & V_8 -> V_61 . V_66 , 1 ) ;
#endif
if ( V_14 ) {
V_194 = sizeof( struct V_31 ) ;
V_195 = sizeof( struct V_59 ) ;
} else {
V_194 = sizeof( struct V_50 ) ;
V_195 = sizeof( struct V_71 ) ;
}
if ( V_8 -> V_196 == V_197 )
V_2 = F_48 ( V_194 , 0 , V_273 ) ;
#if F_104 ( V_198 )
else
V_2 = F_48 ( V_195 , 0 , V_273 ) ;
#endif
if ( ! V_2 )
goto V_269;
V_2 -> V_199 = (struct V_200 * ) V_8 ;
F_44 ( V_2 , V_8 , V_201 ) ;
if ( ! V_8 -> V_274 )
V_8 -> V_274 = F_152 ( V_8 -> V_263 ) ;
F_153 ( V_12 -> V_179 , V_8 -> V_274 , & V_8 -> V_17 ) ;
V_8 -> V_26 = F_154 ( V_261 ) ;
V_8 -> V_27 = ( ( F_155 ( V_261 ) & 0x7F ) ) << 1 ;
V_265 = V_12 -> V_275 / V_12 -> V_276 ;
V_8 -> V_277 = F_156 ( V_261 ) * V_265 ;
V_265 = V_12 -> V_278 / V_12 -> V_276 ;
V_8 -> V_22 = V_12 -> V_279 [ F_156 ( V_261 ) * V_265 ] ;
V_266 = ( (struct V_280 * ) F_157 ( V_261 ) ) -> V_281 . V_282 ;
V_8 -> V_130 = V_283 ;
V_8 -> V_29 = V_284 ;
if ( V_284 <= 0 ) {
V_8 -> V_29 = V_285 ;
V_267 = V_266 / V_286 ;
if ( V_267 )
V_8 -> V_29 *= V_267 ;
}
if ( V_283 <= 0 ) {
V_8 -> V_130 = V_287 ;
V_268 = V_266 / V_286 ;
if ( V_268 )
V_8 -> V_130 *= V_268 ;
}
V_8 -> V_150 = V_12 -> V_150 -
F_52 ( sizeof( struct V_79 ) , 16 ) ;
V_8 -> V_156 = V_8 -> V_150 ;
V_8 -> V_152 = 0 ;
F_145 ( V_8 ) ;
V_8 -> V_222 = 0 ;
F_28 ( L_51 ,
( & V_8 -> V_36 ) , ( & V_8 -> V_39 ) , V_8 , V_8 -> V_56 ,
V_8 -> V_57 , V_8 -> V_26 , V_8 -> V_277 , V_8 -> V_22 ,
V_8 -> V_274 , V_8 -> V_17 , V_8 -> V_27 ) ;
F_158 ( V_170 ) ;
F_42 ( V_8 , V_173 ) ;
if ( V_8 -> V_196 == V_197 )
F_4 ( V_8 , V_2 , V_8 -> V_24 ) ;
#if F_104 ( V_198 )
else
F_30 ( V_8 , V_2 , V_8 -> V_24 ) ;
#endif
F_159 ( V_103 ) ;
return 0 ;
V_269:
#if F_104 ( V_198 )
if ( V_8 -> V_196 == V_262 )
F_146 ( V_261 ,
( const T_1 * ) & V_8 -> V_61 . V_66 , 1 ) ;
#endif
V_272:
if ( V_103 )
F_159 ( V_103 ) ;
if ( V_2 )
F_100 ( V_2 ) ;
return - V_271 ;
}
static int F_160 ( struct V_162 * V_13 )
{
int V_288 ;
if ( V_289 > V_290 )
V_289 = V_290 ;
V_288 = F_161 ( V_13 , V_291 ,
V_289 ) ;
if ( V_288 < 0 )
return V_288 ;
V_13 -> V_292 = F_143 ;
V_13 -> V_293 = F_34 ;
V_13 -> V_294 = F_37 ;
V_13 -> V_295 = F_32 ;
V_13 -> V_296 = F_47 ;
V_13 -> V_297 = F_139 ;
V_13 -> V_298 = F_147 ;
F_31 ( L_52 , V_13 ) ;
return 0 ;
}
static inline void
F_162 ( struct V_162 * V_13 ,
struct V_299 * V_32 ,
unsigned int V_300 , unsigned int V_134 ,
unsigned int V_301 ,
int V_74 )
{
struct V_11 * V_12 = F_5 ( V_13 ) ;
struct V_302 * V_303 = (struct V_302 * ) ( V_32 + 1 ) ;
F_163 ( V_32 , V_300 , 0 , V_74 ) ;
V_32 -> V_157 . V_158 = F_45 ( F_59 ( V_304 ) |
F_164 ( 0 ) ) ;
V_32 -> V_81 = F_45 ( F_165 ( V_305 ) |
F_166 ( F_6 ( V_12 -> V_15 ) ) |
F_167 ( ! F_6 ( V_12 -> V_15 ) ) ) ;
V_32 -> V_134 = F_45 ( F_168 ( V_134 >> 5 ) ) ;
V_32 -> V_306 = F_45 ( F_169 ( V_301 >> 5 ) ) ;
V_32 -> V_307 = F_45 ( F_52 ( V_300 - sizeof( V_32 -> V_157 ) , 16 ) ) ;
V_303 -> V_308 = F_45 ( F_165 ( V_309 ) ) ;
V_303 -> V_3 = F_45 ( V_134 ) ;
}
static struct V_1 *
F_170 ( struct V_162 * V_13 ,
struct V_310 * V_311 ,
unsigned int V_25 , unsigned int V_312 ,
unsigned int V_74 )
{
unsigned int V_301 = ( V_25 << V_313 ) + V_311 -> V_314 ;
unsigned int V_134 = V_312 << V_313 ;
unsigned int V_300 = F_171 ( sizeof( struct V_299 ) +
sizeof( struct V_302 ) + V_134 , 16 ) ;
struct V_1 * V_2 = F_48 ( V_300 , 0 , V_98 ) ;
if ( ! V_2 ) {
F_88 ( L_53 ,
V_315 , V_311 -> V_261 -> V_270 , V_25 , V_312 ) ;
return NULL ;
}
F_162 ( V_13 , (struct V_299 * ) V_2 -> V_33 , V_300 , V_134 ,
V_301 , V_74 ) ;
return V_2 ;
}
static int F_172 ( struct V_310 * V_311 , struct V_7 * V_8 ,
struct V_316 * V_317 ,
unsigned int V_25 , unsigned int V_312 ,
struct V_318 * * V_319 ,
unsigned int * V_320 )
{
struct V_162 * V_13 = V_8 -> V_13 ;
struct V_1 * V_2 = F_170 ( V_13 , V_311 , V_25 , V_312 ,
V_8 -> V_74 ) ;
struct V_299 * V_32 ;
struct V_302 * V_303 ;
struct V_321 * V_322 ;
int V_323 ;
if ( ! V_2 )
return - V_190 ;
V_32 = (struct V_299 * ) V_2 -> V_33 ;
V_303 = (struct V_302 * ) ( V_32 + 1 ) ;
V_322 = (struct V_321 * ) ( V_303 + 1 ) ;
for ( V_323 = 0 ; V_323 < V_312 ; V_323 ++ , V_322 ++ )
F_173 ( V_322 , V_317 , V_319 , V_320 ) ;
F_129 ( V_2 , V_324 ) ;
F_129 ( V_2 , V_155 ) ;
F_27 ( V_2 , V_75 , V_8 -> V_46 ) ;
F_92 ( & V_8 -> V_172 ) ;
F_33 ( V_8 , V_2 ) ;
F_99 ( & V_8 -> V_172 ) ;
return 0 ;
}
static int F_174 ( struct V_310 * V_311 , struct V_7 * V_8 ,
struct V_316 * V_317 )
{
unsigned int V_325 = V_317 -> V_25 ;
unsigned int V_312 = V_317 -> V_312 ;
unsigned int V_323 , V_105 ;
int V_222 = 0 ;
struct V_318 * V_326 = V_317 -> V_327 ;
unsigned int V_328 = 0 ;
V_317 -> V_329 = V_8 -> V_46 ;
for ( V_323 = 0 ; V_323 < V_312 ; V_323 += V_105 , V_325 += V_105 ) {
V_105 = V_312 - V_323 ;
if ( V_105 > V_330 )
V_105 = V_330 ;
V_222 = F_172 ( V_311 , V_8 , V_317 , V_325 , V_105 ,
& V_326 , & V_328 ) ;
if ( V_222 < 0 )
break;
}
return V_222 ;
}
static int F_175 ( struct V_7 * V_8 , unsigned int V_74 ,
int V_331 , bool V_332 )
{
struct V_1 * V_2 ;
struct V_333 * V_32 ;
if ( ! V_331 || V_331 >= V_334 )
return 0 ;
V_2 = F_48 ( sizeof( * V_32 ) , 0 , V_258 ) ;
if ( ! V_2 )
return - V_190 ;
V_32 = (struct V_333 * ) V_2 -> V_33 ;
F_17 ( V_32 , V_8 -> V_74 ) ;
F_18 ( V_32 ) = F_45 ( F_20 ( V_335 , V_8 -> V_74 ) ) ;
V_32 -> V_336 = F_176 ( F_177 ( V_332 ) | F_178 ( V_8 -> V_22 ) ) ;
V_32 -> V_337 = F_176 ( 0 ) ;
V_32 -> V_338 = F_21 ( 0x3 << 8 ) ;
V_32 -> V_121 = F_21 ( V_331 << 8 ) ;
F_27 ( V_2 , V_339 , V_8 -> V_46 ) ;
F_23 ( 1 << V_48 | 1 << V_49 ,
L_54 , V_8 , V_8 -> V_74 , V_331 ) ;
F_36 ( V_8 -> V_13 -> V_45 [ V_8 -> V_46 ] , V_2 ) ;
return 0 ;
}
static int F_179 ( struct V_7 * V_8 , unsigned int V_74 ,
int V_340 , int V_341 , int V_332 )
{
struct V_1 * V_2 ;
struct V_333 * V_32 ;
if ( ! V_340 && ! V_341 )
return 0 ;
V_2 = F_48 ( sizeof( * V_32 ) , 0 , V_258 ) ;
if ( ! V_2 )
return - V_190 ;
V_8 -> V_342 = ( V_340 ? 4 : 0 ) ;
V_8 -> V_237 = ( V_341 ? 4 : 0 ) ;
V_32 = (struct V_333 * ) V_2 -> V_33 ;
F_17 ( V_32 , V_74 ) ;
F_18 ( V_32 ) = F_45 ( F_20 ( V_335 , V_74 ) ) ;
V_32 -> V_336 = F_176 ( F_177 ( V_332 ) | F_178 ( V_8 -> V_22 ) ) ;
V_32 -> V_337 = F_176 ( 0 ) ;
V_32 -> V_338 = F_21 ( 0x3 << 4 ) ;
V_32 -> V_121 = F_21 ( ( ( V_340 ? V_343 : 0 ) |
( V_341 ? V_344 : 0 ) ) << 4 ) ;
F_27 ( V_2 , V_339 , V_8 -> V_46 ) ;
F_23 ( 1 << V_48 | 1 << V_49 ,
L_55 , V_8 , V_8 -> V_74 , V_340 , V_341 ) ;
F_36 ( V_8 -> V_13 -> V_45 [ V_8 -> V_46 ] , V_2 ) ;
return 0 ;
}
static struct V_310 * F_180 ( struct V_162 * V_13 )
{
return (struct V_310 * ) ( * ( (struct V_11 * )
( F_5 ( V_13 ) ) ) -> V_345 ) ;
}
static int F_181 ( struct V_162 * V_13 )
{
struct V_11 * V_12 = F_5 ( V_13 ) ;
struct V_260 * V_261 = V_13 -> V_45 [ 0 ] ;
struct V_346 V_347 ;
unsigned int V_348 ;
int V_323 ;
if ( ! V_12 -> V_349 -> V_350 . V_194 ) {
F_182 ( L_56 , V_261 -> V_270 ) ;
return - V_351 ;
}
V_13 -> V_57 |= V_352 ;
V_348 = V_12 -> V_349 -> V_350 . V_194 >> V_313 ;
memset ( & V_347 , 0 , sizeof( struct V_346 ) ) ;
for ( V_323 = 0 ; V_323 < 4 ; V_323 ++ )
V_347 . V_353 [ V_323 ] = ( V_12 -> V_354 >> ( V_323 << 3 ) )
& 0xF ;
F_183 ( V_12 -> V_355 , & V_347 ) ;
F_184 ( V_12 -> V_345 , V_13 , & V_347 , V_348 ,
V_12 -> V_356 , V_12 -> V_349 -> V_350 . V_357 , 2 ) ;
V_13 -> V_358 = F_179 ;
V_13 -> V_359 = F_175 ;
V_13 -> V_360 = F_174 ;
V_13 -> V_361 = F_185 (unsigned int, ULP2_MAX_PDU_PAYLOAD,
lldi->iscsi_iolen - ISCSI_PDU_NONPAYLOAD_LEN) ;
V_13 -> V_362 = F_185 (unsigned int, ULP2_MAX_PDU_PAYLOAD,
lldi->iscsi_iolen - ISCSI_PDU_NONPAYLOAD_LEN) ;
V_13 -> F_180 = F_180 ;
return 0 ;
}
static void * F_186 ( const struct V_11 * V_12 )
{
struct V_162 * V_13 ;
struct V_280 * V_363 ;
int V_323 , V_288 ;
V_13 = F_187 ( sizeof( * V_12 ) , V_12 -> V_364 ) ;
if ( ! V_13 ) {
F_31 ( L_57 , V_12 ) ;
return NULL ;
}
F_31 ( L_58 ,
V_13 , V_12 -> V_15 , V_12 -> V_364 ,
V_12 -> V_45 [ 0 ] -> V_270 , V_12 -> V_276 , V_12 -> V_275 ,
V_12 -> V_278 , V_12 -> V_150 ) ;
for ( V_323 = 0 ; V_323 < V_12 -> V_278 ; V_323 ++ )
F_23 ( 1 << V_365 ,
L_59 ,
V_13 , V_323 , V_12 -> V_279 [ V_323 ] ) ;
memcpy ( F_5 ( V_13 ) , V_12 , sizeof( * V_12 ) ) ;
V_13 -> V_57 = V_366 ;
V_13 -> V_367 = V_12 -> V_367 ;
V_13 -> V_45 = V_12 -> V_45 ;
V_13 -> V_364 = V_12 -> V_364 ;
V_13 -> V_179 = V_12 -> V_179 ;
V_13 -> V_368 = V_369 ;
V_13 -> V_370 = V_371 ;
V_13 -> V_372 = V_373 ;
V_13 -> V_374 = sizeof( struct V_227 ) ;
V_13 -> V_375 = & V_376 ;
V_13 -> V_122 = F_188 ( F_155 ( V_12 -> V_45 [ 0 ] ) )
<< V_377 ;
F_31 ( L_60 ,
V_13 , V_12 -> V_45 [ 0 ] -> V_270 , V_13 -> V_122 ) ;
V_288 = F_181 ( V_13 ) ;
if ( V_288 ) {
F_31 ( L_61 , V_13 ) ;
goto V_378;
}
V_288 = F_160 ( V_13 ) ;
if ( V_288 ) {
F_31 ( L_62 , V_13 ) ;
goto V_378;
}
V_288 = F_189 ( V_13 , V_379 , V_380 ,
& V_381 , V_382 ) ;
if ( V_288 )
goto V_378;
for ( V_323 = 0 ; V_323 < V_13 -> V_364 ; V_323 ++ ) {
V_363 = F_157 ( V_12 -> V_45 [ V_323 ] ) ;
V_13 -> V_383 [ V_323 ] -> V_46 = V_363 -> V_46 ;
}
return V_13 ;
V_378:
F_190 ( V_13 ) ;
return F_191 ( - V_190 ) ;
}
static int F_192 ( void * V_78 , const V_65 * V_384 ,
const struct V_385 * V_386 )
{
const struct V_163 * V_93 ;
struct V_1 * V_2 ;
unsigned int V_387 ;
struct V_162 * V_13 = V_78 ;
if ( V_386 == NULL ) {
unsigned int V_3 = 64 - sizeof( struct V_388 ) - 8 ;
V_2 = F_48 ( V_3 , 0 , V_98 ) ;
if ( ! V_2 )
goto V_389;
F_193 ( V_2 , & V_384 [ 1 ] , V_3 ) ;
} else {
if ( F_38 ( * ( V_390 * ) V_384 != * ( V_390 * ) V_386 -> V_391 ) ) {
F_31 ( L_63 ,
V_386 -> V_391 , F_194 ( * V_384 ) ,
F_194 ( * ( V_392 * ) V_386 -> V_391 ) ,
V_386 -> V_393 ) ;
return 0 ;
}
V_2 = F_195 ( V_386 , V_394 , V_394 ) ;
if ( F_38 ( ! V_2 ) )
goto V_389;
}
V_93 = (struct V_163 * ) V_2 -> V_80 ;
V_387 = V_93 -> V_395 . V_396 ;
F_23 ( 1 << V_48 ,
L_64 ,
V_13 , V_387 , V_93 -> V_395 . V_397 , F_85 ( V_93 -> V_395 . V_397 ) , V_2 ) ;
if ( V_398 [ V_387 ] )
V_398 [ V_387 ] ( V_13 , V_2 ) ;
else {
F_88 ( L_65 , V_387 ) ;
F_100 ( V_2 ) ;
}
return 0 ;
V_389:
F_23 ( 1 << V_48 , L_66 ) ;
return 1 ;
}
static int F_196 ( void * V_78 , enum V_399 V_56 )
{
struct V_162 * V_13 = V_78 ;
switch ( V_56 ) {
case V_400 :
F_31 ( L_67 , V_13 ) ;
break;
case V_401 :
F_31 ( L_68 , V_13 ) ;
break;
case V_402 :
F_31 ( L_69 , V_13 ) ;
break;
case V_403 :
F_31 ( L_70 , V_13 ) ;
F_190 ( V_13 ) ;
break;
default:
F_31 ( L_71 , V_13 , V_56 ) ;
break;
}
return 0 ;
}
static int T_2 F_197 ( void )
{
int V_288 ;
F_198 ( V_404 L_72 , V_405 ) ;
V_288 = F_199 ( & V_376 , & V_382 ) ;
if ( V_288 < 0 )
return V_288 ;
F_200 ( V_406 , & V_407 ) ;
return 0 ;
}
static void T_3 F_201 ( void )
{
F_202 ( V_406 ) ;
F_203 ( V_366 ) ;
F_204 ( & V_376 , & V_382 ) ;
}
