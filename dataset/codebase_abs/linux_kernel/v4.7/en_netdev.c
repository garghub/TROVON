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
if ( V_105 ) {
F_14 ( V_5 , L_5 ) ;
goto V_103;
}
}
V_105 = F_48 ( V_73 -> V_2 , V_5 -> V_55 , V_111 , & V_113 ) ;
if ( V_105 )
F_44 ( V_114 , V_5 , L_6 , V_111 ) ;
V_103:
F_49 ( & V_73 -> V_116 ) ;
return V_105 ;
}
static int F_50 ( struct V_1 * V_2 ,
T_3 V_12 , T_5 V_111 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
int V_105 = 0 ;
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
return V_105 ;
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
static struct V_218 *
F_119 ( struct V_1 * V_2 , struct V_218 * V_219 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_32 ( & V_5 -> V_220 ) ;
F_120 ( V_219 , & V_2 -> V_219 ) ;
F_34 ( & V_5 -> V_220 ) ;
return V_219 ;
}
static void F_121 ( struct V_4 * V_5 )
{
struct V_203 * V_204 ;
int V_6 ;
V_5 -> V_221 = V_222 ;
V_5 -> V_223 = V_224 ;
V_5 -> V_225 = V_226 ;
V_5 -> V_227 = V_228 ;
F_44 ( V_229 , V_5 , L_49 ,
V_5 -> V_2 -> V_230 , V_5 -> V_221 , V_5 -> V_223 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
V_204 = V_5 -> V_206 [ V_6 ] ;
V_204 -> V_231 = V_5 -> V_221 ;
V_204 -> V_232 = V_5 -> V_223 ;
V_5 -> V_233 [ V_6 ] = V_234 ;
V_5 -> V_235 [ V_6 ] = 0 ;
V_5 -> V_236 [ V_6 ] = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
V_204 = V_5 -> V_237 [ V_6 ] ;
V_204 -> V_231 = V_5 -> V_225 ;
V_204 -> V_232 = V_5 -> V_227 ;
}
V_5 -> V_238 = V_239 ;
V_5 -> V_240 = V_241 ;
V_5 -> V_242 = V_243 ;
V_5 -> V_244 = V_245 ;
V_5 -> V_246 = V_247 ;
V_5 -> V_248 = 1 ;
V_5 -> V_249 = 0 ;
V_5 -> V_250 = 0 ;
}
static void F_122 ( struct V_4 * V_5 )
{
unsigned long V_251 = ( unsigned long ) ( V_252 - V_5 -> V_249 ) ;
struct V_203 * V_204 ;
unsigned long V_253 ;
unsigned long V_254 ;
unsigned long V_255 ;
unsigned long V_256 ;
unsigned long V_257 ;
unsigned long V_258 ;
int V_232 ;
int V_259 , V_105 ;
if ( ! V_5 -> V_248 || V_251 < V_5 -> V_246 * V_260 )
return;
for ( V_259 = 0 ; V_259 < V_5 -> V_205 ; V_259 ++ ) {
F_32 ( & V_5 -> V_220 ) ;
V_256 = V_5 -> V_261 [ V_259 ] -> V_253 ;
V_257 = V_5 -> V_261 [ V_259 ] -> V_262 ;
F_34 ( & V_5 -> V_220 ) ;
V_258 = ( ( unsigned long ) ( V_256 -
V_5 -> V_235 [ V_259 ] ) ) ;
V_253 = V_258 ;
V_254 = V_253 * V_260 / V_251 ;
V_255 = V_253 ? ( ( unsigned long ) ( V_257 -
V_5 -> V_236 [ V_259 ] ) ) / V_253 : 0 ;
if ( V_254 > ( V_263 / V_5 -> V_205 ) &&
V_255 > V_264 ) {
if ( V_254 < V_5 -> V_238 )
V_232 = V_5 -> V_240 ;
else if ( V_254 > V_5 -> V_242 )
V_232 = V_5 -> V_244 ;
else
V_232 = ( V_254 - V_5 -> V_238 ) *
( V_5 -> V_244 - V_5 -> V_240 ) /
( V_5 -> V_242 - V_5 -> V_238 ) +
V_5 -> V_240 ;
} else {
V_232 = V_5 -> V_240 ;
}
if ( V_232 != V_5 -> V_233 [ V_259 ] ) {
V_5 -> V_233 [ V_259 ] = V_232 ;
V_204 = V_5 -> V_206 [ V_259 ] ;
V_204 -> V_232 = V_232 ;
V_204 -> V_231 = V_5 -> V_221 ;
V_105 = F_123 ( V_5 , V_204 ) ;
if ( V_105 )
F_14 ( V_5 , L_50 ,
V_259 ) ;
}
V_5 -> V_235 [ V_259 ] = V_256 ;
V_5 -> V_236 [ V_259 ] = V_257 ;
}
V_5 -> V_249 = V_252 ;
}
static void F_124 ( struct V_23 * V_24 )
{
struct V_265 * V_266 = F_125 ( V_24 ) ;
struct V_4 * V_5 = F_8 ( V_266 , struct V_4 ,
V_267 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
int V_105 ;
F_46 ( & V_73 -> V_116 ) ;
if ( V_73 -> V_117 ) {
if ( V_5 -> V_118 ) {
V_105 = F_126 ( V_73 , V_5 -> V_55 , 0 ) ;
if ( V_105 )
F_44 ( V_114 , V_5 , L_51 ) ;
F_122 ( V_5 ) ;
}
F_127 ( V_73 -> V_106 , & V_5 -> V_267 , V_268 ) ;
}
if ( V_73 -> V_269 [ V_270 + 1 - V_5 -> V_55 ] ) {
F_76 ( V_5 , V_5 -> V_156 ) ;
V_73 -> V_269 [ V_270 + 1 - V_5 -> V_55 ] = 0 ;
}
F_49 ( & V_73 -> V_116 ) ;
}
static void F_128 ( struct V_23 * V_24 )
{
struct V_265 * V_266 = F_125 ( V_24 ) ;
struct V_4 * V_5 = F_8 ( V_266 , struct V_4 ,
V_271 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
F_46 ( & V_73 -> V_116 ) ;
if ( V_73 -> V_117 ) {
if ( V_73 -> V_2 -> V_121 . V_272 & V_273 )
F_129 ( V_73 ) ;
F_130 ( V_5 ) ;
F_127 ( V_73 -> V_106 , & V_5 -> V_271 ,
V_274 ) ;
}
F_49 ( & V_73 -> V_116 ) ;
}
static void F_131 ( struct V_23 * V_24 )
{
struct V_4 * V_5 = F_8 ( V_24 , struct V_4 ,
V_275 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
int V_276 = V_5 -> V_196 ;
F_46 ( & V_73 -> V_116 ) ;
if ( V_5 -> V_197 != V_276 ) {
if ( V_276 == V_277 ) {
F_132 ( V_5 , L_52 ) ;
F_133 ( V_5 -> V_2 ) ;
} else {
F_132 ( V_5 , L_44 ) ;
F_110 ( V_5 -> V_2 ) ;
}
}
V_5 -> V_197 = V_276 ;
F_49 ( & V_73 -> V_116 ) ;
}
static int F_134 ( struct V_4 * V_5 , int V_278 )
{
struct V_279 * V_259 = V_5 -> V_261 [ V_278 ] ;
int V_280 = V_5 -> V_73 -> V_2 -> V_280 ;
if ( ! F_135 ( & V_259 -> V_281 , V_175 ) )
return - V_104 ;
F_136 ( F_137 ( V_278 , V_280 ) ,
V_259 -> V_281 ) ;
return 0 ;
}
static void F_138 ( struct V_4 * V_5 , int V_278 )
{
F_139 ( V_5 -> V_261 [ V_278 ] -> V_281 ) ;
}
int F_140 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_203 * V_204 ;
struct V_282 * V_211 ;
int V_283 = 0 ;
int V_284 = 0 ;
int V_105 = 0 ;
int V_6 ;
int V_285 ;
T_1 V_164 [ 16 ] = { 0 } ;
if ( V_5 -> V_118 ) {
F_44 ( V_127 , V_5 , L_53 ) ;
return 0 ;
}
F_58 ( & V_5 -> V_164 ) ;
F_58 ( & V_5 -> V_189 ) ;
F_58 ( & V_5 -> V_286 ) ;
memset ( & V_5 -> V_287 [ 0 ] , 0 ,
sizeof( struct V_288 ) * V_289 ) ;
V_2 -> V_230 = F_141 ( V_2 -> V_230 , V_5 -> V_290 ) ;
F_142 ( V_2 ) ;
F_44 ( V_127 , V_5 , L_54 , V_5 -> V_291 ) ;
V_105 = F_143 ( V_5 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_55 ) ;
return V_105 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
V_204 = V_5 -> V_206 [ V_6 ] ;
V_105 = F_134 ( V_5 , V_6 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_56 ) ;
goto V_292;
}
V_105 = F_144 ( V_5 , V_204 , V_6 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_57 ) ;
F_138 ( V_5 , V_6 ) ;
goto V_292;
}
for ( V_285 = 0 ; V_285 < V_204 -> V_293 ; V_285 ++ ) {
struct V_294 * V_295 = NULL ;
V_295 = F_145 ( V_204 -> V_296 , V_285 , V_5 -> V_297 ) +
V_5 -> V_298 ;
V_295 -> V_299 = V_300 ;
}
V_105 = F_123 ( V_5 , V_204 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_58 ) ;
F_146 ( V_5 , V_204 ) ;
F_138 ( V_5 , V_6 ) ;
goto V_292;
}
F_147 ( V_5 , V_204 ) ;
V_5 -> V_261 [ V_6 ] -> V_212 = V_204 -> V_301 . V_212 ;
++ V_283 ;
}
F_44 ( V_127 , V_5 , L_59 , V_5 -> V_55 ) ;
V_105 = F_61 ( V_5 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_60 ) ;
goto V_292;
}
V_73 -> V_269 [ V_5 -> V_55 ] = 0 ;
V_5 -> V_302 =
F_148 ( V_73 -> V_2 , V_5 -> V_55 ) ;
V_105 = F_149 ( V_5 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_61 ) ;
goto V_303;
}
V_105 = F_150 ( V_5 ) ;
if ( V_105 )
goto V_304;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
V_204 = V_5 -> V_237 [ V_6 ] ;
V_105 = F_144 ( V_5 , V_204 , V_6 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_62 ) ;
goto V_305;
}
V_105 = F_123 ( V_5 , V_204 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_58 ) ;
F_146 ( V_5 , V_204 ) ;
goto V_305;
}
F_44 ( V_127 , V_5 , L_63 , V_6 ) ;
V_204 -> V_296 -> V_306 = F_151 ( 0xffff ) ;
V_211 = V_5 -> V_211 [ V_6 ] ;
V_105 = F_152 ( V_5 , V_211 , V_204 -> V_301 . V_212 ,
V_6 / V_5 -> V_10 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_64 ) ;
F_146 ( V_5 , V_204 ) ;
goto V_305;
}
V_211 -> V_307 = F_118 ( V_2 , V_6 ) ;
F_147 ( V_5 , V_204 ) ;
for ( V_285 = 0 ; V_285 < V_211 -> V_308 ; V_285 += V_309 )
* ( ( T_2 * ) ( V_211 -> V_296 + V_285 ) ) = 0xffffffff ;
++ V_284 ;
}
V_105 = F_153 ( V_73 -> V_2 , V_5 -> V_55 ,
V_5 -> V_291 + V_310 ,
V_5 -> V_311 -> V_312 ,
V_5 -> V_311 -> V_313 ,
V_5 -> V_311 -> V_314 ,
V_5 -> V_311 -> V_315 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_65 ,
V_5 -> V_55 , V_105 ) ;
goto V_305;
}
V_105 = F_92 ( V_73 -> V_2 , V_5 -> V_55 , V_5 -> V_139 , 0 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_66 ) ;
goto V_305;
}
if ( V_73 -> V_2 -> V_121 . V_122 == V_123 ) {
V_105 = F_154 ( V_73 -> V_2 , V_5 -> V_55 , V_316 , 1 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_67 ,
V_105 ) ;
goto V_305;
}
}
F_44 ( V_114 , V_5 , L_68 ) ;
V_105 = F_155 ( V_73 -> V_2 , V_5 -> V_55 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_69 ) ;
goto V_305;
}
if ( V_73 -> V_2 -> V_121 . V_130 != V_140 &&
F_113 ( V_5 ) )
F_156 ( V_73 , L_70 ) ;
F_157 ( & V_164 [ 10 ] ) ;
V_164 [ 5 ] = V_5 -> V_55 ;
if ( F_102 ( V_73 -> V_2 , & V_5 -> V_63 . V_190 , V_164 ,
V_5 -> V_55 , 0 , V_135 ,
& V_5 -> V_317 ) )
F_156 ( V_73 , L_71 ) ;
V_5 -> V_142 &= ~ ( V_178 | V_180 ) ;
F_33 ( V_73 -> V_106 , & V_5 -> V_177 ) ;
#ifdef F_158
if ( V_5 -> V_73 -> V_2 -> V_121 . V_122 == V_123 )
F_159 ( V_2 ) ;
#endif
V_5 -> V_118 = true ;
F_160 ( V_2 ) ;
F_161 ( V_2 ) ;
return 0 ;
V_305:
while ( V_284 -- ) {
F_162 ( V_5 , V_5 -> V_211 [ V_284 ] ) ;
F_146 ( V_5 , V_5 -> V_237 [ V_284 ] ) ;
}
F_163 ( V_5 ) ;
V_304:
F_164 ( V_5 ) ;
V_303:
F_67 ( V_5 ) ;
V_292:
while ( V_283 -- ) {
F_146 ( V_5 , V_5 -> V_206 [ V_283 ] ) ;
F_138 ( V_5 , V_283 ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ )
F_165 ( V_5 , V_5 -> V_261 [ V_6 ] ) ;
return V_105 ;
}
void F_166 ( struct V_1 * V_2 , int V_318 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_160 * V_182 , * V_107 ;
struct V_288 * V_319 , * V_320 ;
int V_6 ;
T_1 V_164 [ 16 ] = { 0 } ;
if ( ! V_5 -> V_118 ) {
F_44 ( V_127 , V_5 , L_72 ) ;
return;
}
F_167 ( V_73 -> V_2 , V_5 -> V_55 ) ;
F_168 ( V_2 ) ;
if ( V_318 )
F_169 ( V_2 ) ;
F_170 ( V_2 ) ;
F_171 ( V_2 ) ;
F_172 ( V_2 ) ;
V_5 -> V_118 = false ;
V_5 -> V_302 = F_173 ( V_73 -> V_2 ) ;
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
F_157 ( & V_164 [ 10 ] ) ;
V_164 [ 5 ] = V_5 -> V_55 ;
F_101 ( V_73 -> V_2 , & V_5 -> V_63 . V_190 , V_164 ,
V_135 , V_5 -> V_317 ) ;
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
F_174 () ;
F_37 (flow, tmp_flow,
&priv->ethtool_list, list) {
F_13 ( V_73 -> V_2 , V_319 -> V_29 ) ;
F_24 ( & V_319 -> V_48 ) ;
}
}
F_163 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
F_162 ( V_5 , V_5 -> V_211 [ V_6 ] ) ;
F_146 ( V_5 , V_5 -> V_237 [ V_6 ] ) ;
}
F_175 ( 10 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ )
F_176 ( V_2 , V_5 -> V_211 [ V_6 ] ) ;
if ( V_73 -> V_2 -> V_121 . V_130 != V_140 )
F_114 ( V_5 ) ;
F_164 ( V_5 ) ;
F_67 ( V_5 ) ;
if ( ! ( V_73 -> V_2 -> V_121 . V_272 & V_321 ) )
V_73 -> V_269 [ V_5 -> V_55 ] = 1 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
struct V_203 * V_204 = V_5 -> V_206 [ V_6 ] ;
F_177 ( & V_204 -> V_207 ) ;
F_165 ( V_5 , V_5 -> V_261 [ V_6 ] ) ;
F_146 ( V_5 , V_204 ) ;
F_138 ( V_5 , V_6 ) ;
}
}
static void F_178 ( struct V_23 * V_24 )
{
struct V_4 * V_5 = F_8 ( V_24 , struct V_4 ,
V_217 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_44 ( V_127 , V_5 , L_73 , V_5 -> V_55 ) ;
F_179 () ;
F_46 ( & V_73 -> V_116 ) ;
if ( V_5 -> V_118 ) {
F_166 ( V_2 , 1 ) ;
if ( F_140 ( V_2 ) )
F_14 ( V_5 , L_74 , V_5 -> V_55 ) ;
}
F_49 ( & V_73 -> V_116 ) ;
F_180 () ;
}
static void F_181 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
int V_6 ;
if ( F_126 ( V_73 , V_5 -> V_55 , 1 ) )
F_44 ( V_114 , V_5 , L_75 ) ;
memset ( & V_5 -> V_322 , 0 , sizeof( V_5 -> V_322 ) ) ;
memset ( & V_5 -> V_323 , 0 , sizeof( V_5 -> V_323 ) ) ;
memset ( & V_5 -> V_215 , 0 , sizeof( V_5 -> V_215 ) ) ;
memset ( & V_5 -> V_324 , 0 , sizeof( V_5 -> V_324 ) ) ;
memset ( & V_5 -> V_325 , 0 , sizeof( V_5 -> V_325 ) ) ;
memset ( & V_5 -> V_326 , 0 ,
sizeof( V_5 -> V_326 ) ) ;
memset ( & V_5 -> V_327 , 0 ,
sizeof( V_5 -> V_327 ) ) ;
memset ( & V_5 -> V_328 , 0 , sizeof( V_5 -> V_328 ) ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
V_5 -> V_211 [ V_6 ] -> V_262 = 0 ;
V_5 -> V_211 [ V_6 ] -> V_253 = 0 ;
V_5 -> V_211 [ V_6 ] -> V_329 = 0 ;
V_5 -> V_211 [ V_6 ] -> V_330 = 0 ;
V_5 -> V_211 [ V_6 ] -> V_331 = 0 ;
V_5 -> V_211 [ V_6 ] -> V_332 = 0 ;
V_5 -> V_211 [ V_6 ] -> V_333 = 0 ;
V_5 -> V_211 [ V_6 ] -> V_334 = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
V_5 -> V_261 [ V_6 ] -> V_262 = 0 ;
V_5 -> V_261 [ V_6 ] -> V_253 = 0 ;
V_5 -> V_261 [ V_6 ] -> V_335 = 0 ;
V_5 -> V_261 [ V_6 ] -> V_336 = 0 ;
V_5 -> V_261 [ V_6 ] -> V_337 = 0 ;
}
}
static int F_182 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
int V_105 = 0 ;
F_46 ( & V_73 -> V_116 ) ;
if ( ! V_73 -> V_117 ) {
F_14 ( V_5 , L_76 ) ;
V_105 = - V_338 ;
goto V_103;
}
F_181 ( V_2 ) ;
V_105 = F_140 ( V_2 ) ;
if ( V_105 )
F_14 ( V_5 , L_77 , V_5 -> V_55 ) ;
V_103:
F_49 ( & V_73 -> V_116 ) ;
return V_105 ;
}
static int F_183 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
F_44 ( V_339 , V_5 , L_78 ) ;
F_46 ( & V_73 -> V_116 ) ;
F_166 ( V_2 , 0 ) ;
F_133 ( V_2 ) ;
F_49 ( & V_73 -> V_116 ) ;
return 0 ;
}
static void F_184 ( struct V_4 * V_5 )
{
int V_6 ;
#ifdef F_185
V_5 -> V_2 -> V_340 = NULL ;
#endif
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
if ( V_5 -> V_211 && V_5 -> V_211 [ V_6 ] )
F_186 ( V_5 , & V_5 -> V_211 [ V_6 ] ) ;
if ( V_5 -> V_237 && V_5 -> V_237 [ V_6 ] )
F_187 ( V_5 , & V_5 -> V_237 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
if ( V_5 -> V_261 [ V_6 ] )
F_188 ( V_5 , & V_5 -> V_261 [ V_6 ] ,
V_5 -> V_311 -> V_341 , V_5 -> V_342 ) ;
if ( V_5 -> V_206 [ V_6 ] )
F_187 ( V_5 , & V_5 -> V_206 [ V_6 ] ) ;
}
}
static int F_189 ( struct V_4 * V_5 )
{
struct V_343 * V_311 = V_5 -> V_311 ;
int V_6 ;
int V_344 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
V_344 = F_190 ( V_6 % F_191 () ) ;
if ( F_192 ( V_5 , & V_5 -> V_237 [ V_6 ] ,
V_311 -> V_345 , V_6 , V_346 , V_344 ) )
goto V_105;
if ( F_193 ( V_5 , & V_5 -> V_211 [ V_6 ] ,
V_311 -> V_345 , V_347 ,
V_344 , V_6 ) )
goto V_105;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
V_344 = F_190 ( V_6 % F_191 () ) ;
if ( F_192 ( V_5 , & V_5 -> V_206 [ V_6 ] ,
V_311 -> V_341 , V_6 , V_348 , V_344 ) )
goto V_105;
if ( F_194 ( V_5 , & V_5 -> V_261 [ V_6 ] ,
V_311 -> V_341 , V_5 -> V_342 ,
V_344 ) )
goto V_105;
}
#ifdef F_185
V_5 -> V_2 -> V_340 = F_195 ( V_5 -> V_73 -> V_2 , V_5 -> V_55 ) ;
#endif
return 0 ;
V_105:
F_14 ( V_5 , L_79 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
if ( V_5 -> V_261 [ V_6 ] )
F_188 ( V_5 , & V_5 -> V_261 [ V_6 ] ,
V_311 -> V_341 ,
V_5 -> V_342 ) ;
if ( V_5 -> V_206 [ V_6 ] )
F_187 ( V_5 , & V_5 -> V_206 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
if ( V_5 -> V_211 [ V_6 ] )
F_186 ( V_5 , & V_5 -> V_211 [ V_6 ] ) ;
if ( V_5 -> V_237 [ V_6 ] )
F_187 ( V_5 , & V_5 -> V_237 [ V_6 ] ) ;
}
return - V_104 ;
}
static void F_196 ( struct V_1 * V_2 )
{
F_179 () ;
F_169 ( V_2 ) ;
F_183 ( V_2 ) ;
F_180 () ;
}
static int F_197 ( struct V_4 * V_166 ,
struct V_4 * V_167 ,
struct V_343 * V_311 )
{
memcpy ( & V_166 -> V_349 , & V_311 -> V_349 ,
sizeof( V_166 -> V_349 ) ) ;
V_166 -> V_10 = V_167 -> V_73 -> V_350 . V_10 ;
V_166 -> V_210 = V_311 -> V_210 ;
V_166 -> V_205 = V_311 -> V_205 ;
V_166 -> V_142 = V_311 -> V_142 ;
V_166 -> V_73 = V_167 -> V_73 ;
V_166 -> V_55 = V_167 -> V_55 ;
V_166 -> V_2 = V_167 -> V_2 ;
V_166 -> V_311 = V_311 ;
V_166 -> V_342 = F_198 ( sizeof( struct V_351 ) +
V_352 * V_353 ) ;
V_166 -> V_211 = F_20 ( sizeof( struct V_282 * ) * V_354 ,
V_175 ) ;
if ( ! V_166 -> V_211 )
return - V_104 ;
V_166 -> V_237 = F_20 ( sizeof( struct V_203 * ) * V_354 ,
V_175 ) ;
if ( ! V_166 -> V_237 ) {
F_25 ( V_166 -> V_211 ) ;
return - V_104 ;
}
return 0 ;
}
static void F_199 ( struct V_4 * V_166 ,
struct V_4 * V_167 )
{
memcpy ( V_166 -> V_261 , V_167 -> V_261 ,
sizeof( struct V_279 * ) * V_167 -> V_205 ) ;
memcpy ( V_166 -> V_206 , V_167 -> V_206 ,
sizeof( struct V_203 * ) * V_167 -> V_205 ) ;
memcpy ( & V_166 -> V_349 , & V_167 -> V_349 ,
sizeof( V_166 -> V_349 ) ) ;
V_166 -> V_210 = V_167 -> V_210 ;
V_166 -> V_205 = V_167 -> V_205 ;
V_166 -> V_211 = V_167 -> V_211 ;
V_166 -> V_237 = V_167 -> V_237 ;
memcpy ( V_166 -> V_311 , V_167 -> V_311 , sizeof( struct V_343 ) ) ;
}
int F_200 ( struct V_4 * V_5 ,
struct V_4 * V_107 ,
struct V_343 * V_311 )
{
F_197 ( V_107 , V_5 , V_311 ) ;
if ( F_189 ( V_107 ) ) {
F_11 ( V_5 ,
L_80 ,
V_355 ) ;
F_25 ( V_107 -> V_211 ) ;
F_25 ( V_107 -> V_237 ) ;
return - V_104 ;
}
return 0 ;
}
void F_201 ( struct V_4 * V_5 ,
struct V_4 * V_107 )
{
F_184 ( V_5 ) ;
F_199 ( V_5 , V_107 ) ;
}
void F_202 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
bool V_356 = V_73 -> V_2 -> V_357 -> V_358 &
V_359 ;
F_44 ( V_127 , V_5 , L_81 , V_5 -> V_55 ) ;
if ( V_5 -> V_360 ) {
F_203 ( F_204 ( V_73 -> V_2 ,
V_5 -> V_55 ) ) ;
if ( V_356 )
F_196 ( V_2 ) ;
else
F_205 ( V_2 ) ;
}
if ( V_5 -> V_361 )
F_206 ( V_73 -> V_2 , & V_5 -> V_362 , V_363 ) ;
F_207 ( & V_5 -> V_267 ) ;
F_207 ( & V_5 -> V_271 ) ;
F_208 ( V_73 -> V_106 ) ;
if ( V_73 -> V_2 -> V_121 . V_272 & V_273 )
F_209 ( V_73 ) ;
F_46 ( & V_73 -> V_116 ) ;
V_73 -> V_364 [ V_5 -> V_55 ] = NULL ;
V_73 -> V_365 [ V_5 -> V_55 ] = NULL ;
F_49 ( & V_73 -> V_116 ) ;
#ifdef F_185
F_35 ( V_5 ) ;
#endif
F_184 ( V_5 ) ;
F_25 ( V_5 -> V_211 ) ;
F_25 ( V_5 -> V_237 ) ;
if ( ! V_356 )
F_210 ( V_2 ) ;
}
static int F_211 ( struct V_1 * V_2 , int V_366 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
int V_105 = 0 ;
F_44 ( V_127 , V_5 , L_82 ,
V_2 -> V_230 , V_366 ) ;
if ( ( V_366 < V_367 ) || ( V_366 > V_5 -> V_290 ) ) {
F_14 ( V_5 , L_83 , V_366 ) ;
return - V_368 ;
}
V_2 -> V_230 = V_366 ;
if ( F_212 ( V_2 ) ) {
F_46 ( & V_73 -> V_116 ) ;
if ( ! V_73 -> V_117 ) {
F_44 ( V_127 , V_5 , L_84 ) ;
} else {
F_166 ( V_2 , 1 ) ;
V_105 = F_140 ( V_2 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_85 ,
V_5 -> V_55 ) ;
F_33 ( V_73 -> V_106 , & V_5 -> V_217 ) ;
}
}
F_49 ( & V_73 -> V_116 ) ;
}
return 0 ;
}
static int F_213 ( struct V_1 * V_2 , struct V_369 * V_370 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_349 V_371 ;
if ( F_214 ( & V_371 , V_370 -> V_372 , sizeof( V_371 ) ) )
return - V_373 ;
if ( V_371 . V_142 )
return - V_9 ;
if ( ! ( V_73 -> V_2 -> V_121 . V_272 & V_273 ) )
return - V_9 ;
switch ( V_371 . V_374 ) {
case V_375 :
case V_376 :
break;
default:
return - V_377 ;
}
switch ( V_371 . V_378 ) {
case V_379 :
break;
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
V_371 . V_378 = V_380 ;
break;
default:
return - V_377 ;
}
if ( F_215 ( V_2 , V_371 , V_2 -> V_394 ) ) {
V_371 . V_374 = V_375 ;
V_371 . V_378 = V_379 ;
}
return F_216 ( V_370 -> V_372 , & V_371 ,
sizeof( V_371 ) ) ? - V_373 : 0 ;
}
static int F_217 ( struct V_1 * V_2 , struct V_369 * V_370 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_216 ( V_370 -> V_372 , & V_5 -> V_349 ,
sizeof( V_5 -> V_349 ) ) ? - V_373 : 0 ;
}
static int F_218 ( struct V_1 * V_2 , struct V_369 * V_370 , int V_395 )
{
switch ( V_395 ) {
case V_396 :
return F_213 ( V_2 , V_370 ) ;
case V_397 :
return F_217 ( V_2 , V_370 ) ;
default:
return - V_398 ;
}
}
static T_7 F_219 ( struct V_1 * V_399 ,
T_7 V_394 )
{
struct V_4 * V_400 = F_2 ( V_399 ) ;
struct V_112 * V_73 = V_400 -> V_73 ;
if ( V_394 & V_401 &&
! ( V_73 -> V_2 -> V_121 . V_272 & V_402 ) )
V_394 |= V_403 ;
else
V_394 &= ~ V_403 ;
return V_394 ;
}
static int F_220 ( struct V_1 * V_399 ,
T_7 V_394 )
{
struct V_4 * V_5 = F_2 ( V_399 ) ;
bool V_404 = false ;
int V_87 = 0 ;
if ( F_221 ( V_399 , V_394 , V_405 ) ) {
F_132 ( V_5 , L_86 ,
( V_394 & V_405 ) ? L_87 : L_88 ) ;
V_404 = true ;
}
if ( F_221 ( V_399 , V_394 , V_406 ) ) {
T_1 V_407 = ( V_394 & V_406 ) ? 1 : 0 ;
F_132 ( V_5 , L_89 ,
V_407 ? L_87 : L_88 ) ;
V_87 = F_222 ( V_5 -> V_73 -> V_2 ,
V_5 -> V_55 , V_407 ) ;
if ( V_87 )
return V_87 ;
}
if ( F_221 ( V_399 , V_394 , V_401 ) ) {
F_132 ( V_5 , L_90 ,
( V_394 & V_401 ) ? L_87 : L_88 ) ;
V_404 = true ;
}
if ( F_221 ( V_399 , V_394 , V_408 ) )
F_132 ( V_5 , L_91 ,
( V_394 & V_408 ) ? L_87 : L_88 ) ;
if ( F_221 ( V_399 , V_394 , V_409 ) )
F_132 ( V_5 , L_92 ,
( V_394 & V_409 ) ? L_87 : L_88 ) ;
if ( F_221 ( V_399 , V_394 , V_410 ) ) {
F_132 ( V_5 , L_93 ,
( V_394 & V_410 ) ? L_87 : L_88 ) ;
F_223 ( V_399 , V_394 ) ;
}
if ( V_404 ) {
V_87 = F_215 ( V_399 , V_5 -> V_349 ,
V_394 ) ;
if ( V_87 )
return V_87 ;
}
return 0 ;
}
static int F_224 ( struct V_1 * V_2 , int V_411 , T_1 * V_128 )
{
struct V_4 * V_400 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_400 -> V_73 ;
T_6 V_412 = F_62 ( V_128 ) ;
if ( F_225 ( V_128 ) )
return - V_9 ;
return F_226 ( V_73 -> V_2 , V_400 -> V_55 , V_411 , V_412 ) ;
}
static int F_227 ( struct V_1 * V_2 , int V_413 , T_5 V_414 , T_1 V_415 )
{
struct V_4 * V_400 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_400 -> V_73 ;
return F_228 ( V_73 -> V_2 , V_400 -> V_55 , V_413 , V_414 , V_415 ) ;
}
static int F_229 ( struct V_1 * V_2 , int V_413 , int V_416 ,
int V_417 )
{
struct V_4 * V_400 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_400 -> V_73 ;
return F_230 ( V_73 -> V_2 , V_400 -> V_55 , V_413 , V_416 ,
V_417 ) ;
}
static int F_231 ( struct V_1 * V_2 , int V_413 , bool V_418 )
{
struct V_4 * V_400 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_400 -> V_73 ;
return F_232 ( V_73 -> V_2 , V_400 -> V_55 , V_413 , V_418 ) ;
}
static int F_233 ( struct V_1 * V_2 , int V_413 , struct V_419 * V_420 )
{
struct V_4 * V_400 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_400 -> V_73 ;
return F_234 ( V_73 -> V_2 , V_400 -> V_55 , V_413 , V_420 ) ;
}
static int F_235 ( struct V_1 * V_2 , int V_413 , int V_196 )
{
struct V_4 * V_400 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_400 -> V_73 ;
return F_236 ( V_73 -> V_2 , V_400 -> V_55 , V_413 , V_196 ) ;
}
static int F_237 ( struct V_1 * V_2 , int V_413 ,
struct V_421 * V_422 )
{
struct V_4 * V_400 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_400 -> V_73 ;
return F_238 ( V_73 -> V_2 , V_400 -> V_55 , V_413 , V_422 ) ;
}
static int F_239 ( struct V_1 * V_2 ,
struct V_423 * V_424 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_129 * V_73 = V_5 -> V_73 -> V_2 ;
int V_6 ;
T_6 V_425 = V_73 -> V_121 . V_425 [ V_5 -> V_55 ] ;
if ( ! V_425 )
return - V_398 ;
V_424 -> V_426 = sizeof( V_425 ) ;
for ( V_6 = V_427 - 1 ; V_6 >= 0 ; -- V_6 ) {
V_424 -> V_29 [ V_6 ] = V_425 & 0xff ;
V_425 >>= 8 ;
}
return 0 ;
}
static void F_240 ( struct V_23 * V_24 )
{
int V_87 ;
struct V_4 * V_5 = F_8 ( V_24 , struct V_4 ,
V_428 ) ;
V_87 = F_241 ( V_5 -> V_73 -> V_2 , V_5 -> V_429 ) ;
if ( V_87 )
goto V_103;
V_87 = F_154 ( V_5 -> V_73 -> V_2 , V_5 -> V_55 ,
V_316 , 1 ) ;
V_103:
if ( V_87 ) {
F_14 ( V_5 , L_94 , V_87 ) ;
return;
}
V_5 -> V_2 -> V_430 |= V_431 | V_432 |
V_433 |
V_434 | V_435 |
V_436 |
V_437 |
V_438 ;
}
static void F_242 ( struct V_23 * V_24 )
{
int V_87 ;
struct V_4 * V_5 = F_8 ( V_24 , struct V_4 ,
V_439 ) ;
V_5 -> V_2 -> V_430 &= ~ ( V_431 | V_432 |
V_433 |
V_434 | V_435 |
V_436 |
V_437 |
V_438 ) ;
V_87 = F_154 ( V_5 -> V_73 -> V_2 , V_5 -> V_55 ,
V_316 , 0 ) ;
if ( V_87 )
F_14 ( V_5 , L_94 , V_87 ) ;
V_5 -> V_429 = 0 ;
}
static void F_243 ( struct V_1 * V_2 ,
T_8 V_440 , T_3 V_55 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_441 ;
if ( V_5 -> V_73 -> V_2 -> V_121 . V_122 != V_123 )
return;
if ( V_440 == V_442 )
return;
V_441 = V_5 -> V_429 ;
if ( V_441 && V_441 != V_55 ) {
F_11 ( V_5 , L_95 ,
F_244 ( V_441 ) , F_244 ( V_55 ) ) ;
return;
}
V_5 -> V_429 = V_55 ;
F_33 ( V_5 -> V_73 -> V_106 , & V_5 -> V_428 ) ;
}
static void F_245 ( struct V_1 * V_2 ,
T_8 V_440 , T_3 V_55 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_441 ;
if ( V_5 -> V_73 -> V_2 -> V_121 . V_122 != V_123 )
return;
if ( V_440 == V_442 )
return;
V_441 = V_5 -> V_429 ;
if ( V_441 != V_55 ) {
F_44 ( V_127 , V_5 , L_96 , F_244 ( V_55 ) ) ;
return;
}
F_33 ( V_5 -> V_73 -> V_106 , & V_5 -> V_439 ) ;
}
static T_7 F_246 ( struct V_89 * V_90 ,
struct V_1 * V_2 ,
T_7 V_394 )
{
V_394 = F_247 ( V_90 , V_394 ) ;
V_394 = F_248 ( V_90 , V_394 ) ;
if ( V_90 -> V_443 &&
( V_90 -> V_444 == V_445 ) ) {
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_429 ||
( F_249 ( V_90 ) -> V_446 != 4 ) ||
( F_250 ( V_90 ) -> V_447 != V_5 -> V_429 ) )
V_394 &= ~ ( V_448 | V_449 ) ;
}
return V_394 ;
}
static int F_251 ( struct V_1 * V_2 , int V_450 , T_2 V_451 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_282 * V_211 = V_5 -> V_211 [ V_450 ] ;
struct V_452 V_453 ;
int V_105 ;
if ( ! ( V_5 -> V_73 -> V_2 -> V_121 . V_272 & V_454 ) )
return - V_398 ;
if ( V_451 >> 12 ) {
V_453 . V_455 = V_456 ;
V_453 . V_457 = V_451 / 1000 ;
} else if ( V_451 ) {
V_453 . V_455 = V_458 ;
V_453 . V_457 = V_451 ;
} else {
V_453 . V_455 = 0 ;
V_453 . V_457 = 0 ;
}
V_105 = F_252 ( V_5 -> V_73 -> V_2 , V_211 -> V_62 , V_459 ,
& V_453 ) ;
return V_105 ;
}
static void F_253 ( struct V_23 * V_24 )
{
struct V_460 * V_461 = F_8 ( V_24 ,
struct V_460 ,
V_24 ) ;
int V_105 = 0 ;
struct V_129 * V_2 = V_461 -> V_5 -> V_73 -> V_2 ;
if ( V_461 -> V_462 ) {
if ( ! F_254 ( V_2 ) ) {
V_105 = F_255 ( V_2 ) ;
if ( V_105 )
F_14 ( V_461 -> V_5 , L_97 ) ;
}
if ( ! V_105 ) {
V_105 = F_256 ( V_2 , & V_461 -> V_463 ) ;
if ( V_105 )
F_14 ( V_461 -> V_5 , L_98 ,
V_461 -> V_463 . V_464 ,
V_461 -> V_463 . V_465 ,
V_105 ) ;
}
} else if ( F_254 ( V_2 ) ) {
V_105 = F_257 ( V_2 ) ;
if ( V_105 )
F_14 ( V_461 -> V_5 , L_99 ) ;
}
F_258 ( V_461 -> V_5 -> V_2 ) ;
F_25 ( V_461 ) ;
}
static int F_259 ( struct V_4 * V_5 , int V_462 ,
T_1 V_466 , T_1 V_467 )
{
struct V_460 * V_461 = NULL ;
V_461 = F_20 ( sizeof( * V_461 ) , V_81 ) ;
if ( ! V_461 )
return - V_104 ;
F_21 ( & V_461 -> V_24 , F_253 ) ;
V_461 -> V_5 = V_5 ;
V_461 -> V_462 = V_462 ;
V_461 -> V_463 . V_464 = V_466 ;
V_461 -> V_463 . V_465 = V_467 ;
F_260 ( V_5 -> V_2 ) ;
F_33 ( V_5 -> V_73 -> V_106 , & V_461 -> V_24 ) ;
return 0 ;
}
int F_261 ( struct V_468 * V_469 ,
unsigned long V_470 , void * V_471 )
{
struct V_1 * V_472 = F_262 ( V_471 ) ;
T_1 V_55 = 0 ;
struct V_112 * V_73 ;
struct V_129 * V_2 ;
int V_6 , V_473 = 0 ;
bool V_474 = true ;
struct V_4 * V_5 ;
T_1 V_475 = 0 ;
T_1 V_476 = 0 ;
if ( ! F_263 ( F_264 ( V_472 ) , & V_477 ) )
return V_478 ;
V_73 = F_8 ( V_469 , struct V_112 , V_479 ) ;
V_2 = V_73 -> V_2 ;
F_265 (i, dev, MLX4_PORT_TYPE_ETH) {
++ V_473 ;
if ( ! V_55 && ( V_73 -> V_364 [ V_6 ] == V_472 ) )
V_55 = V_6 ;
V_73 -> V_365 [ V_6 ] = V_73 -> V_364 [ V_6 ] ?
F_266 ( V_73 -> V_364 [ V_6 ] ) : NULL ;
if ( ! V_73 -> V_365 [ V_6 ] )
V_474 = false ;
if ( V_473 < 2 )
continue;
if ( V_73 -> V_365 [ V_6 ] != V_73 -> V_365 [ V_6 - 1 ] )
V_474 = false ;
}
V_474 = ( V_473 == 2 ) ? V_474 : false ;
if ( ( V_474 && ( V_470 != V_480 ) ) || ! V_55 )
return V_478 ;
V_5 = F_2 ( V_472 ) ;
if ( V_474 ) {
struct V_481 * V_482 = V_471 ;
struct V_483 * V_484 =
& V_482 -> V_484 ;
if ( ( V_484 -> V_485 . V_486 != V_487 ) &&
( V_484 -> V_485 . V_486 != V_488 ) &&
( V_484 -> V_485 . V_486 != V_489 ) )
V_474 = false ;
if ( V_484 -> V_485 . V_490 != 2 )
V_474 = false ;
if ( V_474 ) {
if ( V_484 -> V_485 . V_486 ==
V_487 ) {
if ( V_484 -> V_491 . V_492 ==
V_493 ) {
if ( V_55 == 1 ) {
V_475 = 2 ;
V_476 = 2 ;
} else {
V_475 = 1 ;
V_476 = 1 ;
}
} else {
if ( V_55 == 1 ) {
V_475 = 1 ;
V_476 = 1 ;
} else {
V_475 = 2 ;
V_476 = 2 ;
}
}
} else {
T_9 V_494 = V_484 -> V_491 . V_494 ;
if ( V_55 == 1 )
V_476 = 2 ;
else
V_475 = 1 ;
if ( ( V_494 == V_495 ) ||
( V_494 == V_496 ) ) {
if ( V_55 == 1 )
V_475 = 1 ;
else
V_476 = 2 ;
} else {
if ( V_55 == 1 )
V_475 = 2 ;
else
V_476 = 1 ;
}
}
}
}
F_259 ( V_5 , V_474 ,
V_475 , V_476 ) ;
return V_478 ;
}
void F_267 ( struct V_129 * V_2 ,
struct V_497 * V_498 ,
T_1 V_315 , T_1 V_314 ,
T_1 V_313 , T_1 V_312 )
{
int V_499 = V_500 + V_501 + V_502 ;
if ( ! F_268 ( V_2 ) &&
( V_2 -> V_121 . V_272 & V_503 ) ) {
F_46 ( & V_498 -> V_504 ) ;
F_269 ( V_498 -> V_505 , V_499 , V_506 ) ;
if ( V_315 )
F_270 ( V_498 -> V_505 , V_499 ,
V_507 ) ;
V_499 += V_507 ;
if ( V_314 && ! ( V_315 ) )
F_270 ( V_498 -> V_505 , V_499 ,
V_508 ) ;
V_499 += V_508 ;
if ( V_313 )
F_270 ( V_498 -> V_505 , V_499 ,
V_509 ) ;
V_499 += V_509 ;
if ( V_312 && ! ( V_313 ) )
F_270 ( V_498 -> V_505 , V_499 ,
V_510 ) ;
V_499 += V_510 ;
F_49 ( & V_498 -> V_504 ) ;
}
}
void F_271 ( struct V_129 * V_2 ,
struct V_497 * V_498 ,
T_1 V_315 , T_1 V_314 ,
T_1 V_313 , T_1 V_312 )
{
int V_499 = 0 ;
F_272 ( & V_498 -> V_504 ) ;
F_273 ( V_498 -> V_505 , V_511 ) ;
if ( F_268 ( V_2 ) ) {
F_270 ( V_498 -> V_505 , V_499 +
F_274 ( V_256 ) , 1 ) ;
F_270 ( V_498 -> V_505 , V_499 +
F_274 ( V_512 ) , 1 ) ;
F_270 ( V_498 -> V_505 , V_499 +
F_274 ( V_257 ) , 1 ) ;
F_270 ( V_498 -> V_505 , V_499 +
F_274 ( V_513 ) , 1 ) ;
F_270 ( V_498 -> V_505 , V_499 +
F_274 ( V_514 ) , 1 ) ;
F_270 ( V_498 -> V_505 , V_499 +
F_274 ( V_330 ) , 1 ) ;
} else {
F_270 ( V_498 -> V_505 , V_499 , V_500 ) ;
}
V_499 += V_500 ;
F_270 ( V_498 -> V_505 , V_499 , V_501 ) ;
V_499 += V_501 ;
if ( F_275 ( V_2 ) )
F_270 ( V_498 -> V_505 , V_499 ,
V_502 ) ;
V_499 += V_502 ;
F_267 ( V_2 , V_498 ,
V_315 , V_314 ,
V_313 , V_312 ) ;
V_499 += V_506 ;
if ( ! F_268 ( V_2 ) )
F_270 ( V_498 -> V_505 , V_499 , V_515 ) ;
}
int F_276 ( struct V_112 * V_73 , int V_55 ,
struct V_343 * V_311 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_6 ;
int V_105 ;
V_2 = F_277 ( sizeof( struct V_4 ) ,
V_354 , V_516 ) ;
if ( V_2 == NULL )
return - V_104 ;
F_278 ( V_2 , V_311 -> V_210 ) ;
F_279 ( V_2 , V_311 -> V_205 ) ;
F_280 ( V_2 , & V_73 -> V_2 -> V_357 -> V_517 -> V_2 ) ;
V_2 -> V_518 = V_55 - 1 ;
V_5 = F_2 ( V_2 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_302 = F_173 ( V_73 -> V_2 ) ;
F_281 ( & V_5 -> V_220 ) ;
F_21 ( & V_5 -> V_177 , F_107 ) ;
F_21 ( & V_5 -> V_217 , F_178 ) ;
F_21 ( & V_5 -> V_275 , F_131 ) ;
F_282 ( & V_5 -> V_267 , F_124 ) ;
F_282 ( & V_5 -> V_271 , F_128 ) ;
#ifdef F_158
F_21 ( & V_5 -> V_428 , F_240 ) ;
F_21 ( & V_5 -> V_439 , F_242 ) ;
#endif
#ifdef F_185
F_58 ( & V_5 -> V_85 ) ;
F_281 ( & V_5 -> V_102 ) ;
#endif
V_5 -> V_2 = V_2 ;
V_5 -> V_73 = V_73 ;
V_5 -> V_519 = & V_73 -> V_517 -> V_2 ;
V_5 -> V_311 = V_311 ;
V_5 -> V_55 = V_55 ;
V_5 -> V_118 = false ;
V_5 -> V_142 = V_311 -> V_142 ;
V_5 -> V_520 = V_521 ;
V_5 -> V_522 = F_283 ( V_523 |
V_524 ) ;
V_5 -> V_10 = V_73 -> V_350 . V_10 ;
V_5 -> V_210 = V_311 -> V_210 ;
V_5 -> V_525 = V_526 ;
F_284 ( V_5 -> V_527 , sizeof( V_5 -> V_527 ) ) ;
V_5 -> V_211 = F_20 ( sizeof( struct V_282 * ) * V_354 ,
V_175 ) ;
if ( ! V_5 -> V_211 ) {
V_105 = - V_104 ;
goto V_103;
}
V_5 -> V_237 = F_20 ( sizeof( struct V_203 * ) * V_354 ,
V_175 ) ;
if ( ! V_5 -> V_237 ) {
V_105 = - V_104 ;
goto V_103;
}
V_5 -> V_205 = V_311 -> V_205 ;
V_5 -> V_298 = ( V_73 -> V_2 -> V_121 . V_297 == 64 ) ? 1 : 0 ;
V_5 -> V_297 = V_73 -> V_2 -> V_121 . V_297 ;
V_5 -> V_528 = - 1 ;
V_5 -> V_529 = V_530 ;
#ifdef F_285
if ( ! F_268 ( V_5 -> V_73 -> V_2 ) ) {
if ( V_73 -> V_2 -> V_121 . V_272 & V_531 ) {
V_2 -> V_532 = & V_533 ;
} else {
F_132 ( V_5 , L_100 ) ;
V_2 -> V_532 = & V_534 ;
}
}
#endif
for ( V_6 = 0 ; V_6 < V_193 ; ++ V_6 )
F_286 ( & V_5 -> V_148 [ V_6 ] ) ;
V_5 -> V_290 = V_73 -> V_2 -> V_121 . V_535 [ V_5 -> V_55 ] ;
if ( V_73 -> V_2 -> V_121 . V_536 [ V_5 -> V_55 ] &
V_537 )
V_5 -> V_142 |= V_538 ;
V_2 -> V_539 = V_69 ;
F_53 ( V_2 -> V_68 , V_73 -> V_2 -> V_121 . V_540 [ V_5 -> V_55 ] ) ;
if ( ! F_78 ( V_2 -> V_68 ) ) {
F_14 ( V_5 , L_101 ,
V_5 -> V_55 , V_2 -> V_68 ) ;
V_105 = - V_9 ;
goto V_103;
} else if ( F_268 ( V_5 -> V_73 -> V_2 ) &&
( V_5 -> V_73 -> V_2 -> V_541 & 1 << V_5 -> V_55 ) ) {
V_2 -> V_542 |= V_543 ;
F_11 ( V_5 , L_102 , V_2 -> V_68 ) ;
}
memcpy ( V_5 -> V_156 , V_2 -> V_68 , sizeof( V_5 -> V_156 ) ) ;
V_5 -> V_342 = F_198 ( sizeof( struct V_351 ) +
V_352 * V_353 ) ;
V_105 = F_189 ( V_5 ) ;
if ( V_105 )
goto V_103;
V_5 -> V_349 . V_142 = 0 ;
V_5 -> V_349 . V_374 = V_375 ;
V_5 -> V_349 . V_378 = V_379 ;
V_105 = F_287 ( V_73 -> V_2 , & V_5 -> V_362 ,
V_363 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_103 ) ;
goto V_103;
}
V_5 -> V_361 = 1 ;
if ( F_275 ( V_5 -> V_73 -> V_2 ) )
V_2 -> V_544 = & V_545 ;
else
V_2 -> V_544 = & V_546 ;
V_2 -> V_547 = V_548 ;
F_278 ( V_2 , V_5 -> V_210 ) ;
F_279 ( V_2 , V_5 -> V_205 ) ;
V_2 -> V_549 = & V_550 ;
V_2 -> V_551 = V_552 | V_431 | V_432 ;
if ( V_73 -> V_553 )
V_2 -> V_551 |= V_434 | V_435 ;
V_2 -> V_554 = V_2 -> V_551 ;
V_2 -> V_551 |= V_433 | V_555 ;
V_2 -> V_394 = V_2 -> V_551 | V_556 |
V_408 | V_401 |
V_557 ;
V_2 -> V_551 |= V_410 |
V_408 | V_401 ;
if ( ! ( V_73 -> V_2 -> V_121 . V_272 & V_402 ) ) {
V_2 -> V_394 |= V_403 |
V_558 ;
V_2 -> V_551 |= V_403 ;
}
if ( F_268 ( V_73 -> V_2 ) ) {
int V_559 ;
V_105 = F_288 ( V_73 -> V_2 , V_55 , & V_559 ) ;
if ( ! V_105 && V_559 ) {
V_2 -> V_551 |= V_409 ;
V_5 -> V_520 |= V_560 ;
}
} else {
if ( V_73 -> V_2 -> V_121 . V_272 & V_561 &&
! ( V_73 -> V_2 -> V_121 . V_272 &
V_402 ) )
V_2 -> V_551 |= V_409 ;
}
if ( V_73 -> V_2 -> V_121 . V_142 & V_562 )
V_2 -> V_551 |= V_405 ;
if ( V_73 -> V_2 -> V_121 . V_272 & V_563 )
V_2 -> V_551 |= V_406 ;
if ( V_73 -> V_2 -> V_121 . V_130 ==
V_136 &&
V_73 -> V_2 -> V_121 . V_124 != V_125 )
V_2 -> V_551 |= V_564 ;
if ( V_73 -> V_2 -> V_121 . V_130 != V_140 )
V_2 -> V_200 |= V_201 ;
if ( V_73 -> V_2 -> V_121 . V_272 & V_565 ) {
V_5 -> V_566 = V_567 ;
} else if ( V_73 -> V_2 -> V_121 . V_272 & V_568 ) {
V_5 -> V_566 = V_569 ;
} else {
F_11 ( V_5 ,
L_104 ) ;
V_5 -> V_566 = V_567 ;
}
if ( V_73 -> V_2 -> V_121 . V_122 == V_123 ) {
V_2 -> V_551 |= V_436 |
V_437 |
V_438 ;
V_2 -> V_394 |= V_436 |
V_437 |
V_438 ;
V_2 -> V_570 = V_437 ;
}
V_73 -> V_364 [ V_55 ] = V_2 ;
V_73 -> V_365 [ V_55 ] = NULL ;
F_133 ( V_2 ) ;
F_121 ( V_5 ) ;
F_11 ( V_5 , L_105 , V_311 -> V_210 ) ;
F_11 ( V_5 , L_106 , V_311 -> V_205 ) ;
F_223 ( V_5 -> V_2 , V_5 -> V_2 -> V_394 ) ;
F_142 ( V_2 ) ;
V_105 = F_153 ( V_73 -> V_2 , V_5 -> V_55 ,
V_5 -> V_291 + V_310 ,
V_311 -> V_312 , V_311 -> V_313 ,
V_311 -> V_314 , V_311 -> V_315 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_65 ,
V_5 -> V_55 , V_105 ) ;
goto V_103;
}
if ( V_73 -> V_2 -> V_121 . V_122 == V_123 ) {
V_105 = F_154 ( V_73 -> V_2 , V_5 -> V_55 , V_316 , 1 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_67 ,
V_105 ) ;
goto V_103;
}
}
F_11 ( V_5 , L_68 ) ;
V_105 = F_155 ( V_73 -> V_2 , V_5 -> V_55 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_69 ) ;
goto V_103;
}
F_127 ( V_73 -> V_106 , & V_5 -> V_267 , V_268 ) ;
if ( V_73 -> V_2 -> V_121 . V_272 & V_273 )
F_289 ( V_73 ) ;
F_127 ( V_73 -> V_106 , & V_5 -> V_271 ,
V_274 ) ;
F_271 ( V_73 -> V_2 , & V_5 -> V_498 ,
V_73 -> V_350 . V_311 [ V_5 -> V_55 ] . V_315 ,
V_73 -> V_350 . V_311 [ V_5 -> V_55 ] . V_314 ,
V_73 -> V_350 . V_311 [ V_5 -> V_55 ] . V_313 ,
V_73 -> V_350 . V_311 [ V_5 -> V_55 ] . V_312 ) ;
V_105 = F_290 ( V_2 ) ;
if ( V_105 ) {
F_14 ( V_5 , L_107 , V_55 ) ;
goto V_103;
}
V_5 -> V_360 = 1 ;
F_291 ( F_204 ( V_73 -> V_2 , V_5 -> V_55 ) ,
V_2 ) ;
return 0 ;
V_103:
F_202 ( V_2 ) ;
return V_105 ;
}
int F_215 ( struct V_1 * V_2 ,
struct V_349 V_571 ,
T_7 V_394 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_112 * V_73 = V_5 -> V_73 ;
struct V_343 V_572 ;
struct V_4 * V_107 ;
int V_118 = 0 ;
int V_105 = 0 ;
if ( V_5 -> V_349 . V_374 == V_571 . V_374 &&
V_5 -> V_349 . V_378 == V_571 . V_378 &&
! F_221 ( V_2 , V_394 , V_401 ) &&
! F_221 ( V_2 , V_394 , V_405 ) )
return 0 ;
if ( F_221 ( V_2 , V_394 , V_401 ) &&
( V_394 & V_401 ) &&
( V_5 -> V_349 . V_378 != V_379 ) ) {
F_11 ( V_5 , L_108 ) ;
return - V_9 ;
}
V_107 = F_20 ( sizeof( * V_107 ) , V_175 ) ;
if ( ! V_107 )
return - V_104 ;
F_46 ( & V_73 -> V_116 ) ;
memcpy ( & V_572 , V_5 -> V_311 , sizeof( struct V_343 ) ) ;
memcpy ( & V_572 . V_349 , & V_571 , sizeof( V_571 ) ) ;
V_105 = F_200 ( V_5 , V_107 , & V_572 ) ;
if ( V_105 )
goto V_103;
if ( V_5 -> V_118 ) {
V_118 = 1 ;
F_166 ( V_2 , 1 ) ;
}
F_11 ( V_5 , L_109 ,
V_571 . V_378 ,
! ! ( V_394 & V_401 ) ) ;
F_201 ( V_5 , V_107 ) ;
if ( F_221 ( V_2 , V_394 , V_401 ) ) {
if ( V_394 & V_401 )
V_2 -> V_394 |= V_401 ;
else
V_2 -> V_394 &= ~ V_401 ;
} else if ( V_571 . V_378 == V_379 ) {
if ( V_2 -> V_573 & V_401 )
V_2 -> V_394 |= V_401 ;
else
V_2 -> V_394 &= ~ V_401 ;
}
if ( F_221 ( V_2 , V_394 , V_405 ) ) {
if ( V_394 & V_405 )
V_2 -> V_394 |= V_405 ;
else
V_2 -> V_394 &= ~ V_405 ;
}
if ( V_571 . V_378 != V_379 ) {
if ( V_2 -> V_394 & V_401 )
F_11 ( V_5 , L_110 ) ;
V_2 -> V_394 &= ~ V_401 ;
}
if ( V_118 ) {
V_105 = F_140 ( V_2 ) ;
if ( V_105 )
F_14 ( V_5 , L_111 ) ;
}
V_103:
F_49 ( & V_73 -> V_116 ) ;
F_25 ( V_107 ) ;
if ( ! V_105 )
F_292 ( V_2 ) ;
return V_105 ;
}
