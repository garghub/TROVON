T_1 F_1 ( T_1 V_1 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_1 == V_3 [ V_2 ] . V_4 )
return V_3 [ V_2 ] . V_1 ;
return V_1 ;
}
bool F_3 ( T_1 V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_5 ) - 1 ; V_2 ++ )
if ( V_1 == V_5 [ V_2 ] . V_1 )
return V_5 [ V_2 ] . V_6 !=
V_5 [ V_2 ] . V_7 ;
return false ;
}
const struct V_5 * F_4 ( T_1 V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_5 ) - 1 ; V_2 ++ )
if ( V_1 == V_5 [ V_2 ] . V_1 )
return V_5 + V_2 ;
return NULL ;
}
const struct V_5 * F_5 (
enum V_8 V_9 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_5 ) - 1 ; V_2 ++ )
if ( V_5 [ V_2 ] . V_9 == V_9 )
return V_5 + V_2 ;
return NULL ;
}
bool F_6 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
struct V_13 * V_14 , * V_15 ;
V_14 = F_7 ( & V_11 -> V_16 , NULL ,
V_17 ,
V_18 ) ;
V_15 = F_7 ( & V_11 -> V_16 , NULL ,
V_17 , V_12 ) ;
return F_8 ( V_14 -> V_1 )
&& ! F_8 ( V_15 -> V_1 ) ;
}
T_2 F_9 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
T_2 V_23 = 0 ;
F_10 (link, &vdev->entity.links, list) {
if ( V_22 -> V_24 ) {
V_23 = V_22 -> V_24 -> V_25 ;
break;
}
}
return V_23 ;
}
static long F_11 ( struct V_26 * V_27 ,
unsigned int V_28 , void * V_29 )
{
return 0 ;
}
static int F_12 ( struct V_26 * V_27 , int V_30 )
{
return 0 ;
}
static int F_13 ( struct V_26 * V_27 ,
struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_10 * V_35 = F_14 ( V_27 ) ;
struct V_36 * V_37 = V_35 -> V_37 ;
if ( V_34 -> type != V_38 &&
V_34 -> type != V_39 &&
V_34 -> type != V_40 &&
V_34 -> type != V_41 &&
V_34 -> type != V_42 &&
V_34 -> type != V_43 &&
V_34 -> type != V_44 &&
V_34 -> type != V_45 )
return - V_46 ;
if ( V_34 -> type == V_38 &&
! F_15 ( V_37 ) )
return - V_46 ;
return F_16 ( V_32 , V_34 , 16 , NULL ) ;
}
static int F_17 ( struct V_26 * V_27 ,
struct V_31 * V_32 ,
struct V_33 * V_34 )
{
return F_18 ( V_32 , V_34 ) ;
}
static int F_19 ( struct V_26 * V_27 ,
struct V_47 * V_48 ,
struct V_49 * V_1 )
{
if ( V_1 -> V_25 >= F_2 ( V_5 ) - 1 )
return - V_46 ;
V_1 -> V_1 = V_5 [ V_1 -> V_25 ] . V_1 ;
return 0 ;
}
static int F_20 ( struct V_26 * V_27 , T_3 V_50 ,
T_3 V_51 )
{
switch ( V_50 ) {
case V_18 :
switch ( V_51 ) {
case V_52 :
return 0 ;
}
break;
default:
switch ( V_51 ) {
case V_53 :
return 0 ;
}
break;
}
return - V_46 ;
}
struct V_54 * F_21 ( struct V_26 * V_27 ,
struct V_47 * V_48 ,
T_3 V_55 , T_3 V_50 ,
T_3 V_51 )
{
struct V_10 * V_35 = F_14 ( V_27 ) ;
if ( V_55 == V_56 ) {
switch ( V_51 ) {
case V_52 :
return F_22 ( V_27 , V_48 , V_50 ) ;
case V_53 :
return F_23 ( V_27 , V_48 , V_50 ) ;
}
}
switch ( V_51 ) {
case V_52 :
return & V_35 -> V_57 [ V_50 ] . V_58 ;
case V_53 :
return & V_35 -> V_57 [ V_50 ] . V_59 ;
}
return NULL ;
}
struct V_13
* F_7 ( struct V_26 * V_27 ,
struct V_47 * V_48 , T_3 V_55 ,
T_3 V_50 )
{
struct V_10 * V_35 = F_14 ( V_27 ) ;
if ( V_55 == V_56 )
return F_24 ( V_27 , V_48 , V_50 ) ;
return & V_35 -> V_57 [ V_50 ] . V_57 ;
}
static void F_25 ( struct V_26 * V_27 ,
struct V_47 * V_48 , T_3 V_55 ,
struct V_13 * * V_60 ,
struct V_54 * V_58 [ V_61 ] ,
struct V_54 * V_62 [ V_61 ] )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_61 ; V_2 ++ ) {
V_60 [ V_2 ] = F_7 ( V_27 , V_48 , V_55 , V_2 ) ;
V_58 [ V_2 ] = F_21 ( V_27 , V_48 , V_55 , V_2 ,
V_52 ) ;
V_62 [ V_2 ] = F_21 ( V_27 , V_48 , V_55 , V_2 ,
V_53 ) ;
}
}
static void F_26 ( struct V_26 * V_27 ,
struct V_47 * V_48 ,
T_3 V_55 , T_3 V_50 , T_3 V_51 ,
T_3 V_63 )
{
struct V_13 * V_60 [ V_61 ] ;
struct V_54 * V_58 [ V_61 ] ,
* V_62 [ V_61 ] ;
if ( V_63 & V_64 )
return;
F_25 ( V_27 , V_48 , V_55 , V_60 , V_58 , V_62 ) ;
switch ( V_50 ) {
case V_18 : {
struct V_54 V_65 = { 0 } ;
V_65 . V_66 = V_60 [ V_50 ] -> V_66 ;
V_65 . V_67 = V_60 [ V_50 ] -> V_67 ;
F_27 ( V_27 , V_48 , V_55 , V_50 ,
V_51 , V_63 , & V_65 ) ;
break;
}
}
}
static int F_28 ( struct V_26 * V_27 ,
struct V_47 * V_48 ,
struct V_68 * V_69 )
{
struct V_54 * V_70 ;
int V_71 = F_20 ( V_27 , V_69 -> V_50 , V_69 -> V_51 ) ;
if ( V_71 )
return V_71 ;
V_70 = F_21 ( V_27 , V_48 , V_69 -> V_55 , V_69 -> V_50 ,
V_69 -> V_51 ) ;
if ( ! V_70 )
return - V_46 ;
V_69 -> V_65 = * V_70 ;
return 0 ;
}
int F_27 ( struct V_26 * V_27 ,
struct V_47 * V_48 ,
T_3 V_55 , T_3 V_50 , T_3 V_51 ,
T_3 V_63 , struct V_54 * V_65 )
{
struct V_10 * V_35 = F_14 ( V_27 ) ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_13 * V_60 [ V_61 ] ;
T_2 V_72 = F_9 ( V_27 -> V_73 ) ;
struct V_54 * V_58 [ V_61 ] ,
* V_62 [ V_61 ] ;
enum V_74 V_75 ;
unsigned int V_2 ;
unsigned int V_76 = V_77 ;
unsigned int V_78 = V_79 ;
V_75 = F_29 ( V_35 , V_72 ) ;
F_25 ( V_27 , V_48 , V_55 , V_60 , V_58 , V_62 ) ;
F_30 ( V_37 -> V_80 ,
L_1 ,
V_81 [ V_50 ] , V_51 == V_52
? L_2 : L_3 ,
V_65 -> V_82 , V_65 -> V_83 , V_65 -> V_66 , V_65 -> V_67 ,
V_55 == V_56 ? L_4
: L_5 , V_63 ) ;
V_65 -> V_66 = F_31 ( V_65 -> V_66 , V_84 ) ;
V_65 -> V_67 = F_31 ( V_65 -> V_67 , V_85 ) ;
switch ( V_50 ) {
case V_18 : {
unsigned int V_86 , V_87 ;
V_58 [ V_50 ] -> V_66 = V_60 [ V_50 ] -> V_66 ;
V_58 [ V_50 ] -> V_67 = V_60 [ V_50 ] -> V_67 ;
if ( ! strncmp ( V_37 -> V_88 [ V_35 -> V_89 ] . V_90 -> V_91 ,
L_6 , 6 ) && V_58 [ V_50 ] -> V_67 == 1092 ) {
V_76 = 12 ;
V_78 = 12 ;
}
if ( V_37 -> V_88 [ V_35 -> V_89 ] . type == V_92 ) {
V_76 = 0 ;
V_78 = 0 ;
}
if ( F_6 ( V_35 ,
V_35 -> V_93 )
&& V_58 [ V_50 ] -> V_66 && V_58 [ V_50 ] -> V_67 )
V_58 [ V_50 ] -> V_66 -= V_76 , V_58 [ V_50 ] -> V_67 -= V_78 ;
if ( V_37 -> V_88 [ V_35 -> V_89 ] . type == V_92 )
V_35 -> V_94 . V_95 = 0 ;
if ( V_35 -> V_94 . V_95 &&
V_35 -> V_96 -> V_97 == V_98 &&
! V_35 -> V_99 -> V_97 ) {
V_58 [ V_50 ] -> V_66 = F_32 ( V_58 [ V_50 ] -> V_66 * 5 / 6 ,
V_84 ) ;
V_58 [ V_50 ] -> V_67 = F_32 ( V_58 [ V_50 ] -> V_67 * 5 / 6 ,
V_85 ) ;
}
V_58 [ V_50 ] -> V_66 = F_33 ( V_58 [ V_50 ] -> V_66 , V_65 -> V_66 ) ;
V_58 [ V_50 ] -> V_67 = F_33 ( V_58 [ V_50 ] -> V_67 , V_65 -> V_67 ) ;
if ( ! ( V_63 & V_64 ) ) {
for ( V_2 = V_100 ;
V_2 < V_61 ; V_2 ++ ) {
struct V_54 V_101 = * V_58 [ V_50 ] ;
F_27 (
V_27 , V_48 , V_55 , V_2 , V_53 ,
V_63 , & V_101 ) ;
}
}
if ( V_55 == V_56 )
break;
if ( V_35 -> V_94 . V_95 &&
V_35 -> V_96 -> V_97 == V_98 &&
! V_35 -> V_99 -> V_97 ) {
V_86 = F_31 ( V_58 [ V_50 ] -> V_66 / 5 ,
V_84 ) ;
V_87 = F_31 ( V_58 [ V_50 ] -> V_67 / 5 ,
V_85 ) ;
} else if ( ! V_35 -> V_94 . V_95 &&
V_35 -> V_96 -> V_97 == V_98 ) {
V_86 = V_87 = 12 ;
} else
V_86 = V_87 = 0 ;
F_34 ( V_35 , V_86 , V_87 ) ;
F_35 ( V_35 , V_75 ,
V_58 [ V_50 ] -> V_66 , V_58 [ V_50 ] -> V_67 ) ;
break;
}
case V_100 :
case V_102 : {
if ( V_35 -> V_103 -> V_97 == V_104 ) {
V_65 -> V_66 = V_58 [ V_18 ] -> V_66 ;
V_65 -> V_67 = V_58 [ V_18 ] -> V_67 ;
}
if ( V_58 [ V_18 ] -> V_66 == V_65 -> V_66
&& V_58 [ V_18 ] -> V_67 == V_65 -> V_67 )
V_35 -> V_94 . V_105 = false ;
else
V_35 -> V_94 . V_105 = true ;
V_62 [ V_50 ] -> V_66 = V_65 -> V_66 ;
V_62 [ V_50 ] -> V_67 = V_65 -> V_67 ;
if ( V_65 -> V_66 == 0 || V_65 -> V_67 == 0 ||
V_58 [ V_18 ] -> V_66 == 0 ||
V_58 [ V_18 ] -> V_67 == 0 )
break;
if ( V_65 -> V_66 * V_58 [ V_18 ] -> V_67 <
V_58 [ V_18 ] -> V_66 * V_65 -> V_67 )
F_35 ( V_35 ,
V_75 ,
F_31 ( V_58 [ V_18 ] ->
V_67 * V_65 -> V_66 / V_65 -> V_67 ,
V_84 ) ,
V_58 [ V_18 ] -> V_67 ) ;
else
F_35 ( V_35 ,
V_75 ,
V_58 [ V_18 ] -> V_66 ,
F_31 ( V_58 [ V_18 ] ->
V_66 * V_65 -> V_67 / V_65 -> V_66 ,
V_84 ) ) ;
break;
}
case V_106 :
case V_107 :
V_62 [ V_50 ] -> V_66 = V_65 -> V_66 ;
V_62 [ V_50 ] -> V_67 = V_65 -> V_67 ;
break;
default:
return - V_46 ;
}
if ( V_50 != V_18 ) {
V_60 [ V_50 ] -> V_66 = V_62 [ V_50 ] -> V_66 ;
V_60 [ V_50 ] -> V_67 = V_62 [ V_50 ] -> V_67 ;
}
if ( ! F_21 ( V_27 , V_48 , V_55 , V_50 , V_51 ) )
return - V_46 ;
* V_65 = * F_21 ( V_27 , V_48 , V_55 , V_50 , V_51 ) ;
F_30 ( V_37 -> V_80 , L_7 ,
V_65 -> V_82 , V_65 -> V_83 , V_65 -> V_66 , V_65 -> V_67 ) ;
return 0 ;
}
static int F_36 ( struct V_26 * V_27 ,
struct V_47 * V_48 ,
struct V_68 * V_69 )
{
int V_71 = F_20 ( V_27 , V_69 -> V_50 , V_69 -> V_51 ) ;
if ( V_71 )
return V_71 ;
return F_27 ( V_27 , V_48 , V_69 -> V_55 , V_69 -> V_50 ,
V_69 -> V_51 , V_69 -> V_63 , & V_69 -> V_65 ) ;
}
static int F_37 ( struct V_10 * V_11 )
{
struct V_108 V_109 = { 0 } ;
struct V_36 * V_37 = V_11 -> V_37 ;
int V_110 , V_111 ;
int V_23 ;
if ( V_37 -> V_88 [ V_11 -> V_89 ] . type == V_112 ||
V_37 -> V_88 [ V_11 -> V_89 ] . type == V_113 )
return 0 ;
V_109 . V_114 = V_115 ;
V_23 =
F_38 ( V_37 -> V_88 [ V_11 -> V_89 ] . V_90 -> V_116 ,
& V_109 ) ;
V_110 = V_109 . V_117 ;
V_109 . V_114 = V_118 ;
V_23 |=
F_38 ( V_37 -> V_88 [ V_11 -> V_89 ] . V_90 -> V_116 ,
& V_109 ) ;
V_111 = V_109 . V_117 ;
if ( V_23 || V_110 != V_111 )
V_110 = 0 ;
return V_110 ;
}
void F_39 ( struct V_26 * V_27 ,
struct V_47 * V_48 , T_3 V_55 ,
T_3 V_50 , struct V_13 * V_60 )
{
struct V_10 * V_35 = F_14 ( V_27 ) ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_13 * V_119 =
F_7 ( V_27 , V_48 , V_55 , V_50 ) ;
T_2 V_72 = F_9 ( V_27 -> V_73 ) ;
enum V_74 V_75 ;
F_30 ( V_37 -> V_80 , L_8 ,
V_81 [ V_50 ] , V_60 -> V_66 , V_60 -> V_67 , V_60 -> V_1 ,
V_55 == V_56 ? L_4
: L_5 ) ;
V_75 = F_29 ( V_35 , V_72 ) ;
switch ( V_50 ) {
case V_18 : {
const struct V_5 * V_120 =
F_4 ( V_60 -> V_1 ) ;
if ( ! V_120 ) {
V_120 = V_5 ;
V_60 -> V_1 = V_120 -> V_1 ;
F_30 ( V_37 -> V_80 , L_9 ,
V_60 -> V_1 ) ;
}
* V_119 = * V_60 ;
F_26 ( V_27 , V_48 , V_55 , V_50 ,
V_52 , 0 ) ;
if ( V_55 == V_17 ) {
F_40 ( V_35 ,
V_75 , V_60 ) ;
F_41 ( V_35 ,
V_75 ,
F_37 ( V_35 ) ) ;
F_42 ( V_35 , V_75 ,
V_120 -> V_121 ) ;
F_43 ( V_35 , V_75 ,
V_120 -> V_122 ) ;
F_44 ( V_35 , V_75 ,
V_60 ) ;
}
break;
}
case V_100 :
case V_107 :
case V_106 :
case V_102 :
V_119 -> V_1 = V_60 -> V_1 ;
break;
}
}
static int F_45 ( struct V_26 * V_27 ,
struct V_47 * V_48 ,
struct V_123 * V_57 )
{
V_57 -> V_124 = * F_7 ( V_27 , V_48 , V_57 -> V_55 , V_57 -> V_50 ) ;
return 0 ;
}
static int F_46 ( struct V_26 * V_27 ,
struct V_47 * V_48 ,
struct V_123 * V_57 )
{
F_39 ( V_27 , V_48 , V_57 -> V_55 , V_57 -> V_50 , & V_57 -> V_124 ) ;
return 0 ;
}
static void F_47 ( struct V_10 * V_11 )
{
unsigned int V_2 ;
F_48 ( & V_11 -> V_125 ) ;
F_48 ( & V_11 -> V_126 ) ;
F_48 ( & V_11 -> V_127 ) ;
F_48 ( & V_11 -> V_128 ) ;
F_48 ( & V_11 -> V_129 ) ;
F_49 ( & V_11 -> V_130 ) ;
for ( V_2 = 0 ; V_2 < V_131 ; V_2 ++ ) {
F_48 ( & V_11 -> V_132 [ V_2 ] ) ;
F_48 ( & V_11 -> V_133 [ V_2 ] ) ;
F_48 ( & V_11 -> V_134 [ V_2 ] ) ;
}
}
static int F_50 ( struct V_135 * V_136 ,
const struct V_137 * V_138 ,
const struct V_137 * V_139 , T_1 V_63 )
{
struct V_26 * V_27 = F_51 ( V_136 ) ;
struct V_10 * V_35 = F_14 ( V_27 ) ;
struct V_36 * V_37 = V_35 -> V_37 ;
unsigned int V_2 ;
switch ( V_138 -> V_25 | F_52 ( V_139 -> V_136 ) ) {
case V_18 | V_140 :
if ( ! ( V_63 & V_141 ) ) {
V_35 -> V_142 = V_143 ;
break;
}
if ( V_35 -> V_142 != V_143 )
return - V_144 ;
for ( V_2 = 0 ; V_2 < V_145 ; V_2 ++ ) {
if ( V_139 -> V_136 != & V_37 -> V_146 [ V_2 ] . V_16 . V_136 )
continue;
V_35 -> V_142 = V_147 + V_2 ;
return 0 ;
}
return - V_46 ;
case V_18 | V_148 :
if ( V_63 & V_141 ) {
if ( V_35 -> V_142 >= V_147 &&
V_35 -> V_142 < ( V_147
+ V_145 ) )
return - V_144 ;
V_35 -> V_142 = V_149 ;
} else {
if ( V_35 -> V_142 == V_149 )
V_35 -> V_142 = V_143 ;
}
break;
case V_107 | V_148 :
break;
case V_106 | V_148 :
break;
case V_100 | V_148 :
break;
case V_102 | V_148 :
break;
default:
return - V_46 ;
}
return 0 ;
}
static int F_53 ( struct V_10 * V_11 )
{
struct V_36 * V_37 = V_11 -> V_37 ;
struct V_150 * V_109 = V_11 -> V_96 ;
struct V_150 * V_151 ;
struct V_152 V_153 = { 0 } ;
int V_154 [] = { V_155 ,
V_156 ,
V_157 ,
V_158 ,
V_159 } ;
T_4 V_160 ;
if ( V_109 -> V_97 != V_98 &&
V_11 -> V_99 -> V_97 )
V_160 = V_161 ;
else
V_160 = V_109 -> V_97 ;
V_151 = F_54 (
V_37 -> V_88 [ V_11 -> V_89 ] . V_90 -> V_116 ,
V_162 ) ;
if ( V_151 )
return F_55 ( V_151 , V_160 ) ;
V_153 . V_163 . V_164 . V_165 = V_154 [ V_160 ] ;
return F_56 (
V_37 -> V_88 [ V_11 -> V_89 ] . V_90 , V_166 , V_167 , & V_153 ) ;
}
int F_57 ( struct V_10 * V_11 )
{
int V_71 ;
F_58 ( V_11 -> V_116 . V_168 ) ;
V_71 = F_53 ( V_11 ) ;
F_59 ( V_11 -> V_116 . V_168 ) ;
return V_71 ;
}
static int F_60 ( struct V_150 * V_109 )
{
struct V_10 * V_11 = F_61 (
V_109 -> V_169 , struct V_10 , V_116 ) ;
switch ( V_109 -> V_114 ) {
case V_162 :
return F_53 ( V_11 ) ;
case V_170 :
if ( V_11 -> V_171 != V_172 ) {
F_62 ( V_11 -> V_37 -> V_80 , L_10 ) ;
return - V_46 ;
}
break;
}
return 0 ;
}
static void F_63 ( struct V_10 * V_11 ,
struct V_173 * V_174 , enum V_175 V_176 )
{
V_174 -> type = V_176 ;
V_174 -> V_11 = V_11 ;
V_174 -> V_37 = V_11 -> V_37 ;
F_49 ( & V_174 -> V_177 ) ;
F_48 ( & V_174 -> V_178 ) ;
F_48 ( & V_174 -> V_179 ) ;
F_48 ( & V_174 -> V_180 ) ;
F_48 ( & V_174 -> V_181 ) ;
memset ( V_174 -> V_182 ,
0 , V_183 * sizeof( unsigned int ) ) ;
memset ( V_174 -> V_184 ,
0 , V_183 *
sizeof( struct V_185 * ) ) ;
}
static void F_64 ( struct V_10 * V_11 ,
struct V_186 * V_174 )
{
V_174 -> V_11 = V_11 ;
V_174 -> V_37 = V_11 -> V_37 ;
F_48 ( & V_11 -> V_187 . V_188 ) ;
F_48 ( & V_11 -> V_187 . V_189 ) ;
F_65 ( & V_11 -> V_187 . V_190 ) ;
}
static int F_66 ( struct V_10 * V_11 )
{
struct V_26 * V_27 = & V_11 -> V_16 ;
struct V_137 * V_191 = V_11 -> V_191 ;
struct V_135 * V_192 = & V_27 -> V_136 ;
int V_23 ;
V_11 -> V_142 = V_143 ;
F_67 ( V_27 , & V_193 ) ;
sprintf ( V_27 -> V_91 , L_11 , V_11 -> V_25 ) ;
F_68 ( V_27 , V_11 ) ;
V_27 -> V_63 |= V_194 | V_195 ;
V_191 [ V_18 ] . V_63 = V_196 ;
V_191 [ V_107 ] . V_63 = V_197 ;
V_191 [ V_106 ] . V_63 = V_197 ;
V_191 [ V_100 ] . V_63 = V_197 ;
V_191 [ V_102 ] . V_63 = V_197 ;
V_11 -> V_57 [ V_18 ] . V_57 . V_1 =
V_198 ;
V_11 -> V_57 [ V_107 ] . V_57 . V_1 =
V_198 ;
V_11 -> V_57 [ V_106 ] . V_57 . V_1 =
V_198 ;
V_11 -> V_57 [ V_100 ] . V_57 . V_1 =
V_198 ;
V_11 -> V_57 [ V_102 ] . V_57 . V_1 =
V_198 ;
V_192 -> V_199 = & V_200 ;
V_192 -> V_201 = V_140 ;
V_23 = F_69 ( V_192 , V_61 , V_191 ) ;
if ( V_23 < 0 )
return V_23 ;
F_63 ( V_11 , & V_11 -> V_202 ,
V_203 ) ;
F_63 ( V_11 , & V_11 -> V_204 ,
V_205 ) ;
F_63 ( V_11 , & V_11 -> V_206 ,
V_205 ) ;
F_63 ( V_11 , & V_11 -> V_207 ,
V_205 ) ;
F_63 ( V_11 , & V_11 -> V_208 ,
V_205 ) ;
F_64 ( V_11 , & V_11 -> V_209 ) ;
V_23 = F_70 ( & V_11 -> V_202 , L_12 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_70 ( & V_11 -> V_207 , L_13 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_70 ( & V_11 -> V_206 , L_14 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_70 ( & V_11 -> V_204 , L_15 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_70 ( & V_11 -> V_208 , L_16 ) ;
if ( V_23 < 0 )
return V_23 ;
F_71 ( & V_11 -> V_209 , L_17 ) ;
V_23 = F_72 ( & V_11 -> V_116 , 1 ) ;
if ( V_23 )
return V_23 ;
V_11 -> V_210 = F_73 ( & V_11 -> V_116 ,
& V_211 , NULL ) ;
V_11 -> V_96 = F_73 ( & V_11 -> V_116 ,
& V_212 , NULL ) ;
V_11 -> V_103 = F_73 ( & V_11 -> V_116 ,
& V_213 , NULL ) ;
V_11 -> V_99 = F_73 ( & V_11 -> V_116 ,
& V_214 , NULL ) ;
V_11 -> V_215 = F_73 ( & V_11 -> V_116 ,
& V_216 ,
NULL ) ;
V_11 -> V_217 =
F_73 ( & V_11 -> V_116 ,
& V_218 ,
NULL ) ;
V_11 -> V_219 =
F_73 ( & V_11 -> V_116 ,
& V_220 ,
NULL ) ;
V_11 -> V_221 =
F_73 ( & V_11 -> V_116 ,
& V_222 ,
NULL ) ;
V_11 -> V_223 =
F_73 ( & V_11 -> V_116 ,
& V_224 ,
NULL ) ;
#ifdef F_74
V_11 -> V_225 =
F_73 ( & V_11 -> V_116 ,
& V_226 ,
NULL ) ;
#ifdef F_75
V_11 -> V_227 =
F_73 ( & V_11 -> V_116 ,
& V_228 ,
NULL ) ;
#endif
#endif
V_11 -> V_16 . V_116 = & V_11 -> V_116 ;
F_49 ( & V_11 -> V_229 ) ;
return V_11 -> V_116 . error ;
}
int F_76 ( struct V_36 * V_37 )
{
struct V_10 * V_11 ;
int V_2 , V_230 , V_23 = 0 ;
V_37 -> V_231 = 2 ;
for ( V_2 = 0 ; V_2 < V_145 ; V_2 ++ ) {
for ( V_230 = 0 ; V_230 < V_37 -> V_231 ; V_230 ++ ) {
V_23 =
F_77 ( & V_37 -> V_146 [ V_2 ] . V_16 .
V_136 , V_232 ,
& V_37 -> V_11 [ V_230 ] . V_16 . V_136 ,
V_18 , 0 ) ;
if ( V_23 < 0 )
return V_23 ;
}
}
for ( V_2 = 0 ; V_2 < V_37 -> V_233 - 2 ; V_2 ++ ) {
V_23 = F_77 ( & V_37 -> V_88 [ V_2 ] . V_90 -> V_136 , 0 ,
& V_37 -> V_146 [ V_37 -> V_88 [ V_2 ] .
V_234 ] . V_16 . V_136 ,
V_235 ,
V_141 |
V_236 ) ;
if ( V_23 < 0 )
return V_23 ;
}
for ( V_2 = 0 ; V_2 < V_37 -> V_231 ; V_2 ++ ) {
V_11 = & V_37 -> V_11 [ V_2 ] ;
V_23 = F_77 ( & V_11 -> V_16 . V_136 ,
V_107 ,
& V_11 -> V_204 . V_20 . V_136 ,
0 , 0 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_77 ( & V_11 -> V_16 . V_136 ,
V_106 ,
& V_11 -> V_206 . V_20 . V_136 , 0 ,
0 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_77 ( & V_11 -> V_16 . V_136 ,
V_100 ,
& V_11 -> V_207 . V_20 . V_136 ,
0 , 0 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_77 ( & V_11 -> V_16 . V_136 ,
V_102 ,
& V_11 -> V_208 . V_20 .
V_136 , 0 , 0 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_11 -> V_25 )
return 0 ;
V_23 = F_77 ( & V_11 -> V_202 . V_20 . V_136 ,
0 , & V_11 -> V_16 . V_136 ,
V_18 , 0 ) ;
if ( V_23 < 0 )
return V_23 ;
}
return 0 ;
}
static void F_78 ( struct V_10 * V_11 )
{
F_79 ( & V_11 -> V_116 ) ;
F_80 ( & V_11 -> V_16 . V_136 ) ;
}
void F_81 ( struct V_10 * V_11 )
{
struct V_31 * V_32 , * V_237 ;
struct V_238 V_239 ;
unsigned int V_2 , V_240 ;
F_82 (fh, fh_tmp,
&asd->subdev.devnode->fh_list, list) {
V_240 = F_83 ( V_32 ) ;
for ( V_2 = 0 ; V_2 < V_240 ; V_2 ++ )
F_84 ( V_32 , & V_239 , 1 ) ;
}
}
void F_85 ( struct V_10 * V_11 )
{
F_78 ( V_11 ) ;
F_86 ( & V_11 -> V_16 ) ;
F_87 ( & V_11 -> V_202 ) ;
F_87 ( & V_11 -> V_204 ) ;
F_87 ( & V_11 -> V_206 ) ;
F_87 ( & V_11 -> V_207 ) ;
F_87 ( & V_11 -> V_208 ) ;
F_88 ( & V_11 -> V_209 ) ;
}
int F_89 ( struct V_10 * V_11 ,
struct V_241 * V_20 )
{
int V_23 ;
V_23 = F_90 ( V_20 , & V_11 -> V_16 ) ;
if ( V_23 < 0 )
goto error;
V_23 = F_91 ( & V_11 -> V_207 , V_20 ) ;
if ( V_23 < 0 )
goto error;
V_23 = F_91 ( & V_11 -> V_206 , V_20 ) ;
if ( V_23 < 0 )
goto error;
V_23 = F_91 ( & V_11 -> V_204 , V_20 ) ;
if ( V_23 < 0 )
goto error;
V_23 = F_91 ( & V_11 -> V_208 , V_20 ) ;
if ( V_23 < 0 )
goto error;
V_23 = F_92 ( & V_11 -> V_209 , V_20 ) ;
if ( V_23 < 0 )
goto error;
if ( V_11 -> V_25 )
return 0 ;
V_23 = F_91 ( & V_11 -> V_202 , V_20 ) ;
if ( V_23 < 0 )
goto error;
return 0 ;
error:
F_85 ( V_11 ) ;
return V_23 ;
}
int F_93 ( struct V_36 * V_37 )
{
struct V_10 * V_11 ;
int V_2 , V_23 = 0 ;
V_37 -> V_231 = 2 ;
V_37 -> V_11 = F_94 ( V_37 -> V_80 , sizeof( struct V_10 ) *
V_37 -> V_231 , V_242 ) ;
if ( ! V_37 -> V_11 )
return - V_243 ;
for ( V_2 = 0 ; V_2 < V_37 -> V_231 ; V_2 ++ ) {
V_11 = & V_37 -> V_11 [ V_2 ] ;
F_49 ( & V_11 -> V_168 ) ;
V_11 -> V_37 = V_37 ;
F_47 ( V_11 ) ;
V_11 -> V_25 = V_2 ;
V_23 = F_66 ( V_11 ) ;
if ( V_23 < 0 ) {
F_78 ( V_11 ) ;
break;
}
}
return V_23 ;
}
