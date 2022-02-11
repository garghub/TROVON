static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int * V_5 ,
unsigned int * V_6 ,
unsigned int V_7 [] , void * V_8 [] )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
if ( V_4 ) {
const struct V_16 * V_17 ;
unsigned int V_18 ;
int V_19 ;
V_17 = F_4 ( V_10 ,
V_4 -> V_4 . V_20 . V_21 ) ;
if ( ! V_17 )
return - V_22 ;
V_19 = F_5 ( V_4 -> V_4 . V_20 . V_23 ,
V_17 -> V_24 ) ;
if ( V_19 < 0 )
return V_19 ;
V_18 = F_6 ( V_25 , V_4 -> V_4 . V_20 . V_26 , V_19 ) ;
V_19 = F_7 ( V_17 -> V_24 , V_18 ,
V_4 -> V_4 . V_20 . V_27 ) ;
if ( V_19 < 0 )
return V_19 ;
V_7 [ 0 ] = F_6 ( V_25 , V_4 -> V_4 . V_20 . V_28 , V_19 ) ;
} else {
V_7 [ 0 ] = V_10 -> V_28 ;
}
V_8 [ 0 ] = V_15 -> V_29 ;
if ( ! V_2 -> V_30 )
V_15 -> V_31 = 0 ;
if ( ! * V_5 )
* V_5 = 2 ;
V_15 -> V_32 = * V_5 ;
* V_6 = 1 ;
if ( F_8 ( V_15 ) )
V_15 -> V_33 = V_34 ;
else
V_15 -> V_33 = 1 ;
F_9 ( V_10 -> V_13 , L_1 , * V_5 , V_7 [ 0 ] ) ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_9 * V_10 = V_15 -> V_12 . V_10 ;
struct V_35 * V_36 = V_10 -> V_37 ;
V_25 V_38 , V_39 , V_40 ;
bool V_41 = false , V_42 = false ;
switch ( V_15 -> V_43 ) {
case V_44 :
V_38 = V_45 ;
break;
case V_46 :
V_38 = V_47 ;
break;
case V_48 :
case V_49 :
V_38 = V_50 ;
break;
case V_51 :
V_38 = V_50 | V_52 ;
break;
case V_53 :
if ( F_8 ( V_15 ) ) {
V_38 = V_54 ;
V_41 = true ;
} else {
V_38 = V_45 ;
}
break;
default:
V_38 = V_45 ;
break;
}
switch ( V_10 -> V_55 -> V_56 ) {
case V_57 :
V_38 |= V_58 ;
break;
case V_59 :
V_38 |= V_15 -> V_60 -> V_61 & V_62 ?
V_63 : V_64 ;
default:
break;
}
switch ( V_10 -> V_55 -> V_24 -> V_65 ) {
case V_66 :
F_11 ( F_12 ( V_36 -> V_23 * V_36 -> V_27 , 0x80 ) ,
V_15 -> V_67 + V_68 ) ;
V_39 = V_69 ;
V_42 = true ;
break;
case V_70 :
V_39 = V_71 ;
V_42 = true ;
break;
case V_72 :
V_39 = 0 ;
V_42 = true ;
break;
case V_73 :
V_39 = V_74 ;
break;
case V_75 :
V_39 = 0 ;
break;
case V_76 :
if ( V_15 -> V_77 == V_78 || V_15 -> V_77 == V_79 ||
V_15 -> V_77 == V_80 ) {
V_39 = V_81 ;
break;
}
default:
F_13 ( V_10 -> V_13 , L_2 ,
V_10 -> V_55 -> V_24 -> V_65 ) ;
return - V_22 ;
}
V_38 |= V_82 ;
if ( V_42 )
V_38 |= V_83 ;
V_40 = V_41 ? V_84 | V_85 : V_85 ;
F_11 ( V_40 , V_15 -> V_67 + V_86 ) ;
F_11 ( V_40 , V_15 -> V_67 + V_87 ) ;
F_11 ( V_39 , V_15 -> V_67 + V_88 ) ;
F_11 ( V_38 | V_89 , V_15 -> V_67 + V_90 ) ;
return 0 ;
}
static void F_14 ( struct V_14 * V_15 )
{
if ( F_8 ( V_15 ) )
F_11 ( V_91 , V_15 -> V_67 + V_92 ) ;
else
F_11 ( V_93 , V_15 -> V_67 + V_92 ) ;
}
static void F_15 ( struct V_14 * V_15 )
{
V_15 -> V_94 = V_95 ;
F_11 ( 0 , V_15 -> V_67 + V_92 ) ;
F_11 ( F_16 ( V_15 -> V_67 + V_90 ) & ~ V_89 ,
V_15 -> V_67 + V_90 ) ;
if ( ! ( F_16 ( V_15 -> V_67 + V_96 ) & V_97 ) )
V_15 -> V_94 = V_98 ;
}
static int F_17 ( struct V_14 * V_15 )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < V_15 -> V_33 ; V_99 ++ )
if ( V_15 -> V_100 [ V_99 ] == NULL )
return V_99 ;
return - 1 ;
}
static int F_18 ( struct V_14 * V_15 )
{
return F_17 ( V_15 ) < 0 ? 1 : 0 ;
}
static int F_19 ( struct V_14 * V_15 )
{
struct V_101 * V_102 ;
T_1 V_103 ;
int V_99 ;
if ( F_20 ( & V_15 -> V_104 ) )
return 0 ;
V_99 = F_17 ( V_15 ) ;
if ( V_99 < 0 )
return 0 ;
V_102 = & F_21 ( V_15 -> V_104 . V_105 , struct V_106 , V_107 ) -> V_102 ;
F_22 ( F_23 ( V_102 ) ) ;
V_15 -> V_100 [ V_99 ] = V_102 ;
V_103 = F_24 ( V_102 , 0 ) ;
F_11 ( V_103 , V_15 -> V_67 + F_25 ( V_99 ) ) ;
return 1 ;
}
static void F_26 ( struct V_101 * V_102 )
{
struct V_9 * V_10 = F_2 ( V_102 -> V_1 ) ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
unsigned long V_108 ;
V_108 = V_10 -> V_28 ;
if ( F_27 ( V_102 , 0 ) < V_108 ) {
F_28 ( V_10 -> V_13 , L_3 ,
V_102 -> V_109 . V_110 , F_27 ( V_102 , 0 ) , V_108 ) ;
goto error;
}
F_29 ( V_102 , 0 , V_108 ) ;
F_9 ( V_10 -> V_13 , L_4 , V_111 ,
V_102 , F_30 ( V_102 , 0 ) , F_31 ( V_102 , 0 ) ) ;
F_32 ( & V_15 -> V_112 ) ;
F_33 ( F_23 ( V_102 ) , & V_15 -> V_104 ) ;
F_19 ( V_15 ) ;
if ( V_15 -> V_94 != V_113 && F_18 ( V_15 ) ) {
if ( F_10 ( V_15 ) ) {
F_22 ( F_23 ( V_102 ) ) ;
F_34 ( & V_15 -> V_112 ) ;
goto error;
}
V_15 -> V_114 = false ;
F_35 ( & V_15 -> V_115 ) ;
V_15 -> V_94 = V_113 ;
F_14 ( V_15 ) ;
}
F_34 ( & V_15 -> V_112 ) ;
return;
error:
F_36 ( V_102 , V_116 ) ;
}
static void F_37 ( struct V_101 * V_102 )
{
struct V_9 * V_10 = F_2 ( V_102 -> V_1 ) ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
unsigned int V_117 ;
int V_118 = 0 ;
F_32 ( & V_15 -> V_112 ) ;
for ( V_117 = 0 ; V_117 < V_34 ; V_117 ++ ) {
if ( V_15 -> V_100 [ V_117 ] == V_102 ) {
V_118 = 1 ;
break;
}
}
if ( V_118 ) {
while ( V_15 -> V_94 != V_98 ) {
if ( V_15 -> V_94 == V_113 )
F_15 ( V_15 ) ;
if ( V_15 -> V_94 == V_95 ) {
V_15 -> V_114 = true ;
F_34 ( & V_15 -> V_112 ) ;
F_38 ( & V_15 -> V_115 ) ;
F_32 ( & V_15 -> V_112 ) ;
}
}
for ( V_117 = 0 ; V_117 < V_34 ; V_117 ++ ) {
if ( V_15 -> V_100 [ V_117 ] ) {
F_36 ( V_15 -> V_100 [ V_117 ] ,
V_116 ) ;
V_15 -> V_100 [ V_117 ] = NULL ;
}
}
} else {
F_22 ( F_23 ( V_102 ) ) ;
}
F_34 ( & V_15 -> V_112 ) ;
}
static int F_39 ( struct V_101 * V_102 )
{
F_40 ( F_23 ( V_102 ) ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_119 * V_120 , * V_121 ;
F_32 ( & V_15 -> V_112 ) ;
F_42 (buf_head, tmp, &priv->capture)
F_22 ( V_120 ) ;
F_34 ( & V_15 -> V_112 ) ;
return 0 ;
}
static T_2 F_43 ( int V_122 , void * V_123 )
{
struct V_14 * V_15 = V_123 ;
V_25 V_124 ;
bool V_125 = false , V_126 ;
int V_99 ;
unsigned int V_127 = 0 ;
F_44 ( & V_15 -> V_112 ) ;
V_124 = F_16 ( V_15 -> V_67 + V_86 ) ;
if ( ! V_124 )
goto V_128;
F_11 ( V_124 , V_15 -> V_67 + V_86 ) ;
V_127 = 1 ;
if ( V_15 -> V_94 == V_98 )
goto V_128;
V_126 = ! ( F_16 ( V_15 -> V_67 + V_96 ) & V_97 ) ;
if ( ! V_15 -> V_114 ) {
if ( F_8 ( V_15 ) )
V_99 = ( F_16 ( V_15 -> V_67 + V_96 ) &
V_129 ) >> V_130 ;
else
V_99 = 0 ;
V_15 -> V_100 [ V_99 ] -> V_109 . V_43 = V_15 -> V_43 ;
V_15 -> V_100 [ V_99 ] -> V_109 . V_31 = V_15 -> V_31 ++ ;
F_45 ( & V_15 -> V_100 [ V_99 ] -> V_109 . V_131 ) ;
F_36 ( V_15 -> V_100 [ V_99 ] , V_132 ) ;
V_15 -> V_100 [ V_99 ] = NULL ;
if ( V_15 -> V_94 != V_95 )
V_125 = F_19 ( V_15 ) ;
if ( V_126 || ! V_125 ) {
V_15 -> V_94 = V_98 ;
} else if ( F_8 ( V_15 ) &&
F_20 ( & V_15 -> V_104 ) &&
V_15 -> V_94 == V_113 ) {
F_15 ( V_15 ) ;
} else {
F_14 ( V_15 ) ;
}
} else if ( V_126 ) {
V_15 -> V_94 = V_98 ;
V_15 -> V_114 = false ;
F_46 ( & V_15 -> V_115 ) ;
}
V_128:
F_47 ( & V_15 -> V_112 ) ;
return F_48 ( V_127 ) ;
}
static int F_49 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_34 ; V_117 ++ )
V_15 -> V_100 [ V_117 ] = NULL ;
F_50 ( V_12 -> V_133 . V_134 ) ;
F_9 ( V_10 -> V_13 , L_5 ,
V_10 -> V_135 ) ;
return 0 ;
}
static void F_51 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_101 * V_102 ;
int V_117 ;
F_11 ( F_16 ( V_15 -> V_67 + V_90 ) & ~ V_89 ,
V_15 -> V_67 + V_90 ) ;
F_11 ( 0 , V_15 -> V_67 + V_87 ) ;
V_15 -> V_94 = V_98 ;
V_15 -> V_114 = false ;
F_32 ( & V_15 -> V_112 ) ;
for ( V_117 = 0 ; V_117 < V_34 ; V_117 ++ ) {
V_102 = V_15 -> V_100 [ V_117 ] ;
if ( V_102 ) {
F_22 ( F_23 ( V_102 ) ) ;
F_36 ( V_102 , V_116 ) ;
}
}
F_34 ( & V_15 -> V_112 ) ;
F_52 ( V_12 -> V_133 . V_134 ) ;
F_9 ( V_10 -> V_13 , L_6 ,
V_10 -> V_135 ) ;
}
static int F_53 ( struct V_11 * V_12 )
{
return 0 ;
}
static void F_54 ( struct V_11 * V_12 )
{
}
static int F_55 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_35 * V_36 = V_10 -> V_37 ;
struct V_14 * V_15 = V_12 -> V_15 ;
unsigned int V_136 , V_137 ;
unsigned char V_138 = 0 ;
struct V_139 * V_140 = & V_36 -> V_141 ;
F_9 ( V_10 -> V_13 , L_7 ,
V_10 -> V_142 , V_10 -> V_143 , V_36 -> V_144 , V_36 -> V_145 ) ;
V_136 = V_36 -> V_144 ;
V_137 = V_36 -> V_145 ;
if ( V_10 -> V_55 -> V_24 -> V_65 == V_76 &&
V_15 -> V_77 == V_80 )
V_138 = 1 ;
F_9 ( V_10 -> V_13 , L_8 ,
V_36 -> V_23 , V_36 -> V_27 , V_36 -> V_144 , V_36 -> V_145 ) ;
F_9 ( V_10 -> V_13 , L_9 ,
V_140 -> V_23 , V_140 -> V_27 ,
V_140 -> V_146 , V_140 -> V_147 ) ;
F_11 ( V_136 << V_138 , V_15 -> V_67 + V_148 ) ;
F_11 ( ( V_136 + V_36 -> V_23 - 1 ) << V_138 ,
V_15 -> V_67 + V_149 ) ;
switch ( V_15 -> V_43 ) {
case V_48 :
case V_49 :
case V_51 :
F_11 ( V_137 / 2 , V_15 -> V_67 + V_150 ) ;
F_11 ( ( V_137 + V_36 -> V_27 ) / 2 - 1 ,
V_15 -> V_67 + V_151 ) ;
break;
default:
F_11 ( V_137 , V_15 -> V_67 + V_150 ) ;
F_11 ( V_137 + V_36 -> V_27 - 1 ,
V_15 -> V_67 + V_151 ) ;
break;
}
F_11 ( 0 , V_15 -> V_67 + V_152 ) ;
F_11 ( 0 , V_15 -> V_67 + V_153 ) ;
F_11 ( ( V_140 -> V_23 - 1 ) << V_138 , V_15 -> V_67 + V_154 ) ;
switch ( V_15 -> V_43 ) {
case V_48 :
case V_49 :
case V_51 :
F_11 ( V_140 -> V_27 / 2 - 1 ,
V_15 -> V_67 + V_155 ) ;
break;
default:
F_11 ( V_140 -> V_27 - 1 , V_15 -> V_67 + V_155 ) ;
break;
}
F_11 ( F_12 ( V_36 -> V_23 , 0x10 ) , V_15 -> V_67 + V_156 ) ;
return 0 ;
}
static void F_56 ( struct V_14 * V_15 , V_25 * V_38 )
{
* V_38 = F_16 ( V_15 -> V_67 + V_90 ) ;
F_11 ( * V_38 & ~ V_89 , V_15 -> V_67 + V_90 ) ;
}
static void F_57 ( struct V_14 * V_15 , V_25 V_38 )
{
unsigned long V_157 = V_158 + 10 * V_159 ;
while ( ( F_16 ( V_15 -> V_67 + V_96 ) & V_160 ) &&
F_58 ( V_158 , V_157 ) )
F_59 ( 1 ) ;
if ( F_60 ( V_158 , V_157 ) ) {
F_28 ( V_15 -> V_12 . V_133 . V_134 ,
L_10 ) ;
return;
}
F_11 ( V_38 , V_15 -> V_67 + V_90 ) ;
}
static int F_61 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_161 * V_162 = F_62 ( V_10 ) ;
struct V_163 V_164 ;
unsigned long V_165 ;
V_25 V_38 ;
V_25 V_166 ;
int V_19 ;
F_56 ( V_15 , & V_38 ) ;
V_19 = F_63 ( V_162 , V_167 , V_168 , & V_164 ) ;
if ( ! V_19 ) {
V_165 = F_64 ( & V_164 , V_169 ) ;
if ( ! V_165 ) {
F_13 ( V_10 -> V_13 ,
L_11 ,
V_164 . V_61 , V_169 ) ;
return - V_22 ;
}
} else if ( V_19 != - V_170 ) {
return V_19 ;
} else {
V_165 = V_169 ;
}
if ( ( V_165 & V_171 ) &&
( V_165 & V_172 ) ) {
if ( V_15 -> V_60 -> V_61 & V_173 )
V_165 &= ~ V_171 ;
else
V_165 &= ~ V_172 ;
}
if ( ( V_165 & V_174 ) &&
( V_165 & V_175 ) ) {
if ( V_15 -> V_60 -> V_61 & V_176 )
V_165 &= ~ V_174 ;
else
V_165 &= ~ V_175 ;
}
V_164 . V_61 = V_165 ;
V_19 = F_63 ( V_162 , V_167 , V_177 , & V_164 ) ;
if ( V_19 < 0 && V_19 != - V_170 )
return V_19 ;
V_166 = V_15 -> V_43 == V_53 ? V_178 : 0 ;
if ( ! ( V_165 & V_175 ) )
V_166 |= V_179 ;
if ( ! ( V_165 & V_172 ) )
V_166 |= V_180 ;
F_11 ( V_166 , V_15 -> V_67 + V_181 ) ;
V_19 = F_55 ( V_10 ) ;
if ( V_19 < 0 )
return V_19 ;
F_57 ( V_15 , V_38 ) ;
return 0 ;
}
static int F_65 ( struct V_9 * V_10 ,
unsigned char V_182 )
{
struct V_161 * V_162 = F_62 ( V_10 ) ;
struct V_163 V_164 ;
int V_19 ;
V_19 = F_63 ( V_162 , V_167 , V_168 , & V_164 ) ;
if ( V_19 == - V_170 )
return 0 ;
else if ( V_19 )
return V_19 ;
if ( V_182 > 24 )
return - V_22 ;
V_19 = F_64 ( & V_164 , V_169 ) ;
if ( V_19 )
return 0 ;
F_13 ( V_10 -> V_13 ,
L_11 ,
V_164 . V_61 , V_169 ) ;
return - V_22 ;
}
static bool F_66 ( const struct V_183 * V_4 )
{
return V_4 -> V_184 == V_185 ||
( V_4 -> V_186 > 8 &&
V_4 -> V_184 == V_187 ) ;
}
static int F_67 ( struct V_9 * V_10 , unsigned int V_188 ,
struct V_16 * V_17 )
{
struct V_161 * V_162 = F_62 ( V_10 ) ;
struct V_189 * V_134 = V_10 -> V_13 ;
int V_19 , V_190 , V_191 ;
int V_192 = 0 ;
struct V_35 * V_36 ;
enum V_193 V_56 ;
const struct V_183 * V_4 ;
V_19 = F_63 ( V_162 , V_167 , V_194 , V_188 , & V_56 ) ;
if ( V_19 < 0 )
return 0 ;
V_4 = F_68 ( V_56 ) ;
if ( ! V_4 ) {
F_13 ( V_134 , L_12 , V_188 , V_56 ) ;
return 0 ;
}
V_19 = F_65 ( V_10 , V_4 -> V_186 ) ;
if ( V_19 < 0 )
return 0 ;
if ( ! V_10 -> V_37 ) {
struct V_195 V_196 ;
struct V_139 V_197 ;
struct V_189 * V_134 = V_10 -> V_13 ;
int V_198 ;
V_19 = F_63 ( V_162 , V_167 , V_199 , & V_196 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_69 ( V_162 , & V_197 ) ;
if ( V_19 == - V_170 ) {
V_197 . V_146 = 0 ;
V_197 . V_147 = 0 ;
V_197 . V_23 = V_196 . V_23 ;
V_197 . V_27 = V_196 . V_27 ;
} else if ( V_19 < 0 ) {
return V_19 ;
}
for ( V_198 = 0 ; V_198 < 3 ; V_198 ++ ) {
if ( V_196 . V_23 <= V_200 &&
V_196 . V_27 <= V_201 )
break;
V_196 . V_23 = 1280 >> V_198 ;
V_196 . V_27 = 960 >> V_198 ;
V_19 = F_70 ( V_162 -> V_133 ,
F_71 ( V_10 ) ,
V_167 , V_202 ,
& V_196 ) ;
if ( V_19 < 0 )
return V_19 ;
}
if ( V_198 == 3 ) {
F_28 ( V_134 ,
L_13 ,
V_196 . V_23 , V_196 . V_27 ) ;
return - V_203 ;
}
F_9 ( V_134 , L_14 , V_196 . V_23 , V_196 . V_27 ) ;
V_36 = F_72 ( sizeof( * V_36 ) , V_204 ) ;
if ( ! V_36 )
return - V_205 ;
V_36 -> V_197 = V_197 ;
V_36 -> V_141 = V_197 ;
V_36 -> V_23 = V_196 . V_23 ;
V_36 -> V_27 = V_196 . V_27 ;
V_10 -> V_37 = V_36 ;
} else {
V_36 = V_10 -> V_37 ;
}
if ( ! V_188 )
V_36 -> V_206 = NULL ;
switch ( V_56 ) {
case V_57 :
case V_59 :
if ( V_36 -> V_206 )
break;
V_36 -> V_206 = V_207 ;
V_191 = F_73 ( V_207 ) ;
V_192 += V_191 ;
for ( V_190 = 0 ; V_17 && V_190 < V_191 ; V_190 ++ , V_17 ++ ) {
V_17 -> V_24 = & V_207 [ V_190 ] ;
V_17 -> V_56 = V_56 ;
F_9 ( V_134 , L_15 ,
V_207 [ V_190 ] . V_208 , V_56 ) ;
}
break;
default:
if ( ! F_66 ( V_4 ) )
return 0 ;
F_9 ( V_134 , L_16 ,
V_4 -> V_208 ) ;
break;
}
V_192 ++ ;
if ( V_17 ) {
V_17 -> V_24 = V_4 ;
V_17 -> V_56 = V_56 ;
V_17 ++ ;
}
return V_192 ;
}
static void F_74 ( struct V_9 * V_10 )
{
F_75 ( V_10 -> V_37 ) ;
V_10 -> V_37 = NULL ;
}
static int F_76 ( struct V_9 * V_10 ,
const struct V_209 * V_210 )
{
struct V_209 V_211 = * V_210 ;
const struct V_139 * V_197 = & V_211 . V_212 ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_209 V_213 ;
struct V_35 * V_36 = V_10 -> V_37 ;
struct V_139 * V_214 = & V_213 . V_212 ;
struct V_161 * V_162 = F_62 ( V_10 ) ;
struct V_189 * V_134 = V_10 -> V_13 ;
struct V_195 V_196 ;
V_25 V_38 ;
int V_19 , V_117 ;
F_9 ( V_134 , L_17 , V_197 -> V_23 , V_197 -> V_27 ,
V_197 -> V_146 , V_197 -> V_147 ) ;
F_56 ( V_15 , & V_38 ) ;
F_9 ( V_134 , L_18 , V_38 ) ;
V_19 = F_77 ( V_162 , & V_211 , & V_213 ,
& V_36 -> V_197 , & V_36 -> V_141 ) ;
if ( V_19 < 0 )
return V_19 ;
F_9 ( V_134 , L_19 ,
V_214 -> V_23 , V_214 -> V_27 ,
V_214 -> V_146 , V_214 -> V_147 ) ;
V_19 = F_63 ( V_162 , V_167 , V_199 , & V_196 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_196 . V_23 > V_200 || V_196 . V_27 > V_201 )
return - V_22 ;
V_36 -> V_23 = V_196 . V_23 ;
V_36 -> V_27 = V_196 . V_27 ;
V_10 -> V_142 = V_36 -> V_23 ;
V_10 -> V_143 = V_36 -> V_27 ;
V_36 -> V_144 = V_197 -> V_146 & ~ 1 ;
V_36 -> V_145 = V_197 -> V_147 & ~ 1 ;
V_19 = F_55 ( V_10 ) ;
if ( V_19 < 0 )
return V_19 ;
V_36 -> V_141 = * V_197 ;
F_9 ( V_134 , L_20 ,
V_10 -> V_142 , V_10 -> V_143 ,
V_36 -> V_144 , V_36 -> V_145 ) ;
for ( V_117 = 0 ; V_117 < V_34 ; V_117 ++ ) {
if ( V_15 -> V_100 [ V_117 ] && V_15 -> V_94 == V_98 ) {
V_38 |= V_89 ;
break;
}
}
F_57 ( V_15 , V_38 ) ;
return V_19 ;
}
static int F_78 ( struct V_9 * V_10 ,
struct V_209 * V_210 )
{
struct V_35 * V_36 = V_10 -> V_37 ;
V_210 -> type = V_215 ;
V_210 -> V_212 = V_36 -> V_141 ;
return 0 ;
}
static int F_79 ( struct V_9 * V_10 ,
struct V_3 * V_216 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_161 * V_162 = F_62 ( V_10 ) ;
struct V_35 * V_36 = V_10 -> V_37 ;
struct V_217 * V_20 = & V_216 -> V_4 . V_20 ;
struct V_195 V_196 ;
struct V_189 * V_134 = V_10 -> V_13 ;
T_3 V_218 = V_20 -> V_21 ;
const struct V_16 * V_17 ;
unsigned int V_219 = 0 , V_220 = 0 ;
int V_19 ;
bool V_221 ;
enum V_222 V_43 ;
T_4 V_223 ;
F_9 ( V_134 , L_21 ,
V_218 , V_20 -> V_23 , V_20 -> V_27 ) ;
switch ( V_20 -> V_43 ) {
default:
V_20 -> V_43 = V_53 ;
case V_53 :
case V_44 :
case V_46 :
case V_49 :
case V_51 :
V_43 = V_20 -> V_43 ;
break;
case V_48 :
V_19 = F_63 ( V_162 , V_167 , V_224 , & V_223 ) ;
if ( V_19 < 0 )
V_223 = V_225 ;
V_43 = V_223 & V_225 ? V_49 :
V_51 ;
break;
}
V_17 = F_4 ( V_10 , V_218 ) ;
if ( ! V_17 ) {
F_13 ( V_134 , L_22 , V_218 ) ;
return - V_22 ;
}
F_80 ( V_10 , & V_36 -> V_197 , & V_36 -> V_141 , V_20 , & V_196 ,
12 ) ;
V_196 . V_43 = V_20 -> V_43 ;
V_196 . V_226 = V_20 -> V_226 ;
V_196 . V_56 = V_17 -> V_56 ;
switch ( V_218 ) {
case V_76 :
V_221 = V_15 -> V_77 != V_80 ;
break;
case V_72 :
case V_70 :
case V_75 :
case V_73 :
V_221 = true ;
break;
default:
V_221 = false ;
break;
}
F_9 ( V_134 , L_23 , V_196 . V_23 , V_196 . V_27 ) ;
V_19 = F_81 ( V_10 , & V_36 -> V_197 , & V_36 -> V_141 ,
& V_196 , & V_219 , & V_220 ,
V_221 , 12 ) ;
F_9 ( V_134 , L_24 ,
V_19 , V_196 . V_23 , V_196 . V_27 , V_20 -> V_23 , V_20 -> V_27 ) ;
if ( V_19 == - V_170 )
F_9 ( V_134 , L_25 ) ;
else if ( V_19 < 0 )
return V_19 ;
if ( V_196 . V_56 != V_17 -> V_56 )
return - V_22 ;
V_36 -> V_23 = V_196 . V_23 ;
V_36 -> V_27 = V_196 . V_27 ;
if ( V_20 -> V_23 > V_219 )
V_219 = V_20 -> V_23 ;
if ( V_20 -> V_27 > V_220 )
V_220 = V_20 -> V_27 ;
V_20 -> V_226 = V_196 . V_226 ;
if ( ! V_221 ) {
V_20 -> V_23 = V_219 ;
V_20 -> V_27 = V_220 ;
}
F_9 ( V_134 , L_26 ,
V_219 , V_20 -> V_23 , V_220 , V_20 -> V_27 ) ;
V_10 -> V_55 = V_17 ;
V_15 -> V_43 = V_43 ;
return 0 ;
}
static int F_82 ( struct V_9 * V_10 ,
struct V_3 * V_216 )
{
const struct V_16 * V_17 ;
struct V_217 * V_20 = & V_216 -> V_4 . V_20 ;
struct V_161 * V_162 = F_62 ( V_10 ) ;
struct V_195 V_196 ;
T_3 V_218 = V_20 -> V_21 ;
int V_23 , V_27 ;
int V_19 ;
V_17 = F_4 ( V_10 , V_218 ) ;
if ( ! V_17 ) {
V_17 = V_10 -> V_55 ;
F_9 ( V_10 -> V_13 , L_27 ,
V_218 , V_17 -> V_24 -> V_65 ) ;
V_218 = V_17 -> V_24 -> V_65 ;
V_20 -> V_21 = V_218 ;
V_20 -> V_226 = V_10 -> V_226 ;
}
F_83 ( & V_20 -> V_23 , 2 , V_200 , 1 ,
& V_20 -> V_27 , 4 , V_201 , 2 , 0 ) ;
V_23 = V_20 -> V_23 ;
V_27 = V_20 -> V_27 ;
V_20 -> V_26 = 0 ;
V_20 -> V_28 = 0 ;
V_196 . V_23 = V_20 -> V_23 ;
V_196 . V_27 = V_20 -> V_27 ;
V_196 . V_43 = V_20 -> V_43 ;
V_196 . V_56 = V_17 -> V_56 ;
V_196 . V_226 = V_20 -> V_226 ;
V_19 = F_70 ( V_162 -> V_133 , F_71 ( V_10 ) ,
V_167 , V_227 , & V_196 ) ;
if ( V_19 < 0 )
return V_19 ;
V_20 -> V_23 = V_196 . V_23 ;
V_20 -> V_27 = V_196 . V_27 ;
V_20 -> V_43 = V_196 . V_43 ;
V_20 -> V_226 = V_196 . V_226 ;
if ( V_218 == V_66 ) {
if ( V_20 -> V_23 < V_23 || V_20 -> V_27 < V_27 ) {
V_196 . V_23 = V_200 ;
V_196 . V_27 = V_201 ;
V_19 = F_70 ( V_162 -> V_133 ,
F_71 ( V_10 ) ,
V_167 , V_227 ,
& V_196 ) ;
if ( V_19 < 0 ) {
F_28 ( V_10 -> V_13 ,
L_28 , V_19 ) ;
return V_19 ;
}
}
if ( V_196 . V_23 > V_23 )
V_20 -> V_23 = V_23 ;
if ( V_196 . V_27 > V_27 )
V_20 -> V_27 = V_27 ;
}
return V_19 ;
}
static unsigned int F_84 ( struct V_228 * V_228 , T_5 * V_229 )
{
struct V_9 * V_10 = V_228 -> V_230 ;
return F_85 ( & V_10 -> V_231 , V_228 , V_229 ) ;
}
static int F_86 ( struct V_11 * V_12 ,
struct V_232 * V_233 )
{
F_87 ( V_233 -> V_234 , L_29 , sizeof( V_233 -> V_234 ) ) ;
V_233 -> V_235 = V_236 | V_237 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
V_2 -> type = V_215 ;
V_2 -> V_238 = V_239 | V_240 ;
V_2 -> V_241 = V_10 ;
V_2 -> V_242 = & V_243 ;
V_2 -> V_244 = & V_245 ;
V_2 -> V_246 = sizeof( struct V_106 ) ;
V_2 -> V_247 = V_248 ;
return F_89 ( V_2 ) ;
}
static int F_90 ( struct V_249 * V_250 )
{
struct V_14 * V_15 ;
struct V_251 * V_252 ;
struct V_253 * V_60 ;
int V_122 , V_19 ;
V_60 = V_250 -> V_134 . V_254 ;
if ( ! V_60 || ! V_60 -> V_61 ) {
F_28 ( & V_250 -> V_134 , L_30 ) ;
return - V_22 ;
}
V_252 = F_91 ( V_250 , V_255 , 0 ) ;
if ( V_252 == NULL )
return - V_22 ;
V_122 = F_92 ( V_250 , 0 ) ;
if ( V_122 <= 0 )
return - V_22 ;
V_15 = F_93 ( & V_250 -> V_134 , sizeof( struct V_14 ) ,
V_204 ) ;
if ( ! V_15 )
return - V_205 ;
V_15 -> V_67 = F_94 ( & V_250 -> V_134 , V_252 ) ;
if ( F_95 ( V_15 -> V_67 ) )
return F_96 ( V_15 -> V_67 ) ;
V_19 = F_97 ( & V_250 -> V_134 , V_122 , F_43 , V_256 ,
F_98 ( & V_250 -> V_134 ) , V_15 ) ;
if ( V_19 )
return V_19 ;
V_15 -> V_29 = F_99 ( & V_250 -> V_134 ) ;
if ( F_95 ( V_15 -> V_29 ) )
return F_96 ( V_15 -> V_29 ) ;
V_15 -> V_12 . V_15 = V_15 ;
V_15 -> V_12 . V_133 . V_134 = & V_250 -> V_134 ;
V_15 -> V_12 . V_257 = V_250 -> V_258 ;
V_15 -> V_12 . V_259 = F_98 ( & V_250 -> V_134 ) ;
V_15 -> V_12 . V_242 = & V_260 ;
V_15 -> V_60 = V_60 ;
V_15 -> V_77 = V_250 -> V_261 -> V_262 ;
F_100 ( & V_15 -> V_112 ) ;
F_40 ( & V_15 -> V_104 ) ;
V_15 -> V_94 = V_98 ;
F_101 ( & V_250 -> V_134 , true ) ;
F_102 ( & V_250 -> V_134 ) ;
V_19 = F_103 ( & V_15 -> V_12 ) ;
if ( V_19 )
goto V_263;
return 0 ;
V_263:
F_104 ( & V_250 -> V_134 ) ;
F_105 ( V_15 -> V_29 ) ;
return V_19 ;
}
static int F_106 ( struct V_249 * V_250 )
{
struct V_11 * V_264 = F_3 ( & V_250 -> V_134 ) ;
struct V_14 * V_15 = F_107 ( V_264 ,
struct V_14 , V_12 ) ;
F_108 ( V_264 ) ;
F_104 ( & V_250 -> V_134 ) ;
F_105 ( V_15 -> V_29 ) ;
return 0 ;
}
