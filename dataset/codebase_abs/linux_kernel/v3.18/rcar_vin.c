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
V_38 |= V_15 -> V_60 & V_61 ?
V_62 : V_63 ;
break;
case V_64 :
V_38 |= V_15 -> V_60 & V_61 ?
V_65 : V_66 ;
break;
default:
break;
}
switch ( V_10 -> V_55 -> V_24 -> V_67 ) {
case V_68 :
F_11 ( F_12 ( V_36 -> V_23 * V_36 -> V_27 , 0x80 ) ,
V_15 -> V_69 + V_70 ) ;
V_39 = V_71 ;
V_42 = true ;
break;
case V_72 :
V_39 = V_73 ;
V_42 = true ;
break;
case V_74 :
V_39 = 0 ;
V_42 = true ;
break;
case V_75 :
V_39 = V_76 ;
break;
case V_77 :
V_39 = 0 ;
break;
case V_78 :
if ( V_15 -> V_79 == V_80 || V_15 -> V_79 == V_81 ||
V_15 -> V_79 == V_82 ) {
V_39 = V_83 ;
break;
}
default:
F_13 ( V_10 -> V_13 , L_2 ,
V_10 -> V_55 -> V_24 -> V_67 ) ;
return - V_22 ;
}
V_38 |= V_84 ;
if ( V_42 )
V_38 |= V_85 ;
V_40 = V_41 ? V_86 | V_87 : V_87 ;
F_11 ( V_40 , V_15 -> V_69 + V_88 ) ;
F_11 ( V_40 , V_15 -> V_69 + V_89 ) ;
F_11 ( V_39 , V_15 -> V_69 + V_90 ) ;
F_11 ( V_38 | V_91 , V_15 -> V_69 + V_92 ) ;
return 0 ;
}
static void F_14 ( struct V_14 * V_15 )
{
if ( F_8 ( V_15 ) )
F_11 ( V_93 , V_15 -> V_69 + V_94 ) ;
else
F_11 ( V_95 , V_15 -> V_69 + V_94 ) ;
}
static void F_15 ( struct V_14 * V_15 )
{
V_15 -> V_96 = V_97 ;
F_11 ( 0 , V_15 -> V_69 + V_94 ) ;
F_11 ( F_16 ( V_15 -> V_69 + V_92 ) & ~ V_91 ,
V_15 -> V_69 + V_92 ) ;
if ( ! ( F_16 ( V_15 -> V_69 + V_98 ) & V_99 ) )
V_15 -> V_96 = V_100 ;
}
static int F_17 ( struct V_14 * V_15 )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < V_15 -> V_33 ; V_101 ++ )
if ( V_15 -> V_102 [ V_101 ] == NULL )
return V_101 ;
return - 1 ;
}
static int F_18 ( struct V_14 * V_15 )
{
return F_17 ( V_15 ) < 0 ? 1 : 0 ;
}
static int F_19 ( struct V_14 * V_15 )
{
struct V_103 * V_104 ;
T_1 V_105 ;
int V_101 ;
if ( F_20 ( & V_15 -> V_106 ) )
return 0 ;
V_101 = F_17 ( V_15 ) ;
if ( V_101 < 0 )
return 0 ;
V_104 = & F_21 ( V_15 -> V_106 . V_107 , struct V_108 , V_109 ) -> V_104 ;
F_22 ( F_23 ( V_104 ) ) ;
V_15 -> V_102 [ V_101 ] = V_104 ;
V_105 = F_24 ( V_104 , 0 ) ;
F_11 ( V_105 , V_15 -> V_69 + F_25 ( V_101 ) ) ;
return 1 ;
}
static void F_26 ( struct V_103 * V_104 )
{
struct V_9 * V_10 = F_2 ( V_104 -> V_1 ) ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
unsigned long V_110 ;
V_110 = V_10 -> V_28 ;
if ( F_27 ( V_104 , 0 ) < V_110 ) {
F_28 ( V_10 -> V_13 , L_3 ,
V_104 -> V_111 . V_112 , F_27 ( V_104 , 0 ) , V_110 ) ;
goto error;
}
F_29 ( V_104 , 0 , V_110 ) ;
F_9 ( V_10 -> V_13 , L_4 , V_113 ,
V_104 , F_30 ( V_104 , 0 ) , F_31 ( V_104 , 0 ) ) ;
F_32 ( & V_15 -> V_114 ) ;
F_33 ( F_23 ( V_104 ) , & V_15 -> V_106 ) ;
F_19 ( V_15 ) ;
if ( V_15 -> V_96 != V_115 && F_18 ( V_15 ) ) {
if ( F_10 ( V_15 ) ) {
F_22 ( F_23 ( V_104 ) ) ;
F_34 ( & V_15 -> V_114 ) ;
goto error;
}
V_15 -> V_116 = false ;
F_35 ( & V_15 -> V_117 ) ;
V_15 -> V_96 = V_115 ;
F_14 ( V_15 ) ;
}
F_34 ( & V_15 -> V_114 ) ;
return;
error:
F_36 ( V_104 , V_118 ) ;
}
static void F_37 ( struct V_103 * V_104 )
{
struct V_9 * V_10 = F_2 ( V_104 -> V_1 ) ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
unsigned int V_119 ;
int V_120 = 0 ;
F_32 ( & V_15 -> V_114 ) ;
for ( V_119 = 0 ; V_119 < V_34 ; V_119 ++ ) {
if ( V_15 -> V_102 [ V_119 ] == V_104 ) {
V_120 = 1 ;
break;
}
}
if ( V_120 ) {
while ( V_15 -> V_96 != V_100 ) {
if ( V_15 -> V_96 == V_115 )
F_15 ( V_15 ) ;
if ( V_15 -> V_96 == V_97 ) {
V_15 -> V_116 = true ;
F_34 ( & V_15 -> V_114 ) ;
F_38 ( & V_15 -> V_117 ) ;
F_32 ( & V_15 -> V_114 ) ;
}
}
for ( V_119 = 0 ; V_119 < V_34 ; V_119 ++ ) {
if ( V_15 -> V_102 [ V_119 ] ) {
F_36 ( V_15 -> V_102 [ V_119 ] ,
V_118 ) ;
V_15 -> V_102 [ V_119 ] = NULL ;
}
}
} else {
F_22 ( F_23 ( V_104 ) ) ;
}
F_34 ( & V_15 -> V_114 ) ;
}
static int F_39 ( struct V_103 * V_104 )
{
F_40 ( F_23 ( V_104 ) ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_121 * V_122 , * V_123 ;
F_32 ( & V_15 -> V_114 ) ;
F_42 (buf_head, tmp, &priv->capture)
F_22 ( V_122 ) ;
F_34 ( & V_15 -> V_114 ) ;
}
static T_2 F_43 ( int V_124 , void * V_125 )
{
struct V_14 * V_15 = V_125 ;
V_25 V_126 ;
bool V_127 = false , V_128 ;
int V_101 ;
unsigned int V_129 = 0 ;
F_44 ( & V_15 -> V_114 ) ;
V_126 = F_16 ( V_15 -> V_69 + V_88 ) ;
if ( ! V_126 )
goto V_130;
F_11 ( V_126 , V_15 -> V_69 + V_88 ) ;
V_129 = 1 ;
if ( V_15 -> V_96 == V_100 )
goto V_130;
V_128 = ! ( F_16 ( V_15 -> V_69 + V_98 ) & V_99 ) ;
if ( ! V_15 -> V_116 ) {
if ( F_8 ( V_15 ) )
V_101 = ( F_16 ( V_15 -> V_69 + V_98 ) &
V_131 ) >> V_132 ;
else
V_101 = 0 ;
V_15 -> V_102 [ V_101 ] -> V_111 . V_43 = V_15 -> V_43 ;
V_15 -> V_102 [ V_101 ] -> V_111 . V_31 = V_15 -> V_31 ++ ;
F_45 ( & V_15 -> V_102 [ V_101 ] -> V_111 . V_133 ) ;
F_36 ( V_15 -> V_102 [ V_101 ] , V_134 ) ;
V_15 -> V_102 [ V_101 ] = NULL ;
if ( V_15 -> V_96 != V_97 )
V_127 = F_19 ( V_15 ) ;
if ( V_128 || ! V_127 ) {
V_15 -> V_96 = V_100 ;
} else if ( F_8 ( V_15 ) &&
F_20 ( & V_15 -> V_106 ) &&
V_15 -> V_96 == V_115 ) {
F_15 ( V_15 ) ;
} else {
F_14 ( V_15 ) ;
}
} else if ( V_128 ) {
V_15 -> V_96 = V_100 ;
V_15 -> V_116 = false ;
F_46 ( & V_15 -> V_117 ) ;
}
V_130:
F_47 ( & V_15 -> V_114 ) ;
return F_48 ( V_129 ) ;
}
static int F_49 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
int V_119 ;
for ( V_119 = 0 ; V_119 < V_34 ; V_119 ++ )
V_15 -> V_102 [ V_119 ] = NULL ;
F_50 ( V_12 -> V_135 . V_136 ) ;
F_9 ( V_10 -> V_13 , L_5 ,
V_10 -> V_137 ) ;
return 0 ;
}
static void F_51 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_103 * V_104 ;
int V_119 ;
F_11 ( F_16 ( V_15 -> V_69 + V_92 ) & ~ V_91 ,
V_15 -> V_69 + V_92 ) ;
F_11 ( 0 , V_15 -> V_69 + V_89 ) ;
V_15 -> V_96 = V_100 ;
V_15 -> V_116 = false ;
F_32 ( & V_15 -> V_114 ) ;
for ( V_119 = 0 ; V_119 < V_34 ; V_119 ++ ) {
V_104 = V_15 -> V_102 [ V_119 ] ;
if ( V_104 ) {
F_22 ( F_23 ( V_104 ) ) ;
F_36 ( V_104 , V_118 ) ;
}
}
F_34 ( & V_15 -> V_114 ) ;
F_52 ( V_12 -> V_135 . V_136 ) ;
F_9 ( V_10 -> V_13 , L_6 ,
V_10 -> V_137 ) ;
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
unsigned int V_138 , V_139 ;
unsigned char V_140 = 0 ;
struct V_141 * V_142 = & V_36 -> V_143 ;
F_9 ( V_10 -> V_13 , L_7 ,
V_10 -> V_144 , V_10 -> V_145 , V_36 -> V_146 , V_36 -> V_147 ) ;
V_138 = V_36 -> V_146 ;
V_139 = V_36 -> V_147 ;
if ( V_10 -> V_55 -> V_24 -> V_67 == V_78 &&
V_15 -> V_79 == V_82 )
V_140 = 1 ;
F_9 ( V_10 -> V_13 , L_8 ,
V_36 -> V_23 , V_36 -> V_27 , V_36 -> V_146 , V_36 -> V_147 ) ;
F_9 ( V_10 -> V_13 , L_9 ,
V_142 -> V_23 , V_142 -> V_27 ,
V_142 -> V_148 , V_142 -> V_149 ) ;
F_11 ( V_138 << V_140 , V_15 -> V_69 + V_150 ) ;
F_11 ( ( V_138 + V_36 -> V_23 - 1 ) << V_140 ,
V_15 -> V_69 + V_151 ) ;
switch ( V_15 -> V_43 ) {
case V_48 :
case V_49 :
case V_51 :
F_11 ( V_139 / 2 , V_15 -> V_69 + V_152 ) ;
F_11 ( ( V_139 + V_36 -> V_27 ) / 2 - 1 ,
V_15 -> V_69 + V_153 ) ;
break;
default:
F_11 ( V_139 , V_15 -> V_69 + V_152 ) ;
F_11 ( V_139 + V_36 -> V_27 - 1 ,
V_15 -> V_69 + V_153 ) ;
break;
}
F_11 ( 0 , V_15 -> V_69 + V_154 ) ;
F_11 ( 0 , V_15 -> V_69 + V_155 ) ;
F_11 ( ( V_142 -> V_23 - 1 ) << V_140 , V_15 -> V_69 + V_156 ) ;
switch ( V_15 -> V_43 ) {
case V_48 :
case V_49 :
case V_51 :
F_11 ( V_142 -> V_27 / 2 - 1 ,
V_15 -> V_69 + V_157 ) ;
break;
default:
F_11 ( V_142 -> V_27 - 1 , V_15 -> V_69 + V_157 ) ;
break;
}
F_11 ( F_12 ( V_36 -> V_23 , 0x10 ) , V_15 -> V_69 + V_158 ) ;
return 0 ;
}
static void F_56 ( struct V_14 * V_15 , V_25 * V_38 )
{
* V_38 = F_16 ( V_15 -> V_69 + V_92 ) ;
F_11 ( * V_38 & ~ V_91 , V_15 -> V_69 + V_92 ) ;
}
static void F_57 ( struct V_14 * V_15 , V_25 V_38 )
{
unsigned long V_159 = V_160 + 10 * V_161 ;
while ( ( F_16 ( V_15 -> V_69 + V_98 ) & V_162 ) &&
F_58 ( V_160 , V_159 ) )
F_59 ( 1 ) ;
if ( F_60 ( V_160 , V_159 ) ) {
F_28 ( V_15 -> V_12 . V_135 . V_136 ,
L_10 ) ;
return;
}
F_11 ( V_38 , V_15 -> V_69 + V_92 ) ;
}
static int F_61 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_163 * V_164 = F_62 ( V_10 ) ;
struct V_165 V_166 ;
unsigned long V_167 ;
V_25 V_38 ;
V_25 V_168 ;
int V_19 ;
F_56 ( V_15 , & V_38 ) ;
V_19 = F_63 ( V_164 , V_169 , V_170 , & V_166 ) ;
if ( ! V_19 ) {
V_167 = F_64 ( & V_166 , V_171 ) ;
if ( ! V_167 ) {
F_13 ( V_10 -> V_13 ,
L_11 ,
V_166 . V_172 , V_171 ) ;
return - V_22 ;
}
} else if ( V_19 != - V_173 ) {
return V_19 ;
} else {
V_167 = V_171 ;
}
if ( ( V_167 & V_174 ) &&
( V_167 & V_175 ) ) {
if ( V_15 -> V_60 & V_176 )
V_167 &= ~ V_174 ;
else
V_167 &= ~ V_175 ;
}
if ( ( V_167 & V_177 ) &&
( V_167 & V_178 ) ) {
if ( V_15 -> V_60 & V_179 )
V_167 &= ~ V_177 ;
else
V_167 &= ~ V_178 ;
}
V_166 . V_172 = V_167 ;
V_19 = F_63 ( V_164 , V_169 , V_180 , & V_166 ) ;
if ( V_19 < 0 && V_19 != - V_173 )
return V_19 ;
V_168 = V_15 -> V_43 == V_53 ? V_181 : 0 ;
if ( ! ( V_167 & V_178 ) )
V_168 |= V_182 ;
if ( ! ( V_167 & V_175 ) )
V_168 |= V_183 ;
F_11 ( V_168 , V_15 -> V_69 + V_184 ) ;
V_19 = F_55 ( V_10 ) ;
if ( V_19 < 0 )
return V_19 ;
F_57 ( V_15 , V_38 ) ;
return 0 ;
}
static int F_65 ( struct V_9 * V_10 ,
unsigned char V_185 )
{
struct V_163 * V_164 = F_62 ( V_10 ) ;
struct V_165 V_166 ;
int V_19 ;
V_19 = F_63 ( V_164 , V_169 , V_170 , & V_166 ) ;
if ( V_19 == - V_173 )
return 0 ;
else if ( V_19 )
return V_19 ;
if ( V_185 > 24 )
return - V_22 ;
V_19 = F_64 ( & V_166 , V_171 ) ;
if ( V_19 )
return 0 ;
F_13 ( V_10 -> V_13 ,
L_11 ,
V_166 . V_172 , V_171 ) ;
return - V_22 ;
}
static bool F_66 ( const struct V_186 * V_4 )
{
return V_4 -> V_187 == V_188 ||
( V_4 -> V_189 > 8 &&
V_4 -> V_187 == V_190 ) ;
}
static int F_67 ( struct V_9 * V_10 , unsigned int V_191 ,
struct V_16 * V_17 )
{
struct V_163 * V_164 = F_62 ( V_10 ) ;
struct V_192 * V_136 = V_10 -> V_13 ;
int V_19 , V_193 , V_194 ;
int V_195 = 0 ;
struct V_35 * V_36 ;
enum V_196 V_56 ;
const struct V_186 * V_4 ;
V_19 = F_63 ( V_164 , V_169 , V_197 , V_191 , & V_56 ) ;
if ( V_19 < 0 )
return 0 ;
V_4 = F_68 ( V_56 ) ;
if ( ! V_4 ) {
F_13 ( V_136 , L_12 , V_191 , V_56 ) ;
return 0 ;
}
V_19 = F_65 ( V_10 , V_4 -> V_189 ) ;
if ( V_19 < 0 )
return 0 ;
if ( ! V_10 -> V_37 ) {
struct V_198 V_199 ;
struct V_141 V_200 ;
struct V_192 * V_136 = V_10 -> V_13 ;
int V_201 ;
V_19 = F_63 ( V_164 , V_169 , V_202 , & V_199 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_69 ( V_164 , & V_200 ) ;
if ( V_19 == - V_173 ) {
V_200 . V_148 = 0 ;
V_200 . V_149 = 0 ;
V_200 . V_23 = V_199 . V_23 ;
V_200 . V_27 = V_199 . V_27 ;
} else if ( V_19 < 0 ) {
return V_19 ;
}
for ( V_201 = 0 ; V_201 < 3 ; V_201 ++ ) {
if ( V_199 . V_23 <= V_203 &&
V_199 . V_27 <= V_204 )
break;
V_199 . V_23 = 1280 >> V_201 ;
V_199 . V_27 = 960 >> V_201 ;
V_19 = F_70 ( V_164 -> V_135 ,
F_71 ( V_10 ) ,
V_169 , V_205 ,
& V_199 ) ;
if ( V_19 < 0 )
return V_19 ;
}
if ( V_201 == 3 ) {
F_28 ( V_136 ,
L_13 ,
V_199 . V_23 , V_199 . V_27 ) ;
return - V_206 ;
}
F_9 ( V_136 , L_14 , V_199 . V_23 , V_199 . V_27 ) ;
V_36 = F_72 ( sizeof( * V_36 ) , V_207 ) ;
if ( ! V_36 )
return - V_208 ;
V_36 -> V_200 = V_200 ;
V_36 -> V_143 = V_200 ;
V_36 -> V_23 = V_199 . V_23 ;
V_36 -> V_27 = V_199 . V_27 ;
V_10 -> V_37 = V_36 ;
} else {
V_36 = V_10 -> V_37 ;
}
if ( ! V_191 )
V_36 -> V_209 = NULL ;
switch ( V_56 ) {
case V_57 :
case V_59 :
case V_64 :
if ( V_36 -> V_209 )
break;
V_36 -> V_209 = V_210 ;
V_194 = F_73 ( V_210 ) ;
V_195 += V_194 ;
for ( V_193 = 0 ; V_17 && V_193 < V_194 ; V_193 ++ , V_17 ++ ) {
V_17 -> V_24 = & V_210 [ V_193 ] ;
V_17 -> V_56 = V_56 ;
F_9 ( V_136 , L_15 ,
V_210 [ V_193 ] . V_211 , V_56 ) ;
}
break;
default:
if ( ! F_66 ( V_4 ) )
return 0 ;
F_9 ( V_136 , L_16 ,
V_4 -> V_211 ) ;
break;
}
V_195 ++ ;
if ( V_17 ) {
V_17 -> V_24 = V_4 ;
V_17 -> V_56 = V_56 ;
V_17 ++ ;
}
return V_195 ;
}
static void F_74 ( struct V_9 * V_10 )
{
F_75 ( V_10 -> V_37 ) ;
V_10 -> V_37 = NULL ;
}
static int F_76 ( struct V_9 * V_10 ,
const struct V_212 * V_213 )
{
struct V_212 V_214 = * V_213 ;
const struct V_141 * V_200 = & V_214 . V_215 ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_212 V_216 ;
struct V_35 * V_36 = V_10 -> V_37 ;
struct V_141 * V_217 = & V_216 . V_215 ;
struct V_163 * V_164 = F_62 ( V_10 ) ;
struct V_192 * V_136 = V_10 -> V_13 ;
struct V_198 V_199 ;
V_25 V_38 ;
int V_19 , V_119 ;
F_9 ( V_136 , L_17 , V_200 -> V_23 , V_200 -> V_27 ,
V_200 -> V_148 , V_200 -> V_149 ) ;
F_56 ( V_15 , & V_38 ) ;
F_9 ( V_136 , L_18 , V_38 ) ;
V_19 = F_77 ( V_164 , & V_214 , & V_216 ,
& V_36 -> V_200 , & V_36 -> V_143 ) ;
if ( V_19 < 0 )
return V_19 ;
F_9 ( V_136 , L_19 ,
V_217 -> V_23 , V_217 -> V_27 ,
V_217 -> V_148 , V_217 -> V_149 ) ;
V_19 = F_63 ( V_164 , V_169 , V_202 , & V_199 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_199 . V_23 > V_203 || V_199 . V_27 > V_204 )
return - V_22 ;
V_36 -> V_23 = V_199 . V_23 ;
V_36 -> V_27 = V_199 . V_27 ;
V_10 -> V_144 = V_36 -> V_23 ;
V_10 -> V_145 = V_36 -> V_27 ;
V_36 -> V_146 = V_200 -> V_148 & ~ 1 ;
V_36 -> V_147 = V_200 -> V_149 & ~ 1 ;
V_19 = F_55 ( V_10 ) ;
if ( V_19 < 0 )
return V_19 ;
V_36 -> V_143 = * V_200 ;
F_9 ( V_136 , L_20 ,
V_10 -> V_144 , V_10 -> V_145 ,
V_36 -> V_146 , V_36 -> V_147 ) ;
for ( V_119 = 0 ; V_119 < V_34 ; V_119 ++ ) {
if ( V_15 -> V_102 [ V_119 ] && V_15 -> V_96 == V_100 ) {
V_38 |= V_91 ;
break;
}
}
F_57 ( V_15 , V_38 ) ;
return V_19 ;
}
static int F_78 ( struct V_9 * V_10 ,
struct V_212 * V_213 )
{
struct V_35 * V_36 = V_10 -> V_37 ;
V_213 -> type = V_218 ;
V_213 -> V_215 = V_36 -> V_143 ;
return 0 ;
}
static int F_79 ( struct V_9 * V_10 ,
struct V_3 * V_219 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_163 * V_164 = F_62 ( V_10 ) ;
struct V_35 * V_36 = V_10 -> V_37 ;
struct V_220 * V_20 = & V_219 -> V_4 . V_20 ;
struct V_198 V_199 ;
struct V_192 * V_136 = V_10 -> V_13 ;
T_3 V_221 = V_20 -> V_21 ;
const struct V_16 * V_17 ;
unsigned int V_222 = 0 , V_223 = 0 ;
int V_19 ;
bool V_224 ;
enum V_225 V_43 ;
T_4 V_226 ;
F_9 ( V_136 , L_21 ,
V_221 , V_20 -> V_23 , V_20 -> V_27 ) ;
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
V_19 = F_63 ( V_164 , V_169 , V_227 , & V_226 ) ;
if ( V_19 < 0 )
V_226 = V_228 ;
V_43 = V_226 & V_228 ? V_49 :
V_51 ;
break;
}
V_17 = F_4 ( V_10 , V_221 ) ;
if ( ! V_17 ) {
F_13 ( V_136 , L_22 , V_221 ) ;
return - V_22 ;
}
F_80 ( V_10 , & V_36 -> V_200 , & V_36 -> V_143 , V_20 , & V_199 ,
12 ) ;
V_199 . V_43 = V_20 -> V_43 ;
V_199 . V_229 = V_20 -> V_229 ;
V_199 . V_56 = V_17 -> V_56 ;
switch ( V_221 ) {
case V_78 :
V_224 = V_15 -> V_79 != V_82 ;
break;
case V_74 :
case V_72 :
case V_77 :
case V_75 :
V_224 = true ;
break;
default:
V_224 = false ;
break;
}
F_9 ( V_136 , L_23 , V_199 . V_23 , V_199 . V_27 ) ;
V_19 = F_81 ( V_10 , & V_36 -> V_200 , & V_36 -> V_143 ,
& V_199 , & V_222 , & V_223 ,
V_224 , 12 ) ;
F_9 ( V_136 , L_24 ,
V_19 , V_199 . V_23 , V_199 . V_27 , V_20 -> V_23 , V_20 -> V_27 ) ;
if ( V_19 == - V_173 )
F_9 ( V_136 , L_25 ) ;
else if ( V_19 < 0 )
return V_19 ;
if ( V_199 . V_56 != V_17 -> V_56 )
return - V_22 ;
V_36 -> V_23 = V_199 . V_23 ;
V_36 -> V_27 = V_199 . V_27 ;
if ( V_20 -> V_23 > V_222 )
V_222 = V_20 -> V_23 ;
if ( V_20 -> V_27 > V_223 )
V_223 = V_20 -> V_27 ;
V_20 -> V_229 = V_199 . V_229 ;
if ( ! V_224 ) {
V_20 -> V_23 = V_222 ;
V_20 -> V_27 = V_223 ;
}
F_9 ( V_136 , L_26 ,
V_222 , V_20 -> V_23 , V_223 , V_20 -> V_27 ) ;
V_10 -> V_55 = V_17 ;
V_15 -> V_43 = V_43 ;
return 0 ;
}
static int F_82 ( struct V_9 * V_10 ,
struct V_3 * V_219 )
{
const struct V_16 * V_17 ;
struct V_220 * V_20 = & V_219 -> V_4 . V_20 ;
struct V_163 * V_164 = F_62 ( V_10 ) ;
struct V_198 V_199 ;
T_3 V_221 = V_20 -> V_21 ;
int V_23 , V_27 ;
int V_19 ;
V_17 = F_4 ( V_10 , V_221 ) ;
if ( ! V_17 ) {
V_17 = V_10 -> V_55 ;
F_9 ( V_10 -> V_13 , L_27 ,
V_221 , V_17 -> V_24 -> V_67 ) ;
V_221 = V_17 -> V_24 -> V_67 ;
V_20 -> V_21 = V_221 ;
V_20 -> V_229 = V_10 -> V_229 ;
}
F_83 ( & V_20 -> V_23 , 2 , V_203 , 1 ,
& V_20 -> V_27 , 4 , V_204 , 2 , 0 ) ;
V_23 = V_20 -> V_23 ;
V_27 = V_20 -> V_27 ;
V_20 -> V_26 = 0 ;
V_20 -> V_28 = 0 ;
V_199 . V_23 = V_20 -> V_23 ;
V_199 . V_27 = V_20 -> V_27 ;
V_199 . V_43 = V_20 -> V_43 ;
V_199 . V_56 = V_17 -> V_56 ;
V_199 . V_229 = V_20 -> V_229 ;
V_19 = F_70 ( V_164 -> V_135 , F_71 ( V_10 ) ,
V_169 , V_230 , & V_199 ) ;
if ( V_19 < 0 )
return V_19 ;
V_20 -> V_23 = V_199 . V_23 ;
V_20 -> V_27 = V_199 . V_27 ;
V_20 -> V_43 = V_199 . V_43 ;
V_20 -> V_229 = V_199 . V_229 ;
if ( V_221 == V_68 ) {
if ( V_20 -> V_23 < V_23 || V_20 -> V_27 < V_27 ) {
V_199 . V_23 = V_203 ;
V_199 . V_27 = V_204 ;
V_19 = F_70 ( V_164 -> V_135 ,
F_71 ( V_10 ) ,
V_169 , V_230 ,
& V_199 ) ;
if ( V_19 < 0 ) {
F_28 ( V_10 -> V_13 ,
L_28 , V_19 ) ;
return V_19 ;
}
}
if ( V_199 . V_23 > V_23 )
V_20 -> V_23 = V_23 ;
if ( V_199 . V_27 > V_27 )
V_20 -> V_27 = V_27 ;
}
return V_19 ;
}
static unsigned int F_84 ( struct V_231 * V_231 , T_5 * V_232 )
{
struct V_9 * V_10 = V_231 -> V_233 ;
return F_85 ( & V_10 -> V_234 , V_231 , V_232 ) ;
}
static int F_86 ( struct V_11 * V_12 ,
struct V_235 * V_236 )
{
F_87 ( V_236 -> V_237 , L_29 , sizeof( V_236 -> V_237 ) ) ;
V_236 -> V_238 = V_239 | V_240 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
V_2 -> type = V_218 ;
V_2 -> V_241 = V_242 | V_243 ;
V_2 -> V_244 = V_10 ;
V_2 -> V_245 = & V_246 ;
V_2 -> V_247 = & V_248 ;
V_2 -> V_249 = sizeof( struct V_108 ) ;
V_2 -> V_250 = V_251 ;
return F_89 ( V_2 ) ;
}
static int F_90 ( struct V_252 * V_253 )
{
const struct V_254 * V_255 = NULL ;
struct V_14 * V_15 ;
struct V_256 * V_257 ;
struct V_258 * V_259 ;
unsigned int V_60 ;
int V_124 , V_19 ;
if ( V_253 -> V_136 . V_260 ) {
struct V_261 V_262 ;
struct V_263 * V_264 ;
V_255 = F_91 ( F_92 ( V_265 ) ,
& V_253 -> V_136 ) ;
V_264 = F_93 ( V_253 -> V_136 . V_260 , NULL ) ;
if ( ! V_264 ) {
F_28 ( & V_253 -> V_136 , L_30 ) ;
return - V_22 ;
}
V_19 = F_94 ( V_264 , & V_262 ) ;
if ( V_19 ) {
F_28 ( & V_253 -> V_136 , L_31 ) ;
return V_19 ;
}
if ( V_262 . V_266 == V_267 )
V_60 = V_61 ;
else {
V_60 = 0 ;
if ( V_262 . V_268 . V_269 . V_172 & V_175 )
V_60 |= V_176 ;
if ( V_262 . V_268 . V_269 . V_172 & V_178 )
V_60 |= V_179 ;
}
F_95 ( V_264 ) ;
F_9 ( & V_253 -> V_136 , L_32 , V_60 ) ;
} else {
V_259 = V_253 -> V_136 . V_270 ;
if ( ! V_259 || ! V_259 -> V_172 ) {
F_28 ( & V_253 -> V_136 , L_33 ) ;
return - V_22 ;
}
V_60 = V_259 -> V_172 ;
}
V_257 = F_96 ( V_253 , V_271 , 0 ) ;
if ( V_257 == NULL )
return - V_22 ;
V_124 = F_97 ( V_253 , 0 ) ;
if ( V_124 <= 0 )
return - V_22 ;
V_15 = F_98 ( & V_253 -> V_136 , sizeof( struct V_14 ) ,
V_207 ) ;
if ( ! V_15 )
return - V_208 ;
V_15 -> V_69 = F_99 ( & V_253 -> V_136 , V_257 ) ;
if ( F_100 ( V_15 -> V_69 ) )
return F_101 ( V_15 -> V_69 ) ;
V_19 = F_102 ( & V_253 -> V_136 , V_124 , F_43 , V_272 ,
F_103 ( & V_253 -> V_136 ) , V_15 ) ;
if ( V_19 )
return V_19 ;
V_15 -> V_29 = F_104 ( & V_253 -> V_136 ) ;
if ( F_100 ( V_15 -> V_29 ) )
return F_101 ( V_15 -> V_29 ) ;
V_15 -> V_12 . V_15 = V_15 ;
V_15 -> V_12 . V_135 . V_136 = & V_253 -> V_136 ;
V_15 -> V_12 . V_273 = F_103 ( & V_253 -> V_136 ) ;
V_15 -> V_12 . V_245 = & V_274 ;
V_15 -> V_60 = V_60 ;
if ( ! V_255 ) {
V_15 -> V_12 . V_275 = V_253 -> V_276 ;
V_15 -> V_79 = V_253 -> V_277 -> V_278 ;
} else {
V_15 -> V_12 . V_275 = F_105 ( V_253 -> V_136 . V_260 , L_34 ) ;
V_15 -> V_79 = (enum V_279 ) V_255 -> V_125 ;
}
F_106 ( & V_15 -> V_114 ) ;
F_40 ( & V_15 -> V_106 ) ;
V_15 -> V_96 = V_100 ;
F_107 ( & V_253 -> V_136 , true ) ;
F_108 ( & V_253 -> V_136 ) ;
V_19 = F_109 ( & V_15 -> V_12 ) ;
if ( V_19 )
goto V_280;
return 0 ;
V_280:
F_110 ( & V_253 -> V_136 ) ;
F_111 ( V_15 -> V_29 ) ;
return V_19 ;
}
static int F_112 ( struct V_252 * V_253 )
{
struct V_11 * V_281 = F_3 ( & V_253 -> V_136 ) ;
struct V_14 * V_15 = F_113 ( V_281 ,
struct V_14 , V_12 ) ;
F_114 ( V_281 ) ;
F_110 ( & V_253 -> V_136 ) ;
F_111 ( V_15 -> V_29 ) ;
return 0 ;
}
