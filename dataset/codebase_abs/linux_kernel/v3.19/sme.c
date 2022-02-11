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
T_2 V_86 = V_87 ;
F_6 ( V_2 ) ;
if ( V_2 -> V_3 -> V_15 . V_88 )
V_86 |= V_89 ;
V_85 = F_27 ( V_2 -> V_7 , V_2 -> V_3 -> V_15 . V_16 ,
V_2 -> V_3 -> V_15 . V_54 ,
V_2 -> V_3 -> V_15 . V_36 ,
V_2 -> V_3 -> V_15 . V_37 ,
V_87 | V_89 ,
V_86 ) ;
if ( ! V_85 )
return NULL ;
memcpy ( V_2 -> V_3 -> V_54 , V_85 -> V_54 , V_81 ) ;
V_2 -> V_3 -> V_15 . V_54 = V_2 -> V_3 -> V_54 ;
V_2 -> V_3 -> V_15 . V_16 = V_85 -> V_16 ;
V_2 -> V_3 -> V_40 = V_48 ;
F_28 ( & V_6 -> V_79 ) ;
return V_85 ;
}
static void F_29 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
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
F_30 ( & V_6 -> V_7 , V_85 ) ;
else
F_28 ( & V_6 -> V_79 ) ;
}
void F_31 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
F_21 ( V_2 ) ;
F_29 ( V_91 ) ;
F_23 ( V_2 ) ;
}
void F_32 ( struct V_1 * V_2 , const T_1 * V_93 , T_3 V_94 )
{
struct V_7 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_95 * V_96 = (struct V_95 * ) V_93 ;
T_2 V_97 = F_33 ( V_96 -> V_98 . V_50 . V_97 ) ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 || V_2 -> V_3 -> V_40 == V_82 )
return;
if ( V_97 == V_99 &&
V_2 -> V_3 -> V_100 &&
V_2 -> V_3 -> V_15 . V_53 != V_101 ) {
switch ( V_2 -> V_3 -> V_15 . V_53 ) {
case V_102 :
if ( V_2 -> V_103 )
V_2 -> V_3 -> V_15 . V_53 =
V_104 ;
else
V_2 -> V_3 -> V_15 . V_53 =
V_101 ;
break;
case V_104 :
V_2 -> V_3 -> V_15 . V_53 =
V_101 ;
break;
default:
V_2 -> V_3 -> V_15 . V_53 =
V_102 ;
break;
}
V_2 -> V_3 -> V_40 = V_48 ;
F_28 ( & V_6 -> V_79 ) ;
} else if ( V_97 != V_105 ) {
F_24 ( V_2 -> V_42 , V_96 -> V_54 ,
NULL , 0 , NULL , 0 ,
V_97 , false , NULL ) ;
} else if ( V_2 -> V_3 -> V_40 == V_52 ) {
V_2 -> V_3 -> V_40 = V_60 ;
F_28 ( & V_6 -> V_79 ) ;
}
}
bool F_34 ( struct V_1 * V_2 , T_2 V_106 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return false ;
if ( V_106 == V_105 ) {
V_2 -> V_3 -> V_40 = V_82 ;
return false ;
}
if ( V_2 -> V_3 -> V_63 ) {
V_2 -> V_3 -> V_63 = false ;
V_2 -> V_3 -> V_40 = V_60 ;
F_28 ( & V_6 -> V_79 ) ;
return true ;
}
V_2 -> V_3 -> V_40 = V_75 ;
F_28 ( & V_6 -> V_79 ) ;
return false ;
}
void F_35 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_40 = V_58 ;
F_28 ( & V_6 -> V_79 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_40 = V_76 ;
F_28 ( & V_6 -> V_79 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_40 = V_75 ;
F_28 ( & V_6 -> V_79 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_43 * V_107 ,
const T_1 * V_64 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_84 * V_85 ;
int V_11 ;
if ( ! V_6 -> V_49 -> V_50 || ! V_6 -> V_49 -> V_61 )
return - V_51 ;
if ( V_2 -> V_108 )
return - V_109 ;
if ( F_13 ( V_2 -> V_3 ) )
return - V_110 ;
V_2 -> V_3 = F_8 ( sizeof( * V_2 -> V_3 ) , V_19 ) ;
if ( ! V_2 -> V_3 )
return - V_20 ;
memcpy ( & V_2 -> V_3 -> V_15 , V_107 , sizeof( * V_107 ) ) ;
if ( V_107 -> V_54 ) {
V_2 -> V_3 -> V_15 . V_54 = V_2 -> V_3 -> V_54 ;
memcpy ( V_2 -> V_3 -> V_54 , V_107 -> V_54 , V_81 ) ;
}
if ( V_107 -> V_4 ) {
V_2 -> V_3 -> V_4 = F_40 ( V_107 -> V_4 , V_107 -> V_65 ,
V_19 ) ;
V_2 -> V_3 -> V_15 . V_4 = V_2 -> V_3 -> V_4 ;
if ( ! V_2 -> V_3 -> V_4 ) {
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return - V_20 ;
}
}
if ( V_107 -> V_53 == V_111 ) {
V_2 -> V_3 -> V_100 = true ;
V_2 -> V_3 -> V_15 . V_53 =
V_102 ;
} else {
V_2 -> V_3 -> V_100 = false ;
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
F_30 ( V_2 -> V_7 , V_85 ) ;
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
static int F_41 ( struct V_1 * V_2 , T_2 V_112 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_11 ;
if ( ! V_2 -> V_3 )
return 0 ;
if ( ! V_6 -> V_49 -> V_113 )
return - V_51 ;
if ( V_2 -> V_3 -> V_40 == V_41 ||
V_2 -> V_3 -> V_40 == V_47 ) {
V_11 = 0 ;
goto V_114;
}
V_11 = F_16 ( V_6 , V_2 -> V_42 ,
V_2 -> V_3 -> V_15 . V_54 ,
NULL , 0 , V_112 , false ) ;
V_114:
F_1 ( V_2 ) ;
return V_11 ;
}
static bool F_42 ( void )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
bool V_115 = true ;
F_20 (rdev, &cfg80211_rdev_list, list) {
F_20 (wdev, &rdev->wdev_list, list) {
F_21 ( V_2 ) ;
if ( V_2 -> V_3 || V_2 -> V_108 )
V_115 = false ;
F_23 ( V_2 ) ;
}
}
return V_115 ;
}
static void F_43 ( struct V_77 * V_78 )
{
F_19 () ;
if ( F_42 () )
F_44 () ;
F_25 () ;
}
void F_24 ( struct V_90 * V_91 , const T_1 * V_54 ,
const T_1 * V_116 , T_3 V_117 ,
const T_1 * V_118 , T_3 V_119 ,
T_2 V_106 , bool V_120 ,
struct V_84 * V_85 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
const T_1 * V_121 ;
#ifdef F_45
union V_122 V_123 ;
#endif
F_6 ( V_2 ) ;
if ( F_13 ( V_2 -> V_124 != V_125 &&
V_2 -> V_124 != V_126 ) ) {
F_30 ( V_2 -> V_7 , V_85 ) ;
return;
}
F_46 ( F_4 ( V_2 -> V_7 ) , V_91 ,
V_54 , V_116 , V_117 ,
V_118 , V_119 ,
V_106 , V_19 ) ;
#ifdef F_45
if ( V_120 ) {
if ( V_116 && V_106 == V_105 ) {
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_127 . V_128 = V_117 ;
F_47 ( V_91 , V_129 , & V_123 , V_116 ) ;
}
if ( V_118 && V_106 == V_105 ) {
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_127 . V_128 = V_119 ;
F_47 ( V_91 , V_130 , & V_123 , V_118 ) ;
}
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_131 . V_132 = V_133 ;
if ( V_54 && V_106 == V_105 ) {
memcpy ( V_123 . V_131 . V_134 , V_54 , V_81 ) ;
memcpy ( V_2 -> V_135 . V_64 , V_54 , V_81 ) ;
V_2 -> V_135 . V_63 = true ;
}
F_47 ( V_91 , V_136 , & V_123 , NULL ) ;
}
#endif
if ( ! V_85 && ( V_106 == V_105 ) ) {
F_48 ( ! F_4 ( V_2 -> V_7 ) -> V_49 -> V_107 ) ;
V_85 = F_27 ( V_2 -> V_7 , NULL , V_54 ,
V_2 -> V_36 , V_2 -> V_37 ,
V_87 ,
V_87 ) ;
if ( V_85 )
F_49 ( F_50 ( V_85 ) ) ;
}
if ( V_2 -> V_108 ) {
F_51 ( V_2 -> V_108 ) ;
F_30 ( V_2 -> V_7 , & V_2 -> V_108 -> V_137 ) ;
V_2 -> V_108 = NULL ;
}
if ( V_106 != V_105 ) {
F_52 ( V_2 -> V_103 ) ;
V_2 -> V_103 = NULL ;
V_2 -> V_37 = 0 ;
if ( V_85 ) {
F_51 ( F_50 ( V_85 ) ) ;
F_30 ( V_2 -> V_7 , V_85 ) ;
}
F_1 ( V_2 ) ;
return;
}
if ( F_13 ( ! V_85 ) )
return;
V_2 -> V_108 = F_50 ( V_85 ) ;
F_53 ( V_2 ) ;
F_54 () ;
V_121 = F_55 ( V_85 , V_138 ) ;
if ( ! V_121 ) {
F_56 () ;
return;
}
V_121 = F_40 ( V_121 , 2 + V_121 [ 1 ] , V_139 ) ;
F_56 () ;
if ( ! V_121 )
return;
F_57 ( V_2 -> V_7 , V_85 -> V_16 -> V_22 ,
V_121 + 2 , V_121 [ 1 ] ) ;
F_2 ( V_121 ) ;
}
void F_58 ( struct V_90 * V_91 , const T_1 * V_54 ,
const T_1 * V_116 , T_3 V_117 ,
const T_1 * V_118 , T_3 V_119 ,
T_2 V_106 , T_4 V_140 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_141 * V_142 ;
unsigned long V_33 ;
V_142 = F_8 ( sizeof( * V_142 ) + V_117 + V_119 , V_140 ) ;
if ( ! V_142 )
return;
V_142 -> type = V_143 ;
if ( V_54 )
memcpy ( V_142 -> V_144 . V_54 , V_54 , V_81 ) ;
if ( V_117 ) {
V_142 -> V_144 . V_116 = ( ( T_1 * ) V_142 ) + sizeof( * V_142 ) ;
V_142 -> V_144 . V_117 = V_117 ;
memcpy ( ( void * ) V_142 -> V_144 . V_116 , V_116 , V_117 ) ;
}
if ( V_119 ) {
V_142 -> V_144 . V_118 = ( ( T_1 * ) V_142 ) + sizeof( * V_142 ) + V_117 ;
V_142 -> V_144 . V_119 = V_119 ;
memcpy ( ( void * ) V_142 -> V_144 . V_118 , V_118 , V_119 ) ;
}
V_142 -> V_144 . V_106 = V_106 ;
F_59 ( & V_2 -> V_145 , V_33 ) ;
F_60 ( & V_142 -> V_146 , & V_2 -> V_147 ) ;
F_61 ( & V_2 -> V_145 , V_33 ) ;
F_62 ( V_148 , & V_6 -> V_149 ) ;
}
void F_63 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
const T_1 * V_116 , T_3 V_117 ,
const T_1 * V_118 , T_3 V_119 )
{
#ifdef F_45
union V_122 V_123 ;
#endif
F_6 ( V_2 ) ;
if ( F_13 ( V_2 -> V_124 != V_125 &&
V_2 -> V_124 != V_126 ) )
goto V_114;
if ( F_13 ( ! V_2 -> V_108 ) )
goto V_114;
F_51 ( V_2 -> V_108 ) ;
F_30 ( V_2 -> V_7 , & V_2 -> V_108 -> V_137 ) ;
V_2 -> V_108 = NULL ;
F_49 ( F_50 ( V_85 ) ) ;
V_2 -> V_108 = F_50 ( V_85 ) ;
F_64 ( F_4 ( V_2 -> V_7 ) ,
V_2 -> V_42 , V_85 -> V_54 ,
V_116 , V_117 , V_118 , V_119 ,
V_19 ) ;
#ifdef F_45
if ( V_116 ) {
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_127 . V_128 = V_117 ;
F_47 ( V_2 -> V_42 , V_129 ,
& V_123 , V_116 ) ;
}
if ( V_118 ) {
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_127 . V_128 = V_119 ;
F_47 ( V_2 -> V_42 , V_130 ,
& V_123 , V_118 ) ;
}
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_131 . V_132 = V_133 ;
memcpy ( V_123 . V_131 . V_134 , V_85 -> V_54 , V_81 ) ;
memcpy ( V_2 -> V_135 . V_64 , V_85 -> V_54 , V_81 ) ;
V_2 -> V_135 . V_63 = true ;
F_47 ( V_2 -> V_42 , V_136 , & V_123 , NULL ) ;
#endif
return;
V_114:
F_30 ( V_2 -> V_7 , V_85 ) ;
}
void F_65 ( struct V_90 * V_91 ,
struct V_31 * V_16 ,
const T_1 * V_54 ,
const T_1 * V_116 , T_3 V_117 ,
const T_1 * V_118 , T_3 V_119 , T_4 V_140 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
struct V_84 * V_85 ;
V_85 = F_27 ( V_2 -> V_7 , V_16 , V_54 , V_2 -> V_36 ,
V_2 -> V_37 , V_87 ,
V_87 ) ;
if ( F_13 ( ! V_85 ) )
return;
F_66 ( V_91 , V_85 , V_116 , V_117 , V_118 ,
V_119 , V_140 ) ;
}
void F_66 ( struct V_90 * V_91 ,
struct V_84 * V_85 , const T_1 * V_116 ,
T_3 V_117 , const T_1 * V_118 ,
T_3 V_119 , T_4 V_140 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_141 * V_142 ;
unsigned long V_33 ;
if ( F_13 ( ! V_85 ) )
return;
V_142 = F_8 ( sizeof( * V_142 ) + V_117 + V_119 , V_140 ) ;
if ( ! V_142 ) {
F_30 ( V_2 -> V_7 , V_85 ) ;
return;
}
V_142 -> type = V_150 ;
V_142 -> V_151 . V_116 = ( ( T_1 * ) V_142 ) + sizeof( * V_142 ) ;
V_142 -> V_151 . V_117 = V_117 ;
memcpy ( ( void * ) V_142 -> V_151 . V_116 , V_116 , V_117 ) ;
V_142 -> V_151 . V_118 = ( ( T_1 * ) V_142 ) + sizeof( * V_142 ) + V_117 ;
V_142 -> V_151 . V_119 = V_119 ;
memcpy ( ( void * ) V_142 -> V_151 . V_118 , V_118 , V_119 ) ;
V_142 -> V_151 . V_85 = V_85 ;
F_59 ( & V_2 -> V_145 , V_33 ) ;
F_60 ( & V_142 -> V_146 , & V_2 -> V_147 ) ;
F_61 ( & V_2 -> V_145 , V_33 ) ;
F_62 ( V_148 , & V_6 -> V_149 ) ;
}
void F_67 ( struct V_90 * V_91 , const T_1 * V_4 ,
T_3 V_65 , T_2 V_112 , bool V_152 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_29 ;
#ifdef F_45
union V_122 V_123 ;
#endif
F_6 ( V_2 ) ;
if ( F_13 ( V_2 -> V_124 != V_125 &&
V_2 -> V_124 != V_126 ) )
return;
if ( V_2 -> V_108 ) {
F_51 ( V_2 -> V_108 ) ;
F_30 ( V_2 -> V_7 , & V_2 -> V_108 -> V_137 ) ;
}
V_2 -> V_108 = NULL ;
V_2 -> V_37 = 0 ;
F_68 ( V_6 , V_91 , V_112 , V_4 , V_65 , V_152 ) ;
if ( V_6 -> V_49 -> V_153 )
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
F_69 ( V_6 , V_91 , V_29 , false , NULL ) ;
F_70 ( V_6 , V_91 , NULL ) ;
#ifdef F_45
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_131 . V_132 = V_133 ;
F_47 ( V_91 , V_136 , & V_123 , NULL ) ;
V_2 -> V_135 . V_107 . V_37 = 0 ;
#endif
F_28 ( & V_154 ) ;
}
void F_71 ( struct V_90 * V_91 , T_2 V_112 ,
const T_1 * V_4 , T_3 V_65 , T_4 V_140 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_141 * V_142 ;
unsigned long V_33 ;
V_142 = F_8 ( sizeof( * V_142 ) + V_65 , V_140 ) ;
if ( ! V_142 )
return;
V_142 -> type = V_155 ;
V_142 -> V_156 . V_4 = ( ( T_1 * ) V_142 ) + sizeof( * V_142 ) ;
V_142 -> V_156 . V_65 = V_65 ;
memcpy ( ( void * ) V_142 -> V_156 . V_4 , V_4 , V_65 ) ;
V_142 -> V_156 . V_112 = V_112 ;
F_59 ( & V_2 -> V_145 , V_33 ) ;
F_60 ( & V_142 -> V_146 , & V_2 -> V_147 ) ;
F_61 ( & V_2 -> V_145 , V_33 ) ;
F_62 ( V_148 , & V_6 -> V_149 ) ;
}
int F_72 ( struct V_5 * V_6 ,
struct V_90 * V_91 ,
struct V_43 * V_107 ,
struct V_157 * V_158 ,
const T_1 * V_64 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
int V_11 ;
F_6 ( V_2 ) ;
if ( F_13 ( V_2 -> V_103 ) ) {
F_52 ( V_2 -> V_103 ) ;
V_2 -> V_103 = NULL ;
}
F_73 ( & V_107 -> V_71 ,
V_6 -> V_7 . V_159 ) ;
if ( V_158 && V_158 -> V_160 >= 0 ) {
int V_161 ;
T_5 V_162 ;
V_161 = V_158 -> V_160 ;
V_162 = V_158 -> V_15 [ V_161 ] . V_162 ;
if ( V_162 == V_163 ||
V_162 == V_164 ) {
V_107 -> V_57 = V_161 ;
V_107 -> V_55 = V_158 -> V_15 [ V_161 ] . V_55 ;
V_107 -> V_56 = V_158 -> V_15 [ V_161 ] . V_56 ;
if ( V_107 -> V_69 . V_165 == 0 )
V_107 -> V_69 . V_165 = V_162 ;
if ( V_107 -> V_69 . V_166 == 0 ) {
V_107 -> V_69 . V_166 = 1 ;
V_107 -> V_69 . V_167 [ 0 ] = V_162 ;
}
}
}
V_2 -> V_103 = V_158 ;
memcpy ( V_2 -> V_36 , V_107 -> V_36 , V_107 -> V_37 ) ;
V_2 -> V_37 = V_107 -> V_37 ;
if ( ! V_6 -> V_49 -> V_107 )
V_11 = F_39 ( V_2 , V_107 , V_64 ) ;
else
V_11 = F_74 ( V_6 , V_91 , V_107 ) ;
if ( V_11 ) {
V_2 -> V_103 = NULL ;
V_2 -> V_37 = 0 ;
return V_11 ;
}
return 0 ;
}
int F_75 ( struct V_5 * V_6 ,
struct V_90 * V_91 , T_2 V_112 , bool V_120 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
int V_11 = 0 ;
F_6 ( V_2 ) ;
F_52 ( V_2 -> V_103 ) ;
V_2 -> V_103 = NULL ;
if ( V_2 -> V_3 )
V_11 = F_41 ( V_2 , V_112 ) ;
else if ( ! V_6 -> V_49 -> V_168 )
F_76 ( V_6 , V_91 ) ;
else if ( V_2 -> V_108 )
V_11 = F_77 ( V_6 , V_91 , V_112 ) ;
return V_11 ;
}
