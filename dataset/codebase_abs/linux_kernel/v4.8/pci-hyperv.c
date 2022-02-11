static
void
F_1 ( void * V_1 , struct V_2 * V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_1 ;
if ( V_4 >= F_2 ( struct V_2 , V_7 ) )
V_6 -> V_8 = V_3 -> V_7 ;
F_3 ( & V_6 -> V_9 ) ;
}
static T_1 F_4 ( int V_10 )
{
union V_11 V_12 ;
V_12 . V_13 = 0 ;
V_12 . V_14 . V_15 = F_5 ( V_10 ) | ( F_6 ( V_10 ) << 5 ) ;
return V_12 . V_13 ;
}
static int F_7 ( T_1 V_12 )
{
union V_11 V_16 ;
V_16 . V_13 = V_12 ;
return F_8 ( 0 , V_16 . V_14 . V_15 ) ;
}
static void F_9 ( struct V_17 * V_18 , int V_19 ,
int V_20 , T_1 * V_21 )
{
unsigned long V_22 ;
void T_2 * V_23 = V_18 -> V_24 -> V_25 + V_26 + V_19 ;
if ( V_19 + V_20 <= V_27 ) {
memcpy ( V_21 , ( ( V_28 * ) & V_18 -> V_29 . V_30 ) + V_19 , V_20 ) ;
} else if ( V_19 >= V_31 && V_19 + V_20 <=
V_32 ) {
memcpy ( V_21 , ( ( V_28 * ) & V_18 -> V_29 . V_33 ) + V_19 -
V_31 , V_20 ) ;
} else if ( V_19 >= V_34 && V_19 + V_20 <=
V_35 ) {
memcpy ( V_21 , ( V_28 * ) & V_18 -> V_29 . V_36 + V_19 -
V_34 , V_20 ) ;
} else if ( V_19 >= V_35 && V_19 + V_20 <=
V_37 ) {
* V_21 = 0 ;
} else if ( V_19 >= V_38 && V_19 + V_20 <=
V_39 ) {
* V_21 = 0 ;
} else if ( V_19 + V_20 <= V_40 ) {
F_10 ( & V_18 -> V_24 -> V_41 , V_22 ) ;
F_11 ( V_18 -> V_29 . V_42 . V_13 , V_18 -> V_24 -> V_25 ) ;
F_12 () ;
switch ( V_20 ) {
case 1 :
* V_21 = F_13 ( V_23 ) ;
break;
case 2 :
* V_21 = F_14 ( V_23 ) ;
break;
default:
* V_21 = F_15 ( V_23 ) ;
break;
}
F_12 () ;
F_16 ( & V_18 -> V_24 -> V_41 , V_22 ) ;
} else {
F_17 ( & V_18 -> V_24 -> V_43 -> V_44 ,
L_1 ) ;
}
}
static void F_18 ( struct V_17 * V_18 , int V_19 ,
int V_20 , T_1 V_21 )
{
unsigned long V_22 ;
void T_2 * V_23 = V_18 -> V_24 -> V_25 + V_26 + V_19 ;
if ( V_19 >= V_34 &&
V_19 + V_20 <= V_37 ) {
} else if ( V_19 >= V_27 && V_19 + V_20 <= V_40 ) {
F_10 ( & V_18 -> V_24 -> V_41 , V_22 ) ;
F_11 ( V_18 -> V_29 . V_42 . V_13 , V_18 -> V_24 -> V_25 ) ;
F_19 () ;
switch ( V_20 ) {
case 1 :
F_20 ( V_21 , V_23 ) ;
break;
case 2 :
F_21 ( V_21 , V_23 ) ;
break;
default:
F_11 ( V_21 , V_23 ) ;
break;
}
F_12 () ;
F_16 ( & V_18 -> V_24 -> V_41 , V_22 ) ;
} else {
F_17 ( & V_18 -> V_24 -> V_43 -> V_44 ,
L_2 ) ;
}
}
static int F_22 ( struct V_45 * V_46 , unsigned int V_10 ,
int V_19 , int V_20 , T_1 * V_21 )
{
struct V_47 * V_24 =
F_23 ( V_46 -> V_48 , struct V_47 , V_48 ) ;
struct V_17 * V_18 ;
V_18 = F_24 ( V_24 , F_4 ( V_10 ) ) ;
if ( ! V_18 )
return V_49 ;
F_9 ( V_18 , V_19 , V_20 , V_21 ) ;
F_25 ( V_18 , V_50 ) ;
return V_51 ;
}
static int F_26 ( struct V_45 * V_46 , unsigned int V_10 ,
int V_19 , int V_20 , T_1 V_21 )
{
struct V_47 * V_24 =
F_23 ( V_46 -> V_48 , struct V_47 , V_48 ) ;
struct V_17 * V_18 ;
V_18 = F_24 ( V_24 , F_4 ( V_10 ) ) ;
if ( ! V_18 )
return V_49 ;
F_18 ( V_18 , V_19 , V_20 , V_21 ) ;
F_25 ( V_18 , V_50 ) ;
return V_51 ;
}
static void F_27 ( struct V_17 * V_18 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 ;
struct {
struct V_56 V_57 ;
V_28 V_58 [ sizeof( struct V_54 ) -
sizeof( struct V_59 ) ] ;
} V_60 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_55 = (struct V_54 * ) & V_60 . V_57 . V_61 ;
V_55 -> V_62 . V_62 =
V_63 ;
V_55 -> V_12 . V_13 = V_18 -> V_29 . V_42 . V_13 ;
V_55 -> V_53 = * V_53 ;
F_28 ( V_18 -> V_24 -> V_43 -> V_64 , V_55 , sizeof( * V_55 ) ,
( unsigned long ) & V_60 . V_57 , V_65 , 0 ) ;
F_29 ( V_53 ) ;
}
static void F_30 ( struct V_66 * V_67 , struct V_68 * V_69 ,
unsigned int V_70 )
{
struct V_47 * V_24 ;
struct V_17 * V_18 ;
struct V_71 * V_72 ;
struct V_52 * V_53 ;
struct V_73 * V_73 = F_31 ( V_67 , V_70 ) ;
struct V_74 * V_75 = F_32 ( V_73 ) ;
V_72 = F_33 ( V_75 ) ;
V_24 = V_69 -> V_76 ;
V_53 = F_34 ( V_73 ) ;
if ( ! V_53 )
return;
V_73 -> V_77 = NULL ;
V_18 = F_24 ( V_24 , F_4 ( V_72 -> V_10 ) ) ;
if ( ! V_18 ) {
F_29 ( V_53 ) ;
return;
}
F_27 ( V_18 , V_53 ) ;
F_25 ( V_18 , V_50 ) ;
}
static int F_35 ( struct V_73 * V_76 , const struct V_78 * V_79 ,
bool V_80 )
{
struct V_73 * V_81 = V_76 -> V_82 ;
return V_81 -> V_83 -> V_84 ( V_81 , V_79 , V_80 ) ;
}
void F_36 ( struct V_73 * V_76 )
{
F_37 ( V_76 ) ;
}
void F_38 ( struct V_73 * V_76 )
{
struct V_74 * V_74 = F_32 ( V_76 ) ;
struct V_85 * V_86 = F_39 ( V_76 ) ;
struct V_87 V_88 ;
struct V_47 * V_24 ;
struct V_78 * V_79 ;
struct V_45 * V_89 ;
struct V_71 * V_72 ;
int V_90 ;
V_79 = F_40 ( V_76 ) ;
V_72 = F_33 ( V_74 ) ;
V_89 = V_72 -> V_46 ;
V_24 = F_23 ( V_89 -> V_48 , struct V_47 , V_48 ) ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_91 = V_92 ;
V_88 . V_93 = 1 ;
V_88 . V_94 = V_74 -> V_95 . V_96 ;
V_88 . V_76 = V_74 -> V_95 . V_76 ;
V_88 . V_97 = ( V_24 -> V_43 -> V_98 . V_99 [ 5 ] << 24 ) |
( V_24 -> V_43 -> V_98 . V_99 [ 4 ] << 16 ) |
( V_24 -> V_43 -> V_98 . V_99 [ 7 ] << 8 ) |
( V_24 -> V_43 -> V_98 . V_99 [ 6 ] & 0xf8 ) |
F_6 ( V_72 -> V_10 ) ;
V_88 . V_100 = V_86 -> V_100 ;
F_41 (cpu, dest, cpu_online_mask)
V_88 . V_101 |= ( 1ULL << F_42 ( V_90 ) ) ;
F_43 ( V_102 , & V_88 , NULL ) ;
F_44 ( V_76 ) ;
}
static void F_45 ( void * V_1 , struct V_2 * V_3 ,
int V_4 )
{
struct V_103 * V_6 = V_1 ;
struct V_104 * V_105 =
(struct V_104 * ) V_3 ;
V_6 -> V_6 . V_8 = V_3 -> V_7 ;
V_6 -> V_53 = V_105 -> V_53 ;
F_3 ( & V_6 -> V_6 . V_9 ) ;
}
static void F_46 ( struct V_73 * V_76 , struct V_106 * V_95 )
{
struct V_85 * V_86 = F_39 ( V_76 ) ;
struct V_47 * V_24 ;
struct V_17 * V_18 ;
struct V_45 * V_89 ;
struct V_71 * V_72 ;
struct V_107 * V_55 ;
struct V_103 V_108 ;
struct V_52 * V_53 ;
struct V_78 * V_109 ;
struct {
struct V_56 V_57 ;
V_28 V_58 [ sizeof( struct V_107 ) -
sizeof( struct V_59 ) ] ;
} V_60 ;
int V_90 ;
int V_110 ;
V_72 = F_33 ( F_32 ( V_76 ) ) ;
V_89 = V_72 -> V_46 ;
V_24 = F_23 ( V_89 -> V_48 , struct V_47 , V_48 ) ;
V_18 = F_24 ( V_24 , F_4 ( V_72 -> V_10 ) ) ;
if ( ! V_18 )
goto V_111;
if ( V_76 -> V_77 ) {
V_53 = V_76 -> V_77 ;
V_76 -> V_77 = NULL ;
F_27 ( V_18 , V_53 ) ;
}
V_53 = F_47 ( sizeof( * V_53 ) , V_112 ) ;
if ( ! V_53 )
goto V_113;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
F_48 ( & V_108 . V_6 . V_9 ) ;
V_60 . V_57 . V_114 = F_45 ;
V_60 . V_57 . V_115 = & V_108 ;
V_55 = (struct V_107 * ) & V_60 . V_57 . V_61 ;
V_55 -> V_62 . V_62 = V_116 ;
V_55 -> V_12 . V_13 = V_18 -> V_29 . V_42 . V_13 ;
V_55 -> V_53 . V_100 = V_86 -> V_100 ;
V_55 -> V_53 . V_117 = 1 ;
V_55 -> V_53 . V_118 =
( V_119 -> V_120 == V_121 ) ? 1 : 0 ;
V_109 = F_40 ( V_76 ) ;
F_41 (cpu, affinity, cpu_online_mask) {
V_55 -> V_53 . V_122 |=
( 1ULL << F_42 ( V_90 ) ) ;
}
V_110 = F_28 ( V_18 -> V_24 -> V_43 -> V_64 , V_55 ,
sizeof( * V_55 ) , ( unsigned long ) & V_60 . V_57 ,
V_65 ,
V_123 ) ;
if ( ! V_110 )
F_49 ( & V_108 . V_6 . V_9 ) ;
if ( V_108 . V_6 . V_8 < 0 ) {
F_17 ( & V_24 -> V_43 -> V_44 ,
L_3 ,
V_108 . V_6 . V_8 ) ;
goto V_124;
}
* V_53 = V_108 . V_53 ;
V_76 -> V_77 = V_53 ;
V_95 -> V_125 = V_108 . V_53 . V_94 >> 32 ;
V_95 -> V_96 = V_108 . V_53 . V_94 & 0xffffffff ;
V_95 -> V_76 = V_108 . V_53 . V_76 ;
F_25 ( V_18 , V_50 ) ;
return;
V_124:
F_29 ( V_53 ) ;
V_113:
F_25 ( V_18 , V_50 ) ;
V_111:
V_95 -> V_125 = 0 ;
V_95 -> V_96 = 0 ;
V_95 -> V_76 = 0 ;
}
static T_3 F_50 ( struct V_68 * V_69 ,
T_4 * V_126 )
{
return V_126 -> V_127 ;
}
static int F_51 ( struct V_47 * V_24 )
{
V_24 -> V_128 . V_83 = & V_129 ;
V_24 -> V_128 . V_130 = & V_131 ;
V_24 -> V_128 . V_22 = ( V_132 |
V_133 | V_134 |
V_135 ) ;
V_24 -> V_128 . V_136 = V_137 ;
V_24 -> V_128 . V_138 = L_4 ;
V_24 -> V_128 . V_76 = V_24 ;
V_24 -> V_66 = F_52 ( V_24 -> V_48 . V_139 ,
& V_24 -> V_128 ,
V_140 ) ;
if ( ! V_24 -> V_66 ) {
F_17 ( & V_24 -> V_43 -> V_44 ,
L_5 ) ;
return - V_141 ;
}
return 0 ;
}
static T_5 F_53 ( T_5 V_142 )
{
return F_54 ( ( 1 + ~ ( V_142 & V_143 ) ) ,
V_144 ) ;
}
static void F_55 ( struct V_47 * V_24 )
{
struct V_145 * V_146 ;
struct V_17 * V_18 ;
T_6 V_147 = 0 ;
unsigned long V_22 ;
struct V_148 * V_149 ;
T_5 V_142 ;
int V_150 ;
V_149 = F_56 ( & V_24 -> V_151 , NULL ) ;
if ( ! V_149 )
return;
if ( V_24 -> V_152 || V_24 -> V_153 ) {
F_3 ( V_149 ) ;
return;
}
F_10 ( & V_24 -> V_154 , V_22 ) ;
F_57 (iter, &hbus->children) {
V_18 = F_23 ( V_146 , struct V_17 , V_155 ) ;
for ( V_150 = 0 ; V_150 < 6 ; V_150 ++ ) {
if ( V_18 -> V_156 [ V_150 ] & V_157 )
F_17 ( & V_24 -> V_43 -> V_44 ,
L_6 ) ;
if ( V_18 -> V_156 [ V_150 ] != 0 ) {
V_142 = V_18 -> V_156 [ V_150 ] ;
if ( V_142 & V_158 )
V_142 |=
( ( T_5 ) V_18 -> V_156 [ ++ V_150 ] << 32 ) ;
else
V_142 |= 0xffffffff00000000ULL ;
V_147 = F_53 ( V_142 ) ;
if ( V_142 & V_158 )
V_24 -> V_153 += V_147 ;
else
V_24 -> V_152 += V_147 ;
}
}
}
F_16 ( & V_24 -> V_154 , V_22 ) ;
F_3 ( V_149 ) ;
}
static void F_58 ( struct V_47 * V_24 )
{
T_6 V_159 = 0 ;
T_6 V_160 = 0 ;
T_6 V_161 = 0 ;
T_6 V_162 = 0 ;
T_6 V_147 ;
struct V_17 * V_18 ;
struct V_145 * V_146 ;
unsigned long V_22 ;
T_5 V_142 ;
T_1 V_163 ;
bool V_164 ;
int V_150 ;
if ( V_24 -> V_152 ) {
V_160 = 1ULL << ( 63 - F_59 ( V_24 -> V_152 ) ) ;
V_162 = V_24 -> V_165 -> V_166 ;
}
if ( V_24 -> V_153 ) {
V_159 = 1ULL <<
( 63 - F_59 ( V_24 -> V_153 ) ) ;
V_161 = V_24 -> V_167 -> V_166 ;
}
F_10 ( & V_24 -> V_154 , V_22 ) ;
do {
F_57 (iter, &hbus->children) {
V_18 = F_23 ( V_146 , struct V_17 ,
V_155 ) ;
for ( V_150 = 0 ; V_150 < 6 ; V_150 ++ ) {
V_142 = V_18 -> V_156 [ V_150 ] ;
if ( V_142 == 0 )
continue;
V_164 = V_142 & V_158 ;
if ( V_164 ) {
V_142 |=
( ( T_5 ) V_18 -> V_156 [ V_150 + 1 ]
<< 32 ) ;
} else {
V_142 |= 0xffffffffULL << 32 ;
}
V_147 = F_53 ( V_142 ) ;
if ( V_164 ) {
if ( V_159 != V_147 ) {
V_150 ++ ;
continue;
}
F_18 ( V_18 ,
V_168 + ( 4 * V_150 ) ,
4 ,
( T_1 ) ( V_161 & 0xffffff00 ) ) ;
V_150 ++ ;
F_18 ( V_18 ,
V_168 + ( 4 * V_150 ) ,
4 , ( T_1 ) ( V_161 >> 32 ) ) ;
V_161 += V_147 ;
} else {
if ( V_160 != V_147 )
continue;
F_18 ( V_18 ,
V_168 + ( 4 * V_150 ) ,
4 ,
( T_1 ) ( V_162 & 0xffffff00 ) ) ;
V_162 += V_147 ;
}
}
if ( V_159 <= 1 && V_160 <= 1 ) {
F_9 ( V_18 , V_27 , 2 ,
& V_163 ) ;
V_163 |= V_169 ;
F_18 ( V_18 , V_27 , 2 ,
V_163 ) ;
break;
}
}
V_159 >>= 1 ;
V_160 >>= 1 ;
} while ( V_159 || V_160 );
F_16 ( & V_24 -> V_154 , V_22 ) ;
}
static int F_60 ( struct V_47 * V_24 )
{
V_24 -> V_45 = F_61 ( & V_24 -> V_43 -> V_44 ,
0 ,
& V_170 ,
& V_24 -> V_48 ,
& V_24 -> V_171 ) ;
if ( ! V_24 -> V_45 )
return - V_141 ;
V_24 -> V_45 -> V_75 = & V_24 -> V_172 ;
V_24 -> V_45 -> V_75 -> V_173 = & V_24 -> V_43 -> V_44 ;
F_62 ( V_24 -> V_45 ) ;
F_63 ( V_24 -> V_45 ) ;
F_64 ( V_24 -> V_45 ) ;
V_24 -> V_174 = V_175 ;
return 0 ;
}
static void F_65 ( void * V_1 , struct V_2 * V_3 ,
int V_4 )
{
struct V_176 * V_148 = V_1 ;
struct V_177 * V_178 =
(struct V_177 * ) V_3 ;
int V_150 ;
if ( V_3 -> V_7 < 0 ) {
F_17 ( & V_148 -> V_18 -> V_24 -> V_43 -> V_44 ,
L_7 ,
V_3 -> V_7 ) ;
} else {
for ( V_150 = 0 ; V_150 < 6 ; V_150 ++ ) {
V_148 -> V_18 -> V_156 [ V_150 ] =
V_178 -> V_156 [ V_150 ] ;
}
}
F_3 ( & V_148 -> V_9 ) ;
}
static void F_66 ( struct V_17 * V_18 ,
enum V_179 V_180 )
{
F_67 ( & V_18 -> V_181 ) ;
}
static void F_25 ( struct V_17 * V_18 ,
enum V_179 V_180 )
{
if ( F_68 ( & V_18 -> V_181 ) )
F_29 ( V_18 ) ;
}
static struct V_17 * F_69 ( struct V_47 * V_24 ,
struct V_182 * V_29 )
{
struct V_17 * V_18 ;
struct V_183 * V_184 ;
struct V_176 V_6 ;
union {
struct V_56 V_185 ;
V_28 V_58 [ 0x100 ] ;
} V_57 ;
unsigned long V_22 ;
int V_110 ;
V_18 = F_47 ( sizeof( * V_18 ) , V_186 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_24 = V_24 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
F_48 ( & V_6 . V_9 ) ;
V_6 . V_18 = V_18 ;
V_57 . V_185 . V_115 = & V_6 ;
V_57 . V_185 . V_114 = F_65 ;
V_184 = (struct V_183 * ) & V_57 . V_185 . V_61 ;
V_184 -> V_62 = V_187 ;
V_184 -> V_12 . V_13 = V_29 -> V_42 . V_13 ;
V_110 = F_28 ( V_24 -> V_43 -> V_64 , V_184 ,
sizeof( struct V_183 ) ,
( unsigned long ) & V_57 . V_185 ,
V_65 ,
V_123 ) ;
if ( V_110 )
goto error;
F_49 ( & V_6 . V_9 ) ;
V_18 -> V_29 = * V_29 ;
F_66 ( V_18 , V_188 ) ;
F_66 ( V_18 , V_189 ) ;
F_10 ( & V_24 -> V_154 , V_22 ) ;
F_70 ( & V_18 -> V_155 , & V_24 -> V_190 ) ;
F_16 ( & V_24 -> V_154 , V_22 ) ;
return V_18 ;
error:
F_29 ( V_18 ) ;
return NULL ;
}
static struct V_17 * F_24 ( struct V_47 * V_24 ,
T_1 V_12 )
{
unsigned long V_22 ;
struct V_17 * V_146 , * V_18 = NULL ;
F_10 ( & V_24 -> V_154 , V_22 ) ;
F_71 (iter, &hbus->children, list_entry) {
if ( V_146 -> V_29 . V_42 . V_13 == V_12 ) {
V_18 = V_146 ;
F_66 ( V_18 , V_50 ) ;
break;
}
}
F_16 ( & V_24 -> V_154 , V_22 ) ;
return V_18 ;
}
static void F_72 ( struct V_191 * V_192 )
{
T_1 V_193 ;
bool V_194 ;
struct V_145 * V_146 ;
struct V_182 * V_195 ;
struct V_17 * V_18 ;
struct V_47 * V_24 ;
struct V_145 V_196 ;
struct V_197 * V_198 ;
struct V_199 * V_200 = NULL ;
unsigned long V_22 ;
V_198 = F_23 ( V_192 , struct V_197 , V_201 ) ;
V_24 = V_198 -> V_46 ;
F_29 ( V_198 ) ;
F_73 ( & V_196 ) ;
if ( F_74 ( & V_24 -> V_202 ) ) {
F_75 ( V_24 ) ;
return;
}
F_10 ( & V_24 -> V_154 , V_22 ) ;
while ( ! F_76 ( & V_24 -> V_203 ) ) {
V_200 = F_77 ( & V_24 -> V_203 , struct V_199 ,
V_155 ) ;
F_78 ( & V_200 -> V_155 ) ;
if ( ! F_76 ( & V_24 -> V_203 ) ) {
F_29 ( V_200 ) ;
continue;
}
}
F_16 ( & V_24 -> V_154 , V_22 ) ;
if ( ! V_200 ) {
F_79 ( & V_24 -> V_202 ) ;
F_75 ( V_24 ) ;
return;
}
F_10 ( & V_24 -> V_154 , V_22 ) ;
F_57 (iter, &hbus->children) {
V_18 = F_23 ( V_146 , struct V_17 ,
V_155 ) ;
V_18 -> V_204 = true ;
}
F_16 ( & V_24 -> V_154 , V_22 ) ;
for ( V_193 = 0 ; V_193 < V_200 -> V_205 ; V_193 ++ ) {
V_194 = false ;
V_195 = & V_200 -> V_15 [ V_193 ] ;
F_10 ( & V_24 -> V_154 , V_22 ) ;
F_57 (iter, &hbus->children) {
V_18 = F_23 ( V_146 , struct V_17 ,
V_155 ) ;
if ( ( V_18 -> V_29 . V_42 . V_13 ==
V_195 -> V_42 . V_13 ) &&
( V_18 -> V_29 . V_30 == V_195 -> V_30 ) &&
( V_18 -> V_29 . V_206 == V_195 -> V_206 ) &&
( V_18 -> V_29 . V_207 == V_195 -> V_207 ) ) {
V_18 -> V_204 = false ;
V_194 = true ;
}
}
F_16 ( & V_24 -> V_154 , V_22 ) ;
if ( ! V_194 ) {
V_18 = F_69 ( V_24 , V_195 ) ;
if ( ! V_18 )
F_17 ( & V_24 -> V_43 -> V_44 ,
L_8 ) ;
}
}
F_10 ( & V_24 -> V_154 , V_22 ) ;
do {
V_194 = false ;
F_57 (iter, &hbus->children) {
V_18 = F_23 ( V_146 , struct V_17 ,
V_155 ) ;
if ( V_18 -> V_204 ) {
V_194 = true ;
F_25 ( V_18 , V_189 ) ;
F_78 ( & V_18 -> V_155 ) ;
F_70 ( & V_18 -> V_155 , & V_196 ) ;
break;
}
}
} while ( V_194 );
F_16 ( & V_24 -> V_154 , V_22 ) ;
while ( ! F_76 ( & V_196 ) ) {
V_18 = F_77 ( & V_196 , struct V_17 ,
V_155 ) ;
F_78 ( & V_18 -> V_155 ) ;
F_25 ( V_18 , V_188 ) ;
}
if ( V_24 -> V_174 == V_175 ) {
F_80 () ;
F_62 ( V_24 -> V_45 ) ;
F_81 () ;
} else {
F_55 ( V_24 ) ;
}
F_79 ( & V_24 -> V_202 ) ;
F_75 ( V_24 ) ;
F_29 ( V_200 ) ;
}
static void F_82 ( struct V_47 * V_24 ,
struct V_208 * V_209 )
{
struct V_199 * V_200 ;
struct V_197 * V_198 ;
unsigned long V_22 ;
V_198 = F_47 ( sizeof( * V_198 ) , V_210 ) ;
if ( ! V_198 )
return;
V_200 = F_47 ( F_83 ( struct V_199 , V_15 ) +
( sizeof( struct V_182 ) *
( V_209 -> V_205 ) ) , V_210 ) ;
if ( ! V_200 ) {
F_29 ( V_198 ) ;
return;
}
F_84 ( & V_198 -> V_201 , F_72 ) ;
V_198 -> V_46 = V_24 ;
V_200 -> V_205 = V_209 -> V_205 ;
if ( V_200 -> V_205 != 0 ) {
memcpy ( V_200 -> V_15 , V_209 -> V_15 ,
sizeof( struct V_182 ) *
V_200 -> V_205 ) ;
}
F_10 ( & V_24 -> V_154 , V_22 ) ;
F_70 ( & V_200 -> V_155 , & V_24 -> V_203 ) ;
F_16 ( & V_24 -> V_154 , V_22 ) ;
F_85 ( V_24 ) ;
F_86 ( & V_198 -> V_201 ) ;
}
static void F_87 ( struct V_191 * V_192 )
{
struct V_211 * V_212 ;
struct V_17 * V_18 ;
struct V_71 * V_72 ;
unsigned long V_22 ;
int V_12 ;
struct {
struct V_56 V_57 ;
V_28 V_58 [ sizeof( struct V_211 ) -
sizeof( struct V_59 ) ] ;
} V_60 ;
V_18 = F_23 ( V_192 , struct V_17 , V_201 ) ;
if ( V_18 -> V_174 != V_213 ) {
F_25 ( V_18 , V_214 ) ;
return;
}
V_12 = F_7 ( V_18 -> V_29 . V_42 . V_13 ) ;
V_72 = F_88 ( V_18 -> V_24 -> V_48 . V_67 , 0 ,
V_12 ) ;
if ( V_72 ) {
F_89 ( V_72 ) ;
F_90 ( V_72 ) ;
}
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_212 = (struct V_211 * ) & V_60 . V_57 . V_61 ;
V_212 -> V_62 = V_215 ;
V_212 -> V_12 . V_13 = V_18 -> V_29 . V_42 . V_13 ;
F_28 ( V_18 -> V_24 -> V_43 -> V_64 , V_212 ,
sizeof( * V_212 ) , ( unsigned long ) & V_60 . V_57 ,
V_65 , 0 ) ;
F_10 ( & V_18 -> V_24 -> V_154 , V_22 ) ;
F_78 ( & V_18 -> V_155 ) ;
F_16 ( & V_18 -> V_24 -> V_154 , V_22 ) ;
F_25 ( V_18 , V_189 ) ;
F_25 ( V_18 , V_214 ) ;
F_75 ( V_18 -> V_24 ) ;
}
static void F_91 ( struct V_17 * V_18 )
{
V_18 -> V_174 = V_213 ;
F_66 ( V_18 , V_214 ) ;
F_84 ( & V_18 -> V_201 , F_87 ) ;
F_85 ( V_18 -> V_24 ) ;
F_86 ( & V_18 -> V_201 ) ;
}
static void F_92 ( void * V_1 )
{
const int V_216 = 0x100 ;
int V_110 ;
struct V_47 * V_24 = V_1 ;
T_1 V_217 ;
T_5 V_218 ;
struct V_219 * V_29 ;
unsigned char * V_58 ;
int V_220 = V_216 ;
struct V_56 * V_221 ;
struct V_2 * V_222 ;
struct V_223 * V_224 ;
struct V_208 * V_225 ;
struct V_226 * V_227 ;
struct V_17 * V_18 ;
V_58 = F_93 ( V_220 , V_186 ) ;
if ( ! V_58 )
return;
while ( 1 ) {
V_110 = F_94 ( V_24 -> V_43 -> V_64 , V_58 ,
V_220 , & V_217 , & V_218 ) ;
if ( V_110 == - V_228 ) {
F_29 ( V_58 ) ;
V_220 = V_217 ;
V_58 = F_93 ( V_217 , V_186 ) ;
if ( ! V_58 )
return;
continue;
}
if ( V_110 || ! V_217 )
break;
if ( V_217 <= sizeof( struct V_2 ) )
continue;
V_29 = (struct V_219 * ) V_58 ;
switch ( V_29 -> type ) {
case V_229 :
V_221 = (struct V_56 * ) V_218 ;
V_222 = (struct V_2 * ) V_58 ;
V_221 -> V_114 ( V_221 -> V_115 ,
V_222 ,
V_217 ) ;
break;
case V_65 :
V_224 = (struct V_223 * ) V_58 ;
switch ( V_224 -> V_62 . V_62 ) {
case V_230 :
V_225 = (struct V_208 * ) V_58 ;
if ( V_217 <
F_83 ( struct V_208 , V_15 ) +
( sizeof( struct V_182 ) *
( V_225 -> V_205 ) ) ) {
F_17 ( & V_24 -> V_43 -> V_44 ,
L_9 ) ;
break;
}
F_82 ( V_24 , V_225 ) ;
break;
case V_231 :
V_227 = (struct V_226 * ) V_58 ;
V_18 = F_24 ( V_24 ,
V_227 -> V_12 . V_13 ) ;
if ( V_18 ) {
F_91 ( V_18 ) ;
F_25 ( V_18 ,
V_50 ) ;
}
break;
default:
F_95 ( & V_24 -> V_43 -> V_44 ,
L_10 ,
V_224 -> V_62 . V_62 ) ;
break;
}
break;
default:
F_17 ( & V_24 -> V_43 -> V_44 ,
L_11 ,
V_29 -> type , V_218 , V_217 ) ;
break;
}
}
F_29 ( V_58 ) ;
}
static int F_96 ( struct V_232 * V_43 )
{
struct V_233 * V_234 ;
struct V_5 V_6 ;
struct V_56 * V_57 ;
int V_110 ;
V_57 = F_47 ( sizeof( * V_57 ) + sizeof( * V_234 ) , V_112 ) ;
if ( ! V_57 )
return - V_235 ;
F_48 ( & V_6 . V_9 ) ;
V_57 -> V_114 = F_1 ;
V_57 -> V_115 = & V_6 ;
V_234 = (struct V_233 * ) & V_57 -> V_61 ;
V_234 -> V_62 . V_62 = V_236 ;
V_234 -> V_237 = V_238 ;
V_110 = F_28 ( V_43 -> V_64 , V_234 ,
sizeof( struct V_233 ) ,
( unsigned long ) V_57 , V_65 ,
V_123 ) ;
if ( V_110 )
goto exit;
F_49 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
F_17 ( & V_43 -> V_44 ,
L_12 ,
V_6 . V_8 ) ;
V_110 = - V_239 ;
goto exit;
}
V_110 = 0 ;
exit:
F_29 ( V_57 ) ;
return V_110 ;
}
static void F_97 ( struct V_47 * V_24 )
{
if ( V_24 -> V_152 && V_24 -> V_165 ) {
V_24 -> V_165 -> V_22 |= V_240 ;
F_98 ( V_24 -> V_165 -> V_166 ,
F_99 ( V_24 -> V_165 ) ) ;
}
if ( V_24 -> V_153 && V_24 -> V_167 ) {
V_24 -> V_167 -> V_22 |= V_240 ;
F_98 ( V_24 -> V_167 -> V_166 ,
F_99 ( V_24 -> V_167 ) ) ;
}
}
static int F_100 ( struct V_47 * V_24 )
{
T_6 V_241 ;
int V_110 ;
if ( V_24 -> V_152 ) {
V_241 = 1ULL << ( 63 - F_59 ( V_24 -> V_152 ) ) ;
V_110 = F_101 ( & V_24 -> V_165 , V_24 -> V_43 , 0 ,
( T_5 ) ( T_1 ) 0xffffffff ,
V_24 -> V_152 ,
V_241 , false ) ;
if ( V_110 ) {
F_17 ( & V_24 -> V_43 -> V_44 ,
L_13 ,
V_24 -> V_152 ) ;
return V_110 ;
}
V_24 -> V_165 -> V_22 |= V_242 ;
V_24 -> V_165 -> V_22 &= ~ V_240 ;
F_102 ( & V_24 -> V_171 ,
V_24 -> V_165 ) ;
}
if ( V_24 -> V_153 ) {
V_241 = 1ULL << ( 63 - F_59 ( V_24 -> V_153 ) ) ;
V_110 = F_101 ( & V_24 -> V_167 , V_24 -> V_43 ,
0x100000000 , - 1 ,
V_24 -> V_153 , V_241 ,
false ) ;
if ( V_110 ) {
F_17 ( & V_24 -> V_43 -> V_44 ,
L_14 ,
V_24 -> V_153 ) ;
goto V_243;
}
V_24 -> V_167 -> V_22 |= V_242 ;
V_24 -> V_167 -> V_22 &= ~ V_240 ;
F_102 ( & V_24 -> V_171 ,
V_24 -> V_167 ) ;
}
return 0 ;
V_243:
if ( V_24 -> V_165 ) {
F_98 ( V_24 -> V_165 -> V_166 ,
F_99 ( V_24 -> V_165 ) ) ;
}
return V_110 ;
}
static int F_103 ( struct V_47 * V_24 )
{
int V_110 ;
V_110 = F_101 ( & V_24 -> V_244 , V_24 -> V_43 , 0 , - 1 ,
V_245 , 0x1000 , false ) ;
if ( V_110 )
return V_110 ;
V_24 -> V_244 -> V_22 |= V_240 ;
return 0 ;
}
static void F_104 ( struct V_47 * V_24 )
{
F_98 ( V_24 -> V_244 -> V_166 , V_245 ) ;
}
static int F_105 ( struct V_232 * V_43 )
{
struct V_47 * V_24 = F_106 ( V_43 ) ;
struct V_246 * V_247 ;
struct V_5 V_6 ;
struct V_56 * V_57 ;
int V_110 ;
V_57 = F_47 ( sizeof( * V_57 ) + sizeof( * V_247 ) , V_112 ) ;
if ( ! V_57 )
return - V_235 ;
F_48 ( & V_6 . V_9 ) ;
V_57 -> V_114 = F_1 ;
V_57 -> V_115 = & V_6 ;
V_247 = (struct V_246 * ) & V_57 -> V_61 ;
V_247 -> V_62 . V_62 = V_248 ;
V_247 -> V_249 = V_24 -> V_244 -> V_166 ;
V_110 = F_28 ( V_43 -> V_64 , V_247 , sizeof( * V_247 ) ,
( unsigned long ) V_57 , V_65 ,
V_123 ) ;
if ( V_110 )
goto exit;
F_49 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
F_17 ( & V_43 -> V_44 ,
L_15 ,
V_6 . V_8 ) ;
V_110 = - V_239 ;
goto exit;
}
V_110 = 0 ;
exit:
F_29 ( V_57 ) ;
return V_110 ;
}
static int F_107 ( struct V_232 * V_43 )
{
struct V_47 * V_24 = F_106 ( V_43 ) ;
struct V_59 V_61 ;
struct V_148 V_108 ;
int V_110 ;
F_48 ( & V_108 ) ;
if ( F_108 ( & V_24 -> V_151 , NULL , & V_108 ) )
return - V_250 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_62 = V_251 ;
V_110 = F_28 ( V_43 -> V_64 , & V_61 , sizeof( V_61 ) ,
0 , V_65 , 0 ) ;
if ( V_110 )
return V_110 ;
F_49 ( & V_108 ) ;
return 0 ;
}
static int F_109 ( struct V_232 * V_43 )
{
struct V_47 * V_24 = F_106 ( V_43 ) ;
struct V_252 * V_253 ;
struct V_5 V_6 ;
struct V_17 * V_18 ;
struct V_56 * V_57 ;
T_1 V_12 ;
int V_110 ;
V_57 = F_93 ( sizeof( * V_57 ) + sizeof( * V_253 ) , V_112 ) ;
if ( ! V_57 )
return - V_235 ;
V_110 = 0 ;
for ( V_12 = 0 ; V_12 < 256 ; V_12 ++ ) {
V_18 = F_24 ( V_24 , V_12 ) ;
if ( ! V_18 )
continue;
memset ( V_57 , 0 , sizeof( * V_57 ) + sizeof( * V_253 ) ) ;
F_48 ( & V_6 . V_9 ) ;
V_57 -> V_114 = F_1 ;
V_57 -> V_115 = & V_6 ;
V_57 -> V_61 . V_62 = V_254 ;
V_253 = (struct V_252 * ) & V_57 -> V_61 ;
V_253 -> V_12 . V_13 = V_18 -> V_29 . V_42 . V_13 ;
F_25 ( V_18 , V_50 ) ;
V_110 = F_28 (
V_43 -> V_64 , & V_57 -> V_61 ,
sizeof( * V_253 ) ,
( unsigned long ) V_57 ,
V_65 ,
V_123 ) ;
if ( V_110 )
break;
F_49 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
V_110 = - V_239 ;
F_17 ( & V_43 -> V_44 ,
L_16 ,
V_6 . V_8 ) ;
break;
}
}
F_29 ( V_57 ) ;
return V_110 ;
}
static int F_110 ( struct V_232 * V_43 )
{
struct V_47 * V_24 = F_106 ( V_43 ) ;
struct V_183 V_57 ;
struct V_17 * V_18 ;
T_1 V_12 ;
int V_110 ;
for ( V_12 = 0 ; V_12 < 256 ; V_12 ++ ) {
V_18 = F_24 ( V_24 , V_12 ) ;
if ( ! V_18 )
continue;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_62 = V_255 ;
V_57 . V_12 . V_13 = V_18 -> V_29 . V_42 . V_13 ;
F_25 ( V_18 , V_50 ) ;
V_110 = F_28 ( V_43 -> V_64 , & V_57 , sizeof( V_57 ) , 0 ,
V_65 , 0 ) ;
if ( V_110 )
return V_110 ;
}
return 0 ;
}
static void F_85 ( struct V_47 * V_24 )
{
F_67 ( & V_24 -> V_256 ) ;
}
static void F_75 ( struct V_47 * V_24 )
{
if ( F_68 ( & V_24 -> V_256 ) )
F_3 ( & V_24 -> V_257 ) ;
}
static int F_111 ( struct V_232 * V_43 ,
const struct V_258 * V_259 )
{
struct V_47 * V_24 ;
int V_110 ;
V_24 = F_47 ( sizeof( * V_24 ) , V_112 ) ;
if ( ! V_24 )
return - V_235 ;
V_24 -> V_48 . V_67 = V_43 -> V_98 . V_99 [ 9 ] |
V_43 -> V_98 . V_99 [ 8 ] << 8 ;
V_24 -> V_43 = V_43 ;
F_67 ( & V_24 -> V_256 ) ;
F_73 ( & V_24 -> V_190 ) ;
F_73 ( & V_24 -> V_203 ) ;
F_73 ( & V_24 -> V_171 ) ;
F_112 ( & V_24 -> V_41 ) ;
F_112 ( & V_24 -> V_154 ) ;
F_113 ( & V_24 -> V_202 , 1 ) ;
F_48 ( & V_24 -> V_257 ) ;
V_110 = F_114 ( V_43 -> V_64 , V_260 , V_260 , NULL , 0 ,
F_92 , V_24 ) ;
if ( V_110 )
goto V_261;
F_115 ( V_43 , V_24 ) ;
V_110 = F_96 ( V_43 ) ;
if ( V_110 )
goto V_262;
V_110 = F_103 ( V_24 ) ;
if ( V_110 )
goto V_262;
V_24 -> V_25 = F_116 ( V_24 -> V_244 -> V_166 ,
V_245 ) ;
if ( ! V_24 -> V_25 ) {
F_17 ( & V_43 -> V_44 ,
L_17 ) ;
V_110 = - V_235 ;
goto V_263;
}
V_24 -> V_48 . V_139 = F_117 ( V_24 ) ;
if ( ! V_24 -> V_48 . V_139 ) {
V_110 = - V_235 ;
goto V_264;
}
V_110 = F_51 ( V_24 ) ;
if ( V_110 )
goto V_265;
V_110 = F_107 ( V_43 ) ;
if ( V_110 )
goto V_266;
V_110 = F_105 ( V_43 ) ;
if ( V_110 )
goto V_266;
V_110 = F_100 ( V_24 ) ;
if ( V_110 )
goto V_266;
V_110 = F_109 ( V_43 ) ;
if ( V_110 )
goto V_267;
F_58 ( V_24 ) ;
V_24 -> V_174 = V_268 ;
V_110 = F_60 ( V_24 ) ;
if ( V_110 )
goto V_267;
return 0 ;
V_267:
F_97 ( V_24 ) ;
V_266:
F_118 ( V_24 -> V_66 ) ;
V_265:
F_119 ( V_24 -> V_48 . V_139 ) ;
V_264:
F_120 ( V_24 -> V_25 ) ;
V_263:
F_104 ( V_24 ) ;
V_262:
F_121 ( V_43 -> V_64 ) ;
V_261:
F_29 ( V_24 ) ;
return V_110 ;
}
static int F_122 ( struct V_232 * V_43 )
{
int V_110 ;
struct V_47 * V_24 ;
union {
struct V_56 V_269 ;
V_28 V_58 [ 0x100 ] ;
} V_57 ;
struct V_208 V_209 ;
struct V_5 V_6 ;
V_24 = F_106 ( V_43 ) ;
memset ( & V_57 . V_269 , 0 , sizeof( V_57 . V_269 ) ) ;
F_48 ( & V_6 . V_9 ) ;
V_57 . V_269 . V_114 = F_1 ;
V_57 . V_269 . V_115 = & V_6 ;
V_57 . V_269 . V_61 . V_62 = V_270 ;
V_110 = F_28 ( V_43 -> V_64 , & V_57 . V_269 . V_61 ,
sizeof( struct V_59 ) ,
( unsigned long ) & V_57 . V_269 ,
V_65 ,
V_123 ) ;
if ( ! V_110 )
F_123 ( & V_6 . V_9 , 10 * V_271 ) ;
if ( V_24 -> V_174 == V_175 ) {
F_80 () ;
F_124 ( V_24 -> V_45 ) ;
F_125 ( V_24 -> V_45 ) ;
F_81 () ;
}
V_110 = F_110 ( V_43 ) ;
if ( V_110 )
F_17 ( & V_43 -> V_44 ,
L_18 ) ;
F_121 ( V_43 -> V_64 ) ;
memset ( & V_209 , 0 , sizeof( V_209 ) ) ;
F_82 ( V_24 , & V_209 ) ;
F_120 ( V_24 -> V_25 ) ;
F_104 ( V_24 ) ;
F_126 ( & V_24 -> V_171 ) ;
F_97 ( V_24 ) ;
F_118 ( V_24 -> V_66 ) ;
F_119 ( V_24 -> V_48 . V_139 ) ;
F_75 ( V_24 ) ;
F_49 ( & V_24 -> V_257 ) ;
F_29 ( V_24 ) ;
return 0 ;
}
static void T_7 F_127 ( void )
{
F_128 ( & V_272 ) ;
}
static int T_8 F_129 ( void )
{
return F_130 ( & V_272 ) ;
}
