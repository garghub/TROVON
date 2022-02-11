static void F_1 ( void * V_1 , struct V_2 * V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_1 ;
if ( V_4 >= F_2 ( struct V_2 , V_7 ) )
V_6 -> V_8 = V_3 -> V_7 ;
else
V_6 -> V_8 = - 1 ;
F_3 ( & V_6 -> V_9 ) ;
}
static void F_4 ( void * V_10 )
{
int V_11 = F_5 () ;
T_1 V_12 ;
F_6 ( V_12 ) ;
V_13 . V_12 [ V_11 ] = V_12 ;
}
static void F_7 ( void )
{
if ( V_13 . V_14 )
return;
memset ( V_13 . V_12 , - 1 , sizeof( V_13 . V_12 ) ) ;
F_8 ( F_4 , NULL , true ) ;
V_13 . V_14 = true ;
}
static T_2 F_9 ( int V_11 )
{
return V_13 . V_12 [ V_11 ] ;
}
static T_2 F_10 ( int V_15 )
{
union V_16 V_17 ;
V_17 . V_18 = 0 ;
V_17 . V_19 . V_20 = F_11 ( V_15 ) ;
V_17 . V_19 . V_21 = F_12 ( V_15 ) ;
return V_17 . V_18 ;
}
static int F_13 ( T_2 V_17 )
{
union V_16 V_22 ;
V_22 . V_18 = V_17 ;
return F_14 ( V_22 . V_19 . V_20 , V_22 . V_19 . V_21 ) ;
}
static void F_15 ( struct V_23 * V_24 , int V_25 ,
int V_26 , T_2 * V_27 )
{
unsigned long V_28 ;
void T_3 * V_29 = V_24 -> V_30 -> V_31 + V_32 + V_25 ;
if ( V_25 + V_26 <= V_33 ) {
memcpy ( V_27 , ( ( V_34 * ) & V_24 -> V_35 . V_36 ) + V_25 , V_26 ) ;
} else if ( V_25 >= V_37 && V_25 + V_26 <=
V_38 ) {
memcpy ( V_27 , ( ( V_34 * ) & V_24 -> V_35 . V_39 ) + V_25 -
V_37 , V_26 ) ;
} else if ( V_25 >= V_40 && V_25 + V_26 <=
V_41 ) {
memcpy ( V_27 , ( V_34 * ) & V_24 -> V_35 . V_42 + V_25 -
V_40 , V_26 ) ;
} else if ( V_25 >= V_41 && V_25 + V_26 <=
V_43 ) {
* V_27 = 0 ;
} else if ( V_25 >= V_44 && V_25 + V_26 <=
V_45 ) {
* V_27 = 0 ;
} else if ( V_25 + V_26 <= V_46 ) {
F_16 ( & V_24 -> V_30 -> V_47 , V_28 ) ;
F_17 ( V_24 -> V_35 . V_48 . V_18 , V_24 -> V_30 -> V_31 ) ;
F_18 () ;
switch ( V_26 ) {
case 1 :
* V_27 = F_19 ( V_29 ) ;
break;
case 2 :
* V_27 = F_20 ( V_29 ) ;
break;
default:
* V_27 = F_21 ( V_29 ) ;
break;
}
F_18 () ;
F_22 ( & V_24 -> V_30 -> V_47 , V_28 ) ;
} else {
F_23 ( & V_24 -> V_30 -> V_49 -> V_50 ,
L_1 ) ;
}
}
static void F_24 ( struct V_23 * V_24 , int V_25 ,
int V_26 , T_2 V_27 )
{
unsigned long V_28 ;
void T_3 * V_29 = V_24 -> V_30 -> V_31 + V_32 + V_25 ;
if ( V_25 >= V_40 &&
V_25 + V_26 <= V_43 ) {
} else if ( V_25 >= V_33 && V_25 + V_26 <= V_46 ) {
F_16 ( & V_24 -> V_30 -> V_47 , V_28 ) ;
F_17 ( V_24 -> V_35 . V_48 . V_18 , V_24 -> V_30 -> V_31 ) ;
F_25 () ;
switch ( V_26 ) {
case 1 :
F_26 ( V_27 , V_29 ) ;
break;
case 2 :
F_27 ( V_27 , V_29 ) ;
break;
default:
F_17 ( V_27 , V_29 ) ;
break;
}
F_18 () ;
F_22 ( & V_24 -> V_30 -> V_47 , V_28 ) ;
} else {
F_23 ( & V_24 -> V_30 -> V_49 -> V_50 ,
L_2 ) ;
}
}
static int F_28 ( struct V_51 * V_52 , unsigned int V_15 ,
int V_25 , int V_26 , T_2 * V_27 )
{
struct V_53 * V_30 =
F_29 ( V_52 -> V_54 , struct V_53 , V_54 ) ;
struct V_23 * V_24 ;
V_24 = F_30 ( V_30 , F_10 ( V_15 ) ) ;
if ( ! V_24 )
return V_55 ;
F_15 ( V_24 , V_25 , V_26 , V_27 ) ;
F_31 ( V_24 , V_56 ) ;
return V_57 ;
}
static int F_32 ( struct V_51 * V_52 , unsigned int V_15 ,
int V_25 , int V_26 , T_2 V_27 )
{
struct V_53 * V_30 =
F_29 ( V_52 -> V_54 , struct V_53 , V_54 ) ;
struct V_23 * V_24 ;
V_24 = F_30 ( V_30 , F_10 ( V_15 ) ) ;
if ( ! V_24 )
return V_55 ;
F_24 ( V_24 , V_25 , V_26 , V_27 ) ;
F_31 ( V_24 , V_56 ) ;
return V_57 ;
}
static void F_33 ( struct V_23 * V_24 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 ;
struct {
struct V_62 V_63 ;
V_34 V_64 [ sizeof( struct V_60 ) ] ;
} V_65 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_61 = (struct V_60 * ) & V_65 . V_63 . V_66 ;
V_61 -> V_67 . type =
V_68 ;
V_61 -> V_17 . V_18 = V_24 -> V_35 . V_48 . V_18 ;
V_61 -> V_59 = * V_59 ;
F_34 ( V_24 -> V_30 -> V_49 -> V_69 , V_61 , sizeof( * V_61 ) ,
( unsigned long ) & V_65 . V_63 , V_70 , 0 ) ;
F_35 ( V_59 ) ;
}
static void F_36 ( struct V_71 * V_72 , struct V_73 * V_74 ,
unsigned int V_75 )
{
struct V_53 * V_30 ;
struct V_23 * V_24 ;
struct V_76 * V_77 ;
struct V_58 * V_59 ;
struct V_78 * V_78 = F_37 ( V_72 , V_75 ) ;
struct V_79 * V_80 = F_38 ( V_78 ) ;
V_77 = F_39 ( V_80 ) ;
V_30 = V_74 -> V_81 ;
V_59 = F_40 ( V_78 ) ;
if ( ! V_59 )
return;
V_78 -> V_82 = NULL ;
V_24 = F_30 ( V_30 , F_10 ( V_77 -> V_15 ) ) ;
if ( ! V_24 ) {
F_35 ( V_59 ) ;
return;
}
F_33 ( V_24 , V_59 ) ;
F_31 ( V_24 , V_56 ) ;
}
static int F_41 ( struct V_78 * V_81 , const struct V_83 * V_84 ,
bool V_85 )
{
struct V_78 * V_86 = V_81 -> V_87 ;
return V_86 -> V_88 -> V_89 ( V_86 , V_84 , V_85 ) ;
}
static void F_42 ( struct V_78 * V_81 )
{
F_43 ( V_81 ) ;
}
static void F_44 ( struct V_78 * V_81 )
{
struct V_79 * V_79 = F_38 ( V_81 ) ;
struct V_90 * V_91 = F_45 ( V_81 ) ;
struct V_92 * V_93 ;
struct V_53 * V_30 ;
struct V_83 * V_84 ;
struct V_51 * V_94 ;
struct V_76 * V_77 ;
unsigned long V_28 ;
T_2 V_95 = 0 ;
int V_96 ;
int V_11 ;
T_1 V_97 ;
V_84 = F_46 ( V_81 ) ;
V_77 = F_39 ( V_79 ) ;
V_94 = V_77 -> V_52 ;
V_30 = F_29 ( V_94 -> V_54 , struct V_53 , V_54 ) ;
F_16 ( & V_30 -> V_98 , V_28 ) ;
V_93 = & V_30 -> V_99 ;
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
V_93 -> V_100 = V_101 ;
V_93 -> V_102 . V_103 = 1 ;
V_93 -> V_102 . V_104 = V_79 -> V_105 . V_106 ;
V_93 -> V_102 . V_81 = V_79 -> V_105 . V_81 ;
V_93 -> V_107 = ( V_30 -> V_49 -> V_108 . V_109 [ 5 ] << 24 ) |
( V_30 -> V_49 -> V_108 . V_109 [ 4 ] << 16 ) |
( V_30 -> V_49 -> V_108 . V_109 [ 7 ] << 8 ) |
( V_30 -> V_49 -> V_108 . V_109 [ 6 ] & 0xf8 ) |
F_12 ( V_77 -> V_15 ) ;
V_93 -> V_110 . V_111 = V_91 -> V_111 ;
if ( V_112 >= V_113 ) {
V_93 -> V_110 . V_28 |=
V_114 ;
V_93 -> V_110 . V_115 . V_116 =
( 1ull << V_117 ) - 1 ;
V_95 = 1 + V_117 ;
F_47 (cpu, dest, cpu_online_mask) {
V_96 = F_9 ( V_11 ) ;
if ( V_96 >= V_117 * 64 ) {
F_23 ( & V_30 -> V_49 -> V_50 ,
L_3 , V_96 ) ;
V_97 = 1 ;
goto V_118;
}
V_93 -> V_110 . V_115 . V_119 [ V_96 / 64 ] |=
( 1ULL << ( V_96 & 63 ) ) ;
}
} else {
F_47 (cpu, dest, cpu_online_mask) {
V_93 -> V_110 . V_120 |=
( 1ULL << F_9 ( V_11 ) ) ;
}
}
V_97 = F_48 ( V_121 | ( V_95 << 17 ) ,
V_93 , NULL ) ;
V_118:
F_22 ( & V_30 -> V_98 , V_28 ) ;
if ( V_97 ) {
F_23 ( & V_30 -> V_49 -> V_50 ,
L_4 , V_122 , V_97 ) ;
return;
}
F_49 ( V_81 ) ;
}
static void F_50 ( void * V_1 , struct V_2 * V_3 ,
int V_4 )
{
struct V_123 * V_6 = V_1 ;
struct V_124 * V_125 =
(struct V_124 * ) V_3 ;
V_6 -> V_6 . V_8 = V_3 -> V_7 ;
V_6 -> V_59 = V_125 -> V_59 ;
F_3 ( & V_6 -> V_6 . V_9 ) ;
}
static T_2 F_51 (
struct V_126 * V_61 , struct V_83 * V_127 ,
T_2 V_18 , V_34 V_111 )
{
V_61 -> V_67 . type = V_128 ;
V_61 -> V_17 . V_18 = V_18 ;
V_61 -> V_59 . V_111 = V_111 ;
V_61 -> V_59 . V_129 = 1 ;
V_61 -> V_59 . V_130 =
( V_131 -> V_132 == V_133 ) ?
V_133 : V_134 ;
V_61 -> V_59 . V_135 = V_136 ;
return sizeof( * V_61 ) ;
}
static T_2 F_52 (
struct V_137 * V_61 , struct V_83 * V_127 ,
T_2 V_18 , V_34 V_111 )
{
int V_11 ;
V_61 -> V_67 . type = V_138 ;
V_61 -> V_17 . V_18 = V_18 ;
V_61 -> V_59 . V_111 = V_111 ;
V_61 -> V_59 . V_129 = 1 ;
V_61 -> V_59 . V_130 =
( V_131 -> V_132 == V_133 ) ?
V_133 : V_134 ;
V_11 = F_53 ( V_127 , V_139 ) ;
V_61 -> V_59 . V_140 [ 0 ] =
F_9 ( V_11 ) ;
V_61 -> V_59 . V_141 = 1 ;
return sizeof( * V_61 ) ;
}
static void F_54 ( struct V_78 * V_81 , struct V_142 * V_105 )
{
struct V_90 * V_91 = F_45 ( V_81 ) ;
struct V_53 * V_30 ;
struct V_23 * V_24 ;
struct V_51 * V_94 ;
struct V_76 * V_77 ;
struct V_123 V_143 ;
struct V_58 * V_59 ;
struct {
struct V_62 V_144 ;
union {
struct V_126 V_145 ;
struct V_137 V_146 ;
} V_147 ;
} V_148 V_65 ;
T_2 V_26 ;
int V_149 ;
V_77 = F_39 ( F_38 ( V_81 ) ) ;
V_94 = V_77 -> V_52 ;
V_30 = F_29 ( V_94 -> V_54 , struct V_53 , V_54 ) ;
V_24 = F_30 ( V_30 , F_10 ( V_77 -> V_15 ) ) ;
if ( ! V_24 )
goto V_150;
if ( V_81 -> V_82 ) {
V_59 = V_81 -> V_82 ;
V_81 -> V_82 = NULL ;
F_33 ( V_24 , V_59 ) ;
}
V_59 = F_55 ( sizeof( * V_59 ) , V_151 ) ;
if ( ! V_59 )
goto V_152;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
F_56 ( & V_143 . V_6 . V_9 ) ;
V_65 . V_144 . V_153 = F_50 ;
V_65 . V_144 . V_154 = & V_143 ;
switch ( V_112 ) {
case V_155 :
V_26 = F_51 ( & V_65 . V_147 . V_145 ,
F_46 ( V_81 ) ,
V_24 -> V_35 . V_48 . V_18 ,
V_91 -> V_111 ) ;
break;
case V_113 :
V_26 = F_52 ( & V_65 . V_147 . V_146 ,
F_46 ( V_81 ) ,
V_24 -> V_35 . V_48 . V_18 ,
V_91 -> V_111 ) ;
break;
default:
F_23 ( & V_30 -> V_49 -> V_50 ,
L_5 ) ;
goto V_156;
}
V_149 = F_34 ( V_24 -> V_30 -> V_49 -> V_69 , & V_65 . V_147 ,
V_26 , ( unsigned long ) & V_65 . V_144 ,
V_70 ,
V_157 ) ;
if ( V_149 ) {
F_23 ( & V_30 -> V_49 -> V_50 ,
L_6 ,
V_143 . V_6 . V_8 ) ;
goto V_156;
}
F_57 ( & V_143 . V_6 . V_9 ) ;
if ( V_143 . V_6 . V_8 < 0 ) {
F_23 ( & V_30 -> V_49 -> V_50 ,
L_7 ,
V_143 . V_6 . V_8 ) ;
goto V_156;
}
* V_59 = V_143 . V_59 ;
V_81 -> V_82 = V_59 ;
V_105 -> V_158 = V_143 . V_59 . V_104 >> 32 ;
V_105 -> V_106 = V_143 . V_59 . V_104 & 0xffffffff ;
V_105 -> V_81 = V_143 . V_59 . V_81 ;
F_31 ( V_24 , V_56 ) ;
return;
V_156:
F_35 ( V_59 ) ;
V_152:
F_31 ( V_24 , V_56 ) ;
V_150:
V_105 -> V_158 = 0 ;
V_105 -> V_106 = 0 ;
V_105 -> V_81 = 0 ;
}
static T_4 F_58 ( struct V_73 * V_74 ,
T_5 * V_159 )
{
return V_159 -> V_160 ;
}
static int F_59 ( struct V_53 * V_30 )
{
V_30 -> V_161 . V_88 = & V_162 ;
V_30 -> V_161 . V_163 = & V_164 ;
V_30 -> V_161 . V_28 = ( V_165 |
V_166 | V_167 |
V_168 ) ;
V_30 -> V_161 . V_169 = V_170 ;
V_30 -> V_161 . V_171 = L_8 ;
V_30 -> V_161 . V_81 = V_30 ;
V_30 -> V_71 = F_60 ( V_30 -> V_54 . V_172 ,
& V_30 -> V_161 ,
V_173 ) ;
if ( ! V_30 -> V_71 ) {
F_23 ( & V_30 -> V_49 -> V_50 ,
L_9 ) ;
return - V_174 ;
}
return 0 ;
}
static T_1 F_61 ( T_1 V_175 )
{
return F_62 ( ( 1 + ~ ( V_175 & V_176 ) ) ,
V_177 ) ;
}
static void F_63 ( struct V_53 * V_30 )
{
struct V_178 * V_179 ;
struct V_23 * V_24 ;
T_6 V_180 = 0 ;
unsigned long V_28 ;
struct V_181 * V_182 ;
T_1 V_175 ;
int V_183 ;
V_182 = F_64 ( & V_30 -> V_184 , NULL ) ;
if ( ! V_182 )
return;
if ( V_30 -> V_185 || V_30 -> V_186 ) {
F_3 ( V_182 ) ;
return;
}
F_16 ( & V_30 -> V_187 , V_28 ) ;
F_65 (iter, &hbus->children) {
V_24 = F_29 ( V_179 , struct V_23 , V_188 ) ;
for ( V_183 = 0 ; V_183 < 6 ; V_183 ++ ) {
if ( V_24 -> V_189 [ V_183 ] & V_190 )
F_23 ( & V_30 -> V_49 -> V_50 ,
L_10 ) ;
if ( V_24 -> V_189 [ V_183 ] != 0 ) {
V_175 = V_24 -> V_189 [ V_183 ] ;
if ( V_175 & V_191 )
V_175 |=
( ( T_1 ) V_24 -> V_189 [ ++ V_183 ] << 32 ) ;
else
V_175 |= 0xffffffff00000000ULL ;
V_180 = F_61 ( V_175 ) ;
if ( V_175 & V_191 )
V_30 -> V_186 += V_180 ;
else
V_30 -> V_185 += V_180 ;
}
}
}
F_22 ( & V_30 -> V_187 , V_28 ) ;
F_3 ( V_182 ) ;
}
static void F_66 ( struct V_53 * V_30 )
{
T_6 V_192 = 0 ;
T_6 V_193 = 0 ;
T_6 V_194 = 0 ;
T_6 V_195 = 0 ;
T_6 V_180 ;
struct V_23 * V_24 ;
struct V_178 * V_179 ;
unsigned long V_28 ;
T_1 V_175 ;
T_2 V_196 ;
bool V_197 ;
int V_183 ;
if ( V_30 -> V_185 ) {
V_193 = 1ULL << ( 63 - F_67 ( V_30 -> V_185 ) ) ;
V_195 = V_30 -> V_198 -> V_199 ;
}
if ( V_30 -> V_186 ) {
V_192 = 1ULL <<
( 63 - F_67 ( V_30 -> V_186 ) ) ;
V_194 = V_30 -> V_200 -> V_199 ;
}
F_16 ( & V_30 -> V_187 , V_28 ) ;
do {
F_65 (iter, &hbus->children) {
V_24 = F_29 ( V_179 , struct V_23 ,
V_188 ) ;
for ( V_183 = 0 ; V_183 < 6 ; V_183 ++ ) {
V_175 = V_24 -> V_189 [ V_183 ] ;
if ( V_175 == 0 )
continue;
V_197 = V_175 & V_191 ;
if ( V_197 ) {
V_175 |=
( ( T_1 ) V_24 -> V_189 [ V_183 + 1 ]
<< 32 ) ;
} else {
V_175 |= 0xffffffffULL << 32 ;
}
V_180 = F_61 ( V_175 ) ;
if ( V_197 ) {
if ( V_192 != V_180 ) {
V_183 ++ ;
continue;
}
F_24 ( V_24 ,
V_201 + ( 4 * V_183 ) ,
4 ,
( T_2 ) ( V_194 & 0xffffff00 ) ) ;
V_183 ++ ;
F_24 ( V_24 ,
V_201 + ( 4 * V_183 ) ,
4 , ( T_2 ) ( V_194 >> 32 ) ) ;
V_194 += V_180 ;
} else {
if ( V_193 != V_180 )
continue;
F_24 ( V_24 ,
V_201 + ( 4 * V_183 ) ,
4 ,
( T_2 ) ( V_195 & 0xffffff00 ) ) ;
V_195 += V_180 ;
}
}
if ( V_192 <= 1 && V_193 <= 1 ) {
F_15 ( V_24 , V_33 , 2 ,
& V_196 ) ;
V_196 |= V_202 ;
F_24 ( V_24 , V_33 , 2 ,
V_196 ) ;
break;
}
}
V_192 >>= 1 ;
V_193 >>= 1 ;
} while ( V_192 || V_193 );
F_22 ( & V_30 -> V_187 , V_28 ) ;
}
static int F_68 ( struct V_53 * V_30 )
{
V_30 -> V_51 = F_69 ( & V_30 -> V_49 -> V_50 ,
0 ,
& V_203 ,
& V_30 -> V_54 ,
& V_30 -> V_204 ) ;
if ( ! V_30 -> V_51 )
return - V_174 ;
V_30 -> V_51 -> V_80 = & V_30 -> V_205 ;
V_30 -> V_51 -> V_80 -> V_20 = & V_30 -> V_49 -> V_50 ;
F_70 () ;
F_71 ( V_30 -> V_51 ) ;
F_72 ( V_30 -> V_51 ) ;
F_73 ( V_30 -> V_51 ) ;
F_74 () ;
V_30 -> V_206 = V_207 ;
return 0 ;
}
static void F_75 ( void * V_1 , struct V_2 * V_3 ,
int V_4 )
{
struct V_208 * V_181 = V_1 ;
struct V_209 * V_210 =
(struct V_209 * ) V_3 ;
int V_183 ;
if ( V_3 -> V_7 < 0 ) {
F_23 ( & V_181 -> V_24 -> V_30 -> V_49 -> V_50 ,
L_11 ,
V_3 -> V_7 ) ;
} else {
for ( V_183 = 0 ; V_183 < 6 ; V_183 ++ ) {
V_181 -> V_24 -> V_189 [ V_183 ] =
V_210 -> V_189 [ V_183 ] ;
}
}
F_3 ( & V_181 -> V_9 ) ;
}
static void F_76 ( struct V_23 * V_24 ,
enum V_211 V_212 )
{
F_77 ( & V_24 -> V_213 ) ;
}
static void F_31 ( struct V_23 * V_24 ,
enum V_211 V_212 )
{
if ( F_78 ( & V_24 -> V_213 ) )
F_35 ( V_24 ) ;
}
static struct V_23 * F_79 ( struct V_53 * V_30 ,
struct V_214 * V_35 )
{
struct V_23 * V_24 ;
struct V_215 * V_216 ;
struct V_208 V_6 ;
struct {
struct V_62 V_217 ;
V_34 V_64 [ sizeof( struct V_215 ) ] ;
} V_63 ;
unsigned long V_28 ;
int V_149 ;
V_24 = F_55 ( sizeof( * V_24 ) , V_151 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_30 = V_30 ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
F_56 ( & V_6 . V_9 ) ;
V_6 . V_24 = V_24 ;
V_63 . V_217 . V_154 = & V_6 ;
V_63 . V_217 . V_153 = F_75 ;
V_216 = (struct V_215 * ) & V_63 . V_217 . V_66 ;
V_216 -> V_67 . type = V_218 ;
V_216 -> V_17 . V_18 = V_35 -> V_48 . V_18 ;
V_149 = F_34 ( V_30 -> V_49 -> V_69 , V_216 ,
sizeof( struct V_215 ) ,
( unsigned long ) & V_63 . V_217 ,
V_70 ,
V_157 ) ;
if ( V_149 )
goto error;
F_57 ( & V_6 . V_9 ) ;
V_24 -> V_35 = * V_35 ;
F_80 ( & V_24 -> V_213 , 1 ) ;
F_76 ( V_24 , V_219 ) ;
F_16 ( & V_30 -> V_187 , V_28 ) ;
if ( F_81 ( & V_30 -> V_220 ) )
V_30 -> V_54 . V_72 = V_35 -> V_221 ;
F_82 ( & V_24 -> V_188 , & V_30 -> V_220 ) ;
F_22 ( & V_30 -> V_187 , V_28 ) ;
return V_24 ;
error:
F_35 ( V_24 ) ;
return NULL ;
}
static struct V_23 * F_30 ( struct V_53 * V_30 ,
T_2 V_17 )
{
unsigned long V_28 ;
struct V_23 * V_179 , * V_24 = NULL ;
F_16 ( & V_30 -> V_187 , V_28 ) ;
F_83 (iter, &hbus->children, list_entry) {
if ( V_179 -> V_35 . V_48 . V_18 == V_17 ) {
V_24 = V_179 ;
F_76 ( V_24 , V_56 ) ;
break;
}
}
F_22 ( & V_30 -> V_187 , V_28 ) ;
return V_24 ;
}
static void F_84 ( struct V_222 * V_223 )
{
T_2 V_224 ;
bool V_225 ;
struct V_178 * V_179 ;
struct V_214 * V_226 ;
struct V_23 * V_24 ;
struct V_53 * V_30 ;
struct V_178 V_227 ;
struct V_228 * V_229 ;
struct V_230 * V_231 = NULL ;
unsigned long V_28 ;
V_229 = F_29 ( V_223 , struct V_228 , V_232 ) ;
V_30 = V_229 -> V_52 ;
F_35 ( V_229 ) ;
F_85 ( & V_227 ) ;
if ( F_86 ( & V_30 -> V_233 ) ) {
F_87 ( V_30 ) ;
return;
}
F_16 ( & V_30 -> V_187 , V_28 ) ;
while ( ! F_81 ( & V_30 -> V_234 ) ) {
V_231 = F_88 ( & V_30 -> V_234 , struct V_230 ,
V_188 ) ;
F_89 ( & V_231 -> V_188 ) ;
if ( ! F_81 ( & V_30 -> V_234 ) ) {
F_35 ( V_231 ) ;
continue;
}
}
F_22 ( & V_30 -> V_187 , V_28 ) ;
if ( ! V_231 ) {
F_90 ( & V_30 -> V_233 ) ;
F_87 ( V_30 ) ;
return;
}
F_16 ( & V_30 -> V_187 , V_28 ) ;
F_65 (iter, &hbus->children) {
V_24 = F_29 ( V_179 , struct V_23 ,
V_188 ) ;
V_24 -> V_235 = true ;
}
F_22 ( & V_30 -> V_187 , V_28 ) ;
for ( V_224 = 0 ; V_224 < V_231 -> V_236 ; V_224 ++ ) {
V_225 = false ;
V_226 = & V_231 -> V_21 [ V_224 ] ;
F_16 ( & V_30 -> V_187 , V_28 ) ;
F_65 (iter, &hbus->children) {
V_24 = F_29 ( V_179 , struct V_23 ,
V_188 ) ;
if ( ( V_24 -> V_35 . V_48 . V_18 ==
V_226 -> V_48 . V_18 ) &&
( V_24 -> V_35 . V_36 == V_226 -> V_36 ) &&
( V_24 -> V_35 . V_237 == V_226 -> V_237 ) &&
( V_24 -> V_35 . V_221 == V_226 -> V_221 ) ) {
V_24 -> V_235 = false ;
V_225 = true ;
}
}
F_22 ( & V_30 -> V_187 , V_28 ) ;
if ( ! V_225 ) {
V_24 = F_79 ( V_30 , V_226 ) ;
if ( ! V_24 )
F_23 ( & V_30 -> V_49 -> V_50 ,
L_12 ) ;
}
}
F_16 ( & V_30 -> V_187 , V_28 ) ;
do {
V_225 = false ;
F_65 (iter, &hbus->children) {
V_24 = F_29 ( V_179 , struct V_23 ,
V_188 ) ;
if ( V_24 -> V_235 ) {
V_225 = true ;
F_31 ( V_24 , V_219 ) ;
F_91 ( & V_24 -> V_188 , & V_227 ) ;
break;
}
}
} while ( V_225 );
F_22 ( & V_30 -> V_187 , V_28 ) ;
while ( ! F_81 ( & V_227 ) ) {
V_24 = F_88 ( & V_227 , struct V_23 ,
V_188 ) ;
F_89 ( & V_24 -> V_188 ) ;
F_31 ( V_24 , V_238 ) ;
}
switch ( V_30 -> V_206 ) {
case V_207 :
F_70 () ;
F_71 ( V_30 -> V_51 ) ;
F_74 () ;
break;
case V_239 :
case V_240 :
F_63 ( V_30 ) ;
break;
default:
break;
}
F_90 ( & V_30 -> V_233 ) ;
F_87 ( V_30 ) ;
F_35 ( V_231 ) ;
}
static void F_92 ( struct V_53 * V_30 ,
struct V_241 * V_242 )
{
struct V_230 * V_231 ;
struct V_228 * V_229 ;
unsigned long V_28 ;
V_229 = F_55 ( sizeof( * V_229 ) , V_243 ) ;
if ( ! V_229 )
return;
V_231 = F_55 ( F_93 ( struct V_230 , V_21 ) +
( sizeof( struct V_214 ) *
( V_242 -> V_236 ) ) , V_243 ) ;
if ( ! V_231 ) {
F_35 ( V_229 ) ;
return;
}
F_94 ( & V_229 -> V_232 , F_84 ) ;
V_229 -> V_52 = V_30 ;
V_231 -> V_236 = V_242 -> V_236 ;
if ( V_231 -> V_236 != 0 ) {
memcpy ( V_231 -> V_21 , V_242 -> V_21 ,
sizeof( struct V_214 ) *
V_231 -> V_236 ) ;
}
F_16 ( & V_30 -> V_187 , V_28 ) ;
F_82 ( & V_231 -> V_188 , & V_30 -> V_234 ) ;
F_22 ( & V_30 -> V_187 , V_28 ) ;
F_95 ( V_30 ) ;
F_96 ( & V_229 -> V_232 ) ;
}
static void F_97 ( struct V_222 * V_223 )
{
struct V_244 * V_245 ;
struct V_23 * V_24 ;
struct V_76 * V_77 ;
unsigned long V_28 ;
int V_17 ;
struct {
struct V_62 V_63 ;
V_34 V_64 [ sizeof( struct V_244 ) ] ;
} V_65 ;
V_24 = F_29 ( V_223 , struct V_23 , V_232 ) ;
if ( V_24 -> V_206 != V_246 ) {
F_31 ( V_24 , V_247 ) ;
return;
}
V_17 = F_13 ( V_24 -> V_35 . V_48 . V_18 ) ;
V_77 = F_98 ( V_24 -> V_30 -> V_54 . V_72 , 0 ,
V_17 ) ;
if ( V_77 ) {
F_70 () ;
F_99 ( V_77 ) ;
F_100 ( V_77 ) ;
F_74 () ;
}
F_16 ( & V_24 -> V_30 -> V_187 , V_28 ) ;
F_89 ( & V_24 -> V_188 ) ;
F_22 ( & V_24 -> V_30 -> V_187 , V_28 ) ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_245 = (struct V_244 * ) & V_65 . V_63 . V_66 ;
V_245 -> V_67 . type = V_248 ;
V_245 -> V_17 . V_18 = V_24 -> V_35 . V_48 . V_18 ;
F_34 ( V_24 -> V_30 -> V_49 -> V_69 , V_245 ,
sizeof( * V_245 ) , ( unsigned long ) & V_65 . V_63 ,
V_70 , 0 ) ;
F_31 ( V_24 , V_219 ) ;
F_31 ( V_24 , V_247 ) ;
F_87 ( V_24 -> V_30 ) ;
}
static void F_101 ( struct V_23 * V_24 )
{
V_24 -> V_206 = V_246 ;
F_76 ( V_24 , V_247 ) ;
F_94 ( & V_24 -> V_232 , F_97 ) ;
F_95 ( V_24 -> V_30 ) ;
F_96 ( & V_24 -> V_232 ) ;
}
static void F_102 ( void * V_1 )
{
const int V_249 = 0x100 ;
int V_149 ;
struct V_53 * V_30 = V_1 ;
T_2 V_250 ;
T_1 V_251 ;
struct V_252 * V_35 ;
unsigned char * V_64 ;
int V_253 = V_249 ;
struct V_62 * V_254 ;
struct V_2 * V_255 ;
struct V_256 * V_257 ;
struct V_241 * V_258 ;
struct V_259 * V_260 ;
struct V_23 * V_24 ;
V_64 = F_103 ( V_253 , V_151 ) ;
if ( ! V_64 )
return;
while ( 1 ) {
V_149 = F_104 ( V_30 -> V_49 -> V_69 , V_64 ,
V_253 , & V_250 , & V_251 ) ;
if ( V_149 == - V_261 ) {
F_35 ( V_64 ) ;
V_253 = V_250 ;
V_64 = F_103 ( V_250 , V_151 ) ;
if ( ! V_64 )
return;
continue;
}
if ( V_149 || ! V_250 )
break;
if ( V_250 <= sizeof( struct V_2 ) )
continue;
V_35 = (struct V_252 * ) V_64 ;
switch ( V_35 -> type ) {
case V_262 :
V_254 = (struct V_62 * ) V_251 ;
V_255 = (struct V_2 * ) V_64 ;
V_254 -> V_153 ( V_254 -> V_154 ,
V_255 ,
V_250 ) ;
break;
case V_70 :
V_257 = (struct V_256 * ) V_64 ;
switch ( V_257 -> V_67 . type ) {
case V_263 :
V_258 = (struct V_241 * ) V_64 ;
if ( V_250 <
F_93 ( struct V_241 , V_21 ) +
( sizeof( struct V_214 ) *
( V_258 -> V_236 ) ) ) {
F_23 ( & V_30 -> V_49 -> V_50 ,
L_13 ) ;
break;
}
F_92 ( V_30 , V_258 ) ;
break;
case V_264 :
V_260 = (struct V_259 * ) V_64 ;
V_24 = F_30 ( V_30 ,
V_260 -> V_17 . V_18 ) ;
if ( V_24 ) {
F_101 ( V_24 ) ;
F_31 ( V_24 ,
V_56 ) ;
}
break;
default:
F_105 ( & V_30 -> V_49 -> V_50 ,
L_14 ,
V_257 -> V_67 . type ) ;
break;
}
break;
default:
F_23 ( & V_30 -> V_49 -> V_50 ,
L_15 ,
V_35 -> type , V_251 , V_250 ) ;
break;
}
}
F_35 ( V_64 ) ;
}
static int F_106 ( struct V_265 * V_49 )
{
struct V_266 * V_267 ;
struct V_5 V_6 ;
struct V_62 * V_63 ;
int V_149 ;
int V_183 ;
V_63 = F_55 ( sizeof( * V_63 ) + sizeof( * V_267 ) , V_268 ) ;
if ( ! V_63 )
return - V_269 ;
F_56 ( & V_6 . V_9 ) ;
V_63 -> V_153 = F_1 ;
V_63 -> V_154 = & V_6 ;
V_267 = (struct V_266 * ) & V_63 -> V_66 ;
V_267 -> V_67 . type = V_270 ;
for ( V_183 = 0 ; V_183 < F_107 ( V_271 ) ; V_183 ++ ) {
V_267 -> V_272 = V_271 [ V_183 ] ;
V_149 = F_34 ( V_49 -> V_69 , V_267 ,
sizeof( struct V_266 ) ,
( unsigned long ) V_63 , V_70 ,
V_157 ) ;
if ( V_149 ) {
F_23 ( & V_49 -> V_50 ,
L_16 ,
V_149 ) ;
goto exit;
}
F_57 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 >= 0 ) {
V_112 = V_271 [ V_183 ] ;
F_108 ( & V_49 -> V_50 ,
L_17 ,
V_112 ) ;
goto exit;
}
if ( V_6 . V_8 != V_273 ) {
F_23 ( & V_49 -> V_50 ,
L_18 ,
V_6 . V_8 ) ;
V_149 = - V_274 ;
goto exit;
}
F_109 ( & V_6 . V_9 ) ;
}
F_23 ( & V_49 -> V_50 ,
L_19 ) ;
V_149 = - V_274 ;
exit:
F_35 ( V_63 ) ;
return V_149 ;
}
static void F_110 ( struct V_53 * V_30 )
{
if ( V_30 -> V_185 && V_30 -> V_198 ) {
V_30 -> V_198 -> V_28 |= V_275 ;
F_111 ( V_30 -> V_198 -> V_199 ,
F_112 ( V_30 -> V_198 ) ) ;
}
if ( V_30 -> V_186 && V_30 -> V_200 ) {
V_30 -> V_200 -> V_28 |= V_275 ;
F_111 ( V_30 -> V_200 -> V_199 ,
F_112 ( V_30 -> V_200 ) ) ;
}
}
static int F_113 ( struct V_53 * V_30 )
{
T_6 V_276 ;
int V_149 ;
if ( V_30 -> V_185 ) {
V_276 = 1ULL << ( 63 - F_67 ( V_30 -> V_185 ) ) ;
V_149 = F_114 ( & V_30 -> V_198 , V_30 -> V_49 , 0 ,
( T_1 ) ( T_2 ) 0xffffffff ,
V_30 -> V_185 ,
V_276 , false ) ;
if ( V_149 ) {
F_23 ( & V_30 -> V_49 -> V_50 ,
L_20 ,
V_30 -> V_185 ) ;
return V_149 ;
}
V_30 -> V_198 -> V_28 |= V_277 ;
V_30 -> V_198 -> V_28 &= ~ V_275 ;
F_115 ( & V_30 -> V_204 ,
V_30 -> V_198 ) ;
}
if ( V_30 -> V_186 ) {
V_276 = 1ULL << ( 63 - F_67 ( V_30 -> V_186 ) ) ;
V_149 = F_114 ( & V_30 -> V_200 , V_30 -> V_49 ,
0x100000000 , - 1 ,
V_30 -> V_186 , V_276 ,
false ) ;
if ( V_149 ) {
F_23 ( & V_30 -> V_49 -> V_50 ,
L_21 ,
V_30 -> V_186 ) ;
goto V_278;
}
V_30 -> V_200 -> V_28 |= V_277 ;
V_30 -> V_200 -> V_28 &= ~ V_275 ;
F_115 ( & V_30 -> V_204 ,
V_30 -> V_200 ) ;
}
return 0 ;
V_278:
if ( V_30 -> V_198 ) {
F_111 ( V_30 -> V_198 -> V_199 ,
F_112 ( V_30 -> V_198 ) ) ;
}
return V_149 ;
}
static int F_116 ( struct V_53 * V_30 )
{
int V_149 ;
V_149 = F_114 ( & V_30 -> V_279 , V_30 -> V_49 , 0 , - 1 ,
V_280 , 0x1000 , false ) ;
if ( V_149 )
return V_149 ;
V_30 -> V_279 -> V_28 |= V_275 ;
return 0 ;
}
static void F_117 ( struct V_53 * V_30 )
{
F_111 ( V_30 -> V_279 -> V_199 , V_280 ) ;
}
static int F_118 ( struct V_265 * V_49 )
{
struct V_53 * V_30 = F_119 ( V_49 ) ;
struct V_281 * V_282 ;
struct V_5 V_6 ;
struct V_62 * V_63 ;
int V_149 ;
V_63 = F_55 ( sizeof( * V_63 ) + sizeof( * V_282 ) , V_268 ) ;
if ( ! V_63 )
return - V_269 ;
F_56 ( & V_6 . V_9 ) ;
V_63 -> V_153 = F_1 ;
V_63 -> V_154 = & V_6 ;
V_282 = (struct V_281 * ) & V_63 -> V_66 ;
V_282 -> V_67 . type = V_283 ;
V_282 -> V_284 = V_30 -> V_279 -> V_199 ;
V_149 = F_34 ( V_49 -> V_69 , V_282 , sizeof( * V_282 ) ,
( unsigned long ) V_63 , V_70 ,
V_157 ) ;
if ( V_149 )
goto exit;
F_57 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
F_23 ( & V_49 -> V_50 ,
L_22 ,
V_6 . V_8 ) ;
V_149 = - V_274 ;
goto exit;
}
V_149 = 0 ;
exit:
F_35 ( V_63 ) ;
return V_149 ;
}
static int F_120 ( struct V_265 * V_49 )
{
struct V_53 * V_30 = F_119 ( V_49 ) ;
struct V_285 V_66 ;
struct V_181 V_143 ;
int V_149 ;
F_56 ( & V_143 ) ;
if ( F_121 ( & V_30 -> V_184 , NULL , & V_143 ) )
return - V_286 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . type = V_287 ;
V_149 = F_34 ( V_49 -> V_69 , & V_66 , sizeof( V_66 ) ,
0 , V_70 , 0 ) ;
if ( V_149 )
return V_149 ;
F_57 ( & V_143 ) ;
return 0 ;
}
static int F_122 ( struct V_265 * V_49 )
{
struct V_53 * V_30 = F_119 ( V_49 ) ;
struct V_288 * V_289 ;
struct V_290 * V_291 ;
struct V_5 V_6 ;
struct V_23 * V_24 ;
struct V_62 * V_63 ;
T_7 V_292 ;
T_2 V_17 ;
int V_149 ;
V_292 = ( V_112 < V_113 )
? sizeof( * V_289 ) : sizeof( * V_291 ) ;
V_63 = F_103 ( sizeof( * V_63 ) + V_292 , V_268 ) ;
if ( ! V_63 )
return - V_269 ;
V_149 = 0 ;
for ( V_17 = 0 ; V_17 < 256 ; V_17 ++ ) {
V_24 = F_30 ( V_30 , V_17 ) ;
if ( ! V_24 )
continue;
memset ( V_63 , 0 , sizeof( * V_63 ) + V_292 ) ;
F_56 ( & V_6 . V_9 ) ;
V_63 -> V_153 = F_1 ;
V_63 -> V_154 = & V_6 ;
if ( V_112 < V_113 ) {
V_289 =
(struct V_288 * ) & V_63 -> V_66 ;
V_289 -> V_67 . type =
V_293 ;
V_289 -> V_17 . V_18 = V_24 -> V_35 . V_48 . V_18 ;
} else {
V_291 =
(struct V_290 * ) & V_63 -> V_66 ;
V_291 -> V_67 . type =
V_294 ;
V_291 -> V_17 . V_18 = V_24 -> V_35 . V_48 . V_18 ;
}
F_31 ( V_24 , V_56 ) ;
V_149 = F_34 ( V_49 -> V_69 , & V_63 -> V_66 ,
V_292 , ( unsigned long ) V_63 ,
V_70 ,
V_157 ) ;
if ( V_149 )
break;
F_57 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
V_149 = - V_274 ;
F_23 ( & V_49 -> V_50 ,
L_23 ,
V_6 . V_8 ) ;
break;
}
}
F_35 ( V_63 ) ;
return V_149 ;
}
static int F_123 ( struct V_265 * V_49 )
{
struct V_53 * V_30 = F_119 ( V_49 ) ;
struct V_215 V_63 ;
struct V_23 * V_24 ;
T_2 V_17 ;
int V_149 ;
for ( V_17 = 0 ; V_17 < 256 ; V_17 ++ ) {
V_24 = F_30 ( V_30 , V_17 ) ;
if ( ! V_24 )
continue;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_63 . V_67 . type = V_295 ;
V_63 . V_17 . V_18 = V_24 -> V_35 . V_48 . V_18 ;
F_31 ( V_24 , V_56 ) ;
V_149 = F_34 ( V_49 -> V_69 , & V_63 , sizeof( V_63 ) , 0 ,
V_70 , 0 ) ;
if ( V_149 )
return V_149 ;
}
return 0 ;
}
static void F_95 ( struct V_53 * V_30 )
{
F_124 ( & V_30 -> V_296 ) ;
}
static void F_87 ( struct V_53 * V_30 )
{
if ( F_125 ( & V_30 -> V_296 ) )
F_3 ( & V_30 -> V_297 ) ;
}
static int F_126 ( struct V_265 * V_49 ,
const struct V_298 * V_299 )
{
struct V_53 * V_30 ;
int V_149 ;
F_127 ( sizeof( * V_30 ) > V_177 ) ;
V_30 = (struct V_53 * ) F_128 ( V_268 ) ;
if ( ! V_30 )
return - V_269 ;
V_30 -> V_206 = V_239 ;
F_7 () ;
V_30 -> V_54 . V_72 = V_49 -> V_108 . V_109 [ 9 ] |
V_49 -> V_108 . V_109 [ 8 ] << 8 ;
V_30 -> V_49 = V_49 ;
F_124 ( & V_30 -> V_296 ) ;
F_85 ( & V_30 -> V_220 ) ;
F_85 ( & V_30 -> V_234 ) ;
F_85 ( & V_30 -> V_204 ) ;
F_129 ( & V_30 -> V_47 ) ;
F_129 ( & V_30 -> V_187 ) ;
F_129 ( & V_30 -> V_98 ) ;
F_130 ( & V_30 -> V_233 , 1 ) ;
F_56 ( & V_30 -> V_297 ) ;
V_149 = F_131 ( V_49 -> V_69 , V_300 , V_300 , NULL , 0 ,
F_102 , V_30 ) ;
if ( V_149 )
goto V_301;
F_132 ( V_49 , V_30 ) ;
V_149 = F_106 ( V_49 ) ;
if ( V_149 )
goto V_302;
V_149 = F_116 ( V_30 ) ;
if ( V_149 )
goto V_302;
V_30 -> V_31 = F_133 ( V_30 -> V_279 -> V_199 ,
V_280 ) ;
if ( ! V_30 -> V_31 ) {
F_23 ( & V_49 -> V_50 ,
L_24 ) ;
V_149 = - V_269 ;
goto V_303;
}
V_30 -> V_54 . V_172 = F_134 ( V_30 ) ;
if ( ! V_30 -> V_54 . V_172 ) {
V_149 = - V_269 ;
goto V_304;
}
V_149 = F_59 ( V_30 ) ;
if ( V_149 )
goto V_305;
V_149 = F_120 ( V_49 ) ;
if ( V_149 )
goto V_306;
V_149 = F_118 ( V_49 ) ;
if ( V_149 )
goto V_306;
V_149 = F_113 ( V_30 ) ;
if ( V_149 )
goto V_306;
V_149 = F_122 ( V_49 ) ;
if ( V_149 )
goto V_307;
F_66 ( V_30 ) ;
V_30 -> V_206 = V_240 ;
V_149 = F_68 ( V_30 ) ;
if ( V_149 )
goto V_307;
return 0 ;
V_307:
F_110 ( V_30 ) ;
V_306:
F_135 ( V_30 -> V_71 ) ;
V_305:
F_136 ( V_30 -> V_54 . V_172 ) ;
V_304:
F_137 ( V_30 -> V_31 ) ;
V_303:
F_117 ( V_30 ) ;
V_302:
F_138 ( V_49 -> V_69 ) ;
V_301:
F_139 ( ( unsigned long ) V_30 ) ;
return V_149 ;
}
static void F_140 ( struct V_265 * V_49 )
{
struct V_53 * V_30 = F_119 ( V_49 ) ;
struct {
struct V_62 V_308 ;
V_34 V_64 [ sizeof( struct V_285 ) ] ;
} V_63 ;
struct V_241 V_242 ;
struct V_5 V_6 ;
int V_149 ;
if ( V_49 -> V_69 -> V_309 )
return;
memset ( & V_242 , 0 , sizeof( V_242 ) ) ;
F_92 ( V_30 , & V_242 ) ;
V_149 = F_123 ( V_49 ) ;
if ( V_149 )
F_23 ( & V_49 -> V_50 ,
L_25 ) ;
memset ( & V_63 . V_308 , 0 , sizeof( V_63 . V_308 ) ) ;
F_56 ( & V_6 . V_9 ) ;
V_63 . V_308 . V_153 = F_1 ;
V_63 . V_308 . V_154 = & V_6 ;
V_63 . V_308 . V_66 [ 0 ] . type = V_310 ;
V_149 = F_34 ( V_49 -> V_69 , & V_63 . V_308 . V_66 ,
sizeof( struct V_285 ) ,
( unsigned long ) & V_63 . V_308 ,
V_70 ,
V_157 ) ;
if ( ! V_149 )
F_141 ( & V_6 . V_9 , 10 * V_311 ) ;
}
static int F_142 ( struct V_265 * V_49 )
{
struct V_53 * V_30 ;
V_30 = F_119 ( V_49 ) ;
if ( V_30 -> V_206 == V_207 ) {
F_70 () ;
F_143 ( V_30 -> V_51 ) ;
F_144 ( V_30 -> V_51 ) ;
F_74 () ;
V_30 -> V_206 = V_312 ;
}
F_140 ( V_49 ) ;
F_138 ( V_49 -> V_69 ) ;
F_137 ( V_30 -> V_31 ) ;
F_117 ( V_30 ) ;
F_145 ( & V_30 -> V_204 ) ;
F_110 ( V_30 ) ;
F_135 ( V_30 -> V_71 ) ;
F_136 ( V_30 -> V_54 . V_172 ) ;
F_87 ( V_30 ) ;
F_57 ( & V_30 -> V_297 ) ;
F_139 ( ( unsigned long ) V_30 ) ;
return 0 ;
}
static void T_8 F_146 ( void )
{
F_147 ( & V_313 ) ;
}
static int T_9 F_148 ( void )
{
return F_149 ( & V_313 ) ;
}
