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
F_49 ( V_2 -> V_130 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_130 -> V_131 ) ;
V_2 -> V_130 = NULL ;
F_1 ( V_2 ) ;
}
if ( F_14 ( V_2 -> V_3 ) )
return - V_132 ;
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
if ( V_129 -> V_56 == V_133 ) {
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
static int F_50 ( struct V_1 * V_2 , T_3 V_134 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_11 ;
if ( ! V_2 -> V_3 )
return 0 ;
if ( ! V_6 -> V_52 -> V_135 )
return - V_54 ;
if ( V_2 -> V_3 -> V_41 == V_42 ||
V_2 -> V_3 -> V_41 == V_50 ) {
V_11 = 0 ;
goto V_136;
}
V_11 = F_17 ( V_6 , V_2 -> V_43 ,
V_2 -> V_3 -> V_15 . V_38 ,
NULL , 0 , V_134 , false ) ;
V_136:
F_1 ( V_2 ) ;
return V_11 ;
}
static bool F_51 ( void )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
bool V_137 = true ;
F_21 (rdev, &cfg80211_rdev_list, list) {
F_21 (wdev, &rdev->wiphy.wdev_list, list) {
F_22 ( V_2 ) ;
if ( V_2 -> V_3 || V_2 -> V_130 )
V_137 = false ;
F_24 ( V_2 ) ;
}
}
return V_137 ;
}
static void F_52 ( struct V_83 * V_84 )
{
F_20 () ;
if ( F_51 () )
F_53 () ;
F_26 () ;
}
void F_25 ( struct V_98 * V_99 ,
struct V_90 * V_91 ,
bool V_138 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
const T_1 * V_139 ;
#ifdef F_54
union V_140 V_141 ;
#endif
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_142 != V_143 &&
V_2 -> V_142 != V_144 ) ) {
F_32 ( V_2 -> V_7 , V_91 -> V_95 ) ;
return;
}
F_55 ( F_4 ( V_2 -> V_7 ) , V_99 , V_91 ,
V_19 ) ;
#ifdef F_54
if ( V_138 ) {
if ( V_91 -> V_145 && V_91 -> V_92 == V_113 ) {
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_141 . V_146 . V_147 = V_91 -> V_148 ;
F_56 ( V_99 , V_149 , & V_141 ,
V_91 -> V_145 ) ;
}
if ( V_91 -> V_150 && V_91 -> V_92 == V_113 ) {
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_141 . V_146 . V_147 = V_91 -> V_151 ;
F_56 ( V_99 , V_152 , & V_141 ,
V_91 -> V_150 ) ;
}
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_141 . V_153 . V_154 = V_155 ;
if ( V_91 -> V_38 && V_91 -> V_92 == V_113 ) {
memcpy ( V_141 . V_153 . V_156 , V_91 -> V_38 , V_87 ) ;
memcpy ( V_2 -> V_157 . V_67 , V_91 -> V_38 , V_87 ) ;
V_2 -> V_157 . V_66 = true ;
}
F_56 ( V_99 , V_158 , & V_141 , NULL ) ;
}
#endif
if ( ! V_91 -> V_95 && ( V_91 -> V_92 == V_113 ) ) {
F_57 ( ! F_4 ( V_2 -> V_7 ) -> V_52 -> V_129 ) ;
V_91 -> V_95 = F_28 ( V_2 -> V_7 , NULL , V_91 -> V_38 ,
V_2 -> V_36 , V_2 -> V_37 ,
V_2 -> V_96 ,
V_159 ) ;
if ( V_91 -> V_95 )
F_58 ( F_59 ( V_91 -> V_95 ) ) ;
}
if ( V_2 -> V_130 ) {
F_49 ( V_2 -> V_130 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_130 -> V_131 ) ;
V_2 -> V_130 = NULL ;
}
if ( V_91 -> V_92 != V_113 ) {
F_60 ( V_2 -> V_111 ) ;
V_2 -> V_111 = NULL ;
V_2 -> V_37 = 0 ;
V_2 -> V_160 = 0 ;
if ( V_91 -> V_95 ) {
F_49 ( F_59 ( V_91 -> V_95 ) ) ;
F_32 ( V_2 -> V_7 , V_91 -> V_95 ) ;
}
F_1 ( V_2 ) ;
return;
}
if ( F_14 ( ! V_91 -> V_95 ) )
return;
V_2 -> V_130 = F_59 ( V_91 -> V_95 ) ;
if ( ! ( V_2 -> V_7 -> V_33 & V_161 ) )
F_61 ( V_2 ) ;
F_62 () ;
V_139 = F_63 ( V_91 -> V_95 , V_162 ) ;
if ( ! V_139 ) {
F_64 () ;
return;
}
V_139 = F_44 ( V_139 , 2 + V_139 [ 1 ] , V_163 ) ;
F_64 () ;
if ( ! V_139 )
return;
F_65 ( V_2 -> V_7 , V_91 -> V_95 -> V_16 -> V_22 ,
V_139 + 2 , V_139 [ 1 ] ) ;
F_2 ( V_139 ) ;
}
void F_66 ( struct V_98 * V_99 ,
struct V_90 * V_15 ,
T_4 V_164 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_165 * V_166 ;
unsigned long V_33 ;
T_1 * V_167 ;
if ( V_15 -> V_95 ) {
struct V_168 * V_169 = F_59 ( V_15 -> V_95 ) ;
if ( F_14 ( F_67 ( & V_169 -> V_170 ) ) ) {
F_32 ( V_2 -> V_7 , V_15 -> V_95 ) ;
return;
}
}
V_166 = F_8 ( sizeof( * V_166 ) + ( V_15 -> V_38 ? V_87 : 0 ) +
V_15 -> V_148 + V_15 -> V_151 +
V_15 -> V_171 + V_15 -> V_172 +
( V_15 -> V_173 ? V_174 : 0 ) , V_164 ) ;
if ( ! V_166 ) {
F_32 ( V_2 -> V_7 , V_15 -> V_95 ) ;
return;
}
V_166 -> type = V_175 ;
V_167 = ( ( T_1 * ) V_166 ) + sizeof( * V_166 ) ;
if ( V_15 -> V_38 ) {
V_166 -> V_91 . V_38 = V_167 ;
memcpy ( ( void * ) V_166 -> V_91 . V_38 , V_15 -> V_38 , V_87 ) ;
V_167 += V_87 ;
}
if ( V_15 -> V_148 ) {
V_166 -> V_91 . V_145 = V_167 ;
V_166 -> V_91 . V_148 = V_15 -> V_148 ;
memcpy ( ( void * ) V_166 -> V_91 . V_145 , V_15 -> V_145 ,
V_15 -> V_148 ) ;
V_167 += V_15 -> V_148 ;
}
if ( V_15 -> V_151 ) {
V_166 -> V_91 . V_150 = V_167 ;
V_166 -> V_91 . V_151 = V_15 -> V_151 ;
memcpy ( ( void * ) V_166 -> V_91 . V_150 , V_15 -> V_150 ,
V_15 -> V_151 ) ;
V_167 += V_15 -> V_151 ;
}
if ( V_15 -> V_171 ) {
V_166 -> V_91 . V_176 = V_167 ;
V_166 -> V_91 . V_171 = V_15 -> V_171 ;
memcpy ( ( void * ) V_166 -> V_91 . V_176 , V_15 -> V_176 ,
V_15 -> V_171 ) ;
V_167 += V_15 -> V_171 ;
}
if ( V_15 -> V_172 ) {
V_166 -> V_91 . V_177 = V_167 ;
V_166 -> V_91 . V_172 = V_15 -> V_172 ;
memcpy ( ( void * ) V_166 -> V_91 . V_177 , V_15 -> V_177 , V_15 -> V_172 ) ;
V_167 += V_15 -> V_172 ;
}
if ( V_15 -> V_173 ) {
V_166 -> V_91 . V_173 = V_167 ;
memcpy ( ( void * ) V_166 -> V_91 . V_173 , V_15 -> V_173 , V_174 ) ;
V_167 += V_174 ;
}
V_166 -> V_91 . V_178 = V_15 -> V_178 ;
if ( V_15 -> V_178 )
V_166 -> V_91 . V_179 = V_15 -> V_179 ;
if ( V_15 -> V_95 )
F_58 ( F_59 ( V_15 -> V_95 ) ) ;
V_166 -> V_91 . V_95 = V_15 -> V_95 ;
V_166 -> V_91 . V_92 = V_15 -> V_92 ;
V_166 -> V_91 . V_93 = V_15 -> V_93 ;
F_68 ( & V_2 -> V_180 , V_33 ) ;
F_69 ( & V_166 -> V_170 , & V_2 -> V_181 ) ;
F_70 ( & V_2 -> V_180 , V_33 ) ;
F_71 ( V_182 , & V_6 -> V_183 ) ;
}
void F_72 ( struct V_1 * V_2 ,
struct V_184 * V_185 )
{
#ifdef F_54
union V_140 V_141 ;
#endif
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_142 != V_143 &&
V_2 -> V_142 != V_144 ) )
goto V_136;
if ( F_14 ( ! V_2 -> V_130 ) )
goto V_136;
F_49 ( V_2 -> V_130 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_130 -> V_131 ) ;
V_2 -> V_130 = NULL ;
if ( F_14 ( ! V_185 -> V_95 ) )
return;
F_58 ( F_59 ( V_185 -> V_95 ) ) ;
V_2 -> V_130 = F_59 ( V_185 -> V_95 ) ;
F_73 ( F_4 ( V_2 -> V_7 ) ,
V_2 -> V_43 , V_185 , V_19 ) ;
#ifdef F_54
if ( V_185 -> V_145 ) {
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_141 . V_146 . V_147 = V_185 -> V_148 ;
F_56 ( V_2 -> V_43 , V_149 ,
& V_141 , V_185 -> V_145 ) ;
}
if ( V_185 -> V_150 ) {
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_141 . V_146 . V_147 = V_185 -> V_151 ;
F_56 ( V_2 -> V_43 , V_152 ,
& V_141 , V_185 -> V_150 ) ;
}
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_141 . V_153 . V_154 = V_155 ;
memcpy ( V_141 . V_153 . V_156 , V_185 -> V_95 -> V_38 , V_87 ) ;
memcpy ( V_2 -> V_157 . V_67 , V_185 -> V_95 -> V_38 , V_87 ) ;
V_2 -> V_157 . V_66 = true ;
F_56 ( V_2 -> V_43 , V_158 , & V_141 , NULL ) ;
#endif
return;
V_136:
F_32 ( V_2 -> V_7 , V_185 -> V_95 ) ;
}
void F_74 ( struct V_98 * V_99 , struct V_184 * V_185 ,
T_4 V_164 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_165 * V_166 ;
unsigned long V_33 ;
if ( ! V_185 -> V_95 ) {
V_185 -> V_95 = F_28 ( V_2 -> V_7 , V_185 -> V_16 ,
V_185 -> V_38 , V_2 -> V_36 ,
V_2 -> V_37 ,
V_2 -> V_96 ,
V_159 ) ;
}
if ( F_14 ( ! V_185 -> V_95 ) )
return;
V_166 = F_8 ( sizeof( * V_166 ) + V_185 -> V_148 + V_185 -> V_151 , V_164 ) ;
if ( ! V_166 ) {
F_32 ( V_2 -> V_7 , V_185 -> V_95 ) ;
return;
}
V_166 -> type = V_186 ;
V_166 -> V_187 . V_145 = ( ( T_1 * ) V_166 ) + sizeof( * V_166 ) ;
V_166 -> V_187 . V_148 = V_185 -> V_148 ;
memcpy ( ( void * ) V_166 -> V_187 . V_145 , V_185 -> V_145 , V_185 -> V_148 ) ;
V_166 -> V_187 . V_150 = ( ( T_1 * ) V_166 ) + sizeof( * V_166 ) + V_185 -> V_148 ;
V_166 -> V_187 . V_151 = V_185 -> V_151 ;
memcpy ( ( void * ) V_166 -> V_187 . V_150 , V_185 -> V_150 , V_185 -> V_151 ) ;
V_166 -> V_187 . V_95 = V_185 -> V_95 ;
V_166 -> V_187 . V_188 = V_185 -> V_188 ;
F_68 ( & V_2 -> V_180 , V_33 ) ;
F_69 ( & V_166 -> V_170 , & V_2 -> V_181 ) ;
F_70 ( & V_2 -> V_180 , V_33 ) ;
F_71 ( V_182 , & V_6 -> V_183 ) ;
}
void F_75 ( struct V_98 * V_99 , const T_1 * V_4 ,
T_2 V_68 , T_3 V_134 , bool V_189 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_29 ;
#ifdef F_54
union V_140 V_141 ;
#endif
F_6 ( V_2 ) ;
if ( F_14 ( V_2 -> V_142 != V_143 &&
V_2 -> V_142 != V_144 ) )
return;
if ( V_2 -> V_130 ) {
F_49 ( V_2 -> V_130 ) ;
F_32 ( V_2 -> V_7 , & V_2 -> V_130 -> V_131 ) ;
}
V_2 -> V_130 = NULL ;
V_2 -> V_37 = 0 ;
V_2 -> V_160 = 0 ;
F_76 ( V_6 , V_99 , V_134 , V_4 , V_68 , V_189 ) ;
if ( V_6 -> V_52 -> V_190 && V_6 -> V_191 ) {
V_6 -> V_191 = 0 ;
F_77 ( V_6 , V_2 ) ;
}
if ( V_6 -> V_52 -> V_192 )
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
F_78 ( V_6 , V_99 , V_29 , false , NULL ) ;
F_79 ( V_6 , V_99 , NULL ) ;
#ifdef F_54
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_141 . V_153 . V_154 = V_155 ;
F_56 ( V_99 , V_158 , & V_141 , NULL ) ;
V_2 -> V_157 . V_129 . V_37 = 0 ;
#endif
F_30 ( & V_193 ) ;
}
void F_80 ( struct V_98 * V_99 , T_3 V_134 ,
const T_1 * V_4 , T_2 V_68 ,
bool V_194 , T_4 V_164 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_165 * V_166 ;
unsigned long V_33 ;
V_166 = F_8 ( sizeof( * V_166 ) + V_68 , V_164 ) ;
if ( ! V_166 )
return;
V_166 -> type = V_195 ;
V_166 -> V_196 . V_4 = ( ( T_1 * ) V_166 ) + sizeof( * V_166 ) ;
V_166 -> V_196 . V_68 = V_68 ;
memcpy ( ( void * ) V_166 -> V_196 . V_4 , V_4 , V_68 ) ;
V_166 -> V_196 . V_134 = V_134 ;
V_166 -> V_196 . V_194 = V_194 ;
F_68 ( & V_2 -> V_180 , V_33 ) ;
F_69 ( & V_166 -> V_170 , & V_2 -> V_181 ) ;
F_70 ( & V_2 -> V_180 , V_33 ) ;
F_71 ( V_182 , & V_6 -> V_183 ) ;
}
int F_81 ( struct V_5 * V_6 ,
struct V_98 * V_99 ,
struct V_46 * V_129 ,
struct V_197 * V_198 ,
const T_1 * V_67 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
int V_11 ;
F_6 ( V_2 ) ;
if ( V_2 -> V_37 &&
( V_2 -> V_37 != V_129 -> V_37 ||
memcmp ( V_2 -> V_36 , V_129 -> V_36 , V_2 -> V_37 ) ) )
return - V_199 ;
if ( V_2 -> V_130 ) {
if ( ! V_67 )
return - V_199 ;
if ( ! F_82 ( V_67 , V_2 -> V_130 -> V_131 . V_38 ) )
return - V_62 ;
}
if ( V_2 -> V_111 )
return - V_132 ;
F_83 ( & V_129 -> V_74 ,
V_6 -> V_7 . V_200 ) ;
if ( V_198 && V_198 -> V_201 >= 0 ) {
int V_202 ;
T_5 V_203 ;
V_202 = V_198 -> V_201 ;
V_203 = V_198 -> V_15 [ V_202 ] . V_203 ;
if ( V_203 == V_204 ||
V_203 == V_205 ) {
V_129 -> V_59 = V_202 ;
V_129 -> V_57 = V_198 -> V_15 [ V_202 ] . V_57 ;
V_129 -> V_58 = V_198 -> V_15 [ V_202 ] . V_58 ;
if ( V_129 -> V_72 . V_206 == 0 )
V_129 -> V_72 . V_206 = V_203 ;
if ( V_129 -> V_72 . V_207 == 0 ) {
V_129 -> V_72 . V_207 = 1 ;
V_129 -> V_72 . V_208 [ 0 ] = V_203 ;
}
}
V_129 -> V_72 . V_209 = V_198 -> V_15 ;
V_129 -> V_72 . V_210 = V_198 -> V_201 ;
} else {
if ( F_14 ( V_198 ) )
return - V_26 ;
}
V_2 -> V_111 = V_198 ;
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
if ( ! V_2 -> V_130 )
V_2 -> V_37 = 0 ;
return V_11 ;
}
return 0 ;
}
int F_85 ( struct V_5 * V_6 ,
struct V_98 * V_99 , T_3 V_134 , bool V_138 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
int V_11 = 0 ;
F_6 ( V_2 ) ;
F_60 ( V_2 -> V_111 ) ;
V_2 -> V_111 = NULL ;
V_2 -> V_160 = 0 ;
if ( V_2 -> V_3 )
V_11 = F_50 ( V_2 , V_134 ) ;
else if ( ! V_6 -> V_52 -> V_214 )
F_86 ( V_6 , V_99 ) ;
else if ( V_2 -> V_37 )
V_11 = F_87 ( V_6 , V_99 , V_134 ) ;
if ( ! V_2 -> V_130 )
V_2 -> V_37 = 0 ;
return V_11 ;
}
void F_88 ( struct V_83 * V_84 )
{
struct V_1 * V_2 =
F_19 ( V_84 , struct V_1 , V_215 ) ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
F_22 ( V_2 ) ;
if ( V_2 -> V_160 ) {
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
