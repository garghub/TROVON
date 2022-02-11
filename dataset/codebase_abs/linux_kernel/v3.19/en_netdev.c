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
struct V_147 * V_148 ;
int V_149 = 0 ;
int V_114 = 0 ;
T_5 V_81 = 0 ;
int * V_71 = & V_5 -> V_150 ;
T_5 V_137 = F_66 ( V_5 -> V_2 -> V_77 ) ;
F_48 ( V_136 , V_5 , L_12 ,
V_5 -> V_2 -> V_77 ) ;
V_149 = F_67 ( V_2 , V_5 -> V_64 , V_137 ) ;
if ( V_149 < 0 ) {
V_114 = V_149 ;
F_18 ( V_5 , L_13 ,
V_5 -> V_2 -> V_77 ) ;
return V_114 ;
}
if ( V_2 -> V_130 . V_139 == V_151 ) {
int V_150 = F_68 ( V_2 , V_5 -> V_64 ) ;
* V_71 = V_150 + V_149 ;
return 0 ;
}
V_114 = F_69 ( V_2 , 1 , 1 , V_71 , V_152 ) ;
F_48 ( V_136 , V_5 , L_14 , * V_71 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_15 ) ;
goto V_153;
}
V_114 = F_60 ( V_5 , V_5 -> V_2 -> V_77 , V_71 , & V_81 ) ;
if ( V_114 )
goto V_154;
V_114 = F_58 ( V_5 , V_5 -> V_2 -> V_77 , * V_71 ,
& V_5 -> V_155 ) ;
if ( V_114 )
goto V_156;
V_148 = F_70 ( sizeof( * V_148 ) , V_157 ) ;
if ( ! V_148 ) {
V_114 = - V_113 ;
goto V_158;
}
memcpy ( V_148 -> V_137 , V_5 -> V_2 -> V_77 , sizeof( V_148 -> V_137 ) ) ;
memcpy ( V_5 -> V_159 , V_148 -> V_137 , sizeof( V_5 -> V_159 ) ) ;
V_148 -> V_81 = V_81 ;
F_71 ( & V_148 -> V_160 ,
& V_5 -> V_161 [ V_148 -> V_137 [ V_162 ] ] ) ;
return 0 ;
V_158:
if ( V_5 -> V_155 )
F_17 ( V_5 -> V_82 -> V_2 , V_5 -> V_155 ) ;
V_156:
F_63 ( V_5 , V_5 -> V_2 -> V_77 , * V_71 , V_81 ) ;
V_154:
F_72 ( V_2 , * V_71 , 1 ) ;
V_153:
F_73 ( V_2 , V_5 -> V_64 , V_137 ) ;
return V_114 ;
}
static void F_74 ( struct V_4 * V_5 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_138 * V_2 = V_82 -> V_2 ;
int V_71 = V_5 -> V_150 ;
T_5 V_137 ;
if ( V_2 -> V_130 . V_139 == V_151 ) {
V_137 = F_66 ( V_5 -> V_2 -> V_77 ) ;
F_48 ( V_136 , V_5 , L_16 ,
V_5 -> V_2 -> V_77 ) ;
F_73 ( V_2 , V_5 -> V_64 , V_137 ) ;
} else {
struct V_147 * V_148 ;
struct V_163 * V_116 ;
struct V_84 * V_164 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_165 ; ++ V_6 ) {
V_164 = & V_5 -> V_161 [ V_6 ] ;
F_75 (entry, tmp, bucket, hlist) {
V_137 = F_66 ( V_148 -> V_137 ) ;
F_48 ( V_136 , V_5 , L_16 ,
V_148 -> V_137 ) ;
F_63 ( V_5 , V_148 -> V_137 ,
V_71 , V_148 -> V_81 ) ;
F_73 ( V_2 , V_5 -> V_64 , V_137 ) ;
F_76 ( & V_148 -> V_160 ) ;
F_77 ( V_148 , V_166 ) ;
}
}
if ( V_5 -> V_155 ) {
F_17 ( V_5 -> V_82 -> V_2 , V_5 -> V_155 ) ;
V_5 -> V_155 = 0 ;
}
F_48 ( V_136 , V_5 , L_17 ,
V_5 -> V_64 , V_71 ) ;
F_72 ( V_2 , V_71 , 1 ) ;
V_5 -> V_167 &= ~ V_168 ;
}
}
static int F_78 ( struct V_4 * V_5 , int V_71 ,
unsigned char * V_169 , unsigned char * V_170 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_138 * V_2 = V_82 -> V_2 ;
int V_114 = 0 ;
T_5 V_171 = F_66 ( V_169 ) ;
if ( V_2 -> V_130 . V_139 != V_151 ) {
struct V_84 * V_164 ;
unsigned int V_161 ;
struct V_147 * V_148 ;
struct V_163 * V_116 ;
T_5 V_172 = F_66 ( V_170 ) ;
V_164 = & V_5 -> V_161 [ V_170 [ V_162 ] ] ;
F_75 (entry, tmp, bucket, hlist) {
if ( F_79 ( V_148 -> V_137 , V_170 ) ) {
F_63 ( V_5 , V_148 -> V_137 ,
V_71 , V_148 -> V_81 ) ;
F_73 ( V_2 , V_5 -> V_64 ,
V_172 ) ;
F_76 ( & V_148 -> V_160 ) ;
F_80 () ;
memcpy ( V_148 -> V_137 , V_169 , V_78 ) ;
V_148 -> V_81 = 0 ;
V_161 = V_169 [ V_162 ] ;
F_71 ( & V_148 -> V_160 ,
& V_5 -> V_161 [ V_161 ] ) ;
F_67 ( V_2 , V_5 -> V_64 , V_171 ) ;
V_114 = F_60 ( V_5 , V_169 ,
& V_71 ,
& V_148 -> V_81 ) ;
if ( V_114 )
return V_114 ;
if ( V_5 -> V_155 ) {
F_17 ( V_5 -> V_82 -> V_2 , V_5 -> V_155 ) ;
V_5 -> V_155 = 0 ;
}
V_114 = F_58 ( V_5 , V_169 , V_71 ,
& V_5 -> V_155 ) ;
return V_114 ;
}
}
return - V_9 ;
}
return F_81 ( V_2 , V_5 -> V_64 , V_71 , V_171 ) ;
}
static int F_82 ( struct V_4 * V_5 ,
unsigned char V_169 [ V_78 + 2 ] )
{
int V_114 = 0 ;
if ( V_5 -> V_19 ) {
V_114 = F_78 ( V_5 , V_5 -> V_150 ,
V_169 , V_5 -> V_159 ) ;
if ( V_114 )
F_18 ( V_5 , L_18 ) ;
} else
F_48 ( V_124 , V_5 , L_19 ) ;
if ( ! V_114 )
memcpy ( V_5 -> V_159 , V_169 , sizeof( V_5 -> V_159 ) ) ;
return V_114 ;
}
static int F_83 ( struct V_1 * V_2 , void * V_129 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_173 * V_109 = V_129 ;
unsigned char V_169 [ V_78 + 2 ] ;
int V_114 ;
if ( ! F_84 ( V_109 -> V_174 ) )
return - V_175 ;
F_50 ( & V_82 -> V_126 ) ;
memcpy ( V_169 , V_109 -> V_174 , V_78 ) ;
V_114 = F_82 ( V_5 , V_169 ) ;
if ( ! V_114 )
memcpy ( V_2 -> V_77 , V_109 -> V_174 , V_78 ) ;
F_53 ( & V_82 -> V_126 ) ;
return V_114 ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_176 * V_116 , * V_177 ;
F_41 (mc_to_del, tmp, &priv->mc_list, list) {
F_28 ( & V_177 -> V_57 ) ;
F_29 ( V_177 ) ;
}
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_178 * V_179 ;
struct V_176 * V_116 ;
F_85 ( V_2 ) ;
F_87 (ha, dev) {
V_116 = F_24 ( sizeof( struct V_176 ) , V_90 ) ;
if ( ! V_116 ) {
F_85 ( V_2 ) ;
return;
}
memcpy ( V_116 -> V_129 , V_179 -> V_129 , V_78 ) ;
F_16 ( & V_116 -> V_57 , & V_5 -> V_180 ) ;
}
}
static void F_88 ( struct V_4 * V_5 ,
struct V_181 * V_182 ,
struct V_181 * V_183 )
{
struct V_176 * V_184 , * V_185 , * V_186 ;
bool V_187 ;
F_89 (dst_tmp, dst, list) {
V_187 = false ;
F_89 (src_tmp, src, list) {
if ( F_90 ( V_184 -> V_129 , V_185 -> V_129 ) ) {
V_187 = true ;
break;
}
}
if ( ! V_187 )
V_184 -> V_188 = V_189 ;
}
F_89 (src_tmp, src, list) {
V_187 = false ;
F_89 (dst_tmp, dst, list) {
if ( F_90 ( V_184 -> V_129 , V_185 -> V_129 ) ) {
V_184 -> V_188 = V_190 ;
V_187 = true ;
break;
}
}
if ( ! V_187 ) {
V_186 = F_91 ( V_185 ,
sizeof( struct V_176 ) ,
V_157 ) ;
if ( ! V_186 )
return;
V_186 -> V_188 = V_191 ;
F_16 ( & V_186 -> V_57 , V_182 ) ;
}
}
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_19 )
return;
F_37 ( V_5 -> V_82 -> V_115 , & V_5 -> V_192 ) ;
}
static void F_93 ( struct V_4 * V_5 ,
struct V_122 * V_82 )
{
int V_114 = 0 ;
if ( ! ( V_5 -> V_167 & V_193 ) ) {
if ( F_94 ( V_5 ) )
F_15 ( V_5 , L_20 ) ;
V_5 -> V_167 |= V_193 ;
switch ( V_82 -> V_2 -> V_130 . V_139 ) {
case V_145 :
V_114 = F_95 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_150 ,
V_194 ) ;
if ( V_114 )
F_18 ( V_5 , L_21 ) ;
V_5 -> V_167 |= V_195 ;
break;
case V_140 :
V_114 = F_96 ( V_82 -> V_2 ,
V_5 -> V_150 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_22 ) ;
if ( ! ( V_5 -> V_167 & V_195 ) ) {
V_114 = F_97 ( V_82 -> V_2 ,
V_5 -> V_150 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_23 ) ;
V_5 -> V_167 |= V_195 ;
}
break;
case V_151 :
V_114 = F_98 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_150 ,
1 ) ;
if ( V_114 )
F_18 ( V_5 , L_21 ) ;
break;
}
V_114 = F_99 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_196 ) ;
if ( V_114 )
F_18 ( V_5 , L_24 ) ;
}
}
static void F_100 ( struct V_4 * V_5 ,
struct V_122 * V_82 )
{
int V_114 = 0 ;
if ( F_94 ( V_5 ) )
F_15 ( V_5 , L_25 ) ;
V_5 -> V_167 &= ~ V_193 ;
switch ( V_82 -> V_2 -> V_130 . V_139 ) {
case V_145 :
V_114 = F_101 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_194 ) ;
if ( V_114 )
F_18 ( V_5 , L_26 ) ;
V_5 -> V_167 &= ~ V_195 ;
break;
case V_140 :
V_114 = F_102 ( V_82 -> V_2 ,
V_5 -> V_150 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_27 ) ;
if ( V_5 -> V_167 & V_195 ) {
V_114 = F_103 ( V_82 -> V_2 ,
V_5 -> V_150 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_28 ) ;
V_5 -> V_167 &= ~ V_195 ;
}
break;
case V_151 :
V_114 = F_98 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_150 , 0 ) ;
if ( V_114 )
F_18 ( V_5 , L_26 ) ;
break;
}
}
static void F_104 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_122 * V_82 )
{
struct V_176 * V_197 , * V_116 ;
T_5 V_198 = 0 ;
T_1 V_180 [ 16 ] = { 0 } ;
int V_114 = 0 ;
if ( V_2 -> V_167 & V_199 ) {
V_114 = F_99 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_196 ) ;
if ( V_114 )
F_18 ( V_5 , L_24 ) ;
if ( ! ( V_5 -> V_167 & V_195 ) ) {
switch ( V_82 -> V_2 -> V_130 . V_139 ) {
case V_145 :
V_114 = F_95 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_150 ,
V_200 ) ;
break;
case V_140 :
V_114 = F_97 ( V_82 -> V_2 ,
V_5 -> V_150 ,
V_5 -> V_64 ) ;
break;
case V_151 :
break;
}
if ( V_114 )
F_18 ( V_5 , L_29 ) ;
V_5 -> V_167 |= V_195 ;
}
} else {
if ( V_5 -> V_167 & V_195 ) {
switch ( V_82 -> V_2 -> V_130 . V_139 ) {
case V_145 :
V_114 = F_101 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_200 ) ;
break;
case V_140 :
V_114 = F_103 ( V_82 -> V_2 ,
V_5 -> V_150 ,
V_5 -> V_64 ) ;
break;
case V_151 :
break;
}
if ( V_114 )
F_18 ( V_5 , L_28 ) ;
V_5 -> V_167 &= ~ V_195 ;
}
V_114 = F_99 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_196 ) ;
if ( V_114 )
F_18 ( V_5 , L_24 ) ;
F_99 ( V_82 -> V_2 , V_5 -> V_64 , V_201 ,
1 , V_202 ) ;
F_105 ( V_2 ) ;
F_86 ( V_2 ) ;
F_106 ( V_2 ) ;
F_89 (mclist, &priv->mc_list, list) {
V_198 = F_66 ( V_197 -> V_129 ) ;
F_99 ( V_82 -> V_2 , V_5 -> V_64 ,
V_198 , 0 , V_202 ) ;
}
V_114 = F_99 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_203 ) ;
if ( V_114 )
F_18 ( V_5 , L_30 ) ;
F_88 ( V_5 , & V_5 -> V_204 , & V_5 -> V_180 ) ;
F_41 (mclist, tmp, &priv->curr_list, list) {
if ( V_197 -> V_188 == V_189 ) {
memcpy ( & V_180 [ 10 ] , V_197 -> V_129 , V_78 ) ;
V_180 [ 5 ] = V_5 -> V_64 ;
V_114 = F_107 ( V_82 -> V_2 ,
& V_5 -> V_72 . V_205 ,
V_180 ,
V_144 ,
V_197 -> V_81 ) ;
if ( V_114 )
F_18 ( V_5 , L_31 ) ;
if ( V_197 -> V_155 ) {
V_114 = F_17 ( V_5 -> V_82 -> V_2 , V_197 -> V_155 ) ;
if ( V_114 )
F_18 ( V_5 , L_32 ) ;
}
F_28 ( & V_197 -> V_57 ) ;
F_29 ( V_197 ) ;
} else if ( V_197 -> V_188 == V_191 ) {
memcpy ( & V_180 [ 10 ] , V_197 -> V_129 , V_78 ) ;
V_180 [ 5 ] = V_5 -> V_64 ;
V_114 = F_108 ( V_82 -> V_2 ,
& V_5 -> V_72 . V_205 ,
V_180 ,
V_5 -> V_64 , 0 ,
V_144 ,
& V_197 -> V_81 ) ;
if ( V_114 )
F_18 ( V_5 , L_33 ) ;
V_114 = F_58 ( V_5 , & V_180 [ 10 ] , V_5 -> V_150 ,
& V_197 -> V_155 ) ;
if ( V_114 )
F_18 ( V_5 , L_34 ) ;
}
}
}
}
static void F_109 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_122 * V_82 )
{
struct V_178 * V_179 ;
struct V_147 * V_148 ;
struct V_163 * V_116 ;
bool V_187 ;
T_5 V_137 ;
int V_114 = 0 ;
struct V_84 * V_164 ;
unsigned int V_6 ;
int V_206 = 0 ;
T_3 V_207 ;
for ( V_6 = 0 ; V_6 < V_165 ; ++ V_6 ) {
V_164 = & V_5 -> V_161 [ V_6 ] ;
F_75 (entry, tmp, bucket, hlist) {
V_187 = false ;
F_110 (ha, dev) {
if ( F_79 ( V_148 -> V_137 ,
V_179 -> V_129 ) ) {
V_187 = true ;
break;
}
}
if ( F_79 ( V_148 -> V_137 ,
V_5 -> V_159 ) )
V_187 = true ;
if ( ! V_187 ) {
V_137 = F_66 ( V_148 -> V_137 ) ;
F_63 ( V_5 , V_148 -> V_137 ,
V_5 -> V_150 ,
V_148 -> V_81 ) ;
F_73 ( V_82 -> V_2 , V_5 -> V_64 , V_137 ) ;
F_76 ( & V_148 -> V_160 ) ;
F_77 ( V_148 , V_166 ) ;
F_48 ( V_136 , V_5 , L_35 ,
V_148 -> V_137 , V_5 -> V_64 ) ;
++ V_206 ;
}
}
}
if ( ( V_5 -> V_167 & V_168 ) && 0 == V_206 )
return;
V_207 = V_5 -> V_167 ;
V_5 -> V_167 &= ~ V_168 ;
F_110 (ha, dev) {
V_187 = false ;
V_164 = & V_5 -> V_161 [ V_179 -> V_129 [ V_162 ] ] ;
F_31 (entry, bucket, hlist) {
if ( F_79 ( V_148 -> V_137 , V_179 -> V_129 ) ) {
V_187 = true ;
break;
}
}
if ( ! V_187 ) {
V_148 = F_70 ( sizeof( * V_148 ) , V_157 ) ;
if ( ! V_148 ) {
F_18 ( V_5 , L_36 ,
V_179 -> V_129 , V_5 -> V_64 ) ;
V_5 -> V_167 |= V_168 ;
break;
}
V_137 = F_66 ( V_179 -> V_129 ) ;
memcpy ( V_148 -> V_137 , V_179 -> V_129 , V_78 ) ;
V_114 = F_67 ( V_82 -> V_2 , V_5 -> V_64 , V_137 ) ;
if ( V_114 < 0 ) {
F_18 ( V_5 , L_37 ,
V_179 -> V_129 , V_5 -> V_64 , V_114 ) ;
F_29 ( V_148 ) ;
V_5 -> V_167 |= V_168 ;
break;
}
V_114 = F_60 ( V_5 , V_179 -> V_129 ,
& V_5 -> V_150 ,
& V_148 -> V_81 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_38 ,
V_179 -> V_129 , V_5 -> V_64 , V_114 ) ;
F_73 ( V_82 -> V_2 , V_5 -> V_64 , V_137 ) ;
F_29 ( V_148 ) ;
V_5 -> V_167 |= V_168 ;
break;
} else {
unsigned int V_161 ;
F_48 ( V_136 , V_5 , L_39 ,
V_179 -> V_129 , V_5 -> V_64 ) ;
V_161 = V_179 -> V_129 [ V_162 ] ;
V_164 = & V_5 -> V_161 [ V_161 ] ;
F_71 ( & V_148 -> V_160 , V_164 ) ;
}
}
}
if ( V_5 -> V_167 & V_168 ) {
F_15 ( V_5 , L_40 ,
V_5 -> V_64 ) ;
} else if ( V_207 & V_168 ) {
F_15 ( V_5 , L_41 ,
V_5 -> V_64 ) ;
}
}
static void F_111 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_192 ) ;
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
if ( V_5 -> V_208 . V_209 ) {
V_5 -> V_210 = V_211 ;
F_114 ( V_2 ) ;
F_48 ( V_212 , V_5 , L_44 ) ;
}
}
}
if ( V_2 -> V_213 & V_214 )
F_109 ( V_5 , V_2 , V_82 ) ;
if ( ( V_2 -> V_167 & V_215 ) ||
( V_5 -> V_167 & V_168 ) ) {
F_93 ( V_5 , V_82 ) ;
goto V_112;
}
if ( V_5 -> V_167 & V_193 )
F_100 ( V_5 , V_82 ) ;
F_104 ( V_5 , V_2 , V_82 ) ;
V_112:
F_53 ( & V_82 -> V_126 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_13 * V_14 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
V_14 = V_5 -> V_217 [ V_6 ] ;
F_116 ( & V_14 -> V_12 ) ;
}
}
static void F_117 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_6 ;
if ( F_118 ( V_5 ) )
F_15 ( V_5 , L_45 , V_5 -> V_64 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
if ( ! F_119 ( F_120 ( V_2 , V_6 ) ) )
continue;
F_15 ( V_5 , L_46 ,
V_6 , V_5 -> V_219 [ V_6 ] -> V_71 , V_5 -> V_219 [ V_6 ] -> V_220 ,
V_5 -> V_219 [ V_6 ] -> V_221 , V_5 -> V_219 [ V_6 ] -> V_222 ) ;
}
V_5 -> V_223 . V_224 ++ ;
F_48 ( V_136 , V_5 , L_47 ) ;
F_37 ( V_82 -> V_115 , & V_5 -> V_225 ) ;
}
static struct V_226 * F_121 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_36 ( & V_5 -> V_227 ) ;
memcpy ( & V_5 -> V_228 , & V_5 -> V_229 , sizeof( V_5 -> V_229 ) ) ;
F_38 ( & V_5 -> V_227 ) ;
return & V_5 -> V_228 ;
}
static void F_122 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
int V_6 ;
V_5 -> V_230 = V_231 ;
V_5 -> V_232 = V_233 ;
V_5 -> V_234 = V_235 ;
V_5 -> V_236 = V_237 ;
F_48 ( V_238 , V_5 , L_48 ,
V_5 -> V_2 -> V_239 , V_5 -> V_230 , V_5 -> V_232 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
V_14 = V_5 -> V_217 [ V_6 ] ;
V_14 -> V_240 = V_5 -> V_230 ;
V_14 -> V_241 = V_5 -> V_232 ;
V_5 -> V_242 [ V_6 ] = V_243 ;
V_5 -> V_244 [ V_6 ] = 0 ;
V_5 -> V_245 [ V_6 ] = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
V_14 = V_5 -> V_246 [ V_6 ] ;
V_14 -> V_240 = V_5 -> V_234 ;
V_14 -> V_241 = V_5 -> V_236 ;
}
V_5 -> V_247 = V_248 ;
V_5 -> V_249 = V_250 ;
V_5 -> V_251 = V_252 ;
V_5 -> V_253 = V_254 ;
V_5 -> V_255 = V_256 ;
V_5 -> V_257 = 1 ;
V_5 -> V_258 = 0 ;
V_5 -> V_259 = 0 ;
}
static void F_123 ( struct V_4 * V_5 )
{
unsigned long V_260 = ( unsigned long ) ( V_261 - V_5 -> V_258 ) ;
struct V_13 * V_14 ;
unsigned long V_262 ;
unsigned long V_263 ;
unsigned long V_264 ;
unsigned long V_265 ;
unsigned long V_266 ;
unsigned long V_267 ;
int V_241 ;
int V_17 , V_114 ;
if ( ! V_5 -> V_257 || V_260 < V_5 -> V_255 * V_268 )
return;
for ( V_17 = 0 ; V_17 < V_5 -> V_216 ; V_17 ++ ) {
F_36 ( & V_5 -> V_227 ) ;
V_265 = V_5 -> V_16 [ V_17 ] -> V_262 ;
V_266 = V_5 -> V_16 [ V_17 ] -> V_269 ;
F_38 ( & V_5 -> V_227 ) ;
V_267 = ( ( unsigned long ) ( V_265 -
V_5 -> V_244 [ V_17 ] ) ) ;
V_262 = V_267 ;
V_263 = V_262 * V_268 / V_260 ;
V_264 = V_262 ? ( ( unsigned long ) ( V_266 -
V_5 -> V_245 [ V_17 ] ) ) / V_262 : 0 ;
if ( V_263 > ( V_270 / V_5 -> V_216 ) &&
V_264 > V_271 ) {
if ( V_263 < V_5 -> V_247 )
V_241 = V_5 -> V_249 ;
else if ( V_263 > V_5 -> V_251 )
V_241 = V_5 -> V_253 ;
else
V_241 = ( V_263 - V_5 -> V_247 ) *
( V_5 -> V_253 - V_5 -> V_249 ) /
( V_5 -> V_251 - V_5 -> V_247 ) +
V_5 -> V_249 ;
} else {
V_241 = V_5 -> V_249 ;
}
if ( V_241 != V_5 -> V_242 [ V_17 ] ) {
V_5 -> V_242 [ V_17 ] = V_241 ;
V_14 = V_5 -> V_217 [ V_17 ] ;
V_14 -> V_241 = V_241 ;
V_14 -> V_240 = V_5 -> V_230 ;
V_114 = F_124 ( V_5 , V_14 ) ;
if ( V_114 )
F_18 ( V_5 , L_49 ,
V_17 ) ;
}
V_5 -> V_244 [ V_17 ] = V_265 ;
V_5 -> V_245 [ V_17 ] = V_266 ;
}
V_5 -> V_258 = V_261 ;
}
static void F_125 ( struct V_31 * V_32 )
{
struct V_272 * V_273 = F_126 ( V_32 ) ;
struct V_4 * V_5 = F_6 ( V_273 , struct V_4 ,
V_274 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_114 ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_82 -> V_127 ) {
if ( V_5 -> V_19 ) {
V_114 = F_127 ( V_82 , V_5 -> V_64 , 0 ) ;
if ( V_114 )
F_48 ( V_124 , V_5 , L_50 ) ;
F_123 ( V_5 ) ;
}
F_128 ( V_82 -> V_115 , & V_5 -> V_274 , V_275 ) ;
}
if ( V_82 -> V_276 [ V_277 + 1 - V_5 -> V_64 ] ) {
F_82 ( V_5 , V_5 -> V_159 ) ;
V_82 -> V_276 [ V_277 + 1 - V_5 -> V_64 ] = 0 ;
}
F_53 ( & V_82 -> V_126 ) ;
}
static void F_129 ( struct V_31 * V_32 )
{
struct V_272 * V_273 = F_126 ( V_32 ) ;
struct V_4 * V_5 = F_6 ( V_273 , struct V_4 ,
V_278 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_82 -> V_127 ) {
if ( V_82 -> V_2 -> V_130 . V_279 & V_280 )
F_130 ( V_82 ) ;
F_128 ( V_82 -> V_115 , & V_5 -> V_278 ,
V_281 ) ;
}
F_53 ( & V_82 -> V_126 ) ;
}
static void F_131 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_282 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_283 = V_5 -> V_209 ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_5 -> V_210 != V_283 ) {
if ( V_283 == V_284 ) {
F_132 ( V_5 , L_51 ) ;
F_133 ( V_5 -> V_2 ) ;
} else {
F_132 ( V_5 , L_44 ) ;
F_114 ( V_5 -> V_2 ) ;
}
}
V_5 -> V_210 = V_283 ;
F_53 ( & V_82 -> V_126 ) ;
}
static int F_134 ( struct V_4 * V_5 , int V_285 )
{
struct V_15 * V_17 = V_5 -> V_16 [ V_285 ] ;
int V_286 = V_5 -> V_82 -> V_2 -> V_286 ;
int V_96 = 0 ;
if ( ! F_135 ( & V_17 -> V_287 , V_157 ) )
return - V_113 ;
V_96 = F_136 ( V_285 , V_286 ,
V_17 -> V_287 ) ;
if ( V_96 )
F_137 ( V_17 -> V_287 ) ;
return V_96 ;
}
static void F_138 ( struct V_4 * V_5 , int V_285 )
{
F_137 ( V_5 -> V_16 [ V_285 ] -> V_287 ) ;
}
int F_139 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_13 * V_14 ;
struct V_288 * V_219 ;
int V_289 = 0 ;
int V_290 = 0 ;
int V_114 = 0 ;
int V_6 ;
int V_291 ;
T_1 V_180 [ 16 ] = { 0 } ;
if ( V_5 -> V_19 ) {
F_48 ( V_136 , V_5 , L_52 ) ;
return 0 ;
}
F_62 ( & V_5 -> V_180 ) ;
F_62 ( & V_5 -> V_204 ) ;
F_62 ( & V_5 -> V_292 ) ;
memset ( & V_5 -> V_293 [ 0 ] , 0 ,
sizeof( struct V_294 ) * V_295 ) ;
V_2 -> V_239 = F_140 ( V_2 -> V_239 , V_5 -> V_296 ) ;
F_141 ( V_2 ) ;
F_48 ( V_136 , V_5 , L_53 , V_5 -> V_297 ) ;
V_114 = F_142 ( V_5 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_54 ) ;
return V_114 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
V_14 = V_5 -> V_217 [ V_6 ] ;
F_143 ( V_14 ) ;
V_114 = F_134 ( V_5 , V_6 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_55 ) ;
goto V_298;
}
V_114 = F_144 ( V_5 , V_14 , V_6 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_56 ) ;
F_138 ( V_5 , V_6 ) ;
goto V_298;
}
for ( V_291 = 0 ; V_291 < V_14 -> V_299 ; V_291 ++ ) {
struct V_300 * V_301 = NULL ;
V_301 = F_145 ( V_14 -> V_302 , V_291 , V_5 -> V_303 ) +
V_5 -> V_304 ;
V_301 -> V_305 = V_306 ;
}
V_114 = F_124 ( V_5 , V_14 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_57 ) ;
F_146 ( V_5 , V_14 ) ;
F_138 ( V_5 , V_6 ) ;
goto V_298;
}
F_147 ( V_5 , V_14 ) ;
V_5 -> V_16 [ V_6 ] -> V_220 = V_14 -> V_307 . V_220 ;
++ V_289 ;
}
F_48 ( V_136 , V_5 , L_58 , V_5 -> V_64 ) ;
V_114 = F_65 ( V_5 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_59 ) ;
goto V_298;
}
V_82 -> V_276 [ V_5 -> V_64 ] = 0 ;
V_114 = F_148 ( V_5 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_60 ) ;
goto V_308;
}
V_114 = F_149 ( V_5 ) ;
if ( V_114 )
goto V_309;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
V_14 = V_5 -> V_246 [ V_6 ] ;
V_114 = F_144 ( V_5 , V_14 , V_6 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_61 ) ;
goto V_310;
}
V_114 = F_124 ( V_5 , V_14 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_57 ) ;
F_146 ( V_5 , V_14 ) ;
goto V_310;
}
F_48 ( V_136 , V_5 , L_62 , V_6 ) ;
V_14 -> V_302 -> V_311 = F_150 ( 0xffff ) ;
V_219 = V_5 -> V_219 [ V_6 ] ;
V_114 = F_151 ( V_5 , V_219 , V_14 -> V_307 . V_220 ,
V_6 / V_5 -> V_10 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_63 ) ;
F_146 ( V_5 , V_14 ) ;
goto V_310;
}
V_219 -> V_312 = F_120 ( V_2 , V_6 ) ;
F_147 ( V_5 , V_14 ) ;
for ( V_291 = 0 ; V_291 < V_219 -> V_313 ; V_291 += V_314 )
* ( ( T_3 * ) ( V_219 -> V_302 + V_291 ) ) = 0xffffffff ;
++ V_290 ;
}
V_114 = F_152 ( V_82 -> V_2 , V_5 -> V_64 ,
V_5 -> V_297 + V_315 ,
V_5 -> V_316 -> V_317 ,
V_5 -> V_316 -> V_318 ,
V_5 -> V_316 -> V_319 ,
V_5 -> V_316 -> V_320 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_64 ,
V_5 -> V_64 , V_114 ) ;
goto V_310;
}
V_114 = F_98 ( V_82 -> V_2 , V_5 -> V_64 , V_5 -> V_150 , 0 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_65 ) ;
goto V_310;
}
if ( V_82 -> V_2 -> V_130 . V_131 == V_132 ) {
V_114 = F_153 ( V_82 -> V_2 , V_5 -> V_64 , V_321 , 1 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_66 ,
V_114 ) ;
goto V_310;
}
}
F_48 ( V_124 , V_5 , L_67 ) ;
V_114 = F_154 ( V_82 -> V_2 , V_5 -> V_64 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_68 ) ;
goto V_310;
}
memset ( & V_180 [ 10 ] , 0xff , V_78 ) ;
V_180 [ 5 ] = V_5 -> V_64 ;
if ( F_108 ( V_82 -> V_2 , & V_5 -> V_72 . V_205 , V_180 ,
V_5 -> V_64 , 0 , V_144 ,
& V_5 -> V_322 ) )
F_155 ( V_82 , L_69 ) ;
V_5 -> V_167 &= ~ ( V_193 | V_195 ) ;
F_37 ( V_82 -> V_115 , & V_5 -> V_192 ) ;
F_156 ( V_82 -> V_2 , & V_5 -> V_323 ) ;
#ifdef F_157
if ( V_5 -> V_82 -> V_2 -> V_130 . V_131 == V_132 )
F_158 ( V_2 ) ;
#endif
V_5 -> V_19 = true ;
F_159 ( V_2 ) ;
F_160 ( V_2 ) ;
return 0 ;
V_310:
while ( V_290 -- ) {
F_161 ( V_5 , V_5 -> V_219 [ V_290 ] ) ;
F_146 ( V_5 , V_5 -> V_246 [ V_290 ] ) ;
}
F_162 ( V_5 ) ;
V_309:
F_163 ( V_5 ) ;
V_308:
F_74 ( V_5 ) ;
V_298:
while ( V_289 -- ) {
F_146 ( V_5 , V_5 -> V_217 [ V_289 ] ) ;
F_138 ( V_5 , V_6 ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ )
F_164 ( V_5 , V_5 -> V_16 [ V_6 ] ) ;
return V_114 ;
}
void F_165 ( struct V_1 * V_2 , int V_324 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_176 * V_197 , * V_116 ;
struct V_294 * V_325 , * V_326 ;
int V_6 ;
T_1 V_180 [ 16 ] = { 0 } ;
if ( ! V_5 -> V_19 ) {
F_48 ( V_136 , V_5 , L_70 ) ;
return;
}
F_166 ( V_82 -> V_2 , V_5 -> V_64 ) ;
F_167 ( V_2 ) ;
if ( V_324 )
F_168 ( V_2 ) ;
F_169 ( V_2 ) ;
F_170 ( V_2 ) ;
F_171 ( V_2 ) ;
V_5 -> V_19 = false ;
if ( V_82 -> V_2 -> V_130 . V_139 ==
V_145 ) {
V_5 -> V_167 &= ~ ( V_193 |
V_195 ) ;
F_101 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_194 ) ;
F_101 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_200 ) ;
} else if ( V_5 -> V_167 & V_193 ) {
V_5 -> V_167 &= ~ V_193 ;
F_102 ( V_82 -> V_2 , V_5 -> V_150 ,
V_5 -> V_64 ) ;
if ( V_5 -> V_167 & V_195 ) {
F_103 ( V_82 -> V_2 , V_5 -> V_150 ,
V_5 -> V_64 ) ;
V_5 -> V_167 &= ~ V_195 ;
}
}
memset ( & V_180 [ 10 ] , 0xff , V_78 ) ;
V_180 [ 5 ] = V_5 -> V_64 ;
F_107 ( V_82 -> V_2 , & V_5 -> V_72 . V_205 , V_180 ,
V_144 , V_5 -> V_322 ) ;
F_89 (mclist, &priv->curr_list, list) {
memcpy ( & V_180 [ 10 ] , V_197 -> V_129 , V_78 ) ;
V_180 [ 5 ] = V_5 -> V_64 ;
F_107 ( V_82 -> V_2 , & V_5 -> V_72 . V_205 ,
V_180 , V_144 , V_197 -> V_81 ) ;
if ( V_197 -> V_155 )
F_17 ( V_82 -> V_2 , V_197 -> V_155 ) ;
}
F_85 ( V_2 ) ;
F_41 (mclist, tmp, &priv->curr_list, list) {
F_28 ( & V_197 -> V_57 ) ;
F_29 ( V_197 ) ;
}
F_99 ( V_82 -> V_2 , V_5 -> V_64 , 0 , 1 , V_202 ) ;
if ( V_82 -> V_2 -> V_130 . V_139 ==
V_145 ) {
F_172 () ;
F_41 (flow, tmp_flow,
&priv->ethtool_list, list) {
F_17 ( V_82 -> V_2 , V_325 -> V_37 ) ;
F_28 ( & V_325 -> V_57 ) ;
}
}
F_162 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
F_161 ( V_5 , V_5 -> V_219 [ V_6 ] ) ;
F_146 ( V_5 , V_5 -> V_246 [ V_6 ] ) ;
}
F_173 ( 10 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ )
F_174 ( V_2 , V_5 -> V_219 [ V_6 ] ) ;
F_163 ( V_5 ) ;
F_74 ( V_5 ) ;
if ( ! ( V_82 -> V_2 -> V_130 . V_279 & V_327 ) )
V_82 -> V_276 [ V_5 -> V_64 ] = 1 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
struct V_13 * V_14 = V_5 -> V_217 [ V_6 ] ;
F_175 () ;
while ( ! F_176 ( V_14 ) ) {
F_177 ( L_71 , V_6 ) ;
F_178 ( 1 ) ;
}
F_179 () ;
F_180 ( & V_14 -> V_12 ) ;
F_164 ( V_5 , V_5 -> V_16 [ V_6 ] ) ;
F_146 ( V_5 , V_14 ) ;
F_138 ( V_5 , V_6 ) ;
}
}
static void F_181 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_225 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_48 ( V_136 , V_5 , L_72 , V_5 -> V_64 ) ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_5 -> V_19 ) {
F_165 ( V_2 , 1 ) ;
if ( F_139 ( V_2 ) )
F_18 ( V_5 , L_73 , V_5 -> V_64 ) ;
}
F_53 ( & V_82 -> V_126 ) ;
}
static void F_182 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_6 ;
if ( F_127 ( V_82 , V_5 -> V_64 , 1 ) )
F_48 ( V_124 , V_5 , L_74 ) ;
memset ( & V_5 -> V_229 , 0 , sizeof( V_5 -> V_229 ) ) ;
memset ( & V_5 -> V_328 , 0 , sizeof( V_5 -> V_328 ) ) ;
memset ( & V_5 -> V_329 , 0 , sizeof( V_5 -> V_329 ) ) ;
memset ( & V_5 -> V_223 , 0 , sizeof( V_5 -> V_223 ) ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
V_5 -> V_219 [ V_6 ] -> V_269 = 0 ;
V_5 -> V_219 [ V_6 ] -> V_262 = 0 ;
V_5 -> V_219 [ V_6 ] -> V_330 = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
V_5 -> V_16 [ V_6 ] -> V_269 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_262 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_331 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_332 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_333 = 0 ;
}
}
static int F_183 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_114 = 0 ;
F_50 ( & V_82 -> V_126 ) ;
if ( ! V_82 -> V_127 ) {
F_18 ( V_5 , L_75 ) ;
V_114 = - V_334 ;
goto V_112;
}
F_182 ( V_2 ) ;
V_114 = F_139 ( V_2 ) ;
if ( V_114 )
F_18 ( V_5 , L_76 , V_5 -> V_64 ) ;
V_112:
F_53 ( & V_82 -> V_126 ) ;
return V_114 ;
}
static int F_184 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
F_48 ( V_335 , V_5 , L_77 ) ;
F_50 ( & V_82 -> V_126 ) ;
F_165 ( V_2 , 0 ) ;
F_133 ( V_2 ) ;
F_53 ( & V_82 -> V_126 ) ;
return 0 ;
}
void F_185 ( struct V_4 * V_5 )
{
int V_6 ;
#ifdef F_186
F_187 ( V_5 -> V_2 -> V_336 ) ;
V_5 -> V_2 -> V_336 = NULL ;
#endif
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
if ( V_5 -> V_219 && V_5 -> V_219 [ V_6 ] )
F_188 ( V_5 , & V_5 -> V_219 [ V_6 ] ) ;
if ( V_5 -> V_246 && V_5 -> V_246 [ V_6 ] )
F_189 ( V_5 , & V_5 -> V_246 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
if ( V_5 -> V_16 [ V_6 ] )
F_190 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_5 -> V_316 -> V_337 , V_5 -> V_338 ) ;
if ( V_5 -> V_217 [ V_6 ] )
F_189 ( V_5 , & V_5 -> V_217 [ V_6 ] ) ;
}
if ( V_5 -> V_339 ) {
F_72 ( V_5 -> V_82 -> V_2 , V_5 -> V_339 , V_5 -> V_218 ) ;
V_5 -> V_339 = 0 ;
}
}
int F_191 ( struct V_4 * V_5 )
{
struct V_340 * V_316 = V_5 -> V_316 ;
int V_6 ;
int V_341 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
V_341 = F_192 ( V_6 % F_193 () ) ;
if ( F_194 ( V_5 , & V_5 -> V_246 [ V_6 ] ,
V_316 -> V_342 , V_6 , V_343 , V_341 ) )
goto V_114;
if ( F_195 ( V_5 , & V_5 -> V_219 [ V_6 ] ,
V_316 -> V_342 , V_344 ,
V_341 , V_6 ) )
goto V_114;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
V_341 = F_192 ( V_6 % F_193 () ) ;
if ( F_194 ( V_5 , & V_5 -> V_217 [ V_6 ] ,
V_316 -> V_337 , V_6 , V_345 , V_341 ) )
goto V_114;
if ( F_196 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_316 -> V_337 , V_5 -> V_338 ,
V_341 ) )
goto V_114;
}
#ifdef F_186
if ( V_5 -> V_82 -> V_2 -> V_130 . V_346 ) {
V_5 -> V_2 -> V_336 = F_197 ( V_5 -> V_82 -> V_2 -> V_130 . V_346 ) ;
if ( ! V_5 -> V_2 -> V_336 )
goto V_114;
}
#endif
return 0 ;
V_114:
F_18 ( V_5 , L_78 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
if ( V_5 -> V_16 [ V_6 ] )
F_190 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_316 -> V_337 ,
V_5 -> V_338 ) ;
if ( V_5 -> V_217 [ V_6 ] )
F_189 ( V_5 , & V_5 -> V_217 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
if ( V_5 -> V_219 [ V_6 ] )
F_188 ( V_5 , & V_5 -> V_219 [ V_6 ] ) ;
if ( V_5 -> V_246 [ V_6 ] )
F_189 ( V_5 , & V_5 -> V_246 [ V_6 ] ) ;
}
return - V_113 ;
}
void F_198 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
F_48 ( V_136 , V_5 , L_79 , V_5 -> V_64 ) ;
if ( V_5 -> V_347 )
F_199 ( V_2 ) ;
if ( V_5 -> V_348 )
F_200 ( V_82 -> V_2 , & V_5 -> V_349 , V_350 ) ;
F_201 ( & V_5 -> V_274 ) ;
F_201 ( & V_5 -> V_278 ) ;
F_202 ( V_82 -> V_115 ) ;
F_50 ( & V_82 -> V_126 ) ;
V_82 -> V_351 [ V_5 -> V_64 ] = NULL ;
F_53 ( & V_82 -> V_126 ) ;
F_185 ( V_5 ) ;
F_29 ( V_5 -> V_219 ) ;
F_29 ( V_5 -> V_246 ) ;
F_203 ( V_2 ) ;
}
static int F_204 ( struct V_1 * V_2 , int V_352 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_114 = 0 ;
F_48 ( V_136 , V_5 , L_80 ,
V_2 -> V_239 , V_352 ) ;
if ( ( V_352 < V_353 ) || ( V_352 > V_5 -> V_296 ) ) {
F_18 ( V_5 , L_81 , V_352 ) ;
return - V_354 ;
}
V_2 -> V_239 = V_352 ;
if ( F_205 ( V_2 ) ) {
F_50 ( & V_82 -> V_126 ) ;
if ( ! V_82 -> V_127 ) {
F_48 ( V_136 , V_5 , L_82 ) ;
} else {
F_165 ( V_2 , 1 ) ;
V_114 = F_139 ( V_2 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_83 ,
V_5 -> V_64 ) ;
F_37 ( V_82 -> V_115 , & V_5 -> V_225 ) ;
}
}
F_53 ( & V_82 -> V_126 ) ;
}
return 0 ;
}
static int F_206 ( struct V_1 * V_2 , struct V_355 * V_356 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_357 V_358 ;
if ( F_207 ( & V_358 , V_356 -> V_359 , sizeof( V_358 ) ) )
return - V_360 ;
if ( V_358 . V_167 )
return - V_9 ;
if ( ! ( V_82 -> V_2 -> V_130 . V_279 & V_280 ) )
return - V_9 ;
switch ( V_358 . V_361 ) {
case V_362 :
case V_363 :
break;
default:
return - V_364 ;
}
switch ( V_358 . V_365 ) {
case V_366 :
break;
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
case V_380 :
V_358 . V_365 = V_367 ;
break;
default:
return - V_364 ;
}
if ( F_208 ( V_2 , V_358 , V_2 -> V_381 ) ) {
V_358 . V_361 = V_362 ;
V_358 . V_365 = V_366 ;
}
return F_209 ( V_356 -> V_359 , & V_358 ,
sizeof( V_358 ) ) ? - V_360 : 0 ;
}
static int F_210 ( struct V_1 * V_2 , struct V_355 * V_356 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_209 ( V_356 -> V_359 , & V_5 -> V_357 ,
sizeof( V_5 -> V_357 ) ) ? - V_360 : 0 ;
}
static int F_211 ( struct V_1 * V_2 , struct V_355 * V_356 , int V_382 )
{
switch ( V_382 ) {
case V_383 :
return F_206 ( V_2 , V_356 ) ;
case V_384 :
return F_210 ( V_2 , V_356 ) ;
default:
return - V_385 ;
}
}
static int F_212 ( struct V_1 * V_386 ,
T_6 V_381 )
{
struct V_4 * V_5 = F_2 ( V_386 ) ;
int V_96 = 0 ;
if ( F_213 ( V_386 , V_381 , V_387 ) ) {
F_132 ( V_5 , L_84 ,
( V_381 & V_387 ) ? L_85 : L_86 ) ;
V_96 = F_208 ( V_386 , V_5 -> V_357 ,
V_381 ) ;
if ( V_96 )
return V_96 ;
}
if ( V_381 & V_388 )
V_5 -> V_389 |= F_214 ( V_390 ) ;
else
V_5 -> V_389 &=
F_214 ( ~ V_390 ) ;
F_215 ( V_386 , V_381 ) ;
return 0 ;
}
static int F_216 ( struct V_1 * V_2 , int V_391 , T_1 * V_137 )
{
struct V_4 * V_392 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_392 -> V_82 ;
T_5 V_393 = F_66 ( V_137 ) ;
if ( ! F_84 ( V_137 ) )
return - V_9 ;
return F_217 ( V_82 -> V_2 , V_392 -> V_64 , V_391 , V_393 ) ;
}
static int F_218 ( struct V_1 * V_2 , int V_394 , T_4 V_395 , T_1 V_396 )
{
struct V_4 * V_392 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_392 -> V_82 ;
return F_219 ( V_82 -> V_2 , V_392 -> V_64 , V_394 , V_395 , V_396 ) ;
}
static int F_220 ( struct V_1 * V_2 , int V_394 , bool V_397 )
{
struct V_4 * V_392 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_392 -> V_82 ;
return F_221 ( V_82 -> V_2 , V_392 -> V_64 , V_394 , V_397 ) ;
}
static int F_222 ( struct V_1 * V_2 , int V_394 , struct V_398 * V_399 )
{
struct V_4 * V_392 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_392 -> V_82 ;
return F_223 ( V_82 -> V_2 , V_392 -> V_64 , V_394 , V_399 ) ;
}
static int F_224 ( struct V_1 * V_2 , int V_394 , int V_209 )
{
struct V_4 * V_392 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_392 -> V_82 ;
return F_225 ( V_82 -> V_2 , V_392 -> V_64 , V_394 , V_209 ) ;
}
static int F_226 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_138 * V_82 = V_5 -> V_82 -> V_2 ;
int V_6 ;
T_5 V_402 = V_82 -> V_130 . V_402 [ V_5 -> V_64 ] ;
if ( ! V_402 )
return - V_385 ;
V_401 -> V_403 = sizeof( V_402 ) ;
for ( V_6 = V_404 - 1 ; V_6 >= 0 ; -- V_6 ) {
V_401 -> V_37 [ V_6 ] = V_402 & 0xff ;
V_402 >>= 8 ;
}
return 0 ;
}
static void F_227 ( struct V_31 * V_32 )
{
int V_96 ;
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_405 ) ;
V_96 = F_228 ( V_5 -> V_82 -> V_2 , V_5 -> V_406 ) ;
if ( V_96 )
goto V_112;
V_96 = F_153 ( V_5 -> V_82 -> V_2 , V_5 -> V_64 ,
V_321 , 1 ) ;
V_112:
if ( V_96 ) {
F_18 ( V_5 , L_87 , V_96 ) ;
return;
}
V_5 -> V_2 -> V_407 |= V_408 | V_409 |
V_410 | V_411 ;
V_5 -> V_2 -> V_412 |= V_411 ;
V_5 -> V_2 -> V_381 |= V_411 ;
}
static void F_229 ( struct V_31 * V_32 )
{
int V_96 ;
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_413 ) ;
V_5 -> V_2 -> V_407 &= ~ ( V_408 | V_409 |
V_410 | V_411 ) ;
V_5 -> V_2 -> V_412 &= ~ V_411 ;
V_5 -> V_2 -> V_381 &= ~ V_411 ;
V_96 = F_153 ( V_5 -> V_82 -> V_2 , V_5 -> V_64 ,
V_321 , 0 ) ;
if ( V_96 )
F_18 ( V_5 , L_87 , V_96 ) ;
V_5 -> V_406 = 0 ;
}
static void F_230 ( struct V_1 * V_2 ,
T_7 V_414 , V_42 V_64 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_42 V_415 ;
if ( V_5 -> V_82 -> V_2 -> V_130 . V_131 != V_132 )
return;
if ( V_414 == V_416 )
return;
V_415 = V_5 -> V_406 ;
if ( V_415 && V_415 != V_64 ) {
F_15 ( V_5 , L_88 ,
F_231 ( V_415 ) , F_231 ( V_64 ) ) ;
return;
}
V_5 -> V_406 = V_64 ;
F_37 ( V_5 -> V_82 -> V_115 , & V_5 -> V_405 ) ;
}
static void F_232 ( struct V_1 * V_2 ,
T_7 V_414 , V_42 V_64 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_42 V_415 ;
if ( V_5 -> V_82 -> V_2 -> V_130 . V_131 != V_132 )
return;
if ( V_414 == V_416 )
return;
V_415 = V_5 -> V_406 ;
if ( V_415 != V_64 ) {
F_48 ( V_136 , V_5 , L_89 , F_231 ( V_64 ) ) ;
return;
}
F_37 ( V_5 -> V_82 -> V_115 , & V_5 -> V_413 ) ;
}
static T_6 F_233 ( struct V_98 * V_99 ,
struct V_1 * V_2 ,
T_6 V_381 )
{
return F_234 ( V_99 , V_381 ) ;
}
int F_235 ( struct V_122 * V_82 , int V_64 ,
struct V_340 * V_316 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_6 ;
int V_114 ;
T_5 V_393 ;
V_2 = F_236 ( sizeof( struct V_4 ) ,
V_417 , V_418 ) ;
if ( V_2 == NULL )
return - V_113 ;
F_237 ( V_2 , V_316 -> V_218 ) ;
F_238 ( V_2 , V_316 -> V_216 ) ;
F_239 ( V_2 , & V_82 -> V_2 -> V_419 -> V_2 ) ;
V_2 -> V_420 = V_64 - 1 ;
V_5 = F_2 ( V_2 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
F_240 ( & V_5 -> V_227 ) ;
F_25 ( & V_5 -> V_192 , F_111 ) ;
F_25 ( & V_5 -> V_225 , F_181 ) ;
F_25 ( & V_5 -> V_282 , F_131 ) ;
F_241 ( & V_5 -> V_274 , F_125 ) ;
F_241 ( & V_5 -> V_278 , F_129 ) ;
#ifdef F_157
F_25 ( & V_5 -> V_405 , F_227 ) ;
F_25 ( & V_5 -> V_413 , F_229 ) ;
#endif
#ifdef F_186
F_62 ( & V_5 -> V_94 ) ;
F_240 ( & V_5 -> V_111 ) ;
#endif
V_5 -> V_2 = V_2 ;
V_5 -> V_82 = V_82 ;
V_5 -> V_421 = & V_82 -> V_419 -> V_2 ;
V_5 -> V_316 = V_316 ;
V_5 -> V_64 = V_64 ;
V_5 -> V_19 = false ;
V_5 -> V_167 = V_316 -> V_167 ;
V_5 -> V_422 = V_423 ;
V_5 -> V_389 = F_214 ( V_424 |
V_425 ) ;
V_5 -> V_10 = V_82 -> V_426 . V_10 ;
V_5 -> V_218 = V_316 -> V_218 ;
V_5 -> V_427 = V_428 ;
F_242 ( V_5 -> V_429 , sizeof( V_5 -> V_429 ) ) ;
V_5 -> V_219 = F_24 ( sizeof( struct V_288 * ) * V_417 ,
V_157 ) ;
if ( ! V_5 -> V_219 ) {
V_114 = - V_113 ;
goto V_112;
}
V_5 -> V_246 = F_24 ( sizeof( struct V_13 * ) * V_417 ,
V_157 ) ;
if ( ! V_5 -> V_246 ) {
V_114 = - V_113 ;
goto V_112;
}
V_5 -> V_216 = V_316 -> V_216 ;
V_5 -> V_304 = ( V_82 -> V_2 -> V_130 . V_303 == 64 ) ? 1 : 0 ;
V_5 -> V_303 = V_82 -> V_2 -> V_130 . V_303 ;
V_5 -> V_430 = - 1 ;
V_5 -> V_431 = V_432 ;
#ifdef F_243
if ( ! F_244 ( V_5 -> V_82 -> V_2 ) ) {
if ( V_82 -> V_2 -> V_130 . V_167 & V_433 ) {
V_2 -> V_434 = & V_435 ;
} else {
F_132 ( V_5 , L_90 ) ;
V_2 -> V_434 = & V_436 ;
}
}
#endif
for ( V_6 = 0 ; V_6 < V_165 ; ++ V_6 )
F_245 ( & V_5 -> V_161 [ V_6 ] ) ;
V_5 -> V_296 = V_82 -> V_2 -> V_130 . V_437 [ V_5 -> V_64 ] ;
if ( V_82 -> V_2 -> V_130 . V_438 [ V_5 -> V_64 ] &
V_439 )
V_5 -> V_167 |= V_440 ;
V_2 -> V_441 = V_78 ;
F_57 ( V_2 -> V_77 , V_82 -> V_2 -> V_130 . V_442 [ V_5 -> V_64 ] ) ;
if ( ! F_84 ( V_2 -> V_77 ) ) {
if ( F_244 ( V_5 -> V_82 -> V_2 ) ) {
F_246 ( V_2 ) ;
F_15 ( V_5 , L_91 , V_2 -> V_77 ) ;
V_393 = F_66 ( V_2 -> V_77 ) ;
V_82 -> V_2 -> V_130 . V_442 [ V_5 -> V_64 ] = V_393 ;
} else {
F_18 ( V_5 , L_92 ,
V_5 -> V_64 , V_2 -> V_77 ) ;
V_114 = - V_9 ;
goto V_112;
}
}
memcpy ( V_5 -> V_159 , V_2 -> V_77 , sizeof( V_5 -> V_159 ) ) ;
V_5 -> V_338 = F_247 ( sizeof( struct V_443 ) +
V_444 * V_445 ) ;
V_114 = F_191 ( V_5 ) ;
if ( V_114 )
goto V_112;
V_5 -> V_357 . V_167 = 0 ;
V_5 -> V_357 . V_361 = V_362 ;
V_5 -> V_357 . V_365 = V_366 ;
V_114 = F_248 ( V_82 -> V_2 , & V_5 -> V_349 ,
V_350 , V_350 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_93 ) ;
goto V_112;
}
V_5 -> V_348 = 1 ;
if ( F_249 ( V_5 -> V_82 -> V_2 ) )
V_2 -> V_446 = & V_447 ;
else
V_2 -> V_446 = & V_448 ;
V_2 -> V_449 = V_450 ;
F_237 ( V_2 , V_5 -> V_218 ) ;
F_238 ( V_2 , V_5 -> V_216 ) ;
V_2 -> V_451 = & V_452 ;
V_2 -> V_412 = V_453 | V_408 | V_454 ;
if ( V_82 -> V_455 )
V_2 -> V_412 |= V_410 | V_456 ;
V_2 -> V_457 = V_2 -> V_412 ;
V_2 -> V_412 |= V_409 | V_458 ;
V_2 -> V_381 = V_2 -> V_412 | V_459 |
V_460 | V_387 |
V_461 ;
V_2 -> V_412 |= V_388 |
V_460 | V_387 ;
if ( V_82 -> V_2 -> V_130 . V_139 ==
V_145 &&
V_82 -> V_2 -> V_130 . V_133 != V_134 )
V_2 -> V_412 |= V_462 ;
if ( V_82 -> V_2 -> V_130 . V_139 != V_151 )
V_2 -> V_213 |= V_214 ;
if ( V_82 -> V_2 -> V_130 . V_279 & V_463 ) {
V_5 -> V_464 = V_465 ;
} else if ( V_82 -> V_2 -> V_130 . V_279 & V_466 ) {
V_5 -> V_464 = V_467 ;
} else {
F_15 ( V_5 ,
L_94 ) ;
V_5 -> V_464 = V_465 ;
}
V_82 -> V_351 [ V_64 ] = V_2 ;
F_133 ( V_2 ) ;
F_122 ( V_5 ) ;
V_114 = F_250 ( V_2 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_95 , V_64 ) ;
goto V_112;
}
V_5 -> V_347 = 1 ;
F_15 ( V_5 , L_96 , V_316 -> V_218 ) ;
F_15 ( V_5 , L_97 , V_316 -> V_216 ) ;
F_215 ( V_5 -> V_2 , V_5 -> V_2 -> V_381 ) ;
F_141 ( V_2 ) ;
V_114 = F_152 ( V_82 -> V_2 , V_5 -> V_64 ,
V_5 -> V_297 + V_315 ,
V_316 -> V_317 , V_316 -> V_318 ,
V_316 -> V_319 , V_316 -> V_320 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_64 ,
V_5 -> V_64 , V_114 ) ;
goto V_112;
}
if ( V_82 -> V_2 -> V_130 . V_131 == V_132 ) {
V_114 = F_153 ( V_82 -> V_2 , V_5 -> V_64 , V_321 , 1 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_66 ,
V_114 ) ;
goto V_112;
}
}
F_15 ( V_5 , L_67 ) ;
V_114 = F_154 ( V_82 -> V_2 , V_5 -> V_64 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_68 ) ;
goto V_112;
}
F_128 ( V_82 -> V_115 , & V_5 -> V_274 , V_275 ) ;
if ( V_82 -> V_2 -> V_130 . V_279 & V_280 )
F_128 ( V_82 -> V_115 , & V_5 -> V_278 ,
V_281 ) ;
return 0 ;
V_112:
F_198 ( V_2 ) ;
return V_114 ;
}
int F_208 ( struct V_1 * V_2 ,
struct V_357 V_468 ,
T_6 V_381 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_19 = 0 ;
int V_114 = 0 ;
if ( V_5 -> V_357 . V_361 == V_468 . V_361 &&
V_5 -> V_357 . V_365 == V_468 . V_365 &&
! F_213 ( V_2 , V_381 , V_387 ) )
return 0 ;
if ( F_213 ( V_2 , V_381 , V_387 ) &&
( V_381 & V_387 ) &&
( V_5 -> V_357 . V_365 != V_366 ) ) {
F_15 ( V_5 , L_98 ) ;
return - V_9 ;
}
F_50 ( & V_82 -> V_126 ) ;
if ( V_5 -> V_19 ) {
V_19 = 1 ;
F_165 ( V_2 , 1 ) ;
}
F_185 ( V_5 ) ;
F_15 ( V_5 , L_99 ,
V_468 . V_365 , ! ! ( V_381 & V_387 ) ) ;
V_5 -> V_357 . V_361 = V_468 . V_361 ;
V_5 -> V_357 . V_365 = V_468 . V_365 ;
if ( F_213 ( V_2 , V_381 , V_387 ) ) {
if ( V_381 & V_387 )
V_2 -> V_381 |= V_387 ;
else
V_2 -> V_381 &= ~ V_387 ;
} else if ( V_468 . V_365 == V_366 ) {
if ( V_2 -> V_469 & V_387 )
V_2 -> V_381 |= V_387 ;
else
V_2 -> V_381 &= ~ V_387 ;
}
if ( V_468 . V_365 != V_366 ) {
if ( V_2 -> V_381 & V_387 )
F_15 ( V_5 , L_100 ) ;
V_2 -> V_381 &= ~ V_387 ;
}
V_114 = F_191 ( V_5 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_101 ) ;
goto V_112;
}
if ( V_19 ) {
V_114 = F_139 ( V_2 ) ;
if ( V_114 )
F_18 ( V_5 , L_102 ) ;
}
V_112:
F_53 ( & V_82 -> V_126 ) ;
F_251 ( V_2 ) ;
return V_114 ;
}
