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
V_67 = F_33 ( V_62 , V_37 , & V_66 ) ;
if ( V_67 )
return V_67 ;
V_64 -> V_68 = V_66 . V_68 ;
V_64 -> V_69 = V_66 . V_69 ;
return 0 ;
}
static void * F_34 ( struct V_70 * V_60 )
{
struct V_14 * V_15 ;
union V_71 V_72 ;
struct V_55 * V_73 ;
struct V_30 * V_31 ;
F_6 ( L_36 ) ;
V_31 = F_35 ( V_60 ) ;
V_15 = (struct V_14 * ) F_36 ( sizeof( * V_15 ) ) ;
if ( ! V_15 ) {
F_14 ( L_37 ,
F_37 ( F_35 ( V_60 ) ) ) ;
return F_38 ( - V_74 ) ;
}
V_15 -> V_41 = F_39 ( V_60 ) ;
if ( ! V_15 -> V_41 ) {
F_14 ( L_38 , F_40 ( V_60 ) ) ;
goto V_75;
}
F_41 ( & V_15 -> V_23 ) ;
F_42 ( & V_15 -> V_76 ) ;
F_42 ( & V_15 -> V_77 ) ;
V_15 -> V_78 = V_60 ;
V_15 -> V_31 = F_35 ( V_60 ) ;
V_15 -> V_7 . V_79 = V_80 ;
V_15 -> V_7 . V_81 = V_82 ;
V_15 -> V_7 . V_83 = V_84 ;
V_15 -> V_7 . V_85 = V_86 ;
V_15 -> V_7 . V_87 = & V_60 -> V_60 ;
V_15 -> V_7 . V_88 = V_89 ;
F_43 ( V_15 -> V_7 . V_8 , L_39 , V_90 ) ;
V_15 -> V_7 . V_91 =
( 1ull << V_92 ) |
( 1ull << V_93 ) |
( 1ull << V_94 ) |
( 1ull << V_95 ) |
( 1ull << V_96 ) |
( 1ull << V_97 ) |
( 1ull << V_98 ) |
( 1ull << V_99 ) |
( 1ull << V_100 ) |
( 1ull << V_101 ) |
( 1ull << V_102 ) |
( 1ull << V_103 ) |
( 1ull << V_104 ) |
( 1ull << V_105 ) |
( 1ull << V_106 ) |
( 1ull << V_107 ) |
( 1ull << V_108 ) ;
V_15 -> V_7 . V_109 = V_110 ;
V_15 -> V_7 . V_111 = F_33 ;
V_15 -> V_7 . V_112 = V_113 ;
V_15 -> V_7 . V_114 = V_115 ;
V_15 -> V_7 . V_116 = V_117 ;
V_15 -> V_7 . V_118 = V_119 ;
V_15 -> V_7 . V_120 = V_121 ;
V_15 -> V_7 . V_122 = V_123 ;
V_15 -> V_7 . V_124 = V_125 ;
V_15 -> V_7 . V_126 = V_127 ;
V_15 -> V_7 . V_128 = V_129 ;
V_15 -> V_7 . V_130 = V_131 ;
V_15 -> V_7 . V_132 = V_133 ;
V_15 -> V_7 . V_134 = V_135 ;
V_15 -> V_7 . V_136 = V_137 ;
V_15 -> V_7 . V_138 = V_139 ;
V_15 -> V_7 . V_140 = V_141 ;
V_15 -> V_7 . V_142 = V_143 ;
V_15 -> V_7 . V_144 = V_145 ;
V_15 -> V_7 . V_146 = V_147 ;
V_15 -> V_7 . V_148 = V_149 ;
V_15 -> V_7 . V_150 = V_151 ;
V_15 -> V_7 . V_152 = V_153 ;
V_15 -> V_7 . V_154 = V_155 ;
V_15 -> V_7 . V_156 = V_157 ;
V_15 -> V_7 . V_158 = F_32 ;
if ( F_44 ( & V_15 -> V_7 , NULL ) )
goto V_159;
F_24 ( V_15 -> V_41 , V_15 -> V_31 -> V_49 ) ;
F_23 ( V_15 -> V_41 , V_15 -> V_31 -> V_46 ) ;
if ( F_20 ( V_15 -> V_31 ) )
F_21 ( V_15 -> V_41 ) ;
V_73 = ( (struct V_160 * ) ( V_31 -> V_161 ) ) -> V_162 ;
if ( V_73 != NULL )
F_30 ( V_15 -> V_41 , V_73 -> V_57 ) ;
F_45 ( V_15 -> V_31 -> V_163 ,
V_15 -> V_41 -> V_58 , & V_72 . V_164 [ 0 ] ) ;
memcpy ( & V_15 -> V_7 . V_165 , & V_72 . V_166 . V_167 ,
sizeof( V_72 . V_166 . V_167 ) ) ;
F_46 ( & V_15 -> V_168 ) ;
F_18 ( L_40 ,
V_15 -> V_7 . V_8 , F_37 ( V_15 -> V_31 ) ,
V_15 -> V_41 -> V_45 , V_15 -> V_41 -> V_42 ,
V_15 -> V_41 -> V_49 ) ;
return V_15 ;
V_159:
F_47 ( V_15 -> V_41 ) ;
V_75:
F_14 ( L_41 ) ;
F_48 ( & V_15 -> V_7 ) ;
return NULL ;
}
static void F_49 ( struct V_14 * V_15 )
{
F_18 ( L_42 , V_15 -> V_7 . V_8 ) ;
F_50 ( V_15 ) ;
F_47 ( V_15 -> V_41 ) ;
F_51 ( & V_15 -> V_7 ) ;
F_48 ( & V_15 -> V_7 ) ;
}
static void F_52 ( struct V_169 * V_169 )
{
struct V_14 * V_15 , * V_170 ;
struct V_70 * V_60 ;
bool V_171 = false ;
V_60 = F_53 ( V_169 , struct V_14 , V_168 ) -> V_78 ;
F_17 ( & V_53 ) ;
F_54 (us_ibdev, tmp,
&usnic_ib_ibdev_list, ib_dev_link) {
if ( V_15 -> V_78 == V_60 ) {
F_55 ( & V_15 -> V_172 ) ;
F_49 ( V_15 ) ;
V_171 = true ;
break;
}
}
F_56 ( ! V_171 , L_43 , F_40 ( V_60 ) ) ;
F_25 ( & V_53 ) ;
}
static struct V_14 * F_57 ( struct V_173 * V_9 )
{
struct V_14 * V_15 ;
struct V_70 * V_174 , * V_175 ;
int V_67 ;
V_175 = F_58 ( V_9 ) ;
V_174 = F_59 ( V_175 ) ;
F_10 ( ! V_174 ) ;
F_17 ( & V_53 ) ;
F_12 (us_ibdev, &usnic_ib_ibdev_list, ib_dev_link) {
if ( V_15 -> V_78 == V_174 ) {
F_60 ( & V_15 -> V_168 ) ;
goto V_176;
}
}
V_15 = F_34 ( V_174 ) ;
if ( F_61 ( V_15 ) ) {
V_15 = V_15 ? V_15 : F_38 ( - V_74 ) ;
goto V_176;
}
V_67 = F_62 ( V_15 ) ;
if ( V_67 ) {
F_49 ( V_15 ) ;
V_15 = F_38 ( V_67 ) ;
goto V_176;
}
F_63 ( & V_15 -> V_172 , & V_177 ) ;
V_176:
F_25 ( & V_53 ) ;
return V_15 ;
}
static int F_64 ( struct V_70 * V_78 ,
const struct V_178 * V_179 )
{
int V_67 ;
struct V_14 * V_6 ;
struct V_4 * V_5 ;
enum V_180 V_181 ;
V_5 = F_65 ( sizeof( * V_5 ) , V_182 ) ;
if ( ! V_5 )
return - V_183 ;
V_67 = F_66 ( V_78 ) ;
if ( V_67 ) {
F_14 ( L_44 ,
F_40 ( V_78 ) , V_67 ) ;
goto V_184;
}
V_67 = F_67 ( V_78 , V_185 ) ;
if ( V_67 ) {
F_14 ( L_45 ,
F_40 ( V_78 ) , V_67 ) ;
goto V_186;
}
F_68 ( V_78 ) ;
F_69 ( V_78 , V_5 ) ;
V_5 -> V_9 = F_70 ( V_78 ) ;
if ( F_61 ( V_5 -> V_9 ) ) {
V_67 = V_5 -> V_9 ? F_71 ( V_5 -> V_9 ) : - V_183 ;
F_14 ( L_46 ,
F_40 ( V_78 ) , V_67 ) ;
goto V_187;
}
V_6 = F_57 ( V_5 -> V_9 ) ;
if ( F_61 ( V_6 ) ) {
F_14 ( L_47 ,
F_40 ( V_78 ) , F_71 ( V_6 ) ) ;
V_67 = V_6 ? F_71 ( V_6 ) : - V_74 ;
goto V_188;
}
V_5 -> V_6 = V_6 ;
F_72 ( & V_5 -> V_189 ) ;
F_17 ( & V_6 -> V_23 ) ;
F_73 ( & V_5 -> V_190 , & V_6 -> V_76 ) ;
for ( V_181 = V_191 + 1 ;
V_181 < V_192 ;
V_181 ++ ) {
V_6 -> V_193 [ V_181 ] = F_74 ( V_5 -> V_9 ,
V_181 ) ;
}
F_25 ( & V_6 -> V_23 ) ;
F_18 ( L_48 , F_40 ( V_78 ) ,
V_6 -> V_7 . V_8 ) ;
F_5 ( V_5 ) ;
return 0 ;
V_188:
F_75 ( V_5 -> V_9 ) ;
V_187:
F_69 ( V_78 , NULL ) ;
F_76 ( V_78 ) ;
F_77 ( V_78 ) ;
V_186:
F_78 ( V_78 ) ;
V_184:
F_79 ( V_5 ) ;
return V_67 ;
}
static void F_80 ( struct V_70 * V_78 )
{
struct V_4 * V_5 = F_35 ( V_78 ) ;
struct V_14 * V_6 = V_5 -> V_6 ;
F_17 ( & V_6 -> V_23 ) ;
F_55 ( & V_5 -> V_190 ) ;
F_25 ( & V_6 -> V_23 ) ;
F_81 ( & V_6 -> V_168 , F_52 ) ;
F_75 ( V_5 -> V_9 ) ;
F_69 ( V_78 , NULL ) ;
F_76 ( V_78 ) ;
F_77 ( V_78 ) ;
F_78 ( V_78 ) ;
F_79 ( V_5 ) ;
F_18 ( L_49 , F_40 ( V_78 ) ) ;
}
static int T_2 F_82 ( void )
{
int V_67 ;
F_83 ( V_194 L_50 , V_195 ) ;
V_67 = F_84 ( V_185 ) ;
if ( V_67 ) {
F_14 ( L_51 , V_67 ) ;
return V_67 ;
}
if ( F_85 ( & V_196 ) ) {
F_14 ( L_52 ) ;
goto V_197;
}
V_67 = F_86 ( & V_198 ) ;
if ( V_67 ) {
F_14 ( L_53 ) ;
goto V_199;
}
V_67 = F_87 ( & V_200 ) ;
if ( V_67 ) {
F_14 ( L_54 ) ;
goto V_201;
}
V_67 = F_88 () ;
if ( V_67 ) {
F_14 ( L_55 ) ;
goto V_202;
}
F_89 () ;
return 0 ;
V_202:
F_90 ( & V_200 ) ;
V_201:
F_91 ( & V_198 ) ;
V_199:
F_92 ( & V_196 ) ;
V_197:
F_93 () ;
return V_67 ;
}
static void T_3 F_94 ( void )
{
F_6 ( L_36 ) ;
F_95 () ;
F_96 () ;
F_90 ( & V_200 ) ;
F_91 ( & V_198 ) ;
F_92 ( & V_196 ) ;
F_93 () ;
}
