static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 , V_8 ) ;
if ( V_2 -> V_9 -> V_10 != 4 || V_3 != 0 )
return V_4 ;
V_11:
if ( ! F_3 ( & V_6 -> V_12 , V_13 ) )
return - V_14 ;
F_4 ( & V_6 -> V_15 ) ;
V_4 = F_5 ( & V_6 -> V_12 , V_2 , & V_2 -> V_16 ) ;
F_6 ( & V_6 -> V_15 ) ;
if ( V_4 == - V_17 )
goto V_11;
return V_4 ;
}
static struct V_1 * F_7 ( const struct V_18 * V_19 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_22 = - V_14 ;
if ( ( V_2 = F_8 ( sizeof( * V_2 ) , V_13 ) ) == NULL )
goto V_23;
V_2 -> V_9 = V_19 -> V_9 ;
F_9 ( & V_2 -> V_24 , 1 ) ;
V_2 -> V_25 = V_26 ;
memcpy ( & V_2 -> V_27 , V_19 -> V_28 , V_19 -> V_29 ) ;
V_2 -> V_30 = V_19 -> V_29 ;
if ( V_19 -> V_31 ) {
V_22 = - V_14 ;
V_2 -> V_32 = F_10 ( V_19 -> V_31 , V_13 ) ;
if ( ! V_2 -> V_32 )
goto V_33;
}
F_11 ( & V_2 -> V_34 ) ;
V_2 -> V_35 = F_12 ( - V_36 ) ;
V_2 -> V_37 = V_19 -> V_38 ;
V_2 -> V_7 = F_13 ( V_19 -> V_39 ) ;
#ifdef F_14
V_22 = F_1 ( V_2 , V_19 -> V_3 ) ;
if ( V_22 )
goto V_33;
F_15 ( & V_2 -> V_40 ) ;
F_16 ( & V_2 -> V_41 , V_42 ) ;
F_17 ( & V_2 -> V_43 , L_1 ) ;
V_2 -> V_44 = 1 << V_45 ;
V_2 -> V_46 = V_19 -> V_3 ;
V_2 -> V_47 = V_48 [ V_19 -> V_3 ] ;
#endif
V_21 = F_18 ( L_2 ) ;
if ( ! F_19 ( V_21 ) )
V_2 -> V_49 = V_21 ;
F_20 ( V_2 ) ;
return V_2 ;
V_33:
F_21 ( V_2 ) ;
V_23:
return F_12 ( V_22 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( F_23 ( V_2 ) ) {
F_24 ( V_2 -> V_50 ) ;
F_25 ( V_2 ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
}
static void F_26 ( struct V_1 * V_2 )
{
if ( F_27 ( V_51 , & V_2 -> V_52 ) )
F_28 ( V_2 -> V_47 -> V_53 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( F_27 ( V_54 , & V_2 -> V_52 ) )
F_30 ( V_2 ) ;
F_22 ( V_2 ) ;
F_26 ( V_2 ) ;
if ( F_27 ( V_55 , & V_2 -> V_52 ) )
F_31 ( V_2 ) ;
F_32 ( & V_2 -> V_43 ) ;
F_21 ( V_2 -> V_56 ) ;
F_21 ( V_2 -> V_57 ) ;
F_21 ( V_2 -> V_58 ) ;
}
void F_33 ( struct V_39 * V_39 )
{
struct V_5 * V_6 = F_2 ( V_39 , V_8 ) ;
F_34 ( & V_6 -> V_12 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 , V_8 ) ;
if ( V_2 -> V_16 )
F_36 ( & V_6 -> V_12 , V_2 -> V_16 ) ;
}
static void F_37 ( struct V_59 * V_60 )
{
F_17 ( & V_60 -> V_61 , L_3 ) ;
}
static void F_38 ( struct V_59 * V_60 )
{
F_39 ( V_60 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
}
void F_33 ( struct V_39 * V_39 )
{
}
static void F_35 ( struct V_1 * V_2 )
{
}
static void F_37 ( struct V_59 * V_60 )
{
}
static void F_40 ( struct V_1 * V_2 )
{
F_41 ( L_4 , V_2 -> V_9 -> V_10 ) ;
F_29 ( V_2 ) ;
F_42 ( V_2 ) ;
if ( ! F_19 ( V_2 -> V_35 ) )
F_43 ( V_2 -> V_35 ) ;
if ( V_2 -> V_49 != NULL )
F_44 ( V_2 -> V_49 ) ;
F_45 ( V_2 -> V_7 ) ;
F_21 ( V_2 -> V_32 ) ;
F_21 ( V_2 ) ;
F_41 ( L_5 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
if ( ! V_2 )
return;
F_41 ( L_6 , F_47 ( & V_2 -> V_24 ) ) ;
V_6 = F_2 ( V_2 -> V_7 , V_8 ) ;
if ( F_48 ( & V_2 -> V_24 , & V_6 -> V_15 ) ) {
F_49 ( & V_2 -> V_62 ) ;
F_35 ( V_2 ) ;
F_6 ( & V_6 -> V_15 ) ;
F_50 ( ! F_51 ( & V_2 -> V_34 ) ) ;
F_40 ( V_2 ) ;
}
}
static int F_52 ( const struct V_63 * V_64 ,
const struct V_63 * V_65 )
{
const struct V_66 * V_67 = ( const struct V_66 * ) V_64 ;
const struct V_66 * V_68 = ( const struct V_66 * ) V_65 ;
if ( ! F_53 ( & V_67 -> V_69 , & V_68 -> V_69 ) )
return 0 ;
else if ( F_54 ( & V_67 -> V_69 ) & V_70 )
return V_67 -> V_71 == V_68 -> V_71 ;
return 1 ;
}
static int F_52 ( const struct V_63 * V_64 ,
const struct V_63 * V_65 )
{
return 0 ;
}
static int F_55 ( const struct V_63 * V_64 ,
const struct V_63 * V_65 )
{
const struct V_72 * V_67 = ( const struct V_72 * ) V_64 ;
const struct V_72 * V_68 = ( const struct V_72 * ) V_65 ;
return V_67 -> V_73 . V_74 == V_68 -> V_73 . V_74 ;
}
static int F_56 ( const struct V_63 * V_64 ,
const struct V_63 * V_65 )
{
const struct V_66 * V_67 = ( const struct V_66 * ) V_64 ;
const struct V_66 * V_68 = ( const struct V_66 * ) V_65 ;
return F_52 ( V_64 , V_65 ) &&
( V_67 -> V_75 == V_68 -> V_75 ) ;
}
static int F_57 ( const struct V_63 * V_64 ,
const struct V_63 * V_65 )
{
const struct V_72 * V_67 = ( const struct V_72 * ) V_64 ;
const struct V_72 * V_68 = ( const struct V_72 * ) V_65 ;
return F_55 ( V_64 , V_65 ) &&
( V_67 -> V_76 == V_68 -> V_76 ) ;
}
static int F_58 ( const struct V_63 * V_64 ,
const struct V_63 * V_65 )
{
if ( V_64 -> V_77 != V_65 -> V_77 )
return 0 ;
switch ( V_64 -> V_77 ) {
case V_78 :
return F_55 ( V_64 , V_65 ) ;
case V_79 :
return F_52 ( V_64 , V_65 ) ;
}
return 0 ;
}
static int F_59 ( const struct V_63 * V_64 ,
const struct V_63 * V_65 )
{
if ( V_64 -> V_77 != V_65 -> V_77 )
return 0 ;
switch ( V_64 -> V_77 ) {
case V_78 :
return F_57 ( V_64 , V_65 ) ;
case V_79 :
return F_56 ( V_64 , V_65 ) ;
}
return 0 ;
}
static bool F_60 ( const struct V_63 * V_28 ,
struct V_1 * V_2 , T_1 V_3 )
{
struct V_63 * V_80 = (struct V_63 * ) & V_2 -> V_27 ;
if ( ! ( V_2 -> V_25 == V_81 ||
V_2 -> V_25 == V_82 ) )
return false ;
F_61 () ;
if ( V_2 -> V_9 -> V_10 != 4 ||
V_2 -> V_46 != V_3 )
return false ;
if ( ! F_58 ( V_28 , V_80 ) )
return false ;
return true ;
}
static struct V_1 * F_62 ( const struct V_18 * V_83 )
{
struct V_1 * V_2 ;
const struct V_63 * V_84 = V_83 -> V_28 ;
struct V_5 * V_6 = F_2 ( V_83 -> V_39 , V_8 ) ;
F_63 (clp, &nn->nfs_client_list, cl_share_link) {
const struct V_63 * V_80 = (struct V_63 * ) & V_2 -> V_27 ;
if ( V_2 -> V_25 < 0 )
continue;
if ( V_2 -> V_9 != V_83 -> V_9 )
continue;
if ( V_2 -> V_37 != V_83 -> V_38 )
continue;
if ( V_2 -> V_46 != V_83 -> V_3 )
continue;
if ( ! F_59 ( V_84 , V_80 ) )
continue;
F_64 ( & V_2 -> V_24 ) ;
return V_2 ;
}
return NULL ;
}
static bool F_65 ( const struct V_1 * V_2 )
{
return V_2 -> V_25 != V_26 ;
}
int F_66 ( const struct V_1 * V_2 )
{
return F_67 ( V_85 ,
F_65 ( V_2 ) ) ;
}
static struct V_1 *
F_68 ( const struct V_18 * V_19 ,
struct V_1 * V_2 )
{
int error ;
error = F_66 ( V_2 ) ;
if ( error < 0 ) {
F_46 ( V_2 ) ;
return F_12 ( - V_86 ) ;
}
if ( V_2 -> V_25 < V_81 ) {
error = V_2 -> V_25 ;
F_46 ( V_2 ) ;
return F_12 ( error ) ;
}
F_61 () ;
F_41 ( L_7 ,
V_87 , V_2 , V_19 -> V_31 ? : L_8 ) ;
return V_2 ;
}
static struct V_1 *
F_69 ( const struct V_18 * V_19 ,
const struct V_88 * V_89 ,
const char * V_90 ,
T_2 V_91 )
{
struct V_1 * V_2 , * V_92 = NULL ;
struct V_5 * V_6 = F_2 ( V_19 -> V_39 , V_8 ) ;
F_41 ( L_9 ,
V_19 -> V_31 ? : L_8 , V_19 -> V_9 -> V_10 ) ;
do {
F_4 ( & V_6 -> V_15 ) ;
V_2 = F_62 ( V_19 ) ;
if ( V_2 ) {
F_6 ( & V_6 -> V_15 ) ;
if ( V_92 )
F_40 ( V_92 ) ;
return F_68 ( V_19 , V_2 ) ;
}
if ( V_92 ) {
F_70 ( & V_92 -> V_62 , & V_6 -> V_93 ) ;
F_6 ( & V_6 -> V_15 ) ;
V_92 -> V_94 = V_19 -> V_95 ;
return V_19 -> V_9 -> V_96 ( V_92 ,
V_89 , V_90 ,
V_91 ) ;
}
F_6 ( & V_6 -> V_15 ) ;
V_92 = F_7 ( V_19 ) ;
} while ( ! F_19 ( V_92 ) );
F_41 ( L_10 ,
V_19 -> V_31 ? : L_8 , F_71 ( V_92 ) ) ;
return V_92 ;
}
void F_72 ( struct V_1 * V_2 , int V_97 )
{
F_73 () ;
V_2 -> V_25 = V_97 ;
F_74 ( & V_85 ) ;
}
static void F_75 ( struct V_88 * V_98 , int V_38 ,
unsigned int V_99 , unsigned int V_100 )
{
V_98 -> V_101 = V_99 * V_102 / 10 ;
V_98 -> V_103 = V_100 ;
switch ( V_38 ) {
case V_104 :
case V_105 :
if ( V_98 -> V_103 == 0 )
V_98 -> V_103 = V_106 ;
if ( V_98 -> V_101 == 0 )
V_98 -> V_101 = V_107 * V_102 / 10 ;
if ( V_98 -> V_101 > V_108 )
V_98 -> V_101 = V_108 ;
V_98 -> V_109 = V_98 -> V_101 ;
V_98 -> V_110 = V_98 -> V_101 + ( V_98 -> V_109 * V_98 -> V_103 ) ;
if ( V_98 -> V_110 > V_108 )
V_98 -> V_110 = V_108 ;
if ( V_98 -> V_110 < V_98 -> V_101 )
V_98 -> V_110 = V_98 -> V_101 ;
V_98 -> V_111 = 0 ;
break;
case V_112 :
if ( V_98 -> V_103 == 0 )
V_98 -> V_103 = V_113 ;
if ( ! V_98 -> V_101 )
V_98 -> V_101 = V_114 * V_102 / 10 ;
if ( V_98 -> V_101 > V_115 )
V_98 -> V_101 = V_115 ;
V_98 -> V_110 = V_115 ;
V_98 -> V_111 = 1 ;
break;
default:
F_76 () ;
}
}
static int F_77 ( struct V_1 * V_2 ,
const struct V_88 * V_89 ,
T_2 V_116 )
{
struct V_117 * V_118 = NULL ;
struct V_119 args = {
. V_39 = V_2 -> V_7 ,
. V_120 = V_2 -> V_37 ,
. V_121 = (struct V_63 * ) & V_2 -> V_27 ,
. V_122 = V_2 -> V_30 ,
. V_123 = V_89 ,
. V_124 = V_2 -> V_32 ,
. V_125 = & V_126 ,
. V_10 = V_2 -> V_9 -> V_10 ,
. V_127 = V_116 ,
} ;
if ( F_78 ( V_128 , & V_2 -> V_94 ) )
args . V_129 |= V_130 ;
if ( F_78 ( V_131 , & V_2 -> V_94 ) )
args . V_129 |= V_132 ;
if ( ! F_19 ( V_2 -> V_35 ) )
return 0 ;
V_118 = F_79 ( & args ) ;
if ( F_19 ( V_118 ) ) {
F_41 ( L_11 ,
V_87 , F_71 ( V_118 ) ) ;
return F_71 ( V_118 ) ;
}
V_2 -> V_35 = V_118 ;
return 0 ;
}
static void F_80 ( struct V_59 * V_60 )
{
if ( ! ( V_60 -> V_129 & V_133 ) ||
! ( V_60 -> V_129 & V_134 ) )
F_81 ( V_60 -> V_135 ) ;
}
static int F_82 ( struct V_59 * V_60 )
{
struct V_135 * V_136 ;
struct V_1 * V_2 = V_60 -> V_1 ;
struct V_137 V_138 = {
. V_31 = V_2 -> V_32 ,
. V_121 = (struct V_63 * ) & V_2 -> V_27 ,
. V_29 = V_2 -> V_30 ,
. V_139 = V_2 -> V_9 -> V_10 ,
. V_140 = V_60 -> V_129 & V_141 ?
1 : 0 ,
. V_39 = V_2 -> V_7 ,
} ;
if ( V_138 . V_139 > 3 )
return 0 ;
if ( ( V_60 -> V_129 & V_133 ) &&
( V_60 -> V_129 & V_134 ) )
return 0 ;
switch ( V_2 -> V_37 ) {
default:
V_138 . V_120 = V_142 ;
break;
case V_112 :
V_138 . V_120 = V_143 ;
}
V_136 = F_83 ( & V_138 ) ;
if ( F_19 ( V_136 ) )
return F_71 ( V_136 ) ;
V_60 -> V_135 = V_136 ;
V_60 -> V_144 = F_80 ;
return 0 ;
}
static void F_84 ( struct V_59 * V_60 )
{
if ( V_60 -> V_1 -> V_9 -> V_10 != 3 )
goto V_145;
if ( V_60 -> V_129 & V_146 )
goto V_145;
V_60 -> V_147 = F_85 ( V_60 -> V_148 , & V_149 , 3 ) ;
if ( F_19 ( V_60 -> V_147 ) )
goto V_145;
V_60 -> V_150 |= V_151 ;
return;
V_145:
V_60 -> V_150 &= ~ V_151 ;
}
static inline void F_84 ( struct V_59 * V_60 )
{
V_60 -> V_129 &= ~ V_146 ;
V_60 -> V_150 &= ~ V_151 ;
}
static int F_86 ( struct V_59 * V_60 ,
const struct V_88 * V_99 ,
T_2 V_152 )
{
struct V_1 * V_2 = V_60 -> V_1 ;
V_60 -> V_148 = F_87 ( V_2 -> V_35 ) ;
if ( F_19 ( V_60 -> V_148 ) ) {
F_41 ( L_12 , V_87 ) ;
return F_71 ( V_60 -> V_148 ) ;
}
memcpy ( & V_60 -> V_148 -> V_153 ,
V_99 ,
sizeof( V_60 -> V_148 -> V_153 ) ) ;
V_60 -> V_148 -> V_154 = & V_60 -> V_148 -> V_153 ;
if ( V_152 != V_2 -> V_35 -> V_155 -> V_156 ) {
struct V_157 * V_158 ;
V_158 = F_88 ( V_152 , V_60 -> V_148 ) ;
if ( F_19 ( V_158 ) ) {
F_41 ( L_13 , V_87 ) ;
return F_71 ( V_158 ) ;
}
}
V_60 -> V_148 -> V_159 = 0 ;
if ( V_60 -> V_129 & V_160 )
V_60 -> V_148 -> V_159 = 1 ;
return 0 ;
}
struct V_1 * F_89 ( struct V_1 * V_2 ,
const struct V_88 * V_89 ,
const char * V_90 , T_2 V_91 )
{
int error ;
if ( V_2 -> V_25 == V_81 ) {
F_41 ( L_14 , V_2 ) ;
return V_2 ;
}
error = F_77 ( V_2 , V_89 , V_161 ) ;
if ( error < 0 )
goto error;
F_72 ( V_2 , V_81 ) ;
return V_2 ;
error:
F_72 ( V_2 , error ) ;
F_46 ( V_2 ) ;
F_41 ( L_15 , error ) ;
return F_12 ( error ) ;
}
static int F_90 ( struct V_59 * V_60 ,
const struct V_162 * V_83 )
{
struct V_18 V_19 = {
. V_31 = V_83 -> V_59 . V_31 ,
. V_28 = ( const struct V_63 * ) & V_83 -> V_59 . V_121 ,
. V_29 = V_83 -> V_59 . V_29 ,
. V_9 = NULL ,
. V_38 = V_83 -> V_59 . V_120 ,
. V_39 = V_83 -> V_39 ,
} ;
struct V_88 V_89 ;
struct V_1 * V_2 ;
int error ;
F_41 ( L_16 ) ;
switch ( V_83 -> V_10 ) {
#ifdef F_91
case 2 :
V_19 . V_9 = & V_163 ;
break;
#endif
#ifdef F_92
case 3 :
V_19 . V_9 = & V_164 ;
break;
#endif
default:
return - V_165 ;
}
F_75 ( & V_89 , V_83 -> V_59 . V_120 ,
V_83 -> V_99 , V_83 -> V_100 ) ;
if ( V_83 -> V_129 & V_141 )
F_93 ( V_131 , & V_19 . V_95 ) ;
V_2 = F_69 ( & V_19 , & V_89 , NULL , V_161 ) ;
if ( F_19 ( V_2 ) ) {
F_41 ( L_17 , F_71 ( V_2 ) ) ;
return F_71 ( V_2 ) ;
}
V_60 -> V_1 = V_2 ;
V_60 -> V_129 = V_83 -> V_129 ;
V_60 -> V_166 = V_83 -> V_166 ;
V_60 -> V_150 |= V_167 | V_168 | V_169 |
V_170 | V_171 | V_172 | V_173 |
V_174 | V_175 | V_176 | V_177 ;
if ( V_83 -> V_178 )
V_60 -> V_178 = F_94 ( V_83 -> V_178 , NULL ) ;
if ( V_83 -> V_179 )
V_60 -> V_179 = F_94 ( V_83 -> V_179 , NULL ) ;
V_60 -> V_180 = V_83 -> V_180 * V_102 ;
V_60 -> V_181 = V_83 -> V_181 * V_102 ;
V_60 -> V_182 = V_83 -> V_182 * V_102 ;
V_60 -> V_183 = V_83 -> V_183 * V_102 ;
error = F_82 ( V_60 ) ;
if ( error < 0 )
goto error;
V_60 -> V_184 = V_83 -> V_59 . V_184 ;
error = F_86 ( V_60 , & V_89 , V_83 -> V_185 [ 0 ] ) ;
if ( error < 0 )
goto error;
if ( V_83 -> V_186 . V_29 ) {
memcpy ( & V_60 -> V_187 , & V_83 -> V_186 . V_121 ,
V_83 -> V_186 . V_29 ) ;
V_60 -> V_188 = V_83 -> V_186 . V_29 ;
}
V_60 -> V_189 = V_83 -> V_186 . V_10 ;
V_60 -> V_190 = V_83 -> V_186 . V_184 ;
V_60 -> V_191 = V_83 -> V_186 . V_120 ;
V_60 -> V_192 = V_83 -> V_193 ;
F_84 ( V_60 ) ;
F_41 ( L_18 , V_2 ) ;
return 0 ;
error:
V_60 -> V_1 = NULL ;
F_46 ( V_2 ) ;
F_41 ( L_19 , error ) ;
return error ;
}
static void F_95 ( struct V_59 * V_60 ,
struct V_194 * V_195 ,
struct V_196 * V_197 )
{
unsigned long V_198 ;
if ( V_60 -> V_178 == 0 )
V_60 -> V_178 = F_94 ( V_197 -> V_199 , NULL ) ;
if ( V_60 -> V_179 == 0 )
V_60 -> V_179 = F_94 ( V_197 -> V_200 , NULL ) ;
if ( V_197 -> V_201 >= 512 && V_60 -> V_178 > V_197 -> V_201 )
V_60 -> V_178 = F_94 ( V_197 -> V_201 , NULL ) ;
if ( V_197 -> V_202 >= 512 && V_60 -> V_179 > V_197 -> V_202 )
V_60 -> V_179 = F_94 ( V_197 -> V_202 , NULL ) ;
V_198 = F_94 ( F_96 ( V_60 -> V_148 ) , NULL ) ;
if ( V_60 -> V_178 > V_198 )
V_60 -> V_178 = V_198 ;
if ( V_60 -> V_178 > V_203 )
V_60 -> V_178 = V_203 ;
V_60 -> V_204 = ( V_60 -> V_178 + V_205 - 1 ) >> V_206 ;
V_60 -> V_207 . V_208 = L_20 ;
V_60 -> V_207 . V_209 = V_60 -> V_204 * V_210 ;
if ( V_60 -> V_179 > V_198 )
V_60 -> V_179 = V_198 ;
if ( V_60 -> V_179 > V_203 )
V_60 -> V_179 = V_203 ;
V_60 -> V_211 = ( V_60 -> V_179 + V_205 - 1 ) >> V_206 ;
V_60 -> V_212 = V_197 -> V_213 ;
F_97 ( V_60 , V_195 , V_197 -> V_214 ) ;
V_60 -> V_215 = F_98 ( V_197 -> V_215 , NULL ) ;
V_60 -> V_216 = F_94 ( V_197 -> V_217 , NULL ) ;
if ( V_60 -> V_216 > V_205 * V_218 )
V_60 -> V_216 = V_205 * V_218 ;
if ( V_60 -> V_216 > V_60 -> V_178 )
V_60 -> V_216 = V_60 -> V_178 ;
if ( V_60 -> V_129 & V_219 ) {
V_60 -> V_180 = V_60 -> V_181 = 0 ;
V_60 -> V_182 = V_60 -> V_183 = 0 ;
}
V_60 -> V_220 = V_197 -> V_220 ;
V_60 -> V_221 = V_197 -> V_221 ;
F_99 ( V_60 -> V_148 , V_60 -> V_179 + 100 , V_60 -> V_178 + 100 ) ;
}
static int F_100 ( struct V_59 * V_60 , struct V_194 * V_195 , struct V_222 * V_223 )
{
struct V_196 V_197 ;
struct V_1 * V_2 = V_60 -> V_1 ;
int error ;
F_41 ( L_21 ) ;
if ( V_2 -> V_9 -> V_224 != NULL ) {
error = V_2 -> V_9 -> V_224 ( V_60 , V_195 ) ;
if ( error < 0 )
goto V_225;
}
V_197 . V_223 = V_223 ;
V_197 . V_214 = 0 ;
error = V_2 -> V_9 -> V_197 ( V_60 , V_195 , & V_197 ) ;
if ( error < 0 )
goto V_225;
F_95 ( V_60 , V_195 , & V_197 ) ;
if ( V_60 -> V_192 == 0 ) {
struct V_226 V_227 ;
V_227 . V_223 = V_223 ;
F_101 ( V_223 ) ;
if ( V_2 -> V_9 -> V_228 ( V_60 , V_195 , & V_227 ) >= 0 )
V_60 -> V_192 = V_227 . V_229 ;
}
F_41 ( L_22 ) ;
return 0 ;
V_225:
F_41 ( L_23 , - error ) ;
return error ;
}
static void F_102 ( struct V_59 * V_230 , struct V_59 * V_231 )
{
V_230 -> V_129 = V_231 -> V_129 ;
V_230 -> V_178 = V_231 -> V_178 ;
V_230 -> V_179 = V_231 -> V_179 ;
V_230 -> V_180 = V_231 -> V_180 ;
V_230 -> V_181 = V_231 -> V_181 ;
V_230 -> V_182 = V_231 -> V_182 ;
V_230 -> V_183 = V_231 -> V_183 ;
V_230 -> V_150 = V_231 -> V_150 ;
V_230 -> V_166 = V_231 -> V_166 ;
}
static void F_103 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_1 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
F_104 ( & V_60 -> V_232 , & V_2 -> V_34 ) ;
F_105 ( & V_60 -> V_233 , & V_6 -> V_234 ) ;
F_106 ( V_235 , & V_2 -> V_52 ) ;
F_6 ( & V_6 -> V_15 ) ;
}
static void F_107 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_1 ;
struct V_5 * V_6 ;
if ( V_2 == NULL )
return;
V_6 = F_2 ( V_2 -> V_7 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
F_108 ( & V_60 -> V_232 ) ;
if ( F_51 ( & V_2 -> V_34 ) )
F_93 ( V_235 , & V_2 -> V_52 ) ;
F_49 ( & V_60 -> V_233 ) ;
F_6 ( & V_6 -> V_15 ) ;
F_109 () ;
}
static struct V_59 * F_110 ( void )
{
struct V_59 * V_60 ;
V_60 = F_8 ( sizeof( struct V_59 ) , V_13 ) ;
if ( ! V_60 )
return NULL ;
V_60 -> V_148 = V_60 -> V_147 = F_12 ( - V_36 ) ;
F_11 ( & V_60 -> V_232 ) ;
F_11 ( & V_60 -> V_233 ) ;
F_11 ( & V_60 -> V_236 ) ;
F_11 ( & V_60 -> V_237 ) ;
F_11 ( & V_60 -> V_238 ) ;
F_9 ( & V_60 -> V_239 , 0 ) ;
V_60 -> V_240 = F_111 () ;
if ( ! V_60 -> V_240 ) {
F_21 ( V_60 ) ;
return NULL ;
}
if ( F_112 ( & V_60 -> V_207 ) ) {
F_113 ( V_60 -> V_240 ) ;
F_21 ( V_60 ) ;
return NULL ;
}
F_114 ( & V_60 -> V_241 ) ;
F_114 ( & V_60 -> V_242 ) ;
F_37 ( V_60 ) ;
return V_60 ;
}
void F_115 ( struct V_59 * V_60 )
{
F_41 ( L_24 ) ;
F_107 ( V_60 ) ;
F_116 ( V_60 ) ;
if ( V_60 -> V_144 != NULL )
V_60 -> V_144 ( V_60 ) ;
if ( ! F_19 ( V_60 -> V_147 ) )
F_43 ( V_60 -> V_147 ) ;
if ( ! F_19 ( V_60 -> V_148 ) )
F_43 ( V_60 -> V_148 ) ;
F_46 ( V_60 -> V_1 ) ;
F_117 ( & V_60 -> V_242 ) ;
F_117 ( & V_60 -> V_241 ) ;
F_113 ( V_60 -> V_240 ) ;
F_118 ( & V_60 -> V_207 ) ;
F_21 ( V_60 ) ;
F_119 () ;
F_41 ( L_25 ) ;
}
struct V_59 * F_120 ( const struct V_162 * V_83 ,
struct V_194 * V_195 )
{
struct V_59 * V_60 ;
struct V_222 * V_223 ;
int error ;
V_60 = F_110 () ;
if ( ! V_60 )
return F_12 ( - V_14 ) ;
error = - V_14 ;
V_223 = F_121 () ;
if ( V_223 == NULL )
goto error;
error = F_90 ( V_60 , V_83 ) ;
if ( error < 0 )
goto error;
F_50 ( ! V_60 -> V_1 ) ;
F_50 ( ! V_60 -> V_1 -> V_9 ) ;
F_50 ( ! V_60 -> V_1 -> V_9 -> V_243 ) ;
error = F_100 ( V_60 , V_195 , V_223 ) ;
if ( error < 0 )
goto error;
if ( V_60 -> V_1 -> V_9 -> V_10 == 3 ) {
if ( V_60 -> V_192 == 0 || V_60 -> V_192 > V_244 )
V_60 -> V_192 = V_244 ;
if ( ! ( V_83 -> V_129 & V_245 ) )
V_60 -> V_150 |= V_246 ;
} else {
if ( V_60 -> V_192 == 0 || V_60 -> V_192 > V_247 )
V_60 -> V_192 = V_247 ;
}
if ( ! ( V_223 -> V_248 & V_249 ) ) {
error = V_60 -> V_1 -> V_9 -> V_250 ( V_60 , V_195 , V_223 ) ;
if ( error < 0 ) {
F_41 ( L_26 , - error ) ;
goto error;
}
}
memcpy ( & V_60 -> V_251 , & V_223 -> V_251 , sizeof( V_60 -> V_251 ) ) ;
F_41 ( L_27 ,
( unsigned long long ) V_60 -> V_251 . V_252 ,
( unsigned long long ) V_60 -> V_251 . V_253 ) ;
F_103 ( V_60 ) ;
V_60 -> V_254 = V_255 ;
F_122 ( V_223 ) ;
return V_60 ;
error:
F_122 ( V_223 ) ;
F_115 ( V_60 ) ;
return F_12 ( error ) ;
}
struct V_1 *
F_123 ( struct V_39 * V_39 , int V_256 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_39 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
V_2 = F_124 ( & V_6 -> V_12 , V_256 ) ;
if ( V_2 )
F_64 ( & V_2 -> V_24 ) ;
F_6 ( & V_6 -> V_15 ) ;
return V_2 ;
}
struct V_1 *
F_125 ( struct V_39 * V_39 , const struct V_63 * V_28 ,
struct V_257 * V_258 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_39 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
F_63 (clp, &nn->nfs_client_list, cl_share_link) {
if ( F_60 ( V_28 , V_2 , 1 ) == false )
continue;
if ( ! F_23 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_50 -> V_259 . V_83 ,
V_258 -> V_83 , V_260 ) != 0 )
continue;
F_64 ( & V_2 -> V_24 ) ;
F_6 ( & V_6 -> V_15 ) ;
return V_2 ;
}
F_6 ( & V_6 -> V_15 ) ;
return NULL ;
}
struct V_1 *
F_125 ( struct V_39 * V_39 , const struct V_63 * V_28 ,
struct V_257 * V_258 )
{
return NULL ;
}
static int F_126 ( struct V_1 * V_2 )
{
int error ;
if ( V_2 -> V_9 -> V_10 == 4 ) {
struct V_261 * V_262 ;
V_262 = F_127 ( V_2 -> V_35 -> V_263 ) ;
if ( F_23 ( V_2 ) ) {
error = F_128 ( V_262 ,
V_264 ) ;
if ( error < 0 )
return error ;
}
error = F_129 ( V_2 -> V_47 -> V_53 , V_262 ) ;
if ( error < 0 ) {
F_41 ( L_28 ,
V_87 , error ) ;
return error ;
}
F_130 ( V_51 , & V_2 -> V_52 ) ;
}
return 0 ;
}
static int F_131 ( struct V_1 * V_2 )
{
#if F_132 ( V_265 )
if ( V_2 -> V_47 -> V_53 ) {
struct V_266 * V_267 = NULL ;
V_267 = F_133 ( V_2 ) ;
if ( ! V_267 )
return - V_14 ;
V_2 -> V_50 = V_267 ;
F_72 ( V_2 , V_82 ) ;
}
#endif
return F_126 ( V_2 ) ;
}
struct V_1 * F_134 ( struct V_1 * V_2 ,
const struct V_88 * V_89 ,
const char * V_90 ,
T_2 V_91 )
{
char V_268 [ V_269 + 1 ] ;
int error ;
if ( V_2 -> V_25 == V_81 ) {
F_41 ( L_29 , V_2 ) ;
return V_2 ;
}
V_2 -> V_9 = & V_270 ;
F_130 ( V_128 , & V_2 -> V_94 ) ;
error = F_77 ( V_2 , V_89 , V_91 ) ;
if ( error < 0 )
goto error;
if ( V_90 == NULL ) {
struct V_271 V_272 ;
struct V_63 * V_84 = (struct V_63 * ) & V_272 ;
error = F_135 ( V_2 -> V_35 , V_84 , sizeof( V_272 ) ) ;
if ( error < 0 )
goto error;
error = F_136 ( V_84 , V_268 , sizeof( V_268 ) ) ;
if ( error < 0 )
goto error;
V_90 = ( const char * ) V_268 ;
}
F_137 ( V_2 -> V_273 , V_90 , sizeof( V_2 -> V_273 ) ) ;
error = F_138 ( V_2 ) ;
if ( error < 0 ) {
F_41 ( L_30 ,
V_87 , error ) ;
goto error;
}
F_130 ( V_55 , & V_2 -> V_52 ) ;
error = F_131 ( V_2 ) ;
if ( error < 0 )
goto error;
if ( ! F_23 ( V_2 ) )
F_72 ( V_2 , V_81 ) ;
return V_2 ;
error:
F_72 ( V_2 , error ) ;
F_46 ( V_2 ) ;
F_41 ( L_31 , error ) ;
return F_12 ( error ) ;
}
static int F_139 ( struct V_59 * V_60 ,
const char * V_31 ,
const struct V_63 * V_28 ,
const T_3 V_29 ,
const char * V_90 ,
T_2 V_91 ,
int V_38 , const struct V_88 * V_89 ,
T_1 V_3 , struct V_39 * V_39 )
{
struct V_18 V_19 = {
. V_31 = V_31 ,
. V_28 = V_28 ,
. V_29 = V_29 ,
. V_9 = & V_270 ,
. V_38 = V_38 ,
. V_3 = V_3 ,
. V_39 = V_39 ,
} ;
struct V_1 * V_2 ;
int error ;
F_41 ( L_32 ) ;
if ( V_60 -> V_129 & V_141 )
F_93 ( V_131 , & V_19 . V_95 ) ;
V_2 = F_69 ( & V_19 , V_89 , V_90 , V_91 ) ;
if ( F_19 ( V_2 ) ) {
error = F_71 ( V_2 ) ;
goto error;
}
F_93 ( V_274 , & V_2 -> V_52 ) ;
V_60 -> V_1 = V_2 ;
F_41 ( L_33 , V_2 ) ;
return 0 ;
error:
F_41 ( L_34 , error ) ;
return error ;
}
struct V_1 * F_140 ( struct V_1 * V_275 ,
const struct V_63 * V_276 , int V_277 ,
int V_278 , unsigned int V_279 , unsigned int V_280 )
{
struct V_18 V_19 = {
. V_28 = V_276 ,
. V_29 = V_277 ,
. V_9 = & V_270 ,
. V_38 = V_278 ,
. V_3 = V_275 -> V_46 ,
. V_39 = V_275 -> V_7 ,
} ;
struct V_88 V_281 ;
struct V_1 * V_2 ;
F_75 ( & V_281 , V_278 , V_279 , V_280 ) ;
V_2 = F_69 ( & V_19 , & V_281 , V_275 -> V_273 ,
V_275 -> V_35 -> V_155 -> V_156 ) ;
F_41 ( L_35 , V_87 , V_2 ) ;
return V_2 ;
}
static void F_141 ( struct V_59 * V_60 )
{
#ifdef V_265
struct V_266 * V_282 ;
T_1 V_283 ;
T_1 V_284 ;
if ( ! F_23 ( V_60 -> V_1 ) )
return;
V_282 = V_60 -> V_1 -> V_50 ;
V_283 = V_282 -> V_285 . V_286 - V_287 ;
V_284 = V_282 -> V_285 . V_288 - V_289 ;
if ( V_60 -> V_178 > V_283 )
V_60 -> V_178 = V_283 ;
if ( V_60 -> V_179 > V_284 )
V_60 -> V_179 = V_284 ;
#endif
}
static int F_142 ( struct V_59 * V_60 ,
struct V_194 * V_195 )
{
struct V_222 * V_223 ;
int error ;
F_50 ( ! V_60 -> V_1 ) ;
F_50 ( ! V_60 -> V_1 -> V_9 ) ;
F_50 ( ! V_60 -> V_1 -> V_9 -> V_243 ) ;
if ( F_143 ( V_60 -> V_1 ) )
return - V_165 ;
V_223 = F_121 () ;
if ( V_223 == NULL )
return - V_14 ;
error = F_144 ( V_60 ) ;
if ( error < 0 )
goto V_290;
error = F_145 ( V_60 , V_195 ) ;
if ( error < 0 )
goto V_290;
F_41 ( L_27 ,
( unsigned long long ) V_60 -> V_251 . V_252 ,
( unsigned long long ) V_60 -> V_251 . V_253 ) ;
F_41 ( L_36 , V_195 -> V_291 ) ;
F_141 ( V_60 ) ;
error = F_100 ( V_60 , V_195 , V_223 ) ;
if ( error < 0 )
goto V_290;
if ( V_60 -> V_192 == 0 || V_60 -> V_192 > V_292 )
V_60 -> V_192 = V_292 ;
F_103 ( V_60 ) ;
V_60 -> V_254 = V_255 ;
V_60 -> V_144 = F_38 ;
V_290:
F_122 ( V_223 ) ;
return error ;
}
static int F_146 ( struct V_59 * V_60 ,
const struct V_162 * V_83 )
{
struct V_88 V_89 ;
int error ;
F_41 ( L_37 ) ;
F_75 ( & V_89 , V_83 -> V_59 . V_120 ,
V_83 -> V_99 , V_83 -> V_100 ) ;
V_60 -> V_129 = V_83 -> V_129 ;
V_60 -> V_150 |= V_293 | V_177 | V_294 ;
if ( ! ( V_83 -> V_129 & V_245 ) )
V_60 -> V_150 |= V_246 ;
V_60 -> V_166 = V_83 -> V_166 ;
error = F_139 ( V_60 ,
V_83 -> V_59 . V_31 ,
( const struct V_63 * ) & V_83 -> V_59 . V_121 ,
V_83 -> V_59 . V_29 ,
V_83 -> V_295 ,
V_83 -> V_185 [ 0 ] ,
V_83 -> V_59 . V_120 ,
& V_89 ,
V_83 -> V_3 ,
V_83 -> V_39 ) ;
if ( error < 0 )
goto error;
if ( V_296 && V_83 -> V_185 [ 0 ] == V_161 )
V_60 -> V_150 |= V_297 ;
if ( V_83 -> V_178 )
V_60 -> V_178 = F_94 ( V_83 -> V_178 , NULL ) ;
if ( V_83 -> V_179 )
V_60 -> V_179 = F_94 ( V_83 -> V_179 , NULL ) ;
V_60 -> V_180 = V_83 -> V_180 * V_102 ;
V_60 -> V_181 = V_83 -> V_181 * V_102 ;
V_60 -> V_182 = V_83 -> V_182 * V_102 ;
V_60 -> V_183 = V_83 -> V_183 * V_102 ;
V_60 -> V_184 = V_83 -> V_59 . V_184 ;
error = F_86 ( V_60 , & V_89 , V_83 -> V_185 [ 0 ] ) ;
error:
F_41 ( L_38 , error ) ;
return error ;
}
struct V_59 * F_147 ( const struct V_162 * V_83 ,
struct V_194 * V_195 )
{
struct V_59 * V_60 ;
int error ;
F_41 ( L_39 ) ;
V_60 = F_110 () ;
if ( ! V_60 )
return F_12 ( - V_14 ) ;
error = F_146 ( V_60 , V_83 ) ;
if ( error < 0 )
goto error;
error = F_142 ( V_60 , V_195 ) ;
if ( error < 0 )
goto error;
F_41 ( L_40 , V_60 ) ;
return V_60 ;
error:
F_115 ( V_60 ) ;
F_41 ( L_41 , error ) ;
return F_12 ( error ) ;
}
struct V_59 * F_148 ( struct V_298 * V_83 ,
struct V_194 * V_195 )
{
struct V_1 * V_299 ;
struct V_59 * V_60 , * V_300 ;
int error ;
F_41 ( L_42 ) ;
V_60 = F_110 () ;
if ( ! V_60 )
return F_12 ( - V_14 ) ;
V_300 = F_149 ( V_83 -> V_301 ) ;
V_299 = V_300 -> V_1 ;
F_102 ( V_60 , V_300 ) ;
V_60 -> V_150 |= V_293 | V_177 ;
error = F_139 ( V_60 , V_83 -> V_31 ,
V_83 -> V_28 ,
V_83 -> V_29 ,
V_299 -> V_273 ,
V_83 -> V_127 ,
F_150 ( V_300 -> V_148 ) ,
V_300 -> V_148 -> V_154 ,
V_299 -> V_47 -> V_53 ,
V_299 -> V_7 ) ;
if ( error < 0 )
goto error;
error = F_86 ( V_60 , V_300 -> V_148 -> V_154 , V_83 -> V_127 ) ;
if ( error < 0 )
goto error;
error = F_142 ( V_60 , V_195 ) ;
if ( error < 0 )
goto error;
F_41 ( L_43 , V_60 ) ;
return V_60 ;
error:
F_115 ( V_60 ) ;
F_41 ( L_44 , error ) ;
return F_12 ( error ) ;
}
struct V_59 * F_151 ( struct V_59 * V_231 ,
struct V_194 * V_302 ,
struct V_222 * V_223 ,
T_2 V_116 )
{
struct V_59 * V_60 ;
struct V_222 * V_303 ;
int error ;
F_41 ( L_45 ,
( unsigned long long ) V_223 -> V_251 . V_252 ,
( unsigned long long ) V_223 -> V_251 . V_253 ) ;
V_60 = F_110 () ;
if ( ! V_60 )
return F_12 ( - V_14 ) ;
error = - V_14 ;
V_303 = F_121 () ;
if ( V_303 == NULL )
goto V_304;
V_60 -> V_1 = V_231 -> V_1 ;
V_60 -> V_144 = V_231 -> V_144 ;
F_64 ( & V_60 -> V_1 -> V_24 ) ;
F_102 ( V_60 , V_231 ) ;
V_60 -> V_251 = V_223 -> V_251 ;
error = F_86 ( V_60 ,
V_231 -> V_148 -> V_154 ,
V_116 ) ;
if ( error < 0 )
goto V_304;
if ( ! F_19 ( V_231 -> V_147 ) )
F_84 ( V_60 ) ;
error = F_100 ( V_60 , V_302 , V_303 ) ;
if ( error < 0 )
goto V_304;
if ( V_60 -> V_192 == 0 || V_60 -> V_192 > V_292 )
V_60 -> V_192 = V_292 ;
F_41 ( L_46 ,
( unsigned long long ) V_60 -> V_251 . V_252 ,
( unsigned long long ) V_60 -> V_251 . V_253 ) ;
error = F_82 ( V_60 ) ;
if ( error < 0 )
goto V_304;
F_103 ( V_60 ) ;
V_60 -> V_254 = V_255 ;
F_122 ( V_303 ) ;
F_41 ( L_47 , V_60 ) ;
return V_60 ;
V_304:
F_122 ( V_303 ) ;
F_115 ( V_60 ) ;
F_41 ( L_48 , error ) ;
return F_12 ( error ) ;
}
void F_152 ( struct V_39 * V_39 )
{
struct V_5 * V_6 = F_2 ( V_39 , V_8 ) ;
F_11 ( & V_6 -> V_93 ) ;
F_11 ( & V_6 -> V_234 ) ;
#ifdef F_14
F_153 ( & V_6 -> V_12 ) ;
#endif
F_15 ( & V_6 -> V_15 ) ;
V_6 -> V_305 = V_306 ;
}
static int F_154 ( struct V_307 * V_307 , struct V_308 * V_308 )
{
struct V_309 * V_310 ;
int V_4 ;
struct V_311 * V_312 = V_308 -> V_313 -> V_314 -> V_315 ;
struct V_39 * V_39 = V_312 -> V_316 -> V_317 -> V_318 ;
V_4 = F_155 ( V_308 , & V_319 ) ;
if ( V_4 < 0 )
return V_4 ;
V_310 = V_308 -> V_320 ;
V_310 -> V_321 = V_39 ;
return 0 ;
}
static void * F_156 ( struct V_309 * V_310 , T_4 * V_322 )
{
struct V_5 * V_6 = F_2 ( V_310 -> V_321 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
return F_157 ( & V_6 -> V_93 , * V_322 ) ;
}
static void * F_158 ( struct V_309 * V_323 , void * V_324 , T_4 * V_325 )
{
struct V_5 * V_6 = F_2 ( V_323 -> V_321 , V_8 ) ;
return F_159 ( V_324 , & V_6 -> V_93 , V_325 ) ;
}
static void F_160 ( struct V_309 * V_323 , void * V_324 )
{
struct V_5 * V_6 = F_2 ( V_323 -> V_321 , V_8 ) ;
F_6 ( & V_6 -> V_15 ) ;
}
static int F_161 ( struct V_309 * V_310 , void * V_324 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_310 -> V_321 , V_8 ) ;
if ( V_324 == & V_6 -> V_93 ) {
F_162 ( V_310 , L_49 ) ;
return 0 ;
}
V_2 = F_163 ( V_324 , struct V_1 , V_62 ) ;
if ( V_2 -> V_25 != V_81 )
return 0 ;
F_164 () ;
F_165 ( V_310 , L_50 ,
V_2 -> V_9 -> V_10 ,
F_166 ( V_2 -> V_35 , V_326 ) ,
F_166 ( V_2 -> V_35 , V_327 ) ,
F_47 ( & V_2 -> V_24 ) ,
V_2 -> V_32 ) ;
F_167 () ;
return 0 ;
}
static int F_168 ( struct V_307 * V_307 , struct V_308 * V_308 )
{
struct V_309 * V_310 ;
int V_4 ;
struct V_311 * V_312 = V_308 -> V_313 -> V_314 -> V_315 ;
struct V_39 * V_39 = V_312 -> V_316 -> V_317 -> V_318 ;
V_4 = F_155 ( V_308 , & V_328 ) ;
if ( V_4 < 0 )
return V_4 ;
V_310 = V_308 -> V_320 ;
V_310 -> V_321 = V_39 ;
return 0 ;
}
static void * F_169 ( struct V_309 * V_310 , T_4 * V_322 )
{
struct V_5 * V_6 = F_2 ( V_310 -> V_321 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
return F_157 ( & V_6 -> V_234 , * V_322 ) ;
}
static void * F_170 ( struct V_309 * V_323 , void * V_324 , T_4 * V_325 )
{
struct V_5 * V_6 = F_2 ( V_323 -> V_321 , V_8 ) ;
return F_159 ( V_324 , & V_6 -> V_234 , V_325 ) ;
}
static void F_171 ( struct V_309 * V_323 , void * V_324 )
{
struct V_5 * V_6 = F_2 ( V_323 -> V_321 , V_8 ) ;
F_6 ( & V_6 -> V_15 ) ;
}
static int F_172 ( struct V_309 * V_310 , void * V_324 )
{
struct V_59 * V_60 ;
struct V_1 * V_2 ;
char V_329 [ 8 ] , V_251 [ 17 ] ;
struct V_5 * V_6 = F_2 ( V_310 -> V_321 , V_8 ) ;
if ( V_324 == & V_6 -> V_234 ) {
F_162 ( V_310 , L_51 ) ;
return 0 ;
}
V_60 = F_163 ( V_324 , struct V_59 , V_233 ) ;
V_2 = V_60 -> V_1 ;
snprintf ( V_329 , 8 , L_52 ,
F_173 ( V_60 -> V_330 ) , F_174 ( V_60 -> V_330 ) ) ;
snprintf ( V_251 , 17 , L_53 ,
( unsigned long long ) V_60 -> V_251 . V_252 ,
( unsigned long long ) V_60 -> V_251 . V_253 ) ;
F_164 () ;
F_165 ( V_310 , L_54 ,
V_2 -> V_9 -> V_10 ,
F_166 ( V_2 -> V_35 , V_326 ) ,
F_166 ( V_2 -> V_35 , V_327 ) ,
V_329 ,
V_251 ,
F_175 ( V_60 ) ) ;
F_167 () ;
return 0 ;
}
int T_5 F_176 ( void )
{
struct V_331 * V_323 ;
V_332 = F_177 ( L_55 , NULL ) ;
if ( ! V_332 )
goto V_23;
V_323 = F_178 ( L_56 , V_333 | V_334 ,
V_332 , & V_335 ) ;
if ( ! V_323 )
goto V_336;
V_323 = F_178 ( L_57 , V_333 | V_334 ,
V_332 , & V_337 ) ;
if ( ! V_323 )
goto V_338;
return 0 ;
V_338:
F_179 ( L_56 , V_332 ) ;
V_336:
F_179 ( L_55 , NULL ) ;
V_23:
return - V_14 ;
}
void F_180 ( void )
{
F_179 ( L_57 , V_332 ) ;
F_179 ( L_56 , V_332 ) ;
F_179 ( L_55 , NULL ) ;
}
