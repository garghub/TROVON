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
if ( V_6 -> V_12 || V_6 -> V_13 )
return - V_14 ;
if ( V_2 -> V_3 -> V_15 . V_16 )
V_10 = 1 ;
else
V_10 = F_8 ( V_2 -> V_7 ) ;
V_9 = F_9 ( sizeof( * V_9 ) + sizeof( V_9 -> V_17 [ 0 ] ) +
sizeof( V_9 -> V_18 [ 0 ] ) * V_10 ,
V_19 ) ;
if ( ! V_9 )
return - V_20 ;
if ( V_2 -> V_3 -> V_15 . V_16 )
V_9 -> V_18 [ 0 ] = V_2 -> V_3 -> V_15 . V_16 ;
else {
int V_21 = 0 , V_22 ;
enum V_23 V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_16 ;
for ( V_24 = 0 ; V_24 < V_28 ; V_24 ++ ) {
V_26 = V_2 -> V_7 -> V_26 [ V_24 ] ;
if ( ! V_26 )
continue;
for ( V_22 = 0 ; V_22 < V_26 -> V_10 ; V_22 ++ ) {
V_16 = & V_26 -> V_18 [ V_22 ] ;
if ( V_16 -> V_29 & V_30 )
continue;
V_9 -> V_18 [ V_21 ++ ] = V_16 ;
}
V_9 -> V_31 [ V_24 ] = ( 1 << V_26 -> V_32 ) - 1 ;
}
V_10 = V_21 ;
}
V_9 -> V_10 = V_10 ;
V_9 -> V_17 = ( void * ) & V_9 -> V_18 [ V_10 ] ;
V_9 -> V_33 = 1 ;
memcpy ( V_9 -> V_17 [ 0 ] . V_34 , V_2 -> V_3 -> V_15 . V_34 ,
V_2 -> V_3 -> V_15 . V_35 ) ;
V_9 -> V_17 [ 0 ] . V_35 = V_2 -> V_3 -> V_15 . V_35 ;
V_9 -> V_2 = V_2 ;
V_9 -> V_7 = & V_6 -> V_7 ;
V_9 -> V_36 = V_37 ;
V_6 -> V_12 = V_9 ;
V_11 = F_10 ( V_6 , V_9 ) ;
if ( ! V_11 ) {
V_2 -> V_3 -> V_38 = V_39 ;
F_11 ( V_6 , V_2 ) ;
F_12 ( V_2 -> V_40 ) ;
} else {
V_6 -> V_12 = NULL ;
F_2 ( V_9 ) ;
}
return V_11 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_41 * V_15 ;
struct V_42 V_43 = {} ;
int V_11 ;
F_7 ( V_2 ) ;
if ( ! V_2 -> V_3 )
return 0 ;
V_15 = & V_2 -> V_3 -> V_15 ;
switch ( V_2 -> V_3 -> V_38 ) {
case V_39 :
return - V_44 ;
case V_45 :
return F_3 ( V_2 ) ;
case V_46 :
F_14 ( ! V_6 -> V_47 -> V_48 ) ;
V_2 -> V_3 -> V_38 = V_49 ;
return F_15 ( V_6 , V_2 -> V_40 ,
V_15 -> V_16 , V_15 -> V_50 ,
V_15 -> V_51 ,
V_15 -> V_34 , V_15 -> V_35 ,
NULL , 0 ,
V_15 -> V_52 , V_15 -> V_53 ,
V_15 -> V_54 , NULL , 0 ) ;
case V_55 :
return - V_56 ;
case V_57 :
F_14 ( ! V_6 -> V_47 -> V_58 ) ;
V_2 -> V_3 -> V_38 = V_59 ;
if ( V_2 -> V_3 -> V_60 )
V_43 . V_61 = V_2 -> V_3 -> V_61 ;
V_43 . V_4 = V_15 -> V_4 ;
V_43 . V_62 = V_15 -> V_62 ;
V_43 . V_63 = V_15 -> V_64 != V_65 ;
V_43 . V_66 = V_15 -> V_66 ;
V_43 . V_29 = V_15 -> V_29 ;
V_43 . V_67 = V_15 -> V_67 ;
V_43 . V_68 = V_15 -> V_68 ;
V_43 . V_69 = V_15 -> V_69 ;
V_43 . V_70 = V_15 -> V_70 ;
V_11 = F_16 ( V_6 , V_2 -> V_40 , V_15 -> V_16 ,
V_15 -> V_51 , V_15 -> V_34 ,
V_15 -> V_35 , & V_43 ) ;
if ( V_11 )
F_17 ( V_6 , V_2 -> V_40 , V_15 -> V_51 ,
NULL , 0 ,
V_71 ,
false ) ;
return V_11 ;
case V_72 :
F_17 ( V_6 , V_2 -> V_40 , V_15 -> V_51 ,
NULL , 0 ,
V_71 , false ) ;
return - V_56 ;
case V_73 :
F_17 ( V_6 , V_2 -> V_40 , V_15 -> V_51 ,
NULL , 0 ,
V_71 , false ) ;
F_1 ( V_2 ) ;
return 0 ;
default:
return 0 ;
}
}
void F_18 ( struct V_74 * V_75 )
{
struct V_5 * V_6 =
F_19 ( V_75 , struct V_5 , V_76 ) ;
struct V_1 * V_2 ;
T_1 V_77 [ V_78 ] , * V_51 = NULL ;
F_20 () ;
F_21 (wdev, &rdev->wdev_list, list) {
if ( ! V_2 -> V_40 )
continue;
F_22 ( V_2 ) ;
if ( ! F_23 ( V_2 -> V_40 ) ) {
F_24 ( V_2 ) ;
continue;
}
if ( ! V_2 -> V_3 ||
V_2 -> V_3 -> V_38 == V_79 ) {
F_24 ( V_2 ) ;
continue;
}
if ( V_2 -> V_3 -> V_15 . V_51 ) {
memcpy ( V_77 , V_2 -> V_3 -> V_15 . V_51 , V_78 ) ;
V_51 = V_77 ;
}
if ( F_13 ( V_2 ) ) {
F_25 (
V_2 -> V_40 , V_51 ,
NULL , 0 , NULL , 0 ,
V_80 ,
false , NULL ) ;
F_1 ( V_2 ) ;
}
F_24 ( V_2 ) ;
}
F_26 () ;
}
static struct V_81 * F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_81 * V_82 ;
T_2 V_83 = V_84 ;
F_7 ( V_2 ) ;
if ( V_2 -> V_3 -> V_15 . V_85 )
V_83 |= V_86 ;
V_82 = F_28 ( V_2 -> V_7 , V_2 -> V_3 -> V_15 . V_16 ,
V_2 -> V_3 -> V_15 . V_51 ,
V_2 -> V_3 -> V_15 . V_34 ,
V_2 -> V_3 -> V_15 . V_35 ,
V_84 | V_86 ,
V_83 ) ;
if ( ! V_82 )
return NULL ;
memcpy ( V_2 -> V_3 -> V_51 , V_82 -> V_51 , V_78 ) ;
V_2 -> V_3 -> V_15 . V_51 = V_2 -> V_3 -> V_51 ;
V_2 -> V_3 -> V_15 . V_16 = V_82 -> V_16 ;
V_2 -> V_3 -> V_38 = V_46 ;
F_29 ( & V_6 -> V_76 ) ;
return V_82 ;
}
static void F_30 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_81 * V_82 ;
F_7 ( V_2 ) ;
if ( ! V_2 -> V_3 )
return;
if ( V_2 -> V_3 -> V_38 != V_39 &&
V_2 -> V_3 -> V_38 != V_45 )
return;
V_82 = F_27 ( V_2 ) ;
if ( V_82 )
F_31 ( & V_6 -> V_7 , V_82 ) ;
else
F_29 ( & V_6 -> V_76 ) ;
}
void F_32 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
F_22 ( V_2 ) ;
F_30 ( V_88 ) ;
F_24 ( V_2 ) ;
}
void F_33 ( struct V_1 * V_2 , const T_1 * V_90 , T_3 V_91 )
{
struct V_7 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_92 * V_93 = (struct V_92 * ) V_90 ;
T_2 V_94 = F_34 ( V_93 -> V_95 . V_48 . V_94 ) ;
F_7 ( V_2 ) ;
if ( ! V_2 -> V_3 || V_2 -> V_3 -> V_38 == V_79 )
return;
if ( V_94 == V_96 &&
V_2 -> V_3 -> V_97 &&
V_2 -> V_3 -> V_15 . V_50 != V_98 ) {
switch ( V_2 -> V_3 -> V_15 . V_50 ) {
case V_99 :
if ( V_2 -> V_100 )
V_2 -> V_3 -> V_15 . V_50 =
V_101 ;
else
V_2 -> V_3 -> V_15 . V_50 =
V_98 ;
break;
case V_101 :
V_2 -> V_3 -> V_15 . V_50 =
V_98 ;
break;
default:
V_2 -> V_3 -> V_15 . V_50 =
V_99 ;
break;
}
V_2 -> V_3 -> V_38 = V_46 ;
F_29 ( & V_6 -> V_76 ) ;
} else if ( V_94 != V_102 ) {
F_25 ( V_2 -> V_40 , V_93 -> V_51 ,
NULL , 0 , NULL , 0 ,
V_94 , false , NULL ) ;
} else if ( V_2 -> V_3 -> V_38 == V_49 ) {
V_2 -> V_3 -> V_38 = V_57 ;
F_29 ( & V_6 -> V_76 ) ;
}
}
bool F_35 ( struct V_1 * V_2 , T_2 V_103 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return false ;
if ( V_103 == V_102 ) {
V_2 -> V_3 -> V_38 = V_79 ;
return false ;
}
if ( V_2 -> V_3 -> V_60 ) {
V_2 -> V_3 -> V_60 = false ;
V_2 -> V_3 -> V_38 = V_57 ;
F_29 ( & V_6 -> V_76 ) ;
return true ;
}
V_2 -> V_3 -> V_38 = V_72 ;
F_29 ( & V_6 -> V_76 ) ;
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
V_2 -> V_3 -> V_38 = V_55 ;
F_29 ( & V_6 -> V_76 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_38 = V_73 ;
F_29 ( & V_6 -> V_76 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( ! V_2 -> V_3 )
return;
V_2 -> V_3 -> V_38 = V_72 ;
F_29 ( & V_6 -> V_76 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_41 * V_104 ,
const T_1 * V_61 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_81 * V_82 ;
int V_11 ;
if ( ! V_6 -> V_47 -> V_48 || ! V_6 -> V_47 -> V_58 )
return - V_105 ;
if ( V_2 -> V_106 )
return - V_107 ;
if ( F_41 ( V_2 -> V_3 ) )
return - V_108 ;
V_2 -> V_3 = F_9 ( sizeof( * V_2 -> V_3 ) , V_19 ) ;
if ( ! V_2 -> V_3 )
return - V_20 ;
memcpy ( & V_2 -> V_3 -> V_15 , V_104 , sizeof( * V_104 ) ) ;
if ( V_104 -> V_51 ) {
V_2 -> V_3 -> V_15 . V_51 = V_2 -> V_3 -> V_51 ;
memcpy ( V_2 -> V_3 -> V_51 , V_104 -> V_51 , V_78 ) ;
}
if ( V_104 -> V_4 ) {
V_2 -> V_3 -> V_4 = F_42 ( V_104 -> V_4 , V_104 -> V_62 ,
V_19 ) ;
V_2 -> V_3 -> V_15 . V_4 = V_2 -> V_3 -> V_4 ;
if ( ! V_2 -> V_3 -> V_4 ) {
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return - V_20 ;
}
}
if ( V_104 -> V_50 == V_109 ) {
V_2 -> V_3 -> V_97 = true ;
V_2 -> V_3 -> V_15 . V_50 =
V_99 ;
} else {
V_2 -> V_3 -> V_97 = false ;
}
V_2 -> V_3 -> V_15 . V_34 = V_2 -> V_34 ;
V_2 -> V_3 -> V_15 . V_35 = V_104 -> V_35 ;
V_82 = F_27 ( V_2 ) ;
if ( V_61 ) {
memcpy ( V_2 -> V_3 -> V_61 , V_61 , V_78 ) ;
V_2 -> V_3 -> V_60 = true ;
}
if ( V_82 ) {
V_2 -> V_3 -> V_38 = V_46 ;
V_11 = F_13 ( V_2 ) ;
F_31 ( V_2 -> V_7 , V_82 ) ;
} else {
V_11 = F_3 ( V_2 ) ;
if ( V_11 == - V_14 ) {
V_11 = 0 ;
V_2 -> V_3 -> V_38 = V_45 ;
}
}
if ( V_11 )
F_1 ( V_2 ) ;
return V_11 ;
}
static int F_43 ( struct V_1 * V_2 , T_2 V_110 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_11 ;
if ( ! V_2 -> V_3 )
return 0 ;
if ( ! V_6 -> V_47 -> V_111 )
return - V_105 ;
if ( V_2 -> V_3 -> V_38 == V_39 ||
V_2 -> V_3 -> V_38 == V_45 ) {
V_11 = 0 ;
goto V_112;
}
V_11 = F_17 ( V_6 , V_2 -> V_40 ,
V_2 -> V_3 -> V_15 . V_51 ,
NULL , 0 , V_110 , false ) ;
V_112:
F_1 ( V_2 ) ;
return V_11 ;
}
static bool F_44 ( void )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
bool V_113 = true ;
F_21 (rdev, &cfg80211_rdev_list, list) {
F_21 (wdev, &rdev->wdev_list, list) {
F_22 ( V_2 ) ;
if ( V_2 -> V_3 || V_2 -> V_106 )
V_113 = false ;
F_24 ( V_2 ) ;
}
}
return V_113 ;
}
static void F_45 ( struct V_74 * V_75 )
{
F_20 () ;
if ( F_44 () )
F_46 () ;
F_26 () ;
}
void F_25 ( struct V_87 * V_88 , const T_1 * V_51 ,
const T_1 * V_114 , T_3 V_115 ,
const T_1 * V_116 , T_3 V_117 ,
T_2 V_103 , bool V_118 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
const T_1 * V_119 ;
#ifdef F_47
union V_120 V_121 ;
#endif
F_7 ( V_2 ) ;
if ( F_41 ( V_2 -> V_122 != V_123 &&
V_2 -> V_122 != V_124 ) ) {
F_31 ( V_2 -> V_7 , V_82 ) ;
return;
}
F_48 ( F_4 ( V_2 -> V_7 ) , V_88 ,
V_51 , V_114 , V_115 ,
V_116 , V_117 ,
V_103 , V_19 ) ;
#ifdef F_47
if ( V_118 ) {
if ( V_114 && V_103 == V_102 ) {
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_125 . V_126 = V_115 ;
F_49 ( V_88 , V_127 , & V_121 , V_114 ) ;
}
if ( V_116 && V_103 == V_102 ) {
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_125 . V_126 = V_117 ;
F_49 ( V_88 , V_128 , & V_121 , V_116 ) ;
}
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_129 . V_130 = V_131 ;
if ( V_51 && V_103 == V_102 ) {
memcpy ( V_121 . V_129 . V_132 , V_51 , V_78 ) ;
memcpy ( V_2 -> V_133 . V_61 , V_51 , V_78 ) ;
V_2 -> V_133 . V_60 = true ;
}
F_49 ( V_88 , V_134 , & V_121 , NULL ) ;
}
#endif
if ( ! V_82 && ( V_103 == V_102 ) ) {
F_50 ( ! F_4 ( V_2 -> V_7 ) -> V_47 -> V_104 ) ;
V_82 = F_28 ( V_2 -> V_7 , NULL , V_51 ,
V_2 -> V_34 , V_2 -> V_35 ,
V_84 ,
V_84 ) ;
if ( V_82 )
F_51 ( F_52 ( V_82 ) ) ;
}
if ( V_2 -> V_106 ) {
F_53 ( V_2 -> V_106 ) ;
F_31 ( V_2 -> V_7 , & V_2 -> V_106 -> V_135 ) ;
V_2 -> V_106 = NULL ;
}
if ( V_103 != V_102 ) {
F_2 ( V_2 -> V_100 ) ;
V_2 -> V_100 = NULL ;
V_2 -> V_35 = 0 ;
if ( V_82 ) {
F_53 ( F_52 ( V_82 ) ) ;
F_31 ( V_2 -> V_7 , V_82 ) ;
}
return;
}
if ( F_41 ( ! V_82 ) )
return;
V_2 -> V_106 = F_52 ( V_82 ) ;
F_54 ( V_2 ) ;
F_55 () ;
V_119 = F_56 ( V_82 , V_136 ) ;
if ( ! V_119 ) {
F_57 () ;
return;
}
V_119 = F_42 ( V_119 , 2 + V_119 [ 1 ] , V_137 ) ;
F_57 () ;
if ( ! V_119 )
return;
F_58 ( V_2 -> V_7 , V_82 -> V_16 -> V_24 ,
V_119 + 2 , V_119 [ 1 ] ) ;
F_2 ( V_119 ) ;
}
void F_59 ( struct V_87 * V_88 , const T_1 * V_51 ,
const T_1 * V_114 , T_3 V_115 ,
const T_1 * V_116 , T_3 V_117 ,
T_2 V_103 , T_4 V_138 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_139 * V_140 ;
unsigned long V_29 ;
V_140 = F_9 ( sizeof( * V_140 ) + V_115 + V_117 , V_138 ) ;
if ( ! V_140 )
return;
V_140 -> type = V_141 ;
if ( V_51 )
memcpy ( V_140 -> V_142 . V_51 , V_51 , V_78 ) ;
if ( V_115 ) {
V_140 -> V_142 . V_114 = ( ( T_1 * ) V_140 ) + sizeof( * V_140 ) ;
V_140 -> V_142 . V_115 = V_115 ;
memcpy ( ( void * ) V_140 -> V_142 . V_114 , V_114 , V_115 ) ;
}
if ( V_117 ) {
V_140 -> V_142 . V_116 = ( ( T_1 * ) V_140 ) + sizeof( * V_140 ) + V_115 ;
V_140 -> V_142 . V_117 = V_117 ;
memcpy ( ( void * ) V_140 -> V_142 . V_116 , V_116 , V_117 ) ;
}
V_140 -> V_142 . V_103 = V_103 ;
F_60 ( & V_2 -> V_143 , V_29 ) ;
F_61 ( & V_140 -> V_144 , & V_2 -> V_145 ) ;
F_62 ( & V_2 -> V_143 , V_29 ) ;
F_63 ( V_146 , & V_6 -> V_147 ) ;
}
void F_64 ( struct V_1 * V_2 ,
struct V_81 * V_82 ,
const T_1 * V_114 , T_3 V_115 ,
const T_1 * V_116 , T_3 V_117 )
{
#ifdef F_47
union V_120 V_121 ;
#endif
F_7 ( V_2 ) ;
if ( F_41 ( V_2 -> V_122 != V_123 &&
V_2 -> V_122 != V_124 ) )
goto V_112;
if ( F_41 ( ! V_2 -> V_106 ) )
goto V_112;
F_53 ( V_2 -> V_106 ) ;
F_31 ( V_2 -> V_7 , & V_2 -> V_106 -> V_135 ) ;
V_2 -> V_106 = NULL ;
F_51 ( F_52 ( V_82 ) ) ;
V_2 -> V_106 = F_52 ( V_82 ) ;
F_65 ( F_4 ( V_2 -> V_7 ) , V_2 -> V_40 , V_82 -> V_51 ,
V_114 , V_115 , V_116 , V_117 ,
V_19 ) ;
#ifdef F_47
if ( V_114 ) {
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_125 . V_126 = V_115 ;
F_49 ( V_2 -> V_40 , V_127 ,
& V_121 , V_114 ) ;
}
if ( V_116 ) {
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_125 . V_126 = V_117 ;
F_49 ( V_2 -> V_40 , V_128 ,
& V_121 , V_116 ) ;
}
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_129 . V_130 = V_131 ;
memcpy ( V_121 . V_129 . V_132 , V_82 -> V_51 , V_78 ) ;
memcpy ( V_2 -> V_133 . V_61 , V_82 -> V_51 , V_78 ) ;
V_2 -> V_133 . V_60 = true ;
F_49 ( V_2 -> V_40 , V_134 , & V_121 , NULL ) ;
#endif
return;
V_112:
F_31 ( V_2 -> V_7 , V_82 ) ;
}
void F_66 ( struct V_87 * V_88 ,
struct V_27 * V_16 ,
const T_1 * V_51 ,
const T_1 * V_114 , T_3 V_115 ,
const T_1 * V_116 , T_3 V_117 , T_4 V_138 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
struct V_81 * V_82 ;
V_82 = F_28 ( V_2 -> V_7 , V_16 , V_51 , V_2 -> V_34 ,
V_2 -> V_35 , V_84 ,
V_84 ) ;
if ( F_41 ( ! V_82 ) )
return;
F_67 ( V_88 , V_82 , V_114 , V_115 , V_116 ,
V_117 , V_138 ) ;
}
void F_67 ( struct V_87 * V_88 ,
struct V_81 * V_82 , const T_1 * V_114 ,
T_3 V_115 , const T_1 * V_116 ,
T_3 V_117 , T_4 V_138 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_139 * V_140 ;
unsigned long V_29 ;
if ( F_41 ( ! V_82 ) )
return;
V_140 = F_9 ( sizeof( * V_140 ) + V_115 + V_117 , V_138 ) ;
if ( ! V_140 ) {
F_31 ( V_2 -> V_7 , V_82 ) ;
return;
}
V_140 -> type = V_148 ;
V_140 -> V_149 . V_114 = ( ( T_1 * ) V_140 ) + sizeof( * V_140 ) ;
V_140 -> V_149 . V_115 = V_115 ;
memcpy ( ( void * ) V_140 -> V_149 . V_114 , V_114 , V_115 ) ;
V_140 -> V_149 . V_116 = ( ( T_1 * ) V_140 ) + sizeof( * V_140 ) + V_115 ;
V_140 -> V_149 . V_117 = V_117 ;
memcpy ( ( void * ) V_140 -> V_149 . V_116 , V_116 , V_117 ) ;
V_140 -> V_149 . V_82 = V_82 ;
F_60 ( & V_2 -> V_143 , V_29 ) ;
F_61 ( & V_140 -> V_144 , & V_2 -> V_145 ) ;
F_62 ( & V_2 -> V_143 , V_29 ) ;
F_63 ( V_146 , & V_6 -> V_147 ) ;
}
void F_68 ( struct V_87 * V_88 , const T_1 * V_4 ,
T_3 V_62 , T_2 V_110 , bool V_150 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
int V_21 ;
#ifdef F_47
union V_120 V_121 ;
#endif
F_7 ( V_2 ) ;
if ( F_41 ( V_2 -> V_122 != V_123 &&
V_2 -> V_122 != V_124 ) )
return;
if ( V_2 -> V_106 ) {
F_53 ( V_2 -> V_106 ) ;
F_31 ( V_2 -> V_7 , & V_2 -> V_106 -> V_135 ) ;
}
V_2 -> V_106 = NULL ;
V_2 -> V_35 = 0 ;
F_69 ( V_6 , V_88 , V_110 , V_4 , V_62 , V_150 ) ;
if ( V_6 -> V_47 -> V_151 )
for ( V_21 = 0 ; V_21 < 6 ; V_21 ++ )
F_70 ( V_6 , V_88 , V_21 , false , NULL ) ;
F_71 ( V_6 , V_88 , NULL ) ;
#ifdef F_47
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_129 . V_130 = V_131 ;
F_49 ( V_88 , V_134 , & V_121 , NULL ) ;
V_2 -> V_133 . V_104 . V_35 = 0 ;
#endif
F_29 ( & V_152 ) ;
}
void F_72 ( struct V_87 * V_88 , T_2 V_110 ,
T_1 * V_4 , T_3 V_62 , T_4 V_138 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_139 * V_140 ;
unsigned long V_29 ;
V_140 = F_9 ( sizeof( * V_140 ) + V_62 , V_138 ) ;
if ( ! V_140 )
return;
V_140 -> type = V_153 ;
V_140 -> V_154 . V_4 = ( ( T_1 * ) V_140 ) + sizeof( * V_140 ) ;
V_140 -> V_154 . V_62 = V_62 ;
memcpy ( ( void * ) V_140 -> V_154 . V_4 , V_4 , V_62 ) ;
V_140 -> V_154 . V_110 = V_110 ;
F_60 ( & V_2 -> V_143 , V_29 ) ;
F_61 ( & V_140 -> V_144 , & V_2 -> V_145 ) ;
F_62 ( & V_2 -> V_143 , V_29 ) ;
F_63 ( V_146 , & V_6 -> V_147 ) ;
}
int F_73 ( struct V_5 * V_6 ,
struct V_87 * V_88 ,
struct V_41 * V_104 ,
struct V_155 * V_156 ,
const T_1 * V_61 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
int V_11 ;
F_7 ( V_2 ) ;
if ( F_41 ( V_2 -> V_100 ) ) {
F_2 ( V_2 -> V_100 ) ;
V_2 -> V_100 = NULL ;
}
F_74 ( & V_104 -> V_68 ,
V_6 -> V_7 . V_157 ) ;
if ( V_156 && V_156 -> V_158 >= 0 ) {
int V_159 ;
T_5 V_160 ;
V_159 = V_156 -> V_158 ;
V_160 = V_156 -> V_15 [ V_159 ] . V_160 ;
if ( V_160 == V_161 ||
V_160 == V_162 ) {
V_104 -> V_54 = V_159 ;
V_104 -> V_52 = V_156 -> V_15 [ V_159 ] . V_52 ;
V_104 -> V_53 = V_156 -> V_15 [ V_159 ] . V_53 ;
if ( V_104 -> V_66 . V_163 == 0 )
V_104 -> V_66 . V_163 = V_160 ;
if ( V_104 -> V_66 . V_164 == 0 ) {
V_104 -> V_66 . V_164 = 1 ;
V_104 -> V_66 . V_165 [ 0 ] = V_160 ;
}
}
}
V_2 -> V_100 = V_156 ;
memcpy ( V_2 -> V_34 , V_104 -> V_34 , V_104 -> V_35 ) ;
V_2 -> V_35 = V_104 -> V_35 ;
if ( ! V_6 -> V_47 -> V_104 )
V_11 = F_40 ( V_2 , V_104 , V_61 ) ;
else
V_11 = F_75 ( V_6 , V_88 , V_104 ) ;
if ( V_11 ) {
V_2 -> V_100 = NULL ;
V_2 -> V_35 = 0 ;
return V_11 ;
}
return 0 ;
}
int F_76 ( struct V_5 * V_6 ,
struct V_87 * V_88 , T_2 V_110 , bool V_118 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
int V_11 = 0 ;
F_7 ( V_2 ) ;
F_2 ( V_2 -> V_100 ) ;
V_2 -> V_100 = NULL ;
if ( V_2 -> V_3 )
V_11 = F_43 ( V_2 , V_110 ) ;
else if ( ! V_6 -> V_47 -> V_166 )
F_77 ( V_6 , V_88 ) ;
else if ( V_2 -> V_106 )
V_11 = F_78 ( V_6 , V_88 , V_110 ) ;
return V_11 ;
}
