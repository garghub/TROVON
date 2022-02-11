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
V_130 -> V_16 . V_133 ++ ;
}
static int F_60 ( int V_1 )
{
int V_134 ;
int V_135 ;
V_4 V_136 ;
union V_137 V_138 ;
union V_139 V_140 ;
union V_141 V_142 ;
union V_143 V_144 ;
union V_145 V_146 ;
union V_147 V_148 ;
union V_149 V_150 ;
union V_151 V_152 ;
union V_44 V_45 ;
union V_153 V_154 ;
V_155:
V_144 . V_4 = F_9 ( V_156 ) ;
if ( ( V_1 == 0 ) && ! V_144 . V_16 . V_157 ) {
F_56 ( L_2 , V_1 ) ;
return - 1 ;
}
if ( F_34 ( V_121 ) ) {
V_150 . V_4 = F_9 ( V_158 ) ;
if ( ( V_1 == 1 ) && V_150 . V_159 . V_160 ) {
F_56 ( L_3 ) ;
return - 1 ;
}
}
V_144 . V_16 . V_161 = 1 ;
V_144 . V_16 . V_162 = 0x20 ;
if ( F_34 ( V_117 ) ) {
V_144 . V_16 . V_163 = 0x20 ;
V_144 . V_16 . V_164 = 0x20 ;
}
F_7 ( V_156 , V_144 . V_4 ) ;
if ( F_61 () -> V_165 == V_166 ) {
if ( V_1 == 0 ) {
V_138 . V_4 = F_9 ( V_167 ) ;
if ( V_138 . V_16 . V_168 == 0 ) {
V_138 . V_16 . V_168 = 1 ;
F_7 ( V_167 , V_138 . V_4 ) ;
V_138 . V_4 = F_9 ( V_169 ) ;
V_138 . V_16 . V_168 = 1 ;
F_7 ( V_169 , V_138 . V_4 ) ;
F_62 ( 2000 ) ;
}
V_138 . V_4 = F_9 ( V_169 ) ;
V_138 . V_16 . V_168 = 0 ;
F_7 ( V_169 , V_138 . V_4 ) ;
V_138 . V_4 = F_9 ( V_167 ) ;
V_138 . V_16 . V_168 = 0 ;
F_7 ( V_167 , V_138 . V_4 ) ;
}
} else {
if ( V_1 )
V_138 . V_4 = F_9 ( V_169 ) ;
else
V_138 . V_4 = F_9 ( V_167 ) ;
if ( V_138 . V_16 . V_168 == 0 ) {
V_138 . V_16 . V_168 = 1 ;
if ( V_1 )
F_7 ( V_169 , V_138 . V_4 ) ;
else
F_7 ( V_167 , V_138 . V_4 ) ;
F_62 ( 2000 ) ;
}
if ( V_1 ) {
V_138 . V_4 = F_9 ( V_169 ) ;
V_138 . V_16 . V_168 = 0 ;
F_7 ( V_169 , V_138 . V_4 ) ;
} else {
V_138 . V_4 = F_9 ( V_167 ) ;
V_138 . V_16 . V_168 = 0 ;
F_7 ( V_167 , V_138 . V_4 ) ;
}
}
F_57 ( 400000 ) ;
if ( ! F_34 ( V_170 ) && ! F_34 ( V_117 ) ) {
V_152 . V_4 = F_9 ( F_63 ( V_1 ) ) ;
V_152 . V_16 . V_171 = 1 ;
F_7 ( F_63 ( V_1 ) , V_152 . V_4 ) ;
if ( F_64 ( F_63 ( V_1 ) ,
union V_151 , V_171 , == , 1 , 10000 ) ) {
F_56 ( L_4 , V_1 ) ;
return - 1 ;
}
}
V_152 . V_4 = F_9 ( F_63 ( V_1 ) ) ;
if ( V_152 . V_16 . V_172 ) {
F_56 ( L_5 , V_1 ) ;
return - 1 ;
}
V_142 . V_4 = F_9 ( F_65 ( V_1 ) ) ;
if ( V_142 . V_4 ) {
F_56 ( L_6 ,
V_1 ) ;
return - 1 ;
}
V_140 . V_4 = F_9 ( F_66 ( V_1 ) ) ;
if ( V_140 . V_4 )
F_56 ( L_7 ,
V_1 , F_67 ( V_140 . V_4 ) ) ;
F_32 ( V_1 ) ;
if ( F_49 ( V_1 ) ) {
F_56 ( L_8 ,
V_1 ) ;
return - 1 ;
}
V_146 . V_4 = F_9 ( V_173 ) ;
V_146 . V_16 . V_174 = 0 ;
V_146 . V_16 . V_175 = 127 ;
F_7 ( V_173 , V_146 . V_4 ) ;
V_148 . V_4 = 0 ;
V_148 . V_16 . V_10 = V_1 ;
V_148 . V_16 . V_176 = 1 ;
V_148 . V_16 . V_177 = 1 ;
V_148 . V_16 . V_178 = 1 ;
V_148 . V_16 . V_179 = 0 ;
V_148 . V_16 . V_180 = 0 ;
V_148 . V_16 . V_181 = 0 ;
V_148 . V_16 . V_182 = 0 ;
V_148 . V_16 . V_133 = 0 ;
for ( V_134 = 12 + V_1 * 4 ; V_134 < 16 + V_1 * 4 ; V_134 ++ ) {
F_7 ( F_68 ( V_134 ) , V_148 . V_4 ) ;
V_148 . V_16 . V_133 += 1 ;
}
for ( V_134 = 0 ; V_134 < 4 ; V_134 ++ ) {
F_7 ( F_69 ( V_134 , V_1 ) , - 1 ) ;
F_7 ( F_70 ( V_134 , V_1 ) , - 1 ) ;
}
F_7 ( F_71 ( V_1 ) , 0 ) ;
F_7 ( F_72 ( V_1 ) , V_183 ) ;
V_154 . V_32 = 0 ;
V_154 . V_16 . V_184 = ( V_185 >> 22 ) ;
V_154 . V_16 . V_186 = 1 ;
V_154 . V_16 . V_187 = 1 ;
V_154 . V_16 . V_188 = 1 ;
V_135 = V_1 ? 16 : 0 ;
#ifdef F_73
V_136 = 4 ;
#else
V_136 = 0 ;
#endif
for ( V_134 = 0 ; V_134 < 16 ; V_134 ++ ) {
F_30 ( ( F_74 ( V_135 ) ^ V_136 ) ,
V_154 . V_32 ) ;
V_135 ++ ;
V_154 . V_16 . V_184 += ( ( ( 1ull << 28 ) / 16ull ) >> 22 ) ;
}
F_7 ( F_75 ( V_1 ) , 0 ) ;
if ( V_1 ) {
union V_189 V_190 ;
V_190 . V_4 = F_9 ( V_191 ) ;
V_190 . V_16 . V_192 = 1 ;
V_190 . V_16 . V_193 = 1 ;
V_190 . V_16 . V_194 = 0 ;
V_190 . V_16 . V_195 = 1 ;
V_190 . V_16 . V_196 = 1 ;
V_190 . V_16 . V_197 = 0 ;
V_190 . V_16 . V_198 = 0 ;
F_7 ( V_191 , V_190 . V_4 ) ;
} else {
union V_199 V_190 ;
V_190 . V_4 = F_9 ( V_200 ) ;
V_190 . V_16 . V_192 = 1 ;
V_190 . V_16 . V_193 = 1 ;
V_190 . V_16 . V_194 = 0 ;
V_190 . V_16 . V_195 = 1 ;
V_190 . V_16 . V_196 = 1 ;
V_190 . V_16 . V_197 = 0 ;
V_190 . V_16 . V_198 = 0 ;
F_7 ( V_200 , V_190 . V_4 ) ;
}
if ( F_34 ( V_201 ) ||
F_34 ( V_202 ) ||
F_34 ( V_170 ) ||
F_34 ( V_117 ) ) {
union V_149 V_203 ;
int V_204 ;
int V_205 ;
int V_206 ;
int V_207 = ( F_34 ( V_117 ) || F_34 ( V_170 ) ) ? 4 : 1 ;
int V_134 ;
T_1 V_208 = ( F_3 ( V_1 ) + 0x100000 ) | ( 1ull << 63 ) ;
V_134 = V_207 ;
while ( V_134 -- ) {
F_30 ( V_208 , 0 ) ;
F_57 ( 10000 ) ;
}
F_7 ( V_209 , ( V_1 ) ? 0xd7fc : 0xcffc ) ;
F_9 ( V_209 ) ;
do {
V_203 . V_4 = F_9 ( V_158 ) ;
V_204 = V_203 . V_16 . V_18 & 0xff ;
F_30 ( V_208 , 0 ) ;
F_57 ( 10000 ) ;
V_203 . V_4 = F_9 ( V_158 ) ;
V_205 = V_203 . V_16 . V_18 & 0xff ;
} while ( V_205 != ( ( V_204 + 1 ) & 0xff ) );
V_205 = ( V_205 + V_207 ) & 0xff ;
F_7 ( V_209 , ( V_1 ) ? 0xd00f : 0xc80f ) ;
F_9 ( V_209 ) ;
V_203 . V_4 = F_9 ( V_158 ) ;
V_206 = ( V_203 . V_16 . V_18 >> 1 ) & 0xff ;
if ( V_206 != V_205 ) {
F_56 ( L_9 , V_1 ) ;
while ( V_205 != 0 ) {
F_30 ( V_208 , 0 ) ;
F_57 ( 10000 ) ;
V_205 = ( V_205 + 1 ) & 0xff ;
}
if ( ( F_61 () -> V_165 == V_166 ) &&
( V_1 == 1 ) )
F_76 ( 0 ) ;
goto V_155;
}
}
V_45 . V_32 = F_5 ( V_1 , F_41 ( V_1 ) ) ;
F_56 ( L_10 , V_1 , V_45 . V_16 . V_127 ) ;
return 0 ;
}
static int F_77 ( int V_1 )
{
T_1 V_108 ;
union V_210 V_211 ;
union V_44 V_45 ;
union V_113 V_114 ;
V_211 . V_4 = F_9 ( F_78 ( V_1 ) ) ;
V_211 . V_16 . V_123 = 1 ;
F_7 ( F_78 ( V_1 ) , V_211 . V_4 ) ;
V_108 = F_54 () ;
do {
if ( F_54 () - V_108 > F_55 () )
return - 1 ;
F_57 ( 10000 ) ;
V_45 . V_32 = F_5 ( V_1 , F_41 ( V_1 ) ) ;
} while ( ( V_45 . V_16 . V_125 == 0 ) || ( V_45 . V_16 . V_212 == 1 ) );
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
int V_134 ;
union V_137 V_138 ;
union V_213 V_214 ;
union V_215 V_216 ;
union V_210 V_217 ;
union V_218 V_219 ;
union V_220 V_221 ;
union V_44 V_45 ;
union V_222 V_223 ;
union V_224 V_225 ;
union V_226 V_227 ;
union V_129 V_148 ;
union V_228 V_229 ;
union V_230 V_154 ;
if ( F_6 ( V_231 ) ) {
if ( F_34 ( V_232 ) ) {
union V_233 V_234 ;
V_234 . V_4 = F_9 ( F_80 ( V_1 ) ) ;
if ( V_234 . V_16 . V_235 == 15 ) {
F_81 ( L_11 , V_1 ) ;
return - 1 ;
}
switch ( V_234 . V_16 . V_235 ) {
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
V_229 . V_4 = F_9 ( F_82 ( V_1 ) ) ;
if ( V_229 . V_16 . V_236 ) {
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
V_214 . V_4 = F_9 ( F_83 ( V_1 ) ) ;
if ( ! V_214 . V_16 . V_157 ) {
F_81 ( L_16 , V_1 ) ;
return - 1 ;
}
if ( F_34 ( V_237 ) ) {
if ( V_1 ) {
union V_238 V_239 ;
V_239 . V_4 = F_9 ( V_240 ) ;
V_239 . V_16 . V_241 = 1 ;
V_239 . V_16 . V_242 = 5 ;
V_239 . V_16 . V_243 = 0x17 ;
F_7 ( V_240 , V_239 . V_4 ) ;
} else {
union V_244 V_239 ;
V_239 . V_4 = F_9 ( V_245 ) ;
V_239 . V_16 . V_241 = 1 ;
V_239 . V_16 . V_242 = 5 ;
V_239 . V_16 . V_243 = 0x17 ;
F_7 ( V_245 , V_239 . V_4 ) ;
}
}
if ( V_1 )
V_138 . V_4 = F_9 ( V_169 ) ;
else
V_138 . V_4 = F_9 ( V_167 ) ;
if ( V_138 . V_16 . V_168 == 0 ) {
V_138 . V_16 . V_168 = 1 ;
if ( V_1 )
F_7 ( V_169 , V_138 . V_4 ) ;
else
F_7 ( V_167 , V_138 . V_4 ) ;
F_62 ( 2000 ) ;
}
if ( V_1 ) {
V_138 . V_4 = F_9 ( V_169 ) ;
V_138 . V_16 . V_168 = 0 ;
F_7 ( V_169 , V_138 . V_4 ) ;
} else {
V_138 . V_4 = F_9 ( V_167 ) ;
V_138 . V_16 . V_168 = 0 ;
F_7 ( V_167 , V_138 . V_4 ) ;
}
F_62 ( 1000 ) ;
if ( F_64 ( F_83 ( V_1 ) , union V_213 , V_246 , == , 1 , 10000 ) ) {
F_81 ( L_5 , V_1 ) ;
return - 1 ;
}
V_219 . V_4 = F_9 ( F_84 ( V_1 ) ) ;
if ( V_219 . V_4 )
F_81 ( L_7 , V_1 , F_67 ( V_219 . V_4 ) ) ;
V_221 . V_4 = F_9 ( F_85 ( V_1 ) ) ;
if ( F_34 ( V_247 ) )
V_221 . V_4 &= ~ 0x3full ;
if ( V_221 . V_4 )
F_81 ( L_17 , V_1 , F_67 ( V_221 . V_4 ) ) ;
F_32 ( V_1 ) ;
V_223 . V_32 = F_5 ( V_1 , F_86 ( V_1 ) ) ;
V_223 . V_16 . V_248 = 1 ;
F_11 ( V_1 , F_86 ( V_1 ) , V_223 . V_32 ) ;
if ( F_77 ( V_1 ) ) {
union V_249 V_250 ;
V_250 . V_32 = F_5 ( V_1 , F_87 ( V_1 ) ) ;
V_250 . V_16 . V_251 = 1 ;
F_11 ( V_1 , F_87 ( V_1 ) , V_250 . V_32 ) ;
if ( F_77 ( V_1 ) ) {
F_81 ( L_18 , V_1 ) ;
return - 1 ;
}
}
V_227 . V_4 = F_9 ( V_252 ) ;
V_227 . V_16 . V_174 = 0 ;
V_227 . V_16 . V_175 = 127 ;
F_7 ( V_252 , V_227 . V_4 ) ;
V_148 . V_4 = 0 ;
V_148 . V_16 . V_10 = V_1 ;
V_148 . V_16 . V_176 = 0 ;
V_148 . V_16 . V_177 = 1 ;
V_148 . V_16 . V_178 = 1 ;
V_148 . V_16 . V_253 = 0 ;
V_148 . V_16 . V_254 = 0 ;
if ( F_34 ( V_131 ) )
V_148 . V_132 . V_133 = 0 ;
else
V_148 . V_16 . V_133 = 0 ;
for ( V_134 = 12 + V_1 * 4 ; V_134 < 16 + V_1 * 4 ; V_134 ++ ) {
F_7 ( F_88 ( V_134 ) , V_148 . V_4 ) ;
F_59 ( & V_148 ) ;
}
for ( V_134 = 0 ; V_134 < 4 ; V_134 ++ ) {
F_7 ( F_89 ( V_134 , V_1 ) , - 1 ) ;
F_7 ( F_90 ( V_134 , V_1 ) , - 1 ) ;
}
F_7 ( F_91 ( V_1 ) , 0 ) ;
F_7 ( F_92 ( V_1 ) , 0 ) ;
V_216 . V_4 = F_9 ( F_93 ( V_1 ) ) ;
V_216 . V_16 . V_255 = 3 ;
V_216 . V_16 . V_192 = 1 ;
V_216 . V_16 . V_193 = 1 ;
V_216 . V_16 . V_194 = 0 ;
F_7 ( F_93 ( V_1 ) , V_216 . V_4 ) ;
V_225 . V_4 = F_9 ( F_94 ( V_1 ) ) ;
V_225 . V_16 . V_195 = 1 ;
V_225 . V_16 . V_196 = 1 ;
V_225 . V_16 . V_197 = 0 ;
V_225 . V_16 . V_198 = 0 ;
F_7 ( F_94 ( V_1 ) , V_225 . V_4 ) ;
F_7 ( F_95 ( V_1 ) , V_183 ) ;
V_154 . V_4 = 0 ;
V_154 . V_16 . V_184 = ( V_185 >> 22 ) ;
V_154 . V_16 . V_186 = 1 ;
V_154 . V_16 . V_187 = 1 ;
V_154 . V_16 . V_188 = 1 ;
for ( V_134 = 0 ; V_134 < 16 ; V_134 ++ ) {
F_7 ( F_96 ( V_134 , V_1 ) , V_154 . V_4 ) ;
V_154 . V_16 . V_184 += ( ( ( 1ull << 28 ) / 16ull ) >> 22 ) ;
}
V_217 . V_4 = F_9 ( F_78 ( V_1 ) ) ;
V_217 . V_16 . V_162 = 250 * 5000000 / 0x10000 ;
F_7 ( F_78 ( V_1 ) , V_217 . V_4 ) ;
V_45 . V_32 = F_5 ( V_1 , F_41 ( V_1 ) ) ;
F_81 ( L_19 , V_1 , V_45 . V_16 . V_127 , V_45 . V_16 . V_256 ) ;
return 0 ;
}
static int F_76 ( int V_1 )
{
int V_257 ;
if ( F_6 ( V_13 ) )
V_257 = F_60 ( V_1 ) ;
else
V_257 = F_79 ( V_1 ) ;
return V_257 ;
}
int T_5 F_97 ( const struct V_258 * V_27 ,
T_6 V_259 , T_6 V_260 )
{
if ( strstr ( F_98 () , L_20 ) &&
V_27 -> V_26 && V_27 -> V_26 -> V_261 ) {
while ( V_27 -> V_26 && V_27 -> V_26 -> V_261 )
V_27 = F_99 ( V_27 -> V_26 -> V_262 ) ;
if ( ( V_27 -> V_26 -> V_263 == 1 ) &&
( V_27 -> V_264 == 0x10b5 ) && ( V_27 -> V_265 == 0x8114 ) ) {
V_260 = ( ( V_260 - 3 ) & 3 ) + 1 ;
}
}
return V_260 - 1 + V_266 ;
}
static void F_100 ( V_32 V_267 )
{
union V_210 V_268 ;
V_268 . V_4 = F_9 ( F_78 ( 1 ) ) ;
V_268 . V_16 . V_162 = V_267 ;
F_7 ( F_78 ( 1 ) , V_268 . V_4 ) ;
}
static V_32 F_101 ( void )
{
V_32 V_267 ;
union V_210 V_268 ;
V_268 . V_4 = F_9 ( F_78 ( 1 ) ) ;
V_267 = V_268 . V_16 . V_162 ;
V_268 . V_16 . V_162 = 0 ;
F_7 ( F_78 ( 1 ) , V_268 . V_4 ) ;
return V_267 ;
}
static int F_102 ( void )
{
union V_269 V_270 ;
V_270 . V_4 = F_9 ( F_103 ( 1 ) ) ;
if ( V_270 . V_16 . V_271 )
return 1 ;
return 0 ;
}
static int F_104 ( unsigned int V_1 , struct V_272 * V_26 ,
unsigned int V_273 , int V_29 , int V_274 ,
V_32 * V_21 )
{
union V_275 V_276 ;
union V_275 V_277 ;
int V_278 = V_26 -> V_263 ;
int V_279 = 0 ;
int V_267 = 0 ;
int V_280 = 10 ;
V_32 V_281 = 0 ;
V_277 . V_4 = 0 ;
F_105 ( V_1 >= F_106 ( V_282 ) ) ;
if ( V_26 -> V_261 == NULL ) {
if ( V_282 [ V_1 ] )
V_278 = 0 ;
else {
union V_30 V_31 ;
V_31 . V_32 = F_5 ( V_1 ,
F_15 ( V_1 ) ) ;
if ( V_31 . V_16 . V_33 != V_278 ) {
V_31 . V_16 . V_33 = V_278 ;
V_31 . V_16 . V_90 = V_278 ;
V_31 . V_16 . V_91 = V_278 ;
F_11 ( V_1 ,
F_15 ( V_1 ) ,
V_31 . V_32 ) ;
}
}
}
if ( ( V_26 -> V_261 == NULL ) && ( V_273 >> 3 != 0 ) )
return V_283 ;
if ( F_34 ( V_284 ) ||
F_34 ( V_285 ) ) {
if ( ( V_26 -> V_261 == NULL ) && ( V_273 >= 2 ) )
return V_283 ;
#if 1
if ( V_278 == 2 )
return V_283 ;
#elif 0
if ( ( V_278 == 2 ) && ( V_273 >> 3 != 2 ) )
return V_283 ;
#elif 0
if ( ( V_278 == 2 ) && ( V_273 >> 3 != 3 ) )
return V_283 ;
#elif 0
if ( ( V_278 == 2 ) &&
! ( ( V_273 == ( 2 << 3 ) ) || ( V_273 == ( 3 << 3 ) ) ) )
return V_283 ;
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
V_277 . V_4 = F_107 ( V_286 , 7 ) ;
V_276 . V_4 = V_277 . V_4 ;
V_276 . V_16 . V_287 = 2 ;
F_108 ( V_286 , 7 , V_276 . V_4 ) ;
}
if ( ( F_34 ( V_288 ) ) && ( V_289 ) )
V_281 = F_101 () ;
F_109 ( L_21
L_22 , V_1 , V_278 , V_273 , V_29 , V_274 ) ;
do {
switch ( V_274 ) {
case 4 :
* V_21 = F_21 ( V_1 , V_278 ,
V_273 >> 3 , V_273 & 0x7 , V_29 ) ;
break;
case 2 :
* V_21 = F_18 ( V_1 , V_278 ,
V_273 >> 3 , V_273 & 0x7 , V_29 ) ;
break;
case 1 :
* V_21 = F_16 ( V_1 , V_278 ,
V_273 >> 3 , V_273 & 0x7 , V_29 ) ;
break;
default:
if ( F_34 ( V_288 ) )
F_100 ( V_281 ) ;
return V_283 ;
}
if ( ( F_34 ( V_288 ) ) &&
( V_289 ) ) {
V_279 = F_102 () ;
V_267 ++ ;
if ( V_267 > V_280 ) {
F_110 ( L_23 ,
V_267 ) ;
V_279 = 0 ;
}
}
} while ( V_279 );
if ( ( F_34 ( V_288 ) ) && ( V_289 ) )
F_100 ( V_281 ) ;
F_109 ( L_24 , * V_21 , V_267 ) ;
if ( F_34 ( V_284 ) ||
F_34 ( V_285 ) )
F_111 ( V_277 . V_4 ) ;
return V_290 ;
}
static int F_112 ( struct V_272 * V_26 , unsigned int V_273 ,
int V_29 , int V_274 , V_32 * V_21 )
{
return F_104 ( 0 , V_26 , V_273 , V_29 , V_274 , V_21 ) ;
}
static int F_113 ( struct V_272 * V_26 , unsigned int V_273 ,
int V_29 , int V_274 , V_32 * V_21 )
{
return F_104 ( 1 , V_26 , V_273 , V_29 , V_274 , V_21 ) ;
}
static int F_114 ( struct V_272 * V_26 , unsigned int V_273 ,
int V_29 , int V_274 , V_32 * V_21 )
{
return V_283 ;
}
static int F_115 ( unsigned int V_1 , struct V_272 * V_26 ,
unsigned int V_273 , int V_29 ,
int V_274 , V_32 V_21 )
{
int V_278 = V_26 -> V_263 ;
F_105 ( V_1 >= F_106 ( V_282 ) ) ;
if ( ( V_26 -> V_261 == NULL ) && ( V_282 [ V_1 ] ) )
V_278 = 0 ;
F_109 ( L_25
L_26 , V_1 , V_278 , V_273 ,
V_29 , V_274 , V_21 ) ;
switch ( V_274 ) {
case 4 :
F_29 ( V_1 , V_278 , V_273 >> 3 ,
V_273 & 0x7 , V_29 , V_21 ) ;
break;
case 2 :
F_26 ( V_1 , V_278 , V_273 >> 3 ,
V_273 & 0x7 , V_29 , V_21 ) ;
break;
case 1 :
F_24 ( V_1 , V_278 , V_273 >> 3 ,
V_273 & 0x7 , V_29 , V_21 ) ;
break;
default:
return V_283 ;
}
return V_290 ;
}
static int F_116 ( struct V_272 * V_26 , unsigned int V_273 ,
int V_29 , int V_274 , V_32 V_21 )
{
return F_115 ( 0 , V_26 , V_273 , V_29 , V_274 , V_21 ) ;
}
static int F_117 ( struct V_272 * V_26 , unsigned int V_273 ,
int V_29 , int V_274 , V_32 V_21 )
{
return F_115 ( 1 , V_26 , V_273 , V_29 , V_274 , V_21 ) ;
}
static int F_118 ( struct V_272 * V_26 , unsigned int V_273 ,
int V_29 , int V_274 , V_32 V_21 )
{
return V_283 ;
}
static int F_119 ( T_2 V_291 )
{
#define F_120 0x111d
if ( ( V_291 & 0xffff ) == F_120 )
return 1 ;
return 0 ;
}
static int T_5 F_121 ( void )
{
int V_257 ;
int V_157 ;
int V_292 = 0 , V_10 ;
union V_224 V_225 ;
union V_228 V_229 ;
if ( ! F_6 ( V_293 ) )
return 0 ;
if ( F_122 () )
return 0 ;
if ( V_294 )
return 0 ;
V_295 = F_97 ;
F_123 ( F_124 ( F_1 ( 0 ) ) ) ;
V_296 . V_297 = 0 ;
V_296 . V_298 =
F_1 ( 1 ) -
F_1 ( 0 ) + F_2 ( 1 ) - 1 ;
V_299 . V_300 = - 1 ;
V_299 . V_301 -> V_297 = ( 1ull << 48 ) ;
V_299 . V_301 -> V_298 = ( 1ull << 48 ) ;
F_125 ( & V_299 ) ;
if ( F_6 ( V_13 ) ) {
union V_143 V_144 ;
V_144 . V_4 = F_9 ( V_156 ) ;
V_157 = V_144 . V_16 . V_157 ;
V_302 = V_303 ;
} else {
union V_213 V_214 ;
V_214 . V_4 = F_9 ( F_83 ( 0 ) ) ;
V_157 = V_214 . V_16 . V_157 ;
V_302 = V_304 ;
}
if ( V_157 ) {
F_81 ( L_27 ) ;
if ( F_34 ( V_247 ) ||
F_34 ( V_305 ) ) {
V_229 . V_4 = F_9 ( F_82 ( 0 ) ) ;
if ( V_229 . V_16 . V_236 ) {
V_292 += 1 ;
V_10 = 0 ;
}
}
V_257 = F_76 ( 0 ) ;
if ( V_257 == 0 ) {
T_2 V_306 ;
V_307 . V_308 =
F_3 ( 0 ) ;
V_307 . V_300 =
F_124 ( F_1
( 0 ) ) ;
V_307 . V_309 = 0 ;
V_307 . V_301 -> V_297 =
F_3 ( 0 ) +
( 4ul << 30 ) - ( V_310 << 20 ) ;
V_307 . V_301 -> V_298 =
F_3 ( 0 ) +
F_4 ( 0 ) - 1 ;
V_307 . V_311 -> V_297 = 4 << 10 ;
V_307 . V_311 -> V_298 =
F_2 ( 0 ) - 1 ;
F_126 ( 100 ) ;
F_125 ( & V_307 ) ;
V_306 = F_21 ( 0 , 0 , 0 , 0 , 0 ) ;
V_282 [ 0 ] =
F_119 ( V_306 ) ;
}
} else {
F_81 ( L_28 ) ;
if ( F_34 ( V_247 ) ||
F_34 ( V_305 ) ) {
V_292 += 1 ;
V_10 = 0 ;
}
}
if ( F_6 ( V_13 ) ) {
V_157 = 1 ;
if ( F_34 ( V_121 ) ) {
union V_149 V_203 ;
V_203 . V_4 = F_9 ( V_158 ) ;
if ( V_203 . V_159 . V_160 )
V_157 = 0 ;
}
} else {
union V_213 V_214 ;
V_214 . V_4 = F_9 ( F_83 ( 1 ) ) ;
V_157 = V_214 . V_16 . V_157 ;
}
if ( V_157 ) {
F_81 ( L_29 ) ;
if ( F_34 ( V_247 ) ||
F_34 ( V_305 ) ) {
V_229 . V_4 = F_9 ( F_82 ( 1 ) ) ;
if ( V_229 . V_16 . V_236 ) {
V_292 += 1 ;
V_10 = 1 ;
}
}
V_257 = F_76 ( 1 ) ;
if ( V_257 == 0 ) {
T_2 V_306 ;
V_312 . V_308 =
F_3 ( 1 ) ;
V_312 . V_300 =
F_124 ( F_1 ( 0 ) ) ;
V_312 . V_309 =
F_1 ( 1 ) -
F_1 ( 0 ) ;
V_312 . V_301 -> V_297 =
F_3 ( 1 ) + ( 4ul << 30 ) -
( V_310 << 20 ) ;
V_312 . V_301 -> V_298 =
F_3 ( 1 ) +
F_4 ( 1 ) - 1 ;
V_312 . V_311 -> V_297 =
F_1 ( 1 ) -
F_1 ( 0 ) ;
V_312 . V_311 -> V_298 =
V_312 . V_311 -> V_297 +
F_2 ( 1 ) - 1 ;
F_126 ( 100 ) ;
F_125 ( & V_312 ) ;
V_306 = F_21 ( 1 , 0 , 0 , 0 , 0 ) ;
V_282 [ 1 ] =
F_119 ( V_306 ) ;
}
} else {
F_81 ( L_30 ) ;
if ( F_34 ( V_247 ) ||
F_34 ( V_305 ) ) {
V_292 += 1 ;
V_10 = 1 ;
}
}
if ( F_34 ( V_247 ) ||
F_34 ( V_305 ) ) {
if ( V_292 == 1 ) {
V_225 . V_4 = F_9 ( F_94 ( V_10 ) ) ;
V_225 . V_16 . V_313 = 1 ;
V_225 . V_16 . V_314 = 1 ;
V_225 . V_16 . V_315 = 1 ;
V_225 . V_16 . V_316 = 1 ;
F_7 ( F_94 ( V_10 ) , V_225 . V_4 ) ;
V_225 . V_4 = F_9 ( F_94 ( ! V_10 ) ) ;
V_225 . V_16 . V_313 = 0 ;
V_225 . V_16 . V_314 = 0 ;
V_225 . V_16 . V_315 = 0 ;
V_225 . V_16 . V_316 = 0 ;
F_7 ( F_94 ( ! V_10 ) , V_225 . V_4 ) ;
}
}
F_127 () ;
return 0 ;
}
