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
struct V_35 V_130 = { { NULL } } ;
struct V_35 V_131 = { { NULL } } ;
struct V_35 V_132 = { { NULL } } ;
struct V_55 V_56 = {
. V_58 = V_133 ,
. V_60 = 0 ,
. V_61 = 1 ,
. V_62 = V_63 ,
. V_65 = V_134 ,
} ;
T_2 V_68 = F_14 ( V_69 << 16 ) ;
if ( V_5 -> V_82 -> V_2 -> V_135 . V_136 != V_137 )
return 0 ;
V_56 . V_64 = V_5 -> V_64 ;
V_56 . V_71 = V_71 ;
F_59 ( & V_56 . V_57 ) ;
V_130 . V_37 = V_54 ;
memcpy ( V_130 . V_75 . V_76 , V_129 , V_78 ) ;
memcpy ( V_130 . V_75 . V_79 , & V_68 , V_78 ) ;
V_131 . V_37 = V_138 ;
V_132 . V_37 = V_54 ;
F_16 ( & V_130 . V_57 , & V_56 . V_57 ) ;
F_16 ( & V_131 . V_57 , & V_56 . V_57 ) ;
F_16 ( & V_132 . V_57 , & V_56 . V_57 ) ;
V_114 = F_19 ( V_5 -> V_82 -> V_2 , & V_56 , V_81 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_8 , V_114 ) ;
return V_114 ;
}
F_48 ( V_139 , V_5 , L_9 , V_129 , * V_81 ) ;
return 0 ;
}
static int F_60 ( struct V_4 * V_5 ,
unsigned char * V_140 , int * V_71 , T_5 * V_81 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_141 * V_2 = V_82 -> V_2 ;
int V_114 ;
switch ( V_2 -> V_135 . V_142 ) {
case V_143 : {
struct V_144 V_145 ;
T_1 V_146 [ 16 ] = { 0 } ;
V_145 . V_71 = * V_71 ;
memcpy ( & V_146 [ 10 ] , V_140 , V_78 ) ;
V_146 [ 5 ] = V_5 -> V_64 ;
V_114 = F_61 ( V_2 , & V_145 , V_146 , 0 , V_147 ) ;
break;
}
case V_148 : {
struct V_35 V_53 = { { NULL } } ;
T_2 V_68 = F_14 ( V_69 << 16 ) ;
struct V_55 V_56 = {
. V_58 = V_133 ,
. V_60 = 0 ,
. V_61 = 1 ,
. V_62 = V_63 ,
. V_65 = V_134 ,
} ;
V_56 . V_64 = V_5 -> V_64 ;
V_56 . V_71 = * V_71 ;
F_59 ( & V_56 . V_57 ) ;
V_53 . V_37 = V_54 ;
memcpy ( V_53 . V_75 . V_76 , V_140 , V_78 ) ;
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
static void F_62 ( struct V_4 * V_5 ,
unsigned char * V_140 , int V_71 , T_5 V_81 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_141 * V_2 = V_82 -> V_2 ;
switch ( V_2 -> V_135 . V_142 ) {
case V_143 : {
struct V_144 V_145 ;
T_1 V_146 [ 16 ] = { 0 } ;
V_145 . V_71 = V_71 ;
memcpy ( & V_146 [ 10 ] , V_140 , V_78 ) ;
V_146 [ 5 ] = V_5 -> V_64 ;
F_63 ( V_2 , & V_145 , V_146 , V_147 ) ;
break;
}
case V_148 : {
F_17 ( V_2 , V_81 ) ;
break;
}
default:
F_18 ( V_5 , L_11 ) ;
}
}
static int F_64 ( struct V_4 * V_5 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_141 * V_2 = V_82 -> V_2 ;
struct V_149 * V_150 ;
int V_151 = 0 ;
int V_114 = 0 ;
T_5 V_81 ;
int * V_71 = & V_5 -> V_152 ;
T_5 V_140 = F_65 ( V_5 -> V_2 -> V_77 ) ;
F_48 ( V_139 , V_5 , L_12 ,
V_5 -> V_2 -> V_77 ) ;
V_151 = F_66 ( V_2 , V_5 -> V_64 , V_140 ) ;
if ( V_151 < 0 ) {
V_114 = V_151 ;
F_18 ( V_5 , L_13 ,
V_5 -> V_2 -> V_77 ) ;
return V_114 ;
}
if ( V_2 -> V_135 . V_142 == V_153 ) {
int V_152 = F_67 ( V_2 , V_5 -> V_64 ) ;
* V_71 = V_152 + V_151 ;
return 0 ;
}
V_114 = F_68 ( V_2 , 1 , 1 , V_71 ) ;
F_48 ( V_139 , V_5 , L_14 , * V_71 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_15 ) ;
goto V_154;
}
V_114 = F_60 ( V_5 , V_5 -> V_2 -> V_77 , V_71 , & V_81 ) ;
if ( V_114 )
goto V_155;
V_114 = F_58 ( V_5 , V_5 -> V_2 -> V_77 , * V_71 ,
& V_5 -> V_156 ) ;
if ( V_114 )
goto V_157;
V_150 = F_69 ( sizeof( * V_150 ) , V_158 ) ;
if ( ! V_150 ) {
V_114 = - V_113 ;
goto V_159;
}
memcpy ( V_150 -> V_140 , V_5 -> V_2 -> V_77 , sizeof( V_150 -> V_140 ) ) ;
V_150 -> V_81 = V_81 ;
F_70 ( & V_150 -> V_160 ,
& V_5 -> V_161 [ V_150 -> V_140 [ V_162 ] ] ) ;
return 0 ;
V_159:
if ( V_5 -> V_156 )
F_17 ( V_5 -> V_82 -> V_2 , V_5 -> V_156 ) ;
V_157:
F_62 ( V_5 , V_5 -> V_2 -> V_77 , * V_71 , V_81 ) ;
V_155:
F_71 ( V_2 , * V_71 , 1 ) ;
V_154:
F_72 ( V_2 , V_5 -> V_64 , V_140 ) ;
return V_114 ;
}
static void F_73 ( struct V_4 * V_5 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_141 * V_2 = V_82 -> V_2 ;
int V_71 = V_5 -> V_152 ;
T_5 V_140 ;
if ( V_2 -> V_135 . V_142 == V_153 ) {
V_140 = F_65 ( V_5 -> V_2 -> V_77 ) ;
F_48 ( V_139 , V_5 , L_16 ,
V_5 -> V_2 -> V_77 ) ;
F_72 ( V_2 , V_5 -> V_64 , V_140 ) ;
} else {
struct V_149 * V_150 ;
struct V_163 * V_116 ;
struct V_84 * V_164 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_165 ; ++ V_6 ) {
V_164 = & V_5 -> V_161 [ V_6 ] ;
F_74 (entry, tmp, bucket, hlist) {
V_140 = F_65 ( V_150 -> V_140 ) ;
F_48 ( V_139 , V_5 , L_16 ,
V_150 -> V_140 ) ;
F_62 ( V_5 , V_150 -> V_140 ,
V_71 , V_150 -> V_81 ) ;
F_72 ( V_2 , V_5 -> V_64 , V_140 ) ;
F_75 ( & V_150 -> V_160 ) ;
F_76 ( V_150 , V_166 ) ;
}
}
if ( V_5 -> V_156 ) {
F_17 ( V_5 -> V_82 -> V_2 , V_5 -> V_156 ) ;
V_5 -> V_156 = 0 ;
}
F_48 ( V_139 , V_5 , L_17 ,
V_5 -> V_64 , V_71 ) ;
F_71 ( V_2 , V_71 , 1 ) ;
V_5 -> V_167 &= ~ V_168 ;
}
}
static int F_77 ( struct V_4 * V_5 , int V_71 ,
unsigned char * V_169 , unsigned char * V_170 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_141 * V_2 = V_82 -> V_2 ;
int V_114 = 0 ;
T_5 V_171 = F_65 ( V_169 ) ;
if ( V_2 -> V_135 . V_142 != V_153 ) {
struct V_84 * V_164 ;
unsigned int V_161 ;
struct V_149 * V_150 ;
struct V_163 * V_116 ;
T_5 V_172 = F_65 ( V_170 ) ;
V_164 = & V_5 -> V_161 [ V_170 [ V_162 ] ] ;
F_74 (entry, tmp, bucket, hlist) {
if ( F_78 ( V_150 -> V_140 , V_170 ) ) {
F_62 ( V_5 , V_150 -> V_140 ,
V_71 , V_150 -> V_81 ) ;
F_72 ( V_2 , V_5 -> V_64 ,
V_172 ) ;
F_75 ( & V_150 -> V_160 ) ;
F_79 () ;
memcpy ( V_150 -> V_140 , V_169 , V_78 ) ;
V_150 -> V_81 = 0 ;
V_161 = V_169 [ V_162 ] ;
F_70 ( & V_150 -> V_160 ,
& V_5 -> V_161 [ V_161 ] ) ;
F_66 ( V_2 , V_5 -> V_64 , V_171 ) ;
V_114 = F_60 ( V_5 , V_169 ,
& V_71 ,
& V_150 -> V_81 ) ;
if ( V_114 )
return V_114 ;
if ( V_5 -> V_156 ) {
F_17 ( V_5 -> V_82 -> V_2 , V_5 -> V_156 ) ;
V_5 -> V_156 = 0 ;
}
V_114 = F_58 ( V_5 , V_169 , V_71 ,
& V_5 -> V_156 ) ;
return V_114 ;
}
}
return - V_9 ;
}
return F_80 ( V_2 , V_5 -> V_64 , V_71 , V_171 ) ;
}
static int F_81 ( struct V_4 * V_5 )
{
int V_114 = 0 ;
if ( V_5 -> V_19 ) {
V_114 = F_77 ( V_5 , V_5 -> V_152 ,
V_5 -> V_2 -> V_77 , V_5 -> V_170 ) ;
if ( V_114 )
F_18 ( V_5 , L_18 ) ;
} else
F_48 ( V_124 , V_5 , L_19 ) ;
memcpy ( V_5 -> V_170 , V_5 -> V_2 -> V_77 ,
sizeof( V_5 -> V_170 ) ) ;
return V_114 ;
}
static int F_82 ( struct V_1 * V_2 , void * V_129 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_173 * V_109 = V_129 ;
int V_114 ;
if ( ! F_83 ( V_109 -> V_174 ) )
return - V_175 ;
F_50 ( & V_82 -> V_126 ) ;
memcpy ( V_2 -> V_77 , V_109 -> V_174 , V_78 ) ;
V_114 = F_81 ( V_5 ) ;
F_53 ( & V_82 -> V_126 ) ;
return V_114 ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_176 * V_116 , * V_177 ;
F_41 (mc_to_del, tmp, &priv->mc_list, list) {
F_28 ( & V_177 -> V_57 ) ;
F_29 ( V_177 ) ;
}
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_178 * V_179 ;
struct V_176 * V_116 ;
F_84 ( V_2 ) ;
F_86 (ha, dev) {
V_116 = F_24 ( sizeof( struct V_176 ) , V_90 ) ;
if ( ! V_116 ) {
F_84 ( V_2 ) ;
return;
}
memcpy ( V_116 -> V_129 , V_179 -> V_129 , V_78 ) ;
F_16 ( & V_116 -> V_57 , & V_5 -> V_180 ) ;
}
}
static void F_87 ( struct V_4 * V_5 ,
struct V_181 * V_182 ,
struct V_181 * V_183 )
{
struct V_176 * V_184 , * V_185 , * V_186 ;
bool V_187 ;
F_88 (dst_tmp, dst, list) {
V_187 = false ;
F_88 (src_tmp, src, list) {
if ( F_89 ( V_184 -> V_129 , V_185 -> V_129 ) ) {
V_187 = true ;
break;
}
}
if ( ! V_187 )
V_184 -> V_188 = V_189 ;
}
F_88 (src_tmp, src, list) {
V_187 = false ;
F_88 (dst_tmp, dst, list) {
if ( F_89 ( V_184 -> V_129 , V_185 -> V_129 ) ) {
V_184 -> V_188 = V_190 ;
V_187 = true ;
break;
}
}
if ( ! V_187 ) {
V_186 = F_90 ( V_185 ,
sizeof( struct V_176 ) ,
V_158 ) ;
if ( ! V_186 )
return;
V_186 -> V_188 = V_191 ;
F_16 ( & V_186 -> V_57 , V_182 ) ;
}
}
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_19 )
return;
F_37 ( V_5 -> V_82 -> V_115 , & V_5 -> V_192 ) ;
}
static void F_92 ( struct V_4 * V_5 ,
struct V_122 * V_82 )
{
int V_114 = 0 ;
if ( ! ( V_5 -> V_167 & V_193 ) ) {
if ( F_93 ( V_5 ) )
F_15 ( V_5 , L_20 ) ;
V_5 -> V_167 |= V_193 ;
switch ( V_82 -> V_2 -> V_135 . V_142 ) {
case V_148 :
V_114 = F_94 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_152 ,
V_194 ) ;
if ( V_114 )
F_18 ( V_5 , L_21 ) ;
V_5 -> V_167 |= V_195 ;
break;
case V_143 :
V_114 = F_95 ( V_82 -> V_2 ,
V_5 -> V_152 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_22 ) ;
if ( ! ( V_5 -> V_167 & V_195 ) ) {
V_114 = F_96 ( V_82 -> V_2 ,
V_5 -> V_152 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_23 ) ;
V_5 -> V_167 |= V_195 ;
}
break;
case V_153 :
V_114 = F_97 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_152 ,
1 ) ;
if ( V_114 )
F_18 ( V_5 , L_21 ) ;
break;
}
V_114 = F_98 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_196 ) ;
if ( V_114 )
F_18 ( V_5 , L_24 ) ;
V_114 = F_51 ( V_82 -> V_2 , V_5 ) ;
if ( V_114 )
F_18 ( V_5 , L_25 ) ;
}
}
static void F_99 ( struct V_4 * V_5 ,
struct V_122 * V_82 )
{
int V_114 = 0 ;
if ( F_93 ( V_5 ) )
F_15 ( V_5 , L_26 ) ;
V_5 -> V_167 &= ~ V_193 ;
switch ( V_82 -> V_2 -> V_135 . V_142 ) {
case V_148 :
V_114 = F_100 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_194 ) ;
if ( V_114 )
F_18 ( V_5 , L_27 ) ;
V_5 -> V_167 &= ~ V_195 ;
break;
case V_143 :
V_114 = F_101 ( V_82 -> V_2 ,
V_5 -> V_152 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_28 ) ;
if ( V_5 -> V_167 & V_195 ) {
V_114 = F_102 ( V_82 -> V_2 ,
V_5 -> V_152 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_29 ) ;
V_5 -> V_167 &= ~ V_195 ;
}
break;
case V_153 :
V_114 = F_97 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_152 , 0 ) ;
if ( V_114 )
F_18 ( V_5 , L_27 ) ;
break;
}
V_114 = F_51 ( V_82 -> V_2 , V_5 ) ;
if ( V_114 )
F_18 ( V_5 , L_30 ) ;
}
static void F_103 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_122 * V_82 )
{
struct V_176 * V_197 , * V_116 ;
T_5 V_198 = 0 ;
T_1 V_180 [ 16 ] = { 0 } ;
int V_114 = 0 ;
if ( V_2 -> V_167 & V_199 ) {
V_114 = F_98 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_196 ) ;
if ( V_114 )
F_18 ( V_5 , L_24 ) ;
if ( ! ( V_5 -> V_167 & V_195 ) ) {
switch ( V_82 -> V_2 -> V_135 . V_142 ) {
case V_148 :
V_114 = F_94 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_152 ,
V_200 ) ;
break;
case V_143 :
V_114 = F_96 ( V_82 -> V_2 ,
V_5 -> V_152 ,
V_5 -> V_64 ) ;
break;
case V_153 :
break;
}
if ( V_114 )
F_18 ( V_5 , L_31 ) ;
V_5 -> V_167 |= V_195 ;
}
} else {
if ( V_5 -> V_167 & V_195 ) {
switch ( V_82 -> V_2 -> V_135 . V_142 ) {
case V_148 :
V_114 = F_100 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_200 ) ;
break;
case V_143 :
V_114 = F_102 ( V_82 -> V_2 ,
V_5 -> V_152 ,
V_5 -> V_64 ) ;
break;
case V_153 :
break;
}
if ( V_114 )
F_18 ( V_5 , L_29 ) ;
V_5 -> V_167 &= ~ V_195 ;
}
V_114 = F_98 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_196 ) ;
if ( V_114 )
F_18 ( V_5 , L_24 ) ;
F_98 ( V_82 -> V_2 , V_5 -> V_64 , V_201 ,
1 , V_202 ) ;
F_104 ( V_2 ) ;
F_85 ( V_2 ) ;
F_105 ( V_2 ) ;
F_88 (mclist, &priv->mc_list, list) {
V_198 = F_65 ( V_197 -> V_129 ) ;
F_98 ( V_82 -> V_2 , V_5 -> V_64 ,
V_198 , 0 , V_202 ) ;
}
V_114 = F_98 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_203 ) ;
if ( V_114 )
F_18 ( V_5 , L_32 ) ;
F_87 ( V_5 , & V_5 -> V_204 , & V_5 -> V_180 ) ;
F_41 (mclist, tmp, &priv->curr_list, list) {
if ( V_197 -> V_188 == V_189 ) {
memcpy ( & V_180 [ 10 ] , V_197 -> V_129 , V_78 ) ;
V_180 [ 5 ] = V_5 -> V_64 ;
V_114 = F_106 ( V_82 -> V_2 ,
& V_5 -> V_72 . V_205 ,
V_180 ,
V_147 ,
V_197 -> V_81 ) ;
if ( V_114 )
F_18 ( V_5 , L_33 ) ;
if ( V_197 -> V_156 ) {
V_114 = F_17 ( V_5 -> V_82 -> V_2 , V_197 -> V_156 ) ;
if ( V_114 )
F_18 ( V_5 , L_34 ) ;
}
F_28 ( & V_197 -> V_57 ) ;
F_29 ( V_197 ) ;
} else if ( V_197 -> V_188 == V_191 ) {
memcpy ( & V_180 [ 10 ] , V_197 -> V_129 , V_78 ) ;
V_180 [ 5 ] = V_5 -> V_64 ;
V_114 = F_107 ( V_82 -> V_2 ,
& V_5 -> V_72 . V_205 ,
V_180 ,
V_5 -> V_64 , 0 ,
V_147 ,
& V_197 -> V_81 ) ;
if ( V_114 )
F_18 ( V_5 , L_35 ) ;
V_114 = F_58 ( V_5 , & V_180 [ 10 ] , V_5 -> V_152 ,
& V_197 -> V_156 ) ;
if ( V_114 )
F_18 ( V_5 , L_36 ) ;
}
}
}
}
static void F_108 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_122 * V_82 )
{
struct V_178 * V_179 ;
struct V_149 * V_150 ;
struct V_163 * V_116 ;
bool V_187 ;
T_5 V_140 ;
int V_114 = 0 ;
struct V_84 * V_164 ;
unsigned int V_6 ;
int V_206 = 0 ;
T_3 V_207 ;
for ( V_6 = 0 ; V_6 < V_165 ; ++ V_6 ) {
V_164 = & V_5 -> V_161 [ V_6 ] ;
F_74 (entry, tmp, bucket, hlist) {
V_187 = false ;
F_109 (ha, dev) {
if ( F_78 ( V_150 -> V_140 ,
V_179 -> V_129 ) ) {
V_187 = true ;
break;
}
}
if ( F_78 ( V_150 -> V_140 , V_2 -> V_77 ) )
V_187 = true ;
if ( ! V_187 ) {
V_140 = F_65 ( V_150 -> V_140 ) ;
F_62 ( V_5 , V_150 -> V_140 ,
V_5 -> V_152 ,
V_150 -> V_81 ) ;
F_72 ( V_82 -> V_2 , V_5 -> V_64 , V_140 ) ;
F_75 ( & V_150 -> V_160 ) ;
F_76 ( V_150 , V_166 ) ;
F_48 ( V_139 , V_5 , L_37 ,
V_150 -> V_140 , V_5 -> V_64 ) ;
++ V_206 ;
}
}
}
if ( ( V_5 -> V_167 & V_168 ) && 0 == V_206 )
return;
V_207 = V_5 -> V_167 ;
V_5 -> V_167 &= ~ V_168 ;
F_109 (ha, dev) {
V_187 = false ;
V_164 = & V_5 -> V_161 [ V_179 -> V_129 [ V_162 ] ] ;
F_31 (entry, bucket, hlist) {
if ( F_78 ( V_150 -> V_140 , V_179 -> V_129 ) ) {
V_187 = true ;
break;
}
}
if ( ! V_187 ) {
V_150 = F_69 ( sizeof( * V_150 ) , V_158 ) ;
if ( ! V_150 ) {
F_18 ( V_5 , L_38 ,
V_179 -> V_129 , V_5 -> V_64 ) ;
V_5 -> V_167 |= V_168 ;
break;
}
V_140 = F_65 ( V_179 -> V_129 ) ;
memcpy ( V_150 -> V_140 , V_179 -> V_129 , V_78 ) ;
V_114 = F_66 ( V_82 -> V_2 , V_5 -> V_64 , V_140 ) ;
if ( V_114 < 0 ) {
F_18 ( V_5 , L_39 ,
V_179 -> V_129 , V_5 -> V_64 , V_114 ) ;
F_29 ( V_150 ) ;
V_5 -> V_167 |= V_168 ;
break;
}
V_114 = F_60 ( V_5 , V_179 -> V_129 ,
& V_5 -> V_152 ,
& V_150 -> V_81 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_40 ,
V_179 -> V_129 , V_5 -> V_64 , V_114 ) ;
F_72 ( V_82 -> V_2 , V_5 -> V_64 , V_140 ) ;
F_29 ( V_150 ) ;
V_5 -> V_167 |= V_168 ;
break;
} else {
unsigned int V_161 ;
F_48 ( V_139 , V_5 , L_41 ,
V_179 -> V_129 , V_5 -> V_64 ) ;
V_161 = V_179 -> V_129 [ V_162 ] ;
V_164 = & V_5 -> V_161 [ V_161 ] ;
F_70 ( & V_150 -> V_160 , V_164 ) ;
}
}
}
if ( V_5 -> V_167 & V_168 ) {
F_15 ( V_5 , L_42 ,
V_5 -> V_64 ) ;
} else if ( V_207 & V_168 ) {
F_15 ( V_5 , L_43 ,
V_5 -> V_64 ) ;
}
}
static void F_110 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_192 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_50 ( & V_82 -> V_126 ) ;
if ( ! V_82 -> V_127 ) {
F_48 ( V_124 , V_5 , L_44 ) ;
goto V_112;
}
if ( ! V_5 -> V_19 ) {
F_48 ( V_124 , V_5 , L_45 ) ;
goto V_112;
}
if ( ! F_111 ( V_2 ) ) {
if ( ! F_112 ( V_82 , V_5 -> V_64 ) ) {
if ( V_5 -> V_208 . V_209 ) {
V_5 -> V_210 = V_211 ;
F_113 ( V_2 ) ;
F_48 ( V_212 , V_5 , L_46 ) ;
}
}
}
if ( V_2 -> V_213 & V_214 )
F_108 ( V_5 , V_2 , V_82 ) ;
if ( ( V_2 -> V_167 & V_215 ) ||
( V_5 -> V_167 & V_168 ) ) {
F_92 ( V_5 , V_82 ) ;
goto V_112;
}
if ( V_5 -> V_167 & V_193 )
F_99 ( V_5 , V_82 ) ;
F_103 ( V_5 , V_2 , V_82 ) ;
V_112:
F_53 ( & V_82 -> V_126 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_13 * V_14 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
V_14 = V_5 -> V_217 [ V_6 ] ;
F_115 ( & V_14 -> V_12 ) ;
}
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_6 ;
if ( F_117 ( V_5 ) )
F_15 ( V_5 , L_47 , V_5 -> V_64 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
if ( ! F_118 ( F_119 ( V_2 , V_6 ) ) )
continue;
F_15 ( V_5 , L_48 ,
V_6 , V_5 -> V_219 [ V_6 ] -> V_71 , V_5 -> V_219 [ V_6 ] -> V_220 ,
V_5 -> V_219 [ V_6 ] -> V_221 , V_5 -> V_219 [ V_6 ] -> V_222 ) ;
}
V_5 -> V_223 . V_224 ++ ;
F_48 ( V_139 , V_5 , L_49 ) ;
F_37 ( V_82 -> V_115 , & V_5 -> V_225 ) ;
}
static struct V_226 * F_120 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_36 ( & V_5 -> V_227 ) ;
memcpy ( & V_5 -> V_228 , & V_5 -> V_229 , sizeof( V_5 -> V_229 ) ) ;
F_38 ( & V_5 -> V_227 ) ;
return & V_5 -> V_228 ;
}
static void F_121 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
int V_6 ;
V_5 -> V_230 = V_231 ;
V_5 -> V_232 = V_233 ;
V_5 -> V_234 = V_235 ;
V_5 -> V_236 = V_237 ;
F_48 ( V_238 , V_5 , L_50 ,
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
static void F_122 ( struct V_4 * V_5 )
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
V_114 = F_123 ( V_5 , V_14 ) ;
if ( V_114 )
F_18 ( V_5 , L_51 ,
V_17 ) ;
}
V_5 -> V_244 [ V_17 ] = V_265 ;
V_5 -> V_245 [ V_17 ] = V_266 ;
}
V_5 -> V_258 = V_261 ;
}
static void F_124 ( struct V_31 * V_32 )
{
struct V_272 * V_273 = F_125 ( V_32 ) ;
struct V_4 * V_5 = F_6 ( V_273 , struct V_4 ,
V_274 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_114 ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_82 -> V_127 ) {
if ( V_5 -> V_19 ) {
V_114 = F_126 ( V_82 , V_5 -> V_64 , 0 ) ;
if ( V_114 )
F_48 ( V_124 , V_5 , L_52 ) ;
F_122 ( V_5 ) ;
}
F_127 ( V_82 -> V_115 , & V_5 -> V_274 , V_275 ) ;
}
if ( V_82 -> V_276 [ V_277 + 1 - V_5 -> V_64 ] ) {
F_81 ( V_5 ) ;
V_82 -> V_276 [ V_277 + 1 - V_5 -> V_64 ] = 0 ;
}
F_53 ( & V_82 -> V_126 ) ;
}
static void F_128 ( struct V_31 * V_32 )
{
struct V_272 * V_273 = F_125 ( V_32 ) ;
struct V_4 * V_5 = F_6 ( V_273 , struct V_4 ,
V_278 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_82 -> V_127 ) {
if ( V_82 -> V_2 -> V_135 . V_279 & V_280 )
F_129 ( V_82 ) ;
F_127 ( V_82 -> V_115 , & V_5 -> V_278 ,
V_281 ) ;
}
F_53 ( & V_82 -> V_126 ) ;
}
static void F_130 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_282 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_283 = V_5 -> V_209 ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_5 -> V_210 != V_283 ) {
if ( V_283 == V_284 ) {
F_131 ( V_5 , L_53 ) ;
F_132 ( V_5 -> V_2 ) ;
} else {
F_131 ( V_5 , L_46 ) ;
F_113 ( V_5 -> V_2 ) ;
}
}
V_5 -> V_210 = V_283 ;
F_53 ( & V_82 -> V_126 ) ;
}
static int F_133 ( struct V_4 * V_5 , int V_285 )
{
struct V_15 * V_17 = V_5 -> V_16 [ V_285 ] ;
int V_286 = V_5 -> V_82 -> V_2 -> V_286 ;
int V_96 = 0 ;
if ( ! F_134 ( & V_17 -> V_287 , V_158 ) )
return - V_113 ;
V_96 = F_135 ( V_285 , V_286 ,
V_17 -> V_287 ) ;
if ( V_96 )
F_136 ( V_17 -> V_287 ) ;
return V_96 ;
}
static void F_137 ( struct V_4 * V_5 , int V_285 )
{
F_136 ( V_5 -> V_16 [ V_285 ] -> V_287 ) ;
}
int F_138 ( struct V_1 * V_2 )
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
F_48 ( V_139 , V_5 , L_54 ) ;
return 0 ;
}
F_59 ( & V_5 -> V_180 ) ;
F_59 ( & V_5 -> V_204 ) ;
F_59 ( & V_5 -> V_292 ) ;
memset ( & V_5 -> V_293 [ 0 ] , 0 ,
sizeof( struct V_294 ) * V_295 ) ;
V_2 -> V_239 = F_139 ( V_2 -> V_239 , V_5 -> V_296 ) ;
F_140 ( V_2 ) ;
F_48 ( V_139 , V_5 , L_55 , V_5 -> V_297 ) ;
V_114 = F_141 ( V_5 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_56 ) ;
return V_114 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
V_14 = V_5 -> V_217 [ V_6 ] ;
F_142 ( V_14 ) ;
V_114 = F_133 ( V_5 , V_6 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_57 ) ;
goto V_298;
}
V_114 = F_143 ( V_5 , V_14 , V_6 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_58 ) ;
F_137 ( V_5 , V_6 ) ;
goto V_298;
}
for ( V_291 = 0 ; V_291 < V_14 -> V_299 ; V_291 ++ )
V_14 -> V_300 [ V_291 ] . V_301 = V_302 ;
V_114 = F_123 ( V_5 , V_14 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_59 ) ;
F_144 ( V_5 , V_14 ) ;
F_137 ( V_5 , V_6 ) ;
goto V_298;
}
F_145 ( V_5 , V_14 ) ;
V_5 -> V_16 [ V_6 ] -> V_220 = V_14 -> V_303 . V_220 ;
++ V_289 ;
}
F_48 ( V_139 , V_5 , L_60 , V_5 -> V_64 ) ;
V_114 = F_64 ( V_5 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_61 ) ;
goto V_298;
}
V_82 -> V_276 [ V_5 -> V_64 ] = 0 ;
V_114 = F_146 ( V_5 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_62 ) ;
goto V_304;
}
V_114 = F_147 ( V_5 ) ;
if ( V_114 )
goto V_305;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
V_14 = V_5 -> V_246 [ V_6 ] ;
V_114 = F_143 ( V_5 , V_14 , V_6 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_63 ) ;
goto V_306;
}
V_114 = F_123 ( V_5 , V_14 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_59 ) ;
F_144 ( V_5 , V_14 ) ;
goto V_306;
}
F_48 ( V_139 , V_5 , L_64 , V_6 ) ;
V_14 -> V_300 -> V_307 = F_148 ( 0xffff ) ;
V_219 = V_5 -> V_219 [ V_6 ] ;
V_114 = F_149 ( V_5 , V_219 , V_14 -> V_303 . V_220 ,
V_6 / V_5 -> V_10 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_65 ) ;
F_144 ( V_5 , V_14 ) ;
goto V_306;
}
V_219 -> V_308 = F_119 ( V_2 , V_6 ) ;
F_145 ( V_5 , V_14 ) ;
for ( V_291 = 0 ; V_291 < V_219 -> V_309 ; V_291 += V_310 )
* ( ( T_3 * ) ( V_219 -> V_300 + V_291 ) ) = 0xffffffff ;
++ V_290 ;
}
V_114 = F_150 ( V_82 -> V_2 , V_5 -> V_64 ,
V_5 -> V_297 + V_311 ,
V_5 -> V_312 -> V_313 ,
V_5 -> V_312 -> V_314 ,
V_5 -> V_312 -> V_315 ,
V_5 -> V_312 -> V_316 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_66 ,
V_5 -> V_64 , V_114 ) ;
goto V_306;
}
V_114 = F_97 ( V_82 -> V_2 , V_5 -> V_64 , V_5 -> V_152 , 0 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_67 ) ;
goto V_306;
}
if ( V_82 -> V_2 -> V_135 . V_136 == V_137 ) {
V_114 = F_151 ( V_82 -> V_2 , V_5 -> V_64 , V_317 , 1 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_68 ,
V_114 ) ;
goto V_306;
}
}
F_48 ( V_124 , V_5 , L_69 ) ;
V_114 = F_152 ( V_82 -> V_2 , V_5 -> V_64 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_70 ) ;
goto V_306;
}
memset ( & V_180 [ 10 ] , 0xff , V_78 ) ;
V_180 [ 5 ] = V_5 -> V_64 ;
if ( F_107 ( V_82 -> V_2 , & V_5 -> V_72 . V_205 , V_180 ,
V_5 -> V_64 , 0 , V_147 ,
& V_5 -> V_318 ) )
F_153 ( V_82 , L_71 ) ;
V_5 -> V_167 &= ~ ( V_193 | V_195 ) ;
F_37 ( V_82 -> V_115 , & V_5 -> V_192 ) ;
F_154 ( V_82 -> V_2 , & V_5 -> V_319 ) ;
#ifdef F_155
if ( V_5 -> V_82 -> V_2 -> V_135 . V_279 & V_320 )
F_156 ( V_2 ) ;
#endif
V_5 -> V_19 = true ;
F_157 ( V_2 ) ;
F_158 ( V_2 ) ;
return 0 ;
V_306:
while ( V_290 -- ) {
F_159 ( V_5 , V_5 -> V_219 [ V_290 ] ) ;
F_144 ( V_5 , V_5 -> V_246 [ V_290 ] ) ;
}
F_160 ( V_5 ) ;
V_305:
F_161 ( V_5 ) ;
V_304:
F_73 ( V_5 ) ;
V_298:
while ( V_289 -- ) {
F_144 ( V_5 , V_5 -> V_217 [ V_289 ] ) ;
F_137 ( V_5 , V_6 ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ )
F_162 ( V_5 , V_5 -> V_16 [ V_6 ] ) ;
return V_114 ;
}
void F_163 ( struct V_1 * V_2 , int V_321 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_176 * V_197 , * V_116 ;
struct V_294 * V_322 , * V_323 ;
int V_6 ;
T_1 V_180 [ 16 ] = { 0 } ;
if ( ! V_5 -> V_19 ) {
F_48 ( V_139 , V_5 , L_72 ) ;
return;
}
F_164 ( V_82 -> V_2 , V_5 -> V_64 ) ;
F_165 ( V_2 ) ;
if ( V_321 )
F_166 ( V_2 ) ;
F_167 ( V_2 ) ;
F_168 ( V_2 ) ;
F_169 ( V_2 ) ;
V_5 -> V_19 = false ;
if ( V_82 -> V_2 -> V_135 . V_142 ==
V_148 ) {
V_5 -> V_167 &= ~ ( V_193 |
V_195 ) ;
F_100 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_194 ) ;
F_100 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_200 ) ;
} else if ( V_5 -> V_167 & V_193 ) {
V_5 -> V_167 &= ~ V_193 ;
F_101 ( V_82 -> V_2 , V_5 -> V_152 ,
V_5 -> V_64 ) ;
if ( V_5 -> V_167 & V_195 ) {
F_102 ( V_82 -> V_2 , V_5 -> V_152 ,
V_5 -> V_64 ) ;
V_5 -> V_167 &= ~ V_195 ;
}
}
memset ( & V_180 [ 10 ] , 0xff , V_78 ) ;
V_180 [ 5 ] = V_5 -> V_64 ;
F_106 ( V_82 -> V_2 , & V_5 -> V_72 . V_205 , V_180 ,
V_147 , V_5 -> V_318 ) ;
F_88 (mclist, &priv->curr_list, list) {
memcpy ( & V_180 [ 10 ] , V_197 -> V_129 , V_78 ) ;
V_180 [ 5 ] = V_5 -> V_64 ;
F_106 ( V_82 -> V_2 , & V_5 -> V_72 . V_205 ,
V_180 , V_147 , V_197 -> V_81 ) ;
if ( V_197 -> V_156 )
F_17 ( V_82 -> V_2 , V_197 -> V_156 ) ;
}
F_84 ( V_2 ) ;
F_41 (mclist, tmp, &priv->curr_list, list) {
F_28 ( & V_197 -> V_57 ) ;
F_29 ( V_197 ) ;
}
F_98 ( V_82 -> V_2 , V_5 -> V_64 , 0 , 1 , V_202 ) ;
if ( V_82 -> V_2 -> V_135 . V_142 ==
V_148 ) {
F_170 () ;
F_41 (flow, tmp_flow,
&priv->ethtool_list, list) {
F_17 ( V_82 -> V_2 , V_322 -> V_37 ) ;
F_28 ( & V_322 -> V_57 ) ;
}
}
F_160 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
F_159 ( V_5 , V_5 -> V_219 [ V_6 ] ) ;
F_144 ( V_5 , V_5 -> V_246 [ V_6 ] ) ;
}
F_171 ( 10 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ )
F_172 ( V_2 , V_5 -> V_219 [ V_6 ] ) ;
F_161 ( V_5 ) ;
F_73 ( V_5 ) ;
if ( ! ( V_82 -> V_2 -> V_135 . V_279 & V_324 ) )
V_82 -> V_276 [ V_5 -> V_64 ] = 1 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
struct V_13 * V_14 = V_5 -> V_217 [ V_6 ] ;
F_173 () ;
while ( ! F_174 ( V_14 ) ) {
F_175 ( L_73 , V_6 ) ;
F_176 ( 1 ) ;
}
F_177 () ;
while ( F_178 ( V_325 , & V_14 -> V_12 . V_326 ) )
F_171 ( 1 ) ;
F_162 ( V_5 , V_5 -> V_16 [ V_6 ] ) ;
F_144 ( V_5 , V_14 ) ;
F_137 ( V_5 , V_6 ) ;
}
}
static void F_179 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_225 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_48 ( V_139 , V_5 , L_74 , V_5 -> V_64 ) ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_5 -> V_19 ) {
F_163 ( V_2 , 1 ) ;
if ( F_138 ( V_2 ) )
F_18 ( V_5 , L_75 , V_5 -> V_64 ) ;
}
F_53 ( & V_82 -> V_126 ) ;
}
static void F_180 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_6 ;
if ( F_126 ( V_82 , V_5 -> V_64 , 1 ) )
F_48 ( V_124 , V_5 , L_76 ) ;
memset ( & V_5 -> V_229 , 0 , sizeof( V_5 -> V_229 ) ) ;
memset ( & V_5 -> V_327 , 0 , sizeof( V_5 -> V_327 ) ) ;
memset ( & V_5 -> V_328 , 0 , sizeof( V_5 -> V_328 ) ) ;
memset ( & V_5 -> V_223 , 0 , sizeof( V_5 -> V_223 ) ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
V_5 -> V_219 [ V_6 ] -> V_269 = 0 ;
V_5 -> V_219 [ V_6 ] -> V_262 = 0 ;
V_5 -> V_219 [ V_6 ] -> V_329 = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
V_5 -> V_16 [ V_6 ] -> V_269 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_262 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_330 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_331 = 0 ;
}
}
static int F_181 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_114 = 0 ;
F_50 ( & V_82 -> V_126 ) ;
if ( ! V_82 -> V_127 ) {
F_18 ( V_5 , L_77 ) ;
V_114 = - V_332 ;
goto V_112;
}
F_180 ( V_2 ) ;
V_114 = F_138 ( V_2 ) ;
if ( V_114 )
F_18 ( V_5 , L_78 , V_5 -> V_64 ) ;
V_112:
F_53 ( & V_82 -> V_126 ) ;
return V_114 ;
}
static int F_182 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
F_48 ( V_333 , V_5 , L_79 ) ;
F_50 ( & V_82 -> V_126 ) ;
F_163 ( V_2 , 0 ) ;
F_132 ( V_2 ) ;
F_53 ( & V_82 -> V_126 ) ;
return 0 ;
}
void F_183 ( struct V_4 * V_5 )
{
int V_6 ;
#ifdef F_184
F_185 ( V_5 -> V_2 -> V_334 ) ;
V_5 -> V_2 -> V_334 = NULL ;
#endif
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
if ( V_5 -> V_219 && V_5 -> V_219 [ V_6 ] )
F_186 ( V_5 , & V_5 -> V_219 [ V_6 ] ) ;
if ( V_5 -> V_246 && V_5 -> V_246 [ V_6 ] )
F_187 ( V_5 , & V_5 -> V_246 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
if ( V_5 -> V_16 [ V_6 ] )
F_188 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_5 -> V_312 -> V_335 , V_5 -> V_336 ) ;
if ( V_5 -> V_217 [ V_6 ] )
F_187 ( V_5 , & V_5 -> V_217 [ V_6 ] ) ;
}
if ( V_5 -> V_337 ) {
F_71 ( V_5 -> V_82 -> V_2 , V_5 -> V_337 , V_5 -> V_218 ) ;
V_5 -> V_337 = 0 ;
}
}
int F_189 ( struct V_4 * V_5 )
{
struct V_338 * V_312 = V_5 -> V_312 ;
int V_6 ;
int V_114 ;
int V_339 ;
V_114 = F_68 ( V_5 -> V_82 -> V_2 , V_5 -> V_218 , 256 , & V_5 -> V_337 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_80 ) ;
return V_114 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
V_339 = F_190 ( V_6 % F_191 () ) ;
if ( F_192 ( V_5 , & V_5 -> V_246 [ V_6 ] ,
V_312 -> V_340 , V_6 , V_341 , V_339 ) )
goto V_114;
if ( F_193 ( V_5 , & V_5 -> V_219 [ V_6 ] ,
V_5 -> V_337 + V_6 ,
V_312 -> V_340 , V_342 ,
V_339 , V_6 ) )
goto V_114;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
V_339 = F_190 ( V_6 % F_191 () ) ;
if ( F_192 ( V_5 , & V_5 -> V_217 [ V_6 ] ,
V_312 -> V_335 , V_6 , V_343 , V_339 ) )
goto V_114;
if ( F_194 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_312 -> V_335 , V_5 -> V_336 ,
V_339 ) )
goto V_114;
}
#ifdef F_184
if ( V_5 -> V_82 -> V_2 -> V_135 . V_344 ) {
V_5 -> V_2 -> V_334 = F_195 ( V_5 -> V_82 -> V_2 -> V_135 . V_344 ) ;
if ( ! V_5 -> V_2 -> V_334 )
goto V_114;
}
#endif
return 0 ;
V_114:
F_18 ( V_5 , L_81 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_216 ; V_6 ++ ) {
if ( V_5 -> V_16 [ V_6 ] )
F_188 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_312 -> V_335 ,
V_5 -> V_336 ) ;
if ( V_5 -> V_217 [ V_6 ] )
F_187 ( V_5 , & V_5 -> V_217 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_218 ; V_6 ++ ) {
if ( V_5 -> V_219 [ V_6 ] )
F_186 ( V_5 , & V_5 -> V_219 [ V_6 ] ) ;
if ( V_5 -> V_246 [ V_6 ] )
F_187 ( V_5 , & V_5 -> V_246 [ V_6 ] ) ;
}
return - V_113 ;
}
void F_196 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
F_48 ( V_139 , V_5 , L_82 , V_5 -> V_64 ) ;
if ( V_5 -> V_345 )
F_197 ( V_2 ) ;
if ( V_5 -> V_346 )
F_198 ( V_82 -> V_2 , & V_5 -> V_347 , V_348 ) ;
F_199 ( & V_5 -> V_274 ) ;
F_199 ( & V_5 -> V_278 ) ;
F_200 ( V_82 -> V_115 ) ;
F_50 ( & V_82 -> V_126 ) ;
V_82 -> V_349 [ V_5 -> V_64 ] = NULL ;
F_53 ( & V_82 -> V_126 ) ;
F_183 ( V_5 ) ;
F_29 ( V_5 -> V_219 ) ;
F_29 ( V_5 -> V_246 ) ;
F_201 ( V_2 ) ;
}
static int F_202 ( struct V_1 * V_2 , int V_350 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_114 = 0 ;
F_48 ( V_139 , V_5 , L_83 ,
V_2 -> V_239 , V_350 ) ;
if ( ( V_350 < V_351 ) || ( V_350 > V_5 -> V_296 ) ) {
F_18 ( V_5 , L_84 , V_350 ) ;
return - V_352 ;
}
V_2 -> V_239 = V_350 ;
if ( F_203 ( V_2 ) ) {
F_50 ( & V_82 -> V_126 ) ;
if ( ! V_82 -> V_127 ) {
F_48 ( V_139 , V_5 , L_85 ) ;
} else {
F_163 ( V_2 , 1 ) ;
V_114 = F_138 ( V_2 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_86 ,
V_5 -> V_64 ) ;
F_37 ( V_82 -> V_115 , & V_5 -> V_225 ) ;
}
}
F_53 ( & V_82 -> V_126 ) ;
}
return 0 ;
}
static int F_204 ( struct V_1 * V_2 , struct V_353 * V_354 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_355 V_356 ;
if ( F_205 ( & V_356 , V_354 -> V_357 , sizeof( V_356 ) ) )
return - V_358 ;
if ( V_356 . V_167 )
return - V_9 ;
if ( ! ( V_82 -> V_2 -> V_135 . V_279 & V_280 ) )
return - V_9 ;
switch ( V_356 . V_359 ) {
case V_360 :
case V_361 :
break;
default:
return - V_362 ;
}
switch ( V_356 . V_363 ) {
case V_364 :
break;
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
case V_377 :
case V_378 :
V_356 . V_363 = V_365 ;
break;
default:
return - V_362 ;
}
if ( F_206 ( V_2 , V_356 . V_359 , V_356 . V_363 ) ) {
V_356 . V_359 = V_360 ;
V_356 . V_363 = V_364 ;
}
return F_207 ( V_354 -> V_357 , & V_356 ,
sizeof( V_356 ) ) ? - V_358 : 0 ;
}
static int F_208 ( struct V_1 * V_2 , struct V_353 * V_354 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_207 ( V_354 -> V_357 , & V_5 -> V_355 ,
sizeof( V_5 -> V_355 ) ) ? - V_358 : 0 ;
}
static int F_209 ( struct V_1 * V_2 , struct V_353 * V_354 , int V_379 )
{
switch ( V_379 ) {
case V_380 :
return F_204 ( V_2 , V_354 ) ;
case V_381 :
return F_208 ( V_2 , V_354 ) ;
default:
return - V_382 ;
}
}
static int F_210 ( struct V_1 * V_383 ,
T_6 V_384 )
{
struct V_4 * V_5 = F_2 ( V_383 ) ;
if ( V_384 & V_385 )
V_5 -> V_386 |= F_211 ( V_387 ) ;
else
V_5 -> V_386 &=
F_211 ( ~ V_387 ) ;
F_212 ( V_383 , V_384 ) ;
return 0 ;
}
static int F_213 ( struct V_1 * V_2 , int V_388 , T_1 * V_140 )
{
struct V_4 * V_389 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_389 -> V_82 ;
T_5 V_390 = F_65 ( V_140 ) ;
if ( ! F_83 ( V_140 ) )
return - V_9 ;
return F_214 ( V_82 -> V_2 , V_389 -> V_64 , V_388 , V_390 ) ;
}
static int F_215 ( struct V_1 * V_2 , int V_391 , T_4 V_392 , T_1 V_393 )
{
struct V_4 * V_389 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_389 -> V_82 ;
return F_216 ( V_82 -> V_2 , V_389 -> V_64 , V_391 , V_392 , V_393 ) ;
}
static int F_217 ( struct V_1 * V_2 , int V_391 , bool V_394 )
{
struct V_4 * V_389 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_389 -> V_82 ;
return F_218 ( V_82 -> V_2 , V_389 -> V_64 , V_391 , V_394 ) ;
}
static int F_219 ( struct V_1 * V_2 , int V_391 , struct V_395 * V_396 )
{
struct V_4 * V_389 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_389 -> V_82 ;
return F_220 ( V_82 -> V_2 , V_389 -> V_64 , V_391 , V_396 ) ;
}
static int F_221 ( struct V_1 * V_2 , int V_391 , int V_209 )
{
struct V_4 * V_389 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_389 -> V_82 ;
return F_222 ( V_82 -> V_2 , V_389 -> V_64 , V_391 , V_209 ) ;
}
static int F_223 ( struct V_1 * V_2 ,
struct V_397 * V_398 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_141 * V_82 = V_5 -> V_82 -> V_2 ;
int V_6 ;
T_5 V_399 = V_82 -> V_135 . V_399 [ V_5 -> V_64 ] ;
if ( ! V_399 )
return - V_382 ;
V_398 -> V_400 = sizeof( V_399 ) ;
for ( V_6 = V_401 - 1 ; V_6 >= 0 ; -- V_6 ) {
V_398 -> V_37 [ V_6 ] = V_399 & 0xff ;
V_399 >>= 8 ;
}
return 0 ;
}
static void F_224 ( struct V_31 * V_32 )
{
int V_96 ;
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_402 ) ;
V_96 = F_225 ( V_5 -> V_82 -> V_2 , V_5 -> V_403 ) ;
if ( V_96 )
goto V_112;
V_96 = F_151 ( V_5 -> V_82 -> V_2 , V_5 -> V_64 ,
V_317 , 1 ) ;
V_112:
if ( V_96 )
F_18 ( V_5 , L_87 , V_96 ) ;
}
static void F_226 ( struct V_31 * V_32 )
{
int V_96 ;
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_404 ) ;
V_96 = F_151 ( V_5 -> V_82 -> V_2 , V_5 -> V_64 ,
V_317 , 0 ) ;
if ( V_96 )
F_18 ( V_5 , L_87 , V_96 ) ;
V_5 -> V_403 = 0 ;
}
static void F_227 ( struct V_1 * V_2 ,
T_7 V_405 , V_42 V_64 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_42 V_406 ;
if ( V_5 -> V_82 -> V_2 -> V_135 . V_136 != V_137 )
return;
if ( V_405 == V_407 )
return;
V_406 = V_5 -> V_403 ;
if ( V_406 && V_406 != V_64 ) {
F_15 ( V_5 , L_88 ,
F_228 ( V_406 ) , F_228 ( V_64 ) ) ;
return;
}
V_5 -> V_403 = V_64 ;
F_37 ( V_5 -> V_82 -> V_115 , & V_5 -> V_402 ) ;
}
static void F_229 ( struct V_1 * V_2 ,
T_7 V_405 , V_42 V_64 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_42 V_406 ;
if ( V_5 -> V_82 -> V_2 -> V_135 . V_136 != V_137 )
return;
if ( V_405 == V_407 )
return;
V_406 = V_5 -> V_403 ;
if ( V_406 != V_64 ) {
F_48 ( V_139 , V_5 , L_89 , F_228 ( V_64 ) ) ;
return;
}
F_37 ( V_5 -> V_82 -> V_115 , & V_5 -> V_404 ) ;
}
int F_230 ( struct V_122 * V_82 , int V_64 ,
struct V_338 * V_312 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_6 ;
int V_114 ;
T_5 V_390 ;
V_2 = F_231 ( sizeof( struct V_4 ) ,
V_408 , V_409 ) ;
if ( V_2 == NULL )
return - V_113 ;
F_232 ( V_2 , V_312 -> V_218 ) ;
F_233 ( V_2 , V_312 -> V_216 ) ;
F_234 ( V_2 , & V_82 -> V_2 -> V_410 -> V_2 ) ;
V_2 -> V_411 = V_64 - 1 ;
V_5 = F_2 ( V_2 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_82 = V_82 ;
V_5 -> V_412 = & V_82 -> V_410 -> V_2 ;
V_5 -> V_312 = V_312 ;
V_5 -> V_64 = V_64 ;
V_5 -> V_19 = false ;
V_5 -> V_167 = V_312 -> V_167 ;
V_5 -> V_386 = F_211 ( V_413 |
V_414 ) ;
V_5 -> V_10 = V_82 -> V_415 . V_10 ;
V_5 -> V_218 = V_312 -> V_218 ;
V_5 -> V_416 = V_417 ;
V_5 -> V_219 = F_24 ( sizeof( struct V_288 * ) * V_408 ,
V_158 ) ;
if ( ! V_5 -> V_219 ) {
V_114 = - V_113 ;
goto V_112;
}
V_5 -> V_246 = F_24 ( sizeof( struct V_13 * ) * V_408 ,
V_158 ) ;
if ( ! V_5 -> V_246 ) {
V_114 = - V_113 ;
goto V_112;
}
V_5 -> V_216 = V_312 -> V_216 ;
V_5 -> V_418 = ( V_82 -> V_2 -> V_135 . V_419 == 64 ) ? 1 : 0 ;
V_5 -> V_420 = - 1 ;
V_5 -> V_421 = V_422 ;
F_235 ( & V_5 -> V_227 ) ;
F_25 ( & V_5 -> V_192 , F_110 ) ;
F_25 ( & V_5 -> V_225 , F_179 ) ;
F_25 ( & V_5 -> V_282 , F_130 ) ;
F_236 ( & V_5 -> V_274 , F_124 ) ;
F_236 ( & V_5 -> V_278 , F_128 ) ;
#ifdef F_155
F_25 ( & V_5 -> V_402 , F_224 ) ;
F_25 ( & V_5 -> V_404 , F_226 ) ;
#endif
#ifdef F_237
if ( ! F_238 ( V_5 -> V_82 -> V_2 ) ) {
if ( V_82 -> V_2 -> V_135 . V_167 & V_423 ) {
V_2 -> V_424 = & V_425 ;
} else {
F_131 ( V_5 , L_90 ) ;
V_2 -> V_424 = & V_426 ;
}
}
#endif
for ( V_6 = 0 ; V_6 < V_165 ; ++ V_6 )
F_239 ( & V_5 -> V_161 [ V_6 ] ) ;
V_5 -> V_296 = V_82 -> V_2 -> V_135 . V_427 [ V_5 -> V_64 ] ;
V_2 -> V_428 = V_78 ;
F_57 ( V_2 -> V_77 , V_82 -> V_2 -> V_135 . V_429 [ V_5 -> V_64 ] ) ;
if ( ! F_83 ( V_2 -> V_77 ) ) {
if ( F_238 ( V_5 -> V_82 -> V_2 ) ) {
F_240 ( V_2 ) ;
F_15 ( V_5 , L_91 , V_2 -> V_77 ) ;
V_390 = F_65 ( V_2 -> V_77 ) ;
V_82 -> V_2 -> V_135 . V_429 [ V_5 -> V_64 ] = V_390 ;
} else {
F_18 ( V_5 , L_92 ,
V_5 -> V_64 , V_2 -> V_77 ) ;
V_114 = - V_9 ;
goto V_112;
}
}
memcpy ( V_5 -> V_170 , V_2 -> V_77 , sizeof( V_5 -> V_170 ) ) ;
V_5 -> V_336 = F_241 ( sizeof( struct V_430 ) +
V_431 * V_432 ) ;
V_114 = F_189 ( V_5 ) ;
if ( V_114 )
goto V_112;
#ifdef F_184
F_59 ( & V_5 -> V_94 ) ;
F_235 ( & V_5 -> V_111 ) ;
#endif
V_5 -> V_355 . V_167 = 0 ;
V_5 -> V_355 . V_359 = V_360 ;
V_5 -> V_355 . V_363 = V_364 ;
V_114 = F_242 ( V_82 -> V_2 , & V_5 -> V_347 ,
V_348 , V_348 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_93 ) ;
goto V_112;
}
V_5 -> V_346 = 1 ;
if ( F_243 ( V_5 -> V_82 -> V_2 ) )
V_2 -> V_433 = & V_434 ;
else
V_2 -> V_433 = & V_435 ;
V_2 -> V_436 = V_437 ;
F_232 ( V_2 , V_5 -> V_218 ) ;
F_233 ( V_2 , V_5 -> V_216 ) ;
V_2 -> V_438 = & V_439 ;
V_2 -> V_440 = V_441 | V_442 | V_443 ;
if ( V_82 -> V_444 )
V_2 -> V_440 |= V_445 | V_446 ;
V_2 -> V_447 = V_2 -> V_440 ;
V_2 -> V_440 |= V_448 | V_449 ;
V_2 -> V_384 = V_2 -> V_440 | V_450 |
V_451 | V_452 |
V_453 ;
V_2 -> V_440 |= V_385 ;
if ( V_82 -> V_2 -> V_135 . V_142 ==
V_148 )
V_2 -> V_440 |= V_454 ;
if ( V_82 -> V_2 -> V_135 . V_142 != V_153 )
V_2 -> V_213 |= V_214 ;
if ( V_82 -> V_2 -> V_135 . V_136 == V_137 ) {
V_2 -> V_455 |= V_442 | V_448 |
V_445 | V_456 ;
V_2 -> V_440 |= V_456 ;
V_2 -> V_384 |= V_456 ;
}
V_82 -> V_349 [ V_64 ] = V_2 ;
F_132 ( V_2 ) ;
F_121 ( V_5 ) ;
V_114 = F_244 ( V_2 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_94 , V_64 ) ;
goto V_112;
}
V_5 -> V_345 = 1 ;
F_15 ( V_5 , L_95 , V_312 -> V_218 ) ;
F_15 ( V_5 , L_96 , V_312 -> V_216 ) ;
F_212 ( V_5 -> V_2 , V_5 -> V_2 -> V_384 ) ;
F_140 ( V_2 ) ;
V_114 = F_150 ( V_82 -> V_2 , V_5 -> V_64 ,
V_5 -> V_297 + V_311 ,
V_312 -> V_313 , V_312 -> V_314 ,
V_312 -> V_315 , V_312 -> V_316 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_66 ,
V_5 -> V_64 , V_114 ) ;
goto V_112;
}
if ( V_82 -> V_2 -> V_135 . V_136 == V_137 ) {
V_114 = F_151 ( V_82 -> V_2 , V_5 -> V_64 , V_317 , 1 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_68 ,
V_114 ) ;
goto V_112;
}
}
F_15 ( V_5 , L_69 ) ;
V_114 = F_152 ( V_82 -> V_2 , V_5 -> V_64 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_70 ) ;
goto V_112;
}
F_127 ( V_82 -> V_115 , & V_5 -> V_274 , V_275 ) ;
if ( V_82 -> V_2 -> V_135 . V_279 & V_280 )
F_127 ( V_82 -> V_115 , & V_5 -> V_278 ,
V_281 ) ;
return 0 ;
V_112:
F_196 ( V_2 ) ;
return V_114 ;
}
