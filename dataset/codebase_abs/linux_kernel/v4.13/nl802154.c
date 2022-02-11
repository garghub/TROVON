static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * * V_5 )
{
struct V_6 * V_7 ;
struct V_1 * V_8 = NULL ;
bool V_9 = V_5 [ V_10 ] ;
bool V_11 = V_5 [ V_12 ] ;
T_1 V_13 ;
int V_14 = - 1 ;
int V_15 = - 1 ;
F_2 () ;
if ( ! V_9 && ! V_11 )
return F_3 ( - V_16 ) ;
if ( V_9 )
V_15 = F_4 ( V_5 [ V_10 ] ) ;
if ( V_11 ) {
V_13 = F_5 ( V_5 [ V_12 ] ) ;
V_14 = V_13 >> 32 ;
}
F_6 (rdev, &cfg802154_rdev_list, list) {
struct V_1 * V_1 ;
if ( F_7 ( & V_7 -> V_17 ) != V_3 )
continue;
if ( V_11 && V_7 -> V_14 != V_14 )
continue;
F_6 (wpan_dev, &rdev->wpan_dev_list, list) {
if ( V_9 && V_1 -> V_18 &&
V_1 -> V_18 -> V_19 == V_15 ) {
V_8 = V_1 ;
break;
}
if ( V_11 &&
V_1 -> V_20 == ( V_21 ) V_13 ) {
V_8 = V_1 ;
break;
}
}
if ( V_8 )
break;
}
if ( V_8 )
return V_8 ;
return F_3 ( - V_22 ) ;
}
static struct V_6 *
F_8 ( struct V_2 * V_3 , struct V_4 * * V_5 )
{
struct V_6 * V_7 = NULL , * V_23 ;
struct V_24 * V_18 ;
F_2 () ;
if ( ! V_5 [ V_25 ] &&
! V_5 [ V_10 ] &&
! V_5 [ V_12 ] )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_25 ] )
V_7 = F_9 (
F_4 ( V_5 [ V_25 ] ) ) ;
if ( V_5 [ V_12 ] ) {
T_1 V_13 = F_5 ( V_5 [ V_12 ] ) ;
struct V_1 * V_1 ;
bool V_26 = false ;
V_23 = F_9 ( V_13 >> 32 ) ;
if ( V_23 ) {
F_6 (wpan_dev, &tmp->wpan_dev_list, list) {
if ( V_1 -> V_20 != ( V_21 ) V_13 )
continue;
V_26 = true ;
break;
}
if ( ! V_26 )
V_23 = NULL ;
if ( V_7 && V_23 != V_7 )
return F_3 ( - V_16 ) ;
V_7 = V_23 ;
}
}
if ( V_5 [ V_10 ] ) {
int V_19 = F_4 ( V_5 [ V_10 ] ) ;
V_18 = F_10 ( V_3 , V_19 ) ;
if ( V_18 ) {
if ( V_18 -> V_27 )
V_23 = F_11 (
V_18 -> V_27 -> V_17 ) ;
else
V_23 = NULL ;
if ( ! V_23 )
return F_3 ( - V_16 ) ;
if ( V_7 && V_23 != V_7 )
return F_3 ( - V_16 ) ;
V_7 = V_23 ;
}
}
if ( ! V_7 )
return F_3 ( - V_22 ) ;
if ( V_3 != F_7 ( & V_7 -> V_17 ) )
return F_3 ( - V_22 ) ;
return V_7 ;
}
static struct V_6 *
F_12 ( struct V_2 * V_3 , struct V_28 * V_29 )
{
return F_8 ( V_3 , V_29 -> V_5 ) ;
}
static int
F_13 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
struct V_6 * * V_7 ,
struct V_1 * * V_1 )
{
int V_34 ;
F_14 () ;
if ( ! V_33 -> args [ 0 ] ) {
V_34 = F_15 ( V_33 -> V_35 , V_36 + V_37 . V_38 ,
F_16 ( & V_37 ) ,
V_37 . V_39 , V_40 , NULL ) ;
if ( V_34 )
goto V_41;
* V_1 = F_1 ( F_17 ( V_31 -> V_42 ) ,
F_16 ( & V_37 ) ) ;
if ( F_18 ( * V_1 ) ) {
V_34 = F_19 ( * V_1 ) ;
goto V_41;
}
* V_7 = F_11 ( ( * V_1 ) -> V_17 ) ;
V_33 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_33 -> args [ 1 ] = ( * V_1 ) -> V_20 ;
} else {
struct V_17 * V_17 = F_20 ( V_33 -> args [ 0 ] - 1 ) ;
struct V_1 * V_23 ;
if ( ! V_17 ) {
V_34 = - V_22 ;
goto V_41;
}
* V_7 = F_11 ( V_17 ) ;
* V_1 = NULL ;
F_6 (tmp, &(*rdev)->wpan_dev_list, list) {
if ( V_23 -> V_20 == V_33 -> args [ 1 ] ) {
* V_1 = V_23 ;
break;
}
}
if ( ! * V_1 ) {
V_34 = - V_22 ;
goto V_41;
}
}
return 0 ;
V_41:
F_21 () ;
return V_34 ;
}
static void
F_22 ( struct V_6 * V_7 )
{
F_21 () ;
}
static inline void * F_23 ( struct V_30 * V_31 , V_21 V_43 , V_21 V_44 ,
int V_45 , T_2 V_46 )
{
return F_24 ( V_31 , V_43 , V_44 , & V_37 , V_45 , V_46 ) ;
}
static int
F_25 ( struct V_30 * V_47 , int V_48 , V_21 V_49 )
{
struct V_4 * V_50 = F_26 ( V_47 , V_48 ) ;
int V_51 ;
if ( ! V_50 )
return - V_52 ;
V_51 = 0 ;
while ( V_49 ) {
if ( ( V_49 & 1 ) && F_27 ( V_47 , V_51 ) )
return - V_52 ;
V_49 >>= 1 ;
V_51 ++ ;
}
F_28 ( V_47 , V_50 ) ;
return 0 ;
}
static int
F_29 ( struct V_6 * V_7 ,
struct V_30 * V_47 )
{
struct V_4 * V_53 ;
unsigned long V_54 ;
V_53 = F_26 ( V_47 , V_55 ) ;
if ( ! V_53 )
return - V_52 ;
for ( V_54 = 0 ; V_54 <= V_56 ; V_54 ++ ) {
if ( F_30 ( V_47 , V_57 ,
V_7 -> V_17 . V_58 . V_59 [ V_54 ] ) )
return - V_52 ;
}
F_28 ( V_47 , V_53 ) ;
return 0 ;
}
static int
F_31 ( struct V_30 * V_47 ,
struct V_6 * V_7 )
{
const struct V_60 * V_61 = & V_7 -> V_17 . V_58 ;
struct V_4 * V_62 , * V_63 ;
int V_51 ;
V_62 = F_26 ( V_47 , V_64 ) ;
if ( ! V_62 )
return - V_52 ;
V_63 = F_26 ( V_47 , V_65 ) ;
if ( ! V_63 )
return - V_52 ;
for ( V_51 = 0 ; V_51 <= V_56 ; V_51 ++ ) {
if ( V_61 -> V_59 [ V_51 ] ) {
if ( F_25 ( V_47 , V_51 , V_61 -> V_59 [ V_51 ] ) )
return - V_52 ;
}
}
F_28 ( V_47 , V_63 ) ;
if ( V_7 -> V_17 . V_45 & V_66 ) {
struct V_4 * V_67 ;
V_67 = F_26 ( V_47 ,
V_68 ) ;
if ( ! V_67 )
return - V_52 ;
for ( V_51 = 0 ; V_51 < V_61 -> V_69 ; V_51 ++ ) {
if ( F_32 ( V_47 , V_51 , V_61 -> V_70 [ V_51 ] ) )
return - V_52 ;
}
F_28 ( V_47 , V_67 ) ;
}
if ( V_7 -> V_17 . V_45 & V_71 ) {
struct V_4 * V_72 ;
V_72 = F_26 ( V_47 , V_73 ) ;
if ( ! V_72 )
return - V_52 ;
for ( V_51 = 0 ; V_51 < V_61 -> V_74 ; V_51 ++ ) {
if ( F_32 ( V_47 , V_51 , V_61 -> V_75 [ V_51 ] ) )
return - V_52 ;
}
F_28 ( V_47 , V_72 ) ;
}
if ( V_7 -> V_17 . V_45 & V_76 ) {
if ( F_25 ( V_47 , V_77 ,
V_61 -> V_78 ) ||
F_25 ( V_47 , V_79 ,
V_61 -> V_80 ) )
return - V_52 ;
}
if ( F_33 ( V_47 , V_81 , V_61 -> V_82 ) ||
F_33 ( V_47 , V_83 , V_61 -> V_84 ) ||
F_33 ( V_47 , V_85 , V_61 -> V_86 ) ||
F_33 ( V_47 , V_87 , V_61 -> V_88 ) ||
F_33 ( V_47 , V_89 ,
V_61 -> V_90 ) ||
F_33 ( V_47 , V_91 ,
V_61 -> V_92 ) ||
F_34 ( V_47 , V_93 ,
V_61 -> V_94 ) ||
F_34 ( V_47 , V_95 ,
V_61 -> V_96 ) ||
F_25 ( V_47 , V_97 ,
V_61 -> V_98 ) ||
F_30 ( V_47 , V_99 , V_61 -> V_100 ) )
return - V_52 ;
F_28 ( V_47 , V_62 ) ;
return 0 ;
}
static int F_35 ( struct V_6 * V_7 ,
enum V_101 V_46 ,
struct V_30 * V_47 , V_21 V_43 , V_21 V_44 ,
int V_45 )
{
struct V_4 * V_102 ;
void * V_103 ;
int V_51 ;
V_103 = F_23 ( V_47 , V_43 , V_44 , V_45 , V_46 ) ;
if ( ! V_103 )
return - V_52 ;
if ( F_30 ( V_47 , V_25 , V_7 -> V_14 ) ||
F_36 ( V_47 , V_104 ,
F_37 ( & V_7 -> V_17 ) ) ||
F_30 ( V_47 , V_105 ,
V_106 ) )
goto V_107;
if ( V_46 != V_108 )
goto V_109;
if ( F_33 ( V_47 , V_110 ,
V_7 -> V_17 . V_111 ) ||
F_33 ( V_47 , V_112 ,
V_7 -> V_17 . V_113 ) )
goto V_107;
if ( F_29 ( V_7 , V_47 ) )
goto V_107;
if ( V_7 -> V_17 . V_45 & V_76 ) {
if ( F_30 ( V_47 , V_114 ,
V_7 -> V_17 . V_115 . V_116 ) )
goto V_107;
if ( V_7 -> V_17 . V_115 . V_116 == V_117 ) {
if ( F_30 ( V_47 , V_118 ,
V_7 -> V_17 . V_115 . V_119 ) )
goto V_107;
}
}
if ( V_7 -> V_17 . V_45 & V_71 ) {
if ( F_32 ( V_47 , V_120 ,
V_7 -> V_17 . V_121 ) )
goto V_107;
}
if ( V_7 -> V_17 . V_45 & V_66 ) {
if ( F_32 ( V_47 , V_122 ,
V_7 -> V_17 . V_123 ) )
goto V_107;
}
if ( F_31 ( V_47 , V_7 ) )
goto V_107;
V_102 = F_26 ( V_47 , V_124 ) ;
if ( ! V_102 )
goto V_107;
V_51 = 0 ;
#define F_38 ( T_3 , T_4 ) \
do { \
if (rdev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL802154_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_38 ( V_125 , V_126 ) ;
F_38 ( V_127 , V_128 ) ;
F_38 ( V_129 , V_130 ) ;
F_38 ( V_131 , V_132 ) ;
F_38 ( V_133 , V_134 ) ;
F_38 ( V_135 , V_136 ) ;
F_38 ( V_137 , V_138 ) ;
F_38 ( V_139 , V_140 ) ;
F_38 ( V_141 , V_142 ) ;
F_38 ( V_143 , V_144 ) ;
if ( V_7 -> V_17 . V_45 & V_71 )
F_38 ( V_145 , V_146 ) ;
if ( V_7 -> V_17 . V_45 & V_66 )
F_38 ( V_147 , V_148 ) ;
if ( V_7 -> V_17 . V_45 & V_76 )
F_38 ( V_149 , V_150 ) ;
#undef F_38
F_28 ( V_47 , V_102 ) ;
V_109:
F_39 ( V_47 , V_103 ) ;
return 0 ;
V_107:
F_40 ( V_47 , V_103 ) ;
return - V_151 ;
}
static int F_41 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
struct V_152 * V_153 )
{
struct V_4 * * V_154 = F_16 ( & V_37 ) ;
int V_155 = F_15 ( V_33 -> V_35 , V_36 + V_37 . V_38 , V_154 ,
V_37 . V_39 , V_40 , NULL ) ;
if ( V_155 )
return 0 ;
if ( V_154 [ V_25 ] )
V_153 -> V_156 = F_4 ( V_154 [ V_25 ] ) ;
if ( V_154 [ V_12 ] )
V_153 -> V_156 = F_5 ( V_154 [ V_12 ] ) >> 32 ;
if ( V_154 [ V_10 ] ) {
struct V_24 * V_18 ;
struct V_6 * V_7 ;
int V_15 = F_4 ( V_154 [ V_10 ] ) ;
V_18 = F_10 ( & V_157 , V_15 ) ;
if ( ! V_18 )
return - V_22 ;
if ( V_18 -> V_27 ) {
V_7 = F_11 (
V_18 -> V_27 -> V_17 ) ;
V_153 -> V_156 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int
F_42 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
int V_158 = 0 , V_155 ;
struct V_152 * V_153 = ( void * ) V_33 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_14 () ;
if ( ! V_153 ) {
V_153 = F_43 ( sizeof( * V_153 ) , V_159 ) ;
if ( ! V_153 ) {
F_21 () ;
return - V_160 ;
}
V_153 -> V_156 = - 1 ;
V_155 = F_41 ( V_31 , V_33 , V_153 ) ;
if ( V_155 ) {
F_44 ( V_153 ) ;
F_21 () ;
return V_155 ;
}
V_33 -> args [ 0 ] = ( long ) V_153 ;
}
F_6 (rdev, &cfg802154_rdev_list, list) {
if ( ! F_45 ( F_7 ( & V_7 -> V_17 ) , F_17 ( V_31 -> V_42 ) ) )
continue;
if ( ++ V_158 <= V_153 -> V_161 )
continue;
if ( V_153 -> V_156 != - 1 &&
V_153 -> V_156 != V_7 -> V_14 )
continue;
V_155 = F_35 ( V_7 ,
V_108 ,
V_31 ,
F_46 ( V_33 -> V_31 ) . V_43 ,
V_33 -> V_35 -> V_162 , V_163 ) ;
if ( V_155 < 0 ) {
if ( ( V_155 == - V_52 || V_155 == - V_151 ) &&
! V_31 -> V_164 && V_33 -> V_165 < 4096 ) {
V_33 -> V_165 = 4096 ;
F_21 () ;
return 1 ;
}
V_158 -- ;
break;
}
break;
}
F_21 () ;
V_153 -> V_161 = V_158 ;
return V_31 -> V_164 ;
}
static int F_47 ( struct V_32 * V_33 )
{
F_44 ( ( void * ) V_33 -> args [ 0 ] ) ;
return 0 ;
}
static int F_48 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_30 * V_47 ;
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
V_47 = F_49 ( V_167 , V_159 ) ;
if ( ! V_47 )
return - V_160 ;
if ( F_35 ( V_7 , V_108 , V_47 ,
V_29 -> V_168 , V_29 -> V_169 , 0 ) < 0 ) {
F_50 ( V_47 ) ;
return - V_52 ;
}
return F_51 ( V_47 , V_29 ) ;
}
static inline T_1 V_13 ( struct V_1 * V_1 )
{
return ( T_1 ) V_1 -> V_20 |
( ( T_1 ) F_11 ( V_1 -> V_17 ) -> V_14 << 32 ) ;
}
static int
F_52 ( struct V_30 * V_47 ,
const struct V_170 * V_171 )
{
struct V_4 * V_172 ;
if ( F_30 ( V_47 , V_173 , V_171 -> V_116 ) )
return - V_52 ;
switch ( V_171 -> V_116 ) {
case V_174 :
V_172 = F_26 ( V_47 , V_175 ) ;
if ( ! V_172 )
return - V_52 ;
if ( F_53 ( V_47 , V_176 ,
V_171 -> V_177 . V_178 ) ||
F_30 ( V_47 , V_179 ,
V_171 -> V_177 . V_116 ) )
return - V_52 ;
switch ( V_171 -> V_177 . V_116 ) {
case V_180 :
if ( F_53 ( V_47 , V_181 ,
V_171 -> V_177 . V_182 ) )
return - V_52 ;
break;
case V_183 :
if ( F_54 ( V_47 , V_184 ,
V_171 -> V_177 . V_185 ,
V_186 ) )
return - V_52 ;
break;
default:
break;
}
F_28 ( V_47 , V_172 ) ;
break;
case V_187 :
break;
case V_188 :
if ( F_55 ( V_47 , V_189 ,
V_171 -> V_190 ) )
return - V_52 ;
break;
case V_191 :
if ( F_54 ( V_47 , V_192 ,
V_171 -> V_193 ,
V_194 ) )
return - V_52 ;
break;
default:
break;
}
if ( V_171 -> V_116 != V_174 ) {
if ( F_33 ( V_47 , V_195 , V_171 -> V_196 ) )
return - V_52 ;
}
return 0 ;
}
static int F_56 ( struct V_30 * V_47 ,
struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_4 * V_197 ;
struct V_198 V_199 ;
int V_155 ;
V_155 = F_57 ( V_7 , V_1 , & V_199 ) ;
if ( V_155 < 0 )
return V_155 ;
if ( F_33 ( V_47 , V_200 , V_199 . V_201 ) ||
F_30 ( V_47 , V_202 , V_199 . V_203 ) ||
F_58 ( V_47 , V_204 ,
V_199 . V_205 ) )
return - V_52 ;
V_197 = F_26 ( V_47 , V_206 ) ;
if ( ! V_197 )
return - V_52 ;
V_155 = F_52 ( V_47 , & V_199 . V_207 ) ;
if ( V_155 < 0 )
return V_155 ;
F_28 ( V_47 , V_197 ) ;
return 0 ;
}
static int
F_59 ( struct V_30 * V_47 , V_21 V_43 , V_21 V_44 , int V_45 ,
struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_24 * V_208 = V_1 -> V_18 ;
void * V_103 ;
V_103 = F_23 ( V_47 , V_43 , V_44 , V_45 ,
V_209 ) ;
if ( ! V_103 )
return - 1 ;
if ( V_208 &&
( F_30 ( V_47 , V_10 , V_208 -> V_19 ) ||
F_36 ( V_47 , V_210 , V_208 -> V_211 ) ) )
goto V_107;
if ( F_30 ( V_47 , V_25 , V_7 -> V_14 ) ||
F_30 ( V_47 , V_212 , V_1 -> V_213 ) ||
F_60 ( V_47 , V_12 ,
V_13 ( V_1 ) , V_214 ) ||
F_30 ( V_47 , V_105 ,
V_7 -> V_215 ^
( V_106 << 2 ) ) )
goto V_107;
if ( F_54 ( V_47 , V_216 ,
V_1 -> V_185 ,
V_214 ) ||
F_53 ( V_47 , V_217 ,
V_1 -> V_182 ) ||
F_53 ( V_47 , V_218 , V_1 -> V_178 ) )
goto V_107;
if ( F_34 ( V_47 , V_219 ,
V_1 -> V_220 ) ||
F_33 ( V_47 , V_221 , V_1 -> V_222 ) ||
F_33 ( V_47 , V_223 ,
V_1 -> V_224 ) ||
F_33 ( V_47 , V_225 , V_1 -> V_226 ) )
goto V_107;
if ( F_33 ( V_47 , V_227 , V_1 -> V_100 ) )
goto V_107;
if ( F_33 ( V_47 , V_228 , V_1 -> V_229 ) )
goto V_107;
#ifdef F_61
if ( F_56 ( V_47 , V_7 , V_1 ) < 0 )
goto V_107;
#endif
F_39 ( V_47 , V_103 ) ;
return 0 ;
V_107:
F_40 ( V_47 , V_103 ) ;
return - V_151 ;
}
static int
F_62 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
int V_230 = 0 ;
int V_231 = 0 ;
int V_232 = V_33 -> args [ 0 ] ;
int V_233 = V_33 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
F_14 () ;
F_6 (rdev, &cfg802154_rdev_list, list) {
if ( ! F_45 ( F_7 ( & V_7 -> V_17 ) , F_17 ( V_31 -> V_42 ) ) )
continue;
if ( V_230 < V_232 ) {
V_230 ++ ;
continue;
}
V_231 = 0 ;
F_6 (wpan_dev, &rdev->wpan_dev_list, list) {
if ( V_231 < V_233 ) {
V_231 ++ ;
continue;
}
if ( F_59 ( V_31 , F_46 ( V_33 -> V_31 ) . V_43 ,
V_33 -> V_35 -> V_162 , V_163 ,
V_7 , V_1 ) < 0 ) {
goto V_234;
}
V_231 ++ ;
}
V_230 ++ ;
}
V_234:
F_21 () ;
V_33 -> args [ 0 ] = V_230 ;
V_33 -> args [ 1 ] = V_231 ;
return V_31 -> V_164 ;
}
static int F_63 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_30 * V_47 ;
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_1 * V_235 = V_29 -> V_166 [ 1 ] ;
V_47 = F_49 ( V_167 , V_159 ) ;
if ( ! V_47 )
return - V_160 ;
if ( F_59 ( V_47 , V_29 -> V_168 , V_29 -> V_169 , 0 ,
V_7 , V_235 ) < 0 ) {
F_50 ( V_47 ) ;
return - V_52 ;
}
return F_51 ( V_47 , V_29 ) ;
}
static int F_64 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
enum V_236 type = V_237 ;
T_5 V_185 = F_65 ( 0x0000000000000000ULL ) ;
if ( ! V_29 -> V_5 [ V_210 ] )
return - V_16 ;
if ( V_29 -> V_5 [ V_212 ] ) {
type = F_4 ( V_29 -> V_5 [ V_212 ] ) ;
if ( type > V_238 ||
! ( V_7 -> V_17 . V_58 . V_98 & F_66 ( type ) ) )
return - V_16 ;
}
if ( V_29 -> V_5 [ V_216 ] )
V_185 = F_67 ( V_29 -> V_5 [ V_216 ] ) ;
if ( ! V_7 -> V_239 -> V_125 )
return - V_240 ;
return F_68 ( V_7 ,
F_69 ( V_29 -> V_5 [ V_210 ] ) ,
V_241 , type , V_185 ) ;
}
static int F_70 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_1 * V_1 = V_29 -> V_166 [ 1 ] ;
if ( ! V_7 -> V_239 -> V_127 )
return - V_240 ;
if ( ! V_1 -> V_18 )
V_29 -> V_166 [ 1 ] = NULL ;
return F_71 ( V_7 , V_1 ) ;
}
static int F_72 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
T_2 V_242 , V_54 ;
if ( ! V_29 -> V_5 [ V_110 ] ||
! V_29 -> V_5 [ V_112 ] )
return - V_16 ;
V_54 = F_73 ( V_29 -> V_5 [ V_110 ] ) ;
V_242 = F_73 ( V_29 -> V_5 [ V_112 ] ) ;
if ( V_54 > V_56 || V_242 > V_243 ||
! ( V_7 -> V_17 . V_58 . V_59 [ V_54 ] & F_66 ( V_242 ) ) )
return - V_16 ;
return F_74 ( V_7 , V_54 , V_242 ) ;
}
static int F_75 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_244 V_115 ;
if ( ! ( V_7 -> V_17 . V_45 & V_76 ) )
return - V_240 ;
if ( ! V_29 -> V_5 [ V_114 ] )
return - V_16 ;
V_115 . V_116 = F_4 ( V_29 -> V_5 [ V_114 ] ) ;
if ( V_115 . V_116 < V_245 ||
V_115 . V_116 > V_246 ||
! ( V_7 -> V_17 . V_58 . V_78 & F_66 ( V_115 . V_116 ) ) )
return - V_16 ;
if ( V_115 . V_116 == V_117 ) {
if ( ! V_29 -> V_5 [ V_118 ] )
return - V_16 ;
V_115 . V_119 = F_4 ( V_29 -> V_5 [ V_118 ] ) ;
if ( V_115 . V_119 > V_247 ||
! ( V_7 -> V_17 . V_58 . V_80 & F_66 ( V_115 . V_119 ) ) )
return - V_16 ;
}
return F_76 ( V_7 , & V_115 ) ;
}
static int F_77 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
T_6 V_248 ;
int V_51 ;
if ( ! ( V_7 -> V_17 . V_45 & V_66 ) )
return - V_240 ;
if ( ! V_29 -> V_5 [ V_122 ] )
return - V_16 ;
V_248 = F_78 ( V_29 -> V_5 [ V_122 ] ) ;
for ( V_51 = 0 ; V_51 < V_7 -> V_17 . V_58 . V_69 ; V_51 ++ ) {
if ( V_248 == V_7 -> V_17 . V_58 . V_70 [ V_51 ] )
return F_79 ( V_7 , V_248 ) ;
}
return - V_16 ;
}
static int F_80 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
T_6 V_249 ;
int V_51 ;
if ( ! ( V_7 -> V_17 . V_45 & V_71 ) )
return - V_240 ;
if ( ! V_29 -> V_5 [ V_120 ] )
return - V_16 ;
V_249 = F_78 ( V_29 -> V_5 [ V_120 ] ) ;
for ( V_51 = 0 ; V_51 < V_7 -> V_17 . V_58 . V_74 ; V_51 ++ ) {
if ( V_249 == V_7 -> V_17 . V_58 . V_75 [ V_51 ] )
return F_81 ( V_7 , V_249 ) ;
}
return - V_16 ;
}
static int F_82 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
T_7 V_178 ;
if ( F_83 ( V_208 ) )
return - V_250 ;
if ( V_1 -> V_251 ) {
if ( F_83 ( V_1 -> V_251 ) )
return - V_250 ;
}
if ( V_1 -> V_213 == V_252 ||
! V_29 -> V_5 [ V_218 ] )
return - V_16 ;
V_178 = F_84 ( V_29 -> V_5 [ V_218 ] ) ;
if ( V_178 == F_85 ( V_253 ) )
return - V_16 ;
return F_86 ( V_7 , V_1 , V_178 ) ;
}
static int F_87 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
T_7 V_182 ;
if ( F_83 ( V_208 ) )
return - V_250 ;
if ( V_1 -> V_251 ) {
if ( F_83 ( V_1 -> V_251 ) )
return - V_250 ;
}
if ( V_1 -> V_213 == V_252 ||
! V_29 -> V_5 [ V_217 ] )
return - V_16 ;
V_182 = F_84 ( V_29 -> V_5 [ V_217 ] ) ;
if ( V_182 == F_85 ( V_254 ) ||
V_182 == F_85 ( V_255 ) )
return - V_16 ;
return F_88 ( V_7 , V_1 , V_182 ) ;
}
static int
F_89 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
T_2 V_226 , V_222 ;
if ( F_83 ( V_208 ) )
return - V_250 ;
if ( ! V_29 -> V_5 [ V_225 ] ||
! V_29 -> V_5 [ V_221 ] )
return - V_16 ;
V_226 = F_73 ( V_29 -> V_5 [ V_225 ] ) ;
V_222 = F_73 ( V_29 -> V_5 [ V_221 ] ) ;
if ( V_226 < V_7 -> V_17 . V_58 . V_82 ||
V_226 > V_7 -> V_17 . V_58 . V_84 ||
V_222 < V_7 -> V_17 . V_58 . V_86 ||
V_222 > V_7 -> V_17 . V_58 . V_88 ||
V_226 > V_222 )
return - V_16 ;
return F_90 ( V_7 , V_1 , V_226 , V_222 ) ;
}
static int
F_91 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
T_2 V_92 ;
if ( F_83 ( V_208 ) )
return - V_250 ;
if ( ! V_29 -> V_5 [ V_223 ] )
return - V_16 ;
V_92 = F_73 (
V_29 -> V_5 [ V_223 ] ) ;
if ( V_92 < V_7 -> V_17 . V_58 . V_90 ||
V_92 > V_7 -> V_17 . V_58 . V_92 )
return - V_16 ;
return F_92 ( V_7 , V_1 , V_92 ) ;
}
static int
F_93 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
T_8 V_96 ;
if ( F_83 ( V_208 ) )
return - V_250 ;
if ( ! V_29 -> V_5 [ V_219 ] )
return - V_16 ;
V_96 = F_94 (
V_29 -> V_5 [ V_219 ] ) ;
if ( V_96 < V_7 -> V_17 . V_58 . V_94 ||
V_96 > V_7 -> V_17 . V_58 . V_96 )
return - V_16 ;
return F_95 ( V_7 , V_1 , V_96 ) ;
}
static int F_96 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
int V_116 ;
if ( F_83 ( V_208 ) )
return - V_250 ;
if ( ! V_29 -> V_5 [ V_227 ] )
return - V_16 ;
V_116 = F_73 ( V_29 -> V_5 [ V_227 ] ) ;
if ( V_116 != 0 && V_116 != 1 )
return - V_16 ;
if ( ! F_97 ( V_116 , V_7 -> V_17 . V_58 . V_100 ) )
return - V_16 ;
return F_98 ( V_7 , V_1 , V_116 ) ;
}
static int
F_99 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
int V_229 ;
if ( F_83 ( V_208 ) )
return - V_250 ;
if ( ! V_29 -> V_5 [ V_228 ] )
return - V_16 ;
V_229 = F_73 ( V_29 -> V_5 [ V_228 ] ) ;
if ( V_229 != 0 && V_229 != 1 )
return - V_16 ;
return F_100 ( V_7 , V_1 , V_229 ) ;
}
static int F_101 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_2 * V_2 ;
int V_34 ;
if ( V_29 -> V_5 [ V_256 ] ) {
V_21 V_257 = F_4 ( V_29 -> V_5 [ V_256 ] ) ;
V_2 = F_102 ( V_257 ) ;
} else if ( V_29 -> V_5 [ V_258 ] ) {
V_21 V_259 = F_4 ( V_29 -> V_5 [ V_258 ] ) ;
V_2 = F_103 ( V_259 ) ;
} else {
return - V_16 ;
}
if ( F_18 ( V_2 ) )
return F_19 ( V_2 ) ;
V_34 = 0 ;
if ( ! F_45 ( F_7 ( & V_7 -> V_17 ) , V_2 ) )
V_34 = F_104 ( V_7 , V_2 ) ;
F_105 ( V_2 ) ;
return V_34 ;
}
static int
F_106 ( struct V_4 * V_260 ,
struct V_261 * V_262 )
{
struct V_4 * V_5 [ V_263 + 1 ] ;
if ( ! V_260 || F_107 ( V_5 , V_263 , V_260 ,
V_264 , NULL ) )
return - V_16 ;
if ( ! V_5 [ V_176 ] ||
! V_5 [ V_179 ] ||
! ( V_5 [ V_181 ] ||
V_5 [ V_184 ] ) )
return - V_16 ;
V_262 -> V_178 = F_84 ( V_5 [ V_176 ] ) ;
V_262 -> V_116 = F_4 ( V_5 [ V_179 ] ) ;
switch ( V_262 -> V_116 ) {
case V_180 :
V_262 -> V_182 = F_84 ( V_5 [ V_181 ] ) ;
break;
case V_183 :
V_262 -> V_185 = F_67 ( V_5 [ V_184 ] ) ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int
F_108 ( struct V_4 * V_260 ,
struct V_170 * V_171 )
{
struct V_4 * V_5 [ V_265 + 1 ] ;
if ( ! V_260 || F_107 ( V_5 , V_265 , V_260 ,
V_266 , NULL ) )
return - V_16 ;
if ( ! V_5 [ V_173 ] )
return - V_16 ;
V_171 -> V_116 = F_4 ( V_5 [ V_173 ] ) ;
switch ( V_171 -> V_116 ) {
case V_174 :
if ( ! V_5 [ V_175 ] )
return - V_16 ;
if ( F_106 ( V_5 [ V_175 ] ,
& V_171 -> V_177 ) < 0 )
return - V_16 ;
break;
case V_187 :
break;
case V_188 :
if ( ! V_5 [ V_189 ] )
return - V_16 ;
V_171 -> V_190 = F_109 ( V_5 [ V_189 ] ) ;
break;
case V_191 :
if ( ! V_5 [ V_192 ] )
return - V_16 ;
V_171 -> V_193 = F_67 ( V_5 [ V_192 ] ) ;
break;
default:
return - V_16 ;
}
if ( V_171 -> V_116 != V_174 ) {
if ( ! V_5 [ V_195 ] )
return - V_16 ;
V_171 -> V_196 = F_73 ( V_5 [ V_195 ] ) ;
}
return 0 ;
}
static int F_110 ( struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
struct V_198 V_199 ;
V_21 V_267 = 0 ;
int V_155 ;
if ( V_29 -> V_5 [ V_200 ] ) {
T_2 V_201 ;
V_201 = F_73 ( V_29 -> V_5 [ V_200 ] ) ;
if ( V_201 != 0 && V_201 != 1 )
return - V_16 ;
V_199 . V_201 = F_73 ( V_29 -> V_5 [ V_200 ] ) ;
V_267 |= V_268 ;
}
if ( V_29 -> V_5 [ V_206 ] ) {
V_155 = F_108 ( V_29 -> V_5 [ V_206 ] ,
& V_199 . V_207 ) ;
if ( V_155 < 0 )
return V_155 ;
V_267 |= V_269 ;
}
if ( V_29 -> V_5 [ V_202 ] ) {
V_199 . V_203 = F_4 ( V_29 -> V_5 [ V_202 ] ) ;
if ( V_199 . V_203 > V_270 )
return - V_16 ;
V_267 |= V_271 ;
}
if ( V_29 -> V_5 [ V_204 ] ) {
V_199 . V_205 = F_111 ( V_29 -> V_5 [ V_204 ] ) ;
V_267 |= V_272 ;
}
return F_112 ( V_7 , V_1 , & V_199 , V_267 ) ;
}
static int F_113 ( struct V_30 * V_47 , V_21 V_46 , V_21 V_43 ,
V_21 V_44 , int V_45 ,
struct V_6 * V_7 ,
struct V_24 * V_208 ,
const struct V_273 * V_274 )
{
void * V_103 ;
V_21 V_275 [ V_276 / 32 ] ;
struct V_4 * V_277 , * V_197 ;
V_103 = F_23 ( V_47 , V_43 , V_44 , V_45 , V_46 ) ;
if ( ! V_103 )
return - 1 ;
if ( F_30 ( V_47 , V_10 , V_208 -> V_19 ) )
goto V_107;
V_277 = F_26 ( V_47 , V_278 ) ;
if ( ! V_277 )
goto V_107;
V_197 = F_26 ( V_47 , V_279 ) ;
if ( ! V_197 )
goto V_107;
if ( F_52 ( V_47 , & V_274 -> V_196 ) < 0 )
goto V_107;
F_28 ( V_47 , V_197 ) ;
if ( F_33 ( V_47 , V_280 ,
V_274 -> V_274 -> V_281 ) )
goto V_107;
if ( V_274 -> V_274 -> V_281 & F_66 ( V_282 ) ) {
memset ( V_275 , 0 , sizeof( V_275 ) ) ;
V_275 [ 7 ] = V_274 -> V_274 -> V_283 ;
if ( F_114 ( V_47 , V_284 ,
sizeof( V_275 ) , V_275 ) )
goto V_107;
}
if ( F_114 ( V_47 , V_285 , V_286 ,
V_274 -> V_274 -> V_274 ) )
goto V_107;
F_28 ( V_47 , V_277 ) ;
F_39 ( V_47 , V_103 ) ;
return 0 ;
V_107:
F_40 ( V_47 , V_103 ) ;
return - V_151 ;
}
static int
F_115 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_6 * V_7 = NULL ;
struct V_273 * V_274 ;
struct V_287 * V_288 ;
struct V_1 * V_1 ;
int V_34 ;
V_34 = F_13 ( V_31 , V_33 , & V_7 , & V_1 ) ;
if ( V_34 )
return V_34 ;
if ( ! V_1 -> V_18 ) {
V_34 = - V_16 ;
goto V_289;
}
F_116 ( V_7 , V_1 ) ;
F_117 ( V_7 , V_1 , & V_288 ) ;
if ( V_33 -> args [ 2 ] )
goto V_234;
F_6 (key, &table->keys, list) {
if ( F_113 ( V_31 , V_290 ,
F_46 ( V_33 -> V_31 ) . V_43 ,
V_33 -> V_35 -> V_162 , V_163 ,
V_7 , V_1 -> V_18 , V_274 ) < 0 ) {
V_34 = - V_291 ;
F_118 ( V_7 , V_1 ) ;
goto V_289;
}
}
V_33 -> args [ 2 ] = 1 ;
V_234:
F_118 ( V_7 , V_1 ) ;
V_34 = V_31 -> V_164 ;
V_289:
F_22 ( V_7 ) ;
return V_34 ;
}
static int F_119 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
struct V_4 * V_5 [ V_292 + 1 ] ;
struct V_293 V_274 = { } ;
struct V_170 V_196 = { } ;
V_21 V_275 [ V_276 / 32 ] = { } ;
if ( F_107 ( V_5 , V_292 ,
V_29 -> V_5 [ V_278 ] ,
V_294 , V_29 -> V_295 ) )
return - V_16 ;
if ( ! V_5 [ V_280 ] ||
! V_5 [ V_285 ] )
return - V_16 ;
if ( F_108 ( V_5 [ V_279 ] , & V_196 ) < 0 )
return - V_52 ;
V_274 . V_281 = F_73 ( V_5 [ V_280 ] ) ;
if ( V_274 . V_281 > F_66 ( V_296 ) ||
( ( V_274 . V_281 & F_66 ( V_282 ) ) &&
! V_5 [ V_284 ] ) )
return - V_16 ;
if ( V_5 [ V_284 ] ) {
F_120 ( V_275 , V_5 [ V_284 ] ,
V_276 / 8 ) ;
if ( V_275 [ 0 ] || V_275 [ 1 ] || V_275 [ 2 ] || V_275 [ 3 ] ||
V_275 [ 4 ] || V_275 [ 5 ] || V_275 [ 6 ] ||
V_275 [ 7 ] > F_66 ( V_297 ) )
return - V_16 ;
V_274 . V_283 = V_275 [ 7 ] ;
} else {
V_274 . V_283 = 0 ;
}
F_120 ( V_274 . V_274 , V_5 [ V_285 ] , V_286 ) ;
if ( F_108 ( V_5 [ V_279 ] , & V_196 ) < 0 )
return - V_52 ;
return F_121 ( V_7 , V_1 , & V_196 , & V_274 ) ;
}
static int F_122 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
struct V_4 * V_5 [ V_292 + 1 ] ;
struct V_170 V_196 ;
if ( F_107 ( V_5 , V_292 ,
V_29 -> V_5 [ V_278 ] ,
V_294 , V_29 -> V_295 ) )
return - V_16 ;
if ( F_108 ( V_5 [ V_279 ] , & V_196 ) < 0 )
return - V_52 ;
return F_123 ( V_7 , V_1 , & V_196 ) ;
}
static int F_124 ( struct V_30 * V_47 , V_21 V_46 , V_21 V_43 ,
V_21 V_44 , int V_45 ,
struct V_6 * V_7 ,
struct V_24 * V_208 ,
const struct V_298 * V_299 )
{
void * V_103 ;
struct V_4 * V_300 ;
V_103 = F_23 ( V_47 , V_43 , V_44 , V_45 , V_46 ) ;
if ( ! V_103 )
return - 1 ;
if ( F_30 ( V_47 , V_10 , V_208 -> V_19 ) )
goto V_107;
V_300 = F_26 ( V_47 , V_301 ) ;
if ( ! V_300 )
goto V_107;
if ( F_30 ( V_47 , V_302 ,
V_299 -> V_205 ) ||
F_53 ( V_47 , V_303 , V_299 -> V_178 ) ||
F_53 ( V_47 , V_304 ,
V_299 -> V_182 ) ||
F_54 ( V_47 , V_305 ,
V_299 -> V_306 , V_307 ) ||
F_33 ( V_47 , V_308 ,
V_299 -> V_309 ) ||
F_30 ( V_47 , V_310 , V_299 -> V_311 ) )
goto V_107;
F_28 ( V_47 , V_300 ) ;
F_39 ( V_47 , V_103 ) ;
return 0 ;
V_107:
F_40 ( V_47 , V_103 ) ;
return - V_151 ;
}
static int
F_125 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_6 * V_7 = NULL ;
struct V_298 * V_208 ;
struct V_287 * V_288 ;
struct V_1 * V_1 ;
int V_34 ;
V_34 = F_13 ( V_31 , V_33 , & V_7 , & V_1 ) ;
if ( V_34 )
return V_34 ;
if ( ! V_1 -> V_18 ) {
V_34 = - V_16 ;
goto V_289;
}
F_116 ( V_7 , V_1 ) ;
F_117 ( V_7 , V_1 , & V_288 ) ;
if ( V_33 -> args [ 2 ] )
goto V_234;
F_6 (dev, &table->devices, list) {
if ( F_124 ( V_31 , V_312 ,
F_46 ( V_33 -> V_31 ) . V_43 ,
V_33 -> V_35 -> V_162 , V_163 ,
V_7 , V_1 -> V_18 , V_208 ) < 0 ) {
V_34 = - V_291 ;
F_118 ( V_7 , V_1 ) ;
goto V_289;
}
}
V_33 -> args [ 2 ] = 1 ;
V_234:
F_118 ( V_7 , V_1 ) ;
V_34 = V_31 -> V_164 ;
V_289:
F_22 ( V_7 ) ;
return V_34 ;
}
static int
F_126 ( struct V_4 * V_260 ,
struct V_298 * V_208 )
{
struct V_4 * V_5 [ V_313 + 1 ] ;
if ( ! V_260 || F_107 ( V_5 , V_313 ,
V_260 , V_314 , NULL ) )
return - V_16 ;
memset ( V_208 , 0 , sizeof( * V_208 ) ) ;
if ( ! V_5 [ V_302 ] ||
! V_5 [ V_303 ] ||
! V_5 [ V_304 ] ||
! V_5 [ V_305 ] ||
! V_5 [ V_308 ] ||
! V_5 [ V_310 ] )
return - V_16 ;
V_208 -> V_205 = F_4 ( V_5 [ V_302 ] ) ;
V_208 -> V_178 = F_84 ( V_5 [ V_303 ] ) ;
V_208 -> V_182 = F_84 ( V_5 [ V_304 ] ) ;
V_208 -> V_306 = F_67 ( V_5 [ V_305 ] ) ;
V_208 -> V_309 = F_73 ( V_5 [ V_308 ] ) ;
V_208 -> V_311 = F_4 ( V_5 [ V_310 ] ) ;
if ( V_208 -> V_311 > V_315 ||
( V_208 -> V_309 != 0 && V_208 -> V_309 != 1 ) )
return - V_16 ;
return 0 ;
}
static int F_127 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
struct V_298 V_299 ;
if ( F_126 ( V_29 -> V_5 [ V_301 ] ,
& V_299 ) < 0 )
return - V_16 ;
return F_128 ( V_7 , V_1 , & V_299 ) ;
}
static int F_129 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
struct V_4 * V_5 [ V_313 + 1 ] ;
T_5 V_185 ;
if ( F_107 ( V_5 , V_313 ,
V_29 -> V_5 [ V_301 ] ,
V_314 , V_29 -> V_295 ) )
return - V_16 ;
if ( ! V_5 [ V_305 ] )
return - V_16 ;
V_185 = F_67 ( V_5 [ V_305 ] ) ;
return F_130 ( V_7 , V_1 , V_185 ) ;
}
static int F_131 ( struct V_30 * V_47 , V_21 V_46 , V_21 V_43 ,
V_21 V_44 , int V_45 ,
struct V_6 * V_7 ,
struct V_24 * V_208 , T_5 V_185 ,
const struct V_316 * V_317 )
{
void * V_103 ;
struct V_4 * V_318 , * V_197 ;
V_103 = F_23 ( V_47 , V_43 , V_44 , V_45 , V_46 ) ;
if ( ! V_103 )
return - 1 ;
if ( F_30 ( V_47 , V_10 , V_208 -> V_19 ) )
goto V_107;
V_318 = F_26 ( V_47 , V_319 ) ;
if ( ! V_318 )
goto V_107;
if ( F_54 ( V_47 , V_320 ,
V_185 , V_321 ) ||
F_30 ( V_47 , V_322 ,
V_317 -> V_205 ) )
goto V_107;
V_197 = F_26 ( V_47 , V_323 ) ;
if ( ! V_197 )
goto V_107;
if ( F_52 ( V_47 , & V_317 -> V_324 ) < 0 )
goto V_107;
F_28 ( V_47 , V_197 ) ;
F_28 ( V_47 , V_318 ) ;
F_39 ( V_47 , V_103 ) ;
return 0 ;
V_107:
F_40 ( V_47 , V_103 ) ;
return - V_151 ;
}
static int
F_132 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_6 * V_7 = NULL ;
struct V_316 * V_325 ;
struct V_298 * V_326 ;
struct V_287 * V_288 ;
struct V_1 * V_1 ;
int V_34 ;
V_34 = F_13 ( V_31 , V_33 , & V_7 , & V_1 ) ;
if ( V_34 )
return V_34 ;
if ( ! V_1 -> V_18 ) {
V_34 = - V_16 ;
goto V_289;
}
F_116 ( V_7 , V_1 ) ;
F_117 ( V_7 , V_1 , & V_288 ) ;
if ( V_33 -> args [ 2 ] )
goto V_234;
F_6 (dpos, &table->devices, list) {
F_6 (kpos, &dpos->keys, list) {
if ( F_131 ( V_31 ,
V_312 ,
F_46 ( V_33 -> V_31 ) . V_43 ,
V_33 -> V_35 -> V_162 ,
V_163 , V_7 ,
V_1 -> V_18 ,
V_326 -> V_306 ,
V_325 ) < 0 ) {
V_34 = - V_291 ;
F_118 ( V_7 , V_1 ) ;
goto V_289;
}
}
}
V_33 -> args [ 2 ] = 1 ;
V_234:
F_118 ( V_7 , V_1 ) ;
V_34 = V_31 -> V_164 ;
V_289:
F_22 ( V_7 ) ;
return V_34 ;
}
static int F_133 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
struct V_4 * V_5 [ V_327 + 1 ] ;
struct V_316 V_274 ;
T_5 V_185 ;
if ( ! V_29 -> V_5 [ V_319 ] ||
F_107 ( V_5 , V_327 ,
V_29 -> V_5 [ V_319 ] ,
V_328 , V_29 -> V_295 ) < 0 )
return - V_16 ;
if ( ! V_5 [ V_322 ] ||
! V_5 [ V_320 ] )
return - V_16 ;
if ( F_108 ( V_5 [ V_323 ] ,
& V_274 . V_324 ) < 0 )
return - V_52 ;
V_274 . V_205 = F_4 ( V_5 [ V_322 ] ) ;
V_185 = F_67 ( V_5 [ V_320 ] ) ;
return F_134 ( V_7 , V_1 , V_185 , & V_274 ) ;
}
static int F_135 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
struct V_4 * V_5 [ V_327 + 1 ] ;
struct V_316 V_274 ;
T_5 V_185 ;
if ( F_107 ( V_5 , V_327 ,
V_29 -> V_5 [ V_319 ] ,
V_328 , V_29 -> V_295 ) )
return - V_16 ;
if ( ! V_5 [ V_320 ] )
return - V_16 ;
if ( F_108 ( V_5 [ V_323 ] ,
& V_274 . V_324 ) < 0 )
return - V_52 ;
V_185 = F_67 ( V_5 [ V_320 ] ) ;
return F_136 ( V_7 , V_1 , V_185 , & V_274 ) ;
}
static int F_137 ( struct V_30 * V_47 , V_21 V_46 , V_21 V_43 ,
V_21 V_44 , int V_45 ,
struct V_6 * V_7 ,
struct V_24 * V_208 ,
const struct V_329 * V_330 )
{
void * V_103 ;
struct V_4 * V_331 ;
V_103 = F_23 ( V_47 , V_43 , V_44 , V_45 , V_46 ) ;
if ( ! V_103 )
return - 1 ;
if ( F_30 ( V_47 , V_10 , V_208 -> V_19 ) )
goto V_107;
V_331 = F_26 ( V_47 , V_332 ) ;
if ( ! V_331 )
goto V_107;
if ( F_30 ( V_47 , V_333 , V_330 -> V_334 ) ||
F_30 ( V_47 , V_335 , V_330 -> V_336 ) ||
F_33 ( V_47 , V_337 ,
V_330 -> V_338 ) )
goto V_107;
if ( V_330 -> V_334 == V_282 ) {
if ( F_30 ( V_47 , V_339 ,
V_330 -> V_340 ) )
goto V_107;
}
F_28 ( V_47 , V_331 ) ;
F_39 ( V_47 , V_103 ) ;
return 0 ;
V_107:
F_40 ( V_47 , V_103 ) ;
return - V_151 ;
}
static int
F_138 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_6 * V_7 = NULL ;
struct V_329 * V_330 ;
struct V_287 * V_288 ;
struct V_1 * V_1 ;
int V_34 ;
V_34 = F_13 ( V_31 , V_33 , & V_7 , & V_1 ) ;
if ( V_34 )
return V_34 ;
if ( ! V_1 -> V_18 ) {
V_34 = - V_16 ;
goto V_289;
}
F_116 ( V_7 , V_1 ) ;
F_117 ( V_7 , V_1 , & V_288 ) ;
if ( V_33 -> args [ 2 ] )
goto V_234;
F_6 (sl, &table->security_levels, list) {
if ( F_137 ( V_31 , V_312 ,
F_46 ( V_33 -> V_31 ) . V_43 ,
V_33 -> V_35 -> V_162 , V_163 ,
V_7 , V_1 -> V_18 , V_330 ) < 0 ) {
V_34 = - V_291 ;
F_118 ( V_7 , V_1 ) ;
goto V_289;
}
}
V_33 -> args [ 2 ] = 1 ;
V_234:
F_118 ( V_7 , V_1 ) ;
V_34 = V_31 -> V_164 ;
V_289:
F_22 ( V_7 ) ;
return V_34 ;
}
static int
F_139 ( struct V_4 * V_260 , struct V_329 * V_330 )
{
struct V_4 * V_5 [ V_341 + 1 ] ;
if ( ! V_260 || F_107 ( V_5 , V_341 ,
V_260 , V_342 , NULL ) )
return - V_16 ;
memset ( V_330 , 0 , sizeof( * V_330 ) ) ;
if ( ! V_5 [ V_335 ] ||
! V_5 [ V_333 ] ||
! V_5 [ V_337 ] )
return - V_16 ;
V_330 -> V_336 = F_73 ( V_5 [ V_335 ] ) ;
V_330 -> V_334 = F_4 ( V_5 [ V_333 ] ) ;
V_330 -> V_338 = F_73 ( V_5 [ V_337 ] ) ;
if ( V_330 -> V_334 > V_296 ||
( V_330 -> V_338 != 0 && V_330 -> V_338 != 1 ) )
return - V_16 ;
if ( V_330 -> V_334 == V_282 ) {
if ( ! V_5 [ V_339 ] )
return - V_16 ;
V_330 -> V_340 = F_4 ( V_5 [ V_339 ] ) ;
if ( V_330 -> V_340 > V_297 )
return - V_16 ;
}
return 0 ;
}
static int F_140 ( struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
struct V_329 V_330 ;
if ( F_139 ( V_29 -> V_5 [ V_332 ] ,
& V_330 ) < 0 )
return - V_16 ;
return F_141 ( V_7 , V_1 , & V_330 ) ;
}
static int F_142 ( struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_166 [ 0 ] ;
struct V_24 * V_208 = V_29 -> V_166 [ 1 ] ;
struct V_1 * V_1 = V_208 -> V_27 ;
struct V_329 V_330 ;
if ( ! V_29 -> V_5 [ V_332 ] ||
F_139 ( V_29 -> V_5 [ V_332 ] ,
& V_330 ) < 0 )
return - V_16 ;
return F_143 ( V_7 , V_1 , & V_330 ) ;
}
static int F_144 ( const struct V_343 * V_239 , struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 ;
struct V_1 * V_1 ;
struct V_24 * V_208 ;
bool V_344 = V_239 -> V_345 & V_346 ;
if ( V_344 )
F_14 () ;
if ( V_239 -> V_345 & V_347 ) {
V_7 = F_12 ( F_145 ( V_29 ) , V_29 ) ;
if ( F_18 ( V_7 ) ) {
if ( V_344 )
F_21 () ;
return F_19 ( V_7 ) ;
}
V_29 -> V_166 [ 0 ] = V_7 ;
} else if ( V_239 -> V_345 & V_348 ||
V_239 -> V_345 & V_349 ) {
F_2 () ;
V_1 = F_1 ( F_145 ( V_29 ) ,
V_29 -> V_5 ) ;
if ( F_18 ( V_1 ) ) {
if ( V_344 )
F_21 () ;
return F_19 ( V_1 ) ;
}
V_208 = V_1 -> V_18 ;
V_7 = F_11 ( V_1 -> V_17 ) ;
if ( V_239 -> V_345 & V_348 ) {
if ( ! V_208 ) {
if ( V_344 )
F_21 () ;
return - V_16 ;
}
V_29 -> V_166 [ 1 ] = V_208 ;
} else {
V_29 -> V_166 [ 1 ] = V_1 ;
}
if ( V_208 ) {
if ( V_239 -> V_345 & V_350 &&
! F_83 ( V_208 ) ) {
if ( V_344 )
F_21 () ;
return - V_351 ;
}
F_146 ( V_208 ) ;
}
V_29 -> V_166 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_147 ( const struct V_343 * V_239 , struct V_30 * V_31 ,
struct V_28 * V_29 )
{
if ( V_29 -> V_166 [ 1 ] ) {
if ( V_239 -> V_345 & V_349 ) {
struct V_1 * V_1 = V_29 -> V_166 [ 1 ] ;
if ( V_1 -> V_18 )
F_148 ( V_1 -> V_18 ) ;
} else {
F_148 ( V_29 -> V_166 [ 1 ] ) ;
}
}
if ( V_239 -> V_345 & V_346 )
F_21 () ;
}
int T_9 F_149 ( void )
{
return F_150 ( & V_37 ) ;
}
void F_151 ( void )
{
F_152 ( & V_37 ) ;
}
