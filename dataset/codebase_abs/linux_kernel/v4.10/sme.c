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
case V_77 :
F_1 ( V_2 ) ;
return 0 ;
default:
return 0 ;
}
}
void F_18 ( struct V_78 * V_79 )
{
struct V_5 * V_6 =
F_19 ( V_79 , struct V_5 , V_80 ) ;
struct V_1 * V_2 ;
T_1 V_81 [ V_82 ] , * V_38 = NULL ;
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
V_2 -> V_3 -> V_41 == V_83 ) {
F_24 ( V_2 ) ;
continue;
}
if ( V_2 -> V_3 -> V_15 . V_38 ) {
memcpy ( V_81 , V_2 -> V_3 -> V_15 . V_38 , V_82 ) ;
V_38 = V_81 ;
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
static struct V_84 * F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_84 * V_85 ;
F_6 ( V_2 ) ;
V_85 = F_28 ( V_2 -> V_7 , V_2 -> V_3 -> V_15 . V_16 ,
V_2 -> V_3 -> V_15 . V_38 ,
V_2 -> V_3 -> V_15 . V_36 ,
V_2 -> V_3 -> V_15 . V_37 ,
V_2 -> V_86 ,
F_29 ( V_2 -> V_3 -> V_15 . V_87 ) ) ;
if ( ! V_85 )
return NULL ;
memcpy ( V_2 -> V_3 -> V_38 , V_85 -> V_38 , V_82 ) ;
V_2 -> V_3 -> V_15 . V_38 = V_2 -> V_3 -> V_38 ;
V_2 -> V_3 -> V_15 . V_16 = V_85 -> V_16 ;
V_2 -> V_3 -> V_41 = V_49 ;
F_30 ( & V_6 -> V_80 ) ;
return V_85 ;
}
static void F_31 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_84 * V_85 ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 )
return;
if ( V_2 -> V_3 -> V_41 != V_42 &&
V_2 -> V_3 -> V_41 != V_48 )
return;
V_85 = F_27 ( V_2 ) ;
if ( V_85 )
F_32 ( & V_6 -> V_7 , V_85 ) ;
else
F_30 ( & V_6 -> V_80 ) ;
}
void F_33 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
F_22 ( V_2 ) ;
F_31 ( V_89 ) ;
F_24 ( V_2 ) ;
}
void F_34 ( struct V_1 * V_2 , const T_1 * V_91 , T_2 V_92 )
{
struct V_7 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_93 * V_94 = (struct V_93 * ) V_91 ;
T_3 V_95 = F_35 ( V_94 -> V_96 . V_51 . V_95 ) ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 || V_2 -> V_3 -> V_41 == V_83 )
return;
if ( V_95 == V_97 &&
V_2 -> V_3 -> V_98 &&
V_2 -> V_3 -> V_15 . V_54 != V_99 ) {
switch ( V_2 -> V_3 -> V_15 . V_54 ) {
case V_100 :
if ( V_2 -> V_101 )
V_2 -> V_3 -> V_15 . V_54 =
V_102 ;
else
V_2 -> V_3 -> V_15 . V_54 =
V_99 ;
break;
case V_102 :
V_2 -> V_3 -> V_15 . V_54 =
V_99 ;
break;
default:
V_2 -> V_3 -> V_15 . V_54 =
V_100 ;
break;
}
V_2 -> V_3 -> V_41 = V_49 ;
F_30 ( & V_6 -> V_80 ) ;
} else if ( V_95 != V_103 ) {
F_25 ( V_2 -> V_43 , V_94 -> V_38 ,
NULL , 0 , NULL , 0 ,
V_95 , false , NULL ) ;
} else if ( V_2 -> V_3 -> V_41 == V_53 ) {
V_2 -> V_3 -> V_41 = V_60 ;
F_30 ( & V_6 -> V_80 ) ;
}
}
bool F_36 ( struct V_1 * V_2 , T_3 V_104 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return false ;
if ( V_104 == V_103 ) {
V_2 -> V_3 -> V_41 = V_83 ;
return false ;
}
if ( V_2 -> V_3 -> V_63 ) {
V_2 -> V_3 -> V_63 = false ;
V_2 -> V_3 -> V_41 = V_60 ;
F_30 ( & V_6 -> V_80 ) ;
return true ;
}
V_2 -> V_3 -> V_41 = V_75 ;
F_30 ( & V_6 -> V_80 ) ;
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
F_30 ( & V_6 -> V_80 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_41 = V_76 ;
F_30 ( & V_6 -> V_80 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_41 = V_75 ;
F_30 ( & V_6 -> V_80 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_41 = V_77 ;
F_30 ( & V_6 -> V_80 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
const T_1 * V_105 , T_2 V_106 ,
const T_1 * * V_107 , T_2 * V_108 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
T_1 * V_91 ;
T_2 V_109 ;
if ( ! V_6 -> V_7 . V_110 ||
( V_105 && F_43 ( V_111 , V_105 , V_106 ) ) ) {
* V_107 = F_44 ( V_105 , V_106 , V_19 ) ;
if ( ! * V_107 )
return - V_20 ;
* V_108 = V_106 ;
return 0 ;
}
V_91 = F_45 ( V_106 + V_6 -> V_7 . V_110 + 2 ,
V_19 ) ;
if ( ! V_91 )
return - V_20 ;
if ( V_106 ) {
static const T_1 V_112 [] = {
V_113 ,
V_114 ,
V_115 ,
V_116 ,
V_117 ,
V_118 ,
} ;
V_109 = F_46 ( V_105 , V_106 , V_112 ,
F_47 ( V_112 ) , 0 ) ;
memcpy ( V_91 , V_105 , V_109 ) ;
memcpy ( V_91 + V_109 + V_6 -> V_7 . V_110 + 2 ,
V_105 + V_109 , V_106 - V_109 ) ;
} else {
V_109 = 0 ;
}
V_91 [ V_109 ] = V_111 ;
V_91 [ V_109 + 1 ] = V_6 -> V_7 . V_110 ;
memcpy ( V_91 + V_109 + 2 ,
V_6 -> V_7 . V_119 ,
V_6 -> V_7 . V_110 ) ;
* V_107 = V_91 ;
* V_108 = V_106 + V_6 -> V_7 . V_110 + 2 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_44 * V_120 ,
const T_1 * V_64 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_84 * V_85 ;
int V_11 ;
if ( ! V_6 -> V_50 -> V_51 || ! V_6 -> V_50 -> V_61 )
return - V_52 ;
if ( V_2 -> V_121 ) {
if ( ! V_64 )
return - V_122 ;
if ( V_64 &&
! F_49 ( V_64 , V_2 -> V_121 -> V_123 . V_38 ) )
return - V_59 ;
F_50 ( V_2 -> V_121 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_121 -> V_123 ) ;
V_2 -> V_121 = NULL ;
F_1 ( V_2 ) ;
}
if ( F_14 ( V_2 -> V_3 ) )
return - V_124 ;
V_2 -> V_3 = F_8 ( sizeof( * V_2 -> V_3 ) , V_19 ) ;
if ( ! V_2 -> V_3 )
return - V_20 ;
memcpy ( & V_2 -> V_3 -> V_15 , V_120 , sizeof( * V_120 ) ) ;
if ( V_120 -> V_38 ) {
V_2 -> V_3 -> V_15 . V_38 = V_2 -> V_3 -> V_38 ;
memcpy ( V_2 -> V_3 -> V_38 , V_120 -> V_38 , V_82 ) ;
}
if ( F_42 ( V_2 , V_120 -> V_4 , V_120 -> V_65 ,
& V_2 -> V_3 -> V_4 ,
& V_2 -> V_3 -> V_15 . V_65 ) ) {
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return - V_20 ;
}
V_2 -> V_3 -> V_15 . V_4 = V_2 -> V_3 -> V_4 ;
if ( V_120 -> V_54 == V_125 ) {
V_2 -> V_3 -> V_98 = true ;
V_2 -> V_3 -> V_15 . V_54 =
V_100 ;
} else {
V_2 -> V_3 -> V_98 = false ;
}
V_2 -> V_3 -> V_15 . V_36 = V_2 -> V_36 ;
V_2 -> V_3 -> V_15 . V_37 = V_2 -> V_37 ;
V_85 = F_27 ( V_2 ) ;
if ( V_64 ) {
memcpy ( V_2 -> V_3 -> V_64 , V_64 , V_82 ) ;
V_2 -> V_3 -> V_63 = true ;
}
if ( V_85 ) {
V_11 = F_13 ( V_2 ) ;
F_32 ( V_2 -> V_7 , V_85 ) ;
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
static int F_51 ( struct V_1 * V_2 , T_3 V_126 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_11 ;
if ( ! V_2 -> V_3 )
return 0 ;
if ( ! V_6 -> V_50 -> V_127 )
return - V_52 ;
if ( V_2 -> V_3 -> V_41 == V_42 ||
V_2 -> V_3 -> V_41 == V_48 ) {
V_11 = 0 ;
goto V_128;
}
V_11 = F_17 ( V_6 , V_2 -> V_43 ,
V_2 -> V_3 -> V_15 . V_38 ,
NULL , 0 , V_126 , false ) ;
V_128:
F_1 ( V_2 ) ;
return V_11 ;
}
static bool F_52 ( void )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
bool V_129 = true ;
F_21 (rdev, &cfg80211_rdev_list, list) {
F_21 (wdev, &rdev->wiphy.wdev_list, list) {
F_22 ( V_2 ) ;
if ( V_2 -> V_3 || V_2 -> V_121 )
V_129 = false ;
F_24 ( V_2 ) ;
}
}
return V_129 ;
}
static void F_53 ( struct V_78 * V_79 )
{
F_20 () ;
if ( F_52 () )
F_54 () ;
F_26 () ;
}
void F_25 ( struct V_88 * V_89 , const T_1 * V_38 ,
const T_1 * V_130 , T_2 V_131 ,
const T_1 * V_132 , T_2 V_133 ,
int V_104 , bool V_134 ,
struct V_84 * V_85 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
const T_1 * V_135 ;
#ifdef F_55
union V_136 V_137 ;
#endif
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_138 != V_139 &&
V_2 -> V_138 != V_140 ) ) {
F_32 ( V_2 -> V_7 , V_85 ) ;
return;
}
F_56 ( F_4 ( V_2 -> V_7 ) , V_89 ,
V_38 , V_130 , V_131 ,
V_132 , V_133 ,
V_104 , V_19 ) ;
#ifdef F_55
if ( V_134 ) {
if ( V_130 && V_104 == V_103 ) {
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_141 . V_142 = V_131 ;
F_57 ( V_89 , V_143 , & V_137 , V_130 ) ;
}
if ( V_132 && V_104 == V_103 ) {
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_141 . V_142 = V_133 ;
F_57 ( V_89 , V_144 , & V_137 , V_132 ) ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_145 . V_146 = V_147 ;
if ( V_38 && V_104 == V_103 ) {
memcpy ( V_137 . V_145 . V_148 , V_38 , V_82 ) ;
memcpy ( V_2 -> V_149 . V_64 , V_38 , V_82 ) ;
V_2 -> V_149 . V_63 = true ;
}
F_57 ( V_89 , V_150 , & V_137 , NULL ) ;
}
#endif
if ( ! V_85 && ( V_104 == V_103 ) ) {
F_58 ( ! F_4 ( V_2 -> V_7 ) -> V_50 -> V_120 ) ;
V_85 = F_28 ( V_2 -> V_7 , NULL , V_38 ,
V_2 -> V_36 , V_2 -> V_37 ,
V_2 -> V_86 ,
V_151 ) ;
if ( V_85 )
F_59 ( F_60 ( V_85 ) ) ;
}
if ( V_2 -> V_121 ) {
F_50 ( V_2 -> V_121 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_121 -> V_123 ) ;
V_2 -> V_121 = NULL ;
}
if ( V_104 != V_103 ) {
F_61 ( V_2 -> V_101 ) ;
V_2 -> V_101 = NULL ;
V_2 -> V_37 = 0 ;
if ( V_85 ) {
F_50 ( F_60 ( V_85 ) ) ;
F_32 ( V_2 -> V_7 , V_85 ) ;
}
F_1 ( V_2 ) ;
return;
}
if ( F_14 ( ! V_85 ) )
return;
V_2 -> V_121 = F_60 ( V_85 ) ;
if ( ! ( V_2 -> V_7 -> V_33 & V_152 ) )
F_62 ( V_2 ) ;
F_63 () ;
V_135 = F_64 ( V_85 , V_153 ) ;
if ( ! V_135 ) {
F_65 () ;
return;
}
V_135 = F_44 ( V_135 , 2 + V_135 [ 1 ] , V_154 ) ;
F_65 () ;
if ( ! V_135 )
return;
F_66 ( V_2 -> V_7 , V_85 -> V_16 -> V_22 ,
V_135 + 2 , V_135 [ 1 ] ) ;
F_2 ( V_135 ) ;
}
void F_67 ( struct V_88 * V_89 , const T_1 * V_38 ,
struct V_84 * V_85 , const T_1 * V_130 ,
T_2 V_131 , const T_1 * V_132 ,
T_2 V_133 , int V_104 , T_4 V_155 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_156 * V_157 ;
unsigned long V_33 ;
if ( V_85 ) {
struct V_158 * V_159 = F_60 ( V_85 ) ;
if ( F_14 ( F_68 ( & V_159 -> V_160 ) ) ) {
F_32 ( V_2 -> V_7 , V_85 ) ;
return;
}
}
V_157 = F_8 ( sizeof( * V_157 ) + V_131 + V_133 , V_155 ) ;
if ( ! V_157 ) {
F_32 ( V_2 -> V_7 , V_85 ) ;
return;
}
V_157 -> type = V_161 ;
if ( V_38 )
memcpy ( V_157 -> V_162 . V_38 , V_38 , V_82 ) ;
if ( V_131 ) {
V_157 -> V_162 . V_130 = ( ( T_1 * ) V_157 ) + sizeof( * V_157 ) ;
V_157 -> V_162 . V_131 = V_131 ;
memcpy ( ( void * ) V_157 -> V_162 . V_130 , V_130 , V_131 ) ;
}
if ( V_133 ) {
V_157 -> V_162 . V_132 = ( ( T_1 * ) V_157 ) + sizeof( * V_157 ) + V_131 ;
V_157 -> V_162 . V_133 = V_133 ;
memcpy ( ( void * ) V_157 -> V_162 . V_132 , V_132 , V_133 ) ;
}
if ( V_85 )
F_59 ( F_60 ( V_85 ) ) ;
V_157 -> V_162 . V_85 = V_85 ;
V_157 -> V_162 . V_104 = V_104 ;
F_69 ( & V_2 -> V_163 , V_33 ) ;
F_70 ( & V_157 -> V_160 , & V_2 -> V_164 ) ;
F_71 ( & V_2 -> V_163 , V_33 ) ;
F_72 ( V_165 , & V_6 -> V_166 ) ;
}
void F_73 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
const T_1 * V_130 , T_2 V_131 ,
const T_1 * V_132 , T_2 V_133 )
{
#ifdef F_55
union V_136 V_137 ;
#endif
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_138 != V_139 &&
V_2 -> V_138 != V_140 ) )
goto V_128;
if ( F_14 ( ! V_2 -> V_121 ) )
goto V_128;
F_50 ( V_2 -> V_121 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_121 -> V_123 ) ;
V_2 -> V_121 = NULL ;
F_59 ( F_60 ( V_85 ) ) ;
V_2 -> V_121 = F_60 ( V_85 ) ;
F_74 ( F_4 ( V_2 -> V_7 ) ,
V_2 -> V_43 , V_85 -> V_38 ,
V_130 , V_131 , V_132 , V_133 ,
V_19 ) ;
#ifdef F_55
if ( V_130 ) {
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_141 . V_142 = V_131 ;
F_57 ( V_2 -> V_43 , V_143 ,
& V_137 , V_130 ) ;
}
if ( V_132 ) {
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_141 . V_142 = V_133 ;
F_57 ( V_2 -> V_43 , V_144 ,
& V_137 , V_132 ) ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_145 . V_146 = V_147 ;
memcpy ( V_137 . V_145 . V_148 , V_85 -> V_38 , V_82 ) ;
memcpy ( V_2 -> V_149 . V_64 , V_85 -> V_38 , V_82 ) ;
V_2 -> V_149 . V_63 = true ;
F_57 ( V_2 -> V_43 , V_150 , & V_137 , NULL ) ;
#endif
return;
V_128:
F_32 ( V_2 -> V_7 , V_85 ) ;
}
void F_75 ( struct V_88 * V_89 ,
struct V_31 * V_16 ,
const T_1 * V_38 ,
const T_1 * V_130 , T_2 V_131 ,
const T_1 * V_132 , T_2 V_133 , T_4 V_155 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
struct V_84 * V_85 ;
V_85 = F_28 ( V_2 -> V_7 , V_16 , V_38 , V_2 -> V_36 ,
V_2 -> V_37 ,
V_2 -> V_86 , V_151 ) ;
if ( F_14 ( ! V_85 ) )
return;
F_76 ( V_89 , V_85 , V_130 , V_131 , V_132 ,
V_133 , V_155 ) ;
}
void F_76 ( struct V_88 * V_89 ,
struct V_84 * V_85 , const T_1 * V_130 ,
T_2 V_131 , const T_1 * V_132 ,
T_2 V_133 , T_4 V_155 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_156 * V_157 ;
unsigned long V_33 ;
if ( F_14 ( ! V_85 ) )
return;
V_157 = F_8 ( sizeof( * V_157 ) + V_131 + V_133 , V_155 ) ;
if ( ! V_157 ) {
F_32 ( V_2 -> V_7 , V_85 ) ;
return;
}
V_157 -> type = V_167 ;
V_157 -> V_168 . V_130 = ( ( T_1 * ) V_157 ) + sizeof( * V_157 ) ;
V_157 -> V_168 . V_131 = V_131 ;
memcpy ( ( void * ) V_157 -> V_168 . V_130 , V_130 , V_131 ) ;
V_157 -> V_168 . V_132 = ( ( T_1 * ) V_157 ) + sizeof( * V_157 ) + V_131 ;
V_157 -> V_168 . V_133 = V_133 ;
memcpy ( ( void * ) V_157 -> V_168 . V_132 , V_132 , V_133 ) ;
V_157 -> V_168 . V_85 = V_85 ;
F_69 ( & V_2 -> V_163 , V_33 ) ;
F_70 ( & V_157 -> V_160 , & V_2 -> V_164 ) ;
F_71 ( & V_2 -> V_163 , V_33 ) ;
F_72 ( V_165 , & V_6 -> V_166 ) ;
}
void F_77 ( struct V_88 * V_89 , const T_1 * V_4 ,
T_2 V_65 , T_3 V_126 , bool V_169 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_29 ;
#ifdef F_55
union V_136 V_137 ;
#endif
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_138 != V_139 &&
V_2 -> V_138 != V_140 ) )
return;
if ( V_2 -> V_121 ) {
F_50 ( V_2 -> V_121 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_121 -> V_123 ) ;
}
V_2 -> V_121 = NULL ;
V_2 -> V_37 = 0 ;
F_78 ( V_6 , V_89 , V_126 , V_4 , V_65 , V_169 ) ;
if ( V_6 -> V_50 -> V_170 && V_6 -> V_171 ) {
V_6 -> V_171 = 0 ;
F_79 ( V_6 , V_2 ) ;
}
if ( V_6 -> V_50 -> V_172 )
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
F_80 ( V_6 , V_89 , V_29 , false , NULL ) ;
F_81 ( V_6 , V_89 , NULL ) ;
#ifdef F_55
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_145 . V_146 = V_147 ;
F_57 ( V_89 , V_150 , & V_137 , NULL ) ;
V_2 -> V_149 . V_120 . V_37 = 0 ;
#endif
F_30 ( & V_173 ) ;
}
void F_82 ( struct V_88 * V_89 , T_3 V_126 ,
const T_1 * V_4 , T_2 V_65 ,
bool V_174 , T_4 V_155 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_156 * V_157 ;
unsigned long V_33 ;
V_157 = F_8 ( sizeof( * V_157 ) + V_65 , V_155 ) ;
if ( ! V_157 )
return;
V_157 -> type = V_175 ;
V_157 -> V_176 . V_4 = ( ( T_1 * ) V_157 ) + sizeof( * V_157 ) ;
V_157 -> V_176 . V_65 = V_65 ;
memcpy ( ( void * ) V_157 -> V_176 . V_4 , V_4 , V_65 ) ;
V_157 -> V_176 . V_126 = V_126 ;
V_157 -> V_176 . V_174 = V_174 ;
F_69 ( & V_2 -> V_163 , V_33 ) ;
F_70 ( & V_157 -> V_160 , & V_2 -> V_164 ) ;
F_71 ( & V_2 -> V_163 , V_33 ) ;
F_72 ( V_165 , & V_6 -> V_166 ) ;
}
int F_83 ( struct V_5 * V_6 ,
struct V_88 * V_89 ,
struct V_44 * V_120 ,
struct V_177 * V_178 ,
const T_1 * V_64 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
int V_11 ;
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_101 ) ) {
F_61 ( V_2 -> V_101 ) ;
V_2 -> V_101 = NULL ;
}
F_84 ( & V_120 -> V_71 ,
V_6 -> V_7 . V_179 ) ;
if ( V_178 && V_178 -> V_180 >= 0 ) {
int V_181 ;
T_5 V_182 ;
V_181 = V_178 -> V_180 ;
V_182 = V_178 -> V_15 [ V_181 ] . V_182 ;
if ( V_182 == V_183 ||
V_182 == V_184 ) {
V_120 -> V_57 = V_181 ;
V_120 -> V_55 = V_178 -> V_15 [ V_181 ] . V_55 ;
V_120 -> V_56 = V_178 -> V_15 [ V_181 ] . V_56 ;
if ( V_120 -> V_69 . V_185 == 0 )
V_120 -> V_69 . V_185 = V_182 ;
if ( V_120 -> V_69 . V_186 == 0 ) {
V_120 -> V_69 . V_186 = 1 ;
V_120 -> V_69 . V_187 [ 0 ] = V_182 ;
}
}
V_120 -> V_69 . V_188 = V_178 -> V_15 ;
V_120 -> V_69 . V_189 = V_178 -> V_180 ;
} else {
if ( F_14 ( V_178 ) )
return - V_26 ;
}
V_2 -> V_101 = V_178 ;
memcpy ( V_2 -> V_36 , V_120 -> V_36 , V_120 -> V_37 ) ;
V_2 -> V_37 = V_120 -> V_37 ;
V_2 -> V_86 = V_120 -> V_190 ? V_191 :
V_192 ;
if ( ! V_6 -> V_50 -> V_120 )
V_11 = F_48 ( V_2 , V_120 , V_64 ) ;
else
V_11 = F_85 ( V_6 , V_89 , V_120 ) ;
if ( V_11 ) {
V_2 -> V_101 = NULL ;
V_2 -> V_37 = 0 ;
return V_11 ;
}
return 0 ;
}
int F_86 ( struct V_5 * V_6 ,
struct V_88 * V_89 , T_3 V_126 , bool V_134 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
int V_11 = 0 ;
F_6 ( V_2 ) ;
F_61 ( V_2 -> V_101 ) ;
V_2 -> V_101 = NULL ;
if ( V_2 -> V_3 )
V_11 = F_51 ( V_2 , V_126 ) ;
else if ( ! V_6 -> V_50 -> V_193 )
F_87 ( V_6 , V_89 ) ;
else if ( V_2 -> V_37 )
V_11 = F_88 ( V_6 , V_89 , V_126 ) ;
return V_11 ;
}
