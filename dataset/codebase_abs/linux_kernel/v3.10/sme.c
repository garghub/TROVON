static bool F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
bool V_5 = true ;
F_2 ( & V_6 ) ;
F_3 (rdev, &cfg80211_rdev_list, list) {
F_4 ( V_2 ) ;
F_3 (wdev, &rdev->wdev_list, list) {
F_5 ( V_4 ) ;
if ( V_4 -> V_7 != V_8 )
V_5 = false ;
F_6 ( V_4 ) ;
}
F_7 ( V_2 ) ;
}
F_8 ( & V_6 ) ;
return V_5 ;
}
static void F_9 ( struct V_9 * V_10 )
{
if ( ! F_1 () )
return;
F_10 () ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_12 * V_13 ;
int V_14 , V_15 ;
F_13 () ;
F_14 ( V_2 ) ;
F_15 ( V_4 ) ;
F_16 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_17 )
return - V_18 ;
if ( V_4 -> V_19 -> V_20 . V_21 ) {
V_14 = 1 ;
} else {
enum V_22 V_23 ;
V_14 = 0 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ! V_4 -> V_11 -> V_25 [ V_23 ] )
continue;
V_14 += V_4 -> V_11 -> V_25 [ V_23 ] -> V_14 ;
}
}
V_13 = F_17 ( sizeof( * V_13 ) + sizeof( V_13 -> V_26 [ 0 ] ) +
sizeof( V_13 -> V_27 [ 0 ] ) * V_14 ,
V_28 ) ;
if ( ! V_13 )
return - V_29 ;
if ( V_4 -> V_19 -> V_20 . V_21 )
V_13 -> V_27 [ 0 ] = V_4 -> V_19 -> V_20 . V_21 ;
else {
int V_30 = 0 , V_31 ;
enum V_22 V_23 ;
struct V_32 * V_25 ;
struct V_33 * V_21 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
V_25 = V_4 -> V_11 -> V_25 [ V_23 ] ;
if ( ! V_25 )
continue;
for ( V_31 = 0 ; V_31 < V_25 -> V_14 ; V_31 ++ ) {
V_21 = & V_25 -> V_27 [ V_31 ] ;
if ( V_21 -> V_34 & V_35 )
continue;
V_13 -> V_27 [ V_30 ++ ] = V_21 ;
}
V_13 -> V_36 [ V_23 ] = ( 1 << V_25 -> V_37 ) - 1 ;
}
V_14 = V_30 ;
}
V_13 -> V_14 = V_14 ;
V_13 -> V_26 = ( void * ) & V_13 -> V_27 [ V_14 ] ;
V_13 -> V_38 = 1 ;
memcpy ( V_13 -> V_26 [ 0 ] . V_39 , V_4 -> V_19 -> V_20 . V_39 ,
V_4 -> V_19 -> V_20 . V_40 ) ;
V_13 -> V_26 [ 0 ] . V_40 = V_4 -> V_19 -> V_20 . V_40 ;
V_13 -> V_4 = V_4 ;
V_13 -> V_11 = & V_2 -> V_11 ;
V_13 -> V_41 = V_42 ;
V_2 -> V_17 = V_13 ;
V_15 = F_18 ( V_2 , V_13 ) ;
if ( ! V_15 ) {
V_4 -> V_19 -> V_43 = V_44 ;
F_19 ( V_2 , V_4 ) ;
F_20 ( V_4 -> V_45 ) ;
} else {
V_2 -> V_17 = NULL ;
F_21 ( V_13 ) ;
}
return V_15 ;
}
static int F_22 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_46 * V_20 ;
struct V_47 V_48 = {} ;
int V_15 ;
F_15 ( V_4 ) ;
if ( ! V_4 -> V_19 )
return 0 ;
V_20 = & V_4 -> V_19 -> V_20 ;
switch ( V_4 -> V_19 -> V_43 ) {
case V_49 :
return F_11 ( V_4 ) ;
case V_50 :
F_23 ( ! V_2 -> V_51 -> V_52 ) ;
V_4 -> V_19 -> V_43 = V_53 ;
return F_24 ( V_2 , V_4 -> V_45 ,
V_20 -> V_21 , V_20 -> V_54 ,
V_20 -> V_55 ,
V_20 -> V_39 , V_20 -> V_40 ,
NULL , 0 ,
V_20 -> V_56 , V_20 -> V_57 ,
V_20 -> V_58 , NULL , 0 ) ;
case V_59 :
F_23 ( ! V_2 -> V_51 -> V_60 ) ;
V_4 -> V_19 -> V_43 = V_61 ;
if ( V_4 -> V_19 -> V_62 )
V_48 . V_63 = V_4 -> V_19 -> V_63 ;
V_48 . V_64 = V_20 -> V_64 ;
V_48 . V_65 = V_20 -> V_65 ;
V_48 . V_66 = V_20 -> V_67 != V_68 ;
V_48 . V_69 = V_20 -> V_69 ;
V_48 . V_34 = V_20 -> V_34 ;
V_48 . V_70 = V_20 -> V_70 ;
V_48 . V_71 = V_20 -> V_71 ;
V_48 . V_72 = V_20 -> V_72 ;
V_48 . V_73 = V_20 -> V_73 ;
V_15 = F_25 ( V_2 , V_4 -> V_45 , V_20 -> V_21 ,
V_20 -> V_55 , V_20 -> V_39 ,
V_20 -> V_40 , & V_48 ) ;
if ( V_15 )
F_26 ( V_2 , V_4 -> V_45 , V_20 -> V_55 ,
NULL , 0 ,
V_74 ,
false ) ;
return V_15 ;
case V_75 :
F_26 ( V_2 , V_4 -> V_45 , V_20 -> V_55 ,
NULL , 0 ,
V_74 , false ) ;
return - V_76 ;
default:
return 0 ;
}
}
void F_27 ( struct V_9 * V_10 )
{
struct V_1 * V_2 =
F_28 ( V_10 , struct V_1 , V_77 ) ;
struct V_3 * V_4 ;
T_1 V_78 [ V_79 ] , * V_55 = NULL ;
F_29 () ;
F_4 ( V_2 ) ;
F_2 ( & V_2 -> V_80 ) ;
F_2 ( & V_2 -> V_16 ) ;
F_3 (wdev, &rdev->wdev_list, list) {
if ( ! V_4 -> V_45 )
continue;
F_5 ( V_4 ) ;
if ( ! F_30 ( V_4 -> V_45 ) ) {
F_6 ( V_4 ) ;
continue;
}
if ( V_4 -> V_7 != V_81 || ! V_4 -> V_19 ) {
F_6 ( V_4 ) ;
continue;
}
if ( V_4 -> V_19 -> V_20 . V_55 ) {
memcpy ( V_78 , V_4 -> V_19 -> V_20 . V_55 , V_79 ) ;
V_55 = V_78 ;
}
if ( F_22 ( V_4 ) )
F_31 (
V_4 -> V_45 , V_55 ,
NULL , 0 , NULL , 0 ,
V_82 ,
false , NULL ) ;
F_6 ( V_4 ) ;
}
F_8 ( & V_2 -> V_16 ) ;
F_8 ( & V_2 -> V_80 ) ;
F_7 ( V_2 ) ;
F_32 () ;
}
static struct V_83 * F_33 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_83 * V_84 ;
T_2 V_85 = V_86 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_19 -> V_20 . V_87 )
V_85 |= V_88 ;
V_84 = F_34 ( V_4 -> V_11 , V_4 -> V_19 -> V_20 . V_21 ,
V_4 -> V_19 -> V_20 . V_55 ,
V_4 -> V_19 -> V_20 . V_39 ,
V_4 -> V_19 -> V_20 . V_40 ,
V_86 | V_88 ,
V_85 ) ;
if ( ! V_84 )
return NULL ;
memcpy ( V_4 -> V_19 -> V_55 , V_84 -> V_55 , V_79 ) ;
V_4 -> V_19 -> V_20 . V_55 = V_4 -> V_19 -> V_55 ;
V_4 -> V_19 -> V_20 . V_21 = V_84 -> V_21 ;
V_4 -> V_19 -> V_43 = V_50 ;
F_35 ( & V_2 -> V_77 ) ;
return V_84 ;
}
static void F_36 ( struct V_89 * V_90 )
{
struct V_3 * V_4 = V_90 -> V_91 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_83 * V_84 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_81 )
return;
if ( ! V_4 -> V_19 )
return;
if ( V_4 -> V_19 -> V_43 != V_44 &&
V_4 -> V_19 -> V_43 != V_49 )
return;
V_84 = F_33 ( V_4 ) ;
if ( V_84 ) {
F_37 ( & V_2 -> V_11 , V_84 ) ;
} else {
if ( V_4 -> V_19 -> V_43 == V_49 )
F_35 ( & V_2 -> V_77 ) ;
else
F_31 (
V_4 -> V_45 ,
V_4 -> V_19 -> V_20 . V_55 ,
NULL , 0 , NULL , 0 ,
V_82 ,
false , NULL ) ;
}
}
void F_38 ( struct V_89 * V_90 )
{
struct V_3 * V_4 = V_90 -> V_91 ;
F_5 ( V_4 ) ;
F_36 ( V_90 ) ;
F_6 ( V_4 ) ;
}
void F_39 ( struct V_89 * V_90 ,
const T_1 * V_92 , T_3 V_93 )
{
struct V_3 * V_4 = V_90 -> V_91 ;
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
struct V_94 * V_95 = (struct V_94 * ) V_92 ;
T_2 V_96 = F_40 ( V_95 -> V_97 . V_52 . V_96 ) ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_81 )
return;
if ( F_41 ( ! V_4 -> V_19 ) )
return;
if ( V_96 == V_98 &&
V_4 -> V_19 -> V_99 &&
V_4 -> V_19 -> V_20 . V_54 != V_100 ) {
switch ( V_4 -> V_19 -> V_20 . V_54 ) {
case V_101 :
if ( V_4 -> V_102 )
V_4 -> V_19 -> V_20 . V_54 =
V_103 ;
else
V_4 -> V_19 -> V_20 . V_54 =
V_100 ;
break;
case V_103 :
V_4 -> V_19 -> V_20 . V_54 =
V_100 ;
break;
default:
V_4 -> V_19 -> V_20 . V_54 =
V_101 ;
break;
}
V_4 -> V_19 -> V_43 = V_50 ;
F_35 ( & V_2 -> V_77 ) ;
} else if ( V_96 != V_104 ) {
F_31 ( V_90 , V_95 -> V_55 , NULL , 0 , NULL , 0 ,
V_96 , false , NULL ) ;
} else if ( V_4 -> V_7 == V_81 &&
V_4 -> V_19 -> V_43 == V_53 ) {
V_4 -> V_19 -> V_43 = V_59 ;
F_35 ( & V_2 -> V_77 ) ;
}
}
bool F_42 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
if ( F_41 ( ! V_4 -> V_19 ) )
return false ;
if ( ! V_4 -> V_19 -> V_62 )
return false ;
V_4 -> V_19 -> V_62 = false ;
V_4 -> V_19 -> V_43 = V_59 ;
F_35 ( & V_2 -> V_77 ) ;
return true ;
}
void F_43 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
V_4 -> V_19 -> V_43 = V_75 ;
F_35 ( & V_2 -> V_77 ) ;
}
void F_31 ( struct V_89 * V_90 , const T_1 * V_55 ,
const T_1 * V_105 , T_3 V_106 ,
const T_1 * V_107 , T_3 V_108 ,
T_2 V_109 , bool V_110 ,
struct V_83 * V_84 )
{
struct V_3 * V_4 = V_90 -> V_91 ;
const T_1 * V_111 ;
#ifdef F_44
union V_112 V_113 ;
#endif
F_15 ( V_4 ) ;
if ( F_41 ( V_4 -> V_114 != V_115 &&
V_4 -> V_114 != V_116 ) )
return;
if ( V_4 -> V_7 != V_81 )
return;
F_45 ( F_12 ( V_4 -> V_11 ) , V_90 ,
V_55 , V_105 , V_106 ,
V_107 , V_108 ,
V_109 , V_28 ) ;
#ifdef F_44
if ( V_110 ) {
if ( V_105 && V_109 == V_104 ) {
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_113 . V_117 . V_118 = V_106 ;
F_46 ( V_90 , V_119 , & V_113 , V_105 ) ;
}
if ( V_107 && V_109 == V_104 ) {
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_113 . V_117 . V_118 = V_108 ;
F_46 ( V_90 , V_120 , & V_113 , V_107 ) ;
}
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_113 . V_121 . V_122 = V_123 ;
if ( V_55 && V_109 == V_104 ) {
memcpy ( V_113 . V_121 . V_124 , V_55 , V_79 ) ;
memcpy ( V_4 -> V_125 . V_63 , V_55 , V_79 ) ;
V_4 -> V_125 . V_62 = true ;
}
F_46 ( V_90 , V_126 , & V_113 , NULL ) ;
}
#endif
if ( V_4 -> V_127 ) {
F_47 ( V_4 -> V_127 ) ;
F_37 ( V_4 -> V_11 , & V_4 -> V_127 -> V_128 ) ;
V_4 -> V_127 = NULL ;
}
if ( V_4 -> V_19 )
V_4 -> V_19 -> V_43 = V_129 ;
if ( V_109 != V_104 ) {
V_4 -> V_7 = V_8 ;
if ( V_4 -> V_19 )
F_21 ( V_4 -> V_19 -> V_64 ) ;
F_21 ( V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
F_21 ( V_4 -> V_102 ) ;
V_4 -> V_102 = NULL ;
V_4 -> V_40 = 0 ;
F_37 ( V_4 -> V_11 , V_84 ) ;
return;
}
if ( ! V_84 )
V_84 = F_34 ( V_4 -> V_11 ,
V_4 -> V_19 ? V_4 -> V_19 -> V_20 . V_21 :
NULL ,
V_55 ,
V_4 -> V_39 , V_4 -> V_40 ,
V_86 ,
V_86 ) ;
if ( F_41 ( ! V_84 ) )
return;
F_48 ( F_49 ( V_84 ) ) ;
V_4 -> V_127 = F_49 ( V_84 ) ;
V_4 -> V_7 = V_130 ;
F_50 ( V_4 ) ;
F_51 () ;
V_111 = F_52 ( V_84 , V_131 ) ;
if ( ! V_111 ) {
F_53 () ;
return;
}
V_111 = F_54 ( V_111 , 2 + V_111 [ 1 ] , V_132 ) ;
F_53 () ;
if ( ! V_111 )
return;
F_55 ( V_4 -> V_11 , V_84 -> V_21 -> V_23 ,
V_111 + 2 , V_111 [ 1 ] ) ;
F_21 ( V_111 ) ;
}
void F_56 ( struct V_89 * V_90 , const T_1 * V_55 ,
const T_1 * V_105 , T_3 V_106 ,
const T_1 * V_107 , T_3 V_108 ,
T_2 V_109 , T_4 V_133 )
{
struct V_3 * V_4 = V_90 -> V_91 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_134 * V_135 ;
unsigned long V_34 ;
F_57 ( V_4 -> V_7 != V_81 ) ;
V_135 = F_17 ( sizeof( * V_135 ) + V_106 + V_108 , V_133 ) ;
if ( ! V_135 )
return;
V_135 -> type = V_136 ;
if ( V_55 )
memcpy ( V_135 -> V_137 . V_55 , V_55 , V_79 ) ;
if ( V_106 ) {
V_135 -> V_137 . V_105 = ( ( T_1 * ) V_135 ) + sizeof( * V_135 ) ;
V_135 -> V_137 . V_106 = V_106 ;
memcpy ( ( void * ) V_135 -> V_137 . V_105 , V_105 , V_106 ) ;
}
if ( V_108 ) {
V_135 -> V_137 . V_107 = ( ( T_1 * ) V_135 ) + sizeof( * V_135 ) + V_106 ;
V_135 -> V_137 . V_108 = V_108 ;
memcpy ( ( void * ) V_135 -> V_137 . V_107 , V_107 , V_108 ) ;
}
V_135 -> V_137 . V_109 = V_109 ;
F_58 ( & V_4 -> V_138 , V_34 ) ;
F_59 ( & V_135 -> V_139 , & V_4 -> V_140 ) ;
F_60 ( & V_4 -> V_138 , V_34 ) ;
F_61 ( V_141 , & V_2 -> V_142 ) ;
}
void F_62 ( struct V_3 * V_4 ,
struct V_83 * V_84 ,
const T_1 * V_105 , T_3 V_106 ,
const T_1 * V_107 , T_3 V_108 )
{
#ifdef F_44
union V_112 V_113 ;
#endif
F_15 ( V_4 ) ;
if ( F_41 ( V_4 -> V_114 != V_115 &&
V_4 -> V_114 != V_116 ) )
goto V_143;
if ( V_4 -> V_7 != V_130 )
goto V_143;
if ( F_41 ( ! V_4 -> V_127 ) ) {
goto V_143;
}
F_47 ( V_4 -> V_127 ) ;
F_37 ( V_4 -> V_11 , & V_4 -> V_127 -> V_128 ) ;
V_4 -> V_127 = NULL ;
F_48 ( F_49 ( V_84 ) ) ;
V_4 -> V_127 = F_49 ( V_84 ) ;
F_63 ( F_12 ( V_4 -> V_11 ) , V_4 -> V_45 , V_84 -> V_55 ,
V_105 , V_106 , V_107 , V_108 ,
V_28 ) ;
#ifdef F_44
if ( V_105 ) {
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_113 . V_117 . V_118 = V_106 ;
F_46 ( V_4 -> V_45 , V_119 ,
& V_113 , V_105 ) ;
}
if ( V_107 ) {
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_113 . V_117 . V_118 = V_108 ;
F_46 ( V_4 -> V_45 , V_120 ,
& V_113 , V_107 ) ;
}
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_113 . V_121 . V_122 = V_123 ;
memcpy ( V_113 . V_121 . V_124 , V_84 -> V_55 , V_79 ) ;
memcpy ( V_4 -> V_125 . V_63 , V_84 -> V_55 , V_79 ) ;
V_4 -> V_125 . V_62 = true ;
F_46 ( V_4 -> V_45 , V_126 , & V_113 , NULL ) ;
#endif
return;
V_143:
F_37 ( V_4 -> V_11 , V_84 ) ;
}
void F_64 ( struct V_89 * V_90 ,
struct V_33 * V_21 ,
const T_1 * V_55 ,
const T_1 * V_105 , T_3 V_106 ,
const T_1 * V_107 , T_3 V_108 , T_4 V_133 )
{
struct V_3 * V_4 = V_90 -> V_91 ;
struct V_83 * V_84 ;
F_57 ( V_4 -> V_7 != V_130 ) ;
V_84 = F_34 ( V_4 -> V_11 , V_21 , V_55 , V_4 -> V_39 ,
V_4 -> V_40 , V_86 ,
V_86 ) ;
if ( F_41 ( ! V_84 ) )
return;
F_65 ( V_90 , V_84 , V_105 , V_106 , V_107 ,
V_108 , V_133 ) ;
}
void F_65 ( struct V_89 * V_90 ,
struct V_83 * V_84 , const T_1 * V_105 ,
T_3 V_106 , const T_1 * V_107 ,
T_3 V_108 , T_4 V_133 )
{
struct V_3 * V_4 = V_90 -> V_91 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_134 * V_135 ;
unsigned long V_34 ;
F_57 ( V_4 -> V_7 != V_130 ) ;
if ( F_41 ( ! V_84 ) )
return;
V_135 = F_17 ( sizeof( * V_135 ) + V_106 + V_108 , V_133 ) ;
if ( ! V_135 ) {
F_37 ( V_4 -> V_11 , V_84 ) ;
return;
}
V_135 -> type = V_144 ;
V_135 -> V_145 . V_105 = ( ( T_1 * ) V_135 ) + sizeof( * V_135 ) ;
V_135 -> V_145 . V_106 = V_106 ;
memcpy ( ( void * ) V_135 -> V_145 . V_105 , V_105 , V_106 ) ;
V_135 -> V_145 . V_107 = ( ( T_1 * ) V_135 ) + sizeof( * V_135 ) + V_106 ;
V_135 -> V_145 . V_108 = V_108 ;
memcpy ( ( void * ) V_135 -> V_145 . V_107 , V_107 , V_108 ) ;
V_135 -> V_145 . V_84 = V_84 ;
F_58 ( & V_4 -> V_138 , V_34 ) ;
F_59 ( & V_135 -> V_139 , & V_4 -> V_140 ) ;
F_60 ( & V_4 -> V_138 , V_34 ) ;
F_61 ( V_141 , & V_2 -> V_142 ) ;
}
void F_66 ( struct V_89 * V_90 , const T_1 * V_64 ,
T_3 V_65 , T_2 V_146 , bool V_147 )
{
struct V_3 * V_4 = V_90 -> V_91 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
int V_30 ;
#ifdef F_44
union V_112 V_113 ;
#endif
F_15 ( V_4 ) ;
if ( F_41 ( V_4 -> V_114 != V_115 &&
V_4 -> V_114 != V_116 ) )
return;
if ( V_4 -> V_7 != V_130 )
return;
if ( V_4 -> V_127 ) {
F_47 ( V_4 -> V_127 ) ;
F_37 ( V_4 -> V_11 , & V_4 -> V_127 -> V_128 ) ;
}
V_4 -> V_127 = NULL ;
V_4 -> V_7 = V_8 ;
V_4 -> V_40 = 0 ;
if ( V_4 -> V_19 ) {
F_21 ( V_4 -> V_19 -> V_64 ) ;
V_4 -> V_19 -> V_64 = NULL ;
F_21 ( V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
}
F_67 ( V_2 , V_90 , V_146 , V_64 , V_65 , V_147 ) ;
if ( V_2 -> V_51 -> V_148 )
for ( V_30 = 0 ; V_30 < 6 ; V_30 ++ )
F_68 ( V_2 , V_90 , V_30 , false , NULL ) ;
#ifdef F_44
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_113 . V_121 . V_122 = V_123 ;
F_46 ( V_90 , V_126 , & V_113 , NULL ) ;
V_4 -> V_125 . V_149 . V_40 = 0 ;
#endif
F_35 ( & V_150 ) ;
}
void F_69 ( struct V_89 * V_90 , T_2 V_146 ,
T_1 * V_64 , T_3 V_65 , T_4 V_133 )
{
struct V_3 * V_4 = V_90 -> V_91 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_134 * V_135 ;
unsigned long V_34 ;
F_57 ( V_4 -> V_7 != V_130 ) ;
V_135 = F_17 ( sizeof( * V_135 ) + V_65 , V_133 ) ;
if ( ! V_135 )
return;
V_135 -> type = V_151 ;
V_135 -> V_152 . V_64 = ( ( T_1 * ) V_135 ) + sizeof( * V_135 ) ;
V_135 -> V_152 . V_65 = V_65 ;
memcpy ( ( void * ) V_135 -> V_152 . V_64 , V_64 , V_65 ) ;
V_135 -> V_152 . V_146 = V_146 ;
F_58 ( & V_4 -> V_138 , V_34 ) ;
F_59 ( & V_135 -> V_139 , & V_4 -> V_140 ) ;
F_60 ( & V_4 -> V_138 , V_34 ) ;
F_61 ( V_141 , & V_2 -> V_142 ) ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
struct V_46 * V_149 ,
struct V_153 * V_154 ,
const T_1 * V_63 )
{
struct V_3 * V_4 = V_90 -> V_91 ;
struct V_83 * V_84 = NULL ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_8 )
return - V_155 ;
if ( F_41 ( V_4 -> V_102 ) ) {
F_21 ( V_4 -> V_102 ) ;
V_4 -> V_102 = NULL ;
}
F_71 ( & V_149 -> V_71 ,
V_2 -> V_11 . V_156 ) ;
if ( V_154 && V_154 -> V_157 >= 0 ) {
int V_158 ;
T_5 V_159 ;
V_158 = V_154 -> V_157 ;
V_159 = V_154 -> V_20 [ V_158 ] . V_159 ;
if ( V_159 == V_160 ||
V_159 == V_161 ) {
V_149 -> V_58 = V_158 ;
V_149 -> V_56 = V_154 -> V_20 [ V_158 ] . V_56 ;
V_149 -> V_57 = V_154 -> V_20 [ V_158 ] . V_57 ;
if ( V_149 -> V_69 . V_162 == 0 )
V_149 -> V_69 . V_162 = V_159 ;
if ( V_149 -> V_69 . V_163 == 0 ) {
V_149 -> V_69 . V_163 = 1 ;
V_149 -> V_69 . V_164 [ 0 ] = V_159 ;
}
}
}
if ( ! V_2 -> V_51 -> V_149 ) {
if ( ! V_2 -> V_51 -> V_52 || ! V_2 -> V_51 -> V_60 )
return - V_165 ;
if ( F_41 ( V_4 -> V_19 ) )
return - V_166 ;
V_4 -> V_19 = F_17 ( sizeof( * V_4 -> V_19 ) , V_28 ) ;
if ( ! V_4 -> V_19 )
return - V_29 ;
memcpy ( & V_4 -> V_19 -> V_20 , V_149 , sizeof( * V_149 ) ) ;
if ( V_149 -> V_55 ) {
V_4 -> V_19 -> V_20 . V_55 = V_4 -> V_19 -> V_55 ;
memcpy ( V_4 -> V_19 -> V_55 , V_149 -> V_55 , V_79 ) ;
}
if ( V_149 -> V_64 ) {
V_4 -> V_19 -> V_64 = F_54 ( V_149 -> V_64 , V_149 -> V_65 ,
V_28 ) ;
V_4 -> V_19 -> V_20 . V_64 = V_4 -> V_19 -> V_64 ;
if ( ! V_4 -> V_19 -> V_64 ) {
F_21 ( V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
return - V_29 ;
}
}
if ( V_149 -> V_54 == V_167 ) {
V_4 -> V_19 -> V_99 = true ;
V_4 -> V_19 -> V_20 . V_54 =
V_101 ;
} else {
V_4 -> V_19 -> V_99 = false ;
}
memcpy ( V_4 -> V_39 , V_149 -> V_39 , V_149 -> V_40 ) ;
V_4 -> V_40 = V_149 -> V_40 ;
V_4 -> V_19 -> V_20 . V_39 = V_4 -> V_39 ;
V_4 -> V_19 -> V_20 . V_40 = V_149 -> V_40 ;
V_84 = F_33 ( V_4 ) ;
V_4 -> V_7 = V_81 ;
V_4 -> V_102 = V_154 ;
if ( V_63 ) {
memcpy ( V_4 -> V_19 -> V_63 , V_63 , V_79 ) ;
V_4 -> V_19 -> V_62 = true ;
}
if ( V_84 ) {
V_4 -> V_19 -> V_43 = V_50 ;
V_15 = F_22 ( V_4 ) ;
F_37 ( V_4 -> V_11 , V_84 ) ;
} else {
V_15 = F_11 ( V_4 ) ;
if ( V_15 == - V_18 ) {
V_15 = 0 ;
V_4 -> V_19 -> V_43 = V_49 ;
}
}
if ( V_15 ) {
F_21 ( V_4 -> V_19 -> V_64 ) ;
F_21 ( V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
V_4 -> V_7 = V_8 ;
V_4 -> V_102 = NULL ;
V_4 -> V_40 = 0 ;
}
return V_15 ;
} else {
V_4 -> V_7 = V_81 ;
V_4 -> V_102 = V_154 ;
V_15 = F_72 ( V_2 , V_90 , V_149 ) ;
if ( V_15 ) {
V_4 -> V_102 = NULL ;
V_4 -> V_7 = V_8 ;
return V_15 ;
}
memcpy ( V_4 -> V_39 , V_149 -> V_39 , V_149 -> V_40 ) ;
V_4 -> V_40 = V_149 -> V_40 ;
return 0 ;
}
}
int F_73 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
struct V_46 * V_149 ,
struct V_153 * V_154 )
{
int V_15 ;
F_2 ( & V_2 -> V_80 ) ;
F_2 ( & V_2 -> V_16 ) ;
F_5 ( V_90 -> V_91 ) ;
V_15 = F_70 ( V_2 , V_90 , V_149 , V_154 , NULL ) ;
F_6 ( V_90 -> V_91 ) ;
F_8 ( & V_2 -> V_16 ) ;
F_8 ( & V_2 -> V_80 ) ;
return V_15 ;
}
int F_74 ( struct V_1 * V_2 ,
struct V_89 * V_90 , T_2 V_146 , bool V_110 )
{
struct V_3 * V_4 = V_90 -> V_91 ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 == V_8 )
return - V_76 ;
F_21 ( V_4 -> V_102 ) ;
V_4 -> V_102 = NULL ;
if ( ! V_2 -> V_51 -> V_168 ) {
if ( ! V_2 -> V_51 -> V_169 )
return - V_165 ;
if ( ! V_4 -> V_19 ) {
F_75 ( V_2 , V_90 ) ;
goto V_168;
}
if ( V_4 -> V_7 == V_81 &&
( V_4 -> V_19 -> V_43 == V_44 ||
V_4 -> V_19 -> V_43 == V_49 ) ) {
V_4 -> V_7 = V_8 ;
F_21 ( V_4 -> V_19 -> V_64 ) ;
F_21 ( V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
V_4 -> V_40 = 0 ;
return 0 ;
}
V_15 = F_26 ( V_2 , V_90 ,
V_4 -> V_19 -> V_20 . V_55 ,
NULL , 0 , V_146 , false ) ;
if ( V_15 )
return V_15 ;
} else {
V_15 = F_76 ( V_2 , V_90 , V_146 ) ;
if ( V_15 )
return V_15 ;
}
V_168:
if ( V_4 -> V_7 == V_130 )
F_66 ( V_90 , NULL , 0 , 0 , false ) ;
else if ( V_4 -> V_7 == V_81 )
F_31 ( V_90 , NULL , NULL , 0 , NULL , 0 ,
V_82 ,
V_110 , NULL ) ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
T_2 V_146 , bool V_110 )
{
int V_15 ;
F_5 ( V_90 -> V_91 ) ;
V_15 = F_74 ( V_2 , V_90 , V_146 , V_110 ) ;
F_6 ( V_90 -> V_91 ) ;
return V_15 ;
}
void F_78 ( struct V_89 * V_90 ,
struct V_170 * V_84 )
{
struct V_3 * V_4 = V_90 -> V_91 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
T_1 V_55 [ V_79 ] ;
F_15 ( V_4 ) ;
if ( ! V_4 -> V_19 )
return;
if ( V_4 -> V_19 -> V_43 == V_129 )
return;
memcpy ( V_55 , V_84 -> V_128 . V_55 , V_79 ) ;
F_26 ( V_2 , V_90 , V_55 , NULL , 0 ,
V_74 , false ) ;
}
