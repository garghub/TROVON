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
static inline T_2 * F_4 ( struct V_12 * V_13 , int V_14 )
{
return V_13 -> V_15 + V_14 * V_13 -> V_16 . V_17 ;
}
static inline int F_5 ( const T_2 * V_4 , int V_18 )
{
return ( V_4 [ V_18 >> 3 ] >> ( V_18 & 7 ) ) & 1 ;
}
static inline void F_6 ( T_2 * V_4 , int V_18 )
{
V_4 [ V_18 >> 3 ] &= ~ ( 1 << ( V_18 & 7 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
T_2 V_3 , const T_2 * V_4 )
{
int V_19 = V_2 -> V_17 ;
int V_20 = V_2 -> V_20 ;
T_1 V_11 = 0 ;
T_2 V_21 ;
V_4 += V_20 / 8 ;
V_20 &= 7 ;
V_21 = ( ( 1LL << V_19 ) - 1 ) << V_20 ;
for (; V_19 > 0 ; V_4 ++ ) {
T_2 V_22 = * V_4 & V_21 ;
V_11 |= V_20 > 0 ? ( V_22 >> V_20 ) : ( V_22 << ( - V_20 ) ) ;
V_19 -= 8 - ( V_20 > 0 ? V_20 : 0 ) ;
V_20 -= 8 ;
V_21 = ( 1 << V_19 ) - 1 ;
}
if ( V_2 -> V_23 == V_24 )
V_11 |= - ( V_11 & ( 1 << ( V_2 -> V_17 - 1 ) ) ) ;
return V_11 ;
}
static void F_8 ( struct V_1 * V_2 ,
T_1 V_11 , T_2 * V_4 )
{
int V_19 = V_2 -> V_17 ;
int V_20 = V_2 -> V_20 ;
T_2 V_21 ;
if ( V_2 -> V_25 == V_26 )
V_11 = - 1 ;
V_4 += V_20 / 8 ;
V_20 &= 7 ;
for (; V_19 > 0 ; V_4 ++ ) {
V_21 = ( ( 1LL << V_19 ) - 1 ) << V_20 ;
* V_4 = ( * V_4 & ~ V_21 ) | ( ( V_11 << V_20 ) & V_21 ) ;
V_11 >>= V_20 ? V_20 : 8 ;
V_19 -= 8 - V_20 ;
V_20 = 0 ;
}
}
static int F_9 ( const struct V_27 * V_28 ,
const T_2 V_29 [ 16 ] )
{
switch ( F_10 ( V_28 ) ) {
case V_30 :
return memcmp ( V_31 , V_29 , 16 ) == 0 ;
case V_32 :
return memcmp ( V_33 , V_29 , 16 ) == 0 ;
case V_34 :
return memcmp ( V_35 , V_29 , 16 ) == 0 ;
case V_36 :
return memcmp ( V_28 -> V_37 . V_38 ,
V_29 , 16 ) == 0 ;
default:
return 0 ;
}
}
static void F_11 ( struct V_27 * V_28 , T_4 V_39 ,
struct V_1 * * V_2 , struct V_12 * * V_40 ,
int V_41 )
{
struct V_12 * V_13 ;
struct V_1 * V_42 ;
unsigned int V_43 ;
if ( V_28 == NULL )
return;
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( ! V_13 -> V_46 )
continue;
F_12 (map, &ctrl->info.mappings, list) {
if ( ( V_42 -> V_14 == V_39 ) && ! V_41 ) {
* V_40 = V_13 ;
* V_2 = V_42 ;
return;
}
if ( ( * V_2 == NULL || ( * V_2 ) -> V_14 > V_42 -> V_14 ) &&
( V_42 -> V_14 > V_39 ) && V_41 ) {
* V_40 = V_13 ;
* V_2 = V_42 ;
}
}
}
}
static struct V_12 * F_13 ( struct V_47 * V_48 ,
T_4 V_39 , struct V_1 * * V_2 )
{
struct V_12 * V_13 = NULL ;
struct V_27 * V_28 ;
int V_41 = V_39 & V_49 ;
* V_2 = NULL ;
V_39 &= V_50 ;
F_12 (entity, &chain->entities, chain) {
F_11 ( V_28 , V_39 , V_2 , & V_13 , V_41 ) ;
if ( V_13 && ! V_41 )
return V_13 ;
}
if ( V_13 == NULL && ! V_41 )
F_14 ( V_51 , L_1 ,
V_39 ) ;
return V_13 ;
}
static int F_15 ( struct V_47 * V_48 ,
struct V_12 * V_13 )
{
int V_52 ;
if ( V_13 -> V_16 . V_53 & V_54 ) {
V_52 = F_16 ( V_48 -> V_55 , V_10 , V_13 -> V_28 -> V_14 ,
V_48 -> V_55 -> V_56 , V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_58 ) ,
V_13 -> V_16 . V_17 ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( V_13 -> V_16 . V_53 & V_59 ) {
V_52 = F_16 ( V_48 -> V_55 , V_7 , V_13 -> V_28 -> V_14 ,
V_48 -> V_55 -> V_56 , V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_60 ) ,
V_13 -> V_16 . V_17 ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( V_13 -> V_16 . V_53 & V_61 ) {
V_52 = F_16 ( V_48 -> V_55 , V_8 , V_13 -> V_28 -> V_14 ,
V_48 -> V_55 -> V_56 , V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_62 ) ,
V_13 -> V_16 . V_17 ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( V_13 -> V_16 . V_53 & V_63 ) {
V_52 = F_16 ( V_48 -> V_55 , V_9 , V_13 -> V_28 -> V_14 ,
V_48 -> V_55 -> V_56 , V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_64 ) ,
V_13 -> V_16 . V_17 ) ;
if ( V_52 < 0 ) {
if ( F_10 ( V_13 -> V_28 ) !=
V_36 )
return V_52 ;
F_17 ( V_48 -> V_55 , V_65 ,
L_2
L_3 ) ;
memset ( F_4 ( V_13 , V_64 ) , 0 ,
V_13 -> V_16 . V_17 ) ;
}
}
V_13 -> V_66 = 1 ;
return 0 ;
}
static int F_18 ( struct V_47 * V_48 ,
struct V_12 * V_13 , struct V_1 * V_2 ,
T_5 * V_11 )
{
struct V_67 * V_68 ;
unsigned int V_43 ;
int V_52 ;
if ( ( V_13 -> V_16 . V_53 & V_69 ) == 0 )
return - V_70 ;
if ( ! V_13 -> V_71 ) {
V_52 = F_16 ( V_48 -> V_55 , V_6 , V_13 -> V_28 -> V_14 ,
V_48 -> V_55 -> V_56 , V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_72 ) ,
V_13 -> V_16 . V_17 ) ;
if ( V_52 < 0 )
return V_52 ;
V_13 -> V_71 = 1 ;
}
* V_11 = V_2 -> V_73 ( V_2 , V_6 ,
F_4 ( V_13 , V_72 ) ) ;
if ( V_2 -> V_25 == V_74 ) {
V_68 = V_2 -> V_75 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_76 ; ++ V_43 , ++ V_68 ) {
if ( V_68 -> V_11 == * V_11 ) {
* V_11 = V_43 ;
break;
}
}
}
return 0 ;
}
static int F_19 ( struct V_47 * V_48 ,
struct V_12 * V_13 ,
struct V_1 * V_2 ,
struct V_77 * V_78 )
{
struct V_1 * V_79 = NULL ;
struct V_12 * V_80 = NULL ;
struct V_67 * V_68 ;
unsigned int V_43 ;
memset ( V_78 , 0 , sizeof *V_78 ) ;
V_78 -> V_14 = V_2 -> V_14 ;
V_78 -> type = V_2 -> V_25 ;
F_20 ( V_78 -> V_81 , V_2 -> V_81 , sizeof V_78 -> V_81 ) ;
V_78 -> V_53 = 0 ;
if ( ! ( V_13 -> V_16 . V_53 & V_69 ) )
V_78 -> V_53 |= V_82 ;
if ( ! ( V_13 -> V_16 . V_53 & V_83 ) )
V_78 -> V_53 |= V_84 ;
if ( V_2 -> V_85 )
F_11 ( V_13 -> V_28 , V_2 -> V_85 ,
& V_79 , & V_80 , 0 ) ;
if ( V_80 && ( V_80 -> V_16 . V_53 & V_69 ) ) {
T_5 V_86 ;
int V_52 = F_18 ( V_48 , V_80 , V_79 , & V_86 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( V_86 != V_2 -> V_87 )
V_78 -> V_53 |= V_88 ;
}
if ( ! V_13 -> V_66 ) {
int V_52 = F_15 ( V_48 , V_13 ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( V_13 -> V_16 . V_53 & V_54 ) {
V_78 -> V_89 = V_2 -> V_73 ( V_2 , V_10 ,
F_4 ( V_13 , V_58 ) ) ;
}
switch ( V_2 -> V_25 ) {
case V_74 :
V_78 -> V_90 = 0 ;
V_78 -> V_91 = V_2 -> V_76 - 1 ;
V_78 -> V_92 = 1 ;
V_68 = V_2 -> V_75 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_76 ; ++ V_43 , ++ V_68 ) {
if ( V_68 -> V_11 == V_78 -> V_89 ) {
V_78 -> V_89 = V_43 ;
break;
}
}
return 0 ;
case V_93 :
V_78 -> V_90 = 0 ;
V_78 -> V_91 = 1 ;
V_78 -> V_92 = 1 ;
return 0 ;
case V_26 :
V_78 -> V_90 = 0 ;
V_78 -> V_91 = 0 ;
V_78 -> V_92 = 0 ;
return 0 ;
default:
break;
}
if ( V_13 -> V_16 . V_53 & V_59 )
V_78 -> V_90 = V_2 -> V_73 ( V_2 , V_7 ,
F_4 ( V_13 , V_60 ) ) ;
if ( V_13 -> V_16 . V_53 & V_61 )
V_78 -> V_91 = V_2 -> V_73 ( V_2 , V_8 ,
F_4 ( V_13 , V_62 ) ) ;
if ( V_13 -> V_16 . V_53 & V_63 )
V_78 -> V_92 = V_2 -> V_73 ( V_2 , V_9 ,
F_4 ( V_13 , V_64 ) ) ;
return 0 ;
}
int F_21 ( struct V_47 * V_48 ,
struct V_77 * V_78 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_52 ;
V_52 = F_22 ( & V_48 -> V_94 ) ;
if ( V_52 < 0 )
return - V_95 ;
V_13 = F_13 ( V_48 , V_78 -> V_14 , & V_2 ) ;
if ( V_13 == NULL ) {
V_52 = - V_96 ;
goto V_97;
}
V_52 = F_19 ( V_48 , V_13 , V_2 , V_78 ) ;
V_97:
F_23 ( & V_48 -> V_94 ) ;
return V_52 ;
}
int F_24 ( struct V_47 * V_48 ,
struct V_98 * V_99 )
{
struct V_67 * V_75 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
T_6 V_100 = V_99 -> V_100 ;
T_6 V_14 = V_99 -> V_14 ;
int V_52 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
V_99 -> V_14 = V_14 ;
V_99 -> V_100 = V_100 ;
V_52 = F_22 ( & V_48 -> V_94 ) ;
if ( V_52 < 0 )
return - V_95 ;
V_13 = F_13 ( V_48 , V_99 -> V_14 , & V_2 ) ;
if ( V_13 == NULL || V_2 -> V_25 != V_74 ) {
V_52 = - V_96 ;
goto V_97;
}
if ( V_99 -> V_100 >= V_2 -> V_76 ) {
V_52 = - V_96 ;
goto V_97;
}
V_75 = & V_2 -> V_75 [ V_99 -> V_100 ] ;
if ( V_2 -> V_23 == V_101 &&
( V_13 -> V_16 . V_53 & V_63 ) ) {
T_5 V_102 ;
if ( ! V_13 -> V_66 ) {
V_52 = F_15 ( V_48 , V_13 ) ;
if ( V_52 < 0 )
goto V_97;
}
V_102 = V_2 -> V_73 ( V_2 , V_9 ,
F_4 ( V_13 , V_64 ) ) ;
if ( ! ( V_102 & V_75 -> V_11 ) ) {
V_52 = - V_96 ;
goto V_97;
}
}
F_20 ( V_99 -> V_81 , V_75 -> V_81 , sizeof V_99 -> V_81 ) ;
V_97:
F_23 ( & V_48 -> V_94 ) ;
return V_52 ;
}
static void F_25 ( struct V_47 * V_48 ,
struct V_103 * V_104 ,
struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_5 V_11 , T_6 V_105 )
{
struct V_77 V_78 ;
F_19 ( V_48 , V_13 , V_2 , & V_78 ) ;
memset ( V_104 -> V_106 , 0 , sizeof( V_104 -> V_106 ) ) ;
V_104 -> type = V_107 ;
V_104 -> V_14 = V_78 . V_14 ;
V_104 -> V_108 . V_13 . V_11 = V_11 ;
V_104 -> V_108 . V_13 . V_105 = V_105 ;
V_104 -> V_108 . V_13 . type = V_78 . type ;
V_104 -> V_108 . V_13 . V_53 = V_78 . V_53 ;
V_104 -> V_108 . V_13 . V_90 = V_78 . V_90 ;
V_104 -> V_108 . V_13 . V_91 = V_78 . V_91 ;
V_104 -> V_108 . V_13 . V_92 = V_78 . V_92 ;
V_104 -> V_108 . V_13 . V_89 = V_78 . V_89 ;
}
static void F_26 ( struct V_109 * V_110 ,
struct V_12 * V_13 , struct V_1 * V_2 ,
T_5 V_11 , T_6 V_105 )
{
struct V_111 * V_112 ;
struct V_103 V_104 ;
if ( F_27 ( & V_2 -> V_113 ) )
return;
F_25 ( V_110 -> V_48 , & V_104 , V_13 , V_2 , V_11 , V_105 ) ;
F_12 (sev, &mapping->ev_subs, node) {
if ( V_112 -> V_114 && ( V_112 -> V_114 != & V_110 -> V_115 ||
( V_112 -> V_53 & V_116 ) ||
( V_105 & V_117 ) ) )
F_28 ( V_112 -> V_114 , & V_104 ) ;
}
}
static void F_29 ( struct V_109 * V_110 ,
struct V_12 * V_118 , T_6 V_119 ,
const struct V_120 * V_121 , unsigned int V_122 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = NULL ;
T_6 V_105 = V_117 ;
unsigned int V_43 ;
T_5 V_86 = 0 ;
for ( V_43 = 0 ; V_43 < V_122 ; V_43 ++ ) {
if ( V_121 [ V_43 ] . V_14 == V_119 )
return;
}
F_11 ( V_118 -> V_28 , V_119 , & V_2 , & V_13 , 0 ) ;
if ( V_13 == NULL )
return;
if ( F_18 ( V_110 -> V_48 , V_13 , V_2 , & V_86 ) == 0 )
V_105 |= V_123 ;
F_26 ( V_110 , V_13 , V_2 , V_86 , V_105 ) ;
}
static void F_30 ( struct V_109 * V_110 ,
const struct V_120 * V_121 , unsigned int V_122 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
T_6 V_105 = V_123 ;
unsigned int V_43 ;
unsigned int V_124 ;
for ( V_43 = 0 ; V_43 < V_122 ; ++ V_43 ) {
V_13 = F_13 ( V_110 -> V_48 , V_121 [ V_43 ] . V_14 , & V_2 ) ;
for ( V_124 = 0 ; V_124 < F_31 ( V_2 -> V_125 ) ; ++ V_124 ) {
if ( ! V_2 -> V_125 [ V_124 ] )
break;
F_29 ( V_110 , V_13 ,
V_2 -> V_125 [ V_124 ] ,
V_121 , V_122 ) ;
}
if ( V_2 -> V_85 ) {
for ( V_124 = 0 ; V_124 < V_122 ; V_124 ++ ) {
if ( V_121 [ V_124 ] . V_14 == V_2 -> V_85 ) {
V_105 |= V_117 ;
break;
}
}
}
F_26 ( V_110 , V_13 , V_2 , V_121 [ V_43 ] . V_11 ,
V_105 ) ;
}
}
static int F_32 ( struct V_111 * V_112 , unsigned V_126 )
{
struct V_109 * V_110 = F_33 ( V_112 -> V_114 , struct V_109 , V_115 ) ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_52 ;
V_52 = F_22 ( & V_110 -> V_48 -> V_94 ) ;
if ( V_52 < 0 )
return - V_95 ;
V_13 = F_13 ( V_110 -> V_48 , V_112 -> V_14 , & V_2 ) ;
if ( V_13 == NULL ) {
V_52 = - V_96 ;
goto V_97;
}
F_34 ( & V_112 -> V_127 , & V_2 -> V_113 ) ;
if ( V_112 -> V_53 & V_128 ) {
struct V_103 V_104 ;
T_6 V_105 = V_117 ;
T_5 V_86 = 0 ;
if ( F_18 ( V_110 -> V_48 , V_13 , V_2 , & V_86 ) == 0 )
V_105 |= V_123 ;
F_25 ( V_110 -> V_48 , & V_104 , V_13 , V_2 , V_86 ,
V_105 ) ;
V_112 -> V_126 = V_126 ;
F_28 ( V_112 -> V_114 , & V_104 ) ;
}
V_97:
F_23 ( & V_110 -> V_48 -> V_94 ) ;
return V_52 ;
}
static void F_35 ( struct V_111 * V_112 )
{
struct V_109 * V_110 = F_33 ( V_112 -> V_114 , struct V_109 , V_115 ) ;
F_36 ( & V_110 -> V_48 -> V_94 ) ;
F_37 ( & V_112 -> V_127 ) ;
F_23 ( & V_110 -> V_48 -> V_94 ) ;
}
int F_38 ( struct V_47 * V_48 )
{
return F_22 ( & V_48 -> V_94 ) ? - V_95 : 0 ;
}
static int F_39 ( struct V_129 * V_55 ,
struct V_27 * V_28 , int V_130 )
{
struct V_12 * V_13 ;
unsigned int V_43 ;
int V_52 ;
if ( V_28 == NULL )
return 0 ;
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( ! V_13 -> V_46 )
continue;
if ( V_13 -> V_16 . V_53 & V_131 ||
! ( V_13 -> V_16 . V_53 & V_69 ) )
V_13 -> V_71 = 0 ;
if ( ! V_13 -> V_132 )
continue;
if ( ! V_130 )
V_52 = F_16 ( V_55 , V_133 , V_13 -> V_28 -> V_14 ,
V_55 -> V_56 , V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_72 ) ,
V_13 -> V_16 . V_17 ) ;
else
V_52 = 0 ;
if ( V_130 || V_52 < 0 )
memcpy ( F_4 ( V_13 , V_72 ) ,
F_4 ( V_13 , V_134 ) ,
V_13 -> V_16 . V_17 ) ;
V_13 -> V_132 = 0 ;
if ( V_52 < 0 )
return V_52 ;
}
return 0 ;
}
int F_40 ( struct V_109 * V_110 , int V_130 ,
const struct V_120 * V_121 ,
unsigned int V_122 )
{
struct V_47 * V_48 = V_110 -> V_48 ;
struct V_27 * V_28 ;
int V_52 = 0 ;
F_12 (entity, &chain->entities, chain) {
V_52 = F_39 ( V_48 -> V_55 , V_28 , V_130 ) ;
if ( V_52 < 0 )
goto V_97;
}
if ( ! V_130 )
F_30 ( V_110 , V_121 , V_122 ) ;
V_97:
F_23 ( & V_48 -> V_94 ) ;
return V_52 ;
}
int F_41 ( struct V_47 * V_48 ,
struct V_120 * V_135 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
V_13 = F_13 ( V_48 , V_135 -> V_14 , & V_2 ) ;
if ( V_13 == NULL )
return - V_96 ;
return F_18 ( V_48 , V_13 , V_2 , & V_135 -> V_11 ) ;
}
int F_42 ( struct V_47 * V_48 ,
struct V_120 * V_135 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
T_5 V_11 ;
T_6 V_92 ;
T_5 F_3 ;
T_5 V_136 ;
int V_52 ;
V_13 = F_13 ( V_48 , V_135 -> V_14 , & V_2 ) ;
if ( V_13 == NULL )
return - V_96 ;
if ( ! ( V_13 -> V_16 . V_53 & V_83 ) )
return - V_70 ;
switch ( V_2 -> V_25 ) {
case V_137 :
if ( ! V_13 -> V_66 ) {
V_52 = F_15 ( V_48 , V_13 ) ;
if ( V_52 < 0 )
return V_52 ;
}
F_3 = V_2 -> V_73 ( V_2 , V_7 ,
F_4 ( V_13 , V_60 ) ) ;
V_136 = V_2 -> V_73 ( V_2 , V_8 ,
F_4 ( V_13 , V_62 ) ) ;
V_92 = V_2 -> V_73 ( V_2 , V_9 ,
F_4 ( V_13 , V_64 ) ) ;
if ( V_92 == 0 )
V_92 = 1 ;
V_135 -> V_11 = F_3 + ( ( T_6 ) ( V_135 -> V_11 - F_3 ) + V_92 / 2 )
/ V_92 * V_92 ;
if ( V_2 -> V_23 == V_24 )
V_135 -> V_11 = F_43 ( V_135 -> V_11 , F_3 , V_136 ) ;
else
V_135 -> V_11 = F_44 ( T_6 , V_135 -> V_11 , F_3 , V_136 ) ;
V_11 = V_135 -> V_11 ;
break;
case V_93 :
V_135 -> V_11 = F_43 ( V_135 -> V_11 , 0 , 1 ) ;
V_11 = V_135 -> V_11 ;
break;
case V_74 :
if ( V_135 -> V_11 < 0 || V_135 -> V_11 >= V_2 -> V_76 )
return - V_138 ;
V_11 = V_2 -> V_75 [ V_135 -> V_11 ] . V_11 ;
if ( V_2 -> V_23 == V_101 &&
( V_13 -> V_16 . V_53 & V_63 ) ) {
if ( ! V_13 -> V_66 ) {
V_52 = F_15 ( V_48 , V_13 ) ;
if ( V_52 < 0 )
return V_52 ;
}
V_92 = V_2 -> V_73 ( V_2 , V_9 ,
F_4 ( V_13 , V_64 ) ) ;
if ( ! ( V_92 & V_11 ) )
return - V_138 ;
}
break;
default:
V_11 = V_135 -> V_11 ;
break;
}
if ( ! V_13 -> V_71 && ( V_13 -> V_16 . V_17 * 8 ) != V_2 -> V_17 ) {
if ( ( V_13 -> V_16 . V_53 & V_69 ) == 0 ) {
memset ( F_4 ( V_13 , V_72 ) ,
0 , V_13 -> V_16 . V_17 ) ;
} else {
V_52 = F_16 ( V_48 -> V_55 , V_6 ,
V_13 -> V_28 -> V_14 , V_48 -> V_55 -> V_56 ,
V_13 -> V_16 . V_57 ,
F_4 ( V_13 , V_72 ) ,
V_13 -> V_16 . V_17 ) ;
if ( V_52 < 0 )
return V_52 ;
}
V_13 -> V_71 = 1 ;
}
if ( ! V_13 -> V_132 ) {
memcpy ( F_4 ( V_13 , V_134 ) ,
F_4 ( V_13 , V_72 ) ,
V_13 -> V_16 . V_17 ) ;
}
V_2 -> V_139 ( V_2 , V_11 ,
F_4 ( V_13 , V_72 ) ) ;
V_13 -> V_132 = 1 ;
V_13 -> V_140 = 1 ;
return 0 ;
}
static void F_45 ( struct V_129 * V_55 ,
const struct V_12 * V_13 , struct V_141 * V_16 )
{
struct V_142 {
struct V_143 V_14 ;
T_7 V_28 ;
T_7 V_57 ;
T_7 V_53 ;
};
static const struct V_142 V_144 [] = {
{ { F_46 ( 0x046d , 0x08c2 ) } , 9 , 1 ,
V_59 | V_61 |
V_54 | V_83 |
V_131 } ,
{ { F_46 ( 0x046d , 0x08cc ) } , 9 , 1 ,
V_59 | V_61 |
V_54 | V_83 |
V_131 } ,
{ { F_46 ( 0x046d , 0x0994 ) } , 9 , 1 ,
V_59 | V_61 |
V_54 | V_83 |
V_131 } ,
} ;
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < F_31 ( V_144 ) ; ++ V_43 ) {
if ( ! F_47 ( V_55 -> V_145 , & V_144 [ V_43 ] . V_14 ) )
continue;
if ( V_144 [ V_43 ] . V_28 == V_13 -> V_28 -> V_14 &&
V_144 [ V_43 ] . V_57 == V_16 -> V_57 ) {
V_16 -> V_53 = V_144 [ V_43 ] . V_53 ;
return;
}
}
}
static int F_48 ( struct V_129 * V_55 ,
const struct V_12 * V_13 , struct V_141 * V_16 )
{
T_7 * V_4 ;
int V_52 ;
V_4 = F_49 ( 2 , V_146 ) ;
if ( V_4 == NULL )
return - V_147 ;
memcpy ( V_16 -> V_28 , V_13 -> V_28 -> V_37 . V_38 ,
sizeof( V_16 -> V_28 ) ) ;
V_16 -> V_100 = V_13 -> V_100 ;
V_16 -> V_57 = V_13 -> V_100 + 1 ;
V_52 = F_16 ( V_55 , V_148 , V_13 -> V_28 -> V_14 , V_55 -> V_56 ,
V_16 -> V_57 , V_4 , 2 ) ;
if ( V_52 < 0 ) {
F_14 ( V_51 ,
L_4 ,
V_16 -> V_28 , V_16 -> V_57 , V_52 ) ;
goto V_97;
}
V_16 -> V_17 = F_50 ( ( V_149 * ) V_4 ) ;
V_52 = F_16 ( V_55 , V_150 , V_13 -> V_28 -> V_14 , V_55 -> V_56 ,
V_16 -> V_57 , V_4 , 1 ) ;
if ( V_52 < 0 ) {
F_14 ( V_51 ,
L_5 ,
V_16 -> V_28 , V_16 -> V_57 , V_52 ) ;
goto V_97;
}
V_16 -> V_53 = V_59 | V_61
| V_63 | V_54
| ( V_4 [ 0 ] & V_151 ?
V_69 : 0 )
| ( V_4 [ 0 ] & V_152 ?
V_83 : 0 )
| ( V_4 [ 0 ] & V_153 ?
V_131 : 0 ) ;
F_45 ( V_55 , V_13 , V_16 ) ;
F_14 ( V_51 , L_6
L_7 ,
V_16 -> V_28 , V_16 -> V_57 , V_16 -> V_17 ,
( V_16 -> V_53 & V_69 ) ? 1 : 0 ,
( V_16 -> V_53 & V_83 ) ? 1 : 0 ,
( V_16 -> V_53 & V_131 ) ? 1 : 0 ) ;
V_97:
F_51 ( V_4 ) ;
return V_52 ;
}
static int F_52 ( struct V_129 * V_55 ,
struct V_12 * V_13 )
{
struct V_141 V_16 ;
int V_52 ;
if ( V_13 -> V_46 )
return 0 ;
V_52 = F_48 ( V_55 , V_13 , & V_16 ) ;
if ( V_52 < 0 )
return V_52 ;
V_52 = F_53 ( V_55 , V_13 , & V_16 ) ;
if ( V_52 < 0 )
F_14 ( V_51 , L_8
L_9 , V_16 . V_28 ,
V_16 . V_57 , V_55 -> V_154 -> V_155 , V_13 -> V_28 -> V_14 ) ;
return V_52 ;
}
int F_54 ( struct V_47 * V_48 ,
struct V_156 * V_157 )
{
struct V_27 * V_28 ;
struct V_12 * V_13 ;
unsigned int V_43 , V_158 = 0 ;
T_4 V_159 ;
T_8 V_17 ;
T_2 * V_4 = NULL ;
int V_52 ;
F_12 (entity, &chain->entities, chain) {
if ( F_10 ( V_28 ) == V_36 &&
V_28 -> V_14 == V_157 -> V_160 )
break;
}
if ( V_28 -> V_14 != V_157 -> V_160 ) {
F_14 ( V_51 , L_10 ,
V_157 -> V_160 ) ;
return - V_161 ;
}
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( V_13 -> V_100 == V_157 -> V_57 - 1 ) {
V_158 = 1 ;
break;
}
}
if ( ! V_158 ) {
F_14 ( V_51 , L_11 ,
V_28 -> V_37 . V_38 , V_157 -> V_57 ) ;
return - V_161 ;
}
if ( F_22 ( & V_48 -> V_94 ) )
return - V_95 ;
V_52 = F_52 ( V_48 -> V_55 , V_13 ) ;
if ( V_52 < 0 ) {
V_52 = - V_161 ;
goto V_97;
}
V_159 = 0 ;
V_17 = V_13 -> V_16 . V_17 ;
switch ( V_157 -> V_3 ) {
case V_6 :
V_159 = V_69 ;
break;
case V_7 :
V_159 = V_59 ;
break;
case V_8 :
V_159 = V_61 ;
break;
case V_10 :
V_159 = V_54 ;
break;
case V_9 :
V_159 = V_63 ;
break;
case V_133 :
V_159 = V_83 ;
break;
case V_148 :
V_17 = 2 ;
break;
case V_150 :
V_17 = 1 ;
break;
default:
V_52 = - V_96 ;
goto V_97;
}
if ( V_17 != V_157 -> V_17 ) {
V_52 = - V_162 ;
goto V_97;
}
if ( V_159 && ! ( V_13 -> V_16 . V_53 & V_159 ) ) {
V_52 = - V_163 ;
goto V_97;
}
V_4 = F_49 ( V_17 , V_146 ) ;
if ( V_4 == NULL ) {
V_52 = - V_147 ;
goto V_97;
}
if ( V_157 -> V_3 == V_133 &&
F_55 ( V_4 , V_157 -> V_4 , V_17 ) ) {
V_52 = - V_164 ;
goto V_97;
}
V_52 = F_16 ( V_48 -> V_55 , V_157 -> V_3 , V_157 -> V_160 ,
V_48 -> V_55 -> V_56 , V_157 -> V_57 , V_4 , V_17 ) ;
if ( V_52 < 0 )
goto V_97;
if ( V_157 -> V_3 != V_133 &&
F_56 ( V_157 -> V_4 , V_4 , V_17 ) )
V_52 = - V_164 ;
V_97:
F_51 ( V_4 ) ;
F_23 ( & V_48 -> V_94 ) ;
return V_52 ;
}
int F_57 ( struct V_129 * V_55 )
{
struct V_12 * V_13 ;
struct V_27 * V_28 ;
unsigned int V_43 ;
int V_52 ;
F_12 (entity, &dev->entities, list) {
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( ! V_13 -> V_46 || ! V_13 -> V_140 ||
( V_13 -> V_16 . V_53 & V_165 ) == 0 )
continue;
F_58 ( V_166 L_12 ,
V_13 -> V_16 . V_28 , V_13 -> V_16 . V_100 ,
V_13 -> V_16 . V_57 ) ;
V_13 -> V_132 = 1 ;
}
V_52 = F_39 ( V_55 , V_28 , 0 ) ;
if ( V_52 < 0 )
return V_52 ;
}
return 0 ;
}
static int F_53 ( struct V_129 * V_55 , struct V_12 * V_13 ,
const struct V_141 * V_16 )
{
int V_52 = 0 ;
V_13 -> V_16 = * V_16 ;
F_59 ( & V_13 -> V_16 . V_167 ) ;
V_13 -> V_15 = F_60 ( V_13 -> V_16 . V_17 * V_168 + 1 ,
V_146 ) ;
if ( V_13 -> V_15 == NULL ) {
V_52 = - V_147 ;
goto V_97;
}
V_13 -> V_46 = 1 ;
F_14 ( V_51 , L_13
L_14 , V_13 -> V_16 . V_28 , V_13 -> V_16 . V_57 ,
V_55 -> V_154 -> V_155 , V_13 -> V_28 -> V_14 ) ;
V_97:
if ( V_52 < 0 )
F_51 ( V_13 -> V_15 ) ;
return V_52 ;
}
static int F_61 ( struct V_129 * V_55 ,
struct V_12 * V_13 , const struct V_1 * V_2 )
{
struct V_1 * V_42 ;
unsigned int V_17 ;
V_42 = F_62 ( V_2 , sizeof( * V_2 ) , V_146 ) ;
if ( V_42 == NULL )
return - V_147 ;
F_59 ( & V_42 -> V_113 ) ;
V_17 = sizeof( * V_2 -> V_75 ) * V_2 -> V_76 ;
V_42 -> V_75 = F_62 ( V_2 -> V_75 , V_17 , V_146 ) ;
if ( V_42 -> V_75 == NULL ) {
F_51 ( V_42 ) ;
return - V_147 ;
}
if ( V_42 -> V_73 == NULL )
V_42 -> V_73 = F_7 ;
if ( V_42 -> V_139 == NULL )
V_42 -> V_139 = F_8 ;
F_34 ( & V_42 -> V_169 , & V_13 -> V_16 . V_167 ) ;
F_14 ( V_51 ,
L_15 ,
V_42 -> V_81 , V_13 -> V_16 . V_28 , V_13 -> V_16 . V_57 ) ;
return 0 ;
}
int F_63 ( struct V_47 * V_48 ,
const struct V_1 * V_2 )
{
struct V_129 * V_55 = V_48 -> V_55 ;
struct V_1 * V_42 ;
struct V_27 * V_28 ;
struct V_12 * V_13 ;
int V_158 = 0 ;
int V_52 ;
if ( V_2 -> V_14 & ~ V_50 ) {
F_14 ( V_51 , L_16
L_17 , V_2 -> V_81 ,
V_2 -> V_14 ) ;
return - V_96 ;
}
F_12 (entity, &chain->entities, chain) {
unsigned int V_43 ;
if ( F_10 ( V_28 ) != V_36 ||
! F_9 ( V_28 , V_2 -> V_28 ) )
continue;
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( V_13 -> V_100 == V_2 -> V_57 - 1 ) {
V_158 = 1 ;
break;
}
}
if ( V_158 )
break;
}
if ( ! V_158 )
return - V_161 ;
if ( F_22 ( & V_48 -> V_94 ) )
return - V_95 ;
V_52 = F_52 ( V_55 , V_13 ) ;
if ( V_52 < 0 ) {
V_52 = - V_161 ;
goto V_97;
}
F_12 (map, &ctrl->info.mappings, list) {
if ( V_2 -> V_14 == V_42 -> V_14 ) {
F_14 ( V_51 , L_18
L_19 ,
V_2 -> V_81 , V_2 -> V_14 ) ;
V_52 = - V_170 ;
goto V_97;
}
}
if ( F_64 ( & V_55 -> V_171 ) > V_172 ) {
F_65 ( & V_55 -> V_171 ) ;
F_14 ( V_51 , L_20
L_21 , V_2 -> V_81 ,
V_172 ) ;
V_52 = - V_147 ;
goto V_97;
}
V_52 = F_61 ( V_55 , V_13 , V_2 ) ;
if ( V_52 < 0 )
F_65 ( & V_55 -> V_171 ) ;
V_97:
F_23 ( & V_48 -> V_94 ) ;
return V_52 ;
}
static void F_66 ( struct V_129 * V_55 ,
struct V_27 * V_28 )
{
struct V_173 {
struct V_143 V_14 ;
T_7 V_100 ;
};
static const struct V_173 V_174 [] = {
{ { F_46 ( 0x13d3 , 0x509b ) } , 9 } ,
{ { F_46 ( 0x1c4f , 0x3000 ) } , 6 } ,
{ { F_46 ( 0x5986 , 0x0241 ) } , 2 } ,
} ;
static const struct V_173 V_175 [] = {
{ { F_46 ( 0x06f8 , 0x3005 ) } , 9 } ,
} ;
const struct V_173 * V_176 ;
unsigned int V_17 ;
unsigned int V_177 ;
unsigned int V_43 ;
T_7 * V_45 ;
switch ( F_10 ( V_28 ) ) {
case V_34 :
V_176 = V_174 ;
V_177 = F_31 ( V_174 ) ;
V_45 = V_28 -> V_178 . V_179 ;
V_17 = V_28 -> V_178 . V_180 ;
break;
case V_30 :
V_176 = V_175 ;
V_177 = F_31 ( V_175 ) ;
V_45 = V_28 -> V_181 . V_179 ;
V_17 = V_28 -> V_181 . V_180 ;
break;
default:
return;
}
for ( V_43 = 0 ; V_43 < V_177 ; ++ V_43 ) {
if ( ! F_47 ( V_55 -> V_145 , & V_176 [ V_43 ] . V_14 ) )
continue;
if ( V_176 [ V_43 ] . V_100 >= 8 * V_17 ||
! F_5 ( V_45 , V_176 [ V_43 ] . V_100 ) )
continue;
F_14 ( V_51 , L_22
L_23 , V_28 -> V_14 , V_176 [ V_43 ] . V_100 ) ;
F_6 ( V_45 , V_176 [ V_43 ] . V_100 ) ;
}
}
static void F_67 ( struct V_129 * V_55 , struct V_12 * V_13 )
{
const struct V_141 * V_16 = V_182 ;
const struct V_141 * V_183 = V_16 + F_31 ( V_182 ) ;
const struct V_1 * V_2 = V_184 ;
const struct V_1 * V_185 =
V_2 + F_31 ( V_184 ) ;
if ( F_10 ( V_13 -> V_28 ) == V_36 )
return;
for (; V_16 < V_183 ; ++ V_16 ) {
if ( F_9 ( V_13 -> V_28 , V_16 -> V_28 ) &&
V_13 -> V_100 == V_16 -> V_100 ) {
F_53 ( V_55 , V_13 , V_16 ) ;
break;
}
}
if ( ! V_13 -> V_46 )
return;
for (; V_2 < V_185 ; ++ V_2 ) {
if ( F_9 ( V_13 -> V_28 , V_2 -> V_28 ) &&
V_13 -> V_16 . V_57 == V_2 -> V_57 )
F_61 ( V_55 , V_13 , V_2 ) ;
}
}
int F_68 ( struct V_129 * V_55 )
{
struct V_27 * V_28 ;
unsigned int V_43 ;
F_12 (entity, &dev->entities, list) {
struct V_12 * V_13 ;
unsigned int V_180 = 0 , V_44 ;
T_2 * V_179 = NULL ;
if ( F_10 ( V_28 ) == V_36 ) {
V_179 = V_28 -> V_37 . V_179 ;
V_180 = V_28 -> V_37 . V_180 ;
} else if ( F_10 ( V_28 ) == V_34 ) {
V_179 = V_28 -> V_178 . V_179 ;
V_180 = V_28 -> V_178 . V_180 ;
} else if ( F_10 ( V_28 ) == V_30 ) {
V_179 = V_28 -> V_181 . V_179 ;
V_180 = V_28 -> V_181 . V_180 ;
}
F_66 ( V_55 , V_28 ) ;
V_44 = F_69 ( V_179 , V_180 ) ;
if ( V_44 == 0 )
continue;
V_28 -> V_45 = F_70 ( V_44 , sizeof( * V_13 ) ,
V_146 ) ;
if ( V_28 -> V_45 == NULL )
return - V_147 ;
V_28 -> V_44 = V_44 ;
V_13 = V_28 -> V_45 ;
for ( V_43 = 0 ; V_43 < V_180 * 8 ; ++ V_43 ) {
if ( F_5 ( V_179 , V_43 ) == 0 )
continue;
V_13 -> V_28 = V_28 ;
V_13 -> V_100 = V_43 ;
F_67 ( V_55 , V_13 ) ;
V_13 ++ ;
}
}
return 0 ;
}
static void F_71 ( struct V_129 * V_55 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 , * V_186 ;
F_72 (mapping, nm, &ctrl->info.mappings, list) {
F_37 ( & V_2 -> V_169 ) ;
F_51 ( V_2 -> V_75 ) ;
F_51 ( V_2 ) ;
}
}
void F_73 ( struct V_129 * V_55 )
{
struct V_27 * V_28 ;
unsigned int V_43 ;
F_12 (entity, &dev->entities, list) {
for ( V_43 = 0 ; V_43 < V_28 -> V_44 ; ++ V_43 ) {
struct V_12 * V_13 = & V_28 -> V_45 [ V_43 ] ;
if ( ! V_13 -> V_46 )
continue;
F_71 ( V_55 , V_13 ) ;
F_51 ( V_13 -> V_15 ) ;
}
F_51 ( V_28 -> V_45 ) ;
}
}
