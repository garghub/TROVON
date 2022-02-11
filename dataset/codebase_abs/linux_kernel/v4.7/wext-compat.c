int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 , char * V_6 )
{
strcpy ( V_5 , L_1 ) ;
return 0 ;
}
int F_2 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_7 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 ;
struct V_13 V_14 ;
enum V_15 type ;
V_12 = F_3 ( V_9 -> V_16 ) ;
switch ( * V_7 ) {
case V_17 :
type = V_18 ;
break;
case V_19 :
type = V_20 ;
break;
case V_21 :
type = V_22 ;
break;
case V_23 :
type = V_24 ;
break;
default:
return - V_25 ;
}
if ( type == V_9 -> V_26 )
return 0 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
return F_4 ( V_12 , V_2 , type , NULL , & V_14 ) ;
}
int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_7 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( ! V_9 )
return - V_27 ;
switch ( V_9 -> V_26 ) {
case V_28 :
* V_7 = V_29 ;
break;
case V_18 :
* V_7 = V_17 ;
break;
case V_20 :
* V_7 = V_19 ;
break;
case V_24 :
* V_7 = V_23 ;
break;
case V_22 :
* V_7 = V_21 ;
break;
case V_30 :
* V_7 = V_31 ;
break;
default:
* V_7 = V_32 ;
break;
}
return 0 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_34 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_35 * V_36 = (struct V_35 * ) V_6 ;
enum V_37 V_38 ;
int V_39 , V_40 = 0 ;
if ( ! V_9 )
return - V_27 ;
V_34 -> V_41 = sizeof( struct V_35 ) ;
memset ( V_36 , 0 , sizeof( struct V_35 ) ) ;
V_36 -> V_42 = V_43 ;
V_36 -> V_44 = 21 ;
V_36 -> V_45 = V_46 ;
V_36 -> V_47 = V_46 ;
V_36 -> V_48 = 0 ;
V_36 -> V_49 = 255 ;
V_36 -> V_50 = 0 ;
V_36 -> V_51 = 2347 ;
V_36 -> V_52 = 256 ;
V_36 -> V_53 = 2346 ;
V_36 -> V_54 = 4 ;
V_36 -> V_55 . V_56 = V_57 ;
switch ( V_9 -> V_16 -> V_58 ) {
case V_59 :
break;
case V_60 :
V_36 -> V_55 . V_61 = ( V_62 ) - 110 ;
V_36 -> V_55 . V_63 = 70 ;
V_36 -> V_64 . V_63 = 35 ;
V_36 -> V_55 . V_56 |= V_65 ;
V_36 -> V_55 . V_56 |= V_66 ;
V_36 -> V_55 . V_56 |= V_67 ;
break;
case V_68 :
V_36 -> V_55 . V_61 = 100 ;
V_36 -> V_55 . V_63 = 100 ;
V_36 -> V_64 . V_63 = 50 ;
V_36 -> V_55 . V_56 |= V_66 ;
V_36 -> V_55 . V_56 |= V_67 ;
break;
}
V_36 -> V_64 . V_61 = V_36 -> V_55 . V_61 / 2 ;
V_36 -> V_64 . V_69 = V_36 -> V_55 . V_69 / 2 ;
V_36 -> V_64 . V_56 = V_36 -> V_55 . V_56 ;
for ( V_39 = 0 ; V_39 < V_9 -> V_16 -> V_70 ; V_39 ++ ) {
switch ( V_9 -> V_16 -> V_71 [ V_39 ] ) {
case V_72 :
V_36 -> V_73 |= ( V_74 |
V_75 ) ;
break;
case V_76 :
V_36 -> V_73 |= ( V_77 |
V_78 ) ;
break;
case V_79 :
V_36 -> V_80 [ V_36 -> V_81 ++ ] =
V_82 ;
break;
case V_83 :
V_36 -> V_80 [ V_36 -> V_81 ++ ] =
V_84 ;
break;
}
}
for ( V_38 = 0 ; V_38 < V_85 ; V_38 ++ ) {
struct V_86 * V_87 ;
V_87 = V_9 -> V_16 -> V_88 [ V_38 ] ;
if ( ! V_87 )
continue;
for ( V_39 = 0 ; V_39 < V_87 -> V_89 && V_40 < V_90 ; V_39 ++ ) {
struct V_91 * V_92 = & V_87 -> V_93 [ V_39 ] ;
if ( ! ( V_92 -> V_94 & V_95 ) ) {
V_36 -> V_96 [ V_40 ] . V_39 =
F_7 (
V_92 -> V_97 ) ;
V_36 -> V_96 [ V_40 ] . V_98 = V_92 -> V_97 ;
V_36 -> V_96 [ V_40 ] . V_99 = 6 ;
V_40 ++ ;
}
}
}
V_36 -> V_100 = V_40 ;
V_36 -> V_101 = V_40 ;
F_8 ( V_36 -> V_102 ) ;
F_9 ( V_36 -> V_102 , V_103 ) ;
F_9 ( V_36 -> V_102 , V_104 ) ;
if ( V_9 -> V_16 -> V_105 > 0 )
V_36 -> V_106 |= V_107 ;
return 0 ;
}
int F_10 ( struct V_108 * V_96 )
{
if ( V_96 -> V_99 == 0 ) {
enum V_37 V_38 = V_109 ;
if ( V_96 -> V_98 < 0 )
return 0 ;
if ( V_96 -> V_98 > 14 )
V_38 = V_110 ;
return F_11 ( V_96 -> V_98 , V_38 ) ;
} else {
int V_39 , div = 1000000 ;
for ( V_39 = 0 ; V_39 < V_96 -> V_99 ; V_39 ++ )
div /= 10 ;
if ( div <= 0 )
return - V_25 ;
return V_96 -> V_98 / div ;
}
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_111 * V_112 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 -> V_16 ) ;
T_1 V_113 = V_9 -> V_16 -> V_114 ;
int V_115 ;
if ( V_112 -> V_116 || ! V_112 -> V_117 )
V_9 -> V_16 -> V_114 = ( T_1 ) - 1 ;
else if ( V_112 -> V_118 < 0 )
return - V_25 ;
else
V_9 -> V_16 -> V_114 = V_112 -> V_118 ;
V_115 = F_13 ( V_12 , V_119 ) ;
if ( V_115 )
V_9 -> V_16 -> V_114 = V_113 ;
return V_115 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_111 * V_112 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_112 -> V_118 = V_9 -> V_16 -> V_114 ;
V_112 -> V_116 = V_112 -> V_118 == ( T_1 ) - 1 ;
V_112 -> V_117 = 1 ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_111 * V_120 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 -> V_16 ) ;
T_1 V_121 = V_9 -> V_16 -> V_122 ;
int V_115 ;
if ( V_120 -> V_116 || ! V_120 -> V_117 )
V_9 -> V_16 -> V_122 = ( T_1 ) - 1 ;
else if ( V_120 -> V_118 < 256 )
return - V_25 ;
else {
V_9 -> V_16 -> V_122 = V_120 -> V_118 & ~ 0x1 ;
}
V_115 = F_13 ( V_12 , V_123 ) ;
if ( V_115 )
V_9 -> V_16 -> V_122 = V_121 ;
return V_115 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_111 * V_120 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_120 -> V_118 = V_9 -> V_16 -> V_122 ;
V_120 -> V_116 = V_120 -> V_118 == ( T_1 ) - 1 ;
V_120 -> V_117 = 1 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_111 * V_124 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 -> V_16 ) ;
T_1 V_125 = 0 ;
V_62 V_126 = V_9 -> V_16 -> V_127 ;
V_62 V_128 = V_9 -> V_16 -> V_129 ;
int V_115 ;
if ( V_124 -> V_116 || V_124 -> V_118 < 1 || V_124 -> V_118 > 255 ||
( V_124 -> V_94 & V_130 ) != V_46 )
return - V_25 ;
if ( V_124 -> V_94 & V_131 ) {
V_9 -> V_16 -> V_127 = V_124 -> V_118 ;
V_125 |= V_132 ;
} else if ( V_124 -> V_94 & V_133 ) {
V_9 -> V_16 -> V_129 = V_124 -> V_118 ;
V_125 |= V_134 ;
} else {
V_9 -> V_16 -> V_129 = V_124 -> V_118 ;
V_9 -> V_16 -> V_127 = V_124 -> V_118 ;
V_125 |= V_132 ;
V_125 |= V_134 ;
}
if ( ! V_125 )
return 0 ;
V_115 = F_13 ( V_12 , V_125 ) ;
if ( V_115 ) {
V_9 -> V_16 -> V_129 = V_128 ;
V_9 -> V_16 -> V_127 = V_126 ;
}
return V_115 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_111 * V_124 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_124 -> V_116 = 0 ;
if ( V_124 -> V_94 == 0 || ( V_124 -> V_94 & V_133 ) ) {
V_124 -> V_94 |= V_46 | V_133 ;
V_124 -> V_118 = V_9 -> V_16 -> V_129 ;
if ( V_9 -> V_16 -> V_127 == V_9 -> V_16 -> V_129 )
V_124 -> V_94 |= V_131 ;
return 0 ;
}
if ( V_124 -> V_94 & V_131 ) {
V_124 -> V_94 = V_46 | V_131 ;
V_124 -> V_118 = V_9 -> V_16 -> V_127 ;
}
return 0 ;
}
static int F_19 ( struct V_11 * V_12 ,
struct V_1 * V_2 , bool V_135 ,
const V_62 * V_136 , bool remove , bool V_137 ,
int V_138 , struct V_139 * V_140 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_115 , V_39 ;
bool V_141 = false ;
if ( V_135 && ! V_136 )
return - V_25 ;
if ( ! V_9 -> V_142 . V_143 ) {
V_9 -> V_142 . V_143 = F_20 ( sizeof( * V_9 -> V_142 . V_143 ) ,
V_144 ) ;
if ( ! V_9 -> V_142 . V_143 )
return - V_145 ;
for ( V_39 = 0 ; V_39 < 6 ; V_39 ++ )
V_9 -> V_142 . V_143 -> V_140 [ V_39 ] . V_146 =
V_9 -> V_142 . V_143 -> V_34 [ V_39 ] ;
}
if ( V_9 -> V_26 != V_20 &&
V_9 -> V_26 != V_18 )
return - V_27 ;
if ( V_140 -> V_147 == V_148 ) {
if ( ! V_9 -> V_149 )
return - V_150 ;
if ( ! V_12 -> V_151 -> V_152 )
return - V_27 ;
if ( V_138 < 4 || V_138 > 5 )
return - V_25 ;
} else if ( V_138 < 0 || V_138 > 3 )
return - V_25 ;
if ( remove ) {
V_115 = 0 ;
if ( V_9 -> V_149 ) {
if ( V_138 == V_9 -> V_142 . V_153 &&
V_9 -> V_26 == V_20 ) {
F_21 ( V_12 , V_9 -> V_154 , true ) ;
V_141 = true ;
}
if ( ! V_135 && V_136 &&
! ( V_12 -> V_16 . V_94 & V_155 ) )
V_115 = - V_156 ;
else
V_115 = F_22 ( V_12 , V_2 , V_138 , V_135 ,
V_136 ) ;
}
V_9 -> V_142 . V_157 . V_158 = false ;
if ( V_115 == - V_156 )
V_115 = 0 ;
if ( ! V_115 ) {
if ( ! V_136 ) {
memset ( V_9 -> V_142 . V_143 -> V_34 [ V_138 ] , 0 ,
sizeof( V_9 -> V_142 . V_143 -> V_34 [ V_138 ] ) ) ;
V_9 -> V_142 . V_143 -> V_140 [ V_138 ] . V_159 = 0 ;
V_9 -> V_142 . V_143 -> V_140 [ V_138 ] . V_147 = 0 ;
}
if ( V_138 == V_9 -> V_142 . V_153 )
V_9 -> V_142 . V_153 = - 1 ;
else if ( V_138 == V_9 -> V_142 . V_160 )
V_9 -> V_142 . V_160 = - 1 ;
}
if ( ! V_115 && V_141 )
V_115 = F_23 ( V_12 , V_9 ) ;
return V_115 ;
}
if ( V_136 )
V_137 = false ;
if ( F_24 ( V_12 , V_140 , V_138 , V_135 , V_136 ) )
return - V_25 ;
V_115 = 0 ;
if ( V_9 -> V_149 )
V_115 = F_25 ( V_12 , V_2 , V_138 , V_135 , V_136 , V_140 ) ;
if ( V_115 )
return V_115 ;
if ( ! V_136 ) {
V_9 -> V_142 . V_143 -> V_140 [ V_138 ] = * V_140 ;
memcpy ( V_9 -> V_142 . V_143 -> V_34 [ V_138 ] ,
V_140 -> V_146 , V_140 -> V_159 ) ;
V_9 -> V_142 . V_143 -> V_140 [ V_138 ] . V_146 =
V_9 -> V_142 . V_143 -> V_34 [ V_138 ] ;
}
if ( ( V_140 -> V_147 == V_79 ||
V_140 -> V_147 == V_83 ) &&
( V_137 || ( ! V_136 && V_9 -> V_142 . V_153 == - 1 ) ) ) {
if ( V_9 -> V_149 ) {
if ( V_9 -> V_26 == V_20 &&
V_9 -> V_142 . V_153 == - 1 ) {
F_21 ( V_12 , V_9 -> V_154 , true ) ;
V_141 = true ;
}
V_115 = F_26 ( V_12 , V_2 , V_138 , true , true ) ;
}
if ( ! V_115 ) {
V_9 -> V_142 . V_153 = V_138 ;
if ( V_141 )
V_115 = F_23 ( V_12 , V_9 ) ;
}
return V_115 ;
}
if ( V_140 -> V_147 == V_148 &&
( V_137 || ( ! V_136 && V_9 -> V_142 . V_160 == - 1 ) ) ) {
if ( V_9 -> V_149 )
V_115 = F_27 ( V_12 , V_2 , V_138 ) ;
if ( ! V_115 )
V_9 -> V_142 . V_160 = V_138 ;
return V_115 ;
}
return 0 ;
}
static int F_28 ( struct V_11 * V_12 ,
struct V_1 * V_2 , bool V_135 ,
const V_62 * V_136 , bool remove , bool V_137 ,
int V_138 , struct V_139 * V_140 )
{
int V_115 ;
F_29 ( V_2 -> V_10 ) ;
V_115 = F_19 ( V_12 , V_2 , V_135 , V_136 ,
remove , V_137 , V_138 , V_140 ) ;
F_30 ( V_2 -> V_10 ) ;
return V_115 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_161 , char * V_162 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 -> V_16 ) ;
int V_138 , V_115 ;
bool remove = false ;
struct V_139 V_140 ;
if ( V_9 -> V_26 != V_18 &&
V_9 -> V_26 != V_20 )
return - V_27 ;
if ( ! V_12 -> V_151 -> V_163 ||
! V_12 -> V_151 -> V_164 ||
! V_12 -> V_151 -> V_165 )
return - V_27 ;
V_138 = V_161 -> V_94 & V_166 ;
if ( V_138 == 0 ) {
V_138 = V_9 -> V_142 . V_153 ;
if ( V_138 < 0 )
V_138 = 0 ;
} else if ( V_138 < 1 || V_138 > 4 )
return - V_25 ;
else
V_138 -- ;
if ( V_161 -> V_94 & V_167 )
remove = true ;
else if ( V_161 -> V_41 == 0 ) {
V_115 = 0 ;
F_29 ( V_9 ) ;
if ( V_9 -> V_149 )
V_115 = F_26 ( V_12 , V_2 , V_138 , true ,
true ) ;
if ( ! V_115 )
V_9 -> V_142 . V_153 = V_138 ;
F_30 ( V_9 ) ;
return V_115 ;
}
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_146 = V_162 ;
V_140 . V_159 = V_161 -> V_41 ;
if ( V_161 -> V_41 == 5 )
V_140 . V_147 = V_79 ;
else if ( V_161 -> V_41 == 13 )
V_140 . V_147 = V_83 ;
else if ( ! remove )
return - V_25 ;
return F_28 ( V_12 , V_2 , false , NULL , remove ,
V_9 -> V_142 . V_153 == - 1 ,
V_138 , & V_140 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_161 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 -> V_16 ) ;
struct V_168 * V_169 = (struct V_168 * ) V_6 ;
const V_62 * V_136 ;
int V_138 ;
bool remove = false ;
struct V_139 V_140 ;
T_1 V_147 ;
if ( V_9 -> V_26 != V_18 &&
V_9 -> V_26 != V_20 )
return - V_27 ;
if ( ! V_12 -> V_151 -> V_163 ||
! V_12 -> V_151 -> V_164 ||
! V_12 -> V_151 -> V_165 )
return - V_27 ;
switch ( V_169 -> V_170 ) {
case V_171 :
remove = true ;
V_147 = 0 ;
break;
case V_172 :
if ( V_169 -> V_159 == 5 )
V_147 = V_79 ;
else if ( V_169 -> V_159 == 13 )
V_147 = V_83 ;
else
return - V_25 ;
break;
case V_173 :
V_147 = V_72 ;
break;
case V_174 :
V_147 = V_76 ;
break;
case V_175 :
V_147 = V_148 ;
break;
default:
return - V_27 ;
}
if ( V_161 -> V_94 & V_167 )
remove = true ;
V_138 = V_161 -> V_94 & V_166 ;
if ( V_147 == V_148 ) {
if ( V_138 < 4 || V_138 > 5 ) {
V_138 = V_9 -> V_142 . V_160 ;
if ( V_138 < 0 )
return - V_25 ;
} else
V_138 -- ;
} else {
if ( V_138 < 1 || V_138 > 4 ) {
V_138 = V_9 -> V_142 . V_153 ;
if ( V_138 < 0 )
return - V_25 ;
} else
V_138 -- ;
}
V_136 = V_169 -> V_136 . V_176 ;
if ( F_33 ( V_136 ) )
V_136 = NULL ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_146 = V_169 -> V_146 ;
V_140 . V_159 = V_169 -> V_159 ;
V_140 . V_147 = V_147 ;
if ( V_169 -> V_177 & V_178 ) {
V_140 . V_179 = V_169 -> V_180 ;
V_140 . V_181 = 6 ;
}
return F_28 (
V_12 , V_2 ,
! ( V_169 -> V_177 & V_182 ) ,
V_136 , remove ,
V_169 -> V_177 & V_183 ,
V_138 , & V_140 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_161 , char * V_162 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_138 ;
if ( V_9 -> V_26 != V_18 &&
V_9 -> V_26 != V_20 )
return - V_27 ;
V_138 = V_161 -> V_94 & V_166 ;
if ( V_138 == 0 ) {
V_138 = V_9 -> V_142 . V_153 ;
if ( V_138 < 0 )
V_138 = 0 ;
} else if ( V_138 < 1 || V_138 > 4 )
return - V_25 ;
else
V_138 -- ;
V_161 -> V_94 = V_138 + 1 ;
if ( ! V_9 -> V_142 . V_143 || ! V_9 -> V_142 . V_143 -> V_140 [ V_138 ] . V_147 ) {
V_161 -> V_94 |= V_167 ;
V_161 -> V_41 = 0 ;
return 0 ;
}
V_161 -> V_41 = F_35 ( V_184 , V_161 -> V_41 ,
V_9 -> V_142 . V_143 -> V_140 [ V_138 ] . V_159 ) ;
memcpy ( V_162 , V_9 -> V_142 . V_143 -> V_140 [ V_138 ] . V_146 , V_161 -> V_41 ) ;
V_161 -> V_94 |= V_185 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_108 * V_186 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 -> V_16 ) ;
struct V_187 V_188 = {
. V_189 = V_190 ,
} ;
int V_96 ;
switch ( V_9 -> V_26 ) {
case V_18 :
return F_37 ( V_2 , V_4 , V_186 , V_6 ) ;
case V_20 :
return F_38 ( V_2 , V_4 , V_186 , V_6 ) ;
case V_24 :
V_96 = F_10 ( V_186 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( V_96 == 0 )
return - V_25 ;
V_188 . V_191 = V_96 ;
V_188 . V_92 = F_39 ( & V_12 -> V_16 , V_96 ) ;
if ( ! V_188 . V_92 )
return - V_25 ;
return F_40 ( V_12 , & V_188 ) ;
case V_192 :
V_96 = F_10 ( V_186 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( V_96 == 0 )
return - V_25 ;
V_188 . V_191 = V_96 ;
V_188 . V_92 = F_39 ( & V_12 -> V_16 , V_96 ) ;
if ( ! V_188 . V_92 )
return - V_25 ;
return F_41 ( V_12 , V_9 , & V_188 ) ;
default:
return - V_27 ;
}
}
static int F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_108 * V_96 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 -> V_16 ) ;
struct V_187 V_188 ;
int V_193 ;
switch ( V_9 -> V_26 ) {
case V_18 :
return F_43 ( V_2 , V_4 , V_96 , V_6 ) ;
case V_20 :
return F_44 ( V_2 , V_4 , V_96 , V_6 ) ;
case V_24 :
if ( ! V_12 -> V_151 -> V_194 )
return - V_25 ;
V_193 = F_45 ( V_12 , V_9 , & V_188 ) ;
if ( V_193 )
return V_193 ;
V_96 -> V_98 = V_188 . V_92 -> V_97 ;
V_96 -> V_99 = 6 ;
return 0 ;
default:
return - V_25 ;
}
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_195 * V_34 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 -> V_16 ) ;
enum V_196 type ;
int V_197 = 0 ;
if ( ( V_34 -> V_198 . V_94 & V_199 ) != V_200 )
return - V_25 ;
if ( V_34 -> V_198 . V_94 & V_201 )
return - V_25 ;
if ( ! V_12 -> V_151 -> V_202 )
return - V_27 ;
if ( ! V_34 -> V_198 . V_116 ) {
F_47 ( V_12 -> V_203 , false ) ;
if ( V_34 -> V_198 . V_117 ) {
if ( V_34 -> V_198 . V_118 < 0 )
return - V_25 ;
V_197 = V_34 -> V_198 . V_118 ;
type = V_204 ;
} else {
if ( V_34 -> V_198 . V_118 < 0 ) {
type = V_205 ;
} else {
V_197 = V_34 -> V_198 . V_118 ;
type = V_206 ;
}
}
} else {
F_47 ( V_12 -> V_203 , true ) ;
F_48 ( & V_12 -> V_207 ) ;
return 0 ;
}
return F_49 ( V_12 , V_9 , type , F_50 ( V_197 ) ) ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_195 * V_34 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 -> V_16 ) ;
int V_115 , V_208 ;
if ( ( V_34 -> V_198 . V_94 & V_199 ) != V_200 )
return - V_25 ;
if ( V_34 -> V_198 . V_94 & V_201 )
return - V_25 ;
if ( ! V_12 -> V_151 -> V_209 )
return - V_27 ;
V_115 = F_52 ( V_12 , V_9 , & V_208 ) ;
if ( V_115 )
return V_115 ;
V_34 -> V_198 . V_117 = 1 ;
V_34 -> V_198 . V_116 = F_53 ( V_12 -> V_203 ) ;
V_34 -> V_198 . V_118 = V_208 ;
V_34 -> V_198 . V_94 = V_200 ;
return 0 ;
}
static int F_54 ( struct V_8 * V_9 ,
T_2 V_210 )
{
int V_211 = 0 ;
if ( ! V_210 )
return - V_25 ;
if ( V_210 & ~ ( V_212 |
V_213 |
V_214 ) )
return - V_25 ;
if ( V_210 & V_212 ) {
V_211 ++ ;
V_9 -> V_142 . V_157 . V_215 = V_216 ;
}
if ( V_210 & V_213 ) {
V_211 ++ ;
V_9 -> V_142 . V_157 . V_215 = V_217 ;
}
if ( V_210 & V_214 ) {
V_211 ++ ;
V_9 -> V_142 . V_157 . V_215 = V_218 ;
}
if ( V_211 > 1 )
V_9 -> V_142 . V_157 . V_215 = V_219 ;
return 0 ;
}
static int F_55 ( struct V_8 * V_9 , T_1 V_220 )
{
if ( V_220 & ~ ( V_221 |
V_222 |
V_223 ) )
return - V_25 ;
if ( ( V_220 & V_223 ) &&
( V_220 & ( V_221 |
V_222 ) ) )
return - V_25 ;
if ( V_220 & V_223 )
V_9 -> V_142 . V_157 . V_224 . V_220 &=
~ ( V_225 | V_226 ) ;
if ( V_220 & V_221 )
V_9 -> V_142 . V_157 . V_224 . V_220 |=
V_225 ;
if ( V_220 & V_222 )
V_9 -> V_142 . V_157 . V_224 . V_220 |=
V_226 ;
return 0 ;
}
static int F_56 ( struct V_8 * V_9 , T_1 V_147 )
{
if ( V_147 & V_227 )
V_9 -> V_142 . V_157 . V_224 . V_228 =
V_79 ;
else if ( V_147 & V_229 )
V_9 -> V_142 . V_157 . V_224 . V_228 =
V_83 ;
else if ( V_147 & V_230 )
V_9 -> V_142 . V_157 . V_224 . V_228 =
V_72 ;
else if ( V_147 & V_231 )
V_9 -> V_142 . V_157 . V_224 . V_228 =
V_76 ;
else if ( V_147 & V_232 )
V_9 -> V_142 . V_157 . V_224 . V_228 =
V_148 ;
else if ( V_147 & V_233 )
V_9 -> V_142 . V_157 . V_224 . V_228 = 0 ;
else
return - V_25 ;
return 0 ;
}
static int F_57 ( struct V_8 * V_9 , T_1 V_147 )
{
int V_234 = 0 ;
T_1 * V_235 = V_9 -> V_142 . V_157 . V_224 . V_235 ;
if ( V_147 & V_227 ) {
V_235 [ V_234 ] = V_79 ;
V_234 ++ ;
}
if ( V_147 & V_229 ) {
V_235 [ V_234 ] = V_83 ;
V_234 ++ ;
}
if ( V_147 & V_230 ) {
V_235 [ V_234 ] = V_72 ;
V_234 ++ ;
}
if ( V_147 & V_231 ) {
V_235 [ V_234 ] = V_76 ;
V_234 ++ ;
}
if ( V_147 & V_232 ) {
V_235 [ V_234 ] = V_148 ;
V_234 ++ ;
}
F_58 ( V_236 < 5 ) ;
V_9 -> V_142 . V_157 . V_224 . V_237 = V_234 ;
return 0 ;
}
static int F_59 ( struct V_8 * V_9 , T_1 V_238 )
{
int V_239 = 0 ;
if ( V_238 & ~ ( V_240 |
V_241 ) )
return - V_25 ;
if ( V_238 & V_240 ) {
V_9 -> V_142 . V_157 . V_224 . V_242 [ V_239 ] =
V_243 ;
V_239 ++ ;
}
if ( V_238 & V_241 ) {
V_9 -> V_142 . V_157 . V_224 . V_242 [ V_239 ] =
V_244 ;
V_239 ++ ;
}
V_9 -> V_142 . V_157 . V_224 . V_245 = V_239 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_111 * V_34 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 -> V_26 != V_18 )
return - V_27 ;
switch ( V_34 -> V_94 & V_246 ) {
case V_247 :
V_9 -> V_142 . V_157 . V_158 = V_34 -> V_118 ;
return 0 ;
case V_248 :
return F_55 ( V_9 , V_34 -> V_118 ) ;
case V_249 :
return F_56 ( V_9 , V_34 -> V_118 ) ;
case V_250 :
return F_59 ( V_9 , V_34 -> V_118 ) ;
case V_251 :
return F_57 ( V_9 , V_34 -> V_118 ) ;
case V_252 :
return F_54 ( V_9 , V_34 -> V_118 ) ;
case V_253 :
case V_254 :
case V_255 :
case V_256 :
return 0 ;
default:
return - V_27 ;
}
}
static int F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_111 * V_34 , char * V_6 )
{
return - V_27 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_111 * V_257 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 -> V_16 ) ;
bool V_258 = V_9 -> V_258 ;
int V_259 = V_9 -> V_260 ;
int V_115 ;
if ( V_9 -> V_26 != V_18 )
return - V_25 ;
if ( ! V_12 -> V_151 -> V_261 )
return - V_27 ;
if ( V_257 -> V_116 ) {
V_258 = false ;
} else {
switch ( V_257 -> V_94 & V_262 ) {
case V_263 :
case V_262 :
case V_264 :
V_258 = true ;
break;
default:
return - V_25 ;
}
if ( V_257 -> V_94 & ~ ( V_262 | V_265 ) )
return - V_25 ;
if ( V_257 -> V_94 & V_265 )
V_259 = V_257 -> V_118 / 1000 ;
}
V_115 = F_63 ( V_12 , V_2 , V_258 , V_259 ) ;
if ( V_115 )
return V_115 ;
V_9 -> V_258 = V_258 ;
V_9 -> V_260 = V_259 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_111 * V_257 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_257 -> V_116 = ! V_9 -> V_258 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_266 * V_136 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 -> V_16 ) ;
int V_115 ;
if ( F_66 ( V_9 -> V_26 != V_22 ) )
return - V_25 ;
if ( V_136 -> V_267 != V_268 )
return - V_25 ;
if ( F_67 ( V_2 ) )
return - V_269 ;
if ( ! V_12 -> V_151 -> V_270 )
return - V_27 ;
V_115 = F_68 ( V_12 , V_2 , ( V_62 * ) & V_136 -> V_176 ) ;
if ( V_115 )
return V_115 ;
memcpy ( & V_9 -> V_142 . V_271 , ( V_62 * ) & V_136 -> V_176 , V_272 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_266 * V_136 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( F_66 ( V_9 -> V_26 != V_22 ) )
return - V_25 ;
V_136 -> V_267 = V_268 ;
memcpy ( & V_136 -> V_176 , V_9 -> V_142 . V_271 , V_272 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_111 * V_273 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 -> V_16 ) ;
struct V_274 V_275 ;
T_1 V_117 , V_276 ;
struct V_86 * V_87 ;
int V_38 , V_277 ;
bool V_278 = false ;
if ( ! V_12 -> V_151 -> V_279 )
return - V_27 ;
memset ( & V_275 , 0 , sizeof( V_275 ) ) ;
V_117 = 0 ;
V_276 = ( T_1 ) - 1 ;
if ( V_273 -> V_118 < 0 ) {
} else if ( V_273 -> V_117 ) {
V_117 = V_273 -> V_118 / 100000 ;
} else {
V_276 = V_273 -> V_118 / 100000 ;
}
for ( V_38 = 0 ; V_38 < V_85 ; V_38 ++ ) {
V_87 = V_9 -> V_16 -> V_88 [ V_38 ] ;
if ( V_87 == NULL )
continue;
for ( V_277 = 0 ; V_277 < V_87 -> V_280 ; V_277 ++ ) {
struct V_281 * V_282 = & V_87 -> V_283 [ V_277 ] ;
if ( V_117 == V_282 -> V_284 ) {
V_275 . V_285 [ V_38 ] . V_286 = 1 << V_277 ;
V_278 = true ;
break;
}
if ( V_282 -> V_284 <= V_276 ) {
V_275 . V_285 [ V_38 ] . V_286 |= 1 << V_277 ;
V_278 = true ;
}
}
}
if ( ! V_278 )
return - V_25 ;
return F_71 ( V_12 , V_2 , NULL , & V_275 ) ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_111 * V_273 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 -> V_16 ) ;
static struct V_287 V_288 ;
V_62 V_136 [ V_272 ] ;
int V_115 ;
if ( V_9 -> V_26 != V_18 )
return - V_27 ;
if ( ! V_12 -> V_151 -> V_289 )
return - V_27 ;
V_115 = 0 ;
F_29 ( V_9 ) ;
if ( V_9 -> V_149 )
memcpy ( V_136 , V_9 -> V_149 -> V_290 . V_271 , V_272 ) ;
else
V_115 = - V_27 ;
F_30 ( V_9 ) ;
if ( V_115 )
return V_115 ;
V_115 = F_73 ( V_12 , V_2 , V_136 , & V_288 ) ;
if ( V_115 )
return V_115 ;
if ( ! ( V_288 . V_291 & F_74 ( V_292 ) ) )
return - V_27 ;
V_273 -> V_118 = 100000 * F_75 ( & V_288 . V_293 ) ;
return 0 ;
}
static struct V_294 * F_76 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 -> V_16 ) ;
static struct V_294 V_295 ;
static struct V_287 V_288 ;
V_62 V_271 [ V_272 ] ;
if ( V_2 -> V_10 -> V_26 != V_18 )
return NULL ;
if ( ! V_12 -> V_151 -> V_289 )
return NULL ;
F_29 ( V_9 ) ;
if ( ! V_9 -> V_149 ) {
F_30 ( V_9 ) ;
return NULL ;
}
memcpy ( V_271 , V_9 -> V_149 -> V_290 . V_271 , V_272 ) ;
F_30 ( V_9 ) ;
memset ( & V_288 , 0 , sizeof( V_288 ) ) ;
if ( F_73 ( V_12 , V_2 , V_271 , & V_288 ) )
return NULL ;
memset ( & V_295 , 0 , sizeof( V_295 ) ) ;
switch ( V_12 -> V_16 . V_58 ) {
case V_60 :
if ( V_288 . V_291 & F_74 ( V_296 ) ) {
int V_297 = V_288 . signal ;
V_295 . V_63 . V_56 |= V_67 ;
V_295 . V_63 . V_56 |= V_66 ;
V_295 . V_63 . V_56 |= V_65 ;
V_295 . V_63 . V_61 = V_297 ;
if ( V_297 < - 110 )
V_297 = - 110 ;
else if ( V_297 > - 40 )
V_297 = - 40 ;
V_295 . V_63 . V_63 = V_297 + 110 ;
break;
}
case V_68 :
if ( V_288 . V_291 & F_74 ( V_296 ) ) {
V_295 . V_63 . V_56 |= V_67 ;
V_295 . V_63 . V_56 |= V_66 ;
V_295 . V_63 . V_61 = V_288 . signal ;
V_295 . V_63 . V_63 = V_288 . signal ;
break;
}
default:
V_295 . V_63 . V_56 |= V_298 ;
V_295 . V_63 . V_56 |= V_299 ;
}
V_295 . V_63 . V_56 |= V_57 ;
if ( V_288 . V_291 & F_74 ( V_300 ) )
V_295 . V_301 . V_302 = V_288 . V_303 ;
if ( V_288 . V_291 & F_74 ( V_304 ) )
V_295 . V_301 . V_305 = V_288 . V_306 ;
return & V_295 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_266 * V_307 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
switch ( V_9 -> V_26 ) {
case V_20 :
return F_78 ( V_2 , V_4 , V_307 , V_6 ) ;
case V_18 :
return F_79 ( V_2 , V_4 , V_307 , V_6 ) ;
case V_22 :
return F_65 ( V_2 , V_4 , V_307 , V_6 ) ;
default:
return - V_27 ;
}
}
static int F_80 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_266 * V_307 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
switch ( V_9 -> V_26 ) {
case V_20 :
return F_81 ( V_2 , V_4 , V_307 , V_6 ) ;
case V_18 :
return F_82 ( V_2 , V_4 , V_307 , V_6 ) ;
case V_22 :
return F_69 ( V_2 , V_4 , V_307 , V_6 ) ;
default:
return - V_27 ;
}
}
static int F_83 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_34 , char * V_308 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
switch ( V_9 -> V_26 ) {
case V_20 :
return F_84 ( V_2 , V_4 , V_34 , V_308 ) ;
case V_18 :
return F_85 ( V_2 , V_4 , V_34 , V_308 ) ;
default:
return - V_27 ;
}
}
static int F_86 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_34 , char * V_308 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_34 -> V_94 = 0 ;
V_34 -> V_41 = 0 ;
switch ( V_9 -> V_26 ) {
case V_20 :
return F_87 ( V_2 , V_4 , V_34 , V_308 ) ;
case V_18 :
return F_88 ( V_2 , V_4 , V_34 , V_308 ) ;
default:
return - V_27 ;
}
}
static int F_89 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_34 , char * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 -> V_16 ) ;
struct V_309 V_310 ;
struct V_311 * V_312 = (struct V_311 * ) V_6 ;
memset ( & V_310 , 0 , sizeof( struct V_309 ) ) ;
if ( V_9 -> V_26 != V_18 )
return - V_25 ;
V_310 . V_271 = V_312 -> V_271 . V_176 ;
V_310 . V_313 = V_312 -> V_313 ;
switch ( V_312 -> V_314 ) {
case V_315 :
if ( ! V_12 -> V_151 -> V_316 )
return - V_27 ;
return F_90 ( V_12 , V_2 , & V_310 ) ;
case V_317 :
if ( ! V_12 -> V_151 -> V_318 )
return - V_27 ;
return F_91 ( V_12 , V_2 , & V_310 ) ;
case V_319 :
if ( ! V_12 -> V_151 -> V_320 )
return - V_27 ;
return F_92 ( V_12 , V_2 ) ;
default:
return - V_27 ;
}
}
