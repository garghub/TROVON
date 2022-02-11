void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_4 ;
V_3 -> V_5 . error = V_1 -> V_6 ;
F_2 ( V_3 ) ;
V_3 -> V_5 . V_7 = 1 ;
F_3 ( & V_3 -> V_8 ) ;
F_4 ( V_1 ) ;
if ( V_3 -> V_9 )
F_5 ( V_3 ) ;
}
static void F_6 ( struct V_10 * V_11 ) __releases( T_1 )
{
unsigned long V_12 = 0 ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
F_7 ( & V_3 -> V_15 -> V_16 , V_12 ) ;
V_3 -> V_17 += V_11 -> V_18 . V_19 >> 9 ;
F_8 ( & V_11 -> V_20 . V_21 ) ;
if ( F_9 ( & V_3 -> V_22 ) )
F_3 ( & V_3 -> V_23 ) ;
if ( F_10 ( V_24 , & V_11 -> V_12 ) )
F_11 ( V_3 , V_25 ) ;
F_12 ( & V_3 -> V_15 -> V_16 , V_12 ) ;
F_13 ( & V_14 -> V_26 -> V_27 , & V_11 -> V_20 ) ;
F_5 ( V_3 ) ;
}
void F_14 ( struct V_10 * V_11 ) __releases( T_1 )
{
unsigned long V_12 = 0 ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_28 * V_26 = V_14 -> V_26 ;
struct V_29 V_18 ;
int V_30 ;
T_2 V_31 ;
int V_32 ;
V_18 = V_11 -> V_18 ;
V_32 = V_11 -> V_12 & V_33 ;
V_31 = V_11 -> V_31 ;
V_11 -> V_12 &= ~ V_33 ;
F_7 ( & V_3 -> V_15 -> V_16 , V_12 ) ;
V_3 -> V_34 += V_11 -> V_18 . V_19 >> 9 ;
F_15 ( & V_11 -> V_20 . V_21 , & V_3 -> V_35 ) ;
V_30 = F_9 ( V_31 == V_36 ? & V_3 -> V_37 : & V_3 -> V_38 ) ;
if ( V_11 -> V_12 & V_39 )
F_11 ( V_3 , V_40 ) ;
if ( V_26 -> V_41 >= V_42 ) {
F_16 ( & V_3 -> V_43 ) ;
if ( ! F_17 ( V_26 -> V_44 , & V_14 -> V_45 ) )
F_18 ( & V_3 -> V_43 , V_46 ) ;
}
F_12 ( & V_3 -> V_15 -> V_16 , V_12 ) ;
if ( V_31 == V_36 )
F_19 ( V_3 , V_18 . V_47 ) ;
if ( V_30 )
F_3 ( & V_3 -> V_23 ) ;
if ( V_32 )
F_20 ( V_3 , & V_18 ) ;
F_5 ( V_3 ) ;
}
void F_21 ( struct V_1 * V_1 )
{
struct V_10 * V_11 = V_1 -> V_4 ;
struct V_2 * V_3 = V_11 -> V_14 -> V_3 ;
bool V_48 = F_22 ( V_1 ) == V_49 ;
bool V_50 = ! ! ( F_23 ( V_1 ) == V_51 ) ;
if ( V_1 -> V_6 && F_24 ( & V_52 ) )
F_25 ( V_3 , L_1 ,
V_48 ? ( V_50 ? L_2 : L_3 )
: L_4 , V_1 -> V_6 ,
( unsigned long long ) V_11 -> V_18 . V_47 ) ;
if ( V_1 -> V_6 )
F_26 ( V_24 , & V_11 -> V_12 ) ;
F_4 ( V_1 ) ;
if ( F_27 ( & V_11 -> V_53 ) ) {
if ( V_48 )
F_14 ( V_11 ) ;
else
F_6 ( V_11 ) ;
}
}
void F_28 ( struct V_2 * V_3 )
{
F_29 ( L_5 ,
V_3 -> V_54 , V_3 -> V_15 -> V_55 , V_3 -> V_56 ) ;
}
void F_30 ( struct V_1 * V_1 )
{
unsigned long V_12 ;
struct V_57 * V_58 = V_1 -> V_4 ;
struct V_2 * V_3 = V_58 -> V_3 ;
struct V_59 V_60 ;
enum V_61 V_62 ;
if ( F_31 ( V_58 -> V_63 & V_64 ) ) {
if ( F_24 ( & V_52 ) )
F_32 ( V_3 , L_6 ) ;
if ( ! V_1 -> V_6 )
F_28 ( V_3 ) ;
}
if ( F_31 ( V_1 -> V_6 ) ) {
switch ( F_23 ( V_1 ) ) {
case V_51 :
if ( V_1 -> V_6 == - V_65 )
V_62 = V_66 ;
else
V_62 = V_67 ;
break;
case V_68 :
if ( V_1 -> V_69 & V_70 )
V_62 = V_71 ;
else
V_62 = V_72 ;
break;
default:
V_62 = V_73 ;
break;
}
} else {
V_62 = V_74 ;
}
F_4 ( V_58 -> V_75 ) ;
V_58 -> V_75 = F_33 ( V_1 -> V_6 ) ;
F_7 ( & V_3 -> V_15 -> V_16 , V_12 ) ;
F_34 ( V_58 , V_62 , & V_60 ) ;
F_12 ( & V_3 -> V_15 -> V_16 , V_12 ) ;
F_5 ( V_3 ) ;
if ( V_60 . V_1 )
F_35 ( V_3 , & V_60 ) ;
}
void F_36 ( struct V_76 * V_77 , struct V_10 * V_11 , void * V_78 )
{
F_37 ( V_58 , V_77 ) ;
struct V_79 V_80 ;
struct V_81 * V_81 = V_11 -> V_82 ;
struct V_81 * V_83 ;
unsigned V_84 ;
F_38 ( V_58 , V_77 ) ;
F_39 ( V_58 , 0 , NULL , NULL ) ;
F_40 ( & V_80 , 1 ) ;
F_41 ( V_58 ) ;
while ( ( V_83 = F_42 ( V_81 ) ) ) {
F_43 ( & V_80 , V_81 , V_85 , 0 ) ;
F_44 ( V_58 , & V_80 , NULL , V_80 . V_86 ) ;
F_45 ( V_58 ) ;
V_81 = V_83 ;
}
V_84 = V_11 -> V_18 . V_19 & ( V_85 - 1 ) ;
F_43 ( & V_80 , V_81 , V_84 ? : V_85 , 0 ) ;
F_44 ( V_58 , & V_80 , V_78 , V_80 . V_86 ) ;
F_46 ( V_58 ) ;
F_47 ( V_58 ) ;
}
void F_48 ( struct V_76 * V_77 , struct V_1 * V_1 , void * V_78 )
{
F_37 ( V_58 , V_77 ) ;
struct V_79 V_80 ;
struct V_87 V_88 ;
struct V_89 V_90 ;
F_38 ( V_58 , V_77 ) ;
F_39 ( V_58 , 0 , NULL , NULL ) ;
F_40 ( & V_80 , 1 ) ;
F_41 ( V_58 ) ;
F_49 (bvec, bio, iter) {
F_43 ( & V_80 , V_88 . V_91 , V_88 . V_92 , V_88 . V_93 ) ;
F_44 ( V_58 , & V_80 , NULL , V_80 . V_86 ) ;
F_45 ( V_58 ) ;
if ( F_23 ( V_1 ) == V_94 )
break;
}
F_44 ( V_58 , NULL , V_78 , 0 ) ;
F_50 ( V_58 ) ;
F_47 ( V_58 ) ;
}
static int F_51 ( struct V_95 * V_20 , int V_96 )
{
struct V_10 * V_11 = F_52 ( V_20 , struct V_10 , V_20 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_97 ;
void * V_78 ;
int V_98 = 0 ;
if ( F_31 ( V_96 ) )
goto V_99;
if ( F_31 ( ( V_11 -> V_12 & V_39 ) != 0 ) )
goto V_99;
V_97 = F_53 ( V_14 -> V_26 -> V_100 ) ;
V_78 = F_54 ( V_97 , V_101 ) ;
if ( V_78 ) {
T_3 V_47 = V_11 -> V_18 . V_47 ;
unsigned int V_19 = V_11 -> V_18 . V_19 ;
F_36 ( V_14 -> V_26 -> V_100 , V_11 , V_78 ) ;
F_55 ( V_3 , V_11 ) ;
V_11 = NULL ;
F_56 ( V_3 ) ;
V_98 = F_57 ( V_14 , V_47 , V_19 ,
V_78 , V_97 ,
V_102 ) ;
F_58 ( V_78 ) ;
} else {
F_59 ( V_3 , L_7 ) ;
V_98 = - V_103 ;
}
V_99:
if ( V_11 )
F_55 ( V_3 , V_11 ) ;
if ( F_31 ( V_98 ) )
F_59 ( V_3 , L_8 ) ;
return V_98 ;
}
static int F_60 ( struct V_13 * V_14 , T_3 V_47 , int V_19 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_10 * V_11 ;
if ( ! F_61 ( V_3 ) )
return - V_104 ;
V_11 = F_62 ( V_14 , V_36 , V_47 ,
V_19 , V_19 , V_105 ) ;
if ( ! V_11 )
goto V_106;
V_11 -> V_20 . V_107 = F_51 ;
F_63 ( & V_3 -> V_15 -> V_16 ) ;
F_64 ( & V_11 -> V_20 . V_21 , & V_3 -> V_22 ) ;
F_65 ( & V_3 -> V_15 -> V_16 ) ;
F_66 ( V_19 >> 9 , & V_3 -> V_108 ) ;
if ( F_67 ( V_3 , V_11 , V_68 , 0 ,
V_109 ) == 0 )
return 0 ;
F_63 ( & V_3 -> V_15 -> V_16 ) ;
F_8 ( & V_11 -> V_20 . V_21 ) ;
F_65 ( & V_3 -> V_15 -> V_16 ) ;
F_55 ( V_3 , V_11 ) ;
V_106:
F_5 ( V_3 ) ;
return - V_110 ;
}
int F_68 ( struct V_95 * V_20 , int V_96 )
{
struct V_2 * V_3 =
F_52 ( V_20 , struct V_2 , V_111 ) ;
switch ( V_3 -> V_112 . V_113 ) {
case V_114 :
F_69 ( V_3 , V_96 ) ;
break;
case V_115 :
F_70 ( V_3 , V_96 ) ;
break;
}
return 0 ;
}
void F_71 ( unsigned long V_116 )
{
struct V_2 * V_3 = (struct V_2 * ) V_116 ;
F_72 (
& F_73 ( V_3 ) -> V_26 -> V_27 ,
& V_3 -> V_111 ) ;
}
static void F_74 ( struct V_117 * V_118 , int V_119 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_118 -> V_19 ; V_18 ++ )
V_118 -> V_120 [ V_18 ] = V_119 ;
}
static int F_75 ( struct V_117 * V_118 , int V_119 )
{
int V_121 ;
V_121 = V_118 -> V_120 [ V_118 -> V_122 ] ;
V_118 -> V_120 [ V_118 -> V_122 ++ ] = V_119 ;
if ( V_118 -> V_122 >= V_118 -> V_19 )
V_118 -> V_122 = 0 ;
return V_121 ;
}
static void F_76 ( struct V_117 * V_118 , int V_119 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_118 -> V_19 ; V_18 ++ )
V_118 -> V_120 [ V_18 ] += V_119 ;
}
struct V_117 * F_77 ( int V_123 )
{
struct V_117 * V_118 ;
V_118 = F_78 ( sizeof( struct V_117 ) + sizeof( int ) * V_123 , V_101 ) ;
if ( ! V_118 )
return NULL ;
V_118 -> V_122 = 0 ;
V_118 -> V_19 = V_123 ;
V_118 -> V_124 = 0 ;
return V_118 ;
}
static int F_79 ( struct V_2 * V_3 , unsigned int V_125 )
{
struct V_126 * V_127 ;
unsigned int V_128 ;
int V_129 ;
int V_130 ;
int V_131 ;
int V_132 ;
int V_133 ;
int V_134 ;
struct V_117 * V_135 ;
V_127 = F_80 ( V_3 -> V_9 -> V_126 ) ;
V_135 = F_80 ( V_3 -> V_136 ) ;
V_132 = V_135 -> V_19 ;
if ( V_3 -> V_137 + V_125 == 0 ) {
V_128 = ( ( V_127 -> V_138 * 2 * V_139 ) / V_140 ) * V_132 ;
} else {
V_128 = V_127 -> V_141 ? V_127 -> V_141 :
V_125 * V_127 -> V_142 * V_140 / ( V_139 * 10 ) ;
}
V_130 = V_128 - V_3 -> V_137 - V_135 -> V_124 ;
V_131 = V_130 / V_132 ;
F_76 ( V_135 , V_131 ) ;
V_135 -> V_124 += V_131 * V_132 ;
V_133 = F_75 ( V_135 , 0 ) ;
V_135 -> V_124 -= V_133 ;
V_129 = V_125 + V_133 ;
if ( V_129 < 0 )
V_129 = 0 ;
V_134 = ( V_127 -> V_143 * 2 * V_139 ) / V_140 ;
if ( V_129 > V_134 )
V_129 = V_134 ;
return V_129 ;
}
static int F_81 ( struct V_2 * V_3 )
{
unsigned int V_125 ;
int V_144 , V_145 ;
V_125 = F_82 ( & V_3 -> V_146 , 0 ) ;
V_3 -> V_137 -= V_125 ;
F_83 () ;
V_145 = F_84 ( V_3 ) / 2 ;
if ( F_80 ( V_3 -> V_136 ) -> V_19 ) {
V_144 = F_79 ( V_3 , V_125 ) >> ( V_147 - 9 ) ;
V_3 -> V_148 = V_144 * V_140 * ( V_149 / 1024 ) / V_139 ;
} else {
V_3 -> V_148 = F_80 ( V_3 -> V_9 -> V_126 ) -> V_138 ;
V_144 = V_139 * V_3 -> V_148 / ( ( V_149 / 1024 ) * V_140 ) ;
}
F_85 () ;
if ( V_145 - V_3 -> V_137 / 8 < V_144 )
V_144 = V_145 - V_3 -> V_137 / 8 ;
return V_144 ;
}
static int F_70 ( struct V_2 * const V_3 , int V_96 )
{
struct V_13 * const V_14 = F_73 ( V_3 ) ;
struct V_28 * const V_26 = V_14 ? V_14 -> V_26 : NULL ;
unsigned long V_150 ;
T_3 V_47 ;
const T_3 V_151 = F_86 ( V_3 -> V_152 ) ;
int V_153 ;
int V_144 , V_154 , V_19 ;
int V_155 , V_156 = 0 ;
int V_18 = 0 ;
int V_157 = 0 ;
if ( F_31 ( V_96 ) )
return 0 ;
if ( V_3 -> V_158 == 0 ) {
F_87 ( V_3 ) ;
return 0 ;
}
if ( ! F_61 ( V_3 ) ) {
F_59 ( V_3 , L_9 ) ;
return 0 ;
}
if ( V_26 -> V_159 & V_160 ) {
F_83 () ;
V_157 = F_80 ( V_3 -> V_9 -> V_126 ) -> V_161 ;
F_85 () ;
}
V_153 = F_88 ( V_3 -> V_162 ) << 9 ;
V_144 = F_81 ( V_3 ) ;
if ( V_144 <= 0 )
goto V_156;
for ( V_18 = 0 ; V_18 < V_144 ; V_18 ++ ) {
F_89 ( & V_26 -> V_116 . V_163 ) ;
if ( V_26 -> V_116 . V_164 ) {
struct V_165 * V_166 = V_26 -> V_116 . V_164 -> V_166 ;
int V_167 = V_166 -> V_168 ;
int V_169 = V_166 -> V_170 ;
if ( V_167 > V_169 / 2 ) {
V_156 = 1 ;
if ( V_166 -> V_171 )
F_26 ( V_172 , & V_166 -> V_171 -> V_12 ) ;
}
} else
V_156 = 1 ;
F_90 ( & V_26 -> V_116 . V_163 ) ;
if ( V_156 )
goto V_156;
V_173:
V_19 = V_149 ;
V_150 = F_91 ( V_3 , V_3 -> V_174 ) ;
if ( V_150 == V_175 ) {
V_3 -> V_174 = F_92 ( V_3 ) ;
F_5 ( V_3 ) ;
return 0 ;
}
V_47 = F_93 ( V_150 ) ;
if ( F_94 ( V_3 , V_47 ) ) {
V_3 -> V_174 = V_150 ;
goto V_156;
}
V_3 -> V_174 = V_150 + 1 ;
if ( F_31 ( F_95 ( V_3 , V_150 ) == 0 ) ) {
F_19 ( V_3 , V_47 ) ;
goto V_173;
}
#if V_176 > V_149
V_155 = 1 ;
V_154 = V_18 ;
while ( V_18 < V_144 ) {
if ( V_19 + V_149 > V_153 )
break;
if ( V_47 & ( ( 1 << ( V_155 + 3 ) ) - 1 ) )
break;
if ( V_157 && V_19 == V_157 )
break;
if ( ( ( V_150 + 1 ) & V_177 ) == 0 )
break;
if ( F_95 ( V_3 , V_150 + 1 ) != 1 )
break;
V_150 ++ ;
V_19 += V_149 ;
if ( ( V_149 << V_155 ) <= V_19 )
V_155 ++ ;
V_18 ++ ;
}
if ( V_19 > V_149 )
V_3 -> V_174 = V_150 + 1 ;
#endif
if ( V_47 + ( V_19 >> 9 ) > V_151 )
V_19 = ( V_151 - V_47 ) << 9 ;
if ( V_3 -> V_178 ) {
switch ( F_60 ( V_14 , V_47 , V_19 ) ) {
case - V_104 :
F_5 ( V_3 ) ;
return - V_104 ;
case - V_110 :
F_19 ( V_3 , V_47 ) ;
V_3 -> V_174 = F_96 ( V_47 ) ;
V_18 = V_154 ;
goto V_156;
case 0 :
break;
default:
F_97 () ;
}
} else {
int V_98 ;
F_56 ( V_3 ) ;
V_98 = F_98 ( V_14 ,
V_19 == V_157 ? V_179 : V_180 ,
V_47 , V_19 , V_36 ) ;
if ( V_98 ) {
F_59 ( V_3 , L_10 ) ;
F_99 ( V_3 ) ;
F_5 ( V_3 ) ;
return V_98 ;
}
}
}
if ( V_3 -> V_174 >= F_92 ( V_3 ) ) {
F_5 ( V_3 ) ;
return 0 ;
}
V_156:
V_3 -> V_137 += ( V_18 << ( V_147 - 9 ) ) ;
F_100 ( & V_3 -> V_181 , V_182 + V_139 ) ;
F_5 ( V_3 ) ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 , int V_96 )
{
int V_144 , V_18 , V_19 ;
T_3 V_47 ;
const T_3 V_151 = F_86 ( V_3 -> V_152 ) ;
bool V_183 = false ;
if ( F_31 ( V_96 ) )
return 1 ;
V_144 = F_81 ( V_3 ) ;
V_47 = V_3 -> V_184 ;
for ( V_18 = 0 ; V_18 < V_144 ; V_18 ++ ) {
if ( V_47 >= V_151 )
return 1 ;
V_183 = V_18 > 0
&& F_101 ( V_3 )
&& V_47 >= V_3 -> V_185 ;
if ( V_183 )
break;
V_19 = V_149 ;
if ( F_94 ( V_3 , V_47 ) ) {
V_3 -> V_184 = V_47 ;
goto V_156;
}
if ( V_47 + ( V_19 >> 9 ) > V_151 )
V_19 = ( V_151 - V_47 ) << 9 ;
F_56 ( V_3 ) ;
if ( F_102 ( F_73 ( V_3 ) , V_47 , V_19 ) ) {
F_99 ( V_3 ) ;
return 0 ;
}
V_47 += V_186 ;
}
V_3 -> V_184 = V_47 ;
V_156:
V_3 -> V_137 += ( V_18 << ( V_147 - 9 ) ) ;
if ( V_18 == 0 || ! V_183 )
F_100 ( & V_3 -> V_181 , V_182 + V_139 ) ;
return 1 ;
}
int F_103 ( struct V_95 * V_20 , int V_96 )
{
struct V_187 * V_188 =
F_52 ( V_20 , struct V_187 , V_20 ) ;
struct V_2 * V_3 = V_188 -> V_3 ;
F_58 ( V_188 ) ;
F_104 ( V_3 ) ;
F_87 ( V_3 ) ;
return 0 ;
}
static int F_105 ( struct V_95 * V_20 , int V_96 )
{
struct V_187 * V_188 =
F_52 ( V_20 , struct V_187 , V_20 ) ;
struct V_2 * V_3 = V_188 -> V_3 ;
F_58 ( V_188 ) ;
F_87 ( V_3 ) ;
return 0 ;
}
static void F_106 ( struct V_2 * V_3 )
{
struct V_28 * V_26 = F_73 ( V_3 ) -> V_26 ;
F_107 ( V_189 , & V_26 -> V_12 ) ;
F_108 ( V_26 ) ;
F_109 ( V_26 -> V_190 ,
F_10 ( V_189 , & V_26 -> V_12 ) || V_3 -> V_112 . V_113 < V_191 ) ;
}
int F_87 ( struct V_2 * V_3 )
{
struct V_28 * V_26 = F_73 ( V_3 ) -> V_26 ;
unsigned long V_192 , V_193 , V_194 ;
unsigned long V_195 ;
union V_196 V_197 , V_198 ;
struct V_187 * V_188 ;
char * V_199 = NULL ;
int V_200 = 0 ;
if ( F_110 ( V_3 ) ) {
F_111 ( V_140 / 10 ) ;
V_188 = F_54 ( sizeof( struct V_187 ) , V_201 ) ;
if ( V_188 ) {
V_188 -> V_20 . V_107 = F_105 ;
V_188 -> V_3 = V_3 ;
F_13 ( & V_26 -> V_27 , & V_188 -> V_20 ) ;
return 1 ;
}
F_59 ( V_3 , L_11 ) ;
}
V_193 = ( V_182 - V_3 -> V_202 - V_3 -> V_203 ) / V_140 ;
if ( V_193 <= 0 )
V_193 = 1 ;
V_192 = V_3 -> V_158 ;
if ( V_3 -> V_112 . V_113 == V_114 || V_3 -> V_112 . V_113 == V_204 )
V_192 -= V_3 -> V_205 ;
V_194 = F_112 ( V_192 / V_193 ) ;
V_3 -> V_203 /= V_140 ;
if ( ! F_61 ( V_3 ) )
goto V_99;
F_106 ( V_3 ) ;
F_63 ( & V_3 -> V_15 -> V_16 ) ;
V_197 = F_113 ( V_3 ) ;
V_200 = ( V_197 . V_113 == V_114 || V_197 . V_113 == V_204 ) ;
if ( V_197 . V_113 <= V_191 )
goto V_206;
V_198 = V_197 ;
V_198 . V_113 = V_191 ;
F_114 ( V_3 , L_12 ,
V_200 ? L_13 : L_14 ,
V_193 + V_3 -> V_203 , V_3 -> V_203 , V_194 ) ;
V_195 = F_115 ( V_3 ) ;
if ( V_197 . V_113 == V_114 || V_197 . V_113 == V_204 ) {
if ( V_195 ) {
F_116 ( V_3 , L_15 ,
V_195 , F_112 ( 1 ) ) ;
V_199 = L_16 ;
}
} else {
F_117 ( V_3 , ( V_195 - V_3 -> V_207 ) == 0 ) ;
if ( V_197 . V_113 == V_115 || V_197 . V_113 == V_208 )
V_199 = L_17 ;
if ( V_3 -> V_178 && V_3 -> V_158 ) {
const unsigned long V_209 = V_3 -> V_210 ;
const unsigned long V_211 = V_3 -> V_158 ;
const int V_212 =
( V_211 == 0 ) ? 0 :
( V_211 < 100000 ) ? ( ( V_209 * 100 ) / V_211 ) : ( V_209 / ( V_211 / 100 ) ) ;
F_114 ( V_3 , L_18
L_19 ,
V_212 ,
F_112 ( V_3 -> V_210 ) ,
F_112 ( V_3 -> V_158 - V_3 -> V_210 ) ,
F_112 ( V_3 -> V_158 ) ) ;
}
}
if ( V_3 -> V_207 ) {
F_114 ( V_3 , L_20 , V_3 -> V_207 ) ;
if ( V_197 . V_113 == V_115 || V_197 . V_113 == V_208 ) {
V_198 . V_213 = V_214 ;
V_198 . V_215 = V_216 ;
} else {
V_198 . V_213 = V_216 ;
V_198 . V_215 = V_214 ;
}
} else {
V_198 . V_213 = V_216 ;
V_198 . V_215 = V_216 ;
if ( V_197 . V_113 == V_115 || V_197 . V_113 == V_208 ) {
if ( V_3 -> V_217 ) {
int V_18 ;
for ( V_18 = V_218 ; V_18 <= V_219 ; V_18 ++ )
F_118 ( V_3 , V_18 , V_3 -> V_217 [ V_18 ] ) ;
F_119 ( V_3 , V_218 , V_3 -> V_9 -> V_220 . V_221 [ V_222 ] ) ;
F_118 ( V_3 , V_222 , V_3 -> V_217 [ V_222 ] ) ;
} else {
F_59 ( V_3 , L_21 ) ;
}
}
if ( ! ( V_197 . V_113 == V_114 || V_197 . V_113 == V_204 ) ) {
F_120 ( V_3 , 0UL ) ;
F_121 ( V_3 , L_22 ) ;
if ( V_3 -> V_217 ) {
int V_18 ;
for ( V_18 = V_222 ; V_18 <= V_219 ; V_18 ++ )
V_3 -> V_217 [ V_18 ] = V_3 -> V_9 -> V_220 . V_221 [ V_18 ] ;
}
}
}
F_122 ( V_3 , V_198 , V_223 , NULL ) ;
V_206:
F_65 ( & V_3 -> V_15 -> V_16 ) ;
if ( V_197 . V_113 == V_224 ) {
enum V_225 V_226 = V_227 ;
enum V_225 V_228 = V_227 ;
enum V_229 V_230 = V_231 ;
F_83 () ;
V_230 = F_80 ( V_3 -> V_9 -> V_126 ) -> V_232 ;
if ( V_230 != V_231 ) {
struct V_13 * V_14 ;
int V_56 ;
F_123 (&connection->peer_devices, peer_device, vnr) {
struct V_2 * V_3 = V_14 -> V_3 ;
V_226 = F_124 ( enum V_225 , V_226 , V_3 -> V_112 . V_213 ) ;
V_228 = F_124 ( enum V_225 , V_228 , V_3 -> V_112 . V_215 ) ;
}
}
F_85 () ;
if ( V_226 == V_216 && V_228 == V_216 )
F_125 ( V_26 , L_23 ) ;
}
F_5 ( V_3 ) ;
V_99:
V_3 -> V_158 = 0 ;
V_3 -> V_207 = 0 ;
V_3 -> V_203 = 0 ;
if ( V_200 && V_3 -> V_205 == 0 )
V_3 -> V_233 = 0 ;
F_126 ( V_3 ) ;
if ( V_199 )
F_127 ( V_3 , V_199 ) ;
return 1 ;
}
static void F_128 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
if ( F_129 ( V_11 ) ) {
int V_18 = ( V_11 -> V_18 . V_19 + V_85 - 1 ) >> V_234 ;
F_66 ( V_18 , & V_3 -> V_235 ) ;
F_130 ( V_18 , & V_3 -> V_236 ) ;
F_63 ( & V_3 -> V_15 -> V_16 ) ;
F_64 ( & V_11 -> V_20 . V_21 , & V_3 -> V_237 ) ;
F_65 ( & V_3 -> V_15 -> V_16 ) ;
F_3 ( & V_238 ) ;
} else
F_55 ( V_3 , V_11 ) ;
}
int F_131 ( struct V_95 * V_20 , int V_96 )
{
struct V_10 * V_11 = F_52 ( V_20 , struct V_10 , V_20 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_98 ;
if ( F_31 ( V_96 ) ) {
F_55 ( V_3 , V_11 ) ;
F_132 ( V_3 ) ;
return 0 ;
}
if ( F_133 ( ( V_11 -> V_12 & V_39 ) == 0 ) ) {
V_98 = F_134 ( V_14 , V_239 , V_11 ) ;
} else {
if ( F_24 ( & V_52 ) )
F_59 ( V_3 , L_24 ,
( unsigned long long ) V_11 -> V_18 . V_47 ) ;
V_98 = F_135 ( V_14 , V_240 , V_11 ) ;
}
F_132 ( V_3 ) ;
F_128 ( V_3 , V_11 ) ;
if ( F_31 ( V_98 ) )
F_59 ( V_3 , L_25 ) ;
return V_98 ;
}
static bool F_136 ( struct V_10 * V_11 )
{
struct V_81 * V_81 = V_11 -> V_82 ;
unsigned int V_84 = V_11 -> V_18 . V_19 ;
F_137 (page) {
unsigned int V_241 = F_124 (unsigned int, len, PAGE_SIZE) ;
unsigned int V_18 , V_242 = V_241 / sizeof( long ) ;
unsigned long * V_243 ;
V_243 = F_138 ( V_81 ) ;
for ( V_18 = 0 ; V_18 < V_242 ; V_18 ++ ) {
if ( V_243 [ V_18 ] ) {
F_139 ( V_243 ) ;
return false ;
}
}
F_139 ( V_243 ) ;
V_84 -= V_241 ;
}
return true ;
}
int F_140 ( struct V_95 * V_20 , int V_96 )
{
struct V_10 * V_11 = F_52 ( V_20 , struct V_10 , V_20 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_98 ;
if ( F_31 ( V_96 ) ) {
F_55 ( V_3 , V_11 ) ;
F_132 ( V_3 ) ;
return 0 ;
}
if ( F_141 ( V_3 , V_244 ) ) {
F_19 ( V_3 , V_11 -> V_18 . V_47 ) ;
F_5 ( V_3 ) ;
}
if ( V_3 -> V_112 . V_113 == V_245 ) {
V_98 = F_135 ( V_14 , V_246 , V_11 ) ;
} else if ( F_133 ( ( V_11 -> V_12 & V_39 ) == 0 ) ) {
if ( F_133 ( V_3 -> V_112 . V_215 >= V_214 ) ) {
F_56 ( V_3 ) ;
if ( V_11 -> V_12 & V_247 && F_136 ( V_11 ) )
V_98 = F_142 ( V_14 , V_11 ) ;
else
V_98 = F_134 ( V_14 , V_248 , V_11 ) ;
} else {
if ( F_24 ( & V_52 ) )
F_59 ( V_3 , L_26
L_27 ) ;
V_98 = 0 ;
}
} else {
if ( F_24 ( & V_52 ) )
F_59 ( V_3 , L_28 ,
( unsigned long long ) V_11 -> V_18 . V_47 ) ;
V_98 = F_135 ( V_14 , V_249 , V_11 ) ;
F_143 ( V_3 , V_11 -> V_18 . V_47 , V_11 -> V_18 . V_19 ) ;
}
F_132 ( V_3 ) ;
F_128 ( V_3 , V_11 ) ;
if ( F_31 ( V_98 ) )
F_59 ( V_3 , L_25 ) ;
return V_98 ;
}
int F_144 ( struct V_95 * V_20 , int V_96 )
{
struct V_10 * V_11 = F_52 ( V_20 , struct V_10 , V_20 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_250 * V_251 ;
int V_97 ;
void * V_78 = NULL ;
int V_98 , V_252 = 0 ;
if ( F_31 ( V_96 ) ) {
F_55 ( V_3 , V_11 ) ;
F_132 ( V_3 ) ;
return 0 ;
}
if ( F_61 ( V_3 ) ) {
F_19 ( V_3 , V_11 -> V_18 . V_47 ) ;
F_5 ( V_3 ) ;
}
V_251 = V_11 -> V_78 ;
if ( F_133 ( ( V_11 -> V_12 & V_39 ) == 0 ) ) {
if ( V_14 -> V_26 -> V_100 ) {
V_97 = F_53 ( V_14 -> V_26 -> V_100 ) ;
F_117 ( V_3 , V_97 == V_251 -> V_97 ) ;
V_78 = F_54 ( V_97 , V_101 ) ;
}
if ( V_78 ) {
F_36 ( V_14 -> V_26 -> V_100 , V_11 , V_78 ) ;
V_252 = ! memcmp ( V_78 , V_251 -> V_78 , V_97 ) ;
F_58 ( V_78 ) ;
}
if ( V_252 ) {
F_145 ( V_3 , V_11 -> V_18 . V_47 , V_11 -> V_18 . V_19 ) ;
V_3 -> V_210 += V_11 -> V_18 . V_19 >> V_147 ;
V_98 = F_135 ( V_14 , V_253 , V_11 ) ;
} else {
F_56 ( V_3 ) ;
V_11 -> V_31 = V_36 ;
V_11 -> V_12 &= ~ V_254 ;
F_58 ( V_251 ) ;
V_98 = F_134 ( V_14 , V_248 , V_11 ) ;
}
} else {
V_98 = F_135 ( V_14 , V_249 , V_11 ) ;
if ( F_24 ( & V_52 ) )
F_59 ( V_3 , L_29 ) ;
}
F_132 ( V_3 ) ;
F_128 ( V_3 , V_11 ) ;
if ( F_31 ( V_98 ) )
F_59 ( V_3 , L_30 ) ;
return V_98 ;
}
int F_146 ( struct V_95 * V_20 , int V_96 )
{
struct V_10 * V_11 = F_52 ( V_20 , struct V_10 , V_20 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
T_3 V_47 = V_11 -> V_18 . V_47 ;
unsigned int V_19 = V_11 -> V_18 . V_19 ;
int V_97 ;
void * V_78 ;
int V_98 = 0 ;
if ( F_31 ( V_96 ) )
goto V_99;
V_97 = F_53 ( V_14 -> V_26 -> V_255 ) ;
V_78 = F_54 ( V_97 , V_101 ) ;
if ( ! V_78 ) {
V_98 = 1 ;
goto V_99;
}
if ( F_133 ( ! ( V_11 -> V_12 & V_39 ) ) )
F_36 ( V_14 -> V_26 -> V_255 , V_11 , V_78 ) ;
else
memset ( V_78 , 0 , V_97 ) ;
F_55 ( V_3 , V_11 ) ;
V_11 = NULL ;
F_56 ( V_3 ) ;
V_98 = F_57 ( V_14 , V_47 , V_19 , V_78 , V_97 , V_256 ) ;
if ( V_98 )
F_99 ( V_3 ) ;
F_58 ( V_78 ) ;
V_99:
if ( V_11 )
F_55 ( V_3 , V_11 ) ;
F_132 ( V_3 ) ;
return V_98 ;
}
void F_147 ( struct V_2 * V_3 , T_3 V_47 , int V_19 )
{
if ( V_3 -> V_257 + V_3 -> V_258 == V_47 ) {
V_3 -> V_258 += V_19 >> 9 ;
} else {
V_3 -> V_257 = V_47 ;
V_3 -> V_258 = V_19 >> 9 ;
}
F_148 ( V_3 , V_47 , V_19 ) ;
}
int F_149 ( struct V_95 * V_20 , int V_96 )
{
struct V_10 * V_11 = F_52 ( V_20 , struct V_10 , V_20 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_250 * V_251 ;
void * V_78 ;
T_3 V_47 = V_11 -> V_18 . V_47 ;
unsigned int V_19 = V_11 -> V_18 . V_19 ;
int V_97 ;
int V_98 , V_252 = 0 ;
bool V_183 = false ;
if ( F_31 ( V_96 ) ) {
F_55 ( V_3 , V_11 ) ;
F_132 ( V_3 ) ;
return 0 ;
}
if ( F_61 ( V_3 ) ) {
F_19 ( V_3 , V_11 -> V_18 . V_47 ) ;
F_5 ( V_3 ) ;
}
V_251 = V_11 -> V_78 ;
if ( F_133 ( ( V_11 -> V_12 & V_39 ) == 0 ) ) {
V_97 = F_53 ( V_14 -> V_26 -> V_255 ) ;
V_78 = F_54 ( V_97 , V_101 ) ;
if ( V_78 ) {
F_36 ( V_14 -> V_26 -> V_255 , V_11 , V_78 ) ;
F_117 ( V_3 , V_97 == V_251 -> V_97 ) ;
V_252 = ! memcmp ( V_78 , V_251 -> V_78 , V_97 ) ;
F_58 ( V_78 ) ;
}
}
F_55 ( V_3 , V_11 ) ;
if ( ! V_252 )
F_147 ( V_3 , V_47 , V_19 ) ;
else
F_104 ( V_3 ) ;
V_98 = F_150 ( V_14 , V_259 , V_47 , V_19 ,
V_252 ? V_260 : V_261 ) ;
F_132 ( V_3 ) ;
-- V_3 -> V_205 ;
if ( ( V_3 -> V_205 & 0x200 ) == 0x200 )
F_151 ( V_3 , V_3 -> V_205 ) ;
V_183 = F_101 ( V_3 ) &&
( V_47 + ( V_19 >> 9 ) ) >= V_3 -> V_185 ;
if ( V_3 -> V_205 == 0 || V_183 ) {
F_104 ( V_3 ) ;
F_87 ( V_3 ) ;
}
return V_98 ;
}
static int F_152 ( struct V_28 * V_26 )
{
struct V_262 * V_263 ;
struct V_264 * V_165 ;
V_165 = & V_26 -> V_116 ;
V_263 = F_153 ( V_26 , V_165 ) ;
if ( ! V_263 )
return - V_104 ;
V_263 -> V_265 = V_26 -> V_266 . V_267 ;
V_263 -> V_268 = 0 ;
V_26 -> V_266 . V_269 = 0 ;
V_26 -> V_266 . V_270 = V_182 ;
return F_154 ( V_26 , V_165 , V_271 , sizeof( * V_263 ) , NULL , 0 ) ;
}
int F_155 ( struct V_95 * V_20 , int V_96 )
{
struct V_2 * V_3 =
F_52 ( V_20 , struct V_2 , V_272 ) ;
struct V_264 * V_165 ;
if ( V_96 )
return 0 ;
V_165 = & F_73 ( V_3 ) -> V_26 -> V_116 ;
if ( ! F_156 ( F_73 ( V_3 ) , V_165 ) )
return - V_104 ;
return F_157 ( F_73 ( V_3 ) , V_165 , V_273 , 0 , NULL , 0 ) ;
}
static void F_158 ( struct V_28 * V_26 , unsigned int V_274 )
{
if ( ! V_26 -> V_266 . V_275 ) {
V_26 -> V_266 . V_275 = true ;
V_26 -> V_266 . V_267 = V_274 ;
V_26 -> V_266 . V_269 = 0 ;
V_26 -> V_266 . V_270 = V_182 ;
}
}
static void F_159 ( struct V_28 * V_26 , unsigned int V_274 )
{
if ( ! V_26 -> V_266 . V_275 )
return;
if ( V_26 -> V_266 . V_267 != V_274 ) {
if ( V_26 -> V_266 . V_269 )
F_152 ( V_26 ) ;
V_26 -> V_266 . V_267 = V_274 ;
}
}
int F_160 ( struct V_95 * V_20 , int V_96 )
{
struct V_57 * V_58 = F_52 ( V_20 , struct V_57 , V_20 ) ;
struct V_2 * V_3 = V_58 -> V_3 ;
struct V_13 * const V_14 = F_73 ( V_3 ) ;
struct V_28 * const V_26 = V_14 -> V_26 ;
int V_98 ;
if ( F_31 ( V_96 ) ) {
F_161 ( V_58 , V_276 ) ;
return 0 ;
}
V_58 -> V_277 = V_182 ;
F_159 ( V_26 , V_58 -> V_274 ) ;
V_98 = F_162 ( V_14 , V_58 ) ;
F_161 ( V_58 , V_278 ) ;
return V_98 ;
}
int F_163 ( struct V_95 * V_20 , int V_96 )
{
struct V_57 * V_58 = F_52 ( V_20 , struct V_57 , V_20 ) ;
struct V_2 * V_3 = V_58 -> V_3 ;
struct V_13 * const V_14 = F_73 ( V_3 ) ;
struct V_28 * V_26 = V_14 -> V_26 ;
int V_98 ;
if ( F_31 ( V_96 ) ) {
F_161 ( V_58 , V_276 ) ;
return 0 ;
}
V_58 -> V_277 = V_182 ;
F_158 ( V_26 , V_58 -> V_274 ) ;
F_159 ( V_26 , V_58 -> V_274 ) ;
V_26 -> V_266 . V_269 ++ ;
V_98 = F_164 ( V_14 , V_58 ) ;
F_161 ( V_58 , V_98 ? V_279 : V_280 ) ;
return V_98 ;
}
int F_165 ( struct V_95 * V_20 , int V_96 )
{
struct V_57 * V_58 = F_52 ( V_20 , struct V_57 , V_20 ) ;
struct V_2 * V_3 = V_58 -> V_3 ;
struct V_13 * const V_14 = F_73 ( V_3 ) ;
struct V_28 * V_26 = V_14 -> V_26 ;
int V_98 ;
if ( F_31 ( V_96 ) ) {
F_161 ( V_58 , V_276 ) ;
return 0 ;
}
V_58 -> V_277 = V_182 ;
F_159 ( V_26 , V_58 -> V_274 ) ;
V_98 = F_98 ( V_14 , V_281 , V_58 -> V_18 . V_47 , V_58 -> V_18 . V_19 ,
( unsigned long ) V_58 ) ;
F_161 ( V_58 , V_98 ? V_279 : V_280 ) ;
return V_98 ;
}
int F_166 ( struct V_95 * V_20 , int V_96 )
{
struct V_57 * V_58 = F_52 ( V_20 , struct V_57 , V_20 ) ;
struct V_2 * V_3 = V_58 -> V_3 ;
if ( F_22 ( V_58 -> V_282 ) == V_49 && V_58 -> V_63 & V_283 )
F_167 ( V_3 , & V_58 -> V_18 ) ;
F_168 ( V_58 , V_58 -> V_282 ) ;
V_58 -> V_75 -> V_284 = V_3 -> V_9 -> V_285 ;
F_169 ( V_58 -> V_75 ) ;
return 0 ;
}
static int F_170 ( struct V_2 * V_3 )
{
struct V_2 * V_286 = V_3 ;
int V_287 ;
while ( 1 ) {
if ( ! V_286 -> V_9 || V_286 -> V_112 . V_213 == V_288 )
return 1 ;
F_83 () ;
V_287 = F_80 ( V_286 -> V_9 -> V_126 ) -> V_287 ;
F_85 () ;
if ( V_287 == - 1 )
return 1 ;
V_286 = F_171 ( V_287 ) ;
if ( ! V_286 )
return 1 ;
if ( ( V_286 -> V_112 . V_113 >= V_224 &&
V_286 -> V_112 . V_113 <= V_208 ) ||
V_286 -> V_112 . V_289 || V_286 -> V_112 . V_290 ||
V_286 -> V_112 . V_291 )
return 0 ;
}
}
static bool F_172 ( struct V_2 * V_3 )
{
bool V_292 = false ;
struct V_2 * V_286 ;
int V_18 ;
F_83 () ;
F_123 (&drbd_devices, odev, i) {
if ( V_286 -> V_112 . V_113 == V_293 && V_286 -> V_112 . V_213 == V_288 )
continue;
if ( ! F_170 ( V_286 ) &&
F_122 ( F_173 ( V_286 , V_289 , 1 ) ,
V_294 , NULL ) != V_295 )
V_292 = true ;
}
F_85 () ;
return V_292 ;
}
static bool F_174 ( struct V_2 * V_3 )
{
bool V_292 = false ;
struct V_2 * V_286 ;
int V_18 ;
F_83 () ;
F_123 (&drbd_devices, odev, i) {
if ( V_286 -> V_112 . V_113 == V_293 && V_286 -> V_112 . V_213 == V_288 )
continue;
if ( V_286 -> V_112 . V_289 ) {
if ( F_170 ( V_286 ) &&
F_122 ( F_173 ( V_286 , V_289 , 0 ) ,
V_294 , NULL ) != V_295 )
V_292 = true ;
}
}
F_85 () ;
return V_292 ;
}
void F_175 ( struct V_2 * V_3 )
{
F_176 () ;
F_174 ( V_3 ) ;
F_177 () ;
}
void F_178 ( struct V_2 * V_3 )
{
F_176 () ;
F_172 ( V_3 ) ;
F_177 () ;
}
enum V_296 F_179 ( struct V_2 * V_3 , int V_297 )
{
struct V_2 * V_286 ;
int V_287 ;
if ( V_297 == - 1 )
return V_298 ;
if ( V_297 < - 1 || V_297 > V_299 )
return V_300 ;
V_286 = F_171 ( V_297 ) ;
while ( 1 ) {
if ( V_286 == V_3 )
return V_301 ;
if ( ! V_286 || ! V_286 -> V_9 || V_286 -> V_112 . V_213 == V_288 )
return V_298 ;
F_83 () ;
V_287 = F_80 ( V_286 -> V_9 -> V_126 ) -> V_287 ;
F_85 () ;
if ( V_287 == - 1 )
return V_298 ;
V_286 = F_171 ( V_287 ) ;
}
}
void F_180 ( struct V_2 * V_3 )
{
int V_292 ;
do {
V_292 = F_172 ( V_3 ) ;
V_292 |= F_174 ( V_3 ) ;
} while ( V_292 );
}
void F_181 ( struct V_2 * V_3 )
{
struct V_302 * V_213 = V_3 -> V_9 -> V_285 -> V_303 -> V_304 ;
struct V_117 * V_135 ;
F_182 ( & V_3 -> V_146 , 0 ) ;
F_182 ( & V_3 -> V_108 , 0 ) ;
V_3 -> V_137 = 0 ;
V_3 -> V_305 =
( int ) F_183 ( & V_213 -> V_306 , V_307 [ 0 ] ) +
( int ) F_183 ( & V_213 -> V_306 , V_307 [ 1 ] ) ;
F_83 () ;
V_135 = F_80 ( V_3 -> V_136 ) ;
V_135 -> V_124 = 0 ;
F_74 ( V_135 , 0 ) ;
F_85 () ;
}
void F_184 ( unsigned long V_116 )
{
struct V_2 * V_3 = (struct V_2 * ) V_116 ;
F_185 ( V_3 , V_308 ) ;
}
static void F_186 ( struct V_2 * V_3 )
{
if ( F_187 ( & V_3 -> V_309 ) || F_187 ( & V_3 -> V_310 ) ) {
F_25 ( V_3 , L_31 ) ;
V_3 -> V_311 . V_312 = V_182 + V_140 / 10 ;
F_188 ( & V_3 -> V_311 ) ;
return;
}
F_189 ( V_3 , V_224 ) ;
F_107 ( V_313 , & V_3 -> V_12 ) ;
}
static bool F_190 ( struct V_28 * V_26 , struct V_2 * V_3 )
{
bool V_314 ;
F_83 () ;
V_314 = F_80 ( V_26 -> V_315 ) -> V_314 ;
F_85 () ;
return V_26 -> V_316 >= 89 &&
V_26 -> V_100 &&
( V_314 == false
|| F_10 ( V_317 , & V_3 -> V_12 ) ) ;
}
void F_189 ( struct V_2 * V_3 , enum V_318 V_319 )
{
struct V_13 * V_14 = F_73 ( V_3 ) ;
struct V_28 * V_26 = V_14 ? V_14 -> V_26 : NULL ;
union V_196 V_198 ;
int V_320 ;
if ( V_3 -> V_112 . V_113 >= V_224 && V_3 -> V_112 . V_113 < V_245 ) {
F_59 ( V_3 , L_32 ) ;
return;
}
if ( ! F_10 ( V_321 , & V_3 -> V_12 ) ) {
if ( V_319 == V_115 ) {
V_320 = F_127 ( V_3 , L_33 ) ;
V_320 = ( V_320 >> 8 ) & 0xff ;
if ( V_320 > 0 ) {
F_114 ( V_3 , L_34
L_35 , V_320 ) ;
F_191 ( V_26 , F_192 ( V_113 , V_322 ) , V_294 ) ;
return;
}
} else {
V_320 = F_127 ( V_3 , L_36 ) ;
V_320 = ( V_320 >> 8 ) & 0xff ;
if ( V_320 > 0 ) {
if ( V_320 == 3 ) {
F_114 ( V_3 , L_37
L_38 , V_320 ) ;
} else {
F_114 ( V_3 , L_37
L_35 , V_320 ) ;
F_191 ( V_26 ,
F_192 ( V_113 , V_322 ) , V_294 ) ;
return;
}
}
}
}
if ( V_323 == V_26 -> V_324 . V_325 ) {
if ( ! F_193 ( V_3 -> V_326 ) ) {
F_26 ( V_321 , & V_3 -> V_12 ) ;
V_3 -> V_311 . V_312 = V_182 + V_140 / 5 ;
F_188 ( & V_3 -> V_311 ) ;
return;
}
} else {
F_89 ( V_3 -> V_326 ) ;
}
F_176 () ;
F_107 ( V_321 , & V_3 -> V_12 ) ;
if ( V_3 -> V_112 . V_113 < V_191
|| ! F_141 ( V_3 , V_327 ) ) {
F_177 () ;
goto V_99;
}
V_198 = F_113 ( V_3 ) ;
V_198 . V_289 = ! F_170 ( V_3 ) ;
V_198 . V_113 = V_319 ;
if ( V_319 == V_115 )
V_198 . V_213 = V_214 ;
else
V_198 . V_215 = V_214 ;
V_320 = F_122 ( V_3 , V_198 , V_223 , NULL ) ;
V_198 = F_113 ( V_3 ) ;
if ( V_198 . V_113 < V_191 )
V_320 = V_328 ;
if ( V_320 == V_329 ) {
unsigned long V_330 = F_115 ( V_3 ) ;
unsigned long V_331 = V_182 ;
int V_18 ;
V_3 -> V_207 = 0 ;
V_3 -> V_203 = 0 ;
V_3 -> V_210 = 0 ;
V_3 -> V_332 = 0 ;
V_3 -> V_158 = V_330 ;
V_3 -> V_202 = V_331 ;
for ( V_18 = 0 ; V_18 < V_333 ; V_18 ++ ) {
V_3 -> V_334 [ V_18 ] = V_330 ;
V_3 -> V_335 [ V_18 ] = V_331 ;
}
F_172 ( V_3 ) ;
F_194 ( & V_3 -> V_336 ) ;
F_195 ( V_3 -> V_337 ) ;
V_3 -> V_338 = 0 ;
V_3 -> V_339 = V_340 ;
F_196 ( & V_3 -> V_336 ) ;
}
F_177 () ;
if ( V_320 == V_329 ) {
F_3 ( & V_3 -> V_341 ) ;
V_3 -> V_342 = V_182 - V_140 ;
F_114 ( V_3 , L_39 ,
F_197 ( V_198 . V_113 ) ,
( unsigned long ) V_3 -> V_158 << ( V_147 - 10 ) ,
( unsigned long ) V_3 -> V_158 ) ;
if ( V_319 == V_115 ) {
V_3 -> V_174 = 0 ;
V_3 -> V_178 = F_190 ( V_26 , V_3 ) ;
} else {
V_3 -> V_178 = false ;
}
if ( V_319 == V_224 && V_26 -> V_316 < 96 )
F_198 ( V_14 ) ;
if ( V_26 -> V_316 < 95 && V_3 -> V_158 == 0 ) {
if ( V_319 == V_224 ) {
struct V_315 * V_343 ;
int V_344 ;
F_83 () ;
V_343 = F_80 ( V_26 -> V_315 ) ;
V_344 = V_343 -> V_345 * V_140 + V_343 -> V_346 * V_140 / 9 ;
F_85 () ;
F_111 ( V_344 ) ;
}
F_87 ( V_3 ) ;
}
F_181 ( V_3 ) ;
if ( V_198 . V_113 == V_115 )
F_100 ( & V_3 -> V_181 , V_182 ) ;
F_126 ( V_3 ) ;
}
F_5 ( V_3 ) ;
V_99:
F_90 ( V_3 -> V_326 ) ;
}
static void F_199 ( struct V_2 * V_3 , bool V_347 )
{
struct V_348 V_349 = { . V_350 = V_351 , } ;
V_3 -> V_342 = V_182 ;
if ( ! F_61 ( V_3 ) )
return;
F_200 ( V_3 , 0 ) ;
if ( V_347 && F_201 ( V_3 -> V_112 . V_113 ) )
F_87 ( V_3 ) ;
F_202 ( V_3 , & V_349 ) ;
V_3 -> V_342 = V_182 ;
F_5 ( V_3 ) ;
}
static void F_203 ( struct V_2 * V_3 )
{
F_204 ( V_3 -> V_337 ) ;
V_3 -> V_337 = NULL ;
F_204 ( V_3 -> V_352 ) ;
V_3 -> V_352 = NULL ;
F_205 ( T_1 ) ;
F_206 ( V_3 , V_3 -> V_9 ) ;
V_3 -> V_9 = NULL ;
F_207 ( T_1 ) ;
F_107 ( V_353 , & V_3 -> V_12 ) ;
F_3 ( & V_3 -> V_8 ) ;
}
static void F_208 ( struct V_2 * V_3 )
{
F_117 ( V_3 , V_3 -> V_112 . V_213 == V_244 ) ;
if ( V_3 -> V_354 && V_3 -> V_9 ) {
if ( F_209 ( V_3 , V_355 ,
L_40 , V_356 ) ) {
if ( F_10 ( V_357 , & V_3 -> V_12 ) ) {
F_210 ( V_3 , V_358 ) ;
F_126 ( V_3 ) ;
}
}
}
F_211 ( V_3 , F_192 ( V_213 , V_288 ) ) ;
}
static int F_212 ( struct V_2 * V_3 )
{
F_25 ( V_3 , L_41 ) ;
F_126 ( V_3 ) ;
return 0 ;
}
void F_213 (
struct V_359 * V_360 ,
unsigned int * V_361 ,
void * V_107 ,
const char * V_362 , const unsigned int line )
{
unsigned int V_18 = * V_361 % V_363 ;
struct V_359 * V_364 = V_360 + V_18 ;
V_364 -> V_365 = V_182 ;
V_364 -> V_366 = V_107 ;
V_364 -> V_367 = V_362 ;
V_364 -> line = line ;
V_364 -> V_361 = * V_361 ;
V_18 = ( V_18 + 1 ) % V_363 ;
V_364 = V_360 + V_18 ;
memset ( V_364 , 0 , sizeof( * V_364 ) ) ;
++ ( * V_361 ) ;
}
static void F_214 ( struct V_2 * V_3 , const unsigned long V_368 )
{
if ( F_10 ( V_369 , & V_368 ) )
F_212 ( V_3 ) ;
if ( F_10 ( V_370 , & V_368 ) ||
F_10 ( V_371 , & V_368 ) )
F_199 ( V_3 , F_10 ( V_370 , & V_368 ) ) ;
if ( F_10 ( V_372 , & V_368 ) )
F_208 ( V_3 ) ;
if ( F_10 ( V_373 , & V_368 ) )
F_203 ( V_3 ) ;
if ( F_10 ( V_308 , & V_368 ) )
F_186 ( V_3 ) ;
}
static unsigned long F_215 ( unsigned long * V_12 )
{
unsigned long V_374 , V_375 ;
do {
V_374 = * V_12 ;
V_375 = V_374 & ~ V_376 ;
} while ( F_216 ( V_12 , V_374 , V_375 ) != V_374 );
return V_374 & V_376 ;
}
static void F_217 ( struct V_28 * V_26 )
{
struct V_13 * V_14 ;
int V_56 ;
F_83 () ;
F_123 (&connection->peer_devices, peer_device, vnr) {
struct V_2 * V_3 = V_14 -> V_3 ;
unsigned long V_368 = F_215 ( & V_3 -> V_12 ) ;
if ( ! V_368 )
continue;
F_16 ( & V_3 -> V_43 ) ;
F_85 () ;
F_214 ( V_3 , V_368 ) ;
F_18 ( & V_3 -> V_43 , V_46 ) ;
F_83 () ;
}
F_85 () ;
}
static bool F_218 ( struct V_377 * V_378 , struct V_379 * V_380 )
{
F_63 ( & V_378 -> V_381 ) ;
F_219 ( & V_378 -> V_382 , V_380 ) ;
F_65 ( & V_378 -> V_381 ) ;
return ! F_9 ( V_380 ) ;
}
static void F_220 ( struct V_28 * V_26 , struct V_379 * V_380 )
{
F_221 ( V_383 ) ;
struct V_315 * V_343 ;
int V_384 , V_385 ;
F_218 ( & V_26 -> V_27 , V_380 ) ;
if ( ! F_9 ( V_380 ) )
return;
F_83 () ;
V_343 = F_80 ( V_26 -> V_315 ) ;
V_384 = V_343 ? V_343 -> V_386 : 0 ;
F_85 () ;
if ( V_384 ) {
F_89 ( & V_26 -> V_116 . V_163 ) ;
if ( V_26 -> V_116 . V_164 )
F_222 ( V_26 -> V_116 . V_164 ) ;
F_90 ( & V_26 -> V_116 . V_163 ) ;
}
for (; ; ) {
int V_387 ;
F_223 ( & V_26 -> V_27 . V_388 , & V_383 , V_389 ) ;
F_63 ( & V_26 -> V_15 -> V_16 ) ;
F_194 ( & V_26 -> V_27 . V_381 ) ;
if ( ! F_9 ( & V_26 -> V_27 . V_382 ) )
F_219 ( & V_26 -> V_27 . V_382 , V_380 ) ;
F_196 ( & V_26 -> V_27 . V_381 ) ;
if ( ! F_9 ( V_380 ) || F_224 ( V_323 ) ) {
F_65 ( & V_26 -> V_15 -> V_16 ) ;
break;
}
V_387 =
F_187 ( & V_26 -> V_390 ) !=
V_26 -> V_266 . V_267 ;
F_65 ( & V_26 -> V_15 -> V_16 ) ;
if ( V_387 )
F_159 ( V_26 ,
V_26 -> V_266 . V_267 + 1 ) ;
if ( F_10 ( V_391 , & V_26 -> V_12 ) )
break;
if ( F_225 ( & V_26 -> V_324 ) != V_392 )
break;
F_226 () ;
}
F_227 ( & V_26 -> V_27 . V_388 , & V_383 ) ;
F_83 () ;
V_343 = F_80 ( V_26 -> V_315 ) ;
V_385 = V_343 ? V_343 -> V_386 : 0 ;
F_85 () ;
F_89 ( & V_26 -> V_116 . V_163 ) ;
if ( V_26 -> V_116 . V_164 ) {
if ( V_385 )
F_228 ( V_26 -> V_116 . V_164 ) ;
else if ( ! V_384 )
F_222 ( V_26 -> V_116 . V_164 ) ;
}
F_90 ( & V_26 -> V_116 . V_163 ) ;
}
int F_229 ( struct V_393 * V_394 )
{
struct V_28 * V_26 = V_394 -> V_26 ;
struct V_95 * V_20 = NULL ;
struct V_13 * V_14 ;
F_230 ( V_380 ) ;
int V_56 ;
while ( F_225 ( V_394 ) == V_392 ) {
F_231 ( V_394 ) ;
if ( F_9 ( & V_380 ) ) {
F_232 ( V_26 , F_220 ) ;
F_220 ( V_26 , & V_380 ) ;
}
if ( F_233 ( V_391 , & V_26 -> V_12 ) ) {
F_232 ( V_26 , F_217 ) ;
F_217 ( V_26 ) ;
}
if ( F_224 ( V_323 ) ) {
F_234 ( V_323 ) ;
if ( F_225 ( V_394 ) == V_392 ) {
F_25 ( V_26 , L_42 ) ;
continue;
}
break;
}
if ( F_225 ( V_394 ) != V_392 )
break;
if ( ! F_9 ( & V_380 ) ) {
V_20 = F_235 ( & V_380 , struct V_95 , V_21 ) ;
F_236 ( & V_20 -> V_21 ) ;
F_232 ( V_26 , V_20 -> V_107 ) ;
if ( V_20 -> V_107 ( V_20 , V_26 -> V_41 < V_42 ) == 0 )
continue;
if ( V_26 -> V_41 >= V_42 )
F_191 ( V_26 , F_192 ( V_113 , V_395 ) , V_294 ) ;
}
}
do {
if ( F_233 ( V_391 , & V_26 -> V_12 ) ) {
F_232 ( V_26 , F_217 ) ;
F_217 ( V_26 ) ;
}
if ( ! F_9 ( & V_380 ) ) {
V_20 = F_235 ( & V_380 , struct V_95 , V_21 ) ;
F_236 ( & V_20 -> V_21 ) ;
F_232 ( V_26 , V_20 -> V_107 ) ;
V_20 -> V_107 ( V_20 , 1 ) ;
} else
F_218 ( & V_26 -> V_27 , & V_380 ) ;
} while ( ! F_9 ( & V_380 ) || F_10 ( V_391 , & V_26 -> V_12 ) );
F_83 () ;
F_123 (&connection->peer_devices, peer_device, vnr) {
struct V_2 * V_3 = V_14 -> V_3 ;
F_117 ( V_3 , V_3 -> V_112 . V_213 == V_288 && V_3 -> V_112 . V_113 == V_293 ) ;
F_16 ( & V_3 -> V_43 ) ;
F_85 () ;
F_237 ( V_3 ) ;
F_18 ( & V_3 -> V_43 , V_46 ) ;
F_83 () ;
}
F_85 () ;
return 0 ;
}
