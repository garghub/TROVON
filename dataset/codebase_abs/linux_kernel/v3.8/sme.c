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
if ( V_2 -> V_16 )
return - V_17 ;
if ( V_4 -> V_18 -> V_19 . V_20 ) {
V_14 = 1 ;
} else {
enum V_21 V_22 ;
V_14 = 0 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! V_4 -> V_11 -> V_24 [ V_22 ] )
continue;
V_14 += V_4 -> V_11 -> V_24 [ V_22 ] -> V_14 ;
}
}
V_13 = F_16 ( sizeof( * V_13 ) + sizeof( V_13 -> V_25 [ 0 ] ) +
sizeof( V_13 -> V_26 [ 0 ] ) * V_14 ,
V_27 ) ;
if ( ! V_13 )
return - V_28 ;
if ( V_4 -> V_18 -> V_19 . V_20 )
V_13 -> V_26 [ 0 ] = V_4 -> V_18 -> V_19 . V_20 ;
else {
int V_29 = 0 , V_30 ;
enum V_21 V_22 ;
struct V_31 * V_24 ;
struct V_32 * V_20 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_24 = V_4 -> V_11 -> V_24 [ V_22 ] ;
if ( ! V_24 )
continue;
for ( V_30 = 0 ; V_30 < V_24 -> V_14 ; V_30 ++ ) {
V_20 = & V_24 -> V_26 [ V_30 ] ;
if ( V_20 -> V_33 & V_34 )
continue;
V_13 -> V_26 [ V_29 ++ ] = V_20 ;
}
V_13 -> V_35 [ V_22 ] = ( 1 << V_24 -> V_36 ) - 1 ;
}
V_14 = V_29 ;
}
V_13 -> V_14 = V_14 ;
V_13 -> V_25 = ( void * ) & V_13 -> V_26 [ V_14 ] ;
V_13 -> V_37 = 1 ;
memcpy ( V_13 -> V_25 [ 0 ] . V_38 , V_4 -> V_18 -> V_19 . V_38 ,
V_4 -> V_18 -> V_19 . V_39 ) ;
V_13 -> V_25 [ 0 ] . V_39 = V_4 -> V_18 -> V_19 . V_39 ;
V_13 -> V_4 = V_4 ;
V_13 -> V_11 = & V_2 -> V_11 ;
V_13 -> V_40 = V_41 ;
V_2 -> V_16 = V_13 ;
V_15 = F_17 ( V_2 , V_13 ) ;
if ( ! V_15 ) {
V_4 -> V_18 -> V_42 = V_43 ;
F_18 ( V_2 , V_4 ) ;
F_19 ( V_4 -> V_44 ) ;
} else {
V_2 -> V_16 = NULL ;
F_20 ( V_13 ) ;
}
return V_15 ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_45 * V_19 ;
const T_1 * V_46 = NULL ;
int V_15 ;
F_15 ( V_4 ) ;
if ( ! V_4 -> V_18 )
return 0 ;
V_19 = & V_4 -> V_18 -> V_19 ;
switch ( V_4 -> V_18 -> V_42 ) {
case V_47 :
return F_11 ( V_4 ) ;
case V_48 :
F_22 ( ! V_2 -> V_49 -> V_50 ) ;
V_4 -> V_18 -> V_42 = V_51 ;
return F_23 ( V_2 , V_4 -> V_44 ,
V_19 -> V_20 , V_19 -> V_52 ,
V_19 -> V_53 ,
V_19 -> V_38 , V_19 -> V_39 ,
NULL , 0 ,
V_19 -> V_54 , V_19 -> V_55 ,
V_19 -> V_56 , NULL , 0 ) ;
case V_57 :
F_22 ( ! V_2 -> V_49 -> V_58 ) ;
V_4 -> V_18 -> V_42 = V_59 ;
if ( V_4 -> V_18 -> V_60 )
V_46 = V_4 -> V_18 -> V_46 ;
V_15 = F_24 ( V_2 , V_4 -> V_44 ,
V_19 -> V_20 , V_19 -> V_53 ,
V_46 ,
V_19 -> V_38 , V_19 -> V_39 ,
V_19 -> V_61 , V_19 -> V_62 ,
false , & V_19 -> V_63 ,
V_19 -> V_33 , & V_19 -> V_64 ,
& V_19 -> V_65 ) ;
if ( V_15 )
F_25 ( V_2 , V_4 -> V_44 , V_19 -> V_53 ,
NULL , 0 ,
V_66 ,
false ) ;
return V_15 ;
case V_67 :
F_25 ( V_2 , V_4 -> V_44 , V_19 -> V_53 ,
NULL , 0 ,
V_66 , false ) ;
return - V_68 ;
default:
return 0 ;
}
}
void F_26 ( struct V_9 * V_10 )
{
struct V_1 * V_2 =
F_27 ( V_10 , struct V_1 , V_69 ) ;
struct V_3 * V_4 ;
T_1 V_70 [ V_71 ] , * V_53 = NULL ;
F_28 () ;
F_4 ( V_2 ) ;
F_2 ( & V_2 -> V_72 ) ;
F_3 (wdev, &rdev->wdev_list, list) {
F_5 ( V_4 ) ;
if ( ! F_29 ( V_4 -> V_44 ) ) {
F_6 ( V_4 ) ;
continue;
}
if ( V_4 -> V_7 != V_73 ) {
F_6 ( V_4 ) ;
continue;
}
if ( V_4 -> V_18 -> V_19 . V_53 ) {
memcpy ( V_70 , V_4 -> V_18 -> V_19 . V_53 , V_71 ) ;
V_53 = V_70 ;
}
if ( F_21 ( V_4 ) )
F_30 (
V_4 -> V_44 , V_53 ,
NULL , 0 , NULL , 0 ,
V_74 ,
false , NULL ) ;
F_6 ( V_4 ) ;
}
F_8 ( & V_2 -> V_72 ) ;
F_7 ( V_2 ) ;
F_31 () ;
}
static struct V_75 * F_32 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_75 * V_76 ;
T_2 V_77 = V_78 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_18 -> V_19 . V_79 )
V_77 |= V_80 ;
V_76 = F_33 ( V_4 -> V_11 , V_4 -> V_18 -> V_19 . V_20 ,
V_4 -> V_18 -> V_19 . V_53 ,
V_4 -> V_18 -> V_19 . V_38 ,
V_4 -> V_18 -> V_19 . V_39 ,
V_78 | V_80 ,
V_77 ) ;
if ( ! V_76 )
return NULL ;
memcpy ( V_4 -> V_18 -> V_53 , V_76 -> V_53 , V_71 ) ;
V_4 -> V_18 -> V_19 . V_53 = V_4 -> V_18 -> V_53 ;
V_4 -> V_18 -> V_19 . V_20 = V_76 -> V_20 ;
V_4 -> V_18 -> V_42 = V_48 ;
F_34 ( & V_2 -> V_69 ) ;
return V_76 ;
}
static void F_35 ( struct V_81 * V_82 )
{
struct V_3 * V_4 = V_82 -> V_83 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_75 * V_76 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_73 )
return;
if ( ! V_4 -> V_18 )
return;
if ( V_4 -> V_18 -> V_42 != V_43 &&
V_4 -> V_18 -> V_42 != V_47 )
return;
V_76 = F_32 ( V_4 ) ;
if ( V_76 ) {
F_36 ( V_76 ) ;
} else {
if ( V_4 -> V_18 -> V_42 == V_47 )
F_34 ( & V_2 -> V_69 ) ;
else
F_30 (
V_4 -> V_44 ,
V_4 -> V_18 -> V_19 . V_53 ,
NULL , 0 , NULL , 0 ,
V_74 ,
false , NULL ) ;
}
}
void F_37 ( struct V_81 * V_82 )
{
struct V_3 * V_4 = V_82 -> V_83 ;
F_2 ( & F_12 ( V_4 -> V_11 ) -> V_72 ) ;
F_5 ( V_4 ) ;
F_35 ( V_82 ) ;
F_6 ( V_4 ) ;
F_8 ( & F_12 ( V_4 -> V_11 ) -> V_72 ) ;
}
void F_38 ( struct V_81 * V_82 ,
const T_1 * V_84 , T_3 V_85 )
{
struct V_3 * V_4 = V_82 -> V_83 ;
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
struct V_86 * V_87 = (struct V_86 * ) V_84 ;
T_2 V_88 = F_39 ( V_87 -> V_89 . V_50 . V_88 ) ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_73 )
return;
if ( F_40 ( ! V_4 -> V_18 ) )
return;
if ( V_88 == V_90 &&
V_4 -> V_18 -> V_91 &&
V_4 -> V_18 -> V_19 . V_52 != V_92 ) {
switch ( V_4 -> V_18 -> V_19 . V_52 ) {
case V_93 :
if ( V_4 -> V_94 )
V_4 -> V_18 -> V_19 . V_52 =
V_95 ;
else
V_4 -> V_18 -> V_19 . V_52 =
V_92 ;
break;
case V_95 :
V_4 -> V_18 -> V_19 . V_52 =
V_92 ;
break;
default:
V_4 -> V_18 -> V_19 . V_52 =
V_93 ;
break;
}
V_4 -> V_18 -> V_42 = V_48 ;
F_34 ( & V_2 -> V_69 ) ;
} else if ( V_88 != V_96 ) {
F_30 ( V_82 , V_87 -> V_53 , NULL , 0 , NULL , 0 ,
V_88 , false , NULL ) ;
} else if ( V_4 -> V_7 == V_73 &&
V_4 -> V_18 -> V_42 == V_51 ) {
V_4 -> V_18 -> V_42 = V_57 ;
F_34 ( & V_2 -> V_69 ) ;
}
}
bool F_41 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
if ( F_40 ( ! V_4 -> V_18 ) )
return false ;
if ( ! V_4 -> V_18 -> V_60 )
return false ;
V_4 -> V_18 -> V_60 = false ;
V_4 -> V_18 -> V_42 = V_57 ;
F_34 ( & V_2 -> V_69 ) ;
return true ;
}
void F_42 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
V_4 -> V_18 -> V_42 = V_67 ;
F_34 ( & V_2 -> V_69 ) ;
}
void F_30 ( struct V_81 * V_82 , const T_1 * V_53 ,
const T_1 * V_97 , T_3 V_98 ,
const T_1 * V_99 , T_3 V_100 ,
T_2 V_101 , bool V_102 ,
struct V_75 * V_76 )
{
struct V_3 * V_4 = V_82 -> V_83 ;
const T_1 * V_103 ;
#ifdef F_43
union V_104 V_105 ;
#endif
F_15 ( V_4 ) ;
if ( F_40 ( V_4 -> V_106 != V_107 &&
V_4 -> V_106 != V_108 ) )
return;
if ( V_4 -> V_7 != V_73 )
return;
F_44 ( F_12 ( V_4 -> V_11 ) , V_82 ,
V_53 , V_97 , V_98 ,
V_99 , V_100 ,
V_101 , V_27 ) ;
#ifdef F_43
if ( V_102 ) {
if ( V_97 && V_101 == V_96 ) {
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . V_109 . V_110 = V_98 ;
F_45 ( V_82 , V_111 , & V_105 , V_97 ) ;
}
if ( V_99 && V_101 == V_96 ) {
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . V_109 . V_110 = V_100 ;
F_45 ( V_82 , V_112 , & V_105 , V_99 ) ;
}
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . V_113 . V_114 = V_115 ;
if ( V_53 && V_101 == V_96 ) {
memcpy ( V_105 . V_113 . V_116 , V_53 , V_71 ) ;
memcpy ( V_4 -> V_117 . V_46 , V_53 , V_71 ) ;
V_4 -> V_117 . V_60 = true ;
}
F_45 ( V_82 , V_118 , & V_105 , NULL ) ;
}
#endif
if ( V_4 -> V_119 ) {
F_46 ( V_4 -> V_119 ) ;
F_36 ( & V_4 -> V_119 -> V_120 ) ;
V_4 -> V_119 = NULL ;
}
if ( V_4 -> V_18 )
V_4 -> V_18 -> V_42 = V_121 ;
if ( V_101 != V_96 ) {
V_4 -> V_7 = V_8 ;
if ( V_4 -> V_18 )
F_20 ( V_4 -> V_18 -> V_61 ) ;
F_20 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
F_20 ( V_4 -> V_94 ) ;
V_4 -> V_94 = NULL ;
V_4 -> V_39 = 0 ;
F_36 ( V_76 ) ;
return;
}
if ( ! V_76 )
V_76 = F_33 ( V_4 -> V_11 ,
V_4 -> V_18 ? V_4 -> V_18 -> V_19 . V_20 :
NULL ,
V_53 ,
V_4 -> V_38 , V_4 -> V_39 ,
V_78 ,
V_78 ) ;
if ( F_40 ( ! V_76 ) )
return;
F_47 ( F_48 ( V_76 ) ) ;
V_4 -> V_119 = F_48 ( V_76 ) ;
V_4 -> V_7 = V_122 ;
F_49 ( V_4 ) ;
F_50 () ;
V_103 = F_51 ( V_76 , V_123 ) ;
if ( ! V_103 ) {
F_52 () ;
return;
}
V_103 = F_53 ( V_103 , 2 + V_103 [ 1 ] , V_124 ) ;
F_52 () ;
if ( ! V_103 )
return;
F_54 ( V_4 -> V_11 ,
V_76 -> V_20 -> V_22 ,
V_103 + 2 ,
V_103 [ 1 ] ) ;
F_20 ( V_103 ) ;
}
void F_55 ( struct V_81 * V_82 , const T_1 * V_53 ,
const T_1 * V_97 , T_3 V_98 ,
const T_1 * V_99 , T_3 V_100 ,
T_2 V_101 , T_4 V_125 )
{
struct V_3 * V_4 = V_82 -> V_83 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_126 * V_127 ;
unsigned long V_33 ;
F_56 ( V_4 -> V_7 != V_73 ) ;
V_127 = F_16 ( sizeof( * V_127 ) + V_98 + V_100 , V_125 ) ;
if ( ! V_127 )
return;
V_127 -> type = V_128 ;
if ( V_53 )
memcpy ( V_127 -> V_129 . V_53 , V_53 , V_71 ) ;
if ( V_98 ) {
V_127 -> V_129 . V_97 = ( ( T_1 * ) V_127 ) + sizeof( * V_127 ) ;
V_127 -> V_129 . V_98 = V_98 ;
memcpy ( ( void * ) V_127 -> V_129 . V_97 , V_97 , V_98 ) ;
}
if ( V_100 ) {
V_127 -> V_129 . V_99 = ( ( T_1 * ) V_127 ) + sizeof( * V_127 ) + V_98 ;
V_127 -> V_129 . V_100 = V_100 ;
memcpy ( ( void * ) V_127 -> V_129 . V_99 , V_99 , V_100 ) ;
}
V_127 -> V_129 . V_101 = V_101 ;
F_57 ( & V_4 -> V_130 , V_33 ) ;
F_58 ( & V_127 -> V_131 , & V_4 -> V_132 ) ;
F_59 ( & V_4 -> V_130 , V_33 ) ;
F_60 ( V_133 , & V_2 -> V_134 ) ;
}
void F_61 ( struct V_3 * V_4 ,
struct V_75 * V_76 ,
const T_1 * V_97 , T_3 V_98 ,
const T_1 * V_99 , T_3 V_100 )
{
#ifdef F_43
union V_104 V_105 ;
#endif
F_15 ( V_4 ) ;
if ( F_40 ( V_4 -> V_106 != V_107 &&
V_4 -> V_106 != V_108 ) )
goto V_135;
if ( V_4 -> V_7 != V_122 )
goto V_135;
if ( F_40 ( ! V_4 -> V_119 ) ) {
goto V_135;
}
F_46 ( V_4 -> V_119 ) ;
F_36 ( & V_4 -> V_119 -> V_120 ) ;
V_4 -> V_119 = NULL ;
F_47 ( F_48 ( V_76 ) ) ;
V_4 -> V_119 = F_48 ( V_76 ) ;
F_62 ( F_12 ( V_4 -> V_11 ) , V_4 -> V_44 , V_76 -> V_53 ,
V_97 , V_98 , V_99 , V_100 ,
V_27 ) ;
#ifdef F_43
if ( V_97 ) {
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . V_109 . V_110 = V_98 ;
F_45 ( V_4 -> V_44 , V_111 ,
& V_105 , V_97 ) ;
}
if ( V_99 ) {
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . V_109 . V_110 = V_100 ;
F_45 ( V_4 -> V_44 , V_112 ,
& V_105 , V_99 ) ;
}
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . V_113 . V_114 = V_115 ;
memcpy ( V_105 . V_113 . V_116 , V_76 -> V_53 , V_71 ) ;
memcpy ( V_4 -> V_117 . V_46 , V_76 -> V_53 , V_71 ) ;
V_4 -> V_117 . V_60 = true ;
F_45 ( V_4 -> V_44 , V_118 , & V_105 , NULL ) ;
#endif
return;
V_135:
F_36 ( V_76 ) ;
}
void F_63 ( struct V_81 * V_82 ,
struct V_32 * V_20 ,
const T_1 * V_53 ,
const T_1 * V_97 , T_3 V_98 ,
const T_1 * V_99 , T_3 V_100 , T_4 V_125 )
{
struct V_3 * V_4 = V_82 -> V_83 ;
struct V_75 * V_76 ;
F_56 ( V_4 -> V_7 != V_122 ) ;
V_76 = F_33 ( V_4 -> V_11 , V_20 , V_53 , V_4 -> V_38 ,
V_4 -> V_39 , V_78 ,
V_78 ) ;
if ( F_40 ( ! V_76 ) )
return;
F_64 ( V_82 , V_76 , V_97 , V_98 , V_99 ,
V_100 , V_125 ) ;
}
void F_64 ( struct V_81 * V_82 ,
struct V_75 * V_76 , const T_1 * V_97 ,
T_3 V_98 , const T_1 * V_99 ,
T_3 V_100 , T_4 V_125 )
{
struct V_3 * V_4 = V_82 -> V_83 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_126 * V_127 ;
unsigned long V_33 ;
F_56 ( V_4 -> V_7 != V_122 ) ;
if ( F_40 ( ! V_76 ) )
return;
V_127 = F_16 ( sizeof( * V_127 ) + V_98 + V_100 , V_125 ) ;
if ( ! V_127 ) {
F_36 ( V_76 ) ;
return;
}
V_127 -> type = V_136 ;
V_127 -> V_137 . V_97 = ( ( T_1 * ) V_127 ) + sizeof( * V_127 ) ;
V_127 -> V_137 . V_98 = V_98 ;
memcpy ( ( void * ) V_127 -> V_137 . V_97 , V_97 , V_98 ) ;
V_127 -> V_137 . V_99 = ( ( T_1 * ) V_127 ) + sizeof( * V_127 ) + V_98 ;
V_127 -> V_137 . V_100 = V_100 ;
memcpy ( ( void * ) V_127 -> V_137 . V_99 , V_99 , V_100 ) ;
V_127 -> V_137 . V_76 = V_76 ;
F_57 ( & V_4 -> V_130 , V_33 ) ;
F_58 ( & V_127 -> V_131 , & V_4 -> V_132 ) ;
F_59 ( & V_4 -> V_130 , V_33 ) ;
F_60 ( V_133 , & V_2 -> V_134 ) ;
}
void F_65 ( struct V_81 * V_82 , const T_1 * V_61 ,
T_3 V_62 , T_2 V_138 , bool V_139 )
{
struct V_3 * V_4 = V_82 -> V_83 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
int V_29 ;
#ifdef F_43
union V_104 V_105 ;
#endif
F_15 ( V_4 ) ;
if ( F_40 ( V_4 -> V_106 != V_107 &&
V_4 -> V_106 != V_108 ) )
return;
if ( V_4 -> V_7 != V_122 )
return;
if ( V_4 -> V_119 ) {
F_46 ( V_4 -> V_119 ) ;
F_36 ( & V_4 -> V_119 -> V_120 ) ;
}
V_4 -> V_119 = NULL ;
V_4 -> V_7 = V_8 ;
V_4 -> V_39 = 0 ;
if ( V_4 -> V_18 ) {
F_20 ( V_4 -> V_18 -> V_61 ) ;
V_4 -> V_18 -> V_61 = NULL ;
F_20 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
}
F_66 ( V_2 , V_82 , V_138 , V_61 , V_62 , V_139 ) ;
if ( V_2 -> V_49 -> V_140 )
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
F_67 ( V_2 , V_82 , V_29 , false , NULL ) ;
#ifdef F_43
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . V_113 . V_114 = V_115 ;
F_45 ( V_82 , V_118 , & V_105 , NULL ) ;
V_4 -> V_117 . V_141 . V_39 = 0 ;
#endif
F_34 ( & V_142 ) ;
}
void F_68 ( struct V_81 * V_82 , T_2 V_138 ,
T_1 * V_61 , T_3 V_62 , T_4 V_125 )
{
struct V_3 * V_4 = V_82 -> V_83 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_126 * V_127 ;
unsigned long V_33 ;
F_56 ( V_4 -> V_7 != V_122 ) ;
V_127 = F_16 ( sizeof( * V_127 ) + V_62 , V_125 ) ;
if ( ! V_127 )
return;
V_127 -> type = V_143 ;
V_127 -> V_144 . V_61 = ( ( T_1 * ) V_127 ) + sizeof( * V_127 ) ;
V_127 -> V_144 . V_62 = V_62 ;
memcpy ( ( void * ) V_127 -> V_144 . V_61 , V_61 , V_62 ) ;
V_127 -> V_144 . V_138 = V_138 ;
F_57 ( & V_4 -> V_130 , V_33 ) ;
F_58 ( & V_127 -> V_131 , & V_4 -> V_132 ) ;
F_59 ( & V_4 -> V_130 , V_33 ) ;
F_60 ( V_133 , & V_2 -> V_134 ) ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_81 * V_82 ,
struct V_45 * V_141 ,
struct V_145 * V_146 ,
const T_1 * V_46 )
{
struct V_3 * V_4 = V_82 -> V_83 ;
struct V_75 * V_76 = NULL ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_8 )
return - V_147 ;
if ( F_40 ( V_4 -> V_94 ) ) {
F_20 ( V_4 -> V_94 ) ;
V_4 -> V_94 = NULL ;
}
F_70 ( & V_141 -> V_65 ,
V_2 -> V_11 . V_148 ) ;
if ( V_146 && V_146 -> V_149 >= 0 ) {
int V_150 ;
T_5 V_151 ;
V_150 = V_146 -> V_149 ;
V_151 = V_146 -> V_19 [ V_150 ] . V_151 ;
if ( V_151 == V_152 ||
V_151 == V_153 ) {
V_141 -> V_56 = V_150 ;
V_141 -> V_54 = V_146 -> V_19 [ V_150 ] . V_54 ;
V_141 -> V_55 = V_146 -> V_19 [ V_150 ] . V_55 ;
if ( V_141 -> V_63 . V_154 == 0 )
V_141 -> V_63 . V_154 = V_151 ;
if ( V_141 -> V_63 . V_155 == 0 ) {
V_141 -> V_63 . V_155 = 1 ;
V_141 -> V_63 . V_156 [ 0 ] = V_151 ;
}
}
}
if ( ! V_2 -> V_49 -> V_141 ) {
if ( ! V_2 -> V_49 -> V_50 || ! V_2 -> V_49 -> V_58 )
return - V_157 ;
if ( F_40 ( V_4 -> V_18 ) )
return - V_158 ;
V_4 -> V_18 = F_16 ( sizeof( * V_4 -> V_18 ) , V_27 ) ;
if ( ! V_4 -> V_18 )
return - V_28 ;
memcpy ( & V_4 -> V_18 -> V_19 , V_141 , sizeof( * V_141 ) ) ;
if ( V_141 -> V_53 ) {
V_4 -> V_18 -> V_19 . V_53 = V_4 -> V_18 -> V_53 ;
memcpy ( V_4 -> V_18 -> V_53 , V_141 -> V_53 , V_71 ) ;
}
if ( V_141 -> V_61 ) {
V_4 -> V_18 -> V_61 = F_53 ( V_141 -> V_61 , V_141 -> V_62 ,
V_27 ) ;
V_4 -> V_18 -> V_19 . V_61 = V_4 -> V_18 -> V_61 ;
if ( ! V_4 -> V_18 -> V_61 ) {
F_20 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
return - V_28 ;
}
}
if ( V_141 -> V_52 == V_159 ) {
V_4 -> V_18 -> V_91 = true ;
V_4 -> V_18 -> V_19 . V_52 =
V_93 ;
} else {
V_4 -> V_18 -> V_91 = false ;
}
memcpy ( V_4 -> V_38 , V_141 -> V_38 , V_141 -> V_39 ) ;
V_4 -> V_39 = V_141 -> V_39 ;
V_4 -> V_18 -> V_19 . V_38 = V_4 -> V_38 ;
V_4 -> V_18 -> V_19 . V_39 = V_141 -> V_39 ;
V_76 = F_32 ( V_4 ) ;
V_4 -> V_7 = V_73 ;
V_4 -> V_94 = V_146 ;
if ( V_46 ) {
memcpy ( V_4 -> V_18 -> V_46 , V_46 , V_71 ) ;
V_4 -> V_18 -> V_60 = true ;
}
if ( V_76 ) {
V_4 -> V_18 -> V_42 = V_48 ;
V_15 = F_21 ( V_4 ) ;
F_36 ( V_76 ) ;
} else {
V_15 = F_11 ( V_4 ) ;
if ( V_15 == - V_17 ) {
V_15 = 0 ;
V_4 -> V_18 -> V_42 = V_47 ;
}
}
if ( V_15 ) {
F_20 ( V_4 -> V_18 -> V_61 ) ;
F_20 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
V_4 -> V_7 = V_8 ;
V_4 -> V_94 = NULL ;
V_4 -> V_39 = 0 ;
}
return V_15 ;
} else {
V_4 -> V_7 = V_73 ;
V_4 -> V_94 = V_146 ;
V_15 = F_71 ( V_2 , V_82 , V_141 ) ;
if ( V_15 ) {
V_4 -> V_94 = NULL ;
V_4 -> V_7 = V_8 ;
return V_15 ;
}
memcpy ( V_4 -> V_38 , V_141 -> V_38 , V_141 -> V_39 ) ;
V_4 -> V_39 = V_141 -> V_39 ;
return 0 ;
}
}
int F_72 ( struct V_1 * V_2 ,
struct V_81 * V_82 ,
struct V_45 * V_141 ,
struct V_145 * V_146 )
{
int V_15 ;
F_2 ( & V_2 -> V_72 ) ;
F_5 ( V_82 -> V_83 ) ;
V_15 = F_69 ( V_2 , V_82 , V_141 , V_146 , NULL ) ;
F_6 ( V_82 -> V_83 ) ;
F_8 ( & V_2 -> V_72 ) ;
return V_15 ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_81 * V_82 , T_2 V_138 , bool V_102 )
{
struct V_3 * V_4 = V_82 -> V_83 ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 == V_8 )
return - V_68 ;
F_20 ( V_4 -> V_94 ) ;
V_4 -> V_94 = NULL ;
if ( ! V_2 -> V_49 -> V_160 ) {
if ( ! V_2 -> V_49 -> V_161 )
return - V_157 ;
if ( ! V_4 -> V_18 ) {
F_74 ( V_2 , V_82 ) ;
return 0 ;
}
if ( V_4 -> V_7 == V_73 &&
( V_4 -> V_18 -> V_42 == V_43 ||
V_4 -> V_18 -> V_42 == V_47 ) ) {
V_4 -> V_7 = V_8 ;
F_20 ( V_4 -> V_18 -> V_61 ) ;
F_20 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
V_4 -> V_39 = 0 ;
return 0 ;
}
V_15 = F_25 ( V_2 , V_82 ,
V_4 -> V_18 -> V_19 . V_53 ,
NULL , 0 , V_138 , false ) ;
if ( V_15 )
return V_15 ;
} else {
V_15 = F_75 ( V_2 , V_82 , V_138 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_4 -> V_7 == V_122 )
F_65 ( V_82 , NULL , 0 , 0 , false ) ;
else if ( V_4 -> V_7 == V_73 )
F_30 ( V_82 , NULL , NULL , 0 , NULL , 0 ,
V_74 ,
V_102 , NULL ) ;
return 0 ;
}
int F_76 ( struct V_1 * V_2 ,
struct V_81 * V_82 ,
T_2 V_138 , bool V_102 )
{
int V_15 ;
F_5 ( V_82 -> V_83 ) ;
V_15 = F_73 ( V_2 , V_82 , V_138 , V_102 ) ;
F_6 ( V_82 -> V_83 ) ;
return V_15 ;
}
void F_77 ( struct V_81 * V_82 ,
struct V_162 * V_76 )
{
struct V_3 * V_4 = V_82 -> V_83 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
T_1 V_53 [ V_71 ] ;
F_15 ( V_4 ) ;
if ( ! V_4 -> V_18 )
return;
if ( V_4 -> V_18 -> V_42 == V_121 )
return;
memcpy ( V_53 , V_76 -> V_120 . V_53 , V_71 ) ;
F_25 ( V_2 , V_82 , V_53 , NULL , 0 ,
V_66 , false ) ;
}
