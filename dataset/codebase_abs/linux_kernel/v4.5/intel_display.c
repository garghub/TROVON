static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 [] = { 800 , 1600 , 2000 , 2400 } ;
F_2 ( & V_2 -> V_5 ) ;
V_3 = F_3 ( V_2 , V_6 ) &
V_7 ;
F_4 ( & V_2 -> V_5 ) ;
return V_4 [ V_3 ] * 1000 ;
}
static int F_5 ( struct V_1 * V_2 ,
const char * V_8 , T_1 V_9 )
{
T_1 V_10 ;
int V_11 ;
if ( V_2 -> V_3 == 0 )
V_2 -> V_3 = F_1 ( V_2 ) ;
F_2 ( & V_2 -> V_5 ) ;
V_10 = F_3 ( V_2 , V_9 ) ;
F_4 ( & V_2 -> V_5 ) ;
V_11 = V_10 & V_12 ;
F_6 ( ( V_10 & V_13 ) !=
( V_11 << V_14 ) ,
L_1 , V_8 ) ;
return F_7 ( V_2 -> V_3 << 1 , V_11 + 1 ) ;
}
int
F_8 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
F_9 ( ! F_10 ( V_16 ) ) ;
return F_11 ( V_18 ) & V_19 ;
}
int F_12 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_20 ;
if ( F_13 ( V_16 ) || F_14 ( V_16 ) )
return 200 ;
V_20 = F_11 ( V_21 ) ;
switch ( V_20 & V_22 ) {
case V_23 :
return 100 ;
case V_24 :
return 133 ;
case V_25 :
return 166 ;
case V_26 :
return 200 ;
case V_27 :
return 266 ;
case V_28 :
return 333 ;
case V_29 :
case V_30 :
return 400 ;
default:
return 133 ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
if ( ! ( F_13 ( V_2 ) || F_14 ( V_2 ) ) )
return;
V_2 -> V_31 = F_5 ( V_2 , L_2 ,
V_32 ) ;
F_16 ( L_3 , V_2 -> V_31 ) ;
}
static inline T_1
F_17 ( struct V_15 * V_16 )
{
if ( F_18 ( V_16 ) ) {
struct V_1 * V_2 = V_16 -> V_17 ;
return ( F_11 ( V_33 ) & V_34 ) + 2 ;
} else
return 27 ;
}
static bool
F_19 ( struct V_35 * V_36 )
{
return F_20 ( V_36 ) ;
}
bool F_21 ( struct V_37 * V_38 , enum V_39 type )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_41 * V_42 ;
F_22 (dev, &crtc->base, encoder)
if ( V_42 -> type == type )
return true ;
return false ;
}
static bool F_23 ( const struct V_43 * V_44 ,
int type )
{
struct V_45 * V_36 = V_44 -> V_40 . V_36 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_41 * V_42 ;
int V_50 , V_51 = 0 ;
F_24 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != V_44 -> V_40 . V_38 )
continue;
V_51 ++ ;
V_42 = F_25 ( V_49 -> V_52 ) ;
if ( V_42 -> type == type )
return true ;
}
F_9 ( V_51 == 0 ) ;
return false ;
}
static const T_3 *
F_26 ( struct V_43 * V_44 , int V_53 )
{
struct V_15 * V_16 = V_44 -> V_40 . V_38 -> V_16 ;
const T_3 * V_54 ;
if ( F_23 ( V_44 , V_55 ) ) {
if ( F_27 ( V_16 ) ) {
if ( V_53 == 100000 )
V_54 = & V_56 ;
else
V_54 = & V_57 ;
} else {
if ( V_53 == 100000 )
V_54 = & V_58 ;
else
V_54 = & V_59 ;
}
} else
V_54 = & V_60 ;
return V_54 ;
}
static const T_3 *
F_28 ( struct V_43 * V_44 )
{
struct V_15 * V_16 = V_44 -> V_40 . V_38 -> V_16 ;
const T_3 * V_54 ;
if ( F_23 ( V_44 , V_55 ) ) {
if ( F_27 ( V_16 ) )
V_54 = & V_61 ;
else
V_54 = & V_62 ;
} else if ( F_23 ( V_44 , V_63 ) ||
F_23 ( V_44 , V_64 ) ) {
V_54 = & V_65 ;
} else if ( F_23 ( V_44 , V_66 ) ) {
V_54 = & V_67 ;
} else
V_54 = & V_68 ;
return V_54 ;
}
static const T_3 *
F_29 ( struct V_43 * V_44 , int V_53 )
{
struct V_15 * V_16 = V_44 -> V_40 . V_38 -> V_16 ;
const T_3 * V_54 ;
if ( F_30 ( V_16 ) )
V_54 = & V_69 ;
else if ( F_10 ( V_16 ) )
V_54 = F_26 ( V_44 , V_53 ) ;
else if ( F_31 ( V_16 ) ) {
V_54 = F_28 ( V_44 ) ;
} else if ( F_32 ( V_16 ) ) {
if ( F_23 ( V_44 , V_55 ) )
V_54 = & V_70 ;
else
V_54 = & V_71 ;
} else if ( F_14 ( V_16 ) ) {
V_54 = & V_72 ;
} else if ( F_13 ( V_16 ) ) {
V_54 = & V_73 ;
} else if ( ! F_33 ( V_16 ) ) {
if ( F_23 ( V_44 , V_55 ) )
V_54 = & V_74 ;
else
V_54 = & V_68 ;
} else {
if ( F_23 ( V_44 , V_55 ) )
V_54 = & V_75 ;
else if ( F_23 ( V_44 , V_76 ) )
V_54 = & V_77 ;
else
V_54 = & V_78 ;
}
return V_54 ;
}
static int F_34 ( int V_53 , T_4 * clock )
{
clock -> V_79 = clock -> V_80 + 2 ;
clock -> V_81 = clock -> V_82 * clock -> V_83 ;
if ( F_9 ( clock -> V_84 == 0 || clock -> V_81 == 0 ) )
return 0 ;
clock -> V_85 = F_7 ( V_53 * clock -> V_79 , clock -> V_84 ) ;
clock -> V_86 = F_7 ( clock -> V_85 , clock -> V_81 ) ;
return clock -> V_86 ;
}
static T_2 F_35 ( struct V_87 * V_87 )
{
return 5 * ( V_87 -> V_88 + 2 ) + ( V_87 -> V_80 + 2 ) ;
}
static int F_36 ( int V_53 , T_4 * clock )
{
clock -> V_79 = F_35 ( clock ) ;
clock -> V_81 = clock -> V_82 * clock -> V_83 ;
if ( F_9 ( clock -> V_84 + 2 == 0 || clock -> V_81 == 0 ) )
return 0 ;
clock -> V_85 = F_7 ( V_53 * clock -> V_79 , clock -> V_84 + 2 ) ;
clock -> V_86 = F_7 ( clock -> V_85 , clock -> V_81 ) ;
return clock -> V_86 ;
}
static int F_37 ( int V_53 , T_4 * clock )
{
clock -> V_79 = clock -> V_88 * clock -> V_80 ;
clock -> V_81 = clock -> V_82 * clock -> V_83 ;
if ( F_9 ( clock -> V_84 == 0 || clock -> V_81 == 0 ) )
return 0 ;
clock -> V_85 = F_7 ( V_53 * clock -> V_79 , clock -> V_84 ) ;
clock -> V_86 = F_7 ( clock -> V_85 , clock -> V_81 ) ;
return clock -> V_86 / 5 ;
}
int F_38 ( int V_53 , T_4 * clock )
{
clock -> V_79 = clock -> V_88 * clock -> V_80 ;
clock -> V_81 = clock -> V_82 * clock -> V_83 ;
if ( F_9 ( clock -> V_84 == 0 || clock -> V_81 == 0 ) )
return 0 ;
clock -> V_85 = F_39 ( ( V_89 ) V_53 * clock -> V_79 ,
clock -> V_84 << 22 ) ;
clock -> V_86 = F_7 ( clock -> V_85 , clock -> V_81 ) ;
return clock -> V_86 / 5 ;
}
static bool F_40 ( struct V_15 * V_16 ,
const T_3 * V_54 ,
const T_4 * clock )
{
if ( clock -> V_84 < V_54 -> V_84 . V_90 || V_54 -> V_84 . V_91 < clock -> V_84 )
F_41 ( L_4 ) ;
if ( clock -> V_82 < V_54 -> V_82 . V_90 || V_54 -> V_82 . V_91 < clock -> V_82 )
F_41 ( L_5 ) ;
if ( clock -> V_80 < V_54 -> V_80 . V_90 || V_54 -> V_80 . V_91 < clock -> V_80 )
F_41 ( L_6 ) ;
if ( clock -> V_88 < V_54 -> V_88 . V_90 || V_54 -> V_88 . V_91 < clock -> V_88 )
F_41 ( L_7 ) ;
if ( ! F_32 ( V_16 ) && ! F_13 ( V_16 ) &&
! F_14 ( V_16 ) && ! F_30 ( V_16 ) )
if ( clock -> V_88 <= clock -> V_80 )
F_41 ( L_8 ) ;
if ( ! F_13 ( V_16 ) && ! F_14 ( V_16 ) && ! F_30 ( V_16 ) ) {
if ( clock -> V_81 < V_54 -> V_81 . V_90 || V_54 -> V_81 . V_91 < clock -> V_81 )
F_41 ( L_9 ) ;
if ( clock -> V_79 < V_54 -> V_79 . V_90 || V_54 -> V_79 . V_91 < clock -> V_79 )
F_41 ( L_10 ) ;
}
if ( clock -> V_85 < V_54 -> V_85 . V_90 || V_54 -> V_85 . V_91 < clock -> V_85 )
F_41 ( L_11 ) ;
if ( clock -> V_86 < V_54 -> V_86 . V_90 || V_54 -> V_86 . V_91 < clock -> V_86 )
F_41 ( L_12 ) ;
return true ;
}
static int
F_42 ( const T_3 * V_54 ,
const struct V_43 * V_44 ,
int V_92 )
{
struct V_15 * V_16 = V_44 -> V_40 . V_38 -> V_16 ;
if ( F_23 ( V_44 , V_55 ) ) {
if ( F_27 ( V_16 ) )
return V_54 -> V_83 . V_93 ;
else
return V_54 -> V_83 . V_94 ;
} else {
if ( V_92 < V_54 -> V_83 . V_95 )
return V_54 -> V_83 . V_94 ;
else
return V_54 -> V_83 . V_93 ;
}
}
static bool
F_43 ( const T_3 * V_54 ,
struct V_43 * V_44 ,
int V_92 , int V_53 , T_4 * V_96 ,
T_4 * V_97 )
{
struct V_15 * V_16 = V_44 -> V_40 . V_38 -> V_16 ;
T_4 clock ;
int V_98 = V_92 ;
memset ( V_97 , 0 , sizeof( * V_97 ) ) ;
clock . V_83 = F_42 ( V_54 , V_44 , V_92 ) ;
for ( clock . V_88 = V_54 -> V_88 . V_90 ; clock . V_88 <= V_54 -> V_88 . V_91 ;
clock . V_88 ++ ) {
for ( clock . V_80 = V_54 -> V_80 . V_90 ;
clock . V_80 <= V_54 -> V_80 . V_91 ; clock . V_80 ++ ) {
if ( clock . V_80 >= clock . V_88 )
break;
for ( clock . V_84 = V_54 -> V_84 . V_90 ;
clock . V_84 <= V_54 -> V_84 . V_91 ; clock . V_84 ++ ) {
for ( clock . V_82 = V_54 -> V_82 . V_90 ;
clock . V_82 <= V_54 -> V_82 . V_91 ; clock . V_82 ++ ) {
int V_99 ;
F_36 ( V_53 , & clock ) ;
if ( ! F_40 ( V_16 , V_54 ,
& clock ) )
continue;
if ( V_96 &&
clock . V_81 != V_96 -> V_81 )
continue;
V_99 = abs ( clock . V_86 - V_92 ) ;
if ( V_99 < V_98 ) {
* V_97 = clock ;
V_98 = V_99 ;
}
}
}
}
}
return ( V_98 != V_92 ) ;
}
static bool
F_44 ( const T_3 * V_54 ,
struct V_43 * V_44 ,
int V_92 , int V_53 , T_4 * V_96 ,
T_4 * V_97 )
{
struct V_15 * V_16 = V_44 -> V_40 . V_38 -> V_16 ;
T_4 clock ;
int V_98 = V_92 ;
memset ( V_97 , 0 , sizeof( * V_97 ) ) ;
clock . V_83 = F_42 ( V_54 , V_44 , V_92 ) ;
for ( clock . V_88 = V_54 -> V_88 . V_90 ; clock . V_88 <= V_54 -> V_88 . V_91 ;
clock . V_88 ++ ) {
for ( clock . V_80 = V_54 -> V_80 . V_90 ;
clock . V_80 <= V_54 -> V_80 . V_91 ; clock . V_80 ++ ) {
for ( clock . V_84 = V_54 -> V_84 . V_90 ;
clock . V_84 <= V_54 -> V_84 . V_91 ; clock . V_84 ++ ) {
for ( clock . V_82 = V_54 -> V_82 . V_90 ;
clock . V_82 <= V_54 -> V_82 . V_91 ; clock . V_82 ++ ) {
int V_99 ;
F_34 ( V_53 , & clock ) ;
if ( ! F_40 ( V_16 , V_54 ,
& clock ) )
continue;
if ( V_96 &&
clock . V_81 != V_96 -> V_81 )
continue;
V_99 = abs ( clock . V_86 - V_92 ) ;
if ( V_99 < V_98 ) {
* V_97 = clock ;
V_98 = V_99 ;
}
}
}
}
}
return ( V_98 != V_92 ) ;
}
static bool
F_45 ( const T_3 * V_54 ,
struct V_43 * V_44 ,
int V_92 , int V_53 , T_4 * V_96 ,
T_4 * V_97 )
{
struct V_15 * V_16 = V_44 -> V_40 . V_38 -> V_16 ;
T_4 clock ;
int V_100 ;
bool V_101 = false ;
int V_102 = ( V_92 >> 8 ) + ( V_92 >> 9 ) ;
memset ( V_97 , 0 , sizeof( * V_97 ) ) ;
clock . V_83 = F_42 ( V_54 , V_44 , V_92 ) ;
V_100 = V_54 -> V_84 . V_91 ;
for ( clock . V_84 = V_54 -> V_84 . V_90 ; clock . V_84 <= V_100 ; clock . V_84 ++ ) {
for ( clock . V_88 = V_54 -> V_88 . V_91 ;
clock . V_88 >= V_54 -> V_88 . V_90 ; clock . V_88 -- ) {
for ( clock . V_80 = V_54 -> V_80 . V_91 ;
clock . V_80 >= V_54 -> V_80 . V_90 ; clock . V_80 -- ) {
for ( clock . V_82 = V_54 -> V_82 . V_91 ;
clock . V_82 >= V_54 -> V_82 . V_90 ; clock . V_82 -- ) {
int V_99 ;
F_36 ( V_53 , & clock ) ;
if ( ! F_40 ( V_16 , V_54 ,
& clock ) )
continue;
V_99 = abs ( clock . V_86 - V_92 ) ;
if ( V_99 < V_102 ) {
* V_97 = clock ;
V_102 = V_99 ;
V_100 = clock . V_84 ;
V_101 = true ;
}
}
}
}
}
return V_101 ;
}
static bool F_46 ( struct V_15 * V_16 , int V_103 ,
const T_4 * V_104 ,
const T_4 * V_97 ,
unsigned int V_105 ,
unsigned int * V_106 )
{
if ( F_14 ( V_16 ) ) {
* V_106 = 0 ;
return V_104 -> V_81 > V_97 -> V_81 ;
}
if ( F_47 ( ! V_103 ) )
return false ;
* V_106 = F_48 ( 1000000ULL *
abs ( V_103 - V_104 -> V_86 ) ,
V_103 ) ;
if ( * V_106 < 100 && V_104 -> V_81 > V_97 -> V_81 ) {
* V_106 = 0 ;
return true ;
}
return * V_106 + 10 < V_105 ;
}
static bool
F_49 ( const T_3 * V_54 ,
struct V_43 * V_44 ,
int V_92 , int V_53 , T_4 * V_96 ,
T_4 * V_97 )
{
struct V_37 * V_38 = F_50 ( V_44 -> V_40 . V_38 ) ;
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
T_4 clock ;
unsigned int V_107 = 1000000 ;
int V_100 = V_90 ( V_54 -> V_84 . V_91 , V_53 / 19200 ) ;
bool V_101 = false ;
V_92 *= 5 ;
memset ( V_97 , 0 , sizeof( * V_97 ) ) ;
for ( clock . V_84 = V_54 -> V_84 . V_90 ; clock . V_84 <= V_100 ; clock . V_84 ++ ) {
for ( clock . V_82 = V_54 -> V_82 . V_91 ; clock . V_82 >= V_54 -> V_82 . V_90 ; clock . V_82 -- ) {
for ( clock . V_83 = V_54 -> V_83 . V_93 ; clock . V_83 >= V_54 -> V_83 . V_94 ;
clock . V_83 -= clock . V_83 > 10 ? 2 : 1 ) {
clock . V_81 = clock . V_82 * clock . V_83 ;
for ( clock . V_88 = V_54 -> V_88 . V_90 ; clock . V_88 <= V_54 -> V_88 . V_91 ; clock . V_88 ++ ) {
unsigned int V_108 ;
clock . V_80 = F_7 ( V_92 * clock . V_81 * clock . V_84 ,
V_53 * clock . V_88 ) ;
F_37 ( V_53 , & clock ) ;
if ( ! F_40 ( V_16 , V_54 ,
& clock ) )
continue;
if ( ! F_46 ( V_16 , V_92 ,
& clock ,
V_97 ,
V_107 , & V_108 ) )
continue;
* V_97 = clock ;
V_107 = V_108 ;
V_101 = true ;
}
}
}
}
return V_101 ;
}
static bool
F_51 ( const T_3 * V_54 ,
struct V_43 * V_44 ,
int V_92 , int V_53 , T_4 * V_96 ,
T_4 * V_97 )
{
struct V_37 * V_38 = F_50 ( V_44 -> V_40 . V_38 ) ;
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
unsigned int V_105 ;
T_4 clock ;
V_89 V_80 ;
int V_101 = false ;
memset ( V_97 , 0 , sizeof( * V_97 ) ) ;
V_105 = 1000000 ;
clock . V_84 = 1 , clock . V_88 = 2 ;
V_92 *= 5 ;
for ( clock . V_82 = V_54 -> V_82 . V_91 ; clock . V_82 >= V_54 -> V_82 . V_90 ; clock . V_82 -- ) {
for ( clock . V_83 = V_54 -> V_83 . V_93 ;
clock . V_83 >= V_54 -> V_83 . V_94 ;
clock . V_83 -= clock . V_83 > 10 ? 2 : 1 ) {
unsigned int V_106 ;
clock . V_81 = clock . V_82 * clock . V_83 ;
V_80 = F_39 ( ( ( V_89 ) V_92 * clock . V_81 *
clock . V_84 ) << 22 , V_53 * clock . V_88 ) ;
if ( V_80 > V_109 / clock . V_88 )
continue;
clock . V_80 = V_80 ;
F_38 ( V_53 , & clock ) ;
if ( ! F_40 ( V_16 , V_54 , & clock ) )
continue;
if ( ! F_46 ( V_16 , V_92 , & clock , V_97 ,
V_105 , & V_106 ) )
continue;
* V_97 = clock ;
V_105 = V_106 ;
V_101 = true ;
}
}
return V_101 ;
}
bool F_52 ( struct V_43 * V_44 , int V_110 ,
T_4 * V_97 )
{
int V_53 = F_53 ( V_44 , 0 ) ;
return F_51 ( F_29 ( V_44 , V_53 ) , V_44 ,
V_110 , V_53 , NULL , V_97 ) ;
}
bool F_54 ( struct V_111 * V_38 )
{
struct V_37 * V_37 = F_50 ( V_38 ) ;
return V_37 -> V_112 && V_38 -> V_113 -> V_36 -> V_114 &&
V_37 -> V_115 -> V_40 . V_116 . V_117 ;
}
enum V_118 F_55 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
struct V_111 * V_38 = V_2 -> V_120 [ V_119 ] ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
return V_37 -> V_115 -> V_121 ;
}
static bool F_56 ( struct V_15 * V_16 , enum V_119 V_119 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_5 V_9 = F_57 ( V_119 ) ;
T_1 V_122 , V_123 ;
T_1 V_124 ;
if ( F_33 ( V_16 ) )
V_124 = V_125 ;
else
V_124 = V_126 ;
V_122 = F_11 ( V_9 ) & V_124 ;
F_58 ( 5 ) ;
V_123 = F_11 ( V_9 ) & V_124 ;
return V_122 == V_123 ;
}
static void F_59 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_118 V_121 = V_38 -> V_115 -> V_121 ;
enum V_119 V_119 = V_38 -> V_119 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
T_5 V_9 = F_61 ( V_121 ) ;
if ( F_62 ( ( F_11 ( V_9 ) & V_128 ) == 0 ,
100 ) )
F_6 ( 1 , L_13 ) ;
} else {
if ( F_62 ( F_56 ( V_16 , V_119 ) , 100 ) )
F_6 ( 1 , L_13 ) ;
}
}
static const char * F_63 ( bool V_129 )
{
return V_129 ? L_14 : L_15 ;
}
void F_64 ( struct V_1 * V_2 ,
enum V_119 V_119 , bool V_36 )
{
T_1 V_10 ;
bool V_130 ;
V_10 = F_11 ( F_65 ( V_119 ) ) ;
V_130 = ! ! ( V_10 & V_131 ) ;
F_66 ( V_130 != V_36 ,
L_16 ,
F_63 ( V_36 ) , F_63 ( V_130 ) ) ;
}
static void F_67 ( struct V_1 * V_2 , bool V_36 )
{
T_1 V_10 ;
bool V_130 ;
F_2 ( & V_2 -> V_5 ) ;
V_10 = F_3 ( V_2 , V_132 ) ;
F_4 ( & V_2 -> V_5 ) ;
V_130 = V_10 & V_133 ;
F_66 ( V_130 != V_36 ,
L_17 ,
F_63 ( V_36 ) , F_63 ( V_130 ) ) ;
}
struct V_134 *
F_68 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_40 . V_16 -> V_17 ;
if ( V_38 -> V_115 -> V_135 < 0 )
return NULL ;
return & V_2 -> V_136 [ V_38 -> V_115 -> V_135 ] ;
}
void F_69 ( struct V_1 * V_2 ,
struct V_134 * V_137 ,
bool V_36 )
{
bool V_130 ;
struct V_138 V_139 ;
if ( F_6 ( ! V_137 ,
L_18 , F_63 ( V_36 ) ) )
return;
V_130 = V_137 -> V_140 ( V_2 , V_137 , & V_139 ) ;
F_66 ( V_130 != V_36 ,
L_19 ,
V_137 -> V_8 , F_63 ( V_36 ) , F_63 ( V_130 ) ) ;
}
static void F_70 ( struct V_1 * V_2 ,
enum V_119 V_119 , bool V_36 )
{
bool V_130 ;
enum V_118 V_121 = F_55 ( V_2 ,
V_119 ) ;
if ( F_71 ( V_2 -> V_16 ) ) {
T_1 V_10 = F_11 ( F_72 ( V_121 ) ) ;
V_130 = ! ! ( V_10 & V_141 ) ;
} else {
T_1 V_10 = F_11 ( F_73 ( V_119 ) ) ;
V_130 = ! ! ( V_10 & V_142 ) ;
}
F_66 ( V_130 != V_36 ,
L_20 ,
F_63 ( V_36 ) , F_63 ( V_130 ) ) ;
}
static void F_74 ( struct V_1 * V_2 ,
enum V_119 V_119 , bool V_36 )
{
T_1 V_10 ;
bool V_130 ;
V_10 = F_11 ( F_75 ( V_119 ) ) ;
V_130 = ! ! ( V_10 & V_143 ) ;
F_66 ( V_130 != V_36 ,
L_21 ,
F_63 ( V_36 ) , F_63 ( V_130 ) ) ;
}
static void F_76 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
T_1 V_10 ;
if ( F_60 ( V_2 -> V_16 ) -> V_127 == 5 )
return;
if ( F_71 ( V_2 -> V_16 ) )
return;
V_10 = F_11 ( F_73 ( V_119 ) ) ;
F_66 ( ! ( V_10 & V_144 ) , L_22 ) ;
}
void F_77 ( struct V_1 * V_2 ,
enum V_119 V_119 , bool V_36 )
{
T_1 V_10 ;
bool V_130 ;
V_10 = F_11 ( F_75 ( V_119 ) ) ;
V_130 = ! ! ( V_10 & V_145 ) ;
F_66 ( V_130 != V_36 ,
L_23 ,
F_63 ( V_36 ) , F_63 ( V_130 ) ) ;
}
void F_78 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_5 V_146 ;
T_1 V_10 ;
enum V_119 V_147 = V_148 ;
bool V_149 = true ;
if ( F_9 ( F_71 ( V_16 ) ) )
return;
if ( F_10 ( V_16 ) ) {
T_1 V_150 ;
V_146 = V_151 ;
V_150 = F_11 ( V_152 ) & V_153 ;
if ( V_150 == V_154 &&
F_11 ( V_155 ) & V_156 )
V_147 = V_157 ;
} else if ( F_13 ( V_16 ) || F_14 ( V_16 ) ) {
V_146 = F_79 ( V_119 ) ;
V_147 = V_119 ;
} else {
V_146 = V_158 ;
if ( F_11 ( V_159 ) & V_156 )
V_147 = V_157 ;
}
V_10 = F_11 ( V_146 ) ;
if ( ! ( V_10 & V_160 ) ||
( ( V_10 & V_161 ) == V_162 ) )
V_149 = false ;
F_66 ( V_147 == V_119 && V_149 ,
L_24 ,
F_80 ( V_119 ) ) ;
}
static void F_81 ( struct V_1 * V_2 ,
enum V_119 V_119 , bool V_36 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
bool V_130 ;
if ( F_82 ( V_16 ) || F_83 ( V_16 ) )
V_130 = F_11 ( F_84 ( V_148 ) ) & V_163 ;
else
V_130 = F_11 ( F_84 ( V_119 ) ) & V_164 ;
F_66 ( V_130 != V_36 ,
L_25 ,
F_80 ( V_119 ) , F_63 ( V_36 ) , F_63 ( V_130 ) ) ;
}
void F_85 ( struct V_1 * V_2 ,
enum V_119 V_119 , bool V_36 )
{
bool V_130 ;
enum V_118 V_121 = F_55 ( V_2 ,
V_119 ) ;
enum V_165 V_166 ;
if ( ( V_119 == V_148 && V_2 -> V_167 & V_168 ) ||
( V_119 == V_157 && V_2 -> V_167 & V_169 ) )
V_36 = true ;
V_166 = F_86 ( V_121 ) ;
if ( F_87 ( V_2 , V_166 ) ) {
T_1 V_10 = F_11 ( F_61 ( V_121 ) ) ;
V_130 = ! ! ( V_10 & V_170 ) ;
F_88 ( V_2 , V_166 ) ;
} else {
V_130 = false ;
}
F_66 ( V_130 != V_36 ,
L_26 ,
F_80 ( V_119 ) , F_63 ( V_36 ) , F_63 ( V_130 ) ) ;
}
static void F_89 ( struct V_1 * V_2 ,
enum V_171 V_171 , bool V_36 )
{
T_1 V_10 ;
bool V_130 ;
V_10 = F_11 ( F_90 ( V_171 ) ) ;
V_130 = ! ! ( V_10 & V_172 ) ;
F_66 ( V_130 != V_36 ,
L_27 ,
F_91 ( V_171 ) , F_63 ( V_36 ) , F_63 ( V_130 ) ) ;
}
static void F_92 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_50 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
T_1 V_10 = F_11 ( F_90 ( V_119 ) ) ;
F_66 ( V_10 & V_172 ,
L_28 ,
F_91 ( V_119 ) ) ;
return;
}
F_93 (dev_priv, i) {
T_1 V_10 = F_11 ( F_90 ( V_50 ) ) ;
enum V_119 V_173 = ( V_10 & V_174 ) >>
V_175 ;
F_66 ( ( V_10 & V_172 ) && V_119 == V_173 ,
L_29 ,
F_91 ( V_50 ) , F_80 ( V_119 ) ) ;
}
}
static void F_94 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_176 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
F_95 (dev_priv, pipe, sprite) {
T_1 V_10 = F_11 ( F_96 ( V_119 , V_176 ) ) ;
F_66 ( V_10 & V_177 ,
L_30 ,
V_176 , F_80 ( V_119 ) ) ;
}
} else if ( F_13 ( V_16 ) || F_14 ( V_16 ) ) {
F_95 (dev_priv, pipe, sprite) {
T_1 V_10 = F_11 ( F_97 ( V_119 , V_176 ) ) ;
F_66 ( V_10 & V_178 ,
L_31 ,
F_98 ( V_119 , V_176 ) , F_80 ( V_119 ) ) ;
}
} else if ( F_60 ( V_16 ) -> V_127 >= 7 ) {
T_1 V_10 = F_11 ( F_99 ( V_119 ) ) ;
F_66 ( V_10 & V_179 ,
L_31 ,
F_91 ( V_119 ) , F_80 ( V_119 ) ) ;
} else if ( F_60 ( V_16 ) -> V_127 >= 5 ) {
T_1 V_10 = F_11 ( F_100 ( V_119 ) ) ;
F_66 ( V_10 & V_180 ,
L_31 ,
F_91 ( V_119 ) , F_80 ( V_119 ) ) ;
}
}
static void F_101 ( struct V_111 * V_38 )
{
if ( F_102 ( F_103 ( V_38 ) == 0 ) )
F_104 ( V_38 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
T_1 V_10 ;
bool V_129 ;
F_102 ( ! ( F_106 ( V_2 -> V_16 ) || F_107 ( V_2 -> V_16 ) ) ) ;
V_10 = F_11 ( V_181 ) ;
V_129 = ! ! ( V_10 & ( V_182 | V_183 |
V_184 ) ) ;
F_66 ( ! V_129 , L_32 ) ;
}
static void F_108 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
T_1 V_10 ;
bool V_129 ;
V_10 = F_11 ( F_109 ( V_119 ) ) ;
V_129 = ! ! ( V_10 & V_185 ) ;
F_66 ( V_129 ,
L_33 ,
F_80 ( V_119 ) ) ;
}
static bool F_110 ( struct V_1 * V_2 ,
enum V_119 V_119 , T_1 V_150 , T_1 V_10 )
{
if ( ( V_10 & V_186 ) == 0 )
return false ;
if ( F_107 ( V_2 -> V_16 ) ) {
T_1 V_187 = F_11 ( F_111 ( V_119 ) ) ;
if ( ( V_187 & V_188 ) != V_150 )
return false ;
} else if ( F_14 ( V_2 -> V_16 ) ) {
if ( ( V_10 & V_189 ) != F_112 ( V_119 ) )
return false ;
} else {
if ( ( V_10 & V_190 ) != ( V_119 << 30 ) )
return false ;
}
return true ;
}
static bool F_113 ( struct V_1 * V_2 ,
enum V_119 V_119 , T_1 V_10 )
{
if ( ( V_10 & V_191 ) == 0 )
return false ;
if ( F_107 ( V_2 -> V_16 ) ) {
if ( ( V_10 & V_192 ) != F_114 ( V_119 ) )
return false ;
} else if ( F_14 ( V_2 -> V_16 ) ) {
if ( ( V_10 & V_193 ) != F_115 ( V_119 ) )
return false ;
} else {
if ( ( V_10 & V_194 ) != F_116 ( V_119 ) )
return false ;
}
return true ;
}
static bool F_117 ( struct V_1 * V_2 ,
enum V_119 V_119 , T_1 V_10 )
{
if ( ( V_10 & V_195 ) == 0 )
return false ;
if ( F_107 ( V_2 -> V_16 ) ) {
if ( ( V_10 & V_196 ) != F_118 ( V_119 ) )
return false ;
} else {
if ( ( V_10 & V_197 ) != F_119 ( V_119 ) )
return false ;
}
return true ;
}
static bool F_120 ( struct V_1 * V_2 ,
enum V_119 V_119 , T_1 V_10 )
{
if ( ( V_10 & V_198 ) == 0 )
return false ;
if ( F_107 ( V_2 -> V_16 ) ) {
if ( ( V_10 & V_196 ) != F_118 ( V_119 ) )
return false ;
} else {
if ( ( V_10 & V_199 ) != F_121 ( V_119 ) )
return false ;
}
return true ;
}
static void F_122 ( struct V_1 * V_2 ,
enum V_119 V_119 , T_5 V_9 ,
T_1 V_150 )
{
T_1 V_10 = F_11 ( V_9 ) ;
F_66 ( F_110 ( V_2 , V_119 , V_150 , V_10 ) ,
L_34 ,
F_123 ( V_9 ) , F_80 ( V_119 ) ) ;
F_66 ( F_106 ( V_2 -> V_16 ) && ( V_10 & V_186 ) == 0
&& ( V_10 & V_200 ) ,
L_35 ) ;
}
static void F_124 ( struct V_1 * V_2 ,
enum V_119 V_119 , T_5 V_9 )
{
T_1 V_10 = F_11 ( V_9 ) ;
F_66 ( F_113 ( V_2 , V_119 , V_10 ) ,
L_36 ,
F_123 ( V_9 ) , F_80 ( V_119 ) ) ;
F_66 ( F_106 ( V_2 -> V_16 ) && ( V_10 & V_191 ) == 0
&& ( V_10 & V_201 ) ,
L_37 ) ;
}
static void F_125 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
T_1 V_10 ;
F_122 ( V_2 , V_119 , V_202 , V_203 ) ;
F_122 ( V_2 , V_119 , V_204 , V_205 ) ;
F_122 ( V_2 , V_119 , V_206 , V_207 ) ;
V_10 = F_11 ( V_208 ) ;
F_66 ( F_120 ( V_2 , V_119 , V_10 ) ,
L_38 ,
F_80 ( V_119 ) ) ;
V_10 = F_11 ( V_155 ) ;
F_66 ( F_117 ( V_2 , V_119 , V_10 ) ,
L_39 ,
F_80 ( V_119 ) ) ;
F_124 ( V_2 , V_119 , V_209 ) ;
F_124 ( V_2 , V_119 , V_210 ) ;
F_124 ( V_2 , V_119 , V_211 ) ;
}
static void F_126 ( struct V_37 * V_38 ,
const struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_5 V_9 = F_65 ( V_38 -> V_119 ) ;
T_1 V_87 = V_212 -> V_213 . V_87 ;
F_127 ( V_2 , V_38 -> V_119 ) ;
if ( F_128 ( V_2 -> V_16 ) )
F_78 ( V_2 , V_38 -> V_119 ) ;
F_129 ( V_9 , V_87 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
if ( F_62 ( ( ( F_11 ( V_9 ) & V_214 ) == V_214 ) , 1 ) )
F_132 ( L_40 , V_38 -> V_119 ) ;
F_129 ( F_133 ( V_38 -> V_119 ) , V_212 -> V_213 . V_215 ) ;
F_130 ( F_133 ( V_38 -> V_119 ) ) ;
F_129 ( V_9 , V_87 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
F_129 ( V_9 , V_87 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
F_129 ( V_9 , V_87 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
}
static void F_134 ( struct V_37 * V_38 ,
const struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
enum V_216 V_217 = F_135 ( V_119 ) ;
T_1 V_218 ;
F_127 ( V_2 , V_38 -> V_119 ) ;
F_2 ( & V_2 -> V_5 ) ;
V_218 = F_136 ( V_2 , V_119 , F_137 ( V_217 ) ) ;
V_218 |= V_219 ;
F_138 ( V_2 , V_119 , F_137 ( V_217 ) , V_218 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_131 ( 1 ) ;
F_129 ( F_65 ( V_119 ) , V_212 -> V_213 . V_87 ) ;
if ( F_62 ( ( ( F_11 ( F_65 ( V_119 ) ) & V_214 ) == V_214 ) , 1 ) )
F_132 ( L_41 , V_119 ) ;
F_129 ( F_133 ( V_119 ) , V_212 -> V_213 . V_215 ) ;
F_130 ( F_133 ( V_119 ) ) ;
}
static int F_139 ( struct V_15 * V_16 )
{
struct V_37 * V_38 ;
int V_220 = 0 ;
F_140 (dev, crtc)
V_220 += V_38 -> V_40 . V_36 -> V_112 &&
F_21 ( V_38 , V_76 ) ;
return V_220 ;
}
static void F_141 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_5 V_9 = F_65 ( V_38 -> V_119 ) ;
T_1 V_87 = V_38 -> V_115 -> V_213 . V_87 ;
F_127 ( V_2 , V_38 -> V_119 ) ;
F_142 ( F_60 ( V_16 ) -> V_127 >= 5 ) ;
if ( F_128 ( V_16 ) && ! F_143 ( V_16 ) )
F_78 ( V_2 , V_38 -> V_119 ) ;
if ( F_143 ( V_16 ) && F_139 ( V_16 ) > 0 ) {
V_87 |= V_221 ;
F_129 ( F_65 ( ! V_38 -> V_119 ) ,
F_11 ( F_65 ( ! V_38 -> V_119 ) ) | V_221 ) ;
}
F_129 ( V_9 , 0 ) ;
F_129 ( V_9 , V_87 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
F_129 ( F_133 ( V_38 -> V_119 ) ,
V_38 -> V_115 -> V_213 . V_215 ) ;
} else {
F_129 ( V_9 , V_87 ) ;
}
F_129 ( V_9 , V_87 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
F_129 ( V_9 , V_87 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
F_129 ( V_9 , V_87 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
}
static void F_144 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 = V_38 -> V_119 ;
if ( F_143 ( V_16 ) &&
F_21 ( V_38 , V_76 ) &&
! F_139 ( V_16 ) ) {
F_129 ( F_65 ( V_157 ) ,
F_11 ( F_65 ( V_157 ) ) & ~ V_221 ) ;
F_129 ( F_65 ( V_148 ) ,
F_11 ( F_65 ( V_148 ) ) & ~ V_221 ) ;
}
if ( ( V_119 == V_148 && V_2 -> V_167 & V_168 ) ||
( V_119 == V_157 && V_2 -> V_167 & V_169 ) )
return;
F_127 ( V_2 , V_119 ) ;
F_129 ( F_65 ( V_119 ) , V_222 ) ;
F_130 ( F_65 ( V_119 ) ) ;
}
static void F_145 ( struct V_1 * V_2 , enum V_119 V_119 )
{
T_1 V_10 ;
F_127 ( V_2 , V_119 ) ;
V_10 = V_222 ;
if ( V_119 == V_157 )
V_10 = V_223 | V_224 ;
F_129 ( F_65 ( V_119 ) , V_10 ) ;
F_130 ( F_65 ( V_119 ) ) ;
}
static void F_146 ( struct V_1 * V_2 , enum V_119 V_119 )
{
enum V_216 V_217 = F_135 ( V_119 ) ;
T_1 V_10 ;
F_127 ( V_2 , V_119 ) ;
V_10 = V_225 |
V_224 | V_222 ;
if ( V_119 != V_148 )
V_10 |= V_223 ;
F_129 ( F_65 ( V_119 ) , V_10 ) ;
F_130 ( F_65 ( V_119 ) ) ;
F_2 ( & V_2 -> V_5 ) ;
V_10 = F_136 ( V_2 , V_119 , F_137 ( V_217 ) ) ;
V_10 &= ~ V_219 ;
F_138 ( V_2 , V_119 , F_137 ( V_217 ) , V_10 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
void F_147 ( struct V_1 * V_2 ,
struct V_226 * V_227 ,
unsigned int V_228 )
{
T_1 V_229 ;
T_5 V_230 ;
switch ( V_227 -> V_217 ) {
case V_231 :
V_229 = V_232 ;
V_230 = F_65 ( 0 ) ;
break;
case V_233 :
V_229 = V_234 ;
V_230 = F_65 ( 0 ) ;
V_228 <<= 4 ;
break;
case V_235 :
V_229 = V_236 ;
V_230 = V_237 ;
break;
default:
F_148 () ;
}
if ( F_62 ( ( F_11 ( V_230 ) & V_229 ) == V_228 , 1000 ) )
F_6 ( 1 , L_42 ,
F_149 ( V_227 -> V_217 ) , F_11 ( V_230 ) & V_229 , V_228 ) ;
}
static void F_150 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_134 * V_137 = F_68 ( V_38 ) ;
if ( F_9 ( V_137 == NULL ) )
return;
F_9 ( ! V_137 -> V_115 . V_238 ) ;
if ( V_137 -> V_112 == 0 ) {
F_16 ( L_43 , V_137 -> V_8 ) ;
F_9 ( V_137 -> V_239 ) ;
F_151 ( V_2 , V_137 ) ;
V_137 -> V_240 ( V_2 , V_137 ) ;
}
}
static void F_152 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_134 * V_137 = F_68 ( V_38 ) ;
if ( F_9 ( V_137 == NULL ) )
return;
if ( F_9 ( V_137 -> V_115 . V_238 == 0 ) )
return;
F_153 ( L_44 ,
V_137 -> V_8 , V_137 -> V_112 , V_137 -> V_239 ,
V_38 -> V_40 . V_40 . V_241 ) ;
if ( V_137 -> V_112 ++ ) {
F_9 ( ! V_137 -> V_239 ) ;
F_154 ( V_2 , V_137 ) ;
return;
}
F_9 ( V_137 -> V_239 ) ;
F_155 ( V_2 , V_242 ) ;
F_153 ( L_45 , V_137 -> V_8 ) ;
V_137 -> V_243 ( V_2 , V_137 ) ;
V_137 -> V_239 = true ;
}
static void F_156 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_134 * V_137 = F_68 ( V_38 ) ;
if ( F_60 ( V_16 ) -> V_127 < 5 )
return;
if ( V_137 == NULL )
return;
if ( F_9 ( ! ( V_137 -> V_115 . V_238 & ( 1 << F_157 ( & V_38 -> V_40 ) ) ) ) )
return;
F_153 ( L_46 ,
V_137 -> V_8 , V_137 -> V_112 , V_137 -> V_239 ,
V_38 -> V_40 . V_40 . V_241 ) ;
if ( F_9 ( V_137 -> V_112 == 0 ) ) {
F_151 ( V_2 , V_137 ) ;
return;
}
F_154 ( V_2 , V_137 ) ;
F_9 ( ! V_137 -> V_239 ) ;
if ( -- V_137 -> V_112 )
return;
F_153 ( L_47 , V_137 -> V_8 ) ;
V_137 -> V_244 ( V_2 , V_137 ) ;
V_137 -> V_239 = false ;
F_88 ( V_2 , V_242 ) ;
}
static void F_158 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_111 * V_38 = V_2 -> V_120 [ V_119 ] ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_5 V_9 ;
T_2 V_10 , V_245 ;
F_142 ( ! F_10 ( V_16 ) ) ;
F_154 ( V_2 ,
F_68 ( V_37 ) ) ;
F_159 ( V_2 , V_119 ) ;
F_160 ( V_2 , V_119 ) ;
if ( F_107 ( V_16 ) ) {
V_9 = F_161 ( V_119 ) ;
V_10 = F_11 ( V_9 ) ;
V_10 |= V_246 ;
F_129 ( V_9 , V_10 ) ;
}
V_9 = F_109 ( V_119 ) ;
V_10 = F_11 ( V_9 ) ;
V_245 = F_11 ( F_61 ( V_119 ) ) ;
if ( F_106 ( V_2 -> V_16 ) ) {
V_10 &= ~ V_247 ;
if ( F_21 ( V_37 , V_63 ) )
V_10 |= V_248 ;
else
V_10 |= V_245 & V_247 ;
}
V_10 &= ~ V_249 ;
if ( ( V_245 & V_250 ) == V_251 )
if ( F_106 ( V_2 -> V_16 ) &&
F_21 ( V_37 , V_66 ) )
V_10 |= V_252 ;
else
V_10 |= V_253 ;
else
V_10 |= V_254 ;
F_129 ( V_9 , V_10 | V_185 ) ;
if ( F_62 ( F_11 ( V_9 ) & V_255 , 100 ) )
F_132 ( L_48 , F_80 ( V_119 ) ) ;
}
static void F_162 ( struct V_1 * V_2 ,
enum V_118 V_121 )
{
T_1 V_10 , V_245 ;
F_142 ( ! F_10 ( V_2 -> V_16 ) ) ;
F_159 ( V_2 , (enum V_119 ) V_121 ) ;
F_160 ( V_2 , V_256 ) ;
V_10 = F_11 ( F_161 ( V_148 ) ) ;
V_10 |= V_246 ;
F_129 ( F_161 ( V_148 ) , V_10 ) ;
V_10 = V_185 ;
V_245 = F_11 ( F_61 ( V_121 ) ) ;
if ( ( V_245 & V_257 ) ==
V_251 )
V_10 |= V_253 ;
else
V_10 |= V_254 ;
F_129 ( V_258 , V_10 ) ;
if ( F_62 ( F_11 ( V_258 ) & V_255 , 100 ) )
F_132 ( L_49 ) ;
}
static void F_163 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_5 V_9 ;
T_2 V_10 ;
F_164 ( V_2 , V_119 ) ;
F_165 ( V_2 , V_119 ) ;
F_125 ( V_2 , V_119 ) ;
V_9 = F_109 ( V_119 ) ;
V_10 = F_11 ( V_9 ) ;
V_10 &= ~ V_185 ;
F_129 ( V_9 , V_10 ) ;
if ( F_62 ( ( F_11 ( V_9 ) & V_255 ) == 0 , 50 ) )
F_132 ( L_50 , F_80 ( V_119 ) ) ;
if ( F_107 ( V_16 ) ) {
V_9 = F_161 ( V_119 ) ;
V_10 = F_11 ( V_9 ) ;
V_10 &= ~ V_246 ;
F_129 ( V_9 , V_10 ) ;
}
}
static void F_166 ( struct V_1 * V_2 )
{
T_1 V_10 ;
V_10 = F_11 ( V_258 ) ;
V_10 &= ~ V_185 ;
F_129 ( V_258 , V_10 ) ;
if ( F_62 ( ( F_11 ( V_258 ) & V_255 ) == 0 , 50 ) )
F_132 ( L_51 ) ;
V_10 = F_11 ( F_161 ( V_148 ) ) ;
V_10 &= ~ V_246 ;
F_129 ( F_161 ( V_148 ) , V_10 ) ;
}
static void F_167 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 = V_38 -> V_119 ;
enum V_118 V_121 = V_38 -> V_115 -> V_121 ;
enum V_119 V_259 ;
T_5 V_9 ;
T_1 V_10 ;
F_153 ( L_52 , F_80 ( V_119 ) ) ;
F_92 ( V_2 , V_119 ) ;
F_168 ( V_2 , V_119 ) ;
F_94 ( V_2 , V_119 ) ;
if ( F_169 ( V_2 -> V_16 ) )
V_259 = V_256 ;
else
V_259 = V_119 ;
if ( F_170 ( V_2 -> V_16 ) )
if ( V_38 -> V_115 -> V_260 )
F_171 ( V_2 ) ;
else
F_172 ( V_2 , V_119 ) ;
else {
if ( V_38 -> V_115 -> V_261 ) {
F_173 ( V_2 , V_259 ) ;
F_76 ( V_2 ,
(enum V_119 ) V_121 ) ;
}
}
V_9 = F_61 ( V_121 ) ;
V_10 = F_11 ( V_9 ) ;
if ( V_10 & V_170 ) {
F_9 ( ! ( ( V_119 == V_148 && V_2 -> V_167 & V_168 ) ||
( V_119 == V_157 && V_2 -> V_167 & V_169 ) ) ) ;
return;
}
F_129 ( V_9 , V_10 | V_170 ) ;
F_130 ( V_9 ) ;
}
static void F_174 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_40 . V_16 -> V_17 ;
enum V_118 V_121 = V_38 -> V_115 -> V_121 ;
enum V_119 V_119 = V_38 -> V_119 ;
T_5 V_9 ;
T_1 V_10 ;
F_153 ( L_53 , F_80 ( V_119 ) ) ;
F_92 ( V_2 , V_119 ) ;
F_168 ( V_2 , V_119 ) ;
F_94 ( V_2 , V_119 ) ;
V_9 = F_61 ( V_121 ) ;
V_10 = F_11 ( V_9 ) ;
if ( ( V_10 & V_170 ) == 0 )
return;
if ( V_38 -> V_115 -> V_262 )
V_10 &= ~ V_263 ;
if ( ! ( V_119 == V_148 && V_2 -> V_167 & V_168 ) &&
! ( V_119 == V_157 && V_2 -> V_167 & V_169 ) )
V_10 &= ~ V_170 ;
F_129 ( V_9 , V_10 ) ;
if ( ( V_10 & V_170 ) == 0 )
F_59 ( V_38 ) ;
}
static bool F_175 ( struct V_15 * V_16 )
{
#ifdef F_176
if ( F_60 ( V_16 ) -> V_127 >= 6 && V_264 )
return true ;
#endif
return false ;
}
unsigned int
F_177 ( struct V_15 * V_16 , T_2 V_265 ,
V_89 V_266 , unsigned int V_171 )
{
unsigned int V_267 ;
T_2 V_268 ;
switch ( V_266 ) {
case V_269 :
V_267 = 1 ;
break;
case V_270 :
V_267 = F_33 ( V_16 ) ? 16 : 8 ;
break;
case V_271 :
V_267 = 32 ;
break;
case V_272 :
V_268 = F_178 ( V_265 , V_171 ) ;
switch ( V_268 ) {
default:
case 1 :
V_267 = 64 ;
break;
case 2 :
case 4 :
V_267 = 32 ;
break;
case 8 :
V_267 = 16 ;
break;
case 16 :
F_179 ( 1 ,
L_54 ) ;
V_267 = 16 ;
break;
}
break;
default:
F_180 ( V_266 ) ;
V_267 = 1 ;
break;
}
return V_267 ;
}
unsigned int
F_181 ( struct V_15 * V_16 , unsigned int V_273 ,
T_2 V_265 , V_89 V_266 )
{
return F_182 ( V_273 , F_177 ( V_16 , V_265 ,
V_266 , 0 ) ) ;
}
static void
F_183 ( struct V_274 * V_275 , struct V_276 * V_114 ,
const struct V_277 * V_278 )
{
struct V_279 * V_280 = & V_275 -> V_281 . V_282 ;
unsigned int V_267 , V_283 ;
* V_275 = V_284 ;
if ( ! V_278 )
return;
if ( ! F_184 ( V_278 -> V_285 ) )
return;
* V_275 = V_286 ;
V_280 -> V_273 = V_114 -> V_273 ;
V_280 -> V_265 = V_114 -> V_265 ;
V_280 -> V_287 = V_114 -> V_288 [ 0 ] ;
V_280 -> V_289 = V_114 -> V_290 [ 1 ] ;
V_280 -> V_291 = V_114 -> V_292 [ 0 ] ;
V_267 = F_177 ( V_114 -> V_16 , V_114 -> V_265 ,
V_114 -> V_292 [ 0 ] , 0 ) ;
V_283 = V_293 / V_267 ;
V_280 -> V_294 = F_185 ( V_114 -> V_288 [ 0 ] , V_283 ) ;
V_280 -> V_295 = F_185 ( V_114 -> V_273 , V_267 ) ;
V_280 -> V_296 = V_280 -> V_294 * V_280 -> V_295 * V_293 ;
if ( V_280 -> V_265 == V_297 ) {
V_267 = F_177 ( V_114 -> V_16 , V_114 -> V_265 ,
V_114 -> V_292 [ 0 ] , 1 ) ;
V_283 = V_293 / V_267 ;
V_280 -> V_298 = F_185 ( V_114 -> V_288 [ 0 ] , V_283 ) ;
V_280 -> V_299 = F_185 ( V_114 -> V_273 / 2 ,
V_267 ) ;
V_280 -> V_300 = V_280 -> V_298 * V_280 -> V_299 *
V_293 ;
}
}
static unsigned int F_186 ( struct V_1 * V_2 )
{
if ( F_60 ( V_2 ) -> V_127 >= 9 )
return 256 * 1024 ;
else if ( F_187 ( V_2 ) || F_188 ( V_2 ) ||
F_13 ( V_2 ) || F_14 ( V_2 ) )
return 128 * 1024 ;
else if ( F_60 ( V_2 ) -> V_127 >= 4 )
return 4 * 1024 ;
else
return 0 ;
}
int
F_189 ( struct V_301 * V_171 ,
struct V_276 * V_114 ,
const struct V_277 * V_278 )
{
struct V_15 * V_16 = V_114 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_302 * V_303 = F_190 ( V_114 ) ;
struct V_274 V_275 ;
T_1 V_304 ;
int V_305 ;
F_9 ( ! F_191 ( & V_16 -> V_306 ) ) ;
switch ( V_114 -> V_292 [ 0 ] ) {
case V_269 :
V_304 = F_186 ( V_2 ) ;
break;
case V_270 :
if ( F_60 ( V_16 ) -> V_127 >= 9 )
V_304 = 256 * 1024 ;
else {
V_304 = 0 ;
}
break;
case V_271 :
case V_272 :
if ( F_179 ( F_60 ( V_16 ) -> V_127 < 9 ,
L_55 ) )
return - V_307 ;
V_304 = 1 * 1024 * 1024 ;
break;
default:
F_180 ( V_114 -> V_292 [ 0 ] ) ;
return - V_307 ;
}
F_183 ( & V_275 , V_114 , V_278 ) ;
if ( F_175 ( V_16 ) && V_304 < 256 * 1024 )
V_304 = 256 * 1024 ;
F_192 ( V_2 ) ;
V_305 = F_193 ( V_303 , V_304 ,
& V_275 ) ;
if ( V_305 )
goto V_308;
if ( V_275 . type == V_309 ) {
V_305 = F_194 ( V_303 ) ;
if ( V_305 == - V_310 ) {
V_305 = - V_311 ;
goto V_312;
} else if ( V_305 )
goto V_312;
F_195 ( V_303 ) ;
}
F_196 ( V_2 ) ;
return 0 ;
V_312:
F_197 ( V_303 , & V_275 ) ;
V_308:
F_196 ( V_2 ) ;
return V_305 ;
}
static void F_198 ( struct V_276 * V_114 ,
const struct V_277 * V_278 )
{
struct V_302 * V_303 = F_190 ( V_114 ) ;
struct V_274 V_275 ;
F_9 ( ! F_191 ( & V_303 -> V_40 . V_16 -> V_306 ) ) ;
F_183 ( & V_275 , V_114 , V_278 ) ;
if ( V_275 . type == V_309 )
F_199 ( V_303 ) ;
F_197 ( V_303 , & V_275 ) ;
}
unsigned long F_200 ( struct V_1 * V_2 ,
int * V_313 , int * V_314 ,
unsigned int V_315 ,
unsigned int V_316 ,
unsigned int V_287 )
{
if ( V_315 != V_317 ) {
unsigned int V_318 , V_319 ;
V_318 = * V_314 / 8 ;
* V_314 %= 8 ;
V_319 = * V_313 / ( 512 / V_316 ) ;
* V_313 %= 512 / V_316 ;
return V_318 * V_287 * 8 + V_319 * 4096 ;
} else {
unsigned int V_304 = F_186 ( V_2 ) - 1 ;
unsigned int V_320 ;
V_320 = * V_314 * V_287 + * V_313 * V_316 ;
* V_314 = ( V_320 & V_304 ) / V_287 ;
* V_313 = ( ( V_320 & V_304 ) - * V_314 * V_287 ) / V_316 ;
return V_320 & ~ V_304 ;
}
}
static int F_201 ( int V_321 )
{
switch ( V_321 ) {
case V_322 :
return V_323 ;
case V_324 :
return V_325 ;
case V_326 :
return V_327 ;
default:
case V_328 :
return V_329 ;
case V_330 :
return V_331 ;
case V_332 :
return V_333 ;
case V_334 :
return V_335 ;
}
}
static int F_202 ( int V_321 , bool V_336 , bool V_337 )
{
switch ( V_321 ) {
case V_338 :
return V_327 ;
default:
case V_339 :
if ( V_336 ) {
if ( V_337 )
return V_340 ;
else
return V_331 ;
} else {
if ( V_337 )
return V_341 ;
else
return V_329 ;
}
case V_342 :
if ( V_336 )
return V_335 ;
else
return V_333 ;
}
}
static bool
F_203 ( struct V_37 * V_38 ,
struct V_343 * V_344 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = F_204 ( V_16 ) ;
struct V_302 * V_303 = NULL ;
struct V_345 V_346 = { 0 } ;
struct V_276 * V_114 = & V_344 -> V_114 -> V_40 ;
T_1 V_347 = F_205 ( V_344 -> V_40 , V_293 ) ;
T_1 V_348 = F_206 ( V_344 -> V_40 + V_344 -> V_296 ,
V_293 ) ;
V_348 -= V_347 ;
if ( V_344 -> V_296 == 0 )
return false ;
if ( V_348 * 2 > V_2 -> V_349 . V_350 )
return false ;
V_303 = F_207 ( V_16 ,
V_347 ,
V_347 ,
V_348 ) ;
if ( ! V_303 )
return false ;
V_303 -> V_315 = V_344 -> V_351 ;
if ( V_303 -> V_315 == V_352 )
V_303 -> V_353 = V_114 -> V_288 [ 0 ] ;
V_346 . V_265 = V_114 -> V_265 ;
V_346 . V_354 = V_114 -> V_354 ;
V_346 . V_273 = V_114 -> V_273 ;
V_346 . V_288 [ 0 ] = V_114 -> V_288 [ 0 ] ;
V_346 . V_292 [ 0 ] = V_114 -> V_292 [ 0 ] ;
V_346 . V_355 = V_356 ;
F_2 ( & V_16 -> V_306 ) ;
if ( F_208 ( V_16 , F_209 ( V_114 ) ,
& V_346 , V_303 ) ) {
F_153 ( L_56 ) ;
goto V_357;
}
F_4 ( & V_16 -> V_306 ) ;
F_153 ( L_57 , V_303 ) ;
return true ;
V_357:
F_210 ( & V_303 -> V_40 ) ;
F_4 ( & V_16 -> V_306 ) ;
return false ;
}
static void
F_211 ( struct V_301 * V_171 )
{
if ( V_171 -> V_114 == V_171 -> V_36 -> V_114 )
return;
if ( V_171 -> V_36 -> V_114 )
F_212 ( V_171 -> V_36 -> V_114 ) ;
V_171 -> V_36 -> V_114 = V_171 -> V_114 ;
if ( V_171 -> V_36 -> V_114 )
F_213 ( V_171 -> V_36 -> V_114 ) ;
}
static void
F_214 ( struct V_37 * V_37 ,
struct V_343 * V_344 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_111 * V_358 ;
struct V_37 * V_50 ;
struct V_302 * V_303 ;
struct V_301 * V_113 = V_37 -> V_40 . V_113 ;
struct V_277 * V_278 = V_113 -> V_36 ;
struct V_35 * V_44 = V_37 -> V_40 . V_36 ;
struct V_359 * V_359 = F_215 ( V_113 ) ;
struct V_276 * V_114 ;
if ( ! V_344 -> V_114 )
return;
if ( F_203 ( V_37 , V_344 ) ) {
V_114 = & V_344 -> V_114 -> V_40 ;
goto V_360;
}
F_216 ( V_344 -> V_114 ) ;
F_217 (dev, c) {
V_50 = F_50 ( V_358 ) ;
if ( V_358 == & V_37 -> V_40 )
continue;
if ( ! V_50 -> V_112 )
continue;
V_114 = V_358 -> V_113 -> V_114 ;
if ( ! V_114 )
continue;
V_303 = F_190 ( V_114 ) ;
if ( F_218 ( V_303 ) == V_344 -> V_40 ) {
F_213 ( V_114 ) ;
goto V_360;
}
}
F_219 ( V_278 ) -> V_361 = false ;
V_44 -> V_362 &= ~ ( 1 << F_220 ( V_113 ) ) ;
F_221 ( & V_37 -> V_40 ) ;
V_359 -> V_363 ( V_113 , & V_37 -> V_40 ) ;
return;
V_360:
V_278 -> V_364 = 0 ;
V_278 -> V_365 = 0 ;
V_278 -> V_366 = V_114 -> V_354 << 16 ;
V_278 -> V_367 = V_114 -> V_273 << 16 ;
V_278 -> V_368 = 0 ;
V_278 -> V_369 = 0 ;
V_278 -> V_370 = V_114 -> V_354 ;
V_278 -> V_371 = V_114 -> V_273 ;
V_303 = F_190 ( V_114 ) ;
if ( V_303 -> V_315 != V_317 )
V_2 -> V_372 = true ;
F_213 ( V_114 ) ;
V_113 -> V_114 = V_113 -> V_36 -> V_114 = V_114 ;
V_113 -> V_38 = V_113 -> V_36 -> V_38 = & V_37 -> V_40 ;
V_37 -> V_40 . V_36 -> V_362 |= ( 1 << F_220 ( V_113 ) ) ;
V_303 -> V_373 |= F_215 ( V_113 ) -> V_374 ;
}
static void F_222 ( struct V_111 * V_38 ,
struct V_276 * V_114 ,
int V_313 , int V_314 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_301 * V_113 = V_38 -> V_113 ;
bool V_361 = F_219 ( V_113 -> V_36 ) -> V_361 ;
struct V_302 * V_303 ;
int V_171 = V_37 -> V_171 ;
unsigned long V_375 ;
T_1 V_376 ;
T_5 V_9 = F_90 ( V_171 ) ;
int V_377 ;
if ( ! V_361 || ! V_114 ) {
F_129 ( V_9 , 0 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 )
F_129 ( F_223 ( V_171 ) , 0 ) ;
else
F_129 ( F_224 ( V_171 ) , 0 ) ;
F_130 ( V_9 ) ;
return;
}
V_303 = F_190 ( V_114 ) ;
if ( F_9 ( V_303 == NULL ) )
return;
V_377 = F_178 ( V_114 -> V_265 , 0 ) ;
V_376 = V_378 ;
V_376 |= V_172 ;
if ( F_60 ( V_16 ) -> V_127 < 4 ) {
if ( V_37 -> V_119 == V_157 )
V_376 |= V_379 ;
F_129 ( F_225 ( V_171 ) ,
( ( V_37 -> V_115 -> V_380 - 1 ) << 16 ) |
( V_37 -> V_115 -> V_381 - 1 ) ) ;
F_129 ( F_226 ( V_171 ) , 0 ) ;
} else if ( F_14 ( V_16 ) && V_171 == V_382 ) {
F_129 ( F_227 ( V_171 ) ,
( ( V_37 -> V_115 -> V_380 - 1 ) << 16 ) |
( V_37 -> V_115 -> V_381 - 1 ) ) ;
F_129 ( F_228 ( V_171 ) , 0 ) ;
F_129 ( F_229 ( V_171 ) , 0 ) ;
}
switch ( V_114 -> V_265 ) {
case V_323 :
V_376 |= V_322 ;
break;
case V_325 :
V_376 |= V_324 ;
break;
case V_327 :
V_376 |= V_326 ;
break;
case V_329 :
V_376 |= V_328 ;
break;
case V_331 :
V_376 |= V_330 ;
break;
case V_333 :
V_376 |= V_332 ;
break;
case V_335 :
V_376 |= V_334 ;
break;
default:
F_148 () ;
}
if ( F_60 ( V_16 ) -> V_127 >= 4 &&
V_303 -> V_315 != V_317 )
V_376 |= V_383 ;
if ( F_31 ( V_16 ) )
V_376 |= V_384 ;
V_375 = V_314 * V_114 -> V_288 [ 0 ] + V_313 * V_377 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
V_37 -> V_385 =
F_200 ( V_2 ,
& V_313 , & V_314 , V_303 -> V_315 ,
V_377 ,
V_114 -> V_288 [ 0 ] ) ;
V_375 -= V_37 -> V_385 ;
} else {
V_37 -> V_385 = V_375 ;
}
if ( V_38 -> V_113 -> V_36 -> V_285 == F_230 ( V_386 ) ) {
V_376 |= V_387 ;
V_313 += ( V_37 -> V_115 -> V_381 - 1 ) ;
V_314 += ( V_37 -> V_115 -> V_380 - 1 ) ;
V_375 +=
( V_37 -> V_115 -> V_380 - 1 ) * V_114 -> V_288 [ 0 ] +
( V_37 -> V_115 -> V_381 - 1 ) * V_377 ;
}
V_37 -> V_388 = V_313 ;
V_37 -> V_389 = V_314 ;
F_129 ( V_9 , V_376 ) ;
F_129 ( F_231 ( V_171 ) , V_114 -> V_288 [ 0 ] ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
F_129 ( F_223 ( V_171 ) ,
F_218 ( V_303 ) + V_37 -> V_385 ) ;
F_129 ( F_232 ( V_171 ) , ( V_314 << 16 ) | V_313 ) ;
F_129 ( F_233 ( V_171 ) , V_375 ) ;
} else
F_129 ( F_224 ( V_171 ) , F_218 ( V_303 ) + V_375 ) ;
F_130 ( V_9 ) ;
}
static void F_234 ( struct V_111 * V_38 ,
struct V_276 * V_114 ,
int V_313 , int V_314 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_301 * V_113 = V_38 -> V_113 ;
bool V_361 = F_219 ( V_113 -> V_36 ) -> V_361 ;
struct V_302 * V_303 ;
int V_171 = V_37 -> V_171 ;
unsigned long V_375 ;
T_1 V_376 ;
T_5 V_9 = F_90 ( V_171 ) ;
int V_377 ;
if ( ! V_361 || ! V_114 ) {
F_129 ( V_9 , 0 ) ;
F_129 ( F_223 ( V_171 ) , 0 ) ;
F_130 ( V_9 ) ;
return;
}
V_303 = F_190 ( V_114 ) ;
if ( F_9 ( V_303 == NULL ) )
return;
V_377 = F_178 ( V_114 -> V_265 , 0 ) ;
V_376 = V_378 ;
V_376 |= V_172 ;
if ( F_235 ( V_16 ) || F_236 ( V_16 ) )
V_376 |= V_390 ;
switch ( V_114 -> V_265 ) {
case V_323 :
V_376 |= V_322 ;
break;
case V_327 :
V_376 |= V_326 ;
break;
case V_329 :
V_376 |= V_328 ;
break;
case V_331 :
V_376 |= V_330 ;
break;
case V_333 :
V_376 |= V_332 ;
break;
case V_335 :
V_376 |= V_334 ;
break;
default:
F_148 () ;
}
if ( V_303 -> V_315 != V_317 )
V_376 |= V_383 ;
if ( ! F_235 ( V_16 ) && ! F_236 ( V_16 ) )
V_376 |= V_384 ;
V_375 = V_314 * V_114 -> V_288 [ 0 ] + V_313 * V_377 ;
V_37 -> V_385 =
F_200 ( V_2 ,
& V_313 , & V_314 , V_303 -> V_315 ,
V_377 ,
V_114 -> V_288 [ 0 ] ) ;
V_375 -= V_37 -> V_385 ;
if ( V_38 -> V_113 -> V_36 -> V_285 == F_230 ( V_386 ) ) {
V_376 |= V_387 ;
if ( ! F_235 ( V_16 ) && ! F_236 ( V_16 ) ) {
V_313 += ( V_37 -> V_115 -> V_381 - 1 ) ;
V_314 += ( V_37 -> V_115 -> V_380 - 1 ) ;
V_375 +=
( V_37 -> V_115 -> V_380 - 1 ) * V_114 -> V_288 [ 0 ] +
( V_37 -> V_115 -> V_381 - 1 ) * V_377 ;
}
}
V_37 -> V_388 = V_313 ;
V_37 -> V_389 = V_314 ;
F_129 ( V_9 , V_376 ) ;
F_129 ( F_231 ( V_171 ) , V_114 -> V_288 [ 0 ] ) ;
F_129 ( F_223 ( V_171 ) ,
F_218 ( V_303 ) + V_37 -> V_385 ) ;
if ( F_235 ( V_16 ) || F_236 ( V_16 ) ) {
F_129 ( F_237 ( V_171 ) , ( V_314 << 16 ) | V_313 ) ;
} else {
F_129 ( F_232 ( V_171 ) , ( V_314 << 16 ) | V_313 ) ;
F_129 ( F_233 ( V_171 ) , V_375 ) ;
}
F_130 ( V_9 ) ;
}
T_1 F_238 ( struct V_15 * V_16 , V_89 V_291 ,
T_2 V_265 )
{
T_1 V_391 = F_178 ( V_265 , 0 ) * 8 ;
switch ( V_291 ) {
case V_269 :
return 64 ;
case V_270 :
if ( F_60 ( V_16 ) -> V_127 == 2 )
return 128 ;
return 512 ;
case V_271 :
return 128 ;
case V_272 :
if ( V_391 == 8 )
return 64 ;
else
return 128 ;
default:
F_180 ( V_291 ) ;
return 64 ;
}
}
T_1 F_239 ( struct V_359 * V_359 ,
struct V_302 * V_303 ,
unsigned int V_171 )
{
struct V_274 V_275 ;
struct V_392 * V_393 ;
T_6 V_320 ;
F_183 ( & V_275 , V_359 -> V_40 . V_36 -> V_114 ,
V_359 -> V_40 . V_36 ) ;
V_393 = F_240 ( V_303 , & V_275 ) ;
if ( F_6 ( ! V_393 , L_58 ,
V_275 . type ) )
return - 1 ;
V_320 = V_393 -> V_394 . V_395 ;
if ( V_171 == 1 ) {
V_320 += V_393 -> V_396 . V_281 . V_282 . V_397 *
V_293 ;
}
F_9 ( F_241 ( V_320 ) ) ;
return F_242 ( V_320 ) ;
}
static void F_243 ( struct V_37 * V_37 , int V_241 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_129 ( F_244 ( V_37 -> V_119 , V_241 ) , 0 ) ;
F_129 ( F_245 ( V_37 -> V_119 , V_241 ) , 0 ) ;
F_129 ( F_246 ( V_37 -> V_119 , V_241 ) , 0 ) ;
}
static void F_247 ( struct V_37 * V_37 )
{
struct V_398 * V_399 ;
int V_50 ;
V_399 = & V_37 -> V_115 -> V_399 ;
for ( V_50 = 0 ; V_50 < V_37 -> V_400 ; V_50 ++ ) {
if ( ! V_399 -> V_401 [ V_50 ] . V_402 )
F_243 ( V_37 , V_50 ) ;
}
}
T_1 F_248 ( T_2 V_265 )
{
switch ( V_265 ) {
case V_323 :
return V_403 ;
case V_327 :
return V_338 ;
case V_331 :
return V_339 | V_404 ;
case V_329 :
return V_339 ;
case V_340 :
return V_339 | V_404 |
V_405 ;
case V_341 :
return V_339 |
V_405 ;
case V_333 :
return V_342 ;
case V_335 :
return V_404 | V_342 ;
case V_406 :
return V_407 | V_408 ;
case V_409 :
return V_407 | V_410 ;
case V_411 :
return V_407 | V_412 ;
case V_413 :
return V_407 | V_414 ;
default:
F_180 ( V_265 ) ;
}
return 0 ;
}
T_1 F_249 ( V_89 V_291 )
{
switch ( V_291 ) {
case V_269 :
break;
case V_270 :
return V_415 ;
case V_271 :
return V_416 ;
case V_272 :
return V_417 ;
default:
F_180 ( V_291 ) ;
}
return 0 ;
}
T_1 F_250 ( unsigned int V_285 )
{
switch ( V_285 ) {
case F_230 ( V_418 ) :
break;
case F_230 ( V_419 ) :
return V_420 ;
case F_230 ( V_386 ) :
return V_421 ;
case F_230 ( V_422 ) :
return V_423 ;
default:
F_180 ( V_285 ) ;
}
return 0 ;
}
static void F_251 ( struct V_111 * V_38 ,
struct V_276 * V_114 ,
int V_313 , int V_314 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_301 * V_171 = V_38 -> V_113 ;
bool V_361 = F_219 ( V_171 -> V_36 ) -> V_361 ;
struct V_302 * V_303 ;
int V_119 = V_37 -> V_119 ;
T_1 V_424 , V_425 , V_353 ;
T_1 V_267 , V_426 , V_427 ;
unsigned int V_285 ;
int V_428 , V_429 ;
T_1 V_430 ;
struct V_43 * V_44 = V_37 -> V_115 ;
struct V_431 * V_278 ;
int V_364 = 0 , V_365 = 0 , V_366 = 0 , V_367 = 0 ;
int V_432 = 0 , V_433 = 0 , V_434 = 0 , V_435 = 0 ;
int V_436 = - 1 ;
V_278 = F_219 ( V_171 -> V_36 ) ;
if ( ! V_361 || ! V_114 ) {
F_129 ( F_96 ( V_119 , 0 ) , 0 ) ;
F_129 ( F_252 ( V_119 , 0 ) , 0 ) ;
F_130 ( F_96 ( V_119 , 0 ) ) ;
return;
}
V_424 = V_177 |
V_437 |
V_438 ;
V_424 |= F_248 ( V_114 -> V_265 ) ;
V_424 |= F_249 ( V_114 -> V_292 [ 0 ] ) ;
V_424 |= V_439 ;
V_285 = V_171 -> V_36 -> V_285 ;
V_424 |= F_250 ( V_285 ) ;
V_303 = F_190 ( V_114 ) ;
V_425 = F_238 ( V_16 , V_114 -> V_292 [ 0 ] ,
V_114 -> V_265 ) ;
V_430 = F_239 ( F_215 ( V_171 ) , V_303 , 0 ) ;
F_9 ( F_253 ( & V_278 -> V_440 ) == 0 ) ;
V_436 = V_278 -> V_436 ;
V_364 = V_278 -> V_440 . V_441 >> 16 ;
V_365 = V_278 -> V_440 . y1 >> 16 ;
V_366 = F_253 ( & V_278 -> V_440 ) >> 16 ;
V_367 = F_254 ( & V_278 -> V_440 ) >> 16 ;
V_432 = V_278 -> V_442 . V_441 ;
V_433 = V_278 -> V_442 . y1 ;
V_434 = F_253 ( & V_278 -> V_442 ) ;
V_435 = F_254 ( & V_278 -> V_442 ) ;
F_9 ( V_313 != V_364 || V_314 != V_365 ) ;
if ( F_184 ( V_285 ) ) {
V_267 = F_177 ( V_16 , V_114 -> V_265 ,
V_114 -> V_292 [ 0 ] , 0 ) ;
V_353 = F_185 ( V_114 -> V_273 , V_267 ) ;
V_428 = V_353 * V_267 - V_314 - V_367 ;
V_429 = V_313 ;
V_427 = ( V_366 - 1 ) << 16 | ( V_367 - 1 ) ;
} else {
V_353 = V_114 -> V_288 [ 0 ] / V_425 ;
V_428 = V_313 ;
V_429 = V_314 ;
V_427 = ( V_367 - 1 ) << 16 | ( V_366 - 1 ) ;
}
V_426 = V_429 << 16 | V_428 ;
V_37 -> V_388 = V_428 ;
V_37 -> V_389 = V_429 ;
F_129 ( F_96 ( V_119 , 0 ) , V_424 ) ;
F_129 ( F_255 ( V_119 , 0 ) , V_426 ) ;
F_129 ( F_256 ( V_119 , 0 ) , V_427 ) ;
F_129 ( F_257 ( V_119 , 0 ) , V_353 ) ;
if ( V_436 >= 0 ) {
T_2 V_443 = 0 ;
F_9 ( ! V_434 || ! V_435 ) ;
V_443 = V_444 | F_258 ( 0 ) |
V_44 -> V_399 . V_401 [ V_436 ] . V_445 ;
F_129 ( F_244 ( V_119 , V_436 ) , V_443 ) ;
F_129 ( F_259 ( V_119 , V_436 ) , 0 ) ;
F_129 ( F_245 ( V_119 , V_436 ) , ( V_432 << 16 ) | V_433 ) ;
F_129 ( F_246 ( V_119 , V_436 ) , ( V_434 << 16 ) | V_435 ) ;
F_129 ( F_260 ( V_119 , 0 ) , 0 ) ;
} else {
F_129 ( F_260 ( V_119 , 0 ) , ( V_433 << 16 ) | V_432 ) ;
}
F_129 ( F_252 ( V_119 , 0 ) , V_430 ) ;
F_130 ( F_252 ( V_119 , 0 ) ) ;
}
static int
F_261 ( struct V_111 * V_38 , struct V_276 * V_114 ,
int V_313 , int V_314 , enum V_446 V_36 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
if ( V_2 -> V_447 . V_448 )
V_2 -> V_447 . V_448 ( V_2 ) ;
V_2 -> V_449 . V_450 ( V_38 , V_114 , V_313 , V_314 ) ;
return 0 ;
}
static void F_262 ( struct V_15 * V_16 )
{
struct V_111 * V_38 ;
F_217 (dev, crtc) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_171 V_171 = V_37 -> V_171 ;
F_263 ( V_16 , V_171 ) ;
F_264 ( V_16 , V_171 ) ;
}
}
static void F_265 ( struct V_15 * V_16 )
{
struct V_111 * V_38 ;
F_217 (dev, crtc) {
struct V_359 * V_171 = F_215 ( V_38 -> V_113 ) ;
struct V_431 * V_278 ;
F_266 ( V_38 , & V_171 -> V_40 ) ;
V_278 = F_219 ( V_171 -> V_40 . V_36 ) ;
if ( V_38 -> V_36 -> V_112 && V_278 -> V_40 . V_114 )
V_171 -> V_451 ( & V_171 -> V_40 , V_278 ) ;
F_267 ( V_38 ) ;
}
}
void F_268 ( struct V_15 * V_16 )
{
if ( F_33 ( V_16 ) )
return;
if ( F_60 ( V_16 ) -> V_127 >= 5 || F_31 ( V_16 ) )
return;
F_269 ( V_16 ) ;
F_270 ( V_16 ) ;
}
void F_271 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_204 ( V_16 ) ;
F_262 ( V_16 ) ;
if ( F_33 ( V_16 ) )
return;
if ( F_60 ( V_16 ) -> V_127 >= 5 || F_31 ( V_16 ) ) {
F_265 ( V_16 ) ;
return;
}
F_272 ( V_2 ) ;
F_273 ( V_2 ) ;
F_274 ( V_16 ) ;
F_275 ( & V_2 -> V_452 ) ;
if ( V_2 -> V_449 . V_453 )
V_2 -> V_449 . V_453 ( V_16 ) ;
F_276 ( & V_2 -> V_452 ) ;
F_277 ( V_16 ) ;
F_278 ( V_2 ) ;
F_279 ( V_16 ) ;
}
static bool F_280 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
bool V_454 ;
if ( F_281 ( & V_2 -> V_455 ) ||
V_37 -> V_456 != F_282 ( & V_2 -> V_455 . V_456 ) )
return false ;
F_275 ( & V_16 -> V_457 ) ;
V_454 = F_50 ( V_38 ) -> V_458 != NULL ;
F_276 ( & V_16 -> V_457 ) ;
return V_454 ;
}
static void F_283 ( struct V_37 * V_38 ,
struct V_43 * V_459 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_43 * V_212 =
F_284 ( V_38 -> V_40 . V_36 ) ;
V_38 -> V_40 . V_445 = V_38 -> V_40 . V_36 -> V_445 ;
F_153 ( L_59 ,
V_459 -> V_381 , V_459 -> V_380 ,
V_212 -> V_381 , V_212 -> V_380 ) ;
if ( F_71 ( V_16 ) )
F_285 ( & V_38 -> V_40 ) ;
F_129 ( F_286 ( V_38 -> V_119 ) ,
( ( V_212 -> V_381 - 1 ) << 16 ) |
( V_212 -> V_380 - 1 ) ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
F_247 ( V_38 ) ;
if ( V_212 -> V_460 . V_129 )
F_287 ( V_38 ) ;
} else if ( F_10 ( V_16 ) ) {
if ( V_212 -> V_460 . V_129 )
F_288 ( V_38 ) ;
else if ( V_459 -> V_460 . V_129 )
F_289 ( V_38 , true ) ;
}
}
static void F_290 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_5 V_9 ;
T_1 V_461 ;
V_9 = F_73 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
if ( F_291 ( V_16 ) ) {
V_461 &= ~ V_462 ;
V_461 |= V_462 | V_463 ;
} else {
V_461 &= ~ V_464 ;
V_461 |= V_464 | V_463 ;
}
F_129 ( V_9 , V_461 ) ;
V_9 = F_75 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
if ( F_107 ( V_16 ) ) {
V_461 &= ~ V_465 ;
V_461 |= V_466 ;
} else {
V_461 &= ~ V_464 ;
V_461 |= V_464 ;
}
F_129 ( V_9 , V_461 | V_467 ) ;
F_130 ( V_9 ) ;
F_131 ( 1000 ) ;
if ( F_291 ( V_16 ) )
F_129 ( V_9 , F_11 ( V_9 ) | V_468 |
V_469 ) ;
}
static void F_292 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_5 V_9 ;
T_1 V_461 , V_470 ;
F_293 ( V_2 , V_119 ) ;
V_9 = F_294 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_471 ;
V_461 &= ~ V_472 ;
F_129 ( V_9 , V_461 ) ;
F_11 ( V_9 ) ;
F_131 ( 150 ) ;
V_9 = F_73 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_473 ;
V_461 |= F_295 ( V_37 -> V_115 -> V_474 ) ;
V_461 &= ~ V_464 ;
V_461 |= V_475 ;
F_129 ( V_9 , V_461 | V_142 ) ;
V_9 = F_75 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_464 ;
V_461 |= V_475 ;
F_129 ( V_9 , V_461 | V_143 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
F_129 ( F_296 ( V_119 ) , V_476 ) ;
F_129 ( F_296 ( V_119 ) , V_476 |
V_477 ) ;
V_9 = F_297 ( V_119 ) ;
for ( V_470 = 0 ; V_470 < 5 ; V_470 ++ ) {
V_461 = F_11 ( V_9 ) ;
F_153 ( L_60 , V_461 ) ;
if ( ( V_461 & V_472 ) ) {
F_153 ( L_61 ) ;
F_129 ( V_9 , V_461 | V_472 ) ;
break;
}
}
if ( V_470 == 5 )
F_132 ( L_62 ) ;
V_9 = F_73 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_464 ;
V_461 |= V_478 ;
F_129 ( V_9 , V_461 ) ;
V_9 = F_75 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_464 ;
V_461 |= V_478 ;
F_129 ( V_9 , V_461 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
V_9 = F_297 ( V_119 ) ;
for ( V_470 = 0 ; V_470 < 5 ; V_470 ++ ) {
V_461 = F_11 ( V_9 ) ;
F_153 ( L_60 , V_461 ) ;
if ( V_461 & V_471 ) {
F_129 ( V_9 , V_461 | V_471 ) ;
F_153 ( L_63 ) ;
break;
}
}
if ( V_470 == 5 )
F_132 ( L_64 ) ;
F_153 ( L_65 ) ;
}
static void F_298 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_5 V_9 ;
T_1 V_461 , V_50 , V_479 ;
V_9 = F_294 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_471 ;
V_461 &= ~ V_472 ;
F_129 ( V_9 , V_461 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
V_9 = F_73 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_473 ;
V_461 |= F_295 ( V_37 -> V_115 -> V_474 ) ;
V_461 &= ~ V_464 ;
V_461 |= V_475 ;
V_461 &= ~ V_480 ;
V_461 |= V_481 ;
F_129 ( V_9 , V_461 | V_142 ) ;
F_129 ( F_299 ( V_119 ) ,
V_482 | V_483 ) ;
V_9 = F_75 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
if ( F_107 ( V_16 ) ) {
V_461 &= ~ V_465 ;
V_461 |= V_484 ;
} else {
V_461 &= ~ V_464 ;
V_461 |= V_475 ;
}
F_129 ( V_9 , V_461 | V_143 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
V_9 = F_73 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_480 ;
V_461 |= V_485 [ V_50 ] ;
F_129 ( V_9 , V_461 ) ;
F_130 ( V_9 ) ;
F_131 ( 500 ) ;
for ( V_479 = 0 ; V_479 < 5 ; V_479 ++ ) {
V_9 = F_297 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
F_153 ( L_60 , V_461 ) ;
if ( V_461 & V_472 ) {
F_129 ( V_9 , V_461 | V_472 ) ;
F_153 ( L_61 ) ;
break;
}
F_131 ( 50 ) ;
}
if ( V_479 < 5 )
break;
}
if ( V_50 == 4 )
F_132 ( L_62 ) ;
V_9 = F_73 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_464 ;
V_461 |= V_478 ;
if ( F_300 ( V_16 ) ) {
V_461 &= ~ V_480 ;
V_461 |= V_481 ;
}
F_129 ( V_9 , V_461 ) ;
V_9 = F_75 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
if ( F_107 ( V_16 ) ) {
V_461 &= ~ V_465 ;
V_461 |= V_486 ;
} else {
V_461 &= ~ V_464 ;
V_461 |= V_478 ;
}
F_129 ( V_9 , V_461 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
V_9 = F_73 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_480 ;
V_461 |= V_485 [ V_50 ] ;
F_129 ( V_9 , V_461 ) ;
F_130 ( V_9 ) ;
F_131 ( 500 ) ;
for ( V_479 = 0 ; V_479 < 5 ; V_479 ++ ) {
V_9 = F_297 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
F_153 ( L_60 , V_461 ) ;
if ( V_461 & V_471 ) {
F_129 ( V_9 , V_461 | V_471 ) ;
F_153 ( L_63 ) ;
break;
}
F_131 ( 50 ) ;
}
if ( V_479 < 5 )
break;
}
if ( V_50 == 4 )
F_132 ( L_64 ) ;
F_153 ( L_66 ) ;
}
static void F_301 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_5 V_9 ;
T_1 V_461 , V_50 , V_487 ;
V_9 = F_294 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_471 ;
V_461 &= ~ V_472 ;
F_129 ( V_9 , V_461 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
F_153 ( L_67 ,
F_11 ( F_297 ( V_119 ) ) ) ;
for ( V_487 = 0 ; V_487 < F_302 ( V_485 ) * 2 ; V_487 ++ ) {
V_9 = F_73 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ ( V_488 | V_462 ) ;
V_461 &= ~ V_142 ;
F_129 ( V_9 , V_461 ) ;
V_9 = F_75 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_488 ;
V_461 &= ~ V_465 ;
V_461 &= ~ V_143 ;
F_129 ( V_9 , V_461 ) ;
V_9 = F_73 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_473 ;
V_461 |= F_295 ( V_37 -> V_115 -> V_474 ) ;
V_461 |= V_489 ;
V_461 &= ~ V_480 ;
V_461 |= V_485 [ V_487 / 2 ] ;
V_461 |= V_490 ;
F_129 ( V_9 , V_461 | V_142 ) ;
F_129 ( F_299 ( V_119 ) ,
V_482 | V_483 ) ;
V_9 = F_75 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 |= V_484 ;
V_461 |= V_490 ;
F_129 ( V_9 , V_461 | V_143 ) ;
F_130 ( V_9 ) ;
F_131 ( 1 ) ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
V_9 = F_297 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
F_153 ( L_60 , V_461 ) ;
if ( V_461 & V_472 ||
( F_11 ( V_9 ) & V_472 ) ) {
F_129 ( V_9 , V_461 | V_472 ) ;
F_153 ( L_68 ,
V_50 ) ;
break;
}
F_131 ( 1 ) ;
}
if ( V_50 == 4 ) {
F_153 ( L_69 , V_487 / 2 ) ;
continue;
}
V_9 = F_73 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_462 ;
V_461 |= V_491 ;
F_129 ( V_9 , V_461 ) ;
V_9 = F_75 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_465 ;
V_461 |= V_486 ;
F_129 ( V_9 , V_461 ) ;
F_130 ( V_9 ) ;
F_131 ( 2 ) ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
V_9 = F_297 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
F_153 ( L_60 , V_461 ) ;
if ( V_461 & V_471 ||
( F_11 ( V_9 ) & V_471 ) ) {
F_129 ( V_9 , V_461 | V_471 ) ;
F_153 ( L_70 ,
V_50 ) ;
goto V_492;
}
F_131 ( 2 ) ;
}
if ( V_50 == 4 )
F_153 ( L_71 , V_487 / 2 ) ;
}
V_492:
F_153 ( L_66 ) ;
}
static void F_303 ( struct V_37 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_37 -> V_119 ;
T_5 V_9 ;
T_1 V_461 ;
V_9 = F_75 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ ( V_473 | ( 0x7 << 16 ) ) ;
V_461 |= F_295 ( V_37 -> V_115 -> V_474 ) ;
V_461 |= ( F_11 ( F_61 ( V_119 ) ) & V_247 ) << 11 ;
F_129 ( V_9 , V_461 | V_145 ) ;
F_130 ( V_9 ) ;
F_131 ( 200 ) ;
V_461 = F_11 ( V_9 ) ;
F_129 ( V_9 , V_461 | V_493 ) ;
F_130 ( V_9 ) ;
F_131 ( 200 ) ;
V_9 = F_73 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
if ( ( V_461 & V_144 ) == 0 ) {
F_129 ( V_9 , V_461 | V_144 ) ;
F_130 ( V_9 ) ;
F_131 ( 100 ) ;
}
}
static void F_304 ( struct V_37 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_37 -> V_119 ;
T_5 V_9 ;
T_1 V_461 ;
V_9 = F_75 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
F_129 ( V_9 , V_461 & ~ V_493 ) ;
V_9 = F_73 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
F_129 ( V_9 , V_461 & ~ V_144 ) ;
F_130 ( V_9 ) ;
F_131 ( 100 ) ;
V_9 = F_75 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
F_129 ( V_9 , V_461 & ~ V_145 ) ;
F_130 ( V_9 ) ;
F_131 ( 100 ) ;
}
static void F_305 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_5 V_9 ;
T_1 V_461 ;
V_9 = F_73 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
F_129 ( V_9 , V_461 & ~ V_142 ) ;
F_130 ( V_9 ) ;
V_9 = F_75 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ ( 0x7 << 16 ) ;
V_461 |= ( F_11 ( F_61 ( V_119 ) ) & V_247 ) << 11 ;
F_129 ( V_9 , V_461 & ~ V_143 ) ;
F_130 ( V_9 ) ;
F_131 ( 100 ) ;
if ( F_106 ( V_16 ) )
F_129 ( F_296 ( V_119 ) , V_476 ) ;
V_9 = F_73 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ V_464 ;
V_461 |= V_475 ;
F_129 ( V_9 , V_461 ) ;
V_9 = F_75 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
if ( F_107 ( V_16 ) ) {
V_461 &= ~ V_465 ;
V_461 |= V_484 ;
} else {
V_461 &= ~ V_464 ;
V_461 |= V_475 ;
}
V_461 &= ~ ( 0x07 << 16 ) ;
V_461 |= ( F_11 ( F_61 ( V_119 ) ) & V_247 ) << 11 ;
F_129 ( V_9 , V_461 ) ;
F_130 ( V_9 ) ;
F_131 ( 100 ) ;
}
bool F_306 ( struct V_15 * V_16 )
{
struct V_37 * V_38 ;
F_140 (dev, crtc) {
if ( F_282 ( & V_38 -> V_494 ) == 0 )
continue;
if ( V_38 -> V_458 )
F_307 ( V_16 , V_38 -> V_119 ) ;
return true ;
}
return false ;
}
static void F_308 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = F_204 ( V_37 -> V_40 . V_16 ) ;
struct V_495 * V_496 = V_37 -> V_458 ;
F_309 () ;
V_37 -> V_458 = NULL ;
if ( V_496 -> V_497 )
F_310 ( V_37 -> V_40 . V_16 ,
V_37 -> V_119 ,
V_496 -> V_497 ) ;
F_104 ( & V_37 -> V_40 ) ;
F_311 ( & V_2 -> V_498 ) ;
F_312 ( V_2 -> V_499 , & V_496 -> V_496 ) ;
F_313 ( V_37 -> V_171 ,
V_496 -> V_500 ) ;
}
static int F_314 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
long V_305 ;
F_9 ( F_315 ( & V_2 -> V_498 ) ) ;
V_305 = F_316 (
V_2 -> V_498 ,
! F_280 ( V_38 ) ,
60 * V_501 ) ;
if ( V_305 < 0 )
return V_305 ;
if ( V_305 == 0 ) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
F_275 ( & V_16 -> V_457 ) ;
if ( V_37 -> V_458 ) {
F_179 ( 1 , L_72 ) ;
F_308 ( V_37 ) ;
}
F_276 ( & V_16 -> V_457 ) ;
}
return 0 ;
}
static void F_317 ( struct V_1 * V_2 )
{
T_1 V_461 ;
F_129 ( V_502 , V_503 ) ;
F_2 ( & V_2 -> V_5 ) ;
V_461 = F_318 ( V_2 , V_504 , V_505 ) ;
V_461 |= V_506 ;
F_319 ( V_2 , V_504 , V_461 , V_505 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_320 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int clock = F_50 ( V_38 ) -> V_115 -> V_40 . V_116 . V_117 ;
T_1 V_507 , V_508 , V_509 , V_510 = 0 ;
T_1 V_461 ;
F_317 ( V_2 ) ;
if ( clock == 20000 ) {
V_509 = 1 ;
V_507 = 0x41 ;
V_508 = 0x20 ;
} else {
T_1 V_511 = 172800 * 1000 ;
T_1 V_512 = 64 ;
T_1 V_513 , V_514 , V_515 ;
V_513 = F_7 ( V_511 , clock ) ;
V_514 = V_513 / V_512 ;
V_515 = V_513 % V_512 ;
V_509 = 0 ;
V_507 = V_514 - 2 ;
V_508 = V_515 ;
}
F_9 ( F_321 ( V_507 ) &
~ V_516 ) ;
F_9 ( F_322 ( V_510 ) &
~ V_517 ) ;
F_153 ( L_73 ,
clock ,
V_509 ,
V_507 ,
V_510 ,
V_508 ) ;
F_2 ( & V_2 -> V_5 ) ;
V_461 = F_318 ( V_2 , V_518 , V_505 ) ;
V_461 &= ~ V_516 ;
V_461 |= F_321 ( V_507 ) ;
V_461 &= ~ V_517 ;
V_461 |= F_323 ( V_508 ) ;
V_461 |= F_322 ( V_510 ) ;
V_461 |= V_519 ;
F_319 ( V_2 , V_518 , V_461 , V_505 ) ;
V_461 = F_318 ( V_2 , V_520 , V_505 ) ;
V_461 &= ~ F_324 ( 1 ) ;
V_461 |= F_324 ( V_509 ) ;
F_319 ( V_2 , V_520 , V_461 , V_505 ) ;
V_461 = F_318 ( V_2 , V_504 , V_505 ) ;
V_461 &= ~ V_506 ;
F_319 ( V_2 , V_504 , V_461 , V_505 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_131 ( 24 ) ;
F_129 ( V_502 , V_521 ) ;
}
static void F_325 ( struct V_37 * V_38 ,
enum V_119 V_259 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_118 V_121 = V_38 -> V_115 -> V_121 ;
F_129 ( F_326 ( V_259 ) ,
F_11 ( F_327 ( V_121 ) ) ) ;
F_129 ( F_328 ( V_259 ) ,
F_11 ( F_329 ( V_121 ) ) ) ;
F_129 ( F_330 ( V_259 ) ,
F_11 ( F_331 ( V_121 ) ) ) ;
F_129 ( F_332 ( V_259 ) ,
F_11 ( F_333 ( V_121 ) ) ) ;
F_129 ( F_334 ( V_259 ) ,
F_11 ( F_335 ( V_121 ) ) ) ;
F_129 ( F_336 ( V_259 ) ,
F_11 ( F_337 ( V_121 ) ) ) ;
F_129 ( F_338 ( V_259 ) ,
F_11 ( F_339 ( V_121 ) ) ) ;
}
static void F_340 ( struct V_15 * V_16 , bool V_243 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_461 ;
V_461 = F_11 ( V_522 ) ;
if ( ! ! ( V_461 & V_523 ) == V_243 )
return;
F_9 ( F_11 ( F_75 ( V_157 ) ) & V_143 ) ;
F_9 ( F_11 ( F_75 ( V_524 ) ) & V_143 ) ;
V_461 &= ~ V_523 ;
if ( V_243 )
V_461 |= V_523 ;
F_153 ( L_74 , V_243 ? L_75 : L_76 ) ;
F_129 ( V_522 , V_461 ) ;
F_130 ( V_522 ) ;
}
static void F_341 ( struct V_37 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
switch ( V_37 -> V_119 ) {
case V_148 :
break;
case V_157 :
if ( V_37 -> V_115 -> V_474 > 2 )
F_340 ( V_16 , false ) ;
else
F_340 ( V_16 , true ) ;
break;
case V_524 :
F_340 ( V_16 , true ) ;
break;
default:
F_148 () ;
}
}
static enum V_217
F_342 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_41 * V_42 ;
F_22 (dev, crtc, encoder) {
if ( V_42 -> type == V_525 ||
V_42 -> type == V_526 )
return F_343 ( & V_42 -> V_40 ) -> V_217 ;
}
return - 1 ;
}
static void F_344 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_1 V_461 ;
F_108 ( V_2 , V_119 ) ;
if ( F_291 ( V_16 ) )
F_341 ( V_37 ) ;
F_129 ( F_345 ( V_119 ) ,
F_11 ( F_346 ( V_119 ) ) & V_527 ) ;
F_347 ( V_2 , V_119 , false ) ;
V_2 -> V_449 . V_528 ( V_38 ) ;
if ( F_107 ( V_16 ) ) {
T_1 V_529 ;
V_461 = F_11 ( V_530 ) ;
V_461 |= F_348 ( V_119 ) ;
V_529 = F_349 ( V_119 ) ;
if ( V_37 -> V_115 -> V_135 == V_531 )
V_461 |= V_529 ;
else
V_461 &= ~ V_529 ;
F_129 ( V_530 , V_461 ) ;
}
F_152 ( V_37 ) ;
F_78 ( V_2 , V_119 ) ;
F_325 ( V_37 , V_119 ) ;
F_290 ( V_38 ) ;
F_347 ( V_2 , V_119 , true ) ;
if ( F_107 ( V_16 ) && V_37 -> V_115 -> V_532 ) {
const struct V_533 * V_116 =
& V_37 -> V_115 -> V_40 . V_116 ;
T_1 V_534 = ( F_11 ( F_61 ( V_119 ) ) & V_247 ) >> 5 ;
T_5 V_9 = F_111 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ ( V_188 |
V_535 |
V_536 ) ;
V_461 |= V_537 ;
V_461 |= V_534 << 9 ;
if ( V_116 -> V_355 & V_538 )
V_461 |= V_539 ;
if ( V_116 -> V_355 & V_540 )
V_461 |= V_541 ;
switch ( F_342 ( V_38 ) ) {
case V_231 :
V_461 |= V_203 ;
break;
case V_233 :
V_461 |= V_205 ;
break;
case V_235 :
V_461 |= V_207 ;
break;
default:
F_148 () ;
}
F_129 ( V_9 , V_461 ) ;
}
F_158 ( V_2 , V_119 ) ;
}
static void F_350 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_118 V_121 = V_37 -> V_115 -> V_121 ;
F_108 ( V_2 , V_256 ) ;
F_320 ( V_38 ) ;
F_325 ( V_37 , V_148 ) ;
F_162 ( V_2 , V_121 ) ;
}
struct V_134 * F_351 ( struct V_37 * V_38 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_38 -> V_40 . V_16 -> V_17 ;
struct V_134 * V_137 ;
struct V_542 * V_135 ;
enum V_543 V_50 ;
int V_91 = V_2 -> V_544 ;
V_135 = F_352 ( V_44 -> V_40 . V_36 ) ;
if ( F_106 ( V_2 -> V_16 ) ) {
V_50 = (enum V_543 ) V_38 -> V_119 ;
V_137 = & V_2 -> V_136 [ V_50 ] ;
F_153 ( L_77 ,
V_38 -> V_40 . V_40 . V_241 , V_137 -> V_8 ) ;
F_9 ( V_135 [ V_50 ] . V_238 ) ;
goto V_101;
}
if ( F_30 ( V_2 -> V_16 ) ) {
struct V_41 * V_42 ;
struct V_226 * V_545 ;
V_42 = F_353 ( V_44 ) ;
if ( F_9 ( ! V_42 ) )
return NULL ;
V_545 = F_343 ( & V_42 -> V_40 ) ;
V_50 = (enum V_543 ) V_545 -> V_217 ;
V_137 = & V_2 -> V_136 [ V_50 ] ;
F_153 ( L_77 ,
V_38 -> V_40 . V_40 . V_241 , V_137 -> V_8 ) ;
F_9 ( V_135 [ V_50 ] . V_238 ) ;
goto V_101;
} else if ( F_60 ( V_2 ) -> V_127 < 9 && F_71 ( V_2 ) )
V_91 = 2 ;
for ( V_50 = 0 ; V_50 < V_91 ; V_50 ++ ) {
V_137 = & V_2 -> V_136 [ V_50 ] ;
if ( V_135 [ V_50 ] . V_238 == 0 )
continue;
if ( memcmp ( & V_44 -> V_213 ,
& V_135 [ V_50 ] . V_139 ,
sizeof( V_44 -> V_213 ) ) == 0 ) {
F_153 ( L_78 ,
V_38 -> V_40 . V_40 . V_241 , V_137 -> V_8 ,
V_135 [ V_50 ] . V_238 ,
V_137 -> V_112 ) ;
goto V_101;
}
}
for ( V_50 = 0 ; V_50 < V_2 -> V_544 ; V_50 ++ ) {
V_137 = & V_2 -> V_136 [ V_50 ] ;
if ( V_135 [ V_50 ] . V_238 == 0 ) {
F_153 ( L_79 ,
V_38 -> V_40 . V_40 . V_241 , V_137 -> V_8 ) ;
goto V_101;
}
}
return NULL ;
V_101:
if ( V_135 [ V_50 ] . V_238 == 0 )
V_135 [ V_50 ] . V_139 =
V_44 -> V_213 ;
V_44 -> V_135 = V_50 ;
F_16 ( L_80 , V_137 -> V_8 ,
F_80 ( V_38 -> V_119 ) ) ;
V_135 [ V_50 ] . V_238 |= 1 << V_38 -> V_119 ;
return V_137 ;
}
static void F_354 ( struct V_45 * V_36 )
{
struct V_1 * V_2 = F_204 ( V_36 -> V_16 ) ;
struct V_542 * V_135 ;
struct V_134 * V_137 ;
enum V_543 V_50 ;
if ( ! F_355 ( V_36 ) -> V_546 )
return;
V_135 = F_355 ( V_36 ) -> V_135 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_544 ; V_50 ++ ) {
V_137 = & V_2 -> V_136 [ V_50 ] ;
V_137 -> V_115 = V_135 [ V_50 ] ;
}
}
static void F_356 ( struct V_15 * V_16 , int V_119 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_5 V_547 = F_57 ( V_119 ) ;
T_1 V_461 ;
V_461 = F_11 ( V_547 ) ;
F_131 ( 500 ) ;
if ( F_62 ( F_11 ( V_547 ) != V_461 , 5 ) ) {
if ( F_62 ( F_11 ( V_547 ) != V_461 , 5 ) )
F_132 ( L_81 , F_80 ( V_119 ) ) ;
}
}
static int
F_357 ( struct V_43 * V_44 , bool V_548 ,
unsigned V_549 , int * V_436 , unsigned int V_285 ,
int V_366 , int V_367 , int V_434 , int V_435 )
{
struct V_398 * V_399 =
& V_44 -> V_399 ;
struct V_37 * V_37 =
F_50 ( V_44 -> V_40 . V_38 ) ;
int V_550 ;
V_550 = F_184 ( V_285 ) ?
( V_367 != V_434 || V_366 != V_435 ) :
( V_366 != V_434 || V_367 != V_435 ) ;
if ( V_548 || ! V_550 ) {
if ( * V_436 >= 0 ) {
V_399 -> V_551 &= ~ ( 1 << V_549 ) ;
V_399 -> V_401 [ * V_436 ] . V_402 = 0 ;
F_153 ( L_82
L_83 ,
V_37 -> V_119 , V_549 , * V_436 ,
V_399 -> V_551 ) ;
* V_436 = - 1 ;
}
return 0 ;
}
if ( V_366 < V_552 || V_367 < V_553 ||
V_434 < V_554 || V_435 < V_555 ||
V_366 > V_556 || V_367 > V_557 ||
V_434 > V_558 || V_435 > V_559 ) {
F_153 ( L_84
L_85 ,
V_37 -> V_119 , V_549 , V_366 , V_367 , V_434 , V_435 ) ;
return - V_307 ;
}
V_399 -> V_551 |= ( 1 << V_549 ) ;
F_153 ( L_82
L_86 ,
V_37 -> V_119 , V_549 , V_366 , V_367 , V_434 , V_435 ,
V_399 -> V_551 ) ;
return 0 ;
}
int F_358 ( struct V_43 * V_36 )
{
struct V_37 * V_37 = F_50 ( V_36 -> V_40 . V_38 ) ;
const struct V_533 * V_116 = & V_36 -> V_40 . V_116 ;
F_153 ( L_87 ,
V_37 -> V_40 . V_40 . V_241 , V_37 -> V_119 , V_560 ) ;
return F_357 ( V_36 , ! V_36 -> V_40 . V_112 , V_560 ,
& V_36 -> V_399 . V_436 , V_418 ,
V_36 -> V_381 , V_36 -> V_380 ,
V_116 -> V_561 , V_116 -> V_562 ) ;
}
static int F_359 ( struct V_43 * V_44 ,
struct V_431 * V_278 )
{
struct V_37 * V_37 = F_50 ( V_44 -> V_40 . V_38 ) ;
struct V_359 * V_359 =
F_215 ( V_278 -> V_40 . V_171 ) ;
struct V_276 * V_114 = V_278 -> V_40 . V_114 ;
int V_305 ;
bool V_548 = ! V_114 || ! V_278 -> V_361 ;
F_153 ( L_88 ,
V_359 -> V_40 . V_40 . V_241 , V_37 -> V_119 ,
F_220 ( & V_359 -> V_40 ) ) ;
V_305 = F_357 ( V_44 , V_548 ,
F_220 ( & V_359 -> V_40 ) ,
& V_278 -> V_436 ,
V_278 -> V_40 . V_285 ,
F_253 ( & V_278 -> V_440 ) >> 16 ,
F_254 ( & V_278 -> V_440 ) >> 16 ,
F_253 ( & V_278 -> V_442 ) ,
F_254 ( & V_278 -> V_442 ) ) ;
if ( V_305 || V_278 -> V_436 < 0 )
return V_305 ;
if ( V_278 -> V_563 . V_355 != V_564 ) {
F_153 ( L_89 ,
V_359 -> V_40 . V_40 . V_241 ) ;
return - V_307 ;
}
switch ( V_114 -> V_265 ) {
case V_327 :
case V_331 :
case V_329 :
case V_340 :
case V_341 :
case V_333 :
case V_335 :
case V_406 :
case V_409 :
case V_411 :
case V_413 :
break;
default:
F_153 ( L_90 ,
V_359 -> V_40 . V_40 . V_241 , V_114 -> V_40 . V_241 , V_114 -> V_265 ) ;
return - V_307 ;
}
return 0 ;
}
static void F_360 ( struct V_37 * V_38 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_38 -> V_400 ; V_50 ++ )
F_243 ( V_38 , V_50 ) ;
}
static void F_287 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
struct V_398 * V_399 =
& V_38 -> V_115 -> V_399 ;
F_153 ( L_91 , V_38 -> V_115 ) ;
if ( V_38 -> V_115 -> V_460 . V_129 ) {
int V_241 ;
if ( F_9 ( V_38 -> V_115 -> V_399 . V_436 < 0 ) ) {
F_132 ( L_92 ) ;
return;
}
V_241 = V_399 -> V_436 ;
F_129 ( F_244 ( V_119 , V_241 ) , V_444 |
V_565 | V_399 -> V_401 [ V_241 ] . V_445 ) ;
F_129 ( F_245 ( V_119 , V_241 ) , V_38 -> V_115 -> V_460 . V_566 ) ;
F_129 ( F_246 ( V_119 , V_241 ) , V_38 -> V_115 -> V_460 . V_296 ) ;
F_153 ( L_93 , V_38 -> V_115 , V_241 ) ;
}
}
static void F_288 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
if ( V_38 -> V_115 -> V_460 . V_129 ) {
if ( F_291 ( V_16 ) || F_235 ( V_16 ) )
F_129 ( F_361 ( V_119 ) , V_567 | V_568 |
F_362 ( V_119 ) ) ;
else
F_129 ( F_361 ( V_119 ) , V_567 | V_568 ) ;
F_129 ( F_363 ( V_119 ) , V_38 -> V_115 -> V_460 . V_566 ) ;
F_129 ( F_364 ( V_119 ) , V_38 -> V_115 -> V_460 . V_296 ) ;
}
}
void F_365 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! V_38 -> V_115 -> V_569 )
return;
F_307 ( V_16 , V_38 -> V_119 ) ;
F_366 ( V_2 , V_38 -> V_171 ) ;
if ( F_236 ( V_16 ) ) {
F_2 ( & V_2 -> V_570 . V_571 ) ;
F_9 ( F_367 ( V_2 , V_572 , 0xc0000000 ) ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
} else {
F_129 ( V_573 , V_574 ) ;
if ( F_62 ( F_368 ( V_573 ) & V_574 , 50 ) )
F_132 ( L_94 ) ;
}
}
void F_369 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! V_38 -> V_115 -> V_569 )
return;
F_366 ( V_2 , V_38 -> V_171 ) ;
if ( F_236 ( V_16 ) ) {
F_2 ( & V_2 -> V_570 . V_571 ) ;
F_9 ( F_367 ( V_2 , V_572 , 0 ) ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
if ( F_62 ( ( F_11 ( V_573 ) & V_574 ) == 0 , 42 ) )
F_132 ( L_95 ) ;
} else {
F_129 ( V_573 , 0 ) ;
F_130 ( V_573 ) ;
}
F_307 ( V_16 , V_38 -> V_119 ) ;
}
static void F_370 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_119 V_119 = V_37 -> V_119 ;
int V_50 ;
bool V_575 = false ;
if ( ! V_38 -> V_36 -> V_112 )
return;
if ( F_170 ( V_2 -> V_16 ) ) {
if ( V_37 -> V_115 -> V_260 )
F_171 ( V_2 ) ;
else
F_172 ( V_2 , V_119 ) ;
}
if ( F_235 ( V_16 ) && V_37 -> V_115 -> V_569 &&
( ( F_11 ( F_371 ( V_119 ) ) & V_576 ) ==
V_577 ) ) {
F_369 ( V_37 ) ;
V_575 = true ;
}
for ( V_50 = 0 ; V_50 < 256 ; V_50 ++ ) {
T_5 V_578 ;
if ( F_170 ( V_16 ) )
V_578 = F_372 ( V_119 , V_50 ) ;
else
V_578 = F_373 ( V_119 , V_50 ) ;
F_129 ( V_578 ,
( V_37 -> V_579 [ V_50 ] << 16 ) |
( V_37 -> V_580 [ V_50 ] << 8 ) |
V_37 -> V_581 [ V_50 ] ) ;
}
if ( V_575 )
F_365 ( V_37 ) ;
}
static void F_374 ( struct V_37 * V_37 )
{
if ( V_37 -> V_582 ) {
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_2 ( & V_16 -> V_306 ) ;
V_2 -> V_583 . V_584 = false ;
( void ) F_375 ( V_37 -> V_582 ) ;
V_2 -> V_583 . V_584 = true ;
F_4 ( & V_16 -> V_306 ) ;
}
}
static void
F_376 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
F_365 ( V_37 ) ;
if ( F_33 ( V_16 ) )
F_347 ( V_2 , V_119 , true ) ;
F_377 ( V_2 ) ;
F_378 ( V_2 ) ;
}
static void
F_221 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
if ( F_33 ( V_16 ) )
F_347 ( V_2 , V_119 , false ) ;
if ( F_170 ( V_16 ) ) {
F_379 ( V_2 , false ) ;
V_2 -> V_585 . V_586 . V_587 = false ;
F_307 ( V_16 , V_119 ) ;
}
F_369 ( V_37 ) ;
}
static void F_380 ( struct V_37 * V_38 )
{
struct V_588 * V_589 = & V_38 -> V_589 ;
struct V_43 * V_212 =
F_284 ( V_38 -> V_40 . V_36 ) ;
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
if ( V_589 -> V_590 )
F_307 ( V_16 , V_38 -> V_119 ) ;
F_381 ( V_16 , V_589 -> V_591 ) ;
V_38 -> V_585 . V_592 = true ;
if ( V_212 -> V_593 && V_212 -> V_40 . V_112 )
F_382 ( & V_38 -> V_40 ) ;
if ( V_589 -> V_594 )
F_383 ( V_38 ) ;
if ( V_589 -> V_595 )
F_376 ( & V_38 -> V_40 ) ;
memset ( V_589 , 0 , sizeof( * V_589 ) ) ;
}
static void F_384 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_588 * V_589 = & V_38 -> V_589 ;
struct V_43 * V_212 =
F_284 ( V_38 -> V_40 . V_36 ) ;
if ( V_589 -> V_596 )
F_385 ( V_38 ) ;
if ( V_38 -> V_589 . V_597 )
F_369 ( V_38 ) ;
if ( V_589 -> V_598 )
F_221 ( & V_38 -> V_40 ) ;
if ( V_212 -> V_599 ) {
V_38 -> V_585 . V_592 = false ;
F_379 ( V_2 , false ) ;
}
if ( ! F_19 ( & V_212 -> V_40 ) && V_212 -> V_593 )
F_382 ( & V_38 -> V_40 ) ;
}
static void F_386 ( struct V_111 * V_38 , unsigned V_362 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_301 * V_81 ;
int V_119 = V_37 -> V_119 ;
F_374 ( V_37 ) ;
F_387 (p, dev, plane_mask)
F_215 ( V_81 ) -> V_363 ( V_81 , V_38 ) ;
F_381 ( V_16 , F_388 ( V_119 ) ) ;
}
static void F_389 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 ;
if ( F_9 ( V_37 -> V_112 ) )
return;
if ( V_37 -> V_115 -> V_261 )
F_390 ( V_2 , V_119 , false ) ;
if ( V_37 -> V_115 -> V_261 )
F_150 ( V_37 ) ;
if ( V_37 -> V_115 -> V_532 )
F_391 ( V_37 , V_600 ) ;
F_392 ( V_37 ) ;
if ( V_37 -> V_115 -> V_261 ) {
F_393 ( V_37 ,
& V_37 -> V_115 -> V_601 , NULL ) ;
}
F_394 ( V_38 ) ;
V_37 -> V_112 = true ;
F_347 ( V_2 , V_119 , true ) ;
F_22 (dev, crtc, encoder)
if ( V_42 -> V_602 )
V_42 -> V_602 ( V_42 ) ;
if ( V_37 -> V_115 -> V_261 ) {
F_303 ( V_37 ) ;
} else {
F_164 ( V_2 , V_119 ) ;
F_165 ( V_2 , V_119 ) ;
}
F_288 ( V_37 ) ;
F_370 ( V_38 ) ;
F_382 ( V_38 ) ;
F_167 ( V_37 ) ;
if ( V_37 -> V_115 -> V_261 )
F_344 ( V_38 ) ;
F_101 ( V_38 ) ;
F_395 ( V_38 ) ;
F_22 (dev, crtc, encoder)
V_42 -> V_243 ( V_42 ) ;
if ( F_107 ( V_16 ) )
F_356 ( V_16 , V_37 -> V_119 ) ;
if ( V_37 -> V_115 -> V_261 )
F_307 ( V_16 , V_119 ) ;
F_390 ( V_2 , V_119 , true ) ;
F_396 ( V_37 ) ;
}
static bool F_397 ( struct V_37 * V_38 )
{
return F_398 ( V_38 -> V_40 . V_16 ) && V_38 -> V_119 == V_148 ;
}
static void F_399 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 , V_603 ;
struct V_43 * V_212 =
F_284 ( V_38 -> V_36 ) ;
if ( F_9 ( V_37 -> V_112 ) )
return;
if ( V_37 -> V_115 -> V_261 )
F_390 ( V_2 , V_256 ,
false ) ;
if ( F_68 ( V_37 ) )
F_152 ( V_37 ) ;
if ( V_37 -> V_115 -> V_532 )
F_391 ( V_37 , V_600 ) ;
F_392 ( V_37 ) ;
if ( V_37 -> V_115 -> V_121 != V_604 ) {
F_129 ( F_400 ( V_37 -> V_115 -> V_121 ) ,
V_37 -> V_115 -> V_605 - 1 ) ;
}
if ( V_37 -> V_115 -> V_261 ) {
F_393 ( V_37 ,
& V_37 -> V_115 -> V_601 , NULL ) ;
}
F_401 ( V_38 ) ;
F_285 ( V_38 ) ;
V_37 -> V_112 = true ;
if ( V_37 -> V_115 -> V_261 )
F_347 ( V_2 , V_119 , false ) ;
else
F_347 ( V_2 , V_119 , true ) ;
F_22 (dev, crtc, encoder) {
if ( V_42 -> V_602 )
V_42 -> V_602 ( V_42 ) ;
}
if ( V_37 -> V_115 -> V_261 )
V_2 -> V_449 . V_528 ( V_38 ) ;
if ( ! V_37 -> V_115 -> V_260 )
F_402 ( V_37 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 )
F_287 ( V_37 ) ;
else
F_288 ( V_37 ) ;
F_370 ( V_38 ) ;
F_403 ( V_38 ) ;
if ( ! V_37 -> V_115 -> V_260 )
F_404 ( V_38 ) ;
F_382 ( V_38 ) ;
F_167 ( V_37 ) ;
if ( V_37 -> V_115 -> V_261 )
F_350 ( V_38 ) ;
if ( V_37 -> V_115 -> V_606 )
F_405 ( V_38 , true ) ;
F_101 ( V_38 ) ;
F_395 ( V_38 ) ;
F_22 (dev, crtc, encoder) {
V_42 -> V_243 ( V_42 ) ;
F_406 ( V_42 , true ) ;
}
if ( V_37 -> V_115 -> V_261 ) {
F_307 ( V_16 , V_119 ) ;
F_307 ( V_16 , V_119 ) ;
F_347 ( V_2 , V_119 , true ) ;
F_390 ( V_2 , V_256 ,
true ) ;
}
V_603 = V_212 -> V_603 ;
if ( F_235 ( V_16 ) && V_603 != V_607 ) {
F_307 ( V_16 , V_603 ) ;
F_307 ( V_16 , V_603 ) ;
}
F_396 ( V_37 ) ;
}
static void F_289 ( struct V_37 * V_38 , bool V_608 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
if ( V_608 || V_38 -> V_115 -> V_460 . V_129 ) {
F_129 ( F_361 ( V_119 ) , 0 ) ;
F_129 ( F_363 ( V_119 ) , 0 ) ;
F_129 ( F_364 ( V_119 ) , 0 ) ;
}
}
static void F_407 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 ;
if ( V_37 -> V_115 -> V_261 )
F_390 ( V_2 , V_119 , false ) ;
F_22 (dev, crtc, encoder)
V_42 -> V_244 ( V_42 ) ;
F_408 ( V_38 ) ;
F_101 ( V_38 ) ;
if ( V_37 -> V_115 -> V_261 )
F_347 ( V_2 , V_119 , false ) ;
F_174 ( V_37 ) ;
F_289 ( V_37 , false ) ;
if ( V_37 -> V_115 -> V_261 ) {
F_305 ( V_38 ) ;
F_347 ( V_2 , V_119 , true ) ;
}
F_22 (dev, crtc, encoder)
if ( V_42 -> V_609 )
V_42 -> V_609 ( V_42 ) ;
if ( V_37 -> V_115 -> V_261 ) {
F_163 ( V_2 , V_119 ) ;
if ( F_107 ( V_16 ) ) {
T_5 V_9 ;
T_1 V_461 ;
V_9 = F_111 ( V_119 ) ;
V_461 = F_11 ( V_9 ) ;
V_461 &= ~ ( V_537 |
V_188 ) ;
V_461 |= V_610 ;
F_129 ( V_9 , V_461 ) ;
V_461 = F_11 ( V_530 ) ;
V_461 &= ~ ( F_348 ( V_119 ) | F_349 ( V_119 ) ) ;
F_129 ( V_530 , V_461 ) ;
}
F_304 ( V_37 ) ;
}
F_390 ( V_2 , V_119 , true ) ;
F_409 ( V_37 ) ;
}
static void F_410 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
enum V_118 V_121 = V_37 -> V_115 -> V_121 ;
if ( V_37 -> V_115 -> V_261 )
F_390 ( V_2 , V_256 ,
false ) ;
F_22 (dev, crtc, encoder) {
F_406 ( V_42 , false ) ;
V_42 -> V_244 ( V_42 ) ;
}
F_408 ( V_38 ) ;
F_101 ( V_38 ) ;
F_174 ( V_37 ) ;
if ( V_37 -> V_115 -> V_606 )
F_405 ( V_38 , false ) ;
if ( ! V_37 -> V_115 -> V_260 )
F_411 ( V_2 , V_121 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 )
F_360 ( V_37 ) ;
else
F_289 ( V_37 , false ) ;
if ( ! V_37 -> V_115 -> V_260 )
F_412 ( V_37 ) ;
F_22 (dev, crtc, encoder)
if ( V_42 -> V_609 )
V_42 -> V_609 ( V_42 ) ;
if ( V_37 -> V_115 -> V_261 ) {
F_166 ( V_2 ) ;
F_317 ( V_2 ) ;
F_413 ( V_38 ) ;
F_390 ( V_2 , V_256 ,
true ) ;
}
F_409 ( V_37 ) ;
}
static void F_414 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_43 * V_212 = V_38 -> V_115 ;
if ( ! V_212 -> V_611 . V_612 )
return;
F_9 ( F_11 ( V_613 ) & V_614 ) ;
F_127 ( V_2 , V_38 -> V_119 ) ;
F_129 ( V_615 , V_212 -> V_611 . V_616 ) ;
F_129 ( V_613 , V_212 -> V_611 . V_612 ) ;
F_129 ( F_415 ( V_38 -> V_119 ) , 0 ) ;
}
static enum V_165 F_416 ( enum V_217 V_217 )
{
switch ( V_217 ) {
case V_617 :
return V_618 ;
case V_231 :
return V_619 ;
case V_233 :
return V_620 ;
case V_235 :
return V_621 ;
case V_622 :
return V_623 ;
default:
F_180 ( V_217 ) ;
return V_624 ;
}
}
static enum V_165 F_417 ( enum V_217 V_217 )
{
switch ( V_217 ) {
case V_617 :
return V_625 ;
case V_231 :
return V_626 ;
case V_233 :
return V_627 ;
case V_235 :
return V_628 ;
case V_622 :
return V_628 ;
default:
F_180 ( V_217 ) ;
return V_625 ;
}
}
enum V_165
F_418 ( struct V_41 * V_41 )
{
struct V_15 * V_16 = V_41 -> V_40 . V_16 ;
struct V_226 * V_545 ;
switch ( V_41 -> type ) {
case V_629 :
F_47 ( ! F_71 ( V_16 ) ) ;
case V_525 :
case V_63 :
case V_526 :
V_545 = F_343 ( & V_41 -> V_40 ) ;
return F_416 ( V_545 -> V_217 ) ;
case V_630 :
V_545 = F_419 ( & V_41 -> V_40 ) -> V_113 ;
return F_416 ( V_545 -> V_217 ) ;
case V_64 :
return V_631 ;
case V_632 :
return V_633 ;
default:
return V_624 ;
}
}
enum V_165
F_420 ( struct V_41 * V_41 )
{
struct V_15 * V_16 = V_41 -> V_40 . V_16 ;
struct V_226 * V_545 ;
switch ( V_41 -> type ) {
case V_629 :
case V_63 :
F_47 ( ! F_71 ( V_16 ) ) ;
case V_525 :
case V_526 :
V_545 = F_343 ( & V_41 -> V_40 ) ;
return F_417 ( V_545 -> V_217 ) ;
case V_630 :
V_545 = F_419 ( & V_41 -> V_40 ) -> V_113 ;
return F_417 ( V_545 -> V_217 ) ;
default:
F_180 ( V_41 -> type ) ;
return V_625 ;
}
}
static unsigned long F_421 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_41 * V_41 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_119 V_119 = V_37 -> V_119 ;
unsigned long V_634 ;
enum V_118 V_118 = V_37 -> V_115 -> V_121 ;
if ( ! V_38 -> V_36 -> V_112 )
return 0 ;
V_634 = F_230 ( F_422 ( V_119 ) ) ;
V_634 |= F_230 ( F_86 ( V_118 ) ) ;
if ( V_37 -> V_115 -> V_460 . V_129 ||
V_37 -> V_115 -> V_460 . V_635 )
V_634 |= F_230 ( F_423 ( V_119 ) ) ;
F_22 (dev, crtc, intel_encoder)
V_634 |= F_230 ( F_418 ( V_41 ) ) ;
return V_634 ;
}
static unsigned long F_424 ( struct V_111 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_165 V_636 ;
unsigned long V_637 , V_638 , V_639 ;
V_639 = V_37 -> V_640 ;
V_37 -> V_640 = V_638 = F_421 ( V_38 ) ;
V_637 = V_638 & ~ V_639 ;
F_425 (domain, domains)
F_155 ( V_2 , V_636 ) ;
return V_639 & ~ V_638 ;
}
static void F_426 ( struct V_1 * V_2 ,
unsigned long V_637 )
{
enum V_165 V_636 ;
F_425 (domain, domains)
F_88 ( V_2 , V_636 ) ;
}
static void F_427 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
unsigned long V_641 [ V_642 ] = {} ;
struct V_35 * V_44 ;
struct V_111 * V_38 ;
int V_50 ;
F_428 (state, crtc, crtc_state, i) {
if ( F_19 ( V_38 -> V_36 ) )
V_641 [ F_50 ( V_38 ) -> V_119 ] =
F_424 ( V_38 ) ;
}
if ( V_2 -> V_449 . V_643 ) {
unsigned int V_644 = F_355 ( V_36 ) -> V_644 ;
if ( V_644 != V_2 -> V_645 &&
! F_9 ( ! V_36 -> V_646 ) )
V_2 -> V_449 . V_643 ( V_36 ) ;
}
for ( V_50 = 0 ; V_50 < V_642 ; V_50 ++ )
if ( V_641 [ V_50 ] )
F_426 ( V_2 , V_641 [ V_50 ] ) ;
}
static int F_429 ( struct V_1 * V_2 )
{
int V_647 = V_2 -> V_647 ;
if ( F_60 ( V_2 ) -> V_127 >= 9 ||
F_235 ( V_2 ) || F_236 ( V_2 ) )
return V_647 ;
else if ( F_14 ( V_2 ) )
return V_647 * 95 / 100 ;
else if ( F_60 ( V_2 ) -> V_127 < 4 )
return 2 * V_647 * 90 / 100 ;
else
return V_647 * 90 / 100 ;
}
static void F_430 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_431 ( V_16 ) || F_432 ( V_16 ) ) {
T_1 V_54 = F_11 ( V_648 ) & V_649 ;
if ( V_54 == V_650 )
V_2 -> V_647 = 675000 ;
else if ( V_54 == V_651 )
V_2 -> V_647 = 540000 ;
else if ( V_54 == V_652 )
V_2 -> V_647 = 450000 ;
else
V_2 -> V_647 = 337500 ;
} else if ( F_236 ( V_16 ) ) {
if ( F_11 ( V_653 ) & V_654 )
V_2 -> V_647 = 450000 ;
else if ( F_433 ( V_16 ) )
V_2 -> V_647 = 450000 ;
else if ( F_434 ( V_16 ) )
V_2 -> V_647 = 540000 ;
else
V_2 -> V_647 = 675000 ;
} else if ( F_14 ( V_16 ) ) {
V_2 -> V_647 = 320000 ;
} else if ( F_13 ( V_16 ) ) {
V_2 -> V_647 = 400000 ;
} else {
V_2 -> V_647 = V_2 -> V_645 ;
}
V_2 -> V_655 = F_429 ( V_2 ) ;
F_16 ( L_96 ,
V_2 -> V_647 ) ;
F_16 ( L_97 ,
V_2 -> V_655 ) ;
}
static void F_435 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_645 = V_2 -> V_449 . V_656 ( V_16 ) ;
F_16 ( L_98 ,
V_2 -> V_645 ) ;
if ( F_13 ( V_16 ) || F_14 ( V_16 ) ) {
F_129 ( V_657 , F_185 ( V_2 -> V_645 , 1000 ) ) ;
}
if ( V_2 -> V_647 == 0 )
F_430 ( V_16 ) ;
}
static void F_436 ( struct V_15 * V_16 , int V_658 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_11 ;
T_2 V_659 ;
T_2 V_660 ;
int V_305 ;
switch ( V_658 ) {
case 144000 :
V_11 = V_661 ;
V_659 = F_437 ( 60 ) ;
break;
case 288000 :
V_11 = V_662 ;
V_659 = F_437 ( 60 ) ;
break;
case 384000 :
V_11 = V_663 ;
V_659 = F_437 ( 60 ) ;
break;
case 576000 :
V_11 = V_664 ;
V_659 = F_437 ( 60 ) ;
break;
case 624000 :
V_11 = V_664 ;
V_659 = F_437 ( 65 ) ;
break;
case 19200 :
V_659 = 0 ;
V_11 = 0 ;
break;
default:
F_132 ( L_99 , V_658 ) ;
return;
}
F_2 ( & V_2 -> V_570 . V_571 ) ;
V_305 = F_367 ( V_2 , V_665 ,
0x80000000 ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
if ( V_305 ) {
F_132 ( L_100 ,
V_305 , V_658 ) ;
return;
}
V_660 = F_11 ( V_666 ) & V_667 ;
V_660 = V_660 * 500 + 1000 ;
if ( V_658 == 19200 || V_658 == 624000 ||
V_660 == 624000 ) {
F_129 ( V_668 , ~ V_669 ) ;
if ( F_62 ( ! ( F_11 ( V_668 ) & V_670 ) ,
1 ) )
F_132 ( L_101 ) ;
}
if ( V_658 != 19200 ) {
T_2 V_10 ;
V_10 = F_11 ( V_671 ) ;
V_10 &= ~ V_672 ;
V_10 |= V_659 ;
F_129 ( V_671 , V_10 ) ;
F_129 ( V_668 , V_669 ) ;
if ( F_62 ( F_11 ( V_668 ) & V_670 , 1 ) )
F_132 ( L_102 ) ;
V_10 = F_11 ( V_666 ) ;
V_10 &= ~ V_673 ;
V_10 |= V_11 ;
V_10 &= ~ V_674 ;
if ( V_658 >= 500000 )
V_10 |= V_674 ;
V_10 &= ~ V_667 ;
V_10 |= ( V_658 - 1000 ) / 500 ;
F_129 ( V_666 , V_10 ) ;
}
F_2 ( & V_2 -> V_570 . V_571 ) ;
V_305 = F_367 ( V_2 , V_665 ,
F_185 ( V_658 , 25000 ) ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
if ( V_305 ) {
F_132 ( L_103 ,
V_305 , V_658 ) ;
return;
}
F_435 ( V_16 ) ;
}
void F_438 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_10 ;
V_10 = F_11 ( V_675 ) ;
V_10 &= ~ V_676 ;
F_129 ( V_675 , V_10 ) ;
F_155 ( V_2 , V_242 ) ;
if ( F_11 ( V_668 ) & V_669 ) {
F_153 ( L_104 ) ;
return;
}
F_436 ( V_16 , 624000 ) ;
F_129 ( V_677 , F_11 ( V_677 ) | V_678 ) ;
F_130 ( V_677 ) ;
F_131 ( 10 ) ;
if ( ! ( F_11 ( V_677 ) & V_679 ) )
F_132 ( L_105 ) ;
}
void F_439 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
F_129 ( V_677 , F_11 ( V_677 ) & ~ V_678 ) ;
F_130 ( V_677 ) ;
F_131 ( 10 ) ;
if ( F_11 ( V_677 ) & V_679 )
F_132 ( L_106 ) ;
F_436 ( V_16 , 19200 ) ;
F_88 ( V_2 , V_242 ) ;
}
static unsigned int F_440 ( unsigned int V_680 )
{
return ( V_680 - 1000 ) / 500 ;
}
static unsigned int F_441 ( unsigned int V_680 )
{
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < F_302 ( V_681 ) ; V_50 ++ ) {
const struct V_682 * V_683 = & V_681 [ V_50 ] ;
if ( V_683 -> V_680 == V_680 )
return V_683 -> V_85 ;
}
return 8100 ;
}
static void
F_442 ( struct V_1 * V_2 , unsigned int V_684 )
{
unsigned int V_685 ;
T_1 V_10 ;
V_10 = F_11 ( V_666 ) ;
V_10 &= ~ V_686 | ~ V_667 ;
V_10 |= V_687 ;
if ( V_684 == 8640 )
V_685 = 308570 ;
else
V_685 = 337500 ;
V_10 = V_687 | F_440 ( V_685 ) ;
F_129 ( V_666 , V_10 ) ;
F_130 ( V_666 ) ;
V_10 = F_11 ( V_688 ) ;
V_10 &= ~ ( F_443 ( V_689 ) | F_444 ( V_689 ) |
F_445 ( V_689 ) ) ;
V_10 |= F_446 ( V_689 ) ;
if ( V_684 == 8640 )
V_10 |= F_447 ( V_690 ,
V_689 ) ;
else
V_10 |= F_447 ( V_691 ,
V_689 ) ;
F_129 ( V_688 , V_10 ) ;
F_130 ( V_688 ) ;
F_129 ( V_692 , F_11 ( V_692 ) | V_693 ) ;
if ( F_62 ( F_11 ( V_692 ) & V_694 , 5 ) )
F_132 ( L_107 ) ;
}
static bool F_448 ( struct V_1 * V_2 )
{
int V_305 ;
T_1 V_10 ;
V_10 = V_695 ;
F_2 ( & V_2 -> V_570 . V_571 ) ;
V_305 = F_449 ( V_2 , V_696 , & V_10 ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
return V_305 == 0 && ( V_10 & V_697 ) ;
}
static bool F_450 ( struct V_1 * V_2 )
{
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < 15 ; V_50 ++ ) {
if ( F_448 ( V_2 ) )
return true ;
F_131 ( 10 ) ;
}
return false ;
}
static void F_451 ( struct V_1 * V_2 , unsigned int V_680 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_1 V_698 , V_699 ;
F_16 ( L_108 , V_680 ) ;
if ( ! F_450 ( V_2 ) ) {
F_132 ( L_109 ) ;
return;
}
switch( V_680 ) {
case 450000 :
case 432000 :
V_698 = V_700 ;
V_699 = 1 ;
break;
case 540000 :
V_698 = V_701 ;
V_699 = 2 ;
break;
case 308570 :
case 337500 :
default:
V_698 = V_687 ;
V_699 = 0 ;
break;
case 617140 :
case 675000 :
V_698 = V_702 ;
V_699 = 3 ;
break;
}
F_129 ( V_666 , V_698 | F_440 ( V_680 ) ) ;
F_130 ( V_666 ) ;
F_2 ( & V_2 -> V_570 . V_571 ) ;
F_367 ( V_2 , V_696 , V_699 ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
F_435 ( V_16 ) ;
}
void F_452 ( struct V_1 * V_2 )
{
F_129 ( V_677 , F_11 ( V_677 ) & ~ V_678 ) ;
F_130 ( V_677 ) ;
F_131 ( 10 ) ;
if ( F_11 ( V_677 ) & V_679 )
F_132 ( L_110 ) ;
F_129 ( V_692 , F_11 ( V_692 ) & ~ V_693 ) ;
if ( F_62 ( ! ( F_11 ( V_692 ) & V_694 ) , 1 ) )
F_132 ( L_111 ) ;
}
void F_453 ( struct V_1 * V_2 )
{
unsigned int V_684 ;
if ( ! ( F_11 ( V_692 ) & V_693 ) ) {
V_684 = F_441 ( V_2 -> V_703 ) ;
F_442 ( V_2 , V_684 ) ;
}
F_451 ( V_2 , V_2 -> V_703 ) ;
F_129 ( V_677 , F_11 ( V_677 ) | V_678 ) ;
F_130 ( V_677 ) ;
F_131 ( 10 ) ;
if ( ! ( F_11 ( V_677 ) & V_679 ) )
F_132 ( L_112 ) ;
}
int F_454 ( struct V_1 * V_2 )
{
T_2 V_704 = F_11 ( V_692 ) ;
T_2 V_705 = F_11 ( V_666 ) ;
int V_680 = V_2 -> V_703 ;
if ( ( F_11 ( F_455 ( 0x18 ) ) & 0x00FFFFFF ) == 0 )
goto V_706;
if ( ! ( ( V_704 & V_693 ) && ( V_704 & V_694 ) ) )
goto V_706;
if ( V_705 == ( ( V_705 & V_686 ) | F_440 ( V_680 ) ) )
return false ;
V_706:
V_2 -> V_703 = V_2 -> V_647 ;
F_453 ( V_2 ) ;
return true ;
}
static void F_456 ( struct V_15 * V_16 , int V_644 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 , V_707 ;
F_9 ( V_2 -> V_449 . V_656 ( V_16 )
!= V_2 -> V_645 ) ;
if ( V_644 >= 320000 )
V_707 = 2 ;
else if ( V_644 == 266667 )
V_707 = 1 ;
else
V_707 = 0 ;
F_2 ( & V_2 -> V_570 . V_571 ) ;
V_10 = F_457 ( V_2 , V_708 ) ;
V_10 &= ~ V_709 ;
V_10 |= ( V_707 << V_710 ) ;
F_458 ( V_2 , V_708 , V_10 ) ;
if ( F_62 ( ( F_457 ( V_2 , V_708 ) &
V_711 ) == ( V_707 << V_712 ) ,
50 ) ) {
F_132 ( L_113 ) ;
}
F_4 ( & V_2 -> V_570 . V_571 ) ;
F_2 ( & V_2 -> V_5 ) ;
if ( V_644 == 400000 ) {
T_1 V_11 ;
V_11 = F_7 ( V_2 -> V_3 << 1 , V_644 ) - 1 ;
V_10 = F_3 ( V_2 , V_713 ) ;
V_10 &= ~ V_12 ;
V_10 |= V_11 ;
F_459 ( V_2 , V_713 , V_10 ) ;
if ( F_62 ( ( F_3 ( V_2 , V_713 ) &
V_13 ) == ( V_11 << V_14 ) ,
50 ) )
F_132 ( L_113 ) ;
}
V_10 = F_460 ( V_2 , V_714 ) ;
V_10 &= ~ 0x7f ;
if ( V_644 == 400000 )
V_10 |= 4500 / 250 ;
else
V_10 |= 3000 / 250 ;
F_461 ( V_2 , V_714 , V_10 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_435 ( V_16 ) ;
}
static void F_462 ( struct V_15 * V_16 , int V_644 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 , V_707 ;
F_9 ( V_2 -> V_449 . V_656 ( V_16 )
!= V_2 -> V_645 ) ;
switch ( V_644 ) {
case 333333 :
case 320000 :
case 266667 :
case 200000 :
break;
default:
F_180 ( V_644 ) ;
return;
}
V_707 = F_7 ( V_2 -> V_3 << 1 , V_644 ) - 1 ;
F_2 ( & V_2 -> V_570 . V_571 ) ;
V_10 = F_457 ( V_2 , V_708 ) ;
V_10 &= ~ V_715 ;
V_10 |= ( V_707 << V_716 ) ;
F_458 ( V_2 , V_708 , V_10 ) ;
if ( F_62 ( ( F_457 ( V_2 , V_708 ) &
V_717 ) == ( V_707 << V_718 ) ,
50 ) ) {
F_132 ( L_113 ) ;
}
F_4 ( & V_2 -> V_570 . V_571 ) ;
F_435 ( V_16 ) ;
}
static int F_463 ( struct V_1 * V_2 ,
int V_719 )
{
int V_720 = ( V_2 -> V_3 << 1 ) % 320000 != 0 ? 333333 : 320000 ;
int V_54 = F_14 ( V_2 ) ? 95 : 90 ;
if ( ! F_14 ( V_2 ) &&
V_719 > V_720 * V_54 / 100 )
return 400000 ;
else if ( V_719 > 266667 * V_54 / 100 )
return V_720 ;
else if ( V_719 > 0 )
return 266667 ;
else
return 200000 ;
}
static int F_464 ( struct V_1 * V_2 ,
int V_719 )
{
if ( V_719 > 576000 * 9 / 10 )
return 624000 ;
else if ( V_719 > 384000 * 9 / 10 )
return 576000 ;
else if ( V_719 > 288000 * 9 / 10 )
return 384000 ;
else if ( V_719 > 144000 * 9 / 10 )
return 288000 ;
else
return 144000 ;
}
static int F_465 ( struct V_15 * V_16 ,
struct V_45 * V_36 )
{
struct V_37 * V_37 ;
struct V_43 * V_44 ;
int V_719 = 0 ;
F_140 (dev, intel_crtc) {
V_44 = F_466 ( V_36 , V_37 ) ;
if ( F_467 ( V_44 ) )
return F_468 ( V_44 ) ;
if ( ! V_44 -> V_40 . V_243 )
continue;
V_719 = V_91 ( V_719 ,
V_44 -> V_40 . V_116 . V_117 ) ;
}
return V_719 ;
}
static int F_469 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_719 = F_465 ( V_16 , V_36 ) ;
if ( V_719 < 0 )
return V_719 ;
F_355 ( V_36 ) -> V_644 =
F_463 ( V_2 , V_719 ) ;
return 0 ;
}
static int F_470 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_719 = F_465 ( V_16 , V_36 ) ;
if ( V_719 < 0 )
return V_719 ;
F_355 ( V_36 ) -> V_644 =
F_464 ( V_2 , V_719 ) ;
return 0 ;
}
static void F_471 ( struct V_1 * V_2 )
{
unsigned int V_721 , V_722 ;
if ( F_14 ( V_2 ) )
V_722 = F_472 ( 12 ) ;
else
V_722 = F_472 ( 8 ) ;
if ( V_2 -> V_645 >= V_2 -> V_31 ) {
if ( F_14 ( V_2 ) )
V_721 = V_723 ;
else
V_721 = F_472 ( 15 ) ;
} else {
V_721 = V_722 ;
}
F_129 ( V_724 , V_725 |
V_722 ) ;
F_129 ( V_724 , V_725 |
V_721 | V_726 ) ;
F_9 ( F_11 ( V_724 ) & V_726 ) ;
}
static void F_473 ( struct V_45 * V_727 )
{
struct V_15 * V_16 = V_727 -> V_16 ;
unsigned int V_728 = F_355 ( V_727 ) -> V_644 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_155 ( V_2 , V_729 ) ;
if ( F_14 ( V_16 ) )
F_462 ( V_16 , V_728 ) ;
else
F_456 ( V_16 , V_728 ) ;
F_471 ( V_2 ) ;
F_88 ( V_2 , V_729 ) ;
}
static void F_474 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = F_204 ( V_16 ) ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 ;
if ( F_9 ( V_37 -> V_112 ) )
return;
if ( V_37 -> V_115 -> V_532 )
F_391 ( V_37 , V_600 ) ;
F_392 ( V_37 ) ;
if ( F_14 ( V_16 ) && V_119 == V_157 ) {
struct V_1 * V_2 = V_16 -> V_17 ;
F_129 ( F_475 ( V_119 ) , V_730 ) ;
F_129 ( F_476 ( V_119 ) , 0 ) ;
}
F_477 ( V_37 ) ;
V_37 -> V_112 = true ;
F_347 ( V_2 , V_119 , true ) ;
F_22 (dev, crtc, encoder)
if ( V_42 -> V_731 )
V_42 -> V_731 ( V_42 ) ;
if ( ! V_37 -> V_115 -> V_260 ) {
if ( F_14 ( V_16 ) ) {
F_478 ( V_37 , V_37 -> V_115 ) ;
F_134 ( V_37 , V_37 -> V_115 ) ;
} else {
F_479 ( V_37 , V_37 -> V_115 ) ;
F_126 ( V_37 , V_37 -> V_115 ) ;
}
}
F_22 (dev, crtc, encoder)
if ( V_42 -> V_602 )
V_42 -> V_602 ( V_42 ) ;
F_414 ( V_37 ) ;
F_370 ( V_38 ) ;
F_167 ( V_37 ) ;
F_101 ( V_38 ) ;
F_395 ( V_38 ) ;
F_22 (dev, crtc, encoder)
V_42 -> V_243 ( V_42 ) ;
}
static void F_480 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_129 ( F_481 ( V_38 -> V_119 ) , V_38 -> V_115 -> V_213 . V_732 ) ;
F_129 ( F_482 ( V_38 -> V_119 ) , V_38 -> V_115 -> V_213 . V_733 ) ;
}
static void F_483 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = F_204 ( V_16 ) ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 ;
if ( F_9 ( V_37 -> V_112 ) )
return;
F_480 ( V_37 ) ;
if ( V_37 -> V_115 -> V_532 )
F_391 ( V_37 , V_600 ) ;
F_392 ( V_37 ) ;
F_477 ( V_37 ) ;
V_37 -> V_112 = true ;
if ( ! F_33 ( V_16 ) )
F_347 ( V_2 , V_119 , true ) ;
F_22 (dev, crtc, encoder)
if ( V_42 -> V_602 )
V_42 -> V_602 ( V_42 ) ;
F_141 ( V_37 ) ;
F_414 ( V_37 ) ;
F_370 ( V_38 ) ;
F_382 ( V_38 ) ;
F_167 ( V_37 ) ;
F_101 ( V_38 ) ;
F_395 ( V_38 ) ;
F_22 (dev, crtc, encoder)
V_42 -> V_243 ( V_42 ) ;
F_396 ( V_37 ) ;
}
static void F_484 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! V_38 -> V_115 -> V_611 . V_612 )
return;
F_127 ( V_2 , V_38 -> V_119 ) ;
F_16 ( L_114 ,
F_11 ( V_613 ) ) ;
F_129 ( V_613 , 0 ) ;
}
static void F_485 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 ;
F_307 ( V_16 , V_119 ) ;
F_22 (dev, crtc, encoder)
V_42 -> V_244 ( V_42 ) ;
F_408 ( V_38 ) ;
F_101 ( V_38 ) ;
F_174 ( V_37 ) ;
F_484 ( V_37 ) ;
F_22 (dev, crtc, encoder)
if ( V_42 -> V_609 )
V_42 -> V_609 ( V_42 ) ;
if ( ! V_37 -> V_115 -> V_260 ) {
if ( F_14 ( V_16 ) )
F_146 ( V_2 , V_119 ) ;
else if ( F_13 ( V_16 ) )
F_145 ( V_2 , V_119 ) ;
else
F_144 ( V_37 ) ;
}
F_22 (dev, crtc, encoder)
if ( V_42 -> V_734 )
V_42 -> V_734 ( V_42 ) ;
if ( ! F_33 ( V_16 ) )
F_347 ( V_2 , V_119 , false ) ;
F_409 ( V_37 ) ;
}
static void F_486 ( struct V_111 * V_38 )
{
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_1 * V_2 = F_204 ( V_38 -> V_16 ) ;
enum V_165 V_636 ;
unsigned long V_637 ;
if ( ! V_37 -> V_112 )
return;
if ( F_219 ( V_38 -> V_113 -> V_36 ) -> V_361 ) {
F_9 ( V_37 -> V_458 ) ;
F_221 ( V_38 ) ;
F_386 ( V_38 , 1 << F_220 ( V_38 -> V_113 ) ) ;
F_219 ( V_38 -> V_113 -> V_36 ) -> V_361 = false ;
}
V_2 -> V_449 . V_735 ( V_38 ) ;
V_37 -> V_112 = false ;
F_382 ( V_38 ) ;
F_156 ( V_37 ) ;
V_637 = V_37 -> V_640 ;
F_425 (domain, domains)
F_88 ( V_2 , V_636 ) ;
V_37 -> V_640 = 0 ;
}
int F_270 ( struct V_15 * V_16 )
{
struct V_736 * V_115 = & V_16 -> V_737 ;
struct V_738 * V_739 = V_115 -> V_740 ;
struct V_45 * V_36 ;
struct V_111 * V_38 ;
unsigned V_238 = 0 ;
int V_305 = 0 ;
if ( F_9 ( ! V_739 ) )
return 0 ;
F_487 ( & V_739 -> V_741 ) ;
V_36 = F_488 ( V_16 ) ;
if ( F_9 ( ! V_36 ) )
return - V_742 ;
V_36 -> V_740 = V_739 ;
V_36 -> V_646 = true ;
F_217 (dev, crtc) {
struct V_35 * V_44 =
F_489 ( V_36 , V_38 ) ;
V_305 = F_490 ( V_44 ) ;
if ( V_305 )
goto free;
if ( ! V_44 -> V_112 )
continue;
V_44 -> V_112 = false ;
V_238 |= 1 << F_157 ( V_38 ) ;
}
if ( V_238 ) {
V_305 = F_491 ( V_36 ) ;
if ( ! V_305 ) {
F_217 (dev, crtc)
if ( V_238 & ( 1 << F_157 ( V_38 ) ) )
V_38 -> V_36 -> V_112 = true ;
return V_305 ;
}
}
free:
if ( V_305 )
F_132 ( L_115 , V_305 ) ;
F_492 ( V_36 ) ;
return V_305 ;
}
void F_493 ( struct V_743 * V_42 )
{
struct V_41 * V_41 = F_25 ( V_42 ) ;
F_494 ( V_42 ) ;
F_216 ( V_41 ) ;
}
static void F_495 ( struct V_744 * V_47 )
{
struct V_111 * V_38 = V_47 -> V_40 . V_36 -> V_38 ;
F_153 ( L_116 ,
V_47 -> V_40 . V_40 . V_241 ,
V_47 -> V_40 . V_8 ) ;
if ( V_47 -> V_140 ( V_47 ) ) {
struct V_41 * V_42 = V_47 -> V_42 ;
struct V_48 * V_745 = V_47 -> V_40 . V_36 ;
F_66 ( ! V_38 ,
L_117 ) ;
if ( ! V_38 )
return;
F_66 ( ! V_38 -> V_36 -> V_112 ,
L_118 ) ;
if ( ! V_42 || V_42 -> type == V_630 )
return;
F_66 ( V_745 -> V_52 != & V_42 -> V_40 ,
L_119 ) ;
F_66 ( V_745 -> V_38 != V_42 -> V_40 . V_38 ,
L_120 ) ;
} else {
F_66 ( V_38 && V_38 -> V_36 -> V_112 ,
L_121 ) ;
F_66 ( ! V_38 && V_47 -> V_40 . V_36 -> V_52 ,
L_122 ) ;
}
}
int F_496 ( struct V_744 * V_47 )
{
F_497 ( & V_47 -> V_40 ) ;
if ( ! V_47 -> V_40 . V_36 )
return - V_742 ;
return 0 ;
}
struct V_744 * F_498 ( void )
{
struct V_744 * V_47 ;
V_47 = F_499 ( sizeof *V_47 , V_746 ) ;
if ( ! V_47 )
return NULL ;
if ( F_496 ( V_47 ) < 0 ) {
F_216 ( V_47 ) ;
return NULL ;
}
return V_47 ;
}
bool F_500 ( struct V_744 * V_47 )
{
enum V_119 V_119 = 0 ;
struct V_41 * V_42 = V_47 -> V_42 ;
return V_42 -> V_140 ( V_42 , & V_119 ) ;
}
static int F_501 ( struct V_43 * V_44 )
{
if ( V_44 -> V_40 . V_243 && V_44 -> V_261 )
return V_44 -> V_474 ;
return 0 ;
}
static int F_502 ( struct V_15 * V_16 , enum V_119 V_119 ,
struct V_43 * V_212 )
{
struct V_45 * V_36 = V_212 -> V_40 . V_36 ;
struct V_37 * V_747 ;
struct V_43 * V_748 ;
F_153 ( L_123 ,
F_80 ( V_119 ) , V_212 -> V_474 ) ;
if ( V_212 -> V_474 > 4 ) {
F_153 ( L_124 ,
F_80 ( V_119 ) , V_212 -> V_474 ) ;
return - V_307 ;
}
if ( F_235 ( V_16 ) || F_236 ( V_16 ) ) {
if ( V_212 -> V_474 > 2 ) {
F_153 ( L_125 ,
V_212 -> V_474 ) ;
return - V_307 ;
} else {
return 0 ;
}
}
if ( F_60 ( V_16 ) -> V_749 == 2 )
return 0 ;
switch ( V_119 ) {
case V_148 :
return 0 ;
case V_157 :
if ( V_212 -> V_474 <= 2 )
return 0 ;
V_747 = F_50 ( F_503 ( V_16 , V_524 ) ) ;
V_748 =
F_466 ( V_36 , V_747 ) ;
if ( F_467 ( V_748 ) )
return F_468 ( V_748 ) ;
if ( F_501 ( V_748 ) > 0 ) {
F_153 ( L_126 ,
F_80 ( V_119 ) , V_212 -> V_474 ) ;
return - V_307 ;
}
return 0 ;
case V_524 :
if ( V_212 -> V_474 > 2 ) {
F_153 ( L_127 ,
F_80 ( V_119 ) , V_212 -> V_474 ) ;
return - V_307 ;
}
V_747 = F_50 ( F_503 ( V_16 , V_157 ) ) ;
V_748 =
F_466 ( V_36 , V_747 ) ;
if ( F_467 ( V_748 ) )
return F_468 ( V_748 ) ;
if ( F_501 ( V_748 ) > 2 ) {
F_153 ( L_128 ) ;
return - V_307 ;
}
return 0 ;
default:
F_148 () ;
}
}
static int F_504 ( struct V_37 * V_37 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
const struct V_533 * V_116 = & V_212 -> V_40 . V_116 ;
int V_750 , V_751 , V_752 , V_305 ;
bool V_753 = false ;
V_479:
V_751 = F_17 ( V_16 ) * F_505 ( 100 ) / F_506 ( 1 ) / 10 ;
V_752 = V_116 -> V_117 ;
V_750 = F_507 ( V_752 , V_751 ,
V_212 -> V_754 ) ;
V_212 -> V_474 = V_750 ;
F_508 ( V_212 -> V_754 , V_750 , V_752 ,
V_751 , & V_212 -> V_601 ) ;
V_305 = F_502 ( V_37 -> V_40 . V_16 ,
V_37 -> V_119 , V_212 ) ;
if ( V_305 == - V_307 && V_212 -> V_754 > 6 * 3 ) {
V_212 -> V_754 -= 2 * 3 ;
F_153 ( L_129 ,
V_212 -> V_754 ) ;
V_753 = true ;
V_212 -> V_755 = true ;
goto V_479;
}
if ( V_753 )
return V_756 ;
return V_305 ;
}
static bool F_509 ( struct V_1 * V_2 ,
struct V_43 * V_212 )
{
if ( V_212 -> V_754 > 24 )
return false ;
if ( F_235 ( V_2 -> V_16 ) )
return true ;
return F_510 ( V_212 ) <=
V_2 -> V_647 * 95 / 100 ;
}
static void F_511 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
V_212 -> V_569 = V_757 . V_758 &&
F_397 ( V_38 ) &&
F_509 ( V_2 , V_212 ) ;
}
static bool F_512 ( const struct V_37 * V_38 )
{
const struct V_1 * V_2 = F_204 ( V_38 -> V_40 . V_16 ) ;
return F_60 ( V_2 ) -> V_127 < 4 &&
( V_38 -> V_119 == V_148 || F_513 ( V_2 ) ) ;
}
static int F_514 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
const struct V_533 * V_116 = & V_212 -> V_40 . V_116 ;
if ( F_60 ( V_16 ) -> V_127 < 4 ) {
int V_759 = V_2 -> V_647 * 9 / 10 ;
if ( F_512 ( V_38 ) &&
V_116 -> V_117 > V_759 ) {
V_759 *= 2 ;
V_212 -> V_262 = true ;
}
if ( V_116 -> V_117 > V_759 ) {
F_153 ( L_130 ,
V_116 -> V_117 , V_759 ,
F_515 ( V_212 -> V_262 ) ) ;
return - V_307 ;
}
}
if ( ( F_23 ( V_212 , V_55 ) &&
F_27 ( V_16 ) ) || V_212 -> V_262 )
V_212 -> V_381 &= ~ 1 ;
if ( ( F_60 ( V_16 ) -> V_127 > 4 || F_31 ( V_16 ) ) &&
V_116 -> V_760 == V_116 -> V_561 )
return - V_307 ;
if ( F_398 ( V_16 ) )
F_511 ( V_38 , V_212 ) ;
if ( V_212 -> V_261 )
return F_504 ( V_38 , V_212 ) ;
return 0 ;
}
static int F_516 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_204 ( V_16 ) ;
T_2 V_704 = F_11 ( V_692 ) ;
T_2 V_705 = F_11 ( V_666 ) ;
T_2 V_761 ;
if ( ! ( V_704 & V_693 ) )
return 24000 ;
if ( ( V_705 & V_686 ) == V_701 )
return 540000 ;
V_761 = ( F_11 ( V_688 ) &
F_445 ( V_689 ) ) >> 1 ;
if ( V_761 == V_762 ||
V_761 == V_690 ) {
switch ( V_705 & V_686 ) {
case V_700 :
return 432000 ;
case V_687 :
return 308570 ;
case V_702 :
return 617140 ;
default:
F_6 ( 1 , L_131 ) ;
}
} else {
switch ( V_705 & V_686 ) {
case V_700 :
return 450000 ;
case V_687 :
return 337500 ;
case V_702 :
return 675000 ;
default:
F_6 ( 1 , L_131 ) ;
}
}
return 24000 ;
}
static int F_517 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_204 ( V_16 ) ;
T_2 V_705 = F_11 ( V_666 ) ;
T_2 V_763 = F_11 ( V_671 ) & V_672 ;
T_2 V_764 = F_11 ( V_668 ) ;
int V_644 ;
if ( ! ( V_764 & V_669 ) )
return 19200 ;
V_644 = 19200 * V_763 / 2 ;
switch ( V_705 & V_673 ) {
case V_664 :
return V_644 ;
case V_663 :
return V_644 * 2 / 3 ;
case V_662 :
return V_644 / 2 ;
case V_661 :
return V_644 / 4 ;
}
return 19200 ;
}
static int F_518 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_765 = F_11 ( V_766 ) ;
T_2 V_680 = V_765 & V_767 ;
if ( V_765 & V_768 )
return 800000 ;
else if ( F_11 ( V_653 ) & V_654 )
return 450000 ;
else if ( V_680 == V_769 )
return 450000 ;
else if ( V_680 == V_770 )
return 540000 ;
else if ( V_680 == V_771 )
return 337500 ;
else
return 675000 ;
}
static int F_519 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_765 = F_11 ( V_766 ) ;
T_2 V_680 = V_765 & V_767 ;
if ( V_765 & V_768 )
return 800000 ;
else if ( F_11 ( V_653 ) & V_654 )
return 450000 ;
else if ( V_680 == V_769 )
return 450000 ;
else if ( F_520 ( V_16 ) )
return 337500 ;
else
return 540000 ;
}
static int F_521 ( struct V_15 * V_16 )
{
return F_5 ( F_204 ( V_16 ) , L_132 ,
V_713 ) ;
}
static int F_522 ( struct V_15 * V_16 )
{
return 450000 ;
}
static int F_523 ( struct V_15 * V_16 )
{
return 400000 ;
}
static int F_524 ( struct V_15 * V_16 )
{
return 333333 ;
}
static int F_525 ( struct V_15 * V_16 )
{
return 200000 ;
}
static int F_526 ( struct V_15 * V_16 )
{
T_7 V_772 = 0 ;
F_527 ( V_16 -> V_773 , V_774 , & V_772 ) ;
switch ( V_772 & V_775 ) {
case V_776 :
return 266667 ;
case V_777 :
return 333333 ;
case V_778 :
return 444444 ;
case V_779 :
return 200000 ;
default:
F_132 ( L_133 , V_772 ) ;
case V_780 :
return 133333 ;
case V_781 :
return 166667 ;
}
}
static int F_528 ( struct V_15 * V_16 )
{
T_7 V_772 = 0 ;
F_527 ( V_16 -> V_773 , V_774 , & V_772 ) ;
if ( V_772 & V_782 )
return 133333 ;
else {
switch ( V_772 & V_775 ) {
case V_783 :
return 333333 ;
default:
case V_784 :
return 190000 ;
}
}
}
static int F_529 ( struct V_15 * V_16 )
{
return 266667 ;
}
static int F_530 ( struct V_15 * V_16 )
{
T_7 V_785 = 0 ;
if ( V_16 -> V_773 -> V_786 == 0x1 )
return 133333 ;
F_531 ( V_16 -> V_773 -> V_787 ,
F_532 ( 0 , 3 ) , V_788 , & V_785 ) ;
switch ( V_785 & V_789 ) {
case V_790 :
case V_791 :
case V_792 :
return 200000 ;
case V_793 :
return 250000 ;
case V_794 :
return 133333 ;
case V_795 :
case V_796 :
case V_797 :
return 266667 ;
}
return 0 ;
}
static int F_533 ( struct V_15 * V_16 )
{
return 133333 ;
}
static unsigned int F_534 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
static const unsigned int V_798 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 6400000 ,
} ;
static const unsigned int V_799 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 2666667 ,
} ;
static const unsigned int V_800 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 3333333 ,
[ 5 ] = 3566667 ,
[ 6 ] = 4266667 ,
} ;
static const unsigned int V_801 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
} ;
static const unsigned int V_802 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 2666667 ,
[ 5 ] = 4266667 ,
} ;
const unsigned int * V_803 ;
unsigned int V_85 ;
T_8 V_218 = 0 ;
if ( F_535 ( V_16 ) )
V_803 = V_802 ;
else if ( F_31 ( V_16 ) )
V_803 = V_801 ;
else if ( F_188 ( V_16 ) )
V_803 = V_800 ;
else if ( F_32 ( V_16 ) )
V_803 = V_799 ;
else if ( F_536 ( V_16 ) )
V_803 = V_798 ;
else
return 0 ;
V_218 = F_11 ( F_128 ( V_16 ) ? V_804 : V_805 ) ;
V_85 = V_803 [ V_218 & 0x7 ] ;
if ( V_85 == 0 )
F_132 ( L_134 , V_218 ) ;
else
F_153 ( L_135 , V_85 ) ;
return V_85 ;
}
static int F_537 ( struct V_15 * V_16 )
{
unsigned int V_806 , V_85 = F_534 ( V_16 ) ;
T_9 V_218 = 0 ;
F_527 ( V_16 -> V_773 , V_774 , & V_218 ) ;
V_806 = ( V_218 >> 12 ) & 0x1 ;
switch ( V_85 ) {
case 2666667 :
case 4000000 :
case 5333333 :
return V_806 ? 333333 : 222222 ;
case 3200000 :
return V_806 ? 320000 : 228571 ;
default:
F_132 ( L_136 , V_85 , V_218 ) ;
return 222222 ;
}
}
static int F_538 ( struct V_15 * V_16 )
{
static const T_8 V_807 [] = { 16 , 10 , 8 } ;
static const T_8 V_808 [] = { 20 , 12 , 10 } ;
static const T_8 V_809 [] = { 24 , 16 , 14 } ;
const T_8 * V_810 ;
unsigned int V_806 , V_85 = F_534 ( V_16 ) ;
T_9 V_218 = 0 ;
F_527 ( V_16 -> V_773 , V_774 , & V_218 ) ;
V_806 = ( ( V_218 >> 8 ) & 0x1f ) - 1 ;
if ( V_806 >= F_302 ( V_807 ) )
goto V_811;
switch ( V_85 ) {
case 3200000 :
V_810 = V_807 ;
break;
case 4000000 :
V_810 = V_808 ;
break;
case 5333333 :
V_810 = V_809 ;
break;
default:
goto V_811;
}
return F_7 ( V_85 , V_810 [ V_806 ] ) ;
V_811:
F_132 ( L_137 , V_85 , V_218 ) ;
return 200000 ;
}
static int F_539 ( struct V_15 * V_16 )
{
static const T_8 V_807 [] = { 12 , 10 , 8 , 7 , 5 , 16 } ;
static const T_8 V_808 [] = { 14 , 12 , 10 , 8 , 6 , 20 } ;
static const T_8 V_812 [] = { 20 , 14 , 12 , 10 , 8 , 24 } ;
static const T_8 V_809 [] = { 20 , 16 , 12 , 12 , 8 , 28 } ;
const T_8 * V_810 ;
unsigned int V_806 , V_85 = F_534 ( V_16 ) ;
T_9 V_218 = 0 ;
F_527 ( V_16 -> V_773 , V_774 , & V_218 ) ;
V_806 = ( V_218 >> 4 ) & 0x7 ;
if ( V_806 >= F_302 ( V_807 ) )
goto V_811;
switch ( V_85 ) {
case 3200000 :
V_810 = V_807 ;
break;
case 4000000 :
V_810 = V_808 ;
break;
case 4800000 :
V_810 = V_812 ;
break;
case 5333333 :
V_810 = V_809 ;
break;
default:
goto V_811;
}
return F_7 ( V_85 , V_810 [ V_806 ] ) ;
V_811:
F_132 ( L_138 , V_85 , V_218 ) ;
return 190476 ;
}
static void
F_540 ( T_2 * V_813 , T_2 * V_814 )
{
while ( * V_813 > V_815 ||
* V_814 > V_815 ) {
* V_813 >>= 1 ;
* V_814 >>= 1 ;
}
}
static void F_541 ( unsigned int V_79 , unsigned int V_84 ,
T_2 * V_816 , T_2 * V_817 )
{
* V_817 = F_542 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_816 = F_48 ( ( V_89 ) V_79 * * V_817 , V_84 ) ;
F_540 ( V_816 , V_817 ) ;
}
void
F_508 ( int V_391 , int V_818 ,
int V_819 , int V_820 ,
struct V_821 * V_822 )
{
V_822 -> V_823 = 64 ;
F_541 ( V_391 * V_819 ,
V_820 * V_818 * 8 ,
& V_822 -> V_824 , & V_822 -> V_825 ) ;
F_541 ( V_819 , V_820 ,
& V_822 -> V_826 , & V_822 -> V_827 ) ;
}
static inline bool F_543 ( struct V_1 * V_2 )
{
if ( V_757 . V_828 >= 0 )
return V_757 . V_828 != 0 ;
return V_2 -> V_829 . V_830
&& ! ( V_2 -> V_167 & V_831 ) ;
}
static int F_53 ( const struct V_43 * V_44 ,
int V_51 )
{
struct V_15 * V_16 = V_44 -> V_40 . V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_53 ;
F_9 ( ! V_44 -> V_40 . V_36 ) ;
if ( F_13 ( V_16 ) || F_14 ( V_16 ) || F_30 ( V_16 ) ) {
V_53 = 100000 ;
} else if ( F_23 ( V_44 , V_55 ) &&
F_543 ( V_2 ) && V_51 < 2 ) {
V_53 = V_2 -> V_829 . V_832 ;
F_153 ( L_139 , V_53 ) ;
} else if ( ! F_33 ( V_16 ) ) {
V_53 = 96000 ;
} else {
V_53 = 48000 ;
}
return V_53 ;
}
static T_2 F_544 ( struct V_87 * V_87 )
{
return ( 1 << V_87 -> V_84 ) << 16 | V_87 -> V_80 ;
}
static T_2 F_545 ( struct V_87 * V_87 )
{
return V_87 -> V_84 << 16 | V_87 -> V_88 << 8 | V_87 -> V_80 ;
}
static void F_546 ( struct V_37 * V_38 ,
struct V_43 * V_44 ,
T_4 * V_833 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
T_1 V_834 , V_835 = 0 ;
if ( F_32 ( V_16 ) ) {
V_834 = F_544 ( & V_44 -> V_87 ) ;
if ( V_833 )
V_835 = F_544 ( V_833 ) ;
} else {
V_834 = F_545 ( & V_44 -> V_87 ) ;
if ( V_833 )
V_835 = F_545 ( V_833 ) ;
}
V_44 -> V_213 . V_732 = V_834 ;
V_38 -> V_836 = false ;
if ( F_23 ( V_44 , V_55 ) &&
V_833 ) {
V_44 -> V_213 . V_733 = V_835 ;
V_38 -> V_836 = true ;
} else {
V_44 -> V_213 . V_733 = V_834 ;
}
}
static void F_547 ( struct V_1 * V_2 , enum V_119
V_119 )
{
T_1 V_837 ;
V_837 = F_136 ( V_2 , V_119 , F_548 ( 1 ) ) ;
V_837 &= 0xffffff00 ;
V_837 |= 0x00000030 ;
F_138 ( V_2 , V_119 , F_548 ( 1 ) , V_837 ) ;
V_837 = F_136 ( V_2 , V_119 , V_838 ) ;
V_837 &= 0x8cffffff ;
V_837 = 0x8c000000 ;
F_138 ( V_2 , V_119 , V_838 , V_837 ) ;
V_837 = F_136 ( V_2 , V_119 , F_548 ( 1 ) ) ;
V_837 &= 0xffffff00 ;
F_138 ( V_2 , V_119 , F_548 ( 1 ) , V_837 ) ;
V_837 = F_136 ( V_2 , V_119 , V_838 ) ;
V_837 &= 0x00ffffff ;
V_837 |= 0xb0000000 ;
F_138 ( V_2 , V_119 , V_838 , V_837 ) ;
}
static void F_549 ( struct V_37 * V_38 ,
struct V_821 * V_822 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
F_129 ( F_550 ( V_119 ) , F_551 ( V_822 -> V_823 ) | V_822 -> V_824 ) ;
F_129 ( F_552 ( V_119 ) , V_822 -> V_825 ) ;
F_129 ( F_553 ( V_119 ) , V_822 -> V_826 ) ;
F_129 ( F_554 ( V_119 ) , V_822 -> V_827 ) ;
}
static void F_393 ( struct V_37 * V_38 ,
struct V_821 * V_822 ,
struct V_821 * V_839 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
enum V_118 V_118 = V_38 -> V_115 -> V_121 ;
if ( F_60 ( V_16 ) -> V_127 >= 5 ) {
F_129 ( F_346 ( V_118 ) , F_551 ( V_822 -> V_823 ) | V_822 -> V_824 ) ;
F_129 ( F_555 ( V_118 ) , V_822 -> V_825 ) ;
F_129 ( F_556 ( V_118 ) , V_822 -> V_826 ) ;
F_129 ( F_557 ( V_118 ) , V_822 -> V_827 ) ;
if ( V_839 && ( F_14 ( V_16 ) || F_60 ( V_16 ) -> V_127 < 8 ) &&
V_38 -> V_115 -> V_840 ) {
F_129 ( F_558 ( V_118 ) ,
F_551 ( V_839 -> V_823 ) | V_839 -> V_824 ) ;
F_129 ( F_559 ( V_118 ) , V_839 -> V_825 ) ;
F_129 ( F_560 ( V_118 ) , V_839 -> V_826 ) ;
F_129 ( F_561 ( V_118 ) , V_839 -> V_827 ) ;
}
} else {
F_129 ( F_562 ( V_119 ) , F_551 ( V_822 -> V_823 ) | V_822 -> V_824 ) ;
F_129 ( F_563 ( V_119 ) , V_822 -> V_825 ) ;
F_129 ( F_564 ( V_119 ) , V_822 -> V_826 ) ;
F_129 ( F_565 ( V_119 ) , V_822 -> V_827 ) ;
}
}
void F_391 ( struct V_37 * V_38 , enum V_841 V_822 )
{
struct V_821 * V_842 , * V_843 = NULL ;
if ( V_822 == V_600 ) {
V_842 = & V_38 -> V_115 -> V_842 ;
V_843 = & V_38 -> V_115 -> V_843 ;
} else if ( V_822 == V_844 ) {
V_842 = & V_38 -> V_115 -> V_843 ;
} else {
F_132 ( L_140 ) ;
return;
}
if ( V_38 -> V_115 -> V_261 )
F_549 ( V_38 , & V_38 -> V_115 -> V_842 ) ;
else
F_393 ( V_38 , V_842 , V_843 ) ;
}
static void F_566 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
T_1 V_87 , V_215 ;
V_87 = V_845 | V_224 |
V_222 | V_846 ;
if ( V_38 -> V_119 == V_157 )
V_87 |= V_223 ;
V_87 |= V_131 ;
V_212 -> V_213 . V_87 = V_87 ;
V_215 = ( V_212 -> V_605 - 1 )
<< V_847 ;
V_212 -> V_213 . V_215 = V_215 ;
}
static void F_479 ( struct V_37 * V_38 ,
const struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
T_1 V_848 ;
T_1 V_849 , V_850 , V_851 , V_852 , V_853 ;
T_1 V_854 , V_837 ;
F_2 ( & V_2 -> V_5 ) ;
V_849 = V_212 -> V_87 . V_84 ;
V_850 = V_212 -> V_87 . V_88 ;
V_851 = V_212 -> V_87 . V_80 ;
V_852 = V_212 -> V_87 . V_82 ;
V_853 = V_212 -> V_87 . V_83 ;
if ( V_119 == V_157 )
F_547 ( V_2 , V_119 ) ;
F_138 ( V_2 , V_119 , V_855 , 0x0100000f ) ;
V_837 = F_136 ( V_2 , V_119 , F_567 ( V_119 ) ) ;
V_837 &= 0x00ffffff ;
F_138 ( V_2 , V_119 , F_567 ( V_119 ) , V_837 ) ;
F_138 ( V_2 , V_119 , V_856 , 0x610 ) ;
V_848 = ( ( V_850 << V_857 ) | ( V_851 & V_858 ) ) ;
V_848 |= ( ( V_852 << V_859 ) | ( V_853 << V_860 ) ) ;
V_848 |= ( ( V_849 << V_861 ) ) ;
V_848 |= ( 1 << V_862 ) ;
V_848 |= ( V_863 << V_864 ) ;
F_138 ( V_2 , V_119 , F_568 ( V_119 ) , V_848 ) ;
V_848 |= V_865 ;
F_138 ( V_2 , V_119 , F_568 ( V_119 ) , V_848 ) ;
if ( V_212 -> V_866 == 162000 ||
F_21 ( V_38 , V_64 ) ||
F_21 ( V_38 , V_63 ) )
F_138 ( V_2 , V_119 , F_569 ( V_119 ) ,
0x009f0003 ) ;
else
F_138 ( V_2 , V_119 , F_569 ( V_119 ) ,
0x00d0000f ) ;
if ( V_212 -> V_532 ) {
if ( V_119 == V_148 )
F_138 ( V_2 , V_119 , F_570 ( V_119 ) ,
0x0df40000 ) ;
else
F_138 ( V_2 , V_119 , F_570 ( V_119 ) ,
0x0df70000 ) ;
} else {
if ( V_119 == V_148 )
F_138 ( V_2 , V_119 , F_570 ( V_119 ) ,
0x0df70000 ) ;
else
F_138 ( V_2 , V_119 , F_570 ( V_119 ) ,
0x0df40000 ) ;
}
V_854 = F_136 ( V_2 , V_119 , F_571 ( V_119 ) ) ;
V_854 = ( V_854 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_21 ( V_38 , V_525 ) ||
F_21 ( V_38 , V_526 ) )
V_854 |= 0x01000000 ;
F_138 ( V_2 , V_119 , F_571 ( V_119 ) , V_854 ) ;
F_138 ( V_2 , V_119 , F_572 ( V_119 ) , 0x87871000 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_573 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
V_212 -> V_213 . V_87 = V_225 |
V_224 | V_222 |
V_131 ;
if ( V_38 -> V_119 != V_148 )
V_212 -> V_213 . V_87 |= V_223 ;
V_212 -> V_213 . V_215 =
( V_212 -> V_605 - 1 ) << V_847 ;
}
static void F_478 ( struct V_37 * V_38 ,
const struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
T_5 V_230 = F_65 ( V_38 -> V_119 ) ;
enum V_216 V_217 = F_135 ( V_119 ) ;
T_1 V_867 , V_868 ;
T_1 V_849 , V_850 , V_851 , V_852 , V_853 , V_869 ;
T_1 V_870 ;
int V_85 ;
V_849 = V_212 -> V_87 . V_84 ;
V_869 = V_212 -> V_87 . V_80 & 0x3fffff ;
V_850 = V_212 -> V_87 . V_88 ;
V_851 = V_212 -> V_87 . V_80 >> 22 ;
V_852 = V_212 -> V_87 . V_82 ;
V_853 = V_212 -> V_87 . V_83 ;
V_85 = V_212 -> V_87 . V_85 ;
V_870 = 0 ;
V_867 = 0 ;
F_129 ( V_230 ,
V_212 -> V_213 . V_87 & ~ V_131 ) ;
F_2 ( & V_2 -> V_5 ) ;
F_138 ( V_2 , V_119 , F_574 ( V_217 ) ,
5 << V_871 |
V_852 << V_872 |
V_853 << V_873 |
1 << V_874 ) ;
F_138 ( V_2 , V_119 , F_575 ( V_217 ) , V_851 ) ;
F_138 ( V_2 , V_119 , F_576 ( V_217 ) ,
V_875 |
1 << V_876 ) ;
F_138 ( V_2 , V_119 , F_577 ( V_217 ) , V_869 ) ;
V_870 = F_136 ( V_2 , V_119 , F_578 ( V_217 ) ) ;
V_870 &= ~ ( V_877 | V_878 ) ;
V_870 |= ( 2 << V_879 ) ;
if ( V_869 )
V_870 |= V_878 ;
F_138 ( V_2 , V_119 , F_578 ( V_217 ) , V_870 ) ;
V_870 = F_136 ( V_2 , V_119 , F_579 ( V_217 ) ) ;
V_870 &= ~ ( V_880 |
V_881 ) ;
V_870 |= ( 0x5 << V_882 ) ;
if ( ! V_869 )
V_870 |= V_881 ;
F_138 ( V_2 , V_119 , F_579 ( V_217 ) , V_870 ) ;
if ( V_85 == 5400000 ) {
V_867 |= ( 0x3 << V_883 ) ;
V_867 |= ( 0x8 << V_884 ) ;
V_867 |= ( 0x1 << V_885 ) ;
V_868 = 0x9 ;
} else if ( V_85 <= 6200000 ) {
V_867 |= ( 0x5 << V_883 ) ;
V_867 |= ( 0xB << V_884 ) ;
V_867 |= ( 0x3 << V_885 ) ;
V_868 = 0x9 ;
} else if ( V_85 <= 6480000 ) {
V_867 |= ( 0x4 << V_883 ) ;
V_867 |= ( 0x9 << V_884 ) ;
V_867 |= ( 0x3 << V_885 ) ;
V_868 = 0x8 ;
} else {
V_867 |= ( 0x4 << V_883 ) ;
V_867 |= ( 0x9 << V_884 ) ;
V_867 |= ( 0x3 << V_885 ) ;
V_868 = 0 ;
}
F_138 ( V_2 , V_119 , F_580 ( V_217 ) , V_867 ) ;
V_870 = F_136 ( V_2 , V_119 , F_581 ( V_217 ) ) ;
V_870 &= ~ V_886 ;
V_870 |= ( V_868 << V_887 ) ;
F_138 ( V_2 , V_119 , F_581 ( V_217 ) , V_870 ) ;
F_138 ( V_2 , V_119 , F_137 ( V_217 ) ,
F_136 ( V_2 , V_119 , F_137 ( V_217 ) ) |
V_888 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
void F_582 ( struct V_15 * V_16 , enum V_119 V_119 ,
const struct V_87 * V_87 )
{
struct V_37 * V_38 =
F_50 ( F_503 ( V_16 , V_119 ) ) ;
struct V_43 V_212 = {
. V_40 . V_38 = & V_38 -> V_40 ,
. V_605 = 1 ,
. V_87 = * V_87 ,
} ;
if ( F_14 ( V_16 ) ) {
F_573 ( V_38 , & V_212 ) ;
F_478 ( V_38 , & V_212 ) ;
F_134 ( V_38 , & V_212 ) ;
} else {
F_566 ( V_38 , & V_212 ) ;
F_479 ( V_38 , & V_212 ) ;
F_126 ( V_38 , & V_212 ) ;
}
}
void F_583 ( struct V_15 * V_16 , enum V_119 V_119 )
{
if ( F_14 ( V_16 ) )
F_146 ( F_204 ( V_16 ) , V_119 ) ;
else
F_145 ( F_204 ( V_16 ) , V_119 ) ;
}
static void F_584 ( struct V_37 * V_38 ,
struct V_43 * V_44 ,
T_4 * V_833 ,
int V_51 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_87 ;
bool V_889 ;
struct V_87 * clock = & V_44 -> V_87 ;
F_546 ( V_38 , V_44 , V_833 ) ;
V_889 = F_23 ( V_44 , V_66 ) ||
F_23 ( V_44 , V_63 ) ;
V_87 = V_222 ;
if ( F_23 ( V_44 , V_55 ) )
V_87 |= V_890 ;
else
V_87 |= V_891 ;
if ( F_585 ( V_16 ) || F_586 ( V_16 ) || F_536 ( V_16 ) ) {
V_87 |= ( V_44 -> V_605 - 1 )
<< V_892 ;
}
if ( V_889 )
V_87 |= V_893 ;
if ( V_44 -> V_532 )
V_87 |= V_893 ;
if ( F_32 ( V_16 ) )
V_87 |= ( 1 << ( clock -> V_82 - 1 ) ) << V_894 ;
else {
V_87 |= ( 1 << ( clock -> V_82 - 1 ) ) << V_895 ;
if ( F_31 ( V_16 ) && V_833 )
V_87 |= ( 1 << ( V_833 -> V_82 - 1 ) ) << V_896 ;
}
switch ( clock -> V_83 ) {
case 5 :
V_87 |= V_897 ;
break;
case 7 :
V_87 |= V_898 ;
break;
case 10 :
V_87 |= V_899 ;
break;
case 14 :
V_87 |= V_900 ;
break;
}
if ( F_60 ( V_16 ) -> V_127 >= 4 )
V_87 |= ( 6 << V_901 ) ;
if ( V_44 -> V_902 )
V_87 |= V_903 ;
else if ( F_23 ( V_44 , V_55 ) &&
F_543 ( V_2 ) && V_51 < 2 )
V_87 |= V_904 ;
else
V_87 |= V_905 ;
V_87 |= V_131 ;
V_44 -> V_213 . V_87 = V_87 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
T_1 V_215 = ( V_44 -> V_605 - 1 )
<< V_847 ;
V_44 -> V_213 . V_215 = V_215 ;
}
}
static void F_587 ( struct V_37 * V_38 ,
struct V_43 * V_44 ,
T_4 * V_833 ,
int V_51 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_87 ;
struct V_87 * clock = & V_44 -> V_87 ;
F_546 ( V_38 , V_44 , V_833 ) ;
V_87 = V_222 ;
if ( F_23 ( V_44 , V_55 ) ) {
V_87 |= ( 1 << ( clock -> V_82 - 1 ) ) << V_895 ;
} else {
if ( clock -> V_82 == 2 )
V_87 |= V_906 ;
else
V_87 |= ( clock -> V_82 - 2 ) << V_895 ;
if ( clock -> V_83 == 4 )
V_87 |= V_907 ;
}
if ( ! F_143 ( V_16 ) && F_23 ( V_44 , V_76 ) )
V_87 |= V_221 ;
if ( F_23 ( V_44 , V_55 ) &&
F_543 ( V_2 ) && V_51 < 2 )
V_87 |= V_904 ;
else
V_87 |= V_905 ;
V_87 |= V_131 ;
V_44 -> V_213 . V_87 = V_87 ;
}
static void F_392 ( struct V_37 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 = V_37 -> V_119 ;
enum V_118 V_121 = V_37 -> V_115 -> V_121 ;
const struct V_533 * V_116 = & V_37 -> V_115 -> V_40 . V_116 ;
T_2 V_908 , V_909 ;
int V_910 = 0 ;
V_908 = V_116 -> V_908 ;
V_909 = V_116 -> V_909 ;
if ( V_116 -> V_355 & V_911 ) {
V_908 -= 1 ;
V_909 -= 1 ;
if ( F_21 ( V_37 , V_66 ) )
V_910 = ( V_116 -> V_912 - 1 ) / 2 ;
else
V_910 = V_116 -> V_760 -
V_116 -> V_912 / 2 ;
if ( V_910 < 0 )
V_910 += V_116 -> V_912 ;
}
if ( F_60 ( V_16 ) -> V_127 > 3 )
F_129 ( F_339 ( V_121 ) , V_910 ) ;
F_129 ( F_327 ( V_121 ) ,
( V_116 -> V_561 - 1 ) |
( ( V_116 -> V_912 - 1 ) << 16 ) ) ;
F_129 ( F_329 ( V_121 ) ,
( V_116 -> V_913 - 1 ) |
( ( V_116 -> V_914 - 1 ) << 16 ) ) ;
F_129 ( F_331 ( V_121 ) ,
( V_116 -> V_760 - 1 ) |
( ( V_116 -> V_915 - 1 ) << 16 ) ) ;
F_129 ( F_333 ( V_121 ) ,
( V_116 -> V_562 - 1 ) |
( ( V_908 - 1 ) << 16 ) ) ;
F_129 ( F_335 ( V_121 ) ,
( V_116 -> V_916 - 1 ) |
( ( V_909 - 1 ) << 16 ) ) ;
F_129 ( F_337 ( V_121 ) ,
( V_116 -> V_917 - 1 ) |
( ( V_116 -> V_918 - 1 ) << 16 ) ) ;
if ( F_235 ( V_16 ) && V_121 == V_604 &&
( V_119 == V_157 || V_119 == V_524 ) )
F_129 ( F_333 ( V_119 ) , F_11 ( F_333 ( V_121 ) ) ) ;
F_129 ( F_286 ( V_119 ) ,
( ( V_37 -> V_115 -> V_381 - 1 ) << 16 ) |
( V_37 -> V_115 -> V_380 - 1 ) ) ;
}
static void F_588 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_118 V_121 = V_212 -> V_121 ;
T_2 V_218 ;
V_218 = F_11 ( F_327 ( V_121 ) ) ;
V_212 -> V_40 . V_116 . V_561 = ( V_218 & 0xffff ) + 1 ;
V_212 -> V_40 . V_116 . V_912 = ( ( V_218 >> 16 ) & 0xffff ) + 1 ;
V_218 = F_11 ( F_329 ( V_121 ) ) ;
V_212 -> V_40 . V_116 . V_913 = ( V_218 & 0xffff ) + 1 ;
V_212 -> V_40 . V_116 . V_914 = ( ( V_218 >> 16 ) & 0xffff ) + 1 ;
V_218 = F_11 ( F_331 ( V_121 ) ) ;
V_212 -> V_40 . V_116 . V_760 = ( V_218 & 0xffff ) + 1 ;
V_212 -> V_40 . V_116 . V_915 = ( ( V_218 >> 16 ) & 0xffff ) + 1 ;
V_218 = F_11 ( F_333 ( V_121 ) ) ;
V_212 -> V_40 . V_116 . V_562 = ( V_218 & 0xffff ) + 1 ;
V_212 -> V_40 . V_116 . V_908 = ( ( V_218 >> 16 ) & 0xffff ) + 1 ;
V_218 = F_11 ( F_335 ( V_121 ) ) ;
V_212 -> V_40 . V_116 . V_916 = ( V_218 & 0xffff ) + 1 ;
V_212 -> V_40 . V_116 . V_909 = ( ( V_218 >> 16 ) & 0xffff ) + 1 ;
V_218 = F_11 ( F_337 ( V_121 ) ) ;
V_212 -> V_40 . V_116 . V_917 = ( V_218 & 0xffff ) + 1 ;
V_212 -> V_40 . V_116 . V_918 = ( ( V_218 >> 16 ) & 0xffff ) + 1 ;
if ( F_11 ( F_61 ( V_121 ) ) & V_250 ) {
V_212 -> V_40 . V_116 . V_355 |= V_911 ;
V_212 -> V_40 . V_116 . V_908 += 1 ;
V_212 -> V_40 . V_116 . V_909 += 1 ;
}
V_218 = F_11 ( F_286 ( V_38 -> V_119 ) ) ;
V_212 -> V_380 = ( V_218 & 0xffff ) + 1 ;
V_212 -> V_381 = ( ( V_218 >> 16 ) & 0xffff ) + 1 ;
V_212 -> V_40 . V_445 . V_919 = V_212 -> V_380 ;
V_212 -> V_40 . V_445 . V_920 = V_212 -> V_381 ;
}
void F_589 ( struct V_533 * V_445 ,
struct V_43 * V_212 )
{
V_445 -> V_920 = V_212 -> V_40 . V_116 . V_561 ;
V_445 -> V_921 = V_212 -> V_40 . V_116 . V_912 ;
V_445 -> V_922 = V_212 -> V_40 . V_116 . V_760 ;
V_445 -> V_923 = V_212 -> V_40 . V_116 . V_915 ;
V_445 -> V_919 = V_212 -> V_40 . V_116 . V_562 ;
V_445 -> V_924 = V_212 -> V_40 . V_116 . V_908 ;
V_445 -> V_925 = V_212 -> V_40 . V_116 . V_917 ;
V_445 -> V_926 = V_212 -> V_40 . V_116 . V_918 ;
V_445 -> V_355 = V_212 -> V_40 . V_116 . V_355 ;
V_445 -> type = V_927 ;
V_445 -> clock = V_212 -> V_40 . V_116 . V_117 ;
V_445 -> V_355 |= V_212 -> V_40 . V_116 . V_355 ;
V_445 -> V_928 = F_590 ( V_445 ) ;
V_445 -> V_929 = F_591 ( V_445 ) ;
F_592 ( V_445 ) ;
}
static void F_477 ( struct V_37 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_930 ;
V_930 = 0 ;
if ( ( V_37 -> V_119 == V_148 && V_2 -> V_167 & V_168 ) ||
( V_37 -> V_119 == V_157 && V_2 -> V_167 & V_169 ) )
V_930 |= F_11 ( F_61 ( V_37 -> V_119 ) ) & V_170 ;
if ( V_37 -> V_115 -> V_262 )
V_930 |= V_263 ;
if ( F_31 ( V_16 ) || F_13 ( V_16 ) || F_14 ( V_16 ) ) {
if ( V_37 -> V_115 -> V_931 && V_37 -> V_115 -> V_754 != 30 )
V_930 |= V_932 |
V_933 ;
switch ( V_37 -> V_115 -> V_754 ) {
case 18 :
V_930 |= V_934 ;
break;
case 24 :
V_930 |= V_248 ;
break;
case 30 :
V_930 |= V_935 ;
break;
default:
F_148 () ;
}
}
if ( F_593 ( V_16 ) ) {
if ( V_37 -> V_836 ) {
F_153 ( L_141 ) ;
V_930 |= V_936 ;
} else {
F_153 ( L_142 ) ;
}
}
if ( V_37 -> V_115 -> V_40 . V_116 . V_355 & V_911 ) {
if ( F_60 ( V_16 ) -> V_127 < 4 ||
F_21 ( V_37 , V_66 ) )
V_930 |= V_937 ;
else
V_930 |= V_938 ;
} else
V_930 |= V_939 ;
if ( ( F_13 ( V_16 ) || F_14 ( V_16 ) ) &&
V_37 -> V_115 -> V_940 )
V_930 |= V_941 ;
F_129 ( F_61 ( V_37 -> V_119 ) , V_930 ) ;
F_130 ( F_61 ( V_37 -> V_119 ) ) ;
}
static int F_594 ( struct V_37 * V_38 ,
struct V_43 * V_44 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_53 , V_51 = 0 ;
T_4 clock ;
bool V_942 ;
const T_3 * V_54 ;
struct V_45 * V_36 = V_44 -> V_40 . V_36 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_50 ;
memset ( & V_44 -> V_213 , 0 ,
sizeof( V_44 -> V_213 ) ) ;
if ( V_44 -> V_260 )
return 0 ;
F_24 (state, connector, connector_state, i) {
if ( V_49 -> V_38 == & V_38 -> V_40 )
V_51 ++ ;
}
if ( ! V_44 -> V_943 ) {
V_53 = F_53 ( V_44 , V_51 ) ;
V_54 = F_29 ( V_44 , V_53 ) ;
V_942 = V_2 -> V_449 . V_944 ( V_54 , V_44 ,
V_44 -> V_866 ,
V_53 , NULL , & clock ) ;
if ( ! V_942 ) {
F_132 ( L_143 ) ;
return - V_307 ;
}
V_44 -> V_87 . V_84 = clock . V_84 ;
V_44 -> V_87 . V_88 = clock . V_88 ;
V_44 -> V_87 . V_80 = clock . V_80 ;
V_44 -> V_87 . V_82 = clock . V_82 ;
V_44 -> V_87 . V_83 = clock . V_83 ;
}
if ( F_33 ( V_16 ) ) {
F_587 ( V_38 , V_44 , NULL ,
V_51 ) ;
} else if ( F_14 ( V_16 ) ) {
F_573 ( V_38 , V_44 ) ;
} else if ( F_13 ( V_16 ) ) {
F_566 ( V_38 , V_44 ) ;
} else {
F_584 ( V_38 , V_44 , NULL ,
V_51 ) ;
}
return 0 ;
}
static void F_595 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_218 ;
if ( F_60 ( V_16 ) -> V_127 <= 3 && ( F_143 ( V_16 ) || ! F_128 ( V_16 ) ) )
return;
V_218 = F_11 ( V_613 ) ;
if ( ! ( V_218 & V_614 ) )
return;
if ( F_60 ( V_16 ) -> V_127 < 4 ) {
if ( V_38 -> V_119 != V_157 )
return;
} else {
if ( ( V_218 & V_945 ) != ( V_38 -> V_119 << V_946 ) )
return;
}
V_212 -> V_611 . V_612 = V_218 ;
V_212 -> V_611 . V_616 = F_11 ( V_615 ) ;
if ( F_60 ( V_16 ) -> V_127 < 5 )
V_212 -> V_611 . V_947 =
F_11 ( V_159 ) & V_948 ;
}
static void F_596 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_212 -> V_121 ;
T_4 clock ;
T_1 V_848 ;
int V_53 = 100000 ;
if ( ! ( V_212 -> V_213 . V_87 & V_131 ) )
return;
F_2 ( & V_2 -> V_5 ) ;
V_848 = F_136 ( V_2 , V_119 , F_568 ( V_119 ) ) ;
F_4 ( & V_2 -> V_5 ) ;
clock . V_88 = ( V_848 >> V_857 ) & 7 ;
clock . V_80 = V_848 & V_858 ;
clock . V_84 = ( V_848 >> V_861 ) & 0xf ;
clock . V_82 = ( V_848 >> V_859 ) & 7 ;
clock . V_83 = ( V_848 >> V_860 ) & 0x1f ;
V_212 -> V_866 = F_37 ( V_53 , & clock ) ;
}
static void
F_597 ( struct V_37 * V_38 ,
struct V_343 * V_344 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 , V_40 , V_320 ;
int V_119 = V_38 -> V_119 , V_171 = V_38 -> V_171 ;
int V_949 , V_265 ;
unsigned int V_950 ;
struct V_276 * V_114 ;
struct V_951 * V_952 ;
V_10 = F_11 ( F_90 ( V_171 ) ) ;
if ( ! ( V_10 & V_172 ) )
return;
V_952 = F_499 ( sizeof( * V_952 ) , V_746 ) ;
if ( ! V_952 ) {
F_153 ( L_144 ) ;
return;
}
V_114 = & V_952 -> V_40 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
if ( V_10 & V_383 ) {
V_344 -> V_351 = V_352 ;
V_114 -> V_292 [ 0 ] = V_270 ;
}
}
V_265 = V_10 & V_953 ;
V_949 = F_201 ( V_265 ) ;
V_114 -> V_265 = V_949 ;
V_114 -> V_391 = F_178 ( V_949 , 0 ) * 8 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
if ( V_344 -> V_351 )
V_320 = F_11 ( F_232 ( V_171 ) ) ;
else
V_320 = F_11 ( F_233 ( V_171 ) ) ;
V_40 = F_11 ( F_223 ( V_171 ) ) & 0xfffff000 ;
} else {
V_40 = F_11 ( F_224 ( V_171 ) ) ;
}
V_344 -> V_40 = V_40 ;
V_10 = F_11 ( F_286 ( V_119 ) ) ;
V_114 -> V_354 = ( ( V_10 >> 16 ) & 0xfff ) + 1 ;
V_114 -> V_273 = ( ( V_10 >> 0 ) & 0xfff ) + 1 ;
V_10 = F_11 ( F_231 ( V_119 ) ) ;
V_114 -> V_288 [ 0 ] = V_10 & 0xffffffc0 ;
V_950 = F_181 ( V_16 , V_114 -> V_273 ,
V_114 -> V_265 ,
V_114 -> V_292 [ 0 ] ) ;
V_344 -> V_296 = V_114 -> V_288 [ 0 ] * V_950 ;
F_153 ( L_145 ,
F_80 ( V_119 ) , V_171 , V_114 -> V_354 , V_114 -> V_273 ,
V_114 -> V_391 , V_40 , V_114 -> V_288 [ 0 ] ,
V_344 -> V_296 ) ;
V_344 -> V_114 = V_952 ;
}
static void F_598 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_212 -> V_121 ;
enum V_216 V_217 = F_135 ( V_119 ) ;
T_4 clock ;
T_1 V_954 , V_955 , V_956 , V_957 , V_958 ;
int V_53 = 100000 ;
F_2 ( & V_2 -> V_5 ) ;
V_954 = F_136 ( V_2 , V_119 , F_574 ( V_217 ) ) ;
V_955 = F_136 ( V_2 , V_119 , F_575 ( V_217 ) ) ;
V_956 = F_136 ( V_2 , V_119 , F_576 ( V_217 ) ) ;
V_957 = F_136 ( V_2 , V_119 , F_577 ( V_217 ) ) ;
V_958 = F_136 ( V_2 , V_119 , F_578 ( V_217 ) ) ;
F_4 ( & V_2 -> V_5 ) ;
clock . V_88 = ( V_956 & 0x7 ) == V_875 ? 2 : 0 ;
clock . V_80 = ( V_955 & 0xff ) << 22 ;
if ( V_958 & V_878 )
clock . V_80 |= V_957 & 0x3fffff ;
clock . V_84 = ( V_956 >> V_876 ) & 0xf ;
clock . V_82 = ( V_954 >> V_872 ) & 0x7 ;
clock . V_83 = ( V_954 >> V_873 ) & 0x1f ;
V_212 -> V_866 = F_38 ( V_53 , & clock ) ;
}
static bool F_599 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_165 V_166 ;
T_2 V_218 ;
bool V_305 ;
V_166 = F_422 ( V_38 -> V_119 ) ;
if ( ! F_87 ( V_2 , V_166 ) )
return false ;
V_212 -> V_121 = (enum V_118 ) V_38 -> V_119 ;
V_212 -> V_135 = V_959 ;
V_305 = false ;
V_218 = F_11 ( F_61 ( V_38 -> V_119 ) ) ;
if ( ! ( V_218 & V_170 ) )
goto V_960;
if ( F_31 ( V_16 ) || F_13 ( V_16 ) || F_14 ( V_16 ) ) {
switch ( V_218 & V_247 ) {
case V_934 :
V_212 -> V_754 = 18 ;
break;
case V_248 :
V_212 -> V_754 = 24 ;
break;
case V_935 :
V_212 -> V_754 = 30 ;
break;
default:
break;
}
}
if ( ( F_13 ( V_16 ) || F_14 ( V_16 ) ) &&
( V_218 & V_941 ) )
V_212 -> V_940 = true ;
if ( F_60 ( V_16 ) -> V_127 < 4 )
V_212 -> V_262 = V_218 & V_263 ;
F_588 ( V_38 , V_212 ) ;
F_595 ( V_38 , V_212 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
V_218 = F_11 ( F_133 ( V_38 -> V_119 ) ) ;
V_212 -> V_605 =
( ( V_218 & V_961 )
>> V_847 ) + 1 ;
V_212 -> V_213 . V_215 = V_218 ;
} else if ( F_585 ( V_16 ) || F_586 ( V_16 ) || F_536 ( V_16 ) ) {
V_218 = F_11 ( F_65 ( V_38 -> V_119 ) ) ;
V_212 -> V_605 =
( ( V_218 & V_962 )
>> V_892 ) + 1 ;
} else {
V_212 -> V_605 = 1 ;
}
V_212 -> V_213 . V_87 = F_11 ( F_65 ( V_38 -> V_119 ) ) ;
if ( ! F_13 ( V_16 ) && ! F_14 ( V_16 ) ) {
if ( F_143 ( V_16 ) )
V_212 -> V_213 . V_87 &= ~ V_221 ;
V_212 -> V_213 . V_732 = F_11 ( F_481 ( V_38 -> V_119 ) ) ;
V_212 -> V_213 . V_733 = F_11 ( F_482 ( V_38 -> V_119 ) ) ;
} else {
V_212 -> V_213 . V_87 &= ~ ( V_214 |
V_234 |
V_232 ) ;
}
if ( F_14 ( V_16 ) )
F_598 ( V_38 , V_212 ) ;
else if ( F_13 ( V_16 ) )
F_596 ( V_38 , V_212 ) ;
else
F_600 ( V_38 , V_212 ) ;
V_212 -> V_40 . V_116 . V_117 =
V_212 -> V_866 / V_212 -> V_605 ;
V_305 = true ;
V_960:
F_88 ( V_2 , V_166 ) ;
return V_305 ;
}
static void F_601 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_41 * V_42 ;
T_1 V_10 , V_963 ;
bool V_964 = false ;
bool V_965 = false ;
bool V_966 = false ;
bool V_967 = false ;
bool V_968 = false ;
F_602 (dev, encoder) {
switch ( V_42 -> type ) {
case V_55 :
V_966 = true ;
V_964 = true ;
break;
case V_526 :
V_966 = true ;
if ( F_343 ( & V_42 -> V_40 ) -> V_217 == V_617 )
V_965 = true ;
break;
default:
break;
}
}
if ( F_106 ( V_16 ) ) {
V_967 = V_2 -> V_829 . V_969 ;
V_968 = V_967 ;
} else {
V_967 = false ;
V_968 = true ;
}
F_153 ( L_146 ,
V_966 , V_964 , V_967 ) ;
V_10 = F_11 ( V_181 ) ;
V_963 = V_10 ;
V_963 &= ~ V_183 ;
if ( V_967 )
V_963 |= V_970 ;
else
V_963 |= V_971 ;
V_963 &= ~ V_182 ;
V_963 &= ~ V_972 ;
V_963 &= ~ V_973 ;
if ( V_966 ) {
V_963 |= V_974 ;
if ( F_543 ( V_2 ) && V_968 )
V_963 |= V_973 ;
if ( V_965 ) {
if ( F_543 ( V_2 ) && V_968 )
V_963 |= V_975 ;
else
V_963 |= V_976 ;
} else
V_963 |= V_977 ;
} else {
V_963 |= V_978 ;
V_963 |= V_977 ;
}
if ( V_963 == V_10 )
return;
V_10 &= ~ V_183 ;
if ( V_967 )
V_10 |= V_970 ;
else
V_10 |= V_971 ;
if ( V_966 ) {
V_10 &= ~ V_182 ;
V_10 |= V_974 ;
if ( F_543 ( V_2 ) && V_968 ) {
F_153 ( L_147 ) ;
V_10 |= V_973 ;
} else
V_10 &= ~ V_973 ;
F_129 ( V_181 , V_10 ) ;
F_130 ( V_181 ) ;
F_131 ( 200 ) ;
V_10 &= ~ V_972 ;
if ( V_965 ) {
if ( F_543 ( V_2 ) && V_968 ) {
F_153 ( L_148 ) ;
V_10 |= V_975 ;
} else
V_10 |= V_976 ;
} else
V_10 |= V_977 ;
F_129 ( V_181 , V_10 ) ;
F_130 ( V_181 ) ;
F_131 ( 200 ) ;
} else {
F_153 ( L_149 ) ;
V_10 &= ~ V_972 ;
V_10 |= V_977 ;
F_129 ( V_181 , V_10 ) ;
F_130 ( V_181 ) ;
F_131 ( 200 ) ;
V_10 &= ~ V_182 ;
V_10 |= V_978 ;
V_10 &= ~ V_973 ;
F_129 ( V_181 , V_10 ) ;
F_130 ( V_181 ) ;
F_131 ( 200 ) ;
}
F_142 ( V_10 != V_963 ) ;
}
static void F_603 ( struct V_1 * V_2 )
{
T_2 V_218 ;
V_218 = F_11 ( V_979 ) ;
V_218 |= V_980 ;
F_129 ( V_979 , V_218 ) ;
if ( F_604 ( F_11 ( V_979 ) &
V_981 , 100 ) )
F_132 ( L_150 ) ;
V_218 = F_11 ( V_979 ) ;
V_218 &= ~ V_980 ;
F_129 ( V_979 , V_218 ) ;
if ( F_604 ( ( F_11 ( V_979 ) &
V_981 ) == 0 , 100 ) )
F_132 ( L_151 ) ;
}
static void F_605 ( struct V_1 * V_2 )
{
T_2 V_218 ;
V_218 = F_318 ( V_2 , 0x8008 , V_982 ) ;
V_218 &= ~ ( 0xFF << 24 ) ;
V_218 |= ( 0x12 << 24 ) ;
F_319 ( V_2 , 0x8008 , V_218 , V_982 ) ;
V_218 = F_318 ( V_2 , 0x2008 , V_982 ) ;
V_218 |= ( 1 << 11 ) ;
F_319 ( V_2 , 0x2008 , V_218 , V_982 ) ;
V_218 = F_318 ( V_2 , 0x2108 , V_982 ) ;
V_218 |= ( 1 << 11 ) ;
F_319 ( V_2 , 0x2108 , V_218 , V_982 ) ;
V_218 = F_318 ( V_2 , 0x206C , V_982 ) ;
V_218 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_319 ( V_2 , 0x206C , V_218 , V_982 ) ;
V_218 = F_318 ( V_2 , 0x216C , V_982 ) ;
V_218 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_319 ( V_2 , 0x216C , V_218 , V_982 ) ;
V_218 = F_318 ( V_2 , 0x2080 , V_982 ) ;
V_218 &= ~ ( 7 << 13 ) ;
V_218 |= ( 5 << 13 ) ;
F_319 ( V_2 , 0x2080 , V_218 , V_982 ) ;
V_218 = F_318 ( V_2 , 0x2180 , V_982 ) ;
V_218 &= ~ ( 7 << 13 ) ;
V_218 |= ( 5 << 13 ) ;
F_319 ( V_2 , 0x2180 , V_218 , V_982 ) ;
V_218 = F_318 ( V_2 , 0x208C , V_982 ) ;
V_218 &= ~ 0xFF ;
V_218 |= 0x1C ;
F_319 ( V_2 , 0x208C , V_218 , V_982 ) ;
V_218 = F_318 ( V_2 , 0x218C , V_982 ) ;
V_218 &= ~ 0xFF ;
V_218 |= 0x1C ;
F_319 ( V_2 , 0x218C , V_218 , V_982 ) ;
V_218 = F_318 ( V_2 , 0x2098 , V_982 ) ;
V_218 &= ~ ( 0xFF << 16 ) ;
V_218 |= ( 0x1C << 16 ) ;
F_319 ( V_2 , 0x2098 , V_218 , V_982 ) ;
V_218 = F_318 ( V_2 , 0x2198 , V_982 ) ;
V_218 &= ~ ( 0xFF << 16 ) ;
V_218 |= ( 0x1C << 16 ) ;
F_319 ( V_2 , 0x2198 , V_218 , V_982 ) ;
V_218 = F_318 ( V_2 , 0x20C4 , V_982 ) ;
V_218 |= ( 1 << 27 ) ;
F_319 ( V_2 , 0x20C4 , V_218 , V_982 ) ;
V_218 = F_318 ( V_2 , 0x21C4 , V_982 ) ;
V_218 |= ( 1 << 27 ) ;
F_319 ( V_2 , 0x21C4 , V_218 , V_982 ) ;
V_218 = F_318 ( V_2 , 0x20EC , V_982 ) ;
V_218 &= ~ ( 0xF << 28 ) ;
V_218 |= ( 4 << 28 ) ;
F_319 ( V_2 , 0x20EC , V_218 , V_982 ) ;
V_218 = F_318 ( V_2 , 0x21EC , V_982 ) ;
V_218 &= ~ ( 0xF << 28 ) ;
V_218 |= ( 4 << 28 ) ;
F_319 ( V_2 , 0x21EC , V_218 , V_982 ) ;
}
static void F_606 ( struct V_15 * V_16 , bool V_983 ,
bool V_984 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_9 , V_218 ;
if ( F_6 ( V_984 && ! V_983 , L_152 ) )
V_983 = true ;
if ( F_6 ( F_607 ( V_16 ) && V_984 , L_153 ) )
V_984 = false ;
F_2 ( & V_2 -> V_5 ) ;
V_218 = F_318 ( V_2 , V_985 , V_505 ) ;
V_218 &= ~ V_506 ;
V_218 |= V_986 ;
F_319 ( V_2 , V_985 , V_218 , V_505 ) ;
F_131 ( 24 ) ;
if ( V_983 ) {
V_218 = F_318 ( V_2 , V_985 , V_505 ) ;
V_218 &= ~ V_986 ;
F_319 ( V_2 , V_985 , V_218 , V_505 ) ;
if ( V_984 ) {
F_603 ( V_2 ) ;
F_605 ( V_2 ) ;
}
}
V_9 = F_607 ( V_16 ) ? V_987 : V_988 ;
V_218 = F_318 ( V_2 , V_9 , V_505 ) ;
V_218 |= V_989 ;
F_319 ( V_2 , V_9 , V_218 , V_505 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_608 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_9 , V_218 ;
F_2 ( & V_2 -> V_5 ) ;
V_9 = F_607 ( V_16 ) ? V_987 : V_988 ;
V_218 = F_318 ( V_2 , V_9 , V_505 ) ;
V_218 &= ~ V_989 ;
F_319 ( V_2 , V_9 , V_218 , V_505 ) ;
V_218 = F_318 ( V_2 , V_985 , V_505 ) ;
if ( ! ( V_218 & V_506 ) ) {
if ( ! ( V_218 & V_986 ) ) {
V_218 |= V_986 ;
F_319 ( V_2 , V_985 , V_218 , V_505 ) ;
F_131 ( 32 ) ;
}
V_218 |= V_506 ;
F_319 ( V_2 , V_985 , V_218 , V_505 ) ;
}
F_4 ( & V_2 -> V_5 ) ;
}
static void F_609 ( struct V_1 * V_2 , int V_990 )
{
T_2 V_218 ;
int V_991 = F_610 ( V_990 ) ;
if ( F_9 ( V_990 % 5 != 0 ) )
return;
if ( F_9 ( V_991 >= F_302 ( V_992 ) ) )
return;
F_2 ( & V_2 -> V_5 ) ;
if ( V_990 % 10 != 0 )
V_218 = 0xAAAAAAAB ;
else
V_218 = 0x00000000 ;
F_319 ( V_2 , V_993 , V_218 , V_505 ) ;
V_218 = F_318 ( V_2 , V_994 , V_505 ) ;
V_218 &= 0xffff0000 ;
V_218 |= V_992 [ V_991 ] ;
F_319 ( V_2 , V_994 , V_218 , V_505 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_611 ( struct V_15 * V_16 )
{
struct V_41 * V_42 ;
bool V_995 = false ;
F_602 (dev, encoder) {
switch ( V_42 -> type ) {
case V_64 :
V_995 = true ;
break;
default:
break;
}
}
if ( V_995 ) {
F_609 ( F_204 ( V_16 ) , 0 ) ;
F_606 ( V_16 , true , true ) ;
} else {
F_608 ( V_16 ) ;
}
}
void F_612 ( struct V_15 * V_16 )
{
if ( F_106 ( V_16 ) || F_107 ( V_16 ) )
F_601 ( V_16 ) ;
else if ( F_169 ( V_16 ) )
F_611 ( V_16 ) ;
}
static int F_613 ( struct V_43 * V_44 )
{
struct V_15 * V_16 = V_44 -> V_40 . V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_45 * V_36 = V_44 -> V_40 . V_36 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_41 * V_42 ;
int V_51 = 0 , V_50 ;
bool V_996 = false ;
F_24 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != V_44 -> V_40 . V_38 )
continue;
V_42 = F_25 ( V_49 -> V_52 ) ;
switch ( V_42 -> type ) {
case V_55 :
V_996 = true ;
break;
default:
break;
}
V_51 ++ ;
}
if ( V_996 && F_543 ( V_2 ) && V_51 < 2 ) {
F_153 ( L_139 ,
V_2 -> V_829 . V_832 ) ;
return V_2 -> V_829 . V_832 ;
}
return 120000 ;
}
static void F_394 ( struct V_111 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_2 V_10 ;
V_10 = 0 ;
switch ( V_37 -> V_115 -> V_754 ) {
case 18 :
V_10 |= V_934 ;
break;
case 24 :
V_10 |= V_248 ;
break;
case 30 :
V_10 |= V_935 ;
break;
case 36 :
V_10 |= V_997 ;
break;
default:
F_148 () ;
}
if ( V_37 -> V_115 -> V_931 )
V_10 |= ( V_932 | V_933 ) ;
if ( V_37 -> V_115 -> V_40 . V_116 . V_355 & V_911 )
V_10 |= V_251 ;
else
V_10 |= V_939 ;
if ( V_37 -> V_115 -> V_940 )
V_10 |= V_941 ;
F_129 ( F_61 ( V_119 ) , V_10 ) ;
F_130 ( F_61 ( V_119 ) ) ;
}
static void F_285 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_9 V_998 = 0x7800 ;
if ( V_37 -> V_115 -> V_940 )
V_998 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_129 ( F_614 ( V_119 ) , V_998 << 16 ) ;
F_129 ( F_615 ( V_119 ) , 0 ) ;
F_129 ( F_616 ( V_119 ) , V_998 ) ;
F_129 ( F_617 ( V_119 ) , 0 ) ;
F_129 ( F_618 ( V_119 ) , 0 ) ;
F_129 ( F_619 ( V_119 ) , V_998 << 16 ) ;
F_129 ( F_620 ( V_119 ) , 0 ) ;
F_129 ( F_621 ( V_119 ) , 0 ) ;
F_129 ( F_622 ( V_119 ) , 0 ) ;
if ( F_60 ( V_16 ) -> V_127 > 6 ) {
T_9 V_999 = 0 ;
if ( V_37 -> V_115 -> V_940 )
V_999 = ( 16 * ( 1 << 12 ) / 255 ) & 0x1fff ;
F_129 ( F_623 ( V_119 ) , V_999 ) ;
F_129 ( F_624 ( V_119 ) , V_999 ) ;
F_129 ( F_625 ( V_119 ) , V_999 ) ;
F_129 ( F_626 ( V_119 ) , 0 ) ;
} else {
T_2 V_445 = V_1000 ;
if ( V_37 -> V_115 -> V_940 )
V_445 |= V_1001 ;
F_129 ( F_626 ( V_119 ) , V_445 ) ;
}
}
static void F_401 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_119 V_119 = V_37 -> V_119 ;
enum V_118 V_121 = V_37 -> V_115 -> V_121 ;
T_2 V_10 ;
V_10 = 0 ;
if ( F_235 ( V_16 ) && V_37 -> V_115 -> V_931 )
V_10 |= ( V_932 | V_933 ) ;
if ( V_37 -> V_115 -> V_40 . V_116 . V_355 & V_911 )
V_10 |= V_251 ;
else
V_10 |= V_939 ;
F_129 ( F_61 ( V_121 ) , V_10 ) ;
F_130 ( F_61 ( V_121 ) ) ;
F_129 ( F_371 ( V_37 -> V_119 ) , V_1002 ) ;
F_130 ( F_371 ( V_37 -> V_119 ) ) ;
if ( F_236 ( V_16 ) || F_60 ( V_16 ) -> V_127 >= 9 ) {
V_10 = 0 ;
switch ( V_37 -> V_115 -> V_754 ) {
case 18 :
V_10 |= V_1003 ;
break;
case 24 :
V_10 |= V_1004 ;
break;
case 30 :
V_10 |= V_1005 ;
break;
case 36 :
V_10 |= V_1006 ;
break;
default:
F_148 () ;
}
if ( V_37 -> V_115 -> V_931 )
V_10 |= V_1007 | V_1008 ;
F_129 ( F_627 ( V_119 ) , V_10 ) ;
}
}
static bool F_628 ( struct V_111 * V_38 ,
struct V_43 * V_44 ,
T_4 * clock ,
bool * V_1009 ,
T_4 * V_833 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_53 ;
const T_3 * V_54 ;
bool V_305 ;
V_53 = F_613 ( V_44 ) ;
V_54 = F_29 ( V_44 , V_53 ) ;
V_305 = V_2 -> V_449 . V_944 ( V_54 , V_44 ,
V_44 -> V_866 ,
V_53 , NULL , clock ) ;
if ( ! V_305 )
return false ;
return true ;
}
int F_507 ( int V_110 , int V_751 , int V_1010 )
{
T_1 V_1011 = V_110 * V_1010 * 21 / 20 ;
return F_185 ( V_1011 , V_751 * 8 ) ;
}
static bool F_629 ( struct V_87 * V_87 , int V_1012 )
{
return F_35 ( V_87 ) < V_1012 * V_87 -> V_84 ;
}
static T_2 F_630 ( struct V_37 * V_37 ,
struct V_43 * V_44 ,
T_1 * V_834 ,
T_4 * V_833 , T_1 * V_835 )
{
struct V_111 * V_38 = & V_37 -> V_40 ;
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_45 * V_36 = V_44 -> V_40 . V_36 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_41 * V_42 ;
T_2 V_87 ;
int V_1012 , V_51 = 0 , V_50 ;
bool V_996 = false , V_889 = false ;
F_24 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != V_44 -> V_40 . V_38 )
continue;
V_42 = F_25 ( V_49 -> V_52 ) ;
switch ( V_42 -> type ) {
case V_55 :
V_996 = true ;
break;
case V_66 :
case V_63 :
V_889 = true ;
break;
default:
break;
}
V_51 ++ ;
}
V_1012 = 21 ;
if ( V_996 ) {
if ( ( F_543 ( V_2 ) &&
V_2 -> V_829 . V_832 == 100000 ) ||
( F_106 ( V_16 ) && F_27 ( V_16 ) ) )
V_1012 = 25 ;
} else if ( V_44 -> V_902 )
V_1012 = 20 ;
if ( F_629 ( & V_44 -> V_87 , V_1012 ) )
* V_834 |= V_1013 ;
if ( V_835 && ( V_833 -> V_79 < V_1012 * V_833 -> V_84 ) )
* V_835 |= V_1013 ;
V_87 = 0 ;
if ( V_996 )
V_87 |= V_890 ;
else
V_87 |= V_891 ;
V_87 |= ( V_44 -> V_605 - 1 )
<< V_1014 ;
if ( V_889 )
V_87 |= V_893 ;
if ( V_44 -> V_532 )
V_87 |= V_893 ;
V_87 |= ( 1 << ( V_44 -> V_87 . V_82 - 1 ) ) << V_895 ;
V_87 |= ( 1 << ( V_44 -> V_87 . V_82 - 1 ) ) << V_896 ;
switch ( V_44 -> V_87 . V_83 ) {
case 5 :
V_87 |= V_897 ;
break;
case 7 :
V_87 |= V_898 ;
break;
case 10 :
V_87 |= V_899 ;
break;
case 14 :
V_87 |= V_900 ;
break;
}
if ( V_996 && F_543 ( V_2 ) && V_51 < 2 )
V_87 |= V_904 ;
else
V_87 |= V_905 ;
return V_87 | V_131 ;
}
static int F_631 ( struct V_37 * V_38 ,
struct V_43 * V_44 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
T_4 clock , V_833 ;
T_1 V_87 = 0 , V_834 = 0 , V_835 = 0 ;
bool V_942 , V_1009 = false ;
bool V_996 = false ;
struct V_134 * V_137 ;
memset ( & V_44 -> V_213 , 0 ,
sizeof( V_44 -> V_213 ) ) ;
V_996 = F_23 ( V_44 , V_55 ) ;
F_6 ( ! ( F_106 ( V_16 ) || F_107 ( V_16 ) ) ,
L_154 , F_632 ( V_16 ) ) ;
V_942 = F_628 ( & V_38 -> V_40 , V_44 , & clock ,
& V_1009 , & V_833 ) ;
if ( ! V_942 && ! V_44 -> V_943 ) {
F_132 ( L_143 ) ;
return - V_307 ;
}
if ( ! V_44 -> V_943 ) {
V_44 -> V_87 . V_84 = clock . V_84 ;
V_44 -> V_87 . V_88 = clock . V_88 ;
V_44 -> V_87 . V_80 = clock . V_80 ;
V_44 -> V_87 . V_82 = clock . V_82 ;
V_44 -> V_87 . V_83 = clock . V_83 ;
}
if ( V_44 -> V_261 ) {
V_834 = F_545 ( & V_44 -> V_87 ) ;
if ( V_1009 )
V_835 = F_545 ( & V_833 ) ;
V_87 = F_630 ( V_38 , V_44 ,
& V_834 , & V_833 ,
V_1009 ? & V_835 : NULL ) ;
V_44 -> V_213 . V_87 = V_87 ;
V_44 -> V_213 . V_732 = V_834 ;
if ( V_1009 )
V_44 -> V_213 . V_733 = V_835 ;
else
V_44 -> V_213 . V_733 = V_834 ;
V_137 = F_351 ( V_38 , V_44 ) ;
if ( V_137 == NULL ) {
F_16 ( L_155 ,
F_80 ( V_38 -> V_119 ) ) ;
return - V_307 ;
}
}
if ( V_996 && V_1009 )
V_38 -> V_836 = true ;
else
V_38 -> V_836 = false ;
return 0 ;
}
static void F_633 ( struct V_37 * V_38 ,
struct V_821 * V_822 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 = V_38 -> V_119 ;
V_822 -> V_826 = F_11 ( F_553 ( V_119 ) ) ;
V_822 -> V_827 = F_11 ( F_554 ( V_119 ) ) ;
V_822 -> V_824 = F_11 ( F_550 ( V_119 ) )
& ~ V_527 ;
V_822 -> V_825 = F_11 ( F_552 ( V_119 ) ) ;
V_822 -> V_823 = ( ( F_11 ( F_550 ( V_119 ) )
& V_527 ) >> V_1015 ) + 1 ;
}
static void F_634 ( struct V_37 * V_38 ,
enum V_118 V_118 ,
struct V_821 * V_822 ,
struct V_821 * V_839 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 = V_38 -> V_119 ;
if ( F_60 ( V_16 ) -> V_127 >= 5 ) {
V_822 -> V_826 = F_11 ( F_556 ( V_118 ) ) ;
V_822 -> V_827 = F_11 ( F_557 ( V_118 ) ) ;
V_822 -> V_824 = F_11 ( F_346 ( V_118 ) )
& ~ V_527 ;
V_822 -> V_825 = F_11 ( F_555 ( V_118 ) ) ;
V_822 -> V_823 = ( ( F_11 ( F_346 ( V_118 ) )
& V_527 ) >> V_1015 ) + 1 ;
if ( V_839 && F_60 ( V_16 ) -> V_127 < 8 &&
V_38 -> V_115 -> V_840 ) {
V_839 -> V_826 = F_11 ( F_560 ( V_118 ) ) ;
V_839 -> V_827 = F_11 ( F_561 ( V_118 ) ) ;
V_839 -> V_824 = F_11 ( F_558 ( V_118 ) )
& ~ V_527 ;
V_839 -> V_825 = F_11 ( F_559 ( V_118 ) ) ;
V_839 -> V_823 = ( ( F_11 ( F_558 ( V_118 ) )
& V_527 ) >> V_1015 ) + 1 ;
}
} else {
V_822 -> V_826 = F_11 ( F_564 ( V_119 ) ) ;
V_822 -> V_827 = F_11 ( F_565 ( V_119 ) ) ;
V_822 -> V_824 = F_11 ( F_562 ( V_119 ) )
& ~ V_527 ;
V_822 -> V_825 = F_11 ( F_563 ( V_119 ) ) ;
V_822 -> V_823 = ( ( F_11 ( F_562 ( V_119 ) )
& V_527 ) >> V_1015 ) + 1 ;
}
}
void F_635 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
if ( V_212 -> V_261 )
F_633 ( V_38 , & V_212 -> V_842 ) ;
else
F_634 ( V_38 , V_212 -> V_121 ,
& V_212 -> V_842 ,
& V_212 -> V_843 ) ;
}
static void F_636 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
F_634 ( V_38 , V_212 -> V_121 ,
& V_212 -> V_601 , NULL ) ;
}
static void F_637 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_398 * V_399 = & V_212 -> V_399 ;
T_2 V_443 = 0 ;
int V_241 = - 1 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_38 -> V_400 ; V_50 ++ ) {
V_443 = F_11 ( F_244 ( V_38 -> V_119 , V_50 ) ) ;
if ( V_443 & V_444 && ! ( V_443 & V_1016 ) ) {
V_241 = V_50 ;
V_212 -> V_460 . V_129 = true ;
V_212 -> V_460 . V_566 = F_11 ( F_245 ( V_38 -> V_119 , V_50 ) ) ;
V_212 -> V_460 . V_296 = F_11 ( F_246 ( V_38 -> V_119 , V_50 ) ) ;
break;
}
}
V_399 -> V_436 = V_241 ;
if ( V_241 >= 0 ) {
V_399 -> V_551 |= ( 1 << V_560 ) ;
} else {
V_399 -> V_551 &= ~ ( 1 << V_560 ) ;
}
}
static void
F_638 ( struct V_37 * V_38 ,
struct V_343 * V_344 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 , V_40 , V_320 , V_1017 , V_351 ;
int V_119 = V_38 -> V_119 ;
int V_949 , V_265 ;
unsigned int V_950 ;
struct V_276 * V_114 ;
struct V_951 * V_952 ;
V_952 = F_499 ( sizeof( * V_952 ) , V_746 ) ;
if ( ! V_952 ) {
F_153 ( L_144 ) ;
return;
}
V_114 = & V_952 -> V_40 ;
V_10 = F_11 ( F_96 ( V_119 , 0 ) ) ;
if ( ! ( V_10 & V_177 ) )
goto error;
V_265 = V_10 & V_1018 ;
V_949 = F_202 ( V_265 ,
V_10 & V_404 ,
V_10 & V_1019 ) ;
V_114 -> V_265 = V_949 ;
V_114 -> V_391 = F_178 ( V_949 , 0 ) * 8 ;
V_351 = V_10 & V_1020 ;
switch ( V_351 ) {
case V_1021 :
V_114 -> V_292 [ 0 ] = V_269 ;
break;
case V_415 :
V_344 -> V_351 = V_352 ;
V_114 -> V_292 [ 0 ] = V_270 ;
break;
case V_416 :
V_114 -> V_292 [ 0 ] = V_271 ;
break;
case V_417 :
V_114 -> V_292 [ 0 ] = V_272 ;
break;
default:
F_180 ( V_351 ) ;
goto error;
}
V_40 = F_11 ( F_252 ( V_119 , 0 ) ) & 0xfffff000 ;
V_344 -> V_40 = V_40 ;
V_320 = F_11 ( F_255 ( V_119 , 0 ) ) ;
V_10 = F_11 ( F_256 ( V_119 , 0 ) ) ;
V_114 -> V_273 = ( ( V_10 >> 16 ) & 0xfff ) + 1 ;
V_114 -> V_354 = ( ( V_10 >> 0 ) & 0x1fff ) + 1 ;
V_10 = F_11 ( F_257 ( V_119 , 0 ) ) ;
V_1017 = F_238 ( V_16 , V_114 -> V_292 [ 0 ] ,
V_114 -> V_265 ) ;
V_114 -> V_288 [ 0 ] = ( V_10 & 0x3ff ) * V_1017 ;
V_950 = F_181 ( V_16 , V_114 -> V_273 ,
V_114 -> V_265 ,
V_114 -> V_292 [ 0 ] ) ;
V_344 -> V_296 = V_114 -> V_288 [ 0 ] * V_950 ;
F_153 ( L_156 ,
F_80 ( V_119 ) , V_114 -> V_354 , V_114 -> V_273 ,
V_114 -> V_391 , V_40 , V_114 -> V_288 [ 0 ] ,
V_344 -> V_296 ) ;
V_344 -> V_114 = V_952 ;
return;
error:
F_216 ( V_114 ) ;
}
static void F_639 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_218 ;
V_218 = F_11 ( F_361 ( V_38 -> V_119 ) ) ;
if ( V_218 & V_567 ) {
V_212 -> V_460 . V_129 = true ;
V_212 -> V_460 . V_566 = F_11 ( F_363 ( V_38 -> V_119 ) ) ;
V_212 -> V_460 . V_296 = F_11 ( F_364 ( V_38 -> V_119 ) ) ;
if ( F_640 ( V_16 ) ) {
F_9 ( ( V_218 & V_1022 ) !=
F_362 ( V_38 -> V_119 ) ) ;
}
}
}
static void
F_641 ( struct V_37 * V_38 ,
struct V_343 * V_344 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 , V_40 , V_320 ;
int V_119 = V_38 -> V_119 ;
int V_949 , V_265 ;
unsigned int V_950 ;
struct V_276 * V_114 ;
struct V_951 * V_952 ;
V_10 = F_11 ( F_90 ( V_119 ) ) ;
if ( ! ( V_10 & V_172 ) )
return;
V_952 = F_499 ( sizeof( * V_952 ) , V_746 ) ;
if ( ! V_952 ) {
F_153 ( L_144 ) ;
return;
}
V_114 = & V_952 -> V_40 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
if ( V_10 & V_383 ) {
V_344 -> V_351 = V_352 ;
V_114 -> V_292 [ 0 ] = V_270 ;
}
}
V_265 = V_10 & V_953 ;
V_949 = F_201 ( V_265 ) ;
V_114 -> V_265 = V_949 ;
V_114 -> V_391 = F_178 ( V_949 , 0 ) * 8 ;
V_40 = F_11 ( F_223 ( V_119 ) ) & 0xfffff000 ;
if ( F_235 ( V_16 ) || F_236 ( V_16 ) ) {
V_320 = F_11 ( F_237 ( V_119 ) ) ;
} else {
if ( V_344 -> V_351 )
V_320 = F_11 ( F_232 ( V_119 ) ) ;
else
V_320 = F_11 ( F_233 ( V_119 ) ) ;
}
V_344 -> V_40 = V_40 ;
V_10 = F_11 ( F_286 ( V_119 ) ) ;
V_114 -> V_354 = ( ( V_10 >> 16 ) & 0xfff ) + 1 ;
V_114 -> V_273 = ( ( V_10 >> 0 ) & 0xfff ) + 1 ;
V_10 = F_11 ( F_231 ( V_119 ) ) ;
V_114 -> V_288 [ 0 ] = V_10 & 0xffffffc0 ;
V_950 = F_181 ( V_16 , V_114 -> V_273 ,
V_114 -> V_265 ,
V_114 -> V_292 [ 0 ] ) ;
V_344 -> V_296 = V_114 -> V_288 [ 0 ] * V_950 ;
F_153 ( L_156 ,
F_80 ( V_119 ) , V_114 -> V_354 , V_114 -> V_273 ,
V_114 -> V_391 , V_40 , V_114 -> V_288 [ 0 ] ,
V_344 -> V_296 ) ;
V_344 -> V_114 = V_952 ;
}
static bool F_642 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_165 V_166 ;
T_2 V_218 ;
bool V_305 ;
V_166 = F_422 ( V_38 -> V_119 ) ;
if ( ! F_87 ( V_2 , V_166 ) )
return false ;
V_212 -> V_121 = (enum V_118 ) V_38 -> V_119 ;
V_212 -> V_135 = V_959 ;
V_305 = false ;
V_218 = F_11 ( F_61 ( V_38 -> V_119 ) ) ;
if ( ! ( V_218 & V_170 ) )
goto V_960;
switch ( V_218 & V_247 ) {
case V_934 :
V_212 -> V_754 = 18 ;
break;
case V_248 :
V_212 -> V_754 = 24 ;
break;
case V_935 :
V_212 -> V_754 = 30 ;
break;
case V_997 :
V_212 -> V_754 = 36 ;
break;
default:
break;
}
if ( V_218 & V_941 )
V_212 -> V_940 = true ;
if ( F_11 ( F_109 ( V_38 -> V_119 ) ) & V_185 ) {
struct V_134 * V_137 ;
V_212 -> V_261 = true ;
V_218 = F_11 ( F_75 ( V_38 -> V_119 ) ) ;
V_212 -> V_474 = ( ( V_473 & V_218 ) >>
V_1023 ) + 1 ;
F_636 ( V_38 , V_212 ) ;
if ( F_106 ( V_2 -> V_16 ) ) {
V_212 -> V_135 =
(enum V_543 ) V_38 -> V_119 ;
} else {
V_218 = F_11 ( V_530 ) ;
if ( V_218 & F_349 ( V_38 -> V_119 ) )
V_212 -> V_135 = V_531 ;
else
V_212 -> V_135 = V_1024 ;
}
V_137 = & V_2 -> V_136 [ V_212 -> V_135 ] ;
F_9 ( ! V_137 -> V_140 ( V_2 , V_137 ,
& V_212 -> V_213 ) ) ;
V_218 = V_212 -> V_213 . V_87 ;
V_212 -> V_605 =
( ( V_218 & V_1025 )
>> V_1014 ) + 1 ;
F_643 ( V_38 , V_212 ) ;
} else {
V_212 -> V_605 = 1 ;
}
F_588 ( V_38 , V_212 ) ;
F_639 ( V_38 , V_212 ) ;
V_305 = true ;
V_960:
F_88 ( V_2 , V_166 ) ;
return V_305 ;
}
static void F_644 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_37 * V_38 ;
F_140 (dev, crtc)
F_66 ( V_38 -> V_112 , L_157 ,
F_80 ( V_38 -> V_119 ) ) ;
F_66 ( F_11 ( V_1026 ) , L_158 ) ;
F_66 ( F_11 ( V_1027 ) & V_1028 , L_159 ) ;
F_66 ( F_11 ( F_645 ( 0 ) ) & V_1029 , L_160 ) ;
F_66 ( F_11 ( F_645 ( 1 ) ) & V_1029 , L_161 ) ;
F_66 ( F_11 ( V_1030 ) & V_1031 , L_162 ) ;
F_66 ( F_11 ( V_1032 ) & V_1033 ,
L_163 ) ;
if ( F_235 ( V_16 ) )
F_66 ( F_11 ( V_1034 ) & V_1033 ,
L_164 ) ;
F_66 ( F_11 ( V_1035 ) & V_1036 ,
L_165 ) ;
F_66 ( F_11 ( V_1037 ) & V_1038 ,
L_166 ) ;
F_66 ( F_11 ( V_1039 ) & V_1040 , L_167 ) ;
F_66 ( F_646 ( V_2 ) , L_168 ) ;
}
static T_2 F_647 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_235 ( V_16 ) )
return F_11 ( V_1041 ) ;
else
return F_11 ( V_1042 ) ;
}
static void F_648 ( struct V_1 * V_2 , T_2 V_10 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_235 ( V_16 ) ) {
F_2 ( & V_2 -> V_570 . V_571 ) ;
if ( F_367 ( V_2 , V_1043 ,
V_10 ) )
F_132 ( L_169 ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
} else {
F_129 ( V_1042 , V_10 ) ;
F_130 ( V_1042 ) ;
}
}
static void F_649 ( struct V_1 * V_2 ,
bool V_1044 , bool V_1045 )
{
T_2 V_10 ;
F_644 ( V_2 ) ;
V_10 = F_11 ( V_766 ) ;
if ( V_1044 ) {
V_10 |= V_768 ;
F_129 ( V_766 , V_10 ) ;
if ( F_604 ( F_11 ( V_766 ) &
V_1046 , 1 ) )
F_132 ( L_170 ) ;
V_10 = F_11 ( V_766 ) ;
}
V_10 |= V_1047 ;
F_129 ( V_766 , V_10 ) ;
F_130 ( V_766 ) ;
if ( F_62 ( ( F_11 ( V_766 ) & V_694 ) == 0 , 1 ) )
F_132 ( L_171 ) ;
V_10 = F_647 ( V_2 ) ;
V_10 |= V_1048 ;
F_648 ( V_2 , V_10 ) ;
F_650 ( 100 ) ;
if ( F_62 ( ( F_647 ( V_2 ) & V_1049 ) == 0 ,
1 ) )
F_132 ( L_172 ) ;
if ( V_1045 ) {
V_10 = F_11 ( V_766 ) ;
V_10 |= V_1050 ;
F_129 ( V_766 , V_10 ) ;
F_130 ( V_766 ) ;
}
}
static void F_651 ( struct V_1 * V_2 )
{
T_2 V_10 ;
V_10 = F_11 ( V_766 ) ;
if ( ( V_10 & ( V_694 | V_1047 | V_768 |
V_1050 ) ) == V_694 )
return;
F_652 ( V_2 , V_1051 ) ;
if ( V_10 & V_1050 ) {
V_10 &= ~ V_1050 ;
F_129 ( V_766 , V_10 ) ;
F_130 ( V_766 ) ;
}
V_10 = F_647 ( V_2 ) ;
V_10 |= V_1052 ;
V_10 &= ~ V_1048 ;
F_648 ( V_2 , V_10 ) ;
V_10 = F_11 ( V_766 ) ;
V_10 &= ~ V_1047 ;
F_129 ( V_766 , V_10 ) ;
if ( F_62 ( F_11 ( V_766 ) & V_694 , 5 ) )
F_132 ( L_173 ) ;
if ( V_10 & V_768 ) {
V_10 = F_11 ( V_766 ) ;
V_10 &= ~ V_768 ;
F_129 ( V_766 , V_10 ) ;
if ( F_604 ( ( F_11 ( V_766 ) &
V_1046 ) == 0 , 1 ) )
F_132 ( L_174 ) ;
}
F_653 ( V_2 , V_1051 ) ;
F_435 ( V_2 -> V_16 ) ;
}
void F_654 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_10 ;
F_153 ( L_175 ) ;
if ( F_607 ( V_16 ) ) {
V_10 = F_11 ( V_1053 ) ;
V_10 &= ~ V_1054 ;
F_129 ( V_1053 , V_10 ) ;
}
F_608 ( V_16 ) ;
F_649 ( V_2 , true , true ) ;
}
void F_655 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_10 ;
F_153 ( L_176 ) ;
F_651 ( V_2 ) ;
F_611 ( V_16 ) ;
if ( F_607 ( V_16 ) ) {
V_10 = F_11 ( V_1053 ) ;
V_10 |= V_1054 ;
F_129 ( V_1053 , V_10 ) ;
}
F_656 ( V_16 ) ;
}
static void F_657 ( struct V_45 * V_727 )
{
struct V_15 * V_16 = V_727 -> V_16 ;
unsigned int V_728 = F_355 ( V_727 ) -> V_644 ;
F_436 ( V_16 , V_728 ) ;
}
static int F_658 ( struct V_45 * V_36 )
{
struct V_37 * V_37 ;
struct V_43 * V_44 ;
int V_1055 = 0 ;
F_140 (state->dev, intel_crtc) {
int V_1056 ;
V_44 = F_466 ( V_36 , V_37 ) ;
if ( F_467 ( V_44 ) )
return F_468 ( V_44 ) ;
if ( ! V_44 -> V_40 . V_243 )
continue;
V_1056 = F_510 ( V_44 ) ;
if ( F_236 ( V_36 -> V_16 ) && V_44 -> V_569 )
V_1056 = F_185 ( V_1056 * 100 , 95 ) ;
V_1055 = V_91 ( V_1055 , V_1056 ) ;
}
return V_1055 ;
}
static void F_659 ( struct V_15 * V_16 , int V_644 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_10 , V_1057 ;
int V_305 ;
if ( F_6 ( ( F_11 ( V_766 ) &
( V_1047 | V_694 |
V_1058 | V_1059 |
V_1060 | V_1050 |
V_768 ) ) != V_694 ,
L_177 ) )
return;
F_2 ( & V_2 -> V_570 . V_571 ) ;
V_305 = F_367 ( V_2 ,
V_1061 , 0x0 ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
if ( V_305 ) {
F_132 ( L_178 ) ;
return;
}
V_10 = F_11 ( V_766 ) ;
V_10 |= V_768 ;
F_129 ( V_766 , V_10 ) ;
if ( F_604 ( F_11 ( V_766 ) &
V_1046 , 1 ) )
F_132 ( L_170 ) ;
V_10 = F_11 ( V_766 ) ;
V_10 &= ~ V_767 ;
switch ( V_644 ) {
case 450000 :
V_10 |= V_769 ;
V_1057 = 0 ;
break;
case 540000 :
V_10 |= V_770 ;
V_1057 = 1 ;
break;
case 337500 :
V_10 |= V_771 ;
V_1057 = 2 ;
break;
case 675000 :
V_10 |= V_1062 ;
V_1057 = 3 ;
break;
default:
F_6 ( 1 , L_179 ) ;
return;
}
F_129 ( V_766 , V_10 ) ;
V_10 = F_11 ( V_766 ) ;
V_10 &= ~ V_768 ;
F_129 ( V_766 , V_10 ) ;
if ( F_604 ( ( F_11 ( V_766 ) &
V_1046 ) == 0 , 1 ) )
F_132 ( L_174 ) ;
F_2 ( & V_2 -> V_570 . V_571 ) ;
F_367 ( V_2 , V_665 , V_1057 ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
F_435 ( V_16 ) ;
F_6 ( V_644 != V_2 -> V_645 ,
L_180 ,
V_644 , V_2 -> V_645 ) ;
}
static int F_660 ( struct V_45 * V_36 )
{
struct V_1 * V_2 = F_204 ( V_36 -> V_16 ) ;
int V_719 = F_658 ( V_36 ) ;
int V_644 ;
if ( V_719 > 540000 )
V_644 = 675000 ;
else if ( V_719 > 450000 )
V_644 = 540000 ;
else if ( V_719 > 337500 )
V_644 = 450000 ;
else
V_644 = 337500 ;
if ( V_644 > V_2 -> V_647 ) {
F_153 ( L_181 ,
V_644 , V_2 -> V_647 ) ;
return - V_307 ;
}
F_355 ( V_36 ) -> V_644 = V_644 ;
return 0 ;
}
static void F_661 ( struct V_45 * V_727 )
{
struct V_15 * V_16 = V_727 -> V_16 ;
unsigned int V_728 = F_355 ( V_727 ) -> V_644 ;
F_659 ( V_16 , V_728 ) ;
}
static int F_662 ( struct V_37 * V_38 ,
struct V_43 * V_44 )
{
if ( ! F_663 ( V_38 , V_44 ) )
return - V_307 ;
V_38 -> V_836 = false ;
return 0 ;
}
static void F_664 ( struct V_1 * V_2 ,
enum V_217 V_217 ,
struct V_43 * V_212 )
{
switch ( V_217 ) {
case V_617 :
V_212 -> V_1063 = V_689 ;
V_212 -> V_135 = V_1064 ;
break;
case V_231 :
V_212 -> V_1063 = V_1065 ;
V_212 -> V_135 = V_1066 ;
break;
case V_233 :
V_212 -> V_1063 = V_1067 ;
V_212 -> V_135 = V_1068 ;
break;
default:
F_132 ( L_182 ) ;
}
}
static void F_665 ( struct V_1 * V_2 ,
enum V_217 V_217 ,
struct V_43 * V_212 )
{
T_1 V_461 , V_1069 ;
V_461 = F_11 ( V_1070 ) & F_666 ( V_217 ) ;
V_212 -> V_1063 = V_461 >> ( V_217 * 3 + 1 ) ;
switch ( V_212 -> V_1063 ) {
case V_689 :
V_1069 = F_11 ( V_688 ) ;
V_212 -> V_213 . V_1071 = V_1069 & 0x3f ;
break;
case V_1065 :
V_212 -> V_135 = V_1064 ;
break;
case V_1067 :
V_212 -> V_135 = V_1066 ;
break;
case V_1072 :
V_212 -> V_135 = V_1068 ;
break;
}
}
static void F_667 ( struct V_1 * V_2 ,
enum V_217 V_217 ,
struct V_43 * V_212 )
{
V_212 -> V_1063 = F_11 ( F_668 ( V_217 ) ) ;
switch ( V_212 -> V_1063 ) {
case V_1073 :
V_212 -> V_135 = V_1074 ;
break;
case V_1075 :
V_212 -> V_135 = V_1076 ;
break;
case V_1077 :
V_212 -> V_135 = V_1078 ;
break;
}
}
static void F_669 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_134 * V_137 ;
enum V_217 V_217 ;
T_2 V_218 ;
V_218 = F_11 ( F_72 ( V_212 -> V_121 ) ) ;
V_217 = ( V_218 & V_1079 ) >> V_1080 ;
if ( F_431 ( V_16 ) || F_432 ( V_16 ) )
F_665 ( V_2 , V_217 , V_212 ) ;
else if ( F_30 ( V_16 ) )
F_664 ( V_2 , V_217 , V_212 ) ;
else
F_667 ( V_2 , V_217 , V_212 ) ;
if ( V_212 -> V_135 >= 0 ) {
V_137 = & V_2 -> V_136 [ V_212 -> V_135 ] ;
F_9 ( ! V_137 -> V_140 ( V_2 , V_137 ,
& V_212 -> V_213 ) ) ;
}
if ( F_60 ( V_16 ) -> V_127 < 9 &&
( V_217 == V_622 ) && F_11 ( V_258 ) & V_185 ) {
V_212 -> V_261 = true ;
V_218 = F_11 ( F_75 ( V_148 ) ) ;
V_212 -> V_474 = ( ( V_473 & V_218 ) >>
V_1023 ) + 1 ;
F_636 ( V_38 , V_212 ) ;
}
}
static bool F_670 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_165 V_166 ;
unsigned long V_1081 ;
T_2 V_218 ;
bool V_305 ;
V_166 = F_422 ( V_38 -> V_119 ) ;
if ( ! F_87 ( V_2 , V_166 ) )
return false ;
V_1081 = F_230 ( V_166 ) ;
V_305 = false ;
V_212 -> V_121 = (enum V_118 ) V_38 -> V_119 ;
V_212 -> V_135 = V_959 ;
V_218 = F_11 ( F_72 ( V_604 ) ) ;
if ( V_218 & V_141 ) {
enum V_119 V_1082 ;
switch ( V_218 & V_1083 ) {
default:
F_6 ( 1 , L_183 ) ;
case V_1084 :
case V_1085 :
V_1082 = V_148 ;
break;
case V_1086 :
V_1082 = V_157 ;
break;
case V_1087 :
V_1082 = V_524 ;
break;
}
if ( V_1082 == V_38 -> V_119 )
V_212 -> V_121 = V_604 ;
}
V_166 = F_86 ( V_212 -> V_121 ) ;
if ( ! F_87 ( V_2 , V_166 ) )
goto V_960;
V_1081 |= F_230 ( V_166 ) ;
V_218 = F_11 ( F_61 ( V_212 -> V_121 ) ) ;
if ( ! ( V_218 & V_170 ) )
goto V_960;
F_669 ( V_38 , V_212 ) ;
F_588 ( V_38 , V_212 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
F_671 ( V_16 , V_38 , V_212 ) ;
}
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
V_212 -> V_399 . V_436 = - 1 ;
V_212 -> V_399 . V_551 &= ~ ( 1 << V_560 ) ;
}
V_166 = F_423 ( V_38 -> V_119 ) ;
if ( F_87 ( V_2 , V_166 ) ) {
V_1081 |= F_230 ( V_166 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 )
F_637 ( V_38 , V_212 ) ;
else
F_639 ( V_38 , V_212 ) ;
}
if ( F_235 ( V_16 ) )
V_212 -> V_569 = F_397 ( V_38 ) &&
( F_11 ( V_573 ) & V_574 ) ;
if ( V_212 -> V_121 != V_604 ) {
V_212 -> V_605 =
F_11 ( F_400 ( V_212 -> V_121 ) ) + 1 ;
} else {
V_212 -> V_605 = 1 ;
}
V_305 = true ;
V_960:
F_425 (power_domain, power_domain_mask)
F_88 ( V_2 , V_166 ) ;
return V_305 ;
}
static void F_672 ( struct V_111 * V_38 , T_1 V_40 , bool V_239 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_2 V_1088 = 0 , V_296 = 0 ;
if ( V_239 ) {
unsigned int V_354 = V_37 -> V_40 . V_1089 -> V_36 -> V_370 ;
unsigned int V_273 = V_37 -> V_40 . V_1089 -> V_36 -> V_371 ;
unsigned int V_353 = F_673 ( V_354 ) * 4 ;
switch ( V_353 ) {
default:
F_179 ( 1 , L_184 ,
V_354 , V_353 ) ;
V_353 = 256 ;
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
}
V_1088 |= V_163 |
V_1090 |
V_1091 |
F_674 ( V_353 ) ;
V_296 = ( V_273 << 12 ) | V_354 ;
}
if ( V_37 -> V_1092 != 0 &&
( V_37 -> V_1093 != V_40 ||
V_37 -> V_1094 != V_296 ||
V_37 -> V_1092 != V_1088 ) ) {
F_129 ( F_84 ( V_148 ) , 0 ) ;
F_130 ( F_84 ( V_148 ) ) ;
V_37 -> V_1092 = 0 ;
}
if ( V_37 -> V_1093 != V_40 ) {
F_129 ( F_675 ( V_148 ) , V_40 ) ;
V_37 -> V_1093 = V_40 ;
}
if ( V_37 -> V_1094 != V_296 ) {
F_129 ( V_1095 , V_296 ) ;
V_37 -> V_1094 = V_296 ;
}
if ( V_37 -> V_1092 != V_1088 ) {
F_129 ( F_84 ( V_148 ) , V_1088 ) ;
F_130 ( F_84 ( V_148 ) ) ;
V_37 -> V_1092 = V_1088 ;
}
}
static void F_676 ( struct V_111 * V_38 , T_1 V_40 , bool V_239 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_2 V_1088 = 0 ;
if ( V_239 ) {
V_1088 = V_1096 ;
switch ( V_37 -> V_40 . V_1089 -> V_36 -> V_370 ) {
case 64 :
V_1088 |= V_1097 ;
break;
case 128 :
V_1088 |= V_1098 ;
break;
case 256 :
V_1088 |= V_1099 ;
break;
default:
F_180 ( V_37 -> V_40 . V_1089 -> V_36 -> V_370 ) ;
return;
}
V_1088 |= V_119 << 28 ;
if ( F_71 ( V_16 ) )
V_1088 |= V_1100 ;
}
if ( V_38 -> V_1089 -> V_36 -> V_285 == F_230 ( V_386 ) )
V_1088 |= V_1101 ;
if ( V_37 -> V_1092 != V_1088 ) {
F_129 ( F_84 ( V_119 ) , V_1088 ) ;
F_130 ( F_84 ( V_119 ) ) ;
V_37 -> V_1092 = V_1088 ;
}
F_129 ( F_675 ( V_119 ) , V_40 ) ;
F_130 ( F_675 ( V_119 ) ) ;
V_37 -> V_1093 = V_40 ;
}
static void F_677 ( struct V_111 * V_38 ,
bool V_239 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
struct V_277 * V_1102 = V_38 -> V_1089 -> V_36 ;
int V_313 = V_1102 -> V_368 ;
int V_314 = V_1102 -> V_369 ;
T_1 V_40 = 0 , V_566 = 0 ;
V_40 = V_37 -> V_1103 ;
if ( V_313 >= V_37 -> V_115 -> V_381 )
V_239 = false ;
if ( V_314 >= V_37 -> V_115 -> V_380 )
V_239 = false ;
if ( V_313 < 0 ) {
if ( V_313 + V_1102 -> V_370 <= 0 )
V_239 = false ;
V_566 |= V_1104 << V_1105 ;
V_313 = - V_313 ;
}
V_566 |= V_313 << V_1105 ;
if ( V_314 < 0 ) {
if ( V_314 + V_1102 -> V_371 <= 0 )
V_239 = false ;
V_566 |= V_1104 << V_1106 ;
V_314 = - V_314 ;
}
V_566 |= V_314 << V_1106 ;
F_129 ( F_678 ( V_119 ) , V_566 ) ;
if ( F_170 ( V_16 ) &&
V_38 -> V_1089 -> V_36 -> V_285 == F_230 ( V_386 ) ) {
V_40 += ( V_1102 -> V_371 *
V_1102 -> V_370 - 1 ) * 4 ;
}
if ( F_82 ( V_16 ) || F_83 ( V_16 ) )
F_672 ( V_38 , V_40 , V_239 ) ;
else
F_676 ( V_38 , V_40 , V_239 ) ;
}
static bool F_679 ( struct V_15 * V_16 ,
T_2 V_354 , T_2 V_273 )
{
if ( V_354 == 0 || V_273 == 0 )
return false ;
if ( F_82 ( V_16 ) || F_83 ( V_16 ) ) {
if ( ( V_354 & 63 ) != 0 )
return false ;
if ( V_354 > ( F_82 ( V_16 ) ? 64 : 512 ) )
return false ;
if ( V_273 > 1023 )
return false ;
} else {
switch ( V_354 | V_273 ) {
case 256 :
case 128 :
if ( F_33 ( V_16 ) )
return false ;
case 64 :
break;
default:
return false ;
}
}
return true ;
}
static void F_680 ( struct V_111 * V_38 , T_7 * V_1107 , T_7 * V_1108 ,
T_7 * V_1109 , T_2 V_395 , T_2 V_296 )
{
int V_1110 = ( V_395 + V_296 > 256 ) ? 256 : V_395 + V_296 , V_50 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
for ( V_50 = V_395 ; V_50 < V_1110 ; V_50 ++ ) {
V_37 -> V_579 [ V_50 ] = V_1107 [ V_50 ] >> 8 ;
V_37 -> V_580 [ V_50 ] = V_1108 [ V_50 ] >> 8 ;
V_37 -> V_581 [ V_50 ] = V_1109 [ V_50 ] >> 8 ;
}
F_370 ( V_38 ) ;
}
struct V_276 *
F_681 ( struct V_15 * V_16 ,
struct V_345 * V_346 ,
struct V_302 * V_303 )
{
struct V_951 * V_952 ;
int V_305 ;
V_952 = F_499 ( sizeof( * V_952 ) , V_746 ) ;
if ( ! V_952 )
return F_682 ( - V_742 ) ;
V_305 = F_208 ( V_16 , V_952 , V_346 , V_303 ) ;
if ( V_305 )
goto V_98;
return & V_952 -> V_40 ;
V_98:
F_216 ( V_952 ) ;
return F_682 ( V_305 ) ;
}
static struct V_276 *
F_683 ( struct V_15 * V_16 ,
struct V_345 * V_346 ,
struct V_302 * V_303 )
{
struct V_276 * V_114 ;
int V_305 ;
V_305 = F_684 ( V_16 ) ;
if ( V_305 )
return F_682 ( V_305 ) ;
V_114 = F_681 ( V_16 , V_346 , V_303 ) ;
F_4 ( & V_16 -> V_306 ) ;
return V_114 ;
}
static T_1
F_685 ( int V_354 , int V_1010 )
{
T_1 V_287 = F_185 ( V_354 * V_1010 , 8 ) ;
return F_182 ( V_287 , 64 ) ;
}
static T_1
F_686 ( struct V_533 * V_445 , int V_1010 )
{
T_1 V_287 = F_685 ( V_445 -> V_920 , V_1010 ) ;
return F_687 ( V_287 * V_445 -> V_919 ) ;
}
static struct V_276 *
F_688 ( struct V_15 * V_16 ,
struct V_533 * V_445 ,
int V_1111 , int V_1010 )
{
struct V_276 * V_114 ;
struct V_302 * V_303 ;
struct V_345 V_346 = { 0 } ;
V_303 = F_689 ( V_16 ,
F_686 ( V_445 , V_1010 ) ) ;
if ( V_303 == NULL )
return F_682 ( - V_742 ) ;
V_346 . V_354 = V_445 -> V_920 ;
V_346 . V_273 = V_445 -> V_919 ;
V_346 . V_288 [ 0 ] = F_685 ( V_346 . V_354 ,
V_1010 ) ;
V_346 . V_265 = F_690 ( V_1010 , V_1111 ) ;
V_114 = F_683 ( V_16 , & V_346 , V_303 ) ;
if ( F_467 ( V_114 ) )
F_691 ( & V_303 -> V_40 ) ;
return V_114 ;
}
static struct V_276 *
F_692 ( struct V_15 * V_16 ,
struct V_533 * V_445 )
{
#ifdef F_693
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_302 * V_303 ;
struct V_276 * V_114 ;
if ( ! V_2 -> V_1112 )
return NULL ;
if ( ! V_2 -> V_1112 -> V_114 )
return NULL ;
V_303 = V_2 -> V_1112 -> V_114 -> V_303 ;
F_142 ( ! V_303 ) ;
V_114 = & V_2 -> V_1112 -> V_114 -> V_40 ;
if ( V_114 -> V_288 [ 0 ] < F_685 ( V_445 -> V_920 ,
V_114 -> V_391 ) )
return NULL ;
if ( V_303 -> V_40 . V_296 < V_445 -> V_919 * V_114 -> V_288 [ 0 ] )
return NULL ;
return V_114 ;
#else
return NULL ;
#endif
}
static int F_694 ( struct V_45 * V_36 ,
struct V_111 * V_38 ,
struct V_533 * V_445 ,
struct V_276 * V_114 ,
int V_313 , int V_314 )
{
struct V_277 * V_278 ;
int V_920 , V_919 ;
int V_305 ;
V_278 = F_695 ( V_36 , V_38 -> V_113 ) ;
if ( F_467 ( V_278 ) )
return F_468 ( V_278 ) ;
if ( V_445 )
F_696 ( V_445 , & V_920 , & V_919 ) ;
else
V_920 = V_919 = 0 ;
V_305 = F_697 ( V_278 , V_114 ? V_38 : NULL ) ;
if ( V_305 )
return V_305 ;
F_698 ( V_278 , V_114 ) ;
V_278 -> V_368 = 0 ;
V_278 -> V_369 = 0 ;
V_278 -> V_370 = V_920 ;
V_278 -> V_371 = V_919 ;
V_278 -> V_364 = V_313 << 16 ;
V_278 -> V_365 = V_314 << 16 ;
V_278 -> V_366 = V_920 << 16 ;
V_278 -> V_367 = V_919 << 16 ;
return 0 ;
}
bool F_699 ( struct V_46 * V_47 ,
struct V_533 * V_445 ,
struct V_1113 * V_1114 ,
struct V_738 * V_739 )
{
struct V_37 * V_37 ;
struct V_41 * V_41 =
F_700 ( V_47 ) ;
struct V_111 * V_1115 ;
struct V_743 * V_42 = & V_41 -> V_40 ;
struct V_111 * V_38 = NULL ;
struct V_15 * V_16 = V_42 -> V_16 ;
struct V_276 * V_114 ;
struct V_736 * V_115 = & V_16 -> V_737 ;
struct V_45 * V_36 = NULL ;
struct V_48 * V_49 ;
struct V_43 * V_44 ;
int V_305 , V_50 = - 1 ;
F_153 ( L_185 ,
V_47 -> V_40 . V_241 , V_47 -> V_8 ,
V_42 -> V_40 . V_241 , V_42 -> V_8 ) ;
V_479:
V_305 = F_701 ( & V_115 -> V_1116 , V_739 ) ;
if ( V_305 )
goto V_811;
if ( V_42 -> V_38 ) {
V_38 = V_42 -> V_38 ;
V_305 = F_701 ( & V_38 -> V_1117 , V_739 ) ;
if ( V_305 )
goto V_811;
V_305 = F_701 ( & V_38 -> V_113 -> V_1117 , V_739 ) ;
if ( V_305 )
goto V_811;
V_1114 -> V_1118 = V_47 -> V_1119 ;
V_1114 -> V_1120 = false ;
if ( V_47 -> V_1119 != V_1121 )
V_47 -> V_1122 -> V_1119 ( V_47 , V_1121 ) ;
return true ;
}
F_217 (dev, possible_crtc) {
V_50 ++ ;
if ( ! ( V_42 -> V_1123 & ( 1 << V_50 ) ) )
continue;
if ( V_1115 -> V_36 -> V_243 )
continue;
V_38 = V_1115 ;
break;
}
if ( ! V_38 ) {
F_153 ( L_186 ) ;
goto V_811;
}
V_305 = F_701 ( & V_38 -> V_1117 , V_739 ) ;
if ( V_305 )
goto V_811;
V_305 = F_701 ( & V_38 -> V_113 -> V_1117 , V_739 ) ;
if ( V_305 )
goto V_811;
V_37 = F_50 ( V_38 ) ;
V_1114 -> V_1118 = V_47 -> V_1119 ;
V_1114 -> V_1120 = true ;
V_1114 -> V_1124 = NULL ;
V_36 = F_488 ( V_16 ) ;
if ( ! V_36 )
return false ;
V_36 -> V_740 = V_739 ;
V_49 = F_702 ( V_36 , V_47 ) ;
if ( F_467 ( V_49 ) ) {
V_305 = F_468 ( V_49 ) ;
goto V_811;
}
V_49 -> V_38 = V_38 ;
V_49 -> V_52 = & V_41 -> V_40 ;
V_44 = F_466 ( V_36 , V_37 ) ;
if ( F_467 ( V_44 ) ) {
V_305 = F_468 ( V_44 ) ;
goto V_811;
}
V_44 -> V_40 . V_112 = V_44 -> V_40 . V_243 = true ;
if ( ! V_445 )
V_445 = & V_1125 ;
V_114 = F_692 ( V_16 , V_445 ) ;
if ( V_114 == NULL ) {
F_153 ( L_187 ) ;
V_114 = F_688 ( V_16 , V_445 , 24 , 32 ) ;
V_1114 -> V_1124 = V_114 ;
} else
F_153 ( L_188 ) ;
if ( F_467 ( V_114 ) ) {
F_153 ( L_189 ) ;
goto V_811;
}
V_305 = F_694 ( V_36 , V_38 , V_445 , V_114 , 0 , 0 ) ;
if ( V_305 )
goto V_811;
F_703 ( & V_44 -> V_40 . V_445 , V_445 ) ;
if ( F_491 ( V_36 ) ) {
F_153 ( L_190 ) ;
if ( V_1114 -> V_1124 )
V_1114 -> V_1124 -> V_1122 -> V_1126 ( V_1114 -> V_1124 ) ;
goto V_811;
}
V_38 -> V_113 -> V_38 = V_38 ;
F_307 ( V_16 , V_37 -> V_119 ) ;
return true ;
V_811:
F_492 ( V_36 ) ;
V_36 = NULL ;
if ( V_305 == - V_310 ) {
F_704 ( V_739 ) ;
goto V_479;
}
return false ;
}
void F_705 ( struct V_46 * V_47 ,
struct V_1113 * V_1114 ,
struct V_738 * V_739 )
{
struct V_15 * V_16 = V_47 -> V_16 ;
struct V_41 * V_41 =
F_700 ( V_47 ) ;
struct V_743 * V_42 = & V_41 -> V_40 ;
struct V_111 * V_38 = V_42 -> V_38 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_45 * V_36 ;
struct V_48 * V_49 ;
struct V_43 * V_44 ;
int V_305 ;
F_153 ( L_185 ,
V_47 -> V_40 . V_241 , V_47 -> V_8 ,
V_42 -> V_40 . V_241 , V_42 -> V_8 ) ;
if ( V_1114 -> V_1120 ) {
V_36 = F_488 ( V_16 ) ;
if ( ! V_36 )
goto V_811;
V_36 -> V_740 = V_739 ;
V_49 = F_702 ( V_36 , V_47 ) ;
if ( F_467 ( V_49 ) )
goto V_811;
V_44 = F_466 ( V_36 , V_37 ) ;
if ( F_467 ( V_44 ) )
goto V_811;
V_49 -> V_52 = NULL ;
V_49 -> V_38 = NULL ;
V_44 -> V_40 . V_243 = V_44 -> V_40 . V_112 = false ;
V_305 = F_694 ( V_36 , V_38 , NULL , NULL ,
0 , 0 ) ;
if ( V_305 )
goto V_811;
V_305 = F_491 ( V_36 ) ;
if ( V_305 )
goto V_811;
if ( V_1114 -> V_1124 ) {
F_706 ( V_1114 -> V_1124 ) ;
F_212 ( V_1114 -> V_1124 ) ;
}
return;
}
if ( V_1114 -> V_1118 != V_1121 )
V_47 -> V_1122 -> V_1119 ( V_47 , V_1114 -> V_1118 ) ;
return;
V_811:
F_153 ( L_191 ) ;
F_492 ( V_36 ) ;
}
static int F_707 ( struct V_15 * V_16 ,
const struct V_43 * V_212 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_87 = V_212 -> V_213 . V_87 ;
if ( ( V_87 & V_1127 ) == V_904 )
return V_2 -> V_829 . V_832 ;
else if ( F_10 ( V_16 ) )
return 120000 ;
else if ( ! F_33 ( V_16 ) )
return 96000 ;
else
return 48000 ;
}
static void F_600 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_212 -> V_121 ;
T_1 V_87 = V_212 -> V_213 . V_87 ;
T_1 V_834 ;
T_4 clock ;
int V_866 ;
int V_53 = F_707 ( V_16 , V_212 ) ;
if ( ( V_87 & V_1128 ) == 0 )
V_834 = V_212 -> V_213 . V_732 ;
else
V_834 = V_212 -> V_213 . V_733 ;
clock . V_88 = ( V_834 & V_1129 ) >> V_1130 ;
if ( F_32 ( V_16 ) ) {
clock . V_84 = F_708 ( ( V_834 & V_1131 ) >> V_1132 ) - 1 ;
clock . V_80 = ( V_834 & V_1133 ) >> V_1134 ;
} else {
clock . V_84 = ( V_834 & V_1135 ) >> V_1132 ;
clock . V_80 = ( V_834 & V_1136 ) >> V_1134 ;
}
if ( ! F_33 ( V_16 ) ) {
if ( F_32 ( V_16 ) )
clock . V_82 = F_708 ( ( V_87 & V_1137 ) >>
V_894 ) ;
else
clock . V_82 = F_708 ( ( V_87 & V_1138 ) >>
V_895 ) ;
switch ( V_87 & V_1139 ) {
case V_891 :
clock . V_83 = V_87 & V_897 ?
5 : 10 ;
break;
case V_890 :
clock . V_83 = V_87 & V_898 ?
7 : 14 ;
break;
default:
F_153 ( L_192
L_193 , ( int ) ( V_87 & V_1139 ) ) ;
return;
}
if ( F_32 ( V_16 ) )
V_866 = F_34 ( V_53 , & clock ) ;
else
V_866 = F_36 ( V_53 , & clock ) ;
} else {
T_1 V_1140 = F_143 ( V_16 ) ? 0 : F_11 ( V_159 ) ;
bool V_996 = ( V_119 == 1 ) && ( V_1140 & V_195 ) ;
if ( V_996 ) {
clock . V_82 = F_708 ( ( V_87 & V_1141 ) >>
V_895 ) ;
if ( V_1140 & V_1142 )
clock . V_83 = 7 ;
else
clock . V_83 = 14 ;
} else {
if ( V_87 & V_906 )
clock . V_82 = 2 ;
else {
clock . V_82 = ( ( V_87 & V_1143 ) >>
V_895 ) + 2 ;
}
if ( V_87 & V_907 )
clock . V_83 = 4 ;
else
clock . V_83 = 2 ;
}
V_866 = F_36 ( V_53 , & clock ) ;
}
V_212 -> V_866 = V_866 ;
}
int F_709 ( int V_1144 ,
const struct V_821 * V_822 )
{
if ( ! V_822 -> V_827 )
return 0 ;
return F_48 ( ( T_6 ) V_822 -> V_826 * V_1144 , V_822 -> V_827 ) ;
}
static void F_643 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
F_600 ( V_38 , V_212 ) ;
V_212 -> V_40 . V_116 . V_117 =
F_709 ( F_17 ( V_16 ) * 10000 ,
& V_212 -> V_601 ) ;
}
struct V_533 * F_710 ( struct V_15 * V_16 ,
struct V_111 * V_38 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_118 V_121 = V_37 -> V_115 -> V_121 ;
struct V_533 * V_445 ;
struct V_43 V_212 ;
int V_1145 = F_11 ( F_327 ( V_121 ) ) ;
int V_928 = F_11 ( F_331 ( V_121 ) ) ;
int V_1146 = F_11 ( F_333 ( V_121 ) ) ;
int V_1147 = F_11 ( F_337 ( V_121 ) ) ;
enum V_119 V_119 = V_37 -> V_119 ;
V_445 = F_499 ( sizeof( * V_445 ) , V_746 ) ;
if ( ! V_445 )
return NULL ;
V_212 . V_121 = (enum V_118 ) V_119 ;
V_212 . V_605 = 1 ;
V_212 . V_213 . V_87 = F_11 ( F_65 ( V_119 ) ) ;
V_212 . V_213 . V_732 = F_11 ( F_481 ( V_119 ) ) ;
V_212 . V_213 . V_733 = F_11 ( F_482 ( V_119 ) ) ;
F_600 ( V_37 , & V_212 ) ;
V_445 -> clock = V_212 . V_866 / V_212 . V_605 ;
V_445 -> V_920 = ( V_1145 & 0xffff ) + 1 ;
V_445 -> V_921 = ( ( V_1145 & 0xffff0000 ) >> 16 ) + 1 ;
V_445 -> V_922 = ( V_928 & 0xffff ) + 1 ;
V_445 -> V_923 = ( ( V_928 & 0xffff0000 ) >> 16 ) + 1 ;
V_445 -> V_919 = ( V_1146 & 0xffff ) + 1 ;
V_445 -> V_924 = ( ( V_1146 & 0xffff0000 ) >> 16 ) + 1 ;
V_445 -> V_925 = ( V_1147 & 0xffff ) + 1 ;
V_445 -> V_926 = ( ( V_1147 & 0xffff0000 ) >> 16 ) + 1 ;
F_592 ( V_445 ) ;
return V_445 ;
}
void F_711 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( V_2 -> V_583 . V_1148 )
return;
F_192 ( V_2 ) ;
F_712 ( V_2 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 6 )
F_713 ( V_2 ) ;
V_2 -> V_583 . V_1148 = true ;
}
void F_714 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! V_2 -> V_583 . V_1148 )
return;
V_2 -> V_583 . V_1148 = false ;
if ( F_60 ( V_16 ) -> V_127 >= 6 )
F_715 ( V_16 -> V_17 ) ;
F_196 ( V_2 ) ;
}
static void F_716 ( struct V_111 * V_38 )
{
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_495 * V_496 ;
F_275 ( & V_16 -> V_457 ) ;
V_496 = V_37 -> V_458 ;
V_37 -> V_458 = NULL ;
F_276 ( & V_16 -> V_457 ) ;
if ( V_496 ) {
F_717 ( & V_496 -> V_496 ) ;
F_216 ( V_496 ) ;
}
F_718 ( V_38 ) ;
F_216 ( V_37 ) ;
}
static void F_719 ( struct V_1149 * V_1150 )
{
struct V_495 * V_496 =
F_720 ( V_1150 , struct V_495 , V_496 ) ;
struct V_37 * V_38 = F_50 ( V_496 -> V_38 ) ;
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_301 * V_113 = V_38 -> V_40 . V_113 ;
F_2 ( & V_16 -> V_306 ) ;
F_198 ( V_496 -> V_1151 , V_113 -> V_36 ) ;
F_210 ( & V_496 -> V_500 -> V_40 ) ;
if ( V_496 -> V_1152 )
F_721 ( & V_496 -> V_1152 , NULL ) ;
F_4 ( & V_16 -> V_306 ) ;
F_722 ( V_16 , F_215 ( V_113 ) -> V_374 ) ;
F_212 ( V_496 -> V_1151 ) ;
F_142 ( F_282 ( & V_38 -> V_494 ) == 0 ) ;
F_723 ( & V_38 -> V_494 ) ;
F_216 ( V_496 ) ;
}
static void F_724 ( struct V_15 * V_16 ,
struct V_111 * V_38 )
{
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_495 * V_496 ;
unsigned long V_355 ;
if ( V_37 == NULL )
return;
F_725 ( & V_16 -> V_457 , V_355 ) ;
V_496 = V_37 -> V_458 ;
F_309 () ;
if ( V_496 == NULL || F_282 ( & V_496 -> V_454 ) < V_1153 ) {
F_726 ( & V_16 -> V_457 , V_355 ) ;
return;
}
F_308 ( V_37 ) ;
F_726 ( & V_16 -> V_457 , V_355 ) ;
}
void F_727 ( struct V_15 * V_16 , int V_119 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_111 * V_38 = V_2 -> V_120 [ V_119 ] ;
F_724 ( V_16 , V_38 ) ;
}
void F_264 ( struct V_15 * V_16 , int V_171 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_111 * V_38 = V_2 -> V_1154 [ V_171 ] ;
F_724 ( V_16 , V_38 ) ;
}
static bool F_728 ( T_1 V_1155 , T_1 V_1156 )
{
return ! ( ( V_1155 - V_1156 ) & 0x80000000 ) ;
}
static bool F_729 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_281 ( & V_2 -> V_455 ) ||
V_38 -> V_456 != F_282 ( & V_2 -> V_455 . V_456 ) )
return true ;
if ( F_60 ( V_16 ) -> V_127 < 5 && ! F_31 ( V_16 ) )
return true ;
return ( F_11 ( F_730 ( V_38 -> V_171 ) ) & ~ 0xfff ) ==
V_38 -> V_458 -> V_1157 &&
F_728 ( F_11 ( F_731 ( V_38 -> V_119 ) ) ,
V_38 -> V_458 -> V_1158 ) ;
}
void F_263 ( struct V_15 * V_16 , int V_171 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 =
F_50 ( V_2 -> V_1154 [ V_171 ] ) ;
unsigned long V_355 ;
F_725 ( & V_16 -> V_457 , V_355 ) ;
if ( V_37 -> V_458 && F_729 ( V_37 ) )
F_732 ( & V_37 -> V_458 -> V_454 ) ;
F_726 ( & V_16 -> V_457 , V_355 ) ;
}
static inline void F_733 ( struct V_495 * V_496 )
{
F_734 () ;
F_735 ( & V_496 -> V_454 , V_1159 ) ;
F_734 () ;
}
static int F_736 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_276 * V_114 ,
struct V_302 * V_303 ,
struct V_1160 * V_1161 ,
T_2 V_355 )
{
struct V_1162 * V_1163 = V_1161 -> V_1163 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_1 V_1164 ;
int V_305 ;
V_305 = F_737 ( V_1161 , 6 ) ;
if ( V_305 )
return V_305 ;
if ( V_37 -> V_171 )
V_1164 = V_1165 ;
else
V_1164 = V_1166 ;
F_738 ( V_1163 , V_1167 | V_1164 ) ;
F_738 ( V_1163 , V_1168 ) ;
F_738 ( V_1163 , V_1169 |
F_739 ( V_37 -> V_171 ) ) ;
F_738 ( V_1163 , V_114 -> V_288 [ 0 ] ) ;
F_738 ( V_1163 , V_37 -> V_458 -> V_1157 ) ;
F_738 ( V_1163 , 0 ) ;
F_733 ( V_37 -> V_458 ) ;
return 0 ;
}
static int F_740 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_276 * V_114 ,
struct V_302 * V_303 ,
struct V_1160 * V_1161 ,
T_2 V_355 )
{
struct V_1162 * V_1163 = V_1161 -> V_1163 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_1 V_1164 ;
int V_305 ;
V_305 = F_737 ( V_1161 , 6 ) ;
if ( V_305 )
return V_305 ;
if ( V_37 -> V_171 )
V_1164 = V_1165 ;
else
V_1164 = V_1166 ;
F_738 ( V_1163 , V_1167 | V_1164 ) ;
F_738 ( V_1163 , V_1168 ) ;
F_738 ( V_1163 , V_1170 |
F_739 ( V_37 -> V_171 ) ) ;
F_738 ( V_1163 , V_114 -> V_288 [ 0 ] ) ;
F_738 ( V_1163 , V_37 -> V_458 -> V_1157 ) ;
F_738 ( V_1163 , V_1168 ) ;
F_733 ( V_37 -> V_458 ) ;
return 0 ;
}
static int F_741 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_276 * V_114 ,
struct V_302 * V_303 ,
struct V_1160 * V_1161 ,
T_2 V_355 )
{
struct V_1162 * V_1163 = V_1161 -> V_1163 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_2 V_1171 , V_1172 ;
int V_305 ;
V_305 = F_737 ( V_1161 , 4 ) ;
if ( V_305 )
return V_305 ;
F_738 ( V_1163 , V_1169 |
F_739 ( V_37 -> V_171 ) ) ;
F_738 ( V_1163 , V_114 -> V_288 [ 0 ] ) ;
F_738 ( V_1163 , V_37 -> V_458 -> V_1157 |
V_303 -> V_315 ) ;
V_1171 = 0 ;
V_1172 = F_11 ( F_286 ( V_37 -> V_119 ) ) & 0x0fff0fff ;
F_738 ( V_1163 , V_1171 | V_1172 ) ;
F_733 ( V_37 -> V_458 ) ;
return 0 ;
}
static int F_742 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_276 * V_114 ,
struct V_302 * V_303 ,
struct V_1160 * V_1161 ,
T_2 V_355 )
{
struct V_1162 * V_1163 = V_1161 -> V_1163 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_2 V_1171 , V_1172 ;
int V_305 ;
V_305 = F_737 ( V_1161 , 4 ) ;
if ( V_305 )
return V_305 ;
F_738 ( V_1163 , V_1169 |
F_739 ( V_37 -> V_171 ) ) ;
F_738 ( V_1163 , V_114 -> V_288 [ 0 ] | V_303 -> V_315 ) ;
F_738 ( V_1163 , V_37 -> V_458 -> V_1157 ) ;
V_1171 = 0 ;
V_1172 = F_11 ( F_286 ( V_37 -> V_119 ) ) & 0x0fff0fff ;
F_738 ( V_1163 , V_1171 | V_1172 ) ;
F_733 ( V_37 -> V_458 ) ;
return 0 ;
}
static int F_743 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_276 * V_114 ,
struct V_302 * V_303 ,
struct V_1160 * V_1161 ,
T_2 V_355 )
{
struct V_1162 * V_1163 = V_1161 -> V_1163 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_2 V_1173 = 0 ;
int V_1174 , V_305 ;
switch ( V_37 -> V_171 ) {
case V_1175 :
V_1173 = V_1176 ;
break;
case V_382 :
V_1173 = V_1177 ;
break;
case V_1178 :
V_1173 = V_1179 ;
break;
default:
F_179 ( 1 , L_194 ) ;
return - V_1180 ;
}
V_1174 = 4 ;
if ( V_1163 -> V_241 == V_1181 ) {
V_1174 += 6 ;
if ( F_744 ( V_16 ) )
V_1174 += 2 ;
}
V_305 = F_745 ( V_1161 ) ;
if ( V_305 )
return V_305 ;
V_305 = F_737 ( V_1161 , V_1174 ) ;
if ( V_305 )
return V_305 ;
if ( V_1163 -> V_241 == V_1181 ) {
F_738 ( V_1163 , F_746 ( 1 ) ) ;
F_747 ( V_1163 , V_1182 ) ;
F_738 ( V_1163 , ~ ( V_1183 |
V_1184 |
V_1185 ) ) ;
if ( F_744 ( V_16 ) )
F_738 ( V_1163 , V_1186 |
V_1187 ) ;
else
F_738 ( V_1163 , V_1188 |
V_1187 ) ;
F_747 ( V_1163 , V_1182 ) ;
F_738 ( V_1163 , V_1163 -> V_1189 . V_1157 + 256 ) ;
if ( F_744 ( V_16 ) ) {
F_738 ( V_1163 , 0 ) ;
F_738 ( V_1163 , V_1168 ) ;
}
}
F_738 ( V_1163 , V_1170 | V_1173 ) ;
F_738 ( V_1163 , ( V_114 -> V_288 [ 0 ] | V_303 -> V_315 ) ) ;
F_738 ( V_1163 , V_37 -> V_458 -> V_1157 ) ;
F_738 ( V_1163 , ( V_1168 ) ) ;
F_733 ( V_37 -> V_458 ) ;
return 0 ;
}
static bool F_748 ( struct V_1162 * V_1163 ,
struct V_302 * V_303 )
{
if ( V_1163 == NULL )
return true ;
if ( F_60 ( V_1163 -> V_16 ) -> V_127 < 5 )
return false ;
if ( V_757 . F_748 < 0 )
return false ;
else if ( V_757 . F_748 > 0 )
return true ;
else if ( V_757 . V_1190 )
return true ;
else if ( V_303 -> V_40 . V_1191 &&
! F_749 ( V_303 -> V_40 . V_1191 -> V_1192 ,
false ) )
return true ;
else
return V_1163 != F_750 ( V_303 -> V_1193 ) ;
}
static void F_751 ( struct V_37 * V_37 ,
unsigned int V_285 ,
struct V_495 * V_496 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_276 * V_114 = V_37 -> V_40 . V_113 -> V_114 ;
const enum V_119 V_119 = V_37 -> V_119 ;
T_1 V_1194 , V_353 , V_267 ;
V_1194 = F_11 ( F_96 ( V_119 , 0 ) ) ;
V_1194 &= ~ V_1020 ;
switch ( V_114 -> V_292 [ 0 ] ) {
case V_269 :
break;
case V_270 :
V_1194 |= V_415 ;
break;
case V_271 :
V_1194 |= V_416 ;
break;
case V_272 :
V_1194 |= V_417 ;
break;
default:
F_180 ( V_114 -> V_292 [ 0 ] ) ;
}
if ( F_184 ( V_285 ) ) {
V_267 = F_177 ( V_16 , V_114 -> V_265 ,
V_114 -> V_292 [ 0 ] , 0 ) ;
V_353 = F_185 ( V_114 -> V_273 , V_267 ) ;
} else {
V_353 = V_114 -> V_288 [ 0 ] /
F_238 ( V_16 , V_114 -> V_292 [ 0 ] ,
V_114 -> V_265 ) ;
}
F_129 ( F_96 ( V_119 , 0 ) , V_1194 ) ;
F_129 ( F_257 ( V_119 , 0 ) , V_353 ) ;
F_129 ( F_252 ( V_119 , 0 ) , V_496 -> V_1157 ) ;
F_130 ( F_252 ( V_119 , 0 ) ) ;
}
static void F_752 ( struct V_37 * V_37 ,
struct V_495 * V_496 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_951 * V_952 =
F_209 ( V_37 -> V_40 . V_113 -> V_114 ) ;
struct V_302 * V_303 = V_952 -> V_303 ;
T_5 V_9 = F_90 ( V_37 -> V_171 ) ;
T_1 V_376 ;
V_376 = F_11 ( V_9 ) ;
if ( V_303 -> V_315 != V_317 )
V_376 |= V_383 ;
else
V_376 &= ~ V_383 ;
F_129 ( V_9 , V_376 ) ;
F_129 ( F_223 ( V_37 -> V_171 ) , V_496 -> V_1157 ) ;
F_130 ( F_223 ( V_37 -> V_171 ) ) ;
}
static void F_753 ( struct V_1195 * V_1196 )
{
struct V_37 * V_38 = V_1196 -> V_38 ;
struct V_495 * V_496 ;
F_275 ( & V_38 -> V_40 . V_16 -> V_457 ) ;
V_496 = V_38 -> V_458 ;
F_276 ( & V_38 -> V_40 . V_16 -> V_457 ) ;
if ( V_496 == NULL )
return;
F_733 ( V_496 ) ;
F_754 ( V_38 ) ;
if ( F_60 ( V_1196 -> V_757 ) -> V_127 >= 9 )
F_751 ( V_38 , V_1196 -> V_285 , V_496 ) ;
else
F_752 ( V_38 , V_496 ) ;
F_755 ( V_38 ) ;
}
static void F_756 ( struct V_1149 * V_496 )
{
struct V_1195 * V_1196 =
F_720 ( V_496 , struct V_1195 , V_496 ) ;
struct V_951 * V_952 =
F_209 ( V_1196 -> V_38 -> V_40 . V_113 -> V_114 ) ;
struct V_302 * V_303 = V_952 -> V_303 ;
if ( V_1196 -> V_1161 ) {
F_9 ( F_757 ( V_1196 -> V_1161 ,
V_1196 -> V_38 -> V_456 ,
false , NULL ,
& V_1196 -> V_757 -> V_570 . V_1197 ) ) ;
F_758 ( V_1196 -> V_1161 ) ;
}
if ( V_303 -> V_40 . V_1191 )
F_9 ( F_759 ( V_303 -> V_40 . V_1191 -> V_1192 ,
false , false ,
V_1198 ) < 0 ) ;
F_753 ( V_1196 ) ;
F_216 ( V_1196 ) ;
}
static int F_760 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_302 * V_303 )
{
struct V_1195 * V_1196 ;
V_1196 = F_761 ( sizeof( * V_1196 ) , V_746 ) ;
if ( V_1196 == NULL )
return - V_742 ;
V_1196 -> V_757 = F_204 ( V_16 ) ;
V_1196 -> V_1161 = F_762 ( V_303 -> V_1193 ) ;
V_1196 -> V_38 = F_50 ( V_38 ) ;
V_1196 -> V_285 = V_38 -> V_113 -> V_36 -> V_285 ;
F_763 ( & V_1196 -> V_496 , F_756 ) ;
F_764 ( & V_1196 -> V_496 ) ;
return 0 ;
}
static int F_765 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_276 * V_114 ,
struct V_302 * V_303 ,
struct V_1160 * V_1161 ,
T_2 V_355 )
{
return - V_1180 ;
}
static bool F_766 ( struct V_15 * V_16 ,
struct V_111 * V_38 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_495 * V_496 = V_37 -> V_458 ;
T_1 V_1199 ;
if ( F_282 ( & V_496 -> V_454 ) >= V_1153 )
return true ;
if ( F_282 ( & V_496 -> V_454 ) < V_1159 )
return false ;
if ( ! V_496 -> V_1200 )
return false ;
if ( V_496 -> V_1201 == 0 ) {
if ( V_496 -> V_1152 &&
! F_767 ( V_496 -> V_1152 , true ) )
return false ;
V_496 -> V_1201 = F_768 ( V_38 ) ;
}
if ( F_768 ( V_38 ) - V_496 -> V_1201 < 3 )
return false ;
if ( F_60 ( V_16 ) -> V_127 >= 4 )
V_1199 = F_769 ( F_11 ( F_223 ( V_37 -> V_171 ) ) ) ;
else
V_1199 = F_11 ( F_224 ( V_37 -> V_171 ) ) ;
return V_1199 == V_496 -> V_1157 ;
}
void F_770 ( struct V_15 * V_16 , int V_119 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_111 * V_38 = V_2 -> V_120 [ V_119 ] ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_495 * V_496 ;
F_9 ( ! F_771 () ) ;
if ( V_38 == NULL )
return;
F_772 ( & V_16 -> V_457 ) ;
V_496 = V_37 -> V_458 ;
if ( V_496 != NULL && F_766 ( V_16 , V_38 ) ) {
F_179 ( 1 , L_195 ,
V_496 -> V_1202 , F_773 ( V_16 , V_119 ) ) ;
F_308 ( V_37 ) ;
V_496 = NULL ;
}
if ( V_496 != NULL &&
F_773 ( V_16 , V_119 ) - V_496 -> V_1202 > 1 )
F_774 ( V_16 , V_496 -> V_1152 ) ;
F_775 ( & V_16 -> V_457 ) ;
}
static int F_776 ( struct V_111 * V_38 ,
struct V_276 * V_114 ,
struct V_1203 * V_497 ,
T_2 V_1204 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_276 * V_1151 = V_38 -> V_113 -> V_114 ;
struct V_302 * V_303 = F_190 ( V_114 ) ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_301 * V_113 = V_38 -> V_113 ;
enum V_119 V_119 = V_37 -> V_119 ;
struct V_495 * V_496 ;
struct V_1162 * V_1163 ;
bool V_1196 ;
struct V_1160 * V_1205 = NULL ;
int V_305 ;
if ( F_9 ( F_190 ( V_1151 ) == NULL ) )
return - V_311 ;
if ( V_114 -> V_265 != V_38 -> V_113 -> V_114 -> V_265 )
return - V_307 ;
if ( F_60 ( V_16 ) -> V_127 > 3 &&
( V_114 -> V_290 [ 0 ] != V_38 -> V_113 -> V_114 -> V_290 [ 0 ] ||
V_114 -> V_288 [ 0 ] != V_38 -> V_113 -> V_114 -> V_288 [ 0 ] ) )
return - V_307 ;
if ( F_777 ( & V_2 -> V_455 ) )
goto V_1206;
V_496 = F_499 ( sizeof( * V_496 ) , V_746 ) ;
if ( V_496 == NULL )
return - V_742 ;
V_496 -> V_497 = V_497 ;
V_496 -> V_38 = V_38 ;
V_496 -> V_1151 = V_1151 ;
F_763 ( & V_496 -> V_496 , F_719 ) ;
V_305 = F_103 ( V_38 ) ;
if ( V_305 )
goto V_1207;
F_275 ( & V_16 -> V_457 ) ;
if ( V_37 -> V_458 ) {
if ( F_766 ( V_16 , V_38 ) ) {
F_16 ( L_196 ) ;
F_308 ( V_37 ) ;
} else {
F_16 ( L_197 ) ;
F_276 ( & V_16 -> V_457 ) ;
F_104 ( V_38 ) ;
F_216 ( V_496 ) ;
return - V_311 ;
}
}
V_37 -> V_458 = V_496 ;
F_276 ( & V_16 -> V_457 ) ;
if ( F_282 ( & V_37 -> V_494 ) >= 2 )
F_778 ( V_2 -> V_499 ) ;
F_213 ( V_496 -> V_1151 ) ;
F_779 ( & V_303 -> V_40 ) ;
V_38 -> V_113 -> V_114 = V_114 ;
F_211 ( V_38 -> V_113 ) ;
V_496 -> V_500 = V_303 ;
V_305 = F_684 ( V_16 ) ;
if ( V_305 )
goto V_1208;
F_780 ( & V_37 -> V_494 ) ;
V_37 -> V_456 = F_282 ( & V_2 -> V_455 . V_456 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 5 || F_31 ( V_16 ) )
V_496 -> V_1158 = F_11 ( F_731 ( V_119 ) ) + 1 ;
if ( F_13 ( V_16 ) || F_14 ( V_16 ) ) {
V_1163 = & V_2 -> V_1163 [ V_1209 ] ;
if ( V_303 -> V_315 != F_190 ( V_496 -> V_1151 ) -> V_315 )
V_1163 = NULL ;
} else if ( F_291 ( V_16 ) || F_235 ( V_16 ) ) {
V_1163 = & V_2 -> V_1163 [ V_1209 ] ;
} else if ( F_60 ( V_16 ) -> V_127 >= 7 ) {
V_1163 = F_750 ( V_303 -> V_1193 ) ;
if ( V_1163 == NULL || V_1163 -> V_241 != V_1181 )
V_1163 = & V_2 -> V_1163 [ V_1209 ] ;
} else {
V_1163 = & V_2 -> V_1163 [ V_1181 ] ;
}
V_1196 = F_748 ( V_1163 , V_303 ) ;
if ( ! V_1196 ) {
V_305 = F_781 ( V_303 , V_1163 , & V_1205 ) ;
if ( V_305 )
goto V_1210;
}
V_305 = F_189 ( V_38 -> V_113 , V_114 ,
V_38 -> V_113 -> V_36 ) ;
if ( V_305 )
goto V_1210;
V_496 -> V_1157 = F_239 ( F_215 ( V_113 ) ,
V_303 , 0 ) ;
V_496 -> V_1157 += V_37 -> V_385 ;
if ( V_1196 ) {
V_305 = F_760 ( V_16 , V_38 , V_303 ) ;
if ( V_305 )
goto V_1211;
F_721 ( & V_496 -> V_1152 ,
V_303 -> V_1193 ) ;
} else {
if ( ! V_1205 ) {
V_305 = F_782 ( V_1163 , V_1163 -> V_1212 , & V_1205 ) ;
if ( V_305 )
goto V_1211;
}
V_305 = V_2 -> V_449 . V_1213 ( V_16 , V_38 , V_114 , V_303 , V_1205 ,
V_1204 ) ;
if ( V_305 )
goto V_1211;
F_721 ( & V_496 -> V_1152 , V_1205 ) ;
}
if ( V_1205 )
F_783 ( V_1205 ) ;
V_496 -> V_1202 = F_768 ( V_38 ) ;
V_496 -> V_1200 = true ;
F_784 ( F_190 ( V_496 -> V_1151 ) , V_303 ,
F_215 ( V_113 ) -> V_374 ) ;
F_4 ( & V_16 -> V_306 ) ;
F_385 ( V_37 ) ;
F_785 ( V_16 ,
F_215 ( V_113 ) -> V_374 ) ;
F_786 ( V_37 -> V_171 , V_303 ) ;
return 0 ;
V_1211:
F_198 ( V_114 , V_38 -> V_113 -> V_36 ) ;
V_1210:
if ( V_1205 )
F_787 ( V_1205 ) ;
F_723 ( & V_37 -> V_494 ) ;
F_4 ( & V_16 -> V_306 ) ;
V_1208:
V_38 -> V_113 -> V_114 = V_1151 ;
F_211 ( V_38 -> V_113 ) ;
F_691 ( & V_303 -> V_40 ) ;
F_212 ( V_496 -> V_1151 ) ;
F_275 ( & V_16 -> V_457 ) ;
V_37 -> V_458 = NULL ;
F_276 ( & V_16 -> V_457 ) ;
F_104 ( V_38 ) ;
V_1207:
F_216 ( V_496 ) ;
if ( V_305 == - V_1214 ) {
struct V_45 * V_36 ;
struct V_277 * V_278 ;
V_1206:
V_36 = F_488 ( V_16 ) ;
if ( ! V_36 )
return - V_742 ;
V_36 -> V_740 = F_788 ( V_38 ) ;
V_479:
V_278 = F_695 ( V_36 , V_113 ) ;
V_305 = F_490 ( V_278 ) ;
if ( ! V_305 ) {
F_698 ( V_278 , V_114 ) ;
V_305 = F_697 ( V_278 , V_38 ) ;
if ( ! V_305 )
V_305 = F_491 ( V_36 ) ;
}
if ( V_305 == - V_310 ) {
F_704 ( V_36 -> V_740 ) ;
F_789 ( V_36 ) ;
goto V_479;
}
if ( V_305 )
F_492 ( V_36 ) ;
if ( V_305 == 0 && V_497 ) {
F_275 ( & V_16 -> V_457 ) ;
F_310 ( V_16 , V_119 , V_497 ) ;
F_276 ( & V_16 -> V_457 ) ;
}
}
return V_305 ;
}
static bool F_790 ( struct V_301 * V_171 ,
struct V_277 * V_36 )
{
struct V_431 * V_1215 = F_219 ( V_36 ) ;
struct V_431 * V_1216 = F_219 ( V_171 -> V_36 ) ;
if ( V_1215 -> V_361 != V_1216 -> V_361 )
return true ;
if ( ! V_1216 -> V_40 . V_114 || ! V_1215 -> V_40 . V_114 )
return false ;
if ( V_1216 -> V_40 . V_114 -> V_292 [ 0 ] != V_1215 -> V_40 . V_114 -> V_292 [ 0 ] ||
V_1216 -> V_40 . V_285 != V_1215 -> V_40 . V_285 ||
F_253 ( & V_1215 -> V_440 ) != F_253 ( & V_1216 -> V_440 ) ||
F_254 ( & V_1215 -> V_440 ) != F_254 ( & V_1216 -> V_440 ) ||
F_253 ( & V_1215 -> V_442 ) != F_253 ( & V_1216 -> V_442 ) ||
F_254 ( & V_1215 -> V_442 ) != F_254 ( & V_1216 -> V_442 ) )
return true ;
return false ;
}
static bool F_791 ( struct V_431 * V_36 )
{
int V_366 = F_253 ( & V_36 -> V_440 ) >> 16 ;
int V_367 = F_254 ( & V_36 -> V_440 ) >> 16 ;
int V_434 = F_253 ( & V_36 -> V_442 ) ;
int V_435 = F_254 ( & V_36 -> V_442 ) ;
return ( V_366 != V_434 || V_367 != V_435 ) ;
}
int F_792 ( struct V_35 * V_44 ,
struct V_277 * V_278 )
{
struct V_43 * V_212 = F_284 ( V_44 ) ;
struct V_111 * V_38 = V_44 -> V_38 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_301 * V_171 = V_278 -> V_171 ;
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_431 * V_1217 =
F_219 ( V_171 -> V_36 ) ;
int V_991 = V_37 -> V_40 . V_40 . V_241 , V_305 ;
int V_50 = F_220 ( V_171 ) ;
bool V_1218 = F_19 ( V_44 ) ;
bool V_1219 = V_38 -> V_36 -> V_112 ;
bool V_1220 = V_44 -> V_112 ;
bool V_1221 , V_1222 , V_361 , V_1223 ;
struct V_276 * V_114 = V_278 -> V_114 ;
if ( V_44 && F_60 ( V_16 ) -> V_127 >= 9 &&
V_171 -> type != V_1224 ) {
V_305 = F_359 (
F_284 ( V_44 ) ,
F_219 ( V_278 ) ) ;
if ( V_305 )
return V_305 ;
}
V_1223 = V_1217 -> V_361 ;
V_361 = F_219 ( V_278 ) -> V_361 ;
if ( ! V_1219 && F_9 ( V_1223 ) )
V_1223 = false ;
if ( ! V_1220 && F_9 ( V_361 ) )
V_361 = false ;
if ( ! V_1223 && ! V_361 )
return 0 ;
V_1221 = V_1223 && ( ! V_361 || V_1218 ) ;
V_1222 = V_361 && ( ! V_1223 || V_1218 ) ;
F_793 ( L_198 , V_991 ,
V_171 -> V_40 . V_241 , V_114 ? V_114 -> V_40 . V_241 : - 1 ) ;
F_793 ( L_199 ,
V_171 -> V_40 . V_241 , V_1223 , V_361 ,
V_1221 , V_1222 , V_1218 ) ;
if ( V_1222 || V_1221 ) {
V_212 -> V_593 = true ;
if ( V_171 -> type != V_1224 ) {
if ( V_1220 )
V_37 -> V_589 . V_590 = true ;
V_212 -> V_599 = true ;
}
} else if ( F_790 ( V_171 , V_278 ) ) {
V_212 -> V_593 = true ;
}
if ( V_361 || V_1223 )
V_37 -> V_589 . V_591 |=
F_215 ( V_171 ) -> V_374 ;
switch ( V_171 -> type ) {
case V_1225 :
V_37 -> V_589 . V_598 = V_1221 ;
V_37 -> V_589 . V_595 = V_1222 ;
if ( V_1221 ) {
V_37 -> V_589 . V_597 = true ;
V_37 -> V_589 . V_596 = true ;
}
if ( V_361 &&
F_60 ( V_16 ) -> V_127 <= 4 && ! F_31 ( V_16 ) &&
V_2 -> V_447 . V_38 == V_37 &&
V_278 -> V_285 != F_230 ( V_418 ) )
V_37 -> V_589 . V_596 = true ;
if ( V_1222 && F_236 ( V_16 ) )
V_37 -> V_589 . V_590 = true ;
V_37 -> V_589 . V_594 |= V_361 || V_1218 ;
break;
case V_1224 :
break;
case V_1226 :
if ( F_291 ( V_16 ) &&
F_791 ( F_219 ( V_278 ) ) &&
! F_791 ( V_1217 ) ) {
F_284 ( V_44 ) -> V_1227 = true ;
} else if ( V_1221 && ! V_1218 ) {
V_37 -> V_589 . V_590 = true ;
V_37 -> V_589 . V_1228 |=
1 << V_50 ;
}
break;
}
return 0 ;
}
static bool F_794 ( const struct V_41 * V_1155 ,
const struct V_41 * V_1156 )
{
return V_1155 == V_1156 || ( V_1155 -> V_1229 & ( 1 << V_1156 -> type ) &&
V_1156 -> V_1229 & ( 1 << V_1155 -> type ) ) ;
}
static bool F_795 ( struct V_45 * V_36 ,
struct V_37 * V_38 ,
struct V_41 * V_42 )
{
struct V_41 * V_1230 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_50 ;
F_24 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != & V_38 -> V_40 )
continue;
V_1230 =
F_25 ( V_49 -> V_52 ) ;
if ( ! F_794 ( V_42 , V_1230 ) )
return false ;
}
return true ;
}
static bool F_796 ( struct V_45 * V_36 ,
struct V_37 * V_38 )
{
struct V_41 * V_42 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_50 ;
F_24 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != & V_38 -> V_40 )
continue;
V_42 = F_25 ( V_49 -> V_52 ) ;
if ( ! F_795 ( V_36 , V_38 , V_42 ) )
return false ;
}
return true ;
}
static int F_797 ( struct V_111 * V_38 ,
struct V_35 * V_44 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_43 * V_212 =
F_284 ( V_44 ) ;
struct V_45 * V_36 = V_44 -> V_36 ;
int V_305 ;
bool V_1218 = F_19 ( V_44 ) ;
if ( V_1218 && ! F_796 ( V_36 , V_37 ) ) {
F_153 ( L_200 ) ;
return - V_307 ;
}
if ( V_1218 && ! V_44 -> V_112 )
V_212 -> V_593 = true ;
if ( V_1218 && V_44 -> V_243 &&
V_2 -> V_449 . V_1231 &&
! F_9 ( V_212 -> V_135 != V_959 ) ) {
V_305 = V_2 -> V_449 . V_1231 ( V_37 ,
V_212 ) ;
if ( V_305 )
return V_305 ;
}
V_305 = 0 ;
if ( V_2 -> V_449 . V_1232 ) {
V_305 = V_2 -> V_449 . V_1232 ( V_37 , V_36 ) ;
if ( V_305 )
return V_305 ;
}
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
if ( V_1218 )
V_305 = F_358 ( V_212 ) ;
if ( ! V_305 )
V_305 = F_798 ( V_16 , V_37 ,
V_212 ) ;
}
return V_305 ;
}
static void F_799 ( struct V_15 * V_16 )
{
struct V_744 * V_47 ;
F_800 (dev, connector) {
if ( V_47 -> V_40 . V_42 ) {
V_47 -> V_40 . V_36 -> V_52 =
V_47 -> V_40 . V_42 ;
V_47 -> V_40 . V_36 -> V_38 =
V_47 -> V_40 . V_42 -> V_38 ;
} else {
V_47 -> V_40 . V_36 -> V_52 = NULL ;
V_47 -> V_40 . V_36 -> V_38 = NULL ;
}
}
}
static void
F_801 ( struct V_744 * V_47 ,
struct V_43 * V_212 )
{
int V_1010 = V_212 -> V_754 ;
F_153 ( L_201 ,
V_47 -> V_40 . V_40 . V_241 ,
V_47 -> V_40 . V_8 ) ;
if ( V_47 -> V_40 . V_1233 . V_534 &&
V_47 -> V_40 . V_1233 . V_534 * 3 < V_1010 ) {
F_153 ( L_202 ,
V_1010 , V_47 -> V_40 . V_1233 . V_534 * 3 ) ;
V_212 -> V_754 = V_47 -> V_40 . V_1233 . V_534 * 3 ;
}
if ( V_47 -> V_40 . V_1233 . V_534 == 0 ) {
int type = V_47 -> V_40 . V_1234 ;
int V_1235 = 24 ;
if ( type == V_1236 ||
type == V_1237 )
V_1235 = 18 ;
if ( V_1010 > V_1235 ) {
F_153 ( L_203 ,
V_1010 , V_1235 ) ;
V_212 -> V_754 = V_1235 ;
}
}
}
static int
F_802 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_45 * V_36 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_1010 , V_50 ;
if ( ( F_31 ( V_16 ) || F_13 ( V_16 ) || F_14 ( V_16 ) ) )
V_1010 = 10 * 3 ;
else if ( F_60 ( V_16 ) -> V_127 >= 5 )
V_1010 = 12 * 3 ;
else
V_1010 = 8 * 3 ;
V_212 -> V_754 = V_1010 ;
V_36 = V_212 -> V_40 . V_36 ;
F_24 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != & V_38 -> V_40 )
continue;
F_801 ( F_803 ( V_47 ) ,
V_212 ) ;
}
return V_1010 ;
}
static void F_804 ( const struct V_533 * V_445 )
{
F_153 ( L_204
L_205 ,
V_445 -> V_117 ,
V_445 -> V_561 , V_445 -> V_760 ,
V_445 -> V_915 , V_445 -> V_912 ,
V_445 -> V_562 , V_445 -> V_917 ,
V_445 -> V_918 , V_445 -> V_908 , V_445 -> type , V_445 -> V_355 ) ;
}
static void F_805 ( struct V_37 * V_38 ,
struct V_43 * V_212 ,
const char * V_1238 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_301 * V_171 ;
struct V_359 * V_359 ;
struct V_431 * V_36 ;
struct V_276 * V_114 ;
F_153 ( L_206 , V_38 -> V_40 . V_40 . V_241 ,
V_1238 , V_212 , F_80 ( V_38 -> V_119 ) ) ;
F_153 ( L_207 , F_806 ( V_212 -> V_121 ) ) ;
F_153 ( L_208 ,
V_212 -> V_754 , V_212 -> V_931 ) ;
F_153 ( L_209 ,
V_212 -> V_261 ,
V_212 -> V_474 ,
V_212 -> V_601 . V_824 , V_212 -> V_601 . V_825 ,
V_212 -> V_601 . V_826 , V_212 -> V_601 . V_827 ,
V_212 -> V_601 . V_823 ) ;
F_153 ( L_210 ,
V_212 -> V_532 ,
V_212 -> V_1239 ,
V_212 -> V_842 . V_824 , V_212 -> V_842 . V_825 ,
V_212 -> V_842 . V_826 , V_212 -> V_842 . V_827 ,
V_212 -> V_842 . V_823 ) ;
F_153 ( L_211 ,
V_212 -> V_532 ,
V_212 -> V_1239 ,
V_212 -> V_843 . V_824 ,
V_212 -> V_843 . V_825 ,
V_212 -> V_843 . V_826 ,
V_212 -> V_843 . V_827 ,
V_212 -> V_843 . V_823 ) ;
F_153 ( L_212 ,
V_212 -> V_1240 ,
V_212 -> V_1241 ) ;
F_153 ( L_213 ) ;
F_807 ( & V_212 -> V_40 . V_445 ) ;
F_153 ( L_214 ) ;
F_807 ( & V_212 -> V_40 . V_116 ) ;
F_804 ( & V_212 -> V_40 . V_116 ) ;
F_153 ( L_215 , V_212 -> V_866 ) ;
F_153 ( L_216 ,
V_212 -> V_381 , V_212 -> V_380 ) ;
F_153 ( L_217 ,
V_38 -> V_400 ,
V_212 -> V_399 . V_551 ,
V_212 -> V_399 . V_436 ) ;
F_153 ( L_218 ,
V_212 -> V_611 . V_612 ,
V_212 -> V_611 . V_616 ,
V_212 -> V_611 . V_947 ) ;
F_153 ( L_219 ,
V_212 -> V_460 . V_566 ,
V_212 -> V_460 . V_296 ,
V_212 -> V_460 . V_129 ? L_220 : L_221 ) ;
F_153 ( L_222 , V_212 -> V_569 ) ;
F_153 ( L_223 , V_212 -> V_262 ) ;
if ( F_30 ( V_16 ) ) {
F_153 ( L_224
L_225
L_226 ,
V_212 -> V_1063 ,
V_212 -> V_213 . V_1242 ,
V_212 -> V_213 . V_1243 ,
V_212 -> V_213 . V_1244 ,
V_212 -> V_213 . V_1245 ,
V_212 -> V_213 . V_1246 ,
V_212 -> V_213 . V_1247 ,
V_212 -> V_213 . V_1248 ,
V_212 -> V_213 . V_1249 ,
V_212 -> V_213 . V_1250 ,
V_212 -> V_213 . V_1251 ,
V_212 -> V_213 . V_1252 ) ;
} else if ( F_431 ( V_16 ) || F_432 ( V_16 ) ) {
F_153 ( L_227
L_228 ,
V_212 -> V_1063 ,
V_212 -> V_213 . V_1071 ,
V_212 -> V_213 . V_1253 ,
V_212 -> V_213 . V_1254 ) ;
} else if ( F_71 ( V_16 ) ) {
F_153 ( L_229 ,
V_212 -> V_1063 ,
V_212 -> V_213 . V_1255 ,
V_212 -> V_213 . V_1256 ) ;
} else {
F_153 ( L_230
L_231 ,
V_212 -> V_213 . V_87 ,
V_212 -> V_213 . V_215 ,
V_212 -> V_213 . V_732 ,
V_212 -> V_213 . V_733 ) ;
}
F_153 ( L_232 ) ;
F_808 (plane, &dev->mode_config.plane_list, head) {
V_359 = F_215 ( V_171 ) ;
if ( V_359 -> V_119 != V_38 -> V_119 )
continue;
V_36 = F_219 ( V_171 -> V_36 ) ;
V_114 = V_36 -> V_40 . V_114 ;
if ( ! V_114 ) {
F_153 ( L_233
L_234 ,
V_171 -> type == V_1224 ? L_235 : L_236 ,
V_171 -> V_40 . V_241 , V_359 -> V_119 ,
( V_38 -> V_40 . V_113 == V_171 ) ? 0 : V_359 -> V_171 + 1 ,
F_220 ( V_171 ) , V_36 -> V_436 ) ;
continue;
}
F_153 ( L_237 ,
V_171 -> type == V_1224 ? L_235 : L_236 ,
V_171 -> V_40 . V_241 , V_359 -> V_119 ,
V_38 -> V_40 . V_113 == V_171 ? 0 : V_359 -> V_171 + 1 ,
F_220 ( V_171 ) ) ;
F_153 ( L_238 ,
V_114 -> V_40 . V_241 , V_114 -> V_354 , V_114 -> V_273 , V_114 -> V_265 ) ;
F_153 ( L_239 ,
V_36 -> V_436 ,
V_36 -> V_440 . V_441 >> 16 , V_36 -> V_440 . y1 >> 16 ,
F_253 ( & V_36 -> V_440 ) >> 16 ,
F_254 ( & V_36 -> V_440 ) >> 16 ,
V_36 -> V_442 . V_441 , V_36 -> V_442 . y1 ,
F_253 ( & V_36 -> V_442 ) , F_254 ( & V_36 -> V_442 ) ) ;
}
}
static bool F_809 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_46 * V_47 ;
unsigned int V_1257 = 0 ;
F_810 (connector, dev) {
struct V_48 * V_49 ;
struct V_41 * V_42 ;
V_49 = F_811 ( V_36 , V_47 ) ;
if ( ! V_49 )
V_49 = V_47 -> V_36 ;
if ( ! V_49 -> V_52 )
continue;
V_42 = F_25 ( V_49 -> V_52 ) ;
F_9 ( ! V_49 -> V_38 ) ;
switch ( V_42 -> type ) {
unsigned int V_229 ;
case V_629 :
if ( F_9 ( ! F_71 ( V_16 ) ) )
break;
case V_525 :
case V_63 :
case V_526 :
V_229 = 1 << F_343 ( & V_42 -> V_40 ) -> V_217 ;
if ( V_1257 & V_229 )
return false ;
V_1257 |= V_229 ;
default:
break;
}
}
return true ;
}
static void
F_812 ( struct V_43 * V_44 )
{
struct V_35 V_1258 ;
struct V_398 V_399 ;
struct V_138 V_213 ;
enum V_543 V_135 ;
T_2 V_1063 ;
bool V_635 ;
V_1258 = V_44 -> V_40 ;
V_399 = V_44 -> V_399 ;
V_135 = V_44 -> V_135 ;
V_213 = V_44 -> V_213 ;
V_1063 = V_44 -> V_1063 ;
V_635 = V_44 -> V_460 . V_635 ;
memset ( V_44 , 0 , sizeof *V_44 ) ;
V_44 -> V_40 = V_1258 ;
V_44 -> V_399 = V_399 ;
V_44 -> V_135 = V_135 ;
V_44 -> V_213 = V_213 ;
V_44 -> V_1063 = V_1063 ;
V_44 -> V_460 . V_635 = V_635 ;
}
static int
F_813 ( struct V_111 * V_38 ,
struct V_43 * V_212 )
{
struct V_45 * V_36 = V_212 -> V_40 . V_36 ;
struct V_41 * V_42 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_1259 , V_305 = - V_307 ;
int V_50 ;
bool V_479 = true ;
F_812 ( V_212 ) ;
V_212 -> V_121 =
(enum V_118 ) F_50 ( V_38 ) -> V_119 ;
if ( ! ( V_212 -> V_40 . V_116 . V_355 &
( V_538 | V_1260 ) ) )
V_212 -> V_40 . V_116 . V_355 |= V_1260 ;
if ( ! ( V_212 -> V_40 . V_116 . V_355 &
( V_540 | V_1261 ) ) )
V_212 -> V_40 . V_116 . V_355 |= V_1261 ;
V_1259 = F_802 ( F_50 ( V_38 ) ,
V_212 ) ;
if ( V_1259 < 0 )
goto V_811;
F_696 ( & V_212 -> V_40 . V_445 ,
& V_212 -> V_381 ,
& V_212 -> V_380 ) ;
V_1262:
V_212 -> V_866 = 0 ;
V_212 -> V_605 = 1 ;
F_814 ( & V_212 -> V_40 . V_116 ,
V_1263 ) ;
F_24 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != V_38 )
continue;
V_42 = F_25 ( V_49 -> V_52 ) ;
if ( ! ( V_42 -> V_1264 ( V_42 , V_212 ) ) ) {
F_153 ( L_240 ) ;
goto V_811;
}
}
if ( ! V_212 -> V_866 )
V_212 -> V_866 = V_212 -> V_40 . V_116 . V_117
* V_212 -> V_605 ;
V_305 = F_514 ( F_50 ( V_38 ) , V_212 ) ;
if ( V_305 < 0 ) {
F_153 ( L_241 ) ;
goto V_811;
}
if ( V_305 == V_756 ) {
if ( F_6 ( ! V_479 , L_242 ) ) {
V_305 = - V_307 ;
goto V_811;
}
F_153 ( L_243 ) ;
V_479 = false ;
goto V_1262;
}
V_212 -> V_931 = V_212 -> V_754 == 6 * 3 ;
F_153 ( L_244 ,
V_1259 , V_212 -> V_754 , V_212 -> V_931 ) ;
V_811:
return V_305 ;
}
static void
F_815 ( struct V_45 * V_36 )
{
struct V_111 * V_38 ;
struct V_35 * V_44 ;
int V_50 ;
F_428 (state, crtc, crtc_state, i) {
F_50 ( V_38 ) -> V_115 = F_284 ( V_38 -> V_36 ) ;
if ( V_38 -> V_36 -> V_112 )
V_38 -> V_1265 = V_38 -> V_36 -> V_116 ;
else
V_38 -> V_1265 . V_117 = 0 ;
if ( F_816 ( V_36 , V_38 -> V_113 ) ) {
struct V_277 * V_278 = V_38 -> V_113 -> V_36 ;
V_38 -> V_113 -> V_114 = V_278 -> V_114 ;
V_38 -> V_313 = V_278 -> V_364 >> 16 ;
V_38 -> V_314 = V_278 -> V_365 >> 16 ;
}
}
}
static bool F_817 ( int V_1266 , int V_1267 )
{
int V_1268 ;
if ( V_1266 == V_1267 )
return true ;
if ( ! V_1266 || ! V_1267 )
return false ;
V_1268 = abs ( V_1266 - V_1267 ) ;
if ( ( ( ( ( V_1268 + V_1266 + V_1267 ) * 100 ) ) / ( V_1266 + V_1267 ) ) < 105 )
return true ;
return false ;
}
static bool
F_818 ( unsigned int V_79 , unsigned int V_84 ,
unsigned int V_80 , unsigned int V_1269 ,
bool V_1270 )
{
if ( V_79 == V_80 && V_84 == V_1269 )
return true ;
if ( V_1270 || ! V_79 || ! V_84 || ! V_80 || ! V_1269 )
return false ;
F_819 ( V_815 > V_109 ) ;
if ( V_79 > V_80 ) {
while ( V_79 > V_80 ) {
V_80 <<= 1 ;
V_1269 <<= 1 ;
}
} else if ( V_79 < V_80 ) {
while ( V_79 < V_80 ) {
V_79 <<= 1 ;
V_84 <<= 1 ;
}
}
return V_79 == V_80 && V_84 == V_1269 ;
}
static bool
F_820 ( const struct V_821 * V_822 ,
struct V_821 * V_839 ,
bool V_1271 )
{
if ( V_822 -> V_823 == V_839 -> V_823 &&
F_818 ( V_822 -> V_824 , V_822 -> V_825 ,
V_839 -> V_824 , V_839 -> V_825 , ! V_1271 ) &&
F_818 ( V_822 -> V_826 , V_822 -> V_827 ,
V_839 -> V_826 , V_839 -> V_827 , ! V_1271 ) ) {
if ( V_1271 )
* V_839 = * V_822 ;
return true ;
}
return false ;
}
static bool
F_821 ( struct V_15 * V_16 ,
struct V_43 * V_1272 ,
struct V_43 * V_212 ,
bool V_1271 )
{
bool V_305 = true ;
#define F_822 ( T_10 , ... ) \
do { \
if (!adjust) \
DRM_ERROR(fmt, ##__VA_ARGS__); \
else \
DRM_DEBUG_KMS(fmt, ##__VA_ARGS__); \
} while (0)
#define F_823 ( V_8 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_824 ( V_8 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_825 ( V_8 ) \
if (!intel_compare_link_m_n(&current_config->name, \
&pipe_config->name,\
adjust)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected tu %i gmch %i/%i link %i/%i, " \
"found tu %i, gmch %i/%i link %i/%i)\n", \
current_config->name.tu, \
current_config->name.gmch_m, \
current_config->name.gmch_n, \
current_config->name.link_m, \
current_config->name.link_n, \
pipe_config->name.tu, \
pipe_config->name.gmch_m, \
pipe_config->name.gmch_n, \
pipe_config->name.link_m, \
pipe_config->name.link_n); \
ret = false; \
}
#define F_826 ( V_8 , T_11 ) \
if (!intel_compare_link_m_n(&current_config->name, \
&pipe_config->name, adjust) && \
!intel_compare_link_m_n(&current_config->alt_name, \
&pipe_config->name, adjust)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected tu %i gmch %i/%i link %i/%i, " \
"or tu %i gmch %i/%i link %i/%i, " \
"found tu %i, gmch %i/%i link %i/%i)\n", \
current_config->name.tu, \
current_config->name.gmch_m, \
current_config->name.gmch_n, \
current_config->name.link_m, \
current_config->name.link_n, \
current_config->alt_name.tu, \
current_config->alt_name.gmch_m, \
current_config->alt_name.gmch_n, \
current_config->alt_name.link_m, \
current_config->alt_name.link_n, \
pipe_config->name.tu, \
pipe_config->name.gmch_m, \
pipe_config->name.gmch_n, \
pipe_config->name.link_m, \
pipe_config->name.link_n); \
ret = false; \
}
#define F_827 ( V_8 , T_11 ) \
if ((current_config->name != pipe_config->name) && \
(current_config->alt_name != pipe_config->name)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i or %i, found %i)\n", \
current_config->name, \
current_config->alt_name, \
pipe_config->name); \
ret = false; \
}
#define F_828 ( V_8 , V_634 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
ret = false; \
}
#define F_829 ( V_8 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_830 ( T_12 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_824 ( V_121 ) ;
F_824 ( V_261 ) ;
F_824 ( V_474 ) ;
F_825 ( V_601 ) ;
F_824 ( V_532 ) ;
F_824 ( V_1239 ) ;
if ( F_60 ( V_16 ) -> V_127 < 8 ) {
F_825 ( V_842 ) ;
if ( V_1272 -> V_840 )
F_825 ( V_843 ) ;
} else
F_826 ( V_842 , V_843 ) ;
F_824 ( V_260 ) ;
F_824 ( V_40 . V_116 . V_561 ) ;
F_824 ( V_40 . V_116 . V_912 ) ;
F_824 ( V_40 . V_116 . V_913 ) ;
F_824 ( V_40 . V_116 . V_914 ) ;
F_824 ( V_40 . V_116 . V_760 ) ;
F_824 ( V_40 . V_116 . V_915 ) ;
F_824 ( V_40 . V_116 . V_562 ) ;
F_824 ( V_40 . V_116 . V_908 ) ;
F_824 ( V_40 . V_116 . V_916 ) ;
F_824 ( V_40 . V_116 . V_909 ) ;
F_824 ( V_40 . V_116 . V_917 ) ;
F_824 ( V_40 . V_116 . V_918 ) ;
F_824 ( V_605 ) ;
F_824 ( V_1273 ) ;
if ( ( F_60 ( V_16 ) -> V_127 < 8 && ! F_235 ( V_16 ) ) ||
F_13 ( V_16 ) || F_14 ( V_16 ) )
F_824 ( V_940 ) ;
F_824 ( V_1241 ) ;
F_824 ( V_1240 ) ;
F_828 ( V_40 . V_116 . V_355 ,
V_911 ) ;
if ( ! F_830 ( V_1274 ) ) {
F_828 ( V_40 . V_116 . V_355 ,
V_538 ) ;
F_828 ( V_40 . V_116 . V_355 ,
V_1260 ) ;
F_828 ( V_40 . V_116 . V_355 ,
V_540 ) ;
F_828 ( V_40 . V_116 . V_355 ,
V_1261 ) ;
}
F_823 ( V_611 . V_612 ) ;
if ( F_60 ( V_16 ) -> V_127 < 4 )
F_824 ( V_611 . V_616 ) ;
F_823 ( V_611 . V_947 ) ;
if ( ! V_1271 ) {
F_824 ( V_381 ) ;
F_824 ( V_380 ) ;
F_824 ( V_460 . V_129 ) ;
if ( V_1272 -> V_460 . V_129 ) {
F_823 ( V_460 . V_566 ) ;
F_823 ( V_460 . V_296 ) ;
}
F_824 ( V_399 . V_436 ) ;
}
if ( F_235 ( V_16 ) )
F_824 ( V_569 ) ;
F_824 ( V_262 ) ;
F_823 ( V_1063 ) ;
F_824 ( V_135 ) ;
F_823 ( V_213 . V_87 ) ;
F_823 ( V_213 . V_215 ) ;
F_823 ( V_213 . V_732 ) ;
F_823 ( V_213 . V_733 ) ;
F_823 ( V_213 . V_1255 ) ;
F_823 ( V_213 . V_1256 ) ;
F_823 ( V_213 . V_1071 ) ;
F_823 ( V_213 . V_1253 ) ;
F_823 ( V_213 . V_1254 ) ;
if ( F_31 ( V_16 ) || F_60 ( V_16 ) -> V_127 >= 5 )
F_824 ( V_754 ) ;
F_829 ( V_40 . V_116 . V_117 ) ;
F_829 ( V_866 ) ;
#undef F_823
#undef F_824
#undef F_827
#undef F_828
#undef F_829
#undef F_830
#undef F_822
return V_305 ;
}
static void F_831 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_1275 V_1276 , * V_1277 ;
struct V_37 * V_37 ;
int V_171 ;
if ( F_60 ( V_16 ) -> V_127 < 9 )
return;
F_832 ( V_2 , & V_1276 ) ;
V_1277 = & V_2 -> V_585 . V_1278 . V_1279 ;
F_140 (dev, intel_crtc) {
struct V_1280 * V_1281 , * V_1282 ;
const enum V_119 V_119 = V_37 -> V_119 ;
if ( ! V_37 -> V_112 )
continue;
F_833 (dev_priv, pipe, plane) {
V_1281 = & V_1276 . V_171 [ V_119 ] [ V_171 ] ;
V_1282 = & V_1277 -> V_171 [ V_119 ] [ V_171 ] ;
if ( F_834 ( V_1281 , V_1282 ) )
continue;
F_132 ( L_245
L_246 ,
F_80 ( V_119 ) , V_171 + 1 ,
V_1282 -> V_395 , V_1282 -> V_1110 ,
V_1281 -> V_395 , V_1281 -> V_1110 ) ;
}
V_1281 = & V_1276 . V_171 [ V_119 ] [ V_1283 ] ;
V_1282 = & V_1277 -> V_171 [ V_119 ] [ V_1283 ] ;
if ( F_834 ( V_1281 , V_1282 ) )
continue;
F_132 ( L_247
L_246 ,
F_80 ( V_119 ) ,
V_1282 -> V_395 , V_1282 -> V_1110 ,
V_1281 -> V_395 , V_1281 -> V_1110 ) ;
}
}
static void
F_835 ( struct V_15 * V_16 ,
struct V_45 * V_727 )
{
struct V_48 * V_1284 ;
struct V_46 * V_47 ;
int V_50 ;
F_24 (old_state, connector, old_conn_state, i) {
struct V_743 * V_42 = V_47 -> V_42 ;
struct V_48 * V_36 = V_47 -> V_36 ;
F_495 ( F_803 ( V_47 ) ) ;
F_66 ( V_36 -> V_52 != V_42 ,
L_248 ) ;
}
}
static void
F_836 ( struct V_15 * V_16 )
{
struct V_41 * V_42 ;
struct V_744 * V_47 ;
F_602 (dev, encoder) {
bool V_129 = false ;
enum V_119 V_119 ;
F_153 ( L_249 ,
V_42 -> V_40 . V_40 . V_241 ,
V_42 -> V_40 . V_8 ) ;
F_800 (dev, connector) {
if ( V_47 -> V_40 . V_36 -> V_52 != & V_42 -> V_40 )
continue;
V_129 = true ;
F_66 ( V_47 -> V_40 . V_36 -> V_38 !=
V_42 -> V_40 . V_38 ,
L_250 ) ;
}
F_66 ( ! ! V_42 -> V_40 . V_38 != V_129 ,
L_251
L_252 ,
! ! V_42 -> V_40 . V_38 , V_129 ) ;
if ( ! V_42 -> V_40 . V_38 ) {
bool V_112 ;
V_112 = V_42 -> V_140 ( V_42 , & V_119 ) ;
F_66 ( V_112 ,
L_253 ,
F_80 ( V_119 ) ) ;
}
}
}
static void
F_837 ( struct V_15 * V_16 , struct V_45 * V_727 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_41 * V_42 ;
struct V_35 * V_459 ;
struct V_111 * V_38 ;
int V_50 ;
F_428 (old_state, crtc, old_crtc_state, i) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_43 * V_212 , * V_1285 ;
bool V_112 ;
if ( ! F_19 ( V_38 -> V_36 ) &&
! F_284 ( V_38 -> V_36 ) -> V_1286 )
continue;
F_838 ( V_38 , V_459 ) ;
V_212 = F_284 ( V_459 ) ;
memset ( V_212 , 0 , sizeof( * V_212 ) ) ;
V_212 -> V_40 . V_38 = V_38 ;
V_212 -> V_40 . V_36 = V_727 ;
F_153 ( L_254 ,
V_38 -> V_40 . V_241 ) ;
V_112 = V_2 -> V_449 . V_1287 ( V_37 ,
V_212 ) ;
if ( ( V_37 -> V_119 == V_148 && V_2 -> V_167 & V_168 ) ||
( V_37 -> V_119 == V_157 && V_2 -> V_167 & V_169 ) )
V_112 = V_38 -> V_36 -> V_112 ;
F_66 ( V_38 -> V_36 -> V_112 != V_112 ,
L_255
L_252 , V_38 -> V_36 -> V_112 , V_112 ) ;
F_66 ( V_37 -> V_112 != V_38 -> V_36 -> V_112 ,
L_256
L_252 , V_38 -> V_36 -> V_112 , V_37 -> V_112 ) ;
F_22 (dev, crtc, encoder) {
enum V_119 V_119 ;
V_112 = V_42 -> V_140 ( V_42 , & V_119 ) ;
F_66 ( V_112 != V_38 -> V_36 -> V_112 ,
L_257 ,
V_42 -> V_40 . V_40 . V_241 , V_112 , V_38 -> V_36 -> V_112 ) ;
F_66 ( V_112 && V_37 -> V_119 != V_119 ,
L_258 ,
F_80 ( V_119 ) ) ;
if ( V_112 )
V_42 -> V_1288 ( V_42 , V_212 ) ;
}
if ( ! V_38 -> V_36 -> V_112 )
continue;
V_1285 = F_284 ( V_38 -> V_36 ) ;
if ( ! F_821 ( V_16 , V_1285 ,
V_212 , false ) ) {
F_66 ( 1 , L_259 ) ;
F_805 ( V_37 , V_212 ,
L_260 ) ;
F_805 ( V_37 , V_1285 ,
L_261 ) ;
}
}
}
static void
F_839 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_38 ;
struct V_138 V_213 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_544 ; V_50 ++ ) {
struct V_134 * V_137 = & V_2 -> V_136 [ V_50 ] ;
int V_1289 = 0 , V_1290 = 0 ;
bool V_112 ;
memset ( & V_213 , 0 , sizeof( V_213 ) ) ;
F_153 ( L_262 , V_137 -> V_8 ) ;
V_112 = V_137 -> V_140 ( V_2 , V_137 , & V_213 ) ;
F_66 ( V_137 -> V_112 > F_840 ( V_137 -> V_115 . V_238 ) ,
L_263 ,
V_137 -> V_112 , F_840 ( V_137 -> V_115 . V_238 ) ) ;
F_66 ( V_137 -> V_112 && ! V_137 -> V_239 ,
L_264 ) ;
F_66 ( V_137 -> V_239 && ! V_137 -> V_112 ,
L_265 ) ;
F_66 ( V_137 -> V_239 != V_112 ,
L_266 ,
V_137 -> V_239 , V_112 ) ;
F_140 (dev, crtc) {
if ( V_38 -> V_40 . V_36 -> V_243 && F_68 ( V_38 ) == V_137 )
V_1289 ++ ;
if ( V_38 -> V_112 && F_68 ( V_38 ) == V_137 )
V_1290 ++ ;
}
F_66 ( V_137 -> V_112 != V_1290 ,
L_267 ,
V_137 -> V_112 , V_1290 ) ;
F_66 ( F_840 ( V_137 -> V_115 . V_238 ) != V_1289 ,
L_268 ,
F_840 ( V_137 -> V_115 . V_238 ) , V_1289 ) ;
F_66 ( V_137 -> V_239 && memcmp ( & V_137 -> V_115 . V_139 , & V_213 ,
sizeof( V_213 ) ) ,
L_269 ) ;
}
}
static void
F_841 ( struct V_15 * V_16 ,
struct V_45 * V_727 )
{
F_831 ( V_16 ) ;
F_835 ( V_16 , V_727 ) ;
F_836 ( V_16 ) ;
F_837 ( V_16 , V_727 ) ;
F_839 ( V_16 ) ;
}
void F_842 ( const struct V_43 * V_212 ,
int V_1291 )
{
F_6 ( ! F_817 ( V_212 -> V_40 . V_116 . V_117 , V_1291 ) ,
L_270 ,
V_212 -> V_40 . V_116 . V_117 , V_1291 ) ;
}
static void F_843 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
if ( F_33 ( V_16 ) ) {
const struct V_533 * V_116 = & V_38 -> V_115 -> V_40 . V_116 ;
int V_924 ;
V_924 = V_116 -> V_908 ;
if ( V_116 -> V_355 & V_911 )
V_924 /= 2 ;
V_38 -> V_1292 = V_924 - 1 ;
} else if ( F_71 ( V_16 ) &&
F_21 ( V_38 , V_63 ) ) {
V_38 -> V_1292 = 2 ;
} else
V_38 -> V_1292 = 1 ;
}
static void F_844 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_1 * V_2 = F_204 ( V_16 ) ;
struct V_542 * V_135 = NULL ;
struct V_37 * V_37 ;
struct V_43 * V_43 ;
struct V_111 * V_38 ;
struct V_35 * V_44 ;
int V_50 ;
if ( ! V_2 -> V_449 . V_1231 )
return;
F_428 (state, crtc, crtc_state, i) {
int V_87 ;
V_37 = F_50 ( V_38 ) ;
V_43 = F_284 ( V_44 ) ;
V_87 = V_43 -> V_135 ;
if ( ! F_19 ( V_44 ) || V_87 == V_959 )
continue;
V_43 -> V_135 = V_959 ;
if ( ! V_135 )
V_135 = F_352 ( V_36 ) ;
V_135 [ V_87 ] . V_238 &= ~ ( 1 << V_37 -> V_119 ) ;
}
}
static int F_845 ( struct V_45 * V_36 )
{
struct V_35 * V_44 ;
struct V_37 * V_37 ;
struct V_111 * V_38 ;
struct V_43 * V_1293 = NULL ;
struct V_43 * V_748 = NULL ;
enum V_119 V_1294 = V_607 , V_1295 = V_607 ;
int V_50 ;
F_428 (state, crtc, crtc_state, i) {
V_37 = F_50 ( V_38 ) ;
if ( ! V_44 -> V_112 || ! F_19 ( V_44 ) )
continue;
if ( V_1293 ) {
V_748 = F_284 ( V_44 ) ;
break;
} else {
V_1293 = F_284 ( V_44 ) ;
V_1294 = V_37 -> V_119 ;
}
}
if ( ! V_1293 )
return 0 ;
F_140 (state->dev, intel_crtc) {
struct V_43 * V_212 ;
V_212 = F_466 ( V_36 , V_37 ) ;
if ( F_467 ( V_212 ) )
return F_468 ( V_212 ) ;
V_212 -> V_603 = V_607 ;
if ( ! V_212 -> V_40 . V_112 ||
F_19 ( & V_212 -> V_40 ) )
continue;
if ( V_1295 != V_607 )
return 0 ;
V_1295 = V_37 -> V_119 ;
}
if ( V_1295 != V_607 )
V_1293 -> V_603 = V_1295 ;
else if ( V_748 )
V_748 -> V_603 = V_1294 ;
return 0 ;
}
static int F_846 ( struct V_45 * V_36 )
{
struct V_111 * V_38 ;
struct V_35 * V_44 ;
int V_305 = 0 ;
F_217 (state->dev, crtc) {
V_44 = F_489 ( V_36 , V_38 ) ;
if ( F_467 ( V_44 ) )
return F_468 ( V_44 ) ;
if ( ! V_44 -> V_112 || F_19 ( V_44 ) )
continue;
V_44 -> V_1218 = true ;
V_305 = F_847 ( V_36 , V_38 ) ;
if ( V_305 )
break;
V_305 = F_848 ( V_36 , V_38 ) ;
if ( V_305 )
break;
}
return V_305 ;
}
static int F_849 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_305 ;
if ( ! F_809 ( V_36 ) ) {
F_153 ( L_271 ) ;
return - V_307 ;
}
if ( V_2 -> V_449 . V_1296 ) {
unsigned int V_644 ;
V_305 = V_2 -> V_449 . V_1296 ( V_36 ) ;
V_644 = F_355 ( V_36 ) -> V_644 ;
if ( ! V_305 && V_644 != V_2 -> V_645 )
V_305 = F_846 ( V_36 ) ;
if ( V_305 < 0 )
return V_305 ;
} else
F_355 ( V_36 ) -> V_644 = V_2 -> V_645 ;
F_844 ( V_36 ) ;
if ( F_235 ( V_16 ) )
return F_845 ( V_36 ) ;
return 0 ;
}
static void F_850 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_1297 * V_1298 = F_355 ( V_36 ) ;
struct V_111 * V_38 ;
struct V_35 * V_1299 ;
struct V_301 * V_171 ;
struct V_277 * V_1300 ;
F_851 (crtc, dev) {
V_1299 = F_852 ( V_36 , V_38 ) ? :
V_38 -> V_36 ;
if ( V_1299 -> V_112 )
V_1298 -> V_1301 . V_1302 ++ ;
}
F_853 (plane, dev) {
V_1300 = F_816 ( V_36 , V_171 ) ? :
V_171 -> V_36 ;
if ( ! F_219 ( V_1300 ) -> V_361 )
continue;
V_1298 -> V_1301 . V_1303 = true ;
if ( V_1300 -> V_370 != V_1300 -> V_366 >> 16 ||
V_1300 -> V_371 != V_1300 -> V_367 >> 16 )
V_1298 -> V_1301 . V_1304 = true ;
}
}
static int F_854 ( struct V_15 * V_16 ,
struct V_45 * V_36 )
{
struct V_1297 * V_1298 = F_355 ( V_36 ) ;
struct V_111 * V_38 ;
struct V_35 * V_44 ;
int V_305 , V_50 ;
bool V_1305 = false ;
V_305 = F_855 ( V_16 , V_36 ) ;
if ( V_305 )
return V_305 ;
F_428 (state, crtc, crtc_state, i) {
struct V_43 * V_212 =
F_284 ( V_44 ) ;
memset ( & F_50 ( V_38 ) -> V_589 , 0 ,
sizeof( struct V_588 ) ) ;
if ( V_44 -> V_445 . V_1306 != V_38 -> V_36 -> V_445 . V_1306 )
V_44 -> V_1218 = true ;
if ( ! V_44 -> V_243 ) {
if ( F_19 ( V_44 ) )
V_1305 = true ;
continue;
}
if ( ! F_19 ( V_44 ) )
continue;
V_305 = F_847 ( V_36 , V_38 ) ;
if ( V_305 )
return V_305 ;
V_305 = F_813 ( V_38 , V_212 ) ;
if ( V_305 )
return V_305 ;
if ( V_757 . V_1307 &&
F_821 ( V_36 -> V_16 ,
F_284 ( V_38 -> V_36 ) ,
V_212 , true ) ) {
V_44 -> V_1218 = false ;
F_284 ( V_44 ) -> V_1286 = true ;
}
if ( F_19 ( V_44 ) ) {
V_1305 = true ;
V_305 = F_848 ( V_36 , V_38 ) ;
if ( V_305 )
return V_305 ;
}
F_805 ( F_50 ( V_38 ) , V_212 ,
F_19 ( V_44 ) ?
L_272 : L_273 ) ;
}
if ( V_1305 ) {
V_305 = F_849 ( V_36 ) ;
if ( V_305 )
return V_305 ;
} else
V_1298 -> V_644 = F_204 ( V_36 -> V_16 ) -> V_645 ;
V_305 = F_856 ( V_36 -> V_16 , V_36 ) ;
if ( V_305 )
return V_305 ;
F_850 ( V_36 ) ;
return 0 ;
}
static int F_857 ( struct V_15 * V_16 ,
struct V_45 * V_36 ,
bool V_1308 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_277 * V_278 ;
struct V_35 * V_44 ;
struct V_301 * V_171 ;
struct V_111 * V_38 ;
int V_50 , V_305 ;
if ( V_1308 ) {
F_153 ( L_274 ) ;
return - V_307 ;
}
F_428 (state, crtc, crtc_state, i) {
V_305 = F_314 ( V_38 ) ;
if ( V_305 )
return V_305 ;
if ( F_282 ( & F_50 ( V_38 ) -> V_494 ) >= 2 )
F_778 ( V_2 -> V_499 ) ;
}
V_305 = F_858 ( & V_16 -> V_306 ) ;
if ( V_305 )
return V_305 ;
V_305 = F_859 ( V_16 , V_36 ) ;
if ( ! V_305 && ! V_1308 && ! F_281 ( & V_2 -> V_455 ) ) {
T_1 V_456 ;
V_456 = F_282 ( & V_2 -> V_455 . V_456 ) ;
F_4 ( & V_16 -> V_306 ) ;
F_860 (state, plane, plane_state, i) {
struct V_431 * V_431 =
F_219 ( V_278 ) ;
if ( ! V_431 -> V_1309 )
continue;
V_305 = F_757 ( V_431 -> V_1309 ,
V_456 , true ,
NULL , NULL ) ;
if ( V_305 == - V_1214 )
V_305 = 0 ;
if ( V_305 )
break;
}
if ( ! V_305 )
return 0 ;
F_2 ( & V_16 -> V_306 ) ;
F_861 ( V_16 , V_36 ) ;
}
F_4 ( & V_16 -> V_306 ) ;
return V_305 ;
}
static int F_862 ( struct V_15 * V_16 ,
struct V_45 * V_36 ,
bool V_1308 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_35 * V_44 ;
struct V_111 * V_38 ;
int V_305 = 0 ;
int V_50 ;
bool V_1305 = false ;
V_305 = F_857 ( V_16 , V_36 , V_1308 ) ;
if ( V_305 ) {
F_793 ( L_275 , V_305 ) ;
return V_305 ;
}
F_863 ( V_16 , V_36 ) ;
V_2 -> V_585 . V_115 = F_355 ( V_36 ) -> V_1301 ;
F_428 (state, crtc, crtc_state, i) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
if ( ! F_19 ( V_38 -> V_36 ) )
continue;
V_1305 = true ;
F_384 ( V_37 ) ;
if ( V_44 -> V_112 ) {
F_386 ( V_38 , V_44 -> V_362 ) ;
V_2 -> V_449 . V_735 ( V_38 ) ;
V_37 -> V_112 = false ;
F_156 ( V_37 ) ;
F_377 ( V_2 ) ;
F_378 ( V_2 ) ;
if ( ! V_38 -> V_36 -> V_112 )
F_382 ( V_38 ) ;
}
}
F_815 ( V_36 ) ;
if ( V_1305 ) {
F_354 ( V_36 ) ;
F_864 ( V_36 -> V_16 , V_36 ) ;
F_427 ( V_36 ) ;
}
F_428 (state, crtc, crtc_state, i) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
bool V_1310 = F_19 ( V_38 -> V_36 ) ;
bool V_1286 = ! V_1310 &&
F_284 ( V_38 -> V_36 ) -> V_1286 ;
unsigned long V_641 = 0 ;
if ( V_1310 )
F_155 ( V_2 , V_1311 ) ;
if ( V_1310 && V_38 -> V_36 -> V_112 ) {
F_843 ( F_50 ( V_38 ) ) ;
V_2 -> V_449 . V_1312 ( V_38 ) ;
}
if ( V_1286 ) {
V_641 = F_424 ( V_38 ) ;
V_1305 = true ;
}
if ( ! V_1310 )
F_384 ( V_37 ) ;
if ( V_38 -> V_36 -> V_112 &&
( V_38 -> V_36 -> V_1313 || V_1286 ) )
F_865 ( V_44 ) ;
if ( V_641 )
F_426 ( V_2 , V_641 ) ;
F_380 ( V_37 ) ;
if ( V_1310 )
F_88 ( V_2 , V_1311 ) ;
}
F_866 ( V_16 , V_36 ) ;
F_2 ( & V_16 -> V_306 ) ;
F_861 ( V_16 , V_36 ) ;
F_4 ( & V_16 -> V_306 ) ;
if ( V_1305 )
F_841 ( V_16 , V_36 ) ;
F_492 ( V_36 ) ;
return 0 ;
}
void F_867 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_45 * V_36 ;
struct V_35 * V_44 ;
int V_305 ;
V_36 = F_488 ( V_16 ) ;
if ( ! V_36 ) {
F_153 ( L_276 ,
V_38 -> V_40 . V_241 ) ;
return;
}
V_36 -> V_740 = F_788 ( V_38 ) ;
V_479:
V_44 = F_489 ( V_36 , V_38 ) ;
V_305 = F_490 ( V_44 ) ;
if ( ! V_305 ) {
if ( ! V_44 -> V_112 )
goto V_960;
V_44 -> V_1218 = true ;
V_305 = F_491 ( V_36 ) ;
}
if ( V_305 == - V_310 ) {
F_789 ( V_36 ) ;
F_704 ( V_36 -> V_740 ) ;
goto V_479;
}
if ( V_305 )
V_960:
F_492 ( V_36 ) ;
}
static bool F_868 ( struct V_1 * V_2 ,
struct V_134 * V_137 ,
struct V_138 * V_139 )
{
T_2 V_10 ;
if ( ! F_87 ( V_2 , V_242 ) )
return false ;
V_10 = F_11 ( F_869 ( V_137 -> V_241 ) ) ;
V_139 -> V_87 = V_10 ;
V_139 -> V_732 = F_11 ( F_870 ( V_137 -> V_241 ) ) ;
V_139 -> V_733 = F_11 ( F_871 ( V_137 -> V_241 ) ) ;
F_88 ( V_2 , V_242 ) ;
return V_10 & V_131 ;
}
static void F_872 ( struct V_1 * V_2 ,
struct V_134 * V_137 )
{
F_129 ( F_870 ( V_137 -> V_241 ) , V_137 -> V_115 . V_139 . V_732 ) ;
F_129 ( F_871 ( V_137 -> V_241 ) , V_137 -> V_115 . V_139 . V_733 ) ;
}
static void F_873 ( struct V_1 * V_2 ,
struct V_134 * V_137 )
{
F_105 ( V_2 ) ;
F_129 ( F_869 ( V_137 -> V_241 ) , V_137 -> V_115 . V_139 . V_87 ) ;
F_130 ( F_869 ( V_137 -> V_241 ) ) ;
F_131 ( 150 ) ;
F_129 ( F_869 ( V_137 -> V_241 ) , V_137 -> V_115 . V_139 . V_87 ) ;
F_130 ( F_869 ( V_137 -> V_241 ) ) ;
F_131 ( 200 ) ;
}
static void F_874 ( struct V_1 * V_2 ,
struct V_134 * V_137 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_37 * V_38 ;
F_140 (dev, crtc) {
if ( F_68 ( V_38 ) == V_137 )
F_108 ( V_2 , V_38 -> V_119 ) ;
}
F_129 ( F_869 ( V_137 -> V_241 ) , 0 ) ;
F_130 ( F_869 ( V_137 -> V_241 ) ) ;
F_131 ( 200 ) ;
}
static void F_875 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
int V_50 ;
V_2 -> V_544 = 2 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_544 ; V_50 ++ ) {
V_2 -> V_136 [ V_50 ] . V_241 = V_50 ;
V_2 -> V_136 [ V_50 ] . V_8 = V_1314 [ V_50 ] ;
V_2 -> V_136 [ V_50 ] . V_240 = F_872 ;
V_2 -> V_136 [ V_50 ] . V_243 = F_873 ;
V_2 -> V_136 [ V_50 ] . V_244 = F_874 ;
V_2 -> V_136 [ V_50 ] . V_140 =
F_868 ;
}
}
static void F_876 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_71 ( V_16 ) )
F_877 ( V_16 ) ;
else if ( F_106 ( V_16 ) || F_107 ( V_16 ) )
F_875 ( V_16 ) ;
else
V_2 -> V_544 = 0 ;
F_142 ( V_2 -> V_544 > V_1315 ) ;
}
int
F_878 ( struct V_301 * V_171 ,
const struct V_277 * V_1316 )
{
struct V_15 * V_16 = V_171 -> V_16 ;
struct V_276 * V_114 = V_1316 -> V_114 ;
struct V_359 * V_359 = F_215 ( V_171 ) ;
struct V_302 * V_303 = F_190 ( V_114 ) ;
struct V_302 * V_1317 = F_190 ( V_171 -> V_36 -> V_114 ) ;
int V_305 = 0 ;
if ( ! V_303 && ! V_1317 )
return 0 ;
if ( V_1317 ) {
struct V_35 * V_44 =
F_852 ( V_1316 -> V_36 , V_171 -> V_36 -> V_38 ) ;
if ( F_19 ( V_44 ) )
V_305 = F_879 ( V_1317 , true ) ;
if ( V_305 && V_305 != - V_1214 )
return V_305 ;
}
if ( V_303 && V_303 -> V_40 . V_1191 ) {
long V_1318 ;
V_1318 = F_759 ( V_303 -> V_40 . V_1191 -> V_1192 ,
false , true ,
V_1198 ) ;
if ( V_1318 == - V_1319 )
return V_1318 ;
F_6 ( V_1318 < 0 , L_277 , V_1318 ) ;
}
if ( ! V_303 ) {
V_305 = 0 ;
} else if ( V_171 -> type == V_1224 &&
F_60 ( V_16 ) -> V_1320 ) {
int V_1321 = F_143 ( V_16 ) ? 16 * 1024 : 256 ;
V_305 = F_880 ( V_303 , V_1321 ) ;
if ( V_305 )
F_153 ( L_278 ) ;
} else {
V_305 = F_189 ( V_171 , V_114 , V_1316 ) ;
}
if ( V_305 == 0 ) {
if ( V_303 ) {
struct V_431 * V_278 =
F_219 ( V_1316 ) ;
F_721 ( & V_278 -> V_1309 ,
V_303 -> V_1193 ) ;
}
F_784 ( V_1317 , V_303 , V_359 -> V_374 ) ;
}
return V_305 ;
}
void
F_881 ( struct V_301 * V_171 ,
const struct V_277 * V_727 )
{
struct V_15 * V_16 = V_171 -> V_16 ;
struct V_359 * V_359 = F_215 ( V_171 ) ;
struct V_431 * V_1322 ;
struct V_302 * V_1317 = F_190 ( V_727 -> V_114 ) ;
struct V_302 * V_303 = F_190 ( V_171 -> V_36 -> V_114 ) ;
V_1322 = F_219 ( V_727 ) ;
if ( ! V_303 && ! V_1317 )
return;
if ( V_1317 && ( V_171 -> type != V_1224 ||
! F_60 ( V_16 ) -> V_1320 ) )
F_198 ( V_727 -> V_114 , V_727 ) ;
if ( ( V_1317 && ( V_1317 -> V_373 & V_359 -> V_374 ) ) ||
( V_303 && ! ( V_303 -> V_373 & V_359 -> V_374 ) ) )
F_784 ( V_1317 , V_303 , V_359 -> V_374 ) ;
F_721 ( & V_1322 -> V_1309 , NULL ) ;
}
int
F_882 ( struct V_37 * V_37 , struct V_43 * V_44 )
{
int V_1323 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_117 , V_644 ;
if ( ! V_37 || ! V_44 )
return V_1324 ;
V_16 = V_37 -> V_40 . V_16 ;
V_2 = V_16 -> V_17 ;
V_117 = V_44 -> V_40 . V_116 . V_117 ;
V_644 = F_355 ( V_44 -> V_40 . V_36 ) -> V_644 ;
if ( F_47 ( ! V_117 || V_644 < V_117 ) )
return V_1324 ;
V_1323 = V_90 ( ( 1 << 16 ) * 3 - 1 , ( 1 << 8 ) * ( ( V_644 << 8 ) / V_117 ) ) ;
return V_1323 ;
}
static int
F_883 ( struct V_301 * V_171 ,
struct V_43 * V_44 ,
struct V_431 * V_36 )
{
struct V_111 * V_38 = V_36 -> V_40 . V_38 ;
struct V_276 * V_114 = V_36 -> V_40 . V_114 ;
int V_1325 = V_1324 ;
int V_1323 = V_1324 ;
bool V_1326 = false ;
if ( F_60 ( V_171 -> V_16 ) -> V_127 >= 9 ) {
if ( V_36 -> V_563 . V_355 == V_564 ) {
V_1325 = 1 ;
V_1323 = F_882 ( F_50 ( V_38 ) , V_44 ) ;
}
V_1326 = true ;
}
return F_884 ( V_171 , V_38 , V_114 , & V_36 -> V_440 ,
& V_36 -> V_442 , & V_36 -> V_1327 ,
V_1325 , V_1323 ,
V_1326 , true ,
& V_36 -> V_361 ) ;
}
static void
F_885 ( struct V_301 * V_171 ,
struct V_431 * V_36 )
{
struct V_111 * V_38 = V_36 -> V_40 . V_38 ;
struct V_276 * V_114 = V_36 -> V_40 . V_114 ;
struct V_15 * V_16 = V_171 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
V_38 = V_38 ? V_38 : V_171 -> V_38 ;
V_2 -> V_449 . V_450 ( V_38 , V_114 ,
V_36 -> V_440 . V_441 >> 16 ,
V_36 -> V_440 . y1 >> 16 ) ;
}
static void
F_886 ( struct V_301 * V_171 ,
struct V_111 * V_38 )
{
struct V_15 * V_16 = V_171 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_449 . V_450 ( V_38 , NULL , 0 , 0 ) ;
}
static void F_887 ( struct V_111 * V_38 ,
struct V_35 * V_459 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_43 * V_1322 =
F_284 ( V_459 ) ;
bool V_1310 = F_19 ( V_38 -> V_36 ) ;
F_754 ( V_37 ) ;
if ( V_1310 )
return;
if ( F_284 ( V_38 -> V_36 ) -> V_1286 )
F_283 ( V_37 , V_1322 ) ;
else if ( F_60 ( V_16 ) -> V_127 >= 9 )
F_247 ( V_37 ) ;
}
static void F_888 ( struct V_111 * V_38 ,
struct V_35 * V_459 )
{
struct V_37 * V_37 = F_50 ( V_38 ) ;
F_755 ( V_37 ) ;
}
void F_889 ( struct V_301 * V_171 )
{
struct V_359 * V_359 = F_215 ( V_171 ) ;
F_890 ( V_171 ) ;
F_216 ( V_359 ) ;
}
static struct V_301 * F_891 ( struct V_15 * V_16 ,
int V_119 )
{
struct V_359 * V_113 ;
struct V_431 * V_36 ;
const T_2 * V_1328 ;
unsigned int V_1329 ;
V_113 = F_499 ( sizeof( * V_113 ) , V_746 ) ;
if ( V_113 == NULL )
return NULL ;
V_36 = F_892 ( & V_113 -> V_40 ) ;
if ( ! V_36 ) {
F_216 ( V_113 ) ;
return NULL ;
}
V_113 -> V_40 . V_36 = & V_36 -> V_40 ;
V_113 -> V_1330 = false ;
V_113 -> V_1331 = 1 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
V_113 -> V_1330 = true ;
V_36 -> V_436 = - 1 ;
}
V_113 -> V_119 = V_119 ;
V_113 -> V_171 = V_119 ;
V_113 -> V_374 = F_893 ( V_119 ) ;
V_113 -> V_1332 = F_883 ;
V_113 -> V_451 = F_885 ;
V_113 -> V_363 = F_886 ;
if ( F_894 ( V_16 ) && F_60 ( V_16 ) -> V_127 < 4 )
V_113 -> V_171 = ! V_119 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
V_1328 = V_1333 ;
V_1329 = F_302 ( V_1333 ) ;
} else if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
V_1328 = V_1334 ;
V_1329 = F_302 ( V_1334 ) ;
} else {
V_1328 = V_1335 ;
V_1329 = F_302 ( V_1335 ) ;
}
F_895 ( V_16 , & V_113 -> V_40 , 0 ,
& V_1336 ,
V_1328 , V_1329 ,
V_1225 , NULL ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 )
F_896 ( V_16 , V_113 ) ;
F_897 ( & V_113 -> V_40 , & V_1337 ) ;
return & V_113 -> V_40 ;
}
void F_896 ( struct V_15 * V_16 , struct V_359 * V_171 )
{
if ( ! V_16 -> V_737 . V_1338 ) {
unsigned long V_355 = F_230 ( V_418 ) |
F_230 ( V_386 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 )
V_355 |= F_230 ( V_419 ) | F_230 ( V_422 ) ;
V_16 -> V_737 . V_1338 =
F_898 ( V_16 , V_355 ) ;
}
if ( V_16 -> V_737 . V_1338 )
F_899 ( & V_171 -> V_40 . V_40 ,
V_16 -> V_737 . V_1338 ,
V_171 -> V_40 . V_36 -> V_285 ) ;
}
static int
F_900 ( struct V_301 * V_171 ,
struct V_43 * V_44 ,
struct V_431 * V_36 )
{
struct V_111 * V_38 = V_44 -> V_40 . V_38 ;
struct V_276 * V_114 = V_36 -> V_40 . V_114 ;
struct V_302 * V_303 = F_190 ( V_114 ) ;
enum V_119 V_119 = F_215 ( V_171 ) -> V_119 ;
unsigned V_353 ;
int V_305 ;
V_305 = F_884 ( V_171 , V_38 , V_114 , & V_36 -> V_440 ,
& V_36 -> V_442 , & V_36 -> V_1327 ,
V_1324 ,
V_1324 ,
true , true , & V_36 -> V_361 ) ;
if ( V_305 )
return V_305 ;
if ( ! V_303 )
return 0 ;
if ( ! F_679 ( V_171 -> V_16 , V_36 -> V_40 . V_370 , V_36 -> V_40 . V_371 ) ) {
F_901 ( L_279 ,
V_36 -> V_40 . V_370 , V_36 -> V_40 . V_371 ) ;
return - V_307 ;
}
V_353 = F_673 ( V_36 -> V_40 . V_370 ) * 4 ;
if ( V_303 -> V_40 . V_296 < V_353 * V_36 -> V_40 . V_371 ) {
F_153 ( L_280 ) ;
return - V_742 ;
}
if ( V_114 -> V_292 [ 0 ] != V_269 ) {
F_153 ( L_281 ) ;
return - V_307 ;
}
if ( F_14 ( V_171 -> V_16 ) && V_119 == V_524 &&
V_36 -> V_361 && V_36 -> V_40 . V_368 < 0 ) {
F_153 ( L_282 ) ;
return - V_307 ;
}
return 0 ;
}
static void
F_902 ( struct V_301 * V_171 ,
struct V_111 * V_38 )
{
F_677 ( V_38 , false ) ;
}
static void
F_903 ( struct V_301 * V_171 ,
struct V_431 * V_36 )
{
struct V_111 * V_38 = V_36 -> V_40 . V_38 ;
struct V_15 * V_16 = V_171 -> V_16 ;
struct V_37 * V_37 ;
struct V_302 * V_303 = F_190 ( V_36 -> V_40 . V_114 ) ;
T_2 V_1199 ;
V_38 = V_38 ? V_38 : V_171 -> V_38 ;
V_37 = F_50 ( V_38 ) ;
if ( ! V_303 )
V_1199 = 0 ;
else if ( ! F_60 ( V_16 ) -> V_1320 )
V_1199 = F_218 ( V_303 ) ;
else
V_1199 = V_303 -> V_1339 -> V_1340 ;
V_37 -> V_1103 = V_1199 ;
if ( V_38 -> V_36 -> V_112 )
F_677 ( V_38 , V_36 -> V_361 ) ;
}
static struct V_301 * F_904 ( struct V_15 * V_16 ,
int V_119 )
{
struct V_359 * V_1089 ;
struct V_431 * V_36 ;
V_1089 = F_499 ( sizeof( * V_1089 ) , V_746 ) ;
if ( V_1089 == NULL )
return NULL ;
V_36 = F_892 ( & V_1089 -> V_40 ) ;
if ( ! V_36 ) {
F_216 ( V_1089 ) ;
return NULL ;
}
V_1089 -> V_40 . V_36 = & V_36 -> V_40 ;
V_1089 -> V_1330 = false ;
V_1089 -> V_1331 = 1 ;
V_1089 -> V_119 = V_119 ;
V_1089 -> V_171 = V_119 ;
V_1089 -> V_374 = F_905 ( V_119 ) ;
V_1089 -> V_1332 = F_900 ;
V_1089 -> V_451 = F_903 ;
V_1089 -> V_363 = F_902 ;
F_895 ( V_16 , & V_1089 -> V_40 , 0 ,
& V_1336 ,
V_1341 ,
F_302 ( V_1341 ) ,
V_1224 , NULL ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
if ( ! V_16 -> V_737 . V_1338 )
V_16 -> V_737 . V_1338 =
F_898 ( V_16 ,
F_230 ( V_418 ) |
F_230 ( V_386 ) ) ;
if ( V_16 -> V_737 . V_1338 )
F_899 ( & V_1089 -> V_40 . V_40 ,
V_16 -> V_737 . V_1338 ,
V_36 -> V_40 . V_285 ) ;
}
if ( F_60 ( V_16 ) -> V_127 >= 9 )
V_36 -> V_436 = - 1 ;
F_897 ( & V_1089 -> V_40 , & V_1337 ) ;
return & V_1089 -> V_40 ;
}
static void F_671 ( struct V_15 * V_16 , struct V_37 * V_37 ,
struct V_43 * V_44 )
{
int V_50 ;
struct V_1342 * V_1342 ;
struct V_398 * V_399 = & V_44 -> V_399 ;
for ( V_50 = 0 ; V_50 < V_37 -> V_400 ; V_50 ++ ) {
V_1342 = & V_399 -> V_401 [ V_50 ] ;
V_1342 -> V_402 = 0 ;
V_1342 -> V_445 = V_1343 ;
}
V_399 -> V_436 = - 1 ;
}
static void F_906 ( struct V_15 * V_16 , int V_119 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 ;
struct V_43 * V_44 = NULL ;
struct V_301 * V_113 = NULL ;
struct V_301 * V_1089 = NULL ;
int V_50 , V_305 ;
V_37 = F_499 ( sizeof( * V_37 ) , V_746 ) ;
if ( V_37 == NULL )
return;
V_44 = F_499 ( sizeof( * V_44 ) , V_746 ) ;
if ( ! V_44 )
goto V_811;
V_37 -> V_115 = V_44 ;
V_37 -> V_40 . V_36 = & V_44 -> V_40 ;
V_44 -> V_40 . V_38 = & V_37 -> V_40 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
if ( V_119 == V_524 )
V_37 -> V_400 = 1 ;
else
V_37 -> V_400 = V_1344 ;
F_671 ( V_16 , V_37 , V_44 ) ;
}
V_113 = F_891 ( V_16 , V_119 ) ;
if ( ! V_113 )
goto V_811;
V_1089 = F_904 ( V_16 , V_119 ) ;
if ( ! V_1089 )
goto V_811;
V_305 = F_907 ( V_16 , & V_37 -> V_40 , V_113 ,
V_1089 , & V_1345 , NULL ) ;
if ( V_305 )
goto V_811;
F_908 ( & V_37 -> V_40 , 256 ) ;
for ( V_50 = 0 ; V_50 < 256 ; V_50 ++ ) {
V_37 -> V_579 [ V_50 ] = V_50 ;
V_37 -> V_580 [ V_50 ] = V_50 ;
V_37 -> V_581 [ V_50 ] = V_50 ;
}
V_37 -> V_119 = V_119 ;
V_37 -> V_171 = V_119 ;
if ( F_894 ( V_16 ) && F_60 ( V_16 ) -> V_127 < 4 ) {
F_153 ( L_283 ) ;
V_37 -> V_171 = ! V_119 ;
}
V_37 -> V_1093 = ~ 0 ;
V_37 -> V_1092 = ~ 0 ;
V_37 -> V_1094 = ~ 0 ;
V_37 -> V_585 . V_592 = true ;
F_142 ( V_119 >= F_302 ( V_2 -> V_1154 ) ||
V_2 -> V_1154 [ V_37 -> V_171 ] != NULL ) ;
V_2 -> V_1154 [ V_37 -> V_171 ] = & V_37 -> V_40 ;
V_2 -> V_120 [ V_37 -> V_119 ] = & V_37 -> V_40 ;
F_909 ( & V_37 -> V_40 , & V_1346 ) ;
F_9 ( F_157 ( & V_37 -> V_40 ) != V_37 -> V_119 ) ;
return;
V_811:
if ( V_113 )
F_890 ( V_113 ) ;
if ( V_1089 )
F_890 ( V_1089 ) ;
F_216 ( V_44 ) ;
F_216 ( V_37 ) ;
}
enum V_119 F_910 ( struct V_744 * V_47 )
{
struct V_743 * V_42 = V_47 -> V_40 . V_42 ;
struct V_15 * V_16 = V_47 -> V_40 . V_16 ;
F_9 ( ! F_911 ( & V_16 -> V_737 . V_1116 ) ) ;
if ( ! V_42 || F_9 ( ! V_42 -> V_38 ) )
return V_607 ;
return F_50 ( V_42 -> V_38 ) -> V_119 ;
}
int F_912 ( struct V_15 * V_16 , void * V_1057 ,
struct V_1347 * V_1348 )
{
struct V_1349 * V_1350 = V_1057 ;
struct V_111 * V_1351 ;
struct V_37 * V_38 ;
V_1351 = F_913 ( V_16 , V_1350 -> V_1352 ) ;
if ( ! V_1351 ) {
F_132 ( L_284 ) ;
return - V_1353 ;
}
V_38 = F_50 ( V_1351 ) ;
V_1350 -> V_119 = V_38 -> V_119 ;
return 0 ;
}
static int F_914 ( struct V_41 * V_42 )
{
struct V_15 * V_16 = V_42 -> V_40 . V_16 ;
struct V_41 * V_1230 ;
int V_1354 = 0 ;
int V_1355 = 0 ;
F_602 (dev, source_encoder) {
if ( F_794 ( V_42 , V_1230 ) )
V_1354 |= ( 1 << V_1355 ) ;
V_1355 ++ ;
}
return V_1354 ;
}
static bool F_915 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! F_128 ( V_16 ) )
return false ;
if ( ( F_11 ( V_1356 ) & V_1357 ) == 0 )
return false ;
if ( F_18 ( V_16 ) && ( F_11 ( V_653 ) & V_1358 ) )
return false ;
return true ;
}
static bool F_916 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 )
return false ;
if ( F_520 ( V_16 ) || F_434 ( V_16 ) )
return false ;
if ( F_14 ( V_16 ) )
return false ;
if ( F_917 ( V_16 ) && F_11 ( V_1359 ) & V_1360 )
return false ;
if ( F_71 ( V_16 ) && F_11 ( F_918 ( V_617 ) ) & V_1361 )
return false ;
if ( ! V_2 -> V_829 . V_1362 )
return false ;
return true ;
}
static void F_919 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_41 * V_42 ;
bool V_1363 = false ;
F_920 ( V_16 ) ;
if ( F_916 ( V_16 ) )
F_921 ( V_16 ) ;
if ( F_30 ( V_16 ) ) {
F_922 ( V_16 , V_617 ) ;
F_922 ( V_16 , V_231 ) ;
F_922 ( V_16 , V_233 ) ;
} else if ( F_71 ( V_16 ) ) {
int V_101 ;
V_101 = F_11 ( F_918 ( V_617 ) ) & V_1364 ;
if ( V_101 || F_431 ( V_16 ) || F_432 ( V_16 ) )
F_922 ( V_16 , V_617 ) ;
V_101 = F_11 ( V_1359 ) ;
if ( V_101 & V_1365 )
F_922 ( V_16 , V_231 ) ;
if ( V_101 & V_1366 )
F_922 ( V_16 , V_233 ) ;
if ( V_101 & V_1367 )
F_922 ( V_16 , V_235 ) ;
if ( ( F_431 ( V_16 ) || F_432 ( V_16 ) ) &&
( V_2 -> V_829 . V_1368 [ V_622 ] . V_1369 ||
V_2 -> V_829 . V_1368 [ V_622 ] . V_1370 ||
V_2 -> V_829 . V_1368 [ V_622 ] . V_1371 ) )
F_922 ( V_16 , V_622 ) ;
} else if ( F_10 ( V_16 ) ) {
int V_101 ;
V_1363 = F_923 ( V_16 , V_235 ) ;
if ( F_915 ( V_16 ) )
F_924 ( V_16 , V_1356 , V_617 ) ;
if ( F_11 ( V_209 ) & V_1372 ) {
V_101 = F_925 ( V_16 , V_1373 , V_231 ) ;
if ( ! V_101 )
F_926 ( V_16 , V_209 , V_231 ) ;
if ( ! V_101 && ( F_11 ( V_202 ) & V_1357 ) )
F_924 ( V_16 , V_202 , V_231 ) ;
}
if ( F_11 ( V_210 ) & V_1372 )
F_926 ( V_16 , V_210 , V_233 ) ;
if ( ! V_1363 && F_11 ( V_211 ) & V_1372 )
F_926 ( V_16 , V_211 , V_235 ) ;
if ( F_11 ( V_204 ) & V_1357 )
F_924 ( V_16 , V_204 , V_233 ) ;
if ( F_11 ( V_206 ) & V_1357 )
F_924 ( V_16 , V_206 , V_235 ) ;
} else if ( F_13 ( V_16 ) || F_14 ( V_16 ) ) {
if ( F_11 ( V_1374 ) & V_1372 &&
! F_923 ( V_16 , V_231 ) )
F_926 ( V_16 , V_1374 , V_231 ) ;
if ( F_11 ( V_1375 ) & V_1357 ||
F_923 ( V_16 , V_231 ) )
F_924 ( V_16 , V_1375 , V_231 ) ;
if ( F_11 ( V_1376 ) & V_1372 &&
! F_923 ( V_16 , V_233 ) )
F_926 ( V_16 , V_1376 , V_233 ) ;
if ( F_11 ( V_1377 ) & V_1357 ||
F_923 ( V_16 , V_233 ) )
F_924 ( V_16 , V_1377 , V_233 ) ;
if ( F_14 ( V_16 ) ) {
if ( F_11 ( V_1378 ) & V_1372 )
F_926 ( V_16 , V_1378 , V_235 ) ;
if ( F_11 ( V_1379 ) & V_1357 )
F_924 ( V_16 , V_1379 , V_235 ) ;
}
F_927 ( V_16 ) ;
} else if ( ! F_33 ( V_16 ) && ! F_32 ( V_16 ) ) {
bool V_101 = false ;
if ( F_11 ( V_1380 ) & V_1372 ) {
F_153 ( L_285 ) ;
V_101 = F_925 ( V_16 , V_1380 , V_231 ) ;
if ( ! V_101 && F_31 ( V_16 ) ) {
F_153 ( L_286 ) ;
F_926 ( V_16 , V_1381 , V_231 ) ;
}
if ( ! V_101 && F_31 ( V_16 ) )
F_924 ( V_16 , V_1382 , V_231 ) ;
}
if ( F_11 ( V_1380 ) & V_1372 ) {
F_153 ( L_287 ) ;
V_101 = F_925 ( V_16 , V_1383 , V_233 ) ;
}
if ( ! V_101 && ( F_11 ( V_1383 ) & V_1372 ) ) {
if ( F_31 ( V_16 ) ) {
F_153 ( L_288 ) ;
F_926 ( V_16 , V_1384 , V_233 ) ;
}
if ( F_31 ( V_16 ) )
F_924 ( V_16 , V_1385 , V_233 ) ;
}
if ( F_31 ( V_16 ) &&
( F_11 ( V_1386 ) & V_1357 ) )
F_924 ( V_16 , V_1386 , V_235 ) ;
} else if ( F_33 ( V_16 ) )
F_928 ( V_16 ) ;
if ( F_929 ( V_16 ) )
F_930 ( V_16 ) ;
F_931 ( V_16 ) ;
F_602 (dev, encoder) {
V_42 -> V_40 . V_1123 = V_42 -> V_238 ;
V_42 -> V_40 . V_1387 =
F_914 ( V_42 ) ;
}
F_612 ( V_16 ) ;
F_932 ( V_16 ) ;
}
static void F_933 ( struct V_276 * V_114 )
{
struct V_15 * V_16 = V_114 -> V_16 ;
struct V_951 * V_952 = F_209 ( V_114 ) ;
F_934 ( V_114 ) ;
F_2 ( & V_16 -> V_306 ) ;
F_9 ( ! V_952 -> V_303 -> V_1388 -- ) ;
F_210 ( & V_952 -> V_303 -> V_40 ) ;
F_4 ( & V_16 -> V_306 ) ;
F_216 ( V_952 ) ;
}
static int F_935 ( struct V_276 * V_114 ,
struct V_1347 * V_1348 ,
unsigned int * V_1389 )
{
struct V_951 * V_952 = F_209 ( V_114 ) ;
struct V_302 * V_303 = V_952 -> V_303 ;
if ( V_303 -> V_1390 . V_583 ) {
F_901 ( L_289 ) ;
return - V_307 ;
}
return F_936 ( V_1348 , & V_303 -> V_40 , V_1389 ) ;
}
static int F_937 ( struct V_276 * V_114 ,
struct V_1347 * V_1348 ,
unsigned V_355 , unsigned V_1391 ,
struct V_1392 * V_1393 ,
unsigned V_1394 )
{
struct V_15 * V_16 = V_114 -> V_16 ;
struct V_951 * V_952 = F_209 ( V_114 ) ;
struct V_302 * V_303 = V_952 -> V_303 ;
F_2 ( & V_16 -> V_306 ) ;
F_938 ( V_303 , false , V_1395 ) ;
F_4 ( & V_16 -> V_306 ) ;
return 0 ;
}
static
T_1 F_939 ( struct V_15 * V_16 , V_89 V_291 ,
T_2 V_265 )
{
T_1 V_127 = F_60 ( V_16 ) -> V_127 ;
if ( V_127 >= 9 ) {
return V_90 ( 8192 * F_178 ( V_265 , 0 ) , 32768 ) ;
} else if ( V_127 >= 5 && ! F_13 ( V_16 ) && ! F_14 ( V_16 ) ) {
return 32 * 1024 ;
} else if ( V_127 >= 4 ) {
if ( V_291 == V_270 )
return 16 * 1024 ;
else
return 32 * 1024 ;
} else if ( V_127 >= 3 ) {
if ( V_291 == V_270 )
return 8 * 1024 ;
else
return 16 * 1024 ;
} else {
return 8 * 1024 ;
}
}
static int F_208 ( struct V_15 * V_16 ,
struct V_951 * V_952 ,
struct V_345 * V_346 ,
struct V_302 * V_303 )
{
unsigned int V_950 ;
int V_305 ;
T_1 V_1396 , V_1397 ;
F_9 ( ! F_191 ( & V_16 -> V_306 ) ) ;
if ( V_346 -> V_355 & V_356 ) {
if ( ! ! ( V_303 -> V_315 == V_352 ) !=
! ! ( V_346 -> V_292 [ 0 ] == V_270 ) ) {
F_901 ( L_290 ) ;
return - V_307 ;
}
} else {
if ( V_303 -> V_315 == V_352 )
V_346 -> V_292 [ 0 ] = V_270 ;
else if ( V_303 -> V_315 == V_1398 ) {
F_901 ( L_291 ) ;
return - V_307 ;
}
}
switch ( V_346 -> V_292 [ 0 ] ) {
case V_271 :
case V_272 :
if ( F_60 ( V_16 ) -> V_127 < 9 ) {
F_901 ( L_292 ,
V_346 -> V_292 [ 0 ] ) ;
return - V_307 ;
}
case V_269 :
case V_270 :
break;
default:
F_901 ( L_293 ,
V_346 -> V_292 [ 0 ] ) ;
return - V_307 ;
}
V_1397 = F_238 ( V_16 , V_346 -> V_292 [ 0 ] ,
V_346 -> V_265 ) ;
if ( V_346 -> V_288 [ 0 ] & ( V_1397 - 1 ) ) {
F_901 ( L_294 ,
V_346 -> V_288 [ 0 ] , V_1397 ) ;
return - V_307 ;
}
V_1396 = F_939 ( V_16 , V_346 -> V_292 [ 0 ] ,
V_346 -> V_265 ) ;
if ( V_346 -> V_288 [ 0 ] > V_1396 ) {
F_901 ( L_295 ,
V_346 -> V_292 [ 0 ] != V_269 ?
L_296 : L_297 ,
V_346 -> V_288 [ 0 ] , V_1396 ) ;
return - V_307 ;
}
if ( V_346 -> V_292 [ 0 ] == V_270 &&
V_346 -> V_288 [ 0 ] != V_303 -> V_353 ) {
F_901 ( L_298 ,
V_346 -> V_288 [ 0 ] , V_303 -> V_353 ) ;
return - V_307 ;
}
switch ( V_346 -> V_265 ) {
case V_323 :
case V_327 :
case V_329 :
case V_341 :
break;
case V_325 :
if ( F_60 ( V_16 ) -> V_127 > 3 ) {
F_901 ( L_299 ,
F_940 ( V_346 -> V_265 ) ) ;
return - V_307 ;
}
break;
case V_340 :
if ( ! F_13 ( V_16 ) && ! F_14 ( V_16 ) &&
F_60 ( V_16 ) -> V_127 < 9 ) {
F_901 ( L_299 ,
F_940 ( V_346 -> V_265 ) ) ;
return - V_307 ;
}
break;
case V_331 :
case V_333 :
case V_335 :
if ( F_60 ( V_16 ) -> V_127 < 4 ) {
F_901 ( L_299 ,
F_940 ( V_346 -> V_265 ) ) ;
return - V_307 ;
}
break;
case V_1399 :
if ( ! F_13 ( V_16 ) && ! F_14 ( V_16 ) ) {
F_901 ( L_299 ,
F_940 ( V_346 -> V_265 ) ) ;
return - V_307 ;
}
break;
case V_406 :
case V_411 :
case V_409 :
case V_413 :
if ( F_60 ( V_16 ) -> V_127 < 5 ) {
F_901 ( L_299 ,
F_940 ( V_346 -> V_265 ) ) ;
return - V_307 ;
}
break;
default:
F_901 ( L_299 ,
F_940 ( V_346 -> V_265 ) ) ;
return - V_307 ;
}
if ( V_346 -> V_290 [ 0 ] != 0 )
return - V_307 ;
V_950 = F_181 ( V_16 , V_346 -> V_273 ,
V_346 -> V_265 ,
V_346 -> V_292 [ 0 ] ) ;
if ( V_303 -> V_40 . V_296 < V_950 * V_346 -> V_288 [ 0 ] )
return - V_307 ;
F_941 ( & V_952 -> V_40 , V_346 ) ;
V_952 -> V_303 = V_303 ;
V_952 -> V_303 -> V_1388 ++ ;
V_305 = F_942 ( V_16 , & V_952 -> V_40 , & V_1400 ) ;
if ( V_305 ) {
F_132 ( L_300 , V_305 ) ;
return V_305 ;
}
return 0 ;
}
static struct V_276 *
F_943 ( struct V_15 * V_16 ,
struct V_1347 * V_1401 ,
const struct V_345 * V_1402 )
{
struct V_276 * V_114 ;
struct V_302 * V_303 ;
struct V_345 V_346 = * V_1402 ;
V_303 = F_944 ( F_945 ( V_16 , V_1401 ,
V_346 . V_1403 [ 0 ] ) ) ;
if ( & V_303 -> V_40 == NULL )
return F_682 ( - V_1353 ) ;
V_114 = F_683 ( V_16 , & V_346 , V_303 ) ;
if ( F_467 ( V_114 ) )
F_691 ( & V_303 -> V_40 ) ;
return V_114 ;
}
static inline void F_946 ( struct V_15 * V_16 )
{
}
static void F_947 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_10 ( V_16 ) || F_31 ( V_16 ) )
V_2 -> V_449 . V_944 = F_45 ;
else if ( F_14 ( V_16 ) )
V_2 -> V_449 . V_944 = F_51 ;
else if ( F_13 ( V_16 ) )
V_2 -> V_449 . V_944 = F_49 ;
else if ( F_32 ( V_16 ) )
V_2 -> V_449 . V_944 = F_44 ;
else
V_2 -> V_449 . V_944 = F_43 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
V_2 -> V_449 . V_1287 = F_670 ;
V_2 -> V_449 . V_1404 =
F_638 ;
V_2 -> V_449 . V_1231 =
F_662 ;
V_2 -> V_449 . V_1312 = F_399 ;
V_2 -> V_449 . V_735 = F_410 ;
V_2 -> V_449 . V_450 =
F_251 ;
} else if ( F_71 ( V_16 ) ) {
V_2 -> V_449 . V_1287 = F_670 ;
V_2 -> V_449 . V_1404 =
F_641 ;
V_2 -> V_449 . V_1231 =
F_662 ;
V_2 -> V_449 . V_1312 = F_399 ;
V_2 -> V_449 . V_735 = F_410 ;
V_2 -> V_449 . V_450 =
F_234 ;
} else if ( F_10 ( V_16 ) ) {
V_2 -> V_449 . V_1287 = F_642 ;
V_2 -> V_449 . V_1404 =
F_641 ;
V_2 -> V_449 . V_1231 =
F_631 ;
V_2 -> V_449 . V_1312 = F_389 ;
V_2 -> V_449 . V_735 = F_407 ;
V_2 -> V_449 . V_450 =
F_234 ;
} else if ( F_13 ( V_16 ) || F_14 ( V_16 ) ) {
V_2 -> V_449 . V_1287 = F_599 ;
V_2 -> V_449 . V_1404 =
F_597 ;
V_2 -> V_449 . V_1231 = F_594 ;
V_2 -> V_449 . V_1312 = F_474 ;
V_2 -> V_449 . V_735 = F_485 ;
V_2 -> V_449 . V_450 =
F_222 ;
} else {
V_2 -> V_449 . V_1287 = F_599 ;
V_2 -> V_449 . V_1404 =
F_597 ;
V_2 -> V_449 . V_1231 = F_594 ;
V_2 -> V_449 . V_1312 = F_483 ;
V_2 -> V_449 . V_735 = F_485 ;
V_2 -> V_449 . V_450 =
F_222 ;
}
if ( F_431 ( V_16 ) || F_432 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_516 ;
else if ( F_30 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_517 ;
else if ( F_236 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_518 ;
else if ( F_235 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_519 ;
else if ( F_13 ( V_16 ) || F_14 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_521 ;
else if ( F_18 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_522 ;
else if ( F_585 ( V_16 ) || F_187 ( V_16 ) ||
F_300 ( V_16 ) || F_291 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_523 ;
else if ( F_535 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_537 ;
else if ( F_188 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_538 ;
else if ( F_32 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_526 ;
else if ( F_536 ( V_16 ) || F_31 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_539 ;
else if ( F_513 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_524 ;
else if ( F_586 ( V_16 ) || F_82 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_525 ;
else if ( F_948 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_528 ;
else if ( F_83 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_529 ;
else if ( F_949 ( V_16 ) )
V_2 -> V_449 . V_656 =
F_530 ;
else {
F_6 ( ! F_143 ( V_16 ) , L_301 ) ;
V_2 -> V_449 . V_656 =
F_533 ;
}
if ( F_18 ( V_16 ) ) {
V_2 -> V_449 . V_528 = F_292 ;
} else if ( F_300 ( V_16 ) ) {
V_2 -> V_449 . V_528 = F_298 ;
} else if ( F_291 ( V_16 ) ) {
V_2 -> V_449 . V_528 = F_301 ;
} else if ( F_235 ( V_16 ) || F_236 ( V_16 ) ) {
V_2 -> V_449 . V_528 = V_1405 ;
if ( F_236 ( V_16 ) ) {
V_2 -> V_449 . V_643 =
F_661 ;
V_2 -> V_449 . V_1296 =
F_660 ;
}
} else if ( F_13 ( V_16 ) || F_14 ( V_16 ) ) {
V_2 -> V_449 . V_643 =
F_473 ;
V_2 -> V_449 . V_1296 =
F_469 ;
} else if ( F_30 ( V_16 ) ) {
V_2 -> V_449 . V_643 =
F_657 ;
V_2 -> V_449 . V_1296 =
F_470 ;
}
switch ( F_60 ( V_16 ) -> V_127 ) {
case 2 :
V_2 -> V_449 . V_1213 = F_736 ;
break;
case 3 :
V_2 -> V_449 . V_1213 = F_740 ;
break;
case 4 :
case 5 :
V_2 -> V_449 . V_1213 = F_741 ;
break;
case 6 :
V_2 -> V_449 . V_1213 = F_742 ;
break;
case 7 :
case 8 :
V_2 -> V_449 . V_1213 = F_743 ;
break;
case 9 :
default:
V_2 -> V_449 . V_1213 = F_765 ;
}
F_950 ( & V_2 -> V_1406 ) ;
}
static void F_951 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_167 |= V_168 ;
F_952 ( L_302 ) ;
}
static void F_953 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_167 |= V_169 ;
F_952 ( L_303 ) ;
}
static void F_954 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_167 |= V_831 ;
F_952 ( L_304 ) ;
}
static void F_955 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_167 |= V_1407 ;
F_952 ( L_305 ) ;
}
static void F_956 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_167 |= V_1408 ;
F_952 ( L_306 ) ;
}
static int F_957 ( const struct V_1409 * V_241 )
{
F_952 ( L_307 , V_241 -> V_1410 ) ;
return 1 ;
}
static void F_958 ( struct V_15 * V_16 )
{
struct V_1411 * V_1412 = V_16 -> V_773 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < F_302 ( V_1413 ) ; V_50 ++ ) {
struct V_1414 * V_1415 = & V_1413 [ V_50 ] ;
if ( V_1412 -> V_1416 == V_1415 -> V_1416 &&
( V_1412 -> V_1417 == V_1415 -> V_1417 ||
V_1415 -> V_1417 == V_1418 ) &&
( V_1412 -> V_1419 == V_1415 -> V_1419 ||
V_1415 -> V_1419 == V_1418 ) )
V_1415 -> V_1420 ( V_16 ) ;
}
for ( V_50 = 0 ; V_50 < F_302 ( V_1421 ) ; V_50 ++ ) {
if ( F_959 ( * V_1421 [ V_50 ] . V_1422 ) != 0 )
V_1421 [ V_50 ] . V_1420 ( V_16 ) ;
}
}
static void F_960 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_13 V_1423 ;
T_5 V_1424 = F_961 ( V_16 ) ;
F_962 ( V_16 -> V_773 , V_1425 ) ;
F_963 ( V_1426 , V_1427 ) ;
V_1423 = F_964 ( V_1428 ) ;
F_963 ( V_1423 | 1 << 5 , V_1428 ) ;
F_965 ( V_16 -> V_773 , V_1425 ) ;
F_131 ( 300 ) ;
F_129 ( V_1424 , V_1429 ) ;
F_130 ( V_1424 ) ;
}
void F_274 ( struct V_15 * V_16 )
{
F_435 ( V_16 ) ;
F_656 ( V_16 ) ;
F_966 ( V_16 ) ;
F_967 ( V_16 ) ;
}
void F_968 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
int V_176 , V_305 ;
enum V_119 V_119 ;
struct V_37 * V_38 ;
F_969 ( V_16 ) ;
V_16 -> V_737 . V_1430 = 0 ;
V_16 -> V_737 . V_1431 = 0 ;
V_16 -> V_737 . V_1432 = 24 ;
V_16 -> V_737 . V_1433 = 1 ;
V_16 -> V_737 . V_1434 = true ;
V_16 -> V_737 . V_1122 = & V_1435 ;
F_958 ( V_16 ) ;
F_970 ( V_16 ) ;
if ( F_60 ( V_16 ) -> V_749 == 0 )
return;
if ( F_106 ( V_16 ) || F_107 ( V_16 ) ) {
bool V_1436 = ! ! ( F_11 ( V_181 ) &
V_973 ) ;
if ( V_2 -> V_829 . V_830 != V_1436 ) {
F_153 ( L_308 ,
V_1436 ? L_75 : L_76 ,
V_2 -> V_829 . V_830 ? L_75 : L_76 ) ;
V_2 -> V_829 . V_830 = V_1436 ;
}
}
F_947 ( V_16 ) ;
F_971 ( V_16 ) ;
if ( F_33 ( V_16 ) ) {
V_16 -> V_737 . V_1437 = 2048 ;
V_16 -> V_737 . V_1438 = 2048 ;
} else if ( F_972 ( V_16 ) ) {
V_16 -> V_737 . V_1437 = 4096 ;
V_16 -> V_737 . V_1438 = 4096 ;
} else {
V_16 -> V_737 . V_1437 = 8192 ;
V_16 -> V_737 . V_1438 = 8192 ;
}
if ( F_82 ( V_16 ) || F_83 ( V_16 ) ) {
V_16 -> V_737 . V_1439 = F_82 ( V_16 ) ? 64 : 512 ;
V_16 -> V_737 . V_1440 = 1023 ;
} else if ( F_33 ( V_16 ) ) {
V_16 -> V_737 . V_1439 = V_1441 ;
V_16 -> V_737 . V_1440 = V_1442 ;
} else {
V_16 -> V_737 . V_1439 = V_1443 ;
V_16 -> V_737 . V_1440 = V_1444 ;
}
V_16 -> V_737 . V_1445 = V_2 -> V_349 . V_1446 ;
F_153 ( L_309 ,
F_60 ( V_16 ) -> V_749 ,
F_60 ( V_16 ) -> V_749 > 1 ? L_310 : L_311 ) ;
F_93 (dev_priv, pipe) {
F_906 ( V_16 , V_119 ) ;
F_95 (dev_priv, pipe, sprite) {
V_305 = F_973 ( V_16 , V_119 , V_176 ) ;
if ( V_305 )
F_153 ( L_312 ,
F_80 ( V_119 ) , F_98 ( V_119 , V_176 ) , V_305 ) ;
}
}
F_15 ( V_2 ) ;
F_435 ( V_16 ) ;
F_876 ( V_16 ) ;
F_960 ( V_16 ) ;
F_919 ( V_16 ) ;
F_269 ( V_16 ) ;
F_974 ( V_16 ) ;
F_279 ( V_16 ) ;
F_140 (dev, crtc) {
struct V_343 V_344 = {} ;
if ( ! V_38 -> V_112 )
continue;
V_2 -> V_449 . V_1404 ( V_38 ,
& V_344 ) ;
F_214 ( V_38 , & V_344 ) ;
}
}
static void F_975 ( struct V_15 * V_16 )
{
struct V_744 * V_47 ;
struct V_46 * V_1447 = NULL ;
struct V_1113 V_1120 ;
struct V_738 * V_739 = V_16 -> V_737 . V_740 ;
F_800 (dev, connector) {
if ( V_47 -> V_42 -> type == V_64 ) {
V_1447 = & V_47 -> V_40 ;
break;
}
}
if ( ! V_1447 )
return;
if ( F_699 ( V_1447 , NULL , & V_1120 , V_739 ) )
F_705 ( V_1447 , & V_1120 , V_739 ) ;
}
static bool
F_976 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 ;
if ( F_60 ( V_16 ) -> V_749 == 1 )
return true ;
V_10 = F_11 ( F_90 ( ! V_38 -> V_171 ) ) ;
if ( ( V_10 & V_172 ) &&
( ! ! ( V_10 & V_174 ) == V_38 -> V_119 ) )
return false ;
return true ;
}
static bool F_977 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_41 * V_42 ;
F_22 (dev, &crtc->base, encoder)
return true ;
return false ;
}
static void F_978 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_5 V_9 = F_61 ( V_38 -> V_115 -> V_121 ) ;
F_129 ( V_9 , F_11 ( V_9 ) & ~ V_1448 ) ;
F_979 ( & V_38 -> V_40 ) ;
if ( V_38 -> V_112 ) {
struct V_359 * V_171 ;
F_395 ( & V_38 -> V_40 ) ;
F_980 (dev, crtc, plane) {
if ( V_171 -> V_40 . type == V_1225 )
continue;
V_171 -> V_363 ( & V_171 -> V_40 , & V_38 -> V_40 ) ;
}
}
if ( F_60 ( V_16 ) -> V_127 < 4 && ! F_976 ( V_38 ) ) {
bool V_171 ;
F_153 ( L_313 ,
V_38 -> V_40 . V_40 . V_241 ) ;
V_171 = V_38 -> V_171 ;
F_219 ( V_38 -> V_40 . V_113 -> V_36 ) -> V_361 = true ;
V_38 -> V_171 = ! V_171 ;
F_486 ( & V_38 -> V_40 ) ;
V_38 -> V_171 = V_171 ;
}
if ( V_2 -> V_167 & V_168 &&
V_38 -> V_119 == V_148 && ! V_38 -> V_112 ) {
F_975 ( V_16 ) ;
}
if ( ! F_977 ( V_38 ) )
F_486 ( & V_38 -> V_40 ) ;
if ( V_38 -> V_112 != V_38 -> V_40 . V_36 -> V_112 ) {
struct V_41 * V_42 ;
F_153 ( L_314 ,
V_38 -> V_40 . V_40 . V_241 ,
V_38 -> V_40 . V_36 -> V_243 ? L_220 : L_221 ,
V_38 -> V_112 ? L_220 : L_221 ) ;
F_9 ( F_981 ( V_38 -> V_40 . V_36 , NULL ) < 0 ) ;
V_38 -> V_40 . V_36 -> V_112 = V_38 -> V_112 ;
V_38 -> V_40 . V_129 = V_38 -> V_112 ;
V_38 -> V_40 . V_36 -> V_1449 = 0 ;
F_9 ( V_38 -> V_112 ) ;
F_22 (dev, &crtc->base, encoder)
V_42 -> V_40 . V_38 = NULL ;
}
if ( V_38 -> V_112 || F_170 ( V_16 ) ) {
V_38 -> V_1450 = true ;
V_38 -> V_1451 = true ;
}
}
static void F_982 ( struct V_41 * V_42 )
{
struct V_744 * V_47 ;
struct V_15 * V_16 = V_42 -> V_40 . V_16 ;
bool V_112 = false ;
bool V_1452 = V_42 -> V_40 . V_38 &&
F_50 ( V_42 -> V_40 . V_38 ) -> V_112 ;
F_800 (dev, connector) {
if ( V_47 -> V_40 . V_42 != & V_42 -> V_40 )
continue;
V_112 = true ;
break;
}
if ( V_112 && ! V_1452 ) {
F_153 ( L_315 ,
V_42 -> V_40 . V_40 . V_241 ,
V_42 -> V_40 . V_8 ) ;
if ( V_42 -> V_40 . V_38 ) {
F_153 ( L_316 ,
V_42 -> V_40 . V_40 . V_241 ,
V_42 -> V_40 . V_8 ) ;
V_42 -> V_244 ( V_42 ) ;
if ( V_42 -> V_609 )
V_42 -> V_609 ( V_42 ) ;
}
V_42 -> V_40 . V_38 = NULL ;
F_800 (dev, connector) {
if ( V_47 -> V_42 != V_42 )
continue;
V_47 -> V_40 . V_1119 = V_1453 ;
V_47 -> V_40 . V_42 = NULL ;
}
}
}
void F_983 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_5 V_1424 = F_961 ( V_16 ) ;
if ( ! ( F_11 ( V_1424 ) & V_1429 ) ) {
F_153 ( L_317 ) ;
F_960 ( V_16 ) ;
}
}
void F_984 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! F_87 ( V_2 , V_1454 ) )
return;
F_983 ( V_16 ) ;
F_88 ( V_2 , V_1454 ) ;
}
static bool F_985 ( struct V_359 * V_171 )
{
struct V_1 * V_2 = F_204 ( V_171 -> V_40 . V_16 ) ;
return F_11 ( F_90 ( V_171 -> V_171 ) ) & V_172 ;
}
static void F_986 ( struct V_37 * V_38 )
{
struct V_301 * V_113 = V_38 -> V_40 . V_113 ;
struct V_431 * V_278 =
F_219 ( V_113 -> V_36 ) ;
V_278 -> V_361 = V_38 -> V_112 &&
F_985 ( F_215 ( V_113 ) ) ;
if ( V_278 -> V_361 )
V_38 -> V_40 . V_36 -> V_362 |= 1 << F_220 ( V_113 ) ;
}
static void F_987 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 ;
struct V_37 * V_38 ;
struct V_41 * V_42 ;
struct V_744 * V_47 ;
int V_50 ;
F_140 (dev, crtc) {
F_838 ( & V_38 -> V_40 , V_38 -> V_40 . V_36 ) ;
memset ( V_38 -> V_115 , 0 , sizeof( * V_38 -> V_115 ) ) ;
V_38 -> V_115 -> V_40 . V_38 = & V_38 -> V_40 ;
V_38 -> V_112 = V_2 -> V_449 . V_1287 ( V_38 ,
V_38 -> V_115 ) ;
V_38 -> V_40 . V_36 -> V_112 = V_38 -> V_112 ;
V_38 -> V_40 . V_129 = V_38 -> V_112 ;
F_986 ( V_38 ) ;
F_153 ( L_318 ,
V_38 -> V_40 . V_40 . V_241 ,
V_38 -> V_112 ? L_220 : L_221 ) ;
}
for ( V_50 = 0 ; V_50 < V_2 -> V_544 ; V_50 ++ ) {
struct V_134 * V_137 = & V_2 -> V_136 [ V_50 ] ;
V_137 -> V_239 = V_137 -> V_140 ( V_2 , V_137 ,
& V_137 -> V_115 . V_139 ) ;
V_137 -> V_112 = 0 ;
V_137 -> V_115 . V_238 = 0 ;
F_140 (dev, crtc) {
if ( V_38 -> V_112 && F_68 ( V_38 ) == V_137 ) {
V_137 -> V_112 ++ ;
V_137 -> V_115 . V_238 |= 1 << V_38 -> V_119 ;
}
}
F_153 ( L_319 ,
V_137 -> V_8 , V_137 -> V_115 . V_238 , V_137 -> V_239 ) ;
if ( V_137 -> V_115 . V_238 )
F_155 ( V_2 , V_242 ) ;
}
F_602 (dev, encoder) {
V_119 = 0 ;
if ( V_42 -> V_140 ( V_42 , & V_119 ) ) {
V_38 = F_50 ( V_2 -> V_120 [ V_119 ] ) ;
V_42 -> V_40 . V_38 = & V_38 -> V_40 ;
V_42 -> V_1288 ( V_42 , V_38 -> V_115 ) ;
} else {
V_42 -> V_40 . V_38 = NULL ;
}
F_153 ( L_320 ,
V_42 -> V_40 . V_40 . V_241 ,
V_42 -> V_40 . V_8 ,
V_42 -> V_40 . V_38 ? L_220 : L_221 ,
F_80 ( V_119 ) ) ;
}
F_800 (dev, connector) {
if ( V_47 -> V_140 ( V_47 ) ) {
V_47 -> V_40 . V_1119 = V_1121 ;
V_42 = V_47 -> V_42 ;
V_47 -> V_40 . V_42 = & V_42 -> V_40 ;
if ( V_42 -> V_40 . V_38 &&
V_42 -> V_40 . V_38 -> V_36 -> V_112 ) {
V_42 -> V_40 . V_38 -> V_36 -> V_1449 |=
1 << F_988 ( & V_47 -> V_40 ) ;
}
} else {
V_47 -> V_40 . V_1119 = V_1453 ;
V_47 -> V_40 . V_42 = NULL ;
}
F_153 ( L_321 ,
V_47 -> V_40 . V_40 . V_241 ,
V_47 -> V_40 . V_8 ,
V_47 -> V_40 . V_42 ? L_220 : L_221 ) ;
}
F_140 (dev, crtc) {
V_38 -> V_40 . V_1265 = V_38 -> V_115 -> V_40 . V_116 ;
memset ( & V_38 -> V_40 . V_445 , 0 , sizeof( V_38 -> V_40 . V_445 ) ) ;
if ( V_38 -> V_40 . V_36 -> V_112 ) {
F_589 ( & V_38 -> V_40 . V_445 , V_38 -> V_115 ) ;
F_589 ( & V_38 -> V_40 . V_36 -> V_116 , V_38 -> V_115 ) ;
F_9 ( F_981 ( V_38 -> V_40 . V_36 , & V_38 -> V_40 . V_445 ) ) ;
V_38 -> V_40 . V_36 -> V_445 . V_1306 = V_1455 ;
F_989 ( & V_38 -> V_40 , & V_38 -> V_40 . V_1265 ) ;
F_843 ( V_38 ) ;
}
}
}
static void
F_974 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 ;
struct V_37 * V_38 ;
struct V_41 * V_42 ;
int V_50 ;
F_987 ( V_16 ) ;
F_602 (dev, encoder) {
F_982 ( V_42 ) ;
}
F_93 (dev_priv, pipe) {
V_38 = F_50 ( V_2 -> V_120 [ V_119 ] ) ;
F_978 ( V_38 ) ;
F_805 ( V_38 , V_38 -> V_115 ,
L_322 ) ;
}
F_799 ( V_16 ) ;
for ( V_50 = 0 ; V_50 < V_2 -> V_544 ; V_50 ++ ) {
struct V_134 * V_137 = & V_2 -> V_136 [ V_50 ] ;
if ( ! V_137 -> V_239 || V_137 -> V_112 )
continue;
F_153 ( L_323 , V_137 -> V_8 ) ;
V_137 -> V_244 ( V_2 , V_137 ) ;
V_137 -> V_239 = false ;
}
if ( F_13 ( V_16 ) || F_14 ( V_16 ) )
F_990 ( V_16 ) ;
else if ( F_991 ( V_16 ) )
F_992 ( V_16 ) ;
else if ( F_10 ( V_16 ) )
F_993 ( V_16 ) ;
F_140 (dev, crtc) {
unsigned long V_641 ;
V_641 = F_424 ( & V_38 -> V_40 ) ;
if ( F_9 ( V_641 ) )
F_426 ( V_2 , V_641 ) ;
}
F_994 ( V_2 , false ) ;
}
void F_277 ( struct V_15 * V_16 )
{
struct V_45 * V_36 = F_488 ( V_16 ) ;
struct V_744 * V_1456 ;
struct V_359 * V_171 ;
struct V_111 * V_38 ;
int V_305 ;
if ( ! V_36 )
return;
V_36 -> V_740 = V_16 -> V_737 . V_740 ;
F_352 ( V_36 ) ;
F_217 (dev, crtc) {
struct V_35 * V_44 =
F_489 ( V_36 , V_38 ) ;
V_305 = F_490 ( V_44 ) ;
if ( V_305 )
goto V_98;
V_44 -> V_1218 = true ;
}
F_995 (dev, plane) {
V_305 = F_490 ( F_695 ( V_36 , & V_171 -> V_40 ) ) ;
if ( V_305 )
goto V_98;
}
F_800 (dev, conn) {
V_305 = F_490 ( F_702 ( V_36 , & V_1456 -> V_40 ) ) ;
if ( V_305 )
goto V_98;
}
F_974 ( V_16 ) ;
F_984 ( V_16 ) ;
V_305 = F_491 ( V_36 ) ;
if ( ! V_305 )
return;
V_98:
F_132 ( L_324 , V_305 ) ;
F_492 ( V_36 ) ;
}
void F_996 ( struct V_15 * V_16 )
{
struct V_111 * V_358 ;
struct V_302 * V_303 ;
int V_305 ;
F_2 ( & V_16 -> V_306 ) ;
F_997 ( V_16 ) ;
F_4 ( & V_16 -> V_306 ) ;
F_274 ( V_16 ) ;
F_998 ( V_16 ) ;
F_217 (dev, c) {
V_303 = F_190 ( V_358 -> V_113 -> V_114 ) ;
if ( V_303 == NULL )
continue;
F_2 ( & V_16 -> V_306 ) ;
V_305 = F_189 ( V_358 -> V_113 ,
V_358 -> V_113 -> V_114 ,
V_358 -> V_113 -> V_36 ) ;
F_4 ( & V_16 -> V_306 ) ;
if ( V_305 ) {
F_132 ( L_325 ,
F_50 ( V_358 ) -> V_119 ) ;
F_212 ( V_358 -> V_113 -> V_114 ) ;
V_358 -> V_113 -> V_114 = NULL ;
V_358 -> V_113 -> V_38 = V_358 -> V_113 -> V_36 -> V_38 = NULL ;
F_211 ( V_358 -> V_113 ) ;
V_358 -> V_36 -> V_362 &= ~ ( 1 << F_220 ( V_358 -> V_113 ) ) ;
}
}
F_999 ( V_16 ) ;
}
void F_1000 ( struct V_744 * V_744 )
{
struct V_46 * V_47 = & V_744 -> V_40 ;
F_1001 ( V_47 ) ;
F_1002 ( V_47 ) ;
}
void F_1003 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_744 * V_47 ;
F_1004 ( V_16 ) ;
F_1005 ( V_16 ) ;
F_1006 ( V_2 ) ;
F_1007 ( V_16 ) ;
F_1008 () ;
F_1009 ( V_2 ) ;
F_1010 () ;
F_800 (dev, connector)
V_47 -> V_1457 ( V_47 ) ;
F_1011 ( V_16 ) ;
F_1012 ( V_16 ) ;
F_2 ( & V_16 -> V_306 ) ;
F_1013 ( V_16 ) ;
F_4 ( & V_16 -> V_306 ) ;
F_1014 ( V_16 ) ;
}
struct V_743 * F_1015 ( struct V_46 * V_47 )
{
return & F_700 ( V_47 ) -> V_40 ;
}
void F_1016 ( struct V_744 * V_47 ,
struct V_41 * V_42 )
{
V_47 -> V_42 = V_42 ;
F_1017 ( & V_47 -> V_40 ,
& V_42 -> V_40 ) ;
}
int F_1018 ( struct V_15 * V_16 , bool V_36 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
unsigned V_9 = F_60 ( V_16 ) -> V_127 >= 6 ? V_1458 : V_1459 ;
T_7 V_1460 ;
if ( F_527 ( V_2 -> V_1461 , V_9 , & V_1460 ) ) {
F_132 ( L_326 ) ;
return - V_1214 ;
}
if ( ! ! ( V_1460 & V_1462 ) == ! V_36 )
return 0 ;
if ( V_36 )
V_1460 &= ~ V_1462 ;
else
V_1460 |= V_1462 ;
if ( F_1019 ( V_2 -> V_1461 , V_9 , V_1460 ) ) {
F_132 ( L_327 ) ;
return - V_1214 ;
}
return 0 ;
}
struct V_1463 *
F_1020 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_1463 * error ;
int V_1464 [] = {
V_256 ,
V_1465 ,
V_1466 ,
V_604 ,
} ;
int V_50 ;
if ( F_60 ( V_16 ) -> V_749 == 0 )
return NULL ;
error = F_499 ( sizeof( * error ) , V_1467 ) ;
if ( error == NULL )
return NULL ;
if ( F_235 ( V_16 ) || F_236 ( V_16 ) )
error -> V_1468 = F_11 ( V_1026 ) ;
F_93 (dev_priv, i) {
error -> V_119 [ V_50 ] . V_1469 =
F_1021 ( V_2 ,
F_422 ( V_50 ) ) ;
if ( ! error -> V_119 [ V_50 ] . V_1469 )
continue;
error -> V_1089 [ V_50 ] . V_612 = F_11 ( F_84 ( V_50 ) ) ;
error -> V_1089 [ V_50 ] . V_1470 = F_11 ( F_678 ( V_50 ) ) ;
error -> V_1089 [ V_50 ] . V_40 = F_11 ( F_675 ( V_50 ) ) ;
error -> V_171 [ V_50 ] . V_612 = F_11 ( F_90 ( V_50 ) ) ;
error -> V_171 [ V_50 ] . V_353 = F_11 ( F_231 ( V_50 ) ) ;
if ( F_60 ( V_16 ) -> V_127 <= 3 ) {
error -> V_171 [ V_50 ] . V_296 = F_11 ( F_225 ( V_50 ) ) ;
error -> V_171 [ V_50 ] . V_566 = F_11 ( F_226 ( V_50 ) ) ;
}
if ( F_60 ( V_16 ) -> V_127 <= 7 && ! F_235 ( V_16 ) )
error -> V_171 [ V_50 ] . V_1199 = F_11 ( F_224 ( V_50 ) ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
error -> V_171 [ V_50 ] . V_1471 = F_11 ( F_223 ( V_50 ) ) ;
error -> V_171 [ V_50 ] . V_1472 = F_11 ( F_232 ( V_50 ) ) ;
}
error -> V_119 [ V_50 ] . V_1473 = F_11 ( F_286 ( V_50 ) ) ;
if ( F_170 ( V_16 ) )
error -> V_119 [ V_50 ] . V_1474 = F_11 ( F_1022 ( V_50 ) ) ;
}
error -> V_1475 = F_60 ( V_16 ) -> V_749 ;
if ( F_71 ( V_2 -> V_16 ) )
error -> V_1475 ++ ;
for ( V_50 = 0 ; V_50 < error -> V_1475 ; V_50 ++ ) {
enum V_118 V_121 = V_1464 [ V_50 ] ;
error -> V_118 [ V_50 ] . V_1469 =
F_1021 ( V_2 ,
F_86 ( V_121 ) ) ;
if ( ! error -> V_118 [ V_50 ] . V_1469 )
continue;
error -> V_118 [ V_50 ] . V_121 = V_121 ;
error -> V_118 [ V_50 ] . V_1476 = F_11 ( F_61 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_921 = F_11 ( F_327 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_1477 = F_11 ( F_329 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_928 = F_11 ( F_331 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_924 = F_11 ( F_333 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_1478 = F_11 ( F_335 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_1147 = F_11 ( F_337 ( V_121 ) ) ;
}
return error ;
}
void
F_1023 ( struct V_1479 * V_79 ,
struct V_15 * V_16 ,
struct V_1463 * error )
{
struct V_1 * V_2 = V_16 -> V_17 ;
int V_50 ;
if ( ! error )
return;
F_1024 ( V_79 , L_328 , F_60 ( V_16 ) -> V_749 ) ;
if ( F_235 ( V_16 ) || F_236 ( V_16 ) )
F_1024 ( V_79 , L_329 ,
error -> V_1468 ) ;
F_93 (dev_priv, i) {
F_1024 ( V_79 , L_330 , V_50 ) ;
F_1024 ( V_79 , L_331 ,
error -> V_119 [ V_50 ] . V_1469 ? L_14 : L_15 ) ;
F_1024 ( V_79 , L_332 , error -> V_119 [ V_50 ] . V_1473 ) ;
F_1024 ( V_79 , L_333 , error -> V_119 [ V_50 ] . V_1474 ) ;
F_1024 ( V_79 , L_334 , V_50 ) ;
F_1024 ( V_79 , L_335 , error -> V_171 [ V_50 ] . V_612 ) ;
F_1024 ( V_79 , L_336 , error -> V_171 [ V_50 ] . V_353 ) ;
if ( F_60 ( V_16 ) -> V_127 <= 3 ) {
F_1024 ( V_79 , L_337 , error -> V_171 [ V_50 ] . V_296 ) ;
F_1024 ( V_79 , L_338 , error -> V_171 [ V_50 ] . V_566 ) ;
}
if ( F_60 ( V_16 ) -> V_127 <= 7 && ! F_235 ( V_16 ) )
F_1024 ( V_79 , L_339 , error -> V_171 [ V_50 ] . V_1199 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
F_1024 ( V_79 , L_340 , error -> V_171 [ V_50 ] . V_1471 ) ;
F_1024 ( V_79 , L_341 , error -> V_171 [ V_50 ] . V_1472 ) ;
}
F_1024 ( V_79 , L_342 , V_50 ) ;
F_1024 ( V_79 , L_335 , error -> V_1089 [ V_50 ] . V_612 ) ;
F_1024 ( V_79 , L_338 , error -> V_1089 [ V_50 ] . V_1470 ) ;
F_1024 ( V_79 , L_343 , error -> V_1089 [ V_50 ] . V_40 ) ;
}
for ( V_50 = 0 ; V_50 < error -> V_1475 ; V_50 ++ ) {
F_1024 ( V_79 , L_344 ,
F_806 ( error -> V_118 [ V_50 ] . V_121 ) ) ;
F_1024 ( V_79 , L_331 ,
error -> V_118 [ V_50 ] . V_1469 ? L_14 : L_15 ) ;
F_1024 ( V_79 , L_345 , error -> V_118 [ V_50 ] . V_1476 ) ;
F_1024 ( V_79 , L_346 , error -> V_118 [ V_50 ] . V_921 ) ;
F_1024 ( V_79 , L_347 , error -> V_118 [ V_50 ] . V_1477 ) ;
F_1024 ( V_79 , L_348 , error -> V_118 [ V_50 ] . V_928 ) ;
F_1024 ( V_79 , L_349 , error -> V_118 [ V_50 ] . V_924 ) ;
F_1024 ( V_79 , L_350 , error -> V_118 [ V_50 ] . V_1478 ) ;
F_1024 ( V_79 , L_351 , error -> V_118 [ V_50 ] . V_1147 ) ;
}
}
void F_1025 ( struct V_15 * V_16 , struct V_1347 * V_1348 )
{
struct V_37 * V_38 ;
F_140 (dev, crtc) {
struct V_495 * V_496 ;
F_275 ( & V_16 -> V_457 ) ;
V_496 = V_38 -> V_458 ;
if ( V_496 && V_496 -> V_497 &&
V_496 -> V_497 -> V_40 . V_1480 == V_1348 ) {
F_216 ( V_496 -> V_497 ) ;
V_496 -> V_497 = NULL ;
}
F_276 ( & V_16 -> V_457 ) ;
}
}
