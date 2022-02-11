static inline void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
const struct V_4 * V_5 )
{
V_2 -> V_6 = V_3 ;
}
static inline int F_2 ( const struct V_1 * V_2 )
{
return V_2 -> V_7 <= ( V_8 -
sizeof( struct V_9 ) ) ;
}
static void F_3 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_4 ( V_5 -> V_14 ) ;
int V_15 = F_5 ( V_5 -> V_16 ) ;
unsigned long long V_17 ;
unsigned int V_18 ;
unsigned int V_19 = ( ( unsigned int ) V_5 -> V_20 ) |
( ( ( unsigned int ) V_5 -> V_21 ) << 14 ) ;
V_17 = F_6 ( 1 ) |
F_7 ( V_15 ) |
F_8 ( V_5 -> V_16 ) |
F_9 ( ( (struct V_10 * ) V_5 -> V_22 ) -> V_23 ) |
F_10 ( V_5 -> V_24 ) |
F_11 ( V_5 -> V_25 ) |
F_12 ( V_26 ) |
F_13 ( V_27 >> 10 ) ;
V_18 = F_14 ( 0 ) |
V_28 |
( 1 << 20 ) |
F_15 ( V_5 -> V_21 ) ;
if ( F_16 ( V_13 -> V_29 ) ) {
struct V_30 * V_31 =
(struct V_30 * ) V_2 -> V_32 ;
F_17 ( V_31 , 0 ) ;
F_18 ( V_31 ) = F_19 ( F_20 ( V_33 ,
V_19 ) ) ;
V_31 -> V_34 = V_5 -> V_35 . V_36 ;
V_31 -> V_37 = V_5 -> V_38 . V_36 ;
V_31 -> V_39 = V_5 -> V_35 . V_40 . V_41 ;
V_31 -> V_42 = V_5 -> V_38 . V_40 . V_41 ;
V_31 -> V_17 = F_21 ( V_17 ) ;
V_31 -> V_43 = F_19 ( F_22 (
V_5 -> V_14 -> V_44 [ V_5 -> V_45 ] ,
V_5 -> V_22 ) ) ;
V_18 |= 1 << 22 ;
V_31 -> V_18 = F_19 ( V_18 ) ;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_1 ,
V_5 , & V_31 -> V_39 , F_24 ( V_31 -> V_34 ) ,
& V_31 -> V_42 , F_24 ( V_31 -> V_37 ) ,
V_5 -> V_20 , V_5 -> V_21 ) ;
} else {
struct V_48 * V_31 =
(struct V_48 * ) V_2 -> V_32 ;
F_17 ( V_31 , 0 ) ;
F_18 ( V_31 ) = F_19 ( F_20 ( V_33 ,
V_19 ) ) ;
V_31 -> V_34 = V_5 -> V_35 . V_36 ;
V_31 -> V_37 = V_5 -> V_38 . V_36 ;
V_31 -> V_39 = V_5 -> V_35 . V_40 . V_41 ;
V_31 -> V_42 = V_5 -> V_38 . V_40 . V_41 ;
V_31 -> V_17 = F_21 ( V_17 ) ;
V_31 -> V_43 = F_21 ( F_25 (
F_22 (
V_5 -> V_14 -> V_44 [ V_5 -> V_45 ] ,
V_5 -> V_22 ) ) ) ;
V_18 |= 1 << 31 ;
V_31 -> V_18 = F_19 ( V_18 ) ;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_2 ,
V_5 , & V_31 -> V_39 , F_24 ( V_31 -> V_34 ) ,
& V_31 -> V_42 , F_24 ( V_31 -> V_37 ) ,
V_5 -> V_20 , V_5 -> V_21 ) ;
}
F_26 ( V_2 , V_49 , V_5 -> V_45 ) ;
F_27 ( V_5 -> V_14 -> V_44 [ V_5 -> V_45 ] , V_2 , V_5 -> V_22 ) ;
}
static void F_28 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_50 ;
struct V_51 * V_31 = (struct V_51 * ) V_2 -> V_32 ;
unsigned int V_52 = V_5 -> V_52 ;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_3 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 ) ;
V_5 -> V_50 = NULL ;
F_26 ( V_2 , V_55 , V_5 -> V_45 ) ;
F_17 ( V_31 , V_52 ) ;
F_18 ( V_31 ) = F_19 ( F_20 ( V_56 , V_52 ) ) ;
V_31 -> V_57 = 0 ;
F_29 ( V_5 , V_2 ) ;
if ( V_5 -> V_53 >= V_58 )
F_30 ( V_5 , 1 ) ;
}
static void F_31 ( void * V_59 , struct V_1 * V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) V_59 ;
struct V_60 * V_31 ;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_4 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 ) ;
V_31 = (struct V_60 * ) V_2 -> V_61 ;
V_31 -> V_62 = V_63 ;
F_32 ( V_5 -> V_14 -> V_44 [ V_5 -> V_45 ] , V_2 ) ;
}
static void F_33 ( struct V_4 * V_5 )
{
struct V_60 * V_31 ;
struct V_1 * V_2 = V_5 -> V_60 ;
if ( F_34 ( V_5 -> V_53 == V_64 ) || ! V_2 || ! V_5 -> V_14 )
return;
F_35 ( V_5 , V_64 ) ;
F_36 ( V_5 , V_65 ) ;
F_37 ( V_5 ) ;
V_5 -> V_60 = NULL ;
V_31 = (struct V_60 * ) V_2 -> V_32 ;
F_1 ( V_2 , V_55 , V_5 ) ;
V_31 -> V_62 = V_66 ;
F_38 ( V_2 , V_5 , F_31 ) ;
F_17 ( V_31 , V_5 -> V_52 ) ;
F_18 ( V_31 ) = F_19 ( F_20 ( V_67 , V_5 -> V_52 ) ) ;
V_31 -> V_68 = F_39 ( V_5 -> V_69 ) ;
V_31 -> V_70 = ! F_40 ( V_5 , V_71 ) ;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_5 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 , V_5 -> V_69 ,
V_31 -> V_70 ) ;
F_27 ( V_5 -> V_14 -> V_44 [ V_5 -> V_45 ] , V_2 , V_5 -> V_22 ) ;
}
static void F_41 ( struct V_4 * V_5 , int V_72 )
{
struct V_1 * V_2 = V_5 -> V_73 ;
struct V_73 * V_74 = (struct V_73 * ) V_2 -> V_32 ;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_6 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 , V_72 ) ;
V_5 -> V_73 = NULL ;
F_1 ( V_2 , V_55 , V_5 ) ;
F_17 ( V_74 , V_5 -> V_52 ) ;
F_18 ( V_74 ) = F_19 ( F_20 ( V_75 , V_5 -> V_52 ) ) ;
V_74 -> V_62 = V_72 ;
F_32 ( V_5 -> V_14 -> V_44 [ V_5 -> V_45 ] , V_2 ) ;
}
static T_1 F_42 ( struct V_4 * V_5 , T_1 V_76 )
{
struct V_1 * V_2 ;
struct V_77 * V_31 ;
F_23 ( 1 << V_46 | 1 << V_78 ,
L_7 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 , V_76 ) ;
V_2 = F_43 ( sizeof( * V_31 ) , 0 , V_79 ) ;
if ( ! V_2 ) {
F_44 ( L_8 , V_5 , V_76 ) ;
return 0 ;
}
V_31 = (struct V_77 * ) V_2 -> V_32 ;
F_26 ( V_2 , V_80 , V_5 -> V_45 ) ;
F_17 ( V_31 , V_5 -> V_52 ) ;
F_18 ( V_31 ) = F_19 ( F_20 ( V_81 ,
V_5 -> V_52 ) ) ;
V_31 -> V_82 = F_19 ( F_45 ( V_76 ) | F_46 ( 1 ) ) ;
F_32 ( V_5 -> V_14 -> V_44 [ V_5 -> V_45 ] , V_2 ) ;
return V_76 ;
}
static inline unsigned int F_47 ( unsigned int V_83 )
{
V_83 -- ;
return ( 3 * V_83 ) / 2 + ( V_83 & 1 ) + 2 ;
}
static inline unsigned int F_48 ( const struct V_1 * V_2 )
{
unsigned int V_84 , V_85 ;
if ( F_2 ( V_2 ) )
return F_49 ( V_2 -> V_7 , 8 ) ;
V_84 = F_50 ( V_2 ) / 8 ;
V_85 = F_51 ( V_2 ) -> V_86 ;
if ( F_52 ( V_2 ) != F_53 ( V_2 ) )
V_85 ++ ;
return V_84 + F_47 ( V_85 ) ;
}
static inline void F_54 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_87 * V_88 ;
int V_89 , V_90 ;
V_89 = 80 ;
V_2 = F_43 ( V_89 , 0 , V_79 ) ;
V_88 = (struct V_87 * ) V_2 -> V_32 ;
V_88 -> V_91 =
F_39 ( F_55 ( V_92 ) | F_56 ( 8 ) ) ;
V_88 -> V_93 =
F_39 ( F_57 ( F_49 ( 72 , 16 ) ) |
F_58 ( V_5 -> V_52 ) ) ;
V_88 -> V_94 [ 0 ] . V_95 = V_96 ;
V_88 -> V_94 [ 0 ] . V_97 = F_39 ( V_5 -> V_14 -> V_98 ) ;
V_88 -> V_94 [ 1 ] . V_95 = V_99 ;
V_88 -> V_94 [ 1 ] . V_97 = F_39 ( V_5 -> V_24 ) ;
V_88 -> V_94 [ 2 ] . V_95 = V_100 ;
V_88 -> V_94 [ 2 ] . V_97 = F_39 ( V_5 -> V_24 ) ;
V_88 -> V_94 [ 3 ] . V_95 = V_101 ;
V_88 -> V_94 [ 3 ] . V_97 = F_39 ( V_5 -> V_21 ) ;
V_88 -> V_94 [ 4 ] . V_95 = V_102 ;
V_88 -> V_94 [ 4 ] . V_97 = F_39 ( V_5 -> V_69 ) ;
V_88 -> V_94 [ 5 ] . V_95 = V_103 ;
V_88 -> V_94 [ 5 ] . V_97 = F_39 ( V_5 -> V_104 ) ;
V_88 -> V_94 [ 6 ] . V_95 = V_105 ;
V_88 -> V_94 [ 6 ] . V_97 = F_39 ( V_106 ) ;
V_88 -> V_94 [ 7 ] . V_95 = V_107 ;
V_88 -> V_94 [ 7 ] . V_97 = F_39 ( V_5 -> V_108 ) ;
V_88 -> V_94 [ 8 ] . V_95 = 0 ;
V_88 -> V_94 [ 8 ] . V_97 = 0 ;
for ( V_90 = 0 ; V_90 < 9 ; V_90 ++ ) {
V_88 -> V_94 [ V_90 ] . V_109 [ 0 ] = 0 ;
V_88 -> V_94 [ V_90 ] . V_109 [ 1 ] = 0 ;
V_88 -> V_94 [ V_90 ] . V_109 [ 2 ] = 0 ;
}
F_1 ( V_2 , V_55 , V_5 ) ;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_9 ,
V_5 , V_5 -> V_52 , 0 , V_5 -> V_24 , V_5 -> V_21 ,
V_5 -> V_69 , V_5 -> V_104 , V_106 ,
V_5 -> V_108 ) ;
F_32 ( V_5 -> V_14 -> V_44 [ V_5 -> V_45 ] , V_2 ) ;
}
static inline void F_59 ( struct V_4 * V_5 , struct V_1 * V_2 ,
int V_110 , int V_7 , T_1 V_76 , int V_111 )
{
struct V_9 * V_31 ;
unsigned int V_112 = F_60 ( V_2 ) & 3 ;
unsigned int V_113 = 0 ;
V_31 = (struct V_9 * ) F_61 ( V_2 , sizeof( * V_31 ) ) ;
if ( F_2 ( V_2 ) ) {
V_31 -> V_114 = F_39 ( F_55 ( V_115 ) |
F_62 ( 1 ) |
F_63 ( V_110 ) ) ;
V_31 -> V_93 = F_39 ( F_58 ( V_5 -> V_52 ) |
F_57 ( V_76 ) ) ;
} else {
V_31 -> V_114 =
F_19 ( F_55 ( V_115 ) |
F_62 ( 1 ) |
F_63 ( 0 ) ) ;
V_31 -> V_93 =
F_19 ( F_58 ( V_5 -> V_52 ) |
F_57 ( V_76 ) ) ;
}
if ( V_112 )
V_113 = F_64 ( V_116 ) |
F_65 ( V_112 ) ;
V_31 -> V_117 = F_39 ( V_113 |
F_66 ( F_67 ( & V_5 -> V_118 ) ? 0 : 1 ) ) ;
V_31 -> V_119 = F_39 ( V_7 ) ;
if ( ! F_40 ( V_5 , V_71 ) )
F_36 ( V_5 , V_71 ) ;
}
static void F_68 ( void * V_59 , struct V_1 * V_2 )
{
F_69 ( V_2 ) ;
}
static int F_30 ( struct V_4 * V_5 , int V_120 )
{
int V_121 = 0 ;
struct V_1 * V_2 ;
if ( F_34 ( V_5 -> V_53 < V_58 ||
V_5 -> V_53 == V_122 || V_5 -> V_53 >= V_64 ) ) {
F_23 ( 1 << V_46 | 1 << V_47 |
1 << V_123 ,
L_10 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 ) ;
return 0 ;
}
while ( V_5 -> V_124 && ( V_2 = F_67 ( & V_5 -> V_118 ) ) != NULL ) {
int V_110 = V_2 -> V_7 ;
int V_7 = V_2 -> V_7 ;
unsigned int V_125 ;
F_70 ( V_2 ) ;
if ( F_2 ( V_2 ) )
V_125 = F_49 ( V_110 +
sizeof( struct V_9 ) , 16 ) ;
else
V_125 = F_49 ( 8 * F_48 ( V_2 )
+ sizeof( struct V_9 ) ,
16 ) ;
if ( V_5 -> V_124 < V_125 ) {
F_23 ( 1 << V_123 ,
L_11 ,
V_5 , V_2 -> V_7 , V_2 -> V_126 ,
V_125 , V_5 -> V_124 ) ;
break;
}
F_71 ( V_2 , & V_5 -> V_118 ) ;
F_1 ( V_2 , V_55 , V_5 ) ;
V_2 -> V_127 = V_125 ;
V_5 -> V_124 -= V_125 ;
V_5 -> V_128 += V_125 ;
F_72 ( V_5 , V_2 ) ;
F_23 ( 1 << V_123 ,
L_12 ,
V_5 , V_2 -> V_7 , V_2 -> V_126 , V_125 ,
V_5 -> V_124 , V_5 -> V_128 ) ;
if ( F_73 ( F_74 ( V_2 , V_129 ) ) ) {
if ( ! F_40 ( V_5 , V_71 ) ) {
F_54 ( V_5 ) ;
V_2 -> V_127 += 5 ;
V_5 -> V_124 -= 5 ;
V_5 -> V_128 += 5 ;
}
V_7 += F_75 ( F_60 ( V_2 ) ) ;
F_59 ( V_5 , V_2 , V_110 , V_7 , V_125 ,
V_120 ) ;
V_5 -> V_69 += V_7 ;
F_76 ( V_2 , V_129 ) ;
}
V_121 += V_2 -> V_130 ;
F_38 ( V_2 , V_5 , F_68 ) ;
F_23 ( 1 << V_46 | 1 << V_123 ,
L_13 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 , V_2 , V_7 ) ;
F_27 ( V_5 -> V_14 -> V_44 [ V_5 -> V_45 ] , V_2 , V_5 -> V_22 ) ;
}
return V_121 ;
}
static inline void F_77 ( struct V_4 * V_5 )
{
struct V_12 * V_13 = F_4 ( V_5 -> V_14 ) ;
if ( F_40 ( V_5 , V_131 ) ) {
F_78 ( V_13 -> V_132 , V_5 -> V_20 ) ;
F_79 ( V_5 , V_131 ) ;
F_80 ( V_5 ) ;
}
}
static void F_81 ( struct V_133 * V_14 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_134 * V_31 = (struct V_134 * ) V_2 -> V_61 ;
unsigned short V_135 = F_24 ( V_31 -> V_135 ) ;
unsigned int V_52 = F_82 ( V_31 ) ;
unsigned int V_20 = F_83 ( F_84 ( V_31 -> V_136 ) ) ;
struct V_12 * V_13 = F_4 ( V_14 ) ;
struct V_137 * V_138 = V_13 -> V_132 ;
T_1 V_139 = F_85 ( V_31 -> V_139 ) ;
V_5 = F_86 ( V_138 , V_20 ) ;
if ( F_34 ( ! V_5 ) ) {
F_87 ( L_14 , V_20 , V_14 ) ;
goto V_140;
}
if ( V_5 -> V_20 != V_20 ) {
F_87 ( L_15 ,
V_20 , V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 , V_5 -> V_20 ) ;
goto V_140;
}
F_23 ( 1 << V_46 | 1 << V_47 ,
L_16 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_52 , V_20 , V_139 ) ;
F_88 ( V_5 ) ;
V_5 -> V_52 = V_52 ;
F_89 ( V_13 -> V_132 , V_5 , V_52 ) ;
F_36 ( V_5 , V_141 ) ;
F_77 ( V_5 ) ;
F_90 ( & V_5 -> V_142 ) ;
if ( F_34 ( V_5 -> V_53 != V_143 ) )
F_44 ( L_17 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 ) ;
if ( V_5 -> V_144 . V_145 ) {
F_91 ( & V_5 -> V_144 ) ;
V_5 -> V_144 . V_145 = NULL ;
}
V_5 -> V_146 = V_5 -> V_147 = V_5 -> V_104 = V_139 ;
if ( V_27 > ( V_148 << 10 ) )
V_5 -> V_147 -= V_27 - ( V_148 << 10 ) ;
V_5 -> V_108 = V_13 -> V_149 [ F_92 ( V_135 ) ] - 40 ;
if ( F_93 ( V_135 ) )
V_5 -> V_108 -= 12 ;
if ( V_5 -> V_108 < 128 )
V_5 -> V_108 = 128 ;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_18 ,
V_5 , F_92 ( V_135 ) , V_5 -> V_108 ) ;
F_94 ( V_5 , F_84 ( V_31 -> V_150 ) , F_24 ( V_31 -> V_135 ) ) ;
if ( F_34 ( F_40 ( V_5 , V_151 ) ) )
F_33 ( V_5 ) ;
else {
if ( F_95 ( & V_5 -> V_118 ) )
F_30 ( V_5 , 0 ) ;
F_96 ( V_5 ) ;
}
F_97 ( & V_5 -> V_142 ) ;
V_140:
F_98 ( V_2 ) ;
}
static int F_99 ( int V_152 )
{
switch ( V_152 ) {
case V_153 :
return - V_154 ;
case V_155 :
return - V_156 ;
case V_157 :
return - V_158 ;
case V_159 :
return - V_160 ;
case V_161 :
return - V_162 ;
default:
return - V_163 ;
}
}
static void F_100 ( unsigned long V_61 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 = (struct V_4 * ) V_61 ;
struct V_12 * V_13 = F_4 ( V_5 -> V_14 ) ;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_19 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 ) ;
F_88 ( V_5 ) ;
F_90 ( & V_5 -> V_142 ) ;
V_2 = F_43 ( F_16 ( V_13 -> V_29 ) ?
sizeof( struct V_30 ) :
sizeof( struct V_48 ) ,
0 , V_79 ) ;
if ( ! V_2 )
F_101 ( V_5 , - V_160 ) ;
else {
V_2 -> V_164 = (struct V_165 * ) V_5 ;
F_38 ( V_2 , V_5 ,
V_166 ) ;
F_3 ( V_5 , V_2 , V_5 -> V_22 ) ;
}
F_97 ( & V_5 -> V_142 ) ;
F_80 ( V_5 ) ;
}
static void F_102 ( struct V_133 * V_14 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_167 * V_74 = (struct V_167 * ) V_2 -> V_61 ;
unsigned int V_52 = F_82 ( V_74 ) ;
unsigned int V_20 =
F_83 ( F_103 ( F_85 ( V_74 -> V_168 ) ) ) ;
unsigned int V_152 = F_104 ( F_85 ( V_74 -> V_168 ) ) ;
struct V_12 * V_13 = F_4 ( V_14 ) ;
struct V_137 * V_138 = V_13 -> V_132 ;
V_5 = F_86 ( V_138 , V_20 ) ;
if ( F_34 ( ! V_5 ) ) {
F_87 ( L_20 , V_20 , V_52 ) ;
goto V_140;
}
F_44 ( L_21 ,
& V_5 -> V_35 . V_40 . V_41 , F_24 ( V_5 -> V_35 . V_36 ) ,
& V_5 -> V_38 . V_40 . V_41 , F_24 ( V_5 -> V_38 . V_36 ) ,
V_20 , V_52 , V_152 , V_5 , V_5 -> V_53 , V_5 -> V_54 ) ;
if ( V_152 == V_169 )
goto V_140;
if ( V_152 && V_152 != V_159 &&
V_152 != V_161 &&
V_152 != V_155 )
F_105 ( V_13 -> V_132 , V_5 -> V_45 , F_82 ( V_74 ) ) ;
F_88 ( V_5 ) ;
F_90 ( & V_5 -> V_142 ) ;
if ( V_152 == V_161 &&
V_5 -> V_144 . V_145 != F_100 ) {
V_5 -> V_144 . V_145 = F_100 ;
F_106 ( & V_5 -> V_144 , V_170 + V_171 / 2 ) ;
} else
F_101 ( V_5 ,
F_99 ( V_152 ) ) ;
F_97 ( & V_5 -> V_142 ) ;
F_80 ( V_5 ) ;
V_140:
F_98 ( V_2 ) ;
}
static void F_107 ( struct V_133 * V_14 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_172 * V_31 = (struct V_172 * ) V_2 -> V_61 ;
unsigned int V_52 = F_82 ( V_31 ) ;
struct V_12 * V_13 = F_4 ( V_14 ) ;
struct V_137 * V_138 = V_13 -> V_132 ;
V_5 = F_108 ( V_138 , V_52 ) ;
if ( F_34 ( ! V_5 ) ) {
F_87 ( L_22 , V_52 ) ;
goto V_140;
}
F_23 ( 1 << V_46 | 1 << V_47 ,
L_19 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 ) ;
F_109 ( V_5 ) ;
V_140:
F_98 ( V_2 ) ;
}
static void F_110 ( struct V_133 * V_14 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_173 * V_74 = (struct V_173 * ) V_2 -> V_61 ;
unsigned int V_52 = F_82 ( V_74 ) ;
struct V_12 * V_13 = F_4 ( V_14 ) ;
struct V_137 * V_138 = V_13 -> V_132 ;
V_5 = F_108 ( V_138 , V_52 ) ;
if ( F_34 ( ! V_5 ) ) {
F_87 ( L_22 , V_52 ) ;
goto V_140;
}
F_23 ( 1 << V_46 | 1 << V_47 ,
L_19 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 ) ;
F_111 ( V_5 , F_84 ( V_74 -> V_69 ) ) ;
V_140:
F_98 ( V_2 ) ;
}
static int F_112 ( struct V_4 * V_5 , int V_174 ,
int * V_175 )
{
switch ( V_174 ) {
case V_176 :
case V_153 :
return V_5 -> V_53 > V_58 ?
- V_177 : - V_178 ;
case V_179 :
case V_180 :
case V_181 :
case V_182 :
return - V_158 ;
default:
return - V_163 ;
}
}
static void F_113 ( struct V_133 * V_14 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_183 * V_31 = (struct V_183 * ) V_2 -> V_61 ;
unsigned int V_52 = F_82 ( V_31 ) ;
struct V_12 * V_13 = F_4 ( V_14 ) ;
struct V_137 * V_138 = V_13 -> V_132 ;
int V_72 = V_63 ;
V_5 = F_108 ( V_138 , V_52 ) ;
if ( F_34 ( ! V_5 ) ) {
F_87 ( L_22 , V_52 ) ;
goto V_140;
}
F_23 ( 1 << V_46 | 1 << V_47 ,
L_23 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 , V_31 -> V_152 ) ;
if ( V_31 -> V_152 == V_169 ||
V_31 -> V_152 == V_184 )
goto V_140;
F_88 ( V_5 ) ;
F_90 ( & V_5 -> V_142 ) ;
if ( ! F_40 ( V_5 , V_185 ) ) {
F_36 ( V_5 , V_185 ) ;
F_35 ( V_5 , V_64 ) ;
goto V_186;
}
F_79 ( V_5 , V_185 ) ;
F_41 ( V_5 , V_72 ) ;
if ( ! F_40 ( V_5 , V_65 ) ) {
V_5 -> V_187 = F_112 ( V_5 , V_31 -> V_152 , & V_72 ) ;
F_114 ( V_5 ) ;
}
V_186:
F_97 ( & V_5 -> V_142 ) ;
F_80 ( V_5 ) ;
V_140:
F_98 ( V_2 ) ;
}
static void F_115 ( struct V_133 * V_14 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_188 * V_74 = (struct V_188 * ) V_2 -> V_61 ;
unsigned int V_52 = F_82 ( V_74 ) ;
struct V_12 * V_13 = F_4 ( V_14 ) ;
struct V_137 * V_138 = V_13 -> V_132 ;
V_5 = F_108 ( V_138 , V_52 ) ;
if ( ! V_5 )
goto V_140;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_24 ,
V_74 -> V_152 , V_5 , V_5 ? V_5 -> V_53 : 0 ,
V_5 ? V_5 -> V_54 : 0UL ) ;
if ( V_74 -> V_152 == V_189 )
goto V_140;
F_116 ( V_5 ) ;
V_140:
F_98 ( V_2 ) ;
}
static void F_117 ( struct V_133 * V_14 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_190 * V_191 = (struct V_190 * ) V_2 -> V_61 ;
unsigned short V_192 = F_118 ( V_191 -> V_192 ) ;
unsigned int V_52 = F_82 ( V_191 ) ;
struct V_12 * V_13 = F_4 ( V_14 ) ;
struct V_137 * V_138 = V_13 -> V_132 ;
V_5 = F_108 ( V_138 , V_52 ) ;
if ( F_34 ( ! V_5 ) ) {
F_87 ( L_25 , V_52 ) ;
goto V_140;
}
F_23 ( 1 << V_46 | 1 << V_78 ,
L_26 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 , V_2 , V_2 -> V_7 ,
V_192 ) ;
F_90 ( & V_5 -> V_142 ) ;
if ( F_34 ( V_5 -> V_53 >= V_193 ) ) {
F_23 ( 1 << V_46 | 1 << V_47 ,
L_27 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 ) ;
if ( V_5 -> V_53 != V_64 )
goto V_194;
else
goto V_195;
}
F_119 ( V_2 ) = F_84 ( V_191 -> V_196 ) ;
F_120 ( V_2 ) = 0 ;
F_70 ( V_2 ) ;
F_121 ( V_2 , sizeof( * V_191 ) ) ;
F_122 ( V_2 , F_24 ( V_191 -> V_7 ) ) ;
if ( ! V_5 -> V_197 ) {
unsigned char * V_198 ;
unsigned int V_199 , V_110 , V_119 ;
F_23 ( 1 << V_46 | 1 << V_78 ,
L_28 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 , V_2 ) ;
V_5 -> V_197 = V_2 ;
F_123 ( V_2 , V_200 ) ;
if ( F_119 ( V_2 ) != V_5 -> V_104 ) {
F_44 ( L_29 ,
V_5 -> V_52 , F_119 ( V_2 ) ,
V_5 -> V_104 ) ;
goto V_194;
}
V_198 = V_2 -> V_61 ;
V_199 = F_24 ( V_191 -> V_7 ) ;
V_110 = F_84 ( * ( unsigned int * ) ( V_198 + 4 ) ) & 0xFFFFFF ;
V_119 = F_124 ( V_192 ) ;
if ( F_16 ( V_13 -> V_29 ) )
V_119 -= 40 ;
if ( ( V_199 + V_110 ) != V_119 ) {
F_44 ( L_30
L_31 ,
V_5 -> V_52 , V_119 , V_199 , V_110 ,
F_119 ( V_2 ) ) ;
goto V_194;
}
F_125 ( V_2 ) = ( V_199 + V_110 + 3 ) & ( ~ 0x3 ) ;
if ( V_110 )
F_125 ( V_2 ) += V_5 -> V_201 ;
V_5 -> V_104 += F_125 ( V_2 ) ;
F_23 ( 1 << V_46 | 1 << V_78 ,
L_32 ,
V_5 , V_2 , * V_198 , V_199 , V_110 ,
F_84 ( * ( ( unsigned int * ) ( V_198 + 16 ) ) ) ,
F_84 ( * ( ( unsigned int * ) ( V_198 + 24 ) ) ) ) ;
} else {
struct V_1 * V_202 = V_5 -> V_197 ;
F_123 ( V_202 , V_203 ) ;
F_23 ( 1 << V_46 | 1 << V_78 ,
L_33 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_2 , V_202 ) ;
}
F_126 ( & V_5 -> V_204 , V_2 ) ;
F_97 ( & V_5 -> V_142 ) ;
return;
V_194:
F_33 ( V_5 ) ;
V_195:
F_97 ( & V_5 -> V_142 ) ;
V_140:
F_98 ( V_2 ) ;
}
static void F_127 ( struct V_133 * V_14 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_1 * V_202 ;
struct V_205 * V_74 = (struct V_205 * ) V_2 -> V_61 ;
unsigned int V_52 = F_82 ( V_74 ) ;
struct V_12 * V_13 = F_4 ( V_14 ) ;
struct V_137 * V_138 = V_13 -> V_132 ;
unsigned int V_152 = F_84 ( V_74 -> V_206 ) ;
V_5 = F_108 ( V_138 , V_52 ) ;
if ( F_34 ( ! V_5 ) ) {
F_87 ( L_22 , V_52 ) ;
goto V_140;
}
F_23 ( 1 << V_46 | 1 << V_78 ,
L_34 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_2 , V_152 , V_5 -> V_197 ) ;
F_90 ( & V_5 -> V_142 ) ;
if ( F_34 ( V_5 -> V_53 >= V_193 ) ) {
F_23 ( 1 << V_46 | 1 << V_47 ,
L_27 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 ) ;
if ( V_5 -> V_53 != V_64 )
goto V_194;
else
goto V_195;
}
if ( ! V_5 -> V_197 ) {
F_87 ( L_35 , V_5 -> V_52 ) ;
goto V_194;
}
V_202 = V_5 -> V_197 ;
V_5 -> V_197 = NULL ;
F_128 ( V_202 ) = F_84 ( V_74 -> V_207 ) ;
if ( F_24 ( V_74 -> V_7 ) != F_125 ( V_202 ) )
F_44 ( L_36 ,
V_5 -> V_52 , F_24 ( V_74 -> V_7 ) , F_125 ( V_202 ) ) ;
if ( V_152 & ( 1 << V_208 ) ) {
F_44 ( L_37 ,
V_5 , V_202 , V_152 , F_120 ( V_202 ) ) ;
F_123 ( V_202 , V_209 ) ;
}
if ( V_152 & ( 1 << V_210 ) ) {
F_44 ( L_38 ,
V_5 , V_202 , V_152 , F_120 ( V_202 ) ) ;
F_123 ( V_202 , V_211 ) ;
}
if ( V_152 & ( 1 << V_212 ) ) {
F_23 ( 1 << V_78 ,
L_39 ,
V_5 , V_202 , V_152 ) ;
F_123 ( V_202 , V_213 ) ;
}
if ( ( V_152 & ( 1 << V_214 ) ) &&
! F_74 ( V_202 , V_203 ) ) {
F_23 ( 1 << V_78 ,
L_40 ,
V_5 , V_202 , V_152 ) ;
F_123 ( V_202 , V_215 ) ;
}
F_23 ( 1 << V_78 ,
L_41 ,
V_5 , V_202 , F_120 ( V_202 ) ) ;
F_123 ( V_202 , V_216 ) ;
F_129 ( V_5 ) ;
F_97 ( & V_5 -> V_142 ) ;
goto V_140;
V_194:
F_33 ( V_5 ) ;
V_195:
F_97 ( & V_5 -> V_142 ) ;
V_140:
F_98 ( V_2 ) ;
}
static void F_130 ( struct V_133 * V_14 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_217 * V_74 = (struct V_217 * ) V_2 -> V_61 ;
unsigned int V_52 = F_82 ( V_74 ) ;
struct V_12 * V_13 = F_4 ( V_14 ) ;
struct V_137 * V_138 = V_13 -> V_132 ;
V_5 = F_108 ( V_138 , V_52 ) ;
if ( F_34 ( ! V_5 ) )
F_87 ( L_22 , V_52 ) ;
else {
F_23 ( 1 << V_46 | 1 << V_47 ,
L_19 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 ) ;
F_131 ( V_5 , V_74 -> V_76 , F_84 ( V_74 -> V_218 ) ,
V_74 -> V_219 ) ;
}
F_98 ( V_2 ) ;
}
static void F_132 ( struct V_133 * V_14 , struct V_1 * V_2 )
{
struct V_220 * V_74 = (struct V_220 * ) V_2 -> V_61 ;
unsigned int V_52 = F_82 ( V_74 ) ;
struct V_12 * V_13 = F_4 ( V_14 ) ;
struct V_137 * V_138 = V_13 -> V_132 ;
struct V_4 * V_5 ;
V_5 = F_108 ( V_138 , V_52 ) ;
if ( ! V_5 )
F_87 ( L_25 , V_52 ) ;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_42 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 , V_74 -> V_152 ) ;
if ( V_74 -> V_152 != V_221 )
F_87 ( L_43 ,
V_5 , V_52 , V_74 -> V_152 ) ;
F_98 ( V_2 ) ;
}
static int F_133 ( struct V_4 * V_5 )
{
V_5 -> V_50 = F_43 ( sizeof( struct V_51 ) ,
0 , V_222 ) ;
if ( ! V_5 -> V_50 )
return - V_160 ;
V_5 -> V_60 = F_43 ( sizeof( struct V_60 ) ,
0 , V_222 ) ;
if ( ! V_5 -> V_60 )
goto V_223;
V_5 -> V_73 = F_43 ( sizeof( struct V_73 ) ,
0 , V_222 ) ;
if ( ! V_5 -> V_73 )
goto V_223;
return 0 ;
V_223:
F_134 ( V_5 ) ;
return - V_160 ;
}
static inline void F_135 ( struct V_4 * V_5 )
{
if ( V_5 -> V_22 ) {
F_136 ( V_5 -> V_22 ) ;
V_5 -> V_22 = NULL ;
F_80 ( V_5 ) ;
}
}
static void F_137 ( struct V_4 * V_5 )
{
struct V_12 * V_13 ;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_19 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 ) ;
F_134 ( V_5 ) ;
if ( V_5 -> V_124 != V_5 -> V_224 ) {
F_138 ( V_5 ) ;
F_139 ( V_5 ) ;
}
F_135 ( V_5 ) ;
if ( F_40 ( V_5 , V_131 ) )
F_77 ( V_5 ) ;
else if ( F_40 ( V_5 , V_141 ) ) {
V_13 = F_4 ( V_5 -> V_14 ) ;
F_105 ( V_13 -> V_132 , 0 , V_5 -> V_52 ) ;
F_79 ( V_5 , V_141 ) ;
F_80 ( V_5 ) ;
}
V_5 -> V_225 = NULL ;
V_5 -> V_14 = NULL ;
}
static int F_140 ( struct V_4 * V_5 )
{
struct V_133 * V_14 = V_5 -> V_14 ;
struct V_12 * V_13 = F_4 ( V_14 ) ;
struct V_226 * V_227 = V_14 -> V_44 [ V_5 -> V_45 ] ;
struct V_228 * V_229 = F_141 ( V_227 ) ;
struct V_1 * V_2 = NULL ;
struct V_230 * V_83 ;
unsigned int V_231 ;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_19 ,
V_5 , V_5 -> V_53 , V_5 -> V_54 , V_5 -> V_52 ) ;
V_5 -> V_20 = F_142 ( V_13 -> V_132 , V_5 ) ;
if ( V_5 -> V_20 < 0 ) {
F_87 ( L_44 , V_227 -> V_232 ) ;
return - V_233 ;
}
F_36 ( V_5 , V_131 ) ;
F_88 ( V_5 ) ;
V_83 = F_143 ( V_5 -> V_225 , & V_5 -> V_38 . V_40 . V_41 ) ;
if ( ! V_83 ) {
F_87 ( L_45 , V_227 -> V_232 ) ;
goto V_234;
}
V_5 -> V_22 = F_144 ( V_13 -> V_22 , V_83 , V_227 , 0 ) ;
if ( ! V_5 -> V_22 ) {
F_87 ( L_46 , V_227 -> V_232 ) ;
goto V_234;
}
F_88 ( V_5 ) ;
V_2 = F_43 ( F_16 ( V_13 -> V_29 ) ?
sizeof( struct V_30 ) :
sizeof( struct V_48 ) ,
0 , V_79 ) ;
if ( ! V_2 )
goto V_234;
V_2 -> V_164 = (struct V_165 * ) V_5 ;
F_38 ( V_2 , V_5 , V_166 ) ;
if ( ! V_5 -> V_235 )
V_5 -> V_235 = F_145 ( V_5 -> V_225 ) ;
F_146 ( V_13 -> V_149 , V_5 -> V_235 , & V_5 -> V_16 ) ;
V_5 -> V_24 = F_147 ( V_227 ) ;
V_5 -> V_25 = ( ( F_148 ( V_227 ) & 0x7F ) ) << 1 ;
V_231 = V_13 -> V_236 / V_13 -> V_237 ;
V_5 -> V_238 = F_149 ( V_227 ) * V_231 ;
V_231 = V_13 -> V_239 / V_13 -> V_237 ;
V_5 -> V_21 = V_13 -> V_240 [ F_149 ( V_227 ) * V_231 ] ;
V_5 -> V_224 = V_5 -> V_124 = V_13 -> V_124 ;
V_5 -> V_128 = 0 ;
F_139 ( V_5 ) ;
V_5 -> V_187 = 0 ;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_47 ,
V_5 , V_229 -> V_45 , V_227 -> V_232 , V_5 -> V_24 ,
V_5 -> V_238 , V_5 -> V_21 , V_5 -> V_235 , V_5 -> V_16 ,
V_5 -> V_25 ) ;
F_35 ( V_5 , V_143 ) ;
F_3 ( V_5 , V_2 , V_5 -> V_22 ) ;
F_150 ( V_83 ) ;
return 0 ;
V_234:
if ( V_83 )
F_150 ( V_83 ) ;
if ( V_2 )
F_98 ( V_2 ) ;
return - V_233 ;
}
int F_151 ( struct V_133 * V_14 )
{
int V_241 ;
if ( V_242 > V_243 )
V_242 = V_243 ;
V_241 = F_152 ( V_14 , V_244 ,
V_242 ) ;
if ( V_241 < 0 )
return V_241 ;
V_14 -> V_245 = F_137 ;
V_14 -> V_246 = F_30 ;
V_14 -> V_247 = F_33 ;
V_14 -> V_248 = F_28 ;
V_14 -> V_249 = F_42 ;
V_14 -> V_250 = F_133 ;
V_14 -> V_251 = F_140 ;
F_44 ( L_48 , V_14 ) ;
return 0 ;
}
static inline void F_153 ( struct V_12 * V_13 ,
struct V_252 * V_31 ,
unsigned int V_253 , unsigned int V_110 ,
unsigned int V_254 )
{
struct V_255 * V_256 = (struct V_255 * ) ( V_31 + 1 ) ;
F_154 ( V_31 , V_253 , 0 , 0 ) ;
if ( F_16 ( V_13 -> V_29 ) )
V_31 -> V_62 = F_39 ( F_155 ( V_257 ) |
( F_156 ( 1 ) ) ) ;
else
V_31 -> V_62 = F_39 ( F_155 ( V_257 ) |
( F_157 ( 1 ) ) ) ;
V_31 -> V_110 = F_39 ( F_158 ( V_110 >> 5 ) ) ;
V_31 -> V_258 = F_39 ( F_159 ( V_254 >> 5 ) ) ;
V_31 -> V_259 = F_39 ( F_49 ( V_253 - sizeof( V_31 -> V_260 ) , 16 ) ) ;
V_256 -> V_261 = F_39 ( F_155 ( V_262 ) ) ;
V_256 -> V_7 = F_39 ( V_110 ) ;
}
static int F_160 ( struct V_133 * V_14 , unsigned int V_45 ,
struct V_263 * V_264 , unsigned int V_23 ,
unsigned int V_265 ,
struct V_266 * V_267 ,
unsigned int V_268 )
{
struct V_269 * V_270 = V_14 -> V_270 ;
struct V_12 * V_13 = F_4 ( V_14 ) ;
struct V_1 * V_2 ;
struct V_252 * V_31 ;
struct V_255 * V_256 ;
struct V_271 * V_272 ;
unsigned int V_254 = V_23 * V_273 + V_270 -> V_274 ;
unsigned int V_110 = V_273 * V_265 ;
unsigned int V_253 = F_161 ( sizeof( struct V_252 ) +
sizeof( struct V_255 ) + V_110 , 16 ) ;
unsigned int V_90 ;
V_2 = F_43 ( V_253 , 0 , V_79 ) ;
if ( ! V_2 ) {
F_87 ( L_49 ,
V_14 , V_23 , V_265 ) ;
return - V_160 ;
}
V_31 = (struct V_252 * ) V_2 -> V_32 ;
F_1 ( V_2 , V_275 , NULL ) ;
F_153 ( V_13 , V_31 , V_253 , V_110 , V_254 ) ;
V_256 = (struct V_255 * ) ( V_31 + 1 ) ;
V_272 = (struct V_271 * ) ( V_256 + 1 ) ;
for ( V_90 = 0 ; V_90 < V_265 ; V_90 ++ , V_272 ++ , V_268 += V_276 ) {
if ( ! V_264 && ! V_267 )
F_162 ( V_272 ) ;
else
F_163 ( V_272 , V_264 , V_267 , V_268 ) ;
}
F_32 ( V_14 -> V_44 [ V_45 ] , V_2 ) ;
return 0 ;
}
static int F_164 ( struct V_4 * V_5 , struct V_263 * V_264 ,
unsigned int V_23 , unsigned int V_265 ,
struct V_266 * V_267 )
{
unsigned int V_90 , V_85 ;
int V_187 = 0 ;
for ( V_90 = 0 ; V_90 < V_265 ; V_90 += V_85 , V_23 += V_85 ) {
V_85 = V_265 - V_90 ;
if ( V_85 > V_277 )
V_85 = V_277 ;
V_187 = F_160 ( V_5 -> V_14 , V_5 -> V_45 , V_264 ,
V_23 , V_85 , V_267 , 4 * V_90 ) ;
if ( V_187 < 0 )
break;
}
return V_187 ;
}
static void F_165 ( struct V_278 * V_279 , unsigned int V_280 ,
unsigned int V_23 , unsigned int V_265 )
{
unsigned int V_90 , V_85 ;
int V_187 ;
for ( V_90 = 0 ; V_90 < V_265 ; V_90 += V_85 , V_23 += V_85 ) {
V_85 = V_265 - V_90 ;
if ( V_85 > V_277 )
V_85 = V_277 ;
V_187 = F_160 ( V_279 -> V_14 , V_279 -> V_45 , NULL ,
V_23 , V_85 , NULL , 0 ) ;
if ( V_187 < 0 )
break;
}
}
static int F_166 ( struct V_4 * V_5 , unsigned int V_52 ,
int V_281 , bool V_282 )
{
struct V_1 * V_2 ;
struct V_283 * V_31 ;
if ( ! V_281 || V_281 >= V_284 )
return 0 ;
V_2 = F_43 ( sizeof( * V_31 ) , 0 , V_222 ) ;
if ( ! V_2 )
return - V_160 ;
V_31 = (struct V_283 * ) V_2 -> V_32 ;
F_17 ( V_31 , V_5 -> V_52 ) ;
F_18 ( V_31 ) = F_39 ( F_20 ( V_285 , V_5 -> V_52 ) ) ;
V_31 -> V_286 = F_167 ( F_168 ( V_282 ) | F_169 ( V_5 -> V_21 ) ) ;
V_31 -> V_287 = F_167 ( 0 ) ;
V_31 -> V_288 = F_21 ( 0x3 << 8 ) ;
V_31 -> V_97 = F_21 ( V_281 << 8 ) ;
F_26 ( V_2 , V_275 , V_5 -> V_45 ) ;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_50 , V_5 , V_5 -> V_52 , V_281 ) ;
F_32 ( V_5 -> V_14 -> V_44 [ V_5 -> V_45 ] , V_2 ) ;
return 0 ;
}
static int F_170 ( struct V_4 * V_5 , unsigned int V_52 ,
int V_289 , int V_290 , int V_282 )
{
struct V_1 * V_2 ;
struct V_283 * V_31 ;
if ( ! V_289 && ! V_290 )
return 0 ;
V_2 = F_43 ( sizeof( * V_31 ) , 0 , V_222 ) ;
if ( ! V_2 )
return - V_160 ;
V_5 -> V_291 = ( V_289 ? 4 : 0 ) ;
V_5 -> V_201 = ( V_290 ? 4 : 0 ) ;
V_31 = (struct V_283 * ) V_2 -> V_32 ;
F_17 ( V_31 , V_52 ) ;
F_18 ( V_31 ) = F_39 ( F_20 ( V_285 , V_52 ) ) ;
V_31 -> V_286 = F_167 ( F_168 ( V_282 ) | F_169 ( V_5 -> V_21 ) ) ;
V_31 -> V_287 = F_167 ( 0 ) ;
V_31 -> V_288 = F_21 ( 0x3 << 4 ) ;
V_31 -> V_97 = F_21 ( ( ( V_289 ? V_292 : 0 ) |
( V_290 ? V_293 : 0 ) ) << 4 ) ;
F_26 ( V_2 , V_275 , V_5 -> V_45 ) ;
F_23 ( 1 << V_46 | 1 << V_47 ,
L_51 , V_5 , V_5 -> V_52 , V_289 , V_290 ) ;
F_32 ( V_5 -> V_14 -> V_44 [ V_5 -> V_45 ] , V_2 ) ;
return 0 ;
}
static int F_171 ( struct V_133 * V_14 )
{
struct V_12 * V_13 = F_4 ( V_14 ) ;
struct V_269 * V_270 = V_14 -> V_270 ;
unsigned int V_294 , V_295 [ 4 ] ;
int V_187 ;
if ( V_270 ) {
F_172 ( & V_270 -> V_296 ) ;
F_173 ( L_52 ,
V_14 , V_14 -> V_270 ) ;
return - V_297 ;
}
V_187 = F_174 ( V_14 , V_13 -> V_298 -> V_299 . V_300 ,
V_13 -> V_298 -> V_299 . V_300 + V_13 -> V_298 -> V_299 . V_301 - 1 ,
V_13 -> V_302 , V_13 -> V_302 ) ;
if ( V_187 < 0 )
return V_187 ;
V_270 = V_14 -> V_270 ;
V_294 = V_270 -> V_303 << V_304 ;
F_175 ( V_295 ) ;
F_176 ( V_13 -> V_44 [ 0 ] , V_294 , V_295 ) ;
V_14 -> V_305 = F_170 ;
V_14 -> V_306 = F_166 ;
V_14 -> V_307 = F_164 ;
V_14 -> V_308 = F_165 ;
F_44 ( L_53 ,
V_14 , V_14 -> V_309 . V_310 , V_14 -> V_309 . V_311 ,
V_14 -> V_309 . V_312 , V_14 -> V_309 . V_313 ) ;
F_44 ( L_54
L_55 ,
V_14 , V_270 -> V_314 , V_270 -> V_315 , V_270 -> V_303 ,
V_270 -> V_316 , V_270 -> V_317 , V_13 -> V_302 ,
V_270 -> V_318 , V_13 -> V_302 ) ;
F_44 ( L_56 ,
V_14 , V_14 -> V_319 , V_270 -> V_317 , V_14 -> V_320 ,
V_270 -> V_318 ) ;
return 0 ;
}
static void * F_177 ( const struct V_12 * V_13 )
{
struct V_133 * V_14 ;
struct V_228 * V_229 ;
int V_90 , V_241 ;
V_14 = F_178 ( sizeof( * V_13 ) , V_13 -> V_321 ) ;
if ( ! V_14 ) {
F_44 ( L_57 , V_13 ) ;
return NULL ;
}
F_44 ( L_58 ,
V_14 , V_13 -> V_29 , V_13 -> V_321 ,
V_13 -> V_44 [ 0 ] -> V_232 , V_13 -> V_237 , V_13 -> V_236 ,
V_13 -> V_239 , V_13 -> V_124 ) ;
for ( V_90 = 0 ; V_90 < V_13 -> V_239 ; V_90 ++ )
F_23 ( 1 << V_322 ,
L_59 ,
V_14 , V_90 , V_13 -> V_240 [ V_90 ] ) ;
memcpy ( F_4 ( V_14 ) , V_13 , sizeof( * V_13 ) ) ;
V_14 -> V_54 = V_323 ;
V_14 -> V_324 = V_13 -> V_324 ;
V_14 -> V_44 = V_13 -> V_44 ;
V_14 -> V_321 = V_13 -> V_321 ;
V_14 -> V_149 = V_13 -> V_149 ;
V_14 -> V_325 = V_326 ;
V_14 -> V_327 = V_106 ;
V_14 -> V_328 = V_27 ;
V_14 -> V_329 = V_330 ;
V_14 -> V_331 = V_332 ;
V_14 -> V_333 = sizeof( struct V_190 ) ;
V_14 -> V_334 = & V_335 ;
V_14 -> V_98 = F_179 ( F_148 ( V_13 -> V_44 [ 0 ] ) ) << 8 ;
F_44 ( L_60 ,
V_14 , V_13 -> V_44 [ 0 ] -> V_232 , V_14 -> V_98 ) ;
V_241 = F_171 ( V_14 ) ;
if ( V_241 ) {
F_44 ( L_61 , V_14 ) ;
goto V_336;
}
V_241 = F_151 ( V_14 ) ;
if ( V_241 ) {
F_44 ( L_62 , V_14 ) ;
goto V_336;
}
V_241 = F_180 ( V_14 , V_337 , V_338 ,
& V_339 , V_340 ) ;
if ( V_241 )
goto V_336;
for ( V_90 = 0 ; V_90 < V_14 -> V_321 ; V_90 ++ ) {
V_229 = F_141 ( V_13 -> V_44 [ V_90 ] ) ;
V_14 -> V_341 [ V_90 ] -> V_45 = V_229 -> V_45 ;
}
return V_14 ;
V_336:
F_181 ( V_14 ) ;
return F_182 ( - V_160 ) ;
}
static int F_183 ( void * V_59 , const T_2 * V_342 ,
const struct V_343 * V_344 )
{
const struct V_134 * V_74 ;
struct V_1 * V_2 ;
unsigned int V_345 ;
struct V_133 * V_14 = V_59 ;
if ( V_344 == NULL ) {
unsigned int V_7 = 64 - sizeof( struct V_346 ) - 8 ;
V_2 = F_43 ( V_7 , 0 , V_79 ) ;
if ( ! V_2 )
goto V_347;
F_184 ( V_2 , & V_342 [ 1 ] , V_7 ) ;
} else {
if ( F_34 ( * ( V_348 * ) V_342 != * ( V_348 * ) V_344 -> V_349 ) ) {
F_44 ( L_63 ,
V_344 -> V_349 , F_185 ( * V_342 ) ,
F_185 ( * ( V_350 * ) V_344 -> V_349 ) ,
V_344 -> V_351 ) ;
return 0 ;
}
V_2 = F_186 ( V_344 , V_352 , V_352 ) ;
if ( F_34 ( ! V_2 ) )
goto V_347;
}
V_74 = (struct V_134 * ) V_2 -> V_61 ;
V_345 = V_74 -> V_353 . V_354 ;
F_23 ( 1 << V_46 ,
L_64 ,
V_14 , V_345 , V_74 -> V_353 . V_355 , F_84 ( V_74 -> V_353 . V_355 ) , V_2 ) ;
if ( V_356 [ V_345 ] )
V_356 [ V_345 ] ( V_14 , V_2 ) ;
else {
F_87 ( L_65 , V_345 ) ;
F_98 ( V_2 ) ;
}
return 0 ;
V_347:
F_23 ( 1 << V_46 , L_66 ) ;
return 1 ;
}
static int F_187 ( void * V_59 , enum V_357 V_53 )
{
struct V_133 * V_14 = V_59 ;
switch ( V_53 ) {
case V_358 :
F_44 ( L_67 , V_14 ) ;
break;
case V_359 :
F_44 ( L_68 , V_14 ) ;
break;
case V_360 :
F_44 ( L_69 , V_14 ) ;
break;
case V_361 :
F_44 ( L_70 , V_14 ) ;
F_181 ( V_14 ) ;
break;
default:
F_44 ( L_71 , V_14 , V_53 ) ;
break;
}
return 0 ;
}
static int T_3 F_188 ( void )
{
int V_241 ;
F_189 ( V_362 L_72 , V_363 ) ;
V_241 = F_190 ( & V_335 , & V_340 ) ;
if ( V_241 < 0 )
return V_241 ;
F_191 ( V_364 , & V_365 ) ;
return 0 ;
}
static void T_4 F_192 ( void )
{
F_193 ( V_364 ) ;
F_194 ( V_323 ) ;
F_195 ( & V_335 , & V_340 ) ;
}
