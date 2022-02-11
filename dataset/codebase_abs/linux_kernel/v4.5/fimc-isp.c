const struct V_1 * F_1 ( const T_1 * V_2 ,
const T_1 * V_3 , int V_4 )
{
const struct V_1 * V_5 , * V_6 = NULL ;
unsigned int V_7 ;
int V_8 = 0 ;
if ( V_4 >= ( int ) F_2 ( V_9 ) )
return NULL ;
for ( V_7 = 0 ; V_7 < F_2 ( V_9 ) ; ++ V_7 ) {
V_5 = & V_9 [ V_7 ] ;
if ( V_2 && V_5 -> V_10 == * V_2 )
return V_5 ;
if ( V_3 && V_5 -> V_3 == * V_3 )
return V_5 ;
if ( V_4 == V_8 )
V_6 = V_5 ;
V_8 ++ ;
}
return V_6 ;
}
void F_3 ( struct V_11 * V_12 )
{
V_12 -> V_13 . args [ 0 ] = F_4 ( V_12 , F_5 ( 20 ) ) ;
V_12 -> V_13 . args [ 1 ] = F_4 ( V_12 , F_5 ( 21 ) ) ;
F_6 ( V_12 , V_14 ) ;
F_7 ( V_12 ) ;
F_8 ( & V_12 -> V_15 ) ;
}
static int F_9 ( struct V_16 * V_17 ,
const struct V_18 * V_19 ,
const struct V_18 * V_20 , T_1 V_21 )
{
return 0 ;
}
static int F_10 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_26 * V_27 )
{
const struct V_1 * V_5 ;
V_5 = F_1 ( NULL , NULL , V_27 -> V_4 ) ;
if ( ! V_5 )
return - V_28 ;
V_27 -> V_27 = V_5 -> V_3 ;
return 0 ;
}
static int F_11 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_29 * V_5 )
{
struct V_30 * V_31 = F_12 ( V_23 ) ;
struct V_32 * V_33 = & V_5 -> V_34 ;
if ( V_5 -> V_35 == V_36 ) {
* V_33 = * F_13 ( V_23 , V_25 , V_5 -> V_37 ) ;
return 0 ;
}
V_33 -> V_38 = V_39 ;
F_14 ( & V_31 -> V_40 ) ;
if ( V_5 -> V_37 == V_41 ) {
* V_33 = V_31 -> V_42 ;
} else {
* V_33 = V_31 -> V_43 ;
if ( V_5 -> V_37 == V_44 ) {
V_33 -> V_38 = V_45 ;
V_33 -> V_27 = V_46 ;
}
}
F_15 ( & V_31 -> V_40 ) ;
F_16 ( 1 , V_23 , L_1 , V_47 ,
V_5 -> V_37 , V_33 -> V_27 , V_33 -> V_48 , V_33 -> V_49 ) ;
return 0 ;
}
static void F_17 ( struct V_30 * V_31 ,
struct V_24 * V_25 ,
struct V_29 * V_5 )
{
struct V_32 * V_33 = & V_5 -> V_34 ;
struct V_32 * V_34 ;
V_33 -> V_38 = V_39 ;
if ( V_5 -> V_37 == V_41 ) {
F_18 ( & V_33 -> V_48 , V_50 ,
V_51 , 0 ,
& V_33 -> V_49 , V_52 ,
V_53 , 0 , 0 ) ;
V_33 -> V_27 = V_54 ;
} else {
if ( V_5 -> V_35 == V_36 )
V_34 = F_13 ( & V_31 -> V_55 , V_25 ,
V_41 ) ;
else
V_34 = & V_31 -> V_42 ;
V_33 -> V_48 = V_34 -> V_48 - V_56 ;
V_33 -> V_49 = V_34 -> V_49 - V_57 ;
if ( V_5 -> V_37 == V_44 ) {
V_33 -> V_27 = V_46 ;
V_33 -> V_38 = V_45 ;
} else {
V_33 -> V_27 = V_34 -> V_27 ;
}
}
}
static int F_19 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_29 * V_5 )
{
struct V_30 * V_31 = F_12 ( V_23 ) ;
struct V_11 * V_12 = F_20 ( V_31 ) ;
struct V_32 * V_33 = & V_5 -> V_34 ;
int V_58 = 0 ;
F_16 ( 1 , V_23 , L_2 ,
V_47 , V_5 -> V_37 , V_33 -> V_27 , V_33 -> V_48 , V_33 -> V_49 ) ;
F_14 ( & V_31 -> V_40 ) ;
F_17 ( V_31 , V_25 , V_5 ) ;
if ( V_5 -> V_35 == V_36 ) {
V_33 = F_13 ( V_23 , V_25 , V_5 -> V_37 ) ;
* V_33 = V_5 -> V_34 ;
if ( V_5 -> V_37 == V_41 ) {
struct V_29 V_34 = * V_5 ;
unsigned int V_37 ;
for ( V_37 = V_44 ;
V_37 < V_59 ; V_37 ++ ) {
V_34 . V_37 = V_37 ;
F_17 ( V_31 , V_25 , & V_34 ) ;
V_33 = F_13 ( V_23 , V_25 , V_37 ) ;
* V_33 = V_34 . V_34 ;
}
}
} else {
if ( V_23 -> V_17 . V_60 == 0 ) {
if ( V_5 -> V_37 == V_41 ) {
struct V_29 V_34 = * V_5 ;
V_31 -> V_42 = * V_33 ;
V_34 . V_37 = V_61 ;
F_17 ( V_31 , V_25 , & V_34 ) ;
V_31 -> V_43 = V_34 . V_34 ;
F_21 ( V_12 , & V_31 -> V_43 ) ;
} else {
V_31 -> V_43 = * V_33 ;
}
} else {
V_58 = - V_62 ;
}
}
F_15 ( & V_31 -> V_40 ) ;
return V_58 ;
}
static int F_22 ( struct V_22 * V_23 , int V_63 )
{
struct V_30 * V_31 = F_12 ( V_23 ) ;
struct V_11 * V_12 = F_20 ( V_31 ) ;
int V_58 ;
F_16 ( 1 , V_23 , L_3 , V_47 , V_63 ) ;
if ( ! F_23 ( V_64 , & V_12 -> V_65 ) )
return - V_62 ;
F_24 () ;
if ( V_63 ) {
if ( F_25 ( V_12 ) ) {
V_58 = F_26 ( V_12 , true ) ;
if ( V_58 < 0 )
return V_58 ;
}
F_16 ( 1 , V_23 , L_4 , V_12 -> V_66 ) ;
V_58 = F_27 ( V_12 ) ;
if ( V_58 )
return - V_28 ;
F_28 ( V_67 , & V_12 -> V_65 ) ;
F_29 ( V_12 ) ;
V_58 = F_30 ( V_12 , V_67 , 1 ,
V_68 ) ;
if ( V_58 < 0 ) {
F_31 ( V_23 , L_5 ) ;
return V_58 ;
}
} else {
F_28 ( V_69 , & V_12 -> V_65 ) ;
F_32 ( V_12 ) ;
V_58 = F_30 ( V_12 , V_69 , 1 ,
V_68 ) ;
if ( V_58 < 0 ) {
F_31 ( V_23 , L_6 ) ;
return V_58 ;
}
V_12 -> V_70 . V_71 = 0 ;
}
return 0 ;
}
static int F_33 ( struct V_22 * V_23 , int V_63 )
{
struct V_30 * V_31 = F_12 ( V_23 ) ;
struct V_11 * V_12 = F_20 ( V_31 ) ;
int V_58 = 0 ;
F_34 ( L_7 , V_63 ) ;
if ( V_63 ) {
V_58 = F_35 ( & V_12 -> V_72 -> V_73 ) ;
if ( V_58 < 0 )
return V_58 ;
F_36 ( V_74 , & V_12 -> V_65 ) ;
V_58 = F_37 ( V_12 ) ;
if ( V_58 < 0 ) {
F_31 ( V_23 , L_8 ) ;
F_38 ( & V_12 -> V_72 -> V_73 ) ;
return V_58 ;
}
F_36 ( V_75 , & V_12 -> V_65 ) ;
V_58 = F_39 ( V_12 ) ;
} else {
if ( ! F_23 ( V_74 , & V_12 -> V_65 ) ) {
F_40 ( V_12 , 0 ) ;
V_58 = F_30 ( V_12 , V_76 , 0 ,
V_68 ) ;
if ( V_58 < 0 ) {
F_31 ( V_23 , L_9 ) ;
return V_58 ;
}
}
if ( F_23 ( V_75 , & V_12 -> V_65 ) ) {
F_41 ( V_12 ) ;
V_58 = F_30 ( V_12 , V_75 , 0 ,
V_68 ) ;
if ( V_58 < 0 ) {
F_31 ( V_23 , L_10 ) ;
return V_58 ;
}
}
F_42 ( V_12 , 0 ) ;
F_43 ( & V_12 -> V_72 -> V_73 ) ;
F_28 ( V_74 , & V_12 -> V_65 ) ;
F_28 ( V_64 , & V_12 -> V_65 ) ;
V_12 -> V_65 = 0 ;
V_12 -> V_77 [ V_12 -> V_66 ] . V_78 [ 0 ] = 0 ;
V_12 -> V_77 [ V_12 -> V_66 ] . V_78 [ 1 ] = 0 ;
F_36 ( V_79 , & V_12 -> V_65 ) ;
F_44 () ;
}
return V_58 ;
}
static int F_45 ( struct V_22 * V_23 ,
struct V_80 * V_81 )
{
struct V_32 V_5 ;
struct V_32 * V_34 ;
V_34 = F_13 ( V_23 , V_81 -> V_37 , V_41 ) ;
V_5 . V_38 = V_39 ;
V_5 . V_27 = V_9 [ 0 ] . V_3 ;
V_5 . V_48 = V_82 + V_56 ;
V_5 . V_49 = V_83 + V_57 ;
V_5 . V_84 = V_85 ;
* V_34 = V_5 ;
V_34 = F_13 ( V_23 , V_81 -> V_37 , V_44 ) ;
V_5 . V_48 = V_82 ;
V_5 . V_49 = V_83 ;
* V_34 = V_5 ;
V_34 = F_13 ( V_23 , V_81 -> V_37 , V_61 ) ;
* V_34 = V_5 ;
return 0 ;
}
static int F_46 ( struct V_22 * V_23 )
{
struct V_30 * V_31 = F_12 ( V_23 ) ;
int V_58 ;
V_31 -> V_86 . V_87 . V_88 = F_47 ( V_23 ) ;
V_58 = F_48 ( V_31 , V_23 -> V_89 ,
V_90 ) ;
if ( V_58 < 0 )
V_31 -> V_86 . V_87 . V_88 = NULL ;
return V_58 ;
}
static void F_49 ( struct V_22 * V_23 )
{
struct V_30 * V_31 = F_12 ( V_23 ) ;
F_50 ( V_31 ,
V_90 ) ;
}
static int F_51 ( struct V_11 * V_12 , int V_91 )
{
switch ( V_91 ) {
case V_92 :
F_52 ( V_12 , V_93 , 0 ) ;
break;
case V_94 :
F_52 ( V_12 , V_95 ,
V_96 ) ;
break;
case V_97 :
F_52 ( V_12 , V_95 ,
V_98 ) ;
break;
case V_99 :
F_52 ( V_12 , V_95 ,
V_100 ) ;
break;
case V_101 :
F_52 ( V_12 , V_95 ,
V_102 ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_53 ( struct V_11 * V_12 ,
struct V_103 * V_104 )
{
bool V_105 = V_104 -> V_106 & V_107 ;
bool V_108 = V_104 -> V_106 & V_109 ;
struct V_110 * V_31 = & V_12 -> V_111 -> V_112 . V_31 ;
int V_113 , V_58 ;
V_113 = V_108 ? V_114 : V_115 ;
V_31 -> V_116 . V_113 = V_113 ;
V_31 -> V_116 . V_117 = V_118 ;
F_54 ( V_12 , V_119 ) ;
V_12 -> V_120 . V_121 = V_108 ;
F_44 () ;
V_58 = F_26 ( V_12 , false ) ;
if ( V_58 < 0 )
return V_58 ;
V_113 = V_105 ? V_114 : V_115 ;
V_31 -> V_116 . V_113 = V_113 ;
V_31 -> V_116 . V_117 = V_118 ;
F_54 ( V_12 , V_119 ) ;
V_12 -> V_120 . V_122 = V_105 ;
F_44 () ;
return F_26 ( V_12 , false ) ;
}
static int F_55 ( struct V_11 * V_12 , int V_91 )
{
unsigned int V_123 , V_124 ;
if ( V_91 == V_125 ) {
F_56 ( V_12 , V_126 , 0 ) ;
return 0 ;
}
V_123 = V_12 -> V_31 . V_127 . V_124 -> V_106 ;
if ( V_123 >= F_2 ( V_128 ) )
return - V_28 ;
V_124 = V_128 [ V_123 ] ;
F_56 ( V_12 , V_129 , V_124 ) ;
return 0 ;
}
static int F_57 ( struct V_11 * V_12 , unsigned int V_91 )
{
unsigned int V_106 ;
switch ( V_91 ) {
case V_130 :
V_106 = V_131 ;
break;
case V_132 :
V_106 = V_133 ;
break;
case V_134 :
V_106 = V_135 ;
break;
case V_136 :
V_106 = V_137 ;
break;
default:
return - V_28 ;
}
F_58 ( V_12 , V_138 , V_106 ) ;
return 0 ;
}
static int F_59 ( struct V_11 * V_12 , int V_91 )
{
switch ( V_91 ) {
case V_139 :
F_60 ( V_12 , V_140 , 0 ) ;
break;
case V_141 :
F_60 ( V_12 , V_142 , 50 ) ;
break;
case V_143 :
F_60 ( V_12 , V_142 , 60 ) ;
break;
case V_144 :
F_60 ( V_12 , V_145 , 0 ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_61 ( struct V_11 * V_12 , int V_91 )
{
static const T_2 V_146 [] [ 2 ] = {
{ V_147 , V_148 } ,
{ V_149 , V_150 } ,
{ V_151 , V_152 } ,
{ V_153 , V_154 } ,
{ 16 , V_155 } ,
} ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_2 ( V_146 ) ; V_7 ++ ) {
if ( V_146 [ V_7 ] [ 0 ] != V_91 )
continue;
F_62 ( V_12 , V_146 [ V_7 ] [ 1 ] ) ;
return 0 ;
}
return - V_28 ;
}
static int F_63 ( struct V_103 * V_104 )
{
struct V_30 * V_31 = F_64 ( V_104 ) ;
struct V_11 * V_12 = F_20 ( V_31 ) ;
bool V_156 = true ;
int V_58 = 0 ;
switch ( V_104 -> V_8 ) {
case V_157 :
F_65 ( V_12 , V_158 ,
V_104 -> V_106 ) ;
break;
case V_159 :
F_65 ( V_12 , V_160 ,
V_104 -> V_106 ) ;
break;
case V_161 :
F_65 ( V_12 , V_162 ,
V_104 -> V_106 ) ;
break;
case V_163 :
F_65 ( V_12 , V_164 ,
V_104 -> V_106 ) ;
break;
case V_165 :
F_65 ( V_12 , V_166 ,
V_104 -> V_106 ) ;
break;
case V_167 :
F_65 ( V_12 , V_168 ,
V_104 -> V_106 ) ;
break;
case V_169 :
V_58 = F_57 ( V_12 , V_104 -> V_106 ) ;
break;
case V_170 :
V_58 = F_51 ( V_12 , V_104 -> V_106 ) ;
break;
case V_171 :
V_58 = F_53 ( V_12 , V_104 ) ;
V_156 = false ;
break;
case V_172 :
V_58 = F_55 ( V_12 , V_104 -> V_106 ) ;
break;
case V_173 :
V_58 = F_59 ( V_12 , V_104 -> V_106 ) ;
break;
case V_174 :
F_61 ( V_12 , V_104 -> V_106 ) ;
break;
default:
V_58 = - V_28 ;
break;
}
if ( V_58 < 0 ) {
F_31 ( & V_31 -> V_55 , L_11 ,
V_104 -> V_175 , V_104 -> V_106 ) ;
return V_58 ;
}
if ( V_156 && F_23 ( V_67 , & V_12 -> V_65 ) )
return F_26 ( V_12 , true ) ;
return 0 ;
}
static void F_66 ( struct V_30 * V_31 )
{
struct V_11 * V_12 = F_20 ( V_31 ) ;
V_31 -> V_42 . V_48 = V_82 +
V_56 ;
V_31 -> V_42 . V_49 = V_83 +
V_57 ;
V_31 -> V_42 . V_27 = V_54 ;
V_31 -> V_43 . V_48 = V_82 ;
V_31 -> V_43 . V_49 = V_83 ;
V_31 -> V_43 . V_27 = V_54 ;
F_21 ( V_12 , & V_31 -> V_43 ) ;
}
int F_67 ( struct V_30 * V_31 )
{
const struct V_176 * V_177 = & V_178 ;
struct V_179 * V_180 = & V_31 -> V_127 . V_180 ;
struct V_22 * V_23 = & V_31 -> V_55 ;
struct V_181 * V_127 = & V_31 -> V_127 ;
int V_58 ;
F_68 ( & V_31 -> V_40 ) ;
F_69 ( V_23 , & V_182 ) ;
V_23 -> V_183 = V_184 ;
V_23 -> V_185 = V_186 ;
V_23 -> V_21 |= V_187 ;
snprintf ( V_23 -> V_175 , sizeof( V_23 -> V_175 ) , L_12 ) ;
V_31 -> V_188 [ V_41 ] . V_21 = V_189 ;
V_31 -> V_188 [ V_44 ] . V_21 = V_190 ;
V_31 -> V_188 [ V_61 ] . V_21 = V_190 ;
V_58 = F_70 ( & V_23 -> V_17 , V_59 ,
V_31 -> V_188 ) ;
if ( V_58 )
return V_58 ;
F_71 ( V_180 , 20 ) ;
V_127 -> V_191 = F_72 ( V_180 , V_177 , V_159 ,
- 2 , 2 , 1 , 0 ) ;
V_127 -> V_192 = F_72 ( V_180 , V_177 , V_165 ,
- 4 , 4 , 1 , 0 ) ;
V_127 -> V_193 = F_72 ( V_180 , V_177 , V_157 ,
- 2 , 2 , 1 , 0 ) ;
V_127 -> V_194 = F_72 ( V_180 , V_177 , V_161 ,
- 2 , 2 , 1 , 0 ) ;
V_127 -> V_195 = F_72 ( V_180 , V_177 , V_167 ,
- 2 , 2 , 1 , 0 ) ;
V_127 -> V_196 = F_73 ( V_180 , V_177 ,
V_170 ,
8 , ~ 0x14e , V_92 ) ;
V_127 -> V_197 = F_72 ( V_180 , V_177 ,
V_163 ,
- 4 , 4 , 1 , 0 ) ;
V_127 -> V_198 = F_73 ( V_180 , V_177 ,
V_169 , 3 ,
~ 0xf , V_130 ) ;
F_73 ( V_180 , V_177 , V_173 ,
V_144 , 0 ,
V_144 ) ;
V_127 -> V_199 = F_73 ( V_180 , V_177 ,
V_172 , 1 , 0 ,
V_125 ) ;
V_127 -> V_124 = F_74 ( V_180 , V_177 ,
V_200 , F_2 ( V_128 ) - 1 ,
F_2 ( V_128 ) / 2 - 1 , V_128 ) ;
V_127 -> V_201 = F_72 ( V_180 , V_177 ,
V_171 , 0 , 0x3 , 0 , 0 ) ;
V_127 -> V_202 = F_73 ( V_180 , V_177 , V_174 ,
V_203 + 1 , ~ 0x1000f , V_147 ) ;
if ( V_180 -> error ) {
F_75 ( & V_23 -> V_17 ) ;
return V_180 -> error ;
}
F_76 ( 2 , & V_127 -> V_199 ,
V_204 , false ) ;
V_23 -> V_205 = V_180 ;
V_23 -> V_206 = & V_207 ;
V_23 -> V_17 . V_177 = & V_208 ;
F_77 ( V_23 , V_31 ) ;
F_66 ( V_31 ) ;
return 0 ;
}
void F_78 ( struct V_30 * V_31 )
{
struct V_22 * V_23 = & V_31 -> V_55 ;
F_79 ( V_23 ) ;
F_75 ( & V_23 -> V_17 ) ;
F_80 ( & V_31 -> V_127 . V_180 ) ;
F_77 ( V_23 , NULL ) ;
}
