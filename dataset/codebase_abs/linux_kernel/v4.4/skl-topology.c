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
}
V_10 -> V_15 . V_16 += V_12 -> V_17 -> V_18 ;
return true ;
}
static bool F_4 ( struct V_10 * V_10 ,
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
}
V_10 -> V_15 . V_24 += V_12 -> V_24 ;
return true ;
}
static void
F_5 ( struct V_10 * V_10 , struct V_11 * V_12 )
{
V_10 -> V_15 . V_24 -= V_12 -> V_24 ;
}
static void
F_6 ( struct V_10 * V_10 , struct V_11 * V_12 )
{
V_10 -> V_15 . V_16 -= V_12 -> V_17 -> V_18 ;
}
static void F_7 ( struct V_13 * V_14 ,
struct V_11 * V_26 )
{
F_8 ( V_14 -> V_20 , L_4 ) ;
F_8 ( V_14 -> V_20 , L_5 ) ;
F_8 ( V_14 -> V_20 , L_6 , V_26 -> V_27 . V_28 ) ;
F_8 ( V_14 -> V_20 , L_7 , V_26 -> V_27 . V_29 ) ;
F_8 ( V_14 -> V_20 , L_8 , V_26 -> V_27 . V_30 ) ;
F_8 ( V_14 -> V_20 , L_9 ,
V_26 -> V_27 . V_31 ) ;
F_8 ( V_14 -> V_20 , L_10 ) ;
F_8 ( V_14 -> V_20 , L_6 , V_26 -> V_32 . V_28 ) ;
F_8 ( V_14 -> V_20 , L_7 , V_26 -> V_32 . V_29 ) ;
F_8 ( V_14 -> V_20 , L_9 ,
V_26 -> V_32 . V_31 ) ;
F_8 ( V_14 -> V_20 , L_8 , V_26 -> V_32 . V_30 ) ;
}
static void F_9 ( struct V_33 * V_34 ,
struct V_35 * V_36 , int V_37 )
{
if ( V_37 & V_38 )
V_34 -> V_29 = V_36 -> V_29 ;
if ( V_37 & V_39 )
V_34 -> V_28 = V_36 -> V_40 ;
if ( V_37 & V_41 )
V_34 -> V_31 = V_36 -> V_42 ;
}
static void F_10 ( struct V_11 * V_43 ,
struct V_35 * V_36 , bool V_44 )
{
int V_45 , V_46 ;
struct V_33 * V_27 , * V_32 ;
V_27 = & V_43 -> V_27 ;
V_32 = & V_43 -> V_32 ;
if ( V_36 -> V_47 == V_48 ) {
if ( V_44 ) {
V_45 = V_43 -> V_49 ;
V_46 = ( ~ V_43 -> V_50 ) &
V_43 -> V_49 ;
} else {
V_46 = V_43 -> V_49 ;
V_45 = ( ~ V_43 -> V_50 ) &
V_43 -> V_49 ;
}
} else {
if ( V_44 ) {
V_46 = V_43 -> V_49 ;
V_45 = ( ~ V_43 -> V_50 ) &
V_43 -> V_49 ;
} else {
V_45 = V_43 -> V_49 ;
V_46 = ( ~ V_43 -> V_50 ) &
V_43 -> V_49 ;
}
}
F_9 ( V_27 , V_36 , V_45 ) ;
F_9 ( V_32 , V_36 , V_46 ) ;
}
static void F_11 ( struct V_13 * V_14 ,
struct V_11 * V_26 )
{
int V_51 = 1 ;
if ( V_26 -> V_52 == V_53 )
V_51 = 5 ;
V_26 -> V_54 = ( V_26 -> V_27 . V_29 / 1000 ) *
( V_26 -> V_27 . V_28 ) *
( V_26 -> V_27 . V_55 >> 3 ) *
V_51 ;
V_26 -> V_56 = ( V_26 -> V_32 . V_29 / 1000 ) *
( V_26 -> V_32 . V_28 ) *
( V_26 -> V_32 . V_55 >> 3 ) *
V_51 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_11 * V_43 = V_2 -> V_57 ;
struct V_35 * V_36 = V_43 -> V_17 -> V_58 ;
int V_59 = V_43 -> V_17 -> V_60 ;
bool V_44 ;
if ( ! V_43 -> V_49 )
return;
F_8 ( V_14 -> V_20 , L_11 ,
V_2 -> V_61 ) ;
F_7 ( V_14 , V_43 ) ;
if ( V_59 == V_62 )
V_44 = true ;
else
V_44 = false ;
F_10 ( V_43 , V_36 , V_44 ) ;
F_11 ( V_14 , V_43 ) ;
F_8 ( V_14 -> V_20 , L_12 ,
V_2 -> V_61 ) ;
F_7 ( V_14 , V_43 ) ;
}
static int F_13 ( struct V_63 * V_20 ,
struct V_1 * V_2 , struct V_64 * V_17 )
{
struct V_11 * V_65 = NULL ;
struct V_66 * V_67 = NULL ;
struct V_68 * V_69 = NULL ;
V_69 = F_14 ( V_20 , sizeof( * V_69 ) , V_70 ) ;
if ( ! V_69 )
return - V_71 ;
V_69 -> V_2 = V_2 ;
F_15 ( & V_69 -> V_72 , & V_17 -> V_73 ) ;
F_16 (w, p) {
if ( ( V_67 -> V_74 -> V_57 == NULL )
&& ( ! F_1 ( V_2 ) ) )
continue;
if ( ( V_67 -> V_74 -> V_57 != NULL ) && V_67 -> V_75
&& F_1 ( V_67 -> V_74 ) ) {
V_65 = V_67 -> V_74 -> V_57 ;
if ( V_17 -> V_76 == V_65 -> V_17 -> V_76 )
F_13 ( V_20 ,
V_67 -> V_74 , V_17 ) ;
}
}
return 0 ;
}
static int
F_17 ( struct V_10 * V_10 , struct V_64 * V_17 )
{
struct V_68 * V_77 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_78 = 0 ;
F_18 (w_module, &pipe->w_list, node) {
V_2 = V_77 -> V_2 ;
V_12 = V_2 -> V_57 ;
if ( ! F_4 ( V_10 , V_12 ) )
return - V_71 ;
F_12 ( V_2 , V_14 ) ;
V_78 = F_19 ( V_14 , V_12 , NULL ) ;
if ( V_78 < 0 )
return V_78 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
int V_78 ;
struct V_11 * V_12 = V_2 -> V_57 ;
struct V_68 * V_77 ;
struct V_64 * V_79 = V_12 -> V_17 ;
struct V_11 * V_65 = NULL , * V_80 ;
struct V_13 * V_14 = V_10 -> V_13 ;
if ( ! F_4 ( V_10 , V_12 ) )
return - V_81 ;
if ( ! F_2 ( V_10 , V_12 ) )
return - V_71 ;
V_78 = F_21 ( V_14 , V_12 -> V_17 ) ;
if ( V_78 < 0 )
return V_78 ;
if ( F_22 ( & V_79 -> V_73 ) ) {
V_78 = F_13 ( V_14 -> V_20 , V_2 , V_79 ) ;
if ( V_78 < 0 )
return V_78 ;
}
V_78 = F_17 ( V_10 , V_79 ) ;
if ( V_78 < 0 )
return V_78 ;
F_18 (w_module, &s_pipe->w_list, node) {
V_80 = V_77 -> V_2 -> V_57 ;
if ( V_65 == NULL ) {
V_65 = V_80 ;
continue;
}
V_78 = F_23 ( V_14 , V_65 , V_80 ) ;
if ( V_78 < 0 )
return V_78 ;
V_65 = V_80 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_66 * V_67 ;
struct V_82 * V_83 ;
struct V_1 * V_84 , * V_74 ;
struct V_11 * V_85 , * V_86 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_78 = 0 ;
V_84 = V_2 ;
V_85 = V_84 -> V_57 ;
F_25 (w, p) {
if ( ! V_67 -> V_75 )
continue;
F_8 ( V_14 -> V_20 , L_13 , V_21 , V_2 -> V_61 ) ;
F_8 ( V_14 -> V_20 , L_14 , V_21 , V_67 -> V_74 -> V_61 ) ;
if ( ( V_67 -> V_74 -> V_57 != NULL ) &&
F_1 ( V_67 -> V_74 ) ) {
V_74 = V_67 -> V_74 ;
V_85 = V_84 -> V_57 ;
V_86 = V_74 -> V_57 ;
V_78 = F_23 ( V_14 , V_85 , V_86 ) ;
if ( V_78 )
return V_78 ;
if ( V_86 -> V_17 -> V_87 != V_88 ) {
V_78 = F_26 ( V_14 , V_86 -> V_17 ) ;
if ( V_78 )
return V_78 ;
}
V_83 = F_27 (
sizeof( struct V_82 ) ,
V_70 ) ;
if ( V_83 == NULL )
return - V_71 ;
V_83 -> V_89 = V_67 ;
F_15 ( & V_83 -> V_72 , & V_10 -> V_90 ) ;
break;
}
}
V_78 = F_26 ( V_14 , V_85 -> V_17 ) ;
if ( V_78 )
return V_78 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
int V_78 = 0 ;
struct V_66 * V_67 ;
struct V_1 * V_84 , * V_74 ;
struct V_11 * V_85 , * V_86 ;
struct V_13 * V_14 = V_10 -> V_13 ;
int V_91 = 0 ;
V_74 = V_2 ;
V_86 = V_74 -> V_57 ;
F_16 (w, p) {
if ( ! V_67 -> V_75 )
continue;
F_8 ( V_14 -> V_20 , L_15 , V_2 -> V_61 ) ;
F_8 ( V_14 -> V_20 , L_16 , V_67 -> V_84 -> V_61 ) ;
if ( ( V_67 -> V_84 -> V_57 != NULL ) &&
F_1 ( V_67 -> V_84 ) ) {
V_84 = V_67 -> V_84 ;
V_85 = V_84 -> V_57 ;
V_86 = V_74 -> V_57 ;
V_91 = 1 ;
if ( V_85 -> V_17 -> V_87 != V_88 )
V_91 = 0 ;
}
}
if ( V_91 ) {
V_78 = F_23 ( V_14 , V_85 , V_86 ) ;
if ( V_78 )
return V_78 ;
V_78 = F_26 ( V_14 , V_86 -> V_17 ) ;
}
return V_78 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_1 * V_84 , * V_74 ;
struct V_11 * V_85 , * V_86 ;
int V_78 = 0 , V_92 = 0 ;
struct V_82 * V_83 , * V_93 ;
struct V_13 * V_14 = V_10 -> V_13 ;
V_74 = V_2 ;
V_86 = V_74 -> V_57 ;
V_78 = F_30 ( V_14 , V_86 -> V_17 ) ;
if ( V_78 )
return V_78 ;
F_31 (path_list, tmp_list,
&skl->dapm_path_list, node) {
if ( V_83 -> V_89 -> V_74 == V_74 ) {
F_8 ( V_14 -> V_20 , L_17 ,
V_83 -> V_89 -> V_61 ) ;
V_84 = V_83 -> V_89 -> V_84 ;
V_85 = V_84 -> V_57 ;
V_92 = 1 ;
F_32 ( & V_83 -> V_72 ) ;
F_33 ( V_83 ) ;
break;
}
}
if ( V_92 ) {
V_78 = F_30 ( V_14 , V_85 -> V_17 ) ;
if ( V_78 < 0 )
return V_78 ;
V_78 = F_34 ( V_14 , V_85 , V_86 ) ;
}
return V_78 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_57 ;
struct V_68 * V_77 ;
struct V_11 * V_65 = NULL , * V_80 ;
struct V_13 * V_14 = V_10 -> V_13 ;
struct V_64 * V_79 = V_12 -> V_17 ;
int V_78 = 0 ;
F_5 ( V_10 , V_12 ) ;
F_18 (w_module, &s_pipe->w_list, node) {
V_80 = V_77 -> V_2 -> V_57 ;
if ( V_65 == NULL ) {
V_65 = V_80 ;
continue;
}
V_78 = F_34 ( V_14 , V_65 , V_80 ) ;
if ( V_78 < 0 )
return V_78 ;
V_65 = V_80 ;
}
V_78 = F_36 ( V_14 , V_12 -> V_17 ) ;
F_6 ( V_10 , V_12 ) ;
return V_78 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_10 * V_10 )
{
struct V_1 * V_84 , * V_74 ;
struct V_11 * V_85 , * V_86 ;
int V_78 = 0 , V_92 = 0 ;
struct V_82 * V_83 , * V_94 ;
struct V_13 * V_14 = V_10 -> V_13 ;
V_84 = V_2 ;
V_85 = V_84 -> V_57 ;
F_5 ( V_10 , V_85 ) ;
V_78 = F_30 ( V_14 , V_85 -> V_17 ) ;
if ( V_78 )
return V_78 ;
F_31 (path_list, tmp_path_list, &skl->dapm_path_list, node) {
if ( V_83 -> V_89 -> V_84 == V_84 ) {
F_8 ( V_14 -> V_20 , L_17 ,
V_83 -> V_89 -> V_61 ) ;
V_74 = V_83 -> V_89 -> V_74 ;
V_86 = V_74 -> V_57 ;
V_92 = 1 ;
F_32 ( & V_83 -> V_72 ) ;
F_33 ( V_83 ) ;
break;
}
}
if ( V_92 ) {
V_78 = F_30 ( V_14 , V_85 -> V_17 ) ;
if ( V_78 < 0 )
return V_78 ;
V_78 = F_34 ( V_14 , V_85 , V_86 ) ;
}
return V_78 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_95 * V_96 , int V_97 )
{
struct V_98 * V_99 = V_2 -> V_99 ;
struct V_10 * V_10 = F_39 ( V_99 -> V_20 ) ;
switch ( V_97 ) {
case V_100 :
return F_20 ( V_2 , V_10 ) ;
case V_101 :
return F_35 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_95 * V_96 , int V_97 )
{
struct V_98 * V_99 = V_2 -> V_99 ;
struct V_10 * V_10 = F_39 ( V_99 -> V_20 ) ;
switch ( V_97 ) {
case V_100 :
return F_20 ( V_2 , V_10 ) ;
case V_102 :
return F_28 ( V_2 , V_10 ) ;
case V_103 :
return F_29 ( V_2 , V_10 ) ;
case V_101 :
return F_35 ( V_2 , V_10 ) ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_95 * V_96 , int V_97 )
{
struct V_98 * V_99 = V_2 -> V_99 ;
struct V_10 * V_10 = F_39 ( V_99 -> V_20 ) ;
switch ( V_97 ) {
case V_100 :
return F_24 ( V_2 , V_10 ) ;
case V_101 :
return F_37 ( V_2 , V_10 ) ;
}
return 0 ;
}
int F_42 ( struct V_63 * V_20 ,
struct V_11 * V_12 ,
struct V_35 * V_36 )
{
struct V_64 * V_17 = V_12 -> V_17 ;
struct V_33 * V_104 = NULL ;
memcpy ( V_17 -> V_58 , V_36 , sizeof( * V_36 ) ) ;
if ( V_36 -> V_47 == V_48 )
V_104 = & V_12 -> V_27 ;
else
V_104 = & V_12 -> V_32 ;
V_104 -> V_29 = V_36 -> V_29 ;
V_104 -> V_28 = V_36 -> V_40 ;
V_104 -> V_31 = F_43 ( V_36 -> V_42 ) ;
switch ( V_104 -> V_31 ) {
case V_105 :
V_104 -> V_55 = V_104 -> V_31 ;
break;
case V_106 :
V_104 -> V_55 = V_107 ;
break;
default:
F_3 ( V_20 , L_18 ,
V_104 -> V_31 ) ;
return - V_108 ;
}
if ( V_36 -> V_47 == V_48 ) {
V_12 -> V_54 = ( V_104 -> V_29 / 1000 ) *
( V_104 -> V_28 ) *
( V_104 -> V_55 >> 3 ) ;
} else {
V_12 -> V_56 = ( V_104 -> V_29 / 1000 ) *
( V_104 -> V_28 ) *
( V_104 -> V_55 >> 3 ) ;
}
return 0 ;
}
struct V_11 *
F_44 ( struct V_109 * V_110 , int V_47 )
{
struct V_1 * V_2 ;
struct V_66 * V_67 = NULL ;
if ( V_47 == V_48 ) {
V_2 = V_110 -> V_111 ;
F_16 (w, p) {
if ( V_67 -> V_75 && V_67 -> V_74 -> V_112 &&
F_1 ( V_67 -> V_74 ) )
continue;
if ( V_67 -> V_74 -> V_57 ) {
F_8 ( V_110 -> V_20 , L_19 ,
V_67 -> V_74 -> V_61 ) ;
return V_67 -> V_74 -> V_57 ;
}
}
} else {
V_2 = V_110 -> V_113 ;
F_25 (w, p) {
if ( V_67 -> V_75 && V_67 -> V_84 -> V_112 &&
F_1 ( V_67 -> V_84 ) )
continue;
if ( V_67 -> V_84 -> V_57 ) {
F_8 ( V_110 -> V_20 , L_19 ,
V_67 -> V_84 -> V_61 ) ;
return V_67 -> V_84 -> V_57 ;
}
}
}
return NULL ;
}
static T_1 F_45 ( int V_114 )
{
int V_78 ;
switch ( V_114 ) {
case V_115 :
V_78 = V_116 ;
break;
case V_117 :
V_78 = V_118 ;
break;
case V_119 :
V_78 = V_116 ;
break;
case V_120 :
V_78 = V_121 ;
break;
default:
V_78 = V_122 ;
break;
}
return V_78 ;
}
static int F_46 ( struct V_109 * V_110 ,
struct V_11 * V_12 ,
struct V_35 * V_36 )
{
struct V_64 * V_17 = V_12 -> V_17 ;
struct V_123 * V_124 ;
struct V_10 * V_10 = F_39 ( V_110 -> V_20 ) ;
int V_125 = F_45 ( V_12 -> V_114 ) ;
memcpy ( V_17 -> V_58 , V_36 , sizeof( * V_36 ) ) ;
V_124 = F_47 ( V_10 , V_12 -> V_126 , V_125 ,
V_36 -> V_42 , V_36 -> V_40 ,
V_36 -> V_29 , V_36 -> V_47 ) ;
if ( V_124 ) {
V_12 -> V_127 . V_128 = V_124 -> V_129 ;
V_12 -> V_127 . V_130 = ( V_131 * ) & V_124 -> V_130 ;
} else {
F_3 ( V_110 -> V_20 , L_20 ,
V_12 -> V_126 , V_125 ,
V_36 -> V_47 ) ;
F_3 ( V_110 -> V_20 , L_21 ,
V_36 -> V_40 , V_36 -> V_29 , V_36 -> V_42 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_48 ( struct V_109 * V_110 ,
struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_66 * V_67 ;
int V_78 = - V_132 ;
F_25 (w, p) {
if ( V_67 -> V_75 && F_1 ( V_67 -> V_84 ) &&
V_67 -> V_84 -> V_57 ) {
if ( ! V_67 -> V_84 -> V_112 ) {
V_78 = F_46 (
V_110 , V_67 -> V_84 -> V_57 ,
V_36 ) ;
if ( V_78 < 0 )
return V_78 ;
} else {
return - V_81 ;
}
} else {
V_78 = F_48 (
V_110 , V_67 -> V_84 , V_36 ) ;
if ( V_78 < 0 )
return V_78 ;
}
}
return V_78 ;
}
static int F_49 ( struct V_109 * V_110 ,
struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_66 * V_67 = NULL ;
int V_78 = - V_132 ;
F_16 (w, p) {
if ( V_67 -> V_75 && F_1 ( V_67 -> V_74 ) &&
V_67 -> V_74 -> V_57 ) {
if ( ! V_67 -> V_74 -> V_112 ) {
V_78 = F_46 (
V_110 , V_67 -> V_74 -> V_57 , V_36 ) ;
if ( V_78 < 0 )
return V_78 ;
} else {
return - V_81 ;
}
} else {
V_78 = F_49 (
V_110 , V_67 -> V_74 , V_36 ) ;
if ( V_78 < 0 )
return V_78 ;
}
}
return V_78 ;
}
int F_50 ( struct V_109 * V_110 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 ;
if ( V_36 -> V_47 == V_48 ) {
V_2 = V_110 -> V_111 ;
return F_48 ( V_110 , V_2 , V_36 ) ;
} else {
V_2 = V_110 -> V_113 ;
return F_49 ( V_110 , V_2 , V_36 ) ;
}
return 0 ;
}
static void F_51 ( struct V_133 * V_134 ,
struct V_135 * V_136 ,
bool V_137 , int V_138 )
{
int V_139 ;
for ( V_139 = 0 ; V_139 < V_138 ; V_139 ++ ) {
V_136 [ V_139 ] . V_3 . V_22 = V_134 [ V_139 ] . V_22 ;
V_136 [ V_139 ] . V_3 . V_23 = V_134 [ V_139 ] . V_23 ;
V_136 [ V_139 ] . V_140 = false ;
V_136 [ V_139 ] . V_137 = V_137 ;
}
}
static struct V_64 * F_52 ( struct V_63 * V_20 ,
struct V_10 * V_10 , struct V_141 * V_142 )
{
struct V_143 * V_144 ;
struct V_64 * V_17 ;
struct V_35 * V_36 ;
F_18 (ppl, &skl->ppl_list, node) {
if ( V_144 -> V_17 -> V_76 == V_142 -> V_145 )
return V_144 -> V_17 ;
}
V_144 = F_14 ( V_20 , sizeof( * V_144 ) , V_70 ) ;
if ( ! V_144 )
return NULL ;
V_17 = F_14 ( V_20 , sizeof( * V_17 ) , V_70 ) ;
if ( ! V_17 )
return NULL ;
V_36 = F_14 ( V_20 , sizeof( * V_36 ) , V_70 ) ;
if ( ! V_36 )
return NULL ;
V_17 -> V_76 = V_142 -> V_145 ;
V_17 -> V_18 = V_142 -> V_18 ;
V_17 -> V_146 = V_142 -> V_146 ;
V_17 -> V_60 = V_142 -> V_60 ;
V_17 -> V_87 = V_147 ;
V_17 -> V_58 = V_36 ;
F_53 ( & V_17 -> V_73 ) ;
V_144 -> V_17 = V_17 ;
F_54 ( & V_144 -> V_72 , & V_10 -> V_148 ) ;
return V_144 -> V_17 ;
}
static int F_55 ( struct V_149 * V_150 ,
struct V_1 * V_2 ,
struct V_151 * V_152 )
{
int V_78 ;
struct V_153 * V_154 = F_56 ( V_150 ) ;
struct V_10 * V_10 = F_57 ( V_154 ) ;
struct V_155 * V_156 = F_58 ( V_154 ) ;
struct V_11 * V_12 ;
struct V_64 * V_17 ;
struct V_157 * V_158 =
(struct V_157 * ) V_152 -> V_57 . V_159 ;
if ( ! V_152 -> V_57 . V_129 )
goto V_160;
V_12 = F_14 ( V_156 -> V_20 , sizeof( * V_12 ) , V_70 ) ;
if ( ! V_12 )
return - V_71 ;
V_2 -> V_57 = V_12 ;
V_12 -> V_3 . V_22 = V_158 -> V_22 ;
V_12 -> V_3 . V_23 = V_158 -> V_23 ;
V_12 -> V_24 = V_158 -> V_25 ;
V_12 -> V_54 = V_158 -> V_54 ;
V_12 -> V_56 = V_158 -> V_56 ;
V_12 -> V_161 = V_158 -> V_161 ;
V_12 -> V_162 = V_158 -> V_162 ;
V_12 -> V_163 = V_158 -> V_163 ;
V_12 -> V_164 = V_158 -> V_164 ;
V_12 -> V_27 . V_28 = V_158 -> V_27 . V_28 ;
V_12 -> V_27 . V_29 = V_158 -> V_27 . V_165 ;
V_12 -> V_27 . V_55 = V_158 -> V_27 . V_55 ;
V_12 -> V_27 . V_31 =
V_158 -> V_27 . V_31 ;
V_12 -> V_27 . V_30 = V_158 -> V_27 . V_30 ;
V_12 -> V_32 . V_28 = V_158 -> V_32 . V_28 ;
V_12 -> V_32 . V_29 = V_158 -> V_32 . V_165 ;
V_12 -> V_32 . V_55 = V_158 -> V_32 . V_55 ;
V_12 -> V_32 . V_31 =
V_158 -> V_32 . V_31 ;
V_12 -> V_32 . V_30 = V_158 -> V_32 . V_30 ;
V_12 -> V_49 = V_158 -> V_49 ;
V_12 -> V_50 = V_158 -> V_50 ;
V_12 -> V_52 = V_158 -> V_166 ;
V_12 -> V_126 = V_158 -> V_126 ;
V_17 = F_52 ( V_156 -> V_20 , V_10 , & V_158 -> V_17 ) ;
if ( V_17 )
V_12 -> V_17 = V_17 ;
V_12 -> V_114 = V_158 -> V_114 ;
V_12 -> V_167 = V_158 -> V_167 ;
V_12 -> V_168 = V_158 -> V_168 ;
V_12 -> V_127 . V_128 = V_158 -> V_130 . V_128 ;
V_12 -> V_169 = F_14 ( V_156 -> V_20 ,
( V_12 -> V_162 ) *
sizeof( * V_12 -> V_169 ) ,
V_70 ) ;
if ( ! V_12 -> V_169 )
return - V_71 ;
V_12 -> V_170 = F_14 ( V_156 -> V_20 , ( V_12 -> V_163 ) *
sizeof( * V_12 -> V_170 ) ,
V_70 ) ;
if ( ! V_12 -> V_170 )
return - V_71 ;
F_51 ( V_158 -> V_171 , V_12 -> V_169 ,
V_158 -> V_172 ,
V_12 -> V_162 ) ;
F_51 ( V_158 -> V_173 , V_12 -> V_170 ,
V_158 -> V_174 ,
V_12 -> V_163 ) ;
if ( V_12 -> V_127 . V_128 == 0 )
goto V_160;
V_12 -> V_127 . V_130 = ( V_131 * ) F_14 ( V_156 -> V_20 ,
V_12 -> V_127 . V_128 , V_70 ) ;
if ( V_12 -> V_127 . V_130 == NULL )
return - V_71 ;
memcpy ( V_12 -> V_127 . V_130 , V_158 -> V_130 . V_130 ,
V_158 -> V_130 . V_128 ) ;
V_160:
if ( V_152 -> V_175 == 0 ) {
F_8 ( V_156 -> V_20 , L_22 ) ;
return 0 ;
}
V_78 = F_59 ( V_2 , V_176 ,
F_60 ( V_176 ) ,
V_152 -> V_175 ) ;
if ( V_78 ) {
F_3 ( V_156 -> V_20 , L_23 ,
V_21 , V_152 -> V_175 ) ;
return - V_108 ;
}
return 0 ;
}
int F_61 ( struct V_177 * V_178 , struct V_153 * V_154 )
{
int V_78 ;
const struct V_179 * V_180 ;
struct V_155 * V_156 = F_58 ( V_154 ) ;
struct V_10 * V_10 = F_57 ( V_154 ) ;
V_78 = F_62 ( & V_180 , L_24 , V_156 -> V_20 ) ;
if ( V_78 < 0 ) {
F_3 ( V_156 -> V_20 , L_25 ,
L_24 , V_78 ) ;
return V_78 ;
}
V_78 = F_63 ( & V_178 -> V_181 ,
& V_182 , V_180 , 0 ) ;
if ( V_78 < 0 ) {
F_3 ( V_156 -> V_20 , L_26 , V_78 ) ;
return - V_108 ;
}
V_10 -> V_15 . V_25 = V_183 ;
V_10 -> V_15 . V_19 = V_184 ;
V_10 -> V_185 = V_180 ;
return 0 ;
}
