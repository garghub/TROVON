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
if ( F_49 ( V_111 ) >= 32 ) {
V_56 -> V_54 . V_124 = V_125 ;
} else {
F_41 (cpu, affinity, cpu_online_mask) {
V_56 -> V_54 . V_124 |=
( 1ULL << F_42 ( V_90 ) ) ;
}
}
V_112 = F_28 ( V_19 -> V_25 -> V_44 -> V_64 , V_56 ,
sizeof( * V_56 ) , ( unsigned long ) & V_60 . V_58 ,
V_65 ,
V_126 ) ;
if ( V_112 )
goto V_127;
F_50 ( & V_110 . V_6 . V_9 ) ;
if ( V_110 . V_6 . V_8 < 0 ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_3 ,
V_110 . V_6 . V_8 ) ;
goto V_127;
}
* V_54 = V_110 . V_54 ;
V_76 -> V_77 = V_54 ;
V_97 -> V_128 = V_110 . V_54 . V_96 >> 32 ;
V_97 -> V_98 = V_110 . V_54 . V_96 & 0xffffffff ;
V_97 -> V_76 = V_110 . V_54 . V_76 ;
F_25 ( V_19 , V_51 ) ;
return;
V_127:
F_29 ( V_54 ) ;
V_115:
F_25 ( V_19 , V_51 ) ;
V_113:
V_97 -> V_128 = 0 ;
V_97 -> V_98 = 0 ;
V_97 -> V_76 = 0 ;
}
static T_3 F_51 ( struct V_68 * V_69 ,
T_4 * V_129 )
{
return V_129 -> V_130 ;
}
static int F_52 ( struct V_48 * V_25 )
{
V_25 -> V_131 . V_83 = & V_132 ;
V_25 -> V_131 . V_133 = & V_134 ;
V_25 -> V_131 . V_23 = ( V_135 |
V_136 | V_137 |
V_138 ) ;
V_25 -> V_131 . V_139 = V_140 ;
V_25 -> V_131 . V_141 = L_4 ;
V_25 -> V_131 . V_76 = V_25 ;
V_25 -> V_66 = F_53 ( V_25 -> V_49 . V_142 ,
& V_25 -> V_131 ,
V_143 ) ;
if ( ! V_25 -> V_66 ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_5 ) ;
return - V_144 ;
}
return 0 ;
}
static T_5 F_54 ( T_5 V_145 )
{
return F_55 ( ( 1 + ~ ( V_145 & V_146 ) ) ,
V_147 ) ;
}
static void F_56 ( struct V_48 * V_25 )
{
struct V_148 * V_149 ;
struct V_18 * V_19 ;
T_6 V_150 = 0 ;
unsigned long V_23 ;
struct V_151 * V_152 ;
T_5 V_145 ;
int V_153 ;
V_152 = F_57 ( & V_25 -> V_154 , NULL ) ;
if ( ! V_152 )
return;
if ( V_25 -> V_155 || V_25 -> V_156 ) {
F_3 ( V_152 ) ;
return;
}
F_10 ( & V_25 -> V_157 , V_23 ) ;
F_58 (iter, &hbus->children) {
V_19 = F_23 ( V_149 , struct V_18 , V_158 ) ;
for ( V_153 = 0 ; V_153 < 6 ; V_153 ++ ) {
if ( V_19 -> V_159 [ V_153 ] & V_160 )
F_17 ( & V_25 -> V_44 -> V_45 ,
L_6 ) ;
if ( V_19 -> V_159 [ V_153 ] != 0 ) {
V_145 = V_19 -> V_159 [ V_153 ] ;
if ( V_145 & V_161 )
V_145 |=
( ( T_5 ) V_19 -> V_159 [ ++ V_153 ] << 32 ) ;
else
V_145 |= 0xffffffff00000000ULL ;
V_150 = F_54 ( V_145 ) ;
if ( V_145 & V_161 )
V_25 -> V_156 += V_150 ;
else
V_25 -> V_155 += V_150 ;
}
}
}
F_16 ( & V_25 -> V_157 , V_23 ) ;
F_3 ( V_152 ) ;
}
static void F_59 ( struct V_48 * V_25 )
{
T_6 V_162 = 0 ;
T_6 V_163 = 0 ;
T_6 V_164 = 0 ;
T_6 V_165 = 0 ;
T_6 V_150 ;
struct V_18 * V_19 ;
struct V_148 * V_149 ;
unsigned long V_23 ;
T_5 V_145 ;
T_1 V_166 ;
bool V_167 ;
int V_153 ;
if ( V_25 -> V_155 ) {
V_163 = 1ULL << ( 63 - F_60 ( V_25 -> V_155 ) ) ;
V_165 = V_25 -> V_168 -> V_169 ;
}
if ( V_25 -> V_156 ) {
V_162 = 1ULL <<
( 63 - F_60 ( V_25 -> V_156 ) ) ;
V_164 = V_25 -> V_170 -> V_169 ;
}
F_10 ( & V_25 -> V_157 , V_23 ) ;
do {
F_58 (iter, &hbus->children) {
V_19 = F_23 ( V_149 , struct V_18 ,
V_158 ) ;
for ( V_153 = 0 ; V_153 < 6 ; V_153 ++ ) {
V_145 = V_19 -> V_159 [ V_153 ] ;
if ( V_145 == 0 )
continue;
V_167 = V_145 & V_161 ;
if ( V_167 ) {
V_145 |=
( ( T_5 ) V_19 -> V_159 [ V_153 + 1 ]
<< 32 ) ;
} else {
V_145 |= 0xffffffffULL << 32 ;
}
V_150 = F_54 ( V_145 ) ;
if ( V_167 ) {
if ( V_162 != V_150 ) {
V_153 ++ ;
continue;
}
F_18 ( V_19 ,
V_171 + ( 4 * V_153 ) ,
4 ,
( T_1 ) ( V_164 & 0xffffff00 ) ) ;
V_153 ++ ;
F_18 ( V_19 ,
V_171 + ( 4 * V_153 ) ,
4 , ( T_1 ) ( V_164 >> 32 ) ) ;
V_164 += V_150 ;
} else {
if ( V_163 != V_150 )
continue;
F_18 ( V_19 ,
V_171 + ( 4 * V_153 ) ,
4 ,
( T_1 ) ( V_165 & 0xffffff00 ) ) ;
V_165 += V_150 ;
}
}
if ( V_162 <= 1 && V_163 <= 1 ) {
F_9 ( V_19 , V_28 , 2 ,
& V_166 ) ;
V_166 |= V_172 ;
F_18 ( V_19 , V_28 , 2 ,
V_166 ) ;
break;
}
}
V_162 >>= 1 ;
V_163 >>= 1 ;
} while ( V_162 || V_163 );
F_16 ( & V_25 -> V_157 , V_23 ) ;
}
static int F_61 ( struct V_48 * V_25 )
{
V_25 -> V_46 = F_62 ( & V_25 -> V_44 -> V_45 ,
0 ,
& V_173 ,
& V_25 -> V_49 ,
& V_25 -> V_174 ) ;
if ( ! V_25 -> V_46 )
return - V_144 ;
V_25 -> V_46 -> V_75 = & V_25 -> V_175 ;
V_25 -> V_46 -> V_75 -> V_15 = & V_25 -> V_44 -> V_45 ;
F_63 () ;
F_64 ( V_25 -> V_46 ) ;
F_65 ( V_25 -> V_46 ) ;
F_66 ( V_25 -> V_46 ) ;
F_67 () ;
V_25 -> V_176 = V_177 ;
return 0 ;
}
static void F_68 ( void * V_1 , struct V_2 * V_3 ,
int V_4 )
{
struct V_178 * V_151 = V_1 ;
struct V_179 * V_180 =
(struct V_179 * ) V_3 ;
int V_153 ;
if ( V_3 -> V_7 < 0 ) {
F_17 ( & V_151 -> V_19 -> V_25 -> V_44 -> V_45 ,
L_7 ,
V_3 -> V_7 ) ;
} else {
for ( V_153 = 0 ; V_153 < 6 ; V_153 ++ ) {
V_151 -> V_19 -> V_159 [ V_153 ] =
V_180 -> V_159 [ V_153 ] ;
}
}
F_3 ( & V_151 -> V_9 ) ;
}
static void F_69 ( struct V_18 * V_19 ,
enum V_181 V_182 )
{
F_70 ( & V_19 -> V_183 ) ;
}
static void F_25 ( struct V_18 * V_19 ,
enum V_181 V_182 )
{
if ( F_71 ( & V_19 -> V_183 ) )
F_29 ( V_19 ) ;
}
static struct V_18 * F_72 ( struct V_48 * V_25 ,
struct V_184 * V_30 )
{
struct V_18 * V_19 ;
struct V_185 * V_186 ;
struct V_178 V_6 ;
struct {
struct V_57 V_187 ;
V_29 V_59 [ sizeof( struct V_185 ) ] ;
} V_58 ;
unsigned long V_23 ;
int V_112 ;
V_19 = F_47 ( sizeof( * V_19 ) , V_114 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_25 = V_25 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
F_48 ( & V_6 . V_9 ) ;
V_6 . V_19 = V_19 ;
V_58 . V_187 . V_117 = & V_6 ;
V_58 . V_187 . V_116 = F_68 ;
V_186 = (struct V_185 * ) & V_58 . V_187 . V_61 ;
V_186 -> V_62 . type = V_188 ;
V_186 -> V_12 . V_13 = V_30 -> V_43 . V_13 ;
V_112 = F_28 ( V_25 -> V_44 -> V_64 , V_186 ,
sizeof( struct V_185 ) ,
( unsigned long ) & V_58 . V_187 ,
V_65 ,
V_126 ) ;
if ( V_112 )
goto error;
F_50 ( & V_6 . V_9 ) ;
V_19 -> V_30 = * V_30 ;
F_73 ( & V_19 -> V_183 , 1 ) ;
F_69 ( V_19 , V_189 ) ;
F_10 ( & V_25 -> V_157 , V_23 ) ;
if ( F_74 ( & V_25 -> V_190 ) )
V_25 -> V_49 . V_67 = V_30 -> V_191 ;
F_75 ( & V_19 -> V_158 , & V_25 -> V_190 ) ;
F_16 ( & V_25 -> V_157 , V_23 ) ;
return V_19 ;
error:
F_29 ( V_19 ) ;
return NULL ;
}
static struct V_18 * F_24 ( struct V_48 * V_25 ,
T_1 V_12 )
{
unsigned long V_23 ;
struct V_18 * V_149 , * V_19 = NULL ;
F_10 ( & V_25 -> V_157 , V_23 ) ;
F_76 (iter, &hbus->children, list_entry) {
if ( V_149 -> V_30 . V_43 . V_13 == V_12 ) {
V_19 = V_149 ;
F_69 ( V_19 , V_51 ) ;
break;
}
}
F_16 ( & V_25 -> V_157 , V_23 ) ;
return V_19 ;
}
static void F_77 ( struct V_192 * V_193 )
{
T_1 V_194 ;
bool V_195 ;
struct V_148 * V_149 ;
struct V_184 * V_196 ;
struct V_18 * V_19 ;
struct V_48 * V_25 ;
struct V_148 V_197 ;
struct V_198 * V_199 ;
struct V_200 * V_201 = NULL ;
unsigned long V_23 ;
V_199 = F_23 ( V_193 , struct V_198 , V_202 ) ;
V_25 = V_199 -> V_47 ;
F_29 ( V_199 ) ;
F_78 ( & V_197 ) ;
if ( F_79 ( & V_25 -> V_203 ) ) {
F_80 ( V_25 ) ;
return;
}
F_10 ( & V_25 -> V_157 , V_23 ) ;
while ( ! F_74 ( & V_25 -> V_204 ) ) {
V_201 = F_81 ( & V_25 -> V_204 , struct V_200 ,
V_158 ) ;
F_82 ( & V_201 -> V_158 ) ;
if ( ! F_74 ( & V_25 -> V_204 ) ) {
F_29 ( V_201 ) ;
continue;
}
}
F_16 ( & V_25 -> V_157 , V_23 ) ;
if ( ! V_201 ) {
F_83 ( & V_25 -> V_203 ) ;
F_80 ( V_25 ) ;
return;
}
F_10 ( & V_25 -> V_157 , V_23 ) ;
F_58 (iter, &hbus->children) {
V_19 = F_23 ( V_149 , struct V_18 ,
V_158 ) ;
V_19 -> V_205 = true ;
}
F_16 ( & V_25 -> V_157 , V_23 ) ;
for ( V_194 = 0 ; V_194 < V_201 -> V_206 ; V_194 ++ ) {
V_195 = false ;
V_196 = & V_201 -> V_16 [ V_194 ] ;
F_10 ( & V_25 -> V_157 , V_23 ) ;
F_58 (iter, &hbus->children) {
V_19 = F_23 ( V_149 , struct V_18 ,
V_158 ) ;
if ( ( V_19 -> V_30 . V_43 . V_13 ==
V_196 -> V_43 . V_13 ) &&
( V_19 -> V_30 . V_31 == V_196 -> V_31 ) &&
( V_19 -> V_30 . V_207 == V_196 -> V_207 ) &&
( V_19 -> V_30 . V_191 == V_196 -> V_191 ) ) {
V_19 -> V_205 = false ;
V_195 = true ;
}
}
F_16 ( & V_25 -> V_157 , V_23 ) ;
if ( ! V_195 ) {
V_19 = F_72 ( V_25 , V_196 ) ;
if ( ! V_19 )
F_17 ( & V_25 -> V_44 -> V_45 ,
L_8 ) ;
}
}
F_10 ( & V_25 -> V_157 , V_23 ) ;
do {
V_195 = false ;
F_58 (iter, &hbus->children) {
V_19 = F_23 ( V_149 , struct V_18 ,
V_158 ) ;
if ( V_19 -> V_205 ) {
V_195 = true ;
F_25 ( V_19 , V_189 ) ;
F_84 ( & V_19 -> V_158 , & V_197 ) ;
break;
}
}
} while ( V_195 );
F_16 ( & V_25 -> V_157 , V_23 ) ;
while ( ! F_74 ( & V_197 ) ) {
V_19 = F_81 ( & V_197 , struct V_18 ,
V_158 ) ;
F_82 ( & V_19 -> V_158 ) ;
F_25 ( V_19 , V_208 ) ;
}
switch( V_25 -> V_176 ) {
case V_177 :
F_63 () ;
F_64 ( V_25 -> V_46 ) ;
F_67 () ;
break;
case V_209 :
case V_210 :
F_56 ( V_25 ) ;
break;
default:
break;
}
F_83 ( & V_25 -> V_203 ) ;
F_80 ( V_25 ) ;
F_29 ( V_201 ) ;
}
static void F_85 ( struct V_48 * V_25 ,
struct V_211 * V_212 )
{
struct V_200 * V_201 ;
struct V_198 * V_199 ;
unsigned long V_23 ;
V_199 = F_47 ( sizeof( * V_199 ) , V_213 ) ;
if ( ! V_199 )
return;
V_201 = F_47 ( F_86 ( struct V_200 , V_16 ) +
( sizeof( struct V_184 ) *
( V_212 -> V_206 ) ) , V_213 ) ;
if ( ! V_201 ) {
F_29 ( V_199 ) ;
return;
}
F_87 ( & V_199 -> V_202 , F_77 ) ;
V_199 -> V_47 = V_25 ;
V_201 -> V_206 = V_212 -> V_206 ;
if ( V_201 -> V_206 != 0 ) {
memcpy ( V_201 -> V_16 , V_212 -> V_16 ,
sizeof( struct V_184 ) *
V_201 -> V_206 ) ;
}
F_10 ( & V_25 -> V_157 , V_23 ) ;
F_75 ( & V_201 -> V_158 , & V_25 -> V_204 ) ;
F_16 ( & V_25 -> V_157 , V_23 ) ;
F_88 ( V_25 ) ;
F_89 ( & V_199 -> V_202 ) ;
}
static void F_90 ( struct V_192 * V_193 )
{
struct V_214 * V_215 ;
struct V_18 * V_19 ;
struct V_71 * V_72 ;
unsigned long V_23 ;
int V_12 ;
struct {
struct V_57 V_58 ;
V_29 V_59 [ sizeof( struct V_214 ) ] ;
} V_60 ;
V_19 = F_23 ( V_193 , struct V_18 , V_202 ) ;
if ( V_19 -> V_176 != V_216 ) {
F_25 ( V_19 , V_217 ) ;
return;
}
V_12 = F_7 ( V_19 -> V_30 . V_43 . V_13 ) ;
V_72 = F_91 ( V_19 -> V_25 -> V_49 . V_67 , 0 ,
V_12 ) ;
if ( V_72 ) {
F_63 () ;
F_92 ( V_72 ) ;
F_93 ( V_72 ) ;
F_67 () ;
}
F_10 ( & V_19 -> V_25 -> V_157 , V_23 ) ;
F_82 ( & V_19 -> V_158 ) ;
F_16 ( & V_19 -> V_25 -> V_157 , V_23 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_215 = (struct V_214 * ) & V_60 . V_58 . V_61 ;
V_215 -> V_62 . type = V_218 ;
V_215 -> V_12 . V_13 = V_19 -> V_30 . V_43 . V_13 ;
F_28 ( V_19 -> V_25 -> V_44 -> V_64 , V_215 ,
sizeof( * V_215 ) , ( unsigned long ) & V_60 . V_58 ,
V_65 , 0 ) ;
F_25 ( V_19 , V_189 ) ;
F_25 ( V_19 , V_217 ) ;
F_80 ( V_19 -> V_25 ) ;
}
static void F_94 ( struct V_18 * V_19 )
{
V_19 -> V_176 = V_216 ;
F_69 ( V_19 , V_217 ) ;
F_87 ( & V_19 -> V_202 , F_90 ) ;
F_88 ( V_19 -> V_25 ) ;
F_89 ( & V_19 -> V_202 ) ;
}
static void F_95 ( void * V_1 )
{
const int V_219 = 0x100 ;
int V_112 ;
struct V_48 * V_25 = V_1 ;
T_1 V_220 ;
T_5 V_221 ;
struct V_222 * V_30 ;
unsigned char * V_59 ;
int V_223 = V_219 ;
struct V_57 * V_224 ;
struct V_2 * V_225 ;
struct V_226 * V_227 ;
struct V_211 * V_228 ;
struct V_229 * V_230 ;
struct V_18 * V_19 ;
V_59 = F_96 ( V_223 , V_114 ) ;
if ( ! V_59 )
return;
while ( 1 ) {
V_112 = F_97 ( V_25 -> V_44 -> V_64 , V_59 ,
V_223 , & V_220 , & V_221 ) ;
if ( V_112 == - V_231 ) {
F_29 ( V_59 ) ;
V_223 = V_220 ;
V_59 = F_96 ( V_220 , V_114 ) ;
if ( ! V_59 )
return;
continue;
}
if ( V_112 || ! V_220 )
break;
if ( V_220 <= sizeof( struct V_2 ) )
continue;
V_30 = (struct V_222 * ) V_59 ;
switch ( V_30 -> type ) {
case V_232 :
V_224 = (struct V_57 * ) V_221 ;
V_225 = (struct V_2 * ) V_59 ;
V_224 -> V_116 ( V_224 -> V_117 ,
V_225 ,
V_220 ) ;
break;
case V_65 :
V_227 = (struct V_226 * ) V_59 ;
switch ( V_227 -> V_62 . type ) {
case V_233 :
V_228 = (struct V_211 * ) V_59 ;
if ( V_220 <
F_86 ( struct V_211 , V_16 ) +
( sizeof( struct V_184 ) *
( V_228 -> V_206 ) ) ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_9 ) ;
break;
}
F_85 ( V_25 , V_228 ) ;
break;
case V_234 :
V_230 = (struct V_229 * ) V_59 ;
V_19 = F_24 ( V_25 ,
V_230 -> V_12 . V_13 ) ;
if ( V_19 ) {
F_94 ( V_19 ) ;
F_25 ( V_19 ,
V_51 ) ;
}
break;
default:
F_98 ( & V_25 -> V_44 -> V_45 ,
L_10 ,
V_227 -> V_62 . type ) ;
break;
}
break;
default:
F_17 ( & V_25 -> V_44 -> V_45 ,
L_11 ,
V_30 -> type , V_221 , V_220 ) ;
break;
}
}
F_29 ( V_59 ) ;
}
static int F_99 ( struct V_235 * V_44 )
{
struct V_236 * V_237 ;
struct V_5 V_6 ;
struct V_57 * V_58 ;
int V_112 ;
V_58 = F_47 ( sizeof( * V_58 ) + sizeof( * V_237 ) , V_238 ) ;
if ( ! V_58 )
return - V_239 ;
F_48 ( & V_6 . V_9 ) ;
V_58 -> V_116 = F_1 ;
V_58 -> V_117 = & V_6 ;
V_237 = (struct V_236 * ) & V_58 -> V_61 ;
V_237 -> V_62 . type = V_240 ;
V_237 -> V_241 = V_242 ;
V_112 = F_28 ( V_44 -> V_64 , V_237 ,
sizeof( struct V_236 ) ,
( unsigned long ) V_58 , V_65 ,
V_126 ) ;
if ( V_112 )
goto exit;
F_50 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
F_17 ( & V_44 -> V_45 ,
L_12 ,
V_6 . V_8 ) ;
V_112 = - V_243 ;
goto exit;
}
V_112 = 0 ;
exit:
F_29 ( V_58 ) ;
return V_112 ;
}
static void F_100 ( struct V_48 * V_25 )
{
if ( V_25 -> V_155 && V_25 -> V_168 ) {
V_25 -> V_168 -> V_23 |= V_244 ;
F_101 ( V_25 -> V_168 -> V_169 ,
F_102 ( V_25 -> V_168 ) ) ;
}
if ( V_25 -> V_156 && V_25 -> V_170 ) {
V_25 -> V_170 -> V_23 |= V_244 ;
F_101 ( V_25 -> V_170 -> V_169 ,
F_102 ( V_25 -> V_170 ) ) ;
}
}
static int F_103 ( struct V_48 * V_25 )
{
T_6 V_245 ;
int V_112 ;
if ( V_25 -> V_155 ) {
V_245 = 1ULL << ( 63 - F_60 ( V_25 -> V_155 ) ) ;
V_112 = F_104 ( & V_25 -> V_168 , V_25 -> V_44 , 0 ,
( T_5 ) ( T_1 ) 0xffffffff ,
V_25 -> V_155 ,
V_245 , false ) ;
if ( V_112 ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_13 ,
V_25 -> V_155 ) ;
return V_112 ;
}
V_25 -> V_168 -> V_23 |= V_246 ;
V_25 -> V_168 -> V_23 &= ~ V_244 ;
F_105 ( & V_25 -> V_174 ,
V_25 -> V_168 ) ;
}
if ( V_25 -> V_156 ) {
V_245 = 1ULL << ( 63 - F_60 ( V_25 -> V_156 ) ) ;
V_112 = F_104 ( & V_25 -> V_170 , V_25 -> V_44 ,
0x100000000 , - 1 ,
V_25 -> V_156 , V_245 ,
false ) ;
if ( V_112 ) {
F_17 ( & V_25 -> V_44 -> V_45 ,
L_14 ,
V_25 -> V_156 ) ;
goto V_247;
}
V_25 -> V_170 -> V_23 |= V_246 ;
V_25 -> V_170 -> V_23 &= ~ V_244 ;
F_105 ( & V_25 -> V_174 ,
V_25 -> V_170 ) ;
}
return 0 ;
V_247:
if ( V_25 -> V_168 ) {
F_101 ( V_25 -> V_168 -> V_169 ,
F_102 ( V_25 -> V_168 ) ) ;
}
return V_112 ;
}
static int F_106 ( struct V_48 * V_25 )
{
int V_112 ;
V_112 = F_104 ( & V_25 -> V_248 , V_25 -> V_44 , 0 , - 1 ,
V_249 , 0x1000 , false ) ;
if ( V_112 )
return V_112 ;
V_25 -> V_248 -> V_23 |= V_244 ;
return 0 ;
}
static void F_107 ( struct V_48 * V_25 )
{
F_101 ( V_25 -> V_248 -> V_169 , V_249 ) ;
}
static int F_108 ( struct V_235 * V_44 )
{
struct V_48 * V_25 = F_109 ( V_44 ) ;
struct V_250 * V_251 ;
struct V_5 V_6 ;
struct V_57 * V_58 ;
int V_112 ;
V_58 = F_47 ( sizeof( * V_58 ) + sizeof( * V_251 ) , V_238 ) ;
if ( ! V_58 )
return - V_239 ;
F_48 ( & V_6 . V_9 ) ;
V_58 -> V_116 = F_1 ;
V_58 -> V_117 = & V_6 ;
V_251 = (struct V_250 * ) & V_58 -> V_61 ;
V_251 -> V_62 . type = V_252 ;
V_251 -> V_253 = V_25 -> V_248 -> V_169 ;
V_112 = F_28 ( V_44 -> V_64 , V_251 , sizeof( * V_251 ) ,
( unsigned long ) V_58 , V_65 ,
V_126 ) ;
if ( V_112 )
goto exit;
F_50 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
F_17 ( & V_44 -> V_45 ,
L_15 ,
V_6 . V_8 ) ;
V_112 = - V_243 ;
goto exit;
}
V_112 = 0 ;
exit:
F_29 ( V_58 ) ;
return V_112 ;
}
static int F_110 ( struct V_235 * V_44 )
{
struct V_48 * V_25 = F_109 ( V_44 ) ;
struct V_254 V_61 ;
struct V_151 V_110 ;
int V_112 ;
F_48 ( & V_110 ) ;
if ( F_111 ( & V_25 -> V_154 , NULL , & V_110 ) )
return - V_255 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . type = V_256 ;
V_112 = F_28 ( V_44 -> V_64 , & V_61 , sizeof( V_61 ) ,
0 , V_65 , 0 ) ;
if ( V_112 )
return V_112 ;
F_50 ( & V_110 ) ;
return 0 ;
}
static int F_112 ( struct V_235 * V_44 )
{
struct V_48 * V_25 = F_109 ( V_44 ) ;
struct V_257 * V_258 ;
struct V_5 V_6 ;
struct V_18 * V_19 ;
struct V_57 * V_58 ;
T_1 V_12 ;
int V_112 ;
V_58 = F_96 ( sizeof( * V_58 ) + sizeof( * V_258 ) , V_238 ) ;
if ( ! V_58 )
return - V_239 ;
V_112 = 0 ;
for ( V_12 = 0 ; V_12 < 256 ; V_12 ++ ) {
V_19 = F_24 ( V_25 , V_12 ) ;
if ( ! V_19 )
continue;
memset ( V_58 , 0 , sizeof( * V_58 ) + sizeof( * V_258 ) ) ;
F_48 ( & V_6 . V_9 ) ;
V_58 -> V_116 = F_1 ;
V_58 -> V_117 = & V_6 ;
V_258 = (struct V_257 * ) & V_58 -> V_61 ;
V_258 -> V_62 . type = V_259 ;
V_258 -> V_12 . V_13 = V_19 -> V_30 . V_43 . V_13 ;
F_25 ( V_19 , V_51 ) ;
V_112 = F_28 (
V_44 -> V_64 , & V_58 -> V_61 ,
sizeof( * V_258 ) ,
( unsigned long ) V_58 ,
V_65 ,
V_126 ) ;
if ( V_112 )
break;
F_50 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
V_112 = - V_243 ;
F_17 ( & V_44 -> V_45 ,
L_16 ,
V_6 . V_8 ) ;
break;
}
}
F_29 ( V_58 ) ;
return V_112 ;
}
static int F_113 ( struct V_235 * V_44 )
{
struct V_48 * V_25 = F_109 ( V_44 ) ;
struct V_185 V_58 ;
struct V_18 * V_19 ;
T_1 V_12 ;
int V_112 ;
for ( V_12 = 0 ; V_12 < 256 ; V_12 ++ ) {
V_19 = F_24 ( V_25 , V_12 ) ;
if ( ! V_19 )
continue;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_62 . type = V_260 ;
V_58 . V_12 . V_13 = V_19 -> V_30 . V_43 . V_13 ;
F_25 ( V_19 , V_51 ) ;
V_112 = F_28 ( V_44 -> V_64 , & V_58 , sizeof( V_58 ) , 0 ,
V_65 , 0 ) ;
if ( V_112 )
return V_112 ;
}
return 0 ;
}
static void F_88 ( struct V_48 * V_25 )
{
F_114 ( & V_25 -> V_261 ) ;
}
static void F_80 ( struct V_48 * V_25 )
{
if ( F_115 ( & V_25 -> V_261 ) )
F_3 ( & V_25 -> V_262 ) ;
}
static int F_116 ( struct V_235 * V_44 ,
const struct V_263 * V_264 )
{
struct V_48 * V_25 ;
int V_112 ;
V_25 = F_47 ( sizeof( * V_25 ) , V_238 ) ;
if ( ! V_25 )
return - V_239 ;
V_25 -> V_176 = V_209 ;
V_25 -> V_49 . V_67 = V_44 -> V_100 . V_101 [ 9 ] |
V_44 -> V_100 . V_101 [ 8 ] << 8 ;
V_25 -> V_44 = V_44 ;
F_114 ( & V_25 -> V_261 ) ;
F_78 ( & V_25 -> V_190 ) ;
F_78 ( & V_25 -> V_204 ) ;
F_78 ( & V_25 -> V_174 ) ;
F_117 ( & V_25 -> V_42 ) ;
F_117 ( & V_25 -> V_157 ) ;
F_117 ( & V_25 -> V_91 ) ;
F_118 ( & V_25 -> V_203 , 1 ) ;
F_48 ( & V_25 -> V_262 ) ;
V_112 = F_119 ( V_44 -> V_64 , V_265 , V_265 , NULL , 0 ,
F_95 , V_25 ) ;
if ( V_112 )
goto V_266;
F_120 ( V_44 , V_25 ) ;
V_112 = F_99 ( V_44 ) ;
if ( V_112 )
goto V_267;
V_112 = F_106 ( V_25 ) ;
if ( V_112 )
goto V_267;
V_25 -> V_26 = F_121 ( V_25 -> V_248 -> V_169 ,
V_249 ) ;
if ( ! V_25 -> V_26 ) {
F_17 ( & V_44 -> V_45 ,
L_17 ) ;
V_112 = - V_239 ;
goto V_268;
}
V_25 -> V_49 . V_142 = F_122 ( V_25 ) ;
if ( ! V_25 -> V_49 . V_142 ) {
V_112 = - V_239 ;
goto V_269;
}
V_112 = F_52 ( V_25 ) ;
if ( V_112 )
goto V_270;
V_112 = F_110 ( V_44 ) ;
if ( V_112 )
goto V_271;
V_112 = F_108 ( V_44 ) ;
if ( V_112 )
goto V_271;
V_112 = F_103 ( V_25 ) ;
if ( V_112 )
goto V_271;
V_112 = F_112 ( V_44 ) ;
if ( V_112 )
goto V_272;
F_59 ( V_25 ) ;
V_25 -> V_176 = V_210 ;
V_112 = F_61 ( V_25 ) ;
if ( V_112 )
goto V_272;
return 0 ;
V_272:
F_100 ( V_25 ) ;
V_271:
F_123 ( V_25 -> V_66 ) ;
V_270:
F_124 ( V_25 -> V_49 . V_142 ) ;
V_269:
F_125 ( V_25 -> V_26 ) ;
V_268:
F_107 ( V_25 ) ;
V_267:
F_126 ( V_44 -> V_64 ) ;
V_266:
F_29 ( V_25 ) ;
return V_112 ;
}
static void F_127 ( struct V_235 * V_44 )
{
struct V_48 * V_25 = F_109 ( V_44 ) ;
struct {
struct V_57 V_273 ;
V_29 V_59 [ sizeof( struct V_254 ) ] ;
} V_58 ;
struct V_211 V_212 ;
struct V_5 V_6 ;
int V_112 ;
if ( V_44 -> V_64 -> V_274 )
return;
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
F_85 ( V_25 , & V_212 ) ;
V_112 = F_113 ( V_44 ) ;
if ( V_112 )
F_17 ( & V_44 -> V_45 ,
L_18 ) ;
memset ( & V_58 . V_273 , 0 , sizeof( V_58 . V_273 ) ) ;
F_48 ( & V_6 . V_9 ) ;
V_58 . V_273 . V_116 = F_1 ;
V_58 . V_273 . V_117 = & V_6 ;
V_58 . V_273 . V_61 [ 0 ] . type = V_275 ;
V_112 = F_28 ( V_44 -> V_64 , & V_58 . V_273 . V_61 ,
sizeof( struct V_254 ) ,
( unsigned long ) & V_58 . V_273 ,
V_65 ,
V_126 ) ;
if ( ! V_112 )
F_128 ( & V_6 . V_9 , 10 * V_276 ) ;
}
static int F_129 ( struct V_235 * V_44 )
{
struct V_48 * V_25 ;
V_25 = F_109 ( V_44 ) ;
if ( V_25 -> V_176 == V_177 ) {
F_63 () ;
F_130 ( V_25 -> V_46 ) ;
F_131 ( V_25 -> V_46 ) ;
F_67 () ;
V_25 -> V_176 = V_277 ;
}
F_127 ( V_44 ) ;
F_126 ( V_44 -> V_64 ) ;
F_125 ( V_25 -> V_26 ) ;
F_107 ( V_25 ) ;
F_132 ( & V_25 -> V_174 ) ;
F_100 ( V_25 ) ;
F_123 ( V_25 -> V_66 ) ;
F_124 ( V_25 -> V_49 . V_142 ) ;
F_80 ( V_25 ) ;
F_50 ( & V_25 -> V_262 ) ;
F_29 ( V_25 ) ;
return 0 ;
}
static void T_7 F_133 ( void )
{
F_134 ( & V_278 ) ;
}
static int T_8 F_135 ( void )
{
return F_136 ( & V_278 ) ;
}
