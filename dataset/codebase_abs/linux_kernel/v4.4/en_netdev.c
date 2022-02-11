int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
unsigned int V_7 = 0 ;
if ( V_3 && V_3 != V_8 )
return - V_9 ;
F_3 ( V_2 , V_3 ) ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ ) {
F_4 ( V_2 , V_6 , V_5 -> V_10 , V_7 ) ;
V_7 += V_5 -> V_10 ;
}
return 0 ;
}
static int F_5 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_6 ( V_12 , struct V_13 , V_12 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_15 * V_16 = V_5 -> V_16 [ V_14 -> V_17 ] ;
int V_18 ;
if ( ! V_5 -> V_19 )
return V_20 ;
if ( ! F_7 ( V_14 ) )
return V_21 ;
V_18 = F_8 ( V_2 , V_14 , 4 ) ;
if ( F_9 ( V_18 ) )
V_16 -> V_22 += V_18 ;
else
V_16 -> V_23 ++ ;
F_10 ( V_14 ) ;
return V_18 ;
}
static enum V_24 F_11 ( T_1 V_25 )
{
switch ( V_25 ) {
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
default:
return V_30 ;
}
}
static void F_12 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = F_6 ( V_32 ,
struct V_33 ,
V_32 ) ;
struct V_4 * V_5 = V_34 -> V_5 ;
struct V_35 V_36 = {
. V_37 = F_11 ( V_34 -> V_25 ) ,
{
. V_38 = {
. V_39 = V_34 -> V_39 ,
. V_40 = ( V_41 V_42 ) - 1 ,
. V_43 = V_34 -> V_43 ,
. V_44 = ( V_41 V_42 ) - 1 ,
} ,
} ,
} ;
struct V_35 V_45 = {
. V_37 = V_46 ,
{
. V_47 = {
. V_48 = V_34 -> V_48 ,
. V_49 = ( V_41 V_50 ) - 1 ,
. V_51 = V_34 -> V_51 ,
. V_52 = ( V_41 V_50 ) - 1 ,
} ,
} ,
} ;
struct V_35 V_53 = {
. V_37 = V_54 ,
} ;
struct V_55 V_56 = {
. V_57 = F_13 ( V_56 . V_57 ) ,
. V_58 = V_59 ,
. V_60 = 1 ,
. V_61 = 1 ,
. V_62 = V_63 ,
. V_64 = V_5 -> V_64 ,
. V_65 = V_66 ,
} ;
int V_67 ;
T_2 V_68 = F_14 ( V_69 << 16 ) ;
if ( V_36 . V_37 >= V_30 ) {
F_15 ( V_5 , L_1 ,
V_34 -> V_25 ) ;
goto V_70;
}
F_16 ( & V_53 . V_57 , & V_56 . V_57 ) ;
F_16 ( & V_45 . V_57 , & V_56 . V_57 ) ;
F_16 ( & V_36 . V_57 , & V_56 . V_57 ) ;
V_56 . V_71 = V_5 -> V_72 . V_73 [ V_34 -> V_74 ] . V_71 ;
memcpy ( V_53 . V_75 . V_76 , V_5 -> V_2 -> V_77 , V_78 ) ;
memcpy ( V_53 . V_75 . V_79 , & V_68 , V_78 ) ;
V_34 -> V_80 = 0 ;
if ( V_34 -> V_81 ) {
V_67 = F_17 ( V_5 -> V_82 -> V_2 , V_34 -> V_81 ) ;
if ( V_67 && V_67 != - V_83 )
F_18 ( V_5 , L_2 , V_67 ) ;
}
V_67 = F_19 ( V_5 -> V_82 -> V_2 , & V_56 , & V_34 -> V_81 ) ;
if ( V_67 )
F_18 ( V_5 , L_3 , V_67 ) ;
V_70:
F_20 ( V_5 ) ;
V_34 -> V_80 = 1 ;
}
static inline struct V_84 *
F_21 ( struct V_4 * V_5 , V_50 V_51 , V_50 V_48 ,
V_42 V_43 , V_42 V_39 )
{
unsigned long V_85 ;
int V_86 ;
V_85 = ( V_41 unsigned long ) V_43 |
( ( V_41 unsigned long ) V_39 << 2 ) ;
V_85 ^= ( V_41 unsigned long ) ( V_51 ^ V_48 ) ;
V_86 = F_22 ( V_85 , V_87 ) ;
return & V_5 -> V_88 [ V_86 ] ;
}
static struct V_33 *
F_23 ( struct V_4 * V_5 , int V_74 , V_50 V_51 ,
V_50 V_48 , T_1 V_25 , V_42 V_43 ,
V_42 V_39 , T_3 V_89 )
{
struct V_33 * V_34 = NULL ;
V_34 = F_24 ( sizeof( struct V_33 ) , V_90 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_5 = V_5 ;
V_34 -> V_74 = V_74 ;
F_25 ( & V_34 -> V_32 , F_12 ) ;
V_34 -> V_51 = V_51 ;
V_34 -> V_48 = V_48 ;
V_34 -> V_25 = V_25 ;
V_34 -> V_43 = V_43 ;
V_34 -> V_39 = V_39 ;
V_34 -> V_89 = V_89 ;
V_34 -> V_37 = V_5 -> V_91 ++ % V_92 ;
F_16 ( & V_34 -> V_93 , & V_5 -> V_94 ) ;
F_26 ( & V_34 -> V_95 ,
F_21 ( V_5 , V_51 , V_48 , V_43 ,
V_39 ) ) ;
return V_34 ;
}
static void F_27 ( struct V_33 * V_34 )
{
struct V_4 * V_5 = V_34 -> V_5 ;
int V_67 ;
F_28 ( & V_34 -> V_93 ) ;
V_67 = F_17 ( V_5 -> V_82 -> V_2 , V_34 -> V_81 ) ;
if ( V_67 && V_67 != - V_83 )
F_18 ( V_5 , L_2 , V_67 ) ;
F_29 ( V_34 ) ;
}
static inline struct V_33 *
F_30 ( struct V_4 * V_5 , V_50 V_51 , V_50 V_48 ,
T_1 V_25 , V_42 V_43 , V_42 V_39 )
{
struct V_33 * V_34 ;
struct V_33 * V_96 = NULL ;
F_31 (filter,
filter_hash_bucket(priv, src_ip, dst_ip,
src_port, dst_port),
filter_chain) {
if ( V_34 -> V_51 == V_51 &&
V_34 -> V_48 == V_48 &&
V_34 -> V_25 == V_25 &&
V_34 -> V_43 == V_43 &&
V_34 -> V_39 == V_39 ) {
V_96 = V_34 ;
break;
}
}
return V_96 ;
}
static int
F_32 ( struct V_1 * V_97 , const struct V_98 * V_99 ,
T_4 V_74 , T_3 V_89 )
{
struct V_4 * V_5 = F_2 ( V_97 ) ;
struct V_33 * V_34 ;
const struct V_100 * V_101 ;
const V_42 * V_102 ;
T_1 V_25 ;
V_50 V_51 ;
V_50 V_48 ;
V_42 V_43 ;
V_42 V_39 ;
int V_103 = F_33 ( V_99 ) ;
int V_96 = 0 ;
if ( V_99 -> V_104 != F_34 ( V_105 ) )
return - V_106 ;
V_101 = ( const struct V_100 * ) ( V_99 -> V_107 + V_103 ) ;
if ( F_35 ( V_101 ) )
return - V_106 ;
if ( ( V_101 -> V_104 != V_28 ) && ( V_101 -> V_104 != V_26 ) )
return - V_106 ;
V_102 = ( const V_42 * ) ( V_99 -> V_107 + V_103 + 4 * V_101 -> V_108 ) ;
V_25 = V_101 -> V_104 ;
V_51 = V_101 -> V_109 ;
V_48 = V_101 -> V_110 ;
V_43 = V_102 [ 0 ] ;
V_39 = V_102 [ 1 ] ;
F_36 ( & V_5 -> V_111 ) ;
V_34 = F_30 ( V_5 , V_51 , V_48 , V_25 ,
V_43 , V_39 ) ;
if ( V_34 ) {
if ( V_34 -> V_74 == V_74 )
goto V_112;
V_34 -> V_74 = V_74 ;
} else {
V_34 = F_23 ( V_5 , V_74 ,
V_51 , V_48 , V_25 ,
V_43 , V_39 , V_89 ) ;
if ( ! V_34 ) {
V_96 = - V_113 ;
goto V_114;
}
}
F_37 ( V_5 -> V_82 -> V_115 , & V_34 -> V_32 ) ;
V_112:
V_96 = V_34 -> V_37 ;
V_114:
F_38 ( & V_5 -> V_111 ) ;
return V_96 ;
}
void F_39 ( struct V_4 * V_5 )
{
struct V_33 * V_34 , * V_116 ;
F_40 ( V_117 ) ;
F_36 ( & V_5 -> V_111 ) ;
F_41 (filter, tmp, &priv->filters, next) {
F_42 ( & V_34 -> V_93 , & V_117 ) ;
F_43 ( & V_34 -> V_95 ) ;
}
F_38 ( & V_5 -> V_111 ) ;
F_41 (filter, tmp, &del_list, next) {
F_44 ( & V_34 -> V_32 ) ;
F_27 ( V_34 ) ;
}
}
static void F_20 ( struct V_4 * V_5 )
{
struct V_33 * V_34 = NULL , * V_116 , * V_118 = NULL ;
F_40 ( V_117 ) ;
int V_6 = 0 ;
F_36 ( & V_5 -> V_111 ) ;
F_41 (filter, tmp, &priv->filters, next) {
if ( V_6 > V_119 )
break;
if ( V_34 -> V_80 &&
! F_45 ( & V_34 -> V_32 ) &&
F_46 ( V_5 -> V_2 ,
V_34 -> V_74 , V_34 -> V_89 ,
V_34 -> V_37 ) ) {
F_42 ( & V_34 -> V_93 , & V_117 ) ;
F_43 ( & V_34 -> V_95 ) ;
} else
V_118 = V_34 ;
V_6 ++ ;
}
if ( V_118 && ( & V_118 -> V_93 != V_5 -> V_94 . V_93 ) )
F_42 ( & V_5 -> V_94 , & V_118 -> V_93 ) ;
F_38 ( & V_5 -> V_111 ) ;
F_41 (filter, tmp, &del_list, next)
F_27 ( V_34 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
V_42 V_120 , T_4 V_121 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_114 ;
int V_123 ;
F_48 ( V_124 , V_5 , L_4 , V_121 ) ;
F_49 ( V_121 , V_5 -> V_125 ) ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_82 -> V_127 && V_5 -> V_19 ) {
V_114 = F_51 ( V_82 -> V_2 , V_5 ) ;
if ( V_114 )
F_18 ( V_5 , L_5 ) ;
}
if ( F_52 ( V_82 -> V_2 , V_5 -> V_64 , V_121 , & V_123 ) )
F_48 ( V_124 , V_5 , L_6 , V_121 ) ;
F_53 ( & V_82 -> V_126 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
V_42 V_120 , T_4 V_121 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_114 ;
F_48 ( V_124 , V_5 , L_7 , V_121 ) ;
F_55 ( V_121 , V_5 -> V_125 ) ;
F_50 ( & V_82 -> V_126 ) ;
F_56 ( V_82 -> V_2 , V_5 -> V_64 , V_121 ) ;
if ( V_82 -> V_127 && V_5 -> V_19 ) {
V_114 = F_51 ( V_82 -> V_2 , V_5 ) ;
if ( V_114 )
F_18 ( V_5 , L_5 ) ;
}
F_53 ( & V_82 -> V_126 ) ;
return 0 ;
}
static void F_57 ( unsigned char V_76 [ V_78 + 2 ] , T_5 V_128 )
{
int V_6 ;
for ( V_6 = V_78 - 1 ; V_6 >= 0 ; -- V_6 ) {
V_76 [ V_6 ] = V_128 & 0xff ;
V_128 >>= 8 ;
}
memset ( & V_76 [ V_78 ] , 0 , 2 ) ;
}
static int F_58 ( struct V_4 * V_5 , unsigned char * V_129 ,
int V_71 , T_5 * V_81 )
{
int V_114 ;
if ( V_5 -> V_82 -> V_2 -> V_130 . V_131 != V_132 ||
V_5 -> V_82 -> V_2 -> V_130 . V_133 == V_134 )
return 0 ;
V_114 = F_59 ( V_5 -> V_82 -> V_2 , V_129 , V_5 -> V_64 , V_71 ,
V_135 , V_81 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_8 , V_114 ) ;
return V_114 ;
}
F_48 ( V_136 , V_5 , L_9 , V_129 , * V_81 ) ;
return 0 ;
}
static int F_60 ( struct V_4 * V_5 ,
unsigned char * V_137 , int * V_71 , T_5 * V_81 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_138 * V_2 = V_82 -> V_2 ;
int V_114 ;
switch ( V_2 -> V_130 . V_139 ) {
case V_140 : {
struct V_141 V_142 ;
T_1 V_143 [ 16 ] = { 0 } ;
V_142 . V_71 = * V_71 ;
memcpy ( & V_143 [ 10 ] , V_137 , V_78 ) ;
V_143 [ 5 ] = V_5 -> V_64 ;
V_114 = F_61 ( V_2 , & V_142 , V_143 , 0 , V_144 ) ;
break;
}
case V_145 : {
struct V_35 V_53 = { { NULL } } ;
T_2 V_68 = F_14 ( V_69 << 16 ) ;
struct V_55 V_56 = {
. V_58 = V_146 ,
. V_60 = 0 ,
. V_61 = 1 ,
. V_62 = V_63 ,
. V_65 = V_135 ,
} ;
V_56 . V_64 = V_5 -> V_64 ;
V_56 . V_71 = * V_71 ;
F_62 ( & V_56 . V_57 ) ;
V_53 . V_37 = V_54 ;
memcpy ( V_53 . V_75 . V_76 , V_137 , V_78 ) ;
memcpy ( V_53 . V_75 . V_79 , & V_68 , V_78 ) ;
F_16 ( & V_53 . V_57 , & V_56 . V_57 ) ;
V_114 = F_19 ( V_2 , & V_56 , V_81 ) ;
break;
}
default:
return - V_9 ;
}
if ( V_114 )
F_15 ( V_5 , L_10 ) ;
return V_114 ;
}
static void F_63 ( struct V_4 * V_5 ,
unsigned char * V_137 , int V_71 , T_5 V_81 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_138 * V_2 = V_82 -> V_2 ;
switch ( V_2 -> V_130 . V_139 ) {
case V_140 : {
struct V_141 V_142 ;
T_1 V_143 [ 16 ] = { 0 } ;
V_142 . V_71 = V_71 ;
memcpy ( & V_143 [ 10 ] , V_137 , V_78 ) ;
V_143 [ 5 ] = V_5 -> V_64 ;
F_64 ( V_2 , & V_142 , V_143 , V_144 ) ;
break;
}
case V_145 : {
F_17 ( V_2 , V_81 ) ;
break;
}
default:
F_18 ( V_5 , L_11 ) ;
}
}
static int F_65 ( struct V_4 * V_5 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_138 * V_2 = V_82 -> V_2 ;
int V_147 = 0 ;
int V_114 = 0 ;
int * V_71 = & V_5 -> V_148 ;
T_5 V_137 = F_66 ( V_5 -> V_2 -> V_77 ) ;
F_48 ( V_136 , V_5 , L_12 ,
V_5 -> V_2 -> V_77 ) ;
V_147 = F_67 ( V_2 , V_5 -> V_64 , V_137 ) ;
if ( V_147 < 0 ) {
V_114 = V_147 ;
F_18 ( V_5 , L_13 ,
V_5 -> V_2 -> V_77 ) ;
return V_114 ;
}
if ( V_2 -> V_130 . V_139 == V_149 ) {
int V_148 = F_68 ( V_2 , V_5 -> V_64 ) ;
* V_71 = V_148 + V_147 ;
return 0 ;
}
V_114 = F_69 ( V_2 , 1 , 1 , V_71 , V_150 ) ;
F_48 ( V_136 , V_5 , L_14 , * V_71 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_15 ) ;
F_70 ( V_2 , V_5 -> V_64 , V_137 ) ;
return V_114 ;
}
return 0 ;
}
static void F_71 ( struct V_4 * V_5 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_138 * V_2 = V_82 -> V_2 ;
int V_71 = V_5 -> V_148 ;
if ( V_2 -> V_130 . V_139 == V_149 ) {
T_5 V_137 = F_66 ( V_5 -> V_2 -> V_77 ) ;
F_48 ( V_136 , V_5 , L_16 ,
V_5 -> V_2 -> V_77 ) ;
F_70 ( V_2 , V_5 -> V_64 , V_137 ) ;
} else {
F_48 ( V_136 , V_5 , L_17 ,
V_5 -> V_64 , V_71 ) ;
F_72 ( V_2 , V_71 , 1 ) ;
V_5 -> V_151 &= ~ V_152 ;
}
}
static int F_73 ( struct V_4 * V_5 , int V_71 ,
unsigned char * V_153 , unsigned char * V_154 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_138 * V_2 = V_82 -> V_2 ;
int V_114 = 0 ;
T_5 V_155 = F_66 ( V_153 ) ;
if ( V_2 -> V_130 . V_139 != V_149 ) {
struct V_84 * V_156 ;
unsigned int V_157 ;
struct V_158 * V_159 ;
struct V_160 * V_116 ;
T_5 V_161 = F_66 ( V_154 ) ;
V_156 = & V_5 -> V_157 [ V_154 [ V_162 ] ] ;
F_74 (entry, tmp, bucket, hlist) {
if ( F_75 ( V_159 -> V_137 , V_154 ) ) {
F_63 ( V_5 , V_159 -> V_137 ,
V_71 , V_159 -> V_81 ) ;
F_70 ( V_2 , V_5 -> V_64 ,
V_161 ) ;
F_76 ( & V_159 -> V_163 ) ;
F_77 () ;
memcpy ( V_159 -> V_137 , V_153 , V_78 ) ;
V_159 -> V_81 = 0 ;
V_157 = V_153 [ V_162 ] ;
F_78 ( & V_159 -> V_163 ,
& V_5 -> V_157 [ V_157 ] ) ;
F_67 ( V_2 , V_5 -> V_64 , V_155 ) ;
V_114 = F_60 ( V_5 , V_153 ,
& V_71 ,
& V_159 -> V_81 ) ;
if ( V_114 )
return V_114 ;
if ( V_5 -> V_164 ) {
F_17 ( V_5 -> V_82 -> V_2 , V_5 -> V_164 ) ;
V_5 -> V_164 = 0 ;
}
V_114 = F_58 ( V_5 , V_153 , V_71 ,
& V_5 -> V_164 ) ;
return V_114 ;
}
}
return - V_9 ;
}
return F_79 ( V_2 , V_5 -> V_64 , V_71 , V_155 ) ;
}
static int F_80 ( struct V_4 * V_5 ,
unsigned char V_153 [ V_78 + 2 ] )
{
int V_114 = 0 ;
if ( V_5 -> V_19 ) {
V_114 = F_73 ( V_5 , V_5 -> V_148 ,
V_153 , V_5 -> V_165 ) ;
if ( V_114 )
F_18 ( V_5 , L_18 ) ;
} else
F_48 ( V_124 , V_5 , L_19 ) ;
if ( ! V_114 )
memcpy ( V_5 -> V_165 , V_153 , sizeof( V_5 -> V_165 ) ) ;
return V_114 ;
}
static int F_81 ( struct V_1 * V_2 , void * V_129 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_166 * V_109 = V_129 ;
unsigned char V_153 [ V_78 + 2 ] ;
int V_114 ;
if ( ! F_82 ( V_109 -> V_167 ) )
return - V_168 ;
F_50 ( & V_82 -> V_126 ) ;
memcpy ( V_153 , V_109 -> V_167 , V_78 ) ;
V_114 = F_80 ( V_5 , V_153 ) ;
if ( ! V_114 )
memcpy ( V_2 -> V_77 , V_109 -> V_167 , V_78 ) ;
F_53 ( & V_82 -> V_126 ) ;
return V_114 ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_169 * V_116 , * V_170 ;
F_41 (mc_to_del, tmp, &priv->mc_list, list) {
F_28 ( & V_170 -> V_57 ) ;
F_29 ( V_170 ) ;
}
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_171 * V_172 ;
struct V_169 * V_116 ;
F_83 ( V_2 ) ;
F_85 (ha, dev) {
V_116 = F_24 ( sizeof( struct V_169 ) , V_90 ) ;
if ( ! V_116 ) {
F_83 ( V_2 ) ;
return;
}
memcpy ( V_116 -> V_129 , V_172 -> V_129 , V_78 ) ;
F_16 ( & V_116 -> V_57 , & V_5 -> V_173 ) ;
}
}
static void F_86 ( struct V_4 * V_5 ,
struct V_174 * V_175 ,
struct V_174 * V_176 )
{
struct V_169 * V_177 , * V_178 , * V_179 ;
bool V_180 ;
F_87 (dst_tmp, dst, list) {
V_180 = false ;
F_87 (src_tmp, src, list) {
if ( F_88 ( V_177 -> V_129 , V_178 -> V_129 ) ) {
V_180 = true ;
break;
}
}
if ( ! V_180 )
V_177 -> V_181 = V_182 ;
}
F_87 (src_tmp, src, list) {
V_180 = false ;
F_87 (dst_tmp, dst, list) {
if ( F_88 ( V_177 -> V_129 , V_178 -> V_129 ) ) {
V_177 -> V_181 = V_183 ;
V_180 = true ;
break;
}
}
if ( ! V_180 ) {
V_179 = F_89 ( V_178 ,
sizeof( struct V_169 ) ,
V_184 ) ;
if ( ! V_179 )
return;
V_179 -> V_181 = V_185 ;
F_16 ( & V_179 -> V_57 , V_175 ) ;
}
}
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_19 )
return;
F_37 ( V_5 -> V_82 -> V_115 , & V_5 -> V_186 ) ;
}
static void F_91 ( struct V_4 * V_5 ,
struct V_122 * V_82 )
{
int V_114 = 0 ;
if ( ! ( V_5 -> V_151 & V_187 ) ) {
if ( F_92 ( V_5 ) )
F_15 ( V_5 , L_20 ) ;
V_5 -> V_151 |= V_187 ;
switch ( V_82 -> V_2 -> V_130 . V_139 ) {
case V_145 :
V_114 = F_93 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_148 ,
V_188 ) ;
if ( V_114 )
F_18 ( V_5 , L_21 ) ;
V_5 -> V_151 |= V_189 ;
break;
case V_140 :
V_114 = F_94 ( V_82 -> V_2 ,
V_5 -> V_148 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_22 ) ;
if ( ! ( V_5 -> V_151 & V_189 ) ) {
V_114 = F_95 ( V_82 -> V_2 ,
V_5 -> V_148 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_23 ) ;
V_5 -> V_151 |= V_189 ;
}
break;
case V_149 :
V_114 = F_96 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_148 ,
1 ) ;
if ( V_114 )
F_18 ( V_5 , L_21 ) ;
break;
}
V_114 = F_97 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_190 ) ;
if ( V_114 )
F_18 ( V_5 , L_24 ) ;
}
}
static void F_98 ( struct V_4 * V_5 ,
struct V_122 * V_82 )
{
int V_114 = 0 ;
if ( F_92 ( V_5 ) )
F_15 ( V_5 , L_25 ) ;
V_5 -> V_151 &= ~ V_187 ;
switch ( V_82 -> V_2 -> V_130 . V_139 ) {
case V_145 :
V_114 = F_99 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_188 ) ;
if ( V_114 )
F_18 ( V_5 , L_26 ) ;
V_5 -> V_151 &= ~ V_189 ;
break;
case V_140 :
V_114 = F_100 ( V_82 -> V_2 ,
V_5 -> V_148 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_27 ) ;
if ( V_5 -> V_151 & V_189 ) {
V_114 = F_101 ( V_82 -> V_2 ,
V_5 -> V_148 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_28 ) ;
V_5 -> V_151 &= ~ V_189 ;
}
break;
case V_149 :
V_114 = F_96 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_148 , 0 ) ;
if ( V_114 )
F_18 ( V_5 , L_26 ) ;
break;
}
}
static void F_102 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_122 * V_82 )
{
struct V_169 * V_191 , * V_116 ;
T_5 V_192 = 0 ;
T_1 V_173 [ 16 ] = { 0 } ;
int V_114 = 0 ;
if ( V_2 -> V_151 & V_193 ) {
V_114 = F_97 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_190 ) ;
if ( V_114 )
F_18 ( V_5 , L_24 ) ;
if ( ! ( V_5 -> V_151 & V_189 ) ) {
switch ( V_82 -> V_2 -> V_130 . V_139 ) {
case V_145 :
V_114 = F_93 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_148 ,
V_194 ) ;
break;
case V_140 :
V_114 = F_95 ( V_82 -> V_2 ,
V_5 -> V_148 ,
V_5 -> V_64 ) ;
break;
case V_149 :
break;
}
if ( V_114 )
F_18 ( V_5 , L_29 ) ;
V_5 -> V_151 |= V_189 ;
}
} else {
if ( V_5 -> V_151 & V_189 ) {
switch ( V_82 -> V_2 -> V_130 . V_139 ) {
case V_145 :
V_114 = F_99 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_194 ) ;
break;
case V_140 :
V_114 = F_101 ( V_82 -> V_2 ,
V_5 -> V_148 ,
V_5 -> V_64 ) ;
break;
case V_149 :
break;
}
if ( V_114 )
F_18 ( V_5 , L_28 ) ;
V_5 -> V_151 &= ~ V_189 ;
}
V_114 = F_97 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_190 ) ;
if ( V_114 )
F_18 ( V_5 , L_24 ) ;
F_97 ( V_82 -> V_2 , V_5 -> V_64 , V_195 ,
1 , V_196 ) ;
F_103 ( V_2 ) ;
F_84 ( V_2 ) ;
F_104 ( V_2 ) ;
F_87 (mclist, &priv->mc_list, list) {
V_192 = F_66 ( V_191 -> V_129 ) ;
F_97 ( V_82 -> V_2 , V_5 -> V_64 ,
V_192 , 0 , V_196 ) ;
}
V_114 = F_97 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_197 ) ;
if ( V_114 )
F_18 ( V_5 , L_30 ) ;
F_86 ( V_5 , & V_5 -> V_198 , & V_5 -> V_173 ) ;
F_41 (mclist, tmp, &priv->curr_list, list) {
if ( V_191 -> V_181 == V_182 ) {
memcpy ( & V_173 [ 10 ] , V_191 -> V_129 , V_78 ) ;
V_173 [ 5 ] = V_5 -> V_64 ;
V_114 = F_105 ( V_82 -> V_2 ,
& V_5 -> V_72 . V_199 ,
V_173 ,
V_144 ,
V_191 -> V_81 ) ;
if ( V_114 )
F_18 ( V_5 , L_31 ) ;
if ( V_191 -> V_164 ) {
V_114 = F_17 ( V_5 -> V_82 -> V_2 , V_191 -> V_164 ) ;
if ( V_114 )
F_18 ( V_5 , L_32 ) ;
}
F_28 ( & V_191 -> V_57 ) ;
F_29 ( V_191 ) ;
} else if ( V_191 -> V_181 == V_185 ) {
memcpy ( & V_173 [ 10 ] , V_191 -> V_129 , V_78 ) ;
V_173 [ 5 ] = V_5 -> V_64 ;
V_114 = F_106 ( V_82 -> V_2 ,
& V_5 -> V_72 . V_199 ,
V_173 ,
V_5 -> V_64 , 0 ,
V_144 ,
& V_191 -> V_81 ) ;
if ( V_114 )
F_18 ( V_5 , L_33 ) ;
V_114 = F_58 ( V_5 , & V_173 [ 10 ] , V_5 -> V_148 ,
& V_191 -> V_164 ) ;
if ( V_114 )
F_18 ( V_5 , L_34 ) ;
}
}
}
}
static void F_107 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_122 * V_82 )
{
struct V_171 * V_172 ;
struct V_158 * V_159 ;
struct V_160 * V_116 ;
bool V_180 ;
T_5 V_137 ;
int V_114 = 0 ;
struct V_84 * V_156 ;
unsigned int V_6 ;
int V_200 = 0 ;
T_3 V_201 ;
for ( V_6 = 0 ; V_6 < V_202 ; ++ V_6 ) {
V_156 = & V_5 -> V_157 [ V_6 ] ;
F_74 (entry, tmp, bucket, hlist) {
V_180 = false ;
F_108 (ha, dev) {
if ( F_75 ( V_159 -> V_137 ,
V_172 -> V_129 ) ) {
V_180 = true ;
break;
}
}
if ( F_75 ( V_159 -> V_137 ,
V_5 -> V_165 ) )
V_180 = true ;
if ( ! V_180 ) {
V_137 = F_66 ( V_159 -> V_137 ) ;
F_63 ( V_5 , V_159 -> V_137 ,
V_5 -> V_148 ,
V_159 -> V_81 ) ;
F_70 ( V_82 -> V_2 , V_5 -> V_64 , V_137 ) ;
F_76 ( & V_159 -> V_163 ) ;
F_109 ( V_159 , V_203 ) ;
F_48 ( V_136 , V_5 , L_35 ,
V_159 -> V_137 , V_5 -> V_64 ) ;
++ V_200 ;
}
}
}
if ( ( V_5 -> V_151 & V_152 ) && 0 == V_200 )
return;
V_201 = V_5 -> V_151 ;
V_5 -> V_151 &= ~ V_152 ;
F_108 (ha, dev) {
V_180 = false ;
V_156 = & V_5 -> V_157 [ V_172 -> V_129 [ V_162 ] ] ;
F_31 (entry, bucket, hlist) {
if ( F_75 ( V_159 -> V_137 , V_172 -> V_129 ) ) {
V_180 = true ;
break;
}
}
if ( ! V_180 ) {
V_159 = F_110 ( sizeof( * V_159 ) , V_184 ) ;
if ( ! V_159 ) {
F_18 ( V_5 , L_36 ,
V_172 -> V_129 , V_5 -> V_64 ) ;
V_5 -> V_151 |= V_152 ;
break;
}
V_137 = F_66 ( V_172 -> V_129 ) ;
memcpy ( V_159 -> V_137 , V_172 -> V_129 , V_78 ) ;
V_114 = F_67 ( V_82 -> V_2 , V_5 -> V_64 , V_137 ) ;
if ( V_114 < 0 ) {
F_18 ( V_5 , L_37 ,
V_172 -> V_129 , V_5 -> V_64 , V_114 ) ;
F_29 ( V_159 ) ;
V_5 -> V_151 |= V_152 ;
break;
}
V_114 = F_60 ( V_5 , V_172 -> V_129 ,
& V_5 -> V_148 ,
& V_159 -> V_81 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_38 ,
V_172 -> V_129 , V_5 -> V_64 , V_114 ) ;
F_70 ( V_82 -> V_2 , V_5 -> V_64 , V_137 ) ;
F_29 ( V_159 ) ;
V_5 -> V_151 |= V_152 ;
break;
} else {
unsigned int V_157 ;
F_48 ( V_136 , V_5 , L_39 ,
V_172 -> V_129 , V_5 -> V_64 ) ;
V_157 = V_172 -> V_129 [ V_162 ] ;
V_156 = & V_5 -> V_157 [ V_157 ] ;
F_78 ( & V_159 -> V_163 , V_156 ) ;
}
}
}
if ( V_5 -> V_151 & V_152 ) {
F_15 ( V_5 , L_40 ,
V_5 -> V_64 ) ;
} else if ( V_201 & V_152 ) {
F_15 ( V_5 , L_41 ,
V_5 -> V_64 ) ;
}
}
static void F_111 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_186 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_50 ( & V_82 -> V_126 ) ;
if ( ! V_82 -> V_127 ) {
F_48 ( V_124 , V_5 , L_42 ) ;
goto V_112;
}
if ( ! V_5 -> V_19 ) {
F_48 ( V_124 , V_5 , L_43 ) ;
goto V_112;
}
if ( ! F_112 ( V_2 ) ) {
if ( ! F_113 ( V_82 , V_5 -> V_64 ) ) {
if ( V_5 -> V_204 . V_205 ) {
V_5 -> V_206 = V_207 ;
F_114 ( V_2 ) ;
F_48 ( V_208 , V_5 , L_44 ) ;
}
}
}
if ( V_2 -> V_209 & V_210 )
F_107 ( V_5 , V_2 , V_82 ) ;
if ( ( V_2 -> V_151 & V_211 ) ||
( V_5 -> V_151 & V_152 ) ) {
F_91 ( V_5 , V_82 ) ;
goto V_112;
}
if ( V_5 -> V_151 & V_187 )
F_98 ( V_5 , V_82 ) ;
F_102 ( V_5 , V_2 , V_82 ) ;
V_112:
F_53 ( & V_82 -> V_126 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_13 * V_14 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_212 ; V_6 ++ ) {
V_14 = V_5 -> V_213 [ V_6 ] ;
F_116 ( & V_14 -> V_12 ) ;
}
}
static int F_117 ( struct V_4 * V_5 )
{
T_5 V_81 ;
int V_114 = 0 ;
int * V_71 = & V_5 -> V_148 ;
struct V_158 * V_159 ;
V_114 = F_60 ( V_5 , V_5 -> V_2 -> V_77 , V_71 , & V_81 ) ;
if ( V_114 )
return V_114 ;
V_114 = F_58 ( V_5 , V_5 -> V_2 -> V_77 , * V_71 ,
& V_5 -> V_164 ) ;
if ( V_114 )
goto V_214;
V_159 = F_110 ( sizeof( * V_159 ) , V_184 ) ;
if ( ! V_159 ) {
V_114 = - V_113 ;
goto V_215;
}
memcpy ( V_159 -> V_137 , V_5 -> V_2 -> V_77 , sizeof( V_159 -> V_137 ) ) ;
memcpy ( V_5 -> V_165 , V_159 -> V_137 , sizeof( V_5 -> V_165 ) ) ;
V_159 -> V_81 = V_81 ;
F_78 ( & V_159 -> V_163 ,
& V_5 -> V_157 [ V_159 -> V_137 [ V_162 ] ] ) ;
return 0 ;
V_215:
if ( V_5 -> V_164 )
F_17 ( V_5 -> V_82 -> V_2 , V_5 -> V_164 ) ;
V_214:
F_63 ( V_5 , V_5 -> V_2 -> V_77 , * V_71 , V_81 ) ;
return V_114 ;
}
static void F_118 ( struct V_4 * V_5 )
{
T_5 V_137 ;
unsigned int V_6 ;
int V_71 = V_5 -> V_148 ;
struct V_84 * V_156 ;
struct V_160 * V_116 ;
struct V_158 * V_159 ;
for ( V_6 = 0 ; V_6 < V_202 ; ++ V_6 ) {
V_156 = & V_5 -> V_157 [ V_6 ] ;
F_74 (entry, tmp, bucket, hlist) {
V_137 = F_66 ( V_159 -> V_137 ) ;
F_48 ( V_136 , V_5 , L_45 ,
V_159 -> V_137 ) ;
F_63 ( V_5 , V_159 -> V_137 ,
V_71 , V_159 -> V_81 ) ;
F_70 ( V_5 -> V_82 -> V_2 , V_5 -> V_64 , V_137 ) ;
F_76 ( & V_159 -> V_163 ) ;
F_109 ( V_159 , V_203 ) ;
}
}
if ( V_5 -> V_164 ) {
F_17 ( V_5 -> V_82 -> V_2 , V_5 -> V_164 ) ;
V_5 -> V_164 = 0 ;
}
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_6 ;
if ( F_120 ( V_5 ) )
F_15 ( V_5 , L_46 , V_5 -> V_64 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
if ( ! F_121 ( F_122 ( V_2 , V_6 ) ) )
continue;
F_15 ( V_5 , L_47 ,
V_6 , V_5 -> V_217 [ V_6 ] -> V_71 , V_5 -> V_217 [ V_6 ] -> V_218 ,
V_5 -> V_217 [ V_6 ] -> V_219 , V_5 -> V_217 [ V_6 ] -> V_220 ) ;
}
V_5 -> V_221 . V_222 ++ ;
F_48 ( V_136 , V_5 , L_48 ) ;
F_37 ( V_82 -> V_115 , & V_5 -> V_223 ) ;
}
static struct V_224 * F_123 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_36 ( & V_5 -> V_225 ) ;
memcpy ( & V_5 -> V_226 , & V_5 -> V_227 , sizeof( V_5 -> V_227 ) ) ;
F_38 ( & V_5 -> V_225 ) ;
return & V_5 -> V_226 ;
}
static void F_124 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
int V_6 ;
V_5 -> V_228 = V_229 ;
V_5 -> V_230 = V_231 ;
V_5 -> V_232 = V_233 ;
V_5 -> V_234 = V_235 ;
F_48 ( V_236 , V_5 , L_49 ,
V_5 -> V_2 -> V_237 , V_5 -> V_228 , V_5 -> V_230 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_212 ; V_6 ++ ) {
V_14 = V_5 -> V_213 [ V_6 ] ;
V_14 -> V_238 = V_5 -> V_228 ;
V_14 -> V_239 = V_5 -> V_230 ;
V_5 -> V_240 [ V_6 ] = V_241 ;
V_5 -> V_242 [ V_6 ] = 0 ;
V_5 -> V_243 [ V_6 ] = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
V_14 = V_5 -> V_244 [ V_6 ] ;
V_14 -> V_238 = V_5 -> V_232 ;
V_14 -> V_239 = V_5 -> V_234 ;
}
V_5 -> V_245 = V_246 ;
V_5 -> V_247 = V_248 ;
V_5 -> V_249 = V_250 ;
V_5 -> V_251 = V_252 ;
V_5 -> V_253 = V_254 ;
V_5 -> V_255 = 1 ;
V_5 -> V_256 = 0 ;
V_5 -> V_257 = 0 ;
}
static void F_125 ( struct V_4 * V_5 )
{
unsigned long V_258 = ( unsigned long ) ( V_259 - V_5 -> V_256 ) ;
struct V_13 * V_14 ;
unsigned long V_260 ;
unsigned long V_261 ;
unsigned long V_262 ;
unsigned long V_263 ;
unsigned long V_264 ;
unsigned long V_265 ;
int V_239 ;
int V_17 , V_114 ;
if ( ! V_5 -> V_255 || V_258 < V_5 -> V_253 * V_266 )
return;
for ( V_17 = 0 ; V_17 < V_5 -> V_212 ; V_17 ++ ) {
F_36 ( & V_5 -> V_225 ) ;
V_263 = V_5 -> V_16 [ V_17 ] -> V_260 ;
V_264 = V_5 -> V_16 [ V_17 ] -> V_267 ;
F_38 ( & V_5 -> V_225 ) ;
V_265 = ( ( unsigned long ) ( V_263 -
V_5 -> V_242 [ V_17 ] ) ) ;
V_260 = V_265 ;
V_261 = V_260 * V_266 / V_258 ;
V_262 = V_260 ? ( ( unsigned long ) ( V_264 -
V_5 -> V_243 [ V_17 ] ) ) / V_260 : 0 ;
if ( V_261 > ( V_268 / V_5 -> V_212 ) &&
V_262 > V_269 ) {
if ( V_261 < V_5 -> V_245 )
V_239 = V_5 -> V_247 ;
else if ( V_261 > V_5 -> V_249 )
V_239 = V_5 -> V_251 ;
else
V_239 = ( V_261 - V_5 -> V_245 ) *
( V_5 -> V_251 - V_5 -> V_247 ) /
( V_5 -> V_249 - V_5 -> V_245 ) +
V_5 -> V_247 ;
} else {
V_239 = V_5 -> V_247 ;
}
if ( V_239 != V_5 -> V_240 [ V_17 ] ) {
V_5 -> V_240 [ V_17 ] = V_239 ;
V_14 = V_5 -> V_213 [ V_17 ] ;
V_14 -> V_239 = V_239 ;
V_14 -> V_238 = V_5 -> V_228 ;
V_114 = F_126 ( V_5 , V_14 ) ;
if ( V_114 )
F_18 ( V_5 , L_50 ,
V_17 ) ;
}
V_5 -> V_242 [ V_17 ] = V_263 ;
V_5 -> V_243 [ V_17 ] = V_264 ;
}
V_5 -> V_256 = V_259 ;
}
static void F_127 ( struct V_31 * V_32 )
{
struct V_270 * V_271 = F_128 ( V_32 ) ;
struct V_4 * V_5 = F_6 ( V_271 , struct V_4 ,
V_272 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_114 ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_82 -> V_127 ) {
if ( V_5 -> V_19 ) {
V_114 = F_129 ( V_82 , V_5 -> V_64 , 0 ) ;
if ( V_114 )
F_48 ( V_124 , V_5 , L_51 ) ;
F_125 ( V_5 ) ;
}
F_130 ( V_82 -> V_115 , & V_5 -> V_272 , V_273 ) ;
}
if ( V_82 -> V_274 [ V_275 + 1 - V_5 -> V_64 ] ) {
F_80 ( V_5 , V_5 -> V_165 ) ;
V_82 -> V_274 [ V_275 + 1 - V_5 -> V_64 ] = 0 ;
}
F_53 ( & V_82 -> V_126 ) ;
}
static void F_131 ( struct V_31 * V_32 )
{
struct V_270 * V_271 = F_128 ( V_32 ) ;
struct V_4 * V_5 = F_6 ( V_271 , struct V_4 ,
V_276 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_82 -> V_127 ) {
if ( V_82 -> V_2 -> V_130 . V_277 & V_278 )
F_132 ( V_82 ) ;
F_133 ( V_5 ) ;
F_130 ( V_82 -> V_115 , & V_5 -> V_276 ,
V_279 ) ;
}
F_53 ( & V_82 -> V_126 ) ;
}
static void F_134 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_280 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_281 = V_5 -> V_205 ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_5 -> V_206 != V_281 ) {
if ( V_281 == V_282 ) {
F_135 ( V_5 , L_52 ) ;
F_136 ( V_5 -> V_2 ) ;
} else {
F_135 ( V_5 , L_44 ) ;
F_114 ( V_5 -> V_2 ) ;
}
}
V_5 -> V_206 = V_281 ;
F_53 ( & V_82 -> V_126 ) ;
}
static int F_137 ( struct V_4 * V_5 , int V_283 )
{
struct V_15 * V_17 = V_5 -> V_16 [ V_283 ] ;
int V_284 = V_5 -> V_82 -> V_2 -> V_284 ;
if ( ! F_138 ( & V_17 -> V_285 , V_184 ) )
return - V_113 ;
F_139 ( F_140 ( V_283 , V_284 ) ,
V_17 -> V_285 ) ;
return 0 ;
}
static void F_141 ( struct V_4 * V_5 , int V_283 )
{
F_142 ( V_5 -> V_16 [ V_283 ] -> V_285 ) ;
}
int F_143 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_13 * V_14 ;
struct V_286 * V_217 ;
int V_287 = 0 ;
int V_288 = 0 ;
int V_114 = 0 ;
int V_6 ;
int V_289 ;
T_1 V_173 [ 16 ] = { 0 } ;
if ( V_5 -> V_19 ) {
F_48 ( V_136 , V_5 , L_53 ) ;
return 0 ;
}
F_62 ( & V_5 -> V_173 ) ;
F_62 ( & V_5 -> V_198 ) ;
F_62 ( & V_5 -> V_290 ) ;
memset ( & V_5 -> V_291 [ 0 ] , 0 ,
sizeof( struct V_292 ) * V_293 ) ;
V_2 -> V_237 = F_144 ( V_2 -> V_237 , V_5 -> V_294 ) ;
F_145 ( V_2 ) ;
F_48 ( V_136 , V_5 , L_54 , V_5 -> V_295 ) ;
V_114 = F_146 ( V_5 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_55 ) ;
return V_114 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_212 ; V_6 ++ ) {
V_14 = V_5 -> V_213 [ V_6 ] ;
F_147 ( V_14 ) ;
V_114 = F_137 ( V_5 , V_6 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_56 ) ;
goto V_296;
}
V_114 = F_148 ( V_5 , V_14 , V_6 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_57 ) ;
F_141 ( V_5 , V_6 ) ;
goto V_296;
}
for ( V_289 = 0 ; V_289 < V_14 -> V_297 ; V_289 ++ ) {
struct V_298 * V_299 = NULL ;
V_299 = F_149 ( V_14 -> V_300 , V_289 , V_5 -> V_301 ) +
V_5 -> V_302 ;
V_299 -> V_303 = V_304 ;
}
V_114 = F_126 ( V_5 , V_14 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_58 ) ;
F_150 ( V_5 , V_14 ) ;
F_141 ( V_5 , V_6 ) ;
goto V_296;
}
F_151 ( V_5 , V_14 ) ;
V_5 -> V_16 [ V_6 ] -> V_218 = V_14 -> V_305 . V_218 ;
++ V_287 ;
}
F_48 ( V_136 , V_5 , L_59 , V_5 -> V_64 ) ;
V_114 = F_65 ( V_5 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_60 ) ;
goto V_296;
}
V_82 -> V_274 [ V_5 -> V_64 ] = 0 ;
V_5 -> V_306 =
F_152 ( V_82 -> V_2 , V_5 -> V_64 ) ;
V_114 = F_153 ( V_5 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_61 ) ;
goto V_307;
}
V_114 = F_154 ( V_5 ) ;
if ( V_114 )
goto V_308;
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
V_14 = V_5 -> V_244 [ V_6 ] ;
V_114 = F_148 ( V_5 , V_14 , V_6 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_62 ) ;
goto V_309;
}
V_114 = F_126 ( V_5 , V_14 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_58 ) ;
F_150 ( V_5 , V_14 ) ;
goto V_309;
}
F_48 ( V_136 , V_5 , L_63 , V_6 ) ;
V_14 -> V_300 -> V_310 = F_155 ( 0xffff ) ;
V_217 = V_5 -> V_217 [ V_6 ] ;
V_114 = F_156 ( V_5 , V_217 , V_14 -> V_305 . V_218 ,
V_6 / V_5 -> V_10 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_64 ) ;
F_150 ( V_5 , V_14 ) ;
goto V_309;
}
V_217 -> V_311 = F_122 ( V_2 , V_6 ) ;
F_151 ( V_5 , V_14 ) ;
for ( V_289 = 0 ; V_289 < V_217 -> V_312 ; V_289 += V_313 )
* ( ( T_3 * ) ( V_217 -> V_300 + V_289 ) ) = 0xffffffff ;
++ V_288 ;
}
V_114 = F_157 ( V_82 -> V_2 , V_5 -> V_64 ,
V_5 -> V_295 + V_314 ,
V_5 -> V_315 -> V_316 ,
V_5 -> V_315 -> V_317 ,
V_5 -> V_315 -> V_318 ,
V_5 -> V_315 -> V_319 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_65 ,
V_5 -> V_64 , V_114 ) ;
goto V_309;
}
V_114 = F_96 ( V_82 -> V_2 , V_5 -> V_64 , V_5 -> V_148 , 0 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_66 ) ;
goto V_309;
}
if ( V_82 -> V_2 -> V_130 . V_131 == V_132 ) {
V_114 = F_158 ( V_82 -> V_2 , V_5 -> V_64 , V_320 , 1 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_67 ,
V_114 ) ;
goto V_309;
}
}
F_48 ( V_124 , V_5 , L_68 ) ;
V_114 = F_159 ( V_82 -> V_2 , V_5 -> V_64 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_69 ) ;
goto V_309;
}
if ( V_82 -> V_2 -> V_130 . V_139 != V_149 &&
F_117 ( V_5 ) )
F_160 ( V_82 , L_70 ) ;
F_161 ( & V_173 [ 10 ] ) ;
V_173 [ 5 ] = V_5 -> V_64 ;
if ( F_106 ( V_82 -> V_2 , & V_5 -> V_72 . V_199 , V_173 ,
V_5 -> V_64 , 0 , V_144 ,
& V_5 -> V_321 ) )
F_160 ( V_82 , L_71 ) ;
V_5 -> V_151 &= ~ ( V_187 | V_189 ) ;
F_37 ( V_82 -> V_115 , & V_5 -> V_186 ) ;
#ifdef F_162
if ( V_5 -> V_82 -> V_2 -> V_130 . V_131 == V_132 )
F_163 ( V_2 ) ;
#endif
V_5 -> V_19 = true ;
F_164 ( V_2 ) ;
F_165 ( V_2 ) ;
return 0 ;
V_309:
while ( V_288 -- ) {
F_166 ( V_5 , V_5 -> V_217 [ V_288 ] ) ;
F_150 ( V_5 , V_5 -> V_244 [ V_288 ] ) ;
}
F_167 ( V_5 ) ;
V_308:
F_168 ( V_5 ) ;
V_307:
F_71 ( V_5 ) ;
V_296:
while ( V_287 -- ) {
F_150 ( V_5 , V_5 -> V_213 [ V_287 ] ) ;
F_141 ( V_5 , V_287 ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_212 ; V_6 ++ )
F_169 ( V_5 , V_5 -> V_16 [ V_6 ] ) ;
return V_114 ;
}
void F_170 ( struct V_1 * V_2 , int V_322 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_169 * V_191 , * V_116 ;
struct V_292 * V_323 , * V_324 ;
int V_6 ;
T_1 V_173 [ 16 ] = { 0 } ;
if ( ! V_5 -> V_19 ) {
F_48 ( V_136 , V_5 , L_72 ) ;
return;
}
F_171 ( V_82 -> V_2 , V_5 -> V_64 ) ;
F_172 ( V_2 ) ;
if ( V_322 )
F_173 ( V_2 ) ;
F_174 ( V_2 ) ;
F_175 ( V_2 ) ;
F_176 ( V_2 ) ;
V_5 -> V_19 = false ;
V_5 -> V_306 = F_177 ( V_82 -> V_2 ) ;
if ( V_82 -> V_2 -> V_130 . V_139 ==
V_145 ) {
V_5 -> V_151 &= ~ ( V_187 |
V_189 ) ;
F_99 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_188 ) ;
F_99 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_194 ) ;
} else if ( V_5 -> V_151 & V_187 ) {
V_5 -> V_151 &= ~ V_187 ;
F_100 ( V_82 -> V_2 , V_5 -> V_148 ,
V_5 -> V_64 ) ;
if ( V_5 -> V_151 & V_189 ) {
F_101 ( V_82 -> V_2 , V_5 -> V_148 ,
V_5 -> V_64 ) ;
V_5 -> V_151 &= ~ V_189 ;
}
}
F_161 ( & V_173 [ 10 ] ) ;
V_173 [ 5 ] = V_5 -> V_64 ;
F_105 ( V_82 -> V_2 , & V_5 -> V_72 . V_199 , V_173 ,
V_144 , V_5 -> V_321 ) ;
F_87 (mclist, &priv->curr_list, list) {
memcpy ( & V_173 [ 10 ] , V_191 -> V_129 , V_78 ) ;
V_173 [ 5 ] = V_5 -> V_64 ;
F_105 ( V_82 -> V_2 , & V_5 -> V_72 . V_199 ,
V_173 , V_144 , V_191 -> V_81 ) ;
if ( V_191 -> V_164 )
F_17 ( V_82 -> V_2 , V_191 -> V_164 ) ;
}
F_83 ( V_2 ) ;
F_41 (mclist, tmp, &priv->curr_list, list) {
F_28 ( & V_191 -> V_57 ) ;
F_29 ( V_191 ) ;
}
F_97 ( V_82 -> V_2 , V_5 -> V_64 , 0 , 1 , V_196 ) ;
if ( V_82 -> V_2 -> V_130 . V_139 ==
V_145 ) {
F_178 () ;
F_41 (flow, tmp_flow,
&priv->ethtool_list, list) {
F_17 ( V_82 -> V_2 , V_323 -> V_37 ) ;
F_28 ( & V_323 -> V_57 ) ;
}
}
F_167 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
F_166 ( V_5 , V_5 -> V_217 [ V_6 ] ) ;
F_150 ( V_5 , V_5 -> V_244 [ V_6 ] ) ;
}
F_179 ( 10 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ )
F_180 ( V_2 , V_5 -> V_217 [ V_6 ] ) ;
if ( V_82 -> V_2 -> V_130 . V_139 != V_149 )
F_118 ( V_5 ) ;
F_168 ( V_5 ) ;
F_71 ( V_5 ) ;
if ( ! ( V_82 -> V_2 -> V_130 . V_277 & V_325 ) )
V_82 -> V_274 [ V_5 -> V_64 ] = 1 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_212 ; V_6 ++ ) {
struct V_13 * V_14 = V_5 -> V_213 [ V_6 ] ;
F_181 () ;
while ( ! F_182 ( V_14 ) ) {
F_183 ( L_73 , V_6 ) ;
F_184 ( 1 ) ;
}
F_185 () ;
F_186 ( & V_14 -> V_12 ) ;
F_169 ( V_5 , V_5 -> V_16 [ V_6 ] ) ;
F_150 ( V_5 , V_14 ) ;
F_141 ( V_5 , V_6 ) ;
}
}
static void F_187 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_223 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_48 ( V_136 , V_5 , L_74 , V_5 -> V_64 ) ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_5 -> V_19 ) {
F_170 ( V_2 , 1 ) ;
if ( F_143 ( V_2 ) )
F_18 ( V_5 , L_75 , V_5 -> V_64 ) ;
}
F_53 ( & V_82 -> V_126 ) ;
}
static void F_188 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_6 ;
if ( F_129 ( V_82 , V_5 -> V_64 , 1 ) )
F_48 ( V_124 , V_5 , L_76 ) ;
memset ( & V_5 -> V_227 , 0 , sizeof( V_5 -> V_227 ) ) ;
memset ( & V_5 -> V_326 , 0 , sizeof( V_5 -> V_326 ) ) ;
memset ( & V_5 -> V_327 , 0 , sizeof( V_5 -> V_327 ) ) ;
memset ( & V_5 -> V_221 , 0 , sizeof( V_5 -> V_221 ) ) ;
memset ( & V_5 -> V_328 , 0 , sizeof( V_5 -> V_328 ) ) ;
memset ( & V_5 -> V_329 , 0 , sizeof( V_5 -> V_329 ) ) ;
memset ( & V_5 -> V_330 , 0 ,
sizeof( V_5 -> V_330 ) ) ;
memset ( & V_5 -> V_331 , 0 ,
sizeof( V_5 -> V_331 ) ) ;
memset ( & V_5 -> V_332 , 0 , sizeof( V_5 -> V_332 ) ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
V_5 -> V_217 [ V_6 ] -> V_267 = 0 ;
V_5 -> V_217 [ V_6 ] -> V_260 = 0 ;
V_5 -> V_217 [ V_6 ] -> V_333 = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_212 ; V_6 ++ ) {
V_5 -> V_16 [ V_6 ] -> V_267 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_260 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_334 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_335 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_336 = 0 ;
}
}
static int F_189 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_114 = 0 ;
F_50 ( & V_82 -> V_126 ) ;
if ( ! V_82 -> V_127 ) {
F_18 ( V_5 , L_77 ) ;
V_114 = - V_337 ;
goto V_112;
}
F_188 ( V_2 ) ;
V_114 = F_143 ( V_2 ) ;
if ( V_114 )
F_18 ( V_5 , L_78 , V_5 -> V_64 ) ;
V_112:
F_53 ( & V_82 -> V_126 ) ;
return V_114 ;
}
static int F_190 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
F_48 ( V_338 , V_5 , L_79 ) ;
F_50 ( & V_82 -> V_126 ) ;
F_170 ( V_2 , 0 ) ;
F_136 ( V_2 ) ;
F_53 ( & V_82 -> V_126 ) ;
return 0 ;
}
void F_191 ( struct V_4 * V_5 )
{
int V_6 ;
#ifdef F_192
V_5 -> V_2 -> V_339 = NULL ;
#endif
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
if ( V_5 -> V_217 && V_5 -> V_217 [ V_6 ] )
F_193 ( V_5 , & V_5 -> V_217 [ V_6 ] ) ;
if ( V_5 -> V_244 && V_5 -> V_244 [ V_6 ] )
F_194 ( V_5 , & V_5 -> V_244 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_212 ; V_6 ++ ) {
if ( V_5 -> V_16 [ V_6 ] )
F_195 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_5 -> V_315 -> V_340 , V_5 -> V_341 ) ;
if ( V_5 -> V_213 [ V_6 ] )
F_194 ( V_5 , & V_5 -> V_213 [ V_6 ] ) ;
}
}
int F_196 ( struct V_4 * V_5 )
{
struct V_342 * V_315 = V_5 -> V_315 ;
int V_6 ;
int V_343 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
V_343 = F_197 ( V_6 % F_198 () ) ;
if ( F_199 ( V_5 , & V_5 -> V_244 [ V_6 ] ,
V_315 -> V_344 , V_6 , V_345 , V_343 ) )
goto V_114;
if ( F_200 ( V_5 , & V_5 -> V_217 [ V_6 ] ,
V_315 -> V_344 , V_346 ,
V_343 , V_6 ) )
goto V_114;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_212 ; V_6 ++ ) {
V_343 = F_197 ( V_6 % F_198 () ) ;
if ( F_199 ( V_5 , & V_5 -> V_213 [ V_6 ] ,
V_315 -> V_340 , V_6 , V_347 , V_343 ) )
goto V_114;
if ( F_201 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_315 -> V_340 , V_5 -> V_341 ,
V_343 ) )
goto V_114;
}
#ifdef F_192
V_5 -> V_2 -> V_339 = F_202 ( V_5 -> V_82 -> V_2 , V_5 -> V_64 ) ;
#endif
return 0 ;
V_114:
F_18 ( V_5 , L_80 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_212 ; V_6 ++ ) {
if ( V_5 -> V_16 [ V_6 ] )
F_195 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_315 -> V_340 ,
V_5 -> V_341 ) ;
if ( V_5 -> V_213 [ V_6 ] )
F_194 ( V_5 , & V_5 -> V_213 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
if ( V_5 -> V_217 [ V_6 ] )
F_193 ( V_5 , & V_5 -> V_217 [ V_6 ] ) ;
if ( V_5 -> V_244 [ V_6 ] )
F_194 ( V_5 , & V_5 -> V_244 [ V_6 ] ) ;
}
return - V_113 ;
}
void F_203 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
F_48 ( V_136 , V_5 , L_81 , V_5 -> V_64 ) ;
if ( V_5 -> V_348 )
F_204 ( V_2 ) ;
if ( V_5 -> V_349 )
F_205 ( V_82 -> V_2 , & V_5 -> V_350 , V_351 ) ;
F_206 ( & V_5 -> V_272 ) ;
F_206 ( & V_5 -> V_276 ) ;
F_207 ( V_82 -> V_115 ) ;
if ( V_82 -> V_2 -> V_130 . V_277 & V_278 )
F_208 ( V_82 ) ;
F_50 ( & V_82 -> V_126 ) ;
V_82 -> V_352 [ V_5 -> V_64 ] = NULL ;
V_82 -> V_353 [ V_5 -> V_64 ] = NULL ;
F_53 ( & V_82 -> V_126 ) ;
F_191 ( V_5 ) ;
F_29 ( V_5 -> V_217 ) ;
F_29 ( V_5 -> V_244 ) ;
F_209 ( V_2 ) ;
}
static int F_210 ( struct V_1 * V_2 , int V_354 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_114 = 0 ;
F_48 ( V_136 , V_5 , L_82 ,
V_2 -> V_237 , V_354 ) ;
if ( ( V_354 < V_355 ) || ( V_354 > V_5 -> V_294 ) ) {
F_18 ( V_5 , L_83 , V_354 ) ;
return - V_356 ;
}
V_2 -> V_237 = V_354 ;
if ( F_211 ( V_2 ) ) {
F_50 ( & V_82 -> V_126 ) ;
if ( ! V_82 -> V_127 ) {
F_48 ( V_136 , V_5 , L_84 ) ;
} else {
F_170 ( V_2 , 1 ) ;
V_114 = F_143 ( V_2 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_85 ,
V_5 -> V_64 ) ;
F_37 ( V_82 -> V_115 , & V_5 -> V_223 ) ;
}
}
F_53 ( & V_82 -> V_126 ) ;
}
return 0 ;
}
static int F_212 ( struct V_1 * V_2 , struct V_357 * V_358 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_359 V_360 ;
if ( F_213 ( & V_360 , V_358 -> V_361 , sizeof( V_360 ) ) )
return - V_362 ;
if ( V_360 . V_151 )
return - V_9 ;
if ( ! ( V_82 -> V_2 -> V_130 . V_277 & V_278 ) )
return - V_9 ;
switch ( V_360 . V_363 ) {
case V_364 :
case V_365 :
break;
default:
return - V_366 ;
}
switch ( V_360 . V_367 ) {
case V_368 :
break;
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
V_360 . V_367 = V_369 ;
break;
default:
return - V_366 ;
}
if ( F_214 ( V_2 , V_360 , V_2 -> V_383 ) ) {
V_360 . V_363 = V_364 ;
V_360 . V_367 = V_368 ;
}
return F_215 ( V_358 -> V_361 , & V_360 ,
sizeof( V_360 ) ) ? - V_362 : 0 ;
}
static int F_216 ( struct V_1 * V_2 , struct V_357 * V_358 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_215 ( V_358 -> V_361 , & V_5 -> V_359 ,
sizeof( V_5 -> V_359 ) ) ? - V_362 : 0 ;
}
static int F_217 ( struct V_1 * V_2 , struct V_357 * V_358 , int V_384 )
{
switch ( V_384 ) {
case V_385 :
return F_212 ( V_2 , V_358 ) ;
case V_386 :
return F_216 ( V_2 , V_358 ) ;
default:
return - V_387 ;
}
}
static T_6 F_218 ( struct V_1 * V_388 ,
T_6 V_383 )
{
struct V_4 * V_389 = F_2 ( V_388 ) ;
struct V_122 * V_82 = V_389 -> V_82 ;
if ( V_383 & V_390 &&
! ( V_82 -> V_2 -> V_130 . V_277 & V_391 ) )
V_383 |= V_392 ;
else
V_383 &= ~ V_392 ;
return V_383 ;
}
static int F_219 ( struct V_1 * V_388 ,
T_6 V_383 )
{
struct V_4 * V_5 = F_2 ( V_388 ) ;
bool V_393 = false ;
int V_96 = 0 ;
if ( F_220 ( V_388 , V_383 , V_394 ) ) {
F_135 ( V_5 , L_86 ,
( V_383 & V_394 ) ? L_87 : L_88 ) ;
V_393 = true ;
}
if ( F_220 ( V_388 , V_383 , V_395 ) ) {
T_1 V_396 = ( V_383 & V_395 ) ? 1 : 0 ;
F_135 ( V_5 , L_89 ,
V_396 ? L_87 : L_88 ) ;
V_96 = F_221 ( V_5 -> V_82 -> V_2 ,
V_5 -> V_64 , V_396 ) ;
if ( V_96 )
return V_96 ;
}
if ( F_220 ( V_388 , V_383 , V_390 ) ) {
F_135 ( V_5 , L_90 ,
( V_383 & V_390 ) ? L_87 : L_88 ) ;
V_393 = true ;
}
if ( F_220 ( V_388 , V_383 , V_397 ) )
F_135 ( V_5 , L_91 ,
( V_383 & V_397 ) ? L_87 : L_88 ) ;
if ( F_220 ( V_388 , V_383 , V_398 ) )
F_135 ( V_5 , L_92 ,
( V_383 & V_398 ) ? L_87 : L_88 ) ;
if ( F_220 ( V_388 , V_383 , V_399 ) ) {
F_135 ( V_5 , L_93 ,
( V_383 & V_399 ) ? L_87 : L_88 ) ;
F_222 ( V_388 , V_383 ) ;
}
if ( V_393 ) {
V_96 = F_214 ( V_388 , V_5 -> V_359 ,
V_383 ) ;
if ( V_96 )
return V_96 ;
}
return 0 ;
}
static int F_223 ( struct V_1 * V_2 , int V_400 , T_1 * V_137 )
{
struct V_4 * V_389 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_389 -> V_82 ;
T_5 V_401 = F_66 ( V_137 ) ;
if ( ! F_82 ( V_137 ) )
return - V_9 ;
return F_224 ( V_82 -> V_2 , V_389 -> V_64 , V_400 , V_401 ) ;
}
static int F_225 ( struct V_1 * V_2 , int V_402 , T_4 V_403 , T_1 V_404 )
{
struct V_4 * V_389 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_389 -> V_82 ;
return F_226 ( V_82 -> V_2 , V_389 -> V_64 , V_402 , V_403 , V_404 ) ;
}
static int F_227 ( struct V_1 * V_2 , int V_402 , int V_405 ,
int V_406 )
{
struct V_4 * V_389 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_389 -> V_82 ;
return F_228 ( V_82 -> V_2 , V_389 -> V_64 , V_402 , V_405 ,
V_406 ) ;
}
static int F_229 ( struct V_1 * V_2 , int V_402 , bool V_407 )
{
struct V_4 * V_389 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_389 -> V_82 ;
return F_230 ( V_82 -> V_2 , V_389 -> V_64 , V_402 , V_407 ) ;
}
static int F_231 ( struct V_1 * V_2 , int V_402 , struct V_408 * V_409 )
{
struct V_4 * V_389 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_389 -> V_82 ;
return F_232 ( V_82 -> V_2 , V_389 -> V_64 , V_402 , V_409 ) ;
}
static int F_233 ( struct V_1 * V_2 , int V_402 , int V_205 )
{
struct V_4 * V_389 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_389 -> V_82 ;
return F_234 ( V_82 -> V_2 , V_389 -> V_64 , V_402 , V_205 ) ;
}
static int F_235 ( struct V_1 * V_2 , int V_402 ,
struct V_410 * V_411 )
{
struct V_4 * V_389 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_389 -> V_82 ;
return F_236 ( V_82 -> V_2 , V_389 -> V_64 , V_402 , V_411 ) ;
}
static int F_237 ( struct V_1 * V_2 ,
struct V_412 * V_413 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_138 * V_82 = V_5 -> V_82 -> V_2 ;
int V_6 ;
T_5 V_414 = V_82 -> V_130 . V_414 [ V_5 -> V_64 ] ;
if ( ! V_414 )
return - V_387 ;
V_413 -> V_415 = sizeof( V_414 ) ;
for ( V_6 = V_416 - 1 ; V_6 >= 0 ; -- V_6 ) {
V_413 -> V_37 [ V_6 ] = V_414 & 0xff ;
V_414 >>= 8 ;
}
return 0 ;
}
static void F_238 ( struct V_31 * V_32 )
{
int V_96 ;
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_417 ) ;
V_96 = F_239 ( V_5 -> V_82 -> V_2 , V_5 -> V_418 ) ;
if ( V_96 )
goto V_112;
V_96 = F_158 ( V_5 -> V_82 -> V_2 , V_5 -> V_64 ,
V_320 , 1 ) ;
V_112:
if ( V_96 ) {
F_18 ( V_5 , L_94 , V_96 ) ;
return;
}
V_5 -> V_2 -> V_419 |= V_420 | V_421 |
V_422 | V_423 ;
V_5 -> V_2 -> V_424 |= V_423 ;
V_5 -> V_2 -> V_383 |= V_423 ;
}
static void F_240 ( struct V_31 * V_32 )
{
int V_96 ;
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_425 ) ;
V_5 -> V_2 -> V_419 &= ~ ( V_420 | V_421 |
V_422 | V_423 ) ;
V_5 -> V_2 -> V_424 &= ~ V_423 ;
V_5 -> V_2 -> V_383 &= ~ V_423 ;
V_96 = F_158 ( V_5 -> V_82 -> V_2 , V_5 -> V_64 ,
V_320 , 0 ) ;
if ( V_96 )
F_18 ( V_5 , L_94 , V_96 ) ;
V_5 -> V_418 = 0 ;
}
static void F_241 ( struct V_1 * V_2 ,
T_7 V_426 , V_42 V_64 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_42 V_427 ;
if ( V_5 -> V_82 -> V_2 -> V_130 . V_131 != V_132 )
return;
if ( V_426 == V_428 )
return;
V_427 = V_5 -> V_418 ;
if ( V_427 && V_427 != V_64 ) {
F_15 ( V_5 , L_95 ,
F_242 ( V_427 ) , F_242 ( V_64 ) ) ;
return;
}
V_5 -> V_418 = V_64 ;
F_37 ( V_5 -> V_82 -> V_115 , & V_5 -> V_417 ) ;
}
static void F_243 ( struct V_1 * V_2 ,
T_7 V_426 , V_42 V_64 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_42 V_427 ;
if ( V_5 -> V_82 -> V_2 -> V_130 . V_131 != V_132 )
return;
if ( V_426 == V_428 )
return;
V_427 = V_5 -> V_418 ;
if ( V_427 != V_64 ) {
F_48 ( V_136 , V_5 , L_96 , F_242 ( V_64 ) ) ;
return;
}
F_37 ( V_5 -> V_82 -> V_115 , & V_5 -> V_425 ) ;
}
static T_6 F_244 ( struct V_98 * V_99 ,
struct V_1 * V_2 ,
T_6 V_383 )
{
V_383 = F_245 ( V_99 , V_383 ) ;
return F_246 ( V_99 , V_383 ) ;
}
static int F_247 ( struct V_1 * V_2 , int V_429 , T_3 V_430 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_286 * V_217 = V_5 -> V_217 [ V_429 ] ;
struct V_431 V_432 ;
int V_114 ;
if ( ! ( V_5 -> V_82 -> V_2 -> V_130 . V_277 & V_433 ) )
return - V_387 ;
if ( V_430 >> 12 ) {
V_432 . V_434 = V_435 ;
V_432 . V_436 = V_430 / 1000 ;
} else if ( V_430 ) {
V_432 . V_434 = V_437 ;
V_432 . V_436 = V_430 ;
} else {
V_432 . V_434 = 0 ;
V_432 . V_436 = 0 ;
}
V_114 = F_248 ( V_5 -> V_82 -> V_2 , V_217 -> V_71 , V_438 ,
& V_432 ) ;
return V_114 ;
}
static void F_249 ( struct V_31 * V_32 )
{
struct V_439 * V_440 = F_6 ( V_32 ,
struct V_439 ,
V_32 ) ;
int V_114 = 0 ;
struct V_138 * V_2 = V_440 -> V_5 -> V_82 -> V_2 ;
if ( V_440 -> V_441 ) {
if ( ! F_250 ( V_2 ) ) {
V_114 = F_251 ( V_2 ) ;
if ( V_114 )
F_18 ( V_440 -> V_5 , L_97 ) ;
}
if ( ! V_114 ) {
V_114 = F_252 ( V_2 , & V_440 -> V_442 ) ;
if ( V_114 )
F_18 ( V_440 -> V_5 , L_98 ,
V_440 -> V_442 . V_443 ,
V_440 -> V_442 . V_444 ,
V_114 ) ;
}
} else if ( F_250 ( V_2 ) ) {
V_114 = F_253 ( V_2 ) ;
if ( V_114 )
F_18 ( V_440 -> V_5 , L_99 ) ;
}
F_254 ( V_440 -> V_5 -> V_2 ) ;
F_29 ( V_440 ) ;
}
static int F_255 ( struct V_4 * V_5 , int V_441 ,
T_1 V_445 , T_1 V_446 )
{
struct V_439 * V_440 = NULL ;
V_440 = F_24 ( sizeof( * V_440 ) , V_90 ) ;
if ( ! V_440 )
return - V_113 ;
F_25 ( & V_440 -> V_32 , F_249 ) ;
V_440 -> V_5 = V_5 ;
V_440 -> V_441 = V_441 ;
V_440 -> V_442 . V_443 = V_445 ;
V_440 -> V_442 . V_444 = V_446 ;
F_256 ( V_5 -> V_2 ) ;
F_37 ( V_5 -> V_82 -> V_115 , & V_440 -> V_32 ) ;
return 0 ;
}
int F_257 ( struct V_447 * V_448 ,
unsigned long V_449 , void * V_450 )
{
struct V_1 * V_451 = F_258 ( V_450 ) ;
T_1 V_64 = 0 ;
struct V_122 * V_82 ;
struct V_138 * V_2 ;
int V_6 , V_452 = 0 ;
bool V_453 = true ;
struct V_4 * V_5 ;
T_1 V_454 = 0 ;
T_1 V_455 = 0 ;
if ( ! F_259 ( F_260 ( V_451 ) , & V_456 ) )
return V_457 ;
V_82 = F_6 ( V_448 , struct V_122 , V_458 ) ;
V_2 = V_82 -> V_2 ;
F_261 (i, dev, MLX4_PORT_TYPE_ETH) {
++ V_452 ;
if ( ! V_64 && ( V_82 -> V_352 [ V_6 ] == V_451 ) )
V_64 = V_6 ;
V_82 -> V_353 [ V_6 ] = V_82 -> V_352 [ V_6 ] ?
F_262 ( V_82 -> V_352 [ V_6 ] ) : NULL ;
if ( ! V_82 -> V_353 [ V_6 ] )
V_453 = false ;
if ( V_452 < 2 )
continue;
if ( V_82 -> V_353 [ V_6 ] != V_82 -> V_353 [ V_6 - 1 ] )
V_453 = false ;
}
V_453 = ( V_452 == 2 ) ? V_453 : false ;
if ( ( V_453 && ( V_449 != V_459 ) ) || ! V_64 )
return V_457 ;
V_5 = F_2 ( V_451 ) ;
if ( V_453 ) {
struct V_460 * V_461 = V_450 ;
struct V_462 * V_463 =
& V_461 -> V_463 ;
if ( ( V_463 -> V_464 . V_465 != V_466 ) &&
( V_463 -> V_464 . V_465 != V_467 ) &&
( V_463 -> V_464 . V_465 != V_468 ) )
V_453 = false ;
if ( V_463 -> V_464 . V_469 != 2 )
V_453 = false ;
if ( V_453 ) {
if ( V_463 -> V_464 . V_465 ==
V_466 ) {
if ( V_463 -> V_470 . V_471 ==
V_472 ) {
if ( V_64 == 1 ) {
V_454 = 2 ;
V_455 = 2 ;
} else {
V_454 = 1 ;
V_455 = 1 ;
}
} else {
if ( V_64 == 1 ) {
V_454 = 1 ;
V_455 = 1 ;
} else {
V_454 = 2 ;
V_455 = 2 ;
}
}
} else {
T_8 V_473 = V_463 -> V_470 . V_473 ;
if ( V_64 == 1 )
V_455 = 2 ;
else
V_454 = 1 ;
if ( ( V_473 == V_474 ) ||
( V_473 == V_475 ) ) {
if ( V_64 == 1 )
V_454 = 1 ;
else
V_455 = 2 ;
} else {
if ( V_64 == 1 )
V_454 = 2 ;
else
V_455 = 1 ;
}
}
}
}
F_255 ( V_5 , V_453 ,
V_454 , V_455 ) ;
return V_457 ;
}
void F_263 ( struct V_138 * V_2 ,
struct V_476 * V_477 ,
T_1 V_319 , T_1 V_318 ,
T_1 V_317 , T_1 V_316 )
{
int V_478 = V_479 + V_480 + V_481 ;
if ( ! F_264 ( V_2 ) &&
( V_2 -> V_130 . V_277 & V_482 ) ) {
F_50 ( & V_477 -> V_483 ) ;
F_265 ( V_477 -> V_484 , V_478 , V_485 ) ;
if ( V_319 )
F_266 ( V_477 -> V_484 , V_478 ,
V_486 ) ;
V_478 += V_486 ;
if ( V_318 && ! ( V_319 ) )
F_266 ( V_477 -> V_484 , V_478 ,
V_487 ) ;
V_478 += V_487 ;
if ( V_317 )
F_266 ( V_477 -> V_484 , V_478 ,
V_488 ) ;
V_478 += V_488 ;
if ( V_316 && ! ( V_317 ) )
F_266 ( V_477 -> V_484 , V_478 ,
V_489 ) ;
V_478 += V_489 ;
F_53 ( & V_477 -> V_483 ) ;
}
}
void F_267 ( struct V_138 * V_2 ,
struct V_476 * V_477 ,
T_1 V_319 , T_1 V_318 ,
T_1 V_317 , T_1 V_316 )
{
int V_478 = 0 ;
F_268 ( & V_477 -> V_483 ) ;
F_269 ( V_477 -> V_484 , V_490 ) ;
if ( F_264 ( V_2 ) ) {
F_266 ( V_477 -> V_484 , V_478 +
F_270 ( V_263 ) , 1 ) ;
F_266 ( V_477 -> V_484 , V_478 +
F_270 ( V_491 ) , 1 ) ;
F_266 ( V_477 -> V_484 , V_478 +
F_270 ( V_264 ) , 1 ) ;
F_266 ( V_477 -> V_484 , V_478 +
F_270 ( V_492 ) , 1 ) ;
F_266 ( V_477 -> V_484 , V_478 +
F_270 ( V_493 ) , 1 ) ;
F_266 ( V_477 -> V_484 , V_478 +
F_270 ( V_494 ) , 1 ) ;
} else {
F_266 ( V_477 -> V_484 , V_478 , V_479 ) ;
}
V_478 += V_479 ;
F_266 ( V_477 -> V_484 , V_478 , V_480 ) ;
V_478 += V_480 ;
if ( F_271 ( V_2 ) )
F_266 ( V_477 -> V_484 , V_478 ,
V_481 ) ;
V_478 += V_481 ;
F_263 ( V_2 , V_477 ,
V_319 , V_318 ,
V_317 , V_316 ) ;
V_478 += V_485 ;
if ( ! F_264 ( V_2 ) )
F_266 ( V_477 -> V_484 , V_478 , V_495 ) ;
}
int F_272 ( struct V_122 * V_82 , int V_64 ,
struct V_342 * V_315 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_6 ;
int V_114 ;
V_2 = F_273 ( sizeof( struct V_4 ) ,
V_496 , V_497 ) ;
if ( V_2 == NULL )
return - V_113 ;
F_274 ( V_2 , V_315 -> V_216 ) ;
F_275 ( V_2 , V_315 -> V_212 ) ;
F_276 ( V_2 , & V_82 -> V_2 -> V_498 -> V_499 -> V_2 ) ;
V_2 -> V_500 = V_64 - 1 ;
V_5 = F_2 ( V_2 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_306 = F_177 ( V_82 -> V_2 ) ;
F_277 ( & V_5 -> V_225 ) ;
F_25 ( & V_5 -> V_186 , F_111 ) ;
F_25 ( & V_5 -> V_223 , F_187 ) ;
F_25 ( & V_5 -> V_280 , F_134 ) ;
F_278 ( & V_5 -> V_272 , F_127 ) ;
F_278 ( & V_5 -> V_276 , F_131 ) ;
#ifdef F_162
F_25 ( & V_5 -> V_417 , F_238 ) ;
F_25 ( & V_5 -> V_425 , F_240 ) ;
#endif
#ifdef F_192
F_62 ( & V_5 -> V_94 ) ;
F_277 ( & V_5 -> V_111 ) ;
#endif
V_5 -> V_2 = V_2 ;
V_5 -> V_82 = V_82 ;
V_5 -> V_501 = & V_82 -> V_499 -> V_2 ;
V_5 -> V_315 = V_315 ;
V_5 -> V_64 = V_64 ;
V_5 -> V_19 = false ;
V_5 -> V_151 = V_315 -> V_151 ;
V_5 -> V_502 = V_503 ;
V_5 -> V_504 = F_279 ( V_505 |
V_506 ) ;
V_5 -> V_10 = V_82 -> V_507 . V_10 ;
V_5 -> V_216 = V_315 -> V_216 ;
V_5 -> V_508 = V_509 ;
F_280 ( V_5 -> V_510 , sizeof( V_5 -> V_510 ) ) ;
V_5 -> V_217 = F_24 ( sizeof( struct V_286 * ) * V_496 ,
V_184 ) ;
if ( ! V_5 -> V_217 ) {
V_114 = - V_113 ;
goto V_112;
}
V_5 -> V_244 = F_24 ( sizeof( struct V_13 * ) * V_496 ,
V_184 ) ;
if ( ! V_5 -> V_244 ) {
V_114 = - V_113 ;
goto V_112;
}
V_5 -> V_212 = V_315 -> V_212 ;
V_5 -> V_302 = ( V_82 -> V_2 -> V_130 . V_301 == 64 ) ? 1 : 0 ;
V_5 -> V_301 = V_82 -> V_2 -> V_130 . V_301 ;
V_5 -> V_511 = - 1 ;
V_5 -> V_512 = V_513 ;
#ifdef F_281
if ( ! F_264 ( V_5 -> V_82 -> V_2 ) ) {
if ( V_82 -> V_2 -> V_130 . V_277 & V_514 ) {
V_2 -> V_515 = & V_516 ;
} else {
F_135 ( V_5 , L_100 ) ;
V_2 -> V_515 = & V_517 ;
}
}
#endif
for ( V_6 = 0 ; V_6 < V_202 ; ++ V_6 )
F_282 ( & V_5 -> V_157 [ V_6 ] ) ;
V_5 -> V_294 = V_82 -> V_2 -> V_130 . V_518 [ V_5 -> V_64 ] ;
if ( V_82 -> V_2 -> V_130 . V_519 [ V_5 -> V_64 ] &
V_520 )
V_5 -> V_151 |= V_521 ;
V_2 -> V_522 = V_78 ;
F_57 ( V_2 -> V_77 , V_82 -> V_2 -> V_130 . V_523 [ V_5 -> V_64 ] ) ;
if ( ! F_82 ( V_2 -> V_77 ) ) {
F_18 ( V_5 , L_101 ,
V_5 -> V_64 , V_2 -> V_77 ) ;
V_114 = - V_9 ;
goto V_112;
} else if ( F_264 ( V_5 -> V_82 -> V_2 ) &&
( V_5 -> V_82 -> V_2 -> V_524 & 1 << V_5 -> V_64 ) ) {
V_2 -> V_525 |= V_526 ;
F_15 ( V_5 , L_102 , V_2 -> V_77 ) ;
}
memcpy ( V_5 -> V_165 , V_2 -> V_77 , sizeof( V_5 -> V_165 ) ) ;
V_5 -> V_341 = F_283 ( sizeof( struct V_527 ) +
V_528 * V_529 ) ;
V_114 = F_196 ( V_5 ) ;
if ( V_114 )
goto V_112;
V_5 -> V_359 . V_151 = 0 ;
V_5 -> V_359 . V_363 = V_364 ;
V_5 -> V_359 . V_367 = V_368 ;
V_114 = F_284 ( V_82 -> V_2 , & V_5 -> V_350 ,
V_351 , V_351 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_103 ) ;
goto V_112;
}
V_5 -> V_349 = 1 ;
if ( F_271 ( V_5 -> V_82 -> V_2 ) )
V_2 -> V_530 = & V_531 ;
else
V_2 -> V_530 = & V_532 ;
V_2 -> V_533 = V_534 ;
F_274 ( V_2 , V_5 -> V_216 ) ;
F_275 ( V_2 , V_5 -> V_212 ) ;
V_2 -> V_535 = & V_536 ;
V_2 -> V_424 = V_537 | V_420 | V_538 ;
if ( V_82 -> V_539 )
V_2 -> V_424 |= V_422 | V_540 ;
V_2 -> V_541 = V_2 -> V_424 ;
V_2 -> V_424 |= V_421 | V_542 ;
V_2 -> V_383 = V_2 -> V_424 | V_543 |
V_397 | V_390 |
V_544 ;
V_2 -> V_424 |= V_399 |
V_397 | V_390 ;
if ( ! ( V_82 -> V_2 -> V_130 . V_277 & V_391 ) ) {
V_2 -> V_383 |= V_392 |
V_545 ;
V_2 -> V_424 |= V_392 ;
}
if ( F_264 ( V_82 -> V_2 ) ) {
int V_546 ;
V_114 = F_285 ( V_82 -> V_2 , V_64 , & V_546 ) ;
if ( ! V_114 && V_546 ) {
V_2 -> V_424 |= V_398 ;
V_5 -> V_502 |= V_547 ;
}
} else {
if ( V_82 -> V_2 -> V_130 . V_277 & V_548 &&
! ( V_82 -> V_2 -> V_130 . V_277 &
V_391 ) )
V_2 -> V_424 |= V_398 ;
}
if ( V_82 -> V_2 -> V_130 . V_151 & V_549 )
V_2 -> V_424 |= V_394 ;
if ( V_82 -> V_2 -> V_130 . V_277 & V_550 )
V_2 -> V_424 |= V_395 ;
if ( V_82 -> V_2 -> V_130 . V_139 ==
V_145 &&
V_82 -> V_2 -> V_130 . V_133 != V_134 )
V_2 -> V_424 |= V_551 ;
if ( V_82 -> V_2 -> V_130 . V_139 != V_149 )
V_2 -> V_209 |= V_210 ;
if ( V_82 -> V_2 -> V_130 . V_277 & V_552 ) {
V_5 -> V_553 = V_554 ;
} else if ( V_82 -> V_2 -> V_130 . V_277 & V_555 ) {
V_5 -> V_553 = V_556 ;
} else {
F_15 ( V_5 ,
L_104 ) ;
V_5 -> V_553 = V_554 ;
}
V_82 -> V_352 [ V_64 ] = V_2 ;
V_82 -> V_353 [ V_64 ] = NULL ;
F_136 ( V_2 ) ;
F_124 ( V_5 ) ;
F_15 ( V_5 , L_105 , V_315 -> V_216 ) ;
F_15 ( V_5 , L_106 , V_315 -> V_212 ) ;
F_222 ( V_5 -> V_2 , V_5 -> V_2 -> V_383 ) ;
F_145 ( V_2 ) ;
V_114 = F_157 ( V_82 -> V_2 , V_5 -> V_64 ,
V_5 -> V_295 + V_314 ,
V_315 -> V_316 , V_315 -> V_317 ,
V_315 -> V_318 , V_315 -> V_319 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_65 ,
V_5 -> V_64 , V_114 ) ;
goto V_112;
}
if ( V_82 -> V_2 -> V_130 . V_131 == V_132 ) {
V_114 = F_158 ( V_82 -> V_2 , V_5 -> V_64 , V_320 , 1 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_67 ,
V_114 ) ;
goto V_112;
}
}
F_15 ( V_5 , L_68 ) ;
V_114 = F_159 ( V_82 -> V_2 , V_5 -> V_64 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_69 ) ;
goto V_112;
}
F_130 ( V_82 -> V_115 , & V_5 -> V_272 , V_273 ) ;
if ( V_82 -> V_2 -> V_130 . V_277 & V_278 )
F_286 ( V_82 ) ;
F_130 ( V_82 -> V_115 , & V_5 -> V_276 ,
V_279 ) ;
F_267 ( V_82 -> V_2 , & V_5 -> V_477 ,
V_82 -> V_507 . V_315 [ V_5 -> V_64 ] . V_319 ,
V_82 -> V_507 . V_315 [ V_5 -> V_64 ] . V_318 ,
V_82 -> V_507 . V_315 [ V_5 -> V_64 ] . V_317 ,
V_82 -> V_507 . V_315 [ V_5 -> V_64 ] . V_316 ) ;
V_114 = F_287 ( V_2 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_107 , V_64 ) ;
goto V_112;
}
V_5 -> V_348 = 1 ;
return 0 ;
V_112:
F_203 ( V_2 ) ;
return V_114 ;
}
int F_214 ( struct V_1 * V_2 ,
struct V_359 V_557 ,
T_6 V_383 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_19 = 0 ;
int V_114 = 0 ;
if ( V_5 -> V_359 . V_363 == V_557 . V_363 &&
V_5 -> V_359 . V_367 == V_557 . V_367 &&
! F_220 ( V_2 , V_383 , V_390 ) &&
! F_220 ( V_2 , V_383 , V_394 ) )
return 0 ;
if ( F_220 ( V_2 , V_383 , V_390 ) &&
( V_383 & V_390 ) &&
( V_5 -> V_359 . V_367 != V_368 ) ) {
F_15 ( V_5 , L_108 ) ;
return - V_9 ;
}
F_50 ( & V_82 -> V_126 ) ;
if ( V_5 -> V_19 ) {
V_19 = 1 ;
F_170 ( V_2 , 1 ) ;
}
F_191 ( V_5 ) ;
F_15 ( V_5 , L_109 ,
V_557 . V_367 , ! ! ( V_383 & V_390 ) ) ;
V_5 -> V_359 . V_363 = V_557 . V_363 ;
V_5 -> V_359 . V_367 = V_557 . V_367 ;
if ( F_220 ( V_2 , V_383 , V_390 ) ) {
if ( V_383 & V_390 )
V_2 -> V_383 |= V_390 ;
else
V_2 -> V_383 &= ~ V_390 ;
} else if ( V_557 . V_367 == V_368 ) {
if ( V_2 -> V_558 & V_390 )
V_2 -> V_383 |= V_390 ;
else
V_2 -> V_383 &= ~ V_390 ;
}
if ( F_220 ( V_2 , V_383 , V_394 ) ) {
if ( V_383 & V_394 )
V_2 -> V_383 |= V_394 ;
else
V_2 -> V_383 &= ~ V_394 ;
}
if ( V_557 . V_367 != V_368 ) {
if ( V_2 -> V_383 & V_390 )
F_15 ( V_5 , L_110 ) ;
V_2 -> V_383 &= ~ V_390 ;
}
V_114 = F_196 ( V_5 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_111 ) ;
goto V_112;
}
if ( V_19 ) {
V_114 = F_143 ( V_2 ) ;
if ( V_114 )
F_18 ( V_5 , L_112 ) ;
}
V_112:
F_53 ( & V_82 -> V_126 ) ;
F_288 ( V_2 ) ;
return V_114 ;
}
