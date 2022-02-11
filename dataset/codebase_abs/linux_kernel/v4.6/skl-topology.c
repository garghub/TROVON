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
static void F_11 ( struct V_33 * V_34 ,
struct V_35 * V_36 , int V_37 )
{
if ( V_37 & V_38 )
V_34 -> V_29 = V_36 -> V_29 ;
if ( V_37 & V_39 )
V_34 -> V_28 = V_36 -> V_40 ;
if ( V_37 & V_41 ) {
V_34 -> V_31 = F_12 ( V_36 -> V_42 ) ;
switch ( V_34 -> V_31 ) {
case V_43 :
V_34 -> V_44 = V_34 -> V_31 ;
break;
default:
V_34 -> V_44 = V_45 ;
break;
}
}
}
static void F_13 ( struct V_11 * V_46 ,
struct V_35 * V_36 , bool V_47 )
{
int V_48 , V_49 ;
struct V_33 * V_27 , * V_32 ;
V_27 = & V_46 -> V_27 [ 0 ] ;
V_32 = & V_46 -> V_32 [ 0 ] ;
if ( V_36 -> V_50 == V_51 ) {
if ( V_47 ) {
V_48 = V_46 -> V_52 ;
V_49 = ( ~ V_46 -> V_53 ) &
V_46 -> V_52 ;
} else {
V_49 = V_46 -> V_52 ;
V_48 = ( ~ V_46 -> V_53 ) &
V_46 -> V_52 ;
}
} else {
if ( V_47 ) {
V_49 = V_46 -> V_52 ;
V_48 = ( ~ V_46 -> V_53 ) &
V_46 -> V_52 ;
} else {
V_48 = V_46 -> V_52 ;
V_49 = ( ~ V_46 -> V_53 ) &
V_46 -> V_52 ;
}
}
F_11 ( V_27 , V_36 , V_48 ) ;
F_11 ( V_32 , V_36 , V_49 ) ;
}
static void F_14 ( struct V_13 * V_14 ,
struct V_11 * V_26 )
{
int V_54 = 1 ;
struct V_33 * V_27 , * V_32 ;
int V_55 , V_56 ;
V_27 = & V_26 -> V_27 [ 0 ] ;
V_32 = & V_26 -> V_32 [ 0 ] ;
if ( V_26 -> V_57 == V_58 )
V_54 = 5 ;
if ( V_27 -> V_29 % 1000 )
V_55 = ( V_27 -> V_29 / 1000 ) + 1 ;
else
V_55 = ( V_27 -> V_29 / 1000 ) ;
V_26 -> V_59 = V_55 * ( V_26 -> V_27 -> V_28 ) *
( V_26 -> V_27 -> V_44 >> 3 ) *
V_54 ;
if ( V_26 -> V_32 -> V_29 % 1000 )
V_56 = ( V_26 -> V_32 -> V_29 / 1000 ) + 1 ;
else
V_56 = ( V_26 -> V_32 -> V_29 / 1000 ) ;
V_26 -> V_60 = V_56 * ( V_26 -> V_32 -> V_28 ) *
( V_26 -> V_32 -> V_44 >> 3 ) *
V_54 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_11 * V_46 = V_2 -> V_61 ;
int V_62 , V_63 ;
T_1 V_40 , V_29 , V_42 ;
struct V_64 * V_65 ;
struct V_10 * V_10 = F_16 ( V_14 -> V_20 ) ;
if ( V_46 -> V_66 . V_67 > 0 )
return 0 ;
F_10 ( V_14 -> V_20 , L_11 ) ;
switch ( V_46 -> V_68 ) {
case V_69 :
V_62 = V_70 ;
V_63 = V_71 ;
V_29 = V_46 -> V_27 [ 0 ] . V_29 ;
V_42 = V_46 -> V_27 [ 0 ] . V_44 ;
V_40 = V_46 -> V_27 [ 0 ] . V_28 ;
break;
case V_72 :
V_62 = V_73 ;
if ( V_46 -> V_74 == V_75 ) {
V_63 = V_51 ;
V_29 = V_46 -> V_32 [ 0 ] . V_29 ;
V_42 = V_46 -> V_32 [ 0 ] . V_44 ;
V_40 = V_46 -> V_32 [ 0 ] . V_28 ;
} else {
V_63 = V_71 ;
V_29 = V_46 -> V_27 [ 0 ] . V_29 ;
V_42 = V_46 -> V_27 [ 0 ] . V_44 ;
V_40 = V_46 -> V_27 [ 0 ] . V_28 ;
}
break;
default:
return - V_76 ;
}
V_65 = F_17 ( V_10 , V_46 -> V_77 , V_62 ,
V_42 , V_40 , V_29 , V_63 ) ;
if ( V_65 ) {
V_46 -> V_66 . V_67 = V_65 -> V_78 ;
V_46 -> V_66 . V_79 = ( T_1 * ) & V_65 -> V_79 ;
} else {
F_3 ( V_14 -> V_20 , L_12 ,
V_46 -> V_77 , V_62 , V_63 ) ;
F_3 ( V_14 -> V_20 , L_13 ,
V_40 , V_29 , V_42 ) ;
return - V_80 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_11 * V_46 = V_2 -> V_61 ;
struct V_35 * V_36 = V_46 -> V_17 -> V_81 ;
int V_82 = V_46 -> V_17 -> V_83 ;
bool V_47 ;
if ( ! V_46 -> V_52 )
return;
F_10 ( V_14 -> V_20 , L_14 ,
V_2 -> V_84 ) ;
F_9 ( V_14 , V_46 ) ;
if ( V_82 == V_85 )
V_47 = true ;
else
V_47 = false ;
F_13 ( V_46 , V_36 , V_47 ) ;
F_14 ( V_14 , V_46 ) ;
F_10 ( V_14 -> V_20 , L_15 ,
V_2 -> V_84 ) ;
F_9 ( V_14 , V_46 ) ;
}
static int F_19 ( struct V_86 * V_20 ,
struct V_1 * V_2 , struct V_87 * V_17 )
{
struct V_11 * V_88 = NULL ;
struct V_89 * V_90 = NULL ;
struct V_91 * V_92 = NULL ;
V_92 = F_20 ( V_20 , sizeof( * V_92 ) , V_93 ) ;
if ( ! V_92 )
return - V_94 ;
V_92 -> V_2 = V_2 ;
F_21 ( & V_92 -> V_95 , & V_17 -> V_96 ) ;
F_22 (w, p) {
if ( ( V_90 -> V_97 -> V_61 == NULL )
&& ( ! F_1 ( V_2 ) ) )
continue;
if ( ( V_90 -> V_97 -> V_61 != NULL ) && V_90 -> V_98
&& F_1 ( V_90 -> V_97 ) ) {
V_88 = V_90 -> V_97 -> V_61 ;
if ( V_17 -> V_99 == V_88 -> V_17 -> V_99 )
F_19 ( V_20 ,
V_90 -> V_97 , V_17 ) ;
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
int V_100 , V_101 ;
struct V_11 * V_12 = V_2 -> V_61 ;
const struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
struct V_108 * V_109 ;
if ( V_12 -> V_66 . V_67 > 0 &&
V_12 -> V_66 . V_110 == V_111 ) {
V_109 = & V_12 -> V_66 ;
V_101 = F_24 ( V_14 , V_109 -> V_79 ,
V_109 -> V_67 ,
V_109 -> V_112 , V_12 ) ;
if ( V_101 < 0 )
return V_101 ;
}
for ( V_100 = 0 ; V_100 < V_2 -> V_113 ; V_100 ++ ) {
V_103 = & V_2 -> V_114 [ V_100 ] ;
if ( V_103 -> V_115 & V_116 ) {
V_105 = ( void * ) V_103 -> V_117 ;
V_107 = (struct V_106 * ) V_105 -> V_118 . V_119 ;
if ( V_107 -> V_110 == V_111 ) {
V_101 = F_24 ( V_14 ,
( T_1 * ) V_107 -> V_36 , V_107 -> V_120 ,
V_107 -> V_112 , V_12 ) ;
if ( V_101 < 0 )
return V_101 ;
}
}
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
const struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
struct V_11 * V_12 = V_2 -> V_61 ;
int V_100 ;
for ( V_100 = 0 ; V_100 < V_2 -> V_113 ; V_100 ++ ) {
V_103 = & V_2 -> V_114 [ V_100 ] ;
if ( V_103 -> V_115 & V_116 ) {
V_105 = (struct V_104 * ) V_103 -> V_117 ;
V_107 = (struct V_106 * ) V_105 -> V_118 . V_119 ;
if ( V_107 -> V_110 != V_121 )
continue;
V_12 -> V_66 . V_79 = ( T_1 * ) & V_107 -> V_36 ;
V_12 -> V_66 . V_67 = V_107 -> V_120 ;
break;
}
}
return 0 ;
}
static int
F_26 ( struct V_10 * V_10 , struct V_87 * V_17 )
{
struct V_91 * V_122 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_101 = 0 ;
F_27 (w_module, &pipe->w_list, node) {
V_2 = V_122 -> V_2 ;
V_12 = V_2 -> V_61 ;
if ( ! F_5 ( V_10 , V_12 ) )
return - V_94 ;
F_6 ( V_10 , V_12 ) ;
if ( V_12 -> V_123 && V_14 -> V_124 -> V_125 . V_126 ) {
V_101 = V_14 -> V_124 -> V_125 . V_126 ( V_14 -> V_124 ,
V_12 -> V_3 . V_22 , V_12 -> V_127 ) ;
if ( V_101 < 0 )
return V_101 ;
V_12 -> V_128 = V_129 ;
}
F_15 ( V_2 , V_14 ) ;
F_18 ( V_2 , V_14 ) ;
F_25 ( V_2 ) ;
V_101 = F_28 ( V_14 , V_12 ) ;
if ( V_101 < 0 )
return V_101 ;
V_101 = F_23 ( V_2 , V_14 ) ;
if ( V_101 < 0 )
return V_101 ;
}
return 0 ;
}
static int F_29 ( struct V_13 * V_14 ,
struct V_87 * V_17 )
{
struct V_91 * V_122 = NULL ;
struct V_11 * V_12 = NULL ;
F_27 (w_module, &pipe->w_list, node) {
V_12 = V_122 -> V_2 -> V_61 ;
if ( V_12 -> V_123 && V_14 -> V_124 -> V_125 . V_130 &&
V_12 -> V_128 > V_131 )
return V_14 -> V_124 -> V_125 . V_130 ( V_14 -> V_124 ,
V_12 -> V_3 . V_22 ) ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
int V_101 ;
struct V_11 * V_12 = V_2 -> V_61 ;
struct V_91 * V_122 ;
struct V_87 * V_132 = V_12 -> V_17 ;
struct V_11 * V_88 = NULL , * V_133 ;
struct V_13 * V_14 = V_10 -> V_13 ;
if ( ! F_5 ( V_10 , V_12 ) )
return - V_134 ;
if ( ! F_2 ( V_10 , V_12 ) )
return - V_94 ;
F_4 ( V_10 , V_12 ) ;
F_6 ( V_10 , V_12 ) ;
V_101 = F_31 ( V_14 , V_12 -> V_17 ) ;
if ( V_101 < 0 )
return V_101 ;
if ( F_32 ( & V_132 -> V_96 ) ) {
V_101 = F_19 ( V_14 -> V_20 , V_2 , V_132 ) ;
if ( V_101 < 0 )
return V_101 ;
}
V_101 = F_26 ( V_10 , V_132 ) ;
if ( V_101 < 0 )
return V_101 ;
F_27 (w_module, &s_pipe->w_list, node) {
V_133 = V_122 -> V_2 -> V_61 ;
if ( V_88 == NULL ) {
V_88 = V_133 ;
continue;
}
V_101 = F_33 ( V_14 , V_88 , V_133 ) ;
if ( V_101 < 0 )
return V_101 ;
V_88 = V_133 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_11 * V_26 , struct V_13 * V_14 )
{
int V_100 , V_101 ;
struct V_11 * V_12 = V_2 -> V_61 ;
const struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
struct V_108 * V_109 ;
for ( V_100 = 0 ; V_100 < V_26 -> V_135 ; V_100 ++ ) {
if ( V_26 -> V_136 [ V_100 ] . V_137 != V_138 )
return 0 ;
}
for ( V_100 = 0 ; V_100 < V_26 -> V_139 ; V_100 ++ ) {
if ( V_26 -> V_140 [ V_100 ] . V_137 != V_138 )
return 0 ;
}
if ( V_12 -> V_66 . V_67 > 0 &&
V_12 -> V_66 . V_110 == V_141 ) {
V_109 = & V_12 -> V_66 ;
V_101 = F_24 ( V_14 , V_109 -> V_79 ,
V_109 -> V_67 ,
V_109 -> V_112 , V_12 ) ;
if ( V_101 < 0 )
return V_101 ;
}
for ( V_100 = 0 ; V_100 < V_2 -> V_113 ; V_100 ++ ) {
V_103 = & V_2 -> V_114 [ V_100 ] ;
if ( V_103 -> V_115 & V_116 ) {
V_105 = ( void * ) V_103 -> V_117 ;
V_107 = (struct V_106 * ) V_105 -> V_118 . V_119 ;
if ( V_107 -> V_110 == V_141 ) {
V_101 = F_24 ( V_14 ,
( T_1 * ) V_107 -> V_36 , V_107 -> V_120 ,
V_107 -> V_112 , V_12 ) ;
if ( V_101 < 0 )
return V_101 ;
}
}
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_10 * V_10 ,
struct V_1 * V_142 ,
struct V_11 * V_143 )
{
struct V_89 * V_90 ;
struct V_1 * V_97 = NULL , * V_144 = NULL ;
struct V_11 * V_145 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_101 ;
F_22 (w, p) {
if ( ! V_90 -> V_98 )
continue;
F_10 ( V_14 -> V_20 , L_16 , V_21 , V_2 -> V_84 ) ;
F_10 ( V_14 -> V_20 , L_17 , V_21 , V_90 -> V_97 -> V_84 ) ;
V_144 = V_90 -> V_97 ;
if ( ! F_1 ( V_90 -> V_97 ) )
return F_35 ( V_90 -> V_97 , V_10 , V_142 , V_143 ) ;
if ( ( V_90 -> V_97 -> V_61 != NULL ) &&
F_1 ( V_90 -> V_97 ) ) {
V_97 = V_90 -> V_97 ;
V_145 = V_97 -> V_61 ;
if ( V_143 -> V_128 == V_131 ||
V_145 -> V_128 == V_131 )
continue;
V_101 = F_33 ( V_14 , V_143 , V_145 ) ;
if ( V_101 )
return V_101 ;
F_34 ( V_142 , V_143 , V_14 ) ;
F_34 ( V_97 , V_145 , V_14 ) ;
if ( V_145 -> V_17 -> V_146 != V_147 ) {
if ( V_145 -> V_17 -> V_83 !=
V_85 )
V_101 = F_36 ( V_14 ,
V_145 -> V_17 ) ;
if ( V_101 )
return V_101 ;
}
}
}
if ( ! V_97 )
return F_35 ( V_144 , V_10 , V_142 , V_143 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_143 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_101 = 0 ;
V_143 = V_2 -> V_61 ;
V_101 = F_35 ( V_2 , V_10 , V_2 , V_143 ) ;
if ( V_101 )
return V_101 ;
if ( V_143 -> V_17 -> V_83 != V_85 )
return F_36 ( V_14 , V_143 -> V_17 ) ;
return 0 ;
}
static struct V_1 * F_38 (
struct V_1 * V_2 , struct V_10 * V_10 )
{
struct V_89 * V_90 ;
struct V_1 * V_142 = NULL ;
struct V_13 * V_14 = V_10 -> V_13 ;
F_39 (w, p) {
V_142 = V_90 -> V_148 ;
if ( ! V_90 -> V_98 )
continue;
F_10 ( V_14 -> V_20 , L_18 , V_2 -> V_84 ) ;
F_10 ( V_14 -> V_20 , L_19 , V_90 -> V_148 -> V_84 ) ;
if ( ( V_90 -> V_148 -> V_61 != NULL ) &&
F_1 ( V_90 -> V_148 ) ) {
return V_90 -> V_148 ;
}
}
if ( V_142 != NULL )
return F_38 ( V_142 , V_10 ) ;
return NULL ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
int V_101 = 0 ;
struct V_1 * V_148 , * V_97 ;
struct V_11 * V_143 , * V_145 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_149 = 0 ;
V_97 = V_2 ;
V_145 = V_97 -> V_61 ;
V_148 = F_38 ( V_2 , V_10 ) ;
if ( V_148 != NULL ) {
V_143 = V_148 -> V_61 ;
V_145 = V_97 -> V_61 ;
V_149 = 1 ;
if ( V_143 -> V_17 -> V_146 != V_147 )
V_149 = 0 ;
}
if ( V_149 ) {
V_101 = F_33 ( V_14 , V_143 , V_145 ) ;
if ( V_101 )
return V_101 ;
F_34 ( V_148 , V_143 , V_14 ) ;
F_34 ( V_97 , V_145 , V_14 ) ;
if ( V_145 -> V_17 -> V_83 != V_85 )
V_101 = F_36 ( V_14 , V_145 -> V_17 ) ;
}
return V_101 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_143 , * V_145 ;
int V_101 = 0 , V_100 ;
struct V_13 * V_14 = V_10 -> V_13 ;
V_145 = V_2 -> V_61 ;
V_101 = F_42 ( V_14 , V_145 -> V_17 ) ;
if ( V_101 )
return V_101 ;
for ( V_100 = 0 ; V_100 < V_145 -> V_139 ; V_100 ++ ) {
if ( V_145 -> V_140 [ V_100 ] . V_137 == V_138 ) {
V_143 = V_145 -> V_140 [ V_100 ] . V_150 ;
if ( ! V_143 )
continue;
V_101 = F_42 ( V_14 , V_143 -> V_17 ) ;
if ( V_101 < 0 )
return V_101 ;
V_101 = F_43 ( V_14 ,
V_143 , V_145 ) ;
}
}
return V_101 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_61 ;
struct V_91 * V_122 ;
struct V_11 * V_88 = NULL , * V_133 ;
struct V_13 * V_14 = V_10 -> V_13 ;
struct V_87 * V_132 = V_12 -> V_17 ;
int V_101 = 0 ;
F_7 ( V_10 , V_12 ) ;
F_8 ( V_10 , V_12 ) ;
F_27 (w_module, &s_pipe->w_list, node) {
V_133 = V_122 -> V_2 -> V_61 ;
F_7 ( V_10 , V_133 ) ;
if ( V_88 == NULL ) {
V_88 = V_133 ;
continue;
}
F_43 ( V_14 , V_88 , V_133 ) ;
V_88 = V_133 ;
}
V_101 = F_45 ( V_14 , V_12 -> V_17 ) ;
return F_29 ( V_14 , V_132 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_143 , * V_145 ;
int V_101 = 0 , V_100 ;
struct V_13 * V_14 = V_10 -> V_13 ;
V_143 = V_2 -> V_61 ;
V_101 = F_42 ( V_14 , V_143 -> V_17 ) ;
if ( V_101 )
return V_101 ;
for ( V_100 = 0 ; V_100 < V_143 -> V_135 ; V_100 ++ ) {
if ( V_143 -> V_136 [ V_100 ] . V_137 == V_138 ) {
V_145 = V_143 -> V_136 [ V_100 ] . V_150 ;
if ( ! V_145 )
continue;
V_101 = F_43 ( V_14 , V_143 ,
V_145 ) ;
}
}
return V_101 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_151 * V_103 , int V_152 )
{
struct V_153 * V_154 = V_2 -> V_154 ;
struct V_10 * V_10 = F_16 ( V_154 -> V_20 ) ;
switch ( V_152 ) {
case V_155 :
return F_30 ( V_2 , V_10 ) ;
case V_156 :
return F_40 ( V_2 , V_10 ) ;
case V_157 :
return F_41 ( V_2 , V_10 ) ;
case V_158 :
return F_44 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_151 * V_103 , int V_152 )
{
struct V_153 * V_154 = V_2 -> V_154 ;
struct V_10 * V_10 = F_16 ( V_154 -> V_20 ) ;
switch ( V_152 ) {
case V_155 :
return F_30 ( V_2 , V_10 ) ;
case V_156 :
return F_40 ( V_2 , V_10 ) ;
case V_157 :
return F_41 ( V_2 , V_10 ) ;
case V_158 :
return F_44 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_151 * V_103 , int V_152 )
{
struct V_153 * V_154 = V_2 -> V_154 ;
struct V_10 * V_10 = F_16 ( V_154 -> V_20 ) ;
switch ( V_152 ) {
case V_155 :
return F_37 ( V_2 , V_10 ) ;
case V_158 :
return F_46 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_50 ( struct V_151 * V_159 ,
unsigned int T_2 * V_160 , unsigned int V_78 )
{
struct V_104 * V_105 =
(struct V_104 * ) V_159 -> V_117 ;
struct V_106 * V_107 = (struct V_106 * ) V_105 -> V_118 . V_119 ;
struct V_1 * V_2 = F_51 ( V_159 ) ;
struct V_11 * V_12 = V_2 -> V_61 ;
struct V_10 * V_10 = F_16 ( V_2 -> V_154 -> V_20 ) ;
if ( V_2 -> V_161 )
F_52 ( V_10 -> V_13 , ( T_1 * ) V_107 -> V_36 ,
V_107 -> V_120 , V_107 -> V_112 , V_12 ) ;
V_78 -= 2 * sizeof( T_1 ) ;
if ( V_78 > V_107 -> V_120 )
V_78 = V_107 -> V_120 ;
if ( V_107 -> V_36 ) {
if ( F_53 ( V_160 , & V_107 -> V_112 , sizeof( T_1 ) ) )
return - V_162 ;
if ( F_53 ( V_160 + 1 , & V_78 , sizeof( T_1 ) ) )
return - V_162 ;
if ( F_53 ( V_160 + 2 , V_107 -> V_36 , V_78 ) )
return - V_162 ;
}
return 0 ;
}
static int F_54 ( struct V_151 * V_159 ,
const unsigned int T_2 * V_160 , unsigned int V_78 )
{
struct V_1 * V_2 = F_51 ( V_159 ) ;
struct V_11 * V_12 = V_2 -> V_61 ;
struct V_104 * V_105 =
(struct V_104 * ) V_159 -> V_117 ;
struct V_106 * V_163 = (struct V_106 * ) V_105 -> V_118 . V_119 ;
struct V_10 * V_10 = F_16 ( V_2 -> V_154 -> V_20 ) ;
if ( V_163 -> V_36 ) {
if ( V_163 -> V_112 == V_164 ) {
if ( F_55 ( V_163 -> V_36 , V_160 , V_78 ) )
return - V_162 ;
} else {
if ( F_55 ( V_163 -> V_36 ,
V_160 + 2 , V_78 ) )
return - V_162 ;
}
if ( V_2 -> V_161 )
return F_24 ( V_10 -> V_13 ,
( T_1 * ) V_163 -> V_36 , V_163 -> V_120 ,
V_163 -> V_112 , V_12 ) ;
}
return 0 ;
}
int F_56 ( struct V_86 * V_20 ,
struct V_11 * V_12 ,
struct V_35 * V_36 )
{
struct V_87 * V_17 = V_12 -> V_17 ;
struct V_33 * V_165 = NULL ;
memcpy ( V_17 -> V_81 , V_36 , sizeof( * V_36 ) ) ;
if ( V_36 -> V_50 == V_51 )
V_165 = & V_12 -> V_27 [ 0 ] ;
else
V_165 = & V_12 -> V_32 [ 0 ] ;
V_165 -> V_29 = V_36 -> V_29 ;
V_165 -> V_28 = V_36 -> V_40 ;
V_165 -> V_31 = F_12 ( V_36 -> V_42 ) ;
switch ( V_165 -> V_31 ) {
case V_43 :
V_165 -> V_44 = V_165 -> V_31 ;
break;
case V_166 :
case V_45 :
V_165 -> V_44 = V_45 ;
break;
default:
F_3 ( V_20 , L_20 ,
V_165 -> V_31 ) ;
return - V_76 ;
}
if ( V_36 -> V_50 == V_51 ) {
V_12 -> V_59 = ( V_165 -> V_29 / 1000 ) *
( V_165 -> V_28 ) *
( V_165 -> V_44 >> 3 ) ;
} else {
V_12 -> V_60 = ( V_165 -> V_29 / 1000 ) *
( V_165 -> V_28 ) *
( V_165 -> V_44 >> 3 ) ;
}
return 0 ;
}
struct V_11 *
F_57 ( struct V_167 * V_168 , int V_50 )
{
struct V_1 * V_2 ;
struct V_89 * V_90 = NULL ;
if ( V_50 == V_51 ) {
V_2 = V_168 -> V_169 ;
F_22 (w, p) {
if ( V_90 -> V_98 && V_90 -> V_97 -> V_161 &&
! F_1 ( V_90 -> V_97 ) )
continue;
if ( V_90 -> V_97 -> V_61 ) {
F_10 ( V_168 -> V_20 , L_21 ,
V_90 -> V_97 -> V_84 ) ;
return V_90 -> V_97 -> V_61 ;
}
}
} else {
V_2 = V_168 -> V_170 ;
F_39 (w, p) {
if ( V_90 -> V_98 && V_90 -> V_148 -> V_161 &&
! F_1 ( V_90 -> V_148 ) )
continue;
if ( V_90 -> V_148 -> V_61 ) {
F_10 ( V_168 -> V_20 , L_21 ,
V_90 -> V_148 -> V_84 ) ;
return V_90 -> V_148 -> V_61 ;
}
}
}
return NULL ;
}
static struct V_11 * F_58 (
struct V_167 * V_168 , struct V_1 * V_2 )
{
struct V_89 * V_90 ;
struct V_11 * V_12 = NULL ;
F_39 (w, p) {
if ( V_2 -> V_171 [ V_172 ] > 0 ) {
if ( V_90 -> V_98 &&
( V_90 -> V_97 -> V_3 == V_7 ) &&
V_90 -> V_148 -> V_61 ) {
V_12 = V_90 -> V_148 -> V_61 ;
return V_12 ;
}
V_12 = F_58 ( V_168 , V_90 -> V_148 ) ;
if ( V_12 )
return V_12 ;
}
}
return V_12 ;
}
static struct V_11 * F_59 (
struct V_167 * V_168 , struct V_1 * V_2 )
{
struct V_89 * V_90 ;
struct V_11 * V_12 = NULL ;
F_22 (w, p) {
if ( V_2 -> V_171 [ V_173 ] > 0 ) {
if ( V_90 -> V_98 &&
( V_90 -> V_148 -> V_3 == V_6 ) &&
V_90 -> V_97 -> V_61 ) {
V_12 = V_90 -> V_97 -> V_61 ;
return V_12 ;
}
V_12 = F_59 ( V_168 , V_90 -> V_97 ) ;
if ( V_12 )
return V_12 ;
}
}
return V_12 ;
}
struct V_11 *
F_60 ( struct V_167 * V_168 , int V_50 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
if ( V_50 == V_51 ) {
V_2 = V_168 -> V_169 ;
V_12 = F_58 ( V_168 , V_2 ) ;
} else {
V_2 = V_168 -> V_170 ;
V_12 = F_59 ( V_168 , V_2 ) ;
}
return V_12 ;
}
static T_3 F_61 ( int V_68 )
{
int V_101 ;
switch ( V_68 ) {
case V_174 :
V_101 = V_73 ;
break;
case V_69 :
V_101 = V_70 ;
break;
case V_72 :
V_101 = V_73 ;
break;
case V_175 :
V_101 = V_176 ;
break;
default:
V_101 = V_177 ;
break;
}
return V_101 ;
}
static int F_62 ( struct V_167 * V_168 ,
struct V_11 * V_12 ,
struct V_35 * V_36 )
{
struct V_87 * V_17 = V_12 -> V_17 ;
struct V_64 * V_65 ;
struct V_10 * V_10 = F_16 ( V_168 -> V_20 ) ;
int V_62 = F_61 ( V_12 -> V_68 ) ;
memcpy ( V_17 -> V_81 , V_36 , sizeof( * V_36 ) ) ;
if ( V_62 == V_176 )
return 0 ;
V_65 = F_17 ( V_10 , V_12 -> V_77 , V_62 ,
V_36 -> V_42 , V_36 -> V_40 ,
V_36 -> V_29 , V_36 -> V_50 ) ;
if ( V_65 ) {
V_12 -> V_66 . V_67 = V_65 -> V_78 ;
V_12 -> V_66 . V_79 = ( T_1 * ) & V_65 -> V_79 ;
} else {
F_3 ( V_168 -> V_20 , L_12 ,
V_12 -> V_77 , V_62 ,
V_36 -> V_50 ) ;
F_3 ( V_168 -> V_20 , L_13 ,
V_36 -> V_40 , V_36 -> V_29 , V_36 -> V_42 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_63 ( struct V_167 * V_168 ,
struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_89 * V_90 ;
int V_101 = - V_80 ;
F_39 (w, p) {
if ( V_90 -> V_98 && F_1 ( V_90 -> V_148 ) &&
V_90 -> V_148 -> V_61 ) {
V_101 = F_62 ( V_168 ,
V_90 -> V_148 -> V_61 , V_36 ) ;
if ( V_101 < 0 )
return V_101 ;
} else {
V_101 = F_63 ( V_168 ,
V_90 -> V_148 , V_36 ) ;
if ( V_101 < 0 )
return V_101 ;
}
}
return V_101 ;
}
static int F_64 ( struct V_167 * V_168 ,
struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_89 * V_90 = NULL ;
int V_101 = - V_80 ;
F_22 (w, p) {
if ( V_90 -> V_98 && F_1 ( V_90 -> V_97 ) &&
V_90 -> V_97 -> V_61 ) {
V_101 = F_62 ( V_168 ,
V_90 -> V_97 -> V_61 , V_36 ) ;
if ( V_101 < 0 )
return V_101 ;
} else {
V_101 = F_64 (
V_168 , V_90 -> V_97 , V_36 ) ;
if ( V_101 < 0 )
return V_101 ;
}
}
return V_101 ;
}
int F_65 ( struct V_167 * V_168 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 ;
if ( V_36 -> V_50 == V_51 ) {
V_2 = V_168 -> V_169 ;
return F_63 ( V_168 , V_2 , V_36 ) ;
} else {
V_2 = V_168 -> V_170 ;
return F_64 ( V_168 , V_2 , V_36 ) ;
}
return 0 ;
}
static void F_66 ( struct V_178 * V_179 ,
struct V_180 * V_181 ,
bool V_182 , int V_183 )
{
int V_100 ;
for ( V_100 = 0 ; V_100 < V_183 ; V_100 ++ ) {
V_181 [ V_100 ] . V_3 . V_22 = V_179 [ V_100 ] . V_22 ;
V_181 [ V_100 ] . V_3 . V_23 = V_179 [ V_100 ] . V_23 ;
V_181 [ V_100 ] . V_184 = false ;
V_181 [ V_100 ] . V_182 = V_182 ;
V_181 [ V_100 ] . V_137 = V_185 ;
}
}
static struct V_87 * F_67 ( struct V_86 * V_20 ,
struct V_10 * V_10 , struct V_186 * V_187 )
{
struct V_188 * V_189 ;
struct V_87 * V_17 ;
struct V_35 * V_36 ;
F_27 (ppl, &skl->ppl_list, node) {
if ( V_189 -> V_17 -> V_99 == V_187 -> V_190 )
return V_189 -> V_17 ;
}
V_189 = F_20 ( V_20 , sizeof( * V_189 ) , V_93 ) ;
if ( ! V_189 )
return NULL ;
V_17 = F_20 ( V_20 , sizeof( * V_17 ) , V_93 ) ;
if ( ! V_17 )
return NULL ;
V_36 = F_20 ( V_20 , sizeof( * V_36 ) , V_93 ) ;
if ( ! V_36 )
return NULL ;
V_17 -> V_99 = V_187 -> V_190 ;
V_17 -> V_18 = V_187 -> V_18 ;
V_17 -> V_191 = V_187 -> V_191 ;
V_17 -> V_83 = V_187 -> V_83 ;
V_17 -> V_146 = V_192 ;
V_17 -> V_81 = V_36 ;
F_68 ( & V_17 -> V_96 ) ;
V_189 -> V_17 = V_17 ;
F_69 ( & V_189 -> V_95 , & V_10 -> V_193 ) ;
return V_189 -> V_17 ;
}
static void F_70 ( struct V_33 * V_194 ,
struct V_195 * V_196 ,
int V_197 )
{
int V_100 ;
for ( V_100 = 0 ; V_100 < V_197 ; V_100 ++ ) {
V_194 [ V_100 ] . V_28 = V_196 [ V_100 ] . V_28 ;
V_194 [ V_100 ] . V_29 = V_196 [ V_100 ] . V_198 ;
V_194 [ V_100 ] . V_44 = V_196 [ V_100 ] . V_44 ;
V_194 [ V_100 ] . V_31 = V_196 [ V_100 ] . V_31 ;
V_194 [ V_100 ] . V_30 = V_196 [ V_100 ] . V_30 ;
V_194 [ V_100 ] . V_199 = V_196 [ V_100 ] . V_199 ;
V_194 [ V_100 ] . V_200 = V_196 [ V_100 ] . V_200 ;
V_194 [ V_100 ] . V_201 = V_196 [ V_100 ] . V_201 ;
}
}
static int F_71 ( struct V_202 * V_203 ,
struct V_1 * V_2 ,
struct V_204 * V_205 )
{
int V_101 ;
struct V_206 * V_207 = F_72 ( V_203 ) ;
struct V_10 * V_10 = F_73 ( V_207 ) ;
struct V_208 * V_209 = F_74 ( V_207 ) ;
struct V_11 * V_12 ;
struct V_87 * V_17 ;
struct V_210 * V_211 =
(struct V_210 * ) V_205 -> V_61 . V_160 ;
if ( ! V_205 -> V_61 . V_78 )
goto V_212;
V_12 = F_20 ( V_209 -> V_20 , sizeof( * V_12 ) , V_93 ) ;
if ( ! V_12 )
return - V_94 ;
V_2 -> V_61 = V_12 ;
V_12 -> V_3 . V_22 = V_211 -> V_22 ;
V_12 -> V_3 . V_23 = V_211 -> V_23 ;
V_12 -> V_24 = V_211 -> V_25 ;
V_12 -> V_59 = V_211 -> V_59 ;
V_12 -> V_60 = V_211 -> V_60 ;
V_12 -> V_213 = V_211 -> V_213 ;
V_12 -> V_139 = V_211 -> V_139 ;
V_12 -> V_135 = V_211 -> V_135 ;
V_12 -> V_123 = V_211 -> V_123 ;
F_70 ( V_12 -> V_27 , V_211 -> V_27 ,
V_214 ) ;
F_70 ( V_12 -> V_32 , V_211 -> V_32 ,
V_215 ) ;
V_12 -> V_52 = V_211 -> V_52 ;
V_12 -> V_53 = V_211 -> V_53 ;
V_12 -> V_57 = V_211 -> V_216 ;
V_12 -> V_77 = V_211 -> V_77 ;
V_12 -> V_217 = V_211 -> V_217 ;
V_17 = F_67 ( V_209 -> V_20 , V_10 , & V_211 -> V_17 ) ;
if ( V_17 )
V_12 -> V_17 = V_17 ;
V_12 -> V_68 = V_211 -> V_68 ;
V_12 -> V_74 = V_211 -> V_74 ;
V_12 -> V_218 = V_211 -> V_218 ;
V_12 -> V_66 . V_67 = V_211 -> V_79 . V_67 ;
if ( V_211 -> V_123 )
memcpy ( V_12 -> V_127 , V_211 -> V_219 ,
F_75 ( V_211 -> V_219 ) ) ;
V_12 -> V_140 = F_20 ( V_209 -> V_20 , ( V_12 -> V_139 ) *
sizeof( * V_12 -> V_140 ) ,
V_93 ) ;
if ( ! V_12 -> V_140 )
return - V_94 ;
V_12 -> V_136 = F_20 ( V_209 -> V_20 , ( V_12 -> V_135 ) *
sizeof( * V_12 -> V_136 ) ,
V_93 ) ;
if ( ! V_12 -> V_136 )
return - V_94 ;
F_66 ( V_211 -> V_220 , V_12 -> V_140 ,
V_211 -> V_221 ,
V_12 -> V_139 ) ;
F_66 ( V_211 -> V_222 , V_12 -> V_136 ,
V_211 -> V_223 ,
V_12 -> V_135 ) ;
if ( V_12 -> V_66 . V_67 == 0 )
goto V_212;
V_12 -> V_66 . V_79 = ( T_1 * ) F_20 ( V_209 -> V_20 ,
V_12 -> V_66 . V_67 , V_93 ) ;
if ( V_12 -> V_66 . V_79 == NULL )
return - V_94 ;
memcpy ( V_12 -> V_66 . V_79 , V_211 -> V_79 . V_79 ,
V_211 -> V_79 . V_67 ) ;
V_12 -> V_66 . V_112 = V_211 -> V_79 . V_112 ;
V_12 -> V_66 . V_110 = V_211 -> V_79 . V_110 ;
V_212:
if ( V_205 -> V_224 == 0 ) {
F_10 ( V_209 -> V_20 , L_22 ) ;
return 0 ;
}
V_101 = F_76 ( V_2 , V_225 ,
F_75 ( V_225 ) ,
V_205 -> V_224 ) ;
if ( V_101 ) {
F_3 ( V_209 -> V_20 , L_23 ,
V_21 , V_205 -> V_224 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_77 ( struct V_86 * V_20 , struct V_104 * V_226 ,
struct V_227 * V_107 )
{
struct V_106 * V_163 ;
struct V_228 * V_229 =
(struct V_228 * ) V_107 -> V_61 . V_160 ;
V_163 = F_20 ( V_20 , sizeof( * V_163 ) , V_93 ) ;
if ( ! V_163 )
return - V_94 ;
V_163 -> V_120 = V_229 -> V_120 ;
V_163 -> V_112 = V_229 -> V_112 ;
V_163 -> V_110 = V_229 -> V_110 ;
if ( V_163 -> V_120 ) {
V_163 -> V_36 = ( char * ) F_20 ( V_20 , V_163 -> V_120 , V_93 ) ;
if ( ! V_163 -> V_36 )
return - V_94 ;
memcpy ( V_163 -> V_36 , V_229 -> V_36 , V_163 -> V_120 ) ;
}
V_226 -> V_118 . V_119 = V_163 ;
return 0 ;
}
static int F_78 ( struct V_202 * V_203 ,
struct V_102 * V_230 ,
struct V_231 * V_232 )
{
struct V_104 * V_105 ;
struct V_227 * V_233 ;
struct V_206 * V_207 = F_72 ( V_203 ) ;
struct V_208 * V_209 = F_74 ( V_207 ) ;
switch ( V_232 -> V_234 . V_235 ) {
case V_236 :
V_233 = F_79 ( V_232 ,
struct V_227 , V_232 ) ;
if ( V_230 -> V_115 & V_116 ) {
V_105 = (struct V_104 * ) V_230 -> V_117 ;
if ( V_233 -> V_61 . V_78 )
return F_77 (
V_209 -> V_20 , V_105 , V_233 ) ;
}
break;
default:
F_80 ( V_209 -> V_20 , L_24 ,
V_232 -> V_234 . V_237 , V_232 -> V_234 . V_238 , V_232 -> V_234 . V_235 ) ;
break;
}
return 0 ;
}
int F_81 ( struct V_239 * V_240 , struct V_206 * V_207 )
{
int V_101 ;
const struct V_241 * V_242 ;
struct V_208 * V_209 = F_74 ( V_207 ) ;
struct V_10 * V_10 = F_73 ( V_207 ) ;
V_101 = F_82 ( & V_242 , V_10 -> V_243 , V_209 -> V_20 ) ;
if ( V_101 < 0 ) {
F_3 ( V_209 -> V_20 , L_25 ,
V_10 -> V_243 , V_101 ) ;
V_101 = F_82 ( & V_242 , L_26 , V_209 -> V_20 ) ;
if ( V_101 < 0 ) {
F_3 ( V_209 -> V_20 , L_27 ,
L_26 , V_101 ) ;
return V_101 ;
}
}
V_101 = F_83 ( & V_240 -> V_244 ,
& V_245 , V_242 , 0 ) ;
if ( V_101 < 0 ) {
F_3 ( V_209 -> V_20 , L_28 , V_101 ) ;
F_84 ( V_242 ) ;
return - V_76 ;
}
V_10 -> V_15 . V_25 = V_246 ;
V_10 -> V_15 . V_19 = V_247 ;
V_10 -> V_248 = V_242 ;
return 0 ;
}
