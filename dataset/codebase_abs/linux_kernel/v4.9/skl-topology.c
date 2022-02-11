static int F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
return false ;
default:
return true ;
}
}
static bool F_2 ( struct V_10 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_10 -> V_13 ;
if ( V_10 -> V_15 . V_16 + V_12 -> V_17 -> V_18 >
V_10 -> V_15 . V_19 ) {
F_3 ( V_14 -> V_20 ,
L_1 , V_21 ,
V_12 -> V_3 . V_22 ,
V_12 -> V_3 . V_23 ) ;
F_3 ( V_14 -> V_20 ,
L_2 ,
V_10 -> V_15 . V_19 , V_10 -> V_15 . V_16 ) ;
return false ;
} else {
return true ;
}
}
static void F_4 ( struct V_10 * V_10 ,
struct V_11 * V_12 )
{
V_10 -> V_15 . V_16 += V_12 -> V_17 -> V_18 ;
}
static bool F_5 ( struct V_10 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_10 -> V_13 ;
if ( V_10 -> V_15 . V_24 + V_12 -> V_24 > V_10 -> V_15 . V_25 ) {
F_3 ( V_14 -> V_20 ,
L_1 , V_21 ,
V_12 -> V_3 . V_22 , V_12 -> V_3 . V_23 ) ;
F_3 ( V_14 -> V_20 ,
L_3 ,
V_10 -> V_15 . V_25 , V_10 -> V_15 . V_24 ) ;
return false ;
} else {
return true ;
}
}
static void F_6 ( struct V_10 * V_10 ,
struct V_11 * V_12 )
{
V_10 -> V_15 . V_24 += V_12 -> V_24 ;
}
static void
F_7 ( struct V_10 * V_10 , struct V_11 * V_12 )
{
V_10 -> V_15 . V_24 -= V_12 -> V_24 ;
}
static void
F_8 ( struct V_10 * V_10 , struct V_11 * V_12 )
{
V_10 -> V_15 . V_16 -= V_12 -> V_17 -> V_18 ;
}
static void F_9 ( struct V_13 * V_14 ,
struct V_11 * V_26 )
{
F_10 ( V_14 -> V_20 , L_4 ) ;
F_10 ( V_14 -> V_20 , L_5 ) ;
F_10 ( V_14 -> V_20 , L_6 , V_26 -> V_27 [ 0 ] . V_28 ) ;
F_10 ( V_14 -> V_20 , L_7 , V_26 -> V_27 [ 0 ] . V_29 ) ;
F_10 ( V_14 -> V_20 , L_8 , V_26 -> V_27 [ 0 ] . V_30 ) ;
F_10 ( V_14 -> V_20 , L_9 , V_26 -> V_27 [ 0 ] . V_31 ) ;
F_10 ( V_14 -> V_20 , L_10 ) ;
F_10 ( V_14 -> V_20 , L_6 , V_26 -> V_32 [ 0 ] . V_28 ) ;
F_10 ( V_14 -> V_20 , L_7 , V_26 -> V_32 [ 0 ] . V_29 ) ;
F_10 ( V_14 -> V_20 , L_9 , V_26 -> V_32 [ 0 ] . V_31 ) ;
F_10 ( V_14 -> V_20 , L_8 , V_26 -> V_32 [ 0 ] . V_30 ) ;
}
static void F_11 ( struct V_33 * V_34 , int V_35 )
{
int V_36 = 0xFFFFFFFF ;
int V_37 = 0 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_35 ; V_38 ++ ) {
V_36 &= ( ~ ( 0xF << ( 4 * V_38 ) ) | ( V_37 << ( 4 * V_38 ) ) ) ;
V_37 ++ ;
}
V_34 -> V_39 = V_36 ;
}
static void F_12 ( struct V_33 * V_34 ,
struct V_40 * V_41 , int V_42 )
{
if ( V_42 & V_43 )
V_34 -> V_29 = V_41 -> V_29 ;
if ( V_42 & V_44 ) {
V_34 -> V_28 = V_41 -> V_45 ;
F_11 ( V_34 , V_34 -> V_28 ) ;
}
if ( V_42 & V_46 ) {
V_34 -> V_31 = F_13 ( V_41 -> V_47 ) ;
switch ( V_34 -> V_31 ) {
case V_48 :
V_34 -> V_49 = V_34 -> V_31 ;
break;
default:
V_34 -> V_49 = V_50 ;
break;
}
}
}
static void F_14 ( struct V_11 * V_51 ,
struct V_40 * V_41 , bool V_52 )
{
int V_53 , V_54 ;
struct V_33 * V_27 , * V_32 ;
V_27 = & V_51 -> V_27 [ 0 ] ;
V_32 = & V_51 -> V_32 [ 0 ] ;
if ( V_41 -> V_55 == V_56 ) {
if ( V_52 ) {
V_53 = V_51 -> V_57 ;
V_54 = ( ~ V_51 -> V_58 ) &
V_51 -> V_57 ;
} else {
V_54 = V_51 -> V_57 ;
V_53 = ( ~ V_51 -> V_58 ) &
V_51 -> V_57 ;
}
} else {
if ( V_52 ) {
V_54 = V_51 -> V_57 ;
V_53 = ( ~ V_51 -> V_58 ) &
V_51 -> V_57 ;
} else {
V_53 = V_51 -> V_57 ;
V_54 = ( ~ V_51 -> V_58 ) &
V_51 -> V_57 ;
}
}
F_12 ( V_27 , V_41 , V_53 ) ;
F_12 ( V_32 , V_41 , V_54 ) ;
}
static void F_15 ( struct V_13 * V_14 ,
struct V_11 * V_26 )
{
int V_59 = 1 ;
struct V_33 * V_27 , * V_32 ;
int V_60 , V_61 ;
V_27 = & V_26 -> V_27 [ 0 ] ;
V_32 = & V_26 -> V_32 [ 0 ] ;
if ( V_26 -> V_62 == V_63 )
V_59 = 5 ;
if ( V_27 -> V_29 % 1000 )
V_60 = ( V_27 -> V_29 / 1000 ) + 1 ;
else
V_60 = ( V_27 -> V_29 / 1000 ) ;
V_26 -> V_64 = V_60 * ( V_26 -> V_27 -> V_28 ) *
( V_26 -> V_27 -> V_49 >> 3 ) *
V_59 ;
if ( V_26 -> V_32 -> V_29 % 1000 )
V_61 = ( V_26 -> V_32 -> V_29 / 1000 ) + 1 ;
else
V_61 = ( V_26 -> V_32 -> V_29 / 1000 ) ;
V_26 -> V_65 = V_61 * ( V_26 -> V_32 -> V_28 ) *
( V_26 -> V_32 -> V_49 >> 3 ) *
V_59 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_11 * V_51 = V_2 -> V_66 ;
int V_67 , V_68 ;
T_1 V_45 , V_29 , V_47 ;
struct V_69 * V_70 ;
struct V_10 * V_10 = F_17 ( V_14 -> V_20 ) ;
if ( V_51 -> V_71 . V_72 > 0 )
return 0 ;
F_10 ( V_14 -> V_20 , L_11 ) ;
switch ( V_51 -> V_73 ) {
case V_74 :
V_67 = V_75 ;
V_68 = V_76 ;
V_29 = V_51 -> V_27 [ 0 ] . V_29 ;
V_47 = V_51 -> V_27 [ 0 ] . V_49 ;
V_45 = V_51 -> V_27 [ 0 ] . V_28 ;
break;
case V_77 :
V_67 = V_78 ;
if ( V_51 -> V_79 == V_80 ) {
V_68 = V_56 ;
V_29 = V_51 -> V_32 [ 0 ] . V_29 ;
V_47 = V_51 -> V_32 [ 0 ] . V_49 ;
V_45 = V_51 -> V_32 [ 0 ] . V_28 ;
} else {
V_68 = V_76 ;
V_29 = V_51 -> V_27 [ 0 ] . V_29 ;
V_47 = V_51 -> V_27 [ 0 ] . V_49 ;
V_45 = V_51 -> V_27 [ 0 ] . V_28 ;
}
break;
default:
return - V_81 ;
}
V_70 = F_18 ( V_10 , V_51 -> V_82 , V_67 ,
V_47 , V_45 , V_29 , V_68 ) ;
if ( V_70 ) {
V_51 -> V_71 . V_72 = V_70 -> V_83 ;
V_51 -> V_71 . V_84 = ( T_1 * ) & V_70 -> V_84 ;
} else {
F_3 ( V_14 -> V_20 , L_12 ,
V_51 -> V_82 , V_67 , V_68 ) ;
F_3 ( V_14 -> V_20 , L_13 ,
V_45 , V_29 , V_47 ) ;
return - V_85 ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_11 * V_51 = V_2 -> V_66 ;
struct V_40 * V_41 = V_51 -> V_17 -> V_86 ;
int V_87 = V_51 -> V_17 -> V_88 ;
bool V_52 ;
if ( ! V_51 -> V_57 )
return;
F_10 ( V_14 -> V_20 , L_14 ,
V_2 -> V_89 ) ;
F_9 ( V_14 , V_51 ) ;
if ( V_87 == V_90 )
V_52 = true ;
else
V_52 = false ;
F_14 ( V_51 , V_41 , V_52 ) ;
F_15 ( V_14 , V_51 ) ;
F_10 ( V_14 -> V_20 , L_15 ,
V_2 -> V_89 ) ;
F_9 ( V_14 , V_51 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
int V_38 , V_91 ;
struct V_11 * V_12 = V_2 -> V_66 ;
const struct V_92 * V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
if ( V_12 -> V_71 . V_72 > 0 &&
V_12 -> V_71 . V_100 == V_101 ) {
V_99 = & V_12 -> V_71 ;
V_91 = F_21 ( V_14 , V_99 -> V_84 ,
V_99 -> V_72 ,
V_99 -> V_102 , V_12 ) ;
if ( V_91 < 0 )
return V_91 ;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_103 ; V_38 ++ ) {
V_93 = & V_2 -> V_104 [ V_38 ] ;
if ( V_93 -> V_105 & V_106 ) {
V_95 = ( void * ) V_93 -> V_107 ;
V_97 = (struct V_96 * ) V_95 -> V_108 . V_109 ;
if ( V_97 -> V_100 == V_101 ) {
V_91 = F_21 ( V_14 ,
( T_1 * ) V_97 -> V_41 , V_97 -> V_83 ,
V_97 -> V_102 , V_12 ) ;
if ( V_91 < 0 )
return V_91 ;
}
}
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
const struct V_92 * V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_11 * V_12 = V_2 -> V_66 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_103 ; V_38 ++ ) {
V_93 = & V_2 -> V_104 [ V_38 ] ;
if ( V_93 -> V_105 & V_106 ) {
V_95 = (struct V_94 * ) V_93 -> V_107 ;
V_97 = (struct V_96 * ) V_95 -> V_108 . V_109 ;
if ( V_97 -> V_100 != V_110 )
continue;
V_12 -> V_71 . V_84 = ( T_1 * ) & V_97 -> V_41 ;
V_12 -> V_71 . V_72 = V_97 -> V_83 ;
break;
}
}
return 0 ;
}
static int
F_23 ( struct V_10 * V_10 , struct V_111 * V_17 )
{
struct V_112 * V_113 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_91 = 0 ;
F_24 (w_module, &pipe->w_list, node) {
V_2 = V_113 -> V_2 ;
V_12 = V_2 -> V_66 ;
if ( V_12 -> V_3 . V_22 < 0 ) {
F_3 ( V_10 -> V_13 -> V_20 ,
L_16 ,
( V_114 * ) V_12 -> V_115 ) ;
return - V_85 ;
}
if ( ! F_5 ( V_10 , V_12 ) )
return - V_116 ;
if ( V_12 -> V_117 && V_14 -> V_118 -> V_119 . V_120 ) {
V_91 = V_14 -> V_118 -> V_119 . V_120 ( V_14 -> V_118 ,
V_12 -> V_3 . V_22 , V_12 -> V_115 ) ;
if ( V_91 < 0 )
return V_91 ;
V_12 -> V_121 = V_122 ;
}
F_16 ( V_2 , V_14 ) ;
F_19 ( V_2 , V_14 ) ;
V_12 -> V_3 . V_123 = F_25 ( V_14 , V_12 ) ;
if ( V_12 -> V_3 . V_123 < 0 )
return V_91 ;
F_22 ( V_2 ) ;
V_91 = F_26 ( V_14 , V_12 ) ;
if ( V_91 < 0 ) {
F_27 ( V_14 , V_12 ) ;
return V_91 ;
}
F_6 ( V_10 , V_12 ) ;
V_91 = F_20 ( V_2 , V_14 ) ;
if ( V_91 < 0 )
return V_91 ;
}
return 0 ;
}
static int F_28 ( struct V_13 * V_14 ,
struct V_111 * V_17 )
{
int V_91 ;
struct V_112 * V_113 = NULL ;
struct V_11 * V_12 = NULL ;
F_24 (w_module, &pipe->w_list, node) {
V_12 = V_113 -> V_2 -> V_66 ;
if ( V_12 -> V_117 && V_14 -> V_118 -> V_119 . V_124 &&
V_12 -> V_121 > V_125 ) {
V_91 = V_14 -> V_118 -> V_119 . V_124 ( V_14 -> V_118 ,
V_12 -> V_3 . V_22 ) ;
if ( V_91 < 0 )
return - V_85 ;
}
F_27 ( V_14 , V_12 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
int V_91 ;
struct V_11 * V_12 = V_2 -> V_66 ;
struct V_112 * V_113 ;
struct V_111 * V_126 = V_12 -> V_17 ;
struct V_11 * V_127 = NULL , * V_128 ;
struct V_13 * V_14 = V_10 -> V_13 ;
if ( ! F_5 ( V_10 , V_12 ) )
return - V_129 ;
if ( ! F_2 ( V_10 , V_12 ) )
return - V_116 ;
V_91 = F_30 ( V_14 , V_12 -> V_17 ) ;
if ( V_91 < 0 )
return V_91 ;
F_4 ( V_10 , V_12 ) ;
F_6 ( V_10 , V_12 ) ;
V_91 = F_23 ( V_10 , V_126 ) ;
if ( V_91 < 0 )
return V_91 ;
F_24 (w_module, &s_pipe->w_list, node) {
V_128 = V_113 -> V_2 -> V_66 ;
if ( V_127 == NULL ) {
V_127 = V_128 ;
continue;
}
V_91 = F_31 ( V_14 , V_127 , V_128 ) ;
if ( V_91 < 0 )
return V_91 ;
V_127 = V_128 ;
}
return 0 ;
}
static int F_32 ( struct V_13 * V_14 ,
struct V_96 * V_130 )
{
struct V_131 * V_41 = (struct V_131 * ) V_130 -> V_41 ;
struct V_132 * V_133 ;
int V_38 , V_123 ;
V_133 = V_41 -> V_134 ;
for ( V_38 = 0 ; V_38 < V_41 -> V_135 ; V_38 ++ ) {
V_123 = F_33 ( V_14 ,
V_133 -> V_136 , V_133 -> V_137 ) ;
if ( V_123 < 0 )
return - V_81 ;
V_133 -> V_137 = V_123 ;
V_133 ++ ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_11 * V_26 , struct V_13 * V_14 )
{
int V_38 , V_91 ;
struct V_11 * V_12 = V_2 -> V_66 ;
const struct V_92 * V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
for ( V_38 = 0 ; V_38 < V_26 -> V_138 ; V_38 ++ ) {
if ( V_26 -> V_139 [ V_38 ] . V_140 != V_141 )
return 0 ;
}
for ( V_38 = 0 ; V_38 < V_26 -> V_142 ; V_38 ++ ) {
if ( V_26 -> V_143 [ V_38 ] . V_140 != V_141 )
return 0 ;
}
if ( V_12 -> V_71 . V_72 > 0 &&
V_12 -> V_71 . V_100 == V_144 ) {
V_99 = & V_12 -> V_71 ;
V_91 = F_21 ( V_14 , V_99 -> V_84 ,
V_99 -> V_72 ,
V_99 -> V_102 , V_12 ) ;
if ( V_91 < 0 )
return V_91 ;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_103 ; V_38 ++ ) {
V_93 = & V_2 -> V_104 [ V_38 ] ;
if ( V_93 -> V_105 & V_106 ) {
V_95 = ( void * ) V_93 -> V_107 ;
V_97 = (struct V_96 * ) V_95 -> V_108 . V_109 ;
if ( V_97 -> V_100 == V_144 ) {
if ( V_12 -> V_62 == V_145 )
F_32 ( V_14 , V_97 ) ;
V_91 = F_21 ( V_14 ,
( T_1 * ) V_97 -> V_41 , V_97 -> V_146 ,
V_97 -> V_102 , V_12 ) ;
if ( V_91 < 0 )
return V_91 ;
}
}
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_10 * V_10 ,
struct V_1 * V_147 ,
struct V_11 * V_148 )
{
struct V_149 * V_150 ;
struct V_1 * V_151 = NULL , * V_152 = NULL ;
struct V_11 * V_153 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_91 ;
F_36 (w, p) {
if ( ! V_150 -> V_154 )
continue;
F_10 ( V_14 -> V_20 , L_17 , V_21 , V_2 -> V_89 ) ;
F_10 ( V_14 -> V_20 , L_18 , V_21 , V_150 -> V_151 -> V_89 ) ;
V_152 = V_150 -> V_151 ;
if ( ! F_1 ( V_150 -> V_151 ) )
return F_35 ( V_150 -> V_151 , V_10 , V_147 , V_148 ) ;
if ( ( V_150 -> V_151 -> V_66 != NULL ) &&
F_1 ( V_150 -> V_151 ) ) {
V_151 = V_150 -> V_151 ;
V_153 = V_151 -> V_66 ;
if ( V_148 -> V_121 == V_125 ||
V_153 -> V_121 == V_125 )
continue;
V_91 = F_31 ( V_14 , V_148 , V_153 ) ;
if ( V_91 )
return V_91 ;
F_34 ( V_147 , V_148 , V_14 ) ;
F_34 ( V_151 , V_153 , V_14 ) ;
if ( V_153 -> V_17 -> V_155 != V_156 ) {
if ( V_153 -> V_17 -> V_88 !=
V_90 )
V_91 = F_37 ( V_14 ,
V_153 -> V_17 ) ;
if ( V_91 )
return V_91 ;
}
}
}
if ( ! V_151 )
return F_35 ( V_152 , V_10 , V_147 , V_148 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_148 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_91 = 0 ;
V_148 = V_2 -> V_66 ;
V_91 = F_35 ( V_2 , V_10 , V_2 , V_148 ) ;
if ( V_91 )
return V_91 ;
if ( V_148 -> V_17 -> V_88 != V_90 )
return F_37 ( V_14 , V_148 -> V_17 ) ;
return 0 ;
}
static struct V_1 * F_39 (
struct V_1 * V_2 , struct V_10 * V_10 )
{
struct V_149 * V_150 ;
struct V_1 * V_147 = NULL ;
struct V_13 * V_14 = V_10 -> V_13 ;
F_40 (w, p) {
V_147 = V_150 -> V_157 ;
if ( ! V_150 -> V_154 )
continue;
F_10 ( V_14 -> V_20 , L_19 , V_2 -> V_89 ) ;
F_10 ( V_14 -> V_20 , L_20 , V_150 -> V_157 -> V_89 ) ;
if ( ( V_150 -> V_157 -> V_66 != NULL ) &&
F_1 ( V_150 -> V_157 ) ) {
return V_150 -> V_157 ;
}
}
if ( V_147 != NULL )
return F_39 ( V_147 , V_10 ) ;
return NULL ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
int V_91 = 0 ;
struct V_1 * V_157 , * V_151 ;
struct V_11 * V_148 , * V_153 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_158 = 0 ;
V_151 = V_2 ;
V_153 = V_151 -> V_66 ;
V_157 = F_39 ( V_2 , V_10 ) ;
if ( V_157 != NULL ) {
V_148 = V_157 -> V_66 ;
V_153 = V_151 -> V_66 ;
V_158 = 1 ;
if ( V_148 -> V_17 -> V_155 != V_156 )
V_158 = 0 ;
}
if ( V_158 ) {
V_91 = F_31 ( V_14 , V_148 , V_153 ) ;
if ( V_91 )
return V_91 ;
F_34 ( V_157 , V_148 , V_14 ) ;
F_34 ( V_151 , V_153 , V_14 ) ;
if ( V_153 -> V_17 -> V_88 != V_90 )
V_91 = F_37 ( V_14 , V_153 -> V_17 ) ;
}
return V_91 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_148 , * V_153 ;
int V_91 = 0 , V_38 ;
struct V_13 * V_14 = V_10 -> V_13 ;
V_153 = V_2 -> V_66 ;
V_91 = F_43 ( V_14 , V_153 -> V_17 ) ;
if ( V_91 )
return V_91 ;
for ( V_38 = 0 ; V_38 < V_153 -> V_142 ; V_38 ++ ) {
if ( V_153 -> V_143 [ V_38 ] . V_140 == V_141 ) {
V_148 = V_153 -> V_143 [ V_38 ] . V_159 ;
if ( ! V_148 )
continue;
V_91 = F_43 ( V_14 , V_148 -> V_17 ) ;
if ( V_91 < 0 )
return V_91 ;
V_91 = F_44 ( V_14 ,
V_148 , V_153 ) ;
}
}
return V_91 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_66 ;
struct V_112 * V_113 ;
struct V_11 * V_127 = NULL , * V_128 ;
struct V_13 * V_14 = V_10 -> V_13 ;
struct V_111 * V_126 = V_12 -> V_17 ;
int V_91 = 0 ;
if ( V_126 -> V_155 == V_160 )
return - V_81 ;
F_7 ( V_10 , V_12 ) ;
F_8 ( V_10 , V_12 ) ;
F_24 (w_module, &s_pipe->w_list, node) {
V_128 = V_113 -> V_2 -> V_66 ;
if ( V_12 -> V_121 >= V_161 )
F_7 ( V_10 , V_128 ) ;
if ( V_127 == NULL ) {
V_127 = V_128 ;
continue;
}
F_44 ( V_14 , V_127 , V_128 ) ;
V_127 = V_128 ;
}
V_91 = F_46 ( V_14 , V_12 -> V_17 ) ;
return F_28 ( V_14 , V_126 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_148 , * V_153 ;
int V_91 = 0 , V_38 ;
struct V_13 * V_14 = V_10 -> V_13 ;
V_148 = V_2 -> V_66 ;
V_91 = F_43 ( V_14 , V_148 -> V_17 ) ;
if ( V_91 )
return V_91 ;
for ( V_38 = 0 ; V_38 < V_148 -> V_138 ; V_38 ++ ) {
if ( V_148 -> V_139 [ V_38 ] . V_140 == V_141 ) {
V_153 = V_148 -> V_139 [ V_38 ] . V_159 ;
if ( ! V_153 )
continue;
V_91 = F_44 ( V_14 , V_148 ,
V_153 ) ;
}
}
return V_91 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_162 * V_93 , int V_163 )
{
struct V_164 * V_165 = V_2 -> V_165 ;
struct V_10 * V_10 = F_17 ( V_165 -> V_20 ) ;
switch ( V_163 ) {
case V_166 :
return F_29 ( V_2 , V_10 ) ;
case V_167 :
return F_41 ( V_2 , V_10 ) ;
case V_168 :
return F_42 ( V_2 , V_10 ) ;
case V_169 :
return F_45 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_162 * V_93 , int V_163 )
{
struct V_164 * V_165 = V_2 -> V_165 ;
struct V_10 * V_10 = F_17 ( V_165 -> V_20 ) ;
switch ( V_163 ) {
case V_166 :
return F_29 ( V_2 , V_10 ) ;
case V_167 :
return F_41 ( V_2 , V_10 ) ;
case V_168 :
return F_42 ( V_2 , V_10 ) ;
case V_169 :
return F_45 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_162 * V_93 , int V_163 )
{
struct V_164 * V_165 = V_2 -> V_165 ;
struct V_10 * V_10 = F_17 ( V_165 -> V_20 ) ;
switch ( V_163 ) {
case V_166 :
return F_38 ( V_2 , V_10 ) ;
case V_169 :
return F_47 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_51 ( struct V_162 * V_170 ,
unsigned int T_2 * V_171 , unsigned int V_83 )
{
struct V_94 * V_95 =
(struct V_94 * ) V_170 -> V_107 ;
struct V_96 * V_97 = (struct V_96 * ) V_95 -> V_108 . V_109 ;
struct V_1 * V_2 = F_52 ( V_170 ) ;
struct V_11 * V_12 = V_2 -> V_66 ;
struct V_10 * V_10 = F_17 ( V_2 -> V_165 -> V_20 ) ;
if ( V_2 -> V_172 )
F_53 ( V_10 -> V_13 , ( T_1 * ) V_97 -> V_41 ,
V_97 -> V_83 , V_97 -> V_102 , V_12 ) ;
V_83 -= 2 * sizeof( T_1 ) ;
if ( V_83 > V_97 -> V_146 )
V_83 = V_97 -> V_146 ;
if ( V_97 -> V_41 ) {
if ( F_54 ( V_171 , & V_97 -> V_102 , sizeof( T_1 ) ) )
return - V_173 ;
if ( F_54 ( V_171 + 1 , & V_83 , sizeof( T_1 ) ) )
return - V_173 ;
if ( F_54 ( V_171 + 2 , V_97 -> V_41 , V_83 ) )
return - V_173 ;
}
return 0 ;
}
static int F_55 ( struct V_162 * V_170 ,
const unsigned int T_2 * V_171 , unsigned int V_83 )
{
struct V_1 * V_2 = F_52 ( V_170 ) ;
struct V_11 * V_12 = V_2 -> V_66 ;
struct V_94 * V_95 =
(struct V_94 * ) V_170 -> V_107 ;
struct V_96 * V_174 = (struct V_96 * ) V_95 -> V_108 . V_109 ;
struct V_10 * V_10 = F_17 ( V_2 -> V_165 -> V_20 ) ;
if ( V_174 -> V_41 ) {
if ( V_83 > V_174 -> V_146 )
return - V_81 ;
V_174 -> V_83 = V_83 ;
if ( V_174 -> V_102 == V_175 ) {
if ( F_56 ( V_174 -> V_41 , V_171 , V_83 ) )
return - V_173 ;
} else {
if ( F_56 ( V_174 -> V_41 ,
V_171 + 2 , V_83 ) )
return - V_173 ;
}
if ( V_2 -> V_172 )
return F_21 ( V_10 -> V_13 ,
( T_1 * ) V_174 -> V_41 , V_174 -> V_83 ,
V_174 -> V_102 , V_12 ) ;
}
return 0 ;
}
static void F_57 ( struct V_11 * V_26 ,
struct V_40 * V_41 )
{
struct V_111 * V_17 = V_26 -> V_17 ;
if ( V_17 -> V_176 ) {
switch ( V_26 -> V_73 ) {
case V_177 :
V_17 -> V_86 -> V_178 = V_41 -> V_178 ;
break;
case V_179 :
V_17 -> V_86 -> V_180 = V_41 -> V_180 ;
break;
default:
break;
}
V_17 -> V_86 -> V_47 = V_41 -> V_47 ;
V_17 -> V_86 -> V_45 = V_41 -> V_45 ;
V_17 -> V_86 -> V_29 = V_41 -> V_29 ;
V_17 -> V_86 -> V_55 = V_41 -> V_55 ;
} else {
memcpy ( V_17 -> V_86 , V_41 , sizeof( * V_41 ) ) ;
}
}
int F_58 ( struct V_181 * V_20 ,
struct V_11 * V_12 ,
struct V_40 * V_41 )
{
struct V_33 * V_182 = NULL ;
F_57 ( V_12 , V_41 ) ;
if ( V_41 -> V_55 == V_56 )
V_182 = & V_12 -> V_27 [ 0 ] ;
else
V_182 = & V_12 -> V_32 [ 0 ] ;
V_182 -> V_29 = V_41 -> V_29 ;
V_182 -> V_28 = V_41 -> V_45 ;
V_182 -> V_31 = F_13 ( V_41 -> V_47 ) ;
switch ( V_182 -> V_31 ) {
case V_48 :
V_182 -> V_49 = V_182 -> V_31 ;
break;
case V_183 :
case V_50 :
V_182 -> V_49 = V_50 ;
break;
default:
F_3 ( V_20 , L_21 ,
V_182 -> V_31 ) ;
return - V_81 ;
}
if ( V_41 -> V_55 == V_56 ) {
V_12 -> V_64 = ( V_182 -> V_29 / 1000 ) *
( V_182 -> V_28 ) *
( V_182 -> V_49 >> 3 ) ;
} else {
V_12 -> V_65 = ( V_182 -> V_29 / 1000 ) *
( V_182 -> V_28 ) *
( V_182 -> V_49 >> 3 ) ;
}
return 0 ;
}
struct V_11 *
F_59 ( struct V_184 * V_185 , int V_55 )
{
struct V_1 * V_2 ;
struct V_149 * V_150 = NULL ;
if ( V_55 == V_56 ) {
V_2 = V_185 -> V_186 ;
F_36 (w, p) {
if ( V_150 -> V_154 && V_150 -> V_151 -> V_172 &&
! F_1 ( V_150 -> V_151 ) )
continue;
if ( V_150 -> V_151 -> V_66 ) {
F_10 ( V_185 -> V_20 , L_22 ,
V_150 -> V_151 -> V_89 ) ;
return V_150 -> V_151 -> V_66 ;
}
}
} else {
V_2 = V_185 -> V_187 ;
F_40 (w, p) {
if ( V_150 -> V_154 && V_150 -> V_157 -> V_172 &&
! F_1 ( V_150 -> V_157 ) )
continue;
if ( V_150 -> V_157 -> V_66 ) {
F_10 ( V_185 -> V_20 , L_22 ,
V_150 -> V_157 -> V_89 ) ;
return V_150 -> V_157 -> V_66 ;
}
}
}
return NULL ;
}
static struct V_11 * F_60 (
struct V_184 * V_185 , struct V_1 * V_2 )
{
struct V_149 * V_150 ;
struct V_11 * V_12 = NULL ;
F_40 (w, p) {
if ( V_2 -> V_188 [ V_189 ] > 0 ) {
if ( V_150 -> V_154 &&
( V_150 -> V_151 -> V_3 == V_7 ) &&
V_150 -> V_157 -> V_66 ) {
V_12 = V_150 -> V_157 -> V_66 ;
return V_12 ;
}
V_12 = F_60 ( V_185 , V_150 -> V_157 ) ;
if ( V_12 )
return V_12 ;
}
}
return V_12 ;
}
static struct V_11 * F_61 (
struct V_184 * V_185 , struct V_1 * V_2 )
{
struct V_149 * V_150 ;
struct V_11 * V_12 = NULL ;
F_36 (w, p) {
if ( V_2 -> V_188 [ V_190 ] > 0 ) {
if ( V_150 -> V_154 &&
( V_150 -> V_157 -> V_3 == V_6 ) &&
V_150 -> V_151 -> V_66 ) {
V_12 = V_150 -> V_151 -> V_66 ;
return V_12 ;
}
V_12 = F_61 ( V_185 , V_150 -> V_151 ) ;
if ( V_12 )
return V_12 ;
}
}
return V_12 ;
}
struct V_11 *
F_62 ( struct V_184 * V_185 , int V_55 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
if ( V_55 == V_56 ) {
V_2 = V_185 -> V_186 ;
V_12 = F_60 ( V_185 , V_2 ) ;
} else {
V_2 = V_185 -> V_187 ;
V_12 = F_61 ( V_185 , V_2 ) ;
}
return V_12 ;
}
static T_3 F_63 ( int V_73 )
{
int V_91 ;
switch ( V_73 ) {
case V_191 :
V_91 = V_78 ;
break;
case V_74 :
V_91 = V_75 ;
break;
case V_77 :
V_91 = V_78 ;
break;
case V_177 :
V_91 = V_192 ;
break;
default:
V_91 = V_193 ;
break;
}
return V_91 ;
}
static int F_64 ( struct V_184 * V_185 ,
struct V_11 * V_12 ,
struct V_40 * V_41 )
{
struct V_69 * V_70 ;
struct V_10 * V_10 = F_17 ( V_185 -> V_20 ) ;
int V_67 = F_63 ( V_12 -> V_73 ) ;
F_57 ( V_12 , V_41 ) ;
if ( V_67 == V_192 )
return 0 ;
V_70 = F_18 ( V_10 , V_12 -> V_82 , V_67 ,
V_41 -> V_47 , V_41 -> V_45 ,
V_41 -> V_29 , V_41 -> V_55 ) ;
if ( V_70 ) {
V_12 -> V_71 . V_72 = V_70 -> V_83 ;
V_12 -> V_71 . V_84 = ( T_1 * ) & V_70 -> V_84 ;
} else {
F_3 ( V_185 -> V_20 , L_12 ,
V_12 -> V_82 , V_67 ,
V_41 -> V_55 ) ;
F_3 ( V_185 -> V_20 , L_13 ,
V_41 -> V_45 , V_41 -> V_29 , V_41 -> V_47 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_65 ( struct V_184 * V_185 ,
struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_149 * V_150 ;
int V_91 = - V_85 ;
F_40 (w, p) {
if ( V_150 -> V_154 && F_1 ( V_150 -> V_157 ) &&
V_150 -> V_157 -> V_66 ) {
V_91 = F_64 ( V_185 ,
V_150 -> V_157 -> V_66 , V_41 ) ;
if ( V_91 < 0 )
return V_91 ;
} else {
V_91 = F_65 ( V_185 ,
V_150 -> V_157 , V_41 ) ;
if ( V_91 < 0 )
return V_91 ;
}
}
return V_91 ;
}
static int F_66 ( struct V_184 * V_185 ,
struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_149 * V_150 = NULL ;
int V_91 = - V_85 ;
F_36 (w, p) {
if ( V_150 -> V_154 && F_1 ( V_150 -> V_151 ) &&
V_150 -> V_151 -> V_66 ) {
V_91 = F_64 ( V_185 ,
V_150 -> V_151 -> V_66 , V_41 ) ;
if ( V_91 < 0 )
return V_91 ;
} else {
V_91 = F_66 (
V_185 , V_150 -> V_151 , V_41 ) ;
if ( V_91 < 0 )
return V_91 ;
}
}
return V_91 ;
}
int F_67 ( struct V_184 * V_185 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 ;
if ( V_41 -> V_55 == V_56 ) {
V_2 = V_185 -> V_186 ;
return F_65 ( V_185 , V_2 , V_41 ) ;
} else {
V_2 = V_185 -> V_187 ;
return F_66 ( V_185 , V_2 , V_41 ) ;
}
return 0 ;
}
static int F_68 ( struct V_181 * V_20 ,
struct V_111 * V_17 , T_1 V_194 ,
T_1 V_195 )
{
switch ( V_194 ) {
case V_196 :
V_17 -> V_88 = V_195 ;
break;
case V_197 :
V_17 -> V_198 = V_195 ;
break;
case V_199 :
V_17 -> V_18 = V_195 ;
break;
default:
F_3 ( V_20 , L_23 , V_194 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_69 ( struct V_181 * V_20 ,
struct V_11 * V_12 , struct V_10 * V_10 ,
struct V_200 * V_201 )
{
struct V_202 * V_203 ;
struct V_111 * V_17 ;
struct V_40 * V_41 ;
F_24 (ppl, &skl->ppl_list, node) {
if ( V_203 -> V_17 -> V_204 == V_201 -> V_205 ) {
V_12 -> V_17 = V_203 -> V_17 ;
return V_206 ;
}
}
V_203 = F_70 ( V_20 , sizeof( * V_203 ) , V_207 ) ;
if ( ! V_203 )
return - V_116 ;
V_17 = F_70 ( V_20 , sizeof( * V_17 ) , V_207 ) ;
if ( ! V_17 )
return - V_116 ;
V_41 = F_70 ( V_20 , sizeof( * V_41 ) , V_207 ) ;
if ( ! V_41 )
return - V_116 ;
V_17 -> V_86 = V_41 ;
V_17 -> V_204 = V_201 -> V_205 ;
F_71 ( & V_17 -> V_208 ) ;
V_203 -> V_17 = V_17 ;
F_72 ( & V_203 -> V_209 , & V_10 -> V_210 ) ;
V_12 -> V_17 = V_17 ;
V_12 -> V_17 -> V_155 = V_160 ;
return 0 ;
}
static int F_73 ( struct V_181 * V_20 , T_1 V_194 ,
struct V_211 * V_212 ,
int V_213 , T_1 V_205 )
{
switch ( V_194 ) {
case V_214 :
V_212 [ V_213 ] . V_3 . V_22 = V_205 ;
break;
case V_215 :
V_212 [ V_213 ] . V_3 . V_23 = V_205 ;
break;
default:
F_3 ( V_20 , L_24 , V_205 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_74 ( struct V_181 * V_20 ,
struct V_11 * V_12 ,
struct V_200 * V_201 ,
int V_68 , int V_216 )
{
int V_91 ;
struct V_211 * V_212 ;
switch ( V_68 ) {
case V_217 :
V_212 = V_12 -> V_143 ;
break;
case V_218 :
V_212 = V_12 -> V_139 ;
break;
default:
F_3 ( V_20 , L_25 ) ;
return - V_81 ;
}
V_91 = F_73 ( V_20 , V_201 -> V_219 ,
V_212 , V_216 , V_201 -> V_205 ) ;
if ( V_91 < 0 )
return V_91 ;
V_212 [ V_216 ] . V_220 = false ;
V_212 [ V_216 ] . V_140 = V_221 ;
return 0 ;
}
static int F_75 ( struct V_181 * V_20 ,
struct V_11 * V_12 , T_1 V_194 ,
T_1 V_205 , T_1 V_68 , T_1 V_216 )
{
struct V_33 * V_222 ;
switch ( V_68 ) {
case V_217 :
V_222 = V_12 -> V_27 ;
V_222 += V_216 ;
break;
case V_218 :
V_222 = V_12 -> V_32 ;
V_222 += V_216 ;
break;
default:
F_3 ( V_20 , L_25 ) ;
return - V_81 ;
}
switch ( V_194 ) {
case V_223 :
V_222 -> V_28 = V_205 ;
break;
case V_224 :
V_222 -> V_29 = V_205 ;
break;
case V_225 :
V_222 -> V_49 = V_205 ;
break;
case V_226 :
V_222 -> V_31 = V_205 ;
break;
case V_227 :
V_222 -> V_30 = V_205 ;
break;
case V_228 :
V_222 -> V_229 = V_205 ;
break;
case V_230 :
V_222 -> V_231 = V_205 ;
break;
case V_232 :
V_222 -> V_39 = V_205 ;
break;
default:
F_3 ( V_20 , L_26 , V_194 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_76 ( struct V_181 * V_20 , struct V_11 * V_12 ,
struct V_233 * V_234 )
{
if ( V_234 -> V_219 == V_235 )
memcpy ( & V_12 -> V_115 , & V_234 -> V_236 , 16 ) ;
else {
F_3 ( V_20 , L_27 , V_234 -> V_219 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_77 (
struct V_211 * V_237 , T_1 V_216 , T_1 V_205 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_216 ; V_38 ++ )
V_237 [ V_38 ] . V_238 = V_205 ;
}
static int F_78 ( struct V_181 * V_20 ,
struct V_200 * V_201 ,
struct V_10 * V_10 , struct V_11 * V_12 )
{
int V_239 = 0 ;
int V_91 ;
static int V_240 ;
static int V_213 , V_68 ;
if ( V_201 -> V_219 > V_241 )
return - V_81 ;
switch ( V_201 -> V_219 ) {
case V_242 :
V_12 -> V_142 = V_201 -> V_205 ;
V_12 -> V_143 = F_70 ( V_20 , V_12 -> V_142 *
sizeof( * V_12 -> V_143 ) ,
V_207 ) ;
if ( ! V_12 -> V_143 )
return - V_116 ;
break;
case V_243 :
V_12 -> V_138 = V_201 -> V_205 ;
V_12 -> V_139 = F_70 ( V_20 , V_12 -> V_138 *
sizeof( * V_12 -> V_139 ) ,
V_207 ) ;
if ( ! V_12 -> V_139 )
return - V_116 ;
break;
case V_244 :
if ( ! V_12 -> V_143 )
return - V_116 ;
F_77 ( V_12 -> V_143 ,
V_12 -> V_142 , V_201 -> V_205 ) ;
break;
case V_245 :
if ( ! V_12 -> V_139 )
return - V_116 ;
F_77 ( V_12 -> V_139 ,
V_12 -> V_138 , V_201 -> V_205 ) ;
break;
case V_246 :
V_12 -> V_247 = V_201 -> V_205 ;
break;
case V_248 :
V_12 -> V_249 = V_201 -> V_205 ;
case V_250 :
V_12 -> V_62 = V_201 -> V_205 ;
break;
case V_251 :
V_12 -> V_73 = V_201 -> V_205 ;
break;
case V_252 :
V_12 -> V_79 = V_201 -> V_205 ;
break;
case V_253 :
V_12 -> V_3 . V_23 =
V_201 -> V_205 ;
break;
case V_254 :
V_12 -> V_255 = V_201 -> V_205 ;
break;
case V_256 :
V_12 -> V_24 = V_201 -> V_205 ;
break;
case V_257 :
V_12 -> V_65 = V_201 -> V_205 ;
break;
case V_258 :
V_12 -> V_64 = V_201 -> V_205 ;
break;
case V_259 :
V_12 -> V_82 = V_201 -> V_205 ;
break;
case V_260 :
V_12 -> V_57 = V_201 -> V_205 ;
break;
case V_261 :
V_12 -> V_58 = V_201 -> V_205 ;
break;
case V_262 :
V_91 = F_69 ( V_20 ,
V_12 , V_10 , V_201 ) ;
if ( V_91 < 0 )
return V_240 ;
if ( V_91 == V_206 )
V_240 = 1 ;
break;
case V_196 :
case V_197 :
case V_199 :
if ( V_240 ) {
V_91 = F_68 ( V_20 , V_12 -> V_17 ,
V_201 -> V_219 , V_201 -> V_205 ) ;
if ( V_91 < 0 )
return V_91 ;
}
break;
case V_263 :
V_68 = V_201 -> V_205 & V_264 ;
V_213 = ( V_201 -> V_205 &
V_265 ) >> 4 ;
break;
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_230 :
case V_232 :
V_91 = F_75 ( V_20 , V_12 , V_201 -> V_219 ,
V_201 -> V_205 , V_68 , V_213 ) ;
if ( V_91 < 0 )
return V_91 ;
break;
case V_214 :
case V_215 :
V_91 = F_74 ( V_20 ,
V_12 , V_201 , V_68 ,
V_213 ) ;
if ( V_91 < 0 )
return V_91 ;
break;
case V_266 :
V_12 -> V_71 . V_72 =
V_201 -> V_205 ;
break;
case V_267 :
V_12 -> V_268 =
V_201 -> V_205 ;
break;
case V_269 :
case V_270 :
case V_271 :
break;
default:
F_3 ( V_20 , L_28 ,
V_201 -> V_219 ) ;
return - V_81 ;
}
V_239 ++ ;
return V_239 ;
}
static int F_79 ( struct V_181 * V_20 ,
char * V_272 , struct V_10 * V_10 ,
struct V_11 * V_12 , int V_273 )
{
struct V_274 * V_275 ;
struct V_200 * V_201 ;
int V_239 = 0 , V_91 ;
int V_276 = 0 , V_277 = 0 ;
if ( V_273 <= 0 )
return - V_81 ;
while ( V_277 < V_273 ) {
V_275 = (struct V_274 * ) ( V_272 + V_276 ) ;
V_276 += V_275 -> V_83 ;
switch ( V_275 -> type ) {
case V_278 :
F_80 ( V_20 , L_29 ) ;
continue;
case V_279 :
V_91 = F_76 ( V_20 , V_12 , V_275 -> V_236 ) ;
if ( V_91 < 0 )
return V_91 ;
V_277 += sizeof( * V_275 -> V_236 ) ;
continue;
default:
V_201 = V_275 -> V_205 ;
V_239 = 0 ;
break;
}
while ( V_239 <= ( V_275 -> V_280 - 1 ) ) {
V_91 = F_78 ( V_20 , V_201 ,
V_10 , V_12 ) ;
if ( V_91 < 0 )
return V_91 ;
V_239 = V_239 + V_91 ;
V_201 ++ ;
}
V_277 += V_239 * sizeof( * V_201 ) ;
}
return 0 ;
}
static int F_81 ( struct V_181 * V_20 ,
struct V_274 * V_275 )
{
struct V_200 * V_201 ;
V_201 = V_275 -> V_205 ;
switch ( V_201 -> V_219 ) {
case V_281 :
case V_282 :
case V_283 :
return V_201 -> V_205 ;
default:
F_3 ( V_20 , L_30 , V_201 -> V_219 ) ;
break;
}
return - V_81 ;
}
static int F_82 ( struct V_284 * V_285 ,
struct V_10 * V_10 , struct V_181 * V_20 ,
struct V_11 * V_12 )
{
struct V_274 * V_275 ;
int V_286 , V_273 = 0 , V_287 , V_276 = 0 ;
char * V_171 ;
int V_91 ;
V_275 = (struct V_274 * ) V_285 -> V_66 . V_171 ;
V_91 = F_81 ( V_20 , V_275 ) ;
if ( V_91 < 0 )
return V_91 ;
V_286 = V_91 ;
V_276 += V_275 -> V_83 ;
V_275 = (struct V_274 * ) ( V_285 -> V_66 . V_171 + V_276 ) ;
while ( V_286 > 0 ) {
V_91 = F_81 ( V_20 , V_275 ) ;
if ( V_91 < 0 )
return V_91 ;
V_287 = V_91 ;
V_276 += V_275 -> V_83 ;
V_275 = (struct V_274 * )
( V_285 -> V_66 . V_171 + V_276 ) ;
V_91 = F_81 ( V_20 , V_275 ) ;
if ( V_91 < 0 )
return V_91 ;
V_273 = V_91 ;
V_276 += V_275 -> V_83 ;
V_275 = (struct V_274 * )
( V_285 -> V_66 . V_171 + V_276 ) ;
V_171 = ( V_285 -> V_66 . V_171 + V_276 ) ;
if ( V_287 == V_288 ) {
V_91 = F_79 ( V_20 , V_171 ,
V_10 , V_12 , V_273 ) ;
if ( V_91 < 0 )
return V_91 ;
-- V_286 ;
} else {
if ( V_12 -> V_71 . V_72 > 0 )
memcpy ( V_12 -> V_71 . V_84 , V_171 ,
V_12 -> V_71 . V_72 ) ;
-- V_286 ;
}
}
return 0 ;
}
static void F_83 ( struct V_289 * V_290 ,
struct V_1 * V_2 )
{
int V_38 ;
struct V_11 * V_12 ;
struct V_111 * V_17 ;
if ( ! strncmp ( V_2 -> V_165 -> V_291 -> V_89 , V_290 -> V_291 . V_89 ,
strlen ( V_290 -> V_291 . V_89 ) ) ) {
V_12 = V_2 -> V_66 ;
V_17 = V_12 -> V_17 ;
for ( V_38 = 0 ; V_38 < V_12 -> V_142 ; V_38 ++ ) {
V_12 -> V_143 [ V_38 ] . V_220 = false ;
V_12 -> V_143 [ V_38 ] . V_140 = V_221 ;
}
for ( V_38 = 0 ; V_38 < V_12 -> V_138 ; V_38 ++ ) {
V_12 -> V_139 [ V_38 ] . V_220 = false ;
V_12 -> V_139 [ V_38 ] . V_140 = V_221 ;
}
V_17 -> V_155 = V_160 ;
V_12 -> V_121 = V_125 ;
}
}
void F_84 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_13 ;
struct V_289 * V_292 = V_10 -> V_290 ;
struct V_1 * V_2 ;
struct V_293 * V_294 ;
if ( V_292 == NULL )
return;
V_294 = V_292 -> V_291 . V_294 ;
if ( ! V_294 || ! V_294 -> V_295 )
return;
V_10 -> V_15 . V_16 = 0 ;
V_10 -> V_15 . V_24 = 0 ;
F_24 (w, &card->widgets, list) {
if ( F_1 ( V_2 ) && ( V_2 -> V_66 != NULL ) )
F_83 ( V_292 , V_2 ) ;
}
F_85 ( V_14 -> V_118 ) ;
}
static int F_86 ( struct V_296 * V_297 ,
struct V_1 * V_2 ,
struct V_284 * V_285 )
{
int V_91 ;
struct V_298 * V_299 = F_87 ( V_297 ) ;
struct V_10 * V_10 = F_88 ( V_299 ) ;
struct V_300 * V_301 = F_89 ( V_299 ) ;
struct V_11 * V_12 ;
if ( ! V_285 -> V_66 . V_83 )
goto V_302;
V_12 = F_70 ( V_301 -> V_20 , sizeof( * V_12 ) , V_207 ) ;
if ( ! V_12 )
return - V_116 ;
V_2 -> V_66 = V_12 ;
V_12 -> V_3 . V_22 = - 1 ;
V_91 = F_82 ( V_285 , V_10 , V_301 -> V_20 , V_12 ) ;
if ( V_91 < 0 )
return V_91 ;
V_302:
if ( V_285 -> V_303 == 0 ) {
F_10 ( V_301 -> V_20 , L_31 ) ;
return 0 ;
}
V_91 = F_90 ( V_2 , V_304 ,
F_91 ( V_304 ) ,
V_285 -> V_303 ) ;
if ( V_91 ) {
F_3 ( V_301 -> V_20 , L_32 ,
V_21 , V_285 -> V_303 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_92 ( struct V_181 * V_20 , struct V_94 * V_305 ,
struct V_306 * V_97 )
{
struct V_96 * V_174 ;
struct V_307 * V_308 =
(struct V_307 * ) V_97 -> V_66 . V_171 ;
V_174 = F_70 ( V_20 , sizeof( * V_174 ) , V_207 ) ;
if ( ! V_174 )
return - V_116 ;
V_174 -> V_146 = V_308 -> V_146 ;
V_174 -> V_102 = V_308 -> V_102 ;
V_174 -> V_100 = V_308 -> V_100 ;
V_174 -> V_83 = V_308 -> V_146 ;
if ( V_174 -> V_146 ) {
V_174 -> V_41 = ( char * ) F_70 ( V_20 , V_174 -> V_146 , V_207 ) ;
if ( ! V_174 -> V_41 )
return - V_116 ;
memcpy ( V_174 -> V_41 , V_308 -> V_41 , V_174 -> V_146 ) ;
}
V_305 -> V_108 . V_109 = V_174 ;
return 0 ;
}
static int F_93 ( struct V_296 * V_297 ,
struct V_92 * V_309 ,
struct V_310 * V_311 )
{
struct V_94 * V_95 ;
struct V_306 * V_312 ;
struct V_298 * V_299 = F_87 ( V_297 ) ;
struct V_300 * V_301 = F_89 ( V_299 ) ;
switch ( V_311 -> V_313 . V_314 ) {
case V_315 :
V_312 = F_94 ( V_311 ,
struct V_306 , V_311 ) ;
if ( V_309 -> V_105 & V_106 ) {
V_95 = (struct V_94 * ) V_309 -> V_107 ;
if ( V_312 -> V_66 . V_83 )
return F_92 (
V_301 -> V_20 , V_95 , V_312 ) ;
}
break;
default:
F_80 ( V_301 -> V_20 , L_33 ,
V_311 -> V_313 . V_316 , V_311 -> V_313 . V_317 , V_311 -> V_313 . V_314 ) ;
break;
}
return 0 ;
}
static int F_95 ( struct V_181 * V_20 ,
struct V_318 * V_319 ,
struct V_320 * V_321 )
{
int V_239 = 0 ;
static int V_322 ;
switch ( V_319 -> V_219 ) {
case V_323 :
if ( V_322 > V_321 -> V_324 - 1 ) {
V_322 = 0 ;
return - V_81 ;
}
strncpy ( V_321 -> V_325 [ V_322 ] . V_89 , V_319 -> string ,
F_91 ( V_321 -> V_325 [ V_322 ] . V_89 ) ) ;
V_322 ++ ;
V_239 ++ ;
break;
default:
F_3 ( V_20 , L_34 , V_319 -> V_219 ) ;
break;
}
return V_239 ;
}
static int F_96 ( struct V_181 * V_20 ,
struct V_274 * V_275 ,
struct V_320 * V_321 )
{
int V_239 = 0 , V_91 ;
struct V_318 * V_319 ;
V_319 = (struct V_318 * ) V_275 -> V_205 ;
while ( V_239 < V_275 -> V_280 ) {
V_91 = F_95 ( V_20 , V_319 , V_321 ) ;
V_319 ++ ;
if ( V_91 < 0 )
return V_91 ;
V_239 = V_239 + V_91 ;
}
return V_239 ;
}
static int F_97 ( struct V_181 * V_20 ,
struct V_200 * V_201 ,
struct V_320 * V_321 )
{
int V_239 = 0 ;
switch ( V_201 -> V_219 ) {
case V_326 :
V_321 -> V_324 = V_201 -> V_205 ;
V_239 ++ ;
break;
default:
F_3 ( V_20 , L_35 , V_201 -> V_219 ) ;
return - V_81 ;
}
return V_239 ;
}
static int F_98 ( struct V_181 * V_20 ,
char * V_272 , struct V_320 * V_321 ,
int V_273 )
{
int V_239 = 0 , V_91 ;
int V_276 = 0 , V_277 = 0 ;
struct V_274 * V_275 ;
struct V_200 * V_201 ;
if ( V_273 <= 0 )
return - V_81 ;
while ( V_277 < V_273 ) {
V_275 = (struct V_274 * ) ( V_272 + V_276 ) ;
V_276 += V_275 -> V_83 ;
switch ( V_275 -> type ) {
case V_278 :
V_91 = F_96 ( V_20 , V_275 , V_321 ) ;
if ( V_91 < 0 )
return V_91 ;
V_239 += V_91 ;
V_277 += V_239 *
sizeof( struct V_318 ) ;
continue;
case V_279 :
F_80 ( V_20 , L_36 ) ;
continue;
default:
V_201 = V_275 -> V_205 ;
V_239 = 0 ;
break;
}
while ( V_239 <= V_275 -> V_280 - 1 ) {
V_91 = F_97 ( V_20 ,
V_201 , V_321 ) ;
if ( V_91 < 0 )
return V_91 ;
V_239 = V_239 + V_91 ;
V_201 ++ ;
V_277 += V_239 *
sizeof( struct V_200 ) ;
break;
}
V_239 = 0 ;
}
return 0 ;
}
static int F_99 ( struct V_327 * V_328 ,
struct V_181 * V_20 , struct V_320 * V_321 )
{
struct V_274 * V_275 ;
int V_286 , V_273 = 0 , V_287 , V_276 = 0 ;
char * V_171 ;
int V_91 ;
V_275 = (struct V_274 * ) V_328 -> V_66 . V_171 ;
V_91 = F_81 ( V_20 , V_275 ) ;
if ( V_91 < 0 )
return V_91 ;
V_286 = V_91 ;
V_276 += V_275 -> V_83 ;
V_275 = (struct V_274 * )
( V_328 -> V_66 . V_171 + V_276 ) ;
while ( V_286 > 0 ) {
V_91 = F_81 ( V_20 , V_275 ) ;
if ( V_91 < 0 )
return V_91 ;
V_287 = V_91 ;
V_276 += V_275 -> V_83 ;
V_275 = (struct V_274 * )
( V_328 -> V_66 . V_171 + V_276 ) ;
V_91 = F_81 ( V_20 , V_275 ) ;
if ( V_91 < 0 )
return V_91 ;
V_273 = V_91 ;
V_276 += V_275 -> V_83 ;
V_275 = (struct V_274 * )
( V_328 -> V_66 . V_171 + V_276 ) ;
V_171 = ( V_328 -> V_66 . V_171 + V_276 ) ;
if ( V_287 == V_288 ) {
V_91 = F_98 ( V_20 , V_171 , V_321 ,
V_273 ) ;
if ( V_91 < 0 )
return V_91 ;
-- V_286 ;
} else {
return - V_81 ;
}
}
return 0 ;
}
static int F_100 ( struct V_296 * V_297 ,
struct V_327 * V_328 )
{
struct V_320 * V_321 ;
struct V_298 * V_299 = F_87 ( V_297 ) ;
struct V_300 * V_301 = F_89 ( V_299 ) ;
struct V_10 * V_10 = F_88 ( V_299 ) ;
int V_91 = 0 ;
if ( V_328 -> V_66 . V_83 == 0 )
return 0 ;
V_321 = & V_10 -> V_13 -> V_328 ;
F_99 ( V_328 , V_301 -> V_20 , V_321 ) ;
if ( V_321 -> V_324 > V_329 ) {
F_3 ( V_301 -> V_20 , L_37 ,
V_321 -> V_324 ) ;
V_91 = - V_81 ;
}
return V_91 ;
}
static int F_101 ( struct V_289 * V_290 )
{
struct V_1 * V_2 ;
struct V_11 * V_26 = NULL ;
struct V_112 * V_330 = NULL ;
struct V_111 * V_17 ;
F_24 (w, &platform->component.card->widgets, list) {
if ( F_1 ( V_2 ) && V_2 -> V_66 != NULL ) {
V_26 = V_2 -> V_66 ;
V_17 = V_26 -> V_17 ;
V_330 = F_70 ( V_290 -> V_20 ,
sizeof( * V_330 ) , V_207 ) ;
if ( ! V_330 )
return - V_116 ;
V_330 -> V_2 = V_2 ;
F_102 ( & V_330 -> V_209 , & V_17 -> V_208 ) ;
}
}
return 0 ;
}
static void F_103 ( struct V_10 * V_10 , struct V_111 * V_17 )
{
struct V_112 * V_113 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
bool V_331 = false , V_332 = false ;
F_24 (w_module, &pipe->w_list, node) {
V_2 = V_113 -> V_2 ;
V_12 = V_2 -> V_66 ;
if ( V_12 -> V_73 == V_179 )
V_331 = true ;
else if ( V_12 -> V_73 != V_333 )
V_332 = true ;
}
if ( V_331 && V_332 )
V_17 -> V_176 = true ;
else
V_17 -> V_176 = false ;
}
int F_104 ( struct V_289 * V_290 , struct V_298 * V_299 )
{
int V_91 ;
const struct V_334 * V_335 ;
struct V_300 * V_301 = F_89 ( V_299 ) ;
struct V_10 * V_10 = F_88 ( V_299 ) ;
struct V_202 * V_203 ;
V_91 = F_105 ( & V_335 , V_10 -> V_336 , V_301 -> V_20 ) ;
if ( V_91 < 0 ) {
F_3 ( V_301 -> V_20 , L_38 ,
V_10 -> V_336 , V_91 ) ;
V_91 = F_105 ( & V_335 , L_39 , V_301 -> V_20 ) ;
if ( V_91 < 0 ) {
F_3 ( V_301 -> V_20 , L_40 ,
L_39 , V_91 ) ;
return V_91 ;
}
}
V_91 = F_106 ( & V_290 -> V_291 ,
& V_337 , V_335 , 0 ) ;
if ( V_91 < 0 ) {
F_3 ( V_301 -> V_20 , L_41 , V_91 ) ;
F_107 ( V_335 ) ;
return - V_81 ;
}
V_10 -> V_15 . V_25 = V_338 ;
V_10 -> V_15 . V_19 = V_339 ;
V_10 -> V_340 = V_335 ;
V_91 = F_101 ( V_290 ) ;
if ( V_91 < 0 )
return V_91 ;
F_24 (ppl, &skl->ppl_list, node)
F_103 ( V_10 , V_203 -> V_17 ) ;
return 0 ;
}
