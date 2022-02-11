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
}
}
V_13 -> V_14 = V_14 ;
V_13 -> V_25 = ( void * ) & V_13 -> V_26 [ V_14 ] ;
V_13 -> V_31 = 1 ;
memcpy ( V_13 -> V_25 [ 0 ] . V_32 , V_4 -> V_18 -> V_19 . V_32 ,
V_4 -> V_18 -> V_19 . V_33 ) ;
V_13 -> V_25 [ 0 ] . V_33 = V_4 -> V_18 -> V_19 . V_33 ;
V_13 -> V_34 = V_4 -> V_35 ;
V_13 -> V_11 = & V_2 -> V_11 ;
V_2 -> V_16 = V_13 ;
V_15 = V_2 -> V_36 -> V_37 ( V_4 -> V_11 , V_4 -> V_35 , V_13 ) ;
if ( ! V_15 ) {
V_4 -> V_18 -> V_38 = V_39 ;
F_17 ( V_2 , V_4 -> V_35 ) ;
F_18 ( V_4 -> V_35 ) ;
} else {
V_2 -> V_16 = NULL ;
F_19 ( V_13 ) ;
}
return V_15 ;
}
static int F_20 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_40 * V_19 ;
const T_1 * V_41 = NULL ;
int V_15 ;
F_15 ( V_4 ) ;
if ( ! V_4 -> V_18 )
return 0 ;
V_19 = & V_4 -> V_18 -> V_19 ;
switch ( V_4 -> V_18 -> V_38 ) {
case V_42 :
return F_11 ( V_4 ) ;
case V_43 :
F_21 ( ! V_2 -> V_36 -> V_44 ) ;
V_4 -> V_18 -> V_38 = V_45 ;
return F_22 ( V_2 , V_4 -> V_35 ,
V_19 -> V_20 , V_19 -> V_46 ,
V_19 -> V_47 ,
V_19 -> V_32 , V_19 -> V_33 ,
NULL , 0 ,
V_19 -> V_48 , V_19 -> V_49 ,
V_19 -> V_50 , false ) ;
case V_51 :
F_21 ( ! V_2 -> V_36 -> V_52 ) ;
V_4 -> V_18 -> V_38 = V_53 ;
if ( V_4 -> V_18 -> V_54 )
V_41 = V_4 -> V_18 -> V_41 ;
V_15 = F_23 ( V_2 , V_4 -> V_35 ,
V_19 -> V_20 , V_19 -> V_47 ,
V_41 ,
V_19 -> V_32 , V_19 -> V_33 ,
V_19 -> V_55 , V_19 -> V_56 ,
false , & V_19 -> V_57 ) ;
if ( V_15 )
F_24 ( V_2 , V_4 -> V_35 , V_19 -> V_47 ,
NULL , 0 ,
V_58 ,
false ) ;
return V_15 ;
case V_59 :
F_24 ( V_2 , V_4 -> V_35 , V_19 -> V_47 ,
NULL , 0 ,
V_58 , false ) ;
return - V_60 ;
default:
return 0 ;
}
}
void F_25 ( struct V_9 * V_10 )
{
struct V_1 * V_2 =
F_26 ( V_10 , struct V_1 , V_61 ) ;
struct V_3 * V_4 ;
T_1 V_62 [ V_63 ] , * V_47 = NULL ;
F_27 () ;
F_4 ( V_2 ) ;
F_2 ( & V_2 -> V_64 ) ;
F_3 (wdev, &rdev->netdev_list, list) {
F_5 ( V_4 ) ;
if ( ! F_28 ( V_4 -> V_35 ) ) {
F_6 ( V_4 ) ;
continue;
}
if ( V_4 -> V_7 != V_65 ) {
F_6 ( V_4 ) ;
continue;
}
if ( V_4 -> V_18 -> V_19 . V_47 ) {
memcpy ( V_62 , V_4 -> V_18 -> V_19 . V_47 , V_63 ) ;
V_47 = V_62 ;
}
if ( F_20 ( V_4 ) )
F_29 (
V_4 -> V_35 , V_47 ,
NULL , 0 , NULL , 0 ,
V_66 ,
false , NULL ) ;
F_6 ( V_4 ) ;
}
F_8 ( & V_2 -> V_64 ) ;
F_7 ( V_2 ) ;
F_30 () ;
}
static struct V_67 * F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_67 * V_68 ;
T_2 V_69 = V_70 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_18 -> V_19 . V_71 )
V_69 |= V_72 ;
V_68 = F_32 ( V_4 -> V_11 , V_4 -> V_18 -> V_19 . V_20 ,
V_4 -> V_18 -> V_19 . V_47 ,
V_4 -> V_18 -> V_19 . V_32 ,
V_4 -> V_18 -> V_19 . V_33 ,
V_70 | V_72 ,
V_69 ) ;
if ( ! V_68 )
return NULL ;
memcpy ( V_4 -> V_18 -> V_47 , V_68 -> V_47 , V_63 ) ;
V_4 -> V_18 -> V_19 . V_47 = V_4 -> V_18 -> V_47 ;
V_4 -> V_18 -> V_19 . V_20 = V_68 -> V_20 ;
V_4 -> V_18 -> V_38 = V_43 ;
F_33 ( & V_2 -> V_61 ) ;
return V_68 ;
}
static void F_34 ( struct V_73 * V_34 )
{
struct V_3 * V_4 = V_34 -> V_74 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_67 * V_68 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_65 )
return;
if ( ! V_4 -> V_18 )
return;
if ( V_4 -> V_18 -> V_38 != V_39 &&
V_4 -> V_18 -> V_38 != V_42 )
return;
V_68 = F_31 ( V_4 ) ;
if ( V_68 ) {
F_35 ( V_68 ) ;
} else {
if ( V_4 -> V_18 -> V_38 == V_42 )
F_33 ( & V_2 -> V_61 ) ;
else
F_29 (
V_4 -> V_35 ,
V_4 -> V_18 -> V_19 . V_47 ,
NULL , 0 , NULL , 0 ,
V_66 ,
false , NULL ) ;
}
}
void F_36 ( struct V_73 * V_34 )
{
struct V_3 * V_4 = V_34 -> V_74 ;
F_2 ( & F_12 ( V_4 -> V_11 ) -> V_64 ) ;
F_5 ( V_4 ) ;
F_34 ( V_34 ) ;
F_6 ( V_4 ) ;
F_8 ( & F_12 ( V_4 -> V_11 ) -> V_64 ) ;
}
void F_37 ( struct V_73 * V_34 ,
const T_1 * V_75 , T_3 V_76 )
{
struct V_3 * V_4 = V_34 -> V_74 ;
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
struct V_77 * V_78 = (struct V_77 * ) V_75 ;
T_2 V_79 = F_38 ( V_78 -> V_80 . V_44 . V_79 ) ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_65 )
return;
if ( F_39 ( ! V_4 -> V_18 ) )
return;
if ( V_79 == V_81 &&
V_4 -> V_18 -> V_82 &&
V_4 -> V_18 -> V_19 . V_46 != V_83 ) {
switch ( V_4 -> V_18 -> V_19 . V_46 ) {
case V_84 :
if ( V_4 -> V_85 )
V_4 -> V_18 -> V_19 . V_46 =
V_86 ;
else
V_4 -> V_18 -> V_19 . V_46 =
V_83 ;
break;
case V_86 :
V_4 -> V_18 -> V_19 . V_46 =
V_83 ;
break;
default:
V_4 -> V_18 -> V_19 . V_46 =
V_84 ;
break;
}
V_4 -> V_18 -> V_38 = V_43 ;
F_33 ( & V_2 -> V_61 ) ;
} else if ( V_79 != V_87 ) {
F_29 ( V_34 , V_78 -> V_47 , NULL , 0 , NULL , 0 ,
V_79 , false , NULL ) ;
} else if ( V_4 -> V_7 == V_65 &&
V_4 -> V_18 -> V_38 == V_45 ) {
V_4 -> V_18 -> V_38 = V_51 ;
F_33 ( & V_2 -> V_61 ) ;
}
}
bool F_40 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
if ( F_39 ( ! V_4 -> V_18 ) )
return false ;
if ( ! V_4 -> V_18 -> V_54 )
return false ;
V_4 -> V_18 -> V_54 = false ;
V_4 -> V_18 -> V_38 = V_51 ;
F_33 ( & V_2 -> V_61 ) ;
return true ;
}
void F_41 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
V_4 -> V_18 -> V_38 = V_59 ;
F_33 ( & V_2 -> V_61 ) ;
}
void F_29 ( struct V_73 * V_34 , const T_1 * V_47 ,
const T_1 * V_88 , T_3 V_89 ,
const T_1 * V_90 , T_3 V_91 ,
T_2 V_92 , bool V_93 ,
struct V_67 * V_68 )
{
struct V_3 * V_4 = V_34 -> V_74 ;
T_1 * V_94 ;
#ifdef F_42
union V_95 V_96 ;
#endif
F_15 ( V_4 ) ;
if ( F_39 ( V_4 -> V_97 != V_98 &&
V_4 -> V_97 != V_99 ) )
return;
if ( V_4 -> V_7 != V_65 )
return;
F_43 ( F_12 ( V_4 -> V_11 ) , V_34 ,
V_47 , V_88 , V_89 ,
V_90 , V_91 ,
V_92 , V_27 ) ;
#ifdef F_42
if ( V_93 ) {
if ( V_88 && V_92 == V_87 ) {
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_100 . V_101 = V_89 ;
F_44 ( V_34 , V_102 , & V_96 , V_88 ) ;
}
if ( V_90 && V_92 == V_87 ) {
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_100 . V_101 = V_91 ;
F_44 ( V_34 , V_103 , & V_96 , V_90 ) ;
}
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_104 . V_105 = V_106 ;
if ( V_47 && V_92 == V_87 ) {
memcpy ( V_96 . V_104 . V_107 , V_47 , V_63 ) ;
memcpy ( V_4 -> V_108 . V_41 , V_47 , V_63 ) ;
V_4 -> V_108 . V_54 = true ;
}
F_44 ( V_34 , V_109 , & V_96 , NULL ) ;
}
#endif
if ( V_4 -> V_110 ) {
F_45 ( V_4 -> V_110 ) ;
F_35 ( & V_4 -> V_110 -> V_111 ) ;
V_4 -> V_110 = NULL ;
}
if ( V_4 -> V_18 )
V_4 -> V_18 -> V_38 = V_112 ;
if ( V_92 != V_87 ) {
V_4 -> V_7 = V_8 ;
if ( V_4 -> V_18 )
F_19 ( V_4 -> V_18 -> V_55 ) ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
F_19 ( V_4 -> V_85 ) ;
V_4 -> V_85 = NULL ;
V_4 -> V_33 = 0 ;
return;
}
if ( ! V_68 )
V_68 = F_32 ( V_4 -> V_11 ,
V_4 -> V_18 ? V_4 -> V_18 -> V_19 . V_20 :
NULL ,
V_47 ,
V_4 -> V_32 , V_4 -> V_33 ,
V_70 ,
V_70 ) ;
if ( F_39 ( ! V_68 ) )
return;
F_46 ( F_47 ( V_68 ) ) ;
V_4 -> V_110 = F_47 ( V_68 ) ;
V_4 -> V_7 = V_113 ;
F_48 ( V_4 ) ;
V_94 = ( T_1 * ) F_49 ( V_68 , V_114 ) ;
if ( ! V_94 )
return;
F_50 ( V_4 -> V_11 ,
V_68 -> V_20 -> V_22 ,
V_94 + 2 ,
V_94 [ 1 ] ) ;
}
void F_51 ( struct V_73 * V_34 , const T_1 * V_47 ,
const T_1 * V_88 , T_3 V_89 ,
const T_1 * V_90 , T_3 V_91 ,
T_2 V_92 , T_4 V_115 )
{
struct V_3 * V_4 = V_34 -> V_74 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_116 * V_117 ;
unsigned long V_118 ;
F_52 ( V_4 -> V_7 != V_65 ) ;
V_117 = F_16 ( sizeof( * V_117 ) + V_89 + V_91 , V_115 ) ;
if ( ! V_117 )
return;
V_117 -> type = V_119 ;
if ( V_47 )
memcpy ( V_117 -> V_120 . V_47 , V_47 , V_63 ) ;
if ( V_89 ) {
V_117 -> V_120 . V_88 = ( ( T_1 * ) V_117 ) + sizeof( * V_117 ) ;
V_117 -> V_120 . V_89 = V_89 ;
memcpy ( ( void * ) V_117 -> V_120 . V_88 , V_88 , V_89 ) ;
}
if ( V_91 ) {
V_117 -> V_120 . V_90 = ( ( T_1 * ) V_117 ) + sizeof( * V_117 ) + V_89 ;
V_117 -> V_120 . V_91 = V_91 ;
memcpy ( ( void * ) V_117 -> V_120 . V_90 , V_90 , V_91 ) ;
}
V_117 -> V_120 . V_92 = V_92 ;
F_53 ( & V_4 -> V_121 , V_118 ) ;
F_54 ( & V_117 -> V_122 , & V_4 -> V_123 ) ;
F_55 ( & V_4 -> V_121 , V_118 ) ;
F_56 ( V_124 , & V_2 -> V_125 ) ;
}
void F_57 ( struct V_3 * V_4 ,
struct V_126 * V_20 ,
const T_1 * V_47 ,
const T_1 * V_88 , T_3 V_89 ,
const T_1 * V_90 , T_3 V_91 )
{
struct V_67 * V_68 ;
#ifdef F_42
union V_95 V_96 ;
#endif
F_15 ( V_4 ) ;
if ( F_39 ( V_4 -> V_97 != V_98 &&
V_4 -> V_97 != V_99 ) )
return;
if ( V_4 -> V_7 != V_113 )
return;
if ( F_39 ( ! V_4 -> V_110 ) ) {
return;
}
F_45 ( V_4 -> V_110 ) ;
F_35 ( & V_4 -> V_110 -> V_111 ) ;
V_4 -> V_110 = NULL ;
V_68 = F_32 ( V_4 -> V_11 , V_20 , V_47 ,
V_4 -> V_32 , V_4 -> V_33 ,
V_70 , V_70 ) ;
if ( F_39 ( ! V_68 ) )
return;
F_46 ( F_47 ( V_68 ) ) ;
V_4 -> V_110 = F_47 ( V_68 ) ;
F_58 ( F_12 ( V_4 -> V_11 ) , V_4 -> V_35 , V_47 ,
V_88 , V_89 , V_90 , V_91 ,
V_27 ) ;
#ifdef F_42
if ( V_88 ) {
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_100 . V_101 = V_89 ;
F_44 ( V_4 -> V_35 , V_102 ,
& V_96 , V_88 ) ;
}
if ( V_90 ) {
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_100 . V_101 = V_91 ;
F_44 ( V_4 -> V_35 , V_103 ,
& V_96 , V_90 ) ;
}
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_104 . V_105 = V_106 ;
memcpy ( V_96 . V_104 . V_107 , V_47 , V_63 ) ;
memcpy ( V_4 -> V_108 . V_41 , V_47 , V_63 ) ;
V_4 -> V_108 . V_54 = true ;
F_44 ( V_4 -> V_35 , V_109 , & V_96 , NULL ) ;
#endif
}
void F_59 ( struct V_73 * V_34 ,
struct V_126 * V_20 ,
const T_1 * V_47 ,
const T_1 * V_88 , T_3 V_89 ,
const T_1 * V_90 , T_3 V_91 , T_4 V_115 )
{
struct V_3 * V_4 = V_34 -> V_74 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_116 * V_117 ;
unsigned long V_118 ;
F_52 ( V_4 -> V_7 != V_113 ) ;
V_117 = F_16 ( sizeof( * V_117 ) + V_89 + V_91 , V_115 ) ;
if ( ! V_117 )
return;
V_117 -> type = V_127 ;
V_117 -> V_128 . V_20 = V_20 ;
memcpy ( V_117 -> V_128 . V_47 , V_47 , V_63 ) ;
V_117 -> V_128 . V_88 = ( ( T_1 * ) V_117 ) + sizeof( * V_117 ) ;
V_117 -> V_128 . V_89 = V_89 ;
memcpy ( ( void * ) V_117 -> V_128 . V_88 , V_88 , V_89 ) ;
V_117 -> V_128 . V_90 = ( ( T_1 * ) V_117 ) + sizeof( * V_117 ) + V_89 ;
V_117 -> V_128 . V_91 = V_91 ;
memcpy ( ( void * ) V_117 -> V_128 . V_90 , V_90 , V_91 ) ;
F_53 ( & V_4 -> V_121 , V_118 ) ;
F_54 ( & V_117 -> V_122 , & V_4 -> V_123 ) ;
F_55 ( & V_4 -> V_121 , V_118 ) ;
F_56 ( V_124 , & V_2 -> V_125 ) ;
}
void F_60 ( struct V_73 * V_34 , const T_1 * V_55 ,
T_3 V_56 , T_2 V_129 , bool V_130 )
{
struct V_3 * V_4 = V_34 -> V_74 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
int V_29 ;
#ifdef F_42
union V_95 V_96 ;
#endif
F_15 ( V_4 ) ;
if ( F_39 ( V_4 -> V_97 != V_98 &&
V_4 -> V_97 != V_99 ) )
return;
if ( V_4 -> V_7 != V_113 )
return;
if ( V_4 -> V_110 ) {
F_45 ( V_4 -> V_110 ) ;
F_35 ( & V_4 -> V_110 -> V_111 ) ;
}
V_4 -> V_110 = NULL ;
V_4 -> V_7 = V_8 ;
V_4 -> V_33 = 0 ;
if ( V_4 -> V_18 ) {
const T_1 * V_47 ;
int V_131 ;
F_19 ( V_4 -> V_18 -> V_55 ) ;
V_4 -> V_18 -> V_55 = NULL ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
for ( V_29 = 0 ; V_29 < V_132 ; V_29 ++ ) {
if ( ! V_4 -> V_133 [ V_29 ] )
continue;
V_47 = V_4 -> V_133 [ V_29 ] -> V_111 . V_47 ;
V_131 = F_24 ( V_2 , V_34 , V_47 , NULL , 0 ,
V_58 ,
false ) ;
F_61 ( V_131 , L_1 , V_131 ) ;
}
}
F_62 ( V_2 , V_34 , V_129 , V_55 , V_56 , V_130 ) ;
if ( V_2 -> V_36 -> V_134 )
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
V_2 -> V_36 -> V_134 ( V_4 -> V_11 , V_34 , V_29 , false , NULL ) ;
#ifdef F_42
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_104 . V_105 = V_106 ;
F_44 ( V_34 , V_109 , & V_96 , NULL ) ;
V_4 -> V_108 . V_135 . V_33 = 0 ;
#endif
F_33 ( & V_136 ) ;
}
void F_63 ( struct V_73 * V_34 , T_2 V_129 ,
T_1 * V_55 , T_3 V_56 , T_4 V_115 )
{
struct V_3 * V_4 = V_34 -> V_74 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_116 * V_117 ;
unsigned long V_118 ;
F_52 ( V_4 -> V_7 != V_113 ) ;
V_117 = F_16 ( sizeof( * V_117 ) + V_56 , V_115 ) ;
if ( ! V_117 )
return;
V_117 -> type = V_137 ;
V_117 -> V_138 . V_55 = ( ( T_1 * ) V_117 ) + sizeof( * V_117 ) ;
V_117 -> V_138 . V_56 = V_56 ;
memcpy ( ( void * ) V_117 -> V_138 . V_55 , V_55 , V_56 ) ;
V_117 -> V_138 . V_129 = V_129 ;
F_53 ( & V_4 -> V_121 , V_118 ) ;
F_54 ( & V_117 -> V_122 , & V_4 -> V_123 ) ;
F_55 ( & V_4 -> V_121 , V_118 ) ;
F_56 ( V_124 , & V_2 -> V_125 ) ;
}
int F_64 ( struct V_1 * V_2 ,
struct V_73 * V_34 ,
struct V_40 * V_135 ,
struct V_139 * V_140 ,
const T_1 * V_41 )
{
struct V_3 * V_4 = V_34 -> V_74 ;
struct V_67 * V_68 = NULL ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_8 )
return - V_141 ;
if ( F_39 ( V_4 -> V_85 ) ) {
F_19 ( V_4 -> V_85 ) ;
V_4 -> V_85 = NULL ;
}
if ( V_140 && V_140 -> V_142 >= 0 ) {
int V_143 ;
T_5 V_144 ;
V_143 = V_140 -> V_142 ;
V_144 = V_140 -> V_19 [ V_143 ] . V_144 ;
if ( V_144 == V_145 ||
V_144 == V_146 ) {
V_135 -> V_50 = V_143 ;
V_135 -> V_48 = V_140 -> V_19 [ V_143 ] . V_48 ;
V_135 -> V_49 = V_140 -> V_19 [ V_143 ] . V_49 ;
if ( V_135 -> V_57 . V_147 == 0 )
V_135 -> V_57 . V_147 = V_144 ;
if ( V_135 -> V_57 . V_148 == 0 ) {
V_135 -> V_57 . V_148 = 1 ;
V_135 -> V_57 . V_149 [ 0 ] = V_144 ;
}
}
}
if ( ! V_2 -> V_36 -> V_135 ) {
if ( ! V_2 -> V_36 -> V_44 || ! V_2 -> V_36 -> V_52 )
return - V_150 ;
if ( F_39 ( V_4 -> V_18 ) )
return - V_151 ;
V_4 -> V_18 = F_16 ( sizeof( * V_4 -> V_18 ) , V_27 ) ;
if ( ! V_4 -> V_18 )
return - V_28 ;
memcpy ( & V_4 -> V_18 -> V_19 , V_135 , sizeof( * V_135 ) ) ;
if ( V_135 -> V_47 ) {
V_4 -> V_18 -> V_19 . V_47 = V_4 -> V_18 -> V_47 ;
memcpy ( V_4 -> V_18 -> V_47 , V_135 -> V_47 , V_63 ) ;
}
if ( V_135 -> V_55 ) {
V_4 -> V_18 -> V_55 = F_65 ( V_135 -> V_55 , V_135 -> V_56 ,
V_27 ) ;
V_4 -> V_18 -> V_19 . V_55 = V_4 -> V_18 -> V_55 ;
if ( ! V_4 -> V_18 -> V_55 ) {
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
return - V_28 ;
}
}
if ( V_135 -> V_46 == V_152 ) {
V_4 -> V_18 -> V_82 = true ;
V_4 -> V_18 -> V_19 . V_46 =
V_84 ;
} else {
V_4 -> V_18 -> V_82 = false ;
}
memcpy ( V_4 -> V_32 , V_135 -> V_32 , V_135 -> V_33 ) ;
V_4 -> V_33 = V_135 -> V_33 ;
V_4 -> V_18 -> V_19 . V_32 = V_4 -> V_32 ;
V_4 -> V_18 -> V_19 . V_33 = V_135 -> V_33 ;
V_68 = F_31 ( V_4 ) ;
V_4 -> V_7 = V_65 ;
V_4 -> V_85 = V_140 ;
if ( V_41 ) {
memcpy ( V_4 -> V_18 -> V_41 , V_41 , V_63 ) ;
V_4 -> V_18 -> V_54 = true ;
}
if ( V_68 ) {
V_4 -> V_18 -> V_38 = V_43 ;
V_15 = F_20 ( V_4 ) ;
F_35 ( V_68 ) ;
} else {
V_15 = F_11 ( V_4 ) ;
if ( V_15 == - V_17 ) {
V_15 = 0 ;
V_4 -> V_18 -> V_38 = V_42 ;
}
}
if ( V_15 ) {
F_19 ( V_4 -> V_18 -> V_55 ) ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
V_4 -> V_7 = V_8 ;
V_4 -> V_85 = NULL ;
V_4 -> V_33 = 0 ;
}
return V_15 ;
} else {
V_4 -> V_7 = V_65 ;
V_4 -> V_85 = V_140 ;
V_15 = V_2 -> V_36 -> V_135 ( & V_2 -> V_11 , V_34 , V_135 ) ;
if ( V_15 ) {
V_4 -> V_85 = NULL ;
V_4 -> V_7 = V_8 ;
return V_15 ;
}
memcpy ( V_4 -> V_32 , V_135 -> V_32 , V_135 -> V_33 ) ;
V_4 -> V_33 = V_135 -> V_33 ;
return 0 ;
}
}
int F_66 ( struct V_1 * V_2 ,
struct V_73 * V_34 ,
struct V_40 * V_135 ,
struct V_139 * V_140 )
{
int V_15 ;
F_2 ( & V_2 -> V_64 ) ;
F_5 ( V_34 -> V_74 ) ;
V_15 = F_64 ( V_2 , V_34 , V_135 , V_140 , NULL ) ;
F_6 ( V_34 -> V_74 ) ;
F_8 ( & V_2 -> V_64 ) ;
return V_15 ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_73 * V_34 , T_2 V_129 , bool V_93 )
{
struct V_3 * V_4 = V_34 -> V_74 ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 == V_8 )
return - V_60 ;
F_19 ( V_4 -> V_85 ) ;
V_4 -> V_85 = NULL ;
if ( ! V_2 -> V_36 -> V_153 ) {
if ( ! V_2 -> V_36 -> V_154 )
return - V_150 ;
if ( ! V_4 -> V_18 ) {
F_68 ( V_2 , V_34 ) ;
return 0 ;
}
if ( V_4 -> V_7 == V_65 &&
( V_4 -> V_18 -> V_38 == V_39 ||
V_4 -> V_18 -> V_38 == V_42 ) ) {
V_4 -> V_7 = V_8 ;
F_19 ( V_4 -> V_18 -> V_55 ) ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
V_4 -> V_33 = 0 ;
return 0 ;
}
V_15 = F_24 ( V_2 , V_34 ,
V_4 -> V_18 -> V_19 . V_47 ,
NULL , 0 , V_129 , false ) ;
if ( V_15 )
return V_15 ;
} else {
V_15 = V_2 -> V_36 -> V_153 ( & V_2 -> V_11 , V_34 , V_129 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_4 -> V_7 == V_113 )
F_60 ( V_34 , NULL , 0 , 0 , false ) ;
else if ( V_4 -> V_7 == V_65 )
F_29 ( V_34 , NULL , NULL , 0 , NULL , 0 ,
V_66 ,
V_93 , NULL ) ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_73 * V_34 ,
T_2 V_129 , bool V_93 )
{
int V_15 ;
F_5 ( V_34 -> V_74 ) ;
V_15 = F_67 ( V_2 , V_34 , V_129 , V_93 ) ;
F_6 ( V_34 -> V_74 ) ;
return V_15 ;
}
void F_70 ( struct V_73 * V_34 , int V_143 )
{
struct V_3 * V_4 = V_34 -> V_74 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
T_1 V_47 [ V_63 ] ;
F_15 ( V_4 ) ;
if ( ! V_4 -> V_18 )
return;
if ( V_4 -> V_18 -> V_38 == V_112 )
return;
if ( ! V_4 -> V_133 [ V_143 ] )
return;
memcpy ( V_47 , V_4 -> V_133 [ V_143 ] -> V_111 . V_47 , V_63 ) ;
if ( F_24 ( V_2 , V_34 , V_47 ,
NULL , 0 , V_58 ,
false ) ) {
F_45 ( V_4 -> V_133 [ V_143 ] ) ;
F_35 ( & V_4 -> V_133 [ V_143 ] -> V_111 ) ;
V_4 -> V_133 [ V_143 ] = NULL ;
}
}
