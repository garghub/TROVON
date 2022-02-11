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
struct V_90 V_91 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_92 = - 1 ;
V_91 . V_38 = V_38 ;
V_91 . V_93 = V_45 ;
F_25 ( V_2 -> V_43 , & V_91 , false ) ;
}
F_24 ( V_2 ) ;
}
F_26 () ;
}
static struct V_94 * F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_94 * V_95 ;
F_6 ( V_2 ) ;
V_95 = F_28 ( V_2 -> V_7 , V_2 -> V_3 -> V_15 . V_16 ,
V_2 -> V_3 -> V_15 . V_38 ,
V_2 -> V_3 -> V_15 . V_36 ,
V_2 -> V_3 -> V_15 . V_37 ,
V_2 -> V_96 ,
F_29 ( V_2 -> V_3 -> V_15 . V_97 ) ) ;
if ( ! V_95 )
return NULL ;
memcpy ( V_2 -> V_3 -> V_38 , V_95 -> V_38 , V_87 ) ;
V_2 -> V_3 -> V_15 . V_38 = V_2 -> V_3 -> V_38 ;
V_2 -> V_3 -> V_15 . V_16 = V_95 -> V_16 ;
V_2 -> V_3 -> V_41 = V_51 ;
F_30 ( & V_6 -> V_85 ) ;
return V_95 ;
}
static void F_31 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_94 * V_95 ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 )
return;
if ( V_2 -> V_3 -> V_41 != V_42 &&
V_2 -> V_3 -> V_41 != V_50 )
return;
V_95 = F_27 ( V_2 ) ;
if ( V_95 )
F_32 ( & V_6 -> V_7 , V_95 ) ;
else
F_30 ( & V_6 -> V_85 ) ;
}
void F_33 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
F_22 ( V_2 ) ;
F_31 ( V_99 ) ;
F_24 ( V_2 ) ;
}
void F_34 ( struct V_1 * V_2 , const T_1 * V_101 , T_2 V_102 )
{
struct V_7 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_103 * V_104 = (struct V_103 * ) V_101 ;
T_3 V_105 = F_35 ( V_104 -> V_106 . V_53 . V_105 ) ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 || V_2 -> V_3 -> V_41 == V_88 )
return;
if ( V_105 == V_107 &&
V_2 -> V_3 -> V_108 &&
V_2 -> V_3 -> V_15 . V_56 != V_109 ) {
switch ( V_2 -> V_3 -> V_15 . V_56 ) {
case V_110 :
if ( V_2 -> V_111 )
V_2 -> V_3 -> V_15 . V_56 =
V_112 ;
else
V_2 -> V_3 -> V_15 . V_56 =
V_109 ;
break;
case V_112 :
V_2 -> V_3 -> V_15 . V_56 =
V_109 ;
break;
default:
V_2 -> V_3 -> V_15 . V_56 =
V_110 ;
break;
}
V_2 -> V_3 -> V_41 = V_51 ;
F_30 ( & V_6 -> V_85 ) ;
} else if ( V_105 != V_113 ) {
struct V_90 V_91 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_92 = V_105 ;
V_91 . V_38 = V_104 -> V_38 ;
V_91 . V_93 = V_89 ;
F_25 ( V_2 -> V_43 , & V_91 , false ) ;
} else if ( V_2 -> V_3 -> V_41 == V_55 ) {
V_2 -> V_3 -> V_41 = V_63 ;
F_30 ( & V_6 -> V_85 ) ;
}
}
bool F_36 ( struct V_1 * V_2 , T_3 V_92 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return false ;
if ( V_92 == V_113 ) {
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
const T_1 * V_114 , T_2 V_115 ,
const T_1 * * V_116 , T_2 * V_117 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
T_1 * V_101 ;
T_2 V_118 ;
if ( ! V_6 -> V_7 . V_119 ||
( V_114 && F_43 ( V_120 , V_114 , V_115 ) ) ) {
* V_116 = F_44 ( V_114 , V_115 , V_19 ) ;
if ( ! * V_116 )
return - V_20 ;
* V_117 = V_115 ;
return 0 ;
}
V_101 = F_45 ( V_115 + V_6 -> V_7 . V_119 + 2 ,
V_19 ) ;
if ( ! V_101 )
return - V_20 ;
if ( V_115 ) {
static const T_1 V_121 [] = {
V_122 ,
V_123 ,
V_124 ,
V_125 ,
V_126 ,
V_127 ,
} ;
V_118 = F_46 ( V_114 , V_115 , V_121 ,
F_47 ( V_121 ) , 0 ) ;
memcpy ( V_101 , V_114 , V_118 ) ;
memcpy ( V_101 + V_118 + V_6 -> V_7 . V_119 + 2 ,
V_114 + V_118 , V_115 - V_118 ) ;
} else {
V_118 = 0 ;
}
V_101 [ V_118 ] = V_120 ;
V_101 [ V_118 + 1 ] = V_6 -> V_7 . V_119 ;
memcpy ( V_101 + V_118 + 2 ,
V_6 -> V_7 . V_128 ,
V_6 -> V_7 . V_119 ) ;
* V_116 = V_101 ;
* V_117 = V_115 + V_6 -> V_7 . V_119 + 2 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_46 * V_129 ,
const T_1 * V_67 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_94 * V_95 ;
int V_11 ;
if ( ! V_6 -> V_52 -> V_53 || ! V_6 -> V_52 -> V_64 )
return - V_54 ;
if ( V_2 -> V_130 ) {
if ( ! V_67 )
return - V_131 ;
if ( V_67 &&
! F_49 ( V_67 , V_2 -> V_130 -> V_132 . V_38 ) )
return - V_62 ;
F_50 ( V_2 -> V_130 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_130 -> V_132 ) ;
V_2 -> V_130 = NULL ;
F_1 ( V_2 ) ;
}
if ( F_14 ( V_2 -> V_3 ) )
return - V_133 ;
V_2 -> V_3 = F_8 ( sizeof( * V_2 -> V_3 ) , V_19 ) ;
if ( ! V_2 -> V_3 )
return - V_20 ;
memcpy ( & V_2 -> V_3 -> V_15 , V_129 , sizeof( * V_129 ) ) ;
if ( V_129 -> V_38 ) {
V_2 -> V_3 -> V_15 . V_38 = V_2 -> V_3 -> V_38 ;
memcpy ( V_2 -> V_3 -> V_38 , V_129 -> V_38 , V_87 ) ;
}
if ( F_42 ( V_2 , V_129 -> V_4 , V_129 -> V_68 ,
& V_2 -> V_3 -> V_4 ,
& V_2 -> V_3 -> V_15 . V_68 ) ) {
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return - V_20 ;
}
V_2 -> V_3 -> V_15 . V_4 = V_2 -> V_3 -> V_4 ;
if ( V_129 -> V_56 == V_134 ) {
V_2 -> V_3 -> V_108 = true ;
V_2 -> V_3 -> V_15 . V_56 =
V_110 ;
} else {
V_2 -> V_3 -> V_108 = false ;
}
V_2 -> V_3 -> V_15 . V_36 = V_2 -> V_36 ;
V_2 -> V_3 -> V_15 . V_37 = V_2 -> V_37 ;
V_95 = F_27 ( V_2 ) ;
if ( V_67 ) {
memcpy ( V_2 -> V_3 -> V_67 , V_67 , V_87 ) ;
V_2 -> V_3 -> V_66 = true ;
}
if ( V_95 ) {
enum V_44 V_45 ;
V_11 = F_13 ( V_2 , & V_45 ) ;
F_32 ( V_2 -> V_7 , V_95 ) ;
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
static int F_51 ( struct V_1 * V_2 , T_3 V_135 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_11 ;
if ( ! V_2 -> V_3 )
return 0 ;
if ( ! V_6 -> V_52 -> V_136 )
return - V_54 ;
if ( V_2 -> V_3 -> V_41 == V_42 ||
V_2 -> V_3 -> V_41 == V_50 ) {
V_11 = 0 ;
goto V_137;
}
V_11 = F_17 ( V_6 , V_2 -> V_43 ,
V_2 -> V_3 -> V_15 . V_38 ,
NULL , 0 , V_135 , false ) ;
V_137:
F_1 ( V_2 ) ;
return V_11 ;
}
static bool F_52 ( void )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
bool V_138 = true ;
F_21 (rdev, &cfg80211_rdev_list, list) {
F_21 (wdev, &rdev->wiphy.wdev_list, list) {
F_22 ( V_2 ) ;
if ( V_2 -> V_3 || V_2 -> V_130 )
V_138 = false ;
F_24 ( V_2 ) ;
}
}
return V_138 ;
}
static void F_53 ( struct V_83 * V_84 )
{
F_20 () ;
if ( F_52 () )
F_54 () ;
F_26 () ;
}
void F_25 ( struct V_98 * V_99 ,
struct V_90 * V_91 ,
bool V_139 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
const T_1 * V_140 ;
#ifdef F_55
union V_141 V_142 ;
#endif
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_143 != V_144 &&
V_2 -> V_143 != V_145 ) ) {
F_32 ( V_2 -> V_7 , V_91 -> V_95 ) ;
return;
}
F_56 ( F_4 ( V_2 -> V_7 ) , V_99 , V_91 ,
V_19 ) ;
#ifdef F_55
if ( V_139 ) {
if ( V_91 -> V_146 && V_91 -> V_92 == V_113 ) {
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_147 . V_148 = V_91 -> V_149 ;
F_57 ( V_99 , V_150 , & V_142 ,
V_91 -> V_146 ) ;
}
if ( V_91 -> V_151 && V_91 -> V_92 == V_113 ) {
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_147 . V_148 = V_91 -> V_152 ;
F_57 ( V_99 , V_153 , & V_142 ,
V_91 -> V_151 ) ;
}
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_154 . V_155 = V_156 ;
if ( V_91 -> V_38 && V_91 -> V_92 == V_113 ) {
memcpy ( V_142 . V_154 . V_157 , V_91 -> V_38 , V_87 ) ;
memcpy ( V_2 -> V_158 . V_67 , V_91 -> V_38 , V_87 ) ;
V_2 -> V_158 . V_66 = true ;
}
F_57 ( V_99 , V_159 , & V_142 , NULL ) ;
}
#endif
if ( ! V_91 -> V_95 && ( V_91 -> V_92 == V_113 ) ) {
F_58 ( ! F_4 ( V_2 -> V_7 ) -> V_52 -> V_129 ) ;
V_91 -> V_95 = F_28 ( V_2 -> V_7 , NULL , V_91 -> V_38 ,
V_2 -> V_36 , V_2 -> V_37 ,
V_2 -> V_96 ,
V_160 ) ;
if ( V_91 -> V_95 )
F_59 ( F_60 ( V_91 -> V_95 ) ) ;
}
if ( V_2 -> V_130 ) {
F_50 ( V_2 -> V_130 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_130 -> V_132 ) ;
V_2 -> V_130 = NULL ;
}
if ( V_91 -> V_92 != V_113 ) {
F_61 ( V_2 -> V_111 ) ;
V_2 -> V_111 = NULL ;
V_2 -> V_37 = 0 ;
V_2 -> V_161 = 0 ;
if ( V_91 -> V_95 ) {
F_50 ( F_60 ( V_91 -> V_95 ) ) ;
F_32 ( V_2 -> V_7 , V_91 -> V_95 ) ;
}
F_1 ( V_2 ) ;
return;
}
if ( F_14 ( ! V_91 -> V_95 ) )
return;
V_2 -> V_130 = F_60 ( V_91 -> V_95 ) ;
if ( ! ( V_2 -> V_7 -> V_33 & V_162 ) )
F_62 ( V_2 ) ;
F_63 () ;
V_140 = F_64 ( V_91 -> V_95 , V_163 ) ;
if ( ! V_140 ) {
F_65 () ;
return;
}
V_140 = F_44 ( V_140 , 2 + V_140 [ 1 ] , V_164 ) ;
F_65 () ;
if ( ! V_140 )
return;
F_66 ( V_2 -> V_7 , V_91 -> V_95 -> V_16 -> V_22 ,
V_140 + 2 , V_140 [ 1 ] ) ;
F_2 ( V_140 ) ;
}
void F_67 ( struct V_98 * V_99 ,
struct V_90 * V_15 ,
T_4 V_165 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_166 * V_167 ;
unsigned long V_33 ;
T_1 * V_168 ;
if ( V_15 -> V_95 ) {
struct V_169 * V_170 = F_60 ( V_15 -> V_95 ) ;
if ( F_14 ( F_68 ( & V_170 -> V_171 ) ) ) {
F_32 ( V_2 -> V_7 , V_15 -> V_95 ) ;
return;
}
}
V_167 = F_8 ( sizeof( * V_167 ) + ( V_15 -> V_38 ? V_87 : 0 ) +
V_15 -> V_149 + V_15 -> V_152 +
V_15 -> V_172 + V_15 -> V_173 +
( V_15 -> V_174 ? V_175 : 0 ) , V_165 ) ;
if ( ! V_167 ) {
F_32 ( V_2 -> V_7 , V_15 -> V_95 ) ;
return;
}
V_167 -> type = V_176 ;
V_168 = ( ( T_1 * ) V_167 ) + sizeof( * V_167 ) ;
if ( V_15 -> V_38 ) {
V_167 -> V_91 . V_38 = V_168 ;
memcpy ( ( void * ) V_167 -> V_91 . V_38 , V_15 -> V_38 , V_87 ) ;
V_168 += V_87 ;
}
if ( V_15 -> V_149 ) {
V_167 -> V_91 . V_146 = V_168 ;
V_167 -> V_91 . V_149 = V_15 -> V_149 ;
memcpy ( ( void * ) V_167 -> V_91 . V_146 , V_15 -> V_146 ,
V_15 -> V_149 ) ;
V_168 += V_15 -> V_149 ;
}
if ( V_15 -> V_152 ) {
V_167 -> V_91 . V_151 = V_168 ;
V_167 -> V_91 . V_152 = V_15 -> V_152 ;
memcpy ( ( void * ) V_167 -> V_91 . V_151 , V_15 -> V_151 ,
V_15 -> V_152 ) ;
V_168 += V_15 -> V_152 ;
}
if ( V_15 -> V_172 ) {
V_167 -> V_91 . V_177 = V_168 ;
V_167 -> V_91 . V_172 = V_15 -> V_172 ;
memcpy ( ( void * ) V_167 -> V_91 . V_177 , V_15 -> V_177 ,
V_15 -> V_172 ) ;
V_168 += V_15 -> V_172 ;
}
if ( V_15 -> V_173 ) {
V_167 -> V_91 . V_178 = V_168 ;
V_167 -> V_91 . V_173 = V_15 -> V_173 ;
memcpy ( ( void * ) V_167 -> V_91 . V_178 , V_15 -> V_178 , V_15 -> V_173 ) ;
V_168 += V_15 -> V_173 ;
}
if ( V_15 -> V_174 ) {
V_167 -> V_91 . V_174 = V_168 ;
memcpy ( ( void * ) V_167 -> V_91 . V_174 , V_15 -> V_174 , V_175 ) ;
V_168 += V_175 ;
}
V_167 -> V_91 . V_179 = V_15 -> V_179 ;
if ( V_15 -> V_179 )
V_167 -> V_91 . V_180 = V_15 -> V_180 ;
if ( V_15 -> V_95 )
F_59 ( F_60 ( V_15 -> V_95 ) ) ;
V_167 -> V_91 . V_95 = V_15 -> V_95 ;
V_167 -> V_91 . V_92 = V_15 -> V_92 ;
V_167 -> V_91 . V_93 = V_15 -> V_93 ;
F_69 ( & V_2 -> V_181 , V_33 ) ;
F_70 ( & V_167 -> V_171 , & V_2 -> V_182 ) ;
F_71 ( & V_2 -> V_181 , V_33 ) ;
F_72 ( V_183 , & V_6 -> V_184 ) ;
}
void F_73 ( struct V_1 * V_2 ,
struct V_185 * V_186 )
{
#ifdef F_55
union V_141 V_142 ;
#endif
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_143 != V_144 &&
V_2 -> V_143 != V_145 ) )
goto V_137;
if ( F_14 ( ! V_2 -> V_130 ) )
goto V_137;
F_50 ( V_2 -> V_130 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_130 -> V_132 ) ;
V_2 -> V_130 = NULL ;
if ( F_14 ( ! V_186 -> V_95 ) )
return;
F_59 ( F_60 ( V_186 -> V_95 ) ) ;
V_2 -> V_130 = F_60 ( V_186 -> V_95 ) ;
F_74 ( F_4 ( V_2 -> V_7 ) ,
V_2 -> V_43 , V_186 , V_19 ) ;
#ifdef F_55
if ( V_186 -> V_146 ) {
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_147 . V_148 = V_186 -> V_149 ;
F_57 ( V_2 -> V_43 , V_150 ,
& V_142 , V_186 -> V_146 ) ;
}
if ( V_186 -> V_151 ) {
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_147 . V_148 = V_186 -> V_152 ;
F_57 ( V_2 -> V_43 , V_153 ,
& V_142 , V_186 -> V_151 ) ;
}
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_154 . V_155 = V_156 ;
memcpy ( V_142 . V_154 . V_157 , V_186 -> V_95 -> V_38 , V_87 ) ;
memcpy ( V_2 -> V_158 . V_67 , V_186 -> V_95 -> V_38 , V_87 ) ;
V_2 -> V_158 . V_66 = true ;
F_57 ( V_2 -> V_43 , V_159 , & V_142 , NULL ) ;
#endif
return;
V_137:
F_32 ( V_2 -> V_7 , V_186 -> V_95 ) ;
}
void F_75 ( struct V_98 * V_99 , struct V_185 * V_186 ,
T_4 V_165 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_166 * V_167 ;
unsigned long V_33 ;
if ( ! V_186 -> V_95 ) {
V_186 -> V_95 = F_28 ( V_2 -> V_7 , V_186 -> V_16 ,
V_186 -> V_38 , V_2 -> V_36 ,
V_2 -> V_37 ,
V_2 -> V_96 ,
V_160 ) ;
}
if ( F_14 ( ! V_186 -> V_95 ) )
return;
V_167 = F_8 ( sizeof( * V_167 ) + V_186 -> V_149 + V_186 -> V_152 , V_165 ) ;
if ( ! V_167 ) {
F_32 ( V_2 -> V_7 , V_186 -> V_95 ) ;
return;
}
V_167 -> type = V_187 ;
V_167 -> V_188 . V_146 = ( ( T_1 * ) V_167 ) + sizeof( * V_167 ) ;
V_167 -> V_188 . V_149 = V_186 -> V_149 ;
memcpy ( ( void * ) V_167 -> V_188 . V_146 , V_186 -> V_146 , V_186 -> V_149 ) ;
V_167 -> V_188 . V_151 = ( ( T_1 * ) V_167 ) + sizeof( * V_167 ) + V_186 -> V_149 ;
V_167 -> V_188 . V_152 = V_186 -> V_152 ;
memcpy ( ( void * ) V_167 -> V_188 . V_151 , V_186 -> V_151 , V_186 -> V_152 ) ;
V_167 -> V_188 . V_95 = V_186 -> V_95 ;
V_167 -> V_188 . V_189 = V_186 -> V_189 ;
F_69 ( & V_2 -> V_181 , V_33 ) ;
F_70 ( & V_167 -> V_171 , & V_2 -> V_182 ) ;
F_71 ( & V_2 -> V_181 , V_33 ) ;
F_72 ( V_183 , & V_6 -> V_184 ) ;
}
void F_76 ( struct V_98 * V_99 , const T_1 * V_4 ,
T_2 V_68 , T_3 V_135 , bool V_190 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_29 ;
#ifdef F_55
union V_141 V_142 ;
#endif
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_143 != V_144 &&
V_2 -> V_143 != V_145 ) )
return;
if ( V_2 -> V_130 ) {
F_50 ( V_2 -> V_130 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_130 -> V_132 ) ;
}
V_2 -> V_130 = NULL ;
V_2 -> V_37 = 0 ;
V_2 -> V_161 = 0 ;
F_77 ( V_6 , V_99 , V_135 , V_4 , V_68 , V_190 ) ;
if ( V_6 -> V_52 -> V_191 && V_6 -> V_192 ) {
V_6 -> V_192 = 0 ;
F_78 ( V_6 , V_2 ) ;
}
if ( V_6 -> V_52 -> V_193 )
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
F_79 ( V_6 , V_99 , V_29 , false , NULL ) ;
F_80 ( V_6 , V_99 , NULL ) ;
#ifdef F_55
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_154 . V_155 = V_156 ;
F_57 ( V_99 , V_159 , & V_142 , NULL ) ;
V_2 -> V_158 . V_129 . V_37 = 0 ;
#endif
F_30 ( & V_194 ) ;
}
void F_81 ( struct V_98 * V_99 , T_3 V_135 ,
const T_1 * V_4 , T_2 V_68 ,
bool V_195 , T_4 V_165 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_166 * V_167 ;
unsigned long V_33 ;
V_167 = F_8 ( sizeof( * V_167 ) + V_68 , V_165 ) ;
if ( ! V_167 )
return;
V_167 -> type = V_196 ;
V_167 -> V_197 . V_4 = ( ( T_1 * ) V_167 ) + sizeof( * V_167 ) ;
V_167 -> V_197 . V_68 = V_68 ;
memcpy ( ( void * ) V_167 -> V_197 . V_4 , V_4 , V_68 ) ;
V_167 -> V_197 . V_135 = V_135 ;
V_167 -> V_197 . V_195 = V_195 ;
F_69 ( & V_2 -> V_181 , V_33 ) ;
F_70 ( & V_167 -> V_171 , & V_2 -> V_182 ) ;
F_71 ( & V_2 -> V_181 , V_33 ) ;
F_72 ( V_183 , & V_6 -> V_184 ) ;
}
int F_82 ( struct V_5 * V_6 ,
struct V_98 * V_99 ,
struct V_46 * V_129 ,
struct V_198 * V_199 ,
const T_1 * V_67 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
int V_11 ;
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_111 ) ) {
F_61 ( V_2 -> V_111 ) ;
V_2 -> V_111 = NULL ;
}
F_83 ( & V_129 -> V_74 ,
V_6 -> V_7 . V_200 ) ;
if ( V_199 && V_199 -> V_201 >= 0 ) {
int V_202 ;
T_5 V_203 ;
V_202 = V_199 -> V_201 ;
V_203 = V_199 -> V_15 [ V_202 ] . V_203 ;
if ( V_203 == V_204 ||
V_203 == V_205 ) {
V_129 -> V_59 = V_202 ;
V_129 -> V_57 = V_199 -> V_15 [ V_202 ] . V_57 ;
V_129 -> V_58 = V_199 -> V_15 [ V_202 ] . V_58 ;
if ( V_129 -> V_72 . V_206 == 0 )
V_129 -> V_72 . V_206 = V_203 ;
if ( V_129 -> V_72 . V_207 == 0 ) {
V_129 -> V_72 . V_207 = 1 ;
V_129 -> V_72 . V_208 [ 0 ] = V_203 ;
}
}
V_129 -> V_72 . V_209 = V_199 -> V_15 ;
V_129 -> V_72 . V_210 = V_199 -> V_201 ;
} else {
if ( F_14 ( V_199 ) )
return - V_26 ;
}
V_2 -> V_111 = V_199 ;
memcpy ( V_2 -> V_36 , V_129 -> V_36 , V_129 -> V_37 ) ;
V_2 -> V_37 = V_129 -> V_37 ;
V_2 -> V_96 = V_129 -> V_211 ? V_212 :
V_213 ;
if ( ! V_6 -> V_52 -> V_129 )
V_11 = F_48 ( V_2 , V_129 , V_67 ) ;
else
V_11 = F_84 ( V_6 , V_99 , V_129 ) ;
if ( V_11 ) {
V_2 -> V_111 = NULL ;
V_2 -> V_37 = 0 ;
return V_11 ;
}
return 0 ;
}
int F_85 ( struct V_5 * V_6 ,
struct V_98 * V_99 , T_3 V_135 , bool V_139 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
int V_11 = 0 ;
F_6 ( V_2 ) ;
F_61 ( V_2 -> V_111 ) ;
V_2 -> V_111 = NULL ;
V_2 -> V_161 = 0 ;
if ( V_2 -> V_3 )
V_11 = F_51 ( V_2 , V_135 ) ;
else if ( ! V_6 -> V_52 -> V_214 )
F_86 ( V_6 , V_99 ) ;
else if ( V_2 -> V_37 )
V_11 = F_87 ( V_6 , V_99 , V_135 ) ;
return V_11 ;
}
void F_88 ( struct V_83 * V_84 )
{
struct V_1 * V_2 =
F_19 ( V_84 , struct V_1 , V_215 ) ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
F_22 ( V_2 ) ;
if ( V_2 -> V_161 ) {
if ( V_6 -> V_52 -> V_214 || V_2 -> V_130 )
F_85 ( V_6 , V_2 -> V_43 ,
V_77 , true ) ;
else
F_17 ( V_6 , V_2 -> V_43 ,
V_2 -> V_216 , NULL , 0 ,
V_77 , false ) ;
}
F_24 ( V_2 ) ;
}
