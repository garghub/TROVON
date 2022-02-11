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
F_8 ( & V_8 -> V_13 , & V_3 -> V_12 ) ;
}
static T_1 F_9 ( const struct V_2 * V_3 ,
const struct V_5 * V_8 )
{
return V_8 - V_3 -> V_10 + 1 ;
}
static struct V_5 *
F_10 ( const struct V_2 * V_3 , T_1 V_14 )
{
return & V_3 -> V_10 [ V_14 - 1 ] ;
}
static void F_11 ( const struct V_2 * V_3 ,
T_2 V_15 , T_2 V_16 )
{
F_12 ( V_16 , V_3 -> V_17 + V_15 ) ;
}
static T_2 F_13 ( const struct V_2 * V_3 , T_2 V_15 )
{
return F_14 ( V_3 -> V_17 + V_15 ) ;
}
static T_2 F_15 ( const struct V_2 * V_3 )
{
return F_13 ( V_3 , V_18 ) ;
}
static void F_16 ( const struct V_2 * V_3 ,
T_2 V_16 )
{
F_11 ( V_3 , V_18 , V_16 ) ;
}
static void F_17 ( const struct V_2 * V_3 )
{
T_2 V_19 ;
V_19 = V_20 ;
if ( V_3 -> V_21 )
V_19 |= V_22 ;
F_11 ( V_3 , V_23 , V_19 ) ;
}
static void F_18 ( const struct V_2 * V_3 )
{
F_11 ( V_3 , V_23 , 0 ) ;
}
static void F_19 ( const struct V_2 * V_3 ,
T_2 V_7 , const void * V_24 , T_3 V_25 )
{
const T_2 * V_26 = V_24 ;
T_3 V_27 ;
V_25 /= sizeof( * V_26 ) ;
F_11 ( V_3 , V_28 , V_7 ) ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ )
F_11 ( V_3 ,
V_29 , V_26 [ V_27 ] ) ;
}
static void F_20 ( const struct V_2 * V_3 ,
const struct V_5 * V_8 )
{
struct V_30 V_7 = { 0 } ;
V_7 . V_31 = V_8 -> V_7 -> V_1 -> V_32 ;
V_7 . V_14 = F_9 ( V_3 , V_8 ) ;
F_19 ( V_3 , V_33 , & V_7 , sizeof( V_7 ) ) ;
}
static void F_21 ( const struct V_2 * V_3 )
{
F_11 ( V_3 , V_34 , 0 ) ;
}
static void F_22 ( const struct V_2 * V_3 )
{
F_11 ( V_3 , V_35 , 0 ) ;
}
static int F_23 ( unsigned char V_36 )
{
return V_36 == V_37 || V_36 == V_38 ||
V_36 == V_39 || V_36 == V_40 ||
V_36 == V_41 || V_36 == V_42 ||
V_36 == V_43 || V_36 == V_44 ;
}
static void F_24 ( const struct V_2 * V_3 ,
unsigned char V_36 )
{
if ( F_23 ( V_36 ) )
F_21 ( V_3 ) ;
else
F_22 ( V_3 ) ;
}
static void F_25 ( const struct V_2 * V_3 )
{
F_26 ( F_1 ( V_3 ) , L_1 , V_3 ) ;
F_19 ( V_3 , V_45 , NULL , 0 ) ;
}
static void F_27 ( const struct V_2 * V_3 )
{
F_26 ( F_1 ( V_3 ) , L_2 , V_3 ) ;
F_19 ( V_3 , V_46 , NULL , 0 ) ;
}
static void F_28 ( const struct V_2 * V_3 , T_2 V_31 )
{
struct V_47 V_7 = { 0 } ;
F_26 ( F_1 ( V_3 ) , L_3 , V_31 ) ;
V_7 . V_31 = V_31 ;
F_19 ( V_3 , V_48 ,
& V_7 , sizeof( V_7 ) ) ;
}
static void F_29 ( struct V_5 * V_8 ,
struct V_49 * V_50 , unsigned V_51 )
{
unsigned V_27 ;
struct V_52 * V_53 ;
F_30 ( V_51 > V_54 ) ;
V_53 = & V_8 -> V_55 -> V_53 [ 0 ] ;
for ( V_27 = 0 ; V_27 < V_51 ; V_27 ++ , V_50 ++ ) {
V_53 [ V_27 ] . V_56 = F_31 ( V_50 ) ;
V_53 [ V_27 ] . V_57 = F_32 ( V_50 ) ;
V_53 [ V_27 ] . V_58 = 0 ;
}
}
static void F_33 ( struct V_2 * V_3 ,
struct V_5 * V_8 , struct V_6 * V_7 ,
struct V_59 * V_60 )
{
unsigned V_51 ;
unsigned V_61 = F_34 ( V_7 ) ;
struct V_49 * V_50 ;
V_60 -> V_62 = V_61 ;
V_60 -> V_63 = 0 ;
if ( V_61 == 0 )
return;
V_50 = F_35 ( V_7 ) ;
V_51 = F_36 ( V_7 ) ;
if ( V_51 != 0 ) {
int V_64 = F_37 ( V_7 ) ;
if ( V_64 > 1 ) {
F_29 ( V_8 , V_50 , V_64 ) ;
V_60 -> V_58 |= V_65 ;
V_8 -> V_66 = F_38 ( V_3 -> V_4 , V_8 -> V_55 ,
V_67 , V_68 ) ;
V_60 -> V_63 = V_8 -> V_66 ;
} else
V_60 -> V_63 = F_31 ( V_50 ) ;
} else {
V_8 -> V_69 = F_38 ( V_3 -> V_4 , V_50 , V_61 ,
V_7 -> V_70 ) ;
V_60 -> V_63 = V_8 -> V_69 ;
}
}
static void F_39 ( const struct V_2 * V_3 ,
struct V_5 * V_8 )
{
struct V_6 * V_7 ;
unsigned V_61 ;
V_7 = V_8 -> V_7 ;
V_61 = F_34 ( V_7 ) ;
if ( V_61 != 0 ) {
unsigned V_51 = F_36 ( V_7 ) ;
if ( V_51 != 0 ) {
F_40 ( V_7 ) ;
if ( V_8 -> V_66 ) {
F_41 ( V_3 -> V_4 , V_8 -> V_66 ,
V_67 , V_68 ) ;
V_8 -> V_66 = 0 ;
}
} else
F_41 ( V_3 -> V_4 , V_8 -> V_69 , V_61 ,
V_7 -> V_70 ) ;
}
if ( V_7 -> V_71 )
F_41 ( V_3 -> V_4 , V_8 -> V_72 ,
V_73 , V_74 ) ;
}
static int T_4 F_42 ( struct V_2 * V_3 )
{
V_3 -> V_75 = F_43 ( V_3 -> V_4 , V_76 ,
& V_3 -> V_77 ) ;
if ( ! V_3 -> V_75 )
return - V_78 ;
V_3 -> V_79 = F_44 ( V_80 ,
V_81 ) ;
V_3 -> V_11 = V_3 -> V_79
* V_82 ;
V_3 -> V_83 = F_43 ( V_3 -> V_4 ,
V_3 -> V_79 * V_76 ,
& V_3 -> V_84 ) ;
if ( ! V_3 -> V_83 )
return - V_78 ;
V_3 -> V_85 = F_44 ( V_86 ,
V_81 ) ;
V_3 -> V_87 = F_43 ( V_3 -> V_4 ,
V_3 -> V_85 * V_76 ,
& V_3 -> V_88 ) ;
if ( ! V_3 -> V_87 )
return - V_78 ;
F_30 ( ! F_45 ( V_3 -> V_77 , V_76 ) ) ;
F_30 ( ! F_45 ( V_3 -> V_84 , V_76 ) ) ;
F_30 ( ! F_45 ( V_3 -> V_88 , V_76 ) ) ;
if ( ! V_3 -> V_21 )
return 0 ;
V_3 -> V_89 = F_44 ( V_90 ,
V_91 ) ;
V_3 -> V_92 = F_43 ( V_3 -> V_4 ,
V_3 -> V_89 * V_76 ,
& V_3 -> V_93 ) ;
if ( ! V_3 -> V_92 )
return - V_78 ;
F_30 ( ! F_45 ( V_3 -> V_93 , V_76 ) ) ;
return 0 ;
}
static void F_46 ( const struct V_2 * V_3 )
{
struct V_94 V_7 = { 0 } ;
T_5 V_95 ;
unsigned V_27 ;
V_7 . V_96 = V_3 -> V_77 >> V_97 ;
V_7 . V_98 = V_3 -> V_79 ;
V_7 . V_99 = V_3 -> V_85 ;
V_95 = V_3 -> V_84 ;
for ( V_27 = 0 ; V_27 < V_3 -> V_79 ; V_27 ++ ) {
V_7 . V_100 [ V_27 ] = V_95 >> V_97 ;
V_95 += V_76 ;
}
V_95 = V_3 -> V_88 ;
for ( V_27 = 0 ; V_27 < V_3 -> V_85 ; V_27 ++ ) {
V_7 . V_101 [ V_27 ] = V_95 >> V_97 ;
V_95 += V_76 ;
}
memset ( V_3 -> V_75 , 0 , V_76 ) ;
memset ( V_3 -> V_83 , 0 , V_3 -> V_79 * V_76 ) ;
memset ( V_3 -> V_87 , 0 , V_3 -> V_85 * V_76 ) ;
F_19 ( V_3 , V_102 ,
& V_7 , sizeof( V_7 ) ) ;
if ( V_3 -> V_21 ) {
struct V_103 V_104 = { 0 } ;
V_104 . V_105 = V_3 -> V_89 ;
V_95 = V_3 -> V_93 ;
for ( V_27 = 0 ; V_27 < V_3 -> V_89 ; V_27 ++ ) {
V_104 . V_106 [ V_27 ] = V_95 >> V_97 ;
V_95 += V_76 ;
}
memset ( V_3 -> V_92 , 0 , V_3 -> V_89 * V_76 ) ;
F_19 ( V_3 , V_107 ,
& V_104 , sizeof( V_104 ) ) ;
}
}
static void F_47 ( struct V_2 * V_3 ,
const struct V_108 * V_60 )
{
struct V_5 * V_8 ;
struct V_6 * V_7 ;
T_2 V_109 = V_60 -> V_110 ;
T_2 V_111 = V_60 -> V_112 ;
V_8 = F_10 ( V_3 , V_60 -> V_14 ) ;
V_7 = V_8 -> V_7 ;
F_39 ( V_3 , V_8 ) ;
F_7 ( V_3 , V_8 ) ;
V_7 -> V_113 = 0 ;
if ( V_111 != V_114 &&
( V_109 == V_115 ||
V_109 == V_116 ||
V_109 == V_117 ) ) {
V_7 -> V_113 = ( V_118 << 16 ) | V_111 ;
if ( V_111 == V_119 && V_7 -> V_71 )
V_7 -> V_113 |= ( V_120 << 24 ) ;
} else
switch ( V_109 ) {
case V_115 :
case V_116 :
case V_117 :
V_7 -> V_113 = ( V_118 << 16 ) ;
break;
case V_121 :
case V_122 :
F_48 ( V_7 , F_34 ( V_7 ) - V_60 -> V_62 ) ;
V_7 -> V_113 = ( V_123 << 16 ) ;
break;
case V_124 :
V_7 -> V_113 = ( V_125 << 16 ) ;
break;
case V_126 :
case V_127 :
case V_128 :
V_7 -> V_113 = ( V_129 << 24 ) ;
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
V_7 -> V_113 |= ( V_123 << 16 ) ;
break;
case V_138 :
case V_139 :
case V_140 :
V_7 -> V_113 = ( V_141 << 16 ) ;
break;
case V_142 :
V_7 -> V_113 = ( V_143 << 16 ) ;
break;
case V_144 :
V_7 -> V_113 = ( V_145 << 16 ) ;
break;
default:
V_7 -> V_113 = ( V_123 << 16 ) ;
F_49 ( V_146 , V_7 ,
L_4 ,
V_109 ) ;
}
F_26 ( & V_7 -> V_1 -> V_147 ,
L_5 ,
V_7 , V_7 -> V_148 [ 0 ] , V_8 , V_7 -> V_113 , V_109 , V_111 ) ;
V_7 -> V_149 ( V_7 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_150 * V_151 = V_3 -> V_75 ;
struct V_108 * V_152 = V_3 -> V_87 ;
T_2 V_153 = V_151 -> V_154 ;
while ( V_151 -> V_155 != V_151 -> V_156 ) {
struct V_108 * V_60 = V_152 + ( V_151 -> V_155 &
F_51 ( V_153 ) ) ;
F_52 () ;
F_47 ( V_3 , V_60 ) ;
F_52 () ;
V_151 -> V_155 ++ ;
}
}
static int F_53 ( struct V_2 * V_3 ,
struct V_5 * V_8 , struct V_6 * V_7 )
{
struct V_150 * V_151 ;
struct V_59 * V_60 ;
struct V_157 * V_158 ;
T_2 V_159 ;
V_151 = V_3 -> V_75 ;
V_158 = V_7 -> V_1 ;
V_159 = V_151 -> V_160 ;
if ( V_151 -> V_161 - V_151 -> V_155 >= 1 << V_159 ) {
F_49 ( V_162 , V_7 , L_6
L_7 ,
V_151 -> V_161 , V_151 -> V_155 ) ;
return - 1 ;
}
V_60 = V_3 -> V_83 + ( V_151 -> V_161 & F_51 ( V_159 ) ) ;
V_60 -> V_163 = V_158 -> V_164 ;
V_60 -> V_31 = V_158 -> V_32 ;
memset ( V_60 -> V_165 , 0 , sizeof( V_60 -> V_165 ) ) ;
V_60 -> V_165 [ 1 ] = V_158 -> V_165 ;
if ( V_7 -> V_71 ) {
V_8 -> V_72 = F_38 ( V_3 -> V_4 , V_7 -> V_71 ,
V_73 ,
V_74 ) ;
V_60 -> V_166 = V_8 -> V_72 ;
V_60 -> V_167 = V_73 ;
} else {
V_60 -> V_167 = 0 ;
V_60 -> V_166 = 0 ;
}
V_60 -> V_168 = V_7 -> V_169 ;
V_60 -> V_170 = F_54 () ;
memcpy ( V_60 -> V_171 , V_7 -> V_148 , V_60 -> V_168 ) ;
V_60 -> V_172 = V_173 ;
if ( V_158 -> V_174 &&
( V_7 -> V_172 == V_175 ||
V_7 -> V_172 == V_176 ) )
V_60 -> V_172 = V_7 -> V_172 ;
if ( V_7 -> V_70 == V_177 )
V_60 -> V_58 = V_178 ;
else if ( V_7 -> V_70 == V_179 )
V_60 -> V_58 = V_180 ;
else if ( V_7 -> V_70 == V_181 )
V_60 -> V_58 = V_182 ;
else
V_60 -> V_58 = 0 ;
F_33 ( V_3 , V_8 , V_7 , V_60 ) ;
V_60 -> V_14 = F_9 ( V_3 , V_8 ) ;
F_52 () ;
V_151 -> V_161 ++ ;
return 0 ;
}
static int F_55 ( struct V_6 * V_7 , void (* F_56)( struct V_6 * ) )
{
struct V_183 * V_184 = V_7 -> V_1 -> V_184 ;
struct V_2 * V_3 = F_57 ( V_184 ) ;
struct V_5 * V_8 ;
unsigned long V_58 ;
F_58 ( & V_3 -> V_185 , V_58 ) ;
V_8 = F_3 ( V_3 , V_7 ) ;
if ( ! V_8 || F_53 ( V_3 , V_8 , V_7 ) != 0 ) {
if ( V_8 )
F_7 ( V_3 , V_8 ) ;
F_59 ( & V_3 -> V_185 , V_58 ) ;
return V_186 ;
}
V_7 -> V_149 = F_56 ;
F_26 ( & V_7 -> V_1 -> V_147 ,
L_8 , V_7 , V_8 , V_7 -> V_148 [ 0 ] ) ;
F_59 ( & V_3 -> V_185 , V_58 ) ;
F_24 ( V_3 , V_7 -> V_148 [ 0 ] ) ;
return 0 ;
}
void F_60 ( struct V_2 * V_3 )
{
unsigned V_27 ;
for ( V_27 = 0 ; V_27 < V_3 -> V_11 ; V_27 ++ ) {
struct V_5 * V_8 = & V_3 -> V_10 [ V_27 ] ;
struct V_6 * V_7 = V_8 -> V_7 ;
if ( V_7 ) {
F_49 ( V_162 , V_7 ,
L_9 , V_7 ) ;
F_39 ( V_3 , V_8 ) ;
F_7 ( V_3 , V_8 ) ;
V_7 -> V_113 = ( V_141 << 16 ) ;
V_7 -> V_149 ( V_7 ) ;
}
}
}
static int F_61 ( struct V_6 * V_7 )
{
struct V_183 * V_184 = V_7 -> V_1 -> V_184 ;
struct V_2 * V_3 = F_57 ( V_184 ) ;
unsigned long V_58 ;
bool V_21 ;
F_49 ( V_187 , V_7 , L_10 ) ;
F_58 ( & V_3 -> V_185 , V_58 ) ;
V_21 = V_3 -> V_21 ;
if ( V_21 ) {
V_3 -> V_21 = 0 ;
F_59 ( & V_3 -> V_185 , V_58 ) ;
F_62 ( V_3 -> V_188 ) ;
F_58 ( & V_3 -> V_185 , V_58 ) ;
}
F_22 ( V_3 ) ;
F_25 ( V_3 ) ;
F_50 ( V_3 ) ;
F_60 ( V_3 ) ;
V_3 -> V_21 = V_21 ;
F_46 ( V_3 ) ;
F_17 ( V_3 ) ;
F_59 ( & V_3 -> V_185 , V_58 ) ;
return V_189 ;
}
static int F_63 ( struct V_6 * V_7 )
{
struct V_183 * V_184 = V_7 -> V_1 -> V_184 ;
struct V_2 * V_3 = F_57 ( V_184 ) ;
unsigned long V_58 ;
F_49 ( V_187 , V_7 , L_11 ) ;
F_58 ( & V_3 -> V_185 , V_58 ) ;
F_22 ( V_3 ) ;
F_27 ( V_3 ) ;
F_50 ( V_3 ) ;
F_59 ( & V_3 -> V_185 , V_58 ) ;
return V_189 ;
}
static int F_64 ( struct V_6 * V_7 )
{
struct V_183 * V_184 = V_7 -> V_1 -> V_184 ;
struct V_2 * V_3 = F_57 ( V_184 ) ;
unsigned long V_58 ;
F_49 ( V_187 , V_7 , L_12 ,
V_184 -> V_190 , V_7 -> V_1 -> V_32 ) ;
F_58 ( & V_3 -> V_185 , V_58 ) ;
F_22 ( V_3 ) ;
F_28 ( V_3 , V_7 -> V_1 -> V_32 ) ;
F_50 ( V_3 ) ;
F_59 ( & V_3 -> V_185 , V_58 ) ;
return V_189 ;
}
static const char * F_65 ( struct V_183 * V_184 )
{
struct V_2 * V_3 = F_57 ( V_184 ) ;
static char V_191 [ 256 ] ;
sprintf ( V_191 , L_13
L_14 , V_3 -> V_192 ,
V_3 -> V_79 , V_3 -> V_85 , V_3 -> V_89 ,
V_193 . V_194 ) ;
return V_191 ;
}
static void F_66 ( const struct V_2 * V_3 ,
const struct V_195 * V_60 )
{
struct V_150 * V_151 = V_3 -> V_75 ;
struct V_183 * V_184 = V_3 -> V_184 ;
struct V_157 * V_158 ;
F_67 ( V_187 L_15 ,
V_60 -> type , V_151 -> V_196 , V_151 -> V_197 , V_151 -> V_198 ) ;
F_68 ( V_199 != 2 ) ;
if ( V_60 -> type == V_200 ) {
struct V_201 * V_24 ;
V_24 = (struct V_201 * ) V_60 ;
F_67 ( V_187
L_16 ,
V_24 -> V_163 , V_24 -> V_31 , V_24 -> V_165 [ 1 ] ) ;
if ( ! F_69 ( V_184 ) )
return;
V_158 = F_70 ( V_184 , V_24 -> V_163 , V_24 -> V_31 ,
V_24 -> V_165 [ 1 ] ) ;
if ( V_158 ) {
F_67 ( V_187 L_17 ) ;
F_71 ( V_158 ) ;
} else
F_72 ( V_3 -> V_184 , V_24 -> V_163 ,
V_24 -> V_31 , V_24 -> V_165 [ 1 ] ) ;
F_73 ( V_184 ) ;
} else if ( V_60 -> type == V_202 ) {
struct V_201 * V_24 ;
V_24 = (struct V_201 * ) V_60 ;
F_67 ( V_187
L_18 ,
V_24 -> V_163 , V_24 -> V_31 , V_24 -> V_165 [ 1 ] ) ;
if ( ! F_69 ( V_184 ) )
return;
V_158 = F_70 ( V_184 , V_24 -> V_163 , V_24 -> V_31 ,
V_24 -> V_165 [ 1 ] ) ;
if ( V_158 ) {
F_74 ( V_158 ) ;
F_71 ( V_158 ) ;
} else
F_67 ( V_187
L_19 ,
V_24 -> V_163 , V_24 -> V_31 , V_24 -> V_165 [ 1 ] ) ;
F_73 ( V_184 ) ;
}
}
static int F_75 ( const struct V_2 * V_3 )
{
struct V_150 * V_151 = V_3 -> V_75 ;
return V_151 -> V_196 != V_151 -> V_197 ;
}
static void F_76 ( const struct V_2 * V_3 )
{
struct V_150 * V_151 = V_3 -> V_75 ;
struct V_195 * V_152 = V_3 -> V_92 ;
T_2 V_203 = V_151 -> V_198 ;
while ( F_75 ( V_3 ) ) {
struct V_195 * V_60 = V_152 + ( V_151 -> V_197 &
F_51 ( V_203 ) ) ;
F_52 () ;
F_66 ( V_3 , V_60 ) ;
F_52 () ;
V_151 -> V_197 ++ ;
}
}
static void F_77 ( struct V_204 * V_205 )
{
struct V_2 * V_3 ;
V_3 = F_78 ( V_205 , struct V_2 , V_206 ) ;
F_76 ( V_3 ) ;
}
static int F_79 ( struct V_2 * V_3 )
{
char V_207 [ 32 ] ;
if ( ! V_208 )
return 0 ;
F_11 ( V_3 , V_28 ,
V_107 ) ;
if ( F_13 ( V_3 , V_209 ) == - 1 )
return 0 ;
snprintf ( V_207 , sizeof( V_207 ) ,
L_20 , V_3 -> V_184 -> V_190 ) ;
V_3 -> V_188 = F_80 ( V_207 ) ;
if ( ! V_3 -> V_188 ) {
F_67 ( V_162 L_21 ) ;
return 0 ;
}
F_81 ( & V_3 -> V_206 , F_77 ) ;
return 1 ;
}
static T_6 F_82 ( int V_210 , void * V_211 )
{
struct V_2 * V_3 = V_211 ;
int V_212 ;
if ( V_3 -> V_213 || V_3 -> V_214 )
V_212 = true ;
else {
T_2 V_16 = F_15 ( V_3 ) ;
V_212 = ( V_16 & V_215 ) != 0 ;
if ( V_212 )
F_16 ( V_211 , V_16 ) ;
}
if ( V_212 ) {
unsigned long V_58 ;
F_58 ( & V_3 -> V_185 , V_58 ) ;
F_50 ( V_3 ) ;
if ( V_3 -> V_21 && F_75 ( V_3 ) )
F_83 ( V_3 -> V_188 , & V_3 -> V_206 ) ;
F_59 ( & V_3 -> V_185 , V_58 ) ;
}
return F_84 ( V_212 ) ;
}
static void F_85 ( const struct V_2 * V_3 )
{
struct V_5 * V_8 = V_3 -> V_10 ;
unsigned V_27 ;
for ( V_27 = 0 ; V_27 < V_3 -> V_11 ; ++ V_27 , ++ V_8 )
F_86 ( ( unsigned long ) V_8 -> V_55 , F_87 ( V_67 ) ) ;
}
static int F_88 ( const struct V_2 * V_3 ,
unsigned int * V_210 )
{
struct V_216 V_217 = { 0 , V_218 } ;
int V_219 ;
V_219 = F_89 ( V_3 -> V_4 , & V_217 , 1 ) ;
if ( V_219 )
return V_219 ;
* V_210 = V_217 . V_220 ;
return 0 ;
}
static void F_90 ( struct V_2 * V_3 )
{
if ( V_3 -> V_210 ) {
F_91 ( V_3 -> V_210 , V_3 ) ;
V_3 -> V_210 = 0 ;
}
if ( V_3 -> V_213 ) {
F_92 ( V_3 -> V_4 ) ;
V_3 -> V_213 = 0 ;
} else if ( V_3 -> V_214 ) {
F_93 ( V_3 -> V_4 ) ;
V_3 -> V_214 = 0 ;
}
}
static void F_94 ( struct V_2 * V_3 )
{
F_90 ( V_3 ) ;
if ( V_3 -> V_188 )
F_95 ( V_3 -> V_188 ) ;
if ( V_3 -> V_17 )
F_96 ( V_3 -> V_4 , V_3 -> V_17 ) ;
F_97 ( V_3 -> V_4 ) ;
if ( V_3 -> V_10 ) {
F_85 ( V_3 ) ;
F_98 ( V_3 -> V_10 ) ;
}
if ( V_3 -> V_75 )
F_99 ( V_3 -> V_4 , V_76 ,
V_3 -> V_75 , V_3 -> V_77 ) ;
if ( V_3 -> V_83 )
F_99 ( V_3 -> V_4 ,
V_3 -> V_79 * V_76 ,
V_3 -> V_83 , V_3 -> V_84 ) ;
if ( V_3 -> V_87 )
F_99 ( V_3 -> V_4 ,
V_3 -> V_85 * V_76 ,
V_3 -> V_87 , V_3 -> V_88 ) ;
if ( V_3 -> V_92 )
F_99 ( V_3 -> V_4 ,
V_3 -> V_89 * V_76 ,
V_3 -> V_92 , V_3 -> V_93 ) ;
}
static int T_4 F_100 ( struct V_2 * V_3 )
{
struct V_5 * V_8 ;
int V_27 ;
V_8 = V_3 -> V_10 ;
F_68 ( sizeof( struct V_221 ) > V_67 ) ;
for ( V_27 = 0 ; V_27 < V_3 -> V_11 ; ++ V_27 , ++ V_8 ) {
V_8 -> V_55 = ( void * ) F_101 ( V_222 ,
F_87 ( V_67 ) ) ;
V_8 -> V_66 = 0 ;
F_30 ( ! F_45 ( ( ( unsigned long ) V_8 -> V_55 ) , V_76 ) ) ;
if ( ! V_8 -> V_55 ) {
for (; V_27 >= 0 ; -- V_27 , -- V_8 ) {
F_86 ( ( unsigned long ) V_8 -> V_55 ,
F_87 ( V_67 ) ) ;
V_8 -> V_55 = NULL ;
}
return - V_78 ;
}
}
return 0 ;
}
static int T_4 F_102 ( struct V_223 * V_224 ,
const struct V_225 * V_32 )
{
struct V_2 * V_3 ;
struct V_183 * V_184 ;
unsigned int V_27 ;
unsigned long V_58 = 0 ;
int error ;
error = - V_226 ;
if ( F_103 ( V_224 ) )
return error ;
if ( F_104 ( V_224 , F_105 ( 64 ) ) == 0 &&
F_106 ( V_224 , F_105 ( 64 ) ) == 0 ) {
F_67 ( V_187 L_22 ) ;
} else if ( F_104 ( V_224 , F_105 ( 32 ) ) == 0 &&
F_106 ( V_224 , F_105 ( 32 ) ) == 0 ) {
F_67 ( V_187 L_23 ) ;
} else {
F_67 ( V_162 L_24 ) ;
goto V_227;
}
V_193 . V_228 =
F_44 ( V_80 , V_81 ) *
V_82 ;
V_193 . V_194 =
F_44 ( V_193 . V_228 , V_229 ) ;
V_184 = F_107 ( & V_193 , sizeof( struct V_2 ) ) ;
if ( ! V_184 ) {
F_67 ( V_162 L_25 ) ;
goto V_227;
}
V_3 = F_57 ( V_184 ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_4 = V_224 ;
V_3 -> V_184 = V_184 ;
F_108 ( & V_3 -> V_185 ) ;
V_184 -> V_230 = 0 ;
V_184 -> V_231 = 16 ;
V_184 -> V_232 = 1 ;
V_184 -> V_233 = 16 ;
V_3 -> V_192 = V_224 -> V_234 ;
if ( F_109 ( V_224 , L_26 ) ) {
F_67 ( V_162 L_27 ) ;
goto V_235;
}
for ( V_27 = 0 ; V_27 < V_236 ; V_27 ++ ) {
if ( ( F_110 ( V_224 , V_27 ) & V_237 ) )
continue;
if ( F_111 ( V_224 , V_27 ) < V_238 )
continue;
break;
}
if ( V_27 == V_236 ) {
F_67 ( V_162
L_28 ) ;
goto V_239;
}
V_3 -> V_17 = F_112 ( V_224 , V_27 , V_238 ) ;
if ( ! V_3 -> V_17 ) {
F_67 ( V_162
L_29 ,
V_27 , V_238 ) ;
goto V_239;
}
F_113 ( V_224 ) ;
F_114 ( V_224 , V_184 ) ;
F_25 ( V_3 ) ;
V_3 -> V_21 = F_79 ( V_3 ) ;
error = F_42 ( V_3 ) ;
if ( error ) {
F_67 ( V_162 L_30 ) ;
goto V_239;
}
F_46 ( V_3 ) ;
V_3 -> V_10 = F_115 ( V_3 -> V_11 ,
sizeof( struct V_5 ) , V_222 ) ;
if ( ! V_3 -> V_10 ) {
F_67 ( V_162 L_31 ) ;
error = - V_78 ;
goto V_240;
}
F_116 ( & V_3 -> V_12 ) ;
for ( V_27 = 0 ; V_27 < V_3 -> V_11 ; V_27 ++ ) {
struct V_5 * V_8 = V_3 -> V_10 + V_27 ;
F_8 ( & V_8 -> V_13 , & V_3 -> V_12 ) ;
}
error = F_100 ( V_3 ) ;
if ( error ) {
F_67 ( V_162 L_32 ) ;
goto V_240;
}
if ( ! V_241 &&
F_88 ( V_3 , & V_3 -> V_210 ) == 0 ) {
F_67 ( V_187 L_33 ) ;
V_3 -> V_214 = 1 ;
} else if ( ! V_242 && F_117 ( V_224 ) == 0 ) {
F_67 ( V_187 L_34 ) ;
V_3 -> V_213 = 1 ;
V_3 -> V_210 = V_224 -> V_210 ;
} else {
F_67 ( V_187 L_35 ) ;
V_3 -> V_210 = V_224 -> V_210 ;
V_58 = V_243 ;
}
error = F_118 ( V_3 -> V_210 , F_82 , V_58 ,
L_26 , V_3 ) ;
if ( error ) {
F_67 ( V_162
L_36 , error ) ;
V_3 -> V_210 = 0 ;
goto V_240;
}
error = F_119 ( V_184 , & V_224 -> V_4 ) ;
if ( error ) {
F_67 ( V_162
L_37 , error ) ;
goto V_240;
}
F_120 ( & V_224 -> V_4 , L_38 ,
V_3 -> V_192 , V_184 -> V_190 ) ;
F_17 ( V_3 ) ;
F_121 ( V_184 ) ;
return 0 ;
V_240:
F_25 ( V_3 ) ;
V_239:
F_94 ( V_3 ) ;
V_235:
F_73 ( V_184 ) ;
V_227:
F_114 ( V_224 , NULL ) ;
F_122 ( V_224 ) ;
return error ;
}
static void F_123 ( struct V_2 * V_3 )
{
F_18 ( V_3 ) ;
if ( V_3 -> V_188 )
F_62 ( V_3 -> V_188 ) ;
F_90 ( V_3 ) ;
F_22 ( V_3 ) ;
F_50 ( V_3 ) ;
F_25 ( V_3 ) ;
}
static void F_124 ( struct V_223 * V_4 )
{
struct V_183 * V_184 = F_125 ( V_4 ) ;
struct V_2 * V_3 = F_57 ( V_184 ) ;
F_123 ( V_3 ) ;
}
static void F_126 ( struct V_223 * V_224 )
{
struct V_183 * V_184 = F_125 ( V_224 ) ;
struct V_2 * V_3 = F_57 ( V_184 ) ;
F_127 ( V_184 ) ;
F_123 ( V_3 ) ;
F_94 ( V_3 ) ;
F_73 ( V_184 ) ;
F_114 ( V_224 , NULL ) ;
F_122 ( V_224 ) ;
}
static int T_7 F_128 ( void )
{
F_129 ( L_39 ,
V_244 , V_245 ) ;
return F_130 ( & V_246 ) ;
}
static void T_8 F_131 ( void )
{
F_132 ( & V_246 ) ;
}
