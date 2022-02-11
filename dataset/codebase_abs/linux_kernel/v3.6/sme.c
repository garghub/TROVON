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
V_2 -> V_16 = V_13 ;
V_15 = V_2 -> V_40 -> V_41 ( V_4 -> V_11 , V_13 ) ;
if ( ! V_15 ) {
V_4 -> V_18 -> V_42 = V_43 ;
F_17 ( V_2 , V_4 ) ;
F_18 ( V_4 -> V_44 ) ;
} else {
V_2 -> V_16 = NULL ;
F_19 ( V_13 ) ;
}
return V_15 ;
}
static int F_20 ( struct V_3 * V_4 )
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
F_21 ( ! V_2 -> V_40 -> V_49 ) ;
V_4 -> V_18 -> V_42 = V_50 ;
return F_22 ( V_2 , V_4 -> V_44 ,
V_19 -> V_20 , V_19 -> V_51 ,
V_19 -> V_52 ,
V_19 -> V_38 , V_19 -> V_39 ,
NULL , 0 ,
V_19 -> V_53 , V_19 -> V_54 ,
V_19 -> V_55 ) ;
case V_56 :
F_21 ( ! V_2 -> V_40 -> V_57 ) ;
V_4 -> V_18 -> V_42 = V_58 ;
if ( V_4 -> V_18 -> V_59 )
V_46 = V_4 -> V_18 -> V_46 ;
V_15 = F_23 ( V_2 , V_4 -> V_44 ,
V_19 -> V_20 , V_19 -> V_52 ,
V_46 ,
V_19 -> V_38 , V_19 -> V_39 ,
V_19 -> V_60 , V_19 -> V_61 ,
false , & V_19 -> V_62 ,
V_19 -> V_33 , & V_19 -> V_63 ,
& V_19 -> V_64 ) ;
if ( V_15 )
F_24 ( V_2 , V_4 -> V_44 , V_19 -> V_52 ,
NULL , 0 ,
V_65 ,
false ) ;
return V_15 ;
case V_66 :
F_24 ( V_2 , V_4 -> V_44 , V_19 -> V_52 ,
NULL , 0 ,
V_65 , false ) ;
return - V_67 ;
default:
return 0 ;
}
}
void F_25 ( struct V_9 * V_10 )
{
struct V_1 * V_2 =
F_26 ( V_10 , struct V_1 , V_68 ) ;
struct V_3 * V_4 ;
T_1 V_69 [ V_70 ] , * V_52 = NULL ;
F_27 () ;
F_4 ( V_2 ) ;
F_2 ( & V_2 -> V_71 ) ;
F_3 (wdev, &rdev->wdev_list, list) {
F_5 ( V_4 ) ;
if ( ! F_28 ( V_4 -> V_44 ) ) {
F_6 ( V_4 ) ;
continue;
}
if ( V_4 -> V_7 != V_72 ) {
F_6 ( V_4 ) ;
continue;
}
if ( V_4 -> V_18 -> V_19 . V_52 ) {
memcpy ( V_69 , V_4 -> V_18 -> V_19 . V_52 , V_70 ) ;
V_52 = V_69 ;
}
if ( F_20 ( V_4 ) )
F_29 (
V_4 -> V_44 , V_52 ,
NULL , 0 , NULL , 0 ,
V_73 ,
false , NULL ) ;
F_6 ( V_4 ) ;
}
F_8 ( & V_2 -> V_71 ) ;
F_7 ( V_2 ) ;
F_30 () ;
}
static struct V_74 * F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_74 * V_75 ;
T_2 V_76 = V_77 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_18 -> V_19 . V_78 )
V_76 |= V_79 ;
V_75 = F_32 ( V_4 -> V_11 , V_4 -> V_18 -> V_19 . V_20 ,
V_4 -> V_18 -> V_19 . V_52 ,
V_4 -> V_18 -> V_19 . V_38 ,
V_4 -> V_18 -> V_19 . V_39 ,
V_77 | V_79 ,
V_76 ) ;
if ( ! V_75 )
return NULL ;
memcpy ( V_4 -> V_18 -> V_52 , V_75 -> V_52 , V_70 ) ;
V_4 -> V_18 -> V_19 . V_52 = V_4 -> V_18 -> V_52 ;
V_4 -> V_18 -> V_19 . V_20 = V_75 -> V_20 ;
V_4 -> V_18 -> V_42 = V_48 ;
F_33 ( & V_2 -> V_68 ) ;
return V_75 ;
}
static void F_34 ( struct V_80 * V_81 )
{
struct V_3 * V_4 = V_81 -> V_82 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_74 * V_75 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_72 )
return;
if ( ! V_4 -> V_18 )
return;
if ( V_4 -> V_18 -> V_42 != V_43 &&
V_4 -> V_18 -> V_42 != V_47 )
return;
V_75 = F_31 ( V_4 ) ;
if ( V_75 ) {
F_35 ( V_75 ) ;
} else {
if ( V_4 -> V_18 -> V_42 == V_47 )
F_33 ( & V_2 -> V_68 ) ;
else
F_29 (
V_4 -> V_44 ,
V_4 -> V_18 -> V_19 . V_52 ,
NULL , 0 , NULL , 0 ,
V_73 ,
false , NULL ) ;
}
}
void F_36 ( struct V_80 * V_81 )
{
struct V_3 * V_4 = V_81 -> V_82 ;
F_2 ( & F_12 ( V_4 -> V_11 ) -> V_71 ) ;
F_5 ( V_4 ) ;
F_34 ( V_81 ) ;
F_6 ( V_4 ) ;
F_8 ( & F_12 ( V_4 -> V_11 ) -> V_71 ) ;
}
void F_37 ( struct V_80 * V_81 ,
const T_1 * V_83 , T_3 V_84 )
{
struct V_3 * V_4 = V_81 -> V_82 ;
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
struct V_85 * V_86 = (struct V_85 * ) V_83 ;
T_2 V_87 = F_38 ( V_86 -> V_88 . V_49 . V_87 ) ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_72 )
return;
if ( F_39 ( ! V_4 -> V_18 ) )
return;
if ( V_87 == V_89 &&
V_4 -> V_18 -> V_90 &&
V_4 -> V_18 -> V_19 . V_51 != V_91 ) {
switch ( V_4 -> V_18 -> V_19 . V_51 ) {
case V_92 :
if ( V_4 -> V_93 )
V_4 -> V_18 -> V_19 . V_51 =
V_94 ;
else
V_4 -> V_18 -> V_19 . V_51 =
V_91 ;
break;
case V_94 :
V_4 -> V_18 -> V_19 . V_51 =
V_91 ;
break;
default:
V_4 -> V_18 -> V_19 . V_51 =
V_92 ;
break;
}
V_4 -> V_18 -> V_42 = V_48 ;
F_33 ( & V_2 -> V_68 ) ;
} else if ( V_87 != V_95 ) {
F_29 ( V_81 , V_86 -> V_52 , NULL , 0 , NULL , 0 ,
V_87 , false , NULL ) ;
} else if ( V_4 -> V_7 == V_72 &&
V_4 -> V_18 -> V_42 == V_50 ) {
V_4 -> V_18 -> V_42 = V_56 ;
F_33 ( & V_2 -> V_68 ) ;
}
}
bool F_40 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
if ( F_39 ( ! V_4 -> V_18 ) )
return false ;
if ( ! V_4 -> V_18 -> V_59 )
return false ;
V_4 -> V_18 -> V_59 = false ;
V_4 -> V_18 -> V_42 = V_56 ;
F_33 ( & V_2 -> V_68 ) ;
return true ;
}
void F_41 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
V_4 -> V_18 -> V_42 = V_66 ;
F_33 ( & V_2 -> V_68 ) ;
}
void F_29 ( struct V_80 * V_81 , const T_1 * V_52 ,
const T_1 * V_96 , T_3 V_97 ,
const T_1 * V_98 , T_3 V_99 ,
T_2 V_100 , bool V_101 ,
struct V_74 * V_75 )
{
struct V_3 * V_4 = V_81 -> V_82 ;
T_1 * V_102 ;
#ifdef F_42
union V_103 V_104 ;
#endif
F_15 ( V_4 ) ;
if ( F_39 ( V_4 -> V_105 != V_106 &&
V_4 -> V_105 != V_107 ) )
return;
if ( V_4 -> V_7 != V_72 )
return;
F_43 ( F_12 ( V_4 -> V_11 ) , V_81 ,
V_52 , V_96 , V_97 ,
V_98 , V_99 ,
V_100 , V_27 ) ;
#ifdef F_42
if ( V_101 ) {
if ( V_96 && V_100 == V_95 ) {
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_108 . V_109 = V_97 ;
F_44 ( V_81 , V_110 , & V_104 , V_96 ) ;
}
if ( V_98 && V_100 == V_95 ) {
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_108 . V_109 = V_99 ;
F_44 ( V_81 , V_111 , & V_104 , V_98 ) ;
}
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_112 . V_113 = V_114 ;
if ( V_52 && V_100 == V_95 ) {
memcpy ( V_104 . V_112 . V_115 , V_52 , V_70 ) ;
memcpy ( V_4 -> V_116 . V_46 , V_52 , V_70 ) ;
V_4 -> V_116 . V_59 = true ;
}
F_44 ( V_81 , V_117 , & V_104 , NULL ) ;
}
#endif
if ( V_4 -> V_118 ) {
F_45 ( V_4 -> V_118 ) ;
F_35 ( & V_4 -> V_118 -> V_119 ) ;
V_4 -> V_118 = NULL ;
}
if ( V_4 -> V_18 )
V_4 -> V_18 -> V_42 = V_120 ;
if ( V_100 != V_95 ) {
V_4 -> V_7 = V_8 ;
if ( V_4 -> V_18 )
F_19 ( V_4 -> V_18 -> V_60 ) ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
F_19 ( V_4 -> V_93 ) ;
V_4 -> V_93 = NULL ;
V_4 -> V_39 = 0 ;
F_35 ( V_75 ) ;
return;
}
if ( ! V_75 )
V_75 = F_32 ( V_4 -> V_11 ,
V_4 -> V_18 ? V_4 -> V_18 -> V_19 . V_20 :
NULL ,
V_52 ,
V_4 -> V_38 , V_4 -> V_39 ,
V_77 ,
V_77 ) ;
if ( F_39 ( ! V_75 ) )
return;
F_46 ( F_47 ( V_75 ) ) ;
V_4 -> V_118 = F_47 ( V_75 ) ;
V_4 -> V_7 = V_121 ;
F_48 ( V_4 ) ;
V_102 = ( T_1 * ) F_49 ( V_75 , V_122 ) ;
if ( ! V_102 )
return;
F_50 ( V_4 -> V_11 ,
V_75 -> V_20 -> V_22 ,
V_102 + 2 ,
V_102 [ 1 ] ) ;
}
void F_51 ( struct V_80 * V_81 , const T_1 * V_52 ,
const T_1 * V_96 , T_3 V_97 ,
const T_1 * V_98 , T_3 V_99 ,
T_2 V_100 , T_4 V_123 )
{
struct V_3 * V_4 = V_81 -> V_82 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_124 * V_125 ;
unsigned long V_33 ;
F_52 ( V_4 -> V_7 != V_72 ) ;
V_125 = F_16 ( sizeof( * V_125 ) + V_97 + V_99 , V_123 ) ;
if ( ! V_125 )
return;
V_125 -> type = V_126 ;
if ( V_52 )
memcpy ( V_125 -> V_127 . V_52 , V_52 , V_70 ) ;
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
struct V_74 * V_75 ,
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
F_46 ( F_47 ( V_75 ) ) ;
V_4 -> V_118 = F_47 ( V_75 ) ;
F_58 ( F_12 ( V_4 -> V_11 ) , V_4 -> V_44 , V_75 -> V_52 ,
V_96 , V_97 , V_98 , V_99 ,
V_27 ) ;
#ifdef F_42
if ( V_96 ) {
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_108 . V_109 = V_97 ;
F_44 ( V_4 -> V_44 , V_110 ,
& V_104 , V_96 ) ;
}
if ( V_98 ) {
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_108 . V_109 = V_99 ;
F_44 ( V_4 -> V_44 , V_111 ,
& V_104 , V_98 ) ;
}
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_112 . V_113 = V_114 ;
memcpy ( V_104 . V_112 . V_115 , V_75 -> V_52 , V_70 ) ;
memcpy ( V_4 -> V_116 . V_46 , V_75 -> V_52 , V_70 ) ;
V_4 -> V_116 . V_59 = true ;
F_44 ( V_4 -> V_44 , V_117 , & V_104 , NULL ) ;
#endif
return;
V_133:
F_35 ( V_75 ) ;
}
void F_59 ( struct V_80 * V_81 ,
struct V_32 * V_20 ,
const T_1 * V_52 ,
const T_1 * V_96 , T_3 V_97 ,
const T_1 * V_98 , T_3 V_99 , T_4 V_123 )
{
struct V_3 * V_4 = V_81 -> V_82 ;
struct V_74 * V_75 ;
F_52 ( V_4 -> V_7 != V_121 ) ;
V_75 = F_32 ( V_4 -> V_11 , V_20 , V_52 , V_4 -> V_38 ,
V_4 -> V_39 , V_77 ,
V_77 ) ;
if ( F_39 ( ! V_75 ) )
return;
F_60 ( V_81 , V_75 , V_96 , V_97 , V_98 ,
V_99 , V_123 ) ;
}
void F_60 ( struct V_80 * V_81 ,
struct V_74 * V_75 , const T_1 * V_96 ,
T_3 V_97 , const T_1 * V_98 ,
T_3 V_99 , T_4 V_123 )
{
struct V_3 * V_4 = V_81 -> V_82 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_124 * V_125 ;
unsigned long V_33 ;
F_52 ( V_4 -> V_7 != V_121 ) ;
if ( F_39 ( ! V_75 ) )
return;
V_125 = F_16 ( sizeof( * V_125 ) + V_97 + V_99 , V_123 ) ;
if ( ! V_125 ) {
F_35 ( V_75 ) ;
return;
}
V_125 -> type = V_134 ;
V_125 -> V_135 . V_96 = ( ( T_1 * ) V_125 ) + sizeof( * V_125 ) ;
V_125 -> V_135 . V_97 = V_97 ;
memcpy ( ( void * ) V_125 -> V_135 . V_96 , V_96 , V_97 ) ;
V_125 -> V_135 . V_98 = ( ( T_1 * ) V_125 ) + sizeof( * V_125 ) + V_97 ;
V_125 -> V_135 . V_99 = V_99 ;
memcpy ( ( void * ) V_125 -> V_135 . V_98 , V_98 , V_99 ) ;
V_125 -> V_135 . V_75 = V_75 ;
F_53 ( & V_4 -> V_128 , V_33 ) ;
F_54 ( & V_125 -> V_129 , & V_4 -> V_130 ) ;
F_55 ( & V_4 -> V_128 , V_33 ) ;
F_56 ( V_131 , & V_2 -> V_132 ) ;
}
void F_61 ( struct V_80 * V_81 , const T_1 * V_60 ,
T_3 V_61 , T_2 V_136 , bool V_137 )
{
struct V_3 * V_4 = V_81 -> V_82 ;
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
F_19 ( V_4 -> V_18 -> V_60 ) ;
V_4 -> V_18 -> V_60 = NULL ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
}
F_62 ( V_2 , V_81 , V_136 , V_60 , V_61 , V_137 ) ;
if ( V_2 -> V_40 -> V_138 )
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
V_2 -> V_40 -> V_138 ( V_4 -> V_11 , V_81 , V_29 , false , NULL ) ;
#ifdef F_42
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_112 . V_113 = V_114 ;
F_44 ( V_81 , V_117 , & V_104 , NULL ) ;
V_4 -> V_116 . V_139 . V_39 = 0 ;
#endif
F_33 ( & V_140 ) ;
}
void F_63 ( struct V_80 * V_81 , T_2 V_136 ,
T_1 * V_60 , T_3 V_61 , T_4 V_123 )
{
struct V_3 * V_4 = V_81 -> V_82 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
struct V_124 * V_125 ;
unsigned long V_33 ;
F_52 ( V_4 -> V_7 != V_121 ) ;
V_125 = F_16 ( sizeof( * V_125 ) + V_61 , V_123 ) ;
if ( ! V_125 )
return;
V_125 -> type = V_141 ;
V_125 -> V_142 . V_60 = ( ( T_1 * ) V_125 ) + sizeof( * V_125 ) ;
V_125 -> V_142 . V_61 = V_61 ;
memcpy ( ( void * ) V_125 -> V_142 . V_60 , V_60 , V_61 ) ;
V_125 -> V_142 . V_136 = V_136 ;
F_53 ( & V_4 -> V_128 , V_33 ) ;
F_54 ( & V_125 -> V_129 , & V_4 -> V_130 ) ;
F_55 ( & V_4 -> V_128 , V_33 ) ;
F_56 ( V_131 , & V_2 -> V_132 ) ;
}
int F_64 ( struct V_1 * V_2 ,
struct V_80 * V_81 ,
struct V_45 * V_139 ,
struct V_143 * V_144 ,
const T_1 * V_46 )
{
struct V_3 * V_4 = V_81 -> V_82 ;
struct V_74 * V_75 = NULL ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 != V_8 )
return - V_145 ;
if ( F_39 ( V_4 -> V_93 ) ) {
F_19 ( V_4 -> V_93 ) ;
V_4 -> V_93 = NULL ;
}
F_65 ( & V_139 -> V_64 ,
V_2 -> V_11 . V_146 ) ;
if ( V_144 && V_144 -> V_147 >= 0 ) {
int V_148 ;
T_5 V_149 ;
V_148 = V_144 -> V_147 ;
V_149 = V_144 -> V_19 [ V_148 ] . V_149 ;
if ( V_149 == V_150 ||
V_149 == V_151 ) {
V_139 -> V_55 = V_148 ;
V_139 -> V_53 = V_144 -> V_19 [ V_148 ] . V_53 ;
V_139 -> V_54 = V_144 -> V_19 [ V_148 ] . V_54 ;
if ( V_139 -> V_62 . V_152 == 0 )
V_139 -> V_62 . V_152 = V_149 ;
if ( V_139 -> V_62 . V_153 == 0 ) {
V_139 -> V_62 . V_153 = 1 ;
V_139 -> V_62 . V_154 [ 0 ] = V_149 ;
}
}
}
if ( ! V_2 -> V_40 -> V_139 ) {
if ( ! V_2 -> V_40 -> V_49 || ! V_2 -> V_40 -> V_57 )
return - V_155 ;
if ( F_39 ( V_4 -> V_18 ) )
return - V_156 ;
V_4 -> V_18 = F_16 ( sizeof( * V_4 -> V_18 ) , V_27 ) ;
if ( ! V_4 -> V_18 )
return - V_28 ;
memcpy ( & V_4 -> V_18 -> V_19 , V_139 , sizeof( * V_139 ) ) ;
if ( V_139 -> V_52 ) {
V_4 -> V_18 -> V_19 . V_52 = V_4 -> V_18 -> V_52 ;
memcpy ( V_4 -> V_18 -> V_52 , V_139 -> V_52 , V_70 ) ;
}
if ( V_139 -> V_60 ) {
V_4 -> V_18 -> V_60 = F_66 ( V_139 -> V_60 , V_139 -> V_61 ,
V_27 ) ;
V_4 -> V_18 -> V_19 . V_60 = V_4 -> V_18 -> V_60 ;
if ( ! V_4 -> V_18 -> V_60 ) {
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
return - V_28 ;
}
}
if ( V_139 -> V_51 == V_157 ) {
V_4 -> V_18 -> V_90 = true ;
V_4 -> V_18 -> V_19 . V_51 =
V_92 ;
} else {
V_4 -> V_18 -> V_90 = false ;
}
memcpy ( V_4 -> V_38 , V_139 -> V_38 , V_139 -> V_39 ) ;
V_4 -> V_39 = V_139 -> V_39 ;
V_4 -> V_18 -> V_19 . V_38 = V_4 -> V_38 ;
V_4 -> V_18 -> V_19 . V_39 = V_139 -> V_39 ;
V_75 = F_31 ( V_4 ) ;
V_4 -> V_7 = V_72 ;
V_4 -> V_93 = V_144 ;
if ( V_46 ) {
memcpy ( V_4 -> V_18 -> V_46 , V_46 , V_70 ) ;
V_4 -> V_18 -> V_59 = true ;
}
if ( V_75 ) {
V_4 -> V_18 -> V_42 = V_48 ;
V_15 = F_20 ( V_4 ) ;
F_35 ( V_75 ) ;
} else {
V_15 = F_11 ( V_4 ) ;
if ( V_15 == - V_17 ) {
V_15 = 0 ;
V_4 -> V_18 -> V_42 = V_47 ;
}
}
if ( V_15 ) {
F_19 ( V_4 -> V_18 -> V_60 ) ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
V_4 -> V_7 = V_8 ;
V_4 -> V_93 = NULL ;
V_4 -> V_39 = 0 ;
}
return V_15 ;
} else {
V_4 -> V_7 = V_72 ;
V_4 -> V_93 = V_144 ;
V_15 = V_2 -> V_40 -> V_139 ( & V_2 -> V_11 , V_81 , V_139 ) ;
if ( V_15 ) {
V_4 -> V_93 = NULL ;
V_4 -> V_7 = V_8 ;
return V_15 ;
}
memcpy ( V_4 -> V_38 , V_139 -> V_38 , V_139 -> V_39 ) ;
V_4 -> V_39 = V_139 -> V_39 ;
return 0 ;
}
}
int F_67 ( struct V_1 * V_2 ,
struct V_80 * V_81 ,
struct V_45 * V_139 ,
struct V_143 * V_144 )
{
int V_15 ;
F_2 ( & V_2 -> V_71 ) ;
F_5 ( V_81 -> V_82 ) ;
V_15 = F_64 ( V_2 , V_81 , V_139 , V_144 , NULL ) ;
F_6 ( V_81 -> V_82 ) ;
F_8 ( & V_2 -> V_71 ) ;
return V_15 ;
}
int F_68 ( struct V_1 * V_2 ,
struct V_80 * V_81 , T_2 V_136 , bool V_101 )
{
struct V_3 * V_4 = V_81 -> V_82 ;
int V_15 ;
F_15 ( V_4 ) ;
if ( V_4 -> V_7 == V_8 )
return - V_67 ;
F_19 ( V_4 -> V_93 ) ;
V_4 -> V_93 = NULL ;
if ( ! V_2 -> V_40 -> V_158 ) {
if ( ! V_2 -> V_40 -> V_159 )
return - V_155 ;
if ( ! V_4 -> V_18 ) {
F_69 ( V_2 , V_81 ) ;
return 0 ;
}
if ( V_4 -> V_7 == V_72 &&
( V_4 -> V_18 -> V_42 == V_43 ||
V_4 -> V_18 -> V_42 == V_47 ) ) {
V_4 -> V_7 = V_8 ;
F_19 ( V_4 -> V_18 -> V_60 ) ;
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
V_4 -> V_39 = 0 ;
return 0 ;
}
V_15 = F_24 ( V_2 , V_81 ,
V_4 -> V_18 -> V_19 . V_52 ,
NULL , 0 , V_136 , false ) ;
if ( V_15 )
return V_15 ;
} else {
V_15 = V_2 -> V_40 -> V_158 ( & V_2 -> V_11 , V_81 , V_136 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_4 -> V_7 == V_121 )
F_61 ( V_81 , NULL , 0 , 0 , false ) ;
else if ( V_4 -> V_7 == V_72 )
F_29 ( V_81 , NULL , NULL , 0 , NULL , 0 ,
V_73 ,
V_101 , NULL ) ;
return 0 ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_80 * V_81 ,
T_2 V_136 , bool V_101 )
{
int V_15 ;
F_5 ( V_81 -> V_82 ) ;
V_15 = F_68 ( V_2 , V_81 , V_136 , V_101 ) ;
F_6 ( V_81 -> V_82 ) ;
return V_15 ;
}
void F_71 ( struct V_80 * V_81 ,
struct V_160 * V_75 )
{
struct V_3 * V_4 = V_81 -> V_82 ;
struct V_1 * V_2 = F_12 ( V_4 -> V_11 ) ;
T_1 V_52 [ V_70 ] ;
F_15 ( V_4 ) ;
if ( ! V_4 -> V_18 )
return;
if ( V_4 -> V_18 -> V_42 == V_120 )
return;
memcpy ( V_52 , V_75 -> V_119 . V_52 , V_70 ) ;
F_24 ( V_2 , V_81 , V_52 , NULL , 0 ,
V_65 , false ) ;
}
