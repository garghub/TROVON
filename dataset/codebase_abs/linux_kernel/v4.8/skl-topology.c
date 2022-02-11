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
if ( ! F_5 ( V_10 , V_12 ) )
return - V_114 ;
if ( V_12 -> V_115 && V_14 -> V_116 -> V_117 . V_118 ) {
V_91 = V_14 -> V_116 -> V_117 . V_118 ( V_14 -> V_116 ,
V_12 -> V_3 . V_22 , V_12 -> V_119 ) ;
if ( V_91 < 0 )
return V_91 ;
V_12 -> V_120 = V_121 ;
}
F_16 ( V_2 , V_14 ) ;
F_19 ( V_2 , V_14 ) ;
F_22 ( V_2 ) ;
V_91 = F_25 ( V_14 , V_12 ) ;
if ( V_91 < 0 )
return V_91 ;
F_6 ( V_10 , V_12 ) ;
V_91 = F_20 ( V_2 , V_14 ) ;
if ( V_91 < 0 )
return V_91 ;
}
return 0 ;
}
static int F_26 ( struct V_13 * V_14 ,
struct V_111 * V_17 )
{
struct V_112 * V_113 = NULL ;
struct V_11 * V_12 = NULL ;
F_24 (w_module, &pipe->w_list, node) {
V_12 = V_113 -> V_2 -> V_66 ;
if ( V_12 -> V_115 && V_14 -> V_116 -> V_117 . V_122 &&
V_12 -> V_120 > V_123 )
return V_14 -> V_116 -> V_117 . V_122 ( V_14 -> V_116 ,
V_12 -> V_3 . V_22 ) ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
int V_91 ;
struct V_11 * V_12 = V_2 -> V_66 ;
struct V_112 * V_113 ;
struct V_111 * V_124 = V_12 -> V_17 ;
struct V_11 * V_125 = NULL , * V_126 ;
struct V_13 * V_14 = V_10 -> V_13 ;
if ( ! F_5 ( V_10 , V_12 ) )
return - V_127 ;
if ( ! F_2 ( V_10 , V_12 ) )
return - V_114 ;
V_91 = F_28 ( V_14 , V_12 -> V_17 ) ;
if ( V_91 < 0 )
return V_91 ;
F_4 ( V_10 , V_12 ) ;
F_6 ( V_10 , V_12 ) ;
V_91 = F_23 ( V_10 , V_124 ) ;
if ( V_91 < 0 )
return V_91 ;
F_24 (w_module, &s_pipe->w_list, node) {
V_126 = V_113 -> V_2 -> V_66 ;
if ( V_125 == NULL ) {
V_125 = V_126 ;
continue;
}
V_91 = F_29 ( V_14 , V_125 , V_126 ) ;
if ( V_91 < 0 )
return V_91 ;
V_125 = V_126 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_11 * V_26 , struct V_13 * V_14 )
{
int V_38 , V_91 ;
struct V_11 * V_12 = V_2 -> V_66 ;
const struct V_92 * V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
for ( V_38 = 0 ; V_38 < V_26 -> V_128 ; V_38 ++ ) {
if ( V_26 -> V_129 [ V_38 ] . V_130 != V_131 )
return 0 ;
}
for ( V_38 = 0 ; V_38 < V_26 -> V_132 ; V_38 ++ ) {
if ( V_26 -> V_133 [ V_38 ] . V_130 != V_131 )
return 0 ;
}
if ( V_12 -> V_71 . V_72 > 0 &&
V_12 -> V_71 . V_100 == V_134 ) {
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
if ( V_97 -> V_100 == V_134 ) {
V_91 = F_21 ( V_14 ,
( T_1 * ) V_97 -> V_41 , V_97 -> V_135 ,
V_97 -> V_102 , V_12 ) ;
if ( V_91 < 0 )
return V_91 ;
}
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_10 * V_10 ,
struct V_1 * V_136 ,
struct V_11 * V_137 )
{
struct V_138 * V_139 ;
struct V_1 * V_140 = NULL , * V_141 = NULL ;
struct V_11 * V_142 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_91 ;
F_32 (w, p) {
if ( ! V_139 -> V_143 )
continue;
F_10 ( V_14 -> V_20 , L_16 , V_21 , V_2 -> V_89 ) ;
F_10 ( V_14 -> V_20 , L_17 , V_21 , V_139 -> V_140 -> V_89 ) ;
V_141 = V_139 -> V_140 ;
if ( ! F_1 ( V_139 -> V_140 ) )
return F_31 ( V_139 -> V_140 , V_10 , V_136 , V_137 ) ;
if ( ( V_139 -> V_140 -> V_66 != NULL ) &&
F_1 ( V_139 -> V_140 ) ) {
V_140 = V_139 -> V_140 ;
V_142 = V_140 -> V_66 ;
if ( V_137 -> V_120 == V_123 ||
V_142 -> V_120 == V_123 )
continue;
V_91 = F_29 ( V_14 , V_137 , V_142 ) ;
if ( V_91 )
return V_91 ;
F_30 ( V_136 , V_137 , V_14 ) ;
F_30 ( V_140 , V_142 , V_14 ) ;
if ( V_142 -> V_17 -> V_144 != V_145 ) {
if ( V_142 -> V_17 -> V_88 !=
V_90 )
V_91 = F_33 ( V_14 ,
V_142 -> V_17 ) ;
if ( V_91 )
return V_91 ;
}
}
}
if ( ! V_140 )
return F_31 ( V_141 , V_10 , V_136 , V_137 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_137 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_91 = 0 ;
V_137 = V_2 -> V_66 ;
V_91 = F_31 ( V_2 , V_10 , V_2 , V_137 ) ;
if ( V_91 )
return V_91 ;
if ( V_137 -> V_17 -> V_88 != V_90 )
return F_33 ( V_14 , V_137 -> V_17 ) ;
return 0 ;
}
static struct V_1 * F_35 (
struct V_1 * V_2 , struct V_10 * V_10 )
{
struct V_138 * V_139 ;
struct V_1 * V_136 = NULL ;
struct V_13 * V_14 = V_10 -> V_13 ;
F_36 (w, p) {
V_136 = V_139 -> V_146 ;
if ( ! V_139 -> V_143 )
continue;
F_10 ( V_14 -> V_20 , L_18 , V_2 -> V_89 ) ;
F_10 ( V_14 -> V_20 , L_19 , V_139 -> V_146 -> V_89 ) ;
if ( ( V_139 -> V_146 -> V_66 != NULL ) &&
F_1 ( V_139 -> V_146 ) ) {
return V_139 -> V_146 ;
}
}
if ( V_136 != NULL )
return F_35 ( V_136 , V_10 ) ;
return NULL ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
int V_91 = 0 ;
struct V_1 * V_146 , * V_140 ;
struct V_11 * V_137 , * V_142 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_147 = 0 ;
V_140 = V_2 ;
V_142 = V_140 -> V_66 ;
V_146 = F_35 ( V_2 , V_10 ) ;
if ( V_146 != NULL ) {
V_137 = V_146 -> V_66 ;
V_142 = V_140 -> V_66 ;
V_147 = 1 ;
if ( V_137 -> V_17 -> V_144 != V_145 )
V_147 = 0 ;
}
if ( V_147 ) {
V_91 = F_29 ( V_14 , V_137 , V_142 ) ;
if ( V_91 )
return V_91 ;
F_30 ( V_146 , V_137 , V_14 ) ;
F_30 ( V_140 , V_142 , V_14 ) ;
if ( V_142 -> V_17 -> V_88 != V_90 )
V_91 = F_33 ( V_14 , V_142 -> V_17 ) ;
}
return V_91 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_137 , * V_142 ;
int V_91 = 0 , V_38 ;
struct V_13 * V_14 = V_10 -> V_13 ;
V_142 = V_2 -> V_66 ;
V_91 = F_39 ( V_14 , V_142 -> V_17 ) ;
if ( V_91 )
return V_91 ;
for ( V_38 = 0 ; V_38 < V_142 -> V_132 ; V_38 ++ ) {
if ( V_142 -> V_133 [ V_38 ] . V_130 == V_131 ) {
V_137 = V_142 -> V_133 [ V_38 ] . V_148 ;
if ( ! V_137 )
continue;
V_91 = F_39 ( V_14 , V_137 -> V_17 ) ;
if ( V_91 < 0 )
return V_91 ;
V_91 = F_40 ( V_14 ,
V_137 , V_142 ) ;
}
}
return V_91 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_66 ;
struct V_112 * V_113 ;
struct V_11 * V_125 = NULL , * V_126 ;
struct V_13 * V_14 = V_10 -> V_13 ;
struct V_111 * V_124 = V_12 -> V_17 ;
int V_91 = 0 ;
if ( V_124 -> V_144 == V_149 )
return - V_81 ;
F_7 ( V_10 , V_12 ) ;
F_8 ( V_10 , V_12 ) ;
F_24 (w_module, &s_pipe->w_list, node) {
V_126 = V_113 -> V_2 -> V_66 ;
if ( V_12 -> V_120 >= V_150 )
F_7 ( V_10 , V_126 ) ;
if ( V_125 == NULL ) {
V_125 = V_126 ;
continue;
}
F_40 ( V_14 , V_125 , V_126 ) ;
V_125 = V_126 ;
}
V_91 = F_42 ( V_14 , V_12 -> V_17 ) ;
return F_26 ( V_14 , V_124 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_137 , * V_142 ;
int V_91 = 0 , V_38 ;
struct V_13 * V_14 = V_10 -> V_13 ;
V_137 = V_2 -> V_66 ;
V_91 = F_39 ( V_14 , V_137 -> V_17 ) ;
if ( V_91 )
return V_91 ;
for ( V_38 = 0 ; V_38 < V_137 -> V_128 ; V_38 ++ ) {
if ( V_137 -> V_129 [ V_38 ] . V_130 == V_131 ) {
V_142 = V_137 -> V_129 [ V_38 ] . V_148 ;
if ( ! V_142 )
continue;
V_91 = F_40 ( V_14 , V_137 ,
V_142 ) ;
}
}
return V_91 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_151 * V_93 , int V_152 )
{
struct V_153 * V_154 = V_2 -> V_154 ;
struct V_10 * V_10 = F_17 ( V_154 -> V_20 ) ;
switch ( V_152 ) {
case V_155 :
return F_27 ( V_2 , V_10 ) ;
case V_156 :
return F_37 ( V_2 , V_10 ) ;
case V_157 :
return F_38 ( V_2 , V_10 ) ;
case V_158 :
return F_41 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_151 * V_93 , int V_152 )
{
struct V_153 * V_154 = V_2 -> V_154 ;
struct V_10 * V_10 = F_17 ( V_154 -> V_20 ) ;
switch ( V_152 ) {
case V_155 :
return F_27 ( V_2 , V_10 ) ;
case V_156 :
return F_37 ( V_2 , V_10 ) ;
case V_157 :
return F_38 ( V_2 , V_10 ) ;
case V_158 :
return F_41 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_151 * V_93 , int V_152 )
{
struct V_153 * V_154 = V_2 -> V_154 ;
struct V_10 * V_10 = F_17 ( V_154 -> V_20 ) ;
switch ( V_152 ) {
case V_155 :
return F_34 ( V_2 , V_10 ) ;
case V_158 :
return F_43 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_47 ( struct V_151 * V_159 ,
unsigned int T_2 * V_160 , unsigned int V_83 )
{
struct V_94 * V_95 =
(struct V_94 * ) V_159 -> V_107 ;
struct V_96 * V_97 = (struct V_96 * ) V_95 -> V_108 . V_109 ;
struct V_1 * V_2 = F_48 ( V_159 ) ;
struct V_11 * V_12 = V_2 -> V_66 ;
struct V_10 * V_10 = F_17 ( V_2 -> V_154 -> V_20 ) ;
if ( V_2 -> V_161 )
F_49 ( V_10 -> V_13 , ( T_1 * ) V_97 -> V_41 ,
V_97 -> V_83 , V_97 -> V_102 , V_12 ) ;
V_83 -= 2 * sizeof( T_1 ) ;
if ( V_83 > V_97 -> V_135 )
V_83 = V_97 -> V_135 ;
if ( V_97 -> V_41 ) {
if ( F_50 ( V_160 , & V_97 -> V_102 , sizeof( T_1 ) ) )
return - V_162 ;
if ( F_50 ( V_160 + 1 , & V_83 , sizeof( T_1 ) ) )
return - V_162 ;
if ( F_50 ( V_160 + 2 , V_97 -> V_41 , V_83 ) )
return - V_162 ;
}
return 0 ;
}
static int F_51 ( struct V_151 * V_159 ,
const unsigned int T_2 * V_160 , unsigned int V_83 )
{
struct V_1 * V_2 = F_48 ( V_159 ) ;
struct V_11 * V_12 = V_2 -> V_66 ;
struct V_94 * V_95 =
(struct V_94 * ) V_159 -> V_107 ;
struct V_96 * V_163 = (struct V_96 * ) V_95 -> V_108 . V_109 ;
struct V_10 * V_10 = F_17 ( V_2 -> V_154 -> V_20 ) ;
if ( V_163 -> V_41 ) {
if ( V_83 > V_163 -> V_135 )
return - V_81 ;
V_163 -> V_83 = V_83 ;
if ( V_163 -> V_102 == V_164 ) {
if ( F_52 ( V_163 -> V_41 , V_160 , V_83 ) )
return - V_162 ;
} else {
if ( F_52 ( V_163 -> V_41 ,
V_160 + 2 , V_83 ) )
return - V_162 ;
}
if ( V_2 -> V_161 )
return F_21 ( V_10 -> V_13 ,
( T_1 * ) V_163 -> V_41 , V_163 -> V_83 ,
V_163 -> V_102 , V_12 ) ;
}
return 0 ;
}
static void F_53 ( struct V_11 * V_26 ,
struct V_40 * V_41 )
{
struct V_111 * V_17 = V_26 -> V_17 ;
if ( V_17 -> V_165 ) {
switch ( V_26 -> V_73 ) {
case V_166 :
V_17 -> V_86 -> V_167 = V_41 -> V_167 ;
break;
case V_168 :
V_17 -> V_86 -> V_169 = V_41 -> V_169 ;
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
int F_54 ( struct V_170 * V_20 ,
struct V_11 * V_12 ,
struct V_40 * V_41 )
{
struct V_33 * V_171 = NULL ;
F_53 ( V_12 , V_41 ) ;
if ( V_41 -> V_55 == V_56 )
V_171 = & V_12 -> V_27 [ 0 ] ;
else
V_171 = & V_12 -> V_32 [ 0 ] ;
V_171 -> V_29 = V_41 -> V_29 ;
V_171 -> V_28 = V_41 -> V_45 ;
V_171 -> V_31 = F_13 ( V_41 -> V_47 ) ;
switch ( V_171 -> V_31 ) {
case V_48 :
V_171 -> V_49 = V_171 -> V_31 ;
break;
case V_172 :
case V_50 :
V_171 -> V_49 = V_50 ;
break;
default:
F_3 ( V_20 , L_20 ,
V_171 -> V_31 ) ;
return - V_81 ;
}
if ( V_41 -> V_55 == V_56 ) {
V_12 -> V_64 = ( V_171 -> V_29 / 1000 ) *
( V_171 -> V_28 ) *
( V_171 -> V_49 >> 3 ) ;
} else {
V_12 -> V_65 = ( V_171 -> V_29 / 1000 ) *
( V_171 -> V_28 ) *
( V_171 -> V_49 >> 3 ) ;
}
return 0 ;
}
struct V_11 *
F_55 ( struct V_173 * V_174 , int V_55 )
{
struct V_1 * V_2 ;
struct V_138 * V_139 = NULL ;
if ( V_55 == V_56 ) {
V_2 = V_174 -> V_175 ;
F_32 (w, p) {
if ( V_139 -> V_143 && V_139 -> V_140 -> V_161 &&
! F_1 ( V_139 -> V_140 ) )
continue;
if ( V_139 -> V_140 -> V_66 ) {
F_10 ( V_174 -> V_20 , L_21 ,
V_139 -> V_140 -> V_89 ) ;
return V_139 -> V_140 -> V_66 ;
}
}
} else {
V_2 = V_174 -> V_176 ;
F_36 (w, p) {
if ( V_139 -> V_143 && V_139 -> V_146 -> V_161 &&
! F_1 ( V_139 -> V_146 ) )
continue;
if ( V_139 -> V_146 -> V_66 ) {
F_10 ( V_174 -> V_20 , L_21 ,
V_139 -> V_146 -> V_89 ) ;
return V_139 -> V_146 -> V_66 ;
}
}
}
return NULL ;
}
static struct V_11 * F_56 (
struct V_173 * V_174 , struct V_1 * V_2 )
{
struct V_138 * V_139 ;
struct V_11 * V_12 = NULL ;
F_36 (w, p) {
if ( V_2 -> V_177 [ V_178 ] > 0 ) {
if ( V_139 -> V_143 &&
( V_139 -> V_140 -> V_3 == V_7 ) &&
V_139 -> V_146 -> V_66 ) {
V_12 = V_139 -> V_146 -> V_66 ;
return V_12 ;
}
V_12 = F_56 ( V_174 , V_139 -> V_146 ) ;
if ( V_12 )
return V_12 ;
}
}
return V_12 ;
}
static struct V_11 * F_57 (
struct V_173 * V_174 , struct V_1 * V_2 )
{
struct V_138 * V_139 ;
struct V_11 * V_12 = NULL ;
F_32 (w, p) {
if ( V_2 -> V_177 [ V_179 ] > 0 ) {
if ( V_139 -> V_143 &&
( V_139 -> V_146 -> V_3 == V_6 ) &&
V_139 -> V_140 -> V_66 ) {
V_12 = V_139 -> V_140 -> V_66 ;
return V_12 ;
}
V_12 = F_57 ( V_174 , V_139 -> V_140 ) ;
if ( V_12 )
return V_12 ;
}
}
return V_12 ;
}
struct V_11 *
F_58 ( struct V_173 * V_174 , int V_55 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
if ( V_55 == V_56 ) {
V_2 = V_174 -> V_175 ;
V_12 = F_56 ( V_174 , V_2 ) ;
} else {
V_2 = V_174 -> V_176 ;
V_12 = F_57 ( V_174 , V_2 ) ;
}
return V_12 ;
}
static T_3 F_59 ( int V_73 )
{
int V_91 ;
switch ( V_73 ) {
case V_180 :
V_91 = V_78 ;
break;
case V_74 :
V_91 = V_75 ;
break;
case V_77 :
V_91 = V_78 ;
break;
case V_166 :
V_91 = V_181 ;
break;
default:
V_91 = V_182 ;
break;
}
return V_91 ;
}
static int F_60 ( struct V_173 * V_174 ,
struct V_11 * V_12 ,
struct V_40 * V_41 )
{
struct V_69 * V_70 ;
struct V_10 * V_10 = F_17 ( V_174 -> V_20 ) ;
int V_67 = F_59 ( V_12 -> V_73 ) ;
F_53 ( V_12 , V_41 ) ;
if ( V_67 == V_181 )
return 0 ;
V_70 = F_18 ( V_10 , V_12 -> V_82 , V_67 ,
V_41 -> V_47 , V_41 -> V_45 ,
V_41 -> V_29 , V_41 -> V_55 ) ;
if ( V_70 ) {
V_12 -> V_71 . V_72 = V_70 -> V_83 ;
V_12 -> V_71 . V_84 = ( T_1 * ) & V_70 -> V_84 ;
} else {
F_3 ( V_174 -> V_20 , L_12 ,
V_12 -> V_82 , V_67 ,
V_41 -> V_55 ) ;
F_3 ( V_174 -> V_20 , L_13 ,
V_41 -> V_45 , V_41 -> V_29 , V_41 -> V_47 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_61 ( struct V_173 * V_174 ,
struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_138 * V_139 ;
int V_91 = - V_85 ;
F_36 (w, p) {
if ( V_139 -> V_143 && F_1 ( V_139 -> V_146 ) &&
V_139 -> V_146 -> V_66 ) {
V_91 = F_60 ( V_174 ,
V_139 -> V_146 -> V_66 , V_41 ) ;
if ( V_91 < 0 )
return V_91 ;
} else {
V_91 = F_61 ( V_174 ,
V_139 -> V_146 , V_41 ) ;
if ( V_91 < 0 )
return V_91 ;
}
}
return V_91 ;
}
static int F_62 ( struct V_173 * V_174 ,
struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_138 * V_139 = NULL ;
int V_91 = - V_85 ;
F_32 (w, p) {
if ( V_139 -> V_143 && F_1 ( V_139 -> V_140 ) &&
V_139 -> V_140 -> V_66 ) {
V_91 = F_60 ( V_174 ,
V_139 -> V_140 -> V_66 , V_41 ) ;
if ( V_91 < 0 )
return V_91 ;
} else {
V_91 = F_62 (
V_174 , V_139 -> V_140 , V_41 ) ;
if ( V_91 < 0 )
return V_91 ;
}
}
return V_91 ;
}
int F_63 ( struct V_173 * V_174 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 ;
if ( V_41 -> V_55 == V_56 ) {
V_2 = V_174 -> V_175 ;
return F_61 ( V_174 , V_2 , V_41 ) ;
} else {
V_2 = V_174 -> V_176 ;
return F_62 ( V_174 , V_2 , V_41 ) ;
}
return 0 ;
}
static void F_64 ( struct V_183 * V_184 ,
struct V_185 * V_186 ,
bool V_187 , int V_188 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_188 ; V_38 ++ ) {
V_186 [ V_38 ] . V_3 . V_22 = V_184 [ V_38 ] . V_22 ;
V_186 [ V_38 ] . V_3 . V_23 = V_184 [ V_38 ] . V_23 ;
V_186 [ V_38 ] . V_189 = false ;
V_186 [ V_38 ] . V_187 = V_187 ;
V_186 [ V_38 ] . V_130 = V_190 ;
}
}
static struct V_111 * F_65 ( struct V_170 * V_20 ,
struct V_10 * V_10 , struct V_191 * V_192 )
{
struct V_193 * V_194 ;
struct V_111 * V_17 ;
struct V_40 * V_41 ;
F_24 (ppl, &skl->ppl_list, node) {
if ( V_194 -> V_17 -> V_195 == V_192 -> V_196 )
return V_194 -> V_17 ;
}
V_194 = F_66 ( V_20 , sizeof( * V_194 ) , V_197 ) ;
if ( ! V_194 )
return NULL ;
V_17 = F_66 ( V_20 , sizeof( * V_17 ) , V_197 ) ;
if ( ! V_17 )
return NULL ;
V_41 = F_66 ( V_20 , sizeof( * V_41 ) , V_197 ) ;
if ( ! V_41 )
return NULL ;
V_17 -> V_195 = V_192 -> V_196 ;
V_17 -> V_18 = V_192 -> V_18 ;
V_17 -> V_198 = V_192 -> V_198 ;
V_17 -> V_88 = V_192 -> V_88 ;
V_17 -> V_144 = V_149 ;
V_17 -> V_86 = V_41 ;
F_67 ( & V_17 -> V_199 ) ;
V_194 -> V_17 = V_17 ;
F_68 ( & V_194 -> V_200 , & V_10 -> V_201 ) ;
return V_194 -> V_17 ;
}
static void F_69 ( struct V_33 * V_202 ,
struct V_203 * V_204 ,
int V_205 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_205 ; V_38 ++ ) {
V_202 [ V_38 ] . V_28 = V_204 [ V_38 ] . V_28 ;
V_202 [ V_38 ] . V_29 = V_204 [ V_38 ] . V_206 ;
V_202 [ V_38 ] . V_49 = V_204 [ V_38 ] . V_49 ;
V_202 [ V_38 ] . V_31 = V_204 [ V_38 ] . V_31 ;
V_202 [ V_38 ] . V_30 = V_204 [ V_38 ] . V_30 ;
V_202 [ V_38 ] . V_39 = V_204 [ V_38 ] . V_39 ;
V_202 [ V_38 ] . V_207 = V_204 [ V_38 ] . V_207 ;
V_202 [ V_38 ] . V_208 = V_204 [ V_38 ] . V_208 ;
}
}
static void F_70 ( struct V_209 * V_210 ,
struct V_1 * V_2 )
{
int V_38 ;
struct V_11 * V_12 ;
struct V_111 * V_17 ;
if ( ! strncmp ( V_2 -> V_154 -> V_211 -> V_89 , V_210 -> V_211 . V_89 ,
strlen ( V_210 -> V_211 . V_89 ) ) ) {
V_12 = V_2 -> V_66 ;
V_17 = V_12 -> V_17 ;
for ( V_38 = 0 ; V_38 < V_12 -> V_132 ; V_38 ++ ) {
V_12 -> V_133 [ V_38 ] . V_189 = false ;
V_12 -> V_133 [ V_38 ] . V_130 = V_190 ;
}
for ( V_38 = 0 ; V_38 < V_12 -> V_128 ; V_38 ++ ) {
V_12 -> V_129 [ V_38 ] . V_189 = false ;
V_12 -> V_129 [ V_38 ] . V_130 = V_190 ;
}
V_17 -> V_144 = V_149 ;
V_12 -> V_120 = V_123 ;
}
}
void F_71 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_13 ;
struct V_209 * V_212 = V_10 -> V_210 ;
struct V_1 * V_2 ;
struct V_213 * V_214 ;
if ( V_212 == NULL )
return;
V_214 = V_212 -> V_211 . V_214 ;
if ( ! V_214 || ! V_214 -> V_215 )
return;
V_10 -> V_15 . V_16 = 0 ;
V_10 -> V_15 . V_24 = 0 ;
F_24 (w, &card->widgets, list) {
if ( F_1 ( V_2 ) && ( V_2 -> V_66 != NULL ) )
F_70 ( V_212 , V_2 ) ;
}
F_72 ( V_14 -> V_116 ) ;
}
static int F_73 ( struct V_216 * V_217 ,
struct V_1 * V_2 ,
struct V_218 * V_219 )
{
int V_91 ;
struct V_220 * V_221 = F_74 ( V_217 ) ;
struct V_10 * V_10 = F_75 ( V_221 ) ;
struct V_222 * V_223 = F_76 ( V_221 ) ;
struct V_11 * V_12 ;
struct V_111 * V_17 ;
struct V_224 * V_225 =
(struct V_224 * ) V_219 -> V_66 . V_160 ;
if ( ! V_219 -> V_66 . V_83 )
goto V_226;
V_12 = F_66 ( V_223 -> V_20 , sizeof( * V_12 ) , V_197 ) ;
if ( ! V_12 )
return - V_114 ;
V_2 -> V_66 = V_12 ;
memcpy ( & V_12 -> V_119 , & V_225 -> V_227 , 16 ) ;
V_91 = F_77 ( V_10 -> V_13 , V_12 -> V_119 , V_225 ) ;
if ( V_91 < 0 )
return V_91 ;
V_12 -> V_3 . V_22 = V_225 -> V_22 ;
V_12 -> V_3 . V_23 = V_225 -> V_23 ;
V_12 -> V_24 = V_225 -> V_25 ;
V_12 -> V_64 = V_225 -> V_64 ;
V_12 -> V_65 = V_225 -> V_65 ;
V_12 -> V_228 = V_225 -> V_228 ;
V_12 -> V_132 = V_225 -> V_132 ;
V_12 -> V_128 = V_225 -> V_128 ;
V_12 -> V_115 = V_225 -> V_115 ;
F_69 ( V_12 -> V_27 , V_225 -> V_27 ,
V_229 ) ;
F_69 ( V_12 -> V_32 , V_225 -> V_32 ,
V_230 ) ;
V_12 -> V_57 = V_225 -> V_57 ;
V_12 -> V_58 = V_225 -> V_58 ;
V_12 -> V_62 = V_225 -> V_231 ;
V_12 -> V_82 = V_225 -> V_82 ;
V_12 -> V_232 = V_225 -> V_232 ;
V_17 = F_65 ( V_223 -> V_20 , V_10 , & V_225 -> V_17 ) ;
if ( V_17 )
V_12 -> V_17 = V_17 ;
V_12 -> V_73 = V_225 -> V_73 ;
V_12 -> V_79 = V_225 -> V_79 ;
V_12 -> V_233 = V_225 -> V_233 ;
V_12 -> V_71 . V_72 = V_225 -> V_84 . V_72 ;
V_12 -> V_133 = F_66 ( V_223 -> V_20 , ( V_12 -> V_132 ) *
sizeof( * V_12 -> V_133 ) ,
V_197 ) ;
if ( ! V_12 -> V_133 )
return - V_114 ;
V_12 -> V_129 = F_66 ( V_223 -> V_20 , ( V_12 -> V_128 ) *
sizeof( * V_12 -> V_129 ) ,
V_197 ) ;
if ( ! V_12 -> V_129 )
return - V_114 ;
F_64 ( V_225 -> V_234 , V_12 -> V_133 ,
V_225 -> V_235 ,
V_12 -> V_132 ) ;
F_64 ( V_225 -> V_236 , V_12 -> V_129 ,
V_225 -> V_237 ,
V_12 -> V_128 ) ;
if ( V_12 -> V_71 . V_72 == 0 )
goto V_226;
V_12 -> V_71 . V_84 = ( T_1 * ) F_66 ( V_223 -> V_20 ,
V_12 -> V_71 . V_72 , V_197 ) ;
if ( V_12 -> V_71 . V_84 == NULL )
return - V_114 ;
memcpy ( V_12 -> V_71 . V_84 , V_225 -> V_84 . V_84 ,
V_225 -> V_84 . V_72 ) ;
V_12 -> V_71 . V_102 = V_225 -> V_84 . V_102 ;
V_12 -> V_71 . V_100 = V_225 -> V_84 . V_100 ;
V_226:
if ( V_219 -> V_238 == 0 ) {
F_10 ( V_223 -> V_20 , L_22 ) ;
return 0 ;
}
V_91 = F_78 ( V_2 , V_239 ,
F_79 ( V_239 ) ,
V_219 -> V_238 ) ;
if ( V_91 ) {
F_3 ( V_223 -> V_20 , L_23 ,
V_21 , V_219 -> V_238 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_80 ( struct V_170 * V_20 , struct V_94 * V_240 ,
struct V_241 * V_97 )
{
struct V_96 * V_163 ;
struct V_242 * V_243 =
(struct V_242 * ) V_97 -> V_66 . V_160 ;
V_163 = F_66 ( V_20 , sizeof( * V_163 ) , V_197 ) ;
if ( ! V_163 )
return - V_114 ;
V_163 -> V_135 = V_243 -> V_135 ;
V_163 -> V_102 = V_243 -> V_102 ;
V_163 -> V_100 = V_243 -> V_100 ;
V_163 -> V_83 = V_243 -> V_135 ;
if ( V_163 -> V_135 ) {
V_163 -> V_41 = ( char * ) F_66 ( V_20 , V_163 -> V_135 , V_197 ) ;
if ( ! V_163 -> V_41 )
return - V_114 ;
memcpy ( V_163 -> V_41 , V_243 -> V_41 , V_163 -> V_135 ) ;
}
V_240 -> V_108 . V_109 = V_163 ;
return 0 ;
}
static int F_81 ( struct V_216 * V_217 ,
struct V_92 * V_244 ,
struct V_245 * V_246 )
{
struct V_94 * V_95 ;
struct V_241 * V_247 ;
struct V_220 * V_221 = F_74 ( V_217 ) ;
struct V_222 * V_223 = F_76 ( V_221 ) ;
switch ( V_246 -> V_248 . V_249 ) {
case V_250 :
V_247 = F_82 ( V_246 ,
struct V_241 , V_246 ) ;
if ( V_244 -> V_105 & V_106 ) {
V_95 = (struct V_94 * ) V_244 -> V_107 ;
if ( V_247 -> V_66 . V_83 )
return F_80 (
V_223 -> V_20 , V_95 , V_247 ) ;
}
break;
default:
F_83 ( V_223 -> V_20 , L_24 ,
V_246 -> V_248 . V_251 , V_246 -> V_248 . V_252 , V_246 -> V_248 . V_249 ) ;
break;
}
return 0 ;
}
static int F_84 ( struct V_209 * V_210 )
{
struct V_1 * V_2 ;
struct V_11 * V_26 = NULL ;
struct V_112 * V_253 = NULL ;
struct V_111 * V_17 ;
F_24 (w, &platform->component.card->widgets, list) {
if ( F_1 ( V_2 ) && V_2 -> V_66 != NULL ) {
V_26 = V_2 -> V_66 ;
V_17 = V_26 -> V_17 ;
V_253 = F_66 ( V_210 -> V_20 ,
sizeof( * V_253 ) , V_197 ) ;
if ( ! V_253 )
return - V_114 ;
V_253 -> V_2 = V_2 ;
F_85 ( & V_253 -> V_200 , & V_17 -> V_199 ) ;
}
}
return 0 ;
}
static void F_86 ( struct V_10 * V_10 , struct V_111 * V_17 )
{
struct V_112 * V_113 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
bool V_254 = false , V_255 = false ;
F_24 (w_module, &pipe->w_list, node) {
V_2 = V_113 -> V_2 ;
V_12 = V_2 -> V_66 ;
if ( V_12 -> V_73 == V_168 )
V_254 = true ;
else if ( V_12 -> V_73 != V_256 )
V_255 = true ;
}
if ( V_254 && V_255 )
V_17 -> V_165 = true ;
else
V_17 -> V_165 = false ;
}
int F_87 ( struct V_209 * V_210 , struct V_220 * V_221 )
{
int V_91 ;
const struct V_257 * V_258 ;
struct V_222 * V_223 = F_76 ( V_221 ) ;
struct V_10 * V_10 = F_75 ( V_221 ) ;
struct V_193 * V_194 ;
V_91 = F_88 ( & V_258 , V_10 -> V_259 , V_223 -> V_20 ) ;
if ( V_91 < 0 ) {
F_3 ( V_223 -> V_20 , L_25 ,
V_10 -> V_259 , V_91 ) ;
V_91 = F_88 ( & V_258 , L_26 , V_223 -> V_20 ) ;
if ( V_91 < 0 ) {
F_3 ( V_223 -> V_20 , L_27 ,
L_26 , V_91 ) ;
return V_91 ;
}
}
V_91 = F_89 ( & V_210 -> V_211 ,
& V_260 , V_258 , 0 ) ;
if ( V_91 < 0 ) {
F_3 ( V_223 -> V_20 , L_28 , V_91 ) ;
F_90 ( V_258 ) ;
return - V_81 ;
}
V_10 -> V_15 . V_25 = V_261 ;
V_10 -> V_15 . V_19 = V_262 ;
V_10 -> V_263 = V_258 ;
V_91 = F_84 ( V_210 ) ;
if ( V_91 < 0 )
return V_91 ;
F_24 (ppl, &skl->ppl_list, node)
F_86 ( V_10 , V_194 -> V_17 ) ;
return 0 ;
}
