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
struct V_12 * V_13 ;
int V_14 = F_4 ( V_5 -> V_15 ) ;
unsigned long long V_16 ;
unsigned int V_17 ;
unsigned int V_18 = ( ( unsigned int ) V_5 -> V_19 ) |
( ( ( unsigned int ) V_5 -> V_20 ) << 14 ) ;
V_16 = F_5 ( 1 ) |
F_6 ( V_14 ) |
F_7 ( V_5 -> V_15 ) |
F_8 ( ( (struct V_10 * ) V_5 -> V_21 ) -> V_22 ) |
F_9 ( V_5 -> V_23 ) |
F_10 ( V_5 -> V_24 ) |
F_11 ( V_25 ) |
F_12 ( V_26 >> 10 ) ;
V_17 = F_13 ( 0 ) |
V_27 |
( 1 << 20 ) | ( 1 << 22 ) |
F_14 ( V_5 -> V_20 ) ;
F_15 ( V_2 , V_28 , V_5 -> V_29 ) ;
V_13 = (struct V_12 * ) V_2 -> V_30 ;
F_16 ( V_13 , 0 ) ;
F_17 ( V_13 ) = F_18 ( F_19 ( V_31 ,
V_18 ) ) ;
V_13 -> V_32 = V_5 -> V_33 . V_34 ;
V_13 -> V_35 = V_5 -> V_36 . V_34 ;
V_13 -> V_37 = V_5 -> V_33 . V_38 . V_39 ;
V_13 -> V_40 = V_5 -> V_36 . V_38 . V_39 ;
V_13 -> V_16 = F_20 ( V_16 ) ;
V_13 -> V_41 = 0 ;
V_13 -> V_17 = F_18 ( V_17 ) ;
F_21 ( 1 << V_42 | 1 << V_43 ,
L_1 ,
V_5 , & V_13 -> V_37 , F_22 ( V_13 -> V_32 ) ,
& V_13 -> V_40 , F_22 ( V_13 -> V_35 ) ,
V_5 -> V_19 , V_5 -> V_20 ) ;
F_23 ( V_5 -> V_44 -> V_45 [ V_5 -> V_29 ] , V_2 , V_5 -> V_21 ) ;
}
static void F_24 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_46 ;
struct V_47 * V_13 = (struct V_47 * ) V_2 -> V_30 ;
unsigned int V_48 = V_5 -> V_48 ;
F_21 ( 1 << V_42 | 1 << V_43 ,
L_2 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 ) ;
V_5 -> V_46 = NULL ;
F_15 ( V_2 , V_51 , V_5 -> V_29 ) ;
F_16 ( V_13 , V_48 ) ;
F_17 ( V_13 ) = F_18 ( F_19 ( V_52 , V_48 ) ) ;
V_13 -> V_53 = 0 ;
F_25 ( V_5 , V_2 ) ;
if ( V_5 -> V_49 >= V_54 )
F_26 ( V_5 , 1 ) ;
}
static void F_27 ( void * V_55 , struct V_1 * V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) V_55 ;
struct V_56 * V_13 ;
F_21 ( 1 << V_42 | 1 << V_43 ,
L_3 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 ) ;
V_13 = (struct V_56 * ) V_2 -> V_57 ;
V_13 -> V_58 = V_59 ;
F_28 ( V_5 -> V_44 -> V_45 [ V_5 -> V_29 ] , V_2 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
struct V_56 * V_13 ;
struct V_1 * V_2 = V_5 -> V_56 ;
if ( F_30 ( V_5 -> V_49 == V_60 ) || ! V_2 || ! V_5 -> V_44 )
return;
F_31 ( V_5 , V_60 ) ;
F_32 ( V_5 , V_61 ) ;
F_33 ( V_5 ) ;
V_5 -> V_56 = NULL ;
V_13 = (struct V_56 * ) V_2 -> V_30 ;
F_1 ( V_2 , V_51 , V_5 ) ;
V_13 -> V_58 = V_62 ;
F_34 ( V_2 , V_5 , F_27 ) ;
F_16 ( V_13 , V_5 -> V_48 ) ;
F_17 ( V_13 ) = F_18 ( F_19 ( V_63 , V_5 -> V_48 ) ) ;
V_13 -> V_64 = F_35 ( V_5 -> V_65 ) ;
V_13 -> V_66 = ! F_36 ( V_5 , V_67 ) ;
F_21 ( 1 << V_42 | 1 << V_43 ,
L_4 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 , V_5 -> V_65 ,
V_13 -> V_66 ) ;
F_23 ( V_5 -> V_44 -> V_45 [ V_5 -> V_29 ] , V_2 , V_5 -> V_21 ) ;
}
static void F_37 ( struct V_4 * V_5 , int V_68 )
{
struct V_1 * V_2 = V_5 -> V_69 ;
struct V_69 * V_70 = (struct V_69 * ) V_2 -> V_30 ;
F_21 ( 1 << V_42 | 1 << V_43 ,
L_5 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 , V_68 ) ;
V_5 -> V_69 = NULL ;
F_1 ( V_2 , V_51 , V_5 ) ;
F_16 ( V_70 , V_5 -> V_48 ) ;
F_17 ( V_70 ) = F_18 ( F_19 ( V_71 , V_5 -> V_48 ) ) ;
V_70 -> V_58 = V_68 ;
F_28 ( V_5 -> V_44 -> V_45 [ V_5 -> V_29 ] , V_2 ) ;
}
static T_1 F_38 ( struct V_4 * V_5 , T_1 V_72 )
{
struct V_1 * V_2 ;
struct V_73 * V_13 ;
F_21 ( 1 << V_42 | 1 << V_74 ,
L_6 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 , V_72 ) ;
V_2 = F_39 ( sizeof( * V_13 ) , 0 , V_75 ) ;
if ( ! V_2 ) {
F_40 ( L_7 , V_5 , V_72 ) ;
return 0 ;
}
V_13 = (struct V_73 * ) V_2 -> V_30 ;
F_15 ( V_2 , V_76 , V_5 -> V_29 ) ;
F_16 ( V_13 , V_5 -> V_48 ) ;
F_17 ( V_13 ) = F_18 ( F_19 ( V_77 ,
V_5 -> V_48 ) ) ;
V_13 -> V_78 = F_18 ( F_41 ( V_72 ) | F_42 ( 1 ) ) ;
F_28 ( V_5 -> V_44 -> V_45 [ V_5 -> V_29 ] , V_2 ) ;
return V_72 ;
}
static inline unsigned int F_43 ( unsigned int V_79 )
{
V_79 -- ;
return ( 3 * V_79 ) / 2 + ( V_79 & 1 ) + 2 ;
}
static inline unsigned int F_44 ( const struct V_1 * V_2 )
{
unsigned int V_80 , V_81 ;
if ( F_2 ( V_2 ) )
return F_45 ( V_2 -> V_7 , 8 ) ;
V_80 = F_46 ( V_2 ) / 8 ;
V_81 = F_47 ( V_2 ) -> V_82 ;
if ( V_2 -> V_83 != V_2 -> V_84 )
V_81 ++ ;
return V_80 + F_43 ( V_81 ) ;
}
static inline void F_48 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_85 * V_86 ;
int V_87 , V_88 ;
V_87 = 80 ;
V_2 = F_39 ( V_87 , 0 , V_75 ) ;
V_86 = (struct V_85 * ) V_2 -> V_30 ;
V_86 -> V_89 =
F_35 ( F_49 ( V_90 ) | F_50 ( 8 ) ) ;
V_86 -> V_91 =
F_35 ( F_51 ( F_45 ( 72 , 16 ) ) |
F_52 ( V_5 -> V_48 ) ) ;
V_86 -> V_92 [ 0 ] . V_93 = V_94 ;
V_86 -> V_92 [ 0 ] . V_95 = F_35 ( V_5 -> V_44 -> V_96 ) ;
V_86 -> V_92 [ 1 ] . V_93 = V_97 ;
V_86 -> V_92 [ 1 ] . V_95 = F_35 ( V_5 -> V_23 ) ;
V_86 -> V_92 [ 2 ] . V_93 = V_98 ;
V_86 -> V_92 [ 2 ] . V_95 = F_35 ( V_5 -> V_23 ) ;
V_86 -> V_92 [ 3 ] . V_93 = V_99 ;
V_86 -> V_92 [ 3 ] . V_95 = F_35 ( V_5 -> V_20 ) ;
V_86 -> V_92 [ 4 ] . V_93 = V_100 ;
V_86 -> V_92 [ 4 ] . V_95 = F_35 ( V_5 -> V_65 ) ;
V_86 -> V_92 [ 5 ] . V_93 = V_101 ;
V_86 -> V_92 [ 5 ] . V_95 = F_35 ( V_5 -> V_102 ) ;
V_86 -> V_92 [ 6 ] . V_93 = V_103 ;
V_86 -> V_92 [ 6 ] . V_95 = F_35 ( V_104 ) ;
V_86 -> V_92 [ 7 ] . V_93 = V_105 ;
V_86 -> V_92 [ 7 ] . V_95 = F_35 ( V_5 -> V_106 ) ;
V_86 -> V_92 [ 8 ] . V_93 = 0 ;
V_86 -> V_92 [ 8 ] . V_95 = 0 ;
for ( V_88 = 0 ; V_88 < 9 ; V_88 ++ ) {
V_86 -> V_92 [ V_88 ] . V_107 [ 0 ] = 0 ;
V_86 -> V_92 [ V_88 ] . V_107 [ 1 ] = 0 ;
V_86 -> V_92 [ V_88 ] . V_107 [ 2 ] = 0 ;
}
F_1 ( V_2 , V_51 , V_5 ) ;
F_21 ( 1 << V_42 | 1 << V_43 ,
L_8 ,
V_5 , V_5 -> V_48 , 0 , V_5 -> V_23 , V_5 -> V_20 ,
V_5 -> V_65 , V_5 -> V_102 , V_104 ,
V_5 -> V_106 ) ;
F_28 ( V_5 -> V_44 -> V_45 [ V_5 -> V_29 ] , V_2 ) ;
}
static inline void F_53 ( struct V_4 * V_5 , struct V_1 * V_2 ,
int V_108 , int V_7 , T_1 V_72 , int V_109 )
{
struct V_9 * V_13 ;
unsigned int V_110 = F_54 ( V_2 ) & 3 ;
unsigned int V_111 = 0 ;
V_13 = (struct V_9 * ) F_55 ( V_2 , sizeof( * V_13 ) ) ;
if ( F_2 ( V_2 ) ) {
V_13 -> V_112 = F_35 ( F_49 ( V_113 ) |
F_56 ( 1 ) |
F_57 ( V_108 ) ) ;
V_13 -> V_91 = F_35 ( F_52 ( V_5 -> V_48 ) |
F_51 ( V_72 ) ) ;
} else {
V_13 -> V_112 =
F_18 ( F_49 ( V_113 ) |
F_56 ( 1 ) |
F_57 ( 0 ) ) ;
V_13 -> V_91 =
F_18 ( F_52 ( V_5 -> V_48 ) |
F_51 ( V_72 ) ) ;
}
if ( V_110 )
V_111 = F_58 ( V_114 ) |
F_59 ( V_110 ) ;
V_13 -> V_115 = F_35 ( V_111 ) |
F_60 ( F_61 ( & V_5 -> V_116 ) ? 0 : 1 ) ;
V_13 -> V_117 = F_35 ( V_7 ) ;
if ( ! F_36 ( V_5 , V_67 ) )
F_32 ( V_5 , V_67 ) ;
}
static void F_62 ( void * V_55 , struct V_1 * V_2 )
{
F_63 ( V_2 ) ;
}
static int F_26 ( struct V_4 * V_5 , int V_118 )
{
int V_119 = 0 ;
struct V_1 * V_2 ;
if ( F_30 ( V_5 -> V_49 < V_54 ||
V_5 -> V_49 == V_120 || V_5 -> V_49 >= V_60 ) ) {
F_21 ( 1 << V_42 | 1 << V_43 |
1 << V_121 ,
L_9 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 ) ;
return 0 ;
}
while ( V_5 -> V_122 && ( V_2 = F_61 ( & V_5 -> V_116 ) ) != NULL ) {
int V_108 = V_2 -> V_7 ;
int V_7 = V_2 -> V_7 ;
unsigned int V_123 ;
F_64 ( V_2 ) ;
if ( F_2 ( V_2 ) )
V_123 = F_45 ( V_108 +
sizeof( struct V_9 ) , 16 ) ;
else
V_123 = F_45 ( 8 * F_44 ( V_2 )
+ sizeof( struct V_9 ) ,
16 ) ;
if ( V_5 -> V_122 < V_123 ) {
F_21 ( 1 << V_121 ,
L_10 ,
V_5 , V_2 -> V_7 , V_2 -> V_124 ,
V_123 , V_5 -> V_122 ) ;
break;
}
F_65 ( V_2 , & V_5 -> V_116 ) ;
F_1 ( V_2 , V_51 , V_5 ) ;
V_2 -> V_125 = V_123 ;
V_5 -> V_122 -= V_123 ;
V_5 -> V_126 += V_123 ;
F_66 ( V_5 , V_2 ) ;
F_21 ( 1 << V_121 ,
L_11 ,
V_5 , V_2 -> V_7 , V_2 -> V_124 , V_123 ,
V_5 -> V_122 , V_5 -> V_126 ) ;
if ( F_67 ( F_68 ( V_2 , V_127 ) ) ) {
if ( ! F_36 ( V_5 , V_67 ) ) {
F_48 ( V_5 ) ;
V_2 -> V_125 += 5 ;
V_5 -> V_122 -= 5 ;
V_5 -> V_126 += 5 ;
}
V_7 += F_69 ( F_54 ( V_2 ) ) ;
F_53 ( V_5 , V_2 , V_108 , V_7 , V_123 ,
V_118 ) ;
V_5 -> V_65 += V_7 ;
F_70 ( V_2 , V_127 ) ;
}
V_119 += V_2 -> V_128 ;
F_34 ( V_2 , V_5 , F_62 ) ;
F_21 ( 1 << V_42 | 1 << V_121 ,
L_12 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 , V_2 , V_7 ) ;
F_23 ( V_5 -> V_44 -> V_45 [ V_5 -> V_29 ] , V_2 , V_5 -> V_21 ) ;
}
return V_119 ;
}
static inline void F_71 ( struct V_4 * V_5 )
{
struct V_129 * V_130 = F_72 ( V_5 -> V_44 ) ;
if ( F_36 ( V_5 , V_131 ) ) {
F_73 ( V_130 -> V_132 , V_5 -> V_19 ) ;
F_74 ( V_5 , V_131 ) ;
F_75 ( V_5 ) ;
}
}
static void F_76 ( struct V_133 * V_44 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_134 * V_13 = (struct V_134 * ) V_2 -> V_57 ;
unsigned short V_135 = F_22 ( V_13 -> V_135 ) ;
unsigned int V_48 = F_77 ( V_13 ) ;
unsigned int V_19 = F_78 ( F_79 ( V_13 -> V_136 ) ) ;
struct V_129 * V_130 = F_72 ( V_44 ) ;
struct V_137 * V_138 = V_130 -> V_132 ;
T_1 V_139 = F_80 ( V_13 -> V_139 ) ;
V_5 = F_81 ( V_138 , V_19 ) ;
if ( F_30 ( ! V_5 ) ) {
F_82 ( L_13 , V_19 , V_44 ) ;
goto V_140;
}
if ( V_5 -> V_19 != V_19 ) {
F_82 ( L_14 ,
V_19 , V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 , V_5 -> V_19 ) ;
goto V_140;
}
F_21 ( 1 << V_42 | 1 << V_43 ,
L_15 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_48 , V_19 , V_139 ) ;
F_83 ( V_5 ) ;
V_5 -> V_48 = V_48 ;
F_84 ( V_130 -> V_132 , V_5 , V_48 ) ;
F_32 ( V_5 , V_141 ) ;
F_71 ( V_5 ) ;
F_85 ( & V_5 -> V_142 ) ;
if ( F_30 ( V_5 -> V_49 != V_143 ) )
F_40 ( L_16 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 ) ;
if ( V_5 -> V_144 . V_145 ) {
F_86 ( & V_5 -> V_144 ) ;
V_5 -> V_144 . V_145 = NULL ;
}
V_5 -> V_146 = V_5 -> V_147 = V_5 -> V_102 = V_139 ;
if ( V_26 > ( V_148 << 10 ) )
V_5 -> V_147 -= V_26 - ( V_148 << 10 ) ;
V_5 -> V_106 = V_130 -> V_149 [ F_87 ( V_135 ) ] - 40 ;
if ( F_88 ( V_135 ) )
V_5 -> V_106 -= 12 ;
if ( V_5 -> V_106 < 128 )
V_5 -> V_106 = 128 ;
F_21 ( 1 << V_42 | 1 << V_43 ,
L_17 ,
V_5 , F_87 ( V_135 ) , V_5 -> V_106 ) ;
F_89 ( V_5 , F_79 ( V_13 -> V_150 ) , F_22 ( V_13 -> V_135 ) ) ;
if ( F_30 ( F_36 ( V_5 , V_151 ) ) )
F_29 ( V_5 ) ;
else {
if ( F_90 ( & V_5 -> V_116 ) )
F_26 ( V_5 , 0 ) ;
F_91 ( V_5 ) ;
}
F_92 ( & V_5 -> V_142 ) ;
V_140:
F_93 ( V_2 ) ;
}
static int F_94 ( int V_152 )
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
static void F_95 ( unsigned long V_57 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 = (struct V_4 * ) V_57 ;
F_21 ( 1 << V_42 | 1 << V_43 ,
L_18 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 ) ;
F_83 ( V_5 ) ;
F_85 ( & V_5 -> V_142 ) ;
V_2 = F_39 ( sizeof( struct V_12 ) , 0 , V_75 ) ;
if ( ! V_2 )
F_96 ( V_5 , - V_160 ) ;
else {
V_2 -> V_164 = (struct V_165 * ) V_5 ;
F_34 ( V_2 , V_5 ,
V_166 ) ;
F_3 ( V_5 , V_2 , V_5 -> V_21 ) ;
}
F_92 ( & V_5 -> V_142 ) ;
F_75 ( V_5 ) ;
}
static void F_97 ( struct V_133 * V_44 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_167 * V_70 = (struct V_167 * ) V_2 -> V_57 ;
unsigned int V_48 = F_77 ( V_70 ) ;
unsigned int V_19 =
F_78 ( F_98 ( F_80 ( V_70 -> V_168 ) ) ) ;
unsigned int V_152 = F_99 ( F_80 ( V_70 -> V_168 ) ) ;
struct V_129 * V_130 = F_72 ( V_44 ) ;
struct V_137 * V_138 = V_130 -> V_132 ;
V_5 = F_81 ( V_138 , V_19 ) ;
if ( F_30 ( ! V_5 ) ) {
F_82 ( L_19 , V_19 , V_48 ) ;
goto V_140;
}
F_40 ( L_20 ,
& V_5 -> V_33 . V_38 . V_39 , F_22 ( V_5 -> V_33 . V_34 ) ,
& V_5 -> V_36 . V_38 . V_39 , F_22 ( V_5 -> V_36 . V_34 ) ,
V_19 , V_48 , V_152 , V_5 , V_5 -> V_49 , V_5 -> V_50 ) ;
if ( V_152 == V_169 )
goto V_140;
if ( V_152 && V_152 != V_159 &&
V_152 != V_161 &&
V_152 != V_155 )
F_100 ( V_130 -> V_132 , V_5 -> V_29 , F_77 ( V_70 ) ) ;
F_83 ( V_5 ) ;
F_85 ( & V_5 -> V_142 ) ;
if ( V_152 == V_161 &&
V_5 -> V_144 . V_145 != F_95 ) {
V_5 -> V_144 . V_145 = F_95 ;
F_101 ( & V_5 -> V_144 , V_170 + V_171 / 2 ) ;
} else
F_96 ( V_5 ,
F_94 ( V_152 ) ) ;
F_92 ( & V_5 -> V_142 ) ;
F_75 ( V_5 ) ;
V_140:
F_93 ( V_2 ) ;
}
static void F_102 ( struct V_133 * V_44 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_172 * V_13 = (struct V_172 * ) V_2 -> V_57 ;
unsigned int V_48 = F_77 ( V_13 ) ;
struct V_129 * V_130 = F_72 ( V_44 ) ;
struct V_137 * V_138 = V_130 -> V_132 ;
V_5 = F_103 ( V_138 , V_48 ) ;
if ( F_30 ( ! V_5 ) ) {
F_82 ( L_21 , V_48 ) ;
goto V_140;
}
F_21 ( 1 << V_42 | 1 << V_43 ,
L_18 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 ) ;
F_104 ( V_5 ) ;
V_140:
F_93 ( V_2 ) ;
}
static void F_105 ( struct V_133 * V_44 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_173 * V_70 = (struct V_173 * ) V_2 -> V_57 ;
unsigned int V_48 = F_77 ( V_70 ) ;
struct V_129 * V_130 = F_72 ( V_44 ) ;
struct V_137 * V_138 = V_130 -> V_132 ;
V_5 = F_103 ( V_138 , V_48 ) ;
if ( F_30 ( ! V_5 ) ) {
F_82 ( L_21 , V_48 ) ;
goto V_140;
}
F_21 ( 1 << V_42 | 1 << V_43 ,
L_18 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 ) ;
F_106 ( V_5 , F_79 ( V_70 -> V_65 ) ) ;
V_140:
F_93 ( V_2 ) ;
}
static int F_107 ( struct V_4 * V_5 , int V_174 ,
int * V_175 )
{
switch ( V_174 ) {
case V_176 :
case V_153 :
return V_5 -> V_49 > V_54 ?
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
static void F_108 ( struct V_133 * V_44 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_183 * V_13 = (struct V_183 * ) V_2 -> V_57 ;
unsigned int V_48 = F_77 ( V_13 ) ;
struct V_129 * V_130 = F_72 ( V_44 ) ;
struct V_137 * V_138 = V_130 -> V_132 ;
int V_68 = V_59 ;
V_5 = F_103 ( V_138 , V_48 ) ;
if ( F_30 ( ! V_5 ) ) {
F_82 ( L_21 , V_48 ) ;
goto V_140;
}
F_21 ( 1 << V_42 | 1 << V_43 ,
L_22 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 , V_13 -> V_152 ) ;
if ( V_13 -> V_152 == V_169 ||
V_13 -> V_152 == V_184 )
goto V_140;
F_83 ( V_5 ) ;
F_85 ( & V_5 -> V_142 ) ;
if ( ! F_36 ( V_5 , V_185 ) ) {
F_32 ( V_5 , V_185 ) ;
F_31 ( V_5 , V_60 ) ;
goto V_186;
}
F_74 ( V_5 , V_185 ) ;
F_37 ( V_5 , V_68 ) ;
if ( ! F_36 ( V_5 , V_61 ) ) {
V_5 -> V_187 = F_107 ( V_5 , V_13 -> V_152 , & V_68 ) ;
F_109 ( V_5 ) ;
}
V_186:
F_92 ( & V_5 -> V_142 ) ;
F_75 ( V_5 ) ;
V_140:
F_93 ( V_2 ) ;
}
static void F_110 ( struct V_133 * V_44 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_188 * V_70 = (struct V_188 * ) V_2 -> V_57 ;
unsigned int V_48 = F_77 ( V_70 ) ;
struct V_129 * V_130 = F_72 ( V_44 ) ;
struct V_137 * V_138 = V_130 -> V_132 ;
V_5 = F_103 ( V_138 , V_48 ) ;
if ( ! V_5 )
goto V_140;
F_21 ( 1 << V_42 | 1 << V_43 ,
L_23 ,
V_70 -> V_152 , V_5 , V_5 ? V_5 -> V_49 : 0 ,
V_5 ? V_5 -> V_50 : 0UL ) ;
if ( V_70 -> V_152 == V_189 )
goto V_140;
F_111 ( V_5 ) ;
V_140:
F_93 ( V_2 ) ;
}
static void F_112 ( struct V_133 * V_44 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_190 * V_191 = (struct V_190 * ) V_2 -> V_57 ;
unsigned short V_192 = F_113 ( V_191 -> V_192 ) ;
unsigned int V_48 = F_77 ( V_191 ) ;
struct V_129 * V_130 = F_72 ( V_44 ) ;
struct V_137 * V_138 = V_130 -> V_132 ;
V_5 = F_103 ( V_138 , V_48 ) ;
if ( F_30 ( ! V_5 ) ) {
F_82 ( L_24 , V_48 ) ;
goto V_140;
}
F_21 ( 1 << V_42 | 1 << V_74 ,
L_25 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 , V_2 , V_2 -> V_7 ,
V_192 ) ;
F_85 ( & V_5 -> V_142 ) ;
if ( F_30 ( V_5 -> V_49 >= V_193 ) ) {
F_21 ( 1 << V_42 | 1 << V_43 ,
L_26 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 ) ;
if ( V_5 -> V_49 != V_60 )
goto V_194;
else
goto V_195;
}
F_114 ( V_2 ) = F_79 ( V_191 -> V_196 ) ;
F_115 ( V_2 ) = 0 ;
F_64 ( V_2 ) ;
F_116 ( V_2 , sizeof( * V_191 ) ) ;
F_117 ( V_2 , F_22 ( V_191 -> V_7 ) ) ;
if ( ! V_5 -> V_197 ) {
unsigned char * V_198 ;
unsigned int V_199 , V_108 ;
F_21 ( 1 << V_42 | 1 << V_74 ,
L_27 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 , V_2 ) ;
V_5 -> V_197 = V_2 ;
F_118 ( V_2 , V_200 ) ;
if ( F_114 ( V_2 ) != V_5 -> V_102 ) {
F_40 ( L_28 ,
V_5 -> V_48 , F_114 ( V_2 ) ,
V_5 -> V_102 ) ;
goto V_194;
}
V_198 = V_2 -> V_57 ;
V_199 = F_22 ( V_191 -> V_7 ) ;
V_108 = F_79 ( * ( unsigned int * ) ( V_198 + 4 ) ) & 0xFFFFFF ;
if ( ( V_199 + V_108 ) != F_119 ( V_192 ) - 40 ) {
F_40 ( L_29
L_30 ,
V_5 -> V_48 , F_119 ( V_192 ) - 40 ,
V_199 , V_108 , F_114 ( V_2 ) ) ;
goto V_194;
}
F_120 ( V_2 ) = ( V_199 + V_108 + 3 ) & ( ~ 0x3 ) ;
if ( V_108 )
F_120 ( V_2 ) += V_5 -> V_201 ;
V_5 -> V_102 += F_120 ( V_2 ) ;
F_21 ( 1 << V_42 | 1 << V_74 ,
L_31 ,
V_5 , V_2 , * V_198 , V_199 , V_108 ,
F_79 ( * ( ( unsigned int * ) ( V_198 + 16 ) ) ) ,
F_79 ( * ( ( unsigned int * ) ( V_198 + 24 ) ) ) ) ;
} else {
struct V_1 * V_202 = V_5 -> V_197 ;
F_118 ( V_202 , V_203 ) ;
F_21 ( 1 << V_42 | 1 << V_74 ,
L_32 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_2 , V_202 ) ;
}
F_121 ( & V_5 -> V_204 , V_2 ) ;
F_92 ( & V_5 -> V_142 ) ;
return;
V_194:
F_29 ( V_5 ) ;
V_195:
F_92 ( & V_5 -> V_142 ) ;
V_140:
F_93 ( V_2 ) ;
}
static void F_122 ( struct V_133 * V_44 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_1 * V_202 ;
struct V_205 * V_70 = (struct V_205 * ) V_2 -> V_57 ;
unsigned int V_48 = F_77 ( V_70 ) ;
struct V_129 * V_130 = F_72 ( V_44 ) ;
struct V_137 * V_138 = V_130 -> V_132 ;
unsigned int V_152 = F_79 ( V_70 -> V_206 ) ;
V_5 = F_103 ( V_138 , V_48 ) ;
if ( F_30 ( ! V_5 ) ) {
F_82 ( L_21 , V_48 ) ;
goto V_140;
}
F_21 ( 1 << V_42 | 1 << V_74 ,
L_33 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_2 , V_152 , V_5 -> V_197 ) ;
F_85 ( & V_5 -> V_142 ) ;
if ( F_30 ( V_5 -> V_49 >= V_193 ) ) {
F_21 ( 1 << V_42 | 1 << V_43 ,
L_26 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 ) ;
if ( V_5 -> V_49 != V_60 )
goto V_194;
else
goto V_195;
}
if ( ! V_5 -> V_197 ) {
F_82 ( L_34 , V_5 -> V_48 ) ;
goto V_194;
}
V_202 = V_5 -> V_197 ;
V_5 -> V_197 = NULL ;
F_123 ( V_202 ) = F_79 ( V_70 -> V_207 ) ;
if ( F_22 ( V_70 -> V_7 ) != F_120 ( V_202 ) )
F_40 ( L_35 ,
V_5 -> V_48 , F_22 ( V_70 -> V_7 ) , F_120 ( V_202 ) ) ;
if ( V_152 & ( 1 << V_208 ) ) {
F_40 ( L_36 ,
V_5 , V_202 , V_152 , F_115 ( V_202 ) ) ;
F_118 ( V_202 , V_209 ) ;
}
if ( V_152 & ( 1 << V_210 ) ) {
F_40 ( L_37 ,
V_5 , V_202 , V_152 , F_115 ( V_202 ) ) ;
F_118 ( V_202 , V_211 ) ;
}
if ( V_152 & ( 1 << V_212 ) ) {
F_21 ( 1 << V_74 ,
L_38 ,
V_5 , V_202 , V_152 ) ;
F_118 ( V_202 , V_213 ) ;
}
if ( ( V_152 & ( 1 << V_214 ) ) &&
! F_68 ( V_202 , V_203 ) ) {
F_21 ( 1 << V_74 ,
L_39 ,
V_5 , V_202 , V_152 ) ;
F_118 ( V_202 , V_215 ) ;
}
F_21 ( 1 << V_74 ,
L_40 ,
V_5 , V_202 , F_115 ( V_202 ) ) ;
F_118 ( V_202 , V_216 ) ;
F_124 ( V_5 ) ;
F_92 ( & V_5 -> V_142 ) ;
goto V_140;
V_194:
F_29 ( V_5 ) ;
V_195:
F_92 ( & V_5 -> V_142 ) ;
V_140:
F_93 ( V_2 ) ;
}
static void F_125 ( struct V_133 * V_44 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_217 * V_70 = (struct V_217 * ) V_2 -> V_57 ;
unsigned int V_48 = F_77 ( V_70 ) ;
struct V_129 * V_130 = F_72 ( V_44 ) ;
struct V_137 * V_138 = V_130 -> V_132 ;
V_5 = F_103 ( V_138 , V_48 ) ;
if ( F_30 ( ! V_5 ) )
F_82 ( L_21 , V_48 ) ;
else {
F_21 ( 1 << V_42 | 1 << V_43 ,
L_18 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 ) ;
F_126 ( V_5 , V_70 -> V_72 , F_79 ( V_70 -> V_218 ) ,
V_70 -> V_219 ) ;
}
F_93 ( V_2 ) ;
}
static void F_127 ( struct V_133 * V_44 , struct V_1 * V_2 )
{
struct V_220 * V_70 = (struct V_220 * ) V_2 -> V_57 ;
unsigned int V_48 = F_77 ( V_70 ) ;
struct V_129 * V_130 = F_72 ( V_44 ) ;
struct V_137 * V_138 = V_130 -> V_132 ;
struct V_4 * V_5 ;
V_5 = F_103 ( V_138 , V_48 ) ;
if ( ! V_5 )
F_82 ( L_24 , V_48 ) ;
F_21 ( 1 << V_42 | 1 << V_43 ,
L_41 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 , V_70 -> V_152 ) ;
if ( V_70 -> V_152 != V_221 )
F_82 ( L_42 ,
V_5 , V_48 , V_70 -> V_152 ) ;
F_93 ( V_2 ) ;
}
static int F_128 ( struct V_4 * V_5 )
{
V_5 -> V_46 = F_39 ( sizeof( struct V_47 ) ,
0 , V_222 ) ;
if ( ! V_5 -> V_46 )
return - V_160 ;
V_5 -> V_56 = F_39 ( sizeof( struct V_56 ) ,
0 , V_222 ) ;
if ( ! V_5 -> V_56 )
goto V_223;
V_5 -> V_69 = F_39 ( sizeof( struct V_69 ) ,
0 , V_222 ) ;
if ( ! V_5 -> V_69 )
goto V_223;
return 0 ;
V_223:
F_129 ( V_5 ) ;
return - V_160 ;
}
static inline void F_130 ( struct V_4 * V_5 )
{
if ( V_5 -> V_21 ) {
F_131 ( V_5 -> V_21 ) ;
V_5 -> V_21 = NULL ;
F_75 ( V_5 ) ;
}
}
static void F_132 ( struct V_4 * V_5 )
{
struct V_129 * V_130 ;
F_21 ( 1 << V_42 | 1 << V_43 ,
L_18 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 ) ;
F_129 ( V_5 ) ;
if ( V_5 -> V_122 != V_5 -> V_224 ) {
F_133 ( V_5 ) ;
F_134 ( V_5 ) ;
}
F_130 ( V_5 ) ;
if ( F_36 ( V_5 , V_131 ) )
F_71 ( V_5 ) ;
else if ( F_36 ( V_5 , V_141 ) ) {
V_130 = F_72 ( V_5 -> V_44 ) ;
F_100 ( V_130 -> V_132 , 0 , V_5 -> V_48 ) ;
F_74 ( V_5 , V_141 ) ;
F_75 ( V_5 ) ;
}
V_5 -> V_225 = NULL ;
V_5 -> V_44 = NULL ;
}
static int F_135 ( struct V_4 * V_5 )
{
struct V_133 * V_44 = V_5 -> V_44 ;
struct V_129 * V_130 = F_72 ( V_44 ) ;
struct V_226 * V_227 = V_44 -> V_45 [ V_5 -> V_29 ] ;
struct V_228 * V_229 = F_136 ( V_227 ) ;
struct V_1 * V_2 = NULL ;
struct V_230 * V_79 ;
unsigned int V_231 ;
F_21 ( 1 << V_42 | 1 << V_43 ,
L_18 ,
V_5 , V_5 -> V_49 , V_5 -> V_50 , V_5 -> V_48 ) ;
V_5 -> V_19 = F_137 ( V_130 -> V_132 , V_5 ) ;
if ( V_5 -> V_19 < 0 ) {
F_82 ( L_43 , V_227 -> V_232 ) ;
return - V_233 ;
}
F_32 ( V_5 , V_131 ) ;
F_83 ( V_5 ) ;
V_79 = F_138 ( V_5 -> V_225 ) ;
if ( ! V_79 ) {
F_82 ( L_44 , V_227 -> V_232 ) ;
goto V_234;
}
V_5 -> V_21 = F_139 ( V_130 -> V_21 , V_79 , V_227 , 0 ) ;
if ( ! V_5 -> V_21 ) {
F_82 ( L_45 , V_227 -> V_232 ) ;
goto V_234;
}
F_83 ( V_5 ) ;
V_2 = F_39 ( sizeof( struct V_12 ) , 0 , V_222 ) ;
if ( ! V_2 )
goto V_234;
V_2 -> V_164 = (struct V_165 * ) V_5 ;
F_34 ( V_2 , V_5 , V_166 ) ;
if ( ! V_5 -> V_235 )
V_5 -> V_235 = F_140 ( V_5 -> V_225 ) ;
F_141 ( V_130 -> V_149 , V_5 -> V_235 , & V_5 -> V_15 ) ;
V_5 -> V_23 = F_142 ( V_227 ) ;
V_5 -> V_24 = ( ( F_143 ( V_227 ) & 0x7F ) ) << 1 ;
V_231 = V_130 -> V_236 / V_130 -> V_237 ;
V_5 -> V_238 = F_144 ( V_227 ) * V_231 ;
V_231 = V_130 -> V_239 / V_130 -> V_237 ;
V_5 -> V_20 = V_130 -> V_240 [ F_144 ( V_227 ) * V_231 ] ;
V_5 -> V_224 = V_5 -> V_122 = V_130 -> V_122 ;
V_5 -> V_126 = 0 ;
F_134 ( V_5 ) ;
V_5 -> V_187 = 0 ;
F_21 ( 1 << V_42 | 1 << V_43 ,
L_46 ,
V_5 , V_229 -> V_29 , V_227 -> V_232 , V_5 -> V_23 ,
V_5 -> V_238 , V_5 -> V_20 , V_5 -> V_235 , V_5 -> V_15 ,
V_5 -> V_24 ) ;
F_31 ( V_5 , V_143 ) ;
F_3 ( V_5 , V_2 , V_5 -> V_21 ) ;
return 0 ;
V_234:
if ( V_2 )
F_93 ( V_2 ) ;
return - V_233 ;
}
int F_145 ( struct V_133 * V_44 )
{
int V_241 ;
if ( V_242 > V_243 )
V_242 = V_243 ;
V_241 = F_146 ( V_44 , V_244 ,
V_242 ) ;
if ( V_241 < 0 )
return V_241 ;
V_44 -> V_245 = F_132 ;
V_44 -> V_246 = F_26 ;
V_44 -> V_247 = F_29 ;
V_44 -> V_248 = F_24 ;
V_44 -> V_249 = F_38 ;
V_44 -> V_250 = F_128 ;
V_44 -> V_251 = F_135 ;
F_40 ( L_47 , V_44 ) ;
return 0 ;
}
static inline void F_147 ( struct V_252 * V_13 ,
unsigned int V_253 , unsigned int V_108 ,
unsigned int V_254 )
{
struct V_255 * V_256 = (struct V_255 * ) ( V_13 + 1 ) ;
F_148 ( V_13 , V_253 , 0 , 0 ) ;
V_13 -> V_58 = F_35 ( F_149 ( V_257 ) | ( 1 << 23 ) ) ;
V_13 -> V_108 = F_35 ( F_150 ( V_108 >> 5 ) ) ;
V_13 -> V_258 = F_35 ( F_151 ( V_254 >> 5 ) ) ;
V_13 -> V_259 = F_35 ( F_45 ( V_253 - sizeof( V_13 -> V_260 ) , 16 ) ) ;
V_256 -> V_261 = F_35 ( F_149 ( V_262 ) ) ;
V_256 -> V_7 = F_35 ( V_108 ) ;
}
static int F_152 ( struct V_133 * V_44 , unsigned int V_29 ,
struct V_263 * V_264 , unsigned int V_22 ,
unsigned int V_265 ,
struct V_266 * V_267 ,
unsigned int V_268 )
{
struct V_269 * V_270 = V_44 -> V_270 ;
struct V_1 * V_2 ;
struct V_252 * V_13 ;
struct V_255 * V_256 ;
struct V_271 * V_272 ;
unsigned int V_254 = V_22 * V_273 + V_270 -> V_274 ;
unsigned int V_108 = V_273 * V_265 ;
unsigned int V_253 = F_153 ( sizeof( struct V_252 ) +
sizeof( struct V_255 ) + V_108 , 16 ) ;
unsigned int V_88 ;
V_2 = F_39 ( V_253 , 0 , V_75 ) ;
if ( ! V_2 ) {
F_82 ( L_48 ,
V_44 , V_22 , V_265 ) ;
return - V_160 ;
}
V_13 = (struct V_252 * ) V_2 -> V_30 ;
F_1 ( V_2 , V_275 , NULL ) ;
F_147 ( V_13 , V_253 , V_108 , V_254 ) ;
V_256 = (struct V_255 * ) ( V_13 + 1 ) ;
V_272 = (struct V_271 * ) ( V_256 + 1 ) ;
for ( V_88 = 0 ; V_88 < V_265 ; V_88 ++ , V_272 ++ , V_268 += V_276 ) {
if ( ! V_264 && ! V_267 )
F_154 ( V_272 ) ;
else
F_155 ( V_272 , V_264 , V_267 , V_268 ) ;
}
F_28 ( V_44 -> V_45 [ V_29 ] , V_2 ) ;
return 0 ;
}
static int F_156 ( struct V_4 * V_5 , struct V_263 * V_264 ,
unsigned int V_22 , unsigned int V_265 ,
struct V_266 * V_267 )
{
unsigned int V_88 , V_81 ;
int V_187 = 0 ;
for ( V_88 = 0 ; V_88 < V_265 ; V_88 += V_81 , V_22 += V_81 ) {
V_81 = V_265 - V_88 ;
if ( V_81 > V_277 )
V_81 = V_277 ;
V_187 = F_152 ( V_5 -> V_44 , V_5 -> V_29 , V_264 ,
V_22 , V_81 , V_267 , 4 * V_88 ) ;
if ( V_187 < 0 )
break;
}
return V_187 ;
}
static void F_157 ( struct V_278 * V_279 , unsigned int V_280 ,
unsigned int V_22 , unsigned int V_265 )
{
unsigned int V_88 , V_81 ;
int V_187 ;
for ( V_88 = 0 ; V_88 < V_265 ; V_88 += V_81 , V_22 += V_81 ) {
V_81 = V_265 - V_88 ;
if ( V_81 > V_277 )
V_81 = V_277 ;
V_187 = F_152 ( V_279 -> V_44 , V_279 -> V_29 , NULL ,
V_22 , V_81 , NULL , 0 ) ;
if ( V_187 < 0 )
break;
}
}
static int F_158 ( struct V_4 * V_5 , unsigned int V_48 ,
int V_281 , bool V_282 )
{
struct V_1 * V_2 ;
struct V_283 * V_13 ;
if ( ! V_281 || V_281 >= V_284 )
return 0 ;
V_2 = F_39 ( sizeof( * V_13 ) , 0 , V_222 ) ;
if ( ! V_2 )
return - V_160 ;
V_13 = (struct V_283 * ) V_2 -> V_30 ;
F_16 ( V_13 , V_5 -> V_48 ) ;
F_17 ( V_13 ) = F_35 ( F_19 ( V_285 , V_5 -> V_48 ) ) ;
V_13 -> V_286 = F_159 ( F_160 ( V_282 ) | F_161 ( V_5 -> V_20 ) ) ;
V_13 -> V_287 = F_159 ( 0 ) ;
V_13 -> V_288 = F_20 ( 0x3 << 8 ) ;
V_13 -> V_95 = F_20 ( V_281 << 8 ) ;
F_15 ( V_2 , V_275 , V_5 -> V_29 ) ;
F_21 ( 1 << V_42 | 1 << V_43 ,
L_49 , V_5 , V_5 -> V_48 , V_281 ) ;
F_28 ( V_5 -> V_44 -> V_45 [ V_5 -> V_29 ] , V_2 ) ;
return 0 ;
}
static int F_162 ( struct V_4 * V_5 , unsigned int V_48 ,
int V_289 , int V_290 , int V_282 )
{
struct V_1 * V_2 ;
struct V_283 * V_13 ;
if ( ! V_289 && ! V_290 )
return 0 ;
V_2 = F_39 ( sizeof( * V_13 ) , 0 , V_222 ) ;
if ( ! V_2 )
return - V_160 ;
V_5 -> V_291 = ( V_289 ? 4 : 0 ) ;
V_5 -> V_201 = ( V_290 ? 4 : 0 ) ;
V_13 = (struct V_283 * ) V_2 -> V_30 ;
F_16 ( V_13 , V_48 ) ;
F_17 ( V_13 ) = F_35 ( F_19 ( V_285 , V_48 ) ) ;
V_13 -> V_286 = F_159 ( F_160 ( V_282 ) | F_161 ( V_5 -> V_20 ) ) ;
V_13 -> V_287 = F_159 ( 0 ) ;
V_13 -> V_288 = F_20 ( 0x3 << 4 ) ;
V_13 -> V_95 = F_20 ( ( ( V_289 ? V_292 : 0 ) |
( V_290 ? V_293 : 0 ) ) << 4 ) ;
F_15 ( V_2 , V_275 , V_5 -> V_29 ) ;
F_21 ( 1 << V_42 | 1 << V_43 ,
L_50 , V_5 , V_5 -> V_48 , V_289 , V_290 ) ;
F_28 ( V_5 -> V_44 -> V_45 [ V_5 -> V_29 ] , V_2 ) ;
return 0 ;
}
static int F_163 ( struct V_133 * V_44 )
{
struct V_129 * V_130 = F_72 ( V_44 ) ;
struct V_269 * V_270 = V_44 -> V_270 ;
unsigned int V_294 , V_295 [ 4 ] ;
int V_187 ;
if ( V_270 ) {
F_164 ( & V_270 -> V_296 ) ;
F_165 ( L_51 ,
V_44 , V_44 -> V_270 ) ;
return - V_297 ;
}
V_187 = F_166 ( V_44 , V_130 -> V_298 -> V_299 . V_300 ,
V_130 -> V_298 -> V_299 . V_300 + V_130 -> V_298 -> V_299 . V_301 - 1 ,
V_130 -> V_302 , V_130 -> V_302 ) ;
if ( V_187 < 0 )
return V_187 ;
V_270 = V_44 -> V_270 ;
V_294 = V_270 -> V_303 << V_304 ;
F_167 ( V_295 ) ;
F_168 ( V_130 -> V_45 [ 0 ] , V_294 , V_295 ) ;
V_44 -> V_305 = F_162 ;
V_44 -> V_306 = F_158 ;
V_44 -> V_307 = F_156 ;
V_44 -> V_308 = F_157 ;
F_40 ( L_52 ,
V_44 , V_44 -> V_309 . V_310 , V_44 -> V_309 . V_311 ,
V_44 -> V_309 . V_312 , V_44 -> V_309 . V_313 ) ;
F_40 ( L_53
L_54 ,
V_44 , V_270 -> V_314 , V_270 -> V_315 , V_270 -> V_303 ,
V_270 -> V_316 , V_270 -> V_317 , V_130 -> V_302 ,
V_270 -> V_318 , V_130 -> V_302 ) ;
F_40 ( L_55 ,
V_44 , V_44 -> V_319 , V_270 -> V_317 , V_44 -> V_320 ,
V_270 -> V_318 ) ;
return 0 ;
}
static void * F_169 ( const struct V_129 * V_130 )
{
struct V_133 * V_44 ;
struct V_228 * V_229 ;
int V_88 , V_241 ;
V_44 = F_170 ( sizeof( * V_130 ) , V_130 -> V_321 ) ;
if ( ! V_44 ) {
F_40 ( L_56 , V_130 ) ;
return NULL ;
}
F_40 ( L_57 ,
V_44 , V_130 -> V_322 , V_130 -> V_321 ,
V_130 -> V_45 [ 0 ] -> V_232 , V_130 -> V_237 , V_130 -> V_236 ,
V_130 -> V_239 , V_130 -> V_122 ) ;
for ( V_88 = 0 ; V_88 < V_130 -> V_239 ; V_88 ++ )
F_21 ( 1 << V_323 ,
L_58 ,
V_44 , V_88 , V_130 -> V_240 [ V_88 ] ) ;
memcpy ( F_72 ( V_44 ) , V_130 , sizeof( * V_130 ) ) ;
V_44 -> V_50 = V_324 ;
V_44 -> V_325 = V_130 -> V_325 ;
V_44 -> V_45 = V_130 -> V_45 ;
V_44 -> V_321 = V_130 -> V_321 ;
V_44 -> V_149 = V_130 -> V_149 ;
V_44 -> V_326 = V_327 ;
V_44 -> V_328 = V_104 ;
V_44 -> V_329 = V_26 ;
V_44 -> V_330 = V_331 ;
V_44 -> V_332 = V_333 ;
V_44 -> V_334 = sizeof( struct V_190 ) ;
V_44 -> V_335 = & V_336 ;
V_44 -> V_96 = F_171 ( F_143 ( V_130 -> V_45 [ 0 ] ) ) << 8 ;
F_40 ( L_59 ,
V_44 , V_130 -> V_45 [ 0 ] -> V_232 , V_44 -> V_96 ) ;
V_241 = F_163 ( V_44 ) ;
if ( V_241 ) {
F_40 ( L_60 , V_44 ) ;
goto V_337;
}
V_241 = F_145 ( V_44 ) ;
if ( V_241 ) {
F_40 ( L_61 , V_44 ) ;
goto V_337;
}
V_241 = F_172 ( V_44 , V_338 , V_339 ,
& V_340 , V_341 ) ;
if ( V_241 )
goto V_337;
for ( V_88 = 0 ; V_88 < V_44 -> V_321 ; V_88 ++ ) {
V_229 = F_136 ( V_130 -> V_45 [ V_88 ] ) ;
V_44 -> V_342 [ V_88 ] -> V_29 = V_229 -> V_29 ;
}
return V_44 ;
V_337:
F_173 ( V_44 ) ;
return F_174 ( - V_160 ) ;
}
static int F_175 ( void * V_55 , const T_2 * V_343 ,
const struct V_344 * V_345 )
{
const struct V_134 * V_70 ;
struct V_1 * V_2 ;
unsigned int V_346 ;
struct V_133 * V_44 = V_55 ;
if ( V_345 == NULL ) {
unsigned int V_7 = 64 - sizeof( struct V_347 ) - 8 ;
V_2 = F_39 ( V_7 , 0 , V_75 ) ;
if ( ! V_2 )
goto V_348;
F_176 ( V_2 , & V_343 [ 1 ] , V_7 ) ;
} else {
if ( F_30 ( * ( V_349 * ) V_343 != * ( V_349 * ) V_345 -> V_350 ) ) {
F_40 ( L_62 ,
V_345 -> V_350 , F_177 ( * V_343 ) ,
F_177 ( * ( V_351 * ) V_345 -> V_350 ) ,
V_345 -> V_352 ) ;
return 0 ;
}
V_2 = F_178 ( V_345 , V_353 , V_353 ) ;
if ( F_30 ( ! V_2 ) )
goto V_348;
}
V_70 = (struct V_134 * ) V_2 -> V_57 ;
V_346 = V_70 -> V_354 . V_355 ;
F_21 ( 1 << V_42 ,
L_63 ,
V_44 , V_346 , V_70 -> V_354 . V_356 , F_79 ( V_70 -> V_354 . V_356 ) , V_2 ) ;
if ( V_357 [ V_346 ] )
V_357 [ V_346 ] ( V_44 , V_2 ) ;
else {
F_82 ( L_64 , V_346 ) ;
F_93 ( V_2 ) ;
}
return 0 ;
V_348:
F_21 ( 1 << V_42 , L_65 ) ;
return 1 ;
}
static int F_179 ( void * V_55 , enum V_358 V_49 )
{
struct V_133 * V_44 = V_55 ;
switch ( V_49 ) {
case V_359 :
F_40 ( L_66 , V_44 ) ;
break;
case V_360 :
F_40 ( L_67 , V_44 ) ;
break;
case V_361 :
F_40 ( L_68 , V_44 ) ;
break;
case V_362 :
F_40 ( L_69 , V_44 ) ;
break;
default:
F_40 ( L_70 , V_44 , V_49 ) ;
break;
}
return 0 ;
}
static int T_3 F_180 ( void )
{
int V_241 ;
F_181 ( V_363 L_71 , V_364 ) ;
V_241 = F_182 ( & V_336 , & V_341 ) ;
if ( V_241 < 0 )
return V_241 ;
F_183 ( V_365 , & V_366 ) ;
return 0 ;
}
static void T_4 F_184 ( void )
{
F_185 ( V_365 ) ;
F_186 ( V_324 ) ;
F_187 ( & V_336 , & V_341 ) ;
}
