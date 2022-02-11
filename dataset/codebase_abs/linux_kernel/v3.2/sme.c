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
false , & V_19 -> V_63 ) ;
if ( V_15 )
F_24 ( V_2 , V_4 -> V_41 , V_19 -> V_53 ,
NULL , 0 ,
V_64 ,
false ) ;
return V_15 ;
case V_65 :
F_24 ( V_2 , V_4 -> V_41 , V_19 -> V_53 ,
NULL , 0 ,
V_64 , false ) ;
return - V_66 ;
default:
return 0 ;
}
}
void F_25 ( struct V_9 * V_10 )
{
struct V_1 * V_2 =
F_26 ( V_10 , struct V_1 , V_67 ) ;
struct V_3 * V_4 ;
T_1 V_68 [ V_69 ] , * V_53 = NULL ;
F_27 () ;
F_4 ( V_2 ) ;
F_2 ( & V_2 -> V_70 ) ;
F_3 (wdev, &rdev->netdev_list, list) {
F_5 ( V_4 ) ;
if ( ! F_28 ( V_4 -> V_41 ) ) {
F_6 ( V_4 ) ;
continue;
}
if ( V_4 -> V_7 != V_71 ) {
F_6 ( V_4 ) ;
continue;
}
if ( V_4 -> V_18 -> V_19 . V_53 ) {
memcpy ( V_68 , V_4 -> V_18 -> V_19 . V_53 , V_69 ) ;
V_53 = V_68 ;
}
if ( F_20 ( V_4 ) )
F_29 (
V_4 -> V_41 , V_53 ,
NULL , 0 , NULL , 0 ,
V_72 ,
false , NULL ) ;
F_6 ( V_4 ) ;
}
F_8 ( & V_2 -> V_70 ) ;
F_7 ( V_2 ) ;
F_30 () ;
}
static struct V_73 * F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_73 * V_74 ;
T_2 V_75 = V_76 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_18 -> V_19 . V_77 )
V_75 |= V_78 ;
V_74 = F_32 ( V_4 -> V_11 , V_4 -> V_18 -> V_19 . V_20 ,
V_4 -> V_18 -> V_19 . V_53 ,
V_4 -> V_18 -> V_19 . V_38 ,
V_4 -> V_18 -> V_19 . V_39 ,
V_76 | V_78 ,
V_75 ) ;
if ( ! V_74 )
return NULL ;
memcpy ( V_4 -> V_18 -> V_53 , V_74 -> V_53 , V_69 ) ;
V_4 -> V_18 -> V_19 . V_53 = V_4 -> V_18 -> V_53 ;
V_4 -> V_18 -> V_19 . V_20 = V_74 -> V_20 ;
V_4 -> V_18 -> V_44 = V_49 ;
F_33 ( & V_2 -> V_67 ) ;
return V_74 ;
}
static void F_34 ( struct V_79 * V_40 )
{
struct V_3 * V_4 = V_40 -> V_80 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_73 * V_74 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_71 )
return;
if ( ! V_4 -> V_18 )
return;
if ( V_4 -> V_18 -> V_44 != V_45 &&
V_4 -> V_18 -> V_44 != V_48 )
return;
V_74 = F_31 ( V_4 ) ;
if ( V_74 ) {
F_35 ( V_74 ) ;
} else {
if ( V_4 -> V_18 -> V_44 == V_48 )
F_33 ( & V_2 -> V_67 ) ;
else
F_29 (
V_4 -> V_41 ,
V_4 -> V_18 -> V_19 . V_53 ,
NULL , 0 , NULL , 0 ,
V_72 ,
false , NULL ) ;
}
}
void F_36 ( struct V_79 * V_40 )
{
struct V_3 * V_4 = V_40 -> V_80 ;
F_2 ( & F_12 ( V_4 -> V_11 ) -> V_70 ) ;
F_5 ( V_4 ) ;
F_34 ( V_40 ) ;
F_6 ( V_4 ) ;
F_8 ( & F_12 ( V_4 -> V_11 ) -> V_70 ) ;
}
void F_37 ( struct V_79 * V_40 ,
const T_1 * V_81 , T_3 V_82 )
{
struct V_3 * V_4 = V_40 -> V_80 ;
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
struct V_83 * V_84 = (struct V_83 * ) V_81 ;
T_2 V_85 = F_38 ( V_84 -> V_86 . V_50 . V_85 ) ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_71 )
return;
if ( F_39 ( ! V_4 -> V_18 ) )
return;
if ( V_85 == V_87 &&
V_4 -> V_18 -> V_88 &&
V_4 -> V_18 -> V_19 . V_52 != V_89 ) {
switch ( V_4 -> V_18 -> V_19 . V_52 ) {
case V_90 :
if ( V_4 -> V_91 )
V_4 -> V_18 -> V_19 . V_52 =
V_92 ;
else
V_4 -> V_18 -> V_19 . V_52 =
V_89 ;
break;
case V_92 :
V_4 -> V_18 -> V_19 . V_52 =
V_89 ;
break;
default:
V_4 -> V_18 -> V_19 . V_52 =
V_90 ;
break;
}
V_4 -> V_18 -> V_44 = V_49 ;
F_33 ( & V_2 -> V_67 ) ;
} else if ( V_85 != V_93 ) {
F_29 ( V_40 , V_84 -> V_53 , NULL , 0 , NULL , 0 ,
V_85 , false , NULL ) ;
} else if ( V_4 -> V_7 == V_71 &&
V_4 -> V_18 -> V_44 == V_51 ) {
V_4 -> V_18 -> V_44 = V_57 ;
F_33 ( & V_2 -> V_67 ) ;
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
F_33 ( & V_2 -> V_67 ) ;
return true ;
}
void F_41 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
V_4 -> V_18 -> V_44 = V_65 ;
F_33 ( & V_2 -> V_67 ) ;
}
void F_29 ( struct V_79 * V_40 , const T_1 * V_53 ,
const T_1 * V_94 , T_3 V_95 ,
const T_1 * V_96 , T_3 V_97 ,
T_2 V_98 , bool V_99 ,
struct V_73 * V_74 )
{
struct V_3 * V_4 = V_40 -> V_80 ;
T_1 * V_100 ;
#ifdef F_42
union V_101 V_102 ;
#endif
F_15 ( V_4 ) ;
if ( F_39 ( V_4 -> V_103 != V_104 &&
V_4 -> V_103 != V_105 ) )
return;
if ( V_4 -> V_7 != V_71 )
return;
F_43 ( F_12 ( V_4 -> V_11 ) , V_40 ,
V_53 , V_94 , V_95 ,
V_96 , V_97 ,
V_98 , V_27 ) ;
#ifdef F_42
if ( V_99 ) {
if ( V_94 && V_98 == V_93 ) {
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_106 . V_107 = V_95 ;
F_44 ( V_40 , V_108 , & V_102 , V_94 ) ;
}
if ( V_96 && V_98 == V_93 ) {
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_106 . V_107 = V_97 ;
F_44 ( V_40 , V_109 , & V_102 , V_96 ) ;
}
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_110 . V_111 = V_112 ;
if ( V_53 && V_98 == V_93 ) {
memcpy ( V_102 . V_110 . V_113 , V_53 , V_69 ) ;
memcpy ( V_4 -> V_114 . V_47 , V_53 , V_69 ) ;
V_4 -> V_114 . V_60 = true ;
}
F_44 ( V_40 , V_115 , & V_102 , NULL ) ;
}
#endif
if ( V_4 -> V_116 ) {
F_45 ( V_4 -> V_116 ) ;
F_35 ( & V_4 -> V_116 -> V_117 ) ;
V_4 -> V_116 = NULL ;
}
if ( V_4 -> V_18 )
V_4 -> V_18 -> V_44 = V_118 ;
if ( V_98 != V_93 ) {
V_4 -> V_7 = V_8 ;
if ( V_4 -> V_18 )
F_19 ( V_4 -> V_18 -> V_61 ) ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
F_19 ( V_4 -> V_91 ) ;
V_4 -> V_91 = NULL ;
V_4 -> V_39 = 0 ;
return;
}
if ( ! V_74 )
V_74 = F_32 ( V_4 -> V_11 ,
V_4 -> V_18 ? V_4 -> V_18 -> V_19 . V_20 :
NULL ,
V_53 ,
V_4 -> V_38 , V_4 -> V_39 ,
V_76 ,
V_76 ) ;
if ( F_39 ( ! V_74 ) )
return;
F_46 ( F_47 ( V_74 ) ) ;
V_4 -> V_116 = F_47 ( V_74 ) ;
V_4 -> V_7 = V_119 ;
F_48 ( V_4 ) ;
V_100 = ( T_1 * ) F_49 ( V_74 , V_120 ) ;
if ( ! V_100 )
return;
F_50 ( V_4 -> V_11 ,
V_74 -> V_20 -> V_22 ,
V_100 + 2 ,
V_100 [ 1 ] ) ;
}
void F_51 ( struct V_79 * V_40 , const T_1 * V_53 ,
const T_1 * V_94 , T_3 V_95 ,
const T_1 * V_96 , T_3 V_97 ,
T_2 V_98 , T_4 V_121 )
{
struct V_3 * V_4 = V_40 -> V_80 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_122 * V_123 ;
unsigned long V_33 ;
F_52 ( V_4 -> V_7 != V_71 ) ;
V_123 = F_16 ( sizeof( * V_123 ) + V_95 + V_97 , V_121 ) ;
if ( ! V_123 )
return;
V_123 -> type = V_124 ;
if ( V_53 )
memcpy ( V_123 -> V_125 . V_53 , V_53 , V_69 ) ;
if ( V_95 ) {
V_123 -> V_125 . V_94 = ( ( T_1 * ) V_123 ) + sizeof( * V_123 ) ;
V_123 -> V_125 . V_95 = V_95 ;
memcpy ( ( void * ) V_123 -> V_125 . V_94 , V_94 , V_95 ) ;
}
if ( V_97 ) {
V_123 -> V_125 . V_96 = ( ( T_1 * ) V_123 ) + sizeof( * V_123 ) + V_95 ;
V_123 -> V_125 . V_97 = V_97 ;
memcpy ( ( void * ) V_123 -> V_125 . V_96 , V_96 , V_97 ) ;
}
V_123 -> V_125 . V_98 = V_98 ;
F_53 ( & V_4 -> V_126 , V_33 ) ;
F_54 ( & V_123 -> V_127 , & V_4 -> V_128 ) ;
F_55 ( & V_4 -> V_126 , V_33 ) ;
F_56 ( V_129 , & V_2 -> V_130 ) ;
}
void F_57 ( struct V_3 * V_4 ,
struct V_32 * V_20 ,
const T_1 * V_53 ,
const T_1 * V_94 , T_3 V_95 ,
const T_1 * V_96 , T_3 V_97 )
{
struct V_73 * V_74 ;
#ifdef F_42
union V_101 V_102 ;
#endif
F_15 ( V_4 ) ;
if ( F_39 ( V_4 -> V_103 != V_104 &&
V_4 -> V_103 != V_105 ) )
return;
if ( V_4 -> V_7 != V_119 )
return;
if ( F_39 ( ! V_4 -> V_116 ) ) {
return;
}
F_45 ( V_4 -> V_116 ) ;
F_35 ( & V_4 -> V_116 -> V_117 ) ;
V_4 -> V_116 = NULL ;
V_74 = F_32 ( V_4 -> V_11 , V_20 , V_53 ,
V_4 -> V_38 , V_4 -> V_39 ,
V_76 , V_76 ) ;
if ( F_39 ( ! V_74 ) )
return;
F_46 ( F_47 ( V_74 ) ) ;
V_4 -> V_116 = F_47 ( V_74 ) ;
F_58 ( F_12 ( V_4 -> V_11 ) , V_4 -> V_41 , V_53 ,
V_94 , V_95 , V_96 , V_97 ,
V_27 ) ;
#ifdef F_42
if ( V_94 ) {
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_106 . V_107 = V_95 ;
F_44 ( V_4 -> V_41 , V_108 ,
& V_102 , V_94 ) ;
}
if ( V_96 ) {
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_106 . V_107 = V_97 ;
F_44 ( V_4 -> V_41 , V_109 ,
& V_102 , V_96 ) ;
}
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_110 . V_111 = V_112 ;
memcpy ( V_102 . V_110 . V_113 , V_53 , V_69 ) ;
memcpy ( V_4 -> V_114 . V_47 , V_53 , V_69 ) ;
V_4 -> V_114 . V_60 = true ;
F_44 ( V_4 -> V_41 , V_115 , & V_102 , NULL ) ;
#endif
}
void F_59 ( struct V_79 * V_40 ,
struct V_32 * V_20 ,
const T_1 * V_53 ,
const T_1 * V_94 , T_3 V_95 ,
const T_1 * V_96 , T_3 V_97 , T_4 V_121 )
{
struct V_3 * V_4 = V_40 -> V_80 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_122 * V_123 ;
unsigned long V_33 ;
F_52 ( V_4 -> V_7 != V_119 ) ;
V_123 = F_16 ( sizeof( * V_123 ) + V_95 + V_97 , V_121 ) ;
if ( ! V_123 )
return;
V_123 -> type = V_131 ;
V_123 -> V_132 . V_20 = V_20 ;
memcpy ( V_123 -> V_132 . V_53 , V_53 , V_69 ) ;
V_123 -> V_132 . V_94 = ( ( T_1 * ) V_123 ) + sizeof( * V_123 ) ;
V_123 -> V_132 . V_95 = V_95 ;
memcpy ( ( void * ) V_123 -> V_132 . V_94 , V_94 , V_95 ) ;
V_123 -> V_132 . V_96 = ( ( T_1 * ) V_123 ) + sizeof( * V_123 ) + V_95 ;
V_123 -> V_132 . V_97 = V_97 ;
memcpy ( ( void * ) V_123 -> V_132 . V_96 , V_96 , V_97 ) ;
F_53 ( & V_4 -> V_126 , V_33 ) ;
F_54 ( & V_123 -> V_127 , & V_4 -> V_128 ) ;
F_55 ( & V_4 -> V_126 , V_33 ) ;
F_56 ( V_129 , & V_2 -> V_130 ) ;
}
void F_60 ( struct V_79 * V_40 , const T_1 * V_61 ,
T_3 V_62 , T_2 V_133 , bool V_134 )
{
struct V_3 * V_4 = V_40 -> V_80 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
int V_29 ;
#ifdef F_42
union V_101 V_102 ;
#endif
F_15 ( V_4 ) ;
if ( F_39 ( V_4 -> V_103 != V_104 &&
V_4 -> V_103 != V_105 ) )
return;
if ( V_4 -> V_7 != V_119 )
return;
if ( V_4 -> V_116 ) {
F_45 ( V_4 -> V_116 ) ;
F_35 ( & V_4 -> V_116 -> V_117 ) ;
}
V_4 -> V_116 = NULL ;
V_4 -> V_7 = V_8 ;
V_4 -> V_39 = 0 ;
if ( V_4 -> V_18 ) {
const T_1 * V_53 ;
int V_135 ;
F_19 ( V_4 -> V_18 -> V_61 ) ;
V_4 -> V_18 -> V_61 = NULL ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
for ( V_29 = 0 ; V_29 < V_136 ; V_29 ++ ) {
if ( ! V_4 -> V_137 [ V_29 ] )
continue;
V_53 = V_4 -> V_137 [ V_29 ] -> V_117 . V_53 ;
V_135 = F_24 ( V_2 , V_40 , V_53 , NULL , 0 ,
V_64 ,
false ) ;
F_61 ( V_135 , L_1 , V_135 ) ;
}
}
F_62 ( V_2 , V_40 , V_133 , V_61 , V_62 , V_134 ) ;
if ( V_2 -> V_42 -> V_138 )
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
V_2 -> V_42 -> V_138 ( V_4 -> V_11 , V_40 , V_29 , false , NULL ) ;
#ifdef F_42
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_110 . V_111 = V_112 ;
F_44 ( V_40 , V_115 , & V_102 , NULL ) ;
V_4 -> V_114 . V_139 . V_39 = 0 ;
#endif
F_33 ( & V_140 ) ;
}
void F_63 ( struct V_79 * V_40 , T_2 V_133 ,
T_1 * V_61 , T_3 V_62 , T_4 V_121 )
{
struct V_3 * V_4 = V_40 -> V_80 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_122 * V_123 ;
unsigned long V_33 ;
F_52 ( V_4 -> V_7 != V_119 ) ;
V_123 = F_16 ( sizeof( * V_123 ) + V_62 , V_121 ) ;
if ( ! V_123 )
return;
V_123 -> type = V_141 ;
V_123 -> V_142 . V_61 = ( ( T_1 * ) V_123 ) + sizeof( * V_123 ) ;
V_123 -> V_142 . V_62 = V_62 ;
memcpy ( ( void * ) V_123 -> V_142 . V_61 , V_61 , V_62 ) ;
V_123 -> V_142 . V_133 = V_133 ;
F_53 ( & V_4 -> V_126 , V_33 ) ;
F_54 ( & V_123 -> V_127 , & V_4 -> V_128 ) ;
F_55 ( & V_4 -> V_126 , V_33 ) ;
F_56 ( V_129 , & V_2 -> V_130 ) ;
}
int F_64 ( struct V_1 * V_2 ,
struct V_79 * V_40 ,
struct V_46 * V_139 ,
struct V_143 * V_144 ,
const T_1 * V_47 )
{
struct V_3 * V_4 = V_40 -> V_80 ;
struct V_73 * V_74 = NULL ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_8 )
return - V_145 ;
if ( F_39 ( V_4 -> V_91 ) ) {
F_19 ( V_4 -> V_91 ) ;
V_4 -> V_91 = NULL ;
}
if ( V_144 && V_144 -> V_146 >= 0 ) {
int V_147 ;
T_5 V_148 ;
V_147 = V_144 -> V_146 ;
V_148 = V_144 -> V_19 [ V_147 ] . V_148 ;
if ( V_148 == V_149 ||
V_148 == V_150 ) {
V_139 -> V_56 = V_147 ;
V_139 -> V_54 = V_144 -> V_19 [ V_147 ] . V_54 ;
V_139 -> V_55 = V_144 -> V_19 [ V_147 ] . V_55 ;
if ( V_139 -> V_63 . V_151 == 0 )
V_139 -> V_63 . V_151 = V_148 ;
if ( V_139 -> V_63 . V_152 == 0 ) {
V_139 -> V_63 . V_152 = 1 ;
V_139 -> V_63 . V_153 [ 0 ] = V_148 ;
}
}
}
if ( ! V_2 -> V_42 -> V_139 ) {
if ( ! V_2 -> V_42 -> V_50 || ! V_2 -> V_42 -> V_58 )
return - V_154 ;
if ( F_39 ( V_4 -> V_18 ) )
return - V_155 ;
V_4 -> V_18 = F_16 ( sizeof( * V_4 -> V_18 ) , V_27 ) ;
if ( ! V_4 -> V_18 )
return - V_28 ;
memcpy ( & V_4 -> V_18 -> V_19 , V_139 , sizeof( * V_139 ) ) ;
if ( V_139 -> V_53 ) {
V_4 -> V_18 -> V_19 . V_53 = V_4 -> V_18 -> V_53 ;
memcpy ( V_4 -> V_18 -> V_53 , V_139 -> V_53 , V_69 ) ;
}
if ( V_139 -> V_61 ) {
V_4 -> V_18 -> V_61 = F_65 ( V_139 -> V_61 , V_139 -> V_62 ,
V_27 ) ;
V_4 -> V_18 -> V_19 . V_61 = V_4 -> V_18 -> V_61 ;
if ( ! V_4 -> V_18 -> V_61 ) {
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
return - V_28 ;
}
}
if ( V_139 -> V_52 == V_156 ) {
V_4 -> V_18 -> V_88 = true ;
V_4 -> V_18 -> V_19 . V_52 =
V_90 ;
} else {
V_4 -> V_18 -> V_88 = false ;
}
memcpy ( V_4 -> V_38 , V_139 -> V_38 , V_139 -> V_39 ) ;
V_4 -> V_39 = V_139 -> V_39 ;
V_4 -> V_18 -> V_19 . V_38 = V_4 -> V_38 ;
V_4 -> V_18 -> V_19 . V_39 = V_139 -> V_39 ;
V_74 = F_31 ( V_4 ) ;
V_4 -> V_7 = V_71 ;
V_4 -> V_91 = V_144 ;
if ( V_47 ) {
memcpy ( V_4 -> V_18 -> V_47 , V_47 , V_69 ) ;
V_4 -> V_18 -> V_60 = true ;
}
if ( V_74 ) {
V_4 -> V_18 -> V_44 = V_49 ;
V_15 = F_20 ( V_4 ) ;
F_35 ( V_74 ) ;
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
V_4 -> V_91 = NULL ;
V_4 -> V_39 = 0 ;
}
return V_15 ;
} else {
V_4 -> V_7 = V_71 ;
V_4 -> V_91 = V_144 ;
V_15 = V_2 -> V_42 -> V_139 ( & V_2 -> V_11 , V_40 , V_139 ) ;
if ( V_15 ) {
V_4 -> V_91 = NULL ;
V_4 -> V_7 = V_8 ;
return V_15 ;
}
memcpy ( V_4 -> V_38 , V_139 -> V_38 , V_139 -> V_39 ) ;
V_4 -> V_39 = V_139 -> V_39 ;
return 0 ;
}
}
int F_66 ( struct V_1 * V_2 ,
struct V_79 * V_40 ,
struct V_46 * V_139 ,
struct V_143 * V_144 )
{
int V_15 ;
F_2 ( & V_2 -> V_70 ) ;
F_5 ( V_40 -> V_80 ) ;
V_15 = F_64 ( V_2 , V_40 , V_139 , V_144 , NULL ) ;
F_6 ( V_40 -> V_80 ) ;
F_8 ( & V_2 -> V_70 ) ;
return V_15 ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_79 * V_40 , T_2 V_133 , bool V_99 )
{
struct V_3 * V_4 = V_40 -> V_80 ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 == V_8 )
return - V_66 ;
F_19 ( V_4 -> V_91 ) ;
V_4 -> V_91 = NULL ;
if ( ! V_2 -> V_42 -> V_157 ) {
if ( ! V_2 -> V_42 -> V_158 )
return - V_154 ;
if ( ! V_4 -> V_18 ) {
F_68 ( V_2 , V_40 ) ;
return 0 ;
}
if ( V_4 -> V_7 == V_71 &&
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
NULL , 0 , V_133 , false ) ;
if ( V_15 )
return V_15 ;
} else {
V_15 = V_2 -> V_42 -> V_157 ( & V_2 -> V_11 , V_40 , V_133 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_4 -> V_7 == V_119 )
F_60 ( V_40 , NULL , 0 , 0 , false ) ;
else if ( V_4 -> V_7 == V_71 )
F_29 ( V_40 , NULL , NULL , 0 , NULL , 0 ,
V_72 ,
V_99 , NULL ) ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_79 * V_40 ,
T_2 V_133 , bool V_99 )
{
int V_15 ;
F_5 ( V_40 -> V_80 ) ;
V_15 = F_67 ( V_2 , V_40 , V_133 , V_99 ) ;
F_6 ( V_40 -> V_80 ) ;
return V_15 ;
}
void F_70 ( struct V_79 * V_40 , int V_147 )
{
struct V_3 * V_4 = V_40 -> V_80 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
T_1 V_53 [ V_69 ] ;
F_15 ( V_4 ) ;
if ( ! V_4 -> V_18 )
return;
if ( V_4 -> V_18 -> V_44 == V_118 )
return;
if ( ! V_4 -> V_137 [ V_147 ] )
return;
memcpy ( V_53 , V_4 -> V_137 [ V_147 ] -> V_117 . V_53 , V_69 ) ;
if ( F_24 ( V_2 , V_40 , V_53 ,
NULL , 0 , V_64 ,
false ) ) {
F_45 ( V_4 -> V_137 [ V_147 ] ) ;
F_35 ( & V_4 -> V_137 [ V_147 ] -> V_117 ) ;
V_4 -> V_137 [ V_147 ] = NULL ;
}
}
