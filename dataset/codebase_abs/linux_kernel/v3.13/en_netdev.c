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
return - V_30 ;
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
if ( V_36 . V_37 < 0 ) {
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
return - V_30 ;
V_101 = ( const struct V_100 * ) ( V_99 -> V_106 + V_103 ) ;
if ( F_35 ( V_101 ) )
return - V_30 ;
if ( ( V_101 -> V_104 != V_28 ) && ( V_101 -> V_104 != V_26 ) )
return - V_30 ;
V_102 = ( const V_42 * ) ( V_99 -> V_106 + V_103 + 4 * V_101 -> V_107 ) ;
V_25 = V_101 -> V_104 ;
V_51 = V_101 -> V_108 ;
V_48 = V_101 -> V_109 ;
V_43 = V_102 [ 0 ] ;
V_39 = V_102 [ 1 ] ;
F_36 ( & V_5 -> V_110 ) ;
V_34 = F_30 ( V_5 , V_51 , V_48 , V_25 ,
V_43 , V_39 ) ;
if ( V_34 ) {
if ( V_34 -> V_74 == V_74 )
goto V_111;
V_34 -> V_74 = V_74 ;
} else {
V_34 = F_23 ( V_5 , V_74 ,
V_51 , V_48 , V_25 ,
V_43 , V_39 , V_89 ) ;
if ( ! V_34 ) {
V_96 = - V_112 ;
goto V_113;
}
}
F_37 ( V_5 -> V_82 -> V_114 , & V_34 -> V_32 ) ;
V_111:
V_96 = V_34 -> V_37 ;
V_113:
F_38 ( & V_5 -> V_110 ) ;
return V_96 ;
}
void F_39 ( struct V_4 * V_5 )
{
struct V_33 * V_34 , * V_115 ;
F_40 ( V_116 ) ;
F_36 ( & V_5 -> V_110 ) ;
F_41 (filter, tmp, &priv->filters, next) {
F_42 ( & V_34 -> V_93 , & V_116 ) ;
F_43 ( & V_34 -> V_95 ) ;
}
F_38 ( & V_5 -> V_110 ) ;
F_41 (filter, tmp, &del_list, next) {
F_44 ( & V_34 -> V_32 ) ;
F_27 ( V_34 ) ;
}
}
static void F_20 ( struct V_4 * V_5 )
{
struct V_33 * V_34 = NULL , * V_115 , * V_117 = NULL ;
F_40 ( V_116 ) ;
int V_6 = 0 ;
F_36 ( & V_5 -> V_110 ) ;
F_41 (filter, tmp, &priv->filters, next) {
if ( V_6 > V_118 )
break;
if ( V_34 -> V_80 &&
! F_45 ( & V_34 -> V_32 ) &&
F_46 ( V_5 -> V_2 ,
V_34 -> V_74 , V_34 -> V_89 ,
V_34 -> V_37 ) ) {
F_42 ( & V_34 -> V_93 , & V_116 ) ;
F_43 ( & V_34 -> V_95 ) ;
} else
V_117 = V_34 ;
V_6 ++ ;
}
if ( V_117 && ( & V_117 -> V_93 != V_5 -> V_94 . V_93 ) )
F_42 ( & V_5 -> V_94 , & V_117 -> V_93 ) ;
F_38 ( & V_5 -> V_110 ) ;
F_41 (filter, tmp, &del_list, next)
F_27 ( V_34 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
V_42 V_119 , T_4 V_120 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
int V_113 ;
int V_122 ;
F_48 ( V_123 , V_5 , L_4 , V_120 ) ;
F_49 ( V_120 , V_5 -> V_124 ) ;
F_50 ( & V_82 -> V_125 ) ;
if ( V_82 -> V_126 && V_5 -> V_19 ) {
V_113 = F_51 ( V_82 -> V_2 , V_5 ) ;
if ( V_113 )
F_18 ( V_5 , L_5 ) ;
}
if ( F_52 ( V_82 -> V_2 , V_5 -> V_64 , V_120 , & V_122 ) )
F_48 ( V_123 , V_5 , L_6 , V_120 ) ;
F_53 ( & V_82 -> V_125 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
V_42 V_119 , T_4 V_120 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
int V_113 ;
F_48 ( V_123 , V_5 , L_7 , V_120 ) ;
F_55 ( V_120 , V_5 -> V_124 ) ;
F_50 ( & V_82 -> V_125 ) ;
F_56 ( V_82 -> V_2 , V_5 -> V_64 , V_120 ) ;
if ( V_82 -> V_126 && V_5 -> V_19 ) {
V_113 = F_51 ( V_82 -> V_2 , V_5 ) ;
if ( V_113 )
F_18 ( V_5 , L_5 ) ;
}
F_53 ( & V_82 -> V_125 ) ;
return 0 ;
}
static void F_57 ( unsigned char V_76 [ V_78 + 2 ] , T_5 V_127 )
{
int V_6 ;
for ( V_6 = V_78 - 1 ; V_6 >= 0 ; -- V_6 ) {
V_76 [ V_6 ] = V_127 & 0xff ;
V_127 >>= 8 ;
}
memset ( & V_76 [ V_78 ] , 0 , 2 ) ;
}
static int F_58 ( struct V_4 * V_5 ,
unsigned char * V_128 , int * V_71 , T_5 * V_81 )
{
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_129 * V_2 = V_82 -> V_2 ;
int V_113 ;
switch ( V_2 -> V_130 . V_131 ) {
case V_132 : {
struct V_133 V_134 ;
T_1 V_135 [ 16 ] = { 0 } ;
V_134 . V_71 = * V_71 ;
memcpy ( & V_135 [ 10 ] , V_128 , V_78 ) ;
V_135 [ 5 ] = V_5 -> V_64 ;
V_113 = F_59 ( V_2 , & V_134 , V_135 , 0 , V_136 ) ;
break;
}
case V_137 : {
struct V_35 V_53 = { { NULL } } ;
T_2 V_68 = F_14 ( V_69 << 16 ) ;
struct V_55 V_56 = {
. V_58 = V_138 ,
. V_60 = 0 ,
. V_61 = 1 ,
. V_62 = V_63 ,
. V_65 = V_139 ,
} ;
V_56 . V_64 = V_5 -> V_64 ;
V_56 . V_71 = * V_71 ;
F_60 ( & V_56 . V_57 ) ;
V_53 . V_37 = V_54 ;
memcpy ( V_53 . V_75 . V_76 , V_128 , V_78 ) ;
memcpy ( V_53 . V_75 . V_79 , & V_68 , V_78 ) ;
F_16 ( & V_53 . V_57 , & V_56 . V_57 ) ;
V_113 = F_19 ( V_2 , & V_56 , V_81 ) ;
break;
}
default:
return - V_9 ;
}
if ( V_113 )
F_15 ( V_5 , L_8 ) ;
return V_113 ;
}
static void F_61 ( struct V_4 * V_5 ,
unsigned char * V_128 , int V_71 , T_5 V_81 )
{
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_129 * V_2 = V_82 -> V_2 ;
switch ( V_2 -> V_130 . V_131 ) {
case V_132 : {
struct V_133 V_134 ;
T_1 V_135 [ 16 ] = { 0 } ;
V_134 . V_71 = V_71 ;
memcpy ( & V_135 [ 10 ] , V_128 , V_78 ) ;
V_135 [ 5 ] = V_5 -> V_64 ;
F_62 ( V_2 , & V_134 , V_135 , V_136 ) ;
break;
}
case V_137 : {
F_17 ( V_2 , V_81 ) ;
break;
}
default:
F_18 ( V_5 , L_9 ) ;
}
}
static int F_63 ( struct V_4 * V_5 )
{
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_129 * V_2 = V_82 -> V_2 ;
struct V_140 * V_141 ;
int V_142 = 0 ;
int V_113 = 0 ;
T_5 V_81 ;
int * V_71 = & V_5 -> V_143 ;
T_5 V_128 = F_64 ( V_5 -> V_2 -> V_77 ) ;
F_48 ( V_144 , V_5 , L_10 ,
V_5 -> V_2 -> V_77 ) ;
V_142 = F_65 ( V_2 , V_5 -> V_64 , V_128 ) ;
if ( V_142 < 0 ) {
V_113 = V_142 ;
F_18 ( V_5 , L_11 ,
V_5 -> V_2 -> V_77 ) ;
return V_113 ;
}
if ( V_2 -> V_130 . V_131 == V_145 ) {
int V_143 = F_66 ( V_2 , V_5 -> V_64 ) ;
* V_71 = V_143 + V_142 ;
return 0 ;
}
V_113 = F_67 ( V_2 , 1 , 1 , V_71 ) ;
F_48 ( V_144 , V_5 , L_12 , * V_71 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_13 ) ;
goto V_146;
}
V_113 = F_58 ( V_5 , V_5 -> V_2 -> V_77 , V_71 , & V_81 ) ;
if ( V_113 )
goto V_147;
V_141 = F_68 ( sizeof( * V_141 ) , V_148 ) ;
if ( ! V_141 ) {
V_113 = - V_112 ;
goto V_149;
}
memcpy ( V_141 -> V_128 , V_5 -> V_2 -> V_77 , sizeof( V_141 -> V_128 ) ) ;
V_141 -> V_81 = V_81 ;
F_69 ( & V_141 -> V_150 ,
& V_5 -> V_151 [ V_141 -> V_128 [ V_152 ] ] ) ;
return 0 ;
V_149:
F_61 ( V_5 , V_5 -> V_2 -> V_77 , * V_71 , V_81 ) ;
V_147:
F_70 ( V_2 , * V_71 , 1 ) ;
V_146:
F_71 ( V_2 , V_5 -> V_64 , V_128 ) ;
return V_113 ;
}
static void F_72 ( struct V_4 * V_5 )
{
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_129 * V_2 = V_82 -> V_2 ;
int V_71 = V_5 -> V_143 ;
T_5 V_128 ;
if ( V_2 -> V_130 . V_131 == V_145 ) {
V_128 = F_64 ( V_5 -> V_2 -> V_77 ) ;
F_48 ( V_144 , V_5 , L_14 ,
V_5 -> V_2 -> V_77 ) ;
F_71 ( V_2 , V_5 -> V_64 , V_128 ) ;
} else {
struct V_140 * V_141 ;
struct V_153 * V_115 ;
struct V_84 * V_154 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_155 ; ++ V_6 ) {
V_154 = & V_5 -> V_151 [ V_6 ] ;
F_73 (entry, tmp, bucket, hlist) {
V_128 = F_64 ( V_141 -> V_128 ) ;
F_48 ( V_144 , V_5 , L_14 ,
V_141 -> V_128 ) ;
F_61 ( V_5 , V_141 -> V_128 ,
V_71 , V_141 -> V_81 ) ;
F_71 ( V_2 , V_5 -> V_64 , V_128 ) ;
F_74 ( & V_141 -> V_150 ) ;
F_75 ( V_141 , V_156 ) ;
}
}
F_48 ( V_144 , V_5 , L_15 ,
V_5 -> V_64 , V_71 ) ;
F_70 ( V_2 , V_71 , 1 ) ;
V_5 -> V_157 &= ~ V_158 ;
}
}
static int F_76 ( struct V_4 * V_5 , int V_71 ,
unsigned char * V_159 , unsigned char * V_160 )
{
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_129 * V_2 = V_82 -> V_2 ;
int V_113 = 0 ;
T_5 V_161 = F_64 ( V_159 ) ;
if ( V_2 -> V_130 . V_131 != V_145 ) {
struct V_84 * V_154 ;
unsigned int V_151 ;
struct V_140 * V_141 ;
struct V_153 * V_115 ;
T_5 V_162 = F_64 ( V_160 ) ;
V_154 = & V_5 -> V_151 [ V_160 [ V_152 ] ] ;
F_73 (entry, tmp, bucket, hlist) {
if ( F_77 ( V_141 -> V_128 , V_160 ) ) {
F_61 ( V_5 , V_141 -> V_128 ,
V_71 , V_141 -> V_81 ) ;
F_71 ( V_2 , V_5 -> V_64 ,
V_162 ) ;
F_74 ( & V_141 -> V_150 ) ;
F_78 () ;
memcpy ( V_141 -> V_128 , V_159 , V_78 ) ;
V_141 -> V_81 = 0 ;
V_151 = V_159 [ V_152 ] ;
F_69 ( & V_141 -> V_150 ,
& V_5 -> V_151 [ V_151 ] ) ;
F_65 ( V_2 , V_5 -> V_64 , V_161 ) ;
V_113 = F_58 ( V_5 , V_159 ,
& V_71 ,
& V_141 -> V_81 ) ;
return V_113 ;
}
}
return - V_9 ;
}
return F_79 ( V_2 , V_5 -> V_64 , V_71 , V_161 ) ;
}
T_5 F_64 ( T_1 * V_163 )
{
T_5 V_128 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_78 ; V_6 ++ ) {
V_128 <<= 8 ;
V_128 |= V_163 [ V_6 ] ;
}
return V_128 ;
}
static int F_80 ( struct V_4 * V_5 )
{
int V_113 = 0 ;
if ( V_5 -> V_19 ) {
V_113 = F_76 ( V_5 , V_5 -> V_143 ,
V_5 -> V_2 -> V_77 , V_5 -> V_160 ) ;
if ( V_113 )
F_18 ( V_5 , L_16 ) ;
memcpy ( V_5 -> V_160 , V_5 -> V_2 -> V_77 ,
sizeof( V_5 -> V_160 ) ) ;
} else
F_48 ( V_123 , V_5 , L_17 ) ;
return V_113 ;
}
static int F_81 ( struct V_1 * V_2 , void * V_163 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_164 * V_108 = V_163 ;
int V_113 ;
if ( ! F_82 ( V_108 -> V_165 ) )
return - V_166 ;
memcpy ( V_2 -> V_77 , V_108 -> V_165 , V_78 ) ;
F_50 ( & V_82 -> V_125 ) ;
V_113 = F_80 ( V_5 ) ;
F_53 ( & V_82 -> V_125 ) ;
return V_113 ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_167 * V_115 , * V_168 ;
F_41 (mc_to_del, tmp, &priv->mc_list, list) {
F_28 ( & V_168 -> V_57 ) ;
F_29 ( V_168 ) ;
}
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_169 * V_170 ;
struct V_167 * V_115 ;
F_83 ( V_2 ) ;
F_85 (ha, dev) {
V_115 = F_24 ( sizeof( struct V_167 ) , V_90 ) ;
if ( ! V_115 ) {
F_83 ( V_2 ) ;
return;
}
memcpy ( V_115 -> V_163 , V_170 -> V_163 , V_78 ) ;
F_16 ( & V_115 -> V_57 , & V_5 -> V_171 ) ;
}
}
static void F_86 ( struct V_4 * V_5 ,
struct V_172 * V_173 ,
struct V_172 * V_174 )
{
struct V_167 * V_175 , * V_176 , * V_177 ;
bool V_178 ;
F_87 (dst_tmp, dst, list) {
V_178 = false ;
F_87 (src_tmp, src, list) {
if ( ! memcmp ( V_175 -> V_163 , V_176 -> V_163 , V_78 ) ) {
V_178 = true ;
break;
}
}
if ( ! V_178 )
V_175 -> V_179 = V_180 ;
}
F_87 (src_tmp, src, list) {
V_178 = false ;
F_87 (dst_tmp, dst, list) {
if ( ! memcmp ( V_175 -> V_163 , V_176 -> V_163 , V_78 ) ) {
V_175 -> V_179 = V_181 ;
V_178 = true ;
break;
}
}
if ( ! V_178 ) {
V_177 = F_88 ( V_176 ,
sizeof( struct V_167 ) ,
V_148 ) ;
if ( ! V_177 )
return;
V_177 -> V_179 = V_182 ;
F_16 ( & V_177 -> V_57 , V_173 ) ;
}
}
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_19 )
return;
F_37 ( V_5 -> V_82 -> V_114 , & V_5 -> V_183 ) ;
}
static void F_90 ( struct V_4 * V_5 ,
struct V_121 * V_82 )
{
int V_113 = 0 ;
if ( ! ( V_5 -> V_157 & V_184 ) ) {
if ( F_91 ( V_5 ) )
F_15 ( V_5 , L_18 ) ;
V_5 -> V_157 |= V_184 ;
switch ( V_82 -> V_2 -> V_130 . V_131 ) {
case V_137 :
V_113 = F_92 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_143 ,
V_185 ) ;
if ( V_113 )
F_18 ( V_5 , L_19 ) ;
V_5 -> V_157 |= V_186 ;
break;
case V_132 :
V_113 = F_93 ( V_82 -> V_2 ,
V_5 -> V_143 ,
V_5 -> V_64 ) ;
if ( V_113 )
F_18 ( V_5 , L_20 ) ;
if ( ! ( V_5 -> V_157 & V_186 ) ) {
V_113 = F_94 ( V_82 -> V_2 ,
V_5 -> V_143 ,
V_5 -> V_64 ) ;
if ( V_113 )
F_18 ( V_5 , L_21 ) ;
V_5 -> V_157 |= V_186 ;
}
break;
case V_145 :
V_113 = F_95 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_143 ,
1 ) ;
if ( V_113 )
F_18 ( V_5 , L_19 ) ;
break;
}
V_113 = F_96 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_187 ) ;
if ( V_113 )
F_18 ( V_5 , L_22 ) ;
V_113 = F_51 ( V_82 -> V_2 , V_5 ) ;
if ( V_113 )
F_18 ( V_5 , L_23 ) ;
}
}
static void F_97 ( struct V_4 * V_5 ,
struct V_121 * V_82 )
{
int V_113 = 0 ;
if ( F_91 ( V_5 ) )
F_15 ( V_5 , L_24 ) ;
V_5 -> V_157 &= ~ V_184 ;
switch ( V_82 -> V_2 -> V_130 . V_131 ) {
case V_137 :
V_113 = F_98 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_185 ) ;
if ( V_113 )
F_18 ( V_5 , L_25 ) ;
V_5 -> V_157 &= ~ V_186 ;
break;
case V_132 :
V_113 = F_99 ( V_82 -> V_2 ,
V_5 -> V_143 ,
V_5 -> V_64 ) ;
if ( V_113 )
F_18 ( V_5 , L_26 ) ;
if ( V_5 -> V_157 & V_186 ) {
V_113 = F_100 ( V_82 -> V_2 ,
V_5 -> V_143 ,
V_5 -> V_64 ) ;
if ( V_113 )
F_18 ( V_5 , L_27 ) ;
V_5 -> V_157 &= ~ V_186 ;
}
break;
case V_145 :
V_113 = F_95 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_143 , 0 ) ;
if ( V_113 )
F_18 ( V_5 , L_25 ) ;
break;
}
V_113 = F_51 ( V_82 -> V_2 , V_5 ) ;
if ( V_113 )
F_18 ( V_5 , L_28 ) ;
}
static void F_101 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_121 * V_82 )
{
struct V_167 * V_188 , * V_115 ;
T_5 V_189 = 0 ;
T_1 V_171 [ 16 ] = { 0 } ;
int V_113 = 0 ;
if ( V_2 -> V_157 & V_190 ) {
V_113 = F_96 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_187 ) ;
if ( V_113 )
F_18 ( V_5 , L_22 ) ;
if ( ! ( V_5 -> V_157 & V_186 ) ) {
switch ( V_82 -> V_2 -> V_130 . V_131 ) {
case V_137 :
V_113 = F_92 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_143 ,
V_191 ) ;
break;
case V_132 :
V_113 = F_94 ( V_82 -> V_2 ,
V_5 -> V_143 ,
V_5 -> V_64 ) ;
break;
case V_145 :
break;
}
if ( V_113 )
F_18 ( V_5 , L_29 ) ;
V_5 -> V_157 |= V_186 ;
}
} else {
if ( V_5 -> V_157 & V_186 ) {
switch ( V_82 -> V_2 -> V_130 . V_131 ) {
case V_137 :
V_113 = F_98 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_191 ) ;
break;
case V_132 :
V_113 = F_100 ( V_82 -> V_2 ,
V_5 -> V_143 ,
V_5 -> V_64 ) ;
break;
case V_145 :
break;
}
if ( V_113 )
F_18 ( V_5 , L_27 ) ;
V_5 -> V_157 &= ~ V_186 ;
}
V_113 = F_96 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_187 ) ;
if ( V_113 )
F_18 ( V_5 , L_22 ) ;
F_96 ( V_82 -> V_2 , V_5 -> V_64 , V_192 ,
1 , V_193 ) ;
F_102 ( V_2 ) ;
F_84 ( V_2 ) ;
F_103 ( V_2 ) ;
F_87 (mclist, &priv->mc_list, list) {
V_189 = F_64 ( V_188 -> V_163 ) ;
F_96 ( V_82 -> V_2 , V_5 -> V_64 ,
V_189 , 0 , V_193 ) ;
}
V_113 = F_96 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_194 ) ;
if ( V_113 )
F_18 ( V_5 , L_30 ) ;
F_86 ( V_5 , & V_5 -> V_195 , & V_5 -> V_171 ) ;
F_41 (mclist, tmp, &priv->curr_list, list) {
if ( V_188 -> V_179 == V_180 ) {
memcpy ( & V_171 [ 10 ] , V_188 -> V_163 , V_78 ) ;
V_171 [ 5 ] = V_5 -> V_64 ;
V_113 = F_104 ( V_82 -> V_2 ,
& V_5 -> V_72 . V_196 ,
V_171 ,
V_136 ,
V_188 -> V_81 ) ;
if ( V_113 )
F_18 ( V_5 , L_31 ) ;
F_28 ( & V_188 -> V_57 ) ;
F_29 ( V_188 ) ;
} else if ( V_188 -> V_179 == V_182 ) {
memcpy ( & V_171 [ 10 ] , V_188 -> V_163 , V_78 ) ;
V_171 [ 5 ] = V_5 -> V_64 ;
V_113 = F_105 ( V_82 -> V_2 ,
& V_5 -> V_72 . V_196 ,
V_171 ,
V_5 -> V_64 , 0 ,
V_136 ,
& V_188 -> V_81 ) ;
if ( V_113 )
F_18 ( V_5 , L_32 ) ;
}
}
}
}
static void F_106 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_121 * V_82 )
{
struct V_169 * V_170 ;
struct V_140 * V_141 ;
struct V_153 * V_115 ;
bool V_178 ;
T_5 V_128 ;
int V_113 = 0 ;
struct V_84 * V_154 ;
unsigned int V_6 ;
int V_197 = 0 ;
T_3 V_198 ;
for ( V_6 = 0 ; V_6 < V_155 ; ++ V_6 ) {
V_154 = & V_5 -> V_151 [ V_6 ] ;
F_73 (entry, tmp, bucket, hlist) {
V_178 = false ;
F_107 (ha, dev) {
if ( F_77 ( V_141 -> V_128 ,
V_170 -> V_163 ) ) {
V_178 = true ;
break;
}
}
if ( F_77 ( V_141 -> V_128 , V_2 -> V_77 ) )
V_178 = true ;
if ( ! V_178 ) {
V_128 = F_64 ( V_141 -> V_128 ) ;
F_61 ( V_5 , V_141 -> V_128 ,
V_5 -> V_143 ,
V_141 -> V_81 ) ;
F_71 ( V_82 -> V_2 , V_5 -> V_64 , V_128 ) ;
F_74 ( & V_141 -> V_150 ) ;
F_75 ( V_141 , V_156 ) ;
F_48 ( V_144 , V_5 , L_33 ,
V_141 -> V_128 , V_5 -> V_64 ) ;
++ V_197 ;
}
}
}
if ( ( V_5 -> V_157 & V_158 ) && 0 == V_197 )
return;
V_198 = V_5 -> V_157 ;
V_5 -> V_157 &= ~ V_158 ;
F_107 (ha, dev) {
V_178 = false ;
V_154 = & V_5 -> V_151 [ V_170 -> V_163 [ V_152 ] ] ;
F_31 (entry, bucket, hlist) {
if ( F_77 ( V_141 -> V_128 , V_170 -> V_163 ) ) {
V_178 = true ;
break;
}
}
if ( ! V_178 ) {
V_141 = F_68 ( sizeof( * V_141 ) , V_148 ) ;
if ( ! V_141 ) {
F_18 ( V_5 , L_34 ,
V_170 -> V_163 , V_5 -> V_64 ) ;
V_5 -> V_157 |= V_158 ;
break;
}
V_128 = F_64 ( V_170 -> V_163 ) ;
memcpy ( V_141 -> V_128 , V_170 -> V_163 , V_78 ) ;
V_113 = F_65 ( V_82 -> V_2 , V_5 -> V_64 , V_128 ) ;
if ( V_113 < 0 ) {
F_18 ( V_5 , L_35 ,
V_170 -> V_163 , V_5 -> V_64 , V_113 ) ;
F_29 ( V_141 ) ;
V_5 -> V_157 |= V_158 ;
break;
}
V_113 = F_58 ( V_5 , V_170 -> V_163 ,
& V_5 -> V_143 ,
& V_141 -> V_81 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_36 ,
V_170 -> V_163 , V_5 -> V_64 , V_113 ) ;
F_71 ( V_82 -> V_2 , V_5 -> V_64 , V_128 ) ;
F_29 ( V_141 ) ;
V_5 -> V_157 |= V_158 ;
break;
} else {
unsigned int V_151 ;
F_48 ( V_144 , V_5 , L_37 ,
V_170 -> V_163 , V_5 -> V_64 ) ;
V_151 = V_170 -> V_163 [ V_152 ] ;
V_154 = & V_5 -> V_151 [ V_151 ] ;
F_69 ( & V_141 -> V_150 , V_154 ) ;
}
}
}
if ( V_5 -> V_157 & V_158 ) {
F_15 ( V_5 , L_38 ,
V_5 -> V_64 ) ;
} else if ( V_198 & V_158 ) {
F_15 ( V_5 , L_39 ,
V_5 -> V_64 ) ;
}
}
static void F_108 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_183 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_50 ( & V_82 -> V_125 ) ;
if ( ! V_82 -> V_126 ) {
F_48 ( V_123 , V_5 , L_40 ) ;
goto V_111;
}
if ( ! V_5 -> V_19 ) {
F_48 ( V_123 , V_5 , L_41 ) ;
goto V_111;
}
if ( ! F_109 ( V_2 ) ) {
if ( ! F_110 ( V_82 , V_5 -> V_64 ) ) {
if ( V_5 -> V_199 . V_200 ) {
V_5 -> V_201 = V_202 ;
F_111 ( V_2 ) ;
F_48 ( V_203 , V_5 , L_42 ) ;
}
}
}
if ( V_2 -> V_204 & V_205 )
F_106 ( V_5 , V_2 , V_82 ) ;
if ( ( V_2 -> V_157 & V_206 ) ||
( V_5 -> V_157 & V_158 ) ) {
F_90 ( V_5 , V_82 ) ;
goto V_111;
}
if ( V_5 -> V_157 & V_184 )
F_97 ( V_5 , V_82 ) ;
F_101 ( V_5 , V_2 , V_82 ) ;
V_111:
F_53 ( & V_82 -> V_125 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_13 * V_14 ;
unsigned long V_157 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
V_14 = V_5 -> V_208 [ V_6 ] ;
F_113 ( & V_14 -> V_209 , V_157 ) ;
F_114 ( & V_14 -> V_12 ) ;
F_8 ( V_2 , V_14 , 0 ) ;
F_115 ( & V_14 -> V_209 , V_157 ) ;
}
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
int V_6 ;
if ( F_117 ( V_5 ) )
F_15 ( V_5 , L_43 , V_5 -> V_64 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
if ( ! F_118 ( F_119 ( V_2 , V_6 ) ) )
continue;
F_15 ( V_5 , L_44 ,
V_6 , V_5 -> V_211 [ V_6 ] -> V_71 , V_5 -> V_211 [ V_6 ] -> V_212 ,
V_5 -> V_211 [ V_6 ] -> V_213 , V_5 -> V_211 [ V_6 ] -> V_214 ) ;
}
V_5 -> V_215 . V_216 ++ ;
F_48 ( V_144 , V_5 , L_45 ) ;
F_37 ( V_82 -> V_114 , & V_5 -> V_217 ) ;
}
static struct V_218 * F_120 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_36 ( & V_5 -> V_219 ) ;
memcpy ( & V_5 -> V_220 , & V_5 -> V_221 , sizeof( V_5 -> V_221 ) ) ;
F_38 ( & V_5 -> V_219 ) ;
return & V_5 -> V_220 ;
}
static void F_121 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
int V_6 ;
V_5 -> V_222 = V_223 ;
V_5 -> V_224 = V_225 ;
V_5 -> V_226 = V_227 ;
V_5 -> V_228 = V_229 ;
F_48 ( V_230 , V_5 , L_46 ,
V_5 -> V_2 -> V_231 , V_5 -> V_222 , V_5 -> V_224 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
V_14 = V_5 -> V_208 [ V_6 ] ;
V_14 -> V_232 = V_5 -> V_222 ;
V_14 -> V_233 = V_5 -> V_224 ;
V_5 -> V_234 [ V_6 ] = V_235 ;
V_5 -> V_236 [ V_6 ] = 0 ;
V_5 -> V_237 [ V_6 ] = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
V_14 = V_5 -> V_238 [ V_6 ] ;
V_14 -> V_232 = V_5 -> V_226 ;
V_14 -> V_233 = V_5 -> V_228 ;
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
static void F_122 ( struct V_4 * V_5 )
{
unsigned long V_252 = ( unsigned long ) ( V_253 - V_5 -> V_250 ) ;
struct V_13 * V_14 ;
unsigned long V_254 ;
unsigned long V_255 ;
unsigned long V_256 ;
unsigned long V_257 ;
unsigned long V_258 ;
unsigned long V_259 ;
int V_233 ;
int V_17 , V_113 ;
if ( ! V_5 -> V_249 || V_252 < V_5 -> V_247 * V_260 )
return;
for ( V_17 = 0 ; V_17 < V_5 -> V_207 ; V_17 ++ ) {
F_36 ( & V_5 -> V_219 ) ;
V_257 = V_5 -> V_16 [ V_17 ] -> V_254 ;
V_258 = V_5 -> V_16 [ V_17 ] -> V_261 ;
F_38 ( & V_5 -> V_219 ) ;
V_259 = ( ( unsigned long ) ( V_257 -
V_5 -> V_236 [ V_17 ] ) ) ;
V_254 = V_259 ;
V_255 = V_254 * V_260 / V_252 ;
V_256 = V_254 ? ( ( unsigned long ) ( V_258 -
V_5 -> V_237 [ V_17 ] ) ) / V_254 : 0 ;
if ( V_255 > ( V_262 / V_5 -> V_207 ) &&
V_256 > V_263 ) {
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
if ( V_233 != V_5 -> V_234 [ V_17 ] ) {
V_5 -> V_234 [ V_17 ] = V_233 ;
V_14 = V_5 -> V_208 [ V_17 ] ;
V_14 -> V_233 = V_233 ;
V_14 -> V_232 = V_5 -> V_222 ;
V_113 = F_123 ( V_5 , V_14 ) ;
if ( V_113 )
F_18 ( V_5 , L_47 ,
V_17 ) ;
}
V_5 -> V_236 [ V_17 ] = V_257 ;
V_5 -> V_237 [ V_17 ] = V_258 ;
}
V_5 -> V_250 = V_253 ;
}
static void F_124 ( struct V_31 * V_32 )
{
struct V_264 * V_265 = F_125 ( V_32 ) ;
struct V_4 * V_5 = F_6 ( V_265 , struct V_4 ,
V_266 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
int V_113 ;
F_50 ( & V_82 -> V_125 ) ;
if ( V_82 -> V_126 ) {
if ( V_5 -> V_19 ) {
V_113 = F_126 ( V_82 , V_5 -> V_64 , 0 ) ;
if ( V_113 )
F_48 ( V_123 , V_5 , L_48 ) ;
F_122 ( V_5 ) ;
}
F_127 ( V_82 -> V_114 , & V_5 -> V_266 , V_267 ) ;
}
if ( V_82 -> V_268 [ V_269 + 1 - V_5 -> V_64 ] ) {
F_80 ( V_5 ) ;
V_82 -> V_268 [ V_269 + 1 - V_5 -> V_64 ] = 0 ;
}
F_53 ( & V_82 -> V_125 ) ;
}
static void F_128 ( struct V_31 * V_32 )
{
struct V_264 * V_265 = F_125 ( V_32 ) ;
struct V_4 * V_5 = F_6 ( V_265 , struct V_4 ,
V_270 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
F_50 ( & V_82 -> V_125 ) ;
if ( V_82 -> V_126 ) {
if ( V_82 -> V_2 -> V_130 . V_271 & V_272 )
F_129 ( V_82 ) ;
F_127 ( V_82 -> V_114 , & V_5 -> V_270 ,
V_273 ) ;
}
F_53 ( & V_82 -> V_125 ) ;
}
static void F_130 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_274 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
int V_275 = V_5 -> V_200 ;
F_50 ( & V_82 -> V_125 ) ;
if ( V_5 -> V_201 != V_275 ) {
if ( V_275 == V_276 ) {
F_131 ( V_5 , L_49 ) ;
F_132 ( V_5 -> V_2 ) ;
} else {
F_131 ( V_5 , L_42 ) ;
F_111 ( V_5 -> V_2 ) ;
}
}
V_5 -> V_201 = V_275 ;
F_53 ( & V_82 -> V_125 ) ;
}
int F_133 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_13 * V_14 ;
struct V_277 * V_211 ;
int V_278 = 0 ;
int V_279 = 0 ;
int V_113 = 0 ;
int V_6 ;
int V_280 ;
T_1 V_171 [ 16 ] = { 0 } ;
if ( V_5 -> V_19 ) {
F_48 ( V_144 , V_5 , L_50 ) ;
return 0 ;
}
F_60 ( & V_5 -> V_171 ) ;
F_60 ( & V_5 -> V_195 ) ;
F_60 ( & V_5 -> V_281 ) ;
memset ( & V_5 -> V_282 [ 0 ] , 0 ,
sizeof( struct V_283 ) * V_284 ) ;
V_2 -> V_231 = F_134 ( V_2 -> V_231 , V_5 -> V_285 ) ;
F_135 ( V_2 ) ;
F_48 ( V_144 , V_5 , L_51 , V_5 -> V_286 ) ;
V_113 = F_136 ( V_5 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_52 ) ;
return V_113 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
V_14 = V_5 -> V_208 [ V_6 ] ;
F_137 ( V_14 ) ;
V_113 = F_138 ( V_5 , V_14 , V_6 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_53 ) ;
goto V_287;
}
for ( V_280 = 0 ; V_280 < V_14 -> V_288 ; V_280 ++ )
V_14 -> V_289 [ V_280 ] . V_290 = V_291 ;
V_113 = F_123 ( V_5 , V_14 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_54 ) ;
F_139 ( V_5 , V_14 ) ;
goto V_287;
}
F_140 ( V_5 , V_14 ) ;
V_5 -> V_16 [ V_6 ] -> V_212 = V_14 -> V_292 . V_212 ;
++ V_278 ;
}
F_48 ( V_144 , V_5 , L_55 , V_5 -> V_64 ) ;
V_113 = F_63 ( V_5 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_56 ) ;
goto V_287;
}
V_82 -> V_268 [ V_5 -> V_64 ] = 0 ;
V_113 = F_141 ( V_5 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_57 ) ;
goto V_293;
}
V_113 = F_142 ( V_5 ) ;
if ( V_113 )
goto V_294;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
V_14 = V_5 -> V_238 [ V_6 ] ;
V_113 = F_138 ( V_5 , V_14 , V_6 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_58 ) ;
goto V_295;
}
V_113 = F_123 ( V_5 , V_14 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_54 ) ;
F_139 ( V_5 , V_14 ) ;
goto V_295;
}
F_48 ( V_144 , V_5 , L_59 , V_6 ) ;
V_14 -> V_289 -> V_296 = F_143 ( 0xffff ) ;
V_211 = V_5 -> V_211 [ V_6 ] ;
V_113 = F_144 ( V_5 , V_211 , V_14 -> V_292 . V_212 ,
V_6 / V_5 -> V_10 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_60 ) ;
F_139 ( V_5 , V_14 ) ;
goto V_295;
}
V_211 -> V_297 = F_119 ( V_2 , V_6 ) ;
F_140 ( V_5 , V_14 ) ;
for ( V_280 = 0 ; V_280 < V_211 -> V_298 ; V_280 += V_299 )
* ( ( T_3 * ) ( V_211 -> V_289 + V_280 ) ) = 0xffffffff ;
++ V_279 ;
}
V_113 = F_145 ( V_82 -> V_2 , V_5 -> V_64 ,
V_5 -> V_286 + V_300 ,
V_5 -> V_301 -> V_302 ,
V_5 -> V_301 -> V_303 ,
V_5 -> V_301 -> V_304 ,
V_5 -> V_301 -> V_305 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_61 ,
V_5 -> V_64 , V_113 ) ;
goto V_295;
}
V_113 = F_95 ( V_82 -> V_2 , V_5 -> V_64 , V_5 -> V_143 , 0 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_62 ) ;
goto V_295;
}
F_48 ( V_123 , V_5 , L_63 ) ;
V_113 = F_146 ( V_82 -> V_2 , V_5 -> V_64 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_64 ) ;
goto V_295;
}
memset ( & V_171 [ 10 ] , 0xff , V_78 ) ;
V_171 [ 5 ] = V_5 -> V_64 ;
if ( F_105 ( V_82 -> V_2 , & V_5 -> V_72 . V_196 , V_171 ,
V_5 -> V_64 , 0 , V_136 ,
& V_5 -> V_306 ) )
F_147 ( V_82 , L_65 ) ;
V_5 -> V_157 &= ~ ( V_184 | V_186 ) ;
F_37 ( V_82 -> V_114 , & V_5 -> V_183 ) ;
F_148 ( V_82 -> V_2 , & V_5 -> V_307 ) ;
V_5 -> V_19 = true ;
F_149 ( V_2 ) ;
F_150 ( V_2 ) ;
return 0 ;
V_295:
while ( V_279 -- ) {
F_151 ( V_5 , V_5 -> V_211 [ V_279 ] ) ;
F_139 ( V_5 , V_5 -> V_238 [ V_279 ] ) ;
}
F_152 ( V_5 ) ;
V_294:
F_153 ( V_5 ) ;
V_293:
F_72 ( V_5 ) ;
V_287:
while ( V_278 -- )
F_139 ( V_5 , V_5 -> V_208 [ V_278 ] ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ )
F_154 ( V_5 , V_5 -> V_16 [ V_6 ] ) ;
return V_113 ;
}
void F_155 ( struct V_1 * V_2 , int V_308 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_167 * V_188 , * V_115 ;
struct V_283 * V_309 , * V_310 ;
int V_6 ;
T_1 V_171 [ 16 ] = { 0 } ;
if ( ! V_5 -> V_19 ) {
F_48 ( V_144 , V_5 , L_66 ) ;
return;
}
F_156 ( V_82 -> V_2 , V_5 -> V_64 ) ;
F_157 ( V_2 ) ;
if ( V_308 )
F_158 ( V_2 ) ;
F_159 ( V_2 ) ;
F_160 ( V_2 ) ;
F_161 ( V_2 ) ;
V_5 -> V_19 = false ;
if ( V_82 -> V_2 -> V_130 . V_131 ==
V_137 ) {
V_5 -> V_157 &= ~ ( V_184 |
V_186 ) ;
F_98 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_185 ) ;
F_98 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_191 ) ;
} else if ( V_5 -> V_157 & V_184 ) {
V_5 -> V_157 &= ~ V_184 ;
F_99 ( V_82 -> V_2 , V_5 -> V_143 ,
V_5 -> V_64 ) ;
if ( V_5 -> V_157 & V_186 ) {
F_100 ( V_82 -> V_2 , V_5 -> V_143 ,
V_5 -> V_64 ) ;
V_5 -> V_157 &= ~ V_186 ;
}
}
memset ( & V_171 [ 10 ] , 0xff , V_78 ) ;
V_171 [ 5 ] = V_5 -> V_64 ;
F_104 ( V_82 -> V_2 , & V_5 -> V_72 . V_196 , V_171 ,
V_136 , V_5 -> V_306 ) ;
F_87 (mclist, &priv->curr_list, list) {
memcpy ( & V_171 [ 10 ] , V_188 -> V_163 , V_78 ) ;
V_171 [ 5 ] = V_5 -> V_64 ;
F_104 ( V_82 -> V_2 , & V_5 -> V_72 . V_196 ,
V_171 , V_136 , V_188 -> V_81 ) ;
}
F_83 ( V_2 ) ;
F_41 (mclist, tmp, &priv->curr_list, list) {
F_28 ( & V_188 -> V_57 ) ;
F_29 ( V_188 ) ;
}
F_96 ( V_82 -> V_2 , V_5 -> V_64 , 0 , 1 , V_193 ) ;
if ( V_82 -> V_2 -> V_130 . V_131 ==
V_137 ) {
F_162 () ;
F_41 (flow, tmp_flow,
&priv->ethtool_list, list) {
F_17 ( V_82 -> V_2 , V_309 -> V_37 ) ;
F_28 ( & V_309 -> V_57 ) ;
}
}
F_152 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
F_151 ( V_5 , V_5 -> V_211 [ V_6 ] ) ;
F_139 ( V_5 , V_5 -> V_238 [ V_6 ] ) ;
}
F_163 ( 10 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ )
F_164 ( V_2 , V_5 -> V_211 [ V_6 ] ) ;
F_153 ( V_5 ) ;
F_72 ( V_5 ) ;
if ( ! ( V_82 -> V_2 -> V_130 . V_271 & V_311 ) )
V_82 -> V_268 [ V_5 -> V_64 ] = 1 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
struct V_13 * V_14 = V_5 -> V_208 [ V_6 ] ;
F_165 () ;
while ( ! F_166 ( V_14 ) ) {
F_167 ( L_67 , V_6 ) ;
F_168 ( 1 ) ;
}
F_169 () ;
while ( F_170 ( V_312 , & V_14 -> V_12 . V_313 ) )
F_163 ( 1 ) ;
F_154 ( V_5 , V_5 -> V_16 [ V_6 ] ) ;
F_139 ( V_5 , V_14 ) ;
}
}
static void F_171 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_217 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_48 ( V_144 , V_5 , L_68 , V_5 -> V_64 ) ;
F_50 ( & V_82 -> V_125 ) ;
if ( V_5 -> V_19 ) {
F_155 ( V_2 , 1 ) ;
if ( F_133 ( V_2 ) )
F_18 ( V_5 , L_69 , V_5 -> V_64 ) ;
}
F_53 ( & V_82 -> V_125 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
int V_6 ;
if ( F_126 ( V_82 , V_5 -> V_64 , 1 ) )
F_48 ( V_123 , V_5 , L_70 ) ;
memset ( & V_5 -> V_221 , 0 , sizeof( V_5 -> V_221 ) ) ;
memset ( & V_5 -> V_314 , 0 , sizeof( V_5 -> V_314 ) ) ;
memset ( & V_5 -> V_315 , 0 , sizeof( V_5 -> V_315 ) ) ;
memset ( & V_5 -> V_215 , 0 , sizeof( V_5 -> V_215 ) ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
V_5 -> V_211 [ V_6 ] -> V_261 = 0 ;
V_5 -> V_211 [ V_6 ] -> V_254 = 0 ;
V_5 -> V_211 [ V_6 ] -> V_316 = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
V_5 -> V_16 [ V_6 ] -> V_261 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_254 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_317 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_318 = 0 ;
}
}
static int F_173 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
int V_113 = 0 ;
F_50 ( & V_82 -> V_125 ) ;
if ( ! V_82 -> V_126 ) {
F_18 ( V_5 , L_71 ) ;
V_113 = - V_319 ;
goto V_111;
}
F_172 ( V_2 ) ;
V_113 = F_133 ( V_2 ) ;
if ( V_113 )
F_18 ( V_5 , L_72 , V_5 -> V_64 ) ;
V_111:
F_53 ( & V_82 -> V_125 ) ;
return V_113 ;
}
static int F_174 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
F_48 ( V_320 , V_5 , L_73 ) ;
F_50 ( & V_82 -> V_125 ) ;
F_155 ( V_2 , 0 ) ;
F_132 ( V_2 ) ;
F_53 ( & V_82 -> V_125 ) ;
return 0 ;
}
void F_175 ( struct V_4 * V_5 )
{
int V_6 ;
#ifdef F_176
F_177 ( V_5 -> V_2 -> V_321 ) ;
V_5 -> V_2 -> V_321 = NULL ;
#endif
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
if ( V_5 -> V_211 && V_5 -> V_211 [ V_6 ] )
F_178 ( V_5 , & V_5 -> V_211 [ V_6 ] ) ;
if ( V_5 -> V_238 && V_5 -> V_238 [ V_6 ] )
F_179 ( V_5 , & V_5 -> V_238 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
if ( V_5 -> V_16 [ V_6 ] )
F_180 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_5 -> V_301 -> V_322 , V_5 -> V_323 ) ;
if ( V_5 -> V_208 [ V_6 ] )
F_179 ( V_5 , & V_5 -> V_208 [ V_6 ] ) ;
}
if ( V_5 -> V_324 ) {
F_70 ( V_5 -> V_82 -> V_2 , V_5 -> V_324 , V_5 -> V_210 ) ;
V_5 -> V_324 = 0 ;
}
}
int F_181 ( struct V_4 * V_5 )
{
struct V_325 * V_301 = V_5 -> V_301 ;
int V_6 ;
int V_113 ;
int V_326 ;
V_113 = F_67 ( V_5 -> V_82 -> V_2 , V_5 -> V_210 , 256 , & V_5 -> V_324 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_74 ) ;
return V_113 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
V_326 = F_182 ( V_6 % F_183 () ) ;
if ( F_184 ( V_5 , & V_5 -> V_238 [ V_6 ] ,
V_301 -> V_327 , V_6 , V_328 , V_326 ) )
goto V_113;
if ( F_185 ( V_5 , & V_5 -> V_211 [ V_6 ] , V_5 -> V_324 + V_6 ,
V_301 -> V_327 , V_329 , V_326 ) )
goto V_113;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
V_326 = F_182 ( V_6 % F_183 () ) ;
if ( F_184 ( V_5 , & V_5 -> V_208 [ V_6 ] ,
V_301 -> V_322 , V_6 , V_330 , V_326 ) )
goto V_113;
if ( F_186 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_301 -> V_322 , V_5 -> V_323 ,
V_326 ) )
goto V_113;
}
#ifdef F_176
if ( V_5 -> V_82 -> V_2 -> V_130 . V_331 ) {
V_5 -> V_2 -> V_321 = F_187 ( V_5 -> V_82 -> V_2 -> V_130 . V_331 ) ;
if ( ! V_5 -> V_2 -> V_321 )
goto V_113;
}
#endif
return 0 ;
V_113:
F_18 ( V_5 , L_75 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_207 ; V_6 ++ ) {
if ( V_5 -> V_16 [ V_6 ] )
F_180 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_301 -> V_322 ,
V_5 -> V_323 ) ;
if ( V_5 -> V_208 [ V_6 ] )
F_179 ( V_5 , & V_5 -> V_208 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_210 ; V_6 ++ ) {
if ( V_5 -> V_211 [ V_6 ] )
F_178 ( V_5 , & V_5 -> V_211 [ V_6 ] ) ;
if ( V_5 -> V_238 [ V_6 ] )
F_179 ( V_5 , & V_5 -> V_238 [ V_6 ] ) ;
}
return - V_112 ;
}
void F_188 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
F_48 ( V_144 , V_5 , L_76 , V_5 -> V_64 ) ;
if ( V_5 -> V_332 )
F_189 ( V_2 ) ;
if ( V_5 -> V_333 )
F_190 ( V_82 -> V_2 , & V_5 -> V_334 , V_335 ) ;
F_191 ( & V_5 -> V_266 ) ;
F_191 ( & V_5 -> V_270 ) ;
F_192 ( V_82 -> V_114 ) ;
F_50 ( & V_82 -> V_125 ) ;
V_82 -> V_336 [ V_5 -> V_64 ] = NULL ;
F_53 ( & V_82 -> V_125 ) ;
F_175 ( V_5 ) ;
F_29 ( V_5 -> V_211 ) ;
F_29 ( V_5 -> V_238 ) ;
F_193 ( V_2 ) ;
}
static int F_194 ( struct V_1 * V_2 , int V_337 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
int V_113 = 0 ;
F_48 ( V_144 , V_5 , L_77 ,
V_2 -> V_231 , V_337 ) ;
if ( ( V_337 < V_338 ) || ( V_337 > V_5 -> V_285 ) ) {
F_18 ( V_5 , L_78 , V_337 ) ;
return - V_339 ;
}
V_2 -> V_231 = V_337 ;
if ( F_195 ( V_2 ) ) {
F_50 ( & V_82 -> V_125 ) ;
if ( ! V_82 -> V_126 ) {
F_48 ( V_144 , V_5 , L_79 ) ;
} else {
F_155 ( V_2 , 1 ) ;
V_113 = F_133 ( V_2 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_80 ,
V_5 -> V_64 ) ;
F_37 ( V_82 -> V_114 , & V_5 -> V_217 ) ;
}
}
F_53 ( & V_82 -> V_125 ) ;
}
return 0 ;
}
static int F_196 ( struct V_1 * V_2 , struct V_340 * V_341 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_342 V_343 ;
if ( F_197 ( & V_343 , V_341 -> V_344 , sizeof( V_343 ) ) )
return - V_345 ;
if ( V_343 . V_157 )
return - V_9 ;
if ( ! ( V_82 -> V_2 -> V_130 . V_271 & V_272 ) )
return - V_9 ;
switch ( V_343 . V_346 ) {
case V_347 :
case V_348 :
break;
default:
return - V_349 ;
}
switch ( V_343 . V_350 ) {
case V_351 :
break;
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
case V_362 :
case V_363 :
case V_364 :
case V_365 :
V_343 . V_350 = V_352 ;
break;
default:
return - V_349 ;
}
if ( F_198 ( V_2 , V_343 . V_346 , V_343 . V_350 ) ) {
V_343 . V_346 = V_347 ;
V_343 . V_350 = V_351 ;
}
return F_199 ( V_341 -> V_344 , & V_343 ,
sizeof( V_343 ) ) ? - V_345 : 0 ;
}
static int F_200 ( struct V_1 * V_2 , struct V_340 * V_341 , int V_366 )
{
switch ( V_366 ) {
case V_367 :
return F_196 ( V_2 , V_341 ) ;
default:
return - V_368 ;
}
}
static int F_201 ( struct V_1 * V_369 ,
T_6 V_370 )
{
struct V_4 * V_5 = F_2 ( V_369 ) ;
if ( V_370 & V_371 )
V_5 -> V_372 |= F_202 ( V_373 ) ;
else
V_5 -> V_372 &=
F_202 ( ~ V_373 ) ;
F_203 ( V_369 , V_370 ) ;
return 0 ;
}
static int F_204 ( struct V_1 * V_2 , int V_374 , T_1 * V_128 )
{
struct V_4 * V_375 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_375 -> V_82 ;
T_5 V_376 = F_64 ( V_128 ) ;
if ( ! F_82 ( V_128 ) )
return - V_9 ;
return F_205 ( V_82 -> V_2 , V_375 -> V_64 , V_374 , V_376 ) ;
}
static int F_206 ( struct V_1 * V_2 , int V_377 , T_4 V_378 , T_1 V_379 )
{
struct V_4 * V_375 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_375 -> V_82 ;
return F_207 ( V_82 -> V_2 , V_375 -> V_64 , V_377 , V_378 , V_379 ) ;
}
static int F_208 ( struct V_1 * V_2 , int V_377 , bool V_380 )
{
struct V_4 * V_375 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_375 -> V_82 ;
return F_209 ( V_82 -> V_2 , V_375 -> V_64 , V_377 , V_380 ) ;
}
static int F_210 ( struct V_1 * V_2 , int V_377 , struct V_381 * V_382 )
{
struct V_4 * V_375 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_375 -> V_82 ;
return F_211 ( V_82 -> V_2 , V_375 -> V_64 , V_377 , V_382 ) ;
}
static int F_212 ( struct V_1 * V_2 , int V_377 , int V_200 )
{
struct V_4 * V_375 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_375 -> V_82 ;
return F_213 ( V_82 -> V_2 , V_375 -> V_64 , V_377 , V_200 ) ;
}
int F_214 ( struct V_121 * V_82 , int V_64 ,
struct V_325 * V_301 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_6 ;
int V_113 ;
T_5 V_376 ;
V_2 = F_215 ( sizeof( struct V_4 ) ,
V_383 , V_384 ) ;
if ( V_2 == NULL )
return - V_112 ;
F_216 ( V_2 , V_301 -> V_210 ) ;
F_217 ( V_2 , V_301 -> V_207 ) ;
F_218 ( V_2 , & V_82 -> V_2 -> V_385 -> V_2 ) ;
V_2 -> V_386 = V_64 - 1 ;
V_5 = F_2 ( V_2 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_82 = V_82 ;
V_5 -> V_387 = & V_82 -> V_385 -> V_2 ;
V_5 -> V_301 = V_301 ;
V_5 -> V_64 = V_64 ;
V_5 -> V_19 = false ;
V_5 -> V_157 = V_301 -> V_157 ;
V_5 -> V_372 = F_202 ( V_388 |
V_389 ) ;
V_5 -> V_10 = V_82 -> V_390 . V_10 ;
V_5 -> V_210 = V_301 -> V_210 ;
V_5 -> V_211 = F_24 ( sizeof( struct V_277 * ) * V_383 ,
V_148 ) ;
if ( ! V_5 -> V_211 ) {
V_113 = - V_112 ;
goto V_111;
}
V_5 -> V_238 = F_24 ( sizeof( struct V_13 * ) * V_383 ,
V_148 ) ;
if ( ! V_5 -> V_238 ) {
V_113 = - V_112 ;
goto V_111;
}
V_5 -> V_207 = V_301 -> V_207 ;
V_5 -> V_391 = ( V_82 -> V_2 -> V_130 . V_392 == 64 ) ? 1 : 0 ;
V_5 -> V_393 = - 1 ;
V_5 -> V_394 = V_395 ;
F_219 ( & V_5 -> V_219 ) ;
F_25 ( & V_5 -> V_183 , F_108 ) ;
F_25 ( & V_5 -> V_217 , F_171 ) ;
F_25 ( & V_5 -> V_274 , F_130 ) ;
F_220 ( & V_5 -> V_266 , F_124 ) ;
F_220 ( & V_5 -> V_270 , F_128 ) ;
#ifdef F_221
if ( ! F_222 ( V_5 -> V_82 -> V_2 ) ) {
if ( V_82 -> V_2 -> V_130 . V_157 & V_396 ) {
V_2 -> V_397 = & V_398 ;
} else {
F_131 ( V_5 , L_81 ) ;
V_2 -> V_397 = & V_399 ;
}
}
#endif
for ( V_6 = 0 ; V_6 < V_155 ; ++ V_6 )
F_223 ( & V_5 -> V_151 [ V_6 ] ) ;
V_5 -> V_285 = V_82 -> V_2 -> V_130 . V_400 [ V_5 -> V_64 ] ;
V_2 -> V_401 = V_78 ;
F_57 ( V_2 -> V_77 , V_82 -> V_2 -> V_130 . V_402 [ V_5 -> V_64 ] ) ;
if ( ! F_82 ( V_2 -> V_77 ) ) {
if ( F_222 ( V_5 -> V_82 -> V_2 ) ) {
F_224 ( V_2 ) ;
F_15 ( V_5 , L_82 , V_2 -> V_77 ) ;
V_376 = F_64 ( V_2 -> V_77 ) ;
V_82 -> V_2 -> V_130 . V_402 [ V_5 -> V_64 ] = V_376 ;
} else {
F_18 ( V_5 , L_83 ,
V_5 -> V_64 , V_2 -> V_77 ) ;
V_113 = - V_9 ;
goto V_111;
}
}
memcpy ( V_5 -> V_160 , V_2 -> V_77 , sizeof( V_5 -> V_160 ) ) ;
V_5 -> V_323 = F_225 ( sizeof( struct V_403 ) +
V_404 * V_405 ) ;
V_113 = F_181 ( V_5 ) ;
if ( V_113 )
goto V_111;
#ifdef F_176
F_60 ( & V_5 -> V_94 ) ;
F_219 ( & V_5 -> V_110 ) ;
#endif
V_5 -> V_342 . V_157 = 0 ;
V_5 -> V_342 . V_346 = V_347 ;
V_5 -> V_342 . V_350 = V_351 ;
V_113 = F_226 ( V_82 -> V_2 , & V_5 -> V_334 ,
V_335 , V_335 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_84 ) ;
goto V_111;
}
V_5 -> V_333 = 1 ;
if ( F_227 ( V_5 -> V_82 -> V_2 ) )
V_2 -> V_406 = & V_407 ;
else
V_2 -> V_406 = & V_408 ;
V_2 -> V_409 = V_410 ;
F_216 ( V_2 , V_5 -> V_210 ) ;
F_217 ( V_2 , V_5 -> V_207 ) ;
F_228 ( V_2 , & V_411 ) ;
V_2 -> V_412 = V_413 | V_414 | V_415 ;
if ( V_82 -> V_416 )
V_2 -> V_412 |= V_417 | V_418 ;
V_2 -> V_419 = V_2 -> V_412 ;
V_2 -> V_412 |= V_420 | V_421 ;
V_2 -> V_370 = V_2 -> V_412 | V_422 |
V_423 | V_424 |
V_425 ;
V_2 -> V_412 |= V_371 ;
if ( V_82 -> V_2 -> V_130 . V_131 ==
V_137 )
V_2 -> V_412 |= V_426 ;
if ( V_82 -> V_2 -> V_130 . V_131 != V_145 )
V_2 -> V_204 |= V_205 ;
V_82 -> V_336 [ V_64 ] = V_2 ;
F_132 ( V_2 ) ;
F_121 ( V_5 ) ;
V_113 = F_229 ( V_2 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_85 , V_64 ) ;
goto V_111;
}
V_5 -> V_332 = 1 ;
F_15 ( V_5 , L_86 , V_301 -> V_210 ) ;
F_15 ( V_5 , L_87 , V_301 -> V_207 ) ;
F_203 ( V_5 -> V_2 , V_5 -> V_2 -> V_370 ) ;
F_135 ( V_2 ) ;
V_113 = F_145 ( V_82 -> V_2 , V_5 -> V_64 ,
V_5 -> V_286 + V_300 ,
V_301 -> V_302 , V_301 -> V_303 ,
V_301 -> V_304 , V_301 -> V_305 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_88
L_89 , V_5 -> V_64 , V_113 ) ;
goto V_111;
}
F_15 ( V_5 , L_63 ) ;
V_113 = F_146 ( V_82 -> V_2 , V_5 -> V_64 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_64 ) ;
goto V_111;
}
F_127 ( V_82 -> V_114 , & V_5 -> V_266 , V_267 ) ;
if ( V_82 -> V_2 -> V_130 . V_271 & V_272 )
F_127 ( V_82 -> V_114 , & V_5 -> V_270 ,
V_273 ) ;
return 0 ;
V_111:
F_188 ( V_2 ) ;
return V_113 ;
}
