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
static void * F_32 ( struct V_61 * V_60 )
{
struct V_14 * V_15 ;
union V_62 V_63 ;
struct V_55 * V_64 ;
struct V_30 * V_31 ;
F_6 ( L_36 ) ;
V_31 = F_33 ( V_60 ) ;
V_15 = (struct V_14 * ) F_34 ( sizeof( * V_15 ) ) ;
if ( F_35 ( V_15 ) ) {
F_14 ( L_37 ,
F_36 ( F_33 ( V_60 ) ) ) ;
return F_37 ( V_15 ? F_38 ( V_15 ) : - V_65 ) ;
}
V_15 -> V_41 = F_39 ( V_60 ) ;
if ( F_35 ( V_15 -> V_41 ) ) {
F_14 ( L_38 ,
F_40 ( V_60 ) , F_38 ( V_15 -> V_41 ) ) ;
goto V_66;
}
F_41 ( & V_15 -> V_23 ) ;
F_42 ( & V_15 -> V_67 ) ;
F_42 ( & V_15 -> V_68 ) ;
V_15 -> V_69 = V_60 ;
V_15 -> V_31 = F_33 ( V_60 ) ;
V_15 -> V_7 . V_70 = V_71 ;
V_15 -> V_7 . V_72 = V_73 ;
V_15 -> V_7 . V_74 = V_75 ;
V_15 -> V_7 . V_76 = V_77 ;
V_15 -> V_7 . V_78 = & V_60 -> V_60 ;
V_15 -> V_7 . V_79 = V_80 ;
F_43 ( V_15 -> V_7 . V_8 , L_39 , V_81 ) ;
V_15 -> V_7 . V_82 =
( 1ull << V_83 ) |
( 1ull << V_84 ) |
( 1ull << V_85 ) |
( 1ull << V_86 ) |
( 1ull << V_87 ) |
( 1ull << V_88 ) |
( 1ull << V_89 ) |
( 1ull << V_90 ) |
( 1ull << V_91 ) |
( 1ull << V_92 ) |
( 1ull << V_93 ) |
( 1ull << V_94 ) |
( 1ull << V_95 ) |
( 1ull << V_96 ) |
( 1ull << V_97 ) |
( 1ull << V_98 ) |
( 1ull << V_99 ) ;
V_15 -> V_7 . V_100 = V_101 ;
V_15 -> V_7 . V_102 = V_103 ;
V_15 -> V_7 . V_104 = V_105 ;
V_15 -> V_7 . V_106 = V_107 ;
V_15 -> V_7 . V_108 = V_109 ;
V_15 -> V_7 . V_110 = V_111 ;
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
if ( F_44 ( & V_15 -> V_7 , NULL ) )
goto V_150;
F_24 ( V_15 -> V_41 , V_15 -> V_31 -> V_49 ) ;
F_23 ( V_15 -> V_41 , V_15 -> V_31 -> V_46 ) ;
if ( F_20 ( V_15 -> V_31 ) )
F_21 ( V_15 -> V_41 ) ;
V_64 = ( (struct V_151 * ) ( V_31 -> V_152 ) ) -> V_153 ;
if ( V_64 != NULL )
F_30 ( V_15 -> V_41 , V_64 -> V_57 ) ;
F_45 ( V_15 -> V_31 -> V_154 ,
V_15 -> V_41 -> V_58 , & V_63 . V_155 [ 0 ] ) ;
memcpy ( & V_15 -> V_7 . V_156 , & V_63 . V_157 . V_158 ,
sizeof( V_63 . V_157 . V_158 ) ) ;
F_46 ( & V_15 -> V_159 ) ;
F_18 ( L_40 ,
V_15 -> V_7 . V_8 , F_36 ( V_15 -> V_31 ) ,
V_15 -> V_41 -> V_45 , V_15 -> V_41 -> V_42 ,
V_15 -> V_41 -> V_49 ) ;
return V_15 ;
V_150:
F_47 ( V_15 -> V_41 ) ;
V_66:
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
static void F_52 ( struct V_160 * V_160 )
{
struct V_14 * V_15 , * V_161 ;
struct V_61 * V_60 ;
bool V_162 = false ;
V_60 = F_53 ( V_160 , struct V_14 , V_159 ) -> V_69 ;
F_17 ( & V_53 ) ;
F_54 (us_ibdev, tmp,
&usnic_ib_ibdev_list, ib_dev_link) {
if ( V_15 -> V_69 == V_60 ) {
F_55 ( & V_15 -> V_163 ) ;
F_49 ( V_15 ) ;
V_162 = true ;
break;
}
}
F_56 ( ! V_162 , L_43 , F_40 ( V_60 ) ) ;
F_25 ( & V_53 ) ;
}
static struct V_14 * F_57 ( struct V_164 * V_9 )
{
struct V_14 * V_15 ;
struct V_61 * V_165 , * V_166 ;
int V_167 ;
V_166 = F_58 ( V_9 ) ;
V_165 = F_59 ( V_166 ) ;
F_10 ( ! V_165 ) ;
F_17 ( & V_53 ) ;
F_12 (us_ibdev, &usnic_ib_ibdev_list, ib_dev_link) {
if ( V_15 -> V_69 == V_165 ) {
F_60 ( & V_15 -> V_159 ) ;
goto V_168;
}
}
V_15 = F_32 ( V_165 ) ;
if ( F_35 ( V_15 ) ) {
V_15 = V_15 ? V_15 : F_37 ( - V_65 ) ;
goto V_168;
}
V_167 = F_61 ( V_15 ) ;
if ( V_167 ) {
F_49 ( V_15 ) ;
V_15 = F_37 ( V_167 ) ;
goto V_168;
}
F_62 ( & V_15 -> V_163 , & V_169 ) ;
V_168:
F_25 ( & V_53 ) ;
return V_15 ;
}
static int F_63 ( struct V_61 * V_69 ,
const struct V_170 * V_171 )
{
int V_167 ;
struct V_14 * V_6 ;
struct V_4 * V_5 ;
enum V_172 V_173 ;
V_5 = F_64 ( sizeof( * V_5 ) , V_174 ) ;
if ( ! V_5 )
return - V_175 ;
V_167 = F_65 ( V_69 ) ;
if ( V_167 ) {
F_14 ( L_44 ,
F_40 ( V_69 ) , V_167 ) ;
goto V_176;
}
V_167 = F_66 ( V_69 , V_177 ) ;
if ( V_167 ) {
F_14 ( L_45 ,
F_40 ( V_69 ) , V_167 ) ;
goto V_178;
}
F_67 ( V_69 ) ;
F_68 ( V_69 , V_5 ) ;
V_5 -> V_9 = F_69 ( V_69 ) ;
if ( F_35 ( V_5 -> V_9 ) ) {
V_167 = V_5 -> V_9 ? F_38 ( V_5 -> V_9 ) : - V_175 ;
F_14 ( L_46 ,
F_40 ( V_69 ) , V_167 ) ;
goto V_179;
}
V_6 = F_57 ( V_5 -> V_9 ) ;
if ( F_35 ( V_6 ) ) {
F_14 ( L_47 ,
F_40 ( V_69 ) , F_38 ( V_6 ) ) ;
V_167 = V_6 ? F_38 ( V_6 ) : - V_65 ;
goto V_180;
}
V_5 -> V_6 = V_6 ;
F_70 ( & V_5 -> V_181 ) ;
F_17 ( & V_6 -> V_23 ) ;
F_71 ( & V_5 -> V_182 , & V_6 -> V_67 ) ;
for ( V_173 = V_183 + 1 ;
V_173 < V_184 ;
V_173 ++ ) {
V_6 -> V_185 [ V_173 ] = F_72 ( V_5 -> V_9 ,
V_173 ) ;
}
F_25 ( & V_6 -> V_23 ) ;
F_18 ( L_48 , F_40 ( V_69 ) ,
V_6 -> V_7 . V_8 ) ;
F_5 ( V_5 ) ;
return 0 ;
V_180:
F_73 ( V_5 -> V_9 ) ;
V_179:
F_68 ( V_69 , NULL ) ;
F_74 ( V_69 ) ;
F_75 ( V_69 ) ;
V_178:
F_76 ( V_69 ) ;
V_176:
F_77 ( V_5 ) ;
return V_167 ;
}
static void F_78 ( struct V_61 * V_69 )
{
struct V_4 * V_5 = F_33 ( V_69 ) ;
struct V_14 * V_6 = V_5 -> V_6 ;
F_17 ( & V_6 -> V_23 ) ;
F_55 ( & V_5 -> V_182 ) ;
F_25 ( & V_6 -> V_23 ) ;
F_79 ( & V_6 -> V_159 , F_52 ) ;
F_73 ( V_5 -> V_9 ) ;
F_68 ( V_69 , NULL ) ;
F_74 ( V_69 ) ;
F_75 ( V_69 ) ;
F_76 ( V_69 ) ;
F_77 ( V_5 ) ;
F_18 ( L_49 , F_40 ( V_69 ) ) ;
}
static int T_1 F_80 ( void )
{
int V_167 ;
F_81 ( V_186 L_50 , V_187 ) ;
V_167 = F_82 ( V_177 ) ;
if ( V_167 ) {
F_14 ( L_51 , V_167 ) ;
return V_167 ;
}
if ( F_83 ( & V_188 ) ) {
F_14 ( L_52 ) ;
goto V_189;
}
V_167 = F_84 ( & V_190 ) ;
if ( V_167 ) {
F_14 ( L_53 ) ;
goto V_191;
}
V_167 = F_85 ( & V_192 ) ;
if ( V_167 ) {
F_14 ( L_54 ) ;
goto V_193;
}
V_167 = F_86 () ;
if ( V_167 ) {
F_14 ( L_55 ) ;
goto V_194;
}
F_87 () ;
return 0 ;
V_194:
F_88 ( & V_192 ) ;
V_193:
F_89 ( & V_190 ) ;
V_191:
F_90 ( & V_188 ) ;
V_189:
F_91 () ;
return V_167 ;
}
static void T_2 F_92 ( void )
{
F_6 ( L_36 ) ;
F_93 () ;
F_94 () ;
F_88 ( & V_192 ) ;
F_89 ( & V_190 ) ;
F_90 ( & V_188 ) ;
F_91 () ;
}
