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
struct V_15 * V_16 = & V_5 -> V_16 [ V_14 -> V_17 ] ;
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
static void F_11 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_6 ( V_25 ,
struct V_26 ,
V_25 ) ;
struct V_4 * V_5 = V_27 -> V_5 ;
struct V_28 V_29 = {
. V_30 = V_31 ,
{
. V_32 = {
. V_33 = V_27 -> V_33 ,
. V_34 = ( V_35 V_36 ) - 1 ,
. V_37 = V_27 -> V_37 ,
. V_38 = ( V_35 V_36 ) - 1 ,
} ,
} ,
} ;
struct V_28 V_39 = {
. V_30 = V_40 ,
{
. V_41 = {
. V_42 = V_27 -> V_42 ,
. V_43 = ( V_35 V_44 ) - 1 ,
. V_45 = V_27 -> V_45 ,
. V_46 = ( V_35 V_44 ) - 1 ,
} ,
} ,
} ;
struct V_28 V_47 = {
. V_30 = V_48 ,
} ;
struct V_49 V_50 = {
. V_51 = F_12 ( V_50 . V_51 ) ,
. V_52 = V_53 ,
. V_54 = 1 ,
. V_55 = 1 ,
. V_56 = V_57 ,
. V_58 = V_5 -> V_58 ,
. V_59 = V_60 ,
} ;
int V_61 ;
T_2 V_62 = F_13 ( V_63 << 16 ) ;
F_14 ( & V_47 . V_51 , & V_50 . V_51 ) ;
F_14 ( & V_39 . V_51 , & V_50 . V_51 ) ;
F_14 ( & V_29 . V_51 , & V_50 . V_51 ) ;
V_50 . V_64 = V_5 -> V_65 . V_66 [ V_27 -> V_67 ] . V_64 ;
memcpy ( V_47 . V_68 . V_69 , V_5 -> V_2 -> V_70 , V_71 ) ;
memcpy ( V_47 . V_68 . V_72 , & V_62 , V_71 ) ;
V_27 -> V_73 = 0 ;
if ( V_27 -> V_74 ) {
V_61 = F_15 ( V_5 -> V_75 -> V_2 , V_27 -> V_74 ) ;
if ( V_61 && V_61 != - V_76 )
F_16 ( V_5 , L_1 , V_61 ) ;
}
V_61 = F_17 ( V_5 -> V_75 -> V_2 , & V_50 , & V_27 -> V_74 ) ;
if ( V_61 )
F_16 ( V_5 , L_2 , V_61 ) ;
F_18 ( V_5 ) ;
V_27 -> V_73 = 1 ;
}
static inline struct V_77 *
F_19 ( struct V_4 * V_5 , V_44 V_45 , V_44 V_42 ,
V_36 V_37 , V_36 V_33 )
{
unsigned long V_78 ;
int V_79 ;
V_78 = ( V_35 unsigned long ) V_37 |
( ( V_35 unsigned long ) V_33 << 2 ) ;
V_78 ^= ( V_35 unsigned long ) ( V_45 ^ V_42 ) ;
V_79 = F_20 ( V_78 , V_80 ) ;
return & V_5 -> V_81 [ V_79 ] ;
}
static struct V_26 *
F_21 ( struct V_4 * V_5 , int V_67 , V_44 V_45 ,
V_44 V_42 , V_36 V_37 , V_36 V_33 ,
T_3 V_82 )
{
struct V_26 * V_27 = NULL ;
V_27 = F_22 ( sizeof( struct V_26 ) , V_83 ) ;
if ( ! V_27 )
return NULL ;
V_27 -> V_5 = V_5 ;
V_27 -> V_67 = V_67 ;
F_23 ( & V_27 -> V_25 , F_11 ) ;
V_27 -> V_45 = V_45 ;
V_27 -> V_42 = V_42 ;
V_27 -> V_37 = V_37 ;
V_27 -> V_33 = V_33 ;
V_27 -> V_82 = V_82 ;
V_27 -> V_30 = V_5 -> V_84 ++ % V_85 ;
F_14 ( & V_27 -> V_86 , & V_5 -> V_87 ) ;
F_24 ( & V_27 -> V_88 ,
F_19 ( V_5 , V_45 , V_42 , V_37 ,
V_33 ) ) ;
return V_27 ;
}
static void F_25 ( struct V_26 * V_27 )
{
struct V_4 * V_5 = V_27 -> V_5 ;
int V_61 ;
F_26 ( & V_27 -> V_86 ) ;
V_61 = F_15 ( V_5 -> V_75 -> V_2 , V_27 -> V_74 ) ;
if ( V_61 && V_61 != - V_76 )
F_16 ( V_5 , L_1 , V_61 ) ;
F_27 ( V_27 ) ;
}
static inline struct V_26 *
F_28 ( struct V_4 * V_5 , V_44 V_45 , V_44 V_42 ,
V_36 V_37 , V_36 V_33 )
{
struct V_26 * V_27 ;
struct V_26 * V_89 = NULL ;
F_29 (filter,
filter_hash_bucket(priv, src_ip, dst_ip,
src_port, dst_port),
filter_chain) {
if ( V_27 -> V_45 == V_45 &&
V_27 -> V_42 == V_42 &&
V_27 -> V_37 == V_37 &&
V_27 -> V_33 == V_33 ) {
V_89 = V_27 ;
break;
}
}
return V_89 ;
}
static int
F_30 ( struct V_1 * V_90 , const struct V_91 * V_92 ,
T_4 V_67 , T_3 V_82 )
{
struct V_4 * V_5 = F_2 ( V_90 ) ;
struct V_26 * V_27 ;
const struct V_93 * V_94 ;
const V_36 * V_95 ;
V_44 V_45 ;
V_44 V_42 ;
V_36 V_37 ;
V_36 V_33 ;
int V_96 = F_31 ( V_92 ) ;
int V_89 = 0 ;
if ( V_92 -> V_97 != F_32 ( V_98 ) )
return - V_99 ;
V_94 = ( const struct V_93 * ) ( V_92 -> V_100 + V_96 ) ;
if ( F_33 ( V_94 ) )
return - V_99 ;
V_95 = ( const V_36 * ) ( V_92 -> V_100 + V_96 + 4 * V_94 -> V_101 ) ;
V_45 = V_94 -> V_102 ;
V_42 = V_94 -> V_103 ;
V_37 = V_95 [ 0 ] ;
V_33 = V_95 [ 1 ] ;
if ( V_94 -> V_97 != V_104 )
return - V_99 ;
F_34 ( & V_5 -> V_105 ) ;
V_27 = F_28 ( V_5 , V_45 , V_42 , V_37 , V_33 ) ;
if ( V_27 ) {
if ( V_27 -> V_67 == V_67 )
goto V_106;
V_27 -> V_67 = V_67 ;
} else {
V_27 = F_21 ( V_5 , V_67 ,
V_45 , V_42 ,
V_37 , V_33 , V_82 ) ;
if ( ! V_27 ) {
V_89 = - V_107 ;
goto V_108;
}
}
F_35 ( V_5 -> V_75 -> V_109 , & V_27 -> V_25 ) ;
V_106:
V_89 = V_27 -> V_30 ;
V_108:
F_36 ( & V_5 -> V_105 ) ;
return V_89 ;
}
void F_37 ( struct V_4 * V_5 ,
struct V_15 * V_16 )
{
struct V_26 * V_27 , * V_110 ;
F_38 ( V_111 ) ;
F_34 ( & V_5 -> V_105 ) ;
F_39 (filter, tmp, &priv->filters, next) {
F_40 ( & V_27 -> V_86 , & V_111 ) ;
F_41 ( & V_27 -> V_88 ) ;
}
F_36 ( & V_5 -> V_105 ) ;
F_39 (filter, tmp, &del_list, next) {
F_42 ( & V_27 -> V_25 ) ;
F_25 ( V_27 ) ;
}
}
static void F_18 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = NULL , * V_110 , * V_112 = NULL ;
F_38 ( V_111 ) ;
int V_6 = 0 ;
F_34 ( & V_5 -> V_105 ) ;
F_39 (filter, tmp, &priv->filters, next) {
if ( V_6 > V_113 )
break;
if ( V_27 -> V_73 &&
! F_43 ( & V_27 -> V_25 ) &&
F_44 ( V_5 -> V_2 ,
V_27 -> V_67 , V_27 -> V_82 ,
V_27 -> V_30 ) ) {
F_40 ( & V_27 -> V_86 , & V_111 ) ;
F_41 ( & V_27 -> V_88 ) ;
} else
V_112 = V_27 ;
V_6 ++ ;
}
if ( V_112 && ( & V_112 -> V_86 != V_5 -> V_87 . V_86 ) )
F_40 ( & V_5 -> V_87 , & V_112 -> V_86 ) ;
F_36 ( & V_5 -> V_105 ) ;
F_39 (filter, tmp, &del_list, next)
F_25 ( V_27 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
V_36 V_114 , T_4 V_115 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
int V_108 ;
int V_117 ;
F_46 ( V_118 , V_5 , L_3 , V_115 ) ;
F_47 ( V_115 , V_5 -> V_119 ) ;
F_48 ( & V_75 -> V_120 ) ;
if ( V_75 -> V_121 && V_5 -> V_19 ) {
V_108 = F_49 ( V_75 -> V_2 , V_5 ) ;
if ( V_108 )
F_16 ( V_5 , L_4 ) ;
}
if ( F_50 ( V_75 -> V_2 , V_5 -> V_58 , V_115 , & V_117 ) )
F_46 ( V_118 , V_5 , L_5 , V_115 ) ;
F_51 ( & V_75 -> V_120 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
V_36 V_114 , T_4 V_115 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
int V_108 ;
int V_117 ;
F_46 ( V_118 , V_5 , L_6 , V_115 ) ;
F_53 ( V_115 , V_5 -> V_119 ) ;
F_48 ( & V_75 -> V_120 ) ;
if ( ! F_54 ( V_75 -> V_2 , V_5 -> V_58 , V_115 , & V_117 ) )
F_55 ( V_75 -> V_2 , V_5 -> V_58 , V_117 ) ;
else
F_46 ( V_118 , V_5 , L_7 , V_115 ) ;
if ( V_75 -> V_121 && V_5 -> V_19 ) {
V_108 = F_49 ( V_75 -> V_2 , V_5 ) ;
if ( V_108 )
F_16 ( V_5 , L_4 ) ;
}
F_51 ( & V_75 -> V_120 ) ;
return 0 ;
}
static void F_56 ( unsigned char V_69 [ V_71 + 2 ] , T_5 V_122 )
{
int V_6 ;
for ( V_6 = V_71 - 1 ; V_6 >= 0 ; -- V_6 ) {
V_69 [ V_6 ] = V_122 & 0xff ;
V_122 >>= 8 ;
}
memset ( & V_69 [ V_71 ] , 0 , 2 ) ;
}
static int F_57 ( struct V_4 * V_5 ,
unsigned char * V_123 , int * V_64 , T_5 * V_74 )
{
struct V_116 * V_75 = V_5 -> V_75 ;
struct V_124 * V_2 = V_75 -> V_2 ;
int V_108 ;
switch ( V_2 -> V_125 . V_126 ) {
case V_127 : {
struct V_128 V_129 ;
T_1 V_130 [ 16 ] = { 0 } ;
V_129 . V_64 = * V_64 ;
memcpy ( & V_130 [ 10 ] , V_123 , V_71 ) ;
V_130 [ 5 ] = V_5 -> V_58 ;
V_108 = F_58 ( V_2 , & V_129 , V_130 , 0 , V_131 ) ;
break;
}
case V_132 : {
struct V_28 V_47 = { { NULL } } ;
T_2 V_62 = F_13 ( V_63 << 16 ) ;
struct V_49 V_50 = {
. V_52 = V_133 ,
. V_54 = 0 ,
. V_55 = 1 ,
. V_56 = V_57 ,
. V_59 = V_134 ,
} ;
V_50 . V_58 = V_5 -> V_58 ;
V_50 . V_64 = * V_64 ;
F_59 ( & V_50 . V_51 ) ;
V_47 . V_30 = V_48 ;
memcpy ( V_47 . V_68 . V_69 , V_123 , V_71 ) ;
memcpy ( V_47 . V_68 . V_72 , & V_62 , V_71 ) ;
F_14 ( & V_47 . V_51 , & V_50 . V_51 ) ;
V_108 = F_17 ( V_2 , & V_50 , V_74 ) ;
break;
}
default:
return - V_9 ;
}
if ( V_108 )
F_60 ( V_5 , L_8 ) ;
return V_108 ;
}
static void F_61 ( struct V_4 * V_5 ,
unsigned char * V_123 , int V_64 , T_5 V_74 )
{
struct V_116 * V_75 = V_5 -> V_75 ;
struct V_124 * V_2 = V_75 -> V_2 ;
switch ( V_2 -> V_125 . V_126 ) {
case V_127 : {
struct V_128 V_129 ;
T_1 V_130 [ 16 ] = { 0 } ;
V_129 . V_64 = V_64 ;
memcpy ( & V_130 [ 10 ] , V_123 , V_71 ) ;
V_130 [ 5 ] = V_5 -> V_58 ;
F_62 ( V_2 , & V_129 , V_130 , V_131 ) ;
break;
}
case V_132 : {
F_15 ( V_2 , V_74 ) ;
break;
}
default:
F_16 ( V_5 , L_9 ) ;
}
}
static int F_63 ( struct V_4 * V_5 )
{
struct V_116 * V_75 = V_5 -> V_75 ;
struct V_124 * V_2 = V_75 -> V_2 ;
struct V_135 * V_136 ;
int V_137 = 0 ;
int V_108 = 0 ;
T_5 V_74 ;
int * V_64 = & V_5 -> V_138 ;
T_5 V_123 = F_64 ( V_5 -> V_2 -> V_70 ) ;
F_46 ( V_139 , V_5 , L_10 ,
V_5 -> V_2 -> V_70 ) ;
V_137 = F_65 ( V_2 , V_5 -> V_58 , V_123 ) ;
if ( V_137 < 0 ) {
V_108 = V_137 ;
F_16 ( V_5 , L_11 ,
V_5 -> V_2 -> V_70 ) ;
return V_108 ;
}
if ( V_2 -> V_125 . V_126 == V_140 ) {
int V_138 = F_66 ( V_2 , V_5 -> V_58 ) ;
* V_64 = V_138 + V_137 ;
return 0 ;
}
V_108 = F_67 ( V_2 , 1 , 1 , V_64 ) ;
F_46 ( V_139 , V_5 , L_12 , * V_64 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_13 ) ;
goto V_141;
}
V_108 = F_57 ( V_5 , V_5 -> V_2 -> V_70 , V_64 , & V_74 ) ;
if ( V_108 )
goto V_142;
V_136 = F_68 ( sizeof( * V_136 ) , V_143 ) ;
if ( ! V_136 ) {
V_108 = - V_107 ;
goto V_144;
}
memcpy ( V_136 -> V_123 , V_5 -> V_2 -> V_70 , sizeof( V_136 -> V_123 ) ) ;
V_136 -> V_74 = V_74 ;
F_69 ( & V_136 -> V_145 ,
& V_5 -> V_146 [ V_136 -> V_123 [ V_147 ] ] ) ;
return 0 ;
V_144:
F_61 ( V_5 , V_5 -> V_2 -> V_70 , * V_64 , V_74 ) ;
V_142:
F_70 ( V_2 , * V_64 , 1 ) ;
V_141:
F_71 ( V_2 , V_5 -> V_58 , V_123 ) ;
return V_108 ;
}
static void F_72 ( struct V_4 * V_5 )
{
struct V_116 * V_75 = V_5 -> V_75 ;
struct V_124 * V_2 = V_75 -> V_2 ;
int V_64 = V_5 -> V_138 ;
T_5 V_123 ;
if ( V_2 -> V_125 . V_126 == V_140 ) {
V_123 = F_64 ( V_5 -> V_2 -> V_70 ) ;
F_46 ( V_139 , V_5 , L_14 ,
V_5 -> V_2 -> V_70 ) ;
F_71 ( V_2 , V_5 -> V_58 , V_123 ) ;
} else {
struct V_135 * V_136 ;
struct V_148 * V_110 ;
struct V_77 * V_149 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_150 ; ++ V_6 ) {
V_149 = & V_5 -> V_146 [ V_6 ] ;
F_73 (entry, tmp, bucket, hlist) {
V_123 = F_64 ( V_136 -> V_123 ) ;
F_46 ( V_139 , V_5 , L_14 ,
V_136 -> V_123 ) ;
F_61 ( V_5 , V_136 -> V_123 ,
V_64 , V_136 -> V_74 ) ;
F_71 ( V_2 , V_5 -> V_58 , V_123 ) ;
F_74 ( & V_136 -> V_145 ) ;
F_75 ( V_136 , V_151 ) ;
}
}
F_46 ( V_139 , V_5 , L_15 ,
V_5 -> V_58 , V_64 ) ;
F_70 ( V_2 , V_64 , 1 ) ;
V_5 -> V_152 &= ~ V_153 ;
}
}
static int F_76 ( struct V_4 * V_5 , int V_64 ,
unsigned char * V_154 , unsigned char * V_155 )
{
struct V_116 * V_75 = V_5 -> V_75 ;
struct V_124 * V_2 = V_75 -> V_2 ;
int V_108 = 0 ;
T_5 V_156 = F_64 ( V_154 ) ;
if ( V_2 -> V_125 . V_126 != V_140 ) {
struct V_77 * V_149 ;
unsigned int V_146 ;
struct V_135 * V_136 ;
struct V_148 * V_110 ;
T_5 V_157 = F_64 ( V_155 ) ;
V_149 = & V_5 -> V_146 [ V_155 [ V_147 ] ] ;
F_73 (entry, tmp, bucket, hlist) {
if ( F_77 ( V_136 -> V_123 , V_155 ) ) {
F_61 ( V_5 , V_136 -> V_123 ,
V_64 , V_136 -> V_74 ) ;
F_71 ( V_2 , V_5 -> V_58 ,
V_157 ) ;
F_74 ( & V_136 -> V_145 ) ;
F_78 () ;
memcpy ( V_136 -> V_123 , V_154 , V_71 ) ;
V_136 -> V_74 = 0 ;
V_146 = V_154 [ V_147 ] ;
F_69 ( & V_136 -> V_145 ,
& V_5 -> V_146 [ V_146 ] ) ;
F_65 ( V_2 , V_5 -> V_58 , V_156 ) ;
V_108 = F_57 ( V_5 , V_154 ,
& V_64 ,
& V_136 -> V_74 ) ;
return V_108 ;
}
}
return - V_9 ;
}
return F_79 ( V_2 , V_5 -> V_58 , V_64 , V_156 ) ;
}
T_5 F_64 ( T_1 * V_158 )
{
T_5 V_123 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_71 ; V_6 ++ ) {
V_123 <<= 8 ;
V_123 |= V_158 [ V_6 ] ;
}
return V_123 ;
}
static int F_80 ( struct V_4 * V_5 )
{
int V_108 = 0 ;
if ( V_5 -> V_19 ) {
V_108 = F_76 ( V_5 , V_5 -> V_138 ,
V_5 -> V_2 -> V_70 , V_5 -> V_155 ) ;
if ( V_108 )
F_16 ( V_5 , L_16 ) ;
memcpy ( V_5 -> V_155 , V_5 -> V_2 -> V_70 ,
sizeof( V_5 -> V_155 ) ) ;
} else
F_46 ( V_118 , V_5 , L_17 ) ;
return V_108 ;
}
static int F_81 ( struct V_1 * V_2 , void * V_158 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
struct V_159 * V_102 = V_158 ;
int V_108 ;
if ( ! F_82 ( V_102 -> V_160 ) )
return - V_161 ;
memcpy ( V_2 -> V_70 , V_102 -> V_160 , V_71 ) ;
F_48 ( & V_75 -> V_120 ) ;
V_108 = F_80 ( V_5 ) ;
F_51 ( & V_75 -> V_120 ) ;
return V_108 ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_162 * V_110 , * V_163 ;
F_39 (mc_to_del, tmp, &priv->mc_list, list) {
F_26 ( & V_163 -> V_51 ) ;
F_27 ( V_163 ) ;
}
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_164 * V_165 ;
struct V_162 * V_110 ;
F_83 ( V_2 ) ;
F_85 (ha, dev) {
V_110 = F_22 ( sizeof( struct V_162 ) , V_83 ) ;
if ( ! V_110 ) {
F_83 ( V_2 ) ;
return;
}
memcpy ( V_110 -> V_158 , V_165 -> V_158 , V_71 ) ;
F_14 ( & V_110 -> V_51 , & V_5 -> V_166 ) ;
}
}
static void F_86 ( struct V_4 * V_5 ,
struct V_167 * V_168 ,
struct V_167 * V_169 )
{
struct V_162 * V_170 , * V_171 , * V_172 ;
bool V_173 ;
F_87 (dst_tmp, dst, list) {
V_173 = false ;
F_87 (src_tmp, src, list) {
if ( ! memcmp ( V_170 -> V_158 , V_171 -> V_158 , V_71 ) ) {
V_173 = true ;
break;
}
}
if ( ! V_173 )
V_170 -> V_174 = V_175 ;
}
F_87 (src_tmp, src, list) {
V_173 = false ;
F_87 (dst_tmp, dst, list) {
if ( ! memcmp ( V_170 -> V_158 , V_171 -> V_158 , V_71 ) ) {
V_170 -> V_174 = V_176 ;
V_173 = true ;
break;
}
}
if ( ! V_173 ) {
V_172 = F_88 ( V_171 ,
sizeof( struct V_162 ) ,
V_143 ) ;
if ( ! V_172 )
return;
V_172 -> V_174 = V_177 ;
F_14 ( & V_172 -> V_51 , V_168 ) ;
}
}
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_19 )
return;
F_35 ( V_5 -> V_75 -> V_109 , & V_5 -> V_178 ) ;
}
static void F_90 ( struct V_4 * V_5 ,
struct V_116 * V_75 )
{
int V_108 = 0 ;
if ( ! ( V_5 -> V_152 & V_179 ) ) {
if ( F_91 ( V_5 ) )
F_60 ( V_5 , L_18 ) ;
V_5 -> V_152 |= V_179 ;
switch ( V_75 -> V_2 -> V_125 . V_126 ) {
case V_132 :
V_108 = F_92 ( V_75 -> V_2 ,
V_5 -> V_58 ,
V_5 -> V_138 ,
V_180 ) ;
if ( V_108 )
F_16 ( V_5 , L_19 ) ;
V_5 -> V_152 |= V_181 ;
break;
case V_127 :
V_108 = F_93 ( V_75 -> V_2 ,
V_5 -> V_138 ,
V_5 -> V_58 ) ;
if ( V_108 )
F_16 ( V_5 , L_20 ) ;
if ( ! ( V_5 -> V_152 & V_181 ) ) {
V_108 = F_94 ( V_75 -> V_2 ,
V_5 -> V_138 ,
V_5 -> V_58 ) ;
if ( V_108 )
F_16 ( V_5 , L_21 ) ;
V_5 -> V_152 |= V_181 ;
}
break;
case V_140 :
V_108 = F_95 ( V_75 -> V_2 ,
V_5 -> V_58 ,
V_5 -> V_138 ,
1 ) ;
if ( V_108 )
F_16 ( V_5 , L_19 ) ;
break;
}
V_108 = F_96 ( V_75 -> V_2 , V_5 -> V_58 , 0 ,
0 , V_182 ) ;
if ( V_108 )
F_16 ( V_5 , L_22 ) ;
V_108 = F_49 ( V_75 -> V_2 , V_5 ) ;
if ( V_108 )
F_16 ( V_5 , L_23 ) ;
}
}
static void F_97 ( struct V_4 * V_5 ,
struct V_116 * V_75 )
{
int V_108 = 0 ;
if ( F_91 ( V_5 ) )
F_60 ( V_5 , L_24 ) ;
V_5 -> V_152 &= ~ V_179 ;
switch ( V_75 -> V_2 -> V_125 . V_126 ) {
case V_132 :
V_108 = F_98 ( V_75 -> V_2 ,
V_5 -> V_58 ,
V_180 ) ;
if ( V_108 )
F_16 ( V_5 , L_25 ) ;
V_5 -> V_152 &= ~ V_181 ;
break;
case V_127 :
V_108 = F_99 ( V_75 -> V_2 ,
V_5 -> V_138 ,
V_5 -> V_58 ) ;
if ( V_108 )
F_16 ( V_5 , L_26 ) ;
if ( V_5 -> V_152 & V_181 ) {
V_108 = F_100 ( V_75 -> V_2 ,
V_5 -> V_138 ,
V_5 -> V_58 ) ;
if ( V_108 )
F_16 ( V_5 , L_27 ) ;
V_5 -> V_152 &= ~ V_181 ;
}
break;
case V_140 :
V_108 = F_95 ( V_75 -> V_2 ,
V_5 -> V_58 ,
V_5 -> V_138 , 0 ) ;
if ( V_108 )
F_16 ( V_5 , L_25 ) ;
break;
}
V_108 = F_49 ( V_75 -> V_2 , V_5 ) ;
if ( V_108 )
F_16 ( V_5 , L_28 ) ;
}
static void F_101 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_116 * V_75 )
{
struct V_162 * V_183 , * V_110 ;
T_5 V_184 = 0 ;
T_1 V_166 [ 16 ] = { 0 } ;
int V_108 = 0 ;
if ( V_2 -> V_152 & V_185 ) {
V_108 = F_96 ( V_75 -> V_2 , V_5 -> V_58 , 0 ,
0 , V_182 ) ;
if ( V_108 )
F_16 ( V_5 , L_22 ) ;
if ( ! ( V_5 -> V_152 & V_181 ) ) {
switch ( V_75 -> V_2 -> V_125 . V_126 ) {
case V_132 :
V_108 = F_92 ( V_75 -> V_2 ,
V_5 -> V_58 ,
V_5 -> V_138 ,
V_186 ) ;
break;
case V_127 :
V_108 = F_94 ( V_75 -> V_2 ,
V_5 -> V_138 ,
V_5 -> V_58 ) ;
break;
case V_140 :
break;
}
if ( V_108 )
F_16 ( V_5 , L_29 ) ;
V_5 -> V_152 |= V_181 ;
}
} else {
if ( V_5 -> V_152 & V_181 ) {
switch ( V_75 -> V_2 -> V_125 . V_126 ) {
case V_132 :
V_108 = F_98 ( V_75 -> V_2 ,
V_5 -> V_58 ,
V_186 ) ;
break;
case V_127 :
V_108 = F_100 ( V_75 -> V_2 ,
V_5 -> V_138 ,
V_5 -> V_58 ) ;
break;
case V_140 :
break;
}
if ( V_108 )
F_16 ( V_5 , L_27 ) ;
V_5 -> V_152 &= ~ V_181 ;
}
V_108 = F_96 ( V_75 -> V_2 , V_5 -> V_58 , 0 ,
0 , V_182 ) ;
if ( V_108 )
F_16 ( V_5 , L_22 ) ;
F_96 ( V_75 -> V_2 , V_5 -> V_58 , V_187 ,
1 , V_188 ) ;
F_102 ( V_2 ) ;
F_84 ( V_2 ) ;
F_103 ( V_2 ) ;
F_87 (mclist, &priv->mc_list, list) {
V_184 = F_64 ( V_183 -> V_158 ) ;
F_96 ( V_75 -> V_2 , V_5 -> V_58 ,
V_184 , 0 , V_188 ) ;
}
V_108 = F_96 ( V_75 -> V_2 , V_5 -> V_58 , 0 ,
0 , V_189 ) ;
if ( V_108 )
F_16 ( V_5 , L_30 ) ;
F_86 ( V_5 , & V_5 -> V_190 , & V_5 -> V_166 ) ;
F_39 (mclist, tmp, &priv->curr_list, list) {
if ( V_183 -> V_174 == V_175 ) {
memcpy ( & V_166 [ 10 ] , V_183 -> V_158 , V_71 ) ;
V_166 [ 5 ] = V_5 -> V_58 ;
V_108 = F_104 ( V_75 -> V_2 ,
& V_5 -> V_65 . V_191 ,
V_166 ,
V_131 ,
V_183 -> V_74 ) ;
if ( V_108 )
F_16 ( V_5 , L_31 ) ;
F_26 ( & V_183 -> V_51 ) ;
F_27 ( V_183 ) ;
} else if ( V_183 -> V_174 == V_177 ) {
memcpy ( & V_166 [ 10 ] , V_183 -> V_158 , V_71 ) ;
V_166 [ 5 ] = V_5 -> V_58 ;
V_108 = F_105 ( V_75 -> V_2 ,
& V_5 -> V_65 . V_191 ,
V_166 ,
V_5 -> V_58 , 0 ,
V_131 ,
& V_183 -> V_74 ) ;
if ( V_108 )
F_16 ( V_5 , L_32 ) ;
}
}
}
}
static void F_106 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_116 * V_75 )
{
struct V_164 * V_165 ;
struct V_135 * V_136 ;
struct V_148 * V_110 ;
bool V_173 ;
T_5 V_123 ;
int V_108 = 0 ;
struct V_77 * V_149 ;
unsigned int V_6 ;
int V_192 = 0 ;
T_3 V_193 ;
for ( V_6 = 0 ; V_6 < V_150 ; ++ V_6 ) {
V_149 = & V_5 -> V_146 [ V_6 ] ;
F_73 (entry, tmp, bucket, hlist) {
V_173 = false ;
F_107 (ha, dev) {
if ( F_77 ( V_136 -> V_123 ,
V_165 -> V_158 ) ) {
V_173 = true ;
break;
}
}
if ( F_77 ( V_136 -> V_123 , V_2 -> V_70 ) )
V_173 = true ;
if ( ! V_173 ) {
V_123 = F_64 ( V_136 -> V_123 ) ;
F_61 ( V_5 , V_136 -> V_123 ,
V_5 -> V_138 ,
V_136 -> V_74 ) ;
F_71 ( V_75 -> V_2 , V_5 -> V_58 , V_123 ) ;
F_74 ( & V_136 -> V_145 ) ;
F_75 ( V_136 , V_151 ) ;
F_46 ( V_139 , V_5 , L_33 ,
V_136 -> V_123 , V_5 -> V_58 ) ;
++ V_192 ;
}
}
}
if ( ( V_5 -> V_152 & V_153 ) && 0 == V_192 )
return;
V_193 = V_5 -> V_152 ;
V_5 -> V_152 &= ~ V_153 ;
F_107 (ha, dev) {
V_173 = false ;
V_149 = & V_5 -> V_146 [ V_165 -> V_158 [ V_147 ] ] ;
F_29 (entry, bucket, hlist) {
if ( F_77 ( V_136 -> V_123 , V_165 -> V_158 ) ) {
V_173 = true ;
break;
}
}
if ( ! V_173 ) {
V_136 = F_68 ( sizeof( * V_136 ) , V_143 ) ;
if ( ! V_136 ) {
F_16 ( V_5 , L_34 ,
V_165 -> V_158 , V_5 -> V_58 ) ;
V_5 -> V_152 |= V_153 ;
break;
}
V_123 = F_64 ( V_165 -> V_158 ) ;
memcpy ( V_136 -> V_123 , V_165 -> V_158 , V_71 ) ;
V_108 = F_65 ( V_75 -> V_2 , V_5 -> V_58 , V_123 ) ;
if ( V_108 < 0 ) {
F_16 ( V_5 , L_35 ,
V_165 -> V_158 , V_5 -> V_58 , V_108 ) ;
F_27 ( V_136 ) ;
V_5 -> V_152 |= V_153 ;
break;
}
V_108 = F_57 ( V_5 , V_165 -> V_158 ,
& V_5 -> V_138 ,
& V_136 -> V_74 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_36 ,
V_165 -> V_158 , V_5 -> V_58 , V_108 ) ;
F_71 ( V_75 -> V_2 , V_5 -> V_58 , V_123 ) ;
F_27 ( V_136 ) ;
V_5 -> V_152 |= V_153 ;
break;
} else {
unsigned int V_146 ;
F_46 ( V_139 , V_5 , L_37 ,
V_165 -> V_158 , V_5 -> V_58 ) ;
V_146 = V_165 -> V_158 [ V_147 ] ;
V_149 = & V_5 -> V_146 [ V_146 ] ;
F_69 ( & V_136 -> V_145 , V_149 ) ;
}
}
}
if ( V_5 -> V_152 & V_153 ) {
F_60 ( V_5 , L_38 ,
V_5 -> V_58 ) ;
} else if ( V_193 & V_153 ) {
F_60 ( V_5 , L_39 ,
V_5 -> V_58 ) ;
}
}
static void F_108 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_6 ( V_25 , struct V_4 ,
V_178 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_48 ( & V_75 -> V_120 ) ;
if ( ! V_75 -> V_121 ) {
F_46 ( V_118 , V_5 , L_40 ) ;
goto V_106;
}
if ( ! V_5 -> V_19 ) {
F_46 ( V_118 , V_5 , L_41 ) ;
goto V_106;
}
if ( ! F_109 ( V_2 ) ) {
if ( ! F_110 ( V_75 , V_5 -> V_58 ) ) {
if ( V_5 -> V_194 . V_195 ) {
V_5 -> V_196 = V_197 ;
F_111 ( V_2 ) ;
F_46 ( V_198 , V_5 , L_42 ) ;
}
}
}
if ( V_2 -> V_199 & V_200 )
F_106 ( V_5 , V_2 , V_75 ) ;
if ( ( V_2 -> V_152 & V_201 ) ||
( V_5 -> V_152 & V_153 ) ) {
F_90 ( V_5 , V_75 ) ;
goto V_106;
}
if ( V_5 -> V_152 & V_179 )
F_97 ( V_5 , V_75 ) ;
F_101 ( V_5 , V_2 , V_75 ) ;
V_106:
F_51 ( & V_75 -> V_120 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_13 * V_14 ;
unsigned long V_152 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ ) {
V_14 = & V_5 -> V_203 [ V_6 ] ;
F_113 ( & V_14 -> V_204 , V_152 ) ;
F_114 ( & V_14 -> V_12 ) ;
F_8 ( V_2 , V_14 , 0 ) ;
F_115 ( & V_14 -> V_204 , V_152 ) ;
}
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
int V_6 ;
if ( F_117 ( V_5 ) )
F_60 ( V_5 , L_43 , V_5 -> V_58 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
if ( ! F_118 ( F_119 ( V_2 , V_6 ) ) )
continue;
F_60 ( V_5 , L_44 ,
V_6 , V_5 -> V_206 [ V_6 ] . V_64 , V_5 -> V_206 [ V_6 ] . V_207 ,
V_5 -> V_206 [ V_6 ] . V_208 , V_5 -> V_206 [ V_6 ] . V_209 ) ;
}
V_5 -> V_210 . V_211 ++ ;
F_46 ( V_139 , V_5 , L_45 ) ;
F_35 ( V_75 -> V_109 , & V_5 -> V_212 ) ;
}
static struct V_213 * F_120 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_34 ( & V_5 -> V_214 ) ;
memcpy ( & V_5 -> V_215 , & V_5 -> V_216 , sizeof( V_5 -> V_216 ) ) ;
F_36 ( & V_5 -> V_214 ) ;
return & V_5 -> V_215 ;
}
static void F_121 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
int V_6 ;
V_5 -> V_217 = V_218 ;
V_5 -> V_219 = V_220 ;
V_5 -> V_221 = V_222 ;
V_5 -> V_223 = V_224 ;
F_46 ( V_225 , V_5 , L_46 ,
V_5 -> V_2 -> V_226 , V_5 -> V_217 , V_5 -> V_219 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ ) {
V_14 = & V_5 -> V_203 [ V_6 ] ;
V_14 -> V_227 = V_5 -> V_217 ;
V_14 -> V_228 = V_5 -> V_219 ;
V_5 -> V_229 [ V_6 ] = V_230 ;
V_5 -> V_231 [ V_6 ] = 0 ;
V_5 -> V_232 [ V_6 ] = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
V_14 = & V_5 -> V_233 [ V_6 ] ;
V_14 -> V_227 = V_5 -> V_221 ;
V_14 -> V_228 = V_5 -> V_223 ;
}
V_5 -> V_234 = V_235 ;
V_5 -> V_236 = V_237 ;
V_5 -> V_238 = V_239 ;
V_5 -> V_240 = V_241 ;
V_5 -> V_242 = V_243 ;
V_5 -> V_244 = 1 ;
V_5 -> V_245 = 0 ;
V_5 -> V_246 = 0 ;
}
static void F_122 ( struct V_4 * V_5 )
{
unsigned long V_247 = ( unsigned long ) ( V_248 - V_5 -> V_245 ) ;
struct V_13 * V_14 ;
unsigned long V_249 ;
unsigned long V_250 ;
unsigned long V_251 ;
unsigned long V_252 ;
unsigned long V_253 ;
unsigned long V_254 ;
int V_228 ;
int V_17 , V_108 ;
if ( ! V_5 -> V_244 || V_247 < V_5 -> V_242 * V_255 )
return;
for ( V_17 = 0 ; V_17 < V_5 -> V_202 ; V_17 ++ ) {
F_34 ( & V_5 -> V_214 ) ;
V_252 = V_5 -> V_16 [ V_17 ] . V_249 ;
V_253 = V_5 -> V_16 [ V_17 ] . V_256 ;
F_36 ( & V_5 -> V_214 ) ;
V_254 = ( ( unsigned long ) ( V_252 -
V_5 -> V_231 [ V_17 ] ) ) ;
V_249 = V_254 ;
V_250 = V_249 * V_255 / V_247 ;
V_251 = V_249 ? ( ( unsigned long ) ( V_253 -
V_5 -> V_232 [ V_17 ] ) ) / V_249 : 0 ;
if ( V_250 > ( V_257 / V_5 -> V_202 ) &&
V_251 > V_258 ) {
if ( V_250 < V_5 -> V_234 )
V_228 = V_5 -> V_236 ;
else if ( V_250 > V_5 -> V_238 )
V_228 = V_5 -> V_240 ;
else
V_228 = ( V_250 - V_5 -> V_234 ) *
( V_5 -> V_240 - V_5 -> V_236 ) /
( V_5 -> V_238 - V_5 -> V_234 ) +
V_5 -> V_236 ;
} else {
V_228 = V_5 -> V_236 ;
}
if ( V_228 != V_5 -> V_229 [ V_17 ] ) {
V_5 -> V_229 [ V_17 ] = V_228 ;
V_14 = & V_5 -> V_203 [ V_17 ] ;
V_14 -> V_228 = V_228 ;
V_14 -> V_227 = V_5 -> V_217 ;
V_108 = F_123 ( V_5 , V_14 ) ;
if ( V_108 )
F_16 ( V_5 , L_47 ,
V_17 ) ;
}
V_5 -> V_231 [ V_17 ] = V_252 ;
V_5 -> V_232 [ V_17 ] = V_253 ;
}
V_5 -> V_245 = V_248 ;
}
static void F_124 ( struct V_24 * V_25 )
{
struct V_259 * V_260 = F_125 ( V_25 ) ;
struct V_4 * V_5 = F_6 ( V_260 , struct V_4 ,
V_261 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
int V_108 ;
F_48 ( & V_75 -> V_120 ) ;
if ( V_75 -> V_121 ) {
if ( V_5 -> V_19 ) {
V_108 = F_126 ( V_75 , V_5 -> V_58 , 0 ) ;
if ( V_108 )
F_46 ( V_118 , V_5 , L_48 ) ;
F_122 ( V_5 ) ;
}
F_127 ( V_75 -> V_109 , & V_5 -> V_261 , V_262 ) ;
}
if ( V_75 -> V_263 [ V_264 + 1 - V_5 -> V_58 ] ) {
F_80 ( V_5 ) ;
V_75 -> V_263 [ V_264 + 1 - V_5 -> V_58 ] = 0 ;
}
F_51 ( & V_75 -> V_120 ) ;
}
static void F_128 ( struct V_24 * V_25 )
{
struct V_259 * V_260 = F_125 ( V_25 ) ;
struct V_4 * V_5 = F_6 ( V_260 , struct V_4 ,
V_265 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
F_48 ( & V_75 -> V_120 ) ;
if ( V_75 -> V_121 ) {
if ( V_75 -> V_2 -> V_125 . V_266 & V_267 )
F_129 ( V_75 ) ;
F_127 ( V_75 -> V_109 , & V_5 -> V_265 ,
V_268 ) ;
}
F_51 ( & V_75 -> V_120 ) ;
}
static void F_130 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_6 ( V_25 , struct V_4 ,
V_269 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
int V_270 = V_5 -> V_195 ;
F_48 ( & V_75 -> V_120 ) ;
if ( V_5 -> V_196 != V_270 ) {
if ( V_270 == V_271 ) {
F_131 ( V_5 , L_49 ) ;
F_132 ( V_5 -> V_2 ) ;
} else {
F_131 ( V_5 , L_42 ) ;
F_111 ( V_5 -> V_2 ) ;
}
}
V_5 -> V_196 = V_270 ;
F_51 ( & V_75 -> V_120 ) ;
}
int F_133 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
struct V_13 * V_14 ;
struct V_272 * V_206 ;
int V_273 = 0 ;
int V_274 = 0 ;
int V_108 = 0 ;
int V_6 ;
int V_275 ;
T_1 V_166 [ 16 ] = { 0 } ;
if ( V_5 -> V_19 ) {
F_46 ( V_139 , V_5 , L_50 ) ;
return 0 ;
}
F_59 ( & V_5 -> V_166 ) ;
F_59 ( & V_5 -> V_190 ) ;
F_59 ( & V_5 -> V_276 ) ;
memset ( & V_5 -> V_277 [ 0 ] , 0 ,
sizeof( struct V_278 ) * V_279 ) ;
V_2 -> V_226 = F_134 ( V_2 -> V_226 , V_5 -> V_280 ) ;
F_135 ( V_2 ) ;
F_46 ( V_139 , V_5 , L_51 , V_5 -> V_281 ) ;
V_108 = F_136 ( V_5 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_52 ) ;
return V_108 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ ) {
V_14 = & V_5 -> V_203 [ V_6 ] ;
F_137 ( V_14 ) ;
V_108 = F_138 ( V_5 , V_14 , V_6 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_53 ) ;
goto V_282;
}
for ( V_275 = 0 ; V_275 < V_14 -> V_283 ; V_275 ++ )
V_14 -> V_284 [ V_275 ] . V_285 = V_286 ;
V_108 = F_123 ( V_5 , V_14 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_54 ) ;
F_139 ( V_5 , V_14 ) ;
goto V_282;
}
F_140 ( V_5 , V_14 ) ;
V_5 -> V_16 [ V_6 ] . V_207 = V_14 -> V_287 . V_207 ;
++ V_273 ;
}
F_46 ( V_139 , V_5 , L_55 , V_5 -> V_58 ) ;
V_108 = F_63 ( V_5 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_56 ) ;
goto V_282;
}
V_75 -> V_263 [ V_5 -> V_58 ] = 0 ;
V_108 = F_141 ( V_5 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_57 ) ;
goto V_288;
}
V_108 = F_142 ( V_5 ) ;
if ( V_108 )
goto V_289;
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
V_14 = & V_5 -> V_233 [ V_6 ] ;
V_108 = F_138 ( V_5 , V_14 , V_6 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_58 ) ;
goto V_290;
}
V_108 = F_123 ( V_5 , V_14 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_54 ) ;
F_139 ( V_5 , V_14 ) ;
goto V_290;
}
F_46 ( V_139 , V_5 , L_59 , V_6 ) ;
V_14 -> V_284 -> V_291 = F_143 ( 0xffff ) ;
V_206 = & V_5 -> V_206 [ V_6 ] ;
V_108 = F_144 ( V_5 , V_206 , V_14 -> V_287 . V_207 ,
V_6 / V_5 -> V_10 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_60 ) ;
F_139 ( V_5 , V_14 ) ;
goto V_290;
}
V_206 -> V_292 = F_119 ( V_2 , V_6 ) ;
F_140 ( V_5 , V_14 ) ;
for ( V_275 = 0 ; V_275 < V_206 -> V_293 ; V_275 += V_294 )
* ( ( T_3 * ) ( V_206 -> V_284 + V_275 ) ) = 0xffffffff ;
++ V_274 ;
}
V_108 = F_145 ( V_75 -> V_2 , V_5 -> V_58 ,
V_5 -> V_281 + V_295 ,
V_5 -> V_296 -> V_297 ,
V_5 -> V_296 -> V_298 ,
V_5 -> V_296 -> V_299 ,
V_5 -> V_296 -> V_300 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_61 ,
V_5 -> V_58 , V_108 ) ;
goto V_290;
}
V_108 = F_95 ( V_75 -> V_2 , V_5 -> V_58 , V_5 -> V_138 , 0 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_62 ) ;
goto V_290;
}
F_46 ( V_118 , V_5 , L_63 ) ;
V_108 = F_146 ( V_75 -> V_2 , V_5 -> V_58 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_64 ) ;
goto V_290;
}
memset ( & V_166 [ 10 ] , 0xff , V_71 ) ;
V_166 [ 5 ] = V_5 -> V_58 ;
if ( F_105 ( V_75 -> V_2 , & V_5 -> V_65 . V_191 , V_166 ,
V_5 -> V_58 , 0 , V_131 ,
& V_5 -> V_301 ) )
F_147 ( V_75 , L_65 ) ;
V_5 -> V_152 &= ~ ( V_179 | V_181 ) ;
F_35 ( V_75 -> V_109 , & V_5 -> V_178 ) ;
F_148 ( V_75 -> V_2 , & V_5 -> V_302 ) ;
V_5 -> V_19 = true ;
F_149 ( V_2 ) ;
F_150 ( V_2 ) ;
return 0 ;
V_290:
while ( V_274 -- ) {
F_151 ( V_5 , & V_5 -> V_206 [ V_274 ] ) ;
F_139 ( V_5 , & V_5 -> V_233 [ V_274 ] ) ;
}
F_152 ( V_5 ) ;
V_289:
F_153 ( V_5 ) ;
V_288:
F_72 ( V_5 ) ;
V_282:
while ( V_273 -- )
F_139 ( V_5 , & V_5 -> V_203 [ V_273 ] ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ )
F_154 ( V_5 , & V_5 -> V_16 [ V_6 ] ) ;
return V_108 ;
}
void F_155 ( struct V_1 * V_2 , int V_303 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
struct V_162 * V_183 , * V_110 ;
struct V_278 * V_304 , * V_305 ;
int V_6 ;
T_1 V_166 [ 16 ] = { 0 } ;
if ( ! V_5 -> V_19 ) {
F_46 ( V_139 , V_5 , L_66 ) ;
return;
}
F_156 ( V_75 -> V_2 , V_5 -> V_58 ) ;
F_157 ( V_2 ) ;
if ( V_303 )
F_158 ( V_2 ) ;
F_159 ( V_2 ) ;
F_160 ( V_2 ) ;
F_161 ( V_2 ) ;
V_5 -> V_19 = false ;
if ( V_75 -> V_2 -> V_125 . V_126 ==
V_132 ) {
V_5 -> V_152 &= ~ ( V_179 |
V_181 ) ;
F_98 ( V_75 -> V_2 ,
V_5 -> V_58 ,
V_180 ) ;
F_98 ( V_75 -> V_2 ,
V_5 -> V_58 ,
V_186 ) ;
} else if ( V_5 -> V_152 & V_179 ) {
V_5 -> V_152 &= ~ V_179 ;
F_99 ( V_75 -> V_2 , V_5 -> V_138 ,
V_5 -> V_58 ) ;
if ( V_5 -> V_152 & V_181 ) {
F_100 ( V_75 -> V_2 , V_5 -> V_138 ,
V_5 -> V_58 ) ;
V_5 -> V_152 &= ~ V_181 ;
}
}
memset ( & V_166 [ 10 ] , 0xff , V_71 ) ;
V_166 [ 5 ] = V_5 -> V_58 ;
F_104 ( V_75 -> V_2 , & V_5 -> V_65 . V_191 , V_166 ,
V_131 , V_5 -> V_301 ) ;
F_87 (mclist, &priv->curr_list, list) {
memcpy ( & V_166 [ 10 ] , V_183 -> V_158 , V_71 ) ;
V_166 [ 5 ] = V_5 -> V_58 ;
F_104 ( V_75 -> V_2 , & V_5 -> V_65 . V_191 ,
V_166 , V_131 , V_183 -> V_74 ) ;
}
F_83 ( V_2 ) ;
F_39 (mclist, tmp, &priv->curr_list, list) {
F_26 ( & V_183 -> V_51 ) ;
F_27 ( V_183 ) ;
}
F_96 ( V_75 -> V_2 , V_5 -> V_58 , 0 , 1 , V_188 ) ;
if ( V_75 -> V_2 -> V_125 . V_126 ==
V_132 ) {
F_162 () ;
F_39 (flow, tmp_flow,
&priv->ethtool_list, list) {
F_15 ( V_75 -> V_2 , V_304 -> V_30 ) ;
F_26 ( & V_304 -> V_51 ) ;
}
}
F_152 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
F_151 ( V_5 , & V_5 -> V_206 [ V_6 ] ) ;
F_139 ( V_5 , & V_5 -> V_233 [ V_6 ] ) ;
}
F_163 ( 10 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ )
F_164 ( V_2 , & V_5 -> V_206 [ V_6 ] ) ;
F_153 ( V_5 ) ;
F_72 ( V_5 ) ;
if ( ! ( V_75 -> V_2 -> V_125 . V_266 & V_306 ) )
V_75 -> V_263 [ V_5 -> V_58 ] = 1 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ ) {
struct V_13 * V_14 = & V_5 -> V_203 [ V_6 ] ;
F_165 () ;
while ( ! F_166 ( V_14 ) ) {
F_167 ( L_67 , V_6 ) ;
F_168 ( 1 ) ;
}
F_169 () ;
while ( F_170 ( V_307 , & V_14 -> V_12 . V_308 ) )
F_163 ( 1 ) ;
F_154 ( V_5 , & V_5 -> V_16 [ V_6 ] ) ;
F_139 ( V_5 , V_14 ) ;
}
}
static void F_171 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_6 ( V_25 , struct V_4 ,
V_212 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_46 ( V_139 , V_5 , L_68 , V_5 -> V_58 ) ;
F_48 ( & V_75 -> V_120 ) ;
if ( V_5 -> V_19 ) {
F_155 ( V_2 , 1 ) ;
if ( F_133 ( V_2 ) )
F_16 ( V_5 , L_69 , V_5 -> V_58 ) ;
}
F_51 ( & V_75 -> V_120 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
int V_6 ;
if ( F_126 ( V_75 , V_5 -> V_58 , 1 ) )
F_46 ( V_118 , V_5 , L_70 ) ;
memset ( & V_5 -> V_216 , 0 , sizeof( V_5 -> V_216 ) ) ;
memset ( & V_5 -> V_309 , 0 , sizeof( V_5 -> V_309 ) ) ;
memset ( & V_5 -> V_310 , 0 , sizeof( V_5 -> V_310 ) ) ;
memset ( & V_5 -> V_210 , 0 , sizeof( V_5 -> V_210 ) ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
V_5 -> V_206 [ V_6 ] . V_256 = 0 ;
V_5 -> V_206 [ V_6 ] . V_249 = 0 ;
V_5 -> V_206 [ V_6 ] . V_311 = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ ) {
V_5 -> V_16 [ V_6 ] . V_256 = 0 ;
V_5 -> V_16 [ V_6 ] . V_249 = 0 ;
V_5 -> V_16 [ V_6 ] . V_312 = 0 ;
V_5 -> V_16 [ V_6 ] . V_313 = 0 ;
}
}
static int F_173 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
int V_108 = 0 ;
F_48 ( & V_75 -> V_120 ) ;
if ( ! V_75 -> V_121 ) {
F_16 ( V_5 , L_71 ) ;
V_108 = - V_314 ;
goto V_106;
}
F_172 ( V_2 ) ;
V_108 = F_133 ( V_2 ) ;
if ( V_108 )
F_16 ( V_5 , L_72 , V_5 -> V_58 ) ;
V_106:
F_51 ( & V_75 -> V_120 ) ;
return V_108 ;
}
static int F_174 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
F_46 ( V_315 , V_5 , L_73 ) ;
F_48 ( & V_75 -> V_120 ) ;
F_155 ( V_2 , 0 ) ;
F_132 ( V_2 ) ;
F_51 ( & V_75 -> V_120 ) ;
return 0 ;
}
void F_175 ( struct V_4 * V_5 )
{
int V_6 ;
#ifdef F_176
F_177 ( V_5 -> V_2 -> V_316 ) ;
V_5 -> V_2 -> V_316 = NULL ;
#endif
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
if ( V_5 -> V_206 [ V_6 ] . V_317 )
F_178 ( V_5 , & V_5 -> V_206 [ V_6 ] ) ;
if ( V_5 -> V_233 [ V_6 ] . V_284 )
F_179 ( V_5 , & V_5 -> V_233 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ ) {
if ( V_5 -> V_16 [ V_6 ] . V_318 )
F_180 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_5 -> V_296 -> V_319 , V_5 -> V_320 ) ;
if ( V_5 -> V_203 [ V_6 ] . V_284 )
F_179 ( V_5 , & V_5 -> V_203 [ V_6 ] ) ;
}
if ( V_5 -> V_321 ) {
F_70 ( V_5 -> V_75 -> V_2 , V_5 -> V_321 , V_5 -> V_205 ) ;
V_5 -> V_321 = 0 ;
}
}
int F_181 ( struct V_4 * V_5 )
{
struct V_322 * V_296 = V_5 -> V_296 ;
int V_6 ;
int V_108 ;
V_108 = F_67 ( V_5 -> V_75 -> V_2 , V_5 -> V_205 , 256 , & V_5 -> V_321 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_74 ) ;
return V_108 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_205 ; V_6 ++ ) {
if ( F_182 ( V_5 , & V_5 -> V_233 [ V_6 ] ,
V_296 -> V_323 , V_6 , V_324 ) )
goto V_108;
if ( F_183 ( V_5 , & V_5 -> V_206 [ V_6 ] , V_5 -> V_321 + V_6 ,
V_296 -> V_323 , V_325 ) )
goto V_108;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_202 ; V_6 ++ ) {
if ( F_182 ( V_5 , & V_5 -> V_203 [ V_6 ] ,
V_296 -> V_319 , V_6 , V_326 ) )
goto V_108;
if ( F_184 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_296 -> V_319 , V_5 -> V_320 ) )
goto V_108;
}
#ifdef F_176
if ( V_5 -> V_75 -> V_2 -> V_125 . V_327 ) {
V_5 -> V_2 -> V_316 = F_185 ( V_5 -> V_75 -> V_2 -> V_125 . V_327 ) ;
if ( ! V_5 -> V_2 -> V_316 )
goto V_108;
}
#endif
return 0 ;
V_108:
F_16 ( V_5 , L_75 ) ;
return - V_107 ;
}
void F_186 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
F_46 ( V_139 , V_5 , L_76 , V_5 -> V_58 ) ;
if ( V_5 -> V_328 )
F_187 ( V_2 ) ;
if ( V_5 -> V_329 )
F_188 ( V_75 -> V_2 , & V_5 -> V_330 , V_331 ) ;
F_189 ( & V_5 -> V_261 ) ;
F_189 ( & V_5 -> V_265 ) ;
F_190 ( V_75 -> V_109 ) ;
F_48 ( & V_75 -> V_120 ) ;
V_75 -> V_332 [ V_5 -> V_58 ] = NULL ;
F_51 ( & V_75 -> V_120 ) ;
F_175 ( V_5 ) ;
F_27 ( V_5 -> V_206 ) ;
F_27 ( V_5 -> V_233 ) ;
F_191 ( V_2 ) ;
}
static int F_192 ( struct V_1 * V_2 , int V_333 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
int V_108 = 0 ;
F_46 ( V_139 , V_5 , L_77 ,
V_2 -> V_226 , V_333 ) ;
if ( ( V_333 < V_334 ) || ( V_333 > V_5 -> V_280 ) ) {
F_16 ( V_5 , L_78 , V_333 ) ;
return - V_335 ;
}
V_2 -> V_226 = V_333 ;
if ( F_193 ( V_2 ) ) {
F_48 ( & V_75 -> V_120 ) ;
if ( ! V_75 -> V_121 ) {
F_46 ( V_139 , V_5 , L_79 ) ;
} else {
F_155 ( V_2 , 1 ) ;
V_108 = F_133 ( V_2 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_80 ,
V_5 -> V_58 ) ;
F_35 ( V_75 -> V_109 , & V_5 -> V_212 ) ;
}
}
F_51 ( & V_75 -> V_120 ) ;
}
return 0 ;
}
static int F_194 ( struct V_1 * V_2 , struct V_336 * V_337 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_5 -> V_75 ;
struct V_338 V_339 ;
if ( F_195 ( & V_339 , V_337 -> V_340 , sizeof( V_339 ) ) )
return - V_341 ;
if ( V_339 . V_152 )
return - V_9 ;
if ( ! ( V_75 -> V_2 -> V_125 . V_266 & V_267 ) )
return - V_9 ;
switch ( V_339 . V_342 ) {
case V_343 :
case V_344 :
break;
default:
return - V_345 ;
}
switch ( V_339 . V_346 ) {
case V_347 :
break;
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
V_339 . V_346 = V_348 ;
break;
default:
return - V_345 ;
}
if ( F_196 ( V_2 , V_339 . V_342 , V_339 . V_346 ) ) {
V_339 . V_342 = V_343 ;
V_339 . V_346 = V_347 ;
}
return F_197 ( V_337 -> V_340 , & V_339 ,
sizeof( V_339 ) ) ? - V_341 : 0 ;
}
static int F_198 ( struct V_1 * V_2 , struct V_336 * V_337 , int V_362 )
{
switch ( V_362 ) {
case V_363 :
return F_194 ( V_2 , V_337 ) ;
default:
return - V_364 ;
}
}
static int F_199 ( struct V_1 * V_365 ,
T_6 V_366 )
{
struct V_4 * V_5 = F_2 ( V_365 ) ;
if ( V_366 & V_367 )
V_5 -> V_368 |= F_200 ( V_369 ) ;
else
V_5 -> V_368 &=
F_200 ( ~ V_369 ) ;
F_201 ( V_365 , V_366 ) ;
return 0 ;
}
static int F_202 ( struct V_1 * V_2 , int V_370 , T_1 * V_123 )
{
struct V_4 * V_371 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_371 -> V_75 ;
T_5 V_372 = F_64 ( V_123 ) ;
if ( ! F_82 ( V_123 ) )
return - V_9 ;
return F_203 ( V_75 -> V_2 , V_371 -> V_58 , V_370 , V_372 ) ;
}
static int F_204 ( struct V_1 * V_2 , int V_373 , T_4 V_374 , T_1 V_375 )
{
struct V_4 * V_371 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_371 -> V_75 ;
return F_205 ( V_75 -> V_2 , V_371 -> V_58 , V_373 , V_374 , V_375 ) ;
}
static int F_206 ( struct V_1 * V_2 , int V_373 , bool V_376 )
{
struct V_4 * V_371 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_371 -> V_75 ;
return F_207 ( V_75 -> V_2 , V_371 -> V_58 , V_373 , V_376 ) ;
}
static int F_208 ( struct V_1 * V_2 , int V_373 , struct V_377 * V_378 )
{
struct V_4 * V_371 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_371 -> V_75 ;
return F_209 ( V_75 -> V_2 , V_371 -> V_58 , V_373 , V_378 ) ;
}
static int F_210 ( struct V_1 * V_2 , int V_373 , int V_195 )
{
struct V_4 * V_371 = F_2 ( V_2 ) ;
struct V_116 * V_75 = V_371 -> V_75 ;
return F_211 ( V_75 -> V_2 , V_371 -> V_58 , V_373 , V_195 ) ;
}
int F_212 ( struct V_116 * V_75 , int V_58 ,
struct V_322 * V_296 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_6 ;
int V_108 ;
T_5 V_372 ;
V_2 = F_213 ( sizeof( struct V_4 ) ,
V_379 , V_380 ) ;
if ( V_2 == NULL )
return - V_107 ;
F_214 ( V_2 , V_296 -> V_205 ) ;
F_215 ( V_2 , V_296 -> V_202 ) ;
F_216 ( V_2 , & V_75 -> V_2 -> V_381 -> V_2 ) ;
V_2 -> V_382 = V_58 - 1 ;
V_5 = F_2 ( V_2 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_75 = V_75 ;
V_5 -> V_383 = & V_75 -> V_381 -> V_2 ;
V_5 -> V_296 = V_296 ;
V_5 -> V_58 = V_58 ;
V_5 -> V_19 = false ;
V_5 -> V_152 = V_296 -> V_152 ;
V_5 -> V_368 = F_200 ( V_384 |
V_385 ) ;
V_5 -> V_10 = V_75 -> V_386 . V_10 ;
V_5 -> V_205 = V_296 -> V_205 ;
V_5 -> V_206 = F_22 ( sizeof( struct V_272 ) * V_379 ,
V_143 ) ;
if ( ! V_5 -> V_206 ) {
V_108 = - V_107 ;
goto V_106;
}
V_5 -> V_233 = F_22 ( sizeof( struct V_13 ) * V_379 ,
V_143 ) ;
if ( ! V_5 -> V_233 ) {
V_108 = - V_107 ;
goto V_106;
}
V_5 -> V_202 = V_296 -> V_202 ;
V_5 -> V_387 = ( V_75 -> V_2 -> V_125 . V_388 == 64 ) ? 1 : 0 ;
V_5 -> V_389 = - 1 ;
V_5 -> V_390 = V_391 ;
F_217 ( & V_5 -> V_214 ) ;
F_23 ( & V_5 -> V_178 , F_108 ) ;
F_23 ( & V_5 -> V_212 , F_171 ) ;
F_23 ( & V_5 -> V_269 , F_130 ) ;
F_218 ( & V_5 -> V_261 , F_124 ) ;
F_218 ( & V_5 -> V_265 , F_128 ) ;
#ifdef F_219
if ( ! F_220 ( V_5 -> V_75 -> V_2 ) ) {
if ( V_75 -> V_2 -> V_125 . V_152 & V_392 ) {
V_2 -> V_393 = & V_394 ;
} else {
F_131 ( V_5 , L_81 ) ;
V_2 -> V_393 = & V_395 ;
}
}
#endif
for ( V_6 = 0 ; V_6 < V_150 ; ++ V_6 )
F_221 ( & V_5 -> V_146 [ V_6 ] ) ;
V_5 -> V_280 = V_75 -> V_2 -> V_125 . V_396 [ V_5 -> V_58 ] ;
V_2 -> V_397 = V_71 ;
F_56 ( V_2 -> V_70 , V_75 -> V_2 -> V_125 . V_398 [ V_5 -> V_58 ] ) ;
if ( ! F_82 ( V_2 -> V_70 ) ) {
if ( F_220 ( V_5 -> V_75 -> V_2 ) ) {
F_222 ( V_2 ) ;
F_60 ( V_5 , L_82 , V_2 -> V_70 ) ;
V_372 = F_64 ( V_2 -> V_70 ) ;
V_75 -> V_2 -> V_125 . V_398 [ V_5 -> V_58 ] = V_372 ;
} else {
F_16 ( V_5 , L_83 ,
V_5 -> V_58 , V_2 -> V_70 ) ;
V_108 = - V_9 ;
goto V_106;
}
}
memcpy ( V_5 -> V_155 , V_2 -> V_70 , sizeof( V_5 -> V_155 ) ) ;
V_5 -> V_320 = F_223 ( sizeof( struct V_399 ) +
V_400 * V_401 ) ;
V_108 = F_181 ( V_5 ) ;
if ( V_108 )
goto V_106;
#ifdef F_176
F_59 ( & V_5 -> V_87 ) ;
F_217 ( & V_5 -> V_105 ) ;
#endif
V_5 -> V_338 . V_152 = 0 ;
V_5 -> V_338 . V_342 = V_343 ;
V_5 -> V_338 . V_346 = V_347 ;
V_108 = F_224 ( V_75 -> V_2 , & V_5 -> V_330 ,
V_331 , V_331 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_84 ) ;
goto V_106;
}
V_5 -> V_329 = 1 ;
if ( F_225 ( V_5 -> V_75 -> V_2 ) )
V_2 -> V_402 = & V_403 ;
else
V_2 -> V_402 = & V_404 ;
V_2 -> V_405 = V_406 ;
F_214 ( V_2 , V_5 -> V_205 ) ;
F_215 ( V_2 , V_5 -> V_202 ) ;
F_226 ( V_2 , & V_407 ) ;
V_2 -> V_408 = V_409 | V_410 | V_411 ;
if ( V_75 -> V_412 )
V_2 -> V_408 |= V_413 | V_414 ;
V_2 -> V_415 = V_2 -> V_408 ;
V_2 -> V_408 |= V_416 | V_417 ;
V_2 -> V_366 = V_2 -> V_408 | V_418 |
V_419 | V_420 |
V_421 ;
V_2 -> V_408 |= V_367 ;
if ( V_75 -> V_2 -> V_125 . V_126 ==
V_132 )
V_2 -> V_408 |= V_422 ;
if ( V_75 -> V_2 -> V_125 . V_126 != V_140 )
V_2 -> V_199 |= V_200 ;
V_75 -> V_332 [ V_58 ] = V_2 ;
F_132 ( V_2 ) ;
F_121 ( V_5 ) ;
V_108 = F_227 ( V_2 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_85 , V_58 ) ;
goto V_106;
}
V_5 -> V_328 = 1 ;
F_60 ( V_5 , L_86 , V_296 -> V_205 ) ;
F_60 ( V_5 , L_87 , V_296 -> V_202 ) ;
F_201 ( V_5 -> V_2 , V_5 -> V_2 -> V_366 ) ;
F_135 ( V_2 ) ;
V_108 = F_145 ( V_75 -> V_2 , V_5 -> V_58 ,
V_5 -> V_281 + V_295 ,
V_296 -> V_297 , V_296 -> V_298 ,
V_296 -> V_299 , V_296 -> V_300 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_88
L_89 , V_5 -> V_58 , V_108 ) ;
goto V_106;
}
F_60 ( V_5 , L_63 ) ;
V_108 = F_146 ( V_75 -> V_2 , V_5 -> V_58 ) ;
if ( V_108 ) {
F_16 ( V_5 , L_64 ) ;
goto V_106;
}
F_127 ( V_75 -> V_109 , & V_5 -> V_261 , V_262 ) ;
if ( V_75 -> V_2 -> V_125 . V_266 & V_267 )
F_127 ( V_75 -> V_109 , & V_5 -> V_265 ,
V_268 ) ;
return 0 ;
V_106:
F_186 ( V_2 ) ;
return V_108 ;
}
