static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 || V_4 -> V_6 )
V_2 -> V_7 . V_8 ++ ;
if ( V_4 -> V_5 )
F_3 ( V_4 -> V_5 ) ;
if ( V_4 -> V_6 )
F_4 ( V_4 -> V_2 , 0 ) ;
V_4 -> V_5 = NULL ;
V_4 -> V_6 = 0 ;
}
static int F_5 ( struct V_9 * V_10 , int V_11 )
{
struct V_3 * V_4 = F_6 ( & V_10 -> V_12 ) ;
struct V_13 V_14 = {
. V_15 = V_4 -> V_16 ,
. V_17 = V_4 -> V_18 ,
. V_11 = V_11 ,
. V_19 = 0 ,
} ;
struct V_20 V_21 ;
int V_22 ;
F_7 ( & V_21 ) ;
if ( V_23 ) {
V_14 . V_24 = V_4 -> V_25 ;
V_14 . V_26 = V_4 -> V_27 ;
V_21 . V_28 = 1 ;
}
F_8 ( & V_14 , & V_21 ) ;
V_22 = F_9 ( V_10 , & V_21 ) ;
if ( V_22 )
F_10 ( & V_10 -> V_12 , L_1 , V_22 ) ;
return V_22 ;
}
static T_1 F_11 ( struct V_9 * V_10 , T_2 V_29 )
{
struct V_3 * V_4 = F_6 ( & V_10 -> V_12 ) ;
T_1 V_30 = 0 ;
V_4 -> V_16 [ 0 ] = V_31 ;
V_4 -> V_16 [ 1 ] = V_29 ;
F_5 ( V_10 , 3 ) ;
V_30 = V_4 -> V_18 [ 2 ] ;
return V_30 ;
}
static void F_12 ( struct V_9 * V_10 , T_2 V_29 ,
T_2 * V_32 , T_2 * V_33 )
{
struct V_3 * V_4 = F_6 ( & V_10 -> V_12 ) ;
V_4 -> V_16 [ 0 ] = V_31 ;
V_4 -> V_16 [ 1 ] = V_29 ;
F_5 ( V_10 , 4 ) ;
* V_32 = V_4 -> V_18 [ 2 ] ;
* V_33 = V_4 -> V_18 [ 3 ] ;
}
static void F_13 ( struct V_9 * V_10 , T_1 V_29 , T_2 V_30 )
{
struct V_3 * V_4 = F_6 ( & V_10 -> V_12 ) ;
V_4 -> V_16 [ 0 ] = V_34 ;
V_4 -> V_16 [ 1 ] = V_29 ;
V_4 -> V_16 [ 2 ] = V_30 ;
F_5 ( V_10 , 3 ) ;
}
static void F_14 ( struct V_9 * V_10 , T_1 V_29 ,
T_1 V_35 , T_2 V_30 )
{
struct V_3 * V_4 = F_6 ( & V_10 -> V_12 ) ;
V_4 -> V_16 [ 0 ] = V_36 ;
V_4 -> V_16 [ 1 ] = V_29 ;
V_4 -> V_16 [ 2 ] = V_35 ;
V_4 -> V_16 [ 3 ] = V_30 ;
F_5 ( V_10 , 4 ) ;
}
static void F_15 ( struct V_9 * V_10 , T_1 * V_37 ,
int V_11 , int V_38 )
{
struct V_3 * V_4 = F_6 ( & V_10 -> V_12 ) ;
if ( F_16 ( V_10 ) ) {
int V_39 ;
for ( V_39 = 1 ; V_39 < V_40 + V_11 ; V_39 ++ )
F_13 ( V_10 , F_17 ( V_38 ) + V_39 ,
V_37 [ V_39 ] ) ;
} else {
memcpy ( V_4 -> V_16 , V_37 , V_40 + V_11 ) ;
F_5 ( V_10 , V_40 + V_11 ) ;
}
}
static void F_18 ( struct V_9 * V_10 , struct V_41 * V_42 ,
int V_38 )
{
struct V_3 * V_4 = F_6 ( & V_10 -> V_12 ) ;
T_3 V_43 , V_44 , V_45 , V_46 ;
T_1 V_37 [ V_47 ] ;
V_45 = ( V_42 -> V_48 & V_49 ) ? 1 : 0 ;
if ( V_45 )
V_43 = ( V_42 -> V_48 & V_50 ) >> 18 ;
else
V_43 = V_42 -> V_48 & V_51 ;
V_44 = V_42 -> V_48 & V_50 ;
V_46 = ( V_42 -> V_48 & V_52 ) ? 1 : 0 ;
V_37 [ V_53 ] = F_19 ( V_38 ) ;
V_37 [ V_54 ] = V_43 >> V_55 ;
V_37 [ V_56 ] = ( ( V_43 & V_57 ) << V_58 ) |
( V_45 << V_59 ) |
( ( V_44 >> V_60 ) & V_61 ) ;
V_37 [ V_62 ] = F_20 ( V_44 , 1 ) ;
V_37 [ V_63 ] = F_20 ( V_44 , 0 ) ;
V_37 [ V_64 ] = ( V_46 << V_65 ) | V_42 -> V_66 ;
memcpy ( V_37 + V_40 , V_42 -> V_67 , V_42 -> V_66 ) ;
F_15 ( V_10 , V_37 , V_42 -> V_66 , V_38 ) ;
V_4 -> V_16 [ 0 ] = F_21 ( 1 << V_38 ) ;
F_5 ( V_4 -> V_10 , 1 ) ;
}
static void F_22 ( struct V_9 * V_10 , T_1 * V_37 ,
int V_68 )
{
struct V_3 * V_4 = F_6 ( & V_10 -> V_12 ) ;
if ( F_16 ( V_10 ) ) {
int V_39 , V_11 ;
for ( V_39 = 1 ; V_39 < V_69 ; V_39 ++ )
V_37 [ V_39 ] = F_11 ( V_10 , F_23 ( V_68 ) + V_39 ) ;
V_11 = F_24 ( V_37 [ V_70 ] & V_71 ) ;
for (; V_39 < ( V_69 + V_11 ) ; V_39 ++ )
V_37 [ V_39 ] = F_11 ( V_10 , F_23 ( V_68 ) + V_39 ) ;
} else {
V_4 -> V_16 [ V_72 ] = F_25 ( V_68 ) ;
F_5 ( V_10 , V_47 ) ;
memcpy ( V_37 , V_4 -> V_18 , V_47 ) ;
}
}
static void F_26 ( struct V_9 * V_10 , int V_68 )
{
struct V_3 * V_4 = F_6 ( & V_10 -> V_12 ) ;
struct V_73 * V_74 ;
struct V_41 * V_42 ;
T_1 V_37 [ V_47 ] ;
V_74 = F_27 ( V_4 -> V_2 , & V_42 ) ;
if ( ! V_74 ) {
F_10 ( & V_10 -> V_12 , L_2 ) ;
V_4 -> V_2 -> V_7 . V_75 ++ ;
return;
}
F_22 ( V_10 , V_37 , V_68 ) ;
if ( V_37 [ V_76 ] & V_77 ) {
V_42 -> V_48 = V_49 ;
V_42 -> V_48 |=
F_28 ( V_37 [ V_76 ] & V_78 , 2 ) |
F_28 ( V_37 [ V_79 ] , 1 ) |
F_28 ( V_37 [ V_80 ] , 0 ) |
( ( ( V_37 [ V_81 ] << V_82 ) |
( V_37 [ V_76 ] >> V_83 ) ) << 18 ) ;
if ( V_37 [ V_70 ] & V_84 )
V_42 -> V_48 |= V_52 ;
} else {
V_42 -> V_48 =
( V_37 [ V_81 ] << V_82 ) |
( V_37 [ V_76 ] >> V_83 ) ;
if ( V_37 [ V_76 ] & V_85 )
V_42 -> V_48 |= V_52 ;
}
V_42 -> V_66 = F_24 ( V_37 [ V_70 ] & V_71 ) ;
memcpy ( V_42 -> V_67 , V_37 + V_69 , V_42 -> V_66 ) ;
V_4 -> V_2 -> V_7 . V_86 ++ ;
V_4 -> V_2 -> V_7 . V_87 += V_42 -> V_66 ;
F_29 ( V_74 ) ;
}
static void F_30 ( struct V_9 * V_10 )
{
F_13 ( V_10 , V_88 , V_89 ) ;
}
static T_4 F_31 ( struct V_73 * V_74 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
if ( V_4 -> V_5 || V_4 -> V_6 ) {
F_32 ( & V_10 -> V_12 , L_3 ) ;
return V_90 ;
}
if ( F_33 ( V_2 , V_74 ) )
return V_91 ;
F_34 ( V_2 ) ;
V_4 -> V_5 = V_74 ;
F_35 ( V_4 -> V_92 , & V_4 -> V_93 ) ;
return V_91 ;
}
static int F_36 ( struct V_1 * V_2 , enum V_94 V_95 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_95 ) {
case V_96 :
F_1 ( V_2 ) ;
V_4 -> V_97 . V_98 = V_99 ;
V_4 -> V_100 = 1 ;
if ( V_4 -> V_97 . V_101 == 0 )
V_4 -> V_102 = V_103 ;
F_35 ( V_4 -> V_92 , & V_4 -> V_104 ) ;
break;
default:
return - V_105 ;
}
return 0 ;
}
static int F_37 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = F_6 ( & V_10 -> V_12 ) ;
unsigned long V_106 ;
F_13 ( V_10 , V_107 ,
V_108 | V_109 | V_110 |
V_111 | V_112 | V_113 ) ;
if ( V_4 -> V_97 . V_114 & V_115 ) {
F_13 ( V_10 , V_88 , V_116 ) ;
} else if ( V_4 -> V_97 . V_114 & V_117 ) {
F_13 ( V_10 , V_88 , V_118 ) ;
} else {
F_13 ( V_10 , V_88 , V_119 ) ;
V_106 = V_120 + V_121 ;
while ( F_11 ( V_10 , V_122 ) & V_123 ) {
F_38 () ;
if ( F_39 ( V_120 , V_106 ) ) {
F_10 ( & V_10 -> V_12 , L_4
L_5 ) ;
return - V_124 ;
}
}
}
V_4 -> V_97 . V_98 = V_99 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_125 * V_126 = & V_4 -> V_97 . V_127 ;
struct V_9 * V_10 = V_4 -> V_10 ;
F_13 ( V_10 , V_128 , ( ( V_126 -> V_129 - 1 ) << V_130 ) |
( V_126 -> V_131 - 1 ) ) ;
F_13 ( V_10 , V_132 , V_133 |
( V_4 -> V_97 . V_114 & V_134 ?
V_135 : 0 ) |
( ( V_126 -> V_136 - 1 ) << V_137 ) |
( V_126 -> V_138 - 1 ) ) ;
F_14 ( V_10 , V_139 , V_140 ,
( V_126 -> V_141 - 1 ) ) ;
F_41 ( & V_10 -> V_12 , L_6 ,
F_11 ( V_10 , V_128 ) ,
F_11 ( V_10 , V_132 ) ,
F_11 ( V_10 , V_139 ) ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_9 * V_10 )
{
F_40 ( V_2 ) ;
F_13 ( V_10 , F_23 ( 0 ) ,
V_142 | V_143 | V_144 ) ;
F_13 ( V_10 , F_23 ( 1 ) ,
V_143 | V_144 ) ;
return 0 ;
}
static int F_43 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = F_6 ( & V_10 -> V_12 ) ;
int V_22 ;
unsigned long V_106 ;
V_4 -> V_16 [ 0 ] = V_145 ;
V_22 = F_44 ( V_10 , V_4 -> V_16 , 1 ) ;
if ( V_22 ) {
F_10 ( & V_10 -> V_12 , L_7 , V_22 ) ;
return - V_146 ;
}
V_106 = V_120 + V_121 ;
F_45 ( 10 ) ;
while ( ( F_11 ( V_10 , V_122 ) & V_123 )
!= V_147 ) {
F_38 () ;
if ( F_39 ( V_120 , V_106 ) ) {
F_10 ( & V_10 -> V_12 , L_4
L_8 ) ;
return - V_124 ;
}
}
return 0 ;
}
static int F_46 ( struct V_9 * V_10 )
{
int V_148 , V_149 ;
F_43 ( V_10 ) ;
V_148 = F_11 ( V_10 , V_122 ) & 0xEE ;
V_149 = F_11 ( V_10 , V_88 ) & 0x17 ;
F_47 ( & V_10 -> V_12 , L_9 , V_148 , V_149 ) ;
return ( V_148 == 0x80 && V_149 == 0x07 ) ? 1 : 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_150 * V_151 = V_10 -> V_12 . V_152 ;
F_49 ( V_10 -> V_153 , V_4 ) ;
F_30 ( V_10 ) ;
if ( V_151 -> V_154 )
V_151 -> V_154 ( 0 ) ;
F_50 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_150 * V_151 = V_10 -> V_12 . V_152 ;
F_50 ( V_2 ) ;
V_4 -> V_155 = 1 ;
F_49 ( V_10 -> V_153 , V_4 ) ;
F_52 ( V_4 -> V_92 ) ;
V_4 -> V_92 = NULL ;
F_53 ( & V_4 -> V_156 ) ;
F_13 ( V_10 , V_107 , 0x00 ) ;
F_13 ( V_10 , V_157 , 0x00 ) ;
F_13 ( V_10 , F_17 ( 0 ) , 0 ) ;
F_1 ( V_2 ) ;
F_30 ( V_10 ) ;
if ( V_151 -> V_154 )
V_151 -> V_154 ( 0 ) ;
V_4 -> V_97 . V_98 = V_158 ;
F_54 ( & V_4 -> V_156 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 , int V_48 , int V_159 )
{
struct V_73 * V_74 ;
struct V_41 * V_42 ;
V_74 = F_56 ( V_2 , & V_42 ) ;
if ( V_74 ) {
V_42 -> V_48 |= V_48 ;
V_42 -> V_67 [ 1 ] = V_159 ;
F_29 ( V_74 ) ;
} else {
F_57 ( V_2 , L_10 ) ;
}
}
static void F_58 ( struct V_160 * V_161 )
{
struct V_3 * V_4 = F_59 ( V_161 , struct V_3 ,
V_93 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_41 * V_42 ;
F_53 ( & V_4 -> V_156 ) ;
if ( V_4 -> V_5 ) {
if ( V_4 -> V_97 . V_98 == V_162 ) {
F_1 ( V_2 ) ;
} else {
V_42 = (struct V_41 * ) V_4 -> V_5 -> V_67 ;
if ( V_42 -> V_66 > V_163 )
V_42 -> V_66 = V_163 ;
F_18 ( V_10 , V_42 , 0 ) ;
V_4 -> V_6 = 1 + V_42 -> V_66 ;
F_60 ( V_4 -> V_5 , V_2 , 0 ) ;
V_4 -> V_5 = NULL ;
}
}
F_54 ( & V_4 -> V_156 ) ;
}
static void F_61 ( struct V_160 * V_161 )
{
struct V_3 * V_4 = F_59 ( V_161 , struct V_3 ,
V_104 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_53 ( & V_4 -> V_156 ) ;
if ( V_4 -> V_102 ) {
F_45 ( 10 ) ;
F_43 ( V_10 ) ;
F_42 ( V_2 , V_4 , V_10 ) ;
if ( V_4 -> V_102 & V_103 ) {
F_37 ( V_10 ) ;
} else if ( V_4 -> V_102 & V_164 ) {
F_62 ( V_2 ) ;
F_1 ( V_2 ) ;
F_37 ( V_10 ) ;
F_63 ( V_2 ) ;
} else {
F_30 ( V_10 ) ;
}
V_4 -> V_102 = 0 ;
V_4 -> V_155 = 0 ;
}
if ( V_4 -> V_100 ) {
V_4 -> V_100 = 0 ;
F_13 ( V_10 , F_17 ( 0 ) , 0 ) ;
F_1 ( V_2 ) ;
F_63 ( V_2 ) ;
F_55 ( V_2 , V_165 , 0 ) ;
}
F_54 ( & V_4 -> V_156 ) ;
}
static T_5 F_64 ( int V_153 , void * V_166 )
{
struct V_3 * V_4 = V_166 ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_53 ( & V_4 -> V_156 ) ;
while ( ! V_4 -> V_155 ) {
enum V_167 V_168 ;
T_1 V_169 , V_170 ;
T_1 V_171 = 0 ;
int V_48 = 0 , V_159 = 0 ;
F_12 ( V_10 , V_157 , & V_169 , & V_170 ) ;
V_169 &= V_172 | V_173 | V_174 ;
if ( V_169 & V_175 ) {
F_26 ( V_10 , 0 ) ;
if ( F_16 ( V_10 ) )
F_14 ( V_10 , V_157 , V_175 , 0x00 ) ;
}
if ( V_169 & V_176 ) {
F_26 ( V_10 , 1 ) ;
if ( F_16 ( V_10 ) )
V_171 |= V_176 ;
}
if ( V_169 & ( V_174 | V_173 ) )
V_171 |= V_169 & ( V_174 | V_173 ) ;
if ( V_171 )
F_14 ( V_10 , V_157 , V_171 , 0x00 ) ;
if ( V_170 )
F_14 ( V_10 , V_177 , V_170 , 0x00 ) ;
if ( V_170 & V_178 ) {
V_168 = V_162 ;
V_48 |= V_179 ;
} else if ( V_170 & V_180 ) {
V_168 = V_181 ;
V_48 |= V_182 ;
V_159 |= V_183 ;
} else if ( V_170 & V_184 ) {
V_168 = V_181 ;
V_48 |= V_182 ;
V_159 |= V_185 ;
} else if ( V_170 & V_186 ) {
V_168 = V_187 ;
V_48 |= V_182 ;
V_159 |= V_188 ;
} else if ( V_170 & V_189 ) {
V_168 = V_187 ;
V_48 |= V_182 ;
V_159 |= V_190 ;
} else {
V_168 = V_99 ;
}
switch ( V_4 -> V_97 . V_98 ) {
case V_99 :
if ( V_168 >= V_187 &&
V_168 <= V_162 )
V_4 -> V_97 . V_191 . V_192 ++ ;
case V_187 :
if ( V_168 >= V_181 &&
V_168 <= V_162 )
V_4 -> V_97 . V_191 . V_193 ++ ;
break;
default:
break;
}
V_4 -> V_97 . V_98 = V_168 ;
if ( V_169 & V_194 ) {
if ( V_170 & ( V_195 | V_196 ) ) {
if ( V_170 & V_195 ) {
V_2 -> V_7 . V_197 ++ ;
V_2 -> V_7 . V_198 ++ ;
}
if ( V_170 & V_196 ) {
V_2 -> V_7 . V_197 ++ ;
V_2 -> V_7 . V_198 ++ ;
}
V_48 |= V_182 ;
V_159 |= V_199 ;
}
F_55 ( V_2 , V_48 , V_159 ) ;
}
if ( V_4 -> V_97 . V_98 == V_162 ) {
if ( V_4 -> V_97 . V_101 == 0 ) {
V_4 -> V_155 = 1 ;
F_65 ( V_2 ) ;
F_30 ( V_10 ) ;
break;
}
}
if ( V_169 == 0 )
break;
if ( V_169 & V_173 ) {
V_2 -> V_7 . V_200 ++ ;
V_2 -> V_7 . V_201 += V_4 -> V_6 - 1 ;
if ( V_4 -> V_6 ) {
F_66 ( V_2 , 0 ) ;
V_4 -> V_6 = 0 ;
}
F_63 ( V_2 ) ;
}
}
F_54 ( & V_4 -> V_156 ) ;
return V_202 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_150 * V_151 = V_10 -> V_12 . V_152 ;
int V_22 ;
V_22 = F_68 ( V_2 ) ;
if ( V_22 ) {
F_10 ( & V_10 -> V_12 , L_11 ) ;
return V_22 ;
}
F_53 ( & V_4 -> V_156 ) ;
if ( V_151 -> V_154 )
V_151 -> V_154 ( 1 ) ;
V_4 -> V_155 = 0 ;
V_4 -> V_5 = NULL ;
V_4 -> V_6 = 0 ;
V_22 = F_69 ( V_10 -> V_153 , NULL , F_64 ,
V_151 -> V_203 ? V_151 -> V_203 : V_204 ,
V_205 , V_4 ) ;
if ( V_22 ) {
F_10 ( & V_10 -> V_12 , L_12 , V_10 -> V_153 ) ;
if ( V_151 -> V_154 )
V_151 -> V_154 ( 0 ) ;
F_50 ( V_2 ) ;
goto V_206;
}
V_4 -> V_92 = F_70 ( L_13 ) ;
F_71 ( & V_4 -> V_93 , F_58 ) ;
F_71 ( & V_4 -> V_104 , F_61 ) ;
V_22 = F_43 ( V_10 ) ;
if ( V_22 ) {
F_48 ( V_2 ) ;
goto V_206;
}
V_22 = F_42 ( V_2 , V_4 , V_10 ) ;
if ( V_22 ) {
F_48 ( V_2 ) ;
goto V_206;
}
V_22 = F_37 ( V_10 ) ;
if ( V_22 ) {
F_48 ( V_2 ) ;
goto V_206;
}
F_63 ( V_2 ) ;
V_206:
F_54 ( & V_4 -> V_156 ) ;
return V_22 ;
}
static int T_6 F_72 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_150 * V_151 = V_10 -> V_12 . V_152 ;
int V_22 = - V_207 ;
if ( ! V_151 )
goto V_208;
V_2 = F_73 ( sizeof( struct V_3 ) , V_209 ) ;
if ( ! V_2 ) {
V_22 = - V_210 ;
goto V_211;
}
V_2 -> V_212 = & V_213 ;
V_2 -> V_214 |= V_215 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_97 . V_216 = & V_217 ;
V_4 -> V_97 . V_218 = F_36 ;
V_4 -> V_97 . clock . V_219 = V_151 -> V_220 / 2 ;
V_4 -> V_97 . V_221 = V_134 |
V_115 | V_117 ;
V_4 -> V_222 = F_74 ( V_10 ) -> V_223 ;
V_4 -> V_2 = V_2 ;
F_75 ( & V_10 -> V_12 , V_4 ) ;
V_4 -> V_10 = V_10 ;
F_76 ( & V_4 -> V_156 ) ;
if ( V_23 ) {
V_10 -> V_12 . V_224 = ~ 0 ;
V_4 -> V_16 = F_77 ( & V_10 -> V_12 ,
V_225 ,
& V_4 -> V_25 ,
V_226 ) ;
if ( V_4 -> V_16 ) {
V_4 -> V_18 = ( V_4 -> V_16 + ( V_225 / 2 ) ) ;
V_4 -> V_27 = ( V_227 ) ( V_4 -> V_25 +
( V_225 / 2 ) ) ;
} else {
V_23 = 0 ;
}
}
if ( ! V_23 ) {
V_4 -> V_16 = F_78 ( V_47 , V_228 ) ;
if ( ! V_4 -> V_16 ) {
V_22 = - V_210 ;
goto V_229;
}
V_4 -> V_18 = F_78 ( V_47 , V_228 ) ;
if ( ! V_4 -> V_18 ) {
V_22 = - V_210 ;
goto V_230;
}
}
if ( V_151 -> V_231 )
V_151 -> V_231 ( 1 ) ;
if ( V_151 -> V_232 )
V_151 -> V_232 ( V_10 ) ;
F_79 ( V_2 , & V_10 -> V_12 ) ;
V_10 -> V_95 = V_233 ;
V_10 -> V_234 = 8 ;
F_80 ( V_10 ) ;
if ( ! F_46 ( V_10 ) ) {
F_41 ( & V_10 -> V_12 , L_14 ) ;
goto V_235;
}
F_30 ( V_10 ) ;
if ( V_151 -> V_154 )
V_151 -> V_154 ( 0 ) ;
V_22 = F_81 ( V_2 ) ;
if ( ! V_22 ) {
F_41 ( & V_10 -> V_12 , L_15 ) ;
return V_22 ;
}
V_235:
if ( ! V_23 )
F_82 ( V_4 -> V_18 ) ;
V_230:
if ( ! V_23 )
F_82 ( V_4 -> V_16 ) ;
V_229:
F_83 ( V_2 ) ;
if ( V_23 )
F_84 ( & V_10 -> V_12 , V_225 ,
V_4 -> V_16 , V_4 -> V_25 ) ;
V_211:
if ( V_151 -> V_231 )
V_151 -> V_231 ( 0 ) ;
F_10 ( & V_10 -> V_12 , L_16 ) ;
V_208:
return V_22 ;
}
static int T_7 F_85 ( struct V_9 * V_10 )
{
struct V_150 * V_151 = V_10 -> V_12 . V_152 ;
struct V_3 * V_4 = F_6 ( & V_10 -> V_12 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_86 ( V_2 ) ;
F_83 ( V_2 ) ;
if ( V_23 ) {
F_84 ( & V_10 -> V_12 , V_225 ,
V_4 -> V_16 , V_4 -> V_25 ) ;
} else {
F_82 ( V_4 -> V_16 ) ;
F_82 ( V_4 -> V_18 ) ;
}
if ( V_151 -> V_231 )
V_151 -> V_231 ( 0 ) ;
return 0 ;
}
static int F_87 ( struct V_9 * V_10 , T_8 V_98 )
{
struct V_150 * V_151 = V_10 -> V_12 . V_152 ;
struct V_3 * V_4 = F_6 ( & V_10 -> V_12 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
V_4 -> V_155 = 1 ;
F_88 ( V_10 -> V_153 ) ;
if ( F_89 ( V_2 ) ) {
F_90 ( V_2 ) ;
F_30 ( V_10 ) ;
if ( V_151 -> V_154 )
V_151 -> V_154 ( 0 ) ;
V_4 -> V_102 = V_164 ;
} else {
V_4 -> V_102 = V_236 ;
}
if ( V_151 -> V_231 ) {
V_151 -> V_231 ( 0 ) ;
V_4 -> V_102 |= V_237 ;
}
return 0 ;
}
static int F_91 ( struct V_9 * V_10 )
{
struct V_150 * V_151 = V_10 -> V_12 . V_152 ;
struct V_3 * V_4 = F_6 ( & V_10 -> V_12 ) ;
if ( V_4 -> V_102 & V_237 ) {
V_151 -> V_231 ( 1 ) ;
F_35 ( V_4 -> V_92 , & V_4 -> V_104 ) ;
} else {
if ( V_4 -> V_102 & V_164 ) {
if ( V_151 -> V_154 )
V_151 -> V_154 ( 1 ) ;
F_35 ( V_4 -> V_92 , & V_4 -> V_104 ) ;
} else {
V_4 -> V_102 = 0 ;
}
}
V_4 -> V_155 = 0 ;
F_92 ( V_10 -> V_153 ) ;
return 0 ;
}
static int T_9 F_93 ( void )
{
return F_94 ( & V_238 ) ;
}
static void T_10 F_95 ( void )
{
F_96 ( & V_238 ) ;
}
