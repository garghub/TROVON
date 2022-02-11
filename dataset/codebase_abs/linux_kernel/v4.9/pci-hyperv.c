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
void F_36 ( struct V_72 * V_75 )
{
F_37 ( V_75 ) ;
}
void F_38 ( struct V_72 * V_75 )
{
struct V_73 * V_73 = F_32 ( V_75 ) ;
struct V_84 * V_85 = F_39 ( V_75 ) ;
struct V_86 V_87 ;
struct V_47 * V_24 ;
struct V_77 * V_78 ;
struct V_45 * V_88 ;
struct V_70 * V_71 ;
int V_89 ;
V_78 = F_40 ( V_75 ) ;
V_71 = F_33 ( V_73 ) ;
V_88 = V_71 -> V_46 ;
V_24 = F_23 ( V_88 -> V_48 , struct V_47 , V_48 ) ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_90 = V_91 ;
V_87 . V_92 = 1 ;
V_87 . V_93 = V_73 -> V_94 . V_95 ;
V_87 . V_75 = V_73 -> V_94 . V_75 ;
V_87 . V_96 = ( V_24 -> V_43 -> V_97 . V_98 [ 5 ] << 24 ) |
( V_24 -> V_43 -> V_97 . V_98 [ 4 ] << 16 ) |
( V_24 -> V_43 -> V_97 . V_98 [ 7 ] << 8 ) |
( V_24 -> V_43 -> V_97 . V_98 [ 6 ] & 0xf8 ) |
F_6 ( V_71 -> V_10 ) ;
V_87 . V_99 = V_85 -> V_99 ;
F_41 (cpu, dest, cpu_online_mask)
V_87 . V_100 |= ( 1ULL << F_42 ( V_89 ) ) ;
F_43 ( V_101 , & V_87 , NULL ) ;
F_44 ( V_75 ) ;
}
static void F_45 ( void * V_1 , struct V_2 * V_3 ,
int V_4 )
{
struct V_102 * V_6 = V_1 ;
struct V_103 * V_104 =
(struct V_103 * ) V_3 ;
V_6 -> V_6 . V_8 = V_3 -> V_7 ;
V_6 -> V_53 = V_104 -> V_53 ;
F_3 ( & V_6 -> V_6 . V_9 ) ;
}
static void F_46 ( struct V_72 * V_75 , struct V_105 * V_94 )
{
struct V_84 * V_85 = F_39 ( V_75 ) ;
struct V_47 * V_24 ;
struct V_17 * V_18 ;
struct V_45 * V_88 ;
struct V_70 * V_71 ;
struct V_106 * V_55 ;
struct V_102 V_107 ;
struct V_52 * V_53 ;
struct V_77 * V_108 ;
struct {
struct V_56 V_57 ;
V_28 V_58 [ sizeof( struct V_106 ) ] ;
} V_59 ;
int V_89 ;
int V_109 ;
V_71 = F_33 ( F_32 ( V_75 ) ) ;
V_88 = V_71 -> V_46 ;
V_24 = F_23 ( V_88 -> V_48 , struct V_47 , V_48 ) ;
V_18 = F_24 ( V_24 , F_4 ( V_71 -> V_10 ) ) ;
if ( ! V_18 )
goto V_110;
if ( V_75 -> V_76 ) {
V_53 = V_75 -> V_76 ;
V_75 -> V_76 = NULL ;
F_27 ( V_18 , V_53 ) ;
}
V_53 = F_47 ( sizeof( * V_53 ) , V_111 ) ;
if ( ! V_53 )
goto V_112;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
F_48 ( & V_107 . V_6 . V_9 ) ;
V_59 . V_57 . V_113 = F_45 ;
V_59 . V_57 . V_114 = & V_107 ;
V_55 = (struct V_106 * ) & V_59 . V_57 . V_60 ;
V_55 -> V_61 . type = V_115 ;
V_55 -> V_12 . V_13 = V_18 -> V_29 . V_42 . V_13 ;
V_55 -> V_53 . V_99 = V_85 -> V_99 ;
V_55 -> V_53 . V_116 = 1 ;
V_55 -> V_53 . V_117 =
( V_118 -> V_119 == V_120 ) ? 1 : 0 ;
V_108 = F_40 ( V_75 ) ;
F_41 (cpu, affinity, cpu_online_mask) {
V_55 -> V_53 . V_121 |=
( 1ULL << F_42 ( V_89 ) ) ;
}
V_109 = F_28 ( V_18 -> V_24 -> V_43 -> V_63 , V_55 ,
sizeof( * V_55 ) , ( unsigned long ) & V_59 . V_57 ,
V_64 ,
V_122 ) ;
if ( V_109 )
goto V_123;
F_49 ( & V_107 . V_6 . V_9 ) ;
if ( V_107 . V_6 . V_8 < 0 ) {
F_17 ( & V_24 -> V_43 -> V_44 ,
L_3 ,
V_107 . V_6 . V_8 ) ;
goto V_123;
}
* V_53 = V_107 . V_53 ;
V_75 -> V_76 = V_53 ;
V_94 -> V_124 = V_107 . V_53 . V_93 >> 32 ;
V_94 -> V_95 = V_107 . V_53 . V_93 & 0xffffffff ;
V_94 -> V_75 = V_107 . V_53 . V_75 ;
F_25 ( V_18 , V_50 ) ;
return;
V_123:
F_29 ( V_53 ) ;
V_112:
F_25 ( V_18 , V_50 ) ;
V_110:
V_94 -> V_124 = 0 ;
V_94 -> V_95 = 0 ;
V_94 -> V_75 = 0 ;
}
static T_3 F_50 ( struct V_67 * V_68 ,
T_4 * V_125 )
{
return V_125 -> V_126 ;
}
static int F_51 ( struct V_47 * V_24 )
{
V_24 -> V_127 . V_82 = & V_128 ;
V_24 -> V_127 . V_129 = & V_130 ;
V_24 -> V_127 . V_22 = ( V_131 |
V_132 | V_133 |
V_134 ) ;
V_24 -> V_127 . V_135 = V_136 ;
V_24 -> V_127 . V_137 = L_4 ;
V_24 -> V_127 . V_75 = V_24 ;
V_24 -> V_65 = F_52 ( V_24 -> V_48 . V_138 ,
& V_24 -> V_127 ,
V_139 ) ;
if ( ! V_24 -> V_65 ) {
F_17 ( & V_24 -> V_43 -> V_44 ,
L_5 ) ;
return - V_140 ;
}
return 0 ;
}
static T_5 F_53 ( T_5 V_141 )
{
return F_54 ( ( 1 + ~ ( V_141 & V_142 ) ) ,
V_143 ) ;
}
static void F_55 ( struct V_47 * V_24 )
{
struct V_144 * V_145 ;
struct V_17 * V_18 ;
T_6 V_146 = 0 ;
unsigned long V_22 ;
struct V_147 * V_148 ;
T_5 V_141 ;
int V_149 ;
V_148 = F_56 ( & V_24 -> V_150 , NULL ) ;
if ( ! V_148 )
return;
if ( V_24 -> V_151 || V_24 -> V_152 ) {
F_3 ( V_148 ) ;
return;
}
F_10 ( & V_24 -> V_153 , V_22 ) ;
F_57 (iter, &hbus->children) {
V_18 = F_23 ( V_145 , struct V_17 , V_154 ) ;
for ( V_149 = 0 ; V_149 < 6 ; V_149 ++ ) {
if ( V_18 -> V_155 [ V_149 ] & V_156 )
F_17 ( & V_24 -> V_43 -> V_44 ,
L_6 ) ;
if ( V_18 -> V_155 [ V_149 ] != 0 ) {
V_141 = V_18 -> V_155 [ V_149 ] ;
if ( V_141 & V_157 )
V_141 |=
( ( T_5 ) V_18 -> V_155 [ ++ V_149 ] << 32 ) ;
else
V_141 |= 0xffffffff00000000ULL ;
V_146 = F_53 ( V_141 ) ;
if ( V_141 & V_157 )
V_24 -> V_152 += V_146 ;
else
V_24 -> V_151 += V_146 ;
}
}
}
F_16 ( & V_24 -> V_153 , V_22 ) ;
F_3 ( V_148 ) ;
}
static void F_58 ( struct V_47 * V_24 )
{
T_6 V_158 = 0 ;
T_6 V_159 = 0 ;
T_6 V_160 = 0 ;
T_6 V_161 = 0 ;
T_6 V_146 ;
struct V_17 * V_18 ;
struct V_144 * V_145 ;
unsigned long V_22 ;
T_5 V_141 ;
T_1 V_162 ;
bool V_163 ;
int V_149 ;
if ( V_24 -> V_151 ) {
V_159 = 1ULL << ( 63 - F_59 ( V_24 -> V_151 ) ) ;
V_161 = V_24 -> V_164 -> V_165 ;
}
if ( V_24 -> V_152 ) {
V_158 = 1ULL <<
( 63 - F_59 ( V_24 -> V_152 ) ) ;
V_160 = V_24 -> V_166 -> V_165 ;
}
F_10 ( & V_24 -> V_153 , V_22 ) ;
do {
F_57 (iter, &hbus->children) {
V_18 = F_23 ( V_145 , struct V_17 ,
V_154 ) ;
for ( V_149 = 0 ; V_149 < 6 ; V_149 ++ ) {
V_141 = V_18 -> V_155 [ V_149 ] ;
if ( V_141 == 0 )
continue;
V_163 = V_141 & V_157 ;
if ( V_163 ) {
V_141 |=
( ( T_5 ) V_18 -> V_155 [ V_149 + 1 ]
<< 32 ) ;
} else {
V_141 |= 0xffffffffULL << 32 ;
}
V_146 = F_53 ( V_141 ) ;
if ( V_163 ) {
if ( V_158 != V_146 ) {
V_149 ++ ;
continue;
}
F_18 ( V_18 ,
V_167 + ( 4 * V_149 ) ,
4 ,
( T_1 ) ( V_160 & 0xffffff00 ) ) ;
V_149 ++ ;
F_18 ( V_18 ,
V_167 + ( 4 * V_149 ) ,
4 , ( T_1 ) ( V_160 >> 32 ) ) ;
V_160 += V_146 ;
} else {
if ( V_159 != V_146 )
continue;
F_18 ( V_18 ,
V_167 + ( 4 * V_149 ) ,
4 ,
( T_1 ) ( V_161 & 0xffffff00 ) ) ;
V_161 += V_146 ;
}
}
if ( V_158 <= 1 && V_159 <= 1 ) {
F_9 ( V_18 , V_27 , 2 ,
& V_162 ) ;
V_162 |= V_168 ;
F_18 ( V_18 , V_27 , 2 ,
V_162 ) ;
break;
}
}
V_158 >>= 1 ;
V_159 >>= 1 ;
} while ( V_158 || V_159 );
F_16 ( & V_24 -> V_153 , V_22 ) ;
}
static int F_60 ( struct V_47 * V_24 )
{
V_24 -> V_45 = F_61 ( & V_24 -> V_43 -> V_44 ,
0 ,
& V_169 ,
& V_24 -> V_48 ,
& V_24 -> V_170 ) ;
if ( ! V_24 -> V_45 )
return - V_140 ;
V_24 -> V_45 -> V_74 = & V_24 -> V_171 ;
V_24 -> V_45 -> V_74 -> V_172 = & V_24 -> V_43 -> V_44 ;
F_62 ( V_24 -> V_45 ) ;
F_63 ( V_24 -> V_45 ) ;
F_64 ( V_24 -> V_45 ) ;
V_24 -> V_173 = V_174 ;
return 0 ;
}
static void F_65 ( void * V_1 , struct V_2 * V_3 ,
int V_4 )
{
struct V_175 * V_147 = V_1 ;
struct V_176 * V_177 =
(struct V_176 * ) V_3 ;
int V_149 ;
if ( V_3 -> V_7 < 0 ) {
F_17 ( & V_147 -> V_18 -> V_24 -> V_43 -> V_44 ,
L_7 ,
V_3 -> V_7 ) ;
} else {
for ( V_149 = 0 ; V_149 < 6 ; V_149 ++ ) {
V_147 -> V_18 -> V_155 [ V_149 ] =
V_177 -> V_155 [ V_149 ] ;
}
}
F_3 ( & V_147 -> V_9 ) ;
}
static void F_66 ( struct V_17 * V_18 ,
enum V_178 V_179 )
{
F_67 ( & V_18 -> V_180 ) ;
}
static void F_25 ( struct V_17 * V_18 ,
enum V_178 V_179 )
{
if ( F_68 ( & V_18 -> V_180 ) )
F_29 ( V_18 ) ;
}
static struct V_17 * F_69 ( struct V_47 * V_24 ,
struct V_181 * V_29 )
{
struct V_17 * V_18 ;
struct V_182 * V_183 ;
struct V_175 V_6 ;
union {
struct V_56 V_184 ;
V_28 V_58 [ 0x100 ] ;
} V_57 ;
unsigned long V_22 ;
int V_109 ;
V_18 = F_47 ( sizeof( * V_18 ) , V_185 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_24 = V_24 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
F_48 ( & V_6 . V_9 ) ;
V_6 . V_18 = V_18 ;
V_57 . V_184 . V_114 = & V_6 ;
V_57 . V_184 . V_113 = F_65 ;
V_183 = (struct V_182 * ) & V_57 . V_184 . V_60 ;
V_183 -> V_61 . type = V_186 ;
V_183 -> V_12 . V_13 = V_29 -> V_42 . V_13 ;
V_109 = F_28 ( V_24 -> V_43 -> V_63 , V_183 ,
sizeof( struct V_182 ) ,
( unsigned long ) & V_57 . V_184 ,
V_64 ,
V_122 ) ;
if ( V_109 )
goto error;
F_49 ( & V_6 . V_9 ) ;
V_18 -> V_29 = * V_29 ;
F_66 ( V_18 , V_187 ) ;
F_66 ( V_18 , V_188 ) ;
F_10 ( & V_24 -> V_153 , V_22 ) ;
F_70 ( & V_18 -> V_154 , & V_24 -> V_189 ) ;
F_16 ( & V_24 -> V_153 , V_22 ) ;
return V_18 ;
error:
F_29 ( V_18 ) ;
return NULL ;
}
static struct V_17 * F_24 ( struct V_47 * V_24 ,
T_1 V_12 )
{
unsigned long V_22 ;
struct V_17 * V_145 , * V_18 = NULL ;
F_10 ( & V_24 -> V_153 , V_22 ) ;
F_71 (iter, &hbus->children, list_entry) {
if ( V_145 -> V_29 . V_42 . V_13 == V_12 ) {
V_18 = V_145 ;
F_66 ( V_18 , V_50 ) ;
break;
}
}
F_16 ( & V_24 -> V_153 , V_22 ) ;
return V_18 ;
}
static void F_72 ( struct V_190 * V_191 )
{
T_1 V_192 ;
bool V_193 ;
struct V_144 * V_145 ;
struct V_181 * V_194 ;
struct V_17 * V_18 ;
struct V_47 * V_24 ;
struct V_144 V_195 ;
struct V_196 * V_197 ;
struct V_198 * V_199 = NULL ;
unsigned long V_22 ;
V_197 = F_23 ( V_191 , struct V_196 , V_200 ) ;
V_24 = V_197 -> V_46 ;
F_29 ( V_197 ) ;
F_73 ( & V_195 ) ;
if ( F_74 ( & V_24 -> V_201 ) ) {
F_75 ( V_24 ) ;
return;
}
F_10 ( & V_24 -> V_153 , V_22 ) ;
while ( ! F_76 ( & V_24 -> V_202 ) ) {
V_199 = F_77 ( & V_24 -> V_202 , struct V_198 ,
V_154 ) ;
F_78 ( & V_199 -> V_154 ) ;
if ( ! F_76 ( & V_24 -> V_202 ) ) {
F_29 ( V_199 ) ;
continue;
}
}
F_16 ( & V_24 -> V_153 , V_22 ) ;
if ( ! V_199 ) {
F_79 ( & V_24 -> V_201 ) ;
F_75 ( V_24 ) ;
return;
}
F_10 ( & V_24 -> V_153 , V_22 ) ;
F_57 (iter, &hbus->children) {
V_18 = F_23 ( V_145 , struct V_17 ,
V_154 ) ;
V_18 -> V_203 = true ;
}
F_16 ( & V_24 -> V_153 , V_22 ) ;
for ( V_192 = 0 ; V_192 < V_199 -> V_204 ; V_192 ++ ) {
V_193 = false ;
V_194 = & V_199 -> V_15 [ V_192 ] ;
F_10 ( & V_24 -> V_153 , V_22 ) ;
F_57 (iter, &hbus->children) {
V_18 = F_23 ( V_145 , struct V_17 ,
V_154 ) ;
if ( ( V_18 -> V_29 . V_42 . V_13 ==
V_194 -> V_42 . V_13 ) &&
( V_18 -> V_29 . V_30 == V_194 -> V_30 ) &&
( V_18 -> V_29 . V_205 == V_194 -> V_205 ) &&
( V_18 -> V_29 . V_206 == V_194 -> V_206 ) ) {
V_18 -> V_203 = false ;
V_193 = true ;
}
}
F_16 ( & V_24 -> V_153 , V_22 ) ;
if ( ! V_193 ) {
V_18 = F_69 ( V_24 , V_194 ) ;
if ( ! V_18 )
F_17 ( & V_24 -> V_43 -> V_44 ,
L_8 ) ;
}
}
F_10 ( & V_24 -> V_153 , V_22 ) ;
do {
V_193 = false ;
F_57 (iter, &hbus->children) {
V_18 = F_23 ( V_145 , struct V_17 ,
V_154 ) ;
if ( V_18 -> V_203 ) {
V_193 = true ;
F_25 ( V_18 , V_188 ) ;
F_80 ( & V_18 -> V_154 , & V_195 ) ;
break;
}
}
} while ( V_193 );
F_16 ( & V_24 -> V_153 , V_22 ) ;
while ( ! F_76 ( & V_195 ) ) {
V_18 = F_77 ( & V_195 , struct V_17 ,
V_154 ) ;
F_78 ( & V_18 -> V_154 ) ;
F_25 ( V_18 , V_187 ) ;
}
if ( V_24 -> V_173 == V_174 ) {
F_81 () ;
F_62 ( V_24 -> V_45 ) ;
F_82 () ;
} else {
F_55 ( V_24 ) ;
}
F_79 ( & V_24 -> V_201 ) ;
F_75 ( V_24 ) ;
F_29 ( V_199 ) ;
}
static void F_83 ( struct V_47 * V_24 ,
struct V_207 * V_208 )
{
struct V_198 * V_199 ;
struct V_196 * V_197 ;
unsigned long V_22 ;
V_197 = F_47 ( sizeof( * V_197 ) , V_209 ) ;
if ( ! V_197 )
return;
V_199 = F_47 ( F_84 ( struct V_198 , V_15 ) +
( sizeof( struct V_181 ) *
( V_208 -> V_204 ) ) , V_209 ) ;
if ( ! V_199 ) {
F_29 ( V_197 ) ;
return;
}
F_85 ( & V_197 -> V_200 , F_72 ) ;
V_197 -> V_46 = V_24 ;
V_199 -> V_204 = V_208 -> V_204 ;
if ( V_199 -> V_204 != 0 ) {
memcpy ( V_199 -> V_15 , V_208 -> V_15 ,
sizeof( struct V_181 ) *
V_199 -> V_204 ) ;
}
F_10 ( & V_24 -> V_153 , V_22 ) ;
F_70 ( & V_199 -> V_154 , & V_24 -> V_202 ) ;
F_16 ( & V_24 -> V_153 , V_22 ) ;
F_86 ( V_24 ) ;
F_87 ( & V_197 -> V_200 ) ;
}
static void F_88 ( struct V_190 * V_191 )
{
struct V_210 * V_211 ;
struct V_17 * V_18 ;
struct V_70 * V_71 ;
unsigned long V_22 ;
int V_12 ;
struct {
struct V_56 V_57 ;
V_28 V_58 [ sizeof( struct V_210 ) ] ;
} V_59 ;
V_18 = F_23 ( V_191 , struct V_17 , V_200 ) ;
if ( V_18 -> V_173 != V_212 ) {
F_25 ( V_18 , V_213 ) ;
return;
}
V_12 = F_7 ( V_18 -> V_29 . V_42 . V_13 ) ;
V_71 = F_89 ( V_18 -> V_24 -> V_48 . V_66 , 0 ,
V_12 ) ;
if ( V_71 ) {
F_90 ( V_71 ) ;
F_91 ( V_71 ) ;
}
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_211 = (struct V_210 * ) & V_59 . V_57 . V_60 ;
V_211 -> V_61 . type = V_214 ;
V_211 -> V_12 . V_13 = V_18 -> V_29 . V_42 . V_13 ;
F_28 ( V_18 -> V_24 -> V_43 -> V_63 , V_211 ,
sizeof( * V_211 ) , ( unsigned long ) & V_59 . V_57 ,
V_64 , 0 ) ;
F_10 ( & V_18 -> V_24 -> V_153 , V_22 ) ;
F_78 ( & V_18 -> V_154 ) ;
F_16 ( & V_18 -> V_24 -> V_153 , V_22 ) ;
F_25 ( V_18 , V_188 ) ;
F_25 ( V_18 , V_213 ) ;
F_75 ( V_18 -> V_24 ) ;
}
static void F_92 ( struct V_17 * V_18 )
{
V_18 -> V_173 = V_212 ;
F_66 ( V_18 , V_213 ) ;
F_85 ( & V_18 -> V_200 , F_88 ) ;
F_86 ( V_18 -> V_24 ) ;
F_87 ( & V_18 -> V_200 ) ;
}
static void F_93 ( void * V_1 )
{
const int V_215 = 0x100 ;
int V_109 ;
struct V_47 * V_24 = V_1 ;
T_1 V_216 ;
T_5 V_217 ;
struct V_218 * V_29 ;
unsigned char * V_58 ;
int V_219 = V_215 ;
struct V_56 * V_220 ;
struct V_2 * V_221 ;
struct V_222 * V_223 ;
struct V_207 * V_224 ;
struct V_225 * V_226 ;
struct V_17 * V_18 ;
V_58 = F_94 ( V_219 , V_185 ) ;
if ( ! V_58 )
return;
while ( 1 ) {
V_109 = F_95 ( V_24 -> V_43 -> V_63 , V_58 ,
V_219 , & V_216 , & V_217 ) ;
if ( V_109 == - V_227 ) {
F_29 ( V_58 ) ;
V_219 = V_216 ;
V_58 = F_94 ( V_216 , V_185 ) ;
if ( ! V_58 )
return;
continue;
}
if ( V_109 || ! V_216 )
break;
if ( V_216 <= sizeof( struct V_2 ) )
continue;
V_29 = (struct V_218 * ) V_58 ;
switch ( V_29 -> type ) {
case V_228 :
V_220 = (struct V_56 * ) V_217 ;
V_221 = (struct V_2 * ) V_58 ;
V_220 -> V_113 ( V_220 -> V_114 ,
V_221 ,
V_216 ) ;
break;
case V_64 :
V_223 = (struct V_222 * ) V_58 ;
switch ( V_223 -> V_61 . type ) {
case V_229 :
V_224 = (struct V_207 * ) V_58 ;
if ( V_216 <
F_84 ( struct V_207 , V_15 ) +
( sizeof( struct V_181 ) *
( V_224 -> V_204 ) ) ) {
F_17 ( & V_24 -> V_43 -> V_44 ,
L_9 ) ;
break;
}
F_83 ( V_24 , V_224 ) ;
break;
case V_230 :
V_226 = (struct V_225 * ) V_58 ;
V_18 = F_24 ( V_24 ,
V_226 -> V_12 . V_13 ) ;
if ( V_18 ) {
F_92 ( V_18 ) ;
F_25 ( V_18 ,
V_50 ) ;
}
break;
default:
F_96 ( & V_24 -> V_43 -> V_44 ,
L_10 ,
V_223 -> V_61 . type ) ;
break;
}
break;
default:
F_17 ( & V_24 -> V_43 -> V_44 ,
L_11 ,
V_29 -> type , V_217 , V_216 ) ;
break;
}
}
F_29 ( V_58 ) ;
}
static int F_97 ( struct V_231 * V_43 )
{
struct V_232 * V_233 ;
struct V_5 V_6 ;
struct V_56 * V_57 ;
int V_109 ;
V_57 = F_47 ( sizeof( * V_57 ) + sizeof( * V_233 ) , V_111 ) ;
if ( ! V_57 )
return - V_234 ;
F_48 ( & V_6 . V_9 ) ;
V_57 -> V_113 = F_1 ;
V_57 -> V_114 = & V_6 ;
V_233 = (struct V_232 * ) & V_57 -> V_60 ;
V_233 -> V_61 . type = V_235 ;
V_233 -> V_236 = V_237 ;
V_109 = F_28 ( V_43 -> V_63 , V_233 ,
sizeof( struct V_232 ) ,
( unsigned long ) V_57 , V_64 ,
V_122 ) ;
if ( V_109 )
goto exit;
F_49 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
F_17 ( & V_43 -> V_44 ,
L_12 ,
V_6 . V_8 ) ;
V_109 = - V_238 ;
goto exit;
}
V_109 = 0 ;
exit:
F_29 ( V_57 ) ;
return V_109 ;
}
static void F_98 ( struct V_47 * V_24 )
{
if ( V_24 -> V_151 && V_24 -> V_164 ) {
V_24 -> V_164 -> V_22 |= V_239 ;
F_99 ( V_24 -> V_164 -> V_165 ,
F_100 ( V_24 -> V_164 ) ) ;
}
if ( V_24 -> V_152 && V_24 -> V_166 ) {
V_24 -> V_166 -> V_22 |= V_239 ;
F_99 ( V_24 -> V_166 -> V_165 ,
F_100 ( V_24 -> V_166 ) ) ;
}
}
static int F_101 ( struct V_47 * V_24 )
{
T_6 V_240 ;
int V_109 ;
if ( V_24 -> V_151 ) {
V_240 = 1ULL << ( 63 - F_59 ( V_24 -> V_151 ) ) ;
V_109 = F_102 ( & V_24 -> V_164 , V_24 -> V_43 , 0 ,
( T_5 ) ( T_1 ) 0xffffffff ,
V_24 -> V_151 ,
V_240 , false ) ;
if ( V_109 ) {
F_17 ( & V_24 -> V_43 -> V_44 ,
L_13 ,
V_24 -> V_151 ) ;
return V_109 ;
}
V_24 -> V_164 -> V_22 |= V_241 ;
V_24 -> V_164 -> V_22 &= ~ V_239 ;
F_103 ( & V_24 -> V_170 ,
V_24 -> V_164 ) ;
}
if ( V_24 -> V_152 ) {
V_240 = 1ULL << ( 63 - F_59 ( V_24 -> V_152 ) ) ;
V_109 = F_102 ( & V_24 -> V_166 , V_24 -> V_43 ,
0x100000000 , - 1 ,
V_24 -> V_152 , V_240 ,
false ) ;
if ( V_109 ) {
F_17 ( & V_24 -> V_43 -> V_44 ,
L_14 ,
V_24 -> V_152 ) ;
goto V_242;
}
V_24 -> V_166 -> V_22 |= V_241 ;
V_24 -> V_166 -> V_22 &= ~ V_239 ;
F_103 ( & V_24 -> V_170 ,
V_24 -> V_166 ) ;
}
return 0 ;
V_242:
if ( V_24 -> V_164 ) {
F_99 ( V_24 -> V_164 -> V_165 ,
F_100 ( V_24 -> V_164 ) ) ;
}
return V_109 ;
}
static int F_104 ( struct V_47 * V_24 )
{
int V_109 ;
V_109 = F_102 ( & V_24 -> V_243 , V_24 -> V_43 , 0 , - 1 ,
V_244 , 0x1000 , false ) ;
if ( V_109 )
return V_109 ;
V_24 -> V_243 -> V_22 |= V_239 ;
return 0 ;
}
static void F_105 ( struct V_47 * V_24 )
{
F_99 ( V_24 -> V_243 -> V_165 , V_244 ) ;
}
static int F_106 ( struct V_231 * V_43 )
{
struct V_47 * V_24 = F_107 ( V_43 ) ;
struct V_245 * V_246 ;
struct V_5 V_6 ;
struct V_56 * V_57 ;
int V_109 ;
V_57 = F_47 ( sizeof( * V_57 ) + sizeof( * V_246 ) , V_111 ) ;
if ( ! V_57 )
return - V_234 ;
F_48 ( & V_6 . V_9 ) ;
V_57 -> V_113 = F_1 ;
V_57 -> V_114 = & V_6 ;
V_246 = (struct V_245 * ) & V_57 -> V_60 ;
V_246 -> V_61 . type = V_247 ;
V_246 -> V_248 = V_24 -> V_243 -> V_165 ;
V_109 = F_28 ( V_43 -> V_63 , V_246 , sizeof( * V_246 ) ,
( unsigned long ) V_57 , V_64 ,
V_122 ) ;
if ( V_109 )
goto exit;
F_49 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
F_17 ( & V_43 -> V_44 ,
L_15 ,
V_6 . V_8 ) ;
V_109 = - V_238 ;
goto exit;
}
V_109 = 0 ;
exit:
F_29 ( V_57 ) ;
return V_109 ;
}
static int F_108 ( struct V_231 * V_43 )
{
struct V_47 * V_24 = F_107 ( V_43 ) ;
struct V_249 V_60 ;
struct V_147 V_107 ;
int V_109 ;
F_48 ( & V_107 ) ;
if ( F_109 ( & V_24 -> V_150 , NULL , & V_107 ) )
return - V_250 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . type = V_251 ;
V_109 = F_28 ( V_43 -> V_63 , & V_60 , sizeof( V_60 ) ,
0 , V_64 , 0 ) ;
if ( V_109 )
return V_109 ;
F_49 ( & V_107 ) ;
return 0 ;
}
static int F_110 ( struct V_231 * V_43 )
{
struct V_47 * V_24 = F_107 ( V_43 ) ;
struct V_252 * V_253 ;
struct V_5 V_6 ;
struct V_17 * V_18 ;
struct V_56 * V_57 ;
T_1 V_12 ;
int V_109 ;
V_57 = F_94 ( sizeof( * V_57 ) + sizeof( * V_253 ) , V_111 ) ;
if ( ! V_57 )
return - V_234 ;
V_109 = 0 ;
for ( V_12 = 0 ; V_12 < 256 ; V_12 ++ ) {
V_18 = F_24 ( V_24 , V_12 ) ;
if ( ! V_18 )
continue;
memset ( V_57 , 0 , sizeof( * V_57 ) + sizeof( * V_253 ) ) ;
F_48 ( & V_6 . V_9 ) ;
V_57 -> V_113 = F_1 ;
V_57 -> V_114 = & V_6 ;
V_253 = (struct V_252 * ) & V_57 -> V_60 ;
V_253 -> V_61 . type = V_254 ;
V_253 -> V_12 . V_13 = V_18 -> V_29 . V_42 . V_13 ;
F_25 ( V_18 , V_50 ) ;
V_109 = F_28 (
V_43 -> V_63 , & V_57 -> V_60 ,
sizeof( * V_253 ) ,
( unsigned long ) V_57 ,
V_64 ,
V_122 ) ;
if ( V_109 )
break;
F_49 ( & V_6 . V_9 ) ;
if ( V_6 . V_8 < 0 ) {
V_109 = - V_238 ;
F_17 ( & V_43 -> V_44 ,
L_16 ,
V_6 . V_8 ) ;
break;
}
}
F_29 ( V_57 ) ;
return V_109 ;
}
static int F_111 ( struct V_231 * V_43 )
{
struct V_47 * V_24 = F_107 ( V_43 ) ;
struct V_182 V_57 ;
struct V_17 * V_18 ;
T_1 V_12 ;
int V_109 ;
for ( V_12 = 0 ; V_12 < 256 ; V_12 ++ ) {
V_18 = F_24 ( V_24 , V_12 ) ;
if ( ! V_18 )
continue;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_61 . type = V_255 ;
V_57 . V_12 . V_13 = V_18 -> V_29 . V_42 . V_13 ;
F_25 ( V_18 , V_50 ) ;
V_109 = F_28 ( V_43 -> V_63 , & V_57 , sizeof( V_57 ) , 0 ,
V_64 , 0 ) ;
if ( V_109 )
return V_109 ;
}
return 0 ;
}
static void F_86 ( struct V_47 * V_24 )
{
F_67 ( & V_24 -> V_256 ) ;
}
static void F_75 ( struct V_47 * V_24 )
{
if ( F_68 ( & V_24 -> V_256 ) )
F_3 ( & V_24 -> V_257 ) ;
}
static int F_112 ( struct V_231 * V_43 ,
const struct V_258 * V_259 )
{
struct V_47 * V_24 ;
int V_109 ;
V_24 = F_47 ( sizeof( * V_24 ) , V_111 ) ;
if ( ! V_24 )
return - V_234 ;
V_24 -> V_48 . V_66 = V_43 -> V_97 . V_98 [ 9 ] |
V_43 -> V_97 . V_98 [ 8 ] << 8 ;
V_24 -> V_43 = V_43 ;
F_67 ( & V_24 -> V_256 ) ;
F_73 ( & V_24 -> V_189 ) ;
F_73 ( & V_24 -> V_202 ) ;
F_73 ( & V_24 -> V_170 ) ;
F_113 ( & V_24 -> V_41 ) ;
F_113 ( & V_24 -> V_153 ) ;
F_114 ( & V_24 -> V_201 , 1 ) ;
F_48 ( & V_24 -> V_257 ) ;
V_109 = F_115 ( V_43 -> V_63 , V_260 , V_260 , NULL , 0 ,
F_93 , V_24 ) ;
if ( V_109 )
goto V_261;
F_116 ( V_43 , V_24 ) ;
V_109 = F_97 ( V_43 ) ;
if ( V_109 )
goto V_262;
V_109 = F_104 ( V_24 ) ;
if ( V_109 )
goto V_262;
V_24 -> V_25 = F_117 ( V_24 -> V_243 -> V_165 ,
V_244 ) ;
if ( ! V_24 -> V_25 ) {
F_17 ( & V_43 -> V_44 ,
L_17 ) ;
V_109 = - V_234 ;
goto V_263;
}
V_24 -> V_48 . V_138 = F_118 ( V_24 ) ;
if ( ! V_24 -> V_48 . V_138 ) {
V_109 = - V_234 ;
goto V_264;
}
V_109 = F_51 ( V_24 ) ;
if ( V_109 )
goto V_265;
V_109 = F_108 ( V_43 ) ;
if ( V_109 )
goto V_266;
V_109 = F_106 ( V_43 ) ;
if ( V_109 )
goto V_266;
V_109 = F_101 ( V_24 ) ;
if ( V_109 )
goto V_266;
V_109 = F_110 ( V_43 ) ;
if ( V_109 )
goto V_267;
F_58 ( V_24 ) ;
V_24 -> V_173 = V_268 ;
V_109 = F_60 ( V_24 ) ;
if ( V_109 )
goto V_267;
return 0 ;
V_267:
F_98 ( V_24 ) ;
V_266:
F_119 ( V_24 -> V_65 ) ;
V_265:
F_120 ( V_24 -> V_48 . V_138 ) ;
V_264:
F_121 ( V_24 -> V_25 ) ;
V_263:
F_105 ( V_24 ) ;
V_262:
F_122 ( V_43 -> V_63 ) ;
V_261:
F_29 ( V_24 ) ;
return V_109 ;
}
static int F_123 ( struct V_231 * V_43 )
{
int V_109 ;
struct V_47 * V_24 ;
union {
struct V_56 V_269 ;
V_28 V_58 [ 0x100 ] ;
} V_57 ;
struct V_207 V_208 ;
struct V_5 V_6 ;
V_24 = F_107 ( V_43 ) ;
memset ( & V_57 . V_269 , 0 , sizeof( V_57 . V_269 ) ) ;
F_48 ( & V_6 . V_9 ) ;
V_57 . V_269 . V_113 = F_1 ;
V_57 . V_269 . V_114 = & V_6 ;
V_57 . V_269 . V_60 [ 0 ] . type = V_270 ;
V_109 = F_28 ( V_43 -> V_63 , & V_57 . V_269 . V_60 ,
sizeof( struct V_249 ) ,
( unsigned long ) & V_57 . V_269 ,
V_64 ,
V_122 ) ;
if ( ! V_109 )
F_124 ( & V_6 . V_9 , 10 * V_271 ) ;
if ( V_24 -> V_173 == V_174 ) {
F_81 () ;
F_125 ( V_24 -> V_45 ) ;
F_126 ( V_24 -> V_45 ) ;
F_82 () ;
}
V_109 = F_111 ( V_43 ) ;
if ( V_109 )
F_17 ( & V_43 -> V_44 ,
L_18 ) ;
F_122 ( V_43 -> V_63 ) ;
memset ( & V_208 , 0 , sizeof( V_208 ) ) ;
F_83 ( V_24 , & V_208 ) ;
F_121 ( V_24 -> V_25 ) ;
F_105 ( V_24 ) ;
F_127 ( & V_24 -> V_170 ) ;
F_98 ( V_24 ) ;
F_119 ( V_24 -> V_65 ) ;
F_120 ( V_24 -> V_48 . V_138 ) ;
F_75 ( V_24 ) ;
F_49 ( & V_24 -> V_257 ) ;
F_29 ( V_24 ) ;
return 0 ;
}
static void T_7 F_128 ( void )
{
F_129 ( & V_272 ) ;
}
static int T_8 F_130 ( void )
{
return F_131 ( & V_272 ) ;
}
