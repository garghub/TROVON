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
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! V_4 -> V_11 -> V_24 [ V_22 ] )
continue;
for ( V_30 = 0 ; V_30 < V_4 -> V_11 -> V_24 [ V_22 ] -> V_14 ;
V_29 ++ , V_30 ++ )
V_13 -> V_26 [ V_29 ] =
& V_4 -> V_11 -> V_24 [ V_22 ] -> V_26 [ V_30 ] ;
V_13 -> V_31 [ V_22 ] =
( 1 << V_4 -> V_11 -> V_24 [ V_22 ] -> V_32 ) - 1 ;
}
}
V_13 -> V_14 = V_14 ;
V_13 -> V_25 = ( void * ) & V_13 -> V_26 [ V_14 ] ;
V_13 -> V_33 = 1 ;
memcpy ( V_13 -> V_25 [ 0 ] . V_34 , V_4 -> V_18 -> V_19 . V_34 ,
V_4 -> V_18 -> V_19 . V_35 ) ;
V_13 -> V_25 [ 0 ] . V_35 = V_4 -> V_18 -> V_19 . V_35 ;
V_13 -> V_36 = V_4 -> V_37 ;
V_13 -> V_11 = & V_2 -> V_11 ;
V_2 -> V_16 = V_13 ;
V_15 = V_2 -> V_38 -> V_39 ( V_4 -> V_11 , V_4 -> V_37 , V_13 ) ;
if ( ! V_15 ) {
V_4 -> V_18 -> V_40 = V_41 ;
F_17 ( V_2 , V_4 -> V_37 ) ;
F_18 ( V_4 -> V_37 ) ;
} else {
V_2 -> V_16 = NULL ;
F_19 ( V_13 ) ;
}
return V_15 ;
}
static int F_20 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_42 * V_19 ;
const T_1 * V_43 = NULL ;
int V_15 ;
F_15 ( V_4 ) ;
if ( ! V_4 -> V_18 )
return 0 ;
V_19 = & V_4 -> V_18 -> V_19 ;
switch ( V_4 -> V_18 -> V_40 ) {
case V_44 :
return F_11 ( V_4 ) ;
case V_45 :
F_21 ( ! V_2 -> V_38 -> V_46 ) ;
V_4 -> V_18 -> V_40 = V_47 ;
return F_22 ( V_2 , V_4 -> V_37 ,
V_19 -> V_20 , V_19 -> V_48 ,
V_19 -> V_49 ,
V_19 -> V_34 , V_19 -> V_35 ,
NULL , 0 ,
V_19 -> V_50 , V_19 -> V_51 ,
V_19 -> V_52 , false ) ;
case V_53 :
F_21 ( ! V_2 -> V_38 -> V_54 ) ;
V_4 -> V_18 -> V_40 = V_55 ;
if ( V_4 -> V_18 -> V_56 )
V_43 = V_4 -> V_18 -> V_43 ;
V_15 = F_23 ( V_2 , V_4 -> V_37 ,
V_19 -> V_20 , V_19 -> V_49 ,
V_43 ,
V_19 -> V_34 , V_19 -> V_35 ,
V_19 -> V_57 , V_19 -> V_58 ,
false , & V_19 -> V_59 ) ;
if ( V_15 )
F_24 ( V_2 , V_4 -> V_37 , V_19 -> V_49 ,
NULL , 0 ,
V_60 ,
false ) ;
return V_15 ;
case V_61 :
F_24 ( V_2 , V_4 -> V_37 , V_19 -> V_49 ,
NULL , 0 ,
V_60 , false ) ;
return - V_62 ;
default:
return 0 ;
}
}
void F_25 ( struct V_9 * V_10 )
{
struct V_1 * V_2 =
F_26 ( V_10 , struct V_1 , V_63 ) ;
struct V_3 * V_4 ;
T_1 V_64 [ V_65 ] , * V_49 = NULL ;
F_27 () ;
F_4 ( V_2 ) ;
F_2 ( & V_2 -> V_66 ) ;
F_3 (wdev, &rdev->netdev_list, list) {
F_5 ( V_4 ) ;
if ( ! F_28 ( V_4 -> V_37 ) ) {
F_6 ( V_4 ) ;
continue;
}
if ( V_4 -> V_7 != V_67 ) {
F_6 ( V_4 ) ;
continue;
}
if ( V_4 -> V_18 -> V_19 . V_49 ) {
memcpy ( V_64 , V_4 -> V_18 -> V_19 . V_49 , V_65 ) ;
V_49 = V_64 ;
}
if ( F_20 ( V_4 ) )
F_29 (
V_4 -> V_37 , V_49 ,
NULL , 0 , NULL , 0 ,
V_68 ,
false , NULL ) ;
F_6 ( V_4 ) ;
}
F_8 ( & V_2 -> V_66 ) ;
F_7 ( V_2 ) ;
F_30 () ;
}
static struct V_69 * F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_69 * V_70 ;
T_2 V_71 = V_72 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_18 -> V_19 . V_73 )
V_71 |= V_74 ;
V_70 = F_32 ( V_4 -> V_11 , V_4 -> V_18 -> V_19 . V_20 ,
V_4 -> V_18 -> V_19 . V_49 ,
V_4 -> V_18 -> V_19 . V_34 ,
V_4 -> V_18 -> V_19 . V_35 ,
V_72 | V_74 ,
V_71 ) ;
if ( ! V_70 )
return NULL ;
memcpy ( V_4 -> V_18 -> V_49 , V_70 -> V_49 , V_65 ) ;
V_4 -> V_18 -> V_19 . V_49 = V_4 -> V_18 -> V_49 ;
V_4 -> V_18 -> V_19 . V_20 = V_70 -> V_20 ;
V_4 -> V_18 -> V_40 = V_45 ;
F_33 ( & V_2 -> V_63 ) ;
return V_70 ;
}
static void F_34 ( struct V_75 * V_36 )
{
struct V_3 * V_4 = V_36 -> V_76 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_69 * V_70 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_67 )
return;
if ( ! V_4 -> V_18 )
return;
if ( V_4 -> V_18 -> V_40 != V_41 &&
V_4 -> V_18 -> V_40 != V_44 )
return;
V_70 = F_31 ( V_4 ) ;
if ( V_70 ) {
F_35 ( V_70 ) ;
} else {
if ( V_4 -> V_18 -> V_40 == V_44 )
F_33 ( & V_2 -> V_63 ) ;
else
F_29 (
V_4 -> V_37 ,
V_4 -> V_18 -> V_19 . V_49 ,
NULL , 0 , NULL , 0 ,
V_68 ,
false , NULL ) ;
}
}
void F_36 ( struct V_75 * V_36 )
{
struct V_3 * V_4 = V_36 -> V_76 ;
F_2 ( & F_12 ( V_4 -> V_11 ) -> V_66 ) ;
F_5 ( V_4 ) ;
F_34 ( V_36 ) ;
F_6 ( V_4 ) ;
F_8 ( & F_12 ( V_4 -> V_11 ) -> V_66 ) ;
}
void F_37 ( struct V_75 * V_36 ,
const T_1 * V_77 , T_3 V_78 )
{
struct V_3 * V_4 = V_36 -> V_76 ;
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
struct V_79 * V_80 = (struct V_79 * ) V_77 ;
T_2 V_81 = F_38 ( V_80 -> V_82 . V_46 . V_81 ) ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_67 )
return;
if ( F_39 ( ! V_4 -> V_18 ) )
return;
if ( V_81 == V_83 &&
V_4 -> V_18 -> V_84 &&
V_4 -> V_18 -> V_19 . V_48 != V_85 ) {
switch ( V_4 -> V_18 -> V_19 . V_48 ) {
case V_86 :
if ( V_4 -> V_87 )
V_4 -> V_18 -> V_19 . V_48 =
V_88 ;
else
V_4 -> V_18 -> V_19 . V_48 =
V_85 ;
break;
case V_88 :
V_4 -> V_18 -> V_19 . V_48 =
V_85 ;
break;
default:
V_4 -> V_18 -> V_19 . V_48 =
V_86 ;
break;
}
V_4 -> V_18 -> V_40 = V_45 ;
F_33 ( & V_2 -> V_63 ) ;
} else if ( V_81 != V_89 ) {
F_29 ( V_36 , V_80 -> V_49 , NULL , 0 , NULL , 0 ,
V_81 , false , NULL ) ;
} else if ( V_4 -> V_7 == V_67 &&
V_4 -> V_18 -> V_40 == V_47 ) {
V_4 -> V_18 -> V_40 = V_53 ;
F_33 ( & V_2 -> V_63 ) ;
}
}
bool F_40 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
if ( F_39 ( ! V_4 -> V_18 ) )
return false ;
if ( ! V_4 -> V_18 -> V_56 )
return false ;
V_4 -> V_18 -> V_56 = false ;
V_4 -> V_18 -> V_40 = V_53 ;
F_33 ( & V_2 -> V_63 ) ;
return true ;
}
void F_41 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
V_4 -> V_18 -> V_40 = V_61 ;
F_33 ( & V_2 -> V_63 ) ;
}
void F_29 ( struct V_75 * V_36 , const T_1 * V_49 ,
const T_1 * V_90 , T_3 V_91 ,
const T_1 * V_92 , T_3 V_93 ,
T_2 V_94 , bool V_95 ,
struct V_69 * V_70 )
{
struct V_3 * V_4 = V_36 -> V_76 ;
T_1 * V_96 ;
#ifdef F_42
union V_97 V_98 ;
#endif
F_15 ( V_4 ) ;
if ( F_39 ( V_4 -> V_99 != V_100 &&
V_4 -> V_99 != V_101 ) )
return;
if ( V_4 -> V_7 != V_67 )
return;
F_43 ( F_12 ( V_4 -> V_11 ) , V_36 ,
V_49 , V_90 , V_91 ,
V_92 , V_93 ,
V_94 , V_27 ) ;
#ifdef F_42
if ( V_95 ) {
if ( V_90 && V_94 == V_89 ) {
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_102 . V_103 = V_91 ;
F_44 ( V_36 , V_104 , & V_98 , V_90 ) ;
}
if ( V_92 && V_94 == V_89 ) {
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_102 . V_103 = V_93 ;
F_44 ( V_36 , V_105 , & V_98 , V_92 ) ;
}
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_106 . V_107 = V_108 ;
if ( V_49 && V_94 == V_89 ) {
memcpy ( V_98 . V_106 . V_109 , V_49 , V_65 ) ;
memcpy ( V_4 -> V_110 . V_43 , V_49 , V_65 ) ;
V_4 -> V_110 . V_56 = true ;
}
F_44 ( V_36 , V_111 , & V_98 , NULL ) ;
}
#endif
if ( V_4 -> V_112 ) {
F_45 ( V_4 -> V_112 ) ;
F_35 ( & V_4 -> V_112 -> V_113 ) ;
V_4 -> V_112 = NULL ;
}
if ( V_4 -> V_18 )
V_4 -> V_18 -> V_40 = V_114 ;
if ( V_94 != V_89 ) {
V_4 -> V_7 = V_8 ;
if ( V_4 -> V_18 )
F_19 ( V_4 -> V_18 -> V_57 ) ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
F_19 ( V_4 -> V_87 ) ;
V_4 -> V_87 = NULL ;
V_4 -> V_35 = 0 ;
return;
}
if ( ! V_70 )
V_70 = F_32 ( V_4 -> V_11 ,
V_4 -> V_18 ? V_4 -> V_18 -> V_19 . V_20 :
NULL ,
V_49 ,
V_4 -> V_34 , V_4 -> V_35 ,
V_72 ,
V_72 ) ;
if ( F_39 ( ! V_70 ) )
return;
F_46 ( F_47 ( V_70 ) ) ;
V_4 -> V_112 = F_47 ( V_70 ) ;
V_4 -> V_7 = V_115 ;
F_48 ( V_4 ) ;
V_96 = ( T_1 * ) F_49 ( V_70 , V_116 ) ;
if ( ! V_96 )
return;
F_50 ( V_4 -> V_11 ,
V_70 -> V_20 -> V_22 ,
V_96 + 2 ,
V_96 [ 1 ] ) ;
}
void F_51 ( struct V_75 * V_36 , const T_1 * V_49 ,
const T_1 * V_90 , T_3 V_91 ,
const T_1 * V_92 , T_3 V_93 ,
T_2 V_94 , T_4 V_117 )
{
struct V_3 * V_4 = V_36 -> V_76 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_118 * V_119 ;
unsigned long V_120 ;
F_52 ( V_4 -> V_7 != V_67 ) ;
V_119 = F_16 ( sizeof( * V_119 ) + V_91 + V_93 , V_117 ) ;
if ( ! V_119 )
return;
V_119 -> type = V_121 ;
if ( V_49 )
memcpy ( V_119 -> V_122 . V_49 , V_49 , V_65 ) ;
if ( V_91 ) {
V_119 -> V_122 . V_90 = ( ( T_1 * ) V_119 ) + sizeof( * V_119 ) ;
V_119 -> V_122 . V_91 = V_91 ;
memcpy ( ( void * ) V_119 -> V_122 . V_90 , V_90 , V_91 ) ;
}
if ( V_93 ) {
V_119 -> V_122 . V_92 = ( ( T_1 * ) V_119 ) + sizeof( * V_119 ) + V_91 ;
V_119 -> V_122 . V_93 = V_93 ;
memcpy ( ( void * ) V_119 -> V_122 . V_92 , V_92 , V_93 ) ;
}
V_119 -> V_122 . V_94 = V_94 ;
F_53 ( & V_4 -> V_123 , V_120 ) ;
F_54 ( & V_119 -> V_124 , & V_4 -> V_125 ) ;
F_55 ( & V_4 -> V_123 , V_120 ) ;
F_56 ( V_126 , & V_2 -> V_127 ) ;
}
void F_57 ( struct V_3 * V_4 ,
struct V_128 * V_20 ,
const T_1 * V_49 ,
const T_1 * V_90 , T_3 V_91 ,
const T_1 * V_92 , T_3 V_93 )
{
struct V_69 * V_70 ;
#ifdef F_42
union V_97 V_98 ;
#endif
F_15 ( V_4 ) ;
if ( F_39 ( V_4 -> V_99 != V_100 &&
V_4 -> V_99 != V_101 ) )
return;
if ( V_4 -> V_7 != V_115 )
return;
if ( F_39 ( ! V_4 -> V_112 ) ) {
return;
}
F_45 ( V_4 -> V_112 ) ;
F_35 ( & V_4 -> V_112 -> V_113 ) ;
V_4 -> V_112 = NULL ;
V_70 = F_32 ( V_4 -> V_11 , V_20 , V_49 ,
V_4 -> V_34 , V_4 -> V_35 ,
V_72 , V_72 ) ;
if ( F_39 ( ! V_70 ) )
return;
F_46 ( F_47 ( V_70 ) ) ;
V_4 -> V_112 = F_47 ( V_70 ) ;
F_58 ( F_12 ( V_4 -> V_11 ) , V_4 -> V_37 , V_49 ,
V_90 , V_91 , V_92 , V_93 ,
V_27 ) ;
#ifdef F_42
if ( V_90 ) {
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_102 . V_103 = V_91 ;
F_44 ( V_4 -> V_37 , V_104 ,
& V_98 , V_90 ) ;
}
if ( V_92 ) {
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_102 . V_103 = V_93 ;
F_44 ( V_4 -> V_37 , V_105 ,
& V_98 , V_92 ) ;
}
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_106 . V_107 = V_108 ;
memcpy ( V_98 . V_106 . V_109 , V_49 , V_65 ) ;
memcpy ( V_4 -> V_110 . V_43 , V_49 , V_65 ) ;
V_4 -> V_110 . V_56 = true ;
F_44 ( V_4 -> V_37 , V_111 , & V_98 , NULL ) ;
#endif
}
void F_59 ( struct V_75 * V_36 ,
struct V_128 * V_20 ,
const T_1 * V_49 ,
const T_1 * V_90 , T_3 V_91 ,
const T_1 * V_92 , T_3 V_93 , T_4 V_117 )
{
struct V_3 * V_4 = V_36 -> V_76 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_118 * V_119 ;
unsigned long V_120 ;
F_52 ( V_4 -> V_7 != V_115 ) ;
V_119 = F_16 ( sizeof( * V_119 ) + V_91 + V_93 , V_117 ) ;
if ( ! V_119 )
return;
V_119 -> type = V_129 ;
V_119 -> V_130 . V_20 = V_20 ;
memcpy ( V_119 -> V_130 . V_49 , V_49 , V_65 ) ;
V_119 -> V_130 . V_90 = ( ( T_1 * ) V_119 ) + sizeof( * V_119 ) ;
V_119 -> V_130 . V_91 = V_91 ;
memcpy ( ( void * ) V_119 -> V_130 . V_90 , V_90 , V_91 ) ;
V_119 -> V_130 . V_92 = ( ( T_1 * ) V_119 ) + sizeof( * V_119 ) + V_91 ;
V_119 -> V_130 . V_93 = V_93 ;
memcpy ( ( void * ) V_119 -> V_130 . V_92 , V_92 , V_93 ) ;
F_53 ( & V_4 -> V_123 , V_120 ) ;
F_54 ( & V_119 -> V_124 , & V_4 -> V_125 ) ;
F_55 ( & V_4 -> V_123 , V_120 ) ;
F_56 ( V_126 , & V_2 -> V_127 ) ;
}
void F_60 ( struct V_75 * V_36 , const T_1 * V_57 ,
T_3 V_58 , T_2 V_131 , bool V_132 )
{
struct V_3 * V_4 = V_36 -> V_76 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
int V_29 ;
#ifdef F_42
union V_97 V_98 ;
#endif
F_15 ( V_4 ) ;
if ( F_39 ( V_4 -> V_99 != V_100 &&
V_4 -> V_99 != V_101 ) )
return;
if ( V_4 -> V_7 != V_115 )
return;
if ( V_4 -> V_112 ) {
F_45 ( V_4 -> V_112 ) ;
F_35 ( & V_4 -> V_112 -> V_113 ) ;
}
V_4 -> V_112 = NULL ;
V_4 -> V_7 = V_8 ;
V_4 -> V_35 = 0 ;
if ( V_4 -> V_18 ) {
const T_1 * V_49 ;
int V_133 ;
F_19 ( V_4 -> V_18 -> V_57 ) ;
V_4 -> V_18 -> V_57 = NULL ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
for ( V_29 = 0 ; V_29 < V_134 ; V_29 ++ ) {
if ( ! V_4 -> V_135 [ V_29 ] )
continue;
V_49 = V_4 -> V_135 [ V_29 ] -> V_113 . V_49 ;
V_133 = F_24 ( V_2 , V_36 , V_49 , NULL , 0 ,
V_60 ,
false ) ;
F_61 ( V_133 , L_1 , V_133 ) ;
}
}
F_62 ( V_2 , V_36 , V_131 , V_57 , V_58 , V_132 ) ;
if ( V_2 -> V_38 -> V_136 )
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
V_2 -> V_38 -> V_136 ( V_4 -> V_11 , V_36 , V_29 , false , NULL ) ;
#ifdef F_42
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_106 . V_107 = V_108 ;
F_44 ( V_36 , V_111 , & V_98 , NULL ) ;
V_4 -> V_110 . V_137 . V_35 = 0 ;
#endif
F_33 ( & V_138 ) ;
}
void F_63 ( struct V_75 * V_36 , T_2 V_131 ,
T_1 * V_57 , T_3 V_58 , T_4 V_117 )
{
struct V_3 * V_4 = V_36 -> V_76 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_118 * V_119 ;
unsigned long V_120 ;
F_52 ( V_4 -> V_7 != V_115 ) ;
V_119 = F_16 ( sizeof( * V_119 ) + V_58 , V_117 ) ;
if ( ! V_119 )
return;
V_119 -> type = V_139 ;
V_119 -> V_140 . V_57 = ( ( T_1 * ) V_119 ) + sizeof( * V_119 ) ;
V_119 -> V_140 . V_58 = V_58 ;
memcpy ( ( void * ) V_119 -> V_140 . V_57 , V_57 , V_58 ) ;
V_119 -> V_140 . V_131 = V_131 ;
F_53 ( & V_4 -> V_123 , V_120 ) ;
F_54 ( & V_119 -> V_124 , & V_4 -> V_125 ) ;
F_55 ( & V_4 -> V_123 , V_120 ) ;
F_56 ( V_126 , & V_2 -> V_127 ) ;
}
int F_64 ( struct V_1 * V_2 ,
struct V_75 * V_36 ,
struct V_42 * V_137 ,
struct V_141 * V_142 ,
const T_1 * V_43 )
{
struct V_3 * V_4 = V_36 -> V_76 ;
struct V_69 * V_70 = NULL ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_8 )
return - V_143 ;
if ( F_39 ( V_4 -> V_87 ) ) {
F_19 ( V_4 -> V_87 ) ;
V_4 -> V_87 = NULL ;
}
if ( V_142 && V_142 -> V_144 >= 0 ) {
int V_145 ;
T_5 V_146 ;
V_145 = V_142 -> V_144 ;
V_146 = V_142 -> V_19 [ V_145 ] . V_146 ;
if ( V_146 == V_147 ||
V_146 == V_148 ) {
V_137 -> V_52 = V_145 ;
V_137 -> V_50 = V_142 -> V_19 [ V_145 ] . V_50 ;
V_137 -> V_51 = V_142 -> V_19 [ V_145 ] . V_51 ;
if ( V_137 -> V_59 . V_149 == 0 )
V_137 -> V_59 . V_149 = V_146 ;
if ( V_137 -> V_59 . V_150 == 0 ) {
V_137 -> V_59 . V_150 = 1 ;
V_137 -> V_59 . V_151 [ 0 ] = V_146 ;
}
}
}
if ( ! V_2 -> V_38 -> V_137 ) {
if ( ! V_2 -> V_38 -> V_46 || ! V_2 -> V_38 -> V_54 )
return - V_152 ;
if ( F_39 ( V_4 -> V_18 ) )
return - V_153 ;
V_4 -> V_18 = F_16 ( sizeof( * V_4 -> V_18 ) , V_27 ) ;
if ( ! V_4 -> V_18 )
return - V_28 ;
memcpy ( & V_4 -> V_18 -> V_19 , V_137 , sizeof( * V_137 ) ) ;
if ( V_137 -> V_49 ) {
V_4 -> V_18 -> V_19 . V_49 = V_4 -> V_18 -> V_49 ;
memcpy ( V_4 -> V_18 -> V_49 , V_137 -> V_49 , V_65 ) ;
}
if ( V_137 -> V_57 ) {
V_4 -> V_18 -> V_57 = F_65 ( V_137 -> V_57 , V_137 -> V_58 ,
V_27 ) ;
V_4 -> V_18 -> V_19 . V_57 = V_4 -> V_18 -> V_57 ;
if ( ! V_4 -> V_18 -> V_57 ) {
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
return - V_28 ;
}
}
if ( V_137 -> V_48 == V_154 ) {
V_4 -> V_18 -> V_84 = true ;
V_4 -> V_18 -> V_19 . V_48 =
V_86 ;
} else {
V_4 -> V_18 -> V_84 = false ;
}
memcpy ( V_4 -> V_34 , V_137 -> V_34 , V_137 -> V_35 ) ;
V_4 -> V_35 = V_137 -> V_35 ;
V_4 -> V_18 -> V_19 . V_34 = V_4 -> V_34 ;
V_4 -> V_18 -> V_19 . V_35 = V_137 -> V_35 ;
V_70 = F_31 ( V_4 ) ;
V_4 -> V_7 = V_67 ;
V_4 -> V_87 = V_142 ;
if ( V_43 ) {
memcpy ( V_4 -> V_18 -> V_43 , V_43 , V_65 ) ;
V_4 -> V_18 -> V_56 = true ;
}
if ( V_70 ) {
V_4 -> V_18 -> V_40 = V_45 ;
V_15 = F_20 ( V_4 ) ;
F_35 ( V_70 ) ;
} else {
V_15 = F_11 ( V_4 ) ;
if ( V_15 == - V_17 ) {
V_15 = 0 ;
V_4 -> V_18 -> V_40 = V_44 ;
}
}
if ( V_15 ) {
F_19 ( V_4 -> V_18 -> V_57 ) ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
V_4 -> V_7 = V_8 ;
V_4 -> V_87 = NULL ;
V_4 -> V_35 = 0 ;
}
return V_15 ;
} else {
V_4 -> V_7 = V_67 ;
V_4 -> V_87 = V_142 ;
V_15 = V_2 -> V_38 -> V_137 ( & V_2 -> V_11 , V_36 , V_137 ) ;
if ( V_15 ) {
V_4 -> V_87 = NULL ;
V_4 -> V_7 = V_8 ;
return V_15 ;
}
memcpy ( V_4 -> V_34 , V_137 -> V_34 , V_137 -> V_35 ) ;
V_4 -> V_35 = V_137 -> V_35 ;
return 0 ;
}
}
int F_66 ( struct V_1 * V_2 ,
struct V_75 * V_36 ,
struct V_42 * V_137 ,
struct V_141 * V_142 )
{
int V_15 ;
F_2 ( & V_2 -> V_66 ) ;
F_5 ( V_36 -> V_76 ) ;
V_15 = F_64 ( V_2 , V_36 , V_137 , V_142 , NULL ) ;
F_6 ( V_36 -> V_76 ) ;
F_8 ( & V_2 -> V_66 ) ;
return V_15 ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_75 * V_36 , T_2 V_131 , bool V_95 )
{
struct V_3 * V_4 = V_36 -> V_76 ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 == V_8 )
return - V_62 ;
F_19 ( V_4 -> V_87 ) ;
V_4 -> V_87 = NULL ;
if ( ! V_2 -> V_38 -> V_155 ) {
if ( ! V_2 -> V_38 -> V_156 )
return - V_152 ;
if ( ! V_4 -> V_18 ) {
F_68 ( V_2 , V_36 ) ;
return 0 ;
}
if ( V_4 -> V_7 == V_67 &&
( V_4 -> V_18 -> V_40 == V_41 ||
V_4 -> V_18 -> V_40 == V_44 ) ) {
V_4 -> V_7 = V_8 ;
F_19 ( V_4 -> V_18 -> V_57 ) ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
V_4 -> V_35 = 0 ;
return 0 ;
}
V_15 = F_24 ( V_2 , V_36 ,
V_4 -> V_18 -> V_19 . V_49 ,
NULL , 0 , V_131 , false ) ;
if ( V_15 )
return V_15 ;
} else {
V_15 = V_2 -> V_38 -> V_155 ( & V_2 -> V_11 , V_36 , V_131 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_4 -> V_7 == V_115 )
F_60 ( V_36 , NULL , 0 , 0 , false ) ;
else if ( V_4 -> V_7 == V_67 )
F_29 ( V_36 , NULL , NULL , 0 , NULL , 0 ,
V_68 ,
V_95 , NULL ) ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_75 * V_36 ,
T_2 V_131 , bool V_95 )
{
int V_15 ;
F_5 ( V_36 -> V_76 ) ;
V_15 = F_67 ( V_2 , V_36 , V_131 , V_95 ) ;
F_6 ( V_36 -> V_76 ) ;
return V_15 ;
}
void F_70 ( struct V_75 * V_36 , int V_145 )
{
struct V_3 * V_4 = V_36 -> V_76 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
T_1 V_49 [ V_65 ] ;
F_15 ( V_4 ) ;
if ( ! V_4 -> V_18 )
return;
if ( V_4 -> V_18 -> V_40 == V_114 )
return;
if ( ! V_4 -> V_135 [ V_145 ] )
return;
memcpy ( V_49 , V_4 -> V_135 [ V_145 ] -> V_113 . V_49 , V_65 ) ;
if ( F_24 ( V_2 , V_36 , V_49 ,
NULL , 0 , V_60 ,
false ) ) {
F_45 ( V_4 -> V_135 [ V_145 ] ) ;
F_35 ( & V_4 -> V_135 [ V_145 ] -> V_113 ) ;
V_4 -> V_135 [ V_145 ] = NULL ;
}
}
