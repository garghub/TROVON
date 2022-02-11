static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 == NULL || V_2 -> V_3 == NULL )
return - V_4 ;
return F_2 ( V_2 -> V_3 ,
V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 V_6 )
{
int V_7 = 0 ;
if ( V_2 == NULL || V_2 -> V_3 == NULL )
return - V_4 ;
V_7 = F_4 ( V_2 ,
V_8 , V_9 , 0 ) ;
if ( V_7 != 0 ) {
F_5 ( L_1 , V_6 ) ;
return V_7 ;
}
F_6 ( V_2 -> V_3 , V_10 , 0 ) ;
F_6 ( V_2 -> V_3 , V_11 , V_6 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_6 )
{
int V_7 = 0 ;
V_7 = F_3 ( V_2 , V_6 ) ;
if ( V_7 != 0 )
return V_7 ;
return F_4 ( V_2 ,
V_8 , V_9 , 0 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
T_2 V_12 , T_2 V_13 )
{
if ( V_2 == NULL || V_2 -> V_3 == NULL )
return - V_4 ;
if ( 0 != ( 3 & V_12 ) ) {
F_5 ( L_2 ) ;
return - V_4 ;
}
if ( V_13 <= ( V_12 + 3 ) ) {
F_5 ( L_3 ) ;
return - V_4 ;
}
F_6 ( V_2 -> V_3 , V_14 ,
V_15 + V_12 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_2 V_12 , T_2 V_16 , T_2 V_13 )
{
int V_7 ;
if ( V_2 == NULL || V_2 -> V_3 == NULL )
return - V_4 ;
V_7 = F_8 ( V_2 , V_12 , V_13 ) ;
if ( ! V_7 )
F_6 ( V_2 -> V_3 , V_17 , V_16 ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_6 , T_2 V_18 )
{
if ( V_2 == NULL || V_2 -> V_3 == NULL )
return - V_4 ;
F_6 ( V_2 -> V_3 , V_5 , V_18 ) ;
return F_7 ( V_2 , V_6 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
T_2 V_19 )
{
int V_20 ;
T_2 V_21 = V_15 +
V_22 +
F_12 ( struct V_23 , V_24 ) ;
if ( V_2 == NULL || V_2 -> V_3 == NULL )
return - V_4 ;
F_6 ( V_2 -> V_3 , V_25 , V_21 ) ;
for ( V_20 = 0 ; V_20 < V_2 -> V_26 ; V_20 ++ ) {
if ( V_19 ==
( F_2 ( V_2 -> V_3 , V_27 ) & V_19 ) )
break;
F_13 ( 1 ) ;
}
if ( V_20 >= V_2 -> V_26 ) {
F_5 ( L_4 ) ;
return - V_4 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_2 V_28 ;
T_2 V_29 ;
int V_30 = 0 ;
struct V_31 V_32 = { 0 } ;
struct V_33 * V_34 ;
if ( V_2 == NULL || V_2 -> V_3 == NULL )
return - V_4 ;
V_34 = (struct V_33 * ) V_2 -> V_35 ;
V_30 = F_15 ( V_2 -> V_3 ,
V_36 , & V_32 ) ;
if ( V_30 )
return - V_4 ;
V_29 = F_2 ( V_2 -> V_3 ,
V_37 ) ;
V_29 = F_16 ( V_29 , V_38 , V_39 , 1 ) ;
V_29 = F_16 ( V_29 , V_38 , V_40 , 1 ) ;
F_6 ( V_2 -> V_3 , V_37 , V_29 ) ;
V_29 = F_2 ( V_2 -> V_3 ,
V_41 ) ;
V_29 = F_16 ( V_29 , V_42 , V_43 , 0 ) ;
V_29 = F_16 ( V_29 , V_42 , V_44 , 0 ) ;
V_29 = F_16 ( V_29 , V_42 , V_45 , 0 ) ;
V_29 = F_16 ( V_29 , V_42 , V_46 , 1 ) ;
F_6 ( V_2 -> V_3 , V_41 , V_29 ) ;
V_28 = F_17 ( V_32 . V_47 ) &
F_18 ( V_48 , V_49 ) ;
F_6 ( V_2 -> V_3 , V_50 , V_28 ) ;
V_28 = F_19 ( V_32 . V_47 ) &
F_18 ( V_51 , V_52 ) ;
F_6 ( V_2 -> V_3 , V_53 , V_28 ) ;
return 0 ;
}
static T_3 F_20 ( struct V_1 * V_2 ,
enum V_54 V_55 )
{
T_3 V_30 = 0 ;
switch ( V_55 ) {
case V_56 :
V_30 = V_57 ;
break;
case V_58 :
if ( V_2 -> V_59 == V_60 )
V_30 = V_57 ;
else
V_30 = V_61 ;
break;
case V_62 :
V_30 = V_63 ;
break;
case V_64 :
V_30 = V_65 ;
break;
case V_66 :
V_30 = V_67 ;
break;
case V_68 :
V_30 = V_69 ;
break;
case V_70 :
if ( V_2 -> V_59 == V_60 )
V_30 = V_69 ;
else
V_30 = V_71 ;
break;
case V_72 :
V_30 = V_73 ;
break;
case V_74 :
V_30 = V_75 ;
break;
case V_76 :
V_30 = V_77 ;
break;
case V_78 :
V_30 = V_79 ;
break;
case V_80 :
V_30 = V_81 ;
break;
case V_82 :
V_30 = V_83 ;
break;
case V_84 :
V_30 = V_85 ;
break;
case V_86 :
V_30 = V_87 ;
break;
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
V_30 = V_94 ;
break;
case V_95 :
V_30 = V_96 ;
break;
}
return V_30 ;
}
static enum V_97 F_21 ( T_2 V_98 )
{
enum V_97 V_7 = V_99 ;
switch ( V_98 ) {
case V_57 :
V_7 = V_100 ;
break;
case V_61 :
V_7 = V_101 ;
break;
case V_63 :
V_7 = V_102 ;
break;
case V_65 :
V_7 = V_103 ;
break;
case V_67 :
V_7 = V_104 ;
break;
case V_69 :
V_7 = V_105 ;
break;
case V_71 :
V_7 = V_106 ;
break;
case V_75 :
V_7 = V_107 ;
break;
default:
break;
}
return V_7 ;
}
static int F_22 (
struct V_1 * V_2 ,
enum V_54 V_108 ,
T_3 type , bool V_109 )
{
T_3 V_20 ;
struct V_33 * V_34 = (struct V_33 * ) V_2 -> V_35 ;
struct V_110 * V_111 = (struct V_110 * ) V_34 -> V_112 . V_113 ;
struct V_114 * V_115 = & V_111 -> V_116 [ V_34 -> V_117 ++ ] ;
V_115 -> type = type ;
V_115 -> V_118 = F_20 ( V_2 , V_108 ) ;
V_115 -> V_119 = V_109 ? V_120 : V_34 -> V_117 ;
for ( V_20 = 0 ; V_20 < V_34 -> V_121 ; V_20 ++ )
if ( V_34 -> V_122 [ V_20 ] . V_123 == V_108 )
break;
if ( V_20 >= V_34 -> V_121 ) {
F_5 ( L_5 ) ;
return - V_4 ;
}
V_115 -> V_124 . V_125 = V_34 -> V_122 [ V_20 ] . V_126 ;
V_115 -> V_124 . V_127 = V_34 -> V_122 [ V_20 ] . V_128 ;
V_115 -> V_129 = V_34 -> V_122 [ V_20 ] . V_130 ;
if ( V_93 == V_108 ) {
struct V_131 * V_132 =
(struct V_131 * ) V_34 -> V_122 [ V_20 ] . V_113 ;
V_132 -> V_133 =
V_134 | V_135 ;
}
return 0 ;
}
static int F_23 (
struct V_1 * V_2 ,
enum V_54 V_108 ,
bool V_109 )
{
T_3 V_20 ;
struct V_33 * V_34 = (struct V_33 * ) V_2 -> V_35 ;
struct V_110 * V_111 = (struct V_110 * ) V_34 -> V_112 . V_113 ;
struct V_114 * V_115 = & V_111 -> V_116 [ V_34 -> V_117 ++ ] ;
V_115 -> type = V_136 ;
V_115 -> V_118 = F_20 ( V_2 , V_108 ) ;
V_115 -> V_119 = V_109 ? V_120 : V_34 -> V_117 ;
for ( V_20 = 0 ; V_20 < V_34 -> V_137 ; V_20 ++ )
if ( V_34 -> V_138 [ V_20 ] . V_123 == V_108 )
break;
if ( V_20 >= V_34 -> V_137 ) {
F_5 ( L_5 ) ;
return - V_4 ;
}
V_115 -> V_124 . V_125 = V_34 -> V_138 [ V_20 ] . V_126 ;
V_115 -> V_124 . V_127 = V_34 -> V_138 [ V_20 ] . V_128 ;
V_115 -> V_129 = V_34 -> V_138 [ V_20 ] . V_130 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = (struct V_33 * ) V_2 -> V_35 ;
V_34 -> V_139 = V_34 -> V_117 ;
F_22 ( V_2 ,
V_78 ,
V_140 , true ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_20 ;
struct V_33 * V_34 = (struct V_33 * ) V_2 -> V_35 ;
struct V_110 * V_111 = (struct V_110 * ) V_34 -> V_112 . V_113 ;
for ( V_20 = 0 ; V_20 < V_141 ; V_20 ++ )
V_111 -> V_142 [ V_20 ] = ( T_3 ) V_143 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = (struct V_33 * ) V_2 -> V_35 ;
struct V_110 * V_111 = (struct V_110 * ) V_34 -> V_112 . V_113 ;
V_111 -> V_142 [ V_144 ] = ( T_3 ) V_34 -> V_117 ;
F_22 ( V_2 ,
V_76 ,
V_140 , false ) ;
F_22 ( V_2 ,
V_80 ,
V_140 , true ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = (struct V_33 * ) V_2 -> V_35 ;
struct V_110 * V_111 = (struct V_110 * ) V_34 -> V_112 . V_113 ;
V_111 -> V_142 [ V_145 ] = ( T_3 ) V_34 -> V_117 ;
F_23 ( V_2 ,
V_62 , false ) ;
F_23 ( V_2 ,
V_64 , false ) ;
F_23 ( V_2 ,
V_66 , false ) ;
F_23 ( V_2 ,
V_68 , false ) ;
if ( V_2 -> V_59 == V_60 )
F_23 ( V_2 ,
V_68 , false ) ;
else
F_23 ( V_2 ,
V_70 , false ) ;
F_23 ( V_2 ,
V_74 , false ) ;
F_22 ( V_2 ,
V_76 ,
V_136 , false ) ;
F_22 ( V_2 ,
V_78 ,
V_136 , false ) ;
F_22 ( V_2 ,
V_80 ,
V_136 , true ) ;
return 0 ;
}
static int F_28 (
struct V_1 * V_2 )
{
struct V_33 * V_34 = (struct V_33 * ) V_2 -> V_35 ;
V_34 -> V_146 = V_34 -> V_117 ;
F_22 ( V_2 ,
V_86 ,
V_147 , true ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = (struct V_33 * ) V_2 -> V_35 ;
V_34 -> V_148 = V_34 -> V_117 ;
F_23 ( V_2 ,
V_56 , false ) ;
if ( V_2 -> V_59 != V_60 )
F_23 ( V_2 ,
V_58 , false ) ;
F_23 ( V_2 ,
V_62 , false ) ;
F_23 ( V_2 ,
V_64 , false ) ;
F_23 ( V_2 ,
V_66 , false ) ;
F_23 ( V_2 ,
V_68 , false ) ;
if ( V_2 -> V_59 != V_60 )
F_23 ( V_2 ,
V_70 , false ) ;
F_23 ( V_2 ,
V_74 , true ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = (struct V_33 * ) V_2 -> V_35 ;
V_34 -> V_149 = V_34 -> V_117 ;
F_22 ( V_2 ,
V_95 ,
V_147 , true ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = (struct V_33 * ) V_2 -> V_35 ;
V_34 -> V_117 = 0 ;
F_25 ( V_2 ) ;
F_24 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = (struct V_33 * ) V_2 -> V_35 ;
T_2 V_150 ;
T_2 V_20 ;
int V_30 ;
enum V_97 V_151 ;
struct V_31 V_32 = { 0 } ;
V_34 -> V_137 = 0 ;
for ( V_20 = 0 ; V_20 < F_33 ( V_152 ) ; V_20 ++ ) {
V_150 = F_20 ( V_2 ,
V_152 [ V_20 ] ) ;
V_151 = F_21 ( V_150 ) ;
V_30 = F_15 ( V_2 -> V_3 ,
V_151 , & V_32 ) ;
if ( V_30 == 0 ) {
V_34 -> V_138 [ V_20 ] . V_128 =
F_19 ( V_32 . V_47 ) ;
V_34 -> V_138 [ V_20 ] . V_126 =
F_17 ( V_32 . V_47 ) ;
V_34 -> V_138 [ V_20 ] . V_130 = V_32 . V_153 ;
V_34 -> V_138 [ V_20 ] . V_123 = V_152 [ V_20 ] ;
V_34 -> V_137 ++ ;
}
}
return 0 ;
}
static int F_34 (
struct V_1 * V_2 ,
enum V_54 V_154 ,
T_2 V_155 ,
struct V_156 * V_157 )
{
struct V_33 * V_34 = (struct V_33 * ) V_2 -> V_35 ;
long long V_47 =
( ( long long ) ( V_34 -> V_158 . V_128 ) << 32 )
| V_34 -> V_158 . V_126 ;
T_2 V_159 = F_35 ( V_155 ) ;
V_47 += V_34 -> V_160 ;
V_157 -> V_130 = V_155 ;
V_157 -> V_113 = ( char * ) V_34 -> V_158 . V_113 +
V_34 -> V_160 ;
V_157 -> V_126 = F_17 ( V_47 ) ;
V_157 -> V_128 = F_19 ( V_47 ) ;
V_157 -> V_123 = V_154 ;
V_34 -> V_160 += V_159 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , void * * V_161 )
{
struct V_33 * V_34 = (struct V_33 * ) V_2 -> V_35 ;
unsigned long V_20 ;
for ( V_20 = 0 ; V_20 < V_34 -> V_121 ; V_20 ++ ) {
if ( V_34 -> V_122 [ V_20 ] . V_123
== V_95 )
break;
}
* V_161 = (struct V_162 * ) V_34 -> V_122 [ V_20 ] . V_113 ;
F_10 ( V_2 ,
V_163 ,
V_34 -> V_122 [ V_20 ] . V_128 ) ;
F_10 ( V_2 ,
V_164 ,
V_34 -> V_122 [ V_20 ] . V_126 ) ;
F_10 ( V_2 , V_165 ,
V_34 -> V_149 ) ;
F_7 ( V_2 , V_166 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = (struct V_33 * ) V_2 -> V_35 ;
unsigned long V_20 ;
for ( V_20 = 0 ; V_20 < V_34 -> V_121 ; V_20 ++ ) {
if ( V_34 -> V_122 [ V_20 ] . V_123
== V_95 )
break;
}
F_10 ( V_2 ,
V_163 ,
V_34 -> V_122 [ V_20 ] . V_128 ) ;
F_10 ( V_2 ,
V_164 ,
V_34 -> V_122 [ V_20 ] . V_126 ) ;
F_10 ( V_2 , V_165 ,
V_34 -> V_149 ) ;
F_7 ( V_2 , V_167 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = (struct V_33 * ) ( V_2 -> V_35 ) ;
T_2 V_12 ;
if ( ! V_2 -> V_168 ) {
F_39 ( L_6 ) ;
return 0 ;
}
F_32 ( V_2 ) ;
F_31 ( V_2 ) ;
V_12 = V_22 +
F_12 ( struct V_23 , V_24 ) ;
F_9 ( V_2 , V_12 , 0 , V_12 + 4 ) ;
F_10 ( V_2 ,
V_169 ,
V_34 -> V_112 . V_128 ) ;
F_10 ( V_2 ,
V_170 ,
V_34 -> V_112 . V_126 ) ;
F_7 ( V_2 , V_171 ) ;
F_10 ( V_2 ,
V_165 ,
V_34 -> V_139 ) ;
F_10 ( V_2 , V_165 ,
V_34 -> V_146 ) ;
return F_10 ( V_2 ,
V_165 ,
V_34 -> V_148 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
T_2 V_172 = 0 ;
V_172 = V_173 |
V_174 |
V_175 |
V_176 |
V_177 |
V_178 |
V_179 |
V_180 ;
if ( V_2 -> V_59 == V_60 )
V_172 &= ~ ( V_175 | V_180 ) ;
V_30 = F_38 ( V_2 ) ;
if ( V_30 )
F_5 ( L_7 ) ;
F_11 ( V_2 , V_172 ) ;
V_30 = F_14 ( V_2 ) ;
if ( V_30 )
F_5 ( L_8 ) ;
return V_30 ;
}
static int F_41 ( struct V_1 * V_2 )
{
T_4 V_47 = 0 ;
int V_30 = 0 ;
struct V_33 * V_34 ;
V_34 = F_42 ( sizeof( struct V_33 ) , V_181 ) ;
if ( V_34 == NULL )
return - V_182 ;
V_2 -> V_35 = V_34 ;
V_34 -> V_112 . V_130 = 4096 ;
V_34 -> V_158 . V_130 =
F_43 ( V_183 , 32 ) +
F_43 ( V_184 , 32 ) +
F_43 ( V_185 , 32 ) +
F_43 ( sizeof( struct V_186 ) , 32 ) +
F_43 ( sizeof( struct V_162 ) , 32 ) ;
V_30 = F_44 ( V_2 -> V_3 ,
V_34 -> V_112 . V_130 ,
V_187 ,
V_188 ,
& V_47 ,
& V_34 -> V_112 . V_113 ,
& V_34 -> V_112 . V_189 ) ;
if ( V_30 != 0 )
return - 1 ;
V_34 -> V_112 . V_128 = F_19 ( V_47 ) ;
V_34 -> V_112 . V_126 = F_17 ( V_47 ) ;
V_30 = F_44 ( V_2 -> V_3 ,
V_34 -> V_158 . V_130 ,
V_187 ,
V_188 ,
& V_47 ,
& V_34 -> V_158 . V_113 ,
& V_34 -> V_158 . V_189 ) ;
if ( V_30 != 0 )
return - 1 ;
V_34 -> V_158 . V_128 = F_19 ( V_47 ) ;
V_34 -> V_158 . V_126 = F_17 ( V_47 ) ;
if ( 0 != F_34 ( V_2 ,
V_76 ,
V_183 ,
& V_34 -> V_122 [ V_34 -> V_121 ++ ] ) ) {
F_5 ( L_9 ) ;
return - 1 ;
}
if ( 0 != F_34 ( V_2 ,
V_78 ,
V_184 ,
& V_34 -> V_122 [ V_34 -> V_121 ++ ] ) ) {
F_5 ( L_9 ) ;
return - 1 ;
}
if ( 0 != F_34 ( V_2 ,
V_80 ,
V_185 ,
& V_34 -> V_122 [ V_34 -> V_121 ++ ] ) ) {
F_5 ( L_9 ) ;
return - 1 ;
}
if ( 0 != F_34 ( V_2 ,
V_86 ,
sizeof( struct V_186 ) ,
& V_34 -> V_122 [ V_34 -> V_121 ++ ] ) ) {
F_5 ( L_9 ) ;
return - 1 ;
}
if ( 0 != F_34 ( V_2 ,
V_95 ,
sizeof( struct V_162 ) ,
& V_34 -> V_122 [ V_34 -> V_121 ++ ] ) ) {
F_5 ( L_9 ) ;
return - 1 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_33 * V_34 ;
if ( V_2 == NULL || V_2 -> V_3 == NULL )
return - V_4 ;
V_34 = (struct V_33 * ) V_2 -> V_35 ;
if ( V_34 ) {
F_46 ( V_2 -> V_3 ,
V_34 -> V_112 . V_189 ) ;
F_46 ( V_2 -> V_3 ,
V_34 -> V_158 . V_189 ) ;
F_47 ( V_34 ) ;
}
return 0 ;
}
