static inline T_1 F_1 ( int V_1 )
{
union V_2 V_3 ;
V_3 . V_4 = 0 ;
V_3 . V_5 . V_6 = 0 ;
V_3 . V_5 . V_5 = 1 ;
V_3 . V_5 . V_7 = 3 ;
V_3 . V_5 . V_8 = 2 ;
V_3 . V_5 . V_9 = 1 ;
V_3 . V_5 . V_10 = V_1 ;
return V_3 . V_4 ;
}
static inline T_1 F_2 ( int V_1 )
{
return 1ull << 32 ;
}
static inline T_1 F_3 ( int V_1 )
{
union V_2 V_3 ;
V_3 . V_4 = 0 ;
V_3 . V_11 . V_6 = 0 ;
V_3 . V_11 . V_5 = 1 ;
V_3 . V_11 . V_7 = 3 ;
V_3 . V_11 . V_8 = 3 + V_1 ;
return V_3 . V_4 ;
}
static inline T_1 F_4 ( int V_1 )
{
return 1ull << 36 ;
}
static T_2 F_5 ( int V_1 , T_2 V_12 )
{
if ( F_6 ( V_13 ) ) {
union V_14 V_15 ;
V_15 . V_4 = 0 ;
V_15 . V_16 . V_17 = V_12 ;
F_7 ( F_8 ( V_1 ) , V_15 . V_4 ) ;
V_15 . V_4 = F_9 ( F_8 ( V_1 ) ) ;
return V_15 . V_16 . V_18 ;
} else {
union V_19 V_20 ;
V_20 . V_4 = 0 ;
V_20 . V_16 . V_17 = V_12 ;
F_7 ( F_10 ( V_1 ) , V_20 . V_4 ) ;
V_20 . V_4 = F_9 ( F_10 ( V_1 ) ) ;
return V_20 . V_16 . V_18 ;
}
}
static void F_11 ( int V_1 , T_2 V_12 ,
T_2 V_21 )
{
if ( F_6 ( V_13 ) ) {
union V_22 V_23 ;
V_23 . V_4 = 0 ;
V_23 . V_16 . V_17 = V_12 ;
V_23 . V_16 . V_18 = V_21 ;
F_7 ( F_12 ( V_1 ) , V_23 . V_4 ) ;
} else {
union V_24 V_25 ;
V_25 . V_4 = 0 ;
V_25 . V_16 . V_17 = V_12 ;
V_25 . V_16 . V_18 = V_21 ;
F_7 ( F_13 ( V_1 ) , V_25 . V_4 ) ;
}
}
static inline T_1 F_14 ( int V_1 , int V_26 ,
int V_27 , int V_28 , int V_29 )
{
union V_2 V_3 ;
union V_30 V_31 ;
V_31 . V_32 =
F_5 ( V_1 , F_15 ( V_1 ) ) ;
if ( ( V_26 <= V_31 . V_16 . V_33 ) && ( V_27 != 0 ) )
return 0 ;
V_3 . V_4 = 0 ;
V_3 . V_34 . V_6 = 2 ;
V_3 . V_34 . V_5 = 1 ;
V_3 . V_34 . V_7 = 3 ;
V_3 . V_34 . V_8 = 1 ;
V_3 . V_34 . V_9 = 1 ;
V_3 . V_34 . V_10 = V_1 ;
V_3 . V_34 . V_35 = ( V_26 > V_31 . V_16 . V_33 ) ;
V_3 . V_34 . V_26 = V_26 ;
V_3 . V_34 . V_27 = V_27 ;
V_3 . V_34 . V_36 = V_28 ;
V_3 . V_34 . V_29 = V_29 ;
return V_3 . V_4 ;
}
static T_3 F_16 ( int V_1 , int V_26 , int V_27 ,
int V_28 , int V_29 )
{
T_1 V_37 =
F_14 ( V_1 , V_26 , V_27 , V_28 , V_29 ) ;
if ( V_37 )
return F_17 ( V_37 ) ;
else
return 0xff ;
}
static T_4 F_18 ( int V_1 , int V_26 , int V_27 ,
int V_28 , int V_29 )
{
T_1 V_37 =
F_14 ( V_1 , V_26 , V_27 , V_28 , V_29 ) ;
if ( V_37 )
return F_19 ( F_20 ( V_37 ) ) ;
else
return 0xffff ;
}
static T_2 F_21 ( int V_1 , int V_26 , int V_27 ,
int V_28 , int V_29 )
{
T_1 V_37 =
F_14 ( V_1 , V_26 , V_27 , V_28 , V_29 ) ;
if ( V_37 )
return F_22 ( F_23 ( V_37 ) ) ;
else
return 0xffffffff ;
}
static void F_24 ( int V_1 , int V_26 , int V_27 , int V_28 ,
int V_29 , T_3 V_21 )
{
T_1 V_37 =
F_14 ( V_1 , V_26 , V_27 , V_28 , V_29 ) ;
if ( V_37 )
F_25 ( V_37 , V_21 ) ;
}
static void F_26 ( int V_1 , int V_26 , int V_27 , int V_28 ,
int V_29 , T_4 V_21 )
{
T_1 V_37 =
F_14 ( V_1 , V_26 , V_27 , V_28 , V_29 ) ;
if ( V_37 )
F_27 ( V_37 , F_28 ( V_21 ) ) ;
}
static void F_29 ( int V_1 , int V_26 , int V_27 , int V_28 ,
int V_29 , T_2 V_21 )
{
T_1 V_37 =
F_14 ( V_1 , V_26 , V_27 , V_28 , V_29 ) ;
if ( V_37 )
F_30 ( V_37 , F_31 ( V_21 ) ) ;
}
static void F_32 ( int V_1 )
{
union V_38 V_39 ;
union V_40 V_41 ;
union V_42 V_43 ;
union V_44 V_45 ;
union V_30 V_31 ;
union V_46 V_47 ;
union V_48 V_49 ;
union V_50 V_51 ;
union V_52 V_53 ;
union V_54 V_55 ;
union V_56 V_57 ;
union V_58 V_59 ;
V_39 . V_32 = F_5 ( V_1 , F_33 ( V_1 ) ) ;
if ( F_34 ( V_60 ) ) {
V_39 . V_16 . V_61 = V_62 ;
V_39 . V_16 . V_63 = V_64 ;
} else {
V_39 . V_16 . V_61 = V_65 ;
V_39 . V_16 . V_63 = V_66 ;
}
V_39 . V_16 . V_67 = 1 ;
V_39 . V_16 . V_68 = 1 ;
V_39 . V_16 . V_69 = 1 ;
V_39 . V_16 . V_70 = 1 ;
V_39 . V_16 . V_71 = 1 ;
V_39 . V_16 . V_72 = 1 ;
F_11 ( V_1 , F_33 ( V_1 ) , V_39 . V_32 ) ;
if ( F_6 ( V_13 ) ) {
union V_73 V_74 ;
V_74 . V_4 = F_9 ( V_75 ) ;
V_74 . V_16 . V_61 = V_62 ;
V_74 . V_16 . V_63 = V_64 ;
if ( V_1 )
V_74 . V_16 . V_76 = 3 ;
else
V_74 . V_16 . V_77 = 3 ;
F_7 ( V_75 , V_74 . V_4 ) ;
} else {
union V_78 V_79 ;
union V_80 V_81 ;
V_79 . V_4 = F_9 ( F_35 ( V_1 ) ) ;
V_79 . V_16 . V_61 = V_65 ;
V_79 . V_16 . V_63 = V_66 ;
V_79 . V_16 . V_82 = 32 ;
F_7 ( F_35 ( V_1 ) , V_79 . V_4 ) ;
V_81 . V_4 = F_9 ( F_36 ( V_1 ) ) ;
V_81 . V_16 . V_63 = V_66 ;
F_7 ( F_36 ( V_1 ) , V_81 . V_4 ) ;
}
V_41 . V_32 = F_5 ( V_1 , F_37 ( V_1 ) ) ;
V_41 . V_16 . V_83 = 1 ;
V_41 . V_16 . V_84 = 1 ;
F_11 ( V_1 , F_37 ( V_1 ) , V_41 . V_32 ) ;
V_43 . V_32 = F_5 ( V_1 , F_38 ( V_1 ) ) ;
V_43 . V_16 . V_85 = 1 ;
V_43 . V_16 . V_86 = 1 ;
V_43 . V_16 . V_87 = 1 ;
V_43 . V_16 . V_88 = 1 ;
F_11 ( V_1 , F_38 ( V_1 ) , V_43 . V_32 ) ;
F_11 ( V_1 , F_39 ( V_1 ) , 0 ) ;
F_11 ( V_1 , F_40 ( V_1 ) , 0 ) ;
V_45 . V_32 = F_5 ( V_1 , F_41 ( V_1 ) ) ;
V_45 . V_16 . V_89 = 0 ;
F_11 ( V_1 , F_41 ( V_1 ) , V_45 . V_32 ) ;
V_31 . V_32 = 0 ;
V_31 . V_16 . V_33 = 1 ;
V_31 . V_16 . V_90 = 1 ;
V_31 . V_16 . V_91 = 1 ;
F_11 ( V_1 , F_15 ( V_1 ) , V_31 . V_32 ) ;
V_47 . V_32 = 0 ;
V_47 . V_16 . V_92 = 0x100 ;
V_47 . V_16 . V_93 = 0 ;
F_11 ( V_1 , F_42 ( V_1 ) , V_47 . V_32 ) ;
V_49 . V_32 = F_5 ( V_1 , F_43 ( V_1 ) ) ;
V_51 . V_32 = F_5 ( V_1 , F_44 ( V_1 ) ) ;
V_53 . V_32 = F_5 ( V_1 , F_45 ( V_1 ) ) ;
V_49 . V_16 . V_94 = 0x100 ;
V_49 . V_16 . V_95 = 0 ;
V_51 . V_16 . V_96 = 0x100 ;
V_53 . V_16 . V_97 = 0 ;
F_11 ( V_1 , F_43 ( V_1 ) , V_49 . V_32 ) ;
F_11 ( V_1 , F_44 ( V_1 ) , V_51 . V_32 ) ;
F_11 ( V_1 , F_45 ( V_1 ) , V_53 . V_32 ) ;
V_55 . V_32 = F_5 ( V_1 , F_46 ( V_1 ) ) ;
V_55 . V_16 . V_98 = 1 ;
V_55 . V_16 . V_99 = 1 ;
V_55 . V_16 . V_100 = 1 ;
V_55 . V_16 . V_101 = 1 ;
F_11 ( V_1 , F_46 ( V_1 ) , V_55 . V_32 ) ;
V_57 . V_32 = F_5 ( V_1 , F_47 ( V_1 ) ) ;
V_57 . V_16 . V_102 = 1 ;
V_57 . V_16 . V_103 = 1 ;
V_57 . V_16 . V_104 = 1 ;
F_11 ( V_1 , F_47 ( V_1 ) , V_57 . V_32 ) ;
V_59 . V_32 = F_5 ( V_1 , F_48 ( V_1 ) ) ;
V_59 . V_16 . V_105 = 1 ;
V_59 . V_16 . V_106 = 1 ;
V_59 . V_16 . V_107 = 1 ;
F_11 ( V_1 , F_48 ( V_1 ) , V_59 . V_32 ) ;
}
static int F_49 ( int V_1 )
{
T_1 V_108 ;
union V_109 V_110 ;
union V_111 V_112 ;
union V_44 V_45 ;
union V_113 V_114 ;
V_112 . V_32 = F_5 ( V_1 , F_50 ( V_1 ) ) ;
V_110 . V_4 = F_9 ( F_51 ( V_1 ) ) ;
if ( V_110 . V_16 . V_115 == 0 )
V_112 . V_16 . V_116 = 0xf ;
else
V_112 . V_16 . V_116 = 0x7 ;
F_11 ( V_1 , F_50 ( V_1 ) , V_112 . V_32 ) ;
if ( F_34 ( V_117 ) ) {
union V_118 V_119 ;
V_119 . V_32 = F_5 ( V_1 , F_52 ( V_1 ) ) ;
V_119 . V_16 . V_120 = 1 ;
F_11 ( V_1 , F_52 ( V_1 ) , V_119 . V_32 ) ;
}
if ( F_34 ( V_121 ) && ( V_1 == 1 ) ) {
V_110 . V_16 . V_122 = 1 ;
F_7 ( F_51 ( V_1 ) , V_110 . V_4 ) ;
}
V_110 . V_4 = F_9 ( F_51 ( V_1 ) ) ;
V_110 . V_16 . V_123 = 1 ;
F_7 ( F_51 ( V_1 ) , V_110 . V_4 ) ;
if ( F_34 ( V_124 ) )
F_53 ( 0 ) ;
V_108 = F_54 () ;
do {
if ( F_54 () - V_108 > 2 * F_55 () ) {
F_56 ( L_1 , V_1 ) ;
return - 1 ;
}
F_57 ( 10000 ) ;
V_45 . V_32 = F_5 ( V_1 , F_41 ( V_1 ) ) ;
} while ( V_45 . V_16 . V_125 == 0 );
F_7 ( V_126 , F_9 ( V_126 ) ) ;
V_114 . V_32 = F_5 ( V_1 , F_58 ( V_1 ) ) ;
switch ( V_45 . V_16 . V_127 ) {
case 1 :
V_114 . V_16 . V_128 = 1677 ;
break;
case 2 :
V_114 . V_16 . V_128 = 867 ;
break;
case 4 :
V_114 . V_16 . V_128 = 462 ;
break;
case 8 :
V_114 . V_16 . V_128 = 258 ;
break;
}
F_11 ( V_1 , F_58 ( V_1 ) , V_114 . V_32 ) ;
return 0 ;
}
static void F_59 ( union V_129 * V_130 )
{
if ( F_34 ( V_131 ) )
V_130 -> V_132 . V_133 ++ ;
else
V_130 -> V_134 . V_133 ++ ;
}
static int F_60 ( int V_1 )
{
int V_135 ;
int V_136 ;
V_4 V_137 ;
union V_138 V_139 ;
union V_140 V_141 ;
union V_142 V_143 ;
union V_144 V_145 ;
union V_146 V_147 ;
union V_148 V_149 ;
union V_150 V_151 ;
union V_152 V_153 ;
union V_44 V_45 ;
union V_154 V_155 ;
V_156:
V_145 . V_4 = F_9 ( V_157 ) ;
if ( ( V_1 == 0 ) && ! V_145 . V_16 . V_158 ) {
F_56 ( L_2 , V_1 ) ;
return - 1 ;
}
if ( F_34 ( V_121 ) ) {
V_151 . V_4 = F_9 ( V_159 ) ;
if ( ( V_1 == 1 ) && V_151 . V_160 . V_161 ) {
F_56 ( L_3 ) ;
return - 1 ;
}
}
V_145 . V_16 . V_162 = 1 ;
V_145 . V_16 . V_163 = 0x20 ;
if ( F_34 ( V_117 ) ) {
V_145 . V_16 . V_164 = 0x20 ;
V_145 . V_16 . V_165 = 0x20 ;
}
F_7 ( V_157 , V_145 . V_4 ) ;
if ( F_61 () -> V_166 == V_167 ) {
if ( V_1 == 0 ) {
V_139 . V_4 = F_9 ( V_168 ) ;
if ( V_139 . V_16 . V_169 == 0 ) {
V_139 . V_16 . V_169 = 1 ;
F_7 ( V_168 , V_139 . V_4 ) ;
V_139 . V_4 = F_9 ( V_170 ) ;
V_139 . V_16 . V_169 = 1 ;
F_7 ( V_170 , V_139 . V_4 ) ;
F_62 ( 2000 ) ;
}
V_139 . V_4 = F_9 ( V_170 ) ;
V_139 . V_16 . V_169 = 0 ;
F_7 ( V_170 , V_139 . V_4 ) ;
V_139 . V_4 = F_9 ( V_168 ) ;
V_139 . V_16 . V_169 = 0 ;
F_7 ( V_168 , V_139 . V_4 ) ;
}
} else {
if ( V_1 )
V_139 . V_4 = F_9 ( V_170 ) ;
else
V_139 . V_4 = F_9 ( V_168 ) ;
if ( V_139 . V_16 . V_169 == 0 ) {
V_139 . V_16 . V_169 = 1 ;
if ( V_1 )
F_7 ( V_170 , V_139 . V_4 ) ;
else
F_7 ( V_168 , V_139 . V_4 ) ;
F_62 ( 2000 ) ;
}
if ( V_1 ) {
V_139 . V_4 = F_9 ( V_170 ) ;
V_139 . V_16 . V_169 = 0 ;
F_7 ( V_170 , V_139 . V_4 ) ;
} else {
V_139 . V_4 = F_9 ( V_168 ) ;
V_139 . V_16 . V_169 = 0 ;
F_7 ( V_168 , V_139 . V_4 ) ;
}
}
F_57 ( 400000 ) ;
if ( ! F_34 ( V_171 ) && ! F_34 ( V_117 ) ) {
V_153 . V_4 = F_9 ( F_63 ( V_1 ) ) ;
V_153 . V_16 . V_172 = 1 ;
F_7 ( F_63 ( V_1 ) , V_153 . V_4 ) ;
if ( F_64 ( F_63 ( V_1 ) ,
union V_152 , V_172 , == , 1 , 10000 ) ) {
F_56 ( L_4 , V_1 ) ;
return - 1 ;
}
}
V_153 . V_4 = F_9 ( F_63 ( V_1 ) ) ;
if ( V_153 . V_16 . V_173 ) {
F_56 ( L_5 , V_1 ) ;
return - 1 ;
}
V_143 . V_4 = F_9 ( F_65 ( V_1 ) ) ;
if ( V_143 . V_4 ) {
F_56 ( L_6 ,
V_1 ) ;
return - 1 ;
}
V_141 . V_4 = F_9 ( F_66 ( V_1 ) ) ;
if ( V_141 . V_4 )
F_56 ( L_7 ,
V_1 , F_67 ( V_141 . V_4 ) ) ;
F_32 ( V_1 ) ;
if ( F_49 ( V_1 ) ) {
F_56 ( L_8 ,
V_1 ) ;
return - 1 ;
}
V_147 . V_4 = F_9 ( V_174 ) ;
V_147 . V_16 . V_175 = 0 ;
V_147 . V_16 . V_176 = 127 ;
F_7 ( V_174 , V_147 . V_4 ) ;
V_149 . V_4 = 0 ;
V_149 . V_16 . V_10 = V_1 ;
V_149 . V_16 . V_177 = 1 ;
V_149 . V_16 . V_178 = 1 ;
V_149 . V_16 . V_179 = 1 ;
V_149 . V_16 . V_180 = 0 ;
V_149 . V_16 . V_181 = 0 ;
V_149 . V_16 . V_182 = 0 ;
V_149 . V_16 . V_183 = 0 ;
V_149 . V_16 . V_133 = 0 ;
for ( V_135 = 12 + V_1 * 4 ; V_135 < 16 + V_1 * 4 ; V_135 ++ ) {
F_7 ( F_68 ( V_135 ) , V_149 . V_4 ) ;
V_149 . V_16 . V_133 += 1 ;
}
for ( V_135 = 0 ; V_135 < 4 ; V_135 ++ ) {
F_7 ( F_69 ( V_135 , V_1 ) , - 1 ) ;
F_7 ( F_70 ( V_135 , V_1 ) , - 1 ) ;
}
F_7 ( F_71 ( V_1 ) , 0 ) ;
F_7 ( F_72 ( V_1 ) , V_184 ) ;
V_155 . V_32 = 0 ;
V_155 . V_16 . V_185 = ( V_186 >> 22 ) ;
V_155 . V_16 . V_187 = 1 ;
V_155 . V_16 . V_188 = 1 ;
V_155 . V_16 . V_189 = 1 ;
V_136 = V_1 ? 16 : 0 ;
#ifdef F_73
V_137 = 4 ;
#else
V_137 = 0 ;
#endif
for ( V_135 = 0 ; V_135 < 16 ; V_135 ++ ) {
F_30 ( ( F_74 ( V_136 ) ^ V_137 ) ,
V_155 . V_32 ) ;
V_136 ++ ;
V_155 . V_16 . V_185 += ( ( ( 1ull << 28 ) / 16ull ) >> 22 ) ;
}
F_7 ( F_75 ( V_1 ) , 0 ) ;
if ( V_1 ) {
union V_190 V_191 ;
V_191 . V_4 = F_9 ( V_192 ) ;
V_191 . V_16 . V_193 = 1 ;
V_191 . V_16 . V_194 = 1 ;
V_191 . V_16 . V_195 = 0 ;
V_191 . V_16 . V_196 = 1 ;
V_191 . V_16 . V_197 = 1 ;
V_191 . V_16 . V_198 = 0 ;
V_191 . V_16 . V_199 = 0 ;
F_7 ( V_192 , V_191 . V_4 ) ;
} else {
union V_200 V_191 ;
V_191 . V_4 = F_9 ( V_201 ) ;
V_191 . V_16 . V_193 = 1 ;
V_191 . V_16 . V_194 = 1 ;
V_191 . V_16 . V_195 = 0 ;
V_191 . V_16 . V_196 = 1 ;
V_191 . V_16 . V_197 = 1 ;
V_191 . V_16 . V_198 = 0 ;
V_191 . V_16 . V_199 = 0 ;
F_7 ( V_201 , V_191 . V_4 ) ;
}
if ( F_34 ( V_202 ) ||
F_34 ( V_203 ) ||
F_34 ( V_171 ) ||
F_34 ( V_117 ) ) {
union V_150 V_204 ;
int V_205 ;
int V_206 ;
int V_207 ;
int V_208 = ( F_34 ( V_117 ) || F_34 ( V_171 ) ) ? 4 : 1 ;
int V_135 ;
T_1 V_209 = ( F_3 ( V_1 ) + 0x100000 ) | ( 1ull << 63 ) ;
V_135 = V_208 ;
while ( V_135 -- ) {
F_30 ( V_209 , 0 ) ;
F_57 ( 10000 ) ;
}
F_7 ( V_210 , ( V_1 ) ? 0xd7fc : 0xcffc ) ;
F_9 ( V_210 ) ;
do {
V_204 . V_4 = F_9 ( V_159 ) ;
V_205 = V_204 . V_16 . V_18 & 0xff ;
F_30 ( V_209 , 0 ) ;
F_57 ( 10000 ) ;
V_204 . V_4 = F_9 ( V_159 ) ;
V_206 = V_204 . V_16 . V_18 & 0xff ;
} while ( V_206 != ( ( V_205 + 1 ) & 0xff ) );
V_206 = ( V_206 + V_208 ) & 0xff ;
F_7 ( V_210 , ( V_1 ) ? 0xd00f : 0xc80f ) ;
F_9 ( V_210 ) ;
V_204 . V_4 = F_9 ( V_159 ) ;
V_207 = ( V_204 . V_16 . V_18 >> 1 ) & 0xff ;
if ( V_207 != V_206 ) {
F_56 ( L_9 , V_1 ) ;
while ( V_206 != 0 ) {
F_30 ( V_209 , 0 ) ;
F_57 ( 10000 ) ;
V_206 = ( V_206 + 1 ) & 0xff ;
}
if ( ( F_61 () -> V_166 == V_167 ) &&
( V_1 == 1 ) )
F_76 ( 0 ) ;
goto V_156;
}
}
V_45 . V_32 = F_5 ( V_1 , F_41 ( V_1 ) ) ;
F_56 ( L_10 , V_1 , V_45 . V_16 . V_127 ) ;
return 0 ;
}
static int F_77 ( int V_1 )
{
T_1 V_108 ;
union V_211 V_212 ;
union V_44 V_45 ;
union V_113 V_114 ;
V_212 . V_4 = F_9 ( F_78 ( V_1 ) ) ;
V_212 . V_16 . V_123 = 1 ;
F_7 ( F_78 ( V_1 ) , V_212 . V_4 ) ;
V_108 = F_54 () ;
do {
if ( F_54 () - V_108 > F_55 () )
return - 1 ;
F_57 ( 10000 ) ;
V_45 . V_32 = F_5 ( V_1 , F_41 ( V_1 ) ) ;
} while ( ( V_45 . V_16 . V_125 == 0 ) || ( V_45 . V_16 . V_213 == 1 ) );
V_114 . V_32 = F_5 ( V_1 , F_58 ( V_1 ) ) ;
switch ( V_45 . V_16 . V_127 ) {
case 1 :
V_114 . V_16 . V_128 = 1677 ;
break;
case 2 :
V_114 . V_16 . V_128 = 867 ;
break;
case 4 :
V_114 . V_16 . V_128 = 462 ;
break;
case 8 :
V_114 . V_16 . V_128 = 258 ;
break;
}
F_11 ( V_1 , F_58 ( V_1 ) , V_114 . V_32 ) ;
return 0 ;
}
static int F_79 ( int V_1 )
{
int V_135 ;
union V_138 V_139 ;
union V_214 V_215 ;
union V_216 V_217 ;
union V_211 V_218 ;
union V_219 V_220 ;
union V_221 V_222 ;
union V_44 V_45 ;
union V_223 V_224 ;
union V_225 V_226 ;
union V_227 V_228 ;
union V_129 V_149 ;
union V_229 V_230 ;
union V_231 V_155 ;
if ( F_6 ( V_232 ) ) {
if ( F_34 ( V_233 ) ) {
union V_234 V_235 ;
V_235 . V_4 = F_9 ( F_80 ( V_1 ) ) ;
if ( V_235 . V_16 . V_236 == 15 ) {
F_81 ( L_11 , V_1 ) ;
return - 1 ;
}
switch ( V_235 . V_16 . V_236 ) {
case 0x1 :
case 0x3 :
case 0x4 :
case 0x6 :
F_81 ( L_12 , V_1 ) ;
return - 1 ;
case 0x9 :
F_81 ( L_13 , V_1 ) ;
return - 1 ;
case 0xb :
F_81 ( L_14 , V_1 ) ;
return - 1 ;
case 0x0 :
case 0x8 :
case 0x2 :
case 0xa :
break;
default:
F_81 ( L_15 , V_1 ) ;
return - 1 ;
}
} else {
V_230 . V_4 = F_9 ( F_82 ( V_1 ) ) ;
if ( V_230 . V_16 . V_237 ) {
F_81 ( L_12 , V_1 ) ;
return - 1 ;
}
}
}
#if 0
pr_notice("PCIE : init for pcie analyzer.\n");
cvmx_helper_qlm_jtag_init();
cvmx_helper_qlm_jtag_shift_zeros(pcie_port, 85);
cvmx_helper_qlm_jtag_shift(pcie_port, 1, 1);
cvmx_helper_qlm_jtag_shift_zeros(pcie_port, 300-86);
cvmx_helper_qlm_jtag_shift_zeros(pcie_port, 85);
cvmx_helper_qlm_jtag_shift(pcie_port, 1, 1);
cvmx_helper_qlm_jtag_shift_zeros(pcie_port, 300-86);
cvmx_helper_qlm_jtag_shift_zeros(pcie_port, 85);
cvmx_helper_qlm_jtag_shift(pcie_port, 1, 1);
cvmx_helper_qlm_jtag_shift_zeros(pcie_port, 300-86);
cvmx_helper_qlm_jtag_shift_zeros(pcie_port, 85);
cvmx_helper_qlm_jtag_shift(pcie_port, 1, 1);
cvmx_helper_qlm_jtag_shift_zeros(pcie_port, 300-86);
cvmx_helper_qlm_jtag_update(pcie_port);
#endif
V_215 . V_4 = F_9 ( F_83 ( V_1 ) ) ;
if ( ! V_215 . V_16 . V_158 ) {
F_81 ( L_16 , V_1 ) ;
return - 1 ;
}
if ( F_34 ( V_238 ) ) {
if ( V_1 ) {
union V_239 V_240 ;
V_240 . V_4 = F_9 ( V_241 ) ;
V_240 . V_16 . V_242 = 1 ;
V_240 . V_16 . V_243 = 5 ;
V_240 . V_16 . V_244 = 0x17 ;
F_7 ( V_241 , V_240 . V_4 ) ;
} else {
union V_245 V_240 ;
V_240 . V_4 = F_9 ( V_246 ) ;
V_240 . V_16 . V_242 = 1 ;
V_240 . V_16 . V_243 = 5 ;
V_240 . V_16 . V_244 = 0x17 ;
F_7 ( V_246 , V_240 . V_4 ) ;
}
}
if ( V_1 )
V_139 . V_4 = F_9 ( V_170 ) ;
else
V_139 . V_4 = F_9 ( V_168 ) ;
if ( V_139 . V_16 . V_169 == 0 ) {
V_139 . V_16 . V_169 = 1 ;
if ( V_1 )
F_7 ( V_170 , V_139 . V_4 ) ;
else
F_7 ( V_168 , V_139 . V_4 ) ;
F_62 ( 2000 ) ;
}
if ( V_1 ) {
V_139 . V_4 = F_9 ( V_170 ) ;
V_139 . V_16 . V_169 = 0 ;
F_7 ( V_170 , V_139 . V_4 ) ;
} else {
V_139 . V_4 = F_9 ( V_168 ) ;
V_139 . V_16 . V_169 = 0 ;
F_7 ( V_168 , V_139 . V_4 ) ;
}
F_62 ( 1000 ) ;
if ( F_64 ( F_83 ( V_1 ) , union V_214 , V_247 , == , 1 , 10000 ) ) {
F_81 ( L_5 , V_1 ) ;
return - 1 ;
}
V_220 . V_4 = F_9 ( F_84 ( V_1 ) ) ;
if ( V_220 . V_4 )
F_81 ( L_7 , V_1 , F_67 ( V_220 . V_4 ) ) ;
V_222 . V_4 = F_9 ( F_85 ( V_1 ) ) ;
if ( F_34 ( V_248 ) )
V_222 . V_4 &= ~ 0x3full ;
if ( V_222 . V_4 )
F_81 ( L_17 , V_1 , F_67 ( V_222 . V_4 ) ) ;
F_32 ( V_1 ) ;
V_224 . V_32 = F_5 ( V_1 , F_86 ( V_1 ) ) ;
V_224 . V_16 . V_249 = 1 ;
F_11 ( V_1 , F_86 ( V_1 ) , V_224 . V_32 ) ;
if ( F_77 ( V_1 ) ) {
union V_250 V_251 ;
V_251 . V_32 = F_5 ( V_1 , F_87 ( V_1 ) ) ;
V_251 . V_16 . V_252 = 1 ;
F_11 ( V_1 , F_87 ( V_1 ) , V_251 . V_32 ) ;
if ( F_77 ( V_1 ) ) {
F_81 ( L_18 , V_1 ) ;
return - 1 ;
}
}
V_228 . V_4 = F_9 ( V_253 ) ;
V_228 . V_16 . V_175 = 0 ;
V_228 . V_16 . V_176 = 127 ;
F_7 ( V_253 , V_228 . V_4 ) ;
V_149 . V_4 = 0 ;
V_149 . V_16 . V_10 = V_1 ;
V_149 . V_16 . V_177 = 0 ;
V_149 . V_16 . V_178 = 1 ;
V_149 . V_16 . V_179 = 1 ;
V_149 . V_16 . V_254 = 0 ;
V_149 . V_16 . V_255 = 0 ;
if ( F_34 ( V_131 ) )
V_149 . V_132 . V_133 = 0 ;
else
V_149 . V_134 . V_133 = 0 ;
for ( V_135 = 12 + V_1 * 4 ; V_135 < 16 + V_1 * 4 ; V_135 ++ ) {
F_7 ( F_88 ( V_135 ) , V_149 . V_4 ) ;
F_59 ( & V_149 ) ;
}
for ( V_135 = 0 ; V_135 < 4 ; V_135 ++ ) {
F_7 ( F_89 ( V_135 , V_1 ) , - 1 ) ;
F_7 ( F_90 ( V_135 , V_1 ) , - 1 ) ;
}
F_7 ( F_91 ( V_1 ) , 0 ) ;
F_7 ( F_92 ( V_1 ) , 0 ) ;
V_217 . V_4 = F_9 ( F_93 ( V_1 ) ) ;
V_217 . V_16 . V_256 = 3 ;
V_217 . V_16 . V_193 = 1 ;
V_217 . V_16 . V_194 = 1 ;
V_217 . V_16 . V_195 = 0 ;
F_7 ( F_93 ( V_1 ) , V_217 . V_4 ) ;
V_226 . V_4 = F_9 ( F_94 ( V_1 ) ) ;
V_226 . V_16 . V_196 = 1 ;
V_226 . V_16 . V_197 = 1 ;
V_226 . V_16 . V_198 = 0 ;
V_226 . V_16 . V_199 = 0 ;
F_7 ( F_94 ( V_1 ) , V_226 . V_4 ) ;
F_7 ( F_95 ( V_1 ) , V_184 ) ;
V_155 . V_4 = 0 ;
V_155 . V_16 . V_185 = ( V_186 >> 22 ) ;
V_155 . V_16 . V_187 = 1 ;
V_155 . V_16 . V_188 = 1 ;
V_155 . V_16 . V_189 = 1 ;
for ( V_135 = 0 ; V_135 < 16 ; V_135 ++ ) {
F_7 ( F_96 ( V_135 , V_1 ) , V_155 . V_4 ) ;
V_155 . V_16 . V_185 += ( ( ( 1ull << 28 ) / 16ull ) >> 22 ) ;
}
V_218 . V_4 = F_9 ( F_78 ( V_1 ) ) ;
V_218 . V_16 . V_163 = 250 * 5000000 / 0x10000 ;
F_7 ( F_78 ( V_1 ) , V_218 . V_4 ) ;
V_45 . V_32 = F_5 ( V_1 , F_41 ( V_1 ) ) ;
F_81 ( L_19 , V_1 , V_45 . V_16 . V_127 , V_45 . V_16 . V_257 ) ;
return 0 ;
}
static int F_76 ( int V_1 )
{
int V_258 ;
if ( F_6 ( V_13 ) )
V_258 = F_60 ( V_1 ) ;
else
V_258 = F_79 ( V_1 ) ;
return V_258 ;
}
int T_5 F_97 ( const struct V_259 * V_27 ,
T_6 V_260 , T_6 V_261 )
{
if ( strstr ( F_98 () , L_20 ) &&
V_27 -> V_26 && V_27 -> V_26 -> V_262 ) {
while ( V_27 -> V_26 && V_27 -> V_26 -> V_262 )
V_27 = F_99 ( V_27 -> V_26 -> V_263 ) ;
if ( ( V_27 -> V_26 -> V_264 == 1 ) &&
( V_27 -> V_265 == 0x10b5 ) && ( V_27 -> V_266 == 0x8114 ) ) {
V_261 = ( ( V_261 - 3 ) & 3 ) + 1 ;
}
}
return V_261 - 1 + V_267 ;
}
static void F_100 ( V_32 V_268 )
{
union V_211 V_269 ;
V_269 . V_4 = F_9 ( F_78 ( 1 ) ) ;
V_269 . V_16 . V_163 = V_268 ;
F_7 ( F_78 ( 1 ) , V_269 . V_4 ) ;
}
static V_32 F_101 ( void )
{
V_32 V_268 ;
union V_211 V_269 ;
V_269 . V_4 = F_9 ( F_78 ( 1 ) ) ;
V_268 = V_269 . V_16 . V_163 ;
V_269 . V_16 . V_163 = 0 ;
F_7 ( F_78 ( 1 ) , V_269 . V_4 ) ;
return V_268 ;
}
static int F_102 ( void )
{
union V_270 V_271 ;
V_271 . V_4 = F_9 ( F_103 ( 1 ) ) ;
if ( V_271 . V_16 . V_272 )
return 1 ;
return 0 ;
}
static int F_104 ( unsigned int V_1 , struct V_273 * V_26 ,
unsigned int V_274 , int V_29 , int V_275 ,
V_32 * V_21 )
{
union V_276 V_277 ;
union V_276 V_278 ;
int V_279 = V_26 -> V_264 ;
int V_280 = 0 ;
int V_268 = 0 ;
int V_281 = 10 ;
V_32 V_282 = 0 ;
V_278 . V_4 = 0 ;
F_105 ( V_1 >= F_106 ( V_283 ) ) ;
if ( V_26 -> V_262 == NULL ) {
if ( V_283 [ V_1 ] )
V_279 = 0 ;
else {
union V_30 V_31 ;
V_31 . V_32 = F_5 ( V_1 ,
F_15 ( V_1 ) ) ;
if ( V_31 . V_16 . V_33 != V_279 ) {
V_31 . V_16 . V_33 = V_279 ;
V_31 . V_16 . V_90 = V_279 ;
V_31 . V_16 . V_91 = V_279 ;
F_11 ( V_1 ,
F_15 ( V_1 ) ,
V_31 . V_32 ) ;
}
}
}
if ( ( V_26 -> V_262 == NULL ) && ( V_274 >> 3 != 0 ) )
return V_284 ;
if ( F_34 ( V_285 ) ||
F_34 ( V_286 ) ) {
if ( ( V_26 -> V_262 == NULL ) && ( V_274 >= 2 ) )
return V_284 ;
#if 1
if ( V_279 == 2 )
return V_284 ;
#elif 0
if ( ( V_279 == 2 ) && ( V_274 >> 3 != 2 ) )
return V_284 ;
#elif 0
if ( ( V_279 == 2 ) && ( V_274 >> 3 != 3 ) )
return V_284 ;
#elif 0
if ( ( V_279 == 2 ) &&
! ( ( V_274 == ( 2 << 3 ) ) || ( V_274 == ( 3 << 3 ) ) ) )
return V_284 ;
#endif
#if 0
if ((bus_number == 4) &&
!((devfn >> 3 >= 1) && (devfn >> 3 <= 4)))
return PCIBIOS_FUNC_NOT_SUPPORTED;
if ((bus_number == 5) && (devfn >> 3 != 0))
return PCIBIOS_FUNC_NOT_SUPPORTED;
if ((bus_number == 6) && (devfn >> 3 != 0))
return PCIBIOS_FUNC_NOT_SUPPORTED;
if ((bus_number == 7) && (devfn >> 3 != 0))
return PCIBIOS_FUNC_NOT_SUPPORTED;
if ((bus_number == 8) && (devfn >> 3 != 0))
return PCIBIOS_FUNC_NOT_SUPPORTED;
#endif
V_278 . V_4 = F_107 ( V_287 , 7 ) ;
V_277 . V_4 = V_278 . V_4 ;
V_277 . V_16 . V_288 = 2 ;
F_108 ( V_287 , 7 , V_277 . V_4 ) ;
}
if ( ( F_34 ( V_289 ) ) && ( V_290 ) )
V_282 = F_101 () ;
F_109 ( L_21
L_22 , V_1 , V_279 , V_274 , V_29 , V_275 ) ;
do {
switch ( V_275 ) {
case 4 :
* V_21 = F_21 ( V_1 , V_279 ,
V_274 >> 3 , V_274 & 0x7 , V_29 ) ;
break;
case 2 :
* V_21 = F_18 ( V_1 , V_279 ,
V_274 >> 3 , V_274 & 0x7 , V_29 ) ;
break;
case 1 :
* V_21 = F_16 ( V_1 , V_279 ,
V_274 >> 3 , V_274 & 0x7 , V_29 ) ;
break;
default:
if ( F_34 ( V_289 ) )
F_100 ( V_282 ) ;
return V_284 ;
}
if ( ( F_34 ( V_289 ) ) &&
( V_290 ) ) {
V_280 = F_102 () ;
V_268 ++ ;
if ( V_268 > V_281 ) {
F_110 ( L_23 ,
V_268 ) ;
V_280 = 0 ;
}
}
} while ( V_280 );
if ( ( F_34 ( V_289 ) ) && ( V_290 ) )
F_100 ( V_282 ) ;
F_109 ( L_24 , * V_21 , V_268 ) ;
if ( F_34 ( V_285 ) ||
F_34 ( V_286 ) )
F_111 ( V_278 . V_4 ) ;
return V_291 ;
}
static int F_112 ( struct V_273 * V_26 , unsigned int V_274 ,
int V_29 , int V_275 , V_32 * V_21 )
{
return F_104 ( 0 , V_26 , V_274 , V_29 , V_275 , V_21 ) ;
}
static int F_113 ( struct V_273 * V_26 , unsigned int V_274 ,
int V_29 , int V_275 , V_32 * V_21 )
{
return F_104 ( 1 , V_26 , V_274 , V_29 , V_275 , V_21 ) ;
}
static int F_114 ( struct V_273 * V_26 , unsigned int V_274 ,
int V_29 , int V_275 , V_32 * V_21 )
{
return V_284 ;
}
static int F_115 ( unsigned int V_1 , struct V_273 * V_26 ,
unsigned int V_274 , int V_29 ,
int V_275 , V_32 V_21 )
{
int V_279 = V_26 -> V_264 ;
F_105 ( V_1 >= F_106 ( V_283 ) ) ;
if ( ( V_26 -> V_262 == NULL ) && ( V_283 [ V_1 ] ) )
V_279 = 0 ;
F_109 ( L_25
L_26 , V_1 , V_279 , V_274 ,
V_29 , V_275 , V_21 ) ;
switch ( V_275 ) {
case 4 :
F_29 ( V_1 , V_279 , V_274 >> 3 ,
V_274 & 0x7 , V_29 , V_21 ) ;
break;
case 2 :
F_26 ( V_1 , V_279 , V_274 >> 3 ,
V_274 & 0x7 , V_29 , V_21 ) ;
break;
case 1 :
F_24 ( V_1 , V_279 , V_274 >> 3 ,
V_274 & 0x7 , V_29 , V_21 ) ;
break;
default:
return V_284 ;
}
#if V_292
F_62 ( V_292 ) ;
#endif
return V_291 ;
}
static int F_116 ( struct V_273 * V_26 , unsigned int V_274 ,
int V_29 , int V_275 , V_32 V_21 )
{
return F_115 ( 0 , V_26 , V_274 , V_29 , V_275 , V_21 ) ;
}
static int F_117 ( struct V_273 * V_26 , unsigned int V_274 ,
int V_29 , int V_275 , V_32 V_21 )
{
return F_115 ( 1 , V_26 , V_274 , V_29 , V_275 , V_21 ) ;
}
static int F_118 ( struct V_273 * V_26 , unsigned int V_274 ,
int V_29 , int V_275 , V_32 V_21 )
{
return V_284 ;
}
static int F_119 ( T_2 V_293 )
{
#define F_120 0x111d
if ( ( V_293 & 0xffff ) == F_120 )
return 1 ;
return 0 ;
}
static int T_5 F_121 ( void )
{
int V_258 ;
int V_158 ;
int V_294 = 0 , V_10 ;
union V_225 V_226 ;
union V_229 V_230 ;
if ( ! F_6 ( V_295 ) )
return 0 ;
if ( F_122 () )
return 0 ;
if ( V_296 )
return 0 ;
V_297 = F_97 ;
F_123 ( F_124 ( F_1 ( 0 ) ) ) ;
V_298 . V_299 = 0 ;
V_298 . V_300 =
F_1 ( 1 ) -
F_1 ( 0 ) + F_2 ( 1 ) - 1 ;
V_301 . V_302 = - 1 ;
V_301 . V_303 -> V_299 = ( 1ull << 48 ) ;
V_301 . V_303 -> V_300 = ( 1ull << 48 ) ;
F_125 ( & V_301 ) ;
if ( F_6 ( V_13 ) ) {
union V_144 V_145 ;
V_145 . V_4 = F_9 ( V_157 ) ;
V_158 = V_145 . V_16 . V_158 ;
V_304 = V_305 ;
} else {
union V_214 V_215 ;
V_215 . V_4 = F_9 ( F_83 ( 0 ) ) ;
V_158 = V_215 . V_16 . V_158 ;
V_304 = V_306 ;
}
if ( V_158 ) {
F_81 ( L_27 ) ;
if ( F_34 ( V_248 ) ||
F_34 ( V_307 ) ) {
V_230 . V_4 = F_9 ( F_82 ( 0 ) ) ;
if ( V_230 . V_16 . V_237 ) {
V_294 += 1 ;
V_10 = 0 ;
}
}
V_258 = F_76 ( 0 ) ;
if ( V_258 == 0 ) {
T_2 V_308 ;
V_309 . V_310 =
F_3 ( 0 ) ;
V_309 . V_302 =
F_124 ( F_1
( 0 ) ) ;
V_309 . V_311 = 0 ;
V_309 . V_303 -> V_299 =
F_3 ( 0 ) +
( 4ul << 30 ) - ( V_312 << 20 ) ;
V_309 . V_303 -> V_300 =
F_3 ( 0 ) +
F_4 ( 0 ) - 1 ;
V_309 . V_313 -> V_299 = 4 << 10 ;
V_309 . V_313 -> V_300 =
F_2 ( 0 ) - 1 ;
F_126 ( 100 ) ;
F_125 ( & V_309 ) ;
V_308 = F_21 ( 0 , 0 , 0 , 0 , 0 ) ;
V_283 [ 0 ] =
F_119 ( V_308 ) ;
}
} else {
F_81 ( L_28 ) ;
if ( F_34 ( V_248 ) ||
F_34 ( V_307 ) ) {
V_294 += 1 ;
V_10 = 0 ;
}
}
if ( F_6 ( V_13 ) ) {
V_158 = 1 ;
if ( F_34 ( V_121 ) ) {
union V_150 V_204 ;
V_204 . V_4 = F_9 ( V_159 ) ;
if ( V_204 . V_160 . V_161 )
V_158 = 0 ;
}
} else {
union V_214 V_215 ;
V_215 . V_4 = F_9 ( F_83 ( 1 ) ) ;
V_158 = V_215 . V_16 . V_158 ;
}
if ( V_158 ) {
F_81 ( L_29 ) ;
if ( F_34 ( V_248 ) ||
F_34 ( V_307 ) ) {
V_230 . V_4 = F_9 ( F_82 ( 1 ) ) ;
if ( V_230 . V_16 . V_237 ) {
V_294 += 1 ;
V_10 = 1 ;
}
}
V_258 = F_76 ( 1 ) ;
if ( V_258 == 0 ) {
T_2 V_308 ;
V_314 . V_310 =
F_3 ( 1 ) ;
V_314 . V_302 =
F_124 ( F_1 ( 0 ) ) ;
V_314 . V_311 =
F_1 ( 1 ) -
F_1 ( 0 ) ;
V_314 . V_303 -> V_299 =
F_3 ( 1 ) + ( 4ul << 30 ) -
( V_312 << 20 ) ;
V_314 . V_303 -> V_300 =
F_3 ( 1 ) +
F_4 ( 1 ) - 1 ;
V_314 . V_313 -> V_299 =
F_1 ( 1 ) -
F_1 ( 0 ) ;
V_314 . V_313 -> V_300 =
V_314 . V_313 -> V_299 +
F_2 ( 1 ) - 1 ;
F_126 ( 100 ) ;
F_125 ( & V_314 ) ;
V_308 = F_21 ( 1 , 0 , 0 , 0 , 0 ) ;
V_283 [ 1 ] =
F_119 ( V_308 ) ;
}
} else {
F_81 ( L_30 ) ;
if ( F_34 ( V_248 ) ||
F_34 ( V_307 ) ) {
V_294 += 1 ;
V_10 = 1 ;
}
}
if ( F_34 ( V_248 ) ||
F_34 ( V_307 ) ) {
if ( V_294 == 1 ) {
V_226 . V_4 = F_9 ( F_94 ( V_10 ) ) ;
V_226 . V_16 . V_315 = 1 ;
V_226 . V_16 . V_316 = 1 ;
V_226 . V_16 . V_317 = 1 ;
V_226 . V_16 . V_318 = 1 ;
F_7 ( F_94 ( V_10 ) , V_226 . V_4 ) ;
V_226 . V_4 = F_9 ( F_94 ( ! V_10 ) ) ;
V_226 . V_16 . V_315 = 0 ;
V_226 . V_16 . V_316 = 0 ;
V_226 . V_16 . V_317 = 0 ;
V_226 . V_16 . V_318 = 0 ;
F_7 ( F_94 ( ! V_10 ) , V_226 . V_4 ) ;
}
}
F_127 () ;
return 0 ;
}
