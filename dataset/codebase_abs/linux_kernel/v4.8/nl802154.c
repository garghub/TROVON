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
V_37 . V_39 , V_37 . V_40 ,
V_41 ) ;
if ( V_34 )
goto V_42;
* V_1 = F_1 ( F_16 ( V_31 -> V_43 ) ,
V_37 . V_39 ) ;
if ( F_17 ( * V_1 ) ) {
V_34 = F_18 ( * V_1 ) ;
goto V_42;
}
* V_7 = F_11 ( ( * V_1 ) -> V_17 ) ;
V_33 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_33 -> args [ 1 ] = ( * V_1 ) -> V_20 ;
} else {
struct V_17 * V_17 = F_19 ( V_33 -> args [ 0 ] - 1 ) ;
struct V_1 * V_23 ;
if ( ! V_17 ) {
V_34 = - V_22 ;
goto V_42;
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
goto V_42;
}
}
return 0 ;
V_42:
F_20 () ;
return V_34 ;
}
static void
F_21 ( struct V_6 * V_7 )
{
F_20 () ;
}
static inline void * F_22 ( struct V_30 * V_31 , V_21 V_44 , V_21 V_45 ,
int V_46 , T_2 V_47 )
{
return F_23 ( V_31 , V_44 , V_45 , & V_37 , V_46 , V_47 ) ;
}
static int
F_24 ( struct V_30 * V_48 , int V_49 , V_21 V_50 )
{
struct V_4 * V_51 = F_25 ( V_48 , V_49 ) ;
int V_52 ;
if ( ! V_51 )
return - V_53 ;
V_52 = 0 ;
while ( V_50 ) {
if ( ( V_50 & 1 ) && F_26 ( V_48 , V_52 ) )
return - V_53 ;
V_50 >>= 1 ;
V_52 ++ ;
}
F_27 ( V_48 , V_51 ) ;
return 0 ;
}
static int
F_28 ( struct V_6 * V_7 ,
struct V_30 * V_48 )
{
struct V_4 * V_54 ;
unsigned long V_55 ;
V_54 = F_25 ( V_48 , V_56 ) ;
if ( ! V_54 )
return - V_53 ;
for ( V_55 = 0 ; V_55 <= V_57 ; V_55 ++ ) {
if ( F_29 ( V_48 , V_58 ,
V_7 -> V_17 . V_59 . V_60 [ V_55 ] ) )
return - V_53 ;
}
F_27 ( V_48 , V_54 ) ;
return 0 ;
}
static int
F_30 ( struct V_30 * V_48 ,
struct V_6 * V_7 )
{
const struct V_61 * V_62 = & V_7 -> V_17 . V_59 ;
struct V_4 * V_63 , * V_64 ;
int V_52 ;
V_63 = F_25 ( V_48 , V_65 ) ;
if ( ! V_63 )
return - V_53 ;
V_64 = F_25 ( V_48 , V_66 ) ;
if ( ! V_64 )
return - V_53 ;
for ( V_52 = 0 ; V_52 <= V_57 ; V_52 ++ ) {
if ( V_62 -> V_60 [ V_52 ] ) {
if ( F_24 ( V_48 , V_52 , V_62 -> V_60 [ V_52 ] ) )
return - V_53 ;
}
}
F_27 ( V_48 , V_64 ) ;
if ( V_7 -> V_17 . V_46 & V_67 ) {
struct V_4 * V_68 ;
V_68 = F_25 ( V_48 ,
V_69 ) ;
if ( ! V_68 )
return - V_53 ;
for ( V_52 = 0 ; V_52 < V_62 -> V_70 ; V_52 ++ ) {
if ( F_31 ( V_48 , V_52 , V_62 -> V_71 [ V_52 ] ) )
return - V_53 ;
}
F_27 ( V_48 , V_68 ) ;
}
if ( V_7 -> V_17 . V_46 & V_72 ) {
struct V_4 * V_73 ;
V_73 = F_25 ( V_48 , V_74 ) ;
if ( ! V_73 )
return - V_53 ;
for ( V_52 = 0 ; V_52 < V_62 -> V_75 ; V_52 ++ ) {
if ( F_31 ( V_48 , V_52 , V_62 -> V_76 [ V_52 ] ) )
return - V_53 ;
}
F_27 ( V_48 , V_73 ) ;
}
if ( V_7 -> V_17 . V_46 & V_77 ) {
if ( F_24 ( V_48 , V_78 ,
V_62 -> V_79 ) ||
F_24 ( V_48 , V_80 ,
V_62 -> V_81 ) )
return - V_53 ;
}
if ( F_32 ( V_48 , V_82 , V_62 -> V_83 ) ||
F_32 ( V_48 , V_84 , V_62 -> V_85 ) ||
F_32 ( V_48 , V_86 , V_62 -> V_87 ) ||
F_32 ( V_48 , V_88 , V_62 -> V_89 ) ||
F_32 ( V_48 , V_90 ,
V_62 -> V_91 ) ||
F_32 ( V_48 , V_92 ,
V_62 -> V_93 ) ||
F_33 ( V_48 , V_94 ,
V_62 -> V_95 ) ||
F_33 ( V_48 , V_96 ,
V_62 -> V_97 ) ||
F_24 ( V_48 , V_98 ,
V_62 -> V_99 ) ||
F_29 ( V_48 , V_100 , V_62 -> V_101 ) )
return - V_53 ;
F_27 ( V_48 , V_63 ) ;
return 0 ;
}
static int F_34 ( struct V_6 * V_7 ,
enum V_102 V_47 ,
struct V_30 * V_48 , V_21 V_44 , V_21 V_45 ,
int V_46 )
{
struct V_4 * V_103 ;
void * V_104 ;
int V_52 ;
V_104 = F_22 ( V_48 , V_44 , V_45 , V_46 , V_47 ) ;
if ( ! V_104 )
return - V_53 ;
if ( F_29 ( V_48 , V_25 , V_7 -> V_14 ) ||
F_35 ( V_48 , V_105 ,
F_36 ( & V_7 -> V_17 ) ) ||
F_29 ( V_48 , V_106 ,
V_107 ) )
goto V_108;
if ( V_47 != V_109 )
goto V_110;
if ( F_32 ( V_48 , V_111 ,
V_7 -> V_17 . V_112 ) ||
F_32 ( V_48 , V_113 ,
V_7 -> V_17 . V_114 ) )
goto V_108;
if ( F_28 ( V_7 , V_48 ) )
goto V_108;
if ( V_7 -> V_17 . V_46 & V_77 ) {
if ( F_29 ( V_48 , V_115 ,
V_7 -> V_17 . V_116 . V_117 ) )
goto V_108;
if ( V_7 -> V_17 . V_116 . V_117 == V_118 ) {
if ( F_29 ( V_48 , V_119 ,
V_7 -> V_17 . V_116 . V_120 ) )
goto V_108;
}
}
if ( V_7 -> V_17 . V_46 & V_72 ) {
if ( F_31 ( V_48 , V_121 ,
V_7 -> V_17 . V_122 ) )
goto V_108;
}
if ( V_7 -> V_17 . V_46 & V_67 ) {
if ( F_31 ( V_48 , V_123 ,
V_7 -> V_17 . V_124 ) )
goto V_108;
}
if ( F_30 ( V_48 , V_7 ) )
goto V_108;
V_103 = F_25 ( V_48 , V_125 ) ;
if ( ! V_103 )
goto V_108;
V_52 = 0 ;
#define F_37 ( T_3 , T_4 ) \
do { \
if (rdev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL802154_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_37 ( V_126 , V_127 ) ;
F_37 ( V_128 , V_129 ) ;
F_37 ( V_130 , V_131 ) ;
F_37 ( V_132 , V_133 ) ;
F_37 ( V_134 , V_135 ) ;
F_37 ( V_136 , V_137 ) ;
F_37 ( V_138 , V_139 ) ;
F_37 ( V_140 , V_141 ) ;
F_37 ( V_142 , V_143 ) ;
F_37 ( V_144 , V_145 ) ;
if ( V_7 -> V_17 . V_46 & V_72 )
F_37 ( V_146 , V_147 ) ;
if ( V_7 -> V_17 . V_46 & V_67 )
F_37 ( V_148 , V_149 ) ;
if ( V_7 -> V_17 . V_46 & V_77 )
F_37 ( V_150 , V_151 ) ;
#undef F_37
F_27 ( V_48 , V_103 ) ;
V_110:
F_38 ( V_48 , V_104 ) ;
return 0 ;
V_108:
F_39 ( V_48 , V_104 ) ;
return - V_152 ;
}
static int F_40 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
struct V_153 * V_154 )
{
struct V_4 * * V_155 = V_37 . V_39 ;
int V_156 = F_15 ( V_33 -> V_35 , V_36 + V_37 . V_38 ,
V_155 , V_37 . V_40 , V_41 ) ;
if ( V_156 )
return 0 ;
if ( V_155 [ V_25 ] )
V_154 -> V_157 = F_4 ( V_155 [ V_25 ] ) ;
if ( V_155 [ V_12 ] )
V_154 -> V_157 = F_5 ( V_155 [ V_12 ] ) >> 32 ;
if ( V_155 [ V_10 ] ) {
struct V_24 * V_18 ;
struct V_6 * V_7 ;
int V_15 = F_4 ( V_155 [ V_10 ] ) ;
V_18 = F_10 ( & V_158 , V_15 ) ;
if ( ! V_18 )
return - V_22 ;
if ( V_18 -> V_27 ) {
V_7 = F_11 (
V_18 -> V_27 -> V_17 ) ;
V_154 -> V_157 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int
F_41 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
int V_159 = 0 , V_156 ;
struct V_153 * V_154 = ( void * ) V_33 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_14 () ;
if ( ! V_154 ) {
V_154 = F_42 ( sizeof( * V_154 ) , V_160 ) ;
if ( ! V_154 ) {
F_20 () ;
return - V_161 ;
}
V_154 -> V_157 = - 1 ;
V_156 = F_40 ( V_31 , V_33 , V_154 ) ;
if ( V_156 ) {
F_43 ( V_154 ) ;
F_20 () ;
return V_156 ;
}
V_33 -> args [ 0 ] = ( long ) V_154 ;
}
F_6 (rdev, &cfg802154_rdev_list, list) {
if ( ! F_44 ( F_7 ( & V_7 -> V_17 ) , F_16 ( V_31 -> V_43 ) ) )
continue;
if ( ++ V_159 <= V_154 -> V_162 )
continue;
if ( V_154 -> V_157 != - 1 &&
V_154 -> V_157 != V_7 -> V_14 )
continue;
V_156 = F_34 ( V_7 ,
V_109 ,
V_31 ,
F_45 ( V_33 -> V_31 ) . V_44 ,
V_33 -> V_35 -> V_163 , V_164 ) ;
if ( V_156 < 0 ) {
if ( ( V_156 == - V_53 || V_156 == - V_152 ) &&
! V_31 -> V_165 && V_33 -> V_166 < 4096 ) {
V_33 -> V_166 = 4096 ;
F_20 () ;
return 1 ;
}
V_159 -- ;
break;
}
break;
}
F_20 () ;
V_154 -> V_162 = V_159 ;
return V_31 -> V_165 ;
}
static int F_46 ( struct V_32 * V_33 )
{
F_43 ( ( void * ) V_33 -> args [ 0 ] ) ;
return 0 ;
}
static int F_47 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_30 * V_48 ;
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
V_48 = F_48 ( V_168 , V_160 ) ;
if ( ! V_48 )
return - V_161 ;
if ( F_34 ( V_7 , V_109 , V_48 ,
V_29 -> V_169 , V_29 -> V_170 , 0 ) < 0 ) {
F_49 ( V_48 ) ;
return - V_53 ;
}
return F_50 ( V_48 , V_29 ) ;
}
static inline T_1 V_13 ( struct V_1 * V_1 )
{
return ( T_1 ) V_1 -> V_20 |
( ( T_1 ) F_11 ( V_1 -> V_17 ) -> V_14 << 32 ) ;
}
static int
F_51 ( struct V_30 * V_48 ,
const struct V_171 * V_172 )
{
struct V_4 * V_173 ;
if ( F_29 ( V_48 , V_174 , V_172 -> V_117 ) )
return - V_53 ;
switch ( V_172 -> V_117 ) {
case V_175 :
V_173 = F_25 ( V_48 , V_176 ) ;
if ( ! V_173 )
return - V_53 ;
if ( F_52 ( V_48 , V_177 ,
V_172 -> V_178 . V_179 ) ||
F_29 ( V_48 , V_180 ,
V_172 -> V_178 . V_117 ) )
return - V_53 ;
switch ( V_172 -> V_178 . V_117 ) {
case V_181 :
if ( F_52 ( V_48 , V_182 ,
V_172 -> V_178 . V_183 ) )
return - V_53 ;
break;
case V_184 :
if ( F_53 ( V_48 , V_185 ,
V_172 -> V_178 . V_186 ,
V_187 ) )
return - V_53 ;
break;
default:
break;
}
F_27 ( V_48 , V_173 ) ;
break;
case V_188 :
break;
case V_189 :
if ( F_54 ( V_48 , V_190 ,
V_172 -> V_191 ) )
return - V_53 ;
break;
case V_192 :
if ( F_53 ( V_48 , V_193 ,
V_172 -> V_194 ,
V_195 ) )
return - V_53 ;
break;
default:
break;
}
if ( V_172 -> V_117 != V_175 ) {
if ( F_32 ( V_48 , V_196 , V_172 -> V_197 ) )
return - V_53 ;
}
return 0 ;
}
static int F_55 ( struct V_30 * V_48 ,
struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_4 * V_198 ;
struct V_199 V_200 ;
int V_156 ;
V_156 = F_56 ( V_7 , V_1 , & V_200 ) ;
if ( V_156 < 0 )
return V_156 ;
if ( F_32 ( V_48 , V_201 , V_200 . V_202 ) ||
F_29 ( V_48 , V_203 , V_200 . V_204 ) ||
F_57 ( V_48 , V_205 ,
V_200 . V_206 ) )
return - V_53 ;
V_198 = F_25 ( V_48 , V_207 ) ;
if ( ! V_198 )
return - V_53 ;
V_156 = F_51 ( V_48 , & V_200 . V_208 ) ;
if ( V_156 < 0 )
return V_156 ;
F_27 ( V_48 , V_198 ) ;
return 0 ;
}
static int
F_58 ( struct V_30 * V_48 , V_21 V_44 , V_21 V_45 , int V_46 ,
struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_24 * V_209 = V_1 -> V_18 ;
void * V_104 ;
V_104 = F_22 ( V_48 , V_44 , V_45 , V_46 ,
V_210 ) ;
if ( ! V_104 )
return - 1 ;
if ( V_209 &&
( F_29 ( V_48 , V_10 , V_209 -> V_19 ) ||
F_35 ( V_48 , V_211 , V_209 -> V_212 ) ) )
goto V_108;
if ( F_29 ( V_48 , V_25 , V_7 -> V_14 ) ||
F_29 ( V_48 , V_213 , V_1 -> V_214 ) ||
F_59 ( V_48 , V_12 ,
V_13 ( V_1 ) , V_215 ) ||
F_29 ( V_48 , V_106 ,
V_7 -> V_216 ^
( V_107 << 2 ) ) )
goto V_108;
if ( F_53 ( V_48 , V_217 ,
V_1 -> V_186 ,
V_215 ) ||
F_52 ( V_48 , V_218 ,
V_1 -> V_183 ) ||
F_52 ( V_48 , V_219 , V_1 -> V_179 ) )
goto V_108;
if ( F_33 ( V_48 , V_220 ,
V_1 -> V_221 ) ||
F_32 ( V_48 , V_222 , V_1 -> V_223 ) ||
F_32 ( V_48 , V_224 ,
V_1 -> V_225 ) ||
F_32 ( V_48 , V_226 , V_1 -> V_227 ) )
goto V_108;
if ( F_32 ( V_48 , V_228 , V_1 -> V_101 ) )
goto V_108;
if ( F_32 ( V_48 , V_229 , V_1 -> V_230 ) )
goto V_108;
#ifdef F_60
if ( F_55 ( V_48 , V_7 , V_1 ) < 0 )
goto V_108;
#endif
F_38 ( V_48 , V_104 ) ;
return 0 ;
V_108:
F_39 ( V_48 , V_104 ) ;
return - V_152 ;
}
static int
F_61 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
int V_231 = 0 ;
int V_232 = 0 ;
int V_233 = V_33 -> args [ 0 ] ;
int V_234 = V_33 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
F_14 () ;
F_6 (rdev, &cfg802154_rdev_list, list) {
if ( ! F_44 ( F_7 ( & V_7 -> V_17 ) , F_16 ( V_31 -> V_43 ) ) )
continue;
if ( V_231 < V_233 ) {
V_231 ++ ;
continue;
}
V_232 = 0 ;
F_6 (wpan_dev, &rdev->wpan_dev_list, list) {
if ( V_232 < V_234 ) {
V_232 ++ ;
continue;
}
if ( F_58 ( V_31 , F_45 ( V_33 -> V_31 ) . V_44 ,
V_33 -> V_35 -> V_163 , V_164 ,
V_7 , V_1 ) < 0 ) {
goto V_235;
}
V_232 ++ ;
}
V_231 ++ ;
}
V_235:
F_20 () ;
V_33 -> args [ 0 ] = V_231 ;
V_33 -> args [ 1 ] = V_232 ;
return V_31 -> V_165 ;
}
static int F_62 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_30 * V_48 ;
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_1 * V_236 = V_29 -> V_167 [ 1 ] ;
V_48 = F_48 ( V_168 , V_160 ) ;
if ( ! V_48 )
return - V_161 ;
if ( F_58 ( V_48 , V_29 -> V_169 , V_29 -> V_170 , 0 ,
V_7 , V_236 ) < 0 ) {
F_49 ( V_48 ) ;
return - V_53 ;
}
return F_50 ( V_48 , V_29 ) ;
}
static int F_63 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
enum V_237 type = V_238 ;
T_5 V_186 = F_64 ( 0x0000000000000000ULL ) ;
if ( ! V_29 -> V_5 [ V_211 ] )
return - V_16 ;
if ( V_29 -> V_5 [ V_213 ] ) {
type = F_4 ( V_29 -> V_5 [ V_213 ] ) ;
if ( type > V_239 ||
! ( V_7 -> V_17 . V_59 . V_99 & F_65 ( type ) ) )
return - V_16 ;
}
if ( V_29 -> V_5 [ V_217 ] )
V_186 = F_66 ( V_29 -> V_5 [ V_217 ] ) ;
if ( ! V_7 -> V_240 -> V_126 )
return - V_241 ;
return F_67 ( V_7 ,
F_68 ( V_29 -> V_5 [ V_211 ] ) ,
V_242 , type , V_186 ) ;
}
static int F_69 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_1 * V_1 = V_29 -> V_167 [ 1 ] ;
if ( ! V_7 -> V_240 -> V_128 )
return - V_241 ;
if ( ! V_1 -> V_18 )
V_29 -> V_167 [ 1 ] = NULL ;
return F_70 ( V_7 , V_1 ) ;
}
static int F_71 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
T_2 V_243 , V_55 ;
if ( ! V_29 -> V_5 [ V_111 ] ||
! V_29 -> V_5 [ V_113 ] )
return - V_16 ;
V_55 = F_72 ( V_29 -> V_5 [ V_111 ] ) ;
V_243 = F_72 ( V_29 -> V_5 [ V_113 ] ) ;
if ( V_55 > V_57 || V_243 > V_244 ||
! ( V_7 -> V_17 . V_59 . V_60 [ V_55 ] & F_65 ( V_243 ) ) )
return - V_16 ;
return F_73 ( V_7 , V_55 , V_243 ) ;
}
static int F_74 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_245 V_116 ;
if ( ! ( V_7 -> V_17 . V_46 & V_77 ) )
return - V_241 ;
if ( ! V_29 -> V_5 [ V_115 ] )
return - V_16 ;
V_116 . V_117 = F_4 ( V_29 -> V_5 [ V_115 ] ) ;
if ( V_116 . V_117 < V_246 ||
V_116 . V_117 > V_247 ||
! ( V_7 -> V_17 . V_59 . V_79 & F_65 ( V_116 . V_117 ) ) )
return - V_16 ;
if ( V_116 . V_117 == V_118 ) {
if ( ! V_29 -> V_5 [ V_119 ] )
return - V_16 ;
V_116 . V_120 = F_4 ( V_29 -> V_5 [ V_119 ] ) ;
if ( V_116 . V_120 > V_248 ||
! ( V_7 -> V_17 . V_59 . V_81 & F_65 ( V_116 . V_120 ) ) )
return - V_16 ;
}
return F_75 ( V_7 , & V_116 ) ;
}
static int F_76 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
T_6 V_249 ;
int V_52 ;
if ( ! ( V_7 -> V_17 . V_46 & V_67 ) )
return - V_241 ;
if ( ! V_29 -> V_5 [ V_123 ] )
return - V_16 ;
V_249 = F_77 ( V_29 -> V_5 [ V_123 ] ) ;
for ( V_52 = 0 ; V_52 < V_7 -> V_17 . V_59 . V_70 ; V_52 ++ ) {
if ( V_249 == V_7 -> V_17 . V_59 . V_71 [ V_52 ] )
return F_78 ( V_7 , V_249 ) ;
}
return - V_16 ;
}
static int F_79 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
T_6 V_250 ;
int V_52 ;
if ( ! ( V_7 -> V_17 . V_46 & V_72 ) )
return - V_241 ;
if ( ! V_29 -> V_5 [ V_121 ] )
return - V_16 ;
V_250 = F_77 ( V_29 -> V_5 [ V_121 ] ) ;
for ( V_52 = 0 ; V_52 < V_7 -> V_17 . V_59 . V_75 ; V_52 ++ ) {
if ( V_250 == V_7 -> V_17 . V_59 . V_76 [ V_52 ] )
return F_80 ( V_7 , V_250 ) ;
}
return - V_16 ;
}
static int F_81 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
T_7 V_179 ;
if ( F_82 ( V_209 ) )
return - V_251 ;
if ( V_1 -> V_252 ) {
if ( F_82 ( V_1 -> V_252 ) )
return - V_251 ;
}
if ( V_1 -> V_214 == V_253 ||
! V_29 -> V_5 [ V_219 ] )
return - V_16 ;
V_179 = F_83 ( V_29 -> V_5 [ V_219 ] ) ;
if ( V_179 == F_84 ( V_254 ) )
return - V_16 ;
return F_85 ( V_7 , V_1 , V_179 ) ;
}
static int F_86 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
T_7 V_183 ;
if ( F_82 ( V_209 ) )
return - V_251 ;
if ( V_1 -> V_252 ) {
if ( F_82 ( V_1 -> V_252 ) )
return - V_251 ;
}
if ( V_1 -> V_214 == V_253 ||
! V_29 -> V_5 [ V_218 ] )
return - V_16 ;
V_183 = F_83 ( V_29 -> V_5 [ V_218 ] ) ;
if ( V_183 == F_84 ( V_255 ) ||
V_183 == F_84 ( V_256 ) )
return - V_16 ;
return F_87 ( V_7 , V_1 , V_183 ) ;
}
static int
F_88 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
T_2 V_227 , V_223 ;
if ( F_82 ( V_209 ) )
return - V_251 ;
if ( ! V_29 -> V_5 [ V_226 ] ||
! V_29 -> V_5 [ V_222 ] )
return - V_16 ;
V_227 = F_72 ( V_29 -> V_5 [ V_226 ] ) ;
V_223 = F_72 ( V_29 -> V_5 [ V_222 ] ) ;
if ( V_227 < V_7 -> V_17 . V_59 . V_83 ||
V_227 > V_7 -> V_17 . V_59 . V_85 ||
V_223 < V_7 -> V_17 . V_59 . V_87 ||
V_223 > V_7 -> V_17 . V_59 . V_89 ||
V_227 > V_223 )
return - V_16 ;
return F_89 ( V_7 , V_1 , V_227 , V_223 ) ;
}
static int
F_90 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
T_2 V_93 ;
if ( F_82 ( V_209 ) )
return - V_251 ;
if ( ! V_29 -> V_5 [ V_224 ] )
return - V_16 ;
V_93 = F_72 (
V_29 -> V_5 [ V_224 ] ) ;
if ( V_93 < V_7 -> V_17 . V_59 . V_91 ||
V_93 > V_7 -> V_17 . V_59 . V_93 )
return - V_16 ;
return F_91 ( V_7 , V_1 , V_93 ) ;
}
static int
F_92 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
T_8 V_97 ;
if ( F_82 ( V_209 ) )
return - V_251 ;
if ( ! V_29 -> V_5 [ V_220 ] )
return - V_16 ;
V_97 = F_93 (
V_29 -> V_5 [ V_220 ] ) ;
if ( V_97 < V_7 -> V_17 . V_59 . V_95 ||
V_97 > V_7 -> V_17 . V_59 . V_97 )
return - V_16 ;
return F_94 ( V_7 , V_1 , V_97 ) ;
}
static int F_95 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
int V_117 ;
if ( F_82 ( V_209 ) )
return - V_251 ;
if ( ! V_29 -> V_5 [ V_228 ] )
return - V_16 ;
V_117 = F_72 ( V_29 -> V_5 [ V_228 ] ) ;
if ( V_117 != 0 && V_117 != 1 )
return - V_16 ;
if ( ! F_96 ( V_117 , V_7 -> V_17 . V_59 . V_101 ) )
return - V_16 ;
return F_97 ( V_7 , V_1 , V_117 ) ;
}
static int
F_98 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
int V_230 ;
if ( F_82 ( V_209 ) )
return - V_251 ;
if ( ! V_29 -> V_5 [ V_229 ] )
return - V_16 ;
V_230 = F_72 ( V_29 -> V_5 [ V_229 ] ) ;
if ( V_230 != 0 && V_230 != 1 )
return - V_16 ;
return F_99 ( V_7 , V_1 , V_230 ) ;
}
static int F_100 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_2 * V_2 ;
int V_34 ;
if ( V_29 -> V_5 [ V_257 ] ) {
V_21 V_258 = F_4 ( V_29 -> V_5 [ V_257 ] ) ;
V_2 = F_101 ( V_258 ) ;
} else if ( V_29 -> V_5 [ V_259 ] ) {
V_21 V_260 = F_4 ( V_29 -> V_5 [ V_259 ] ) ;
V_2 = F_102 ( V_260 ) ;
} else {
return - V_16 ;
}
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
V_34 = 0 ;
if ( ! F_44 ( F_7 ( & V_7 -> V_17 ) , V_2 ) )
V_34 = F_103 ( V_7 , V_2 ) ;
F_104 ( V_2 ) ;
return V_34 ;
}
static int
F_105 ( struct V_4 * V_261 ,
struct V_262 * V_263 )
{
struct V_4 * V_5 [ V_264 + 1 ] ;
if ( ! V_261 || F_106 ( V_5 , V_264 , V_261 ,
V_265 ) )
return - V_16 ;
if ( ! V_5 [ V_177 ] ||
! V_5 [ V_180 ] ||
! ( V_5 [ V_182 ] ||
V_5 [ V_185 ] ) )
return - V_16 ;
V_263 -> V_179 = F_83 ( V_5 [ V_177 ] ) ;
V_263 -> V_117 = F_4 ( V_5 [ V_180 ] ) ;
switch ( V_263 -> V_117 ) {
case V_181 :
V_263 -> V_183 = F_83 ( V_5 [ V_182 ] ) ;
break;
case V_184 :
V_263 -> V_186 = F_66 ( V_5 [ V_185 ] ) ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int
F_107 ( struct V_4 * V_261 ,
struct V_171 * V_172 )
{
struct V_4 * V_5 [ V_266 + 1 ] ;
if ( ! V_261 || F_106 ( V_5 , V_266 , V_261 ,
V_267 ) )
return - V_16 ;
if ( ! V_5 [ V_174 ] )
return - V_16 ;
V_172 -> V_117 = F_4 ( V_5 [ V_174 ] ) ;
switch ( V_172 -> V_117 ) {
case V_175 :
if ( ! V_5 [ V_176 ] )
return - V_16 ;
if ( F_105 ( V_5 [ V_176 ] ,
& V_172 -> V_178 ) < 0 )
return - V_16 ;
break;
case V_188 :
break;
case V_189 :
if ( ! V_5 [ V_190 ] )
return - V_16 ;
V_172 -> V_191 = F_108 ( V_5 [ V_190 ] ) ;
break;
case V_192 :
if ( ! V_5 [ V_193 ] )
return - V_16 ;
V_172 -> V_194 = F_66 ( V_5 [ V_193 ] ) ;
break;
default:
return - V_16 ;
}
if ( V_172 -> V_117 != V_175 ) {
if ( ! V_5 [ V_196 ] )
return - V_16 ;
V_172 -> V_197 = F_72 ( V_5 [ V_196 ] ) ;
}
return 0 ;
}
static int F_109 ( struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
struct V_199 V_200 ;
V_21 V_268 = 0 ;
int V_156 ;
if ( V_29 -> V_5 [ V_201 ] ) {
T_2 V_202 ;
V_202 = F_72 ( V_29 -> V_5 [ V_201 ] ) ;
if ( V_202 != 0 && V_202 != 1 )
return - V_16 ;
V_200 . V_202 = F_72 ( V_29 -> V_5 [ V_201 ] ) ;
V_268 |= V_269 ;
}
if ( V_29 -> V_5 [ V_207 ] ) {
V_156 = F_107 ( V_29 -> V_5 [ V_207 ] ,
& V_200 . V_208 ) ;
if ( V_156 < 0 )
return V_156 ;
V_268 |= V_270 ;
}
if ( V_29 -> V_5 [ V_203 ] ) {
V_200 . V_204 = F_4 ( V_29 -> V_5 [ V_203 ] ) ;
if ( V_200 . V_204 > V_271 )
return - V_16 ;
V_268 |= V_272 ;
}
if ( V_29 -> V_5 [ V_205 ] ) {
V_200 . V_206 = F_110 ( V_29 -> V_5 [ V_205 ] ) ;
V_268 |= V_273 ;
}
return F_111 ( V_7 , V_1 , & V_200 , V_268 ) ;
}
static int F_112 ( struct V_30 * V_48 , V_21 V_47 , V_21 V_44 ,
V_21 V_45 , int V_46 ,
struct V_6 * V_7 ,
struct V_24 * V_209 ,
const struct V_274 * V_275 )
{
void * V_104 ;
V_21 V_276 [ V_277 / 32 ] ;
struct V_4 * V_278 , * V_198 ;
V_104 = F_22 ( V_48 , V_44 , V_45 , V_46 , V_47 ) ;
if ( ! V_104 )
return - 1 ;
if ( F_29 ( V_48 , V_10 , V_209 -> V_19 ) )
goto V_108;
V_278 = F_25 ( V_48 , V_279 ) ;
if ( ! V_278 )
goto V_108;
V_198 = F_25 ( V_48 , V_280 ) ;
if ( ! V_198 )
goto V_108;
if ( F_51 ( V_48 , & V_275 -> V_197 ) < 0 )
goto V_108;
F_27 ( V_48 , V_198 ) ;
if ( F_32 ( V_48 , V_281 ,
V_275 -> V_275 -> V_282 ) )
goto V_108;
if ( V_275 -> V_275 -> V_282 & F_65 ( V_283 ) ) {
memset ( V_276 , 0 , sizeof( V_276 ) ) ;
V_276 [ 7 ] = V_275 -> V_275 -> V_284 ;
if ( F_113 ( V_48 , V_285 ,
sizeof( V_276 ) , V_276 ) )
goto V_108;
}
if ( F_113 ( V_48 , V_286 , V_287 ,
V_275 -> V_275 -> V_275 ) )
goto V_108;
F_27 ( V_48 , V_278 ) ;
F_38 ( V_48 , V_104 ) ;
return 0 ;
V_108:
F_39 ( V_48 , V_104 ) ;
return - V_152 ;
}
static int
F_114 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_6 * V_7 = NULL ;
struct V_274 * V_275 ;
struct V_288 * V_289 ;
struct V_1 * V_1 ;
int V_34 ;
V_34 = F_13 ( V_31 , V_33 , & V_7 , & V_1 ) ;
if ( V_34 )
return V_34 ;
if ( ! V_1 -> V_18 ) {
V_34 = - V_16 ;
goto V_290;
}
F_115 ( V_7 , V_1 ) ;
F_116 ( V_7 , V_1 , & V_289 ) ;
if ( V_33 -> args [ 2 ] )
goto V_235;
F_6 (key, &table->keys, list) {
if ( F_112 ( V_31 , V_291 ,
F_45 ( V_33 -> V_31 ) . V_44 ,
V_33 -> V_35 -> V_163 , V_164 ,
V_7 , V_1 -> V_18 , V_275 ) < 0 ) {
V_34 = - V_292 ;
F_117 ( V_7 , V_1 ) ;
goto V_290;
}
}
V_33 -> args [ 2 ] = 1 ;
V_235:
F_117 ( V_7 , V_1 ) ;
V_34 = V_31 -> V_165 ;
V_290:
F_21 ( V_7 ) ;
return V_34 ;
}
static int F_118 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
struct V_4 * V_5 [ V_293 + 1 ] ;
struct V_294 V_275 = { } ;
struct V_171 V_197 = { } ;
V_21 V_276 [ V_277 / 32 ] = { } ;
if ( F_106 ( V_5 , V_293 ,
V_29 -> V_5 [ V_279 ] ,
V_295 ) )
return - V_16 ;
if ( ! V_5 [ V_281 ] ||
! V_5 [ V_286 ] )
return - V_16 ;
if ( F_107 ( V_5 [ V_280 ] , & V_197 ) < 0 )
return - V_53 ;
V_275 . V_282 = F_72 ( V_5 [ V_281 ] ) ;
if ( V_275 . V_282 > F_65 ( V_296 ) ||
( ( V_275 . V_282 & F_65 ( V_283 ) ) &&
! V_5 [ V_285 ] ) )
return - V_16 ;
if ( V_5 [ V_285 ] ) {
F_119 ( V_276 , V_5 [ V_285 ] ,
V_277 / 8 ) ;
if ( V_276 [ 0 ] || V_276 [ 1 ] || V_276 [ 2 ] || V_276 [ 3 ] ||
V_276 [ 4 ] || V_276 [ 5 ] || V_276 [ 6 ] ||
V_276 [ 7 ] > F_65 ( V_297 ) )
return - V_16 ;
V_275 . V_284 = V_276 [ 7 ] ;
} else {
V_275 . V_284 = 0 ;
}
F_119 ( V_275 . V_275 , V_5 [ V_286 ] , V_287 ) ;
if ( F_107 ( V_5 [ V_280 ] , & V_197 ) < 0 )
return - V_53 ;
return F_120 ( V_7 , V_1 , & V_197 , & V_275 ) ;
}
static int F_121 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
struct V_4 * V_5 [ V_293 + 1 ] ;
struct V_171 V_197 ;
if ( F_106 ( V_5 , V_293 ,
V_29 -> V_5 [ V_279 ] ,
V_295 ) )
return - V_16 ;
if ( F_107 ( V_5 [ V_280 ] , & V_197 ) < 0 )
return - V_53 ;
return F_122 ( V_7 , V_1 , & V_197 ) ;
}
static int F_123 ( struct V_30 * V_48 , V_21 V_47 , V_21 V_44 ,
V_21 V_45 , int V_46 ,
struct V_6 * V_7 ,
struct V_24 * V_209 ,
const struct V_298 * V_299 )
{
void * V_104 ;
struct V_4 * V_300 ;
V_104 = F_22 ( V_48 , V_44 , V_45 , V_46 , V_47 ) ;
if ( ! V_104 )
return - 1 ;
if ( F_29 ( V_48 , V_10 , V_209 -> V_19 ) )
goto V_108;
V_300 = F_25 ( V_48 , V_301 ) ;
if ( ! V_300 )
goto V_108;
if ( F_29 ( V_48 , V_302 ,
V_299 -> V_206 ) ||
F_52 ( V_48 , V_303 , V_299 -> V_179 ) ||
F_52 ( V_48 , V_304 ,
V_299 -> V_183 ) ||
F_53 ( V_48 , V_305 ,
V_299 -> V_306 , V_307 ) ||
F_32 ( V_48 , V_308 ,
V_299 -> V_309 ) ||
F_29 ( V_48 , V_310 , V_299 -> V_311 ) )
goto V_108;
F_27 ( V_48 , V_300 ) ;
F_38 ( V_48 , V_104 ) ;
return 0 ;
V_108:
F_39 ( V_48 , V_104 ) ;
return - V_152 ;
}
static int
F_124 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_6 * V_7 = NULL ;
struct V_298 * V_209 ;
struct V_288 * V_289 ;
struct V_1 * V_1 ;
int V_34 ;
V_34 = F_13 ( V_31 , V_33 , & V_7 , & V_1 ) ;
if ( V_34 )
return V_34 ;
if ( ! V_1 -> V_18 ) {
V_34 = - V_16 ;
goto V_290;
}
F_115 ( V_7 , V_1 ) ;
F_116 ( V_7 , V_1 , & V_289 ) ;
if ( V_33 -> args [ 2 ] )
goto V_235;
F_6 (dev, &table->devices, list) {
if ( F_123 ( V_31 , V_312 ,
F_45 ( V_33 -> V_31 ) . V_44 ,
V_33 -> V_35 -> V_163 , V_164 ,
V_7 , V_1 -> V_18 , V_209 ) < 0 ) {
V_34 = - V_292 ;
F_117 ( V_7 , V_1 ) ;
goto V_290;
}
}
V_33 -> args [ 2 ] = 1 ;
V_235:
F_117 ( V_7 , V_1 ) ;
V_34 = V_31 -> V_165 ;
V_290:
F_21 ( V_7 ) ;
return V_34 ;
}
static int
F_125 ( struct V_4 * V_261 ,
struct V_298 * V_209 )
{
struct V_4 * V_5 [ V_313 + 1 ] ;
if ( ! V_261 || F_106 ( V_5 , V_313 , V_261 ,
V_314 ) )
return - V_16 ;
memset ( V_209 , 0 , sizeof( * V_209 ) ) ;
if ( ! V_5 [ V_302 ] ||
! V_5 [ V_303 ] ||
! V_5 [ V_304 ] ||
! V_5 [ V_305 ] ||
! V_5 [ V_308 ] ||
! V_5 [ V_310 ] )
return - V_16 ;
V_209 -> V_206 = F_4 ( V_5 [ V_302 ] ) ;
V_209 -> V_179 = F_83 ( V_5 [ V_303 ] ) ;
V_209 -> V_183 = F_83 ( V_5 [ V_304 ] ) ;
V_209 -> V_306 = F_66 ( V_5 [ V_305 ] ) ;
V_209 -> V_309 = F_72 ( V_5 [ V_308 ] ) ;
V_209 -> V_311 = F_4 ( V_5 [ V_310 ] ) ;
if ( V_209 -> V_311 > V_315 ||
( V_209 -> V_309 != 0 && V_209 -> V_309 != 1 ) )
return - V_16 ;
return 0 ;
}
static int F_126 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
struct V_298 V_299 ;
if ( F_125 ( V_29 -> V_5 [ V_301 ] ,
& V_299 ) < 0 )
return - V_16 ;
return F_127 ( V_7 , V_1 , & V_299 ) ;
}
static int F_128 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
struct V_4 * V_5 [ V_313 + 1 ] ;
T_5 V_186 ;
if ( F_106 ( V_5 , V_313 ,
V_29 -> V_5 [ V_301 ] ,
V_314 ) )
return - V_16 ;
if ( ! V_5 [ V_305 ] )
return - V_16 ;
V_186 = F_66 ( V_5 [ V_305 ] ) ;
return F_129 ( V_7 , V_1 , V_186 ) ;
}
static int F_130 ( struct V_30 * V_48 , V_21 V_47 , V_21 V_44 ,
V_21 V_45 , int V_46 ,
struct V_6 * V_7 ,
struct V_24 * V_209 , T_5 V_186 ,
const struct V_316 * V_317 )
{
void * V_104 ;
struct V_4 * V_318 , * V_198 ;
V_104 = F_22 ( V_48 , V_44 , V_45 , V_46 , V_47 ) ;
if ( ! V_104 )
return - 1 ;
if ( F_29 ( V_48 , V_10 , V_209 -> V_19 ) )
goto V_108;
V_318 = F_25 ( V_48 , V_319 ) ;
if ( ! V_318 )
goto V_108;
if ( F_53 ( V_48 , V_320 ,
V_186 , V_321 ) ||
F_29 ( V_48 , V_322 ,
V_317 -> V_206 ) )
goto V_108;
V_198 = F_25 ( V_48 , V_323 ) ;
if ( ! V_198 )
goto V_108;
if ( F_51 ( V_48 , & V_317 -> V_324 ) < 0 )
goto V_108;
F_27 ( V_48 , V_198 ) ;
F_27 ( V_48 , V_318 ) ;
F_38 ( V_48 , V_104 ) ;
return 0 ;
V_108:
F_39 ( V_48 , V_104 ) ;
return - V_152 ;
}
static int
F_131 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_6 * V_7 = NULL ;
struct V_316 * V_325 ;
struct V_298 * V_326 ;
struct V_288 * V_289 ;
struct V_1 * V_1 ;
int V_34 ;
V_34 = F_13 ( V_31 , V_33 , & V_7 , & V_1 ) ;
if ( V_34 )
return V_34 ;
if ( ! V_1 -> V_18 ) {
V_34 = - V_16 ;
goto V_290;
}
F_115 ( V_7 , V_1 ) ;
F_116 ( V_7 , V_1 , & V_289 ) ;
if ( V_33 -> args [ 2 ] )
goto V_235;
F_6 (dpos, &table->devices, list) {
F_6 (kpos, &dpos->keys, list) {
if ( F_130 ( V_31 ,
V_312 ,
F_45 ( V_33 -> V_31 ) . V_44 ,
V_33 -> V_35 -> V_163 ,
V_164 , V_7 ,
V_1 -> V_18 ,
V_326 -> V_306 ,
V_325 ) < 0 ) {
V_34 = - V_292 ;
F_117 ( V_7 , V_1 ) ;
goto V_290;
}
}
}
V_33 -> args [ 2 ] = 1 ;
V_235:
F_117 ( V_7 , V_1 ) ;
V_34 = V_31 -> V_165 ;
V_290:
F_21 ( V_7 ) ;
return V_34 ;
}
static int F_132 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
struct V_4 * V_5 [ V_327 + 1 ] ;
struct V_316 V_275 ;
T_5 V_186 ;
if ( ! V_29 -> V_5 [ V_319 ] ||
F_106 ( V_5 , V_327 ,
V_29 -> V_5 [ V_319 ] ,
V_328 ) < 0 )
return - V_16 ;
if ( ! V_5 [ V_322 ] ||
! V_5 [ V_320 ] )
return - V_16 ;
if ( F_107 ( V_5 [ V_323 ] ,
& V_275 . V_324 ) < 0 )
return - V_53 ;
V_275 . V_206 = F_4 ( V_5 [ V_322 ] ) ;
V_186 = F_66 ( V_5 [ V_320 ] ) ;
return F_133 ( V_7 , V_1 , V_186 , & V_275 ) ;
}
static int F_134 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
struct V_4 * V_5 [ V_327 + 1 ] ;
struct V_316 V_275 ;
T_5 V_186 ;
if ( F_106 ( V_5 , V_327 ,
V_29 -> V_5 [ V_319 ] ,
V_328 ) )
return - V_16 ;
if ( ! V_5 [ V_320 ] )
return - V_16 ;
if ( F_107 ( V_5 [ V_323 ] ,
& V_275 . V_324 ) < 0 )
return - V_53 ;
V_186 = F_66 ( V_5 [ V_320 ] ) ;
return F_135 ( V_7 , V_1 , V_186 , & V_275 ) ;
}
static int F_136 ( struct V_30 * V_48 , V_21 V_47 , V_21 V_44 ,
V_21 V_45 , int V_46 ,
struct V_6 * V_7 ,
struct V_24 * V_209 ,
const struct V_329 * V_330 )
{
void * V_104 ;
struct V_4 * V_331 ;
V_104 = F_22 ( V_48 , V_44 , V_45 , V_46 , V_47 ) ;
if ( ! V_104 )
return - 1 ;
if ( F_29 ( V_48 , V_10 , V_209 -> V_19 ) )
goto V_108;
V_331 = F_25 ( V_48 , V_332 ) ;
if ( ! V_331 )
goto V_108;
if ( F_29 ( V_48 , V_333 , V_330 -> V_334 ) ||
F_29 ( V_48 , V_335 , V_330 -> V_336 ) ||
F_32 ( V_48 , V_337 ,
V_330 -> V_338 ) )
goto V_108;
if ( V_330 -> V_334 == V_283 ) {
if ( F_29 ( V_48 , V_339 ,
V_330 -> V_340 ) )
goto V_108;
}
F_27 ( V_48 , V_331 ) ;
F_38 ( V_48 , V_104 ) ;
return 0 ;
V_108:
F_39 ( V_48 , V_104 ) ;
return - V_152 ;
}
static int
F_137 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_6 * V_7 = NULL ;
struct V_329 * V_330 ;
struct V_288 * V_289 ;
struct V_1 * V_1 ;
int V_34 ;
V_34 = F_13 ( V_31 , V_33 , & V_7 , & V_1 ) ;
if ( V_34 )
return V_34 ;
if ( ! V_1 -> V_18 ) {
V_34 = - V_16 ;
goto V_290;
}
F_115 ( V_7 , V_1 ) ;
F_116 ( V_7 , V_1 , & V_289 ) ;
if ( V_33 -> args [ 2 ] )
goto V_235;
F_6 (sl, &table->security_levels, list) {
if ( F_136 ( V_31 , V_312 ,
F_45 ( V_33 -> V_31 ) . V_44 ,
V_33 -> V_35 -> V_163 , V_164 ,
V_7 , V_1 -> V_18 , V_330 ) < 0 ) {
V_34 = - V_292 ;
F_117 ( V_7 , V_1 ) ;
goto V_290;
}
}
V_33 -> args [ 2 ] = 1 ;
V_235:
F_117 ( V_7 , V_1 ) ;
V_34 = V_31 -> V_165 ;
V_290:
F_21 ( V_7 ) ;
return V_34 ;
}
static int
F_138 ( struct V_4 * V_261 , struct V_329 * V_330 )
{
struct V_4 * V_5 [ V_341 + 1 ] ;
if ( ! V_261 || F_106 ( V_5 , V_341 , V_261 ,
V_342 ) )
return - V_16 ;
memset ( V_330 , 0 , sizeof( * V_330 ) ) ;
if ( ! V_5 [ V_335 ] ||
! V_5 [ V_333 ] ||
! V_5 [ V_337 ] )
return - V_16 ;
V_330 -> V_336 = F_72 ( V_5 [ V_335 ] ) ;
V_330 -> V_334 = F_4 ( V_5 [ V_333 ] ) ;
V_330 -> V_338 = F_72 ( V_5 [ V_337 ] ) ;
if ( V_330 -> V_334 > V_296 ||
( V_330 -> V_338 != 0 && V_330 -> V_338 != 1 ) )
return - V_16 ;
if ( V_330 -> V_334 == V_283 ) {
if ( ! V_5 [ V_339 ] )
return - V_16 ;
V_330 -> V_340 = F_4 ( V_5 [ V_339 ] ) ;
if ( V_330 -> V_340 > V_297 )
return - V_16 ;
}
return 0 ;
}
static int F_139 ( struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
struct V_329 V_330 ;
if ( F_138 ( V_29 -> V_5 [ V_332 ] ,
& V_330 ) < 0 )
return - V_16 ;
return F_140 ( V_7 , V_1 , & V_330 ) ;
}
static int F_141 ( struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_24 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_27 ;
struct V_329 V_330 ;
if ( ! V_29 -> V_5 [ V_332 ] ||
F_138 ( V_29 -> V_5 [ V_332 ] ,
& V_330 ) < 0 )
return - V_16 ;
return F_142 ( V_7 , V_1 , & V_330 ) ;
}
static int F_143 ( const struct V_343 * V_240 , struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 ;
struct V_1 * V_1 ;
struct V_24 * V_209 ;
bool V_344 = V_240 -> V_345 & V_346 ;
if ( V_344 )
F_14 () ;
if ( V_240 -> V_345 & V_347 ) {
V_7 = F_12 ( F_144 ( V_29 ) , V_29 ) ;
if ( F_17 ( V_7 ) ) {
if ( V_344 )
F_20 () ;
return F_18 ( V_7 ) ;
}
V_29 -> V_167 [ 0 ] = V_7 ;
} else if ( V_240 -> V_345 & V_348 ||
V_240 -> V_345 & V_349 ) {
F_2 () ;
V_1 = F_1 ( F_144 ( V_29 ) ,
V_29 -> V_5 ) ;
if ( F_17 ( V_1 ) ) {
if ( V_344 )
F_20 () ;
return F_18 ( V_1 ) ;
}
V_209 = V_1 -> V_18 ;
V_7 = F_11 ( V_1 -> V_17 ) ;
if ( V_240 -> V_345 & V_348 ) {
if ( ! V_209 ) {
if ( V_344 )
F_20 () ;
return - V_16 ;
}
V_29 -> V_167 [ 1 ] = V_209 ;
} else {
V_29 -> V_167 [ 1 ] = V_1 ;
}
if ( V_209 ) {
if ( V_240 -> V_345 & V_350 &&
! F_82 ( V_209 ) ) {
if ( V_344 )
F_20 () ;
return - V_351 ;
}
F_145 ( V_209 ) ;
}
V_29 -> V_167 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_146 ( const struct V_343 * V_240 , struct V_30 * V_31 ,
struct V_28 * V_29 )
{
if ( V_29 -> V_167 [ 1 ] ) {
if ( V_240 -> V_345 & V_349 ) {
struct V_1 * V_1 = V_29 -> V_167 [ 1 ] ;
if ( V_1 -> V_18 )
F_147 ( V_1 -> V_18 ) ;
} else {
F_147 ( V_29 -> V_167 [ 1 ] ) ;
}
}
if ( V_240 -> V_345 & V_346 )
F_20 () ;
}
int F_148 ( void )
{
return F_149 ( & V_37 , V_352 ,
V_353 ) ;
}
void F_150 ( void )
{
F_151 ( & V_37 ) ;
}
