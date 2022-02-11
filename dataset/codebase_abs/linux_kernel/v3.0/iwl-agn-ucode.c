static int F_1 ( struct V_1 * V_2 , const char * V_3 ,
struct V_4 * V_5 , T_1 V_6 )
{
T_2 V_7 = V_5 -> V_8 ;
T_1 V_9 = V_5 -> V_10 ;
int V_11 ;
V_2 -> V_12 = 0 ;
F_2 ( V_2 ,
F_3 ( V_13 ) ,
V_14 ) ;
F_2 ( V_2 ,
F_4 ( V_13 ) , V_6 ) ;
F_2 ( V_2 ,
F_5 ( V_13 ) ,
V_7 & V_15 ) ;
F_2 ( V_2 ,
F_6 ( V_13 ) ,
( F_7 ( V_7 )
<< V_16 ) | V_9 ) ;
F_2 ( V_2 ,
F_8 ( V_13 ) ,
1 << V_17 |
1 << V_18 |
V_19 ) ;
F_2 ( V_2 ,
F_3 ( V_13 ) ,
V_20 |
V_21 |
V_22 ) ;
F_9 ( V_2 , L_1 , V_3 ) ;
V_11 = F_10 ( V_2 -> V_23 ,
V_2 -> V_12 , 5 * V_24 ) ;
if ( V_11 == - V_25 ) {
F_11 ( V_2 , L_2
L_3 , V_3 ) ;
return V_11 ;
}
if ( ! V_11 ) {
F_11 ( V_2 , L_4 ,
V_3 ) ;
return - V_26 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_27 * V_5 )
{
int V_11 = 0 ;
V_11 = F_1 ( V_2 , L_5 , & V_5 -> V_28 ,
V_29 ) ;
if ( V_11 )
return V_11 ;
return F_1 ( V_2 , L_6 , & V_5 -> V_30 ,
V_31 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_32 V_33 ;
T_3 * V_34 =
( T_3 * ) F_14 ( V_2 , V_35 ) ;
V_33 . V_36 . V_37 = V_38 ;
V_33 . V_36 . V_39 = 0 ;
V_33 . V_36 . V_40 = 1 ;
V_33 . V_36 . V_41 = 1 ;
V_33 . V_42 = F_15 ( V_34 [ 0 ] ) ;
V_33 . V_43 = F_15 ( V_34 [ 1 ] ) ;
return F_16 ( & V_2 -> V_44 [ V_45 ] ,
( V_46 * ) & V_33 , sizeof( V_33 ) ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_47 V_33 ;
T_3 * V_48 =
( T_3 * ) F_14 ( V_2 , V_49 ) ;
V_33 . V_36 . V_37 = V_50 ;
V_33 . V_36 . V_39 = 0 ;
V_33 . V_36 . V_40 = 1 ;
V_33 . V_36 . V_41 = 1 ;
V_33 . V_51 = F_15 ( V_48 [ 1 ] ) ;
if ( ! ( V_33 . V_51 ) )
V_33 . V_51 = V_52 ;
V_33 . V_53 = 0 ;
F_18 ( V_2 , L_7 ,
V_33 . V_51 ) ;
return F_16 ( & V_2 -> V_44 [ V_54 ] ,
( V_46 * ) & V_33 , sizeof( V_33 ) ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_55 V_56 ;
struct V_57 V_33 = {
. V_58 = V_59 ,
. V_10 = { sizeof( struct V_55 ) , } ,
. V_30 = { & V_56 , } ,
} ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_60 . V_61 . V_62 = V_63 ;
V_56 . V_60 . V_61 . V_64 = V_63 ;
V_56 . V_60 . V_61 . V_65 = V_63 ;
V_56 . V_60 . V_66 = V_63 ;
return F_20 ( V_2 , & V_33 ) ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
struct V_69 * V_70 = F_22 ( V_68 ) ;
struct V_71 * V_36 = (struct V_71 * ) V_70 -> V_72 . V_73 ;
int V_10 = F_23 ( V_70 -> V_74 ) & V_75 ;
int V_76 ;
V_10 -= 4 ;
switch ( V_36 -> V_37 ) {
case V_77 :
V_76 = V_78 ;
break;
case V_79 :
V_76 = V_80 ;
break;
case V_81 :
V_76 = V_82 ;
break;
case V_83 :
V_76 = V_84 ;
break;
case V_85 :
V_76 = V_86 ;
break;
default:
F_11 ( V_2 , L_8 ,
V_36 -> V_37 ) ;
return;
}
F_16 ( & V_2 -> V_44 [ V_76 ] , V_70 -> V_72 . V_73 , V_10 ) ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_11 ;
if ( V_2 -> V_87 -> V_88 &&
V_2 -> V_87 -> V_88 -> V_89 ) {
V_11 = F_25 ( V_2 , V_90 ,
V_91 ) ;
if ( V_11 )
return V_11 ;
}
V_11 = F_19 ( V_2 ) ;
if ( V_11 )
return V_11 ;
if ( V_2 -> V_87 -> V_92 )
return F_17 ( V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_93 V_94 ;
if ( V_2 -> V_87 -> V_95 -> V_96 ) {
V_94 . V_66 = V_97 ;
V_94 . V_66 |= V_98 ;
memcpy ( V_94 . V_99 , V_100 ,
sizeof( struct V_101 ) *
V_102 ) ;
V_94 . V_66 |= V_103 ;
V_94 . V_66 |= V_104 ;
} else {
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
}
return F_27 ( V_2 , V_105 ,
sizeof( V_94 ) , & V_94 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_106 V_107 ;
memcpy ( V_107 . V_108 , V_109 ,
sizeof( V_109 ) ) ;
if ( F_27 ( V_2 , V_110 ,
sizeof( V_107 ) , & V_107 ) )
F_11 ( V_2 , L_9 ) ;
}
int F_25 ( struct V_1 * V_2 , V_46 V_111 , V_46 type )
{
struct V_112 V_113 ;
int V_11 ;
V_113 . V_111 = V_111 ;
V_113 . type = type ;
V_11 = F_27 ( V_2 , V_114 ,
sizeof( V_113 ) , & V_113 ) ;
if ( V_11 )
F_11 ( V_2 , L_10 ) ;
return V_11 ;
}
static int F_29 ( struct V_1 * V_2 )
{
const struct V_115 * V_116 ;
struct V_117 * V_118 ;
T_1 V_119 ;
unsigned long V_66 ;
int V_120 , V_121 ;
T_1 V_122 ;
int V_11 ;
F_30 ( & V_2 -> V_123 , V_66 ) ;
V_2 -> V_124 = F_31 ( V_2 , V_125 ) ;
V_119 = V_2 -> V_124 + V_126 ;
for (; V_119 < V_2 -> V_124 + V_127 ;
V_119 += 4 )
F_32 ( V_2 , V_119 , 0 ) ;
for (; V_119 < V_2 -> V_124 + V_128 ;
V_119 += 4 )
F_32 ( V_2 , V_119 , 0 ) ;
for (; V_119 < V_2 -> V_124 +
F_33 ( V_2 -> V_129 . V_130 ) ; V_119 += 4 )
F_32 ( V_2 , V_119 , 0 ) ;
F_34 ( V_2 , V_131 ,
V_2 -> V_132 . V_133 >> 10 ) ;
for ( V_121 = 0 ; V_121 < V_134 ; V_121 ++ )
F_2 ( V_2 , F_3 ( V_121 ) ,
V_20 |
V_135 ) ;
V_122 = F_35 ( V_2 , V_136 ) ;
F_2 ( V_2 , V_136 ,
V_122 | V_137 ) ;
F_34 ( V_2 , V_138 ,
F_36 ( V_2 ) ) ;
F_34 ( V_2 , V_139 , 0 ) ;
for ( V_120 = 0 ; V_120 < V_2 -> V_129 . V_130 ; V_120 ++ ) {
F_34 ( V_2 , F_37 ( V_120 ) , 0 ) ;
F_2 ( V_2 , V_140 , 0 | ( V_120 << 8 ) ) ;
F_32 ( V_2 , V_2 -> V_124 +
F_38 ( V_120 ) , 0 ) ;
F_32 ( V_2 , V_2 -> V_124 +
F_38 ( V_120 ) +
sizeof( T_1 ) ,
( ( V_141 <<
V_142 ) &
V_143 ) |
( ( V_144 <<
V_145 ) &
V_146 ) ) ;
}
F_34 ( V_2 , V_147 ,
F_39 ( 0 , V_2 -> V_129 . V_130 ) ) ;
F_40 ( V_2 , F_39 ( 0 , 7 ) ) ;
if ( V_2 -> V_148 != F_41 ( V_149 ) )
V_116 = V_150 ;
else
V_116 = V_151 ;
F_42 ( V_2 , V_2 -> V_152 , 0 ) ;
memset ( & V_2 -> V_153 [ 0 ] , 0 , sizeof( V_2 -> V_153 ) ) ;
for ( V_120 = 0 ; V_120 < 4 ; V_120 ++ )
F_43 ( & V_2 -> V_154 [ V_120 ] , 0 ) ;
F_44 (priv, ctx)
V_118 -> V_155 = false ;
V_2 -> V_156 = 0 ;
F_45 ( F_46 ( V_151 ) != 10 ) ;
F_45 ( F_46 ( V_150 ) != 10 ) ;
for ( V_120 = 0 ; V_120 < 10 ; V_120 ++ ) {
int V_157 = V_116 [ V_120 ] . V_157 ;
int V_158 = V_116 [ V_120 ] . V_158 ;
F_47 ( V_2 , V_120 ) ;
if ( V_157 == V_159 )
continue;
if ( V_158 != V_160 )
F_48 ( & V_2 -> V_161 [ V_120 ] , V_158 , V_120 ) ;
F_49 ( V_2 , & V_2 -> V_161 [ V_120 ] , V_157 , 0 ) ;
}
F_50 ( & V_2 -> V_123 , V_66 ) ;
F_51 ( V_2 , V_162 ,
V_163 ) ;
V_11 = F_26 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_13 ( V_2 ) ;
if ( V_11 )
return V_11 ;
return F_52 ( V_2 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_4 * V_4 )
{
T_4 * V_5 = ( T_4 * ) V_4 -> V_164 ;
T_1 V_10 = V_4 -> V_10 ;
T_1 V_165 ;
T_1 V_120 ;
F_9 ( V_2 , L_11 , V_10 ) ;
for ( V_120 = 0 ; V_120 < V_10 ; V_120 += 100 , V_5 += 100 / sizeof( T_1 ) ) {
F_2 ( V_2 , V_166 ,
V_120 + V_29 ) ;
V_165 = F_54 ( V_2 , V_167 ) ;
if ( V_165 != F_23 ( * V_5 ) )
return - V_168 ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_4 * V_4 )
{
T_4 * V_5 = ( T_4 * ) V_4 -> V_164 ;
T_1 V_10 = V_4 -> V_10 ;
T_1 V_165 ;
T_1 V_169 ;
int V_170 = 0 ;
F_9 ( V_2 , L_11 , V_10 ) ;
F_2 ( V_2 , V_166 ,
V_29 ) ;
for ( V_169 = 0 ;
V_169 < V_10 && V_170 < 20 ;
V_169 += sizeof( T_1 ) , V_5 ++ ) {
V_165 = F_54 ( V_2 , V_167 ) ;
if ( V_165 != F_23 ( * V_5 ) ) {
F_11 ( V_2 , L_12
L_13 ,
V_169 , V_165 , F_23 ( * V_5 ) ) ;
V_170 ++ ;
}
}
}
static int F_56 ( struct V_1 * V_2 , struct V_27 * V_171 )
{
if ( ! F_53 ( V_2 , & V_171 -> V_28 ) ) {
F_9 ( V_2 , L_14 ) ;
return 0 ;
}
F_11 ( V_2 , L_15 ) ;
F_55 ( V_2 , & V_171 -> V_28 ) ;
return - V_168 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
void * V_30 )
{
struct V_172 * V_173 = V_30 ;
struct V_174 * V_175 ;
V_175 = & V_70 -> V_72 . V_176 ;
F_9 ( V_2 , L_16
L_17 ,
V_175 -> V_177 , V_175 -> V_178 ,
V_175 -> V_179 ) ;
V_2 -> V_180 . V_181 =
F_23 ( V_175 -> V_182 ) ;
V_2 -> V_180 . V_183 =
F_23 ( V_175 -> V_184 ) ;
V_173 -> V_185 = V_175 -> V_179 ;
V_173 -> V_186 = V_175 -> V_177 == V_187 ;
}
int F_58 ( struct V_1 * V_2 ,
struct V_27 * V_5 ,
int V_185 , int V_188 )
{
struct V_189 V_190 ;
struct V_172 V_173 ;
int V_11 ;
enum V_191 V_192 ;
V_11 = F_59 ( V_2 ) ;
if ( V_11 )
return V_11 ;
F_60 ( V_2 , & V_190 , V_193 ,
F_57 , & V_173 ) ;
V_192 = V_2 -> V_194 ;
V_2 -> V_194 = V_185 ;
V_11 = F_12 ( V_2 , V_5 ) ;
if ( V_11 ) {
V_2 -> V_194 = V_192 ;
F_61 ( V_2 , & V_190 ) ;
return V_11 ;
}
F_62 ( V_2 , V_195 , 0 ) ;
V_11 = F_63 ( V_2 , & V_190 , V_196 ) ;
if ( V_11 ) {
V_2 -> V_194 = V_192 ;
return V_11 ;
}
if ( ! V_173 . V_186 ) {
F_11 ( V_2 , L_18 ) ;
V_2 -> V_194 = V_192 ;
return - V_168 ;
}
if ( V_173 . V_185 != V_185 &&
V_173 . V_185 != V_188 ) {
F_11 ( V_2 ,
L_19 ,
V_173 . V_185 , V_185 ) ;
V_2 -> V_194 = V_192 ;
return - V_168 ;
}
V_11 = F_56 ( V_2 , V_5 ) ;
if ( V_11 ) {
V_2 -> V_194 = V_192 ;
return V_11 ;
}
F_64 ( 5 ) ;
V_11 = F_29 ( V_2 ) ;
if ( V_11 ) {
F_65 ( V_2 ,
L_20 , V_11 ) ;
V_2 -> V_194 = V_192 ;
return V_11 ;
}
return 0 ;
}
int F_66 ( struct V_1 * V_2 )
{
struct V_189 V_197 ;
int V_11 ;
F_67 ( & V_2 -> V_198 ) ;
if ( ! V_2 -> V_199 . V_28 . V_10 )
return 0 ;
if ( V_2 -> V_194 != V_200 )
return 0 ;
F_60 ( V_2 , & V_197 ,
V_201 ,
NULL , NULL ) ;
V_11 = F_58 ( V_2 , & V_2 -> V_199 ,
V_202 , - 1 ) ;
if ( V_11 )
goto error;
V_11 = F_24 ( V_2 ) ;
if ( V_11 )
goto error;
V_11 = F_63 ( V_2 , & V_197 , V_203 ) ;
goto V_204;
error:
F_61 ( V_2 , & V_197 ) ;
V_204:
F_68 ( V_2 ) ;
return V_11 ;
}
