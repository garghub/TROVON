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
V_29 = F_3 ( V_8 -> V_17 ) ;
switch ( * V_27 ) {
case V_33 :
type = V_34 ;
break;
case V_35 :
type = V_36 ;
break;
case V_37 :
type = V_38 ;
break;
case V_39 :
type = V_40 ;
break;
default:
return - V_41 ;
}
if ( type == V_8 -> V_42 )
return 0 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
return F_4 ( V_29 , V_2 , type , NULL , & V_31 ) ;
}
int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_27 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( ! V_8 )
return - V_16 ;
switch ( V_8 -> V_42 ) {
case V_43 :
* V_27 = V_44 ;
break;
case V_34 :
* V_27 = V_33 ;
break;
case V_36 :
* V_27 = V_35 ;
break;
case V_40 :
* V_27 = V_39 ;
break;
case V_38 :
* V_27 = V_37 ;
break;
case V_45 :
* V_27 = V_46 ;
break;
default:
* V_27 = V_47 ;
break;
}
return 0 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_48 * V_49 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_50 * V_51 = (struct V_50 * ) V_6 ;
enum V_52 V_53 ;
int V_23 , V_54 = 0 ;
if ( ! V_8 )
return - V_16 ;
V_49 -> V_55 = sizeof( struct V_50 ) ;
memset ( V_51 , 0 , sizeof( struct V_50 ) ) ;
V_51 -> V_56 = V_57 ;
V_51 -> V_58 = 21 ;
V_51 -> V_59 = V_60 ;
V_51 -> V_61 = V_60 ;
V_51 -> V_62 = 0 ;
V_51 -> V_63 = 255 ;
V_51 -> V_64 = 0 ;
V_51 -> V_65 = 2347 ;
V_51 -> V_66 = 256 ;
V_51 -> V_67 = 2346 ;
V_51 -> V_68 = 4 ;
V_51 -> V_69 . V_70 = V_71 ;
switch ( V_8 -> V_17 -> V_72 ) {
case V_73 :
break;
case V_74 :
V_51 -> V_69 . V_75 = ( V_76 ) - 110 ;
V_51 -> V_69 . V_77 = 70 ;
V_51 -> V_78 . V_77 = 35 ;
V_51 -> V_69 . V_70 |= V_79 ;
V_51 -> V_69 . V_70 |= V_80 ;
V_51 -> V_69 . V_70 |= V_81 ;
break;
case V_82 :
V_51 -> V_69 . V_75 = 100 ;
V_51 -> V_69 . V_77 = 100 ;
V_51 -> V_78 . V_77 = 50 ;
V_51 -> V_69 . V_70 |= V_80 ;
V_51 -> V_69 . V_70 |= V_81 ;
break;
}
V_51 -> V_78 . V_75 = V_51 -> V_69 . V_75 / 2 ;
V_51 -> V_78 . V_83 = V_51 -> V_69 . V_83 / 2 ;
V_51 -> V_78 . V_70 = V_51 -> V_69 . V_70 ;
for ( V_23 = 0 ; V_23 < V_8 -> V_17 -> V_84 ; V_23 ++ ) {
switch ( V_8 -> V_17 -> V_85 [ V_23 ] ) {
case V_86 :
V_51 -> V_87 |= ( V_88 |
V_89 ) ;
break;
case V_90 :
V_51 -> V_87 |= ( V_91 |
V_92 ) ;
break;
case V_93 :
V_51 -> V_94 [ V_51 -> V_95 ++ ] =
V_96 ;
break;
case V_97 :
V_51 -> V_94 [ V_51 -> V_95 ++ ] =
V_98 ;
break;
}
}
for ( V_53 = 0 ; V_53 < V_99 ; V_53 ++ ) {
struct V_10 * V_11 ;
V_11 = V_8 -> V_17 -> V_18 [ V_53 ] ;
if ( ! V_11 )
continue;
for ( V_23 = 0 ; V_23 < V_11 -> V_100 && V_54 < V_101 ; V_23 ++ ) {
struct V_102 * V_103 = & V_11 -> V_104 [ V_23 ] ;
if ( ! ( V_103 -> V_105 & V_106 ) ) {
V_51 -> V_107 [ V_54 ] . V_23 =
F_7 (
V_103 -> V_108 ) ;
V_51 -> V_107 [ V_54 ] . V_109 = V_103 -> V_108 ;
V_51 -> V_107 [ V_54 ] . V_110 = 6 ;
V_54 ++ ;
}
}
}
V_51 -> V_111 = V_54 ;
V_51 -> V_112 = V_54 ;
F_8 ( V_51 -> V_113 ) ;
F_9 ( V_51 -> V_113 , V_114 ) ;
F_9 ( V_51 -> V_113 , V_115 ) ;
if ( V_8 -> V_17 -> V_116 > 0 )
V_51 -> V_117 |= V_118 ;
return 0 ;
}
int F_10 ( struct V_119 * V_107 )
{
if ( V_107 -> V_110 == 0 ) {
enum V_52 V_53 = V_22 ;
if ( V_107 -> V_109 < 0 )
return 0 ;
if ( V_107 -> V_109 > 14 )
V_53 = V_19 ;
return F_11 ( V_107 -> V_109 , V_53 ) ;
} else {
int V_23 , div = 1000000 ;
for ( V_23 = 0 ; V_23 < V_107 -> V_110 ; V_23 ++ )
div /= 10 ;
if ( div <= 0 )
return - V_41 ;
return V_107 -> V_109 / div ;
}
}
int F_12 ( struct V_1 * V_2 ,
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
return - V_41 ;
else
V_8 -> V_17 -> V_123 = V_121 -> V_127 ;
V_124 = F_13 ( V_29 , V_128 ) ;
if ( V_124 )
V_8 -> V_17 -> V_123 = V_122 ;
return V_124 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_121 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_121 -> V_127 = V_8 -> V_17 -> V_123 ;
V_121 -> V_125 = V_121 -> V_127 == ( T_1 ) - 1 ;
V_121 -> V_126 = 1 ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_129 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
T_1 V_130 = V_8 -> V_17 -> V_131 ;
int V_124 ;
if ( V_129 -> V_125 || ! V_129 -> V_126 )
V_8 -> V_17 -> V_131 = ( T_1 ) - 1 ;
else if ( V_129 -> V_127 < 256 )
return - V_41 ;
else {
V_8 -> V_17 -> V_131 = V_129 -> V_127 & ~ 0x1 ;
}
V_124 = F_13 ( V_29 , V_132 ) ;
if ( V_124 )
V_8 -> V_17 -> V_131 = V_130 ;
return V_124 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_129 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_129 -> V_127 = V_8 -> V_17 -> V_131 ;
V_129 -> V_125 = V_129 -> V_127 == ( T_1 ) - 1 ;
V_129 -> V_126 = 1 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_133 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
T_1 V_134 = 0 ;
V_76 V_135 = V_8 -> V_17 -> V_136 ;
V_76 V_137 = V_8 -> V_17 -> V_138 ;
int V_124 ;
if ( V_133 -> V_125 || V_133 -> V_127 < 1 || V_133 -> V_127 > 255 ||
( V_133 -> V_105 & V_139 ) != V_60 )
return - V_41 ;
if ( V_133 -> V_105 & V_140 ) {
V_8 -> V_17 -> V_136 = V_133 -> V_127 ;
V_134 |= V_141 ;
} else if ( V_133 -> V_105 & V_142 ) {
V_8 -> V_17 -> V_138 = V_133 -> V_127 ;
V_134 |= V_143 ;
} else {
V_8 -> V_17 -> V_138 = V_133 -> V_127 ;
V_8 -> V_17 -> V_136 = V_133 -> V_127 ;
V_134 |= V_141 ;
V_134 |= V_143 ;
}
if ( ! V_134 )
return 0 ;
V_124 = F_13 ( V_29 , V_134 ) ;
if ( V_124 ) {
V_8 -> V_17 -> V_138 = V_137 ;
V_8 -> V_17 -> V_136 = V_135 ;
}
return V_124 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_133 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_133 -> V_125 = 0 ;
if ( V_133 -> V_105 == 0 || ( V_133 -> V_105 & V_142 ) ) {
V_133 -> V_105 |= V_60 | V_142 ;
V_133 -> V_127 = V_8 -> V_17 -> V_138 ;
if ( V_8 -> V_17 -> V_136 == V_8 -> V_17 -> V_138 )
V_133 -> V_105 |= V_140 ;
return 0 ;
}
if ( V_133 -> V_105 & V_140 ) {
V_133 -> V_105 = V_60 | V_140 ;
V_133 -> V_127 = V_8 -> V_17 -> V_136 ;
}
return 0 ;
}
static int F_19 ( struct V_28 * V_29 ,
struct V_1 * V_2 , bool V_144 ,
const V_76 * V_145 , bool remove , bool V_146 ,
int V_147 , struct V_148 * V_149 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_124 , V_23 ;
bool V_150 = false ;
if ( V_144 && ! V_145 )
return - V_41 ;
if ( ! V_8 -> V_151 . V_152 ) {
V_8 -> V_151 . V_152 = F_20 ( sizeof( * V_8 -> V_151 . V_152 ) ,
V_153 ) ;
if ( ! V_8 -> V_151 . V_152 )
return - V_154 ;
for ( V_23 = 0 ; V_23 < 6 ; V_23 ++ )
V_8 -> V_151 . V_152 -> V_149 [ V_23 ] . V_155 =
V_8 -> V_151 . V_152 -> V_49 [ V_23 ] ;
}
if ( V_8 -> V_42 != V_36 &&
V_8 -> V_42 != V_34 )
return - V_16 ;
if ( V_149 -> V_156 == V_157 ) {
if ( ! V_8 -> V_158 )
return - V_159 ;
if ( ! V_29 -> V_160 -> V_161 )
return - V_16 ;
if ( V_147 < 4 || V_147 > 5 )
return - V_41 ;
} else if ( V_147 < 0 || V_147 > 3 )
return - V_41 ;
if ( remove ) {
V_124 = 0 ;
if ( V_8 -> V_158 ) {
if ( V_147 == V_8 -> V_151 . V_162 &&
V_8 -> V_42 == V_36 ) {
F_21 ( V_29 , V_8 -> V_163 , true ) ;
V_150 = true ;
}
if ( ! V_144 && V_145 &&
! ( V_29 -> V_17 . V_105 & V_164 ) )
V_124 = - V_165 ;
else
V_124 = F_22 ( V_29 , V_2 , V_147 , V_144 ,
V_145 ) ;
}
V_8 -> V_151 . V_166 . V_167 = false ;
if ( V_124 == - V_165 )
V_124 = 0 ;
if ( ! V_124 ) {
if ( ! V_145 ) {
memset ( V_8 -> V_151 . V_152 -> V_49 [ V_147 ] , 0 ,
sizeof( V_8 -> V_151 . V_152 -> V_49 [ V_147 ] ) ) ;
V_8 -> V_151 . V_152 -> V_149 [ V_147 ] . V_168 = 0 ;
V_8 -> V_151 . V_152 -> V_149 [ V_147 ] . V_156 = 0 ;
}
if ( V_147 == V_8 -> V_151 . V_162 )
V_8 -> V_151 . V_162 = - 1 ;
else if ( V_147 == V_8 -> V_151 . V_169 )
V_8 -> V_151 . V_169 = - 1 ;
}
if ( ! V_124 && V_150 )
V_124 = F_23 ( V_29 , V_8 ) ;
return V_124 ;
}
if ( V_145 )
V_146 = false ;
if ( F_24 ( V_29 , V_149 , V_147 , V_144 , V_145 ) )
return - V_41 ;
V_124 = 0 ;
if ( V_8 -> V_158 )
V_124 = F_25 ( V_29 , V_2 , V_147 , V_144 , V_145 , V_149 ) ;
if ( V_124 )
return V_124 ;
if ( ! V_145 ) {
V_8 -> V_151 . V_152 -> V_149 [ V_147 ] = * V_149 ;
memcpy ( V_8 -> V_151 . V_152 -> V_49 [ V_147 ] ,
V_149 -> V_155 , V_149 -> V_168 ) ;
V_8 -> V_151 . V_152 -> V_149 [ V_147 ] . V_155 =
V_8 -> V_151 . V_152 -> V_49 [ V_147 ] ;
}
if ( ( V_149 -> V_156 == V_93 ||
V_149 -> V_156 == V_97 ) &&
( V_146 || ( ! V_145 && V_8 -> V_151 . V_162 == - 1 ) ) ) {
if ( V_8 -> V_158 ) {
if ( V_8 -> V_42 == V_36 &&
V_8 -> V_151 . V_162 == - 1 ) {
F_21 ( V_29 , V_8 -> V_163 , true ) ;
V_150 = true ;
}
V_124 = F_26 ( V_29 , V_2 , V_147 , true , true ) ;
}
if ( ! V_124 ) {
V_8 -> V_151 . V_162 = V_147 ;
if ( V_150 )
V_124 = F_23 ( V_29 , V_8 ) ;
}
return V_124 ;
}
if ( V_149 -> V_156 == V_157 &&
( V_146 || ( ! V_145 && V_8 -> V_151 . V_169 == - 1 ) ) ) {
if ( V_8 -> V_158 )
V_124 = F_27 ( V_29 , V_2 , V_147 ) ;
if ( ! V_124 )
V_8 -> V_151 . V_169 = V_147 ;
return V_124 ;
}
return 0 ;
}
static int F_28 ( struct V_28 * V_29 ,
struct V_1 * V_2 , bool V_144 ,
const V_76 * V_145 , bool remove , bool V_146 ,
int V_147 , struct V_148 * V_149 )
{
int V_124 ;
F_29 ( V_2 -> V_9 ) ;
V_124 = F_19 ( V_29 , V_2 , V_144 , V_145 ,
remove , V_146 , V_147 , V_149 ) ;
F_30 ( V_2 -> V_9 ) ;
return V_124 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_48 * V_170 , char * V_171 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
int V_147 , V_124 ;
bool remove = false ;
struct V_148 V_149 ;
if ( V_8 -> V_42 != V_34 &&
V_8 -> V_42 != V_36 )
return - V_16 ;
if ( ! V_29 -> V_160 -> V_172 ||
! V_29 -> V_160 -> V_173 ||
! V_29 -> V_160 -> V_174 )
return - V_16 ;
V_147 = V_170 -> V_105 & V_175 ;
if ( V_147 == 0 ) {
V_147 = V_8 -> V_151 . V_162 ;
if ( V_147 < 0 )
V_147 = 0 ;
} else if ( V_147 < 1 || V_147 > 4 )
return - V_41 ;
else
V_147 -- ;
if ( V_170 -> V_105 & V_176 )
remove = true ;
else if ( V_170 -> V_55 == 0 ) {
V_124 = 0 ;
F_29 ( V_8 ) ;
if ( V_8 -> V_158 )
V_124 = F_26 ( V_29 , V_2 , V_147 , true ,
true ) ;
if ( ! V_124 )
V_8 -> V_151 . V_162 = V_147 ;
F_30 ( V_8 ) ;
return V_124 ;
}
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
V_149 . V_155 = V_171 ;
V_149 . V_168 = V_170 -> V_55 ;
if ( V_170 -> V_55 == 5 )
V_149 . V_156 = V_93 ;
else if ( V_170 -> V_55 == 13 )
V_149 . V_156 = V_97 ;
else if ( ! remove )
return - V_41 ;
return F_28 ( V_29 , V_2 , false , NULL , remove ,
V_8 -> V_151 . V_162 == - 1 ,
V_147 , & V_149 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_48 * V_170 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
struct V_177 * V_178 = (struct V_177 * ) V_6 ;
const V_76 * V_145 ;
int V_147 ;
bool remove = false ;
struct V_148 V_149 ;
T_1 V_156 ;
if ( V_8 -> V_42 != V_34 &&
V_8 -> V_42 != V_36 )
return - V_16 ;
if ( ! V_29 -> V_160 -> V_172 ||
! V_29 -> V_160 -> V_173 ||
! V_29 -> V_160 -> V_174 )
return - V_16 ;
switch ( V_178 -> V_179 ) {
case V_180 :
remove = true ;
V_156 = 0 ;
break;
case V_181 :
if ( V_178 -> V_168 == 5 )
V_156 = V_93 ;
else if ( V_178 -> V_168 == 13 )
V_156 = V_97 ;
else
return - V_41 ;
break;
case V_182 :
V_156 = V_86 ;
break;
case V_183 :
V_156 = V_90 ;
break;
case V_184 :
V_156 = V_157 ;
break;
default:
return - V_16 ;
}
if ( V_170 -> V_105 & V_176 )
remove = true ;
V_147 = V_170 -> V_105 & V_175 ;
if ( V_156 == V_157 ) {
if ( V_147 < 4 || V_147 > 5 ) {
V_147 = V_8 -> V_151 . V_169 ;
if ( V_147 < 0 )
return - V_41 ;
} else
V_147 -- ;
} else {
if ( V_147 < 1 || V_147 > 4 ) {
V_147 = V_8 -> V_151 . V_162 ;
if ( V_147 < 0 )
return - V_41 ;
} else
V_147 -- ;
}
V_145 = V_178 -> V_145 . V_185 ;
if ( F_33 ( V_145 ) )
V_145 = NULL ;
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
V_149 . V_155 = V_178 -> V_155 ;
V_149 . V_168 = V_178 -> V_168 ;
V_149 . V_156 = V_156 ;
if ( V_178 -> V_186 & V_187 ) {
V_149 . V_188 = V_178 -> V_189 ;
V_149 . V_190 = 6 ;
}
return F_28 (
V_29 , V_2 ,
! ( V_178 -> V_186 & V_191 ) ,
V_145 , remove ,
V_178 -> V_186 & V_192 ,
V_147 , & V_149 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_48 * V_170 , char * V_171 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_147 ;
if ( V_8 -> V_42 != V_34 &&
V_8 -> V_42 != V_36 )
return - V_16 ;
V_147 = V_170 -> V_105 & V_175 ;
if ( V_147 == 0 ) {
V_147 = V_8 -> V_151 . V_162 ;
if ( V_147 < 0 )
V_147 = 0 ;
} else if ( V_147 < 1 || V_147 > 4 )
return - V_41 ;
else
V_147 -- ;
V_170 -> V_105 = V_147 + 1 ;
if ( ! V_8 -> V_151 . V_152 || ! V_8 -> V_151 . V_152 -> V_149 [ V_147 ] . V_156 ) {
V_170 -> V_105 |= V_176 ;
V_170 -> V_55 = 0 ;
return 0 ;
}
V_170 -> V_55 = F_35 ( V_193 , V_170 -> V_55 ,
V_8 -> V_151 . V_152 -> V_149 [ V_147 ] . V_168 ) ;
memcpy ( V_171 , V_8 -> V_151 . V_152 -> V_149 [ V_147 ] . V_155 , V_170 -> V_55 ) ;
V_170 -> V_105 |= V_194 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_119 * V_195 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
struct V_196 V_197 = {
. V_198 = V_199 ,
} ;
int V_107 ;
switch ( V_8 -> V_42 ) {
case V_34 :
return F_37 ( V_2 , V_4 , V_195 , V_6 ) ;
case V_36 :
return F_38 ( V_2 , V_4 , V_195 , V_6 ) ;
case V_40 :
V_107 = F_10 ( V_195 ) ;
if ( V_107 < 0 )
return V_107 ;
if ( V_107 == 0 )
return - V_41 ;
V_197 . V_200 = V_107 ;
V_197 . V_103 = F_39 ( & V_29 -> V_17 , V_107 ) ;
if ( ! V_197 . V_103 )
return - V_41 ;
return F_40 ( V_29 , & V_197 ) ;
case V_201 :
V_107 = F_10 ( V_195 ) ;
if ( V_107 < 0 )
return V_107 ;
if ( V_107 == 0 )
return - V_41 ;
V_197 . V_200 = V_107 ;
V_197 . V_103 = F_39 ( & V_29 -> V_17 , V_107 ) ;
if ( ! V_197 . V_103 )
return - V_41 ;
return F_41 ( V_29 , V_8 , & V_197 ) ;
default:
return - V_16 ;
}
}
static int F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_119 * V_107 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
struct V_196 V_197 ;
int V_202 ;
switch ( V_8 -> V_42 ) {
case V_34 :
return F_43 ( V_2 , V_4 , V_107 , V_6 ) ;
case V_36 :
return F_44 ( V_2 , V_4 , V_107 , V_6 ) ;
case V_40 :
if ( ! V_29 -> V_160 -> V_203 )
return - V_41 ;
V_202 = F_45 ( V_29 , V_8 , & V_197 ) ;
if ( V_202 )
return V_202 ;
V_107 -> V_109 = V_197 . V_103 -> V_108 ;
V_107 -> V_110 = 6 ;
return 0 ;
default:
return - V_41 ;
}
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_204 * V_49 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
enum V_205 type ;
int V_206 = 0 ;
if ( ( V_49 -> V_207 . V_105 & V_208 ) != V_209 )
return - V_41 ;
if ( V_49 -> V_207 . V_105 & V_210 )
return - V_41 ;
if ( ! V_29 -> V_160 -> V_211 )
return - V_16 ;
if ( ! V_49 -> V_207 . V_125 ) {
F_47 ( V_29 -> V_212 , false ) ;
if ( V_49 -> V_207 . V_126 ) {
if ( V_49 -> V_207 . V_127 < 0 )
return - V_41 ;
V_206 = V_49 -> V_207 . V_127 ;
type = V_213 ;
} else {
if ( V_49 -> V_207 . V_127 < 0 ) {
type = V_214 ;
} else {
V_206 = V_49 -> V_207 . V_127 ;
type = V_215 ;
}
}
} else {
F_47 ( V_29 -> V_212 , true ) ;
F_48 ( & V_29 -> V_216 ) ;
return 0 ;
}
return F_49 ( V_29 , V_8 , type , F_50 ( V_206 ) ) ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_204 * V_49 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
int V_124 , V_217 ;
if ( ( V_49 -> V_207 . V_105 & V_208 ) != V_209 )
return - V_41 ;
if ( V_49 -> V_207 . V_105 & V_210 )
return - V_41 ;
if ( ! V_29 -> V_160 -> V_218 )
return - V_16 ;
V_124 = F_52 ( V_29 , V_8 , & V_217 ) ;
if ( V_124 )
return V_124 ;
V_49 -> V_207 . V_126 = 1 ;
V_49 -> V_207 . V_125 = F_53 ( V_29 -> V_212 ) ;
V_49 -> V_207 . V_127 = V_217 ;
V_49 -> V_207 . V_105 = V_209 ;
return 0 ;
}
static int F_54 ( struct V_7 * V_8 ,
T_2 V_219 )
{
int V_220 = 0 ;
if ( ! V_219 )
return - V_41 ;
if ( V_219 & ~ ( V_221 |
V_222 |
V_223 ) )
return - V_41 ;
if ( V_219 & V_221 ) {
V_220 ++ ;
V_8 -> V_151 . V_166 . V_224 = V_225 ;
}
if ( V_219 & V_222 ) {
V_220 ++ ;
V_8 -> V_151 . V_166 . V_224 = V_226 ;
}
if ( V_219 & V_223 ) {
V_220 ++ ;
V_8 -> V_151 . V_166 . V_224 = V_227 ;
}
if ( V_220 > 1 )
V_8 -> V_151 . V_166 . V_224 = V_228 ;
return 0 ;
}
static int F_55 ( struct V_7 * V_8 , T_1 V_229 )
{
if ( V_229 & ~ ( V_230 |
V_231 |
V_232 ) )
return - V_41 ;
if ( ( V_229 & V_232 ) &&
( V_229 & ( V_230 |
V_231 ) ) )
return - V_41 ;
if ( V_229 & V_232 )
V_8 -> V_151 . V_166 . V_233 . V_229 &=
~ ( V_234 | V_235 ) ;
if ( V_229 & V_230 )
V_8 -> V_151 . V_166 . V_233 . V_229 |=
V_234 ;
if ( V_229 & V_231 )
V_8 -> V_151 . V_166 . V_233 . V_229 |=
V_235 ;
return 0 ;
}
static int F_56 ( struct V_7 * V_8 , T_1 V_156 )
{
if ( V_156 & V_236 )
V_8 -> V_151 . V_166 . V_233 . V_237 =
V_93 ;
else if ( V_156 & V_238 )
V_8 -> V_151 . V_166 . V_233 . V_237 =
V_97 ;
else if ( V_156 & V_239 )
V_8 -> V_151 . V_166 . V_233 . V_237 =
V_86 ;
else if ( V_156 & V_240 )
V_8 -> V_151 . V_166 . V_233 . V_237 =
V_90 ;
else if ( V_156 & V_241 )
V_8 -> V_151 . V_166 . V_233 . V_237 =
V_157 ;
else if ( V_156 & V_242 )
V_8 -> V_151 . V_166 . V_233 . V_237 = 0 ;
else
return - V_41 ;
return 0 ;
}
static int F_57 ( struct V_7 * V_8 , T_1 V_156 )
{
int V_243 = 0 ;
T_1 * V_244 = V_8 -> V_151 . V_166 . V_233 . V_244 ;
if ( V_156 & V_236 ) {
V_244 [ V_243 ] = V_93 ;
V_243 ++ ;
}
if ( V_156 & V_238 ) {
V_244 [ V_243 ] = V_97 ;
V_243 ++ ;
}
if ( V_156 & V_239 ) {
V_244 [ V_243 ] = V_86 ;
V_243 ++ ;
}
if ( V_156 & V_240 ) {
V_244 [ V_243 ] = V_90 ;
V_243 ++ ;
}
if ( V_156 & V_241 ) {
V_244 [ V_243 ] = V_157 ;
V_243 ++ ;
}
F_58 ( V_245 < 5 ) ;
V_8 -> V_151 . V_166 . V_233 . V_246 = V_243 ;
return 0 ;
}
static int F_59 ( struct V_7 * V_8 , T_1 V_247 )
{
int V_248 = 0 ;
if ( V_247 & ~ ( V_249 |
V_250 ) )
return - V_41 ;
if ( V_247 & V_249 ) {
V_8 -> V_151 . V_166 . V_233 . V_251 [ V_248 ] =
V_252 ;
V_248 ++ ;
}
if ( V_247 & V_250 ) {
V_8 -> V_151 . V_166 . V_233 . V_251 [ V_248 ] =
V_253 ;
V_248 ++ ;
}
V_8 -> V_151 . V_166 . V_233 . V_254 = V_248 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_49 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_8 -> V_42 != V_34 )
return - V_16 ;
switch ( V_49 -> V_105 & V_255 ) {
case V_256 :
V_8 -> V_151 . V_166 . V_167 = V_49 -> V_127 ;
return 0 ;
case V_257 :
return F_55 ( V_8 , V_49 -> V_127 ) ;
case V_258 :
return F_56 ( V_8 , V_49 -> V_127 ) ;
case V_259 :
return F_59 ( V_8 , V_49 -> V_127 ) ;
case V_260 :
return F_57 ( V_8 , V_49 -> V_127 ) ;
case V_261 :
return F_54 ( V_8 , V_49 -> V_127 ) ;
case V_262 :
case V_263 :
case V_264 :
case V_265 :
return 0 ;
default:
return - V_16 ;
}
}
static int F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_49 , char * V_6 )
{
return - V_16 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_266 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
bool V_267 = V_8 -> V_267 ;
int V_268 = V_8 -> V_269 ;
int V_124 ;
if ( V_8 -> V_42 != V_34 )
return - V_41 ;
if ( ! V_29 -> V_160 -> V_270 )
return - V_16 ;
if ( V_266 -> V_125 ) {
V_267 = false ;
} else {
switch ( V_266 -> V_105 & V_271 ) {
case V_272 :
case V_271 :
case V_273 :
V_267 = true ;
break;
default:
return - V_41 ;
}
if ( V_266 -> V_105 & ~ ( V_271 | V_274 ) )
return - V_41 ;
if ( V_266 -> V_105 & V_274 )
V_268 = V_266 -> V_127 / 1000 ;
}
V_124 = F_63 ( V_29 , V_2 , V_267 , V_268 ) ;
if ( V_124 )
return V_124 ;
V_8 -> V_267 = V_267 ;
V_8 -> V_269 = V_268 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_266 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_266 -> V_125 = ! V_8 -> V_267 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_275 * V_145 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
int V_124 ;
if ( F_66 ( V_8 -> V_42 != V_38 ) )
return - V_41 ;
if ( V_145 -> V_276 != V_277 )
return - V_41 ;
if ( F_67 ( V_2 ) )
return - V_278 ;
if ( ! V_29 -> V_160 -> V_279 )
return - V_16 ;
V_124 = F_68 ( V_29 , V_2 , ( V_76 * ) & V_145 -> V_185 ) ;
if ( V_124 )
return V_124 ;
memcpy ( & V_8 -> V_151 . V_280 , ( V_76 * ) & V_145 -> V_185 , V_281 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_275 * V_145 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( F_66 ( V_8 -> V_42 != V_38 ) )
return - V_41 ;
V_145 -> V_276 = V_277 ;
memcpy ( & V_145 -> V_185 , V_8 -> V_151 . V_280 , V_281 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_282 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
struct V_283 V_284 ;
T_1 V_126 , V_285 ;
struct V_10 * V_11 ;
int V_53 , V_286 ;
bool V_287 = false ;
if ( ! V_29 -> V_160 -> V_288 )
return - V_16 ;
memset ( & V_284 , 0 , sizeof( V_284 ) ) ;
V_126 = 0 ;
V_285 = ( T_1 ) - 1 ;
if ( V_282 -> V_127 < 0 ) {
} else if ( V_282 -> V_126 ) {
V_126 = V_282 -> V_127 / 100000 ;
} else {
V_285 = V_282 -> V_127 / 100000 ;
}
for ( V_53 = 0 ; V_53 < V_99 ; V_53 ++ ) {
V_11 = V_8 -> V_17 -> V_18 [ V_53 ] ;
if ( V_11 == NULL )
continue;
for ( V_286 = 0 ; V_286 < V_11 -> V_24 ; V_286 ++ ) {
struct V_289 * V_290 = & V_11 -> V_25 [ V_286 ] ;
if ( V_126 == V_290 -> V_26 ) {
V_284 . V_291 [ V_53 ] . V_292 = 1 << V_286 ;
V_287 = true ;
break;
}
if ( V_290 -> V_26 <= V_285 ) {
V_284 . V_291 [ V_53 ] . V_292 |= 1 << V_286 ;
V_287 = true ;
}
}
}
if ( ! V_287 )
return - V_41 ;
return F_71 ( V_29 , V_2 , NULL , & V_284 ) ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_282 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
static struct V_293 V_294 ;
V_76 V_145 [ V_281 ] ;
int V_124 ;
if ( V_8 -> V_42 != V_34 )
return - V_16 ;
if ( ! V_29 -> V_160 -> V_295 )
return - V_16 ;
V_124 = 0 ;
F_29 ( V_8 ) ;
if ( V_8 -> V_158 )
memcpy ( V_145 , V_8 -> V_158 -> V_296 . V_280 , V_281 ) ;
else
V_124 = - V_16 ;
F_30 ( V_8 ) ;
if ( V_124 )
return V_124 ;
V_124 = F_73 ( V_29 , V_2 , V_145 , & V_294 ) ;
if ( V_124 )
return V_124 ;
if ( ! ( V_294 . V_297 & F_74 ( V_298 ) ) )
return - V_16 ;
V_282 -> V_127 = 100000 * F_75 ( & V_294 . V_299 ) ;
return 0 ;
}
static struct V_300 * F_76 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
static struct V_300 V_301 ;
static struct V_293 V_294 ;
V_76 V_280 [ V_281 ] ;
if ( V_2 -> V_9 -> V_42 != V_34 )
return NULL ;
if ( ! V_29 -> V_160 -> V_295 )
return NULL ;
F_29 ( V_8 ) ;
if ( ! V_8 -> V_158 ) {
F_30 ( V_8 ) ;
return NULL ;
}
memcpy ( V_280 , V_8 -> V_158 -> V_296 . V_280 , V_281 ) ;
F_30 ( V_8 ) ;
if ( F_73 ( V_29 , V_2 , V_280 , & V_294 ) )
return NULL ;
memset ( & V_301 , 0 , sizeof( V_301 ) ) ;
switch ( V_29 -> V_17 . V_72 ) {
case V_74 :
if ( V_294 . V_297 & F_74 ( V_302 ) ) {
int V_303 = V_294 . signal ;
V_301 . V_77 . V_70 |= V_81 ;
V_301 . V_77 . V_70 |= V_80 ;
V_301 . V_77 . V_70 |= V_79 ;
V_301 . V_77 . V_75 = V_303 ;
if ( V_303 < - 110 )
V_303 = - 110 ;
else if ( V_303 > - 40 )
V_303 = - 40 ;
V_301 . V_77 . V_77 = V_303 + 110 ;
break;
}
case V_82 :
if ( V_294 . V_297 & F_74 ( V_302 ) ) {
V_301 . V_77 . V_70 |= V_81 ;
V_301 . V_77 . V_70 |= V_80 ;
V_301 . V_77 . V_75 = V_294 . signal ;
V_301 . V_77 . V_77 = V_294 . signal ;
break;
}
default:
V_301 . V_77 . V_70 |= V_304 ;
V_301 . V_77 . V_70 |= V_305 ;
}
V_301 . V_77 . V_70 |= V_71 ;
if ( V_294 . V_297 & F_74 ( V_306 ) )
V_301 . V_307 . V_308 = V_294 . V_309 ;
if ( V_294 . V_297 & F_74 ( V_310 ) )
V_301 . V_307 . V_311 = V_294 . V_312 ;
return & V_301 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_275 * V_313 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
switch ( V_8 -> V_42 ) {
case V_36 :
return F_78 ( V_2 , V_4 , V_313 , V_6 ) ;
case V_34 :
return F_79 ( V_2 , V_4 , V_313 , V_6 ) ;
case V_38 :
return F_65 ( V_2 , V_4 , V_313 , V_6 ) ;
default:
return - V_16 ;
}
}
static int F_80 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_275 * V_313 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
switch ( V_8 -> V_42 ) {
case V_36 :
return F_81 ( V_2 , V_4 , V_313 , V_6 ) ;
case V_34 :
return F_82 ( V_2 , V_4 , V_313 , V_6 ) ;
case V_38 :
return F_69 ( V_2 , V_4 , V_313 , V_6 ) ;
default:
return - V_16 ;
}
}
static int F_83 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_48 * V_49 , char * V_314 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
switch ( V_8 -> V_42 ) {
case V_36 :
return F_84 ( V_2 , V_4 , V_49 , V_314 ) ;
case V_34 :
return F_85 ( V_2 , V_4 , V_49 , V_314 ) ;
default:
return - V_16 ;
}
}
static int F_86 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_48 * V_49 , char * V_314 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_49 -> V_105 = 0 ;
V_49 -> V_55 = 0 ;
switch ( V_8 -> V_42 ) {
case V_36 :
return F_87 ( V_2 , V_4 , V_49 , V_314 ) ;
case V_34 :
return F_88 ( V_2 , V_4 , V_49 , V_314 ) ;
default:
return - V_16 ;
}
}
static int F_89 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_48 * V_49 , char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = F_3 ( V_8 -> V_17 ) ;
struct V_315 V_316 ;
struct V_317 * V_318 = (struct V_317 * ) V_6 ;
memset ( & V_316 , 0 , sizeof( struct V_315 ) ) ;
if ( V_8 -> V_42 != V_34 )
return - V_41 ;
V_316 . V_280 = V_318 -> V_280 . V_185 ;
V_316 . V_319 = V_318 -> V_319 ;
switch ( V_318 -> V_320 ) {
case V_321 :
if ( ! V_29 -> V_160 -> V_322 )
return - V_16 ;
return F_90 ( V_29 , V_2 , & V_316 ) ;
case V_323 :
if ( ! V_29 -> V_160 -> V_324 )
return - V_16 ;
return F_91 ( V_29 , V_2 , & V_316 ) ;
case V_325 :
if ( ! V_29 -> V_160 -> V_326 )
return - V_16 ;
return F_92 ( V_29 , V_2 ) ;
default:
return - V_16 ;
}
}
