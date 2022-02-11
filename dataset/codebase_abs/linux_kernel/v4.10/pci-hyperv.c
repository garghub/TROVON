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
V_28 V_58 [ sizeof( struct V_54 ) ] ;
} V_59 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_55 = (struct V_54 * ) & V_59 . V_57 . V_60 ;
V_55 -> V_61 . type =
V_62 ;
V_55 -> V_12 . V_13 = V_18 -> V_29 . V_42 . V_13 ;
V_55 -> V_53 = * V_53 ;
F_28 ( V_18 -> V_24 -> V_43 -> V_63 , V_55 , sizeof( * V_55 ) ,
( unsigned long ) & V_59 . V_57 , V_64 , 0 ) ;
F_29 ( V_53 ) ;
}
static void F_30 ( struct V_65 * V_66 , struct V_67 * V_68 ,
unsigned int V_69 )
{
struct V_47 * V_24 ;
struct V_17 * V_18 ;
struct V_70 * V_71 ;
struct V_52 * V_53 ;
struct V_72 * V_72 = F_31 ( V_66 , V_69 ) ;
struct V_73 * V_74 = F_32 ( V_72 ) ;
V_71 = F_33 ( V_74 ) ;
V_24 = V_68 -> V_75 ;
V_53 = F_34 ( V_72 ) ;
if ( ! V_53 )
return;
V_72 -> V_76 = NULL ;
V_18 = F_24 ( V_24 , F_4 ( V_71 -> V_10 ) ) ;
if ( ! V_18 ) {
F_29 ( V_53 ) ;
return;
}
F_27 ( V_18 , V_53 ) ;
F_25 ( V_18 , V_50 ) ;
}
static int F_35 ( struct V_72 * V_75 , const struct V_77 * V_78 ,
bool V_79 )
{
struct V_72 * V_80 = V_75 -> V_81 ;
return V_80 -> V_82 -> V_83 ( V_80 , V_78 , V_79 ) ;
}
static void F_36 ( struct V_72 * V_75 )
{
F_37 ( V_75 ) ;
}
static void F_38 ( struct V_72 * V_75 )
{
struct V_73 * V_73 = F_32 ( V_75 ) ;
struct V_84 * V_85 = F_39 ( V_75 ) ;
struct V_86 * V_87 ;
struct V_47 * V_24 ;
struct V_77 * V_78 ;
struct V_45 * V_88 ;
struct V_70 * V_71 ;
int V_89 ;
unsigned long V_22 ;
V_78 = F_40 ( V_75 ) ;
V_71 = F_33 ( V_73 ) ;
V_88 = V_71 -> V_46 ;
V_24 = F_23 ( V_88 -> V_48 , struct V_47 , V_48 ) ;
F_10 ( & V_24 -> V_90 , V_22 ) ;
V_87 = & V_24 -> V_91 ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_92 = V_93 ;
V_87 -> V_94 = 1 ;
V_87 -> V_95 = V_73 -> V_96 . V_97 ;
V_87 -> V_75 = V_73 -> V_96 . V_75 ;
V_87 -> V_98 = ( V_24 -> V_43 -> V_99 . V_100 [ 5 ] << 24 ) |
( V_24 -> V_43 -> V_99 . V_100 [ 4 ] << 16 ) |
( V_24 -> V_43 -> V_99 . V_100 [ 7 ] << 8 ) |
( V_24 -> V_43 -> V_99 . V_100 [ 6 ] & 0xf8 ) |
F_6 ( V_71 -> V_10 ) ;
V_87 -> V_101 = V_85 -> V_101 ;
F_41 (cpu, dest, cpu_online_mask)
V_87 -> V_102 |= ( 1ULL << F_42 ( V_89 ) ) ;
F_43 ( V_103 , V_87 , NULL ) ;
F_16 ( & V_24 -> V_90 , V_22 ) ;
F_44 ( V_75 ) ;
}
static void F_45 ( void * V_1 , struct V_2 * V_3 ,
int V_4 )
{
struct V_104 * V_6 = V_1 ;
struct V_105 * V_106 =
(struct V_105 * ) V_3 ;
V_6 -> V_6 . V_8 = V_3 -> V_7 ;
V_6 -> V_53 = V_106 -> V_53 ;
F_3 ( & V_6 -> V_6 . V_9 ) ;
}
static void F_46 ( struct V_72 * V_75 , struct V_107 * V_96 )
{
struct V_84 * V_85 = F_39 ( V_75 ) ;
struct V_47 * V_24 ;
struct V_17 * V_18 ;
struct V_45 * V_88 ;
struct V_70 * V_71 ;
struct V_108 * V_55 ;
struct V_104 V_109 ;
struct V_52 * V_53 ;
struct V_77 * V_110 ;
struct {
struct V_56 V_57 ;
V_28 V_58 [ sizeof( struct V_108 ) ] ;
} V_59 ;
int V_89 ;
int V_111 ;
V_71 = F_33 ( F_32 ( V_75 ) ) ;
V_88 = V_71 -> V_46 ;
V_24 = F_23 ( V_88 -> V_48 , struct V_47 , V_48 ) ;
V_18 = F_24 ( V_24 , F_4 ( V_71 -> V_10 ) ) ;
if ( ! V_18 )
goto V_112;
if ( V_75 -> V_76 ) {
V_53 = V_75 -> V_76 ;
V_75 -> V_76 = NULL ;
F_27 ( V_18 , V_53 ) ;
}
V_53 = F_47 ( sizeof( * V_53 ) , V_113 ) ;
if ( ! V_53 )
goto V_114;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
F_48 ( & V_109 . V_6 . V_9 ) ;
V_59 . V_57 . V_115 = F_45 ;
V_59 . V_57 . V_116 = & V_109 ;
V_55 = (struct V_108 * ) & V_59 . V_57 . V_60 ;
V_55 -> V_61 . type = V_117 ;
V_55 -> V_12 . V_13 = V_18 -> V_29 . V_42 . V_13 ;
V_55 -> V_53 . V_101 = V_85 -> V_101 ;
V_55 -> V_53 . V_118 = 1 ;
V_55 -> V_53 . V_119 =
( V_120 -> V_121 == V_122 ) ? 1 : 0 ;
V_110 = F_40 ( V_75 ) ;
F_41 (cpu, affinity, cpu_online_mask) {
V_55 -> V_53 . V_123 |=
( 1ULL << F_42 ( V_89 ) ) ;
}
V_111 = F_28 ( V_18 -> V_24 -> V_43 -> V_63 , V_55 ,
sizeof( * V_55 ) , ( unsigned long ) & V_59 . V_57 ,
V_64 ,
V_124 ) ;
if ( V_111 )
goto V_125;
F_49 ( & V_109 . V_6 . V_9 ) ;
if ( V_109 . V_6 . V_8 < 0 ) {
F_17 ( & V_24 -> V_43 -> V_44 ,
L_3 ,
V_109 . V_6 . V_8 ) ;
goto V_125;
}
* V_53 = V_109 . V_53 ;
V_75 -> V_76 = V_53 ;
V_96 -> V_126 = V_109 . V_53 . V_95 >> 32 ;
V_96 -> V_97 = V_109 . V_53 . V_95 & 0xffffffff ;
V_96 -> V_75 = V_109 . V_53 . V_75 ;
F_25 ( V_18 , V_50 ) ;
return;
V_125:
F_29 ( V_53 ) ;
V_114:
F_25 ( V_18 , V_50 ) ;
V_112:
V_96 -> V_126 = 0 ;
V_96 -> V_97 = 0 ;
V_96 -> V_75 = 0 ;
}
static T_3 F_50 ( struct V_67 * V_68 ,
T_4 * V_127 )
{
return V_127 -> V_128 ;
}
static int F_51 ( struct V_47 * V_24 )
{
V_24 -> V_129 . V_82 = & V_130 ;
V_24 -> V_129 . V_131 = & V_132 ;
V_24 -> V_129 . V_22 = ( V_133 |
V_134 | V_135 |
V_136 ) ;
V_24 -> V_129 . V_137 = V_138 ;
V_24 -> V_129 . V_139 = L_4 ;
V_24 -> V_129 . V_75 = V_24 ;
V_24 -> V_65 = F_52 ( V_24 -> V_48 . V_140 ,
& V_24 -> V_129 ,
V_141 ) ;
if ( ! V_24 -> V_65 ) {
F_17 ( & V_24 -> V_43 -> V_44 ,
L_5 ) ;
return - V_142 ;
}
return 0 ;
}
static T_5 F_53 ( T_5 V_143 )
{
return F_54 ( ( 1 + ~ ( V_143 & V_144 ) ) ,
V_145 ) ;
}
static void F_55 ( struct V_47 * V_24 )
{
struct V_146 * V_147 ;
struct V_17 * V_18 ;
T_6 V_148 = 0 ;
unsigned long V_22 ;
struct V_149 * V_150 ;
T_5 V_143 ;
int V_151 ;
V_150 = F_56 ( & V_24 -> V_152 , NULL ) ;
if ( ! V_150 )
return;
if ( V_24 -> V_153 || V_24 -> V_154 ) {
F_3 ( V_150 ) ;
return;
}
F_10 ( & V_24 -> V_155 , V_22 ) ;
F_57 (iter, &hbus->children) {
V_18 = F_23 ( V_147 , struct V_17 , V_156 ) ;
for ( V_151 = 0 ; V_151 < 6 ; V_151 ++ ) {
if ( V_18 -> V_157 [ V_151 ] & V_158 )
F_17 ( & V_24 -> V_43 -> V_44 ,
L_6 ) ;
if ( V_18 -> V_157 [ V_151 ] != 0 ) {
V_143 = V_18 -> V_157 [ V_151 ] ;
if ( V_143 & V_159 )
V_143 |=
( ( T_5 ) V_18 -> V_157 [ ++ V_151 ] << 32 ) ;
else
V_143 |= 0xffffffff00000000ULL ;
V_148 = F_53 ( V_143 ) ;
if ( V_143 & V_159 )
V_24 -> V_154 += V_148 ;
else
V_24 -> V_153 += V_148 ;
}
}
}
F_16 ( & V_24 -> V_155 , V_22 ) ;
F_3 ( V_150 ) ;
}
static void F_58 ( struct V_47 * V_24 )
{
T_6 V_160 = 0 ;
T_6 V_161 = 0 ;
T_6 V_162 = 0 ;
T_6 V_163 = 0 ;
T_6 V_148 ;
struct V_17 * V_18 ;
struct V_146 * V_147 ;
unsigned long V_22 ;
T_5 V_143 ;
T_1 V_164 ;
bool V_165 ;
int V_151 ;
if ( V_24 -> V_153 ) {
V_161 = 1ULL << ( 63 - F_59 ( V_24 -> V_153 ) ) ;
V_163 = V_24 -> V_166 -> V_167 ;
}
if ( V_24 -> V_154 ) {
V_160 = 1ULL <<
( 63 - F_59 ( V_24 -> V_154 ) ) ;
V_162 = V_24 -> V_168 -> V_167 ;
}
F_10 ( & V_24 -> V_155 , V_22 ) ;
do {
F_57 (iter, &hbus->children) {
V_18 = F_23 ( V_147 , struct V_17 ,
V_156 ) ;
for ( V_151 = 0 ; V_151 < 6 ; V_151 ++ ) {
V_143 = V_18 -> V_157 [ V_151 ] ;
if ( V_143 == 0 )
continue;
V_165 = V_143 & V_159 ;
if ( V_165 ) {
V_143 |=
( ( T_5 ) V_18 -> V_157 [ V_151 + 1 ]
<< 32 ) ;
} else {
V_143 |= 0xffffffffULL << 32 ;
}
V_148 = F_53 ( V_143 ) ;
if ( V_165 ) {
if ( V_160 != V_148 ) {
V_151 ++ ;
continue;
}
F_18 ( V_18 ,
V_169 + ( 4 * V_151 ) ,
4 ,
( T_1 ) ( V_162 & 0xffffff00 ) ) ;
V_151 ++ ;
F_18 ( V_18 ,
V_169 + ( 4 * V_151 ) ,
4 , ( T_1 ) ( V_162 >> 32 ) ) ;
V_162 += V_148 ;
} else {
if ( V_161 != V_148 )
continue;
F_18 ( V_18 ,
V_169 + ( 4 * V_151 ) ,
4 ,
( T_1 ) ( V_163 & 0xffffff00 ) ) ;
V_163 += V_148 ;
}
}
if ( V_160 <= 1 && V_161 <= 1 ) {
F_9 ( V_18 , V_27 , 2 ,
& V_164 ) ;
V_164 |= V_170 ;
F_18 ( V_18 , V_27 , 2 ,
V_164 ) ;
break;
}
}
V_160 >>= 1 ;
V_161 >>= 1 ;
} while ( V_160 || V_161 );
F_16 ( & V_24 -> V_155 , V_22 ) ;
}
static int F_60 ( struct V_47 * V_24 )
{
V_24 -> V_45 = F_61 ( & V_24 -> V_43 -> V_44 ,
0 ,
& V_171 ,
& V_24 -> V_48 ,
& V_24 -> V_172 ) ;
if ( ! V_24 -> V_45 )
return - V_142 ;
V_24 -> V_45 -> V_74 = & V_24 -> V_173 ;
V_24 -> V_45 -> V_74 -> V_174 = & V_24 -> V_43 -> V_44 ;
F_62 ( V_24 -> V_45 ) ;
F_63 ( V_24 -> V_45 ) ;
F_64 ( V_24 -> V_45 ) ;
V_24 -> V_175 = V_176 ;
return 0 ;
}
static void F_65 ( void * V_1 , struct V_2 * V_3 ,
int V_4 )
{
struct V_177 * V_149 = V_1 ;
struct V_178 * V_179 =
(struct V_178 * ) V_3 ;
int V_151 ;
if ( V_3 -> V_7 < 0 ) {
F_17 ( & V_149 -> V_18 -> V_24 -> V_43 -> V_44 ,
L_7 ,
V_3 -> V_7 ) ;
} else {
for ( V_151 = 0 ; V_151 < 6 ; V_151 ++ ) {
V_149 -> V_18 -> V_157 [ V_151 ] =
V_179 -> V_157 [ V_151 ] ;
}
}
F_3 ( & V_149 -> V_9 ) ;
}
static void F_66 ( struct V_17 * V_18 ,
enum V_180 V_181 )
{
F_67 ( & V_18 -> V_182 ) ;
}
static void F_25 ( struct V_17 * V_18 ,
enum V_180 V_181 )
{
if ( F_68 ( & V_18 -> V_182 ) )
F_29 ( V_18 ) ;
}
static struct V_17 * F_69 ( struct V_47 * V_24 ,
struct V_183 * V_29 )
{
struct V_17 * V_18 ;
struct V_184 * V_185 ;
struct V_177 V_6 ;
struct {
struct V_56 V_186 ;
V_28 V_58 [ sizeof( struct V_184 ) ] ;
} V_57 ;
unsigned long V_22 ;
int V_111 ;
V_18 = F_47 ( sizeof( * V_18 ) , V_187 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_24 = V_24 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
F_48 ( & V_6 . V_9 ) ;
V_6 . V_18 = V_18 ;
V_57 . V_186 . V_116 = & V_6 ;
V_57 . V_186 . V_115 = F_65 ;
V_185 = (struct V_184 * ) & V_57 . V_186 . V_60 ;
V_185 -> V_61 . type = V_188 ;
V_185 -> V_12 . V_13 = V_29 -> V_42 . V_13 ;
V_111 = F_28 ( V_24 -> V_43 -> V_63 , V_185 ,
sizeof( struct V_184 ) ,
( unsigned long ) & V_57 . V_186 ,
V_64 ,
V_124 ) ;
if ( V_111 )
goto error;
F_49 ( & V_6 . V_9 ) ;
V_18 -> V_29 = * V_29 ;
F_66 ( V_18 , V_189 ) ;
F_66 ( V_18 , V_190 ) ;
F_10 ( & V_24 -> V_155 , V_22 ) ;
F_70 ( & V_18 -> V_156 , & V_24 -> V_191 ) ;
F_16 ( & V_24 -> V_155 , V_22 ) ;
return V_18 ;
error:
F_29 ( V_18 ) ;
return NULL ;
}
static struct V_17 * F_24 ( struct V_47 * V_24 ,
T_1 V_12 )
{
unsigned long V_22 ;
struct V_17 * V_147 , * V_18 = NULL ;
F_10 ( & V_24 -> V_155 , V_22 ) ;
F_71 (iter, &hbus->children, list_entry) {
if ( V_147 -> V_29 . V_42 . V_13 == V_12 ) {
V_18 = V_147 ;
F_66 ( V_18 , V_50 ) ;
break;
}
}
F_16 ( & V_24 -> V_155 , V_22 ) ;
return V_18 ;
}
static void F_72 ( struct V_192 * V_193 )
{
T_1 V_194 ;
bool V_195 ;
struct V_146 * V_147 ;
struct V_183 * V_196 ;
struct V_17 * V_18 ;
struct V_47 * V_24 ;
struct V_146 V_197 ;
struct V_198 * V_199 ;
struct V_200 * V_201 = NULL ;
unsigned long V_22 ;
V_199 = F_23 ( V_193 , struct V_198 , V_202 ) ;
V_24 = V_199 -> V_46 ;
F_29 ( V_199 ) ;
F_73 ( & V_197 ) ;
if ( F_74 ( & V_24 -> V_203 ) ) {
F_75 ( V_24 ) ;
return;
}
F_10 ( & V_24 -> V_155 , V_22 ) ;
while ( ! F_76 ( & V_24 -> V_204 ) ) {
V_201 = F_77 ( & V_24 -> V_204 , struct V_200 ,
V_156 ) ;
F_78 ( & V_201 -> V_156 ) ;
if ( ! F_76 ( & V_24 -> V_204 ) ) {
F_29 ( V_201 ) ;
continue;
}
}
F_16 ( & V_24 -> V_155 , V_22 ) ;
if ( ! V_201 ) {
F_79 ( & V_24 -> V_203 ) ;
F_75 ( V_24 ) ;
return;
}
F_10 ( & V_24 -> V_155 , V_22 ) ;
F_57 (iter, &hbus->children) {
V_18 = F_23 ( V_147 , struct V_17 ,
V_156 ) ;
V_18 -> V_205 = true ;
}
F_16 ( & V_24 -> V_155 , V_22 ) ;
for ( V_194 = 0 ; V_194 < V_201 -> V_206 ; V_194 ++ ) {
V_195 = false ;
V_196 = & V_201 -> V_15 [ V_194 ] ;
F_10 ( & V_24 -> V_155 , V_22 ) ;
F_57 (iter, &hbus->children) {
V_18 = F_23 ( V_147 , struct V_17 ,
V_156 ) ;
if ( ( V_18 -> V_29 . V_42 . V_13 ==
V_196 -> V_42 . V_13 ) &&
( V_18 -> V_29 . V_30 == V_196 -> V_30 ) &&
( V_18 -> V_29 . V_207 == V_196 -> V_207 ) &&
( V_18 -> V_29 . V_208 == V_196 -> V_208 ) ) {
V_18 -> V_205 = false ;
V_195 = true ;
}
}
F_16 ( & V_24 -> V_155 , V_22 ) ;
if ( ! V_195 ) {
V_18 = F_69 ( V_24 , V_196 ) ;
if ( ! V_18 )
F_17 ( & V_24 -> V_43 -> V_44 ,
L_8 ) ;
}
}
F_10 ( & V_24 -> V_155 , V_22 ) ;
do {
V_195 = false ;
F_57 (iter, &hbus->children) {
V_18 = F_23 ( V_147 , struct V_17 ,
V_156 ) ;
if ( V_18 -> V_205 ) {
V_195 = true ;
F_25 ( V_18 , V_190 ) ;
F_80 ( & V_18 -> V_156 , & V_197 ) ;
break;
}
}
} while ( V_195 );
F_16 ( & V_24 -> V_155 , V_22 ) ;
while ( ! F_76 ( & V_197 ) ) {
V_18 = F_77 ( & V_197 , struct V_17 ,
V_156 ) ;
F_78 ( & V_18 -> V_156 ) ;
F_25 ( V_18 , V_189 ) ;
}
if ( V_24 -> V_175 == V_176 ) {
F_81 () ;
F_62 ( V_24 -> V_45 ) ;
F_82 () ;
} else {
F_55 ( V_24 ) ;
}
F_79 ( & V_24 -> V_203 ) ;
F_75 ( V_24 ) ;
F_29 ( V_201 ) ;
}
static void F_83 ( struct V_47 * V_24 ,
struct V_209 * V_210 )
{
struct V_200 * V_201 ;
struct V_198 * V_199 ;
unsigned long V_22 ;
V_199 = F_47 ( sizeof( * V_199 ) , V_211 ) ;
if ( ! V_199 )
return;
V_201 = F_47 ( F_84 ( struct V_200 , V_15 ) +
( sizeof( struct V_183 ) *
( V_210 -> V_206 ) ) , V_211 ) ;
if ( ! V_201 ) {
F_29 ( V_199 ) ;
return;
}
F_85 ( & V_199 -> V_202 , F_72 ) ;
V_199 -> V_46 = V_24 ;
V_201 -> V_206 = V_210 -> V_206 ;
if ( V_201 -> V_206 != 0 ) {
memcpy ( V_201 -> V_15 , V_210 -> V_15 ,
sizeof( struct V_183 ) *
V_201 -> V_206 ) ;
}
F_10 ( & V_24 -> V_155 , V_22 ) ;
F_70 ( & V_201 -> V_156 , & V_24 -> V_204 ) ;
F_16 ( & V_24 -> V_155 , V_22 ) ;
F_86 ( V_24 ) ;
F_87 ( & V_199 -> V_202 ) ;
}
static void F_88 ( struct V_192 * V_193 )
{
struct V_212 * V_213 ;
struct V_17 * V_18 ;
struct V_70 * V_71 ;
unsigned long V_22 ;
int V_12 ;
struct {
struct V_56 V_57 ;
V_28 V_58 [ sizeof( struct V_212 ) ] ;
} V_59 ;
V_18 = F_23 ( V_193 , struct V_17 , V_202 ) ;
if ( V_18 -> V_175 != V_214 ) {
F_25 ( V_18 , V_215 ) ;
return;
}
V_12 = F_7 ( V_18 -> V_29 . V_42 . V_13 ) ;
V_71 = F_89 ( V_18 -> V_24 -> V_48 . V_66 , 0 ,
V_12 ) ;
if ( V_71 ) {
F_90 ( V_71 ) ;
F_91 ( V_71 ) ;
}
F_10 ( & V_18 -> V_24 -> V_155 , V_22 ) ;
F_78 ( & V_18 -> V_156 ) ;
F_16 ( & V_18 -> V_24 -> V_155 , V_22 ) ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_213 = (struct V_212 * ) & V_59 . V_57 . V_60 ;
V_213 -> V_61 . type = V_216 ;
V_213 -> V_12 . V_13 = V_18 -> V_29 . V_42 . V_13 ;
F_28 ( V_18 -> V_24 -> V_43 -> V_63 , V_213 ,
sizeof( * V_213 ) , ( unsigned long ) & V_59 . V_57 ,
V_64 , 0 ) ;
F_25 ( V_18 , V_190 ) ;
F_25 ( V_18 , V_215 ) ;
F_75 ( V_18 -> V_24 ) ;
}
static void F_92 ( struct V_17 * V_18 )
{
V_18 -> V_175 = V_214 ;
F_66 ( V_18 , V_215 ) ;
F_85 ( & V_18 -> V_202 , F_88 ) ;
F_86 ( V_18 -> V_24 ) ;
F_87 ( & V_18 -> V_202 ) ;
}
static void F_93 ( void * V_1 )
{
const int V_217 = 0x100 ;
int V_111 ;
struct V_47 * V_24 = V_1 ;
T_1 V_218 ;
T_5 V_219 ;
struct V_220 * V_29 ;
unsigned char * V_58 ;
int V_221 = V_217 ;
struct V_56 * V_222 ;
struct V_2 * V_223 ;
struct V_224 * V_225 ;
struct V_209 * V_226 ;
struct V_227 * V_228 ;
struct V_17 * V_18 ;
V_58 = F_94 ( V_221 , V_187 ) ;
if ( ! V_58 )
return;
while ( 1 ) {
V_111 = F_95 ( V_24 -> V_43 -> V_63 , V_58 ,
V_221 , & V_218 , & V_219 ) ;
if ( V_111 == - V_229 ) {
F_29 ( V_58 ) ;
V_221 = V_218 ;
V_58 = F_94 ( V_218 , V_187 ) ;
if ( ! V_58 )
return;
continue;
}
if ( V_111 || ! V_218 )
break;
if ( V_218 <= sizeof( struct V_2 ) )
continue;
V_29 = (struct V_220 * ) V_58 ;
switch ( V_29 -> type ) {
case V_230 :
V_222 = (struct V_56 * ) V_219 ;
V_223 = (struct V_2 * ) V_58 ;
V_222 -> V_115 ( V_222 -> V_116 ,
V_223 ,
V_218 ) ;
break;
case V_64 :
V_225 = (struct V_224 * ) V_58 ;
switch ( V_225 -> V_61 . type ) {
case V_231 :
V_226 = (struct V_209 * ) V_58 ;
if ( V_218 <
F_84 ( struct V_209 , V_15 ) +
( sizeof( struct V_183 ) *
( V_226 -> V_206 ) ) ) {
F_17 ( & V_24 -> V_43 -> V_44 ,
L_9 ) ;
break;
}
F_83 ( V_24 , V_226 ) ;
break;
case V_232 :
V_228 = (struct V_227 * ) V_58 ;
V_18 = F_24 ( V_24 ,
V_228 -> V_12 . V_13 ) ;
if ( V_18 ) {
F_92 ( V_18 ) ;
F_25 ( V_18 ,
V_50 ) ;
}
break;
default:
F_96 ( & V_24 -> V_43 -> V_44 ,
L_10 ,
V_225 -> V_61 . type ) ;
break;
}
break;
default:
F_17 ( & V_24 -> V_43 -> V_44 ,
L_11 ,
V_29 -> type , V_219 , V_218 ) ;
break;
}
}
F_29 ( V_58 ) ;
}
static int F_97 ( struct V_233 * V_43 )
{
struct V_234 * V_235 ;
struct V_5 V_6 ;
struct V_56 * V_57 ;
int V_111 ;
V_57 = F_47 ( sizeof( * V_57 ) + sizeof( * V_235 ) , V_113 ) ;
if ( ! V_57 )
return - V_236 ;
F_48 ( & V_6 . V_9 ) ;
V_57 -> V_115 = F_1 ;
V_57 -> V_116 = & V_6 ;
V_235 = (struct V_234 * ) & V_57 -> V_60 ;
V_235 -> V_61 . type = V_237 ;
V_235 -> V_238 = V_239 ;
V_111 = F_28 ( V_43 -> V_63 , V_235 ,
sizeof( struct V_234 ) ,
( unsigned long ) V_57 , V_64 ,
V_124 ) ;
if ( V_111 )
goto exit;
F_49 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
F_17 ( & V_43 -> V_44 ,
L_12 ,
V_6 . V_8 ) ;
V_111 = - V_240 ;
goto exit;
}
V_111 = 0 ;
exit:
F_29 ( V_57 ) ;
return V_111 ;
}
static void F_98 ( struct V_47 * V_24 )
{
if ( V_24 -> V_153 && V_24 -> V_166 ) {
V_24 -> V_166 -> V_22 |= V_241 ;
F_99 ( V_24 -> V_166 -> V_167 ,
F_100 ( V_24 -> V_166 ) ) ;
}
if ( V_24 -> V_154 && V_24 -> V_168 ) {
V_24 -> V_168 -> V_22 |= V_241 ;
F_99 ( V_24 -> V_168 -> V_167 ,
F_100 ( V_24 -> V_168 ) ) ;
}
}
static int F_101 ( struct V_47 * V_24 )
{
T_6 V_242 ;
int V_111 ;
if ( V_24 -> V_153 ) {
V_242 = 1ULL << ( 63 - F_59 ( V_24 -> V_153 ) ) ;
V_111 = F_102 ( & V_24 -> V_166 , V_24 -> V_43 , 0 ,
( T_5 ) ( T_1 ) 0xffffffff ,
V_24 -> V_153 ,
V_242 , false ) ;
if ( V_111 ) {
F_17 ( & V_24 -> V_43 -> V_44 ,
L_13 ,
V_24 -> V_153 ) ;
return V_111 ;
}
V_24 -> V_166 -> V_22 |= V_243 ;
V_24 -> V_166 -> V_22 &= ~ V_241 ;
F_103 ( & V_24 -> V_172 ,
V_24 -> V_166 ) ;
}
if ( V_24 -> V_154 ) {
V_242 = 1ULL << ( 63 - F_59 ( V_24 -> V_154 ) ) ;
V_111 = F_102 ( & V_24 -> V_168 , V_24 -> V_43 ,
0x100000000 , - 1 ,
V_24 -> V_154 , V_242 ,
false ) ;
if ( V_111 ) {
F_17 ( & V_24 -> V_43 -> V_44 ,
L_14 ,
V_24 -> V_154 ) ;
goto V_244;
}
V_24 -> V_168 -> V_22 |= V_243 ;
V_24 -> V_168 -> V_22 &= ~ V_241 ;
F_103 ( & V_24 -> V_172 ,
V_24 -> V_168 ) ;
}
return 0 ;
V_244:
if ( V_24 -> V_166 ) {
F_99 ( V_24 -> V_166 -> V_167 ,
F_100 ( V_24 -> V_166 ) ) ;
}
return V_111 ;
}
static int F_104 ( struct V_47 * V_24 )
{
int V_111 ;
V_111 = F_102 ( & V_24 -> V_245 , V_24 -> V_43 , 0 , - 1 ,
V_246 , 0x1000 , false ) ;
if ( V_111 )
return V_111 ;
V_24 -> V_245 -> V_22 |= V_241 ;
return 0 ;
}
static void F_105 ( struct V_47 * V_24 )
{
F_99 ( V_24 -> V_245 -> V_167 , V_246 ) ;
}
static int F_106 ( struct V_233 * V_43 )
{
struct V_47 * V_24 = F_107 ( V_43 ) ;
struct V_247 * V_248 ;
struct V_5 V_6 ;
struct V_56 * V_57 ;
int V_111 ;
V_57 = F_47 ( sizeof( * V_57 ) + sizeof( * V_248 ) , V_113 ) ;
if ( ! V_57 )
return - V_236 ;
F_48 ( & V_6 . V_9 ) ;
V_57 -> V_115 = F_1 ;
V_57 -> V_116 = & V_6 ;
V_248 = (struct V_247 * ) & V_57 -> V_60 ;
V_248 -> V_61 . type = V_249 ;
V_248 -> V_250 = V_24 -> V_245 -> V_167 ;
V_111 = F_28 ( V_43 -> V_63 , V_248 , sizeof( * V_248 ) ,
( unsigned long ) V_57 , V_64 ,
V_124 ) ;
if ( V_111 )
goto exit;
F_49 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
F_17 ( & V_43 -> V_44 ,
L_15 ,
V_6 . V_8 ) ;
V_111 = - V_240 ;
goto exit;
}
V_111 = 0 ;
exit:
F_29 ( V_57 ) ;
return V_111 ;
}
static int F_108 ( struct V_233 * V_43 )
{
struct V_47 * V_24 = F_107 ( V_43 ) ;
struct V_251 V_60 ;
struct V_149 V_109 ;
int V_111 ;
F_48 ( & V_109 ) ;
if ( F_109 ( & V_24 -> V_152 , NULL , & V_109 ) )
return - V_252 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . type = V_253 ;
V_111 = F_28 ( V_43 -> V_63 , & V_60 , sizeof( V_60 ) ,
0 , V_64 , 0 ) ;
if ( V_111 )
return V_111 ;
F_49 ( & V_109 ) ;
return 0 ;
}
static int F_110 ( struct V_233 * V_43 )
{
struct V_47 * V_24 = F_107 ( V_43 ) ;
struct V_254 * V_255 ;
struct V_5 V_6 ;
struct V_17 * V_18 ;
struct V_56 * V_57 ;
T_1 V_12 ;
int V_111 ;
V_57 = F_94 ( sizeof( * V_57 ) + sizeof( * V_255 ) , V_113 ) ;
if ( ! V_57 )
return - V_236 ;
V_111 = 0 ;
for ( V_12 = 0 ; V_12 < 256 ; V_12 ++ ) {
V_18 = F_24 ( V_24 , V_12 ) ;
if ( ! V_18 )
continue;
memset ( V_57 , 0 , sizeof( * V_57 ) + sizeof( * V_255 ) ) ;
F_48 ( & V_6 . V_9 ) ;
V_57 -> V_115 = F_1 ;
V_57 -> V_116 = & V_6 ;
V_255 = (struct V_254 * ) & V_57 -> V_60 ;
V_255 -> V_61 . type = V_256 ;
V_255 -> V_12 . V_13 = V_18 -> V_29 . V_42 . V_13 ;
F_25 ( V_18 , V_50 ) ;
V_111 = F_28 (
V_43 -> V_63 , & V_57 -> V_60 ,
sizeof( * V_255 ) ,
( unsigned long ) V_57 ,
V_64 ,
V_124 ) ;
if ( V_111 )
break;
F_49 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
V_111 = - V_240 ;
F_17 ( & V_43 -> V_44 ,
L_16 ,
V_6 . V_8 ) ;
break;
}
}
F_29 ( V_57 ) ;
return V_111 ;
}
static int F_111 ( struct V_233 * V_43 )
{
struct V_47 * V_24 = F_107 ( V_43 ) ;
struct V_184 V_57 ;
struct V_17 * V_18 ;
T_1 V_12 ;
int V_111 ;
for ( V_12 = 0 ; V_12 < 256 ; V_12 ++ ) {
V_18 = F_24 ( V_24 , V_12 ) ;
if ( ! V_18 )
continue;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_61 . type = V_257 ;
V_57 . V_12 . V_13 = V_18 -> V_29 . V_42 . V_13 ;
F_25 ( V_18 , V_50 ) ;
V_111 = F_28 ( V_43 -> V_63 , & V_57 , sizeof( V_57 ) , 0 ,
V_64 , 0 ) ;
if ( V_111 )
return V_111 ;
}
return 0 ;
}
static void F_86 ( struct V_47 * V_24 )
{
F_67 ( & V_24 -> V_258 ) ;
}
static void F_75 ( struct V_47 * V_24 )
{
if ( F_68 ( & V_24 -> V_258 ) )
F_3 ( & V_24 -> V_259 ) ;
}
static int F_112 ( struct V_233 * V_43 ,
const struct V_260 * V_261 )
{
struct V_47 * V_24 ;
int V_111 ;
V_24 = F_47 ( sizeof( * V_24 ) , V_113 ) ;
if ( ! V_24 )
return - V_236 ;
V_24 -> V_48 . V_66 = V_43 -> V_99 . V_100 [ 9 ] |
V_43 -> V_99 . V_100 [ 8 ] << 8 ;
V_24 -> V_43 = V_43 ;
F_67 ( & V_24 -> V_258 ) ;
F_73 ( & V_24 -> V_191 ) ;
F_73 ( & V_24 -> V_204 ) ;
F_73 ( & V_24 -> V_172 ) ;
F_113 ( & V_24 -> V_41 ) ;
F_113 ( & V_24 -> V_155 ) ;
F_113 ( & V_24 -> V_90 ) ;
F_114 ( & V_24 -> V_203 , 1 ) ;
F_48 ( & V_24 -> V_259 ) ;
V_111 = F_115 ( V_43 -> V_63 , V_262 , V_262 , NULL , 0 ,
F_93 , V_24 ) ;
if ( V_111 )
goto V_263;
F_116 ( V_43 , V_24 ) ;
V_111 = F_97 ( V_43 ) ;
if ( V_111 )
goto V_264;
V_111 = F_104 ( V_24 ) ;
if ( V_111 )
goto V_264;
V_24 -> V_25 = F_117 ( V_24 -> V_245 -> V_167 ,
V_246 ) ;
if ( ! V_24 -> V_25 ) {
F_17 ( & V_43 -> V_44 ,
L_17 ) ;
V_111 = - V_236 ;
goto V_265;
}
V_24 -> V_48 . V_140 = F_118 ( V_24 ) ;
if ( ! V_24 -> V_48 . V_140 ) {
V_111 = - V_236 ;
goto V_266;
}
V_111 = F_51 ( V_24 ) ;
if ( V_111 )
goto V_267;
V_111 = F_108 ( V_43 ) ;
if ( V_111 )
goto V_268;
V_111 = F_106 ( V_43 ) ;
if ( V_111 )
goto V_268;
V_111 = F_101 ( V_24 ) ;
if ( V_111 )
goto V_268;
V_111 = F_110 ( V_43 ) ;
if ( V_111 )
goto V_269;
F_58 ( V_24 ) ;
V_24 -> V_175 = V_270 ;
V_111 = F_60 ( V_24 ) ;
if ( V_111 )
goto V_269;
return 0 ;
V_269:
F_98 ( V_24 ) ;
V_268:
F_119 ( V_24 -> V_65 ) ;
V_267:
F_120 ( V_24 -> V_48 . V_140 ) ;
V_266:
F_121 ( V_24 -> V_25 ) ;
V_265:
F_105 ( V_24 ) ;
V_264:
F_122 ( V_43 -> V_63 ) ;
V_263:
F_29 ( V_24 ) ;
return V_111 ;
}
static void F_123 ( struct V_233 * V_43 )
{
struct V_47 * V_24 = F_107 ( V_43 ) ;
struct {
struct V_56 V_271 ;
V_28 V_58 [ sizeof( struct V_251 ) ] ;
} V_57 ;
struct V_209 V_210 ;
struct V_5 V_6 ;
int V_111 ;
if ( V_43 -> V_63 -> V_272 )
return;
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
F_83 ( V_24 , & V_210 ) ;
V_111 = F_111 ( V_43 ) ;
if ( V_111 )
F_17 ( & V_43 -> V_44 ,
L_18 ) ;
memset ( & V_57 . V_271 , 0 , sizeof( V_57 . V_271 ) ) ;
F_48 ( & V_6 . V_9 ) ;
V_57 . V_271 . V_115 = F_1 ;
V_57 . V_271 . V_116 = & V_6 ;
V_57 . V_271 . V_60 [ 0 ] . type = V_273 ;
V_111 = F_28 ( V_43 -> V_63 , & V_57 . V_271 . V_60 ,
sizeof( struct V_251 ) ,
( unsigned long ) & V_57 . V_271 ,
V_64 ,
V_124 ) ;
if ( ! V_111 )
F_124 ( & V_6 . V_9 , 10 * V_274 ) ;
}
static int F_125 ( struct V_233 * V_43 )
{
struct V_47 * V_24 ;
V_24 = F_107 ( V_43 ) ;
if ( V_24 -> V_175 == V_176 ) {
F_81 () ;
F_126 ( V_24 -> V_45 ) ;
F_127 ( V_24 -> V_45 ) ;
F_82 () ;
}
F_123 ( V_43 ) ;
F_122 ( V_43 -> V_63 ) ;
F_121 ( V_24 -> V_25 ) ;
F_105 ( V_24 ) ;
F_128 ( & V_24 -> V_172 ) ;
F_98 ( V_24 ) ;
F_119 ( V_24 -> V_65 ) ;
F_120 ( V_24 -> V_48 . V_140 ) ;
F_75 ( V_24 ) ;
F_49 ( & V_24 -> V_259 ) ;
F_29 ( V_24 ) ;
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
