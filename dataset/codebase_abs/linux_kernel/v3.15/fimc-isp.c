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
* V_33 = * F_13 ( V_25 , V_5 -> V_37 ) ;
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
V_34 = F_13 ( V_25 ,
V_41 ) ;
else
V_34 = & V_31 -> V_42 ;
V_33 -> V_48 = V_34 -> V_48 - V_55 ;
V_33 -> V_49 = V_34 -> V_49 - V_56 ;
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
int V_57 = 0 ;
F_16 ( 1 , V_23 , L_2 ,
V_47 , V_5 -> V_37 , V_33 -> V_27 , V_33 -> V_48 , V_33 -> V_49 ) ;
F_14 ( & V_31 -> V_40 ) ;
F_17 ( V_31 , V_25 , V_5 ) ;
if ( V_5 -> V_35 == V_36 ) {
V_33 = F_13 ( V_25 , V_5 -> V_37 ) ;
* V_33 = V_5 -> V_34 ;
if ( V_5 -> V_37 == V_41 ) {
struct V_29 V_34 = * V_5 ;
unsigned int V_37 ;
for ( V_37 = V_44 ;
V_37 < V_58 ; V_37 ++ ) {
V_34 . V_37 = V_37 ;
F_17 ( V_31 , V_25 , & V_34 ) ;
V_33 = F_13 ( V_25 , V_37 ) ;
* V_33 = V_34 . V_34 ;
}
}
} else {
if ( V_23 -> V_17 . V_59 == 0 ) {
if ( V_5 -> V_37 == V_41 ) {
struct V_29 V_34 = * V_5 ;
V_31 -> V_42 = * V_33 ;
V_34 . V_37 = V_60 ;
F_17 ( V_31 , V_25 , & V_34 ) ;
V_31 -> V_43 = V_34 . V_34 ;
F_21 ( V_12 , & V_31 -> V_43 ) ;
} else {
V_31 -> V_43 = * V_33 ;
}
} else {
V_57 = - V_61 ;
}
}
F_15 ( & V_31 -> V_40 ) ;
return V_57 ;
}
static int F_22 ( struct V_22 * V_23 , int V_62 )
{
struct V_30 * V_31 = F_12 ( V_23 ) ;
struct V_11 * V_12 = F_20 ( V_31 ) ;
int V_57 ;
F_16 ( 1 , V_23 , L_3 , V_47 , V_62 ) ;
if ( ! F_23 ( V_63 , & V_12 -> V_64 ) )
return - V_61 ;
F_24 () ;
if ( V_62 ) {
if ( F_25 ( V_12 ) ) {
V_57 = F_26 ( V_12 , true ) ;
if ( V_57 < 0 )
return V_57 ;
}
F_16 ( 1 , V_23 , L_4 , V_12 -> V_65 ) ;
V_57 = F_27 ( V_12 ) ;
if ( V_57 )
return - V_28 ;
F_28 ( V_66 , & V_12 -> V_64 ) ;
F_29 ( V_12 ) ;
V_57 = F_30 ( V_12 , V_66 , 1 ,
V_67 ) ;
if ( V_57 < 0 ) {
F_31 ( V_23 , L_5 ) ;
return V_57 ;
}
} else {
F_28 ( V_68 , & V_12 -> V_64 ) ;
F_32 ( V_12 ) ;
V_57 = F_30 ( V_12 , V_68 , 1 ,
V_67 ) ;
if ( V_57 < 0 ) {
F_31 ( V_23 , L_6 ) ;
return V_57 ;
}
V_12 -> V_69 . V_70 = 0 ;
}
return 0 ;
}
static int F_33 ( struct V_22 * V_23 , int V_62 )
{
struct V_30 * V_31 = F_12 ( V_23 ) ;
struct V_11 * V_12 = F_20 ( V_31 ) ;
int V_57 = 0 ;
F_34 ( L_7 , V_62 ) ;
if ( V_62 ) {
V_57 = F_35 ( & V_12 -> V_71 -> V_72 ) ;
if ( V_57 < 0 )
return V_57 ;
F_36 ( V_73 , & V_12 -> V_64 ) ;
V_57 = F_37 ( V_12 ) ;
if ( V_57 < 0 ) {
F_31 ( V_23 , L_8 ) ;
F_38 ( & V_12 -> V_71 -> V_72 ) ;
return V_57 ;
}
F_36 ( V_74 , & V_12 -> V_64 ) ;
V_57 = F_39 ( V_12 ) ;
} else {
if ( ! F_23 ( V_73 , & V_12 -> V_64 ) ) {
F_40 ( V_12 , 0 ) ;
V_57 = F_30 ( V_12 , V_75 , 0 ,
V_67 ) ;
if ( V_57 < 0 ) {
F_31 ( V_23 , L_9 ) ;
return V_57 ;
}
}
if ( F_23 ( V_74 , & V_12 -> V_64 ) ) {
F_41 ( V_12 ) ;
V_57 = F_30 ( V_12 , V_74 , 0 ,
V_67 ) ;
if ( V_57 < 0 ) {
F_31 ( V_23 , L_10 ) ;
return V_57 ;
}
}
F_42 ( V_12 , 0 ) ;
F_43 ( & V_12 -> V_71 -> V_72 ) ;
F_28 ( V_73 , & V_12 -> V_64 ) ;
F_28 ( V_63 , & V_12 -> V_64 ) ;
V_12 -> V_64 = 0 ;
V_12 -> V_76 [ V_12 -> V_65 ] . V_77 [ 0 ] = 0 ;
V_12 -> V_76 [ V_12 -> V_65 ] . V_77 [ 1 ] = 0 ;
F_36 ( V_78 , & V_12 -> V_64 ) ;
F_44 () ;
}
return V_57 ;
}
static int F_45 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_32 V_5 ;
struct V_32 * V_34 ;
V_34 = F_13 ( V_25 , V_41 ) ;
V_5 . V_38 = V_39 ;
V_5 . V_27 = V_9 [ 0 ] . V_3 ;
V_5 . V_48 = V_79 + V_55 ;
V_5 . V_49 = V_80 + V_56 ;
V_5 . V_81 = V_82 ;
* V_34 = V_5 ;
V_34 = F_13 ( V_25 , V_44 ) ;
V_5 . V_48 = V_79 ;
V_5 . V_49 = V_80 ;
* V_34 = V_5 ;
V_34 = F_13 ( V_25 , V_60 ) ;
* V_34 = V_5 ;
return 0 ;
}
static int F_46 ( struct V_22 * V_23 )
{
struct V_30 * V_31 = F_12 ( V_23 ) ;
int V_57 ;
V_31 -> V_83 . V_84 . V_85 = F_47 ( V_23 ) ;
V_57 = F_48 ( V_31 , V_23 -> V_86 ,
V_87 ) ;
if ( V_57 < 0 )
V_31 -> V_83 . V_84 . V_85 = NULL ;
return V_57 ;
}
static void F_49 ( struct V_22 * V_23 )
{
struct V_30 * V_31 = F_12 ( V_23 ) ;
F_50 ( V_31 ,
V_87 ) ;
}
static int F_51 ( struct V_11 * V_12 , int V_88 )
{
switch ( V_88 ) {
case V_89 :
F_52 ( V_12 , V_90 , 0 ) ;
break;
case V_91 :
F_52 ( V_12 , V_92 ,
V_93 ) ;
break;
case V_94 :
F_52 ( V_12 , V_92 ,
V_95 ) ;
break;
case V_96 :
F_52 ( V_12 , V_92 ,
V_97 ) ;
break;
case V_98 :
F_52 ( V_12 , V_92 ,
V_99 ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_53 ( struct V_11 * V_12 ,
struct V_100 * V_101 )
{
bool V_102 = V_101 -> V_103 & V_104 ;
bool V_105 = V_101 -> V_103 & V_106 ;
struct V_107 * V_31 = & V_12 -> V_108 -> V_109 . V_31 ;
int V_110 , V_57 ;
V_110 = V_105 ? V_111 : V_112 ;
V_31 -> V_113 . V_110 = V_110 ;
V_31 -> V_113 . V_114 = V_115 ;
F_54 ( V_12 , V_116 ) ;
V_12 -> V_117 . V_118 = V_105 ;
F_44 () ;
V_57 = F_26 ( V_12 , false ) ;
if ( V_57 < 0 )
return V_57 ;
V_110 = V_102 ? V_111 : V_112 ;
V_31 -> V_113 . V_110 = V_110 ;
V_31 -> V_113 . V_114 = V_115 ;
F_54 ( V_12 , V_116 ) ;
V_12 -> V_117 . V_119 = V_102 ;
F_44 () ;
return F_26 ( V_12 , false ) ;
}
static int F_55 ( struct V_11 * V_12 , int V_88 )
{
unsigned int V_120 , V_121 ;
if ( V_88 == V_122 ) {
F_56 ( V_12 , V_123 , 0 ) ;
return 0 ;
}
V_120 = V_12 -> V_31 . V_124 . V_121 -> V_103 ;
if ( V_120 >= F_2 ( V_125 ) )
return - V_28 ;
V_121 = V_125 [ V_120 ] ;
F_56 ( V_12 , V_126 , V_121 ) ;
return 0 ;
}
static int F_57 ( struct V_11 * V_12 , unsigned int V_88 )
{
unsigned int V_103 ;
switch ( V_88 ) {
case V_127 :
V_103 = V_128 ;
break;
case V_129 :
V_103 = V_130 ;
break;
case V_131 :
V_103 = V_132 ;
break;
case V_133 :
V_103 = V_134 ;
break;
default:
return - V_28 ;
}
F_58 ( V_12 , V_135 , V_103 ) ;
return 0 ;
}
static int F_59 ( struct V_11 * V_12 , int V_88 )
{
switch ( V_88 ) {
case V_136 :
F_60 ( V_12 , V_137 , 0 ) ;
break;
case V_138 :
F_60 ( V_12 , V_139 , 50 ) ;
break;
case V_140 :
F_60 ( V_12 , V_139 , 60 ) ;
break;
case V_141 :
F_60 ( V_12 , V_142 , 0 ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_61 ( struct V_11 * V_12 , int V_88 )
{
static const T_2 V_143 [] [ 2 ] = {
{ V_144 , V_145 } ,
{ V_146 , V_147 } ,
{ V_148 , V_149 } ,
{ V_150 , V_151 } ,
{ 16 , V_152 } ,
} ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_2 ( V_143 ) ; V_7 ++ ) {
if ( V_143 [ V_7 ] [ 0 ] != V_88 )
continue;
F_62 ( V_12 , V_143 [ V_7 ] [ 1 ] ) ;
return 0 ;
}
return - V_28 ;
}
static int F_63 ( struct V_100 * V_101 )
{
struct V_30 * V_31 = F_64 ( V_101 ) ;
struct V_11 * V_12 = F_20 ( V_31 ) ;
bool V_153 = true ;
int V_57 = 0 ;
switch ( V_101 -> V_8 ) {
case V_154 :
F_65 ( V_12 , V_155 ,
V_101 -> V_103 ) ;
break;
case V_156 :
F_65 ( V_12 , V_157 ,
V_101 -> V_103 ) ;
break;
case V_158 :
F_65 ( V_12 , V_159 ,
V_101 -> V_103 ) ;
break;
case V_160 :
F_65 ( V_12 , V_161 ,
V_101 -> V_103 ) ;
break;
case V_162 :
F_65 ( V_12 , V_163 ,
V_101 -> V_103 ) ;
break;
case V_164 :
F_65 ( V_12 , V_165 ,
V_101 -> V_103 ) ;
break;
case V_166 :
V_57 = F_57 ( V_12 , V_101 -> V_103 ) ;
break;
case V_167 :
V_57 = F_51 ( V_12 , V_101 -> V_103 ) ;
break;
case V_168 :
V_57 = F_53 ( V_12 , V_101 ) ;
V_153 = false ;
break;
case V_169 :
V_57 = F_55 ( V_12 , V_101 -> V_103 ) ;
break;
case V_170 :
V_57 = F_59 ( V_12 , V_101 -> V_103 ) ;
break;
case V_171 :
F_61 ( V_12 , V_101 -> V_103 ) ;
break;
default:
V_57 = - V_28 ;
break;
}
if ( V_57 < 0 ) {
F_31 ( & V_31 -> V_172 , L_11 ,
V_101 -> V_173 , V_101 -> V_103 ) ;
return V_57 ;
}
if ( V_153 && F_23 ( V_66 , & V_12 -> V_64 ) )
return F_26 ( V_12 , true ) ;
return 0 ;
}
static void F_66 ( struct V_30 * V_31 )
{
struct V_11 * V_12 = F_20 ( V_31 ) ;
V_31 -> V_42 . V_48 = V_79 +
V_55 ;
V_31 -> V_42 . V_49 = V_80 +
V_56 ;
V_31 -> V_42 . V_27 = V_54 ;
V_31 -> V_43 . V_48 = V_79 ;
V_31 -> V_43 . V_49 = V_80 ;
V_31 -> V_43 . V_27 = V_54 ;
F_21 ( V_12 , & V_31 -> V_43 ) ;
}
int F_67 ( struct V_30 * V_31 )
{
const struct V_174 * V_175 = & V_176 ;
struct V_177 * V_178 = & V_31 -> V_124 . V_178 ;
struct V_22 * V_23 = & V_31 -> V_172 ;
struct V_179 * V_124 = & V_31 -> V_124 ;
int V_57 ;
F_68 ( & V_31 -> V_40 ) ;
F_69 ( V_23 , & V_180 ) ;
V_23 -> V_181 = V_182 ;
V_23 -> V_183 = V_184 ;
V_23 -> V_21 |= V_185 ;
snprintf ( V_23 -> V_173 , sizeof( V_23 -> V_173 ) , L_12 ) ;
V_31 -> V_186 [ V_41 ] . V_21 = V_187 ;
V_31 -> V_186 [ V_44 ] . V_21 = V_188 ;
V_31 -> V_186 [ V_60 ] . V_21 = V_188 ;
V_57 = F_70 ( & V_23 -> V_17 , V_58 ,
V_31 -> V_186 , 0 ) ;
if ( V_57 )
return V_57 ;
F_71 ( V_178 , 20 ) ;
V_124 -> V_189 = F_72 ( V_178 , V_175 , V_156 ,
- 2 , 2 , 1 , 0 ) ;
V_124 -> V_190 = F_72 ( V_178 , V_175 , V_162 ,
- 4 , 4 , 1 , 0 ) ;
V_124 -> V_191 = F_72 ( V_178 , V_175 , V_154 ,
- 2 , 2 , 1 , 0 ) ;
V_124 -> V_192 = F_72 ( V_178 , V_175 , V_158 ,
- 2 , 2 , 1 , 0 ) ;
V_124 -> V_193 = F_72 ( V_178 , V_175 , V_164 ,
- 2 , 2 , 1 , 0 ) ;
V_124 -> V_194 = F_73 ( V_178 , V_175 ,
V_167 ,
8 , ~ 0x14e , V_89 ) ;
V_124 -> V_195 = F_72 ( V_178 , V_175 ,
V_160 ,
- 4 , 4 , 1 , 0 ) ;
V_124 -> V_196 = F_73 ( V_178 , V_175 ,
V_166 , 3 ,
~ 0xf , V_127 ) ;
F_73 ( V_178 , V_175 , V_170 ,
V_141 , 0 ,
V_141 ) ;
V_124 -> V_197 = F_73 ( V_178 , V_175 ,
V_169 , 1 , 0 ,
V_122 ) ;
V_124 -> V_121 = F_74 ( V_178 , V_175 ,
V_198 , F_2 ( V_125 ) - 1 ,
F_2 ( V_125 ) / 2 - 1 , V_125 ) ;
V_124 -> V_199 = F_72 ( V_178 , V_175 ,
V_168 , 0 , 0x3 , 0 , 0 ) ;
V_124 -> V_200 = F_73 ( V_178 , V_175 , V_171 ,
V_201 + 1 , ~ 0x1000f , V_144 ) ;
if ( V_178 -> error ) {
F_75 ( & V_23 -> V_17 ) ;
return V_178 -> error ;
}
F_76 ( 2 , & V_124 -> V_197 ,
V_202 , false ) ;
V_23 -> V_203 = V_178 ;
V_23 -> V_204 = & V_205 ;
V_23 -> V_17 . V_175 = & V_206 ;
F_77 ( V_23 , V_31 ) ;
F_66 ( V_31 ) ;
return 0 ;
}
void F_78 ( struct V_30 * V_31 )
{
struct V_22 * V_23 = & V_31 -> V_172 ;
F_79 ( V_23 ) ;
F_75 ( & V_23 -> V_17 ) ;
F_80 ( & V_31 -> V_124 . V_178 ) ;
F_77 ( V_23 , NULL ) ;
}
