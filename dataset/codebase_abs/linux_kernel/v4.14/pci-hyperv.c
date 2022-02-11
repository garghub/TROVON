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
static T_1 F_4 ( int V_10 )
{
union V_11 V_12 ;
V_12 . V_13 = 0 ;
V_12 . V_14 . V_15 = F_5 ( V_10 ) ;
V_12 . V_14 . V_16 = F_6 ( V_10 ) ;
return V_12 . V_13 ;
}
static int F_7 ( T_1 V_12 )
{
union V_11 V_17 ;
V_17 . V_13 = V_12 ;
return F_8 ( V_17 . V_14 . V_15 , V_17 . V_14 . V_16 ) ;
}
static void F_9 ( struct V_18 * V_19 , int V_20 ,
int V_21 , T_1 * V_22 )
{
unsigned long V_23 ;
void T_2 * V_24 = V_19 -> V_25 -> V_26 + V_27 + V_20 ;
if ( V_20 + V_21 <= V_28 ) {
memcpy ( V_22 , ( ( V_29 * ) & V_19 -> V_30 . V_31 ) + V_20 , V_21 ) ;
} else if ( V_20 >= V_32 && V_20 + V_21 <=
V_33 ) {
memcpy ( V_22 , ( ( V_29 * ) & V_19 -> V_30 . V_34 ) + V_20 -
V_32 , V_21 ) ;
} else if ( V_20 >= V_35 && V_20 + V_21 <=
V_36 ) {
memcpy ( V_22 , ( V_29 * ) & V_19 -> V_30 . V_37 + V_20 -
V_35 , V_21 ) ;
} else if ( V_20 >= V_36 && V_20 + V_21 <=
V_38 ) {
* V_22 = 0 ;
} else if ( V_20 >= V_39 && V_20 + V_21 <=
V_40 ) {
* V_22 = 0 ;
} else if ( V_20 + V_21 <= V_41 ) {
F_10 ( & V_19 -> V_25 -> V_42 , V_23 ) ;
F_11 ( V_19 -> V_30 . V_43 . V_13 , V_19 -> V_25 -> V_26 ) ;
F_12 () ;
switch ( V_21 ) {
case 1 :
* V_22 = F_13 ( V_24 ) ;
break;
case 2 :
* V_22 = F_14 ( V_24 ) ;
break;
default:
* V_22 = F_15 ( V_24 ) ;
break;
}
F_12 () ;
F_16 ( & V_19 -> V_25 -> V_42 , V_23 ) ;
} else {
F_17 ( & V_19 -> V_25 -> V_44 -> V_45 ,
L_1 ) ;
}
}
static void F_18 ( struct V_18 * V_19 , int V_20 ,
int V_21 , T_1 V_22 )
{
unsigned long V_23 ;
void T_2 * V_24 = V_19 -> V_25 -> V_26 + V_27 + V_20 ;
if ( V_20 >= V_35 &&
V_20 + V_21 <= V_38 ) {
} else if ( V_20 >= V_28 && V_20 + V_21 <= V_41 ) {
F_10 ( & V_19 -> V_25 -> V_42 , V_23 ) ;
F_11 ( V_19 -> V_30 . V_43 . V_13 , V_19 -> V_25 -> V_26 ) ;
F_19 () ;
switch ( V_21 ) {
case 1 :
F_20 ( V_22 , V_24 ) ;
break;
case 2 :
F_21 ( V_22 , V_24 ) ;
break;
default:
F_11 ( V_22 , V_24 ) ;
break;
}
F_12 () ;
F_16 ( & V_19 -> V_25 -> V_42 , V_23 ) ;
} else {
F_17 ( & V_19 -> V_25 -> V_44 -> V_45 ,
L_2 ) ;
}
}
static int F_22 ( struct V_46 * V_47 , unsigned int V_10 ,
int V_20 , int V_21 , T_1 * V_22 )
{
struct V_48 * V_25 =
F_23 ( V_47 -> V_49 , struct V_48 , V_49 ) ;
struct V_18 * V_19 ;
V_19 = F_24 ( V_25 , F_4 ( V_10 ) ) ;
if ( ! V_19 )
return V_50 ;
F_9 ( V_19 , V_20 , V_21 , V_22 ) ;
F_25 ( V_19 , V_51 ) ;
return V_52 ;
}
static int F_26 ( struct V_46 * V_47 , unsigned int V_10 ,
int V_20 , int V_21 , T_1 V_22 )
{
struct V_48 * V_25 =
F_23 ( V_47 -> V_49 , struct V_48 , V_49 ) ;
struct V_18 * V_19 ;
V_19 = F_24 ( V_25 , F_4 ( V_10 ) ) ;
if ( ! V_19 )
return V_50 ;
F_18 ( V_19 , V_20 , V_21 , V_22 ) ;
F_25 ( V_19 , V_51 ) ;
return V_52 ;
}
static void F_27 ( struct V_18 * V_19 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 ;
struct {
struct V_57 V_58 ;
V_29 V_59 [ sizeof( struct V_55 ) ] ;
} V_60 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_56 = (struct V_55 * ) & V_60 . V_58 . V_61 ;
V_56 -> V_62 . type =
V_63 ;
V_56 -> V_12 . V_13 = V_19 -> V_30 . V_43 . V_13 ;
V_56 -> V_54 = * V_54 ;
F_28 ( V_19 -> V_25 -> V_44 -> V_64 , V_56 , sizeof( * V_56 ) ,
( unsigned long ) & V_60 . V_58 , V_65 , 0 ) ;
F_29 ( V_54 ) ;
}
static void F_30 ( struct V_66 * V_67 , struct V_68 * V_69 ,
unsigned int V_70 )
{
struct V_48 * V_25 ;
struct V_18 * V_19 ;
struct V_71 * V_72 ;
struct V_53 * V_54 ;
struct V_73 * V_73 = F_31 ( V_67 , V_70 ) ;
struct V_74 * V_75 = F_32 ( V_73 ) ;
V_72 = F_33 ( V_75 ) ;
V_25 = V_69 -> V_76 ;
V_54 = F_34 ( V_73 ) ;
if ( ! V_54 )
return;
V_73 -> V_77 = NULL ;
V_19 = F_24 ( V_25 , F_4 ( V_72 -> V_10 ) ) ;
if ( ! V_19 ) {
F_29 ( V_54 ) ;
return;
}
F_27 ( V_19 , V_54 ) ;
F_25 ( V_19 , V_51 ) ;
}
static int F_35 ( struct V_73 * V_76 , const struct V_78 * V_79 ,
bool V_80 )
{
struct V_73 * V_81 = V_76 -> V_82 ;
return V_81 -> V_83 -> V_84 ( V_81 , V_79 , V_80 ) ;
}
static void F_36 ( struct V_73 * V_76 )
{
F_37 ( V_76 ) ;
}
static void F_38 ( struct V_73 * V_76 )
{
struct V_74 * V_74 = F_32 ( V_76 ) ;
struct V_85 * V_86 = F_39 ( V_76 ) ;
struct V_87 * V_88 ;
struct V_48 * V_25 ;
struct V_78 * V_79 ;
struct V_46 * V_89 ;
struct V_71 * V_72 ;
unsigned long V_23 ;
T_1 V_90 = 0 ;
int V_91 ;
int V_92 ;
T_3 V_93 ;
V_79 = F_40 ( V_76 ) ;
V_72 = F_33 ( V_74 ) ;
V_89 = V_72 -> V_47 ;
V_25 = F_23 ( V_89 -> V_49 , struct V_48 , V_49 ) ;
F_10 ( & V_25 -> V_94 , V_23 ) ;
V_88 = & V_25 -> V_95 ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_96 = V_97 ;
V_88 -> V_98 . V_99 = 1 ;
V_88 -> V_98 . V_100 = V_74 -> V_101 . V_102 ;
V_88 -> V_98 . V_76 = V_74 -> V_101 . V_76 ;
V_88 -> V_103 = ( V_25 -> V_44 -> V_104 . V_105 [ 5 ] << 24 ) |
( V_25 -> V_44 -> V_104 . V_105 [ 4 ] << 16 ) |
( V_25 -> V_44 -> V_104 . V_105 [ 7 ] << 8 ) |
( V_25 -> V_44 -> V_104 . V_105 [ 6 ] & 0xf8 ) |
F_6 ( V_72 -> V_10 ) ;
V_88 -> V_106 . V_107 = V_86 -> V_107 ;
if ( V_108 >= V_109 ) {
V_88 -> V_106 . V_23 |=
V_110 ;
V_88 -> V_106 . V_111 . V_112 =
( 1ull << V_113 ) - 1 ;
V_90 = 1 + V_113 ;
F_41 (cpu, dest, cpu_online_mask) {
V_91 = F_42 ( V_92 ) ;
if ( V_91 >= V_113 * 64 ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_3 , V_91 ) ;
V_93 = 1 ;
goto V_114;
}
V_88 -> V_106 . V_111 . V_115 [ V_91 / 64 ] |=
( 1ULL << ( V_91 & 63 ) ) ;
}
} else {
F_41 (cpu, dest, cpu_online_mask) {
V_88 -> V_106 . V_116 |=
( 1ULL << F_42 ( V_92 ) ) ;
}
}
V_93 = F_43 ( V_117 | ( V_90 << 17 ) ,
V_88 , NULL ) ;
V_114:
F_16 ( & V_25 -> V_94 , V_23 ) ;
if ( V_93 ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_4 , V_118 , V_93 ) ;
return;
}
F_44 ( V_76 ) ;
}
static void F_45 ( void * V_1 , struct V_2 * V_3 ,
int V_4 )
{
struct V_119 * V_6 = V_1 ;
struct V_120 * V_121 =
(struct V_120 * ) V_3 ;
V_6 -> V_6 . V_8 = V_3 -> V_7 ;
V_6 -> V_54 = V_121 -> V_54 ;
F_3 ( & V_6 -> V_6 . V_9 ) ;
}
static T_1 F_46 (
struct V_122 * V_56 , struct V_78 * V_123 ,
T_1 V_13 , V_29 V_107 )
{
V_56 -> V_62 . type = V_124 ;
V_56 -> V_12 . V_13 = V_13 ;
V_56 -> V_54 . V_107 = V_107 ;
V_56 -> V_54 . V_125 = 1 ;
V_56 -> V_54 . V_126 =
( V_127 -> V_128 == V_129 ) ?
V_129 : V_130 ;
V_56 -> V_54 . V_131 = V_132 ;
return sizeof( * V_56 ) ;
}
static T_1 F_47 (
struct V_133 * V_56 , struct V_78 * V_123 ,
T_1 V_13 , V_29 V_107 )
{
int V_92 ;
V_56 -> V_62 . type = V_134 ;
V_56 -> V_12 . V_13 = V_13 ;
V_56 -> V_54 . V_107 = V_107 ;
V_56 -> V_54 . V_125 = 1 ;
V_56 -> V_54 . V_126 =
( V_127 -> V_128 == V_129 ) ?
V_129 : V_130 ;
V_92 = F_48 ( V_123 , V_135 ) ;
V_56 -> V_54 . V_136 [ 0 ] =
F_42 ( V_92 ) ;
V_56 -> V_54 . V_137 = 1 ;
return sizeof( * V_56 ) ;
}
static void F_49 ( struct V_73 * V_76 , struct V_138 * V_101 )
{
struct V_85 * V_86 = F_39 ( V_76 ) ;
struct V_48 * V_25 ;
struct V_18 * V_19 ;
struct V_46 * V_89 ;
struct V_71 * V_72 ;
struct V_119 V_139 ;
struct V_53 * V_54 ;
struct {
struct V_57 V_140 ;
union {
struct V_122 V_141 ;
struct V_133 V_142 ;
} V_143 ;
} V_144 V_60 ;
T_1 V_21 ;
int V_145 ;
V_72 = F_33 ( F_32 ( V_76 ) ) ;
V_89 = V_72 -> V_47 ;
V_25 = F_23 ( V_89 -> V_49 , struct V_48 , V_49 ) ;
V_19 = F_24 ( V_25 , F_4 ( V_72 -> V_10 ) ) ;
if ( ! V_19 )
goto V_146;
if ( V_76 -> V_77 ) {
V_54 = V_76 -> V_77 ;
V_76 -> V_77 = NULL ;
F_27 ( V_19 , V_54 ) ;
}
V_54 = F_50 ( sizeof( * V_54 ) , V_147 ) ;
if ( ! V_54 )
goto V_148;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
F_51 ( & V_139 . V_6 . V_9 ) ;
V_60 . V_140 . V_149 = F_45 ;
V_60 . V_140 . V_150 = & V_139 ;
switch ( V_108 ) {
case V_151 :
V_21 = F_46 ( & V_60 . V_143 . V_141 ,
F_40 ( V_76 ) ,
V_19 -> V_30 . V_43 . V_13 ,
V_86 -> V_107 ) ;
break;
case V_109 :
V_21 = F_47 ( & V_60 . V_143 . V_142 ,
F_40 ( V_76 ) ,
V_19 -> V_30 . V_43 . V_13 ,
V_86 -> V_107 ) ;
break;
default:
F_17 ( & V_25 -> V_44 -> V_45 ,
L_5 ) ;
goto V_152;
}
V_145 = F_28 ( V_19 -> V_25 -> V_44 -> V_64 , & V_60 . V_143 ,
V_21 , ( unsigned long ) & V_60 . V_140 ,
V_65 ,
V_153 ) ;
if ( V_145 ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_6 ,
V_139 . V_6 . V_8 ) ;
goto V_152;
}
while ( ! F_52 ( & V_139 . V_6 . V_9 ) )
F_53 ( 100 ) ;
if ( V_139 . V_6 . V_8 < 0 ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_7 ,
V_139 . V_6 . V_8 ) ;
goto V_152;
}
* V_54 = V_139 . V_54 ;
V_76 -> V_77 = V_54 ;
V_101 -> V_154 = V_139 . V_54 . V_100 >> 32 ;
V_101 -> V_102 = V_139 . V_54 . V_100 & 0xffffffff ;
V_101 -> V_76 = V_139 . V_54 . V_76 ;
F_25 ( V_19 , V_51 ) ;
return;
V_152:
F_29 ( V_54 ) ;
V_148:
F_25 ( V_19 , V_51 ) ;
V_146:
V_101 -> V_154 = 0 ;
V_101 -> V_102 = 0 ;
V_101 -> V_76 = 0 ;
}
static T_4 F_54 ( struct V_68 * V_69 ,
T_5 * V_155 )
{
return V_155 -> V_156 ;
}
static int F_55 ( struct V_48 * V_25 )
{
V_25 -> V_157 . V_83 = & V_158 ;
V_25 -> V_157 . V_159 = & V_160 ;
V_25 -> V_157 . V_23 = ( V_161 |
V_162 | V_163 |
V_164 ) ;
V_25 -> V_157 . V_165 = V_166 ;
V_25 -> V_157 . V_167 = L_8 ;
V_25 -> V_157 . V_76 = V_25 ;
V_25 -> V_66 = F_56 ( V_25 -> V_49 . V_168 ,
& V_25 -> V_157 ,
V_169 ) ;
if ( ! V_25 -> V_66 ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_9 ) ;
return - V_170 ;
}
return 0 ;
}
static T_3 F_57 ( T_3 V_171 )
{
return F_58 ( ( 1 + ~ ( V_171 & V_172 ) ) ,
V_173 ) ;
}
static void F_59 ( struct V_48 * V_25 )
{
struct V_174 * V_175 ;
struct V_18 * V_19 ;
T_6 V_176 = 0 ;
unsigned long V_23 ;
struct V_177 * V_178 ;
T_3 V_171 ;
int V_179 ;
V_178 = F_60 ( & V_25 -> V_180 , NULL ) ;
if ( ! V_178 )
return;
if ( V_25 -> V_181 || V_25 -> V_182 ) {
F_3 ( V_178 ) ;
return;
}
F_10 ( & V_25 -> V_183 , V_23 ) ;
F_61 (iter, &hbus->children) {
V_19 = F_23 ( V_175 , struct V_18 , V_184 ) ;
for ( V_179 = 0 ; V_179 < 6 ; V_179 ++ ) {
if ( V_19 -> V_185 [ V_179 ] & V_186 )
F_17 ( & V_25 -> V_44 -> V_45 ,
L_10 ) ;
if ( V_19 -> V_185 [ V_179 ] != 0 ) {
V_171 = V_19 -> V_185 [ V_179 ] ;
if ( V_171 & V_187 )
V_171 |=
( ( T_3 ) V_19 -> V_185 [ ++ V_179 ] << 32 ) ;
else
V_171 |= 0xffffffff00000000ULL ;
V_176 = F_57 ( V_171 ) ;
if ( V_171 & V_187 )
V_25 -> V_182 += V_176 ;
else
V_25 -> V_181 += V_176 ;
}
}
}
F_16 ( & V_25 -> V_183 , V_23 ) ;
F_3 ( V_178 ) ;
}
static void F_62 ( struct V_48 * V_25 )
{
T_6 V_188 = 0 ;
T_6 V_189 = 0 ;
T_6 V_190 = 0 ;
T_6 V_191 = 0 ;
T_6 V_176 ;
struct V_18 * V_19 ;
struct V_174 * V_175 ;
unsigned long V_23 ;
T_3 V_171 ;
T_1 V_192 ;
bool V_193 ;
int V_179 ;
if ( V_25 -> V_181 ) {
V_189 = 1ULL << ( 63 - F_63 ( V_25 -> V_181 ) ) ;
V_191 = V_25 -> V_194 -> V_195 ;
}
if ( V_25 -> V_182 ) {
V_188 = 1ULL <<
( 63 - F_63 ( V_25 -> V_182 ) ) ;
V_190 = V_25 -> V_196 -> V_195 ;
}
F_10 ( & V_25 -> V_183 , V_23 ) ;
do {
F_61 (iter, &hbus->children) {
V_19 = F_23 ( V_175 , struct V_18 ,
V_184 ) ;
for ( V_179 = 0 ; V_179 < 6 ; V_179 ++ ) {
V_171 = V_19 -> V_185 [ V_179 ] ;
if ( V_171 == 0 )
continue;
V_193 = V_171 & V_187 ;
if ( V_193 ) {
V_171 |=
( ( T_3 ) V_19 -> V_185 [ V_179 + 1 ]
<< 32 ) ;
} else {
V_171 |= 0xffffffffULL << 32 ;
}
V_176 = F_57 ( V_171 ) ;
if ( V_193 ) {
if ( V_188 != V_176 ) {
V_179 ++ ;
continue;
}
F_18 ( V_19 ,
V_197 + ( 4 * V_179 ) ,
4 ,
( T_1 ) ( V_190 & 0xffffff00 ) ) ;
V_179 ++ ;
F_18 ( V_19 ,
V_197 + ( 4 * V_179 ) ,
4 , ( T_1 ) ( V_190 >> 32 ) ) ;
V_190 += V_176 ;
} else {
if ( V_189 != V_176 )
continue;
F_18 ( V_19 ,
V_197 + ( 4 * V_179 ) ,
4 ,
( T_1 ) ( V_191 & 0xffffff00 ) ) ;
V_191 += V_176 ;
}
}
if ( V_188 <= 1 && V_189 <= 1 ) {
F_9 ( V_19 , V_28 , 2 ,
& V_192 ) ;
V_192 |= V_198 ;
F_18 ( V_19 , V_28 , 2 ,
V_192 ) ;
break;
}
}
V_188 >>= 1 ;
V_189 >>= 1 ;
} while ( V_188 || V_189 );
F_16 ( & V_25 -> V_183 , V_23 ) ;
}
static int F_64 ( struct V_48 * V_25 )
{
V_25 -> V_46 = F_65 ( & V_25 -> V_44 -> V_45 ,
0 ,
& V_199 ,
& V_25 -> V_49 ,
& V_25 -> V_200 ) ;
if ( ! V_25 -> V_46 )
return - V_170 ;
V_25 -> V_46 -> V_75 = & V_25 -> V_201 ;
V_25 -> V_46 -> V_75 -> V_15 = & V_25 -> V_44 -> V_45 ;
F_66 () ;
F_67 ( V_25 -> V_46 ) ;
F_68 ( V_25 -> V_46 ) ;
F_69 ( V_25 -> V_46 ) ;
F_70 () ;
V_25 -> V_202 = V_203 ;
return 0 ;
}
static void F_71 ( void * V_1 , struct V_2 * V_3 ,
int V_4 )
{
struct V_204 * V_177 = V_1 ;
struct V_205 * V_206 =
(struct V_205 * ) V_3 ;
int V_179 ;
if ( V_3 -> V_7 < 0 ) {
F_17 ( & V_177 -> V_19 -> V_25 -> V_44 -> V_45 ,
L_11 ,
V_3 -> V_7 ) ;
} else {
for ( V_179 = 0 ; V_179 < 6 ; V_179 ++ ) {
V_177 -> V_19 -> V_185 [ V_179 ] =
V_206 -> V_185 [ V_179 ] ;
}
}
F_3 ( & V_177 -> V_9 ) ;
}
static void F_72 ( struct V_18 * V_19 ,
enum V_207 V_208 )
{
F_73 ( & V_19 -> V_209 ) ;
}
static void F_25 ( struct V_18 * V_19 ,
enum V_207 V_208 )
{
if ( F_74 ( & V_19 -> V_209 ) )
F_29 ( V_19 ) ;
}
static struct V_18 * F_75 ( struct V_48 * V_25 ,
struct V_210 * V_30 )
{
struct V_18 * V_19 ;
struct V_211 * V_212 ;
struct V_204 V_6 ;
struct {
struct V_57 V_213 ;
V_29 V_59 [ sizeof( struct V_211 ) ] ;
} V_58 ;
unsigned long V_23 ;
int V_145 ;
V_19 = F_50 ( sizeof( * V_19 ) , V_147 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_25 = V_25 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
F_51 ( & V_6 . V_9 ) ;
V_6 . V_19 = V_19 ;
V_58 . V_213 . V_150 = & V_6 ;
V_58 . V_213 . V_149 = F_71 ;
V_212 = (struct V_211 * ) & V_58 . V_213 . V_61 ;
V_212 -> V_62 . type = V_214 ;
V_212 -> V_12 . V_13 = V_30 -> V_43 . V_13 ;
V_145 = F_28 ( V_25 -> V_44 -> V_64 , V_212 ,
sizeof( struct V_211 ) ,
( unsigned long ) & V_58 . V_213 ,
V_65 ,
V_153 ) ;
if ( V_145 )
goto error;
F_76 ( & V_6 . V_9 ) ;
V_19 -> V_30 = * V_30 ;
F_77 ( & V_19 -> V_209 , 1 ) ;
F_72 ( V_19 , V_215 ) ;
F_10 ( & V_25 -> V_183 , V_23 ) ;
if ( F_78 ( & V_25 -> V_216 ) )
V_25 -> V_49 . V_67 = V_30 -> V_217 ;
F_79 ( & V_19 -> V_184 , & V_25 -> V_216 ) ;
F_16 ( & V_25 -> V_183 , V_23 ) ;
return V_19 ;
error:
F_29 ( V_19 ) ;
return NULL ;
}
static struct V_18 * F_24 ( struct V_48 * V_25 ,
T_1 V_12 )
{
unsigned long V_23 ;
struct V_18 * V_175 , * V_19 = NULL ;
F_10 ( & V_25 -> V_183 , V_23 ) ;
F_80 (iter, &hbus->children, list_entry) {
if ( V_175 -> V_30 . V_43 . V_13 == V_12 ) {
V_19 = V_175 ;
F_72 ( V_19 , V_51 ) ;
break;
}
}
F_16 ( & V_25 -> V_183 , V_23 ) ;
return V_19 ;
}
static void F_81 ( struct V_218 * V_219 )
{
T_1 V_220 ;
bool V_221 ;
struct V_174 * V_175 ;
struct V_210 * V_222 ;
struct V_18 * V_19 ;
struct V_48 * V_25 ;
struct V_174 V_223 ;
struct V_224 * V_225 ;
struct V_226 * V_227 = NULL ;
unsigned long V_23 ;
V_225 = F_23 ( V_219 , struct V_224 , V_228 ) ;
V_25 = V_225 -> V_47 ;
F_29 ( V_225 ) ;
F_82 ( & V_223 ) ;
if ( F_83 ( & V_25 -> V_229 ) ) {
F_84 ( V_25 ) ;
return;
}
F_10 ( & V_25 -> V_183 , V_23 ) ;
while ( ! F_78 ( & V_25 -> V_230 ) ) {
V_227 = F_85 ( & V_25 -> V_230 , struct V_226 ,
V_184 ) ;
F_86 ( & V_227 -> V_184 ) ;
if ( ! F_78 ( & V_25 -> V_230 ) ) {
F_29 ( V_227 ) ;
continue;
}
}
F_16 ( & V_25 -> V_183 , V_23 ) ;
if ( ! V_227 ) {
F_87 ( & V_25 -> V_229 ) ;
F_84 ( V_25 ) ;
return;
}
F_10 ( & V_25 -> V_183 , V_23 ) ;
F_61 (iter, &hbus->children) {
V_19 = F_23 ( V_175 , struct V_18 ,
V_184 ) ;
V_19 -> V_231 = true ;
}
F_16 ( & V_25 -> V_183 , V_23 ) ;
for ( V_220 = 0 ; V_220 < V_227 -> V_232 ; V_220 ++ ) {
V_221 = false ;
V_222 = & V_227 -> V_16 [ V_220 ] ;
F_10 ( & V_25 -> V_183 , V_23 ) ;
F_61 (iter, &hbus->children) {
V_19 = F_23 ( V_175 , struct V_18 ,
V_184 ) ;
if ( ( V_19 -> V_30 . V_43 . V_13 ==
V_222 -> V_43 . V_13 ) &&
( V_19 -> V_30 . V_31 == V_222 -> V_31 ) &&
( V_19 -> V_30 . V_233 == V_222 -> V_233 ) &&
( V_19 -> V_30 . V_217 == V_222 -> V_217 ) ) {
V_19 -> V_231 = false ;
V_221 = true ;
}
}
F_16 ( & V_25 -> V_183 , V_23 ) ;
if ( ! V_221 ) {
V_19 = F_75 ( V_25 , V_222 ) ;
if ( ! V_19 )
F_17 ( & V_25 -> V_44 -> V_45 ,
L_12 ) ;
}
}
F_10 ( & V_25 -> V_183 , V_23 ) ;
do {
V_221 = false ;
F_61 (iter, &hbus->children) {
V_19 = F_23 ( V_175 , struct V_18 ,
V_184 ) ;
if ( V_19 -> V_231 ) {
V_221 = true ;
F_25 ( V_19 , V_215 ) ;
F_88 ( & V_19 -> V_184 , & V_223 ) ;
break;
}
}
} while ( V_221 );
F_16 ( & V_25 -> V_183 , V_23 ) ;
while ( ! F_78 ( & V_223 ) ) {
V_19 = F_85 ( & V_223 , struct V_18 ,
V_184 ) ;
F_86 ( & V_19 -> V_184 ) ;
F_25 ( V_19 , V_234 ) ;
}
switch ( V_25 -> V_202 ) {
case V_203 :
F_66 () ;
F_67 ( V_25 -> V_46 ) ;
F_70 () ;
break;
case V_235 :
case V_236 :
F_59 ( V_25 ) ;
break;
default:
break;
}
F_87 ( & V_25 -> V_229 ) ;
F_84 ( V_25 ) ;
F_29 ( V_227 ) ;
}
static void F_89 ( struct V_48 * V_25 ,
struct V_237 * V_238 )
{
struct V_226 * V_227 ;
struct V_224 * V_225 ;
unsigned long V_23 ;
V_225 = F_50 ( sizeof( * V_225 ) , V_239 ) ;
if ( ! V_225 )
return;
V_227 = F_50 ( F_90 ( struct V_226 , V_16 ) +
( sizeof( struct V_210 ) *
( V_238 -> V_232 ) ) , V_239 ) ;
if ( ! V_227 ) {
F_29 ( V_225 ) ;
return;
}
F_91 ( & V_225 -> V_228 , F_81 ) ;
V_225 -> V_47 = V_25 ;
V_227 -> V_232 = V_238 -> V_232 ;
if ( V_227 -> V_232 != 0 ) {
memcpy ( V_227 -> V_16 , V_238 -> V_16 ,
sizeof( struct V_210 ) *
V_227 -> V_232 ) ;
}
F_10 ( & V_25 -> V_183 , V_23 ) ;
F_79 ( & V_227 -> V_184 , & V_25 -> V_230 ) ;
F_16 ( & V_25 -> V_183 , V_23 ) ;
F_92 ( V_25 ) ;
F_93 ( & V_225 -> V_228 ) ;
}
static void F_94 ( struct V_218 * V_219 )
{
struct V_240 * V_241 ;
struct V_18 * V_19 ;
struct V_71 * V_72 ;
unsigned long V_23 ;
int V_12 ;
struct {
struct V_57 V_58 ;
V_29 V_59 [ sizeof( struct V_240 ) ] ;
} V_60 ;
V_19 = F_23 ( V_219 , struct V_18 , V_228 ) ;
if ( V_19 -> V_202 != V_242 ) {
F_25 ( V_19 , V_243 ) ;
return;
}
V_12 = F_7 ( V_19 -> V_30 . V_43 . V_13 ) ;
V_72 = F_95 ( V_19 -> V_25 -> V_49 . V_67 , 0 ,
V_12 ) ;
if ( V_72 ) {
F_66 () ;
F_96 ( V_72 ) ;
F_97 ( V_72 ) ;
F_70 () ;
}
F_10 ( & V_19 -> V_25 -> V_183 , V_23 ) ;
F_86 ( & V_19 -> V_184 ) ;
F_16 ( & V_19 -> V_25 -> V_183 , V_23 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_241 = (struct V_240 * ) & V_60 . V_58 . V_61 ;
V_241 -> V_62 . type = V_244 ;
V_241 -> V_12 . V_13 = V_19 -> V_30 . V_43 . V_13 ;
F_28 ( V_19 -> V_25 -> V_44 -> V_64 , V_241 ,
sizeof( * V_241 ) , ( unsigned long ) & V_60 . V_58 ,
V_65 , 0 ) ;
F_25 ( V_19 , V_215 ) ;
F_25 ( V_19 , V_243 ) ;
F_84 ( V_19 -> V_25 ) ;
}
static void F_98 ( struct V_18 * V_19 )
{
V_19 -> V_202 = V_242 ;
F_72 ( V_19 , V_243 ) ;
F_91 ( & V_19 -> V_228 , F_94 ) ;
F_92 ( V_19 -> V_25 ) ;
F_93 ( & V_19 -> V_228 ) ;
}
static void F_99 ( void * V_1 )
{
const int V_245 = 0x100 ;
int V_145 ;
struct V_48 * V_25 = V_1 ;
T_1 V_246 ;
T_3 V_247 ;
struct V_248 * V_30 ;
unsigned char * V_59 ;
int V_249 = V_245 ;
struct V_57 * V_250 ;
struct V_2 * V_251 ;
struct V_252 * V_253 ;
struct V_237 * V_254 ;
struct V_255 * V_256 ;
struct V_18 * V_19 ;
V_59 = F_100 ( V_249 , V_147 ) ;
if ( ! V_59 )
return;
while ( 1 ) {
V_145 = F_101 ( V_25 -> V_44 -> V_64 , V_59 ,
V_249 , & V_246 , & V_247 ) ;
if ( V_145 == - V_257 ) {
F_29 ( V_59 ) ;
V_249 = V_246 ;
V_59 = F_100 ( V_246 , V_147 ) ;
if ( ! V_59 )
return;
continue;
}
if ( V_145 || ! V_246 )
break;
if ( V_246 <= sizeof( struct V_2 ) )
continue;
V_30 = (struct V_248 * ) V_59 ;
switch ( V_30 -> type ) {
case V_258 :
V_250 = (struct V_57 * ) V_247 ;
V_251 = (struct V_2 * ) V_59 ;
V_250 -> V_149 ( V_250 -> V_150 ,
V_251 ,
V_246 ) ;
break;
case V_65 :
V_253 = (struct V_252 * ) V_59 ;
switch ( V_253 -> V_62 . type ) {
case V_259 :
V_254 = (struct V_237 * ) V_59 ;
if ( V_246 <
F_90 ( struct V_237 , V_16 ) +
( sizeof( struct V_210 ) *
( V_254 -> V_232 ) ) ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_13 ) ;
break;
}
F_89 ( V_25 , V_254 ) ;
break;
case V_260 :
V_256 = (struct V_255 * ) V_59 ;
V_19 = F_24 ( V_25 ,
V_256 -> V_12 . V_13 ) ;
if ( V_19 ) {
F_98 ( V_19 ) ;
F_25 ( V_19 ,
V_51 ) ;
}
break;
default:
F_102 ( & V_25 -> V_44 -> V_45 ,
L_14 ,
V_253 -> V_62 . type ) ;
break;
}
break;
default:
F_17 ( & V_25 -> V_44 -> V_45 ,
L_15 ,
V_30 -> type , V_247 , V_246 ) ;
break;
}
}
F_29 ( V_59 ) ;
}
static int F_103 ( struct V_261 * V_44 )
{
struct V_262 * V_263 ;
struct V_5 V_6 ;
struct V_57 * V_58 ;
int V_145 ;
int V_179 ;
V_58 = F_50 ( sizeof( * V_58 ) + sizeof( * V_263 ) , V_264 ) ;
if ( ! V_58 )
return - V_265 ;
F_51 ( & V_6 . V_9 ) ;
V_58 -> V_149 = F_1 ;
V_58 -> V_150 = & V_6 ;
V_263 = (struct V_262 * ) & V_58 -> V_61 ;
V_263 -> V_62 . type = V_266 ;
for ( V_179 = 0 ; V_179 < F_104 ( V_267 ) ; V_179 ++ ) {
V_263 -> V_268 = V_267 [ V_179 ] ;
V_145 = F_28 ( V_44 -> V_64 , V_263 ,
sizeof( struct V_262 ) ,
( unsigned long ) V_58 , V_65 ,
V_153 ) ;
if ( V_145 ) {
F_17 ( & V_44 -> V_45 ,
L_16 ,
V_145 ) ;
goto exit;
}
F_76 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 >= 0 ) {
V_108 = V_267 [ V_179 ] ;
F_105 ( & V_44 -> V_45 ,
L_17 ,
V_108 ) ;
goto exit;
}
if ( V_6 . V_8 != V_269 ) {
F_17 ( & V_44 -> V_45 ,
L_18 ,
V_6 . V_8 ) ;
V_145 = - V_270 ;
goto exit;
}
F_106 ( & V_6 . V_9 ) ;
}
F_17 ( & V_44 -> V_45 ,
L_19 ) ;
V_145 = - V_270 ;
exit:
F_29 ( V_58 ) ;
return V_145 ;
}
static void F_107 ( struct V_48 * V_25 )
{
if ( V_25 -> V_181 && V_25 -> V_194 ) {
V_25 -> V_194 -> V_23 |= V_271 ;
F_108 ( V_25 -> V_194 -> V_195 ,
F_109 ( V_25 -> V_194 ) ) ;
}
if ( V_25 -> V_182 && V_25 -> V_196 ) {
V_25 -> V_196 -> V_23 |= V_271 ;
F_108 ( V_25 -> V_196 -> V_195 ,
F_109 ( V_25 -> V_196 ) ) ;
}
}
static int F_110 ( struct V_48 * V_25 )
{
T_6 V_272 ;
int V_145 ;
if ( V_25 -> V_181 ) {
V_272 = 1ULL << ( 63 - F_63 ( V_25 -> V_181 ) ) ;
V_145 = F_111 ( & V_25 -> V_194 , V_25 -> V_44 , 0 ,
( T_3 ) ( T_1 ) 0xffffffff ,
V_25 -> V_181 ,
V_272 , false ) ;
if ( V_145 ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_20 ,
V_25 -> V_181 ) ;
return V_145 ;
}
V_25 -> V_194 -> V_23 |= V_273 ;
V_25 -> V_194 -> V_23 &= ~ V_271 ;
F_112 ( & V_25 -> V_200 ,
V_25 -> V_194 ) ;
}
if ( V_25 -> V_182 ) {
V_272 = 1ULL << ( 63 - F_63 ( V_25 -> V_182 ) ) ;
V_145 = F_111 ( & V_25 -> V_196 , V_25 -> V_44 ,
0x100000000 , - 1 ,
V_25 -> V_182 , V_272 ,
false ) ;
if ( V_145 ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_21 ,
V_25 -> V_182 ) ;
goto V_274;
}
V_25 -> V_196 -> V_23 |= V_273 ;
V_25 -> V_196 -> V_23 &= ~ V_271 ;
F_112 ( & V_25 -> V_200 ,
V_25 -> V_196 ) ;
}
return 0 ;
V_274:
if ( V_25 -> V_194 ) {
F_108 ( V_25 -> V_194 -> V_195 ,
F_109 ( V_25 -> V_194 ) ) ;
}
return V_145 ;
}
static int F_113 ( struct V_48 * V_25 )
{
int V_145 ;
V_145 = F_111 ( & V_25 -> V_275 , V_25 -> V_44 , 0 , - 1 ,
V_276 , 0x1000 , false ) ;
if ( V_145 )
return V_145 ;
V_25 -> V_275 -> V_23 |= V_271 ;
return 0 ;
}
static void F_114 ( struct V_48 * V_25 )
{
F_108 ( V_25 -> V_275 -> V_195 , V_276 ) ;
}
static int F_115 ( struct V_261 * V_44 )
{
struct V_48 * V_25 = F_116 ( V_44 ) ;
struct V_277 * V_278 ;
struct V_5 V_6 ;
struct V_57 * V_58 ;
int V_145 ;
V_58 = F_50 ( sizeof( * V_58 ) + sizeof( * V_278 ) , V_264 ) ;
if ( ! V_58 )
return - V_265 ;
F_51 ( & V_6 . V_9 ) ;
V_58 -> V_149 = F_1 ;
V_58 -> V_150 = & V_6 ;
V_278 = (struct V_277 * ) & V_58 -> V_61 ;
V_278 -> V_62 . type = V_279 ;
V_278 -> V_280 = V_25 -> V_275 -> V_195 ;
V_145 = F_28 ( V_44 -> V_64 , V_278 , sizeof( * V_278 ) ,
( unsigned long ) V_58 , V_65 ,
V_153 ) ;
if ( V_145 )
goto exit;
F_76 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
F_17 ( & V_44 -> V_45 ,
L_22 ,
V_6 . V_8 ) ;
V_145 = - V_270 ;
goto exit;
}
V_145 = 0 ;
exit:
F_29 ( V_58 ) ;
return V_145 ;
}
static int F_117 ( struct V_261 * V_44 )
{
struct V_48 * V_25 = F_116 ( V_44 ) ;
struct V_281 V_61 ;
struct V_177 V_139 ;
int V_145 ;
F_51 ( & V_139 ) ;
if ( F_118 ( & V_25 -> V_180 , NULL , & V_139 ) )
return - V_282 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . type = V_283 ;
V_145 = F_28 ( V_44 -> V_64 , & V_61 , sizeof( V_61 ) ,
0 , V_65 , 0 ) ;
if ( V_145 )
return V_145 ;
F_76 ( & V_139 ) ;
return 0 ;
}
static int F_119 ( struct V_261 * V_44 )
{
struct V_48 * V_25 = F_116 ( V_44 ) ;
struct V_284 * V_285 ;
struct V_286 * V_287 ;
struct V_5 V_6 ;
struct V_18 * V_19 ;
struct V_57 * V_58 ;
T_7 V_288 ;
T_1 V_12 ;
int V_145 ;
V_288 = ( V_108 < V_109 )
? sizeof( * V_285 ) : sizeof( * V_287 ) ;
V_58 = F_100 ( sizeof( * V_58 ) + V_288 , V_264 ) ;
if ( ! V_58 )
return - V_265 ;
V_145 = 0 ;
for ( V_12 = 0 ; V_12 < 256 ; V_12 ++ ) {
V_19 = F_24 ( V_25 , V_12 ) ;
if ( ! V_19 )
continue;
memset ( V_58 , 0 , sizeof( * V_58 ) + V_288 ) ;
F_51 ( & V_6 . V_9 ) ;
V_58 -> V_149 = F_1 ;
V_58 -> V_150 = & V_6 ;
if ( V_108 < V_109 ) {
V_285 =
(struct V_284 * ) & V_58 -> V_61 ;
V_285 -> V_62 . type =
V_289 ;
V_285 -> V_12 . V_13 = V_19 -> V_30 . V_43 . V_13 ;
} else {
V_287 =
(struct V_286 * ) & V_58 -> V_61 ;
V_287 -> V_62 . type =
V_290 ;
V_287 -> V_12 . V_13 = V_19 -> V_30 . V_43 . V_13 ;
}
F_25 ( V_19 , V_51 ) ;
V_145 = F_28 ( V_44 -> V_64 , & V_58 -> V_61 ,
V_288 , ( unsigned long ) V_58 ,
V_65 ,
V_153 ) ;
if ( V_145 )
break;
F_76 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
V_145 = - V_270 ;
F_17 ( & V_44 -> V_45 ,
L_23 ,
V_6 . V_8 ) ;
break;
}
}
F_29 ( V_58 ) ;
return V_145 ;
}
static int F_120 ( struct V_261 * V_44 )
{
struct V_48 * V_25 = F_116 ( V_44 ) ;
struct V_211 V_58 ;
struct V_18 * V_19 ;
T_1 V_12 ;
int V_145 ;
for ( V_12 = 0 ; V_12 < 256 ; V_12 ++ ) {
V_19 = F_24 ( V_25 , V_12 ) ;
if ( ! V_19 )
continue;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_62 . type = V_291 ;
V_58 . V_12 . V_13 = V_19 -> V_30 . V_43 . V_13 ;
F_25 ( V_19 , V_51 ) ;
V_145 = F_28 ( V_44 -> V_64 , & V_58 , sizeof( V_58 ) , 0 ,
V_65 , 0 ) ;
if ( V_145 )
return V_145 ;
}
return 0 ;
}
static void F_92 ( struct V_48 * V_25 )
{
F_121 ( & V_25 -> V_292 ) ;
}
static void F_84 ( struct V_48 * V_25 )
{
if ( F_122 ( & V_25 -> V_292 ) )
F_3 ( & V_25 -> V_293 ) ;
}
static int F_123 ( struct V_261 * V_44 ,
const struct V_294 * V_295 )
{
struct V_48 * V_25 ;
int V_145 ;
F_124 ( sizeof( * V_25 ) > V_173 ) ;
V_25 = (struct V_48 * ) F_125 ( V_264 ) ;
if ( ! V_25 )
return - V_265 ;
V_25 -> V_202 = V_235 ;
V_25 -> V_49 . V_67 = V_44 -> V_104 . V_105 [ 9 ] |
V_44 -> V_104 . V_105 [ 8 ] << 8 ;
V_25 -> V_44 = V_44 ;
F_121 ( & V_25 -> V_292 ) ;
F_82 ( & V_25 -> V_216 ) ;
F_82 ( & V_25 -> V_230 ) ;
F_82 ( & V_25 -> V_200 ) ;
F_126 ( & V_25 -> V_42 ) ;
F_126 ( & V_25 -> V_183 ) ;
F_126 ( & V_25 -> V_94 ) ;
F_127 ( & V_25 -> V_229 , 1 ) ;
F_51 ( & V_25 -> V_293 ) ;
V_145 = F_128 ( V_44 -> V_64 , V_296 , V_296 , NULL , 0 ,
F_99 , V_25 ) ;
if ( V_145 )
goto V_297;
F_129 ( V_44 , V_25 ) ;
V_145 = F_103 ( V_44 ) ;
if ( V_145 )
goto V_298;
V_145 = F_113 ( V_25 ) ;
if ( V_145 )
goto V_298;
V_25 -> V_26 = F_130 ( V_25 -> V_275 -> V_195 ,
V_276 ) ;
if ( ! V_25 -> V_26 ) {
F_17 ( & V_44 -> V_45 ,
L_24 ) ;
V_145 = - V_265 ;
goto V_299;
}
V_25 -> V_49 . V_168 = F_131 ( V_25 ) ;
if ( ! V_25 -> V_49 . V_168 ) {
V_145 = - V_265 ;
goto V_300;
}
V_145 = F_55 ( V_25 ) ;
if ( V_145 )
goto V_301;
V_145 = F_117 ( V_44 ) ;
if ( V_145 )
goto V_302;
V_145 = F_115 ( V_44 ) ;
if ( V_145 )
goto V_302;
V_145 = F_110 ( V_25 ) ;
if ( V_145 )
goto V_302;
V_145 = F_119 ( V_44 ) ;
if ( V_145 )
goto V_303;
F_62 ( V_25 ) ;
V_25 -> V_202 = V_236 ;
V_145 = F_64 ( V_25 ) ;
if ( V_145 )
goto V_303;
return 0 ;
V_303:
F_107 ( V_25 ) ;
V_302:
F_132 ( V_25 -> V_66 ) ;
V_301:
F_133 ( V_25 -> V_49 . V_168 ) ;
V_300:
F_134 ( V_25 -> V_26 ) ;
V_299:
F_114 ( V_25 ) ;
V_298:
F_135 ( V_44 -> V_64 ) ;
V_297:
F_136 ( ( unsigned long ) V_25 ) ;
return V_145 ;
}
static void F_137 ( struct V_261 * V_44 )
{
struct V_48 * V_25 = F_116 ( V_44 ) ;
struct {
struct V_57 V_304 ;
V_29 V_59 [ sizeof( struct V_281 ) ] ;
} V_58 ;
struct V_237 V_238 ;
struct V_5 V_6 ;
int V_145 ;
if ( V_44 -> V_64 -> V_305 )
return;
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
F_89 ( V_25 , & V_238 ) ;
V_145 = F_120 ( V_44 ) ;
if ( V_145 )
F_17 ( & V_44 -> V_45 ,
L_25 ) ;
memset ( & V_58 . V_304 , 0 , sizeof( V_58 . V_304 ) ) ;
F_51 ( & V_6 . V_9 ) ;
V_58 . V_304 . V_149 = F_1 ;
V_58 . V_304 . V_150 = & V_6 ;
V_58 . V_304 . V_61 [ 0 ] . type = V_306 ;
V_145 = F_28 ( V_44 -> V_64 , & V_58 . V_304 . V_61 ,
sizeof( struct V_281 ) ,
( unsigned long ) & V_58 . V_304 ,
V_65 ,
V_153 ) ;
if ( ! V_145 )
F_138 ( & V_6 . V_9 , 10 * V_307 ) ;
}
static int F_139 ( struct V_261 * V_44 )
{
struct V_48 * V_25 ;
V_25 = F_116 ( V_44 ) ;
if ( V_25 -> V_202 == V_203 ) {
F_66 () ;
F_140 ( V_25 -> V_46 ) ;
F_141 ( V_25 -> V_46 ) ;
F_70 () ;
V_25 -> V_202 = V_308 ;
}
F_137 ( V_44 ) ;
F_135 ( V_44 -> V_64 ) ;
F_134 ( V_25 -> V_26 ) ;
F_114 ( V_25 ) ;
F_142 ( & V_25 -> V_200 ) ;
F_107 ( V_25 ) ;
F_132 ( V_25 -> V_66 ) ;
F_133 ( V_25 -> V_49 . V_168 ) ;
F_84 ( V_25 ) ;
F_76 ( & V_25 -> V_293 ) ;
F_136 ( ( unsigned long ) V_25 ) ;
return 0 ;
}
static void T_8 F_143 ( void )
{
F_144 ( & V_309 ) ;
}
static int T_9 F_145 ( void )
{
return F_146 ( & V_309 ) ;
}
