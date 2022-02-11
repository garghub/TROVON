int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 ;
bool V_12 = false , V_13 = false , V_14 = false , V_15 = false ;
if ( ! V_8 )
return - V_16 ;
V_11 = V_8 -> V_17 -> V_18 [ V_19 ] ;
if ( V_11 ) {
V_13 = true ;
V_12 |= V_11 -> V_20 . V_21 ;
}
V_11 = V_8 -> V_17 -> V_18 [ V_22 ] ;
if ( V_11 ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < V_11 -> V_24 ; V_23 ++ ) {
if ( V_11 -> V_25 [ V_23 ] . V_26 == 10 )
V_14 = true ;
if ( V_11 -> V_25 [ V_23 ] . V_26 == 60 )
V_15 = true ;
}
V_12 |= V_11 -> V_20 . V_21 ;
}
strcpy ( V_5 , L_1 ) ;
if ( V_13 )
strcat ( V_5 , L_2 ) ;
if ( V_14 )
strcat ( V_5 , L_3 ) ;
if ( V_15 )
strcat ( V_5 , L_4 ) ;
if ( V_12 )
strcat ( V_5 , L_5 ) ;
return 0 ;
}
int F_2 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_27 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 ;
struct V_30 V_31 ;
enum V_32 type ;
int V_33 ;
V_29 = F_3 ( V_8 -> V_17 ) ;
switch ( * V_27 ) {
case V_34 :
type = V_35 ;
break;
case V_36 :
type = V_37 ;
break;
case V_38 :
type = V_39 ;
break;
case V_40 :
type = V_41 ;
break;
default:
return - V_42 ;
}
if ( type == V_8 -> V_43 )
return 0 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
F_4 ( V_29 ) ;
V_33 = F_5 ( V_29 , V_2 , type , NULL , & V_31 ) ;
F_6 ( V_29 ) ;
return V_33 ;
}
int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_27 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( ! V_8 )
return - V_16 ;
switch ( V_8 -> V_43 ) {
case V_44 :
* V_27 = V_45 ;
break;
case V_35 :
* V_27 = V_34 ;
break;
case V_37 :
* V_27 = V_36 ;
break;
case V_41 :
* V_27 = V_40 ;
break;
case V_39 :
* V_27 = V_38 ;
break;
case V_46 :
* V_27 = V_47 ;
break;
default:
* V_27 = V_48 ;
break;
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_50 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_51 * V_52 = (struct V_51 * ) V_6 ;
enum V_53 V_54 ;
int V_23 , V_55 = 0 ;
if ( ! V_8 )
return - V_16 ;
V_50 -> V_56 = sizeof( struct V_51 ) ;
memset ( V_52 , 0 , sizeof( struct V_51 ) ) ;
V_52 -> V_57 = V_58 ;
V_52 -> V_59 = 21 ;
V_52 -> V_60 = V_61 ;
V_52 -> V_62 = V_61 ;
V_52 -> V_63 = 0 ;
V_52 -> V_64 = 255 ;
V_52 -> V_65 = 0 ;
V_52 -> V_66 = 2347 ;
V_52 -> V_67 = 256 ;
V_52 -> V_68 = 2346 ;
V_52 -> V_69 = 4 ;
V_52 -> V_70 . V_71 = V_72 ;
switch ( V_8 -> V_17 -> V_73 ) {
case V_74 :
break;
case V_75 :
V_52 -> V_70 . V_76 = ( V_77 ) - 110 ;
V_52 -> V_70 . V_78 = 70 ;
V_52 -> V_79 . V_78 = 35 ;
V_52 -> V_70 . V_71 |= V_80 ;
V_52 -> V_70 . V_71 |= V_81 ;
V_52 -> V_70 . V_71 |= V_82 ;
break;
case V_83 :
V_52 -> V_70 . V_76 = 100 ;
V_52 -> V_70 . V_78 = 100 ;
V_52 -> V_79 . V_78 = 50 ;
V_52 -> V_70 . V_71 |= V_81 ;
V_52 -> V_70 . V_71 |= V_82 ;
break;
}
V_52 -> V_79 . V_76 = V_52 -> V_70 . V_76 / 2 ;
V_52 -> V_79 . V_84 = V_52 -> V_70 . V_84 / 2 ;
V_52 -> V_79 . V_71 = V_52 -> V_70 . V_71 ;
for ( V_23 = 0 ; V_23 < V_8 -> V_17 -> V_85 ; V_23 ++ ) {
switch ( V_8 -> V_17 -> V_86 [ V_23 ] ) {
case V_87 :
V_52 -> V_88 |= ( V_89 |
V_90 ) ;
break;
case V_91 :
V_52 -> V_88 |= ( V_92 |
V_93 ) ;
break;
case V_94 :
V_52 -> V_95 [ V_52 -> V_96 ++ ] =
V_97 ;
break;
case V_98 :
V_52 -> V_95 [ V_52 -> V_96 ++ ] =
V_99 ;
break;
}
}
for ( V_54 = 0 ; V_54 < V_100 ; V_54 ++ ) {
struct V_10 * V_11 ;
V_11 = V_8 -> V_17 -> V_18 [ V_54 ] ;
if ( ! V_11 )
continue;
for ( V_23 = 0 ; V_23 < V_11 -> V_101 && V_55 < V_102 ; V_23 ++ ) {
struct V_103 * V_104 = & V_11 -> V_105 [ V_23 ] ;
if ( ! ( V_104 -> V_106 & V_107 ) ) {
V_52 -> V_108 [ V_55 ] . V_23 =
F_9 (
V_104 -> V_109 ) ;
V_52 -> V_108 [ V_55 ] . V_110 = V_104 -> V_109 ;
V_52 -> V_108 [ V_55 ] . V_111 = 6 ;
V_55 ++ ;
}
}
}
V_52 -> V_112 = V_55 ;
V_52 -> V_113 = V_55 ;
F_10 ( V_52 -> V_114 ) ;
F_11 ( V_52 -> V_114 , V_115 ) ;
F_11 ( V_52 -> V_114 , V_116 ) ;
if ( V_8 -> V_17 -> V_117 > 0 )
V_52 -> V_118 |= V_119 ;
return 0 ;
}
int F_12 ( struct V_17 * V_17 , struct V_120 * V_108 )
{
if ( V_108 -> V_111 == 0 ) {
enum V_53 V_54 = V_22 ;
if ( V_108 -> V_110 < 0 )
return 0 ;
if ( V_108 -> V_110 > 14 )
V_54 = V_19 ;
return F_13 ( V_108 -> V_110 , V_54 ) ;
} else {
int V_23 , div = 1000000 ;
for ( V_23 = 0 ; V_23 < V_108 -> V_111 ; V_23 ++ )
div /= 10 ;
if ( div <= 0 )
return - V_42 ;
return V_108 -> V_110 / div ;
}
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_121 * V_122 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
T_1 V_123 = V_8 -> V_17 -> V_124 ;
int V_125 ;
if ( V_122 -> V_126 || ! V_122 -> V_127 )
V_8 -> V_17 -> V_124 = ( T_1 ) - 1 ;
else if ( V_122 -> V_128 < 0 )
return - V_42 ;
else
V_8 -> V_17 -> V_124 = V_122 -> V_128 ;
V_125 = F_15 ( V_29 , V_129 ) ;
if ( V_125 )
V_8 -> V_17 -> V_124 = V_123 ;
return V_125 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_121 * V_122 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_122 -> V_128 = V_8 -> V_17 -> V_124 ;
V_122 -> V_126 = V_122 -> V_128 == ( T_1 ) - 1 ;
V_122 -> V_127 = 1 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_121 * V_130 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
T_1 V_131 = V_8 -> V_17 -> V_132 ;
int V_125 ;
if ( V_130 -> V_126 || ! V_130 -> V_127 )
V_8 -> V_17 -> V_132 = ( T_1 ) - 1 ;
else if ( V_130 -> V_128 < 256 )
return - V_42 ;
else {
V_8 -> V_17 -> V_132 = V_130 -> V_128 & ~ 0x1 ;
}
V_125 = F_15 ( V_29 , V_133 ) ;
if ( V_125 )
V_8 -> V_17 -> V_132 = V_131 ;
return V_125 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_121 * V_130 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_130 -> V_128 = V_8 -> V_17 -> V_132 ;
V_130 -> V_126 = V_130 -> V_128 == ( T_1 ) - 1 ;
V_130 -> V_127 = 1 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_121 * V_134 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
T_1 V_135 = 0 ;
V_77 V_136 = V_8 -> V_17 -> V_137 ;
V_77 V_138 = V_8 -> V_17 -> V_139 ;
int V_125 ;
if ( V_134 -> V_126 ||
( V_134 -> V_106 & V_140 ) != V_61 )
return - V_42 ;
if ( V_134 -> V_106 & V_141 ) {
V_8 -> V_17 -> V_137 = V_134 -> V_128 ;
V_135 |= V_142 ;
} else if ( V_134 -> V_106 & V_143 ) {
V_8 -> V_17 -> V_139 = V_134 -> V_128 ;
V_135 |= V_144 ;
} else {
V_8 -> V_17 -> V_139 = V_134 -> V_128 ;
V_8 -> V_17 -> V_137 = V_134 -> V_128 ;
V_135 |= V_142 ;
V_135 |= V_144 ;
}
if ( ! V_135 )
return 0 ;
V_125 = F_15 ( V_29 , V_135 ) ;
if ( V_125 ) {
V_8 -> V_17 -> V_139 = V_138 ;
V_8 -> V_17 -> V_137 = V_136 ;
}
return V_125 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_121 * V_134 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_134 -> V_126 = 0 ;
if ( V_134 -> V_106 == 0 || ( V_134 -> V_106 & V_143 ) ) {
V_134 -> V_106 |= V_61 ;
V_134 -> V_128 = V_8 -> V_17 -> V_139 ;
if ( V_8 -> V_17 -> V_137 != V_8 -> V_17 -> V_139 )
V_134 -> V_106 |= V_141 ;
return 0 ;
}
if ( V_134 -> V_106 & V_141 ) {
V_134 -> V_106 = V_61 | V_141 ;
V_134 -> V_128 = V_8 -> V_17 -> V_137 ;
}
return 0 ;
}
static int F_21 ( struct V_28 * V_29 ,
struct V_1 * V_2 , bool V_145 ,
const V_77 * V_146 , bool remove , bool V_147 ,
int V_148 , struct V_149 * V_150 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_125 , V_23 ;
bool V_151 = false ;
if ( V_145 && ! V_146 )
return - V_42 ;
if ( ! V_8 -> V_152 . V_153 ) {
V_8 -> V_152 . V_153 = F_22 ( sizeof( * V_8 -> V_152 . V_153 ) ,
V_154 ) ;
if ( ! V_8 -> V_152 . V_153 )
return - V_155 ;
for ( V_23 = 0 ; V_23 < 6 ; V_23 ++ )
V_8 -> V_152 . V_153 -> V_150 [ V_23 ] . V_156 =
V_8 -> V_152 . V_153 -> V_50 [ V_23 ] ;
}
if ( V_8 -> V_43 != V_37 &&
V_8 -> V_43 != V_35 )
return - V_16 ;
if ( V_150 -> V_157 == V_158 ) {
if ( ! V_8 -> V_159 )
return - V_160 ;
if ( ! V_29 -> V_161 -> V_162 )
return - V_16 ;
if ( V_148 < 4 || V_148 > 5 )
return - V_42 ;
} else if ( V_148 < 0 || V_148 > 3 )
return - V_42 ;
if ( remove ) {
V_125 = 0 ;
if ( V_8 -> V_159 ) {
if ( V_148 == V_8 -> V_152 . V_163 &&
V_8 -> V_43 == V_37 ) {
F_23 ( V_29 , V_8 -> V_164 , true ) ;
V_151 = true ;
}
if ( ! V_145 && V_146 &&
! ( V_29 -> V_17 . V_106 & V_165 ) )
V_125 = - V_166 ;
else
V_125 = F_24 ( V_29 , V_2 , V_148 , V_145 ,
V_146 ) ;
}
V_8 -> V_152 . V_167 . V_168 = false ;
if ( V_125 == - V_166 )
V_125 = 0 ;
if ( ! V_125 ) {
if ( ! V_146 ) {
V_8 -> V_152 . V_153 -> V_150 [ V_148 ] . V_169 = 0 ;
V_8 -> V_152 . V_153 -> V_150 [ V_148 ] . V_157 = 0 ;
}
if ( V_148 == V_8 -> V_152 . V_163 )
V_8 -> V_152 . V_163 = - 1 ;
else if ( V_148 == V_8 -> V_152 . V_170 )
V_8 -> V_152 . V_170 = - 1 ;
}
if ( ! V_125 && V_151 )
V_125 = F_25 ( V_29 , V_8 ) ;
return V_125 ;
}
if ( V_146 )
V_147 = false ;
if ( F_26 ( V_29 , V_150 , V_148 , V_145 , V_146 ) )
return - V_42 ;
V_125 = 0 ;
if ( V_8 -> V_159 )
V_125 = F_27 ( V_29 , V_2 , V_148 , V_145 , V_146 , V_150 ) ;
if ( V_125 )
return V_125 ;
if ( ! V_146 ) {
V_8 -> V_152 . V_153 -> V_150 [ V_148 ] = * V_150 ;
memcpy ( V_8 -> V_152 . V_153 -> V_50 [ V_148 ] ,
V_150 -> V_156 , V_150 -> V_169 ) ;
V_8 -> V_152 . V_153 -> V_150 [ V_148 ] . V_156 =
V_8 -> V_152 . V_153 -> V_50 [ V_148 ] ;
}
if ( ( V_150 -> V_157 == V_94 ||
V_150 -> V_157 == V_98 ) &&
( V_147 || ( ! V_146 && V_8 -> V_152 . V_163 == - 1 ) ) ) {
if ( V_8 -> V_159 ) {
if ( V_8 -> V_43 == V_37 &&
V_8 -> V_152 . V_163 == - 1 ) {
F_23 ( V_29 , V_8 -> V_164 , true ) ;
V_151 = true ;
}
V_125 = F_28 ( V_29 , V_2 , V_148 , true , true ) ;
}
if ( ! V_125 ) {
V_8 -> V_152 . V_163 = V_148 ;
if ( V_151 )
V_125 = F_25 ( V_29 , V_8 ) ;
}
return V_125 ;
}
if ( V_150 -> V_157 == V_158 &&
( V_147 || ( ! V_146 && V_8 -> V_152 . V_170 == - 1 ) ) ) {
if ( V_8 -> V_159 )
V_125 = F_29 ( V_29 , V_2 , V_148 ) ;
if ( ! V_125 )
V_8 -> V_152 . V_170 = V_148 ;
return V_125 ;
}
return 0 ;
}
static int F_30 ( struct V_28 * V_29 ,
struct V_1 * V_2 , bool V_145 ,
const V_77 * V_146 , bool remove , bool V_147 ,
int V_148 , struct V_149 * V_150 )
{
int V_125 ;
F_31 ( & V_29 -> V_171 ) ;
F_32 ( V_2 -> V_9 ) ;
V_125 = F_21 ( V_29 , V_2 , V_145 , V_146 ,
remove , V_147 , V_148 , V_150 ) ;
F_33 ( V_2 -> V_9 ) ;
F_34 ( & V_29 -> V_171 ) ;
return V_125 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_172 , char * V_173 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
int V_148 , V_125 ;
bool remove = false ;
struct V_149 V_150 ;
if ( V_8 -> V_43 != V_35 &&
V_8 -> V_43 != V_37 )
return - V_16 ;
if ( ! V_29 -> V_161 -> V_174 ||
! V_29 -> V_161 -> V_175 ||
! V_29 -> V_161 -> V_176 )
return - V_16 ;
V_148 = V_172 -> V_106 & V_177 ;
if ( V_148 == 0 ) {
V_148 = V_8 -> V_152 . V_163 ;
if ( V_148 < 0 )
V_148 = 0 ;
} else if ( V_148 < 1 || V_148 > 4 )
return - V_42 ;
else
V_148 -- ;
if ( V_172 -> V_106 & V_178 )
remove = true ;
else if ( V_172 -> V_56 == 0 ) {
V_125 = 0 ;
F_32 ( V_8 ) ;
if ( V_8 -> V_159 )
V_125 = F_28 ( V_29 , V_2 , V_148 , true ,
true ) ;
if ( ! V_125 )
V_8 -> V_152 . V_163 = V_148 ;
F_33 ( V_8 ) ;
return V_125 ;
}
memset ( & V_150 , 0 , sizeof( V_150 ) ) ;
V_150 . V_156 = V_173 ;
V_150 . V_169 = V_172 -> V_56 ;
if ( V_172 -> V_56 == 5 )
V_150 . V_157 = V_94 ;
else if ( V_172 -> V_56 == 13 )
V_150 . V_157 = V_98 ;
else if ( ! remove )
return - V_42 ;
return F_30 ( V_29 , V_2 , false , NULL , remove ,
V_8 -> V_152 . V_163 == - 1 ,
V_148 , & V_150 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_172 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
struct V_179 * V_180 = (struct V_179 * ) V_6 ;
const V_77 * V_146 ;
int V_148 ;
bool remove = false ;
struct V_149 V_150 ;
T_1 V_157 ;
if ( V_8 -> V_43 != V_35 &&
V_8 -> V_43 != V_37 )
return - V_16 ;
if ( ! V_29 -> V_161 -> V_174 ||
! V_29 -> V_161 -> V_175 ||
! V_29 -> V_161 -> V_176 )
return - V_16 ;
switch ( V_180 -> V_181 ) {
case V_182 :
remove = true ;
V_157 = 0 ;
break;
case V_183 :
if ( V_180 -> V_169 == 5 )
V_157 = V_94 ;
else if ( V_180 -> V_169 == 13 )
V_157 = V_98 ;
else
return - V_42 ;
break;
case V_184 :
V_157 = V_87 ;
break;
case V_185 :
V_157 = V_91 ;
break;
case V_186 :
V_157 = V_158 ;
break;
default:
return - V_16 ;
}
if ( V_172 -> V_106 & V_178 )
remove = true ;
V_148 = V_172 -> V_106 & V_177 ;
if ( V_157 == V_158 ) {
if ( V_148 < 4 || V_148 > 5 ) {
V_148 = V_8 -> V_152 . V_170 ;
if ( V_148 < 0 )
return - V_42 ;
} else
V_148 -- ;
} else {
if ( V_148 < 1 || V_148 > 4 ) {
V_148 = V_8 -> V_152 . V_163 ;
if ( V_148 < 0 )
return - V_42 ;
} else
V_148 -- ;
}
V_146 = V_180 -> V_146 . V_187 ;
if ( F_37 ( V_146 ) )
V_146 = NULL ;
memset ( & V_150 , 0 , sizeof( V_150 ) ) ;
V_150 . V_156 = V_180 -> V_156 ;
V_150 . V_169 = V_180 -> V_169 ;
V_150 . V_157 = V_157 ;
if ( V_180 -> V_188 & V_189 ) {
V_150 . V_190 = V_180 -> V_191 ;
V_150 . V_192 = 6 ;
}
return F_30 (
V_29 , V_2 ,
! ( V_180 -> V_188 & V_193 ) ,
V_146 , remove ,
V_180 -> V_188 & V_194 ,
V_148 , & V_150 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_172 , char * V_173 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_148 ;
if ( V_8 -> V_43 != V_35 &&
V_8 -> V_43 != V_37 )
return - V_16 ;
V_148 = V_172 -> V_106 & V_177 ;
if ( V_148 == 0 ) {
V_148 = V_8 -> V_152 . V_163 ;
if ( V_148 < 0 )
V_148 = 0 ;
} else if ( V_148 < 1 || V_148 > 4 )
return - V_42 ;
else
V_148 -- ;
V_172 -> V_106 = V_148 + 1 ;
if ( ! V_8 -> V_152 . V_153 || ! V_8 -> V_152 . V_153 -> V_150 [ V_148 ] . V_157 ) {
V_172 -> V_106 |= V_178 ;
V_172 -> V_56 = 0 ;
return 0 ;
}
V_172 -> V_56 = F_39 ( V_195 , V_172 -> V_56 ,
V_8 -> V_152 . V_153 -> V_150 [ V_148 ] . V_169 ) ;
memcpy ( V_173 , V_8 -> V_152 . V_153 -> V_150 [ V_148 ] . V_156 , V_172 -> V_56 ) ;
V_172 -> V_106 |= V_196 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_197 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
struct V_198 V_199 = {
. V_200 = V_201 ,
} ;
int V_108 , V_125 ;
switch ( V_8 -> V_43 ) {
case V_35 :
return F_41 ( V_2 , V_4 , V_197 , V_6 ) ;
case V_37 :
return F_42 ( V_2 , V_4 , V_197 , V_6 ) ;
case V_41 :
V_108 = F_12 ( V_8 -> V_17 , V_197 ) ;
if ( V_108 < 0 )
return V_108 ;
if ( V_108 == 0 )
return - V_42 ;
V_199 . V_202 = V_108 ;
V_199 . V_104 = F_43 ( & V_29 -> V_17 , V_108 ) ;
if ( ! V_199 . V_104 )
return - V_42 ;
F_31 ( & V_29 -> V_171 ) ;
V_125 = F_44 ( V_29 , & V_199 ) ;
F_34 ( & V_29 -> V_171 ) ;
return V_125 ;
case V_203 :
V_108 = F_12 ( V_8 -> V_17 , V_197 ) ;
if ( V_108 < 0 )
return V_108 ;
if ( V_108 == 0 )
return - V_42 ;
V_199 . V_202 = V_108 ;
V_199 . V_104 = F_43 ( & V_29 -> V_17 , V_108 ) ;
if ( ! V_199 . V_104 )
return - V_42 ;
F_31 ( & V_29 -> V_171 ) ;
V_125 = F_45 ( V_29 , V_8 , & V_199 ) ;
F_34 ( & V_29 -> V_171 ) ;
return V_125 ;
default:
return - V_16 ;
}
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_108 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
struct V_198 V_199 ;
int V_33 ;
switch ( V_8 -> V_43 ) {
case V_35 :
return F_47 ( V_2 , V_4 , V_108 , V_6 ) ;
case V_37 :
return F_48 ( V_2 , V_4 , V_108 , V_6 ) ;
case V_41 :
if ( ! V_29 -> V_161 -> V_204 )
return - V_42 ;
V_33 = F_49 ( V_29 , V_8 , & V_199 ) ;
if ( V_33 )
return V_33 ;
V_108 -> V_110 = V_199 . V_104 -> V_109 ;
V_108 -> V_111 = 6 ;
return 0 ;
default:
return - V_42 ;
}
}
static int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_205 * V_50 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
enum V_206 type ;
int V_207 = 0 ;
if ( ( V_50 -> V_208 . V_106 & V_209 ) != V_210 )
return - V_42 ;
if ( V_50 -> V_208 . V_106 & V_211 )
return - V_42 ;
if ( ! V_29 -> V_161 -> V_212 )
return - V_16 ;
if ( ! V_50 -> V_208 . V_126 ) {
F_51 ( V_29 -> V_213 , false ) ;
if ( V_50 -> V_208 . V_127 ) {
if ( V_50 -> V_208 . V_128 < 0 )
return - V_42 ;
V_207 = V_50 -> V_208 . V_128 ;
type = V_214 ;
} else {
if ( V_50 -> V_208 . V_128 < 0 ) {
type = V_215 ;
} else {
V_207 = V_50 -> V_208 . V_128 ;
type = V_216 ;
}
}
} else {
F_51 ( V_29 -> V_213 , true ) ;
F_52 ( & V_29 -> V_217 ) ;
return 0 ;
}
return F_53 ( V_29 , V_8 , type , F_54 ( V_207 ) ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_205 * V_50 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
int V_125 , V_218 ;
if ( ( V_50 -> V_208 . V_106 & V_209 ) != V_210 )
return - V_42 ;
if ( V_50 -> V_208 . V_106 & V_211 )
return - V_42 ;
if ( ! V_29 -> V_161 -> V_219 )
return - V_16 ;
V_125 = F_56 ( V_29 , V_8 , & V_218 ) ;
if ( V_125 )
return V_125 ;
V_50 -> V_208 . V_127 = 1 ;
V_50 -> V_208 . V_126 = F_57 ( V_29 -> V_213 ) ;
V_50 -> V_208 . V_128 = V_218 ;
V_50 -> V_208 . V_106 = V_210 ;
return 0 ;
}
static int F_58 ( struct V_7 * V_8 ,
T_2 V_220 )
{
int V_221 = 0 ;
if ( ! V_220 )
return - V_42 ;
if ( V_220 & ~ ( V_222 |
V_223 |
V_224 ) )
return - V_42 ;
if ( V_220 & V_222 ) {
V_221 ++ ;
V_8 -> V_152 . V_167 . V_225 = V_226 ;
}
if ( V_220 & V_223 ) {
V_221 ++ ;
V_8 -> V_152 . V_167 . V_225 = V_227 ;
}
if ( V_220 & V_224 ) {
V_221 ++ ;
V_8 -> V_152 . V_167 . V_225 = V_228 ;
}
if ( V_221 > 1 )
V_8 -> V_152 . V_167 . V_225 = V_229 ;
return 0 ;
}
static int F_59 ( struct V_7 * V_8 , T_1 V_230 )
{
if ( V_230 & ~ ( V_231 |
V_232 |
V_233 ) )
return - V_42 ;
if ( ( V_230 & V_233 ) &&
( V_230 & ( V_231 |
V_232 ) ) )
return - V_42 ;
if ( V_230 & V_233 )
V_8 -> V_152 . V_167 . V_234 . V_230 &=
~ ( V_235 | V_236 ) ;
if ( V_230 & V_231 )
V_8 -> V_152 . V_167 . V_234 . V_230 |=
V_235 ;
if ( V_230 & V_232 )
V_8 -> V_152 . V_167 . V_234 . V_230 |=
V_236 ;
return 0 ;
}
static int F_60 ( struct V_7 * V_8 , T_1 V_157 )
{
if ( V_157 & V_237 )
V_8 -> V_152 . V_167 . V_234 . V_238 =
V_94 ;
else if ( V_157 & V_239 )
V_8 -> V_152 . V_167 . V_234 . V_238 =
V_98 ;
else if ( V_157 & V_240 )
V_8 -> V_152 . V_167 . V_234 . V_238 =
V_87 ;
else if ( V_157 & V_241 )
V_8 -> V_152 . V_167 . V_234 . V_238 =
V_91 ;
else if ( V_157 & V_242 )
V_8 -> V_152 . V_167 . V_234 . V_238 =
V_158 ;
else if ( V_157 & V_243 )
V_8 -> V_152 . V_167 . V_234 . V_238 = 0 ;
else
return - V_42 ;
return 0 ;
}
static int F_61 ( struct V_7 * V_8 , T_1 V_157 )
{
int V_244 = 0 ;
T_1 * V_245 = V_8 -> V_152 . V_167 . V_234 . V_245 ;
if ( V_157 & V_237 ) {
V_245 [ V_244 ] = V_94 ;
V_244 ++ ;
}
if ( V_157 & V_239 ) {
V_245 [ V_244 ] = V_98 ;
V_244 ++ ;
}
if ( V_157 & V_240 ) {
V_245 [ V_244 ] = V_87 ;
V_244 ++ ;
}
if ( V_157 & V_241 ) {
V_245 [ V_244 ] = V_91 ;
V_244 ++ ;
}
if ( V_157 & V_242 ) {
V_245 [ V_244 ] = V_158 ;
V_244 ++ ;
}
F_62 ( V_246 < 5 ) ;
V_8 -> V_152 . V_167 . V_234 . V_247 = V_244 ;
return 0 ;
}
static int F_63 ( struct V_7 * V_8 , T_1 V_248 )
{
int V_249 = 0 ;
if ( V_248 & ~ ( V_250 |
V_251 ) )
return - V_42 ;
if ( V_248 & V_250 ) {
V_8 -> V_152 . V_167 . V_234 . V_252 [ V_249 ] =
V_253 ;
V_249 ++ ;
}
if ( V_248 & V_251 ) {
V_8 -> V_152 . V_167 . V_234 . V_252 [ V_249 ] =
V_254 ;
V_249 ++ ;
}
V_8 -> V_152 . V_167 . V_234 . V_255 = V_249 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_121 * V_50 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_8 -> V_43 != V_35 )
return - V_16 ;
switch ( V_50 -> V_106 & V_256 ) {
case V_257 :
V_8 -> V_152 . V_167 . V_168 = V_50 -> V_128 ;
return 0 ;
case V_258 :
return F_59 ( V_8 , V_50 -> V_128 ) ;
case V_259 :
return F_60 ( V_8 , V_50 -> V_128 ) ;
case V_260 :
return F_63 ( V_8 , V_50 -> V_128 ) ;
case V_261 :
return F_61 ( V_8 , V_50 -> V_128 ) ;
case V_262 :
return F_58 ( V_8 , V_50 -> V_128 ) ;
case V_263 :
case V_264 :
case V_265 :
case V_266 :
return 0 ;
default:
return - V_16 ;
}
}
static int F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_121 * V_50 , char * V_6 )
{
return - V_16 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_121 * V_267 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
bool V_268 = V_8 -> V_268 ;
int V_269 = V_8 -> V_270 ;
int V_125 ;
if ( V_8 -> V_43 != V_35 )
return - V_42 ;
if ( ! V_29 -> V_161 -> V_271 )
return - V_16 ;
if ( V_267 -> V_126 ) {
V_268 = false ;
} else {
switch ( V_267 -> V_106 & V_272 ) {
case V_273 :
case V_272 :
case V_274 :
V_268 = true ;
break;
default:
return - V_42 ;
}
if ( V_267 -> V_106 & ~ ( V_272 | V_275 ) )
return - V_42 ;
if ( V_267 -> V_106 & V_275 )
V_269 = V_267 -> V_128 / 1000 ;
}
V_125 = F_67 ( V_29 , V_2 , V_268 , V_269 ) ;
if ( V_125 )
return V_125 ;
V_8 -> V_268 = V_268 ;
V_8 -> V_270 = V_269 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_121 * V_267 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_267 -> V_126 = ! V_8 -> V_268 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_276 * V_146 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
int V_125 ;
if ( F_70 ( V_8 -> V_43 != V_39 ) )
return - V_42 ;
if ( V_146 -> V_277 != V_278 )
return - V_42 ;
if ( F_71 ( V_2 ) )
return - V_279 ;
if ( ! V_29 -> V_161 -> V_280 )
return - V_16 ;
V_125 = F_72 ( V_29 , V_2 , ( V_77 * ) & V_146 -> V_187 ) ;
if ( V_125 )
return V_125 ;
memcpy ( & V_8 -> V_152 . V_281 , ( V_77 * ) & V_146 -> V_187 , V_282 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_276 * V_146 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( F_70 ( V_8 -> V_43 != V_39 ) )
return - V_42 ;
V_146 -> V_277 = V_278 ;
memcpy ( & V_146 -> V_187 , V_8 -> V_152 . V_281 , V_282 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_121 * V_283 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
struct V_284 V_285 ;
T_1 V_127 , V_286 ;
struct V_10 * V_11 ;
int V_54 , V_287 ;
bool V_288 = false ;
if ( ! V_29 -> V_161 -> V_289 )
return - V_16 ;
memset ( & V_285 , 0 , sizeof( V_285 ) ) ;
V_127 = 0 ;
V_286 = ( T_1 ) - 1 ;
if ( V_283 -> V_128 < 0 ) {
} else if ( V_283 -> V_127 ) {
V_127 = V_283 -> V_128 / 100000 ;
} else {
V_286 = V_283 -> V_128 / 100000 ;
}
for ( V_54 = 0 ; V_54 < V_100 ; V_54 ++ ) {
V_11 = V_8 -> V_17 -> V_18 [ V_54 ] ;
if ( V_11 == NULL )
continue;
for ( V_287 = 0 ; V_287 < V_11 -> V_24 ; V_287 ++ ) {
struct V_290 * V_291 = & V_11 -> V_25 [ V_287 ] ;
if ( V_127 == V_291 -> V_26 ) {
V_285 . V_292 [ V_54 ] . V_293 = 1 << V_287 ;
V_288 = true ;
break;
}
if ( V_291 -> V_26 <= V_286 ) {
V_285 . V_292 [ V_54 ] . V_293 |= 1 << V_287 ;
V_288 = true ;
}
}
}
if ( ! V_288 )
return - V_42 ;
return F_75 ( V_29 , V_2 , NULL , & V_285 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_121 * V_283 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
static struct V_294 V_295 ;
V_77 V_146 [ V_282 ] ;
int V_125 ;
if ( V_8 -> V_43 != V_35 )
return - V_16 ;
if ( ! V_29 -> V_161 -> V_296 )
return - V_16 ;
V_125 = 0 ;
F_32 ( V_8 ) ;
if ( V_8 -> V_159 )
memcpy ( V_146 , V_8 -> V_159 -> V_297 . V_281 , V_282 ) ;
else
V_125 = - V_16 ;
F_33 ( V_8 ) ;
if ( V_125 )
return V_125 ;
V_125 = F_77 ( V_29 , V_2 , V_146 , & V_295 ) ;
if ( V_125 )
return V_125 ;
if ( ! ( V_295 . V_298 & V_299 ) )
return - V_16 ;
V_283 -> V_128 = 100000 * F_78 ( & V_295 . V_300 ) ;
return 0 ;
}
static struct V_301 * F_79 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
static struct V_301 V_302 ;
static struct V_294 V_295 ;
V_77 V_281 [ V_282 ] ;
if ( V_2 -> V_9 -> V_43 != V_35 )
return NULL ;
if ( ! V_29 -> V_161 -> V_296 )
return NULL ;
F_32 ( V_8 ) ;
if ( ! V_8 -> V_159 ) {
F_33 ( V_8 ) ;
return NULL ;
}
memcpy ( V_281 , V_8 -> V_159 -> V_297 . V_281 , V_282 ) ;
F_33 ( V_8 ) ;
if ( F_77 ( V_29 , V_2 , V_281 , & V_295 ) )
return NULL ;
memset ( & V_302 , 0 , sizeof( V_302 ) ) ;
switch ( V_29 -> V_17 . V_73 ) {
case V_75 :
if ( V_295 . V_298 & V_303 ) {
int V_304 = V_295 . signal ;
V_302 . V_78 . V_71 |= V_82 ;
V_302 . V_78 . V_71 |= V_81 ;
V_302 . V_78 . V_71 |= V_80 ;
V_302 . V_78 . V_76 = V_304 ;
if ( V_304 < - 110 )
V_304 = - 110 ;
else if ( V_304 > - 40 )
V_304 = - 40 ;
V_302 . V_78 . V_78 = V_304 + 110 ;
break;
}
case V_83 :
if ( V_295 . V_298 & V_303 ) {
V_302 . V_78 . V_71 |= V_82 ;
V_302 . V_78 . V_71 |= V_81 ;
V_302 . V_78 . V_76 = V_295 . signal ;
V_302 . V_78 . V_78 = V_295 . signal ;
break;
}
default:
V_302 . V_78 . V_71 |= V_305 ;
V_302 . V_78 . V_71 |= V_306 ;
}
V_302 . V_78 . V_71 |= V_72 ;
if ( V_295 . V_298 & V_307 )
V_302 . V_308 . V_309 = V_295 . V_310 ;
if ( V_295 . V_298 & V_311 )
V_302 . V_308 . V_312 = V_295 . V_313 ;
return & V_302 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_276 * V_314 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
switch ( V_8 -> V_43 ) {
case V_37 :
return F_81 ( V_2 , V_4 , V_314 , V_6 ) ;
case V_35 :
return F_82 ( V_2 , V_4 , V_314 , V_6 ) ;
case V_39 :
return F_69 ( V_2 , V_4 , V_314 , V_6 ) ;
default:
return - V_16 ;
}
}
static int F_83 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_276 * V_314 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
switch ( V_8 -> V_43 ) {
case V_37 :
return F_84 ( V_2 , V_4 , V_314 , V_6 ) ;
case V_35 :
return F_85 ( V_2 , V_4 , V_314 , V_6 ) ;
case V_39 :
return F_73 ( V_2 , V_4 , V_314 , V_6 ) ;
default:
return - V_16 ;
}
}
static int F_86 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_50 , char * V_315 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
switch ( V_8 -> V_43 ) {
case V_37 :
return F_87 ( V_2 , V_4 , V_50 , V_315 ) ;
case V_35 :
return F_88 ( V_2 , V_4 , V_50 , V_315 ) ;
default:
return - V_16 ;
}
}
static int F_89 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_50 , char * V_315 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_50 -> V_106 = 0 ;
V_50 -> V_56 = 0 ;
switch ( V_8 -> V_43 ) {
case V_37 :
return F_90 ( V_2 , V_4 , V_50 , V_315 ) ;
case V_35 :
return F_91 ( V_2 , V_4 , V_50 , V_315 ) ;
default:
return - V_16 ;
}
}
static int F_92 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_50 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
struct V_316 V_317 ;
struct V_318 * V_319 = (struct V_318 * ) V_6 ;
memset ( & V_317 , 0 , sizeof( struct V_316 ) ) ;
if ( V_8 -> V_43 != V_35 )
return - V_42 ;
V_317 . V_281 = V_319 -> V_281 . V_187 ;
V_317 . V_320 = V_319 -> V_320 ;
switch ( V_319 -> V_321 ) {
case V_322 :
if ( ! V_29 -> V_161 -> V_323 )
return - V_16 ;
return F_93 ( V_29 , V_2 , & V_317 ) ;
case V_324 :
if ( ! V_29 -> V_161 -> V_325 )
return - V_16 ;
return F_94 ( V_29 , V_2 , & V_317 ) ;
case V_326 :
if ( ! V_29 -> V_161 -> V_327 )
return - V_16 ;
return F_95 ( V_29 , V_2 ) ;
default:
return - V_16 ;
}
}
