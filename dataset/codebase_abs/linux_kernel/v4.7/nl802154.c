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
if ( V_11 && V_7 -> V_14 != V_14 )
continue;
F_6 (wpan_dev, &rdev->wpan_dev_list, list) {
if ( V_9 && V_1 -> V_17 &&
V_1 -> V_17 -> V_18 == V_15 ) {
V_8 = V_1 ;
break;
}
if ( V_11 &&
V_1 -> V_19 == ( V_20 ) V_13 ) {
V_8 = V_1 ;
break;
}
}
if ( V_8 )
break;
}
if ( V_8 )
return V_8 ;
return F_3 ( - V_21 ) ;
}
static struct V_6 *
F_7 ( struct V_2 * V_3 , struct V_4 * * V_5 )
{
struct V_6 * V_7 = NULL , * V_22 ;
struct V_23 * V_17 ;
F_2 () ;
if ( ! V_5 [ V_24 ] &&
! V_5 [ V_10 ] &&
! V_5 [ V_12 ] )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_24 ] )
V_7 = F_8 (
F_4 ( V_5 [ V_24 ] ) ) ;
if ( V_5 [ V_12 ] ) {
T_1 V_13 = F_5 ( V_5 [ V_12 ] ) ;
struct V_1 * V_1 ;
bool V_25 = false ;
V_22 = F_8 ( V_13 >> 32 ) ;
if ( V_22 ) {
F_6 (wpan_dev, &tmp->wpan_dev_list, list) {
if ( V_1 -> V_19 != ( V_20 ) V_13 )
continue;
V_25 = true ;
break;
}
if ( ! V_25 )
V_22 = NULL ;
if ( V_7 && V_22 != V_7 )
return F_3 ( - V_16 ) ;
V_7 = V_22 ;
}
}
if ( V_5 [ V_10 ] ) {
int V_18 = F_4 ( V_5 [ V_10 ] ) ;
V_17 = F_9 ( V_3 , V_18 ) ;
if ( V_17 ) {
if ( V_17 -> V_26 )
V_22 = F_10 (
V_17 -> V_26 -> V_27 ) ;
else
V_22 = NULL ;
if ( ! V_22 )
return F_3 ( - V_16 ) ;
if ( V_7 && V_22 != V_7 )
return F_3 ( - V_16 ) ;
V_7 = V_22 ;
}
}
if ( ! V_7 )
return F_3 ( - V_21 ) ;
return V_7 ;
}
static struct V_6 *
F_11 ( struct V_2 * V_3 , struct V_28 * V_29 )
{
return F_7 ( V_3 , V_29 -> V_5 ) ;
}
static int
F_12 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
struct V_6 * * V_7 ,
struct V_1 * * V_1 )
{
int V_34 ;
F_13 () ;
if ( ! V_33 -> args [ 0 ] ) {
V_34 = F_14 ( V_33 -> V_35 , V_36 + V_37 . V_38 ,
V_37 . V_39 , V_37 . V_40 ,
V_41 ) ;
if ( V_34 )
goto V_42;
* V_1 = F_1 ( F_15 ( V_31 -> V_43 ) ,
V_37 . V_39 ) ;
if ( F_16 ( * V_1 ) ) {
V_34 = F_17 ( * V_1 ) ;
goto V_42;
}
* V_7 = F_10 ( ( * V_1 ) -> V_27 ) ;
V_33 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_33 -> args [ 1 ] = ( * V_1 ) -> V_19 ;
} else {
struct V_27 * V_27 = F_18 ( V_33 -> args [ 0 ] - 1 ) ;
struct V_1 * V_22 ;
if ( ! V_27 ) {
V_34 = - V_21 ;
goto V_42;
}
* V_7 = F_10 ( V_27 ) ;
* V_1 = NULL ;
F_6 (tmp, &(*rdev)->wpan_dev_list, list) {
if ( V_22 -> V_19 == V_33 -> args [ 1 ] ) {
* V_1 = V_22 ;
break;
}
}
if ( ! * V_1 ) {
V_34 = - V_21 ;
goto V_42;
}
}
return 0 ;
V_42:
F_19 () ;
return V_34 ;
}
static void
F_20 ( struct V_6 * V_7 )
{
F_19 () ;
}
static inline void * F_21 ( struct V_30 * V_31 , V_20 V_44 , V_20 V_45 ,
int V_46 , T_2 V_47 )
{
return F_22 ( V_31 , V_44 , V_45 , & V_37 , V_46 , V_47 ) ;
}
static int
F_23 ( struct V_30 * V_48 , int V_49 , V_20 V_50 )
{
struct V_4 * V_51 = F_24 ( V_48 , V_49 ) ;
int V_52 ;
if ( ! V_51 )
return - V_53 ;
V_52 = 0 ;
while ( V_50 ) {
if ( ( V_50 & 1 ) && F_25 ( V_48 , V_52 ) )
return - V_53 ;
V_50 >>= 1 ;
V_52 ++ ;
}
F_26 ( V_48 , V_51 ) ;
return 0 ;
}
static int
F_27 ( struct V_6 * V_7 ,
struct V_30 * V_48 )
{
struct V_4 * V_54 ;
unsigned long V_55 ;
V_54 = F_24 ( V_48 , V_56 ) ;
if ( ! V_54 )
return - V_53 ;
for ( V_55 = 0 ; V_55 <= V_57 ; V_55 ++ ) {
if ( F_28 ( V_48 , V_58 ,
V_7 -> V_27 . V_59 . V_60 [ V_55 ] ) )
return - V_53 ;
}
F_26 ( V_48 , V_54 ) ;
return 0 ;
}
static int
F_29 ( struct V_30 * V_48 ,
struct V_6 * V_7 )
{
const struct V_61 * V_62 = & V_7 -> V_27 . V_59 ;
struct V_4 * V_63 , * V_64 ;
int V_52 ;
V_63 = F_24 ( V_48 , V_65 ) ;
if ( ! V_63 )
return - V_53 ;
V_64 = F_24 ( V_48 , V_66 ) ;
if ( ! V_64 )
return - V_53 ;
for ( V_52 = 0 ; V_52 <= V_57 ; V_52 ++ ) {
if ( V_62 -> V_60 [ V_52 ] ) {
if ( F_23 ( V_48 , V_52 , V_62 -> V_60 [ V_52 ] ) )
return - V_53 ;
}
}
F_26 ( V_48 , V_64 ) ;
if ( V_7 -> V_27 . V_46 & V_67 ) {
struct V_4 * V_68 ;
V_68 = F_24 ( V_48 ,
V_69 ) ;
if ( ! V_68 )
return - V_53 ;
for ( V_52 = 0 ; V_52 < V_62 -> V_70 ; V_52 ++ ) {
if ( F_30 ( V_48 , V_52 , V_62 -> V_71 [ V_52 ] ) )
return - V_53 ;
}
F_26 ( V_48 , V_68 ) ;
}
if ( V_7 -> V_27 . V_46 & V_72 ) {
struct V_4 * V_73 ;
V_73 = F_24 ( V_48 , V_74 ) ;
if ( ! V_73 )
return - V_53 ;
for ( V_52 = 0 ; V_52 < V_62 -> V_75 ; V_52 ++ ) {
if ( F_30 ( V_48 , V_52 , V_62 -> V_76 [ V_52 ] ) )
return - V_53 ;
}
F_26 ( V_48 , V_73 ) ;
}
if ( V_7 -> V_27 . V_46 & V_77 ) {
if ( F_23 ( V_48 , V_78 ,
V_62 -> V_79 ) ||
F_23 ( V_48 , V_80 ,
V_62 -> V_81 ) )
return - V_53 ;
}
if ( F_31 ( V_48 , V_82 , V_62 -> V_83 ) ||
F_31 ( V_48 , V_84 , V_62 -> V_85 ) ||
F_31 ( V_48 , V_86 , V_62 -> V_87 ) ||
F_31 ( V_48 , V_88 , V_62 -> V_89 ) ||
F_31 ( V_48 , V_90 ,
V_62 -> V_91 ) ||
F_31 ( V_48 , V_92 ,
V_62 -> V_93 ) ||
F_32 ( V_48 , V_94 ,
V_62 -> V_95 ) ||
F_32 ( V_48 , V_96 ,
V_62 -> V_97 ) ||
F_23 ( V_48 , V_98 ,
V_62 -> V_99 ) ||
F_28 ( V_48 , V_100 , V_62 -> V_101 ) )
return - V_53 ;
F_26 ( V_48 , V_63 ) ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 ,
enum V_102 V_47 ,
struct V_30 * V_48 , V_20 V_44 , V_20 V_45 ,
int V_46 )
{
struct V_4 * V_103 ;
void * V_104 ;
int V_52 ;
V_104 = F_21 ( V_48 , V_44 , V_45 , V_46 , V_47 ) ;
if ( ! V_104 )
return - V_53 ;
if ( F_28 ( V_48 , V_24 , V_7 -> V_14 ) ||
F_34 ( V_48 , V_105 ,
F_35 ( & V_7 -> V_27 ) ) ||
F_28 ( V_48 , V_106 ,
V_107 ) )
goto V_108;
if ( V_47 != V_109 )
goto V_110;
if ( F_31 ( V_48 , V_111 ,
V_7 -> V_27 . V_112 ) ||
F_31 ( V_48 , V_113 ,
V_7 -> V_27 . V_114 ) )
goto V_108;
if ( F_27 ( V_7 , V_48 ) )
goto V_108;
if ( V_7 -> V_27 . V_46 & V_77 ) {
if ( F_28 ( V_48 , V_115 ,
V_7 -> V_27 . V_116 . V_117 ) )
goto V_108;
if ( V_7 -> V_27 . V_116 . V_117 == V_118 ) {
if ( F_28 ( V_48 , V_119 ,
V_7 -> V_27 . V_116 . V_120 ) )
goto V_108;
}
}
if ( V_7 -> V_27 . V_46 & V_72 ) {
if ( F_30 ( V_48 , V_121 ,
V_7 -> V_27 . V_122 ) )
goto V_108;
}
if ( V_7 -> V_27 . V_46 & V_67 ) {
if ( F_30 ( V_48 , V_123 ,
V_7 -> V_27 . V_124 ) )
goto V_108;
}
if ( F_29 ( V_48 , V_7 ) )
goto V_108;
V_103 = F_24 ( V_48 , V_125 ) ;
if ( ! V_103 )
goto V_108;
V_52 = 0 ;
#define F_36 ( T_3 , T_4 ) \
do { \
if (rdev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL802154_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_36 ( V_126 , V_127 ) ;
F_36 ( V_128 , V_129 ) ;
F_36 ( V_130 , V_131 ) ;
F_36 ( V_132 , V_133 ) ;
F_36 ( V_134 , V_135 ) ;
F_36 ( V_136 , V_137 ) ;
F_36 ( V_138 , V_139 ) ;
F_36 ( V_140 , V_141 ) ;
F_36 ( V_142 , V_143 ) ;
F_36 ( V_144 , V_145 ) ;
if ( V_7 -> V_27 . V_46 & V_72 )
F_36 ( V_146 , V_147 ) ;
if ( V_7 -> V_27 . V_46 & V_67 )
F_36 ( V_148 , V_149 ) ;
if ( V_7 -> V_27 . V_46 & V_77 )
F_36 ( V_150 , V_151 ) ;
#undef F_36
F_26 ( V_48 , V_103 ) ;
V_110:
F_37 ( V_48 , V_104 ) ;
return 0 ;
V_108:
F_38 ( V_48 , V_104 ) ;
return - V_152 ;
}
static int F_39 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
struct V_153 * V_154 )
{
struct V_4 * * V_155 = V_37 . V_39 ;
int V_156 = F_14 ( V_33 -> V_35 , V_36 + V_37 . V_38 ,
V_155 , V_37 . V_40 , V_41 ) ;
if ( V_156 )
return 0 ;
if ( V_155 [ V_24 ] )
V_154 -> V_157 = F_4 ( V_155 [ V_24 ] ) ;
if ( V_155 [ V_12 ] )
V_154 -> V_157 = F_5 ( V_155 [ V_12 ] ) >> 32 ;
if ( V_155 [ V_10 ] ) {
struct V_23 * V_17 ;
struct V_6 * V_7 ;
int V_15 = F_4 ( V_155 [ V_10 ] ) ;
V_17 = F_9 ( & V_158 , V_15 ) ;
if ( ! V_17 )
return - V_21 ;
if ( V_17 -> V_26 ) {
V_7 = F_10 (
V_17 -> V_26 -> V_27 ) ;
V_154 -> V_157 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int
F_40 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
int V_159 = 0 , V_156 ;
struct V_153 * V_154 = ( void * ) V_33 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_13 () ;
if ( ! V_154 ) {
V_154 = F_41 ( sizeof( * V_154 ) , V_160 ) ;
if ( ! V_154 ) {
F_19 () ;
return - V_161 ;
}
V_154 -> V_157 = - 1 ;
V_156 = F_39 ( V_31 , V_33 , V_154 ) ;
if ( V_156 ) {
F_42 ( V_154 ) ;
F_19 () ;
return V_156 ;
}
V_33 -> args [ 0 ] = ( long ) V_154 ;
}
F_6 (rdev, &cfg802154_rdev_list, list) {
if ( ++ V_159 <= V_154 -> V_162 )
continue;
if ( V_154 -> V_157 != - 1 &&
V_154 -> V_157 != V_7 -> V_14 )
continue;
V_156 = F_33 ( V_7 ,
V_109 ,
V_31 ,
F_43 ( V_33 -> V_31 ) . V_44 ,
V_33 -> V_35 -> V_163 , V_164 ) ;
if ( V_156 < 0 ) {
if ( ( V_156 == - V_53 || V_156 == - V_152 ) &&
! V_31 -> V_165 && V_33 -> V_166 < 4096 ) {
V_33 -> V_166 = 4096 ;
F_19 () ;
return 1 ;
}
V_159 -- ;
break;
}
break;
}
F_19 () ;
V_154 -> V_162 = V_159 ;
return V_31 -> V_165 ;
}
static int F_44 ( struct V_32 * V_33 )
{
F_42 ( ( void * ) V_33 -> args [ 0 ] ) ;
return 0 ;
}
static int F_45 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_30 * V_48 ;
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
V_48 = F_46 ( V_168 , V_160 ) ;
if ( ! V_48 )
return - V_161 ;
if ( F_33 ( V_7 , V_109 , V_48 ,
V_29 -> V_169 , V_29 -> V_170 , 0 ) < 0 ) {
F_47 ( V_48 ) ;
return - V_53 ;
}
return F_48 ( V_48 , V_29 ) ;
}
static inline T_1 V_13 ( struct V_1 * V_1 )
{
return ( T_1 ) V_1 -> V_19 |
( ( T_1 ) F_10 ( V_1 -> V_27 ) -> V_14 << 32 ) ;
}
static int
F_49 ( struct V_30 * V_48 ,
const struct V_171 * V_172 )
{
struct V_4 * V_173 ;
if ( F_28 ( V_48 , V_174 , V_172 -> V_117 ) )
return - V_53 ;
switch ( V_172 -> V_117 ) {
case V_175 :
V_173 = F_24 ( V_48 , V_176 ) ;
if ( ! V_173 )
return - V_53 ;
if ( F_50 ( V_48 , V_177 ,
V_172 -> V_178 . V_179 ) ||
F_28 ( V_48 , V_180 ,
V_172 -> V_178 . V_117 ) )
return - V_53 ;
switch ( V_172 -> V_178 . V_117 ) {
case V_181 :
if ( F_50 ( V_48 , V_182 ,
V_172 -> V_178 . V_183 ) )
return - V_53 ;
break;
case V_184 :
if ( F_51 ( V_48 , V_185 ,
V_172 -> V_178 . V_186 ,
V_187 ) )
return - V_53 ;
break;
default:
break;
}
F_26 ( V_48 , V_173 ) ;
break;
case V_188 :
break;
case V_189 :
if ( F_52 ( V_48 , V_190 ,
V_172 -> V_191 ) )
return - V_53 ;
break;
case V_192 :
if ( F_51 ( V_48 , V_193 ,
V_172 -> V_194 ,
V_195 ) )
return - V_53 ;
break;
default:
break;
}
if ( V_172 -> V_117 != V_175 ) {
if ( F_31 ( V_48 , V_196 , V_172 -> V_197 ) )
return - V_53 ;
}
return 0 ;
}
static int F_53 ( struct V_30 * V_48 ,
struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_4 * V_198 ;
struct V_199 V_200 ;
int V_156 ;
V_156 = F_54 ( V_7 , V_1 , & V_200 ) ;
if ( V_156 < 0 )
return V_156 ;
if ( F_31 ( V_48 , V_201 , V_200 . V_202 ) ||
F_28 ( V_48 , V_203 , V_200 . V_204 ) ||
F_55 ( V_48 , V_205 ,
V_200 . V_206 ) )
return - V_53 ;
V_198 = F_24 ( V_48 , V_207 ) ;
if ( ! V_198 )
return - V_53 ;
V_156 = F_49 ( V_48 , & V_200 . V_208 ) ;
if ( V_156 < 0 )
return V_156 ;
F_26 ( V_48 , V_198 ) ;
return 0 ;
}
static int
F_56 ( struct V_30 * V_48 , V_20 V_44 , V_20 V_45 , int V_46 ,
struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_23 * V_209 = V_1 -> V_17 ;
void * V_104 ;
V_104 = F_21 ( V_48 , V_44 , V_45 , V_46 ,
V_210 ) ;
if ( ! V_104 )
return - 1 ;
if ( V_209 &&
( F_28 ( V_48 , V_10 , V_209 -> V_18 ) ||
F_34 ( V_48 , V_211 , V_209 -> V_212 ) ) )
goto V_108;
if ( F_28 ( V_48 , V_24 , V_7 -> V_14 ) ||
F_28 ( V_48 , V_213 , V_1 -> V_214 ) ||
F_57 ( V_48 , V_12 ,
V_13 ( V_1 ) , V_215 ) ||
F_28 ( V_48 , V_106 ,
V_7 -> V_216 ^
( V_107 << 2 ) ) )
goto V_108;
if ( F_51 ( V_48 , V_217 ,
V_1 -> V_186 ,
V_215 ) ||
F_50 ( V_48 , V_218 ,
V_1 -> V_183 ) ||
F_50 ( V_48 , V_219 , V_1 -> V_179 ) )
goto V_108;
if ( F_32 ( V_48 , V_220 ,
V_1 -> V_221 ) ||
F_31 ( V_48 , V_222 , V_1 -> V_223 ) ||
F_31 ( V_48 , V_224 ,
V_1 -> V_225 ) ||
F_31 ( V_48 , V_226 , V_1 -> V_227 ) )
goto V_108;
if ( F_31 ( V_48 , V_228 , V_1 -> V_101 ) )
goto V_108;
if ( F_31 ( V_48 , V_229 , V_1 -> V_230 ) )
goto V_108;
#ifdef F_58
if ( F_53 ( V_48 , V_7 , V_1 ) < 0 )
goto V_108;
#endif
F_37 ( V_48 , V_104 ) ;
return 0 ;
V_108:
F_38 ( V_48 , V_104 ) ;
return - V_152 ;
}
static int
F_59 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
int V_231 = 0 ;
int V_232 = 0 ;
int V_233 = V_33 -> args [ 0 ] ;
int V_234 = V_33 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
F_13 () ;
F_6 (rdev, &cfg802154_rdev_list, list) {
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
if ( F_56 ( V_31 , F_43 ( V_33 -> V_31 ) . V_44 ,
V_33 -> V_35 -> V_163 , V_164 ,
V_7 , V_1 ) < 0 ) {
goto V_235;
}
V_232 ++ ;
}
V_231 ++ ;
}
V_235:
F_19 () ;
V_33 -> args [ 0 ] = V_231 ;
V_33 -> args [ 1 ] = V_232 ;
return V_31 -> V_165 ;
}
static int F_60 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_30 * V_48 ;
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_1 * V_236 = V_29 -> V_167 [ 1 ] ;
V_48 = F_46 ( V_168 , V_160 ) ;
if ( ! V_48 )
return - V_161 ;
if ( F_56 ( V_48 , V_29 -> V_169 , V_29 -> V_170 , 0 ,
V_7 , V_236 ) < 0 ) {
F_47 ( V_48 ) ;
return - V_53 ;
}
return F_48 ( V_48 , V_29 ) ;
}
static int F_61 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
enum V_237 type = V_238 ;
T_5 V_186 = F_62 ( 0x0000000000000000ULL ) ;
if ( ! V_29 -> V_5 [ V_211 ] )
return - V_16 ;
if ( V_29 -> V_5 [ V_213 ] ) {
type = F_4 ( V_29 -> V_5 [ V_213 ] ) ;
if ( type > V_239 ||
! ( V_7 -> V_27 . V_59 . V_99 & F_63 ( type ) ) )
return - V_16 ;
}
if ( V_29 -> V_5 [ V_217 ] )
V_186 = F_64 ( V_29 -> V_5 [ V_217 ] ) ;
if ( ! V_7 -> V_240 -> V_126 )
return - V_241 ;
return F_65 ( V_7 ,
F_66 ( V_29 -> V_5 [ V_211 ] ) ,
V_242 , type , V_186 ) ;
}
static int F_67 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_1 * V_1 = V_29 -> V_167 [ 1 ] ;
if ( ! V_7 -> V_240 -> V_128 )
return - V_241 ;
if ( ! V_1 -> V_17 )
V_29 -> V_167 [ 1 ] = NULL ;
return F_68 ( V_7 , V_1 ) ;
}
static int F_69 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
T_2 V_243 , V_55 ;
if ( ! V_29 -> V_5 [ V_111 ] ||
! V_29 -> V_5 [ V_113 ] )
return - V_16 ;
V_55 = F_70 ( V_29 -> V_5 [ V_111 ] ) ;
V_243 = F_70 ( V_29 -> V_5 [ V_113 ] ) ;
if ( V_55 > V_57 || V_243 > V_244 ||
! ( V_7 -> V_27 . V_59 . V_60 [ V_55 ] & F_63 ( V_243 ) ) )
return - V_16 ;
return F_71 ( V_7 , V_55 , V_243 ) ;
}
static int F_72 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_245 V_116 ;
if ( ! ( V_7 -> V_27 . V_46 & V_77 ) )
return - V_241 ;
if ( ! V_29 -> V_5 [ V_115 ] )
return - V_16 ;
V_116 . V_117 = F_4 ( V_29 -> V_5 [ V_115 ] ) ;
if ( V_116 . V_117 < V_246 ||
V_116 . V_117 > V_247 ||
! ( V_7 -> V_27 . V_59 . V_79 & F_63 ( V_116 . V_117 ) ) )
return - V_16 ;
if ( V_116 . V_117 == V_118 ) {
if ( ! V_29 -> V_5 [ V_119 ] )
return - V_16 ;
V_116 . V_120 = F_4 ( V_29 -> V_5 [ V_119 ] ) ;
if ( V_116 . V_120 > V_248 ||
! ( V_7 -> V_27 . V_59 . V_81 & F_63 ( V_116 . V_120 ) ) )
return - V_16 ;
}
return F_73 ( V_7 , & V_116 ) ;
}
static int F_74 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
T_6 V_249 ;
int V_52 ;
if ( ! ( V_7 -> V_27 . V_46 & V_67 ) )
return - V_241 ;
if ( ! V_29 -> V_5 [ V_123 ] )
return - V_16 ;
V_249 = F_75 ( V_29 -> V_5 [ V_123 ] ) ;
for ( V_52 = 0 ; V_52 < V_7 -> V_27 . V_59 . V_70 ; V_52 ++ ) {
if ( V_249 == V_7 -> V_27 . V_59 . V_71 [ V_52 ] )
return F_76 ( V_7 , V_249 ) ;
}
return - V_16 ;
}
static int F_77 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
T_6 V_250 ;
int V_52 ;
if ( ! ( V_7 -> V_27 . V_46 & V_72 ) )
return - V_241 ;
if ( ! V_29 -> V_5 [ V_121 ] )
return - V_16 ;
V_250 = F_75 ( V_29 -> V_5 [ V_121 ] ) ;
for ( V_52 = 0 ; V_52 < V_7 -> V_27 . V_59 . V_75 ; V_52 ++ ) {
if ( V_250 == V_7 -> V_27 . V_59 . V_76 [ V_52 ] )
return F_78 ( V_7 , V_250 ) ;
}
return - V_16 ;
}
static int F_79 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
T_7 V_179 ;
if ( F_80 ( V_209 ) )
return - V_251 ;
if ( V_1 -> V_252 ) {
if ( F_80 ( V_1 -> V_252 ) )
return - V_251 ;
}
if ( V_1 -> V_214 == V_253 ||
! V_29 -> V_5 [ V_219 ] )
return - V_16 ;
V_179 = F_81 ( V_29 -> V_5 [ V_219 ] ) ;
if ( V_179 == F_82 ( V_254 ) )
return - V_16 ;
return F_83 ( V_7 , V_1 , V_179 ) ;
}
static int F_84 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
T_7 V_183 ;
if ( F_80 ( V_209 ) )
return - V_251 ;
if ( V_1 -> V_252 ) {
if ( F_80 ( V_1 -> V_252 ) )
return - V_251 ;
}
if ( V_1 -> V_214 == V_253 ||
! V_29 -> V_5 [ V_218 ] )
return - V_16 ;
V_183 = F_81 ( V_29 -> V_5 [ V_218 ] ) ;
if ( V_183 == F_82 ( V_255 ) ||
V_183 == F_82 ( V_256 ) )
return - V_16 ;
return F_85 ( V_7 , V_1 , V_183 ) ;
}
static int
F_86 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
T_2 V_227 , V_223 ;
if ( F_80 ( V_209 ) )
return - V_251 ;
if ( ! V_29 -> V_5 [ V_226 ] ||
! V_29 -> V_5 [ V_222 ] )
return - V_16 ;
V_227 = F_70 ( V_29 -> V_5 [ V_226 ] ) ;
V_223 = F_70 ( V_29 -> V_5 [ V_222 ] ) ;
if ( V_227 < V_7 -> V_27 . V_59 . V_83 ||
V_227 > V_7 -> V_27 . V_59 . V_85 ||
V_223 < V_7 -> V_27 . V_59 . V_87 ||
V_223 > V_7 -> V_27 . V_59 . V_89 ||
V_227 > V_223 )
return - V_16 ;
return F_87 ( V_7 , V_1 , V_227 , V_223 ) ;
}
static int
F_88 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
T_2 V_93 ;
if ( F_80 ( V_209 ) )
return - V_251 ;
if ( ! V_29 -> V_5 [ V_224 ] )
return - V_16 ;
V_93 = F_70 (
V_29 -> V_5 [ V_224 ] ) ;
if ( V_93 < V_7 -> V_27 . V_59 . V_91 ||
V_93 > V_7 -> V_27 . V_59 . V_93 )
return - V_16 ;
return F_89 ( V_7 , V_1 , V_93 ) ;
}
static int
F_90 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
T_8 V_97 ;
if ( F_80 ( V_209 ) )
return - V_251 ;
if ( ! V_29 -> V_5 [ V_220 ] )
return - V_16 ;
V_97 = F_91 (
V_29 -> V_5 [ V_220 ] ) ;
if ( V_97 < V_7 -> V_27 . V_59 . V_95 ||
V_97 > V_7 -> V_27 . V_59 . V_97 )
return - V_16 ;
return F_92 ( V_7 , V_1 , V_97 ) ;
}
static int F_93 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
int V_117 ;
if ( F_80 ( V_209 ) )
return - V_251 ;
if ( ! V_29 -> V_5 [ V_228 ] )
return - V_16 ;
V_117 = F_70 ( V_29 -> V_5 [ V_228 ] ) ;
if ( V_117 != 0 && V_117 != 1 )
return - V_16 ;
if ( ! F_94 ( V_117 , V_7 -> V_27 . V_59 . V_101 ) )
return - V_16 ;
return F_95 ( V_7 , V_1 , V_117 ) ;
}
static int
F_96 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
int V_230 ;
if ( F_80 ( V_209 ) )
return - V_251 ;
if ( ! V_29 -> V_5 [ V_229 ] )
return - V_16 ;
V_230 = F_70 ( V_29 -> V_5 [ V_229 ] ) ;
if ( V_230 != 0 && V_230 != 1 )
return - V_16 ;
return F_97 ( V_7 , V_1 , V_230 ) ;
}
static int
F_98 ( struct V_4 * V_257 ,
struct V_258 * V_259 )
{
struct V_4 * V_5 [ V_260 + 1 ] ;
if ( ! V_257 || F_99 ( V_5 , V_260 , V_257 ,
V_261 ) )
return - V_16 ;
if ( ! V_5 [ V_177 ] ||
! V_5 [ V_180 ] ||
! ( V_5 [ V_182 ] ||
V_5 [ V_185 ] ) )
return - V_16 ;
V_259 -> V_179 = F_81 ( V_5 [ V_177 ] ) ;
V_259 -> V_117 = F_4 ( V_5 [ V_180 ] ) ;
switch ( V_259 -> V_117 ) {
case V_181 :
V_259 -> V_183 = F_81 ( V_5 [ V_182 ] ) ;
break;
case V_184 :
V_259 -> V_186 = F_64 ( V_5 [ V_185 ] ) ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int
F_100 ( struct V_4 * V_257 ,
struct V_171 * V_172 )
{
struct V_4 * V_5 [ V_262 + 1 ] ;
if ( ! V_257 || F_99 ( V_5 , V_262 , V_257 ,
V_263 ) )
return - V_16 ;
if ( ! V_5 [ V_174 ] )
return - V_16 ;
V_172 -> V_117 = F_4 ( V_5 [ V_174 ] ) ;
switch ( V_172 -> V_117 ) {
case V_175 :
if ( ! V_5 [ V_176 ] )
return - V_16 ;
if ( F_98 ( V_5 [ V_176 ] ,
& V_172 -> V_178 ) < 0 )
return - V_16 ;
break;
case V_188 :
break;
case V_189 :
if ( ! V_5 [ V_190 ] )
return - V_16 ;
V_172 -> V_191 = F_101 ( V_5 [ V_190 ] ) ;
break;
case V_192 :
if ( ! V_5 [ V_193 ] )
return - V_16 ;
V_172 -> V_194 = F_64 ( V_5 [ V_193 ] ) ;
break;
default:
return - V_16 ;
}
if ( V_172 -> V_117 != V_175 ) {
if ( ! V_5 [ V_196 ] )
return - V_16 ;
V_172 -> V_197 = F_70 ( V_5 [ V_196 ] ) ;
}
return 0 ;
}
static int F_102 ( struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
struct V_199 V_200 ;
V_20 V_264 = 0 ;
int V_156 ;
if ( V_29 -> V_5 [ V_201 ] ) {
T_2 V_202 ;
V_202 = F_70 ( V_29 -> V_5 [ V_201 ] ) ;
if ( V_202 != 0 && V_202 != 1 )
return - V_16 ;
V_200 . V_202 = F_70 ( V_29 -> V_5 [ V_201 ] ) ;
V_264 |= V_265 ;
}
if ( V_29 -> V_5 [ V_207 ] ) {
V_156 = F_100 ( V_29 -> V_5 [ V_207 ] ,
& V_200 . V_208 ) ;
if ( V_156 < 0 )
return V_156 ;
V_264 |= V_266 ;
}
if ( V_29 -> V_5 [ V_203 ] ) {
V_200 . V_204 = F_4 ( V_29 -> V_5 [ V_203 ] ) ;
if ( V_200 . V_204 > V_267 )
return - V_16 ;
V_264 |= V_268 ;
}
if ( V_29 -> V_5 [ V_205 ] ) {
V_200 . V_206 = F_103 ( V_29 -> V_5 [ V_205 ] ) ;
V_264 |= V_269 ;
}
return F_104 ( V_7 , V_1 , & V_200 , V_264 ) ;
}
static int F_105 ( struct V_30 * V_48 , V_20 V_47 , V_20 V_44 ,
V_20 V_45 , int V_46 ,
struct V_6 * V_7 ,
struct V_23 * V_209 ,
const struct V_270 * V_271 )
{
void * V_104 ;
V_20 V_272 [ V_273 / 32 ] ;
struct V_4 * V_274 , * V_198 ;
V_104 = F_21 ( V_48 , V_44 , V_45 , V_46 , V_47 ) ;
if ( ! V_104 )
return - 1 ;
if ( F_28 ( V_48 , V_10 , V_209 -> V_18 ) )
goto V_108;
V_274 = F_24 ( V_48 , V_275 ) ;
if ( ! V_274 )
goto V_108;
V_198 = F_24 ( V_48 , V_276 ) ;
if ( ! V_198 )
goto V_108;
if ( F_49 ( V_48 , & V_271 -> V_197 ) < 0 )
goto V_108;
F_26 ( V_48 , V_198 ) ;
if ( F_31 ( V_48 , V_277 ,
V_271 -> V_271 -> V_278 ) )
goto V_108;
if ( V_271 -> V_271 -> V_278 & F_63 ( V_279 ) ) {
memset ( V_272 , 0 , sizeof( V_272 ) ) ;
V_272 [ 7 ] = V_271 -> V_271 -> V_280 ;
if ( F_106 ( V_48 , V_281 ,
sizeof( V_272 ) , V_272 ) )
goto V_108;
}
if ( F_106 ( V_48 , V_282 , V_283 ,
V_271 -> V_271 -> V_271 ) )
goto V_108;
F_26 ( V_48 , V_274 ) ;
F_37 ( V_48 , V_104 ) ;
return 0 ;
V_108:
F_38 ( V_48 , V_104 ) ;
return - V_152 ;
}
static int
F_107 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_6 * V_7 = NULL ;
struct V_270 * V_271 ;
struct V_284 * V_285 ;
struct V_1 * V_1 ;
int V_34 ;
V_34 = F_12 ( V_31 , V_33 , & V_7 , & V_1 ) ;
if ( V_34 )
return V_34 ;
if ( ! V_1 -> V_17 ) {
V_34 = - V_16 ;
goto V_286;
}
F_108 ( V_7 , V_1 ) ;
F_109 ( V_7 , V_1 , & V_285 ) ;
if ( V_33 -> args [ 2 ] )
goto V_235;
F_6 (key, &table->keys, list) {
if ( F_105 ( V_31 , V_287 ,
F_43 ( V_33 -> V_31 ) . V_44 ,
V_33 -> V_35 -> V_163 , V_164 ,
V_7 , V_1 -> V_17 , V_271 ) < 0 ) {
V_34 = - V_288 ;
F_110 ( V_7 , V_1 ) ;
goto V_286;
}
}
V_33 -> args [ 2 ] = 1 ;
V_235:
F_110 ( V_7 , V_1 ) ;
V_34 = V_31 -> V_165 ;
V_286:
F_20 ( V_7 ) ;
return V_34 ;
}
static int F_111 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
struct V_4 * V_5 [ V_289 + 1 ] ;
struct V_290 V_271 = { } ;
struct V_171 V_197 = { } ;
V_20 V_272 [ V_273 / 32 ] = { } ;
if ( F_99 ( V_5 , V_289 ,
V_29 -> V_5 [ V_275 ] ,
V_291 ) )
return - V_16 ;
if ( ! V_5 [ V_277 ] ||
! V_5 [ V_282 ] )
return - V_16 ;
if ( F_100 ( V_5 [ V_276 ] , & V_197 ) < 0 )
return - V_53 ;
V_271 . V_278 = F_70 ( V_5 [ V_277 ] ) ;
if ( V_271 . V_278 > F_63 ( V_292 ) ||
( ( V_271 . V_278 & F_63 ( V_279 ) ) &&
! V_5 [ V_281 ] ) )
return - V_16 ;
if ( V_5 [ V_281 ] ) {
F_112 ( V_272 , V_5 [ V_281 ] ,
V_273 / 8 ) ;
if ( V_272 [ 0 ] || V_272 [ 1 ] || V_272 [ 2 ] || V_272 [ 3 ] ||
V_272 [ 4 ] || V_272 [ 5 ] || V_272 [ 6 ] ||
V_272 [ 7 ] > F_63 ( V_293 ) )
return - V_16 ;
V_271 . V_280 = V_272 [ 7 ] ;
} else {
V_271 . V_280 = 0 ;
}
F_112 ( V_271 . V_271 , V_5 [ V_282 ] , V_283 ) ;
if ( F_100 ( V_5 [ V_276 ] , & V_197 ) < 0 )
return - V_53 ;
return F_113 ( V_7 , V_1 , & V_197 , & V_271 ) ;
}
static int F_114 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
struct V_4 * V_5 [ V_289 + 1 ] ;
struct V_171 V_197 ;
if ( F_99 ( V_5 , V_289 ,
V_29 -> V_5 [ V_275 ] ,
V_291 ) )
return - V_16 ;
if ( F_100 ( V_5 [ V_276 ] , & V_197 ) < 0 )
return - V_53 ;
return F_115 ( V_7 , V_1 , & V_197 ) ;
}
static int F_116 ( struct V_30 * V_48 , V_20 V_47 , V_20 V_44 ,
V_20 V_45 , int V_46 ,
struct V_6 * V_7 ,
struct V_23 * V_209 ,
const struct V_294 * V_295 )
{
void * V_104 ;
struct V_4 * V_296 ;
V_104 = F_21 ( V_48 , V_44 , V_45 , V_46 , V_47 ) ;
if ( ! V_104 )
return - 1 ;
if ( F_28 ( V_48 , V_10 , V_209 -> V_18 ) )
goto V_108;
V_296 = F_24 ( V_48 , V_297 ) ;
if ( ! V_296 )
goto V_108;
if ( F_28 ( V_48 , V_298 ,
V_295 -> V_206 ) ||
F_50 ( V_48 , V_299 , V_295 -> V_179 ) ||
F_50 ( V_48 , V_300 ,
V_295 -> V_183 ) ||
F_51 ( V_48 , V_301 ,
V_295 -> V_302 , V_303 ) ||
F_31 ( V_48 , V_304 ,
V_295 -> V_305 ) ||
F_28 ( V_48 , V_306 , V_295 -> V_307 ) )
goto V_108;
F_26 ( V_48 , V_296 ) ;
F_37 ( V_48 , V_104 ) ;
return 0 ;
V_108:
F_38 ( V_48 , V_104 ) ;
return - V_152 ;
}
static int
F_117 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_6 * V_7 = NULL ;
struct V_294 * V_209 ;
struct V_284 * V_285 ;
struct V_1 * V_1 ;
int V_34 ;
V_34 = F_12 ( V_31 , V_33 , & V_7 , & V_1 ) ;
if ( V_34 )
return V_34 ;
if ( ! V_1 -> V_17 ) {
V_34 = - V_16 ;
goto V_286;
}
F_108 ( V_7 , V_1 ) ;
F_109 ( V_7 , V_1 , & V_285 ) ;
if ( V_33 -> args [ 2 ] )
goto V_235;
F_6 (dev, &table->devices, list) {
if ( F_116 ( V_31 , V_308 ,
F_43 ( V_33 -> V_31 ) . V_44 ,
V_33 -> V_35 -> V_163 , V_164 ,
V_7 , V_1 -> V_17 , V_209 ) < 0 ) {
V_34 = - V_288 ;
F_110 ( V_7 , V_1 ) ;
goto V_286;
}
}
V_33 -> args [ 2 ] = 1 ;
V_235:
F_110 ( V_7 , V_1 ) ;
V_34 = V_31 -> V_165 ;
V_286:
F_20 ( V_7 ) ;
return V_34 ;
}
static int
F_118 ( struct V_4 * V_257 ,
struct V_294 * V_209 )
{
struct V_4 * V_5 [ V_309 + 1 ] ;
if ( ! V_257 || F_99 ( V_5 , V_309 , V_257 ,
V_310 ) )
return - V_16 ;
memset ( V_209 , 0 , sizeof( * V_209 ) ) ;
if ( ! V_5 [ V_298 ] ||
! V_5 [ V_299 ] ||
! V_5 [ V_300 ] ||
! V_5 [ V_301 ] ||
! V_5 [ V_304 ] ||
! V_5 [ V_306 ] )
return - V_16 ;
V_209 -> V_206 = F_4 ( V_5 [ V_298 ] ) ;
V_209 -> V_179 = F_81 ( V_5 [ V_299 ] ) ;
V_209 -> V_183 = F_81 ( V_5 [ V_300 ] ) ;
V_209 -> V_302 = F_64 ( V_5 [ V_301 ] ) ;
V_209 -> V_305 = F_70 ( V_5 [ V_304 ] ) ;
V_209 -> V_307 = F_4 ( V_5 [ V_306 ] ) ;
if ( V_209 -> V_307 > V_311 ||
( V_209 -> V_305 != 0 && V_209 -> V_305 != 1 ) )
return - V_16 ;
return 0 ;
}
static int F_119 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
struct V_294 V_295 ;
if ( F_118 ( V_29 -> V_5 [ V_297 ] ,
& V_295 ) < 0 )
return - V_16 ;
return F_120 ( V_7 , V_1 , & V_295 ) ;
}
static int F_121 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
struct V_4 * V_5 [ V_309 + 1 ] ;
T_5 V_186 ;
if ( F_99 ( V_5 , V_309 ,
V_29 -> V_5 [ V_297 ] ,
V_310 ) )
return - V_16 ;
if ( ! V_5 [ V_301 ] )
return - V_16 ;
V_186 = F_64 ( V_5 [ V_301 ] ) ;
return F_122 ( V_7 , V_1 , V_186 ) ;
}
static int F_123 ( struct V_30 * V_48 , V_20 V_47 , V_20 V_44 ,
V_20 V_45 , int V_46 ,
struct V_6 * V_7 ,
struct V_23 * V_209 , T_5 V_186 ,
const struct V_312 * V_313 )
{
void * V_104 ;
struct V_4 * V_314 , * V_198 ;
V_104 = F_21 ( V_48 , V_44 , V_45 , V_46 , V_47 ) ;
if ( ! V_104 )
return - 1 ;
if ( F_28 ( V_48 , V_10 , V_209 -> V_18 ) )
goto V_108;
V_314 = F_24 ( V_48 , V_315 ) ;
if ( ! V_314 )
goto V_108;
if ( F_51 ( V_48 , V_316 ,
V_186 , V_317 ) ||
F_28 ( V_48 , V_318 ,
V_313 -> V_206 ) )
goto V_108;
V_198 = F_24 ( V_48 , V_319 ) ;
if ( ! V_198 )
goto V_108;
if ( F_49 ( V_48 , & V_313 -> V_320 ) < 0 )
goto V_108;
F_26 ( V_48 , V_198 ) ;
F_26 ( V_48 , V_314 ) ;
F_37 ( V_48 , V_104 ) ;
return 0 ;
V_108:
F_38 ( V_48 , V_104 ) ;
return - V_152 ;
}
static int
F_124 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_6 * V_7 = NULL ;
struct V_312 * V_321 ;
struct V_294 * V_322 ;
struct V_284 * V_285 ;
struct V_1 * V_1 ;
int V_34 ;
V_34 = F_12 ( V_31 , V_33 , & V_7 , & V_1 ) ;
if ( V_34 )
return V_34 ;
if ( ! V_1 -> V_17 ) {
V_34 = - V_16 ;
goto V_286;
}
F_108 ( V_7 , V_1 ) ;
F_109 ( V_7 , V_1 , & V_285 ) ;
if ( V_33 -> args [ 2 ] )
goto V_235;
F_6 (dpos, &table->devices, list) {
F_6 (kpos, &dpos->keys, list) {
if ( F_123 ( V_31 ,
V_308 ,
F_43 ( V_33 -> V_31 ) . V_44 ,
V_33 -> V_35 -> V_163 ,
V_164 , V_7 ,
V_1 -> V_17 ,
V_322 -> V_302 ,
V_321 ) < 0 ) {
V_34 = - V_288 ;
F_110 ( V_7 , V_1 ) ;
goto V_286;
}
}
}
V_33 -> args [ 2 ] = 1 ;
V_235:
F_110 ( V_7 , V_1 ) ;
V_34 = V_31 -> V_165 ;
V_286:
F_20 ( V_7 ) ;
return V_34 ;
}
static int F_125 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
struct V_4 * V_5 [ V_323 + 1 ] ;
struct V_312 V_271 ;
T_5 V_186 ;
if ( ! V_29 -> V_5 [ V_315 ] ||
F_99 ( V_5 , V_323 ,
V_29 -> V_5 [ V_315 ] ,
V_324 ) < 0 )
return - V_16 ;
if ( ! V_5 [ V_318 ] ||
! V_5 [ V_316 ] )
return - V_16 ;
if ( F_100 ( V_5 [ V_319 ] ,
& V_271 . V_320 ) < 0 )
return - V_53 ;
V_271 . V_206 = F_4 ( V_5 [ V_318 ] ) ;
V_186 = F_64 ( V_5 [ V_316 ] ) ;
return F_126 ( V_7 , V_1 , V_186 , & V_271 ) ;
}
static int F_127 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
struct V_4 * V_5 [ V_323 + 1 ] ;
struct V_312 V_271 ;
T_5 V_186 ;
if ( F_99 ( V_5 , V_323 ,
V_29 -> V_5 [ V_315 ] ,
V_324 ) )
return - V_16 ;
if ( ! V_5 [ V_316 ] )
return - V_16 ;
if ( F_100 ( V_5 [ V_319 ] ,
& V_271 . V_320 ) < 0 )
return - V_53 ;
V_186 = F_64 ( V_5 [ V_316 ] ) ;
return F_128 ( V_7 , V_1 , V_186 , & V_271 ) ;
}
static int F_129 ( struct V_30 * V_48 , V_20 V_47 , V_20 V_44 ,
V_20 V_45 , int V_46 ,
struct V_6 * V_7 ,
struct V_23 * V_209 ,
const struct V_325 * V_326 )
{
void * V_104 ;
struct V_4 * V_327 ;
V_104 = F_21 ( V_48 , V_44 , V_45 , V_46 , V_47 ) ;
if ( ! V_104 )
return - 1 ;
if ( F_28 ( V_48 , V_10 , V_209 -> V_18 ) )
goto V_108;
V_327 = F_24 ( V_48 , V_328 ) ;
if ( ! V_327 )
goto V_108;
if ( F_28 ( V_48 , V_329 , V_326 -> V_330 ) ||
F_28 ( V_48 , V_331 , V_326 -> V_332 ) ||
F_31 ( V_48 , V_333 ,
V_326 -> V_334 ) )
goto V_108;
if ( V_326 -> V_330 == V_279 ) {
if ( F_28 ( V_48 , V_335 ,
V_326 -> V_336 ) )
goto V_108;
}
F_26 ( V_48 , V_327 ) ;
F_37 ( V_48 , V_104 ) ;
return 0 ;
V_108:
F_38 ( V_48 , V_104 ) ;
return - V_152 ;
}
static int
F_130 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_6 * V_7 = NULL ;
struct V_325 * V_326 ;
struct V_284 * V_285 ;
struct V_1 * V_1 ;
int V_34 ;
V_34 = F_12 ( V_31 , V_33 , & V_7 , & V_1 ) ;
if ( V_34 )
return V_34 ;
if ( ! V_1 -> V_17 ) {
V_34 = - V_16 ;
goto V_286;
}
F_108 ( V_7 , V_1 ) ;
F_109 ( V_7 , V_1 , & V_285 ) ;
if ( V_33 -> args [ 2 ] )
goto V_235;
F_6 (sl, &table->security_levels, list) {
if ( F_129 ( V_31 , V_308 ,
F_43 ( V_33 -> V_31 ) . V_44 ,
V_33 -> V_35 -> V_163 , V_164 ,
V_7 , V_1 -> V_17 , V_326 ) < 0 ) {
V_34 = - V_288 ;
F_110 ( V_7 , V_1 ) ;
goto V_286;
}
}
V_33 -> args [ 2 ] = 1 ;
V_235:
F_110 ( V_7 , V_1 ) ;
V_34 = V_31 -> V_165 ;
V_286:
F_20 ( V_7 ) ;
return V_34 ;
}
static int
F_131 ( struct V_4 * V_257 , struct V_325 * V_326 )
{
struct V_4 * V_5 [ V_337 + 1 ] ;
if ( ! V_257 || F_99 ( V_5 , V_337 , V_257 ,
V_338 ) )
return - V_16 ;
memset ( V_326 , 0 , sizeof( * V_326 ) ) ;
if ( ! V_5 [ V_331 ] ||
! V_5 [ V_329 ] ||
! V_5 [ V_333 ] )
return - V_16 ;
V_326 -> V_332 = F_70 ( V_5 [ V_331 ] ) ;
V_326 -> V_330 = F_4 ( V_5 [ V_329 ] ) ;
V_326 -> V_334 = F_70 ( V_5 [ V_333 ] ) ;
if ( V_326 -> V_330 > V_292 ||
( V_326 -> V_334 != 0 && V_326 -> V_334 != 1 ) )
return - V_16 ;
if ( V_326 -> V_330 == V_279 ) {
if ( ! V_5 [ V_335 ] )
return - V_16 ;
V_326 -> V_336 = F_4 ( V_5 [ V_335 ] ) ;
if ( V_326 -> V_336 > V_293 )
return - V_16 ;
}
return 0 ;
}
static int F_132 ( struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
struct V_325 V_326 ;
if ( F_131 ( V_29 -> V_5 [ V_328 ] ,
& V_326 ) < 0 )
return - V_16 ;
return F_133 ( V_7 , V_1 , & V_326 ) ;
}
static int F_134 ( struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_167 [ 0 ] ;
struct V_23 * V_209 = V_29 -> V_167 [ 1 ] ;
struct V_1 * V_1 = V_209 -> V_26 ;
struct V_325 V_326 ;
if ( ! V_29 -> V_5 [ V_328 ] ||
F_131 ( V_29 -> V_5 [ V_328 ] ,
& V_326 ) < 0 )
return - V_16 ;
return F_135 ( V_7 , V_1 , & V_326 ) ;
}
static int F_136 ( const struct V_339 * V_240 , struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 ;
struct V_1 * V_1 ;
struct V_23 * V_209 ;
bool V_340 = V_240 -> V_341 & V_342 ;
if ( V_340 )
F_13 () ;
if ( V_240 -> V_341 & V_343 ) {
V_7 = F_11 ( F_137 ( V_29 ) , V_29 ) ;
if ( F_16 ( V_7 ) ) {
if ( V_340 )
F_19 () ;
return F_17 ( V_7 ) ;
}
V_29 -> V_167 [ 0 ] = V_7 ;
} else if ( V_240 -> V_341 & V_344 ||
V_240 -> V_341 & V_345 ) {
F_2 () ;
V_1 = F_1 ( F_137 ( V_29 ) ,
V_29 -> V_5 ) ;
if ( F_16 ( V_1 ) ) {
if ( V_340 )
F_19 () ;
return F_17 ( V_1 ) ;
}
V_209 = V_1 -> V_17 ;
V_7 = F_10 ( V_1 -> V_27 ) ;
if ( V_240 -> V_341 & V_344 ) {
if ( ! V_209 ) {
if ( V_340 )
F_19 () ;
return - V_16 ;
}
V_29 -> V_167 [ 1 ] = V_209 ;
} else {
V_29 -> V_167 [ 1 ] = V_1 ;
}
if ( V_209 ) {
if ( V_240 -> V_341 & V_346 &&
! F_80 ( V_209 ) ) {
if ( V_340 )
F_19 () ;
return - V_347 ;
}
F_138 ( V_209 ) ;
}
V_29 -> V_167 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_139 ( const struct V_339 * V_240 , struct V_30 * V_31 ,
struct V_28 * V_29 )
{
if ( V_29 -> V_167 [ 1 ] ) {
if ( V_240 -> V_341 & V_345 ) {
struct V_1 * V_1 = V_29 -> V_167 [ 1 ] ;
if ( V_1 -> V_17 )
F_140 ( V_1 -> V_17 ) ;
} else {
F_140 ( V_29 -> V_167 [ 1 ] ) ;
}
}
if ( V_240 -> V_341 & V_342 )
F_19 () ;
}
int F_141 ( void )
{
return F_142 ( & V_37 , V_348 ,
V_349 ) ;
}
void F_143 ( void )
{
F_144 ( & V_37 ) ;
}
