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
F_5 ( V_10 L_1 ) ;
return V_7 ;
}
F_6 ( V_2 -> V_3 , V_11 , 0 ) ;
F_6 ( V_2 -> V_3 , V_12 , V_6 ) ;
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
T_2 V_13 , T_2 V_14 )
{
if ( V_2 == NULL || V_2 -> V_3 == NULL )
return - V_4 ;
if ( 0 != ( 3 & V_13 ) ) {
F_5 ( V_10 L_2 ) ;
return - V_4 ;
}
if ( V_14 <= ( V_13 + 3 ) ) {
F_5 ( V_10 L_3 ) ;
return - V_4 ;
}
F_6 ( V_2 -> V_3 , V_15 ,
V_16 + V_13 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_2 V_13 , T_2 V_17 , T_2 V_14 )
{
int V_7 ;
if ( V_2 == NULL || V_2 -> V_3 == NULL )
return - V_4 ;
V_7 = F_8 ( V_2 , V_13 , V_14 ) ;
if ( ! V_7 )
F_6 ( V_2 -> V_3 , V_18 , V_17 ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_6 , T_2 V_19 )
{
if ( V_2 == NULL || V_2 -> V_3 == NULL )
return - V_4 ;
F_6 ( V_2 -> V_3 , V_5 , V_19 ) ;
return F_7 ( V_2 , V_6 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = (struct V_20 * ) ( V_2 -> V_22 ) ;
T_2 V_13 ;
if ( ! V_2 -> V_23 ) {
F_5 ( V_24 L_4 ) ;
return 0 ;
}
V_13 = V_25 +
F_12 ( struct V_26 , V_27 ) ;
F_9 ( V_2 , V_13 , 0 , V_13 + 4 ) ;
F_10 ( V_2 ,
V_28 ,
V_21 -> V_29 . V_30 ) ;
F_10 ( V_2 ,
V_31 ,
V_21 -> V_29 . V_32 ) ;
F_7 ( V_2 , V_33 ) ;
F_10 ( V_2 ,
V_34 ,
V_21 -> V_35 ) ;
F_10 ( V_2 , V_34 ,
V_21 -> V_36 ) ;
return F_10 ( V_2 ,
V_34 ,
V_21 -> V_37 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
T_2 V_38 )
{
int V_39 ;
T_2 V_40 = V_16 +
V_25 +
F_12 ( struct V_26 , V_27 ) ;
if ( V_2 == NULL || V_2 -> V_3 == NULL )
return - V_4 ;
F_6 ( V_2 -> V_3 , V_41 , V_40 ) ;
for ( V_39 = 0 ; V_39 < V_2 -> V_42 ; V_39 ++ ) {
if ( V_38 ==
( F_2 ( V_2 -> V_3 , V_43 ) & V_38 ) )
break;
F_14 ( 1 ) ;
}
if ( V_39 >= V_2 -> V_42 ) {
F_5 ( V_10 L_5 ) ;
return - V_4 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_2 V_44 ;
T_2 V_45 ;
int V_46 = 0 ;
struct V_47 V_48 = { 0 } ;
struct V_20 * V_21 ;
if ( V_2 == NULL || V_2 -> V_3 == NULL )
return - V_4 ;
V_21 = (struct V_20 * ) V_2 -> V_22 ;
V_46 = F_16 ( V_2 -> V_3 ,
V_49 , & V_48 ) ;
if ( V_46 )
return - V_4 ;
V_45 = F_2 ( V_2 -> V_3 ,
V_50 ) ;
V_45 = F_17 ( V_45 , V_51 , V_52 , 1 ) ;
V_45 = F_17 ( V_45 , V_51 , V_53 , 1 ) ;
F_6 ( V_2 -> V_3 , V_50 , V_45 ) ;
V_45 = F_2 ( V_2 -> V_3 ,
V_54 ) ;
V_45 = F_17 ( V_45 , V_55 , V_56 , 0 ) ;
V_45 = F_17 ( V_45 , V_55 , V_57 , 0 ) ;
V_45 = F_17 ( V_45 , V_55 , V_58 , 0 ) ;
V_45 = F_17 ( V_45 , V_55 , V_59 , 1 ) ;
F_6 ( V_2 -> V_3 , V_54 , V_45 ) ;
V_44 = F_18 ( V_48 . V_60 ) &
F_19 ( V_61 , V_62 ) ;
F_6 ( V_2 -> V_3 , V_63 , V_44 ) ;
V_44 = F_20 ( V_48 . V_60 ) &
F_19 ( V_64 , V_65 ) ;
F_6 ( V_2 -> V_3 , V_66 , V_44 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_46 = 0 ;
T_2 V_67 = V_68 |
V_69 |
V_70 |
V_71 |
V_72 |
V_73 |
V_74 |
V_75 ;
if ( V_2 -> V_76 == V_77 )
V_67 &= ~ ( V_70 | V_75 ) ;
V_46 = F_11 ( V_2 ) ;
if ( V_46 )
F_5 ( V_10 L_6 ) ;
F_13 ( V_2 , V_67 ) ;
V_46 = F_15 ( V_2 ) ;
if ( V_46 )
F_5 ( V_10 L_7 ) ;
return V_46 ;
}
static T_3 F_22 ( struct V_1 * V_2 ,
enum V_78 V_79 )
{
T_3 V_46 = 0 ;
switch ( V_79 ) {
case V_80 :
V_46 = V_81 ;
break;
case V_82 :
if ( V_2 -> V_76 == V_77 )
V_46 = V_81 ;
else
V_46 = V_83 ;
break;
case V_84 :
V_46 = V_85 ;
break;
case V_86 :
V_46 = V_87 ;
break;
case V_88 :
V_46 = V_89 ;
break;
case V_90 :
V_46 = V_91 ;
break;
case V_92 :
if ( V_2 -> V_76 == V_77 )
V_46 = V_91 ;
else
V_46 = V_93 ;
break;
case V_94 :
V_46 = V_95 ;
break;
case V_96 :
V_46 = V_97 ;
break;
case V_98 :
V_46 = V_99 ;
break;
case V_100 :
V_46 = V_101 ;
break;
case V_102 :
V_46 = V_103 ;
break;
case V_104 :
V_46 = V_105 ;
break;
case V_106 :
V_46 = V_107 ;
break;
case V_108 :
V_46 = V_109 ;
break;
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_46 = V_116 ;
break;
case V_117 :
V_46 = V_118 ;
break;
}
return V_46 ;
}
static enum V_119 F_23 ( T_2 V_120 )
{
enum V_119 V_7 = V_121 ;
switch ( V_120 ) {
case V_81 :
V_7 = V_122 ;
break;
case V_83 :
V_7 = V_123 ;
break;
case V_85 :
V_7 = V_124 ;
break;
case V_87 :
V_7 = V_125 ;
break;
case V_89 :
V_7 = V_126 ;
break;
case V_91 :
V_7 = V_127 ;
break;
case V_93 :
V_7 = V_128 ;
break;
case V_97 :
V_7 = V_129 ;
break;
default:
break;
}
return V_7 ;
}
static int F_24 (
struct V_1 * V_2 ,
enum V_78 V_130 ,
T_3 type , bool V_131 )
{
T_3 V_39 ;
struct V_20 * V_21 = (struct V_20 * ) V_2 -> V_22 ;
struct V_132 * V_133 = (struct V_132 * ) V_21 -> V_29 . V_134 ;
struct V_135 * V_136 = & V_133 -> V_137 [ V_21 -> V_138 ++ ] ;
V_136 -> type = type ;
V_136 -> V_139 = F_22 ( V_2 , V_130 ) ;
V_136 -> V_140 = V_131 ? V_141 : V_21 -> V_138 ;
for ( V_39 = 0 ; V_39 < V_21 -> V_142 ; V_39 ++ )
if ( V_21 -> V_143 [ V_39 ] . V_144 == V_130 )
break;
if ( V_39 >= V_21 -> V_142 ) {
F_5 ( V_10 L_8 ) ;
return - V_4 ;
}
V_136 -> V_145 . V_146 = V_21 -> V_143 [ V_39 ] . V_32 ;
V_136 -> V_145 . V_147 = V_21 -> V_143 [ V_39 ] . V_30 ;
V_136 -> V_148 = V_21 -> V_143 [ V_39 ] . V_149 ;
if ( V_115 == V_130 ) {
struct V_150 * V_151 =
(struct V_150 * ) V_21 -> V_143 [ V_39 ] . V_134 ;
V_151 -> V_152 =
V_153 | V_154 ;
}
return 0 ;
}
static int F_25 (
struct V_1 * V_2 ,
enum V_78 V_130 ,
bool V_131 )
{
T_3 V_39 ;
struct V_20 * V_21 = (struct V_20 * ) V_2 -> V_22 ;
struct V_132 * V_133 = (struct V_132 * ) V_21 -> V_29 . V_134 ;
struct V_135 * V_136 = & V_133 -> V_137 [ V_21 -> V_138 ++ ] ;
V_136 -> type = V_155 ;
V_136 -> V_139 = F_22 ( V_2 , V_130 ) ;
V_136 -> V_140 = V_131 ? V_141 : V_21 -> V_138 ;
for ( V_39 = 0 ; V_39 < V_21 -> V_156 ; V_39 ++ )
if ( V_21 -> V_157 [ V_39 ] . V_144 == V_130 )
break;
if ( V_39 >= V_21 -> V_156 ) {
F_5 ( V_10 L_8 ) ;
return - V_4 ;
}
V_136 -> V_145 . V_146 = V_21 -> V_157 [ V_39 ] . V_32 ;
V_136 -> V_145 . V_147 = V_21 -> V_157 [ V_39 ] . V_30 ;
V_136 -> V_148 = V_21 -> V_157 [ V_39 ] . V_149 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = (struct V_20 * ) V_2 -> V_22 ;
V_21 -> V_35 = V_21 -> V_138 ;
F_24 ( V_2 ,
V_100 ,
V_158 , true ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_39 ;
struct V_20 * V_21 = (struct V_20 * ) V_2 -> V_22 ;
struct V_132 * V_133 = (struct V_132 * ) V_21 -> V_29 . V_134 ;
for ( V_39 = 0 ; V_39 < V_159 ; V_39 ++ )
V_133 -> V_160 [ V_39 ] = ( T_3 ) V_161 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = (struct V_20 * ) V_2 -> V_22 ;
struct V_132 * V_133 = (struct V_132 * ) V_21 -> V_29 . V_134 ;
V_133 -> V_160 [ V_162 ] = ( T_3 ) V_21 -> V_138 ;
F_24 ( V_2 ,
V_98 ,
V_158 , false ) ;
F_24 ( V_2 ,
V_102 ,
V_158 , true ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = (struct V_20 * ) V_2 -> V_22 ;
struct V_132 * V_133 = (struct V_132 * ) V_21 -> V_29 . V_134 ;
V_133 -> V_160 [ V_163 ] = ( T_3 ) V_21 -> V_138 ;
F_25 ( V_2 ,
V_84 , false ) ;
F_25 ( V_2 ,
V_86 , false ) ;
F_25 ( V_2 ,
V_88 , false ) ;
F_25 ( V_2 ,
V_90 , false ) ;
if ( V_2 -> V_76 == V_77 )
F_25 ( V_2 ,
V_90 , false ) ;
else
F_25 ( V_2 ,
V_92 , false ) ;
F_25 ( V_2 ,
V_96 , false ) ;
F_24 ( V_2 ,
V_98 ,
V_155 , false ) ;
F_24 ( V_2 ,
V_100 ,
V_155 , false ) ;
F_24 ( V_2 ,
V_102 ,
V_155 , true ) ;
return 0 ;
}
static int F_30 (
struct V_1 * V_2 )
{
struct V_20 * V_21 = (struct V_20 * ) V_2 -> V_22 ;
V_21 -> V_36 = V_21 -> V_138 ;
F_24 ( V_2 ,
V_108 ,
V_164 , true ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = (struct V_20 * ) V_2 -> V_22 ;
V_21 -> V_37 = V_21 -> V_138 ;
F_25 ( V_2 ,
V_80 , false ) ;
if ( V_2 -> V_76 != V_77 )
F_25 ( V_2 ,
V_82 , false ) ;
F_25 ( V_2 ,
V_84 , false ) ;
F_25 ( V_2 ,
V_86 , false ) ;
F_25 ( V_2 ,
V_88 , false ) ;
F_25 ( V_2 ,
V_90 , false ) ;
if ( V_2 -> V_76 != V_77 )
F_25 ( V_2 ,
V_92 , false ) ;
F_25 ( V_2 ,
V_96 , true ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = (struct V_20 * ) V_2 -> V_22 ;
V_21 -> V_165 = V_21 -> V_138 ;
F_24 ( V_2 ,
V_117 ,
V_164 , true ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = (struct V_20 * ) V_2 -> V_22 ;
V_21 -> V_138 = 0 ;
F_27 ( V_2 ) ;
F_26 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = (struct V_20 * ) V_2 -> V_22 ;
T_2 V_166 ;
T_2 V_39 ;
int V_46 ;
enum V_119 V_167 ;
struct V_47 V_48 = { 0 } ;
V_21 -> V_156 = 0 ;
for ( V_39 = 0 ; V_39 < F_35 ( V_168 ) ; V_39 ++ ) {
V_166 = F_22 ( V_2 ,
V_168 [ V_39 ] ) ;
V_167 = F_23 ( V_166 ) ;
V_46 = F_16 ( V_2 -> V_3 ,
V_167 , & V_48 ) ;
if ( V_46 == 0 ) {
V_21 -> V_157 [ V_39 ] . V_30 =
F_20 ( V_48 . V_60 ) ;
V_21 -> V_157 [ V_39 ] . V_32 =
F_18 ( V_48 . V_60 ) ;
V_21 -> V_157 [ V_39 ] . V_149 = V_48 . V_169 ;
V_21 -> V_157 [ V_39 ] . V_144 = V_168 [ V_39 ] ;
V_21 -> V_156 ++ ;
}
}
return 0 ;
}
static int F_36 (
struct V_1 * V_2 ,
enum V_78 V_170 ,
T_2 V_171 ,
struct V_172 * V_173 )
{
struct V_20 * V_21 = (struct V_20 * ) V_2 -> V_22 ;
long long V_60 =
( ( long long ) ( V_21 -> V_174 . V_30 ) << 32 )
| V_21 -> V_174 . V_32 ;
T_2 V_175 = F_37 ( V_171 ) ;
V_60 += V_21 -> V_176 ;
V_173 -> V_149 = V_171 ;
V_173 -> V_134 = ( char * ) V_21 -> V_174 . V_134 +
V_21 -> V_176 ;
V_173 -> V_32 = F_18 ( V_60 ) ;
V_173 -> V_30 = F_20 ( V_60 ) ;
V_173 -> V_144 = V_170 ;
V_21 -> V_176 += V_175 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , void * * V_177 )
{
struct V_20 * V_21 = (struct V_20 * ) V_2 -> V_22 ;
unsigned long V_39 ;
for ( V_39 = 0 ; V_39 < V_21 -> V_142 ; V_39 ++ ) {
if ( V_21 -> V_143 [ V_39 ] . V_144
== V_117 )
break;
}
* V_177 = (struct V_178 * ) V_21 -> V_143 [ V_39 ] . V_134 ;
F_10 ( V_2 ,
V_179 ,
V_21 -> V_143 [ V_39 ] . V_30 ) ;
F_10 ( V_2 ,
V_180 ,
V_21 -> V_143 [ V_39 ] . V_32 ) ;
F_10 ( V_2 , V_34 ,
V_21 -> V_165 ) ;
F_7 ( V_2 , V_181 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = (struct V_20 * ) V_2 -> V_22 ;
unsigned long V_39 ;
for ( V_39 = 0 ; V_39 < V_21 -> V_142 ; V_39 ++ ) {
if ( V_21 -> V_143 [ V_39 ] . V_144
== V_117 )
break;
}
F_10 ( V_2 ,
V_179 ,
V_21 -> V_143 [ V_39 ] . V_30 ) ;
F_10 ( V_2 ,
V_180 ,
V_21 -> V_143 [ V_39 ] . V_32 ) ;
F_10 ( V_2 , V_34 ,
V_21 -> V_165 ) ;
F_7 ( V_2 , V_182 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = (struct V_20 * ) V_2 -> V_22 ;
T_4 V_60 = 0 ;
int V_46 = 0 ;
V_21 -> V_29 . V_149 = 4096 ;
V_21 -> V_174 . V_149 =
F_41 ( V_183 , 32 ) +
F_41 ( V_184 , 32 ) +
F_41 ( V_185 , 32 ) +
F_41 ( sizeof( struct V_186 ) , 32 ) +
F_41 ( sizeof( struct V_178 ) , 32 ) ;
V_46 = F_42 ( V_2 -> V_3 ,
V_21 -> V_29 . V_149 ,
V_187 ,
V_188 ,
& V_60 ,
& V_21 -> V_29 . V_134 ,
& V_21 -> V_29 . V_189 ) ;
if ( V_46 != 0 )
return - 1 ;
V_21 -> V_29 . V_30 = F_20 ( V_60 ) ;
V_21 -> V_29 . V_32 = F_18 ( V_60 ) ;
V_46 = F_42 ( V_2 -> V_3 ,
V_21 -> V_174 . V_149 ,
V_187 ,
V_188 ,
& V_60 ,
& V_21 -> V_174 . V_134 ,
& V_21 -> V_174 . V_189 ) ;
if ( V_46 != 0 )
return - 1 ;
V_21 -> V_174 . V_30 = F_20 ( V_60 ) ;
V_21 -> V_174 . V_32 = F_18 ( V_60 ) ;
F_34 ( V_2 ) ;
if ( 0 != F_36 ( V_2 ,
V_98 ,
V_183 ,
& V_21 -> V_143 [ V_21 -> V_142 ++ ] ) ) {
F_5 ( V_10 L_9 ) ;
return - 1 ;
}
if ( 0 != F_36 ( V_2 ,
V_100 ,
V_184 ,
& V_21 -> V_143 [ V_21 -> V_142 ++ ] ) ) {
F_5 ( V_10 L_9 ) ;
return - 1 ;
}
if ( 0 != F_36 ( V_2 ,
V_102 ,
V_185 ,
& V_21 -> V_143 [ V_21 -> V_142 ++ ] ) ) {
F_5 ( V_10 L_9 ) ;
return - 1 ;
}
if ( 0 != F_36 ( V_2 ,
V_108 ,
sizeof( struct V_186 ) ,
& V_21 -> V_143 [ V_21 -> V_142 ++ ] ) ) {
F_5 ( V_10 L_9 ) ;
return - 1 ;
}
if ( 0 != F_36 ( V_2 ,
V_117 ,
sizeof( struct V_178 ) ,
& V_21 -> V_143 [ V_21 -> V_142 ++ ] ) ) {
F_5 ( V_10 L_9 ) ;
return - 1 ;
}
F_33 ( V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
if ( V_2 == NULL || V_2 -> V_3 == NULL )
return - V_4 ;
V_21 = (struct V_20 * ) V_2 -> V_22 ;
if ( V_21 ) {
F_44 ( V_2 -> V_3 ,
V_21 -> V_29 . V_189 ) ;
F_44 ( V_2 -> V_3 ,
V_21 -> V_174 . V_189 ) ;
F_45 ( V_21 ) ;
F_45 ( V_2 ) ;
}
return 0 ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
V_21 = F_47 ( sizeof( struct V_20 ) , V_190 ) ;
if ( V_21 == NULL )
return - V_191 ;
V_2 -> V_22 = V_21 ;
V_2 -> V_192 = & V_193 ;
return 0 ;
}
