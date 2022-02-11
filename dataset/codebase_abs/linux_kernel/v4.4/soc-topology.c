static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 , T_1 V_5 , const char * V_6 )
{
const T_2 * V_7 = V_2 -> V_8 + V_3 * V_4 ;
if ( V_7 > V_2 -> V_9 -> V_10 + V_2 -> V_9 -> V_11 ) {
F_2 ( V_2 -> V_12 , L_1 ,
V_6 ) ;
return - V_13 ;
}
if ( V_3 * V_4 > V_5 ) {
F_2 ( V_2 -> V_12 ,
L_2 ,
V_6 , V_4 , V_3 , V_5 ) ;
return - V_13 ;
}
return 0 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
const T_2 * V_7 = V_2 -> V_14 ;
if ( V_7 >= V_2 -> V_9 -> V_10 + V_2 -> V_9 -> V_11 )
return 1 ;
return 0 ;
}
static inline unsigned long F_4 ( struct V_1 * V_2 )
{
return ( unsigned long ) ( V_2 -> V_14 - V_2 -> V_9 -> V_10 ) ;
}
static inline unsigned long F_5 ( struct V_1 * V_2 )
{
return ( unsigned long ) ( V_2 -> V_8 - V_2 -> V_9 -> V_10 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
if ( V_16 [ V_18 ] . V_20 == V_17 )
return V_16 [ V_18 ] . V_21 ;
}
return - V_13 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
if ( V_16 [ V_18 ] . V_20 == V_17 )
return V_16 [ V_18 ] . V_22 ;
}
return - V_13 ;
}
static int F_8 ( int V_23 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < F_9 ( V_24 ) ; V_18 ++ ) {
if ( V_23 == V_24 [ V_18 ] . V_25 )
return V_24 [ V_18 ] . V_26 ;
}
return - V_13 ;
}
static enum V_27 F_10 (
struct V_28 * V_29 )
{
if ( V_29 == NULL )
return V_30 ;
switch ( V_29 -> V_31 . V_32 ) {
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
return V_38 ;
case V_39 :
case V_40 :
return V_41 ;
case V_42 :
return V_43 ;
default:
return V_30 ;
}
}
static enum V_27 F_11 ( struct V_44 * V_45 ,
struct V_28 * V_29 )
{
switch ( V_45 -> type ) {
case V_46 :
return F_10 ( V_29 ) ;
case V_47 :
case V_48 :
return V_30 ;
case V_49 :
return V_50 ;
case V_51 :
return V_52 ;
case V_53 :
return V_54 ;
case V_55 :
return V_56 ;
default:
return V_30 ;
}
}
static inline void F_12 ( struct V_1 * V_2 ,
struct V_28 * V_45 , int V_57 )
{
F_2 ( V_2 -> V_12 ,
L_3 ,
V_45 -> V_31 . V_58 , V_45 -> V_31 . V_59 , V_45 -> V_31 . V_32 , V_57 ,
F_5 ( V_2 ) ) ;
}
static inline void F_13 ( struct V_1 * V_2 ,
struct V_28 * V_45 , const char * V_60 )
{
F_2 ( V_2 -> V_12 ,
L_4 ,
V_60 , V_45 -> V_31 . V_58 , V_45 -> V_31 . V_59 , V_45 -> V_31 . V_32 ,
F_5 ( V_2 ) ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
int V_61 = 0 ;
if ( V_2 -> V_62 && V_2 -> V_31 && V_2 -> V_31 -> V_63 )
V_61 = V_2 -> V_31 -> V_63 ( V_2 -> V_62 , V_45 ) ;
else {
F_2 ( V_2 -> V_12 , L_5 ,
V_45 -> V_64 ) ;
return - V_13 ;
}
if ( V_61 < 0 )
F_2 ( V_2 -> V_12 ,
L_6 ,
F_4 ( V_2 ) ,
F_4 ( V_2 ) ,
V_45 -> type , V_45 -> V_64 ) ;
return V_61 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
if ( V_2 -> V_65 != V_66 )
return 0 ;
return F_14 ( V_2 , V_45 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_67 * V_68 , struct V_69 * V_70 )
{
if ( V_2 -> V_62 && V_2 -> V_31 && V_2 -> V_31 -> V_71 )
return V_2 -> V_31 -> V_71 ( V_2 -> V_62 , V_68 , V_70 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_72 * V_73 , int V_74 )
{
if ( V_2 -> V_62 && V_2 -> V_31 && V_2 -> V_31 -> V_75 )
return V_2 -> V_31 -> V_75 ( V_2 -> V_62 , V_73 , V_74 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_62 && V_2 -> V_31 && V_2 -> V_31 -> V_76 )
V_2 -> V_31 -> V_76 ( V_2 -> V_62 ) ;
}
static int F_19 ( struct V_77 * V_78 , struct V_79 * V_12 ,
const struct V_80 * V_81 , const char * V_82 ,
void * V_10 , struct V_83 * * V_84 )
{
int V_85 ;
* V_84 = F_20 ( V_81 , V_10 , V_81 -> V_60 , V_82 ) ;
if ( * V_84 == NULL ) {
F_2 ( V_12 , L_7 ,
V_81 -> V_60 ) ;
return - V_86 ;
}
V_85 = F_21 ( V_78 , * V_84 ) ;
if ( V_85 < 0 ) {
F_2 ( V_12 , L_8 ,
V_81 -> V_60 , V_85 ) ;
return V_85 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_80 * V_87 , struct V_83 * * V_84 )
{
struct V_88 * V_62 = V_2 -> V_62 ;
return F_19 ( V_62 -> V_78 -> V_77 ,
V_62 -> V_12 , V_87 , NULL , V_62 , V_84 ) ;
}
static void F_23 ( struct V_88 * V_62 ,
struct V_89 * V_90 , int V_65 )
{
struct V_77 * V_78 = V_62 -> V_78 -> V_77 ;
struct V_91 * V_92 =
F_24 ( V_90 , struct V_91 , V_90 ) ;
const unsigned int * V_93 = NULL ;
if ( V_65 != V_94 )
return;
if ( V_90 -> V_31 && V_90 -> V_31 -> V_95 )
V_90 -> V_31 -> V_95 ( V_62 , V_90 ) ;
if ( V_92 -> V_90 . V_96 . V_84 -> V_97 . V_93 )
V_93 = V_92 -> V_90 . V_96 . V_84 -> V_97 . V_93 ;
F_25 ( V_78 , V_92 -> V_90 . V_96 . V_84 ) ;
F_26 ( & V_92 -> V_90 . V_98 ) ;
F_27 ( V_92 ) ;
F_27 ( V_93 ) ;
}
static void F_28 ( struct V_88 * V_62 ,
struct V_89 * V_90 , int V_65 )
{
struct V_77 * V_78 = V_62 -> V_78 -> V_77 ;
struct V_99 * V_100 = F_24 ( V_90 , struct V_99 , V_90 ) ;
int V_18 ;
if ( V_65 != V_94 )
return;
if ( V_90 -> V_31 && V_90 -> V_31 -> V_95 )
V_90 -> V_31 -> V_95 ( V_62 , V_90 ) ;
F_25 ( V_78 , V_100 -> V_90 . V_96 . V_84 ) ;
F_26 ( & V_100 -> V_90 . V_98 ) ;
F_27 ( V_100 -> V_90 . V_96 . V_101 ) ;
for ( V_18 = 0 ; V_18 < V_100 -> V_102 ; V_18 ++ )
F_27 ( V_100 -> V_90 . V_96 . V_103 [ V_18 ] ) ;
F_27 ( V_100 ) ;
}
static void F_29 ( struct V_88 * V_62 ,
struct V_89 * V_90 , int V_65 )
{
struct V_77 * V_78 = V_62 -> V_78 -> V_77 ;
struct V_104 * V_105 =
F_24 ( V_90 , struct V_104 , V_90 ) ;
if ( V_65 != V_94 )
return;
if ( V_90 -> V_31 && V_90 -> V_31 -> V_95 )
V_90 -> V_31 -> V_95 ( V_62 , V_90 ) ;
F_25 ( V_78 , V_105 -> V_90 . V_96 . V_84 ) ;
F_26 ( & V_105 -> V_90 . V_98 ) ;
F_27 ( V_105 ) ;
}
static void F_30 ( struct V_88 * V_62 ,
struct V_89 * V_90 , int V_65 )
{
struct V_77 * V_78 = V_62 -> V_78 -> V_77 ;
struct V_67 * V_68 =
F_24 ( V_90 , struct V_67 , V_90 ) ;
int V_18 ;
if ( V_65 != V_106 )
return;
if ( V_90 -> V_31 && V_90 -> V_31 -> V_107 )
V_90 -> V_31 -> V_107 ( V_62 , V_90 ) ;
if ( V_90 -> V_108 . V_109 ) {
struct V_99 * V_100 =
(struct V_99 * ) V_68 -> V_110 [ 0 ] -> V_111 ;
F_25 ( V_78 , V_68 -> V_110 [ 0 ] ) ;
F_27 ( V_100 -> V_90 . V_96 . V_101 ) ;
for ( V_18 = 0 ; V_18 < V_100 -> V_102 ; V_18 ++ )
F_27 ( V_100 -> V_90 . V_96 . V_103 [ V_18 ] ) ;
F_27 ( V_100 ) ;
F_27 ( V_68 -> V_112 ) ;
} else {
for ( V_18 = 0 ; V_18 < V_68 -> V_113 ; V_18 ++ ) {
struct V_83 * V_84 = V_68 -> V_110 [ V_18 ] ;
struct V_91 * V_92 =
(struct V_91 * ) V_84 -> V_111 ;
F_27 ( V_68 -> V_110 [ V_18 ] -> V_97 . V_93 ) ;
F_25 ( V_78 , V_68 -> V_110 [ V_18 ] ) ;
F_27 ( V_92 ) ;
}
F_27 ( V_68 -> V_112 ) ;
}
}
static void F_31 ( struct V_88 * V_62 ,
struct V_89 * V_90 , int V_65 )
{
if ( V_65 != V_114 )
return;
if ( V_90 -> V_31 && V_90 -> V_31 -> V_115 )
V_90 -> V_31 -> V_115 ( V_62 , V_90 ) ;
F_26 ( & V_90 -> V_98 ) ;
F_27 ( V_90 ) ;
}
static int F_32 ( struct V_28 * V_45 ,
struct V_80 * V_87 ,
const struct V_1 * V_2 )
{
const struct V_116 * V_31 ;
const struct V_117 * V_118 ;
int V_119 , V_18 ;
if ( V_45 -> V_31 . V_32 == V_42
&& V_87 -> V_120 & V_121
&& V_87 -> V_122 & V_123
&& V_87 -> V_122 & V_124 ) {
struct V_104 * V_125 ;
struct V_126 * V_127 ;
V_125 = (struct V_104 * ) V_87 -> V_111 ;
V_127 = F_24 ( V_45 , struct V_126 , V_45 ) ;
V_87 -> V_32 = V_128 ;
V_87 -> V_97 . V_129 = V_130 ;
V_118 = V_2 -> V_131 ;
V_119 = V_2 -> V_132 ;
for ( V_18 = 0 ; V_18 < V_119 ; V_18 ++ ) {
if ( ! V_125 -> V_59 && V_118 [ V_18 ] . V_20 == V_127 -> V_118 . V_59 )
V_125 -> V_59 = V_118 [ V_18 ] . V_59 ;
if ( ! V_125 -> V_58 && V_118 [ V_18 ] . V_20 == V_127 -> V_118 . V_58 )
V_125 -> V_58 = V_118 [ V_18 ] . V_58 ;
}
if ( V_125 -> V_59 && V_125 -> V_58 )
return 0 ;
else
return - V_13 ;
}
V_31 = V_2 -> V_133 ;
V_119 = V_2 -> V_134 ;
for ( V_18 = 0 ; V_18 < V_119 ; V_18 ++ ) {
if ( V_87 -> V_59 == NULL && V_31 [ V_18 ] . V_20 == V_45 -> V_31 . V_59 )
V_87 -> V_59 = V_31 [ V_18 ] . V_59 ;
if ( V_87 -> V_58 == NULL && V_31 [ V_18 ] . V_20 == V_45 -> V_31 . V_58 )
V_87 -> V_58 = V_31 [ V_18 ] . V_58 ;
if ( V_87 -> V_32 == NULL && V_31 [ V_18 ] . V_20 == V_45 -> V_31 . V_32 )
V_87 -> V_32 = V_31 [ V_18 ] . V_32 ;
}
if ( V_87 -> V_59 && V_87 -> V_58 && V_87 -> V_32 )
return 0 ;
V_31 = V_133 ;
V_119 = F_9 ( V_133 ) ;
for ( V_18 = 0 ; V_18 < V_119 ; V_18 ++ ) {
if ( V_87 -> V_59 == NULL && V_31 [ V_18 ] . V_20 == V_45 -> V_31 . V_59 )
V_87 -> V_59 = V_31 [ V_18 ] . V_59 ;
if ( V_87 -> V_58 == NULL && V_31 [ V_18 ] . V_20 == V_45 -> V_31 . V_58 )
V_87 -> V_58 = V_31 [ V_18 ] . V_58 ;
if ( V_87 -> V_32 == NULL && V_31 [ V_18 ] . V_20 == V_45 -> V_31 . V_32 )
V_87 -> V_32 = V_31 [ V_18 ] . V_32 ;
}
if ( V_87 -> V_59 && V_87 -> V_58 && V_87 -> V_32 )
return 0 ;
return - V_13 ;
}
int F_33 ( struct V_67 * V_68 ,
const struct V_135 * V_136 ,
int V_137 , T_3 V_138 )
{
int V_18 ;
V_68 -> V_139 = NULL ;
for ( V_18 = 0 ; V_18 < V_137 ; V_18 ++ ) {
if ( V_138 == V_136 [ V_18 ] . type ) {
V_68 -> V_139 = V_136 [ V_18 ] . V_140 ;
return 0 ;
}
}
return - V_13 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_80 * V_87 , struct V_28 * V_45 )
{
if ( V_2 -> V_62 && V_2 -> V_31 && V_2 -> V_31 -> V_141 )
return V_2 -> V_31 -> V_141 ( V_2 -> V_62 , V_87 , V_45 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_80 * V_142 , struct V_143 * V_144 )
{
unsigned int V_145 = 2 * sizeof( unsigned int ) ;
unsigned int * V_93 ;
V_93 = F_36 ( V_145 + 2 * sizeof( unsigned int ) , V_146 ) ;
if ( ! V_93 )
return - V_86 ;
V_93 [ 0 ] = V_147 ;
V_93 [ 1 ] = V_145 ;
V_93 [ 2 ] = V_144 -> V_148 ;
V_93 [ 3 ] = ( V_144 -> V_149 & V_150 )
| ( V_144 -> V_151 ? V_152 : 0 ) ;
V_142 -> V_97 . V_93 = ( void * ) V_93 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_80 * V_142 , struct V_28 * V_153 )
{
struct V_154 * V_155 ;
if ( ! ( V_153 -> V_122 & V_123 ) )
return 0 ;
if ( ! ( V_153 -> V_122 & V_124 ) ) {
V_155 = & V_153 -> V_97 ;
switch ( V_155 -> type ) {
case V_147 :
return F_35 ( V_2 , V_142 ,
& V_155 -> V_144 ) ;
default:
F_38 ( V_2 -> V_12 , L_9 ,
V_155 -> type ) ;
return - V_13 ;
}
}
return 0 ;
}
static inline void F_39 ( struct V_1 * V_2 ,
struct V_80 * V_142 )
{
F_27 ( V_142 -> V_97 . V_93 ) ;
}
static int F_40 ( struct V_1 * V_2 , unsigned int V_4 ,
T_1 V_11 )
{
struct V_126 * V_127 ;
struct V_104 * V_125 ;
struct V_80 V_142 ;
int V_18 , V_85 ;
if ( F_1 ( V_2 ,
sizeof( struct V_126 ) , V_4 ,
V_11 , L_10 ) ) {
F_2 ( V_2 -> V_12 , L_11 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_127 = (struct V_126 * ) V_2 -> V_8 ;
if ( F_41 ( V_127 -> V_45 . V_60 , V_156 ) ==
V_156 )
return - V_13 ;
V_125 = F_36 ( sizeof( * V_125 ) , V_146 ) ;
if ( V_125 == NULL )
return - V_86 ;
V_2 -> V_8 += ( sizeof( struct V_126 ) +
V_127 -> V_157 . V_11 ) ;
F_38 ( V_2 -> V_12 ,
L_12 ,
V_127 -> V_45 . V_60 , V_127 -> V_45 . V_122 ) ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_60 = V_127 -> V_45 . V_60 ;
V_142 . V_111 = ( long ) V_125 ;
V_142 . V_120 = V_121 ;
V_142 . V_122 = V_127 -> V_45 . V_122 ;
V_125 -> V_158 = V_127 -> V_158 ;
V_125 -> V_90 . type = V_43 ;
V_125 -> V_90 . V_31 = V_2 -> V_31 ;
F_42 ( & V_125 -> V_90 . V_98 ) ;
V_85 = F_32 ( & V_127 -> V_45 , & V_142 , V_2 ) ;
if ( V_85 ) {
F_13 ( V_2 , & V_127 -> V_45 , V_127 -> V_45 . V_60 ) ;
F_27 ( V_125 ) ;
continue;
}
V_85 = F_34 ( V_2 , & V_142 ,
(struct V_28 * ) V_127 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_127 -> V_45 . V_60 ) ;
F_27 ( V_125 ) ;
continue;
}
V_85 = F_22 ( V_2 , & V_142 ,
& V_125 -> V_90 . V_96 . V_84 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_14 ,
V_127 -> V_45 . V_60 ) ;
F_27 ( V_125 ) ;
continue;
}
F_43 ( & V_125 -> V_90 . V_98 , & V_2 -> V_62 -> V_159 ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , unsigned int V_4 ,
T_1 V_11 )
{
struct V_160 * V_161 ;
struct V_91 * V_92 ;
struct V_80 V_142 ;
int V_18 , V_85 ;
if ( F_1 ( V_2 ,
sizeof( struct V_160 ) ,
V_4 , V_11 , L_15 ) ) {
F_2 ( V_2 -> V_12 , L_16 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_161 = (struct V_160 * ) V_2 -> V_8 ;
if ( F_41 ( V_161 -> V_45 . V_60 , V_156 ) ==
V_156 )
return - V_13 ;
V_92 = F_36 ( sizeof( * V_92 ) , V_146 ) ;
if ( V_92 == NULL )
return - V_86 ;
V_2 -> V_8 += ( sizeof( struct V_160 ) +
V_161 -> V_157 . V_11 ) ;
F_38 ( V_2 -> V_12 ,
L_17 ,
V_161 -> V_45 . V_60 , V_161 -> V_45 . V_122 ) ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_60 = V_161 -> V_45 . V_60 ;
V_142 . V_111 = ( long ) V_92 ;
V_142 . V_120 = V_121 ;
V_142 . V_122 = V_161 -> V_45 . V_122 ;
V_92 -> V_21 = F_6 ( V_2 , V_161 -> V_162 ,
V_163 ) ;
V_92 -> V_164 = F_6 ( V_2 , V_161 -> V_162 ,
V_165 ) ;
V_92 -> V_22 = F_7 ( V_2 , V_161 -> V_162 ,
V_163 ) ;
V_92 -> V_166 = F_7 ( V_2 , V_161 -> V_162 ,
V_165 ) ;
V_92 -> V_158 = V_161 -> V_158 ;
V_92 -> V_148 = V_161 -> V_148 ;
V_92 -> V_167 = V_161 -> V_167 ;
V_92 -> V_168 = V_161 -> V_168 ;
V_92 -> V_90 . V_57 = V_2 -> V_57 ;
V_92 -> V_90 . V_31 = V_2 -> V_31 ;
V_92 -> V_90 . type = V_38 ;
F_42 ( & V_92 -> V_90 . V_98 ) ;
V_85 = F_32 ( & V_161 -> V_45 , & V_142 , V_2 ) ;
if ( V_85 ) {
F_13 ( V_2 , & V_161 -> V_45 , V_161 -> V_45 . V_60 ) ;
F_27 ( V_92 ) ;
continue;
}
V_85 = F_34 ( V_2 , & V_142 ,
(struct V_28 * ) V_161 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_161 -> V_45 . V_60 ) ;
F_27 ( V_92 ) ;
continue;
}
F_37 ( V_2 , & V_142 , & V_161 -> V_45 ) ;
V_85 = F_22 ( V_2 , & V_142 ,
& V_92 -> V_90 . V_96 . V_84 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_14 ,
V_161 -> V_45 . V_60 ) ;
F_39 ( V_2 , & V_142 ) ;
F_27 ( V_92 ) ;
continue;
}
F_43 ( & V_92 -> V_90 . V_98 , & V_2 -> V_62 -> V_159 ) ;
}
return 0 ;
}
static int F_45 ( struct V_99 * V_100 ,
struct V_169 * V_170 )
{
int V_18 , V_61 ;
V_100 -> V_90 . V_96 . V_103 =
F_36 ( sizeof( char * ) * V_170 -> V_102 , V_146 ) ;
if ( V_100 -> V_90 . V_96 . V_103 == NULL )
return - V_86 ;
for ( V_18 = 0 ; V_18 < V_170 -> V_102 ; V_18 ++ ) {
if ( F_41 ( V_170 -> V_171 [ V_18 ] , V_156 ) ==
V_156 ) {
V_61 = - V_13 ;
goto V_85;
}
V_100 -> V_90 . V_96 . V_103 [ V_18 ] = F_46 ( V_170 -> V_171 [ V_18 ] , V_146 ) ;
if ( ! V_100 -> V_90 . V_96 . V_103 [ V_18 ] ) {
V_61 = - V_86 ;
goto V_85;
}
}
return 0 ;
V_85:
for ( -- V_18 ; V_18 >= 0 ; V_18 -- )
F_27 ( V_100 -> V_90 . V_96 . V_103 [ V_18 ] ) ;
F_27 ( V_100 -> V_90 . V_96 . V_103 ) ;
return V_61 ;
}
static int F_47 ( struct V_99 * V_100 ,
struct V_169 * V_170 )
{
if ( V_170 -> V_102 > sizeof( * V_170 -> V_172 ) )
return - V_13 ;
V_100 -> V_90 . V_96 . V_101 = F_48 ( V_170 -> V_172 ,
V_170 -> V_102 * sizeof( V_173 ) ,
V_146 ) ;
if ( ! V_100 -> V_90 . V_96 . V_101 )
return - V_86 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , unsigned int V_4 ,
T_1 V_11 )
{
struct V_169 * V_170 ;
struct V_99 * V_100 ;
struct V_80 V_142 ;
int V_18 , V_61 , V_85 ;
if ( F_1 ( V_2 ,
sizeof( struct V_169 ) ,
V_4 , V_11 , L_18 ) ) {
F_2 ( V_2 -> V_12 , L_19 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_170 = (struct V_169 * ) V_2 -> V_8 ;
V_2 -> V_8 += ( sizeof( struct V_169 ) +
V_170 -> V_157 . V_11 ) ;
if ( F_41 ( V_170 -> V_45 . V_60 , V_156 ) ==
V_156 )
return - V_13 ;
V_100 = F_36 ( ( sizeof( * V_100 ) ) , V_146 ) ;
if ( V_100 == NULL )
return - V_86 ;
F_38 ( V_2 -> V_12 , L_20 ,
V_170 -> V_45 . V_60 , V_170 -> V_102 ) ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_60 = V_170 -> V_45 . V_60 ;
V_142 . V_111 = ( long ) V_100 ;
V_142 . V_120 = V_121 ;
V_142 . V_122 = V_170 -> V_45 . V_122 ;
V_100 -> V_21 = F_6 ( V_2 , V_170 -> V_162 , V_163 ) ;
V_100 -> V_174 = F_7 ( V_2 , V_170 -> V_162 ,
V_163 ) ;
V_100 -> V_175 = F_7 ( V_2 , V_170 -> V_162 ,
V_163 ) ;
V_100 -> V_102 = V_170 -> V_102 ;
V_100 -> V_176 = V_170 -> V_176 ;
V_100 -> V_90 . V_57 = V_2 -> V_57 ;
V_100 -> V_90 . type = V_41 ;
V_100 -> V_90 . V_31 = V_2 -> V_31 ;
F_42 ( & V_100 -> V_90 . V_98 ) ;
switch ( V_170 -> V_45 . V_31 . V_32 ) {
case V_177 :
case V_40 :
V_85 = F_47 ( V_100 , V_170 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 ,
L_21 ,
V_170 -> V_45 . V_60 ) ;
F_27 ( V_100 ) ;
continue;
}
case V_39 :
case V_178 :
case V_179 :
V_85 = F_45 ( V_100 , V_170 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 ,
L_22 ,
V_170 -> V_45 . V_60 ) ;
F_27 ( V_100 ) ;
continue;
}
break;
default:
F_2 ( V_2 -> V_12 ,
L_23 ,
V_170 -> V_45 . V_31 . V_32 , V_170 -> V_45 . V_60 ) ;
F_27 ( V_100 ) ;
continue;
}
V_85 = F_32 ( & V_170 -> V_45 , & V_142 , V_2 ) ;
if ( V_85 ) {
F_13 ( V_2 , & V_170 -> V_45 , V_170 -> V_45 . V_60 ) ;
F_27 ( V_100 ) ;
continue;
}
V_85 = F_34 ( V_2 , & V_142 ,
(struct V_28 * ) V_170 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_170 -> V_45 . V_60 ) ;
F_27 ( V_100 ) ;
continue;
}
V_61 = F_22 ( V_2 ,
& V_142 , & V_100 -> V_90 . V_96 . V_84 ) ;
if ( V_61 < 0 ) {
F_2 ( V_2 -> V_12 , L_24 ,
V_170 -> V_45 . V_60 ) ;
F_27 ( V_100 ) ;
continue;
}
F_43 ( & V_100 -> V_90 . V_98 , & V_2 -> V_62 -> V_159 ) ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_28 * V_29 ;
int V_18 ;
if ( V_2 -> V_65 != V_94 ) {
V_2 -> V_8 += V_45 -> V_11 + V_45 -> V_180 ;
return 0 ;
}
F_38 ( V_2 -> V_12 , L_25 , V_45 -> V_4 ,
F_5 ( V_2 ) ) ;
for ( V_18 = 0 ; V_18 < V_45 -> V_4 ; V_18 ++ ) {
V_29 = (struct V_28 * ) V_2 -> V_8 ;
switch ( V_29 -> V_31 . V_32 ) {
case V_33 :
case V_37 :
case V_34 :
case V_35 :
case V_36 :
case V_181 :
case V_182 :
F_44 ( V_2 , 1 , V_45 -> V_180 ) ;
break;
case V_39 :
case V_40 :
case V_178 :
case V_179 :
case V_177 :
F_49 ( V_2 , 1 , V_45 -> V_180 ) ;
break;
case V_42 :
F_40 ( V_2 , 1 , V_45 -> V_180 ) ;
break;
default:
F_12 ( V_2 , V_29 , V_18 ) ;
return - V_13 ;
}
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_183 * V_184 = & V_2 -> V_62 -> V_184 ;
struct V_185 V_186 ;
struct V_187 * V_188 ;
int V_4 = V_45 -> V_4 , V_18 ;
if ( V_2 -> V_65 != V_189 ) {
V_2 -> V_8 += V_45 -> V_11 + V_45 -> V_180 ;
return 0 ;
}
if ( F_1 ( V_2 ,
sizeof( struct V_187 ) ,
V_4 , V_45 -> V_180 , L_26 ) ) {
F_2 ( V_2 -> V_12 , L_27 ,
V_4 ) ;
return - V_13 ;
}
F_38 ( V_2 -> V_12 , L_28 , V_4 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_188 = (struct V_187 * ) V_2 -> V_8 ;
V_2 -> V_8 += sizeof( struct V_187 ) ;
if ( F_41 ( V_188 -> V_190 , V_156 ) ==
V_156 )
return - V_13 ;
if ( F_41 ( V_188 -> V_191 , V_156 ) ==
V_156 )
return - V_13 ;
if ( F_41 ( V_188 -> V_96 , V_156 ) ==
V_156 )
return - V_13 ;
V_186 . V_190 = V_188 -> V_190 ;
V_186 . V_191 = V_188 -> V_191 ;
V_186 . V_192 = NULL ;
if ( F_41 ( V_188 -> V_96 , V_156 ) == 0 )
V_186 . V_96 = NULL ;
else
V_186 . V_96 = V_188 -> V_96 ;
F_52 ( V_184 , & V_186 , 1 ) ;
}
return 0 ;
}
static struct V_80 * F_53 (
struct V_1 * V_2 , int V_113 )
{
struct V_80 * V_142 ;
struct V_91 * V_92 ;
struct V_160 * V_161 ;
int V_18 , V_85 ;
V_142 = F_54 ( V_113 , sizeof( * V_142 ) , V_146 ) ;
if ( V_142 == NULL )
return NULL ;
for ( V_18 = 0 ; V_18 < V_113 ; V_18 ++ ) {
V_161 = (struct V_160 * ) V_2 -> V_8 ;
V_92 = F_36 ( sizeof( * V_92 ) , V_146 ) ;
if ( V_92 == NULL )
goto V_85;
V_2 -> V_8 += ( sizeof( struct V_160 ) +
V_161 -> V_157 . V_11 ) ;
if ( F_41 ( V_161 -> V_45 . V_60 , V_156 ) ==
V_156 )
goto V_193;
F_38 ( V_2 -> V_12 , L_29 ,
V_161 -> V_45 . V_60 , V_18 ) ;
V_142 [ V_18 ] . V_60 = V_161 -> V_45 . V_60 ;
V_142 [ V_18 ] . V_111 = ( long ) V_92 ;
V_142 [ V_18 ] . V_120 = V_121 ;
V_142 [ V_18 ] . V_122 = V_161 -> V_45 . V_122 ;
V_92 -> V_21 = F_6 ( V_2 , V_161 -> V_162 ,
V_163 ) ;
V_92 -> V_164 = F_6 ( V_2 , V_161 -> V_162 ,
V_165 ) ;
V_92 -> V_22 = F_7 ( V_2 , V_161 -> V_162 ,
V_163 ) ;
V_92 -> V_166 = F_7 ( V_2 , V_161 -> V_162 ,
V_165 ) ;
V_92 -> V_158 = V_161 -> V_158 ;
V_92 -> V_148 = V_161 -> V_148 ;
V_92 -> V_167 = V_161 -> V_167 ;
V_92 -> V_168 = V_161 -> V_168 ;
V_92 -> V_90 . V_57 = V_2 -> V_57 ;
F_42 ( & V_92 -> V_90 . V_98 ) ;
V_85 = F_32 ( & V_161 -> V_45 , & V_142 [ V_18 ] , V_2 ) ;
if ( V_85 ) {
F_13 ( V_2 , & V_161 -> V_45 , V_161 -> V_45 . V_60 ) ;
F_27 ( V_92 ) ;
continue;
}
V_85 = F_34 ( V_2 , & V_142 [ V_18 ] ,
(struct V_28 * ) V_161 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_161 -> V_45 . V_60 ) ;
F_27 ( V_92 ) ;
continue;
}
}
return V_142 ;
V_193:
F_27 ( V_92 ) ;
V_85:
for ( -- V_18 ; V_18 >= 0 ; V_18 -- )
F_27 ( ( void * ) V_142 [ V_18 ] . V_111 ) ;
F_27 ( V_142 ) ;
return NULL ;
}
static struct V_80 * F_55 (
struct V_1 * V_2 )
{
struct V_80 * V_142 ;
struct V_169 * V_170 ;
struct V_99 * V_100 ;
int V_18 , V_85 ;
V_170 = (struct V_169 * ) V_2 -> V_8 ;
V_2 -> V_8 += ( sizeof( struct V_169 ) +
V_170 -> V_157 . V_11 ) ;
if ( F_41 ( V_170 -> V_45 . V_60 , V_156 ) ==
V_156 )
return NULL ;
V_142 = F_36 ( sizeof( * V_142 ) , V_146 ) ;
if ( V_142 == NULL )
return NULL ;
V_100 = F_36 ( sizeof( * V_100 ) , V_146 ) ;
if ( V_100 == NULL )
goto V_85;
F_38 ( V_2 -> V_12 , L_30 ,
V_170 -> V_45 . V_60 ) ;
V_142 -> V_60 = V_170 -> V_45 . V_60 ;
V_142 -> V_111 = ( long ) V_100 ;
V_142 -> V_120 = V_121 ;
V_142 -> V_122 = V_170 -> V_45 . V_122 ;
V_100 -> V_21 = F_6 ( V_2 , V_170 -> V_162 , V_163 ) ;
V_100 -> V_174 = F_7 ( V_2 , V_170 -> V_162 , V_163 ) ;
V_100 -> V_175 = F_7 ( V_2 , V_170 -> V_162 , V_165 ) ;
V_100 -> V_102 = V_170 -> V_102 ;
V_100 -> V_176 = V_170 -> V_176 ;
V_100 -> V_90 . V_57 = V_2 -> V_57 ;
switch ( V_170 -> V_45 . V_31 . V_32 ) {
case V_40 :
case V_177 :
V_85 = F_47 ( V_100 , V_170 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_21 ,
V_170 -> V_45 . V_60 ) ;
goto V_194;
}
case V_39 :
case V_178 :
case V_179 :
V_85 = F_45 ( V_100 , V_170 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_22 ,
V_170 -> V_45 . V_60 ) ;
goto V_194;
}
break;
default:
F_2 ( V_2 -> V_12 , L_23 ,
V_170 -> V_45 . V_31 . V_32 , V_170 -> V_45 . V_60 ) ;
goto V_194;
}
V_85 = F_32 ( & V_170 -> V_45 , V_142 , V_2 ) ;
if ( V_85 ) {
F_13 ( V_2 , & V_170 -> V_45 , V_170 -> V_45 . V_60 ) ;
goto V_194;
}
V_85 = F_34 ( V_2 , V_142 ,
(struct V_28 * ) V_170 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_170 -> V_45 . V_60 ) ;
goto V_194;
}
return V_142 ;
V_194:
F_27 ( V_100 -> V_90 . V_96 . V_101 ) ;
for ( V_18 = 0 ; V_18 < V_170 -> V_102 ; V_18 ++ )
F_27 ( V_100 -> V_90 . V_96 . V_103 [ V_18 ] ) ;
F_27 ( V_100 ) ;
V_85:
F_27 ( V_142 ) ;
return NULL ;
}
static struct V_80 * F_56 (
struct V_1 * V_2 , int V_4 )
{
struct V_126 * V_127 ;
struct V_104 * V_125 ;
struct V_80 * V_142 ;
int V_18 , V_85 ;
V_142 = F_54 ( V_4 , sizeof( * V_142 ) , V_146 ) ;
if ( ! V_142 )
return NULL ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_127 = (struct V_126 * ) V_2 -> V_8 ;
if ( F_41 ( V_127 -> V_45 . V_60 , V_156 ) ==
V_156 )
goto V_85;
V_125 = F_36 ( sizeof( * V_125 ) , V_146 ) ;
if ( V_125 == NULL )
goto V_85;
V_2 -> V_8 += ( sizeof( struct V_126 ) +
V_127 -> V_157 . V_11 ) ;
F_38 ( V_2 -> V_12 ,
L_12 ,
V_127 -> V_45 . V_60 , V_127 -> V_45 . V_122 ) ;
V_142 [ V_18 ] . V_60 = V_127 -> V_45 . V_60 ;
V_142 [ V_18 ] . V_111 = ( long ) V_125 ;
V_142 [ V_18 ] . V_120 = V_121 ;
V_142 [ V_18 ] . V_122 = V_127 -> V_45 . V_122 ;
V_125 -> V_158 = V_127 -> V_158 ;
F_42 ( & V_125 -> V_90 . V_98 ) ;
V_85 = F_32 ( & V_127 -> V_45 , & V_142 [ V_18 ] , V_2 ) ;
if ( V_85 ) {
F_13 ( V_2 , & V_127 -> V_45 , V_127 -> V_45 . V_60 ) ;
F_27 ( V_125 ) ;
continue;
}
V_85 = F_34 ( V_2 , & V_142 [ V_18 ] ,
(struct V_28 * ) V_127 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_127 -> V_45 . V_60 ) ;
F_27 ( V_125 ) ;
continue;
}
}
return V_142 ;
V_85:
for ( -- V_18 ; V_18 >= 0 ; V_18 -- )
F_27 ( ( void * ) V_142 [ V_18 ] . V_111 ) ;
F_27 ( V_142 ) ;
return NULL ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_69 * V_68 )
{
struct V_183 * V_184 = & V_2 -> V_62 -> V_184 ;
struct V_67 V_195 , * V_108 ;
struct V_28 * V_29 ;
struct V_196 * V_78 = V_2 -> V_62 -> V_78 ;
int V_61 = 0 ;
if ( F_41 ( V_68 -> V_60 , V_156 ) ==
V_156 )
return - V_13 ;
if ( F_41 ( V_68 -> V_197 , V_156 ) ==
V_156 )
return - V_13 ;
F_38 ( V_2 -> V_12 , L_31 ,
V_68 -> V_60 , V_68 -> V_20 ) ;
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
V_195 . V_20 = F_8 ( V_68 -> V_20 ) ;
if ( V_195 . V_20 < 0 )
return V_195 . V_20 ;
V_195 . V_60 = F_46 ( V_68 -> V_60 , V_146 ) ;
if ( ! V_195 . V_60 )
return - V_86 ;
V_195 . V_197 = F_46 ( V_68 -> V_197 , V_146 ) ;
if ( ! V_195 . V_197 ) {
V_61 = - V_86 ;
goto V_85;
}
V_195 . V_21 = V_68 -> V_21 ;
V_195 . V_22 = V_68 -> V_22 ;
V_195 . V_176 = V_68 -> V_176 ;
V_195 . V_198 = V_68 -> V_198 ;
V_195 . V_199 = V_68 -> V_167 ? 0 : 1 ;
V_195 . V_200 = V_68 -> V_167 ? 1 : 0 ;
V_195 . V_201 = V_68 -> V_201 ;
V_195 . V_202 = V_68 -> V_202 ;
V_195 . V_90 . V_57 = V_2 -> V_57 ;
V_2 -> V_8 +=
( sizeof( struct V_69 ) + V_68 -> V_157 . V_11 ) ;
if ( V_68 -> V_113 == 0 ) {
V_195 . V_113 = 0 ;
goto V_108;
}
V_29 = (struct V_28 * ) V_2 -> V_8 ;
F_38 ( V_2 -> V_12 , L_32 ,
V_68 -> V_60 , V_68 -> V_113 , V_29 -> type ) ;
switch ( V_29 -> V_31 . V_32 ) {
case V_33 :
case V_37 :
case V_34 :
case V_35 :
case V_36 :
case V_181 :
V_195 . V_113 = V_68 -> V_113 ;
V_195 . V_112 =
F_53 ( V_2 ,
V_195 . V_113 ) ;
if ( ! V_195 . V_112 ) {
V_61 = - V_86 ;
goto V_203;
}
break;
case V_39 :
case V_40 :
case V_178 :
case V_179 :
case V_177 :
V_195 . V_90 . V_108 . V_109 = 1 ;
V_195 . V_113 = 1 ;
V_195 . V_112 =
F_55 ( V_2 ) ;
if ( ! V_195 . V_112 ) {
V_61 = - V_86 ;
goto V_203;
}
break;
case V_42 :
V_195 . V_113 = V_68 -> V_113 ;
V_195 . V_112 =
F_56 ( V_2 ,
V_195 . V_113 ) ;
if ( ! V_195 . V_112 ) {
V_61 = - V_86 ;
goto V_203;
}
break;
default:
F_2 ( V_2 -> V_12 , L_33 ,
V_29 -> V_31 . V_58 , V_29 -> V_31 . V_59 ,
V_29 -> V_31 . V_32 ) ;
V_61 = - V_13 ;
goto V_203;
}
V_108:
V_61 = F_16 ( V_2 , & V_195 , V_68 ) ;
if ( V_61 < 0 )
goto V_203;
if ( V_78 -> V_204 )
V_108 = F_58 ( V_184 , & V_195 ) ;
else
V_108 = F_59 ( V_184 , & V_195 ) ;
if ( V_108 == NULL ) {
F_2 ( V_2 -> V_12 , L_34 ,
V_68 -> V_60 ) ;
goto V_203;
}
V_108 -> V_90 . type = V_50 ;
V_108 -> V_90 . V_31 = V_2 -> V_31 ;
V_108 -> V_90 . V_57 = V_2 -> V_57 ;
F_43 ( & V_108 -> V_90 . V_98 , & V_2 -> V_62 -> V_159 ) ;
return 0 ;
V_203:
F_27 ( V_195 . V_197 ) ;
V_85:
F_27 ( V_195 . V_60 ) ;
return V_61 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_69 * V_108 ;
int V_61 , V_4 = V_45 -> V_4 , V_18 ;
if ( V_2 -> V_65 != V_106 )
return 0 ;
F_38 ( V_2 -> V_12 , L_35 , V_4 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_108 = (struct V_69 * ) V_2 -> V_8 ;
V_61 = F_57 ( V_2 , V_108 ) ;
if ( V_61 < 0 )
F_2 ( V_2 -> V_12 , L_36 ,
V_108 -> V_60 ) ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_196 * V_78 = V_2 -> V_62 -> V_78 ;
int V_61 ;
if ( ! V_78 || ! V_78 -> V_204 ) {
F_62 ( V_2 -> V_12 , L_37
L_38 ) ;
return 0 ;
}
V_61 = F_63 ( V_78 ) ;
if ( V_61 < 0 )
F_2 ( V_2 -> V_12 , L_39 ,
V_61 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_72 * V_73 ;
struct V_89 * V_90 ;
int V_4 = V_45 -> V_4 ;
int V_61 ;
if ( V_2 -> V_65 != V_114 )
return 0 ;
V_73 = (struct V_72 * ) V_2 -> V_8 ;
if ( F_1 ( V_2 ,
sizeof( struct V_205 ) , V_4 ,
V_45 -> V_180 , L_40 ) ) {
F_2 ( V_2 -> V_12 , L_41 ,
V_4 ) ;
return - V_13 ;
}
F_38 ( V_2 -> V_12 , L_42 , V_4 ) ;
V_2 -> V_8 += sizeof( struct V_205 ) * V_4 ;
V_90 = F_36 ( sizeof( struct V_89 ) , V_146 ) ;
if ( V_90 == NULL )
return - V_86 ;
V_61 = F_17 ( V_2 , V_73 , V_4 ) ;
if ( V_61 < 0 ) {
F_2 ( V_2 -> V_62 -> V_12 , L_43 ) ;
goto V_85;
}
V_90 -> type = F_11 ( V_45 , NULL ) ;
V_90 -> V_73 . V_4 = V_4 ;
V_90 -> V_73 . V_206 = V_73 ;
V_90 -> V_31 = V_2 -> V_31 ;
V_90 -> V_57 = V_2 -> V_57 ;
F_43 ( & V_90 -> V_98 , & V_2 -> V_62 -> V_159 ) ;
return 0 ;
V_85:
F_27 ( V_90 ) ;
return V_61 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_207 * V_208 ;
if ( V_2 -> V_65 != V_209 )
return 0 ;
V_208 = (struct V_207 * ) V_2 -> V_8 ;
V_2 -> V_8 += sizeof( struct V_207 ) ;
if ( V_2 -> V_62 && V_2 -> V_31 && V_2 -> V_31 -> V_208 )
return V_2 -> V_31 -> V_208 ( V_2 -> V_62 , V_208 ) ;
F_2 ( V_2 -> V_12 , L_44 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
if ( F_4 ( V_2 ) >= V_2 -> V_9 -> V_11 )
return 0 ;
if ( V_45 -> V_210 == F_67 ( V_211 ) ) {
F_2 ( V_2 -> V_12 ,
L_45 ,
V_2 -> V_65 , V_45 -> V_210 ,
F_4 ( V_2 ) , V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_45 -> V_210 != V_211 ) {
F_2 ( V_2 -> V_12 ,
L_46 ,
V_2 -> V_65 , V_45 -> V_210 ,
F_4 ( V_2 ) , V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_45 -> V_212 != V_213 ) {
F_2 ( V_2 -> V_12 ,
L_47 ,
V_2 -> V_65 , V_45 -> V_212 ,
V_213 , F_4 ( V_2 ) ,
V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_45 -> V_180 == 0 ) {
F_2 ( V_2 -> V_12 , L_48 ,
F_4 ( V_2 ) ) ;
return - V_13 ;
}
if ( V_2 -> V_65 == V_45 -> type )
F_38 ( V_2 -> V_12 ,
L_49 ,
V_45 -> V_180 , V_45 -> type , V_45 -> V_214 ,
V_45 -> V_64 , V_2 -> V_65 ) ;
return 1 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
V_2 -> V_8 = V_2 -> V_14 + sizeof( struct V_44 ) ;
if ( V_45 -> V_57 != V_2 -> V_215 &&
V_45 -> V_57 != V_216 )
return 0 ;
V_2 -> V_57 = V_45 -> V_57 ;
switch ( V_45 -> type ) {
case V_46 :
case V_217 :
case V_218 :
return F_50 ( V_2 , V_45 ) ;
case V_47 :
return F_51 ( V_2 , V_45 ) ;
case V_49 :
return F_60 ( V_2 , V_45 ) ;
case V_53 :
case V_51 :
case V_55 :
return F_64 ( V_2 , V_45 ) ;
case V_48 :
return F_65 ( V_2 , V_45 ) ;
default:
return F_15 ( V_2 , V_45 ) ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
int V_61 ;
V_2 -> V_65 = V_219 ;
while ( V_2 -> V_65 <= V_220 ) {
V_2 -> V_14 = V_2 -> V_9 -> V_10 ;
V_45 = (struct V_44 * ) V_2 -> V_14 ;
while ( ! F_3 ( V_2 ) ) {
V_61 = F_66 ( V_2 , V_45 ) ;
if ( V_61 < 0 )
return V_61 ;
else if ( V_61 == 0 )
break;
V_61 = F_68 ( V_2 , V_45 ) ;
if ( V_61 < 0 )
return V_61 ;
V_2 -> V_14 += V_45 -> V_180 +
sizeof( struct V_44 ) ;
V_45 = (struct V_44 * ) V_2 -> V_14 ;
}
V_2 -> V_65 ++ ;
}
V_61 = F_61 ( V_2 ) ;
if ( V_61 < 0 )
F_2 ( V_2 -> V_12 ,
L_50 ) ;
return V_61 ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_61 ;
V_61 = F_69 ( V_2 ) ;
if ( V_61 == 0 )
F_18 ( V_2 ) ;
return V_61 ;
}
int F_71 ( struct V_88 * V_62 ,
struct V_221 * V_31 , const struct V_222 * V_9 , V_173 V_20 )
{
struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_9 = V_9 ;
V_2 . V_12 = V_62 -> V_12 ;
V_2 . V_62 = V_62 ;
V_2 . V_31 = V_31 ;
V_2 . V_215 = V_20 ;
V_2 . V_133 = V_31 -> V_133 ;
V_2 . V_134 = V_31 -> V_134 ;
V_2 . V_131 = V_31 -> V_131 ;
V_2 . V_132 = V_31 -> V_132 ;
return F_70 ( & V_2 ) ;
}
void F_72 ( struct V_67 * V_68 )
{
if ( V_68 -> V_90 . type != V_50 )
return;
F_30 ( V_68 -> V_184 -> V_223 , & V_68 -> V_90 , V_106 ) ;
}
void F_73 ( struct V_183 * V_184 ,
V_173 V_57 )
{
struct V_67 * V_68 , * V_224 ;
F_74 (w, next_w, &dapm->card->widgets, list) {
if ( V_68 -> V_90 . type != V_50 || V_68 -> V_184 != V_184 )
continue;
if ( V_68 -> V_90 . V_57 != V_57 &&
V_68 -> V_90 . V_57 != V_216 )
continue;
F_72 ( V_68 ) ;
F_75 ( V_68 ) ;
}
F_76 ( V_184 ) ;
}
int F_77 ( struct V_88 * V_62 , V_173 V_57 )
{
struct V_89 * V_90 , * V_225 ;
int V_65 = V_220 ;
while ( V_65 >= V_219 ) {
F_74 (dobj, next_dobj, &comp->dobj_list,
list) {
if ( V_90 -> V_57 != V_57 &&
V_90 -> V_57 != V_216 )
continue;
switch ( V_90 -> type ) {
case V_38 :
F_23 ( V_62 , V_90 , V_65 ) ;
break;
case V_41 :
F_28 ( V_62 , V_90 , V_65 ) ;
break;
case V_43 :
F_29 ( V_62 , V_90 , V_65 ) ;
break;
case V_50 :
F_30 ( V_62 , V_90 , V_65 ) ;
break;
case V_54 :
case V_52 :
case V_56 :
F_31 ( V_62 , V_90 , V_65 ) ;
break;
default:
F_2 ( V_62 -> V_12 , L_51 ,
V_90 -> type ) ;
break;
}
}
V_65 -- ;
}
return ! F_78 ( & V_62 -> V_159 ) ;
}
