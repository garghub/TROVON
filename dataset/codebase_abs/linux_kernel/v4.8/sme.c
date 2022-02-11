static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return;
F_2 ( V_2 -> V_3 -> V_4 ) ;
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_8 * V_9 ;
int V_10 , V_11 ;
F_5 () ;
F_6 ( V_2 ) ;
if ( V_6 -> V_12 || V_6 -> V_13 )
return - V_14 ;
if ( V_2 -> V_3 -> V_15 . V_16 )
V_10 = 1 ;
else
V_10 = F_7 ( V_2 -> V_7 ) ;
V_9 = F_8 ( sizeof( * V_9 ) + sizeof( V_9 -> V_17 [ 0 ] ) +
sizeof( V_9 -> V_18 [ 0 ] ) * V_10 ,
V_19 ) ;
if ( ! V_9 )
return - V_20 ;
if ( V_2 -> V_3 -> V_15 . V_16 ) {
enum V_21 V_22 = V_2 -> V_3 -> V_15 . V_16 -> V_22 ;
struct V_23 * V_24 =
V_2 -> V_7 -> V_25 [ V_22 ] ;
if ( ! V_24 ) {
F_2 ( V_9 ) ;
return - V_26 ;
}
V_9 -> V_18 [ 0 ] = V_2 -> V_3 -> V_15 . V_16 ;
V_9 -> V_27 [ V_22 ] = ( 1 << V_24 -> V_28 ) - 1 ;
} else {
int V_29 = 0 , V_30 ;
enum V_21 V_22 ;
struct V_23 * V_25 ;
struct V_31 * V_16 ;
for ( V_22 = 0 ; V_22 < V_32 ; V_22 ++ ) {
V_25 = V_2 -> V_7 -> V_25 [ V_22 ] ;
if ( ! V_25 )
continue;
for ( V_30 = 0 ; V_30 < V_25 -> V_10 ; V_30 ++ ) {
V_16 = & V_25 -> V_18 [ V_30 ] ;
if ( V_16 -> V_33 & V_34 )
continue;
V_9 -> V_18 [ V_29 ++ ] = V_16 ;
}
V_9 -> V_27 [ V_22 ] = ( 1 << V_25 -> V_28 ) - 1 ;
}
V_10 = V_29 ;
}
V_9 -> V_10 = V_10 ;
V_9 -> V_17 = ( void * ) & V_9 -> V_18 [ V_10 ] ;
V_9 -> V_35 = 1 ;
memcpy ( V_9 -> V_17 [ 0 ] . V_36 , V_2 -> V_3 -> V_15 . V_36 ,
V_2 -> V_3 -> V_15 . V_37 ) ;
V_9 -> V_17 [ 0 ] . V_37 = V_2 -> V_3 -> V_15 . V_37 ;
F_9 ( V_9 -> V_38 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_7 = & V_6 -> V_7 ;
V_9 -> V_39 = V_40 ;
V_6 -> V_12 = V_9 ;
V_11 = F_10 ( V_6 , V_9 ) ;
if ( ! V_11 ) {
V_2 -> V_3 -> V_41 = V_42 ;
F_11 ( V_6 , V_2 ) ;
F_12 ( V_2 -> V_43 ) ;
} else {
V_6 -> V_12 = NULL ;
F_2 ( V_9 ) ;
}
return V_11 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_44 * V_15 ;
struct V_45 V_46 = {} ;
int V_11 ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 )
return 0 ;
V_15 = & V_2 -> V_3 -> V_15 ;
switch ( V_2 -> V_3 -> V_41 ) {
case V_42 :
return - V_47 ;
case V_48 :
return F_3 ( V_2 ) ;
case V_49 :
if ( F_14 ( ! V_6 -> V_50 -> V_51 ) )
return - V_52 ;
V_2 -> V_3 -> V_41 = V_53 ;
return F_15 ( V_6 , V_2 -> V_43 ,
V_15 -> V_16 , V_15 -> V_54 ,
V_15 -> V_38 ,
V_15 -> V_36 , V_15 -> V_37 ,
NULL , 0 ,
V_15 -> V_55 , V_15 -> V_56 ,
V_15 -> V_57 , NULL , 0 ) ;
case V_58 :
return - V_59 ;
case V_60 :
if ( F_14 ( ! V_6 -> V_50 -> V_61 ) )
return - V_52 ;
V_2 -> V_3 -> V_41 = V_62 ;
if ( V_2 -> V_3 -> V_63 )
V_46 . V_64 = V_2 -> V_3 -> V_64 ;
V_46 . V_4 = V_15 -> V_4 ;
V_46 . V_65 = V_15 -> V_65 ;
V_46 . V_66 = V_15 -> V_67 != V_68 ;
V_46 . V_69 = V_15 -> V_69 ;
V_46 . V_33 = V_15 -> V_33 ;
V_46 . V_70 = V_15 -> V_70 ;
V_46 . V_71 = V_15 -> V_71 ;
V_46 . V_72 = V_15 -> V_72 ;
V_46 . V_73 = V_15 -> V_73 ;
V_11 = F_16 ( V_6 , V_2 -> V_43 , V_15 -> V_16 ,
V_15 -> V_38 , V_15 -> V_36 ,
V_15 -> V_37 , & V_46 ) ;
if ( V_11 )
F_17 ( V_6 , V_2 -> V_43 , V_15 -> V_38 ,
NULL , 0 ,
V_74 ,
false ) ;
return V_11 ;
case V_75 :
F_17 ( V_6 , V_2 -> V_43 , V_15 -> V_38 ,
NULL , 0 ,
V_74 , false ) ;
return - V_59 ;
case V_76 :
F_17 ( V_6 , V_2 -> V_43 , V_15 -> V_38 ,
NULL , 0 ,
V_74 , false ) ;
F_1 ( V_2 ) ;
return 0 ;
default:
return 0 ;
}
}
void F_18 ( struct V_77 * V_78 )
{
struct V_5 * V_6 =
F_19 ( V_78 , struct V_5 , V_79 ) ;
struct V_1 * V_2 ;
T_1 V_80 [ V_81 ] , * V_38 = NULL ;
F_20 () ;
F_21 (wdev, &rdev->wiphy.wdev_list, list) {
if ( ! V_2 -> V_43 )
continue;
F_22 ( V_2 ) ;
if ( ! F_23 ( V_2 -> V_43 ) ) {
F_24 ( V_2 ) ;
continue;
}
if ( ! V_2 -> V_3 ||
V_2 -> V_3 -> V_41 == V_82 ) {
F_24 ( V_2 ) ;
continue;
}
if ( V_2 -> V_3 -> V_15 . V_38 ) {
memcpy ( V_80 , V_2 -> V_3 -> V_15 . V_38 , V_81 ) ;
V_38 = V_80 ;
}
if ( F_13 ( V_2 ) ) {
F_25 (
V_2 -> V_43 , V_38 ,
NULL , 0 , NULL , 0 , - 1 , false , NULL ) ;
}
F_24 ( V_2 ) ;
}
F_26 () ;
}
static struct V_83 * F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_83 * V_84 ;
F_6 ( V_2 ) ;
V_84 = F_28 ( V_2 -> V_7 , V_2 -> V_3 -> V_15 . V_16 ,
V_2 -> V_3 -> V_15 . V_38 ,
V_2 -> V_3 -> V_15 . V_36 ,
V_2 -> V_3 -> V_15 . V_37 ,
V_2 -> V_85 ,
F_29 ( V_2 -> V_3 -> V_15 . V_86 ) ) ;
if ( ! V_84 )
return NULL ;
memcpy ( V_2 -> V_3 -> V_38 , V_84 -> V_38 , V_81 ) ;
V_2 -> V_3 -> V_15 . V_38 = V_2 -> V_3 -> V_38 ;
V_2 -> V_3 -> V_15 . V_16 = V_84 -> V_16 ;
V_2 -> V_3 -> V_41 = V_49 ;
F_30 ( & V_6 -> V_79 ) ;
return V_84 ;
}
static void F_31 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_83 * V_84 ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 )
return;
if ( V_2 -> V_3 -> V_41 != V_42 &&
V_2 -> V_3 -> V_41 != V_48 )
return;
V_84 = F_27 ( V_2 ) ;
if ( V_84 )
F_32 ( & V_6 -> V_7 , V_84 ) ;
else
F_30 ( & V_6 -> V_79 ) ;
}
void F_33 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
F_22 ( V_2 ) ;
F_31 ( V_88 ) ;
F_24 ( V_2 ) ;
}
void F_34 ( struct V_1 * V_2 , const T_1 * V_90 , T_2 V_91 )
{
struct V_7 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_92 * V_93 = (struct V_92 * ) V_90 ;
T_3 V_94 = F_35 ( V_93 -> V_95 . V_51 . V_94 ) ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 || V_2 -> V_3 -> V_41 == V_82 )
return;
if ( V_94 == V_96 &&
V_2 -> V_3 -> V_97 &&
V_2 -> V_3 -> V_15 . V_54 != V_98 ) {
switch ( V_2 -> V_3 -> V_15 . V_54 ) {
case V_99 :
if ( V_2 -> V_100 )
V_2 -> V_3 -> V_15 . V_54 =
V_101 ;
else
V_2 -> V_3 -> V_15 . V_54 =
V_98 ;
break;
case V_101 :
V_2 -> V_3 -> V_15 . V_54 =
V_98 ;
break;
default:
V_2 -> V_3 -> V_15 . V_54 =
V_99 ;
break;
}
V_2 -> V_3 -> V_41 = V_49 ;
F_30 ( & V_6 -> V_79 ) ;
} else if ( V_94 != V_102 ) {
F_25 ( V_2 -> V_43 , V_93 -> V_38 ,
NULL , 0 , NULL , 0 ,
V_94 , false , NULL ) ;
} else if ( V_2 -> V_3 -> V_41 == V_53 ) {
V_2 -> V_3 -> V_41 = V_60 ;
F_30 ( & V_6 -> V_79 ) ;
}
}
bool F_36 ( struct V_1 * V_2 , T_3 V_103 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return false ;
if ( V_103 == V_102 ) {
V_2 -> V_3 -> V_41 = V_82 ;
return false ;
}
if ( V_2 -> V_3 -> V_63 ) {
V_2 -> V_3 -> V_63 = false ;
V_2 -> V_3 -> V_41 = V_60 ;
F_30 ( & V_6 -> V_79 ) ;
return true ;
}
V_2 -> V_3 -> V_41 = V_75 ;
F_30 ( & V_6 -> V_79 ) ;
return false ;
}
void F_37 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_41 = V_58 ;
F_30 ( & V_6 -> V_79 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_41 = V_76 ;
F_30 ( & V_6 -> V_79 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_41 = V_75 ;
F_30 ( & V_6 -> V_79 ) ;
}
static int F_41 ( struct V_1 * V_2 ,
const T_1 * V_104 , T_2 V_105 ,
const T_1 * * V_106 , T_2 * V_107 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
T_1 * V_90 ;
T_2 V_108 ;
if ( ! V_6 -> V_7 . V_109 ||
( V_104 && F_42 ( V_110 , V_104 , V_105 ) ) ) {
* V_106 = F_43 ( V_104 , V_105 , V_19 ) ;
if ( ! * V_106 )
return - V_20 ;
* V_107 = V_105 ;
return 0 ;
}
V_90 = F_44 ( V_105 + V_6 -> V_7 . V_109 + 2 ,
V_19 ) ;
if ( ! V_90 )
return - V_20 ;
if ( V_105 ) {
static const T_1 V_111 [] = {
V_112 ,
V_113 ,
V_114 ,
V_115 ,
V_116 ,
V_117 ,
} ;
V_108 = F_45 ( V_104 , V_105 , V_111 ,
F_46 ( V_111 ) , 0 ) ;
memcpy ( V_90 , V_104 , V_108 ) ;
memcpy ( V_90 + V_108 + V_6 -> V_7 . V_109 + 2 ,
V_104 + V_108 , V_105 - V_108 ) ;
} else {
V_108 = 0 ;
}
V_90 [ V_108 ] = V_110 ;
V_90 [ V_108 + 1 ] = V_6 -> V_7 . V_109 ;
memcpy ( V_90 + V_108 + 2 ,
V_6 -> V_7 . V_118 ,
V_6 -> V_7 . V_109 ) ;
* V_106 = V_90 ;
* V_107 = V_105 + V_6 -> V_7 . V_109 + 2 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_44 * V_119 ,
const T_1 * V_64 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_83 * V_84 ;
int V_11 ;
if ( ! V_6 -> V_50 -> V_51 || ! V_6 -> V_50 -> V_61 )
return - V_52 ;
if ( V_2 -> V_120 ) {
if ( ! V_64 )
return - V_121 ;
if ( V_64 &&
! F_48 ( V_64 , V_2 -> V_120 -> V_122 . V_38 ) )
return - V_59 ;
F_49 ( V_2 -> V_120 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_120 -> V_122 ) ;
V_2 -> V_120 = NULL ;
F_1 ( V_2 ) ;
}
if ( F_14 ( V_2 -> V_3 ) )
return - V_123 ;
V_2 -> V_3 = F_8 ( sizeof( * V_2 -> V_3 ) , V_19 ) ;
if ( ! V_2 -> V_3 )
return - V_20 ;
memcpy ( & V_2 -> V_3 -> V_15 , V_119 , sizeof( * V_119 ) ) ;
if ( V_119 -> V_38 ) {
V_2 -> V_3 -> V_15 . V_38 = V_2 -> V_3 -> V_38 ;
memcpy ( V_2 -> V_3 -> V_38 , V_119 -> V_38 , V_81 ) ;
}
if ( F_41 ( V_2 , V_119 -> V_4 , V_119 -> V_65 ,
& V_2 -> V_3 -> V_4 ,
& V_2 -> V_3 -> V_15 . V_65 ) ) {
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return - V_20 ;
}
V_2 -> V_3 -> V_15 . V_4 = V_2 -> V_3 -> V_4 ;
if ( V_119 -> V_54 == V_124 ) {
V_2 -> V_3 -> V_97 = true ;
V_2 -> V_3 -> V_15 . V_54 =
V_99 ;
} else {
V_2 -> V_3 -> V_97 = false ;
}
V_2 -> V_3 -> V_15 . V_36 = V_2 -> V_36 ;
V_2 -> V_3 -> V_15 . V_37 = V_2 -> V_37 ;
V_84 = F_27 ( V_2 ) ;
if ( V_64 ) {
memcpy ( V_2 -> V_3 -> V_64 , V_64 , V_81 ) ;
V_2 -> V_3 -> V_63 = true ;
}
if ( V_84 ) {
V_11 = F_13 ( V_2 ) ;
F_32 ( V_2 -> V_7 , V_84 ) ;
} else {
V_11 = F_3 ( V_2 ) ;
if ( V_11 == - V_14 ) {
V_11 = 0 ;
V_2 -> V_3 -> V_41 = V_48 ;
}
}
if ( V_11 )
F_1 ( V_2 ) ;
return V_11 ;
}
static int F_50 ( struct V_1 * V_2 , T_3 V_125 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_11 ;
if ( ! V_2 -> V_3 )
return 0 ;
if ( ! V_6 -> V_50 -> V_126 )
return - V_52 ;
if ( V_2 -> V_3 -> V_41 == V_42 ||
V_2 -> V_3 -> V_41 == V_48 ) {
V_11 = 0 ;
goto V_127;
}
V_11 = F_17 ( V_6 , V_2 -> V_43 ,
V_2 -> V_3 -> V_15 . V_38 ,
NULL , 0 , V_125 , false ) ;
V_127:
F_1 ( V_2 ) ;
return V_11 ;
}
static bool F_51 ( void )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
bool V_128 = true ;
F_21 (rdev, &cfg80211_rdev_list, list) {
F_21 (wdev, &rdev->wiphy.wdev_list, list) {
F_22 ( V_2 ) ;
if ( V_2 -> V_3 || V_2 -> V_120 )
V_128 = false ;
F_24 ( V_2 ) ;
}
}
return V_128 ;
}
static void F_52 ( struct V_77 * V_78 )
{
F_20 () ;
if ( F_51 () )
F_53 () ;
F_26 () ;
}
void F_25 ( struct V_87 * V_88 , const T_1 * V_38 ,
const T_1 * V_129 , T_2 V_130 ,
const T_1 * V_131 , T_2 V_132 ,
int V_103 , bool V_133 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
const T_1 * V_134 ;
#ifdef F_54
union V_135 V_136 ;
#endif
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_137 != V_138 &&
V_2 -> V_137 != V_139 ) ) {
F_32 ( V_2 -> V_7 , V_84 ) ;
return;
}
F_55 ( F_4 ( V_2 -> V_7 ) , V_88 ,
V_38 , V_129 , V_130 ,
V_131 , V_132 ,
V_103 , V_19 ) ;
#ifdef F_54
if ( V_133 ) {
if ( V_129 && V_103 == V_102 ) {
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_140 . V_141 = V_130 ;
F_56 ( V_88 , V_142 , & V_136 , V_129 ) ;
}
if ( V_131 && V_103 == V_102 ) {
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_140 . V_141 = V_132 ;
F_56 ( V_88 , V_143 , & V_136 , V_131 ) ;
}
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_144 . V_145 = V_146 ;
if ( V_38 && V_103 == V_102 ) {
memcpy ( V_136 . V_144 . V_147 , V_38 , V_81 ) ;
memcpy ( V_2 -> V_148 . V_64 , V_38 , V_81 ) ;
V_2 -> V_148 . V_63 = true ;
}
F_56 ( V_88 , V_149 , & V_136 , NULL ) ;
}
#endif
if ( ! V_84 && ( V_103 == V_102 ) ) {
F_57 ( ! F_4 ( V_2 -> V_7 ) -> V_50 -> V_119 ) ;
V_84 = F_28 ( V_2 -> V_7 , NULL , V_38 ,
V_2 -> V_36 , V_2 -> V_37 ,
V_2 -> V_85 ,
V_150 ) ;
if ( V_84 )
F_58 ( F_59 ( V_84 ) ) ;
}
if ( V_2 -> V_120 ) {
F_49 ( V_2 -> V_120 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_120 -> V_122 ) ;
V_2 -> V_120 = NULL ;
}
if ( V_103 != V_102 ) {
F_60 ( V_2 -> V_100 ) ;
V_2 -> V_100 = NULL ;
V_2 -> V_37 = 0 ;
if ( V_84 ) {
F_49 ( F_59 ( V_84 ) ) ;
F_32 ( V_2 -> V_7 , V_84 ) ;
}
F_1 ( V_2 ) ;
return;
}
if ( F_14 ( ! V_84 ) )
return;
V_2 -> V_120 = F_59 ( V_84 ) ;
F_61 ( V_2 ) ;
F_62 () ;
V_134 = F_63 ( V_84 , V_151 ) ;
if ( ! V_134 ) {
F_64 () ;
return;
}
V_134 = F_43 ( V_134 , 2 + V_134 [ 1 ] , V_152 ) ;
F_64 () ;
if ( ! V_134 )
return;
F_65 ( V_2 -> V_7 , V_84 -> V_16 -> V_22 ,
V_134 + 2 , V_134 [ 1 ] ) ;
F_2 ( V_134 ) ;
}
void F_66 ( struct V_87 * V_88 , const T_1 * V_38 ,
struct V_83 * V_84 , const T_1 * V_129 ,
T_2 V_130 , const T_1 * V_131 ,
T_2 V_132 , int V_103 , T_4 V_153 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_154 * V_155 ;
unsigned long V_33 ;
if ( V_84 ) {
struct V_156 * V_157 = F_59 ( V_84 ) ;
if ( F_14 ( F_67 ( & V_157 -> V_158 ) ) ) {
F_32 ( V_2 -> V_7 , V_84 ) ;
return;
}
}
V_155 = F_8 ( sizeof( * V_155 ) + V_130 + V_132 , V_153 ) ;
if ( ! V_155 ) {
F_32 ( V_2 -> V_7 , V_84 ) ;
return;
}
V_155 -> type = V_159 ;
if ( V_38 )
memcpy ( V_155 -> V_160 . V_38 , V_38 , V_81 ) ;
if ( V_130 ) {
V_155 -> V_160 . V_129 = ( ( T_1 * ) V_155 ) + sizeof( * V_155 ) ;
V_155 -> V_160 . V_130 = V_130 ;
memcpy ( ( void * ) V_155 -> V_160 . V_129 , V_129 , V_130 ) ;
}
if ( V_132 ) {
V_155 -> V_160 . V_131 = ( ( T_1 * ) V_155 ) + sizeof( * V_155 ) + V_130 ;
V_155 -> V_160 . V_132 = V_132 ;
memcpy ( ( void * ) V_155 -> V_160 . V_131 , V_131 , V_132 ) ;
}
if ( V_84 )
F_58 ( F_59 ( V_84 ) ) ;
V_155 -> V_160 . V_84 = V_84 ;
V_155 -> V_160 . V_103 = V_103 ;
F_68 ( & V_2 -> V_161 , V_33 ) ;
F_69 ( & V_155 -> V_158 , & V_2 -> V_162 ) ;
F_70 ( & V_2 -> V_161 , V_33 ) ;
F_71 ( V_163 , & V_6 -> V_164 ) ;
}
void F_72 ( struct V_1 * V_2 ,
struct V_83 * V_84 ,
const T_1 * V_129 , T_2 V_130 ,
const T_1 * V_131 , T_2 V_132 )
{
#ifdef F_54
union V_135 V_136 ;
#endif
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_137 != V_138 &&
V_2 -> V_137 != V_139 ) )
goto V_127;
if ( F_14 ( ! V_2 -> V_120 ) )
goto V_127;
F_49 ( V_2 -> V_120 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_120 -> V_122 ) ;
V_2 -> V_120 = NULL ;
F_58 ( F_59 ( V_84 ) ) ;
V_2 -> V_120 = F_59 ( V_84 ) ;
F_73 ( F_4 ( V_2 -> V_7 ) ,
V_2 -> V_43 , V_84 -> V_38 ,
V_129 , V_130 , V_131 , V_132 ,
V_19 ) ;
#ifdef F_54
if ( V_129 ) {
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_140 . V_141 = V_130 ;
F_56 ( V_2 -> V_43 , V_142 ,
& V_136 , V_129 ) ;
}
if ( V_131 ) {
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_140 . V_141 = V_132 ;
F_56 ( V_2 -> V_43 , V_143 ,
& V_136 , V_131 ) ;
}
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_144 . V_145 = V_146 ;
memcpy ( V_136 . V_144 . V_147 , V_84 -> V_38 , V_81 ) ;
memcpy ( V_2 -> V_148 . V_64 , V_84 -> V_38 , V_81 ) ;
V_2 -> V_148 . V_63 = true ;
F_56 ( V_2 -> V_43 , V_149 , & V_136 , NULL ) ;
#endif
return;
V_127:
F_32 ( V_2 -> V_7 , V_84 ) ;
}
void F_74 ( struct V_87 * V_88 ,
struct V_31 * V_16 ,
const T_1 * V_38 ,
const T_1 * V_129 , T_2 V_130 ,
const T_1 * V_131 , T_2 V_132 , T_4 V_153 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
struct V_83 * V_84 ;
V_84 = F_28 ( V_2 -> V_7 , V_16 , V_38 , V_2 -> V_36 ,
V_2 -> V_37 ,
V_2 -> V_85 , V_150 ) ;
if ( F_14 ( ! V_84 ) )
return;
F_75 ( V_88 , V_84 , V_129 , V_130 , V_131 ,
V_132 , V_153 ) ;
}
void F_75 ( struct V_87 * V_88 ,
struct V_83 * V_84 , const T_1 * V_129 ,
T_2 V_130 , const T_1 * V_131 ,
T_2 V_132 , T_4 V_153 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_154 * V_155 ;
unsigned long V_33 ;
if ( F_14 ( ! V_84 ) )
return;
V_155 = F_8 ( sizeof( * V_155 ) + V_130 + V_132 , V_153 ) ;
if ( ! V_155 ) {
F_32 ( V_2 -> V_7 , V_84 ) ;
return;
}
V_155 -> type = V_165 ;
V_155 -> V_166 . V_129 = ( ( T_1 * ) V_155 ) + sizeof( * V_155 ) ;
V_155 -> V_166 . V_130 = V_130 ;
memcpy ( ( void * ) V_155 -> V_166 . V_129 , V_129 , V_130 ) ;
V_155 -> V_166 . V_131 = ( ( T_1 * ) V_155 ) + sizeof( * V_155 ) + V_130 ;
V_155 -> V_166 . V_132 = V_132 ;
memcpy ( ( void * ) V_155 -> V_166 . V_131 , V_131 , V_132 ) ;
V_155 -> V_166 . V_84 = V_84 ;
F_68 ( & V_2 -> V_161 , V_33 ) ;
F_69 ( & V_155 -> V_158 , & V_2 -> V_162 ) ;
F_70 ( & V_2 -> V_161 , V_33 ) ;
F_71 ( V_163 , & V_6 -> V_164 ) ;
}
void F_76 ( struct V_87 * V_88 , const T_1 * V_4 ,
T_2 V_65 , T_3 V_125 , bool V_167 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_29 ;
#ifdef F_54
union V_135 V_136 ;
#endif
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_137 != V_138 &&
V_2 -> V_137 != V_139 ) )
return;
if ( V_2 -> V_120 ) {
F_49 ( V_2 -> V_120 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_120 -> V_122 ) ;
}
V_2 -> V_120 = NULL ;
V_2 -> V_37 = 0 ;
F_77 ( V_6 , V_88 , V_125 , V_4 , V_65 , V_167 ) ;
if ( V_6 -> V_50 -> V_168 && V_6 -> V_169 ) {
V_6 -> V_169 = 0 ;
F_78 ( V_6 , V_2 ) ;
}
if ( V_6 -> V_50 -> V_170 )
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
F_79 ( V_6 , V_88 , V_29 , false , NULL ) ;
F_80 ( V_6 , V_88 , NULL ) ;
#ifdef F_54
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_144 . V_145 = V_146 ;
F_56 ( V_88 , V_149 , & V_136 , NULL ) ;
V_2 -> V_148 . V_119 . V_37 = 0 ;
#endif
F_30 ( & V_171 ) ;
}
void F_81 ( struct V_87 * V_88 , T_3 V_125 ,
const T_1 * V_4 , T_2 V_65 ,
bool V_172 , T_4 V_153 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_154 * V_155 ;
unsigned long V_33 ;
V_155 = F_8 ( sizeof( * V_155 ) + V_65 , V_153 ) ;
if ( ! V_155 )
return;
V_155 -> type = V_173 ;
V_155 -> V_174 . V_4 = ( ( T_1 * ) V_155 ) + sizeof( * V_155 ) ;
V_155 -> V_174 . V_65 = V_65 ;
memcpy ( ( void * ) V_155 -> V_174 . V_4 , V_4 , V_65 ) ;
V_155 -> V_174 . V_125 = V_125 ;
V_155 -> V_174 . V_172 = V_172 ;
F_68 ( & V_2 -> V_161 , V_33 ) ;
F_69 ( & V_155 -> V_158 , & V_2 -> V_162 ) ;
F_70 ( & V_2 -> V_161 , V_33 ) ;
F_71 ( V_163 , & V_6 -> V_164 ) ;
}
int F_82 ( struct V_5 * V_6 ,
struct V_87 * V_88 ,
struct V_44 * V_119 ,
struct V_175 * V_176 ,
const T_1 * V_64 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
int V_11 ;
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_100 ) ) {
F_60 ( V_2 -> V_100 ) ;
V_2 -> V_100 = NULL ;
}
F_83 ( & V_119 -> V_71 ,
V_6 -> V_7 . V_177 ) ;
if ( V_176 && V_176 -> V_178 >= 0 ) {
int V_179 ;
T_5 V_180 ;
V_179 = V_176 -> V_178 ;
V_180 = V_176 -> V_15 [ V_179 ] . V_180 ;
if ( V_180 == V_181 ||
V_180 == V_182 ) {
V_119 -> V_57 = V_179 ;
V_119 -> V_55 = V_176 -> V_15 [ V_179 ] . V_55 ;
V_119 -> V_56 = V_176 -> V_15 [ V_179 ] . V_56 ;
if ( V_119 -> V_69 . V_183 == 0 )
V_119 -> V_69 . V_183 = V_180 ;
if ( V_119 -> V_69 . V_184 == 0 ) {
V_119 -> V_69 . V_184 = 1 ;
V_119 -> V_69 . V_185 [ 0 ] = V_180 ;
}
}
}
V_2 -> V_100 = V_176 ;
memcpy ( V_2 -> V_36 , V_119 -> V_36 , V_119 -> V_37 ) ;
V_2 -> V_37 = V_119 -> V_37 ;
V_2 -> V_85 = V_119 -> V_186 ? V_187 :
V_188 ;
if ( ! V_6 -> V_50 -> V_119 )
V_11 = F_47 ( V_2 , V_119 , V_64 ) ;
else
V_11 = F_84 ( V_6 , V_88 , V_119 ) ;
if ( V_11 ) {
V_2 -> V_100 = NULL ;
V_2 -> V_37 = 0 ;
return V_11 ;
}
return 0 ;
}
int F_85 ( struct V_5 * V_6 ,
struct V_87 * V_88 , T_3 V_125 , bool V_133 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
int V_11 = 0 ;
F_6 ( V_2 ) ;
F_60 ( V_2 -> V_100 ) ;
V_2 -> V_100 = NULL ;
if ( V_2 -> V_3 )
V_11 = F_50 ( V_2 , V_125 ) ;
else if ( ! V_6 -> V_50 -> V_189 )
F_86 ( V_6 , V_88 ) ;
else if ( V_2 -> V_120 )
V_11 = F_87 ( V_6 , V_88 , V_125 ) ;
return V_11 ;
}
