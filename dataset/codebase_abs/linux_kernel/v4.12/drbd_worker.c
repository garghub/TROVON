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
bool V_50 = F_23 ( V_1 ) == V_51 ||
F_23 ( V_1 ) == V_52 ;
if ( V_1 -> V_6 && F_24 ( & V_53 ) )
F_25 ( V_3 , L_1 ,
V_48 ? ( V_50 ? L_2 : L_3 )
: L_4 , V_1 -> V_6 ,
( unsigned long long ) V_11 -> V_18 . V_47 ) ;
if ( V_1 -> V_6 )
F_26 ( V_24 , & V_11 -> V_12 ) ;
F_4 ( V_1 ) ;
if ( F_27 ( & V_11 -> V_54 ) ) {
if ( V_48 )
F_14 ( V_11 ) ;
else
F_6 ( V_11 ) ;
}
}
void F_28 ( struct V_2 * V_3 )
{
F_29 ( L_5 ,
V_3 -> V_55 , V_3 -> V_15 -> V_56 , V_3 -> V_57 ) ;
}
void F_30 ( struct V_1 * V_1 )
{
unsigned long V_12 ;
struct V_58 * V_59 = V_1 -> V_4 ;
struct V_2 * V_3 = V_59 -> V_3 ;
struct V_60 V_61 ;
enum V_62 V_63 ;
if ( F_31 ( V_59 -> V_64 & V_65 ) ) {
if ( F_24 ( & V_53 ) )
F_32 ( V_3 , L_6 ) ;
if ( ! V_1 -> V_6 )
F_28 ( V_3 ) ;
}
if ( F_31 ( V_1 -> V_6 ) ) {
switch ( F_23 ( V_1 ) ) {
case V_51 :
case V_52 :
if ( V_1 -> V_6 == - V_66 )
V_63 = V_67 ;
else
V_63 = V_68 ;
break;
case V_69 :
if ( V_1 -> V_70 & V_71 )
V_63 = V_72 ;
else
V_63 = V_73 ;
break;
default:
V_63 = V_74 ;
break;
}
} else {
V_63 = V_75 ;
}
F_4 ( V_59 -> V_76 ) ;
V_59 -> V_76 = F_33 ( V_1 -> V_6 ) ;
F_7 ( & V_3 -> V_15 -> V_16 , V_12 ) ;
F_34 ( V_59 , V_63 , & V_61 ) ;
F_12 ( & V_3 -> V_15 -> V_16 , V_12 ) ;
F_5 ( V_3 ) ;
if ( V_61 . V_1 )
F_35 ( V_3 , & V_61 ) ;
}
void F_36 ( struct V_77 * V_78 , struct V_10 * V_11 , void * V_79 )
{
F_37 ( V_59 , V_78 ) ;
struct V_80 V_81 ;
struct V_82 * V_82 = V_11 -> V_83 ;
struct V_82 * V_84 ;
unsigned V_85 ;
F_38 ( V_59 , V_78 ) ;
F_39 ( V_59 , 0 , NULL , NULL ) ;
F_40 ( & V_81 , 1 ) ;
F_41 ( V_59 ) ;
while ( ( V_84 = F_42 ( V_82 ) ) ) {
F_43 ( & V_81 , V_82 , V_86 , 0 ) ;
F_44 ( V_59 , & V_81 , NULL , V_81 . V_87 ) ;
F_45 ( V_59 ) ;
V_82 = V_84 ;
}
V_85 = V_11 -> V_18 . V_19 & ( V_86 - 1 ) ;
F_43 ( & V_81 , V_82 , V_85 ? : V_86 , 0 ) ;
F_44 ( V_59 , & V_81 , V_79 , V_81 . V_87 ) ;
F_46 ( V_59 ) ;
F_47 ( V_59 ) ;
}
void F_48 ( struct V_77 * V_78 , struct V_1 * V_1 , void * V_79 )
{
F_37 ( V_59 , V_78 ) ;
struct V_80 V_81 ;
struct V_88 V_89 ;
struct V_90 V_91 ;
F_38 ( V_59 , V_78 ) ;
F_39 ( V_59 , 0 , NULL , NULL ) ;
F_40 ( & V_81 , 1 ) ;
F_41 ( V_59 ) ;
F_49 (bvec, bio, iter) {
F_43 ( & V_81 , V_89 . V_92 , V_89 . V_93 , V_89 . V_94 ) ;
F_44 ( V_59 , & V_81 , NULL , V_81 . V_87 ) ;
F_45 ( V_59 ) ;
if ( F_23 ( V_1 ) == V_95 )
break;
}
F_44 ( V_59 , NULL , V_79 , 0 ) ;
F_50 ( V_59 ) ;
F_47 ( V_59 ) ;
}
static int F_51 ( struct V_96 * V_20 , int V_97 )
{
struct V_10 * V_11 = F_52 ( V_20 , struct V_10 , V_20 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_98 ;
void * V_79 ;
int V_99 = 0 ;
if ( F_31 ( V_97 ) )
goto V_100;
if ( F_31 ( ( V_11 -> V_12 & V_39 ) != 0 ) )
goto V_100;
V_98 = F_53 ( V_14 -> V_26 -> V_101 ) ;
V_79 = F_54 ( V_98 , V_102 ) ;
if ( V_79 ) {
T_3 V_47 = V_11 -> V_18 . V_47 ;
unsigned int V_19 = V_11 -> V_18 . V_19 ;
F_36 ( V_14 -> V_26 -> V_101 , V_11 , V_79 ) ;
F_55 ( V_3 , V_11 ) ;
V_11 = NULL ;
F_56 ( V_3 ) ;
V_99 = F_57 ( V_14 , V_47 , V_19 ,
V_79 , V_98 ,
V_103 ) ;
F_58 ( V_79 ) ;
} else {
F_59 ( V_3 , L_7 ) ;
V_99 = - V_104 ;
}
V_100:
if ( V_11 )
F_55 ( V_3 , V_11 ) ;
if ( F_31 ( V_99 ) )
F_59 ( V_3 , L_8 ) ;
return V_99 ;
}
static int F_60 ( struct V_13 * V_14 , T_3 V_47 , int V_19 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_10 * V_11 ;
if ( ! F_61 ( V_3 ) )
return - V_105 ;
V_11 = F_62 ( V_14 , V_36 , V_47 ,
V_19 , V_19 , V_106 ) ;
if ( ! V_11 )
goto V_107;
V_11 -> V_20 . V_108 = F_51 ;
F_63 ( & V_3 -> V_15 -> V_16 ) ;
F_64 ( & V_11 -> V_20 . V_21 , & V_3 -> V_22 ) ;
F_65 ( & V_3 -> V_15 -> V_16 ) ;
F_66 ( V_19 >> 9 , & V_3 -> V_109 ) ;
if ( F_67 ( V_3 , V_11 , V_69 , 0 ,
V_110 ) == 0 )
return 0 ;
F_63 ( & V_3 -> V_15 -> V_16 ) ;
F_8 ( & V_11 -> V_20 . V_21 ) ;
F_65 ( & V_3 -> V_15 -> V_16 ) ;
F_55 ( V_3 , V_11 ) ;
V_107:
F_5 ( V_3 ) ;
return - V_111 ;
}
int F_68 ( struct V_96 * V_20 , int V_97 )
{
struct V_2 * V_3 =
F_52 ( V_20 , struct V_2 , V_112 ) ;
switch ( V_3 -> V_113 . V_114 ) {
case V_115 :
F_69 ( V_3 , V_97 ) ;
break;
case V_116 :
F_70 ( V_3 , V_97 ) ;
break;
}
return 0 ;
}
void F_71 ( unsigned long V_117 )
{
struct V_2 * V_3 = (struct V_2 * ) V_117 ;
F_72 (
& F_73 ( V_3 ) -> V_26 -> V_27 ,
& V_3 -> V_112 ) ;
}
static void F_74 ( struct V_118 * V_119 , int V_120 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_119 -> V_19 ; V_18 ++ )
V_119 -> V_121 [ V_18 ] = V_120 ;
}
static int F_75 ( struct V_118 * V_119 , int V_120 )
{
int V_122 ;
V_122 = V_119 -> V_121 [ V_119 -> V_123 ] ;
V_119 -> V_121 [ V_119 -> V_123 ++ ] = V_120 ;
if ( V_119 -> V_123 >= V_119 -> V_19 )
V_119 -> V_123 = 0 ;
return V_122 ;
}
static void F_76 ( struct V_118 * V_119 , int V_120 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_119 -> V_19 ; V_18 ++ )
V_119 -> V_121 [ V_18 ] += V_120 ;
}
struct V_118 * F_77 ( int V_124 )
{
struct V_118 * V_119 ;
V_119 = F_78 ( sizeof( struct V_118 ) + sizeof( int ) * V_124 , V_102 ) ;
if ( ! V_119 )
return NULL ;
V_119 -> V_123 = 0 ;
V_119 -> V_19 = V_124 ;
V_119 -> V_125 = 0 ;
return V_119 ;
}
static int F_79 ( struct V_2 * V_3 , unsigned int V_126 )
{
struct V_127 * V_128 ;
unsigned int V_129 ;
int V_130 ;
int V_131 ;
int V_132 ;
int V_133 ;
int V_134 ;
int V_135 ;
struct V_118 * V_136 ;
V_128 = F_80 ( V_3 -> V_9 -> V_127 ) ;
V_136 = F_80 ( V_3 -> V_137 ) ;
V_133 = V_136 -> V_19 ;
if ( V_3 -> V_138 + V_126 == 0 ) {
V_129 = ( ( V_128 -> V_139 * 2 * V_140 ) / V_141 ) * V_133 ;
} else {
V_129 = V_128 -> V_142 ? V_128 -> V_142 :
V_126 * V_128 -> V_143 * V_141 / ( V_140 * 10 ) ;
}
V_131 = V_129 - V_3 -> V_138 - V_136 -> V_125 ;
V_132 = V_131 / V_133 ;
F_76 ( V_136 , V_132 ) ;
V_136 -> V_125 += V_132 * V_133 ;
V_134 = F_75 ( V_136 , 0 ) ;
V_136 -> V_125 -= V_134 ;
V_130 = V_126 + V_134 ;
if ( V_130 < 0 )
V_130 = 0 ;
V_135 = ( V_128 -> V_144 * 2 * V_140 ) / V_141 ;
if ( V_130 > V_135 )
V_130 = V_135 ;
return V_130 ;
}
static int F_81 ( struct V_2 * V_3 )
{
unsigned int V_126 ;
int V_145 , V_146 ;
V_126 = F_82 ( & V_3 -> V_147 , 0 ) ;
V_3 -> V_138 -= V_126 ;
F_83 () ;
V_146 = F_84 ( V_3 ) / 2 ;
if ( F_80 ( V_3 -> V_137 ) -> V_19 ) {
V_145 = F_79 ( V_3 , V_126 ) >> ( V_148 - 9 ) ;
V_3 -> V_149 = V_145 * V_141 * ( V_150 / 1024 ) / V_140 ;
} else {
V_3 -> V_149 = F_80 ( V_3 -> V_9 -> V_127 ) -> V_139 ;
V_145 = V_140 * V_3 -> V_149 / ( ( V_150 / 1024 ) * V_141 ) ;
}
F_85 () ;
if ( V_146 - V_3 -> V_138 / 8 < V_145 )
V_145 = V_146 - V_3 -> V_138 / 8 ;
return V_145 ;
}
static int F_70 ( struct V_2 * const V_3 , int V_97 )
{
struct V_13 * const V_14 = F_73 ( V_3 ) ;
struct V_28 * const V_26 = V_14 ? V_14 -> V_26 : NULL ;
unsigned long V_151 ;
T_3 V_47 ;
const T_3 V_152 = F_86 ( V_3 -> V_153 ) ;
int V_154 ;
int V_145 , V_155 , V_19 ;
int V_156 , V_157 = 0 ;
int V_18 = 0 ;
int V_158 = 0 ;
if ( F_31 ( V_97 ) )
return 0 ;
if ( V_3 -> V_159 == 0 ) {
F_87 ( V_3 ) ;
return 0 ;
}
if ( ! F_61 ( V_3 ) ) {
F_59 ( V_3 , L_9 ) ;
return 0 ;
}
if ( V_26 -> V_160 & V_161 ) {
F_83 () ;
V_158 = F_80 ( V_3 -> V_9 -> V_127 ) -> V_162 ;
F_85 () ;
}
V_154 = F_88 ( V_3 -> V_163 ) << 9 ;
V_145 = F_81 ( V_3 ) ;
if ( V_145 <= 0 )
goto V_157;
for ( V_18 = 0 ; V_18 < V_145 ; V_18 ++ ) {
F_89 ( & V_26 -> V_117 . V_164 ) ;
if ( V_26 -> V_117 . V_165 ) {
struct V_166 * V_167 = V_26 -> V_117 . V_165 -> V_167 ;
int V_168 = V_167 -> V_169 ;
int V_170 = V_167 -> V_171 ;
if ( V_168 > V_170 / 2 ) {
V_157 = 1 ;
if ( V_167 -> V_172 )
F_26 ( V_173 , & V_167 -> V_172 -> V_12 ) ;
}
} else
V_157 = 1 ;
F_90 ( & V_26 -> V_117 . V_164 ) ;
if ( V_157 )
goto V_157;
V_174:
V_19 = V_150 ;
V_151 = F_91 ( V_3 , V_3 -> V_175 ) ;
if ( V_151 == V_176 ) {
V_3 -> V_175 = F_92 ( V_3 ) ;
F_5 ( V_3 ) ;
return 0 ;
}
V_47 = F_93 ( V_151 ) ;
if ( F_94 ( V_3 , V_47 ) ) {
V_3 -> V_175 = V_151 ;
goto V_157;
}
V_3 -> V_175 = V_151 + 1 ;
if ( F_31 ( F_95 ( V_3 , V_151 ) == 0 ) ) {
F_19 ( V_3 , V_47 ) ;
goto V_174;
}
#if V_177 > V_150
V_156 = 1 ;
V_155 = V_18 ;
while ( V_18 < V_145 ) {
if ( V_19 + V_150 > V_154 )
break;
if ( V_47 & ( ( 1 << ( V_156 + 3 ) ) - 1 ) )
break;
if ( V_158 && V_19 == V_158 )
break;
if ( ( ( V_151 + 1 ) & V_178 ) == 0 )
break;
if ( F_95 ( V_3 , V_151 + 1 ) != 1 )
break;
V_151 ++ ;
V_19 += V_150 ;
if ( ( V_150 << V_156 ) <= V_19 )
V_156 ++ ;
V_18 ++ ;
}
if ( V_19 > V_150 )
V_3 -> V_175 = V_151 + 1 ;
#endif
if ( V_47 + ( V_19 >> 9 ) > V_152 )
V_19 = ( V_152 - V_47 ) << 9 ;
if ( V_3 -> V_179 ) {
switch ( F_60 ( V_14 , V_47 , V_19 ) ) {
case - V_105 :
F_5 ( V_3 ) ;
return - V_105 ;
case - V_111 :
F_19 ( V_3 , V_47 ) ;
V_3 -> V_175 = F_96 ( V_47 ) ;
V_18 = V_155 ;
goto V_157;
case 0 :
break;
default:
F_97 () ;
}
} else {
int V_99 ;
F_56 ( V_3 ) ;
V_99 = F_98 ( V_14 ,
V_19 == V_158 ? V_180 : V_181 ,
V_47 , V_19 , V_36 ) ;
if ( V_99 ) {
F_59 ( V_3 , L_10 ) ;
F_99 ( V_3 ) ;
F_5 ( V_3 ) ;
return V_99 ;
}
}
}
if ( V_3 -> V_175 >= F_92 ( V_3 ) ) {
F_5 ( V_3 ) ;
return 0 ;
}
V_157:
V_3 -> V_138 += ( V_18 << ( V_148 - 9 ) ) ;
F_100 ( & V_3 -> V_182 , V_183 + V_140 ) ;
F_5 ( V_3 ) ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 , int V_97 )
{
int V_145 , V_18 , V_19 ;
T_3 V_47 ;
const T_3 V_152 = F_86 ( V_3 -> V_153 ) ;
bool V_184 = false ;
if ( F_31 ( V_97 ) )
return 1 ;
V_145 = F_81 ( V_3 ) ;
V_47 = V_3 -> V_185 ;
for ( V_18 = 0 ; V_18 < V_145 ; V_18 ++ ) {
if ( V_47 >= V_152 )
return 1 ;
V_184 = V_18 > 0
&& F_101 ( V_3 )
&& V_47 >= V_3 -> V_186 ;
if ( V_184 )
break;
V_19 = V_150 ;
if ( F_94 ( V_3 , V_47 ) ) {
V_3 -> V_185 = V_47 ;
goto V_157;
}
if ( V_47 + ( V_19 >> 9 ) > V_152 )
V_19 = ( V_152 - V_47 ) << 9 ;
F_56 ( V_3 ) ;
if ( F_102 ( F_73 ( V_3 ) , V_47 , V_19 ) ) {
F_99 ( V_3 ) ;
return 0 ;
}
V_47 += V_187 ;
}
V_3 -> V_185 = V_47 ;
V_157:
V_3 -> V_138 += ( V_18 << ( V_148 - 9 ) ) ;
if ( V_18 == 0 || ! V_184 )
F_100 ( & V_3 -> V_182 , V_183 + V_140 ) ;
return 1 ;
}
int F_103 ( struct V_96 * V_20 , int V_97 )
{
struct V_188 * V_189 =
F_52 ( V_20 , struct V_188 , V_20 ) ;
struct V_2 * V_3 = V_189 -> V_3 ;
F_58 ( V_189 ) ;
F_104 ( V_3 ) ;
F_87 ( V_3 ) ;
return 0 ;
}
static int F_105 ( struct V_96 * V_20 , int V_97 )
{
struct V_188 * V_189 =
F_52 ( V_20 , struct V_188 , V_20 ) ;
struct V_2 * V_3 = V_189 -> V_3 ;
F_58 ( V_189 ) ;
F_87 ( V_3 ) ;
return 0 ;
}
static void F_106 ( struct V_2 * V_3 )
{
struct V_28 * V_26 = F_73 ( V_3 ) -> V_26 ;
F_107 ( V_190 , & V_26 -> V_12 ) ;
F_108 ( V_26 ) ;
F_109 ( V_26 -> V_191 ,
F_10 ( V_190 , & V_26 -> V_12 ) || V_3 -> V_113 . V_114 < V_192 ) ;
}
int F_87 ( struct V_2 * V_3 )
{
struct V_28 * V_26 = F_73 ( V_3 ) -> V_26 ;
unsigned long V_193 , V_194 , V_195 ;
unsigned long V_196 ;
union V_197 V_198 , V_199 ;
struct V_188 * V_189 ;
char * V_200 = NULL ;
int V_201 = 0 ;
if ( F_110 ( V_3 ) ) {
F_111 ( V_141 / 10 ) ;
V_189 = F_54 ( sizeof( struct V_188 ) , V_202 ) ;
if ( V_189 ) {
V_189 -> V_20 . V_108 = F_105 ;
V_189 -> V_3 = V_3 ;
F_13 ( & V_26 -> V_27 , & V_189 -> V_20 ) ;
return 1 ;
}
F_59 ( V_3 , L_11 ) ;
}
V_194 = ( V_183 - V_3 -> V_203 - V_3 -> V_204 ) / V_141 ;
if ( V_194 <= 0 )
V_194 = 1 ;
V_193 = V_3 -> V_159 ;
if ( V_3 -> V_113 . V_114 == V_115 || V_3 -> V_113 . V_114 == V_205 )
V_193 -= V_3 -> V_206 ;
V_195 = F_112 ( V_193 / V_194 ) ;
V_3 -> V_204 /= V_141 ;
if ( ! F_61 ( V_3 ) )
goto V_100;
F_106 ( V_3 ) ;
F_63 ( & V_3 -> V_15 -> V_16 ) ;
V_198 = F_113 ( V_3 ) ;
V_201 = ( V_198 . V_114 == V_115 || V_198 . V_114 == V_205 ) ;
if ( V_198 . V_114 <= V_192 )
goto V_207;
V_199 = V_198 ;
V_199 . V_114 = V_192 ;
F_114 ( V_3 , L_12 ,
V_201 ? L_13 : L_14 ,
V_194 + V_3 -> V_204 , V_3 -> V_204 , V_195 ) ;
V_196 = F_115 ( V_3 ) ;
if ( V_198 . V_114 == V_115 || V_198 . V_114 == V_205 ) {
if ( V_196 ) {
F_116 ( V_3 , L_15 ,
V_196 , F_112 ( 1 ) ) ;
V_200 = L_16 ;
}
} else {
F_117 ( V_3 , ( V_196 - V_3 -> V_208 ) == 0 ) ;
if ( V_198 . V_114 == V_116 || V_198 . V_114 == V_209 )
V_200 = L_17 ;
if ( V_3 -> V_179 && V_3 -> V_159 ) {
const unsigned long V_210 = V_3 -> V_211 ;
const unsigned long V_212 = V_3 -> V_159 ;
const int V_213 =
( V_212 == 0 ) ? 0 :
( V_212 < 100000 ) ? ( ( V_210 * 100 ) / V_212 ) : ( V_210 / ( V_212 / 100 ) ) ;
F_114 ( V_3 , L_18
L_19 ,
V_213 ,
F_112 ( V_3 -> V_211 ) ,
F_112 ( V_3 -> V_159 - V_3 -> V_211 ) ,
F_112 ( V_3 -> V_159 ) ) ;
}
}
if ( V_3 -> V_208 ) {
F_114 ( V_3 , L_20 , V_3 -> V_208 ) ;
if ( V_198 . V_114 == V_116 || V_198 . V_114 == V_209 ) {
V_199 . V_214 = V_215 ;
V_199 . V_216 = V_217 ;
} else {
V_199 . V_214 = V_217 ;
V_199 . V_216 = V_215 ;
}
} else {
V_199 . V_214 = V_217 ;
V_199 . V_216 = V_217 ;
if ( V_198 . V_114 == V_116 || V_198 . V_114 == V_209 ) {
if ( V_3 -> V_218 ) {
int V_18 ;
for ( V_18 = V_219 ; V_18 <= V_220 ; V_18 ++ )
F_118 ( V_3 , V_18 , V_3 -> V_218 [ V_18 ] ) ;
F_119 ( V_3 , V_219 , V_3 -> V_9 -> V_221 . V_222 [ V_223 ] ) ;
F_118 ( V_3 , V_223 , V_3 -> V_218 [ V_223 ] ) ;
} else {
F_59 ( V_3 , L_21 ) ;
}
}
if ( ! ( V_198 . V_114 == V_115 || V_198 . V_114 == V_205 ) ) {
F_120 ( V_3 , 0UL ) ;
F_121 ( V_3 , L_22 ) ;
if ( V_3 -> V_218 ) {
int V_18 ;
for ( V_18 = V_223 ; V_18 <= V_220 ; V_18 ++ )
V_3 -> V_218 [ V_18 ] = V_3 -> V_9 -> V_221 . V_222 [ V_18 ] ;
}
}
}
F_122 ( V_3 , V_199 , V_224 , NULL ) ;
V_207:
F_65 ( & V_3 -> V_15 -> V_16 ) ;
if ( V_198 . V_114 == V_225 ) {
enum V_226 V_227 = V_228 ;
enum V_226 V_229 = V_228 ;
enum V_230 V_231 = V_232 ;
F_83 () ;
V_231 = F_80 ( V_3 -> V_9 -> V_127 ) -> V_233 ;
if ( V_231 != V_232 ) {
struct V_13 * V_14 ;
int V_57 ;
F_123 (&connection->peer_devices, peer_device, vnr) {
struct V_2 * V_3 = V_14 -> V_3 ;
V_227 = F_124 ( enum V_226 , V_227 , V_3 -> V_113 . V_214 ) ;
V_229 = F_124 ( enum V_226 , V_229 , V_3 -> V_113 . V_216 ) ;
}
}
F_85 () ;
if ( V_227 == V_217 && V_229 == V_217 )
F_125 ( V_26 , L_23 ) ;
}
F_5 ( V_3 ) ;
V_100:
V_3 -> V_159 = 0 ;
V_3 -> V_208 = 0 ;
V_3 -> V_204 = 0 ;
if ( V_201 && V_3 -> V_206 == 0 )
V_3 -> V_234 = 0 ;
F_126 ( V_3 ) ;
if ( V_200 )
F_127 ( V_3 , V_200 ) ;
return 1 ;
}
static void F_128 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
if ( F_129 ( V_11 ) ) {
int V_18 = ( V_11 -> V_18 . V_19 + V_86 - 1 ) >> V_235 ;
F_66 ( V_18 , & V_3 -> V_236 ) ;
F_130 ( V_18 , & V_3 -> V_237 ) ;
F_63 ( & V_3 -> V_15 -> V_16 ) ;
F_64 ( & V_11 -> V_20 . V_21 , & V_3 -> V_238 ) ;
F_65 ( & V_3 -> V_15 -> V_16 ) ;
F_3 ( & V_239 ) ;
} else
F_55 ( V_3 , V_11 ) ;
}
int F_131 ( struct V_96 * V_20 , int V_97 )
{
struct V_10 * V_11 = F_52 ( V_20 , struct V_10 , V_20 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_99 ;
if ( F_31 ( V_97 ) ) {
F_55 ( V_3 , V_11 ) ;
F_132 ( V_3 ) ;
return 0 ;
}
if ( F_133 ( ( V_11 -> V_12 & V_39 ) == 0 ) ) {
V_99 = F_134 ( V_14 , V_240 , V_11 ) ;
} else {
if ( F_24 ( & V_53 ) )
F_59 ( V_3 , L_24 ,
( unsigned long long ) V_11 -> V_18 . V_47 ) ;
V_99 = F_135 ( V_14 , V_241 , V_11 ) ;
}
F_132 ( V_3 ) ;
F_128 ( V_3 , V_11 ) ;
if ( F_31 ( V_99 ) )
F_59 ( V_3 , L_25 ) ;
return V_99 ;
}
static bool F_136 ( struct V_10 * V_11 )
{
struct V_82 * V_82 = V_11 -> V_83 ;
unsigned int V_85 = V_11 -> V_18 . V_19 ;
F_137 (page) {
unsigned int V_242 = F_124 (unsigned int, len, PAGE_SIZE) ;
unsigned int V_18 , V_243 = V_242 / sizeof( long ) ;
unsigned long * V_244 ;
V_244 = F_138 ( V_82 ) ;
for ( V_18 = 0 ; V_18 < V_243 ; V_18 ++ ) {
if ( V_244 [ V_18 ] ) {
F_139 ( V_244 ) ;
return false ;
}
}
F_139 ( V_244 ) ;
V_85 -= V_242 ;
}
return true ;
}
int F_140 ( struct V_96 * V_20 , int V_97 )
{
struct V_10 * V_11 = F_52 ( V_20 , struct V_10 , V_20 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_99 ;
if ( F_31 ( V_97 ) ) {
F_55 ( V_3 , V_11 ) ;
F_132 ( V_3 ) ;
return 0 ;
}
if ( F_141 ( V_3 , V_245 ) ) {
F_19 ( V_3 , V_11 -> V_18 . V_47 ) ;
F_5 ( V_3 ) ;
}
if ( V_3 -> V_113 . V_114 == V_246 ) {
V_99 = F_135 ( V_14 , V_247 , V_11 ) ;
} else if ( F_133 ( ( V_11 -> V_12 & V_39 ) == 0 ) ) {
if ( F_133 ( V_3 -> V_113 . V_216 >= V_215 ) ) {
F_56 ( V_3 ) ;
if ( V_11 -> V_12 & V_248 && F_136 ( V_11 ) )
V_99 = F_142 ( V_14 , V_11 ) ;
else
V_99 = F_134 ( V_14 , V_249 , V_11 ) ;
} else {
if ( F_24 ( & V_53 ) )
F_59 ( V_3 , L_26
L_27 ) ;
V_99 = 0 ;
}
} else {
if ( F_24 ( & V_53 ) )
F_59 ( V_3 , L_28 ,
( unsigned long long ) V_11 -> V_18 . V_47 ) ;
V_99 = F_135 ( V_14 , V_250 , V_11 ) ;
F_143 ( V_3 , V_11 -> V_18 . V_47 , V_11 -> V_18 . V_19 ) ;
}
F_132 ( V_3 ) ;
F_128 ( V_3 , V_11 ) ;
if ( F_31 ( V_99 ) )
F_59 ( V_3 , L_25 ) ;
return V_99 ;
}
int F_144 ( struct V_96 * V_20 , int V_97 )
{
struct V_10 * V_11 = F_52 ( V_20 , struct V_10 , V_20 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_251 * V_252 ;
int V_98 ;
void * V_79 = NULL ;
int V_99 , V_253 = 0 ;
if ( F_31 ( V_97 ) ) {
F_55 ( V_3 , V_11 ) ;
F_132 ( V_3 ) ;
return 0 ;
}
if ( F_61 ( V_3 ) ) {
F_19 ( V_3 , V_11 -> V_18 . V_47 ) ;
F_5 ( V_3 ) ;
}
V_252 = V_11 -> V_79 ;
if ( F_133 ( ( V_11 -> V_12 & V_39 ) == 0 ) ) {
if ( V_14 -> V_26 -> V_101 ) {
V_98 = F_53 ( V_14 -> V_26 -> V_101 ) ;
F_117 ( V_3 , V_98 == V_252 -> V_98 ) ;
V_79 = F_54 ( V_98 , V_102 ) ;
}
if ( V_79 ) {
F_36 ( V_14 -> V_26 -> V_101 , V_11 , V_79 ) ;
V_253 = ! memcmp ( V_79 , V_252 -> V_79 , V_98 ) ;
F_58 ( V_79 ) ;
}
if ( V_253 ) {
F_145 ( V_3 , V_11 -> V_18 . V_47 , V_11 -> V_18 . V_19 ) ;
V_3 -> V_211 += V_11 -> V_18 . V_19 >> V_148 ;
V_99 = F_135 ( V_14 , V_254 , V_11 ) ;
} else {
F_56 ( V_3 ) ;
V_11 -> V_31 = V_36 ;
V_11 -> V_12 &= ~ V_255 ;
F_58 ( V_252 ) ;
V_99 = F_134 ( V_14 , V_249 , V_11 ) ;
}
} else {
V_99 = F_135 ( V_14 , V_250 , V_11 ) ;
if ( F_24 ( & V_53 ) )
F_59 ( V_3 , L_29 ) ;
}
F_132 ( V_3 ) ;
F_128 ( V_3 , V_11 ) ;
if ( F_31 ( V_99 ) )
F_59 ( V_3 , L_30 ) ;
return V_99 ;
}
int F_146 ( struct V_96 * V_20 , int V_97 )
{
struct V_10 * V_11 = F_52 ( V_20 , struct V_10 , V_20 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
T_3 V_47 = V_11 -> V_18 . V_47 ;
unsigned int V_19 = V_11 -> V_18 . V_19 ;
int V_98 ;
void * V_79 ;
int V_99 = 0 ;
if ( F_31 ( V_97 ) )
goto V_100;
V_98 = F_53 ( V_14 -> V_26 -> V_256 ) ;
V_79 = F_54 ( V_98 , V_102 ) ;
if ( ! V_79 ) {
V_99 = 1 ;
goto V_100;
}
if ( F_133 ( ! ( V_11 -> V_12 & V_39 ) ) )
F_36 ( V_14 -> V_26 -> V_256 , V_11 , V_79 ) ;
else
memset ( V_79 , 0 , V_98 ) ;
F_55 ( V_3 , V_11 ) ;
V_11 = NULL ;
F_56 ( V_3 ) ;
V_99 = F_57 ( V_14 , V_47 , V_19 , V_79 , V_98 , V_257 ) ;
if ( V_99 )
F_99 ( V_3 ) ;
F_58 ( V_79 ) ;
V_100:
if ( V_11 )
F_55 ( V_3 , V_11 ) ;
F_132 ( V_3 ) ;
return V_99 ;
}
void F_147 ( struct V_2 * V_3 , T_3 V_47 , int V_19 )
{
if ( V_3 -> V_258 + V_3 -> V_259 == V_47 ) {
V_3 -> V_259 += V_19 >> 9 ;
} else {
V_3 -> V_258 = V_47 ;
V_3 -> V_259 = V_19 >> 9 ;
}
F_148 ( V_3 , V_47 , V_19 ) ;
}
int F_149 ( struct V_96 * V_20 , int V_97 )
{
struct V_10 * V_11 = F_52 ( V_20 , struct V_10 , V_20 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_251 * V_252 ;
void * V_79 ;
T_3 V_47 = V_11 -> V_18 . V_47 ;
unsigned int V_19 = V_11 -> V_18 . V_19 ;
int V_98 ;
int V_99 , V_253 = 0 ;
bool V_184 = false ;
if ( F_31 ( V_97 ) ) {
F_55 ( V_3 , V_11 ) ;
F_132 ( V_3 ) ;
return 0 ;
}
if ( F_61 ( V_3 ) ) {
F_19 ( V_3 , V_11 -> V_18 . V_47 ) ;
F_5 ( V_3 ) ;
}
V_252 = V_11 -> V_79 ;
if ( F_133 ( ( V_11 -> V_12 & V_39 ) == 0 ) ) {
V_98 = F_53 ( V_14 -> V_26 -> V_256 ) ;
V_79 = F_54 ( V_98 , V_102 ) ;
if ( V_79 ) {
F_36 ( V_14 -> V_26 -> V_256 , V_11 , V_79 ) ;
F_117 ( V_3 , V_98 == V_252 -> V_98 ) ;
V_253 = ! memcmp ( V_79 , V_252 -> V_79 , V_98 ) ;
F_58 ( V_79 ) ;
}
}
F_55 ( V_3 , V_11 ) ;
if ( ! V_253 )
F_147 ( V_3 , V_47 , V_19 ) ;
else
F_104 ( V_3 ) ;
V_99 = F_150 ( V_14 , V_260 , V_47 , V_19 ,
V_253 ? V_261 : V_262 ) ;
F_132 ( V_3 ) ;
-- V_3 -> V_206 ;
if ( ( V_3 -> V_206 & 0x200 ) == 0x200 )
F_151 ( V_3 , V_3 -> V_206 ) ;
V_184 = F_101 ( V_3 ) &&
( V_47 + ( V_19 >> 9 ) ) >= V_3 -> V_186 ;
if ( V_3 -> V_206 == 0 || V_184 ) {
F_104 ( V_3 ) ;
F_87 ( V_3 ) ;
}
return V_99 ;
}
static int F_152 ( struct V_28 * V_26 )
{
struct V_263 * V_264 ;
struct V_265 * V_166 ;
V_166 = & V_26 -> V_117 ;
V_264 = F_153 ( V_26 , V_166 ) ;
if ( ! V_264 )
return - V_105 ;
V_264 -> V_266 = V_26 -> V_267 . V_268 ;
V_264 -> V_269 = 0 ;
V_26 -> V_267 . V_270 = 0 ;
V_26 -> V_267 . V_271 = V_183 ;
return F_154 ( V_26 , V_166 , V_272 , sizeof( * V_264 ) , NULL , 0 ) ;
}
int F_155 ( struct V_96 * V_20 , int V_97 )
{
struct V_2 * V_3 =
F_52 ( V_20 , struct V_2 , V_273 ) ;
struct V_265 * V_166 ;
if ( V_97 )
return 0 ;
V_166 = & F_73 ( V_3 ) -> V_26 -> V_117 ;
if ( ! F_156 ( F_73 ( V_3 ) , V_166 ) )
return - V_105 ;
return F_157 ( F_73 ( V_3 ) , V_166 , V_274 , 0 , NULL , 0 ) ;
}
static void F_158 ( struct V_28 * V_26 , unsigned int V_275 )
{
if ( ! V_26 -> V_267 . V_276 ) {
V_26 -> V_267 . V_276 = true ;
V_26 -> V_267 . V_268 = V_275 ;
V_26 -> V_267 . V_270 = 0 ;
V_26 -> V_267 . V_271 = V_183 ;
}
}
static void F_159 ( struct V_28 * V_26 , unsigned int V_275 )
{
if ( ! V_26 -> V_267 . V_276 )
return;
if ( V_26 -> V_267 . V_268 != V_275 ) {
if ( V_26 -> V_267 . V_270 )
F_152 ( V_26 ) ;
V_26 -> V_267 . V_268 = V_275 ;
}
}
int F_160 ( struct V_96 * V_20 , int V_97 )
{
struct V_58 * V_59 = F_52 ( V_20 , struct V_58 , V_20 ) ;
struct V_2 * V_3 = V_59 -> V_3 ;
struct V_13 * const V_14 = F_73 ( V_3 ) ;
struct V_28 * const V_26 = V_14 -> V_26 ;
int V_99 ;
if ( F_31 ( V_97 ) ) {
F_161 ( V_59 , V_277 ) ;
return 0 ;
}
V_59 -> V_278 = V_183 ;
F_159 ( V_26 , V_59 -> V_275 ) ;
V_99 = F_162 ( V_14 , V_59 ) ;
F_161 ( V_59 , V_279 ) ;
return V_99 ;
}
int F_163 ( struct V_96 * V_20 , int V_97 )
{
struct V_58 * V_59 = F_52 ( V_20 , struct V_58 , V_20 ) ;
struct V_2 * V_3 = V_59 -> V_3 ;
struct V_13 * const V_14 = F_73 ( V_3 ) ;
struct V_28 * V_26 = V_14 -> V_26 ;
int V_99 ;
if ( F_31 ( V_97 ) ) {
F_161 ( V_59 , V_277 ) ;
return 0 ;
}
V_59 -> V_278 = V_183 ;
F_158 ( V_26 , V_59 -> V_275 ) ;
F_159 ( V_26 , V_59 -> V_275 ) ;
V_26 -> V_267 . V_270 ++ ;
V_99 = F_164 ( V_14 , V_59 ) ;
F_161 ( V_59 , V_99 ? V_280 : V_281 ) ;
return V_99 ;
}
int F_165 ( struct V_96 * V_20 , int V_97 )
{
struct V_58 * V_59 = F_52 ( V_20 , struct V_58 , V_20 ) ;
struct V_2 * V_3 = V_59 -> V_3 ;
struct V_13 * const V_14 = F_73 ( V_3 ) ;
struct V_28 * V_26 = V_14 -> V_26 ;
int V_99 ;
if ( F_31 ( V_97 ) ) {
F_161 ( V_59 , V_277 ) ;
return 0 ;
}
V_59 -> V_278 = V_183 ;
F_159 ( V_26 , V_59 -> V_275 ) ;
V_99 = F_98 ( V_14 , V_282 , V_59 -> V_18 . V_47 , V_59 -> V_18 . V_19 ,
( unsigned long ) V_59 ) ;
F_161 ( V_59 , V_99 ? V_280 : V_281 ) ;
return V_99 ;
}
int F_166 ( struct V_96 * V_20 , int V_97 )
{
struct V_58 * V_59 = F_52 ( V_20 , struct V_58 , V_20 ) ;
struct V_2 * V_3 = V_59 -> V_3 ;
if ( F_22 ( V_59 -> V_283 ) == V_49 && V_59 -> V_64 & V_284 )
F_167 ( V_3 , & V_59 -> V_18 ) ;
F_168 ( V_59 , V_59 -> V_283 ) ;
V_59 -> V_76 -> V_285 = V_3 -> V_9 -> V_286 ;
F_169 ( V_59 -> V_76 ) ;
return 0 ;
}
static int F_170 ( struct V_2 * V_3 )
{
struct V_2 * V_287 = V_3 ;
int V_288 ;
while ( 1 ) {
if ( ! V_287 -> V_9 || V_287 -> V_113 . V_214 == V_289 )
return 1 ;
F_83 () ;
V_288 = F_80 ( V_287 -> V_9 -> V_127 ) -> V_288 ;
F_85 () ;
if ( V_288 == - 1 )
return 1 ;
V_287 = F_171 ( V_288 ) ;
if ( ! V_287 )
return 1 ;
if ( ( V_287 -> V_113 . V_114 >= V_225 &&
V_287 -> V_113 . V_114 <= V_209 ) ||
V_287 -> V_113 . V_290 || V_287 -> V_113 . V_291 ||
V_287 -> V_113 . V_292 )
return 0 ;
}
}
static bool F_172 ( struct V_2 * V_3 )
{
bool V_293 = false ;
struct V_2 * V_287 ;
int V_18 ;
F_83 () ;
F_123 (&drbd_devices, odev, i) {
if ( V_287 -> V_113 . V_114 == V_294 && V_287 -> V_113 . V_214 == V_289 )
continue;
if ( ! F_170 ( V_287 ) &&
F_122 ( F_173 ( V_287 , V_290 , 1 ) ,
V_295 , NULL ) != V_296 )
V_293 = true ;
}
F_85 () ;
return V_293 ;
}
static bool F_174 ( struct V_2 * V_3 )
{
bool V_293 = false ;
struct V_2 * V_287 ;
int V_18 ;
F_83 () ;
F_123 (&drbd_devices, odev, i) {
if ( V_287 -> V_113 . V_114 == V_294 && V_287 -> V_113 . V_214 == V_289 )
continue;
if ( V_287 -> V_113 . V_290 ) {
if ( F_170 ( V_287 ) &&
F_122 ( F_173 ( V_287 , V_290 , 0 ) ,
V_295 , NULL ) != V_296 )
V_293 = true ;
}
}
F_85 () ;
return V_293 ;
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
enum V_297 F_179 ( struct V_2 * V_3 , int V_298 )
{
struct V_2 * V_287 ;
int V_288 ;
if ( V_298 == - 1 )
return V_299 ;
if ( V_298 < - 1 || V_298 > V_300 )
return V_301 ;
V_287 = F_171 ( V_298 ) ;
while ( 1 ) {
if ( V_287 == V_3 )
return V_302 ;
if ( ! V_287 || ! V_287 -> V_9 || V_287 -> V_113 . V_214 == V_289 )
return V_299 ;
F_83 () ;
V_288 = F_80 ( V_287 -> V_9 -> V_127 ) -> V_288 ;
F_85 () ;
if ( V_288 == - 1 )
return V_299 ;
V_287 = F_171 ( V_288 ) ;
}
}
void F_180 ( struct V_2 * V_3 )
{
int V_293 ;
do {
V_293 = F_172 ( V_3 ) ;
V_293 |= F_174 ( V_3 ) ;
} while ( V_293 );
}
void F_181 ( struct V_2 * V_3 )
{
struct V_303 * V_214 = V_3 -> V_9 -> V_286 -> V_304 -> V_305 ;
struct V_118 * V_136 ;
F_182 ( & V_3 -> V_147 , 0 ) ;
F_182 ( & V_3 -> V_109 , 0 ) ;
V_3 -> V_138 = 0 ;
V_3 -> V_306 =
( int ) F_183 ( & V_214 -> V_307 , V_308 [ 0 ] ) +
( int ) F_183 ( & V_214 -> V_307 , V_308 [ 1 ] ) ;
F_83 () ;
V_136 = F_80 ( V_3 -> V_137 ) ;
V_136 -> V_125 = 0 ;
F_74 ( V_136 , 0 ) ;
F_85 () ;
}
void F_184 ( unsigned long V_117 )
{
struct V_2 * V_3 = (struct V_2 * ) V_117 ;
F_185 ( V_3 , V_309 ) ;
}
static void F_186 ( struct V_2 * V_3 )
{
if ( F_187 ( & V_3 -> V_310 ) || F_187 ( & V_3 -> V_311 ) ) {
F_25 ( V_3 , L_31 ) ;
V_3 -> V_312 . V_313 = V_183 + V_141 / 10 ;
F_188 ( & V_3 -> V_312 ) ;
return;
}
F_189 ( V_3 , V_225 ) ;
F_107 ( V_314 , & V_3 -> V_12 ) ;
}
static bool F_190 ( struct V_28 * V_26 , struct V_2 * V_3 )
{
bool V_315 ;
F_83 () ;
V_315 = F_80 ( V_26 -> V_316 ) -> V_315 ;
F_85 () ;
return V_26 -> V_317 >= 89 &&
V_26 -> V_101 &&
( V_315 == false
|| F_10 ( V_318 , & V_3 -> V_12 ) ) ;
}
void F_189 ( struct V_2 * V_3 , enum V_319 V_320 )
{
struct V_13 * V_14 = F_73 ( V_3 ) ;
struct V_28 * V_26 = V_14 ? V_14 -> V_26 : NULL ;
union V_197 V_199 ;
int V_321 ;
if ( V_3 -> V_113 . V_114 >= V_225 && V_3 -> V_113 . V_114 < V_246 ) {
F_59 ( V_3 , L_32 ) ;
return;
}
if ( ! F_10 ( V_322 , & V_3 -> V_12 ) ) {
if ( V_320 == V_116 ) {
V_321 = F_127 ( V_3 , L_33 ) ;
V_321 = ( V_321 >> 8 ) & 0xff ;
if ( V_321 > 0 ) {
F_114 ( V_3 , L_34
L_35 , V_321 ) ;
F_191 ( V_26 , F_192 ( V_114 , V_323 ) , V_295 ) ;
return;
}
} else {
V_321 = F_127 ( V_3 , L_36 ) ;
V_321 = ( V_321 >> 8 ) & 0xff ;
if ( V_321 > 0 ) {
if ( V_321 == 3 ) {
F_114 ( V_3 , L_37
L_38 , V_321 ) ;
} else {
F_114 ( V_3 , L_37
L_35 , V_321 ) ;
F_191 ( V_26 ,
F_192 ( V_114 , V_323 ) , V_295 ) ;
return;
}
}
}
}
if ( V_324 == V_26 -> V_325 . V_326 ) {
if ( ! F_193 ( V_3 -> V_327 ) ) {
F_26 ( V_322 , & V_3 -> V_12 ) ;
V_3 -> V_312 . V_313 = V_183 + V_141 / 5 ;
F_188 ( & V_3 -> V_312 ) ;
return;
}
} else {
F_89 ( V_3 -> V_327 ) ;
}
F_176 () ;
F_107 ( V_322 , & V_3 -> V_12 ) ;
if ( V_3 -> V_113 . V_114 < V_192
|| ! F_141 ( V_3 , V_328 ) ) {
F_177 () ;
goto V_100;
}
V_199 = F_113 ( V_3 ) ;
V_199 . V_290 = ! F_170 ( V_3 ) ;
V_199 . V_114 = V_320 ;
if ( V_320 == V_116 )
V_199 . V_214 = V_215 ;
else
V_199 . V_216 = V_215 ;
V_321 = F_122 ( V_3 , V_199 , V_224 , NULL ) ;
V_199 = F_113 ( V_3 ) ;
if ( V_199 . V_114 < V_192 )
V_321 = V_329 ;
if ( V_321 == V_330 ) {
unsigned long V_331 = F_115 ( V_3 ) ;
unsigned long V_332 = V_183 ;
int V_18 ;
V_3 -> V_208 = 0 ;
V_3 -> V_204 = 0 ;
V_3 -> V_211 = 0 ;
V_3 -> V_333 = 0 ;
V_3 -> V_159 = V_331 ;
V_3 -> V_203 = V_332 ;
for ( V_18 = 0 ; V_18 < V_334 ; V_18 ++ ) {
V_3 -> V_335 [ V_18 ] = V_331 ;
V_3 -> V_336 [ V_18 ] = V_332 ;
}
F_172 ( V_3 ) ;
F_194 ( & V_3 -> V_337 ) ;
F_195 ( V_3 -> V_338 ) ;
V_3 -> V_339 = 0 ;
V_3 -> V_340 = V_341 ;
F_196 ( & V_3 -> V_337 ) ;
}
F_177 () ;
if ( V_321 == V_330 ) {
F_3 ( & V_3 -> V_342 ) ;
V_3 -> V_343 = V_183 - V_141 ;
F_114 ( V_3 , L_39 ,
F_197 ( V_199 . V_114 ) ,
( unsigned long ) V_3 -> V_159 << ( V_148 - 10 ) ,
( unsigned long ) V_3 -> V_159 ) ;
if ( V_320 == V_116 ) {
V_3 -> V_175 = 0 ;
V_3 -> V_179 = F_190 ( V_26 , V_3 ) ;
} else {
V_3 -> V_179 = false ;
}
if ( V_320 == V_225 && V_26 -> V_317 < 96 )
F_198 ( V_14 ) ;
if ( V_26 -> V_317 < 95 && V_3 -> V_159 == 0 ) {
if ( V_320 == V_225 ) {
struct V_316 * V_344 ;
int V_345 ;
F_83 () ;
V_344 = F_80 ( V_26 -> V_316 ) ;
V_345 = V_344 -> V_346 * V_141 + V_344 -> V_347 * V_141 / 9 ;
F_85 () ;
F_111 ( V_345 ) ;
}
F_87 ( V_3 ) ;
}
F_181 ( V_3 ) ;
if ( V_199 . V_114 == V_116 )
F_100 ( & V_3 -> V_182 , V_183 ) ;
F_126 ( V_3 ) ;
}
F_5 ( V_3 ) ;
V_100:
F_90 ( V_3 -> V_327 ) ;
}
static void F_199 ( struct V_2 * V_3 , bool V_348 )
{
struct V_349 V_350 = { . V_351 = V_352 , } ;
V_3 -> V_343 = V_183 ;
if ( ! F_61 ( V_3 ) )
return;
F_200 ( V_3 , 0 ) ;
if ( V_348 && F_201 ( V_3 -> V_113 . V_114 ) )
F_87 ( V_3 ) ;
F_202 ( V_3 , & V_350 ) ;
V_3 -> V_343 = V_183 ;
F_5 ( V_3 ) ;
}
static void F_203 ( struct V_2 * V_3 )
{
F_204 ( V_3 -> V_338 ) ;
V_3 -> V_338 = NULL ;
F_204 ( V_3 -> V_353 ) ;
V_3 -> V_353 = NULL ;
F_205 ( T_1 ) ;
F_206 ( V_3 , V_3 -> V_9 ) ;
V_3 -> V_9 = NULL ;
F_207 ( T_1 ) ;
F_107 ( V_354 , & V_3 -> V_12 ) ;
F_3 ( & V_3 -> V_8 ) ;
}
static void F_208 ( struct V_2 * V_3 )
{
F_117 ( V_3 , V_3 -> V_113 . V_214 == V_245 ) ;
if ( V_3 -> V_355 && V_3 -> V_9 ) {
if ( F_209 ( V_3 , V_356 ,
L_40 , V_357 ) ) {
if ( F_10 ( V_358 , & V_3 -> V_12 ) ) {
F_210 ( V_3 , V_359 ) ;
F_126 ( V_3 ) ;
}
}
}
F_211 ( V_3 , F_192 ( V_214 , V_289 ) ) ;
}
static int F_212 ( struct V_2 * V_3 )
{
F_25 ( V_3 , L_41 ) ;
F_126 ( V_3 ) ;
return 0 ;
}
void F_213 (
struct V_360 * V_361 ,
unsigned int * V_362 ,
void * V_108 ,
const char * V_363 , const unsigned int line )
{
unsigned int V_18 = * V_362 % V_364 ;
struct V_360 * V_365 = V_361 + V_18 ;
V_365 -> V_366 = V_183 ;
V_365 -> V_367 = V_108 ;
V_365 -> V_368 = V_363 ;
V_365 -> line = line ;
V_365 -> V_362 = * V_362 ;
V_18 = ( V_18 + 1 ) % V_364 ;
V_365 = V_361 + V_18 ;
memset ( V_365 , 0 , sizeof( * V_365 ) ) ;
++ ( * V_362 ) ;
}
static void F_214 ( struct V_2 * V_3 , const unsigned long V_369 )
{
if ( F_10 ( V_370 , & V_369 ) )
F_212 ( V_3 ) ;
if ( F_10 ( V_371 , & V_369 ) ||
F_10 ( V_372 , & V_369 ) )
F_199 ( V_3 , F_10 ( V_371 , & V_369 ) ) ;
if ( F_10 ( V_373 , & V_369 ) )
F_208 ( V_3 ) ;
if ( F_10 ( V_374 , & V_369 ) )
F_203 ( V_3 ) ;
if ( F_10 ( V_309 , & V_369 ) )
F_186 ( V_3 ) ;
}
static unsigned long F_215 ( unsigned long * V_12 )
{
unsigned long V_375 , V_376 ;
do {
V_375 = * V_12 ;
V_376 = V_375 & ~ V_377 ;
} while ( F_216 ( V_12 , V_375 , V_376 ) != V_375 );
return V_375 & V_377 ;
}
static void F_217 ( struct V_28 * V_26 )
{
struct V_13 * V_14 ;
int V_57 ;
F_83 () ;
F_123 (&connection->peer_devices, peer_device, vnr) {
struct V_2 * V_3 = V_14 -> V_3 ;
unsigned long V_369 = F_215 ( & V_3 -> V_12 ) ;
if ( ! V_369 )
continue;
F_16 ( & V_3 -> V_43 ) ;
F_85 () ;
F_214 ( V_3 , V_369 ) ;
F_18 ( & V_3 -> V_43 , V_46 ) ;
F_83 () ;
}
F_85 () ;
}
static bool F_218 ( struct V_378 * V_379 , struct V_380 * V_381 )
{
F_63 ( & V_379 -> V_382 ) ;
F_219 ( & V_379 -> V_383 , V_381 ) ;
F_65 ( & V_379 -> V_382 ) ;
return ! F_9 ( V_381 ) ;
}
static void F_220 ( struct V_28 * V_26 , struct V_380 * V_381 )
{
F_221 ( V_384 ) ;
struct V_316 * V_344 ;
int V_385 , V_386 ;
F_218 ( & V_26 -> V_27 , V_381 ) ;
if ( ! F_9 ( V_381 ) )
return;
F_83 () ;
V_344 = F_80 ( V_26 -> V_316 ) ;
V_385 = V_344 ? V_344 -> V_387 : 0 ;
F_85 () ;
if ( V_385 ) {
F_89 ( & V_26 -> V_117 . V_164 ) ;
if ( V_26 -> V_117 . V_165 )
F_222 ( V_26 -> V_117 . V_165 ) ;
F_90 ( & V_26 -> V_117 . V_164 ) ;
}
for (; ; ) {
int V_388 ;
F_223 ( & V_26 -> V_27 . V_389 , & V_384 , V_390 ) ;
F_63 ( & V_26 -> V_15 -> V_16 ) ;
F_194 ( & V_26 -> V_27 . V_382 ) ;
if ( ! F_9 ( & V_26 -> V_27 . V_383 ) )
F_219 ( & V_26 -> V_27 . V_383 , V_381 ) ;
F_196 ( & V_26 -> V_27 . V_382 ) ;
if ( ! F_9 ( V_381 ) || F_224 ( V_324 ) ) {
F_65 ( & V_26 -> V_15 -> V_16 ) ;
break;
}
V_388 =
F_187 ( & V_26 -> V_391 ) !=
V_26 -> V_267 . V_268 ;
F_65 ( & V_26 -> V_15 -> V_16 ) ;
if ( V_388 )
F_159 ( V_26 ,
V_26 -> V_267 . V_268 + 1 ) ;
if ( F_10 ( V_392 , & V_26 -> V_12 ) )
break;
if ( F_225 ( & V_26 -> V_325 ) != V_393 )
break;
F_226 () ;
}
F_227 ( & V_26 -> V_27 . V_389 , & V_384 ) ;
F_83 () ;
V_344 = F_80 ( V_26 -> V_316 ) ;
V_386 = V_344 ? V_344 -> V_387 : 0 ;
F_85 () ;
F_89 ( & V_26 -> V_117 . V_164 ) ;
if ( V_26 -> V_117 . V_165 ) {
if ( V_386 )
F_228 ( V_26 -> V_117 . V_165 ) ;
else if ( ! V_385 )
F_222 ( V_26 -> V_117 . V_165 ) ;
}
F_90 ( & V_26 -> V_117 . V_164 ) ;
}
int F_229 ( struct V_394 * V_395 )
{
struct V_28 * V_26 = V_395 -> V_26 ;
struct V_96 * V_20 = NULL ;
struct V_13 * V_14 ;
F_230 ( V_381 ) ;
int V_57 ;
while ( F_225 ( V_395 ) == V_393 ) {
F_231 ( V_395 ) ;
if ( F_9 ( & V_381 ) ) {
F_232 ( V_26 , F_220 ) ;
F_220 ( V_26 , & V_381 ) ;
}
if ( F_233 ( V_392 , & V_26 -> V_12 ) ) {
F_232 ( V_26 , F_217 ) ;
F_217 ( V_26 ) ;
}
if ( F_224 ( V_324 ) ) {
F_234 ( V_324 ) ;
if ( F_225 ( V_395 ) == V_393 ) {
F_25 ( V_26 , L_42 ) ;
continue;
}
break;
}
if ( F_225 ( V_395 ) != V_393 )
break;
if ( ! F_9 ( & V_381 ) ) {
V_20 = F_235 ( & V_381 , struct V_96 , V_21 ) ;
F_236 ( & V_20 -> V_21 ) ;
F_232 ( V_26 , V_20 -> V_108 ) ;
if ( V_20 -> V_108 ( V_20 , V_26 -> V_41 < V_42 ) == 0 )
continue;
if ( V_26 -> V_41 >= V_42 )
F_191 ( V_26 , F_192 ( V_114 , V_396 ) , V_295 ) ;
}
}
do {
if ( F_233 ( V_392 , & V_26 -> V_12 ) ) {
F_232 ( V_26 , F_217 ) ;
F_217 ( V_26 ) ;
}
if ( ! F_9 ( & V_381 ) ) {
V_20 = F_235 ( & V_381 , struct V_96 , V_21 ) ;
F_236 ( & V_20 -> V_21 ) ;
F_232 ( V_26 , V_20 -> V_108 ) ;
V_20 -> V_108 ( V_20 , 1 ) ;
} else
F_218 ( & V_26 -> V_27 , & V_381 ) ;
} while ( ! F_9 ( & V_381 ) || F_10 ( V_392 , & V_26 -> V_12 ) );
F_83 () ;
F_123 (&connection->peer_devices, peer_device, vnr) {
struct V_2 * V_3 = V_14 -> V_3 ;
F_117 ( V_3 , V_3 -> V_113 . V_214 == V_289 && V_3 -> V_113 . V_114 == V_294 ) ;
F_16 ( & V_3 -> V_43 ) ;
F_85 () ;
F_237 ( V_3 ) ;
F_18 ( & V_3 -> V_43 , V_46 ) ;
F_83 () ;
}
F_85 () ;
return 0 ;
}
