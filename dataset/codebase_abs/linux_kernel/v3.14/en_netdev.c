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
static int F_58 ( struct V_4 * V_5 , unsigned char * V_128 ,
int V_71 , T_5 * V_81 )
{
int V_113 ;
struct V_35 V_129 = { { NULL } } ;
struct V_35 V_130 = { { NULL } } ;
struct V_35 V_131 = { { NULL } } ;
struct V_55 V_56 = {
. V_58 = V_132 ,
. V_60 = 0 ,
. V_61 = 1 ,
. V_62 = V_63 ,
. V_65 = V_133 ,
} ;
T_2 V_68 = F_14 ( V_69 << 16 ) ;
if ( V_5 -> V_82 -> V_2 -> V_134 . V_135 != V_136 )
return 0 ;
V_56 . V_64 = V_5 -> V_64 ;
V_56 . V_71 = V_71 ;
F_59 ( & V_56 . V_57 ) ;
V_129 . V_37 = V_54 ;
memcpy ( V_129 . V_75 . V_76 , V_128 , V_78 ) ;
memcpy ( V_129 . V_75 . V_79 , & V_68 , V_78 ) ;
V_130 . V_37 = V_137 ;
V_131 . V_37 = V_54 ;
F_16 ( & V_129 . V_57 , & V_56 . V_57 ) ;
F_16 ( & V_130 . V_57 , & V_56 . V_57 ) ;
F_16 ( & V_131 . V_57 , & V_56 . V_57 ) ;
V_113 = F_19 ( V_5 -> V_82 -> V_2 , & V_56 , V_81 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_8 , V_113 ) ;
return V_113 ;
}
F_48 ( V_138 , V_5 , L_9 , V_128 , * V_81 ) ;
return 0 ;
}
static int F_60 ( struct V_4 * V_5 ,
unsigned char * V_139 , int * V_71 , T_5 * V_81 )
{
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_140 * V_2 = V_82 -> V_2 ;
int V_113 ;
switch ( V_2 -> V_134 . V_141 ) {
case V_142 : {
struct V_143 V_144 ;
T_1 V_145 [ 16 ] = { 0 } ;
V_144 . V_71 = * V_71 ;
memcpy ( & V_145 [ 10 ] , V_139 , V_78 ) ;
V_145 [ 5 ] = V_5 -> V_64 ;
V_113 = F_61 ( V_2 , & V_144 , V_145 , 0 , V_146 ) ;
break;
}
case V_147 : {
struct V_35 V_53 = { { NULL } } ;
T_2 V_68 = F_14 ( V_69 << 16 ) ;
struct V_55 V_56 = {
. V_58 = V_132 ,
. V_60 = 0 ,
. V_61 = 1 ,
. V_62 = V_63 ,
. V_65 = V_133 ,
} ;
V_56 . V_64 = V_5 -> V_64 ;
V_56 . V_71 = * V_71 ;
F_59 ( & V_56 . V_57 ) ;
V_53 . V_37 = V_54 ;
memcpy ( V_53 . V_75 . V_76 , V_139 , V_78 ) ;
memcpy ( V_53 . V_75 . V_79 , & V_68 , V_78 ) ;
F_16 ( & V_53 . V_57 , & V_56 . V_57 ) ;
V_113 = F_19 ( V_2 , & V_56 , V_81 ) ;
break;
}
default:
return - V_9 ;
}
if ( V_113 )
F_15 ( V_5 , L_10 ) ;
return V_113 ;
}
static void F_62 ( struct V_4 * V_5 ,
unsigned char * V_139 , int V_71 , T_5 V_81 )
{
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_140 * V_2 = V_82 -> V_2 ;
switch ( V_2 -> V_134 . V_141 ) {
case V_142 : {
struct V_143 V_144 ;
T_1 V_145 [ 16 ] = { 0 } ;
V_144 . V_71 = V_71 ;
memcpy ( & V_145 [ 10 ] , V_139 , V_78 ) ;
V_145 [ 5 ] = V_5 -> V_64 ;
F_63 ( V_2 , & V_144 , V_145 , V_146 ) ;
break;
}
case V_147 : {
F_17 ( V_2 , V_81 ) ;
break;
}
default:
F_18 ( V_5 , L_11 ) ;
}
}
static int F_64 ( struct V_4 * V_5 )
{
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_140 * V_2 = V_82 -> V_2 ;
struct V_148 * V_149 ;
int V_150 = 0 ;
int V_113 = 0 ;
T_5 V_81 ;
int * V_71 = & V_5 -> V_151 ;
T_5 V_139 = F_65 ( V_5 -> V_2 -> V_77 ) ;
F_48 ( V_138 , V_5 , L_12 ,
V_5 -> V_2 -> V_77 ) ;
V_150 = F_66 ( V_2 , V_5 -> V_64 , V_139 ) ;
if ( V_150 < 0 ) {
V_113 = V_150 ;
F_18 ( V_5 , L_13 ,
V_5 -> V_2 -> V_77 ) ;
return V_113 ;
}
if ( V_2 -> V_134 . V_141 == V_152 ) {
int V_151 = F_67 ( V_2 , V_5 -> V_64 ) ;
* V_71 = V_151 + V_150 ;
return 0 ;
}
V_113 = F_68 ( V_2 , 1 , 1 , V_71 ) ;
F_48 ( V_138 , V_5 , L_14 , * V_71 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_15 ) ;
goto V_153;
}
V_113 = F_60 ( V_5 , V_5 -> V_2 -> V_77 , V_71 , & V_81 ) ;
if ( V_113 )
goto V_154;
V_113 = F_58 ( V_5 , V_5 -> V_2 -> V_77 , * V_71 ,
& V_5 -> V_155 ) ;
if ( V_113 )
goto V_156;
V_149 = F_69 ( sizeof( * V_149 ) , V_157 ) ;
if ( ! V_149 ) {
V_113 = - V_112 ;
goto V_158;
}
memcpy ( V_149 -> V_139 , V_5 -> V_2 -> V_77 , sizeof( V_149 -> V_139 ) ) ;
V_149 -> V_81 = V_81 ;
F_70 ( & V_149 -> V_159 ,
& V_5 -> V_160 [ V_149 -> V_139 [ V_161 ] ] ) ;
return 0 ;
V_158:
if ( V_5 -> V_155 )
F_17 ( V_5 -> V_82 -> V_2 , V_5 -> V_155 ) ;
V_156:
F_62 ( V_5 , V_5 -> V_2 -> V_77 , * V_71 , V_81 ) ;
V_154:
F_71 ( V_2 , * V_71 , 1 ) ;
V_153:
F_72 ( V_2 , V_5 -> V_64 , V_139 ) ;
return V_113 ;
}
static void F_73 ( struct V_4 * V_5 )
{
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_140 * V_2 = V_82 -> V_2 ;
int V_71 = V_5 -> V_151 ;
T_5 V_139 ;
if ( V_2 -> V_134 . V_141 == V_152 ) {
V_139 = F_65 ( V_5 -> V_2 -> V_77 ) ;
F_48 ( V_138 , V_5 , L_16 ,
V_5 -> V_2 -> V_77 ) ;
F_72 ( V_2 , V_5 -> V_64 , V_139 ) ;
} else {
struct V_148 * V_149 ;
struct V_162 * V_115 ;
struct V_84 * V_163 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_164 ; ++ V_6 ) {
V_163 = & V_5 -> V_160 [ V_6 ] ;
F_74 (entry, tmp, bucket, hlist) {
V_139 = F_65 ( V_149 -> V_139 ) ;
F_48 ( V_138 , V_5 , L_16 ,
V_149 -> V_139 ) ;
F_62 ( V_5 , V_149 -> V_139 ,
V_71 , V_149 -> V_81 ) ;
F_72 ( V_2 , V_5 -> V_64 , V_139 ) ;
F_75 ( & V_149 -> V_159 ) ;
F_76 ( V_149 , V_165 ) ;
}
}
if ( V_5 -> V_155 ) {
F_17 ( V_5 -> V_82 -> V_2 , V_5 -> V_155 ) ;
V_5 -> V_155 = 0 ;
}
F_48 ( V_138 , V_5 , L_17 ,
V_5 -> V_64 , V_71 ) ;
F_71 ( V_2 , V_71 , 1 ) ;
V_5 -> V_166 &= ~ V_167 ;
}
}
static int F_77 ( struct V_4 * V_5 , int V_71 ,
unsigned char * V_168 , unsigned char * V_169 )
{
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_140 * V_2 = V_82 -> V_2 ;
int V_113 = 0 ;
T_5 V_170 = F_65 ( V_168 ) ;
if ( V_2 -> V_134 . V_141 != V_152 ) {
struct V_84 * V_163 ;
unsigned int V_160 ;
struct V_148 * V_149 ;
struct V_162 * V_115 ;
T_5 V_171 = F_65 ( V_169 ) ;
V_163 = & V_5 -> V_160 [ V_169 [ V_161 ] ] ;
F_74 (entry, tmp, bucket, hlist) {
if ( F_78 ( V_149 -> V_139 , V_169 ) ) {
F_62 ( V_5 , V_149 -> V_139 ,
V_71 , V_149 -> V_81 ) ;
F_72 ( V_2 , V_5 -> V_64 ,
V_171 ) ;
F_75 ( & V_149 -> V_159 ) ;
F_79 () ;
memcpy ( V_149 -> V_139 , V_168 , V_78 ) ;
V_149 -> V_81 = 0 ;
V_160 = V_168 [ V_161 ] ;
F_70 ( & V_149 -> V_159 ,
& V_5 -> V_160 [ V_160 ] ) ;
F_66 ( V_2 , V_5 -> V_64 , V_170 ) ;
V_113 = F_60 ( V_5 , V_168 ,
& V_71 ,
& V_149 -> V_81 ) ;
if ( V_113 )
return V_113 ;
if ( V_5 -> V_155 ) {
F_17 ( V_5 -> V_82 -> V_2 , V_5 -> V_155 ) ;
V_5 -> V_155 = 0 ;
}
V_113 = F_58 ( V_5 , V_168 , V_71 ,
& V_5 -> V_155 ) ;
return V_113 ;
}
}
return - V_9 ;
}
return F_80 ( V_2 , V_5 -> V_64 , V_71 , V_170 ) ;
}
T_5 F_65 ( T_1 * V_128 )
{
T_5 V_139 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_78 ; V_6 ++ ) {
V_139 <<= 8 ;
V_139 |= V_128 [ V_6 ] ;
}
return V_139 ;
}
static int F_81 ( struct V_4 * V_5 )
{
int V_113 = 0 ;
if ( V_5 -> V_19 ) {
V_113 = F_77 ( V_5 , V_5 -> V_151 ,
V_5 -> V_2 -> V_77 , V_5 -> V_169 ) ;
if ( V_113 )
F_18 ( V_5 , L_18 ) ;
memcpy ( V_5 -> V_169 , V_5 -> V_2 -> V_77 ,
sizeof( V_5 -> V_169 ) ) ;
} else
F_48 ( V_123 , V_5 , L_19 ) ;
return V_113 ;
}
static int F_82 ( struct V_1 * V_2 , void * V_128 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_172 * V_108 = V_128 ;
int V_113 ;
if ( ! F_83 ( V_108 -> V_173 ) )
return - V_174 ;
memcpy ( V_2 -> V_77 , V_108 -> V_173 , V_78 ) ;
F_50 ( & V_82 -> V_125 ) ;
V_113 = F_81 ( V_5 ) ;
F_53 ( & V_82 -> V_125 ) ;
return V_113 ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_175 * V_115 , * V_176 ;
F_41 (mc_to_del, tmp, &priv->mc_list, list) {
F_28 ( & V_176 -> V_57 ) ;
F_29 ( V_176 ) ;
}
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_177 * V_178 ;
struct V_175 * V_115 ;
F_84 ( V_2 ) ;
F_86 (ha, dev) {
V_115 = F_24 ( sizeof( struct V_175 ) , V_90 ) ;
if ( ! V_115 ) {
F_84 ( V_2 ) ;
return;
}
memcpy ( V_115 -> V_128 , V_178 -> V_128 , V_78 ) ;
F_16 ( & V_115 -> V_57 , & V_5 -> V_179 ) ;
}
}
static void F_87 ( struct V_4 * V_5 ,
struct V_180 * V_181 ,
struct V_180 * V_182 )
{
struct V_175 * V_183 , * V_184 , * V_185 ;
bool V_186 ;
F_88 (dst_tmp, dst, list) {
V_186 = false ;
F_88 (src_tmp, src, list) {
if ( F_89 ( V_183 -> V_128 , V_184 -> V_128 ) ) {
V_186 = true ;
break;
}
}
if ( ! V_186 )
V_183 -> V_187 = V_188 ;
}
F_88 (src_tmp, src, list) {
V_186 = false ;
F_88 (dst_tmp, dst, list) {
if ( F_89 ( V_183 -> V_128 , V_184 -> V_128 ) ) {
V_183 -> V_187 = V_189 ;
V_186 = true ;
break;
}
}
if ( ! V_186 ) {
V_185 = F_90 ( V_184 ,
sizeof( struct V_175 ) ,
V_157 ) ;
if ( ! V_185 )
return;
V_185 -> V_187 = V_190 ;
F_16 ( & V_185 -> V_57 , V_181 ) ;
}
}
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_19 )
return;
F_37 ( V_5 -> V_82 -> V_114 , & V_5 -> V_191 ) ;
}
static void F_92 ( struct V_4 * V_5 ,
struct V_121 * V_82 )
{
int V_113 = 0 ;
if ( ! ( V_5 -> V_166 & V_192 ) ) {
if ( F_93 ( V_5 ) )
F_15 ( V_5 , L_20 ) ;
V_5 -> V_166 |= V_192 ;
switch ( V_82 -> V_2 -> V_134 . V_141 ) {
case V_147 :
V_113 = F_94 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_151 ,
V_193 ) ;
if ( V_113 )
F_18 ( V_5 , L_21 ) ;
V_5 -> V_166 |= V_194 ;
break;
case V_142 :
V_113 = F_95 ( V_82 -> V_2 ,
V_5 -> V_151 ,
V_5 -> V_64 ) ;
if ( V_113 )
F_18 ( V_5 , L_22 ) ;
if ( ! ( V_5 -> V_166 & V_194 ) ) {
V_113 = F_96 ( V_82 -> V_2 ,
V_5 -> V_151 ,
V_5 -> V_64 ) ;
if ( V_113 )
F_18 ( V_5 , L_23 ) ;
V_5 -> V_166 |= V_194 ;
}
break;
case V_152 :
V_113 = F_97 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_151 ,
1 ) ;
if ( V_113 )
F_18 ( V_5 , L_21 ) ;
break;
}
V_113 = F_98 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_195 ) ;
if ( V_113 )
F_18 ( V_5 , L_24 ) ;
V_113 = F_51 ( V_82 -> V_2 , V_5 ) ;
if ( V_113 )
F_18 ( V_5 , L_25 ) ;
}
}
static void F_99 ( struct V_4 * V_5 ,
struct V_121 * V_82 )
{
int V_113 = 0 ;
if ( F_93 ( V_5 ) )
F_15 ( V_5 , L_26 ) ;
V_5 -> V_166 &= ~ V_192 ;
switch ( V_82 -> V_2 -> V_134 . V_141 ) {
case V_147 :
V_113 = F_100 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_193 ) ;
if ( V_113 )
F_18 ( V_5 , L_27 ) ;
V_5 -> V_166 &= ~ V_194 ;
break;
case V_142 :
V_113 = F_101 ( V_82 -> V_2 ,
V_5 -> V_151 ,
V_5 -> V_64 ) ;
if ( V_113 )
F_18 ( V_5 , L_28 ) ;
if ( V_5 -> V_166 & V_194 ) {
V_113 = F_102 ( V_82 -> V_2 ,
V_5 -> V_151 ,
V_5 -> V_64 ) ;
if ( V_113 )
F_18 ( V_5 , L_29 ) ;
V_5 -> V_166 &= ~ V_194 ;
}
break;
case V_152 :
V_113 = F_97 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_151 , 0 ) ;
if ( V_113 )
F_18 ( V_5 , L_27 ) ;
break;
}
V_113 = F_51 ( V_82 -> V_2 , V_5 ) ;
if ( V_113 )
F_18 ( V_5 , L_30 ) ;
}
static void F_103 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_121 * V_82 )
{
struct V_175 * V_196 , * V_115 ;
T_5 V_197 = 0 ;
T_1 V_179 [ 16 ] = { 0 } ;
int V_113 = 0 ;
if ( V_2 -> V_166 & V_198 ) {
V_113 = F_98 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_195 ) ;
if ( V_113 )
F_18 ( V_5 , L_24 ) ;
if ( ! ( V_5 -> V_166 & V_194 ) ) {
switch ( V_82 -> V_2 -> V_134 . V_141 ) {
case V_147 :
V_113 = F_94 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_151 ,
V_199 ) ;
break;
case V_142 :
V_113 = F_96 ( V_82 -> V_2 ,
V_5 -> V_151 ,
V_5 -> V_64 ) ;
break;
case V_152 :
break;
}
if ( V_113 )
F_18 ( V_5 , L_31 ) ;
V_5 -> V_166 |= V_194 ;
}
} else {
if ( V_5 -> V_166 & V_194 ) {
switch ( V_82 -> V_2 -> V_134 . V_141 ) {
case V_147 :
V_113 = F_100 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_199 ) ;
break;
case V_142 :
V_113 = F_102 ( V_82 -> V_2 ,
V_5 -> V_151 ,
V_5 -> V_64 ) ;
break;
case V_152 :
break;
}
if ( V_113 )
F_18 ( V_5 , L_29 ) ;
V_5 -> V_166 &= ~ V_194 ;
}
V_113 = F_98 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_195 ) ;
if ( V_113 )
F_18 ( V_5 , L_24 ) ;
F_98 ( V_82 -> V_2 , V_5 -> V_64 , V_200 ,
1 , V_201 ) ;
F_104 ( V_2 ) ;
F_85 ( V_2 ) ;
F_105 ( V_2 ) ;
F_88 (mclist, &priv->mc_list, list) {
V_197 = F_65 ( V_196 -> V_128 ) ;
F_98 ( V_82 -> V_2 , V_5 -> V_64 ,
V_197 , 0 , V_201 ) ;
}
V_113 = F_98 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_202 ) ;
if ( V_113 )
F_18 ( V_5 , L_32 ) ;
F_87 ( V_5 , & V_5 -> V_203 , & V_5 -> V_179 ) ;
F_41 (mclist, tmp, &priv->curr_list, list) {
if ( V_196 -> V_187 == V_188 ) {
memcpy ( & V_179 [ 10 ] , V_196 -> V_128 , V_78 ) ;
V_179 [ 5 ] = V_5 -> V_64 ;
V_113 = F_106 ( V_82 -> V_2 ,
& V_5 -> V_72 . V_204 ,
V_179 ,
V_146 ,
V_196 -> V_81 ) ;
if ( V_113 )
F_18 ( V_5 , L_33 ) ;
if ( V_196 -> V_155 ) {
V_113 = F_17 ( V_5 -> V_82 -> V_2 , V_196 -> V_155 ) ;
if ( V_113 )
F_18 ( V_5 , L_34 ) ;
}
F_28 ( & V_196 -> V_57 ) ;
F_29 ( V_196 ) ;
} else if ( V_196 -> V_187 == V_190 ) {
memcpy ( & V_179 [ 10 ] , V_196 -> V_128 , V_78 ) ;
V_179 [ 5 ] = V_5 -> V_64 ;
V_113 = F_107 ( V_82 -> V_2 ,
& V_5 -> V_72 . V_204 ,
V_179 ,
V_5 -> V_64 , 0 ,
V_146 ,
& V_196 -> V_81 ) ;
if ( V_113 )
F_18 ( V_5 , L_35 ) ;
V_113 = F_58 ( V_5 , & V_179 [ 10 ] , V_5 -> V_151 ,
& V_196 -> V_155 ) ;
if ( V_113 )
F_18 ( V_5 , L_36 ) ;
}
}
}
}
static void F_108 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_121 * V_82 )
{
struct V_177 * V_178 ;
struct V_148 * V_149 ;
struct V_162 * V_115 ;
bool V_186 ;
T_5 V_139 ;
int V_113 = 0 ;
struct V_84 * V_163 ;
unsigned int V_6 ;
int V_205 = 0 ;
T_3 V_206 ;
for ( V_6 = 0 ; V_6 < V_164 ; ++ V_6 ) {
V_163 = & V_5 -> V_160 [ V_6 ] ;
F_74 (entry, tmp, bucket, hlist) {
V_186 = false ;
F_109 (ha, dev) {
if ( F_78 ( V_149 -> V_139 ,
V_178 -> V_128 ) ) {
V_186 = true ;
break;
}
}
if ( F_78 ( V_149 -> V_139 , V_2 -> V_77 ) )
V_186 = true ;
if ( ! V_186 ) {
V_139 = F_65 ( V_149 -> V_139 ) ;
F_62 ( V_5 , V_149 -> V_139 ,
V_5 -> V_151 ,
V_149 -> V_81 ) ;
F_72 ( V_82 -> V_2 , V_5 -> V_64 , V_139 ) ;
F_75 ( & V_149 -> V_159 ) ;
F_76 ( V_149 , V_165 ) ;
F_48 ( V_138 , V_5 , L_37 ,
V_149 -> V_139 , V_5 -> V_64 ) ;
++ V_205 ;
}
}
}
if ( ( V_5 -> V_166 & V_167 ) && 0 == V_205 )
return;
V_206 = V_5 -> V_166 ;
V_5 -> V_166 &= ~ V_167 ;
F_109 (ha, dev) {
V_186 = false ;
V_163 = & V_5 -> V_160 [ V_178 -> V_128 [ V_161 ] ] ;
F_31 (entry, bucket, hlist) {
if ( F_78 ( V_149 -> V_139 , V_178 -> V_128 ) ) {
V_186 = true ;
break;
}
}
if ( ! V_186 ) {
V_149 = F_69 ( sizeof( * V_149 ) , V_157 ) ;
if ( ! V_149 ) {
F_18 ( V_5 , L_38 ,
V_178 -> V_128 , V_5 -> V_64 ) ;
V_5 -> V_166 |= V_167 ;
break;
}
V_139 = F_65 ( V_178 -> V_128 ) ;
memcpy ( V_149 -> V_139 , V_178 -> V_128 , V_78 ) ;
V_113 = F_66 ( V_82 -> V_2 , V_5 -> V_64 , V_139 ) ;
if ( V_113 < 0 ) {
F_18 ( V_5 , L_39 ,
V_178 -> V_128 , V_5 -> V_64 , V_113 ) ;
F_29 ( V_149 ) ;
V_5 -> V_166 |= V_167 ;
break;
}
V_113 = F_60 ( V_5 , V_178 -> V_128 ,
& V_5 -> V_151 ,
& V_149 -> V_81 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_40 ,
V_178 -> V_128 , V_5 -> V_64 , V_113 ) ;
F_72 ( V_82 -> V_2 , V_5 -> V_64 , V_139 ) ;
F_29 ( V_149 ) ;
V_5 -> V_166 |= V_167 ;
break;
} else {
unsigned int V_160 ;
F_48 ( V_138 , V_5 , L_41 ,
V_178 -> V_128 , V_5 -> V_64 ) ;
V_160 = V_178 -> V_128 [ V_161 ] ;
V_163 = & V_5 -> V_160 [ V_160 ] ;
F_70 ( & V_149 -> V_159 , V_163 ) ;
}
}
}
if ( V_5 -> V_166 & V_167 ) {
F_15 ( V_5 , L_42 ,
V_5 -> V_64 ) ;
} else if ( V_206 & V_167 ) {
F_15 ( V_5 , L_43 ,
V_5 -> V_64 ) ;
}
}
static void F_110 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_191 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_50 ( & V_82 -> V_125 ) ;
if ( ! V_82 -> V_126 ) {
F_48 ( V_123 , V_5 , L_44 ) ;
goto V_111;
}
if ( ! V_5 -> V_19 ) {
F_48 ( V_123 , V_5 , L_45 ) ;
goto V_111;
}
if ( ! F_111 ( V_2 ) ) {
if ( ! F_112 ( V_82 , V_5 -> V_64 ) ) {
if ( V_5 -> V_207 . V_208 ) {
V_5 -> V_209 = V_210 ;
F_113 ( V_2 ) ;
F_48 ( V_211 , V_5 , L_46 ) ;
}
}
}
if ( V_2 -> V_212 & V_213 )
F_108 ( V_5 , V_2 , V_82 ) ;
if ( ( V_2 -> V_166 & V_214 ) ||
( V_5 -> V_166 & V_167 ) ) {
F_92 ( V_5 , V_82 ) ;
goto V_111;
}
if ( V_5 -> V_166 & V_192 )
F_99 ( V_5 , V_82 ) ;
F_103 ( V_5 , V_2 , V_82 ) ;
V_111:
F_53 ( & V_82 -> V_125 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_13 * V_14 ;
unsigned long V_166 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
V_14 = V_5 -> V_216 [ V_6 ] ;
F_115 ( & V_14 -> V_217 , V_166 ) ;
F_116 ( & V_14 -> V_12 ) ;
F_8 ( V_2 , V_14 , 0 ) ;
F_117 ( & V_14 -> V_217 , V_166 ) ;
}
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
int V_6 ;
if ( F_119 ( V_5 ) )
F_15 ( V_5 , L_47 , V_5 -> V_64 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
if ( ! F_120 ( F_121 ( V_2 , V_6 ) ) )
continue;
F_15 ( V_5 , L_48 ,
V_6 , V_5 -> V_219 [ V_6 ] -> V_71 , V_5 -> V_219 [ V_6 ] -> V_220 ,
V_5 -> V_219 [ V_6 ] -> V_221 , V_5 -> V_219 [ V_6 ] -> V_222 ) ;
}
V_5 -> V_223 . V_224 ++ ;
F_48 ( V_138 , V_5 , L_49 ) ;
F_37 ( V_82 -> V_114 , & V_5 -> V_225 ) ;
}
static struct V_226 * F_122 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_36 ( & V_5 -> V_227 ) ;
memcpy ( & V_5 -> V_228 , & V_5 -> V_229 , sizeof( V_5 -> V_229 ) ) ;
F_38 ( & V_5 -> V_227 ) ;
return & V_5 -> V_228 ;
}
static void F_123 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
int V_6 ;
V_5 -> V_230 = V_231 ;
V_5 -> V_232 = V_233 ;
V_5 -> V_234 = V_235 ;
V_5 -> V_236 = V_237 ;
F_48 ( V_238 , V_5 , L_50 ,
V_5 -> V_2 -> V_239 , V_5 -> V_230 , V_5 -> V_232 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
V_14 = V_5 -> V_216 [ V_6 ] ;
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
static void F_124 ( struct V_4 * V_5 )
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
int V_17 , V_113 ;
if ( ! V_5 -> V_257 || V_260 < V_5 -> V_255 * V_268 )
return;
for ( V_17 = 0 ; V_17 < V_5 -> V_215 ; V_17 ++ ) {
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
if ( V_263 > ( V_270 / V_5 -> V_215 ) &&
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
V_14 = V_5 -> V_216 [ V_17 ] ;
V_14 -> V_241 = V_241 ;
V_14 -> V_240 = V_5 -> V_230 ;
V_113 = F_125 ( V_5 , V_14 ) ;
if ( V_113 )
F_18 ( V_5 , L_51 ,
V_17 ) ;
}
V_5 -> V_244 [ V_17 ] = V_265 ;
V_5 -> V_245 [ V_17 ] = V_266 ;
}
V_5 -> V_258 = V_261 ;
}
static void F_126 ( struct V_31 * V_32 )
{
struct V_272 * V_273 = F_127 ( V_32 ) ;
struct V_4 * V_5 = F_6 ( V_273 , struct V_4 ,
V_274 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
int V_113 ;
F_50 ( & V_82 -> V_125 ) ;
if ( V_82 -> V_126 ) {
if ( V_5 -> V_19 ) {
V_113 = F_128 ( V_82 , V_5 -> V_64 , 0 ) ;
if ( V_113 )
F_48 ( V_123 , V_5 , L_52 ) ;
F_124 ( V_5 ) ;
}
F_129 ( V_82 -> V_114 , & V_5 -> V_274 , V_275 ) ;
}
if ( V_82 -> V_276 [ V_277 + 1 - V_5 -> V_64 ] ) {
F_81 ( V_5 ) ;
V_82 -> V_276 [ V_277 + 1 - V_5 -> V_64 ] = 0 ;
}
F_53 ( & V_82 -> V_125 ) ;
}
static void F_130 ( struct V_31 * V_32 )
{
struct V_272 * V_273 = F_127 ( V_32 ) ;
struct V_4 * V_5 = F_6 ( V_273 , struct V_4 ,
V_278 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
F_50 ( & V_82 -> V_125 ) ;
if ( V_82 -> V_126 ) {
if ( V_82 -> V_2 -> V_134 . V_279 & V_280 )
F_131 ( V_82 ) ;
F_129 ( V_82 -> V_114 , & V_5 -> V_278 ,
V_281 ) ;
}
F_53 ( & V_82 -> V_125 ) ;
}
static void F_132 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_282 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
int V_283 = V_5 -> V_208 ;
F_50 ( & V_82 -> V_125 ) ;
if ( V_5 -> V_209 != V_283 ) {
if ( V_283 == V_284 ) {
F_133 ( V_5 , L_53 ) ;
F_134 ( V_5 -> V_2 ) ;
} else {
F_133 ( V_5 , L_46 ) ;
F_113 ( V_5 -> V_2 ) ;
}
}
V_5 -> V_209 = V_283 ;
F_53 ( & V_82 -> V_125 ) ;
}
int F_135 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_13 * V_14 ;
struct V_285 * V_219 ;
int V_286 = 0 ;
int V_287 = 0 ;
int V_113 = 0 ;
int V_6 ;
int V_288 ;
T_1 V_179 [ 16 ] = { 0 } ;
if ( V_5 -> V_19 ) {
F_48 ( V_138 , V_5 , L_54 ) ;
return 0 ;
}
F_59 ( & V_5 -> V_179 ) ;
F_59 ( & V_5 -> V_203 ) ;
F_59 ( & V_5 -> V_289 ) ;
memset ( & V_5 -> V_290 [ 0 ] , 0 ,
sizeof( struct V_291 ) * V_292 ) ;
V_2 -> V_239 = F_136 ( V_2 -> V_239 , V_5 -> V_293 ) ;
F_137 ( V_2 ) ;
F_48 ( V_138 , V_5 , L_55 , V_5 -> V_294 ) ;
V_113 = F_138 ( V_5 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_56 ) ;
return V_113 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
V_14 = V_5 -> V_216 [ V_6 ] ;
F_139 ( V_14 ) ;
V_113 = F_140 ( V_5 , V_14 , V_6 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_57 ) ;
goto V_295;
}
for ( V_288 = 0 ; V_288 < V_14 -> V_296 ; V_288 ++ )
V_14 -> V_297 [ V_288 ] . V_298 = V_299 ;
V_113 = F_125 ( V_5 , V_14 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_58 ) ;
F_141 ( V_5 , V_14 ) ;
goto V_295;
}
F_142 ( V_5 , V_14 ) ;
V_5 -> V_16 [ V_6 ] -> V_220 = V_14 -> V_300 . V_220 ;
++ V_286 ;
}
F_48 ( V_138 , V_5 , L_59 , V_5 -> V_64 ) ;
V_113 = F_64 ( V_5 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_60 ) ;
goto V_295;
}
V_82 -> V_276 [ V_5 -> V_64 ] = 0 ;
V_113 = F_143 ( V_5 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_61 ) ;
goto V_301;
}
V_113 = F_144 ( V_5 ) ;
if ( V_113 )
goto V_302;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
V_14 = V_5 -> V_246 [ V_6 ] ;
V_113 = F_140 ( V_5 , V_14 , V_6 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_62 ) ;
goto V_303;
}
V_113 = F_125 ( V_5 , V_14 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_58 ) ;
F_141 ( V_5 , V_14 ) ;
goto V_303;
}
F_48 ( V_138 , V_5 , L_63 , V_6 ) ;
V_14 -> V_297 -> V_304 = F_145 ( 0xffff ) ;
V_219 = V_5 -> V_219 [ V_6 ] ;
V_113 = F_146 ( V_5 , V_219 , V_14 -> V_300 . V_220 ,
V_6 / V_5 -> V_10 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_64 ) ;
F_141 ( V_5 , V_14 ) ;
goto V_303;
}
V_219 -> V_305 = F_121 ( V_2 , V_6 ) ;
F_142 ( V_5 , V_14 ) ;
for ( V_288 = 0 ; V_288 < V_219 -> V_306 ; V_288 += V_307 )
* ( ( T_3 * ) ( V_219 -> V_297 + V_288 ) ) = 0xffffffff ;
++ V_287 ;
}
V_113 = F_147 ( V_82 -> V_2 , V_5 -> V_64 ,
V_5 -> V_294 + V_308 ,
V_5 -> V_309 -> V_310 ,
V_5 -> V_309 -> V_311 ,
V_5 -> V_309 -> V_312 ,
V_5 -> V_309 -> V_313 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_65 ,
V_5 -> V_64 , V_113 ) ;
goto V_303;
}
V_113 = F_97 ( V_82 -> V_2 , V_5 -> V_64 , V_5 -> V_151 , 0 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_66 ) ;
goto V_303;
}
if ( V_82 -> V_2 -> V_134 . V_135 == V_136 ) {
V_113 = F_148 ( V_82 -> V_2 , V_5 -> V_64 , V_314 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_67 ,
V_113 ) ;
goto V_303;
}
}
F_48 ( V_123 , V_5 , L_68 ) ;
V_113 = F_149 ( V_82 -> V_2 , V_5 -> V_64 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_69 ) ;
goto V_303;
}
memset ( & V_179 [ 10 ] , 0xff , V_78 ) ;
V_179 [ 5 ] = V_5 -> V_64 ;
if ( F_107 ( V_82 -> V_2 , & V_5 -> V_72 . V_204 , V_179 ,
V_5 -> V_64 , 0 , V_146 ,
& V_5 -> V_315 ) )
F_150 ( V_82 , L_70 ) ;
V_5 -> V_166 &= ~ ( V_192 | V_194 ) ;
F_37 ( V_82 -> V_114 , & V_5 -> V_191 ) ;
F_151 ( V_82 -> V_2 , & V_5 -> V_316 ) ;
V_5 -> V_19 = true ;
F_152 ( V_2 ) ;
F_153 ( V_2 ) ;
return 0 ;
V_303:
while ( V_287 -- ) {
F_154 ( V_5 , V_5 -> V_219 [ V_287 ] ) ;
F_141 ( V_5 , V_5 -> V_246 [ V_287 ] ) ;
}
F_155 ( V_5 ) ;
V_302:
F_156 ( V_5 ) ;
V_301:
F_73 ( V_5 ) ;
V_295:
while ( V_286 -- )
F_141 ( V_5 , V_5 -> V_216 [ V_286 ] ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ )
F_157 ( V_5 , V_5 -> V_16 [ V_6 ] ) ;
return V_113 ;
}
void F_158 ( struct V_1 * V_2 , int V_317 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_175 * V_196 , * V_115 ;
struct V_291 * V_318 , * V_319 ;
int V_6 ;
T_1 V_179 [ 16 ] = { 0 } ;
if ( ! V_5 -> V_19 ) {
F_48 ( V_138 , V_5 , L_71 ) ;
return;
}
F_159 ( V_82 -> V_2 , V_5 -> V_64 ) ;
F_160 ( V_2 ) ;
if ( V_317 )
F_161 ( V_2 ) ;
F_162 ( V_2 ) ;
F_163 ( V_2 ) ;
F_164 ( V_2 ) ;
V_5 -> V_19 = false ;
if ( V_82 -> V_2 -> V_134 . V_141 ==
V_147 ) {
V_5 -> V_166 &= ~ ( V_192 |
V_194 ) ;
F_100 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_193 ) ;
F_100 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_199 ) ;
} else if ( V_5 -> V_166 & V_192 ) {
V_5 -> V_166 &= ~ V_192 ;
F_101 ( V_82 -> V_2 , V_5 -> V_151 ,
V_5 -> V_64 ) ;
if ( V_5 -> V_166 & V_194 ) {
F_102 ( V_82 -> V_2 , V_5 -> V_151 ,
V_5 -> V_64 ) ;
V_5 -> V_166 &= ~ V_194 ;
}
}
memset ( & V_179 [ 10 ] , 0xff , V_78 ) ;
V_179 [ 5 ] = V_5 -> V_64 ;
F_106 ( V_82 -> V_2 , & V_5 -> V_72 . V_204 , V_179 ,
V_146 , V_5 -> V_315 ) ;
F_88 (mclist, &priv->curr_list, list) {
memcpy ( & V_179 [ 10 ] , V_196 -> V_128 , V_78 ) ;
V_179 [ 5 ] = V_5 -> V_64 ;
F_106 ( V_82 -> V_2 , & V_5 -> V_72 . V_204 ,
V_179 , V_146 , V_196 -> V_81 ) ;
if ( V_196 -> V_155 )
F_17 ( V_82 -> V_2 , V_196 -> V_155 ) ;
}
F_84 ( V_2 ) ;
F_41 (mclist, tmp, &priv->curr_list, list) {
F_28 ( & V_196 -> V_57 ) ;
F_29 ( V_196 ) ;
}
F_98 ( V_82 -> V_2 , V_5 -> V_64 , 0 , 1 , V_201 ) ;
if ( V_82 -> V_2 -> V_134 . V_141 ==
V_147 ) {
F_165 () ;
F_41 (flow, tmp_flow,
&priv->ethtool_list, list) {
F_17 ( V_82 -> V_2 , V_318 -> V_37 ) ;
F_28 ( & V_318 -> V_57 ) ;
}
}
F_155 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
F_154 ( V_5 , V_5 -> V_219 [ V_6 ] ) ;
F_141 ( V_5 , V_5 -> V_246 [ V_6 ] ) ;
}
F_166 ( 10 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ )
F_167 ( V_2 , V_5 -> V_219 [ V_6 ] ) ;
F_156 ( V_5 ) ;
F_73 ( V_5 ) ;
if ( ! ( V_82 -> V_2 -> V_134 . V_279 & V_320 ) )
V_82 -> V_276 [ V_5 -> V_64 ] = 1 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
struct V_13 * V_14 = V_5 -> V_216 [ V_6 ] ;
F_168 () ;
while ( ! F_169 ( V_14 ) ) {
F_170 ( L_72 , V_6 ) ;
F_171 ( 1 ) ;
}
F_172 () ;
while ( F_173 ( V_321 , & V_14 -> V_12 . V_322 ) )
F_166 ( 1 ) ;
F_157 ( V_5 , V_5 -> V_16 [ V_6 ] ) ;
F_141 ( V_5 , V_14 ) ;
}
}
static void F_174 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_225 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_48 ( V_138 , V_5 , L_73 , V_5 -> V_64 ) ;
F_50 ( & V_82 -> V_125 ) ;
if ( V_5 -> V_19 ) {
F_158 ( V_2 , 1 ) ;
if ( F_135 ( V_2 ) )
F_18 ( V_5 , L_74 , V_5 -> V_64 ) ;
}
F_53 ( & V_82 -> V_125 ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
int V_6 ;
if ( F_128 ( V_82 , V_5 -> V_64 , 1 ) )
F_48 ( V_123 , V_5 , L_75 ) ;
memset ( & V_5 -> V_229 , 0 , sizeof( V_5 -> V_229 ) ) ;
memset ( & V_5 -> V_323 , 0 , sizeof( V_5 -> V_323 ) ) ;
memset ( & V_5 -> V_324 , 0 , sizeof( V_5 -> V_324 ) ) ;
memset ( & V_5 -> V_223 , 0 , sizeof( V_5 -> V_223 ) ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
V_5 -> V_219 [ V_6 ] -> V_269 = 0 ;
V_5 -> V_219 [ V_6 ] -> V_262 = 0 ;
V_5 -> V_219 [ V_6 ] -> V_325 = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
V_5 -> V_16 [ V_6 ] -> V_269 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_262 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_326 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_327 = 0 ;
}
}
static int F_176 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
int V_113 = 0 ;
F_50 ( & V_82 -> V_125 ) ;
if ( ! V_82 -> V_126 ) {
F_18 ( V_5 , L_76 ) ;
V_113 = - V_328 ;
goto V_111;
}
F_175 ( V_2 ) ;
V_113 = F_135 ( V_2 ) ;
if ( V_113 )
F_18 ( V_5 , L_77 , V_5 -> V_64 ) ;
V_111:
F_53 ( & V_82 -> V_125 ) ;
return V_113 ;
}
static int F_177 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
F_48 ( V_329 , V_5 , L_78 ) ;
F_50 ( & V_82 -> V_125 ) ;
F_158 ( V_2 , 0 ) ;
F_134 ( V_2 ) ;
F_53 ( & V_82 -> V_125 ) ;
return 0 ;
}
void F_178 ( struct V_4 * V_5 )
{
int V_6 ;
#ifdef F_179
F_180 ( V_5 -> V_2 -> V_330 ) ;
V_5 -> V_2 -> V_330 = NULL ;
#endif
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
if ( V_5 -> V_219 && V_5 -> V_219 [ V_6 ] )
F_181 ( V_5 , & V_5 -> V_219 [ V_6 ] ) ;
if ( V_5 -> V_246 && V_5 -> V_246 [ V_6 ] )
F_182 ( V_5 , & V_5 -> V_246 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
if ( V_5 -> V_16 [ V_6 ] )
F_183 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_5 -> V_309 -> V_331 , V_5 -> V_332 ) ;
if ( V_5 -> V_216 [ V_6 ] )
F_182 ( V_5 , & V_5 -> V_216 [ V_6 ] ) ;
}
if ( V_5 -> V_333 ) {
F_71 ( V_5 -> V_82 -> V_2 , V_5 -> V_333 , V_5 -> V_218 ) ;
V_5 -> V_333 = 0 ;
}
}
int F_184 ( struct V_4 * V_5 )
{
struct V_334 * V_309 = V_5 -> V_309 ;
int V_6 ;
int V_113 ;
int V_335 ;
V_113 = F_68 ( V_5 -> V_82 -> V_2 , V_5 -> V_218 , 256 , & V_5 -> V_333 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_79 ) ;
return V_113 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
V_335 = F_185 ( V_6 % F_186 () ) ;
if ( F_187 ( V_5 , & V_5 -> V_246 [ V_6 ] ,
V_309 -> V_336 , V_6 , V_337 , V_335 ) )
goto V_113;
if ( F_188 ( V_5 , & V_5 -> V_219 [ V_6 ] ,
V_5 -> V_333 + V_6 ,
V_309 -> V_336 , V_338 ,
V_335 , V_6 ) )
goto V_113;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
V_335 = F_185 ( V_6 % F_186 () ) ;
if ( F_187 ( V_5 , & V_5 -> V_216 [ V_6 ] ,
V_309 -> V_331 , V_6 , V_339 , V_335 ) )
goto V_113;
if ( F_189 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_309 -> V_331 , V_5 -> V_332 ,
V_335 ) )
goto V_113;
}
#ifdef F_179
if ( V_5 -> V_82 -> V_2 -> V_134 . V_340 ) {
V_5 -> V_2 -> V_330 = F_190 ( V_5 -> V_82 -> V_2 -> V_134 . V_340 ) ;
if ( ! V_5 -> V_2 -> V_330 )
goto V_113;
}
#endif
return 0 ;
V_113:
F_18 ( V_5 , L_80 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
if ( V_5 -> V_16 [ V_6 ] )
F_183 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_309 -> V_331 ,
V_5 -> V_332 ) ;
if ( V_5 -> V_216 [ V_6 ] )
F_182 ( V_5 , & V_5 -> V_216 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
if ( V_5 -> V_219 [ V_6 ] )
F_181 ( V_5 , & V_5 -> V_219 [ V_6 ] ) ;
if ( V_5 -> V_246 [ V_6 ] )
F_182 ( V_5 , & V_5 -> V_246 [ V_6 ] ) ;
}
return - V_112 ;
}
void F_191 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
F_48 ( V_138 , V_5 , L_81 , V_5 -> V_64 ) ;
if ( V_5 -> V_341 )
F_192 ( V_2 ) ;
if ( V_5 -> V_342 )
F_193 ( V_82 -> V_2 , & V_5 -> V_343 , V_344 ) ;
F_194 ( & V_5 -> V_274 ) ;
F_194 ( & V_5 -> V_278 ) ;
F_195 ( V_82 -> V_114 ) ;
F_50 ( & V_82 -> V_125 ) ;
V_82 -> V_345 [ V_5 -> V_64 ] = NULL ;
F_53 ( & V_82 -> V_125 ) ;
F_178 ( V_5 ) ;
F_29 ( V_5 -> V_219 ) ;
F_29 ( V_5 -> V_246 ) ;
F_196 ( V_2 ) ;
}
static int F_197 ( struct V_1 * V_2 , int V_346 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
int V_113 = 0 ;
F_48 ( V_138 , V_5 , L_82 ,
V_2 -> V_239 , V_346 ) ;
if ( ( V_346 < V_347 ) || ( V_346 > V_5 -> V_293 ) ) {
F_18 ( V_5 , L_83 , V_346 ) ;
return - V_348 ;
}
V_2 -> V_239 = V_346 ;
if ( F_198 ( V_2 ) ) {
F_50 ( & V_82 -> V_125 ) ;
if ( ! V_82 -> V_126 ) {
F_48 ( V_138 , V_5 , L_84 ) ;
} else {
F_158 ( V_2 , 1 ) ;
V_113 = F_135 ( V_2 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_85 ,
V_5 -> V_64 ) ;
F_37 ( V_82 -> V_114 , & V_5 -> V_225 ) ;
}
}
F_53 ( & V_82 -> V_125 ) ;
}
return 0 ;
}
static int F_199 ( struct V_1 * V_2 , struct V_349 * V_350 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_5 -> V_82 ;
struct V_351 V_352 ;
if ( F_200 ( & V_352 , V_350 -> V_353 , sizeof( V_352 ) ) )
return - V_354 ;
if ( V_352 . V_166 )
return - V_9 ;
if ( ! ( V_82 -> V_2 -> V_134 . V_279 & V_280 ) )
return - V_9 ;
switch ( V_352 . V_355 ) {
case V_356 :
case V_357 :
break;
default:
return - V_358 ;
}
switch ( V_352 . V_359 ) {
case V_360 :
break;
case V_361 :
case V_362 :
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
V_352 . V_359 = V_361 ;
break;
default:
return - V_358 ;
}
if ( F_201 ( V_2 , V_352 . V_355 , V_352 . V_359 ) ) {
V_352 . V_355 = V_356 ;
V_352 . V_359 = V_360 ;
}
return F_202 ( V_350 -> V_353 , & V_352 ,
sizeof( V_352 ) ) ? - V_354 : 0 ;
}
static int F_203 ( struct V_1 * V_2 , struct V_349 * V_350 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_202 ( V_350 -> V_353 , & V_5 -> V_351 ,
sizeof( V_5 -> V_351 ) ) ? - V_354 : 0 ;
}
static int F_204 ( struct V_1 * V_2 , struct V_349 * V_350 , int V_375 )
{
switch ( V_375 ) {
case V_376 :
return F_199 ( V_2 , V_350 ) ;
case V_377 :
return F_203 ( V_2 , V_350 ) ;
default:
return - V_378 ;
}
}
static int F_205 ( struct V_1 * V_379 ,
T_6 V_380 )
{
struct V_4 * V_5 = F_2 ( V_379 ) ;
if ( V_380 & V_381 )
V_5 -> V_382 |= F_206 ( V_383 ) ;
else
V_5 -> V_382 &=
F_206 ( ~ V_383 ) ;
F_207 ( V_379 , V_380 ) ;
return 0 ;
}
static int F_208 ( struct V_1 * V_2 , int V_384 , T_1 * V_139 )
{
struct V_4 * V_385 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_385 -> V_82 ;
T_5 V_386 = F_65 ( V_139 ) ;
if ( ! F_83 ( V_139 ) )
return - V_9 ;
return F_209 ( V_82 -> V_2 , V_385 -> V_64 , V_384 , V_386 ) ;
}
static int F_210 ( struct V_1 * V_2 , int V_387 , T_4 V_388 , T_1 V_389 )
{
struct V_4 * V_385 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_385 -> V_82 ;
return F_211 ( V_82 -> V_2 , V_385 -> V_64 , V_387 , V_388 , V_389 ) ;
}
static int F_212 ( struct V_1 * V_2 , int V_387 , bool V_390 )
{
struct V_4 * V_385 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_385 -> V_82 ;
return F_213 ( V_82 -> V_2 , V_385 -> V_64 , V_387 , V_390 ) ;
}
static int F_214 ( struct V_1 * V_2 , int V_387 , struct V_391 * V_392 )
{
struct V_4 * V_385 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_385 -> V_82 ;
return F_215 ( V_82 -> V_2 , V_385 -> V_64 , V_387 , V_392 ) ;
}
static int F_216 ( struct V_1 * V_2 , int V_387 , int V_208 )
{
struct V_4 * V_385 = F_2 ( V_2 ) ;
struct V_121 * V_82 = V_385 -> V_82 ;
return F_217 ( V_82 -> V_2 , V_385 -> V_64 , V_387 , V_208 ) ;
}
static int F_218 ( struct V_1 * V_2 ,
struct V_393 * V_394 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_140 * V_82 = V_5 -> V_82 -> V_2 ;
int V_6 ;
T_5 V_395 = V_82 -> V_134 . V_395 [ V_5 -> V_64 ] ;
if ( ! V_395 )
return - V_378 ;
V_394 -> V_396 = sizeof( V_395 ) ;
for ( V_6 = V_397 - 1 ; V_6 >= 0 ; -- V_6 ) {
V_394 -> V_37 [ V_6 ] = V_395 & 0xff ;
V_395 >>= 8 ;
}
return 0 ;
}
int F_219 ( struct V_121 * V_82 , int V_64 ,
struct V_334 * V_309 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_6 ;
int V_113 ;
T_5 V_386 ;
V_2 = F_220 ( sizeof( struct V_4 ) ,
V_398 , V_399 ) ;
if ( V_2 == NULL )
return - V_112 ;
F_221 ( V_2 , V_309 -> V_218 ) ;
F_222 ( V_2 , V_309 -> V_215 ) ;
F_223 ( V_2 , & V_82 -> V_2 -> V_400 -> V_2 ) ;
V_2 -> V_401 = V_64 - 1 ;
V_5 = F_2 ( V_2 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_82 = V_82 ;
V_5 -> V_402 = & V_82 -> V_400 -> V_2 ;
V_5 -> V_309 = V_309 ;
V_5 -> V_64 = V_64 ;
V_5 -> V_19 = false ;
V_5 -> V_166 = V_309 -> V_166 ;
V_5 -> V_382 = F_206 ( V_403 |
V_404 ) ;
V_5 -> V_10 = V_82 -> V_405 . V_10 ;
V_5 -> V_218 = V_309 -> V_218 ;
V_5 -> V_219 = F_24 ( sizeof( struct V_285 * ) * V_398 ,
V_157 ) ;
if ( ! V_5 -> V_219 ) {
V_113 = - V_112 ;
goto V_111;
}
V_5 -> V_246 = F_24 ( sizeof( struct V_13 * ) * V_398 ,
V_157 ) ;
if ( ! V_5 -> V_246 ) {
V_113 = - V_112 ;
goto V_111;
}
V_5 -> V_215 = V_309 -> V_215 ;
V_5 -> V_406 = ( V_82 -> V_2 -> V_134 . V_407 == 64 ) ? 1 : 0 ;
V_5 -> V_408 = - 1 ;
V_5 -> V_409 = V_410 ;
F_224 ( & V_5 -> V_227 ) ;
F_25 ( & V_5 -> V_191 , F_110 ) ;
F_25 ( & V_5 -> V_225 , F_174 ) ;
F_25 ( & V_5 -> V_282 , F_132 ) ;
F_225 ( & V_5 -> V_274 , F_126 ) ;
F_225 ( & V_5 -> V_278 , F_130 ) ;
#ifdef F_226
if ( ! F_227 ( V_5 -> V_82 -> V_2 ) ) {
if ( V_82 -> V_2 -> V_134 . V_166 & V_411 ) {
V_2 -> V_412 = & V_413 ;
} else {
F_133 ( V_5 , L_86 ) ;
V_2 -> V_412 = & V_414 ;
}
}
#endif
for ( V_6 = 0 ; V_6 < V_164 ; ++ V_6 )
F_228 ( & V_5 -> V_160 [ V_6 ] ) ;
V_5 -> V_293 = V_82 -> V_2 -> V_134 . V_415 [ V_5 -> V_64 ] ;
V_2 -> V_416 = V_78 ;
F_57 ( V_2 -> V_77 , V_82 -> V_2 -> V_134 . V_417 [ V_5 -> V_64 ] ) ;
if ( ! F_83 ( V_2 -> V_77 ) ) {
if ( F_227 ( V_5 -> V_82 -> V_2 ) ) {
F_229 ( V_2 ) ;
F_15 ( V_5 , L_87 , V_2 -> V_77 ) ;
V_386 = F_65 ( V_2 -> V_77 ) ;
V_82 -> V_2 -> V_134 . V_417 [ V_5 -> V_64 ] = V_386 ;
} else {
F_18 ( V_5 , L_88 ,
V_5 -> V_64 , V_2 -> V_77 ) ;
V_113 = - V_9 ;
goto V_111;
}
}
memcpy ( V_5 -> V_169 , V_2 -> V_77 , sizeof( V_5 -> V_169 ) ) ;
V_5 -> V_332 = F_230 ( sizeof( struct V_418 ) +
V_419 * V_420 ) ;
V_113 = F_184 ( V_5 ) ;
if ( V_113 )
goto V_111;
#ifdef F_179
F_59 ( & V_5 -> V_94 ) ;
F_224 ( & V_5 -> V_110 ) ;
#endif
V_5 -> V_351 . V_166 = 0 ;
V_5 -> V_351 . V_355 = V_356 ;
V_5 -> V_351 . V_359 = V_360 ;
V_113 = F_231 ( V_82 -> V_2 , & V_5 -> V_343 ,
V_344 , V_344 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_89 ) ;
goto V_111;
}
V_5 -> V_342 = 1 ;
if ( F_232 ( V_5 -> V_82 -> V_2 ) )
V_2 -> V_421 = & V_422 ;
else
V_2 -> V_421 = & V_423 ;
V_2 -> V_424 = V_425 ;
F_221 ( V_2 , V_5 -> V_218 ) ;
F_222 ( V_2 , V_5 -> V_215 ) ;
F_233 ( V_2 , & V_426 ) ;
V_2 -> V_427 = V_428 | V_429 | V_430 ;
if ( V_82 -> V_431 )
V_2 -> V_427 |= V_432 | V_433 ;
V_2 -> V_434 = V_2 -> V_427 ;
V_2 -> V_427 |= V_435 | V_436 ;
V_2 -> V_380 = V_2 -> V_427 | V_437 |
V_438 | V_439 |
V_440 ;
V_2 -> V_427 |= V_381 ;
if ( V_82 -> V_2 -> V_134 . V_141 ==
V_147 )
V_2 -> V_427 |= V_441 ;
if ( V_82 -> V_2 -> V_134 . V_141 != V_152 )
V_2 -> V_212 |= V_213 ;
if ( V_82 -> V_2 -> V_134 . V_135 == V_136 ) {
V_2 -> V_442 |= V_429 | V_435 |
V_432 | V_443 ;
V_2 -> V_427 |= V_443 ;
V_2 -> V_380 |= V_443 ;
}
V_82 -> V_345 [ V_64 ] = V_2 ;
F_134 ( V_2 ) ;
F_123 ( V_5 ) ;
V_113 = F_234 ( V_2 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_90 , V_64 ) ;
goto V_111;
}
V_5 -> V_341 = 1 ;
F_15 ( V_5 , L_91 , V_309 -> V_218 ) ;
F_15 ( V_5 , L_92 , V_309 -> V_215 ) ;
F_207 ( V_5 -> V_2 , V_5 -> V_2 -> V_380 ) ;
F_137 ( V_2 ) ;
V_113 = F_147 ( V_82 -> V_2 , V_5 -> V_64 ,
V_5 -> V_294 + V_308 ,
V_309 -> V_310 , V_309 -> V_311 ,
V_309 -> V_312 , V_309 -> V_313 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_93
L_94 , V_5 -> V_64 , V_113 ) ;
goto V_111;
}
if ( V_82 -> V_2 -> V_134 . V_135 == V_136 ) {
V_113 = F_148 ( V_82 -> V_2 , V_5 -> V_64 , V_314 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_67 ,
V_113 ) ;
goto V_111;
}
}
F_15 ( V_5 , L_68 ) ;
V_113 = F_149 ( V_82 -> V_2 , V_5 -> V_64 ) ;
if ( V_113 ) {
F_18 ( V_5 , L_69 ) ;
goto V_111;
}
F_129 ( V_82 -> V_114 , & V_5 -> V_274 , V_275 ) ;
if ( V_82 -> V_2 -> V_134 . V_279 & V_280 )
F_129 ( V_82 -> V_114 , & V_5 -> V_278 ,
V_281 ) ;
return 0 ;
V_111:
F_191 ( V_2 ) ;
return V_113 ;
}
