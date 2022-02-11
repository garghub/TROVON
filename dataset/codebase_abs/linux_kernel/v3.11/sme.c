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
F_6 ( V_6 ) ;
F_7 ( V_2 ) ;
if ( V_6 -> V_12 )
return - V_13 ;
if ( V_2 -> V_3 -> V_14 . V_15 ) {
V_10 = 1 ;
} else {
enum V_16 V_17 ;
V_10 = 0 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
if ( ! V_2 -> V_7 -> V_19 [ V_17 ] )
continue;
V_10 += V_2 -> V_7 -> V_19 [ V_17 ] -> V_10 ;
}
}
V_9 = F_8 ( sizeof( * V_9 ) + sizeof( V_9 -> V_20 [ 0 ] ) +
sizeof( V_9 -> V_21 [ 0 ] ) * V_10 ,
V_22 ) ;
if ( ! V_9 )
return - V_23 ;
if ( V_2 -> V_3 -> V_14 . V_15 )
V_9 -> V_21 [ 0 ] = V_2 -> V_3 -> V_14 . V_15 ;
else {
int V_24 = 0 , V_25 ;
enum V_16 V_17 ;
struct V_26 * V_19 ;
struct V_27 * V_15 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
V_19 = V_2 -> V_7 -> V_19 [ V_17 ] ;
if ( ! V_19 )
continue;
for ( V_25 = 0 ; V_25 < V_19 -> V_10 ; V_25 ++ ) {
V_15 = & V_19 -> V_21 [ V_25 ] ;
if ( V_15 -> V_28 & V_29 )
continue;
V_9 -> V_21 [ V_24 ++ ] = V_15 ;
}
V_9 -> V_30 [ V_17 ] = ( 1 << V_19 -> V_31 ) - 1 ;
}
V_10 = V_24 ;
}
V_9 -> V_10 = V_10 ;
V_9 -> V_20 = ( void * ) & V_9 -> V_21 [ V_10 ] ;
V_9 -> V_32 = 1 ;
memcpy ( V_9 -> V_20 [ 0 ] . V_33 , V_2 -> V_3 -> V_14 . V_33 ,
V_2 -> V_3 -> V_14 . V_34 ) ;
V_9 -> V_20 [ 0 ] . V_34 = V_2 -> V_3 -> V_14 . V_34 ;
V_9 -> V_2 = V_2 ;
V_9 -> V_7 = & V_6 -> V_7 ;
V_9 -> V_35 = V_36 ;
V_6 -> V_12 = V_9 ;
V_11 = F_9 ( V_6 , V_9 ) ;
if ( ! V_11 ) {
V_2 -> V_3 -> V_37 = V_38 ;
F_10 ( V_6 , V_2 ) ;
F_11 ( V_2 -> V_39 ) ;
} else {
V_6 -> V_12 = NULL ;
F_2 ( V_9 ) ;
}
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_40 * V_14 ;
struct V_41 V_42 = {} ;
int V_11 ;
F_7 ( V_2 ) ;
if ( ! V_2 -> V_3 )
return 0 ;
V_14 = & V_2 -> V_3 -> V_14 ;
switch ( V_2 -> V_3 -> V_37 ) {
case V_38 :
return - V_43 ;
case V_44 :
return F_3 ( V_2 ) ;
case V_45 :
F_13 ( ! V_6 -> V_46 -> V_47 ) ;
V_2 -> V_3 -> V_37 = V_48 ;
return F_14 ( V_6 , V_2 -> V_39 ,
V_14 -> V_15 , V_14 -> V_49 ,
V_14 -> V_50 ,
V_14 -> V_33 , V_14 -> V_34 ,
NULL , 0 ,
V_14 -> V_51 , V_14 -> V_52 ,
V_14 -> V_53 , NULL , 0 ) ;
case V_54 :
return - V_55 ;
case V_56 :
F_13 ( ! V_6 -> V_46 -> V_57 ) ;
V_2 -> V_3 -> V_37 = V_58 ;
if ( V_2 -> V_3 -> V_59 )
V_42 . V_60 = V_2 -> V_3 -> V_60 ;
V_42 . V_4 = V_14 -> V_4 ;
V_42 . V_61 = V_14 -> V_61 ;
V_42 . V_62 = V_14 -> V_63 != V_64 ;
V_42 . V_65 = V_14 -> V_65 ;
V_42 . V_28 = V_14 -> V_28 ;
V_42 . V_66 = V_14 -> V_66 ;
V_42 . V_67 = V_14 -> V_67 ;
V_42 . V_68 = V_14 -> V_68 ;
V_42 . V_69 = V_14 -> V_69 ;
V_11 = F_15 ( V_6 , V_2 -> V_39 , V_14 -> V_15 ,
V_14 -> V_50 , V_14 -> V_33 ,
V_14 -> V_34 , & V_42 ) ;
if ( V_11 )
F_16 ( V_6 , V_2 -> V_39 , V_14 -> V_50 ,
NULL , 0 ,
V_70 ,
false ) ;
return V_11 ;
case V_71 :
F_16 ( V_6 , V_2 -> V_39 , V_14 -> V_50 ,
NULL , 0 ,
V_70 , false ) ;
return - V_55 ;
case V_72 :
F_16 ( V_6 , V_2 -> V_39 , V_14 -> V_50 ,
NULL , 0 ,
V_70 , false ) ;
F_1 ( V_2 ) ;
return 0 ;
default:
return 0 ;
}
}
void F_17 ( struct V_73 * V_74 )
{
struct V_5 * V_6 =
F_18 ( V_74 , struct V_5 , V_75 ) ;
struct V_1 * V_2 ;
T_1 V_76 [ V_77 ] , * V_50 = NULL ;
F_19 () ;
F_20 (wdev, &rdev->wdev_list, list) {
if ( ! V_2 -> V_39 )
continue;
F_21 ( V_2 ) ;
if ( ! F_22 ( V_2 -> V_39 ) ) {
F_23 ( V_2 ) ;
continue;
}
if ( ! V_2 -> V_3 ||
V_2 -> V_3 -> V_37 == V_78 ) {
F_23 ( V_2 ) ;
continue;
}
if ( V_2 -> V_3 -> V_14 . V_50 ) {
memcpy ( V_76 , V_2 -> V_3 -> V_14 . V_50 , V_77 ) ;
V_50 = V_76 ;
}
if ( F_12 ( V_2 ) ) {
F_24 (
V_2 -> V_39 , V_50 ,
NULL , 0 , NULL , 0 ,
V_79 ,
false , NULL ) ;
F_1 ( V_2 ) ;
}
F_23 ( V_2 ) ;
}
F_25 () ;
}
static struct V_80 * F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_80 * V_81 ;
T_2 V_82 = V_83 ;
F_7 ( V_2 ) ;
if ( V_2 -> V_3 -> V_14 . V_84 )
V_82 |= V_85 ;
V_81 = F_27 ( V_2 -> V_7 , V_2 -> V_3 -> V_14 . V_15 ,
V_2 -> V_3 -> V_14 . V_50 ,
V_2 -> V_3 -> V_14 . V_33 ,
V_2 -> V_3 -> V_14 . V_34 ,
V_83 | V_85 ,
V_82 ) ;
if ( ! V_81 )
return NULL ;
memcpy ( V_2 -> V_3 -> V_50 , V_81 -> V_50 , V_77 ) ;
V_2 -> V_3 -> V_14 . V_50 = V_2 -> V_3 -> V_50 ;
V_2 -> V_3 -> V_14 . V_15 = V_81 -> V_15 ;
V_2 -> V_3 -> V_37 = V_45 ;
F_28 ( & V_6 -> V_75 ) ;
return V_81 ;
}
static void F_29 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = V_87 -> V_88 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_80 * V_81 ;
F_7 ( V_2 ) ;
if ( ! V_2 -> V_3 )
return;
if ( V_2 -> V_3 -> V_37 != V_38 &&
V_2 -> V_3 -> V_37 != V_44 )
return;
V_81 = F_26 ( V_2 ) ;
if ( V_81 )
F_30 ( & V_6 -> V_7 , V_81 ) ;
else
F_28 ( & V_6 -> V_75 ) ;
}
void F_31 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = V_87 -> V_88 ;
F_21 ( V_2 ) ;
F_29 ( V_87 ) ;
F_23 ( V_2 ) ;
}
void F_32 ( struct V_1 * V_2 , const T_1 * V_89 , T_3 V_90 )
{
struct V_7 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_91 * V_92 = (struct V_91 * ) V_89 ;
T_2 V_93 = F_33 ( V_92 -> V_94 . V_47 . V_93 ) ;
F_7 ( V_2 ) ;
if ( ! V_2 -> V_3 || V_2 -> V_3 -> V_37 == V_78 )
return;
if ( V_93 == V_95 &&
V_2 -> V_3 -> V_96 &&
V_2 -> V_3 -> V_14 . V_49 != V_97 ) {
switch ( V_2 -> V_3 -> V_14 . V_49 ) {
case V_98 :
if ( V_2 -> V_99 )
V_2 -> V_3 -> V_14 . V_49 =
V_100 ;
else
V_2 -> V_3 -> V_14 . V_49 =
V_97 ;
break;
case V_100 :
V_2 -> V_3 -> V_14 . V_49 =
V_97 ;
break;
default:
V_2 -> V_3 -> V_14 . V_49 =
V_98 ;
break;
}
V_2 -> V_3 -> V_37 = V_45 ;
F_28 ( & V_6 -> V_75 ) ;
} else if ( V_93 != V_101 ) {
F_24 ( V_2 -> V_39 , V_92 -> V_50 ,
NULL , 0 , NULL , 0 ,
V_93 , false , NULL ) ;
} else if ( V_2 -> V_3 -> V_37 == V_48 ) {
V_2 -> V_3 -> V_37 = V_56 ;
F_28 ( & V_6 -> V_75 ) ;
}
}
bool F_34 ( struct V_1 * V_2 , T_2 V_102 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return false ;
if ( V_102 == V_101 ) {
V_2 -> V_3 -> V_37 = V_78 ;
return false ;
}
if ( V_2 -> V_3 -> V_59 ) {
V_2 -> V_3 -> V_59 = false ;
V_2 -> V_3 -> V_37 = V_56 ;
F_28 ( & V_6 -> V_75 ) ;
return true ;
}
V_2 -> V_3 -> V_37 = V_71 ;
F_28 ( & V_6 -> V_75 ) ;
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
V_2 -> V_3 -> V_37 = V_54 ;
F_28 ( & V_6 -> V_75 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_37 = V_72 ;
F_28 ( & V_6 -> V_75 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_37 = V_71 ;
F_28 ( & V_6 -> V_75 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_40 * V_103 ,
const T_1 * V_60 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_80 * V_81 ;
int V_11 ;
if ( ! V_6 -> V_46 -> V_47 || ! V_6 -> V_46 -> V_57 )
return - V_104 ;
if ( V_2 -> V_105 )
return - V_106 ;
if ( F_40 ( V_2 -> V_3 ) )
return - V_107 ;
V_2 -> V_3 = F_8 ( sizeof( * V_2 -> V_3 ) , V_22 ) ;
if ( ! V_2 -> V_3 )
return - V_23 ;
memcpy ( & V_2 -> V_3 -> V_14 , V_103 , sizeof( * V_103 ) ) ;
if ( V_103 -> V_50 ) {
V_2 -> V_3 -> V_14 . V_50 = V_2 -> V_3 -> V_50 ;
memcpy ( V_2 -> V_3 -> V_50 , V_103 -> V_50 , V_77 ) ;
}
if ( V_103 -> V_4 ) {
V_2 -> V_3 -> V_4 = F_41 ( V_103 -> V_4 , V_103 -> V_61 ,
V_22 ) ;
V_2 -> V_3 -> V_14 . V_4 = V_2 -> V_3 -> V_4 ;
if ( ! V_2 -> V_3 -> V_4 ) {
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return - V_23 ;
}
}
if ( V_103 -> V_49 == V_108 ) {
V_2 -> V_3 -> V_96 = true ;
V_2 -> V_3 -> V_14 . V_49 =
V_98 ;
} else {
V_2 -> V_3 -> V_96 = false ;
}
V_2 -> V_3 -> V_14 . V_33 = V_2 -> V_33 ;
V_2 -> V_3 -> V_14 . V_34 = V_103 -> V_34 ;
V_81 = F_26 ( V_2 ) ;
if ( V_60 ) {
memcpy ( V_2 -> V_3 -> V_60 , V_60 , V_77 ) ;
V_2 -> V_3 -> V_59 = true ;
}
if ( V_81 ) {
V_2 -> V_3 -> V_37 = V_45 ;
V_11 = F_12 ( V_2 ) ;
F_30 ( V_2 -> V_7 , V_81 ) ;
} else {
V_11 = F_3 ( V_2 ) ;
if ( V_11 == - V_13 ) {
V_11 = 0 ;
V_2 -> V_3 -> V_37 = V_44 ;
}
}
if ( V_11 )
F_1 ( V_2 ) ;
return V_11 ;
}
static int F_42 ( struct V_1 * V_2 , T_2 V_109 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_11 ;
if ( ! V_2 -> V_3 )
return 0 ;
if ( ! V_6 -> V_46 -> V_110 )
return - V_104 ;
if ( V_2 -> V_3 -> V_37 == V_38 ||
V_2 -> V_3 -> V_37 == V_44 ) {
V_11 = 0 ;
goto V_111;
}
V_11 = F_16 ( V_6 , V_2 -> V_39 ,
V_2 -> V_3 -> V_14 . V_50 ,
NULL , 0 , V_109 , false ) ;
V_111:
F_1 ( V_2 ) ;
return V_11 ;
}
static bool F_43 ( void )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
bool V_112 = true ;
F_20 (rdev, &cfg80211_rdev_list, list) {
F_20 (wdev, &rdev->wdev_list, list) {
F_21 ( V_2 ) ;
if ( V_2 -> V_3 || V_2 -> V_105 )
V_112 = false ;
F_23 ( V_2 ) ;
}
}
return V_112 ;
}
static void F_44 ( struct V_73 * V_74 )
{
F_19 () ;
if ( F_43 () )
F_45 () ;
F_25 () ;
}
void F_24 ( struct V_86 * V_87 , const T_1 * V_50 ,
const T_1 * V_113 , T_3 V_114 ,
const T_1 * V_115 , T_3 V_116 ,
T_2 V_102 , bool V_117 ,
struct V_80 * V_81 )
{
struct V_1 * V_2 = V_87 -> V_88 ;
const T_1 * V_118 ;
#ifdef F_46
union V_119 V_120 ;
#endif
F_7 ( V_2 ) ;
if ( F_40 ( V_2 -> V_121 != V_122 &&
V_2 -> V_121 != V_123 ) ) {
F_30 ( V_2 -> V_7 , V_81 ) ;
return;
}
F_47 ( F_4 ( V_2 -> V_7 ) , V_87 ,
V_50 , V_113 , V_114 ,
V_115 , V_116 ,
V_102 , V_22 ) ;
#ifdef F_46
if ( V_117 ) {
if ( V_113 && V_102 == V_101 ) {
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_124 . V_125 = V_114 ;
F_48 ( V_87 , V_126 , & V_120 , V_113 ) ;
}
if ( V_115 && V_102 == V_101 ) {
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_124 . V_125 = V_116 ;
F_48 ( V_87 , V_127 , & V_120 , V_115 ) ;
}
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_128 . V_129 = V_130 ;
if ( V_50 && V_102 == V_101 ) {
memcpy ( V_120 . V_128 . V_131 , V_50 , V_77 ) ;
memcpy ( V_2 -> V_132 . V_60 , V_50 , V_77 ) ;
V_2 -> V_132 . V_59 = true ;
}
F_48 ( V_87 , V_133 , & V_120 , NULL ) ;
}
#endif
if ( V_2 -> V_105 ) {
F_49 ( V_2 -> V_105 ) ;
F_30 ( V_2 -> V_7 , & V_2 -> V_105 -> V_134 ) ;
V_2 -> V_105 = NULL ;
}
if ( V_102 != V_101 ) {
F_2 ( V_2 -> V_99 ) ;
V_2 -> V_99 = NULL ;
V_2 -> V_34 = 0 ;
if ( V_81 ) {
F_49 ( F_50 ( V_81 ) ) ;
F_30 ( V_2 -> V_7 , V_81 ) ;
}
return;
}
if ( ! V_81 ) {
F_51 ( ! F_4 ( V_2 -> V_7 ) -> V_46 -> V_103 ) ;
V_81 = F_27 ( V_2 -> V_7 , NULL , V_50 ,
V_2 -> V_33 , V_2 -> V_34 ,
V_83 ,
V_83 ) ;
if ( F_40 ( ! V_81 ) )
return;
F_52 ( F_50 ( V_81 ) ) ;
}
V_2 -> V_105 = F_50 ( V_81 ) ;
F_53 ( V_2 ) ;
F_54 () ;
V_118 = F_55 ( V_81 , V_135 ) ;
if ( ! V_118 ) {
F_56 () ;
return;
}
V_118 = F_41 ( V_118 , 2 + V_118 [ 1 ] , V_136 ) ;
F_56 () ;
if ( ! V_118 )
return;
F_57 ( V_2 -> V_7 , V_81 -> V_15 -> V_17 ,
V_118 + 2 , V_118 [ 1 ] ) ;
F_2 ( V_118 ) ;
}
void F_58 ( struct V_86 * V_87 , const T_1 * V_50 ,
const T_1 * V_113 , T_3 V_114 ,
const T_1 * V_115 , T_3 V_116 ,
T_2 V_102 , T_4 V_137 )
{
struct V_1 * V_2 = V_87 -> V_88 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_138 * V_139 ;
unsigned long V_28 ;
V_139 = F_8 ( sizeof( * V_139 ) + V_114 + V_116 , V_137 ) ;
if ( ! V_139 )
return;
V_139 -> type = V_140 ;
if ( V_50 )
memcpy ( V_139 -> V_141 . V_50 , V_50 , V_77 ) ;
if ( V_114 ) {
V_139 -> V_141 . V_113 = ( ( T_1 * ) V_139 ) + sizeof( * V_139 ) ;
V_139 -> V_141 . V_114 = V_114 ;
memcpy ( ( void * ) V_139 -> V_141 . V_113 , V_113 , V_114 ) ;
}
if ( V_116 ) {
V_139 -> V_141 . V_115 = ( ( T_1 * ) V_139 ) + sizeof( * V_139 ) + V_114 ;
V_139 -> V_141 . V_116 = V_116 ;
memcpy ( ( void * ) V_139 -> V_141 . V_115 , V_115 , V_116 ) ;
}
V_139 -> V_141 . V_102 = V_102 ;
F_59 ( & V_2 -> V_142 , V_28 ) ;
F_60 ( & V_139 -> V_143 , & V_2 -> V_144 ) ;
F_61 ( & V_2 -> V_142 , V_28 ) ;
F_62 ( V_145 , & V_6 -> V_146 ) ;
}
void F_63 ( struct V_1 * V_2 ,
struct V_80 * V_81 ,
const T_1 * V_113 , T_3 V_114 ,
const T_1 * V_115 , T_3 V_116 )
{
#ifdef F_46
union V_119 V_120 ;
#endif
F_7 ( V_2 ) ;
if ( F_40 ( V_2 -> V_121 != V_122 &&
V_2 -> V_121 != V_123 ) )
goto V_111;
if ( F_40 ( ! V_2 -> V_105 ) )
goto V_111;
F_49 ( V_2 -> V_105 ) ;
F_30 ( V_2 -> V_7 , & V_2 -> V_105 -> V_134 ) ;
V_2 -> V_105 = NULL ;
F_52 ( F_50 ( V_81 ) ) ;
V_2 -> V_105 = F_50 ( V_81 ) ;
F_64 ( F_4 ( V_2 -> V_7 ) , V_2 -> V_39 , V_81 -> V_50 ,
V_113 , V_114 , V_115 , V_116 ,
V_22 ) ;
#ifdef F_46
if ( V_113 ) {
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_124 . V_125 = V_114 ;
F_48 ( V_2 -> V_39 , V_126 ,
& V_120 , V_113 ) ;
}
if ( V_115 ) {
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_124 . V_125 = V_116 ;
F_48 ( V_2 -> V_39 , V_127 ,
& V_120 , V_115 ) ;
}
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_128 . V_129 = V_130 ;
memcpy ( V_120 . V_128 . V_131 , V_81 -> V_50 , V_77 ) ;
memcpy ( V_2 -> V_132 . V_60 , V_81 -> V_50 , V_77 ) ;
V_2 -> V_132 . V_59 = true ;
F_48 ( V_2 -> V_39 , V_133 , & V_120 , NULL ) ;
#endif
return;
V_111:
F_30 ( V_2 -> V_7 , V_81 ) ;
}
void F_65 ( struct V_86 * V_87 ,
struct V_27 * V_15 ,
const T_1 * V_50 ,
const T_1 * V_113 , T_3 V_114 ,
const T_1 * V_115 , T_3 V_116 , T_4 V_137 )
{
struct V_1 * V_2 = V_87 -> V_88 ;
struct V_80 * V_81 ;
V_81 = F_27 ( V_2 -> V_7 , V_15 , V_50 , V_2 -> V_33 ,
V_2 -> V_34 , V_83 ,
V_83 ) ;
if ( F_40 ( ! V_81 ) )
return;
F_66 ( V_87 , V_81 , V_113 , V_114 , V_115 ,
V_116 , V_137 ) ;
}
void F_66 ( struct V_86 * V_87 ,
struct V_80 * V_81 , const T_1 * V_113 ,
T_3 V_114 , const T_1 * V_115 ,
T_3 V_116 , T_4 V_137 )
{
struct V_1 * V_2 = V_87 -> V_88 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_138 * V_139 ;
unsigned long V_28 ;
if ( F_40 ( ! V_81 ) )
return;
V_139 = F_8 ( sizeof( * V_139 ) + V_114 + V_116 , V_137 ) ;
if ( ! V_139 ) {
F_30 ( V_2 -> V_7 , V_81 ) ;
return;
}
V_139 -> type = V_147 ;
V_139 -> V_148 . V_113 = ( ( T_1 * ) V_139 ) + sizeof( * V_139 ) ;
V_139 -> V_148 . V_114 = V_114 ;
memcpy ( ( void * ) V_139 -> V_148 . V_113 , V_113 , V_114 ) ;
V_139 -> V_148 . V_115 = ( ( T_1 * ) V_139 ) + sizeof( * V_139 ) + V_114 ;
V_139 -> V_148 . V_116 = V_116 ;
memcpy ( ( void * ) V_139 -> V_148 . V_115 , V_115 , V_116 ) ;
V_139 -> V_148 . V_81 = V_81 ;
F_59 ( & V_2 -> V_142 , V_28 ) ;
F_60 ( & V_139 -> V_143 , & V_2 -> V_144 ) ;
F_61 ( & V_2 -> V_142 , V_28 ) ;
F_62 ( V_145 , & V_6 -> V_146 ) ;
}
void F_67 ( struct V_86 * V_87 , const T_1 * V_4 ,
T_3 V_61 , T_2 V_109 , bool V_149 )
{
struct V_1 * V_2 = V_87 -> V_88 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_24 ;
#ifdef F_46
union V_119 V_120 ;
#endif
F_7 ( V_2 ) ;
if ( F_40 ( V_2 -> V_121 != V_122 &&
V_2 -> V_121 != V_123 ) )
return;
if ( V_2 -> V_105 ) {
F_49 ( V_2 -> V_105 ) ;
F_30 ( V_2 -> V_7 , & V_2 -> V_105 -> V_134 ) ;
}
V_2 -> V_105 = NULL ;
V_2 -> V_34 = 0 ;
F_68 ( V_6 , V_87 , V_109 , V_4 , V_61 , V_149 ) ;
if ( V_6 -> V_46 -> V_150 )
for ( V_24 = 0 ; V_24 < 6 ; V_24 ++ )
F_69 ( V_6 , V_87 , V_24 , false , NULL ) ;
#ifdef F_46
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_128 . V_129 = V_130 ;
F_48 ( V_87 , V_133 , & V_120 , NULL ) ;
V_2 -> V_132 . V_103 . V_34 = 0 ;
#endif
F_28 ( & V_151 ) ;
}
void F_70 ( struct V_86 * V_87 , T_2 V_109 ,
T_1 * V_4 , T_3 V_61 , T_4 V_137 )
{
struct V_1 * V_2 = V_87 -> V_88 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_138 * V_139 ;
unsigned long V_28 ;
V_139 = F_8 ( sizeof( * V_139 ) + V_61 , V_137 ) ;
if ( ! V_139 )
return;
V_139 -> type = V_152 ;
V_139 -> V_153 . V_4 = ( ( T_1 * ) V_139 ) + sizeof( * V_139 ) ;
V_139 -> V_153 . V_61 = V_61 ;
memcpy ( ( void * ) V_139 -> V_153 . V_4 , V_4 , V_61 ) ;
V_139 -> V_153 . V_109 = V_109 ;
F_59 ( & V_2 -> V_142 , V_28 ) ;
F_60 ( & V_139 -> V_143 , & V_2 -> V_144 ) ;
F_61 ( & V_2 -> V_142 , V_28 ) ;
F_62 ( V_145 , & V_6 -> V_146 ) ;
}
int F_71 ( struct V_5 * V_6 ,
struct V_86 * V_87 ,
struct V_40 * V_103 ,
struct V_154 * V_155 ,
const T_1 * V_60 )
{
struct V_1 * V_2 = V_87 -> V_88 ;
int V_11 ;
F_7 ( V_2 ) ;
if ( F_40 ( V_2 -> V_99 ) ) {
F_2 ( V_2 -> V_99 ) ;
V_2 -> V_99 = NULL ;
}
F_72 ( & V_103 -> V_67 ,
V_6 -> V_7 . V_156 ) ;
if ( V_155 && V_155 -> V_157 >= 0 ) {
int V_158 ;
T_5 V_159 ;
V_158 = V_155 -> V_157 ;
V_159 = V_155 -> V_14 [ V_158 ] . V_159 ;
if ( V_159 == V_160 ||
V_159 == V_161 ) {
V_103 -> V_53 = V_158 ;
V_103 -> V_51 = V_155 -> V_14 [ V_158 ] . V_51 ;
V_103 -> V_52 = V_155 -> V_14 [ V_158 ] . V_52 ;
if ( V_103 -> V_65 . V_162 == 0 )
V_103 -> V_65 . V_162 = V_159 ;
if ( V_103 -> V_65 . V_163 == 0 ) {
V_103 -> V_65 . V_163 = 1 ;
V_103 -> V_65 . V_164 [ 0 ] = V_159 ;
}
}
}
V_2 -> V_99 = V_155 ;
memcpy ( V_2 -> V_33 , V_103 -> V_33 , V_103 -> V_34 ) ;
V_2 -> V_34 = V_103 -> V_34 ;
if ( ! V_6 -> V_46 -> V_103 )
V_11 = F_39 ( V_2 , V_103 , V_60 ) ;
else
V_11 = F_73 ( V_6 , V_87 , V_103 ) ;
if ( V_11 ) {
V_2 -> V_99 = NULL ;
V_2 -> V_34 = 0 ;
return V_11 ;
}
return 0 ;
}
int F_74 ( struct V_5 * V_6 ,
struct V_86 * V_87 , T_2 V_109 , bool V_117 )
{
struct V_1 * V_2 = V_87 -> V_88 ;
int V_11 = 0 ;
F_7 ( V_2 ) ;
F_2 ( V_2 -> V_99 ) ;
V_2 -> V_99 = NULL ;
if ( V_2 -> V_3 )
V_11 = F_42 ( V_2 , V_109 ) ;
else if ( ! V_6 -> V_46 -> V_165 )
F_75 ( V_6 , V_87 ) ;
else if ( V_2 -> V_105 )
V_11 = F_76 ( V_6 , V_87 , V_109 ) ;
return V_11 ;
}
