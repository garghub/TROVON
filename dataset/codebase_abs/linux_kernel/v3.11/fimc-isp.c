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
F_7 ( & V_12 -> V_15 ) ;
}
static int F_8 ( struct V_16 * V_17 ,
const struct V_18 * V_19 ,
const struct V_18 * V_20 , T_1 V_21 )
{
return 0 ;
}
static int F_9 ( struct V_22 * V_23 ,
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
static int F_10 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_29 * V_5 )
{
struct V_30 * V_31 = F_11 ( V_23 ) ;
struct V_32 * V_33 = & V_5 -> V_34 ;
if ( V_5 -> V_35 == V_36 ) {
* V_33 = * F_12 ( V_25 , V_5 -> V_37 ) ;
return 0 ;
}
V_33 -> V_38 = V_39 ;
F_13 ( & V_31 -> V_40 ) ;
if ( V_5 -> V_37 == V_41 ) {
* V_33 = V_31 -> V_42 ;
} else {
* V_33 = V_31 -> V_43 ;
if ( V_5 -> V_37 == V_44 ) {
V_33 -> V_38 = V_45 ;
V_33 -> V_27 = V_46 ;
}
}
F_14 ( & V_31 -> V_40 ) ;
F_15 ( 1 , V_23 , L_1 , V_47 ,
V_5 -> V_37 , V_33 -> V_27 , V_33 -> V_48 , V_33 -> V_49 ) ;
return 0 ;
}
static void F_16 ( struct V_30 * V_31 ,
struct V_24 * V_25 ,
struct V_29 * V_5 )
{
struct V_32 * V_33 = & V_5 -> V_34 ;
struct V_32 * V_34 ;
V_33 -> V_38 = V_39 ;
if ( V_5 -> V_37 == V_41 ) {
F_17 ( & V_33 -> V_48 , V_50 ,
V_51 , 0 ,
& V_33 -> V_49 , V_52 ,
V_53 , 0 , 0 ) ;
V_33 -> V_27 = V_54 ;
} else {
if ( V_5 -> V_35 == V_36 )
V_34 = F_12 ( V_25 ,
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
static int F_18 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_29 * V_5 )
{
struct V_30 * V_31 = F_11 ( V_23 ) ;
struct V_11 * V_12 = F_19 ( V_31 ) ;
struct V_32 * V_33 = & V_5 -> V_34 ;
int V_57 = 0 ;
F_15 ( 1 , V_23 , L_2 ,
V_47 , V_5 -> V_37 , V_33 -> V_27 , V_33 -> V_48 , V_33 -> V_49 ) ;
F_13 ( & V_31 -> V_40 ) ;
F_16 ( V_31 , V_25 , V_5 ) ;
if ( V_5 -> V_35 == V_36 ) {
V_33 = F_12 ( V_25 , V_5 -> V_37 ) ;
* V_33 = V_5 -> V_34 ;
if ( V_5 -> V_37 == V_41 ) {
struct V_29 V_34 = * V_5 ;
unsigned int V_37 ;
for ( V_37 = V_44 ;
V_37 < V_58 ; V_37 ++ ) {
V_34 . V_37 = V_37 ;
F_16 ( V_31 , V_25 , & V_34 ) ;
V_33 = F_12 ( V_25 , V_37 ) ;
* V_33 = V_34 . V_34 ;
}
}
} else {
if ( V_23 -> V_17 . V_59 == 0 ) {
if ( V_5 -> V_37 == V_41 ) {
struct V_29 V_34 = * V_5 ;
V_31 -> V_42 = * V_33 ;
V_34 . V_37 = V_60 ;
F_16 ( V_31 , V_25 , & V_34 ) ;
V_31 -> V_43 = V_34 . V_34 ;
F_20 ( V_12 , & V_31 -> V_43 ) ;
} else {
V_31 -> V_43 = * V_33 ;
}
} else {
V_57 = - V_61 ;
}
}
F_14 ( & V_31 -> V_40 ) ;
return V_57 ;
}
static int F_21 ( struct V_22 * V_23 , int V_62 )
{
struct V_30 * V_31 = F_11 ( V_23 ) ;
struct V_11 * V_12 = F_19 ( V_31 ) ;
int V_57 ;
F_15 ( 1 , V_23 , L_3 , V_47 , V_62 ) ;
if ( ! F_22 ( V_63 , & V_12 -> V_64 ) )
return - V_61 ;
F_23 () ;
if ( V_62 ) {
if ( F_24 ( V_12 ) ) {
V_57 = F_25 ( V_12 , true ) ;
if ( V_57 < 0 )
return V_57 ;
}
F_15 ( 1 , V_23 , L_4 , V_12 -> V_65 ) ;
V_57 = F_26 ( V_12 ) ;
if ( V_57 )
return - V_28 ;
F_27 ( V_66 , & V_12 -> V_64 ) ;
F_28 ( V_12 ) ;
V_57 = F_29 ( V_12 , V_66 , 1 ,
V_67 ) ;
if ( V_57 < 0 ) {
F_30 ( V_23 , L_5 ) ;
return V_57 ;
}
} else {
F_27 ( V_68 , & V_12 -> V_64 ) ;
F_31 ( V_12 ) ;
V_57 = F_29 ( V_12 , V_68 , 1 ,
V_67 ) ;
if ( V_57 < 0 ) {
F_30 ( V_23 , L_6 ) ;
return V_57 ;
}
V_12 -> V_69 . V_70 = 0 ;
}
return 0 ;
}
static int F_32 ( struct V_22 * V_23 , int V_62 )
{
struct V_30 * V_31 = F_11 ( V_23 ) ;
struct V_11 * V_12 = F_19 ( V_31 ) ;
int V_57 = 0 ;
F_33 ( L_7 , V_62 ) ;
if ( V_62 ) {
V_57 = F_34 ( & V_12 -> V_71 -> V_72 ) ;
if ( V_57 < 0 )
return V_57 ;
F_35 ( V_73 , & V_12 -> V_64 ) ;
V_57 = F_36 ( V_12 ) ;
if ( V_57 < 0 ) {
F_30 ( V_23 , L_8 ) ;
F_37 ( & V_12 -> V_71 -> V_72 ) ;
return V_57 ;
}
F_35 ( V_74 , & V_12 -> V_64 ) ;
V_57 = F_38 ( V_12 ) ;
} else {
if ( ! F_22 ( V_73 , & V_12 -> V_64 ) ) {
F_39 ( V_12 , 0 ) ;
V_57 = F_29 ( V_12 , V_75 , 0 ,
V_67 ) ;
if ( V_57 < 0 ) {
F_30 ( V_23 , L_9 ) ;
return V_57 ;
}
}
if ( F_22 ( V_74 , & V_12 -> V_64 ) ) {
F_40 ( V_12 ) ;
V_57 = F_29 ( V_12 , V_74 , 0 ,
V_67 ) ;
if ( V_57 < 0 ) {
F_30 ( V_23 , L_10 ) ;
return V_57 ;
}
}
F_41 ( V_12 , 0 ) ;
F_42 ( & V_12 -> V_71 -> V_72 ) ;
F_27 ( V_73 , & V_12 -> V_64 ) ;
F_27 ( V_63 , & V_12 -> V_64 ) ;
V_12 -> V_64 = 0 ;
V_12 -> V_76 [ V_12 -> V_65 ] . V_77 [ 0 ] = 0 ;
V_12 -> V_76 [ V_12 -> V_65 ] . V_77 [ 1 ] = 0 ;
F_35 ( V_78 , & V_12 -> V_64 ) ;
F_43 () ;
}
return V_57 ;
}
static int F_44 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_32 V_5 ;
struct V_32 * V_34 ;
V_34 = F_12 ( V_25 , V_41 ) ;
V_5 . V_38 = V_39 ;
V_5 . V_27 = V_9 [ 0 ] . V_3 ;
V_5 . V_48 = V_79 + V_55 ;
V_5 . V_49 = V_80 + V_56 ;
V_5 . V_81 = V_82 ;
* V_34 = V_5 ;
V_34 = F_12 ( V_25 , V_44 ) ;
V_5 . V_48 = V_79 ;
V_5 . V_49 = V_80 ;
* V_34 = V_5 ;
V_34 = F_12 ( V_25 , V_60 ) ;
* V_34 = V_5 ;
return 0 ;
}
static int F_45 ( struct V_11 * V_12 , int V_83 )
{
switch ( V_83 ) {
case V_84 :
F_46 ( V_12 , V_85 , 0 ) ;
break;
case V_86 :
F_46 ( V_12 , V_87 ,
V_88 ) ;
break;
case V_89 :
F_46 ( V_12 , V_87 ,
V_90 ) ;
break;
case V_91 :
F_46 ( V_12 , V_87 ,
V_92 ) ;
break;
case V_93 :
F_46 ( V_12 , V_87 ,
V_94 ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_47 ( struct V_11 * V_12 ,
struct V_95 * V_96 )
{
bool V_97 = V_96 -> V_98 & V_99 ;
bool V_100 = V_96 -> V_98 & V_101 ;
struct V_102 * V_31 = & V_12 -> V_103 -> V_104 . V_31 ;
int V_105 , V_57 ;
V_105 = V_100 ? V_106 : V_107 ;
V_31 -> V_108 . V_105 = V_105 ;
V_31 -> V_108 . V_109 = V_110 ;
F_48 ( V_12 , V_111 ) ;
V_12 -> V_112 . V_113 = V_100 ;
F_43 () ;
V_57 = F_25 ( V_12 , false ) ;
if ( V_57 < 0 )
return V_57 ;
V_105 = V_97 ? V_106 : V_107 ;
V_31 -> V_108 . V_105 = V_105 ;
V_31 -> V_108 . V_109 = V_110 ;
F_48 ( V_12 , V_111 ) ;
V_12 -> V_112 . V_114 = V_97 ;
F_43 () ;
return F_25 ( V_12 , false ) ;
}
static int F_49 ( struct V_11 * V_12 , int V_83 )
{
unsigned int V_115 , V_116 ;
if ( V_83 == V_117 ) {
F_50 ( V_12 , V_118 , 0 ) ;
return 0 ;
}
V_115 = V_12 -> V_31 . V_119 . V_116 -> V_98 ;
if ( V_115 >= F_2 ( V_120 ) )
return - V_28 ;
V_116 = V_120 [ V_115 ] ;
F_50 ( V_12 , V_121 , V_116 ) ;
return 0 ;
}
static int F_51 ( struct V_11 * V_12 , unsigned int V_83 )
{
unsigned int V_98 ;
switch ( V_83 ) {
case V_122 :
V_98 = V_123 ;
break;
case V_124 :
V_98 = V_125 ;
break;
case V_126 :
V_98 = V_127 ;
break;
case V_128 :
V_98 = V_129 ;
break;
default:
return - V_28 ;
} ;
F_52 ( V_12 , V_130 , V_98 ) ;
return 0 ;
}
static int F_53 ( struct V_11 * V_12 , int V_83 )
{
switch ( V_83 ) {
case V_131 :
F_54 ( V_12 , V_132 , 0 ) ;
break;
case V_133 :
F_54 ( V_12 , V_134 , 50 ) ;
break;
case V_135 :
F_54 ( V_12 , V_134 , 60 ) ;
break;
case V_136 :
F_54 ( V_12 , V_137 , 0 ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_55 ( struct V_11 * V_12 , int V_83 )
{
static const T_2 V_138 [] [ 2 ] = {
{ V_139 , V_140 } ,
{ V_141 , V_142 } ,
{ V_143 , V_144 } ,
{ V_145 , V_146 } ,
{ 16 , V_147 } ,
} ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_2 ( V_138 ) ; V_7 ++ ) {
if ( V_138 [ V_7 ] [ 0 ] != V_83 )
continue;
F_56 ( V_12 , V_138 [ V_7 ] [ 1 ] ) ;
return 0 ;
}
return - V_28 ;
}
static int F_57 ( struct V_95 * V_96 )
{
struct V_30 * V_31 = F_58 ( V_96 ) ;
struct V_11 * V_12 = F_19 ( V_31 ) ;
bool V_148 = true ;
int V_57 = 0 ;
switch ( V_96 -> V_8 ) {
case V_149 :
F_59 ( V_12 , V_150 ,
V_96 -> V_98 ) ;
break;
case V_151 :
F_59 ( V_12 , V_152 ,
V_96 -> V_98 ) ;
break;
case V_153 :
F_59 ( V_12 , V_154 ,
V_96 -> V_98 ) ;
break;
case V_155 :
F_59 ( V_12 , V_156 ,
V_96 -> V_98 ) ;
break;
case V_157 :
F_59 ( V_12 , V_158 ,
V_96 -> V_98 ) ;
break;
case V_159 :
F_59 ( V_12 , V_160 ,
V_96 -> V_98 ) ;
break;
case V_161 :
V_57 = F_51 ( V_12 , V_96 -> V_98 ) ;
break;
case V_162 :
V_57 = F_45 ( V_12 , V_96 -> V_98 ) ;
break;
case V_163 :
V_57 = F_47 ( V_12 , V_96 ) ;
V_148 = false ;
break;
case V_164 :
V_57 = F_49 ( V_12 , V_96 -> V_98 ) ;
break;
case V_165 :
V_57 = F_53 ( V_12 , V_96 -> V_98 ) ;
break;
case V_166 :
F_55 ( V_12 , V_96 -> V_98 ) ;
break;
default:
V_57 = - V_28 ;
break;
}
if ( V_57 < 0 ) {
F_30 ( & V_31 -> V_167 , L_11 ,
V_96 -> V_168 , V_96 -> V_98 ) ;
return V_57 ;
}
if ( V_148 && F_22 ( V_66 , & V_12 -> V_64 ) )
return F_25 ( V_12 , true ) ;
return 0 ;
}
static void F_60 ( struct V_30 * V_31 )
{
struct V_11 * V_12 = F_19 ( V_31 ) ;
V_31 -> V_42 . V_48 = V_79 +
V_55 ;
V_31 -> V_42 . V_49 = V_80 +
V_56 ;
V_31 -> V_42 . V_27 = V_54 ;
V_31 -> V_43 . V_48 = V_79 ;
V_31 -> V_43 . V_49 = V_80 ;
V_31 -> V_43 . V_27 = V_54 ;
F_20 ( V_12 , & V_31 -> V_43 ) ;
}
int F_61 ( struct V_30 * V_31 )
{
const struct V_169 * V_170 = & V_171 ;
struct V_172 * V_173 = & V_31 -> V_119 . V_173 ;
struct V_22 * V_23 = & V_31 -> V_167 ;
struct V_174 * V_119 = & V_31 -> V_119 ;
int V_57 ;
F_62 ( & V_31 -> V_40 ) ;
F_63 ( V_23 , & V_175 ) ;
V_23 -> V_176 = V_177 ;
V_23 -> V_21 |= V_178 ;
snprintf ( V_23 -> V_168 , sizeof( V_23 -> V_168 ) , L_12 ) ;
V_31 -> V_179 [ V_41 ] . V_21 = V_180 ;
V_31 -> V_179 [ V_44 ] . V_21 = V_181 ;
V_31 -> V_179 [ V_60 ] . V_21 = V_181 ;
V_57 = F_64 ( & V_23 -> V_17 , V_58 ,
V_31 -> V_179 , 0 ) ;
if ( V_57 )
return V_57 ;
F_65 ( V_173 , 20 ) ;
V_119 -> V_182 = F_66 ( V_173 , V_170 , V_151 ,
- 2 , 2 , 1 , 0 ) ;
V_119 -> V_183 = F_66 ( V_173 , V_170 , V_157 ,
- 4 , 4 , 1 , 0 ) ;
V_119 -> V_184 = F_66 ( V_173 , V_170 , V_149 ,
- 2 , 2 , 1 , 0 ) ;
V_119 -> V_185 = F_66 ( V_173 , V_170 , V_153 ,
- 2 , 2 , 1 , 0 ) ;
V_119 -> V_186 = F_66 ( V_173 , V_170 , V_159 ,
- 2 , 2 , 1 , 0 ) ;
V_119 -> V_187 = F_67 ( V_173 , V_170 ,
V_162 ,
8 , ~ 0x14e , V_84 ) ;
V_119 -> V_188 = F_66 ( V_173 , V_170 ,
V_155 ,
- 4 , 4 , 1 , 0 ) ;
V_119 -> V_189 = F_67 ( V_173 , V_170 ,
V_161 , 3 ,
~ 0xf , V_122 ) ;
F_67 ( V_173 , V_170 , V_165 ,
V_136 , 0 ,
V_136 ) ;
V_119 -> V_190 = F_67 ( V_173 , V_170 ,
V_164 , 1 , 0 ,
V_117 ) ;
V_119 -> V_116 = F_68 ( V_173 , V_170 ,
V_191 , F_2 ( V_120 ) - 1 ,
F_2 ( V_120 ) / 2 - 1 , V_120 ) ;
V_119 -> V_192 = F_66 ( V_173 , V_170 ,
V_163 , 0 , 0x3 , 0 , 0 ) ;
V_119 -> V_193 = F_67 ( V_173 , V_170 , V_166 ,
V_194 + 1 , ~ 0x1000f , V_139 ) ;
if ( V_173 -> error ) {
F_69 ( & V_23 -> V_17 ) ;
return V_173 -> error ;
}
F_70 ( 2 , & V_119 -> V_190 ,
V_195 , false ) ;
V_23 -> V_196 = V_173 ;
V_23 -> V_197 = & V_198 ;
V_23 -> V_17 . V_170 = & V_199 ;
F_71 ( V_23 , V_31 ) ;
F_60 ( V_31 ) ;
return 0 ;
}
void F_72 ( struct V_30 * V_31 )
{
struct V_22 * V_23 = & V_31 -> V_167 ;
F_73 ( V_23 ) ;
F_69 ( & V_23 -> V_17 ) ;
F_74 ( & V_31 -> V_119 . V_173 ) ;
F_71 ( V_23 , NULL ) ;
}
