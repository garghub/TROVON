static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_5 <= 64 )
V_2 -> V_6 . V_7 ++ ;
else if ( V_4 -> V_5 <= 127 )
V_2 -> V_6 . V_8 ++ ;
else if ( V_4 -> V_5 <= 255 )
V_2 -> V_6 . V_9 ++ ;
else if ( V_4 -> V_5 <= 511 )
V_2 -> V_6 . V_10 ++ ;
else if ( V_4 -> V_5 <= 1023 )
V_2 -> V_6 . V_11 ++ ;
else if ( V_4 -> V_5 <= 1518 )
V_2 -> V_6 . V_12 ++ ;
else
V_2 -> V_6 . V_13 ++ ;
}
void F_2 ( struct V_1 * V_2 , T_1 V_14 , T_1 V_15 )
{
F_3 ( V_15 , V_2 -> V_16 + V_14 ) ;
}
T_1 F_4 ( struct V_1 * V_2 , T_1 V_14 )
{
return F_5 ( V_2 -> V_16 + V_14 ) ;
}
void F_6 ( struct V_1 * V_2 , T_1 V_14 ,
T_1 V_17 , T_1 V_15 )
{
void T_2 * V_18 = V_2 -> V_16 + V_14 ;
F_3 ( V_15 , V_18 + ( V_17 << V_19 ) ) ;
}
T_1 F_7 ( struct V_1 * V_2 , T_1 V_14 , T_1 V_17 )
{
void T_2 * V_18 = V_2 -> V_16 + V_14 ;
return F_5 ( V_18 + ( V_17 << V_19 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , union V_20 * V_21 )
{
T_1 * V_22 = ( T_1 * ) V_21 ;
F_2 ( V_2 , V_23 + 0 , V_22 [ 0 ] ) ;
F_2 ( V_2 , V_23 + 8 , V_22 [ 1 ] ) ;
}
int F_9 ( struct V_1 * V_2 , union V_20 * V_21 )
{
int V_24 = V_25 ;
int V_26 = 10 ;
V_2 -> V_27 = false ;
V_2 -> V_28 = false ;
F_8 ( V_2 , V_21 ) ;
while ( ! V_2 -> V_27 ) {
if ( V_2 -> V_28 )
return - V_29 ;
F_10 ( V_26 ) ;
if ( V_2 -> V_27 )
break;
V_24 -= V_26 ;
if ( ! V_24 ) {
F_11 ( V_2 -> V_30 ,
L_1 ,
( V_21 -> V_22 . V_22 & 0xFF ) , V_2 -> V_31 ) ;
return - V_32 ;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_24 = 5000 , V_26 = 20 ;
union V_20 V_21 = {} ;
V_21 . V_22 . V_22 = V_33 ;
V_2 -> V_34 = false ;
F_8 ( V_2 , & V_21 ) ;
while ( ! V_2 -> V_34 ) {
F_10 ( V_26 ) ;
if ( V_2 -> V_34 )
break;
V_24 -= V_26 ;
if ( ! V_24 ) {
F_11 ( V_2 -> V_30 ,
L_2 ) ;
return 0 ;
}
}
return 1 ;
}
static void F_13 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
if ( V_36 -> V_37 )
V_2 -> V_38 . V_39 [ V_36 -> V_40 ] = V_36 -> V_41 ;
else
V_2 -> V_38 . V_42 [ V_36 -> V_40 ] = V_36 -> V_41 ;
}
static void F_14 ( struct V_1 * V_2 )
{
union V_20 V_21 = {} ;
T_1 * V_43 ;
T_1 V_44 ;
int V_45 ;
V_44 = V_23 ;
V_43 = ( T_1 * ) & V_21 ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
* V_43 = F_4 ( V_2 , V_44 ) ;
V_43 ++ ;
V_44 += sizeof( T_1 ) ;
}
F_15 ( V_2 -> V_30 , L_3 , V_21 . V_22 . V_22 ) ;
switch ( V_21 . V_22 . V_22 ) {
case V_33 :
V_2 -> V_34 = true ;
V_2 -> V_31 = V_21 . V_47 . V_31 & 0x7F ;
V_2 -> V_48 = V_21 . V_47 . V_48 & 0x7F ;
V_2 -> V_49 = V_21 . V_47 . V_50 ;
if ( ! V_2 -> V_51 )
F_16 ( V_2 -> V_30 -> V_52 ,
V_21 . V_47 . V_53 ) ;
V_2 -> V_54 = false ;
V_2 -> V_55 = 0 ;
V_2 -> V_56 = 0 ;
break;
case V_57 :
V_2 -> V_27 = true ;
break;
case V_58 :
V_2 -> V_28 = true ;
break;
case V_59 :
V_2 -> V_60 . V_61 = V_21 . V_61 . V_62 ;
V_2 -> V_27 = true ;
break;
case V_63 :
F_13 ( V_2 , & V_21 . V_38 ) ;
V_2 -> V_27 = true ;
V_2 -> V_64 = true ;
break;
case V_65 :
V_2 -> V_27 = true ;
V_2 -> V_54 = V_21 . V_66 . V_54 ;
V_2 -> V_55 = V_21 . V_66 . V_55 ;
V_2 -> V_56 = V_21 . V_66 . V_56 ;
if ( V_2 -> V_54 ) {
F_17 ( V_2 -> V_30 , L_4 ,
V_2 -> V_30 -> V_67 , V_2 -> V_56 ,
V_2 -> V_55 == V_68 ?
L_5 : L_6 ) ;
F_18 ( V_2 -> V_30 ) ;
F_19 ( V_2 -> V_30 ) ;
} else {
F_17 ( V_2 -> V_30 , L_7 ,
V_2 -> V_30 -> V_67 ) ;
F_20 ( V_2 -> V_30 ) ;
F_21 ( V_2 -> V_30 ) ;
}
break;
default:
F_11 ( V_2 -> V_30 ,
L_8 , V_21 . V_22 . V_22 ) ;
break;
}
F_22 ( V_2 , V_69 , 0 ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_70 * V_30 )
{
union V_20 V_21 = {} ;
V_21 . V_71 . V_22 = V_72 ;
V_21 . V_71 . V_31 = V_2 -> V_31 ;
F_16 ( V_21 . V_71 . V_53 , V_30 -> V_52 ) ;
return F_9 ( V_2 , & V_21 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
union V_20 V_21 = {} ;
V_21 . V_73 . V_22 = V_74 ;
V_21 . V_73 . V_31 = V_2 -> V_31 ;
V_21 . V_73 . V_75 = V_2 -> V_75 ;
V_21 . V_73 . V_76 = V_2 -> V_77 -> V_76 ;
F_9 ( V_2 , & V_21 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
union V_20 V_21 = {} ;
V_21 . V_61 . V_22 = V_59 ;
V_21 . V_61 . V_31 = V_2 -> V_31 ;
F_9 ( V_2 , & V_21 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
union V_20 V_21 = {} ;
struct V_78 * V_79 = & V_2 -> V_60 ;
int V_80 = V_79 -> V_61 ;
int V_45 , V_81 = 0 ;
V_21 . V_82 . V_31 = V_2 -> V_31 ;
V_21 . V_82 . V_83 = V_79 -> V_83 ;
while ( V_80 ) {
V_21 . V_82 . V_84 = V_81 ;
V_21 . V_82 . V_85 = F_27 ( V_80 ,
V_86 ) ;
V_21 . V_82 . V_22 = V_21 . V_82 . V_84 ?
V_87 : V_88 ;
for ( V_45 = 0 ; V_45 < V_21 . V_82 . V_85 ; V_45 ++ )
V_21 . V_82 . V_89 [ V_45 ] = V_79 -> V_89 [ V_81 ++ ] ;
F_9 ( V_2 , & V_21 ) ;
V_80 -= V_21 . V_82 . V_85 ;
}
}
void F_28 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = & V_2 -> V_60 ;
T_1 V_90 = V_91 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_92 ; V_40 ++ ) {
F_2 ( V_2 , V_90 , V_79 -> V_93 [ V_40 ] ) ;
V_90 += sizeof( T_1 ) ;
}
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = & V_2 -> V_60 ;
int V_40 ;
F_25 ( V_2 ) ;
if ( ( V_2 -> V_77 -> V_76 <= 1 ) || ( V_75 != V_94 ) ) {
V_79 -> V_95 = false ;
V_79 -> V_83 = 0 ;
return 0 ;
}
V_79 -> V_95 = true ;
V_79 -> V_93 [ 0 ] = 0xFEED0BADFEED0BADULL ;
V_79 -> V_93 [ 1 ] = 0xFEED0BADFEED0BADULL ;
V_79 -> V_93 [ 2 ] = 0xFEED0BADFEED0BADULL ;
V_79 -> V_93 [ 3 ] = 0xFEED0BADFEED0BADULL ;
V_79 -> V_93 [ 4 ] = 0xFEED0BADFEED0BADULL ;
F_28 ( V_2 ) ;
V_79 -> V_96 = V_97 | V_98 | V_99 ;
F_2 ( V_2 , V_100 , V_79 -> V_96 ) ;
V_79 -> V_83 = F_30 ( F_31 ( V_79 -> V_61 ) ) ;
for ( V_40 = 0 ; V_40 < V_79 -> V_61 ; V_40 ++ )
V_79 -> V_89 [ V_40 ] = F_32 ( V_40 ,
V_2 -> V_77 -> V_76 ) ;
F_26 ( V_2 ) ;
return 1 ;
}
int F_33 ( struct V_70 * V_30 ,
int V_101 , int V_102 )
{
int V_103 = 0 ;
V_103 = F_34 ( V_30 , V_101 ) ;
if ( V_103 ) {
F_11 ( V_30 ,
L_9 , V_101 ) ;
return V_103 ;
}
V_103 = F_35 ( V_30 , V_102 ) ;
if ( V_103 )
F_11 ( V_30 ,
L_10 , V_102 ) ;
return V_103 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_103 ;
union V_20 V_21 = {} ;
V_21 . V_22 . V_22 = V_104 ;
F_37 ( V_2 , true ) ;
V_103 = F_38 ( V_2 , true ) ;
if ( V_103 ) {
F_11 ( V_2 -> V_30 ,
L_11 ) ;
return V_103 ;
}
F_8 ( V_2 , & V_21 ) ;
return 0 ;
}
static void F_39 ( struct V_70 * V_30 ,
struct V_105 * V_106 ,
struct V_107 * V_108 , int V_109 )
{
struct V_3 * V_4 = NULL ;
struct V_1 * V_2 = F_40 ( V_30 ) ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
V_111 = & V_2 -> V_77 -> V_111 [ V_108 -> V_114 ] ;
V_113 = (struct V_112 * ) F_41 ( V_111 , V_108 -> V_115 ) ;
if ( V_113 -> V_116 != V_117 )
return;
F_15 ( V_2 -> V_30 ,
L_12 ,
V_118 , V_108 -> V_119 , V_108 -> V_114 ,
V_108 -> V_115 , V_113 -> V_120 ) ;
F_42 ( V_111 , V_113 -> V_120 + 1 ) ;
F_43 ( V_2 , V_106 , V_108 ) ;
V_4 = (struct V_3 * ) V_111 -> V_121 [ V_108 -> V_115 ] ;
if ( V_4 ) {
F_44 ( V_4 ) ;
F_45 ( V_4 ) ;
V_111 -> V_121 [ V_108 -> V_115 ] = ( T_1 ) NULL ;
}
}
static void F_46 ( struct V_70 * V_30 ,
struct V_122 * V_123 ,
struct V_105 * V_106 ,
struct V_124 * V_125 , int V_109 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 = F_40 ( V_30 ) ;
int V_103 = 0 ;
V_103 = F_47 ( V_2 , V_106 , V_125 ) ;
if ( V_103 && ! V_125 -> V_126 )
return;
V_4 = F_48 ( V_2 , V_125 ) ;
if ( ! V_4 ) {
F_15 ( V_2 -> V_30 , L_13 ) ;
return;
}
if ( F_49 ( V_2 ) ) {
F_17 ( V_2 -> V_30 , L_14 , V_30 -> V_67 ,
V_4 , V_4 -> V_5 ) ;
F_50 ( V_127 , L_15 , V_128 , 16 , 1 ,
V_4 -> V_129 , V_4 -> V_5 , true ) ;
}
F_1 ( V_2 , V_4 ) ;
F_51 ( V_4 , V_125 -> V_130 ) ;
if ( V_30 -> V_131 & V_132 ) {
V_4 -> V_133 = V_134 ;
} else {
F_52 ( V_4 ) ;
}
V_4 -> V_135 = F_53 ( V_4 , V_30 ) ;
if ( V_123 && ( V_30 -> V_136 & V_137 ) )
F_54 ( V_123 , V_4 ) ;
else
F_55 ( V_4 ) ;
}
static int F_56 ( struct V_70 * V_30 , T_3 V_138 ,
struct V_122 * V_123 , int V_139 )
{
int V_140 , V_141 = 0 , V_142 = 0 ;
int V_143 , V_144 ;
struct V_1 * V_2 = F_40 ( V_30 ) ;
struct V_145 * V_77 = V_2 -> V_77 ;
struct V_105 * V_106 = & V_77 -> V_106 [ V_138 ] ;
struct V_124 * V_146 ;
struct V_147 * V_148 ;
F_57 ( & V_106 -> V_149 ) ;
V_150:
V_140 = 0 ;
V_143 = F_7 ( V_2 , V_151 , V_138 ) ;
V_143 &= V_152 ;
if ( ! V_143 )
goto V_153;
V_144 = F_7 ( V_2 , V_154 , V_138 ) >> 9 ;
V_144 &= 0xFFFF ;
F_15 ( V_2 -> V_30 , L_16 ,
V_118 , V_138 , V_143 , V_144 ) ;
while ( V_140 < V_143 ) {
V_146 = (struct V_124 * ) F_58 ( V_106 , V_144 ) ;
V_144 ++ ;
V_144 &= ( V_106 -> V_155 . V_156 - 1 ) ;
F_44 ( (struct V_124 * ) F_58 ( V_106 , V_144 ) ) ;
if ( ( V_141 >= V_139 ) && V_123 &&
( V_146 -> V_109 != V_157 ) ) {
break;
}
F_15 ( V_2 -> V_30 , L_17 ,
V_138 , V_146 -> V_109 ) ;
switch ( V_146 -> V_109 ) {
case V_158 :
F_46 ( V_30 , V_123 , V_106 ,
V_146 , V_158 ) ;
V_141 ++ ;
break;
case V_157 :
F_39 ( V_30 , V_106 ,
( void * ) V_146 , V_157 ) ;
V_142 ++ ;
break;
case V_159 :
case V_160 :
case V_161 :
case V_162 :
break;
}
V_140 ++ ;
}
F_15 ( V_2 -> V_30 ,
L_18 ,
V_118 , V_138 , V_140 , V_141 , V_139 ) ;
F_6 ( V_2 , V_163 ,
V_138 , V_140 ) ;
if ( ( V_141 < V_139 ) && V_123 )
goto V_150;
V_153:
if ( V_142 ) {
V_148 = F_59 ( V_30 , V_138 ) ;
if ( F_60 ( V_148 ) ) {
F_61 ( V_148 ) ;
V_2 -> V_6 . V_164 ++ ;
if ( F_62 ( V_2 ) )
F_63 ( V_30 ,
L_19 ,
V_30 -> V_67 , V_138 ) ;
}
}
F_64 ( & V_106 -> V_149 ) ;
return V_141 ;
}
static int F_65 ( struct V_122 * V_123 , int V_139 )
{
T_1 V_165 ;
int V_141 = 0 ;
struct V_70 * V_30 = V_123 -> V_166 ;
struct V_1 * V_2 = F_40 ( V_30 ) ;
struct V_167 * V_106 ;
V_106 = F_66 ( V_123 , struct V_167 , V_123 ) ;
V_141 = F_56 ( V_30 , V_106 -> V_138 , V_123 , V_139 ) ;
if ( V_141 < V_139 ) {
F_67 ( V_123 ) ;
V_165 = F_7 ( V_2 , V_154 ,
V_106 -> V_138 ) ;
F_22 ( V_2 , V_168 , V_106 -> V_138 ) ;
F_6 ( V_2 , V_154 ,
V_106 -> V_138 , V_165 ) ;
F_68 ( V_2 , V_168 , V_106 -> V_138 ) ;
}
return V_141 ;
}
static void F_69 ( unsigned long V_129 )
{
struct V_1 * V_2 = (struct V_1 * ) V_129 ;
struct V_145 * V_77 = V_2 -> V_77 ;
int V_17 ;
T_1 V_169 ;
F_70 ( V_2 -> V_30 ) ;
for ( V_17 = 0 ; V_17 < V_77 -> V_170 ; V_17 ++ ) {
V_169 = F_7 ( V_2 , V_151 ,
V_17 ) ;
if ( ! ( V_169 & V_171 ) )
continue;
F_71 ( V_2 , V_168 , V_17 ) ;
F_72 ( V_2 , V_17 ) ;
F_56 ( V_2 -> V_30 , V_17 , NULL , 0 ) ;
F_73 ( V_2 , V_77 , V_17 , true ) ;
F_74 ( V_2 -> V_30 , & V_77 -> V_111 [ V_17 ] , V_17 ) ;
F_75 ( V_2 , & V_77 -> V_111 [ V_17 ] , V_17 ) ;
F_68 ( V_2 , V_168 , V_17 ) ;
}
F_19 ( V_2 -> V_30 ) ;
F_68 ( V_2 , V_172 , 0 ) ;
}
static T_4 F_76 ( int V_173 , void * V_174 )
{
struct V_1 * V_2 = (struct V_1 * ) V_174 ;
T_1 V_175 ;
V_175 = F_4 ( V_2 , V_176 ) ;
if ( ! ( V_175 & V_177 ) )
return V_178 ;
F_14 ( V_2 ) ;
return V_178 ;
}
static T_4 F_77 ( int V_173 , void * V_174 )
{
T_1 V_17 , V_175 , V_179 = 0 ;
T_1 V_180 , V_181 , V_182 ;
struct V_1 * V_2 = (struct V_1 * ) V_174 ;
struct V_145 * V_77 = V_2 -> V_77 ;
struct V_167 * V_183 = NULL ;
V_175 = F_4 ( V_2 , V_176 ) ;
if ( F_78 ( V_2 ) )
F_17 ( V_2 -> V_30 , L_20 ,
V_2 -> V_30 -> V_67 , V_175 ) ;
V_182 = V_175 & V_184 ;
if ( V_182 ) {
F_71 ( V_2 , V_172 , 0 ) ;
F_79 ( & V_2 -> V_185 ) ;
V_179 |= V_182 ;
}
V_180 = ( V_175 & V_186 ) >> V_187 ;
for ( V_17 = 0 ; V_17 < V_77 -> V_170 ; V_17 ++ ) {
if ( ! ( V_180 & ( 1 << V_17 ) ) )
continue;
if ( ! F_80 ( V_2 , V_168 , V_17 ) )
continue;
F_71 ( V_2 , V_168 , V_17 ) ;
V_179 |= ( ( 1 << V_17 ) << V_187 ) ;
V_183 = V_2 -> V_123 [ V_17 ] ;
if ( V_183 )
F_81 ( & V_183 -> V_123 ) ;
}
V_181 = ( V_175 & V_188 ) >> V_189 ;
if ( V_181 ) {
for ( V_17 = 0 ; V_17 < V_77 -> V_190 ; V_17 ++ ) {
if ( ! F_80 ( V_2 , V_191 , V_17 ) )
continue;
F_71 ( V_2 , V_191 , V_17 ) ;
F_79 ( & V_2 -> V_192 ) ;
V_179 |= ( ( 1 << V_17 ) << V_189 ) ;
}
}
F_2 ( V_2 , V_176 , V_179 ) ;
return V_178 ;
}
static int F_82 ( struct V_1 * V_2 )
{
int V_193 , V_194 ;
V_2 -> V_195 = V_196 ;
for ( V_194 = 0 ; V_194 < V_2 -> V_195 ; V_194 ++ )
V_2 -> V_197 [ V_194 ] . V_198 = V_194 ;
V_193 = F_83 ( V_2 -> V_199 , V_2 -> V_197 , V_2 -> V_195 ) ;
if ( V_193 ) {
F_11 ( V_2 -> V_30 ,
L_21 , V_2 -> V_195 ) ;
return 0 ;
}
V_2 -> V_200 = 1 ;
return 1 ;
}
static void F_84 ( struct V_1 * V_2 )
{
if ( V_2 -> V_200 ) {
F_85 ( V_2 -> V_199 ) ;
V_2 -> V_200 = 0 ;
V_2 -> V_195 = 0 ;
}
}
static int F_86 ( struct V_1 * V_2 )
{
int V_173 , free , V_193 = 0 ;
int V_201 ;
F_87 (irq)
sprintf ( V_2 -> V_202 [ V_173 ] , L_22 ,
V_2 -> V_31 , V_173 ) ;
F_88 (irq)
sprintf ( V_2 -> V_202 [ V_173 ] , L_23 ,
V_2 -> V_31 , V_173 - V_203 ) ;
F_89 (irq)
sprintf ( V_2 -> V_202 [ V_173 ] , L_24 ,
V_2 -> V_31 , V_173 - V_204 ) ;
for ( V_173 = 0 ; V_173 < V_203 ; V_173 ++ ) {
V_201 = V_2 -> V_197 [ V_173 ] . V_201 ;
V_193 = F_90 ( V_201 , F_77 ,
0 , V_2 -> V_202 [ V_173 ] , V_2 ) ;
if ( V_193 )
break;
V_2 -> V_205 [ V_173 ] = true ;
}
for ( V_173 = V_203 ; V_173 < V_206 ; V_173 ++ ) {
V_201 = V_2 -> V_197 [ V_173 ] . V_201 ;
V_193 = F_90 ( V_201 , F_77 ,
0 , V_2 -> V_202 [ V_173 ] , V_2 ) ;
if ( V_193 )
break;
V_2 -> V_205 [ V_173 ] = true ;
}
sprintf ( V_2 -> V_202 [ V_207 ] ,
L_25 , V_2 -> V_31 ) ;
if ( ! V_193 ) {
V_201 = V_2 -> V_197 [ V_207 ] . V_201 ;
V_173 = V_207 ;
V_193 = F_90 ( V_201 , F_77 ,
0 , V_2 -> V_202 [ V_173 ] , V_2 ) ;
if ( ! V_193 )
V_2 -> V_205 [ V_173 ] = true ;
}
if ( V_193 ) {
F_11 ( V_2 -> V_30 , L_26 ) ;
for ( free = 0 ; free < V_173 ; free ++ )
F_91 ( V_2 -> V_197 [ free ] . V_201 , V_2 ) ;
return V_193 ;
}
return 0 ;
}
static void F_92 ( struct V_1 * V_2 )
{
int V_173 ;
for ( V_173 = 0 ; V_173 < V_2 -> V_195 ; V_173 ++ ) {
if ( V_2 -> V_205 [ V_173 ] )
F_91 ( V_2 -> V_197 [ V_173 ] . V_201 , V_2 ) ;
V_2 -> V_205 [ V_173 ] = false ;
}
F_84 ( V_2 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
int V_193 = 0 ;
int V_173 = V_206 ;
if ( V_2 -> V_200 )
return 0 ;
if ( ! F_82 ( V_2 ) )
return 1 ;
sprintf ( V_2 -> V_202 [ V_173 ] , L_27 , L_28 ) ;
V_193 = F_90 ( V_2 -> V_197 [ V_173 ] . V_201 ,
F_76 , 0 , V_2 -> V_202 [ V_173 ] , V_2 ) ;
if ( V_193 )
return V_193 ;
V_2 -> V_205 [ V_173 ] = true ;
F_68 ( V_2 , V_69 , 0 ) ;
if ( ! F_12 ( V_2 ) ) {
F_71 ( V_2 , V_69 , 0 ) ;
F_92 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static T_5 F_94 ( struct V_3 * V_4 , struct V_70 * V_30 )
{
struct V_1 * V_2 = F_40 ( V_30 ) ;
int V_208 = F_95 ( V_4 ) ;
struct V_147 * V_148 = F_59 ( V_30 , V_208 ) ;
if ( V_4 -> V_5 <= V_209 ) {
F_96 ( V_4 ) ;
return V_210 ;
}
if ( ! F_60 ( V_148 ) && ! F_97 ( V_2 , V_4 ) ) {
F_98 ( V_148 ) ;
V_2 -> V_6 . V_211 ++ ;
if ( F_62 ( V_2 ) )
F_63 ( V_30 ,
L_29 ,
V_30 -> V_67 , V_208 ) ;
return V_212 ;
}
return V_210 ;
}
int F_99 ( struct V_70 * V_30 )
{
int V_173 , V_17 ;
struct V_1 * V_2 = F_40 ( V_30 ) ;
struct V_145 * V_77 = V_2 -> V_77 ;
struct V_167 * V_183 = NULL ;
union V_20 V_21 = {} ;
V_21 . V_22 . V_22 = V_213 ;
F_9 ( V_2 , & V_21 ) ;
F_20 ( V_30 ) ;
for ( V_17 = 0 ; V_17 < V_77 -> V_190 ; V_17 ++ ) {
F_71 ( V_2 , V_191 , V_17 ) ;
F_22 ( V_2 , V_191 , V_17 ) ;
}
F_71 ( V_2 , V_172 , 0 ) ;
F_22 ( V_2 , V_172 , 0 ) ;
for ( V_173 = 0 ; V_173 < V_2 -> V_195 ; V_173 ++ )
F_100 ( V_2 -> V_197 [ V_173 ] . V_201 ) ;
F_101 ( & V_2 -> V_192 ) ;
F_101 ( & V_2 -> V_185 ) ;
if ( V_2 -> V_214 )
F_102 ( & V_2 -> V_215 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_77 -> V_170 ; V_17 ++ ) {
V_183 = V_2 -> V_123 [ V_17 ] ;
if ( ! V_183 )
continue;
V_2 -> V_123 [ V_17 ] = NULL ;
F_103 ( & V_183 -> V_123 ) ;
F_71 ( V_2 , V_168 , V_17 ) ;
F_22 ( V_2 , V_168 , V_17 ) ;
F_104 ( & V_183 -> V_123 ) ;
F_105 ( & V_183 -> V_123 ) ;
F_106 ( V_183 ) ;
}
F_70 ( V_30 ) ;
F_38 ( V_2 , false ) ;
F_37 ( V_2 , false ) ;
F_71 ( V_2 , V_69 , 0 ) ;
F_92 ( V_2 ) ;
return 0 ;
}
int F_107 ( struct V_70 * V_30 )
{
int V_103 , V_17 ;
struct V_1 * V_2 = F_40 ( V_30 ) ;
struct V_145 * V_77 = V_2 -> V_77 ;
struct V_167 * V_183 = NULL ;
V_2 -> V_216 = V_30 -> V_216 ;
F_20 ( V_30 ) ;
V_103 = F_93 ( V_2 ) ;
if ( V_103 )
return V_103 ;
for ( V_17 = 0 ; V_17 < V_77 -> V_170 ; V_17 ++ ) {
V_183 = F_108 ( sizeof( * V_183 ) , V_217 ) ;
if ( ! V_183 ) {
V_103 = - V_218 ;
goto V_219;
}
V_183 -> V_138 = V_17 ;
F_109 ( V_30 , & V_183 -> V_123 , F_65 ,
V_220 ) ;
F_110 ( & V_183 -> V_123 ) ;
V_2 -> V_123 [ V_17 ] = V_183 ;
}
if ( F_111 ( V_30 -> V_52 ) ) {
F_112 ( V_30 ) ;
F_23 ( V_2 , V_30 ) ;
}
if ( V_2 -> V_51 ) {
V_2 -> V_51 = false ;
F_23 ( V_2 , V_30 ) ;
}
F_113 ( & V_2 -> V_185 , F_69 ,
( unsigned long ) V_2 ) ;
F_113 ( & V_2 -> V_192 , V_221 ,
( unsigned long ) V_2 ) ;
F_114 ( & V_2 -> V_215 , V_222 ) ;
V_2 -> V_75 = V_75 ;
F_24 ( V_2 ) ;
F_29 ( V_2 ) ;
V_103 = F_86 ( V_2 ) ;
if ( V_103 )
goto V_223;
V_103 = F_36 ( V_2 ) ;
if ( V_103 )
goto V_223;
F_115 () ;
F_2 ( V_2 , V_176 , - 1 ) ;
F_68 ( V_2 , V_172 , 0 ) ;
for ( V_17 = 0 ; V_17 < V_77 -> V_170 ; V_17 ++ )
F_68 ( V_2 , V_168 , V_17 ) ;
for ( V_17 = 0 ; V_17 < V_77 -> V_190 ; V_17 ++ )
F_68 ( V_2 , V_191 , V_17 ) ;
V_2 -> V_6 . V_211 = 0 ;
V_2 -> V_6 . V_164 = 0 ;
F_18 ( V_30 ) ;
F_19 ( V_30 ) ;
return 0 ;
V_223:
F_71 ( V_2 , V_69 , 0 ) ;
F_92 ( V_2 ) ;
V_219:
for ( V_17 = 0 ; V_17 < V_77 -> V_170 ; V_17 ++ ) {
V_183 = V_2 -> V_123 [ V_17 ] ;
if ( ! V_183 )
continue;
F_104 ( & V_183 -> V_123 ) ;
F_105 ( & V_183 -> V_123 ) ;
F_106 ( V_183 ) ;
V_2 -> V_123 [ V_17 ] = NULL ;
}
return V_103 ;
}
static int F_116 ( struct V_1 * V_2 , int V_216 )
{
union V_20 V_21 = {} ;
V_21 . V_224 . V_22 = V_225 ;
V_21 . V_224 . V_226 = V_216 ;
V_21 . V_224 . V_31 = V_2 -> V_31 ;
return F_9 ( V_2 , & V_21 ) ;
}
static int F_117 ( struct V_70 * V_30 , int V_227 )
{
struct V_1 * V_2 = F_40 ( V_30 ) ;
if ( V_227 > V_228 )
return - V_29 ;
if ( V_227 < V_229 )
return - V_29 ;
if ( F_116 ( V_2 , V_227 ) )
return - V_29 ;
V_30 -> V_216 = V_227 ;
V_2 -> V_216 = V_227 ;
return 0 ;
}
static int F_118 ( struct V_70 * V_30 , void * V_230 )
{
struct V_231 * V_18 = V_230 ;
struct V_1 * V_2 = F_40 ( V_30 ) ;
if ( ! F_119 ( V_18 -> V_232 ) )
return - V_233 ;
memcpy ( V_30 -> V_52 , V_18 -> V_232 , V_30 -> V_234 ) ;
if ( V_2 -> V_200 ) {
if ( F_23 ( V_2 , V_30 ) )
return - V_32 ;
} else {
V_2 -> V_51 = true ;
}
return 0 ;
}
void F_120 ( struct V_1 * V_2 )
{
int V_235 = 0 ;
union V_20 V_21 = {} ;
int V_24 ;
if ( ! F_121 ( V_2 -> V_30 ) )
return;
V_21 . V_38 . V_22 = V_63 ;
V_21 . V_38 . V_31 = V_2 -> V_31 ;
V_21 . V_38 . V_37 = 1 ;
while ( V_235 < V_236 ) {
V_2 -> V_64 = 0 ;
V_21 . V_38 . V_40 = V_235 ;
F_9 ( V_2 , & V_21 ) ;
V_24 = 0 ;
while ( ( ! V_2 -> V_64 ) && ( V_24 < 10 ) ) {
F_10 ( 2 ) ;
V_24 ++ ;
}
V_235 ++ ;
}
V_235 = 0 ;
V_21 . V_38 . V_37 = 0 ;
while ( V_235 < V_237 ) {
V_2 -> V_64 = 0 ;
V_21 . V_38 . V_40 = V_235 ;
F_9 ( V_2 , & V_21 ) ;
V_24 = 0 ;
while ( ( ! V_2 -> V_64 ) && ( V_24 < 10 ) ) {
F_10 ( 2 ) ;
V_24 ++ ;
}
V_235 ++ ;
}
}
void F_122 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_238 * V_41 = & V_2 -> V_41 ;
struct V_239 * V_6 = & V_2 -> V_6 ;
struct V_145 * V_77 = V_2 -> V_77 ;
#define F_123 ( T_6 ) \
nicvf_reg_read(nic, NIC_VNIC_RX_STAT_0_13 | (reg << 3))
#define F_124 ( T_6 ) \
nicvf_reg_read(nic, NIC_VNIC_TX_STAT_0_4 | (reg << 3))
V_41 -> V_240 = F_123 ( V_241 ) ;
V_41 -> V_242 = F_123 ( V_243 ) ;
V_41 -> V_244 = F_123 ( V_245 ) ;
V_41 -> V_246 = F_123 ( V_247 ) ;
V_41 -> V_248 = F_123 ( V_249 ) ;
V_41 -> V_250 = F_123 ( V_251 ) ;
V_41 -> V_252 = F_123 ( V_253 ) ;
V_41 -> V_254 = F_123 ( V_255 ) ;
V_41 -> V_256 = F_123 ( V_257 ) ;
V_41 -> V_258 = F_123 ( V_259 ) ;
V_41 -> V_260 = F_123 ( V_261 ) ;
V_41 -> V_262 = F_123 ( V_263 ) ;
V_41 -> V_264 = F_124 ( V_265 ) ;
V_41 -> V_266 = F_124 ( V_267 ) ;
V_41 -> V_268 = F_124 ( V_269 ) ;
V_41 -> V_270 = F_124 ( V_271 ) ;
V_41 -> V_272 = F_124 ( V_273 ) ;
V_6 -> V_274 = V_41 -> V_242 +
V_41 -> V_244 +
V_41 -> V_246 ;
V_6 -> V_275 = V_41 -> V_266 +
V_41 -> V_268 +
V_41 -> V_270 ;
V_6 -> V_276 = V_41 -> V_252 +
V_41 -> V_254 ;
V_6 -> V_272 = V_41 -> V_272 ;
for ( V_17 = 0 ; V_17 < V_77 -> V_76 ; V_17 ++ )
F_125 ( V_2 , V_17 ) ;
for ( V_17 = 0 ; V_17 < V_77 -> V_277 ; V_17 ++ )
F_126 ( V_2 , V_17 ) ;
}
static struct V_278 * F_127 ( struct V_70 * V_30 ,
struct V_278 * V_41 )
{
struct V_1 * V_2 = F_40 ( V_30 ) ;
struct V_238 * V_279 = & V_2 -> V_41 ;
struct V_239 * V_6 = & V_2 -> V_6 ;
F_122 ( V_2 ) ;
V_41 -> V_280 = V_279 -> V_240 ;
V_41 -> V_281 = V_6 -> V_274 ;
V_41 -> V_282 = V_6 -> V_276 ;
V_41 -> V_283 = V_279 -> V_264 ;
V_41 -> V_284 = V_6 -> V_275 ;
V_41 -> V_285 = V_6 -> V_272 ;
return V_41 ;
}
static void F_128 ( struct V_70 * V_166 )
{
struct V_1 * V_2 = F_40 ( V_166 ) ;
if ( F_62 ( V_2 ) )
F_63 ( V_166 , L_30 ,
V_166 -> V_67 ) ;
F_129 ( & V_2 -> V_286 ) ;
}
static void F_130 ( struct V_287 * V_288 )
{
struct V_1 * V_2 ;
V_2 = F_66 ( V_288 , struct V_1 , V_286 ) ;
if ( ! F_121 ( V_2 -> V_30 ) )
return;
F_99 ( V_2 -> V_30 ) ;
F_107 ( V_2 -> V_30 ) ;
V_2 -> V_30 -> V_289 = V_290 ;
}
static int F_131 ( struct V_291 * V_199 , const struct V_292 * V_293 )
{
struct V_294 * V_166 = & V_199 -> V_166 ;
struct V_70 * V_30 ;
struct V_1 * V_2 ;
struct V_145 * V_77 ;
int V_103 ;
V_103 = F_132 ( V_199 ) ;
if ( V_103 ) {
F_133 ( V_166 , L_31 ) ;
return V_103 ;
}
V_103 = F_134 ( V_199 , V_295 ) ;
if ( V_103 ) {
F_133 ( V_166 , L_32 , V_103 ) ;
goto V_296;
}
V_103 = F_135 ( V_199 , F_136 ( 48 ) ) ;
if ( V_103 ) {
F_133 ( V_166 , L_33 ) ;
goto V_297;
}
V_103 = F_137 ( V_199 , F_136 ( 48 ) ) ;
if ( V_103 ) {
F_133 ( V_166 , L_34 ) ;
goto V_297;
}
V_30 = F_138 ( sizeof( struct V_1 ) ,
V_298 ,
V_299 ) ;
if ( ! V_30 ) {
V_103 = - V_218 ;
goto V_297;
}
F_139 ( V_199 , V_30 ) ;
F_140 ( V_30 , & V_199 -> V_166 ) ;
V_2 = F_40 ( V_30 ) ;
V_2 -> V_30 = V_30 ;
V_2 -> V_199 = V_199 ;
V_2 -> V_16 = F_141 ( V_199 , V_300 , 0 ) ;
if ( ! V_2 -> V_16 ) {
F_133 ( V_166 , L_35 ) ;
V_103 = - V_218 ;
goto V_301;
}
V_103 = F_142 ( V_2 ) ;
if ( V_103 )
goto V_301;
V_77 = V_2 -> V_77 ;
V_103 = F_33 ( V_30 , V_77 -> V_277 , V_77 -> V_76 ) ;
if ( V_103 )
goto V_301;
V_103 = F_93 ( V_2 ) ;
if ( V_103 )
goto V_301;
V_30 -> V_136 |= ( V_132 | V_302 | V_303 |
V_304 | V_137 ) ;
V_30 -> V_131 = V_30 -> V_136 ;
V_30 -> V_305 = & V_306 ;
V_30 -> V_307 = V_308 ;
F_143 ( & V_2 -> V_286 , F_130 ) ;
V_103 = F_144 ( V_30 ) ;
if ( V_103 ) {
F_133 ( V_166 , L_36 ) ;
goto V_309;
}
V_2 -> V_310 = V_311 ;
F_145 ( V_30 ) ;
return 0 ;
V_309:
F_92 ( V_2 ) ;
V_301:
F_139 ( V_199 , NULL ) ;
F_146 ( V_30 ) ;
V_297:
F_147 ( V_199 ) ;
V_296:
F_148 ( V_199 ) ;
return V_103 ;
}
static void F_149 ( struct V_291 * V_199 )
{
struct V_70 * V_30 = F_150 ( V_199 ) ;
struct V_1 * V_2 = F_40 ( V_30 ) ;
F_151 ( V_30 ) ;
F_92 ( V_2 ) ;
F_139 ( V_199 , NULL ) ;
F_146 ( V_30 ) ;
F_147 ( V_199 ) ;
F_148 ( V_199 ) ;
}
static void F_152 ( struct V_291 * V_199 )
{
F_149 ( V_199 ) ;
}
static int T_7 F_153 ( void )
{
F_154 ( L_37 , V_295 , V_312 ) ;
return F_155 ( & V_313 ) ;
}
static void T_8 F_156 ( void )
{
F_157 ( & V_313 ) ;
}
