static inline void F_1 ( struct V_1 * V_2 ,
void T_1 * V_3 ,
T_2 V_4 )
{
#ifdef F_2
F_3 ( F_4 ( V_4 ) & V_5 ,
V_3 + V_6 ) ;
#endif
F_3 ( F_5 ( V_4 ) , V_3 + V_7 ) ;
}
static inline void F_6 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
unsigned int V_10 )
{
F_7 ( V_2 , V_9 -> V_11 , F_8 ( V_10 ) ) ;
F_7 ( V_2 , V_9 -> V_12 , F_9 ( V_10 ) ) ;
}
static int F_10 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
if ( ! F_12 ( V_14 ) )
return - V_17 ;
return F_13 ( V_2 -> V_18 , V_16 ) ;
}
static int F_14 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
if ( ! F_12 ( V_14 ) )
return - V_17 ;
return F_15 ( V_2 -> V_18 , V_16 ) ;
}
static int F_16 ( struct V_13 * V_14 ,
T_3 V_19 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
T_4 V_20 ;
V_2 -> V_21 = ! ! ( V_19 & V_22 ) ;
V_20 = F_17 ( V_2 , V_23 ) ;
if ( V_2 -> V_21 )
V_20 |= V_24 ;
else
V_20 &= ~ V_24 ;
if ( V_2 -> V_21 && V_2 -> V_25 )
V_20 |= V_26 ;
else
V_20 &= ~ V_26 ;
if ( F_18 ( V_14 ) )
V_20 |= V_27 ;
else
V_20 &= ~ V_27 ;
F_19 ( V_2 , V_20 , V_23 ) ;
return 0 ;
}
static int F_20 ( struct V_13 * V_14 ,
T_3 V_19 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
T_4 V_20 ;
V_2 -> V_28 = ! ! ( V_19 & ( V_29 | V_30 ) ) ;
V_20 = F_21 ( V_2 , V_31 ) ;
if ( V_2 -> V_28 )
V_20 |= V_32 ;
else
V_20 &= ~ V_32 ;
F_7 ( V_2 , V_20 , V_31 ) ;
return 0 ;
}
static int F_22 ( struct V_13 * V_14 ,
T_3 V_33 )
{
T_3 V_34 = V_33 ^ V_14 -> V_33 ;
T_3 V_19 = V_14 -> V_35 ;
int V_36 = 0 ;
if ( V_34 & V_22 )
V_36 = F_16 ( V_14 , V_19 ) ;
if ( V_34 & ( V_29 | V_30 ) )
V_36 = F_20 ( V_14 , V_19 ) ;
return V_36 ;
}
static void F_23 ( struct V_13 * V_14 ,
struct V_37 * V_38 )
{
F_24 ( V_38 -> V_39 , V_40 , sizeof( V_38 -> V_39 ) ) ;
F_24 ( V_38 -> V_41 , L_1 , sizeof( V_38 -> V_41 ) ) ;
F_24 ( V_38 -> V_42 , L_2 , sizeof( V_38 -> V_42 ) ) ;
V_38 -> V_43 = V_44 ;
}
static T_4 F_25 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
return V_2 -> V_45 ;
}
static void F_26 ( struct V_13 * V_14 , T_4 V_46 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
V_2 -> V_45 = V_46 ;
}
static int F_27 ( struct V_13 * V_14 , int V_47 )
{
switch ( V_47 ) {
case V_48 :
return V_44 ;
default:
return - V_49 ;
}
}
static void F_28 ( struct V_13 * V_14 ,
T_4 V_50 , T_5 * V_51 )
{
int V_52 ;
switch ( V_50 ) {
case V_48 :
for ( V_52 = 0 ; V_52 < V_44 ; V_52 ++ ) {
memcpy ( V_51 + V_52 * V_53 ,
V_54 [ V_52 ] . V_55 ,
V_53 ) ;
}
break;
default:
break;
}
}
static void F_29 ( struct V_1 * V_2 )
{
int V_52 , V_56 = 0 ;
for ( V_52 = 0 ; V_52 < V_44 ; V_52 ++ ) {
const struct V_57 * V_58 ;
T_5 V_59 = 0 ;
T_4 V_60 = 0 ;
char * V_61 ;
V_58 = & V_54 [ V_52 ] ;
switch ( V_58 -> type ) {
case V_62 :
case V_63 :
continue;
case V_64 :
case V_65 :
case V_66 :
if ( V_58 -> type != V_64 )
V_59 = V_67 ;
V_60 = F_30 ( V_2 , V_68 + V_56 + V_59 ) ;
break;
case V_69 :
V_60 = F_17 ( V_2 , V_58 -> V_70 ) ;
if ( V_60 == ~ 0 )
F_19 ( V_2 , 0 , V_58 -> V_70 ) ;
break;
case V_71 :
V_60 = F_31 ( V_2 , V_58 -> V_70 ) ;
if ( V_60 == ~ 0 )
F_32 ( V_2 , 0 , V_58 -> V_70 ) ;
break;
}
V_56 += V_58 -> V_72 ;
V_61 = ( char * ) V_2 + V_58 -> V_73 ;
* ( T_4 * ) V_61 = V_60 ;
}
F_33 ( V_2 , V_74 , V_2 -> V_75 , L_3 ) ;
}
static void F_34 ( struct V_13 * V_14 ,
struct V_76 * V_77 , T_6 * V_51 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
int V_52 ;
if ( F_12 ( V_14 ) )
F_29 ( V_2 ) ;
for ( V_52 = 0 ; V_52 < V_44 ; V_52 ++ ) {
const struct V_57 * V_58 ;
char * V_61 ;
V_58 = & V_54 [ V_52 ] ;
if ( V_58 -> type == V_62 )
V_61 = ( char * ) & V_14 -> V_77 ;
else
V_61 = ( char * ) V_2 ;
V_61 += V_58 -> V_73 ;
V_51 [ V_52 ] = * ( T_4 * ) V_61 ;
}
}
static void F_35 ( struct V_13 * V_14 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
T_4 V_20 ;
V_79 -> V_80 = V_81 | V_82 ;
V_79 -> V_83 = V_2 -> V_83 ;
if ( ! ( V_2 -> V_83 & V_82 ) )
return;
V_20 = F_30 ( V_2 , V_84 ) ;
F_36 ( V_20 , & V_79 -> V_85 [ 0 ] ) ;
V_20 = F_30 ( V_2 , V_86 ) ;
F_37 ( V_20 , & V_79 -> V_85 [ 2 ] ) ;
}
static int F_38 ( struct V_13 * V_14 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
struct V_87 * V_88 = & V_2 -> V_89 -> V_14 ;
T_4 V_80 = V_81 | V_82 ;
if ( ! F_39 ( V_88 ) )
return - V_90 ;
if ( V_79 -> V_83 & ~ V_80 )
return - V_17 ;
if ( V_79 -> V_83 & V_82 ) {
F_40 ( V_2 , F_41 ( & V_79 -> V_85 [ 0 ] ) ,
V_84 ) ;
F_40 ( V_2 , F_42 ( & V_79 -> V_85 [ 2 ] ) ,
V_86 ) ;
}
if ( V_79 -> V_83 ) {
F_43 ( V_88 , 1 ) ;
if ( V_2 -> V_91 )
F_44 ( V_2 -> V_92 ) ;
V_2 -> V_91 = 0 ;
} else {
F_43 ( V_88 , 0 ) ;
if ( ! V_2 -> V_91 )
F_45 ( V_2 -> V_92 ) ;
V_2 -> V_91 = 1 ;
}
V_2 -> V_83 = V_79 -> V_83 ;
return 0 ;
}
static void F_46 ( struct V_93 * V_94 )
{
F_47 ( V_94 -> V_95 ) ;
V_94 -> V_95 = NULL ;
F_48 ( V_94 , V_96 , 0 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
struct V_87 * V_88 = & V_2 -> V_89 -> V_14 ;
struct V_13 * V_97 = V_2 -> V_75 ;
T_2 V_98 ;
int V_36 ;
V_94 -> V_95 = F_50 ( V_2 -> V_75 , V_99 ) ;
if ( ! V_94 -> V_95 ) {
F_51 ( V_2 , V_100 , V_97 , L_4 ) ;
return - V_101 ;
}
V_98 = F_52 ( V_88 , V_94 -> V_95 -> V_51 ,
V_99 , V_102 ) ;
V_36 = F_53 ( V_88 , V_98 ) ;
if ( V_36 ) {
V_2 -> V_103 . V_104 ++ ;
F_46 ( V_94 ) ;
F_51 ( V_2 , V_100 , V_97 , L_5 ) ;
return V_36 ;
}
F_48 ( V_94 , V_96 , V_98 ) ;
F_1 ( V_2 , V_2 -> V_105 , V_98 ) ;
V_2 -> V_106 ++ ;
V_2 -> V_106 &= ( V_2 -> V_107 - 1 ) ;
V_2 -> V_105 = V_2 -> V_108 +
( V_2 -> V_106 * V_109 ) ;
F_33 ( V_2 , V_110 , V_97 , L_6 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_93 * V_94 ;
int V_36 = 0 ;
unsigned int V_52 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_107 ; V_52 ++ ) {
V_94 = & V_2 -> V_111 [ V_2 -> V_106 ] ;
if ( V_94 -> V_95 )
continue;
V_36 = F_49 ( V_2 , V_94 ) ;
if ( V_36 )
break;
}
return V_36 ;
}
static unsigned int F_55 ( struct V_1 * V_2 ,
unsigned int V_112 )
{
struct V_87 * V_88 = & V_2 -> V_89 -> V_14 ;
struct V_13 * V_97 = V_2 -> V_75 ;
unsigned int V_113 = 0 , V_114 ;
struct V_93 * V_94 ;
struct V_115 * V_95 ;
unsigned int V_116 ;
T_7 V_117 , V_118 ;
struct V_119 * V_120 ;
int V_36 ;
V_116 = F_56 ( V_2 , V_121 ) ;
V_116 &= V_122 ;
if ( V_116 < V_2 -> V_123 )
V_114 = ( V_124 + 1 ) -
V_2 -> V_123 + V_116 ;
else
V_114 = V_116 - V_2 -> V_123 ;
F_33 ( V_2 , V_110 , V_97 ,
L_7 ,
V_116 , V_2 -> V_123 , V_114 ) ;
while ( ( V_113 < V_114 ) && ( V_113 < V_112 ) ) {
V_94 = & V_2 -> V_111 [ V_2 -> V_125 ] ;
V_95 = V_94 -> V_95 ;
V_113 ++ ;
V_2 -> V_125 ++ ;
if ( V_2 -> V_125 == V_2 -> V_107 )
V_2 -> V_125 = 0 ;
if ( F_57 ( ! V_95 ) ) {
F_51 ( V_2 , V_100 , V_97 , L_8 ) ;
V_97 -> V_77 . V_126 ++ ;
V_97 -> V_77 . V_127 ++ ;
goto V_128;
}
F_58 ( V_88 , F_59 ( V_94 , V_96 ) ,
V_99 , V_102 ) ;
V_120 = (struct V_119 * ) V_95 -> V_51 ;
V_117 = ( V_120 -> V_129 >> V_130 ) & V_131 ;
V_118 = ( V_120 -> V_129 >> V_132 ) &
V_133 ;
F_33 ( V_2 , V_110 , V_97 ,
L_9 ,
V_116 , V_2 -> V_123 , V_2 -> V_125 ,
V_117 , V_118 ) ;
if ( F_57 ( ! ( V_118 & V_134 ) || ! ( V_118 & V_135 ) ) ) {
F_51 ( V_2 , V_110 , V_97 , L_10 ) ;
V_97 -> V_77 . V_126 ++ ;
V_97 -> V_77 . V_127 ++ ;
F_46 ( V_94 ) ;
goto V_128;
}
if ( F_57 ( V_118 & ( V_136 | V_137 ) ) ) {
F_51 ( V_2 , V_100 , V_97 , L_11 ) ;
if ( V_118 & V_137 )
V_97 -> V_77 . V_138 ++ ;
V_97 -> V_77 . V_126 ++ ;
V_97 -> V_77 . V_127 ++ ;
F_46 ( V_94 ) ;
goto V_128;
}
F_60 ( V_95 , V_117 ) ;
if ( F_61 ( V_118 & V_139 ) )
V_95 -> V_140 = V_141 ;
F_62 ( V_95 , sizeof( * V_120 ) + 2 ) ;
V_117 -= ( sizeof( * V_120 ) + 2 ) ;
if ( V_2 -> V_25 ) {
F_63 ( V_95 , V_117 - V_142 ) ;
V_117 -= V_142 ;
}
V_95 -> V_143 = F_64 ( V_95 , V_97 ) ;
V_97 -> V_77 . V_144 ++ ;
V_97 -> V_77 . V_145 += V_117 ;
F_65 ( & V_2 -> V_146 , V_95 ) ;
V_128:
V_36 = F_49 ( V_2 , V_94 ) ;
if ( V_36 )
V_2 -> V_103 . V_147 ++ ;
}
return V_113 ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
unsigned int * V_148 ,
unsigned int * V_149 )
{
struct V_87 * V_88 = & V_2 -> V_89 -> V_14 ;
struct V_13 * V_97 = V_2 -> V_75 ;
if ( V_94 -> V_95 ) {
V_97 -> V_77 . V_150 += V_94 -> V_95 -> V_117 ;
* V_148 += V_94 -> V_95 -> V_117 ;
F_58 ( V_88 , F_59 ( V_94 , V_96 ) ,
F_67 ( V_94 , V_151 ) ,
V_152 ) ;
V_97 -> V_77 . V_153 ++ ;
( * V_149 ) ++ ;
F_46 ( V_94 ) ;
} else if ( F_59 ( V_94 , V_96 ) ) {
V_97 -> V_77 . V_150 += F_67 ( V_94 , V_151 ) ;
F_68 ( V_88 , F_59 ( V_94 , V_96 ) ,
F_67 ( V_94 , V_151 ) , V_152 ) ;
F_48 ( V_94 , V_96 , 0 ) ;
}
}
static unsigned int F_69 ( struct V_1 * V_2 ,
struct V_154 * V_155 )
{
struct V_13 * V_97 = V_2 -> V_75 ;
unsigned int V_156 , V_157 , V_158 , V_159 ;
unsigned int V_149 = 0 , V_148 = 0 ;
struct V_93 * V_94 ;
struct V_160 * V_161 ;
T_4 V_162 ;
V_161 = F_70 ( V_97 , V_155 -> V_163 ) ;
V_162 = F_21 ( V_2 , F_71 ( V_155 -> V_163 ) ) ;
V_156 = ( V_162 >> V_164 ) & V_165 ;
V_155 -> V_116 = ( V_162 & V_166 ) ;
V_157 = V_155 -> V_156 ;
V_159 = V_155 -> V_167 ;
V_156 &= ( V_159 - 1 ) ;
if ( V_156 >= V_157 )
V_158 = V_156 - V_157 ;
else
V_158 = V_159 - V_157 + V_156 ;
F_33 ( V_2 , V_168 , V_97 ,
L_12 ,
V_155 -> V_163 , V_156 , V_158 , V_157 ) ;
while ( V_158 -- > 0 ) {
V_94 = V_155 -> V_169 + V_157 ;
F_66 ( V_2 , V_94 , & V_148 , & V_149 ) ;
V_155 -> V_170 ++ ;
V_157 ++ ;
V_157 &= ( V_159 - 1 ) ;
}
V_155 -> V_156 = V_156 ;
if ( F_72 ( V_161 ) && V_149 )
F_73 ( V_161 ) ;
F_33 ( V_2 , V_168 , V_97 ,
L_13 ,
V_155 -> V_163 , V_155 -> V_156 , V_149 , V_148 ) ;
return V_149 ;
}
static unsigned int F_74 ( struct V_1 * V_2 ,
struct V_154 * V_155 )
{
unsigned int V_171 ;
unsigned long V_172 ;
F_75 ( & V_155 -> V_173 , V_172 ) ;
V_171 = F_69 ( V_2 , V_155 ) ;
F_76 ( & V_155 -> V_173 , V_172 ) ;
return V_171 ;
}
static int F_77 ( struct V_174 * V_146 , int V_112 )
{
struct V_154 * V_155 =
F_78 ( V_146 , struct V_154 , V_146 ) ;
unsigned int V_175 = 0 ;
V_175 = F_74 ( V_155 -> V_2 , V_155 ) ;
if ( V_175 == 0 ) {
F_79 ( V_146 ) ;
F_80 ( V_155 -> V_2 , F_81 ( V_155 -> V_163 ) ) ;
return 0 ;
}
return V_112 ;
}
static void F_82 ( struct V_1 * V_2 )
{
unsigned int V_176 ;
for ( V_176 = 0 ; V_176 < V_2 -> V_75 -> V_177 ; V_176 ++ )
F_74 ( V_2 , & V_2 -> V_178 [ V_176 ] ) ;
}
static int F_83 ( struct V_174 * V_146 , int V_112 )
{
struct V_1 * V_2 =
F_78 ( V_146 , struct V_1 , V_146 ) ;
unsigned int V_175 = 0 ;
V_175 = F_55 ( V_2 , V_112 ) ;
V_2 -> V_123 += V_175 ;
V_2 -> V_123 &= V_124 ;
F_84 ( V_2 , V_2 -> V_123 , V_179 ) ;
if ( V_175 < V_112 ) {
F_79 ( V_146 ) ;
F_85 ( V_2 , V_180 ) ;
}
return V_175 ;
}
static void F_86 ( struct V_1 * V_2 )
{
T_4 V_20 ;
F_87 ( V_2 , V_181 ) ;
V_20 = F_30 ( V_2 , V_182 ) ;
V_20 &= ~ V_183 ;
F_40 ( V_2 , V_20 , V_182 ) ;
F_33 ( V_2 , V_79 , V_2 -> V_75 , L_14 ) ;
}
static T_8 F_88 ( int V_184 , void * V_185 )
{
struct V_13 * V_14 = V_185 ;
struct V_1 * V_2 = F_11 ( V_14 ) ;
V_2 -> V_186 = F_89 ( V_2 , V_187 ) &
~ F_89 ( V_2 , V_188 ) ;
F_90 ( V_2 , V_2 -> V_186 , V_189 ) ;
if ( F_57 ( V_2 -> V_186 == 0 ) ) {
F_91 ( V_2 -> V_75 , L_15 ) ;
return V_190 ;
}
if ( V_2 -> V_186 & V_180 ) {
if ( F_61 ( F_92 ( & V_2 -> V_146 ) ) ) {
F_87 ( V_2 , V_180 ) ;
F_93 ( & V_2 -> V_146 ) ;
}
}
if ( V_2 -> V_186 & V_191 )
F_82 ( V_2 ) ;
if ( V_2 -> V_186 & V_181 ) {
F_94 ( V_2 -> V_75 , L_16 ) ;
F_86 ( V_2 ) ;
}
return V_192 ;
}
static T_8 F_95 ( int V_184 , void * V_185 )
{
struct V_13 * V_14 = V_185 ;
struct V_1 * V_2 = F_11 ( V_14 ) ;
struct V_154 * V_193 ;
unsigned int V_155 ;
V_2 -> V_194 = F_96 ( V_2 , V_187 ) &
~ F_96 ( V_2 , V_188 ) ;
F_97 ( V_2 , 0xffffffff , V_189 ) ;
if ( F_57 ( V_2 -> V_194 == 0 ) ) {
F_91 ( V_2 -> V_75 , L_17 ) ;
return V_190 ;
}
for ( V_155 = 0 ; V_155 < V_14 -> V_177 ; V_155 ++ ) {
if ( ! ( V_2 -> V_194 & F_81 ( V_155 ) ) )
continue;
V_193 = & V_2 -> V_178 [ V_155 ] ;
if ( F_61 ( F_92 ( & V_193 -> V_146 ) ) ) {
F_98 ( V_2 , F_81 ( V_155 ) ) ;
F_93 ( & V_193 -> V_146 ) ;
}
}
return V_192 ;
}
static T_8 F_99 ( int V_184 , void * V_185 )
{
struct V_1 * V_2 = V_185 ;
F_100 ( & V_2 -> V_89 -> V_14 , 0 ) ;
return V_192 ;
}
static struct V_115 * F_101 ( struct V_115 * V_95 ,
struct V_13 * V_14 )
{
struct V_115 * V_195 ;
struct V_196 * V_197 ;
T_4 V_198 ;
T_5 V_199 ;
T_7 V_200 ;
T_7 V_201 ;
if ( F_57 ( F_102 ( V_95 ) < sizeof( * V_197 ) ) ) {
V_195 = F_103 ( V_95 , sizeof( * V_197 ) ) ;
F_104 ( V_95 ) ;
if ( ! V_195 ) {
V_14 -> V_77 . V_202 ++ ;
V_14 -> V_77 . V_203 ++ ;
return NULL ;
}
V_95 = V_195 ;
}
V_197 = (struct V_196 * ) F_105 ( V_95 , sizeof( * V_197 ) ) ;
memset ( V_197 , 0 , sizeof( * V_197 ) ) ;
if ( V_95 -> V_140 == V_204 ) {
V_201 = F_106 ( V_95 -> V_143 ) ;
switch ( V_201 ) {
case V_205 :
V_199 = F_107 ( V_95 ) -> V_143 ;
break;
case V_206 :
V_199 = F_108 ( V_95 ) -> V_207 ;
break;
default:
return V_95 ;
}
V_200 = F_109 ( V_95 ) - sizeof( * V_197 ) ;
V_198 = ( V_200 + V_95 -> V_208 ) & V_209 ;
V_198 |= ( V_200 << V_210 ) ;
if ( V_199 == V_211 || V_199 == V_212 ) {
V_198 |= V_213 ;
if ( V_199 == V_212 && V_201 == V_205 )
V_198 |= V_214 ;
} else {
V_198 = 0 ;
}
V_197 -> V_215 = V_198 ;
}
return V_95 ;
}
static T_9 F_110 ( struct V_115 * V_95 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
struct V_87 * V_88 = & V_2 -> V_89 -> V_14 ;
struct V_154 * V_155 ;
struct V_93 * V_94 ;
struct V_160 * V_161 ;
struct V_8 * V_9 ;
unsigned int V_216 ;
unsigned long V_172 ;
T_2 V_98 ;
T_4 V_217 ;
T_7 V_218 ;
int V_36 ;
V_218 = F_111 ( V_95 ) ;
V_161 = F_70 ( V_14 , V_218 ) ;
V_155 = & V_2 -> V_178 [ V_218 ] ;
F_75 ( & V_155 -> V_173 , V_172 ) ;
if ( F_57 ( V_155 -> V_170 == 0 ) ) {
F_112 ( V_161 ) ;
F_113 ( V_14 , L_18 , V_218 ) ;
V_36 = V_219 ;
goto V_220;
}
if ( V_2 -> V_28 ) {
V_95 = F_101 ( V_95 , V_14 ) ;
if ( ! V_95 ) {
V_36 = V_221 ;
goto V_220;
}
}
if ( F_114 ( V_95 , V_222 + V_223 ) ) {
V_36 = V_221 ;
goto V_220;
}
V_216 = V_95 -> V_117 < V_222 + V_223 ?
V_222 + V_223 : V_95 -> V_117 ;
V_98 = F_52 ( V_88 , V_95 -> V_51 , V_216 , V_152 ) ;
if ( F_53 ( V_88 , V_98 ) ) {
V_2 -> V_103 . V_224 ++ ;
F_51 ( V_2 , V_225 , V_14 , L_19 ,
V_95 -> V_51 , V_216 ) ;
V_36 = V_221 ;
goto V_220;
}
V_94 = & V_155 -> V_169 [ V_155 -> V_226 ] ;
V_94 -> V_95 = V_95 ;
F_48 ( V_94 , V_96 , V_98 ) ;
F_115 ( V_94 , V_151 , V_216 ) ;
V_9 = V_155 -> V_227 ;
V_9 -> V_12 = F_5 ( V_98 ) ;
V_217 = F_4 ( V_98 ) & V_5 ;
V_217 |= ( V_216 << V_130 ) ;
V_217 |= ( V_135 | V_134 | V_228 ) <<
V_132 ;
if ( V_95 -> V_140 == V_204 )
V_217 |= ( V_139 << V_132 ) ;
V_155 -> V_226 ++ ;
if ( V_155 -> V_226 == V_155 -> V_167 )
V_155 -> V_226 = 0 ;
V_155 -> V_170 -- ;
F_116 () ;
V_9 -> V_11 = V_217 ;
F_116 () ;
F_6 ( V_2 , V_9 , V_155 -> V_163 ) ;
if ( V_155 -> V_170 == 0 )
F_112 ( V_161 ) ;
F_33 ( V_2 , V_229 , V_14 , L_20 ,
V_155 -> V_163 , V_155 -> V_170 , V_155 -> V_226 ) ;
V_36 = V_221 ;
V_220:
F_76 ( & V_155 -> V_173 , V_172 ) ;
return V_36 ;
}
static void F_117 ( struct V_13 * V_14 )
{
F_91 ( V_14 , L_21 ) ;
V_14 -> V_230 = V_231 ;
V_14 -> V_77 . V_202 ++ ;
F_118 ( V_14 ) ;
}
static void F_119 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
struct V_232 * V_18 = V_2 -> V_18 ;
unsigned int V_34 = 0 ;
T_4 V_233 = 0 , V_20 ;
if ( V_2 -> V_234 != V_18 -> V_235 ) {
V_34 = 1 ;
V_2 -> V_234 = V_18 -> V_235 ;
}
if ( V_2 -> V_236 != V_18 -> V_237 ) {
V_34 = 1 ;
V_2 -> V_236 = V_18 -> V_237 ;
}
switch ( V_18 -> V_238 ) {
case V_239 :
V_233 = V_240 ;
break;
case V_241 :
V_233 = V_242 ;
break;
case V_243 :
V_233 = V_244 ;
break;
case V_245 :
V_233 = V_246 ;
break;
default:
break;
}
V_233 <<= V_247 ;
if ( V_18 -> V_237 == V_248 )
V_233 |= V_249 ;
if ( V_2 -> V_250 != V_18 -> V_251 ) {
V_34 = 1 ;
V_2 -> V_250 = V_18 -> V_251 ;
}
if ( ! V_18 -> V_251 )
V_233 |= V_252 | V_253 ;
if ( ! V_34 )
return;
if ( V_18 -> V_235 ) {
V_20 = F_30 ( V_2 , V_254 ) ;
V_20 &= ~ ( ( V_255 << V_247 ) |
V_249 | V_252 |
V_253 ) ;
V_20 |= V_233 ;
F_40 ( V_2 , V_20 , V_254 ) ;
}
F_120 ( V_2 -> V_18 ) ;
}
static int F_121 ( struct V_1 * V_2 ,
unsigned int V_163 )
{
struct V_154 * V_155 = & V_2 -> V_178 [ V_163 ] ;
struct V_87 * V_88 = & V_2 -> V_89 -> V_14 ;
T_10 V_167 ;
void * V_61 ;
T_4 V_20 ;
V_167 = 256 ;
V_61 = F_122 ( V_88 , sizeof( struct V_8 ) , & V_155 -> V_256 ,
V_257 ) ;
if ( ! V_61 ) {
F_51 ( V_2 , V_74 , V_2 -> V_75 , L_22 ) ;
return - V_101 ;
}
V_155 -> V_169 = F_123 ( V_167 , sizeof( struct V_93 ) , V_257 ) ;
if ( ! V_155 -> V_169 ) {
F_51 ( V_2 , V_74 , V_2 -> V_75 , L_23 ) ;
return - V_101 ;
}
F_124 ( & V_155 -> V_173 ) ;
V_155 -> V_2 = V_2 ;
F_125 ( V_2 -> V_75 , & V_155 -> V_146 , F_77 , 64 ) ;
V_155 -> V_163 = V_163 ;
V_155 -> V_167 = V_167 ;
V_155 -> V_258 = V_155 -> V_167 ;
V_155 -> V_227 = V_61 ;
V_155 -> V_170 = V_155 -> V_167 ;
V_155 -> V_226 = 0 ;
F_7 ( V_2 , V_259 , F_126 ( V_163 ) ) ;
F_7 ( V_2 , 0 , F_127 ( V_163 ) ) ;
F_7 ( V_2 , 1 , F_128 ( V_163 ) ) ;
F_7 ( V_2 , 0 , F_71 ( V_163 ) ) ;
F_7 ( V_2 , V_260 , F_129 ( V_163 ) ) ;
F_7 ( V_2 , 0 , F_130 ( V_163 ) ) ;
F_7 ( V_2 , V_155 -> V_167 |
1 << V_261 ,
F_131 ( V_163 ) ) ;
V_20 = F_21 ( V_2 , V_262 ) ;
V_20 |= ( 1 << V_163 ) ;
F_7 ( V_2 , V_20 , V_262 ) ;
F_132 ( & V_155 -> V_146 ) ;
F_33 ( V_2 , V_74 , V_2 -> V_75 ,
L_24 ,
V_155 -> V_167 , V_155 -> V_227 ) ;
return 0 ;
}
static void F_133 ( struct V_1 * V_2 ,
unsigned int V_163 )
{
struct V_154 * V_155 = & V_2 -> V_178 [ V_163 ] ;
struct V_87 * V_88 = & V_2 -> V_89 -> V_14 ;
T_4 V_20 ;
V_20 = F_21 ( V_2 , V_263 ) ;
if ( ! ( V_20 & V_264 ) )
F_91 ( V_2 -> V_75 , L_25 ) ;
if ( ! V_155 -> V_169 )
return;
F_134 ( & V_155 -> V_146 ) ;
F_135 ( & V_155 -> V_146 ) ;
F_74 ( V_2 , V_155 ) ;
F_136 ( V_155 -> V_169 ) ;
V_155 -> V_169 = NULL ;
if ( V_155 -> V_256 ) {
F_137 ( V_88 , sizeof( struct V_8 ) ,
V_155 -> V_227 , V_155 -> V_256 ) ;
V_155 -> V_256 = 0 ;
}
V_155 -> V_167 = 0 ;
V_155 -> V_258 = 0 ;
F_33 ( V_2 , V_74 , V_2 -> V_75 , L_26 ) ;
}
static inline int F_138 ( struct V_1 * V_2 ,
unsigned int V_46 )
{
unsigned int V_265 = 1000 ;
T_4 V_20 ;
V_20 = F_56 ( V_2 , V_266 ) ;
if ( V_46 )
V_20 |= V_267 ;
else
V_20 &= ~ V_267 ;
F_84 ( V_2 , V_20 , V_266 ) ;
do {
V_20 = F_56 ( V_2 , V_268 ) ;
if ( ! ! ( V_20 & V_269 ) == ! V_46 )
return 0 ;
F_139 ( 1000 , 2000 ) ;
} while ( V_265 -- > 0 );
F_113 ( V_2 -> V_75 , L_27 ) ;
return - V_270 ;
}
static inline int F_140 ( struct V_1 * V_2 ,
unsigned int V_46 )
{
unsigned int V_265 = 1000 ;
T_4 V_20 ;
V_20 = F_21 ( V_2 , V_31 ) ;
if ( V_46 )
V_20 |= V_271 ;
else
V_20 &= ~ V_271 ;
F_7 ( V_2 , V_20 , V_31 ) ;
do {
V_20 = F_21 ( V_2 , V_263 ) ;
if ( ! ! ( V_20 & V_264 ) == ! V_46 )
return 0 ;
F_139 ( 1000 , 2000 ) ;
} while ( V_265 -- > 0 );
F_113 ( V_2 -> V_75 , L_28 ) ;
return - V_270 ;
}
static int F_141 ( struct V_1 * V_2 )
{
T_4 V_20 ;
int V_36 ;
V_2 -> V_107 = V_272 ;
V_2 -> V_108 = V_2 -> V_273 + V_274 ;
V_2 -> V_105 = V_2 -> V_108 ;
V_2 -> V_106 = 0 ;
V_2 -> V_123 = 0 ;
V_2 -> V_125 = 0 ;
V_2 -> V_111 = F_123 ( V_2 -> V_107 , sizeof( struct V_93 ) ,
V_257 ) ;
if ( ! V_2 -> V_111 ) {
F_51 ( V_2 , V_74 , V_2 -> V_75 , L_23 ) ;
return - V_101 ;
}
V_36 = F_54 ( V_2 ) ;
if ( V_36 ) {
F_51 ( V_2 , V_74 , V_2 -> V_75 , L_29 ) ;
return V_36 ;
}
V_20 = F_56 ( V_2 , V_268 ) ;
if ( ! ( V_20 & V_269 ) )
F_138 ( V_2 , 0 ) ;
F_84 ( V_2 , 0 , V_275 ) ;
F_84 ( V_2 , 0 , V_276 ) ;
F_84 ( V_2 , 0 , V_121 ) ;
F_84 ( V_2 , 0 , V_179 ) ;
F_84 ( V_2 , V_2 -> V_107 << V_277 |
V_99 , V_278 ) ;
F_84 ( V_2 , 0 , V_279 ) ;
F_84 ( V_2 , 0 , V_280 ) ;
F_84 ( V_2 , 0 , V_281 ) ;
F_84 ( V_2 , V_282 - 1 , V_283 ) ;
F_84 ( V_2 , 1 , V_284 ) ;
F_33 ( V_2 , V_74 , V_2 -> V_75 ,
L_30 ,
V_2 -> V_107 , V_2 -> V_108 ) ;
return 0 ;
}
static void F_142 ( struct V_1 * V_2 )
{
struct V_93 * V_94 ;
unsigned int V_52 ;
T_4 V_20 ;
V_20 = F_56 ( V_2 , V_268 ) ;
if ( ! ( V_20 & V_269 ) )
F_91 ( V_2 -> V_75 , L_31 ) ;
for ( V_52 = 0 ; V_52 < V_2 -> V_107 ; V_52 ++ ) {
V_94 = & V_2 -> V_111 [ V_52 ] ;
if ( F_59 ( V_94 , V_96 ) )
F_58 ( & V_2 -> V_89 -> V_14 ,
F_59 ( V_94 , V_96 ) ,
V_99 , V_102 ) ;
F_46 ( V_94 ) ;
}
F_136 ( V_2 -> V_111 ) ;
V_2 -> V_111 = NULL ;
F_33 ( V_2 , V_74 , V_2 -> V_75 , L_32 ) ;
}
static void F_143 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
T_4 V_20 ;
V_20 = F_30 ( V_2 , V_254 ) ;
if ( V_14 -> V_172 & V_285 )
V_20 |= V_286 ;
else
V_20 &= ~ V_286 ;
F_40 ( V_2 , V_20 , V_254 ) ;
if ( V_14 -> V_172 & V_287 )
return;
}
static inline void F_144 ( struct V_1 * V_2 ,
T_4 V_288 , unsigned int V_46 )
{
T_4 V_20 ;
V_20 = F_30 ( V_2 , V_254 ) ;
if ( V_46 )
V_20 |= V_288 ;
else
V_20 &= ~ V_288 ;
F_40 ( V_2 , V_20 , V_254 ) ;
if ( V_46 == 0 )
F_139 ( 1000 , 2000 ) ;
}
static inline void F_145 ( struct V_1 * V_2 )
{
T_4 V_20 ;
V_20 = F_30 ( V_2 , V_254 ) ;
V_20 |= V_289 ;
F_40 ( V_2 , V_20 , V_254 ) ;
F_146 ( 10 ) ;
V_20 = F_30 ( V_2 , V_254 ) ;
V_20 &= ~ V_289 ;
F_40 ( V_2 , V_20 , V_254 ) ;
}
static void F_147 ( struct V_1 * V_2 ,
unsigned char * V_4 )
{
F_40 ( V_2 , ( V_4 [ 0 ] << 24 ) | ( V_4 [ 1 ] << 16 ) |
( V_4 [ 2 ] << 8 ) | V_4 [ 3 ] , V_290 ) ;
F_40 ( V_2 , ( V_4 [ 4 ] << 8 ) | V_4 [ 5 ] , V_291 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
F_149 ( V_2 , V_292 , V_293 ) ;
F_149 ( V_2 , V_294 , V_295 ) ;
F_150 ( 1 ) ;
F_149 ( V_2 , 0 , V_293 ) ;
F_149 ( V_2 , 0 , V_295 ) ;
}
static int F_151 ( struct V_13 * V_14 , void * V_61 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
struct V_296 * V_4 = V_61 ;
if ( ! F_152 ( V_4 -> V_297 ) )
return - V_17 ;
memcpy ( V_14 -> V_298 , V_4 -> V_297 , V_14 -> V_299 ) ;
if ( ! F_12 ( V_14 ) )
return 0 ;
F_147 ( V_2 , V_14 -> V_298 ) ;
return 0 ;
}
static void F_153 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
F_132 ( & V_2 -> V_146 ) ;
F_85 ( V_2 , V_180 | V_191 ) ;
F_154 ( V_2 -> V_18 ) ;
F_80 ( V_2 , 0xffffffff ) ;
F_155 ( V_14 ) ;
}
static void F_156 ( struct V_1 * V_2 )
{
T_4 V_20 ;
V_20 = F_31 ( V_2 , V_300 ) ;
V_20 |= V_301 | V_302 ;
F_32 ( V_2 , V_20 , V_300 ) ;
}
static int F_157 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
unsigned int V_52 ;
int V_36 ;
F_145 ( V_2 ) ;
F_148 ( V_2 ) ;
F_144 ( V_2 , V_303 | V_304 , 0 ) ;
F_156 ( V_2 ) ;
F_40 ( V_2 , V_305 , V_306 ) ;
F_147 ( V_2 , V_14 -> V_298 ) ;
V_2 -> V_25 = ! ! ( F_30 ( V_2 , V_254 ) & V_307 ) ;
V_2 -> V_18 = F_158 ( V_14 , V_2 -> V_308 , F_119 ,
0 , V_2 -> V_309 ) ;
if ( ! V_2 -> V_18 ) {
F_113 ( V_14 , L_33 ) ;
return - V_310 ;
}
V_2 -> V_236 = - 1 ;
V_2 -> V_234 = - 1 ;
V_2 -> V_250 = - 1 ;
F_90 ( V_2 , 0xffffffff , V_311 ) ;
F_90 ( V_2 , 0xffffffff , V_189 ) ;
F_90 ( V_2 , 0 , V_312 ) ;
F_97 ( V_2 , 0xffffffff , V_311 ) ;
F_97 ( V_2 , 0xffffffff , V_189 ) ;
F_97 ( V_2 , 0 , V_312 ) ;
V_36 = F_159 ( V_2 -> V_313 , F_88 , 0 , V_14 -> V_314 , V_14 ) ;
if ( V_36 ) {
F_113 ( V_14 , L_34 ) ;
goto V_315;
}
V_36 = F_159 ( V_2 -> V_316 , F_95 , 0 , V_14 -> V_314 , V_14 ) ;
if ( V_36 ) {
F_113 ( V_14 , L_35 ) ;
goto V_317;
}
for ( V_52 = 0 ; V_52 < V_14 -> V_177 ; V_52 ++ ) {
V_36 = F_121 ( V_2 , V_52 ) ;
if ( V_36 ) {
F_113 ( V_14 , L_36 ,
V_52 ) ;
goto V_318;
}
}
F_7 ( V_2 , V_319 , V_263 ) ;
V_36 = F_141 ( V_2 ) ;
if ( V_36 ) {
F_113 ( V_14 , L_37 ) ;
goto V_320;
}
V_36 = F_138 ( V_2 , 1 ) ;
if ( V_36 )
goto V_320;
V_36 = F_140 ( V_2 , 1 ) ;
if ( V_36 )
goto V_321;
F_144 ( V_2 , V_303 | V_304 , 1 ) ;
F_153 ( V_14 ) ;
return 0 ;
V_321:
F_87 ( V_2 , V_180 | V_191 ) ;
V_320:
F_142 ( V_2 ) ;
V_318:
for ( V_52 = 0 ; V_52 < V_14 -> V_177 ; V_52 ++ )
F_133 ( V_2 , V_52 ) ;
F_160 ( V_2 -> V_316 , V_14 ) ;
V_317:
F_160 ( V_2 -> V_313 , V_14 ) ;
V_315:
F_161 ( V_2 -> V_18 ) ;
return V_36 ;
}
static void F_162 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
F_163 ( V_14 ) ;
F_134 ( & V_2 -> V_146 ) ;
F_164 ( V_2 -> V_18 ) ;
F_87 ( V_2 , 0xffffffff ) ;
F_90 ( V_2 , 0xffffffff , V_189 ) ;
F_98 ( V_2 , 0xffffffff ) ;
F_97 ( V_2 , 0xffffffff , V_189 ) ;
}
static int F_165 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
unsigned int V_52 ;
int V_36 ;
F_162 ( V_14 ) ;
F_144 ( V_2 , V_303 , 0 ) ;
V_36 = F_140 ( V_2 , 0 ) ;
if ( V_36 ) {
F_113 ( V_14 , L_38 ) ;
return V_36 ;
}
F_139 ( 2000 , 3000 ) ;
V_36 = F_138 ( V_2 , 0 ) ;
if ( V_36 ) {
F_113 ( V_14 , L_39 ) ;
return V_36 ;
}
F_144 ( V_2 , V_304 , 0 ) ;
for ( V_52 = 0 ; V_52 < V_14 -> V_177 ; V_52 ++ )
F_133 ( V_2 , V_52 ) ;
F_142 ( V_2 ) ;
F_160 ( V_2 -> V_313 , V_14 ) ;
F_160 ( V_2 -> V_316 , V_14 ) ;
F_161 ( V_2 -> V_18 ) ;
return 0 ;
}
static int F_166 ( struct V_322 * V_89 )
{
struct V_1 * V_2 ;
struct V_323 * V_324 ;
struct V_13 * V_14 ;
const void * V_325 ;
struct V_326 * V_327 ;
T_4 V_161 , V_328 ;
int V_36 ;
V_324 = V_89 -> V_14 . V_329 ;
V_327 = F_167 ( V_89 , V_330 , 0 ) ;
if ( F_168 ( V_324 , L_40 , & V_161 ) )
V_161 = V_331 ;
if ( F_168 ( V_324 , L_41 , & V_328 ) )
V_328 = 1 ;
V_14 = F_169 ( sizeof( * V_2 ) , V_161 , V_328 ) ;
if ( ! V_14 )
return - V_101 ;
V_2 = F_11 ( V_14 ) ;
V_2 -> V_313 = F_170 ( V_89 , 0 ) ;
V_2 -> V_316 = F_170 ( V_89 , 1 ) ;
V_2 -> V_92 = F_170 ( V_89 , 2 ) ;
if ( V_2 -> V_313 <= 0 || V_2 -> V_316 <= 0 ) {
F_171 ( & V_89 -> V_14 , L_42 ) ;
V_36 = - V_17 ;
goto V_332;
}
V_2 -> V_273 = F_172 ( & V_89 -> V_14 , V_327 ) ;
if ( F_173 ( V_2 -> V_273 ) ) {
V_36 = F_174 ( V_2 -> V_273 ) ;
goto V_332;
}
V_2 -> V_75 = V_14 ;
V_2 -> V_89 = V_89 ;
V_2 -> V_309 = F_175 ( V_324 ) ;
if ( V_2 -> V_309 < 0 )
V_2 -> V_309 = V_333 ;
if ( F_176 ( V_324 ) ) {
V_36 = F_177 ( V_324 ) ;
if ( V_36 ) {
F_171 ( & V_89 -> V_14 , L_43 ) ;
goto V_332;
}
V_2 -> V_308 = V_324 ;
}
V_325 = F_178 ( V_324 ) ;
if ( ! V_325 || ! F_152 ( V_325 ) ) {
F_179 ( & V_89 -> V_14 , L_44 ) ;
F_180 ( V_14 -> V_298 ) ;
} else {
F_181 ( V_14 -> V_298 , V_325 ) ;
}
F_182 ( V_14 , & V_89 -> V_14 ) ;
F_183 ( & V_89 -> V_14 , V_14 ) ;
V_14 -> V_334 = & V_335 ;
V_14 -> V_336 = & V_337 ;
F_125 ( V_14 , & V_2 -> V_146 , F_83 , 64 ) ;
V_14 -> V_338 |= V_22 | V_339 |
V_29 | V_30 ;
V_2 -> V_91 = 1 ;
V_36 = F_184 ( & V_89 -> V_14 , V_2 -> V_92 ,
F_99 , 0 , V_14 -> V_314 , V_2 ) ;
if ( ! V_36 )
F_185 ( & V_89 -> V_14 , 1 ) ;
F_186 ( sizeof( struct V_196 ) != 8 ) ;
V_14 -> V_340 += sizeof( struct V_196 ) ;
F_187 ( V_14 ) ;
V_36 = F_188 ( V_14 ) ;
if ( V_36 ) {
F_171 ( & V_89 -> V_14 , L_45 ) ;
goto V_332;
}
V_2 -> V_341 = F_189 ( V_2 , V_342 ) & V_343 ;
F_190 ( & V_89 -> V_14 ,
L_46 V_344
L_47 ,
( V_2 -> V_341 >> 8 ) & 0xff , V_2 -> V_341 & 0xff ,
V_2 -> V_273 , V_2 -> V_313 , V_2 -> V_316 , V_161 , V_328 ) ;
return 0 ;
V_332:
F_191 ( V_14 ) ;
return V_36 ;
}
static int F_192 ( struct V_322 * V_89 )
{
struct V_13 * V_14 = F_193 ( & V_89 -> V_14 ) ;
F_194 ( V_14 ) ;
F_191 ( V_14 ) ;
F_183 ( & V_89 -> V_14 , NULL ) ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 )
{
struct V_13 * V_97 = V_2 -> V_75 ;
unsigned int V_265 = 1000 ;
T_4 V_20 ;
V_20 = F_30 ( V_2 , V_182 ) ;
V_20 |= V_183 ;
V_20 &= ~ V_345 ;
if ( V_2 -> V_83 & V_82 )
V_20 |= V_345 ;
F_40 ( V_2 , V_20 , V_182 ) ;
do {
V_20 = F_31 ( V_2 , V_346 ) ;
if ( V_20 & V_347 )
break;
F_146 ( 10 ) ;
} while ( V_265 -- > 0 );
if ( ! V_265 ) {
V_20 = F_30 ( V_2 , V_182 ) ;
V_20 &= ~ V_183 ;
F_40 ( V_2 , V_20 , V_182 ) ;
F_51 ( V_2 , V_79 , V_97 , L_48 ) ;
return - V_270 ;
}
F_144 ( V_2 , V_303 , 1 ) ;
F_85 ( V_2 , V_181 ) ;
F_33 ( V_2 , V_79 , V_97 , L_49 ) ;
return 0 ;
}
static int F_196 ( struct V_87 * V_3 )
{
struct V_13 * V_14 = F_193 ( V_3 ) ;
struct V_1 * V_2 = F_11 ( V_14 ) ;
unsigned int V_52 ;
int V_36 = 0 ;
T_4 V_20 ;
if ( ! F_12 ( V_14 ) )
return 0 ;
F_162 ( V_14 ) ;
F_197 ( V_2 -> V_18 ) ;
F_198 ( V_14 ) ;
F_144 ( V_2 , V_303 , 0 ) ;
V_36 = F_138 ( V_2 , 0 ) ;
if ( V_36 ) {
F_113 ( V_14 , L_50 ) ;
return V_36 ;
}
if ( V_2 -> V_21 ) {
V_20 = F_17 ( V_2 , V_23 ) ;
V_20 &= ~ V_24 ;
F_19 ( V_2 , V_20 , V_23 ) ;
}
if ( ! V_2 -> V_83 )
F_149 ( V_2 , V_292 , V_293 ) ;
V_36 = F_140 ( V_2 , 0 ) ;
if ( V_36 ) {
F_113 ( V_14 , L_51 ) ;
return V_36 ;
}
F_139 ( 2000 , 3000 ) ;
F_144 ( V_2 , V_304 , 0 ) ;
F_149 ( V_2 , V_294 , V_295 ) ;
for ( V_52 = 0 ; V_52 < V_14 -> V_177 ; V_52 ++ )
F_133 ( V_2 , V_52 ) ;
F_142 ( V_2 ) ;
if ( F_199 ( V_3 ) && V_2 -> V_83 )
V_36 = F_195 ( V_2 ) ;
return V_36 ;
}
static int F_200 ( struct V_87 * V_3 )
{
struct V_13 * V_14 = F_193 ( V_3 ) ;
struct V_1 * V_2 = F_11 ( V_14 ) ;
unsigned int V_52 ;
T_4 V_20 ;
int V_36 ;
if ( ! F_12 ( V_14 ) )
return 0 ;
F_145 ( V_2 ) ;
F_86 ( V_2 ) ;
for ( V_52 = 0 ; V_52 < V_14 -> V_177 ; V_52 ++ ) {
V_36 = F_121 ( V_2 , V_52 ) ;
if ( V_36 ) {
F_113 ( V_14 , L_36 ,
V_52 ) ;
goto V_348;
}
}
F_7 ( V_2 , V_319 , V_263 ) ;
V_36 = F_141 ( V_2 ) ;
if ( V_36 ) {
F_113 ( V_14 , L_37 ) ;
goto V_320;
}
F_201 ( V_14 ) ;
F_149 ( V_2 , 0 , V_293 ) ;
V_36 = F_138 ( V_2 , 1 ) ;
if ( V_36 ) {
F_113 ( V_14 , L_52 ) ;
goto V_320;
}
if ( V_2 -> V_21 ) {
V_20 = F_17 ( V_2 , V_23 ) ;
V_20 |= V_24 ;
F_19 ( V_2 , V_20 , V_23 ) ;
}
F_156 ( V_2 ) ;
F_40 ( V_2 , V_305 , V_306 ) ;
F_147 ( V_2 , V_14 -> V_298 ) ;
F_144 ( V_2 , V_303 , 1 ) ;
F_149 ( V_2 , 0 , V_295 ) ;
F_144 ( V_2 , V_304 , 1 ) ;
V_36 = F_140 ( V_2 , 1 ) ;
if ( V_36 ) {
F_113 ( V_14 , L_51 ) ;
goto V_320;
}
F_202 ( V_2 -> V_18 ) ;
F_153 ( V_14 ) ;
return 0 ;
V_320:
F_142 ( V_2 ) ;
V_348:
for ( V_52 = 0 ; V_52 < V_14 -> V_177 ; V_52 ++ )
F_133 ( V_2 , V_52 ) ;
return V_36 ;
}
