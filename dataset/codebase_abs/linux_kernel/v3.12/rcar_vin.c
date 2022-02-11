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
if ( V_15 -> V_77 == V_78 || V_15 -> V_77 == V_79 ) {
V_39 = V_80 ;
break;
}
default:
F_13 ( V_10 -> V_13 , L_2 ,
V_10 -> V_55 -> V_24 -> V_65 ) ;
return - V_22 ;
}
V_38 |= V_81 ;
if ( V_42 )
V_38 |= V_82 ;
V_40 = V_41 ? V_83 | V_84 : V_84 ;
F_11 ( V_40 , V_15 -> V_67 + V_85 ) ;
F_11 ( V_40 , V_15 -> V_67 + V_86 ) ;
F_11 ( V_39 , V_15 -> V_67 + V_87 ) ;
F_11 ( V_38 | V_88 , V_15 -> V_67 + V_89 ) ;
return 0 ;
}
static void F_14 ( struct V_14 * V_15 )
{
if ( F_8 ( V_15 ) )
F_11 ( V_90 , V_15 -> V_67 + V_91 ) ;
else
F_11 ( V_92 , V_15 -> V_67 + V_91 ) ;
}
static void F_15 ( struct V_14 * V_15 )
{
V_15 -> V_93 = V_94 ;
F_11 ( 0 , V_15 -> V_67 + V_91 ) ;
F_11 ( F_16 ( V_15 -> V_67 + V_89 ) & ~ V_88 ,
V_15 -> V_67 + V_89 ) ;
if ( ! ( F_16 ( V_15 -> V_67 + V_95 ) & V_96 ) )
V_15 -> V_93 = V_97 ;
}
static int F_17 ( struct V_14 * V_15 )
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_15 -> V_33 ; V_98 ++ )
if ( V_15 -> V_99 [ V_98 ] == NULL )
return V_98 ;
return - 1 ;
}
static int F_18 ( struct V_14 * V_15 )
{
return F_17 ( V_15 ) < 0 ? 1 : 0 ;
}
static int F_19 ( struct V_14 * V_15 )
{
struct V_100 * V_101 ;
T_1 V_102 ;
int V_98 ;
if ( F_20 ( & V_15 -> V_103 ) )
return 0 ;
V_98 = F_17 ( V_15 ) ;
if ( V_98 < 0 )
return 0 ;
V_101 = & F_21 ( V_15 -> V_103 . V_104 , struct V_105 , V_106 ) -> V_101 ;
F_22 ( F_23 ( V_101 ) ) ;
V_15 -> V_99 [ V_98 ] = V_101 ;
V_102 = F_24 ( V_101 , 0 ) ;
F_11 ( V_102 , V_15 -> V_67 + F_25 ( V_98 ) ) ;
return 1 ;
}
static void F_26 ( struct V_100 * V_101 )
{
struct V_9 * V_10 = F_2 ( V_101 -> V_1 ) ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
unsigned long V_107 ;
V_107 = V_10 -> V_28 ;
if ( F_27 ( V_101 , 0 ) < V_107 ) {
F_28 ( V_10 -> V_13 , L_3 ,
V_101 -> V_108 . V_109 , F_27 ( V_101 , 0 ) , V_107 ) ;
goto error;
}
F_29 ( V_101 , 0 , V_107 ) ;
F_9 ( V_10 -> V_13 , L_4 , V_110 ,
V_101 , F_30 ( V_101 , 0 ) , F_31 ( V_101 , 0 ) ) ;
F_32 ( & V_15 -> V_111 ) ;
F_33 ( F_23 ( V_101 ) , & V_15 -> V_103 ) ;
F_19 ( V_15 ) ;
if ( V_15 -> V_93 != V_112 && F_18 ( V_15 ) ) {
if ( F_10 ( V_15 ) ) {
F_22 ( F_23 ( V_101 ) ) ;
F_34 ( & V_15 -> V_111 ) ;
goto error;
}
V_15 -> V_113 = false ;
F_35 ( & V_15 -> V_114 ) ;
V_15 -> V_93 = V_112 ;
F_14 ( V_15 ) ;
}
F_34 ( & V_15 -> V_111 ) ;
return;
error:
F_36 ( V_101 , V_115 ) ;
}
static void F_37 ( struct V_100 * V_101 )
{
struct V_9 * V_10 = F_2 ( V_101 -> V_1 ) ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
unsigned int V_116 ;
int V_117 = 0 ;
F_32 ( & V_15 -> V_111 ) ;
for ( V_116 = 0 ; V_116 < V_34 ; V_116 ++ ) {
if ( V_15 -> V_99 [ V_116 ] == V_101 ) {
V_117 = 1 ;
break;
}
}
if ( V_117 ) {
while ( V_15 -> V_93 != V_97 ) {
if ( V_15 -> V_93 == V_112 )
F_15 ( V_15 ) ;
if ( V_15 -> V_93 == V_94 ) {
V_15 -> V_113 = true ;
F_34 ( & V_15 -> V_111 ) ;
F_38 ( & V_15 -> V_114 ) ;
F_32 ( & V_15 -> V_111 ) ;
}
}
for ( V_116 = 0 ; V_116 < V_34 ; V_116 ++ ) {
if ( V_15 -> V_99 [ V_116 ] ) {
F_36 ( V_15 -> V_99 [ V_116 ] ,
V_115 ) ;
V_15 -> V_99 [ V_116 ] = NULL ;
}
}
} else {
F_22 ( F_23 ( V_101 ) ) ;
}
F_34 ( & V_15 -> V_111 ) ;
}
static int F_39 ( struct V_100 * V_101 )
{
F_40 ( F_23 ( V_101 ) ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_118 * V_119 , * V_120 ;
F_32 ( & V_15 -> V_111 ) ;
F_42 (buf_head, tmp, &priv->capture)
F_22 ( V_119 ) ;
F_34 ( & V_15 -> V_111 ) ;
return 0 ;
}
static T_2 F_43 ( int V_121 , void * V_122 )
{
struct V_14 * V_15 = V_122 ;
V_25 V_123 ;
bool V_124 = false , V_125 ;
int V_98 ;
unsigned int V_126 = 0 ;
F_44 ( & V_15 -> V_111 ) ;
V_123 = F_16 ( V_15 -> V_67 + V_85 ) ;
if ( ! V_123 )
goto V_127;
F_11 ( V_123 , V_15 -> V_67 + V_85 ) ;
V_126 = 1 ;
if ( V_15 -> V_93 == V_97 )
goto V_127;
V_125 = ! ( F_16 ( V_15 -> V_67 + V_95 ) & V_96 ) ;
if ( ! V_15 -> V_113 ) {
if ( F_8 ( V_15 ) )
V_98 = ( F_16 ( V_15 -> V_67 + V_95 ) &
V_128 ) >> V_129 ;
else
V_98 = 0 ;
V_15 -> V_99 [ V_98 ] -> V_108 . V_43 = V_15 -> V_43 ;
V_15 -> V_99 [ V_98 ] -> V_108 . V_31 = V_15 -> V_31 ++ ;
F_45 ( & V_15 -> V_99 [ V_98 ] -> V_108 . V_130 ) ;
F_36 ( V_15 -> V_99 [ V_98 ] , V_131 ) ;
V_15 -> V_99 [ V_98 ] = NULL ;
if ( V_15 -> V_93 != V_94 )
V_124 = F_19 ( V_15 ) ;
if ( V_125 || ! V_124 ) {
V_15 -> V_93 = V_97 ;
} else if ( F_8 ( V_15 ) &&
F_20 ( & V_15 -> V_103 ) &&
V_15 -> V_93 == V_112 ) {
F_15 ( V_15 ) ;
} else {
F_14 ( V_15 ) ;
}
} else if ( V_125 ) {
V_15 -> V_93 = V_97 ;
V_15 -> V_113 = false ;
F_46 ( & V_15 -> V_114 ) ;
}
V_127:
F_47 ( & V_15 -> V_111 ) ;
return F_48 ( V_126 ) ;
}
static int F_49 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
int V_116 ;
for ( V_116 = 0 ; V_116 < V_34 ; V_116 ++ )
V_15 -> V_99 [ V_116 ] = NULL ;
F_50 ( V_12 -> V_132 . V_133 ) ;
F_9 ( V_10 -> V_13 , L_5 ,
V_10 -> V_134 ) ;
return 0 ;
}
static void F_51 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_100 * V_101 ;
int V_116 ;
F_11 ( F_16 ( V_15 -> V_67 + V_89 ) & ~ V_88 ,
V_15 -> V_67 + V_89 ) ;
F_11 ( 0 , V_15 -> V_67 + V_86 ) ;
V_15 -> V_93 = V_97 ;
V_15 -> V_113 = false ;
F_32 ( & V_15 -> V_111 ) ;
for ( V_116 = 0 ; V_116 < V_34 ; V_116 ++ ) {
V_101 = V_15 -> V_99 [ V_116 ] ;
if ( V_101 ) {
F_22 ( F_23 ( V_101 ) ) ;
F_36 ( V_101 , V_115 ) ;
}
}
F_34 ( & V_15 -> V_111 ) ;
F_52 ( V_12 -> V_132 . V_133 ) ;
F_9 ( V_10 -> V_13 , L_6 ,
V_10 -> V_134 ) ;
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
unsigned int V_135 , V_136 ;
unsigned char V_137 = 0 ;
struct V_138 * V_139 = & V_36 -> V_140 ;
F_9 ( V_10 -> V_13 , L_7 ,
V_10 -> V_141 , V_10 -> V_142 , V_36 -> V_143 , V_36 -> V_144 ) ;
V_135 = V_36 -> V_143 ;
V_136 = V_36 -> V_144 ;
if ( V_10 -> V_55 -> V_24 -> V_65 == V_76 &&
V_15 -> V_77 == V_79 )
V_137 = 1 ;
F_9 ( V_10 -> V_13 , L_8 ,
V_36 -> V_23 , V_36 -> V_27 , V_36 -> V_143 , V_36 -> V_144 ) ;
F_9 ( V_10 -> V_13 , L_9 ,
V_139 -> V_23 , V_139 -> V_27 ,
V_139 -> V_145 , V_139 -> V_146 ) ;
F_11 ( V_135 << V_137 , V_15 -> V_67 + V_147 ) ;
F_11 ( ( V_135 + V_36 -> V_23 - 1 ) << V_137 ,
V_15 -> V_67 + V_148 ) ;
switch ( V_15 -> V_43 ) {
case V_48 :
case V_49 :
case V_51 :
F_11 ( V_136 / 2 , V_15 -> V_67 + V_149 ) ;
F_11 ( ( V_136 + V_36 -> V_27 ) / 2 - 1 ,
V_15 -> V_67 + V_150 ) ;
break;
default:
F_11 ( V_136 , V_15 -> V_67 + V_149 ) ;
F_11 ( V_136 + V_36 -> V_27 - 1 ,
V_15 -> V_67 + V_150 ) ;
break;
}
F_11 ( 0 , V_15 -> V_67 + V_151 ) ;
F_11 ( 0 , V_15 -> V_67 + V_152 ) ;
F_11 ( ( V_139 -> V_23 - 1 ) << V_137 , V_15 -> V_67 + V_153 ) ;
switch ( V_15 -> V_43 ) {
case V_48 :
case V_49 :
case V_51 :
F_11 ( V_139 -> V_27 / 2 - 1 ,
V_15 -> V_67 + V_154 ) ;
break;
default:
F_11 ( V_139 -> V_27 - 1 , V_15 -> V_67 + V_154 ) ;
break;
}
F_11 ( F_12 ( V_36 -> V_23 , 0x10 ) , V_15 -> V_67 + V_155 ) ;
return 0 ;
}
static void F_56 ( struct V_14 * V_15 , V_25 * V_38 )
{
* V_38 = F_16 ( V_15 -> V_67 + V_89 ) ;
F_11 ( * V_38 & ~ V_88 , V_15 -> V_67 + V_89 ) ;
}
static void F_57 ( struct V_14 * V_15 , V_25 V_38 )
{
unsigned long V_156 = V_157 + 10 * V_158 ;
while ( ( F_16 ( V_15 -> V_67 + V_95 ) & V_159 ) &&
F_58 ( V_157 , V_156 ) )
F_59 ( 1 ) ;
if ( F_60 ( V_157 , V_156 ) ) {
F_28 ( V_15 -> V_12 . V_132 . V_133 ,
L_10 ) ;
return;
}
F_11 ( V_38 , V_15 -> V_67 + V_89 ) ;
}
static int F_61 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_160 * V_161 = F_62 ( V_10 ) ;
struct V_162 V_163 ;
unsigned long V_164 ;
V_25 V_38 ;
V_25 V_165 ;
int V_19 ;
F_56 ( V_15 , & V_38 ) ;
V_19 = F_63 ( V_161 , V_166 , V_167 , & V_163 ) ;
if ( ! V_19 ) {
V_164 = F_64 ( & V_163 , V_168 ) ;
if ( ! V_164 ) {
F_13 ( V_10 -> V_13 ,
L_11 ,
V_163 . V_61 , V_168 ) ;
return - V_22 ;
}
} else if ( V_19 != - V_169 ) {
return V_19 ;
} else {
V_164 = V_168 ;
}
if ( ( V_164 & V_170 ) &&
( V_164 & V_171 ) ) {
if ( V_15 -> V_60 -> V_61 & V_172 )
V_164 &= ~ V_170 ;
else
V_164 &= ~ V_171 ;
}
if ( ( V_164 & V_173 ) &&
( V_164 & V_174 ) ) {
if ( V_15 -> V_60 -> V_61 & V_175 )
V_164 &= ~ V_173 ;
else
V_164 &= ~ V_174 ;
}
V_163 . V_61 = V_164 ;
V_19 = F_63 ( V_161 , V_166 , V_176 , & V_163 ) ;
if ( V_19 < 0 && V_19 != - V_169 )
return V_19 ;
V_165 = V_15 -> V_43 == V_53 ? V_177 : 0 ;
if ( ! ( V_164 & V_174 ) )
V_165 |= V_178 ;
if ( ! ( V_164 & V_171 ) )
V_165 |= V_179 ;
F_11 ( V_165 , V_15 -> V_67 + V_180 ) ;
V_19 = F_55 ( V_10 ) ;
if ( V_19 < 0 )
return V_19 ;
F_57 ( V_15 , V_38 ) ;
return 0 ;
}
static int F_65 ( struct V_9 * V_10 ,
unsigned char V_181 )
{
struct V_160 * V_161 = F_62 ( V_10 ) ;
struct V_162 V_163 ;
int V_19 ;
V_19 = F_63 ( V_161 , V_166 , V_167 , & V_163 ) ;
if ( V_19 == - V_169 )
return 0 ;
else if ( V_19 )
return V_19 ;
if ( V_181 > 24 )
return - V_22 ;
V_19 = F_64 ( & V_163 , V_168 ) ;
if ( V_19 )
return 0 ;
F_13 ( V_10 -> V_13 ,
L_11 ,
V_163 . V_61 , V_168 ) ;
return - V_22 ;
}
static bool F_66 ( const struct V_182 * V_4 )
{
return V_4 -> V_183 == V_184 ||
( V_4 -> V_185 > 8 &&
V_4 -> V_183 == V_186 ) ;
}
static int F_67 ( struct V_9 * V_10 , unsigned int V_187 ,
struct V_16 * V_17 )
{
struct V_160 * V_161 = F_62 ( V_10 ) ;
struct V_188 * V_133 = V_10 -> V_13 ;
int V_19 , V_189 , V_190 ;
int V_191 = 0 ;
struct V_35 * V_36 ;
enum V_192 V_56 ;
const struct V_182 * V_4 ;
V_19 = F_63 ( V_161 , V_166 , V_193 , V_187 , & V_56 ) ;
if ( V_19 < 0 )
return 0 ;
V_4 = F_68 ( V_56 ) ;
if ( ! V_4 ) {
F_13 ( V_133 , L_12 , V_187 , V_56 ) ;
return 0 ;
}
V_19 = F_65 ( V_10 , V_4 -> V_185 ) ;
if ( V_19 < 0 )
return 0 ;
if ( ! V_10 -> V_37 ) {
struct V_194 V_195 ;
struct V_138 V_196 ;
struct V_188 * V_133 = V_10 -> V_13 ;
int V_197 ;
V_19 = F_63 ( V_161 , V_166 , V_198 , & V_195 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_69 ( V_161 , & V_196 ) ;
if ( V_19 == - V_169 ) {
V_196 . V_145 = 0 ;
V_196 . V_146 = 0 ;
V_196 . V_23 = V_195 . V_23 ;
V_196 . V_27 = V_195 . V_27 ;
} else if ( V_19 < 0 ) {
return V_19 ;
}
for ( V_197 = 0 ; V_197 < 3 ; V_197 ++ ) {
if ( V_195 . V_23 <= V_199 &&
V_195 . V_27 <= V_200 )
break;
V_195 . V_23 = 1280 >> V_197 ;
V_195 . V_27 = 960 >> V_197 ;
V_19 = F_70 ( V_161 -> V_132 ,
F_71 ( V_10 ) ,
V_166 , V_201 ,
& V_195 ) ;
if ( V_19 < 0 )
return V_19 ;
}
if ( V_197 == 3 ) {
F_28 ( V_133 ,
L_13 ,
V_195 . V_23 , V_195 . V_27 ) ;
return - V_202 ;
}
F_9 ( V_133 , L_14 , V_195 . V_23 , V_195 . V_27 ) ;
V_36 = F_72 ( sizeof( * V_36 ) , V_203 ) ;
if ( ! V_36 )
return - V_204 ;
V_36 -> V_196 = V_196 ;
V_36 -> V_140 = V_196 ;
V_36 -> V_23 = V_195 . V_23 ;
V_36 -> V_27 = V_195 . V_27 ;
V_10 -> V_37 = V_36 ;
} else {
V_36 = V_10 -> V_37 ;
}
if ( ! V_187 )
V_36 -> V_205 = NULL ;
switch ( V_56 ) {
case V_57 :
case V_59 :
if ( V_36 -> V_205 )
break;
V_36 -> V_205 = V_206 ;
V_190 = F_73 ( V_206 ) ;
V_191 += V_190 ;
for ( V_189 = 0 ; V_17 && V_189 < V_190 ; V_189 ++ , V_17 ++ ) {
V_17 -> V_24 = & V_206 [ V_189 ] ;
V_17 -> V_56 = V_56 ;
F_9 ( V_133 , L_15 ,
V_206 [ V_189 ] . V_207 , V_56 ) ;
}
break;
default:
if ( ! F_66 ( V_4 ) )
return 0 ;
F_9 ( V_133 , L_16 ,
V_4 -> V_207 ) ;
break;
}
V_191 ++ ;
if ( V_17 ) {
V_17 -> V_24 = V_4 ;
V_17 -> V_56 = V_56 ;
V_17 ++ ;
}
return V_191 ;
}
static void F_74 ( struct V_9 * V_10 )
{
F_75 ( V_10 -> V_37 ) ;
V_10 -> V_37 = NULL ;
}
static int F_76 ( struct V_9 * V_10 ,
const struct V_208 * V_209 )
{
struct V_208 V_210 = * V_209 ;
const struct V_138 * V_196 = & V_210 . V_211 ;
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_208 V_212 ;
struct V_35 * V_36 = V_10 -> V_37 ;
struct V_138 * V_213 = & V_212 . V_211 ;
struct V_160 * V_161 = F_62 ( V_10 ) ;
struct V_188 * V_133 = V_10 -> V_13 ;
struct V_194 V_195 ;
V_25 V_38 ;
int V_19 , V_116 ;
F_9 ( V_133 , L_17 , V_196 -> V_23 , V_196 -> V_27 ,
V_196 -> V_145 , V_196 -> V_146 ) ;
F_56 ( V_15 , & V_38 ) ;
F_9 ( V_133 , L_18 , V_38 ) ;
V_19 = F_77 ( V_161 , & V_210 , & V_212 ,
& V_36 -> V_196 , & V_36 -> V_140 ) ;
if ( V_19 < 0 )
return V_19 ;
F_9 ( V_133 , L_19 ,
V_213 -> V_23 , V_213 -> V_27 ,
V_213 -> V_145 , V_213 -> V_146 ) ;
V_19 = F_63 ( V_161 , V_166 , V_198 , & V_195 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_195 . V_23 > V_199 || V_195 . V_27 > V_200 )
return - V_22 ;
V_36 -> V_23 = V_195 . V_23 ;
V_36 -> V_27 = V_195 . V_27 ;
V_10 -> V_141 = V_36 -> V_23 ;
V_10 -> V_142 = V_36 -> V_27 ;
V_36 -> V_143 = V_196 -> V_145 & ~ 1 ;
V_36 -> V_144 = V_196 -> V_146 & ~ 1 ;
V_19 = F_55 ( V_10 ) ;
if ( V_19 < 0 )
return V_19 ;
V_36 -> V_140 = * V_196 ;
F_9 ( V_133 , L_20 ,
V_10 -> V_141 , V_10 -> V_142 ,
V_36 -> V_143 , V_36 -> V_144 ) ;
for ( V_116 = 0 ; V_116 < V_34 ; V_116 ++ ) {
if ( V_15 -> V_99 [ V_116 ] && V_15 -> V_93 == V_97 ) {
V_38 |= V_88 ;
break;
}
}
F_57 ( V_15 , V_38 ) ;
return V_19 ;
}
static int F_78 ( struct V_9 * V_10 ,
struct V_208 * V_209 )
{
struct V_35 * V_36 = V_10 -> V_37 ;
V_209 -> type = V_214 ;
V_209 -> V_211 = V_36 -> V_140 ;
return 0 ;
}
static int F_79 ( struct V_9 * V_10 ,
struct V_3 * V_215 )
{
struct V_11 * V_12 = F_3 ( V_10 -> V_13 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_160 * V_161 = F_62 ( V_10 ) ;
struct V_35 * V_36 = V_10 -> V_37 ;
struct V_216 * V_20 = & V_215 -> V_4 . V_20 ;
struct V_194 V_195 ;
struct V_188 * V_133 = V_10 -> V_13 ;
T_3 V_217 = V_20 -> V_21 ;
const struct V_16 * V_17 ;
unsigned int V_218 = 0 , V_219 = 0 ;
int V_19 ;
bool V_220 ;
enum V_221 V_43 ;
T_4 V_222 ;
F_9 ( V_133 , L_21 ,
V_217 , V_20 -> V_23 , V_20 -> V_27 ) ;
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
V_19 = F_63 ( V_161 , V_166 , V_223 , & V_222 ) ;
if ( V_19 < 0 )
V_222 = V_224 ;
V_43 = V_222 & V_224 ? V_49 :
V_51 ;
break;
}
V_17 = F_4 ( V_10 , V_217 ) ;
if ( ! V_17 ) {
F_13 ( V_133 , L_22 , V_217 ) ;
return - V_22 ;
}
F_80 ( V_10 , & V_36 -> V_196 , & V_36 -> V_140 , V_20 , & V_195 ,
12 ) ;
V_195 . V_43 = V_20 -> V_43 ;
V_195 . V_225 = V_20 -> V_225 ;
V_195 . V_56 = V_17 -> V_56 ;
switch ( V_217 ) {
case V_76 :
V_220 = V_15 -> V_77 != V_79 ;
break;
case V_72 :
case V_70 :
case V_75 :
case V_73 :
V_220 = true ;
break;
default:
V_220 = false ;
break;
}
F_9 ( V_133 , L_23 , V_195 . V_23 , V_195 . V_27 ) ;
V_19 = F_81 ( V_10 , & V_36 -> V_196 , & V_36 -> V_140 ,
& V_195 , & V_218 , & V_219 ,
V_220 , 12 ) ;
F_9 ( V_133 , L_24 ,
V_19 , V_195 . V_23 , V_195 . V_27 , V_20 -> V_23 , V_20 -> V_27 ) ;
if ( V_19 == - V_169 )
F_9 ( V_133 , L_25 ) ;
else if ( V_19 < 0 )
return V_19 ;
if ( V_195 . V_56 != V_17 -> V_56 )
return - V_22 ;
V_36 -> V_23 = V_195 . V_23 ;
V_36 -> V_27 = V_195 . V_27 ;
if ( V_20 -> V_23 > V_218 )
V_218 = V_20 -> V_23 ;
if ( V_20 -> V_27 > V_219 )
V_219 = V_20 -> V_27 ;
V_20 -> V_225 = V_195 . V_225 ;
if ( ! V_220 ) {
V_20 -> V_23 = V_218 ;
V_20 -> V_27 = V_219 ;
}
F_9 ( V_133 , L_26 ,
V_218 , V_20 -> V_23 , V_219 , V_20 -> V_27 ) ;
V_10 -> V_55 = V_17 ;
V_15 -> V_43 = V_43 ;
return 0 ;
}
static int F_82 ( struct V_9 * V_10 ,
struct V_3 * V_215 )
{
const struct V_16 * V_17 ;
struct V_216 * V_20 = & V_215 -> V_4 . V_20 ;
struct V_160 * V_161 = F_62 ( V_10 ) ;
struct V_194 V_195 ;
T_3 V_217 = V_20 -> V_21 ;
int V_23 , V_27 ;
int V_19 ;
V_17 = F_4 ( V_10 , V_217 ) ;
if ( ! V_17 ) {
V_17 = V_10 -> V_55 ;
F_9 ( V_10 -> V_13 , L_27 ,
V_217 , V_17 -> V_24 -> V_65 ) ;
V_217 = V_17 -> V_24 -> V_65 ;
V_20 -> V_21 = V_217 ;
V_20 -> V_225 = V_10 -> V_225 ;
}
F_83 ( & V_20 -> V_23 , 2 , V_199 , 1 ,
& V_20 -> V_27 , 4 , V_200 , 2 , 0 ) ;
V_23 = V_20 -> V_23 ;
V_27 = V_20 -> V_27 ;
V_20 -> V_26 = 0 ;
V_20 -> V_28 = 0 ;
V_195 . V_23 = V_20 -> V_23 ;
V_195 . V_27 = V_20 -> V_27 ;
V_195 . V_43 = V_20 -> V_43 ;
V_195 . V_56 = V_17 -> V_56 ;
V_195 . V_225 = V_20 -> V_225 ;
V_19 = F_70 ( V_161 -> V_132 , F_71 ( V_10 ) ,
V_166 , V_226 , & V_195 ) ;
if ( V_19 < 0 )
return V_19 ;
V_20 -> V_23 = V_195 . V_23 ;
V_20 -> V_27 = V_195 . V_27 ;
V_20 -> V_43 = V_195 . V_43 ;
V_20 -> V_225 = V_195 . V_225 ;
if ( V_217 == V_66 ) {
if ( V_20 -> V_23 < V_23 || V_20 -> V_27 < V_27 ) {
V_195 . V_23 = V_199 ;
V_195 . V_27 = V_200 ;
V_19 = F_70 ( V_161 -> V_132 ,
F_71 ( V_10 ) ,
V_166 , V_226 ,
& V_195 ) ;
if ( V_19 < 0 ) {
F_28 ( V_10 -> V_13 ,
L_28 , V_19 ) ;
return V_19 ;
}
}
if ( V_195 . V_23 > V_23 )
V_20 -> V_23 = V_23 ;
if ( V_195 . V_27 > V_27 )
V_20 -> V_27 = V_27 ;
}
return V_19 ;
}
static unsigned int F_84 ( struct V_227 * V_227 , T_5 * V_228 )
{
struct V_9 * V_10 = V_227 -> V_229 ;
return F_85 ( & V_10 -> V_230 , V_227 , V_228 ) ;
}
static int F_86 ( struct V_11 * V_12 ,
struct V_231 * V_232 )
{
F_87 ( V_232 -> V_233 , L_29 , sizeof( V_232 -> V_233 ) ) ;
V_232 -> V_234 = V_235 | V_236 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
V_2 -> type = V_214 ;
V_2 -> V_237 = V_238 | V_239 ;
V_2 -> V_240 = V_10 ;
V_2 -> V_241 = & V_242 ;
V_2 -> V_243 = & V_244 ;
V_2 -> V_245 = sizeof( struct V_105 ) ;
V_2 -> V_246 = V_247 ;
return F_89 ( V_2 ) ;
}
static int F_90 ( struct V_248 * V_249 )
{
struct V_14 * V_15 ;
struct V_250 * V_251 ;
struct V_252 * V_60 ;
int V_121 , V_19 ;
V_60 = V_249 -> V_133 . V_253 ;
if ( ! V_60 || ! V_60 -> V_61 ) {
F_28 ( & V_249 -> V_133 , L_30 ) ;
return - V_22 ;
}
V_251 = F_91 ( V_249 , V_254 , 0 ) ;
if ( V_251 == NULL )
return - V_22 ;
V_121 = F_92 ( V_249 , 0 ) ;
if ( V_121 <= 0 )
return - V_22 ;
V_15 = F_93 ( & V_249 -> V_133 , sizeof( struct V_14 ) ,
V_203 ) ;
if ( ! V_15 )
return - V_204 ;
V_15 -> V_67 = F_94 ( & V_249 -> V_133 , V_251 ) ;
if ( F_95 ( V_15 -> V_67 ) )
return F_96 ( V_15 -> V_67 ) ;
V_19 = F_97 ( & V_249 -> V_133 , V_121 , F_43 , V_255 ,
F_98 ( & V_249 -> V_133 ) , V_15 ) ;
if ( V_19 )
return V_19 ;
V_15 -> V_29 = F_99 ( & V_249 -> V_133 ) ;
if ( F_95 ( V_15 -> V_29 ) )
return F_96 ( V_15 -> V_29 ) ;
V_15 -> V_12 . V_15 = V_15 ;
V_15 -> V_12 . V_132 . V_133 = & V_249 -> V_133 ;
V_15 -> V_12 . V_256 = V_249 -> V_257 ;
V_15 -> V_12 . V_258 = F_98 ( & V_249 -> V_133 ) ;
V_15 -> V_12 . V_241 = & V_259 ;
V_15 -> V_60 = V_60 ;
V_15 -> V_77 = V_249 -> V_260 -> V_261 ;
F_100 ( & V_15 -> V_111 ) ;
F_40 ( & V_15 -> V_103 ) ;
V_15 -> V_93 = V_97 ;
F_101 ( & V_249 -> V_133 , true ) ;
F_102 ( & V_249 -> V_133 ) ;
V_19 = F_103 ( & V_15 -> V_12 ) ;
if ( V_19 )
goto V_262;
return 0 ;
V_262:
F_104 ( & V_249 -> V_133 ) ;
F_105 ( V_15 -> V_29 ) ;
return V_19 ;
}
static int F_106 ( struct V_248 * V_249 )
{
struct V_11 * V_263 = F_3 ( & V_249 -> V_133 ) ;
struct V_14 * V_15 = F_107 ( V_263 ,
struct V_14 , V_12 ) ;
F_108 ( V_263 ) ;
F_104 ( & V_249 -> V_133 ) ;
F_105 ( V_15 -> V_29 ) ;
return 0 ;
}
