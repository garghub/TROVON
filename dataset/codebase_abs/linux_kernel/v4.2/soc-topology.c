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
const struct V_116 * V_31 , int V_117 ,
const struct V_116 * V_118 , int V_119 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_117 ; V_18 ++ ) {
if ( V_31 [ V_18 ] . V_20 == V_45 -> V_31 . V_59 )
V_87 -> V_59 = V_31 [ V_18 ] . V_59 ;
if ( V_31 [ V_18 ] . V_20 == V_45 -> V_31 . V_58 )
V_87 -> V_58 = V_31 [ V_18 ] . V_58 ;
if ( V_31 [ V_18 ] . V_20 == V_45 -> V_31 . V_32 )
V_87 -> V_32 = V_31 [ V_18 ] . V_32 ;
}
if ( V_87 -> V_59 && V_87 -> V_58 && V_87 -> V_32 )
return 0 ;
for ( V_18 = 0 ; V_18 < V_119 ; V_18 ++ ) {
if ( V_87 -> V_59 == NULL && V_118 [ V_18 ] . V_20 == V_45 -> V_31 . V_59 )
V_87 -> V_59 = V_118 [ V_18 ] . V_59 ;
if ( V_87 -> V_58 == NULL && V_118 [ V_18 ] . V_20 == V_45 -> V_31 . V_58 )
V_87 -> V_58 = V_118 [ V_18 ] . V_58 ;
if ( V_87 -> V_32 == NULL && V_118 [ V_18 ] . V_20 == V_45 -> V_31 . V_32 )
V_87 -> V_32 = V_118 [ V_18 ] . V_32 ;
}
if ( V_87 -> V_59 && V_87 -> V_58 && V_87 -> V_32 )
return 0 ;
return - V_13 ;
}
int F_33 ( struct V_67 * V_68 ,
const struct V_120 * V_121 ,
int V_122 , T_3 V_123 )
{
int V_18 ;
V_68 -> V_124 = NULL ;
for ( V_18 = 0 ; V_18 < V_122 ; V_18 ++ ) {
if ( V_123 == V_121 [ V_18 ] . type ) {
V_68 -> V_124 = V_121 [ V_18 ] . V_125 ;
return 0 ;
}
}
return - V_13 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_80 * V_87 , struct V_28 * V_45 )
{
if ( V_2 -> V_62 && V_2 -> V_31 && V_2 -> V_31 -> V_126 )
return V_2 -> V_31 -> V_126 ( V_2 -> V_62 , V_87 , V_45 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_80 * V_127 , struct V_128 * V_129 )
{
unsigned int V_130 = 2 * sizeof( unsigned int ) ;
unsigned int * V_93 ;
V_93 = F_36 ( V_130 + 2 * sizeof( unsigned int ) , V_131 ) ;
if ( ! V_93 )
return - V_86 ;
V_93 [ 0 ] = V_132 ;
V_93 [ 1 ] = V_130 ;
V_93 [ 2 ] = V_129 -> V_133 ;
V_93 [ 3 ] = ( V_129 -> V_134 & V_135 )
| ( V_129 -> V_136 ? V_137 : 0 ) ;
V_127 -> V_97 . V_93 = ( void * ) V_93 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_80 * V_127 , struct V_28 * V_138 )
{
struct V_139 * V_140 ;
if ( ! ( V_138 -> V_141 & V_142 ) )
return 0 ;
if ( V_138 -> V_141 & V_143 ) {
V_127 -> V_97 . V_144 = V_145 ;
} else {
V_140 = & V_138 -> V_97 ;
switch ( V_140 -> type ) {
case V_132 :
return F_35 ( V_2 , V_127 ,
& V_140 -> V_129 ) ;
default:
F_38 ( V_2 -> V_12 , L_9 ,
V_140 -> type ) ;
return - V_13 ;
}
}
return 0 ;
}
static inline void F_39 ( struct V_1 * V_2 ,
struct V_80 * V_127 )
{
F_27 ( V_127 -> V_97 . V_93 ) ;
}
static int F_40 ( struct V_1 * V_2 , unsigned int V_4 ,
T_1 V_11 )
{
struct V_146 * V_147 ;
struct V_104 * V_148 ;
struct V_80 V_127 ;
int V_18 , V_85 ;
if ( F_1 ( V_2 ,
sizeof( struct V_146 ) , V_4 ,
V_11 , L_10 ) ) {
F_2 ( V_2 -> V_12 , L_11 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_147 = (struct V_146 * ) V_2 -> V_8 ;
if ( F_41 ( V_147 -> V_45 . V_60 , V_149 ) ==
V_149 )
return - V_13 ;
V_148 = F_36 ( sizeof( * V_148 ) , V_131 ) ;
if ( V_148 == NULL )
return - V_86 ;
V_2 -> V_8 += ( sizeof( struct V_146 ) +
V_147 -> V_150 . V_11 ) ;
F_38 ( V_2 -> V_12 ,
L_12 ,
V_147 -> V_45 . V_60 , V_147 -> V_45 . V_141 ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_60 = V_147 -> V_45 . V_60 ;
V_127 . V_111 = ( long ) V_148 ;
V_127 . V_151 = V_152 ;
V_127 . V_141 = V_147 -> V_45 . V_141 ;
V_148 -> V_153 = V_147 -> V_153 ;
V_148 -> V_90 . type = V_43 ;
V_148 -> V_90 . V_31 = V_2 -> V_31 ;
F_42 ( & V_148 -> V_90 . V_98 ) ;
V_85 = F_32 ( & V_147 -> V_45 , & V_127 , V_154 ,
F_9 ( V_154 ) , V_2 -> V_154 , V_2 -> V_155 ) ;
if ( V_85 ) {
F_13 ( V_2 , & V_147 -> V_45 , V_147 -> V_45 . V_60 ) ;
F_27 ( V_148 ) ;
continue;
}
V_85 = F_34 ( V_2 , & V_127 ,
(struct V_28 * ) V_147 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_147 -> V_45 . V_60 ) ;
F_27 ( V_148 ) ;
continue;
}
V_85 = F_22 ( V_2 , & V_127 ,
& V_148 -> V_90 . V_96 . V_84 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_14 ,
V_147 -> V_45 . V_60 ) ;
F_27 ( V_148 ) ;
continue;
}
F_43 ( & V_148 -> V_90 . V_98 , & V_2 -> V_62 -> V_156 ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , unsigned int V_4 ,
T_1 V_11 )
{
struct V_157 * V_158 ;
struct V_91 * V_92 ;
struct V_80 V_127 ;
int V_18 , V_85 ;
if ( F_1 ( V_2 ,
sizeof( struct V_157 ) ,
V_4 , V_11 , L_15 ) ) {
F_2 ( V_2 -> V_12 , L_16 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_158 = (struct V_157 * ) V_2 -> V_8 ;
if ( F_41 ( V_158 -> V_45 . V_60 , V_149 ) ==
V_149 )
return - V_13 ;
V_92 = F_36 ( sizeof( * V_92 ) , V_131 ) ;
if ( V_92 == NULL )
return - V_86 ;
V_2 -> V_8 += ( sizeof( struct V_157 ) +
V_158 -> V_150 . V_11 ) ;
F_38 ( V_2 -> V_12 ,
L_17 ,
V_158 -> V_45 . V_60 , V_158 -> V_45 . V_141 ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_60 = V_158 -> V_45 . V_60 ;
V_127 . V_111 = ( long ) V_92 ;
V_127 . V_151 = V_152 ;
V_127 . V_141 = V_158 -> V_45 . V_141 ;
V_92 -> V_21 = F_6 ( V_2 , V_158 -> V_159 ,
V_160 ) ;
V_92 -> V_161 = F_6 ( V_2 , V_158 -> V_159 ,
V_162 ) ;
V_92 -> V_22 = F_7 ( V_2 , V_158 -> V_159 ,
V_160 ) ;
V_92 -> V_163 = F_7 ( V_2 , V_158 -> V_159 ,
V_162 ) ;
V_92 -> V_153 = V_158 -> V_153 ;
V_92 -> V_133 = V_158 -> V_133 ;
V_92 -> V_164 = V_158 -> V_164 ;
V_92 -> V_165 = V_158 -> V_165 ;
V_92 -> V_90 . V_57 = V_2 -> V_57 ;
V_92 -> V_90 . V_31 = V_2 -> V_31 ;
V_92 -> V_90 . type = V_38 ;
F_42 ( & V_92 -> V_90 . V_98 ) ;
V_85 = F_32 ( & V_158 -> V_45 , & V_127 , V_154 ,
F_9 ( V_154 ) , V_2 -> V_154 , V_2 -> V_155 ) ;
if ( V_85 ) {
F_13 ( V_2 , & V_158 -> V_45 , V_158 -> V_45 . V_60 ) ;
F_27 ( V_92 ) ;
continue;
}
V_85 = F_34 ( V_2 , & V_127 ,
(struct V_28 * ) V_158 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_158 -> V_45 . V_60 ) ;
F_27 ( V_92 ) ;
continue;
}
F_37 ( V_2 , & V_127 , & V_158 -> V_45 ) ;
V_85 = F_22 ( V_2 , & V_127 ,
& V_92 -> V_90 . V_96 . V_84 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_14 ,
V_158 -> V_45 . V_60 ) ;
F_39 ( V_2 , & V_127 ) ;
F_27 ( V_92 ) ;
continue;
}
F_43 ( & V_92 -> V_90 . V_98 , & V_2 -> V_62 -> V_156 ) ;
}
return 0 ;
}
static int F_45 ( struct V_99 * V_100 ,
struct V_166 * V_167 )
{
int V_18 , V_61 ;
V_100 -> V_90 . V_96 . V_103 =
F_36 ( sizeof( char * ) * V_167 -> V_102 , V_131 ) ;
if ( V_100 -> V_90 . V_96 . V_103 == NULL )
return - V_86 ;
for ( V_18 = 0 ; V_18 < V_167 -> V_102 ; V_18 ++ ) {
if ( F_41 ( V_167 -> V_168 [ V_18 ] , V_149 ) ==
V_149 ) {
V_61 = - V_13 ;
goto V_85;
}
V_100 -> V_90 . V_96 . V_103 [ V_18 ] = F_46 ( V_167 -> V_168 [ V_18 ] , V_131 ) ;
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
struct V_166 * V_167 )
{
if ( V_167 -> V_102 > sizeof( * V_167 -> V_169 ) )
return - V_13 ;
V_100 -> V_90 . V_96 . V_101 =
F_48 ( V_167 -> V_102 * sizeof( V_170 ) , V_131 ) ;
if ( ! V_100 -> V_90 . V_96 . V_101 )
return - V_86 ;
memcpy ( V_100 -> V_90 . V_96 . V_101 , V_167 -> V_169 , V_167 -> V_102 * sizeof( V_170 ) ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , unsigned int V_4 ,
T_1 V_11 )
{
struct V_166 * V_167 ;
struct V_99 * V_100 ;
struct V_80 V_127 ;
int V_18 , V_61 , V_85 ;
if ( F_1 ( V_2 ,
sizeof( struct V_166 ) ,
V_4 , V_11 , L_18 ) ) {
F_2 ( V_2 -> V_12 , L_19 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_167 = (struct V_166 * ) V_2 -> V_8 ;
V_2 -> V_8 += ( sizeof( struct V_166 ) +
V_167 -> V_150 . V_11 ) ;
if ( F_41 ( V_167 -> V_45 . V_60 , V_149 ) ==
V_149 )
return - V_13 ;
V_100 = F_36 ( ( sizeof( * V_100 ) ) , V_131 ) ;
if ( V_100 == NULL )
return - V_86 ;
F_38 ( V_2 -> V_12 , L_20 ,
V_167 -> V_45 . V_60 , V_167 -> V_102 ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_60 = V_167 -> V_45 . V_60 ;
V_127 . V_111 = ( long ) V_100 ;
V_127 . V_151 = V_152 ;
V_127 . V_141 = V_167 -> V_45 . V_141 ;
V_100 -> V_21 = F_6 ( V_2 , V_167 -> V_159 , V_160 ) ;
V_100 -> V_171 = F_7 ( V_2 , V_167 -> V_159 ,
V_160 ) ;
V_100 -> V_172 = F_7 ( V_2 , V_167 -> V_159 ,
V_160 ) ;
V_100 -> V_102 = V_167 -> V_102 ;
V_100 -> V_173 = V_167 -> V_173 ;
V_100 -> V_90 . V_57 = V_2 -> V_57 ;
V_100 -> V_90 . type = V_41 ;
V_100 -> V_90 . V_31 = V_2 -> V_31 ;
F_42 ( & V_100 -> V_90 . V_98 ) ;
switch ( V_167 -> V_45 . V_31 . V_32 ) {
case V_174 :
case V_40 :
V_85 = F_47 ( V_100 , V_167 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 ,
L_21 ,
V_167 -> V_45 . V_60 ) ;
F_27 ( V_100 ) ;
continue;
}
case V_39 :
case V_175 :
case V_176 :
V_85 = F_45 ( V_100 , V_167 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 ,
L_22 ,
V_167 -> V_45 . V_60 ) ;
F_27 ( V_100 ) ;
continue;
}
break;
default:
F_2 ( V_2 -> V_12 ,
L_23 ,
V_167 -> V_45 . V_31 . V_32 , V_167 -> V_45 . V_60 ) ;
F_27 ( V_100 ) ;
continue;
}
V_85 = F_32 ( & V_167 -> V_45 , & V_127 , V_154 ,
F_9 ( V_154 ) , V_2 -> V_154 , V_2 -> V_155 ) ;
if ( V_85 ) {
F_13 ( V_2 , & V_167 -> V_45 , V_167 -> V_45 . V_60 ) ;
F_27 ( V_100 ) ;
continue;
}
V_85 = F_34 ( V_2 , & V_127 ,
(struct V_28 * ) V_167 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_167 -> V_45 . V_60 ) ;
F_27 ( V_100 ) ;
continue;
}
V_61 = F_22 ( V_2 ,
& V_127 , & V_100 -> V_90 . V_96 . V_84 ) ;
if ( V_61 < 0 ) {
F_2 ( V_2 -> V_12 , L_24 ,
V_167 -> V_45 . V_60 ) ;
F_27 ( V_100 ) ;
continue;
}
F_43 ( & V_100 -> V_90 . V_98 , & V_2 -> V_62 -> V_156 ) ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_28 * V_29 ;
int V_18 ;
if ( V_2 -> V_65 != V_94 ) {
V_2 -> V_8 += V_45 -> V_11 + V_45 -> V_177 ;
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
case V_178 :
case V_179 :
F_44 ( V_2 , 1 , V_45 -> V_177 ) ;
break;
case V_39 :
case V_40 :
case V_175 :
case V_176 :
case V_174 :
F_49 ( V_2 , 1 , V_45 -> V_177 ) ;
break;
case V_42 :
F_40 ( V_2 , 1 , V_45 -> V_177 ) ;
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
struct V_180 * V_181 = & V_2 -> V_62 -> V_181 ;
struct V_182 V_183 ;
struct V_184 * V_185 ;
int V_4 = V_45 -> V_4 , V_18 ;
if ( V_2 -> V_65 != V_186 ) {
V_2 -> V_8 += V_45 -> V_11 + V_45 -> V_177 ;
return 0 ;
}
if ( F_1 ( V_2 ,
sizeof( struct V_184 ) ,
V_4 , V_45 -> V_177 , L_26 ) ) {
F_2 ( V_2 -> V_12 , L_27 ,
V_4 ) ;
return - V_13 ;
}
F_38 ( V_2 -> V_12 , L_28 , V_4 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_185 = (struct V_184 * ) V_2 -> V_8 ;
V_2 -> V_8 += sizeof( struct V_184 ) ;
if ( F_41 ( V_185 -> V_187 , V_149 ) ==
V_149 )
return - V_13 ;
if ( F_41 ( V_185 -> V_188 , V_149 ) ==
V_149 )
return - V_13 ;
if ( F_41 ( V_185 -> V_96 , V_149 ) ==
V_149 )
return - V_13 ;
V_183 . V_187 = V_185 -> V_187 ;
V_183 . V_188 = V_185 -> V_188 ;
V_183 . V_189 = NULL ;
if ( F_41 ( V_185 -> V_96 , V_149 ) == 0 )
V_183 . V_96 = NULL ;
else
V_183 . V_96 = V_185 -> V_96 ;
F_52 ( V_181 , & V_183 , 1 ) ;
}
return 0 ;
}
static struct V_80 * F_53 (
struct V_1 * V_2 , int V_113 )
{
struct V_80 * V_127 ;
struct V_91 * V_92 ;
struct V_157 * V_158 ;
int V_18 , V_85 ;
V_127 = F_36 ( sizeof( * V_127 ) * V_113 , V_131 ) ;
if ( V_127 == NULL )
return NULL ;
for ( V_18 = 0 ; V_18 < V_113 ; V_18 ++ ) {
V_158 = (struct V_157 * ) V_2 -> V_8 ;
V_92 = F_36 ( sizeof( * V_92 ) , V_131 ) ;
if ( V_92 == NULL )
goto V_85;
V_2 -> V_8 += ( sizeof( struct V_157 ) +
V_158 -> V_150 . V_11 ) ;
if ( F_41 ( V_158 -> V_45 . V_60 , V_149 ) ==
V_149 )
goto V_190;
F_38 ( V_2 -> V_12 , L_29 ,
V_158 -> V_45 . V_60 , V_18 ) ;
V_127 [ V_18 ] . V_60 = V_158 -> V_45 . V_60 ;
V_127 [ V_18 ] . V_111 = ( long ) V_92 ;
V_127 [ V_18 ] . V_151 = V_152 ;
V_127 [ V_18 ] . V_141 = V_158 -> V_45 . V_141 ;
V_92 -> V_21 = F_6 ( V_2 , V_158 -> V_159 ,
V_160 ) ;
V_92 -> V_161 = F_6 ( V_2 , V_158 -> V_159 ,
V_162 ) ;
V_92 -> V_22 = F_7 ( V_2 , V_158 -> V_159 ,
V_160 ) ;
V_92 -> V_163 = F_7 ( V_2 , V_158 -> V_159 ,
V_162 ) ;
V_92 -> V_153 = V_158 -> V_153 ;
V_92 -> V_133 = V_158 -> V_133 ;
V_92 -> V_164 = V_158 -> V_164 ;
V_92 -> V_165 = V_158 -> V_165 ;
V_92 -> V_90 . V_57 = V_2 -> V_57 ;
F_42 ( & V_92 -> V_90 . V_98 ) ;
V_85 = F_32 ( & V_158 -> V_45 , & V_127 [ V_18 ] , V_154 ,
F_9 ( V_154 ) , V_2 -> V_154 , V_2 -> V_155 ) ;
if ( V_85 ) {
F_13 ( V_2 , & V_158 -> V_45 , V_158 -> V_45 . V_60 ) ;
F_27 ( V_92 ) ;
continue;
}
V_85 = F_34 ( V_2 , & V_127 [ V_18 ] ,
(struct V_28 * ) V_158 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_158 -> V_45 . V_60 ) ;
F_27 ( V_92 ) ;
continue;
}
}
return V_127 ;
V_190:
F_27 ( V_92 ) ;
V_85:
for ( -- V_18 ; V_18 >= 0 ; V_18 -- )
F_27 ( ( void * ) V_127 [ V_18 ] . V_111 ) ;
F_27 ( V_127 ) ;
return NULL ;
}
static struct V_80 * F_54 (
struct V_1 * V_2 )
{
struct V_80 * V_127 ;
struct V_166 * V_167 ;
struct V_99 * V_100 ;
int V_18 , V_85 ;
V_167 = (struct V_166 * ) V_2 -> V_8 ;
V_2 -> V_8 += ( sizeof( struct V_166 ) +
V_167 -> V_150 . V_11 ) ;
if ( F_41 ( V_167 -> V_45 . V_60 , V_149 ) ==
V_149 )
return NULL ;
V_127 = F_36 ( sizeof( * V_127 ) , V_131 ) ;
if ( V_127 == NULL )
return NULL ;
V_100 = F_36 ( sizeof( * V_100 ) , V_131 ) ;
if ( V_100 == NULL )
goto V_85;
F_38 ( V_2 -> V_12 , L_30 ,
V_167 -> V_45 . V_60 ) ;
V_127 -> V_60 = V_167 -> V_45 . V_60 ;
V_127 -> V_111 = ( long ) V_100 ;
V_127 -> V_151 = V_152 ;
V_127 -> V_141 = V_167 -> V_45 . V_141 ;
V_100 -> V_21 = F_6 ( V_2 , V_167 -> V_159 , V_160 ) ;
V_100 -> V_171 = F_7 ( V_2 , V_167 -> V_159 , V_160 ) ;
V_100 -> V_172 = F_7 ( V_2 , V_167 -> V_159 , V_162 ) ;
V_100 -> V_102 = V_167 -> V_102 ;
V_100 -> V_173 = V_167 -> V_173 ;
V_100 -> V_90 . V_57 = V_2 -> V_57 ;
switch ( V_167 -> V_45 . V_31 . V_32 ) {
case V_40 :
case V_174 :
V_85 = F_47 ( V_100 , V_167 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_21 ,
V_167 -> V_45 . V_60 ) ;
goto V_191;
}
case V_39 :
case V_175 :
case V_176 :
V_85 = F_45 ( V_100 , V_167 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_22 ,
V_167 -> V_45 . V_60 ) ;
goto V_191;
}
break;
default:
F_2 ( V_2 -> V_12 , L_23 ,
V_167 -> V_45 . V_31 . V_32 , V_167 -> V_45 . V_60 ) ;
goto V_191;
}
V_85 = F_32 ( & V_167 -> V_45 , V_127 , V_154 ,
F_9 ( V_154 ) , V_2 -> V_154 , V_2 -> V_155 ) ;
if ( V_85 ) {
F_13 ( V_2 , & V_167 -> V_45 , V_167 -> V_45 . V_60 ) ;
goto V_191;
}
V_85 = F_34 ( V_2 , V_127 ,
(struct V_28 * ) V_167 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_167 -> V_45 . V_60 ) ;
goto V_191;
}
return V_127 ;
V_191:
F_27 ( V_100 -> V_90 . V_96 . V_101 ) ;
for ( V_18 = 0 ; V_18 < V_167 -> V_102 ; V_18 ++ )
F_27 ( V_100 -> V_90 . V_96 . V_103 [ V_18 ] ) ;
F_27 ( V_100 ) ;
V_85:
F_27 ( V_127 ) ;
return NULL ;
}
static struct V_80 * F_55 (
struct V_1 * V_2 , int V_4 )
{
struct V_146 * V_147 ;
struct V_104 * V_148 ;
struct V_80 * V_127 ;
int V_18 , V_85 ;
V_127 = F_36 ( sizeof( * V_127 ) * V_4 , V_131 ) ;
if ( ! V_127 )
return NULL ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_147 = (struct V_146 * ) V_2 -> V_8 ;
if ( F_41 ( V_147 -> V_45 . V_60 , V_149 ) ==
V_149 )
goto V_85;
V_148 = F_36 ( sizeof( * V_148 ) , V_131 ) ;
if ( V_148 == NULL )
goto V_85;
V_2 -> V_8 += ( sizeof( struct V_146 ) +
V_147 -> V_150 . V_11 ) ;
F_38 ( V_2 -> V_12 ,
L_12 ,
V_147 -> V_45 . V_60 , V_147 -> V_45 . V_141 ) ;
memset ( V_127 , 0 , sizeof( * V_127 ) ) ;
V_127 [ V_18 ] . V_60 = V_147 -> V_45 . V_60 ;
V_127 [ V_18 ] . V_111 = ( long ) V_148 ;
V_127 [ V_18 ] . V_151 = V_152 ;
V_127 [ V_18 ] . V_141 = V_147 -> V_45 . V_141 ;
V_148 -> V_153 = V_147 -> V_153 ;
F_42 ( & V_148 -> V_90 . V_98 ) ;
V_85 = F_32 ( & V_147 -> V_45 , & V_127 [ V_18 ] , V_154 ,
F_9 ( V_154 ) , V_2 -> V_154 ,
V_2 -> V_155 ) ;
if ( V_85 ) {
F_13 ( V_2 , & V_147 -> V_45 , V_147 -> V_45 . V_60 ) ;
F_27 ( V_148 ) ;
continue;
}
V_85 = F_34 ( V_2 , & V_127 [ V_18 ] ,
(struct V_28 * ) V_147 ) ;
if ( V_85 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_147 -> V_45 . V_60 ) ;
F_27 ( V_148 ) ;
continue;
}
}
return V_127 ;
V_85:
for ( -- V_18 ; V_18 >= 0 ; V_18 -- )
F_27 ( ( void * ) V_127 [ V_18 ] . V_111 ) ;
F_27 ( V_127 ) ;
return NULL ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_69 * V_68 )
{
struct V_180 * V_181 = & V_2 -> V_62 -> V_181 ;
struct V_67 V_192 , * V_108 ;
struct V_28 * V_29 ;
struct V_193 * V_78 = V_2 -> V_62 -> V_78 ;
int V_61 = 0 ;
if ( F_41 ( V_68 -> V_60 , V_149 ) ==
V_149 )
return - V_13 ;
if ( F_41 ( V_68 -> V_194 , V_149 ) ==
V_149 )
return - V_13 ;
F_38 ( V_2 -> V_12 , L_31 ,
V_68 -> V_60 , V_68 -> V_20 ) ;
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
V_192 . V_20 = F_8 ( V_68 -> V_20 ) ;
if ( V_192 . V_20 < 0 )
return V_192 . V_20 ;
V_192 . V_60 = F_46 ( V_68 -> V_60 , V_131 ) ;
if ( ! V_192 . V_60 )
return - V_86 ;
V_192 . V_194 = F_46 ( V_68 -> V_194 , V_131 ) ;
if ( ! V_192 . V_194 ) {
V_61 = - V_86 ;
goto V_85;
}
V_192 . V_21 = V_68 -> V_21 ;
V_192 . V_22 = V_68 -> V_22 ;
V_192 . V_173 = V_68 -> V_173 ;
V_192 . V_195 = V_68 -> V_195 ;
V_192 . V_196 = V_68 -> V_164 ? 0 : 1 ;
V_192 . V_197 = V_68 -> V_164 ? 1 : 0 ;
V_192 . V_198 = V_68 -> V_198 ;
V_192 . V_199 = V_68 -> V_199 ;
V_192 . V_90 . V_57 = V_2 -> V_57 ;
V_2 -> V_8 +=
( sizeof( struct V_69 ) + V_68 -> V_150 . V_11 ) ;
if ( V_68 -> V_113 == 0 ) {
V_192 . V_113 = 0 ;
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
case V_178 :
V_192 . V_113 = V_68 -> V_113 ;
V_192 . V_112 =
F_53 ( V_2 ,
V_192 . V_113 ) ;
if ( ! V_192 . V_112 ) {
V_61 = - V_86 ;
goto V_200;
}
break;
case V_39 :
case V_40 :
case V_175 :
case V_176 :
case V_174 :
V_192 . V_90 . V_108 . V_109 = 1 ;
V_192 . V_113 = 1 ;
V_192 . V_112 =
F_54 ( V_2 ) ;
if ( ! V_192 . V_112 ) {
V_61 = - V_86 ;
goto V_200;
}
break;
case V_42 :
V_192 . V_113 = V_68 -> V_113 ;
V_192 . V_112 =
F_55 ( V_2 ,
V_192 . V_113 ) ;
if ( ! V_192 . V_112 ) {
V_61 = - V_86 ;
goto V_200;
}
break;
default:
F_2 ( V_2 -> V_12 , L_33 ,
V_29 -> V_31 . V_58 , V_29 -> V_31 . V_59 ,
V_29 -> V_31 . V_32 ) ;
V_61 = - V_13 ;
goto V_200;
}
V_108:
V_61 = F_16 ( V_2 , & V_192 , V_68 ) ;
if ( V_61 < 0 )
goto V_200;
if ( V_78 -> V_201 )
V_108 = F_57 ( V_181 , & V_192 ) ;
else
V_108 = F_58 ( V_181 , & V_192 ) ;
if ( V_108 == NULL ) {
F_2 ( V_2 -> V_12 , L_34 ,
V_68 -> V_60 ) ;
goto V_200;
}
V_108 -> V_90 . type = V_50 ;
V_108 -> V_90 . V_31 = V_2 -> V_31 ;
V_108 -> V_90 . V_57 = V_2 -> V_57 ;
F_43 ( & V_108 -> V_90 . V_98 , & V_2 -> V_62 -> V_156 ) ;
return 0 ;
V_200:
F_27 ( V_192 . V_194 ) ;
V_85:
F_27 ( V_192 . V_60 ) ;
return V_61 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_69 * V_108 ;
int V_61 , V_4 = V_45 -> V_4 , V_18 ;
if ( V_2 -> V_65 != V_106 )
return 0 ;
F_38 ( V_2 -> V_12 , L_35 , V_4 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_108 = (struct V_69 * ) V_2 -> V_8 ;
V_61 = F_56 ( V_2 , V_108 ) ;
if ( V_61 < 0 )
F_2 ( V_2 -> V_12 , L_36 ,
V_108 -> V_60 ) ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_193 * V_78 = V_2 -> V_62 -> V_78 ;
int V_61 ;
if ( ! V_78 || ! V_78 -> V_201 ) {
F_61 ( V_2 -> V_12 , L_37
L_38 ) ;
return 0 ;
}
V_61 = F_62 ( V_78 ) ;
if ( V_61 < 0 )
F_2 ( V_2 -> V_12 , L_39 ,
V_61 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
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
sizeof( struct V_72 ) , V_4 ,
V_45 -> V_177 , L_40 ) ) {
F_2 ( V_2 -> V_12 , L_41 ,
V_4 ) ;
return - V_13 ;
}
F_38 ( V_2 -> V_12 , L_42 , V_4 ) ;
V_2 -> V_8 += sizeof( struct V_72 ) * V_4 ;
V_90 = F_36 ( sizeof( struct V_89 ) , V_131 ) ;
if ( V_90 == NULL )
return - V_86 ;
V_61 = F_17 ( V_2 , V_73 , V_4 ) ;
if ( V_61 < 0 ) {
F_2 ( V_2 -> V_62 -> V_12 , L_43 ) ;
goto V_85;
}
V_90 -> type = F_11 ( V_45 , NULL ) ;
V_90 -> V_73 . V_4 = V_4 ;
V_90 -> V_73 . V_202 = V_73 ;
V_90 -> V_31 = V_2 -> V_31 ;
V_90 -> V_57 = V_2 -> V_57 ;
F_43 ( & V_90 -> V_98 , & V_2 -> V_62 -> V_156 ) ;
return 0 ;
V_85:
F_27 ( V_90 ) ;
return V_61 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_203 * V_204 ;
if ( V_2 -> V_65 != V_205 )
return 0 ;
V_204 = (struct V_203 * ) V_2 -> V_8 ;
V_2 -> V_8 += sizeof( struct V_203 ) ;
if ( V_2 -> V_62 && V_2 -> V_31 && V_2 -> V_31 -> V_204 )
return V_2 -> V_31 -> V_204 ( V_2 -> V_62 , V_204 ) ;
F_2 ( V_2 -> V_12 , L_44 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
if ( F_4 ( V_2 ) >= V_2 -> V_9 -> V_11 )
return 0 ;
if ( V_45 -> V_206 == F_66 ( V_207 ) ) {
F_2 ( V_2 -> V_12 ,
L_45 ,
V_2 -> V_65 , V_45 -> V_206 ,
F_4 ( V_2 ) , V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_45 -> V_206 != V_207 ) {
F_2 ( V_2 -> V_12 ,
L_46 ,
V_2 -> V_65 , V_45 -> V_206 ,
F_4 ( V_2 ) , V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_45 -> V_208 != V_209 ) {
F_2 ( V_2 -> V_12 ,
L_47 ,
V_2 -> V_65 , V_45 -> V_208 ,
V_209 , F_4 ( V_2 ) ,
V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_45 -> V_177 == 0 ) {
F_2 ( V_2 -> V_12 , L_48 ,
F_4 ( V_2 ) ) ;
return - V_13 ;
}
if ( V_2 -> V_65 == V_45 -> type )
F_38 ( V_2 -> V_12 ,
L_49 ,
V_45 -> V_177 , V_45 -> type , V_45 -> V_210 ,
V_45 -> V_64 , V_2 -> V_65 ) ;
return 1 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
V_2 -> V_8 = V_2 -> V_14 + sizeof( struct V_44 ) ;
if ( V_45 -> V_57 != V_2 -> V_211 &&
V_45 -> V_57 != V_212 )
return 0 ;
V_2 -> V_57 = V_45 -> V_57 ;
switch ( V_45 -> type ) {
case V_46 :
case V_213 :
case V_214 :
return F_50 ( V_2 , V_45 ) ;
case V_47 :
return F_51 ( V_2 , V_45 ) ;
case V_49 :
return F_59 ( V_2 , V_45 ) ;
case V_53 :
case V_51 :
case V_55 :
return F_63 ( V_2 , V_45 ) ;
case V_48 :
return F_64 ( V_2 , V_45 ) ;
default:
return F_15 ( V_2 , V_45 ) ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
int V_61 ;
V_2 -> V_65 = V_215 ;
while ( V_2 -> V_65 <= V_216 ) {
V_2 -> V_14 = V_2 -> V_9 -> V_10 ;
V_45 = (struct V_44 * ) V_2 -> V_14 ;
while ( ! F_3 ( V_2 ) ) {
V_61 = F_65 ( V_2 , V_45 ) ;
if ( V_61 < 0 )
return V_61 ;
else if ( V_61 == 0 )
break;
V_61 = F_67 ( V_2 , V_45 ) ;
if ( V_61 < 0 )
return V_61 ;
V_2 -> V_14 += V_45 -> V_177 +
sizeof( struct V_44 ) ;
V_45 = (struct V_44 * ) V_2 -> V_14 ;
}
V_2 -> V_65 ++ ;
}
V_61 = F_60 ( V_2 ) ;
if ( V_61 < 0 )
F_2 ( V_2 -> V_12 ,
L_50 ) ;
return V_61 ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_61 ;
V_61 = F_68 ( V_2 ) ;
if ( V_61 == 0 )
F_18 ( V_2 ) ;
return V_61 ;
}
int F_70 ( struct V_88 * V_62 ,
struct V_217 * V_31 , const struct V_218 * V_9 , V_170 V_20 )
{
struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_9 = V_9 ;
V_2 . V_12 = V_62 -> V_12 ;
V_2 . V_62 = V_62 ;
V_2 . V_31 = V_31 ;
V_2 . V_211 = V_20 ;
V_2 . V_154 = V_31 -> V_154 ;
V_2 . V_155 = V_31 -> V_155 ;
return F_69 ( & V_2 ) ;
}
void F_71 ( struct V_67 * V_68 )
{
if ( V_68 -> V_90 . type != V_50 )
return;
F_30 ( V_68 -> V_181 -> V_219 , & V_68 -> V_90 , V_106 ) ;
}
void F_72 ( struct V_180 * V_181 ,
V_170 V_57 )
{
struct V_67 * V_68 , * V_220 ;
struct V_221 * V_93 , * V_222 ;
F_73 (w, next_w, &dapm->card->widgets, list) {
if ( V_68 -> V_90 . type != V_50 || V_68 -> V_181 != V_181 )
continue;
if ( V_68 -> V_90 . V_57 != V_57 &&
V_68 -> V_90 . V_57 != V_212 )
continue;
F_26 ( & V_68 -> V_98 ) ;
F_73 (p, next_p, &w->sources, list_sink) {
F_26 ( & V_93 -> V_223 ) ;
F_26 ( & V_93 -> V_224 ) ;
F_26 ( & V_93 -> V_98 ) ;
F_27 ( V_93 ) ;
}
F_73 (p, next_p, &w->sinks, list_source) {
F_26 ( & V_93 -> V_223 ) ;
F_26 ( & V_93 -> V_224 ) ;
F_26 ( & V_93 -> V_98 ) ;
F_27 ( V_93 ) ;
}
F_71 ( V_68 ) ;
F_27 ( V_68 -> V_110 ) ;
F_27 ( V_68 -> V_60 ) ;
F_27 ( V_68 ) ;
}
}
int F_74 ( struct V_88 * V_62 , V_170 V_57 )
{
struct V_89 * V_90 , * V_225 ;
int V_65 = V_216 ;
while ( V_65 >= V_215 ) {
F_73 (dobj, next_dobj, &comp->dobj_list,
list) {
if ( V_90 -> V_57 != V_57 &&
V_90 -> V_57 != V_212 )
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
return ! F_75 ( & V_62 -> V_156 ) ;
}
