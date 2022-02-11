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
static int F_5 ( struct V_1 * V_2 , T_2 V_11 , T_3 V_12 ,
struct V_13 * V_14 )
{
if ( V_14 -> type != V_15 )
return - V_9 ;
return F_1 ( V_2 , V_14 -> V_14 ) ;
}
static enum V_16 F_6 ( T_1 V_17 )
{
switch ( V_17 ) {
case V_18 :
return V_19 ;
case V_20 :
return V_21 ;
default:
return V_22 ;
}
}
static void F_7 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_8 ( V_24 ,
struct V_25 ,
V_24 ) ;
struct V_4 * V_5 = V_26 -> V_5 ;
struct V_27 V_28 = {
. V_29 = F_6 ( V_26 -> V_17 ) ,
{
. V_30 = {
. V_31 = V_26 -> V_31 ,
. V_32 = ( V_33 T_3 ) - 1 ,
. V_34 = V_26 -> V_34 ,
. V_35 = ( V_33 T_3 ) - 1 ,
} ,
} ,
} ;
struct V_27 V_36 = {
. V_29 = V_37 ,
{
. V_38 = {
. V_39 = V_26 -> V_39 ,
. V_40 = ( V_33 V_41 ) - 1 ,
. V_42 = V_26 -> V_42 ,
. V_43 = ( V_33 V_41 ) - 1 ,
} ,
} ,
} ;
struct V_27 V_44 = {
. V_29 = V_45 ,
} ;
struct V_46 V_47 = {
. V_48 = F_9 ( V_47 . V_48 ) ,
. V_49 = V_50 ,
. V_51 = 1 ,
. V_52 = 1 ,
. V_53 = V_54 ,
. V_55 = V_5 -> V_55 ,
. V_56 = V_57 ,
} ;
int V_58 ;
T_4 V_59 = F_10 ( V_60 << 16 ) ;
if ( V_28 . V_29 >= V_22 ) {
F_11 ( V_5 , L_1 ,
V_26 -> V_17 ) ;
goto V_61;
}
F_12 ( & V_44 . V_48 , & V_47 . V_48 ) ;
F_12 ( & V_36 . V_48 , & V_47 . V_48 ) ;
F_12 ( & V_28 . V_48 , & V_47 . V_48 ) ;
V_47 . V_62 = V_5 -> V_63 . V_64 [ V_26 -> V_65 ] . V_62 ;
memcpy ( V_44 . V_66 . V_67 , V_5 -> V_2 -> V_68 , V_69 ) ;
memcpy ( V_44 . V_66 . V_70 , & V_59 , V_69 ) ;
V_26 -> V_71 = 0 ;
if ( V_26 -> V_72 ) {
V_58 = F_13 ( V_5 -> V_73 -> V_2 , V_26 -> V_72 ) ;
if ( V_58 && V_58 != - V_74 )
F_14 ( V_5 , L_2 , V_58 ) ;
}
V_58 = F_15 ( V_5 -> V_73 -> V_2 , & V_47 , & V_26 -> V_72 ) ;
if ( V_58 )
F_14 ( V_5 , L_3 , V_58 ) ;
V_61:
F_16 ( V_5 ) ;
V_26 -> V_71 = 1 ;
}
static inline struct V_75 *
F_17 ( struct V_4 * V_5 , V_41 V_42 , V_41 V_39 ,
T_3 V_34 , T_3 V_31 )
{
unsigned long V_76 ;
int V_77 ;
V_76 = ( V_33 unsigned long ) V_34 |
( ( V_33 unsigned long ) V_31 << 2 ) ;
V_76 ^= ( V_33 unsigned long ) ( V_42 ^ V_39 ) ;
V_77 = F_18 ( V_76 , V_78 ) ;
return & V_5 -> V_79 [ V_77 ] ;
}
static struct V_25 *
F_19 ( struct V_4 * V_5 , int V_65 , V_41 V_42 ,
V_41 V_39 , T_1 V_17 , T_3 V_34 ,
T_3 V_31 , T_2 V_80 )
{
struct V_25 * V_26 = NULL ;
V_26 = F_20 ( sizeof( struct V_25 ) , V_81 ) ;
if ( ! V_26 )
return NULL ;
V_26 -> V_5 = V_5 ;
V_26 -> V_65 = V_65 ;
F_21 ( & V_26 -> V_24 , F_7 ) ;
V_26 -> V_42 = V_42 ;
V_26 -> V_39 = V_39 ;
V_26 -> V_17 = V_17 ;
V_26 -> V_34 = V_34 ;
V_26 -> V_31 = V_31 ;
V_26 -> V_80 = V_80 ;
V_26 -> V_29 = V_5 -> V_82 ++ % V_83 ;
F_12 ( & V_26 -> V_84 , & V_5 -> V_85 ) ;
F_22 ( & V_26 -> V_86 ,
F_17 ( V_5 , V_42 , V_39 , V_34 ,
V_31 ) ) ;
return V_26 ;
}
static void F_23 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_5 ;
int V_58 ;
F_24 ( & V_26 -> V_84 ) ;
V_58 = F_13 ( V_5 -> V_73 -> V_2 , V_26 -> V_72 ) ;
if ( V_58 && V_58 != - V_74 )
F_14 ( V_5 , L_2 , V_58 ) ;
F_25 ( V_26 ) ;
}
static inline struct V_25 *
F_26 ( struct V_4 * V_5 , V_41 V_42 , V_41 V_39 ,
T_1 V_17 , T_3 V_34 , T_3 V_31 )
{
struct V_25 * V_26 ;
struct V_25 * V_87 = NULL ;
F_27 (filter,
filter_hash_bucket(priv, src_ip, dst_ip,
src_port, dst_port),
filter_chain) {
if ( V_26 -> V_42 == V_42 &&
V_26 -> V_39 == V_39 &&
V_26 -> V_17 == V_17 &&
V_26 -> V_34 == V_34 &&
V_26 -> V_31 == V_31 ) {
V_87 = V_26 ;
break;
}
}
return V_87 ;
}
static int
F_28 ( struct V_1 * V_88 , const struct V_89 * V_90 ,
T_5 V_65 , T_2 V_80 )
{
struct V_4 * V_5 = F_2 ( V_88 ) ;
struct V_25 * V_26 ;
const struct V_91 * V_92 ;
const T_3 * V_93 ;
T_1 V_17 ;
V_41 V_42 ;
V_41 V_39 ;
T_3 V_34 ;
T_3 V_31 ;
int V_94 = F_29 ( V_90 ) ;
int V_87 = 0 ;
if ( V_90 -> V_95 != F_30 ( V_96 ) )
return - V_97 ;
V_92 = ( const struct V_91 * ) ( V_90 -> V_98 + V_94 ) ;
if ( F_31 ( V_92 ) )
return - V_97 ;
if ( ( V_92 -> V_95 != V_20 ) && ( V_92 -> V_95 != V_18 ) )
return - V_97 ;
V_93 = ( const T_3 * ) ( V_90 -> V_98 + V_94 + 4 * V_92 -> V_99 ) ;
V_17 = V_92 -> V_95 ;
V_42 = V_92 -> V_100 ;
V_39 = V_92 -> V_101 ;
V_34 = V_93 [ 0 ] ;
V_31 = V_93 [ 1 ] ;
F_32 ( & V_5 -> V_102 ) ;
V_26 = F_26 ( V_5 , V_42 , V_39 , V_17 ,
V_34 , V_31 ) ;
if ( V_26 ) {
if ( V_26 -> V_65 == V_65 )
goto V_103;
V_26 -> V_65 = V_65 ;
} else {
V_26 = F_19 ( V_5 , V_65 ,
V_42 , V_39 , V_17 ,
V_34 , V_31 , V_80 ) ;
if ( ! V_26 ) {
V_87 = - V_104 ;
goto V_105;
}
}
F_33 ( V_5 -> V_73 -> V_106 , & V_26 -> V_24 ) ;
V_103:
V_87 = V_26 -> V_29 ;
V_105:
F_34 ( & V_5 -> V_102 ) ;
return V_87 ;
}
void F_35 ( struct V_4 * V_5 )
{
struct V_25 * V_26 , * V_107 ;
F_36 ( V_108 ) ;
F_32 ( & V_5 -> V_102 ) ;
F_37 (filter, tmp, &priv->filters, next) {
F_38 ( & V_26 -> V_84 , & V_108 ) ;
F_39 ( & V_26 -> V_86 ) ;
}
F_34 ( & V_5 -> V_102 ) ;
F_37 (filter, tmp, &del_list, next) {
F_40 ( & V_26 -> V_24 ) ;
F_23 ( V_26 ) ;
}
}
static void F_16 ( struct V_4 * V_5 )
{
struct V_25 * V_26 = NULL , * V_107 , * V_109 = NULL ;
F_36 ( V_108 ) ;
int V_6 = 0 ;
F_32 ( & V_5 -> V_102 ) ;
F_37 (filter, tmp, &priv->filters, next) {
if ( V_6 > V_110 )
break;
if ( V_26 -> V_71 &&
! F_41 ( & V_26 -> V_24 ) &&
F_42 ( V_5 -> V_2 ,
V_26 -> V_65 , V_26 -> V_80 ,
V_26 -> V_29 ) ) {
F_38 ( & V_26 -> V_84 , & V_108 ) ;
F_39 ( & V_26 -> V_86 ) ;
} else
V_109 = V_26 ;
V_6 ++ ;
}
if ( V_109 && ( & V_109 -> V_84 != V_5 -> V_85 . V_84 ) )
F_38 ( & V_5 -> V_85 , & V_109 -> V_84 ) ;
F_34 ( & V_5 -> V_102 ) ;
F_37 (filter, tmp, &del_list, next)
F_23 ( V_26 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
T_3 V_12 , T_5 V_111 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
int V_105 ;
int V_113 ;
F_44 ( V_114 , V_5 , L_4 , V_111 ) ;
F_45 ( V_111 , V_5 -> V_115 ) ;
F_46 ( & V_73 -> V_116 ) ;
if ( V_73 -> V_117 && V_5 -> V_118 ) {
V_105 = F_47 ( V_73 -> V_2 , V_5 ) ;
if ( V_105 )
F_14 ( V_5 , L_5 ) ;
}
if ( F_48 ( V_73 -> V_2 , V_5 -> V_55 , V_111 , & V_113 ) )
F_44 ( V_114 , V_5 , L_6 , V_111 ) ;
F_49 ( & V_73 -> V_116 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
T_3 V_12 , T_5 V_111 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
int V_105 ;
F_44 ( V_114 , V_5 , L_7 , V_111 ) ;
F_51 ( V_111 , V_5 -> V_115 ) ;
F_46 ( & V_73 -> V_116 ) ;
F_52 ( V_73 -> V_2 , V_5 -> V_55 , V_111 ) ;
if ( V_73 -> V_117 && V_5 -> V_118 ) {
V_105 = F_47 ( V_73 -> V_2 , V_5 ) ;
if ( V_105 )
F_14 ( V_5 , L_5 ) ;
}
F_49 ( & V_73 -> V_116 ) ;
return 0 ;
}
static void F_53 ( unsigned char V_67 [ V_69 + 2 ] , T_6 V_119 )
{
int V_6 ;
for ( V_6 = V_69 - 1 ; V_6 >= 0 ; -- V_6 ) {
V_67 [ V_6 ] = V_119 & 0xff ;
V_119 >>= 8 ;
}
memset ( & V_67 [ V_69 ] , 0 , 2 ) ;
}
static int F_54 ( struct V_4 * V_5 , unsigned char * V_120 ,
int V_62 , T_6 * V_72 )
{
int V_105 ;
if ( V_5 -> V_73 -> V_2 -> V_121 . V_122 != V_123 ||
V_5 -> V_73 -> V_2 -> V_121 . V_124 == V_125 )
return 0 ;
V_105 = F_55 ( V_5 -> V_73 -> V_2 , V_120 , V_5 -> V_55 , V_62 ,
V_126 , V_72 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_8 , V_105 ) ;
return V_105 ;
}
F_44 ( V_127 , V_5 , L_9 , V_120 , * V_72 ) ;
return 0 ;
}
static int F_56 ( struct V_4 * V_5 ,
unsigned char * V_128 , int * V_62 , T_6 * V_72 )
{
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_129 * V_2 = V_73 -> V_2 ;
int V_105 ;
switch ( V_2 -> V_121 . V_130 ) {
case V_131 : {
struct V_132 V_133 ;
T_1 V_134 [ 16 ] = { 0 } ;
V_133 . V_62 = * V_62 ;
memcpy ( & V_134 [ 10 ] , V_128 , V_69 ) ;
V_134 [ 5 ] = V_5 -> V_55 ;
V_105 = F_57 ( V_2 , & V_133 , V_134 , 0 , V_135 ) ;
break;
}
case V_136 : {
struct V_27 V_44 = { { NULL } } ;
T_4 V_59 = F_10 ( V_60 << 16 ) ;
struct V_46 V_47 = {
. V_49 = V_137 ,
. V_51 = 0 ,
. V_52 = 1 ,
. V_53 = V_54 ,
. V_56 = V_126 ,
} ;
V_47 . V_55 = V_5 -> V_55 ;
V_47 . V_62 = * V_62 ;
F_58 ( & V_47 . V_48 ) ;
V_44 . V_29 = V_45 ;
memcpy ( V_44 . V_66 . V_67 , V_128 , V_69 ) ;
memcpy ( V_44 . V_66 . V_70 , & V_59 , V_69 ) ;
F_12 ( & V_44 . V_48 , & V_47 . V_48 ) ;
V_105 = F_15 ( V_2 , & V_47 , V_72 ) ;
break;
}
default:
return - V_9 ;
}
if ( V_105 )
F_11 ( V_5 , L_10 ) ;
return V_105 ;
}
static void F_59 ( struct V_4 * V_5 ,
unsigned char * V_128 , int V_62 , T_6 V_72 )
{
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_129 * V_2 = V_73 -> V_2 ;
switch ( V_2 -> V_121 . V_130 ) {
case V_131 : {
struct V_132 V_133 ;
T_1 V_134 [ 16 ] = { 0 } ;
V_133 . V_62 = V_62 ;
memcpy ( & V_134 [ 10 ] , V_128 , V_69 ) ;
V_134 [ 5 ] = V_5 -> V_55 ;
F_60 ( V_2 , & V_133 , V_134 , V_135 ) ;
break;
}
case V_136 : {
F_13 ( V_2 , V_72 ) ;
break;
}
default:
F_14 ( V_5 , L_11 ) ;
}
}
static int F_61 ( struct V_4 * V_5 )
{
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_129 * V_2 = V_73 -> V_2 ;
int V_138 = 0 ;
int V_105 = 0 ;
int * V_62 = & V_5 -> V_139 ;
T_6 V_128 = F_62 ( V_5 -> V_2 -> V_68 ) ;
F_44 ( V_127 , V_5 , L_12 ,
V_5 -> V_2 -> V_68 ) ;
V_138 = F_63 ( V_2 , V_5 -> V_55 , V_128 ) ;
if ( V_138 < 0 ) {
V_105 = V_138 ;
F_14 ( V_5 , L_13 ,
V_5 -> V_2 -> V_68 ) ;
return V_105 ;
}
if ( V_2 -> V_121 . V_130 == V_140 ) {
int V_139 = F_64 ( V_2 , V_5 -> V_55 ) ;
* V_62 = V_139 + V_138 ;
return 0 ;
}
V_105 = F_65 ( V_2 , 1 , 1 , V_62 , V_141 ) ;
F_44 ( V_127 , V_5 , L_14 , * V_62 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_15 ) ;
F_66 ( V_2 , V_5 -> V_55 , V_128 ) ;
return V_105 ;
}
return 0 ;
}
static void F_67 ( struct V_4 * V_5 )
{
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_129 * V_2 = V_73 -> V_2 ;
int V_62 = V_5 -> V_139 ;
if ( V_2 -> V_121 . V_130 == V_140 ) {
T_6 V_128 = F_62 ( V_5 -> V_2 -> V_68 ) ;
F_44 ( V_127 , V_5 , L_16 ,
V_5 -> V_2 -> V_68 ) ;
F_66 ( V_2 , V_5 -> V_55 , V_128 ) ;
} else {
F_44 ( V_127 , V_5 , L_17 ,
V_5 -> V_55 , V_62 ) ;
F_68 ( V_2 , V_62 , 1 ) ;
V_5 -> V_142 &= ~ V_143 ;
}
}
static int F_69 ( struct V_4 * V_5 , int V_62 ,
unsigned char * V_144 , unsigned char * V_145 )
{
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_129 * V_2 = V_73 -> V_2 ;
int V_105 = 0 ;
T_6 V_146 = F_62 ( V_144 ) ;
if ( V_2 -> V_121 . V_130 != V_140 ) {
struct V_75 * V_147 ;
unsigned int V_148 ;
struct V_149 * V_150 ;
struct V_151 * V_107 ;
T_6 V_152 = F_62 ( V_145 ) ;
V_147 = & V_5 -> V_148 [ V_145 [ V_153 ] ] ;
F_70 (entry, tmp, bucket, hlist) {
if ( F_71 ( V_150 -> V_128 , V_145 ) ) {
F_59 ( V_5 , V_150 -> V_128 ,
V_62 , V_150 -> V_72 ) ;
F_66 ( V_2 , V_5 -> V_55 ,
V_152 ) ;
F_72 ( & V_150 -> V_154 ) ;
F_73 () ;
memcpy ( V_150 -> V_128 , V_144 , V_69 ) ;
V_150 -> V_72 = 0 ;
V_148 = V_144 [ V_153 ] ;
F_74 ( & V_150 -> V_154 ,
& V_5 -> V_148 [ V_148 ] ) ;
F_63 ( V_2 , V_5 -> V_55 , V_146 ) ;
V_105 = F_56 ( V_5 , V_144 ,
& V_62 ,
& V_150 -> V_72 ) ;
if ( V_105 )
return V_105 ;
if ( V_5 -> V_155 ) {
F_13 ( V_5 -> V_73 -> V_2 , V_5 -> V_155 ) ;
V_5 -> V_155 = 0 ;
}
V_105 = F_54 ( V_5 , V_144 , V_62 ,
& V_5 -> V_155 ) ;
return V_105 ;
}
}
return - V_9 ;
}
return F_75 ( V_2 , V_5 -> V_55 , V_62 , V_146 ) ;
}
static int F_76 ( struct V_4 * V_5 ,
unsigned char V_144 [ V_69 + 2 ] )
{
int V_105 = 0 ;
if ( V_5 -> V_118 ) {
V_105 = F_69 ( V_5 , V_5 -> V_139 ,
V_144 , V_5 -> V_156 ) ;
if ( V_105 )
F_14 ( V_5 , L_18 ) ;
} else
F_44 ( V_114 , V_5 , L_19 ) ;
if ( ! V_105 )
memcpy ( V_5 -> V_156 , V_144 , sizeof( V_5 -> V_156 ) ) ;
return V_105 ;
}
static int F_77 ( struct V_1 * V_2 , void * V_120 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_157 * V_100 = V_120 ;
unsigned char V_144 [ V_69 + 2 ] ;
int V_105 ;
if ( ! F_78 ( V_100 -> V_158 ) )
return - V_159 ;
F_46 ( & V_73 -> V_116 ) ;
memcpy ( V_144 , V_100 -> V_158 , V_69 ) ;
V_105 = F_76 ( V_5 , V_144 ) ;
if ( ! V_105 )
memcpy ( V_2 -> V_68 , V_100 -> V_158 , V_69 ) ;
F_49 ( & V_73 -> V_116 ) ;
return V_105 ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_160 * V_107 , * V_161 ;
F_37 (mc_to_del, tmp, &priv->mc_list, list) {
F_24 ( & V_161 -> V_48 ) ;
F_25 ( V_161 ) ;
}
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_162 * V_163 ;
struct V_160 * V_107 ;
F_79 ( V_2 ) ;
F_81 (ha, dev) {
V_107 = F_20 ( sizeof( struct V_160 ) , V_81 ) ;
if ( ! V_107 ) {
F_79 ( V_2 ) ;
return;
}
memcpy ( V_107 -> V_120 , V_163 -> V_120 , V_69 ) ;
F_12 ( & V_107 -> V_48 , & V_5 -> V_164 ) ;
}
}
static void F_82 ( struct V_4 * V_5 ,
struct V_165 * V_166 ,
struct V_165 * V_167 )
{
struct V_160 * V_168 , * V_169 , * V_170 ;
bool V_171 ;
F_83 (dst_tmp, dst, list) {
V_171 = false ;
F_83 (src_tmp, src, list) {
if ( F_84 ( V_168 -> V_120 , V_169 -> V_120 ) ) {
V_171 = true ;
break;
}
}
if ( ! V_171 )
V_168 -> V_172 = V_173 ;
}
F_83 (src_tmp, src, list) {
V_171 = false ;
F_83 (dst_tmp, dst, list) {
if ( F_84 ( V_168 -> V_120 , V_169 -> V_120 ) ) {
V_168 -> V_172 = V_174 ;
V_171 = true ;
break;
}
}
if ( ! V_171 ) {
V_170 = F_85 ( V_169 ,
sizeof( struct V_160 ) ,
V_175 ) ;
if ( ! V_170 )
return;
V_170 -> V_172 = V_176 ;
F_12 ( & V_170 -> V_48 , V_166 ) ;
}
}
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_118 )
return;
F_33 ( V_5 -> V_73 -> V_106 , & V_5 -> V_177 ) ;
}
static void F_87 ( struct V_4 * V_5 ,
struct V_112 * V_73 )
{
int V_105 = 0 ;
if ( ! ( V_5 -> V_142 & V_178 ) ) {
if ( F_88 ( V_5 ) )
F_11 ( V_5 , L_20 ) ;
V_5 -> V_142 |= V_178 ;
switch ( V_73 -> V_2 -> V_121 . V_130 ) {
case V_136 :
V_105 = F_89 ( V_73 -> V_2 ,
V_5 -> V_55 ,
V_5 -> V_139 ,
V_179 ) ;
if ( V_105 )
F_14 ( V_5 , L_21 ) ;
V_5 -> V_142 |= V_180 ;
break;
case V_131 :
V_105 = F_90 ( V_73 -> V_2 ,
V_5 -> V_139 ,
V_5 -> V_55 ) ;
if ( V_105 )
F_14 ( V_5 , L_22 ) ;
if ( ! ( V_5 -> V_142 & V_180 ) ) {
V_105 = F_91 ( V_73 -> V_2 ,
V_5 -> V_139 ,
V_5 -> V_55 ) ;
if ( V_105 )
F_14 ( V_5 , L_23 ) ;
V_5 -> V_142 |= V_180 ;
}
break;
case V_140 :
V_105 = F_92 ( V_73 -> V_2 ,
V_5 -> V_55 ,
V_5 -> V_139 ,
1 ) ;
if ( V_105 )
F_14 ( V_5 , L_21 ) ;
break;
}
V_105 = F_93 ( V_73 -> V_2 , V_5 -> V_55 , 0 ,
0 , V_181 ) ;
if ( V_105 )
F_14 ( V_5 , L_24 ) ;
}
}
static void F_94 ( struct V_4 * V_5 ,
struct V_112 * V_73 )
{
int V_105 = 0 ;
if ( F_88 ( V_5 ) )
F_11 ( V_5 , L_25 ) ;
V_5 -> V_142 &= ~ V_178 ;
switch ( V_73 -> V_2 -> V_121 . V_130 ) {
case V_136 :
V_105 = F_95 ( V_73 -> V_2 ,
V_5 -> V_55 ,
V_179 ) ;
if ( V_105 )
F_14 ( V_5 , L_26 ) ;
V_5 -> V_142 &= ~ V_180 ;
break;
case V_131 :
V_105 = F_96 ( V_73 -> V_2 ,
V_5 -> V_139 ,
V_5 -> V_55 ) ;
if ( V_105 )
F_14 ( V_5 , L_27 ) ;
if ( V_5 -> V_142 & V_180 ) {
V_105 = F_97 ( V_73 -> V_2 ,
V_5 -> V_139 ,
V_5 -> V_55 ) ;
if ( V_105 )
F_14 ( V_5 , L_28 ) ;
V_5 -> V_142 &= ~ V_180 ;
}
break;
case V_140 :
V_105 = F_92 ( V_73 -> V_2 ,
V_5 -> V_55 ,
V_5 -> V_139 , 0 ) ;
if ( V_105 )
F_14 ( V_5 , L_26 ) ;
break;
}
}
static void F_98 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_112 * V_73 )
{
struct V_160 * V_182 , * V_107 ;
T_6 V_183 = 0 ;
T_1 V_164 [ 16 ] = { 0 } ;
int V_105 = 0 ;
if ( V_2 -> V_142 & V_184 ) {
V_105 = F_93 ( V_73 -> V_2 , V_5 -> V_55 , 0 ,
0 , V_181 ) ;
if ( V_105 )
F_14 ( V_5 , L_24 ) ;
if ( ! ( V_5 -> V_142 & V_180 ) ) {
switch ( V_73 -> V_2 -> V_121 . V_130 ) {
case V_136 :
V_105 = F_89 ( V_73 -> V_2 ,
V_5 -> V_55 ,
V_5 -> V_139 ,
V_185 ) ;
break;
case V_131 :
V_105 = F_91 ( V_73 -> V_2 ,
V_5 -> V_139 ,
V_5 -> V_55 ) ;
break;
case V_140 :
break;
}
if ( V_105 )
F_14 ( V_5 , L_29 ) ;
V_5 -> V_142 |= V_180 ;
}
} else {
if ( V_5 -> V_142 & V_180 ) {
switch ( V_73 -> V_2 -> V_121 . V_130 ) {
case V_136 :
V_105 = F_95 ( V_73 -> V_2 ,
V_5 -> V_55 ,
V_185 ) ;
break;
case V_131 :
V_105 = F_97 ( V_73 -> V_2 ,
V_5 -> V_139 ,
V_5 -> V_55 ) ;
break;
case V_140 :
break;
}
if ( V_105 )
F_14 ( V_5 , L_28 ) ;
V_5 -> V_142 &= ~ V_180 ;
}
V_105 = F_93 ( V_73 -> V_2 , V_5 -> V_55 , 0 ,
0 , V_181 ) ;
if ( V_105 )
F_14 ( V_5 , L_24 ) ;
F_93 ( V_73 -> V_2 , V_5 -> V_55 , V_186 ,
1 , V_187 ) ;
F_99 ( V_2 ) ;
F_80 ( V_2 ) ;
F_100 ( V_2 ) ;
F_83 (mclist, &priv->mc_list, list) {
V_183 = F_62 ( V_182 -> V_120 ) ;
F_93 ( V_73 -> V_2 , V_5 -> V_55 ,
V_183 , 0 , V_187 ) ;
}
V_105 = F_93 ( V_73 -> V_2 , V_5 -> V_55 , 0 ,
0 , V_188 ) ;
if ( V_105 )
F_14 ( V_5 , L_30 ) ;
F_82 ( V_5 , & V_5 -> V_189 , & V_5 -> V_164 ) ;
F_37 (mclist, tmp, &priv->curr_list, list) {
if ( V_182 -> V_172 == V_173 ) {
memcpy ( & V_164 [ 10 ] , V_182 -> V_120 , V_69 ) ;
V_164 [ 5 ] = V_5 -> V_55 ;
V_105 = F_101 ( V_73 -> V_2 ,
& V_5 -> V_63 . V_190 ,
V_164 ,
V_135 ,
V_182 -> V_72 ) ;
if ( V_105 )
F_14 ( V_5 , L_31 ) ;
if ( V_182 -> V_155 ) {
V_105 = F_13 ( V_5 -> V_73 -> V_2 , V_182 -> V_155 ) ;
if ( V_105 )
F_14 ( V_5 , L_32 ) ;
}
F_24 ( & V_182 -> V_48 ) ;
F_25 ( V_182 ) ;
} else if ( V_182 -> V_172 == V_176 ) {
memcpy ( & V_164 [ 10 ] , V_182 -> V_120 , V_69 ) ;
V_164 [ 5 ] = V_5 -> V_55 ;
V_105 = F_102 ( V_73 -> V_2 ,
& V_5 -> V_63 . V_190 ,
V_164 ,
V_5 -> V_55 , 0 ,
V_135 ,
& V_182 -> V_72 ) ;
if ( V_105 )
F_14 ( V_5 , L_33 ) ;
V_105 = F_54 ( V_5 , & V_164 [ 10 ] , V_5 -> V_139 ,
& V_182 -> V_155 ) ;
if ( V_105 )
F_14 ( V_5 , L_34 ) ;
}
}
}
}
static void F_103 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_112 * V_73 )
{
struct V_162 * V_163 ;
struct V_149 * V_150 ;
struct V_151 * V_107 ;
bool V_171 ;
T_6 V_128 ;
int V_105 = 0 ;
struct V_75 * V_147 ;
unsigned int V_6 ;
int V_191 = 0 ;
T_2 V_192 ;
for ( V_6 = 0 ; V_6 < V_193 ; ++ V_6 ) {
V_147 = & V_5 -> V_148 [ V_6 ] ;
F_70 (entry, tmp, bucket, hlist) {
V_171 = false ;
F_104 (ha, dev) {
if ( F_71 ( V_150 -> V_128 ,
V_163 -> V_120 ) ) {
V_171 = true ;
break;
}
}
if ( F_71 ( V_150 -> V_128 ,
V_5 -> V_156 ) )
V_171 = true ;
if ( ! V_171 ) {
V_128 = F_62 ( V_150 -> V_128 ) ;
F_59 ( V_5 , V_150 -> V_128 ,
V_5 -> V_139 ,
V_150 -> V_72 ) ;
F_66 ( V_73 -> V_2 , V_5 -> V_55 , V_128 ) ;
F_72 ( & V_150 -> V_154 ) ;
F_105 ( V_150 , V_194 ) ;
F_44 ( V_127 , V_5 , L_35 ,
V_150 -> V_128 , V_5 -> V_55 ) ;
++ V_191 ;
}
}
}
if ( ( V_5 -> V_142 & V_143 ) && 0 == V_191 )
return;
V_192 = V_5 -> V_142 ;
V_5 -> V_142 &= ~ V_143 ;
F_104 (ha, dev) {
V_171 = false ;
V_147 = & V_5 -> V_148 [ V_163 -> V_120 [ V_153 ] ] ;
F_27 (entry, bucket, hlist) {
if ( F_71 ( V_150 -> V_128 , V_163 -> V_120 ) ) {
V_171 = true ;
break;
}
}
if ( ! V_171 ) {
V_150 = F_106 ( sizeof( * V_150 ) , V_175 ) ;
if ( ! V_150 ) {
F_14 ( V_5 , L_36 ,
V_163 -> V_120 , V_5 -> V_55 ) ;
V_5 -> V_142 |= V_143 ;
break;
}
V_128 = F_62 ( V_163 -> V_120 ) ;
memcpy ( V_150 -> V_128 , V_163 -> V_120 , V_69 ) ;
V_105 = F_63 ( V_73 -> V_2 , V_5 -> V_55 , V_128 ) ;
if ( V_105 < 0 ) {
F_14 ( V_5 , L_37 ,
V_163 -> V_120 , V_5 -> V_55 , V_105 ) ;
F_25 ( V_150 ) ;
V_5 -> V_142 |= V_143 ;
break;
}
V_105 = F_56 ( V_5 , V_163 -> V_120 ,
& V_5 -> V_139 ,
& V_150 -> V_72 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_38 ,
V_163 -> V_120 , V_5 -> V_55 , V_105 ) ;
F_66 ( V_73 -> V_2 , V_5 -> V_55 , V_128 ) ;
F_25 ( V_150 ) ;
V_5 -> V_142 |= V_143 ;
break;
} else {
unsigned int V_148 ;
F_44 ( V_127 , V_5 , L_39 ,
V_163 -> V_120 , V_5 -> V_55 ) ;
V_148 = V_163 -> V_120 [ V_153 ] ;
V_147 = & V_5 -> V_148 [ V_148 ] ;
F_74 ( & V_150 -> V_154 , V_147 ) ;
}
}
}
if ( V_5 -> V_142 & V_143 ) {
F_11 ( V_5 , L_40 ,
V_5 -> V_55 ) ;
} else if ( V_192 & V_143 ) {
F_11 ( V_5 , L_41 ,
V_5 -> V_55 ) ;
}
}
static void F_107 ( struct V_23 * V_24 )
{
struct V_4 * V_5 = F_8 ( V_24 , struct V_4 ,
V_177 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_46 ( & V_73 -> V_116 ) ;
if ( ! V_73 -> V_117 ) {
F_44 ( V_114 , V_5 , L_42 ) ;
goto V_103;
}
if ( ! V_5 -> V_118 ) {
F_44 ( V_114 , V_5 , L_43 ) ;
goto V_103;
}
if ( ! F_108 ( V_2 ) ) {
if ( ! F_109 ( V_73 , V_5 -> V_55 ) ) {
if ( V_5 -> V_195 . V_196 ) {
V_5 -> V_197 = V_198 ;
F_110 ( V_2 ) ;
F_44 ( V_199 , V_5 , L_44 ) ;
}
}
}
if ( V_2 -> V_200 & V_201 )
F_103 ( V_5 , V_2 , V_73 ) ;
if ( ( V_2 -> V_142 & V_202 ) ||
( V_5 -> V_142 & V_143 ) ) {
F_87 ( V_5 , V_73 ) ;
goto V_103;
}
if ( V_5 -> V_142 & V_178 )
F_94 ( V_5 , V_73 ) ;
F_98 ( V_5 , V_2 , V_73 ) ;
V_103:
F_49 ( & V_73 -> V_116 ) ;
}
static void F_111 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_203 * V_204 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
V_204 = V_5 -> V_206 [ V_6 ] ;
F_112 ( & V_204 -> V_207 ) ;
}
}
static int F_113 ( struct V_4 * V_5 )
{
T_6 V_72 ;
int V_105 = 0 ;
int * V_62 = & V_5 -> V_139 ;
struct V_149 * V_150 ;
V_105 = F_56 ( V_5 , V_5 -> V_2 -> V_68 , V_62 , & V_72 ) ;
if ( V_105 )
return V_105 ;
V_105 = F_54 ( V_5 , V_5 -> V_2 -> V_68 , * V_62 ,
& V_5 -> V_155 ) ;
if ( V_105 )
goto V_208;
V_150 = F_106 ( sizeof( * V_150 ) , V_175 ) ;
if ( ! V_150 ) {
V_105 = - V_104 ;
goto V_209;
}
memcpy ( V_150 -> V_128 , V_5 -> V_2 -> V_68 , sizeof( V_150 -> V_128 ) ) ;
memcpy ( V_5 -> V_156 , V_150 -> V_128 , sizeof( V_5 -> V_156 ) ) ;
V_150 -> V_72 = V_72 ;
F_74 ( & V_150 -> V_154 ,
& V_5 -> V_148 [ V_150 -> V_128 [ V_153 ] ] ) ;
return 0 ;
V_209:
if ( V_5 -> V_155 )
F_13 ( V_5 -> V_73 -> V_2 , V_5 -> V_155 ) ;
V_208:
F_59 ( V_5 , V_5 -> V_2 -> V_68 , * V_62 , V_72 ) ;
return V_105 ;
}
static void F_114 ( struct V_4 * V_5 )
{
T_6 V_128 ;
unsigned int V_6 ;
int V_62 = V_5 -> V_139 ;
struct V_75 * V_147 ;
struct V_151 * V_107 ;
struct V_149 * V_150 ;
for ( V_6 = 0 ; V_6 < V_193 ; ++ V_6 ) {
V_147 = & V_5 -> V_148 [ V_6 ] ;
F_70 (entry, tmp, bucket, hlist) {
V_128 = F_62 ( V_150 -> V_128 ) ;
F_44 ( V_127 , V_5 , L_45 ,
V_150 -> V_128 ) ;
F_59 ( V_5 , V_150 -> V_128 ,
V_62 , V_150 -> V_72 ) ;
F_66 ( V_5 -> V_73 -> V_2 , V_5 -> V_55 , V_128 ) ;
F_72 ( & V_150 -> V_154 ) ;
F_105 ( V_150 , V_194 ) ;
}
}
if ( V_5 -> V_155 ) {
F_13 ( V_5 -> V_73 -> V_2 , V_5 -> V_155 ) ;
V_5 -> V_155 = 0 ;
}
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
int V_6 ;
if ( F_116 ( V_5 ) )
F_11 ( V_5 , L_46 , V_5 -> V_55 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
if ( ! F_117 ( F_118 ( V_2 , V_6 ) ) )
continue;
F_11 ( V_5 , L_47 ,
V_6 , V_5 -> V_211 [ V_6 ] -> V_62 , V_5 -> V_211 [ V_6 ] -> V_212 ,
V_5 -> V_211 [ V_6 ] -> V_213 , V_5 -> V_211 [ V_6 ] -> V_214 ) ;
}
V_5 -> V_215 . V_216 ++ ;
F_44 ( V_127 , V_5 , L_48 ) ;
F_33 ( V_73 -> V_106 , & V_5 -> V_217 ) ;
}
static struct V_218 * F_119 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_32 ( & V_5 -> V_219 ) ;
memcpy ( & V_5 -> V_220 , & V_5 -> V_221 , sizeof( V_5 -> V_221 ) ) ;
F_34 ( & V_5 -> V_219 ) ;
return & V_5 -> V_220 ;
}
static void F_120 ( struct V_4 * V_5 )
{
struct V_203 * V_204 ;
int V_6 ;
V_5 -> V_222 = V_223 ;
V_5 -> V_224 = V_225 ;
V_5 -> V_226 = V_227 ;
V_5 -> V_228 = V_229 ;
F_44 ( V_230 , V_5 , L_49 ,
V_5 -> V_2 -> V_231 , V_5 -> V_222 , V_5 -> V_224 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
V_204 = V_5 -> V_206 [ V_6 ] ;
V_204 -> V_232 = V_5 -> V_222 ;
V_204 -> V_233 = V_5 -> V_224 ;
V_5 -> V_234 [ V_6 ] = V_235 ;
V_5 -> V_236 [ V_6 ] = 0 ;
V_5 -> V_237 [ V_6 ] = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
V_204 = V_5 -> V_238 [ V_6 ] ;
V_204 -> V_232 = V_5 -> V_226 ;
V_204 -> V_233 = V_5 -> V_228 ;
}
V_5 -> V_239 = V_240 ;
V_5 -> V_241 = V_242 ;
V_5 -> V_243 = V_244 ;
V_5 -> V_245 = V_246 ;
V_5 -> V_247 = V_248 ;
V_5 -> V_249 = 1 ;
V_5 -> V_250 = 0 ;
V_5 -> V_251 = 0 ;
}
static void F_121 ( struct V_4 * V_5 )
{
unsigned long V_252 = ( unsigned long ) ( V_253 - V_5 -> V_250 ) ;
struct V_203 * V_204 ;
unsigned long V_254 ;
unsigned long V_255 ;
unsigned long V_256 ;
unsigned long V_257 ;
unsigned long V_258 ;
unsigned long V_259 ;
int V_233 ;
int V_260 , V_105 ;
if ( ! V_5 -> V_249 || V_252 < V_5 -> V_247 * V_261 )
return;
for ( V_260 = 0 ; V_260 < V_5 -> V_205 ; V_260 ++ ) {
F_32 ( & V_5 -> V_219 ) ;
V_257 = V_5 -> V_262 [ V_260 ] -> V_254 ;
V_258 = V_5 -> V_262 [ V_260 ] -> V_263 ;
F_34 ( & V_5 -> V_219 ) ;
V_259 = ( ( unsigned long ) ( V_257 -
V_5 -> V_236 [ V_260 ] ) ) ;
V_254 = V_259 ;
V_255 = V_254 * V_261 / V_252 ;
V_256 = V_254 ? ( ( unsigned long ) ( V_258 -
V_5 -> V_237 [ V_260 ] ) ) / V_254 : 0 ;
if ( V_255 > ( V_264 / V_5 -> V_205 ) &&
V_256 > V_265 ) {
if ( V_255 < V_5 -> V_239 )
V_233 = V_5 -> V_241 ;
else if ( V_255 > V_5 -> V_243 )
V_233 = V_5 -> V_245 ;
else
V_233 = ( V_255 - V_5 -> V_239 ) *
( V_5 -> V_245 - V_5 -> V_241 ) /
( V_5 -> V_243 - V_5 -> V_239 ) +
V_5 -> V_241 ;
} else {
V_233 = V_5 -> V_241 ;
}
if ( V_233 != V_5 -> V_234 [ V_260 ] ) {
V_5 -> V_234 [ V_260 ] = V_233 ;
V_204 = V_5 -> V_206 [ V_260 ] ;
V_204 -> V_233 = V_233 ;
V_204 -> V_232 = V_5 -> V_222 ;
V_105 = F_122 ( V_5 , V_204 ) ;
if ( V_105 )
F_14 ( V_5 , L_50 ,
V_260 ) ;
}
V_5 -> V_236 [ V_260 ] = V_257 ;
V_5 -> V_237 [ V_260 ] = V_258 ;
}
V_5 -> V_250 = V_253 ;
}
static void F_123 ( struct V_23 * V_24 )
{
struct V_266 * V_267 = F_124 ( V_24 ) ;
struct V_4 * V_5 = F_8 ( V_267 , struct V_4 ,
V_268 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
int V_105 ;
F_46 ( & V_73 -> V_116 ) ;
if ( V_73 -> V_117 ) {
if ( V_5 -> V_118 ) {
V_105 = F_125 ( V_73 , V_5 -> V_55 , 0 ) ;
if ( V_105 )
F_44 ( V_114 , V_5 , L_51 ) ;
F_121 ( V_5 ) ;
}
F_126 ( V_73 -> V_106 , & V_5 -> V_268 , V_269 ) ;
}
if ( V_73 -> V_270 [ V_271 + 1 - V_5 -> V_55 ] ) {
F_76 ( V_5 , V_5 -> V_156 ) ;
V_73 -> V_270 [ V_271 + 1 - V_5 -> V_55 ] = 0 ;
}
F_49 ( & V_73 -> V_116 ) ;
}
static void F_127 ( struct V_23 * V_24 )
{
struct V_266 * V_267 = F_124 ( V_24 ) ;
struct V_4 * V_5 = F_8 ( V_267 , struct V_4 ,
V_272 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
F_46 ( & V_73 -> V_116 ) ;
if ( V_73 -> V_117 ) {
if ( V_73 -> V_2 -> V_121 . V_273 & V_274 )
F_128 ( V_73 ) ;
F_129 ( V_5 ) ;
F_126 ( V_73 -> V_106 , & V_5 -> V_272 ,
V_275 ) ;
}
F_49 ( & V_73 -> V_116 ) ;
}
static void F_130 ( struct V_23 * V_24 )
{
struct V_4 * V_5 = F_8 ( V_24 , struct V_4 ,
V_276 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
int V_277 = V_5 -> V_196 ;
F_46 ( & V_73 -> V_116 ) ;
if ( V_5 -> V_197 != V_277 ) {
if ( V_277 == V_278 ) {
F_131 ( V_5 , L_52 ) ;
F_132 ( V_5 -> V_2 ) ;
} else {
F_131 ( V_5 , L_44 ) ;
F_110 ( V_5 -> V_2 ) ;
}
}
V_5 -> V_197 = V_277 ;
F_49 ( & V_73 -> V_116 ) ;
}
static int F_133 ( struct V_4 * V_5 , int V_279 )
{
struct V_280 * V_260 = V_5 -> V_262 [ V_279 ] ;
int V_281 = V_5 -> V_73 -> V_2 -> V_281 ;
if ( ! F_134 ( & V_260 -> V_282 , V_175 ) )
return - V_104 ;
F_135 ( F_136 ( V_279 , V_281 ) ,
V_260 -> V_282 ) ;
return 0 ;
}
static void F_137 ( struct V_4 * V_5 , int V_279 )
{
F_138 ( V_5 -> V_262 [ V_279 ] -> V_282 ) ;
}
int F_139 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_203 * V_204 ;
struct V_283 * V_211 ;
int V_284 = 0 ;
int V_285 = 0 ;
int V_105 = 0 ;
int V_6 ;
int V_286 ;
T_1 V_164 [ 16 ] = { 0 } ;
if ( V_5 -> V_118 ) {
F_44 ( V_127 , V_5 , L_53 ) ;
return 0 ;
}
F_58 ( & V_5 -> V_164 ) ;
F_58 ( & V_5 -> V_189 ) ;
F_58 ( & V_5 -> V_287 ) ;
memset ( & V_5 -> V_288 [ 0 ] , 0 ,
sizeof( struct V_289 ) * V_290 ) ;
V_2 -> V_231 = F_140 ( V_2 -> V_231 , V_5 -> V_291 ) ;
F_141 ( V_2 ) ;
F_44 ( V_127 , V_5 , L_54 , V_5 -> V_292 ) ;
V_105 = F_142 ( V_5 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_55 ) ;
return V_105 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
V_204 = V_5 -> V_206 [ V_6 ] ;
V_105 = F_133 ( V_5 , V_6 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_56 ) ;
goto V_293;
}
V_105 = F_143 ( V_5 , V_204 , V_6 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_57 ) ;
F_137 ( V_5 , V_6 ) ;
goto V_293;
}
for ( V_286 = 0 ; V_286 < V_204 -> V_294 ; V_286 ++ ) {
struct V_295 * V_296 = NULL ;
V_296 = F_144 ( V_204 -> V_297 , V_286 , V_5 -> V_298 ) +
V_5 -> V_299 ;
V_296 -> V_300 = V_301 ;
}
V_105 = F_122 ( V_5 , V_204 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_58 ) ;
F_145 ( V_5 , V_204 ) ;
F_137 ( V_5 , V_6 ) ;
goto V_293;
}
F_146 ( V_5 , V_204 ) ;
V_5 -> V_262 [ V_6 ] -> V_212 = V_204 -> V_302 . V_212 ;
++ V_284 ;
}
F_44 ( V_127 , V_5 , L_59 , V_5 -> V_55 ) ;
V_105 = F_61 ( V_5 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_60 ) ;
goto V_293;
}
V_73 -> V_270 [ V_5 -> V_55 ] = 0 ;
V_5 -> V_303 =
F_147 ( V_73 -> V_2 , V_5 -> V_55 ) ;
V_105 = F_148 ( V_5 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_61 ) ;
goto V_304;
}
V_105 = F_149 ( V_5 ) ;
if ( V_105 )
goto V_305;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
V_204 = V_5 -> V_238 [ V_6 ] ;
V_105 = F_143 ( V_5 , V_204 , V_6 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_62 ) ;
goto V_306;
}
V_105 = F_122 ( V_5 , V_204 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_58 ) ;
F_145 ( V_5 , V_204 ) ;
goto V_306;
}
F_44 ( V_127 , V_5 , L_63 , V_6 ) ;
V_204 -> V_297 -> V_307 = F_150 ( 0xffff ) ;
V_211 = V_5 -> V_211 [ V_6 ] ;
V_105 = F_151 ( V_5 , V_211 , V_204 -> V_302 . V_212 ,
V_6 / V_5 -> V_10 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_64 ) ;
F_145 ( V_5 , V_204 ) ;
goto V_306;
}
V_211 -> V_308 = F_118 ( V_2 , V_6 ) ;
F_146 ( V_5 , V_204 ) ;
for ( V_286 = 0 ; V_286 < V_211 -> V_309 ; V_286 += V_310 )
* ( ( T_2 * ) ( V_211 -> V_297 + V_286 ) ) = 0xffffffff ;
++ V_285 ;
}
V_105 = F_152 ( V_73 -> V_2 , V_5 -> V_55 ,
V_5 -> V_292 + V_311 ,
V_5 -> V_312 -> V_313 ,
V_5 -> V_312 -> V_314 ,
V_5 -> V_312 -> V_315 ,
V_5 -> V_312 -> V_316 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_65 ,
V_5 -> V_55 , V_105 ) ;
goto V_306;
}
V_105 = F_92 ( V_73 -> V_2 , V_5 -> V_55 , V_5 -> V_139 , 0 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_66 ) ;
goto V_306;
}
if ( V_73 -> V_2 -> V_121 . V_122 == V_123 ) {
V_105 = F_153 ( V_73 -> V_2 , V_5 -> V_55 , V_317 , 1 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_67 ,
V_105 ) ;
goto V_306;
}
}
F_44 ( V_114 , V_5 , L_68 ) ;
V_105 = F_154 ( V_73 -> V_2 , V_5 -> V_55 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_69 ) ;
goto V_306;
}
if ( V_73 -> V_2 -> V_121 . V_130 != V_140 &&
F_113 ( V_5 ) )
F_155 ( V_73 , L_70 ) ;
F_156 ( & V_164 [ 10 ] ) ;
V_164 [ 5 ] = V_5 -> V_55 ;
if ( F_102 ( V_73 -> V_2 , & V_5 -> V_63 . V_190 , V_164 ,
V_5 -> V_55 , 0 , V_135 ,
& V_5 -> V_318 ) )
F_155 ( V_73 , L_71 ) ;
V_5 -> V_142 &= ~ ( V_178 | V_180 ) ;
F_33 ( V_73 -> V_106 , & V_5 -> V_177 ) ;
#ifdef F_157
if ( V_5 -> V_73 -> V_2 -> V_121 . V_122 == V_123 )
F_158 ( V_2 ) ;
#endif
V_5 -> V_118 = true ;
F_159 ( V_2 ) ;
F_160 ( V_2 ) ;
return 0 ;
V_306:
while ( V_285 -- ) {
F_161 ( V_5 , V_5 -> V_211 [ V_285 ] ) ;
F_145 ( V_5 , V_5 -> V_238 [ V_285 ] ) ;
}
F_162 ( V_5 ) ;
V_305:
F_163 ( V_5 ) ;
V_304:
F_67 ( V_5 ) ;
V_293:
while ( V_284 -- ) {
F_145 ( V_5 , V_5 -> V_206 [ V_284 ] ) ;
F_137 ( V_5 , V_284 ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ )
F_164 ( V_5 , V_5 -> V_262 [ V_6 ] ) ;
return V_105 ;
}
void F_165 ( struct V_1 * V_2 , int V_319 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_160 * V_182 , * V_107 ;
struct V_289 * V_320 , * V_321 ;
int V_6 ;
T_1 V_164 [ 16 ] = { 0 } ;
if ( ! V_5 -> V_118 ) {
F_44 ( V_127 , V_5 , L_72 ) ;
return;
}
F_166 ( V_73 -> V_2 , V_5 -> V_55 ) ;
F_167 ( V_2 ) ;
if ( V_319 )
F_168 ( V_2 ) ;
F_169 ( V_2 ) ;
F_170 ( V_2 ) ;
F_171 ( V_2 ) ;
V_5 -> V_118 = false ;
V_5 -> V_303 = F_172 ( V_73 -> V_2 ) ;
if ( V_73 -> V_2 -> V_121 . V_130 ==
V_136 ) {
V_5 -> V_142 &= ~ ( V_178 |
V_180 ) ;
F_95 ( V_73 -> V_2 ,
V_5 -> V_55 ,
V_179 ) ;
F_95 ( V_73 -> V_2 ,
V_5 -> V_55 ,
V_185 ) ;
} else if ( V_5 -> V_142 & V_178 ) {
V_5 -> V_142 &= ~ V_178 ;
F_96 ( V_73 -> V_2 , V_5 -> V_139 ,
V_5 -> V_55 ) ;
if ( V_5 -> V_142 & V_180 ) {
F_97 ( V_73 -> V_2 , V_5 -> V_139 ,
V_5 -> V_55 ) ;
V_5 -> V_142 &= ~ V_180 ;
}
}
F_156 ( & V_164 [ 10 ] ) ;
V_164 [ 5 ] = V_5 -> V_55 ;
F_101 ( V_73 -> V_2 , & V_5 -> V_63 . V_190 , V_164 ,
V_135 , V_5 -> V_318 ) ;
F_83 (mclist, &priv->curr_list, list) {
memcpy ( & V_164 [ 10 ] , V_182 -> V_120 , V_69 ) ;
V_164 [ 5 ] = V_5 -> V_55 ;
F_101 ( V_73 -> V_2 , & V_5 -> V_63 . V_190 ,
V_164 , V_135 , V_182 -> V_72 ) ;
if ( V_182 -> V_155 )
F_13 ( V_73 -> V_2 , V_182 -> V_155 ) ;
}
F_79 ( V_2 ) ;
F_37 (mclist, tmp, &priv->curr_list, list) {
F_24 ( & V_182 -> V_48 ) ;
F_25 ( V_182 ) ;
}
F_93 ( V_73 -> V_2 , V_5 -> V_55 , 0 , 1 , V_187 ) ;
if ( V_73 -> V_2 -> V_121 . V_130 ==
V_136 ) {
F_173 () ;
F_37 (flow, tmp_flow,
&priv->ethtool_list, list) {
F_13 ( V_73 -> V_2 , V_320 -> V_29 ) ;
F_24 ( & V_320 -> V_48 ) ;
}
}
F_162 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
F_161 ( V_5 , V_5 -> V_211 [ V_6 ] ) ;
F_145 ( V_5 , V_5 -> V_238 [ V_6 ] ) ;
}
F_174 ( 10 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ )
F_175 ( V_2 , V_5 -> V_211 [ V_6 ] ) ;
if ( V_73 -> V_2 -> V_121 . V_130 != V_140 )
F_114 ( V_5 ) ;
F_163 ( V_5 ) ;
F_67 ( V_5 ) ;
if ( ! ( V_73 -> V_2 -> V_121 . V_273 & V_322 ) )
V_73 -> V_270 [ V_5 -> V_55 ] = 1 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
struct V_203 * V_204 = V_5 -> V_206 [ V_6 ] ;
F_176 ( & V_204 -> V_207 ) ;
F_164 ( V_5 , V_5 -> V_262 [ V_6 ] ) ;
F_145 ( V_5 , V_204 ) ;
F_137 ( V_5 , V_6 ) ;
}
}
static void F_177 ( struct V_23 * V_24 )
{
struct V_4 * V_5 = F_8 ( V_24 , struct V_4 ,
V_217 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_44 ( V_127 , V_5 , L_73 , V_5 -> V_55 ) ;
F_46 ( & V_73 -> V_116 ) ;
if ( V_5 -> V_118 ) {
F_165 ( V_2 , 1 ) ;
if ( F_139 ( V_2 ) )
F_14 ( V_5 , L_74 , V_5 -> V_55 ) ;
}
F_49 ( & V_73 -> V_116 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
int V_6 ;
if ( F_125 ( V_73 , V_5 -> V_55 , 1 ) )
F_44 ( V_114 , V_5 , L_75 ) ;
memset ( & V_5 -> V_221 , 0 , sizeof( V_5 -> V_221 ) ) ;
memset ( & V_5 -> V_323 , 0 , sizeof( V_5 -> V_323 ) ) ;
memset ( & V_5 -> V_324 , 0 , sizeof( V_5 -> V_324 ) ) ;
memset ( & V_5 -> V_215 , 0 , sizeof( V_5 -> V_215 ) ) ;
memset ( & V_5 -> V_325 , 0 , sizeof( V_5 -> V_325 ) ) ;
memset ( & V_5 -> V_326 , 0 , sizeof( V_5 -> V_326 ) ) ;
memset ( & V_5 -> V_327 , 0 ,
sizeof( V_5 -> V_327 ) ) ;
memset ( & V_5 -> V_328 , 0 ,
sizeof( V_5 -> V_328 ) ) ;
memset ( & V_5 -> V_329 , 0 , sizeof( V_5 -> V_329 ) ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
V_5 -> V_211 [ V_6 ] -> V_263 = 0 ;
V_5 -> V_211 [ V_6 ] -> V_254 = 0 ;
V_5 -> V_211 [ V_6 ] -> V_330 = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
V_5 -> V_262 [ V_6 ] -> V_263 = 0 ;
V_5 -> V_262 [ V_6 ] -> V_254 = 0 ;
V_5 -> V_262 [ V_6 ] -> V_331 = 0 ;
V_5 -> V_262 [ V_6 ] -> V_332 = 0 ;
V_5 -> V_262 [ V_6 ] -> V_333 = 0 ;
}
}
static int F_179 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
int V_105 = 0 ;
F_46 ( & V_73 -> V_116 ) ;
if ( ! V_73 -> V_117 ) {
F_14 ( V_5 , L_76 ) ;
V_105 = - V_334 ;
goto V_103;
}
F_178 ( V_2 ) ;
V_105 = F_139 ( V_2 ) ;
if ( V_105 )
F_14 ( V_5 , L_77 , V_5 -> V_55 ) ;
V_103:
F_49 ( & V_73 -> V_116 ) ;
return V_105 ;
}
static int F_180 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
F_44 ( V_335 , V_5 , L_78 ) ;
F_46 ( & V_73 -> V_116 ) ;
F_165 ( V_2 , 0 ) ;
F_132 ( V_2 ) ;
F_49 ( & V_73 -> V_116 ) ;
return 0 ;
}
void F_181 ( struct V_4 * V_5 )
{
int V_6 ;
#ifdef F_182
V_5 -> V_2 -> V_336 = NULL ;
#endif
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
if ( V_5 -> V_211 && V_5 -> V_211 [ V_6 ] )
F_183 ( V_5 , & V_5 -> V_211 [ V_6 ] ) ;
if ( V_5 -> V_238 && V_5 -> V_238 [ V_6 ] )
F_184 ( V_5 , & V_5 -> V_238 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
if ( V_5 -> V_262 [ V_6 ] )
F_185 ( V_5 , & V_5 -> V_262 [ V_6 ] ,
V_5 -> V_312 -> V_337 , V_5 -> V_338 ) ;
if ( V_5 -> V_206 [ V_6 ] )
F_184 ( V_5 , & V_5 -> V_206 [ V_6 ] ) ;
}
}
int F_186 ( struct V_4 * V_5 )
{
struct V_339 * V_312 = V_5 -> V_312 ;
int V_6 ;
int V_340 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
V_340 = F_187 ( V_6 % F_188 () ) ;
if ( F_189 ( V_5 , & V_5 -> V_238 [ V_6 ] ,
V_312 -> V_341 , V_6 , V_342 , V_340 ) )
goto V_105;
if ( F_190 ( V_5 , & V_5 -> V_211 [ V_6 ] ,
V_312 -> V_341 , V_343 ,
V_340 , V_6 ) )
goto V_105;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
V_340 = F_187 ( V_6 % F_188 () ) ;
if ( F_189 ( V_5 , & V_5 -> V_206 [ V_6 ] ,
V_312 -> V_337 , V_6 , V_344 , V_340 ) )
goto V_105;
if ( F_191 ( V_5 , & V_5 -> V_262 [ V_6 ] ,
V_312 -> V_337 , V_5 -> V_338 ,
V_340 ) )
goto V_105;
}
#ifdef F_182
V_5 -> V_2 -> V_336 = F_192 ( V_5 -> V_73 -> V_2 , V_5 -> V_55 ) ;
#endif
return 0 ;
V_105:
F_14 ( V_5 , L_79 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
if ( V_5 -> V_262 [ V_6 ] )
F_185 ( V_5 , & V_5 -> V_262 [ V_6 ] ,
V_312 -> V_337 ,
V_5 -> V_338 ) ;
if ( V_5 -> V_206 [ V_6 ] )
F_184 ( V_5 , & V_5 -> V_206 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
if ( V_5 -> V_211 [ V_6 ] )
F_183 ( V_5 , & V_5 -> V_211 [ V_6 ] ) ;
if ( V_5 -> V_238 [ V_6 ] )
F_184 ( V_5 , & V_5 -> V_238 [ V_6 ] ) ;
}
return - V_104 ;
}
void F_193 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
F_44 ( V_127 , V_5 , L_80 , V_5 -> V_55 ) ;
if ( V_5 -> V_345 ) {
F_194 ( F_195 ( V_73 -> V_2 ,
V_5 -> V_55 ) ) ;
F_196 ( V_2 ) ;
}
if ( V_5 -> V_346 )
F_197 ( V_73 -> V_2 , & V_5 -> V_347 , V_348 ) ;
F_198 ( & V_5 -> V_268 ) ;
F_198 ( & V_5 -> V_272 ) ;
F_199 ( V_73 -> V_106 ) ;
if ( V_73 -> V_2 -> V_121 . V_273 & V_274 )
F_200 ( V_73 ) ;
F_46 ( & V_73 -> V_116 ) ;
V_73 -> V_349 [ V_5 -> V_55 ] = NULL ;
V_73 -> V_350 [ V_5 -> V_55 ] = NULL ;
F_49 ( & V_73 -> V_116 ) ;
F_181 ( V_5 ) ;
F_25 ( V_5 -> V_211 ) ;
F_25 ( V_5 -> V_238 ) ;
F_201 ( V_2 ) ;
}
static int F_202 ( struct V_1 * V_2 , int V_351 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
int V_105 = 0 ;
F_44 ( V_127 , V_5 , L_81 ,
V_2 -> V_231 , V_351 ) ;
if ( ( V_351 < V_352 ) || ( V_351 > V_5 -> V_291 ) ) {
F_14 ( V_5 , L_82 , V_351 ) ;
return - V_353 ;
}
V_2 -> V_231 = V_351 ;
if ( F_203 ( V_2 ) ) {
F_46 ( & V_73 -> V_116 ) ;
if ( ! V_73 -> V_117 ) {
F_44 ( V_127 , V_5 , L_83 ) ;
} else {
F_165 ( V_2 , 1 ) ;
V_105 = F_139 ( V_2 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_84 ,
V_5 -> V_55 ) ;
F_33 ( V_73 -> V_106 , & V_5 -> V_217 ) ;
}
}
F_49 ( & V_73 -> V_116 ) ;
}
return 0 ;
}
static int F_204 ( struct V_1 * V_2 , struct V_354 * V_355 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_356 V_357 ;
if ( F_205 ( & V_357 , V_355 -> V_358 , sizeof( V_357 ) ) )
return - V_359 ;
if ( V_357 . V_142 )
return - V_9 ;
if ( ! ( V_73 -> V_2 -> V_121 . V_273 & V_274 ) )
return - V_9 ;
switch ( V_357 . V_360 ) {
case V_361 :
case V_362 :
break;
default:
return - V_363 ;
}
switch ( V_357 . V_364 ) {
case V_365 :
break;
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
case V_377 :
case V_378 :
case V_379 :
V_357 . V_364 = V_366 ;
break;
default:
return - V_363 ;
}
if ( F_206 ( V_2 , V_357 , V_2 -> V_380 ) ) {
V_357 . V_360 = V_361 ;
V_357 . V_364 = V_365 ;
}
return F_207 ( V_355 -> V_358 , & V_357 ,
sizeof( V_357 ) ) ? - V_359 : 0 ;
}
static int F_208 ( struct V_1 * V_2 , struct V_354 * V_355 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_207 ( V_355 -> V_358 , & V_5 -> V_356 ,
sizeof( V_5 -> V_356 ) ) ? - V_359 : 0 ;
}
static int F_209 ( struct V_1 * V_2 , struct V_354 * V_355 , int V_381 )
{
switch ( V_381 ) {
case V_382 :
return F_204 ( V_2 , V_355 ) ;
case V_383 :
return F_208 ( V_2 , V_355 ) ;
default:
return - V_384 ;
}
}
static T_7 F_210 ( struct V_1 * V_385 ,
T_7 V_380 )
{
struct V_4 * V_386 = F_2 ( V_385 ) ;
struct V_112 * V_73 = V_386 -> V_73 ;
if ( V_380 & V_387 &&
! ( V_73 -> V_2 -> V_121 . V_273 & V_388 ) )
V_380 |= V_389 ;
else
V_380 &= ~ V_389 ;
return V_380 ;
}
static int F_211 ( struct V_1 * V_385 ,
T_7 V_380 )
{
struct V_4 * V_5 = F_2 ( V_385 ) ;
bool V_390 = false ;
int V_87 = 0 ;
if ( F_212 ( V_385 , V_380 , V_391 ) ) {
F_131 ( V_5 , L_85 ,
( V_380 & V_391 ) ? L_86 : L_87 ) ;
V_390 = true ;
}
if ( F_212 ( V_385 , V_380 , V_392 ) ) {
T_1 V_393 = ( V_380 & V_392 ) ? 1 : 0 ;
F_131 ( V_5 , L_88 ,
V_393 ? L_86 : L_87 ) ;
V_87 = F_213 ( V_5 -> V_73 -> V_2 ,
V_5 -> V_55 , V_393 ) ;
if ( V_87 )
return V_87 ;
}
if ( F_212 ( V_385 , V_380 , V_387 ) ) {
F_131 ( V_5 , L_89 ,
( V_380 & V_387 ) ? L_86 : L_87 ) ;
V_390 = true ;
}
if ( F_212 ( V_385 , V_380 , V_394 ) )
F_131 ( V_5 , L_90 ,
( V_380 & V_394 ) ? L_86 : L_87 ) ;
if ( F_212 ( V_385 , V_380 , V_395 ) )
F_131 ( V_5 , L_91 ,
( V_380 & V_395 ) ? L_86 : L_87 ) ;
if ( F_212 ( V_385 , V_380 , V_396 ) ) {
F_131 ( V_5 , L_92 ,
( V_380 & V_396 ) ? L_86 : L_87 ) ;
F_214 ( V_385 , V_380 ) ;
}
if ( V_390 ) {
V_87 = F_206 ( V_385 , V_5 -> V_356 ,
V_380 ) ;
if ( V_87 )
return V_87 ;
}
return 0 ;
}
static int F_215 ( struct V_1 * V_2 , int V_397 , T_1 * V_128 )
{
struct V_4 * V_386 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_386 -> V_73 ;
T_6 V_398 = F_62 ( V_128 ) ;
if ( F_216 ( V_128 ) )
return - V_9 ;
return F_217 ( V_73 -> V_2 , V_386 -> V_55 , V_397 , V_398 ) ;
}
static int F_218 ( struct V_1 * V_2 , int V_399 , T_5 V_400 , T_1 V_401 )
{
struct V_4 * V_386 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_386 -> V_73 ;
return F_219 ( V_73 -> V_2 , V_386 -> V_55 , V_399 , V_400 , V_401 ) ;
}
static int F_220 ( struct V_1 * V_2 , int V_399 , int V_402 ,
int V_403 )
{
struct V_4 * V_386 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_386 -> V_73 ;
return F_221 ( V_73 -> V_2 , V_386 -> V_55 , V_399 , V_402 ,
V_403 ) ;
}
static int F_222 ( struct V_1 * V_2 , int V_399 , bool V_404 )
{
struct V_4 * V_386 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_386 -> V_73 ;
return F_223 ( V_73 -> V_2 , V_386 -> V_55 , V_399 , V_404 ) ;
}
static int F_224 ( struct V_1 * V_2 , int V_399 , struct V_405 * V_406 )
{
struct V_4 * V_386 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_386 -> V_73 ;
return F_225 ( V_73 -> V_2 , V_386 -> V_55 , V_399 , V_406 ) ;
}
static int F_226 ( struct V_1 * V_2 , int V_399 , int V_196 )
{
struct V_4 * V_386 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_386 -> V_73 ;
return F_227 ( V_73 -> V_2 , V_386 -> V_55 , V_399 , V_196 ) ;
}
static int F_228 ( struct V_1 * V_2 , int V_399 ,
struct V_407 * V_408 )
{
struct V_4 * V_386 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_386 -> V_73 ;
return F_229 ( V_73 -> V_2 , V_386 -> V_55 , V_399 , V_408 ) ;
}
static int F_230 ( struct V_1 * V_2 ,
struct V_409 * V_410 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_129 * V_73 = V_5 -> V_73 -> V_2 ;
int V_6 ;
T_6 V_411 = V_73 -> V_121 . V_411 [ V_5 -> V_55 ] ;
if ( ! V_411 )
return - V_384 ;
V_410 -> V_412 = sizeof( V_411 ) ;
for ( V_6 = V_413 - 1 ; V_6 >= 0 ; -- V_6 ) {
V_410 -> V_29 [ V_6 ] = V_411 & 0xff ;
V_411 >>= 8 ;
}
return 0 ;
}
static void F_231 ( struct V_23 * V_24 )
{
int V_87 ;
struct V_4 * V_5 = F_8 ( V_24 , struct V_4 ,
V_414 ) ;
V_87 = F_232 ( V_5 -> V_73 -> V_2 , V_5 -> V_415 ) ;
if ( V_87 )
goto V_103;
V_87 = F_153 ( V_5 -> V_73 -> V_2 , V_5 -> V_55 ,
V_317 , 1 ) ;
V_103:
if ( V_87 ) {
F_14 ( V_5 , L_93 , V_87 ) ;
return;
}
V_5 -> V_2 -> V_416 |= V_417 | V_418 |
V_419 | V_420 ;
}
static void F_233 ( struct V_23 * V_24 )
{
int V_87 ;
struct V_4 * V_5 = F_8 ( V_24 , struct V_4 ,
V_421 ) ;
V_5 -> V_2 -> V_416 &= ~ ( V_417 | V_418 |
V_419 | V_420 ) ;
V_87 = F_153 ( V_5 -> V_73 -> V_2 , V_5 -> V_55 ,
V_317 , 0 ) ;
if ( V_87 )
F_14 ( V_5 , L_93 , V_87 ) ;
V_5 -> V_415 = 0 ;
}
static void F_234 ( struct V_1 * V_2 ,
T_8 V_422 , T_3 V_55 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_423 ;
if ( V_5 -> V_73 -> V_2 -> V_121 . V_122 != V_123 )
return;
if ( V_422 == V_424 )
return;
V_423 = V_5 -> V_415 ;
if ( V_423 && V_423 != V_55 ) {
F_11 ( V_5 , L_94 ,
F_235 ( V_423 ) , F_235 ( V_55 ) ) ;
return;
}
V_5 -> V_415 = V_55 ;
F_33 ( V_5 -> V_73 -> V_106 , & V_5 -> V_414 ) ;
}
static void F_236 ( struct V_1 * V_2 ,
T_8 V_422 , T_3 V_55 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_423 ;
if ( V_5 -> V_73 -> V_2 -> V_121 . V_122 != V_123 )
return;
if ( V_422 == V_424 )
return;
V_423 = V_5 -> V_415 ;
if ( V_423 != V_55 ) {
F_44 ( V_127 , V_5 , L_95 , F_235 ( V_55 ) ) ;
return;
}
F_33 ( V_5 -> V_73 -> V_106 , & V_5 -> V_421 ) ;
}
static T_7 F_237 ( struct V_89 * V_90 ,
struct V_1 * V_2 ,
T_7 V_380 )
{
V_380 = F_238 ( V_90 , V_380 ) ;
return F_239 ( V_90 , V_380 ) ;
}
static int F_240 ( struct V_1 * V_2 , int V_425 , T_2 V_426 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_283 * V_211 = V_5 -> V_211 [ V_425 ] ;
struct V_427 V_428 ;
int V_105 ;
if ( ! ( V_5 -> V_73 -> V_2 -> V_121 . V_273 & V_429 ) )
return - V_384 ;
if ( V_426 >> 12 ) {
V_428 . V_430 = V_431 ;
V_428 . V_432 = V_426 / 1000 ;
} else if ( V_426 ) {
V_428 . V_430 = V_433 ;
V_428 . V_432 = V_426 ;
} else {
V_428 . V_430 = 0 ;
V_428 . V_432 = 0 ;
}
V_105 = F_241 ( V_5 -> V_73 -> V_2 , V_211 -> V_62 , V_434 ,
& V_428 ) ;
return V_105 ;
}
static void F_242 ( struct V_23 * V_24 )
{
struct V_435 * V_436 = F_8 ( V_24 ,
struct V_435 ,
V_24 ) ;
int V_105 = 0 ;
struct V_129 * V_2 = V_436 -> V_5 -> V_73 -> V_2 ;
if ( V_436 -> V_437 ) {
if ( ! F_243 ( V_2 ) ) {
V_105 = F_244 ( V_2 ) ;
if ( V_105 )
F_14 ( V_436 -> V_5 , L_96 ) ;
}
if ( ! V_105 ) {
V_105 = F_245 ( V_2 , & V_436 -> V_438 ) ;
if ( V_105 )
F_14 ( V_436 -> V_5 , L_97 ,
V_436 -> V_438 . V_439 ,
V_436 -> V_438 . V_440 ,
V_105 ) ;
}
} else if ( F_243 ( V_2 ) ) {
V_105 = F_246 ( V_2 ) ;
if ( V_105 )
F_14 ( V_436 -> V_5 , L_98 ) ;
}
F_247 ( V_436 -> V_5 -> V_2 ) ;
F_25 ( V_436 ) ;
}
static int F_248 ( struct V_4 * V_5 , int V_437 ,
T_1 V_441 , T_1 V_442 )
{
struct V_435 * V_436 = NULL ;
V_436 = F_20 ( sizeof( * V_436 ) , V_81 ) ;
if ( ! V_436 )
return - V_104 ;
F_21 ( & V_436 -> V_24 , F_242 ) ;
V_436 -> V_5 = V_5 ;
V_436 -> V_437 = V_437 ;
V_436 -> V_438 . V_439 = V_441 ;
V_436 -> V_438 . V_440 = V_442 ;
F_249 ( V_5 -> V_2 ) ;
F_33 ( V_5 -> V_73 -> V_106 , & V_436 -> V_24 ) ;
return 0 ;
}
int F_250 ( struct V_443 * V_444 ,
unsigned long V_445 , void * V_446 )
{
struct V_1 * V_447 = F_251 ( V_446 ) ;
T_1 V_55 = 0 ;
struct V_112 * V_73 ;
struct V_129 * V_2 ;
int V_6 , V_448 = 0 ;
bool V_449 = true ;
struct V_4 * V_5 ;
T_1 V_450 = 0 ;
T_1 V_451 = 0 ;
if ( ! F_252 ( F_253 ( V_447 ) , & V_452 ) )
return V_453 ;
V_73 = F_8 ( V_444 , struct V_112 , V_454 ) ;
V_2 = V_73 -> V_2 ;
F_254 (i, dev, MLX4_PORT_TYPE_ETH) {
++ V_448 ;
if ( ! V_55 && ( V_73 -> V_349 [ V_6 ] == V_447 ) )
V_55 = V_6 ;
V_73 -> V_350 [ V_6 ] = V_73 -> V_349 [ V_6 ] ?
F_255 ( V_73 -> V_349 [ V_6 ] ) : NULL ;
if ( ! V_73 -> V_350 [ V_6 ] )
V_449 = false ;
if ( V_448 < 2 )
continue;
if ( V_73 -> V_350 [ V_6 ] != V_73 -> V_350 [ V_6 - 1 ] )
V_449 = false ;
}
V_449 = ( V_448 == 2 ) ? V_449 : false ;
if ( ( V_449 && ( V_445 != V_455 ) ) || ! V_55 )
return V_453 ;
V_5 = F_2 ( V_447 ) ;
if ( V_449 ) {
struct V_456 * V_457 = V_446 ;
struct V_458 * V_459 =
& V_457 -> V_459 ;
if ( ( V_459 -> V_460 . V_461 != V_462 ) &&
( V_459 -> V_460 . V_461 != V_463 ) &&
( V_459 -> V_460 . V_461 != V_464 ) )
V_449 = false ;
if ( V_459 -> V_460 . V_465 != 2 )
V_449 = false ;
if ( V_449 ) {
if ( V_459 -> V_460 . V_461 ==
V_462 ) {
if ( V_459 -> V_466 . V_467 ==
V_468 ) {
if ( V_55 == 1 ) {
V_450 = 2 ;
V_451 = 2 ;
} else {
V_450 = 1 ;
V_451 = 1 ;
}
} else {
if ( V_55 == 1 ) {
V_450 = 1 ;
V_451 = 1 ;
} else {
V_450 = 2 ;
V_451 = 2 ;
}
}
} else {
T_9 V_469 = V_459 -> V_466 . V_469 ;
if ( V_55 == 1 )
V_451 = 2 ;
else
V_450 = 1 ;
if ( ( V_469 == V_470 ) ||
( V_469 == V_471 ) ) {
if ( V_55 == 1 )
V_450 = 1 ;
else
V_451 = 2 ;
} else {
if ( V_55 == 1 )
V_450 = 2 ;
else
V_451 = 1 ;
}
}
}
}
F_248 ( V_5 , V_449 ,
V_450 , V_451 ) ;
return V_453 ;
}
void F_256 ( struct V_129 * V_2 ,
struct V_472 * V_473 ,
T_1 V_316 , T_1 V_315 ,
T_1 V_314 , T_1 V_313 )
{
int V_474 = V_475 + V_476 + V_477 ;
if ( ! F_257 ( V_2 ) &&
( V_2 -> V_121 . V_273 & V_478 ) ) {
F_46 ( & V_473 -> V_479 ) ;
F_258 ( V_473 -> V_480 , V_474 , V_481 ) ;
if ( V_316 )
F_259 ( V_473 -> V_480 , V_474 ,
V_482 ) ;
V_474 += V_482 ;
if ( V_315 && ! ( V_316 ) )
F_259 ( V_473 -> V_480 , V_474 ,
V_483 ) ;
V_474 += V_483 ;
if ( V_314 )
F_259 ( V_473 -> V_480 , V_474 ,
V_484 ) ;
V_474 += V_484 ;
if ( V_313 && ! ( V_314 ) )
F_259 ( V_473 -> V_480 , V_474 ,
V_485 ) ;
V_474 += V_485 ;
F_49 ( & V_473 -> V_479 ) ;
}
}
void F_260 ( struct V_129 * V_2 ,
struct V_472 * V_473 ,
T_1 V_316 , T_1 V_315 ,
T_1 V_314 , T_1 V_313 )
{
int V_474 = 0 ;
F_261 ( & V_473 -> V_479 ) ;
F_262 ( V_473 -> V_480 , V_486 ) ;
if ( F_257 ( V_2 ) ) {
F_259 ( V_473 -> V_480 , V_474 +
F_263 ( V_257 ) , 1 ) ;
F_259 ( V_473 -> V_480 , V_474 +
F_263 ( V_487 ) , 1 ) ;
F_259 ( V_473 -> V_480 , V_474 +
F_263 ( V_258 ) , 1 ) ;
F_259 ( V_473 -> V_480 , V_474 +
F_263 ( V_488 ) , 1 ) ;
F_259 ( V_473 -> V_480 , V_474 +
F_263 ( V_489 ) , 1 ) ;
F_259 ( V_473 -> V_480 , V_474 +
F_263 ( V_490 ) , 1 ) ;
} else {
F_259 ( V_473 -> V_480 , V_474 , V_475 ) ;
}
V_474 += V_475 ;
F_259 ( V_473 -> V_480 , V_474 , V_476 ) ;
V_474 += V_476 ;
if ( F_264 ( V_2 ) )
F_259 ( V_473 -> V_480 , V_474 ,
V_477 ) ;
V_474 += V_477 ;
F_256 ( V_2 , V_473 ,
V_316 , V_315 ,
V_314 , V_313 ) ;
V_474 += V_481 ;
if ( ! F_257 ( V_2 ) )
F_259 ( V_473 -> V_480 , V_474 , V_491 ) ;
}
int F_265 ( struct V_112 * V_73 , int V_55 ,
struct V_339 * V_312 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_6 ;
int V_105 ;
V_2 = F_266 ( sizeof( struct V_4 ) ,
V_492 , V_493 ) ;
if ( V_2 == NULL )
return - V_104 ;
F_267 ( V_2 , V_312 -> V_210 ) ;
F_268 ( V_2 , V_312 -> V_205 ) ;
F_269 ( V_2 , & V_73 -> V_2 -> V_494 -> V_495 -> V_2 ) ;
V_2 -> V_496 = V_55 - 1 ;
V_5 = F_2 ( V_2 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_303 = F_172 ( V_73 -> V_2 ) ;
F_270 ( & V_5 -> V_219 ) ;
F_21 ( & V_5 -> V_177 , F_107 ) ;
F_21 ( & V_5 -> V_217 , F_177 ) ;
F_21 ( & V_5 -> V_276 , F_130 ) ;
F_271 ( & V_5 -> V_268 , F_123 ) ;
F_271 ( & V_5 -> V_272 , F_127 ) ;
#ifdef F_157
F_21 ( & V_5 -> V_414 , F_231 ) ;
F_21 ( & V_5 -> V_421 , F_233 ) ;
#endif
#ifdef F_182
F_58 ( & V_5 -> V_85 ) ;
F_270 ( & V_5 -> V_102 ) ;
#endif
V_5 -> V_2 = V_2 ;
V_5 -> V_73 = V_73 ;
V_5 -> V_497 = & V_73 -> V_495 -> V_2 ;
V_5 -> V_312 = V_312 ;
V_5 -> V_55 = V_55 ;
V_5 -> V_118 = false ;
V_5 -> V_142 = V_312 -> V_142 ;
V_5 -> V_498 = V_499 ;
V_5 -> V_500 = F_272 ( V_501 |
V_502 ) ;
V_5 -> V_10 = V_73 -> V_503 . V_10 ;
V_5 -> V_210 = V_312 -> V_210 ;
V_5 -> V_504 = V_505 ;
F_273 ( V_5 -> V_506 , sizeof( V_5 -> V_506 ) ) ;
V_5 -> V_211 = F_20 ( sizeof( struct V_283 * ) * V_492 ,
V_175 ) ;
if ( ! V_5 -> V_211 ) {
V_105 = - V_104 ;
goto V_103;
}
V_5 -> V_238 = F_20 ( sizeof( struct V_203 * ) * V_492 ,
V_175 ) ;
if ( ! V_5 -> V_238 ) {
V_105 = - V_104 ;
goto V_103;
}
V_5 -> V_205 = V_312 -> V_205 ;
V_5 -> V_299 = ( V_73 -> V_2 -> V_121 . V_298 == 64 ) ? 1 : 0 ;
V_5 -> V_298 = V_73 -> V_2 -> V_121 . V_298 ;
V_5 -> V_507 = - 1 ;
V_5 -> V_508 = V_509 ;
#ifdef F_274
if ( ! F_257 ( V_5 -> V_73 -> V_2 ) ) {
if ( V_73 -> V_2 -> V_121 . V_273 & V_510 ) {
V_2 -> V_511 = & V_512 ;
} else {
F_131 ( V_5 , L_99 ) ;
V_2 -> V_511 = & V_513 ;
}
}
#endif
for ( V_6 = 0 ; V_6 < V_193 ; ++ V_6 )
F_275 ( & V_5 -> V_148 [ V_6 ] ) ;
V_5 -> V_291 = V_73 -> V_2 -> V_121 . V_514 [ V_5 -> V_55 ] ;
if ( V_73 -> V_2 -> V_121 . V_515 [ V_5 -> V_55 ] &
V_516 )
V_5 -> V_142 |= V_517 ;
V_2 -> V_518 = V_69 ;
F_53 ( V_2 -> V_68 , V_73 -> V_2 -> V_121 . V_519 [ V_5 -> V_55 ] ) ;
if ( ! F_78 ( V_2 -> V_68 ) ) {
F_14 ( V_5 , L_100 ,
V_5 -> V_55 , V_2 -> V_68 ) ;
V_105 = - V_9 ;
goto V_103;
} else if ( F_257 ( V_5 -> V_73 -> V_2 ) &&
( V_5 -> V_73 -> V_2 -> V_520 & 1 << V_5 -> V_55 ) ) {
V_2 -> V_521 |= V_522 ;
F_11 ( V_5 , L_101 , V_2 -> V_68 ) ;
}
memcpy ( V_5 -> V_156 , V_2 -> V_68 , sizeof( V_5 -> V_156 ) ) ;
V_5 -> V_338 = F_276 ( sizeof( struct V_523 ) +
V_524 * V_525 ) ;
V_105 = F_186 ( V_5 ) ;
if ( V_105 )
goto V_103;
V_5 -> V_356 . V_142 = 0 ;
V_5 -> V_356 . V_360 = V_361 ;
V_5 -> V_356 . V_364 = V_365 ;
V_105 = F_277 ( V_73 -> V_2 , & V_5 -> V_347 ,
V_348 , V_348 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_102 ) ;
goto V_103;
}
V_5 -> V_346 = 1 ;
if ( F_264 ( V_5 -> V_73 -> V_2 ) )
V_2 -> V_526 = & V_527 ;
else
V_2 -> V_526 = & V_528 ;
V_2 -> V_529 = V_530 ;
F_267 ( V_2 , V_5 -> V_210 ) ;
F_268 ( V_2 , V_5 -> V_205 ) ;
V_2 -> V_531 = & V_532 ;
V_2 -> V_533 = V_534 | V_417 | V_535 ;
if ( V_73 -> V_536 )
V_2 -> V_533 |= V_419 | V_537 ;
V_2 -> V_538 = V_2 -> V_533 ;
V_2 -> V_533 |= V_418 | V_539 ;
V_2 -> V_380 = V_2 -> V_533 | V_540 |
V_394 | V_387 |
V_541 ;
V_2 -> V_533 |= V_396 |
V_394 | V_387 ;
if ( ! ( V_73 -> V_2 -> V_121 . V_273 & V_388 ) ) {
V_2 -> V_380 |= V_389 |
V_542 ;
V_2 -> V_533 |= V_389 ;
}
if ( F_257 ( V_73 -> V_2 ) ) {
int V_543 ;
V_105 = F_278 ( V_73 -> V_2 , V_55 , & V_543 ) ;
if ( ! V_105 && V_543 ) {
V_2 -> V_533 |= V_395 ;
V_5 -> V_498 |= V_544 ;
}
} else {
if ( V_73 -> V_2 -> V_121 . V_273 & V_545 &&
! ( V_73 -> V_2 -> V_121 . V_273 &
V_388 ) )
V_2 -> V_533 |= V_395 ;
}
if ( V_73 -> V_2 -> V_121 . V_142 & V_546 )
V_2 -> V_533 |= V_391 ;
if ( V_73 -> V_2 -> V_121 . V_273 & V_547 )
V_2 -> V_533 |= V_392 ;
if ( V_73 -> V_2 -> V_121 . V_130 ==
V_136 &&
V_73 -> V_2 -> V_121 . V_124 != V_125 )
V_2 -> V_533 |= V_548 ;
if ( V_73 -> V_2 -> V_121 . V_130 != V_140 )
V_2 -> V_200 |= V_201 ;
if ( V_73 -> V_2 -> V_121 . V_273 & V_549 ) {
V_5 -> V_550 = V_551 ;
} else if ( V_73 -> V_2 -> V_121 . V_273 & V_552 ) {
V_5 -> V_550 = V_553 ;
} else {
F_11 ( V_5 ,
L_103 ) ;
V_5 -> V_550 = V_551 ;
}
if ( V_73 -> V_2 -> V_121 . V_122 == V_123 ) {
V_2 -> V_533 |= V_420 ;
V_2 -> V_380 |= V_420 ;
}
V_73 -> V_349 [ V_55 ] = V_2 ;
V_73 -> V_350 [ V_55 ] = NULL ;
F_132 ( V_2 ) ;
F_120 ( V_5 ) ;
F_11 ( V_5 , L_104 , V_312 -> V_210 ) ;
F_11 ( V_5 , L_105 , V_312 -> V_205 ) ;
F_214 ( V_5 -> V_2 , V_5 -> V_2 -> V_380 ) ;
F_141 ( V_2 ) ;
V_105 = F_152 ( V_73 -> V_2 , V_5 -> V_55 ,
V_5 -> V_292 + V_311 ,
V_312 -> V_313 , V_312 -> V_314 ,
V_312 -> V_315 , V_312 -> V_316 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_65 ,
V_5 -> V_55 , V_105 ) ;
goto V_103;
}
if ( V_73 -> V_2 -> V_121 . V_122 == V_123 ) {
V_105 = F_153 ( V_73 -> V_2 , V_5 -> V_55 , V_317 , 1 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_67 ,
V_105 ) ;
goto V_103;
}
}
F_11 ( V_5 , L_68 ) ;
V_105 = F_154 ( V_73 -> V_2 , V_5 -> V_55 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_69 ) ;
goto V_103;
}
F_126 ( V_73 -> V_106 , & V_5 -> V_268 , V_269 ) ;
if ( V_73 -> V_2 -> V_121 . V_273 & V_274 )
F_279 ( V_73 ) ;
F_126 ( V_73 -> V_106 , & V_5 -> V_272 ,
V_275 ) ;
F_260 ( V_73 -> V_2 , & V_5 -> V_473 ,
V_73 -> V_503 . V_312 [ V_5 -> V_55 ] . V_316 ,
V_73 -> V_503 . V_312 [ V_5 -> V_55 ] . V_315 ,
V_73 -> V_503 . V_312 [ V_5 -> V_55 ] . V_314 ,
V_73 -> V_503 . V_312 [ V_5 -> V_55 ] . V_313 ) ;
V_105 = F_280 ( V_2 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_106 , V_55 ) ;
goto V_103;
}
V_5 -> V_345 = 1 ;
F_281 ( F_195 ( V_73 -> V_2 , V_5 -> V_55 ) ,
V_2 ) ;
return 0 ;
V_103:
F_193 ( V_2 ) ;
return V_105 ;
}
int F_206 ( struct V_1 * V_2 ,
struct V_356 V_554 ,
T_7 V_380 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
int V_118 = 0 ;
int V_105 = 0 ;
if ( V_5 -> V_356 . V_360 == V_554 . V_360 &&
V_5 -> V_356 . V_364 == V_554 . V_364 &&
! F_212 ( V_2 , V_380 , V_387 ) &&
! F_212 ( V_2 , V_380 , V_391 ) )
return 0 ;
if ( F_212 ( V_2 , V_380 , V_387 ) &&
( V_380 & V_387 ) &&
( V_5 -> V_356 . V_364 != V_365 ) ) {
F_11 ( V_5 , L_107 ) ;
return - V_9 ;
}
F_46 ( & V_73 -> V_116 ) ;
if ( V_5 -> V_118 ) {
V_118 = 1 ;
F_165 ( V_2 , 1 ) ;
}
F_181 ( V_5 ) ;
F_11 ( V_5 , L_108 ,
V_554 . V_364 , ! ! ( V_380 & V_387 ) ) ;
V_5 -> V_356 . V_360 = V_554 . V_360 ;
V_5 -> V_356 . V_364 = V_554 . V_364 ;
if ( F_212 ( V_2 , V_380 , V_387 ) ) {
if ( V_380 & V_387 )
V_2 -> V_380 |= V_387 ;
else
V_2 -> V_380 &= ~ V_387 ;
} else if ( V_554 . V_364 == V_365 ) {
if ( V_2 -> V_555 & V_387 )
V_2 -> V_380 |= V_387 ;
else
V_2 -> V_380 &= ~ V_387 ;
}
if ( F_212 ( V_2 , V_380 , V_391 ) ) {
if ( V_380 & V_391 )
V_2 -> V_380 |= V_391 ;
else
V_2 -> V_380 &= ~ V_391 ;
}
if ( V_554 . V_364 != V_365 ) {
if ( V_2 -> V_380 & V_387 )
F_11 ( V_5 , L_109 ) ;
V_2 -> V_380 &= ~ V_387 ;
}
V_105 = F_186 ( V_5 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_110 ) ;
goto V_103;
}
if ( V_118 ) {
V_105 = F_139 ( V_2 ) ;
if ( V_105 )
F_14 ( V_5 , L_111 ) ;
}
V_103:
F_49 ( & V_73 -> V_116 ) ;
F_282 ( V_2 ) ;
return V_105 ;
}
