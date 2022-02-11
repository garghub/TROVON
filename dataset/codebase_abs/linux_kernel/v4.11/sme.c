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
static int F_13 ( struct V_1 * V_2 ,
enum V_44 * V_45 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_46 * V_15 ;
struct V_47 V_48 = {} ;
int V_11 ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 )
return 0 ;
V_15 = & V_2 -> V_3 -> V_15 ;
switch ( V_2 -> V_3 -> V_41 ) {
case V_42 :
return - V_49 ;
case V_50 :
return F_3 ( V_2 ) ;
case V_51 :
if ( F_14 ( ! V_6 -> V_52 -> V_53 ) )
return - V_54 ;
V_2 -> V_3 -> V_41 = V_55 ;
return F_15 ( V_6 , V_2 -> V_43 ,
V_15 -> V_16 , V_15 -> V_56 ,
V_15 -> V_38 ,
V_15 -> V_36 , V_15 -> V_37 ,
NULL , 0 ,
V_15 -> V_57 , V_15 -> V_58 ,
V_15 -> V_59 , NULL , 0 ) ;
case V_60 :
* V_45 = V_61 ;
return - V_62 ;
case V_63 :
if ( F_14 ( ! V_6 -> V_52 -> V_64 ) )
return - V_54 ;
V_2 -> V_3 -> V_41 = V_65 ;
if ( V_2 -> V_3 -> V_66 )
V_48 . V_67 = V_2 -> V_3 -> V_67 ;
V_48 . V_4 = V_15 -> V_4 ;
V_48 . V_68 = V_15 -> V_68 ;
V_48 . V_69 = V_15 -> V_70 != V_71 ;
V_48 . V_72 = V_15 -> V_72 ;
V_48 . V_33 = V_15 -> V_33 ;
V_48 . V_73 = V_15 -> V_73 ;
V_48 . V_74 = V_15 -> V_74 ;
V_48 . V_75 = V_15 -> V_75 ;
V_48 . V_76 = V_15 -> V_76 ;
V_11 = F_16 ( V_6 , V_2 -> V_43 , V_15 -> V_16 ,
V_15 -> V_38 , V_15 -> V_36 ,
V_15 -> V_37 , & V_48 ) ;
if ( V_11 )
F_17 ( V_6 , V_2 -> V_43 , V_15 -> V_38 ,
NULL , 0 ,
V_77 ,
false ) ;
return V_11 ;
case V_78 :
* V_45 = V_79 ;
case V_80 :
F_17 ( V_6 , V_2 -> V_43 , V_15 -> V_38 ,
NULL , 0 ,
V_77 , false ) ;
return - V_62 ;
case V_81 :
F_17 ( V_6 , V_2 -> V_43 , V_15 -> V_38 ,
NULL , 0 ,
V_77 , false ) ;
case V_82 :
F_1 ( V_2 ) ;
return 0 ;
default:
return 0 ;
}
}
void F_18 ( struct V_83 * V_84 )
{
struct V_5 * V_6 =
F_19 ( V_84 , struct V_5 , V_85 ) ;
struct V_1 * V_2 ;
T_1 V_86 [ V_87 ] , * V_38 = NULL ;
enum V_44 V_45 ;
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
V_2 -> V_3 -> V_41 == V_88 ) {
F_24 ( V_2 ) ;
continue;
}
if ( V_2 -> V_3 -> V_15 . V_38 ) {
memcpy ( V_86 , V_2 -> V_3 -> V_15 . V_38 , V_87 ) ;
V_38 = V_86 ;
}
V_45 = V_89 ;
if ( F_13 ( V_2 , & V_45 ) ) {
F_25 (
V_2 -> V_43 , V_38 ,
NULL , 0 , NULL , 0 , - 1 , false , NULL ,
V_45 ) ;
}
F_24 ( V_2 ) ;
}
F_26 () ;
}
static struct V_90 * F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_90 * V_91 ;
F_6 ( V_2 ) ;
V_91 = F_28 ( V_2 -> V_7 , V_2 -> V_3 -> V_15 . V_16 ,
V_2 -> V_3 -> V_15 . V_38 ,
V_2 -> V_3 -> V_15 . V_36 ,
V_2 -> V_3 -> V_15 . V_37 ,
V_2 -> V_92 ,
F_29 ( V_2 -> V_3 -> V_15 . V_93 ) ) ;
if ( ! V_91 )
return NULL ;
memcpy ( V_2 -> V_3 -> V_38 , V_91 -> V_38 , V_87 ) ;
V_2 -> V_3 -> V_15 . V_38 = V_2 -> V_3 -> V_38 ;
V_2 -> V_3 -> V_15 . V_16 = V_91 -> V_16 ;
V_2 -> V_3 -> V_41 = V_51 ;
F_30 ( & V_6 -> V_85 ) ;
return V_91 ;
}
static void F_31 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_96 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_90 * V_91 ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 )
return;
if ( V_2 -> V_3 -> V_41 != V_42 &&
V_2 -> V_3 -> V_41 != V_50 )
return;
V_91 = F_27 ( V_2 ) ;
if ( V_91 )
F_32 ( & V_6 -> V_7 , V_91 ) ;
else
F_30 ( & V_6 -> V_85 ) ;
}
void F_33 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_96 ;
F_22 ( V_2 ) ;
F_31 ( V_95 ) ;
F_24 ( V_2 ) ;
}
void F_34 ( struct V_1 * V_2 , const T_1 * V_97 , T_2 V_98 )
{
struct V_7 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_99 * V_100 = (struct V_99 * ) V_97 ;
T_3 V_101 = F_35 ( V_100 -> V_102 . V_53 . V_101 ) ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 || V_2 -> V_3 -> V_41 == V_88 )
return;
if ( V_101 == V_103 &&
V_2 -> V_3 -> V_104 &&
V_2 -> V_3 -> V_15 . V_56 != V_105 ) {
switch ( V_2 -> V_3 -> V_15 . V_56 ) {
case V_106 :
if ( V_2 -> V_107 )
V_2 -> V_3 -> V_15 . V_56 =
V_108 ;
else
V_2 -> V_3 -> V_15 . V_56 =
V_105 ;
break;
case V_108 :
V_2 -> V_3 -> V_15 . V_56 =
V_105 ;
break;
default:
V_2 -> V_3 -> V_15 . V_56 =
V_106 ;
break;
}
V_2 -> V_3 -> V_41 = V_51 ;
F_30 ( & V_6 -> V_85 ) ;
} else if ( V_101 != V_109 ) {
F_25 ( V_2 -> V_43 , V_100 -> V_38 ,
NULL , 0 , NULL , 0 ,
V_101 , false , NULL ,
V_89 ) ;
} else if ( V_2 -> V_3 -> V_41 == V_55 ) {
V_2 -> V_3 -> V_41 = V_63 ;
F_30 ( & V_6 -> V_85 ) ;
}
}
bool F_36 ( struct V_1 * V_2 , T_3 V_110 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return false ;
if ( V_110 == V_109 ) {
V_2 -> V_3 -> V_41 = V_88 ;
return false ;
}
if ( V_2 -> V_3 -> V_66 ) {
V_2 -> V_3 -> V_66 = false ;
V_2 -> V_3 -> V_41 = V_63 ;
F_30 ( & V_6 -> V_85 ) ;
return true ;
}
V_2 -> V_3 -> V_41 = V_80 ;
F_30 ( & V_6 -> V_85 ) ;
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
V_2 -> V_3 -> V_41 = V_60 ;
F_30 ( & V_6 -> V_85 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_41 = V_81 ;
F_30 ( & V_6 -> V_85 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_41 = V_78 ;
F_30 ( & V_6 -> V_85 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_41 = V_82 ;
F_30 ( & V_6 -> V_85 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
const T_1 * V_111 , T_2 V_112 ,
const T_1 * * V_113 , T_2 * V_114 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
T_1 * V_97 ;
T_2 V_115 ;
if ( ! V_6 -> V_7 . V_116 ||
( V_111 && F_43 ( V_117 , V_111 , V_112 ) ) ) {
* V_113 = F_44 ( V_111 , V_112 , V_19 ) ;
if ( ! * V_113 )
return - V_20 ;
* V_114 = V_112 ;
return 0 ;
}
V_97 = F_45 ( V_112 + V_6 -> V_7 . V_116 + 2 ,
V_19 ) ;
if ( ! V_97 )
return - V_20 ;
if ( V_112 ) {
static const T_1 V_118 [] = {
V_119 ,
V_120 ,
V_121 ,
V_122 ,
V_123 ,
V_124 ,
} ;
V_115 = F_46 ( V_111 , V_112 , V_118 ,
F_47 ( V_118 ) , 0 ) ;
memcpy ( V_97 , V_111 , V_115 ) ;
memcpy ( V_97 + V_115 + V_6 -> V_7 . V_116 + 2 ,
V_111 + V_115 , V_112 - V_115 ) ;
} else {
V_115 = 0 ;
}
V_97 [ V_115 ] = V_117 ;
V_97 [ V_115 + 1 ] = V_6 -> V_7 . V_116 ;
memcpy ( V_97 + V_115 + 2 ,
V_6 -> V_7 . V_125 ,
V_6 -> V_7 . V_116 ) ;
* V_113 = V_97 ;
* V_114 = V_112 + V_6 -> V_7 . V_116 + 2 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_46 * V_126 ,
const T_1 * V_67 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_90 * V_91 ;
int V_11 ;
if ( ! V_6 -> V_52 -> V_53 || ! V_6 -> V_52 -> V_64 )
return - V_54 ;
if ( V_2 -> V_127 ) {
if ( ! V_67 )
return - V_128 ;
if ( V_67 &&
! F_49 ( V_67 , V_2 -> V_127 -> V_129 . V_38 ) )
return - V_62 ;
F_50 ( V_2 -> V_127 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_127 -> V_129 ) ;
V_2 -> V_127 = NULL ;
F_1 ( V_2 ) ;
}
if ( F_14 ( V_2 -> V_3 ) )
return - V_130 ;
V_2 -> V_3 = F_8 ( sizeof( * V_2 -> V_3 ) , V_19 ) ;
if ( ! V_2 -> V_3 )
return - V_20 ;
memcpy ( & V_2 -> V_3 -> V_15 , V_126 , sizeof( * V_126 ) ) ;
if ( V_126 -> V_38 ) {
V_2 -> V_3 -> V_15 . V_38 = V_2 -> V_3 -> V_38 ;
memcpy ( V_2 -> V_3 -> V_38 , V_126 -> V_38 , V_87 ) ;
}
if ( F_42 ( V_2 , V_126 -> V_4 , V_126 -> V_68 ,
& V_2 -> V_3 -> V_4 ,
& V_2 -> V_3 -> V_15 . V_68 ) ) {
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return - V_20 ;
}
V_2 -> V_3 -> V_15 . V_4 = V_2 -> V_3 -> V_4 ;
if ( V_126 -> V_56 == V_131 ) {
V_2 -> V_3 -> V_104 = true ;
V_2 -> V_3 -> V_15 . V_56 =
V_106 ;
} else {
V_2 -> V_3 -> V_104 = false ;
}
V_2 -> V_3 -> V_15 . V_36 = V_2 -> V_36 ;
V_2 -> V_3 -> V_15 . V_37 = V_2 -> V_37 ;
V_91 = F_27 ( V_2 ) ;
if ( V_67 ) {
memcpy ( V_2 -> V_3 -> V_67 , V_67 , V_87 ) ;
V_2 -> V_3 -> V_66 = true ;
}
if ( V_91 ) {
enum V_44 V_45 ;
V_11 = F_13 ( V_2 , & V_45 ) ;
F_32 ( V_2 -> V_7 , V_91 ) ;
} else {
V_11 = F_3 ( V_2 ) ;
if ( V_11 == - V_14 ) {
V_11 = 0 ;
V_2 -> V_3 -> V_41 = V_50 ;
}
}
if ( V_11 )
F_1 ( V_2 ) ;
return V_11 ;
}
static int F_51 ( struct V_1 * V_2 , T_3 V_132 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_11 ;
if ( ! V_2 -> V_3 )
return 0 ;
if ( ! V_6 -> V_52 -> V_133 )
return - V_54 ;
if ( V_2 -> V_3 -> V_41 == V_42 ||
V_2 -> V_3 -> V_41 == V_50 ) {
V_11 = 0 ;
goto V_134;
}
V_11 = F_17 ( V_6 , V_2 -> V_43 ,
V_2 -> V_3 -> V_15 . V_38 ,
NULL , 0 , V_132 , false ) ;
V_134:
F_1 ( V_2 ) ;
return V_11 ;
}
static bool F_52 ( void )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
bool V_135 = true ;
F_21 (rdev, &cfg80211_rdev_list, list) {
F_21 (wdev, &rdev->wiphy.wdev_list, list) {
F_22 ( V_2 ) ;
if ( V_2 -> V_3 || V_2 -> V_127 )
V_135 = false ;
F_24 ( V_2 ) ;
}
}
return V_135 ;
}
static void F_53 ( struct V_83 * V_84 )
{
F_20 () ;
if ( F_52 () )
F_54 () ;
F_26 () ;
}
void F_25 ( struct V_94 * V_95 , const T_1 * V_38 ,
const T_1 * V_136 , T_2 V_137 ,
const T_1 * V_138 , T_2 V_139 ,
int V_110 , bool V_140 ,
struct V_90 * V_91 ,
enum V_44 V_141 )
{
struct V_1 * V_2 = V_95 -> V_96 ;
const T_1 * V_142 ;
#ifdef F_55
union V_143 V_144 ;
#endif
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_145 != V_146 &&
V_2 -> V_145 != V_147 ) ) {
F_32 ( V_2 -> V_7 , V_91 ) ;
return;
}
F_56 ( F_4 ( V_2 -> V_7 ) , V_95 ,
V_38 , V_136 , V_137 ,
V_138 , V_139 ,
V_110 , V_141 , V_19 ) ;
#ifdef F_55
if ( V_140 ) {
if ( V_136 && V_110 == V_109 ) {
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_144 . V_148 . V_149 = V_137 ;
F_57 ( V_95 , V_150 , & V_144 , V_136 ) ;
}
if ( V_138 && V_110 == V_109 ) {
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_144 . V_148 . V_149 = V_139 ;
F_57 ( V_95 , V_151 , & V_144 , V_138 ) ;
}
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_144 . V_152 . V_153 = V_154 ;
if ( V_38 && V_110 == V_109 ) {
memcpy ( V_144 . V_152 . V_155 , V_38 , V_87 ) ;
memcpy ( V_2 -> V_156 . V_67 , V_38 , V_87 ) ;
V_2 -> V_156 . V_66 = true ;
}
F_57 ( V_95 , V_157 , & V_144 , NULL ) ;
}
#endif
if ( ! V_91 && ( V_110 == V_109 ) ) {
F_58 ( ! F_4 ( V_2 -> V_7 ) -> V_52 -> V_126 ) ;
V_91 = F_28 ( V_2 -> V_7 , NULL , V_38 ,
V_2 -> V_36 , V_2 -> V_37 ,
V_2 -> V_92 ,
V_158 ) ;
if ( V_91 )
F_59 ( F_60 ( V_91 ) ) ;
}
if ( V_2 -> V_127 ) {
F_50 ( V_2 -> V_127 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_127 -> V_129 ) ;
V_2 -> V_127 = NULL ;
}
if ( V_110 != V_109 ) {
F_61 ( V_2 -> V_107 ) ;
V_2 -> V_107 = NULL ;
V_2 -> V_37 = 0 ;
V_2 -> V_159 = 0 ;
if ( V_91 ) {
F_50 ( F_60 ( V_91 ) ) ;
F_32 ( V_2 -> V_7 , V_91 ) ;
}
F_1 ( V_2 ) ;
return;
}
if ( F_14 ( ! V_91 ) )
return;
V_2 -> V_127 = F_60 ( V_91 ) ;
if ( ! ( V_2 -> V_7 -> V_33 & V_160 ) )
F_62 ( V_2 ) ;
F_63 () ;
V_142 = F_64 ( V_91 , V_161 ) ;
if ( ! V_142 ) {
F_65 () ;
return;
}
V_142 = F_44 ( V_142 , 2 + V_142 [ 1 ] , V_162 ) ;
F_65 () ;
if ( ! V_142 )
return;
F_66 ( V_2 -> V_7 , V_91 -> V_16 -> V_22 ,
V_142 + 2 , V_142 [ 1 ] ) ;
F_2 ( V_142 ) ;
}
void F_67 ( struct V_94 * V_95 , const T_1 * V_38 ,
struct V_90 * V_91 , const T_1 * V_136 ,
T_2 V_137 , const T_1 * V_138 ,
T_2 V_139 , int V_110 , T_4 V_163 ,
enum V_44 V_141 )
{
struct V_1 * V_2 = V_95 -> V_96 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_164 * V_165 ;
unsigned long V_33 ;
if ( V_91 ) {
struct V_166 * V_167 = F_60 ( V_91 ) ;
if ( F_14 ( F_68 ( & V_167 -> V_168 ) ) ) {
F_32 ( V_2 -> V_7 , V_91 ) ;
return;
}
}
V_165 = F_8 ( sizeof( * V_165 ) + V_137 + V_139 , V_163 ) ;
if ( ! V_165 ) {
F_32 ( V_2 -> V_7 , V_91 ) ;
return;
}
V_165 -> type = V_169 ;
if ( V_38 )
memcpy ( V_165 -> V_170 . V_38 , V_38 , V_87 ) ;
if ( V_137 ) {
V_165 -> V_170 . V_136 = ( ( T_1 * ) V_165 ) + sizeof( * V_165 ) ;
V_165 -> V_170 . V_137 = V_137 ;
memcpy ( ( void * ) V_165 -> V_170 . V_136 , V_136 , V_137 ) ;
}
if ( V_139 ) {
V_165 -> V_170 . V_138 = ( ( T_1 * ) V_165 ) + sizeof( * V_165 ) + V_137 ;
V_165 -> V_170 . V_139 = V_139 ;
memcpy ( ( void * ) V_165 -> V_170 . V_138 , V_138 , V_139 ) ;
}
if ( V_91 )
F_59 ( F_60 ( V_91 ) ) ;
V_165 -> V_170 . V_91 = V_91 ;
V_165 -> V_170 . V_110 = V_110 ;
V_165 -> V_170 . V_141 = V_141 ;
F_69 ( & V_2 -> V_171 , V_33 ) ;
F_70 ( & V_165 -> V_168 , & V_2 -> V_172 ) ;
F_71 ( & V_2 -> V_171 , V_33 ) ;
F_72 ( V_173 , & V_6 -> V_174 ) ;
}
void F_73 ( struct V_1 * V_2 ,
struct V_90 * V_91 ,
const T_1 * V_136 , T_2 V_137 ,
const T_1 * V_138 , T_2 V_139 )
{
#ifdef F_55
union V_143 V_144 ;
#endif
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_145 != V_146 &&
V_2 -> V_145 != V_147 ) )
goto V_134;
if ( F_14 ( ! V_2 -> V_127 ) )
goto V_134;
F_50 ( V_2 -> V_127 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_127 -> V_129 ) ;
V_2 -> V_127 = NULL ;
F_59 ( F_60 ( V_91 ) ) ;
V_2 -> V_127 = F_60 ( V_91 ) ;
F_74 ( F_4 ( V_2 -> V_7 ) ,
V_2 -> V_43 , V_91 -> V_38 ,
V_136 , V_137 , V_138 , V_139 ,
V_19 ) ;
#ifdef F_55
if ( V_136 ) {
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_144 . V_148 . V_149 = V_137 ;
F_57 ( V_2 -> V_43 , V_150 ,
& V_144 , V_136 ) ;
}
if ( V_138 ) {
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_144 . V_148 . V_149 = V_139 ;
F_57 ( V_2 -> V_43 , V_151 ,
& V_144 , V_138 ) ;
}
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_144 . V_152 . V_153 = V_154 ;
memcpy ( V_144 . V_152 . V_155 , V_91 -> V_38 , V_87 ) ;
memcpy ( V_2 -> V_156 . V_67 , V_91 -> V_38 , V_87 ) ;
V_2 -> V_156 . V_66 = true ;
F_57 ( V_2 -> V_43 , V_157 , & V_144 , NULL ) ;
#endif
return;
V_134:
F_32 ( V_2 -> V_7 , V_91 ) ;
}
void F_75 ( struct V_94 * V_95 ,
struct V_31 * V_16 ,
const T_1 * V_38 ,
const T_1 * V_136 , T_2 V_137 ,
const T_1 * V_138 , T_2 V_139 , T_4 V_163 )
{
struct V_1 * V_2 = V_95 -> V_96 ;
struct V_90 * V_91 ;
V_91 = F_28 ( V_2 -> V_7 , V_16 , V_38 , V_2 -> V_36 ,
V_2 -> V_37 ,
V_2 -> V_92 , V_158 ) ;
if ( F_14 ( ! V_91 ) )
return;
F_76 ( V_95 , V_91 , V_136 , V_137 , V_138 ,
V_139 , V_163 ) ;
}
void F_76 ( struct V_94 * V_95 ,
struct V_90 * V_91 , const T_1 * V_136 ,
T_2 V_137 , const T_1 * V_138 ,
T_2 V_139 , T_4 V_163 )
{
struct V_1 * V_2 = V_95 -> V_96 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_164 * V_165 ;
unsigned long V_33 ;
if ( F_14 ( ! V_91 ) )
return;
V_165 = F_8 ( sizeof( * V_165 ) + V_137 + V_139 , V_163 ) ;
if ( ! V_165 ) {
F_32 ( V_2 -> V_7 , V_91 ) ;
return;
}
V_165 -> type = V_175 ;
V_165 -> V_176 . V_136 = ( ( T_1 * ) V_165 ) + sizeof( * V_165 ) ;
V_165 -> V_176 . V_137 = V_137 ;
memcpy ( ( void * ) V_165 -> V_176 . V_136 , V_136 , V_137 ) ;
V_165 -> V_176 . V_138 = ( ( T_1 * ) V_165 ) + sizeof( * V_165 ) + V_137 ;
V_165 -> V_176 . V_139 = V_139 ;
memcpy ( ( void * ) V_165 -> V_176 . V_138 , V_138 , V_139 ) ;
V_165 -> V_176 . V_91 = V_91 ;
F_69 ( & V_2 -> V_171 , V_33 ) ;
F_70 ( & V_165 -> V_168 , & V_2 -> V_172 ) ;
F_71 ( & V_2 -> V_171 , V_33 ) ;
F_72 ( V_173 , & V_6 -> V_174 ) ;
}
void F_77 ( struct V_94 * V_95 , const T_1 * V_4 ,
T_2 V_68 , T_3 V_132 , bool V_177 )
{
struct V_1 * V_2 = V_95 -> V_96 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_29 ;
#ifdef F_55
union V_143 V_144 ;
#endif
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_145 != V_146 &&
V_2 -> V_145 != V_147 ) )
return;
if ( V_2 -> V_127 ) {
F_50 ( V_2 -> V_127 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_127 -> V_129 ) ;
}
V_2 -> V_127 = NULL ;
V_2 -> V_37 = 0 ;
V_2 -> V_159 = 0 ;
F_78 ( V_6 , V_95 , V_132 , V_4 , V_68 , V_177 ) ;
if ( V_6 -> V_52 -> V_178 && V_6 -> V_179 ) {
V_6 -> V_179 = 0 ;
F_79 ( V_6 , V_2 ) ;
}
if ( V_6 -> V_52 -> V_180 )
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
F_80 ( V_6 , V_95 , V_29 , false , NULL ) ;
F_81 ( V_6 , V_95 , NULL ) ;
#ifdef F_55
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_144 . V_152 . V_153 = V_154 ;
F_57 ( V_95 , V_157 , & V_144 , NULL ) ;
V_2 -> V_156 . V_126 . V_37 = 0 ;
#endif
F_30 ( & V_181 ) ;
}
void F_82 ( struct V_94 * V_95 , T_3 V_132 ,
const T_1 * V_4 , T_2 V_68 ,
bool V_182 , T_4 V_163 )
{
struct V_1 * V_2 = V_95 -> V_96 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_164 * V_165 ;
unsigned long V_33 ;
V_165 = F_8 ( sizeof( * V_165 ) + V_68 , V_163 ) ;
if ( ! V_165 )
return;
V_165 -> type = V_183 ;
V_165 -> V_184 . V_4 = ( ( T_1 * ) V_165 ) + sizeof( * V_165 ) ;
V_165 -> V_184 . V_68 = V_68 ;
memcpy ( ( void * ) V_165 -> V_184 . V_4 , V_4 , V_68 ) ;
V_165 -> V_184 . V_132 = V_132 ;
V_165 -> V_184 . V_182 = V_182 ;
F_69 ( & V_2 -> V_171 , V_33 ) ;
F_70 ( & V_165 -> V_168 , & V_2 -> V_172 ) ;
F_71 ( & V_2 -> V_171 , V_33 ) ;
F_72 ( V_173 , & V_6 -> V_174 ) ;
}
int F_83 ( struct V_5 * V_6 ,
struct V_94 * V_95 ,
struct V_46 * V_126 ,
struct V_185 * V_186 ,
const T_1 * V_67 )
{
struct V_1 * V_2 = V_95 -> V_96 ;
int V_11 ;
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_107 ) ) {
F_61 ( V_2 -> V_107 ) ;
V_2 -> V_107 = NULL ;
}
F_84 ( & V_126 -> V_74 ,
V_6 -> V_7 . V_187 ) ;
if ( V_186 && V_186 -> V_188 >= 0 ) {
int V_189 ;
T_5 V_190 ;
V_189 = V_186 -> V_188 ;
V_190 = V_186 -> V_15 [ V_189 ] . V_190 ;
if ( V_190 == V_191 ||
V_190 == V_192 ) {
V_126 -> V_59 = V_189 ;
V_126 -> V_57 = V_186 -> V_15 [ V_189 ] . V_57 ;
V_126 -> V_58 = V_186 -> V_15 [ V_189 ] . V_58 ;
if ( V_126 -> V_72 . V_193 == 0 )
V_126 -> V_72 . V_193 = V_190 ;
if ( V_126 -> V_72 . V_194 == 0 ) {
V_126 -> V_72 . V_194 = 1 ;
V_126 -> V_72 . V_195 [ 0 ] = V_190 ;
}
}
V_126 -> V_72 . V_196 = V_186 -> V_15 ;
V_126 -> V_72 . V_197 = V_186 -> V_188 ;
} else {
if ( F_14 ( V_186 ) )
return - V_26 ;
}
V_2 -> V_107 = V_186 ;
memcpy ( V_2 -> V_36 , V_126 -> V_36 , V_126 -> V_37 ) ;
V_2 -> V_37 = V_126 -> V_37 ;
V_2 -> V_92 = V_126 -> V_198 ? V_199 :
V_200 ;
if ( ! V_6 -> V_52 -> V_126 )
V_11 = F_48 ( V_2 , V_126 , V_67 ) ;
else
V_11 = F_85 ( V_6 , V_95 , V_126 ) ;
if ( V_11 ) {
V_2 -> V_107 = NULL ;
V_2 -> V_37 = 0 ;
return V_11 ;
}
return 0 ;
}
int F_86 ( struct V_5 * V_6 ,
struct V_94 * V_95 , T_3 V_132 , bool V_140 )
{
struct V_1 * V_2 = V_95 -> V_96 ;
int V_11 = 0 ;
F_6 ( V_2 ) ;
F_61 ( V_2 -> V_107 ) ;
V_2 -> V_107 = NULL ;
V_2 -> V_159 = 0 ;
if ( V_2 -> V_3 )
V_11 = F_51 ( V_2 , V_132 ) ;
else if ( ! V_6 -> V_52 -> V_201 )
F_87 ( V_6 , V_95 ) ;
else if ( V_2 -> V_37 )
V_11 = F_88 ( V_6 , V_95 , V_132 ) ;
return V_11 ;
}
void F_89 ( struct V_83 * V_84 )
{
struct V_1 * V_2 =
F_19 ( V_84 , struct V_1 , V_202 ) ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
F_22 ( V_2 ) ;
if ( V_2 -> V_159 ) {
if ( V_6 -> V_52 -> V_201 || V_2 -> V_127 )
F_86 ( V_6 , V_2 -> V_43 ,
V_77 , true ) ;
else
F_17 ( V_6 , V_2 -> V_43 ,
V_2 -> V_203 , NULL , 0 ,
V_77 , false ) ;
}
F_24 ( V_2 ) ;
}
