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
V_127 = & V_2 -> V_87 -> V_127 [ V_124 -> V_130 ] ;
V_129 = (struct V_128 * ) F_47 ( V_127 , V_124 -> V_131 ) ;
if ( V_129 -> V_132 != V_133 )
return;
F_16 ( V_2 -> V_33 ,
L_12 ,
V_134 , V_124 -> V_135 , V_124 -> V_130 ,
V_124 -> V_131 , V_129 -> V_136 ) ;
F_48 ( V_2 , V_122 , V_124 ) ;
V_8 = (struct V_7 * ) V_127 -> V_137 [ V_124 -> V_131 ] ;
if ( V_8 ) {
F_49 ( V_127 , V_129 -> V_136 + 1 ) ;
F_50 ( V_8 ) ;
F_51 ( V_8 ) ;
V_127 -> V_137 [ V_124 -> V_131 ] = ( T_2 ) NULL ;
} else {
if ( ! V_2 -> V_138 )
F_49 ( V_127 , V_129 -> V_136 + 1 ) ;
}
}
static inline void F_52 ( struct V_80 * V_33 ,
struct V_139 * V_140 ,
struct V_7 * V_8 )
{
T_1 V_141 ;
T_4 V_142 ;
if ( ! ( V_33 -> V_143 & V_144 ) )
return;
switch ( V_140 -> V_145 ) {
case V_146 :
case V_147 :
V_141 = V_148 ;
V_142 = V_140 -> V_149 ;
break;
case V_150 :
V_141 = V_151 ;
V_142 = V_140 -> V_149 ;
break;
default:
V_141 = V_152 ;
V_142 = 0 ;
}
F_53 ( V_8 , V_142 , V_141 ) ;
}
static void F_54 ( struct V_80 * V_33 ,
struct V_153 * V_154 ,
struct V_139 * V_140 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 = F_46 ( V_33 ) ;
int V_119 = 0 ;
int V_155 ;
V_155 = F_1 ( V_2 , V_140 -> V_155 ) ;
if ( V_2 -> V_4 ) {
V_2 = V_2 -> V_78 ;
V_33 = V_2 -> V_33 ;
}
V_119 = F_55 ( V_2 , V_140 ) ;
if ( V_119 && ! V_140 -> V_156 )
return;
V_8 = F_56 ( V_2 , V_140 ) ;
if ( ! V_8 ) {
F_16 ( V_2 -> V_33 , L_13 ) ;
return;
}
if ( F_57 ( V_2 ) ) {
F_18 ( V_2 -> V_33 , L_14 , V_33 -> V_69 ,
V_8 , V_8 -> V_9 ) ;
F_58 ( V_157 , L_15 , V_158 , 16 , 1 ,
V_8 -> V_159 , V_8 -> V_9 , true ) ;
}
if ( V_119 ) {
F_59 ( V_8 ) ;
return;
}
F_2 ( V_2 , V_8 ) ;
F_52 ( V_33 , V_140 , V_8 ) ;
F_60 ( V_8 , V_155 ) ;
if ( V_33 -> V_160 & V_161 ) {
V_8 -> V_162 = V_163 ;
} else {
F_61 ( V_8 ) ;
}
V_8 -> V_164 = F_62 ( V_8 , V_33 ) ;
if ( V_140 -> V_165 && V_140 -> V_166 )
F_63 ( V_8 , F_64 ( V_167 ) ,
F_65 ( ( V_168 V_169 ) V_140 -> V_170 ) ) ;
if ( V_154 && ( V_33 -> V_143 & V_171 ) )
F_66 ( V_154 , V_8 ) ;
else
F_67 ( V_8 ) ;
}
static int F_68 ( struct V_80 * V_33 , T_1 V_172 ,
struct V_153 * V_154 , int V_173 )
{
int V_174 , V_175 = 0 , V_176 = 0 ;
int V_177 , V_178 ;
struct V_1 * V_2 = F_46 ( V_33 ) ;
struct V_179 * V_87 = V_2 -> V_87 ;
struct V_121 * V_122 = & V_87 -> V_122 [ V_172 ] ;
struct V_139 * V_180 ;
struct V_181 * V_182 ;
F_69 ( & V_122 -> V_183 ) ;
V_184:
V_174 = 0 ;
V_177 = F_8 ( V_2 , V_185 , V_172 ) ;
V_177 &= V_186 ;
if ( ! V_177 )
goto V_187;
V_178 = F_8 ( V_2 , V_188 , V_172 ) >> 9 ;
V_178 &= 0xFFFF ;
F_16 ( V_2 -> V_33 , L_16 ,
V_134 , V_172 , V_177 , V_178 ) ;
while ( V_174 < V_177 ) {
V_180 = (struct V_139 * ) F_70 ( V_122 , V_178 ) ;
V_178 ++ ;
V_178 &= ( V_122 -> V_189 . V_190 - 1 ) ;
F_50 ( (struct V_139 * ) F_70 ( V_122 , V_178 ) ) ;
if ( ( V_175 >= V_173 ) && V_154 &&
( V_180 -> V_125 != V_191 ) ) {
break;
}
F_16 ( V_2 -> V_33 , L_17 ,
V_172 , V_180 -> V_125 ) ;
switch ( V_180 -> V_125 ) {
case V_192 :
F_54 ( V_33 , V_154 , V_180 ) ;
V_175 ++ ;
break;
case V_191 :
F_45 ( V_33 , V_122 ,
( void * ) V_180 , V_191 ) ;
V_176 ++ ;
break;
case V_193 :
case V_194 :
case V_195 :
case V_196 :
break;
}
V_174 ++ ;
}
F_16 ( V_2 -> V_33 ,
L_18 ,
V_134 , V_172 , V_174 , V_175 , V_173 ) ;
F_7 ( V_2 , V_197 ,
V_172 , V_174 ) ;
if ( ( V_175 < V_173 ) && V_154 )
goto V_184;
V_187:
if ( V_176 ) {
V_33 = V_2 -> V_78 -> V_33 ;
V_182 = F_71 ( V_33 ,
F_1 ( V_2 , V_172 ) ) ;
V_2 = V_2 -> V_78 ;
if ( F_72 ( V_182 ) && F_73 ( V_33 ) ) {
F_74 ( V_182 ) ;
V_2 -> V_10 . V_198 ++ ;
if ( F_75 ( V_2 ) )
F_76 ( V_33 ,
L_19 ,
V_33 -> V_69 , V_172 ) ;
}
}
F_77 ( & V_122 -> V_183 ) ;
return V_175 ;
}
static int F_78 ( struct V_153 * V_154 , int V_173 )
{
T_2 V_199 ;
int V_175 = 0 ;
struct V_80 * V_33 = V_154 -> V_200 ;
struct V_1 * V_2 = F_46 ( V_33 ) ;
struct V_201 * V_122 ;
V_122 = F_79 ( V_154 , struct V_201 , V_154 ) ;
V_175 = F_68 ( V_33 , V_122 -> V_172 , V_154 , V_173 ) ;
if ( V_175 < V_173 ) {
F_80 ( V_154 ) ;
V_199 = F_8 ( V_2 , V_188 ,
V_122 -> V_172 ) ;
F_23 ( V_2 , V_202 , V_122 -> V_172 ) ;
F_7 ( V_2 , V_188 ,
V_122 -> V_172 , V_199 ) ;
F_81 ( V_2 , V_202 , V_122 -> V_172 ) ;
}
return V_175 ;
}
static void F_82 ( unsigned long V_159 )
{
struct V_1 * V_2 = (struct V_1 * ) V_159 ;
struct V_179 * V_87 = V_2 -> V_87 ;
int V_3 ;
T_2 V_203 ;
F_83 ( V_2 -> V_33 ) ;
for ( V_3 = 0 ; V_3 < V_87 -> V_117 ; V_3 ++ ) {
V_203 = F_8 ( V_2 , V_185 ,
V_3 ) ;
if ( ! ( V_203 & V_204 ) )
continue;
F_84 ( V_2 , V_202 , V_3 ) ;
F_85 ( V_2 , V_3 ) ;
F_68 ( V_2 -> V_33 , V_3 , NULL , 0 ) ;
F_86 ( V_2 , V_87 , V_3 , true ) ;
F_87 ( V_2 -> V_33 , & V_87 -> V_127 [ V_3 ] , V_3 ) ;
F_88 ( V_2 , & V_87 -> V_127 [ V_3 ] , V_3 ) ;
F_81 ( V_2 , V_202 , V_3 ) ;
}
F_20 ( V_2 -> V_33 ) ;
F_81 ( V_2 , V_205 , 0 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
if ( F_90 ( V_2 ) )
F_18 ( V_2 -> V_33 , L_20 ,
V_2 -> V_33 -> V_69 , F_5 ( V_2 , V_206 ) ) ;
}
static T_5 F_91 ( int V_207 , void * V_208 )
{
struct V_1 * V_2 = (struct V_1 * ) V_208 ;
T_2 V_209 ;
F_89 ( V_2 ) ;
V_209 = F_5 ( V_2 , V_206 ) ;
if ( ! ( V_209 & V_210 ) )
return V_211 ;
F_15 ( V_2 ) ;
return V_211 ;
}
static T_5 F_92 ( int V_207 , void * V_212 )
{
struct V_201 * V_213 = (struct V_201 * ) V_212 ;
struct V_1 * V_2 = V_213 -> V_1 ;
int V_3 = V_213 -> V_172 ;
F_89 ( V_2 ) ;
F_84 ( V_2 , V_202 , V_3 ) ;
F_93 ( & V_213 -> V_154 ) ;
F_23 ( V_2 , V_202 , V_3 ) ;
return V_211 ;
}
static T_5 F_94 ( int V_207 , void * V_208 )
{
struct V_1 * V_2 = (struct V_1 * ) V_208 ;
T_1 V_3 ;
F_89 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_87 -> V_214 ; V_3 ++ ) {
if ( ! F_95 ( V_2 , V_215 , V_3 ) )
continue;
F_84 ( V_2 , V_215 , V_3 ) ;
F_96 ( & V_2 -> V_216 ) ;
F_23 ( V_2 , V_215 , V_3 ) ;
}
return V_211 ;
}
static T_5 F_97 ( int V_207 , void * V_208 )
{
struct V_1 * V_2 = (struct V_1 * ) V_208 ;
F_89 ( V_2 ) ;
F_84 ( V_2 , V_205 , 0 ) ;
F_96 ( & V_2 -> V_217 ) ;
F_23 ( V_2 , V_205 , 0 ) ;
return V_211 ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_218 , V_219 ;
V_2 -> V_220 = V_221 ;
for ( V_219 = 0 ; V_219 < V_2 -> V_220 ; V_219 ++ )
V_2 -> V_222 [ V_219 ] . V_223 = V_219 ;
V_218 = F_99 ( V_2 -> V_224 , V_2 -> V_222 , V_2 -> V_220 ) ;
if ( V_218 ) {
F_12 ( V_2 -> V_33 ,
L_21 , V_2 -> V_220 ) ;
return 0 ;
}
V_2 -> V_225 = 1 ;
return 1 ;
}
static void F_100 ( struct V_1 * V_2 )
{
if ( V_2 -> V_225 ) {
F_101 ( V_2 -> V_224 ) ;
V_2 -> V_225 = 0 ;
V_2 -> V_220 = 0 ;
}
}
static int F_102 ( struct V_1 * V_2 )
{
int V_207 , V_218 = 0 ;
int V_226 ;
F_103 (irq)
sprintf ( V_2 -> V_227 [ V_207 ] , L_22 ,
V_2 -> V_34 , V_207 ) ;
F_104 (irq)
sprintf ( V_2 -> V_227 [ V_207 ] , L_23 ,
V_2 -> V_34 , V_207 - V_228 ) ;
F_105 (irq)
sprintf ( V_2 -> V_227 [ V_207 ] , L_24 ,
V_2 -> V_34 , V_207 - V_229 ) ;
for ( V_207 = 0 ; V_207 < V_2 -> V_87 -> V_117 ; V_207 ++ ) {
V_226 = V_2 -> V_222 [ V_207 ] . V_226 ;
V_218 = F_106 ( V_226 , F_92 ,
0 , V_2 -> V_227 [ V_207 ] , V_2 -> V_154 [ V_207 ] ) ;
if ( V_218 )
goto V_119;
V_2 -> V_230 [ V_207 ] = true ;
}
for ( V_207 = V_229 ;
V_207 < ( V_229 + V_2 -> V_87 -> V_214 ) ; V_207 ++ ) {
V_226 = V_2 -> V_222 [ V_207 ] . V_226 ;
V_218 = F_106 ( V_226 , F_94 ,
0 , V_2 -> V_227 [ V_207 ] , V_2 ) ;
if ( V_218 )
goto V_119;
V_2 -> V_230 [ V_207 ] = true ;
}
sprintf ( V_2 -> V_227 [ V_231 ] ,
L_25 , V_2 -> V_34 ) ;
V_207 = V_231 ;
V_218 = F_106 ( V_2 -> V_222 [ V_207 ] . V_226 ,
F_97 ,
0 , V_2 -> V_227 [ V_207 ] , V_2 ) ;
if ( ! V_218 )
V_2 -> V_230 [ V_207 ] = true ;
V_119:
if ( V_218 )
F_12 ( V_2 -> V_33 , L_26 , V_207 ) ;
return V_218 ;
}
static void F_107 ( struct V_1 * V_2 )
{
int V_207 ;
for ( V_207 = 0 ; V_207 < V_2 -> V_220 ; V_207 ++ ) {
if ( ! V_2 -> V_230 [ V_207 ] )
continue;
if ( V_207 < V_228 )
F_108 ( V_2 -> V_222 [ V_207 ] . V_226 , V_2 -> V_154 [ V_207 ] ) ;
else
F_108 ( V_2 -> V_222 [ V_207 ] . V_226 , V_2 ) ;
V_2 -> V_230 [ V_207 ] = false ;
}
F_100 ( V_2 ) ;
}
static int F_109 ( struct V_1 * V_2 )
{
int V_218 = 0 ;
int V_207 = V_232 ;
if ( V_2 -> V_225 )
return 0 ;
if ( ! F_98 ( V_2 ) )
return 1 ;
sprintf ( V_2 -> V_227 [ V_207 ] , L_27 , L_28 ) ;
V_218 = F_106 ( V_2 -> V_222 [ V_207 ] . V_226 ,
F_91 , 0 , V_2 -> V_227 [ V_207 ] , V_2 ) ;
if ( V_218 )
return V_218 ;
V_2 -> V_230 [ V_207 ] = true ;
F_81 ( V_2 , V_79 , 0 ) ;
if ( ! F_13 ( V_2 ) ) {
F_84 ( V_2 , V_79 , 0 ) ;
F_107 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static T_6 F_110 ( struct V_7 * V_8 , struct V_80 * V_33 )
{
struct V_1 * V_2 = F_46 ( V_33 ) ;
int V_233 = F_111 ( V_8 ) ;
struct V_181 * V_182 = F_71 ( V_33 , V_233 ) ;
if ( V_8 -> V_9 <= V_234 ) {
F_112 ( V_8 ) ;
return V_235 ;
}
if ( ! F_72 ( V_182 ) && ! F_113 ( V_2 , V_8 ) ) {
F_114 ( V_182 ) ;
V_2 -> V_10 . V_236 ++ ;
if ( F_75 ( V_2 ) )
F_76 ( V_33 ,
L_29 ,
V_33 -> V_69 , V_233 ) ;
return V_237 ;
}
return V_235 ;
}
static inline void F_115 ( struct V_1 * V_2 )
{
struct V_201 * V_213 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_87 -> V_117 ; V_3 ++ ) {
V_213 = V_2 -> V_154 [ V_3 ] ;
if ( ! V_213 )
continue;
V_2 -> V_154 [ V_3 ] = NULL ;
F_116 ( V_213 ) ;
}
}
int F_117 ( struct V_80 * V_33 )
{
int V_207 , V_3 ;
struct V_1 * V_2 = F_46 ( V_33 ) ;
struct V_179 * V_87 = V_2 -> V_87 ;
struct V_201 * V_213 = NULL ;
union V_23 V_24 = {} ;
V_24 . V_25 . V_25 = V_238 ;
F_10 ( V_2 , & V_24 ) ;
F_21 ( V_33 ) ;
F_22 ( V_2 -> V_33 ) ;
V_2 -> V_57 = false ;
if ( ! V_2 -> V_4 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_72 ; V_3 ++ ) {
if ( ! V_2 -> V_76 [ V_3 ] )
continue;
F_117 ( V_2 -> V_76 [ V_3 ] -> V_33 ) ;
V_2 -> V_76 [ V_3 ] = NULL ;
}
}
for ( V_3 = 0 ; V_3 < V_87 -> V_214 ; V_3 ++ ) {
F_84 ( V_2 , V_215 , V_3 ) ;
F_23 ( V_2 , V_215 , V_3 ) ;
}
F_84 ( V_2 , V_205 , 0 ) ;
F_23 ( V_2 , V_205 , 0 ) ;
for ( V_207 = 0 ; V_207 < V_2 -> V_220 ; V_207 ++ )
F_118 ( V_2 -> V_222 [ V_207 ] . V_226 ) ;
F_119 ( & V_2 -> V_216 ) ;
F_119 ( & V_2 -> V_217 ) ;
if ( V_2 -> V_239 )
F_120 ( & V_2 -> V_240 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_87 -> V_117 ; V_3 ++ ) {
V_213 = V_2 -> V_154 [ V_3 ] ;
if ( ! V_213 )
continue;
F_121 ( & V_213 -> V_154 ) ;
F_84 ( V_2 , V_202 , V_3 ) ;
F_23 ( V_2 , V_202 , V_3 ) ;
F_122 ( & V_213 -> V_154 ) ;
F_123 ( & V_213 -> V_154 ) ;
}
F_83 ( V_33 ) ;
F_44 ( V_2 , false ) ;
F_43 ( V_2 , false ) ;
F_84 ( V_2 , V_79 , 0 ) ;
F_107 ( V_2 ) ;
F_115 ( V_2 ) ;
V_2 -> V_78 = V_2 ;
return 0 ;
}
int F_36 ( struct V_80 * V_33 )
{
int V_119 , V_3 ;
struct V_1 * V_2 = F_46 ( V_33 ) ;
struct V_179 * V_87 = V_2 -> V_87 ;
struct V_201 * V_213 = NULL ;
V_2 -> V_241 = V_33 -> V_241 ;
F_21 ( V_33 ) ;
V_119 = F_109 ( V_2 ) ;
if ( V_119 )
return V_119 ;
for ( V_3 = 0 ; V_3 < V_87 -> V_117 ; V_3 ++ ) {
V_213 = F_124 ( sizeof( * V_213 ) , V_242 ) ;
if ( ! V_213 ) {
V_119 = - V_243 ;
goto V_244;
}
V_213 -> V_172 = V_3 ;
V_213 -> V_1 = V_2 ;
F_125 ( V_33 , & V_213 -> V_154 , F_78 ,
V_245 ) ;
F_126 ( & V_213 -> V_154 ) ;
V_2 -> V_154 [ V_3 ] = V_213 ;
}
if ( F_127 ( V_33 -> V_54 ) ) {
F_128 ( V_33 ) ;
F_24 ( V_2 , V_33 ) ;
}
if ( V_2 -> V_53 ) {
V_2 -> V_53 = false ;
F_24 ( V_2 , V_33 ) ;
}
F_129 ( & V_2 -> V_217 , F_82 ,
( unsigned long ) V_2 ) ;
F_129 ( & V_2 -> V_216 , V_246 ,
( unsigned long ) V_2 ) ;
F_130 ( & V_2 -> V_240 , V_247 ) ;
V_2 -> V_85 = V_85 ;
if ( ! V_2 -> V_4 )
F_25 ( V_2 ) ;
F_34 ( V_2 ) ;
if ( V_2 -> V_4 )
F_39 ( V_2 ) ;
if ( ! V_2 -> V_4 )
F_30 ( V_2 ) ;
V_119 = F_102 ( V_2 ) ;
if ( V_119 )
goto V_248;
V_119 = F_42 ( V_2 ) ;
if ( V_119 )
goto V_248;
F_131 () ;
F_3 ( V_2 , V_206 , - 1 ) ;
F_81 ( V_2 , V_205 , 0 ) ;
for ( V_3 = 0 ; V_3 < V_87 -> V_117 ; V_3 ++ )
F_81 ( V_2 , V_202 , V_3 ) ;
for ( V_3 = 0 ; V_3 < V_87 -> V_214 ; V_3 ++ )
F_81 ( V_2 , V_215 , V_3 ) ;
V_2 -> V_10 . V_236 = 0 ;
V_2 -> V_10 . V_198 = 0 ;
return 0 ;
V_248:
F_84 ( V_2 , V_79 , 0 ) ;
F_107 ( V_2 ) ;
F_119 ( & V_2 -> V_217 ) ;
F_119 ( & V_2 -> V_216 ) ;
V_244:
for ( V_3 = 0 ; V_3 < V_87 -> V_117 ; V_3 ++ ) {
V_213 = V_2 -> V_154 [ V_3 ] ;
if ( ! V_213 )
continue;
F_122 ( & V_213 -> V_154 ) ;
F_123 ( & V_213 -> V_154 ) ;
}
F_115 ( V_2 ) ;
return V_119 ;
}
static int F_132 ( struct V_1 * V_2 , int V_241 )
{
union V_23 V_24 = {} ;
V_24 . V_249 . V_25 = V_250 ;
V_24 . V_249 . V_251 = V_241 ;
V_24 . V_249 . V_34 = V_2 -> V_34 ;
return F_10 ( V_2 , & V_24 ) ;
}
static int F_133 ( struct V_80 * V_33 , int V_252 )
{
struct V_1 * V_2 = F_46 ( V_33 ) ;
if ( V_252 > V_253 )
return - V_32 ;
if ( V_252 < V_254 )
return - V_32 ;
if ( F_132 ( V_2 , V_252 ) )
return - V_32 ;
V_33 -> V_241 = V_252 ;
V_2 -> V_241 = V_252 ;
return 0 ;
}
static int F_134 ( struct V_80 * V_33 , void * V_255 )
{
struct V_256 * V_21 = V_255 ;
struct V_1 * V_2 = F_46 ( V_33 ) ;
if ( ! F_135 ( V_21 -> V_257 ) )
return - V_258 ;
memcpy ( V_33 -> V_54 , V_21 -> V_257 , V_33 -> V_259 ) ;
if ( V_2 -> V_225 ) {
if ( F_24 ( V_2 , V_33 ) )
return - V_35 ;
} else {
V_2 -> V_53 = true ;
}
return 0 ;
}
void F_136 ( struct V_1 * V_2 )
{
int V_260 = 0 ;
union V_23 V_24 = {} ;
if ( ! F_137 ( V_2 -> V_33 ) )
return;
V_24 . V_40 . V_25 = V_66 ;
V_24 . V_40 . V_34 = V_2 -> V_34 ;
V_24 . V_40 . V_39 = 1 ;
while ( V_260 < V_261 ) {
V_24 . V_40 . V_42 = V_260 ;
if ( F_10 ( V_2 , & V_24 ) )
return;
V_260 ++ ;
}
V_260 = 0 ;
V_24 . V_40 . V_39 = 0 ;
while ( V_260 < V_262 ) {
V_24 . V_40 . V_42 = V_260 ;
if ( F_10 ( V_2 , & V_24 ) )
return;
V_260 ++ ;
}
}
void F_138 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_263 * V_43 = & V_2 -> V_264 ;
struct V_265 * V_10 = & V_2 -> V_10 ;
struct V_179 * V_87 = V_2 -> V_87 ;
#define F_139 ( T_7 ) \
nicvf_reg_read(nic, NIC_VNIC_RX_STAT_0_13 | (reg << 3))
#define F_140 ( T_7 ) \
nicvf_reg_read(nic, NIC_VNIC_TX_STAT_0_4 | (reg << 3))
V_43 -> V_266 = F_139 ( V_267 ) ;
V_43 -> V_268 = F_139 ( V_269 ) ;
V_43 -> V_270 = F_139 ( V_271 ) ;
V_43 -> V_272 = F_139 ( V_273 ) ;
V_43 -> V_274 = F_139 ( V_275 ) ;
V_43 -> V_276 = F_139 ( V_277 ) ;
V_43 -> V_278 = F_139 ( V_279 ) ;
V_43 -> V_280 = F_139 ( V_281 ) ;
V_43 -> V_282 = F_139 ( V_283 ) ;
V_43 -> V_284 = F_139 ( V_285 ) ;
V_43 -> V_286 = F_139 ( V_287 ) ;
V_43 -> V_288 = F_139 ( V_289 ) ;
V_43 -> V_290 = F_139 ( V_291 ) ;
V_43 -> V_292 = F_139 ( V_293 ) ;
V_43 -> V_294 = F_140 ( V_295 ) ;
V_43 -> V_296 = F_140 ( V_297 ) ;
V_43 -> V_298 = F_140 ( V_299 ) ;
V_43 -> V_300 = F_140 ( V_301 ) ;
V_43 -> V_302 = F_140 ( V_303 ) ;
V_10 -> V_304 = V_43 -> V_296 +
V_43 -> V_298 +
V_43 -> V_300 ;
V_10 -> V_305 = V_43 -> V_268 +
V_43 -> V_270 +
V_43 -> V_272 ;
V_10 -> V_306 = V_43 -> V_278 +
V_43 -> V_282 ;
V_10 -> V_302 = V_43 -> V_302 ;
for ( V_3 = 0 ; V_3 < V_87 -> V_86 ; V_3 ++ )
F_141 ( V_2 , V_3 ) ;
for ( V_3 = 0 ; V_3 < V_87 -> V_116 ; V_3 ++ )
F_142 ( V_2 , V_3 ) ;
}
static struct V_307 * F_143 ( struct V_80 * V_33 ,
struct V_307 * V_43 )
{
struct V_1 * V_2 = F_46 ( V_33 ) ;
struct V_263 * V_264 = & V_2 -> V_264 ;
struct V_265 * V_10 = & V_2 -> V_10 ;
F_138 ( V_2 ) ;
V_43 -> V_266 = V_264 -> V_266 ;
V_43 -> V_308 = V_10 -> V_305 ;
V_43 -> V_309 = V_10 -> V_306 ;
V_43 -> V_310 = V_264 -> V_272 ;
V_43 -> V_311 = V_264 -> V_294 ;
V_43 -> V_312 = V_10 -> V_304 ;
V_43 -> V_313 = V_10 -> V_302 ;
return V_43 ;
}
static void F_144 ( struct V_80 * V_200 )
{
struct V_1 * V_2 = F_46 ( V_200 ) ;
if ( F_75 ( V_2 ) )
F_76 ( V_200 , L_30 ,
V_200 -> V_69 ) ;
F_145 ( & V_2 -> V_314 ) ;
}
static void F_146 ( struct V_315 * V_316 )
{
struct V_1 * V_2 ;
V_2 = F_79 ( V_316 , struct V_1 , V_314 ) ;
if ( ! F_137 ( V_2 -> V_33 ) )
return;
F_117 ( V_2 -> V_33 ) ;
F_36 ( V_2 -> V_33 ) ;
V_2 -> V_33 -> V_317 = V_318 ;
}
static int F_147 ( struct V_1 * V_2 ,
T_8 V_143 )
{
union V_23 V_24 = {} ;
V_24 . V_319 . V_25 = V_320 ;
V_24 . V_319 . V_34 = V_2 -> V_34 ;
V_24 . V_319 . V_105 = ( V_143 & V_321 ) != 0 ;
return F_10 ( V_2 , & V_24 ) ;
}
static T_8 F_148 ( struct V_80 * V_33 ,
T_8 V_143 )
{
struct V_1 * V_2 = F_46 ( V_33 ) ;
if ( ( V_143 & V_321 ) &&
F_137 ( V_33 ) && ! V_2 -> V_56 )
V_143 &= ~ V_321 ;
return V_143 ;
}
static int F_149 ( struct V_80 * V_33 ,
T_8 V_143 )
{
struct V_1 * V_2 = F_46 ( V_33 ) ;
T_8 V_322 = V_143 ^ V_33 -> V_143 ;
if ( V_322 & V_323 )
F_150 ( V_2 , V_143 ) ;
if ( ( V_322 & V_321 ) && F_137 ( V_33 ) )
return F_147 ( V_2 , V_143 ) ;
return 0 ;
}
static int F_151 ( struct V_324 * V_224 , const struct V_325 * V_326 )
{
struct V_327 * V_200 = & V_224 -> V_200 ;
struct V_80 * V_33 ;
struct V_1 * V_2 ;
int V_119 , V_328 ;
V_119 = F_152 ( V_224 ) ;
if ( V_119 ) {
F_153 ( V_200 , L_31 ) ;
return V_119 ;
}
V_119 = F_154 ( V_224 , V_329 ) ;
if ( V_119 ) {
F_153 ( V_200 , L_32 , V_119 ) ;
goto V_330;
}
V_119 = F_155 ( V_224 , F_156 ( 48 ) ) ;
if ( V_119 ) {
F_153 ( V_200 , L_33 ) ;
goto V_331;
}
V_119 = F_157 ( V_224 , F_156 ( 48 ) ) ;
if ( V_119 ) {
F_153 ( V_200 , L_34 ) ;
goto V_331;
}
V_328 = V_6 ;
if ( V_224 -> V_332 ) {
V_328 = F_158 ( F_159 () , V_6 ) ;
V_328 = F_28 ( V_328 ,
( V_333 + 1 ) * V_6 ) ;
}
V_33 = F_160 ( sizeof( struct V_1 ) , V_328 , V_328 ) ;
if ( ! V_33 ) {
V_119 = - V_243 ;
goto V_331;
}
F_161 ( V_224 , V_33 ) ;
F_162 ( V_33 , & V_224 -> V_200 ) ;
V_2 = F_46 ( V_33 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_224 = V_224 ;
V_2 -> V_78 = V_2 ;
V_2 -> V_334 = V_328 ;
V_2 -> V_20 = F_163 ( V_224 , V_335 , 0 ) ;
if ( ! V_2 -> V_20 ) {
F_153 ( V_200 , L_35 ) ;
V_119 = - V_243 ;
goto V_336;
}
V_119 = F_164 ( V_2 ) ;
if ( V_119 )
goto V_336;
V_119 = F_109 ( V_2 ) ;
if ( V_119 )
goto V_336;
F_38 ( V_2 ) ;
if ( ! F_165 ( V_2 -> V_224 ) )
V_2 -> V_138 = true ;
if ( V_2 -> V_4 )
return 0 ;
V_119 = F_37 ( V_33 , V_2 -> V_113 , V_2 -> V_111 ) ;
if ( V_119 )
goto V_337;
V_33 -> V_160 = ( V_161 | V_338 | V_339 |
V_340 | V_171 |
V_323 ) ;
V_33 -> V_160 |= V_144 ;
V_33 -> V_143 |= V_33 -> V_160 ;
V_33 -> V_160 |= V_321 ;
V_33 -> V_341 = V_339 | V_338 | V_340 ;
V_33 -> V_342 = & V_343 ;
V_33 -> V_344 = V_345 ;
F_166 ( & V_2 -> V_314 , F_146 ) ;
V_119 = F_167 ( V_33 ) ;
if ( V_119 ) {
F_153 ( V_200 , L_36 ) ;
goto V_337;
}
V_2 -> V_346 = V_347 ;
F_168 ( V_33 ) ;
return 0 ;
V_337:
F_107 ( V_2 ) ;
V_336:
F_161 ( V_224 , NULL ) ;
F_169 ( V_33 ) ;
V_331:
F_170 ( V_224 ) ;
V_330:
F_171 ( V_224 ) ;
return V_119 ;
}
static void F_172 ( struct V_324 * V_224 )
{
struct V_80 * V_33 = F_173 ( V_224 ) ;
struct V_1 * V_2 ;
struct V_80 * V_348 ;
if ( ! V_33 )
return;
V_2 = F_46 ( V_33 ) ;
V_348 = V_2 -> V_78 -> V_33 ;
if ( V_348 && ( V_348 -> V_349 == V_350 ) )
F_174 ( V_348 ) ;
F_107 ( V_2 ) ;
F_161 ( V_224 , NULL ) ;
F_169 ( V_33 ) ;
F_170 ( V_224 ) ;
F_171 ( V_224 ) ;
}
static void F_175 ( struct V_324 * V_224 )
{
F_172 ( V_224 ) ;
}
static int T_9 F_176 ( void )
{
F_177 ( L_37 , V_329 , V_351 ) ;
return F_178 ( & V_352 ) ;
}
static void T_10 F_179 ( void )
{
F_180 ( & V_352 ) ;
}
