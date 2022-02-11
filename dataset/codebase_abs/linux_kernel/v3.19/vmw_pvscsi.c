static struct V_1 *
F_1 ( const struct V_2 * V_3 )
{
return & ( V_3 -> V_4 -> V_4 ) ;
}
static struct V_5 *
F_2 ( const struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_5 * V_8 , * V_9 ;
V_9 = & V_3 -> V_10 [ V_3 -> V_11 ] ;
for ( V_8 = V_3 -> V_10 ; V_8 < V_9 ; V_8 ++ )
if ( V_8 -> V_7 == V_7 )
return V_8 ;
return NULL ;
}
static struct V_5 *
F_3 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_5 * V_8 ;
if ( F_4 ( & V_3 -> V_12 ) )
return NULL ;
V_8 = F_5 ( & V_3 -> V_12 , struct V_5 , V_13 ) ;
V_8 -> V_7 = V_7 ;
F_6 ( & V_8 -> V_13 ) ;
return V_8 ;
}
static void F_7 ( struct V_2 * V_3 ,
struct V_5 * V_8 )
{
V_8 -> V_7 = NULL ;
V_8 -> V_14 = NULL ;
F_8 ( & V_8 -> V_13 , & V_3 -> V_12 ) ;
}
static T_1 F_9 ( const struct V_2 * V_3 ,
const struct V_5 * V_8 )
{
return V_8 - V_3 -> V_10 + 1 ;
}
static struct V_5 *
F_10 ( const struct V_2 * V_3 , T_1 V_15 )
{
return & V_3 -> V_10 [ V_15 - 1 ] ;
}
static void F_11 ( const struct V_2 * V_3 ,
T_2 V_16 , T_2 V_17 )
{
F_12 ( V_17 , V_3 -> V_18 + V_16 ) ;
}
static T_2 F_13 ( const struct V_2 * V_3 , T_2 V_16 )
{
return F_14 ( V_3 -> V_18 + V_16 ) ;
}
static T_2 F_15 ( const struct V_2 * V_3 )
{
return F_13 ( V_3 , V_19 ) ;
}
static void F_16 ( const struct V_2 * V_3 ,
T_2 V_17 )
{
F_11 ( V_3 , V_19 , V_17 ) ;
}
static void F_17 ( const struct V_2 * V_3 )
{
T_2 V_20 ;
V_20 = V_21 ;
if ( V_3 -> V_22 )
V_20 |= V_23 ;
F_11 ( V_3 , V_24 , V_20 ) ;
}
static void F_18 ( const struct V_2 * V_3 )
{
F_11 ( V_3 , V_24 , 0 ) ;
}
static void F_19 ( const struct V_2 * V_3 ,
T_2 V_7 , const void * V_25 , T_3 V_26 )
{
const T_2 * V_27 = V_25 ;
T_3 V_28 ;
V_26 /= sizeof( * V_27 ) ;
F_11 ( V_3 , V_29 , V_7 ) ;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ )
F_11 ( V_3 ,
V_30 , V_27 [ V_28 ] ) ;
}
static void F_20 ( const struct V_2 * V_3 ,
const struct V_5 * V_8 )
{
struct V_31 V_7 = { 0 } ;
V_7 . V_32 = V_8 -> V_7 -> V_1 -> V_33 ;
V_7 . V_15 = F_9 ( V_3 , V_8 ) ;
F_19 ( V_3 , V_34 , & V_7 , sizeof( V_7 ) ) ;
}
static void F_21 ( const struct V_2 * V_3 )
{
F_11 ( V_3 , V_35 , 0 ) ;
}
static void F_22 ( const struct V_2 * V_3 )
{
F_11 ( V_3 , V_36 , 0 ) ;
}
static int F_23 ( unsigned char V_37 )
{
return V_37 == V_38 || V_37 == V_39 ||
V_37 == V_40 || V_37 == V_41 ||
V_37 == V_42 || V_37 == V_43 ||
V_37 == V_44 || V_37 == V_45 ;
}
static void F_24 ( const struct V_2 * V_3 ,
unsigned char V_37 )
{
if ( F_23 ( V_37 ) ) {
struct V_46 * V_47 = V_3 -> V_48 ;
if ( ! V_3 -> V_49 ||
V_47 -> V_50 - V_47 -> V_51 >= V_47 -> V_52 )
F_21 ( V_3 ) ;
} else {
F_22 ( V_3 ) ;
}
}
static void F_25 ( const struct V_2 * V_3 )
{
F_26 ( F_1 ( V_3 ) , L_1 , V_3 ) ;
F_19 ( V_3 , V_53 , NULL , 0 ) ;
}
static void F_27 ( const struct V_2 * V_3 )
{
F_26 ( F_1 ( V_3 ) , L_2 , V_3 ) ;
F_19 ( V_3 , V_54 , NULL , 0 ) ;
}
static void F_28 ( const struct V_2 * V_3 , T_2 V_32 )
{
struct V_55 V_7 = { 0 } ;
F_26 ( F_1 ( V_3 ) , L_3 , V_32 ) ;
V_7 . V_32 = V_32 ;
F_19 ( V_3 , V_56 ,
& V_7 , sizeof( V_7 ) ) ;
}
static void F_29 ( struct V_5 * V_8 ,
struct V_57 * V_58 , unsigned V_59 )
{
unsigned V_28 ;
struct V_60 * V_61 ;
F_30 ( V_59 > V_62 ) ;
V_61 = & V_8 -> V_63 -> V_61 [ 0 ] ;
for ( V_28 = 0 ; V_28 < V_59 ; V_28 ++ , V_58 ++ ) {
V_61 [ V_28 ] . V_64 = F_31 ( V_58 ) ;
V_61 [ V_28 ] . V_65 = F_32 ( V_58 ) ;
V_61 [ V_28 ] . V_66 = 0 ;
}
}
static void F_33 ( struct V_2 * V_3 ,
struct V_5 * V_8 , struct V_6 * V_7 ,
struct V_67 * V_68 )
{
unsigned V_59 ;
unsigned V_69 = F_34 ( V_7 ) ;
struct V_57 * V_58 ;
V_68 -> V_70 = V_69 ;
V_68 -> V_71 = 0 ;
if ( V_69 == 0 )
return;
V_58 = F_35 ( V_7 ) ;
V_59 = F_36 ( V_7 ) ;
if ( V_59 != 0 ) {
int V_72 = F_37 ( V_7 ) ;
if ( V_72 > 1 ) {
F_29 ( V_8 , V_58 , V_72 ) ;
V_68 -> V_66 |= V_73 ;
V_8 -> V_74 = F_38 ( V_3 -> V_4 , V_8 -> V_63 ,
V_75 , V_76 ) ;
V_68 -> V_71 = V_8 -> V_74 ;
} else
V_68 -> V_71 = F_31 ( V_58 ) ;
} else {
V_8 -> V_77 = F_38 ( V_3 -> V_4 , V_58 , V_69 ,
V_7 -> V_78 ) ;
V_68 -> V_71 = V_8 -> V_77 ;
}
}
static void F_39 ( const struct V_2 * V_3 ,
struct V_5 * V_8 )
{
struct V_6 * V_7 ;
unsigned V_69 ;
V_7 = V_8 -> V_7 ;
V_69 = F_34 ( V_7 ) ;
if ( V_69 != 0 ) {
unsigned V_59 = F_36 ( V_7 ) ;
if ( V_59 != 0 ) {
F_40 ( V_7 ) ;
if ( V_8 -> V_74 ) {
F_41 ( V_3 -> V_4 , V_8 -> V_74 ,
V_75 , V_76 ) ;
V_8 -> V_74 = 0 ;
}
} else
F_41 ( V_3 -> V_4 , V_8 -> V_77 , V_69 ,
V_7 -> V_78 ) ;
}
if ( V_7 -> V_79 )
F_41 ( V_3 -> V_4 , V_8 -> V_80 ,
V_81 , V_82 ) ;
}
static int F_42 ( struct V_2 * V_3 )
{
V_3 -> V_48 = F_43 ( V_3 -> V_4 , V_83 ,
& V_3 -> V_84 ) ;
if ( ! V_3 -> V_48 )
return - V_85 ;
V_3 -> V_86 = F_44 ( V_87 ,
V_88 ) ;
V_3 -> V_11 = V_3 -> V_86
* V_89 ;
V_3 -> V_90 = F_43 ( V_3 -> V_4 ,
V_3 -> V_86 * V_83 ,
& V_3 -> V_91 ) ;
if ( ! V_3 -> V_90 )
return - V_85 ;
V_3 -> V_92 = F_44 ( V_93 ,
V_88 ) ;
V_3 -> V_94 = F_43 ( V_3 -> V_4 ,
V_3 -> V_92 * V_83 ,
& V_3 -> V_95 ) ;
if ( ! V_3 -> V_94 )
return - V_85 ;
F_30 ( ! F_45 ( V_3 -> V_84 , V_83 ) ) ;
F_30 ( ! F_45 ( V_3 -> V_91 , V_83 ) ) ;
F_30 ( ! F_45 ( V_3 -> V_95 , V_83 ) ) ;
if ( ! V_3 -> V_22 )
return 0 ;
V_3 -> V_96 = F_44 ( V_97 ,
V_98 ) ;
V_3 -> V_99 = F_43 ( V_3 -> V_4 ,
V_3 -> V_96 * V_83 ,
& V_3 -> V_100 ) ;
if ( ! V_3 -> V_99 )
return - V_85 ;
F_30 ( ! F_45 ( V_3 -> V_100 , V_83 ) ) ;
return 0 ;
}
static void F_46 ( const struct V_2 * V_3 )
{
struct V_101 V_7 = { 0 } ;
T_4 V_102 ;
unsigned V_28 ;
V_7 . V_103 = V_3 -> V_84 >> V_104 ;
V_7 . V_105 = V_3 -> V_86 ;
V_7 . V_106 = V_3 -> V_92 ;
V_102 = V_3 -> V_91 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_86 ; V_28 ++ ) {
V_7 . V_107 [ V_28 ] = V_102 >> V_104 ;
V_102 += V_83 ;
}
V_102 = V_3 -> V_95 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_92 ; V_28 ++ ) {
V_7 . V_108 [ V_28 ] = V_102 >> V_104 ;
V_102 += V_83 ;
}
memset ( V_3 -> V_48 , 0 , V_83 ) ;
memset ( V_3 -> V_90 , 0 , V_3 -> V_86 * V_83 ) ;
memset ( V_3 -> V_94 , 0 , V_3 -> V_92 * V_83 ) ;
F_19 ( V_3 , V_109 ,
& V_7 , sizeof( V_7 ) ) ;
if ( V_3 -> V_22 ) {
struct V_110 V_111 = { 0 } ;
V_111 . V_112 = V_3 -> V_96 ;
V_102 = V_3 -> V_100 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_96 ; V_28 ++ ) {
V_111 . V_113 [ V_28 ] = V_102 >> V_104 ;
V_102 += V_83 ;
}
memset ( V_3 -> V_99 , 0 , V_3 -> V_96 * V_83 ) ;
F_19 ( V_3 , V_114 ,
& V_111 , sizeof( V_111 ) ) ;
}
}
static int F_47 ( struct V_115 * V_116 , int V_117 )
{
if ( ! V_116 -> V_118 )
V_117 = 1 ;
return F_48 ( V_116 , V_117 ) ;
}
static void F_49 ( struct V_2 * V_3 ,
const struct V_119 * V_68 )
{
struct V_5 * V_8 ;
struct V_6 * V_7 ;
struct V_120 * V_14 ;
T_2 V_121 = V_68 -> V_122 ;
T_2 V_123 = V_68 -> V_124 ;
V_8 = F_10 ( V_3 , V_68 -> V_15 ) ;
V_7 = V_8 -> V_7 ;
V_14 = V_8 -> V_14 ;
F_39 ( V_3 , V_8 ) ;
F_7 ( V_3 , V_8 ) ;
if ( V_14 ) {
F_50 ( V_14 ) ;
return;
}
V_7 -> V_125 = 0 ;
if ( V_123 != V_126 &&
( V_121 == V_127 ||
V_121 == V_128 ||
V_121 == V_129 ) ) {
V_7 -> V_125 = ( V_130 << 16 ) | V_123 ;
if ( V_123 == V_131 && V_7 -> V_79 )
V_7 -> V_125 |= ( V_132 << 24 ) ;
} else
switch ( V_121 ) {
case V_127 :
case V_128 :
case V_129 :
V_7 -> V_125 = ( V_130 << 16 ) ;
break;
case V_133 :
case V_134 :
F_51 ( V_7 , F_34 ( V_7 ) - V_68 -> V_70 ) ;
V_7 -> V_125 = ( V_135 << 16 ) ;
break;
case V_136 :
V_7 -> V_125 = ( V_137 << 16 ) ;
break;
case V_138 :
case V_139 :
case V_140 :
V_7 -> V_125 = ( V_141 << 24 ) ;
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
V_7 -> V_125 |= ( V_135 << 16 ) ;
break;
case V_150 :
case V_151 :
case V_152 :
V_7 -> V_125 = ( V_153 << 16 ) ;
break;
case V_154 :
V_7 -> V_125 = ( V_155 << 16 ) ;
break;
case V_156 :
V_7 -> V_125 = ( V_157 << 16 ) ;
break;
default:
V_7 -> V_125 = ( V_135 << 16 ) ;
F_52 ( V_158 , V_7 ,
L_4 ,
V_121 ) ;
}
F_26 ( & V_7 -> V_1 -> V_159 ,
L_5 ,
V_7 , V_7 -> V_160 [ 0 ] , V_8 , V_7 -> V_125 , V_121 , V_123 ) ;
V_7 -> V_161 ( V_7 ) ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_46 * V_47 = V_3 -> V_48 ;
struct V_119 * V_162 = V_3 -> V_94 ;
T_2 V_163 = V_47 -> V_164 ;
while ( V_47 -> V_165 != V_47 -> V_166 ) {
struct V_119 * V_68 = V_162 + ( V_47 -> V_165 &
F_54 ( V_163 ) ) ;
F_55 () ;
F_49 ( V_3 , V_68 ) ;
F_55 () ;
V_47 -> V_165 ++ ;
}
}
static int F_56 ( struct V_2 * V_3 ,
struct V_5 * V_8 , struct V_6 * V_7 )
{
struct V_46 * V_47 ;
struct V_67 * V_68 ;
struct V_115 * V_116 ;
T_2 V_167 ;
V_47 = V_3 -> V_48 ;
V_116 = V_7 -> V_1 ;
V_167 = V_47 -> V_168 ;
if ( V_47 -> V_50 - V_47 -> V_165 >= 1 << V_167 ) {
F_52 ( V_169 , V_7 , L_6
L_7 ,
V_47 -> V_50 , V_47 -> V_165 ) ;
return - 1 ;
}
V_68 = V_3 -> V_90 + ( V_47 -> V_50 & F_54 ( V_167 ) ) ;
V_68 -> V_170 = V_116 -> V_171 ;
V_68 -> V_32 = V_116 -> V_33 ;
memset ( V_68 -> V_172 , 0 , sizeof( V_68 -> V_172 ) ) ;
V_68 -> V_172 [ 1 ] = V_116 -> V_172 ;
if ( V_7 -> V_79 ) {
V_8 -> V_80 = F_38 ( V_3 -> V_4 , V_7 -> V_79 ,
V_81 ,
V_82 ) ;
V_68 -> V_173 = V_8 -> V_80 ;
V_68 -> V_174 = V_81 ;
} else {
V_68 -> V_174 = 0 ;
V_68 -> V_173 = 0 ;
}
V_68 -> V_175 = V_7 -> V_176 ;
V_68 -> V_177 = F_57 () ;
memcpy ( V_68 -> V_178 , V_7 -> V_160 , V_68 -> V_175 ) ;
V_68 -> V_179 = V_180 ;
if ( V_7 -> V_78 == V_181 )
V_68 -> V_66 = V_182 ;
else if ( V_7 -> V_78 == V_183 )
V_68 -> V_66 = V_184 ;
else if ( V_7 -> V_78 == V_185 )
V_68 -> V_66 = V_186 ;
else
V_68 -> V_66 = 0 ;
F_33 ( V_3 , V_8 , V_7 , V_68 ) ;
V_68 -> V_15 = F_9 ( V_3 , V_8 ) ;
F_55 () ;
V_47 -> V_50 ++ ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 , void (* F_59)( struct V_6 * ) )
{
struct V_187 * V_188 = V_7 -> V_1 -> V_188 ;
struct V_2 * V_3 = F_60 ( V_188 ) ;
struct V_5 * V_8 ;
unsigned long V_66 ;
F_61 ( & V_3 -> V_189 , V_66 ) ;
V_8 = F_3 ( V_3 , V_7 ) ;
if ( ! V_8 || F_56 ( V_3 , V_8 , V_7 ) != 0 ) {
if ( V_8 )
F_7 ( V_3 , V_8 ) ;
F_62 ( & V_3 -> V_189 , V_66 ) ;
return V_190 ;
}
V_7 -> V_161 = F_59 ;
F_26 ( & V_7 -> V_1 -> V_159 ,
L_8 , V_7 , V_8 , V_7 -> V_160 [ 0 ] ) ;
F_62 ( & V_3 -> V_189 , V_66 ) ;
F_24 ( V_3 , V_7 -> V_160 [ 0 ] ) ;
return 0 ;
}
void F_63 ( struct V_2 * V_3 )
{
unsigned V_28 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_11 ; V_28 ++ ) {
struct V_5 * V_8 = & V_3 -> V_10 [ V_28 ] ;
struct V_6 * V_7 = V_8 -> V_7 ;
if ( V_7 ) {
F_52 ( V_169 , V_7 ,
L_9 , V_7 ) ;
F_39 ( V_3 , V_8 ) ;
F_7 ( V_3 , V_8 ) ;
V_7 -> V_125 = ( V_153 << 16 ) ;
V_7 -> V_161 ( V_7 ) ;
}
}
}
static int F_64 ( struct V_6 * V_7 )
{
struct V_187 * V_188 = V_7 -> V_1 -> V_188 ;
struct V_2 * V_3 = F_60 ( V_188 ) ;
unsigned long V_66 ;
bool V_22 ;
F_52 ( V_191 , V_7 , L_10 ) ;
F_61 ( & V_3 -> V_189 , V_66 ) ;
V_22 = V_3 -> V_22 ;
if ( V_22 ) {
V_3 -> V_22 = 0 ;
F_62 ( & V_3 -> V_189 , V_66 ) ;
F_65 ( V_3 -> V_192 ) ;
F_61 ( & V_3 -> V_189 , V_66 ) ;
}
F_22 ( V_3 ) ;
F_25 ( V_3 ) ;
F_53 ( V_3 ) ;
F_63 ( V_3 ) ;
V_3 -> V_22 = V_22 ;
F_46 ( V_3 ) ;
F_17 ( V_3 ) ;
F_62 ( & V_3 -> V_189 , V_66 ) ;
return V_193 ;
}
static int F_66 ( struct V_6 * V_7 )
{
struct V_187 * V_188 = V_7 -> V_1 -> V_188 ;
struct V_2 * V_3 = F_60 ( V_188 ) ;
unsigned long V_66 ;
F_52 ( V_191 , V_7 , L_11 ) ;
F_61 ( & V_3 -> V_189 , V_66 ) ;
F_22 ( V_3 ) ;
F_27 ( V_3 ) ;
F_53 ( V_3 ) ;
F_62 ( & V_3 -> V_189 , V_66 ) ;
return V_193 ;
}
static int F_67 ( struct V_6 * V_7 )
{
struct V_187 * V_188 = V_7 -> V_1 -> V_188 ;
struct V_2 * V_3 = F_60 ( V_188 ) ;
unsigned long V_66 ;
F_52 ( V_191 , V_7 , L_12 ,
V_188 -> V_194 , V_7 -> V_1 -> V_33 ) ;
F_61 ( & V_3 -> V_189 , V_66 ) ;
F_22 ( V_3 ) ;
F_28 ( V_3 , V_7 -> V_1 -> V_33 ) ;
F_53 ( V_3 ) ;
F_62 ( & V_3 -> V_189 , V_66 ) ;
return V_193 ;
}
static const char * F_68 ( struct V_187 * V_188 )
{
struct V_2 * V_3 = F_60 ( V_188 ) ;
static char V_195 [ 256 ] ;
sprintf ( V_195 , L_13
L_14 , V_3 -> V_196 ,
V_3 -> V_86 , V_3 -> V_92 , V_3 -> V_96 ,
V_197 . V_198 ) ;
return V_195 ;
}
static void F_69 ( const struct V_2 * V_3 ,
const struct V_199 * V_68 )
{
struct V_46 * V_47 = V_3 -> V_48 ;
struct V_187 * V_188 = V_3 -> V_188 ;
struct V_115 * V_116 ;
F_70 ( V_191 L_15 ,
V_68 -> type , V_47 -> V_200 , V_47 -> V_201 , V_47 -> V_202 ) ;
F_71 ( V_203 != 2 ) ;
if ( V_68 -> type == V_204 ) {
struct V_205 * V_25 ;
V_25 = (struct V_205 * ) V_68 ;
F_70 ( V_191
L_16 ,
V_25 -> V_170 , V_25 -> V_32 , V_25 -> V_172 [ 1 ] ) ;
if ( ! F_72 ( V_188 ) )
return;
V_116 = F_73 ( V_188 , V_25 -> V_170 , V_25 -> V_32 ,
V_25 -> V_172 [ 1 ] ) ;
if ( V_116 ) {
F_70 ( V_191 L_17 ) ;
F_74 ( V_116 ) ;
} else
F_75 ( V_3 -> V_188 , V_25 -> V_170 ,
V_25 -> V_32 , V_25 -> V_172 [ 1 ] ) ;
F_76 ( V_188 ) ;
} else if ( V_68 -> type == V_206 ) {
struct V_205 * V_25 ;
V_25 = (struct V_205 * ) V_68 ;
F_70 ( V_191
L_18 ,
V_25 -> V_170 , V_25 -> V_32 , V_25 -> V_172 [ 1 ] ) ;
if ( ! F_72 ( V_188 ) )
return;
V_116 = F_73 ( V_188 , V_25 -> V_170 , V_25 -> V_32 ,
V_25 -> V_172 [ 1 ] ) ;
if ( V_116 ) {
F_77 ( V_116 ) ;
F_74 ( V_116 ) ;
} else
F_70 ( V_191
L_19 ,
V_25 -> V_170 , V_25 -> V_32 , V_25 -> V_172 [ 1 ] ) ;
F_76 ( V_188 ) ;
}
}
static int F_78 ( const struct V_2 * V_3 )
{
struct V_46 * V_47 = V_3 -> V_48 ;
return V_47 -> V_200 != V_47 -> V_201 ;
}
static void F_79 ( const struct V_2 * V_3 )
{
struct V_46 * V_47 = V_3 -> V_48 ;
struct V_199 * V_162 = V_3 -> V_99 ;
T_2 V_207 = V_47 -> V_202 ;
while ( F_78 ( V_3 ) ) {
struct V_199 * V_68 = V_162 + ( V_47 -> V_201 &
F_54 ( V_207 ) ) ;
F_55 () ;
F_69 ( V_3 , V_68 ) ;
F_55 () ;
V_47 -> V_201 ++ ;
}
}
static void F_80 ( struct V_208 * V_209 )
{
struct V_2 * V_3 ;
V_3 = F_81 ( V_209 , struct V_2 , V_210 ) ;
F_79 ( V_3 ) ;
}
static int F_82 ( struct V_2 * V_3 )
{
char V_211 [ 32 ] ;
if ( ! V_212 )
return 0 ;
F_11 ( V_3 , V_29 ,
V_114 ) ;
if ( F_13 ( V_3 , V_213 ) == - 1 )
return 0 ;
snprintf ( V_211 , sizeof( V_211 ) ,
L_20 , V_3 -> V_188 -> V_194 ) ;
V_3 -> V_192 = F_83 ( V_211 ) ;
if ( ! V_3 -> V_192 ) {
F_70 ( V_169 L_21 ) ;
return 0 ;
}
F_84 ( & V_3 -> V_210 , F_80 ) ;
return 1 ;
}
static bool F_85 ( struct V_2 * V_3 ,
bool V_214 )
{
T_2 V_17 ;
if ( ! V_215 )
return false ;
F_11 ( V_3 , V_29 ,
V_216 ) ;
V_17 = F_13 ( V_3 , V_213 ) ;
if ( V_17 == - 1 ) {
F_70 ( V_191 L_22 ) ;
return false ;
} else {
struct V_217 V_111 = { 0 } ;
V_111 . V_214 = V_214 ;
F_70 ( V_191
L_23 ,
V_214 ? L_24 : L_25 ) ;
F_19 ( V_3 ,
V_216 ,
& V_111 , sizeof( V_111 ) ) ;
return F_13 ( V_3 ,
V_213 ) != 0 ;
}
}
static T_5 F_86 ( int V_218 , void * V_219 )
{
struct V_2 * V_3 = V_219 ;
int V_220 ;
if ( V_3 -> V_221 || V_3 -> V_222 )
V_220 = true ;
else {
T_2 V_17 = F_15 ( V_3 ) ;
V_220 = ( V_17 & V_223 ) != 0 ;
if ( V_220 )
F_16 ( V_219 , V_17 ) ;
}
if ( V_220 ) {
unsigned long V_66 ;
F_61 ( & V_3 -> V_189 , V_66 ) ;
F_53 ( V_3 ) ;
if ( V_3 -> V_22 && F_78 ( V_3 ) )
F_87 ( V_3 -> V_192 , & V_3 -> V_210 ) ;
F_62 ( & V_3 -> V_189 , V_66 ) ;
}
return F_88 ( V_220 ) ;
}
static void F_89 ( const struct V_2 * V_3 )
{
struct V_5 * V_8 = V_3 -> V_10 ;
unsigned V_28 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_11 ; ++ V_28 , ++ V_8 )
F_90 ( ( unsigned long ) V_8 -> V_63 , F_91 ( V_75 ) ) ;
}
static int F_92 ( const struct V_2 * V_3 ,
unsigned int * V_218 )
{
struct V_224 V_225 = { 0 , V_226 } ;
int V_227 ;
V_227 = F_93 ( V_3 -> V_4 , & V_225 , 1 ) ;
if ( V_227 )
return V_227 ;
* V_218 = V_225 . V_228 ;
return 0 ;
}
static void F_94 ( struct V_2 * V_3 )
{
if ( V_3 -> V_218 ) {
F_95 ( V_3 -> V_218 , V_3 ) ;
V_3 -> V_218 = 0 ;
}
if ( V_3 -> V_221 ) {
F_96 ( V_3 -> V_4 ) ;
V_3 -> V_221 = 0 ;
} else if ( V_3 -> V_222 ) {
F_97 ( V_3 -> V_4 ) ;
V_3 -> V_222 = 0 ;
}
}
static void F_98 ( struct V_2 * V_3 )
{
F_94 ( V_3 ) ;
if ( V_3 -> V_192 )
F_99 ( V_3 -> V_192 ) ;
if ( V_3 -> V_18 )
F_100 ( V_3 -> V_4 , V_3 -> V_18 ) ;
F_101 ( V_3 -> V_4 ) ;
if ( V_3 -> V_10 ) {
F_89 ( V_3 ) ;
F_102 ( V_3 -> V_10 ) ;
}
if ( V_3 -> V_48 )
F_103 ( V_3 -> V_4 , V_83 ,
V_3 -> V_48 , V_3 -> V_84 ) ;
if ( V_3 -> V_90 )
F_103 ( V_3 -> V_4 ,
V_3 -> V_86 * V_83 ,
V_3 -> V_90 , V_3 -> V_91 ) ;
if ( V_3 -> V_94 )
F_103 ( V_3 -> V_4 ,
V_3 -> V_92 * V_83 ,
V_3 -> V_94 , V_3 -> V_95 ) ;
if ( V_3 -> V_99 )
F_103 ( V_3 -> V_4 ,
V_3 -> V_96 * V_83 ,
V_3 -> V_99 , V_3 -> V_100 ) ;
}
static int F_104 ( struct V_2 * V_3 )
{
struct V_5 * V_8 ;
int V_28 ;
V_8 = V_3 -> V_10 ;
F_71 ( sizeof( struct V_229 ) > V_75 ) ;
for ( V_28 = 0 ; V_28 < V_3 -> V_11 ; ++ V_28 , ++ V_8 ) {
V_8 -> V_63 = ( void * ) F_105 ( V_230 ,
F_91 ( V_75 ) ) ;
V_8 -> V_74 = 0 ;
F_30 ( ! F_45 ( ( ( unsigned long ) V_8 -> V_63 ) , V_83 ) ) ;
if ( ! V_8 -> V_63 ) {
for (; V_28 >= 0 ; -- V_28 , -- V_8 ) {
F_90 ( ( unsigned long ) V_8 -> V_63 ,
F_91 ( V_75 ) ) ;
V_8 -> V_63 = NULL ;
}
return - V_85 ;
}
}
return 0 ;
}
static T_2 F_106 ( struct V_2 * V_3 )
{
struct V_231 V_7 ;
struct V_232 * V_233 ;
struct V_1 * V_4 ;
T_4 V_234 ;
void * V_235 ;
T_2 V_236 = 16 ;
V_4 = F_1 ( V_3 ) ;
V_235 = F_43 ( V_3 -> V_4 , V_83 ,
& V_234 ) ;
if ( ! V_235 ) {
F_107 ( V_4 , L_26 ) ;
goto exit;
}
F_30 ( V_234 & ~ V_237 ) ;
V_7 . V_238 = ( ( T_1 ) V_239 ) << 32 ;
V_7 . V_240 = V_241 ;
V_7 . V_242 = V_234 ;
V_7 . V_243 = 0 ;
V_233 = V_235 ;
memset ( V_233 , 0 , sizeof *V_233 ) ;
V_233 -> V_122 = V_244 ;
V_233 -> V_124 = V_245 ;
F_19 ( V_3 , V_246 , & V_7 , sizeof V_7 ) ;
if ( V_233 -> V_122 == V_127 &&
V_233 -> V_124 == V_247 ) {
struct V_248 * V_249 ;
V_249 = V_235 ;
V_236 = V_249 -> V_236 ;
} else
F_107 ( V_4 , L_27 ,
V_233 -> V_122 , V_233 -> V_124 ) ;
F_103 ( V_3 -> V_4 , V_83 , V_235 , V_234 ) ;
exit:
return V_236 ;
}
static int F_108 ( struct V_250 * V_251 , const struct V_252 * V_33 )
{
struct V_2 * V_3 ;
struct V_2 V_253 ;
struct V_187 * V_188 = NULL ;
unsigned int V_28 ;
unsigned long V_66 = 0 ;
int error ;
T_2 V_254 ;
error = - V_255 ;
if ( F_109 ( V_251 ) )
return error ;
if ( F_110 ( V_251 , F_111 ( 64 ) ) == 0 &&
F_112 ( V_251 , F_111 ( 64 ) ) == 0 ) {
F_70 ( V_191 L_28 ) ;
} else if ( F_110 ( V_251 , F_111 ( 32 ) ) == 0 &&
F_112 ( V_251 , F_111 ( 32 ) ) == 0 ) {
F_70 ( V_191 L_29 ) ;
} else {
F_70 ( V_169 L_30 ) ;
goto V_256;
}
V_3 = & V_253 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_4 = V_251 ;
V_3 -> V_196 = V_251 -> V_257 ;
if ( F_113 ( V_251 , L_31 ) ) {
F_70 ( V_169 L_32 ) ;
goto V_256;
}
for ( V_28 = 0 ; V_28 < V_258 ; V_28 ++ ) {
if ( ( F_114 ( V_251 , V_28 ) & V_259 ) )
continue;
if ( F_115 ( V_251 , V_28 ) < V_260 )
continue;
break;
}
if ( V_28 == V_258 ) {
F_70 ( V_169
L_33 ) ;
goto V_261;
}
V_3 -> V_18 = F_116 ( V_251 , V_28 , V_260 ) ;
if ( ! V_3 -> V_18 ) {
F_70 ( V_169
L_34 ,
V_28 , V_260 ) ;
goto V_261;
}
F_117 ( V_251 ) ;
V_254 = F_106 ( V_3 ) ;
F_70 ( V_191 L_35 , V_254 ) ;
if ( V_88 == 0 )
V_88 = ( V_254 > 16 ) ?
V_262 :
V_263 ;
F_70 ( V_191
L_36 ,
V_88 ) ;
V_197 . V_264 =
F_44 ( V_87 , V_88 ) *
V_89 ;
V_197 . V_198 =
F_44 ( V_197 . V_264 , V_265 ) ;
V_188 = F_118 ( & V_197 , sizeof( struct V_2 ) ) ;
if ( ! V_188 ) {
F_70 ( V_169 L_37 ) ;
goto V_261;
}
V_3 = F_60 ( V_188 ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_4 = V_251 ;
V_3 -> V_188 = V_188 ;
V_3 -> V_196 = V_253 . V_196 ;
V_3 -> V_18 = V_253 . V_18 ;
F_119 ( & V_3 -> V_189 ) ;
V_188 -> V_266 = 0 ;
V_188 -> V_267 = 1 ;
V_188 -> V_268 = 16 ;
V_188 -> V_254 = V_254 ;
F_120 ( V_251 , V_188 ) ;
F_25 ( V_3 ) ;
V_3 -> V_22 = F_82 ( V_3 ) ;
error = F_42 ( V_3 ) ;
if ( error ) {
F_70 ( V_169 L_38 ) ;
goto V_269;
}
F_46 ( V_3 ) ;
V_3 -> V_10 = F_121 ( V_3 -> V_11 ,
sizeof( struct V_5 ) , V_230 ) ;
if ( ! V_3 -> V_10 ) {
F_70 ( V_169 L_39 ) ;
error = - V_85 ;
goto V_270;
}
F_122 ( & V_3 -> V_12 ) ;
for ( V_28 = 0 ; V_28 < V_3 -> V_11 ; V_28 ++ ) {
struct V_5 * V_8 = V_3 -> V_10 + V_28 ;
F_8 ( & V_8 -> V_13 , & V_3 -> V_12 ) ;
}
error = F_104 ( V_3 ) ;
if ( error ) {
F_70 ( V_169 L_40 ) ;
goto V_270;
}
if ( ! V_271 &&
F_92 ( V_3 , & V_3 -> V_218 ) == 0 ) {
F_70 ( V_191 L_41 ) ;
V_3 -> V_222 = 1 ;
} else if ( ! V_272 && F_123 ( V_251 ) == 0 ) {
F_70 ( V_191 L_42 ) ;
V_3 -> V_221 = 1 ;
V_3 -> V_218 = V_251 -> V_218 ;
} else {
F_70 ( V_191 L_43 ) ;
V_3 -> V_218 = V_251 -> V_218 ;
V_66 = V_273 ;
}
V_3 -> V_49 = F_85 ( V_3 , true ) ;
F_70 ( V_158 L_44 ,
V_3 -> V_49 ? L_24 : L_25 ) ;
error = F_124 ( V_3 -> V_218 , F_86 , V_66 ,
L_31 , V_3 ) ;
if ( error ) {
F_70 ( V_169
L_45 , error ) ;
V_3 -> V_218 = 0 ;
goto V_270;
}
error = F_125 ( V_188 , & V_251 -> V_4 ) ;
if ( error ) {
F_70 ( V_169
L_46 , error ) ;
goto V_270;
}
F_126 ( & V_251 -> V_4 , L_47 ,
V_3 -> V_196 , V_188 -> V_194 ) ;
F_17 ( V_3 ) ;
F_127 ( V_188 ) ;
return 0 ;
V_270:
F_25 ( V_3 ) ;
V_269:
F_98 ( V_3 ) ;
F_76 ( V_188 ) ;
V_256:
F_128 ( V_251 ) ;
return error ;
V_261:
F_98 ( V_3 ) ;
goto V_256;
}
static void F_129 ( struct V_2 * V_3 )
{
F_18 ( V_3 ) ;
if ( V_3 -> V_192 )
F_65 ( V_3 -> V_192 ) ;
F_94 ( V_3 ) ;
F_22 ( V_3 ) ;
F_53 ( V_3 ) ;
F_25 ( V_3 ) ;
}
static void F_130 ( struct V_250 * V_4 )
{
struct V_187 * V_188 = F_131 ( V_4 ) ;
struct V_2 * V_3 = F_60 ( V_188 ) ;
F_129 ( V_3 ) ;
}
static void F_132 ( struct V_250 * V_251 )
{
struct V_187 * V_188 = F_131 ( V_251 ) ;
struct V_2 * V_3 = F_60 ( V_188 ) ;
F_133 ( V_188 ) ;
F_129 ( V_3 ) ;
F_98 ( V_3 ) ;
F_76 ( V_188 ) ;
F_128 ( V_251 ) ;
}
static int T_6 F_134 ( void )
{
F_135 ( L_48 ,
V_274 , V_275 ) ;
return F_136 ( & V_276 ) ;
}
static void T_7 F_137 ( void )
{
F_138 ( & V_276 ) ;
}
