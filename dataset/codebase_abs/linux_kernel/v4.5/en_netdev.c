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
static enum V_11 F_5 ( T_1 V_12 )
{
switch ( V_12 ) {
case V_13 :
return V_14 ;
case V_15 :
return V_16 ;
default:
return V_17 ;
}
}
static void F_6 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_7 ( V_19 ,
struct V_20 ,
V_19 ) ;
struct V_4 * V_5 = V_21 -> V_5 ;
struct V_22 V_23 = {
. V_24 = F_5 ( V_21 -> V_12 ) ,
{
. V_25 = {
. V_26 = V_21 -> V_26 ,
. V_27 = ( V_28 V_29 ) - 1 ,
. V_30 = V_21 -> V_30 ,
. V_31 = ( V_28 V_29 ) - 1 ,
} ,
} ,
} ;
struct V_22 V_32 = {
. V_24 = V_33 ,
{
. V_34 = {
. V_35 = V_21 -> V_35 ,
. V_36 = ( V_28 V_37 ) - 1 ,
. V_38 = V_21 -> V_38 ,
. V_39 = ( V_28 V_37 ) - 1 ,
} ,
} ,
} ;
struct V_22 V_40 = {
. V_24 = V_41 ,
} ;
struct V_42 V_43 = {
. V_44 = F_8 ( V_43 . V_44 ) ,
. V_45 = V_46 ,
. V_47 = 1 ,
. V_48 = 1 ,
. V_49 = V_50 ,
. V_51 = V_5 -> V_51 ,
. V_52 = V_53 ,
} ;
int V_54 ;
T_2 V_55 = F_9 ( V_56 << 16 ) ;
if ( V_23 . V_24 >= V_17 ) {
F_10 ( V_5 , L_1 ,
V_21 -> V_12 ) ;
goto V_57;
}
F_11 ( & V_40 . V_44 , & V_43 . V_44 ) ;
F_11 ( & V_32 . V_44 , & V_43 . V_44 ) ;
F_11 ( & V_23 . V_44 , & V_43 . V_44 ) ;
V_43 . V_58 = V_5 -> V_59 . V_60 [ V_21 -> V_61 ] . V_58 ;
memcpy ( V_40 . V_62 . V_63 , V_5 -> V_2 -> V_64 , V_65 ) ;
memcpy ( V_40 . V_62 . V_66 , & V_55 , V_65 ) ;
V_21 -> V_67 = 0 ;
if ( V_21 -> V_68 ) {
V_54 = F_12 ( V_5 -> V_69 -> V_2 , V_21 -> V_68 ) ;
if ( V_54 && V_54 != - V_70 )
F_13 ( V_5 , L_2 , V_54 ) ;
}
V_54 = F_14 ( V_5 -> V_69 -> V_2 , & V_43 , & V_21 -> V_68 ) ;
if ( V_54 )
F_13 ( V_5 , L_3 , V_54 ) ;
V_57:
F_15 ( V_5 ) ;
V_21 -> V_67 = 1 ;
}
static inline struct V_71 *
F_16 ( struct V_4 * V_5 , V_37 V_38 , V_37 V_35 ,
V_29 V_30 , V_29 V_26 )
{
unsigned long V_72 ;
int V_73 ;
V_72 = ( V_28 unsigned long ) V_30 |
( ( V_28 unsigned long ) V_26 << 2 ) ;
V_72 ^= ( V_28 unsigned long ) ( V_38 ^ V_35 ) ;
V_73 = F_17 ( V_72 , V_74 ) ;
return & V_5 -> V_75 [ V_73 ] ;
}
static struct V_20 *
F_18 ( struct V_4 * V_5 , int V_61 , V_37 V_38 ,
V_37 V_35 , T_1 V_12 , V_29 V_30 ,
V_29 V_26 , T_3 V_76 )
{
struct V_20 * V_21 = NULL ;
V_21 = F_19 ( sizeof( struct V_20 ) , V_77 ) ;
if ( ! V_21 )
return NULL ;
V_21 -> V_5 = V_5 ;
V_21 -> V_61 = V_61 ;
F_20 ( & V_21 -> V_19 , F_6 ) ;
V_21 -> V_38 = V_38 ;
V_21 -> V_35 = V_35 ;
V_21 -> V_12 = V_12 ;
V_21 -> V_30 = V_30 ;
V_21 -> V_26 = V_26 ;
V_21 -> V_76 = V_76 ;
V_21 -> V_24 = V_5 -> V_78 ++ % V_79 ;
F_11 ( & V_21 -> V_80 , & V_5 -> V_81 ) ;
F_21 ( & V_21 -> V_82 ,
F_16 ( V_5 , V_38 , V_35 , V_30 ,
V_26 ) ) ;
return V_21 ;
}
static void F_22 ( struct V_20 * V_21 )
{
struct V_4 * V_5 = V_21 -> V_5 ;
int V_54 ;
F_23 ( & V_21 -> V_80 ) ;
V_54 = F_12 ( V_5 -> V_69 -> V_2 , V_21 -> V_68 ) ;
if ( V_54 && V_54 != - V_70 )
F_13 ( V_5 , L_2 , V_54 ) ;
F_24 ( V_21 ) ;
}
static inline struct V_20 *
F_25 ( struct V_4 * V_5 , V_37 V_38 , V_37 V_35 ,
T_1 V_12 , V_29 V_30 , V_29 V_26 )
{
struct V_20 * V_21 ;
struct V_20 * V_83 = NULL ;
F_26 (filter,
filter_hash_bucket(priv, src_ip, dst_ip,
src_port, dst_port),
filter_chain) {
if ( V_21 -> V_38 == V_38 &&
V_21 -> V_35 == V_35 &&
V_21 -> V_12 == V_12 &&
V_21 -> V_30 == V_30 &&
V_21 -> V_26 == V_26 ) {
V_83 = V_21 ;
break;
}
}
return V_83 ;
}
static int
F_27 ( struct V_1 * V_84 , const struct V_85 * V_86 ,
T_4 V_61 , T_3 V_76 )
{
struct V_4 * V_5 = F_2 ( V_84 ) ;
struct V_20 * V_21 ;
const struct V_87 * V_88 ;
const V_29 * V_89 ;
T_1 V_12 ;
V_37 V_38 ;
V_37 V_35 ;
V_29 V_30 ;
V_29 V_26 ;
int V_90 = F_28 ( V_86 ) ;
int V_83 = 0 ;
if ( V_86 -> V_91 != F_29 ( V_92 ) )
return - V_93 ;
V_88 = ( const struct V_87 * ) ( V_86 -> V_94 + V_90 ) ;
if ( F_30 ( V_88 ) )
return - V_93 ;
if ( ( V_88 -> V_91 != V_15 ) && ( V_88 -> V_91 != V_13 ) )
return - V_93 ;
V_89 = ( const V_29 * ) ( V_86 -> V_94 + V_90 + 4 * V_88 -> V_95 ) ;
V_12 = V_88 -> V_91 ;
V_38 = V_88 -> V_96 ;
V_35 = V_88 -> V_97 ;
V_30 = V_89 [ 0 ] ;
V_26 = V_89 [ 1 ] ;
F_31 ( & V_5 -> V_98 ) ;
V_21 = F_25 ( V_5 , V_38 , V_35 , V_12 ,
V_30 , V_26 ) ;
if ( V_21 ) {
if ( V_21 -> V_61 == V_61 )
goto V_99;
V_21 -> V_61 = V_61 ;
} else {
V_21 = F_18 ( V_5 , V_61 ,
V_38 , V_35 , V_12 ,
V_30 , V_26 , V_76 ) ;
if ( ! V_21 ) {
V_83 = - V_100 ;
goto V_101;
}
}
F_32 ( V_5 -> V_69 -> V_102 , & V_21 -> V_19 ) ;
V_99:
V_83 = V_21 -> V_24 ;
V_101:
F_33 ( & V_5 -> V_98 ) ;
return V_83 ;
}
void F_34 ( struct V_4 * V_5 )
{
struct V_20 * V_21 , * V_103 ;
F_35 ( V_104 ) ;
F_31 ( & V_5 -> V_98 ) ;
F_36 (filter, tmp, &priv->filters, next) {
F_37 ( & V_21 -> V_80 , & V_104 ) ;
F_38 ( & V_21 -> V_82 ) ;
}
F_33 ( & V_5 -> V_98 ) ;
F_36 (filter, tmp, &del_list, next) {
F_39 ( & V_21 -> V_19 ) ;
F_22 ( V_21 ) ;
}
}
static void F_15 ( struct V_4 * V_5 )
{
struct V_20 * V_21 = NULL , * V_103 , * V_105 = NULL ;
F_35 ( V_104 ) ;
int V_6 = 0 ;
F_31 ( & V_5 -> V_98 ) ;
F_36 (filter, tmp, &priv->filters, next) {
if ( V_6 > V_106 )
break;
if ( V_21 -> V_67 &&
! F_40 ( & V_21 -> V_19 ) &&
F_41 ( V_5 -> V_2 ,
V_21 -> V_61 , V_21 -> V_76 ,
V_21 -> V_24 ) ) {
F_37 ( & V_21 -> V_80 , & V_104 ) ;
F_38 ( & V_21 -> V_82 ) ;
} else
V_105 = V_21 ;
V_6 ++ ;
}
if ( V_105 && ( & V_105 -> V_80 != V_5 -> V_81 . V_80 ) )
F_37 ( & V_5 -> V_81 , & V_105 -> V_80 ) ;
F_33 ( & V_5 -> V_98 ) ;
F_36 (filter, tmp, &del_list, next)
F_22 ( V_21 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
V_29 V_107 , T_4 V_108 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
int V_101 ;
int V_110 ;
F_43 ( V_111 , V_5 , L_4 , V_108 ) ;
F_44 ( V_108 , V_5 -> V_112 ) ;
F_45 ( & V_69 -> V_113 ) ;
if ( V_69 -> V_114 && V_5 -> V_115 ) {
V_101 = F_46 ( V_69 -> V_2 , V_5 ) ;
if ( V_101 )
F_13 ( V_5 , L_5 ) ;
}
if ( F_47 ( V_69 -> V_2 , V_5 -> V_51 , V_108 , & V_110 ) )
F_43 ( V_111 , V_5 , L_6 , V_108 ) ;
F_48 ( & V_69 -> V_113 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
V_29 V_107 , T_4 V_108 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
int V_101 ;
F_43 ( V_111 , V_5 , L_7 , V_108 ) ;
F_50 ( V_108 , V_5 -> V_112 ) ;
F_45 ( & V_69 -> V_113 ) ;
F_51 ( V_69 -> V_2 , V_5 -> V_51 , V_108 ) ;
if ( V_69 -> V_114 && V_5 -> V_115 ) {
V_101 = F_46 ( V_69 -> V_2 , V_5 ) ;
if ( V_101 )
F_13 ( V_5 , L_5 ) ;
}
F_48 ( & V_69 -> V_113 ) ;
return 0 ;
}
static void F_52 ( unsigned char V_63 [ V_65 + 2 ] , T_5 V_116 )
{
int V_6 ;
for ( V_6 = V_65 - 1 ; V_6 >= 0 ; -- V_6 ) {
V_63 [ V_6 ] = V_116 & 0xff ;
V_116 >>= 8 ;
}
memset ( & V_63 [ V_65 ] , 0 , 2 ) ;
}
static int F_53 ( struct V_4 * V_5 , unsigned char * V_117 ,
int V_58 , T_5 * V_68 )
{
int V_101 ;
if ( V_5 -> V_69 -> V_2 -> V_118 . V_119 != V_120 ||
V_5 -> V_69 -> V_2 -> V_118 . V_121 == V_122 )
return 0 ;
V_101 = F_54 ( V_5 -> V_69 -> V_2 , V_117 , V_5 -> V_51 , V_58 ,
V_123 , V_68 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_8 , V_101 ) ;
return V_101 ;
}
F_43 ( V_124 , V_5 , L_9 , V_117 , * V_68 ) ;
return 0 ;
}
static int F_55 ( struct V_4 * V_5 ,
unsigned char * V_125 , int * V_58 , T_5 * V_68 )
{
struct V_109 * V_69 = V_5 -> V_69 ;
struct V_126 * V_2 = V_69 -> V_2 ;
int V_101 ;
switch ( V_2 -> V_118 . V_127 ) {
case V_128 : {
struct V_129 V_130 ;
T_1 V_131 [ 16 ] = { 0 } ;
V_130 . V_58 = * V_58 ;
memcpy ( & V_131 [ 10 ] , V_125 , V_65 ) ;
V_131 [ 5 ] = V_5 -> V_51 ;
V_101 = F_56 ( V_2 , & V_130 , V_131 , 0 , V_132 ) ;
break;
}
case V_133 : {
struct V_22 V_40 = { { NULL } } ;
T_2 V_55 = F_9 ( V_56 << 16 ) ;
struct V_42 V_43 = {
. V_45 = V_134 ,
. V_47 = 0 ,
. V_48 = 1 ,
. V_49 = V_50 ,
. V_52 = V_123 ,
} ;
V_43 . V_51 = V_5 -> V_51 ;
V_43 . V_58 = * V_58 ;
F_57 ( & V_43 . V_44 ) ;
V_40 . V_24 = V_41 ;
memcpy ( V_40 . V_62 . V_63 , V_125 , V_65 ) ;
memcpy ( V_40 . V_62 . V_66 , & V_55 , V_65 ) ;
F_11 ( & V_40 . V_44 , & V_43 . V_44 ) ;
V_101 = F_14 ( V_2 , & V_43 , V_68 ) ;
break;
}
default:
return - V_9 ;
}
if ( V_101 )
F_10 ( V_5 , L_10 ) ;
return V_101 ;
}
static void F_58 ( struct V_4 * V_5 ,
unsigned char * V_125 , int V_58 , T_5 V_68 )
{
struct V_109 * V_69 = V_5 -> V_69 ;
struct V_126 * V_2 = V_69 -> V_2 ;
switch ( V_2 -> V_118 . V_127 ) {
case V_128 : {
struct V_129 V_130 ;
T_1 V_131 [ 16 ] = { 0 } ;
V_130 . V_58 = V_58 ;
memcpy ( & V_131 [ 10 ] , V_125 , V_65 ) ;
V_131 [ 5 ] = V_5 -> V_51 ;
F_59 ( V_2 , & V_130 , V_131 , V_132 ) ;
break;
}
case V_133 : {
F_12 ( V_2 , V_68 ) ;
break;
}
default:
F_13 ( V_5 , L_11 ) ;
}
}
static int F_60 ( struct V_4 * V_5 )
{
struct V_109 * V_69 = V_5 -> V_69 ;
struct V_126 * V_2 = V_69 -> V_2 ;
int V_135 = 0 ;
int V_101 = 0 ;
int * V_58 = & V_5 -> V_136 ;
T_5 V_125 = F_61 ( V_5 -> V_2 -> V_64 ) ;
F_43 ( V_124 , V_5 , L_12 ,
V_5 -> V_2 -> V_64 ) ;
V_135 = F_62 ( V_2 , V_5 -> V_51 , V_125 ) ;
if ( V_135 < 0 ) {
V_101 = V_135 ;
F_13 ( V_5 , L_13 ,
V_5 -> V_2 -> V_64 ) ;
return V_101 ;
}
if ( V_2 -> V_118 . V_127 == V_137 ) {
int V_136 = F_63 ( V_2 , V_5 -> V_51 ) ;
* V_58 = V_136 + V_135 ;
return 0 ;
}
V_101 = F_64 ( V_2 , 1 , 1 , V_58 , V_138 ) ;
F_43 ( V_124 , V_5 , L_14 , * V_58 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_15 ) ;
F_65 ( V_2 , V_5 -> V_51 , V_125 ) ;
return V_101 ;
}
return 0 ;
}
static void F_66 ( struct V_4 * V_5 )
{
struct V_109 * V_69 = V_5 -> V_69 ;
struct V_126 * V_2 = V_69 -> V_2 ;
int V_58 = V_5 -> V_136 ;
if ( V_2 -> V_118 . V_127 == V_137 ) {
T_5 V_125 = F_61 ( V_5 -> V_2 -> V_64 ) ;
F_43 ( V_124 , V_5 , L_16 ,
V_5 -> V_2 -> V_64 ) ;
F_65 ( V_2 , V_5 -> V_51 , V_125 ) ;
} else {
F_43 ( V_124 , V_5 , L_17 ,
V_5 -> V_51 , V_58 ) ;
F_67 ( V_2 , V_58 , 1 ) ;
V_5 -> V_139 &= ~ V_140 ;
}
}
static int F_68 ( struct V_4 * V_5 , int V_58 ,
unsigned char * V_141 , unsigned char * V_142 )
{
struct V_109 * V_69 = V_5 -> V_69 ;
struct V_126 * V_2 = V_69 -> V_2 ;
int V_101 = 0 ;
T_5 V_143 = F_61 ( V_141 ) ;
if ( V_2 -> V_118 . V_127 != V_137 ) {
struct V_71 * V_144 ;
unsigned int V_145 ;
struct V_146 * V_147 ;
struct V_148 * V_103 ;
T_5 V_149 = F_61 ( V_142 ) ;
V_144 = & V_5 -> V_145 [ V_142 [ V_150 ] ] ;
F_69 (entry, tmp, bucket, hlist) {
if ( F_70 ( V_147 -> V_125 , V_142 ) ) {
F_58 ( V_5 , V_147 -> V_125 ,
V_58 , V_147 -> V_68 ) ;
F_65 ( V_2 , V_5 -> V_51 ,
V_149 ) ;
F_71 ( & V_147 -> V_151 ) ;
F_72 () ;
memcpy ( V_147 -> V_125 , V_141 , V_65 ) ;
V_147 -> V_68 = 0 ;
V_145 = V_141 [ V_150 ] ;
F_73 ( & V_147 -> V_151 ,
& V_5 -> V_145 [ V_145 ] ) ;
F_62 ( V_2 , V_5 -> V_51 , V_143 ) ;
V_101 = F_55 ( V_5 , V_141 ,
& V_58 ,
& V_147 -> V_68 ) ;
if ( V_101 )
return V_101 ;
if ( V_5 -> V_152 ) {
F_12 ( V_5 -> V_69 -> V_2 , V_5 -> V_152 ) ;
V_5 -> V_152 = 0 ;
}
V_101 = F_53 ( V_5 , V_141 , V_58 ,
& V_5 -> V_152 ) ;
return V_101 ;
}
}
return - V_9 ;
}
return F_74 ( V_2 , V_5 -> V_51 , V_58 , V_143 ) ;
}
static int F_75 ( struct V_4 * V_5 ,
unsigned char V_141 [ V_65 + 2 ] )
{
int V_101 = 0 ;
if ( V_5 -> V_115 ) {
V_101 = F_68 ( V_5 , V_5 -> V_136 ,
V_141 , V_5 -> V_153 ) ;
if ( V_101 )
F_13 ( V_5 , L_18 ) ;
} else
F_43 ( V_111 , V_5 , L_19 ) ;
if ( ! V_101 )
memcpy ( V_5 -> V_153 , V_141 , sizeof( V_5 -> V_153 ) ) ;
return V_101 ;
}
static int F_76 ( struct V_1 * V_2 , void * V_117 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
struct V_154 * V_96 = V_117 ;
unsigned char V_141 [ V_65 + 2 ] ;
int V_101 ;
if ( ! F_77 ( V_96 -> V_155 ) )
return - V_156 ;
F_45 ( & V_69 -> V_113 ) ;
memcpy ( V_141 , V_96 -> V_155 , V_65 ) ;
V_101 = F_75 ( V_5 , V_141 ) ;
if ( ! V_101 )
memcpy ( V_2 -> V_64 , V_96 -> V_155 , V_65 ) ;
F_48 ( & V_69 -> V_113 ) ;
return V_101 ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_157 * V_103 , * V_158 ;
F_36 (mc_to_del, tmp, &priv->mc_list, list) {
F_23 ( & V_158 -> V_44 ) ;
F_24 ( V_158 ) ;
}
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_159 * V_160 ;
struct V_157 * V_103 ;
F_78 ( V_2 ) ;
F_80 (ha, dev) {
V_103 = F_19 ( sizeof( struct V_157 ) , V_77 ) ;
if ( ! V_103 ) {
F_78 ( V_2 ) ;
return;
}
memcpy ( V_103 -> V_117 , V_160 -> V_117 , V_65 ) ;
F_11 ( & V_103 -> V_44 , & V_5 -> V_161 ) ;
}
}
static void F_81 ( struct V_4 * V_5 ,
struct V_162 * V_163 ,
struct V_162 * V_164 )
{
struct V_157 * V_165 , * V_166 , * V_167 ;
bool V_168 ;
F_82 (dst_tmp, dst, list) {
V_168 = false ;
F_82 (src_tmp, src, list) {
if ( F_83 ( V_165 -> V_117 , V_166 -> V_117 ) ) {
V_168 = true ;
break;
}
}
if ( ! V_168 )
V_165 -> V_169 = V_170 ;
}
F_82 (src_tmp, src, list) {
V_168 = false ;
F_82 (dst_tmp, dst, list) {
if ( F_83 ( V_165 -> V_117 , V_166 -> V_117 ) ) {
V_165 -> V_169 = V_171 ;
V_168 = true ;
break;
}
}
if ( ! V_168 ) {
V_167 = F_84 ( V_166 ,
sizeof( struct V_157 ) ,
V_172 ) ;
if ( ! V_167 )
return;
V_167 -> V_169 = V_173 ;
F_11 ( & V_167 -> V_44 , V_163 ) ;
}
}
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_115 )
return;
F_32 ( V_5 -> V_69 -> V_102 , & V_5 -> V_174 ) ;
}
static void F_86 ( struct V_4 * V_5 ,
struct V_109 * V_69 )
{
int V_101 = 0 ;
if ( ! ( V_5 -> V_139 & V_175 ) ) {
if ( F_87 ( V_5 ) )
F_10 ( V_5 , L_20 ) ;
V_5 -> V_139 |= V_175 ;
switch ( V_69 -> V_2 -> V_118 . V_127 ) {
case V_133 :
V_101 = F_88 ( V_69 -> V_2 ,
V_5 -> V_51 ,
V_5 -> V_136 ,
V_176 ) ;
if ( V_101 )
F_13 ( V_5 , L_21 ) ;
V_5 -> V_139 |= V_177 ;
break;
case V_128 :
V_101 = F_89 ( V_69 -> V_2 ,
V_5 -> V_136 ,
V_5 -> V_51 ) ;
if ( V_101 )
F_13 ( V_5 , L_22 ) ;
if ( ! ( V_5 -> V_139 & V_177 ) ) {
V_101 = F_90 ( V_69 -> V_2 ,
V_5 -> V_136 ,
V_5 -> V_51 ) ;
if ( V_101 )
F_13 ( V_5 , L_23 ) ;
V_5 -> V_139 |= V_177 ;
}
break;
case V_137 :
V_101 = F_91 ( V_69 -> V_2 ,
V_5 -> V_51 ,
V_5 -> V_136 ,
1 ) ;
if ( V_101 )
F_13 ( V_5 , L_21 ) ;
break;
}
V_101 = F_92 ( V_69 -> V_2 , V_5 -> V_51 , 0 ,
0 , V_178 ) ;
if ( V_101 )
F_13 ( V_5 , L_24 ) ;
}
}
static void F_93 ( struct V_4 * V_5 ,
struct V_109 * V_69 )
{
int V_101 = 0 ;
if ( F_87 ( V_5 ) )
F_10 ( V_5 , L_25 ) ;
V_5 -> V_139 &= ~ V_175 ;
switch ( V_69 -> V_2 -> V_118 . V_127 ) {
case V_133 :
V_101 = F_94 ( V_69 -> V_2 ,
V_5 -> V_51 ,
V_176 ) ;
if ( V_101 )
F_13 ( V_5 , L_26 ) ;
V_5 -> V_139 &= ~ V_177 ;
break;
case V_128 :
V_101 = F_95 ( V_69 -> V_2 ,
V_5 -> V_136 ,
V_5 -> V_51 ) ;
if ( V_101 )
F_13 ( V_5 , L_27 ) ;
if ( V_5 -> V_139 & V_177 ) {
V_101 = F_96 ( V_69 -> V_2 ,
V_5 -> V_136 ,
V_5 -> V_51 ) ;
if ( V_101 )
F_13 ( V_5 , L_28 ) ;
V_5 -> V_139 &= ~ V_177 ;
}
break;
case V_137 :
V_101 = F_91 ( V_69 -> V_2 ,
V_5 -> V_51 ,
V_5 -> V_136 , 0 ) ;
if ( V_101 )
F_13 ( V_5 , L_26 ) ;
break;
}
}
static void F_97 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_109 * V_69 )
{
struct V_157 * V_179 , * V_103 ;
T_5 V_180 = 0 ;
T_1 V_161 [ 16 ] = { 0 } ;
int V_101 = 0 ;
if ( V_2 -> V_139 & V_181 ) {
V_101 = F_92 ( V_69 -> V_2 , V_5 -> V_51 , 0 ,
0 , V_178 ) ;
if ( V_101 )
F_13 ( V_5 , L_24 ) ;
if ( ! ( V_5 -> V_139 & V_177 ) ) {
switch ( V_69 -> V_2 -> V_118 . V_127 ) {
case V_133 :
V_101 = F_88 ( V_69 -> V_2 ,
V_5 -> V_51 ,
V_5 -> V_136 ,
V_182 ) ;
break;
case V_128 :
V_101 = F_90 ( V_69 -> V_2 ,
V_5 -> V_136 ,
V_5 -> V_51 ) ;
break;
case V_137 :
break;
}
if ( V_101 )
F_13 ( V_5 , L_29 ) ;
V_5 -> V_139 |= V_177 ;
}
} else {
if ( V_5 -> V_139 & V_177 ) {
switch ( V_69 -> V_2 -> V_118 . V_127 ) {
case V_133 :
V_101 = F_94 ( V_69 -> V_2 ,
V_5 -> V_51 ,
V_182 ) ;
break;
case V_128 :
V_101 = F_96 ( V_69 -> V_2 ,
V_5 -> V_136 ,
V_5 -> V_51 ) ;
break;
case V_137 :
break;
}
if ( V_101 )
F_13 ( V_5 , L_28 ) ;
V_5 -> V_139 &= ~ V_177 ;
}
V_101 = F_92 ( V_69 -> V_2 , V_5 -> V_51 , 0 ,
0 , V_178 ) ;
if ( V_101 )
F_13 ( V_5 , L_24 ) ;
F_92 ( V_69 -> V_2 , V_5 -> V_51 , V_183 ,
1 , V_184 ) ;
F_98 ( V_2 ) ;
F_79 ( V_2 ) ;
F_99 ( V_2 ) ;
F_82 (mclist, &priv->mc_list, list) {
V_180 = F_61 ( V_179 -> V_117 ) ;
F_92 ( V_69 -> V_2 , V_5 -> V_51 ,
V_180 , 0 , V_184 ) ;
}
V_101 = F_92 ( V_69 -> V_2 , V_5 -> V_51 , 0 ,
0 , V_185 ) ;
if ( V_101 )
F_13 ( V_5 , L_30 ) ;
F_81 ( V_5 , & V_5 -> V_186 , & V_5 -> V_161 ) ;
F_36 (mclist, tmp, &priv->curr_list, list) {
if ( V_179 -> V_169 == V_170 ) {
memcpy ( & V_161 [ 10 ] , V_179 -> V_117 , V_65 ) ;
V_161 [ 5 ] = V_5 -> V_51 ;
V_101 = F_100 ( V_69 -> V_2 ,
& V_5 -> V_59 . V_187 ,
V_161 ,
V_132 ,
V_179 -> V_68 ) ;
if ( V_101 )
F_13 ( V_5 , L_31 ) ;
if ( V_179 -> V_152 ) {
V_101 = F_12 ( V_5 -> V_69 -> V_2 , V_179 -> V_152 ) ;
if ( V_101 )
F_13 ( V_5 , L_32 ) ;
}
F_23 ( & V_179 -> V_44 ) ;
F_24 ( V_179 ) ;
} else if ( V_179 -> V_169 == V_173 ) {
memcpy ( & V_161 [ 10 ] , V_179 -> V_117 , V_65 ) ;
V_161 [ 5 ] = V_5 -> V_51 ;
V_101 = F_101 ( V_69 -> V_2 ,
& V_5 -> V_59 . V_187 ,
V_161 ,
V_5 -> V_51 , 0 ,
V_132 ,
& V_179 -> V_68 ) ;
if ( V_101 )
F_13 ( V_5 , L_33 ) ;
V_101 = F_53 ( V_5 , & V_161 [ 10 ] , V_5 -> V_136 ,
& V_179 -> V_152 ) ;
if ( V_101 )
F_13 ( V_5 , L_34 ) ;
}
}
}
}
static void F_102 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_109 * V_69 )
{
struct V_159 * V_160 ;
struct V_146 * V_147 ;
struct V_148 * V_103 ;
bool V_168 ;
T_5 V_125 ;
int V_101 = 0 ;
struct V_71 * V_144 ;
unsigned int V_6 ;
int V_188 = 0 ;
T_3 V_189 ;
for ( V_6 = 0 ; V_6 < V_190 ; ++ V_6 ) {
V_144 = & V_5 -> V_145 [ V_6 ] ;
F_69 (entry, tmp, bucket, hlist) {
V_168 = false ;
F_103 (ha, dev) {
if ( F_70 ( V_147 -> V_125 ,
V_160 -> V_117 ) ) {
V_168 = true ;
break;
}
}
if ( F_70 ( V_147 -> V_125 ,
V_5 -> V_153 ) )
V_168 = true ;
if ( ! V_168 ) {
V_125 = F_61 ( V_147 -> V_125 ) ;
F_58 ( V_5 , V_147 -> V_125 ,
V_5 -> V_136 ,
V_147 -> V_68 ) ;
F_65 ( V_69 -> V_2 , V_5 -> V_51 , V_125 ) ;
F_71 ( & V_147 -> V_151 ) ;
F_104 ( V_147 , V_191 ) ;
F_43 ( V_124 , V_5 , L_35 ,
V_147 -> V_125 , V_5 -> V_51 ) ;
++ V_188 ;
}
}
}
if ( ( V_5 -> V_139 & V_140 ) && 0 == V_188 )
return;
V_189 = V_5 -> V_139 ;
V_5 -> V_139 &= ~ V_140 ;
F_103 (ha, dev) {
V_168 = false ;
V_144 = & V_5 -> V_145 [ V_160 -> V_117 [ V_150 ] ] ;
F_26 (entry, bucket, hlist) {
if ( F_70 ( V_147 -> V_125 , V_160 -> V_117 ) ) {
V_168 = true ;
break;
}
}
if ( ! V_168 ) {
V_147 = F_105 ( sizeof( * V_147 ) , V_172 ) ;
if ( ! V_147 ) {
F_13 ( V_5 , L_36 ,
V_160 -> V_117 , V_5 -> V_51 ) ;
V_5 -> V_139 |= V_140 ;
break;
}
V_125 = F_61 ( V_160 -> V_117 ) ;
memcpy ( V_147 -> V_125 , V_160 -> V_117 , V_65 ) ;
V_101 = F_62 ( V_69 -> V_2 , V_5 -> V_51 , V_125 ) ;
if ( V_101 < 0 ) {
F_13 ( V_5 , L_37 ,
V_160 -> V_117 , V_5 -> V_51 , V_101 ) ;
F_24 ( V_147 ) ;
V_5 -> V_139 |= V_140 ;
break;
}
V_101 = F_55 ( V_5 , V_160 -> V_117 ,
& V_5 -> V_136 ,
& V_147 -> V_68 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_38 ,
V_160 -> V_117 , V_5 -> V_51 , V_101 ) ;
F_65 ( V_69 -> V_2 , V_5 -> V_51 , V_125 ) ;
F_24 ( V_147 ) ;
V_5 -> V_139 |= V_140 ;
break;
} else {
unsigned int V_145 ;
F_43 ( V_124 , V_5 , L_39 ,
V_160 -> V_117 , V_5 -> V_51 ) ;
V_145 = V_160 -> V_117 [ V_150 ] ;
V_144 = & V_5 -> V_145 [ V_145 ] ;
F_73 ( & V_147 -> V_151 , V_144 ) ;
}
}
}
if ( V_5 -> V_139 & V_140 ) {
F_10 ( V_5 , L_40 ,
V_5 -> V_51 ) ;
} else if ( V_189 & V_140 ) {
F_10 ( V_5 , L_41 ,
V_5 -> V_51 ) ;
}
}
static void F_106 ( struct V_18 * V_19 )
{
struct V_4 * V_5 = F_7 ( V_19 , struct V_4 ,
V_174 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_45 ( & V_69 -> V_113 ) ;
if ( ! V_69 -> V_114 ) {
F_43 ( V_111 , V_5 , L_42 ) ;
goto V_99;
}
if ( ! V_5 -> V_115 ) {
F_43 ( V_111 , V_5 , L_43 ) ;
goto V_99;
}
if ( ! F_107 ( V_2 ) ) {
if ( ! F_108 ( V_69 , V_5 -> V_51 ) ) {
if ( V_5 -> V_192 . V_193 ) {
V_5 -> V_194 = V_195 ;
F_109 ( V_2 ) ;
F_43 ( V_196 , V_5 , L_44 ) ;
}
}
}
if ( V_2 -> V_197 & V_198 )
F_102 ( V_5 , V_2 , V_69 ) ;
if ( ( V_2 -> V_139 & V_199 ) ||
( V_5 -> V_139 & V_140 ) ) {
F_86 ( V_5 , V_69 ) ;
goto V_99;
}
if ( V_5 -> V_139 & V_175 )
F_93 ( V_5 , V_69 ) ;
F_97 ( V_5 , V_2 , V_69 ) ;
V_99:
F_48 ( & V_69 -> V_113 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_200 * V_201 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ ) {
V_201 = V_5 -> V_203 [ V_6 ] ;
F_111 ( & V_201 -> V_204 ) ;
}
}
static int F_112 ( struct V_4 * V_5 )
{
T_5 V_68 ;
int V_101 = 0 ;
int * V_58 = & V_5 -> V_136 ;
struct V_146 * V_147 ;
V_101 = F_55 ( V_5 , V_5 -> V_2 -> V_64 , V_58 , & V_68 ) ;
if ( V_101 )
return V_101 ;
V_101 = F_53 ( V_5 , V_5 -> V_2 -> V_64 , * V_58 ,
& V_5 -> V_152 ) ;
if ( V_101 )
goto V_205;
V_147 = F_105 ( sizeof( * V_147 ) , V_172 ) ;
if ( ! V_147 ) {
V_101 = - V_100 ;
goto V_206;
}
memcpy ( V_147 -> V_125 , V_5 -> V_2 -> V_64 , sizeof( V_147 -> V_125 ) ) ;
memcpy ( V_5 -> V_153 , V_147 -> V_125 , sizeof( V_5 -> V_153 ) ) ;
V_147 -> V_68 = V_68 ;
F_73 ( & V_147 -> V_151 ,
& V_5 -> V_145 [ V_147 -> V_125 [ V_150 ] ] ) ;
return 0 ;
V_206:
if ( V_5 -> V_152 )
F_12 ( V_5 -> V_69 -> V_2 , V_5 -> V_152 ) ;
V_205:
F_58 ( V_5 , V_5 -> V_2 -> V_64 , * V_58 , V_68 ) ;
return V_101 ;
}
static void F_113 ( struct V_4 * V_5 )
{
T_5 V_125 ;
unsigned int V_6 ;
int V_58 = V_5 -> V_136 ;
struct V_71 * V_144 ;
struct V_148 * V_103 ;
struct V_146 * V_147 ;
for ( V_6 = 0 ; V_6 < V_190 ; ++ V_6 ) {
V_144 = & V_5 -> V_145 [ V_6 ] ;
F_69 (entry, tmp, bucket, hlist) {
V_125 = F_61 ( V_147 -> V_125 ) ;
F_43 ( V_124 , V_5 , L_45 ,
V_147 -> V_125 ) ;
F_58 ( V_5 , V_147 -> V_125 ,
V_58 , V_147 -> V_68 ) ;
F_65 ( V_5 -> V_69 -> V_2 , V_5 -> V_51 , V_125 ) ;
F_71 ( & V_147 -> V_151 ) ;
F_104 ( V_147 , V_191 ) ;
}
}
if ( V_5 -> V_152 ) {
F_12 ( V_5 -> V_69 -> V_2 , V_5 -> V_152 ) ;
V_5 -> V_152 = 0 ;
}
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
int V_6 ;
if ( F_115 ( V_5 ) )
F_10 ( V_5 , L_46 , V_5 -> V_51 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
if ( ! F_116 ( F_117 ( V_2 , V_6 ) ) )
continue;
F_10 ( V_5 , L_47 ,
V_6 , V_5 -> V_208 [ V_6 ] -> V_58 , V_5 -> V_208 [ V_6 ] -> V_209 ,
V_5 -> V_208 [ V_6 ] -> V_210 , V_5 -> V_208 [ V_6 ] -> V_211 ) ;
}
V_5 -> V_212 . V_213 ++ ;
F_43 ( V_124 , V_5 , L_48 ) ;
F_32 ( V_69 -> V_102 , & V_5 -> V_214 ) ;
}
static struct V_215 * F_118 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_31 ( & V_5 -> V_216 ) ;
memcpy ( & V_5 -> V_217 , & V_5 -> V_218 , sizeof( V_5 -> V_218 ) ) ;
F_33 ( & V_5 -> V_216 ) ;
return & V_5 -> V_217 ;
}
static void F_119 ( struct V_4 * V_5 )
{
struct V_200 * V_201 ;
int V_6 ;
V_5 -> V_219 = V_220 ;
V_5 -> V_221 = V_222 ;
V_5 -> V_223 = V_224 ;
V_5 -> V_225 = V_226 ;
F_43 ( V_227 , V_5 , L_49 ,
V_5 -> V_2 -> V_228 , V_5 -> V_219 , V_5 -> V_221 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ ) {
V_201 = V_5 -> V_203 [ V_6 ] ;
V_201 -> V_229 = V_5 -> V_219 ;
V_201 -> V_230 = V_5 -> V_221 ;
V_5 -> V_231 [ V_6 ] = V_232 ;
V_5 -> V_233 [ V_6 ] = 0 ;
V_5 -> V_234 [ V_6 ] = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
V_201 = V_5 -> V_235 [ V_6 ] ;
V_201 -> V_229 = V_5 -> V_223 ;
V_201 -> V_230 = V_5 -> V_225 ;
}
V_5 -> V_236 = V_237 ;
V_5 -> V_238 = V_239 ;
V_5 -> V_240 = V_241 ;
V_5 -> V_242 = V_243 ;
V_5 -> V_244 = V_245 ;
V_5 -> V_246 = 1 ;
V_5 -> V_247 = 0 ;
V_5 -> V_248 = 0 ;
}
static void F_120 ( struct V_4 * V_5 )
{
unsigned long V_249 = ( unsigned long ) ( V_250 - V_5 -> V_247 ) ;
struct V_200 * V_201 ;
unsigned long V_251 ;
unsigned long V_252 ;
unsigned long V_253 ;
unsigned long V_254 ;
unsigned long V_255 ;
unsigned long V_256 ;
int V_230 ;
int V_257 , V_101 ;
if ( ! V_5 -> V_246 || V_249 < V_5 -> V_244 * V_258 )
return;
for ( V_257 = 0 ; V_257 < V_5 -> V_202 ; V_257 ++ ) {
F_31 ( & V_5 -> V_216 ) ;
V_254 = V_5 -> V_259 [ V_257 ] -> V_251 ;
V_255 = V_5 -> V_259 [ V_257 ] -> V_260 ;
F_33 ( & V_5 -> V_216 ) ;
V_256 = ( ( unsigned long ) ( V_254 -
V_5 -> V_233 [ V_257 ] ) ) ;
V_251 = V_256 ;
V_252 = V_251 * V_258 / V_249 ;
V_253 = V_251 ? ( ( unsigned long ) ( V_255 -
V_5 -> V_234 [ V_257 ] ) ) / V_251 : 0 ;
if ( V_252 > ( V_261 / V_5 -> V_202 ) &&
V_253 > V_262 ) {
if ( V_252 < V_5 -> V_236 )
V_230 = V_5 -> V_238 ;
else if ( V_252 > V_5 -> V_240 )
V_230 = V_5 -> V_242 ;
else
V_230 = ( V_252 - V_5 -> V_236 ) *
( V_5 -> V_242 - V_5 -> V_238 ) /
( V_5 -> V_240 - V_5 -> V_236 ) +
V_5 -> V_238 ;
} else {
V_230 = V_5 -> V_238 ;
}
if ( V_230 != V_5 -> V_231 [ V_257 ] ) {
V_5 -> V_231 [ V_257 ] = V_230 ;
V_201 = V_5 -> V_203 [ V_257 ] ;
V_201 -> V_230 = V_230 ;
V_201 -> V_229 = V_5 -> V_219 ;
V_101 = F_121 ( V_5 , V_201 ) ;
if ( V_101 )
F_13 ( V_5 , L_50 ,
V_257 ) ;
}
V_5 -> V_233 [ V_257 ] = V_254 ;
V_5 -> V_234 [ V_257 ] = V_255 ;
}
V_5 -> V_247 = V_250 ;
}
static void F_122 ( struct V_18 * V_19 )
{
struct V_263 * V_264 = F_123 ( V_19 ) ;
struct V_4 * V_5 = F_7 ( V_264 , struct V_4 ,
V_265 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
int V_101 ;
F_45 ( & V_69 -> V_113 ) ;
if ( V_69 -> V_114 ) {
if ( V_5 -> V_115 ) {
V_101 = F_124 ( V_69 , V_5 -> V_51 , 0 ) ;
if ( V_101 )
F_43 ( V_111 , V_5 , L_51 ) ;
F_120 ( V_5 ) ;
}
F_125 ( V_69 -> V_102 , & V_5 -> V_265 , V_266 ) ;
}
if ( V_69 -> V_267 [ V_268 + 1 - V_5 -> V_51 ] ) {
F_75 ( V_5 , V_5 -> V_153 ) ;
V_69 -> V_267 [ V_268 + 1 - V_5 -> V_51 ] = 0 ;
}
F_48 ( & V_69 -> V_113 ) ;
}
static void F_126 ( struct V_18 * V_19 )
{
struct V_263 * V_264 = F_123 ( V_19 ) ;
struct V_4 * V_5 = F_7 ( V_264 , struct V_4 ,
V_269 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
F_45 ( & V_69 -> V_113 ) ;
if ( V_69 -> V_114 ) {
if ( V_69 -> V_2 -> V_118 . V_270 & V_271 )
F_127 ( V_69 ) ;
F_128 ( V_5 ) ;
F_125 ( V_69 -> V_102 , & V_5 -> V_269 ,
V_272 ) ;
}
F_48 ( & V_69 -> V_113 ) ;
}
static void F_129 ( struct V_18 * V_19 )
{
struct V_4 * V_5 = F_7 ( V_19 , struct V_4 ,
V_273 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
int V_274 = V_5 -> V_193 ;
F_45 ( & V_69 -> V_113 ) ;
if ( V_5 -> V_194 != V_274 ) {
if ( V_274 == V_275 ) {
F_130 ( V_5 , L_52 ) ;
F_131 ( V_5 -> V_2 ) ;
} else {
F_130 ( V_5 , L_44 ) ;
F_109 ( V_5 -> V_2 ) ;
}
}
V_5 -> V_194 = V_274 ;
F_48 ( & V_69 -> V_113 ) ;
}
static int F_132 ( struct V_4 * V_5 , int V_276 )
{
struct V_277 * V_257 = V_5 -> V_259 [ V_276 ] ;
int V_278 = V_5 -> V_69 -> V_2 -> V_278 ;
if ( ! F_133 ( & V_257 -> V_279 , V_172 ) )
return - V_100 ;
F_134 ( F_135 ( V_276 , V_278 ) ,
V_257 -> V_279 ) ;
return 0 ;
}
static void F_136 ( struct V_4 * V_5 , int V_276 )
{
F_137 ( V_5 -> V_259 [ V_276 ] -> V_279 ) ;
}
int F_138 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
struct V_200 * V_201 ;
struct V_280 * V_208 ;
int V_281 = 0 ;
int V_282 = 0 ;
int V_101 = 0 ;
int V_6 ;
int V_283 ;
T_1 V_161 [ 16 ] = { 0 } ;
if ( V_5 -> V_115 ) {
F_43 ( V_124 , V_5 , L_53 ) ;
return 0 ;
}
F_57 ( & V_5 -> V_161 ) ;
F_57 ( & V_5 -> V_186 ) ;
F_57 ( & V_5 -> V_284 ) ;
memset ( & V_5 -> V_285 [ 0 ] , 0 ,
sizeof( struct V_286 ) * V_287 ) ;
V_2 -> V_228 = F_139 ( V_2 -> V_228 , V_5 -> V_288 ) ;
F_140 ( V_2 ) ;
F_43 ( V_124 , V_5 , L_54 , V_5 -> V_289 ) ;
V_101 = F_141 ( V_5 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_55 ) ;
return V_101 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ ) {
V_201 = V_5 -> V_203 [ V_6 ] ;
V_101 = F_132 ( V_5 , V_6 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_56 ) ;
goto V_290;
}
V_101 = F_142 ( V_5 , V_201 , V_6 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_57 ) ;
F_136 ( V_5 , V_6 ) ;
goto V_290;
}
for ( V_283 = 0 ; V_283 < V_201 -> V_291 ; V_283 ++ ) {
struct V_292 * V_293 = NULL ;
V_293 = F_143 ( V_201 -> V_294 , V_283 , V_5 -> V_295 ) +
V_5 -> V_296 ;
V_293 -> V_297 = V_298 ;
}
V_101 = F_121 ( V_5 , V_201 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_58 ) ;
F_144 ( V_5 , V_201 ) ;
F_136 ( V_5 , V_6 ) ;
goto V_290;
}
F_145 ( V_5 , V_201 ) ;
V_5 -> V_259 [ V_6 ] -> V_209 = V_201 -> V_299 . V_209 ;
++ V_281 ;
}
F_43 ( V_124 , V_5 , L_59 , V_5 -> V_51 ) ;
V_101 = F_60 ( V_5 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_60 ) ;
goto V_290;
}
V_69 -> V_267 [ V_5 -> V_51 ] = 0 ;
V_5 -> V_300 =
F_146 ( V_69 -> V_2 , V_5 -> V_51 ) ;
V_101 = F_147 ( V_5 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_61 ) ;
goto V_301;
}
V_101 = F_148 ( V_5 ) ;
if ( V_101 )
goto V_302;
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
V_201 = V_5 -> V_235 [ V_6 ] ;
V_101 = F_142 ( V_5 , V_201 , V_6 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_62 ) ;
goto V_303;
}
V_101 = F_121 ( V_5 , V_201 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_58 ) ;
F_144 ( V_5 , V_201 ) ;
goto V_303;
}
F_43 ( V_124 , V_5 , L_63 , V_6 ) ;
V_201 -> V_294 -> V_304 = F_149 ( 0xffff ) ;
V_208 = V_5 -> V_208 [ V_6 ] ;
V_101 = F_150 ( V_5 , V_208 , V_201 -> V_299 . V_209 ,
V_6 / V_5 -> V_10 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_64 ) ;
F_144 ( V_5 , V_201 ) ;
goto V_303;
}
V_208 -> V_305 = F_117 ( V_2 , V_6 ) ;
F_145 ( V_5 , V_201 ) ;
for ( V_283 = 0 ; V_283 < V_208 -> V_306 ; V_283 += V_307 )
* ( ( T_3 * ) ( V_208 -> V_294 + V_283 ) ) = 0xffffffff ;
++ V_282 ;
}
V_101 = F_151 ( V_69 -> V_2 , V_5 -> V_51 ,
V_5 -> V_289 + V_308 ,
V_5 -> V_309 -> V_310 ,
V_5 -> V_309 -> V_311 ,
V_5 -> V_309 -> V_312 ,
V_5 -> V_309 -> V_313 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_65 ,
V_5 -> V_51 , V_101 ) ;
goto V_303;
}
V_101 = F_91 ( V_69 -> V_2 , V_5 -> V_51 , V_5 -> V_136 , 0 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_66 ) ;
goto V_303;
}
if ( V_69 -> V_2 -> V_118 . V_119 == V_120 ) {
V_101 = F_152 ( V_69 -> V_2 , V_5 -> V_51 , V_314 , 1 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_67 ,
V_101 ) ;
goto V_303;
}
}
F_43 ( V_111 , V_5 , L_68 ) ;
V_101 = F_153 ( V_69 -> V_2 , V_5 -> V_51 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_69 ) ;
goto V_303;
}
if ( V_69 -> V_2 -> V_118 . V_127 != V_137 &&
F_112 ( V_5 ) )
F_154 ( V_69 , L_70 ) ;
F_155 ( & V_161 [ 10 ] ) ;
V_161 [ 5 ] = V_5 -> V_51 ;
if ( F_101 ( V_69 -> V_2 , & V_5 -> V_59 . V_187 , V_161 ,
V_5 -> V_51 , 0 , V_132 ,
& V_5 -> V_315 ) )
F_154 ( V_69 , L_71 ) ;
V_5 -> V_139 &= ~ ( V_175 | V_177 ) ;
F_32 ( V_69 -> V_102 , & V_5 -> V_174 ) ;
#ifdef F_156
if ( V_5 -> V_69 -> V_2 -> V_118 . V_119 == V_120 )
F_157 ( V_2 ) ;
#endif
V_5 -> V_115 = true ;
F_158 ( V_2 ) ;
F_159 ( V_2 ) ;
return 0 ;
V_303:
while ( V_282 -- ) {
F_160 ( V_5 , V_5 -> V_208 [ V_282 ] ) ;
F_144 ( V_5 , V_5 -> V_235 [ V_282 ] ) ;
}
F_161 ( V_5 ) ;
V_302:
F_162 ( V_5 ) ;
V_301:
F_66 ( V_5 ) ;
V_290:
while ( V_281 -- ) {
F_144 ( V_5 , V_5 -> V_203 [ V_281 ] ) ;
F_136 ( V_5 , V_281 ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ )
F_163 ( V_5 , V_5 -> V_259 [ V_6 ] ) ;
return V_101 ;
}
void F_164 ( struct V_1 * V_2 , int V_316 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
struct V_157 * V_179 , * V_103 ;
struct V_286 * V_317 , * V_318 ;
int V_6 ;
T_1 V_161 [ 16 ] = { 0 } ;
if ( ! V_5 -> V_115 ) {
F_43 ( V_124 , V_5 , L_72 ) ;
return;
}
F_165 ( V_69 -> V_2 , V_5 -> V_51 ) ;
F_166 ( V_2 ) ;
if ( V_316 )
F_167 ( V_2 ) ;
F_168 ( V_2 ) ;
F_169 ( V_2 ) ;
F_170 ( V_2 ) ;
V_5 -> V_115 = false ;
V_5 -> V_300 = F_171 ( V_69 -> V_2 ) ;
if ( V_69 -> V_2 -> V_118 . V_127 ==
V_133 ) {
V_5 -> V_139 &= ~ ( V_175 |
V_177 ) ;
F_94 ( V_69 -> V_2 ,
V_5 -> V_51 ,
V_176 ) ;
F_94 ( V_69 -> V_2 ,
V_5 -> V_51 ,
V_182 ) ;
} else if ( V_5 -> V_139 & V_175 ) {
V_5 -> V_139 &= ~ V_175 ;
F_95 ( V_69 -> V_2 , V_5 -> V_136 ,
V_5 -> V_51 ) ;
if ( V_5 -> V_139 & V_177 ) {
F_96 ( V_69 -> V_2 , V_5 -> V_136 ,
V_5 -> V_51 ) ;
V_5 -> V_139 &= ~ V_177 ;
}
}
F_155 ( & V_161 [ 10 ] ) ;
V_161 [ 5 ] = V_5 -> V_51 ;
F_100 ( V_69 -> V_2 , & V_5 -> V_59 . V_187 , V_161 ,
V_132 , V_5 -> V_315 ) ;
F_82 (mclist, &priv->curr_list, list) {
memcpy ( & V_161 [ 10 ] , V_179 -> V_117 , V_65 ) ;
V_161 [ 5 ] = V_5 -> V_51 ;
F_100 ( V_69 -> V_2 , & V_5 -> V_59 . V_187 ,
V_161 , V_132 , V_179 -> V_68 ) ;
if ( V_179 -> V_152 )
F_12 ( V_69 -> V_2 , V_179 -> V_152 ) ;
}
F_78 ( V_2 ) ;
F_36 (mclist, tmp, &priv->curr_list, list) {
F_23 ( & V_179 -> V_44 ) ;
F_24 ( V_179 ) ;
}
F_92 ( V_69 -> V_2 , V_5 -> V_51 , 0 , 1 , V_184 ) ;
if ( V_69 -> V_2 -> V_118 . V_127 ==
V_133 ) {
F_172 () ;
F_36 (flow, tmp_flow,
&priv->ethtool_list, list) {
F_12 ( V_69 -> V_2 , V_317 -> V_24 ) ;
F_23 ( & V_317 -> V_44 ) ;
}
}
F_161 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
F_160 ( V_5 , V_5 -> V_208 [ V_6 ] ) ;
F_144 ( V_5 , V_5 -> V_235 [ V_6 ] ) ;
}
F_173 ( 10 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ )
F_174 ( V_2 , V_5 -> V_208 [ V_6 ] ) ;
if ( V_69 -> V_2 -> V_118 . V_127 != V_137 )
F_113 ( V_5 ) ;
F_162 ( V_5 ) ;
F_66 ( V_5 ) ;
if ( ! ( V_69 -> V_2 -> V_118 . V_270 & V_319 ) )
V_69 -> V_267 [ V_5 -> V_51 ] = 1 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ ) {
struct V_200 * V_201 = V_5 -> V_203 [ V_6 ] ;
F_175 ( & V_201 -> V_204 ) ;
F_163 ( V_5 , V_5 -> V_259 [ V_6 ] ) ;
F_144 ( V_5 , V_201 ) ;
F_136 ( V_5 , V_6 ) ;
}
}
static void F_176 ( struct V_18 * V_19 )
{
struct V_4 * V_5 = F_7 ( V_19 , struct V_4 ,
V_214 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_43 ( V_124 , V_5 , L_73 , V_5 -> V_51 ) ;
F_45 ( & V_69 -> V_113 ) ;
if ( V_5 -> V_115 ) {
F_164 ( V_2 , 1 ) ;
if ( F_138 ( V_2 ) )
F_13 ( V_5 , L_74 , V_5 -> V_51 ) ;
}
F_48 ( & V_69 -> V_113 ) ;
}
static void F_177 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
int V_6 ;
if ( F_124 ( V_69 , V_5 -> V_51 , 1 ) )
F_43 ( V_111 , V_5 , L_75 ) ;
memset ( & V_5 -> V_218 , 0 , sizeof( V_5 -> V_218 ) ) ;
memset ( & V_5 -> V_320 , 0 , sizeof( V_5 -> V_320 ) ) ;
memset ( & V_5 -> V_321 , 0 , sizeof( V_5 -> V_321 ) ) ;
memset ( & V_5 -> V_212 , 0 , sizeof( V_5 -> V_212 ) ) ;
memset ( & V_5 -> V_322 , 0 , sizeof( V_5 -> V_322 ) ) ;
memset ( & V_5 -> V_323 , 0 , sizeof( V_5 -> V_323 ) ) ;
memset ( & V_5 -> V_324 , 0 ,
sizeof( V_5 -> V_324 ) ) ;
memset ( & V_5 -> V_325 , 0 ,
sizeof( V_5 -> V_325 ) ) ;
memset ( & V_5 -> V_326 , 0 , sizeof( V_5 -> V_326 ) ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
V_5 -> V_208 [ V_6 ] -> V_260 = 0 ;
V_5 -> V_208 [ V_6 ] -> V_251 = 0 ;
V_5 -> V_208 [ V_6 ] -> V_327 = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ ) {
V_5 -> V_259 [ V_6 ] -> V_260 = 0 ;
V_5 -> V_259 [ V_6 ] -> V_251 = 0 ;
V_5 -> V_259 [ V_6 ] -> V_328 = 0 ;
V_5 -> V_259 [ V_6 ] -> V_329 = 0 ;
V_5 -> V_259 [ V_6 ] -> V_330 = 0 ;
}
}
static int F_178 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
int V_101 = 0 ;
F_45 ( & V_69 -> V_113 ) ;
if ( ! V_69 -> V_114 ) {
F_13 ( V_5 , L_76 ) ;
V_101 = - V_331 ;
goto V_99;
}
F_177 ( V_2 ) ;
V_101 = F_138 ( V_2 ) ;
if ( V_101 )
F_13 ( V_5 , L_77 , V_5 -> V_51 ) ;
V_99:
F_48 ( & V_69 -> V_113 ) ;
return V_101 ;
}
static int F_179 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
F_43 ( V_332 , V_5 , L_78 ) ;
F_45 ( & V_69 -> V_113 ) ;
F_164 ( V_2 , 0 ) ;
F_131 ( V_2 ) ;
F_48 ( & V_69 -> V_113 ) ;
return 0 ;
}
void F_180 ( struct V_4 * V_5 )
{
int V_6 ;
#ifdef F_181
V_5 -> V_2 -> V_333 = NULL ;
#endif
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
if ( V_5 -> V_208 && V_5 -> V_208 [ V_6 ] )
F_182 ( V_5 , & V_5 -> V_208 [ V_6 ] ) ;
if ( V_5 -> V_235 && V_5 -> V_235 [ V_6 ] )
F_183 ( V_5 , & V_5 -> V_235 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ ) {
if ( V_5 -> V_259 [ V_6 ] )
F_184 ( V_5 , & V_5 -> V_259 [ V_6 ] ,
V_5 -> V_309 -> V_334 , V_5 -> V_335 ) ;
if ( V_5 -> V_203 [ V_6 ] )
F_183 ( V_5 , & V_5 -> V_203 [ V_6 ] ) ;
}
}
int F_185 ( struct V_4 * V_5 )
{
struct V_336 * V_309 = V_5 -> V_309 ;
int V_6 ;
int V_337 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
V_337 = F_186 ( V_6 % F_187 () ) ;
if ( F_188 ( V_5 , & V_5 -> V_235 [ V_6 ] ,
V_309 -> V_338 , V_6 , V_339 , V_337 ) )
goto V_101;
if ( F_189 ( V_5 , & V_5 -> V_208 [ V_6 ] ,
V_309 -> V_338 , V_340 ,
V_337 , V_6 ) )
goto V_101;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ ) {
V_337 = F_186 ( V_6 % F_187 () ) ;
if ( F_188 ( V_5 , & V_5 -> V_203 [ V_6 ] ,
V_309 -> V_334 , V_6 , V_341 , V_337 ) )
goto V_101;
if ( F_190 ( V_5 , & V_5 -> V_259 [ V_6 ] ,
V_309 -> V_334 , V_5 -> V_335 ,
V_337 ) )
goto V_101;
}
#ifdef F_181
V_5 -> V_2 -> V_333 = F_191 ( V_5 -> V_69 -> V_2 , V_5 -> V_51 ) ;
#endif
return 0 ;
V_101:
F_13 ( V_5 , L_79 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ ) {
if ( V_5 -> V_259 [ V_6 ] )
F_184 ( V_5 , & V_5 -> V_259 [ V_6 ] ,
V_309 -> V_334 ,
V_5 -> V_335 ) ;
if ( V_5 -> V_203 [ V_6 ] )
F_183 ( V_5 , & V_5 -> V_203 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
if ( V_5 -> V_208 [ V_6 ] )
F_182 ( V_5 , & V_5 -> V_208 [ V_6 ] ) ;
if ( V_5 -> V_235 [ V_6 ] )
F_183 ( V_5 , & V_5 -> V_235 [ V_6 ] ) ;
}
return - V_100 ;
}
void F_192 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
F_43 ( V_124 , V_5 , L_80 , V_5 -> V_51 ) ;
if ( V_5 -> V_342 )
F_193 ( V_2 ) ;
if ( V_5 -> V_343 )
F_194 ( V_69 -> V_2 , & V_5 -> V_344 , V_345 ) ;
F_195 ( & V_5 -> V_265 ) ;
F_195 ( & V_5 -> V_269 ) ;
F_196 ( V_69 -> V_102 ) ;
if ( V_69 -> V_2 -> V_118 . V_270 & V_271 )
F_197 ( V_69 ) ;
F_45 ( & V_69 -> V_113 ) ;
V_69 -> V_346 [ V_5 -> V_51 ] = NULL ;
V_69 -> V_347 [ V_5 -> V_51 ] = NULL ;
F_48 ( & V_69 -> V_113 ) ;
F_180 ( V_5 ) ;
F_24 ( V_5 -> V_208 ) ;
F_24 ( V_5 -> V_235 ) ;
F_198 ( V_2 ) ;
}
static int F_199 ( struct V_1 * V_2 , int V_348 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
int V_101 = 0 ;
F_43 ( V_124 , V_5 , L_81 ,
V_2 -> V_228 , V_348 ) ;
if ( ( V_348 < V_349 ) || ( V_348 > V_5 -> V_288 ) ) {
F_13 ( V_5 , L_82 , V_348 ) ;
return - V_350 ;
}
V_2 -> V_228 = V_348 ;
if ( F_200 ( V_2 ) ) {
F_45 ( & V_69 -> V_113 ) ;
if ( ! V_69 -> V_114 ) {
F_43 ( V_124 , V_5 , L_83 ) ;
} else {
F_164 ( V_2 , 1 ) ;
V_101 = F_138 ( V_2 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_84 ,
V_5 -> V_51 ) ;
F_32 ( V_69 -> V_102 , & V_5 -> V_214 ) ;
}
}
F_48 ( & V_69 -> V_113 ) ;
}
return 0 ;
}
static int F_201 ( struct V_1 * V_2 , struct V_351 * V_352 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
struct V_353 V_354 ;
if ( F_202 ( & V_354 , V_352 -> V_355 , sizeof( V_354 ) ) )
return - V_356 ;
if ( V_354 . V_139 )
return - V_9 ;
if ( ! ( V_69 -> V_2 -> V_118 . V_270 & V_271 ) )
return - V_9 ;
switch ( V_354 . V_357 ) {
case V_358 :
case V_359 :
break;
default:
return - V_360 ;
}
switch ( V_354 . V_361 ) {
case V_362 :
break;
case V_363 :
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
V_354 . V_361 = V_363 ;
break;
default:
return - V_360 ;
}
if ( F_203 ( V_2 , V_354 , V_2 -> V_377 ) ) {
V_354 . V_357 = V_358 ;
V_354 . V_361 = V_362 ;
}
return F_204 ( V_352 -> V_355 , & V_354 ,
sizeof( V_354 ) ) ? - V_356 : 0 ;
}
static int F_205 ( struct V_1 * V_2 , struct V_351 * V_352 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_204 ( V_352 -> V_355 , & V_5 -> V_353 ,
sizeof( V_5 -> V_353 ) ) ? - V_356 : 0 ;
}
static int F_206 ( struct V_1 * V_2 , struct V_351 * V_352 , int V_378 )
{
switch ( V_378 ) {
case V_379 :
return F_201 ( V_2 , V_352 ) ;
case V_380 :
return F_205 ( V_2 , V_352 ) ;
default:
return - V_381 ;
}
}
static T_6 F_207 ( struct V_1 * V_382 ,
T_6 V_377 )
{
struct V_4 * V_383 = F_2 ( V_382 ) ;
struct V_109 * V_69 = V_383 -> V_69 ;
if ( V_377 & V_384 &&
! ( V_69 -> V_2 -> V_118 . V_270 & V_385 ) )
V_377 |= V_386 ;
else
V_377 &= ~ V_386 ;
return V_377 ;
}
static int F_208 ( struct V_1 * V_382 ,
T_6 V_377 )
{
struct V_4 * V_5 = F_2 ( V_382 ) ;
bool V_387 = false ;
int V_83 = 0 ;
if ( F_209 ( V_382 , V_377 , V_388 ) ) {
F_130 ( V_5 , L_85 ,
( V_377 & V_388 ) ? L_86 : L_87 ) ;
V_387 = true ;
}
if ( F_209 ( V_382 , V_377 , V_389 ) ) {
T_1 V_390 = ( V_377 & V_389 ) ? 1 : 0 ;
F_130 ( V_5 , L_88 ,
V_390 ? L_86 : L_87 ) ;
V_83 = F_210 ( V_5 -> V_69 -> V_2 ,
V_5 -> V_51 , V_390 ) ;
if ( V_83 )
return V_83 ;
}
if ( F_209 ( V_382 , V_377 , V_384 ) ) {
F_130 ( V_5 , L_89 ,
( V_377 & V_384 ) ? L_86 : L_87 ) ;
V_387 = true ;
}
if ( F_209 ( V_382 , V_377 , V_391 ) )
F_130 ( V_5 , L_90 ,
( V_377 & V_391 ) ? L_86 : L_87 ) ;
if ( F_209 ( V_382 , V_377 , V_392 ) )
F_130 ( V_5 , L_91 ,
( V_377 & V_392 ) ? L_86 : L_87 ) ;
if ( F_209 ( V_382 , V_377 , V_393 ) ) {
F_130 ( V_5 , L_92 ,
( V_377 & V_393 ) ? L_86 : L_87 ) ;
F_211 ( V_382 , V_377 ) ;
}
if ( V_387 ) {
V_83 = F_203 ( V_382 , V_5 -> V_353 ,
V_377 ) ;
if ( V_83 )
return V_83 ;
}
return 0 ;
}
static int F_212 ( struct V_1 * V_2 , int V_394 , T_1 * V_125 )
{
struct V_4 * V_383 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_383 -> V_69 ;
T_5 V_395 = F_61 ( V_125 ) ;
if ( F_213 ( V_125 ) )
return - V_9 ;
return F_214 ( V_69 -> V_2 , V_383 -> V_51 , V_394 , V_395 ) ;
}
static int F_215 ( struct V_1 * V_2 , int V_396 , T_4 V_397 , T_1 V_398 )
{
struct V_4 * V_383 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_383 -> V_69 ;
return F_216 ( V_69 -> V_2 , V_383 -> V_51 , V_396 , V_397 , V_398 ) ;
}
static int F_217 ( struct V_1 * V_2 , int V_396 , int V_399 ,
int V_400 )
{
struct V_4 * V_383 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_383 -> V_69 ;
return F_218 ( V_69 -> V_2 , V_383 -> V_51 , V_396 , V_399 ,
V_400 ) ;
}
static int F_219 ( struct V_1 * V_2 , int V_396 , bool V_401 )
{
struct V_4 * V_383 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_383 -> V_69 ;
return F_220 ( V_69 -> V_2 , V_383 -> V_51 , V_396 , V_401 ) ;
}
static int F_221 ( struct V_1 * V_2 , int V_396 , struct V_402 * V_403 )
{
struct V_4 * V_383 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_383 -> V_69 ;
return F_222 ( V_69 -> V_2 , V_383 -> V_51 , V_396 , V_403 ) ;
}
static int F_223 ( struct V_1 * V_2 , int V_396 , int V_193 )
{
struct V_4 * V_383 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_383 -> V_69 ;
return F_224 ( V_69 -> V_2 , V_383 -> V_51 , V_396 , V_193 ) ;
}
static int F_225 ( struct V_1 * V_2 , int V_396 ,
struct V_404 * V_405 )
{
struct V_4 * V_383 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_383 -> V_69 ;
return F_226 ( V_69 -> V_2 , V_383 -> V_51 , V_396 , V_405 ) ;
}
static int F_227 ( struct V_1 * V_2 ,
struct V_406 * V_407 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_126 * V_69 = V_5 -> V_69 -> V_2 ;
int V_6 ;
T_5 V_408 = V_69 -> V_118 . V_408 [ V_5 -> V_51 ] ;
if ( ! V_408 )
return - V_381 ;
V_407 -> V_409 = sizeof( V_408 ) ;
for ( V_6 = V_410 - 1 ; V_6 >= 0 ; -- V_6 ) {
V_407 -> V_24 [ V_6 ] = V_408 & 0xff ;
V_408 >>= 8 ;
}
return 0 ;
}
static void F_228 ( struct V_18 * V_19 )
{
int V_83 ;
struct V_4 * V_5 = F_7 ( V_19 , struct V_4 ,
V_411 ) ;
V_83 = F_229 ( V_5 -> V_69 -> V_2 , V_5 -> V_412 ) ;
if ( V_83 )
goto V_99;
V_83 = F_152 ( V_5 -> V_69 -> V_2 , V_5 -> V_51 ,
V_314 , 1 ) ;
V_99:
if ( V_83 ) {
F_13 ( V_5 , L_93 , V_83 ) ;
return;
}
V_5 -> V_2 -> V_413 |= V_414 | V_415 |
V_416 | V_417 ;
}
static void F_230 ( struct V_18 * V_19 )
{
int V_83 ;
struct V_4 * V_5 = F_7 ( V_19 , struct V_4 ,
V_418 ) ;
V_5 -> V_2 -> V_413 &= ~ ( V_414 | V_415 |
V_416 | V_417 ) ;
V_83 = F_152 ( V_5 -> V_69 -> V_2 , V_5 -> V_51 ,
V_314 , 0 ) ;
if ( V_83 )
F_13 ( V_5 , L_93 , V_83 ) ;
V_5 -> V_412 = 0 ;
}
static void F_231 ( struct V_1 * V_2 ,
T_7 V_419 , V_29 V_51 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_29 V_420 ;
if ( V_5 -> V_69 -> V_2 -> V_118 . V_119 != V_120 )
return;
if ( V_419 == V_421 )
return;
V_420 = V_5 -> V_412 ;
if ( V_420 && V_420 != V_51 ) {
F_10 ( V_5 , L_94 ,
F_232 ( V_420 ) , F_232 ( V_51 ) ) ;
return;
}
V_5 -> V_412 = V_51 ;
F_32 ( V_5 -> V_69 -> V_102 , & V_5 -> V_411 ) ;
}
static void F_233 ( struct V_1 * V_2 ,
T_7 V_419 , V_29 V_51 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_29 V_420 ;
if ( V_5 -> V_69 -> V_2 -> V_118 . V_119 != V_120 )
return;
if ( V_419 == V_421 )
return;
V_420 = V_5 -> V_412 ;
if ( V_420 != V_51 ) {
F_43 ( V_124 , V_5 , L_95 , F_232 ( V_51 ) ) ;
return;
}
F_32 ( V_5 -> V_69 -> V_102 , & V_5 -> V_418 ) ;
}
static T_6 F_234 ( struct V_85 * V_86 ,
struct V_1 * V_2 ,
T_6 V_377 )
{
V_377 = F_235 ( V_86 , V_377 ) ;
return F_236 ( V_86 , V_377 ) ;
}
static int F_237 ( struct V_1 * V_2 , int V_422 , T_3 V_423 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_280 * V_208 = V_5 -> V_208 [ V_422 ] ;
struct V_424 V_425 ;
int V_101 ;
if ( ! ( V_5 -> V_69 -> V_2 -> V_118 . V_270 & V_426 ) )
return - V_381 ;
if ( V_423 >> 12 ) {
V_425 . V_427 = V_428 ;
V_425 . V_429 = V_423 / 1000 ;
} else if ( V_423 ) {
V_425 . V_427 = V_430 ;
V_425 . V_429 = V_423 ;
} else {
V_425 . V_427 = 0 ;
V_425 . V_429 = 0 ;
}
V_101 = F_238 ( V_5 -> V_69 -> V_2 , V_208 -> V_58 , V_431 ,
& V_425 ) ;
return V_101 ;
}
static void F_239 ( struct V_18 * V_19 )
{
struct V_432 * V_433 = F_7 ( V_19 ,
struct V_432 ,
V_19 ) ;
int V_101 = 0 ;
struct V_126 * V_2 = V_433 -> V_5 -> V_69 -> V_2 ;
if ( V_433 -> V_434 ) {
if ( ! F_240 ( V_2 ) ) {
V_101 = F_241 ( V_2 ) ;
if ( V_101 )
F_13 ( V_433 -> V_5 , L_96 ) ;
}
if ( ! V_101 ) {
V_101 = F_242 ( V_2 , & V_433 -> V_435 ) ;
if ( V_101 )
F_13 ( V_433 -> V_5 , L_97 ,
V_433 -> V_435 . V_436 ,
V_433 -> V_435 . V_437 ,
V_101 ) ;
}
} else if ( F_240 ( V_2 ) ) {
V_101 = F_243 ( V_2 ) ;
if ( V_101 )
F_13 ( V_433 -> V_5 , L_98 ) ;
}
F_244 ( V_433 -> V_5 -> V_2 ) ;
F_24 ( V_433 ) ;
}
static int F_245 ( struct V_4 * V_5 , int V_434 ,
T_1 V_438 , T_1 V_439 )
{
struct V_432 * V_433 = NULL ;
V_433 = F_19 ( sizeof( * V_433 ) , V_77 ) ;
if ( ! V_433 )
return - V_100 ;
F_20 ( & V_433 -> V_19 , F_239 ) ;
V_433 -> V_5 = V_5 ;
V_433 -> V_434 = V_434 ;
V_433 -> V_435 . V_436 = V_438 ;
V_433 -> V_435 . V_437 = V_439 ;
F_246 ( V_5 -> V_2 ) ;
F_32 ( V_5 -> V_69 -> V_102 , & V_433 -> V_19 ) ;
return 0 ;
}
int F_247 ( struct V_440 * V_441 ,
unsigned long V_442 , void * V_443 )
{
struct V_1 * V_444 = F_248 ( V_443 ) ;
T_1 V_51 = 0 ;
struct V_109 * V_69 ;
struct V_126 * V_2 ;
int V_6 , V_445 = 0 ;
bool V_446 = true ;
struct V_4 * V_5 ;
T_1 V_447 = 0 ;
T_1 V_448 = 0 ;
if ( ! F_249 ( F_250 ( V_444 ) , & V_449 ) )
return V_450 ;
V_69 = F_7 ( V_441 , struct V_109 , V_451 ) ;
V_2 = V_69 -> V_2 ;
F_251 (i, dev, MLX4_PORT_TYPE_ETH) {
++ V_445 ;
if ( ! V_51 && ( V_69 -> V_346 [ V_6 ] == V_444 ) )
V_51 = V_6 ;
V_69 -> V_347 [ V_6 ] = V_69 -> V_346 [ V_6 ] ?
F_252 ( V_69 -> V_346 [ V_6 ] ) : NULL ;
if ( ! V_69 -> V_347 [ V_6 ] )
V_446 = false ;
if ( V_445 < 2 )
continue;
if ( V_69 -> V_347 [ V_6 ] != V_69 -> V_347 [ V_6 - 1 ] )
V_446 = false ;
}
V_446 = ( V_445 == 2 ) ? V_446 : false ;
if ( ( V_446 && ( V_442 != V_452 ) ) || ! V_51 )
return V_450 ;
V_5 = F_2 ( V_444 ) ;
if ( V_446 ) {
struct V_453 * V_454 = V_443 ;
struct V_455 * V_456 =
& V_454 -> V_456 ;
if ( ( V_456 -> V_457 . V_458 != V_459 ) &&
( V_456 -> V_457 . V_458 != V_460 ) &&
( V_456 -> V_457 . V_458 != V_461 ) )
V_446 = false ;
if ( V_456 -> V_457 . V_462 != 2 )
V_446 = false ;
if ( V_446 ) {
if ( V_456 -> V_457 . V_458 ==
V_459 ) {
if ( V_456 -> V_463 . V_464 ==
V_465 ) {
if ( V_51 == 1 ) {
V_447 = 2 ;
V_448 = 2 ;
} else {
V_447 = 1 ;
V_448 = 1 ;
}
} else {
if ( V_51 == 1 ) {
V_447 = 1 ;
V_448 = 1 ;
} else {
V_447 = 2 ;
V_448 = 2 ;
}
}
} else {
T_8 V_466 = V_456 -> V_463 . V_466 ;
if ( V_51 == 1 )
V_448 = 2 ;
else
V_447 = 1 ;
if ( ( V_466 == V_467 ) ||
( V_466 == V_468 ) ) {
if ( V_51 == 1 )
V_447 = 1 ;
else
V_448 = 2 ;
} else {
if ( V_51 == 1 )
V_447 = 2 ;
else
V_448 = 1 ;
}
}
}
}
F_245 ( V_5 , V_446 ,
V_447 , V_448 ) ;
return V_450 ;
}
void F_253 ( struct V_126 * V_2 ,
struct V_469 * V_470 ,
T_1 V_313 , T_1 V_312 ,
T_1 V_311 , T_1 V_310 )
{
int V_471 = V_472 + V_473 + V_474 ;
if ( ! F_254 ( V_2 ) &&
( V_2 -> V_118 . V_270 & V_475 ) ) {
F_45 ( & V_470 -> V_476 ) ;
F_255 ( V_470 -> V_477 , V_471 , V_478 ) ;
if ( V_313 )
F_256 ( V_470 -> V_477 , V_471 ,
V_479 ) ;
V_471 += V_479 ;
if ( V_312 && ! ( V_313 ) )
F_256 ( V_470 -> V_477 , V_471 ,
V_480 ) ;
V_471 += V_480 ;
if ( V_311 )
F_256 ( V_470 -> V_477 , V_471 ,
V_481 ) ;
V_471 += V_481 ;
if ( V_310 && ! ( V_311 ) )
F_256 ( V_470 -> V_477 , V_471 ,
V_482 ) ;
V_471 += V_482 ;
F_48 ( & V_470 -> V_476 ) ;
}
}
void F_257 ( struct V_126 * V_2 ,
struct V_469 * V_470 ,
T_1 V_313 , T_1 V_312 ,
T_1 V_311 , T_1 V_310 )
{
int V_471 = 0 ;
F_258 ( & V_470 -> V_476 ) ;
F_259 ( V_470 -> V_477 , V_483 ) ;
if ( F_254 ( V_2 ) ) {
F_256 ( V_470 -> V_477 , V_471 +
F_260 ( V_254 ) , 1 ) ;
F_256 ( V_470 -> V_477 , V_471 +
F_260 ( V_484 ) , 1 ) ;
F_256 ( V_470 -> V_477 , V_471 +
F_260 ( V_255 ) , 1 ) ;
F_256 ( V_470 -> V_477 , V_471 +
F_260 ( V_485 ) , 1 ) ;
F_256 ( V_470 -> V_477 , V_471 +
F_260 ( V_486 ) , 1 ) ;
F_256 ( V_470 -> V_477 , V_471 +
F_260 ( V_487 ) , 1 ) ;
} else {
F_256 ( V_470 -> V_477 , V_471 , V_472 ) ;
}
V_471 += V_472 ;
F_256 ( V_470 -> V_477 , V_471 , V_473 ) ;
V_471 += V_473 ;
if ( F_261 ( V_2 ) )
F_256 ( V_470 -> V_477 , V_471 ,
V_474 ) ;
V_471 += V_474 ;
F_253 ( V_2 , V_470 ,
V_313 , V_312 ,
V_311 , V_310 ) ;
V_471 += V_478 ;
if ( ! F_254 ( V_2 ) )
F_256 ( V_470 -> V_477 , V_471 , V_488 ) ;
}
int F_262 ( struct V_109 * V_69 , int V_51 ,
struct V_336 * V_309 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_6 ;
int V_101 ;
V_2 = F_263 ( sizeof( struct V_4 ) ,
V_489 , V_490 ) ;
if ( V_2 == NULL )
return - V_100 ;
F_264 ( V_2 , V_309 -> V_207 ) ;
F_265 ( V_2 , V_309 -> V_202 ) ;
F_266 ( V_2 , & V_69 -> V_2 -> V_491 -> V_492 -> V_2 ) ;
V_2 -> V_493 = V_51 - 1 ;
V_5 = F_2 ( V_2 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_300 = F_171 ( V_69 -> V_2 ) ;
F_267 ( & V_5 -> V_216 ) ;
F_20 ( & V_5 -> V_174 , F_106 ) ;
F_20 ( & V_5 -> V_214 , F_176 ) ;
F_20 ( & V_5 -> V_273 , F_129 ) ;
F_268 ( & V_5 -> V_265 , F_122 ) ;
F_268 ( & V_5 -> V_269 , F_126 ) ;
#ifdef F_156
F_20 ( & V_5 -> V_411 , F_228 ) ;
F_20 ( & V_5 -> V_418 , F_230 ) ;
#endif
#ifdef F_181
F_57 ( & V_5 -> V_81 ) ;
F_267 ( & V_5 -> V_98 ) ;
#endif
V_5 -> V_2 = V_2 ;
V_5 -> V_69 = V_69 ;
V_5 -> V_494 = & V_69 -> V_492 -> V_2 ;
V_5 -> V_309 = V_309 ;
V_5 -> V_51 = V_51 ;
V_5 -> V_115 = false ;
V_5 -> V_139 = V_309 -> V_139 ;
V_5 -> V_495 = V_496 ;
V_5 -> V_497 = F_269 ( V_498 |
V_499 ) ;
V_5 -> V_10 = V_69 -> V_500 . V_10 ;
V_5 -> V_207 = V_309 -> V_207 ;
V_5 -> V_501 = V_502 ;
F_270 ( V_5 -> V_503 , sizeof( V_5 -> V_503 ) ) ;
V_5 -> V_208 = F_19 ( sizeof( struct V_280 * ) * V_489 ,
V_172 ) ;
if ( ! V_5 -> V_208 ) {
V_101 = - V_100 ;
goto V_99;
}
V_5 -> V_235 = F_19 ( sizeof( struct V_200 * ) * V_489 ,
V_172 ) ;
if ( ! V_5 -> V_235 ) {
V_101 = - V_100 ;
goto V_99;
}
V_5 -> V_202 = V_309 -> V_202 ;
V_5 -> V_296 = ( V_69 -> V_2 -> V_118 . V_295 == 64 ) ? 1 : 0 ;
V_5 -> V_295 = V_69 -> V_2 -> V_118 . V_295 ;
V_5 -> V_504 = - 1 ;
V_5 -> V_505 = V_506 ;
#ifdef F_271
if ( ! F_254 ( V_5 -> V_69 -> V_2 ) ) {
if ( V_69 -> V_2 -> V_118 . V_270 & V_507 ) {
V_2 -> V_508 = & V_509 ;
} else {
F_130 ( V_5 , L_99 ) ;
V_2 -> V_508 = & V_510 ;
}
}
#endif
for ( V_6 = 0 ; V_6 < V_190 ; ++ V_6 )
F_272 ( & V_5 -> V_145 [ V_6 ] ) ;
V_5 -> V_288 = V_69 -> V_2 -> V_118 . V_511 [ V_5 -> V_51 ] ;
if ( V_69 -> V_2 -> V_118 . V_512 [ V_5 -> V_51 ] &
V_513 )
V_5 -> V_139 |= V_514 ;
V_2 -> V_515 = V_65 ;
F_52 ( V_2 -> V_64 , V_69 -> V_2 -> V_118 . V_516 [ V_5 -> V_51 ] ) ;
if ( ! F_77 ( V_2 -> V_64 ) ) {
F_13 ( V_5 , L_100 ,
V_5 -> V_51 , V_2 -> V_64 ) ;
V_101 = - V_9 ;
goto V_99;
} else if ( F_254 ( V_5 -> V_69 -> V_2 ) &&
( V_5 -> V_69 -> V_2 -> V_517 & 1 << V_5 -> V_51 ) ) {
V_2 -> V_518 |= V_519 ;
F_10 ( V_5 , L_101 , V_2 -> V_64 ) ;
}
memcpy ( V_5 -> V_153 , V_2 -> V_64 , sizeof( V_5 -> V_153 ) ) ;
V_5 -> V_335 = F_273 ( sizeof( struct V_520 ) +
V_521 * V_522 ) ;
V_101 = F_185 ( V_5 ) ;
if ( V_101 )
goto V_99;
V_5 -> V_353 . V_139 = 0 ;
V_5 -> V_353 . V_357 = V_358 ;
V_5 -> V_353 . V_361 = V_362 ;
V_101 = F_274 ( V_69 -> V_2 , & V_5 -> V_344 ,
V_345 , V_345 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_102 ) ;
goto V_99;
}
V_5 -> V_343 = 1 ;
if ( F_261 ( V_5 -> V_69 -> V_2 ) )
V_2 -> V_523 = & V_524 ;
else
V_2 -> V_523 = & V_525 ;
V_2 -> V_526 = V_527 ;
F_264 ( V_2 , V_5 -> V_207 ) ;
F_265 ( V_2 , V_5 -> V_202 ) ;
V_2 -> V_528 = & V_529 ;
V_2 -> V_530 = V_531 | V_414 | V_532 ;
if ( V_69 -> V_533 )
V_2 -> V_530 |= V_416 | V_534 ;
V_2 -> V_535 = V_2 -> V_530 ;
V_2 -> V_530 |= V_415 | V_536 ;
V_2 -> V_377 = V_2 -> V_530 | V_537 |
V_391 | V_384 |
V_538 ;
V_2 -> V_530 |= V_393 |
V_391 | V_384 ;
if ( ! ( V_69 -> V_2 -> V_118 . V_270 & V_385 ) ) {
V_2 -> V_377 |= V_386 |
V_539 ;
V_2 -> V_530 |= V_386 ;
}
if ( F_254 ( V_69 -> V_2 ) ) {
int V_540 ;
V_101 = F_275 ( V_69 -> V_2 , V_51 , & V_540 ) ;
if ( ! V_101 && V_540 ) {
V_2 -> V_530 |= V_392 ;
V_5 -> V_495 |= V_541 ;
}
} else {
if ( V_69 -> V_2 -> V_118 . V_270 & V_542 &&
! ( V_69 -> V_2 -> V_118 . V_270 &
V_385 ) )
V_2 -> V_530 |= V_392 ;
}
if ( V_69 -> V_2 -> V_118 . V_139 & V_543 )
V_2 -> V_530 |= V_388 ;
if ( V_69 -> V_2 -> V_118 . V_270 & V_544 )
V_2 -> V_530 |= V_389 ;
if ( V_69 -> V_2 -> V_118 . V_127 ==
V_133 &&
V_69 -> V_2 -> V_118 . V_121 != V_122 )
V_2 -> V_530 |= V_545 ;
if ( V_69 -> V_2 -> V_118 . V_127 != V_137 )
V_2 -> V_197 |= V_198 ;
if ( V_69 -> V_2 -> V_118 . V_270 & V_546 ) {
V_5 -> V_547 = V_548 ;
} else if ( V_69 -> V_2 -> V_118 . V_270 & V_549 ) {
V_5 -> V_547 = V_550 ;
} else {
F_10 ( V_5 ,
L_103 ) ;
V_5 -> V_547 = V_548 ;
}
if ( V_69 -> V_2 -> V_118 . V_119 == V_120 ) {
V_2 -> V_530 |= V_417 ;
V_2 -> V_377 |= V_417 ;
}
V_69 -> V_346 [ V_51 ] = V_2 ;
V_69 -> V_347 [ V_51 ] = NULL ;
F_131 ( V_2 ) ;
F_119 ( V_5 ) ;
F_10 ( V_5 , L_104 , V_309 -> V_207 ) ;
F_10 ( V_5 , L_105 , V_309 -> V_202 ) ;
F_211 ( V_5 -> V_2 , V_5 -> V_2 -> V_377 ) ;
F_140 ( V_2 ) ;
V_101 = F_151 ( V_69 -> V_2 , V_5 -> V_51 ,
V_5 -> V_289 + V_308 ,
V_309 -> V_310 , V_309 -> V_311 ,
V_309 -> V_312 , V_309 -> V_313 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_65 ,
V_5 -> V_51 , V_101 ) ;
goto V_99;
}
if ( V_69 -> V_2 -> V_118 . V_119 == V_120 ) {
V_101 = F_152 ( V_69 -> V_2 , V_5 -> V_51 , V_314 , 1 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_67 ,
V_101 ) ;
goto V_99;
}
}
F_10 ( V_5 , L_68 ) ;
V_101 = F_153 ( V_69 -> V_2 , V_5 -> V_51 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_69 ) ;
goto V_99;
}
F_125 ( V_69 -> V_102 , & V_5 -> V_265 , V_266 ) ;
if ( V_69 -> V_2 -> V_118 . V_270 & V_271 )
F_276 ( V_69 ) ;
F_125 ( V_69 -> V_102 , & V_5 -> V_269 ,
V_272 ) ;
F_257 ( V_69 -> V_2 , & V_5 -> V_470 ,
V_69 -> V_500 . V_309 [ V_5 -> V_51 ] . V_313 ,
V_69 -> V_500 . V_309 [ V_5 -> V_51 ] . V_312 ,
V_69 -> V_500 . V_309 [ V_5 -> V_51 ] . V_311 ,
V_69 -> V_500 . V_309 [ V_5 -> V_51 ] . V_310 ) ;
V_101 = F_277 ( V_2 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_106 , V_51 ) ;
goto V_99;
}
V_5 -> V_342 = 1 ;
return 0 ;
V_99:
F_192 ( V_2 ) ;
return V_101 ;
}
int F_203 ( struct V_1 * V_2 ,
struct V_353 V_551 ,
T_6 V_377 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_109 * V_69 = V_5 -> V_69 ;
int V_115 = 0 ;
int V_101 = 0 ;
if ( V_5 -> V_353 . V_357 == V_551 . V_357 &&
V_5 -> V_353 . V_361 == V_551 . V_361 &&
! F_209 ( V_2 , V_377 , V_384 ) &&
! F_209 ( V_2 , V_377 , V_388 ) )
return 0 ;
if ( F_209 ( V_2 , V_377 , V_384 ) &&
( V_377 & V_384 ) &&
( V_5 -> V_353 . V_361 != V_362 ) ) {
F_10 ( V_5 , L_107 ) ;
return - V_9 ;
}
F_45 ( & V_69 -> V_113 ) ;
if ( V_5 -> V_115 ) {
V_115 = 1 ;
F_164 ( V_2 , 1 ) ;
}
F_180 ( V_5 ) ;
F_10 ( V_5 , L_108 ,
V_551 . V_361 , ! ! ( V_377 & V_384 ) ) ;
V_5 -> V_353 . V_357 = V_551 . V_357 ;
V_5 -> V_353 . V_361 = V_551 . V_361 ;
if ( F_209 ( V_2 , V_377 , V_384 ) ) {
if ( V_377 & V_384 )
V_2 -> V_377 |= V_384 ;
else
V_2 -> V_377 &= ~ V_384 ;
} else if ( V_551 . V_361 == V_362 ) {
if ( V_2 -> V_552 & V_384 )
V_2 -> V_377 |= V_384 ;
else
V_2 -> V_377 &= ~ V_384 ;
}
if ( F_209 ( V_2 , V_377 , V_388 ) ) {
if ( V_377 & V_388 )
V_2 -> V_377 |= V_388 ;
else
V_2 -> V_377 &= ~ V_388 ;
}
if ( V_551 . V_361 != V_362 ) {
if ( V_2 -> V_377 & V_384 )
F_10 ( V_5 , L_109 ) ;
V_2 -> V_377 &= ~ V_384 ;
}
V_101 = F_185 ( V_5 ) ;
if ( V_101 ) {
F_13 ( V_5 , L_110 ) ;
goto V_99;
}
if ( V_115 ) {
V_101 = F_138 ( V_2 ) ;
if ( V_101 )
F_13 ( V_5 , L_111 ) ;
}
V_99:
F_48 ( & V_69 -> V_113 ) ;
F_278 ( V_2 ) ;
return V_101 ;
}
