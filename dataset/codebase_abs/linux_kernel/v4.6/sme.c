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
V_9 -> V_2 = V_2 ;
V_9 -> V_7 = & V_6 -> V_7 ;
V_9 -> V_38 = V_39 ;
V_6 -> V_12 = V_9 ;
V_11 = F_9 ( V_6 , V_9 ) ;
if ( ! V_11 ) {
V_2 -> V_3 -> V_40 = V_41 ;
F_10 ( V_6 , V_2 ) ;
F_11 ( V_2 -> V_42 ) ;
} else {
V_6 -> V_12 = NULL ;
F_2 ( V_9 ) ;
}
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_43 * V_15 ;
struct V_44 V_45 = {} ;
int V_11 ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 )
return 0 ;
V_15 = & V_2 -> V_3 -> V_15 ;
switch ( V_2 -> V_3 -> V_40 ) {
case V_41 :
return - V_46 ;
case V_47 :
return F_3 ( V_2 ) ;
case V_48 :
if ( F_13 ( ! V_6 -> V_49 -> V_50 ) )
return - V_51 ;
V_2 -> V_3 -> V_40 = V_52 ;
return F_14 ( V_6 , V_2 -> V_42 ,
V_15 -> V_16 , V_15 -> V_53 ,
V_15 -> V_54 ,
V_15 -> V_36 , V_15 -> V_37 ,
NULL , 0 ,
V_15 -> V_55 , V_15 -> V_56 ,
V_15 -> V_57 , NULL , 0 ) ;
case V_58 :
return - V_59 ;
case V_60 :
if ( F_13 ( ! V_6 -> V_49 -> V_61 ) )
return - V_51 ;
V_2 -> V_3 -> V_40 = V_62 ;
if ( V_2 -> V_3 -> V_63 )
V_45 . V_64 = V_2 -> V_3 -> V_64 ;
V_45 . V_4 = V_15 -> V_4 ;
V_45 . V_65 = V_15 -> V_65 ;
V_45 . V_66 = V_15 -> V_67 != V_68 ;
V_45 . V_69 = V_15 -> V_69 ;
V_45 . V_33 = V_15 -> V_33 ;
V_45 . V_70 = V_15 -> V_70 ;
V_45 . V_71 = V_15 -> V_71 ;
V_45 . V_72 = V_15 -> V_72 ;
V_45 . V_73 = V_15 -> V_73 ;
V_11 = F_15 ( V_6 , V_2 -> V_42 , V_15 -> V_16 ,
V_15 -> V_54 , V_15 -> V_36 ,
V_15 -> V_37 , & V_45 ) ;
if ( V_11 )
F_16 ( V_6 , V_2 -> V_42 , V_15 -> V_54 ,
NULL , 0 ,
V_74 ,
false ) ;
return V_11 ;
case V_75 :
F_16 ( V_6 , V_2 -> V_42 , V_15 -> V_54 ,
NULL , 0 ,
V_74 , false ) ;
return - V_59 ;
case V_76 :
F_16 ( V_6 , V_2 -> V_42 , V_15 -> V_54 ,
NULL , 0 ,
V_74 , false ) ;
F_1 ( V_2 ) ;
return 0 ;
default:
return 0 ;
}
}
void F_17 ( struct V_77 * V_78 )
{
struct V_5 * V_6 =
F_18 ( V_78 , struct V_5 , V_79 ) ;
struct V_1 * V_2 ;
T_1 V_80 [ V_81 ] , * V_54 = NULL ;
F_19 () ;
F_20 (wdev, &rdev->wdev_list, list) {
if ( ! V_2 -> V_42 )
continue;
F_21 ( V_2 ) ;
if ( ! F_22 ( V_2 -> V_42 ) ) {
F_23 ( V_2 ) ;
continue;
}
if ( ! V_2 -> V_3 ||
V_2 -> V_3 -> V_40 == V_82 ) {
F_23 ( V_2 ) ;
continue;
}
if ( V_2 -> V_3 -> V_15 . V_54 ) {
memcpy ( V_80 , V_2 -> V_3 -> V_15 . V_54 , V_81 ) ;
V_54 = V_80 ;
}
if ( F_12 ( V_2 ) ) {
F_24 (
V_2 -> V_42 , V_54 ,
NULL , 0 , NULL , 0 ,
V_83 ,
false , NULL ) ;
}
F_23 ( V_2 ) ;
}
F_25 () ;
}
static struct V_84 * F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_84 * V_85 ;
F_6 ( V_2 ) ;
V_85 = F_27 ( V_2 -> V_7 , V_2 -> V_3 -> V_15 . V_16 ,
V_2 -> V_3 -> V_15 . V_54 ,
V_2 -> V_3 -> V_15 . V_36 ,
V_2 -> V_3 -> V_15 . V_37 ,
V_2 -> V_86 ,
F_28 ( V_2 -> V_3 -> V_15 . V_87 ) ) ;
if ( ! V_85 )
return NULL ;
memcpy ( V_2 -> V_3 -> V_54 , V_85 -> V_54 , V_81 ) ;
V_2 -> V_3 -> V_15 . V_54 = V_2 -> V_3 -> V_54 ;
V_2 -> V_3 -> V_15 . V_16 = V_85 -> V_16 ;
V_2 -> V_3 -> V_40 = V_48 ;
F_29 ( & V_6 -> V_79 ) ;
return V_85 ;
}
static void F_30 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_84 * V_85 ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 )
return;
if ( V_2 -> V_3 -> V_40 != V_41 &&
V_2 -> V_3 -> V_40 != V_47 )
return;
V_85 = F_26 ( V_2 ) ;
if ( V_85 )
F_31 ( & V_6 -> V_7 , V_85 ) ;
else
F_29 ( & V_6 -> V_79 ) ;
}
void F_32 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
F_21 ( V_2 ) ;
F_30 ( V_89 ) ;
F_23 ( V_2 ) ;
}
void F_33 ( struct V_1 * V_2 , const T_1 * V_91 , T_2 V_92 )
{
struct V_7 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_93 * V_94 = (struct V_93 * ) V_91 ;
T_3 V_95 = F_34 ( V_94 -> V_96 . V_50 . V_95 ) ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 || V_2 -> V_3 -> V_40 == V_82 )
return;
if ( V_95 == V_97 &&
V_2 -> V_3 -> V_98 &&
V_2 -> V_3 -> V_15 . V_53 != V_99 ) {
switch ( V_2 -> V_3 -> V_15 . V_53 ) {
case V_100 :
if ( V_2 -> V_101 )
V_2 -> V_3 -> V_15 . V_53 =
V_102 ;
else
V_2 -> V_3 -> V_15 . V_53 =
V_99 ;
break;
case V_102 :
V_2 -> V_3 -> V_15 . V_53 =
V_99 ;
break;
default:
V_2 -> V_3 -> V_15 . V_53 =
V_100 ;
break;
}
V_2 -> V_3 -> V_40 = V_48 ;
F_29 ( & V_6 -> V_79 ) ;
} else if ( V_95 != V_103 ) {
F_24 ( V_2 -> V_42 , V_94 -> V_54 ,
NULL , 0 , NULL , 0 ,
V_95 , false , NULL ) ;
} else if ( V_2 -> V_3 -> V_40 == V_52 ) {
V_2 -> V_3 -> V_40 = V_60 ;
F_29 ( & V_6 -> V_79 ) ;
}
}
bool F_35 ( struct V_1 * V_2 , T_3 V_104 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return false ;
if ( V_104 == V_103 ) {
V_2 -> V_3 -> V_40 = V_82 ;
return false ;
}
if ( V_2 -> V_3 -> V_63 ) {
V_2 -> V_3 -> V_63 = false ;
V_2 -> V_3 -> V_40 = V_60 ;
F_29 ( & V_6 -> V_79 ) ;
return true ;
}
V_2 -> V_3 -> V_40 = V_75 ;
F_29 ( & V_6 -> V_79 ) ;
return false ;
}
void F_36 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_40 = V_58 ;
F_29 ( & V_6 -> V_79 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_40 = V_76 ;
F_29 ( & V_6 -> V_79 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_40 = V_75 ;
F_29 ( & V_6 -> V_79 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
const T_1 * V_105 , T_2 V_106 ,
const T_1 * * V_107 , T_2 * V_108 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
T_1 * V_91 ;
T_2 V_109 ;
if ( ! V_6 -> V_7 . V_110 ||
( V_105 && F_41 ( V_111 , V_105 , V_106 ) ) ) {
* V_107 = F_42 ( V_105 , V_106 , V_19 ) ;
if ( ! * V_107 )
return - V_20 ;
* V_108 = V_106 ;
return 0 ;
}
V_91 = F_43 ( V_106 + V_6 -> V_7 . V_110 + 2 ,
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
V_109 = F_44 ( V_105 , V_106 , V_112 ,
F_45 ( V_112 ) , 0 ) ;
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
static int F_46 ( struct V_1 * V_2 ,
struct V_43 * V_120 ,
const T_1 * V_64 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_84 * V_85 ;
int V_11 ;
if ( ! V_6 -> V_49 -> V_50 || ! V_6 -> V_49 -> V_61 )
return - V_51 ;
if ( V_2 -> V_121 )
return - V_122 ;
if ( F_13 ( V_2 -> V_3 ) )
return - V_123 ;
V_2 -> V_3 = F_8 ( sizeof( * V_2 -> V_3 ) , V_19 ) ;
if ( ! V_2 -> V_3 )
return - V_20 ;
memcpy ( & V_2 -> V_3 -> V_15 , V_120 , sizeof( * V_120 ) ) ;
if ( V_120 -> V_54 ) {
V_2 -> V_3 -> V_15 . V_54 = V_2 -> V_3 -> V_54 ;
memcpy ( V_2 -> V_3 -> V_54 , V_120 -> V_54 , V_81 ) ;
}
if ( F_40 ( V_2 , V_120 -> V_4 , V_120 -> V_65 ,
& V_2 -> V_3 -> V_4 ,
& V_2 -> V_3 -> V_15 . V_65 ) ) {
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return - V_20 ;
}
V_2 -> V_3 -> V_15 . V_4 = V_2 -> V_3 -> V_4 ;
if ( V_120 -> V_53 == V_124 ) {
V_2 -> V_3 -> V_98 = true ;
V_2 -> V_3 -> V_15 . V_53 =
V_100 ;
} else {
V_2 -> V_3 -> V_98 = false ;
}
V_2 -> V_3 -> V_15 . V_36 = V_2 -> V_36 ;
V_2 -> V_3 -> V_15 . V_37 = V_2 -> V_37 ;
V_85 = F_26 ( V_2 ) ;
if ( V_64 ) {
memcpy ( V_2 -> V_3 -> V_64 , V_64 , V_81 ) ;
V_2 -> V_3 -> V_63 = true ;
}
if ( V_85 ) {
V_11 = F_12 ( V_2 ) ;
F_31 ( V_2 -> V_7 , V_85 ) ;
} else {
V_11 = F_3 ( V_2 ) ;
if ( V_11 == - V_14 ) {
V_11 = 0 ;
V_2 -> V_3 -> V_40 = V_47 ;
}
}
if ( V_11 )
F_1 ( V_2 ) ;
return V_11 ;
}
static int F_47 ( struct V_1 * V_2 , T_3 V_125 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_11 ;
if ( ! V_2 -> V_3 )
return 0 ;
if ( ! V_6 -> V_49 -> V_126 )
return - V_51 ;
if ( V_2 -> V_3 -> V_40 == V_41 ||
V_2 -> V_3 -> V_40 == V_47 ) {
V_11 = 0 ;
goto V_127;
}
V_11 = F_16 ( V_6 , V_2 -> V_42 ,
V_2 -> V_3 -> V_15 . V_54 ,
NULL , 0 , V_125 , false ) ;
V_127:
F_1 ( V_2 ) ;
return V_11 ;
}
static bool F_48 ( void )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
bool V_128 = true ;
F_20 (rdev, &cfg80211_rdev_list, list) {
F_20 (wdev, &rdev->wdev_list, list) {
F_21 ( V_2 ) ;
if ( V_2 -> V_3 || V_2 -> V_121 )
V_128 = false ;
F_23 ( V_2 ) ;
}
}
return V_128 ;
}
static void F_49 ( struct V_77 * V_78 )
{
F_19 () ;
if ( F_48 () )
F_50 () ;
F_25 () ;
}
void F_24 ( struct V_88 * V_89 , const T_1 * V_54 ,
const T_1 * V_129 , T_2 V_130 ,
const T_1 * V_131 , T_2 V_132 ,
T_3 V_104 , bool V_133 ,
struct V_84 * V_85 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
const T_1 * V_134 ;
#ifdef F_51
union V_135 V_136 ;
#endif
F_6 ( V_2 ) ;
if ( F_13 ( V_2 -> V_137 != V_138 &&
V_2 -> V_137 != V_139 ) ) {
F_31 ( V_2 -> V_7 , V_85 ) ;
return;
}
F_52 ( F_4 ( V_2 -> V_7 ) , V_89 ,
V_54 , V_129 , V_130 ,
V_131 , V_132 ,
V_104 , V_19 ) ;
#ifdef F_51
if ( V_133 ) {
if ( V_129 && V_104 == V_103 ) {
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_140 . V_141 = V_130 ;
F_53 ( V_89 , V_142 , & V_136 , V_129 ) ;
}
if ( V_131 && V_104 == V_103 ) {
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_140 . V_141 = V_132 ;
F_53 ( V_89 , V_143 , & V_136 , V_131 ) ;
}
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_144 . V_145 = V_146 ;
if ( V_54 && V_104 == V_103 ) {
memcpy ( V_136 . V_144 . V_147 , V_54 , V_81 ) ;
memcpy ( V_2 -> V_148 . V_64 , V_54 , V_81 ) ;
V_2 -> V_148 . V_63 = true ;
}
F_53 ( V_89 , V_149 , & V_136 , NULL ) ;
}
#endif
if ( ! V_85 && ( V_104 == V_103 ) ) {
F_54 ( ! F_4 ( V_2 -> V_7 ) -> V_49 -> V_120 ) ;
V_85 = F_27 ( V_2 -> V_7 , NULL , V_54 ,
V_2 -> V_36 , V_2 -> V_37 ,
V_2 -> V_86 ,
V_150 ) ;
if ( V_85 )
F_55 ( F_56 ( V_85 ) ) ;
}
if ( V_2 -> V_121 ) {
F_57 ( V_2 -> V_121 ) ;
F_31 ( V_2 -> V_7 , & V_2 -> V_121 -> V_151 ) ;
V_2 -> V_121 = NULL ;
}
if ( V_104 != V_103 ) {
F_58 ( V_2 -> V_101 ) ;
V_2 -> V_101 = NULL ;
V_2 -> V_37 = 0 ;
if ( V_85 ) {
F_57 ( F_56 ( V_85 ) ) ;
F_31 ( V_2 -> V_7 , V_85 ) ;
}
F_1 ( V_2 ) ;
return;
}
if ( F_13 ( ! V_85 ) )
return;
V_2 -> V_121 = F_56 ( V_85 ) ;
F_59 ( V_2 ) ;
F_60 () ;
V_134 = F_61 ( V_85 , V_152 ) ;
if ( ! V_134 ) {
F_62 () ;
return;
}
V_134 = F_42 ( V_134 , 2 + V_134 [ 1 ] , V_153 ) ;
F_62 () ;
if ( ! V_134 )
return;
F_63 ( V_2 -> V_7 , V_85 -> V_16 -> V_22 ,
V_134 + 2 , V_134 [ 1 ] ) ;
F_2 ( V_134 ) ;
}
void F_64 ( struct V_88 * V_89 , const T_1 * V_54 ,
const T_1 * V_129 , T_2 V_130 ,
const T_1 * V_131 , T_2 V_132 ,
T_3 V_104 , T_4 V_154 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_155 * V_156 ;
unsigned long V_33 ;
V_156 = F_8 ( sizeof( * V_156 ) + V_130 + V_132 , V_154 ) ;
if ( ! V_156 )
return;
V_156 -> type = V_157 ;
if ( V_54 )
memcpy ( V_156 -> V_158 . V_54 , V_54 , V_81 ) ;
if ( V_130 ) {
V_156 -> V_158 . V_129 = ( ( T_1 * ) V_156 ) + sizeof( * V_156 ) ;
V_156 -> V_158 . V_130 = V_130 ;
memcpy ( ( void * ) V_156 -> V_158 . V_129 , V_129 , V_130 ) ;
}
if ( V_132 ) {
V_156 -> V_158 . V_131 = ( ( T_1 * ) V_156 ) + sizeof( * V_156 ) + V_130 ;
V_156 -> V_158 . V_132 = V_132 ;
memcpy ( ( void * ) V_156 -> V_158 . V_131 , V_131 , V_132 ) ;
}
V_156 -> V_158 . V_104 = V_104 ;
F_65 ( & V_2 -> V_159 , V_33 ) ;
F_66 ( & V_156 -> V_160 , & V_2 -> V_161 ) ;
F_67 ( & V_2 -> V_159 , V_33 ) ;
F_68 ( V_162 , & V_6 -> V_163 ) ;
}
void F_69 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
const T_1 * V_129 , T_2 V_130 ,
const T_1 * V_131 , T_2 V_132 )
{
#ifdef F_51
union V_135 V_136 ;
#endif
F_6 ( V_2 ) ;
if ( F_13 ( V_2 -> V_137 != V_138 &&
V_2 -> V_137 != V_139 ) )
goto V_127;
if ( F_13 ( ! V_2 -> V_121 ) )
goto V_127;
F_57 ( V_2 -> V_121 ) ;
F_31 ( V_2 -> V_7 , & V_2 -> V_121 -> V_151 ) ;
V_2 -> V_121 = NULL ;
F_55 ( F_56 ( V_85 ) ) ;
V_2 -> V_121 = F_56 ( V_85 ) ;
F_70 ( F_4 ( V_2 -> V_7 ) ,
V_2 -> V_42 , V_85 -> V_54 ,
V_129 , V_130 , V_131 , V_132 ,
V_19 ) ;
#ifdef F_51
if ( V_129 ) {
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_140 . V_141 = V_130 ;
F_53 ( V_2 -> V_42 , V_142 ,
& V_136 , V_129 ) ;
}
if ( V_131 ) {
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_140 . V_141 = V_132 ;
F_53 ( V_2 -> V_42 , V_143 ,
& V_136 , V_131 ) ;
}
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_144 . V_145 = V_146 ;
memcpy ( V_136 . V_144 . V_147 , V_85 -> V_54 , V_81 ) ;
memcpy ( V_2 -> V_148 . V_64 , V_85 -> V_54 , V_81 ) ;
V_2 -> V_148 . V_63 = true ;
F_53 ( V_2 -> V_42 , V_149 , & V_136 , NULL ) ;
#endif
return;
V_127:
F_31 ( V_2 -> V_7 , V_85 ) ;
}
void F_71 ( struct V_88 * V_89 ,
struct V_31 * V_16 ,
const T_1 * V_54 ,
const T_1 * V_129 , T_2 V_130 ,
const T_1 * V_131 , T_2 V_132 , T_4 V_154 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
struct V_84 * V_85 ;
V_85 = F_27 ( V_2 -> V_7 , V_16 , V_54 , V_2 -> V_36 ,
V_2 -> V_37 ,
V_2 -> V_86 , V_150 ) ;
if ( F_13 ( ! V_85 ) )
return;
F_72 ( V_89 , V_85 , V_129 , V_130 , V_131 ,
V_132 , V_154 ) ;
}
void F_72 ( struct V_88 * V_89 ,
struct V_84 * V_85 , const T_1 * V_129 ,
T_2 V_130 , const T_1 * V_131 ,
T_2 V_132 , T_4 V_154 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_155 * V_156 ;
unsigned long V_33 ;
if ( F_13 ( ! V_85 ) )
return;
V_156 = F_8 ( sizeof( * V_156 ) + V_130 + V_132 , V_154 ) ;
if ( ! V_156 ) {
F_31 ( V_2 -> V_7 , V_85 ) ;
return;
}
V_156 -> type = V_164 ;
V_156 -> V_165 . V_129 = ( ( T_1 * ) V_156 ) + sizeof( * V_156 ) ;
V_156 -> V_165 . V_130 = V_130 ;
memcpy ( ( void * ) V_156 -> V_165 . V_129 , V_129 , V_130 ) ;
V_156 -> V_165 . V_131 = ( ( T_1 * ) V_156 ) + sizeof( * V_156 ) + V_130 ;
V_156 -> V_165 . V_132 = V_132 ;
memcpy ( ( void * ) V_156 -> V_165 . V_131 , V_131 , V_132 ) ;
V_156 -> V_165 . V_85 = V_85 ;
F_65 ( & V_2 -> V_159 , V_33 ) ;
F_66 ( & V_156 -> V_160 , & V_2 -> V_161 ) ;
F_67 ( & V_2 -> V_159 , V_33 ) ;
F_68 ( V_162 , & V_6 -> V_163 ) ;
}
void F_73 ( struct V_88 * V_89 , const T_1 * V_4 ,
T_2 V_65 , T_3 V_125 , bool V_166 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_29 ;
#ifdef F_51
union V_135 V_136 ;
#endif
F_6 ( V_2 ) ;
if ( F_13 ( V_2 -> V_137 != V_138 &&
V_2 -> V_137 != V_139 ) )
return;
if ( V_2 -> V_121 ) {
F_57 ( V_2 -> V_121 ) ;
F_31 ( V_2 -> V_7 , & V_2 -> V_121 -> V_151 ) ;
}
V_2 -> V_121 = NULL ;
V_2 -> V_37 = 0 ;
F_74 ( V_6 , V_89 , V_125 , V_4 , V_65 , V_166 ) ;
if ( V_6 -> V_49 -> V_167 && V_6 -> V_168 ) {
V_6 -> V_168 = 0 ;
F_75 ( V_6 , V_2 ) ;
}
if ( V_6 -> V_49 -> V_169 )
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
F_76 ( V_6 , V_89 , V_29 , false , NULL ) ;
F_77 ( V_6 , V_89 , NULL ) ;
#ifdef F_51
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_144 . V_145 = V_146 ;
F_53 ( V_89 , V_149 , & V_136 , NULL ) ;
V_2 -> V_148 . V_120 . V_37 = 0 ;
#endif
F_29 ( & V_170 ) ;
}
void F_78 ( struct V_88 * V_89 , T_3 V_125 ,
const T_1 * V_4 , T_2 V_65 ,
bool V_171 , T_4 V_154 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_155 * V_156 ;
unsigned long V_33 ;
V_156 = F_8 ( sizeof( * V_156 ) + V_65 , V_154 ) ;
if ( ! V_156 )
return;
V_156 -> type = V_172 ;
V_156 -> V_173 . V_4 = ( ( T_1 * ) V_156 ) + sizeof( * V_156 ) ;
V_156 -> V_173 . V_65 = V_65 ;
memcpy ( ( void * ) V_156 -> V_173 . V_4 , V_4 , V_65 ) ;
V_156 -> V_173 . V_125 = V_125 ;
V_156 -> V_173 . V_171 = V_171 ;
F_65 ( & V_2 -> V_159 , V_33 ) ;
F_66 ( & V_156 -> V_160 , & V_2 -> V_161 ) ;
F_67 ( & V_2 -> V_159 , V_33 ) ;
F_68 ( V_162 , & V_6 -> V_163 ) ;
}
int F_79 ( struct V_5 * V_6 ,
struct V_88 * V_89 ,
struct V_43 * V_120 ,
struct V_174 * V_175 ,
const T_1 * V_64 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
int V_11 ;
F_6 ( V_2 ) ;
if ( F_13 ( V_2 -> V_101 ) ) {
F_58 ( V_2 -> V_101 ) ;
V_2 -> V_101 = NULL ;
}
F_80 ( & V_120 -> V_71 ,
V_6 -> V_7 . V_176 ) ;
if ( V_175 && V_175 -> V_177 >= 0 ) {
int V_178 ;
T_5 V_179 ;
V_178 = V_175 -> V_177 ;
V_179 = V_175 -> V_15 [ V_178 ] . V_179 ;
if ( V_179 == V_180 ||
V_179 == V_181 ) {
V_120 -> V_57 = V_178 ;
V_120 -> V_55 = V_175 -> V_15 [ V_178 ] . V_55 ;
V_120 -> V_56 = V_175 -> V_15 [ V_178 ] . V_56 ;
if ( V_120 -> V_69 . V_182 == 0 )
V_120 -> V_69 . V_182 = V_179 ;
if ( V_120 -> V_69 . V_183 == 0 ) {
V_120 -> V_69 . V_183 = 1 ;
V_120 -> V_69 . V_184 [ 0 ] = V_179 ;
}
}
}
V_2 -> V_101 = V_175 ;
memcpy ( V_2 -> V_36 , V_120 -> V_36 , V_120 -> V_37 ) ;
V_2 -> V_37 = V_120 -> V_37 ;
V_2 -> V_86 = V_120 -> V_185 ? V_186 :
V_187 ;
if ( ! V_6 -> V_49 -> V_120 )
V_11 = F_46 ( V_2 , V_120 , V_64 ) ;
else
V_11 = F_81 ( V_6 , V_89 , V_120 ) ;
if ( V_11 ) {
V_2 -> V_101 = NULL ;
V_2 -> V_37 = 0 ;
return V_11 ;
}
return 0 ;
}
int F_82 ( struct V_5 * V_6 ,
struct V_88 * V_89 , T_3 V_125 , bool V_133 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
int V_11 = 0 ;
F_6 ( V_2 ) ;
F_58 ( V_2 -> V_101 ) ;
V_2 -> V_101 = NULL ;
if ( V_2 -> V_3 )
V_11 = F_47 ( V_2 , V_125 ) ;
else if ( ! V_6 -> V_49 -> V_188 )
F_83 ( V_6 , V_89 ) ;
else if ( V_2 -> V_121 )
V_11 = F_84 ( V_6 , V_89 , V_125 ) ;
return V_11 ;
}
