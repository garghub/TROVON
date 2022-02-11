static bool F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
bool V_5 = true ;
F_2 ( & V_6 ) ;
F_3 (rdev, &cfg80211_rdev_list, list) {
F_4 ( V_2 ) ;
F_3 (wdev, &rdev->netdev_list, list) {
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
V_13 -> V_40 = V_4 -> V_41 ;
V_13 -> V_11 = & V_2 -> V_11 ;
V_2 -> V_16 = V_13 ;
V_15 = V_2 -> V_42 -> V_43 ( V_4 -> V_11 , V_4 -> V_41 , V_13 ) ;
if ( ! V_15 ) {
V_4 -> V_18 -> V_44 = V_45 ;
F_17 ( V_2 , V_4 -> V_41 ) ;
F_18 ( V_4 -> V_41 ) ;
} else {
V_2 -> V_16 = NULL ;
F_19 ( V_13 ) ;
}
return V_15 ;
}
static int F_20 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_46 * V_19 ;
const T_1 * V_47 = NULL ;
int V_15 ;
F_15 ( V_4 ) ;
if ( ! V_4 -> V_18 )
return 0 ;
V_19 = & V_4 -> V_18 -> V_19 ;
switch ( V_4 -> V_18 -> V_44 ) {
case V_48 :
return F_11 ( V_4 ) ;
case V_49 :
F_21 ( ! V_2 -> V_42 -> V_50 ) ;
V_4 -> V_18 -> V_44 = V_51 ;
return F_22 ( V_2 , V_4 -> V_41 ,
V_19 -> V_20 , V_19 -> V_52 ,
V_19 -> V_53 ,
V_19 -> V_38 , V_19 -> V_39 ,
NULL , 0 ,
V_19 -> V_54 , V_19 -> V_55 ,
V_19 -> V_56 , false ) ;
case V_57 :
F_21 ( ! V_2 -> V_42 -> V_58 ) ;
V_4 -> V_18 -> V_44 = V_59 ;
if ( V_4 -> V_18 -> V_60 )
V_47 = V_4 -> V_18 -> V_47 ;
V_15 = F_23 ( V_2 , V_4 -> V_41 ,
V_19 -> V_20 , V_19 -> V_53 ,
V_47 ,
V_19 -> V_38 , V_19 -> V_39 ,
V_19 -> V_61 , V_19 -> V_62 ,
false , & V_19 -> V_63 ,
V_19 -> V_33 , & V_19 -> V_64 ,
& V_19 -> V_65 ) ;
if ( V_15 )
F_24 ( V_2 , V_4 -> V_41 , V_19 -> V_53 ,
NULL , 0 ,
V_66 ,
false ) ;
return V_15 ;
case V_67 :
F_24 ( V_2 , V_4 -> V_41 , V_19 -> V_53 ,
NULL , 0 ,
V_66 , false ) ;
return - V_68 ;
default:
return 0 ;
}
}
void F_25 ( struct V_9 * V_10 )
{
struct V_1 * V_2 =
F_26 ( V_10 , struct V_1 , V_69 ) ;
struct V_3 * V_4 ;
T_1 V_70 [ V_71 ] , * V_53 = NULL ;
F_27 () ;
F_4 ( V_2 ) ;
F_2 ( & V_2 -> V_72 ) ;
F_3 (wdev, &rdev->netdev_list, list) {
F_5 ( V_4 ) ;
if ( ! F_28 ( V_4 -> V_41 ) ) {
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
if ( F_20 ( V_4 ) )
F_29 (
V_4 -> V_41 , V_53 ,
NULL , 0 , NULL , 0 ,
V_74 ,
false , NULL ) ;
F_6 ( V_4 ) ;
}
F_8 ( & V_2 -> V_72 ) ;
F_7 ( V_2 ) ;
F_30 () ;
}
static struct V_75 * F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_75 * V_76 ;
T_2 V_77 = V_78 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_18 -> V_19 . V_79 )
V_77 |= V_80 ;
V_76 = F_32 ( V_4 -> V_11 , V_4 -> V_18 -> V_19 . V_20 ,
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
V_4 -> V_18 -> V_44 = V_49 ;
F_33 ( & V_2 -> V_69 ) ;
return V_76 ;
}
static void F_34 ( struct V_81 * V_40 )
{
struct V_3 * V_4 = V_40 -> V_82 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_75 * V_76 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_73 )
return;
if ( ! V_4 -> V_18 )
return;
if ( V_4 -> V_18 -> V_44 != V_45 &&
V_4 -> V_18 -> V_44 != V_48 )
return;
V_76 = F_31 ( V_4 ) ;
if ( V_76 ) {
F_35 ( V_76 ) ;
} else {
if ( V_4 -> V_18 -> V_44 == V_48 )
F_33 ( & V_2 -> V_69 ) ;
else
F_29 (
V_4 -> V_41 ,
V_4 -> V_18 -> V_19 . V_53 ,
NULL , 0 , NULL , 0 ,
V_74 ,
false , NULL ) ;
}
}
void F_36 ( struct V_81 * V_40 )
{
struct V_3 * V_4 = V_40 -> V_82 ;
F_2 ( & F_12 ( V_4 -> V_11 ) -> V_72 ) ;
F_5 ( V_4 ) ;
F_34 ( V_40 ) ;
F_6 ( V_4 ) ;
F_8 ( & F_12 ( V_4 -> V_11 ) -> V_72 ) ;
}
void F_37 ( struct V_81 * V_40 ,
const T_1 * V_83 , T_3 V_84 )
{
struct V_3 * V_4 = V_40 -> V_82 ;
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
struct V_85 * V_86 = (struct V_85 * ) V_83 ;
T_2 V_87 = F_38 ( V_86 -> V_88 . V_50 . V_87 ) ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_73 )
return;
if ( F_39 ( ! V_4 -> V_18 ) )
return;
if ( V_87 == V_89 &&
V_4 -> V_18 -> V_90 &&
V_4 -> V_18 -> V_19 . V_52 != V_91 ) {
switch ( V_4 -> V_18 -> V_19 . V_52 ) {
case V_92 :
if ( V_4 -> V_93 )
V_4 -> V_18 -> V_19 . V_52 =
V_94 ;
else
V_4 -> V_18 -> V_19 . V_52 =
V_91 ;
break;
case V_94 :
V_4 -> V_18 -> V_19 . V_52 =
V_91 ;
break;
default:
V_4 -> V_18 -> V_19 . V_52 =
V_92 ;
break;
}
V_4 -> V_18 -> V_44 = V_49 ;
F_33 ( & V_2 -> V_69 ) ;
} else if ( V_87 != V_95 ) {
F_29 ( V_40 , V_86 -> V_53 , NULL , 0 , NULL , 0 ,
V_87 , false , NULL ) ;
} else if ( V_4 -> V_7 == V_73 &&
V_4 -> V_18 -> V_44 == V_51 ) {
V_4 -> V_18 -> V_44 = V_57 ;
F_33 ( & V_2 -> V_69 ) ;
}
}
bool F_40 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
if ( F_39 ( ! V_4 -> V_18 ) )
return false ;
if ( ! V_4 -> V_18 -> V_60 )
return false ;
V_4 -> V_18 -> V_60 = false ;
V_4 -> V_18 -> V_44 = V_57 ;
F_33 ( & V_2 -> V_69 ) ;
return true ;
}
void F_41 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
V_4 -> V_18 -> V_44 = V_67 ;
F_33 ( & V_2 -> V_69 ) ;
}
void F_29 ( struct V_81 * V_40 , const T_1 * V_53 ,
const T_1 * V_96 , T_3 V_97 ,
const T_1 * V_98 , T_3 V_99 ,
T_2 V_100 , bool V_101 ,
struct V_75 * V_76 )
{
struct V_3 * V_4 = V_40 -> V_82 ;
T_1 * V_102 ;
#ifdef F_42
union V_103 V_104 ;
#endif
F_15 ( V_4 ) ;
if ( F_39 ( V_4 -> V_105 != V_106 &&
V_4 -> V_105 != V_107 ) )
return;
if ( V_4 -> V_7 != V_73 )
return;
F_43 ( F_12 ( V_4 -> V_11 ) , V_40 ,
V_53 , V_96 , V_97 ,
V_98 , V_99 ,
V_100 , V_27 ) ;
#ifdef F_42
if ( V_101 ) {
if ( V_96 && V_100 == V_95 ) {
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_108 . V_109 = V_97 ;
F_44 ( V_40 , V_110 , & V_104 , V_96 ) ;
}
if ( V_98 && V_100 == V_95 ) {
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_108 . V_109 = V_99 ;
F_44 ( V_40 , V_111 , & V_104 , V_98 ) ;
}
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_112 . V_113 = V_114 ;
if ( V_53 && V_100 == V_95 ) {
memcpy ( V_104 . V_112 . V_115 , V_53 , V_71 ) ;
memcpy ( V_4 -> V_116 . V_47 , V_53 , V_71 ) ;
V_4 -> V_116 . V_60 = true ;
}
F_44 ( V_40 , V_117 , & V_104 , NULL ) ;
}
#endif
if ( V_4 -> V_118 ) {
F_45 ( V_4 -> V_118 ) ;
F_35 ( & V_4 -> V_118 -> V_119 ) ;
V_4 -> V_118 = NULL ;
}
if ( V_4 -> V_18 )
V_4 -> V_18 -> V_44 = V_120 ;
if ( V_100 != V_95 ) {
V_4 -> V_7 = V_8 ;
if ( V_4 -> V_18 )
F_19 ( V_4 -> V_18 -> V_61 ) ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
F_19 ( V_4 -> V_93 ) ;
V_4 -> V_93 = NULL ;
V_4 -> V_39 = 0 ;
return;
}
if ( ! V_76 )
V_76 = F_32 ( V_4 -> V_11 ,
V_4 -> V_18 ? V_4 -> V_18 -> V_19 . V_20 :
NULL ,
V_53 ,
V_4 -> V_38 , V_4 -> V_39 ,
V_78 ,
V_78 ) ;
if ( F_39 ( ! V_76 ) )
return;
F_46 ( F_47 ( V_76 ) ) ;
V_4 -> V_118 = F_47 ( V_76 ) ;
V_4 -> V_7 = V_121 ;
F_48 ( V_4 ) ;
V_102 = ( T_1 * ) F_49 ( V_76 , V_122 ) ;
if ( ! V_102 )
return;
F_50 ( V_4 -> V_11 ,
V_76 -> V_20 -> V_22 ,
V_102 + 2 ,
V_102 [ 1 ] ) ;
}
void F_51 ( struct V_81 * V_40 , const T_1 * V_53 ,
const T_1 * V_96 , T_3 V_97 ,
const T_1 * V_98 , T_3 V_99 ,
T_2 V_100 , T_4 V_123 )
{
struct V_3 * V_4 = V_40 -> V_82 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_124 * V_125 ;
unsigned long V_33 ;
F_52 ( V_4 -> V_7 != V_73 ) ;
V_125 = F_16 ( sizeof( * V_125 ) + V_97 + V_99 , V_123 ) ;
if ( ! V_125 )
return;
V_125 -> type = V_126 ;
if ( V_53 )
memcpy ( V_125 -> V_127 . V_53 , V_53 , V_71 ) ;
if ( V_97 ) {
V_125 -> V_127 . V_96 = ( ( T_1 * ) V_125 ) + sizeof( * V_125 ) ;
V_125 -> V_127 . V_97 = V_97 ;
memcpy ( ( void * ) V_125 -> V_127 . V_96 , V_96 , V_97 ) ;
}
if ( V_99 ) {
V_125 -> V_127 . V_98 = ( ( T_1 * ) V_125 ) + sizeof( * V_125 ) + V_97 ;
V_125 -> V_127 . V_99 = V_99 ;
memcpy ( ( void * ) V_125 -> V_127 . V_98 , V_98 , V_99 ) ;
}
V_125 -> V_127 . V_100 = V_100 ;
F_53 ( & V_4 -> V_128 , V_33 ) ;
F_54 ( & V_125 -> V_129 , & V_4 -> V_130 ) ;
F_55 ( & V_4 -> V_128 , V_33 ) ;
F_56 ( V_131 , & V_2 -> V_132 ) ;
}
void F_57 ( struct V_3 * V_4 ,
struct V_75 * V_76 ,
const T_1 * V_96 , T_3 V_97 ,
const T_1 * V_98 , T_3 V_99 )
{
#ifdef F_42
union V_103 V_104 ;
#endif
F_15 ( V_4 ) ;
if ( F_39 ( V_4 -> V_105 != V_106 &&
V_4 -> V_105 != V_107 ) )
goto V_133;
if ( V_4 -> V_7 != V_121 )
goto V_133;
if ( F_39 ( ! V_4 -> V_118 ) ) {
goto V_133;
}
F_45 ( V_4 -> V_118 ) ;
F_35 ( & V_4 -> V_118 -> V_119 ) ;
V_4 -> V_118 = NULL ;
F_46 ( F_47 ( V_76 ) ) ;
V_4 -> V_118 = F_47 ( V_76 ) ;
F_58 ( F_12 ( V_4 -> V_11 ) , V_4 -> V_41 , V_76 -> V_53 ,
V_96 , V_97 , V_98 , V_99 ,
V_27 ) ;
#ifdef F_42
if ( V_96 ) {
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_108 . V_109 = V_97 ;
F_44 ( V_4 -> V_41 , V_110 ,
& V_104 , V_96 ) ;
}
if ( V_98 ) {
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_108 . V_109 = V_99 ;
F_44 ( V_4 -> V_41 , V_111 ,
& V_104 , V_98 ) ;
}
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_112 . V_113 = V_114 ;
memcpy ( V_104 . V_112 . V_115 , V_76 -> V_53 , V_71 ) ;
memcpy ( V_4 -> V_116 . V_47 , V_76 -> V_53 , V_71 ) ;
V_4 -> V_116 . V_60 = true ;
F_44 ( V_4 -> V_41 , V_117 , & V_104 , NULL ) ;
#endif
return;
V_133:
F_35 ( V_76 ) ;
}
void F_59 ( struct V_81 * V_40 ,
struct V_32 * V_20 ,
const T_1 * V_53 ,
const T_1 * V_96 , T_3 V_97 ,
const T_1 * V_98 , T_3 V_99 , T_4 V_123 )
{
struct V_3 * V_4 = V_40 -> V_82 ;
struct V_75 * V_76 ;
F_52 ( V_4 -> V_7 != V_121 ) ;
V_76 = F_32 ( V_4 -> V_11 , V_20 , V_53 , V_4 -> V_38 ,
V_4 -> V_39 , V_78 ,
V_78 ) ;
if ( F_39 ( ! V_76 ) )
return;
F_60 ( V_40 , V_76 , V_96 , V_97 , V_98 ,
V_99 , V_123 ) ;
}
void F_60 ( struct V_81 * V_40 ,
struct V_75 * V_76 , const T_1 * V_96 ,
T_3 V_97 , const T_1 * V_98 ,
T_3 V_99 , T_4 V_123 )
{
struct V_3 * V_4 = V_40 -> V_82 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_124 * V_125 ;
unsigned long V_33 ;
F_52 ( V_4 -> V_7 != V_121 ) ;
if ( F_39 ( ! V_76 ) )
return;
V_125 = F_16 ( sizeof( * V_125 ) + V_97 + V_99 , V_123 ) ;
if ( ! V_125 ) {
F_35 ( V_76 ) ;
return;
}
V_125 -> type = V_134 ;
V_125 -> V_135 . V_96 = ( ( T_1 * ) V_125 ) + sizeof( * V_125 ) ;
V_125 -> V_135 . V_97 = V_97 ;
memcpy ( ( void * ) V_125 -> V_135 . V_96 , V_96 , V_97 ) ;
V_125 -> V_135 . V_98 = ( ( T_1 * ) V_125 ) + sizeof( * V_125 ) + V_97 ;
V_125 -> V_135 . V_99 = V_99 ;
memcpy ( ( void * ) V_125 -> V_135 . V_98 , V_98 , V_99 ) ;
V_125 -> V_135 . V_76 = V_76 ;
F_53 ( & V_4 -> V_128 , V_33 ) ;
F_54 ( & V_125 -> V_129 , & V_4 -> V_130 ) ;
F_55 ( & V_4 -> V_128 , V_33 ) ;
F_56 ( V_131 , & V_2 -> V_132 ) ;
}
void F_61 ( struct V_81 * V_40 , const T_1 * V_61 ,
T_3 V_62 , T_2 V_136 , bool V_137 )
{
struct V_3 * V_4 = V_40 -> V_82 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
int V_29 ;
#ifdef F_42
union V_103 V_104 ;
#endif
F_15 ( V_4 ) ;
if ( F_39 ( V_4 -> V_105 != V_106 &&
V_4 -> V_105 != V_107 ) )
return;
if ( V_4 -> V_7 != V_121 )
return;
if ( V_4 -> V_118 ) {
F_45 ( V_4 -> V_118 ) ;
F_35 ( & V_4 -> V_118 -> V_119 ) ;
}
V_4 -> V_118 = NULL ;
V_4 -> V_7 = V_8 ;
V_4 -> V_39 = 0 ;
if ( V_4 -> V_18 ) {
const T_1 * V_53 ;
int V_138 ;
F_19 ( V_4 -> V_18 -> V_61 ) ;
V_4 -> V_18 -> V_61 = NULL ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
for ( V_29 = 0 ; V_29 < V_139 ; V_29 ++ ) {
if ( ! V_4 -> V_140 [ V_29 ] )
continue;
V_53 = V_4 -> V_140 [ V_29 ] -> V_119 . V_53 ;
V_138 = F_24 ( V_2 , V_40 , V_53 , NULL , 0 ,
V_66 ,
false ) ;
F_62 ( V_138 , L_1 , V_138 ) ;
}
}
F_63 ( V_2 , V_40 , V_136 , V_61 , V_62 , V_137 ) ;
if ( V_2 -> V_42 -> V_141 )
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
V_2 -> V_42 -> V_141 ( V_4 -> V_11 , V_40 , V_29 , false , NULL ) ;
#ifdef F_42
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_112 . V_113 = V_114 ;
F_44 ( V_40 , V_117 , & V_104 , NULL ) ;
V_4 -> V_116 . V_142 . V_39 = 0 ;
#endif
F_33 ( & V_143 ) ;
}
void F_64 ( struct V_81 * V_40 , T_2 V_136 ,
T_1 * V_61 , T_3 V_62 , T_4 V_123 )
{
struct V_3 * V_4 = V_40 -> V_82 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_124 * V_125 ;
unsigned long V_33 ;
F_52 ( V_4 -> V_7 != V_121 ) ;
V_125 = F_16 ( sizeof( * V_125 ) + V_62 , V_123 ) ;
if ( ! V_125 )
return;
V_125 -> type = V_144 ;
V_125 -> V_145 . V_61 = ( ( T_1 * ) V_125 ) + sizeof( * V_125 ) ;
V_125 -> V_145 . V_62 = V_62 ;
memcpy ( ( void * ) V_125 -> V_145 . V_61 , V_61 , V_62 ) ;
V_125 -> V_145 . V_136 = V_136 ;
F_53 ( & V_4 -> V_128 , V_33 ) ;
F_54 ( & V_125 -> V_129 , & V_4 -> V_130 ) ;
F_55 ( & V_4 -> V_128 , V_33 ) ;
F_56 ( V_131 , & V_2 -> V_132 ) ;
}
int F_65 ( struct V_1 * V_2 ,
struct V_81 * V_40 ,
struct V_46 * V_142 ,
struct V_146 * V_147 ,
const T_1 * V_47 )
{
struct V_3 * V_4 = V_40 -> V_82 ;
struct V_75 * V_76 = NULL ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_8 )
return - V_148 ;
if ( F_39 ( V_4 -> V_93 ) ) {
F_19 ( V_4 -> V_93 ) ;
V_4 -> V_93 = NULL ;
}
F_66 ( & V_142 -> V_65 ,
V_2 -> V_11 . V_149 ) ;
if ( V_147 && V_147 -> V_150 >= 0 ) {
int V_151 ;
T_5 V_152 ;
V_151 = V_147 -> V_150 ;
V_152 = V_147 -> V_19 [ V_151 ] . V_152 ;
if ( V_152 == V_153 ||
V_152 == V_154 ) {
V_142 -> V_56 = V_151 ;
V_142 -> V_54 = V_147 -> V_19 [ V_151 ] . V_54 ;
V_142 -> V_55 = V_147 -> V_19 [ V_151 ] . V_55 ;
if ( V_142 -> V_63 . V_155 == 0 )
V_142 -> V_63 . V_155 = V_152 ;
if ( V_142 -> V_63 . V_156 == 0 ) {
V_142 -> V_63 . V_156 = 1 ;
V_142 -> V_63 . V_157 [ 0 ] = V_152 ;
}
}
}
if ( ! V_2 -> V_42 -> V_142 ) {
if ( ! V_2 -> V_42 -> V_50 || ! V_2 -> V_42 -> V_58 )
return - V_158 ;
if ( F_39 ( V_4 -> V_18 ) )
return - V_159 ;
V_4 -> V_18 = F_16 ( sizeof( * V_4 -> V_18 ) , V_27 ) ;
if ( ! V_4 -> V_18 )
return - V_28 ;
memcpy ( & V_4 -> V_18 -> V_19 , V_142 , sizeof( * V_142 ) ) ;
if ( V_142 -> V_53 ) {
V_4 -> V_18 -> V_19 . V_53 = V_4 -> V_18 -> V_53 ;
memcpy ( V_4 -> V_18 -> V_53 , V_142 -> V_53 , V_71 ) ;
}
if ( V_142 -> V_61 ) {
V_4 -> V_18 -> V_61 = F_67 ( V_142 -> V_61 , V_142 -> V_62 ,
V_27 ) ;
V_4 -> V_18 -> V_19 . V_61 = V_4 -> V_18 -> V_61 ;
if ( ! V_4 -> V_18 -> V_61 ) {
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
return - V_28 ;
}
}
if ( V_142 -> V_52 == V_160 ) {
V_4 -> V_18 -> V_90 = true ;
V_4 -> V_18 -> V_19 . V_52 =
V_92 ;
} else {
V_4 -> V_18 -> V_90 = false ;
}
memcpy ( V_4 -> V_38 , V_142 -> V_38 , V_142 -> V_39 ) ;
V_4 -> V_39 = V_142 -> V_39 ;
V_4 -> V_18 -> V_19 . V_38 = V_4 -> V_38 ;
V_4 -> V_18 -> V_19 . V_39 = V_142 -> V_39 ;
V_76 = F_31 ( V_4 ) ;
V_4 -> V_7 = V_73 ;
V_4 -> V_93 = V_147 ;
if ( V_47 ) {
memcpy ( V_4 -> V_18 -> V_47 , V_47 , V_71 ) ;
V_4 -> V_18 -> V_60 = true ;
}
if ( V_76 ) {
V_4 -> V_18 -> V_44 = V_49 ;
V_15 = F_20 ( V_4 ) ;
F_35 ( V_76 ) ;
} else {
V_15 = F_11 ( V_4 ) ;
if ( V_15 == - V_17 ) {
V_15 = 0 ;
V_4 -> V_18 -> V_44 = V_48 ;
}
}
if ( V_15 ) {
F_19 ( V_4 -> V_18 -> V_61 ) ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
V_4 -> V_7 = V_8 ;
V_4 -> V_93 = NULL ;
V_4 -> V_39 = 0 ;
}
return V_15 ;
} else {
V_4 -> V_7 = V_73 ;
V_4 -> V_93 = V_147 ;
V_15 = V_2 -> V_42 -> V_142 ( & V_2 -> V_11 , V_40 , V_142 ) ;
if ( V_15 ) {
V_4 -> V_93 = NULL ;
V_4 -> V_7 = V_8 ;
return V_15 ;
}
memcpy ( V_4 -> V_38 , V_142 -> V_38 , V_142 -> V_39 ) ;
V_4 -> V_39 = V_142 -> V_39 ;
return 0 ;
}
}
int F_68 ( struct V_1 * V_2 ,
struct V_81 * V_40 ,
struct V_46 * V_142 ,
struct V_146 * V_147 )
{
int V_15 ;
F_2 ( & V_2 -> V_72 ) ;
F_5 ( V_40 -> V_82 ) ;
V_15 = F_65 ( V_2 , V_40 , V_142 , V_147 , NULL ) ;
F_6 ( V_40 -> V_82 ) ;
F_8 ( & V_2 -> V_72 ) ;
return V_15 ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_81 * V_40 , T_2 V_136 , bool V_101 )
{
struct V_3 * V_4 = V_40 -> V_82 ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 == V_8 )
return - V_68 ;
F_19 ( V_4 -> V_93 ) ;
V_4 -> V_93 = NULL ;
if ( ! V_2 -> V_42 -> V_161 ) {
if ( ! V_2 -> V_42 -> V_162 )
return - V_158 ;
if ( ! V_4 -> V_18 ) {
F_70 ( V_2 , V_40 ) ;
return 0 ;
}
if ( V_4 -> V_7 == V_73 &&
( V_4 -> V_18 -> V_44 == V_45 ||
V_4 -> V_18 -> V_44 == V_48 ) ) {
V_4 -> V_7 = V_8 ;
F_19 ( V_4 -> V_18 -> V_61 ) ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
V_4 -> V_39 = 0 ;
return 0 ;
}
V_15 = F_24 ( V_2 , V_40 ,
V_4 -> V_18 -> V_19 . V_53 ,
NULL , 0 , V_136 , false ) ;
if ( V_15 )
return V_15 ;
} else {
V_15 = V_2 -> V_42 -> V_161 ( & V_2 -> V_11 , V_40 , V_136 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_4 -> V_7 == V_121 )
F_61 ( V_40 , NULL , 0 , 0 , false ) ;
else if ( V_4 -> V_7 == V_73 )
F_29 ( V_40 , NULL , NULL , 0 , NULL , 0 ,
V_74 ,
V_101 , NULL ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 ,
struct V_81 * V_40 ,
T_2 V_136 , bool V_101 )
{
int V_15 ;
F_5 ( V_40 -> V_82 ) ;
V_15 = F_69 ( V_2 , V_40 , V_136 , V_101 ) ;
F_6 ( V_40 -> V_82 ) ;
return V_15 ;
}
void F_72 ( struct V_81 * V_40 , int V_151 )
{
struct V_3 * V_4 = V_40 -> V_82 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
T_1 V_53 [ V_71 ] ;
F_15 ( V_4 ) ;
if ( ! V_4 -> V_18 )
return;
if ( V_4 -> V_18 -> V_44 == V_120 )
return;
if ( ! V_4 -> V_140 [ V_151 ] )
return;
memcpy ( V_53 , V_4 -> V_140 [ V_151 ] -> V_119 . V_53 , V_71 ) ;
if ( F_24 ( V_2 , V_40 , V_53 ,
NULL , 0 , V_66 ,
false ) ) {
F_45 ( V_4 -> V_140 [ V_151 ] ) ;
F_35 ( & V_4 -> V_140 [ V_151 ] -> V_119 ) ;
V_4 -> V_140 [ V_151 ] = NULL ;
}
}
