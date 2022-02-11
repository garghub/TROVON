static T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 , const T_2 * V_4 )
{
T_3 V_5 = ( T_3 ) V_4 [ 0 ] ;
switch ( V_3 ) {
case V_6 :
return ( V_5 == 0 ) ? 0 : ( V_5 > 0 ? V_4 [ 2 ] : - V_4 [ 2 ] ) ;
case V_7 :
case V_8 :
case V_9 :
case V_10 :
default:
return V_4 [ 2 ] ;
}
}
static void F_2 ( struct V_1 * V_2 ,
T_1 V_11 , T_2 * V_4 )
{
V_4 [ 0 ] = V_11 == 0 ? 0 : ( V_11 > 0 ) ? 1 : 0xff ;
V_4 [ 2 ] = F_3 ( ( int ) abs ( V_11 ) , 0xff ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
T_2 V_3 , const T_2 * V_4 )
{
unsigned int V_12 = V_2 -> V_13 / 8 ;
T_3 V_14 = ( T_3 ) V_4 [ V_12 ] ;
switch ( V_3 ) {
case V_6 :
return ( V_14 == 0 ) ? 0 : ( V_14 > 0 ? V_4 [ V_12 + 1 ]
: - V_4 [ V_12 + 1 ] ) ;
case V_7 :
return - V_4 [ V_12 + 1 ] ;
case V_8 :
case V_9 :
case V_10 :
default:
return V_4 [ V_12 + 1 ] ;
}
}
static void F_5 ( struct V_1 * V_2 ,
T_1 V_11 , T_2 * V_4 )
{
unsigned int V_12 = V_2 -> V_13 / 8 ;
V_4 [ V_12 ] = V_11 == 0 ? 0 : ( V_11 > 0 ) ? 1 : 0xff ;
V_4 [ V_12 + 1 ] = F_6 ( int , abs ( V_11 ) , 0xff ) ;
}
static inline T_2 * F_7 ( struct V_15 * V_16 , int V_17 )
{
return V_16 -> V_18 + V_17 * V_16 -> V_19 . V_20 ;
}
static inline int F_8 ( const T_2 * V_4 , int V_21 )
{
return ( V_4 [ V_21 >> 3 ] >> ( V_21 & 7 ) ) & 1 ;
}
static inline void F_9 ( T_2 * V_4 , int V_21 )
{
V_4 [ V_21 >> 3 ] &= ~ ( 1 << ( V_21 & 7 ) ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
T_2 V_3 , const T_2 * V_4 )
{
int V_22 = V_2 -> V_20 ;
int V_13 = V_2 -> V_13 ;
T_1 V_11 = 0 ;
T_2 V_23 ;
V_4 += V_13 / 8 ;
V_13 &= 7 ;
V_23 = ( ( 1LL << V_22 ) - 1 ) << V_13 ;
for (; V_22 > 0 ; V_4 ++ ) {
T_2 V_24 = * V_4 & V_23 ;
V_11 |= V_13 > 0 ? ( V_24 >> V_13 ) : ( V_24 << ( - V_13 ) ) ;
V_22 -= 8 - ( V_13 > 0 ? V_13 : 0 ) ;
V_13 -= 8 ;
V_23 = ( 1 << V_22 ) - 1 ;
}
if ( V_2 -> V_25 == V_26 )
V_11 |= - ( V_11 & ( 1 << ( V_2 -> V_20 - 1 ) ) ) ;
return V_11 ;
}
static void F_11 ( struct V_1 * V_2 ,
T_1 V_11 , T_2 * V_4 )
{
int V_22 = V_2 -> V_20 ;
int V_13 = V_2 -> V_13 ;
T_2 V_23 ;
if ( V_2 -> V_27 == V_28 )
V_11 = - 1 ;
V_4 += V_13 / 8 ;
V_13 &= 7 ;
for (; V_22 > 0 ; V_4 ++ ) {
V_23 = ( ( 1LL << V_22 ) - 1 ) << V_13 ;
* V_4 = ( * V_4 & ~ V_23 ) | ( ( V_11 << V_13 ) & V_23 ) ;
V_11 >>= V_13 ? V_13 : 8 ;
V_22 -= 8 - V_13 ;
V_13 = 0 ;
}
}
static int F_12 ( const struct V_29 * V_30 ,
const T_2 V_31 [ 16 ] )
{
switch ( F_13 ( V_30 ) ) {
case V_32 :
return memcmp ( V_33 , V_31 , 16 ) == 0 ;
case V_34 :
return memcmp ( V_35 , V_31 , 16 ) == 0 ;
case V_36 :
return memcmp ( V_37 , V_31 , 16 ) == 0 ;
case V_38 :
return memcmp ( V_30 -> V_39 . V_40 ,
V_31 , 16 ) == 0 ;
default:
return 0 ;
}
}
static void F_14 ( struct V_29 * V_30 , T_4 V_41 ,
struct V_1 * * V_2 , struct V_15 * * V_42 ,
int V_43 )
{
struct V_15 * V_16 ;
struct V_1 * V_44 ;
unsigned int V_45 ;
if ( V_30 == NULL )
return;
for ( V_45 = 0 ; V_45 < V_30 -> V_46 ; ++ V_45 ) {
V_16 = & V_30 -> V_47 [ V_45 ] ;
if ( ! V_16 -> V_48 )
continue;
F_15 (map, &ctrl->info.mappings, list) {
if ( ( V_44 -> V_17 == V_41 ) && ! V_43 ) {
* V_42 = V_16 ;
* V_2 = V_44 ;
return;
}
if ( ( * V_2 == NULL || ( * V_2 ) -> V_17 > V_44 -> V_17 ) &&
( V_44 -> V_17 > V_41 ) && V_43 ) {
* V_42 = V_16 ;
* V_2 = V_44 ;
}
}
}
}
static struct V_15 * F_16 ( struct V_49 * V_50 ,
T_4 V_41 , struct V_1 * * V_2 )
{
struct V_15 * V_16 = NULL ;
struct V_29 * V_30 ;
int V_43 = V_41 & V_51 ;
* V_2 = NULL ;
V_41 &= V_52 ;
F_15 (entity, &chain->entities, chain) {
F_14 ( V_30 , V_41 , V_2 , & V_16 , V_43 ) ;
if ( V_16 && ! V_43 )
return V_16 ;
}
if ( V_16 == NULL && ! V_43 )
F_17 ( V_53 , L_1 ,
V_41 ) ;
return V_16 ;
}
static int F_18 ( struct V_49 * V_50 ,
struct V_15 * V_16 )
{
int V_54 ;
if ( V_16 -> V_19 . V_55 & V_56 ) {
V_54 = F_19 ( V_50 -> V_57 , V_10 , V_16 -> V_30 -> V_17 ,
V_50 -> V_57 -> V_58 , V_16 -> V_19 . V_59 ,
F_7 ( V_16 , V_60 ) ,
V_16 -> V_19 . V_20 ) ;
if ( V_54 < 0 )
return V_54 ;
}
if ( V_16 -> V_19 . V_55 & V_61 ) {
V_54 = F_19 ( V_50 -> V_57 , V_7 , V_16 -> V_30 -> V_17 ,
V_50 -> V_57 -> V_58 , V_16 -> V_19 . V_59 ,
F_7 ( V_16 , V_62 ) ,
V_16 -> V_19 . V_20 ) ;
if ( V_54 < 0 )
return V_54 ;
}
if ( V_16 -> V_19 . V_55 & V_63 ) {
V_54 = F_19 ( V_50 -> V_57 , V_8 , V_16 -> V_30 -> V_17 ,
V_50 -> V_57 -> V_58 , V_16 -> V_19 . V_59 ,
F_7 ( V_16 , V_64 ) ,
V_16 -> V_19 . V_20 ) ;
if ( V_54 < 0 )
return V_54 ;
}
if ( V_16 -> V_19 . V_55 & V_65 ) {
V_54 = F_19 ( V_50 -> V_57 , V_9 , V_16 -> V_30 -> V_17 ,
V_50 -> V_57 -> V_58 , V_16 -> V_19 . V_59 ,
F_7 ( V_16 , V_66 ) ,
V_16 -> V_19 . V_20 ) ;
if ( V_54 < 0 ) {
if ( F_13 ( V_16 -> V_30 ) !=
V_38 )
return V_54 ;
F_20 ( V_50 -> V_57 , V_67 ,
L_2
L_3 ) ;
memset ( F_7 ( V_16 , V_66 ) , 0 ,
V_16 -> V_19 . V_20 ) ;
}
}
V_16 -> V_68 = 1 ;
return 0 ;
}
static int F_21 ( struct V_49 * V_50 ,
struct V_15 * V_16 , struct V_1 * V_2 ,
T_5 * V_11 )
{
struct V_69 * V_70 ;
unsigned int V_45 ;
int V_54 ;
if ( ( V_16 -> V_19 . V_55 & V_71 ) == 0 )
return - V_72 ;
if ( ! V_16 -> V_73 ) {
V_54 = F_19 ( V_50 -> V_57 , V_6 , V_16 -> V_30 -> V_17 ,
V_50 -> V_57 -> V_58 , V_16 -> V_19 . V_59 ,
F_7 ( V_16 , V_74 ) ,
V_16 -> V_19 . V_20 ) ;
if ( V_54 < 0 )
return V_54 ;
V_16 -> V_73 = 1 ;
}
* V_11 = V_2 -> V_75 ( V_2 , V_6 ,
F_7 ( V_16 , V_74 ) ) ;
if ( V_2 -> V_27 == V_76 ) {
V_70 = V_2 -> V_77 ;
for ( V_45 = 0 ; V_45 < V_2 -> V_78 ; ++ V_45 , ++ V_70 ) {
if ( V_70 -> V_11 == * V_11 ) {
* V_11 = V_45 ;
break;
}
}
}
return 0 ;
}
static int F_22 ( struct V_49 * V_50 ,
struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_1 * V_81 = NULL ;
struct V_15 * V_82 = NULL ;
struct V_69 * V_70 ;
unsigned int V_45 ;
memset ( V_80 , 0 , sizeof *V_80 ) ;
V_80 -> V_17 = V_2 -> V_17 ;
V_80 -> type = V_2 -> V_27 ;
F_23 ( V_80 -> V_83 , V_2 -> V_83 , sizeof V_80 -> V_83 ) ;
V_80 -> V_55 = 0 ;
if ( ! ( V_16 -> V_19 . V_55 & V_71 ) )
V_80 -> V_55 |= V_84 ;
if ( ! ( V_16 -> V_19 . V_55 & V_85 ) )
V_80 -> V_55 |= V_86 ;
if ( V_2 -> V_87 )
F_14 ( V_16 -> V_30 , V_2 -> V_87 ,
& V_81 , & V_82 , 0 ) ;
if ( V_82 && ( V_82 -> V_19 . V_55 & V_71 ) ) {
T_5 V_88 ;
int V_54 = F_21 ( V_50 , V_82 , V_81 , & V_88 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_88 != V_2 -> V_89 )
V_80 -> V_55 |= V_90 ;
}
if ( ! V_16 -> V_68 ) {
int V_54 = F_18 ( V_50 , V_16 ) ;
if ( V_54 < 0 )
return V_54 ;
}
if ( V_16 -> V_19 . V_55 & V_56 ) {
V_80 -> V_91 = V_2 -> V_75 ( V_2 , V_10 ,
F_7 ( V_16 , V_60 ) ) ;
}
switch ( V_2 -> V_27 ) {
case V_76 :
V_80 -> V_92 = 0 ;
V_80 -> V_93 = V_2 -> V_78 - 1 ;
V_80 -> V_94 = 1 ;
V_70 = V_2 -> V_77 ;
for ( V_45 = 0 ; V_45 < V_2 -> V_78 ; ++ V_45 , ++ V_70 ) {
if ( V_70 -> V_11 == V_80 -> V_91 ) {
V_80 -> V_91 = V_45 ;
break;
}
}
return 0 ;
case V_95 :
V_80 -> V_92 = 0 ;
V_80 -> V_93 = 1 ;
V_80 -> V_94 = 1 ;
return 0 ;
case V_28 :
V_80 -> V_92 = 0 ;
V_80 -> V_93 = 0 ;
V_80 -> V_94 = 0 ;
return 0 ;
default:
break;
}
if ( V_16 -> V_19 . V_55 & V_61 )
V_80 -> V_92 = V_2 -> V_75 ( V_2 , V_7 ,
F_7 ( V_16 , V_62 ) ) ;
if ( V_16 -> V_19 . V_55 & V_63 )
V_80 -> V_93 = V_2 -> V_75 ( V_2 , V_8 ,
F_7 ( V_16 , V_64 ) ) ;
if ( V_16 -> V_19 . V_55 & V_65 )
V_80 -> V_94 = V_2 -> V_75 ( V_2 , V_9 ,
F_7 ( V_16 , V_66 ) ) ;
return 0 ;
}
int F_24 ( struct V_49 * V_50 ,
struct V_79 * V_80 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_54 ;
V_54 = F_25 ( & V_50 -> V_96 ) ;
if ( V_54 < 0 )
return - V_97 ;
V_16 = F_16 ( V_50 , V_80 -> V_17 , & V_2 ) ;
if ( V_16 == NULL ) {
V_54 = - V_98 ;
goto V_99;
}
V_54 = F_22 ( V_50 , V_16 , V_2 , V_80 ) ;
V_99:
F_26 ( & V_50 -> V_96 ) ;
return V_54 ;
}
int F_27 ( struct V_49 * V_50 ,
struct V_100 * V_101 )
{
struct V_69 * V_77 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
T_6 V_102 = V_101 -> V_102 ;
T_6 V_17 = V_101 -> V_17 ;
int V_54 ;
memset ( V_101 , 0 , sizeof( * V_101 ) ) ;
V_101 -> V_17 = V_17 ;
V_101 -> V_102 = V_102 ;
V_54 = F_25 ( & V_50 -> V_96 ) ;
if ( V_54 < 0 )
return - V_97 ;
V_16 = F_16 ( V_50 , V_101 -> V_17 , & V_2 ) ;
if ( V_16 == NULL || V_2 -> V_27 != V_76 ) {
V_54 = - V_98 ;
goto V_99;
}
if ( V_101 -> V_102 >= V_2 -> V_78 ) {
V_54 = - V_98 ;
goto V_99;
}
V_77 = & V_2 -> V_77 [ V_101 -> V_102 ] ;
if ( V_2 -> V_25 == V_103 &&
( V_16 -> V_19 . V_55 & V_65 ) ) {
T_5 V_104 ;
if ( ! V_16 -> V_68 ) {
V_54 = F_18 ( V_50 , V_16 ) ;
if ( V_54 < 0 )
goto V_99;
}
V_104 = V_2 -> V_75 ( V_2 , V_9 ,
F_7 ( V_16 , V_66 ) ) ;
if ( ! ( V_104 & V_77 -> V_11 ) ) {
V_54 = - V_98 ;
goto V_99;
}
}
F_23 ( V_101 -> V_83 , V_77 -> V_83 , sizeof V_101 -> V_83 ) ;
V_99:
F_26 ( & V_50 -> V_96 ) ;
return V_54 ;
}
static void F_28 ( struct V_49 * V_50 ,
struct V_105 * V_106 ,
struct V_15 * V_16 ,
struct V_1 * V_2 ,
T_5 V_11 , T_6 V_107 )
{
struct V_79 V_80 ;
F_22 ( V_50 , V_16 , V_2 , & V_80 ) ;
memset ( V_106 -> V_108 , 0 , sizeof( V_106 -> V_108 ) ) ;
V_106 -> type = V_109 ;
V_106 -> V_17 = V_80 . V_17 ;
V_106 -> V_110 . V_16 . V_11 = V_11 ;
V_106 -> V_110 . V_16 . V_107 = V_107 ;
V_106 -> V_110 . V_16 . type = V_80 . type ;
V_106 -> V_110 . V_16 . V_55 = V_80 . V_55 ;
V_106 -> V_110 . V_16 . V_92 = V_80 . V_92 ;
V_106 -> V_110 . V_16 . V_93 = V_80 . V_93 ;
V_106 -> V_110 . V_16 . V_94 = V_80 . V_94 ;
V_106 -> V_110 . V_16 . V_91 = V_80 . V_91 ;
}
static void F_29 ( struct V_111 * V_112 ,
struct V_15 * V_16 , struct V_1 * V_2 ,
T_5 V_11 , T_6 V_107 )
{
struct V_113 * V_114 ;
struct V_105 V_106 ;
if ( F_30 ( & V_2 -> V_115 ) )
return;
F_28 ( V_112 -> V_50 , & V_106 , V_16 , V_2 , V_11 , V_107 ) ;
F_15 (sev, &mapping->ev_subs, node) {
if ( V_114 -> V_116 && ( V_114 -> V_116 != & V_112 -> V_117 ||
( V_114 -> V_55 & V_118 ) ||
( V_107 & V_119 ) ) )
F_31 ( V_114 -> V_116 , & V_106 ) ;
}
}
static void F_32 ( struct V_111 * V_112 ,
struct V_15 * V_120 , T_6 V_121 ,
const struct V_122 * V_123 , unsigned int V_124 )
{
struct V_1 * V_2 = NULL ;
struct V_15 * V_16 = NULL ;
T_6 V_107 = V_119 ;
unsigned int V_45 ;
T_5 V_88 = 0 ;
for ( V_45 = 0 ; V_45 < V_124 ; V_45 ++ ) {
if ( V_123 [ V_45 ] . V_17 == V_121 )
return;
}
F_14 ( V_120 -> V_30 , V_121 , & V_2 , & V_16 , 0 ) ;
if ( V_16 == NULL )
return;
if ( F_21 ( V_112 -> V_50 , V_16 , V_2 , & V_88 ) == 0 )
V_107 |= V_125 ;
F_29 ( V_112 , V_16 , V_2 , V_88 , V_107 ) ;
}
static void F_33 ( struct V_111 * V_112 ,
const struct V_122 * V_123 , unsigned int V_124 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
T_6 V_107 = V_125 ;
unsigned int V_45 ;
unsigned int V_126 ;
for ( V_45 = 0 ; V_45 < V_124 ; ++ V_45 ) {
V_16 = F_16 ( V_112 -> V_50 , V_123 [ V_45 ] . V_17 , & V_2 ) ;
for ( V_126 = 0 ; V_126 < F_34 ( V_2 -> V_127 ) ; ++ V_126 ) {
if ( ! V_2 -> V_127 [ V_126 ] )
break;
F_32 ( V_112 , V_16 ,
V_2 -> V_127 [ V_126 ] ,
V_123 , V_124 ) ;
}
if ( V_2 -> V_87 ) {
for ( V_126 = 0 ; V_126 < V_124 ; V_126 ++ ) {
if ( V_123 [ V_126 ] . V_17 == V_2 -> V_87 ) {
V_107 |= V_119 ;
break;
}
}
}
F_29 ( V_112 , V_16 , V_2 , V_123 [ V_45 ] . V_11 ,
V_107 ) ;
}
}
static int F_35 ( struct V_113 * V_114 , unsigned V_128 )
{
struct V_111 * V_112 = F_36 ( V_114 -> V_116 , struct V_111 , V_117 ) ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_54 ;
V_54 = F_25 ( & V_112 -> V_50 -> V_96 ) ;
if ( V_54 < 0 )
return - V_97 ;
V_16 = F_16 ( V_112 -> V_50 , V_114 -> V_17 , & V_2 ) ;
if ( V_16 == NULL ) {
V_54 = - V_98 ;
goto V_99;
}
F_37 ( & V_114 -> V_129 , & V_2 -> V_115 ) ;
if ( V_114 -> V_55 & V_130 ) {
struct V_105 V_106 ;
T_6 V_107 = V_119 ;
T_5 V_88 = 0 ;
if ( F_21 ( V_112 -> V_50 , V_16 , V_2 , & V_88 ) == 0 )
V_107 |= V_125 ;
F_28 ( V_112 -> V_50 , & V_106 , V_16 , V_2 , V_88 ,
V_107 ) ;
V_114 -> V_128 = V_128 ;
F_31 ( V_114 -> V_116 , & V_106 ) ;
}
V_99:
F_26 ( & V_112 -> V_50 -> V_96 ) ;
return V_54 ;
}
static void F_38 ( struct V_113 * V_114 )
{
struct V_111 * V_112 = F_36 ( V_114 -> V_116 , struct V_111 , V_117 ) ;
F_39 ( & V_112 -> V_50 -> V_96 ) ;
F_40 ( & V_114 -> V_129 ) ;
F_26 ( & V_112 -> V_50 -> V_96 ) ;
}
int F_41 ( struct V_49 * V_50 )
{
return F_25 ( & V_50 -> V_96 ) ? - V_97 : 0 ;
}
static int F_42 ( struct V_131 * V_57 ,
struct V_29 * V_30 , int V_132 )
{
struct V_15 * V_16 ;
unsigned int V_45 ;
int V_54 ;
if ( V_30 == NULL )
return 0 ;
for ( V_45 = 0 ; V_45 < V_30 -> V_46 ; ++ V_45 ) {
V_16 = & V_30 -> V_47 [ V_45 ] ;
if ( ! V_16 -> V_48 )
continue;
if ( V_16 -> V_19 . V_55 & V_133 ||
! ( V_16 -> V_19 . V_55 & V_71 ) )
V_16 -> V_73 = 0 ;
if ( ! V_16 -> V_134 )
continue;
if ( ! V_132 )
V_54 = F_19 ( V_57 , V_135 , V_16 -> V_30 -> V_17 ,
V_57 -> V_58 , V_16 -> V_19 . V_59 ,
F_7 ( V_16 , V_74 ) ,
V_16 -> V_19 . V_20 ) ;
else
V_54 = 0 ;
if ( V_132 || V_54 < 0 )
memcpy ( F_7 ( V_16 , V_74 ) ,
F_7 ( V_16 , V_136 ) ,
V_16 -> V_19 . V_20 ) ;
V_16 -> V_134 = 0 ;
if ( V_54 < 0 )
return V_54 ;
}
return 0 ;
}
int F_43 ( struct V_111 * V_112 , int V_132 ,
const struct V_122 * V_123 ,
unsigned int V_124 )
{
struct V_49 * V_50 = V_112 -> V_50 ;
struct V_29 * V_30 ;
int V_54 = 0 ;
F_15 (entity, &chain->entities, chain) {
V_54 = F_42 ( V_50 -> V_57 , V_30 , V_132 ) ;
if ( V_54 < 0 )
goto V_99;
}
if ( ! V_132 )
F_33 ( V_112 , V_123 , V_124 ) ;
V_99:
F_26 ( & V_50 -> V_96 ) ;
return V_54 ;
}
int F_44 ( struct V_49 * V_50 ,
struct V_122 * V_137 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
V_16 = F_16 ( V_50 , V_137 -> V_17 , & V_2 ) ;
if ( V_16 == NULL )
return - V_98 ;
return F_21 ( V_50 , V_16 , V_2 , & V_137 -> V_11 ) ;
}
int F_45 ( struct V_49 * V_50 ,
struct V_122 * V_137 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
T_5 V_11 ;
T_6 V_94 ;
T_5 F_3 ;
T_5 V_138 ;
int V_54 ;
V_16 = F_16 ( V_50 , V_137 -> V_17 , & V_2 ) ;
if ( V_16 == NULL )
return - V_98 ;
if ( ! ( V_16 -> V_19 . V_55 & V_85 ) )
return - V_72 ;
switch ( V_2 -> V_27 ) {
case V_139 :
if ( ! V_16 -> V_68 ) {
V_54 = F_18 ( V_50 , V_16 ) ;
if ( V_54 < 0 )
return V_54 ;
}
F_3 = V_2 -> V_75 ( V_2 , V_7 ,
F_7 ( V_16 , V_62 ) ) ;
V_138 = V_2 -> V_75 ( V_2 , V_8 ,
F_7 ( V_16 , V_64 ) ) ;
V_94 = V_2 -> V_75 ( V_2 , V_9 ,
F_7 ( V_16 , V_66 ) ) ;
if ( V_94 == 0 )
V_94 = 1 ;
V_137 -> V_11 = F_3 + ( ( T_6 ) ( V_137 -> V_11 - F_3 ) + V_94 / 2 )
/ V_94 * V_94 ;
if ( V_2 -> V_25 == V_26 )
V_137 -> V_11 = F_46 ( V_137 -> V_11 , F_3 , V_138 ) ;
else
V_137 -> V_11 = F_47 ( T_6 , V_137 -> V_11 , F_3 , V_138 ) ;
V_11 = V_137 -> V_11 ;
break;
case V_95 :
V_137 -> V_11 = F_46 ( V_137 -> V_11 , 0 , 1 ) ;
V_11 = V_137 -> V_11 ;
break;
case V_76 :
if ( V_137 -> V_11 < 0 || V_137 -> V_11 >= V_2 -> V_78 )
return - V_140 ;
V_11 = V_2 -> V_77 [ V_137 -> V_11 ] . V_11 ;
if ( V_2 -> V_25 == V_103 &&
( V_16 -> V_19 . V_55 & V_65 ) ) {
if ( ! V_16 -> V_68 ) {
V_54 = F_18 ( V_50 , V_16 ) ;
if ( V_54 < 0 )
return V_54 ;
}
V_94 = V_2 -> V_75 ( V_2 , V_9 ,
F_7 ( V_16 , V_66 ) ) ;
if ( ! ( V_94 & V_11 ) )
return - V_98 ;
}
break;
default:
V_11 = V_137 -> V_11 ;
break;
}
if ( ! V_16 -> V_73 && ( V_16 -> V_19 . V_20 * 8 ) != V_2 -> V_20 ) {
if ( ( V_16 -> V_19 . V_55 & V_71 ) == 0 ) {
memset ( F_7 ( V_16 , V_74 ) ,
0 , V_16 -> V_19 . V_20 ) ;
} else {
V_54 = F_19 ( V_50 -> V_57 , V_6 ,
V_16 -> V_30 -> V_17 , V_50 -> V_57 -> V_58 ,
V_16 -> V_19 . V_59 ,
F_7 ( V_16 , V_74 ) ,
V_16 -> V_19 . V_20 ) ;
if ( V_54 < 0 )
return V_54 ;
}
V_16 -> V_73 = 1 ;
}
if ( ! V_16 -> V_134 ) {
memcpy ( F_7 ( V_16 , V_136 ) ,
F_7 ( V_16 , V_74 ) ,
V_16 -> V_19 . V_20 ) ;
}
V_2 -> V_141 ( V_2 , V_11 ,
F_7 ( V_16 , V_74 ) ) ;
V_16 -> V_134 = 1 ;
V_16 -> V_142 = 1 ;
return 0 ;
}
static void F_48 ( struct V_131 * V_57 ,
const struct V_15 * V_16 , struct V_143 * V_19 )
{
struct V_144 {
struct V_145 V_17 ;
T_7 V_30 ;
T_7 V_59 ;
T_7 V_55 ;
};
static const struct V_144 V_146 [] = {
{ { F_49 ( 0x046d , 0x08c2 ) } , 9 , 1 ,
V_61 | V_63 |
V_56 | V_85 |
V_133 } ,
{ { F_49 ( 0x046d , 0x08cc ) } , 9 , 1 ,
V_61 | V_63 |
V_56 | V_85 |
V_133 } ,
{ { F_49 ( 0x046d , 0x0994 ) } , 9 , 1 ,
V_61 | V_63 |
V_56 | V_85 |
V_133 } ,
} ;
unsigned int V_45 ;
for ( V_45 = 0 ; V_45 < F_34 ( V_146 ) ; ++ V_45 ) {
if ( ! F_50 ( V_57 -> V_147 , & V_146 [ V_45 ] . V_17 ) )
continue;
if ( V_146 [ V_45 ] . V_30 == V_16 -> V_30 -> V_17 &&
V_146 [ V_45 ] . V_59 == V_19 -> V_59 ) {
V_19 -> V_55 = V_146 [ V_45 ] . V_55 ;
return;
}
}
}
static int F_51 ( struct V_131 * V_57 ,
const struct V_15 * V_16 , struct V_143 * V_19 )
{
T_7 * V_4 ;
int V_54 ;
V_4 = F_52 ( 2 , V_148 ) ;
if ( V_4 == NULL )
return - V_149 ;
memcpy ( V_19 -> V_30 , V_16 -> V_30 -> V_39 . V_40 ,
sizeof( V_19 -> V_30 ) ) ;
V_19 -> V_102 = V_16 -> V_102 ;
V_19 -> V_59 = V_16 -> V_102 + 1 ;
V_54 = F_19 ( V_57 , V_150 , V_16 -> V_30 -> V_17 , V_57 -> V_58 ,
V_19 -> V_59 , V_4 , 2 ) ;
if ( V_54 < 0 ) {
F_17 ( V_53 ,
L_4 ,
V_19 -> V_30 , V_19 -> V_59 , V_54 ) ;
goto V_99;
}
V_19 -> V_20 = F_53 ( ( V_151 * ) V_4 ) ;
V_54 = F_19 ( V_57 , V_152 , V_16 -> V_30 -> V_17 , V_57 -> V_58 ,
V_19 -> V_59 , V_4 , 1 ) ;
if ( V_54 < 0 ) {
F_17 ( V_53 ,
L_5 ,
V_19 -> V_30 , V_19 -> V_59 , V_54 ) ;
goto V_99;
}
V_19 -> V_55 = V_61 | V_63
| V_65 | V_56
| ( V_4 [ 0 ] & V_153 ?
V_71 : 0 )
| ( V_4 [ 0 ] & V_154 ?
V_85 : 0 )
| ( V_4 [ 0 ] & V_155 ?
V_133 : 0 ) ;
F_48 ( V_57 , V_16 , V_19 ) ;
F_17 ( V_53 , L_6
L_7 ,
V_19 -> V_30 , V_19 -> V_59 , V_19 -> V_20 ,
( V_19 -> V_55 & V_71 ) ? 1 : 0 ,
( V_19 -> V_55 & V_85 ) ? 1 : 0 ,
( V_19 -> V_55 & V_133 ) ? 1 : 0 ) ;
V_99:
F_54 ( V_4 ) ;
return V_54 ;
}
static int F_55 ( struct V_131 * V_57 ,
struct V_15 * V_16 )
{
struct V_143 V_19 ;
int V_54 ;
if ( V_16 -> V_48 )
return 0 ;
V_54 = F_51 ( V_57 , V_16 , & V_19 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_56 ( V_57 , V_16 , & V_19 ) ;
if ( V_54 < 0 )
F_17 ( V_53 , L_8
L_9 , V_19 . V_30 ,
V_19 . V_59 , V_57 -> V_156 -> V_157 , V_16 -> V_30 -> V_17 ) ;
return V_54 ;
}
int F_57 ( struct V_49 * V_50 ,
struct V_158 * V_159 )
{
struct V_29 * V_30 ;
struct V_15 * V_16 ;
unsigned int V_45 , V_160 = 0 ;
T_4 V_161 ;
T_8 V_20 ;
T_2 * V_4 = NULL ;
int V_54 ;
F_15 (entity, &chain->entities, chain) {
if ( F_13 ( V_30 ) == V_38 &&
V_30 -> V_17 == V_159 -> V_162 )
break;
}
if ( V_30 -> V_17 != V_159 -> V_162 ) {
F_17 ( V_53 , L_10 ,
V_159 -> V_162 ) ;
return - V_163 ;
}
for ( V_45 = 0 ; V_45 < V_30 -> V_46 ; ++ V_45 ) {
V_16 = & V_30 -> V_47 [ V_45 ] ;
if ( V_16 -> V_102 == V_159 -> V_59 - 1 ) {
V_160 = 1 ;
break;
}
}
if ( ! V_160 ) {
F_17 ( V_53 , L_11 ,
V_30 -> V_39 . V_40 , V_159 -> V_59 ) ;
return - V_163 ;
}
if ( F_25 ( & V_50 -> V_96 ) )
return - V_97 ;
V_54 = F_55 ( V_50 -> V_57 , V_16 ) ;
if ( V_54 < 0 ) {
V_54 = - V_163 ;
goto V_99;
}
V_161 = 0 ;
V_20 = V_16 -> V_19 . V_20 ;
switch ( V_159 -> V_3 ) {
case V_6 :
V_161 = V_71 ;
break;
case V_7 :
V_161 = V_61 ;
break;
case V_8 :
V_161 = V_63 ;
break;
case V_10 :
V_161 = V_56 ;
break;
case V_9 :
V_161 = V_65 ;
break;
case V_135 :
V_161 = V_85 ;
break;
case V_150 :
V_20 = 2 ;
break;
case V_152 :
V_20 = 1 ;
break;
default:
V_54 = - V_98 ;
goto V_99;
}
if ( V_20 != V_159 -> V_20 ) {
V_54 = - V_164 ;
goto V_99;
}
if ( V_161 && ! ( V_16 -> V_19 . V_55 & V_161 ) ) {
V_54 = - V_165 ;
goto V_99;
}
V_4 = F_52 ( V_20 , V_148 ) ;
if ( V_4 == NULL ) {
V_54 = - V_149 ;
goto V_99;
}
if ( V_159 -> V_3 == V_135 &&
F_58 ( V_4 , V_159 -> V_4 , V_20 ) ) {
V_54 = - V_166 ;
goto V_99;
}
V_54 = F_19 ( V_50 -> V_57 , V_159 -> V_3 , V_159 -> V_162 ,
V_50 -> V_57 -> V_58 , V_159 -> V_59 , V_4 , V_20 ) ;
if ( V_54 < 0 )
goto V_99;
if ( V_159 -> V_3 != V_135 &&
F_59 ( V_159 -> V_4 , V_4 , V_20 ) )
V_54 = - V_166 ;
V_99:
F_54 ( V_4 ) ;
F_26 ( & V_50 -> V_96 ) ;
return V_54 ;
}
int F_60 ( struct V_131 * V_57 )
{
struct V_15 * V_16 ;
struct V_29 * V_30 ;
unsigned int V_45 ;
int V_54 ;
F_15 (entity, &dev->entities, list) {
for ( V_45 = 0 ; V_45 < V_30 -> V_46 ; ++ V_45 ) {
V_16 = & V_30 -> V_47 [ V_45 ] ;
if ( ! V_16 -> V_48 || ! V_16 -> V_142 ||
( V_16 -> V_19 . V_55 & V_167 ) == 0 )
continue;
F_61 ( V_168 L_12 ,
V_16 -> V_19 . V_30 , V_16 -> V_19 . V_102 ,
V_16 -> V_19 . V_59 ) ;
V_16 -> V_134 = 1 ;
}
V_54 = F_42 ( V_57 , V_30 , 0 ) ;
if ( V_54 < 0 )
return V_54 ;
}
return 0 ;
}
static int F_56 ( struct V_131 * V_57 , struct V_15 * V_16 ,
const struct V_143 * V_19 )
{
int V_54 = 0 ;
V_16 -> V_19 = * V_19 ;
F_62 ( & V_16 -> V_19 . V_169 ) ;
V_16 -> V_18 = F_63 ( V_16 -> V_19 . V_20 * V_170 + 1 ,
V_148 ) ;
if ( V_16 -> V_18 == NULL ) {
V_54 = - V_149 ;
goto V_99;
}
V_16 -> V_48 = 1 ;
F_17 ( V_53 , L_13
L_14 , V_16 -> V_19 . V_30 , V_16 -> V_19 . V_59 ,
V_57 -> V_156 -> V_157 , V_16 -> V_30 -> V_17 ) ;
V_99:
if ( V_54 < 0 )
F_54 ( V_16 -> V_18 ) ;
return V_54 ;
}
static int F_64 ( struct V_131 * V_57 ,
struct V_15 * V_16 , const struct V_1 * V_2 )
{
struct V_1 * V_44 ;
unsigned int V_20 ;
V_44 = F_65 ( V_2 , sizeof( * V_2 ) , V_148 ) ;
if ( V_44 == NULL )
return - V_149 ;
F_62 ( & V_44 -> V_115 ) ;
V_20 = sizeof( * V_2 -> V_77 ) * V_2 -> V_78 ;
V_44 -> V_77 = F_65 ( V_2 -> V_77 , V_20 , V_148 ) ;
if ( V_44 -> V_77 == NULL ) {
F_54 ( V_44 ) ;
return - V_149 ;
}
if ( V_44 -> V_75 == NULL )
V_44 -> V_75 = F_10 ;
if ( V_44 -> V_141 == NULL )
V_44 -> V_141 = F_11 ;
F_37 ( & V_44 -> V_171 , & V_16 -> V_19 . V_169 ) ;
F_17 ( V_53 ,
L_15 ,
V_44 -> V_83 , V_16 -> V_19 . V_30 , V_16 -> V_19 . V_59 ) ;
return 0 ;
}
int F_66 ( struct V_49 * V_50 ,
const struct V_1 * V_2 )
{
struct V_131 * V_57 = V_50 -> V_57 ;
struct V_1 * V_44 ;
struct V_29 * V_30 ;
struct V_15 * V_16 ;
int V_160 = 0 ;
int V_54 ;
if ( V_2 -> V_17 & ~ V_52 ) {
F_17 ( V_53 , L_16
L_17 , V_2 -> V_83 ,
V_2 -> V_17 ) ;
return - V_98 ;
}
F_15 (entity, &chain->entities, chain) {
unsigned int V_45 ;
if ( F_13 ( V_30 ) != V_38 ||
! F_12 ( V_30 , V_2 -> V_30 ) )
continue;
for ( V_45 = 0 ; V_45 < V_30 -> V_46 ; ++ V_45 ) {
V_16 = & V_30 -> V_47 [ V_45 ] ;
if ( V_16 -> V_102 == V_2 -> V_59 - 1 ) {
V_160 = 1 ;
break;
}
}
if ( V_160 )
break;
}
if ( ! V_160 )
return - V_163 ;
if ( F_25 ( & V_50 -> V_96 ) )
return - V_97 ;
V_54 = F_55 ( V_57 , V_16 ) ;
if ( V_54 < 0 ) {
V_54 = - V_163 ;
goto V_99;
}
F_15 (map, &ctrl->info.mappings, list) {
if ( V_2 -> V_17 == V_44 -> V_17 ) {
F_17 ( V_53 , L_18
L_19 ,
V_2 -> V_83 , V_2 -> V_17 ) ;
V_54 = - V_172 ;
goto V_99;
}
}
if ( F_67 ( & V_57 -> V_173 ) > V_174 ) {
F_68 ( & V_57 -> V_173 ) ;
F_17 ( V_53 , L_20
L_21 , V_2 -> V_83 ,
V_174 ) ;
V_54 = - V_149 ;
goto V_99;
}
V_54 = F_64 ( V_57 , V_16 , V_2 ) ;
if ( V_54 < 0 )
F_68 ( & V_57 -> V_173 ) ;
V_99:
F_26 ( & V_50 -> V_96 ) ;
return V_54 ;
}
static void F_69 ( struct V_131 * V_57 ,
struct V_29 * V_30 )
{
struct V_175 {
struct V_145 V_17 ;
T_7 V_102 ;
};
static const struct V_175 V_176 [] = {
{ { F_49 ( 0x13d3 , 0x509b ) } , 9 } ,
{ { F_49 ( 0x1c4f , 0x3000 ) } , 6 } ,
{ { F_49 ( 0x5986 , 0x0241 ) } , 2 } ,
} ;
static const struct V_175 V_177 [] = {
{ { F_49 ( 0x06f8 , 0x3005 ) } , 9 } ,
} ;
const struct V_175 * V_178 ;
unsigned int V_20 ;
unsigned int V_179 ;
unsigned int V_45 ;
T_7 * V_47 ;
switch ( F_13 ( V_30 ) ) {
case V_36 :
V_178 = V_176 ;
V_179 = F_34 ( V_176 ) ;
V_47 = V_30 -> V_180 . V_181 ;
V_20 = V_30 -> V_180 . V_182 ;
break;
case V_32 :
V_178 = V_177 ;
V_179 = F_34 ( V_177 ) ;
V_47 = V_30 -> V_183 . V_181 ;
V_20 = V_30 -> V_183 . V_182 ;
break;
default:
return;
}
for ( V_45 = 0 ; V_45 < V_179 ; ++ V_45 ) {
if ( ! F_50 ( V_57 -> V_147 , & V_178 [ V_45 ] . V_17 ) )
continue;
if ( V_178 [ V_45 ] . V_102 >= 8 * V_20 ||
! F_8 ( V_47 , V_178 [ V_45 ] . V_102 ) )
continue;
F_17 ( V_53 , L_22
L_23 , V_30 -> V_17 , V_178 [ V_45 ] . V_102 ) ;
F_9 ( V_47 , V_178 [ V_45 ] . V_102 ) ;
}
}
static void F_70 ( struct V_131 * V_57 , struct V_15 * V_16 )
{
const struct V_143 * V_19 = V_184 ;
const struct V_143 * V_185 = V_19 + F_34 ( V_184 ) ;
const struct V_1 * V_2 = V_186 ;
const struct V_1 * V_187 =
V_2 + F_34 ( V_186 ) ;
if ( F_13 ( V_16 -> V_30 ) == V_38 )
return;
for (; V_19 < V_185 ; ++ V_19 ) {
if ( F_12 ( V_16 -> V_30 , V_19 -> V_30 ) &&
V_16 -> V_102 == V_19 -> V_102 ) {
F_56 ( V_57 , V_16 , V_19 ) ;
break;
}
}
if ( ! V_16 -> V_48 )
return;
for (; V_2 < V_187 ; ++ V_2 ) {
if ( F_12 ( V_16 -> V_30 , V_2 -> V_30 ) &&
V_16 -> V_19 . V_59 == V_2 -> V_59 )
F_64 ( V_57 , V_16 , V_2 ) ;
}
}
int F_71 ( struct V_131 * V_57 )
{
struct V_29 * V_30 ;
unsigned int V_45 ;
F_15 (entity, &dev->entities, list) {
struct V_15 * V_16 ;
unsigned int V_182 = 0 , V_46 ;
T_2 * V_181 = NULL ;
if ( F_13 ( V_30 ) == V_38 ) {
V_181 = V_30 -> V_39 . V_181 ;
V_182 = V_30 -> V_39 . V_182 ;
} else if ( F_13 ( V_30 ) == V_36 ) {
V_181 = V_30 -> V_180 . V_181 ;
V_182 = V_30 -> V_180 . V_182 ;
} else if ( F_13 ( V_30 ) == V_32 ) {
V_181 = V_30 -> V_183 . V_181 ;
V_182 = V_30 -> V_183 . V_182 ;
}
F_69 ( V_57 , V_30 ) ;
V_46 = F_72 ( V_181 , V_182 ) ;
if ( V_46 == 0 )
continue;
V_30 -> V_47 = F_73 ( V_46 , sizeof( * V_16 ) ,
V_148 ) ;
if ( V_30 -> V_47 == NULL )
return - V_149 ;
V_30 -> V_46 = V_46 ;
V_16 = V_30 -> V_47 ;
for ( V_45 = 0 ; V_45 < V_182 * 8 ; ++ V_45 ) {
if ( F_8 ( V_181 , V_45 ) == 0 )
continue;
V_16 -> V_30 = V_30 ;
V_16 -> V_102 = V_45 ;
F_70 ( V_57 , V_16 ) ;
V_16 ++ ;
}
}
return 0 ;
}
static void F_74 ( struct V_131 * V_57 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 , * V_188 ;
F_75 (mapping, nm, &ctrl->info.mappings, list) {
F_40 ( & V_2 -> V_171 ) ;
F_54 ( V_2 -> V_77 ) ;
F_54 ( V_2 ) ;
}
}
void F_76 ( struct V_131 * V_57 )
{
struct V_29 * V_30 ;
unsigned int V_45 ;
F_15 (entity, &dev->entities, list) {
for ( V_45 = 0 ; V_45 < V_30 -> V_46 ; ++ V_45 ) {
struct V_15 * V_16 = & V_30 -> V_47 [ V_45 ] ;
if ( ! V_16 -> V_48 )
continue;
F_74 ( V_57 , V_16 ) ;
F_54 ( V_16 -> V_18 ) ;
}
F_54 ( V_30 -> V_47 ) ;
}
}
