static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_6 ;
T_1 V_8 ;
T_2 * V_9 ;
T_3 V_10 ;
V_8 = F_2 () ;
V_9 = F_3 ( V_4 ) ;
V_10 = F_4 ( V_4 ) ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
F_5 ( V_6 , & V_2 -> V_11 , V_2 , V_2 -> V_12 ) ;
F_6 ( V_6 , V_9 , V_10 ) ;
F_3 ( V_4 ) = V_9 + V_8 ;
F_4 ( V_4 ) = V_10 + V_8 ;
}
static void
F_7 ( struct V_1 * V_2 , int V_13 )
{
struct V_14 * V_15 , * V_16 , * V_17 ;
struct V_18 * V_19 ;
V_15 = F_8 ( V_2 , V_13 ) ;
F_9 (qe, qen, waitq) {
if ( F_10 ( V_2 , V_13 ) )
break;
F_11 ( V_16 ) ;
V_19 = (struct V_18 * ) V_16 ;
V_19 -> V_20 ( V_19 -> V_21 ) ;
}
}
void
F_12 ( struct V_1 * V_2 , int V_22 )
{
F_13 ( V_2 ) ;
}
T_4
F_13 ( struct V_1 * V_2 )
{
T_1 V_23 , V_24 ;
int V_25 ;
V_23 = F_14 ( V_2 -> V_26 . V_27 . V_28 ) ;
if ( ! V_23 )
return V_29 ;
V_24 = V_23 & V_30 ;
F_15 ( V_24 , V_2 -> V_26 . V_27 . V_28 ) ;
for ( V_25 = 0 ; V_25 < V_31 ; V_25 ++ ) {
if ( V_23 & ( V_32 << V_25 ) )
F_16 ( V_2 , V_25 & ( V_33 - 1 ) ) ;
}
V_23 &= ~ V_24 ;
if ( ! V_23 )
return V_34 ;
V_24 = V_23 & V_35 ;
F_15 ( V_24 , V_2 -> V_26 . V_27 . V_28 ) ;
for ( V_25 = 0 ; V_25 < V_31 ; V_25 ++ ) {
if ( V_23 & ( V_36 << V_25 ) )
F_17 ( V_2 , V_25 & ( V_33 - 1 ) ) ;
}
V_23 &= ~ V_24 ;
if ( ! V_23 )
return V_34 ;
F_18 ( V_2 , V_23 ) ;
return V_34 ;
}
void
F_19 ( struct V_1 * V_2 )
{
T_1 V_37 ;
int V_38 = F_20 ( & V_2 -> V_11 ) ;
F_21 ( V_2 , V_38 ) ;
F_22 ( V_2 ) ;
V_37 = ( V_39 | V_40 |
V_41 | V_42 |
V_43 ) ;
if ( V_38 == 0 )
V_37 |= ( V_36 | V_44 |
V_45 | V_46 |
V_32 | V_47 |
V_48 | V_49 |
V_50 ) ;
else
V_37 |= ( V_51 | V_52 |
V_53 | V_54 |
V_55 | V_56 |
V_57 | V_58 |
V_59 ) ;
F_15 ( V_37 , V_2 -> V_26 . V_27 . V_28 ) ;
F_15 ( ~ V_37 , V_2 -> V_26 . V_27 . V_60 ) ;
V_2 -> V_26 . V_60 = ~ V_37 ;
F_23 ( V_2 , V_2 -> V_61 . V_62 != 0 ) ;
}
void
F_24 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_29 ) ;
F_15 ( - 1L , V_2 -> V_26 . V_27 . V_60 ) ;
F_25 ( V_2 ) ;
}
void
F_17 ( struct V_1 * V_2 , int V_13 )
{
struct V_14 * V_15 ;
V_13 &= ( V_33 - 1 ) ;
V_2 -> V_26 . V_63 . V_64 ( V_2 , V_13 ) ;
V_15 = F_8 ( V_2 , V_13 ) ;
if ( ! F_26 ( V_15 ) )
F_7 ( V_2 , V_13 ) ;
}
void
F_27 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
F_21 ( V_2 , V_66 -> V_67 . V_68 ) ;
F_21 ( V_2 , V_66 -> V_67 . V_69 ) ;
F_21 ( V_2 , V_66 -> V_67 . V_70 . V_71 ) ;
F_28 ( 1 ) ;
F_29 ( V_2 -> V_12 ) ;
}
void
F_16 ( struct V_1 * V_2 , int V_13 )
{
struct V_65 * V_66 ;
T_1 V_72 , V_73 ;
struct V_14 * V_15 ;
V_13 &= ( V_33 - 1 ) ;
V_2 -> V_26 . V_63 . V_74 ( V_2 , V_13 ) ;
V_73 = F_30 ( V_2 , V_13 ) ;
V_72 = F_31 ( V_2 , V_13 ) ;
if ( V_2 -> V_75 ) {
while ( V_73 != V_72 ) {
V_66 = F_32 ( V_2 , V_13 , V_73 ) ;
V_76 [ V_66 -> V_67 . V_68 ] ( V_2 , V_66 ) ;
F_33 ( V_73 , V_2 -> V_26 . V_77 . V_78 . V_79 ) ;
}
}
F_30 ( V_2 , V_13 ) = V_72 ;
F_15 ( V_72 , V_2 -> V_26 . V_27 . V_80 [ V_13 ] ) ;
F_34 () ;
V_15 = F_8 ( V_2 , V_13 ) ;
if ( ! F_26 ( V_15 ) )
F_7 ( V_2 , V_13 ) ;
}
void
F_18 ( struct V_1 * V_2 , int V_22 )
{
T_1 V_23 , V_81 ;
V_23 = F_14 ( V_2 -> V_26 . V_27 . V_28 ) ;
if ( V_23 & ( V_50 | V_59 ) )
F_35 ( & V_2 -> V_11 ) ;
V_23 &= ( V_39 | V_40 |
V_41 | V_42 | V_43 ) ;
if ( V_23 ) {
if ( V_23 & V_43 ) {
V_81 = F_14 ( V_2 -> V_11 . V_82 . V_83 ) ;
V_81 &= ~ V_84 ;
F_15 ( V_81 , V_2 -> V_11 . V_82 . V_83 ) ;
}
if ( V_23 & V_42 ) {
V_81 = F_14 (
V_2 -> V_11 . V_82 . V_85 ) ;
V_81 &= V_86 ;
F_15 ( V_81 ,
V_2 -> V_11 . V_82 . V_85 ) ;
}
F_15 ( V_23 , V_2 -> V_26 . V_27 . V_28 ) ;
F_36 ( & V_2 -> V_11 ) ;
}
}
static void
F_37 ( struct V_87 * V_77 , T_1 * V_8 )
{
int V_88 , V_89 , V_90 ;
V_89 = F_38 ( ( V_77 -> V_78 . V_91 * V_92 ) ,
V_93 ) ;
V_90 = F_38 ( ( V_77 -> V_78 . V_79 * V_92 ) ,
V_93 ) ;
for ( V_88 = 0 ; V_88 < V_77 -> V_94 . V_95 ; V_88 ++ ) {
* V_8 = * V_8 + V_89 ;
* V_8 = * V_8 + V_90 ;
}
for ( V_88 = 0 ; V_88 < V_77 -> V_94 . V_95 ; V_88 ++ )
* V_8 += ( 2 * V_96 ) ;
}
static void
F_39 ( struct V_87 * V_77 , T_1 * V_8 )
{
* V_8 +=
F_38 ( sizeof( struct V_97 ) , V_96 ) ;
* V_8 +=
F_38 ( sizeof( struct V_98 ) ,
V_96 ) ;
}
static void
F_40 ( void * V_99 )
{
struct V_1 * V_2 = V_99 ;
struct V_100 * V_26 = & V_2 -> V_26 ;
struct V_101 V_102 ;
struct V_97 * V_103 = V_26 -> V_104 ;
struct V_87 * V_77 = & V_26 -> V_77 ;
int V_88 ;
F_28 ( V_77 -> V_94 . V_95 > V_33 ) ;
F_21 ( V_2 , V_77 -> V_94 . V_95 ) ;
F_41 ( V_2 ) ;
V_103 -> V_105 = V_106 ;
V_103 -> V_95 = V_77 -> V_94 . V_95 ;
F_42 ( V_103 -> V_107 , V_26 -> V_108 . V_109 ) ;
for ( V_88 = 0 ; V_88 < V_77 -> V_94 . V_95 ; V_88 ++ ) {
F_42 ( V_103 -> V_110 [ V_88 ] ,
V_26 -> V_110 [ V_88 ] . V_109 ) ;
F_42 ( V_103 -> V_111 [ V_88 ] ,
V_26 -> V_112 [ V_88 ] . V_109 ) ;
V_103 -> V_113 [ V_88 ] =
F_43 ( V_77 -> V_78 . V_91 ) ;
F_42 ( V_103 -> V_114 [ V_88 ] ,
V_26 -> V_114 [ V_88 ] . V_109 ) ;
F_42 ( V_103 -> V_115 [ V_88 ] ,
V_26 -> V_116 [ V_88 ] . V_109 ) ;
V_103 -> V_117 [ V_88 ] =
F_43 ( V_77 -> V_78 . V_79 ) ;
}
if ( ! V_26 -> V_118 )
V_103 -> V_119 . V_120 = V_34 ;
V_26 -> V_118 = V_29 ;
F_44 ( V_102 . V_121 , V_122 , V_123 ,
F_45 ( V_2 ) ) ;
F_42 ( V_102 . V_124 , V_26 -> V_103 . V_109 ) ;
F_46 ( & V_2 -> V_11 , & V_102 ,
sizeof( struct V_101 ) ) ;
}
static void
F_47 ( struct V_1 * V_2 , void * V_125 , struct V_87 * V_77 ,
struct V_126 * V_127 )
{
struct V_100 * V_26 = & V_2 -> V_26 ;
V_2 -> V_125 = V_125 ;
V_26 -> V_2 = V_2 ;
V_26 -> V_128 = V_129 ;
V_26 -> V_77 = * V_77 ;
if ( F_48 ( F_49 ( & V_2 -> V_11 ) ) ) {
V_26 -> V_63 . V_130 = V_131 ;
V_26 -> V_63 . V_64 = V_132 ;
V_26 -> V_63 . V_74 = V_133 ;
V_26 -> V_63 . V_134 = V_135 ;
V_26 -> V_63 . V_136 = V_137 ;
V_26 -> V_63 . V_138 = V_139 ;
V_26 -> V_63 . V_140 = V_141 ;
V_26 -> V_63 . V_142 = V_143 ;
V_26 -> V_63 . V_144 = V_145 ;
} else {
V_26 -> V_63 . V_130 = V_146 ;
V_26 -> V_63 . V_64 = V_147 ;
V_26 -> V_63 . V_74 = V_148 ;
V_26 -> V_63 . V_134 = V_149 ;
V_26 -> V_63 . V_136 = V_150 ;
V_26 -> V_63 . V_138 = V_151 ;
V_26 -> V_63 . V_140 = V_152 ;
V_26 -> V_63 . V_142 = V_153 ;
V_26 -> V_63 . V_144 = V_154 ;
}
V_26 -> V_63 . V_130 ( V_2 ) ;
V_2 -> V_61 . V_62 = 0 ;
}
static void
F_50 ( struct V_1 * V_2 , struct V_87 * V_77 ,
struct V_3 * V_155 )
{
T_2 * V_9 ;
T_3 V_10 ;
int V_88 , V_89 , V_90 ;
struct V_100 * V_26 = & V_2 -> V_26 ;
int V_156 ;
V_9 = F_3 ( V_155 ) ;
V_10 = F_4 ( V_155 ) ;
F_51 ( & V_2 -> V_11 , V_9 , V_10 ) ;
V_9 += F_38 ( sizeof( struct V_157 ) , V_93 ) ;
V_10 += F_38 ( sizeof( struct V_157 ) , V_93 ) ;
V_89 = F_38 ( ( V_77 -> V_78 . V_91 * V_92 ) ,
V_93 ) ;
V_90 = F_38 ( ( V_77 -> V_78 . V_79 * V_92 ) ,
V_93 ) ;
for ( V_88 = 0 ; V_88 < V_77 -> V_94 . V_95 ; V_88 ++ ) {
V_26 -> V_110 [ V_88 ] . V_158 = V_9 ;
V_26 -> V_110 [ V_88 ] . V_109 = V_10 ;
memset ( V_9 , 0 , V_89 ) ;
V_9 += V_89 ;
V_10 += V_89 ;
V_26 -> V_114 [ V_88 ] . V_158 = V_9 ;
V_26 -> V_114 [ V_88 ] . V_109 = V_10 ;
memset ( V_9 , 0 , V_90 ) ;
V_9 += V_90 ;
V_10 += V_90 ;
}
for ( V_88 = 0 ; V_88 < V_77 -> V_94 . V_95 ; V_88 ++ ) {
V_26 -> V_112 [ V_88 ] . V_158 = V_9 ;
V_26 -> V_112 [ V_88 ] . V_109 = V_10 ;
V_9 += V_96 ;
V_10 += V_96 ;
V_26 -> V_116 [ V_88 ] . V_158 = V_9 ;
V_26 -> V_116 [ V_88 ] . V_109 = V_10 ;
V_9 += V_96 ;
V_10 += V_96 ;
}
V_2 -> V_26 . V_103 . V_158 = V_9 ;
V_2 -> V_26 . V_103 . V_109 = V_10 ;
V_2 -> V_26 . V_104 = (struct V_97 * ) V_9 ;
V_9 += F_38 ( sizeof( struct V_97 ) , V_96 ) ;
V_10 += F_38 ( sizeof( struct V_97 ) , V_96 ) ;
V_2 -> V_26 . V_108 . V_158 = V_9 ;
V_2 -> V_26 . V_108 . V_109 = V_10 ;
V_2 -> V_26 . V_159 = (struct V_98 * ) V_9 ;
V_9 +=
F_38 ( sizeof( struct V_98 ) ,
V_96 ) ;
V_10 += F_38 ( sizeof( struct V_98 ) ,
V_96 ) ;
F_3 ( V_155 ) = V_9 ;
F_4 ( V_155 ) = V_10 ;
V_156 = ( V_160 ) ? V_161 : 0 ;
if ( V_156 > 0 ) {
F_52 ( & V_2 -> V_11 , F_53 ( V_155 ) ) ;
F_53 ( V_155 ) += V_156 ;
}
}
static void
F_54 ( struct V_1 * V_2 )
{
int V_88 ;
V_2 -> V_75 = V_34 ;
for ( V_88 = 0 ; V_162 [ V_88 ] ; V_88 ++ )
V_162 [ V_88 ] -> F_55 ( V_2 ) ;
}
static void
F_56 ( struct V_1 * V_2 )
{
int V_88 ;
for ( V_88 = 0 ; V_162 [ V_88 ] ; V_88 ++ )
V_162 [ V_88 ] -> F_57 ( V_2 ) ;
}
static void
F_58 ( void * V_99 , T_4 V_163 )
{
struct V_1 * V_2 = V_99 ;
if ( V_163 ) {
if ( V_2 -> V_26 . V_118 )
F_59 ( V_2 -> V_125 , V_164 ) ;
else
F_59 ( V_2 -> V_125 , V_165 ) ;
} else {
if ( V_2 -> V_26 . V_118 )
V_2 -> V_26 . V_128 = V_129 ;
}
}
static void
F_60 ( void * V_99 , T_4 V_166 )
{
struct V_1 * V_2 = V_99 ;
struct V_167 * V_125 = V_2 -> V_125 ;
if ( V_166 )
V_163 ( & V_125 -> V_168 ) ;
else
V_2 -> V_26 . V_128 = V_129 ;
}
static void
F_61 ( void * V_99 , T_4 V_166 )
{
struct V_1 * V_2 = V_99 ;
struct V_167 * V_125 = V_2 -> V_125 ;
if ( V_166 )
V_163 ( & V_125 -> V_169 ) ;
}
static void
F_62 ( struct V_1 * V_2 )
{
struct V_100 * V_26 = & V_2 -> V_26 ;
struct V_98 * V_159 = V_26 -> V_159 ;
struct V_170 * V_94 = & V_159 -> V_94 ;
V_94 -> V_95 = V_94 -> V_95 ;
V_94 -> V_171 = F_63 ( V_94 -> V_171 ) ;
V_94 -> V_172 = F_63 ( V_94 -> V_172 ) ;
V_94 -> V_173 = F_63 ( V_94 -> V_173 ) ;
V_94 -> V_174 = F_63 ( V_94 -> V_174 ) ;
V_94 -> V_175 = F_63 ( V_94 -> V_175 ) ;
V_26 -> V_118 = V_34 ;
F_64 ( V_2 ) ;
if ( V_26 -> V_128 == V_176 )
F_65 ( V_2 , & V_26 -> V_177 , F_58 , V_2 ) ;
else
F_54 ( V_2 ) ;
}
void
F_41 ( struct V_1 * V_2 )
{
int V_178 ;
for ( V_178 = 0 ; V_178 < V_33 ; V_178 ++ ) {
F_66 ( V_2 , V_178 ) = 0 ;
F_67 ( V_2 , V_178 ) = 0 ;
F_30 ( V_2 , V_178 ) = 0 ;
F_31 ( V_2 , V_178 ) = 0 ;
}
}
static void
F_68 ( void * V_99 , enum V_179 V_180 )
{
struct V_1 * V_2 = V_99 ;
if ( V_180 != V_164 ) {
F_24 ( V_2 ) ;
if ( V_2 -> V_26 . V_128 == V_176 )
F_65 ( V_2 , & V_2 -> V_26 . V_177 ,
F_58 , V_2 ) ;
return;
}
F_40 ( V_2 ) ;
}
static void
F_69 ( void * V_99 )
{
struct V_1 * V_2 = V_99 ;
F_24 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( V_2 -> V_26 . V_128 == V_181 )
F_65 ( V_2 , & V_2 -> V_26 . V_182 , F_60 ,
V_2 ) ;
else {
F_28 ( V_2 -> V_26 . V_128 != V_183 ) ;
F_65 ( V_2 , & V_2 -> V_26 . V_184 , F_61 ,
V_2 ) ;
}
}
static void
F_70 ( void * V_99 )
{
struct V_1 * V_2 = V_99 ;
V_2 -> V_75 = V_29 ;
F_24 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( V_2 -> V_26 . V_128 == V_176 )
F_65 ( V_2 , & V_2 -> V_26 . V_177 , F_58 ,
V_2 ) ;
}
static void
F_71 ( void * V_99 )
{
struct V_1 * V_2 = V_99 ;
F_41 ( V_2 ) ;
F_19 ( V_2 ) ;
}
void
F_72 ( struct V_87 * V_77 , T_1 * V_185 ,
T_1 * V_8 )
{
* V_8 += F_38 ( sizeof( struct V_157 ) , V_93 ) ;
F_39 ( V_77 , V_8 ) ;
F_37 ( V_77 , V_8 ) ;
* V_185 += ( V_160 ) ? V_161 : 0 ;
}
void
F_73 ( struct V_1 * V_2 , void * V_125 , struct V_87 * V_77 ,
struct V_3 * V_155 , struct V_126 * V_127 )
{
int V_88 ;
struct V_186 * V_11 = & V_2 -> V_11 ;
V_187 . V_188 = F_68 ;
V_187 . V_189 = F_69 ;
V_187 . V_190 = F_70 ;
V_187 . V_191 = F_71 ;
V_11 -> V_12 = V_2 -> V_12 ;
F_74 ( & V_2 -> V_11 , V_2 , & V_187 , & V_2 -> V_192 ) ;
if ( V_127 -> V_193 == V_194 )
F_75 ( & V_2 -> V_11 ) ;
F_76 ( & V_2 -> V_11 , V_127 , V_122 ) ;
F_77 ( & V_2 -> V_11 , V_195 ) ;
F_47 ( V_2 , V_125 , V_77 , V_127 ) ;
F_50 ( V_2 , V_77 , V_155 ) ;
F_78 ( & V_2 -> V_192 . V_196 ) ;
F_78 ( & V_2 -> V_197 ) ;
for ( V_88 = 0 ; V_88 < V_33 ; V_88 ++ )
F_78 ( & V_2 -> V_198 [ V_88 ] ) ;
}
void
F_79 ( struct V_1 * V_2 )
{
V_2 -> V_26 . V_128 = V_176 ;
F_80 ( & V_2 -> V_11 ) ;
}
void
F_81 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 . V_118 )
F_54 ( V_2 ) ;
}
void
F_82 ( struct V_1 * V_2 )
{
V_2 -> V_26 . V_128 = V_181 ;
V_2 -> V_75 = V_29 ;
F_83 ( & V_2 -> V_11 ) ;
}
void
F_84 ( void * V_199 , struct V_200 * V_66 )
{
struct V_1 * V_2 = V_199 ;
struct V_100 * V_26 = & V_2 -> V_26 ;
union V_201 * V_202 ;
V_202 = (union V_201 * ) V_66 ;
F_21 ( V_2 , V_202 -> V_121 . V_69 ) ;
switch ( V_202 -> V_121 . V_69 ) {
case V_203 :
V_26 -> V_204 = & V_202 -> V_204 ;
F_62 ( V_2 ) ;
break;
case V_205 :
V_26 -> V_206 ( V_26 -> V_207 , V_164 ) ;
break;
default:
F_28 ( 1 ) ;
}
}
void
F_85 ( struct V_1 * V_2 , struct V_208 * V_209 )
{
struct V_100 * V_26 = & V_2 -> V_26 ;
V_209 -> V_119 . V_120 = V_26 -> V_104 -> V_119 . V_120 ;
V_209 -> V_119 . V_210 = V_26 -> V_104 -> V_119 . V_210 ?
F_63 ( V_26 -> V_104 -> V_119 . V_210 ) :
F_63 ( V_26 -> V_159 -> V_119 . V_210 ) ;
V_209 -> V_119 . V_211 = V_26 -> V_104 -> V_119 . V_211 ?
F_63 ( V_26 -> V_104 -> V_119 . V_211 ) :
F_63 ( V_26 -> V_159 -> V_119 . V_211 ) ;
V_209 -> V_212 = V_26 -> V_77 ;
}
T_5
F_86 ( struct V_1 * V_2 , struct V_213 * V_209 )
{
struct V_100 * V_26 = & V_2 -> V_26 ;
struct V_214 * V_66 ;
V_26 -> V_104 -> V_119 . V_120 = V_209 -> V_120 ;
V_26 -> V_104 -> V_119 . V_210 = F_43 ( V_209 -> V_210 ) ;
V_26 -> V_104 -> V_119 . V_211 = F_43 ( V_209 -> V_211 ) ;
if ( ! F_87 ( V_2 ) )
return V_164 ;
V_66 = F_88 ( V_2 , V_215 ) ;
if ( ! V_66 )
return V_216 ;
F_44 ( V_66 -> V_121 , V_122 , V_217 ,
F_45 ( V_2 ) ) ;
V_66 -> V_120 = V_26 -> V_104 -> V_119 . V_120 ;
V_66 -> V_210 = V_26 -> V_104 -> V_119 . V_210 ;
V_66 -> V_211 = V_26 -> V_104 -> V_119 . V_211 ;
F_21 ( V_2 , V_209 -> V_210 ) ;
F_21 ( V_2 , V_209 -> V_211 ) ;
F_89 ( V_2 , V_215 ) ;
return V_164 ;
}
void
F_90 ( struct V_1 * V_2 , T_3 V_218 )
{
struct V_100 * V_26 = & V_2 -> V_26 ;
V_26 -> V_104 -> V_219 = ( V_220 - 1 ) ;
F_42 ( V_26 -> V_104 -> V_221 , V_218 ) ;
}
void
F_91 ( struct V_1 * V_2 )
{
F_92 ( V_2 -> V_222 , V_223 , V_224 , 0 ,
L_1 ) ;
F_80 ( & V_2 -> V_11 ) ;
}
void
F_93 ( struct V_1 * V_2 )
{
F_92 ( V_2 -> V_222 , V_223 , V_224 , 0 ,
L_2 ) ;
V_2 -> V_26 . V_128 = V_183 ;
V_2 -> V_75 = V_29 ;
F_83 ( & V_2 -> V_11 ) ;
}
T_4
F_87 ( struct V_1 * V_2 )
{
return F_94 ( & V_2 -> V_11 ) && V_2 -> V_26 . V_118 ;
}
void
F_95 ( struct V_1 * V_2 , T_2 * V_225 , T_6 * V_226 )
{
struct V_100 * V_26 = & V_2 -> V_26 ;
struct V_98 * V_159 = V_26 -> V_159 ;
int V_88 ;
if ( V_159 -> V_227 . V_228 && V_159 -> V_227 . V_229 ) {
F_21 ( V_2 , V_159 -> V_227 . V_229 ) ;
* V_225 = V_159 -> V_227 . V_229 ;
for ( V_88 = 0 ; V_88 < V_159 -> V_227 . V_229 ; V_88 ++ )
V_226 [ V_88 ] = V_159 -> V_227 . V_230 [ V_88 ] . V_231 ;
return;
}
* V_225 = V_159 -> V_232 . V_225 ;
memcpy ( V_226 , V_159 -> V_232 . V_233 , sizeof( V_159 -> V_232 . V_233 ) ) ;
}
int
F_96 ( struct V_1 * V_2 , struct V_234 * V_235 )
{
struct V_100 * V_26 = & V_2 -> V_26 ;
struct V_98 * V_159 = V_26 -> V_159 ;
memcpy ( V_235 , V_159 -> V_227 . V_236 , sizeof( V_159 -> V_227 . V_236 ) ) ;
return V_159 -> V_227 . V_237 ;
}
void
F_97 ( struct V_87 * V_77 , struct V_3 * V_155 )
{
int V_88 ;
T_1 V_185 = 0 , V_8 = 0 ;
F_28 ( ( V_77 == NULL ) || ( V_155 == NULL ) ) ;
memset ( ( void * ) V_155 , 0 , sizeof( struct V_3 ) ) ;
V_155 -> V_155 [ V_238 - 1 ] . V_239 =
V_238 ;
V_155 -> V_155 [ V_240 - 1 ] . V_239 =
V_240 ;
F_72 ( V_77 , & V_185 , & V_8 ) ;
for ( V_88 = 0 ; V_162 [ V_88 ] ; V_88 ++ )
V_162 [ V_88 ] -> V_155 ( V_77 , & V_185 , & V_8 ) ;
V_8 += F_2 () ;
V_155 -> V_155 [ V_238 - 1 ] . V_241 = V_185 ;
V_155 -> V_155 [ V_240 - 1 ] . V_241 = V_8 ;
}
void
F_98 ( struct V_1 * V_2 , void * V_125 , struct V_87 * V_77 ,
struct V_3 * V_155 , struct V_126 * V_127 )
{
int V_88 ;
struct V_242 * V_243 ;
V_2 -> V_244 = V_29 ;
F_28 ( ( V_77 == NULL ) || ( V_155 == NULL ) ) ;
for ( V_88 = 0 ; V_88 < V_245 ; V_88 ++ ) {
V_243 = V_155 -> V_155 + V_88 ;
V_243 -> V_246 = V_243 -> V_158 ;
V_243 -> V_247 = V_243 -> V_248 ;
}
F_73 ( V_2 , V_125 , V_77 , V_155 , V_127 ) ;
for ( V_88 = 0 ; V_162 [ V_88 ] ; V_88 ++ )
V_162 [ V_88 ] -> F_99 ( V_2 , V_125 , V_77 , V_155 , V_127 ) ;
F_1 ( V_2 , V_155 ) ;
}
void
F_100 ( struct V_1 * V_2 )
{
int V_88 ;
for ( V_88 = 0 ; V_162 [ V_88 ] ; V_88 ++ )
V_162 [ V_88 ] -> F_101 ( V_2 ) ;
F_102 ( & V_2 -> V_11 ) ;
}
void
F_103 ( struct V_1 * V_2 , struct V_14 * V_197 )
{
F_78 ( V_197 ) ;
F_104 ( & V_2 -> V_197 , V_197 ) ;
}
void
F_105 ( struct V_1 * V_2 , struct V_14 * V_197 )
{
struct V_14 * V_16 ;
struct V_14 * V_17 ;
struct V_249 * V_250 ;
F_9 (qe, qen, comp_q) {
V_250 = (struct V_249 * ) V_16 ;
V_250 -> V_251 ( V_250 -> V_21 , V_34 ) ;
}
}
void
F_106 ( struct V_1 * V_2 , struct V_14 * V_197 )
{
struct V_14 * V_16 ;
struct V_249 * V_250 ;
while ( ! F_26 ( V_197 ) ) {
F_107 ( V_197 , & V_16 ) ;
V_250 = (struct V_249 * ) V_16 ;
V_250 -> V_251 ( V_250 -> V_21 , V_29 ) ;
}
}
void
F_108 ( struct V_252 * * V_253 , int * V_254 )
{
static struct V_252 V_255 [] = {
{ V_256 , V_257 } ,
{ V_256 , V_258 } ,
{ V_256 , V_259 } ,
{ V_256 , V_194 } ,
} ;
* V_254 = sizeof( V_255 ) / sizeof( V_255 [ 0 ] ) ;
* V_253 = V_255 ;
}
void
F_109 ( struct V_87 * V_77 )
{
V_77 -> V_94 . V_260 = V_261 ;
V_77 -> V_94 . V_262 = V_263 ;
V_77 -> V_94 . V_175 = V_264 ;
V_77 -> V_94 . V_171 = V_265 ;
V_77 -> V_94 . V_172 = V_266 ;
V_77 -> V_94 . V_173 = V_267 ;
V_77 -> V_94 . V_174 = V_268 ;
V_77 -> V_94 . V_95 = V_269 ;
V_77 -> V_78 . V_91 = V_270 ;
V_77 -> V_78 . V_79 = V_271 ;
V_77 -> V_78 . V_272 = V_273 ;
V_77 -> V_78 . V_274 = V_275 ;
V_77 -> V_78 . V_276 = V_277 ;
V_77 -> V_78 . V_278 = V_279 ;
V_77 -> V_78 . V_280 = V_29 ;
V_77 -> V_78 . V_281 = V_29 ;
}
void
F_110 ( struct V_87 * V_77 )
{
F_109 ( V_77 ) ;
V_77 -> V_94 . V_171 = V_282 ;
V_77 -> V_94 . V_172 = V_283 ;
V_77 -> V_94 . V_173 = V_284 ;
V_77 -> V_94 . V_174 = V_285 ;
V_77 -> V_94 . V_175 = V_286 ;
V_77 -> V_78 . V_272 = V_287 ;
V_77 -> V_78 . V_91 = V_288 ;
V_77 -> V_78 . V_79 = V_289 ;
V_77 -> V_78 . V_290 = V_34 ;
}
