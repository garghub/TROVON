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
V_52 -> V_70 . V_76 = - 110 ;
V_52 -> V_70 . V_77 = 70 ;
V_52 -> V_78 . V_77 = 35 ;
V_52 -> V_70 . V_71 |= V_79 ;
V_52 -> V_70 . V_71 |= V_80 ;
V_52 -> V_70 . V_71 |= V_81 ;
break;
case V_82 :
V_52 -> V_70 . V_76 = 100 ;
V_52 -> V_70 . V_77 = 100 ;
V_52 -> V_78 . V_77 = 50 ;
V_52 -> V_70 . V_71 |= V_80 ;
V_52 -> V_70 . V_71 |= V_81 ;
break;
}
V_52 -> V_78 . V_76 = V_52 -> V_70 . V_76 / 2 ;
V_52 -> V_78 . V_83 = V_52 -> V_70 . V_83 / 2 ;
V_52 -> V_78 . V_71 = V_52 -> V_70 . V_71 ;
for ( V_23 = 0 ; V_23 < V_8 -> V_17 -> V_84 ; V_23 ++ ) {
switch ( V_8 -> V_17 -> V_85 [ V_23 ] ) {
case V_86 :
V_52 -> V_87 |= ( V_88 |
V_89 ) ;
break;
case V_90 :
V_52 -> V_87 |= ( V_91 |
V_92 ) ;
break;
case V_93 :
V_52 -> V_94 [ V_52 -> V_95 ++ ] =
V_96 ;
break;
case V_97 :
V_52 -> V_94 [ V_52 -> V_95 ++ ] =
V_98 ;
break;
}
}
for ( V_54 = 0 ; V_54 < V_99 ; V_54 ++ ) {
struct V_10 * V_11 ;
V_11 = V_8 -> V_17 -> V_18 [ V_54 ] ;
if ( ! V_11 )
continue;
for ( V_23 = 0 ; V_23 < V_11 -> V_100 && V_55 < V_101 ; V_23 ++ ) {
struct V_102 * V_103 = & V_11 -> V_104 [ V_23 ] ;
if ( ! ( V_103 -> V_105 & V_106 ) ) {
V_52 -> V_107 [ V_55 ] . V_23 =
F_9 (
V_103 -> V_108 ) ;
V_52 -> V_107 [ V_55 ] . V_109 = V_103 -> V_108 ;
V_52 -> V_107 [ V_55 ] . V_110 = 6 ;
V_55 ++ ;
}
}
}
V_52 -> V_111 = V_55 ;
V_52 -> V_112 = V_55 ;
F_10 ( V_52 -> V_113 ) ;
F_11 ( V_52 -> V_113 , V_114 ) ;
F_11 ( V_52 -> V_113 , V_115 ) ;
if ( V_8 -> V_17 -> V_116 > 0 )
V_52 -> V_117 |= V_118 ;
return 0 ;
}
int F_12 ( struct V_17 * V_17 , struct V_119 * V_107 )
{
if ( V_107 -> V_110 == 0 ) {
enum V_53 V_54 = V_22 ;
if ( V_107 -> V_109 < 0 )
return 0 ;
if ( V_107 -> V_109 > 14 )
V_54 = V_19 ;
return F_13 ( V_107 -> V_109 , V_54 ) ;
} else {
int V_23 , div = 1000000 ;
for ( V_23 = 0 ; V_23 < V_107 -> V_110 ; V_23 ++ )
div /= 10 ;
if ( div <= 0 )
return - V_42 ;
return V_107 -> V_109 / div ;
}
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_121 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
T_1 V_122 = V_8 -> V_17 -> V_123 ;
int V_124 ;
if ( V_121 -> V_125 || ! V_121 -> V_126 )
V_8 -> V_17 -> V_123 = ( T_1 ) - 1 ;
else if ( V_121 -> V_127 < 0 )
return - V_42 ;
else
V_8 -> V_17 -> V_123 = V_121 -> V_127 ;
V_124 = V_29 -> V_128 -> V_129 ( V_8 -> V_17 ,
V_130 ) ;
if ( V_124 )
V_8 -> V_17 -> V_123 = V_122 ;
return V_124 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_121 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_121 -> V_127 = V_8 -> V_17 -> V_123 ;
V_121 -> V_125 = V_121 -> V_127 == ( T_1 ) - 1 ;
V_121 -> V_126 = 1 ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_131 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
T_1 V_132 = V_8 -> V_17 -> V_133 ;
int V_124 ;
if ( V_131 -> V_125 || ! V_131 -> V_126 )
V_8 -> V_17 -> V_133 = ( T_1 ) - 1 ;
else if ( V_131 -> V_127 < 256 )
return - V_42 ;
else {
V_8 -> V_17 -> V_133 = V_131 -> V_127 & ~ 0x1 ;
}
V_124 = V_29 -> V_128 -> V_129 ( V_8 -> V_17 ,
V_134 ) ;
if ( V_124 )
V_8 -> V_17 -> V_133 = V_132 ;
return V_124 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_131 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_131 -> V_127 = V_8 -> V_17 -> V_133 ;
V_131 -> V_125 = V_131 -> V_127 == ( T_1 ) - 1 ;
V_131 -> V_126 = 1 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_135 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
T_1 V_136 = 0 ;
T_2 V_137 = V_8 -> V_17 -> V_138 ;
T_2 V_139 = V_8 -> V_17 -> V_140 ;
int V_124 ;
if ( V_135 -> V_125 ||
( V_135 -> V_105 & V_141 ) != V_61 )
return - V_42 ;
if ( V_135 -> V_105 & V_142 ) {
V_8 -> V_17 -> V_138 = V_135 -> V_127 ;
V_136 |= V_143 ;
} else if ( V_135 -> V_105 & V_144 ) {
V_8 -> V_17 -> V_140 = V_135 -> V_127 ;
V_136 |= V_145 ;
} else {
V_8 -> V_17 -> V_140 = V_135 -> V_127 ;
V_8 -> V_17 -> V_138 = V_135 -> V_127 ;
V_136 |= V_143 ;
V_136 |= V_145 ;
}
if ( ! V_136 )
return 0 ;
V_124 = V_29 -> V_128 -> V_129 ( V_8 -> V_17 , V_136 ) ;
if ( V_124 ) {
V_8 -> V_17 -> V_140 = V_139 ;
V_8 -> V_17 -> V_138 = V_137 ;
}
return V_124 ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_135 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_135 -> V_125 = 0 ;
if ( V_135 -> V_105 == 0 || ( V_135 -> V_105 & V_144 ) ) {
V_135 -> V_105 |= V_61 ;
V_135 -> V_127 = V_8 -> V_17 -> V_140 ;
if ( V_8 -> V_17 -> V_138 != V_8 -> V_17 -> V_140 )
V_135 -> V_105 |= V_142 ;
return 0 ;
}
if ( V_135 -> V_105 & V_142 ) {
V_135 -> V_105 = V_61 | V_142 ;
V_135 -> V_127 = V_8 -> V_17 -> V_138 ;
}
return 0 ;
}
static int F_20 ( struct V_28 * V_29 ,
struct V_1 * V_2 , bool V_146 ,
const T_2 * V_147 , bool remove , bool V_148 ,
int V_149 , struct V_150 * V_151 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_124 , V_23 ;
bool V_152 = false ;
if ( V_146 && ! V_147 )
return - V_42 ;
if ( ! V_8 -> V_153 . V_154 ) {
V_8 -> V_153 . V_154 = F_21 ( sizeof( * V_8 -> V_153 . V_154 ) ,
V_155 ) ;
if ( ! V_8 -> V_153 . V_154 )
return - V_156 ;
for ( V_23 = 0 ; V_23 < 6 ; V_23 ++ )
V_8 -> V_153 . V_154 -> V_151 [ V_23 ] . V_157 =
V_8 -> V_153 . V_154 -> V_50 [ V_23 ] ;
}
if ( V_8 -> V_43 != V_37 &&
V_8 -> V_43 != V_35 )
return - V_16 ;
if ( V_151 -> V_158 == V_159 ) {
if ( ! V_8 -> V_160 )
return - V_161 ;
if ( ! V_29 -> V_128 -> V_162 )
return - V_16 ;
if ( V_149 < 4 || V_149 > 5 )
return - V_42 ;
} else if ( V_149 < 0 || V_149 > 3 )
return - V_42 ;
if ( remove ) {
V_124 = 0 ;
if ( V_8 -> V_160 ) {
if ( V_149 == V_8 -> V_153 . V_163 &&
V_8 -> V_43 == V_37 ) {
F_22 ( V_29 , V_8 -> V_164 , true ) ;
V_152 = true ;
}
if ( ! V_146 && V_147 &&
! ( V_29 -> V_17 . V_105 & V_165 ) )
V_124 = - V_166 ;
else
V_124 = V_29 -> V_128 -> V_167 ( & V_29 -> V_17 , V_2 , V_149 ,
V_146 , V_147 ) ;
}
V_8 -> V_153 . V_168 . V_169 = false ;
if ( V_124 == - V_166 )
V_124 = 0 ;
if ( ! V_124 ) {
if ( ! V_147 ) {
V_8 -> V_153 . V_154 -> V_151 [ V_149 ] . V_170 = 0 ;
V_8 -> V_153 . V_154 -> V_151 [ V_149 ] . V_158 = 0 ;
}
if ( V_149 == V_8 -> V_153 . V_163 )
V_8 -> V_153 . V_163 = - 1 ;
else if ( V_149 == V_8 -> V_153 . V_171 )
V_8 -> V_153 . V_171 = - 1 ;
}
if ( ! V_124 && V_152 )
V_124 = F_23 ( V_29 , V_8 ) ;
return V_124 ;
}
if ( V_147 )
V_148 = false ;
if ( F_24 ( V_29 , V_151 , V_149 , V_146 , V_147 ) )
return - V_42 ;
V_124 = 0 ;
if ( V_8 -> V_160 )
V_124 = V_29 -> V_128 -> V_172 ( & V_29 -> V_17 , V_2 , V_149 ,
V_146 , V_147 , V_151 ) ;
if ( V_124 )
return V_124 ;
if ( ! V_147 ) {
V_8 -> V_153 . V_154 -> V_151 [ V_149 ] = * V_151 ;
memcpy ( V_8 -> V_153 . V_154 -> V_50 [ V_149 ] ,
V_151 -> V_157 , V_151 -> V_170 ) ;
V_8 -> V_153 . V_154 -> V_151 [ V_149 ] . V_157 =
V_8 -> V_153 . V_154 -> V_50 [ V_149 ] ;
}
if ( ( V_151 -> V_158 == V_93 ||
V_151 -> V_158 == V_97 ) &&
( V_148 || ( ! V_147 && V_8 -> V_153 . V_163 == - 1 ) ) ) {
if ( V_8 -> V_160 ) {
if ( V_8 -> V_43 == V_37 &&
V_8 -> V_153 . V_163 == - 1 ) {
F_22 ( V_29 , V_8 -> V_164 , true ) ;
V_152 = true ;
}
V_124 = V_29 -> V_128 -> V_173 ( & V_29 -> V_17 , V_2 ,
V_149 , true , true ) ;
}
if ( ! V_124 ) {
V_8 -> V_153 . V_163 = V_149 ;
if ( V_152 )
V_124 = F_23 ( V_29 , V_8 ) ;
}
return V_124 ;
}
if ( V_151 -> V_158 == V_159 &&
( V_148 || ( ! V_147 && V_8 -> V_153 . V_171 == - 1 ) ) ) {
if ( V_8 -> V_160 )
V_124 = V_29 -> V_128 -> V_162 ( & V_29 -> V_17 ,
V_2 , V_149 ) ;
if ( ! V_124 )
V_8 -> V_153 . V_171 = V_149 ;
return V_124 ;
}
return 0 ;
}
static int F_25 ( struct V_28 * V_29 ,
struct V_1 * V_2 , bool V_146 ,
const T_2 * V_147 , bool remove , bool V_148 ,
int V_149 , struct V_150 * V_151 )
{
int V_124 ;
F_26 ( & V_29 -> V_174 ) ;
F_27 ( V_2 -> V_9 ) ;
V_124 = F_20 ( V_29 , V_2 , V_146 , V_147 ,
remove , V_148 , V_149 , V_151 ) ;
F_28 ( V_2 -> V_9 ) ;
F_29 ( & V_29 -> V_174 ) ;
return V_124 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_175 , char * V_176 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
int V_149 , V_124 ;
bool remove = false ;
struct V_150 V_151 ;
if ( V_8 -> V_43 != V_35 &&
V_8 -> V_43 != V_37 )
return - V_16 ;
if ( ! V_29 -> V_128 -> V_167 ||
! V_29 -> V_128 -> V_172 ||
! V_29 -> V_128 -> V_173 )
return - V_16 ;
V_149 = V_175 -> V_105 & V_177 ;
if ( V_149 == 0 ) {
V_149 = V_8 -> V_153 . V_163 ;
if ( V_149 < 0 )
V_149 = 0 ;
} else if ( V_149 < 1 || V_149 > 4 )
return - V_42 ;
else
V_149 -- ;
if ( V_175 -> V_105 & V_178 )
remove = true ;
else if ( V_175 -> V_56 == 0 ) {
V_124 = 0 ;
F_27 ( V_8 ) ;
if ( V_8 -> V_160 )
V_124 = V_29 -> V_128 -> V_173 ( & V_29 -> V_17 , V_2 ,
V_149 , true , true ) ;
if ( ! V_124 )
V_8 -> V_153 . V_163 = V_149 ;
F_28 ( V_8 ) ;
return V_124 ;
}
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . V_157 = V_176 ;
V_151 . V_170 = V_175 -> V_56 ;
if ( V_175 -> V_56 == 5 )
V_151 . V_158 = V_93 ;
else if ( V_175 -> V_56 == 13 )
V_151 . V_158 = V_97 ;
else if ( ! remove )
return - V_42 ;
return F_25 ( V_29 , V_2 , false , NULL , remove ,
V_8 -> V_153 . V_163 == - 1 ,
V_149 , & V_151 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_175 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
struct V_179 * V_180 = (struct V_179 * ) V_6 ;
const T_2 * V_147 ;
int V_149 ;
bool remove = false ;
struct V_150 V_151 ;
T_1 V_158 ;
if ( V_8 -> V_43 != V_35 &&
V_8 -> V_43 != V_37 )
return - V_16 ;
if ( ! V_29 -> V_128 -> V_167 ||
! V_29 -> V_128 -> V_172 ||
! V_29 -> V_128 -> V_173 )
return - V_16 ;
switch ( V_180 -> V_181 ) {
case V_182 :
remove = true ;
V_158 = 0 ;
break;
case V_183 :
if ( V_180 -> V_170 == 5 )
V_158 = V_93 ;
else if ( V_180 -> V_170 == 13 )
V_158 = V_97 ;
else
return - V_42 ;
break;
case V_184 :
V_158 = V_86 ;
break;
case V_185 :
V_158 = V_90 ;
break;
case V_186 :
V_158 = V_159 ;
break;
default:
return - V_16 ;
}
if ( V_175 -> V_105 & V_178 )
remove = true ;
V_149 = V_175 -> V_105 & V_177 ;
if ( V_158 == V_159 ) {
if ( V_149 < 4 || V_149 > 5 ) {
V_149 = V_8 -> V_153 . V_171 ;
if ( V_149 < 0 )
return - V_42 ;
} else
V_149 -- ;
} else {
if ( V_149 < 1 || V_149 > 4 ) {
V_149 = V_8 -> V_153 . V_163 ;
if ( V_149 < 0 )
return - V_42 ;
} else
V_149 -- ;
}
V_147 = V_180 -> V_147 . V_187 ;
if ( F_32 ( V_147 ) )
V_147 = NULL ;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . V_157 = V_180 -> V_157 ;
V_151 . V_170 = V_180 -> V_170 ;
V_151 . V_158 = V_158 ;
if ( V_180 -> V_188 & V_189 ) {
V_151 . V_190 = V_180 -> V_191 ;
V_151 . V_192 = 6 ;
}
return F_25 (
V_29 , V_2 ,
! ( V_180 -> V_188 & V_193 ) ,
V_147 , remove ,
V_180 -> V_188 & V_194 ,
V_149 , & V_151 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_175 , char * V_176 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_149 ;
if ( V_8 -> V_43 != V_35 &&
V_8 -> V_43 != V_37 )
return - V_16 ;
V_149 = V_175 -> V_105 & V_177 ;
if ( V_149 == 0 ) {
V_149 = V_8 -> V_153 . V_163 ;
if ( V_149 < 0 )
V_149 = 0 ;
} else if ( V_149 < 1 || V_149 > 4 )
return - V_42 ;
else
V_149 -- ;
V_175 -> V_105 = V_149 + 1 ;
if ( ! V_8 -> V_153 . V_154 || ! V_8 -> V_153 . V_154 -> V_151 [ V_149 ] . V_158 ) {
V_175 -> V_105 |= V_178 ;
V_175 -> V_56 = 0 ;
return 0 ;
}
V_175 -> V_56 = F_34 ( V_195 , V_175 -> V_56 ,
V_8 -> V_153 . V_154 -> V_151 [ V_149 ] . V_170 ) ;
memcpy ( V_176 , V_8 -> V_153 . V_154 -> V_151 [ V_149 ] . V_157 , V_175 -> V_56 ) ;
V_175 -> V_105 |= V_196 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_119 * V_197 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
int V_107 , V_124 ;
switch ( V_8 -> V_43 ) {
case V_35 :
return F_36 ( V_2 , V_4 , V_197 , V_6 ) ;
case V_37 :
return F_37 ( V_2 , V_4 , V_197 , V_6 ) ;
case V_41 :
case V_39 :
case V_198 :
V_107 = F_12 ( V_8 -> V_17 , V_197 ) ;
if ( V_107 < 0 )
return V_107 ;
if ( V_107 == 0 )
return - V_42 ;
F_26 ( & V_29 -> V_174 ) ;
F_27 ( V_8 ) ;
V_124 = F_38 ( V_29 , V_8 , V_107 , V_199 ) ;
F_28 ( V_8 ) ;
F_29 ( & V_29 -> V_174 ) ;
return V_124 ;
default:
return - V_16 ;
}
}
static int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_119 * V_107 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
struct V_102 * V_103 ;
switch ( V_8 -> V_43 ) {
case V_35 :
return F_40 ( V_2 , V_4 , V_107 , V_6 ) ;
case V_37 :
return F_41 ( V_2 , V_4 , V_107 , V_6 ) ;
case V_41 :
if ( ! V_29 -> V_128 -> V_200 )
return - V_42 ;
V_103 = V_29 -> V_128 -> V_200 ( V_8 -> V_17 ) ;
if ( ! V_103 )
return - V_42 ;
V_107 -> V_109 = V_103 -> V_108 ;
V_107 -> V_110 = 6 ;
return 0 ;
default:
if ( ! V_8 -> V_201 )
return - V_42 ;
V_107 -> V_109 = V_8 -> V_201 -> V_108 ;
V_107 -> V_110 = 6 ;
return 0 ;
}
}
static int F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_202 * V_50 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
enum V_203 type ;
int V_204 = 0 ;
if ( ( V_50 -> V_205 . V_105 & V_206 ) != V_207 )
return - V_42 ;
if ( V_50 -> V_205 . V_105 & V_208 )
return - V_42 ;
if ( ! V_29 -> V_128 -> V_209 )
return - V_16 ;
if ( ! V_50 -> V_205 . V_125 ) {
F_43 ( V_29 -> V_210 , false ) ;
if ( V_50 -> V_205 . V_126 ) {
if ( V_50 -> V_205 . V_127 < 0 )
return - V_42 ;
V_204 = V_50 -> V_205 . V_127 ;
type = V_211 ;
} else {
if ( V_50 -> V_205 . V_127 < 0 ) {
type = V_212 ;
} else {
V_204 = V_50 -> V_205 . V_127 ;
type = V_213 ;
}
}
} else {
F_43 ( V_29 -> V_210 , true ) ;
F_44 ( & V_29 -> V_214 ) ;
return 0 ;
}
return V_29 -> V_128 -> V_209 ( V_8 -> V_17 , type , F_45 ( V_204 ) ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_202 * V_50 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
int V_124 , V_215 ;
if ( ( V_50 -> V_205 . V_105 & V_206 ) != V_207 )
return - V_42 ;
if ( V_50 -> V_205 . V_105 & V_208 )
return - V_42 ;
if ( ! V_29 -> V_128 -> V_216 )
return - V_16 ;
V_124 = V_29 -> V_128 -> V_216 ( V_8 -> V_17 , & V_215 ) ;
if ( V_124 )
return V_124 ;
V_50 -> V_205 . V_126 = 1 ;
V_50 -> V_205 . V_125 = F_47 ( V_29 -> V_210 ) ;
V_50 -> V_205 . V_127 = V_215 ;
V_50 -> V_205 . V_105 = V_207 ;
return 0 ;
}
static int F_48 ( struct V_7 * V_8 ,
T_3 V_217 )
{
int V_218 = 0 ;
if ( ! V_217 )
return - V_42 ;
if ( V_217 & ~ ( V_219 |
V_220 |
V_221 ) )
return - V_42 ;
if ( V_217 & V_219 ) {
V_218 ++ ;
V_8 -> V_153 . V_168 . V_222 = V_223 ;
}
if ( V_217 & V_220 ) {
V_218 ++ ;
V_8 -> V_153 . V_168 . V_222 = V_224 ;
}
if ( V_217 & V_221 ) {
V_218 ++ ;
V_8 -> V_153 . V_168 . V_222 = V_225 ;
}
if ( V_218 > 1 )
V_8 -> V_153 . V_168 . V_222 = V_226 ;
return 0 ;
}
static int F_49 ( struct V_7 * V_8 , T_1 V_227 )
{
if ( V_227 & ~ ( V_228 |
V_229 |
V_230 ) )
return - V_42 ;
if ( ( V_227 & V_230 ) &&
( V_227 & ( V_228 |
V_229 ) ) )
return - V_42 ;
if ( V_227 & V_230 )
V_8 -> V_153 . V_168 . V_231 . V_227 &=
~ ( V_232 | V_233 ) ;
if ( V_227 & V_228 )
V_8 -> V_153 . V_168 . V_231 . V_227 |=
V_232 ;
if ( V_227 & V_229 )
V_8 -> V_153 . V_168 . V_231 . V_227 |=
V_233 ;
return 0 ;
}
static int F_50 ( struct V_7 * V_8 , T_1 V_158 )
{
if ( V_158 & V_234 )
V_8 -> V_153 . V_168 . V_231 . V_235 =
V_93 ;
else if ( V_158 & V_236 )
V_8 -> V_153 . V_168 . V_231 . V_235 =
V_97 ;
else if ( V_158 & V_237 )
V_8 -> V_153 . V_168 . V_231 . V_235 =
V_86 ;
else if ( V_158 & V_238 )
V_8 -> V_153 . V_168 . V_231 . V_235 =
V_90 ;
else if ( V_158 & V_239 )
V_8 -> V_153 . V_168 . V_231 . V_235 =
V_159 ;
else if ( V_158 & V_240 )
V_8 -> V_153 . V_168 . V_231 . V_235 = 0 ;
else
return - V_42 ;
return 0 ;
}
static int F_51 ( struct V_7 * V_8 , T_1 V_158 )
{
int V_241 = 0 ;
T_1 * V_242 = V_8 -> V_153 . V_168 . V_231 . V_242 ;
if ( V_158 & V_234 ) {
V_242 [ V_241 ] = V_93 ;
V_241 ++ ;
}
if ( V_158 & V_236 ) {
V_242 [ V_241 ] = V_97 ;
V_241 ++ ;
}
if ( V_158 & V_237 ) {
V_242 [ V_241 ] = V_86 ;
V_241 ++ ;
}
if ( V_158 & V_238 ) {
V_242 [ V_241 ] = V_90 ;
V_241 ++ ;
}
if ( V_158 & V_239 ) {
V_242 [ V_241 ] = V_159 ;
V_241 ++ ;
}
F_52 ( V_243 < 5 ) ;
V_8 -> V_153 . V_168 . V_231 . V_244 = V_241 ;
return 0 ;
}
static int F_53 ( struct V_7 * V_8 , T_1 V_245 )
{
int V_246 = 0 ;
if ( V_245 & ~ ( V_247 |
V_248 ) )
return - V_42 ;
if ( V_245 & V_247 ) {
V_8 -> V_153 . V_168 . V_231 . V_249 [ V_246 ] =
V_250 ;
V_246 ++ ;
}
if ( V_245 & V_248 ) {
V_8 -> V_153 . V_168 . V_231 . V_249 [ V_246 ] =
V_251 ;
V_246 ++ ;
}
V_8 -> V_153 . V_168 . V_231 . V_252 = V_246 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_50 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_8 -> V_43 != V_35 )
return - V_16 ;
switch ( V_50 -> V_105 & V_253 ) {
case V_254 :
V_8 -> V_153 . V_168 . V_169 = V_50 -> V_127 ;
return 0 ;
case V_255 :
return F_49 ( V_8 , V_50 -> V_127 ) ;
case V_256 :
return F_50 ( V_8 , V_50 -> V_127 ) ;
case V_257 :
return F_53 ( V_8 , V_50 -> V_127 ) ;
case V_258 :
return F_51 ( V_8 , V_50 -> V_127 ) ;
case V_259 :
return F_48 ( V_8 , V_50 -> V_127 ) ;
case V_260 :
case V_261 :
case V_262 :
case V_263 :
return 0 ;
default:
return - V_16 ;
}
}
static int F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_50 , char * V_6 )
{
return - V_16 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_264 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
bool V_265 = V_8 -> V_265 ;
int V_266 = V_8 -> V_267 ;
int V_124 ;
if ( V_8 -> V_43 != V_35 )
return - V_42 ;
if ( ! V_29 -> V_128 -> V_268 )
return - V_16 ;
if ( V_264 -> V_125 ) {
V_265 = false ;
} else {
switch ( V_264 -> V_105 & V_269 ) {
case V_270 :
case V_269 :
case V_271 :
V_265 = true ;
break;
default:
return - V_42 ;
}
if ( V_264 -> V_105 & ~ ( V_269 | V_272 ) )
return - V_42 ;
if ( V_264 -> V_105 & V_272 )
V_266 = V_264 -> V_127 / 1000 ;
}
V_124 = V_29 -> V_128 -> V_268 ( V_8 -> V_17 , V_2 , V_265 , V_266 ) ;
if ( V_124 )
return V_124 ;
V_8 -> V_265 = V_265 ;
V_8 -> V_267 = V_266 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_264 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_264 -> V_125 = ! V_8 -> V_265 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_273 * V_147 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
int V_124 ;
if ( F_59 ( V_8 -> V_43 != V_39 ) )
return - V_42 ;
if ( V_147 -> V_274 != V_275 )
return - V_42 ;
if ( F_60 ( V_2 ) )
return - V_276 ;
if ( ! V_29 -> V_128 -> V_277 )
return - V_16 ;
V_124 = V_29 -> V_128 -> V_277 ( V_8 -> V_17 , V_2 , ( T_2 * ) & V_147 -> V_187 ) ;
if ( V_124 )
return V_124 ;
memcpy ( & V_8 -> V_153 . V_278 , ( T_2 * ) & V_147 -> V_187 , V_279 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_273 * V_147 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( F_59 ( V_8 -> V_43 != V_39 ) )
return - V_42 ;
V_147 -> V_274 = V_275 ;
memcpy ( & V_147 -> V_187 , V_8 -> V_153 . V_278 , V_279 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_280 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
struct V_281 V_282 ;
T_1 V_126 , V_283 ;
struct V_10 * V_11 ;
int V_54 , V_284 ;
bool V_285 = false ;
if ( ! V_29 -> V_128 -> V_286 )
return - V_16 ;
memset ( & V_282 , 0 , sizeof( V_282 ) ) ;
V_126 = 0 ;
V_283 = ( T_1 ) - 1 ;
if ( V_280 -> V_127 < 0 ) {
} else if ( V_280 -> V_126 ) {
V_126 = V_280 -> V_127 / 100000 ;
} else {
V_283 = V_280 -> V_127 / 100000 ;
}
for ( V_54 = 0 ; V_54 < V_99 ; V_54 ++ ) {
V_11 = V_8 -> V_17 -> V_18 [ V_54 ] ;
if ( V_11 == NULL )
continue;
for ( V_284 = 0 ; V_284 < V_11 -> V_24 ; V_284 ++ ) {
struct V_287 * V_288 = & V_11 -> V_25 [ V_284 ] ;
if ( V_126 == V_288 -> V_26 ) {
V_282 . V_289 [ V_54 ] . V_290 = 1 << V_284 ;
V_285 = true ;
break;
}
if ( V_288 -> V_26 <= V_283 ) {
V_282 . V_289 [ V_54 ] . V_290 |= 1 << V_284 ;
V_285 = true ;
}
}
}
if ( ! V_285 )
return - V_42 ;
return V_29 -> V_128 -> V_286 ( V_8 -> V_17 , V_2 , NULL , & V_282 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_280 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
static struct V_291 V_292 ;
T_2 V_147 [ V_279 ] ;
int V_124 ;
if ( V_8 -> V_43 != V_35 )
return - V_16 ;
if ( ! V_29 -> V_128 -> V_293 )
return - V_16 ;
V_124 = 0 ;
F_27 ( V_8 ) ;
if ( V_8 -> V_160 )
memcpy ( V_147 , V_8 -> V_160 -> V_294 . V_278 , V_279 ) ;
else
V_124 = - V_16 ;
F_28 ( V_8 ) ;
if ( V_124 )
return V_124 ;
V_124 = V_29 -> V_128 -> V_293 ( & V_29 -> V_17 , V_2 , V_147 , & V_292 ) ;
if ( V_124 )
return V_124 ;
if ( ! ( V_292 . V_295 & V_296 ) )
return - V_16 ;
V_280 -> V_127 = 100000 * F_64 ( & V_292 . V_297 ) ;
return 0 ;
}
static struct V_298 * F_65 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
static struct V_298 V_299 ;
static struct V_291 V_292 ;
T_2 V_278 [ V_279 ] ;
if ( V_2 -> V_9 -> V_43 != V_35 )
return NULL ;
if ( ! V_29 -> V_128 -> V_293 )
return NULL ;
F_27 ( V_8 ) ;
if ( ! V_8 -> V_160 ) {
F_28 ( V_8 ) ;
return NULL ;
}
memcpy ( V_278 , V_8 -> V_160 -> V_294 . V_278 , V_279 ) ;
F_28 ( V_8 ) ;
if ( V_29 -> V_128 -> V_293 ( & V_29 -> V_17 , V_2 , V_278 , & V_292 ) )
return NULL ;
memset ( & V_299 , 0 , sizeof( V_299 ) ) ;
switch ( V_29 -> V_17 . V_73 ) {
case V_75 :
if ( V_292 . V_295 & V_300 ) {
int V_301 = V_292 . signal ;
V_299 . V_77 . V_71 |= V_81 ;
V_299 . V_77 . V_71 |= V_80 ;
V_299 . V_77 . V_71 |= V_79 ;
V_299 . V_77 . V_76 = V_301 ;
if ( V_301 < - 110 )
V_301 = - 110 ;
else if ( V_301 > - 40 )
V_301 = - 40 ;
V_299 . V_77 . V_77 = V_301 + 110 ;
break;
}
case V_82 :
if ( V_292 . V_295 & V_300 ) {
V_299 . V_77 . V_71 |= V_81 ;
V_299 . V_77 . V_71 |= V_80 ;
V_299 . V_77 . V_76 = V_292 . signal ;
V_299 . V_77 . V_77 = V_292 . signal ;
break;
}
default:
V_299 . V_77 . V_71 |= V_302 ;
V_299 . V_77 . V_71 |= V_303 ;
}
V_299 . V_77 . V_71 |= V_72 ;
if ( V_292 . V_295 & V_304 )
V_299 . V_305 . V_306 = V_292 . V_307 ;
if ( V_292 . V_295 & V_308 )
V_299 . V_305 . V_309 = V_292 . V_310 ;
return & V_299 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_273 * V_311 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
switch ( V_8 -> V_43 ) {
case V_37 :
return F_67 ( V_2 , V_4 , V_311 , V_6 ) ;
case V_35 :
return F_68 ( V_2 , V_4 , V_311 , V_6 ) ;
case V_39 :
return F_58 ( V_2 , V_4 , V_311 , V_6 ) ;
default:
return - V_16 ;
}
}
static int F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_273 * V_311 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
switch ( V_8 -> V_43 ) {
case V_37 :
return F_70 ( V_2 , V_4 , V_311 , V_6 ) ;
case V_35 :
return F_71 ( V_2 , V_4 , V_311 , V_6 ) ;
case V_39 :
return F_61 ( V_2 , V_4 , V_311 , V_6 ) ;
default:
return - V_16 ;
}
}
static int F_72 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_50 , char * V_312 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
switch ( V_8 -> V_43 ) {
case V_37 :
return F_73 ( V_2 , V_4 , V_50 , V_312 ) ;
case V_35 :
return F_74 ( V_2 , V_4 , V_50 , V_312 ) ;
default:
return - V_16 ;
}
}
static int F_75 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_50 , char * V_312 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_50 -> V_105 = 0 ;
V_50 -> V_56 = 0 ;
switch ( V_8 -> V_43 ) {
case V_37 :
return F_76 ( V_2 , V_4 , V_50 , V_312 ) ;
case V_35 :
return F_77 ( V_2 , V_4 , V_50 , V_312 ) ;
default:
return - V_16 ;
}
}
static int F_78 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_50 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
struct V_313 V_314 ;
struct V_315 * V_316 = (struct V_315 * ) V_6 ;
memset ( & V_314 , 0 , sizeof( struct V_313 ) ) ;
if ( V_8 -> V_43 != V_35 )
return - V_42 ;
V_314 . V_278 = V_316 -> V_278 . V_187 ;
V_314 . V_317 = V_316 -> V_317 ;
switch ( V_316 -> V_318 ) {
case V_319 :
if ( ! V_29 -> V_128 -> V_320 )
return - V_16 ;
return V_29 -> V_128 -> V_320 ( & V_29 -> V_17 , V_2 , & V_314 ) ;
case V_321 :
if ( ! V_29 -> V_128 -> V_322 )
return - V_16 ;
return V_29 -> V_128 -> V_322 ( & V_29 -> V_17 , V_2 , & V_314 ) ;
case V_323 :
if ( ! V_29 -> V_128 -> V_324 )
return - V_16 ;
return V_29 -> V_128 -> V_324 ( & V_29 -> V_17 , V_2 ) ;
default:
return - V_16 ;
}
}
