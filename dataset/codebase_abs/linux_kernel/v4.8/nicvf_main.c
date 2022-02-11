static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 )
return V_3 + ( ( V_2 -> V_5 + 1 ) * V_6 ) ;
else
return V_3 ;
}
static inline void F_2 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
if ( V_8 -> V_9 <= 64 )
V_2 -> V_10 . V_11 ++ ;
else if ( V_8 -> V_9 <= 127 )
V_2 -> V_10 . V_12 ++ ;
else if ( V_8 -> V_9 <= 255 )
V_2 -> V_10 . V_13 ++ ;
else if ( V_8 -> V_9 <= 511 )
V_2 -> V_10 . V_14 ++ ;
else if ( V_8 -> V_9 <= 1023 )
V_2 -> V_10 . V_15 ++ ;
else if ( V_8 -> V_9 <= 1518 )
V_2 -> V_10 . V_16 ++ ;
else
V_2 -> V_10 . V_17 ++ ;
}
void F_3 ( struct V_1 * V_2 , T_2 V_18 , T_2 V_19 )
{
F_4 ( V_19 , V_2 -> V_20 + V_18 ) ;
}
T_2 F_5 ( struct V_1 * V_2 , T_2 V_18 )
{
return F_6 ( V_2 -> V_20 + V_18 ) ;
}
void F_7 ( struct V_1 * V_2 , T_2 V_18 ,
T_2 V_3 , T_2 V_19 )
{
void T_3 * V_21 = V_2 -> V_20 + V_18 ;
F_4 ( V_19 , V_21 + ( V_3 << V_22 ) ) ;
}
T_2 F_8 ( struct V_1 * V_2 , T_2 V_18 , T_2 V_3 )
{
void T_3 * V_21 = V_2 -> V_20 + V_18 ;
return F_6 ( V_21 + ( V_3 << V_22 ) ) ;
}
static void F_9 ( struct V_1 * V_2 , union V_23 * V_24 )
{
T_2 * V_25 = ( T_2 * ) V_24 ;
F_3 ( V_2 , V_26 + 0 , V_25 [ 0 ] ) ;
F_3 ( V_2 , V_26 + 8 , V_25 [ 1 ] ) ;
}
int F_10 ( struct V_1 * V_2 , union V_23 * V_24 )
{
int V_27 = V_28 ;
int V_29 = 10 ;
V_2 -> V_30 = false ;
V_2 -> V_31 = false ;
F_9 ( V_2 , V_24 ) ;
while ( ! V_2 -> V_30 ) {
if ( V_2 -> V_31 )
return - V_32 ;
F_11 ( V_29 ) ;
if ( V_2 -> V_30 )
break;
V_27 -= V_29 ;
if ( ! V_27 ) {
F_12 ( V_2 -> V_33 ,
L_1 ,
( V_24 -> V_25 . V_25 & 0xFF ) , V_2 -> V_34 ) ;
return - V_35 ;
}
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
union V_23 V_24 = {} ;
V_24 . V_25 . V_25 = V_36 ;
if ( F_10 ( V_2 , & V_24 ) ) {
F_12 ( V_2 -> V_33 ,
L_2 ) ;
return 0 ;
}
return 1 ;
}
static void F_14 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
if ( V_38 -> V_39 )
V_2 -> V_40 . V_41 [ V_38 -> V_42 ] = V_38 -> V_43 ;
else
V_2 -> V_40 . V_44 [ V_38 -> V_42 ] = V_38 -> V_43 ;
}
static void F_15 ( struct V_1 * V_2 )
{
union V_23 V_24 = {} ;
T_2 * V_45 ;
T_2 V_46 ;
int V_47 ;
V_46 = V_26 ;
V_45 = ( T_2 * ) & V_24 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
* V_45 = F_5 ( V_2 , V_46 ) ;
V_45 ++ ;
V_46 += sizeof( T_2 ) ;
}
F_16 ( V_2 -> V_33 , L_3 , V_24 . V_25 . V_25 ) ;
switch ( V_24 . V_25 . V_25 ) {
case V_36 :
V_2 -> V_30 = true ;
V_2 -> V_34 = V_24 . V_49 . V_34 & 0x7F ;
V_2 -> V_50 = V_24 . V_49 . V_50 & 0x7F ;
V_2 -> V_51 = V_24 . V_49 . V_52 ;
if ( ! V_2 -> V_53 )
F_17 ( V_2 -> V_33 -> V_54 ,
V_24 . V_49 . V_55 ) ;
V_2 -> V_4 = V_24 . V_49 . V_4 ;
V_2 -> V_56 = V_24 . V_49 . V_56 ;
V_2 -> V_57 = false ;
V_2 -> V_58 = 0 ;
V_2 -> V_59 = 0 ;
break;
case V_60 :
V_2 -> V_30 = true ;
break;
case V_61 :
V_2 -> V_31 = true ;
break;
case V_62 :
V_2 -> V_63 . V_64 = V_24 . V_64 . V_65 ;
V_2 -> V_30 = true ;
break;
case V_66 :
F_14 ( V_2 , & V_24 . V_40 ) ;
V_2 -> V_30 = true ;
break;
case V_67 :
V_2 -> V_30 = true ;
V_2 -> V_57 = V_24 . V_68 . V_57 ;
V_2 -> V_58 = V_24 . V_68 . V_58 ;
V_2 -> V_59 = V_24 . V_68 . V_59 ;
if ( V_2 -> V_57 ) {
F_18 ( V_2 -> V_33 , L_4 ,
V_2 -> V_33 -> V_69 , V_2 -> V_59 ,
V_2 -> V_58 == V_70 ?
L_5 : L_6 ) ;
F_19 ( V_2 -> V_33 ) ;
F_20 ( V_2 -> V_33 ) ;
} else {
F_18 ( V_2 -> V_33 , L_7 ,
V_2 -> V_33 -> V_69 ) ;
F_21 ( V_2 -> V_33 ) ;
F_22 ( V_2 -> V_33 ) ;
}
break;
case V_71 :
V_2 -> V_72 = V_24 . V_73 . V_74 ;
V_2 -> V_30 = true ;
break;
case V_75 :
V_2 -> V_76 [ V_24 . V_1 . V_5 ] =
(struct V_1 * ) V_24 . V_1 . V_1 ;
V_2 -> V_30 = true ;
break;
case V_77 :
V_2 -> V_78 = (struct V_1 * ) V_24 . V_1 . V_1 ;
V_2 -> V_30 = true ;
break;
default:
F_12 ( V_2 -> V_33 ,
L_8 , V_24 . V_25 . V_25 ) ;
break;
}
F_23 ( V_2 , V_79 , 0 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_80 * V_33 )
{
union V_23 V_24 = {} ;
V_24 . V_81 . V_25 = V_82 ;
V_24 . V_81 . V_34 = V_2 -> V_34 ;
F_17 ( V_24 . V_81 . V_55 , V_33 -> V_54 ) ;
return F_10 ( V_2 , & V_24 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
union V_23 V_24 = {} ;
V_24 . V_83 . V_25 = V_84 ;
V_24 . V_83 . V_34 = V_2 -> V_34 ;
V_24 . V_83 . V_85 = V_2 -> V_85 ;
V_24 . V_83 . V_86 = V_2 -> V_87 -> V_86 ;
F_10 ( V_2 , & V_24 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
union V_23 V_24 = {} ;
V_24 . V_64 . V_25 = V_62 ;
V_24 . V_64 . V_34 = V_2 -> V_34 ;
F_10 ( V_2 , & V_24 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
union V_23 V_24 = {} ;
struct V_88 * V_89 = & V_2 -> V_63 ;
int V_90 = V_89 -> V_64 ;
int V_47 , V_91 = 0 ;
V_24 . V_92 . V_34 = V_2 -> V_34 ;
V_24 . V_92 . V_93 = V_89 -> V_93 ;
while ( V_90 ) {
V_24 . V_92 . V_94 = V_91 ;
V_24 . V_92 . V_95 = F_28 ( V_90 ,
V_96 ) ;
V_24 . V_92 . V_25 = V_24 . V_92 . V_94 ?
V_97 : V_98 ;
for ( V_47 = 0 ; V_47 < V_24 . V_92 . V_95 ; V_47 ++ )
V_24 . V_92 . V_99 [ V_47 ] = V_89 -> V_99 [ V_91 ++ ] ;
F_10 ( V_2 , & V_24 ) ;
V_90 -= V_24 . V_92 . V_95 ;
}
}
void F_29 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = & V_2 -> V_63 ;
T_2 V_100 = V_101 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_102 ; V_42 ++ ) {
F_3 ( V_2 , V_100 , V_89 -> V_103 [ V_42 ] ) ;
V_100 += sizeof( T_2 ) ;
}
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = & V_2 -> V_63 ;
int V_42 ;
F_26 ( V_2 ) ;
if ( V_85 != V_104 ) {
V_89 -> V_105 = false ;
V_89 -> V_93 = 0 ;
return 0 ;
}
V_89 -> V_105 = true ;
V_89 -> V_103 [ 0 ] = 0xFEED0BADFEED0BADULL ;
V_89 -> V_103 [ 1 ] = 0xFEED0BADFEED0BADULL ;
V_89 -> V_103 [ 2 ] = 0xFEED0BADFEED0BADULL ;
V_89 -> V_103 [ 3 ] = 0xFEED0BADFEED0BADULL ;
V_89 -> V_103 [ 4 ] = 0xFEED0BADFEED0BADULL ;
F_29 ( V_2 ) ;
V_89 -> V_106 = V_107 | V_108 | V_109 ;
F_3 ( V_2 , V_110 , V_89 -> V_106 ) ;
V_89 -> V_93 = F_31 ( F_32 ( V_89 -> V_64 ) ) ;
for ( V_42 = 0 ; V_42 < V_89 -> V_64 ; V_42 ++ )
V_89 -> V_99 [ V_42 ] = F_33 ( V_42 ,
V_2 -> V_111 ) ;
F_27 ( V_2 ) ;
return 1 ;
}
static void F_34 ( struct V_1 * V_2 )
{
union V_23 V_24 = {} ;
int V_112 ;
int V_72 = V_2 -> V_72 ;
int V_111 = 0 , V_113 = 0 ;
if ( V_2 -> V_4 || ! V_2 -> V_72 )
return;
V_24 . V_73 . V_25 = V_71 ;
V_24 . V_73 . V_34 = V_2 -> V_34 ;
V_24 . V_73 . V_74 = V_2 -> V_72 ;
if ( F_10 ( V_2 , & V_24 ) ) {
V_2 -> V_72 = 0 ;
return;
}
if ( ! V_2 -> V_72 )
return;
if ( V_2 -> V_111 > V_114 )
V_111 = V_2 -> V_111 - V_114 ;
if ( V_2 -> V_113 > V_115 )
V_113 = V_2 -> V_113 - V_115 ;
for ( V_112 = 0 ; V_112 < V_2 -> V_72 ; V_112 ++ ) {
V_24 . V_1 . V_25 = V_75 ;
V_24 . V_1 . V_34 = V_2 -> V_34 ;
V_24 . V_1 . V_5 = V_112 ;
F_10 ( V_2 , & V_24 ) ;
V_2 -> V_76 [ V_112 ] -> V_5 = V_112 ;
if ( V_111 > V_114 ) {
V_2 -> V_76 [ V_112 ] -> V_87 -> V_86 = V_114 ;
V_111 -= V_114 ;
} else {
V_2 -> V_76 [ V_112 ] -> V_87 -> V_86 = V_111 ;
V_111 = 0 ;
}
if ( V_113 > V_115 ) {
V_2 -> V_76 [ V_112 ] -> V_87 -> V_116 = V_115 ;
V_113 -= V_115 ;
} else {
V_2 -> V_76 [ V_112 ] -> V_87 -> V_116 = V_113 ;
V_113 = 0 ;
}
V_2 -> V_76 [ V_112 ] -> V_87 -> V_117 =
F_35 ( V_2 -> V_76 [ V_112 ] -> V_87 -> V_86 , V_2 -> V_76 [ V_112 ] -> V_87 -> V_116 ) ;
F_36 ( V_2 -> V_76 [ V_112 ] -> V_33 ) ;
}
if ( V_72 != V_2 -> V_72 )
F_37 ( V_2 -> V_33 ,
V_2 -> V_113 , V_2 -> V_111 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
union V_23 V_24 = {} ;
V_24 . V_1 . V_25 = V_118 ;
V_24 . V_1 . V_4 = V_2 -> V_4 ;
V_24 . V_1 . V_1 = ( T_2 ) V_2 ;
F_10 ( V_2 , & V_24 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
union V_23 V_24 = {} ;
V_24 . V_1 . V_25 = V_77 ;
F_10 ( V_2 , & V_24 ) ;
}
int F_37 ( struct V_80 * V_33 ,
int V_113 , int V_111 )
{
int V_119 = 0 ;
V_119 = F_40 ( V_33 , V_113 ) ;
if ( V_119 ) {
F_12 ( V_33 ,
L_9 , V_113 ) ;
return V_119 ;
}
V_119 = F_41 ( V_33 , V_111 ) ;
if ( V_119 )
F_12 ( V_33 ,
L_10 , V_111 ) ;
return V_119 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_119 ;
union V_23 V_24 = {} ;
V_24 . V_25 . V_25 = V_120 ;
F_43 ( V_2 , true ) ;
V_119 = F_44 ( V_2 , true ) ;
if ( V_119 ) {
F_12 ( V_2 -> V_33 ,
L_11 ) ;
return V_119 ;
}
F_9 ( V_2 , & V_24 ) ;
return 0 ;
}
static void F_45 ( struct V_80 * V_33 ,
struct V_121 * V_122 ,
struct V_123 * V_124 , int V_125 )
{
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 = F_46 ( V_33 ) ;
struct V_126 * V_127 ;
struct V_128 * V_129 ;
struct V_128 * V_130 ;
V_127 = & V_2 -> V_87 -> V_127 [ V_124 -> V_131 ] ;
V_129 = (struct V_128 * ) F_47 ( V_127 , V_124 -> V_132 ) ;
if ( V_129 -> V_133 != V_134 )
return;
F_16 ( V_2 -> V_33 ,
L_12 ,
V_135 , V_124 -> V_136 , V_124 -> V_131 ,
V_124 -> V_132 , V_129 -> V_137 ) ;
F_48 ( V_2 , V_122 , V_124 ) ;
V_8 = (struct V_7 * ) V_127 -> V_138 [ V_124 -> V_132 ] ;
if ( V_8 ) {
if ( V_129 -> V_139 ) {
V_130 =
(struct V_128 * ) F_47 ( V_127 , V_129 -> V_140 ) ;
F_49 ( V_127 , V_130 -> V_137 + 1 ) ;
}
F_49 ( V_127 , V_129 -> V_137 + 1 ) ;
F_50 ( V_8 ) ;
F_51 ( V_8 ) ;
V_127 -> V_138 [ V_124 -> V_132 ] = ( T_2 ) NULL ;
} else {
if ( ! V_2 -> V_141 )
F_49 ( V_127 , V_129 -> V_137 + 1 ) ;
}
}
static inline void F_52 ( struct V_80 * V_33 ,
struct V_142 * V_143 ,
struct V_7 * V_8 )
{
T_1 V_144 ;
T_4 V_145 ;
if ( ! ( V_33 -> V_146 & V_147 ) )
return;
switch ( V_143 -> V_148 ) {
case V_149 :
case V_150 :
V_144 = V_151 ;
V_145 = V_143 -> V_152 ;
break;
case V_153 :
V_144 = V_154 ;
V_145 = V_143 -> V_152 ;
break;
default:
V_144 = V_155 ;
V_145 = 0 ;
}
F_53 ( V_8 , V_145 , V_144 ) ;
}
static void F_54 ( struct V_80 * V_33 ,
struct V_156 * V_157 ,
struct V_142 * V_143 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 = F_46 ( V_33 ) ;
int V_119 = 0 ;
int V_158 ;
V_158 = F_1 ( V_2 , V_143 -> V_158 ) ;
if ( V_2 -> V_4 ) {
V_2 = V_2 -> V_78 ;
V_33 = V_2 -> V_33 ;
}
V_119 = F_55 ( V_2 , V_143 ) ;
if ( V_119 && ! V_143 -> V_159 )
return;
V_8 = F_56 ( V_2 , V_143 ) ;
if ( ! V_8 ) {
F_16 ( V_2 -> V_33 , L_13 ) ;
return;
}
if ( F_57 ( V_2 ) ) {
F_18 ( V_2 -> V_33 , L_14 , V_33 -> V_69 ,
V_8 , V_8 -> V_9 ) ;
F_58 ( V_160 , L_15 , V_161 , 16 , 1 ,
V_8 -> V_162 , V_8 -> V_9 , true ) ;
}
if ( V_119 ) {
F_59 ( V_8 ) ;
return;
}
F_2 ( V_2 , V_8 ) ;
F_52 ( V_33 , V_143 , V_8 ) ;
F_60 ( V_8 , V_158 ) ;
if ( V_33 -> V_163 & V_164 ) {
V_8 -> V_165 = V_166 ;
} else {
F_61 ( V_8 ) ;
}
V_8 -> V_167 = F_62 ( V_8 , V_33 ) ;
if ( V_143 -> V_168 && V_143 -> V_169 )
F_63 ( V_8 , F_64 ( V_170 ) ,
F_65 ( ( V_171 V_172 ) V_143 -> V_173 ) ) ;
if ( V_157 && ( V_33 -> V_146 & V_174 ) )
F_66 ( V_157 , V_8 ) ;
else
F_67 ( V_8 ) ;
}
static int F_68 ( struct V_80 * V_33 , T_1 V_175 ,
struct V_156 * V_157 , int V_176 )
{
int V_177 , V_178 = 0 , V_179 = 0 ;
int V_180 , V_181 ;
struct V_1 * V_2 = F_46 ( V_33 ) ;
struct V_182 * V_87 = V_2 -> V_87 ;
struct V_121 * V_122 = & V_87 -> V_122 [ V_175 ] ;
struct V_142 * V_183 ;
struct V_184 * V_185 ;
F_69 ( & V_122 -> V_186 ) ;
V_187:
V_177 = 0 ;
V_180 = F_8 ( V_2 , V_188 , V_175 ) ;
V_180 &= V_189 ;
if ( ! V_180 )
goto V_190;
V_181 = F_8 ( V_2 , V_191 , V_175 ) >> 9 ;
V_181 &= 0xFFFF ;
F_16 ( V_2 -> V_33 , L_16 ,
V_135 , V_175 , V_180 , V_181 ) ;
while ( V_177 < V_180 ) {
V_183 = (struct V_142 * ) F_70 ( V_122 , V_181 ) ;
V_181 ++ ;
V_181 &= ( V_122 -> V_192 . V_193 - 1 ) ;
F_50 ( (struct V_142 * ) F_70 ( V_122 , V_181 ) ) ;
if ( ( V_178 >= V_176 ) && V_157 &&
( V_183 -> V_125 != V_194 ) ) {
break;
}
F_16 ( V_2 -> V_33 , L_17 ,
V_175 , V_183 -> V_125 ) ;
switch ( V_183 -> V_125 ) {
case V_195 :
F_54 ( V_33 , V_157 , V_183 ) ;
V_178 ++ ;
break;
case V_194 :
F_45 ( V_33 , V_122 ,
( void * ) V_183 , V_194 ) ;
V_179 ++ ;
break;
case V_196 :
case V_197 :
case V_198 :
case V_199 :
break;
}
V_177 ++ ;
}
F_16 ( V_2 -> V_33 ,
L_18 ,
V_135 , V_175 , V_177 , V_178 , V_176 ) ;
F_7 ( V_2 , V_200 ,
V_175 , V_177 ) ;
if ( ( V_178 < V_176 ) && V_157 )
goto V_187;
V_190:
if ( V_179 ) {
V_33 = V_2 -> V_78 -> V_33 ;
V_185 = F_71 ( V_33 ,
F_1 ( V_2 , V_175 ) ) ;
V_2 = V_2 -> V_78 ;
if ( F_72 ( V_185 ) && F_73 ( V_33 ) ) {
F_74 ( V_185 ) ;
V_2 -> V_10 . V_201 ++ ;
if ( F_75 ( V_2 ) )
F_76 ( V_33 ,
L_19 ,
V_33 -> V_69 , V_175 ) ;
}
}
F_77 ( & V_122 -> V_186 ) ;
return V_178 ;
}
static int F_78 ( struct V_156 * V_157 , int V_176 )
{
T_2 V_202 ;
int V_178 = 0 ;
struct V_80 * V_33 = V_157 -> V_203 ;
struct V_1 * V_2 = F_46 ( V_33 ) ;
struct V_204 * V_122 ;
V_122 = F_79 ( V_157 , struct V_204 , V_157 ) ;
V_178 = F_68 ( V_33 , V_122 -> V_175 , V_157 , V_176 ) ;
if ( V_178 < V_176 ) {
F_80 ( V_157 ) ;
V_202 = F_8 ( V_2 , V_191 ,
V_122 -> V_175 ) ;
F_23 ( V_2 , V_205 , V_122 -> V_175 ) ;
F_7 ( V_2 , V_191 ,
V_122 -> V_175 , V_202 ) ;
F_81 ( V_2 , V_205 , V_122 -> V_175 ) ;
}
return V_178 ;
}
static void F_82 ( unsigned long V_162 )
{
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
struct V_182 * V_87 = V_2 -> V_87 ;
int V_3 ;
T_2 V_206 ;
F_83 ( V_2 -> V_33 ) ;
for ( V_3 = 0 ; V_3 < V_87 -> V_117 ; V_3 ++ ) {
V_206 = F_8 ( V_2 , V_188 ,
V_3 ) ;
if ( ! ( V_206 & V_207 ) )
continue;
F_84 ( V_2 , V_205 , V_3 ) ;
F_85 ( V_2 , V_3 ) ;
F_68 ( V_2 -> V_33 , V_3 , NULL , 0 ) ;
F_86 ( V_2 , V_87 , V_3 , true ) ;
F_87 ( V_2 -> V_33 , & V_87 -> V_127 [ V_3 ] , V_3 ) ;
F_88 ( V_2 , & V_87 -> V_127 [ V_3 ] , V_3 ) ;
F_81 ( V_2 , V_205 , V_3 ) ;
}
F_20 ( V_2 -> V_33 ) ;
F_81 ( V_2 , V_208 , 0 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
if ( F_90 ( V_2 ) )
F_18 ( V_2 -> V_33 , L_20 ,
V_2 -> V_33 -> V_69 , F_5 ( V_2 , V_209 ) ) ;
}
static T_5 F_91 ( int V_210 , void * V_211 )
{
struct V_1 * V_2 = (struct V_1 * ) V_211 ;
T_2 V_212 ;
F_89 ( V_2 ) ;
V_212 = F_5 ( V_2 , V_209 ) ;
if ( ! ( V_212 & V_213 ) )
return V_214 ;
F_15 ( V_2 ) ;
return V_214 ;
}
static T_5 F_92 ( int V_210 , void * V_215 )
{
struct V_204 * V_216 = (struct V_204 * ) V_215 ;
struct V_1 * V_2 = V_216 -> V_1 ;
int V_3 = V_216 -> V_175 ;
F_89 ( V_2 ) ;
F_84 ( V_2 , V_205 , V_3 ) ;
F_93 ( & V_216 -> V_157 ) ;
F_23 ( V_2 , V_205 , V_3 ) ;
return V_214 ;
}
static T_5 F_94 ( int V_210 , void * V_211 )
{
struct V_1 * V_2 = (struct V_1 * ) V_211 ;
T_1 V_3 ;
F_89 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_87 -> V_217 ; V_3 ++ ) {
if ( ! F_95 ( V_2 , V_218 , V_3 ) )
continue;
F_84 ( V_2 , V_218 , V_3 ) ;
F_96 ( & V_2 -> V_219 ) ;
F_23 ( V_2 , V_218 , V_3 ) ;
}
return V_214 ;
}
static T_5 F_97 ( int V_210 , void * V_211 )
{
struct V_1 * V_2 = (struct V_1 * ) V_211 ;
F_89 ( V_2 ) ;
F_84 ( V_2 , V_208 , 0 ) ;
F_96 ( & V_2 -> V_220 ) ;
F_23 ( V_2 , V_208 , 0 ) ;
return V_214 ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_221 , V_222 ;
V_2 -> V_223 = V_224 ;
for ( V_222 = 0 ; V_222 < V_2 -> V_223 ; V_222 ++ )
V_2 -> V_225 [ V_222 ] . V_226 = V_222 ;
V_221 = F_99 ( V_2 -> V_227 , V_2 -> V_225 , V_2 -> V_223 ) ;
if ( V_221 ) {
F_12 ( V_2 -> V_33 ,
L_21 , V_2 -> V_223 ) ;
return 0 ;
}
V_2 -> V_228 = 1 ;
return 1 ;
}
static void F_100 ( struct V_1 * V_2 )
{
if ( V_2 -> V_228 ) {
F_101 ( V_2 -> V_227 ) ;
V_2 -> V_228 = 0 ;
V_2 -> V_223 = 0 ;
}
}
static void F_102 ( struct V_1 * V_2 )
{
int V_222 , V_229 ;
int V_230 ;
for ( V_222 = 0 ; V_222 < V_2 -> V_223 ; V_222 ++ ) {
if ( ! V_2 -> V_231 [ V_222 ] )
continue;
if ( ! F_103 ( & V_2 -> V_232 [ V_222 ] , V_233 ) )
return;
if ( V_222 < V_234 )
V_229 = F_1 ( V_2 , V_222 ) + 1 ;
else
V_229 = 0 ;
F_104 ( F_105 ( V_229 , V_2 -> V_51 ) ,
V_2 -> V_232 [ V_222 ] ) ;
V_230 = V_2 -> V_225 [ V_222 ] . V_235 ;
F_106 ( V_230 , V_2 -> V_232 [ V_222 ] ) ;
}
}
static int F_107 ( struct V_1 * V_2 )
{
int V_210 , V_221 = 0 ;
int V_235 ;
F_108 (irq)
sprintf ( V_2 -> V_236 [ V_210 ] , L_22 ,
V_2 -> V_34 , V_210 ) ;
F_109 (irq)
sprintf ( V_2 -> V_236 [ V_210 ] , L_23 ,
V_2 -> V_34 , V_210 - V_234 ) ;
F_110 (irq)
sprintf ( V_2 -> V_236 [ V_210 ] , L_24 ,
V_2 -> V_34 , V_210 - V_237 ) ;
for ( V_210 = 0 ; V_210 < V_2 -> V_87 -> V_117 ; V_210 ++ ) {
V_235 = V_2 -> V_225 [ V_210 ] . V_235 ;
V_221 = F_111 ( V_235 , F_92 ,
0 , V_2 -> V_236 [ V_210 ] , V_2 -> V_157 [ V_210 ] ) ;
if ( V_221 )
goto V_119;
V_2 -> V_231 [ V_210 ] = true ;
}
for ( V_210 = V_237 ;
V_210 < ( V_237 + V_2 -> V_87 -> V_217 ) ; V_210 ++ ) {
V_235 = V_2 -> V_225 [ V_210 ] . V_235 ;
V_221 = F_111 ( V_235 , F_94 ,
0 , V_2 -> V_236 [ V_210 ] , V_2 ) ;
if ( V_221 )
goto V_119;
V_2 -> V_231 [ V_210 ] = true ;
}
sprintf ( V_2 -> V_236 [ V_238 ] ,
L_25 , V_2 -> V_34 ) ;
V_210 = V_238 ;
V_221 = F_111 ( V_2 -> V_225 [ V_210 ] . V_235 ,
F_97 ,
0 , V_2 -> V_236 [ V_210 ] , V_2 ) ;
if ( V_221 )
goto V_119;
V_2 -> V_231 [ V_210 ] = true ;
F_102 ( V_2 ) ;
V_119:
if ( V_221 )
F_12 ( V_2 -> V_33 , L_26 , V_210 ) ;
return V_221 ;
}
static void F_112 ( struct V_1 * V_2 )
{
int V_210 ;
for ( V_210 = 0 ; V_210 < V_2 -> V_223 ; V_210 ++ ) {
if ( ! V_2 -> V_231 [ V_210 ] )
continue;
F_106 ( V_2 -> V_225 [ V_210 ] . V_235 , NULL ) ;
F_113 ( V_2 -> V_232 [ V_210 ] ) ;
if ( V_210 < V_234 )
F_114 ( V_2 -> V_225 [ V_210 ] . V_235 , V_2 -> V_157 [ V_210 ] ) ;
else
F_114 ( V_2 -> V_225 [ V_210 ] . V_235 , V_2 ) ;
V_2 -> V_231 [ V_210 ] = false ;
}
F_100 ( V_2 ) ;
}
static int F_115 ( struct V_1 * V_2 )
{
int V_221 = 0 ;
int V_210 = V_239 ;
if ( V_2 -> V_228 )
return 0 ;
if ( ! F_98 ( V_2 ) )
return 1 ;
sprintf ( V_2 -> V_236 [ V_210 ] , L_27 , L_28 ) ;
V_221 = F_111 ( V_2 -> V_225 [ V_210 ] . V_235 ,
F_91 , 0 , V_2 -> V_236 [ V_210 ] , V_2 ) ;
if ( V_221 )
return V_221 ;
V_2 -> V_231 [ V_210 ] = true ;
F_81 ( V_2 , V_79 , 0 ) ;
if ( ! F_13 ( V_2 ) ) {
F_84 ( V_2 , V_79 , 0 ) ;
F_112 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static T_6 F_116 ( struct V_7 * V_8 , struct V_80 * V_33 )
{
struct V_1 * V_2 = F_46 ( V_33 ) ;
int V_240 = F_117 ( V_8 ) ;
struct V_184 * V_185 = F_71 ( V_33 , V_240 ) ;
if ( V_8 -> V_9 <= V_241 ) {
F_118 ( V_8 ) ;
return V_242 ;
}
if ( ! F_72 ( V_185 ) && ! F_119 ( V_2 , V_8 ) ) {
F_120 ( V_185 ) ;
V_2 -> V_10 . V_243 ++ ;
if ( F_75 ( V_2 ) )
F_76 ( V_33 ,
L_29 ,
V_33 -> V_69 , V_240 ) ;
return V_244 ;
}
return V_242 ;
}
static inline void F_121 ( struct V_1 * V_2 )
{
struct V_204 * V_216 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_87 -> V_117 ; V_3 ++ ) {
V_216 = V_2 -> V_157 [ V_3 ] ;
if ( ! V_216 )
continue;
V_2 -> V_157 [ V_3 ] = NULL ;
F_122 ( V_216 ) ;
}
}
int F_123 ( struct V_80 * V_33 )
{
int V_210 , V_3 ;
struct V_1 * V_2 = F_46 ( V_33 ) ;
struct V_182 * V_87 = V_2 -> V_87 ;
struct V_204 * V_216 = NULL ;
union V_23 V_24 = {} ;
V_24 . V_25 . V_25 = V_245 ;
F_10 ( V_2 , & V_24 ) ;
F_21 ( V_33 ) ;
F_22 ( V_2 -> V_33 ) ;
V_2 -> V_57 = false ;
if ( ! V_2 -> V_4 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_72 ; V_3 ++ ) {
if ( ! V_2 -> V_76 [ V_3 ] )
continue;
F_123 ( V_2 -> V_76 [ V_3 ] -> V_33 ) ;
V_2 -> V_76 [ V_3 ] = NULL ;
}
}
for ( V_3 = 0 ; V_3 < V_87 -> V_217 ; V_3 ++ ) {
F_84 ( V_2 , V_218 , V_3 ) ;
F_23 ( V_2 , V_218 , V_3 ) ;
}
F_84 ( V_2 , V_208 , 0 ) ;
F_23 ( V_2 , V_208 , 0 ) ;
for ( V_210 = 0 ; V_210 < V_2 -> V_223 ; V_210 ++ )
F_124 ( V_2 -> V_225 [ V_210 ] . V_235 ) ;
F_125 ( & V_2 -> V_219 ) ;
F_125 ( & V_2 -> V_220 ) ;
if ( V_2 -> V_246 )
F_126 ( & V_2 -> V_247 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_87 -> V_117 ; V_3 ++ ) {
V_216 = V_2 -> V_157 [ V_3 ] ;
if ( ! V_216 )
continue;
F_127 ( & V_216 -> V_157 ) ;
F_84 ( V_2 , V_205 , V_3 ) ;
F_23 ( V_2 , V_205 , V_3 ) ;
F_128 ( & V_216 -> V_157 ) ;
F_129 ( & V_216 -> V_157 ) ;
}
F_83 ( V_33 ) ;
F_44 ( V_2 , false ) ;
F_43 ( V_2 , false ) ;
F_84 ( V_2 , V_79 , 0 ) ;
F_112 ( V_2 ) ;
F_121 ( V_2 ) ;
V_2 -> V_78 = V_2 ;
return 0 ;
}
int F_36 ( struct V_80 * V_33 )
{
int V_119 , V_3 ;
struct V_1 * V_2 = F_46 ( V_33 ) ;
struct V_182 * V_87 = V_2 -> V_87 ;
struct V_204 * V_216 = NULL ;
V_2 -> V_248 = V_33 -> V_248 ;
F_21 ( V_33 ) ;
V_119 = F_115 ( V_2 ) ;
if ( V_119 )
return V_119 ;
for ( V_3 = 0 ; V_3 < V_87 -> V_117 ; V_3 ++ ) {
V_216 = F_130 ( sizeof( * V_216 ) , V_233 ) ;
if ( ! V_216 ) {
V_119 = - V_249 ;
goto V_250;
}
V_216 -> V_175 = V_3 ;
V_216 -> V_1 = V_2 ;
F_131 ( V_33 , & V_216 -> V_157 , F_78 ,
V_251 ) ;
F_132 ( & V_216 -> V_157 ) ;
V_2 -> V_157 [ V_3 ] = V_216 ;
}
if ( F_133 ( V_33 -> V_54 ) ) {
F_134 ( V_33 ) ;
F_24 ( V_2 , V_33 ) ;
}
if ( V_2 -> V_53 ) {
V_2 -> V_53 = false ;
F_24 ( V_2 , V_33 ) ;
}
F_135 ( & V_2 -> V_220 , F_82 ,
( unsigned long ) V_2 ) ;
F_135 ( & V_2 -> V_219 , V_252 ,
( unsigned long ) V_2 ) ;
F_136 ( & V_2 -> V_247 , V_253 ) ;
V_2 -> V_85 = V_85 ;
if ( ! V_2 -> V_4 )
F_25 ( V_2 ) ;
F_34 ( V_2 ) ;
if ( V_2 -> V_4 )
F_39 ( V_2 ) ;
if ( ! V_2 -> V_4 )
F_30 ( V_2 ) ;
V_119 = F_107 ( V_2 ) ;
if ( V_119 )
goto V_254;
V_119 = F_42 ( V_2 ) ;
if ( V_119 )
goto V_254;
F_137 () ;
F_3 ( V_2 , V_209 , - 1 ) ;
F_81 ( V_2 , V_208 , 0 ) ;
for ( V_3 = 0 ; V_3 < V_87 -> V_117 ; V_3 ++ )
F_81 ( V_2 , V_205 , V_3 ) ;
for ( V_3 = 0 ; V_3 < V_87 -> V_217 ; V_3 ++ )
F_81 ( V_2 , V_218 , V_3 ) ;
V_2 -> V_10 . V_243 = 0 ;
V_2 -> V_10 . V_201 = 0 ;
return 0 ;
V_254:
F_84 ( V_2 , V_79 , 0 ) ;
F_112 ( V_2 ) ;
F_125 ( & V_2 -> V_220 ) ;
F_125 ( & V_2 -> V_219 ) ;
V_250:
for ( V_3 = 0 ; V_3 < V_87 -> V_117 ; V_3 ++ ) {
V_216 = V_2 -> V_157 [ V_3 ] ;
if ( ! V_216 )
continue;
F_128 ( & V_216 -> V_157 ) ;
F_129 ( & V_216 -> V_157 ) ;
}
F_121 ( V_2 ) ;
return V_119 ;
}
static int F_138 ( struct V_1 * V_2 , int V_248 )
{
union V_23 V_24 = {} ;
V_24 . V_255 . V_25 = V_256 ;
V_24 . V_255 . V_257 = V_248 ;
V_24 . V_255 . V_34 = V_2 -> V_34 ;
return F_10 ( V_2 , & V_24 ) ;
}
static int F_139 ( struct V_80 * V_33 , int V_258 )
{
struct V_1 * V_2 = F_46 ( V_33 ) ;
if ( V_258 > V_259 )
return - V_32 ;
if ( V_258 < V_260 )
return - V_32 ;
if ( F_138 ( V_2 , V_258 ) )
return - V_32 ;
V_33 -> V_248 = V_258 ;
V_2 -> V_248 = V_258 ;
return 0 ;
}
static int F_140 ( struct V_80 * V_33 , void * V_261 )
{
struct V_262 * V_21 = V_261 ;
struct V_1 * V_2 = F_46 ( V_33 ) ;
if ( ! F_141 ( V_21 -> V_263 ) )
return - V_264 ;
memcpy ( V_33 -> V_54 , V_21 -> V_263 , V_33 -> V_265 ) ;
if ( V_2 -> V_228 ) {
if ( F_24 ( V_2 , V_33 ) )
return - V_35 ;
} else {
V_2 -> V_53 = true ;
}
return 0 ;
}
void F_142 ( struct V_1 * V_2 )
{
int V_266 = 0 ;
union V_23 V_24 = {} ;
if ( ! F_143 ( V_2 -> V_33 ) )
return;
V_24 . V_40 . V_25 = V_66 ;
V_24 . V_40 . V_34 = V_2 -> V_34 ;
V_24 . V_40 . V_39 = 1 ;
while ( V_266 < V_267 ) {
V_24 . V_40 . V_42 = V_266 ;
if ( F_10 ( V_2 , & V_24 ) )
return;
V_266 ++ ;
}
V_266 = 0 ;
V_24 . V_40 . V_39 = 0 ;
while ( V_266 < V_268 ) {
V_24 . V_40 . V_42 = V_266 ;
if ( F_10 ( V_2 , & V_24 ) )
return;
V_266 ++ ;
}
}
void F_144 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_269 * V_43 = & V_2 -> V_270 ;
struct V_271 * V_10 = & V_2 -> V_10 ;
struct V_182 * V_87 = V_2 -> V_87 ;
#define F_145 ( T_7 ) \
nicvf_reg_read(nic, NIC_VNIC_RX_STAT_0_13 | (reg << 3))
#define F_146 ( T_7 ) \
nicvf_reg_read(nic, NIC_VNIC_TX_STAT_0_4 | (reg << 3))
V_43 -> V_272 = F_145 ( V_273 ) ;
V_43 -> V_274 = F_145 ( V_275 ) ;
V_43 -> V_276 = F_145 ( V_277 ) ;
V_43 -> V_278 = F_145 ( V_279 ) ;
V_43 -> V_280 = F_145 ( V_281 ) ;
V_43 -> V_282 = F_145 ( V_283 ) ;
V_43 -> V_284 = F_145 ( V_285 ) ;
V_43 -> V_286 = F_145 ( V_287 ) ;
V_43 -> V_288 = F_145 ( V_289 ) ;
V_43 -> V_290 = F_145 ( V_291 ) ;
V_43 -> V_292 = F_145 ( V_293 ) ;
V_43 -> V_294 = F_145 ( V_295 ) ;
V_43 -> V_296 = F_145 ( V_297 ) ;
V_43 -> V_298 = F_145 ( V_299 ) ;
V_43 -> V_300 = F_146 ( V_301 ) ;
V_43 -> V_302 = F_146 ( V_303 ) ;
V_43 -> V_304 = F_146 ( V_305 ) ;
V_43 -> V_306 = F_146 ( V_307 ) ;
V_43 -> V_308 = F_146 ( V_309 ) ;
V_10 -> V_310 = V_43 -> V_302 +
V_43 -> V_304 +
V_43 -> V_306 ;
V_10 -> V_311 = V_43 -> V_274 +
V_43 -> V_276 +
V_43 -> V_278 ;
V_10 -> V_312 = V_43 -> V_284 +
V_43 -> V_288 ;
V_10 -> V_308 = V_43 -> V_308 ;
for ( V_3 = 0 ; V_3 < V_87 -> V_86 ; V_3 ++ )
F_147 ( V_2 , V_3 ) ;
for ( V_3 = 0 ; V_3 < V_87 -> V_116 ; V_3 ++ )
F_148 ( V_2 , V_3 ) ;
}
static struct V_313 * F_149 ( struct V_80 * V_33 ,
struct V_313 * V_43 )
{
struct V_1 * V_2 = F_46 ( V_33 ) ;
struct V_269 * V_270 = & V_2 -> V_270 ;
struct V_271 * V_10 = & V_2 -> V_10 ;
F_144 ( V_2 ) ;
V_43 -> V_272 = V_270 -> V_272 ;
V_43 -> V_314 = V_10 -> V_311 ;
V_43 -> V_315 = V_10 -> V_312 ;
V_43 -> V_316 = V_270 -> V_278 ;
V_43 -> V_317 = V_270 -> V_300 ;
V_43 -> V_318 = V_10 -> V_310 ;
V_43 -> V_319 = V_10 -> V_308 ;
return V_43 ;
}
static void F_150 ( struct V_80 * V_203 )
{
struct V_1 * V_2 = F_46 ( V_203 ) ;
if ( F_75 ( V_2 ) )
F_76 ( V_203 , L_30 ,
V_203 -> V_69 ) ;
V_2 -> V_10 . V_320 ++ ;
F_151 ( & V_2 -> V_321 ) ;
}
static void F_152 ( struct V_322 * V_323 )
{
struct V_1 * V_2 ;
V_2 = F_79 ( V_323 , struct V_1 , V_321 ) ;
if ( ! F_143 ( V_2 -> V_33 ) )
return;
F_123 ( V_2 -> V_33 ) ;
F_36 ( V_2 -> V_33 ) ;
F_153 ( V_2 -> V_33 ) ;
}
static int F_154 ( struct V_1 * V_2 ,
T_8 V_146 )
{
union V_23 V_24 = {} ;
V_24 . V_324 . V_25 = V_325 ;
V_24 . V_324 . V_34 = V_2 -> V_34 ;
V_24 . V_324 . V_105 = ( V_146 & V_326 ) != 0 ;
return F_10 ( V_2 , & V_24 ) ;
}
static T_8 F_155 ( struct V_80 * V_33 ,
T_8 V_146 )
{
struct V_1 * V_2 = F_46 ( V_33 ) ;
if ( ( V_146 & V_326 ) &&
F_143 ( V_33 ) && ! V_2 -> V_56 )
V_146 &= ~ V_326 ;
return V_146 ;
}
static int F_156 ( struct V_80 * V_33 ,
T_8 V_146 )
{
struct V_1 * V_2 = F_46 ( V_33 ) ;
T_8 V_327 = V_146 ^ V_33 -> V_146 ;
if ( V_327 & V_328 )
F_157 ( V_2 , V_146 ) ;
if ( ( V_327 & V_326 ) && F_143 ( V_33 ) )
return F_154 ( V_2 , V_146 ) ;
return 0 ;
}
static int F_158 ( struct V_329 * V_227 , const struct V_330 * V_331 )
{
struct V_332 * V_203 = & V_227 -> V_203 ;
struct V_80 * V_33 ;
struct V_1 * V_2 ;
int V_119 , V_333 ;
T_9 V_334 ;
V_119 = F_159 ( V_227 ) ;
if ( V_119 ) {
F_160 ( V_203 , L_31 ) ;
return V_119 ;
}
V_119 = F_161 ( V_227 , V_335 ) ;
if ( V_119 ) {
F_160 ( V_203 , L_32 , V_119 ) ;
goto V_336;
}
V_119 = F_162 ( V_227 , F_163 ( 48 ) ) ;
if ( V_119 ) {
F_160 ( V_203 , L_33 ) ;
goto V_337;
}
V_119 = F_164 ( V_227 , F_163 ( 48 ) ) ;
if ( V_119 ) {
F_160 ( V_203 , L_34 ) ;
goto V_337;
}
V_333 = V_6 ;
if ( V_227 -> V_338 ) {
V_333 = F_165 ( F_166 () , V_6 ) ;
V_333 = F_28 ( V_333 ,
( V_339 + 1 ) * V_6 ) ;
}
V_33 = F_167 ( sizeof( struct V_1 ) , V_333 , V_333 ) ;
if ( ! V_33 ) {
V_119 = - V_249 ;
goto V_337;
}
F_168 ( V_227 , V_33 ) ;
F_169 ( V_33 , & V_227 -> V_203 ) ;
V_2 = F_46 ( V_33 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_227 = V_227 ;
V_2 -> V_78 = V_2 ;
V_2 -> V_340 = V_333 ;
V_2 -> V_20 = F_170 ( V_227 , V_341 , 0 ) ;
if ( ! V_2 -> V_20 ) {
F_160 ( V_203 , L_35 ) ;
V_119 = - V_249 ;
goto V_342;
}
V_119 = F_171 ( V_2 ) ;
if ( V_119 )
goto V_342;
V_119 = F_115 ( V_2 ) ;
if ( V_119 )
goto V_342;
F_38 ( V_2 ) ;
if ( ! F_172 ( V_2 -> V_227 ) )
V_2 -> V_141 = true ;
F_173 ( V_2 -> V_227 , V_343 , & V_334 ) ;
if ( V_334 == 0xA134 )
V_2 -> V_344 = true ;
if ( V_2 -> V_4 )
return 0 ;
V_119 = F_37 ( V_33 , V_2 -> V_113 , V_2 -> V_111 ) ;
if ( V_119 )
goto V_345;
V_33 -> V_163 = ( V_164 | V_346 | V_347 |
V_348 | V_174 |
V_328 ) ;
V_33 -> V_163 |= V_147 ;
V_33 -> V_146 |= V_33 -> V_163 ;
V_33 -> V_163 |= V_326 ;
V_33 -> V_349 = V_347 | V_346 | V_348 ;
V_33 -> V_350 = & V_351 ;
V_33 -> V_352 = V_353 ;
F_174 ( & V_2 -> V_321 , F_152 ) ;
V_119 = F_175 ( V_33 ) ;
if ( V_119 ) {
F_160 ( V_203 , L_36 ) ;
goto V_345;
}
V_2 -> V_354 = V_355 ;
F_176 ( V_33 ) ;
return 0 ;
V_345:
F_112 ( V_2 ) ;
V_342:
F_168 ( V_227 , NULL ) ;
F_177 ( V_33 ) ;
V_337:
F_178 ( V_227 ) ;
V_336:
F_179 ( V_227 ) ;
return V_119 ;
}
static void F_180 ( struct V_329 * V_227 )
{
struct V_80 * V_33 = F_181 ( V_227 ) ;
struct V_1 * V_2 ;
struct V_80 * V_356 ;
if ( ! V_33 )
return;
V_2 = F_46 ( V_33 ) ;
V_356 = V_2 -> V_78 -> V_33 ;
if ( V_356 && ( V_356 -> V_357 == V_358 ) )
F_182 ( V_356 ) ;
F_112 ( V_2 ) ;
F_168 ( V_227 , NULL ) ;
F_177 ( V_33 ) ;
F_178 ( V_227 ) ;
F_179 ( V_227 ) ;
}
static void F_183 ( struct V_329 * V_227 )
{
F_180 ( V_227 ) ;
}
static int T_10 F_184 ( void )
{
F_185 ( L_37 , V_335 , V_359 ) ;
return F_186 ( & V_360 ) ;
}
static void T_11 F_187 ( void )
{
F_188 ( & V_360 ) ;
}
