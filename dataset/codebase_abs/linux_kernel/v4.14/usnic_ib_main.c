static int F_1 ( void * V_1 , char * V_2 , int V_3 )
{
struct V_4 * V_5 = V_1 ;
return F_2 ( V_2 , V_3 , L_1 , V_5 -> V_6 -> V_7 . V_8 ) ;
}
static void F_3 ( struct V_4 * V_5 , char * V_2 , int V_3 )
{
F_4 ( V_5 -> V_9 , V_2 , V_3 , V_5 ,
F_1 ,
V_10 , V_11 ) ;
}
void F_5 ( struct V_4 * V_5 )
{
char V_2 [ 1000 ] ;
F_3 ( V_5 , V_2 , sizeof( V_2 ) ) ;
F_6 ( L_2 , V_2 ) ;
}
static inline const char * F_7 ( unsigned long V_12 )
{
const char * V_13 [] = { L_3 , L_4 , L_5 ,
L_6 , L_7 ,
L_8 , L_9 , L_10 ,
L_11 , L_12 , L_13 ,
L_14 , L_15 ,
L_16 , L_17 ,
L_18 , L_19 , L_20 ,
L_21 , L_22
} ;
if ( V_12 >= F_8 ( V_13 ) )
return L_23 ;
else
return V_13 [ V_12 ] ;
}
static void F_9 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 ;
enum V_20 V_21 ;
int V_22 ;
F_10 ( ! F_11 ( & V_15 -> V_23 ) ) ;
F_12 (ctx, &us_ibdev->ctx_list, link) {
F_12 (qp_grp, &ctx->qp_grp_list, link) {
V_21 = V_19 -> V_24 ;
if ( V_21 == V_25 ||
V_21 == V_26 ||
V_21 == V_27 ) {
V_22 = F_13 ( V_19 ,
V_28 ,
NULL ) ;
if ( V_22 ) {
F_14 ( L_24 ,
V_19 -> V_29 ,
F_15
( V_21 ) ,
F_15
( V_28 ) ) ;
}
}
}
}
}
static void F_16 ( struct V_14 * V_15 ,
unsigned long V_12 )
{
struct V_30 * V_31 ;
struct V_32 V_32 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
F_17 ( & V_15 -> V_23 ) ;
V_31 = V_15 -> V_31 ;
switch ( V_12 ) {
case V_33 :
F_18 ( L_25 , V_15 -> V_7 . V_8 ) ;
F_9 ( V_15 ) ;
V_32 . V_12 = V_34 ;
V_32 . V_35 = & V_15 -> V_7 ;
V_32 . V_36 . V_37 = 1 ;
F_19 ( & V_32 ) ;
break;
case V_38 :
case V_39 :
case V_40 :
if ( ! V_15 -> V_41 -> V_42 &&
F_20 ( V_31 ) ) {
F_21 ( V_15 -> V_41 ) ;
F_18 ( L_26 , V_15 -> V_7 . V_8 ) ;
V_32 . V_12 = V_43 ;
V_32 . V_35 = & V_15 -> V_7 ;
V_32 . V_36 . V_37 = 1 ;
F_19 ( & V_32 ) ;
} else if ( V_15 -> V_41 -> V_42 &&
! F_20 ( V_31 ) ) {
F_22 ( V_15 -> V_41 ) ;
F_18 ( L_27 , V_15 -> V_7 . V_8 ) ;
F_9 ( V_15 ) ;
V_32 . V_12 = V_34 ;
V_32 . V_35 = & V_15 -> V_7 ;
V_32 . V_36 . V_37 = 1 ;
F_19 ( & V_32 ) ;
} else {
F_6 ( L_28 ,
F_7 ( V_12 ) ,
V_15 -> V_7 . V_8 ) ;
}
break;
case V_44 :
if ( ! memcmp ( V_15 -> V_41 -> V_45 , V_31 -> V_46 ,
sizeof( V_15 -> V_41 -> V_45 ) ) ) {
F_6 ( L_29 ,
V_15 -> V_7 . V_8 ) ;
} else {
F_18 ( L_30 ,
V_15 -> V_7 . V_8 ,
V_15 -> V_41 -> V_45 ,
V_31 -> V_46 ) ;
F_23 ( V_15 -> V_41 , V_31 -> V_46 ) ;
F_9 ( V_15 ) ;
V_32 . V_12 = V_47 ;
V_32 . V_35 = & V_15 -> V_7 ;
V_32 . V_36 . V_37 = 1 ;
F_19 ( & V_32 ) ;
}
break;
case V_48 :
if ( V_15 -> V_41 -> V_49 != V_31 -> V_49 ) {
F_18 ( L_31 ,
V_15 -> V_7 . V_8 ,
V_15 -> V_41 -> V_49 , V_31 -> V_49 ) ;
F_24 ( V_15 -> V_41 , V_31 -> V_49 ) ;
F_9 ( V_15 ) ;
} else {
F_6 ( L_32 ,
V_15 -> V_7 . V_8 ) ;
}
break;
default:
F_6 ( L_33 ,
F_7 ( V_12 ) ,
V_15 -> V_7 . V_8 ) ;
}
F_25 ( & V_15 -> V_23 ) ;
}
static int F_26 ( struct V_50 * V_51 ,
unsigned long V_12 , void * V_52 )
{
struct V_14 * V_15 ;
struct V_30 * V_31 = F_27 ( V_52 ) ;
F_17 ( & V_53 ) ;
F_12 (us_ibdev, &usnic_ib_ibdev_list, ib_dev_link) {
if ( V_15 -> V_31 == V_31 ) {
F_16 ( V_15 , V_12 ) ;
break;
}
}
F_25 ( & V_53 ) ;
return V_54 ;
}
static int F_28 ( struct V_14 * V_15 ,
unsigned long V_12 , void * V_52 )
{
struct V_55 * V_56 = V_52 ;
struct V_32 V_32 ;
F_17 ( & V_15 -> V_23 ) ;
switch ( V_12 ) {
case V_39 :
F_18 ( L_34 ,
F_7 ( V_12 ) ) ;
F_29 ( V_15 -> V_41 ) ;
F_9 ( V_15 ) ;
V_32 . V_12 = V_47 ;
V_32 . V_35 = & V_15 -> V_7 ;
V_32 . V_36 . V_37 = 1 ;
F_19 ( & V_32 ) ;
break;
case V_38 :
F_30 ( V_15 -> V_41 , V_56 -> V_57 ) ;
F_18 ( L_35 ,
F_7 ( V_12 ) ,
& V_15 -> V_41 -> V_58 ) ;
V_32 . V_12 = V_47 ;
V_32 . V_35 = & V_15 -> V_7 ;
V_32 . V_36 . V_37 = 1 ;
F_19 ( & V_32 ) ;
break;
default:
F_18 ( L_33 ,
F_7 ( V_12 ) ,
V_15 -> V_7 . V_8 ) ;
}
F_25 ( & V_15 -> V_23 ) ;
return V_54 ;
}
static int F_31 ( struct V_50 * V_51 ,
unsigned long V_12 , void * V_52 )
{
struct V_14 * V_15 ;
struct V_55 * V_56 = V_52 ;
struct V_30 * V_31 = V_56 -> V_59 -> V_60 ;
F_17 ( & V_53 ) ;
F_12 (us_ibdev, &usnic_ib_ibdev_list, ib_dev_link) {
if ( V_15 -> V_31 == V_31 ) {
F_28 ( V_15 , V_12 , V_52 ) ;
break;
}
}
F_25 ( & V_53 ) ;
return V_54 ;
}
static int F_32 ( struct V_61 * V_62 , T_1 V_37 ,
struct V_63 * V_64 )
{
struct V_65 V_66 ;
int V_67 ;
V_64 -> V_68 = V_69 ;
V_67 = F_33 ( V_62 , V_37 , & V_66 ) ;
if ( V_67 )
return V_67 ;
V_64 -> V_70 = V_66 . V_70 ;
V_64 -> V_71 = V_66 . V_71 ;
return 0 ;
}
static void F_34 ( struct V_61 * V_35 , char * V_72 )
{
struct V_14 * V_15 =
F_35 ( V_35 , struct V_14 , V_7 ) ;
struct V_73 V_74 ;
F_17 ( & V_15 -> V_23 ) ;
V_15 -> V_31 -> V_75 -> V_76 ( V_15 -> V_31 , & V_74 ) ;
F_25 ( & V_15 -> V_23 ) ;
snprintf ( V_72 , V_77 , L_36 , V_74 . V_78 ) ;
}
static void * F_36 ( struct V_79 * V_60 )
{
struct V_14 * V_15 ;
union V_80 V_81 ;
struct V_82 * V_83 ;
struct V_30 * V_31 ;
F_6 ( L_37 ) ;
V_31 = F_37 ( V_60 ) ;
V_15 = (struct V_14 * ) F_38 ( sizeof( * V_15 ) ) ;
if ( ! V_15 ) {
F_14 ( L_38 ,
F_39 ( F_37 ( V_60 ) ) ) ;
return F_40 ( - V_84 ) ;
}
V_15 -> V_41 = F_41 ( V_60 ) ;
if ( ! V_15 -> V_41 ) {
F_14 ( L_39 , F_42 ( V_60 ) ) ;
goto V_85;
}
F_43 ( & V_15 -> V_23 ) ;
F_44 ( & V_15 -> V_86 ) ;
F_44 ( & V_15 -> V_87 ) ;
V_15 -> V_88 = V_60 ;
V_15 -> V_31 = F_37 ( V_60 ) ;
V_15 -> V_7 . V_89 = V_90 ;
V_15 -> V_7 . V_91 = V_92 ;
V_15 -> V_7 . V_93 = V_94 ;
V_15 -> V_7 . V_95 = V_96 ;
V_15 -> V_7 . V_60 . V_97 = & V_60 -> V_60 ;
V_15 -> V_7 . V_98 = V_99 ;
F_45 ( V_15 -> V_7 . V_8 , L_40 , V_100 ) ;
V_15 -> V_7 . V_101 =
( 1ull << V_102 ) |
( 1ull << V_103 ) |
( 1ull << V_104 ) |
( 1ull << V_105 ) |
( 1ull << V_106 ) |
( 1ull << V_107 ) |
( 1ull << V_108 ) |
( 1ull << V_109 ) |
( 1ull << V_110 ) |
( 1ull << V_111 ) |
( 1ull << V_112 ) |
( 1ull << V_113 ) |
( 1ull << V_114 ) |
( 1ull << V_115 ) |
( 1ull << V_116 ) |
( 1ull << V_117 ) |
( 1ull << V_118 ) ;
V_15 -> V_7 . V_119 = V_120 ;
V_15 -> V_7 . V_121 = V_122 ;
V_15 -> V_7 . V_123 = V_124 ;
V_15 -> V_7 . V_125 = V_126 ;
V_15 -> V_7 . V_127 = V_128 ;
V_15 -> V_7 . V_129 = V_130 ;
V_15 -> V_7 . V_131 = V_132 ;
V_15 -> V_7 . V_133 = V_134 ;
V_15 -> V_7 . V_135 = V_136 ;
V_15 -> V_7 . V_137 = V_138 ;
V_15 -> V_7 . V_139 = V_140 ;
V_15 -> V_7 . V_141 = V_142 ;
V_15 -> V_7 . V_143 = V_144 ;
V_15 -> V_7 . V_145 = V_146 ;
V_15 -> V_7 . V_147 = V_148 ;
V_15 -> V_7 . V_149 = V_150 ;
V_15 -> V_7 . V_151 = V_152 ;
V_15 -> V_7 . V_153 = V_154 ;
V_15 -> V_7 . V_155 = V_156 ;
V_15 -> V_7 . V_157 = V_158 ;
V_15 -> V_7 . V_159 = V_160 ;
V_15 -> V_7 . V_161 = V_162 ;
V_15 -> V_7 . V_163 = V_164 ;
V_15 -> V_7 . V_165 = V_166 ;
V_15 -> V_7 . V_167 = V_168 ;
V_15 -> V_7 . V_169 = V_170 ;
V_15 -> V_7 . V_171 = F_32 ;
V_15 -> V_7 . V_172 = F_34 ;
if ( F_46 ( & V_15 -> V_7 , NULL ) )
goto V_173;
F_24 ( V_15 -> V_41 , V_15 -> V_31 -> V_49 ) ;
F_23 ( V_15 -> V_41 , V_15 -> V_31 -> V_46 ) ;
if ( F_20 ( V_15 -> V_31 ) )
F_21 ( V_15 -> V_41 ) ;
V_83 = F_47 ( V_31 ) ;
if ( V_83 -> V_174 )
F_30 ( V_15 -> V_41 ,
V_83 -> V_174 -> V_57 ) ;
F_48 ( V_83 ) ;
F_49 ( V_15 -> V_31 -> V_175 ,
V_15 -> V_41 -> V_58 , & V_81 . V_176 [ 0 ] ) ;
memcpy ( & V_15 -> V_7 . V_177 , & V_81 . V_178 . V_179 ,
sizeof( V_81 . V_178 . V_179 ) ) ;
F_50 ( & V_15 -> V_180 ) ;
F_18 ( L_41 ,
V_15 -> V_7 . V_8 , F_39 ( V_15 -> V_31 ) ,
V_15 -> V_41 -> V_45 , V_15 -> V_41 -> V_42 ,
V_15 -> V_41 -> V_49 ) ;
return V_15 ;
V_173:
F_51 ( V_15 -> V_41 ) ;
V_85:
F_14 ( L_42 ) ;
F_52 ( & V_15 -> V_7 ) ;
return NULL ;
}
static void F_53 ( struct V_14 * V_15 )
{
F_18 ( L_43 , V_15 -> V_7 . V_8 ) ;
F_54 ( V_15 ) ;
F_51 ( V_15 -> V_41 ) ;
F_55 ( & V_15 -> V_7 ) ;
F_52 ( & V_15 -> V_7 ) ;
}
static void F_56 ( struct V_181 * V_181 )
{
struct V_14 * V_15 , * V_182 ;
struct V_79 * V_60 ;
bool V_183 = false ;
V_60 = F_35 ( V_181 , struct V_14 , V_180 ) -> V_88 ;
F_17 ( & V_53 ) ;
F_57 (us_ibdev, tmp,
&usnic_ib_ibdev_list, ib_dev_link) {
if ( V_15 -> V_88 == V_60 ) {
F_58 ( & V_15 -> V_184 ) ;
F_53 ( V_15 ) ;
V_183 = true ;
break;
}
}
F_59 ( ! V_183 , L_44 , F_42 ( V_60 ) ) ;
F_25 ( & V_53 ) ;
}
static struct V_14 * F_60 ( struct V_185 * V_9 )
{
struct V_14 * V_15 ;
struct V_79 * V_186 , * V_187 ;
int V_67 ;
V_187 = F_61 ( V_9 ) ;
V_186 = F_62 ( V_187 ) ;
F_10 ( ! V_186 ) ;
F_17 ( & V_53 ) ;
F_12 (us_ibdev, &usnic_ib_ibdev_list, ib_dev_link) {
if ( V_15 -> V_88 == V_186 ) {
F_63 ( & V_15 -> V_180 ) ;
goto V_188;
}
}
V_15 = F_36 ( V_186 ) ;
if ( F_64 ( V_15 ) ) {
V_15 = V_15 ? V_15 : F_40 ( - V_84 ) ;
goto V_188;
}
V_67 = F_65 ( V_15 ) ;
if ( V_67 ) {
F_53 ( V_15 ) ;
V_15 = F_40 ( V_67 ) ;
goto V_188;
}
F_66 ( & V_15 -> V_184 , & V_189 ) ;
V_188:
F_25 ( & V_53 ) ;
return V_15 ;
}
static int F_67 ( struct V_79 * V_88 ,
const struct V_190 * V_191 )
{
int V_67 ;
struct V_14 * V_6 ;
struct V_4 * V_5 ;
enum V_192 V_193 ;
V_5 = F_68 ( sizeof( * V_5 ) , V_194 ) ;
if ( ! V_5 )
return - V_195 ;
V_67 = F_69 ( V_88 ) ;
if ( V_67 ) {
F_14 ( L_45 ,
F_42 ( V_88 ) , V_67 ) ;
goto V_196;
}
V_67 = F_70 ( V_88 , V_197 ) ;
if ( V_67 ) {
F_14 ( L_46 ,
F_42 ( V_88 ) , V_67 ) ;
goto V_198;
}
F_71 ( V_88 ) ;
F_72 ( V_88 , V_5 ) ;
V_5 -> V_9 = F_73 ( V_88 ) ;
if ( F_64 ( V_5 -> V_9 ) ) {
V_67 = V_5 -> V_9 ? F_74 ( V_5 -> V_9 ) : - V_195 ;
F_14 ( L_47 ,
F_42 ( V_88 ) , V_67 ) ;
goto V_199;
}
V_6 = F_60 ( V_5 -> V_9 ) ;
if ( F_64 ( V_6 ) ) {
F_14 ( L_48 ,
F_42 ( V_88 ) , F_74 ( V_6 ) ) ;
V_67 = V_6 ? F_74 ( V_6 ) : - V_84 ;
goto V_200;
}
V_5 -> V_6 = V_6 ;
F_75 ( & V_5 -> V_201 ) ;
F_17 ( & V_6 -> V_23 ) ;
F_76 ( & V_5 -> V_202 , & V_6 -> V_86 ) ;
for ( V_193 = V_203 + 1 ;
V_193 < V_204 ;
V_193 ++ ) {
V_6 -> V_205 [ V_193 ] = F_77 ( V_5 -> V_9 ,
V_193 ) ;
}
F_25 ( & V_6 -> V_23 ) ;
F_18 ( L_49 , F_42 ( V_88 ) ,
V_6 -> V_7 . V_8 ) ;
F_5 ( V_5 ) ;
return 0 ;
V_200:
F_78 ( V_5 -> V_9 ) ;
V_199:
F_72 ( V_88 , NULL ) ;
F_79 ( V_88 ) ;
F_80 ( V_88 ) ;
V_198:
F_81 ( V_88 ) ;
V_196:
F_82 ( V_5 ) ;
return V_67 ;
}
static void F_83 ( struct V_79 * V_88 )
{
struct V_4 * V_5 = F_37 ( V_88 ) ;
struct V_14 * V_6 = V_5 -> V_6 ;
F_17 ( & V_6 -> V_23 ) ;
F_58 ( & V_5 -> V_202 ) ;
F_25 ( & V_6 -> V_23 ) ;
F_84 ( & V_6 -> V_180 , F_56 ) ;
F_78 ( V_5 -> V_9 ) ;
F_72 ( V_88 , NULL ) ;
F_79 ( V_88 ) ;
F_80 ( V_88 ) ;
F_81 ( V_88 ) ;
F_82 ( V_5 ) ;
F_18 ( L_50 , F_42 ( V_88 ) ) ;
}
static int T_2 F_85 ( void )
{
int V_67 ;
F_86 ( V_206 L_36 , V_207 ) ;
V_67 = F_87 ( V_197 ) ;
if ( V_67 ) {
F_14 ( L_51 , V_67 ) ;
return V_67 ;
}
V_67 = F_88 ( & V_208 ) ;
if ( V_67 ) {
F_14 ( L_52 ) ;
goto V_209;
}
V_67 = F_89 ( & V_210 ) ;
if ( V_67 ) {
F_14 ( L_53 ) ;
goto V_211;
}
V_67 = F_90 ( & V_212 ) ;
if ( V_67 ) {
F_14 ( L_54 ) ;
goto V_213;
}
V_67 = F_91 () ;
if ( V_67 ) {
F_14 ( L_55 ) ;
goto V_214;
}
F_92 () ;
return 0 ;
V_214:
F_93 ( & V_212 ) ;
V_213:
F_94 ( & V_210 ) ;
V_211:
F_95 ( & V_208 ) ;
V_209:
F_96 () ;
return V_67 ;
}
static void T_3 F_97 ( void )
{
F_6 ( L_37 ) ;
F_98 () ;
F_99 () ;
F_93 ( & V_212 ) ;
F_94 ( & V_210 ) ;
F_95 ( & V_208 ) ;
F_96 () ;
}
