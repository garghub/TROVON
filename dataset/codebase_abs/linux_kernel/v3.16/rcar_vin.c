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
break;
case V_65 :
V_38 |= V_15 -> V_60 -> V_61 & V_62 ?
V_66 : V_67 ;
break;
default:
break;
}
switch ( V_10 -> V_55 -> V_24 -> V_68 ) {
case V_69 :
F_11 ( F_12 ( V_36 -> V_23 * V_36 -> V_27 , 0x80 ) ,
V_15 -> V_70 + V_71 ) ;
V_39 = V_72 ;
V_42 = true ;
break;
case V_73 :
V_39 = V_74 ;
V_42 = true ;
break;
case V_75 :
V_39 = 0 ;
V_42 = true ;
break;
case V_76 :
V_39 = V_77 ;
break;
case V_78 :
V_39 = 0 ;
break;
case V_79 :
if ( V_15 -> V_80 == V_81 || V_15 -> V_80 == V_82 ||
V_15 -> V_80 == V_83 ) {
V_39 = V_84 ;
break;
}
default:
F_13 ( V_10 -> V_13 , L_2 ,
V_10 -> V_55 -> V_24 -> V_68 ) ;
return - V_22 ;
}
V_38 |= V_85 ;
if ( V_42 )
V_38 |= V_86 ;
V_40 = V_41 ? V_87 | V_88 : V_88 ;
F_11 ( V_40 , V_15 -> V_70 + V_89 ) ;
F_11 ( V_40 , V_15 -> V_70 + V_90 ) ;
F_11 ( V_39 , V_15 -> V_70 + V_91 ) ;
F_11 ( V_38 | V_92 , V_15 -> V_70 + V_93 ) ;
return 0 ;
}
static void F_14 ( struct V_14 * V_15 )
{
if ( F_8 ( V_15 ) )
F_11 ( V_94 , V_15 -> V_70 + V_95 ) ;
else
F_11 ( V_96 , V_15 -> V_70 + V_95 ) ;
}
static void F_15 ( struct V_14 * V_15 )
{
V_15 -> V_97 = V_98 ;
F_11 ( 0 , V_15 -> V_70 + V_95 ) ;
F_11 ( F_16 ( V_15 -> V_70 + V_93 ) & ~ V_92 ,
V_15 -> V_70 + V_93 ) ;
if ( ! ( F_16 ( V_15 -> V_70 + V_99 ) & V_100 ) )
V_15 -> V_97 = V_101 ;
}
static int F_17 ( struct V_14 * V_15 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_15 -> V_33 ; V_102 ++ )
if ( V_15 -> V_103 [ V_102 ] == NULL )
return V_102 ;
return - 1 ;
}
static int F_18 ( struct V_14 * V_15 )
{
return F_17 ( V_15 ) < 0 ? 1 : 0 ;
}
static int F_19 ( struct V_14 * V_15 )
{
struct V_104 * V_105 ;
T_1 V_106 ;
int V_102 ;
if ( F_20 ( & V_15 -> V_107 ) )
return 0 ;
V_102 = F_17 ( V_15 ) ;
if ( V_102 < 0 )
return 0 ;
V_105 = & F_21 ( V_15 -> V_107 . V_108 , struct V_109 , V_110 ) -> V_105 ;
F_22 ( F_23 ( V_105 ) ) ;
V_15 -> V_103 [ V_102 ] = V_105 ;
V_106 = F_24 ( V_105 , 0 ) ;
F_11 ( V_106 , V_15 -> V_70 + F_25 ( V_102 ) ) ;
return 1 ;
}
static void F_26 ( struct V_104 * V_105 )
{
struct V_9 * V_10 = F_2 ( V_105 -> V_1 ) ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
unsigned long V_111 ;
V_111 = V_10 -> V_28 ;
if ( F_27 ( V_105 , 0 ) < V_111 ) {
F_28 ( V_10 -> V_13 , L_3 ,
V_105 -> V_112 . V_113 , F_27 ( V_105 , 0 ) , V_111 ) ;
goto error;
}
F_29 ( V_105 , 0 , V_111 ) ;
F_9 ( V_10 -> V_13 , L_4 , V_114 ,
V_105 , F_30 ( V_105 , 0 ) , F_31 ( V_105 , 0 ) ) ;
F_32 ( & V_15 -> V_115 ) ;
F_33 ( F_23 ( V_105 ) , & V_15 -> V_107 ) ;
F_19 ( V_15 ) ;
if ( V_15 -> V_97 != V_116 && F_18 ( V_15 ) ) {
if ( F_10 ( V_15 ) ) {
F_22 ( F_23 ( V_105 ) ) ;
F_34 ( & V_15 -> V_115 ) ;
goto error;
}
V_15 -> V_117 = false ;
F_35 ( & V_15 -> V_118 ) ;
V_15 -> V_97 = V_116 ;
F_14 ( V_15 ) ;
}
F_34 ( & V_15 -> V_115 ) ;
return;
error:
F_36 ( V_105 , V_119 ) ;
}
static void F_37 ( struct V_104 * V_105 )
{
struct V_9 * V_10 = F_2 ( V_105 -> V_1 ) ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
unsigned int V_120 ;
int V_121 = 0 ;
F_32 ( & V_15 -> V_115 ) ;
for ( V_120 = 0 ; V_120 < V_34 ; V_120 ++ ) {
if ( V_15 -> V_103 [ V_120 ] == V_105 ) {
V_121 = 1 ;
break;
}
}
if ( V_121 ) {
while ( V_15 -> V_97 != V_101 ) {
if ( V_15 -> V_97 == V_116 )
F_15 ( V_15 ) ;
if ( V_15 -> V_97 == V_98 ) {
V_15 -> V_117 = true ;
F_34 ( & V_15 -> V_115 ) ;
F_38 ( & V_15 -> V_118 ) ;
F_32 ( & V_15 -> V_115 ) ;
}
}
for ( V_120 = 0 ; V_120 < V_34 ; V_120 ++ ) {
if ( V_15 -> V_103 [ V_120 ] ) {
F_36 ( V_15 -> V_103 [ V_120 ] ,
V_119 ) ;
V_15 -> V_103 [ V_120 ] = NULL ;
}
}
} else {
F_22 ( F_23 ( V_105 ) ) ;
}
F_34 ( & V_15 -> V_115 ) ;
}
static int F_39 ( struct V_104 * V_105 )
{
F_40 ( F_23 ( V_105 ) ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_122 * V_123 , * V_124 ;
F_32 ( & V_15 -> V_115 ) ;
F_42 (buf_head, tmp, &priv->capture)
F_22 ( V_123 ) ;
F_34 ( & V_15 -> V_115 ) ;
}
static T_2 F_43 ( int V_125 , void * V_126 )
{
struct V_14 * V_15 = V_126 ;
V_25 V_127 ;
bool V_128 = false , V_129 ;
int V_102 ;
unsigned int V_130 = 0 ;
F_44 ( & V_15 -> V_115 ) ;
V_127 = F_16 ( V_15 -> V_70 + V_89 ) ;
if ( ! V_127 )
goto V_131;
F_11 ( V_127 , V_15 -> V_70 + V_89 ) ;
V_130 = 1 ;
if ( V_15 -> V_97 == V_101 )
goto V_131;
V_129 = ! ( F_16 ( V_15 -> V_70 + V_99 ) & V_100 ) ;
if ( ! V_15 -> V_117 ) {
if ( F_8 ( V_15 ) )
V_102 = ( F_16 ( V_15 -> V_70 + V_99 ) &
V_132 ) >> V_133 ;
else
V_102 = 0 ;
V_15 -> V_103 [ V_102 ] -> V_112 . V_43 = V_15 -> V_43 ;
V_15 -> V_103 [ V_102 ] -> V_112 . V_31 = V_15 -> V_31 ++ ;
F_45 ( & V_15 -> V_103 [ V_102 ] -> V_112 . V_134 ) ;
F_36 ( V_15 -> V_103 [ V_102 ] , V_135 ) ;
V_15 -> V_103 [ V_102 ] = NULL ;
if ( V_15 -> V_97 != V_98 )
V_128 = F_19 ( V_15 ) ;
if ( V_129 || ! V_128 ) {
V_15 -> V_97 = V_101 ;
} else if ( F_8 ( V_15 ) &&
F_20 ( & V_15 -> V_107 ) &&
V_15 -> V_97 == V_116 ) {
F_15 ( V_15 ) ;
} else {
F_14 ( V_15 ) ;
}
} else if ( V_129 ) {
V_15 -> V_97 = V_101 ;
V_15 -> V_117 = false ;
F_46 ( & V_15 -> V_118 ) ;
}
V_131:
F_47 ( & V_15 -> V_115 ) ;
return F_48 ( V_130 ) ;
}
static int F_49 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < V_34 ; V_120 ++ )
V_15 -> V_103 [ V_120 ] = NULL ;
F_50 ( V_12 -> V_136 . V_137 ) ;
F_9 ( V_10 -> V_13 , L_5 ,
V_10 -> V_138 ) ;
return 0 ;
}
static void F_51 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_104 * V_105 ;
int V_120 ;
F_11 ( F_16 ( V_15 -> V_70 + V_93 ) & ~ V_92 ,
V_15 -> V_70 + V_93 ) ;
F_11 ( 0 , V_15 -> V_70 + V_90 ) ;
V_15 -> V_97 = V_101 ;
V_15 -> V_117 = false ;
F_32 ( & V_15 -> V_115 ) ;
for ( V_120 = 0 ; V_120 < V_34 ; V_120 ++ ) {
V_105 = V_15 -> V_103 [ V_120 ] ;
if ( V_105 ) {
F_22 ( F_23 ( V_105 ) ) ;
F_36 ( V_105 , V_119 ) ;
}
}
F_34 ( & V_15 -> V_115 ) ;
F_52 ( V_12 -> V_136 . V_137 ) ;
F_9 ( V_10 -> V_13 , L_6 ,
V_10 -> V_138 ) ;
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
unsigned int V_139 , V_140 ;
unsigned char V_141 = 0 ;
struct V_142 * V_143 = & V_36 -> V_144 ;
F_9 ( V_10 -> V_13 , L_7 ,
V_10 -> V_145 , V_10 -> V_146 , V_36 -> V_147 , V_36 -> V_148 ) ;
V_139 = V_36 -> V_147 ;
V_140 = V_36 -> V_148 ;
if ( V_10 -> V_55 -> V_24 -> V_68 == V_79 &&
V_15 -> V_80 == V_83 )
V_141 = 1 ;
F_9 ( V_10 -> V_13 , L_8 ,
V_36 -> V_23 , V_36 -> V_27 , V_36 -> V_147 , V_36 -> V_148 ) ;
F_9 ( V_10 -> V_13 , L_9 ,
V_143 -> V_23 , V_143 -> V_27 ,
V_143 -> V_149 , V_143 -> V_150 ) ;
F_11 ( V_139 << V_141 , V_15 -> V_70 + V_151 ) ;
F_11 ( ( V_139 + V_36 -> V_23 - 1 ) << V_141 ,
V_15 -> V_70 + V_152 ) ;
switch ( V_15 -> V_43 ) {
case V_48 :
case V_49 :
case V_51 :
F_11 ( V_140 / 2 , V_15 -> V_70 + V_153 ) ;
F_11 ( ( V_140 + V_36 -> V_27 ) / 2 - 1 ,
V_15 -> V_70 + V_154 ) ;
break;
default:
F_11 ( V_140 , V_15 -> V_70 + V_153 ) ;
F_11 ( V_140 + V_36 -> V_27 - 1 ,
V_15 -> V_70 + V_154 ) ;
break;
}
F_11 ( 0 , V_15 -> V_70 + V_155 ) ;
F_11 ( 0 , V_15 -> V_70 + V_156 ) ;
F_11 ( ( V_143 -> V_23 - 1 ) << V_141 , V_15 -> V_70 + V_157 ) ;
switch ( V_15 -> V_43 ) {
case V_48 :
case V_49 :
case V_51 :
F_11 ( V_143 -> V_27 / 2 - 1 ,
V_15 -> V_70 + V_158 ) ;
break;
default:
F_11 ( V_143 -> V_27 - 1 , V_15 -> V_70 + V_158 ) ;
break;
}
F_11 ( F_12 ( V_36 -> V_23 , 0x10 ) , V_15 -> V_70 + V_159 ) ;
return 0 ;
}
static void F_56 ( struct V_14 * V_15 , V_25 * V_38 )
{
* V_38 = F_16 ( V_15 -> V_70 + V_93 ) ;
F_11 ( * V_38 & ~ V_92 , V_15 -> V_70 + V_93 ) ;
}
static void F_57 ( struct V_14 * V_15 , V_25 V_38 )
{
unsigned long V_160 = V_161 + 10 * V_162 ;
while ( ( F_16 ( V_15 -> V_70 + V_99 ) & V_163 ) &&
F_58 ( V_161 , V_160 ) )
F_59 ( 1 ) ;
if ( F_60 ( V_161 , V_160 ) ) {
F_28 ( V_15 -> V_12 . V_136 . V_137 ,
L_10 ) ;
return;
}
F_11 ( V_38 , V_15 -> V_70 + V_93 ) ;
}
static int F_61 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_164 * V_165 = F_62 ( V_10 ) ;
struct V_166 V_167 ;
unsigned long V_168 ;
V_25 V_38 ;
V_25 V_169 ;
int V_19 ;
F_56 ( V_15 , & V_38 ) ;
V_19 = F_63 ( V_165 , V_170 , V_171 , & V_167 ) ;
if ( ! V_19 ) {
V_168 = F_64 ( & V_167 , V_172 ) ;
if ( ! V_168 ) {
F_13 ( V_10 -> V_13 ,
L_11 ,
V_167 . V_61 , V_172 ) ;
return - V_22 ;
}
} else if ( V_19 != - V_173 ) {
return V_19 ;
} else {
V_168 = V_172 ;
}
if ( ( V_168 & V_174 ) &&
( V_168 & V_175 ) ) {
if ( V_15 -> V_60 -> V_61 & V_176 )
V_168 &= ~ V_174 ;
else
V_168 &= ~ V_175 ;
}
if ( ( V_168 & V_177 ) &&
( V_168 & V_178 ) ) {
if ( V_15 -> V_60 -> V_61 & V_179 )
V_168 &= ~ V_177 ;
else
V_168 &= ~ V_178 ;
}
V_167 . V_61 = V_168 ;
V_19 = F_63 ( V_165 , V_170 , V_180 , & V_167 ) ;
if ( V_19 < 0 && V_19 != - V_173 )
return V_19 ;
V_169 = V_15 -> V_43 == V_53 ? V_181 : 0 ;
if ( ! ( V_168 & V_178 ) )
V_169 |= V_182 ;
if ( ! ( V_168 & V_175 ) )
V_169 |= V_183 ;
F_11 ( V_169 , V_15 -> V_70 + V_184 ) ;
V_19 = F_55 ( V_10 ) ;
if ( V_19 < 0 )
return V_19 ;
F_57 ( V_15 , V_38 ) ;
return 0 ;
}
static int F_65 ( struct V_9 * V_10 ,
unsigned char V_185 )
{
struct V_164 * V_165 = F_62 ( V_10 ) ;
struct V_166 V_167 ;
int V_19 ;
V_19 = F_63 ( V_165 , V_170 , V_171 , & V_167 ) ;
if ( V_19 == - V_173 )
return 0 ;
else if ( V_19 )
return V_19 ;
if ( V_185 > 24 )
return - V_22 ;
V_19 = F_64 ( & V_167 , V_172 ) ;
if ( V_19 )
return 0 ;
F_13 ( V_10 -> V_13 ,
L_11 ,
V_167 . V_61 , V_172 ) ;
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
struct V_164 * V_165 = F_62 ( V_10 ) ;
struct V_192 * V_137 = V_10 -> V_13 ;
int V_19 , V_193 , V_194 ;
int V_195 = 0 ;
struct V_35 * V_36 ;
enum V_196 V_56 ;
const struct V_186 * V_4 ;
V_19 = F_63 ( V_165 , V_170 , V_197 , V_191 , & V_56 ) ;
if ( V_19 < 0 )
return 0 ;
V_4 = F_68 ( V_56 ) ;
if ( ! V_4 ) {
F_13 ( V_137 , L_12 , V_191 , V_56 ) ;
return 0 ;
}
V_19 = F_65 ( V_10 , V_4 -> V_189 ) ;
if ( V_19 < 0 )
return 0 ;
if ( ! V_10 -> V_37 ) {
struct V_198 V_199 ;
struct V_142 V_200 ;
struct V_192 * V_137 = V_10 -> V_13 ;
int V_201 ;
V_19 = F_63 ( V_165 , V_170 , V_202 , & V_199 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_69 ( V_165 , & V_200 ) ;
if ( V_19 == - V_173 ) {
V_200 . V_149 = 0 ;
V_200 . V_150 = 0 ;
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
V_19 = F_70 ( V_165 -> V_136 ,
F_71 ( V_10 ) ,
V_170 , V_205 ,
& V_199 ) ;
if ( V_19 < 0 )
return V_19 ;
}
if ( V_201 == 3 ) {
F_28 ( V_137 ,
L_13 ,
V_199 . V_23 , V_199 . V_27 ) ;
return - V_206 ;
}
F_9 ( V_137 , L_14 , V_199 . V_23 , V_199 . V_27 ) ;
V_36 = F_72 ( sizeof( * V_36 ) , V_207 ) ;
if ( ! V_36 )
return - V_208 ;
V_36 -> V_200 = V_200 ;
V_36 -> V_144 = V_200 ;
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
case V_65 :
if ( V_36 -> V_209 )
break;
V_36 -> V_209 = V_210 ;
V_194 = F_73 ( V_210 ) ;
V_195 += V_194 ;
for ( V_193 = 0 ; V_17 && V_193 < V_194 ; V_193 ++ , V_17 ++ ) {
V_17 -> V_24 = & V_210 [ V_193 ] ;
V_17 -> V_56 = V_56 ;
F_9 ( V_137 , L_15 ,
V_210 [ V_193 ] . V_211 , V_56 ) ;
}
break;
default:
if ( ! F_66 ( V_4 ) )
return 0 ;
F_9 ( V_137 , L_16 ,
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
const struct V_142 * V_200 = & V_214 . V_215 ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_212 V_216 ;
struct V_35 * V_36 = V_10 -> V_37 ;
struct V_142 * V_217 = & V_216 . V_215 ;
struct V_164 * V_165 = F_62 ( V_10 ) ;
struct V_192 * V_137 = V_10 -> V_13 ;
struct V_198 V_199 ;
V_25 V_38 ;
int V_19 , V_120 ;
F_9 ( V_137 , L_17 , V_200 -> V_23 , V_200 -> V_27 ,
V_200 -> V_149 , V_200 -> V_150 ) ;
F_56 ( V_15 , & V_38 ) ;
F_9 ( V_137 , L_18 , V_38 ) ;
V_19 = F_77 ( V_165 , & V_214 , & V_216 ,
& V_36 -> V_200 , & V_36 -> V_144 ) ;
if ( V_19 < 0 )
return V_19 ;
F_9 ( V_137 , L_19 ,
V_217 -> V_23 , V_217 -> V_27 ,
V_217 -> V_149 , V_217 -> V_150 ) ;
V_19 = F_63 ( V_165 , V_170 , V_202 , & V_199 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_199 . V_23 > V_203 || V_199 . V_27 > V_204 )
return - V_22 ;
V_36 -> V_23 = V_199 . V_23 ;
V_36 -> V_27 = V_199 . V_27 ;
V_10 -> V_145 = V_36 -> V_23 ;
V_10 -> V_146 = V_36 -> V_27 ;
V_36 -> V_147 = V_200 -> V_149 & ~ 1 ;
V_36 -> V_148 = V_200 -> V_150 & ~ 1 ;
V_19 = F_55 ( V_10 ) ;
if ( V_19 < 0 )
return V_19 ;
V_36 -> V_144 = * V_200 ;
F_9 ( V_137 , L_20 ,
V_10 -> V_145 , V_10 -> V_146 ,
V_36 -> V_147 , V_36 -> V_148 ) ;
for ( V_120 = 0 ; V_120 < V_34 ; V_120 ++ ) {
if ( V_15 -> V_103 [ V_120 ] && V_15 -> V_97 == V_101 ) {
V_38 |= V_92 ;
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
V_213 -> V_215 = V_36 -> V_144 ;
return 0 ;
}
static int F_79 ( struct V_9 * V_10 ,
struct V_3 * V_219 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_164 * V_165 = F_62 ( V_10 ) ;
struct V_35 * V_36 = V_10 -> V_37 ;
struct V_220 * V_20 = & V_219 -> V_4 . V_20 ;
struct V_198 V_199 ;
struct V_192 * V_137 = V_10 -> V_13 ;
T_3 V_221 = V_20 -> V_21 ;
const struct V_16 * V_17 ;
unsigned int V_222 = 0 , V_223 = 0 ;
int V_19 ;
bool V_224 ;
enum V_225 V_43 ;
T_4 V_226 ;
F_9 ( V_137 , L_21 ,
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
V_19 = F_63 ( V_165 , V_170 , V_227 , & V_226 ) ;
if ( V_19 < 0 )
V_226 = V_228 ;
V_43 = V_226 & V_228 ? V_49 :
V_51 ;
break;
}
V_17 = F_4 ( V_10 , V_221 ) ;
if ( ! V_17 ) {
F_13 ( V_137 , L_22 , V_221 ) ;
return - V_22 ;
}
F_80 ( V_10 , & V_36 -> V_200 , & V_36 -> V_144 , V_20 , & V_199 ,
12 ) ;
V_199 . V_43 = V_20 -> V_43 ;
V_199 . V_229 = V_20 -> V_229 ;
V_199 . V_56 = V_17 -> V_56 ;
switch ( V_221 ) {
case V_79 :
V_224 = V_15 -> V_80 != V_83 ;
break;
case V_75 :
case V_73 :
case V_78 :
case V_76 :
V_224 = true ;
break;
default:
V_224 = false ;
break;
}
F_9 ( V_137 , L_23 , V_199 . V_23 , V_199 . V_27 ) ;
V_19 = F_81 ( V_10 , & V_36 -> V_200 , & V_36 -> V_144 ,
& V_199 , & V_222 , & V_223 ,
V_224 , 12 ) ;
F_9 ( V_137 , L_24 ,
V_19 , V_199 . V_23 , V_199 . V_27 , V_20 -> V_23 , V_20 -> V_27 ) ;
if ( V_19 == - V_173 )
F_9 ( V_137 , L_25 ) ;
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
F_9 ( V_137 , L_26 ,
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
struct V_164 * V_165 = F_62 ( V_10 ) ;
struct V_198 V_199 ;
T_3 V_221 = V_20 -> V_21 ;
int V_23 , V_27 ;
int V_19 ;
V_17 = F_4 ( V_10 , V_221 ) ;
if ( ! V_17 ) {
V_17 = V_10 -> V_55 ;
F_9 ( V_10 -> V_13 , L_27 ,
V_221 , V_17 -> V_24 -> V_68 ) ;
V_221 = V_17 -> V_24 -> V_68 ;
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
V_19 = F_70 ( V_165 -> V_136 , F_71 ( V_10 ) ,
V_170 , V_230 , & V_199 ) ;
if ( V_19 < 0 )
return V_19 ;
V_20 -> V_23 = V_199 . V_23 ;
V_20 -> V_27 = V_199 . V_27 ;
V_20 -> V_43 = V_199 . V_43 ;
V_20 -> V_229 = V_199 . V_229 ;
if ( V_221 == V_69 ) {
if ( V_20 -> V_23 < V_23 || V_20 -> V_27 < V_27 ) {
V_199 . V_23 = V_203 ;
V_199 . V_27 = V_204 ;
V_19 = F_70 ( V_165 -> V_136 ,
F_71 ( V_10 ) ,
V_170 , V_230 ,
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
V_2 -> V_249 = sizeof( struct V_109 ) ;
V_2 -> V_250 = V_251 ;
return F_89 ( V_2 ) ;
}
static int F_90 ( struct V_252 * V_253 )
{
struct V_14 * V_15 ;
struct V_254 * V_255 ;
struct V_256 * V_60 ;
int V_125 , V_19 ;
V_60 = V_253 -> V_137 . V_257 ;
if ( ! V_60 || ! V_60 -> V_61 ) {
F_28 ( & V_253 -> V_137 , L_30 ) ;
return - V_22 ;
}
V_255 = F_91 ( V_253 , V_258 , 0 ) ;
if ( V_255 == NULL )
return - V_22 ;
V_125 = F_92 ( V_253 , 0 ) ;
if ( V_125 <= 0 )
return - V_22 ;
V_15 = F_93 ( & V_253 -> V_137 , sizeof( struct V_14 ) ,
V_207 ) ;
if ( ! V_15 )
return - V_208 ;
V_15 -> V_70 = F_94 ( & V_253 -> V_137 , V_255 ) ;
if ( F_95 ( V_15 -> V_70 ) )
return F_96 ( V_15 -> V_70 ) ;
V_19 = F_97 ( & V_253 -> V_137 , V_125 , F_43 , V_259 ,
F_98 ( & V_253 -> V_137 ) , V_15 ) ;
if ( V_19 )
return V_19 ;
V_15 -> V_29 = F_99 ( & V_253 -> V_137 ) ;
if ( F_95 ( V_15 -> V_29 ) )
return F_96 ( V_15 -> V_29 ) ;
V_15 -> V_12 . V_15 = V_15 ;
V_15 -> V_12 . V_136 . V_137 = & V_253 -> V_137 ;
V_15 -> V_12 . V_260 = V_253 -> V_261 ;
V_15 -> V_12 . V_262 = F_98 ( & V_253 -> V_137 ) ;
V_15 -> V_12 . V_245 = & V_263 ;
V_15 -> V_60 = V_60 ;
V_15 -> V_80 = V_253 -> V_264 -> V_265 ;
F_100 ( & V_15 -> V_115 ) ;
F_40 ( & V_15 -> V_107 ) ;
V_15 -> V_97 = V_101 ;
F_101 ( & V_253 -> V_137 , true ) ;
F_102 ( & V_253 -> V_137 ) ;
V_19 = F_103 ( & V_15 -> V_12 ) ;
if ( V_19 )
goto V_266;
return 0 ;
V_266:
F_104 ( & V_253 -> V_137 ) ;
F_105 ( V_15 -> V_29 ) ;
return V_19 ;
}
static int F_106 ( struct V_252 * V_253 )
{
struct V_11 * V_267 = F_3 ( & V_253 -> V_137 ) ;
struct V_14 * V_15 = F_107 ( V_267 ,
struct V_14 , V_12 ) ;
F_108 ( V_267 ) ;
F_104 ( & V_253 -> V_137 ) ;
F_105 ( V_15 -> V_29 ) ;
return 0 ;
}
