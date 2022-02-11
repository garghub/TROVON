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
static int F_20 ( struct V_91 * V_20 ,
struct V_1 * V_2 , struct V_92 * V_17 )
{
struct V_11 * V_93 = NULL ;
struct V_94 * V_95 = NULL ;
struct V_96 * V_97 = NULL ;
V_97 = F_21 ( V_20 , sizeof( * V_97 ) , V_98 ) ;
if ( ! V_97 )
return - V_99 ;
V_97 -> V_2 = V_2 ;
F_22 ( & V_97 -> V_100 , & V_17 -> V_101 ) ;
F_23 (w, p) {
if ( ( V_95 -> V_102 -> V_66 == NULL )
&& ( ! F_1 ( V_2 ) ) )
continue;
if ( ( V_95 -> V_102 -> V_66 != NULL ) && V_95 -> V_103
&& F_1 ( V_95 -> V_102 ) ) {
V_93 = V_95 -> V_102 -> V_66 ;
if ( V_17 -> V_104 == V_93 -> V_17 -> V_104 )
F_20 ( V_20 ,
V_95 -> V_102 , V_17 ) ;
}
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
int V_38 , V_105 ;
struct V_11 * V_12 = V_2 -> V_66 ;
const struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
if ( V_12 -> V_71 . V_72 > 0 &&
V_12 -> V_71 . V_114 == V_115 ) {
V_113 = & V_12 -> V_71 ;
V_105 = F_25 ( V_14 , V_113 -> V_84 ,
V_113 -> V_72 ,
V_113 -> V_116 , V_12 ) ;
if ( V_105 < 0 )
return V_105 ;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_117 ; V_38 ++ ) {
V_107 = & V_2 -> V_118 [ V_38 ] ;
if ( V_107 -> V_119 & V_120 ) {
V_109 = ( void * ) V_107 -> V_121 ;
V_111 = (struct V_110 * ) V_109 -> V_122 . V_123 ;
if ( V_111 -> V_114 == V_115 ) {
V_105 = F_25 ( V_14 ,
( T_1 * ) V_111 -> V_41 , V_111 -> V_124 ,
V_111 -> V_116 , V_12 ) ;
if ( V_105 < 0 )
return V_105 ;
}
}
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
const struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_11 * V_12 = V_2 -> V_66 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_117 ; V_38 ++ ) {
V_107 = & V_2 -> V_118 [ V_38 ] ;
if ( V_107 -> V_119 & V_120 ) {
V_109 = (struct V_108 * ) V_107 -> V_121 ;
V_111 = (struct V_110 * ) V_109 -> V_122 . V_123 ;
if ( V_111 -> V_114 != V_125 )
continue;
V_12 -> V_71 . V_84 = ( T_1 * ) & V_111 -> V_41 ;
V_12 -> V_71 . V_72 = V_111 -> V_124 ;
break;
}
}
return 0 ;
}
static int
F_27 ( struct V_10 * V_10 , struct V_92 * V_17 )
{
struct V_96 * V_126 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_105 = 0 ;
F_28 (w_module, &pipe->w_list, node) {
V_2 = V_126 -> V_2 ;
V_12 = V_2 -> V_66 ;
if ( ! F_5 ( V_10 , V_12 ) )
return - V_99 ;
F_6 ( V_10 , V_12 ) ;
if ( V_12 -> V_127 && V_14 -> V_128 -> V_129 . V_130 ) {
V_105 = V_14 -> V_128 -> V_129 . V_130 ( V_14 -> V_128 ,
V_12 -> V_3 . V_22 , V_12 -> V_131 ) ;
if ( V_105 < 0 )
return V_105 ;
V_12 -> V_132 = V_133 ;
}
F_16 ( V_2 , V_14 ) ;
F_19 ( V_2 , V_14 ) ;
F_26 ( V_2 ) ;
V_105 = F_29 ( V_14 , V_12 ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_24 ( V_2 , V_14 ) ;
if ( V_105 < 0 )
return V_105 ;
}
return 0 ;
}
static int F_30 ( struct V_13 * V_14 ,
struct V_92 * V_17 )
{
struct V_96 * V_126 = NULL ;
struct V_11 * V_12 = NULL ;
F_28 (w_module, &pipe->w_list, node) {
V_12 = V_126 -> V_2 -> V_66 ;
if ( V_12 -> V_127 && V_14 -> V_128 -> V_129 . V_134 &&
V_12 -> V_132 > V_135 )
return V_14 -> V_128 -> V_129 . V_134 ( V_14 -> V_128 ,
V_12 -> V_3 . V_22 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
int V_105 ;
struct V_11 * V_12 = V_2 -> V_66 ;
struct V_96 * V_126 ;
struct V_92 * V_136 = V_12 -> V_17 ;
struct V_11 * V_93 = NULL , * V_137 ;
struct V_13 * V_14 = V_10 -> V_13 ;
if ( ! F_5 ( V_10 , V_12 ) )
return - V_138 ;
if ( ! F_2 ( V_10 , V_12 ) )
return - V_99 ;
F_4 ( V_10 , V_12 ) ;
F_6 ( V_10 , V_12 ) ;
V_105 = F_32 ( V_14 , V_12 -> V_17 ) ;
if ( V_105 < 0 )
return V_105 ;
if ( F_33 ( & V_136 -> V_101 ) ) {
V_105 = F_20 ( V_14 -> V_20 , V_2 , V_136 ) ;
if ( V_105 < 0 )
return V_105 ;
}
V_105 = F_27 ( V_10 , V_136 ) ;
if ( V_105 < 0 )
return V_105 ;
F_28 (w_module, &s_pipe->w_list, node) {
V_137 = V_126 -> V_2 -> V_66 ;
if ( V_93 == NULL ) {
V_93 = V_137 ;
continue;
}
V_105 = F_34 ( V_14 , V_93 , V_137 ) ;
if ( V_105 < 0 )
return V_105 ;
V_93 = V_137 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_11 * V_26 , struct V_13 * V_14 )
{
int V_38 , V_105 ;
struct V_11 * V_12 = V_2 -> V_66 ;
const struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
for ( V_38 = 0 ; V_38 < V_26 -> V_139 ; V_38 ++ ) {
if ( V_26 -> V_140 [ V_38 ] . V_141 != V_142 )
return 0 ;
}
for ( V_38 = 0 ; V_38 < V_26 -> V_143 ; V_38 ++ ) {
if ( V_26 -> V_144 [ V_38 ] . V_141 != V_142 )
return 0 ;
}
if ( V_12 -> V_71 . V_72 > 0 &&
V_12 -> V_71 . V_114 == V_145 ) {
V_113 = & V_12 -> V_71 ;
V_105 = F_25 ( V_14 , V_113 -> V_84 ,
V_113 -> V_72 ,
V_113 -> V_116 , V_12 ) ;
if ( V_105 < 0 )
return V_105 ;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_117 ; V_38 ++ ) {
V_107 = & V_2 -> V_118 [ V_38 ] ;
if ( V_107 -> V_119 & V_120 ) {
V_109 = ( void * ) V_107 -> V_121 ;
V_111 = (struct V_110 * ) V_109 -> V_122 . V_123 ;
if ( V_111 -> V_114 == V_145 ) {
V_105 = F_25 ( V_14 ,
( T_1 * ) V_111 -> V_41 , V_111 -> V_124 ,
V_111 -> V_116 , V_12 ) ;
if ( V_105 < 0 )
return V_105 ;
}
}
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_10 * V_10 ,
struct V_1 * V_146 ,
struct V_11 * V_147 )
{
struct V_94 * V_95 ;
struct V_1 * V_102 = NULL , * V_148 = NULL ;
struct V_11 * V_149 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_105 ;
F_23 (w, p) {
if ( ! V_95 -> V_103 )
continue;
F_10 ( V_14 -> V_20 , L_16 , V_21 , V_2 -> V_89 ) ;
F_10 ( V_14 -> V_20 , L_17 , V_21 , V_95 -> V_102 -> V_89 ) ;
V_148 = V_95 -> V_102 ;
if ( ! F_1 ( V_95 -> V_102 ) )
return F_36 ( V_95 -> V_102 , V_10 , V_146 , V_147 ) ;
if ( ( V_95 -> V_102 -> V_66 != NULL ) &&
F_1 ( V_95 -> V_102 ) ) {
V_102 = V_95 -> V_102 ;
V_149 = V_102 -> V_66 ;
if ( V_147 -> V_132 == V_135 ||
V_149 -> V_132 == V_135 )
continue;
V_105 = F_34 ( V_14 , V_147 , V_149 ) ;
if ( V_105 )
return V_105 ;
F_35 ( V_146 , V_147 , V_14 ) ;
F_35 ( V_102 , V_149 , V_14 ) ;
if ( V_149 -> V_17 -> V_150 != V_151 ) {
if ( V_149 -> V_17 -> V_88 !=
V_90 )
V_105 = F_37 ( V_14 ,
V_149 -> V_17 ) ;
if ( V_105 )
return V_105 ;
}
}
}
if ( ! V_102 )
return F_36 ( V_148 , V_10 , V_146 , V_147 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_147 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_105 = 0 ;
V_147 = V_2 -> V_66 ;
V_105 = F_36 ( V_2 , V_10 , V_2 , V_147 ) ;
if ( V_105 )
return V_105 ;
if ( V_147 -> V_17 -> V_88 != V_90 )
return F_37 ( V_14 , V_147 -> V_17 ) ;
return 0 ;
}
static struct V_1 * F_39 (
struct V_1 * V_2 , struct V_10 * V_10 )
{
struct V_94 * V_95 ;
struct V_1 * V_146 = NULL ;
struct V_13 * V_14 = V_10 -> V_13 ;
F_40 (w, p) {
V_146 = V_95 -> V_152 ;
if ( ! V_95 -> V_103 )
continue;
F_10 ( V_14 -> V_20 , L_18 , V_2 -> V_89 ) ;
F_10 ( V_14 -> V_20 , L_19 , V_95 -> V_152 -> V_89 ) ;
if ( ( V_95 -> V_152 -> V_66 != NULL ) &&
F_1 ( V_95 -> V_152 ) ) {
return V_95 -> V_152 ;
}
}
if ( V_146 != NULL )
return F_39 ( V_146 , V_10 ) ;
return NULL ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
int V_105 = 0 ;
struct V_1 * V_152 , * V_102 ;
struct V_11 * V_147 , * V_149 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_153 = 0 ;
V_102 = V_2 ;
V_149 = V_102 -> V_66 ;
V_152 = F_39 ( V_2 , V_10 ) ;
if ( V_152 != NULL ) {
V_147 = V_152 -> V_66 ;
V_149 = V_102 -> V_66 ;
V_153 = 1 ;
if ( V_147 -> V_17 -> V_150 != V_151 )
V_153 = 0 ;
}
if ( V_153 ) {
V_105 = F_34 ( V_14 , V_147 , V_149 ) ;
if ( V_105 )
return V_105 ;
F_35 ( V_152 , V_147 , V_14 ) ;
F_35 ( V_102 , V_149 , V_14 ) ;
if ( V_149 -> V_17 -> V_88 != V_90 )
V_105 = F_37 ( V_14 , V_149 -> V_17 ) ;
}
return V_105 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_147 , * V_149 ;
int V_105 = 0 , V_38 ;
struct V_13 * V_14 = V_10 -> V_13 ;
V_149 = V_2 -> V_66 ;
V_105 = F_43 ( V_14 , V_149 -> V_17 ) ;
if ( V_105 )
return V_105 ;
for ( V_38 = 0 ; V_38 < V_149 -> V_143 ; V_38 ++ ) {
if ( V_149 -> V_144 [ V_38 ] . V_141 == V_142 ) {
V_147 = V_149 -> V_144 [ V_38 ] . V_154 ;
if ( ! V_147 )
continue;
V_105 = F_43 ( V_14 , V_147 -> V_17 ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_44 ( V_14 ,
V_147 , V_149 ) ;
}
}
return V_105 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_66 ;
struct V_96 * V_126 ;
struct V_11 * V_93 = NULL , * V_137 ;
struct V_13 * V_14 = V_10 -> V_13 ;
struct V_92 * V_136 = V_12 -> V_17 ;
int V_105 = 0 ;
F_7 ( V_10 , V_12 ) ;
F_8 ( V_10 , V_12 ) ;
F_28 (w_module, &s_pipe->w_list, node) {
V_137 = V_126 -> V_2 -> V_66 ;
F_7 ( V_10 , V_137 ) ;
if ( V_93 == NULL ) {
V_93 = V_137 ;
continue;
}
F_44 ( V_14 , V_93 , V_137 ) ;
V_93 = V_137 ;
}
V_105 = F_46 ( V_14 , V_12 -> V_17 ) ;
return F_30 ( V_14 , V_136 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_147 , * V_149 ;
int V_105 = 0 , V_38 ;
struct V_13 * V_14 = V_10 -> V_13 ;
V_147 = V_2 -> V_66 ;
V_105 = F_43 ( V_14 , V_147 -> V_17 ) ;
if ( V_105 )
return V_105 ;
for ( V_38 = 0 ; V_38 < V_147 -> V_139 ; V_38 ++ ) {
if ( V_147 -> V_140 [ V_38 ] . V_141 == V_142 ) {
V_149 = V_147 -> V_140 [ V_38 ] . V_154 ;
if ( ! V_149 )
continue;
V_105 = F_44 ( V_14 , V_147 ,
V_149 ) ;
}
}
return V_105 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_155 * V_107 , int V_156 )
{
struct V_157 * V_158 = V_2 -> V_158 ;
struct V_10 * V_10 = F_17 ( V_158 -> V_20 ) ;
switch ( V_156 ) {
case V_159 :
return F_31 ( V_2 , V_10 ) ;
case V_160 :
return F_41 ( V_2 , V_10 ) ;
case V_161 :
return F_42 ( V_2 , V_10 ) ;
case V_162 :
return F_45 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_155 * V_107 , int V_156 )
{
struct V_157 * V_158 = V_2 -> V_158 ;
struct V_10 * V_10 = F_17 ( V_158 -> V_20 ) ;
switch ( V_156 ) {
case V_159 :
return F_31 ( V_2 , V_10 ) ;
case V_160 :
return F_41 ( V_2 , V_10 ) ;
case V_161 :
return F_42 ( V_2 , V_10 ) ;
case V_162 :
return F_45 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_155 * V_107 , int V_156 )
{
struct V_157 * V_158 = V_2 -> V_158 ;
struct V_10 * V_10 = F_17 ( V_158 -> V_20 ) ;
switch ( V_156 ) {
case V_159 :
return F_38 ( V_2 , V_10 ) ;
case V_162 :
return F_47 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_51 ( struct V_155 * V_163 ,
unsigned int T_2 * V_164 , unsigned int V_83 )
{
struct V_108 * V_109 =
(struct V_108 * ) V_163 -> V_121 ;
struct V_110 * V_111 = (struct V_110 * ) V_109 -> V_122 . V_123 ;
struct V_1 * V_2 = F_52 ( V_163 ) ;
struct V_11 * V_12 = V_2 -> V_66 ;
struct V_10 * V_10 = F_17 ( V_2 -> V_158 -> V_20 ) ;
if ( V_2 -> V_165 )
F_53 ( V_10 -> V_13 , ( T_1 * ) V_111 -> V_41 ,
V_111 -> V_124 , V_111 -> V_116 , V_12 ) ;
V_83 -= 2 * sizeof( T_1 ) ;
if ( V_83 > V_111 -> V_124 )
V_83 = V_111 -> V_124 ;
if ( V_111 -> V_41 ) {
if ( F_54 ( V_164 , & V_111 -> V_116 , sizeof( T_1 ) ) )
return - V_166 ;
if ( F_54 ( V_164 + 1 , & V_83 , sizeof( T_1 ) ) )
return - V_166 ;
if ( F_54 ( V_164 + 2 , V_111 -> V_41 , V_83 ) )
return - V_166 ;
}
return 0 ;
}
static int F_55 ( struct V_155 * V_163 ,
const unsigned int T_2 * V_164 , unsigned int V_83 )
{
struct V_1 * V_2 = F_52 ( V_163 ) ;
struct V_11 * V_12 = V_2 -> V_66 ;
struct V_108 * V_109 =
(struct V_108 * ) V_163 -> V_121 ;
struct V_110 * V_167 = (struct V_110 * ) V_109 -> V_122 . V_123 ;
struct V_10 * V_10 = F_17 ( V_2 -> V_158 -> V_20 ) ;
if ( V_167 -> V_41 ) {
if ( V_167 -> V_116 == V_168 ) {
if ( F_56 ( V_167 -> V_41 , V_164 , V_83 ) )
return - V_166 ;
} else {
if ( F_56 ( V_167 -> V_41 ,
V_164 + 2 , V_83 ) )
return - V_166 ;
}
if ( V_2 -> V_165 )
return F_25 ( V_10 -> V_13 ,
( T_1 * ) V_167 -> V_41 , V_167 -> V_124 ,
V_167 -> V_116 , V_12 ) ;
}
return 0 ;
}
int F_57 ( struct V_91 * V_20 ,
struct V_11 * V_12 ,
struct V_40 * V_41 )
{
struct V_92 * V_17 = V_12 -> V_17 ;
struct V_33 * V_169 = NULL ;
memcpy ( V_17 -> V_86 , V_41 , sizeof( * V_41 ) ) ;
if ( V_41 -> V_55 == V_56 )
V_169 = & V_12 -> V_27 [ 0 ] ;
else
V_169 = & V_12 -> V_32 [ 0 ] ;
V_169 -> V_29 = V_41 -> V_29 ;
V_169 -> V_28 = V_41 -> V_45 ;
V_169 -> V_31 = F_13 ( V_41 -> V_47 ) ;
switch ( V_169 -> V_31 ) {
case V_48 :
V_169 -> V_49 = V_169 -> V_31 ;
break;
case V_170 :
case V_50 :
V_169 -> V_49 = V_50 ;
break;
default:
F_3 ( V_20 , L_20 ,
V_169 -> V_31 ) ;
return - V_81 ;
}
if ( V_41 -> V_55 == V_56 ) {
V_12 -> V_64 = ( V_169 -> V_29 / 1000 ) *
( V_169 -> V_28 ) *
( V_169 -> V_49 >> 3 ) ;
} else {
V_12 -> V_65 = ( V_169 -> V_29 / 1000 ) *
( V_169 -> V_28 ) *
( V_169 -> V_49 >> 3 ) ;
}
return 0 ;
}
struct V_11 *
F_58 ( struct V_171 * V_172 , int V_55 )
{
struct V_1 * V_2 ;
struct V_94 * V_95 = NULL ;
if ( V_55 == V_56 ) {
V_2 = V_172 -> V_173 ;
F_23 (w, p) {
if ( V_95 -> V_103 && V_95 -> V_102 -> V_165 &&
! F_1 ( V_95 -> V_102 ) )
continue;
if ( V_95 -> V_102 -> V_66 ) {
F_10 ( V_172 -> V_20 , L_21 ,
V_95 -> V_102 -> V_89 ) ;
return V_95 -> V_102 -> V_66 ;
}
}
} else {
V_2 = V_172 -> V_174 ;
F_40 (w, p) {
if ( V_95 -> V_103 && V_95 -> V_152 -> V_165 &&
! F_1 ( V_95 -> V_152 ) )
continue;
if ( V_95 -> V_152 -> V_66 ) {
F_10 ( V_172 -> V_20 , L_21 ,
V_95 -> V_152 -> V_89 ) ;
return V_95 -> V_152 -> V_66 ;
}
}
}
return NULL ;
}
static struct V_11 * F_59 (
struct V_171 * V_172 , struct V_1 * V_2 )
{
struct V_94 * V_95 ;
struct V_11 * V_12 = NULL ;
F_40 (w, p) {
if ( V_2 -> V_175 [ V_176 ] > 0 ) {
if ( V_95 -> V_103 &&
( V_95 -> V_102 -> V_3 == V_7 ) &&
V_95 -> V_152 -> V_66 ) {
V_12 = V_95 -> V_152 -> V_66 ;
return V_12 ;
}
V_12 = F_59 ( V_172 , V_95 -> V_152 ) ;
if ( V_12 )
return V_12 ;
}
}
return V_12 ;
}
static struct V_11 * F_60 (
struct V_171 * V_172 , struct V_1 * V_2 )
{
struct V_94 * V_95 ;
struct V_11 * V_12 = NULL ;
F_23 (w, p) {
if ( V_2 -> V_175 [ V_177 ] > 0 ) {
if ( V_95 -> V_103 &&
( V_95 -> V_152 -> V_3 == V_6 ) &&
V_95 -> V_102 -> V_66 ) {
V_12 = V_95 -> V_102 -> V_66 ;
return V_12 ;
}
V_12 = F_60 ( V_172 , V_95 -> V_102 ) ;
if ( V_12 )
return V_12 ;
}
}
return V_12 ;
}
struct V_11 *
F_61 ( struct V_171 * V_172 , int V_55 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
if ( V_55 == V_56 ) {
V_2 = V_172 -> V_173 ;
V_12 = F_59 ( V_172 , V_2 ) ;
} else {
V_2 = V_172 -> V_174 ;
V_12 = F_60 ( V_172 , V_2 ) ;
}
return V_12 ;
}
static T_3 F_62 ( int V_73 )
{
int V_105 ;
switch ( V_73 ) {
case V_178 :
V_105 = V_78 ;
break;
case V_74 :
V_105 = V_75 ;
break;
case V_77 :
V_105 = V_78 ;
break;
case V_179 :
V_105 = V_180 ;
break;
default:
V_105 = V_181 ;
break;
}
return V_105 ;
}
static int F_63 ( struct V_171 * V_172 ,
struct V_11 * V_12 ,
struct V_40 * V_41 )
{
struct V_92 * V_17 = V_12 -> V_17 ;
struct V_69 * V_70 ;
struct V_10 * V_10 = F_17 ( V_172 -> V_20 ) ;
int V_67 = F_62 ( V_12 -> V_73 ) ;
memcpy ( V_17 -> V_86 , V_41 , sizeof( * V_41 ) ) ;
if ( V_67 == V_180 )
return 0 ;
V_70 = F_18 ( V_10 , V_12 -> V_82 , V_67 ,
V_41 -> V_47 , V_41 -> V_45 ,
V_41 -> V_29 , V_41 -> V_55 ) ;
if ( V_70 ) {
V_12 -> V_71 . V_72 = V_70 -> V_83 ;
V_12 -> V_71 . V_84 = ( T_1 * ) & V_70 -> V_84 ;
} else {
F_3 ( V_172 -> V_20 , L_12 ,
V_12 -> V_82 , V_67 ,
V_41 -> V_55 ) ;
F_3 ( V_172 -> V_20 , L_13 ,
V_41 -> V_45 , V_41 -> V_29 , V_41 -> V_47 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_64 ( struct V_171 * V_172 ,
struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_94 * V_95 ;
int V_105 = - V_85 ;
F_40 (w, p) {
if ( V_95 -> V_103 && F_1 ( V_95 -> V_152 ) &&
V_95 -> V_152 -> V_66 ) {
V_105 = F_63 ( V_172 ,
V_95 -> V_152 -> V_66 , V_41 ) ;
if ( V_105 < 0 )
return V_105 ;
} else {
V_105 = F_64 ( V_172 ,
V_95 -> V_152 , V_41 ) ;
if ( V_105 < 0 )
return V_105 ;
}
}
return V_105 ;
}
static int F_65 ( struct V_171 * V_172 ,
struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_94 * V_95 = NULL ;
int V_105 = - V_85 ;
F_23 (w, p) {
if ( V_95 -> V_103 && F_1 ( V_95 -> V_102 ) &&
V_95 -> V_102 -> V_66 ) {
V_105 = F_63 ( V_172 ,
V_95 -> V_102 -> V_66 , V_41 ) ;
if ( V_105 < 0 )
return V_105 ;
} else {
V_105 = F_65 (
V_172 , V_95 -> V_102 , V_41 ) ;
if ( V_105 < 0 )
return V_105 ;
}
}
return V_105 ;
}
int F_66 ( struct V_171 * V_172 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 ;
if ( V_41 -> V_55 == V_56 ) {
V_2 = V_172 -> V_173 ;
return F_64 ( V_172 , V_2 , V_41 ) ;
} else {
V_2 = V_172 -> V_174 ;
return F_65 ( V_172 , V_2 , V_41 ) ;
}
return 0 ;
}
static void F_67 ( struct V_182 * V_183 ,
struct V_184 * V_185 ,
bool V_186 , int V_187 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_187 ; V_38 ++ ) {
V_185 [ V_38 ] . V_3 . V_22 = V_183 [ V_38 ] . V_22 ;
V_185 [ V_38 ] . V_3 . V_23 = V_183 [ V_38 ] . V_23 ;
V_185 [ V_38 ] . V_188 = false ;
V_185 [ V_38 ] . V_186 = V_186 ;
V_185 [ V_38 ] . V_141 = V_189 ;
}
}
static struct V_92 * F_68 ( struct V_91 * V_20 ,
struct V_10 * V_10 , struct V_190 * V_191 )
{
struct V_192 * V_193 ;
struct V_92 * V_17 ;
struct V_40 * V_41 ;
F_28 (ppl, &skl->ppl_list, node) {
if ( V_193 -> V_17 -> V_104 == V_191 -> V_194 )
return V_193 -> V_17 ;
}
V_193 = F_21 ( V_20 , sizeof( * V_193 ) , V_98 ) ;
if ( ! V_193 )
return NULL ;
V_17 = F_21 ( V_20 , sizeof( * V_17 ) , V_98 ) ;
if ( ! V_17 )
return NULL ;
V_41 = F_21 ( V_20 , sizeof( * V_41 ) , V_98 ) ;
if ( ! V_41 )
return NULL ;
V_17 -> V_104 = V_191 -> V_194 ;
V_17 -> V_18 = V_191 -> V_18 ;
V_17 -> V_195 = V_191 -> V_195 ;
V_17 -> V_88 = V_191 -> V_88 ;
V_17 -> V_150 = V_196 ;
V_17 -> V_86 = V_41 ;
F_69 ( & V_17 -> V_101 ) ;
V_193 -> V_17 = V_17 ;
F_70 ( & V_193 -> V_100 , & V_10 -> V_197 ) ;
return V_193 -> V_17 ;
}
static void F_71 ( struct V_33 * V_198 ,
struct V_199 * V_200 ,
int V_201 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_201 ; V_38 ++ ) {
V_198 [ V_38 ] . V_28 = V_200 [ V_38 ] . V_28 ;
V_198 [ V_38 ] . V_29 = V_200 [ V_38 ] . V_202 ;
V_198 [ V_38 ] . V_49 = V_200 [ V_38 ] . V_49 ;
V_198 [ V_38 ] . V_31 = V_200 [ V_38 ] . V_31 ;
V_198 [ V_38 ] . V_30 = V_200 [ V_38 ] . V_30 ;
V_198 [ V_38 ] . V_39 = V_200 [ V_38 ] . V_39 ;
V_198 [ V_38 ] . V_203 = V_200 [ V_38 ] . V_203 ;
V_198 [ V_38 ] . V_204 = V_200 [ V_38 ] . V_204 ;
}
}
static int F_72 ( struct V_205 * V_206 ,
struct V_1 * V_2 ,
struct V_207 * V_208 )
{
int V_105 ;
struct V_209 * V_210 = F_73 ( V_206 ) ;
struct V_10 * V_10 = F_74 ( V_210 ) ;
struct V_211 * V_212 = F_75 ( V_210 ) ;
struct V_11 * V_12 ;
struct V_92 * V_17 ;
struct V_213 * V_214 =
(struct V_213 * ) V_208 -> V_66 . V_164 ;
if ( ! V_208 -> V_66 . V_83 )
goto V_215;
V_12 = F_21 ( V_212 -> V_20 , sizeof( * V_12 ) , V_98 ) ;
if ( ! V_12 )
return - V_99 ;
V_2 -> V_66 = V_12 ;
memcpy ( & V_12 -> V_131 , & V_214 -> V_216 , 16 ) ;
V_12 -> V_3 . V_22 = V_214 -> V_22 ;
V_12 -> V_3 . V_23 = V_214 -> V_23 ;
V_12 -> V_24 = V_214 -> V_25 ;
V_12 -> V_64 = V_214 -> V_64 ;
V_12 -> V_65 = V_214 -> V_65 ;
V_12 -> V_217 = V_214 -> V_217 ;
V_12 -> V_143 = V_214 -> V_143 ;
V_12 -> V_139 = V_214 -> V_139 ;
V_12 -> V_127 = V_214 -> V_127 ;
F_71 ( V_12 -> V_27 , V_214 -> V_27 ,
V_218 ) ;
F_71 ( V_12 -> V_32 , V_214 -> V_32 ,
V_219 ) ;
V_12 -> V_57 = V_214 -> V_57 ;
V_12 -> V_58 = V_214 -> V_58 ;
V_12 -> V_62 = V_214 -> V_220 ;
V_12 -> V_82 = V_214 -> V_82 ;
V_12 -> V_221 = V_214 -> V_221 ;
V_17 = F_68 ( V_212 -> V_20 , V_10 , & V_214 -> V_17 ) ;
if ( V_17 )
V_12 -> V_17 = V_17 ;
V_12 -> V_73 = V_214 -> V_73 ;
V_12 -> V_79 = V_214 -> V_79 ;
V_12 -> V_222 = V_214 -> V_222 ;
V_12 -> V_71 . V_72 = V_214 -> V_84 . V_72 ;
V_12 -> V_144 = F_21 ( V_212 -> V_20 , ( V_12 -> V_143 ) *
sizeof( * V_12 -> V_144 ) ,
V_98 ) ;
if ( ! V_12 -> V_144 )
return - V_99 ;
V_12 -> V_140 = F_21 ( V_212 -> V_20 , ( V_12 -> V_139 ) *
sizeof( * V_12 -> V_140 ) ,
V_98 ) ;
if ( ! V_12 -> V_140 )
return - V_99 ;
F_67 ( V_214 -> V_223 , V_12 -> V_144 ,
V_214 -> V_224 ,
V_12 -> V_143 ) ;
F_67 ( V_214 -> V_225 , V_12 -> V_140 ,
V_214 -> V_226 ,
V_12 -> V_139 ) ;
if ( V_12 -> V_71 . V_72 == 0 )
goto V_215;
V_12 -> V_71 . V_84 = ( T_1 * ) F_21 ( V_212 -> V_20 ,
V_12 -> V_71 . V_72 , V_98 ) ;
if ( V_12 -> V_71 . V_84 == NULL )
return - V_99 ;
memcpy ( V_12 -> V_71 . V_84 , V_214 -> V_84 . V_84 ,
V_214 -> V_84 . V_72 ) ;
V_12 -> V_71 . V_116 = V_214 -> V_84 . V_116 ;
V_12 -> V_71 . V_114 = V_214 -> V_84 . V_114 ;
V_215:
if ( V_208 -> V_227 == 0 ) {
F_10 ( V_212 -> V_20 , L_22 ) ;
return 0 ;
}
V_105 = F_76 ( V_2 , V_228 ,
F_77 ( V_228 ) ,
V_208 -> V_227 ) ;
if ( V_105 ) {
F_3 ( V_212 -> V_20 , L_23 ,
V_21 , V_208 -> V_227 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_78 ( struct V_91 * V_20 , struct V_108 * V_229 ,
struct V_230 * V_111 )
{
struct V_110 * V_167 ;
struct V_231 * V_232 =
(struct V_231 * ) V_111 -> V_66 . V_164 ;
V_167 = F_21 ( V_20 , sizeof( * V_167 ) , V_98 ) ;
if ( ! V_167 )
return - V_99 ;
V_167 -> V_124 = V_232 -> V_124 ;
V_167 -> V_116 = V_232 -> V_116 ;
V_167 -> V_114 = V_232 -> V_114 ;
if ( V_167 -> V_124 ) {
V_167 -> V_41 = ( char * ) F_21 ( V_20 , V_167 -> V_124 , V_98 ) ;
if ( ! V_167 -> V_41 )
return - V_99 ;
memcpy ( V_167 -> V_41 , V_232 -> V_41 , V_167 -> V_124 ) ;
}
V_229 -> V_122 . V_123 = V_167 ;
return 0 ;
}
static int F_79 ( struct V_205 * V_206 ,
struct V_106 * V_233 ,
struct V_234 * V_235 )
{
struct V_108 * V_109 ;
struct V_230 * V_236 ;
struct V_209 * V_210 = F_73 ( V_206 ) ;
struct V_211 * V_212 = F_75 ( V_210 ) ;
switch ( V_235 -> V_237 . V_238 ) {
case V_239 :
V_236 = F_80 ( V_235 ,
struct V_230 , V_235 ) ;
if ( V_233 -> V_119 & V_120 ) {
V_109 = (struct V_108 * ) V_233 -> V_121 ;
if ( V_236 -> V_66 . V_83 )
return F_78 (
V_212 -> V_20 , V_109 , V_236 ) ;
}
break;
default:
F_81 ( V_212 -> V_20 , L_24 ,
V_235 -> V_237 . V_240 , V_235 -> V_237 . V_241 , V_235 -> V_237 . V_238 ) ;
break;
}
return 0 ;
}
int F_82 ( struct V_242 * V_243 , struct V_209 * V_210 )
{
int V_105 ;
const struct V_244 * V_245 ;
struct V_211 * V_212 = F_75 ( V_210 ) ;
struct V_10 * V_10 = F_74 ( V_210 ) ;
V_105 = F_83 ( & V_245 , V_10 -> V_246 , V_212 -> V_20 ) ;
if ( V_105 < 0 ) {
F_3 ( V_212 -> V_20 , L_25 ,
V_10 -> V_246 , V_105 ) ;
V_105 = F_83 ( & V_245 , L_26 , V_212 -> V_20 ) ;
if ( V_105 < 0 ) {
F_3 ( V_212 -> V_20 , L_27 ,
L_26 , V_105 ) ;
return V_105 ;
}
}
V_105 = F_84 ( & V_243 -> V_247 ,
& V_248 , V_245 , 0 ) ;
if ( V_105 < 0 ) {
F_3 ( V_212 -> V_20 , L_28 , V_105 ) ;
F_85 ( V_245 ) ;
return - V_81 ;
}
V_10 -> V_15 . V_25 = V_249 ;
V_10 -> V_15 . V_19 = V_250 ;
V_10 -> V_251 = V_245 ;
return 0 ;
}
