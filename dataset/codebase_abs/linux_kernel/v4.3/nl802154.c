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
static inline void * F_12 ( struct V_30 * V_31 , V_20 V_32 , V_20 V_33 ,
int V_34 , T_2 V_35 )
{
return F_13 ( V_31 , V_32 , V_33 , & V_36 , V_34 , V_35 ) ;
}
static int
F_14 ( struct V_30 * V_37 , int V_38 , V_20 V_39 )
{
struct V_4 * V_40 = F_15 ( V_37 , V_38 ) ;
int V_41 ;
if ( ! V_40 )
return - V_42 ;
V_41 = 0 ;
while ( V_39 ) {
if ( ( V_39 & 1 ) && F_16 ( V_37 , V_41 ) )
return - V_42 ;
V_39 >>= 1 ;
V_41 ++ ;
}
F_17 ( V_37 , V_40 ) ;
return 0 ;
}
static int
F_18 ( struct V_6 * V_7 ,
struct V_30 * V_37 )
{
struct V_4 * V_43 ;
unsigned long V_44 ;
V_43 = F_15 ( V_37 , V_45 ) ;
if ( ! V_43 )
return - V_42 ;
for ( V_44 = 0 ; V_44 <= V_46 ; V_44 ++ ) {
if ( F_19 ( V_37 , V_47 ,
V_7 -> V_27 . V_48 . V_49 [ V_44 ] ) )
return - V_42 ;
}
F_17 ( V_37 , V_43 ) ;
return 0 ;
}
static int
F_20 ( struct V_30 * V_37 ,
struct V_6 * V_7 )
{
const struct V_50 * V_51 = & V_7 -> V_27 . V_48 ;
struct V_4 * V_52 , * V_53 ;
int V_41 ;
V_52 = F_15 ( V_37 , V_54 ) ;
if ( ! V_52 )
return - V_42 ;
V_53 = F_15 ( V_37 , V_55 ) ;
if ( ! V_53 )
return - V_42 ;
for ( V_41 = 0 ; V_41 <= V_46 ; V_41 ++ ) {
if ( V_51 -> V_49 [ V_41 ] ) {
if ( F_14 ( V_37 , V_41 , V_51 -> V_49 [ V_41 ] ) )
return - V_42 ;
}
}
F_17 ( V_37 , V_53 ) ;
if ( V_7 -> V_27 . V_34 & V_56 ) {
struct V_4 * V_57 ;
V_57 = F_15 ( V_37 ,
V_58 ) ;
if ( ! V_57 )
return - V_42 ;
for ( V_41 = 0 ; V_41 < V_51 -> V_59 ; V_41 ++ ) {
if ( F_21 ( V_37 , V_41 , V_51 -> V_60 [ V_41 ] ) )
return - V_42 ;
}
F_17 ( V_37 , V_57 ) ;
}
if ( V_7 -> V_27 . V_34 & V_61 ) {
struct V_4 * V_62 ;
V_62 = F_15 ( V_37 , V_63 ) ;
if ( ! V_62 )
return - V_42 ;
for ( V_41 = 0 ; V_41 < V_51 -> V_64 ; V_41 ++ ) {
if ( F_21 ( V_37 , V_41 , V_51 -> V_65 [ V_41 ] ) )
return - V_42 ;
}
F_17 ( V_37 , V_62 ) ;
}
if ( V_7 -> V_27 . V_34 & V_66 ) {
if ( F_14 ( V_37 , V_67 ,
V_51 -> V_68 ) ||
F_14 ( V_37 , V_69 ,
V_51 -> V_70 ) )
return - V_42 ;
}
if ( F_22 ( V_37 , V_71 , V_51 -> V_72 ) ||
F_22 ( V_37 , V_73 , V_51 -> V_74 ) ||
F_22 ( V_37 , V_75 , V_51 -> V_76 ) ||
F_22 ( V_37 , V_77 , V_51 -> V_78 ) ||
F_22 ( V_37 , V_79 ,
V_51 -> V_80 ) ||
F_22 ( V_37 , V_81 ,
V_51 -> V_82 ) ||
F_23 ( V_37 , V_83 ,
V_51 -> V_84 ) ||
F_23 ( V_37 , V_85 ,
V_51 -> V_86 ) ||
F_14 ( V_37 , V_87 ,
V_51 -> V_88 ) ||
F_19 ( V_37 , V_89 , V_51 -> V_90 ) )
return - V_42 ;
F_17 ( V_37 , V_52 ) ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 ,
enum V_91 V_35 ,
struct V_30 * V_37 , V_20 V_32 , V_20 V_33 ,
int V_34 )
{
struct V_4 * V_92 ;
void * V_93 ;
int V_41 ;
V_93 = F_12 ( V_37 , V_32 , V_33 , V_34 , V_35 ) ;
if ( ! V_93 )
return - V_42 ;
if ( F_19 ( V_37 , V_24 , V_7 -> V_14 ) ||
F_25 ( V_37 , V_94 ,
F_26 ( & V_7 -> V_27 ) ) ||
F_19 ( V_37 , V_95 ,
V_96 ) )
goto V_97;
if ( V_35 != V_98 )
goto V_99;
if ( F_22 ( V_37 , V_100 ,
V_7 -> V_27 . V_101 ) ||
F_22 ( V_37 , V_102 ,
V_7 -> V_27 . V_103 ) )
goto V_97;
if ( F_18 ( V_7 , V_37 ) )
goto V_97;
if ( V_7 -> V_27 . V_34 & V_66 ) {
if ( F_19 ( V_37 , V_104 ,
V_7 -> V_27 . V_105 . V_106 ) )
goto V_97;
if ( V_7 -> V_27 . V_105 . V_106 == V_107 ) {
if ( F_19 ( V_37 , V_108 ,
V_7 -> V_27 . V_105 . V_109 ) )
goto V_97;
}
}
if ( V_7 -> V_27 . V_34 & V_61 ) {
if ( F_21 ( V_37 , V_110 ,
V_7 -> V_27 . V_111 ) )
goto V_97;
}
if ( V_7 -> V_27 . V_34 & V_56 ) {
if ( F_21 ( V_37 , V_112 ,
V_7 -> V_27 . V_113 ) )
goto V_97;
}
if ( F_20 ( V_37 , V_7 ) )
goto V_97;
V_92 = F_15 ( V_37 , V_114 ) ;
if ( ! V_92 )
goto V_97;
V_41 = 0 ;
#define F_27 ( T_3 , T_4 ) \
do { \
if (rdev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL802154_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_27 ( V_115 , V_116 ) ;
F_27 ( V_117 , V_118 ) ;
F_27 ( V_119 , V_120 ) ;
F_27 ( V_121 , V_122 ) ;
F_27 ( V_123 , V_124 ) ;
F_27 ( V_125 , V_126 ) ;
F_27 ( V_127 , V_128 ) ;
F_27 ( V_129 , V_130 ) ;
F_27 ( V_131 , V_132 ) ;
F_27 ( V_133 , V_134 ) ;
if ( V_7 -> V_27 . V_34 & V_61 )
F_27 ( V_135 , V_136 ) ;
if ( V_7 -> V_27 . V_34 & V_56 )
F_27 ( V_137 , V_138 ) ;
if ( V_7 -> V_27 . V_34 & V_66 )
F_27 ( V_139 , V_140 ) ;
#undef F_27
F_17 ( V_37 , V_92 ) ;
V_99:
F_28 ( V_37 , V_93 ) ;
return 0 ;
V_97:
F_29 ( V_37 , V_93 ) ;
return - V_141 ;
}
static int F_30 ( struct V_30 * V_31 ,
struct V_142 * V_143 ,
struct V_144 * V_145 )
{
struct V_4 * * V_146 = V_36 . V_147 ;
int V_148 = F_31 ( V_143 -> V_149 , V_150 + V_36 . V_151 ,
V_146 , V_36 . V_152 , V_153 ) ;
if ( V_148 )
return 0 ;
if ( V_146 [ V_24 ] )
V_145 -> V_154 = F_4 ( V_146 [ V_24 ] ) ;
if ( V_146 [ V_12 ] )
V_145 -> V_154 = F_5 ( V_146 [ V_12 ] ) >> 32 ;
if ( V_146 [ V_10 ] ) {
struct V_23 * V_17 ;
struct V_6 * V_7 ;
int V_15 = F_4 ( V_146 [ V_10 ] ) ;
V_17 = F_9 ( & V_155 , V_15 ) ;
if ( ! V_17 )
return - V_21 ;
if ( V_17 -> V_26 ) {
V_7 = F_10 (
V_17 -> V_26 -> V_27 ) ;
V_145 -> V_154 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int
F_32 ( struct V_30 * V_31 , struct V_142 * V_143 )
{
int V_156 = 0 , V_148 ;
struct V_144 * V_145 = ( void * ) V_143 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_33 () ;
if ( ! V_145 ) {
V_145 = F_34 ( sizeof( * V_145 ) , V_157 ) ;
if ( ! V_145 ) {
F_35 () ;
return - V_158 ;
}
V_145 -> V_154 = - 1 ;
V_148 = F_30 ( V_31 , V_143 , V_145 ) ;
if ( V_148 ) {
F_36 ( V_145 ) ;
F_35 () ;
return V_148 ;
}
V_143 -> args [ 0 ] = ( long ) V_145 ;
}
F_6 (rdev, &cfg802154_rdev_list, list) {
if ( ++ V_156 <= V_145 -> V_159 )
continue;
if ( V_145 -> V_154 != - 1 &&
V_145 -> V_154 != V_7 -> V_14 )
continue;
V_148 = F_24 ( V_7 ,
V_98 ,
V_31 ,
F_37 ( V_143 -> V_31 ) . V_32 ,
V_143 -> V_149 -> V_160 , V_161 ) ;
if ( V_148 < 0 ) {
if ( ( V_148 == - V_42 || V_148 == - V_141 ) &&
! V_31 -> V_162 && V_143 -> V_163 < 4096 ) {
V_143 -> V_163 = 4096 ;
F_35 () ;
return 1 ;
}
V_156 -- ;
break;
}
break;
}
F_35 () ;
V_145 -> V_159 = V_156 ;
return V_31 -> V_162 ;
}
static int F_38 ( struct V_142 * V_143 )
{
F_36 ( ( void * ) V_143 -> args [ 0 ] ) ;
return 0 ;
}
static int F_39 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_30 * V_37 ;
struct V_6 * V_7 = V_29 -> V_164 [ 0 ] ;
V_37 = F_40 ( V_165 , V_157 ) ;
if ( ! V_37 )
return - V_158 ;
if ( F_24 ( V_7 , V_98 , V_37 ,
V_29 -> V_166 , V_29 -> V_167 , 0 ) < 0 ) {
F_41 ( V_37 ) ;
return - V_42 ;
}
return F_42 ( V_37 , V_29 ) ;
}
static inline T_1 V_13 ( struct V_1 * V_1 )
{
return ( T_1 ) V_1 -> V_19 |
( ( T_1 ) F_10 ( V_1 -> V_27 ) -> V_14 << 32 ) ;
}
static int
F_43 ( struct V_30 * V_37 , V_20 V_32 , V_20 V_33 , int V_34 ,
struct V_6 * V_7 ,
struct V_1 * V_1 )
{
struct V_23 * V_168 = V_1 -> V_17 ;
void * V_93 ;
V_93 = F_12 ( V_37 , V_32 , V_33 , V_34 ,
V_169 ) ;
if ( ! V_93 )
return - 1 ;
if ( V_168 &&
( F_19 ( V_37 , V_10 , V_168 -> V_18 ) ||
F_25 ( V_37 , V_170 , V_168 -> V_171 ) ) )
goto V_97;
if ( F_19 ( V_37 , V_24 , V_7 -> V_14 ) ||
F_19 ( V_37 , V_172 , V_1 -> V_173 ) ||
F_44 ( V_37 , V_12 , V_13 ( V_1 ) ) ||
F_19 ( V_37 , V_95 ,
V_7 -> V_174 ^
( V_96 << 2 ) ) )
goto V_97;
if ( F_45 ( V_37 , V_175 ,
V_1 -> V_176 ) ||
F_46 ( V_37 , V_177 ,
V_1 -> V_178 ) ||
F_46 ( V_37 , V_179 , V_1 -> V_180 ) )
goto V_97;
if ( F_23 ( V_37 , V_181 ,
V_1 -> V_182 ) ||
F_22 ( V_37 , V_183 , V_1 -> V_184 ) ||
F_22 ( V_37 , V_185 ,
V_1 -> V_186 ) ||
F_22 ( V_37 , V_187 , V_1 -> V_188 ) )
goto V_97;
if ( F_22 ( V_37 , V_189 , V_1 -> V_90 ) )
goto V_97;
if ( F_22 ( V_37 , V_190 , V_1 -> V_191 ) )
goto V_97;
F_28 ( V_37 , V_93 ) ;
return 0 ;
V_97:
F_29 ( V_37 , V_93 ) ;
return - V_141 ;
}
static int
F_47 ( struct V_30 * V_31 , struct V_142 * V_143 )
{
int V_192 = 0 ;
int V_193 = 0 ;
int V_194 = V_143 -> args [ 0 ] ;
int V_195 = V_143 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
F_33 () ;
F_6 (rdev, &cfg802154_rdev_list, list) {
if ( V_192 < V_194 ) {
V_192 ++ ;
continue;
}
V_193 = 0 ;
F_6 (wpan_dev, &rdev->wpan_dev_list, list) {
if ( V_193 < V_195 ) {
V_193 ++ ;
continue;
}
if ( F_43 ( V_31 , F_37 ( V_143 -> V_31 ) . V_32 ,
V_143 -> V_149 -> V_160 , V_161 ,
V_7 , V_1 ) < 0 ) {
goto V_196;
}
V_193 ++ ;
}
V_192 ++ ;
}
V_196:
F_35 () ;
V_143 -> args [ 0 ] = V_192 ;
V_143 -> args [ 1 ] = V_193 ;
return V_31 -> V_162 ;
}
static int F_48 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_30 * V_37 ;
struct V_6 * V_7 = V_29 -> V_164 [ 0 ] ;
struct V_1 * V_197 = V_29 -> V_164 [ 1 ] ;
V_37 = F_40 ( V_165 , V_157 ) ;
if ( ! V_37 )
return - V_158 ;
if ( F_43 ( V_37 , V_29 -> V_166 , V_29 -> V_167 , 0 ,
V_7 , V_197 ) < 0 ) {
F_41 ( V_37 ) ;
return - V_42 ;
}
return F_42 ( V_37 , V_29 ) ;
}
static int F_49 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_164 [ 0 ] ;
enum V_198 type = V_199 ;
T_5 V_176 = F_50 ( 0x0000000000000000ULL ) ;
if ( ! V_29 -> V_5 [ V_170 ] )
return - V_16 ;
if ( V_29 -> V_5 [ V_172 ] ) {
type = F_4 ( V_29 -> V_5 [ V_172 ] ) ;
if ( type > V_200 ||
! ( V_7 -> V_27 . V_48 . V_88 & F_51 ( type ) ) )
return - V_16 ;
}
if ( V_29 -> V_5 [ V_175 ] )
V_176 = ( V_201 T_5 ) F_5 (
V_29 -> V_5 [ V_175 ] ) ;
if ( ! V_7 -> V_202 -> V_115 )
return - V_203 ;
return F_52 ( V_7 ,
F_53 ( V_29 -> V_5 [ V_170 ] ) ,
V_204 , type , V_176 ) ;
}
static int F_54 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_164 [ 0 ] ;
struct V_1 * V_1 = V_29 -> V_164 [ 1 ] ;
if ( ! V_7 -> V_202 -> V_117 )
return - V_203 ;
if ( ! V_1 -> V_17 )
V_29 -> V_164 [ 1 ] = NULL ;
return F_55 ( V_7 , V_1 ) ;
}
static int F_56 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_164 [ 0 ] ;
T_2 V_205 , V_44 ;
if ( ! V_29 -> V_5 [ V_100 ] ||
! V_29 -> V_5 [ V_102 ] )
return - V_16 ;
V_44 = F_57 ( V_29 -> V_5 [ V_100 ] ) ;
V_205 = F_57 ( V_29 -> V_5 [ V_102 ] ) ;
if ( V_44 > V_46 || V_205 > V_206 ||
! ( V_7 -> V_27 . V_48 . V_49 [ V_44 ] & F_51 ( V_205 ) ) )
return - V_16 ;
return F_58 ( V_7 , V_44 , V_205 ) ;
}
static int F_59 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_164 [ 0 ] ;
struct V_207 V_105 ;
if ( ! ( V_7 -> V_27 . V_34 & V_66 ) )
return - V_203 ;
if ( ! V_29 -> V_5 [ V_104 ] )
return - V_16 ;
V_105 . V_106 = F_4 ( V_29 -> V_5 [ V_104 ] ) ;
if ( V_105 . V_106 < V_208 ||
V_105 . V_106 > V_209 ||
! ( V_7 -> V_27 . V_48 . V_68 & F_51 ( V_105 . V_106 ) ) )
return - V_16 ;
if ( V_105 . V_106 == V_107 ) {
if ( ! V_29 -> V_5 [ V_108 ] )
return - V_16 ;
V_105 . V_109 = F_4 ( V_29 -> V_5 [ V_108 ] ) ;
if ( V_105 . V_109 > V_210 ||
! ( V_7 -> V_27 . V_48 . V_70 & F_51 ( V_105 . V_109 ) ) )
return - V_16 ;
}
return F_60 ( V_7 , & V_105 ) ;
}
static int F_61 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_164 [ 0 ] ;
T_6 V_211 ;
int V_41 ;
if ( ! ( V_7 -> V_27 . V_34 & V_56 ) )
return - V_203 ;
if ( ! V_29 -> V_5 [ V_112 ] )
return - V_16 ;
V_211 = F_62 ( V_29 -> V_5 [ V_112 ] ) ;
for ( V_41 = 0 ; V_41 < V_7 -> V_27 . V_48 . V_59 ; V_41 ++ ) {
if ( V_211 == V_7 -> V_27 . V_48 . V_60 [ V_41 ] )
return F_63 ( V_7 , V_211 ) ;
}
return - V_16 ;
}
static int F_64 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_164 [ 0 ] ;
T_6 V_212 ;
int V_41 ;
if ( ! ( V_7 -> V_27 . V_34 & V_61 ) )
return - V_203 ;
if ( ! V_29 -> V_5 [ V_110 ] )
return - V_16 ;
V_212 = F_62 ( V_29 -> V_5 [ V_110 ] ) ;
for ( V_41 = 0 ; V_41 < V_7 -> V_27 . V_48 . V_64 ; V_41 ++ ) {
if ( V_212 == V_7 -> V_27 . V_48 . V_65 [ V_41 ] )
return F_65 ( V_7 , V_212 ) ;
}
return - V_16 ;
}
static int F_66 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_164 [ 0 ] ;
struct V_23 * V_168 = V_29 -> V_164 [ 1 ] ;
struct V_1 * V_1 = V_168 -> V_26 ;
T_7 V_180 ;
if ( F_67 ( V_168 ) )
return - V_213 ;
if ( V_1 -> V_173 == V_214 ||
! V_29 -> V_5 [ V_179 ] )
return - V_16 ;
V_180 = F_68 ( V_29 -> V_5 [ V_179 ] ) ;
if ( V_180 == F_69 ( V_215 ) )
return - V_16 ;
return F_70 ( V_7 , V_1 , V_180 ) ;
}
static int F_71 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_164 [ 0 ] ;
struct V_23 * V_168 = V_29 -> V_164 [ 1 ] ;
struct V_1 * V_1 = V_168 -> V_26 ;
T_7 V_178 ;
if ( F_67 ( V_168 ) )
return - V_213 ;
if ( V_1 -> V_173 == V_214 ||
! V_29 -> V_5 [ V_177 ] )
return - V_16 ;
V_178 = F_68 ( V_29 -> V_5 [ V_177 ] ) ;
if ( V_178 == F_69 ( V_216 ) ||
V_178 == F_69 ( V_217 ) )
return - V_16 ;
return F_72 ( V_7 , V_1 , V_178 ) ;
}
static int
F_73 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_164 [ 0 ] ;
struct V_23 * V_168 = V_29 -> V_164 [ 1 ] ;
struct V_1 * V_1 = V_168 -> V_26 ;
T_2 V_188 , V_184 ;
if ( F_67 ( V_168 ) )
return - V_213 ;
if ( ! V_29 -> V_5 [ V_187 ] ||
! V_29 -> V_5 [ V_183 ] )
return - V_16 ;
V_188 = F_57 ( V_29 -> V_5 [ V_187 ] ) ;
V_184 = F_57 ( V_29 -> V_5 [ V_183 ] ) ;
if ( V_188 < V_7 -> V_27 . V_48 . V_72 ||
V_188 > V_7 -> V_27 . V_48 . V_74 ||
V_184 < V_7 -> V_27 . V_48 . V_76 ||
V_184 > V_7 -> V_27 . V_48 . V_78 ||
V_188 > V_184 )
return - V_16 ;
return F_74 ( V_7 , V_1 , V_188 , V_184 ) ;
}
static int
F_75 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_164 [ 0 ] ;
struct V_23 * V_168 = V_29 -> V_164 [ 1 ] ;
struct V_1 * V_1 = V_168 -> V_26 ;
T_2 V_82 ;
if ( F_67 ( V_168 ) )
return - V_213 ;
if ( ! V_29 -> V_5 [ V_185 ] )
return - V_16 ;
V_82 = F_57 (
V_29 -> V_5 [ V_185 ] ) ;
if ( V_82 < V_7 -> V_27 . V_48 . V_80 ||
V_82 > V_7 -> V_27 . V_48 . V_82 )
return - V_16 ;
return F_76 ( V_7 , V_1 , V_82 ) ;
}
static int
F_77 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_164 [ 0 ] ;
struct V_23 * V_168 = V_29 -> V_164 [ 1 ] ;
struct V_1 * V_1 = V_168 -> V_26 ;
T_8 V_86 ;
if ( F_67 ( V_168 ) )
return - V_213 ;
if ( ! V_29 -> V_5 [ V_181 ] )
return - V_16 ;
V_86 = F_78 (
V_29 -> V_5 [ V_181 ] ) ;
if ( V_86 < V_7 -> V_27 . V_48 . V_84 ||
V_86 > V_7 -> V_27 . V_48 . V_86 )
return - V_16 ;
return F_79 ( V_7 , V_1 , V_86 ) ;
}
static int F_80 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_164 [ 0 ] ;
struct V_23 * V_168 = V_29 -> V_164 [ 1 ] ;
struct V_1 * V_1 = V_168 -> V_26 ;
int V_106 ;
if ( F_67 ( V_168 ) )
return - V_213 ;
if ( ! V_29 -> V_5 [ V_189 ] )
return - V_16 ;
V_106 = F_57 ( V_29 -> V_5 [ V_189 ] ) ;
if ( V_106 != 0 && V_106 != 1 )
return - V_16 ;
if ( ! F_81 ( V_106 , V_7 -> V_27 . V_48 . V_90 ) )
return - V_16 ;
return F_82 ( V_7 , V_1 , V_106 ) ;
}
static int
F_83 ( struct V_30 * V_31 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_164 [ 0 ] ;
struct V_23 * V_168 = V_29 -> V_164 [ 1 ] ;
struct V_1 * V_1 = V_168 -> V_26 ;
int V_191 ;
if ( F_67 ( V_168 ) )
return - V_213 ;
if ( ! V_29 -> V_5 [ V_190 ] )
return - V_16 ;
V_191 = F_57 ( V_29 -> V_5 [ V_190 ] ) ;
if ( V_191 != 0 && V_191 != 1 )
return - V_16 ;
return F_84 ( V_7 , V_1 , V_191 ) ;
}
static int F_85 ( const struct V_218 * V_202 , struct V_30 * V_31 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 ;
struct V_1 * V_1 ;
struct V_23 * V_168 ;
bool V_219 = V_202 -> V_220 & V_221 ;
if ( V_219 )
F_33 () ;
if ( V_202 -> V_220 & V_222 ) {
V_7 = F_11 ( F_86 ( V_29 ) , V_29 ) ;
if ( F_87 ( V_7 ) ) {
if ( V_219 )
F_35 () ;
return F_88 ( V_7 ) ;
}
V_29 -> V_164 [ 0 ] = V_7 ;
} else if ( V_202 -> V_220 & V_223 ||
V_202 -> V_220 & V_224 ) {
F_2 () ;
V_1 = F_1 ( F_86 ( V_29 ) ,
V_29 -> V_5 ) ;
if ( F_87 ( V_1 ) ) {
if ( V_219 )
F_35 () ;
return F_88 ( V_1 ) ;
}
V_168 = V_1 -> V_17 ;
V_7 = F_10 ( V_1 -> V_27 ) ;
if ( V_202 -> V_220 & V_223 ) {
if ( ! V_168 ) {
if ( V_219 )
F_35 () ;
return - V_16 ;
}
V_29 -> V_164 [ 1 ] = V_168 ;
} else {
V_29 -> V_164 [ 1 ] = V_1 ;
}
if ( V_168 ) {
if ( V_202 -> V_220 & V_225 &&
! F_67 ( V_168 ) ) {
if ( V_219 )
F_35 () ;
return - V_226 ;
}
F_89 ( V_168 ) ;
}
V_29 -> V_164 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_90 ( const struct V_218 * V_202 , struct V_30 * V_31 ,
struct V_28 * V_29 )
{
if ( V_29 -> V_164 [ 1 ] ) {
if ( V_202 -> V_220 & V_224 ) {
struct V_1 * V_1 = V_29 -> V_164 [ 1 ] ;
if ( V_1 -> V_17 )
F_91 ( V_1 -> V_17 ) ;
} else {
F_91 ( V_29 -> V_164 [ 1 ] ) ;
}
}
if ( V_202 -> V_220 & V_221 )
F_35 () ;
}
int F_92 ( void )
{
return F_93 ( & V_36 , V_227 ,
V_228 ) ;
}
void F_94 ( void )
{
F_95 ( & V_36 ) ;
}
