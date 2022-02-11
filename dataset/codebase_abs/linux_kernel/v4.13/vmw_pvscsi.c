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
static int F_33 ( struct V_2 * V_3 ,
struct V_5 * V_8 , struct V_6 * V_7 ,
struct V_67 * V_68 )
{
unsigned V_59 ;
unsigned V_69 = F_34 ( V_7 ) ;
struct V_57 * V_58 ;
V_68 -> V_70 = V_69 ;
V_68 -> V_71 = 0 ;
if ( V_69 == 0 )
return 0 ;
V_58 = F_35 ( V_7 ) ;
V_59 = F_36 ( V_7 ) ;
if ( V_59 != 0 ) {
int V_72 = F_37 ( V_7 ) ;
if ( V_72 == - V_73 ) {
F_38 ( V_74 , V_7 ,
L_4 ) ;
return - V_73 ;
} else if ( V_72 > 1 ) {
F_29 ( V_8 , V_58 , V_72 ) ;
V_68 -> V_66 |= V_75 ;
V_8 -> V_76 = F_39 ( V_3 -> V_4 , V_8 -> V_63 ,
V_77 , V_78 ) ;
if ( F_40 ( V_3 -> V_4 , V_8 -> V_76 ) ) {
F_38 ( V_74 , V_7 ,
L_5 ) ;
F_41 ( V_7 ) ;
V_8 -> V_76 = 0 ;
return - V_73 ;
}
V_68 -> V_71 = V_8 -> V_76 ;
} else
V_68 -> V_71 = F_31 ( V_58 ) ;
} else {
V_8 -> V_79 = F_39 ( V_3 -> V_4 , V_58 , V_69 ,
V_7 -> V_80 ) ;
if ( F_40 ( V_3 -> V_4 , V_8 -> V_79 ) ) {
F_38 ( V_74 , V_7 ,
L_6 ) ;
return - V_73 ;
}
V_68 -> V_71 = V_8 -> V_79 ;
}
return 0 ;
}
static void F_42 ( const struct V_2 * V_3 ,
struct V_5 * V_8 )
{
struct V_6 * V_7 ;
unsigned V_69 ;
V_7 = V_8 -> V_7 ;
V_69 = F_34 ( V_7 ) ;
if ( V_69 != 0 ) {
unsigned V_59 = F_36 ( V_7 ) ;
if ( V_59 != 0 ) {
F_41 ( V_7 ) ;
if ( V_8 -> V_76 ) {
F_43 ( V_3 -> V_4 , V_8 -> V_76 ,
V_77 , V_78 ) ;
V_8 -> V_76 = 0 ;
}
} else
F_43 ( V_3 -> V_4 , V_8 -> V_79 , V_69 ,
V_7 -> V_80 ) ;
}
if ( V_7 -> V_81 )
F_43 ( V_3 -> V_4 , V_8 -> V_82 ,
V_83 , V_84 ) ;
}
static int F_44 ( struct V_2 * V_3 )
{
V_3 -> V_48 = F_45 ( V_3 -> V_4 , V_85 ,
& V_3 -> V_86 ) ;
if ( ! V_3 -> V_48 )
return - V_73 ;
V_3 -> V_87 = F_46 ( V_88 ,
V_89 ) ;
V_3 -> V_11 = V_3 -> V_87
* V_90 ;
V_3 -> V_91 = F_45 ( V_3 -> V_4 ,
V_3 -> V_87 * V_85 ,
& V_3 -> V_92 ) ;
if ( ! V_3 -> V_91 )
return - V_73 ;
V_3 -> V_93 = F_46 ( V_94 ,
V_89 ) ;
V_3 -> V_95 = F_45 ( V_3 -> V_4 ,
V_3 -> V_93 * V_85 ,
& V_3 -> V_96 ) ;
if ( ! V_3 -> V_95 )
return - V_73 ;
F_30 ( ! F_47 ( V_3 -> V_86 , V_85 ) ) ;
F_30 ( ! F_47 ( V_3 -> V_92 , V_85 ) ) ;
F_30 ( ! F_47 ( V_3 -> V_96 , V_85 ) ) ;
if ( ! V_3 -> V_22 )
return 0 ;
V_3 -> V_97 = F_46 ( V_98 ,
V_99 ) ;
V_3 -> V_100 = F_45 ( V_3 -> V_4 ,
V_3 -> V_97 * V_85 ,
& V_3 -> V_101 ) ;
if ( ! V_3 -> V_100 )
return - V_73 ;
F_30 ( ! F_47 ( V_3 -> V_101 , V_85 ) ) ;
return 0 ;
}
static void F_48 ( const struct V_2 * V_3 )
{
struct V_102 V_7 = { 0 } ;
T_4 V_103 ;
unsigned V_28 ;
V_7 . V_104 = V_3 -> V_86 >> V_105 ;
V_7 . V_106 = V_3 -> V_87 ;
V_7 . V_107 = V_3 -> V_93 ;
V_103 = V_3 -> V_92 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_87 ; V_28 ++ ) {
V_7 . V_108 [ V_28 ] = V_103 >> V_105 ;
V_103 += V_85 ;
}
V_103 = V_3 -> V_96 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_93 ; V_28 ++ ) {
V_7 . V_109 [ V_28 ] = V_103 >> V_105 ;
V_103 += V_85 ;
}
memset ( V_3 -> V_48 , 0 , V_85 ) ;
memset ( V_3 -> V_91 , 0 , V_3 -> V_87 * V_85 ) ;
memset ( V_3 -> V_95 , 0 , V_3 -> V_93 * V_85 ) ;
F_19 ( V_3 , V_110 ,
& V_7 , sizeof( V_7 ) ) ;
if ( V_3 -> V_22 ) {
struct V_111 V_112 = { 0 } ;
V_112 . V_113 = V_3 -> V_97 ;
V_103 = V_3 -> V_101 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_97 ; V_28 ++ ) {
V_112 . V_114 [ V_28 ] = V_103 >> V_105 ;
V_103 += V_85 ;
}
memset ( V_3 -> V_100 , 0 , V_3 -> V_97 * V_85 ) ;
F_19 ( V_3 , V_115 ,
& V_112 , sizeof( V_112 ) ) ;
}
}
static int F_49 ( struct V_116 * V_117 , int V_118 )
{
if ( ! V_117 -> V_119 )
V_118 = 1 ;
return F_50 ( V_117 , V_118 ) ;
}
static void F_51 ( struct V_2 * V_3 ,
const struct V_120 * V_68 )
{
struct V_5 * V_8 ;
struct V_6 * V_7 ;
struct V_121 * V_14 ;
T_2 V_122 = V_68 -> V_123 ;
T_2 V_124 = V_68 -> V_125 ;
V_8 = F_10 ( V_3 , V_68 -> V_15 ) ;
V_7 = V_8 -> V_7 ;
V_14 = V_8 -> V_14 ;
F_42 ( V_3 , V_8 ) ;
F_7 ( V_3 , V_8 ) ;
if ( V_14 ) {
F_52 ( V_14 ) ;
return;
}
V_7 -> V_126 = 0 ;
if ( V_124 != V_127 &&
( V_122 == V_128 ||
V_122 == V_129 ||
V_122 == V_130 ) ) {
V_7 -> V_126 = ( V_131 << 16 ) | V_124 ;
if ( V_124 == V_132 && V_7 -> V_81 )
V_7 -> V_126 |= ( V_133 << 24 ) ;
} else
switch ( V_122 ) {
case V_128 :
case V_129 :
case V_130 :
V_7 -> V_126 = ( V_131 << 16 ) ;
break;
case V_134 :
case V_135 :
F_53 ( V_7 , F_34 ( V_7 ) - V_68 -> V_70 ) ;
V_7 -> V_126 = ( V_136 << 16 ) ;
break;
case V_137 :
V_7 -> V_126 = ( V_138 << 16 ) ;
break;
case V_139 :
case V_140 :
case V_141 :
V_7 -> V_126 = ( V_142 << 24 ) ;
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
V_7 -> V_126 |= ( V_136 << 16 ) ;
break;
case V_151 :
case V_152 :
case V_153 :
V_7 -> V_126 = ( V_154 << 16 ) ;
break;
case V_155 :
V_7 -> V_126 = ( V_156 << 16 ) ;
break;
case V_157 :
V_7 -> V_126 = ( V_158 << 16 ) ;
break;
default:
V_7 -> V_126 = ( V_136 << 16 ) ;
F_38 ( V_159 , V_7 ,
L_7 ,
V_122 ) ;
}
F_26 ( & V_7 -> V_1 -> V_160 ,
L_8 ,
V_7 , V_7 -> V_161 [ 0 ] , V_8 , V_7 -> V_126 , V_122 , V_124 ) ;
V_7 -> V_162 ( V_7 ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_46 * V_47 = V_3 -> V_48 ;
struct V_120 * V_163 = V_3 -> V_95 ;
T_2 V_164 = V_47 -> V_165 ;
while ( V_47 -> V_166 != V_47 -> V_167 ) {
struct V_120 * V_68 = V_163 + ( V_47 -> V_166 &
F_55 ( V_164 ) ) ;
F_56 () ;
F_51 ( V_3 , V_68 ) ;
F_56 () ;
V_47 -> V_166 ++ ;
}
}
static int F_57 ( struct V_2 * V_3 ,
struct V_5 * V_8 , struct V_6 * V_7 )
{
struct V_46 * V_47 ;
struct V_67 * V_68 ;
struct V_116 * V_117 ;
T_2 V_168 ;
V_47 = V_3 -> V_48 ;
V_117 = V_7 -> V_1 ;
V_168 = V_47 -> V_169 ;
if ( V_47 -> V_50 - V_47 -> V_166 >= 1 << V_168 ) {
F_38 ( V_74 , V_7 , L_9
L_10 ,
V_47 -> V_50 , V_47 -> V_166 ) ;
return - 1 ;
}
V_68 = V_3 -> V_91 + ( V_47 -> V_50 & F_55 ( V_168 ) ) ;
V_68 -> V_170 = V_117 -> V_171 ;
V_68 -> V_32 = V_117 -> V_33 ;
memset ( V_68 -> V_172 , 0 , sizeof( V_68 -> V_172 ) ) ;
V_68 -> V_172 [ 1 ] = V_117 -> V_172 ;
if ( V_7 -> V_81 ) {
V_8 -> V_82 = F_39 ( V_3 -> V_4 , V_7 -> V_81 ,
V_83 ,
V_84 ) ;
if ( F_40 ( V_3 -> V_4 , V_8 -> V_82 ) ) {
F_38 ( V_74 , V_7 ,
L_11 ) ;
V_8 -> V_82 = 0 ;
return - V_73 ;
}
V_68 -> V_173 = V_8 -> V_82 ;
V_68 -> V_174 = V_83 ;
} else {
V_68 -> V_174 = 0 ;
V_68 -> V_173 = 0 ;
}
V_68 -> V_175 = V_7 -> V_176 ;
V_68 -> V_177 = F_58 () ;
memcpy ( V_68 -> V_178 , V_7 -> V_161 , V_68 -> V_175 ) ;
V_68 -> V_179 = V_180 ;
if ( V_7 -> V_80 == V_181 )
V_68 -> V_66 = V_182 ;
else if ( V_7 -> V_80 == V_183 )
V_68 -> V_66 = V_184 ;
else if ( V_7 -> V_80 == V_185 )
V_68 -> V_66 = V_186 ;
else
V_68 -> V_66 = 0 ;
if ( F_33 ( V_3 , V_8 , V_7 , V_68 ) != 0 ) {
if ( V_7 -> V_81 ) {
F_43 ( V_3 -> V_4 , V_8 -> V_82 ,
V_83 ,
V_84 ) ;
V_8 -> V_82 = 0 ;
}
return - V_73 ;
}
V_68 -> V_15 = F_9 ( V_3 , V_8 ) ;
F_56 () ;
V_47 -> V_50 ++ ;
return 0 ;
}
static int F_59 ( struct V_6 * V_7 , void (* F_60)( struct V_6 * ) )
{
struct V_187 * V_188 = V_7 -> V_1 -> V_188 ;
struct V_2 * V_3 = F_61 ( V_188 ) ;
struct V_5 * V_8 ;
unsigned long V_66 ;
F_62 ( & V_3 -> V_189 , V_66 ) ;
V_8 = F_3 ( V_3 , V_7 ) ;
if ( ! V_8 || F_57 ( V_3 , V_8 , V_7 ) != 0 ) {
if ( V_8 )
F_7 ( V_3 , V_8 ) ;
F_63 ( & V_3 -> V_189 , V_66 ) ;
return V_190 ;
}
V_7 -> V_162 = F_60 ;
F_26 ( & V_7 -> V_1 -> V_160 ,
L_12 , V_7 , V_8 , V_7 -> V_161 [ 0 ] ) ;
F_63 ( & V_3 -> V_189 , V_66 ) ;
F_24 ( V_3 , V_7 -> V_161 [ 0 ] ) ;
return 0 ;
}
void F_64 ( struct V_2 * V_3 )
{
unsigned V_28 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_11 ; V_28 ++ ) {
struct V_5 * V_8 = & V_3 -> V_10 [ V_28 ] ;
struct V_6 * V_7 = V_8 -> V_7 ;
if ( V_7 ) {
F_38 ( V_74 , V_7 ,
L_13 , V_7 ) ;
F_42 ( V_3 , V_8 ) ;
F_7 ( V_3 , V_8 ) ;
V_7 -> V_126 = ( V_154 << 16 ) ;
V_7 -> V_162 ( V_7 ) ;
}
}
}
static int F_65 ( struct V_6 * V_7 )
{
struct V_187 * V_188 = V_7 -> V_1 -> V_188 ;
struct V_2 * V_3 = F_61 ( V_188 ) ;
unsigned long V_66 ;
bool V_22 ;
F_38 ( V_191 , V_7 , L_14 ) ;
F_62 ( & V_3 -> V_189 , V_66 ) ;
V_22 = V_3 -> V_22 ;
if ( V_22 ) {
V_3 -> V_22 = 0 ;
F_63 ( & V_3 -> V_189 , V_66 ) ;
F_66 ( V_3 -> V_192 ) ;
F_62 ( & V_3 -> V_189 , V_66 ) ;
}
F_22 ( V_3 ) ;
F_25 ( V_3 ) ;
F_54 ( V_3 ) ;
F_64 ( V_3 ) ;
V_3 -> V_22 = V_22 ;
F_48 ( V_3 ) ;
F_17 ( V_3 ) ;
F_63 ( & V_3 -> V_189 , V_66 ) ;
return V_193 ;
}
static int F_67 ( struct V_6 * V_7 )
{
struct V_187 * V_188 = V_7 -> V_1 -> V_188 ;
struct V_2 * V_3 = F_61 ( V_188 ) ;
unsigned long V_66 ;
F_38 ( V_191 , V_7 , L_15 ) ;
F_62 ( & V_3 -> V_189 , V_66 ) ;
F_22 ( V_3 ) ;
F_27 ( V_3 ) ;
F_54 ( V_3 ) ;
F_63 ( & V_3 -> V_189 , V_66 ) ;
return V_193 ;
}
static int F_68 ( struct V_6 * V_7 )
{
struct V_187 * V_188 = V_7 -> V_1 -> V_188 ;
struct V_2 * V_3 = F_61 ( V_188 ) ;
unsigned long V_66 ;
F_38 ( V_191 , V_7 , L_16 ,
V_188 -> V_194 , V_7 -> V_1 -> V_33 ) ;
F_62 ( & V_3 -> V_189 , V_66 ) ;
F_22 ( V_3 ) ;
F_28 ( V_3 , V_7 -> V_1 -> V_33 ) ;
F_54 ( V_3 ) ;
F_63 ( & V_3 -> V_189 , V_66 ) ;
return V_193 ;
}
static const char * F_69 ( struct V_187 * V_188 )
{
struct V_2 * V_3 = F_61 ( V_188 ) ;
static char V_195 [ 256 ] ;
sprintf ( V_195 , L_17
L_18 , V_3 -> V_196 ,
V_3 -> V_87 , V_3 -> V_93 , V_3 -> V_97 ,
V_197 . V_198 ) ;
return V_195 ;
}
static void F_70 ( const struct V_2 * V_3 ,
const struct V_199 * V_68 )
{
struct V_46 * V_47 = V_3 -> V_48 ;
struct V_187 * V_188 = V_3 -> V_188 ;
struct V_116 * V_117 ;
F_71 ( V_191 L_19 ,
V_68 -> type , V_47 -> V_200 , V_47 -> V_201 , V_47 -> V_202 ) ;
F_72 ( V_203 != 2 ) ;
if ( V_68 -> type == V_204 ) {
struct V_205 * V_25 ;
V_25 = (struct V_205 * ) V_68 ;
F_71 ( V_191
L_20 ,
V_25 -> V_170 , V_25 -> V_32 , V_25 -> V_172 [ 1 ] ) ;
if ( ! F_73 ( V_188 ) )
return;
V_117 = F_74 ( V_188 , V_25 -> V_170 , V_25 -> V_32 ,
V_25 -> V_172 [ 1 ] ) ;
if ( V_117 ) {
F_71 ( V_191 L_21 ) ;
F_75 ( V_117 ) ;
} else
F_76 ( V_3 -> V_188 , V_25 -> V_170 ,
V_25 -> V_32 , V_25 -> V_172 [ 1 ] ) ;
F_77 ( V_188 ) ;
} else if ( V_68 -> type == V_206 ) {
struct V_205 * V_25 ;
V_25 = (struct V_205 * ) V_68 ;
F_71 ( V_191
L_22 ,
V_25 -> V_170 , V_25 -> V_32 , V_25 -> V_172 [ 1 ] ) ;
if ( ! F_73 ( V_188 ) )
return;
V_117 = F_74 ( V_188 , V_25 -> V_170 , V_25 -> V_32 ,
V_25 -> V_172 [ 1 ] ) ;
if ( V_117 ) {
F_78 ( V_117 ) ;
F_75 ( V_117 ) ;
} else
F_71 ( V_191
L_23 ,
V_25 -> V_170 , V_25 -> V_32 , V_25 -> V_172 [ 1 ] ) ;
F_77 ( V_188 ) ;
}
}
static int F_79 ( const struct V_2 * V_3 )
{
struct V_46 * V_47 = V_3 -> V_48 ;
return V_47 -> V_200 != V_47 -> V_201 ;
}
static void F_80 ( const struct V_2 * V_3 )
{
struct V_46 * V_47 = V_3 -> V_48 ;
struct V_199 * V_163 = V_3 -> V_100 ;
T_2 V_207 = V_47 -> V_202 ;
while ( F_79 ( V_3 ) ) {
struct V_199 * V_68 = V_163 + ( V_47 -> V_201 &
F_55 ( V_207 ) ) ;
F_56 () ;
F_70 ( V_3 , V_68 ) ;
F_56 () ;
V_47 -> V_201 ++ ;
}
}
static void F_81 ( struct V_208 * V_209 )
{
struct V_2 * V_3 ;
V_3 = F_82 ( V_209 , struct V_2 , V_210 ) ;
F_80 ( V_3 ) ;
}
static int F_83 ( struct V_2 * V_3 )
{
char V_211 [ 32 ] ;
if ( ! V_212 )
return 0 ;
F_11 ( V_3 , V_29 ,
V_115 ) ;
if ( F_13 ( V_3 , V_213 ) == - 1 )
return 0 ;
snprintf ( V_211 , sizeof( V_211 ) ,
L_24 , V_3 -> V_188 -> V_194 ) ;
V_3 -> V_192 = F_84 ( V_211 ) ;
if ( ! V_3 -> V_192 ) {
F_71 ( V_74 L_25 ) ;
return 0 ;
}
F_85 ( & V_3 -> V_210 , F_81 ) ;
return 1 ;
}
static bool F_86 ( struct V_2 * V_3 ,
bool V_214 )
{
T_2 V_17 ;
if ( ! V_215 )
return false ;
F_11 ( V_3 , V_29 ,
V_216 ) ;
V_17 = F_13 ( V_3 , V_213 ) ;
if ( V_17 == - 1 ) {
F_71 ( V_191 L_26 ) ;
return false ;
} else {
struct V_217 V_112 = { 0 } ;
V_112 . V_214 = V_214 ;
F_71 ( V_191
L_27 ,
V_214 ? L_28 : L_29 ) ;
F_19 ( V_3 ,
V_216 ,
& V_112 , sizeof( V_112 ) ) ;
return F_13 ( V_3 ,
V_213 ) != 0 ;
}
}
static T_5 F_87 ( int V_218 , void * V_219 )
{
struct V_2 * V_3 = V_219 ;
unsigned long V_66 ;
F_62 ( & V_3 -> V_189 , V_66 ) ;
F_54 ( V_3 ) ;
if ( V_3 -> V_22 && F_79 ( V_3 ) )
F_88 ( V_3 -> V_192 , & V_3 -> V_210 ) ;
F_63 ( & V_3 -> V_189 , V_66 ) ;
return V_220 ;
}
static T_5 F_89 ( int V_218 , void * V_219 )
{
struct V_2 * V_3 = V_219 ;
T_2 V_17 = F_15 ( V_3 ) ;
if ( ! ( V_17 & V_221 ) )
return V_222 ;
F_16 ( V_219 , V_17 ) ;
return F_87 ( V_218 , V_219 ) ;
}
static void F_90 ( const struct V_2 * V_3 )
{
struct V_5 * V_8 = V_3 -> V_10 ;
unsigned V_28 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_11 ; ++ V_28 , ++ V_8 )
F_91 ( ( unsigned long ) V_8 -> V_63 , F_92 ( V_77 ) ) ;
}
static void F_93 ( struct V_2 * V_3 )
{
F_94 ( F_95 ( V_3 -> V_4 , 0 ) , V_3 ) ;
F_96 ( V_3 -> V_4 ) ;
}
static void F_97 ( struct V_2 * V_3 )
{
F_93 ( V_3 ) ;
if ( V_3 -> V_192 )
F_98 ( V_3 -> V_192 ) ;
if ( V_3 -> V_18 )
F_99 ( V_3 -> V_4 , V_3 -> V_18 ) ;
F_100 ( V_3 -> V_4 ) ;
if ( V_3 -> V_10 ) {
F_90 ( V_3 ) ;
F_101 ( V_3 -> V_10 ) ;
}
if ( V_3 -> V_48 )
F_102 ( V_3 -> V_4 , V_85 ,
V_3 -> V_48 , V_3 -> V_86 ) ;
if ( V_3 -> V_91 )
F_102 ( V_3 -> V_4 ,
V_3 -> V_87 * V_85 ,
V_3 -> V_91 , V_3 -> V_92 ) ;
if ( V_3 -> V_95 )
F_102 ( V_3 -> V_4 ,
V_3 -> V_93 * V_85 ,
V_3 -> V_95 , V_3 -> V_96 ) ;
if ( V_3 -> V_100 )
F_102 ( V_3 -> V_4 ,
V_3 -> V_97 * V_85 ,
V_3 -> V_100 , V_3 -> V_101 ) ;
}
static int F_103 ( struct V_2 * V_3 )
{
struct V_5 * V_8 ;
int V_28 ;
V_8 = V_3 -> V_10 ;
F_72 ( sizeof( struct V_223 ) > V_77 ) ;
for ( V_28 = 0 ; V_28 < V_3 -> V_11 ; ++ V_28 , ++ V_8 ) {
V_8 -> V_63 = ( void * ) F_104 ( V_224 ,
F_92 ( V_77 ) ) ;
V_8 -> V_76 = 0 ;
F_30 ( ! F_47 ( ( ( unsigned long ) V_8 -> V_63 ) , V_85 ) ) ;
if ( ! V_8 -> V_63 ) {
for (; V_28 >= 0 ; -- V_28 , -- V_8 ) {
F_91 ( ( unsigned long ) V_8 -> V_63 ,
F_92 ( V_77 ) ) ;
V_8 -> V_63 = NULL ;
}
return - V_73 ;
}
}
return 0 ;
}
static T_2 F_105 ( struct V_2 * V_3 )
{
struct V_225 V_7 ;
struct V_226 * V_227 ;
struct V_1 * V_4 ;
T_4 V_228 ;
void * V_229 ;
T_2 V_230 = 16 ;
V_4 = F_1 ( V_3 ) ;
V_229 = F_45 ( V_3 -> V_4 , V_85 ,
& V_228 ) ;
if ( ! V_229 ) {
F_106 ( V_4 , L_30 ) ;
goto exit;
}
F_30 ( V_228 & ~ V_231 ) ;
V_7 . V_232 = ( ( T_1 ) V_233 ) << 32 ;
V_7 . V_234 = V_235 ;
V_7 . V_236 = V_228 ;
V_7 . V_237 = 0 ;
V_227 = V_229 ;
memset ( V_227 , 0 , sizeof *V_227 ) ;
V_227 -> V_123 = V_238 ;
V_227 -> V_125 = V_239 ;
F_19 ( V_3 , V_240 , & V_7 , sizeof V_7 ) ;
if ( V_227 -> V_123 == V_128 &&
V_227 -> V_125 == V_241 ) {
struct V_242 * V_243 ;
V_243 = V_229 ;
V_230 = V_243 -> V_230 ;
} else
F_106 ( V_4 , L_31 ,
V_227 -> V_123 , V_227 -> V_125 ) ;
F_102 ( V_3 -> V_4 , V_85 , V_229 , V_228 ) ;
exit:
return V_230 ;
}
static int F_107 ( struct V_244 * V_245 , const struct V_246 * V_33 )
{
unsigned int V_247 = V_248 | V_249 | V_250 ;
struct V_2 * V_3 ;
struct V_2 V_251 ;
struct V_187 * V_188 = NULL ;
unsigned int V_28 ;
int error ;
T_2 V_252 ;
error = - V_253 ;
if ( F_108 ( V_245 ) )
return error ;
if ( F_109 ( V_245 , F_110 ( 64 ) ) == 0 &&
F_111 ( V_245 , F_110 ( 64 ) ) == 0 ) {
F_71 ( V_191 L_32 ) ;
} else if ( F_109 ( V_245 , F_110 ( 32 ) ) == 0 &&
F_111 ( V_245 , F_110 ( 32 ) ) == 0 ) {
F_71 ( V_191 L_33 ) ;
} else {
F_71 ( V_74 L_34 ) ;
goto V_254;
}
V_3 = & V_251 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_4 = V_245 ;
V_3 -> V_196 = V_245 -> V_255 ;
if ( F_112 ( V_245 , L_35 ) ) {
F_71 ( V_74 L_36 ) ;
goto V_254;
}
for ( V_28 = 0 ; V_28 < V_256 ; V_28 ++ ) {
if ( ( F_113 ( V_245 , V_28 ) & V_257 ) )
continue;
if ( F_114 ( V_245 , V_28 ) < V_258 )
continue;
break;
}
if ( V_28 == V_256 ) {
F_71 ( V_74
L_37 ) ;
goto V_259;
}
V_3 -> V_18 = F_115 ( V_245 , V_28 , V_258 ) ;
if ( ! V_3 -> V_18 ) {
F_71 ( V_74
L_38 ,
V_28 , V_258 ) ;
goto V_259;
}
F_116 ( V_245 ) ;
V_252 = F_105 ( V_3 ) ;
F_71 ( V_191 L_39 , V_252 ) ;
if ( V_89 == 0 )
V_89 = ( V_252 > 16 ) ?
V_260 :
V_261 ;
F_71 ( V_191
L_40 ,
V_89 ) ;
V_197 . V_262 =
F_46 ( V_88 , V_89 ) *
V_90 ;
V_197 . V_198 =
F_46 ( V_197 . V_262 , V_263 ) ;
V_188 = F_117 ( & V_197 , sizeof( struct V_2 ) ) ;
if ( ! V_188 ) {
F_71 ( V_74 L_41 ) ;
goto V_259;
}
V_3 = F_61 ( V_188 ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_4 = V_245 ;
V_3 -> V_188 = V_188 ;
V_3 -> V_196 = V_251 . V_196 ;
V_3 -> V_18 = V_251 . V_18 ;
F_118 ( & V_3 -> V_189 ) ;
V_188 -> V_264 = 0 ;
V_188 -> V_265 = 1 ;
V_188 -> V_266 = 16 ;
V_188 -> V_252 = V_252 ;
F_119 ( V_245 , V_188 ) ;
F_25 ( V_3 ) ;
V_3 -> V_22 = F_83 ( V_3 ) ;
error = F_44 ( V_3 ) ;
if ( error ) {
F_71 ( V_74 L_42 ) ;
goto V_267;
}
F_48 ( V_3 ) ;
V_3 -> V_10 = F_120 ( V_3 -> V_11 ,
sizeof( struct V_5 ) , V_224 ) ;
if ( ! V_3 -> V_10 ) {
F_71 ( V_74 L_43 ) ;
error = - V_73 ;
goto V_268;
}
F_121 ( & V_3 -> V_12 ) ;
for ( V_28 = 0 ; V_28 < V_3 -> V_11 ; V_28 ++ ) {
struct V_5 * V_8 = V_3 -> V_10 + V_28 ;
F_8 ( & V_8 -> V_13 , & V_3 -> V_12 ) ;
}
error = F_103 ( V_3 ) ;
if ( error ) {
F_71 ( V_74 L_44 ) ;
goto V_268;
}
if ( V_269 )
V_247 &= ~ V_248 ;
if ( V_270 )
V_247 &= ~ V_249 ;
error = F_122 ( V_3 -> V_4 , 1 , 1 , V_247 ) ;
if ( error < 0 )
goto V_268;
V_3 -> V_49 = F_86 ( V_3 , true ) ;
F_71 ( V_159 L_45 ,
V_3 -> V_49 ? L_28 : L_29 ) ;
if ( V_3 -> V_4 -> V_271 || V_3 -> V_4 -> V_272 ) {
F_71 ( V_191 L_46 ,
V_3 -> V_4 -> V_271 ? L_47 : L_48 ) ;
error = F_123 ( F_95 ( V_245 , 0 ) , F_87 ,
0 , L_35 , V_3 ) ;
} else {
F_71 ( V_191 L_49 ) ;
error = F_123 ( F_95 ( V_245 , 0 ) , F_89 ,
V_273 , L_35 , V_3 ) ;
}
if ( error ) {
F_71 ( V_74
L_50 , error ) ;
goto V_268;
}
error = F_124 ( V_188 , & V_245 -> V_4 ) ;
if ( error ) {
F_71 ( V_74
L_51 , error ) ;
goto V_268;
}
F_125 ( & V_245 -> V_4 , L_52 ,
V_3 -> V_196 , V_188 -> V_194 ) ;
F_17 ( V_3 ) ;
F_126 ( V_188 ) ;
return 0 ;
V_268:
F_25 ( V_3 ) ;
V_267:
F_97 ( V_3 ) ;
F_77 ( V_188 ) ;
V_254:
F_127 ( V_245 ) ;
return error ;
V_259:
F_97 ( V_3 ) ;
goto V_254;
}
static void F_128 ( struct V_2 * V_3 )
{
F_18 ( V_3 ) ;
if ( V_3 -> V_192 )
F_66 ( V_3 -> V_192 ) ;
F_93 ( V_3 ) ;
F_22 ( V_3 ) ;
F_54 ( V_3 ) ;
F_25 ( V_3 ) ;
}
static void F_129 ( struct V_244 * V_4 )
{
struct V_187 * V_188 = F_130 ( V_4 ) ;
struct V_2 * V_3 = F_61 ( V_188 ) ;
F_128 ( V_3 ) ;
}
static void F_131 ( struct V_244 * V_245 )
{
struct V_187 * V_188 = F_130 ( V_245 ) ;
struct V_2 * V_3 = F_61 ( V_188 ) ;
F_132 ( V_188 ) ;
F_128 ( V_3 ) ;
F_97 ( V_3 ) ;
F_77 ( V_188 ) ;
F_127 ( V_245 ) ;
}
static int T_6 F_133 ( void )
{
F_134 ( L_53 ,
V_274 , V_275 ) ;
return F_135 ( & V_276 ) ;
}
static void T_7 F_136 ( void )
{
F_137 ( & V_276 ) ;
}
