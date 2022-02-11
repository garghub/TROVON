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
const T_1 * V_47 = NULL ;
int V_15 ;
F_15 ( V_4 ) ;
if ( ! V_4 -> V_19 )
return 0 ;
V_20 = & V_4 -> V_19 -> V_20 ;
switch ( V_4 -> V_19 -> V_43 ) {
case V_48 :
return F_11 ( V_4 ) ;
case V_49 :
F_23 ( ! V_2 -> V_50 -> V_51 ) ;
V_4 -> V_19 -> V_43 = V_52 ;
return F_24 ( V_2 , V_4 -> V_45 ,
V_20 -> V_21 , V_20 -> V_53 ,
V_20 -> V_54 ,
V_20 -> V_39 , V_20 -> V_40 ,
NULL , 0 ,
V_20 -> V_55 , V_20 -> V_56 ,
V_20 -> V_57 , NULL , 0 ) ;
case V_58 :
F_23 ( ! V_2 -> V_50 -> V_59 ) ;
V_4 -> V_19 -> V_43 = V_60 ;
if ( V_4 -> V_19 -> V_61 )
V_47 = V_4 -> V_19 -> V_47 ;
V_15 = F_25 ( V_2 , V_4 -> V_45 ,
V_20 -> V_21 , V_20 -> V_54 ,
V_47 ,
V_20 -> V_39 , V_20 -> V_40 ,
V_20 -> V_62 , V_20 -> V_63 ,
V_20 -> V_64 != V_65 ,
& V_20 -> V_66 ,
V_20 -> V_34 , & V_20 -> V_67 ,
& V_20 -> V_68 ) ;
if ( V_15 )
F_26 ( V_2 , V_4 -> V_45 , V_20 -> V_54 ,
NULL , 0 ,
V_69 ,
false ) ;
return V_15 ;
case V_70 :
F_26 ( V_2 , V_4 -> V_45 , V_20 -> V_54 ,
NULL , 0 ,
V_69 , false ) ;
return - V_71 ;
default:
return 0 ;
}
}
void F_27 ( struct V_9 * V_10 )
{
struct V_1 * V_2 =
F_28 ( V_10 , struct V_1 , V_72 ) ;
struct V_3 * V_4 ;
T_1 V_73 [ V_74 ] , * V_54 = NULL ;
F_29 () ;
F_4 ( V_2 ) ;
F_2 ( & V_2 -> V_75 ) ;
F_2 ( & V_2 -> V_16 ) ;
F_3 (wdev, &rdev->wdev_list, list) {
F_5 ( V_4 ) ;
if ( ! F_30 ( V_4 -> V_45 ) ) {
F_6 ( V_4 ) ;
continue;
}
if ( V_4 -> V_7 != V_76 ) {
F_6 ( V_4 ) ;
continue;
}
if ( V_4 -> V_19 -> V_20 . V_54 ) {
memcpy ( V_73 , V_4 -> V_19 -> V_20 . V_54 , V_74 ) ;
V_54 = V_73 ;
}
if ( F_22 ( V_4 ) )
F_31 (
V_4 -> V_45 , V_54 ,
NULL , 0 , NULL , 0 ,
V_77 ,
false , NULL ) ;
F_6 ( V_4 ) ;
}
F_8 ( & V_2 -> V_16 ) ;
F_8 ( & V_2 -> V_75 ) ;
F_7 ( V_2 ) ;
F_32 () ;
}
static struct V_78 * F_33 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_78 * V_79 ;
T_2 V_80 = V_81 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_19 -> V_20 . V_82 )
V_80 |= V_83 ;
V_79 = F_34 ( V_4 -> V_11 , V_4 -> V_19 -> V_20 . V_21 ,
V_4 -> V_19 -> V_20 . V_54 ,
V_4 -> V_19 -> V_20 . V_39 ,
V_4 -> V_19 -> V_20 . V_40 ,
V_81 | V_83 ,
V_80 ) ;
if ( ! V_79 )
return NULL ;
memcpy ( V_4 -> V_19 -> V_54 , V_79 -> V_54 , V_74 ) ;
V_4 -> V_19 -> V_20 . V_54 = V_4 -> V_19 -> V_54 ;
V_4 -> V_19 -> V_20 . V_21 = V_79 -> V_21 ;
V_4 -> V_19 -> V_43 = V_49 ;
F_35 ( & V_2 -> V_72 ) ;
return V_79 ;
}
static void F_36 ( struct V_84 * V_85 )
{
struct V_3 * V_4 = V_85 -> V_86 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_78 * V_79 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_76 )
return;
if ( ! V_4 -> V_19 )
return;
if ( V_4 -> V_19 -> V_43 != V_44 &&
V_4 -> V_19 -> V_43 != V_48 )
return;
V_79 = F_33 ( V_4 ) ;
if ( V_79 ) {
F_37 ( & V_2 -> V_11 , V_79 ) ;
} else {
if ( V_4 -> V_19 -> V_43 == V_48 )
F_35 ( & V_2 -> V_72 ) ;
else
F_31 (
V_4 -> V_45 ,
V_4 -> V_19 -> V_20 . V_54 ,
NULL , 0 , NULL , 0 ,
V_77 ,
false , NULL ) ;
}
}
void F_38 ( struct V_84 * V_85 )
{
struct V_3 * V_4 = V_85 -> V_86 ;
F_5 ( V_4 ) ;
F_36 ( V_85 ) ;
F_6 ( V_4 ) ;
}
void F_39 ( struct V_84 * V_85 ,
const T_1 * V_87 , T_3 V_88 )
{
struct V_3 * V_4 = V_85 -> V_86 ;
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
struct V_89 * V_90 = (struct V_89 * ) V_87 ;
T_2 V_91 = F_40 ( V_90 -> V_92 . V_51 . V_91 ) ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_76 )
return;
if ( F_41 ( ! V_4 -> V_19 ) )
return;
if ( V_91 == V_93 &&
V_4 -> V_19 -> V_94 &&
V_4 -> V_19 -> V_20 . V_53 != V_95 ) {
switch ( V_4 -> V_19 -> V_20 . V_53 ) {
case V_96 :
if ( V_4 -> V_97 )
V_4 -> V_19 -> V_20 . V_53 =
V_98 ;
else
V_4 -> V_19 -> V_20 . V_53 =
V_95 ;
break;
case V_98 :
V_4 -> V_19 -> V_20 . V_53 =
V_95 ;
break;
default:
V_4 -> V_19 -> V_20 . V_53 =
V_96 ;
break;
}
V_4 -> V_19 -> V_43 = V_49 ;
F_35 ( & V_2 -> V_72 ) ;
} else if ( V_91 != V_99 ) {
F_31 ( V_85 , V_90 -> V_54 , NULL , 0 , NULL , 0 ,
V_91 , false , NULL ) ;
} else if ( V_4 -> V_7 == V_76 &&
V_4 -> V_19 -> V_43 == V_52 ) {
V_4 -> V_19 -> V_43 = V_58 ;
F_35 ( & V_2 -> V_72 ) ;
}
}
bool F_42 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
if ( F_41 ( ! V_4 -> V_19 ) )
return false ;
if ( ! V_4 -> V_19 -> V_61 )
return false ;
V_4 -> V_19 -> V_61 = false ;
V_4 -> V_19 -> V_43 = V_58 ;
F_35 ( & V_2 -> V_72 ) ;
return true ;
}
void F_43 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
V_4 -> V_19 -> V_43 = V_70 ;
F_35 ( & V_2 -> V_72 ) ;
}
void F_31 ( struct V_84 * V_85 , const T_1 * V_54 ,
const T_1 * V_100 , T_3 V_101 ,
const T_1 * V_102 , T_3 V_103 ,
T_2 V_104 , bool V_105 ,
struct V_78 * V_79 )
{
struct V_3 * V_4 = V_85 -> V_86 ;
const T_1 * V_106 ;
#ifdef F_44
union V_107 V_108 ;
#endif
F_15 ( V_4 ) ;
if ( F_41 ( V_4 -> V_109 != V_110 &&
V_4 -> V_109 != V_111 ) )
return;
if ( V_4 -> V_7 != V_76 )
return;
F_45 ( F_12 ( V_4 -> V_11 ) , V_85 ,
V_54 , V_100 , V_101 ,
V_102 , V_103 ,
V_104 , V_28 ) ;
#ifdef F_44
if ( V_105 ) {
if ( V_100 && V_104 == V_99 ) {
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_112 . V_113 = V_101 ;
F_46 ( V_85 , V_114 , & V_108 , V_100 ) ;
}
if ( V_102 && V_104 == V_99 ) {
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_112 . V_113 = V_103 ;
F_46 ( V_85 , V_115 , & V_108 , V_102 ) ;
}
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_116 . V_117 = V_118 ;
if ( V_54 && V_104 == V_99 ) {
memcpy ( V_108 . V_116 . V_119 , V_54 , V_74 ) ;
memcpy ( V_4 -> V_120 . V_47 , V_54 , V_74 ) ;
V_4 -> V_120 . V_61 = true ;
}
F_46 ( V_85 , V_121 , & V_108 , NULL ) ;
}
#endif
if ( V_4 -> V_122 ) {
F_47 ( V_4 -> V_122 ) ;
F_37 ( V_4 -> V_11 , & V_4 -> V_122 -> V_123 ) ;
V_4 -> V_122 = NULL ;
}
if ( V_4 -> V_19 )
V_4 -> V_19 -> V_43 = V_124 ;
if ( V_104 != V_99 ) {
V_4 -> V_7 = V_8 ;
if ( V_4 -> V_19 )
F_21 ( V_4 -> V_19 -> V_62 ) ;
F_21 ( V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
F_21 ( V_4 -> V_97 ) ;
V_4 -> V_97 = NULL ;
V_4 -> V_40 = 0 ;
F_37 ( V_4 -> V_11 , V_79 ) ;
return;
}
if ( ! V_79 )
V_79 = F_34 ( V_4 -> V_11 ,
V_4 -> V_19 ? V_4 -> V_19 -> V_20 . V_21 :
NULL ,
V_54 ,
V_4 -> V_39 , V_4 -> V_40 ,
V_81 ,
V_81 ) ;
if ( F_41 ( ! V_79 ) )
return;
F_48 ( F_49 ( V_79 ) ) ;
V_4 -> V_122 = F_49 ( V_79 ) ;
V_4 -> V_7 = V_125 ;
F_50 ( V_4 ) ;
F_51 () ;
V_106 = F_52 ( V_79 , V_126 ) ;
if ( ! V_106 ) {
F_53 () ;
return;
}
V_106 = F_54 ( V_106 , 2 + V_106 [ 1 ] , V_127 ) ;
F_53 () ;
if ( ! V_106 )
return;
F_55 ( V_4 -> V_11 , V_79 -> V_21 -> V_23 ,
V_106 + 2 , V_106 [ 1 ] ) ;
F_21 ( V_106 ) ;
}
void F_56 ( struct V_84 * V_85 , const T_1 * V_54 ,
const T_1 * V_100 , T_3 V_101 ,
const T_1 * V_102 , T_3 V_103 ,
T_2 V_104 , T_4 V_128 )
{
struct V_3 * V_4 = V_85 -> V_86 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_129 * V_130 ;
unsigned long V_34 ;
F_57 ( V_4 -> V_7 != V_76 ) ;
V_130 = F_17 ( sizeof( * V_130 ) + V_101 + V_103 , V_128 ) ;
if ( ! V_130 )
return;
V_130 -> type = V_131 ;
if ( V_54 )
memcpy ( V_130 -> V_132 . V_54 , V_54 , V_74 ) ;
if ( V_101 ) {
V_130 -> V_132 . V_100 = ( ( T_1 * ) V_130 ) + sizeof( * V_130 ) ;
V_130 -> V_132 . V_101 = V_101 ;
memcpy ( ( void * ) V_130 -> V_132 . V_100 , V_100 , V_101 ) ;
}
if ( V_103 ) {
V_130 -> V_132 . V_102 = ( ( T_1 * ) V_130 ) + sizeof( * V_130 ) + V_101 ;
V_130 -> V_132 . V_103 = V_103 ;
memcpy ( ( void * ) V_130 -> V_132 . V_102 , V_102 , V_103 ) ;
}
V_130 -> V_132 . V_104 = V_104 ;
F_58 ( & V_4 -> V_133 , V_34 ) ;
F_59 ( & V_130 -> V_134 , & V_4 -> V_135 ) ;
F_60 ( & V_4 -> V_133 , V_34 ) ;
F_61 ( V_136 , & V_2 -> V_137 ) ;
}
void F_62 ( struct V_3 * V_4 ,
struct V_78 * V_79 ,
const T_1 * V_100 , T_3 V_101 ,
const T_1 * V_102 , T_3 V_103 )
{
#ifdef F_44
union V_107 V_108 ;
#endif
F_15 ( V_4 ) ;
if ( F_41 ( V_4 -> V_109 != V_110 &&
V_4 -> V_109 != V_111 ) )
goto V_138;
if ( V_4 -> V_7 != V_125 )
goto V_138;
if ( F_41 ( ! V_4 -> V_122 ) ) {
goto V_138;
}
F_47 ( V_4 -> V_122 ) ;
F_37 ( V_4 -> V_11 , & V_4 -> V_122 -> V_123 ) ;
V_4 -> V_122 = NULL ;
F_48 ( F_49 ( V_79 ) ) ;
V_4 -> V_122 = F_49 ( V_79 ) ;
F_63 ( F_12 ( V_4 -> V_11 ) , V_4 -> V_45 , V_79 -> V_54 ,
V_100 , V_101 , V_102 , V_103 ,
V_28 ) ;
#ifdef F_44
if ( V_100 ) {
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_112 . V_113 = V_101 ;
F_46 ( V_4 -> V_45 , V_114 ,
& V_108 , V_100 ) ;
}
if ( V_102 ) {
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_112 . V_113 = V_103 ;
F_46 ( V_4 -> V_45 , V_115 ,
& V_108 , V_102 ) ;
}
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_116 . V_117 = V_118 ;
memcpy ( V_108 . V_116 . V_119 , V_79 -> V_54 , V_74 ) ;
memcpy ( V_4 -> V_120 . V_47 , V_79 -> V_54 , V_74 ) ;
V_4 -> V_120 . V_61 = true ;
F_46 ( V_4 -> V_45 , V_121 , & V_108 , NULL ) ;
#endif
return;
V_138:
F_37 ( V_4 -> V_11 , V_79 ) ;
}
void F_64 ( struct V_84 * V_85 ,
struct V_33 * V_21 ,
const T_1 * V_54 ,
const T_1 * V_100 , T_3 V_101 ,
const T_1 * V_102 , T_3 V_103 , T_4 V_128 )
{
struct V_3 * V_4 = V_85 -> V_86 ;
struct V_78 * V_79 ;
F_57 ( V_4 -> V_7 != V_125 ) ;
V_79 = F_34 ( V_4 -> V_11 , V_21 , V_54 , V_4 -> V_39 ,
V_4 -> V_40 , V_81 ,
V_81 ) ;
if ( F_41 ( ! V_79 ) )
return;
F_65 ( V_85 , V_79 , V_100 , V_101 , V_102 ,
V_103 , V_128 ) ;
}
void F_65 ( struct V_84 * V_85 ,
struct V_78 * V_79 , const T_1 * V_100 ,
T_3 V_101 , const T_1 * V_102 ,
T_3 V_103 , T_4 V_128 )
{
struct V_3 * V_4 = V_85 -> V_86 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_129 * V_130 ;
unsigned long V_34 ;
F_57 ( V_4 -> V_7 != V_125 ) ;
if ( F_41 ( ! V_79 ) )
return;
V_130 = F_17 ( sizeof( * V_130 ) + V_101 + V_103 , V_128 ) ;
if ( ! V_130 ) {
F_37 ( V_4 -> V_11 , V_79 ) ;
return;
}
V_130 -> type = V_139 ;
V_130 -> V_140 . V_100 = ( ( T_1 * ) V_130 ) + sizeof( * V_130 ) ;
V_130 -> V_140 . V_101 = V_101 ;
memcpy ( ( void * ) V_130 -> V_140 . V_100 , V_100 , V_101 ) ;
V_130 -> V_140 . V_102 = ( ( T_1 * ) V_130 ) + sizeof( * V_130 ) + V_101 ;
V_130 -> V_140 . V_103 = V_103 ;
memcpy ( ( void * ) V_130 -> V_140 . V_102 , V_102 , V_103 ) ;
V_130 -> V_140 . V_79 = V_79 ;
F_58 ( & V_4 -> V_133 , V_34 ) ;
F_59 ( & V_130 -> V_134 , & V_4 -> V_135 ) ;
F_60 ( & V_4 -> V_133 , V_34 ) ;
F_61 ( V_136 , & V_2 -> V_137 ) ;
}
void F_66 ( struct V_84 * V_85 , const T_1 * V_62 ,
T_3 V_63 , T_2 V_141 , bool V_142 )
{
struct V_3 * V_4 = V_85 -> V_86 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
int V_30 ;
#ifdef F_44
union V_107 V_108 ;
#endif
F_15 ( V_4 ) ;
if ( F_41 ( V_4 -> V_109 != V_110 &&
V_4 -> V_109 != V_111 ) )
return;
if ( V_4 -> V_7 != V_125 )
return;
if ( V_4 -> V_122 ) {
F_47 ( V_4 -> V_122 ) ;
F_37 ( V_4 -> V_11 , & V_4 -> V_122 -> V_123 ) ;
}
V_4 -> V_122 = NULL ;
V_4 -> V_7 = V_8 ;
V_4 -> V_40 = 0 ;
if ( V_4 -> V_19 ) {
F_21 ( V_4 -> V_19 -> V_62 ) ;
V_4 -> V_19 -> V_62 = NULL ;
F_21 ( V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
}
F_67 ( V_2 , V_85 , V_141 , V_62 , V_63 , V_142 ) ;
if ( V_2 -> V_50 -> V_143 )
for ( V_30 = 0 ; V_30 < 6 ; V_30 ++ )
F_68 ( V_2 , V_85 , V_30 , false , NULL ) ;
#ifdef F_44
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_116 . V_117 = V_118 ;
F_46 ( V_85 , V_121 , & V_108 , NULL ) ;
V_4 -> V_120 . V_144 . V_40 = 0 ;
#endif
F_35 ( & V_145 ) ;
}
void F_69 ( struct V_84 * V_85 , T_2 V_141 ,
T_1 * V_62 , T_3 V_63 , T_4 V_128 )
{
struct V_3 * V_4 = V_85 -> V_86 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_129 * V_130 ;
unsigned long V_34 ;
F_57 ( V_4 -> V_7 != V_125 ) ;
V_130 = F_17 ( sizeof( * V_130 ) + V_63 , V_128 ) ;
if ( ! V_130 )
return;
V_130 -> type = V_146 ;
V_130 -> V_147 . V_62 = ( ( T_1 * ) V_130 ) + sizeof( * V_130 ) ;
V_130 -> V_147 . V_63 = V_63 ;
memcpy ( ( void * ) V_130 -> V_147 . V_62 , V_62 , V_63 ) ;
V_130 -> V_147 . V_141 = V_141 ;
F_58 ( & V_4 -> V_133 , V_34 ) ;
F_59 ( & V_130 -> V_134 , & V_4 -> V_135 ) ;
F_60 ( & V_4 -> V_133 , V_34 ) ;
F_61 ( V_136 , & V_2 -> V_137 ) ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
struct V_46 * V_144 ,
struct V_148 * V_149 ,
const T_1 * V_47 )
{
struct V_3 * V_4 = V_85 -> V_86 ;
struct V_78 * V_79 = NULL ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_8 )
return - V_150 ;
if ( F_41 ( V_4 -> V_97 ) ) {
F_21 ( V_4 -> V_97 ) ;
V_4 -> V_97 = NULL ;
}
F_71 ( & V_144 -> V_68 ,
V_2 -> V_11 . V_151 ) ;
if ( V_149 && V_149 -> V_152 >= 0 ) {
int V_153 ;
T_5 V_154 ;
V_153 = V_149 -> V_152 ;
V_154 = V_149 -> V_20 [ V_153 ] . V_154 ;
if ( V_154 == V_155 ||
V_154 == V_156 ) {
V_144 -> V_57 = V_153 ;
V_144 -> V_55 = V_149 -> V_20 [ V_153 ] . V_55 ;
V_144 -> V_56 = V_149 -> V_20 [ V_153 ] . V_56 ;
if ( V_144 -> V_66 . V_157 == 0 )
V_144 -> V_66 . V_157 = V_154 ;
if ( V_144 -> V_66 . V_158 == 0 ) {
V_144 -> V_66 . V_158 = 1 ;
V_144 -> V_66 . V_159 [ 0 ] = V_154 ;
}
}
}
if ( ! V_2 -> V_50 -> V_144 ) {
if ( ! V_2 -> V_50 -> V_51 || ! V_2 -> V_50 -> V_59 )
return - V_160 ;
if ( F_41 ( V_4 -> V_19 ) )
return - V_161 ;
V_4 -> V_19 = F_17 ( sizeof( * V_4 -> V_19 ) , V_28 ) ;
if ( ! V_4 -> V_19 )
return - V_29 ;
memcpy ( & V_4 -> V_19 -> V_20 , V_144 , sizeof( * V_144 ) ) ;
if ( V_144 -> V_54 ) {
V_4 -> V_19 -> V_20 . V_54 = V_4 -> V_19 -> V_54 ;
memcpy ( V_4 -> V_19 -> V_54 , V_144 -> V_54 , V_74 ) ;
}
if ( V_144 -> V_62 ) {
V_4 -> V_19 -> V_62 = F_54 ( V_144 -> V_62 , V_144 -> V_63 ,
V_28 ) ;
V_4 -> V_19 -> V_20 . V_62 = V_4 -> V_19 -> V_62 ;
if ( ! V_4 -> V_19 -> V_62 ) {
F_21 ( V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
return - V_29 ;
}
}
if ( V_144 -> V_53 == V_162 ) {
V_4 -> V_19 -> V_94 = true ;
V_4 -> V_19 -> V_20 . V_53 =
V_96 ;
} else {
V_4 -> V_19 -> V_94 = false ;
}
memcpy ( V_4 -> V_39 , V_144 -> V_39 , V_144 -> V_40 ) ;
V_4 -> V_40 = V_144 -> V_40 ;
V_4 -> V_19 -> V_20 . V_39 = V_4 -> V_39 ;
V_4 -> V_19 -> V_20 . V_40 = V_144 -> V_40 ;
V_79 = F_33 ( V_4 ) ;
V_4 -> V_7 = V_76 ;
V_4 -> V_97 = V_149 ;
if ( V_47 ) {
memcpy ( V_4 -> V_19 -> V_47 , V_47 , V_74 ) ;
V_4 -> V_19 -> V_61 = true ;
}
if ( V_79 ) {
V_4 -> V_19 -> V_43 = V_49 ;
V_15 = F_22 ( V_4 ) ;
F_37 ( V_4 -> V_11 , V_79 ) ;
} else {
V_15 = F_11 ( V_4 ) ;
if ( V_15 == - V_18 ) {
V_15 = 0 ;
V_4 -> V_19 -> V_43 = V_48 ;
}
}
if ( V_15 ) {
F_21 ( V_4 -> V_19 -> V_62 ) ;
F_21 ( V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
V_4 -> V_7 = V_8 ;
V_4 -> V_97 = NULL ;
V_4 -> V_40 = 0 ;
}
return V_15 ;
} else {
V_4 -> V_7 = V_76 ;
V_4 -> V_97 = V_149 ;
V_15 = F_72 ( V_2 , V_85 , V_144 ) ;
if ( V_15 ) {
V_4 -> V_97 = NULL ;
V_4 -> V_7 = V_8 ;
return V_15 ;
}
memcpy ( V_4 -> V_39 , V_144 -> V_39 , V_144 -> V_40 ) ;
V_4 -> V_40 = V_144 -> V_40 ;
return 0 ;
}
}
int F_73 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
struct V_46 * V_144 ,
struct V_148 * V_149 )
{
int V_15 ;
F_2 ( & V_2 -> V_75 ) ;
F_2 ( & V_2 -> V_16 ) ;
F_5 ( V_85 -> V_86 ) ;
V_15 = F_70 ( V_2 , V_85 , V_144 , V_149 , NULL ) ;
F_6 ( V_85 -> V_86 ) ;
F_8 ( & V_2 -> V_16 ) ;
F_8 ( & V_2 -> V_75 ) ;
return V_15 ;
}
int F_74 ( struct V_1 * V_2 ,
struct V_84 * V_85 , T_2 V_141 , bool V_105 )
{
struct V_3 * V_4 = V_85 -> V_86 ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 == V_8 )
return - V_71 ;
F_21 ( V_4 -> V_97 ) ;
V_4 -> V_97 = NULL ;
if ( ! V_2 -> V_50 -> V_163 ) {
if ( ! V_2 -> V_50 -> V_164 )
return - V_160 ;
if ( ! V_4 -> V_19 ) {
F_75 ( V_2 , V_85 ) ;
return 0 ;
}
if ( V_4 -> V_7 == V_76 &&
( V_4 -> V_19 -> V_43 == V_44 ||
V_4 -> V_19 -> V_43 == V_48 ) ) {
V_4 -> V_7 = V_8 ;
F_21 ( V_4 -> V_19 -> V_62 ) ;
F_21 ( V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
V_4 -> V_40 = 0 ;
return 0 ;
}
V_15 = F_26 ( V_2 , V_85 ,
V_4 -> V_19 -> V_20 . V_54 ,
NULL , 0 , V_141 , false ) ;
if ( V_15 )
return V_15 ;
} else {
V_15 = F_76 ( V_2 , V_85 , V_141 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_4 -> V_7 == V_125 )
F_66 ( V_85 , NULL , 0 , 0 , false ) ;
else if ( V_4 -> V_7 == V_76 )
F_31 ( V_85 , NULL , NULL , 0 , NULL , 0 ,
V_77 ,
V_105 , NULL ) ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
T_2 V_141 , bool V_105 )
{
int V_15 ;
F_5 ( V_85 -> V_86 ) ;
V_15 = F_74 ( V_2 , V_85 , V_141 , V_105 ) ;
F_6 ( V_85 -> V_86 ) ;
return V_15 ;
}
void F_78 ( struct V_84 * V_85 ,
struct V_165 * V_79 )
{
struct V_3 * V_4 = V_85 -> V_86 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
T_1 V_54 [ V_74 ] ;
F_15 ( V_4 ) ;
if ( ! V_4 -> V_19 )
return;
if ( V_4 -> V_19 -> V_43 == V_124 )
return;
memcpy ( V_54 , V_79 -> V_123 . V_54 , V_74 ) ;
F_26 ( V_2 , V_85 , V_54 , NULL , 0 ,
V_69 , false ) ;
}
