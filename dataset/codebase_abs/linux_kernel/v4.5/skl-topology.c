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
V_27 = & V_26 -> V_27 [ 0 ] ;
V_32 = & V_26 -> V_32 [ 0 ] ;
if ( V_26 -> V_55 == V_56 )
V_54 = 5 ;
V_26 -> V_57 = ( V_27 -> V_29 / 1000 ) *
( V_26 -> V_27 -> V_28 ) *
( V_26 -> V_27 -> V_44 >> 3 ) *
V_54 ;
V_26 -> V_58 = ( V_26 -> V_32 -> V_29 / 1000 ) *
( V_26 -> V_32 -> V_28 ) *
( V_26 -> V_32 -> V_44 >> 3 ) *
V_54 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_11 * V_46 = V_2 -> V_59 ;
struct V_35 * V_36 = V_46 -> V_17 -> V_60 ;
int V_61 = V_46 -> V_17 -> V_62 ;
bool V_47 ;
if ( ! V_46 -> V_52 )
return;
F_10 ( V_14 -> V_20 , L_11 ,
V_2 -> V_63 ) ;
F_9 ( V_14 , V_46 ) ;
if ( V_61 == V_64 )
V_47 = true ;
else
V_47 = false ;
F_13 ( V_46 , V_36 , V_47 ) ;
F_14 ( V_14 , V_46 ) ;
F_10 ( V_14 -> V_20 , L_12 ,
V_2 -> V_63 ) ;
F_9 ( V_14 , V_46 ) ;
}
static int F_16 ( struct V_65 * V_20 ,
struct V_1 * V_2 , struct V_66 * V_17 )
{
struct V_11 * V_67 = NULL ;
struct V_68 * V_69 = NULL ;
struct V_70 * V_71 = NULL ;
V_71 = F_17 ( V_20 , sizeof( * V_71 ) , V_72 ) ;
if ( ! V_71 )
return - V_73 ;
V_71 -> V_2 = V_2 ;
F_18 ( & V_71 -> V_74 , & V_17 -> V_75 ) ;
F_19 (w, p) {
if ( ( V_69 -> V_76 -> V_59 == NULL )
&& ( ! F_1 ( V_2 ) ) )
continue;
if ( ( V_69 -> V_76 -> V_59 != NULL ) && V_69 -> V_77
&& F_1 ( V_69 -> V_76 ) ) {
V_67 = V_69 -> V_76 -> V_59 ;
if ( V_17 -> V_78 == V_67 -> V_17 -> V_78 )
F_16 ( V_20 ,
V_69 -> V_76 , V_17 ) ;
}
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
int V_79 , V_80 ;
struct V_11 * V_12 = V_2 -> V_59 ;
const struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
if ( V_12 -> V_89 . V_90 > 0 &&
V_12 -> V_89 . V_91 == V_92 ) {
V_88 = & V_12 -> V_89 ;
V_80 = F_21 ( V_14 , V_88 -> V_93 ,
V_88 -> V_90 ,
V_88 -> V_94 , V_12 ) ;
if ( V_80 < 0 )
return V_80 ;
}
for ( V_79 = 0 ; V_79 < V_2 -> V_95 ; V_79 ++ ) {
V_82 = & V_2 -> V_96 [ V_79 ] ;
if ( V_82 -> V_97 & V_98 ) {
V_84 = ( void * ) V_82 -> V_99 ;
V_86 = (struct V_85 * ) V_84 -> V_100 . V_101 ;
if ( V_86 -> V_91 == V_92 ) {
V_80 = F_21 ( V_14 ,
( V_102 * ) V_86 -> V_36 , V_86 -> V_103 ,
V_86 -> V_94 , V_12 ) ;
if ( V_80 < 0 )
return V_80 ;
}
}
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
const struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_11 * V_12 = V_2 -> V_59 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_2 -> V_95 ; V_79 ++ ) {
V_82 = & V_2 -> V_96 [ V_79 ] ;
if ( V_82 -> V_97 & V_98 ) {
V_84 = (struct V_83 * ) V_82 -> V_99 ;
V_86 = (struct V_85 * ) V_84 -> V_100 . V_101 ;
if ( V_86 -> V_91 != V_104 )
continue;
V_12 -> V_89 . V_93 = ( V_102 * ) & V_86 -> V_36 ;
V_12 -> V_89 . V_90 = V_86 -> V_103 ;
break;
}
}
return 0 ;
}
static int
F_23 ( struct V_10 * V_10 , struct V_66 * V_17 )
{
struct V_70 * V_105 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_80 = 0 ;
F_24 (w_module, &pipe->w_list, node) {
V_2 = V_105 -> V_2 ;
V_12 = V_2 -> V_59 ;
if ( ! F_5 ( V_10 , V_12 ) )
return - V_73 ;
if ( V_12 -> V_106 && V_14 -> V_107 -> V_108 . V_109 ) {
V_80 = V_14 -> V_107 -> V_108 . V_109 ( V_14 -> V_107 ,
V_12 -> V_3 . V_22 , V_12 -> V_110 ) ;
if ( V_80 < 0 )
return V_80 ;
}
F_15 ( V_2 , V_14 ) ;
F_22 ( V_2 ) ;
V_80 = F_25 ( V_14 , V_12 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 = F_20 ( V_2 , V_14 ) ;
if ( V_80 < 0 )
return V_80 ;
F_6 ( V_10 , V_12 ) ;
}
return 0 ;
}
static int F_26 ( struct V_13 * V_14 ,
struct V_66 * V_17 )
{
struct V_70 * V_105 = NULL ;
struct V_11 * V_12 = NULL ;
F_24 (w_module, &pipe->w_list, node) {
V_12 = V_105 -> V_2 -> V_59 ;
if ( V_12 -> V_106 && V_14 -> V_107 -> V_108 . V_111 )
return V_14 -> V_107 -> V_108 . V_111 ( V_14 -> V_107 ,
V_12 -> V_3 . V_22 ) ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
int V_80 ;
struct V_11 * V_12 = V_2 -> V_59 ;
struct V_70 * V_105 ;
struct V_66 * V_112 = V_12 -> V_17 ;
struct V_11 * V_67 = NULL , * V_113 ;
struct V_13 * V_14 = V_10 -> V_13 ;
if ( ! F_5 ( V_10 , V_12 ) )
return - V_114 ;
if ( ! F_2 ( V_10 , V_12 ) )
return - V_73 ;
V_80 = F_28 ( V_14 , V_12 -> V_17 ) ;
if ( V_80 < 0 )
return V_80 ;
if ( F_29 ( & V_112 -> V_75 ) ) {
V_80 = F_16 ( V_14 -> V_20 , V_2 , V_112 ) ;
if ( V_80 < 0 )
return V_80 ;
}
V_80 = F_23 ( V_10 , V_112 ) ;
if ( V_80 < 0 )
return V_80 ;
F_24 (w_module, &s_pipe->w_list, node) {
V_113 = V_105 -> V_2 -> V_59 ;
if ( V_67 == NULL ) {
V_67 = V_113 ;
continue;
}
V_80 = F_30 ( V_14 , V_67 , V_113 ) ;
if ( V_80 < 0 )
return V_80 ;
V_67 = V_113 ;
}
F_4 ( V_10 , V_12 ) ;
F_6 ( V_10 , V_12 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_10 * V_10 ,
struct V_1 * V_115 ,
struct V_11 * V_116 )
{
struct V_68 * V_69 ;
struct V_1 * V_76 = NULL , * V_117 = NULL ;
struct V_11 * V_118 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_80 ;
F_19 (w, p) {
if ( ! V_69 -> V_77 )
continue;
F_10 ( V_14 -> V_20 , L_13 , V_21 , V_2 -> V_63 ) ;
F_10 ( V_14 -> V_20 , L_14 , V_21 , V_69 -> V_76 -> V_63 ) ;
V_117 = V_69 -> V_76 ;
if ( ! F_1 ( V_69 -> V_76 ) )
return F_31 ( V_69 -> V_76 , V_10 , V_115 , V_116 ) ;
if ( ( V_69 -> V_76 -> V_59 != NULL ) &&
F_1 ( V_69 -> V_76 ) ) {
V_76 = V_69 -> V_76 ;
V_118 = V_76 -> V_59 ;
V_80 = F_30 ( V_14 , V_116 , V_118 ) ;
if ( V_80 )
return V_80 ;
if ( V_118 -> V_17 -> V_119 != V_120 ) {
if ( V_118 -> V_17 -> V_62 !=
V_64 )
V_80 = F_32 ( V_14 ,
V_118 -> V_17 ) ;
if ( V_80 )
return V_80 ;
}
}
}
if ( ! V_76 )
return F_31 ( V_117 , V_10 , V_115 , V_116 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_116 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_80 = 0 ;
V_116 = V_2 -> V_59 ;
V_80 = F_31 ( V_2 , V_10 , V_2 , V_116 ) ;
if ( V_80 )
return V_80 ;
if ( V_116 -> V_17 -> V_62 != V_64 )
return F_32 ( V_14 , V_116 -> V_17 ) ;
return 0 ;
}
static struct V_1 * F_34 (
struct V_1 * V_2 , struct V_10 * V_10 )
{
struct V_68 * V_69 ;
struct V_1 * V_115 = NULL ;
struct V_13 * V_14 = V_10 -> V_13 ;
F_35 (w, p) {
V_115 = V_69 -> V_121 ;
if ( ! V_69 -> V_77 )
continue;
F_10 ( V_14 -> V_20 , L_15 , V_2 -> V_63 ) ;
F_10 ( V_14 -> V_20 , L_16 , V_69 -> V_121 -> V_63 ) ;
if ( ( V_69 -> V_121 -> V_59 != NULL ) &&
F_1 ( V_69 -> V_121 ) ) {
return V_69 -> V_121 ;
}
}
if ( V_115 != NULL )
return F_34 ( V_115 , V_10 ) ;
return NULL ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
int V_80 = 0 ;
struct V_1 * V_121 , * V_76 ;
struct V_11 * V_116 , * V_118 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_122 = 0 ;
V_76 = V_2 ;
V_118 = V_76 -> V_59 ;
V_121 = F_34 ( V_2 , V_10 ) ;
if ( V_121 != NULL ) {
V_116 = V_121 -> V_59 ;
V_118 = V_76 -> V_59 ;
V_122 = 1 ;
if ( V_116 -> V_17 -> V_119 != V_120 )
V_122 = 0 ;
}
if ( V_122 ) {
V_80 = F_30 ( V_14 , V_116 , V_118 ) ;
if ( V_80 )
return V_80 ;
if ( V_118 -> V_17 -> V_62 != V_64 )
V_80 = F_32 ( V_14 , V_118 -> V_17 ) ;
}
return V_80 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_116 , * V_118 ;
int V_80 = 0 , V_79 ;
struct V_13 * V_14 = V_10 -> V_13 ;
V_118 = V_2 -> V_59 ;
V_80 = F_38 ( V_14 , V_118 -> V_17 ) ;
if ( V_80 )
return V_80 ;
for ( V_79 = 0 ; V_79 < V_118 -> V_123 ; V_79 ++ ) {
if ( V_118 -> V_124 [ V_79 ] . V_125 == V_126 ) {
V_116 = V_118 -> V_124 [ V_79 ] . V_127 ;
if ( ! V_116 )
continue;
V_80 = F_38 ( V_14 , V_116 -> V_17 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 = F_39 ( V_14 ,
V_116 , V_118 ) ;
}
}
return V_80 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_59 ;
struct V_70 * V_105 ;
struct V_11 * V_67 = NULL , * V_113 ;
struct V_13 * V_14 = V_10 -> V_13 ;
struct V_66 * V_112 = V_12 -> V_17 ;
int V_80 = 0 ;
F_7 ( V_10 , V_12 ) ;
F_8 ( V_10 , V_12 ) ;
F_24 (w_module, &s_pipe->w_list, node) {
V_113 = V_105 -> V_2 -> V_59 ;
F_7 ( V_10 , V_113 ) ;
if ( V_67 == NULL ) {
V_67 = V_113 ;
continue;
}
F_39 ( V_14 , V_67 , V_113 ) ;
V_67 = V_113 ;
}
V_80 = F_41 ( V_14 , V_12 -> V_17 ) ;
return F_26 ( V_14 , V_112 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_116 , * V_118 ;
int V_80 = 0 , V_79 ;
struct V_13 * V_14 = V_10 -> V_13 ;
V_116 = V_2 -> V_59 ;
V_80 = F_38 ( V_14 , V_116 -> V_17 ) ;
if ( V_80 )
return V_80 ;
for ( V_79 = 0 ; V_79 < V_116 -> V_128 ; V_79 ++ ) {
if ( V_116 -> V_129 [ V_79 ] . V_125 == V_126 ) {
V_118 = V_116 -> V_129 [ V_79 ] . V_127 ;
if ( ! V_118 )
continue;
V_80 = F_39 ( V_14 , V_116 ,
V_118 ) ;
}
}
return V_80 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_130 * V_82 , int V_131 )
{
struct V_132 * V_133 = V_2 -> V_133 ;
struct V_10 * V_10 = F_44 ( V_133 -> V_20 ) ;
switch ( V_131 ) {
case V_134 :
return F_27 ( V_2 , V_10 ) ;
case V_135 :
return F_36 ( V_2 , V_10 ) ;
case V_136 :
return F_37 ( V_2 , V_10 ) ;
case V_137 :
return F_40 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_130 * V_82 , int V_131 )
{
struct V_132 * V_133 = V_2 -> V_133 ;
struct V_10 * V_10 = F_44 ( V_133 -> V_20 ) ;
switch ( V_131 ) {
case V_134 :
return F_27 ( V_2 , V_10 ) ;
case V_135 :
return F_36 ( V_2 , V_10 ) ;
case V_136 :
return F_37 ( V_2 , V_10 ) ;
case V_137 :
return F_40 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_130 * V_82 , int V_131 )
{
struct V_132 * V_133 = V_2 -> V_133 ;
struct V_10 * V_10 = F_44 ( V_133 -> V_20 ) ;
switch ( V_131 ) {
case V_134 :
return F_33 ( V_2 , V_10 ) ;
case V_137 :
return F_42 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_47 ( struct V_130 * V_138 ,
unsigned int T_1 * V_139 , unsigned int V_140 )
{
struct V_83 * V_84 =
(struct V_83 * ) V_138 -> V_99 ;
struct V_85 * V_86 = (struct V_85 * ) V_84 -> V_100 . V_101 ;
struct V_1 * V_2 = F_48 ( V_138 ) ;
struct V_11 * V_12 = V_2 -> V_59 ;
struct V_10 * V_10 = F_44 ( V_2 -> V_133 -> V_20 ) ;
if ( V_2 -> V_141 )
F_49 ( V_10 -> V_13 , ( V_102 * ) V_86 -> V_36 ,
V_86 -> V_103 , V_86 -> V_94 , V_12 ) ;
V_140 -= 2 * sizeof( V_102 ) ;
if ( V_140 > V_86 -> V_103 )
V_140 = V_86 -> V_103 ;
if ( V_86 -> V_36 ) {
if ( F_50 ( V_139 , & V_86 -> V_94 , sizeof( V_102 ) ) )
return - V_142 ;
if ( F_50 ( V_139 + 1 , & V_140 , sizeof( V_102 ) ) )
return - V_142 ;
if ( F_50 ( V_139 + 2 , V_86 -> V_36 , V_140 ) )
return - V_142 ;
}
return 0 ;
}
static int F_51 ( struct V_130 * V_138 ,
const unsigned int T_1 * V_139 , unsigned int V_140 )
{
struct V_1 * V_2 = F_48 ( V_138 ) ;
struct V_11 * V_12 = V_2 -> V_59 ;
struct V_83 * V_84 =
(struct V_83 * ) V_138 -> V_99 ;
struct V_85 * V_143 = (struct V_85 * ) V_84 -> V_100 . V_101 ;
struct V_10 * V_10 = F_44 ( V_2 -> V_133 -> V_20 ) ;
if ( V_143 -> V_36 ) {
if ( V_143 -> V_94 == V_144 ) {
if ( F_52 ( V_143 -> V_36 , V_139 , V_140 ) )
return - V_142 ;
} else {
if ( F_52 ( V_143 -> V_36 ,
V_139 + 2 , V_140 ) )
return - V_142 ;
}
if ( V_2 -> V_141 )
return F_21 ( V_10 -> V_13 ,
( V_102 * ) V_143 -> V_36 , V_143 -> V_103 ,
V_143 -> V_94 , V_12 ) ;
}
return 0 ;
}
int F_53 ( struct V_65 * V_20 ,
struct V_11 * V_12 ,
struct V_35 * V_36 )
{
struct V_66 * V_17 = V_12 -> V_17 ;
struct V_33 * V_145 = NULL ;
memcpy ( V_17 -> V_60 , V_36 , sizeof( * V_36 ) ) ;
if ( V_36 -> V_50 == V_51 )
V_145 = & V_12 -> V_27 [ 0 ] ;
else
V_145 = & V_12 -> V_32 [ 0 ] ;
V_145 -> V_29 = V_36 -> V_29 ;
V_145 -> V_28 = V_36 -> V_40 ;
V_145 -> V_31 = F_12 ( V_36 -> V_42 ) ;
switch ( V_145 -> V_31 ) {
case V_43 :
V_145 -> V_44 = V_145 -> V_31 ;
break;
case V_146 :
case V_45 :
V_145 -> V_44 = V_45 ;
break;
default:
F_3 ( V_20 , L_17 ,
V_145 -> V_31 ) ;
return - V_147 ;
}
if ( V_36 -> V_50 == V_51 ) {
V_12 -> V_57 = ( V_145 -> V_29 / 1000 ) *
( V_145 -> V_28 ) *
( V_145 -> V_44 >> 3 ) ;
} else {
V_12 -> V_58 = ( V_145 -> V_29 / 1000 ) *
( V_145 -> V_28 ) *
( V_145 -> V_44 >> 3 ) ;
}
return 0 ;
}
struct V_11 *
F_54 ( struct V_148 * V_149 , int V_50 )
{
struct V_1 * V_2 ;
struct V_68 * V_69 = NULL ;
if ( V_50 == V_51 ) {
V_2 = V_149 -> V_150 ;
F_19 (w, p) {
if ( V_69 -> V_77 && V_69 -> V_76 -> V_141 &&
! F_1 ( V_69 -> V_76 ) )
continue;
if ( V_69 -> V_76 -> V_59 ) {
F_10 ( V_149 -> V_20 , L_18 ,
V_69 -> V_76 -> V_63 ) ;
return V_69 -> V_76 -> V_59 ;
}
}
} else {
V_2 = V_149 -> V_151 ;
F_35 (w, p) {
if ( V_69 -> V_77 && V_69 -> V_121 -> V_141 &&
! F_1 ( V_69 -> V_121 ) )
continue;
if ( V_69 -> V_121 -> V_59 ) {
F_10 ( V_149 -> V_20 , L_18 ,
V_69 -> V_121 -> V_63 ) ;
return V_69 -> V_121 -> V_59 ;
}
}
}
return NULL ;
}
static T_2 F_55 ( int V_152 )
{
int V_80 ;
switch ( V_152 ) {
case V_153 :
V_80 = V_154 ;
break;
case V_155 :
V_80 = V_156 ;
break;
case V_157 :
V_80 = V_154 ;
break;
case V_158 :
V_80 = V_159 ;
break;
default:
V_80 = V_160 ;
break;
}
return V_80 ;
}
static int F_56 ( struct V_148 * V_149 ,
struct V_11 * V_12 ,
struct V_35 * V_36 )
{
struct V_66 * V_17 = V_12 -> V_17 ;
struct V_161 * V_162 ;
struct V_10 * V_10 = F_44 ( V_149 -> V_20 ) ;
int V_163 = F_55 ( V_12 -> V_152 ) ;
memcpy ( V_17 -> V_60 , V_36 , sizeof( * V_36 ) ) ;
if ( V_163 == V_159 )
return 0 ;
V_162 = F_57 ( V_10 , V_12 -> V_164 , V_163 ,
V_36 -> V_42 , V_36 -> V_40 ,
V_36 -> V_29 , V_36 -> V_50 ) ;
if ( V_162 ) {
V_12 -> V_89 . V_90 = V_162 -> V_140 ;
V_12 -> V_89 . V_93 = ( V_102 * ) & V_162 -> V_93 ;
} else {
F_3 ( V_149 -> V_20 , L_19 ,
V_12 -> V_164 , V_163 ,
V_36 -> V_50 ) ;
F_3 ( V_149 -> V_20 , L_20 ,
V_36 -> V_40 , V_36 -> V_29 , V_36 -> V_42 ) ;
return - V_147 ;
}
return 0 ;
}
static int F_58 ( struct V_148 * V_149 ,
struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_68 * V_69 ;
int V_80 = - V_165 ;
F_35 (w, p) {
if ( V_69 -> V_77 && F_1 ( V_69 -> V_121 ) &&
V_69 -> V_121 -> V_59 ) {
V_80 = F_56 ( V_149 ,
V_69 -> V_121 -> V_59 , V_36 ) ;
if ( V_80 < 0 )
return V_80 ;
} else {
V_80 = F_58 ( V_149 ,
V_69 -> V_121 , V_36 ) ;
if ( V_80 < 0 )
return V_80 ;
}
}
return V_80 ;
}
static int F_59 ( struct V_148 * V_149 ,
struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_68 * V_69 = NULL ;
int V_80 = - V_165 ;
F_19 (w, p) {
if ( V_69 -> V_77 && F_1 ( V_69 -> V_76 ) &&
V_69 -> V_76 -> V_59 ) {
V_80 = F_56 ( V_149 ,
V_69 -> V_76 -> V_59 , V_36 ) ;
if ( V_80 < 0 )
return V_80 ;
} else {
V_80 = F_59 (
V_149 , V_69 -> V_76 , V_36 ) ;
if ( V_80 < 0 )
return V_80 ;
}
}
return V_80 ;
}
int F_60 ( struct V_148 * V_149 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 ;
if ( V_36 -> V_50 == V_51 ) {
V_2 = V_149 -> V_150 ;
return F_58 ( V_149 , V_2 , V_36 ) ;
} else {
V_2 = V_149 -> V_151 ;
return F_59 ( V_149 , V_2 , V_36 ) ;
}
return 0 ;
}
static void F_61 ( struct V_166 * V_167 ,
struct V_168 * V_169 ,
bool V_170 , int V_171 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_171 ; V_79 ++ ) {
V_169 [ V_79 ] . V_3 . V_22 = V_167 [ V_79 ] . V_22 ;
V_169 [ V_79 ] . V_3 . V_23 = V_167 [ V_79 ] . V_23 ;
V_169 [ V_79 ] . V_172 = false ;
V_169 [ V_79 ] . V_170 = V_170 ;
V_169 [ V_79 ] . V_125 = V_173 ;
}
}
static struct V_66 * F_62 ( struct V_65 * V_20 ,
struct V_10 * V_10 , struct V_174 * V_175 )
{
struct V_176 * V_177 ;
struct V_66 * V_17 ;
struct V_35 * V_36 ;
F_24 (ppl, &skl->ppl_list, node) {
if ( V_177 -> V_17 -> V_78 == V_175 -> V_178 )
return V_177 -> V_17 ;
}
V_177 = F_17 ( V_20 , sizeof( * V_177 ) , V_72 ) ;
if ( ! V_177 )
return NULL ;
V_17 = F_17 ( V_20 , sizeof( * V_17 ) , V_72 ) ;
if ( ! V_17 )
return NULL ;
V_36 = F_17 ( V_20 , sizeof( * V_36 ) , V_72 ) ;
if ( ! V_36 )
return NULL ;
V_17 -> V_78 = V_175 -> V_178 ;
V_17 -> V_18 = V_175 -> V_18 ;
V_17 -> V_179 = V_175 -> V_179 ;
V_17 -> V_62 = V_175 -> V_62 ;
V_17 -> V_119 = V_180 ;
V_17 -> V_60 = V_36 ;
F_63 ( & V_17 -> V_75 ) ;
V_177 -> V_17 = V_17 ;
F_64 ( & V_177 -> V_74 , & V_10 -> V_181 ) ;
return V_177 -> V_17 ;
}
static void F_65 ( struct V_33 * V_182 ,
struct V_183 * V_184 ,
int V_185 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_185 ; V_79 ++ ) {
V_182 [ V_79 ] . V_28 = V_184 [ V_79 ] . V_28 ;
V_182 [ V_79 ] . V_29 = V_184 [ V_79 ] . V_186 ;
V_182 [ V_79 ] . V_44 = V_184 [ V_79 ] . V_44 ;
V_182 [ V_79 ] . V_31 = V_184 [ V_79 ] . V_31 ;
V_182 [ V_79 ] . V_30 = V_184 [ V_79 ] . V_30 ;
V_182 [ V_79 ] . V_187 = V_184 [ V_79 ] . V_187 ;
V_182 [ V_79 ] . V_188 = V_184 [ V_79 ] . V_188 ;
V_182 [ V_79 ] . V_189 = V_184 [ V_79 ] . V_189 ;
}
}
static int F_66 ( struct V_190 * V_191 ,
struct V_1 * V_2 ,
struct V_192 * V_193 )
{
int V_80 ;
struct V_194 * V_195 = F_67 ( V_191 ) ;
struct V_10 * V_10 = F_68 ( V_195 ) ;
struct V_196 * V_197 = F_69 ( V_195 ) ;
struct V_11 * V_12 ;
struct V_66 * V_17 ;
struct V_198 * V_199 =
(struct V_198 * ) V_193 -> V_59 . V_139 ;
if ( ! V_193 -> V_59 . V_140 )
goto V_200;
V_12 = F_17 ( V_197 -> V_20 , sizeof( * V_12 ) , V_72 ) ;
if ( ! V_12 )
return - V_73 ;
V_2 -> V_59 = V_12 ;
V_12 -> V_3 . V_22 = V_199 -> V_22 ;
V_12 -> V_3 . V_23 = V_199 -> V_23 ;
V_12 -> V_24 = V_199 -> V_25 ;
V_12 -> V_57 = V_199 -> V_57 ;
V_12 -> V_58 = V_199 -> V_58 ;
V_12 -> V_201 = V_199 -> V_201 ;
V_12 -> V_123 = V_199 -> V_123 ;
V_12 -> V_128 = V_199 -> V_128 ;
V_12 -> V_106 = V_199 -> V_106 ;
F_65 ( V_12 -> V_27 , V_199 -> V_27 ,
V_202 ) ;
F_65 ( V_12 -> V_32 , V_199 -> V_32 ,
V_203 ) ;
V_12 -> V_52 = V_199 -> V_52 ;
V_12 -> V_53 = V_199 -> V_53 ;
V_12 -> V_55 = V_199 -> V_204 ;
V_12 -> V_164 = V_199 -> V_164 ;
V_12 -> V_205 = V_199 -> V_205 ;
V_17 = F_62 ( V_197 -> V_20 , V_10 , & V_199 -> V_17 ) ;
if ( V_17 )
V_12 -> V_17 = V_17 ;
V_12 -> V_152 = V_199 -> V_152 ;
V_12 -> V_206 = V_199 -> V_206 ;
V_12 -> V_207 = V_199 -> V_207 ;
V_12 -> V_89 . V_90 = V_199 -> V_93 . V_90 ;
if ( V_199 -> V_106 )
memcpy ( V_12 -> V_110 , V_199 -> V_208 ,
F_70 ( V_199 -> V_208 ) ) ;
V_12 -> V_124 = F_17 ( V_197 -> V_20 , ( V_12 -> V_123 ) *
sizeof( * V_12 -> V_124 ) ,
V_72 ) ;
if ( ! V_12 -> V_124 )
return - V_73 ;
V_12 -> V_129 = F_17 ( V_197 -> V_20 , ( V_12 -> V_128 ) *
sizeof( * V_12 -> V_129 ) ,
V_72 ) ;
if ( ! V_12 -> V_129 )
return - V_73 ;
F_61 ( V_199 -> V_209 , V_12 -> V_124 ,
V_199 -> V_210 ,
V_12 -> V_123 ) ;
F_61 ( V_199 -> V_211 , V_12 -> V_129 ,
V_199 -> V_212 ,
V_12 -> V_128 ) ;
if ( V_12 -> V_89 . V_90 == 0 )
goto V_200;
V_12 -> V_89 . V_93 = ( V_102 * ) F_17 ( V_197 -> V_20 ,
V_12 -> V_89 . V_90 , V_72 ) ;
if ( V_12 -> V_89 . V_93 == NULL )
return - V_73 ;
memcpy ( V_12 -> V_89 . V_93 , V_199 -> V_93 . V_93 ,
V_199 -> V_93 . V_90 ) ;
V_12 -> V_89 . V_94 = V_199 -> V_93 . V_94 ;
V_12 -> V_89 . V_91 = V_199 -> V_93 . V_91 ;
V_200:
if ( V_193 -> V_213 == 0 ) {
F_10 ( V_197 -> V_20 , L_21 ) ;
return 0 ;
}
V_80 = F_71 ( V_2 , V_214 ,
F_70 ( V_214 ) ,
V_193 -> V_213 ) ;
if ( V_80 ) {
F_3 ( V_197 -> V_20 , L_22 ,
V_21 , V_193 -> V_213 ) ;
return - V_147 ;
}
return 0 ;
}
static int F_72 ( struct V_65 * V_20 , struct V_83 * V_215 ,
struct V_216 * V_86 )
{
struct V_85 * V_143 ;
struct V_217 * V_218 =
(struct V_217 * ) V_86 -> V_59 . V_139 ;
V_143 = F_17 ( V_20 , sizeof( * V_143 ) , V_72 ) ;
if ( ! V_143 )
return - V_73 ;
V_143 -> V_103 = V_218 -> V_103 ;
V_143 -> V_94 = V_218 -> V_94 ;
V_143 -> V_91 = V_218 -> V_91 ;
if ( V_143 -> V_103 ) {
V_143 -> V_36 = ( char * ) F_17 ( V_20 , V_143 -> V_103 , V_72 ) ;
if ( ! V_143 -> V_36 )
return - V_73 ;
if ( V_218 -> V_36 )
memcpy ( V_143 -> V_36 , V_218 -> V_36 , V_143 -> V_103 ) ;
}
V_215 -> V_100 . V_101 = V_143 ;
return 0 ;
}
static int F_73 ( struct V_190 * V_191 ,
struct V_81 * V_219 ,
struct V_220 * V_221 )
{
struct V_83 * V_84 ;
struct V_216 * V_222 ;
struct V_194 * V_195 = F_67 ( V_191 ) ;
struct V_196 * V_197 = F_69 ( V_195 ) ;
switch ( V_221 -> V_223 . V_224 ) {
case V_225 :
V_222 = F_74 ( V_221 ,
struct V_216 , V_221 ) ;
if ( V_219 -> V_97 & V_98 ) {
V_84 = (struct V_83 * ) V_219 -> V_99 ;
if ( V_222 -> V_59 . V_140 )
return F_72 (
V_197 -> V_20 , V_84 , V_222 ) ;
}
break;
default:
F_75 ( V_197 -> V_20 , L_23 ,
V_221 -> V_223 . V_226 , V_221 -> V_223 . V_227 , V_221 -> V_223 . V_224 ) ;
break;
}
return 0 ;
}
int F_76 ( struct V_228 * V_229 , struct V_194 * V_195 )
{
int V_80 ;
const struct V_230 * V_231 ;
struct V_196 * V_197 = F_69 ( V_195 ) ;
struct V_10 * V_10 = F_68 ( V_195 ) ;
V_80 = F_77 ( & V_231 , L_24 , V_197 -> V_20 ) ;
if ( V_80 < 0 ) {
F_3 ( V_197 -> V_20 , L_25 ,
L_24 , V_80 ) ;
return V_80 ;
}
V_80 = F_78 ( & V_229 -> V_232 ,
& V_233 , V_231 , 0 ) ;
if ( V_80 < 0 ) {
F_3 ( V_197 -> V_20 , L_26 , V_80 ) ;
F_79 ( V_231 ) ;
return - V_147 ;
}
V_10 -> V_15 . V_25 = V_234 ;
V_10 -> V_15 . V_19 = V_235 ;
V_10 -> V_236 = V_231 ;
return 0 ;
}
