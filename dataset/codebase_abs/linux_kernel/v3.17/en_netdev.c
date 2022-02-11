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
if ( V_5 -> V_82 -> V_2 -> V_130 . V_131 != V_132 )
return 0 ;
V_114 = F_59 ( V_5 -> V_82 -> V_2 , V_129 , V_5 -> V_64 , V_71 ,
V_133 , V_81 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_8 , V_114 ) ;
return V_114 ;
}
F_48 ( V_134 , V_5 , L_9 , V_129 , * V_81 ) ;
return 0 ;
}
static int F_60 ( struct V_4 * V_5 ,
unsigned char * V_135 , int * V_71 , T_5 * V_81 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_136 * V_2 = V_82 -> V_2 ;
int V_114 ;
switch ( V_2 -> V_130 . V_137 ) {
case V_138 : {
struct V_139 V_140 ;
T_1 V_141 [ 16 ] = { 0 } ;
V_140 . V_71 = * V_71 ;
memcpy ( & V_141 [ 10 ] , V_135 , V_78 ) ;
V_141 [ 5 ] = V_5 -> V_64 ;
V_114 = F_61 ( V_2 , & V_140 , V_141 , 0 , V_142 ) ;
break;
}
case V_143 : {
struct V_35 V_53 = { { NULL } } ;
T_2 V_68 = F_14 ( V_69 << 16 ) ;
struct V_55 V_56 = {
. V_58 = V_144 ,
. V_60 = 0 ,
. V_61 = 1 ,
. V_62 = V_63 ,
. V_65 = V_133 ,
} ;
V_56 . V_64 = V_5 -> V_64 ;
V_56 . V_71 = * V_71 ;
F_62 ( & V_56 . V_57 ) ;
V_53 . V_37 = V_54 ;
memcpy ( V_53 . V_75 . V_76 , V_135 , V_78 ) ;
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
unsigned char * V_135 , int V_71 , T_5 V_81 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_136 * V_2 = V_82 -> V_2 ;
switch ( V_2 -> V_130 . V_137 ) {
case V_138 : {
struct V_139 V_140 ;
T_1 V_141 [ 16 ] = { 0 } ;
V_140 . V_71 = V_71 ;
memcpy ( & V_141 [ 10 ] , V_135 , V_78 ) ;
V_141 [ 5 ] = V_5 -> V_64 ;
F_64 ( V_2 , & V_140 , V_141 , V_142 ) ;
break;
}
case V_143 : {
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
struct V_136 * V_2 = V_82 -> V_2 ;
struct V_145 * V_146 ;
int V_147 = 0 ;
int V_114 = 0 ;
T_5 V_81 ;
int * V_71 = & V_5 -> V_148 ;
T_5 V_135 = F_66 ( V_5 -> V_2 -> V_77 ) ;
F_48 ( V_134 , V_5 , L_12 ,
V_5 -> V_2 -> V_77 ) ;
V_147 = F_67 ( V_2 , V_5 -> V_64 , V_135 ) ;
if ( V_147 < 0 ) {
V_114 = V_147 ;
F_18 ( V_5 , L_13 ,
V_5 -> V_2 -> V_77 ) ;
return V_114 ;
}
if ( V_2 -> V_130 . V_137 == V_149 ) {
int V_148 = F_68 ( V_2 , V_5 -> V_64 ) ;
* V_71 = V_148 + V_147 ;
return 0 ;
}
V_114 = F_69 ( V_2 , 1 , 1 , V_71 ) ;
F_48 ( V_134 , V_5 , L_14 , * V_71 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_15 ) ;
goto V_150;
}
V_114 = F_60 ( V_5 , V_5 -> V_2 -> V_77 , V_71 , & V_81 ) ;
if ( V_114 )
goto V_151;
V_114 = F_58 ( V_5 , V_5 -> V_2 -> V_77 , * V_71 ,
& V_5 -> V_152 ) ;
if ( V_114 )
goto V_153;
V_146 = F_70 ( sizeof( * V_146 ) , V_154 ) ;
if ( ! V_146 ) {
V_114 = - V_113 ;
goto V_155;
}
memcpy ( V_146 -> V_135 , V_5 -> V_2 -> V_77 , sizeof( V_146 -> V_135 ) ) ;
memcpy ( V_5 -> V_156 , V_146 -> V_135 , sizeof( V_5 -> V_156 ) ) ;
V_146 -> V_81 = V_81 ;
F_71 ( & V_146 -> V_157 ,
& V_5 -> V_158 [ V_146 -> V_135 [ V_159 ] ] ) ;
return 0 ;
V_155:
if ( V_5 -> V_152 )
F_17 ( V_5 -> V_82 -> V_2 , V_5 -> V_152 ) ;
V_153:
F_63 ( V_5 , V_5 -> V_2 -> V_77 , * V_71 , V_81 ) ;
V_151:
F_72 ( V_2 , * V_71 , 1 ) ;
V_150:
F_73 ( V_2 , V_5 -> V_64 , V_135 ) ;
return V_114 ;
}
static void F_74 ( struct V_4 * V_5 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_136 * V_2 = V_82 -> V_2 ;
int V_71 = V_5 -> V_148 ;
T_5 V_135 ;
if ( V_2 -> V_130 . V_137 == V_149 ) {
V_135 = F_66 ( V_5 -> V_2 -> V_77 ) ;
F_48 ( V_134 , V_5 , L_16 ,
V_5 -> V_2 -> V_77 ) ;
F_73 ( V_2 , V_5 -> V_64 , V_135 ) ;
} else {
struct V_145 * V_146 ;
struct V_160 * V_116 ;
struct V_84 * V_161 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_162 ; ++ V_6 ) {
V_161 = & V_5 -> V_158 [ V_6 ] ;
F_75 (entry, tmp, bucket, hlist) {
V_135 = F_66 ( V_146 -> V_135 ) ;
F_48 ( V_134 , V_5 , L_16 ,
V_146 -> V_135 ) ;
F_63 ( V_5 , V_146 -> V_135 ,
V_71 , V_146 -> V_81 ) ;
F_73 ( V_2 , V_5 -> V_64 , V_135 ) ;
F_76 ( & V_146 -> V_157 ) ;
F_77 ( V_146 , V_163 ) ;
}
}
if ( V_5 -> V_152 ) {
F_17 ( V_5 -> V_82 -> V_2 , V_5 -> V_152 ) ;
V_5 -> V_152 = 0 ;
}
F_48 ( V_134 , V_5 , L_17 ,
V_5 -> V_64 , V_71 ) ;
F_72 ( V_2 , V_71 , 1 ) ;
V_5 -> V_164 &= ~ V_165 ;
}
}
static int F_78 ( struct V_4 * V_5 , int V_71 ,
unsigned char * V_166 , unsigned char * V_167 )
{
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_136 * V_2 = V_82 -> V_2 ;
int V_114 = 0 ;
T_5 V_168 = F_66 ( V_166 ) ;
if ( V_2 -> V_130 . V_137 != V_149 ) {
struct V_84 * V_161 ;
unsigned int V_158 ;
struct V_145 * V_146 ;
struct V_160 * V_116 ;
T_5 V_169 = F_66 ( V_167 ) ;
V_161 = & V_5 -> V_158 [ V_167 [ V_159 ] ] ;
F_75 (entry, tmp, bucket, hlist) {
if ( F_79 ( V_146 -> V_135 , V_167 ) ) {
F_63 ( V_5 , V_146 -> V_135 ,
V_71 , V_146 -> V_81 ) ;
F_73 ( V_2 , V_5 -> V_64 ,
V_169 ) ;
F_76 ( & V_146 -> V_157 ) ;
F_80 () ;
memcpy ( V_146 -> V_135 , V_166 , V_78 ) ;
V_146 -> V_81 = 0 ;
V_158 = V_166 [ V_159 ] ;
F_71 ( & V_146 -> V_157 ,
& V_5 -> V_158 [ V_158 ] ) ;
F_67 ( V_2 , V_5 -> V_64 , V_168 ) ;
V_114 = F_60 ( V_5 , V_166 ,
& V_71 ,
& V_146 -> V_81 ) ;
if ( V_114 )
return V_114 ;
if ( V_5 -> V_152 ) {
F_17 ( V_5 -> V_82 -> V_2 , V_5 -> V_152 ) ;
V_5 -> V_152 = 0 ;
}
V_114 = F_58 ( V_5 , V_166 , V_71 ,
& V_5 -> V_152 ) ;
return V_114 ;
}
}
return - V_9 ;
}
return F_81 ( V_2 , V_5 -> V_64 , V_71 , V_168 ) ;
}
static int F_82 ( struct V_4 * V_5 ,
unsigned char V_166 [ V_78 + 2 ] )
{
int V_114 = 0 ;
if ( V_5 -> V_19 ) {
V_114 = F_78 ( V_5 , V_5 -> V_148 ,
V_166 , V_5 -> V_156 ) ;
if ( V_114 )
F_18 ( V_5 , L_18 ) ;
} else
F_48 ( V_124 , V_5 , L_19 ) ;
if ( ! V_114 )
memcpy ( V_5 -> V_156 , V_166 , sizeof( V_5 -> V_156 ) ) ;
return V_114 ;
}
static int F_83 ( struct V_1 * V_2 , void * V_129 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_170 * V_109 = V_129 ;
unsigned char V_166 [ V_78 + 2 ] ;
int V_114 ;
if ( ! F_84 ( V_109 -> V_171 ) )
return - V_172 ;
F_50 ( & V_82 -> V_126 ) ;
memcpy ( V_166 , V_109 -> V_171 , V_78 ) ;
V_114 = F_82 ( V_5 , V_166 ) ;
if ( ! V_114 )
memcpy ( V_2 -> V_77 , V_109 -> V_171 , V_78 ) ;
F_53 ( & V_82 -> V_126 ) ;
return V_114 ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_173 * V_116 , * V_174 ;
F_41 (mc_to_del, tmp, &priv->mc_list, list) {
F_28 ( & V_174 -> V_57 ) ;
F_29 ( V_174 ) ;
}
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_175 * V_176 ;
struct V_173 * V_116 ;
F_85 ( V_2 ) ;
F_87 (ha, dev) {
V_116 = F_24 ( sizeof( struct V_173 ) , V_90 ) ;
if ( ! V_116 ) {
F_85 ( V_2 ) ;
return;
}
memcpy ( V_116 -> V_129 , V_176 -> V_129 , V_78 ) ;
F_16 ( & V_116 -> V_57 , & V_5 -> V_177 ) ;
}
}
static void F_88 ( struct V_4 * V_5 ,
struct V_178 * V_179 ,
struct V_178 * V_180 )
{
struct V_173 * V_181 , * V_182 , * V_183 ;
bool V_184 ;
F_89 (dst_tmp, dst, list) {
V_184 = false ;
F_89 (src_tmp, src, list) {
if ( F_90 ( V_181 -> V_129 , V_182 -> V_129 ) ) {
V_184 = true ;
break;
}
}
if ( ! V_184 )
V_181 -> V_185 = V_186 ;
}
F_89 (src_tmp, src, list) {
V_184 = false ;
F_89 (dst_tmp, dst, list) {
if ( F_90 ( V_181 -> V_129 , V_182 -> V_129 ) ) {
V_181 -> V_185 = V_187 ;
V_184 = true ;
break;
}
}
if ( ! V_184 ) {
V_183 = F_91 ( V_182 ,
sizeof( struct V_173 ) ,
V_154 ) ;
if ( ! V_183 )
return;
V_183 -> V_185 = V_188 ;
F_16 ( & V_183 -> V_57 , V_179 ) ;
}
}
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_19 )
return;
F_37 ( V_5 -> V_82 -> V_115 , & V_5 -> V_189 ) ;
}
static void F_93 ( struct V_4 * V_5 ,
struct V_122 * V_82 )
{
int V_114 = 0 ;
if ( ! ( V_5 -> V_164 & V_190 ) ) {
if ( F_94 ( V_5 ) )
F_15 ( V_5 , L_20 ) ;
V_5 -> V_164 |= V_190 ;
switch ( V_82 -> V_2 -> V_130 . V_137 ) {
case V_143 :
V_114 = F_95 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_148 ,
V_191 ) ;
if ( V_114 )
F_18 ( V_5 , L_21 ) ;
V_5 -> V_164 |= V_192 ;
break;
case V_138 :
V_114 = F_96 ( V_82 -> V_2 ,
V_5 -> V_148 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_22 ) ;
if ( ! ( V_5 -> V_164 & V_192 ) ) {
V_114 = F_97 ( V_82 -> V_2 ,
V_5 -> V_148 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_23 ) ;
V_5 -> V_164 |= V_192 ;
}
break;
case V_149 :
V_114 = F_98 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_148 ,
1 ) ;
if ( V_114 )
F_18 ( V_5 , L_21 ) ;
break;
}
V_114 = F_99 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_193 ) ;
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
V_5 -> V_164 &= ~ V_190 ;
switch ( V_82 -> V_2 -> V_130 . V_137 ) {
case V_143 :
V_114 = F_101 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_191 ) ;
if ( V_114 )
F_18 ( V_5 , L_26 ) ;
V_5 -> V_164 &= ~ V_192 ;
break;
case V_138 :
V_114 = F_102 ( V_82 -> V_2 ,
V_5 -> V_148 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_27 ) ;
if ( V_5 -> V_164 & V_192 ) {
V_114 = F_103 ( V_82 -> V_2 ,
V_5 -> V_148 ,
V_5 -> V_64 ) ;
if ( V_114 )
F_18 ( V_5 , L_28 ) ;
V_5 -> V_164 &= ~ V_192 ;
}
break;
case V_149 :
V_114 = F_98 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_148 , 0 ) ;
if ( V_114 )
F_18 ( V_5 , L_26 ) ;
break;
}
}
static void F_104 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_122 * V_82 )
{
struct V_173 * V_194 , * V_116 ;
T_5 V_195 = 0 ;
T_1 V_177 [ 16 ] = { 0 } ;
int V_114 = 0 ;
if ( V_2 -> V_164 & V_196 ) {
V_114 = F_99 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_193 ) ;
if ( V_114 )
F_18 ( V_5 , L_24 ) ;
if ( ! ( V_5 -> V_164 & V_192 ) ) {
switch ( V_82 -> V_2 -> V_130 . V_137 ) {
case V_143 :
V_114 = F_95 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_5 -> V_148 ,
V_197 ) ;
break;
case V_138 :
V_114 = F_97 ( V_82 -> V_2 ,
V_5 -> V_148 ,
V_5 -> V_64 ) ;
break;
case V_149 :
break;
}
if ( V_114 )
F_18 ( V_5 , L_29 ) ;
V_5 -> V_164 |= V_192 ;
}
} else {
if ( V_5 -> V_164 & V_192 ) {
switch ( V_82 -> V_2 -> V_130 . V_137 ) {
case V_143 :
V_114 = F_101 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_197 ) ;
break;
case V_138 :
V_114 = F_103 ( V_82 -> V_2 ,
V_5 -> V_148 ,
V_5 -> V_64 ) ;
break;
case V_149 :
break;
}
if ( V_114 )
F_18 ( V_5 , L_28 ) ;
V_5 -> V_164 &= ~ V_192 ;
}
V_114 = F_99 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_193 ) ;
if ( V_114 )
F_18 ( V_5 , L_24 ) ;
F_99 ( V_82 -> V_2 , V_5 -> V_64 , V_198 ,
1 , V_199 ) ;
F_105 ( V_2 ) ;
F_86 ( V_2 ) ;
F_106 ( V_2 ) ;
F_89 (mclist, &priv->mc_list, list) {
V_195 = F_66 ( V_194 -> V_129 ) ;
F_99 ( V_82 -> V_2 , V_5 -> V_64 ,
V_195 , 0 , V_199 ) ;
}
V_114 = F_99 ( V_82 -> V_2 , V_5 -> V_64 , 0 ,
0 , V_200 ) ;
if ( V_114 )
F_18 ( V_5 , L_30 ) ;
F_88 ( V_5 , & V_5 -> V_201 , & V_5 -> V_177 ) ;
F_41 (mclist, tmp, &priv->curr_list, list) {
if ( V_194 -> V_185 == V_186 ) {
memcpy ( & V_177 [ 10 ] , V_194 -> V_129 , V_78 ) ;
V_177 [ 5 ] = V_5 -> V_64 ;
V_114 = F_107 ( V_82 -> V_2 ,
& V_5 -> V_72 . V_202 ,
V_177 ,
V_142 ,
V_194 -> V_81 ) ;
if ( V_114 )
F_18 ( V_5 , L_31 ) ;
if ( V_194 -> V_152 ) {
V_114 = F_17 ( V_5 -> V_82 -> V_2 , V_194 -> V_152 ) ;
if ( V_114 )
F_18 ( V_5 , L_32 ) ;
}
F_28 ( & V_194 -> V_57 ) ;
F_29 ( V_194 ) ;
} else if ( V_194 -> V_185 == V_188 ) {
memcpy ( & V_177 [ 10 ] , V_194 -> V_129 , V_78 ) ;
V_177 [ 5 ] = V_5 -> V_64 ;
V_114 = F_108 ( V_82 -> V_2 ,
& V_5 -> V_72 . V_202 ,
V_177 ,
V_5 -> V_64 , 0 ,
V_142 ,
& V_194 -> V_81 ) ;
if ( V_114 )
F_18 ( V_5 , L_33 ) ;
V_114 = F_58 ( V_5 , & V_177 [ 10 ] , V_5 -> V_148 ,
& V_194 -> V_152 ) ;
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
struct V_175 * V_176 ;
struct V_145 * V_146 ;
struct V_160 * V_116 ;
bool V_184 ;
T_5 V_135 ;
int V_114 = 0 ;
struct V_84 * V_161 ;
unsigned int V_6 ;
int V_203 = 0 ;
T_3 V_204 ;
for ( V_6 = 0 ; V_6 < V_162 ; ++ V_6 ) {
V_161 = & V_5 -> V_158 [ V_6 ] ;
F_75 (entry, tmp, bucket, hlist) {
V_184 = false ;
F_110 (ha, dev) {
if ( F_79 ( V_146 -> V_135 ,
V_176 -> V_129 ) ) {
V_184 = true ;
break;
}
}
if ( F_79 ( V_146 -> V_135 ,
V_5 -> V_156 ) )
V_184 = true ;
if ( ! V_184 ) {
V_135 = F_66 ( V_146 -> V_135 ) ;
F_63 ( V_5 , V_146 -> V_135 ,
V_5 -> V_148 ,
V_146 -> V_81 ) ;
F_73 ( V_82 -> V_2 , V_5 -> V_64 , V_135 ) ;
F_76 ( & V_146 -> V_157 ) ;
F_77 ( V_146 , V_163 ) ;
F_48 ( V_134 , V_5 , L_35 ,
V_146 -> V_135 , V_5 -> V_64 ) ;
++ V_203 ;
}
}
}
if ( ( V_5 -> V_164 & V_165 ) && 0 == V_203 )
return;
V_204 = V_5 -> V_164 ;
V_5 -> V_164 &= ~ V_165 ;
F_110 (ha, dev) {
V_184 = false ;
V_161 = & V_5 -> V_158 [ V_176 -> V_129 [ V_159 ] ] ;
F_31 (entry, bucket, hlist) {
if ( F_79 ( V_146 -> V_135 , V_176 -> V_129 ) ) {
V_184 = true ;
break;
}
}
if ( ! V_184 ) {
V_146 = F_70 ( sizeof( * V_146 ) , V_154 ) ;
if ( ! V_146 ) {
F_18 ( V_5 , L_36 ,
V_176 -> V_129 , V_5 -> V_64 ) ;
V_5 -> V_164 |= V_165 ;
break;
}
V_135 = F_66 ( V_176 -> V_129 ) ;
memcpy ( V_146 -> V_135 , V_176 -> V_129 , V_78 ) ;
V_114 = F_67 ( V_82 -> V_2 , V_5 -> V_64 , V_135 ) ;
if ( V_114 < 0 ) {
F_18 ( V_5 , L_37 ,
V_176 -> V_129 , V_5 -> V_64 , V_114 ) ;
F_29 ( V_146 ) ;
V_5 -> V_164 |= V_165 ;
break;
}
V_114 = F_60 ( V_5 , V_176 -> V_129 ,
& V_5 -> V_148 ,
& V_146 -> V_81 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_38 ,
V_176 -> V_129 , V_5 -> V_64 , V_114 ) ;
F_73 ( V_82 -> V_2 , V_5 -> V_64 , V_135 ) ;
F_29 ( V_146 ) ;
V_5 -> V_164 |= V_165 ;
break;
} else {
unsigned int V_158 ;
F_48 ( V_134 , V_5 , L_39 ,
V_176 -> V_129 , V_5 -> V_64 ) ;
V_158 = V_176 -> V_129 [ V_159 ] ;
V_161 = & V_5 -> V_158 [ V_158 ] ;
F_71 ( & V_146 -> V_157 , V_161 ) ;
}
}
}
if ( V_5 -> V_164 & V_165 ) {
F_15 ( V_5 , L_40 ,
V_5 -> V_64 ) ;
} else if ( V_204 & V_165 ) {
F_15 ( V_5 , L_41 ,
V_5 -> V_64 ) ;
}
}
static void F_111 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_189 ) ;
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
if ( V_5 -> V_205 . V_206 ) {
V_5 -> V_207 = V_208 ;
F_114 ( V_2 ) ;
F_48 ( V_209 , V_5 , L_44 ) ;
}
}
}
if ( V_2 -> V_210 & V_211 )
F_109 ( V_5 , V_2 , V_82 ) ;
if ( ( V_2 -> V_164 & V_212 ) ||
( V_5 -> V_164 & V_165 ) ) {
F_93 ( V_5 , V_82 ) ;
goto V_112;
}
if ( V_5 -> V_164 & V_190 )
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
for ( V_6 = 0 ; V_6 < V_5 -> V_213 ; V_6 ++ ) {
V_14 = V_5 -> V_214 [ V_6 ] ;
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
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
if ( ! F_119 ( F_120 ( V_2 , V_6 ) ) )
continue;
F_15 ( V_5 , L_46 ,
V_6 , V_5 -> V_216 [ V_6 ] -> V_71 , V_5 -> V_216 [ V_6 ] -> V_217 ,
V_5 -> V_216 [ V_6 ] -> V_218 , V_5 -> V_216 [ V_6 ] -> V_219 ) ;
}
V_5 -> V_220 . V_221 ++ ;
F_48 ( V_134 , V_5 , L_47 ) ;
F_37 ( V_82 -> V_115 , & V_5 -> V_222 ) ;
}
static struct V_223 * F_121 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_36 ( & V_5 -> V_224 ) ;
memcpy ( & V_5 -> V_225 , & V_5 -> V_226 , sizeof( V_5 -> V_226 ) ) ;
F_38 ( & V_5 -> V_224 ) ;
return & V_5 -> V_225 ;
}
static void F_122 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
int V_6 ;
V_5 -> V_227 = V_228 ;
V_5 -> V_229 = V_230 ;
V_5 -> V_231 = V_232 ;
V_5 -> V_233 = V_234 ;
F_48 ( V_235 , V_5 , L_48 ,
V_5 -> V_2 -> V_236 , V_5 -> V_227 , V_5 -> V_229 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_213 ; V_6 ++ ) {
V_14 = V_5 -> V_214 [ V_6 ] ;
V_14 -> V_237 = V_5 -> V_227 ;
V_14 -> V_238 = V_5 -> V_229 ;
V_5 -> V_239 [ V_6 ] = V_240 ;
V_5 -> V_241 [ V_6 ] = 0 ;
V_5 -> V_242 [ V_6 ] = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
V_14 = V_5 -> V_243 [ V_6 ] ;
V_14 -> V_237 = V_5 -> V_231 ;
V_14 -> V_238 = V_5 -> V_233 ;
}
V_5 -> V_244 = V_245 ;
V_5 -> V_246 = V_247 ;
V_5 -> V_248 = V_249 ;
V_5 -> V_250 = V_251 ;
V_5 -> V_252 = V_253 ;
V_5 -> V_254 = 1 ;
V_5 -> V_255 = 0 ;
V_5 -> V_256 = 0 ;
}
static void F_123 ( struct V_4 * V_5 )
{
unsigned long V_257 = ( unsigned long ) ( V_258 - V_5 -> V_255 ) ;
struct V_13 * V_14 ;
unsigned long V_259 ;
unsigned long V_260 ;
unsigned long V_261 ;
unsigned long V_262 ;
unsigned long V_263 ;
unsigned long V_264 ;
int V_238 ;
int V_17 , V_114 ;
if ( ! V_5 -> V_254 || V_257 < V_5 -> V_252 * V_265 )
return;
for ( V_17 = 0 ; V_17 < V_5 -> V_213 ; V_17 ++ ) {
F_36 ( & V_5 -> V_224 ) ;
V_262 = V_5 -> V_16 [ V_17 ] -> V_259 ;
V_263 = V_5 -> V_16 [ V_17 ] -> V_266 ;
F_38 ( & V_5 -> V_224 ) ;
V_264 = ( ( unsigned long ) ( V_262 -
V_5 -> V_241 [ V_17 ] ) ) ;
V_259 = V_264 ;
V_260 = V_259 * V_265 / V_257 ;
V_261 = V_259 ? ( ( unsigned long ) ( V_263 -
V_5 -> V_242 [ V_17 ] ) ) / V_259 : 0 ;
if ( V_260 > ( V_267 / V_5 -> V_213 ) &&
V_261 > V_268 ) {
if ( V_260 < V_5 -> V_244 )
V_238 = V_5 -> V_246 ;
else if ( V_260 > V_5 -> V_248 )
V_238 = V_5 -> V_250 ;
else
V_238 = ( V_260 - V_5 -> V_244 ) *
( V_5 -> V_250 - V_5 -> V_246 ) /
( V_5 -> V_248 - V_5 -> V_244 ) +
V_5 -> V_246 ;
} else {
V_238 = V_5 -> V_246 ;
}
if ( V_238 != V_5 -> V_239 [ V_17 ] ) {
V_5 -> V_239 [ V_17 ] = V_238 ;
V_14 = V_5 -> V_214 [ V_17 ] ;
V_14 -> V_238 = V_238 ;
V_14 -> V_237 = V_5 -> V_227 ;
V_114 = F_124 ( V_5 , V_14 ) ;
if ( V_114 )
F_18 ( V_5 , L_49 ,
V_17 ) ;
}
V_5 -> V_241 [ V_17 ] = V_262 ;
V_5 -> V_242 [ V_17 ] = V_263 ;
}
V_5 -> V_255 = V_258 ;
}
static void F_125 ( struct V_31 * V_32 )
{
struct V_269 * V_270 = F_126 ( V_32 ) ;
struct V_4 * V_5 = F_6 ( V_270 , struct V_4 ,
V_271 ) ;
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
F_128 ( V_82 -> V_115 , & V_5 -> V_271 , V_272 ) ;
}
if ( V_82 -> V_273 [ V_274 + 1 - V_5 -> V_64 ] ) {
F_82 ( V_5 , V_5 -> V_156 ) ;
V_82 -> V_273 [ V_274 + 1 - V_5 -> V_64 ] = 0 ;
}
F_53 ( & V_82 -> V_126 ) ;
}
static void F_129 ( struct V_31 * V_32 )
{
struct V_269 * V_270 = F_126 ( V_32 ) ;
struct V_4 * V_5 = F_6 ( V_270 , struct V_4 ,
V_275 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_82 -> V_127 ) {
if ( V_82 -> V_2 -> V_130 . V_276 & V_277 )
F_130 ( V_82 ) ;
F_128 ( V_82 -> V_115 , & V_5 -> V_275 ,
V_278 ) ;
}
F_53 ( & V_82 -> V_126 ) ;
}
static void F_131 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_279 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_280 = V_5 -> V_206 ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_5 -> V_207 != V_280 ) {
if ( V_280 == V_281 ) {
F_132 ( V_5 , L_51 ) ;
F_133 ( V_5 -> V_2 ) ;
} else {
F_132 ( V_5 , L_44 ) ;
F_114 ( V_5 -> V_2 ) ;
}
}
V_5 -> V_207 = V_280 ;
F_53 ( & V_82 -> V_126 ) ;
}
static int F_134 ( struct V_4 * V_5 , int V_282 )
{
struct V_15 * V_17 = V_5 -> V_16 [ V_282 ] ;
int V_283 = V_5 -> V_82 -> V_2 -> V_283 ;
int V_96 = 0 ;
if ( ! F_135 ( & V_17 -> V_284 , V_154 ) )
return - V_113 ;
V_96 = F_136 ( V_282 , V_283 ,
V_17 -> V_284 ) ;
if ( V_96 )
F_137 ( V_17 -> V_284 ) ;
return V_96 ;
}
static void F_138 ( struct V_4 * V_5 , int V_282 )
{
F_137 ( V_5 -> V_16 [ V_282 ] -> V_284 ) ;
}
int F_139 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_13 * V_14 ;
struct V_285 * V_216 ;
int V_286 = 0 ;
int V_287 = 0 ;
int V_114 = 0 ;
int V_6 ;
int V_288 ;
T_1 V_177 [ 16 ] = { 0 } ;
if ( V_5 -> V_19 ) {
F_48 ( V_134 , V_5 , L_52 ) ;
return 0 ;
}
F_62 ( & V_5 -> V_177 ) ;
F_62 ( & V_5 -> V_201 ) ;
F_62 ( & V_5 -> V_289 ) ;
memset ( & V_5 -> V_290 [ 0 ] , 0 ,
sizeof( struct V_291 ) * V_292 ) ;
V_2 -> V_236 = F_140 ( V_2 -> V_236 , V_5 -> V_293 ) ;
F_141 ( V_2 ) ;
F_48 ( V_134 , V_5 , L_53 , V_5 -> V_294 ) ;
V_114 = F_142 ( V_5 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_54 ) ;
return V_114 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_213 ; V_6 ++ ) {
V_14 = V_5 -> V_214 [ V_6 ] ;
F_143 ( V_14 ) ;
V_114 = F_134 ( V_5 , V_6 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_55 ) ;
goto V_295;
}
V_114 = F_144 ( V_5 , V_14 , V_6 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_56 ) ;
F_138 ( V_5 , V_6 ) ;
goto V_295;
}
for ( V_288 = 0 ; V_288 < V_14 -> V_296 ; V_288 ++ )
V_14 -> V_297 [ V_288 ] . V_298 = V_299 ;
V_114 = F_124 ( V_5 , V_14 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_57 ) ;
F_145 ( V_5 , V_14 ) ;
F_138 ( V_5 , V_6 ) ;
goto V_295;
}
F_146 ( V_5 , V_14 ) ;
V_5 -> V_16 [ V_6 ] -> V_217 = V_14 -> V_300 . V_217 ;
++ V_286 ;
}
F_48 ( V_134 , V_5 , L_58 , V_5 -> V_64 ) ;
V_114 = F_65 ( V_5 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_59 ) ;
goto V_295;
}
V_82 -> V_273 [ V_5 -> V_64 ] = 0 ;
V_114 = F_147 ( V_5 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_60 ) ;
goto V_301;
}
V_114 = F_148 ( V_5 ) ;
if ( V_114 )
goto V_302;
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
V_14 = V_5 -> V_243 [ V_6 ] ;
V_114 = F_144 ( V_5 , V_14 , V_6 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_61 ) ;
goto V_303;
}
V_114 = F_124 ( V_5 , V_14 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_57 ) ;
F_145 ( V_5 , V_14 ) ;
goto V_303;
}
F_48 ( V_134 , V_5 , L_62 , V_6 ) ;
V_14 -> V_297 -> V_304 = F_149 ( 0xffff ) ;
V_216 = V_5 -> V_216 [ V_6 ] ;
V_114 = F_150 ( V_5 , V_216 , V_14 -> V_300 . V_217 ,
V_6 / V_5 -> V_10 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_63 ) ;
F_145 ( V_5 , V_14 ) ;
goto V_303;
}
V_216 -> V_305 = F_120 ( V_2 , V_6 ) ;
F_146 ( V_5 , V_14 ) ;
for ( V_288 = 0 ; V_288 < V_216 -> V_306 ; V_288 += V_307 )
* ( ( T_3 * ) ( V_216 -> V_297 + V_288 ) ) = 0xffffffff ;
++ V_287 ;
}
V_114 = F_151 ( V_82 -> V_2 , V_5 -> V_64 ,
V_5 -> V_294 + V_308 ,
V_5 -> V_309 -> V_310 ,
V_5 -> V_309 -> V_311 ,
V_5 -> V_309 -> V_312 ,
V_5 -> V_309 -> V_313 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_64 ,
V_5 -> V_64 , V_114 ) ;
goto V_303;
}
V_114 = F_98 ( V_82 -> V_2 , V_5 -> V_64 , V_5 -> V_148 , 0 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_65 ) ;
goto V_303;
}
if ( V_82 -> V_2 -> V_130 . V_131 == V_132 ) {
V_114 = F_152 ( V_82 -> V_2 , V_5 -> V_64 , V_314 , 1 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_66 ,
V_114 ) ;
goto V_303;
}
}
F_48 ( V_124 , V_5 , L_67 ) ;
V_114 = F_153 ( V_82 -> V_2 , V_5 -> V_64 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_68 ) ;
goto V_303;
}
memset ( & V_177 [ 10 ] , 0xff , V_78 ) ;
V_177 [ 5 ] = V_5 -> V_64 ;
if ( F_108 ( V_82 -> V_2 , & V_5 -> V_72 . V_202 , V_177 ,
V_5 -> V_64 , 0 , V_142 ,
& V_5 -> V_315 ) )
F_154 ( V_82 , L_69 ) ;
V_5 -> V_164 &= ~ ( V_190 | V_192 ) ;
F_37 ( V_82 -> V_115 , & V_5 -> V_189 ) ;
F_155 ( V_82 -> V_2 , & V_5 -> V_316 ) ;
#ifdef F_156
if ( V_5 -> V_82 -> V_2 -> V_130 . V_276 & V_317 )
F_157 ( V_2 ) ;
#endif
V_5 -> V_19 = true ;
F_158 ( V_2 ) ;
F_159 ( V_2 ) ;
return 0 ;
V_303:
while ( V_287 -- ) {
F_160 ( V_5 , V_5 -> V_216 [ V_287 ] ) ;
F_145 ( V_5 , V_5 -> V_243 [ V_287 ] ) ;
}
F_161 ( V_5 ) ;
V_302:
F_162 ( V_5 ) ;
V_301:
F_74 ( V_5 ) ;
V_295:
while ( V_286 -- ) {
F_145 ( V_5 , V_5 -> V_214 [ V_286 ] ) ;
F_138 ( V_5 , V_6 ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_213 ; V_6 ++ )
F_163 ( V_5 , V_5 -> V_16 [ V_6 ] ) ;
return V_114 ;
}
void F_164 ( struct V_1 * V_2 , int V_318 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_173 * V_194 , * V_116 ;
struct V_291 * V_319 , * V_320 ;
int V_6 ;
T_1 V_177 [ 16 ] = { 0 } ;
if ( ! V_5 -> V_19 ) {
F_48 ( V_134 , V_5 , L_70 ) ;
return;
}
F_165 ( V_82 -> V_2 , V_5 -> V_64 ) ;
F_166 ( V_2 ) ;
if ( V_318 )
F_167 ( V_2 ) ;
F_168 ( V_2 ) ;
F_169 ( V_2 ) ;
F_170 ( V_2 ) ;
V_5 -> V_19 = false ;
if ( V_82 -> V_2 -> V_130 . V_137 ==
V_143 ) {
V_5 -> V_164 &= ~ ( V_190 |
V_192 ) ;
F_101 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_191 ) ;
F_101 ( V_82 -> V_2 ,
V_5 -> V_64 ,
V_197 ) ;
} else if ( V_5 -> V_164 & V_190 ) {
V_5 -> V_164 &= ~ V_190 ;
F_102 ( V_82 -> V_2 , V_5 -> V_148 ,
V_5 -> V_64 ) ;
if ( V_5 -> V_164 & V_192 ) {
F_103 ( V_82 -> V_2 , V_5 -> V_148 ,
V_5 -> V_64 ) ;
V_5 -> V_164 &= ~ V_192 ;
}
}
memset ( & V_177 [ 10 ] , 0xff , V_78 ) ;
V_177 [ 5 ] = V_5 -> V_64 ;
F_107 ( V_82 -> V_2 , & V_5 -> V_72 . V_202 , V_177 ,
V_142 , V_5 -> V_315 ) ;
F_89 (mclist, &priv->curr_list, list) {
memcpy ( & V_177 [ 10 ] , V_194 -> V_129 , V_78 ) ;
V_177 [ 5 ] = V_5 -> V_64 ;
F_107 ( V_82 -> V_2 , & V_5 -> V_72 . V_202 ,
V_177 , V_142 , V_194 -> V_81 ) ;
if ( V_194 -> V_152 )
F_17 ( V_82 -> V_2 , V_194 -> V_152 ) ;
}
F_85 ( V_2 ) ;
F_41 (mclist, tmp, &priv->curr_list, list) {
F_28 ( & V_194 -> V_57 ) ;
F_29 ( V_194 ) ;
}
F_99 ( V_82 -> V_2 , V_5 -> V_64 , 0 , 1 , V_199 ) ;
if ( V_82 -> V_2 -> V_130 . V_137 ==
V_143 ) {
F_171 () ;
F_41 (flow, tmp_flow,
&priv->ethtool_list, list) {
F_17 ( V_82 -> V_2 , V_319 -> V_37 ) ;
F_28 ( & V_319 -> V_57 ) ;
}
}
F_161 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
F_160 ( V_5 , V_5 -> V_216 [ V_6 ] ) ;
F_145 ( V_5 , V_5 -> V_243 [ V_6 ] ) ;
}
F_172 ( 10 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ )
F_173 ( V_2 , V_5 -> V_216 [ V_6 ] ) ;
F_162 ( V_5 ) ;
F_74 ( V_5 ) ;
if ( ! ( V_82 -> V_2 -> V_130 . V_276 & V_321 ) )
V_82 -> V_273 [ V_5 -> V_64 ] = 1 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_213 ; V_6 ++ ) {
struct V_13 * V_14 = V_5 -> V_214 [ V_6 ] ;
F_174 () ;
while ( ! F_175 ( V_14 ) ) {
F_176 ( L_71 , V_6 ) ;
F_177 ( 1 ) ;
}
F_178 () ;
while ( F_179 ( V_322 , & V_14 -> V_12 . V_323 ) )
F_172 ( 1 ) ;
F_163 ( V_5 , V_5 -> V_16 [ V_6 ] ) ;
F_145 ( V_5 , V_14 ) ;
F_138 ( V_5 , V_6 ) ;
}
}
static void F_180 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_222 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_48 ( V_134 , V_5 , L_72 , V_5 -> V_64 ) ;
F_50 ( & V_82 -> V_126 ) ;
if ( V_5 -> V_19 ) {
F_164 ( V_2 , 1 ) ;
if ( F_139 ( V_2 ) )
F_18 ( V_5 , L_73 , V_5 -> V_64 ) ;
}
F_53 ( & V_82 -> V_126 ) ;
}
static void F_181 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_6 ;
if ( F_127 ( V_82 , V_5 -> V_64 , 1 ) )
F_48 ( V_124 , V_5 , L_74 ) ;
memset ( & V_5 -> V_226 , 0 , sizeof( V_5 -> V_226 ) ) ;
memset ( & V_5 -> V_324 , 0 , sizeof( V_5 -> V_324 ) ) ;
memset ( & V_5 -> V_325 , 0 , sizeof( V_5 -> V_325 ) ) ;
memset ( & V_5 -> V_220 , 0 , sizeof( V_5 -> V_220 ) ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
V_5 -> V_216 [ V_6 ] -> V_266 = 0 ;
V_5 -> V_216 [ V_6 ] -> V_259 = 0 ;
V_5 -> V_216 [ V_6 ] -> V_326 = 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_213 ; V_6 ++ ) {
V_5 -> V_16 [ V_6 ] -> V_266 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_259 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_327 = 0 ;
V_5 -> V_16 [ V_6 ] -> V_328 = 0 ;
}
}
static int F_182 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_114 = 0 ;
F_50 ( & V_82 -> V_126 ) ;
if ( ! V_82 -> V_127 ) {
F_18 ( V_5 , L_75 ) ;
V_114 = - V_329 ;
goto V_112;
}
F_181 ( V_2 ) ;
V_114 = F_139 ( V_2 ) ;
if ( V_114 )
F_18 ( V_5 , L_76 , V_5 -> V_64 ) ;
V_112:
F_53 ( & V_82 -> V_126 ) ;
return V_114 ;
}
static int F_183 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
F_48 ( V_330 , V_5 , L_77 ) ;
F_50 ( & V_82 -> V_126 ) ;
F_164 ( V_2 , 0 ) ;
F_133 ( V_2 ) ;
F_53 ( & V_82 -> V_126 ) ;
return 0 ;
}
void F_184 ( struct V_4 * V_5 )
{
int V_6 ;
#ifdef F_185
F_186 ( V_5 -> V_2 -> V_331 ) ;
V_5 -> V_2 -> V_331 = NULL ;
#endif
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
if ( V_5 -> V_216 && V_5 -> V_216 [ V_6 ] )
F_187 ( V_5 , & V_5 -> V_216 [ V_6 ] ) ;
if ( V_5 -> V_243 && V_5 -> V_243 [ V_6 ] )
F_188 ( V_5 , & V_5 -> V_243 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_213 ; V_6 ++ ) {
if ( V_5 -> V_16 [ V_6 ] )
F_189 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_5 -> V_309 -> V_332 , V_5 -> V_333 ) ;
if ( V_5 -> V_214 [ V_6 ] )
F_188 ( V_5 , & V_5 -> V_214 [ V_6 ] ) ;
}
if ( V_5 -> V_334 ) {
F_72 ( V_5 -> V_82 -> V_2 , V_5 -> V_334 , V_5 -> V_215 ) ;
V_5 -> V_334 = 0 ;
}
}
int F_190 ( struct V_4 * V_5 )
{
struct V_335 * V_309 = V_5 -> V_309 ;
int V_6 ;
int V_114 ;
int V_336 ;
V_114 = F_69 ( V_5 -> V_82 -> V_2 , V_5 -> V_215 , 256 , & V_5 -> V_334 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_78 ) ;
return V_114 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
V_336 = F_191 ( V_6 % F_192 () ) ;
if ( F_193 ( V_5 , & V_5 -> V_243 [ V_6 ] ,
V_309 -> V_337 , V_6 , V_338 , V_336 ) )
goto V_114;
if ( F_194 ( V_5 , & V_5 -> V_216 [ V_6 ] ,
V_5 -> V_334 + V_6 ,
V_309 -> V_337 , V_339 ,
V_336 , V_6 ) )
goto V_114;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_213 ; V_6 ++ ) {
V_336 = F_191 ( V_6 % F_192 () ) ;
if ( F_193 ( V_5 , & V_5 -> V_214 [ V_6 ] ,
V_309 -> V_332 , V_6 , V_340 , V_336 ) )
goto V_114;
if ( F_195 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_309 -> V_332 , V_5 -> V_333 ,
V_336 ) )
goto V_114;
}
#ifdef F_185
if ( V_5 -> V_82 -> V_2 -> V_130 . V_341 ) {
V_5 -> V_2 -> V_331 = F_196 ( V_5 -> V_82 -> V_2 -> V_130 . V_341 ) ;
if ( ! V_5 -> V_2 -> V_331 )
goto V_114;
}
#endif
return 0 ;
V_114:
F_18 ( V_5 , L_79 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_213 ; V_6 ++ ) {
if ( V_5 -> V_16 [ V_6 ] )
F_189 ( V_5 , & V_5 -> V_16 [ V_6 ] ,
V_309 -> V_332 ,
V_5 -> V_333 ) ;
if ( V_5 -> V_214 [ V_6 ] )
F_188 ( V_5 , & V_5 -> V_214 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_215 ; V_6 ++ ) {
if ( V_5 -> V_216 [ V_6 ] )
F_187 ( V_5 , & V_5 -> V_216 [ V_6 ] ) ;
if ( V_5 -> V_243 [ V_6 ] )
F_188 ( V_5 , & V_5 -> V_243 [ V_6 ] ) ;
}
return - V_113 ;
}
void F_197 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
F_48 ( V_134 , V_5 , L_80 , V_5 -> V_64 ) ;
if ( V_5 -> V_342 )
F_198 ( V_2 ) ;
if ( V_5 -> V_343 )
F_199 ( V_82 -> V_2 , & V_5 -> V_344 , V_345 ) ;
F_200 ( & V_5 -> V_271 ) ;
F_200 ( & V_5 -> V_275 ) ;
F_201 ( V_82 -> V_115 ) ;
F_50 ( & V_82 -> V_126 ) ;
V_82 -> V_346 [ V_5 -> V_64 ] = NULL ;
F_53 ( & V_82 -> V_126 ) ;
F_184 ( V_5 ) ;
F_29 ( V_5 -> V_216 ) ;
F_29 ( V_5 -> V_243 ) ;
F_202 ( V_2 ) ;
}
static int F_203 ( struct V_1 * V_2 , int V_347 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
int V_114 = 0 ;
F_48 ( V_134 , V_5 , L_81 ,
V_2 -> V_236 , V_347 ) ;
if ( ( V_347 < V_348 ) || ( V_347 > V_5 -> V_293 ) ) {
F_18 ( V_5 , L_82 , V_347 ) ;
return - V_349 ;
}
V_2 -> V_236 = V_347 ;
if ( F_204 ( V_2 ) ) {
F_50 ( & V_82 -> V_126 ) ;
if ( ! V_82 -> V_127 ) {
F_48 ( V_134 , V_5 , L_83 ) ;
} else {
F_164 ( V_2 , 1 ) ;
V_114 = F_139 ( V_2 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_84 ,
V_5 -> V_64 ) ;
F_37 ( V_82 -> V_115 , & V_5 -> V_222 ) ;
}
}
F_53 ( & V_82 -> V_126 ) ;
}
return 0 ;
}
static int F_205 ( struct V_1 * V_2 , struct V_350 * V_351 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_5 -> V_82 ;
struct V_352 V_353 ;
if ( F_206 ( & V_353 , V_351 -> V_354 , sizeof( V_353 ) ) )
return - V_355 ;
if ( V_353 . V_164 )
return - V_9 ;
if ( ! ( V_82 -> V_2 -> V_130 . V_276 & V_277 ) )
return - V_9 ;
switch ( V_353 . V_356 ) {
case V_357 :
case V_358 :
break;
default:
return - V_359 ;
}
switch ( V_353 . V_360 ) {
case V_361 :
break;
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
case V_375 :
V_353 . V_360 = V_362 ;
break;
default:
return - V_359 ;
}
if ( F_207 ( V_2 , V_353 . V_356 , V_353 . V_360 ) ) {
V_353 . V_356 = V_357 ;
V_353 . V_360 = V_361 ;
}
return F_208 ( V_351 -> V_354 , & V_353 ,
sizeof( V_353 ) ) ? - V_355 : 0 ;
}
static int F_209 ( struct V_1 * V_2 , struct V_350 * V_351 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_208 ( V_351 -> V_354 , & V_5 -> V_352 ,
sizeof( V_5 -> V_352 ) ) ? - V_355 : 0 ;
}
static int F_210 ( struct V_1 * V_2 , struct V_350 * V_351 , int V_376 )
{
switch ( V_376 ) {
case V_377 :
return F_205 ( V_2 , V_351 ) ;
case V_378 :
return F_209 ( V_2 , V_351 ) ;
default:
return - V_379 ;
}
}
static int F_211 ( struct V_1 * V_380 ,
T_6 V_381 )
{
struct V_4 * V_5 = F_2 ( V_380 ) ;
if ( V_381 & V_382 )
V_5 -> V_383 |= F_212 ( V_384 ) ;
else
V_5 -> V_383 &=
F_212 ( ~ V_384 ) ;
F_213 ( V_380 , V_381 ) ;
return 0 ;
}
static int F_214 ( struct V_1 * V_2 , int V_385 , T_1 * V_135 )
{
struct V_4 * V_386 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_386 -> V_82 ;
T_5 V_387 = F_66 ( V_135 ) ;
if ( ! F_84 ( V_135 ) )
return - V_9 ;
return F_215 ( V_82 -> V_2 , V_386 -> V_64 , V_385 , V_387 ) ;
}
static int F_216 ( struct V_1 * V_2 , int V_388 , T_4 V_389 , T_1 V_390 )
{
struct V_4 * V_386 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_386 -> V_82 ;
return F_217 ( V_82 -> V_2 , V_386 -> V_64 , V_388 , V_389 , V_390 ) ;
}
static int F_218 ( struct V_1 * V_2 , int V_388 , bool V_391 )
{
struct V_4 * V_386 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_386 -> V_82 ;
return F_219 ( V_82 -> V_2 , V_386 -> V_64 , V_388 , V_391 ) ;
}
static int F_220 ( struct V_1 * V_2 , int V_388 , struct V_392 * V_393 )
{
struct V_4 * V_386 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_386 -> V_82 ;
return F_221 ( V_82 -> V_2 , V_386 -> V_64 , V_388 , V_393 ) ;
}
static int F_222 ( struct V_1 * V_2 , int V_388 , int V_206 )
{
struct V_4 * V_386 = F_2 ( V_2 ) ;
struct V_122 * V_82 = V_386 -> V_82 ;
return F_223 ( V_82 -> V_2 , V_386 -> V_64 , V_388 , V_206 ) ;
}
static int F_224 ( struct V_1 * V_2 ,
struct V_394 * V_395 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_136 * V_82 = V_5 -> V_82 -> V_2 ;
int V_6 ;
T_5 V_396 = V_82 -> V_130 . V_396 [ V_5 -> V_64 ] ;
if ( ! V_396 )
return - V_379 ;
V_395 -> V_397 = sizeof( V_396 ) ;
for ( V_6 = V_398 - 1 ; V_6 >= 0 ; -- V_6 ) {
V_395 -> V_37 [ V_6 ] = V_396 & 0xff ;
V_396 >>= 8 ;
}
return 0 ;
}
static void F_225 ( struct V_31 * V_32 )
{
int V_96 ;
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_399 ) ;
V_96 = F_226 ( V_5 -> V_82 -> V_2 , V_5 -> V_400 ) ;
if ( V_96 )
goto V_112;
V_96 = F_152 ( V_5 -> V_82 -> V_2 , V_5 -> V_64 ,
V_314 , 1 ) ;
V_112:
if ( V_96 )
F_18 ( V_5 , L_85 , V_96 ) ;
}
static void F_227 ( struct V_31 * V_32 )
{
int V_96 ;
struct V_4 * V_5 = F_6 ( V_32 , struct V_4 ,
V_401 ) ;
V_96 = F_152 ( V_5 -> V_82 -> V_2 , V_5 -> V_64 ,
V_314 , 0 ) ;
if ( V_96 )
F_18 ( V_5 , L_85 , V_96 ) ;
V_5 -> V_400 = 0 ;
}
static void F_228 ( struct V_1 * V_2 ,
T_7 V_402 , V_42 V_64 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_42 V_403 ;
if ( V_5 -> V_82 -> V_2 -> V_130 . V_131 != V_132 )
return;
if ( V_402 == V_404 )
return;
V_403 = V_5 -> V_400 ;
if ( V_403 && V_403 != V_64 ) {
F_15 ( V_5 , L_86 ,
F_229 ( V_403 ) , F_229 ( V_64 ) ) ;
return;
}
V_5 -> V_400 = V_64 ;
F_37 ( V_5 -> V_82 -> V_115 , & V_5 -> V_399 ) ;
}
static void F_230 ( struct V_1 * V_2 ,
T_7 V_402 , V_42 V_64 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_42 V_403 ;
if ( V_5 -> V_82 -> V_2 -> V_130 . V_131 != V_132 )
return;
if ( V_402 == V_404 )
return;
V_403 = V_5 -> V_400 ;
if ( V_403 != V_64 ) {
F_48 ( V_134 , V_5 , L_87 , F_229 ( V_64 ) ) ;
return;
}
F_37 ( V_5 -> V_82 -> V_115 , & V_5 -> V_401 ) ;
}
int F_231 ( struct V_122 * V_82 , int V_64 ,
struct V_335 * V_309 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_6 ;
int V_114 ;
T_5 V_387 ;
V_2 = F_232 ( sizeof( struct V_4 ) ,
V_405 , V_406 ) ;
if ( V_2 == NULL )
return - V_113 ;
F_233 ( V_2 , V_309 -> V_215 ) ;
F_234 ( V_2 , V_309 -> V_213 ) ;
F_235 ( V_2 , & V_82 -> V_2 -> V_407 -> V_2 ) ;
V_2 -> V_408 = V_64 - 1 ;
V_5 = F_2 ( V_2 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_82 = V_82 ;
V_5 -> V_409 = & V_82 -> V_407 -> V_2 ;
V_5 -> V_309 = V_309 ;
V_5 -> V_64 = V_64 ;
V_5 -> V_19 = false ;
V_5 -> V_164 = V_309 -> V_164 ;
V_5 -> V_410 = V_411 ;
V_5 -> V_383 = F_212 ( V_412 |
V_413 ) ;
V_5 -> V_10 = V_82 -> V_414 . V_10 ;
V_5 -> V_215 = V_309 -> V_215 ;
V_5 -> V_415 = V_416 ;
V_5 -> V_216 = F_24 ( sizeof( struct V_285 * ) * V_405 ,
V_154 ) ;
if ( ! V_5 -> V_216 ) {
V_114 = - V_113 ;
goto V_112;
}
V_5 -> V_243 = F_24 ( sizeof( struct V_13 * ) * V_405 ,
V_154 ) ;
if ( ! V_5 -> V_243 ) {
V_114 = - V_113 ;
goto V_112;
}
V_5 -> V_213 = V_309 -> V_213 ;
V_5 -> V_417 = ( V_82 -> V_2 -> V_130 . V_418 == 64 ) ? 1 : 0 ;
V_5 -> V_419 = - 1 ;
V_5 -> V_420 = V_421 ;
F_236 ( & V_5 -> V_224 ) ;
F_25 ( & V_5 -> V_189 , F_111 ) ;
F_25 ( & V_5 -> V_222 , F_180 ) ;
F_25 ( & V_5 -> V_279 , F_131 ) ;
F_237 ( & V_5 -> V_271 , F_125 ) ;
F_237 ( & V_5 -> V_275 , F_129 ) ;
#ifdef F_156
F_25 ( & V_5 -> V_399 , F_225 ) ;
F_25 ( & V_5 -> V_401 , F_227 ) ;
#endif
#ifdef F_238
if ( ! F_239 ( V_5 -> V_82 -> V_2 ) ) {
if ( V_82 -> V_2 -> V_130 . V_164 & V_422 ) {
V_2 -> V_423 = & V_424 ;
} else {
F_132 ( V_5 , L_88 ) ;
V_2 -> V_423 = & V_425 ;
}
}
#endif
for ( V_6 = 0 ; V_6 < V_162 ; ++ V_6 )
F_240 ( & V_5 -> V_158 [ V_6 ] ) ;
V_5 -> V_293 = V_82 -> V_2 -> V_130 . V_426 [ V_5 -> V_64 ] ;
V_2 -> V_427 = V_78 ;
F_57 ( V_2 -> V_77 , V_82 -> V_2 -> V_130 . V_428 [ V_5 -> V_64 ] ) ;
if ( ! F_84 ( V_2 -> V_77 ) ) {
if ( F_239 ( V_5 -> V_82 -> V_2 ) ) {
F_241 ( V_2 ) ;
F_15 ( V_5 , L_89 , V_2 -> V_77 ) ;
V_387 = F_66 ( V_2 -> V_77 ) ;
V_82 -> V_2 -> V_130 . V_428 [ V_5 -> V_64 ] = V_387 ;
} else {
F_18 ( V_5 , L_90 ,
V_5 -> V_64 , V_2 -> V_77 ) ;
V_114 = - V_9 ;
goto V_112;
}
}
memcpy ( V_5 -> V_156 , V_2 -> V_77 , sizeof( V_5 -> V_156 ) ) ;
V_5 -> V_333 = F_242 ( sizeof( struct V_429 ) +
V_430 * V_431 ) ;
V_114 = F_190 ( V_5 ) ;
if ( V_114 )
goto V_112;
#ifdef F_185
F_62 ( & V_5 -> V_94 ) ;
F_236 ( & V_5 -> V_111 ) ;
#endif
V_5 -> V_352 . V_164 = 0 ;
V_5 -> V_352 . V_356 = V_357 ;
V_5 -> V_352 . V_360 = V_361 ;
V_114 = F_243 ( V_82 -> V_2 , & V_5 -> V_344 ,
V_345 , V_345 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_91 ) ;
goto V_112;
}
V_5 -> V_343 = 1 ;
if ( F_244 ( V_5 -> V_82 -> V_2 ) )
V_2 -> V_432 = & V_433 ;
else
V_2 -> V_432 = & V_434 ;
V_2 -> V_435 = V_436 ;
F_233 ( V_2 , V_5 -> V_215 ) ;
F_234 ( V_2 , V_5 -> V_213 ) ;
V_2 -> V_437 = & V_438 ;
V_2 -> V_439 = V_440 | V_441 | V_442 ;
if ( V_82 -> V_443 )
V_2 -> V_439 |= V_444 | V_445 ;
V_2 -> V_446 = V_2 -> V_439 ;
V_2 -> V_439 |= V_447 | V_448 ;
V_2 -> V_381 = V_2 -> V_439 | V_449 |
V_450 | V_451 |
V_452 ;
V_2 -> V_439 |= V_382 ;
if ( V_82 -> V_2 -> V_130 . V_137 ==
V_143 )
V_2 -> V_439 |= V_453 ;
if ( V_82 -> V_2 -> V_130 . V_137 != V_149 )
V_2 -> V_210 |= V_211 ;
if ( V_82 -> V_2 -> V_130 . V_131 == V_132 ) {
V_2 -> V_454 |= V_441 | V_447 |
V_444 | V_455 ;
V_2 -> V_439 |= V_455 ;
V_2 -> V_381 |= V_455 ;
}
V_82 -> V_346 [ V_64 ] = V_2 ;
F_133 ( V_2 ) ;
F_122 ( V_5 ) ;
V_114 = F_245 ( V_2 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_92 , V_64 ) ;
goto V_112;
}
V_5 -> V_342 = 1 ;
F_15 ( V_5 , L_93 , V_309 -> V_215 ) ;
F_15 ( V_5 , L_94 , V_309 -> V_213 ) ;
F_213 ( V_5 -> V_2 , V_5 -> V_2 -> V_381 ) ;
F_141 ( V_2 ) ;
V_114 = F_151 ( V_82 -> V_2 , V_5 -> V_64 ,
V_5 -> V_294 + V_308 ,
V_309 -> V_310 , V_309 -> V_311 ,
V_309 -> V_312 , V_309 -> V_313 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_64 ,
V_5 -> V_64 , V_114 ) ;
goto V_112;
}
if ( V_82 -> V_2 -> V_130 . V_131 == V_132 ) {
V_114 = F_152 ( V_82 -> V_2 , V_5 -> V_64 , V_314 , 1 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_66 ,
V_114 ) ;
goto V_112;
}
}
F_15 ( V_5 , L_67 ) ;
V_114 = F_153 ( V_82 -> V_2 , V_5 -> V_64 ) ;
if ( V_114 ) {
F_18 ( V_5 , L_68 ) ;
goto V_112;
}
F_128 ( V_82 -> V_115 , & V_5 -> V_271 , V_272 ) ;
if ( V_82 -> V_2 -> V_130 . V_276 & V_277 )
F_128 ( V_82 -> V_115 , & V_5 -> V_275 ,
V_278 ) ;
return 0 ;
V_112:
F_197 ( V_2 ) ;
return V_114 ;
}
