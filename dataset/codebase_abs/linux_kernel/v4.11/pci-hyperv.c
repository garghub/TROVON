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
int V_90 ;
unsigned long V_23 ;
V_79 = F_40 ( V_76 ) ;
V_72 = F_33 ( V_74 ) ;
V_89 = V_72 -> V_47 ;
V_25 = F_23 ( V_89 -> V_49 , struct V_48 , V_49 ) ;
F_10 ( & V_25 -> V_91 , V_23 ) ;
V_88 = & V_25 -> V_92 ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_93 = V_94 ;
V_88 -> V_95 = 1 ;
V_88 -> V_96 = V_74 -> V_97 . V_98 ;
V_88 -> V_76 = V_74 -> V_97 . V_76 ;
V_88 -> V_99 = ( V_25 -> V_44 -> V_100 . V_101 [ 5 ] << 24 ) |
( V_25 -> V_44 -> V_100 . V_101 [ 4 ] << 16 ) |
( V_25 -> V_44 -> V_100 . V_101 [ 7 ] << 8 ) |
( V_25 -> V_44 -> V_100 . V_101 [ 6 ] & 0xf8 ) |
F_6 ( V_72 -> V_10 ) ;
V_88 -> V_102 = V_86 -> V_102 ;
F_41 (cpu, dest, cpu_online_mask)
V_88 -> V_103 |= ( 1ULL << F_42 ( V_90 ) ) ;
F_43 ( V_104 , V_88 , NULL ) ;
F_16 ( & V_25 -> V_91 , V_23 ) ;
F_44 ( V_76 ) ;
}
static void F_45 ( void * V_1 , struct V_2 * V_3 ,
int V_4 )
{
struct V_105 * V_6 = V_1 ;
struct V_106 * V_107 =
(struct V_106 * ) V_3 ;
V_6 -> V_6 . V_8 = V_3 -> V_7 ;
V_6 -> V_54 = V_107 -> V_54 ;
F_3 ( & V_6 -> V_6 . V_9 ) ;
}
static void F_46 ( struct V_73 * V_76 , struct V_108 * V_97 )
{
struct V_85 * V_86 = F_39 ( V_76 ) ;
struct V_48 * V_25 ;
struct V_18 * V_19 ;
struct V_46 * V_89 ;
struct V_71 * V_72 ;
struct V_109 * V_56 ;
struct V_105 V_110 ;
struct V_53 * V_54 ;
struct V_78 * V_111 ;
struct {
struct V_57 V_58 ;
V_29 V_59 [ sizeof( struct V_109 ) ] ;
} V_60 ;
int V_90 ;
int V_112 ;
V_72 = F_33 ( F_32 ( V_76 ) ) ;
V_89 = V_72 -> V_47 ;
V_25 = F_23 ( V_89 -> V_49 , struct V_48 , V_49 ) ;
V_19 = F_24 ( V_25 , F_4 ( V_72 -> V_10 ) ) ;
if ( ! V_19 )
goto V_113;
if ( V_76 -> V_77 ) {
V_54 = V_76 -> V_77 ;
V_76 -> V_77 = NULL ;
F_27 ( V_19 , V_54 ) ;
}
V_54 = F_47 ( sizeof( * V_54 ) , V_114 ) ;
if ( ! V_54 )
goto V_115;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
F_48 ( & V_110 . V_6 . V_9 ) ;
V_60 . V_58 . V_116 = F_45 ;
V_60 . V_58 . V_117 = & V_110 ;
V_56 = (struct V_109 * ) & V_60 . V_58 . V_61 ;
V_56 -> V_62 . type = V_118 ;
V_56 -> V_12 . V_13 = V_19 -> V_30 . V_43 . V_13 ;
V_56 -> V_54 . V_102 = V_86 -> V_102 ;
V_56 -> V_54 . V_119 = 1 ;
V_56 -> V_54 . V_120 =
( V_121 -> V_122 == V_123 ) ? 1 : 0 ;
V_111 = F_40 ( V_76 ) ;
F_41 (cpu, affinity, cpu_online_mask) {
V_56 -> V_54 . V_124 |=
( 1ULL << F_42 ( V_90 ) ) ;
}
V_112 = F_28 ( V_19 -> V_25 -> V_44 -> V_64 , V_56 ,
sizeof( * V_56 ) , ( unsigned long ) & V_60 . V_58 ,
V_65 ,
V_125 ) ;
if ( V_112 )
goto V_126;
F_49 ( & V_110 . V_6 . V_9 ) ;
if ( V_110 . V_6 . V_8 < 0 ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_3 ,
V_110 . V_6 . V_8 ) ;
goto V_126;
}
* V_54 = V_110 . V_54 ;
V_76 -> V_77 = V_54 ;
V_97 -> V_127 = V_110 . V_54 . V_96 >> 32 ;
V_97 -> V_98 = V_110 . V_54 . V_96 & 0xffffffff ;
V_97 -> V_76 = V_110 . V_54 . V_76 ;
F_25 ( V_19 , V_51 ) ;
return;
V_126:
F_29 ( V_54 ) ;
V_115:
F_25 ( V_19 , V_51 ) ;
V_113:
V_97 -> V_127 = 0 ;
V_97 -> V_98 = 0 ;
V_97 -> V_76 = 0 ;
}
static T_3 F_50 ( struct V_68 * V_69 ,
T_4 * V_128 )
{
return V_128 -> V_129 ;
}
static int F_51 ( struct V_48 * V_25 )
{
V_25 -> V_130 . V_83 = & V_131 ;
V_25 -> V_130 . V_132 = & V_133 ;
V_25 -> V_130 . V_23 = ( V_134 |
V_135 | V_136 |
V_137 ) ;
V_25 -> V_130 . V_138 = V_139 ;
V_25 -> V_130 . V_140 = L_4 ;
V_25 -> V_130 . V_76 = V_25 ;
V_25 -> V_66 = F_52 ( V_25 -> V_49 . V_141 ,
& V_25 -> V_130 ,
V_142 ) ;
if ( ! V_25 -> V_66 ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_5 ) ;
return - V_143 ;
}
return 0 ;
}
static T_5 F_53 ( T_5 V_144 )
{
return F_54 ( ( 1 + ~ ( V_144 & V_145 ) ) ,
V_146 ) ;
}
static void F_55 ( struct V_48 * V_25 )
{
struct V_147 * V_148 ;
struct V_18 * V_19 ;
T_6 V_149 = 0 ;
unsigned long V_23 ;
struct V_150 * V_151 ;
T_5 V_144 ;
int V_152 ;
V_151 = F_56 ( & V_25 -> V_153 , NULL ) ;
if ( ! V_151 )
return;
if ( V_25 -> V_154 || V_25 -> V_155 ) {
F_3 ( V_151 ) ;
return;
}
F_10 ( & V_25 -> V_156 , V_23 ) ;
F_57 (iter, &hbus->children) {
V_19 = F_23 ( V_148 , struct V_18 , V_157 ) ;
for ( V_152 = 0 ; V_152 < 6 ; V_152 ++ ) {
if ( V_19 -> V_158 [ V_152 ] & V_159 )
F_17 ( & V_25 -> V_44 -> V_45 ,
L_6 ) ;
if ( V_19 -> V_158 [ V_152 ] != 0 ) {
V_144 = V_19 -> V_158 [ V_152 ] ;
if ( V_144 & V_160 )
V_144 |=
( ( T_5 ) V_19 -> V_158 [ ++ V_152 ] << 32 ) ;
else
V_144 |= 0xffffffff00000000ULL ;
V_149 = F_53 ( V_144 ) ;
if ( V_144 & V_160 )
V_25 -> V_155 += V_149 ;
else
V_25 -> V_154 += V_149 ;
}
}
}
F_16 ( & V_25 -> V_156 , V_23 ) ;
F_3 ( V_151 ) ;
}
static void F_58 ( struct V_48 * V_25 )
{
T_6 V_161 = 0 ;
T_6 V_162 = 0 ;
T_6 V_163 = 0 ;
T_6 V_164 = 0 ;
T_6 V_149 ;
struct V_18 * V_19 ;
struct V_147 * V_148 ;
unsigned long V_23 ;
T_5 V_144 ;
T_1 V_165 ;
bool V_166 ;
int V_152 ;
if ( V_25 -> V_154 ) {
V_162 = 1ULL << ( 63 - F_59 ( V_25 -> V_154 ) ) ;
V_164 = V_25 -> V_167 -> V_168 ;
}
if ( V_25 -> V_155 ) {
V_161 = 1ULL <<
( 63 - F_59 ( V_25 -> V_155 ) ) ;
V_163 = V_25 -> V_169 -> V_168 ;
}
F_10 ( & V_25 -> V_156 , V_23 ) ;
do {
F_57 (iter, &hbus->children) {
V_19 = F_23 ( V_148 , struct V_18 ,
V_157 ) ;
for ( V_152 = 0 ; V_152 < 6 ; V_152 ++ ) {
V_144 = V_19 -> V_158 [ V_152 ] ;
if ( V_144 == 0 )
continue;
V_166 = V_144 & V_160 ;
if ( V_166 ) {
V_144 |=
( ( T_5 ) V_19 -> V_158 [ V_152 + 1 ]
<< 32 ) ;
} else {
V_144 |= 0xffffffffULL << 32 ;
}
V_149 = F_53 ( V_144 ) ;
if ( V_166 ) {
if ( V_161 != V_149 ) {
V_152 ++ ;
continue;
}
F_18 ( V_19 ,
V_170 + ( 4 * V_152 ) ,
4 ,
( T_1 ) ( V_163 & 0xffffff00 ) ) ;
V_152 ++ ;
F_18 ( V_19 ,
V_170 + ( 4 * V_152 ) ,
4 , ( T_1 ) ( V_163 >> 32 ) ) ;
V_163 += V_149 ;
} else {
if ( V_162 != V_149 )
continue;
F_18 ( V_19 ,
V_170 + ( 4 * V_152 ) ,
4 ,
( T_1 ) ( V_164 & 0xffffff00 ) ) ;
V_164 += V_149 ;
}
}
if ( V_161 <= 1 && V_162 <= 1 ) {
F_9 ( V_19 , V_28 , 2 ,
& V_165 ) ;
V_165 |= V_171 ;
F_18 ( V_19 , V_28 , 2 ,
V_165 ) ;
break;
}
}
V_161 >>= 1 ;
V_162 >>= 1 ;
} while ( V_161 || V_162 );
F_16 ( & V_25 -> V_156 , V_23 ) ;
}
static int F_60 ( struct V_48 * V_25 )
{
V_25 -> V_46 = F_61 ( & V_25 -> V_44 -> V_45 ,
0 ,
& V_172 ,
& V_25 -> V_49 ,
& V_25 -> V_173 ) ;
if ( ! V_25 -> V_46 )
return - V_143 ;
V_25 -> V_46 -> V_75 = & V_25 -> V_174 ;
V_25 -> V_46 -> V_75 -> V_15 = & V_25 -> V_44 -> V_45 ;
F_62 ( V_25 -> V_46 ) ;
F_63 ( V_25 -> V_46 ) ;
F_64 ( V_25 -> V_46 ) ;
V_25 -> V_175 = V_176 ;
return 0 ;
}
static void F_65 ( void * V_1 , struct V_2 * V_3 ,
int V_4 )
{
struct V_177 * V_150 = V_1 ;
struct V_178 * V_179 =
(struct V_178 * ) V_3 ;
int V_152 ;
if ( V_3 -> V_7 < 0 ) {
F_17 ( & V_150 -> V_19 -> V_25 -> V_44 -> V_45 ,
L_7 ,
V_3 -> V_7 ) ;
} else {
for ( V_152 = 0 ; V_152 < 6 ; V_152 ++ ) {
V_150 -> V_19 -> V_158 [ V_152 ] =
V_179 -> V_158 [ V_152 ] ;
}
}
F_3 ( & V_150 -> V_9 ) ;
}
static void F_66 ( struct V_18 * V_19 ,
enum V_180 V_181 )
{
F_67 ( & V_19 -> V_182 ) ;
}
static void F_25 ( struct V_18 * V_19 ,
enum V_180 V_181 )
{
if ( F_68 ( & V_19 -> V_182 ) )
F_29 ( V_19 ) ;
}
static struct V_18 * F_69 ( struct V_48 * V_25 ,
struct V_183 * V_30 )
{
struct V_18 * V_19 ;
struct V_184 * V_185 ;
struct V_177 V_6 ;
struct {
struct V_57 V_186 ;
V_29 V_59 [ sizeof( struct V_184 ) ] ;
} V_58 ;
unsigned long V_23 ;
int V_112 ;
V_19 = F_47 ( sizeof( * V_19 ) , V_187 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_25 = V_25 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
F_48 ( & V_6 . V_9 ) ;
V_6 . V_19 = V_19 ;
V_58 . V_186 . V_117 = & V_6 ;
V_58 . V_186 . V_116 = F_65 ;
V_185 = (struct V_184 * ) & V_58 . V_186 . V_61 ;
V_185 -> V_62 . type = V_188 ;
V_185 -> V_12 . V_13 = V_30 -> V_43 . V_13 ;
V_112 = F_28 ( V_25 -> V_44 -> V_64 , V_185 ,
sizeof( struct V_184 ) ,
( unsigned long ) & V_58 . V_186 ,
V_65 ,
V_125 ) ;
if ( V_112 )
goto error;
F_49 ( & V_6 . V_9 ) ;
V_19 -> V_30 = * V_30 ;
F_66 ( V_19 , V_189 ) ;
F_66 ( V_19 , V_190 ) ;
F_10 ( & V_25 -> V_156 , V_23 ) ;
if ( F_70 ( & V_25 -> V_191 ) )
V_25 -> V_49 . V_67 = V_30 -> V_192 ;
F_71 ( & V_19 -> V_157 , & V_25 -> V_191 ) ;
F_16 ( & V_25 -> V_156 , V_23 ) ;
return V_19 ;
error:
F_29 ( V_19 ) ;
return NULL ;
}
static struct V_18 * F_24 ( struct V_48 * V_25 ,
T_1 V_12 )
{
unsigned long V_23 ;
struct V_18 * V_148 , * V_19 = NULL ;
F_10 ( & V_25 -> V_156 , V_23 ) ;
F_72 (iter, &hbus->children, list_entry) {
if ( V_148 -> V_30 . V_43 . V_13 == V_12 ) {
V_19 = V_148 ;
F_66 ( V_19 , V_51 ) ;
break;
}
}
F_16 ( & V_25 -> V_156 , V_23 ) ;
return V_19 ;
}
static void F_73 ( struct V_193 * V_194 )
{
T_1 V_195 ;
bool V_196 ;
struct V_147 * V_148 ;
struct V_183 * V_197 ;
struct V_18 * V_19 ;
struct V_48 * V_25 ;
struct V_147 V_198 ;
struct V_199 * V_200 ;
struct V_201 * V_202 = NULL ;
unsigned long V_23 ;
V_200 = F_23 ( V_194 , struct V_199 , V_203 ) ;
V_25 = V_200 -> V_47 ;
F_29 ( V_200 ) ;
F_74 ( & V_198 ) ;
if ( F_75 ( & V_25 -> V_204 ) ) {
F_76 ( V_25 ) ;
return;
}
F_10 ( & V_25 -> V_156 , V_23 ) ;
while ( ! F_70 ( & V_25 -> V_205 ) ) {
V_202 = F_77 ( & V_25 -> V_205 , struct V_201 ,
V_157 ) ;
F_78 ( & V_202 -> V_157 ) ;
if ( ! F_70 ( & V_25 -> V_205 ) ) {
F_29 ( V_202 ) ;
continue;
}
}
F_16 ( & V_25 -> V_156 , V_23 ) ;
if ( ! V_202 ) {
F_79 ( & V_25 -> V_204 ) ;
F_76 ( V_25 ) ;
return;
}
F_10 ( & V_25 -> V_156 , V_23 ) ;
F_57 (iter, &hbus->children) {
V_19 = F_23 ( V_148 , struct V_18 ,
V_157 ) ;
V_19 -> V_206 = true ;
}
F_16 ( & V_25 -> V_156 , V_23 ) ;
for ( V_195 = 0 ; V_195 < V_202 -> V_207 ; V_195 ++ ) {
V_196 = false ;
V_197 = & V_202 -> V_16 [ V_195 ] ;
F_10 ( & V_25 -> V_156 , V_23 ) ;
F_57 (iter, &hbus->children) {
V_19 = F_23 ( V_148 , struct V_18 ,
V_157 ) ;
if ( ( V_19 -> V_30 . V_43 . V_13 ==
V_197 -> V_43 . V_13 ) &&
( V_19 -> V_30 . V_31 == V_197 -> V_31 ) &&
( V_19 -> V_30 . V_208 == V_197 -> V_208 ) &&
( V_19 -> V_30 . V_192 == V_197 -> V_192 ) ) {
V_19 -> V_206 = false ;
V_196 = true ;
}
}
F_16 ( & V_25 -> V_156 , V_23 ) ;
if ( ! V_196 ) {
V_19 = F_69 ( V_25 , V_197 ) ;
if ( ! V_19 )
F_17 ( & V_25 -> V_44 -> V_45 ,
L_8 ) ;
}
}
F_10 ( & V_25 -> V_156 , V_23 ) ;
do {
V_196 = false ;
F_57 (iter, &hbus->children) {
V_19 = F_23 ( V_148 , struct V_18 ,
V_157 ) ;
if ( V_19 -> V_206 ) {
V_196 = true ;
F_25 ( V_19 , V_190 ) ;
F_80 ( & V_19 -> V_157 , & V_198 ) ;
break;
}
}
} while ( V_196 );
F_16 ( & V_25 -> V_156 , V_23 ) ;
while ( ! F_70 ( & V_198 ) ) {
V_19 = F_77 ( & V_198 , struct V_18 ,
V_157 ) ;
F_78 ( & V_19 -> V_157 ) ;
F_25 ( V_19 , V_189 ) ;
}
if ( V_25 -> V_175 == V_176 ) {
F_81 () ;
F_62 ( V_25 -> V_46 ) ;
F_82 () ;
} else {
F_55 ( V_25 ) ;
}
F_79 ( & V_25 -> V_204 ) ;
F_76 ( V_25 ) ;
F_29 ( V_202 ) ;
}
static void F_83 ( struct V_48 * V_25 ,
struct V_209 * V_210 )
{
struct V_201 * V_202 ;
struct V_199 * V_200 ;
unsigned long V_23 ;
V_200 = F_47 ( sizeof( * V_200 ) , V_211 ) ;
if ( ! V_200 )
return;
V_202 = F_47 ( F_84 ( struct V_201 , V_16 ) +
( sizeof( struct V_183 ) *
( V_210 -> V_207 ) ) , V_211 ) ;
if ( ! V_202 ) {
F_29 ( V_200 ) ;
return;
}
F_85 ( & V_200 -> V_203 , F_73 ) ;
V_200 -> V_47 = V_25 ;
V_202 -> V_207 = V_210 -> V_207 ;
if ( V_202 -> V_207 != 0 ) {
memcpy ( V_202 -> V_16 , V_210 -> V_16 ,
sizeof( struct V_183 ) *
V_202 -> V_207 ) ;
}
F_10 ( & V_25 -> V_156 , V_23 ) ;
F_71 ( & V_202 -> V_157 , & V_25 -> V_205 ) ;
F_16 ( & V_25 -> V_156 , V_23 ) ;
F_86 ( V_25 ) ;
F_87 ( & V_200 -> V_203 ) ;
}
static void F_88 ( struct V_193 * V_194 )
{
struct V_212 * V_213 ;
struct V_18 * V_19 ;
struct V_71 * V_72 ;
unsigned long V_23 ;
int V_12 ;
struct {
struct V_57 V_58 ;
V_29 V_59 [ sizeof( struct V_212 ) ] ;
} V_60 ;
V_19 = F_23 ( V_194 , struct V_18 , V_203 ) ;
if ( V_19 -> V_175 != V_214 ) {
F_25 ( V_19 , V_215 ) ;
return;
}
V_12 = F_7 ( V_19 -> V_30 . V_43 . V_13 ) ;
V_72 = F_89 ( V_19 -> V_25 -> V_49 . V_67 , 0 ,
V_12 ) ;
if ( V_72 ) {
F_90 ( V_72 ) ;
F_91 ( V_72 ) ;
}
F_10 ( & V_19 -> V_25 -> V_156 , V_23 ) ;
F_78 ( & V_19 -> V_157 ) ;
F_16 ( & V_19 -> V_25 -> V_156 , V_23 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_213 = (struct V_212 * ) & V_60 . V_58 . V_61 ;
V_213 -> V_62 . type = V_216 ;
V_213 -> V_12 . V_13 = V_19 -> V_30 . V_43 . V_13 ;
F_28 ( V_19 -> V_25 -> V_44 -> V_64 , V_213 ,
sizeof( * V_213 ) , ( unsigned long ) & V_60 . V_58 ,
V_65 , 0 ) ;
F_25 ( V_19 , V_190 ) ;
F_25 ( V_19 , V_215 ) ;
F_76 ( V_19 -> V_25 ) ;
}
static void F_92 ( struct V_18 * V_19 )
{
V_19 -> V_175 = V_214 ;
F_66 ( V_19 , V_215 ) ;
F_85 ( & V_19 -> V_203 , F_88 ) ;
F_86 ( V_19 -> V_25 ) ;
F_87 ( & V_19 -> V_203 ) ;
}
static void F_93 ( void * V_1 )
{
const int V_217 = 0x100 ;
int V_112 ;
struct V_48 * V_25 = V_1 ;
T_1 V_218 ;
T_5 V_219 ;
struct V_220 * V_30 ;
unsigned char * V_59 ;
int V_221 = V_217 ;
struct V_57 * V_222 ;
struct V_2 * V_223 ;
struct V_224 * V_225 ;
struct V_209 * V_226 ;
struct V_227 * V_228 ;
struct V_18 * V_19 ;
V_59 = F_94 ( V_221 , V_187 ) ;
if ( ! V_59 )
return;
while ( 1 ) {
V_112 = F_95 ( V_25 -> V_44 -> V_64 , V_59 ,
V_221 , & V_218 , & V_219 ) ;
if ( V_112 == - V_229 ) {
F_29 ( V_59 ) ;
V_221 = V_218 ;
V_59 = F_94 ( V_218 , V_187 ) ;
if ( ! V_59 )
return;
continue;
}
if ( V_112 || ! V_218 )
break;
if ( V_218 <= sizeof( struct V_2 ) )
continue;
V_30 = (struct V_220 * ) V_59 ;
switch ( V_30 -> type ) {
case V_230 :
V_222 = (struct V_57 * ) V_219 ;
V_223 = (struct V_2 * ) V_59 ;
V_222 -> V_116 ( V_222 -> V_117 ,
V_223 ,
V_218 ) ;
break;
case V_65 :
V_225 = (struct V_224 * ) V_59 ;
switch ( V_225 -> V_62 . type ) {
case V_231 :
V_226 = (struct V_209 * ) V_59 ;
if ( V_218 <
F_84 ( struct V_209 , V_16 ) +
( sizeof( struct V_183 ) *
( V_226 -> V_207 ) ) ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_9 ) ;
break;
}
F_83 ( V_25 , V_226 ) ;
break;
case V_232 :
V_228 = (struct V_227 * ) V_59 ;
V_19 = F_24 ( V_25 ,
V_228 -> V_12 . V_13 ) ;
if ( V_19 ) {
F_92 ( V_19 ) ;
F_25 ( V_19 ,
V_51 ) ;
}
break;
default:
F_96 ( & V_25 -> V_44 -> V_45 ,
L_10 ,
V_225 -> V_62 . type ) ;
break;
}
break;
default:
F_17 ( & V_25 -> V_44 -> V_45 ,
L_11 ,
V_30 -> type , V_219 , V_218 ) ;
break;
}
}
F_29 ( V_59 ) ;
}
static int F_97 ( struct V_233 * V_44 )
{
struct V_234 * V_235 ;
struct V_5 V_6 ;
struct V_57 * V_58 ;
int V_112 ;
V_58 = F_47 ( sizeof( * V_58 ) + sizeof( * V_235 ) , V_114 ) ;
if ( ! V_58 )
return - V_236 ;
F_48 ( & V_6 . V_9 ) ;
V_58 -> V_116 = F_1 ;
V_58 -> V_117 = & V_6 ;
V_235 = (struct V_234 * ) & V_58 -> V_61 ;
V_235 -> V_62 . type = V_237 ;
V_235 -> V_238 = V_239 ;
V_112 = F_28 ( V_44 -> V_64 , V_235 ,
sizeof( struct V_234 ) ,
( unsigned long ) V_58 , V_65 ,
V_125 ) ;
if ( V_112 )
goto exit;
F_49 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
F_17 ( & V_44 -> V_45 ,
L_12 ,
V_6 . V_8 ) ;
V_112 = - V_240 ;
goto exit;
}
V_112 = 0 ;
exit:
F_29 ( V_58 ) ;
return V_112 ;
}
static void F_98 ( struct V_48 * V_25 )
{
if ( V_25 -> V_154 && V_25 -> V_167 ) {
V_25 -> V_167 -> V_23 |= V_241 ;
F_99 ( V_25 -> V_167 -> V_168 ,
F_100 ( V_25 -> V_167 ) ) ;
}
if ( V_25 -> V_155 && V_25 -> V_169 ) {
V_25 -> V_169 -> V_23 |= V_241 ;
F_99 ( V_25 -> V_169 -> V_168 ,
F_100 ( V_25 -> V_169 ) ) ;
}
}
static int F_101 ( struct V_48 * V_25 )
{
T_6 V_242 ;
int V_112 ;
if ( V_25 -> V_154 ) {
V_242 = 1ULL << ( 63 - F_59 ( V_25 -> V_154 ) ) ;
V_112 = F_102 ( & V_25 -> V_167 , V_25 -> V_44 , 0 ,
( T_5 ) ( T_1 ) 0xffffffff ,
V_25 -> V_154 ,
V_242 , false ) ;
if ( V_112 ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_13 ,
V_25 -> V_154 ) ;
return V_112 ;
}
V_25 -> V_167 -> V_23 |= V_243 ;
V_25 -> V_167 -> V_23 &= ~ V_241 ;
F_103 ( & V_25 -> V_173 ,
V_25 -> V_167 ) ;
}
if ( V_25 -> V_155 ) {
V_242 = 1ULL << ( 63 - F_59 ( V_25 -> V_155 ) ) ;
V_112 = F_102 ( & V_25 -> V_169 , V_25 -> V_44 ,
0x100000000 , - 1 ,
V_25 -> V_155 , V_242 ,
false ) ;
if ( V_112 ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_14 ,
V_25 -> V_155 ) ;
goto V_244;
}
V_25 -> V_169 -> V_23 |= V_243 ;
V_25 -> V_169 -> V_23 &= ~ V_241 ;
F_103 ( & V_25 -> V_173 ,
V_25 -> V_169 ) ;
}
return 0 ;
V_244:
if ( V_25 -> V_167 ) {
F_99 ( V_25 -> V_167 -> V_168 ,
F_100 ( V_25 -> V_167 ) ) ;
}
return V_112 ;
}
static int F_104 ( struct V_48 * V_25 )
{
int V_112 ;
V_112 = F_102 ( & V_25 -> V_245 , V_25 -> V_44 , 0 , - 1 ,
V_246 , 0x1000 , false ) ;
if ( V_112 )
return V_112 ;
V_25 -> V_245 -> V_23 |= V_241 ;
return 0 ;
}
static void F_105 ( struct V_48 * V_25 )
{
F_99 ( V_25 -> V_245 -> V_168 , V_246 ) ;
}
static int F_106 ( struct V_233 * V_44 )
{
struct V_48 * V_25 = F_107 ( V_44 ) ;
struct V_247 * V_248 ;
struct V_5 V_6 ;
struct V_57 * V_58 ;
int V_112 ;
V_58 = F_47 ( sizeof( * V_58 ) + sizeof( * V_248 ) , V_114 ) ;
if ( ! V_58 )
return - V_236 ;
F_48 ( & V_6 . V_9 ) ;
V_58 -> V_116 = F_1 ;
V_58 -> V_117 = & V_6 ;
V_248 = (struct V_247 * ) & V_58 -> V_61 ;
V_248 -> V_62 . type = V_249 ;
V_248 -> V_250 = V_25 -> V_245 -> V_168 ;
V_112 = F_28 ( V_44 -> V_64 , V_248 , sizeof( * V_248 ) ,
( unsigned long ) V_58 , V_65 ,
V_125 ) ;
if ( V_112 )
goto exit;
F_49 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
F_17 ( & V_44 -> V_45 ,
L_15 ,
V_6 . V_8 ) ;
V_112 = - V_240 ;
goto exit;
}
V_112 = 0 ;
exit:
F_29 ( V_58 ) ;
return V_112 ;
}
static int F_108 ( struct V_233 * V_44 )
{
struct V_48 * V_25 = F_107 ( V_44 ) ;
struct V_251 V_61 ;
struct V_150 V_110 ;
int V_112 ;
F_48 ( & V_110 ) ;
if ( F_109 ( & V_25 -> V_153 , NULL , & V_110 ) )
return - V_252 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . type = V_253 ;
V_112 = F_28 ( V_44 -> V_64 , & V_61 , sizeof( V_61 ) ,
0 , V_65 , 0 ) ;
if ( V_112 )
return V_112 ;
F_49 ( & V_110 ) ;
return 0 ;
}
static int F_110 ( struct V_233 * V_44 )
{
struct V_48 * V_25 = F_107 ( V_44 ) ;
struct V_254 * V_255 ;
struct V_5 V_6 ;
struct V_18 * V_19 ;
struct V_57 * V_58 ;
T_1 V_12 ;
int V_112 ;
V_58 = F_94 ( sizeof( * V_58 ) + sizeof( * V_255 ) , V_114 ) ;
if ( ! V_58 )
return - V_236 ;
V_112 = 0 ;
for ( V_12 = 0 ; V_12 < 256 ; V_12 ++ ) {
V_19 = F_24 ( V_25 , V_12 ) ;
if ( ! V_19 )
continue;
memset ( V_58 , 0 , sizeof( * V_58 ) + sizeof( * V_255 ) ) ;
F_48 ( & V_6 . V_9 ) ;
V_58 -> V_116 = F_1 ;
V_58 -> V_117 = & V_6 ;
V_255 = (struct V_254 * ) & V_58 -> V_61 ;
V_255 -> V_62 . type = V_256 ;
V_255 -> V_12 . V_13 = V_19 -> V_30 . V_43 . V_13 ;
F_25 ( V_19 , V_51 ) ;
V_112 = F_28 (
V_44 -> V_64 , & V_58 -> V_61 ,
sizeof( * V_255 ) ,
( unsigned long ) V_58 ,
V_65 ,
V_125 ) ;
if ( V_112 )
break;
F_49 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
V_112 = - V_240 ;
F_17 ( & V_44 -> V_45 ,
L_16 ,
V_6 . V_8 ) ;
break;
}
}
F_29 ( V_58 ) ;
return V_112 ;
}
static int F_111 ( struct V_233 * V_44 )
{
struct V_48 * V_25 = F_107 ( V_44 ) ;
struct V_184 V_58 ;
struct V_18 * V_19 ;
T_1 V_12 ;
int V_112 ;
for ( V_12 = 0 ; V_12 < 256 ; V_12 ++ ) {
V_19 = F_24 ( V_25 , V_12 ) ;
if ( ! V_19 )
continue;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_62 . type = V_257 ;
V_58 . V_12 . V_13 = V_19 -> V_30 . V_43 . V_13 ;
F_25 ( V_19 , V_51 ) ;
V_112 = F_28 ( V_44 -> V_64 , & V_58 , sizeof( V_58 ) , 0 ,
V_65 , 0 ) ;
if ( V_112 )
return V_112 ;
}
return 0 ;
}
static void F_86 ( struct V_48 * V_25 )
{
F_67 ( & V_25 -> V_258 ) ;
}
static void F_76 ( struct V_48 * V_25 )
{
if ( F_68 ( & V_25 -> V_258 ) )
F_3 ( & V_25 -> V_259 ) ;
}
static int F_112 ( struct V_233 * V_44 ,
const struct V_260 * V_261 )
{
struct V_48 * V_25 ;
int V_112 ;
V_25 = F_47 ( sizeof( * V_25 ) , V_114 ) ;
if ( ! V_25 )
return - V_236 ;
V_25 -> V_49 . V_67 = V_44 -> V_100 . V_101 [ 9 ] |
V_44 -> V_100 . V_101 [ 8 ] << 8 ;
V_25 -> V_44 = V_44 ;
F_67 ( & V_25 -> V_258 ) ;
F_74 ( & V_25 -> V_191 ) ;
F_74 ( & V_25 -> V_205 ) ;
F_74 ( & V_25 -> V_173 ) ;
F_113 ( & V_25 -> V_42 ) ;
F_113 ( & V_25 -> V_156 ) ;
F_113 ( & V_25 -> V_91 ) ;
F_114 ( & V_25 -> V_204 , 1 ) ;
F_48 ( & V_25 -> V_259 ) ;
V_112 = F_115 ( V_44 -> V_64 , V_262 , V_262 , NULL , 0 ,
F_93 , V_25 ) ;
if ( V_112 )
goto V_263;
F_116 ( V_44 , V_25 ) ;
V_112 = F_97 ( V_44 ) ;
if ( V_112 )
goto V_264;
V_112 = F_104 ( V_25 ) ;
if ( V_112 )
goto V_264;
V_25 -> V_26 = F_117 ( V_25 -> V_245 -> V_168 ,
V_246 ) ;
if ( ! V_25 -> V_26 ) {
F_17 ( & V_44 -> V_45 ,
L_17 ) ;
V_112 = - V_236 ;
goto V_265;
}
V_25 -> V_49 . V_141 = F_118 ( V_25 ) ;
if ( ! V_25 -> V_49 . V_141 ) {
V_112 = - V_236 ;
goto V_266;
}
V_112 = F_51 ( V_25 ) ;
if ( V_112 )
goto V_267;
V_112 = F_108 ( V_44 ) ;
if ( V_112 )
goto V_268;
V_112 = F_106 ( V_44 ) ;
if ( V_112 )
goto V_268;
V_112 = F_101 ( V_25 ) ;
if ( V_112 )
goto V_268;
V_112 = F_110 ( V_44 ) ;
if ( V_112 )
goto V_269;
F_58 ( V_25 ) ;
V_25 -> V_175 = V_270 ;
V_112 = F_60 ( V_25 ) ;
if ( V_112 )
goto V_269;
return 0 ;
V_269:
F_98 ( V_25 ) ;
V_268:
F_119 ( V_25 -> V_66 ) ;
V_267:
F_120 ( V_25 -> V_49 . V_141 ) ;
V_266:
F_121 ( V_25 -> V_26 ) ;
V_265:
F_105 ( V_25 ) ;
V_264:
F_122 ( V_44 -> V_64 ) ;
V_263:
F_29 ( V_25 ) ;
return V_112 ;
}
static void F_123 ( struct V_233 * V_44 )
{
struct V_48 * V_25 = F_107 ( V_44 ) ;
struct {
struct V_57 V_271 ;
V_29 V_59 [ sizeof( struct V_251 ) ] ;
} V_58 ;
struct V_209 V_210 ;
struct V_5 V_6 ;
int V_112 ;
if ( V_44 -> V_64 -> V_272 )
return;
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
F_83 ( V_25 , & V_210 ) ;
V_112 = F_111 ( V_44 ) ;
if ( V_112 )
F_17 ( & V_44 -> V_45 ,
L_18 ) ;
memset ( & V_58 . V_271 , 0 , sizeof( V_58 . V_271 ) ) ;
F_48 ( & V_6 . V_9 ) ;
V_58 . V_271 . V_116 = F_1 ;
V_58 . V_271 . V_117 = & V_6 ;
V_58 . V_271 . V_61 [ 0 ] . type = V_273 ;
V_112 = F_28 ( V_44 -> V_64 , & V_58 . V_271 . V_61 ,
sizeof( struct V_251 ) ,
( unsigned long ) & V_58 . V_271 ,
V_65 ,
V_125 ) ;
if ( ! V_112 )
F_124 ( & V_6 . V_9 , 10 * V_274 ) ;
}
static int F_125 ( struct V_233 * V_44 )
{
struct V_48 * V_25 ;
V_25 = F_107 ( V_44 ) ;
if ( V_25 -> V_175 == V_176 ) {
F_81 () ;
F_126 ( V_25 -> V_46 ) ;
F_127 ( V_25 -> V_46 ) ;
F_82 () ;
}
F_123 ( V_44 ) ;
F_122 ( V_44 -> V_64 ) ;
F_121 ( V_25 -> V_26 ) ;
F_105 ( V_25 ) ;
F_128 ( & V_25 -> V_173 ) ;
F_98 ( V_25 ) ;
F_119 ( V_25 -> V_66 ) ;
F_120 ( V_25 -> V_49 . V_141 ) ;
F_76 ( V_25 ) ;
F_49 ( & V_25 -> V_259 ) ;
F_29 ( V_25 ) ;
return 0 ;
}
static void T_7 F_129 ( void )
{
F_130 ( & V_275 ) ;
}
static int T_8 F_131 ( void )
{
return F_132 ( & V_275 ) ;
}
