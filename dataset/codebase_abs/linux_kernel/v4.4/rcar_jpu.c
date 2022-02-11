static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_3 ) ;
return F_2 ( V_5 , struct V_1 , V_6 ) ;
}
static T_1 F_3 ( struct V_7 * V_7 , unsigned int V_8 )
{
return F_4 ( V_7 -> V_9 + V_8 ) ;
}
static void F_5 ( struct V_7 * V_7 , T_1 V_10 , unsigned int V_8 )
{
F_6 ( V_10 , V_7 -> V_9 + V_8 ) ;
}
static struct V_11 * F_7 ( struct V_12 * V_13 )
{
return F_2 ( V_13 -> V_14 , struct V_11 , V_15 ) ;
}
static struct V_11 * F_8 ( struct V_16 * V_17 )
{
return F_2 ( V_17 , struct V_11 , V_17 ) ;
}
static void F_9 ( struct V_7 * V_7 , T_1 V_8 , const unsigned int * V_18 ,
unsigned int V_19 ) {
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ )
F_5 ( V_7 , V_18 [ V_20 ] , V_8 + ( V_20 << 2 ) ) ;
}
static void F_10 ( struct V_7 * V_7 , unsigned short V_21 )
{
F_9 ( V_7 , F_11 ( 0 ) , V_22 [ V_21 ] , V_23 ) ;
F_9 ( V_7 , F_11 ( 1 ) , V_24 [ V_21 ] , V_23 ) ;
}
static void F_12 ( struct V_7 * V_7 )
{
F_9 ( V_7 , F_13 ( 0 ) , V_25 , V_26 ) ;
F_9 ( V_7 , F_14 ( 0 ) , V_27 , V_28 ) ;
F_9 ( V_7 , F_13 ( 1 ) , V_29 , V_26 ) ;
F_9 ( V_7 , F_14 ( 1 ) , V_30 , V_28 ) ;
}
static int F_15 ( struct V_7 * V_7 )
{
unsigned long V_31 ;
V_31 = V_32 + F_16 ( V_33 ) ;
while ( F_3 ( V_7 , V_34 ) & V_35 ) {
if ( F_17 ( V_32 , V_31 ) ) {
F_18 ( V_7 -> V_36 , L_1 ) ;
return - V_37 ;
}
F_19 () ;
}
return 0 ;
}
static int F_20 ( struct V_7 * V_7 )
{
F_5 ( V_7 , V_35 , V_34 ) ;
return F_15 ( V_7 ) ;
}
static void F_21 ( T_2 * V_38 , const T_2 * V_39 )
{
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < F_22 ( V_40 ) ; V_20 ++ )
V_38 [ V_20 ] = * ( V_39 + V_40 [ V_20 ] ) ;
}
static void F_23 ( T_2 * V_38 , const T_2 * V_41 , unsigned int V_19 )
{
unsigned int V_20 , V_42 ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 += 4 )
for ( V_42 = 0 ; V_42 < 4 && ( V_20 + V_42 ) < V_19 ; ++ V_42 )
V_38 [ V_20 + V_42 ] = V_41 [ V_20 + 3 - V_42 ] ;
}
static void F_24 ( unsigned short V_21 , unsigned char * V_38 )
{
F_21 ( V_38 + V_43 , ( const T_2 * ) V_22 [ V_21 ] ) ;
F_21 ( V_38 + V_44 , ( const T_2 * ) V_24 [ V_21 ] ) ;
F_23 ( V_38 + V_45 , ( const T_2 * ) V_25 ,
V_46 ) ;
F_23 ( V_38 + V_47 , ( const T_2 * ) V_27 ,
V_48 ) ;
F_23 ( V_38 + V_49 , ( const T_2 * ) V_29 ,
V_46 ) ;
F_23 ( V_38 + V_50 , ( const T_2 * ) V_30 ,
V_48 ) ;
}
static int F_25 ( struct V_51 * V_6 )
{
if ( V_6 -> V_52 >= V_6 -> V_53 )
return - 1 ;
return * ( T_2 * ) V_6 -> V_52 ++ ;
}
static int F_26 ( struct V_51 * V_6 , unsigned int * V_54 )
{
if ( V_6 -> V_53 - V_6 -> V_52 < 2 )
return - 1 ;
* V_54 = F_27 ( V_6 -> V_52 ) ;
V_6 -> V_52 += 2 ;
return 0 ;
}
static void F_28 ( struct V_51 * V_6 , unsigned long V_19 )
{
V_6 -> V_52 += F_29 ( ( unsigned long ) ( V_6 -> V_53 - V_6 -> V_52 ) , V_19 ) ;
}
static T_2 F_30 ( void * V_55 , unsigned long V_56 , unsigned int * V_57 ,
unsigned int * V_58 )
{
struct V_51 V_51 ;
unsigned int V_54 ;
bool V_59 = false ;
V_51 . V_53 = V_55 + V_56 ;
V_51 . V_52 = V_55 ;
if ( V_56 < V_60 || * ( T_2 * ) ( V_55 + V_56 - 1 ) != V_61 )
return 0 ;
for (; ; ) {
int V_13 ;
do
V_13 = F_25 ( & V_51 ) ;
while ( V_13 == 0xff || V_13 == 0 );
if ( ! V_59 && V_13 == V_62 ) {
V_59 = true ;
continue;
} else if ( V_59 != ( V_13 != V_62 ) )
return 0 ;
switch ( V_13 ) {
case V_63 :
F_28 ( & V_51 , 3 ) ;
if ( F_26 ( & V_51 , V_58 ) ||
F_26 ( & V_51 , V_57 ) ||
F_25 ( & V_51 ) != 3 )
return 0 ;
F_28 ( & V_51 , 1 ) ;
return F_25 ( & V_51 ) ;
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 ... V_68 + 0x0f :
if ( F_26 ( & V_51 , & V_54 ) )
return 0 ;
F_28 ( & V_51 , ( long ) V_54 - 2 ) ;
case 0 :
break;
default:
return 0 ;
}
}
return 0 ;
}
static int F_31 ( struct V_69 * V_69 , void * V_70 ,
struct V_71 * V_72 )
{
struct V_11 * V_73 = F_8 ( V_70 ) ;
if ( V_73 -> V_74 )
F_32 ( V_72 -> V_75 , V_76 L_2 , sizeof( V_72 -> V_75 ) ) ;
else
F_32 ( V_72 -> V_75 , V_76 L_3 , sizeof( V_72 -> V_75 ) ) ;
F_32 ( V_72 -> V_77 , V_76 , sizeof( V_72 -> V_77 ) ) ;
snprintf ( V_72 -> V_78 , sizeof( V_72 -> V_78 ) , L_4 ,
F_33 ( V_73 -> V_7 -> V_36 ) ) ;
V_72 -> V_79 |= V_80 | V_81 ;
V_72 -> V_82 = V_83 | V_72 -> V_79 ;
memset ( V_72 -> V_84 , 0 , sizeof( V_72 -> V_84 ) ) ;
return 0 ;
}
static struct V_85 * F_34 ( bool V_74 , T_1 V_86 ,
unsigned int V_87 )
{
unsigned int V_20 , V_88 ;
if ( V_74 )
V_88 = V_87 == V_89 ? V_90 :
V_91 ;
else
V_88 = V_87 == V_89 ? V_92 :
V_93 ;
for ( V_20 = 0 ; V_20 < F_22 ( V_94 ) ; V_20 ++ ) {
struct V_85 * V_95 = & V_94 [ V_20 ] ;
if ( V_95 -> V_96 == V_86 && V_95 -> V_97 & V_88 )
return V_95 ;
}
return NULL ;
}
static int F_35 ( struct V_98 * V_99 , T_1 type )
{
unsigned int V_20 , V_100 = 0 ;
for ( V_20 = 0 ; V_20 < F_22 ( V_94 ) ; ++ V_20 ) {
if ( V_94 [ V_20 ] . V_97 & type ) {
if ( V_100 == V_99 -> V_101 )
break;
++ V_100 ;
}
}
if ( V_20 >= F_22 ( V_94 ) )
return - V_102 ;
V_99 -> V_86 = V_94 [ V_20 ] . V_96 ;
return 0 ;
}
static int F_36 ( struct V_69 * V_69 , void * V_70 ,
struct V_98 * V_99 )
{
struct V_11 * V_73 = F_8 ( V_70 ) ;
return F_35 ( V_99 , V_73 -> V_74 ? V_91 :
V_93 ) ;
}
static int F_37 ( struct V_69 * V_69 , void * V_70 ,
struct V_98 * V_99 )
{
struct V_11 * V_73 = F_8 ( V_70 ) ;
return F_35 ( V_99 , V_73 -> V_74 ? V_90 : V_92 ) ;
}
static struct V_103 * F_38 ( struct V_11 * V_73 ,
enum V_104 type )
{
if ( F_39 ( type ) )
return & V_73 -> V_105 ;
else
return & V_73 -> V_106 ;
}
static void F_40 ( T_1 * V_107 , unsigned int V_108 ,
unsigned int V_109 , unsigned int V_110 ,
T_1 * V_111 , unsigned int V_112 ,
unsigned int V_113 , unsigned int V_114 )
{
unsigned int V_57 , V_58 , V_115 , V_116 ;
V_57 = * V_107 ;
V_58 = * V_111 ;
V_115 = 1U << V_110 ;
V_116 = 1U << V_114 ;
F_41 ( V_107 , V_108 , V_109 , V_110 , V_111 , V_112 , V_113 ,
V_114 , 3 ) ;
if ( * V_107 < V_57 && * V_107 + V_115 < V_109 )
* V_107 += V_115 ;
if ( * V_111 < V_58 && * V_111 + V_116 < V_113 )
* V_111 += V_116 ;
}
static int F_42 ( struct V_11 * V_73 , struct V_85 * * V_117 ,
struct V_118 * V_119 ,
enum V_104 type )
{
struct V_85 * V_95 ;
unsigned int V_120 , V_107 , V_111 ;
V_120 = F_39 ( type ) ? V_89 :
V_121 ;
V_95 = F_34 ( V_73 -> V_74 , V_119 -> V_86 , V_120 ) ;
if ( ! V_95 ) {
unsigned int V_86 ;
F_43 ( V_73 -> V_7 -> V_36 , L_5 ) ;
if ( V_73 -> V_74 )
V_86 = V_120 == V_89 ?
V_122 : V_123 ;
else
V_86 = V_120 == V_121 ?
V_122 : V_123 ;
V_95 = F_34 ( V_73 -> V_74 , V_86 , V_120 ) ;
}
V_119 -> V_86 = V_95 -> V_96 ;
V_119 -> V_124 = V_95 -> V_124 ;
V_119 -> V_125 = V_126 ;
V_119 -> V_127 = V_95 -> V_127 ;
memset ( V_119 -> V_84 , 0 , sizeof( V_119 -> V_84 ) ) ;
F_40 ( & V_119 -> V_57 , V_128 , V_129 ,
V_95 -> V_114 , & V_119 -> V_58 , V_130 ,
V_131 , V_95 -> V_132 ) ;
V_107 = V_119 -> V_57 ;
V_111 = V_119 -> V_58 ;
if ( V_95 -> V_96 == V_123 ) {
if ( V_119 -> V_133 [ 0 ] . V_134 <= 0 || V_73 -> V_74 )
V_119 -> V_133 [ 0 ] . V_134 = V_135 +
( V_136 * V_107 * V_111 ) ;
V_119 -> V_133 [ 0 ] . V_137 = 0 ;
memset ( V_119 -> V_133 [ 0 ] . V_84 , 0 ,
sizeof( V_119 -> V_133 [ 0 ] . V_84 ) ) ;
} else {
unsigned int V_20 , V_138 = 0 ;
for ( V_20 = 0 ; V_20 < V_119 -> V_127 ; ++ V_20 )
V_138 = F_44 ( V_138 , V_119 -> V_133 [ V_20 ] . V_137 ) ;
V_138 = F_45 (unsigned int, bpl, w, JPU_WIDTH_MAX) ;
V_138 = F_46 ( V_138 , V_139 ) ;
for ( V_20 = 0 ; V_20 < V_119 -> V_127 ; ++ V_20 ) {
V_119 -> V_133 [ V_20 ] . V_137 = V_138 ;
V_119 -> V_133 [ V_20 ] . V_134 = V_138 * V_111 * V_95 -> V_140 [ V_20 ] / 8 ;
memset ( V_119 -> V_133 [ V_20 ] . V_84 , 0 ,
sizeof( V_119 -> V_133 [ V_20 ] . V_84 ) ) ;
}
}
if ( V_117 )
* V_117 = V_95 ;
return 0 ;
}
static int F_47 ( struct V_69 * V_69 , void * V_70 , struct V_141 * V_99 )
{
struct V_11 * V_73 = F_8 ( V_70 ) ;
if ( ! F_48 ( V_73 -> V_17 . V_142 , V_99 -> type ) )
return - V_102 ;
return F_42 ( V_73 , NULL , & V_99 -> V_95 . V_143 , V_99 -> type ) ;
}
static int F_49 ( struct V_69 * V_69 , void * V_70 , struct V_141 * V_99 )
{
struct V_144 * V_145 ;
struct V_11 * V_73 = F_8 ( V_70 ) ;
struct V_146 * V_142 = V_73 -> V_17 . V_142 ;
struct V_85 * V_117 ;
struct V_103 * V_147 ;
int V_148 ;
V_145 = F_48 ( V_142 , V_99 -> type ) ;
if ( ! V_145 )
return - V_102 ;
if ( F_50 ( V_145 ) ) {
F_51 ( & V_73 -> V_7 -> V_149 , L_6 , V_150 ) ;
return - V_151 ;
}
V_148 = F_42 ( V_73 , & V_117 , & V_99 -> V_95 . V_143 , V_99 -> type ) ;
if ( V_148 < 0 )
return V_148 ;
V_147 = F_38 ( V_73 , V_99 -> type ) ;
V_147 -> V_152 = V_99 -> V_95 . V_143 ;
V_147 -> V_117 = V_117 ;
return 0 ;
}
static int F_52 ( struct V_69 * V_69 , void * V_70 , struct V_141 * V_99 )
{
struct V_103 * V_147 ;
struct V_11 * V_73 = F_8 ( V_70 ) ;
if ( ! F_48 ( V_73 -> V_17 . V_142 , V_99 -> type ) )
return - V_102 ;
V_147 = F_38 ( V_73 , V_99 -> type ) ;
V_99 -> V_95 . V_143 = V_147 -> V_152 ;
return 0 ;
}
static int F_53 ( struct V_12 * V_153 )
{
struct V_11 * V_73 = F_7 ( V_153 ) ;
unsigned long V_154 ;
F_54 ( & V_73 -> V_7 -> V_155 , V_154 ) ;
if ( V_153 -> V_156 == V_157 )
V_73 -> V_158 = V_153 -> V_10 ;
F_55 ( & V_73 -> V_7 -> V_155 , V_154 ) ;
return 0 ;
}
static int F_56 ( struct V_69 * V_69 , void * V_70 , enum V_104 type )
{
struct V_11 * V_73 = F_8 ( V_70 ) ;
struct V_103 * V_159 , * V_160 , * V_161 , V_162 , * V_163 ;
enum V_104 V_164 ;
V_159 = F_38 ( V_73 , V_165 ) ;
V_160 = F_38 ( V_73 , V_166 ) ;
if ( V_73 -> V_74 ) {
V_162 = * V_159 ;
V_161 = V_159 ;
V_163 = V_160 ;
V_164 = V_165 ;
} else {
V_162 = * V_160 ;
V_161 = V_160 ;
V_163 = V_159 ;
V_164 = V_166 ;
}
V_162 . V_152 . V_57 = V_163 -> V_152 . V_57 ;
V_162 . V_152 . V_58 = V_163 -> V_152 . V_58 ;
F_42 ( V_73 , NULL , & V_162 . V_152 , V_164 ) ;
if ( V_162 . V_152 . V_57 != V_161 -> V_152 . V_57 ||
V_162 . V_152 . V_58 != V_161 -> V_152 . V_58 ) {
F_18 ( V_73 -> V_7 -> V_36 , L_7 ) ;
return - V_102 ;
}
return F_57 ( V_69 , V_73 -> V_17 . V_142 , type ) ;
}
static int F_58 ( struct V_11 * V_73 )
{
struct V_12 * V_153 ;
int V_148 ;
F_59 ( & V_73 -> V_15 , 1 ) ;
V_153 = F_60 ( & V_73 -> V_15 , & V_167 ,
V_157 ,
0 , V_168 - 1 , 1 , 0 ) ;
if ( V_73 -> V_15 . error ) {
V_148 = V_73 -> V_15 . error ;
goto V_169;
}
if ( ! V_73 -> V_74 )
V_153 -> V_154 |= V_170 |
V_171 ;
V_148 = F_61 ( & V_73 -> V_15 ) ;
if ( V_148 < 0 )
goto V_169;
return 0 ;
V_169:
F_62 ( & V_73 -> V_15 ) ;
return V_148 ;
}
static int F_63 ( struct V_144 * V_145 ,
const void * V_172 ,
unsigned int * V_173 , unsigned int * V_174 ,
unsigned int V_175 [] , void * V_176 [] )
{
const struct V_141 * V_95 = V_172 ;
struct V_11 * V_73 = F_64 ( V_145 ) ;
struct V_103 * V_147 ;
unsigned int V_20 ;
V_147 = F_38 ( V_73 , V_145 -> type ) ;
* V_174 = V_147 -> V_152 . V_127 ;
for ( V_20 = 0 ; V_20 < * V_174 ; V_20 ++ ) {
unsigned int V_177 = V_147 -> V_152 . V_133 [ V_20 ] . V_134 ;
unsigned int V_178 = V_95 ?
V_95 -> V_95 . V_143 . V_133 [ V_20 ] . V_134 : 0 ;
if ( V_95 && V_178 < V_177 )
return - V_102 ;
V_175 [ V_20 ] = V_95 ? V_178 : V_177 ;
V_176 [ V_20 ] = V_73 -> V_7 -> V_179 ;
}
return 0 ;
}
static int F_65 ( struct V_180 * V_3 )
{
struct V_2 * V_181 = F_66 ( V_3 ) ;
struct V_11 * V_73 = F_64 ( V_3 -> V_144 ) ;
struct V_103 * V_147 ;
unsigned int V_20 ;
V_147 = F_38 ( V_73 , V_3 -> V_144 -> type ) ;
if ( F_39 ( V_3 -> V_144 -> type ) ) {
if ( V_181 -> V_125 == V_182 )
V_181 -> V_125 = V_126 ;
if ( V_181 -> V_125 != V_126 ) {
F_18 ( V_73 -> V_7 -> V_36 , L_8 ,
V_150 ) ;
return - V_102 ;
}
}
for ( V_20 = 0 ; V_20 < V_147 -> V_152 . V_127 ; V_20 ++ ) {
unsigned long V_56 = V_147 -> V_152 . V_133 [ V_20 ] . V_134 ;
if ( F_67 ( V_3 , V_20 ) < V_56 ) {
F_18 ( V_73 -> V_7 -> V_36 ,
L_9 ,
V_150 , F_67 ( V_3 , V_20 ) , V_56 ) ;
return - V_102 ;
}
if ( ! V_73 -> V_74 && ! F_39 ( V_3 -> V_144 -> type ) )
F_68 ( V_3 , V_20 , V_56 ) ;
}
return 0 ;
}
static void F_69 ( struct V_180 * V_3 )
{
struct V_2 * V_181 = F_66 ( V_3 ) ;
struct V_11 * V_73 = F_64 ( V_3 -> V_144 ) ;
if ( ! V_73 -> V_74 && F_39 ( V_3 -> V_144 -> type ) ) {
struct V_1 * V_183 = F_1 ( V_181 ) ;
struct V_103 * V_147 , V_184 ;
void * V_55 = F_70 ( V_3 , 0 ) ;
unsigned long V_185 = F_71 ( V_3 , 0 ) ;
unsigned int V_57 , V_58 ;
T_2 V_186 = F_30 ( V_55 , V_185 , & V_57 ,
& V_58 ) ;
if ( V_186 != V_187 && V_186 != V_188 )
goto V_189;
V_147 = & V_73 -> V_105 ;
V_184 = * V_147 ;
V_184 . V_152 . V_57 = V_57 ;
V_184 . V_152 . V_58 = V_58 ;
F_42 ( V_73 , & V_184 . V_117 , & V_184 . V_152 ,
V_165 ) ;
if ( V_184 . V_152 . V_57 != V_147 -> V_152 . V_57 ||
V_184 . V_152 . V_58 != V_147 -> V_152 . V_58 )
goto V_189;
V_183 -> V_186 = V_186 ;
}
if ( V_73 -> V_17 . V_142 )
F_72 ( V_73 -> V_17 . V_142 , V_181 ) ;
return;
V_189:
F_18 ( V_73 -> V_7 -> V_36 , L_10 ) ;
F_73 ( V_3 , V_190 ) ;
}
static void F_74 ( struct V_180 * V_3 )
{
struct V_2 * V_181 = F_66 ( V_3 ) ;
struct V_1 * V_183 = F_1 ( V_181 ) ;
struct V_11 * V_73 = F_64 ( V_3 -> V_144 ) ;
struct V_103 * V_147 = & V_73 -> V_105 ;
enum V_104 type = V_3 -> V_144 -> type ;
T_2 * V_55 ;
if ( V_3 -> V_191 == V_192 )
V_181 -> V_193 = F_38 ( V_73 , type ) -> V_193 ++ ;
if ( ! V_73 -> V_74 || V_3 -> V_191 != V_192 ||
F_39 ( type ) )
return;
V_55 = F_70 ( V_3 , 0 ) ;
memcpy ( V_55 , V_194 [ V_183 -> V_158 ] , V_135 ) ;
* ( V_195 * ) ( V_55 + V_196 ) =
F_75 ( V_147 -> V_152 . V_58 ) ;
* ( V_195 * ) ( V_55 + V_197 ) =
F_75 ( V_147 -> V_152 . V_57 ) ;
* ( V_55 + V_198 ) = V_147 -> V_117 -> V_186 ;
}
static int F_76 ( struct V_144 * V_145 , unsigned V_199 )
{
struct V_11 * V_73 = F_64 ( V_145 ) ;
struct V_103 * V_147 = F_38 ( V_73 , V_145 -> type ) ;
V_147 -> V_193 = 0 ;
return 0 ;
}
static void F_77 ( struct V_144 * V_145 )
{
struct V_11 * V_73 = F_64 ( V_145 ) ;
struct V_2 * V_3 ;
unsigned long V_154 ;
for (; ; ) {
if ( F_39 ( V_145 -> type ) )
V_3 = F_78 ( V_73 -> V_17 . V_142 ) ;
else
V_3 = F_79 ( V_73 -> V_17 . V_142 ) ;
if ( V_3 == NULL )
return;
F_54 ( & V_73 -> V_7 -> V_155 , V_154 ) ;
F_80 ( V_3 , V_190 ) ;
F_55 ( & V_73 -> V_7 -> V_155 , V_154 ) ;
}
}
static int F_81 ( void * V_70 , struct V_144 * V_200 ,
struct V_144 * V_201 )
{
struct V_11 * V_73 = V_70 ;
int V_148 ;
memset ( V_200 , 0 , sizeof( * V_200 ) ) ;
V_200 -> type = V_165 ;
V_200 -> V_202 = V_203 | V_204 ;
V_200 -> V_205 = V_73 ;
V_200 -> V_206 = sizeof( struct V_1 ) ;
V_200 -> V_207 = & V_208 ;
V_200 -> V_209 = & V_210 ;
V_200 -> V_211 = V_212 ;
V_200 -> V_155 = & V_73 -> V_7 -> V_213 ;
V_148 = F_82 ( V_200 ) ;
if ( V_148 )
return V_148 ;
memset ( V_201 , 0 , sizeof( * V_201 ) ) ;
V_201 -> type = V_166 ;
V_201 -> V_202 = V_203 | V_204 ;
V_201 -> V_205 = V_73 ;
V_201 -> V_206 = sizeof( struct V_1 ) ;
V_201 -> V_207 = & V_208 ;
V_201 -> V_209 = & V_210 ;
V_201 -> V_211 = V_212 ;
V_201 -> V_155 = & V_73 -> V_7 -> V_213 ;
return F_82 ( V_201 ) ;
}
static int F_83 ( struct V_69 * V_69 )
{
struct V_7 * V_7 = F_84 ( V_69 ) ;
struct V_214 * V_215 = F_85 ( V_69 ) ;
struct V_11 * V_73 ;
int V_148 ;
V_73 = F_86 ( sizeof( * V_73 ) , V_216 ) ;
if ( ! V_73 )
return - V_217 ;
F_87 ( & V_73 -> V_17 , V_215 ) ;
V_73 -> V_17 . V_15 = & V_73 -> V_15 ;
V_69 -> V_218 = & V_73 -> V_17 ;
F_88 ( & V_73 -> V_17 ) ;
V_73 -> V_7 = V_7 ;
V_73 -> V_74 = V_215 == & V_7 -> V_219 ;
F_42 ( V_73 , & V_73 -> V_105 . V_117 , & V_73 -> V_105 . V_152 ,
V_165 ) ;
F_42 ( V_73 , & V_73 -> V_106 . V_117 , & V_73 -> V_106 . V_152 ,
V_166 ) ;
V_73 -> V_17 . V_142 = F_89 ( V_7 -> V_220 , V_73 , F_81 ) ;
if ( F_90 ( V_73 -> V_17 . V_142 ) ) {
V_148 = F_91 ( V_73 -> V_17 . V_142 ) ;
goto V_221;
}
V_148 = F_58 ( V_73 ) ;
if ( V_148 < 0 )
goto V_221;
if ( F_92 ( & V_7 -> V_213 ) ) {
V_148 = - V_222 ;
goto V_221;
}
if ( V_7 -> V_223 == 0 ) {
V_148 = F_93 ( V_7 -> V_224 ) ;
if ( V_148 < 0 )
goto V_225;
V_148 = F_20 ( V_7 ) ;
if ( V_148 )
goto V_225;
}
V_7 -> V_223 ++ ;
F_94 ( & V_7 -> V_213 ) ;
return 0 ;
V_225:
F_94 ( & V_7 -> V_213 ) ;
V_221:
F_95 ( & V_73 -> V_17 ) ;
F_96 ( & V_73 -> V_17 ) ;
F_97 ( V_73 ) ;
return V_148 ;
}
static int F_98 ( struct V_69 * V_69 )
{
struct V_7 * V_7 = F_84 ( V_69 ) ;
struct V_11 * V_73 = F_8 ( V_69 -> V_218 ) ;
F_99 ( & V_7 -> V_213 ) ;
if ( -- V_7 -> V_223 == 0 )
F_100 ( V_7 -> V_224 ) ;
F_94 ( & V_7 -> V_213 ) ;
F_101 ( V_73 -> V_17 . V_142 ) ;
F_62 ( & V_73 -> V_15 ) ;
F_95 ( & V_73 -> V_17 ) ;
F_96 ( & V_73 -> V_17 ) ;
F_97 ( V_73 ) ;
return 0 ;
}
static void F_102 ( struct V_11 * V_73 , bool V_226 )
{
struct V_2 * V_227 , * V_228 ;
unsigned long V_154 ;
F_54 ( & V_73 -> V_7 -> V_155 , V_154 ) ;
V_227 = F_78 ( V_73 -> V_17 . V_142 ) ;
V_228 = F_79 ( V_73 -> V_17 . V_142 ) ;
F_80 ( V_227 , V_190 ) ;
F_80 ( V_228 , V_190 ) ;
if ( V_226 )
F_5 ( V_73 -> V_7 , V_35 , V_34 ) ;
F_55 ( & V_73 -> V_7 -> V_155 , V_154 ) ;
F_103 ( V_73 -> V_7 -> V_220 , V_73 -> V_17 . V_142 ) ;
}
static void F_104 ( void * V_70 )
{
struct V_11 * V_73 = V_70 ;
struct V_7 * V_7 = V_73 -> V_7 ;
struct V_1 * V_183 ;
struct V_103 * V_147 ;
struct V_2 * V_227 , * V_228 ;
unsigned int V_107 , V_111 , V_138 ;
unsigned char V_127 , V_186 ;
unsigned long V_154 ;
if ( F_15 ( V_7 ) ) {
F_102 ( V_73 , true ) ;
return;
}
F_54 ( & V_73 -> V_7 -> V_155 , V_154 ) ;
V_7 -> V_52 = V_73 ;
V_227 = F_105 ( V_73 -> V_17 . V_142 ) ;
V_228 = F_106 ( V_73 -> V_17 . V_142 ) ;
if ( V_73 -> V_74 ) {
V_183 = F_1 ( V_228 ) ;
V_147 = & V_73 -> V_105 ;
} else {
V_183 = F_1 ( V_227 ) ;
V_147 = & V_73 -> V_106 ;
}
V_107 = V_147 -> V_152 . V_57 ;
V_111 = V_147 -> V_152 . V_58 ;
V_138 = V_147 -> V_152 . V_133 [ 0 ] . V_137 ;
V_127 = V_147 -> V_117 -> V_127 ;
V_186 = V_147 -> V_117 -> V_186 ;
if ( V_73 -> V_74 ) {
unsigned long V_229 , V_230 , V_231 ;
unsigned int V_232 , V_233 ;
V_231 = F_107 ( & V_228 -> V_234 , 0 ) ;
V_229 =
F_107 ( & V_227 -> V_234 , 0 ) ;
if ( V_127 > 1 )
V_230 = F_107 (
& V_227 -> V_234 , 1 ) ;
else
V_230 = V_229 + V_107 * V_111 ;
V_183 -> V_158 = V_73 -> V_158 ;
if ( V_186 == V_188 ) {
V_232 = V_235 ;
V_233 = V_236 ;
} else {
V_232 = V_237 ;
V_233 = V_238 ;
}
F_5 ( V_7 , V_239 | V_240 | V_232 |
V_241 , V_242 ) ;
F_5 ( V_7 , V_243 | V_233 , V_244 ) ;
F_5 ( V_7 , V_245 , V_246 ) ;
F_5 ( V_7 , V_247 , V_248 ) ;
F_5 ( V_7 , V_229 , V_249 ) ;
F_5 ( V_7 , V_230 , V_250 ) ;
F_5 ( V_7 , V_138 , V_251 ) ;
F_5 ( V_7 , ( V_107 >> 8 ) & V_252 , V_253 ) ;
F_5 ( V_7 , V_107 & V_252 , V_254 ) ;
F_5 ( V_7 , ( V_111 >> 8 ) & V_252 , V_255 ) ;
F_5 ( V_7 , V_111 & V_252 , V_256 ) ;
F_5 ( V_7 , V_107 , V_257 ) ;
F_5 ( V_7 , V_111 , V_258 ) ;
F_5 ( V_7 , V_231 + V_135 , V_259 ) ;
F_5 ( V_7 , 0 << F_108 ( 1 ) | 1 << F_108 ( 2 ) |
1 << F_108 ( 3 ) , V_260 ) ;
F_5 ( V_7 , 0 << F_109 ( 1 ) | 0 << F_110 ( 1 ) |
1 << F_109 ( 2 ) | 1 << F_110 ( 2 ) |
1 << F_109 ( 3 ) | 1 << F_110 ( 3 ) ,
V_261 ) ;
F_10 ( V_7 , V_73 -> V_158 ) ;
F_12 ( V_7 ) ;
} else {
unsigned long V_262 , V_263 , V_264 ;
if ( V_183 -> V_186 != V_186 ) {
F_18 ( V_73 -> V_7 -> V_36 ,
L_7 ) ;
F_55 ( & V_73 -> V_7 -> V_155 , V_154 ) ;
F_102 ( V_73 , false ) ;
return;
}
V_262 = F_107 ( & V_227 -> V_234 , 0 ) ;
V_263 =
F_107 ( & V_228 -> V_234 , 0 ) ;
if ( V_147 -> V_117 -> V_127 > 1 )
V_264 = F_107 (
& V_228 -> V_234 , 1 ) ;
else
V_264 = V_263 + V_107 * V_111 ;
F_5 ( V_7 , V_265 | V_240 , V_242 ) ;
F_5 ( V_7 , V_243 , V_244 ) ;
F_5 ( V_7 , V_245 , V_246 ) ;
F_5 ( V_7 , V_247 | V_266 , V_248 ) ;
F_5 ( V_7 , V_262 , V_267 ) ;
F_5 ( V_7 , V_263 , V_268 ) ;
F_5 ( V_7 , V_264 , V_269 ) ;
F_5 ( V_7 , V_138 , V_270 ) ;
}
F_5 ( V_7 , V_271 , V_34 ) ;
F_55 ( & V_73 -> V_7 -> V_155 , V_154 ) ;
}
static int F_111 ( void * V_70 )
{
return 1 ;
}
static void F_112 ( void * V_70 )
{
struct V_11 * V_73 = V_70 ;
if ( ! F_113 ( V_73 -> V_7 -> V_272 , ! V_73 -> V_7 -> V_52 ,
F_16 ( V_273 ) ) )
F_102 ( V_73 , true ) ;
}
static T_3 F_114 ( int V_274 , void * V_275 )
{
struct V_7 * V_7 = V_275 ;
struct V_11 * V_276 ;
struct V_2 * V_227 , * V_228 ;
unsigned int V_277 ;
V_277 = F_3 ( V_7 , V_278 ) ;
if ( ! ( ( V_279 | V_280 | V_281 ) &
V_277 ) )
return V_282 ;
F_5 ( V_7 , ~ ( V_277 & V_283 ) , V_278 ) ;
if ( V_277 & ( V_281 | V_280 ) )
F_5 ( V_7 , V_284 , V_34 ) ;
F_115 ( & V_7 -> V_155 ) ;
if ( ( V_277 & V_280 ) &&
! ( V_277 & V_279 ) )
goto V_285;
V_276 = F_116 ( V_7 -> V_220 ) ;
if ( ! V_276 ) {
F_18 ( V_7 -> V_36 , L_11 ) ;
goto V_285;
}
V_227 = F_78 ( V_276 -> V_17 . V_142 ) ;
V_228 = F_79 ( V_276 -> V_17 . V_142 ) ;
if ( V_277 & V_279 ) {
if ( V_276 -> V_74 ) {
unsigned long V_286 = F_3 ( V_7 , V_287 ) << 16
| F_3 ( V_7 , V_288 ) << 8
| F_3 ( V_7 , V_289 ) ;
F_68 ( & V_228 -> V_234 , 0 ,
V_286 + V_135 ) ;
}
V_228 -> V_125 = V_227 -> V_125 ;
V_228 -> V_290 = V_227 -> V_290 ;
if ( V_227 -> V_154 & V_291 )
V_228 -> V_292 = V_227 -> V_292 ;
V_228 -> V_154 &= ~ V_293 ;
V_228 -> V_154 |= V_227 -> V_154 &
V_293 ;
V_228 -> V_154 = V_227 -> V_154 &
( V_291 | V_294 |
V_295 | V_296 |
V_293 ) ;
F_80 ( V_227 , V_192 ) ;
F_80 ( V_228 , V_192 ) ;
} else if ( V_277 & V_281 ) {
unsigned char error = F_3 ( V_7 , V_297 ) & V_298 ;
F_43 ( V_7 -> V_36 , L_12 , error ,
V_299 [ error ] ) ;
F_80 ( V_227 , V_190 ) ;
F_80 ( V_228 , V_190 ) ;
}
V_7 -> V_52 = NULL ;
F_5 ( V_7 , V_35 , V_34 ) ;
F_117 ( & V_7 -> V_155 ) ;
F_103 ( V_7 -> V_220 , V_276 -> V_17 . V_142 ) ;
F_118 ( & V_7 -> V_272 ) ;
return V_300 ;
V_285:
F_117 ( & V_7 -> V_155 ) ;
return V_300 ;
}
static int F_119 ( struct V_301 * V_302 )
{
struct V_7 * V_7 ;
struct V_303 * V_304 ;
int V_148 ;
unsigned int V_20 ;
V_7 = F_120 ( & V_302 -> V_36 , sizeof( * V_7 ) , V_216 ) ;
if ( ! V_7 )
return - V_217 ;
F_121 ( & V_7 -> V_272 ) ;
F_122 ( & V_7 -> V_213 ) ;
F_123 ( & V_7 -> V_155 ) ;
V_7 -> V_36 = & V_302 -> V_36 ;
V_304 = F_124 ( V_302 , V_305 , 0 ) ;
V_7 -> V_9 = F_125 ( & V_302 -> V_36 , V_304 ) ;
if ( F_90 ( V_7 -> V_9 ) )
return F_91 ( V_7 -> V_9 ) ;
V_7 -> V_274 = V_148 = F_126 ( V_302 , 0 ) ;
if ( V_148 < 0 ) {
F_18 ( & V_302 -> V_36 , L_13 ) ;
return V_148 ;
}
V_148 = F_127 ( & V_302 -> V_36 , V_7 -> V_274 , F_114 , 0 ,
F_33 ( & V_302 -> V_36 ) , V_7 ) ;
if ( V_148 ) {
F_18 ( & V_302 -> V_36 , L_14 , V_7 -> V_274 ) ;
return V_148 ;
}
V_7 -> V_224 = F_128 ( & V_302 -> V_36 , NULL ) ;
if ( F_90 ( V_7 -> V_224 ) ) {
F_18 ( & V_302 -> V_36 , L_15 ) ;
return F_91 ( V_7 -> V_224 ) ;
}
V_148 = F_129 ( & V_302 -> V_36 , & V_7 -> V_149 ) ;
if ( V_148 ) {
F_18 ( & V_302 -> V_36 , L_16 ) ;
return V_148 ;
}
V_7 -> V_220 = F_130 ( & V_306 ) ;
if ( F_90 ( V_7 -> V_220 ) ) {
F_51 ( & V_7 -> V_149 , L_17 ) ;
V_148 = F_91 ( V_7 -> V_220 ) ;
goto V_307;
}
V_7 -> V_179 = F_131 ( & V_302 -> V_36 ) ;
if ( F_90 ( V_7 -> V_179 ) ) {
F_51 ( & V_7 -> V_149 , L_18 ) ;
V_148 = F_91 ( V_7 -> V_179 ) ;
goto V_308;
}
for ( V_20 = 0 ; V_20 < V_168 ; V_20 ++ )
F_24 ( V_20 , ( unsigned char * ) V_194 [ V_20 ] ) ;
F_32 ( V_7 -> V_219 . V_309 , V_76 , sizeof( V_7 -> V_219 . V_309 ) ) ;
V_7 -> V_219 . V_310 = & V_311 ;
V_7 -> V_219 . V_312 = & V_313 ;
V_7 -> V_219 . V_314 = - 1 ;
V_7 -> V_219 . V_315 = V_316 ;
V_7 -> V_219 . V_155 = & V_7 -> V_213 ;
V_7 -> V_219 . V_149 = & V_7 -> V_149 ;
V_7 -> V_219 . V_317 = V_318 ;
V_148 = F_132 ( & V_7 -> V_219 , V_319 , - 1 ) ;
if ( V_148 ) {
F_51 ( & V_7 -> V_149 , L_19 ) ;
goto V_320;
}
F_133 ( & V_7 -> V_219 , V_7 ) ;
F_32 ( V_7 -> V_321 . V_309 , V_76 , sizeof( V_7 -> V_321 . V_309 ) ) ;
V_7 -> V_321 . V_310 = & V_311 ;
V_7 -> V_321 . V_312 = & V_313 ;
V_7 -> V_321 . V_314 = - 1 ;
V_7 -> V_321 . V_315 = V_316 ;
V_7 -> V_321 . V_155 = & V_7 -> V_213 ;
V_7 -> V_321 . V_149 = & V_7 -> V_149 ;
V_7 -> V_321 . V_317 = V_318 ;
V_148 = F_132 ( & V_7 -> V_321 , V_319 , - 1 ) ;
if ( V_148 ) {
F_51 ( & V_7 -> V_149 , L_19 ) ;
goto V_322;
}
F_133 ( & V_7 -> V_321 , V_7 ) ;
F_134 ( V_302 , V_7 ) ;
F_135 ( & V_7 -> V_149 , L_20 ,
V_7 -> V_219 . V_100 ) ;
F_135 ( & V_7 -> V_149 , L_21 ,
V_7 -> V_321 . V_100 ) ;
return 0 ;
V_322:
F_136 ( & V_7 -> V_219 ) ;
V_320:
F_137 ( V_7 -> V_179 ) ;
V_308:
F_138 ( V_7 -> V_220 ) ;
V_307:
F_139 ( & V_7 -> V_149 ) ;
return V_148 ;
}
static int F_140 ( struct V_301 * V_302 )
{
struct V_7 * V_7 = F_141 ( V_302 ) ;
F_136 ( & V_7 -> V_321 ) ;
F_136 ( & V_7 -> V_219 ) ;
F_137 ( V_7 -> V_179 ) ;
F_138 ( V_7 -> V_220 ) ;
F_139 ( & V_7 -> V_149 ) ;
return 0 ;
}
static int F_142 ( struct V_323 * V_36 )
{
struct V_7 * V_7 = F_143 ( V_36 ) ;
if ( V_7 -> V_223 == 0 )
return 0 ;
F_100 ( V_7 -> V_224 ) ;
return 0 ;
}
static int F_144 ( struct V_323 * V_36 )
{
struct V_7 * V_7 = F_143 ( V_36 ) ;
if ( V_7 -> V_223 == 0 )
return 0 ;
F_93 ( V_7 -> V_224 ) ;
return 0 ;
}
