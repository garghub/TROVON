static void F_1 ( struct V_1 * V_2 , int V_3 )
{
union V_4 V_5 ;
unsigned long V_6 ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_5 . V_8 = F_3 ( V_2 -> V_9 + V_10 ) ;
V_5 . V_11 . V_12 = V_3 ? 1 : 0 ;
F_4 ( V_2 -> V_9 + V_10 , V_5 . V_8 ) ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_3 )
{
union V_4 V_5 ;
unsigned long V_6 ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_5 . V_8 = F_3 ( V_2 -> V_9 + V_10 ) ;
V_5 . V_11 . V_13 = V_3 ? 1 : 0 ;
F_4 ( V_2 -> V_9 + V_10 , V_5 . V_8 ) ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 1 ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
F_6 ( V_2 , 1 ) ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
F_6 ( V_2 , 0 ) ;
}
static unsigned int F_11 ( unsigned int V_14 )
{
return V_14 - 8 ;
}
static unsigned int F_12 ( unsigned int V_14 )
{
return V_14 * sizeof( union V_15 ) ;
}
static void F_13 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
while ( V_2 -> V_18 < F_11 ( V_19 ) ) {
unsigned int V_20 ;
union V_15 V_21 ;
struct V_22 * V_23 ;
V_20 = V_17 -> V_24 + V_25 + 8 + V_26 ;
V_23 = F_15 ( V_17 , V_20 ) ;
if ( ! V_23 )
break;
F_16 ( V_23 , V_26 ) ;
F_17 ( & V_2 -> V_27 , V_23 ) ;
V_21 . V_28 = 0 ;
V_21 . V_11 . V_29 = V_20 ;
V_21 . V_11 . V_30 = F_18 ( V_2 -> V_31 , V_23 -> V_32 ,
V_20 ,
V_33 ) ;
V_2 -> V_34 [ V_2 -> V_35 ] = V_21 . V_28 ;
F_19 ( V_2 -> V_31 , V_2 -> V_36 ,
F_12 ( V_19 ) ,
V_37 ) ;
V_2 -> V_35 =
( V_2 -> V_35 + 1 ) % V_19 ;
V_2 -> V_18 ++ ;
F_4 ( V_2 -> V_9 + V_38 , 1 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
union V_39 V_40 ;
union V_15 V_21 ;
struct V_22 * V_23 ;
int V_41 = 0 ;
unsigned long V_6 ;
V_40 . V_8 = F_3 ( V_2 -> V_9 + V_42 ) ;
while ( V_40 . V_11 . V_43 ) {
F_2 ( & V_2 -> V_44 . V_7 , V_6 ) ;
V_40 . V_8 = F_3 ( V_2 -> V_9 + V_42 ) ;
if ( V_40 . V_11 . V_43 == 0 ) {
F_5 ( & V_2 -> V_44 . V_7 , V_6 ) ;
break;
}
F_21 ( V_2 -> V_31 , V_2 -> V_45 ,
F_12 ( V_46 ) ,
V_37 ) ;
V_21 . V_28 = V_2 -> V_47 [ V_2 -> V_48 ] ;
V_2 -> V_48 =
( V_2 -> V_48 + 1 ) % V_46 ;
V_23 = F_22 ( & V_2 -> V_44 ) ;
V_40 . V_8 = 0 ;
V_40 . V_11 . V_43 = 1 ;
F_4 ( V_2 -> V_9 + V_42 , V_40 . V_8 ) ;
V_2 -> V_49 -- ;
F_5 ( & V_2 -> V_44 . V_7 , V_6 ) ;
F_23 ( V_2 -> V_31 , V_21 . V_11 . V_30 , V_21 . V_11 . V_29 ,
V_50 ) ;
F_24 ( V_23 ) ;
V_41 ++ ;
V_40 . V_8 = F_3 ( V_2 -> V_9 + V_42 ) ;
}
if ( V_41 && F_25 ( V_2 -> V_17 ) )
F_26 ( V_2 -> V_17 ) ;
}
static void F_27 ( unsigned long V_51 )
{
struct V_1 * V_2 = (struct V_1 * ) V_51 ;
F_20 ( V_2 ) ;
F_9 ( V_2 ) ;
}
static void F_28 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
unsigned long V_6 ;
V_8 V_52 , V_53 ;
V_52 = F_3 ( V_2 -> V_54 + V_55 ) ;
V_53 = F_3 ( V_2 -> V_54 + V_56 ) ;
if ( V_52 || V_53 ) {
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_17 -> V_57 . V_58 += V_53 ;
V_17 -> V_57 . V_59 += V_52 ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
}
}
static void F_29 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
unsigned long V_6 ;
union V_60 V_61 ;
union V_62 V_63 ;
V_61 . V_8 = F_3 ( V_2 -> V_54 + V_64 ) ;
V_63 . V_8 = F_3 ( V_2 -> V_54 + V_65 ) ;
if ( V_61 . V_11 . V_66 || V_61 . V_11 . V_67 || V_63 . V_11 . V_68 || V_63 . V_11 . V_69 ) {
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_17 -> V_57 . V_70 += V_61 . V_11 . V_66 + V_61 . V_11 . V_67 ;
V_17 -> V_57 . V_71 += V_63 . V_11 . V_68 + V_63 . V_11 . V_69 ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
}
}
static V_8 F_30 ( struct V_1 * V_2 ,
struct V_22 * * V_72 )
{
union V_15 V_21 ;
F_21 ( V_2 -> V_31 , V_2 -> V_36 ,
F_12 ( V_19 ) ,
V_37 ) ;
V_21 . V_28 = V_2 -> V_34 [ V_2 -> V_73 ] ;
V_2 -> V_73 = ( V_2 -> V_73 + 1 ) % V_19 ;
V_2 -> V_18 -- ;
* V_72 = F_22 ( & V_2 -> V_27 ) ;
F_23 ( V_2 -> V_31 , V_21 . V_11 . V_30 ,
V_74 + V_25 ,
V_33 ) ;
return V_21 . V_28 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
union V_75 V_76 ;
union V_15 V_21 ;
struct V_22 * V_23 ;
struct V_22 * V_77 ;
struct V_22 * V_78 ;
union V_15 V_79 ;
int V_80 = 1 ;
V_21 . V_28 = F_30 ( V_2 , & V_23 ) ;
if ( F_32 ( V_21 . V_11 . V_81 == V_82 ) ) {
F_33 ( V_23 , V_21 . V_11 . V_29 ) ;
V_83:
V_23 -> V_84 = F_34 ( V_23 , V_17 ) ;
V_17 -> V_57 . V_85 ++ ;
V_17 -> V_57 . V_86 += V_23 -> V_29 ;
F_35 ( V_23 ) ;
V_80 = 0 ;
} else if ( V_21 . V_11 . V_81 == V_87 ) {
F_33 ( V_23 , V_21 . V_11 . V_29 ) ;
do {
V_79 . V_28 = F_30 ( V_2 , & V_77 ) ;
if ( V_79 . V_11 . V_81 != V_87
&& V_79 . V_11 . V_81 != V_82 )
goto V_88;
F_33 ( V_77 , V_79 . V_11 . V_29 ) ;
V_78 = F_36 ( V_23 , 0 , V_77 -> V_29 ,
V_89 ) ;
if ( ! V_78 )
goto V_88;
if ( F_37 ( V_77 , 0 , F_38 ( V_78 ) ,
V_77 -> V_29 ) )
goto V_88;
F_33 ( V_78 , V_77 -> V_29 ) ;
F_24 ( V_23 ) ;
F_24 ( V_77 ) ;
V_23 = V_78 ;
} while ( V_79 . V_11 . V_81 == V_87 );
goto V_83;
} else {
F_24 ( V_23 ) ;
}
goto V_90;
V_88:
F_24 ( V_23 ) ;
F_24 ( V_77 ) ;
while ( V_79 . V_11 . V_81 == V_87 ) {
V_79 . V_28 = F_30 ( V_2 , & V_77 ) ;
F_24 ( V_77 ) ;
}
V_17 -> V_57 . V_58 ++ ;
V_90:
V_76 . V_8 = 0 ;
V_76 . V_11 . V_91 = 1 ;
F_4 ( V_2 -> V_9 + V_92 , V_76 . V_8 ) ;
return V_80 ;
}
static int F_39 ( struct V_1 * V_2 , int V_93 )
{
unsigned int V_94 = 0 ;
union V_75 V_76 ;
int V_80 ;
V_76 . V_8 = F_3 ( V_2 -> V_9 + V_92 ) ;
while ( V_94 < V_93 && V_76 . V_11 . V_91 ) {
V_80 = F_31 ( V_2 ) ;
if ( ! V_80 )
V_94 ++ ;
V_76 . V_8 = F_3 ( V_2 -> V_9 + V_92 ) ;
}
F_13 ( V_2 -> V_17 ) ;
return V_94 ;
}
static int F_40 ( struct V_95 * V_96 , int V_93 )
{
struct V_1 * V_2 = F_41 ( V_96 , struct V_1 , V_96 ) ;
struct V_16 * V_17 = V_2 -> V_17 ;
unsigned int V_94 = 0 ;
V_94 = F_39 ( V_2 , V_93 ) ;
if ( V_94 < V_93 ) {
F_42 ( V_96 ) ;
F_7 ( V_2 ) ;
}
F_28 ( V_17 ) ;
return V_94 ;
}
static void F_43 ( struct V_1 * V_2 )
{
union V_97 V_98 ;
union V_99 V_100 ;
union V_101 V_102 ;
V_98 . V_8 = 0 ;
F_4 ( V_2 -> V_9 + V_103 , V_98 . V_8 ) ;
do {
V_98 . V_8 = F_3 ( V_2 -> V_9 + V_103 ) ;
} while ( V_98 . V_11 . V_104 );
V_98 . V_11 . V_105 = 1 ;
F_4 ( V_2 -> V_9 + V_103 , V_98 . V_8 ) ;
F_3 ( V_2 -> V_9 + V_103 ) ;
F_44 ( 64 ) ;
V_100 . V_8 = F_3 ( V_2 -> V_9 + V_106 ) ;
if ( V_100 . V_8 )
F_45 ( V_2 -> V_31 , L_1 ,
( unsigned long long ) V_100 . V_8 ) ;
V_102 . V_8 = F_3 ( V_107 ) ;
if ( V_102 . V_8 )
F_45 ( V_2 -> V_31 , L_2 ,
( unsigned long long ) V_102 . V_8 ) ;
}
static void F_46 ( struct V_108 * V_109 ,
unsigned char * V_30 )
{
int V_110 ;
for ( V_110 = 0 ; V_110 < 6 ; V_110 ++ )
V_109 -> V_111 [ V_110 ] |= ( V_8 ) V_30 [ V_110 ] << ( 8 * ( V_109 -> V_112 ) ) ;
V_109 -> V_113 |= ( 1ULL << V_109 -> V_112 ) ;
V_109 -> V_112 ++ ;
}
static void F_47 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
union V_114 V_115 ;
union V_116 V_117 ;
unsigned long V_6 ;
unsigned int V_118 ;
unsigned int V_119 = 1 ;
unsigned int V_120 = 1 ;
struct V_108 V_121 ;
struct V_122 * V_123 ;
int V_124 ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
if ( ( V_17 -> V_6 & V_125 ) || V_17 -> V_126 . V_127 > 7 ) {
V_119 = 0 ;
V_124 = 8 ;
} else {
V_124 = 7 - V_17 -> V_126 . V_127 ;
}
if ( V_17 -> V_6 & V_128 ) {
if ( V_119 == 0 || ( V_17 -> V_6 & V_129 ) ||
F_48 ( V_17 ) > V_124 )
V_120 = 2 ;
else
V_120 = 0 ;
}
if ( V_119 == 1 ) {
F_46 ( & V_121 , V_17 -> V_130 ) ;
F_49 (ha, netdev)
F_46 ( & V_121 , V_123 -> V_30 ) ;
}
if ( V_120 == 0 ) {
F_50 (ha, netdev)
F_46 ( & V_121 , V_123 -> V_30 ) ;
}
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_117 . V_8 = F_3 ( V_2 -> V_54 + V_131 ) ;
V_118 = V_117 . V_11 . V_132 ;
V_117 . V_11 . V_132 = 0 ;
F_4 ( V_2 -> V_54 + V_131 , V_117 . V_8 ) ;
V_115 . V_8 = 0 ;
V_115 . V_11 . V_119 = V_119 ;
V_115 . V_11 . V_133 = V_120 ;
V_115 . V_11 . V_134 = 1 ;
F_4 ( V_2 -> V_54 + V_135 , V_115 . V_8 ) ;
F_4 ( V_2 -> V_54 + V_136 , V_121 . V_111 [ 0 ] ) ;
F_4 ( V_2 -> V_54 + V_137 , V_121 . V_111 [ 1 ] ) ;
F_4 ( V_2 -> V_54 + V_138 , V_121 . V_111 [ 2 ] ) ;
F_4 ( V_2 -> V_54 + V_139 , V_121 . V_111 [ 3 ] ) ;
F_4 ( V_2 -> V_54 + V_140 , V_121 . V_111 [ 4 ] ) ;
F_4 ( V_2 -> V_54 + V_141 , V_121 . V_111 [ 5 ] ) ;
F_4 ( V_2 -> V_54 + V_142 , V_121 . V_113 ) ;
V_117 . V_11 . V_132 = V_118 ;
F_4 ( V_2 -> V_54 + V_131 , V_117 . V_8 ) ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
}
static int F_51 ( struct V_16 * V_17 , void * V_30 )
{
struct V_143 * V_144 = V_30 ;
if ( ! F_52 ( V_144 -> V_145 ) )
return - V_146 ;
memcpy ( V_17 -> V_130 , V_144 -> V_145 , V_147 ) ;
F_47 ( V_17 ) ;
return 0 ;
}
static int F_53 ( struct V_16 * V_17 , int V_148 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
int V_149 = V_148 + V_25 ;
if ( V_149 < 64 || V_149 > 16383 ) {
F_45 ( V_2 -> V_31 , L_3 ,
64 - V_25 ,
16383 - V_25 ) ;
return - V_150 ;
}
V_17 -> V_24 = V_148 ;
F_4 ( V_2 -> V_54 + V_151 , V_149 ) ;
F_4 ( V_2 -> V_54 + V_152 ,
( V_149 + 7 ) & 0xfff8 ) ;
return 0 ;
}
static T_1 F_54 ( int V_153 , void * V_154 )
{
struct V_16 * V_17 = V_154 ;
struct V_1 * V_2 = F_14 ( V_17 ) ;
union V_155 V_156 ;
V_156 . V_8 = F_3 ( V_2 -> V_9 + V_157 ) ;
F_4 ( V_2 -> V_9 + V_157 , V_156 . V_8 ) ;
F_3 ( V_2 -> V_9 + V_157 ) ;
if ( V_156 . V_11 . V_158 ) {
F_8 ( V_2 ) ;
F_55 ( & V_2 -> V_96 ) ;
}
if ( V_156 . V_11 . V_159 ) {
F_10 ( V_2 ) ;
F_56 ( & V_2 -> V_160 ) ;
}
return V_161 ;
}
static int F_57 ( struct V_16 * V_17 ,
struct V_162 * V_163 , int V_164 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
if ( ! F_58 ( V_17 ) )
return - V_150 ;
if ( ! V_2 -> V_165 )
return - V_150 ;
return F_59 ( V_2 -> V_165 , V_163 , V_164 ) ;
}
static void F_60 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
union V_116 V_166 ;
unsigned long V_6 ;
int V_167 = 0 ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
if ( V_2 -> V_165 -> V_168 ) {
if ( ! V_2 -> V_169 )
V_167 = 1 ;
if ( V_2 -> V_170 != V_2 -> V_165 -> V_171 ) {
V_2 -> V_170 = V_2 -> V_165 -> V_171 ;
V_166 . V_8 = F_3 ( V_2 -> V_54 + V_131 ) ;
V_166 . V_11 . V_171 = V_2 -> V_165 -> V_171 ;
F_4 ( V_2 -> V_54 + V_131 , V_166 . V_8 ) ;
}
} else {
if ( V_2 -> V_169 )
V_167 = - 1 ;
}
V_2 -> V_169 = V_2 -> V_165 -> V_168 ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
if ( V_167 != 0 ) {
if ( V_167 > 0 ) {
F_61 ( V_17 ) ;
F_62 ( L_4 , V_17 -> V_172 ,
V_2 -> V_165 -> V_173 ,
V_174 == V_2 -> V_165 -> V_171 ?
L_5 : L_6 ) ;
} else {
F_63 ( V_17 ) ;
F_62 ( L_7 , V_17 -> V_172 ) ;
}
}
}
static int F_64 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
if ( F_65 () || V_2 -> V_175 == NULL ) {
F_61 ( V_17 ) ;
return 0 ;
}
V_2 -> V_165 = F_66 ( V_17 , V_2 -> V_175 ,
F_60 , 0 ,
V_176 ) ;
if ( ! V_2 -> V_165 )
return - 1 ;
F_67 ( V_2 -> V_165 ) ;
return 0 ;
}
static int F_68 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
int V_177 = V_2 -> V_177 ;
union V_97 V_98 ;
union V_178 V_179 ;
union V_180 V_181 ;
union V_182 V_183 ;
union V_116 V_166 ;
union V_184 V_185 ;
union V_186 V_187 ;
union V_188 V_189 ;
union V_4 V_5 ;
struct V_143 V_144 ;
V_2 -> V_47 = F_69 ( F_12 ( V_46 ) ,
V_190 ) ;
if ( ! V_2 -> V_47 )
return - V_191 ;
V_2 -> V_45 =
F_18 ( V_2 -> V_31 , V_2 -> V_47 ,
F_12 ( V_46 ) ,
V_37 ) ;
V_2 -> V_192 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_49 = 0 ;
V_2 -> V_34 = F_69 ( F_12 ( V_19 ) ,
V_190 ) ;
if ( ! V_2 -> V_34 )
goto V_193;
V_2 -> V_36 =
F_18 ( V_2 -> V_31 , V_2 -> V_34 ,
F_12 ( V_19 ) ,
V_37 ) ;
V_2 -> V_73 = 0 ;
V_2 -> V_35 = 0 ;
V_2 -> V_18 = 0 ;
F_43 ( V_2 ) ;
V_98 . V_8 = F_3 ( V_2 -> V_9 + V_103 ) ;
if ( V_98 . V_11 . V_105 ) {
V_98 . V_11 . V_105 = 0 ;
F_4 ( V_2 -> V_9 + V_103 , V_98 . V_8 ) ;
do {
V_98 . V_8 = F_3 ( V_2 -> V_9 + V_103 ) ;
} while ( V_98 . V_11 . V_105 );
}
V_179 . V_8 = 0 ;
V_179 . V_11 . V_132 = 1 ;
F_4 ( V_194 , V_179 . V_8 ) ;
V_181 . V_8 = 0 ;
V_181 . V_11 . V_195 = V_2 -> V_45 >> 3 ;
V_181 . V_11 . V_196 = V_46 ;
F_4 ( V_2 -> V_9 + V_197 , V_181 . V_8 ) ;
V_183 . V_8 = 0 ;
V_183 . V_11 . V_198 = V_2 -> V_36 >> 3 ;
V_183 . V_11 . V_199 = V_19 ;
F_4 ( V_2 -> V_9 + V_200 , V_183 . V_8 ) ;
V_166 . V_8 = F_3 ( V_2 -> V_54 + V_131 ) ;
V_166 . V_11 . V_132 = 0 ;
F_4 ( V_2 -> V_54 + V_131 , V_166 . V_8 ) ;
memcpy ( V_144 . V_145 , V_17 -> V_130 , V_147 ) ;
F_51 ( V_17 , & V_144 ) ;
F_53 ( V_17 , V_17 -> V_24 ) ;
V_98 . V_8 = 0 ;
V_98 . V_11 . V_201 = 1 ;
V_98 . V_11 . V_132 = 1 ;
V_98 . V_11 . V_202 = 0 ;
V_98 . V_11 . V_203 = 1 ;
F_4 ( V_2 -> V_9 + V_103 , V_98 . V_8 ) ;
if ( F_70 ( V_204 )
|| F_70 ( V_205 ) ) {
union V_206 V_207 ;
V_207 . V_8 = F_3 ( V_208 ) ;
if ( V_177 ) {
V_207 . V_11 . V_209 = 1 ;
V_207 . V_11 . V_210 = 6 ;
V_207 . V_11 . V_211 = 6 ;
} else {
V_207 . V_11 . V_212 = 1 ;
V_207 . V_11 . V_213 = 6 ;
V_207 . V_11 . V_214 = 6 ;
}
F_4 ( V_208 , V_207 . V_8 ) ;
}
F_13 ( V_17 ) ;
F_4 ( V_2 -> V_54 + V_215 , 1 ) ;
F_4 ( V_2 -> V_54 + V_55 , 0 ) ;
F_4 ( V_2 -> V_54 + V_56 , 0 ) ;
F_4 ( V_2 -> V_54 + V_216 , 1 ) ;
F_4 ( V_2 -> V_54 + V_64 , 0 ) ;
F_4 ( V_2 -> V_54 + V_65 , 0 ) ;
F_4 ( V_2 -> V_9 + V_157 , F_3 ( V_2 -> V_9 + V_157 ) ) ;
if ( F_71 ( V_2 -> V_217 , F_54 , 0 , V_17 -> V_172 ,
V_17 ) ) {
F_72 ( V_2 -> V_31 , L_8 , V_2 -> V_217 ) ;
goto V_218;
}
V_187 . V_8 = 0 ;
V_187 . V_11 . V_219 = 0 ;
F_4 ( V_2 -> V_9 + V_220 , V_187 . V_8 ) ;
V_189 . V_8 = 0 ;
V_189 . V_11 . V_221 = 1 ;
F_4 ( V_2 -> V_9 + V_222 , V_189 . V_8 ) ;
V_5 . V_8 = 0 ;
V_5 . V_11 . V_12 = 1 ;
V_5 . V_11 . V_13 = 1 ;
F_4 ( V_2 -> V_9 + V_10 , V_5 . V_8 ) ;
V_185 . V_8 = 0 ;
V_185 . V_11 . V_223 = 1 ;
V_185 . V_11 . V_224 = 1 ;
V_185 . V_11 . V_225 = 1 ;
V_185 . V_11 . V_226 = 1 ;
V_185 . V_11 . V_227 = 0 ;
V_185 . V_11 . V_228 = 1 ;
V_185 . V_11 . V_229 = 1 ;
V_185 . V_11 . V_230 = 1 ;
V_185 . V_11 . V_231 = 1 ;
V_185 . V_11 . V_232 = 1 ;
F_4 ( V_2 -> V_54 + V_233 , V_185 . V_8 ) ;
V_179 . V_8 = 0 ;
V_179 . V_11 . V_132 = 1 ;
F_4 ( V_194 , V_179 . V_8 ) ;
V_166 . V_8 = F_3 ( V_2 -> V_54 + V_131 ) ;
V_166 . V_11 . V_234 = 1 ;
V_166 . V_11 . V_235 = 1 ;
V_166 . V_11 . V_132 = 1 ;
V_2 -> V_170 = 1 ;
V_166 . V_11 . V_171 = V_2 -> V_170 ;
F_4 ( V_2 -> V_54 + V_131 , V_166 . V_8 ) ;
V_2 -> V_169 = 0 ;
F_63 ( V_17 ) ;
if ( F_64 ( V_17 ) ) {
F_72 ( V_2 -> V_31 , L_9 ) ;
goto V_218;
}
F_26 ( V_17 ) ;
F_73 ( & V_2 -> V_96 ) ;
return 0 ;
V_218:
F_43 ( V_2 ) ;
F_23 ( V_2 -> V_31 , V_2 -> V_36 ,
F_12 ( V_19 ) ,
V_37 ) ;
F_74 ( V_2 -> V_34 ) ;
V_193:
F_23 ( V_2 -> V_31 , V_2 -> V_45 ,
F_12 ( V_46 ) ,
V_37 ) ;
F_74 ( V_2 -> V_47 ) ;
return - V_191 ;
}
static int F_75 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
F_76 ( & V_2 -> V_96 ) ;
F_77 ( V_17 ) ;
if ( V_2 -> V_165 )
F_78 ( V_2 -> V_165 ) ;
F_63 ( V_17 ) ;
F_43 ( V_2 ) ;
F_79 ( V_2 -> V_217 , V_17 ) ;
F_80 ( & V_2 -> V_44 ) ;
F_80 ( & V_2 -> V_27 ) ;
F_23 ( V_2 -> V_31 , V_2 -> V_36 ,
F_12 ( V_19 ) ,
V_37 ) ;
F_74 ( V_2 -> V_34 ) ;
F_23 ( V_2 -> V_31 , V_2 -> V_45 ,
F_12 ( V_46 ) ,
V_37 ) ;
F_74 ( V_2 -> V_47 ) ;
return 0 ;
}
static int F_81 ( struct V_22 * V_23 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
union V_15 V_21 ;
unsigned long V_6 ;
int V_236 = V_237 ;
V_21 . V_28 = 0 ;
V_21 . V_11 . V_29 = V_23 -> V_29 ;
V_21 . V_11 . V_30 = F_18 ( V_2 -> V_31 , V_23 -> V_32 ,
V_23 -> V_29 ,
V_50 ) ;
F_2 ( & V_2 -> V_44 . V_7 , V_6 ) ;
if ( F_82 ( V_2 -> V_49 >= F_11 ( V_46 ) - 1 ) ) {
F_5 ( & V_2 -> V_44 . V_7 , V_6 ) ;
F_77 ( V_17 ) ;
F_2 ( & V_2 -> V_44 . V_7 , V_6 ) ;
}
if ( F_82 ( V_2 -> V_49 >=
F_11 ( V_46 ) ) ) {
F_5 ( & V_2 -> V_44 . V_7 , V_6 ) ;
F_23 ( V_2 -> V_31 , V_21 . V_11 . V_30 , V_21 . V_11 . V_29 ,
V_50 ) ;
goto V_238;
}
F_17 ( & V_2 -> V_44 , V_23 ) ;
V_2 -> V_47 [ V_2 -> V_192 ] = V_21 . V_28 ;
V_2 -> V_192 = ( V_2 -> V_192 + 1 ) % V_46 ;
V_2 -> V_49 ++ ;
F_5 ( & V_2 -> V_44 . V_7 , V_6 ) ;
F_19 ( V_2 -> V_31 , V_2 -> V_45 ,
F_12 ( V_46 ) ,
V_37 ) ;
V_17 -> V_57 . V_239 ++ ;
V_17 -> V_57 . V_240 += V_23 -> V_29 ;
F_4 ( V_2 -> V_9 + V_241 , 1 ) ;
V_236 = V_242 ;
V_238:
F_29 ( V_17 ) ;
return V_236 ;
}
static void F_83 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
F_39 ( V_2 , 16 ) ;
F_28 ( V_17 ) ;
}
static void F_84 ( struct V_16 * V_17 ,
struct V_243 * V_244 )
{
strncpy ( V_244 -> V_245 , V_246 , sizeof( V_244 -> V_245 ) ) ;
strncpy ( V_244 -> V_247 , V_248 , sizeof( V_244 -> V_247 ) ) ;
strncpy ( V_244 -> V_249 , L_10 , sizeof( V_244 -> V_249 ) ) ;
strncpy ( V_244 -> V_250 , L_10 , sizeof( V_244 -> V_250 ) ) ;
V_244 -> V_251 = 0 ;
V_244 -> V_252 = 0 ;
V_244 -> V_253 = 0 ;
V_244 -> V_254 = 0 ;
}
static int F_85 ( struct V_16 * V_17 ,
struct V_255 * V_164 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
if ( V_2 -> V_165 )
return F_86 ( V_2 -> V_165 , V_164 ) ;
return - V_150 ;
}
static int F_87 ( struct V_16 * V_17 ,
struct V_255 * V_164 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
if ( ! F_88 ( V_256 ) )
return - V_257 ;
if ( V_2 -> V_165 )
return F_89 ( V_2 -> V_165 , V_164 ) ;
return - V_150 ;
}
static int T_2 F_90 ( struct V_258 * V_259 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
const T_3 * V_32 ;
const T_4 * V_260 ;
struct V_261 * V_262 ;
struct V_261 * V_263 ;
int V_29 ;
int V_264 ;
V_17 = F_91 ( sizeof( struct V_1 ) ) ;
if ( V_17 == NULL )
return - V_191 ;
F_92 ( & V_259 -> V_31 , V_17 ) ;
V_2 = F_14 ( V_17 ) ;
F_93 ( V_17 , & V_2 -> V_96 , F_40 ,
V_265 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_31 = & V_259 -> V_31 ;
V_32 = F_94 ( V_259 -> V_31 . V_266 , L_11 , & V_29 ) ;
if ( V_32 && V_29 == sizeof( * V_32 ) ) {
V_2 -> V_177 = F_95 ( V_32 ) ;
} else {
F_72 ( & V_259 -> V_31 , L_12 ) ;
V_264 = - V_267 ;
goto V_268;
}
snprintf ( V_17 -> V_172 , V_269 , L_13 , V_2 -> V_177 ) ;
V_264 = F_96 ( V_259 , 0 ) ;
if ( V_264 < 0 )
goto V_268;
V_2 -> V_217 = V_264 ;
V_262 = F_97 ( V_259 , V_270 , 0 ) ;
if ( V_262 == NULL ) {
F_72 ( & V_259 -> V_31 , L_14 ) ;
V_264 = - V_267 ;
goto V_268;
}
V_263 = F_97 ( V_259 , V_270 , 1 ) ;
if ( V_263 == NULL ) {
F_72 ( & V_259 -> V_31 , L_14 ) ;
V_264 = - V_267 ;
goto V_268;
}
V_2 -> V_271 = V_262 -> V_272 ;
V_2 -> V_273 = F_98 ( V_262 ) ;
V_2 -> V_274 = V_263 -> V_272 ;
V_2 -> V_275 = F_98 ( V_263 ) ;
if ( ! F_99 ( & V_259 -> V_31 , V_2 -> V_271 , V_2 -> V_273 ,
V_262 -> V_172 ) ) {
F_72 ( & V_259 -> V_31 , L_15 ,
V_262 -> V_172 ) ;
V_264 = - V_267 ;
goto V_268;
}
if ( ! F_99 ( & V_259 -> V_31 , V_2 -> V_274 , V_2 -> V_275 ,
V_263 -> V_172 ) ) {
V_264 = - V_267 ;
F_72 ( & V_259 -> V_31 , L_15 ,
V_263 -> V_172 ) ;
goto V_268;
}
V_2 -> V_9 = ( V_8 ) F_100 ( & V_259 -> V_31 , V_2 -> V_271 , V_2 -> V_273 ) ;
V_2 -> V_54 = ( V_8 ) F_100 ( & V_259 -> V_31 , V_2 -> V_274 , V_2 -> V_275 ) ;
F_101 ( & V_2 -> V_7 ) ;
F_102 ( & V_2 -> V_44 ) ;
F_102 ( & V_2 -> V_27 ) ;
F_103 ( & V_2 -> V_160 ,
F_27 , ( unsigned long ) V_2 ) ;
V_17 -> V_276 |= V_277 ;
V_17 -> V_278 = & V_279 ;
V_17 -> V_280 = & V_281 ;
V_260 = F_104 ( V_259 -> V_31 . V_266 ) ;
if ( V_260 )
memcpy ( V_17 -> V_130 , V_260 , 6 ) ;
V_2 -> V_175 = F_105 ( V_259 -> V_31 . V_266 , L_16 , 0 ) ;
V_259 -> V_31 . V_282 = F_106 ( 64 ) ;
V_259 -> V_31 . V_283 = & V_259 -> V_31 . V_282 ;
V_264 = F_107 ( V_17 ) ;
if ( V_264 )
goto V_268;
F_108 ( & V_259 -> V_31 , L_17 V_248 L_18 ) ;
return 0 ;
V_268:
F_109 ( V_17 ) ;
return V_264 ;
}
static int T_5 F_110 ( struct V_258 * V_259 )
{
struct V_16 * V_17 = F_111 ( & V_259 -> V_31 ) ;
F_112 ( V_17 ) ;
F_109 ( V_17 ) ;
return 0 ;
}
static int T_6 F_113 ( void )
{
F_114 () ;
return F_115 ( & V_284 ) ;
}
static void T_7 F_116 ( void )
{
F_117 ( & V_284 ) ;
}
