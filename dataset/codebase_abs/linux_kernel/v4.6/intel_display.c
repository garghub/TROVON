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
void F_63 ( struct V_1 * V_2 ,
enum V_119 V_119 , bool V_36 )
{
T_1 V_10 ;
bool V_129 ;
V_10 = F_11 ( F_64 ( V_119 ) ) ;
V_129 = ! ! ( V_10 & V_130 ) ;
F_65 ( V_129 != V_36 ,
L_14 ,
F_66 ( V_36 ) , F_66 ( V_129 ) ) ;
}
static void F_67 ( struct V_1 * V_2 , bool V_36 )
{
T_1 V_10 ;
bool V_129 ;
F_2 ( & V_2 -> V_5 ) ;
V_10 = F_3 ( V_2 , V_131 ) ;
F_4 ( & V_2 -> V_5 ) ;
V_129 = V_10 & V_132 ;
F_65 ( V_129 != V_36 ,
L_15 ,
F_66 ( V_36 ) , F_66 ( V_129 ) ) ;
}
struct V_133 *
F_68 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_40 . V_16 -> V_17 ;
if ( V_38 -> V_115 -> V_134 < 0 )
return NULL ;
return & V_2 -> V_135 [ V_38 -> V_115 -> V_134 ] ;
}
void F_69 ( struct V_1 * V_2 ,
struct V_133 * V_136 ,
bool V_36 )
{
bool V_129 ;
struct V_137 V_138 ;
if ( F_6 ( ! V_136 , L_16 , F_66 ( V_36 ) ) )
return;
V_129 = V_136 -> V_139 ( V_2 , V_136 , & V_138 ) ;
F_65 ( V_129 != V_36 ,
L_17 ,
V_136 -> V_8 , F_66 ( V_36 ) , F_66 ( V_129 ) ) ;
}
static void F_70 ( struct V_1 * V_2 ,
enum V_119 V_119 , bool V_36 )
{
bool V_129 ;
enum V_118 V_121 = F_55 ( V_2 ,
V_119 ) ;
if ( F_71 ( V_2 -> V_16 ) ) {
T_1 V_10 = F_11 ( F_72 ( V_121 ) ) ;
V_129 = ! ! ( V_10 & V_140 ) ;
} else {
T_1 V_10 = F_11 ( F_73 ( V_119 ) ) ;
V_129 = ! ! ( V_10 & V_141 ) ;
}
F_65 ( V_129 != V_36 ,
L_18 ,
F_66 ( V_36 ) , F_66 ( V_129 ) ) ;
}
static void F_74 ( struct V_1 * V_2 ,
enum V_119 V_119 , bool V_36 )
{
T_1 V_10 ;
bool V_129 ;
V_10 = F_11 ( F_75 ( V_119 ) ) ;
V_129 = ! ! ( V_10 & V_142 ) ;
F_65 ( V_129 != V_36 ,
L_19 ,
F_66 ( V_36 ) , F_66 ( V_129 ) ) ;
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
F_65 ( ! ( V_10 & V_143 ) , L_20 ) ;
}
void F_77 ( struct V_1 * V_2 ,
enum V_119 V_119 , bool V_36 )
{
T_1 V_10 ;
bool V_129 ;
V_10 = F_11 ( F_75 ( V_119 ) ) ;
V_129 = ! ! ( V_10 & V_144 ) ;
F_65 ( V_129 != V_36 ,
L_21 ,
F_66 ( V_36 ) , F_66 ( V_129 ) ) ;
}
void F_78 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_5 V_145 ;
T_1 V_10 ;
enum V_119 V_146 = V_147 ;
bool V_148 = true ;
if ( F_9 ( F_71 ( V_16 ) ) )
return;
if ( F_10 ( V_16 ) ) {
T_1 V_149 ;
V_145 = V_150 ;
V_149 = F_11 ( V_151 ) & V_152 ;
if ( V_149 == V_153 &&
F_11 ( V_154 ) & V_155 )
V_146 = V_156 ;
} else if ( F_13 ( V_16 ) || F_14 ( V_16 ) ) {
V_145 = F_79 ( V_119 ) ;
V_146 = V_119 ;
} else {
V_145 = V_157 ;
if ( F_11 ( V_158 ) & V_155 )
V_146 = V_156 ;
}
V_10 = F_11 ( V_145 ) ;
if ( ! ( V_10 & V_159 ) ||
( ( V_10 & V_160 ) == V_161 ) )
V_148 = false ;
F_65 ( V_146 == V_119 && V_148 ,
L_22 ,
F_80 ( V_119 ) ) ;
}
static void F_81 ( struct V_1 * V_2 ,
enum V_119 V_119 , bool V_36 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
bool V_129 ;
if ( F_82 ( V_16 ) || F_83 ( V_16 ) )
V_129 = F_11 ( F_84 ( V_147 ) ) & V_162 ;
else
V_129 = F_11 ( F_84 ( V_119 ) ) & V_163 ;
F_65 ( V_129 != V_36 ,
L_23 ,
F_80 ( V_119 ) , F_66 ( V_36 ) , F_66 ( V_129 ) ) ;
}
void F_85 ( struct V_1 * V_2 ,
enum V_119 V_119 , bool V_36 )
{
bool V_129 ;
enum V_118 V_121 = F_55 ( V_2 ,
V_119 ) ;
enum V_164 V_165 ;
if ( ( V_119 == V_147 && V_2 -> V_166 & V_167 ) ||
( V_119 == V_156 && V_2 -> V_166 & V_168 ) )
V_36 = true ;
V_165 = F_86 ( V_121 ) ;
if ( F_87 ( V_2 , V_165 ) ) {
T_1 V_10 = F_11 ( F_61 ( V_121 ) ) ;
V_129 = ! ! ( V_10 & V_169 ) ;
F_88 ( V_2 , V_165 ) ;
} else {
V_129 = false ;
}
F_65 ( V_129 != V_36 ,
L_24 ,
F_80 ( V_119 ) , F_66 ( V_36 ) , F_66 ( V_129 ) ) ;
}
static void F_89 ( struct V_1 * V_2 ,
enum V_170 V_170 , bool V_36 )
{
T_1 V_10 ;
bool V_129 ;
V_10 = F_11 ( F_90 ( V_170 ) ) ;
V_129 = ! ! ( V_10 & V_171 ) ;
F_65 ( V_129 != V_36 ,
L_25 ,
F_91 ( V_170 ) , F_66 ( V_36 ) , F_66 ( V_129 ) ) ;
}
static void F_92 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_50 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
T_1 V_10 = F_11 ( F_90 ( V_119 ) ) ;
F_65 ( V_10 & V_171 ,
L_26 ,
F_91 ( V_119 ) ) ;
return;
}
F_93 (dev_priv, i) {
T_1 V_10 = F_11 ( F_90 ( V_50 ) ) ;
enum V_119 V_172 = ( V_10 & V_173 ) >>
V_174 ;
F_65 ( ( V_10 & V_171 ) && V_119 == V_172 ,
L_27 ,
F_91 ( V_50 ) , F_80 ( V_119 ) ) ;
}
}
static void F_94 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_175 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
F_95 (dev_priv, pipe, sprite) {
T_1 V_10 = F_11 ( F_96 ( V_119 , V_175 ) ) ;
F_65 ( V_10 & V_176 ,
L_28 ,
V_175 , F_80 ( V_119 ) ) ;
}
} else if ( F_13 ( V_16 ) || F_14 ( V_16 ) ) {
F_95 (dev_priv, pipe, sprite) {
T_1 V_10 = F_11 ( F_97 ( V_119 , V_175 ) ) ;
F_65 ( V_10 & V_177 ,
L_29 ,
F_98 ( V_119 , V_175 ) , F_80 ( V_119 ) ) ;
}
} else if ( F_60 ( V_16 ) -> V_127 >= 7 ) {
T_1 V_10 = F_11 ( F_99 ( V_119 ) ) ;
F_65 ( V_10 & V_178 ,
L_29 ,
F_91 ( V_119 ) , F_80 ( V_119 ) ) ;
} else if ( F_60 ( V_16 ) -> V_127 >= 5 ) {
T_1 V_10 = F_11 ( F_100 ( V_119 ) ) ;
F_65 ( V_10 & V_179 ,
L_29 ,
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
bool V_180 ;
F_102 ( ! ( F_106 ( V_2 -> V_16 ) || F_107 ( V_2 -> V_16 ) ) ) ;
V_10 = F_11 ( V_181 ) ;
V_180 = ! ! ( V_10 & ( V_182 | V_183 |
V_184 ) ) ;
F_65 ( ! V_180 , L_30 ) ;
}
static void F_108 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
T_1 V_10 ;
bool V_180 ;
V_10 = F_11 ( F_109 ( V_119 ) ) ;
V_180 = ! ! ( V_10 & V_185 ) ;
F_65 ( V_180 ,
L_31 ,
F_80 ( V_119 ) ) ;
}
static bool F_110 ( struct V_1 * V_2 ,
enum V_119 V_119 , T_1 V_149 , T_1 V_10 )
{
if ( ( V_10 & V_186 ) == 0 )
return false ;
if ( F_107 ( V_2 -> V_16 ) ) {
T_1 V_187 = F_11 ( F_111 ( V_119 ) ) ;
if ( ( V_187 & V_188 ) != V_149 )
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
T_1 V_149 )
{
T_1 V_10 = F_11 ( V_9 ) ;
F_65 ( F_110 ( V_2 , V_119 , V_149 , V_10 ) ,
L_32 ,
F_123 ( V_9 ) , F_80 ( V_119 ) ) ;
F_65 ( F_106 ( V_2 -> V_16 ) && ( V_10 & V_186 ) == 0
&& ( V_10 & V_200 ) ,
L_33 ) ;
}
static void F_124 ( struct V_1 * V_2 ,
enum V_119 V_119 , T_5 V_9 )
{
T_1 V_10 = F_11 ( V_9 ) ;
F_65 ( F_113 ( V_2 , V_119 , V_10 ) ,
L_34 ,
F_123 ( V_9 ) , F_80 ( V_119 ) ) ;
F_65 ( F_106 ( V_2 -> V_16 ) && ( V_10 & V_191 ) == 0
&& ( V_10 & V_201 ) ,
L_35 ) ;
}
static void F_125 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
T_1 V_10 ;
F_122 ( V_2 , V_119 , V_202 , V_203 ) ;
F_122 ( V_2 , V_119 , V_204 , V_205 ) ;
F_122 ( V_2 , V_119 , V_206 , V_207 ) ;
V_10 = F_11 ( V_208 ) ;
F_65 ( F_120 ( V_2 , V_119 , V_10 ) ,
L_36 ,
F_80 ( V_119 ) ) ;
V_10 = F_11 ( V_154 ) ;
F_65 ( F_117 ( V_2 , V_119 , V_10 ) ,
L_37 ,
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
T_5 V_9 = F_64 ( V_38 -> V_119 ) ;
T_1 V_87 = V_212 -> V_213 . V_87 ;
F_127 ( V_2 , V_38 -> V_119 ) ;
if ( F_128 ( V_2 -> V_16 ) )
F_78 ( V_2 , V_38 -> V_119 ) ;
F_129 ( V_9 , V_87 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
if ( F_62 ( ( ( F_11 ( V_9 ) & V_214 ) == V_214 ) , 1 ) )
F_132 ( L_38 , V_38 -> V_119 ) ;
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
F_129 ( F_64 ( V_119 ) , V_212 -> V_213 . V_87 ) ;
if ( F_62 ( ( ( F_11 ( F_64 ( V_119 ) ) & V_214 ) == V_214 ) , 1 ) )
F_132 ( L_39 , V_119 ) ;
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
T_5 V_9 = F_64 ( V_38 -> V_119 ) ;
T_1 V_87 = V_38 -> V_115 -> V_213 . V_87 ;
F_127 ( V_2 , V_38 -> V_119 ) ;
F_142 ( F_60 ( V_16 ) -> V_127 >= 5 ) ;
if ( F_128 ( V_16 ) && ! F_143 ( V_16 ) )
F_78 ( V_2 , V_38 -> V_119 ) ;
if ( F_143 ( V_16 ) && F_139 ( V_16 ) > 0 ) {
V_87 |= V_221 ;
F_129 ( F_64 ( ! V_38 -> V_119 ) ,
F_11 ( F_64 ( ! V_38 -> V_119 ) ) | V_221 ) ;
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
F_129 ( F_64 ( V_156 ) ,
F_11 ( F_64 ( V_156 ) ) & ~ V_221 ) ;
F_129 ( F_64 ( V_147 ) ,
F_11 ( F_64 ( V_147 ) ) & ~ V_221 ) ;
}
if ( ( V_119 == V_147 && V_2 -> V_166 & V_167 ) ||
( V_119 == V_156 && V_2 -> V_166 & V_168 ) )
return;
F_127 ( V_2 , V_119 ) ;
F_129 ( F_64 ( V_119 ) , V_222 ) ;
F_130 ( F_64 ( V_119 ) ) ;
}
static void F_145 ( struct V_1 * V_2 , enum V_119 V_119 )
{
T_1 V_10 ;
F_127 ( V_2 , V_119 ) ;
V_10 = V_222 ;
if ( V_119 == V_156 )
V_10 = V_223 | V_224 ;
F_129 ( F_64 ( V_119 ) , V_10 ) ;
F_130 ( F_64 ( V_119 ) ) ;
}
static void F_146 ( struct V_1 * V_2 , enum V_119 V_119 )
{
enum V_216 V_217 = F_135 ( V_119 ) ;
T_1 V_10 ;
F_127 ( V_2 , V_119 ) ;
V_10 = V_225 |
V_224 | V_222 ;
if ( V_119 != V_147 )
V_10 |= V_223 ;
F_129 ( F_64 ( V_119 ) , V_10 ) ;
F_130 ( F_64 ( V_119 ) ) ;
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
V_230 = F_64 ( 0 ) ;
break;
case V_233 :
V_229 = V_234 ;
V_230 = F_64 ( 0 ) ;
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
F_6 ( 1 , L_40 ,
F_149 ( V_227 -> V_217 ) , F_11 ( V_230 ) & V_229 , V_228 ) ;
}
static void F_150 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_133 * V_136 = F_68 ( V_38 ) ;
if ( F_9 ( V_136 == NULL ) )
return;
F_9 ( ! V_136 -> V_115 . V_238 ) ;
if ( V_136 -> V_112 == 0 ) {
F_16 ( L_41 , V_136 -> V_8 ) ;
F_9 ( V_136 -> V_239 ) ;
F_151 ( V_2 , V_136 ) ;
V_136 -> V_240 ( V_2 , V_136 ) ;
}
}
static void F_152 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_133 * V_136 = F_68 ( V_38 ) ;
if ( F_9 ( V_136 == NULL ) )
return;
if ( F_9 ( V_136 -> V_115 . V_238 == 0 ) )
return;
F_153 ( L_42 ,
V_136 -> V_8 , V_136 -> V_112 , V_136 -> V_239 ,
V_38 -> V_40 . V_40 . V_241 ) ;
if ( V_136 -> V_112 ++ ) {
F_9 ( ! V_136 -> V_239 ) ;
F_154 ( V_2 , V_136 ) ;
return;
}
F_9 ( V_136 -> V_239 ) ;
F_155 ( V_2 , V_242 ) ;
F_153 ( L_43 , V_136 -> V_8 ) ;
V_136 -> V_243 ( V_2 , V_136 ) ;
V_136 -> V_239 = true ;
}
static void F_156 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_133 * V_136 = F_68 ( V_38 ) ;
if ( F_60 ( V_16 ) -> V_127 < 5 )
return;
if ( V_136 == NULL )
return;
if ( F_9 ( ! ( V_136 -> V_115 . V_238 & ( 1 << F_157 ( & V_38 -> V_40 ) ) ) ) )
return;
F_153 ( L_44 ,
V_136 -> V_8 , V_136 -> V_112 , V_136 -> V_239 ,
V_38 -> V_40 . V_40 . V_241 ) ;
if ( F_9 ( V_136 -> V_112 == 0 ) ) {
F_151 ( V_2 , V_136 ) ;
return;
}
F_154 ( V_2 , V_136 ) ;
F_9 ( ! V_136 -> V_239 ) ;
if ( -- V_136 -> V_112 )
return;
F_153 ( L_45 , V_136 -> V_8 ) ;
V_136 -> V_244 ( V_2 , V_136 ) ;
V_136 -> V_239 = false ;
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
F_132 ( L_46 , F_80 ( V_119 ) ) ;
}
static void F_162 ( struct V_1 * V_2 ,
enum V_118 V_121 )
{
T_1 V_10 , V_245 ;
F_142 ( ! F_10 ( V_2 -> V_16 ) ) ;
F_159 ( V_2 , (enum V_119 ) V_121 ) ;
F_160 ( V_2 , V_256 ) ;
V_10 = F_11 ( F_161 ( V_147 ) ) ;
V_10 |= V_246 ;
F_129 ( F_161 ( V_147 ) , V_10 ) ;
V_10 = V_185 ;
V_245 = F_11 ( F_61 ( V_121 ) ) ;
if ( ( V_245 & V_257 ) ==
V_251 )
V_10 |= V_253 ;
else
V_10 |= V_254 ;
F_129 ( V_258 , V_10 ) ;
if ( F_62 ( F_11 ( V_258 ) & V_255 , 100 ) )
F_132 ( L_47 ) ;
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
F_132 ( L_48 , F_80 ( V_119 ) ) ;
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
F_132 ( L_49 ) ;
V_10 = F_11 ( F_161 ( V_147 ) ) ;
V_10 &= ~ V_246 ;
F_129 ( F_161 ( V_147 ) , V_10 ) ;
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
F_153 ( L_50 , F_80 ( V_119 ) ) ;
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
if ( V_10 & V_169 ) {
F_9 ( ! ( ( V_119 == V_147 && V_2 -> V_166 & V_167 ) ||
( V_119 == V_156 && V_2 -> V_166 & V_168 ) ) ) ;
return;
}
F_129 ( V_9 , V_10 | V_169 ) ;
F_130 ( V_9 ) ;
if ( V_16 -> V_262 == 0 &&
F_62 ( F_174 ( V_38 ) != V_38 -> V_263 , 50 ) )
F_132 ( L_51 , F_80 ( V_119 ) ) ;
}
static void F_175 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_40 . V_16 -> V_17 ;
enum V_118 V_121 = V_38 -> V_115 -> V_121 ;
enum V_119 V_119 = V_38 -> V_119 ;
T_5 V_9 ;
T_1 V_10 ;
F_153 ( L_52 , F_80 ( V_119 ) ) ;
F_92 ( V_2 , V_119 ) ;
F_168 ( V_2 , V_119 ) ;
F_94 ( V_2 , V_119 ) ;
V_9 = F_61 ( V_121 ) ;
V_10 = F_11 ( V_9 ) ;
if ( ( V_10 & V_169 ) == 0 )
return;
if ( V_38 -> V_115 -> V_264 )
V_10 &= ~ V_265 ;
if ( ! ( V_119 == V_147 && V_2 -> V_166 & V_167 ) &&
! ( V_119 == V_156 && V_2 -> V_166 & V_168 ) )
V_10 &= ~ V_169 ;
F_129 ( V_9 , V_10 ) ;
if ( ( V_10 & V_169 ) == 0 )
F_59 ( V_38 ) ;
}
static bool F_176 ( struct V_15 * V_16 )
{
#ifdef F_177
if ( F_60 ( V_16 ) -> V_127 >= 6 && V_266 )
return true ;
#endif
return false ;
}
static unsigned int F_178 ( const struct V_1 * V_2 )
{
return F_33 ( V_2 ) ? 2048 : 4096 ;
}
static unsigned int F_179 ( const struct V_1 * V_2 ,
V_89 V_267 , unsigned int V_268 )
{
switch ( V_267 ) {
case V_269 :
return V_268 ;
case V_270 :
if ( F_33 ( V_2 ) )
return 128 ;
else
return 512 ;
case V_271 :
if ( F_33 ( V_2 ) || F_180 ( V_2 ) )
return 128 ;
else
return 512 ;
case V_272 :
switch ( V_268 ) {
case 1 :
return 64 ;
case 2 :
case 4 :
return 128 ;
case 8 :
case 16 :
return 256 ;
default:
F_181 ( V_268 ) ;
return V_268 ;
}
break;
default:
F_181 ( V_267 ) ;
return V_268 ;
}
}
unsigned int F_182 ( const struct V_1 * V_2 ,
V_89 V_267 , unsigned int V_268 )
{
if ( V_267 == V_269 )
return 1 ;
else
return F_178 ( V_2 ) /
F_179 ( V_2 , V_267 , V_268 ) ;
}
unsigned int
F_183 ( struct V_15 * V_16 , unsigned int V_273 ,
T_2 V_274 , V_89 V_267 )
{
unsigned int V_268 = F_184 ( V_274 , 0 ) ;
unsigned int V_275 = F_182 ( F_185 ( V_16 ) , V_267 , V_268 ) ;
return F_186 ( V_273 , V_275 ) ;
}
static void
F_187 ( struct V_276 * V_277 , struct V_278 * V_114 ,
const struct V_279 * V_280 )
{
struct V_1 * V_2 = F_185 ( V_114 -> V_16 ) ;
struct V_281 * V_282 = & V_277 -> V_283 . V_284 ;
unsigned int V_285 , V_286 , V_275 , V_268 ;
* V_277 = V_287 ;
if ( ! V_280 )
return;
if ( ! F_188 ( V_280 -> V_288 ) )
return;
* V_277 = V_289 ;
V_282 -> V_273 = V_114 -> V_273 ;
V_282 -> V_274 = V_114 -> V_274 ;
V_282 -> V_290 = V_114 -> V_291 [ 0 ] ;
V_282 -> V_292 = V_114 -> V_293 [ 1 ] ;
V_282 -> V_267 = V_114 -> V_294 [ 0 ] ;
V_285 = F_178 ( V_2 ) ;
V_268 = F_184 ( V_114 -> V_274 , 0 ) ;
V_286 = F_179 ( V_2 , V_114 -> V_294 [ 0 ] , V_268 ) ;
V_275 = V_285 / V_286 ;
V_282 -> V_295 = F_189 ( V_114 -> V_291 [ 0 ] , V_286 ) ;
V_282 -> V_296 = F_189 ( V_114 -> V_273 , V_275 ) ;
V_282 -> V_297 = V_282 -> V_295 * V_282 -> V_296 * V_285 ;
if ( V_282 -> V_274 == V_298 ) {
V_268 = F_184 ( V_114 -> V_274 , 1 ) ;
V_286 = F_179 ( V_2 , V_114 -> V_294 [ 1 ] , V_268 ) ;
V_275 = V_285 / V_286 ;
V_282 -> V_299 = F_189 ( V_114 -> V_291 [ 1 ] , V_286 ) ;
V_282 -> V_300 = F_189 ( V_114 -> V_273 / 2 , V_275 ) ;
V_282 -> V_301 = V_282 -> V_299 * V_282 -> V_300 * V_285 ;
}
}
static unsigned int F_190 ( const struct V_1 * V_2 )
{
if ( F_60 ( V_2 ) -> V_127 >= 9 )
return 256 * 1024 ;
else if ( F_191 ( V_2 ) || F_192 ( V_2 ) ||
F_13 ( V_2 ) || F_14 ( V_2 ) )
return 128 * 1024 ;
else if ( F_60 ( V_2 ) -> V_127 >= 4 )
return 4 * 1024 ;
else
return 0 ;
}
static unsigned int F_193 ( const struct V_1 * V_2 ,
V_89 V_267 )
{
switch ( V_267 ) {
case V_269 :
return F_190 ( V_2 ) ;
case V_270 :
if ( F_60 ( V_2 ) -> V_127 >= 9 )
return 256 * 1024 ;
return 0 ;
case V_271 :
case V_272 :
return 1 * 1024 * 1024 ;
default:
F_181 ( V_267 ) ;
return 0 ;
}
}
int
F_194 ( struct V_302 * V_170 ,
struct V_278 * V_114 ,
const struct V_279 * V_280 )
{
struct V_15 * V_16 = V_114 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_303 * V_304 = F_195 ( V_114 ) ;
struct V_276 V_277 ;
T_1 V_305 ;
int V_306 ;
F_9 ( ! F_196 ( & V_16 -> V_307 ) ) ;
V_305 = F_193 ( V_2 , V_114 -> V_294 [ 0 ] ) ;
F_187 ( & V_277 , V_114 , V_280 ) ;
if ( F_176 ( V_16 ) && V_305 < 256 * 1024 )
V_305 = 256 * 1024 ;
F_197 ( V_2 ) ;
V_306 = F_198 ( V_304 , V_305 ,
& V_277 ) ;
if ( V_306 )
goto V_308;
if ( V_277 . type == V_309 ) {
V_306 = F_199 ( V_304 ) ;
if ( V_306 == - V_310 ) {
V_306 = - V_311 ;
goto V_312;
} else if ( V_306 )
goto V_312;
F_200 ( V_304 ) ;
}
F_201 ( V_2 ) ;
return 0 ;
V_312:
F_202 ( V_304 , & V_277 ) ;
V_308:
F_201 ( V_2 ) ;
return V_306 ;
}
static void F_203 ( struct V_278 * V_114 ,
const struct V_279 * V_280 )
{
struct V_303 * V_304 = F_195 ( V_114 ) ;
struct V_276 V_277 ;
F_9 ( ! F_196 ( & V_304 -> V_40 . V_16 -> V_307 ) ) ;
F_187 ( & V_277 , V_114 , V_280 ) ;
if ( V_277 . type == V_309 )
F_204 ( V_304 ) ;
F_202 ( V_304 , & V_277 ) ;
}
T_1 F_205 ( struct V_1 * V_2 ,
int * V_313 , int * V_314 ,
V_89 V_267 ,
unsigned int V_268 ,
unsigned int V_290 )
{
if ( V_267 != V_269 ) {
unsigned int V_285 , V_286 , V_275 ;
unsigned int V_315 , V_316 ;
V_285 = F_178 ( V_2 ) ;
V_286 = F_179 ( V_2 , V_267 , V_268 ) ;
V_275 = V_285 / V_286 ;
V_315 = * V_314 / V_275 ;
* V_314 %= V_275 ;
V_316 = * V_313 / ( V_286 / V_268 ) ;
* V_313 %= V_286 / V_268 ;
return V_315 * V_290 * V_275 + V_316 * V_285 ;
} else {
unsigned int V_305 = F_190 ( V_2 ) - 1 ;
unsigned int V_317 ;
V_317 = * V_314 * V_290 + * V_313 * V_268 ;
* V_314 = ( V_317 & V_305 ) / V_290 ;
* V_313 = ( ( V_317 & V_305 ) - * V_314 * V_290 ) / V_268 ;
return V_317 & ~ V_305 ;
}
}
static int F_206 ( int V_318 )
{
switch ( V_318 ) {
case V_319 :
return V_320 ;
case V_321 :
return V_322 ;
case V_323 :
return V_324 ;
default:
case V_325 :
return V_326 ;
case V_327 :
return V_328 ;
case V_329 :
return V_330 ;
case V_331 :
return V_332 ;
}
}
static int F_207 ( int V_318 , bool V_333 , bool V_334 )
{
switch ( V_318 ) {
case V_335 :
return V_324 ;
default:
case V_336 :
if ( V_333 ) {
if ( V_334 )
return V_337 ;
else
return V_328 ;
} else {
if ( V_334 )
return V_338 ;
else
return V_326 ;
}
case V_339 :
if ( V_333 )
return V_332 ;
else
return V_330 ;
}
}
static bool
F_208 ( struct V_37 * V_38 ,
struct V_340 * V_341 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = F_185 ( V_16 ) ;
struct V_303 * V_304 = NULL ;
struct V_342 V_343 = { 0 } ;
struct V_278 * V_114 = & V_341 -> V_114 -> V_40 ;
T_1 V_344 = F_209 ( V_341 -> V_40 , V_345 ) ;
T_1 V_346 = F_210 ( V_341 -> V_40 + V_341 -> V_297 ,
V_345 ) ;
V_346 -= V_344 ;
if ( V_341 -> V_297 == 0 )
return false ;
if ( V_346 * 2 > V_2 -> V_347 . V_348 )
return false ;
F_2 ( & V_16 -> V_307 ) ;
V_304 = F_211 ( V_16 ,
V_344 ,
V_344 ,
V_346 ) ;
if ( ! V_304 ) {
F_4 ( & V_16 -> V_307 ) ;
return false ;
}
V_304 -> V_349 = V_341 -> V_350 ;
if ( V_304 -> V_349 == V_351 )
V_304 -> V_352 = V_114 -> V_291 [ 0 ] ;
V_343 . V_274 = V_114 -> V_274 ;
V_343 . V_353 = V_114 -> V_353 ;
V_343 . V_273 = V_114 -> V_273 ;
V_343 . V_291 [ 0 ] = V_114 -> V_291 [ 0 ] ;
V_343 . V_294 [ 0 ] = V_114 -> V_294 [ 0 ] ;
V_343 . V_354 = V_355 ;
if ( F_212 ( V_16 , F_213 ( V_114 ) ,
& V_343 , V_304 ) ) {
F_153 ( L_53 ) ;
goto V_356;
}
F_4 ( & V_16 -> V_307 ) ;
F_153 ( L_54 , V_304 ) ;
return true ;
V_356:
F_214 ( & V_304 -> V_40 ) ;
F_4 ( & V_16 -> V_307 ) ;
return false ;
}
static void
F_215 ( struct V_302 * V_170 )
{
if ( V_170 -> V_114 == V_170 -> V_36 -> V_114 )
return;
if ( V_170 -> V_36 -> V_114 )
F_216 ( V_170 -> V_36 -> V_114 ) ;
V_170 -> V_36 -> V_114 = V_170 -> V_114 ;
if ( V_170 -> V_36 -> V_114 )
F_217 ( V_170 -> V_36 -> V_114 ) ;
}
static void
F_218 ( struct V_37 * V_37 ,
struct V_340 * V_341 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_111 * V_357 ;
struct V_37 * V_50 ;
struct V_303 * V_304 ;
struct V_302 * V_113 = V_37 -> V_40 . V_113 ;
struct V_279 * V_280 = V_113 -> V_36 ;
struct V_35 * V_44 = V_37 -> V_40 . V_36 ;
struct V_358 * V_358 = F_219 ( V_113 ) ;
struct V_359 * V_360 =
F_220 ( V_280 ) ;
struct V_278 * V_114 ;
if ( ! V_341 -> V_114 )
return;
if ( F_208 ( V_37 , V_341 ) ) {
V_114 = & V_341 -> V_114 -> V_40 ;
goto V_361;
}
F_221 ( V_341 -> V_114 ) ;
F_222 (dev, c) {
V_50 = F_50 ( V_357 ) ;
if ( V_357 == & V_37 -> V_40 )
continue;
if ( ! V_50 -> V_112 )
continue;
V_114 = V_357 -> V_113 -> V_114 ;
if ( ! V_114 )
continue;
V_304 = F_195 ( V_114 ) ;
if ( F_223 ( V_304 ) == V_341 -> V_40 ) {
F_217 ( V_114 ) ;
goto V_361;
}
}
F_220 ( V_280 ) -> V_362 = false ;
V_44 -> V_363 &= ~ ( 1 << F_224 ( V_113 ) ) ;
F_225 ( & V_37 -> V_40 ) ;
V_358 -> V_364 ( V_113 , & V_37 -> V_40 ) ;
return;
V_361:
V_280 -> V_365 = 0 ;
V_280 -> V_366 = 0 ;
V_280 -> V_367 = V_114 -> V_353 << 16 ;
V_280 -> V_368 = V_114 -> V_273 << 16 ;
V_280 -> V_369 = 0 ;
V_280 -> V_370 = 0 ;
V_280 -> V_371 = V_114 -> V_353 ;
V_280 -> V_372 = V_114 -> V_273 ;
V_360 -> V_373 . V_374 = V_280 -> V_365 ;
V_360 -> V_373 . y1 = V_280 -> V_366 ;
V_360 -> V_373 . V_375 = V_280 -> V_365 + V_280 -> V_367 ;
V_360 -> V_373 . V_376 = V_280 -> V_366 + V_280 -> V_368 ;
V_360 -> V_377 . V_374 = V_280 -> V_369 ;
V_360 -> V_377 . y1 = V_280 -> V_370 ;
V_360 -> V_377 . V_375 = V_280 -> V_369 + V_280 -> V_371 ;
V_360 -> V_377 . V_376 = V_280 -> V_370 + V_280 -> V_372 ;
V_304 = F_195 ( V_114 ) ;
if ( V_304 -> V_349 != V_378 )
V_2 -> V_379 = true ;
F_217 ( V_114 ) ;
V_113 -> V_114 = V_113 -> V_36 -> V_114 = V_114 ;
V_113 -> V_38 = V_113 -> V_36 -> V_38 = & V_37 -> V_40 ;
V_37 -> V_40 . V_36 -> V_363 |= ( 1 << F_224 ( V_113 ) ) ;
V_304 -> V_380 |= F_219 ( V_113 ) -> V_381 ;
}
static void F_226 ( struct V_302 * V_113 ,
const struct V_43 * V_44 ,
const struct V_359 * V_280 )
{
struct V_15 * V_16 = V_113 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_44 -> V_40 . V_38 ) ;
struct V_278 * V_114 = V_280 -> V_40 . V_114 ;
struct V_303 * V_304 = F_195 ( V_114 ) ;
int V_170 = V_37 -> V_170 ;
T_1 V_382 ;
T_1 V_383 ;
T_5 V_9 = F_90 ( V_170 ) ;
int V_268 = F_184 ( V_114 -> V_274 , 0 ) ;
int V_313 = V_280 -> V_373 . V_374 >> 16 ;
int V_314 = V_280 -> V_373 . y1 >> 16 ;
V_383 = V_384 ;
V_383 |= V_171 ;
if ( F_60 ( V_16 ) -> V_127 < 4 ) {
if ( V_37 -> V_119 == V_156 )
V_383 |= V_385 ;
F_129 ( F_227 ( V_170 ) ,
( ( V_44 -> V_386 - 1 ) << 16 ) |
( V_44 -> V_387 - 1 ) ) ;
F_129 ( F_228 ( V_170 ) , 0 ) ;
} else if ( F_14 ( V_16 ) && V_170 == V_388 ) {
F_129 ( F_229 ( V_170 ) ,
( ( V_44 -> V_386 - 1 ) << 16 ) |
( V_44 -> V_387 - 1 ) ) ;
F_129 ( F_230 ( V_170 ) , 0 ) ;
F_129 ( F_231 ( V_170 ) , 0 ) ;
}
switch ( V_114 -> V_274 ) {
case V_320 :
V_383 |= V_319 ;
break;
case V_322 :
V_383 |= V_321 ;
break;
case V_324 :
V_383 |= V_323 ;
break;
case V_326 :
V_383 |= V_325 ;
break;
case V_328 :
V_383 |= V_327 ;
break;
case V_330 :
V_383 |= V_329 ;
break;
case V_332 :
V_383 |= V_331 ;
break;
default:
F_148 () ;
}
if ( F_60 ( V_16 ) -> V_127 >= 4 &&
V_304 -> V_349 != V_378 )
V_383 |= V_389 ;
if ( F_31 ( V_16 ) )
V_383 |= V_390 ;
V_382 = V_314 * V_114 -> V_291 [ 0 ] + V_313 * V_268 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
V_37 -> V_391 =
F_205 ( V_2 , & V_313 , & V_314 ,
V_114 -> V_294 [ 0 ] , V_268 ,
V_114 -> V_291 [ 0 ] ) ;
V_382 -= V_37 -> V_391 ;
} else {
V_37 -> V_391 = V_382 ;
}
if ( V_280 -> V_40 . V_288 == F_232 ( V_392 ) ) {
V_383 |= V_393 ;
V_313 += ( V_44 -> V_387 - 1 ) ;
V_314 += ( V_44 -> V_386 - 1 ) ;
V_382 +=
( V_44 -> V_386 - 1 ) * V_114 -> V_291 [ 0 ] +
( V_44 -> V_387 - 1 ) * V_268 ;
}
V_37 -> V_394 = V_313 ;
V_37 -> V_395 = V_314 ;
F_129 ( V_9 , V_383 ) ;
F_129 ( F_233 ( V_170 ) , V_114 -> V_291 [ 0 ] ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
F_129 ( F_234 ( V_170 ) ,
F_223 ( V_304 ) + V_37 -> V_391 ) ;
F_129 ( F_235 ( V_170 ) , ( V_314 << 16 ) | V_313 ) ;
F_129 ( F_236 ( V_170 ) , V_382 ) ;
} else
F_129 ( F_237 ( V_170 ) , F_223 ( V_304 ) + V_382 ) ;
F_130 ( V_9 ) ;
}
static void F_238 ( struct V_302 * V_113 ,
struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_170 = V_37 -> V_170 ;
F_129 ( F_90 ( V_170 ) , 0 ) ;
if ( F_60 ( V_2 ) -> V_127 >= 4 )
F_129 ( F_234 ( V_170 ) , 0 ) ;
else
F_129 ( F_237 ( V_170 ) , 0 ) ;
F_130 ( F_90 ( V_170 ) ) ;
}
static void F_239 ( struct V_302 * V_113 ,
const struct V_43 * V_44 ,
const struct V_359 * V_280 )
{
struct V_15 * V_16 = V_113 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_44 -> V_40 . V_38 ) ;
struct V_278 * V_114 = V_280 -> V_40 . V_114 ;
struct V_303 * V_304 = F_195 ( V_114 ) ;
int V_170 = V_37 -> V_170 ;
T_1 V_382 ;
T_1 V_383 ;
T_5 V_9 = F_90 ( V_170 ) ;
int V_268 = F_184 ( V_114 -> V_274 , 0 ) ;
int V_313 = V_280 -> V_373 . V_374 >> 16 ;
int V_314 = V_280 -> V_373 . y1 >> 16 ;
V_383 = V_384 ;
V_383 |= V_171 ;
if ( F_240 ( V_16 ) || F_241 ( V_16 ) )
V_383 |= V_396 ;
switch ( V_114 -> V_274 ) {
case V_320 :
V_383 |= V_319 ;
break;
case V_324 :
V_383 |= V_323 ;
break;
case V_326 :
V_383 |= V_325 ;
break;
case V_328 :
V_383 |= V_327 ;
break;
case V_330 :
V_383 |= V_329 ;
break;
case V_332 :
V_383 |= V_331 ;
break;
default:
F_148 () ;
}
if ( V_304 -> V_349 != V_378 )
V_383 |= V_389 ;
if ( ! F_240 ( V_16 ) && ! F_241 ( V_16 ) )
V_383 |= V_390 ;
V_382 = V_314 * V_114 -> V_291 [ 0 ] + V_313 * V_268 ;
V_37 -> V_391 =
F_205 ( V_2 , & V_313 , & V_314 ,
V_114 -> V_294 [ 0 ] , V_268 ,
V_114 -> V_291 [ 0 ] ) ;
V_382 -= V_37 -> V_391 ;
if ( V_280 -> V_40 . V_288 == F_232 ( V_392 ) ) {
V_383 |= V_393 ;
if ( ! F_240 ( V_16 ) && ! F_241 ( V_16 ) ) {
V_313 += ( V_44 -> V_387 - 1 ) ;
V_314 += ( V_44 -> V_386 - 1 ) ;
V_382 +=
( V_44 -> V_386 - 1 ) * V_114 -> V_291 [ 0 ] +
( V_44 -> V_387 - 1 ) * V_268 ;
}
}
V_37 -> V_394 = V_313 ;
V_37 -> V_395 = V_314 ;
F_129 ( V_9 , V_383 ) ;
F_129 ( F_233 ( V_170 ) , V_114 -> V_291 [ 0 ] ) ;
F_129 ( F_234 ( V_170 ) ,
F_223 ( V_304 ) + V_37 -> V_391 ) ;
if ( F_240 ( V_16 ) || F_241 ( V_16 ) ) {
F_129 ( F_242 ( V_170 ) , ( V_314 << 16 ) | V_313 ) ;
} else {
F_129 ( F_235 ( V_170 ) , ( V_314 << 16 ) | V_313 ) ;
F_129 ( F_236 ( V_170 ) , V_382 ) ;
}
F_130 ( V_9 ) ;
}
T_1 F_243 ( const struct V_1 * V_2 ,
V_89 V_267 , T_2 V_274 )
{
if ( V_267 == V_269 ) {
return 64 ;
} else {
int V_268 = F_184 ( V_274 , 0 ) ;
return F_179 ( V_2 , V_267 , V_268 ) ;
}
}
T_1 F_244 ( struct V_358 * V_358 ,
struct V_303 * V_304 ,
unsigned int V_170 )
{
struct V_276 V_277 ;
struct V_397 * V_398 ;
T_6 V_317 ;
F_187 ( & V_277 , V_358 -> V_40 . V_36 -> V_114 ,
V_358 -> V_40 . V_36 ) ;
V_398 = F_245 ( V_304 , & V_277 ) ;
if ( F_6 ( ! V_398 , L_55 ,
V_277 . type ) )
return - 1 ;
V_317 = V_398 -> V_399 . V_400 ;
if ( V_170 == 1 ) {
V_317 += V_398 -> V_401 . V_283 . V_284 . V_402 *
V_345 ;
}
F_9 ( F_246 ( V_317 ) ) ;
return F_247 ( V_317 ) ;
}
static void F_248 ( struct V_37 * V_37 , int V_241 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_129 ( F_249 ( V_37 -> V_119 , V_241 ) , 0 ) ;
F_129 ( F_250 ( V_37 -> V_119 , V_241 ) , 0 ) ;
F_129 ( F_251 ( V_37 -> V_119 , V_241 ) , 0 ) ;
}
static void F_252 ( struct V_37 * V_37 )
{
struct V_403 * V_404 ;
int V_50 ;
V_404 = & V_37 -> V_115 -> V_404 ;
for ( V_50 = 0 ; V_50 < V_37 -> V_405 ; V_50 ++ ) {
if ( ! V_404 -> V_406 [ V_50 ] . V_407 )
F_248 ( V_37 , V_50 ) ;
}
}
T_1 F_253 ( T_2 V_274 )
{
switch ( V_274 ) {
case V_320 :
return V_408 ;
case V_324 :
return V_335 ;
case V_328 :
return V_336 | V_409 ;
case V_326 :
return V_336 ;
case V_337 :
return V_336 | V_409 |
V_410 ;
case V_338 :
return V_336 |
V_410 ;
case V_330 :
return V_339 ;
case V_332 :
return V_409 | V_339 ;
case V_411 :
return V_412 | V_413 ;
case V_414 :
return V_412 | V_415 ;
case V_416 :
return V_412 | V_417 ;
case V_418 :
return V_412 | V_419 ;
default:
F_181 ( V_274 ) ;
}
return 0 ;
}
T_1 F_254 ( V_89 V_267 )
{
switch ( V_267 ) {
case V_269 :
break;
case V_270 :
return V_420 ;
case V_271 :
return V_421 ;
case V_272 :
return V_422 ;
default:
F_181 ( V_267 ) ;
}
return 0 ;
}
T_1 F_255 ( unsigned int V_288 )
{
switch ( V_288 ) {
case F_232 ( V_423 ) :
break;
case F_232 ( V_424 ) :
return V_425 ;
case F_232 ( V_392 ) :
return V_426 ;
case F_232 ( V_427 ) :
return V_428 ;
default:
F_181 ( V_288 ) ;
}
return 0 ;
}
static void F_256 ( struct V_302 * V_170 ,
const struct V_43 * V_44 ,
const struct V_359 * V_280 )
{
struct V_15 * V_16 = V_170 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_44 -> V_40 . V_38 ) ;
struct V_278 * V_114 = V_280 -> V_40 . V_114 ;
struct V_303 * V_304 = F_195 ( V_114 ) ;
int V_119 = V_37 -> V_119 ;
T_1 V_429 , V_430 , V_352 ;
T_1 V_275 , V_431 , V_432 ;
unsigned int V_288 = V_280 -> V_40 . V_288 ;
int V_433 , V_434 ;
T_1 V_435 ;
int V_436 = V_280 -> V_436 ;
int V_365 = V_280 -> V_373 . V_374 >> 16 ;
int V_366 = V_280 -> V_373 . y1 >> 16 ;
int V_367 = F_257 ( & V_280 -> V_373 ) >> 16 ;
int V_368 = F_258 ( & V_280 -> V_373 ) >> 16 ;
int V_437 = V_280 -> V_377 . V_374 ;
int V_438 = V_280 -> V_377 . y1 ;
int V_439 = F_257 ( & V_280 -> V_377 ) ;
int V_440 = F_258 ( & V_280 -> V_377 ) ;
V_429 = V_176 |
V_441 |
V_442 ;
V_429 |= F_253 ( V_114 -> V_274 ) ;
V_429 |= F_254 ( V_114 -> V_294 [ 0 ] ) ;
V_429 |= V_443 ;
V_429 |= F_255 ( V_288 ) ;
V_430 = F_243 ( V_2 , V_114 -> V_294 [ 0 ] ,
V_114 -> V_274 ) ;
V_435 = F_244 ( F_219 ( V_170 ) , V_304 , 0 ) ;
F_9 ( F_257 ( & V_280 -> V_373 ) == 0 ) ;
if ( F_188 ( V_288 ) ) {
int V_268 = F_184 ( V_114 -> V_274 , 0 ) ;
V_275 = F_182 ( V_2 , V_114 -> V_294 [ 0 ] , V_268 ) ;
V_352 = F_189 ( V_114 -> V_273 , V_275 ) ;
V_433 = V_352 * V_275 - V_366 - V_368 ;
V_434 = V_365 ;
V_432 = ( V_367 - 1 ) << 16 | ( V_368 - 1 ) ;
} else {
V_352 = V_114 -> V_291 [ 0 ] / V_430 ;
V_433 = V_365 ;
V_434 = V_366 ;
V_432 = ( V_368 - 1 ) << 16 | ( V_367 - 1 ) ;
}
V_431 = V_434 << 16 | V_433 ;
V_37 -> V_394 = V_433 ;
V_37 -> V_395 = V_434 ;
F_129 ( F_96 ( V_119 , 0 ) , V_429 ) ;
F_129 ( F_259 ( V_119 , 0 ) , V_431 ) ;
F_129 ( F_260 ( V_119 , 0 ) , V_432 ) ;
F_129 ( F_261 ( V_119 , 0 ) , V_352 ) ;
if ( V_436 >= 0 ) {
T_2 V_444 = 0 ;
F_9 ( ! V_439 || ! V_440 ) ;
V_444 = V_445 | F_262 ( 0 ) |
V_44 -> V_404 . V_406 [ V_436 ] . V_446 ;
F_129 ( F_249 ( V_119 , V_436 ) , V_444 ) ;
F_129 ( F_263 ( V_119 , V_436 ) , 0 ) ;
F_129 ( F_250 ( V_119 , V_436 ) , ( V_437 << 16 ) | V_438 ) ;
F_129 ( F_251 ( V_119 , V_436 ) , ( V_439 << 16 ) | V_440 ) ;
F_129 ( F_264 ( V_119 , 0 ) , 0 ) ;
} else {
F_129 ( F_264 ( V_119 , 0 ) , ( V_438 << 16 ) | V_437 ) ;
}
F_129 ( F_265 ( V_119 , 0 ) , V_435 ) ;
F_130 ( F_265 ( V_119 , 0 ) ) ;
}
static void F_266 ( struct V_302 * V_113 ,
struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = F_50 ( V_38 ) -> V_119 ;
F_129 ( F_96 ( V_119 , 0 ) , 0 ) ;
F_129 ( F_265 ( V_119 , 0 ) , 0 ) ;
F_130 ( F_265 ( V_119 , 0 ) ) ;
}
static int
F_267 ( struct V_111 * V_38 , struct V_278 * V_114 ,
int V_313 , int V_314 , enum V_447 V_36 )
{
F_132 ( L_56 ) ;
return - V_448 ;
}
static void F_268 ( struct V_15 * V_16 )
{
struct V_111 * V_38 ;
F_222 (dev, crtc) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_170 V_170 = V_37 -> V_170 ;
F_269 ( V_16 , V_170 ) ;
F_270 ( V_16 , V_170 ) ;
}
}
static void F_271 ( struct V_15 * V_16 )
{
struct V_111 * V_38 ;
F_222 (dev, crtc) {
struct V_358 * V_170 = F_219 ( V_38 -> V_113 ) ;
struct V_359 * V_280 ;
F_272 ( V_38 , & V_170 -> V_40 ) ;
V_280 = F_220 ( V_170 -> V_40 . V_36 ) ;
if ( V_280 -> V_362 )
V_170 -> V_449 ( & V_170 -> V_40 ,
F_273 ( V_38 -> V_36 ) ,
V_280 ) ;
F_274 ( V_38 ) ;
}
}
void F_275 ( struct V_15 * V_16 )
{
if ( F_33 ( V_16 ) )
return;
if ( F_60 ( V_16 ) -> V_127 >= 5 || F_31 ( V_16 ) )
return;
F_276 ( V_16 ) ;
F_277 ( V_16 ) ;
}
void F_278 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_185 ( V_16 ) ;
F_268 ( V_16 ) ;
if ( F_33 ( V_16 ) )
return;
if ( F_60 ( V_16 ) -> V_127 >= 5 || F_31 ( V_16 ) ) {
F_271 ( V_16 ) ;
return;
}
F_279 ( V_2 ) ;
F_280 ( V_2 ) ;
F_281 ( V_16 ) ;
F_282 ( & V_2 -> V_450 ) ;
if ( V_2 -> V_451 . V_452 )
V_2 -> V_451 . V_452 ( V_16 ) ;
F_283 ( & V_2 -> V_450 ) ;
F_284 ( V_16 ) ;
F_285 ( V_2 ) ;
F_286 ( V_16 ) ;
}
static bool F_287 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
bool V_453 ;
if ( F_288 ( & V_2 -> V_454 ) ||
V_37 -> V_455 != F_289 ( & V_2 -> V_454 . V_455 ) )
return false ;
F_282 ( & V_16 -> V_456 ) ;
V_453 = F_50 ( V_38 ) -> V_457 != NULL ;
F_283 ( & V_16 -> V_456 ) ;
return V_453 ;
}
static void F_290 ( struct V_37 * V_38 ,
struct V_43 * V_458 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_43 * V_212 =
F_273 ( V_38 -> V_40 . V_36 ) ;
V_38 -> V_40 . V_446 = V_38 -> V_40 . V_36 -> V_446 ;
F_153 ( L_57 ,
V_458 -> V_387 , V_458 -> V_386 ,
V_212 -> V_387 , V_212 -> V_386 ) ;
if ( F_71 ( V_16 ) )
F_291 ( & V_38 -> V_40 ) ;
F_129 ( F_292 ( V_38 -> V_119 ) ,
( ( V_212 -> V_387 - 1 ) << 16 ) |
( V_212 -> V_386 - 1 ) ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
F_252 ( V_38 ) ;
if ( V_212 -> V_459 . V_180 )
F_293 ( V_38 ) ;
} else if ( F_10 ( V_16 ) ) {
if ( V_212 -> V_459 . V_180 )
F_294 ( V_38 ) ;
else if ( V_458 -> V_459 . V_180 )
F_295 ( V_38 , true ) ;
}
}
static void F_296 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_5 V_9 ;
T_1 V_460 ;
V_9 = F_73 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
if ( F_297 ( V_16 ) ) {
V_460 &= ~ V_461 ;
V_460 |= V_461 | V_462 ;
} else {
V_460 &= ~ V_463 ;
V_460 |= V_463 | V_462 ;
}
F_129 ( V_9 , V_460 ) ;
V_9 = F_75 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
if ( F_107 ( V_16 ) ) {
V_460 &= ~ V_464 ;
V_460 |= V_465 ;
} else {
V_460 &= ~ V_463 ;
V_460 |= V_463 ;
}
F_129 ( V_9 , V_460 | V_466 ) ;
F_130 ( V_9 ) ;
F_131 ( 1000 ) ;
if ( F_297 ( V_16 ) )
F_129 ( V_9 , F_11 ( V_9 ) | V_467 |
V_468 ) ;
}
static void F_298 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_5 V_9 ;
T_1 V_460 , V_469 ;
F_299 ( V_2 , V_119 ) ;
V_9 = F_300 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_470 ;
V_460 &= ~ V_471 ;
F_129 ( V_9 , V_460 ) ;
F_11 ( V_9 ) ;
F_131 ( 150 ) ;
V_9 = F_73 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_472 ;
V_460 |= F_301 ( V_37 -> V_115 -> V_473 ) ;
V_460 &= ~ V_463 ;
V_460 |= V_474 ;
F_129 ( V_9 , V_460 | V_141 ) ;
V_9 = F_75 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_463 ;
V_460 |= V_474 ;
F_129 ( V_9 , V_460 | V_142 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
F_129 ( F_302 ( V_119 ) , V_475 ) ;
F_129 ( F_302 ( V_119 ) , V_475 |
V_476 ) ;
V_9 = F_303 ( V_119 ) ;
for ( V_469 = 0 ; V_469 < 5 ; V_469 ++ ) {
V_460 = F_11 ( V_9 ) ;
F_153 ( L_58 , V_460 ) ;
if ( ( V_460 & V_471 ) ) {
F_153 ( L_59 ) ;
F_129 ( V_9 , V_460 | V_471 ) ;
break;
}
}
if ( V_469 == 5 )
F_132 ( L_60 ) ;
V_9 = F_73 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_463 ;
V_460 |= V_477 ;
F_129 ( V_9 , V_460 ) ;
V_9 = F_75 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_463 ;
V_460 |= V_477 ;
F_129 ( V_9 , V_460 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
V_9 = F_303 ( V_119 ) ;
for ( V_469 = 0 ; V_469 < 5 ; V_469 ++ ) {
V_460 = F_11 ( V_9 ) ;
F_153 ( L_58 , V_460 ) ;
if ( V_460 & V_470 ) {
F_129 ( V_9 , V_460 | V_470 ) ;
F_153 ( L_61 ) ;
break;
}
}
if ( V_469 == 5 )
F_132 ( L_62 ) ;
F_153 ( L_63 ) ;
}
static void F_304 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_5 V_9 ;
T_1 V_460 , V_50 , V_478 ;
V_9 = F_300 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_470 ;
V_460 &= ~ V_471 ;
F_129 ( V_9 , V_460 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
V_9 = F_73 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_472 ;
V_460 |= F_301 ( V_37 -> V_115 -> V_473 ) ;
V_460 &= ~ V_463 ;
V_460 |= V_474 ;
V_460 &= ~ V_479 ;
V_460 |= V_480 ;
F_129 ( V_9 , V_460 | V_141 ) ;
F_129 ( F_305 ( V_119 ) ,
V_481 | V_482 ) ;
V_9 = F_75 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
if ( F_107 ( V_16 ) ) {
V_460 &= ~ V_464 ;
V_460 |= V_483 ;
} else {
V_460 &= ~ V_463 ;
V_460 |= V_474 ;
}
F_129 ( V_9 , V_460 | V_142 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
V_9 = F_73 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_479 ;
V_460 |= V_484 [ V_50 ] ;
F_129 ( V_9 , V_460 ) ;
F_130 ( V_9 ) ;
F_131 ( 500 ) ;
for ( V_478 = 0 ; V_478 < 5 ; V_478 ++ ) {
V_9 = F_303 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
F_153 ( L_58 , V_460 ) ;
if ( V_460 & V_471 ) {
F_129 ( V_9 , V_460 | V_471 ) ;
F_153 ( L_59 ) ;
break;
}
F_131 ( 50 ) ;
}
if ( V_478 < 5 )
break;
}
if ( V_50 == 4 )
F_132 ( L_60 ) ;
V_9 = F_73 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_463 ;
V_460 |= V_477 ;
if ( F_306 ( V_16 ) ) {
V_460 &= ~ V_479 ;
V_460 |= V_480 ;
}
F_129 ( V_9 , V_460 ) ;
V_9 = F_75 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
if ( F_107 ( V_16 ) ) {
V_460 &= ~ V_464 ;
V_460 |= V_485 ;
} else {
V_460 &= ~ V_463 ;
V_460 |= V_477 ;
}
F_129 ( V_9 , V_460 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
V_9 = F_73 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_479 ;
V_460 |= V_484 [ V_50 ] ;
F_129 ( V_9 , V_460 ) ;
F_130 ( V_9 ) ;
F_131 ( 500 ) ;
for ( V_478 = 0 ; V_478 < 5 ; V_478 ++ ) {
V_9 = F_303 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
F_153 ( L_58 , V_460 ) ;
if ( V_460 & V_470 ) {
F_129 ( V_9 , V_460 | V_470 ) ;
F_153 ( L_61 ) ;
break;
}
F_131 ( 50 ) ;
}
if ( V_478 < 5 )
break;
}
if ( V_50 == 4 )
F_132 ( L_62 ) ;
F_153 ( L_64 ) ;
}
static void F_307 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_5 V_9 ;
T_1 V_460 , V_50 , V_486 ;
V_9 = F_300 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_470 ;
V_460 &= ~ V_471 ;
F_129 ( V_9 , V_460 ) ;
F_130 ( V_9 ) ;
F_131 ( 150 ) ;
F_153 ( L_65 ,
F_11 ( F_303 ( V_119 ) ) ) ;
for ( V_486 = 0 ; V_486 < F_308 ( V_484 ) * 2 ; V_486 ++ ) {
V_9 = F_73 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ ( V_487 | V_461 ) ;
V_460 &= ~ V_141 ;
F_129 ( V_9 , V_460 ) ;
V_9 = F_75 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_487 ;
V_460 &= ~ V_464 ;
V_460 &= ~ V_142 ;
F_129 ( V_9 , V_460 ) ;
V_9 = F_73 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_472 ;
V_460 |= F_301 ( V_37 -> V_115 -> V_473 ) ;
V_460 |= V_488 ;
V_460 &= ~ V_479 ;
V_460 |= V_484 [ V_486 / 2 ] ;
V_460 |= V_489 ;
F_129 ( V_9 , V_460 | V_141 ) ;
F_129 ( F_305 ( V_119 ) ,
V_481 | V_482 ) ;
V_9 = F_75 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 |= V_483 ;
V_460 |= V_489 ;
F_129 ( V_9 , V_460 | V_142 ) ;
F_130 ( V_9 ) ;
F_131 ( 1 ) ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
V_9 = F_303 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
F_153 ( L_58 , V_460 ) ;
if ( V_460 & V_471 ||
( F_11 ( V_9 ) & V_471 ) ) {
F_129 ( V_9 , V_460 | V_471 ) ;
F_153 ( L_66 ,
V_50 ) ;
break;
}
F_131 ( 1 ) ;
}
if ( V_50 == 4 ) {
F_153 ( L_67 , V_486 / 2 ) ;
continue;
}
V_9 = F_73 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_461 ;
V_460 |= V_490 ;
F_129 ( V_9 , V_460 ) ;
V_9 = F_75 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_464 ;
V_460 |= V_485 ;
F_129 ( V_9 , V_460 ) ;
F_130 ( V_9 ) ;
F_131 ( 2 ) ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
V_9 = F_303 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
F_153 ( L_58 , V_460 ) ;
if ( V_460 & V_470 ||
( F_11 ( V_9 ) & V_470 ) ) {
F_129 ( V_9 , V_460 | V_470 ) ;
F_153 ( L_68 ,
V_50 ) ;
goto V_491;
}
F_131 ( 2 ) ;
}
if ( V_50 == 4 )
F_153 ( L_69 , V_486 / 2 ) ;
}
V_491:
F_153 ( L_64 ) ;
}
static void F_309 ( struct V_37 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_37 -> V_119 ;
T_5 V_9 ;
T_1 V_460 ;
V_9 = F_75 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ ( V_472 | ( 0x7 << 16 ) ) ;
V_460 |= F_301 ( V_37 -> V_115 -> V_473 ) ;
V_460 |= ( F_11 ( F_61 ( V_119 ) ) & V_247 ) << 11 ;
F_129 ( V_9 , V_460 | V_144 ) ;
F_130 ( V_9 ) ;
F_131 ( 200 ) ;
V_460 = F_11 ( V_9 ) ;
F_129 ( V_9 , V_460 | V_492 ) ;
F_130 ( V_9 ) ;
F_131 ( 200 ) ;
V_9 = F_73 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
if ( ( V_460 & V_143 ) == 0 ) {
F_129 ( V_9 , V_460 | V_143 ) ;
F_130 ( V_9 ) ;
F_131 ( 100 ) ;
}
}
static void F_310 ( struct V_37 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_37 -> V_119 ;
T_5 V_9 ;
T_1 V_460 ;
V_9 = F_75 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
F_129 ( V_9 , V_460 & ~ V_492 ) ;
V_9 = F_73 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
F_129 ( V_9 , V_460 & ~ V_143 ) ;
F_130 ( V_9 ) ;
F_131 ( 100 ) ;
V_9 = F_75 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
F_129 ( V_9 , V_460 & ~ V_144 ) ;
F_130 ( V_9 ) ;
F_131 ( 100 ) ;
}
static void F_311 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_5 V_9 ;
T_1 V_460 ;
V_9 = F_73 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
F_129 ( V_9 , V_460 & ~ V_141 ) ;
F_130 ( V_9 ) ;
V_9 = F_75 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ ( 0x7 << 16 ) ;
V_460 |= ( F_11 ( F_61 ( V_119 ) ) & V_247 ) << 11 ;
F_129 ( V_9 , V_460 & ~ V_142 ) ;
F_130 ( V_9 ) ;
F_131 ( 100 ) ;
if ( F_106 ( V_16 ) )
F_129 ( F_302 ( V_119 ) , V_475 ) ;
V_9 = F_73 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ V_463 ;
V_460 |= V_474 ;
F_129 ( V_9 , V_460 ) ;
V_9 = F_75 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
if ( F_107 ( V_16 ) ) {
V_460 &= ~ V_464 ;
V_460 |= V_483 ;
} else {
V_460 &= ~ V_463 ;
V_460 |= V_474 ;
}
V_460 &= ~ ( 0x07 << 16 ) ;
V_460 |= ( F_11 ( F_61 ( V_119 ) ) & V_247 ) << 11 ;
F_129 ( V_9 , V_460 ) ;
F_130 ( V_9 ) ;
F_131 ( 100 ) ;
}
bool F_312 ( struct V_15 * V_16 )
{
struct V_37 * V_38 ;
F_140 (dev, crtc) {
if ( F_289 ( & V_38 -> V_493 ) == 0 )
continue;
if ( V_38 -> V_457 )
F_313 ( V_16 , V_38 -> V_119 ) ;
return true ;
}
return false ;
}
static void F_314 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = F_185 ( V_37 -> V_40 . V_16 ) ;
struct V_494 * V_495 = V_37 -> V_457 ;
F_315 () ;
V_37 -> V_457 = NULL ;
if ( V_495 -> V_496 )
F_316 ( V_37 -> V_40 . V_16 ,
V_37 -> V_119 ,
V_495 -> V_496 ) ;
F_104 ( & V_37 -> V_40 ) ;
F_317 ( & V_2 -> V_497 ) ;
F_318 ( V_2 -> V_498 , & V_495 -> V_495 ) ;
F_319 ( V_37 -> V_170 ,
V_495 -> V_499 ) ;
}
static int F_320 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
long V_306 ;
F_9 ( F_321 ( & V_2 -> V_497 ) ) ;
V_306 = F_322 (
V_2 -> V_497 ,
! F_287 ( V_38 ) ,
60 * V_500 ) ;
if ( V_306 < 0 )
return V_306 ;
if ( V_306 == 0 ) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
F_282 ( & V_16 -> V_456 ) ;
if ( V_37 -> V_457 ) {
F_323 ( 1 , L_70 ) ;
F_314 ( V_37 ) ;
}
F_283 ( & V_16 -> V_456 ) ;
}
return 0 ;
}
static void F_324 ( struct V_1 * V_2 )
{
T_1 V_460 ;
F_129 ( V_501 , V_502 ) ;
F_2 ( & V_2 -> V_5 ) ;
V_460 = F_325 ( V_2 , V_503 , V_504 ) ;
V_460 |= V_505 ;
F_326 ( V_2 , V_503 , V_460 , V_504 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_327 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int clock = F_50 ( V_38 ) -> V_115 -> V_40 . V_116 . V_117 ;
T_1 V_506 , V_507 , V_508 , V_509 = 0 ;
T_1 V_460 ;
F_324 ( V_2 ) ;
if ( clock == 20000 ) {
V_508 = 1 ;
V_506 = 0x41 ;
V_507 = 0x20 ;
} else {
T_1 V_510 = 172800 * 1000 ;
T_1 V_511 = 64 ;
T_1 V_512 , V_513 , V_514 ;
V_512 = F_7 ( V_510 , clock ) ;
V_513 = V_512 / V_511 ;
V_514 = V_512 % V_511 ;
V_508 = 0 ;
V_506 = V_513 - 2 ;
V_507 = V_514 ;
}
F_9 ( F_328 ( V_506 ) &
~ V_515 ) ;
F_9 ( F_329 ( V_509 ) &
~ V_516 ) ;
F_153 ( L_71 ,
clock ,
V_508 ,
V_506 ,
V_509 ,
V_507 ) ;
F_2 ( & V_2 -> V_5 ) ;
V_460 = F_325 ( V_2 , V_517 , V_504 ) ;
V_460 &= ~ V_515 ;
V_460 |= F_328 ( V_506 ) ;
V_460 &= ~ V_516 ;
V_460 |= F_330 ( V_507 ) ;
V_460 |= F_329 ( V_509 ) ;
V_460 |= V_518 ;
F_326 ( V_2 , V_517 , V_460 , V_504 ) ;
V_460 = F_325 ( V_2 , V_519 , V_504 ) ;
V_460 &= ~ F_331 ( 1 ) ;
V_460 |= F_331 ( V_508 ) ;
F_326 ( V_2 , V_519 , V_460 , V_504 ) ;
V_460 = F_325 ( V_2 , V_503 , V_504 ) ;
V_460 &= ~ V_505 ;
F_326 ( V_2 , V_503 , V_460 , V_504 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_131 ( 24 ) ;
F_129 ( V_501 , V_520 ) ;
}
static void F_332 ( struct V_37 * V_38 ,
enum V_119 V_259 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_118 V_121 = V_38 -> V_115 -> V_121 ;
F_129 ( F_333 ( V_259 ) ,
F_11 ( F_334 ( V_121 ) ) ) ;
F_129 ( F_335 ( V_259 ) ,
F_11 ( F_336 ( V_121 ) ) ) ;
F_129 ( F_337 ( V_259 ) ,
F_11 ( F_338 ( V_121 ) ) ) ;
F_129 ( F_339 ( V_259 ) ,
F_11 ( F_340 ( V_121 ) ) ) ;
F_129 ( F_341 ( V_259 ) ,
F_11 ( F_342 ( V_121 ) ) ) ;
F_129 ( F_343 ( V_259 ) ,
F_11 ( F_344 ( V_121 ) ) ) ;
F_129 ( F_345 ( V_259 ) ,
F_11 ( F_346 ( V_121 ) ) ) ;
}
static void F_347 ( struct V_15 * V_16 , bool V_243 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_460 ;
V_460 = F_11 ( V_521 ) ;
if ( ! ! ( V_460 & V_522 ) == V_243 )
return;
F_9 ( F_11 ( F_75 ( V_156 ) ) & V_142 ) ;
F_9 ( F_11 ( F_75 ( V_523 ) ) & V_142 ) ;
V_460 &= ~ V_522 ;
if ( V_243 )
V_460 |= V_522 ;
F_153 ( L_72 , V_243 ? L_73 : L_74 ) ;
F_129 ( V_521 , V_460 ) ;
F_130 ( V_521 ) ;
}
static void F_348 ( struct V_37 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
switch ( V_37 -> V_119 ) {
case V_147 :
break;
case V_156 :
if ( V_37 -> V_115 -> V_473 > 2 )
F_347 ( V_16 , false ) ;
else
F_347 ( V_16 , true ) ;
break;
case V_523 :
F_347 ( V_16 , true ) ;
break;
default:
F_148 () ;
}
}
static enum V_217
F_349 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_41 * V_42 ;
F_22 (dev, crtc, encoder) {
if ( V_42 -> type == V_524 ||
V_42 -> type == V_525 )
return F_350 ( & V_42 -> V_40 ) -> V_217 ;
}
return - 1 ;
}
static void F_351 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_1 V_460 ;
F_108 ( V_2 , V_119 ) ;
if ( F_297 ( V_16 ) )
F_348 ( V_37 ) ;
F_129 ( F_352 ( V_119 ) ,
F_11 ( F_353 ( V_119 ) ) & V_526 ) ;
F_354 ( V_2 , V_119 , false ) ;
V_2 -> V_451 . V_527 ( V_38 ) ;
if ( F_107 ( V_16 ) ) {
T_1 V_528 ;
V_460 = F_11 ( V_529 ) ;
V_460 |= F_355 ( V_119 ) ;
V_528 = F_356 ( V_119 ) ;
if ( V_37 -> V_115 -> V_134 == V_530 )
V_460 |= V_528 ;
else
V_460 &= ~ V_528 ;
F_129 ( V_529 , V_460 ) ;
}
F_152 ( V_37 ) ;
F_78 ( V_2 , V_119 ) ;
F_332 ( V_37 , V_119 ) ;
F_296 ( V_38 ) ;
F_354 ( V_2 , V_119 , true ) ;
if ( F_107 ( V_16 ) && V_37 -> V_115 -> V_531 ) {
const struct V_532 * V_116 =
& V_37 -> V_115 -> V_40 . V_116 ;
T_1 V_533 = ( F_11 ( F_61 ( V_119 ) ) & V_247 ) >> 5 ;
T_5 V_9 = F_111 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ ( V_188 |
V_534 |
V_535 ) ;
V_460 |= V_536 ;
V_460 |= V_533 << 9 ;
if ( V_116 -> V_354 & V_537 )
V_460 |= V_538 ;
if ( V_116 -> V_354 & V_539 )
V_460 |= V_540 ;
switch ( F_349 ( V_38 ) ) {
case V_231 :
V_460 |= V_203 ;
break;
case V_233 :
V_460 |= V_205 ;
break;
case V_235 :
V_460 |= V_207 ;
break;
default:
F_148 () ;
}
F_129 ( V_9 , V_460 ) ;
}
F_158 ( V_2 , V_119 ) ;
}
static void F_357 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_118 V_121 = V_37 -> V_115 -> V_121 ;
F_108 ( V_2 , V_256 ) ;
F_327 ( V_38 ) ;
F_332 ( V_37 , V_147 ) ;
F_162 ( V_2 , V_121 ) ;
}
struct V_133 * F_358 ( struct V_37 * V_38 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_38 -> V_40 . V_16 -> V_17 ;
struct V_133 * V_136 ;
struct V_541 * V_134 ;
enum V_542 V_50 ;
int V_91 = V_2 -> V_543 ;
V_134 = F_359 ( V_44 -> V_40 . V_36 ) ;
if ( F_106 ( V_2 -> V_16 ) ) {
V_50 = (enum V_542 ) V_38 -> V_119 ;
V_136 = & V_2 -> V_135 [ V_50 ] ;
F_153 ( L_75 ,
V_38 -> V_40 . V_40 . V_241 , V_136 -> V_8 ) ;
F_9 ( V_134 [ V_50 ] . V_238 ) ;
goto V_101;
}
if ( F_30 ( V_2 -> V_16 ) ) {
struct V_41 * V_42 ;
struct V_226 * V_544 ;
V_42 = F_360 ( V_44 ) ;
if ( F_9 ( ! V_42 ) )
return NULL ;
V_544 = F_350 ( & V_42 -> V_40 ) ;
V_50 = (enum V_542 ) V_544 -> V_217 ;
V_136 = & V_2 -> V_135 [ V_50 ] ;
F_153 ( L_75 ,
V_38 -> V_40 . V_40 . V_241 , V_136 -> V_8 ) ;
F_9 ( V_134 [ V_50 ] . V_238 ) ;
goto V_101;
} else if ( F_60 ( V_2 ) -> V_127 < 9 && F_71 ( V_2 ) )
V_91 = 2 ;
for ( V_50 = 0 ; V_50 < V_91 ; V_50 ++ ) {
V_136 = & V_2 -> V_135 [ V_50 ] ;
if ( V_134 [ V_50 ] . V_238 == 0 )
continue;
if ( memcmp ( & V_44 -> V_213 ,
& V_134 [ V_50 ] . V_138 ,
sizeof( V_44 -> V_213 ) ) == 0 ) {
F_153 ( L_76 ,
V_38 -> V_40 . V_40 . V_241 , V_136 -> V_8 ,
V_134 [ V_50 ] . V_238 ,
V_136 -> V_112 ) ;
goto V_101;
}
}
for ( V_50 = 0 ; V_50 < V_2 -> V_543 ; V_50 ++ ) {
V_136 = & V_2 -> V_135 [ V_50 ] ;
if ( V_134 [ V_50 ] . V_238 == 0 ) {
F_153 ( L_77 ,
V_38 -> V_40 . V_40 . V_241 , V_136 -> V_8 ) ;
goto V_101;
}
}
return NULL ;
V_101:
if ( V_134 [ V_50 ] . V_238 == 0 )
V_134 [ V_50 ] . V_138 =
V_44 -> V_213 ;
V_44 -> V_134 = V_50 ;
F_16 ( L_78 , V_136 -> V_8 ,
F_80 ( V_38 -> V_119 ) ) ;
V_134 [ V_50 ] . V_238 |= 1 << V_38 -> V_119 ;
return V_136 ;
}
static void F_361 ( struct V_45 * V_36 )
{
struct V_1 * V_2 = F_185 ( V_36 -> V_16 ) ;
struct V_541 * V_134 ;
struct V_133 * V_136 ;
enum V_542 V_50 ;
if ( ! F_362 ( V_36 ) -> V_545 )
return;
V_134 = F_362 ( V_36 ) -> V_134 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_543 ; V_50 ++ ) {
V_136 = & V_2 -> V_135 [ V_50 ] ;
V_136 -> V_115 = V_134 [ V_50 ] ;
}
}
static void F_363 ( struct V_15 * V_16 , int V_119 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_5 V_546 = F_57 ( V_119 ) ;
T_1 V_460 ;
V_460 = F_11 ( V_546 ) ;
F_131 ( 500 ) ;
if ( F_62 ( F_11 ( V_546 ) != V_460 , 5 ) ) {
if ( F_62 ( F_11 ( V_546 ) != V_460 , 5 ) )
F_132 ( L_79 , F_80 ( V_119 ) ) ;
}
}
static int
F_364 ( struct V_43 * V_44 , bool V_547 ,
unsigned V_548 , int * V_436 , unsigned int V_288 ,
int V_367 , int V_368 , int V_439 , int V_440 )
{
struct V_403 * V_404 =
& V_44 -> V_404 ;
struct V_37 * V_37 =
F_50 ( V_44 -> V_40 . V_38 ) ;
int V_549 ;
V_549 = F_188 ( V_288 ) ?
( V_368 != V_439 || V_367 != V_440 ) :
( V_367 != V_439 || V_368 != V_440 ) ;
if ( V_547 || ! V_549 ) {
if ( * V_436 >= 0 ) {
V_404 -> V_550 &= ~ ( 1 << V_548 ) ;
V_404 -> V_406 [ * V_436 ] . V_407 = 0 ;
F_153 ( L_80
L_81 ,
V_37 -> V_119 , V_548 , * V_436 ,
V_404 -> V_550 ) ;
* V_436 = - 1 ;
}
return 0 ;
}
if ( V_367 < V_551 || V_368 < V_552 ||
V_439 < V_553 || V_440 < V_554 ||
V_367 > V_555 || V_368 > V_556 ||
V_439 > V_557 || V_440 > V_558 ) {
F_153 ( L_82
L_83 ,
V_37 -> V_119 , V_548 , V_367 , V_368 , V_439 , V_440 ) ;
return - V_559 ;
}
V_404 -> V_550 |= ( 1 << V_548 ) ;
F_153 ( L_80
L_84 ,
V_37 -> V_119 , V_548 , V_367 , V_368 , V_439 , V_440 ,
V_404 -> V_550 ) ;
return 0 ;
}
int F_365 ( struct V_43 * V_36 )
{
struct V_37 * V_37 = F_50 ( V_36 -> V_40 . V_38 ) ;
const struct V_532 * V_116 = & V_36 -> V_40 . V_116 ;
F_153 ( L_85 ,
V_37 -> V_40 . V_40 . V_241 , V_37 -> V_119 , V_560 ) ;
return F_364 ( V_36 , ! V_36 -> V_40 . V_112 , V_560 ,
& V_36 -> V_404 . V_436 , F_232 ( V_423 ) ,
V_36 -> V_387 , V_36 -> V_386 ,
V_116 -> V_561 , V_116 -> V_562 ) ;
}
static int F_366 ( struct V_43 * V_44 ,
struct V_359 * V_280 )
{
struct V_37 * V_37 = F_50 ( V_44 -> V_40 . V_38 ) ;
struct V_358 * V_358 =
F_219 ( V_280 -> V_40 . V_170 ) ;
struct V_278 * V_114 = V_280 -> V_40 . V_114 ;
int V_306 ;
bool V_547 = ! V_114 || ! V_280 -> V_362 ;
F_153 ( L_86 ,
V_358 -> V_40 . V_40 . V_241 , V_37 -> V_119 ,
F_224 ( & V_358 -> V_40 ) ) ;
V_306 = F_364 ( V_44 , V_547 ,
F_224 ( & V_358 -> V_40 ) ,
& V_280 -> V_436 ,
V_280 -> V_40 . V_288 ,
F_257 ( & V_280 -> V_373 ) >> 16 ,
F_258 ( & V_280 -> V_373 ) >> 16 ,
F_257 ( & V_280 -> V_377 ) ,
F_258 ( & V_280 -> V_377 ) ) ;
if ( V_306 || V_280 -> V_436 < 0 )
return V_306 ;
if ( V_280 -> V_563 . V_354 != V_564 ) {
F_153 ( L_87 ,
V_358 -> V_40 . V_40 . V_241 ) ;
return - V_559 ;
}
switch ( V_114 -> V_274 ) {
case V_324 :
case V_328 :
case V_326 :
case V_337 :
case V_338 :
case V_330 :
case V_332 :
case V_411 :
case V_414 :
case V_416 :
case V_418 :
break;
default:
F_153 ( L_88 ,
V_358 -> V_40 . V_40 . V_241 , V_114 -> V_40 . V_241 , V_114 -> V_274 ) ;
return - V_559 ;
}
return 0 ;
}
static void F_367 ( struct V_37 * V_38 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_38 -> V_405 ; V_50 ++ )
F_248 ( V_38 , V_50 ) ;
}
static void F_293 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
struct V_403 * V_404 =
& V_38 -> V_115 -> V_404 ;
F_153 ( L_89 , V_38 -> V_115 ) ;
if ( V_38 -> V_115 -> V_459 . V_180 ) {
int V_241 ;
if ( F_9 ( V_38 -> V_115 -> V_404 . V_436 < 0 ) ) {
F_132 ( L_90 ) ;
return;
}
V_241 = V_404 -> V_436 ;
F_129 ( F_249 ( V_119 , V_241 ) , V_445 |
V_565 | V_404 -> V_406 [ V_241 ] . V_446 ) ;
F_129 ( F_250 ( V_119 , V_241 ) , V_38 -> V_115 -> V_459 . V_566 ) ;
F_129 ( F_251 ( V_119 , V_241 ) , V_38 -> V_115 -> V_459 . V_297 ) ;
F_153 ( L_91 , V_38 -> V_115 , V_241 ) ;
}
}
static void F_294 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
if ( V_38 -> V_115 -> V_459 . V_180 ) {
if ( F_297 ( V_16 ) || F_240 ( V_16 ) )
F_129 ( F_368 ( V_119 ) , V_567 | V_568 |
F_369 ( V_119 ) ) ;
else
F_129 ( F_368 ( V_119 ) , V_567 | V_568 ) ;
F_129 ( F_370 ( V_119 ) , V_38 -> V_115 -> V_459 . V_566 ) ;
F_129 ( F_371 ( V_119 ) , V_38 -> V_115 -> V_459 . V_297 ) ;
}
}
void F_372 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! V_38 -> V_115 -> V_569 )
return;
F_313 ( V_16 , V_38 -> V_119 ) ;
F_373 ( V_2 , V_38 -> V_170 ) ;
if ( F_241 ( V_16 ) ) {
F_2 ( & V_2 -> V_570 . V_571 ) ;
F_9 ( F_374 ( V_2 , V_572 , 0xc0000000 ) ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
} else {
F_129 ( V_573 , V_574 ) ;
if ( F_62 ( F_375 ( V_573 ) & V_574 , 50 ) )
F_132 ( L_92 ) ;
}
}
void F_376 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! V_38 -> V_115 -> V_569 )
return;
F_373 ( V_2 , V_38 -> V_170 ) ;
if ( F_241 ( V_16 ) ) {
F_2 ( & V_2 -> V_570 . V_571 ) ;
F_9 ( F_374 ( V_2 , V_572 , 0 ) ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
if ( F_62 ( ( F_11 ( V_573 ) & V_574 ) == 0 , 42 ) )
F_132 ( L_93 ) ;
} else {
F_129 ( V_573 , 0 ) ;
F_130 ( V_573 ) ;
}
F_313 ( V_16 , V_38 -> V_119 ) ;
}
static void F_377 ( struct V_111 * V_38 )
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
if ( F_240 ( V_16 ) && V_37 -> V_115 -> V_569 &&
( ( F_11 ( F_378 ( V_119 ) ) & V_576 ) ==
V_577 ) ) {
F_376 ( V_37 ) ;
V_575 = true ;
}
for ( V_50 = 0 ; V_50 < 256 ; V_50 ++ ) {
T_5 V_578 ;
if ( F_170 ( V_16 ) )
V_578 = F_379 ( V_119 , V_50 ) ;
else
V_578 = F_380 ( V_119 , V_50 ) ;
F_129 ( V_578 ,
( V_37 -> V_579 [ V_50 ] << 16 ) |
( V_37 -> V_580 [ V_50 ] << 8 ) |
V_37 -> V_581 [ V_50 ] ) ;
}
if ( V_575 )
F_372 ( V_37 ) ;
}
static void F_381 ( struct V_37 * V_37 )
{
if ( V_37 -> V_582 ) {
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_2 ( & V_16 -> V_307 ) ;
V_2 -> V_583 . V_584 = false ;
( void ) F_382 ( V_37 -> V_582 ) ;
V_2 -> V_583 . V_584 = true ;
F_4 ( & V_16 -> V_307 ) ;
}
}
static void
F_383 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
F_372 ( V_37 ) ;
if ( F_33 ( V_16 ) )
F_354 ( V_2 , V_119 , true ) ;
F_384 ( V_2 ) ;
F_385 ( V_2 ) ;
}
static void
F_225 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
if ( F_33 ( V_16 ) )
F_354 ( V_2 , V_119 , false ) ;
if ( F_170 ( V_16 ) ) {
F_386 ( V_2 , false ) ;
V_2 -> V_585 . V_586 . V_587 = false ;
F_313 ( V_16 , V_119 ) ;
}
F_376 ( V_37 ) ;
}
static void F_387 ( struct V_37 * V_38 )
{
struct V_588 * V_589 = & V_38 -> V_589 ;
struct V_43 * V_212 =
F_273 ( V_38 -> V_40 . V_36 ) ;
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
F_388 ( V_16 , V_589 -> V_590 ) ;
V_38 -> V_585 . V_591 = true ;
if ( V_212 -> V_592 && V_212 -> V_40 . V_112 )
F_389 ( & V_38 -> V_40 ) ;
if ( V_589 -> V_593 )
F_390 ( V_38 ) ;
if ( V_589 -> V_594 )
F_383 ( & V_38 -> V_40 ) ;
memset ( V_589 , 0 , sizeof( * V_589 ) ) ;
}
static void F_391 ( struct V_43 * V_458 )
{
struct V_37 * V_38 = F_50 ( V_458 -> V_40 . V_38 ) ;
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_588 * V_589 = & V_38 -> V_589 ;
struct V_43 * V_212 =
F_273 ( V_38 -> V_40 . V_36 ) ;
struct V_45 * V_595 = V_458 -> V_40 . V_36 ;
struct V_302 * V_113 = V_38 -> V_40 . V_113 ;
struct V_279 * V_596 =
F_392 ( V_595 , V_113 ) ;
bool V_597 = F_19 ( & V_212 -> V_40 ) ;
if ( V_589 -> V_593 )
F_393 ( V_38 ) ;
if ( V_596 ) {
struct V_359 * V_598 =
F_220 ( V_113 -> V_36 ) ;
struct V_359 * V_599 =
F_220 ( V_596 ) ;
if ( V_599 -> V_362 &&
( V_597 || ! V_598 -> V_362 ) )
F_225 ( & V_38 -> V_40 ) ;
}
if ( V_212 -> V_600 ) {
V_38 -> V_585 . V_591 = false ;
if ( V_458 -> V_40 . V_112 )
F_386 ( V_2 , false ) ;
}
if ( ! F_19 ( & V_212 -> V_40 ) && V_212 -> V_592 )
F_389 ( & V_38 -> V_40 ) ;
}
static void F_394 ( struct V_111 * V_38 , unsigned V_363 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_302 * V_81 ;
int V_119 = V_37 -> V_119 ;
F_381 ( V_37 ) ;
F_395 (p, dev, plane_mask)
F_219 ( V_81 ) -> V_364 ( V_81 , V_38 ) ;
F_388 ( V_16 , F_396 ( V_119 ) ) ;
}
static void F_397 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 ;
if ( F_9 ( V_37 -> V_112 ) )
return;
if ( V_37 -> V_115 -> V_261 )
F_398 ( V_2 , V_119 , false ) ;
if ( V_37 -> V_115 -> V_261 )
F_150 ( V_37 ) ;
if ( V_37 -> V_115 -> V_531 )
F_399 ( V_37 , V_601 ) ;
F_400 ( V_37 ) ;
if ( V_37 -> V_115 -> V_261 ) {
F_401 ( V_37 ,
& V_37 -> V_115 -> V_602 , NULL ) ;
}
F_402 ( V_38 ) ;
V_37 -> V_112 = true ;
F_354 ( V_2 , V_119 , true ) ;
F_22 (dev, crtc, encoder)
if ( V_42 -> V_603 )
V_42 -> V_603 ( V_42 ) ;
if ( V_37 -> V_115 -> V_261 ) {
F_309 ( V_37 ) ;
} else {
F_164 ( V_2 , V_119 ) ;
F_165 ( V_2 , V_119 ) ;
}
F_294 ( V_37 ) ;
F_377 ( V_38 ) ;
F_389 ( V_38 ) ;
F_167 ( V_37 ) ;
if ( V_37 -> V_115 -> V_261 )
F_351 ( V_38 ) ;
F_101 ( V_38 ) ;
F_403 ( V_38 ) ;
F_22 (dev, crtc, encoder)
V_42 -> V_243 ( V_42 ) ;
if ( F_107 ( V_16 ) )
F_363 ( V_16 , V_37 -> V_119 ) ;
if ( V_37 -> V_115 -> V_261 )
F_313 ( V_16 , V_119 ) ;
F_398 ( V_2 , V_119 , true ) ;
}
static bool F_404 ( struct V_37 * V_38 )
{
return F_405 ( V_38 -> V_40 . V_16 ) && V_38 -> V_119 == V_147 ;
}
static void F_406 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 , V_604 ;
struct V_43 * V_212 =
F_273 ( V_38 -> V_36 ) ;
if ( F_9 ( V_37 -> V_112 ) )
return;
if ( V_37 -> V_115 -> V_261 )
F_398 ( V_2 , V_256 ,
false ) ;
if ( F_68 ( V_37 ) )
F_152 ( V_37 ) ;
if ( V_37 -> V_115 -> V_531 )
F_399 ( V_37 , V_601 ) ;
F_400 ( V_37 ) ;
if ( V_37 -> V_115 -> V_121 != V_605 ) {
F_129 ( F_407 ( V_37 -> V_115 -> V_121 ) ,
V_37 -> V_115 -> V_606 - 1 ) ;
}
if ( V_37 -> V_115 -> V_261 ) {
F_401 ( V_37 ,
& V_37 -> V_115 -> V_602 , NULL ) ;
}
F_408 ( V_38 ) ;
F_291 ( V_38 ) ;
V_37 -> V_112 = true ;
if ( V_37 -> V_115 -> V_261 )
F_354 ( V_2 , V_119 , false ) ;
else
F_354 ( V_2 , V_119 , true ) ;
F_22 (dev, crtc, encoder) {
if ( V_42 -> V_603 )
V_42 -> V_603 ( V_42 ) ;
}
if ( V_37 -> V_115 -> V_261 )
V_2 -> V_451 . V_527 ( V_38 ) ;
if ( ! V_37 -> V_115 -> V_260 )
F_409 ( V_37 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 )
F_293 ( V_37 ) ;
else
F_294 ( V_37 ) ;
F_377 ( V_38 ) ;
F_410 ( V_38 ) ;
if ( ! V_37 -> V_115 -> V_260 )
F_411 ( V_38 ) ;
F_389 ( V_38 ) ;
F_167 ( V_37 ) ;
if ( V_37 -> V_115 -> V_261 )
F_357 ( V_38 ) ;
if ( V_37 -> V_115 -> V_607 )
F_412 ( V_38 , true ) ;
F_101 ( V_38 ) ;
F_403 ( V_38 ) ;
F_22 (dev, crtc, encoder) {
V_42 -> V_243 ( V_42 ) ;
F_413 ( V_42 , true ) ;
}
if ( V_37 -> V_115 -> V_261 ) {
F_313 ( V_16 , V_119 ) ;
F_313 ( V_16 , V_119 ) ;
F_354 ( V_2 , V_119 , true ) ;
F_398 ( V_2 , V_256 ,
true ) ;
}
V_604 = V_212 -> V_604 ;
if ( F_240 ( V_16 ) && V_604 != V_608 ) {
F_313 ( V_16 , V_604 ) ;
F_313 ( V_16 , V_604 ) ;
}
}
static void F_295 ( struct V_37 * V_38 , bool V_609 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
if ( V_609 || V_38 -> V_115 -> V_459 . V_180 ) {
F_129 ( F_368 ( V_119 ) , 0 ) ;
F_129 ( F_370 ( V_119 ) , 0 ) ;
F_129 ( F_371 ( V_119 ) , 0 ) ;
}
}
static void F_414 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 ;
if ( V_37 -> V_115 -> V_261 )
F_398 ( V_2 , V_119 , false ) ;
F_22 (dev, crtc, encoder)
V_42 -> V_244 ( V_42 ) ;
F_415 ( V_38 ) ;
F_101 ( V_38 ) ;
if ( V_37 -> V_115 -> V_261 )
F_354 ( V_2 , V_119 , false ) ;
F_175 ( V_37 ) ;
F_295 ( V_37 , false ) ;
if ( V_37 -> V_115 -> V_261 ) {
F_311 ( V_38 ) ;
F_354 ( V_2 , V_119 , true ) ;
}
F_22 (dev, crtc, encoder)
if ( V_42 -> V_610 )
V_42 -> V_610 ( V_42 ) ;
if ( V_37 -> V_115 -> V_261 ) {
F_163 ( V_2 , V_119 ) ;
if ( F_107 ( V_16 ) ) {
T_5 V_9 ;
T_1 V_460 ;
V_9 = F_111 ( V_119 ) ;
V_460 = F_11 ( V_9 ) ;
V_460 &= ~ ( V_536 |
V_188 ) ;
V_460 |= V_611 ;
F_129 ( V_9 , V_460 ) ;
V_460 = F_11 ( V_529 ) ;
V_460 &= ~ ( F_355 ( V_119 ) | F_356 ( V_119 ) ) ;
F_129 ( V_529 , V_460 ) ;
}
F_310 ( V_37 ) ;
}
F_398 ( V_2 , V_119 , true ) ;
}
static void F_416 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
enum V_118 V_121 = V_37 -> V_115 -> V_121 ;
if ( V_37 -> V_115 -> V_261 )
F_398 ( V_2 , V_256 ,
false ) ;
F_22 (dev, crtc, encoder) {
F_413 ( V_42 , false ) ;
V_42 -> V_244 ( V_42 ) ;
}
F_415 ( V_38 ) ;
F_101 ( V_38 ) ;
F_175 ( V_37 ) ;
if ( V_37 -> V_115 -> V_607 )
F_412 ( V_38 , false ) ;
if ( ! V_37 -> V_115 -> V_260 )
F_417 ( V_2 , V_121 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 )
F_367 ( V_37 ) ;
else
F_295 ( V_37 , false ) ;
if ( ! V_37 -> V_115 -> V_260 )
F_418 ( V_37 ) ;
F_22 (dev, crtc, encoder)
if ( V_42 -> V_610 )
V_42 -> V_610 ( V_42 ) ;
if ( V_37 -> V_115 -> V_261 ) {
F_166 ( V_2 ) ;
F_324 ( V_2 ) ;
F_419 ( V_38 ) ;
F_398 ( V_2 , V_256 ,
true ) ;
}
}
static void F_420 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_43 * V_212 = V_38 -> V_115 ;
if ( ! V_212 -> V_612 . V_613 )
return;
F_9 ( F_11 ( V_614 ) & V_615 ) ;
F_127 ( V_2 , V_38 -> V_119 ) ;
F_129 ( V_616 , V_212 -> V_612 . V_617 ) ;
F_129 ( V_614 , V_212 -> V_612 . V_613 ) ;
F_129 ( F_421 ( V_38 -> V_119 ) , 0 ) ;
}
static enum V_164 F_422 ( enum V_217 V_217 )
{
switch ( V_217 ) {
case V_618 :
return V_619 ;
case V_231 :
return V_620 ;
case V_233 :
return V_621 ;
case V_235 :
return V_622 ;
case V_623 :
return V_624 ;
default:
F_181 ( V_217 ) ;
return V_625 ;
}
}
static enum V_164 F_423 ( enum V_217 V_217 )
{
switch ( V_217 ) {
case V_618 :
return V_626 ;
case V_231 :
return V_627 ;
case V_233 :
return V_628 ;
case V_235 :
return V_629 ;
case V_623 :
return V_629 ;
default:
F_181 ( V_217 ) ;
return V_626 ;
}
}
enum V_164
F_424 ( struct V_41 * V_41 )
{
struct V_15 * V_16 = V_41 -> V_40 . V_16 ;
struct V_226 * V_544 ;
switch ( V_41 -> type ) {
case V_630 :
F_47 ( ! F_71 ( V_16 ) ) ;
case V_524 :
case V_63 :
case V_525 :
V_544 = F_350 ( & V_41 -> V_40 ) ;
return F_422 ( V_544 -> V_217 ) ;
case V_631 :
V_544 = F_425 ( & V_41 -> V_40 ) -> V_113 ;
return F_422 ( V_544 -> V_217 ) ;
case V_64 :
return V_632 ;
case V_633 :
return V_634 ;
default:
return V_625 ;
}
}
enum V_164
F_426 ( struct V_41 * V_41 )
{
struct V_15 * V_16 = V_41 -> V_40 . V_16 ;
struct V_226 * V_544 ;
switch ( V_41 -> type ) {
case V_630 :
case V_63 :
F_47 ( ! F_71 ( V_16 ) ) ;
case V_524 :
case V_525 :
V_544 = F_350 ( & V_41 -> V_40 ) ;
return F_423 ( V_544 -> V_217 ) ;
case V_631 :
V_544 = F_425 ( & V_41 -> V_40 ) -> V_113 ;
return F_423 ( V_544 -> V_217 ) ;
default:
F_181 ( V_41 -> type ) ;
return V_626 ;
}
}
static unsigned long F_427 ( struct V_111 * V_38 ,
struct V_43 * V_44 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_635 * V_42 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_119 V_119 = V_37 -> V_119 ;
unsigned long V_636 ;
enum V_118 V_118 = V_44 -> V_121 ;
if ( ! V_44 -> V_40 . V_112 )
return 0 ;
V_636 = F_232 ( F_428 ( V_119 ) ) ;
V_636 |= F_232 ( F_86 ( V_118 ) ) ;
if ( V_44 -> V_459 . V_180 ||
V_44 -> V_459 . V_637 )
V_636 |= F_232 ( F_429 ( V_119 ) ) ;
F_430 (encoder, dev, crtc_state->base.encoder_mask) {
struct V_41 * V_41 = F_25 ( V_42 ) ;
V_636 |= F_232 ( F_424 ( V_41 ) ) ;
}
return V_636 ;
}
static unsigned long
F_431 ( struct V_111 * V_38 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_38 -> V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_164 V_638 ;
unsigned long V_639 , V_640 , V_641 ;
V_641 = V_37 -> V_642 ;
V_37 -> V_642 = V_640 =
F_427 ( V_38 , V_44 ) ;
V_639 = V_640 & ~ V_641 ;
F_432 (domain, domains)
F_155 ( V_2 , V_638 ) ;
return V_641 & ~ V_640 ;
}
static void F_433 ( struct V_1 * V_2 ,
unsigned long V_639 )
{
enum V_164 V_638 ;
F_432 (domain, domains)
F_88 ( V_2 , V_638 ) ;
}
static int F_434 ( struct V_1 * V_2 )
{
int V_643 = V_2 -> V_643 ;
if ( F_60 ( V_2 ) -> V_127 >= 9 ||
F_240 ( V_2 ) || F_241 ( V_2 ) )
return V_643 ;
else if ( F_14 ( V_2 ) )
return V_643 * 95 / 100 ;
else if ( F_60 ( V_2 ) -> V_127 < 4 )
return 2 * V_643 * 90 / 100 ;
else
return V_643 * 90 / 100 ;
}
static void F_435 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_436 ( V_16 ) || F_437 ( V_16 ) ) {
T_1 V_54 = F_11 ( V_644 ) & V_645 ;
if ( V_54 == V_646 )
V_2 -> V_643 = 675000 ;
else if ( V_54 == V_647 )
V_2 -> V_643 = 540000 ;
else if ( V_54 == V_648 )
V_2 -> V_643 = 450000 ;
else
V_2 -> V_643 = 337500 ;
} else if ( F_241 ( V_16 ) ) {
if ( F_11 ( V_649 ) & V_650 )
V_2 -> V_643 = 450000 ;
else if ( F_438 ( V_16 ) )
V_2 -> V_643 = 450000 ;
else if ( F_439 ( V_16 ) )
V_2 -> V_643 = 540000 ;
else
V_2 -> V_643 = 675000 ;
} else if ( F_14 ( V_16 ) ) {
V_2 -> V_643 = 320000 ;
} else if ( F_13 ( V_16 ) ) {
V_2 -> V_643 = 400000 ;
} else {
V_2 -> V_643 = V_2 -> V_651 ;
}
V_2 -> V_652 = F_434 ( V_2 ) ;
F_16 ( L_94 ,
V_2 -> V_643 ) ;
F_16 ( L_95 ,
V_2 -> V_652 ) ;
}
static void F_440 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_651 = V_2 -> V_451 . V_653 ( V_16 ) ;
F_16 ( L_96 ,
V_2 -> V_651 ) ;
if ( F_13 ( V_16 ) || F_14 ( V_16 ) ) {
F_129 ( V_654 , F_189 ( V_2 -> V_651 , 1000 ) ) ;
}
if ( V_2 -> V_643 == 0 )
F_435 ( V_16 ) ;
}
static void F_441 ( struct V_15 * V_16 , int V_655 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_11 ;
T_2 V_656 ;
T_2 V_657 ;
int V_306 ;
switch ( V_655 ) {
case 144000 :
V_11 = V_658 ;
V_656 = F_442 ( 60 ) ;
break;
case 288000 :
V_11 = V_659 ;
V_656 = F_442 ( 60 ) ;
break;
case 384000 :
V_11 = V_660 ;
V_656 = F_442 ( 60 ) ;
break;
case 576000 :
V_11 = V_661 ;
V_656 = F_442 ( 60 ) ;
break;
case 624000 :
V_11 = V_661 ;
V_656 = F_442 ( 65 ) ;
break;
case 19200 :
V_656 = 0 ;
V_11 = 0 ;
break;
default:
F_132 ( L_97 , V_655 ) ;
return;
}
F_2 ( & V_2 -> V_570 . V_571 ) ;
V_306 = F_374 ( V_2 , V_662 ,
0x80000000 ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
if ( V_306 ) {
F_132 ( L_98 ,
V_306 , V_655 ) ;
return;
}
V_657 = F_11 ( V_663 ) & V_664 ;
V_657 = V_657 * 500 + 1000 ;
if ( V_655 == 19200 || V_655 == 624000 ||
V_657 == 624000 ) {
F_129 ( V_665 , ~ V_666 ) ;
if ( F_62 ( ! ( F_11 ( V_665 ) & V_667 ) ,
1 ) )
F_132 ( L_99 ) ;
}
if ( V_655 != 19200 ) {
T_2 V_10 ;
V_10 = F_11 ( V_668 ) ;
V_10 &= ~ V_669 ;
V_10 |= V_656 ;
F_129 ( V_668 , V_10 ) ;
F_129 ( V_665 , V_666 ) ;
if ( F_62 ( F_11 ( V_665 ) & V_667 , 1 ) )
F_132 ( L_100 ) ;
V_10 = F_11 ( V_663 ) ;
V_10 &= ~ V_670 ;
V_10 |= V_11 ;
V_10 &= ~ V_671 ;
if ( V_655 >= 500000 )
V_10 |= V_671 ;
V_10 &= ~ V_664 ;
V_10 |= ( V_655 - 1000 ) / 500 ;
F_129 ( V_663 , V_10 ) ;
}
F_2 ( & V_2 -> V_570 . V_571 ) ;
V_306 = F_374 ( V_2 , V_662 ,
F_189 ( V_655 , 25000 ) ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
if ( V_306 ) {
F_132 ( L_101 ,
V_306 , V_655 ) ;
return;
}
F_440 ( V_16 ) ;
}
void F_443 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_10 ;
V_10 = F_11 ( V_672 ) ;
V_10 &= ~ V_673 ;
F_129 ( V_672 , V_10 ) ;
F_155 ( V_2 , V_242 ) ;
if ( F_11 ( V_665 ) & V_666 ) {
F_153 ( L_102 ) ;
return;
}
F_441 ( V_16 , 624000 ) ;
F_129 ( V_674 , F_11 ( V_674 ) | V_675 ) ;
F_130 ( V_674 ) ;
F_131 ( 10 ) ;
if ( ! ( F_11 ( V_674 ) & V_676 ) )
F_132 ( L_103 ) ;
}
void F_444 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
F_129 ( V_674 , F_11 ( V_674 ) & ~ V_675 ) ;
F_130 ( V_674 ) ;
F_131 ( 10 ) ;
if ( F_11 ( V_674 ) & V_676 )
F_132 ( L_104 ) ;
F_441 ( V_16 , 19200 ) ;
F_88 ( V_2 , V_242 ) ;
}
static unsigned int F_445 ( unsigned int V_677 )
{
return ( V_677 - 1000 ) / 500 ;
}
static unsigned int F_446 ( unsigned int V_677 )
{
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < F_308 ( V_678 ) ; V_50 ++ ) {
const struct V_679 * V_680 = & V_678 [ V_50 ] ;
if ( V_680 -> V_677 == V_677 )
return V_680 -> V_85 ;
}
return 8100 ;
}
static void
F_447 ( struct V_1 * V_2 , unsigned int V_681 )
{
unsigned int V_682 ;
T_1 V_10 ;
V_10 = F_11 ( V_663 ) ;
V_10 &= ~ V_683 | ~ V_664 ;
V_10 |= V_684 ;
if ( V_681 == 8640 )
V_682 = 308570 ;
else
V_682 = 337500 ;
V_10 = V_684 | F_445 ( V_682 ) ;
F_129 ( V_663 , V_10 ) ;
F_130 ( V_663 ) ;
V_10 = F_11 ( V_685 ) ;
V_10 &= ~ ( F_448 ( V_686 ) | F_449 ( V_686 ) |
F_450 ( V_686 ) ) ;
V_10 |= F_451 ( V_686 ) ;
if ( V_681 == 8640 )
V_10 |= F_452 ( V_687 ,
V_686 ) ;
else
V_10 |= F_452 ( V_688 ,
V_686 ) ;
F_129 ( V_685 , V_10 ) ;
F_130 ( V_685 ) ;
F_129 ( V_689 , F_11 ( V_689 ) | V_690 ) ;
if ( F_62 ( F_11 ( V_689 ) & V_691 , 5 ) )
F_132 ( L_105 ) ;
}
static bool F_453 ( struct V_1 * V_2 )
{
int V_306 ;
T_1 V_10 ;
V_10 = V_692 ;
F_2 ( & V_2 -> V_570 . V_571 ) ;
V_306 = F_454 ( V_2 , V_693 , & V_10 ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
return V_306 == 0 && ( V_10 & V_694 ) ;
}
static bool F_455 ( struct V_1 * V_2 )
{
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < 15 ; V_50 ++ ) {
if ( F_453 ( V_2 ) )
return true ;
F_131 ( 10 ) ;
}
return false ;
}
static void F_456 ( struct V_1 * V_2 , unsigned int V_677 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_1 V_695 , V_696 ;
F_16 ( L_106 , V_677 ) ;
if ( ! F_455 ( V_2 ) ) {
F_132 ( L_107 ) ;
return;
}
switch( V_677 ) {
case 450000 :
case 432000 :
V_695 = V_697 ;
V_696 = 1 ;
break;
case 540000 :
V_695 = V_698 ;
V_696 = 2 ;
break;
case 308570 :
case 337500 :
default:
V_695 = V_684 ;
V_696 = 0 ;
break;
case 617140 :
case 675000 :
V_695 = V_699 ;
V_696 = 3 ;
break;
}
F_129 ( V_663 , V_695 | F_445 ( V_677 ) ) ;
F_130 ( V_663 ) ;
F_2 ( & V_2 -> V_570 . V_571 ) ;
F_374 ( V_2 , V_693 , V_696 ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
F_440 ( V_16 ) ;
}
void F_457 ( struct V_1 * V_2 )
{
F_129 ( V_674 , F_11 ( V_674 ) & ~ V_675 ) ;
F_130 ( V_674 ) ;
F_131 ( 10 ) ;
if ( F_11 ( V_674 ) & V_676 )
F_132 ( L_108 ) ;
F_129 ( V_689 , F_11 ( V_689 ) & ~ V_690 ) ;
if ( F_62 ( ! ( F_11 ( V_689 ) & V_691 ) , 1 ) )
F_132 ( L_109 ) ;
}
void F_458 ( struct V_1 * V_2 )
{
unsigned int V_681 ;
if ( ! ( F_11 ( V_689 ) & V_690 ) ) {
V_681 = F_446 ( V_2 -> V_700 ) ;
F_447 ( V_2 , V_681 ) ;
}
F_456 ( V_2 , V_2 -> V_700 ) ;
F_129 ( V_674 , F_11 ( V_674 ) | V_675 ) ;
F_130 ( V_674 ) ;
F_131 ( 10 ) ;
if ( ! ( F_11 ( V_674 ) & V_676 ) )
F_132 ( L_110 ) ;
}
int F_459 ( struct V_1 * V_2 )
{
T_2 V_701 = F_11 ( V_689 ) ;
T_2 V_702 = F_11 ( V_663 ) ;
int V_677 = V_2 -> V_700 ;
if ( ( F_11 ( F_460 ( 0x18 ) ) & 0x00FFFFFF ) == 0 )
goto V_703;
if ( ! ( ( V_701 & V_690 ) && ( V_701 & V_691 ) ) )
goto V_703;
if ( V_702 == ( ( V_702 & V_683 ) | F_445 ( V_677 ) ) )
return false ;
V_703:
V_2 -> V_700 = V_2 -> V_643 ;
F_458 ( V_2 ) ;
return true ;
}
static void F_461 ( struct V_15 * V_16 , int V_704 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 , V_705 ;
F_9 ( V_2 -> V_451 . V_653 ( V_16 )
!= V_2 -> V_651 ) ;
if ( V_704 >= 320000 )
V_705 = 2 ;
else if ( V_704 == 266667 )
V_705 = 1 ;
else
V_705 = 0 ;
F_2 ( & V_2 -> V_570 . V_571 ) ;
V_10 = F_462 ( V_2 , V_706 ) ;
V_10 &= ~ V_707 ;
V_10 |= ( V_705 << V_708 ) ;
F_463 ( V_2 , V_706 , V_10 ) ;
if ( F_62 ( ( F_462 ( V_2 , V_706 ) &
V_709 ) == ( V_705 << V_710 ) ,
50 ) ) {
F_132 ( L_111 ) ;
}
F_4 ( & V_2 -> V_570 . V_571 ) ;
F_2 ( & V_2 -> V_5 ) ;
if ( V_704 == 400000 ) {
T_1 V_11 ;
V_11 = F_7 ( V_2 -> V_3 << 1 , V_704 ) - 1 ;
V_10 = F_3 ( V_2 , V_711 ) ;
V_10 &= ~ V_12 ;
V_10 |= V_11 ;
F_464 ( V_2 , V_711 , V_10 ) ;
if ( F_62 ( ( F_3 ( V_2 , V_711 ) &
V_13 ) == ( V_11 << V_14 ) ,
50 ) )
F_132 ( L_111 ) ;
}
V_10 = F_465 ( V_2 , V_712 ) ;
V_10 &= ~ 0x7f ;
if ( V_704 == 400000 )
V_10 |= 4500 / 250 ;
else
V_10 |= 3000 / 250 ;
F_466 ( V_2 , V_712 , V_10 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_440 ( V_16 ) ;
}
static void F_467 ( struct V_15 * V_16 , int V_704 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 , V_705 ;
F_9 ( V_2 -> V_451 . V_653 ( V_16 )
!= V_2 -> V_651 ) ;
switch ( V_704 ) {
case 333333 :
case 320000 :
case 266667 :
case 200000 :
break;
default:
F_181 ( V_704 ) ;
return;
}
V_705 = F_7 ( V_2 -> V_3 << 1 , V_704 ) - 1 ;
F_2 ( & V_2 -> V_570 . V_571 ) ;
V_10 = F_462 ( V_2 , V_706 ) ;
V_10 &= ~ V_713 ;
V_10 |= ( V_705 << V_714 ) ;
F_463 ( V_2 , V_706 , V_10 ) ;
if ( F_62 ( ( F_462 ( V_2 , V_706 ) &
V_715 ) == ( V_705 << V_716 ) ,
50 ) ) {
F_132 ( L_111 ) ;
}
F_4 ( & V_2 -> V_570 . V_571 ) ;
F_440 ( V_16 ) ;
}
static int F_468 ( struct V_1 * V_2 ,
int V_717 )
{
int V_718 = ( V_2 -> V_3 << 1 ) % 320000 != 0 ? 333333 : 320000 ;
int V_54 = F_14 ( V_2 ) ? 95 : 90 ;
if ( ! F_14 ( V_2 ) &&
V_717 > V_718 * V_54 / 100 )
return 400000 ;
else if ( V_717 > 266667 * V_54 / 100 )
return V_718 ;
else if ( V_717 > 0 )
return 266667 ;
else
return 200000 ;
}
static int F_469 ( struct V_1 * V_2 ,
int V_717 )
{
if ( V_717 > 576000 * 9 / 10 )
return 624000 ;
else if ( V_717 > 384000 * 9 / 10 )
return 576000 ;
else if ( V_717 > 288000 * 9 / 10 )
return 384000 ;
else if ( V_717 > 144000 * 9 / 10 )
return 288000 ;
else
return 144000 ;
}
static int F_470 ( struct V_15 * V_16 ,
struct V_45 * V_36 )
{
struct V_719 * V_360 = F_362 ( V_36 ) ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_111 * V_38 ;
struct V_35 * V_44 ;
unsigned V_717 = 0 , V_50 ;
enum V_119 V_119 ;
memcpy ( V_360 -> V_720 , V_2 -> V_720 ,
sizeof( V_360 -> V_720 ) ) ;
F_471 (state, crtc, crtc_state, i) {
int V_721 = 0 ;
if ( V_44 -> V_243 )
V_721 = V_44 -> V_116 . V_117 ;
V_360 -> V_720 [ V_50 ] = V_721 ;
}
F_93 (dev_priv, pipe)
V_717 = V_91 ( V_360 -> V_720 [ V_119 ] , V_717 ) ;
return V_717 ;
}
static int F_472 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_717 = F_470 ( V_16 , V_36 ) ;
struct V_719 * V_360 =
F_362 ( V_36 ) ;
if ( V_717 < 0 )
return V_717 ;
V_360 -> V_704 = V_360 -> V_722 =
F_468 ( V_2 , V_717 ) ;
if ( ! V_360 -> V_723 )
V_360 -> V_722 = F_468 ( V_2 , 0 ) ;
return 0 ;
}
static int F_473 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_717 = F_470 ( V_16 , V_36 ) ;
struct V_719 * V_360 =
F_362 ( V_36 ) ;
if ( V_717 < 0 )
return V_717 ;
V_360 -> V_704 = V_360 -> V_722 =
F_469 ( V_2 , V_717 ) ;
if ( ! V_360 -> V_723 )
V_360 -> V_722 = F_469 ( V_2 , 0 ) ;
return 0 ;
}
static void F_474 ( struct V_1 * V_2 )
{
unsigned int V_724 , V_725 ;
if ( F_14 ( V_2 ) )
V_725 = F_475 ( 12 ) ;
else
V_725 = F_475 ( 8 ) ;
if ( V_2 -> V_651 >= V_2 -> V_31 ) {
if ( F_14 ( V_2 ) )
V_724 = V_726 ;
else
V_724 = F_475 ( 15 ) ;
} else {
V_724 = V_725 ;
}
F_129 ( V_727 , V_728 |
V_725 ) ;
F_129 ( V_727 , V_728 |
V_724 | V_729 ) ;
F_9 ( F_11 ( V_727 ) & V_729 ) ;
}
static void F_476 ( struct V_45 * V_595 )
{
struct V_15 * V_16 = V_595 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_719 * V_730 =
F_362 ( V_595 ) ;
unsigned V_731 = V_730 -> V_722 ;
F_155 ( V_2 , V_732 ) ;
if ( F_14 ( V_16 ) )
F_467 ( V_16 , V_731 ) ;
else
F_461 ( V_16 , V_731 ) ;
F_474 ( V_2 ) ;
F_88 ( V_2 , V_732 ) ;
}
static void F_477 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = F_185 ( V_16 ) ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 ;
if ( F_9 ( V_37 -> V_112 ) )
return;
if ( V_37 -> V_115 -> V_531 )
F_399 ( V_37 , V_601 ) ;
F_400 ( V_37 ) ;
if ( F_14 ( V_16 ) && V_119 == V_156 ) {
struct V_1 * V_2 = V_16 -> V_17 ;
F_129 ( F_478 ( V_119 ) , V_733 ) ;
F_129 ( F_479 ( V_119 ) , 0 ) ;
}
F_480 ( V_37 ) ;
V_37 -> V_112 = true ;
F_354 ( V_2 , V_119 , true ) ;
F_22 (dev, crtc, encoder)
if ( V_42 -> V_734 )
V_42 -> V_734 ( V_42 ) ;
if ( ! V_37 -> V_115 -> V_260 ) {
if ( F_14 ( V_16 ) ) {
F_481 ( V_37 , V_37 -> V_115 ) ;
F_134 ( V_37 , V_37 -> V_115 ) ;
} else {
F_482 ( V_37 , V_37 -> V_115 ) ;
F_126 ( V_37 , V_37 -> V_115 ) ;
}
}
F_22 (dev, crtc, encoder)
if ( V_42 -> V_603 )
V_42 -> V_603 ( V_42 ) ;
F_420 ( V_37 ) ;
F_377 ( V_38 ) ;
F_167 ( V_37 ) ;
F_101 ( V_38 ) ;
F_403 ( V_38 ) ;
F_22 (dev, crtc, encoder)
V_42 -> V_243 ( V_42 ) ;
}
static void F_483 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_129 ( F_484 ( V_38 -> V_119 ) , V_38 -> V_115 -> V_213 . V_735 ) ;
F_129 ( F_485 ( V_38 -> V_119 ) , V_38 -> V_115 -> V_213 . V_736 ) ;
}
static void F_486 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = F_185 ( V_16 ) ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 ;
if ( F_9 ( V_37 -> V_112 ) )
return;
F_483 ( V_37 ) ;
if ( V_37 -> V_115 -> V_531 )
F_399 ( V_37 , V_601 ) ;
F_400 ( V_37 ) ;
F_480 ( V_37 ) ;
V_37 -> V_112 = true ;
if ( ! F_33 ( V_16 ) )
F_354 ( V_2 , V_119 , true ) ;
F_22 (dev, crtc, encoder)
if ( V_42 -> V_603 )
V_42 -> V_603 ( V_42 ) ;
F_141 ( V_37 ) ;
F_420 ( V_37 ) ;
F_377 ( V_38 ) ;
F_389 ( V_38 ) ;
F_167 ( V_37 ) ;
F_101 ( V_38 ) ;
F_403 ( V_38 ) ;
F_22 (dev, crtc, encoder)
V_42 -> V_243 ( V_42 ) ;
}
static void F_487 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! V_38 -> V_115 -> V_612 . V_613 )
return;
F_127 ( V_2 , V_38 -> V_119 ) ;
F_16 ( L_112 ,
F_11 ( V_614 ) ) ;
F_129 ( V_614 , 0 ) ;
}
static void F_488 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 ;
F_313 ( V_16 , V_119 ) ;
F_22 (dev, crtc, encoder)
V_42 -> V_244 ( V_42 ) ;
F_415 ( V_38 ) ;
F_101 ( V_38 ) ;
F_175 ( V_37 ) ;
F_487 ( V_37 ) ;
F_22 (dev, crtc, encoder)
if ( V_42 -> V_610 )
V_42 -> V_610 ( V_42 ) ;
if ( ! V_37 -> V_115 -> V_260 ) {
if ( F_14 ( V_16 ) )
F_146 ( V_2 , V_119 ) ;
else if ( F_13 ( V_16 ) )
F_145 ( V_2 , V_119 ) ;
else
F_144 ( V_37 ) ;
}
F_22 (dev, crtc, encoder)
if ( V_42 -> V_737 )
V_42 -> V_737 ( V_42 ) ;
if ( ! F_33 ( V_16 ) )
F_354 ( V_2 , V_119 , false ) ;
}
static void F_489 ( struct V_111 * V_38 )
{
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_1 * V_2 = F_185 ( V_38 -> V_16 ) ;
enum V_164 V_638 ;
unsigned long V_639 ;
if ( ! V_37 -> V_112 )
return;
if ( F_220 ( V_38 -> V_113 -> V_36 ) -> V_362 ) {
F_9 ( V_37 -> V_457 ) ;
F_225 ( V_38 ) ;
F_394 ( V_38 , 1 << F_224 ( V_38 -> V_113 ) ) ;
F_220 ( V_38 -> V_113 -> V_36 ) -> V_362 = false ;
}
V_2 -> V_451 . V_738 ( V_38 ) ;
V_37 -> V_112 = false ;
F_490 ( V_37 ) ;
F_389 ( V_38 ) ;
F_156 ( V_37 ) ;
V_639 = V_37 -> V_642 ;
F_432 (domain, domains)
F_88 ( V_2 , V_638 ) ;
V_37 -> V_642 = 0 ;
V_2 -> V_723 &= ~ ( 1 << V_37 -> V_119 ) ;
V_2 -> V_720 [ V_37 -> V_119 ] = 0 ;
}
int F_277 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_185 ( V_16 ) ;
struct V_45 * V_36 ;
int V_306 ;
V_36 = F_491 ( V_16 ) ;
V_306 = F_492 ( V_36 ) ;
if ( V_306 )
F_132 ( L_113 , V_306 ) ;
else
V_2 -> V_739 = V_36 ;
return V_306 ;
}
void F_493 ( struct V_635 * V_42 )
{
struct V_41 * V_41 = F_25 ( V_42 ) ;
F_494 ( V_42 ) ;
F_221 ( V_41 ) ;
}
static void F_495 ( struct V_740 * V_47 )
{
struct V_111 * V_38 = V_47 -> V_40 . V_36 -> V_38 ;
F_153 ( L_114 ,
V_47 -> V_40 . V_40 . V_241 ,
V_47 -> V_40 . V_8 ) ;
if ( V_47 -> V_139 ( V_47 ) ) {
struct V_41 * V_42 = V_47 -> V_42 ;
struct V_48 * V_741 = V_47 -> V_40 . V_36 ;
F_65 ( ! V_38 ,
L_115 ) ;
if ( ! V_38 )
return;
F_65 ( ! V_38 -> V_36 -> V_112 ,
L_116 ) ;
if ( ! V_42 || V_42 -> type == V_631 )
return;
F_65 ( V_741 -> V_52 != & V_42 -> V_40 ,
L_117 ) ;
F_65 ( V_741 -> V_38 != V_42 -> V_40 . V_38 ,
L_118 ) ;
} else {
F_65 ( V_38 && V_38 -> V_36 -> V_112 ,
L_119 ) ;
F_65 ( ! V_38 && V_47 -> V_40 . V_36 -> V_52 ,
L_120 ) ;
}
}
int F_496 ( struct V_740 * V_47 )
{
F_497 ( & V_47 -> V_40 ) ;
if ( ! V_47 -> V_40 . V_36 )
return - V_742 ;
return 0 ;
}
struct V_740 * F_498 ( void )
{
struct V_740 * V_47 ;
V_47 = F_499 ( sizeof *V_47 , V_743 ) ;
if ( ! V_47 )
return NULL ;
if ( F_496 ( V_47 ) < 0 ) {
F_221 ( V_47 ) ;
return NULL ;
}
return V_47 ;
}
bool F_500 ( struct V_740 * V_47 )
{
enum V_119 V_119 = 0 ;
struct V_41 * V_42 = V_47 -> V_42 ;
return V_42 -> V_139 ( V_42 , & V_119 ) ;
}
static int F_501 ( struct V_43 * V_44 )
{
if ( V_44 -> V_40 . V_243 && V_44 -> V_261 )
return V_44 -> V_473 ;
return 0 ;
}
static int F_502 ( struct V_15 * V_16 , enum V_119 V_119 ,
struct V_43 * V_212 )
{
struct V_45 * V_36 = V_212 -> V_40 . V_36 ;
struct V_37 * V_744 ;
struct V_43 * V_745 ;
F_153 ( L_121 ,
F_80 ( V_119 ) , V_212 -> V_473 ) ;
if ( V_212 -> V_473 > 4 ) {
F_153 ( L_122 ,
F_80 ( V_119 ) , V_212 -> V_473 ) ;
return - V_559 ;
}
if ( F_240 ( V_16 ) || F_241 ( V_16 ) ) {
if ( V_212 -> V_473 > 2 ) {
F_153 ( L_123 ,
V_212 -> V_473 ) ;
return - V_559 ;
} else {
return 0 ;
}
}
if ( F_60 ( V_16 ) -> V_746 == 2 )
return 0 ;
switch ( V_119 ) {
case V_147 :
return 0 ;
case V_156 :
if ( V_212 -> V_473 <= 2 )
return 0 ;
V_744 = F_50 ( F_503 ( V_16 , V_523 ) ) ;
V_745 =
F_504 ( V_36 , V_744 ) ;
if ( F_505 ( V_745 ) )
return F_506 ( V_745 ) ;
if ( F_501 ( V_745 ) > 0 ) {
F_153 ( L_124 ,
F_80 ( V_119 ) , V_212 -> V_473 ) ;
return - V_559 ;
}
return 0 ;
case V_523 :
if ( V_212 -> V_473 > 2 ) {
F_153 ( L_125 ,
F_80 ( V_119 ) , V_212 -> V_473 ) ;
return - V_559 ;
}
V_744 = F_50 ( F_503 ( V_16 , V_156 ) ) ;
V_745 =
F_504 ( V_36 , V_744 ) ;
if ( F_505 ( V_745 ) )
return F_506 ( V_745 ) ;
if ( F_501 ( V_745 ) > 2 ) {
F_153 ( L_126 ) ;
return - V_559 ;
}
return 0 ;
default:
F_148 () ;
}
}
static int F_507 ( struct V_37 * V_37 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
const struct V_532 * V_116 = & V_212 -> V_40 . V_116 ;
int V_747 , V_748 , V_749 , V_306 ;
bool V_750 = false ;
V_478:
V_748 = F_17 ( V_16 ) * F_508 ( 100 ) / F_509 ( 1 ) / 10 ;
V_749 = V_116 -> V_117 ;
V_747 = F_510 ( V_749 , V_748 ,
V_212 -> V_751 ) ;
V_212 -> V_473 = V_747 ;
F_511 ( V_212 -> V_751 , V_747 , V_749 ,
V_748 , & V_212 -> V_602 ) ;
V_306 = F_502 ( V_37 -> V_40 . V_16 ,
V_37 -> V_119 , V_212 ) ;
if ( V_306 == - V_559 && V_212 -> V_751 > 6 * 3 ) {
V_212 -> V_751 -= 2 * 3 ;
F_153 ( L_127 ,
V_212 -> V_751 ) ;
V_750 = true ;
V_212 -> V_752 = true ;
goto V_478;
}
if ( V_750 )
return V_753 ;
return V_306 ;
}
static bool F_512 ( struct V_1 * V_2 ,
struct V_43 * V_212 )
{
if ( V_212 -> V_751 > 24 )
return false ;
if ( F_240 ( V_2 -> V_16 ) )
return true ;
return F_513 ( V_212 ) <=
V_2 -> V_643 * 95 / 100 ;
}
static void F_514 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
V_212 -> V_569 = V_754 . V_755 &&
F_404 ( V_38 ) &&
F_512 ( V_2 , V_212 ) ;
}
static bool F_515 ( const struct V_37 * V_38 )
{
const struct V_1 * V_2 = F_185 ( V_38 -> V_40 . V_16 ) ;
return F_60 ( V_2 ) -> V_127 < 4 &&
( V_38 -> V_119 == V_147 || F_516 ( V_2 ) ) ;
}
static int F_517 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
const struct V_532 * V_116 = & V_212 -> V_40 . V_116 ;
if ( F_60 ( V_16 ) -> V_127 < 4 ) {
int V_756 = V_2 -> V_643 * 9 / 10 ;
if ( F_515 ( V_38 ) &&
V_116 -> V_117 > V_756 ) {
V_756 *= 2 ;
V_212 -> V_264 = true ;
}
if ( V_116 -> V_117 > V_756 ) {
F_153 ( L_128 ,
V_116 -> V_117 , V_756 ,
F_518 ( V_212 -> V_264 ) ) ;
return - V_559 ;
}
}
if ( ( F_23 ( V_212 , V_55 ) &&
F_27 ( V_16 ) ) || V_212 -> V_264 )
V_212 -> V_387 &= ~ 1 ;
if ( ( F_60 ( V_16 ) -> V_127 > 4 || F_31 ( V_16 ) ) &&
V_116 -> V_757 == V_116 -> V_561 )
return - V_559 ;
if ( F_405 ( V_16 ) )
F_514 ( V_38 , V_212 ) ;
if ( V_212 -> V_261 )
return F_507 ( V_38 , V_212 ) ;
return 0 ;
}
static int F_519 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_185 ( V_16 ) ;
T_2 V_701 = F_11 ( V_689 ) ;
T_2 V_702 = F_11 ( V_663 ) ;
T_2 V_758 ;
if ( ! ( V_701 & V_690 ) )
return 24000 ;
if ( ( V_702 & V_683 ) == V_698 )
return 540000 ;
V_758 = ( F_11 ( V_685 ) &
F_450 ( V_686 ) ) >> 1 ;
if ( V_758 == V_759 ||
V_758 == V_687 ) {
switch ( V_702 & V_683 ) {
case V_697 :
return 432000 ;
case V_684 :
return 308570 ;
case V_699 :
return 617140 ;
default:
F_6 ( 1 , L_129 ) ;
}
} else {
switch ( V_702 & V_683 ) {
case V_697 :
return 450000 ;
case V_684 :
return 337500 ;
case V_699 :
return 675000 ;
default:
F_6 ( 1 , L_129 ) ;
}
}
return 24000 ;
}
static int F_520 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_185 ( V_16 ) ;
T_2 V_702 = F_11 ( V_663 ) ;
T_2 V_760 = F_11 ( V_668 ) & V_669 ;
T_2 V_761 = F_11 ( V_665 ) ;
int V_704 ;
if ( ! ( V_761 & V_666 ) )
return 19200 ;
V_704 = 19200 * V_760 / 2 ;
switch ( V_702 & V_670 ) {
case V_661 :
return V_704 ;
case V_660 :
return V_704 * 2 / 3 ;
case V_659 :
return V_704 / 2 ;
case V_658 :
return V_704 / 4 ;
}
return 19200 ;
}
static int F_521 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_762 = F_11 ( V_763 ) ;
T_2 V_677 = V_762 & V_764 ;
if ( V_762 & V_765 )
return 800000 ;
else if ( F_11 ( V_649 ) & V_650 )
return 450000 ;
else if ( V_677 == V_766 )
return 450000 ;
else if ( V_677 == V_767 )
return 540000 ;
else if ( V_677 == V_768 )
return 337500 ;
else
return 675000 ;
}
static int F_522 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_762 = F_11 ( V_763 ) ;
T_2 V_677 = V_762 & V_764 ;
if ( V_762 & V_765 )
return 800000 ;
else if ( F_11 ( V_649 ) & V_650 )
return 450000 ;
else if ( V_677 == V_766 )
return 450000 ;
else if ( F_523 ( V_16 ) )
return 337500 ;
else
return 540000 ;
}
static int F_524 ( struct V_15 * V_16 )
{
return F_5 ( F_185 ( V_16 ) , L_130 ,
V_711 ) ;
}
static int F_525 ( struct V_15 * V_16 )
{
return 450000 ;
}
static int F_526 ( struct V_15 * V_16 )
{
return 400000 ;
}
static int F_527 ( struct V_15 * V_16 )
{
return 333333 ;
}
static int F_528 ( struct V_15 * V_16 )
{
return 200000 ;
}
static int F_529 ( struct V_15 * V_16 )
{
T_7 V_769 = 0 ;
F_530 ( V_16 -> V_770 , V_771 , & V_769 ) ;
switch ( V_769 & V_772 ) {
case V_773 :
return 266667 ;
case V_774 :
return 333333 ;
case V_775 :
return 444444 ;
case V_776 :
return 200000 ;
default:
F_132 ( L_131 , V_769 ) ;
case V_777 :
return 133333 ;
case V_778 :
return 166667 ;
}
}
static int F_531 ( struct V_15 * V_16 )
{
T_7 V_769 = 0 ;
F_530 ( V_16 -> V_770 , V_771 , & V_769 ) ;
if ( V_769 & V_779 )
return 133333 ;
else {
switch ( V_769 & V_772 ) {
case V_780 :
return 333333 ;
default:
case V_781 :
return 190000 ;
}
}
}
static int F_532 ( struct V_15 * V_16 )
{
return 266667 ;
}
static int F_533 ( struct V_15 * V_16 )
{
T_7 V_782 = 0 ;
if ( V_16 -> V_770 -> V_783 == 0x1 )
return 133333 ;
F_534 ( V_16 -> V_770 -> V_784 ,
F_535 ( 0 , 3 ) , V_785 , & V_782 ) ;
switch ( V_782 & V_786 ) {
case V_787 :
case V_788 :
case V_789 :
return 200000 ;
case V_790 :
return 250000 ;
case V_791 :
return 133333 ;
case V_792 :
case V_793 :
case V_794 :
return 266667 ;
}
return 0 ;
}
static int F_536 ( struct V_15 * V_16 )
{
return 133333 ;
}
static unsigned int F_537 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
static const unsigned int V_795 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 6400000 ,
} ;
static const unsigned int V_796 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 2666667 ,
} ;
static const unsigned int V_797 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 3333333 ,
[ 5 ] = 3566667 ,
[ 6 ] = 4266667 ,
} ;
static const unsigned int V_798 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
} ;
static const unsigned int V_799 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 2666667 ,
[ 5 ] = 4266667 ,
} ;
const unsigned int * V_800 ;
unsigned int V_85 ;
T_8 V_218 = 0 ;
if ( F_538 ( V_16 ) )
V_800 = V_799 ;
else if ( F_31 ( V_16 ) )
V_800 = V_798 ;
else if ( F_192 ( V_16 ) )
V_800 = V_797 ;
else if ( F_32 ( V_16 ) )
V_800 = V_796 ;
else if ( F_539 ( V_16 ) )
V_800 = V_795 ;
else
return 0 ;
V_218 = F_11 ( F_128 ( V_16 ) ? V_801 : V_802 ) ;
V_85 = V_800 [ V_218 & 0x7 ] ;
if ( V_85 == 0 )
F_132 ( L_132 , V_218 ) ;
else
F_153 ( L_133 , V_85 ) ;
return V_85 ;
}
static int F_540 ( struct V_15 * V_16 )
{
unsigned int V_803 , V_85 = F_537 ( V_16 ) ;
T_9 V_218 = 0 ;
F_530 ( V_16 -> V_770 , V_771 , & V_218 ) ;
V_803 = ( V_218 >> 12 ) & 0x1 ;
switch ( V_85 ) {
case 2666667 :
case 4000000 :
case 5333333 :
return V_803 ? 333333 : 222222 ;
case 3200000 :
return V_803 ? 320000 : 228571 ;
default:
F_132 ( L_134 , V_85 , V_218 ) ;
return 222222 ;
}
}
static int F_541 ( struct V_15 * V_16 )
{
static const T_8 V_804 [] = { 16 , 10 , 8 } ;
static const T_8 V_805 [] = { 20 , 12 , 10 } ;
static const T_8 V_806 [] = { 24 , 16 , 14 } ;
const T_8 * V_807 ;
unsigned int V_803 , V_85 = F_537 ( V_16 ) ;
T_9 V_218 = 0 ;
F_530 ( V_16 -> V_770 , V_771 , & V_218 ) ;
V_803 = ( ( V_218 >> 8 ) & 0x1f ) - 1 ;
if ( V_803 >= F_308 ( V_804 ) )
goto V_808;
switch ( V_85 ) {
case 3200000 :
V_807 = V_804 ;
break;
case 4000000 :
V_807 = V_805 ;
break;
case 5333333 :
V_807 = V_806 ;
break;
default:
goto V_808;
}
return F_7 ( V_85 , V_807 [ V_803 ] ) ;
V_808:
F_132 ( L_135 , V_85 , V_218 ) ;
return 200000 ;
}
static int F_542 ( struct V_15 * V_16 )
{
static const T_8 V_804 [] = { 12 , 10 , 8 , 7 , 5 , 16 } ;
static const T_8 V_805 [] = { 14 , 12 , 10 , 8 , 6 , 20 } ;
static const T_8 V_809 [] = { 20 , 14 , 12 , 10 , 8 , 24 } ;
static const T_8 V_806 [] = { 20 , 16 , 12 , 12 , 8 , 28 } ;
const T_8 * V_807 ;
unsigned int V_803 , V_85 = F_537 ( V_16 ) ;
T_9 V_218 = 0 ;
F_530 ( V_16 -> V_770 , V_771 , & V_218 ) ;
V_803 = ( V_218 >> 4 ) & 0x7 ;
if ( V_803 >= F_308 ( V_804 ) )
goto V_808;
switch ( V_85 ) {
case 3200000 :
V_807 = V_804 ;
break;
case 4000000 :
V_807 = V_805 ;
break;
case 4800000 :
V_807 = V_809 ;
break;
case 5333333 :
V_807 = V_806 ;
break;
default:
goto V_808;
}
return F_7 ( V_85 , V_807 [ V_803 ] ) ;
V_808:
F_132 ( L_136 , V_85 , V_218 ) ;
return 190476 ;
}
static void
F_543 ( T_2 * V_810 , T_2 * V_811 )
{
while ( * V_810 > V_812 ||
* V_811 > V_812 ) {
* V_810 >>= 1 ;
* V_811 >>= 1 ;
}
}
static void F_544 ( unsigned int V_79 , unsigned int V_84 ,
T_2 * V_813 , T_2 * V_814 )
{
* V_814 = F_545 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_813 = F_48 ( ( V_89 ) V_79 * * V_814 , V_84 ) ;
F_543 ( V_813 , V_814 ) ;
}
void
F_511 ( int V_815 , int V_816 ,
int V_817 , int V_818 ,
struct V_819 * V_820 )
{
V_820 -> V_821 = 64 ;
F_544 ( V_815 * V_817 ,
V_818 * V_816 * 8 ,
& V_820 -> V_822 , & V_820 -> V_823 ) ;
F_544 ( V_817 , V_818 ,
& V_820 -> V_824 , & V_820 -> V_825 ) ;
}
static inline bool F_546 ( struct V_1 * V_2 )
{
if ( V_754 . V_826 >= 0 )
return V_754 . V_826 != 0 ;
return V_2 -> V_827 . V_828
&& ! ( V_2 -> V_166 & V_829 ) ;
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
F_546 ( V_2 ) && V_51 < 2 ) {
V_53 = V_2 -> V_827 . V_830 ;
F_153 ( L_137 , V_53 ) ;
} else if ( ! F_33 ( V_16 ) ) {
V_53 = 96000 ;
} else {
V_53 = 48000 ;
}
return V_53 ;
}
static T_2 F_547 ( struct V_87 * V_87 )
{
return ( 1 << V_87 -> V_84 ) << 16 | V_87 -> V_80 ;
}
static T_2 F_548 ( struct V_87 * V_87 )
{
return V_87 -> V_84 << 16 | V_87 -> V_88 << 8 | V_87 -> V_80 ;
}
static void F_549 ( struct V_37 * V_38 ,
struct V_43 * V_44 ,
T_4 * V_831 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
T_1 V_832 , V_833 = 0 ;
if ( F_32 ( V_16 ) ) {
V_832 = F_547 ( & V_44 -> V_87 ) ;
if ( V_831 )
V_833 = F_547 ( V_831 ) ;
} else {
V_832 = F_548 ( & V_44 -> V_87 ) ;
if ( V_831 )
V_833 = F_548 ( V_831 ) ;
}
V_44 -> V_213 . V_735 = V_832 ;
V_38 -> V_834 = false ;
if ( F_23 ( V_44 , V_55 ) &&
V_831 ) {
V_44 -> V_213 . V_736 = V_833 ;
V_38 -> V_834 = true ;
} else {
V_44 -> V_213 . V_736 = V_832 ;
}
}
static void F_550 ( struct V_1 * V_2 , enum V_119
V_119 )
{
T_1 V_835 ;
V_835 = F_136 ( V_2 , V_119 , F_551 ( 1 ) ) ;
V_835 &= 0xffffff00 ;
V_835 |= 0x00000030 ;
F_138 ( V_2 , V_119 , F_551 ( 1 ) , V_835 ) ;
V_835 = F_136 ( V_2 , V_119 , V_836 ) ;
V_835 &= 0x8cffffff ;
V_835 = 0x8c000000 ;
F_138 ( V_2 , V_119 , V_836 , V_835 ) ;
V_835 = F_136 ( V_2 , V_119 , F_551 ( 1 ) ) ;
V_835 &= 0xffffff00 ;
F_138 ( V_2 , V_119 , F_551 ( 1 ) , V_835 ) ;
V_835 = F_136 ( V_2 , V_119 , V_836 ) ;
V_835 &= 0x00ffffff ;
V_835 |= 0xb0000000 ;
F_138 ( V_2 , V_119 , V_836 , V_835 ) ;
}
static void F_552 ( struct V_37 * V_38 ,
struct V_819 * V_820 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
F_129 ( F_553 ( V_119 ) , F_554 ( V_820 -> V_821 ) | V_820 -> V_822 ) ;
F_129 ( F_555 ( V_119 ) , V_820 -> V_823 ) ;
F_129 ( F_556 ( V_119 ) , V_820 -> V_824 ) ;
F_129 ( F_557 ( V_119 ) , V_820 -> V_825 ) ;
}
static void F_401 ( struct V_37 * V_38 ,
struct V_819 * V_820 ,
struct V_819 * V_837 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
enum V_118 V_118 = V_38 -> V_115 -> V_121 ;
if ( F_60 ( V_16 ) -> V_127 >= 5 ) {
F_129 ( F_353 ( V_118 ) , F_554 ( V_820 -> V_821 ) | V_820 -> V_822 ) ;
F_129 ( F_558 ( V_118 ) , V_820 -> V_823 ) ;
F_129 ( F_559 ( V_118 ) , V_820 -> V_824 ) ;
F_129 ( F_560 ( V_118 ) , V_820 -> V_825 ) ;
if ( V_837 && ( F_14 ( V_16 ) || F_60 ( V_16 ) -> V_127 < 8 ) &&
V_38 -> V_115 -> V_838 ) {
F_129 ( F_561 ( V_118 ) ,
F_554 ( V_837 -> V_821 ) | V_837 -> V_822 ) ;
F_129 ( F_562 ( V_118 ) , V_837 -> V_823 ) ;
F_129 ( F_563 ( V_118 ) , V_837 -> V_824 ) ;
F_129 ( F_564 ( V_118 ) , V_837 -> V_825 ) ;
}
} else {
F_129 ( F_565 ( V_119 ) , F_554 ( V_820 -> V_821 ) | V_820 -> V_822 ) ;
F_129 ( F_566 ( V_119 ) , V_820 -> V_823 ) ;
F_129 ( F_567 ( V_119 ) , V_820 -> V_824 ) ;
F_129 ( F_568 ( V_119 ) , V_820 -> V_825 ) ;
}
}
void F_399 ( struct V_37 * V_38 , enum V_839 V_820 )
{
struct V_819 * V_840 , * V_841 = NULL ;
if ( V_820 == V_601 ) {
V_840 = & V_38 -> V_115 -> V_840 ;
V_841 = & V_38 -> V_115 -> V_841 ;
} else if ( V_820 == V_842 ) {
V_840 = & V_38 -> V_115 -> V_841 ;
} else {
F_132 ( L_138 ) ;
return;
}
if ( V_38 -> V_115 -> V_261 )
F_552 ( V_38 , & V_38 -> V_115 -> V_840 ) ;
else
F_401 ( V_38 , V_840 , V_841 ) ;
}
static void F_569 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
T_1 V_87 , V_215 ;
V_87 = V_843 | V_224 |
V_222 | V_844 ;
if ( V_38 -> V_119 == V_156 )
V_87 |= V_223 ;
V_87 |= V_130 ;
V_212 -> V_213 . V_87 = V_87 ;
V_215 = ( V_212 -> V_606 - 1 )
<< V_845 ;
V_212 -> V_213 . V_215 = V_215 ;
}
static void F_482 ( struct V_37 * V_38 ,
const struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
T_1 V_846 ;
T_1 V_847 , V_848 , V_849 , V_850 , V_851 ;
T_1 V_852 , V_835 ;
F_2 ( & V_2 -> V_5 ) ;
V_847 = V_212 -> V_87 . V_84 ;
V_848 = V_212 -> V_87 . V_88 ;
V_849 = V_212 -> V_87 . V_80 ;
V_850 = V_212 -> V_87 . V_82 ;
V_851 = V_212 -> V_87 . V_83 ;
if ( V_119 == V_156 )
F_550 ( V_2 , V_119 ) ;
F_138 ( V_2 , V_119 , V_853 , 0x0100000f ) ;
V_835 = F_136 ( V_2 , V_119 , F_570 ( V_119 ) ) ;
V_835 &= 0x00ffffff ;
F_138 ( V_2 , V_119 , F_570 ( V_119 ) , V_835 ) ;
F_138 ( V_2 , V_119 , V_854 , 0x610 ) ;
V_846 = ( ( V_848 << V_855 ) | ( V_849 & V_856 ) ) ;
V_846 |= ( ( V_850 << V_857 ) | ( V_851 << V_858 ) ) ;
V_846 |= ( ( V_847 << V_859 ) ) ;
V_846 |= ( 1 << V_860 ) ;
V_846 |= ( V_861 << V_862 ) ;
F_138 ( V_2 , V_119 , F_571 ( V_119 ) , V_846 ) ;
V_846 |= V_863 ;
F_138 ( V_2 , V_119 , F_571 ( V_119 ) , V_846 ) ;
if ( V_212 -> V_864 == 162000 ||
F_21 ( V_38 , V_64 ) ||
F_21 ( V_38 , V_63 ) )
F_138 ( V_2 , V_119 , F_572 ( V_119 ) ,
0x009f0003 ) ;
else
F_138 ( V_2 , V_119 , F_572 ( V_119 ) ,
0x00d0000f ) ;
if ( V_212 -> V_531 ) {
if ( V_119 == V_147 )
F_138 ( V_2 , V_119 , F_573 ( V_119 ) ,
0x0df40000 ) ;
else
F_138 ( V_2 , V_119 , F_573 ( V_119 ) ,
0x0df70000 ) ;
} else {
if ( V_119 == V_147 )
F_138 ( V_2 , V_119 , F_573 ( V_119 ) ,
0x0df70000 ) ;
else
F_138 ( V_2 , V_119 , F_573 ( V_119 ) ,
0x0df40000 ) ;
}
V_852 = F_136 ( V_2 , V_119 , F_574 ( V_119 ) ) ;
V_852 = ( V_852 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_21 ( V_38 , V_524 ) ||
F_21 ( V_38 , V_525 ) )
V_852 |= 0x01000000 ;
F_138 ( V_2 , V_119 , F_574 ( V_119 ) , V_852 ) ;
F_138 ( V_2 , V_119 , F_575 ( V_119 ) , 0x87871000 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_576 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
V_212 -> V_213 . V_87 = V_225 |
V_224 | V_222 |
V_130 ;
if ( V_38 -> V_119 != V_147 )
V_212 -> V_213 . V_87 |= V_223 ;
V_212 -> V_213 . V_215 =
( V_212 -> V_606 - 1 ) << V_845 ;
}
static void F_481 ( struct V_37 * V_38 ,
const struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
T_5 V_230 = F_64 ( V_38 -> V_119 ) ;
enum V_216 V_217 = F_135 ( V_119 ) ;
T_1 V_865 , V_866 ;
T_1 V_847 , V_848 , V_849 , V_850 , V_851 , V_867 ;
T_1 V_868 ;
int V_85 ;
V_847 = V_212 -> V_87 . V_84 ;
V_867 = V_212 -> V_87 . V_80 & 0x3fffff ;
V_848 = V_212 -> V_87 . V_88 ;
V_849 = V_212 -> V_87 . V_80 >> 22 ;
V_850 = V_212 -> V_87 . V_82 ;
V_851 = V_212 -> V_87 . V_83 ;
V_85 = V_212 -> V_87 . V_85 ;
V_868 = 0 ;
V_865 = 0 ;
F_129 ( V_230 ,
V_212 -> V_213 . V_87 & ~ V_130 ) ;
F_2 ( & V_2 -> V_5 ) ;
F_138 ( V_2 , V_119 , F_577 ( V_217 ) ,
5 << V_869 |
V_850 << V_870 |
V_851 << V_871 |
1 << V_872 ) ;
F_138 ( V_2 , V_119 , F_578 ( V_217 ) , V_849 ) ;
F_138 ( V_2 , V_119 , F_579 ( V_217 ) ,
V_873 |
1 << V_874 ) ;
F_138 ( V_2 , V_119 , F_580 ( V_217 ) , V_867 ) ;
V_868 = F_136 ( V_2 , V_119 , F_581 ( V_217 ) ) ;
V_868 &= ~ ( V_875 | V_876 ) ;
V_868 |= ( 2 << V_877 ) ;
if ( V_867 )
V_868 |= V_876 ;
F_138 ( V_2 , V_119 , F_581 ( V_217 ) , V_868 ) ;
V_868 = F_136 ( V_2 , V_119 , F_582 ( V_217 ) ) ;
V_868 &= ~ ( V_878 |
V_879 ) ;
V_868 |= ( 0x5 << V_880 ) ;
if ( ! V_867 )
V_868 |= V_879 ;
F_138 ( V_2 , V_119 , F_582 ( V_217 ) , V_868 ) ;
if ( V_85 == 5400000 ) {
V_865 |= ( 0x3 << V_881 ) ;
V_865 |= ( 0x8 << V_882 ) ;
V_865 |= ( 0x1 << V_883 ) ;
V_866 = 0x9 ;
} else if ( V_85 <= 6200000 ) {
V_865 |= ( 0x5 << V_881 ) ;
V_865 |= ( 0xB << V_882 ) ;
V_865 |= ( 0x3 << V_883 ) ;
V_866 = 0x9 ;
} else if ( V_85 <= 6480000 ) {
V_865 |= ( 0x4 << V_881 ) ;
V_865 |= ( 0x9 << V_882 ) ;
V_865 |= ( 0x3 << V_883 ) ;
V_866 = 0x8 ;
} else {
V_865 |= ( 0x4 << V_881 ) ;
V_865 |= ( 0x9 << V_882 ) ;
V_865 |= ( 0x3 << V_883 ) ;
V_866 = 0 ;
}
F_138 ( V_2 , V_119 , F_583 ( V_217 ) , V_865 ) ;
V_868 = F_136 ( V_2 , V_119 , F_584 ( V_217 ) ) ;
V_868 &= ~ V_884 ;
V_868 |= ( V_866 << V_885 ) ;
F_138 ( V_2 , V_119 , F_584 ( V_217 ) , V_868 ) ;
F_138 ( V_2 , V_119 , F_137 ( V_217 ) ,
F_136 ( V_2 , V_119 , F_137 ( V_217 ) ) |
V_886 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
int F_585 ( struct V_15 * V_16 , enum V_119 V_119 ,
const struct V_87 * V_87 )
{
struct V_37 * V_38 =
F_50 ( F_503 ( V_16 , V_119 ) ) ;
struct V_43 * V_212 ;
V_212 = F_499 ( sizeof( * V_212 ) , V_743 ) ;
if ( ! V_212 )
return - V_742 ;
V_212 -> V_40 . V_38 = & V_38 -> V_40 ;
V_212 -> V_606 = 1 ;
V_212 -> V_87 = * V_87 ;
if ( F_14 ( V_16 ) ) {
F_576 ( V_38 , V_212 ) ;
F_481 ( V_38 , V_212 ) ;
F_134 ( V_38 , V_212 ) ;
} else {
F_569 ( V_38 , V_212 ) ;
F_482 ( V_38 , V_212 ) ;
F_126 ( V_38 , V_212 ) ;
}
F_221 ( V_212 ) ;
return 0 ;
}
void F_586 ( struct V_15 * V_16 , enum V_119 V_119 )
{
if ( F_14 ( V_16 ) )
F_146 ( F_185 ( V_16 ) , V_119 ) ;
else
F_145 ( F_185 ( V_16 ) , V_119 ) ;
}
static void F_587 ( struct V_37 * V_38 ,
struct V_43 * V_44 ,
T_4 * V_831 ,
int V_51 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_87 ;
bool V_887 ;
struct V_87 * clock = & V_44 -> V_87 ;
F_549 ( V_38 , V_44 , V_831 ) ;
V_887 = F_23 ( V_44 , V_66 ) ||
F_23 ( V_44 , V_63 ) ;
V_87 = V_222 ;
if ( F_23 ( V_44 , V_55 ) )
V_87 |= V_888 ;
else
V_87 |= V_889 ;
if ( F_588 ( V_16 ) || F_589 ( V_16 ) || F_539 ( V_16 ) ) {
V_87 |= ( V_44 -> V_606 - 1 )
<< V_890 ;
}
if ( V_887 )
V_87 |= V_891 ;
if ( V_44 -> V_531 )
V_87 |= V_891 ;
if ( F_32 ( V_16 ) )
V_87 |= ( 1 << ( clock -> V_82 - 1 ) ) << V_892 ;
else {
V_87 |= ( 1 << ( clock -> V_82 - 1 ) ) << V_893 ;
if ( F_31 ( V_16 ) && V_831 )
V_87 |= ( 1 << ( V_831 -> V_82 - 1 ) ) << V_894 ;
}
switch ( clock -> V_83 ) {
case 5 :
V_87 |= V_895 ;
break;
case 7 :
V_87 |= V_896 ;
break;
case 10 :
V_87 |= V_897 ;
break;
case 14 :
V_87 |= V_898 ;
break;
}
if ( F_60 ( V_16 ) -> V_127 >= 4 )
V_87 |= ( 6 << V_899 ) ;
if ( V_44 -> V_900 )
V_87 |= V_901 ;
else if ( F_23 ( V_44 , V_55 ) &&
F_546 ( V_2 ) && V_51 < 2 )
V_87 |= V_902 ;
else
V_87 |= V_903 ;
V_87 |= V_130 ;
V_44 -> V_213 . V_87 = V_87 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
T_1 V_215 = ( V_44 -> V_606 - 1 )
<< V_845 ;
V_44 -> V_213 . V_215 = V_215 ;
}
}
static void F_590 ( struct V_37 * V_38 ,
struct V_43 * V_44 ,
T_4 * V_831 ,
int V_51 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_87 ;
struct V_87 * clock = & V_44 -> V_87 ;
F_549 ( V_38 , V_44 , V_831 ) ;
V_87 = V_222 ;
if ( F_23 ( V_44 , V_55 ) ) {
V_87 |= ( 1 << ( clock -> V_82 - 1 ) ) << V_893 ;
} else {
if ( clock -> V_82 == 2 )
V_87 |= V_904 ;
else
V_87 |= ( clock -> V_82 - 2 ) << V_893 ;
if ( clock -> V_83 == 4 )
V_87 |= V_905 ;
}
if ( ! F_143 ( V_16 ) && F_23 ( V_44 , V_76 ) )
V_87 |= V_221 ;
if ( F_23 ( V_44 , V_55 ) &&
F_546 ( V_2 ) && V_51 < 2 )
V_87 |= V_902 ;
else
V_87 |= V_903 ;
V_87 |= V_130 ;
V_44 -> V_213 . V_87 = V_87 ;
}
static void F_400 ( struct V_37 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 = V_37 -> V_119 ;
enum V_118 V_121 = V_37 -> V_115 -> V_121 ;
const struct V_532 * V_116 = & V_37 -> V_115 -> V_40 . V_116 ;
T_2 V_906 , V_907 ;
int V_908 = 0 ;
V_906 = V_116 -> V_906 ;
V_907 = V_116 -> V_907 ;
if ( V_116 -> V_354 & V_909 ) {
V_906 -= 1 ;
V_907 -= 1 ;
if ( F_21 ( V_37 , V_66 ) )
V_908 = ( V_116 -> V_910 - 1 ) / 2 ;
else
V_908 = V_116 -> V_757 -
V_116 -> V_910 / 2 ;
if ( V_908 < 0 )
V_908 += V_116 -> V_910 ;
}
if ( F_60 ( V_16 ) -> V_127 > 3 )
F_129 ( F_346 ( V_121 ) , V_908 ) ;
F_129 ( F_334 ( V_121 ) ,
( V_116 -> V_561 - 1 ) |
( ( V_116 -> V_910 - 1 ) << 16 ) ) ;
F_129 ( F_336 ( V_121 ) ,
( V_116 -> V_911 - 1 ) |
( ( V_116 -> V_912 - 1 ) << 16 ) ) ;
F_129 ( F_338 ( V_121 ) ,
( V_116 -> V_757 - 1 ) |
( ( V_116 -> V_913 - 1 ) << 16 ) ) ;
F_129 ( F_340 ( V_121 ) ,
( V_116 -> V_562 - 1 ) |
( ( V_906 - 1 ) << 16 ) ) ;
F_129 ( F_342 ( V_121 ) ,
( V_116 -> V_914 - 1 ) |
( ( V_907 - 1 ) << 16 ) ) ;
F_129 ( F_344 ( V_121 ) ,
( V_116 -> V_915 - 1 ) |
( ( V_116 -> V_916 - 1 ) << 16 ) ) ;
if ( F_240 ( V_16 ) && V_121 == V_605 &&
( V_119 == V_156 || V_119 == V_523 ) )
F_129 ( F_340 ( V_119 ) , F_11 ( F_340 ( V_121 ) ) ) ;
F_129 ( F_292 ( V_119 ) ,
( ( V_37 -> V_115 -> V_387 - 1 ) << 16 ) |
( V_37 -> V_115 -> V_386 - 1 ) ) ;
}
static void F_591 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_118 V_121 = V_212 -> V_121 ;
T_2 V_218 ;
V_218 = F_11 ( F_334 ( V_121 ) ) ;
V_212 -> V_40 . V_116 . V_561 = ( V_218 & 0xffff ) + 1 ;
V_212 -> V_40 . V_116 . V_910 = ( ( V_218 >> 16 ) & 0xffff ) + 1 ;
V_218 = F_11 ( F_336 ( V_121 ) ) ;
V_212 -> V_40 . V_116 . V_911 = ( V_218 & 0xffff ) + 1 ;
V_212 -> V_40 . V_116 . V_912 = ( ( V_218 >> 16 ) & 0xffff ) + 1 ;
V_218 = F_11 ( F_338 ( V_121 ) ) ;
V_212 -> V_40 . V_116 . V_757 = ( V_218 & 0xffff ) + 1 ;
V_212 -> V_40 . V_116 . V_913 = ( ( V_218 >> 16 ) & 0xffff ) + 1 ;
V_218 = F_11 ( F_340 ( V_121 ) ) ;
V_212 -> V_40 . V_116 . V_562 = ( V_218 & 0xffff ) + 1 ;
V_212 -> V_40 . V_116 . V_906 = ( ( V_218 >> 16 ) & 0xffff ) + 1 ;
V_218 = F_11 ( F_342 ( V_121 ) ) ;
V_212 -> V_40 . V_116 . V_914 = ( V_218 & 0xffff ) + 1 ;
V_212 -> V_40 . V_116 . V_907 = ( ( V_218 >> 16 ) & 0xffff ) + 1 ;
V_218 = F_11 ( F_344 ( V_121 ) ) ;
V_212 -> V_40 . V_116 . V_915 = ( V_218 & 0xffff ) + 1 ;
V_212 -> V_40 . V_116 . V_916 = ( ( V_218 >> 16 ) & 0xffff ) + 1 ;
if ( F_11 ( F_61 ( V_121 ) ) & V_250 ) {
V_212 -> V_40 . V_116 . V_354 |= V_909 ;
V_212 -> V_40 . V_116 . V_906 += 1 ;
V_212 -> V_40 . V_116 . V_907 += 1 ;
}
V_218 = F_11 ( F_292 ( V_38 -> V_119 ) ) ;
V_212 -> V_386 = ( V_218 & 0xffff ) + 1 ;
V_212 -> V_387 = ( ( V_218 >> 16 ) & 0xffff ) + 1 ;
V_212 -> V_40 . V_446 . V_917 = V_212 -> V_386 ;
V_212 -> V_40 . V_446 . V_918 = V_212 -> V_387 ;
}
void F_592 ( struct V_532 * V_446 ,
struct V_43 * V_212 )
{
V_446 -> V_918 = V_212 -> V_40 . V_116 . V_561 ;
V_446 -> V_919 = V_212 -> V_40 . V_116 . V_910 ;
V_446 -> V_920 = V_212 -> V_40 . V_116 . V_757 ;
V_446 -> V_921 = V_212 -> V_40 . V_116 . V_913 ;
V_446 -> V_917 = V_212 -> V_40 . V_116 . V_562 ;
V_446 -> V_922 = V_212 -> V_40 . V_116 . V_906 ;
V_446 -> V_923 = V_212 -> V_40 . V_116 . V_915 ;
V_446 -> V_924 = V_212 -> V_40 . V_116 . V_916 ;
V_446 -> V_354 = V_212 -> V_40 . V_116 . V_354 ;
V_446 -> type = V_925 ;
V_446 -> clock = V_212 -> V_40 . V_116 . V_117 ;
V_446 -> V_354 |= V_212 -> V_40 . V_116 . V_354 ;
V_446 -> V_926 = F_593 ( V_446 ) ;
V_446 -> V_927 = F_594 ( V_446 ) ;
F_595 ( V_446 ) ;
}
static void F_480 ( struct V_37 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_928 ;
V_928 = 0 ;
if ( ( V_37 -> V_119 == V_147 && V_2 -> V_166 & V_167 ) ||
( V_37 -> V_119 == V_156 && V_2 -> V_166 & V_168 ) )
V_928 |= F_11 ( F_61 ( V_37 -> V_119 ) ) & V_169 ;
if ( V_37 -> V_115 -> V_264 )
V_928 |= V_265 ;
if ( F_31 ( V_16 ) || F_13 ( V_16 ) || F_14 ( V_16 ) ) {
if ( V_37 -> V_115 -> V_929 && V_37 -> V_115 -> V_751 != 30 )
V_928 |= V_930 |
V_931 ;
switch ( V_37 -> V_115 -> V_751 ) {
case 18 :
V_928 |= V_932 ;
break;
case 24 :
V_928 |= V_248 ;
break;
case 30 :
V_928 |= V_933 ;
break;
default:
F_148 () ;
}
}
if ( F_596 ( V_16 ) ) {
if ( V_37 -> V_834 ) {
F_153 ( L_139 ) ;
V_928 |= V_934 ;
} else {
F_153 ( L_140 ) ;
}
}
if ( V_37 -> V_115 -> V_40 . V_116 . V_354 & V_909 ) {
if ( F_60 ( V_16 ) -> V_127 < 4 ||
F_21 ( V_37 , V_66 ) )
V_928 |= V_935 ;
else
V_928 |= V_936 ;
} else
V_928 |= V_937 ;
if ( ( F_13 ( V_16 ) || F_14 ( V_16 ) ) &&
V_37 -> V_115 -> V_938 )
V_928 |= V_939 ;
F_129 ( F_61 ( V_37 -> V_119 ) , V_928 ) ;
F_130 ( F_61 ( V_37 -> V_119 ) ) ;
}
static int F_597 ( struct V_37 * V_38 ,
struct V_43 * V_44 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_53 , V_51 = 0 ;
T_4 clock ;
bool V_940 ;
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
if ( ! V_44 -> V_941 ) {
V_53 = F_53 ( V_44 , V_51 ) ;
V_54 = F_29 ( V_44 , V_53 ) ;
V_940 = V_2 -> V_451 . V_942 ( V_54 , V_44 ,
V_44 -> V_864 ,
V_53 , NULL , & clock ) ;
if ( ! V_940 ) {
F_132 ( L_141 ) ;
return - V_559 ;
}
V_44 -> V_87 . V_84 = clock . V_84 ;
V_44 -> V_87 . V_88 = clock . V_88 ;
V_44 -> V_87 . V_80 = clock . V_80 ;
V_44 -> V_87 . V_82 = clock . V_82 ;
V_44 -> V_87 . V_83 = clock . V_83 ;
}
if ( F_33 ( V_16 ) ) {
F_590 ( V_38 , V_44 , NULL ,
V_51 ) ;
} else if ( F_14 ( V_16 ) ) {
F_576 ( V_38 , V_44 ) ;
} else if ( F_13 ( V_16 ) ) {
F_569 ( V_38 , V_44 ) ;
} else {
F_587 ( V_38 , V_44 , NULL ,
V_51 ) ;
}
return 0 ;
}
static void F_598 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_218 ;
if ( F_60 ( V_16 ) -> V_127 <= 3 && ( F_143 ( V_16 ) || ! F_128 ( V_16 ) ) )
return;
V_218 = F_11 ( V_614 ) ;
if ( ! ( V_218 & V_615 ) )
return;
if ( F_60 ( V_16 ) -> V_127 < 4 ) {
if ( V_38 -> V_119 != V_156 )
return;
} else {
if ( ( V_218 & V_943 ) != ( V_38 -> V_119 << V_944 ) )
return;
}
V_212 -> V_612 . V_613 = V_218 ;
V_212 -> V_612 . V_617 = F_11 ( V_616 ) ;
}
static void F_599 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_212 -> V_121 ;
T_4 clock ;
T_1 V_846 ;
int V_53 = 100000 ;
if ( ! ( V_212 -> V_213 . V_87 & V_130 ) )
return;
F_2 ( & V_2 -> V_5 ) ;
V_846 = F_136 ( V_2 , V_119 , F_571 ( V_119 ) ) ;
F_4 ( & V_2 -> V_5 ) ;
clock . V_88 = ( V_846 >> V_855 ) & 7 ;
clock . V_80 = V_846 & V_856 ;
clock . V_84 = ( V_846 >> V_859 ) & 0xf ;
clock . V_82 = ( V_846 >> V_857 ) & 7 ;
clock . V_83 = ( V_846 >> V_858 ) & 0x1f ;
V_212 -> V_864 = F_37 ( V_53 , & clock ) ;
}
static void
F_600 ( struct V_37 * V_38 ,
struct V_340 * V_341 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 , V_40 , V_317 ;
int V_119 = V_38 -> V_119 , V_170 = V_38 -> V_170 ;
int V_945 , V_274 ;
unsigned int V_946 ;
struct V_278 * V_114 ;
struct V_947 * V_948 ;
V_10 = F_11 ( F_90 ( V_170 ) ) ;
if ( ! ( V_10 & V_171 ) )
return;
V_948 = F_499 ( sizeof( * V_948 ) , V_743 ) ;
if ( ! V_948 ) {
F_153 ( L_142 ) ;
return;
}
V_114 = & V_948 -> V_40 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
if ( V_10 & V_389 ) {
V_341 -> V_350 = V_351 ;
V_114 -> V_294 [ 0 ] = V_270 ;
}
}
V_274 = V_10 & V_949 ;
V_945 = F_206 ( V_274 ) ;
V_114 -> V_274 = V_945 ;
V_114 -> V_815 = F_184 ( V_945 , 0 ) * 8 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
if ( V_341 -> V_350 )
V_317 = F_11 ( F_235 ( V_170 ) ) ;
else
V_317 = F_11 ( F_236 ( V_170 ) ) ;
V_40 = F_11 ( F_234 ( V_170 ) ) & 0xfffff000 ;
} else {
V_40 = F_11 ( F_237 ( V_170 ) ) ;
}
V_341 -> V_40 = V_40 ;
V_10 = F_11 ( F_292 ( V_119 ) ) ;
V_114 -> V_353 = ( ( V_10 >> 16 ) & 0xfff ) + 1 ;
V_114 -> V_273 = ( ( V_10 >> 0 ) & 0xfff ) + 1 ;
V_10 = F_11 ( F_233 ( V_119 ) ) ;
V_114 -> V_291 [ 0 ] = V_10 & 0xffffffc0 ;
V_946 = F_183 ( V_16 , V_114 -> V_273 ,
V_114 -> V_274 ,
V_114 -> V_294 [ 0 ] ) ;
V_341 -> V_297 = V_114 -> V_291 [ 0 ] * V_946 ;
F_153 ( L_143 ,
F_80 ( V_119 ) , V_170 , V_114 -> V_353 , V_114 -> V_273 ,
V_114 -> V_815 , V_40 , V_114 -> V_291 [ 0 ] ,
V_341 -> V_297 ) ;
V_341 -> V_114 = V_948 ;
}
static void F_601 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_212 -> V_121 ;
enum V_216 V_217 = F_135 ( V_119 ) ;
T_4 clock ;
T_1 V_950 , V_951 , V_952 , V_953 , V_954 ;
int V_53 = 100000 ;
F_2 ( & V_2 -> V_5 ) ;
V_950 = F_136 ( V_2 , V_119 , F_577 ( V_217 ) ) ;
V_951 = F_136 ( V_2 , V_119 , F_578 ( V_217 ) ) ;
V_952 = F_136 ( V_2 , V_119 , F_579 ( V_217 ) ) ;
V_953 = F_136 ( V_2 , V_119 , F_580 ( V_217 ) ) ;
V_954 = F_136 ( V_2 , V_119 , F_581 ( V_217 ) ) ;
F_4 ( & V_2 -> V_5 ) ;
clock . V_88 = ( V_952 & 0x7 ) == V_873 ? 2 : 0 ;
clock . V_80 = ( V_951 & 0xff ) << 22 ;
if ( V_954 & V_876 )
clock . V_80 |= V_953 & 0x3fffff ;
clock . V_84 = ( V_952 >> V_874 ) & 0xf ;
clock . V_82 = ( V_950 >> V_870 ) & 0x7 ;
clock . V_83 = ( V_950 >> V_871 ) & 0x1f ;
V_212 -> V_864 = F_38 ( V_53 , & clock ) ;
}
static bool F_602 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_164 V_165 ;
T_2 V_218 ;
bool V_306 ;
V_165 = F_428 ( V_38 -> V_119 ) ;
if ( ! F_87 ( V_2 , V_165 ) )
return false ;
V_212 -> V_121 = (enum V_118 ) V_38 -> V_119 ;
V_212 -> V_134 = V_955 ;
V_306 = false ;
V_218 = F_11 ( F_61 ( V_38 -> V_119 ) ) ;
if ( ! ( V_218 & V_169 ) )
goto V_956;
if ( F_31 ( V_16 ) || F_13 ( V_16 ) || F_14 ( V_16 ) ) {
switch ( V_218 & V_247 ) {
case V_932 :
V_212 -> V_751 = 18 ;
break;
case V_248 :
V_212 -> V_751 = 24 ;
break;
case V_933 :
V_212 -> V_751 = 30 ;
break;
default:
break;
}
}
if ( ( F_13 ( V_16 ) || F_14 ( V_16 ) ) &&
( V_218 & V_939 ) )
V_212 -> V_938 = true ;
if ( F_60 ( V_16 ) -> V_127 < 4 )
V_212 -> V_264 = V_218 & V_265 ;
F_591 ( V_38 , V_212 ) ;
F_598 ( V_38 , V_212 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
V_218 = F_11 ( F_133 ( V_38 -> V_119 ) ) ;
V_212 -> V_606 =
( ( V_218 & V_957 )
>> V_845 ) + 1 ;
V_212 -> V_213 . V_215 = V_218 ;
} else if ( F_588 ( V_16 ) || F_589 ( V_16 ) || F_539 ( V_16 ) ) {
V_218 = F_11 ( F_64 ( V_38 -> V_119 ) ) ;
V_212 -> V_606 =
( ( V_218 & V_958 )
>> V_890 ) + 1 ;
} else {
V_212 -> V_606 = 1 ;
}
V_212 -> V_213 . V_87 = F_11 ( F_64 ( V_38 -> V_119 ) ) ;
if ( ! F_13 ( V_16 ) && ! F_14 ( V_16 ) ) {
if ( F_143 ( V_16 ) )
V_212 -> V_213 . V_87 &= ~ V_221 ;
V_212 -> V_213 . V_735 = F_11 ( F_484 ( V_38 -> V_119 ) ) ;
V_212 -> V_213 . V_736 = F_11 ( F_485 ( V_38 -> V_119 ) ) ;
} else {
V_212 -> V_213 . V_87 &= ~ ( V_214 |
V_234 |
V_232 ) ;
}
if ( F_14 ( V_16 ) )
F_601 ( V_38 , V_212 ) ;
else if ( F_13 ( V_16 ) )
F_599 ( V_38 , V_212 ) ;
else
F_603 ( V_38 , V_212 ) ;
V_212 -> V_40 . V_116 . V_117 =
V_212 -> V_864 / V_212 -> V_606 ;
V_306 = true ;
V_956:
F_88 ( V_2 , V_165 ) ;
return V_306 ;
}
static void F_604 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_41 * V_42 ;
T_1 V_10 , V_959 ;
bool V_960 = false ;
bool V_961 = false ;
bool V_962 = false ;
bool V_963 = false ;
bool V_964 = false ;
F_605 (dev, encoder) {
switch ( V_42 -> type ) {
case V_55 :
V_962 = true ;
V_960 = true ;
break;
case V_525 :
V_962 = true ;
if ( F_350 ( & V_42 -> V_40 ) -> V_217 == V_618 )
V_961 = true ;
break;
default:
break;
}
}
if ( F_106 ( V_16 ) ) {
V_963 = V_2 -> V_827 . V_965 ;
V_964 = V_963 ;
} else {
V_963 = false ;
V_964 = true ;
}
F_153 ( L_144 ,
V_962 , V_960 , V_963 ) ;
V_10 = F_11 ( V_181 ) ;
V_959 = V_10 ;
V_959 &= ~ V_183 ;
if ( V_963 )
V_959 |= V_966 ;
else
V_959 |= V_967 ;
V_959 &= ~ V_182 ;
V_959 &= ~ V_968 ;
V_959 &= ~ V_969 ;
if ( V_962 ) {
V_959 |= V_970 ;
if ( F_546 ( V_2 ) && V_964 )
V_959 |= V_969 ;
if ( V_961 ) {
if ( F_546 ( V_2 ) && V_964 )
V_959 |= V_971 ;
else
V_959 |= V_972 ;
} else
V_959 |= V_973 ;
} else {
V_959 |= V_974 ;
V_959 |= V_973 ;
}
if ( V_959 == V_10 )
return;
V_10 &= ~ V_183 ;
if ( V_963 )
V_10 |= V_966 ;
else
V_10 |= V_967 ;
if ( V_962 ) {
V_10 &= ~ V_182 ;
V_10 |= V_970 ;
if ( F_546 ( V_2 ) && V_964 ) {
F_153 ( L_145 ) ;
V_10 |= V_969 ;
} else
V_10 &= ~ V_969 ;
F_129 ( V_181 , V_10 ) ;
F_130 ( V_181 ) ;
F_131 ( 200 ) ;
V_10 &= ~ V_968 ;
if ( V_961 ) {
if ( F_546 ( V_2 ) && V_964 ) {
F_153 ( L_146 ) ;
V_10 |= V_971 ;
} else
V_10 |= V_972 ;
} else
V_10 |= V_973 ;
F_129 ( V_181 , V_10 ) ;
F_130 ( V_181 ) ;
F_131 ( 200 ) ;
} else {
F_153 ( L_147 ) ;
V_10 &= ~ V_968 ;
V_10 |= V_973 ;
F_129 ( V_181 , V_10 ) ;
F_130 ( V_181 ) ;
F_131 ( 200 ) ;
V_10 &= ~ V_182 ;
V_10 |= V_974 ;
V_10 &= ~ V_969 ;
F_129 ( V_181 , V_10 ) ;
F_130 ( V_181 ) ;
F_131 ( 200 ) ;
}
F_142 ( V_10 != V_959 ) ;
}
static void F_606 ( struct V_1 * V_2 )
{
T_2 V_218 ;
V_218 = F_11 ( V_975 ) ;
V_218 |= V_976 ;
F_129 ( V_975 , V_218 ) ;
if ( F_607 ( F_11 ( V_975 ) &
V_977 , 100 ) )
F_132 ( L_148 ) ;
V_218 = F_11 ( V_975 ) ;
V_218 &= ~ V_976 ;
F_129 ( V_975 , V_218 ) ;
if ( F_607 ( ( F_11 ( V_975 ) &
V_977 ) == 0 , 100 ) )
F_132 ( L_149 ) ;
}
static void F_608 ( struct V_1 * V_2 )
{
T_2 V_218 ;
V_218 = F_325 ( V_2 , 0x8008 , V_978 ) ;
V_218 &= ~ ( 0xFF << 24 ) ;
V_218 |= ( 0x12 << 24 ) ;
F_326 ( V_2 , 0x8008 , V_218 , V_978 ) ;
V_218 = F_325 ( V_2 , 0x2008 , V_978 ) ;
V_218 |= ( 1 << 11 ) ;
F_326 ( V_2 , 0x2008 , V_218 , V_978 ) ;
V_218 = F_325 ( V_2 , 0x2108 , V_978 ) ;
V_218 |= ( 1 << 11 ) ;
F_326 ( V_2 , 0x2108 , V_218 , V_978 ) ;
V_218 = F_325 ( V_2 , 0x206C , V_978 ) ;
V_218 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_326 ( V_2 , 0x206C , V_218 , V_978 ) ;
V_218 = F_325 ( V_2 , 0x216C , V_978 ) ;
V_218 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_326 ( V_2 , 0x216C , V_218 , V_978 ) ;
V_218 = F_325 ( V_2 , 0x2080 , V_978 ) ;
V_218 &= ~ ( 7 << 13 ) ;
V_218 |= ( 5 << 13 ) ;
F_326 ( V_2 , 0x2080 , V_218 , V_978 ) ;
V_218 = F_325 ( V_2 , 0x2180 , V_978 ) ;
V_218 &= ~ ( 7 << 13 ) ;
V_218 |= ( 5 << 13 ) ;
F_326 ( V_2 , 0x2180 , V_218 , V_978 ) ;
V_218 = F_325 ( V_2 , 0x208C , V_978 ) ;
V_218 &= ~ 0xFF ;
V_218 |= 0x1C ;
F_326 ( V_2 , 0x208C , V_218 , V_978 ) ;
V_218 = F_325 ( V_2 , 0x218C , V_978 ) ;
V_218 &= ~ 0xFF ;
V_218 |= 0x1C ;
F_326 ( V_2 , 0x218C , V_218 , V_978 ) ;
V_218 = F_325 ( V_2 , 0x2098 , V_978 ) ;
V_218 &= ~ ( 0xFF << 16 ) ;
V_218 |= ( 0x1C << 16 ) ;
F_326 ( V_2 , 0x2098 , V_218 , V_978 ) ;
V_218 = F_325 ( V_2 , 0x2198 , V_978 ) ;
V_218 &= ~ ( 0xFF << 16 ) ;
V_218 |= ( 0x1C << 16 ) ;
F_326 ( V_2 , 0x2198 , V_218 , V_978 ) ;
V_218 = F_325 ( V_2 , 0x20C4 , V_978 ) ;
V_218 |= ( 1 << 27 ) ;
F_326 ( V_2 , 0x20C4 , V_218 , V_978 ) ;
V_218 = F_325 ( V_2 , 0x21C4 , V_978 ) ;
V_218 |= ( 1 << 27 ) ;
F_326 ( V_2 , 0x21C4 , V_218 , V_978 ) ;
V_218 = F_325 ( V_2 , 0x20EC , V_978 ) ;
V_218 &= ~ ( 0xF << 28 ) ;
V_218 |= ( 4 << 28 ) ;
F_326 ( V_2 , 0x20EC , V_218 , V_978 ) ;
V_218 = F_325 ( V_2 , 0x21EC , V_978 ) ;
V_218 &= ~ ( 0xF << 28 ) ;
V_218 |= ( 4 << 28 ) ;
F_326 ( V_2 , 0x21EC , V_218 , V_978 ) ;
}
static void F_609 ( struct V_15 * V_16 , bool V_979 ,
bool V_980 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_9 , V_218 ;
if ( F_6 ( V_980 && ! V_979 , L_150 ) )
V_979 = true ;
if ( F_6 ( F_610 ( V_16 ) && V_980 , L_151 ) )
V_980 = false ;
F_2 ( & V_2 -> V_5 ) ;
V_218 = F_325 ( V_2 , V_981 , V_504 ) ;
V_218 &= ~ V_505 ;
V_218 |= V_982 ;
F_326 ( V_2 , V_981 , V_218 , V_504 ) ;
F_131 ( 24 ) ;
if ( V_979 ) {
V_218 = F_325 ( V_2 , V_981 , V_504 ) ;
V_218 &= ~ V_982 ;
F_326 ( V_2 , V_981 , V_218 , V_504 ) ;
if ( V_980 ) {
F_606 ( V_2 ) ;
F_608 ( V_2 ) ;
}
}
V_9 = F_610 ( V_16 ) ? V_983 : V_984 ;
V_218 = F_325 ( V_2 , V_9 , V_504 ) ;
V_218 |= V_985 ;
F_326 ( V_2 , V_9 , V_218 , V_504 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_611 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_9 , V_218 ;
F_2 ( & V_2 -> V_5 ) ;
V_9 = F_610 ( V_16 ) ? V_983 : V_984 ;
V_218 = F_325 ( V_2 , V_9 , V_504 ) ;
V_218 &= ~ V_985 ;
F_326 ( V_2 , V_9 , V_218 , V_504 ) ;
V_218 = F_325 ( V_2 , V_981 , V_504 ) ;
if ( ! ( V_218 & V_505 ) ) {
if ( ! ( V_218 & V_982 ) ) {
V_218 |= V_982 ;
F_326 ( V_2 , V_981 , V_218 , V_504 ) ;
F_131 ( 32 ) ;
}
V_218 |= V_505 ;
F_326 ( V_2 , V_981 , V_218 , V_504 ) ;
}
F_4 ( & V_2 -> V_5 ) ;
}
static void F_612 ( struct V_1 * V_2 , int V_986 )
{
T_2 V_218 ;
int V_987 = F_613 ( V_986 ) ;
if ( F_9 ( V_986 % 5 != 0 ) )
return;
if ( F_9 ( V_987 >= F_308 ( V_988 ) ) )
return;
F_2 ( & V_2 -> V_5 ) ;
if ( V_986 % 10 != 0 )
V_218 = 0xAAAAAAAB ;
else
V_218 = 0x00000000 ;
F_326 ( V_2 , V_989 , V_218 , V_504 ) ;
V_218 = F_325 ( V_2 , V_990 , V_504 ) ;
V_218 &= 0xffff0000 ;
V_218 |= V_988 [ V_987 ] ;
F_326 ( V_2 , V_990 , V_218 , V_504 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_614 ( struct V_15 * V_16 )
{
struct V_41 * V_42 ;
bool V_991 = false ;
F_605 (dev, encoder) {
switch ( V_42 -> type ) {
case V_64 :
V_991 = true ;
break;
default:
break;
}
}
if ( V_991 ) {
F_612 ( F_185 ( V_16 ) , 0 ) ;
F_609 ( V_16 , true , true ) ;
} else {
F_611 ( V_16 ) ;
}
}
void F_615 ( struct V_15 * V_16 )
{
if ( F_106 ( V_16 ) || F_107 ( V_16 ) )
F_604 ( V_16 ) ;
else if ( F_169 ( V_16 ) )
F_614 ( V_16 ) ;
}
static int F_616 ( struct V_43 * V_44 )
{
struct V_15 * V_16 = V_44 -> V_40 . V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_45 * V_36 = V_44 -> V_40 . V_36 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_41 * V_42 ;
int V_51 = 0 , V_50 ;
bool V_992 = false ;
F_24 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != V_44 -> V_40 . V_38 )
continue;
V_42 = F_25 ( V_49 -> V_52 ) ;
switch ( V_42 -> type ) {
case V_55 :
V_992 = true ;
break;
default:
break;
}
V_51 ++ ;
}
if ( V_992 && F_546 ( V_2 ) && V_51 < 2 ) {
F_153 ( L_137 ,
V_2 -> V_827 . V_830 ) ;
return V_2 -> V_827 . V_830 ;
}
return 120000 ;
}
static void F_402 ( struct V_111 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_2 V_10 ;
V_10 = 0 ;
switch ( V_37 -> V_115 -> V_751 ) {
case 18 :
V_10 |= V_932 ;
break;
case 24 :
V_10 |= V_248 ;
break;
case 30 :
V_10 |= V_933 ;
break;
case 36 :
V_10 |= V_993 ;
break;
default:
F_148 () ;
}
if ( V_37 -> V_115 -> V_929 )
V_10 |= ( V_930 | V_931 ) ;
if ( V_37 -> V_115 -> V_40 . V_116 . V_354 & V_909 )
V_10 |= V_251 ;
else
V_10 |= V_937 ;
if ( V_37 -> V_115 -> V_938 )
V_10 |= V_939 ;
F_129 ( F_61 ( V_119 ) , V_10 ) ;
F_130 ( F_61 ( V_119 ) ) ;
}
static void F_291 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_9 V_994 = 0x7800 ;
if ( V_37 -> V_115 -> V_938 )
V_994 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_129 ( F_617 ( V_119 ) , V_994 << 16 ) ;
F_129 ( F_618 ( V_119 ) , 0 ) ;
F_129 ( F_619 ( V_119 ) , V_994 ) ;
F_129 ( F_620 ( V_119 ) , 0 ) ;
F_129 ( F_621 ( V_119 ) , 0 ) ;
F_129 ( F_622 ( V_119 ) , V_994 << 16 ) ;
F_129 ( F_623 ( V_119 ) , 0 ) ;
F_129 ( F_624 ( V_119 ) , 0 ) ;
F_129 ( F_625 ( V_119 ) , 0 ) ;
if ( F_60 ( V_16 ) -> V_127 > 6 ) {
T_9 V_995 = 0 ;
if ( V_37 -> V_115 -> V_938 )
V_995 = ( 16 * ( 1 << 12 ) / 255 ) & 0x1fff ;
F_129 ( F_626 ( V_119 ) , V_995 ) ;
F_129 ( F_627 ( V_119 ) , V_995 ) ;
F_129 ( F_628 ( V_119 ) , V_995 ) ;
F_129 ( F_629 ( V_119 ) , 0 ) ;
} else {
T_2 V_446 = V_996 ;
if ( V_37 -> V_115 -> V_938 )
V_446 |= V_997 ;
F_129 ( F_629 ( V_119 ) , V_446 ) ;
}
}
static void F_408 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_119 V_119 = V_37 -> V_119 ;
enum V_118 V_121 = V_37 -> V_115 -> V_121 ;
T_2 V_10 ;
V_10 = 0 ;
if ( F_240 ( V_16 ) && V_37 -> V_115 -> V_929 )
V_10 |= ( V_930 | V_931 ) ;
if ( V_37 -> V_115 -> V_40 . V_116 . V_354 & V_909 )
V_10 |= V_251 ;
else
V_10 |= V_937 ;
F_129 ( F_61 ( V_121 ) , V_10 ) ;
F_130 ( F_61 ( V_121 ) ) ;
F_129 ( F_378 ( V_37 -> V_119 ) , V_998 ) ;
F_130 ( F_378 ( V_37 -> V_119 ) ) ;
if ( F_241 ( V_16 ) || F_60 ( V_16 ) -> V_127 >= 9 ) {
V_10 = 0 ;
switch ( V_37 -> V_115 -> V_751 ) {
case 18 :
V_10 |= V_999 ;
break;
case 24 :
V_10 |= V_1000 ;
break;
case 30 :
V_10 |= V_1001 ;
break;
case 36 :
V_10 |= V_1002 ;
break;
default:
F_148 () ;
}
if ( V_37 -> V_115 -> V_929 )
V_10 |= V_1003 | V_1004 ;
F_129 ( F_630 ( V_119 ) , V_10 ) ;
}
}
static bool F_631 ( struct V_111 * V_38 ,
struct V_43 * V_44 ,
T_4 * clock ,
bool * V_1005 ,
T_4 * V_831 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_53 ;
const T_3 * V_54 ;
bool V_306 ;
V_53 = F_616 ( V_44 ) ;
V_54 = F_29 ( V_44 , V_53 ) ;
V_306 = V_2 -> V_451 . V_942 ( V_54 , V_44 ,
V_44 -> V_864 ,
V_53 , NULL , clock ) ;
if ( ! V_306 )
return false ;
return true ;
}
int F_510 ( int V_110 , int V_748 , int V_1006 )
{
T_1 V_1007 = V_110 * V_1006 * 21 / 20 ;
return F_189 ( V_1007 , V_748 * 8 ) ;
}
static bool F_632 ( struct V_87 * V_87 , int V_1008 )
{
return F_35 ( V_87 ) < V_1008 * V_87 -> V_84 ;
}
static T_2 F_633 ( struct V_37 * V_37 ,
struct V_43 * V_44 ,
T_1 * V_832 ,
T_4 * V_831 , T_1 * V_833 )
{
struct V_111 * V_38 = & V_37 -> V_40 ;
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_45 * V_36 = V_44 -> V_40 . V_36 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_41 * V_42 ;
T_2 V_87 ;
int V_1008 , V_51 = 0 , V_50 ;
bool V_992 = false , V_887 = false ;
F_24 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != V_44 -> V_40 . V_38 )
continue;
V_42 = F_25 ( V_49 -> V_52 ) ;
switch ( V_42 -> type ) {
case V_55 :
V_992 = true ;
break;
case V_66 :
case V_63 :
V_887 = true ;
break;
default:
break;
}
V_51 ++ ;
}
V_1008 = 21 ;
if ( V_992 ) {
if ( ( F_546 ( V_2 ) &&
V_2 -> V_827 . V_830 == 100000 ) ||
( F_106 ( V_16 ) && F_27 ( V_16 ) ) )
V_1008 = 25 ;
} else if ( V_44 -> V_900 )
V_1008 = 20 ;
if ( F_632 ( & V_44 -> V_87 , V_1008 ) )
* V_832 |= V_1009 ;
if ( V_833 && ( V_831 -> V_79 < V_1008 * V_831 -> V_84 ) )
* V_833 |= V_1009 ;
V_87 = 0 ;
if ( V_992 )
V_87 |= V_888 ;
else
V_87 |= V_889 ;
V_87 |= ( V_44 -> V_606 - 1 )
<< V_1010 ;
if ( V_887 )
V_87 |= V_891 ;
if ( V_44 -> V_531 )
V_87 |= V_891 ;
V_87 |= ( 1 << ( V_44 -> V_87 . V_82 - 1 ) ) << V_893 ;
V_87 |= ( 1 << ( V_44 -> V_87 . V_82 - 1 ) ) << V_894 ;
switch ( V_44 -> V_87 . V_83 ) {
case 5 :
V_87 |= V_895 ;
break;
case 7 :
V_87 |= V_896 ;
break;
case 10 :
V_87 |= V_897 ;
break;
case 14 :
V_87 |= V_898 ;
break;
}
if ( V_992 && F_546 ( V_2 ) && V_51 < 2 )
V_87 |= V_902 ;
else
V_87 |= V_903 ;
return V_87 | V_130 ;
}
static int F_634 ( struct V_37 * V_38 ,
struct V_43 * V_44 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
T_4 clock , V_831 ;
T_1 V_87 = 0 , V_832 = 0 , V_833 = 0 ;
bool V_940 , V_1005 = false ;
bool V_992 = false ;
struct V_133 * V_136 ;
memset ( & V_44 -> V_213 , 0 ,
sizeof( V_44 -> V_213 ) ) ;
V_992 = F_23 ( V_44 , V_55 ) ;
F_6 ( ! ( F_106 ( V_16 ) || F_107 ( V_16 ) ) ,
L_152 , F_635 ( V_16 ) ) ;
V_940 = F_631 ( & V_38 -> V_40 , V_44 , & clock ,
& V_1005 , & V_831 ) ;
if ( ! V_940 && ! V_44 -> V_941 ) {
F_132 ( L_141 ) ;
return - V_559 ;
}
if ( ! V_44 -> V_941 ) {
V_44 -> V_87 . V_84 = clock . V_84 ;
V_44 -> V_87 . V_88 = clock . V_88 ;
V_44 -> V_87 . V_80 = clock . V_80 ;
V_44 -> V_87 . V_82 = clock . V_82 ;
V_44 -> V_87 . V_83 = clock . V_83 ;
}
if ( V_44 -> V_261 ) {
V_832 = F_548 ( & V_44 -> V_87 ) ;
if ( V_1005 )
V_833 = F_548 ( & V_831 ) ;
V_87 = F_633 ( V_38 , V_44 ,
& V_832 , & V_831 ,
V_1005 ? & V_833 : NULL ) ;
V_44 -> V_213 . V_87 = V_87 ;
V_44 -> V_213 . V_735 = V_832 ;
if ( V_1005 )
V_44 -> V_213 . V_736 = V_833 ;
else
V_44 -> V_213 . V_736 = V_832 ;
V_136 = F_358 ( V_38 , V_44 ) ;
if ( V_136 == NULL ) {
F_16 ( L_153 ,
F_80 ( V_38 -> V_119 ) ) ;
return - V_559 ;
}
}
if ( V_992 && V_1005 )
V_38 -> V_834 = true ;
else
V_38 -> V_834 = false ;
return 0 ;
}
static void F_636 ( struct V_37 * V_38 ,
struct V_819 * V_820 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 = V_38 -> V_119 ;
V_820 -> V_824 = F_11 ( F_556 ( V_119 ) ) ;
V_820 -> V_825 = F_11 ( F_557 ( V_119 ) ) ;
V_820 -> V_822 = F_11 ( F_553 ( V_119 ) )
& ~ V_526 ;
V_820 -> V_823 = F_11 ( F_555 ( V_119 ) ) ;
V_820 -> V_821 = ( ( F_11 ( F_553 ( V_119 ) )
& V_526 ) >> V_1011 ) + 1 ;
}
static void F_637 ( struct V_37 * V_38 ,
enum V_118 V_118 ,
struct V_819 * V_820 ,
struct V_819 * V_837 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 = V_38 -> V_119 ;
if ( F_60 ( V_16 ) -> V_127 >= 5 ) {
V_820 -> V_824 = F_11 ( F_559 ( V_118 ) ) ;
V_820 -> V_825 = F_11 ( F_560 ( V_118 ) ) ;
V_820 -> V_822 = F_11 ( F_353 ( V_118 ) )
& ~ V_526 ;
V_820 -> V_823 = F_11 ( F_558 ( V_118 ) ) ;
V_820 -> V_821 = ( ( F_11 ( F_353 ( V_118 ) )
& V_526 ) >> V_1011 ) + 1 ;
if ( V_837 && F_60 ( V_16 ) -> V_127 < 8 &&
V_38 -> V_115 -> V_838 ) {
V_837 -> V_824 = F_11 ( F_563 ( V_118 ) ) ;
V_837 -> V_825 = F_11 ( F_564 ( V_118 ) ) ;
V_837 -> V_822 = F_11 ( F_561 ( V_118 ) )
& ~ V_526 ;
V_837 -> V_823 = F_11 ( F_562 ( V_118 ) ) ;
V_837 -> V_821 = ( ( F_11 ( F_561 ( V_118 ) )
& V_526 ) >> V_1011 ) + 1 ;
}
} else {
V_820 -> V_824 = F_11 ( F_567 ( V_119 ) ) ;
V_820 -> V_825 = F_11 ( F_568 ( V_119 ) ) ;
V_820 -> V_822 = F_11 ( F_565 ( V_119 ) )
& ~ V_526 ;
V_820 -> V_823 = F_11 ( F_566 ( V_119 ) ) ;
V_820 -> V_821 = ( ( F_11 ( F_565 ( V_119 ) )
& V_526 ) >> V_1011 ) + 1 ;
}
}
void F_638 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
if ( V_212 -> V_261 )
F_636 ( V_38 , & V_212 -> V_840 ) ;
else
F_637 ( V_38 , V_212 -> V_121 ,
& V_212 -> V_840 ,
& V_212 -> V_841 ) ;
}
static void F_639 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
F_637 ( V_38 , V_212 -> V_121 ,
& V_212 -> V_602 , NULL ) ;
}
static void F_640 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_403 * V_404 = & V_212 -> V_404 ;
T_2 V_444 = 0 ;
int V_241 = - 1 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_38 -> V_405 ; V_50 ++ ) {
V_444 = F_11 ( F_249 ( V_38 -> V_119 , V_50 ) ) ;
if ( V_444 & V_445 && ! ( V_444 & V_1012 ) ) {
V_241 = V_50 ;
V_212 -> V_459 . V_180 = true ;
V_212 -> V_459 . V_566 = F_11 ( F_250 ( V_38 -> V_119 , V_50 ) ) ;
V_212 -> V_459 . V_297 = F_11 ( F_251 ( V_38 -> V_119 , V_50 ) ) ;
break;
}
}
V_404 -> V_436 = V_241 ;
if ( V_241 >= 0 ) {
V_404 -> V_550 |= ( 1 << V_560 ) ;
} else {
V_404 -> V_550 &= ~ ( 1 << V_560 ) ;
}
}
static void
F_641 ( struct V_37 * V_38 ,
struct V_340 * V_341 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 , V_40 , V_317 , V_1013 , V_350 ;
int V_119 = V_38 -> V_119 ;
int V_945 , V_274 ;
unsigned int V_946 ;
struct V_278 * V_114 ;
struct V_947 * V_948 ;
V_948 = F_499 ( sizeof( * V_948 ) , V_743 ) ;
if ( ! V_948 ) {
F_153 ( L_142 ) ;
return;
}
V_114 = & V_948 -> V_40 ;
V_10 = F_11 ( F_96 ( V_119 , 0 ) ) ;
if ( ! ( V_10 & V_176 ) )
goto error;
V_274 = V_10 & V_1014 ;
V_945 = F_207 ( V_274 ,
V_10 & V_409 ,
V_10 & V_1015 ) ;
V_114 -> V_274 = V_945 ;
V_114 -> V_815 = F_184 ( V_945 , 0 ) * 8 ;
V_350 = V_10 & V_1016 ;
switch ( V_350 ) {
case V_1017 :
V_114 -> V_294 [ 0 ] = V_269 ;
break;
case V_420 :
V_341 -> V_350 = V_351 ;
V_114 -> V_294 [ 0 ] = V_270 ;
break;
case V_421 :
V_114 -> V_294 [ 0 ] = V_271 ;
break;
case V_422 :
V_114 -> V_294 [ 0 ] = V_272 ;
break;
default:
F_181 ( V_350 ) ;
goto error;
}
V_40 = F_11 ( F_265 ( V_119 , 0 ) ) & 0xfffff000 ;
V_341 -> V_40 = V_40 ;
V_317 = F_11 ( F_259 ( V_119 , 0 ) ) ;
V_10 = F_11 ( F_260 ( V_119 , 0 ) ) ;
V_114 -> V_273 = ( ( V_10 >> 16 ) & 0xfff ) + 1 ;
V_114 -> V_353 = ( ( V_10 >> 0 ) & 0x1fff ) + 1 ;
V_10 = F_11 ( F_261 ( V_119 , 0 ) ) ;
V_1013 = F_243 ( V_2 , V_114 -> V_294 [ 0 ] ,
V_114 -> V_274 ) ;
V_114 -> V_291 [ 0 ] = ( V_10 & 0x3ff ) * V_1013 ;
V_946 = F_183 ( V_16 , V_114 -> V_273 ,
V_114 -> V_274 ,
V_114 -> V_294 [ 0 ] ) ;
V_341 -> V_297 = V_114 -> V_291 [ 0 ] * V_946 ;
F_153 ( L_154 ,
F_80 ( V_119 ) , V_114 -> V_353 , V_114 -> V_273 ,
V_114 -> V_815 , V_40 , V_114 -> V_291 [ 0 ] ,
V_341 -> V_297 ) ;
V_341 -> V_114 = V_948 ;
return;
error:
F_221 ( V_114 ) ;
}
static void F_642 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_218 ;
V_218 = F_11 ( F_368 ( V_38 -> V_119 ) ) ;
if ( V_218 & V_567 ) {
V_212 -> V_459 . V_180 = true ;
V_212 -> V_459 . V_566 = F_11 ( F_370 ( V_38 -> V_119 ) ) ;
V_212 -> V_459 . V_297 = F_11 ( F_371 ( V_38 -> V_119 ) ) ;
if ( F_643 ( V_16 ) ) {
F_9 ( ( V_218 & V_1018 ) !=
F_369 ( V_38 -> V_119 ) ) ;
}
}
}
static void
F_644 ( struct V_37 * V_38 ,
struct V_340 * V_341 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 , V_40 , V_317 ;
int V_119 = V_38 -> V_119 ;
int V_945 , V_274 ;
unsigned int V_946 ;
struct V_278 * V_114 ;
struct V_947 * V_948 ;
V_10 = F_11 ( F_90 ( V_119 ) ) ;
if ( ! ( V_10 & V_171 ) )
return;
V_948 = F_499 ( sizeof( * V_948 ) , V_743 ) ;
if ( ! V_948 ) {
F_153 ( L_142 ) ;
return;
}
V_114 = & V_948 -> V_40 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
if ( V_10 & V_389 ) {
V_341 -> V_350 = V_351 ;
V_114 -> V_294 [ 0 ] = V_270 ;
}
}
V_274 = V_10 & V_949 ;
V_945 = F_206 ( V_274 ) ;
V_114 -> V_274 = V_945 ;
V_114 -> V_815 = F_184 ( V_945 , 0 ) * 8 ;
V_40 = F_11 ( F_234 ( V_119 ) ) & 0xfffff000 ;
if ( F_240 ( V_16 ) || F_241 ( V_16 ) ) {
V_317 = F_11 ( F_242 ( V_119 ) ) ;
} else {
if ( V_341 -> V_350 )
V_317 = F_11 ( F_235 ( V_119 ) ) ;
else
V_317 = F_11 ( F_236 ( V_119 ) ) ;
}
V_341 -> V_40 = V_40 ;
V_10 = F_11 ( F_292 ( V_119 ) ) ;
V_114 -> V_353 = ( ( V_10 >> 16 ) & 0xfff ) + 1 ;
V_114 -> V_273 = ( ( V_10 >> 0 ) & 0xfff ) + 1 ;
V_10 = F_11 ( F_233 ( V_119 ) ) ;
V_114 -> V_291 [ 0 ] = V_10 & 0xffffffc0 ;
V_946 = F_183 ( V_16 , V_114 -> V_273 ,
V_114 -> V_274 ,
V_114 -> V_294 [ 0 ] ) ;
V_341 -> V_297 = V_114 -> V_291 [ 0 ] * V_946 ;
F_153 ( L_154 ,
F_80 ( V_119 ) , V_114 -> V_353 , V_114 -> V_273 ,
V_114 -> V_815 , V_40 , V_114 -> V_291 [ 0 ] ,
V_341 -> V_297 ) ;
V_341 -> V_114 = V_948 ;
}
static bool F_645 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_164 V_165 ;
T_2 V_218 ;
bool V_306 ;
V_165 = F_428 ( V_38 -> V_119 ) ;
if ( ! F_87 ( V_2 , V_165 ) )
return false ;
V_212 -> V_121 = (enum V_118 ) V_38 -> V_119 ;
V_212 -> V_134 = V_955 ;
V_306 = false ;
V_218 = F_11 ( F_61 ( V_38 -> V_119 ) ) ;
if ( ! ( V_218 & V_169 ) )
goto V_956;
switch ( V_218 & V_247 ) {
case V_932 :
V_212 -> V_751 = 18 ;
break;
case V_248 :
V_212 -> V_751 = 24 ;
break;
case V_933 :
V_212 -> V_751 = 30 ;
break;
case V_993 :
V_212 -> V_751 = 36 ;
break;
default:
break;
}
if ( V_218 & V_939 )
V_212 -> V_938 = true ;
if ( F_11 ( F_109 ( V_38 -> V_119 ) ) & V_185 ) {
struct V_133 * V_136 ;
V_212 -> V_261 = true ;
V_218 = F_11 ( F_75 ( V_38 -> V_119 ) ) ;
V_212 -> V_473 = ( ( V_472 & V_218 ) >>
V_1019 ) + 1 ;
F_639 ( V_38 , V_212 ) ;
if ( F_106 ( V_2 -> V_16 ) ) {
V_212 -> V_134 =
(enum V_542 ) V_38 -> V_119 ;
} else {
V_218 = F_11 ( V_529 ) ;
if ( V_218 & F_356 ( V_38 -> V_119 ) )
V_212 -> V_134 = V_530 ;
else
V_212 -> V_134 = V_1020 ;
}
V_136 = & V_2 -> V_135 [ V_212 -> V_134 ] ;
F_9 ( ! V_136 -> V_139 ( V_2 , V_136 ,
& V_212 -> V_213 ) ) ;
V_218 = V_212 -> V_213 . V_87 ;
V_212 -> V_606 =
( ( V_218 & V_1021 )
>> V_1010 ) + 1 ;
F_646 ( V_38 , V_212 ) ;
} else {
V_212 -> V_606 = 1 ;
}
F_591 ( V_38 , V_212 ) ;
F_642 ( V_38 , V_212 ) ;
V_306 = true ;
V_956:
F_88 ( V_2 , V_165 ) ;
return V_306 ;
}
static void F_647 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_37 * V_38 ;
F_140 (dev, crtc)
F_65 ( V_38 -> V_112 , L_155 ,
F_80 ( V_38 -> V_119 ) ) ;
F_65 ( F_11 ( V_1022 ) , L_156 ) ;
F_65 ( F_11 ( V_1023 ) & V_1024 , L_157 ) ;
F_65 ( F_11 ( F_648 ( 0 ) ) & V_1025 , L_158 ) ;
F_65 ( F_11 ( F_648 ( 1 ) ) & V_1025 , L_159 ) ;
F_65 ( F_11 ( V_1026 ) & V_1027 , L_160 ) ;
F_65 ( F_11 ( V_1028 ) & V_1029 ,
L_161 ) ;
if ( F_240 ( V_16 ) )
F_65 ( F_11 ( V_1030 ) & V_1029 ,
L_162 ) ;
F_65 ( F_11 ( V_1031 ) & V_1032 ,
L_163 ) ;
F_65 ( F_11 ( V_1033 ) & V_1034 ,
L_164 ) ;
F_65 ( F_11 ( V_1035 ) & V_1036 , L_165 ) ;
F_65 ( F_649 ( V_2 ) , L_166 ) ;
}
static T_2 F_650 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_240 ( V_16 ) )
return F_11 ( V_1037 ) ;
else
return F_11 ( V_1038 ) ;
}
static void F_651 ( struct V_1 * V_2 , T_2 V_10 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_240 ( V_16 ) ) {
F_2 ( & V_2 -> V_570 . V_571 ) ;
if ( F_374 ( V_2 , V_1039 ,
V_10 ) )
F_132 ( L_167 ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
} else {
F_129 ( V_1038 , V_10 ) ;
F_130 ( V_1038 ) ;
}
}
static void F_652 ( struct V_1 * V_2 ,
bool V_1040 , bool V_1041 )
{
T_2 V_10 ;
F_647 ( V_2 ) ;
V_10 = F_11 ( V_763 ) ;
if ( V_1040 ) {
V_10 |= V_765 ;
F_129 ( V_763 , V_10 ) ;
if ( F_607 ( F_11 ( V_763 ) &
V_1042 , 1 ) )
F_132 ( L_168 ) ;
V_10 = F_11 ( V_763 ) ;
}
V_10 |= V_1043 ;
F_129 ( V_763 , V_10 ) ;
F_130 ( V_763 ) ;
if ( F_62 ( ( F_11 ( V_763 ) & V_691 ) == 0 , 1 ) )
F_132 ( L_169 ) ;
V_10 = F_650 ( V_2 ) ;
V_10 |= V_1044 ;
F_651 ( V_2 , V_10 ) ;
F_653 ( 100 ) ;
if ( F_62 ( ( F_650 ( V_2 ) & V_1045 ) == 0 ,
1 ) )
F_132 ( L_170 ) ;
if ( V_1041 ) {
V_10 = F_11 ( V_763 ) ;
V_10 |= V_1046 ;
F_129 ( V_763 , V_10 ) ;
F_130 ( V_763 ) ;
}
}
static void F_654 ( struct V_1 * V_2 )
{
T_2 V_10 ;
V_10 = F_11 ( V_763 ) ;
if ( ( V_10 & ( V_691 | V_1043 | V_765 |
V_1046 ) ) == V_691 )
return;
F_655 ( V_2 , V_1047 ) ;
if ( V_10 & V_1046 ) {
V_10 &= ~ V_1046 ;
F_129 ( V_763 , V_10 ) ;
F_130 ( V_763 ) ;
}
V_10 = F_650 ( V_2 ) ;
V_10 |= V_1048 ;
V_10 &= ~ V_1044 ;
F_651 ( V_2 , V_10 ) ;
V_10 = F_11 ( V_763 ) ;
V_10 &= ~ V_1043 ;
F_129 ( V_763 , V_10 ) ;
if ( F_62 ( F_11 ( V_763 ) & V_691 , 5 ) )
F_132 ( L_171 ) ;
if ( V_10 & V_765 ) {
V_10 = F_11 ( V_763 ) ;
V_10 &= ~ V_765 ;
F_129 ( V_763 , V_10 ) ;
if ( F_607 ( ( F_11 ( V_763 ) &
V_1042 ) == 0 , 1 ) )
F_132 ( L_172 ) ;
}
F_656 ( V_2 , V_1047 ) ;
F_440 ( V_2 -> V_16 ) ;
}
void F_657 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_10 ;
F_153 ( L_173 ) ;
if ( F_610 ( V_16 ) ) {
V_10 = F_11 ( V_1049 ) ;
V_10 &= ~ V_1050 ;
F_129 ( V_1049 , V_10 ) ;
}
F_611 ( V_16 ) ;
F_652 ( V_2 , true , true ) ;
}
void F_658 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_10 ;
F_153 ( L_174 ) ;
F_654 ( V_2 ) ;
F_614 ( V_16 ) ;
if ( F_610 ( V_16 ) ) {
V_10 = F_11 ( V_1049 ) ;
V_10 |= V_1050 ;
F_129 ( V_1049 , V_10 ) ;
}
}
static void F_659 ( struct V_45 * V_595 )
{
struct V_15 * V_16 = V_595 -> V_16 ;
struct V_719 * V_730 =
F_362 ( V_595 ) ;
unsigned int V_731 = V_730 -> V_722 ;
F_441 ( V_16 , V_731 ) ;
}
static int F_660 ( struct V_45 * V_36 )
{
struct V_719 * V_360 = F_362 ( V_36 ) ;
struct V_1 * V_2 = V_36 -> V_16 -> V_17 ;
struct V_111 * V_38 ;
struct V_35 * V_1051 ;
struct V_43 * V_44 ;
unsigned V_1052 = 0 , V_50 ;
enum V_119 V_119 ;
memcpy ( V_360 -> V_720 , V_2 -> V_720 ,
sizeof( V_360 -> V_720 ) ) ;
F_471 (state, crtc, cstate, i) {
int V_1053 ;
V_44 = F_273 ( V_1051 ) ;
if ( ! V_44 -> V_40 . V_243 ) {
V_360 -> V_720 [ V_50 ] = 0 ;
continue;
}
V_1053 = F_513 ( V_44 ) ;
if ( F_241 ( V_2 ) && V_44 -> V_569 )
V_1053 = F_189 ( V_1053 * 100 , 95 ) ;
V_360 -> V_720 [ V_50 ] = V_1053 ;
}
F_93 (dev_priv, pipe)
V_1052 = V_91 ( V_360 -> V_720 [ V_119 ] , V_1052 ) ;
return V_1052 ;
}
static void F_661 ( struct V_15 * V_16 , int V_704 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_10 , V_1054 ;
int V_306 ;
if ( F_6 ( ( F_11 ( V_763 ) &
( V_1043 | V_691 |
V_1055 | V_1056 |
V_1057 | V_1046 |
V_765 ) ) != V_691 ,
L_175 ) )
return;
F_2 ( & V_2 -> V_570 . V_571 ) ;
V_306 = F_374 ( V_2 ,
V_1058 , 0x0 ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
if ( V_306 ) {
F_132 ( L_176 ) ;
return;
}
V_10 = F_11 ( V_763 ) ;
V_10 |= V_765 ;
F_129 ( V_763 , V_10 ) ;
if ( F_607 ( F_11 ( V_763 ) &
V_1042 , 1 ) )
F_132 ( L_168 ) ;
V_10 = F_11 ( V_763 ) ;
V_10 &= ~ V_764 ;
switch ( V_704 ) {
case 450000 :
V_10 |= V_766 ;
V_1054 = 0 ;
break;
case 540000 :
V_10 |= V_767 ;
V_1054 = 1 ;
break;
case 337500 :
V_10 |= V_768 ;
V_1054 = 2 ;
break;
case 675000 :
V_10 |= V_1059 ;
V_1054 = 3 ;
break;
default:
F_6 ( 1 , L_177 ) ;
return;
}
F_129 ( V_763 , V_10 ) ;
V_10 = F_11 ( V_763 ) ;
V_10 &= ~ V_765 ;
F_129 ( V_763 , V_10 ) ;
if ( F_607 ( ( F_11 ( V_763 ) &
V_1042 ) == 0 , 1 ) )
F_132 ( L_172 ) ;
F_2 ( & V_2 -> V_570 . V_571 ) ;
F_374 ( V_2 , V_662 , V_1054 ) ;
F_4 ( & V_2 -> V_570 . V_571 ) ;
F_129 ( V_1060 , F_7 ( V_704 , 1000 ) - 1 ) ;
F_440 ( V_16 ) ;
F_6 ( V_704 != V_2 -> V_651 ,
L_178 ,
V_704 , V_2 -> V_651 ) ;
}
static int F_662 ( struct V_45 * V_36 )
{
struct V_1 * V_2 = F_185 ( V_36 -> V_16 ) ;
struct V_719 * V_360 = F_362 ( V_36 ) ;
int V_717 = F_660 ( V_36 ) ;
int V_704 ;
if ( V_717 > 540000 )
V_704 = 675000 ;
else if ( V_717 > 450000 )
V_704 = 540000 ;
else if ( V_717 > 337500 )
V_704 = 450000 ;
else
V_704 = 337500 ;
if ( V_704 > V_2 -> V_643 ) {
F_153 ( L_179 ,
V_704 , V_2 -> V_643 ) ;
return - V_559 ;
}
V_360 -> V_704 = V_360 -> V_722 = V_704 ;
if ( ! V_360 -> V_723 )
V_360 -> V_722 = 337500 ;
return 0 ;
}
static void F_663 ( struct V_45 * V_595 )
{
struct V_15 * V_16 = V_595 -> V_16 ;
struct V_719 * V_730 =
F_362 ( V_595 ) ;
unsigned V_731 = V_730 -> V_722 ;
F_661 ( V_16 , V_731 ) ;
}
static int F_664 ( struct V_37 * V_38 ,
struct V_43 * V_44 )
{
struct V_41 * V_41 =
F_360 ( V_44 ) ;
if ( V_41 -> type != V_633 ) {
if ( ! F_665 ( V_38 , V_44 ) )
return - V_559 ;
}
V_38 -> V_834 = false ;
return 0 ;
}
static void F_666 ( struct V_1 * V_2 ,
enum V_217 V_217 ,
struct V_43 * V_212 )
{
switch ( V_217 ) {
case V_618 :
V_212 -> V_1061 = V_686 ;
V_212 -> V_134 = V_1062 ;
break;
case V_231 :
V_212 -> V_1061 = V_1063 ;
V_212 -> V_134 = V_1064 ;
break;
case V_233 :
V_212 -> V_1061 = V_1065 ;
V_212 -> V_134 = V_1066 ;
break;
default:
F_132 ( L_180 ) ;
}
}
static void F_667 ( struct V_1 * V_2 ,
enum V_217 V_217 ,
struct V_43 * V_212 )
{
T_1 V_460 , V_1067 ;
V_460 = F_11 ( V_1068 ) & F_668 ( V_217 ) ;
V_212 -> V_1061 = V_460 >> ( V_217 * 3 + 1 ) ;
switch ( V_212 -> V_1061 ) {
case V_686 :
V_1067 = F_11 ( V_685 ) ;
V_212 -> V_213 . V_1069 = V_1067 & 0x3f ;
break;
case V_1063 :
V_212 -> V_134 = V_1062 ;
break;
case V_1065 :
V_212 -> V_134 = V_1064 ;
break;
case V_1070 :
V_212 -> V_134 = V_1066 ;
break;
}
}
static void F_669 ( struct V_1 * V_2 ,
enum V_217 V_217 ,
struct V_43 * V_212 )
{
V_212 -> V_1061 = F_11 ( F_670 ( V_217 ) ) ;
switch ( V_212 -> V_1061 ) {
case V_1071 :
V_212 -> V_134 = V_1072 ;
break;
case V_1073 :
V_212 -> V_134 = V_1074 ;
break;
case V_1075 :
V_212 -> V_134 = V_1076 ;
break;
}
}
static void F_671 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_133 * V_136 ;
enum V_217 V_217 ;
T_2 V_218 ;
V_218 = F_11 ( F_72 ( V_212 -> V_121 ) ) ;
V_217 = ( V_218 & V_1077 ) >> V_1078 ;
if ( F_436 ( V_16 ) || F_437 ( V_16 ) )
F_667 ( V_2 , V_217 , V_212 ) ;
else if ( F_30 ( V_16 ) )
F_666 ( V_2 , V_217 , V_212 ) ;
else
F_669 ( V_2 , V_217 , V_212 ) ;
if ( V_212 -> V_134 >= 0 ) {
V_136 = & V_2 -> V_135 [ V_212 -> V_134 ] ;
F_9 ( ! V_136 -> V_139 ( V_2 , V_136 ,
& V_212 -> V_213 ) ) ;
}
if ( F_60 ( V_16 ) -> V_127 < 9 &&
( V_217 == V_623 ) && F_11 ( V_258 ) & V_185 ) {
V_212 -> V_261 = true ;
V_218 = F_11 ( F_75 ( V_147 ) ) ;
V_212 -> V_473 = ( ( V_472 & V_218 ) >>
V_1019 ) + 1 ;
F_639 ( V_38 , V_212 ) ;
}
}
static bool F_672 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_164 V_165 ;
unsigned long V_1079 ;
T_2 V_218 ;
bool V_306 ;
V_165 = F_428 ( V_38 -> V_119 ) ;
if ( ! F_87 ( V_2 , V_165 ) )
return false ;
V_1079 = F_232 ( V_165 ) ;
V_306 = false ;
V_212 -> V_121 = (enum V_118 ) V_38 -> V_119 ;
V_212 -> V_134 = V_955 ;
V_218 = F_11 ( F_72 ( V_605 ) ) ;
if ( V_218 & V_140 ) {
enum V_119 V_1080 ;
switch ( V_218 & V_1081 ) {
default:
F_6 ( 1 , L_181 ) ;
case V_1082 :
case V_1083 :
V_1080 = V_147 ;
break;
case V_1084 :
V_1080 = V_156 ;
break;
case V_1085 :
V_1080 = V_523 ;
break;
}
if ( V_1080 == V_38 -> V_119 )
V_212 -> V_121 = V_605 ;
}
V_165 = F_86 ( V_212 -> V_121 ) ;
if ( ! F_87 ( V_2 , V_165 ) )
goto V_956;
V_1079 |= F_232 ( V_165 ) ;
V_218 = F_11 ( F_61 ( V_212 -> V_121 ) ) ;
if ( ! ( V_218 & V_169 ) )
goto V_956;
F_671 ( V_38 , V_212 ) ;
F_591 ( V_38 , V_212 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
F_673 ( V_16 , V_38 , V_212 ) ;
}
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
V_212 -> V_404 . V_436 = - 1 ;
V_212 -> V_404 . V_550 &= ~ ( 1 << V_560 ) ;
}
V_165 = F_429 ( V_38 -> V_119 ) ;
if ( F_87 ( V_2 , V_165 ) ) {
V_1079 |= F_232 ( V_165 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 )
F_640 ( V_38 , V_212 ) ;
else
F_642 ( V_38 , V_212 ) ;
}
if ( F_240 ( V_16 ) )
V_212 -> V_569 = F_404 ( V_38 ) &&
( F_11 ( V_573 ) & V_574 ) ;
if ( V_212 -> V_121 != V_605 ) {
V_212 -> V_606 =
F_11 ( F_407 ( V_212 -> V_121 ) ) + 1 ;
} else {
V_212 -> V_606 = 1 ;
}
V_306 = true ;
V_956:
F_432 (power_domain, power_domain_mask)
F_88 ( V_2 , V_165 ) ;
return V_306 ;
}
static void F_674 ( struct V_111 * V_38 , T_1 V_40 ,
const struct V_359 * V_280 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_2 V_1086 = 0 , V_297 = 0 ;
if ( V_280 && V_280 -> V_362 ) {
unsigned int V_353 = V_280 -> V_40 . V_371 ;
unsigned int V_273 = V_280 -> V_40 . V_372 ;
unsigned int V_352 = F_675 ( V_353 ) * 4 ;
switch ( V_352 ) {
default:
F_323 ( 1 , L_182 ,
V_353 , V_352 ) ;
V_352 = 256 ;
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
}
V_1086 |= V_162 |
V_1087 |
V_1088 |
F_676 ( V_352 ) ;
V_297 = ( V_273 << 12 ) | V_353 ;
}
if ( V_37 -> V_1089 != 0 &&
( V_37 -> V_1090 != V_40 ||
V_37 -> V_1091 != V_297 ||
V_37 -> V_1089 != V_1086 ) ) {
F_129 ( F_84 ( V_147 ) , 0 ) ;
F_130 ( F_84 ( V_147 ) ) ;
V_37 -> V_1089 = 0 ;
}
if ( V_37 -> V_1090 != V_40 ) {
F_129 ( F_677 ( V_147 ) , V_40 ) ;
V_37 -> V_1090 = V_40 ;
}
if ( V_37 -> V_1091 != V_297 ) {
F_129 ( V_1092 , V_297 ) ;
V_37 -> V_1091 = V_297 ;
}
if ( V_37 -> V_1089 != V_1086 ) {
F_129 ( F_84 ( V_147 ) , V_1086 ) ;
F_130 ( F_84 ( V_147 ) ) ;
V_37 -> V_1089 = V_1086 ;
}
}
static void F_678 ( struct V_111 * V_38 , T_1 V_40 ,
const struct V_359 * V_280 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_2 V_1086 = 0 ;
if ( V_280 && V_280 -> V_362 ) {
V_1086 = V_1093 ;
switch ( V_280 -> V_40 . V_371 ) {
case 64 :
V_1086 |= V_1094 ;
break;
case 128 :
V_1086 |= V_1095 ;
break;
case 256 :
V_1086 |= V_1096 ;
break;
default:
F_181 ( V_280 -> V_40 . V_371 ) ;
return;
}
V_1086 |= V_119 << 28 ;
if ( F_71 ( V_16 ) )
V_1086 |= V_1097 ;
if ( V_280 -> V_40 . V_288 == F_232 ( V_392 ) )
V_1086 |= V_1098 ;
}
if ( V_37 -> V_1089 != V_1086 ) {
F_129 ( F_84 ( V_119 ) , V_1086 ) ;
F_130 ( F_84 ( V_119 ) ) ;
V_37 -> V_1089 = V_1086 ;
}
F_129 ( F_677 ( V_119 ) , V_40 ) ;
F_130 ( F_677 ( V_119 ) ) ;
V_37 -> V_1090 = V_40 ;
}
static void F_679 ( struct V_111 * V_38 ,
const struct V_359 * V_280 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_1 V_40 = V_37 -> V_1099 ;
T_1 V_566 = 0 ;
if ( V_280 ) {
int V_313 = V_280 -> V_40 . V_369 ;
int V_314 = V_280 -> V_40 . V_370 ;
if ( V_313 < 0 ) {
V_566 |= V_1100 << V_1101 ;
V_313 = - V_313 ;
}
V_566 |= V_313 << V_1101 ;
if ( V_314 < 0 ) {
V_566 |= V_1100 << V_1102 ;
V_314 = - V_314 ;
}
V_566 |= V_314 << V_1102 ;
if ( F_170 ( V_16 ) &&
V_280 -> V_40 . V_288 == F_232 ( V_392 ) ) {
V_40 += ( V_280 -> V_40 . V_372 *
V_280 -> V_40 . V_371 - 1 ) * 4 ;
}
}
F_129 ( F_680 ( V_119 ) , V_566 ) ;
if ( F_82 ( V_16 ) || F_83 ( V_16 ) )
F_674 ( V_38 , V_40 , V_280 ) ;
else
F_678 ( V_38 , V_40 , V_280 ) ;
}
static bool F_681 ( struct V_15 * V_16 ,
T_2 V_353 , T_2 V_273 )
{
if ( V_353 == 0 || V_273 == 0 )
return false ;
if ( F_82 ( V_16 ) || F_83 ( V_16 ) ) {
if ( ( V_353 & 63 ) != 0 )
return false ;
if ( V_353 > ( F_82 ( V_16 ) ? 64 : 512 ) )
return false ;
if ( V_273 > 1023 )
return false ;
} else {
switch ( V_353 | V_273 ) {
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
static void F_682 ( struct V_111 * V_38 , T_7 * V_1103 , T_7 * V_1104 ,
T_7 * V_1105 , T_2 V_400 , T_2 V_297 )
{
int V_1106 = ( V_400 + V_297 > 256 ) ? 256 : V_400 + V_297 , V_50 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
for ( V_50 = V_400 ; V_50 < V_1106 ; V_50 ++ ) {
V_37 -> V_579 [ V_50 ] = V_1103 [ V_50 ] >> 8 ;
V_37 -> V_580 [ V_50 ] = V_1104 [ V_50 ] >> 8 ;
V_37 -> V_581 [ V_50 ] = V_1105 [ V_50 ] >> 8 ;
}
F_377 ( V_38 ) ;
}
struct V_278 *
F_683 ( struct V_15 * V_16 ,
struct V_342 * V_343 ,
struct V_303 * V_304 )
{
struct V_947 * V_948 ;
int V_306 ;
V_948 = F_499 ( sizeof( * V_948 ) , V_743 ) ;
if ( ! V_948 )
return F_684 ( - V_742 ) ;
V_306 = F_212 ( V_16 , V_948 , V_343 , V_304 ) ;
if ( V_306 )
goto V_98;
return & V_948 -> V_40 ;
V_98:
F_221 ( V_948 ) ;
return F_684 ( V_306 ) ;
}
static struct V_278 *
F_685 ( struct V_15 * V_16 ,
struct V_342 * V_343 ,
struct V_303 * V_304 )
{
struct V_278 * V_114 ;
int V_306 ;
V_306 = F_686 ( V_16 ) ;
if ( V_306 )
return F_684 ( V_306 ) ;
V_114 = F_683 ( V_16 , V_343 , V_304 ) ;
F_4 ( & V_16 -> V_307 ) ;
return V_114 ;
}
static T_1
F_687 ( int V_353 , int V_1006 )
{
T_1 V_290 = F_189 ( V_353 * V_1006 , 8 ) ;
return F_186 ( V_290 , 64 ) ;
}
static T_1
F_688 ( struct V_532 * V_446 , int V_1006 )
{
T_1 V_290 = F_687 ( V_446 -> V_918 , V_1006 ) ;
return F_689 ( V_290 * V_446 -> V_917 ) ;
}
static struct V_278 *
F_690 ( struct V_15 * V_16 ,
struct V_532 * V_446 ,
int V_1107 , int V_1006 )
{
struct V_278 * V_114 ;
struct V_303 * V_304 ;
struct V_342 V_343 = { 0 } ;
V_304 = F_691 ( V_16 ,
F_688 ( V_446 , V_1006 ) ) ;
if ( V_304 == NULL )
return F_684 ( - V_742 ) ;
V_343 . V_353 = V_446 -> V_918 ;
V_343 . V_273 = V_446 -> V_917 ;
V_343 . V_291 [ 0 ] = F_687 ( V_343 . V_353 ,
V_1006 ) ;
V_343 . V_274 = F_692 ( V_1006 , V_1107 ) ;
V_114 = F_685 ( V_16 , & V_343 , V_304 ) ;
if ( F_505 ( V_114 ) )
F_693 ( & V_304 -> V_40 ) ;
return V_114 ;
}
static struct V_278 *
F_694 ( struct V_15 * V_16 ,
struct V_532 * V_446 )
{
#ifdef F_695
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_303 * V_304 ;
struct V_278 * V_114 ;
if ( ! V_2 -> V_1108 )
return NULL ;
if ( ! V_2 -> V_1108 -> V_114 )
return NULL ;
V_304 = V_2 -> V_1108 -> V_114 -> V_304 ;
F_142 ( ! V_304 ) ;
V_114 = & V_2 -> V_1108 -> V_114 -> V_40 ;
if ( V_114 -> V_291 [ 0 ] < F_687 ( V_446 -> V_918 ,
V_114 -> V_815 ) )
return NULL ;
if ( V_304 -> V_40 . V_297 < V_446 -> V_917 * V_114 -> V_291 [ 0 ] )
return NULL ;
F_217 ( V_114 ) ;
return V_114 ;
#else
return NULL ;
#endif
}
static int F_696 ( struct V_45 * V_36 ,
struct V_111 * V_38 ,
struct V_532 * V_446 ,
struct V_278 * V_114 ,
int V_313 , int V_314 )
{
struct V_279 * V_280 ;
int V_918 , V_917 ;
int V_306 ;
V_280 = F_697 ( V_36 , V_38 -> V_113 ) ;
if ( F_505 ( V_280 ) )
return F_506 ( V_280 ) ;
if ( V_446 )
F_698 ( V_446 , & V_918 , & V_917 ) ;
else
V_918 = V_917 = 0 ;
V_306 = F_699 ( V_280 , V_114 ? V_38 : NULL ) ;
if ( V_306 )
return V_306 ;
F_700 ( V_280 , V_114 ) ;
V_280 -> V_369 = 0 ;
V_280 -> V_370 = 0 ;
V_280 -> V_371 = V_918 ;
V_280 -> V_372 = V_917 ;
V_280 -> V_365 = V_313 << 16 ;
V_280 -> V_366 = V_314 << 16 ;
V_280 -> V_367 = V_918 << 16 ;
V_280 -> V_368 = V_917 << 16 ;
return 0 ;
}
bool F_701 ( struct V_46 * V_47 ,
struct V_532 * V_446 ,
struct V_1109 * V_1110 ,
struct V_1111 * V_1112 )
{
struct V_37 * V_37 ;
struct V_41 * V_41 =
F_702 ( V_47 ) ;
struct V_111 * V_1113 ;
struct V_635 * V_42 = & V_41 -> V_40 ;
struct V_111 * V_38 = NULL ;
struct V_15 * V_16 = V_42 -> V_16 ;
struct V_278 * V_114 ;
struct V_1114 * V_115 = & V_16 -> V_1115 ;
struct V_45 * V_36 = NULL , * V_1116 = NULL ;
struct V_48 * V_49 ;
struct V_43 * V_44 ;
int V_306 , V_50 = - 1 ;
F_153 ( L_183 ,
V_47 -> V_40 . V_241 , V_47 -> V_8 ,
V_42 -> V_40 . V_241 , V_42 -> V_8 ) ;
V_1110 -> V_1116 = NULL ;
V_478:
V_306 = F_703 ( & V_115 -> V_1117 , V_1112 ) ;
if ( V_306 )
goto V_808;
if ( V_47 -> V_36 -> V_38 ) {
V_38 = V_47 -> V_36 -> V_38 ;
V_306 = F_703 ( & V_38 -> V_1118 , V_1112 ) ;
if ( V_306 )
goto V_808;
goto V_101;
}
F_222 (dev, possible_crtc) {
V_50 ++ ;
if ( ! ( V_42 -> V_1119 & ( 1 << V_50 ) ) )
continue;
V_306 = F_703 ( & V_1113 -> V_1118 , V_1112 ) ;
if ( V_306 )
goto V_808;
if ( V_1113 -> V_36 -> V_243 ) {
F_704 ( & V_1113 -> V_1118 ) ;
continue;
}
V_38 = V_1113 ;
break;
}
if ( ! V_38 ) {
F_153 ( L_184 ) ;
goto V_808;
}
V_101:
V_37 = F_50 ( V_38 ) ;
V_306 = F_703 ( & V_38 -> V_113 -> V_1118 , V_1112 ) ;
if ( V_306 )
goto V_808;
V_36 = F_705 ( V_16 ) ;
V_1116 = F_705 ( V_16 ) ;
if ( ! V_36 || ! V_1116 ) {
V_306 = - V_742 ;
goto V_808;
}
V_36 -> V_1120 = V_1112 ;
V_1116 -> V_1120 = V_1112 ;
V_49 = F_706 ( V_36 , V_47 ) ;
if ( F_505 ( V_49 ) ) {
V_306 = F_506 ( V_49 ) ;
goto V_808;
}
V_306 = F_707 ( V_49 , V_38 ) ;
if ( V_306 )
goto V_808;
V_44 = F_504 ( V_36 , V_37 ) ;
if ( F_505 ( V_44 ) ) {
V_306 = F_506 ( V_44 ) ;
goto V_808;
}
V_44 -> V_40 . V_112 = V_44 -> V_40 . V_243 = true ;
if ( ! V_446 )
V_446 = & V_1121 ;
V_114 = F_694 ( V_16 , V_446 ) ;
if ( V_114 == NULL ) {
F_153 ( L_185 ) ;
V_114 = F_690 ( V_16 , V_446 , 24 , 32 ) ;
} else
F_153 ( L_186 ) ;
if ( F_505 ( V_114 ) ) {
F_153 ( L_187 ) ;
goto V_808;
}
V_306 = F_696 ( V_36 , V_38 , V_446 , V_114 , 0 , 0 ) ;
if ( V_306 )
goto V_808;
F_216 ( V_114 ) ;
V_306 = F_708 ( & V_44 -> V_40 , V_446 ) ;
if ( V_306 )
goto V_808;
V_306 = F_492 ( F_706 ( V_1116 , V_47 ) ) ;
if ( ! V_306 )
V_306 = F_492 ( F_709 ( V_1116 , V_38 ) ) ;
if ( ! V_306 )
V_306 = F_492 ( F_697 ( V_1116 , V_38 -> V_113 ) ) ;
if ( V_306 ) {
F_153 ( L_188 , V_306 ) ;
goto V_808;
}
V_306 = F_710 ( V_36 ) ;
if ( V_306 ) {
F_153 ( L_189 ) ;
goto V_808;
}
V_1110 -> V_1116 = V_1116 ;
F_313 ( V_16 , V_37 -> V_119 ) ;
return true ;
V_808:
F_711 ( V_36 ) ;
F_711 ( V_1116 ) ;
V_1116 = V_36 = NULL ;
if ( V_306 == - V_310 ) {
F_712 ( V_1112 ) ;
goto V_478;
}
return false ;
}
void F_713 ( struct V_46 * V_47 ,
struct V_1109 * V_1110 ,
struct V_1111 * V_1112 )
{
struct V_41 * V_41 =
F_702 ( V_47 ) ;
struct V_635 * V_42 = & V_41 -> V_40 ;
struct V_45 * V_36 = V_1110 -> V_1116 ;
int V_306 ;
F_153 ( L_183 ,
V_47 -> V_40 . V_241 , V_47 -> V_8 ,
V_42 -> V_40 . V_241 , V_42 -> V_8 ) ;
if ( ! V_36 )
return;
V_306 = F_710 ( V_36 ) ;
if ( V_306 ) {
F_153 ( L_190 , V_306 ) ;
F_711 ( V_36 ) ;
}
}
static int F_714 ( struct V_15 * V_16 ,
const struct V_43 * V_212 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_87 = V_212 -> V_213 . V_87 ;
if ( ( V_87 & V_1122 ) == V_902 )
return V_2 -> V_827 . V_830 ;
else if ( F_10 ( V_16 ) )
return 120000 ;
else if ( ! F_33 ( V_16 ) )
return 96000 ;
else
return 48000 ;
}
static void F_603 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_212 -> V_121 ;
T_1 V_87 = V_212 -> V_213 . V_87 ;
T_1 V_832 ;
T_4 clock ;
int V_864 ;
int V_53 = F_714 ( V_16 , V_212 ) ;
if ( ( V_87 & V_1123 ) == 0 )
V_832 = V_212 -> V_213 . V_735 ;
else
V_832 = V_212 -> V_213 . V_736 ;
clock . V_88 = ( V_832 & V_1124 ) >> V_1125 ;
if ( F_32 ( V_16 ) ) {
clock . V_84 = F_715 ( ( V_832 & V_1126 ) >> V_1127 ) - 1 ;
clock . V_80 = ( V_832 & V_1128 ) >> V_1129 ;
} else {
clock . V_84 = ( V_832 & V_1130 ) >> V_1127 ;
clock . V_80 = ( V_832 & V_1131 ) >> V_1129 ;
}
if ( ! F_33 ( V_16 ) ) {
if ( F_32 ( V_16 ) )
clock . V_82 = F_715 ( ( V_87 & V_1132 ) >>
V_892 ) ;
else
clock . V_82 = F_715 ( ( V_87 & V_1133 ) >>
V_893 ) ;
switch ( V_87 & V_1134 ) {
case V_889 :
clock . V_83 = V_87 & V_895 ?
5 : 10 ;
break;
case V_888 :
clock . V_83 = V_87 & V_896 ?
7 : 14 ;
break;
default:
F_153 ( L_191
L_192 , ( int ) ( V_87 & V_1134 ) ) ;
return;
}
if ( F_32 ( V_16 ) )
V_864 = F_34 ( V_53 , & clock ) ;
else
V_864 = F_36 ( V_53 , & clock ) ;
} else {
T_1 V_1135 = F_143 ( V_16 ) ? 0 : F_11 ( V_158 ) ;
bool V_992 = ( V_119 == 1 ) && ( V_1135 & V_195 ) ;
if ( V_992 ) {
clock . V_82 = F_715 ( ( V_87 & V_1136 ) >>
V_893 ) ;
if ( V_1135 & V_1137 )
clock . V_83 = 7 ;
else
clock . V_83 = 14 ;
} else {
if ( V_87 & V_904 )
clock . V_82 = 2 ;
else {
clock . V_82 = ( ( V_87 & V_1138 ) >>
V_893 ) + 2 ;
}
if ( V_87 & V_905 )
clock . V_83 = 4 ;
else
clock . V_83 = 2 ;
}
V_864 = F_36 ( V_53 , & clock ) ;
}
V_212 -> V_864 = V_864 ;
}
int F_716 ( int V_1139 ,
const struct V_819 * V_820 )
{
if ( ! V_820 -> V_825 )
return 0 ;
return F_48 ( ( T_6 ) V_820 -> V_824 * V_1139 , V_820 -> V_825 ) ;
}
static void F_646 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
F_603 ( V_38 , V_212 ) ;
V_212 -> V_40 . V_116 . V_117 =
F_716 ( F_17 ( V_16 ) * 10000 ,
& V_212 -> V_602 ) ;
}
struct V_532 * F_717 ( struct V_15 * V_16 ,
struct V_111 * V_38 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_118 V_121 = V_37 -> V_115 -> V_121 ;
struct V_532 * V_446 ;
struct V_43 * V_212 ;
int V_1140 = F_11 ( F_334 ( V_121 ) ) ;
int V_926 = F_11 ( F_338 ( V_121 ) ) ;
int V_1141 = F_11 ( F_340 ( V_121 ) ) ;
int V_1142 = F_11 ( F_344 ( V_121 ) ) ;
enum V_119 V_119 = V_37 -> V_119 ;
V_446 = F_499 ( sizeof( * V_446 ) , V_743 ) ;
if ( ! V_446 )
return NULL ;
V_212 = F_499 ( sizeof( * V_212 ) , V_743 ) ;
if ( ! V_212 ) {
F_221 ( V_446 ) ;
return NULL ;
}
V_212 -> V_121 = (enum V_118 ) V_119 ;
V_212 -> V_606 = 1 ;
V_212 -> V_213 . V_87 = F_11 ( F_64 ( V_119 ) ) ;
V_212 -> V_213 . V_735 = F_11 ( F_484 ( V_119 ) ) ;
V_212 -> V_213 . V_736 = F_11 ( F_485 ( V_119 ) ) ;
F_603 ( V_37 , V_212 ) ;
V_446 -> clock = V_212 -> V_864 / V_212 -> V_606 ;
V_446 -> V_918 = ( V_1140 & 0xffff ) + 1 ;
V_446 -> V_919 = ( ( V_1140 & 0xffff0000 ) >> 16 ) + 1 ;
V_446 -> V_920 = ( V_926 & 0xffff ) + 1 ;
V_446 -> V_921 = ( ( V_926 & 0xffff0000 ) >> 16 ) + 1 ;
V_446 -> V_917 = ( V_1141 & 0xffff ) + 1 ;
V_446 -> V_922 = ( ( V_1141 & 0xffff0000 ) >> 16 ) + 1 ;
V_446 -> V_923 = ( V_1142 & 0xffff ) + 1 ;
V_446 -> V_924 = ( ( V_1142 & 0xffff0000 ) >> 16 ) + 1 ;
F_595 ( V_446 ) ;
F_221 ( V_212 ) ;
return V_446 ;
}
void F_718 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( V_2 -> V_583 . V_1143 )
return;
F_197 ( V_2 ) ;
F_719 ( V_2 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 6 )
F_720 ( V_2 ) ;
V_2 -> V_583 . V_1143 = true ;
}
void F_721 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! V_2 -> V_583 . V_1143 )
return;
V_2 -> V_583 . V_1143 = false ;
if ( F_60 ( V_16 ) -> V_127 >= 6 )
F_722 ( V_16 -> V_17 ) ;
F_201 ( V_2 ) ;
}
static void F_723 ( struct V_111 * V_38 )
{
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_494 * V_495 ;
F_282 ( & V_16 -> V_456 ) ;
V_495 = V_37 -> V_457 ;
V_37 -> V_457 = NULL ;
F_283 ( & V_16 -> V_456 ) ;
if ( V_495 ) {
F_724 ( & V_495 -> V_495 ) ;
F_221 ( V_495 ) ;
}
F_725 ( V_38 ) ;
F_221 ( V_37 ) ;
}
static void F_726 ( struct V_1144 * V_1145 )
{
struct V_494 * V_495 =
F_727 ( V_1145 , struct V_494 , V_495 ) ;
struct V_37 * V_38 = F_50 ( V_495 -> V_38 ) ;
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_302 * V_113 = V_38 -> V_40 . V_113 ;
F_2 ( & V_16 -> V_307 ) ;
F_203 ( V_495 -> V_1146 , V_113 -> V_36 ) ;
F_214 ( & V_495 -> V_499 -> V_40 ) ;
if ( V_495 -> V_1147 )
F_728 ( & V_495 -> V_1147 , NULL ) ;
F_4 ( & V_16 -> V_307 ) ;
F_729 ( V_16 , F_219 ( V_113 ) -> V_381 ) ;
F_390 ( V_38 ) ;
F_216 ( V_495 -> V_1146 ) ;
F_142 ( F_289 ( & V_38 -> V_493 ) == 0 ) ;
F_730 ( & V_38 -> V_493 ) ;
F_221 ( V_495 ) ;
}
static void F_731 ( struct V_15 * V_16 ,
struct V_111 * V_38 )
{
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_494 * V_495 ;
unsigned long V_354 ;
if ( V_37 == NULL )
return;
F_732 ( & V_16 -> V_456 , V_354 ) ;
V_495 = V_37 -> V_457 ;
F_315 () ;
if ( V_495 == NULL || F_289 ( & V_495 -> V_453 ) < V_1148 ) {
F_733 ( & V_16 -> V_456 , V_354 ) ;
return;
}
F_314 ( V_37 ) ;
F_733 ( & V_16 -> V_456 , V_354 ) ;
}
void F_734 ( struct V_15 * V_16 , int V_119 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_111 * V_38 = V_2 -> V_120 [ V_119 ] ;
F_731 ( V_16 , V_38 ) ;
}
void F_270 ( struct V_15 * V_16 , int V_170 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_111 * V_38 = V_2 -> V_1149 [ V_170 ] ;
F_731 ( V_16 , V_38 ) ;
}
static bool F_735 ( T_1 V_1150 , T_1 V_1151 )
{
return ! ( ( V_1150 - V_1151 ) & 0x80000000 ) ;
}
static bool F_736 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_288 ( & V_2 -> V_454 ) ||
V_38 -> V_455 != F_289 ( & V_2 -> V_454 . V_455 ) )
return true ;
if ( F_60 ( V_16 ) -> V_127 < 5 && ! F_31 ( V_16 ) )
return true ;
return ( F_11 ( F_737 ( V_38 -> V_170 ) ) & ~ 0xfff ) ==
V_38 -> V_457 -> V_1152 &&
F_735 ( F_11 ( F_738 ( V_38 -> V_119 ) ) ,
V_38 -> V_457 -> V_1153 ) ;
}
void F_269 ( struct V_15 * V_16 , int V_170 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 =
F_50 ( V_2 -> V_1149 [ V_170 ] ) ;
unsigned long V_354 ;
F_732 ( & V_16 -> V_456 , V_354 ) ;
if ( V_37 -> V_457 && F_736 ( V_37 ) )
F_739 ( & V_37 -> V_457 -> V_453 ) ;
F_733 ( & V_16 -> V_456 , V_354 ) ;
}
static inline void F_740 ( struct V_494 * V_495 )
{
F_741 () ;
F_742 ( & V_495 -> V_453 , V_1154 ) ;
F_741 () ;
}
static int F_743 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_278 * V_114 ,
struct V_303 * V_304 ,
struct V_1155 * V_1156 ,
T_2 V_354 )
{
struct V_1157 * V_1158 = V_1156 -> V_1158 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_1 V_1159 ;
int V_306 ;
V_306 = F_744 ( V_1156 , 6 ) ;
if ( V_306 )
return V_306 ;
if ( V_37 -> V_170 )
V_1159 = V_1160 ;
else
V_1159 = V_1161 ;
F_745 ( V_1158 , V_1162 | V_1159 ) ;
F_745 ( V_1158 , V_1163 ) ;
F_745 ( V_1158 , V_1164 |
F_746 ( V_37 -> V_170 ) ) ;
F_745 ( V_1158 , V_114 -> V_291 [ 0 ] ) ;
F_745 ( V_1158 , V_37 -> V_457 -> V_1152 ) ;
F_745 ( V_1158 , 0 ) ;
F_740 ( V_37 -> V_457 ) ;
return 0 ;
}
static int F_747 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_278 * V_114 ,
struct V_303 * V_304 ,
struct V_1155 * V_1156 ,
T_2 V_354 )
{
struct V_1157 * V_1158 = V_1156 -> V_1158 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_1 V_1159 ;
int V_306 ;
V_306 = F_744 ( V_1156 , 6 ) ;
if ( V_306 )
return V_306 ;
if ( V_37 -> V_170 )
V_1159 = V_1160 ;
else
V_1159 = V_1161 ;
F_745 ( V_1158 , V_1162 | V_1159 ) ;
F_745 ( V_1158 , V_1163 ) ;
F_745 ( V_1158 , V_1165 |
F_746 ( V_37 -> V_170 ) ) ;
F_745 ( V_1158 , V_114 -> V_291 [ 0 ] ) ;
F_745 ( V_1158 , V_37 -> V_457 -> V_1152 ) ;
F_745 ( V_1158 , V_1163 ) ;
F_740 ( V_37 -> V_457 ) ;
return 0 ;
}
static int F_748 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_278 * V_114 ,
struct V_303 * V_304 ,
struct V_1155 * V_1156 ,
T_2 V_354 )
{
struct V_1157 * V_1158 = V_1156 -> V_1158 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_2 V_1166 , V_1167 ;
int V_306 ;
V_306 = F_744 ( V_1156 , 4 ) ;
if ( V_306 )
return V_306 ;
F_745 ( V_1158 , V_1164 |
F_746 ( V_37 -> V_170 ) ) ;
F_745 ( V_1158 , V_114 -> V_291 [ 0 ] ) ;
F_745 ( V_1158 , V_37 -> V_457 -> V_1152 |
V_304 -> V_349 ) ;
V_1166 = 0 ;
V_1167 = F_11 ( F_292 ( V_37 -> V_119 ) ) & 0x0fff0fff ;
F_745 ( V_1158 , V_1166 | V_1167 ) ;
F_740 ( V_37 -> V_457 ) ;
return 0 ;
}
static int F_749 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_278 * V_114 ,
struct V_303 * V_304 ,
struct V_1155 * V_1156 ,
T_2 V_354 )
{
struct V_1157 * V_1158 = V_1156 -> V_1158 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_2 V_1166 , V_1167 ;
int V_306 ;
V_306 = F_744 ( V_1156 , 4 ) ;
if ( V_306 )
return V_306 ;
F_745 ( V_1158 , V_1164 |
F_746 ( V_37 -> V_170 ) ) ;
F_745 ( V_1158 , V_114 -> V_291 [ 0 ] | V_304 -> V_349 ) ;
F_745 ( V_1158 , V_37 -> V_457 -> V_1152 ) ;
V_1166 = 0 ;
V_1167 = F_11 ( F_292 ( V_37 -> V_119 ) ) & 0x0fff0fff ;
F_745 ( V_1158 , V_1166 | V_1167 ) ;
F_740 ( V_37 -> V_457 ) ;
return 0 ;
}
static int F_750 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_278 * V_114 ,
struct V_303 * V_304 ,
struct V_1155 * V_1156 ,
T_2 V_354 )
{
struct V_1157 * V_1158 = V_1156 -> V_1158 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_2 V_1168 = 0 ;
int V_1169 , V_306 ;
switch ( V_37 -> V_170 ) {
case V_1170 :
V_1168 = V_1171 ;
break;
case V_388 :
V_1168 = V_1172 ;
break;
case V_1173 :
V_1168 = V_1174 ;
break;
default:
F_323 ( 1 , L_193 ) ;
return - V_448 ;
}
V_1169 = 4 ;
if ( V_1158 -> V_241 == V_1175 ) {
V_1169 += 6 ;
if ( F_751 ( V_16 ) )
V_1169 += 2 ;
}
V_306 = F_752 ( V_1156 ) ;
if ( V_306 )
return V_306 ;
V_306 = F_744 ( V_1156 , V_1169 ) ;
if ( V_306 )
return V_306 ;
if ( V_1158 -> V_241 == V_1175 ) {
F_745 ( V_1158 , F_753 ( 1 ) ) ;
F_754 ( V_1158 , V_1176 ) ;
F_745 ( V_1158 , ~ ( V_1177 |
V_1178 |
V_1179 ) ) ;
if ( F_751 ( V_16 ) )
F_745 ( V_1158 , V_1180 |
V_1181 ) ;
else
F_745 ( V_1158 , V_1182 |
V_1181 ) ;
F_754 ( V_1158 , V_1176 ) ;
F_745 ( V_1158 , V_1158 -> V_1183 . V_1152 + 256 ) ;
if ( F_751 ( V_16 ) ) {
F_745 ( V_1158 , 0 ) ;
F_745 ( V_1158 , V_1163 ) ;
}
}
F_745 ( V_1158 , V_1165 | V_1168 ) ;
F_745 ( V_1158 , ( V_114 -> V_291 [ 0 ] | V_304 -> V_349 ) ) ;
F_745 ( V_1158 , V_37 -> V_457 -> V_1152 ) ;
F_745 ( V_1158 , ( V_1163 ) ) ;
F_740 ( V_37 -> V_457 ) ;
return 0 ;
}
static bool F_755 ( struct V_1157 * V_1158 ,
struct V_303 * V_304 )
{
if ( V_1158 == NULL )
return true ;
if ( F_60 ( V_1158 -> V_16 ) -> V_127 < 5 )
return false ;
if ( V_754 . F_755 < 0 )
return false ;
else if ( V_754 . F_755 > 0 )
return true ;
else if ( V_754 . V_1184 )
return true ;
else if ( V_304 -> V_40 . V_1185 &&
! F_756 ( V_304 -> V_40 . V_1185 -> V_1186 ,
false ) )
return true ;
else
return V_1158 != F_757 ( V_304 -> V_1187 ) ;
}
static void F_758 ( struct V_37 * V_37 ,
unsigned int V_288 ,
struct V_494 * V_495 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_278 * V_114 = V_37 -> V_40 . V_113 -> V_114 ;
const enum V_119 V_119 = V_37 -> V_119 ;
T_1 V_1188 , V_352 , V_275 ;
V_1188 = F_11 ( F_96 ( V_119 , 0 ) ) ;
V_1188 &= ~ V_1016 ;
switch ( V_114 -> V_294 [ 0 ] ) {
case V_269 :
break;
case V_270 :
V_1188 |= V_420 ;
break;
case V_271 :
V_1188 |= V_421 ;
break;
case V_272 :
V_1188 |= V_422 ;
break;
default:
F_181 ( V_114 -> V_294 [ 0 ] ) ;
}
if ( F_188 ( V_288 ) ) {
V_275 = F_182 ( V_2 , V_114 -> V_294 [ 0 ] , 0 ) ;
V_352 = F_189 ( V_114 -> V_273 , V_275 ) ;
} else {
V_352 = V_114 -> V_291 [ 0 ] /
F_243 ( V_2 , V_114 -> V_294 [ 0 ] ,
V_114 -> V_274 ) ;
}
F_129 ( F_96 ( V_119 , 0 ) , V_1188 ) ;
F_129 ( F_261 ( V_119 , 0 ) , V_352 ) ;
F_129 ( F_265 ( V_119 , 0 ) , V_495 -> V_1152 ) ;
F_130 ( F_265 ( V_119 , 0 ) ) ;
}
static void F_759 ( struct V_37 * V_37 ,
struct V_494 * V_495 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_947 * V_948 =
F_213 ( V_37 -> V_40 . V_113 -> V_114 ) ;
struct V_303 * V_304 = V_948 -> V_304 ;
T_5 V_9 = F_90 ( V_37 -> V_170 ) ;
T_1 V_383 ;
V_383 = F_11 ( V_9 ) ;
if ( V_304 -> V_349 != V_378 )
V_383 |= V_389 ;
else
V_383 &= ~ V_389 ;
F_129 ( V_9 , V_383 ) ;
F_129 ( F_234 ( V_37 -> V_170 ) , V_495 -> V_1152 ) ;
F_130 ( F_234 ( V_37 -> V_170 ) ) ;
}
static void F_760 ( struct V_1189 * V_1190 )
{
struct V_37 * V_38 = V_1190 -> V_38 ;
struct V_494 * V_495 ;
F_282 ( & V_38 -> V_40 . V_16 -> V_456 ) ;
V_495 = V_38 -> V_457 ;
F_283 ( & V_38 -> V_40 . V_16 -> V_456 ) ;
if ( V_495 == NULL )
return;
F_740 ( V_495 ) ;
F_761 ( V_38 ) ;
if ( F_60 ( V_1190 -> V_754 ) -> V_127 >= 9 )
F_758 ( V_38 , V_1190 -> V_288 , V_495 ) ;
else
F_759 ( V_38 , V_495 ) ;
F_762 ( V_38 ) ;
}
static void F_763 ( struct V_1144 * V_495 )
{
struct V_1189 * V_1190 =
F_727 ( V_495 , struct V_1189 , V_495 ) ;
struct V_947 * V_948 =
F_213 ( V_1190 -> V_38 -> V_40 . V_113 -> V_114 ) ;
struct V_303 * V_304 = V_948 -> V_304 ;
if ( V_1190 -> V_1156 ) {
F_9 ( F_764 ( V_1190 -> V_1156 ,
V_1190 -> V_38 -> V_455 ,
false , NULL ,
& V_1190 -> V_754 -> V_570 . V_1191 ) ) ;
F_765 ( V_1190 -> V_1156 ) ;
}
if ( V_304 -> V_40 . V_1185 )
F_9 ( F_766 ( V_304 -> V_40 . V_1185 -> V_1186 ,
false , false ,
V_1192 ) < 0 ) ;
F_760 ( V_1190 ) ;
F_221 ( V_1190 ) ;
}
static int F_767 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_303 * V_304 )
{
struct V_1189 * V_1190 ;
V_1190 = F_768 ( sizeof( * V_1190 ) , V_743 ) ;
if ( V_1190 == NULL )
return - V_742 ;
V_1190 -> V_754 = F_185 ( V_16 ) ;
V_1190 -> V_1156 = F_769 ( V_304 -> V_1187 ) ;
V_1190 -> V_38 = F_50 ( V_38 ) ;
V_1190 -> V_288 = V_38 -> V_113 -> V_36 -> V_288 ;
F_770 ( & V_1190 -> V_495 , F_763 ) ;
F_771 ( & V_1190 -> V_495 ) ;
return 0 ;
}
static int F_772 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_278 * V_114 ,
struct V_303 * V_304 ,
struct V_1155 * V_1156 ,
T_2 V_354 )
{
return - V_448 ;
}
static bool F_773 ( struct V_15 * V_16 ,
struct V_111 * V_38 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_494 * V_495 = V_37 -> V_457 ;
T_1 V_1193 ;
if ( F_289 ( & V_495 -> V_453 ) >= V_1148 )
return true ;
if ( F_289 ( & V_495 -> V_453 ) < V_1154 )
return false ;
if ( ! V_495 -> V_1194 )
return false ;
if ( V_495 -> V_1195 == 0 ) {
if ( V_495 -> V_1147 &&
! F_774 ( V_495 -> V_1147 , true ) )
return false ;
V_495 -> V_1195 = F_775 ( V_38 ) ;
}
if ( F_775 ( V_38 ) - V_495 -> V_1195 < 3 )
return false ;
if ( F_60 ( V_16 ) -> V_127 >= 4 )
V_1193 = F_776 ( F_11 ( F_234 ( V_37 -> V_170 ) ) ) ;
else
V_1193 = F_11 ( F_237 ( V_37 -> V_170 ) ) ;
return V_1193 == V_495 -> V_1152 ;
}
void F_777 ( struct V_15 * V_16 , int V_119 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_111 * V_38 = V_2 -> V_120 [ V_119 ] ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_494 * V_495 ;
F_9 ( ! F_778 () ) ;
if ( V_38 == NULL )
return;
F_779 ( & V_16 -> V_456 ) ;
V_495 = V_37 -> V_457 ;
if ( V_495 != NULL && F_773 ( V_16 , V_38 ) ) {
F_323 ( 1 , L_194 ,
V_495 -> V_1196 , F_780 ( V_16 , V_119 ) ) ;
F_314 ( V_37 ) ;
V_495 = NULL ;
}
if ( V_495 != NULL &&
F_780 ( V_16 , V_119 ) - V_495 -> V_1196 > 1 )
F_781 ( V_16 , V_495 -> V_1147 ) ;
F_782 ( & V_16 -> V_456 ) ;
}
static int F_783 ( struct V_111 * V_38 ,
struct V_278 * V_114 ,
struct V_1197 * V_496 ,
T_2 V_1198 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_278 * V_1146 = V_38 -> V_113 -> V_114 ;
struct V_303 * V_304 = F_195 ( V_114 ) ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_302 * V_113 = V_38 -> V_113 ;
enum V_119 V_119 = V_37 -> V_119 ;
struct V_494 * V_495 ;
struct V_1157 * V_1158 ;
bool V_1190 ;
struct V_1155 * V_1199 = NULL ;
int V_306 ;
if ( F_9 ( F_195 ( V_1146 ) == NULL ) )
return - V_311 ;
if ( V_114 -> V_274 != V_38 -> V_113 -> V_114 -> V_274 )
return - V_559 ;
if ( F_60 ( V_16 ) -> V_127 > 3 &&
( V_114 -> V_293 [ 0 ] != V_38 -> V_113 -> V_114 -> V_293 [ 0 ] ||
V_114 -> V_291 [ 0 ] != V_38 -> V_113 -> V_114 -> V_291 [ 0 ] ) )
return - V_559 ;
if ( F_784 ( & V_2 -> V_454 ) )
goto V_1200;
V_495 = F_499 ( sizeof( * V_495 ) , V_743 ) ;
if ( V_495 == NULL )
return - V_742 ;
V_495 -> V_496 = V_496 ;
V_495 -> V_38 = V_38 ;
V_495 -> V_1146 = V_1146 ;
F_770 ( & V_495 -> V_495 , F_726 ) ;
V_306 = F_103 ( V_38 ) ;
if ( V_306 )
goto V_1201;
F_282 ( & V_16 -> V_456 ) ;
if ( V_37 -> V_457 ) {
if ( F_773 ( V_16 , V_38 ) ) {
F_16 ( L_195 ) ;
F_314 ( V_37 ) ;
} else {
F_16 ( L_196 ) ;
F_283 ( & V_16 -> V_456 ) ;
F_104 ( V_38 ) ;
F_221 ( V_495 ) ;
return - V_311 ;
}
}
V_37 -> V_457 = V_495 ;
F_283 ( & V_16 -> V_456 ) ;
if ( F_289 ( & V_37 -> V_493 ) >= 2 )
F_785 ( V_2 -> V_498 ) ;
F_217 ( V_495 -> V_1146 ) ;
F_786 ( & V_304 -> V_40 ) ;
V_38 -> V_113 -> V_114 = V_114 ;
F_215 ( V_38 -> V_113 ) ;
F_393 ( V_37 ) ;
V_495 -> V_499 = V_304 ;
V_306 = F_686 ( V_16 ) ;
if ( V_306 )
goto V_1202;
F_787 ( & V_37 -> V_493 ) ;
V_37 -> V_455 = F_289 ( & V_2 -> V_454 . V_455 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 5 || F_31 ( V_16 ) )
V_495 -> V_1153 = F_11 ( F_738 ( V_119 ) ) + 1 ;
if ( F_13 ( V_16 ) || F_14 ( V_16 ) ) {
V_1158 = & V_2 -> V_1158 [ V_1203 ] ;
if ( V_304 -> V_349 != F_195 ( V_495 -> V_1146 ) -> V_349 )
V_1158 = NULL ;
} else if ( F_297 ( V_16 ) || F_240 ( V_16 ) ) {
V_1158 = & V_2 -> V_1158 [ V_1203 ] ;
} else if ( F_60 ( V_16 ) -> V_127 >= 7 ) {
V_1158 = F_757 ( V_304 -> V_1187 ) ;
if ( V_1158 == NULL || V_1158 -> V_241 != V_1175 )
V_1158 = & V_2 -> V_1158 [ V_1203 ] ;
} else {
V_1158 = & V_2 -> V_1158 [ V_1175 ] ;
}
V_1190 = F_755 ( V_1158 , V_304 ) ;
if ( ! V_1190 ) {
V_306 = F_788 ( V_304 , V_1158 , & V_1199 ) ;
if ( V_306 )
goto V_1204;
}
V_306 = F_194 ( V_38 -> V_113 , V_114 ,
V_38 -> V_113 -> V_36 ) ;
if ( V_306 )
goto V_1204;
V_495 -> V_1152 = F_244 ( F_219 ( V_113 ) ,
V_304 , 0 ) ;
V_495 -> V_1152 += V_37 -> V_391 ;
if ( V_1190 ) {
V_306 = F_767 ( V_16 , V_38 , V_304 ) ;
if ( V_306 )
goto V_1205;
F_728 ( & V_495 -> V_1147 ,
V_304 -> V_1187 ) ;
} else {
if ( ! V_1199 ) {
V_1199 = F_789 ( V_1158 , NULL ) ;
if ( F_505 ( V_1199 ) ) {
V_306 = F_506 ( V_1199 ) ;
goto V_1205;
}
}
V_306 = V_2 -> V_451 . V_1206 ( V_16 , V_38 , V_114 , V_304 , V_1199 ,
V_1198 ) ;
if ( V_306 )
goto V_1205;
F_728 ( & V_495 -> V_1147 , V_1199 ) ;
}
if ( V_1199 )
F_790 ( V_1199 ) ;
V_495 -> V_1196 = F_775 ( V_38 ) ;
V_495 -> V_1194 = true ;
F_791 ( F_195 ( V_495 -> V_1146 ) , V_304 ,
F_219 ( V_113 ) -> V_381 ) ;
F_4 ( & V_16 -> V_307 ) ;
F_792 ( V_16 ,
F_219 ( V_113 ) -> V_381 ) ;
F_793 ( V_37 -> V_170 , V_304 ) ;
return 0 ;
V_1205:
F_203 ( V_114 , V_38 -> V_113 -> V_36 ) ;
V_1204:
if ( ! F_794 ( V_1199 ) )
F_795 ( V_1199 ) ;
F_730 ( & V_37 -> V_493 ) ;
F_4 ( & V_16 -> V_307 ) ;
V_1202:
V_38 -> V_113 -> V_114 = V_1146 ;
F_215 ( V_38 -> V_113 ) ;
F_693 ( & V_304 -> V_40 ) ;
F_216 ( V_495 -> V_1146 ) ;
F_282 ( & V_16 -> V_456 ) ;
V_37 -> V_457 = NULL ;
F_283 ( & V_16 -> V_456 ) ;
F_104 ( V_38 ) ;
V_1201:
F_221 ( V_495 ) ;
if ( V_306 == - V_1207 ) {
struct V_45 * V_36 ;
struct V_279 * V_280 ;
V_1200:
V_36 = F_705 ( V_16 ) ;
if ( ! V_36 )
return - V_742 ;
V_36 -> V_1120 = F_796 ( V_38 ) ;
V_478:
V_280 = F_697 ( V_36 , V_113 ) ;
V_306 = F_492 ( V_280 ) ;
if ( ! V_306 ) {
F_700 ( V_280 , V_114 ) ;
V_306 = F_699 ( V_280 , V_38 ) ;
if ( ! V_306 )
V_306 = F_710 ( V_36 ) ;
}
if ( V_306 == - V_310 ) {
F_712 ( V_36 -> V_1120 ) ;
F_797 ( V_36 ) ;
goto V_478;
}
if ( V_306 )
F_711 ( V_36 ) ;
if ( V_306 == 0 && V_496 ) {
F_282 ( & V_16 -> V_456 ) ;
F_316 ( V_16 , V_119 , V_496 ) ;
F_283 ( & V_16 -> V_456 ) ;
}
}
return V_306 ;
}
static bool F_798 ( struct V_302 * V_170 ,
struct V_279 * V_36 )
{
struct V_359 * V_1208 = F_220 ( V_36 ) ;
struct V_359 * V_1209 = F_220 ( V_170 -> V_36 ) ;
if ( V_1208 -> V_362 != V_1209 -> V_362 )
return true ;
if ( ! V_1209 -> V_40 . V_114 || ! V_1208 -> V_40 . V_114 )
return false ;
if ( V_1209 -> V_40 . V_114 -> V_294 [ 0 ] != V_1208 -> V_40 . V_114 -> V_294 [ 0 ] ||
V_1209 -> V_40 . V_288 != V_1208 -> V_40 . V_288 ||
F_257 ( & V_1208 -> V_373 ) != F_257 ( & V_1209 -> V_373 ) ||
F_258 ( & V_1208 -> V_373 ) != F_258 ( & V_1209 -> V_373 ) ||
F_257 ( & V_1208 -> V_377 ) != F_257 ( & V_1209 -> V_377 ) ||
F_258 ( & V_1208 -> V_377 ) != F_258 ( & V_1209 -> V_377 ) )
return true ;
return false ;
}
static bool F_799 ( struct V_359 * V_36 )
{
int V_367 = F_257 ( & V_36 -> V_373 ) >> 16 ;
int V_368 = F_258 ( & V_36 -> V_373 ) >> 16 ;
int V_439 = F_257 ( & V_36 -> V_377 ) ;
int V_440 = F_258 ( & V_36 -> V_377 ) ;
return ( V_367 != V_439 || V_368 != V_440 ) ;
}
int F_800 ( struct V_35 * V_44 ,
struct V_279 * V_280 )
{
struct V_43 * V_212 = F_273 ( V_44 ) ;
struct V_111 * V_38 = V_44 -> V_38 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_302 * V_170 = V_280 -> V_170 ;
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_359 * V_1210 =
F_220 ( V_170 -> V_36 ) ;
int V_987 = V_37 -> V_40 . V_40 . V_241 , V_306 ;
bool V_1211 = F_19 ( V_44 ) ;
bool V_1212 = V_38 -> V_36 -> V_112 ;
bool V_1213 = V_44 -> V_112 ;
bool V_1214 , V_1215 , V_362 , V_1216 ;
struct V_278 * V_114 = V_280 -> V_114 ;
if ( V_44 && F_60 ( V_16 ) -> V_127 >= 9 &&
V_170 -> type != V_1217 ) {
V_306 = F_366 (
F_273 ( V_44 ) ,
F_220 ( V_280 ) ) ;
if ( V_306 )
return V_306 ;
}
V_1216 = V_1210 -> V_362 ;
V_362 = F_220 ( V_280 ) -> V_362 ;
if ( ! V_1212 && F_9 ( V_1216 ) )
V_1216 = false ;
if ( ! V_1213 )
F_220 ( V_280 ) -> V_362 = V_362 = false ;
if ( ! V_1216 && ! V_362 )
return 0 ;
if ( V_114 != V_1210 -> V_40 . V_114 )
V_212 -> V_1218 = true ;
V_1214 = V_1216 && ( ! V_362 || V_1211 ) ;
V_1215 = V_362 && ( ! V_1216 || V_1211 ) ;
F_801 ( L_197 , V_987 ,
V_170 -> V_40 . V_241 , V_114 ? V_114 -> V_40 . V_241 : - 1 ) ;
F_801 ( L_198 ,
V_170 -> V_40 . V_241 , V_1216 , V_362 ,
V_1214 , V_1215 , V_1211 ) ;
if ( V_1215 || V_1214 ) {
V_212 -> V_592 = true ;
if ( V_170 -> type != V_1217 )
V_212 -> V_600 = true ;
} else if ( F_798 ( V_170 , V_280 ) ) {
V_212 -> V_592 = true ;
}
if ( V_362 || V_1216 )
V_37 -> V_589 . V_590 |=
F_219 ( V_170 ) -> V_381 ;
switch ( V_170 -> type ) {
case V_1219 :
V_37 -> V_589 . V_594 = V_1215 ;
V_37 -> V_589 . V_593 = true ;
break;
case V_1217 :
break;
case V_1220 :
if ( F_297 ( V_16 ) &&
F_799 ( F_220 ( V_280 ) ) &&
! F_799 ( V_1210 ) )
V_212 -> V_1221 = true ;
break;
}
return 0 ;
}
static bool F_802 ( const struct V_41 * V_1150 ,
const struct V_41 * V_1151 )
{
return V_1150 == V_1151 || ( V_1150 -> V_1222 & ( 1 << V_1151 -> type ) &&
V_1151 -> V_1222 & ( 1 << V_1150 -> type ) ) ;
}
static bool F_803 ( struct V_45 * V_36 ,
struct V_37 * V_38 ,
struct V_41 * V_42 )
{
struct V_41 * V_1223 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_50 ;
F_24 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != & V_38 -> V_40 )
continue;
V_1223 =
F_25 ( V_49 -> V_52 ) ;
if ( ! F_802 ( V_42 , V_1223 ) )
return false ;
}
return true ;
}
static bool F_804 ( struct V_45 * V_36 ,
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
if ( ! F_803 ( V_36 , V_38 , V_42 ) )
return false ;
}
return true ;
}
static int F_805 ( struct V_111 * V_38 ,
struct V_35 * V_44 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_43 * V_212 =
F_273 ( V_44 ) ;
struct V_45 * V_36 = V_44 -> V_36 ;
int V_306 ;
bool V_1211 = F_19 ( V_44 ) ;
if ( V_1211 && ! F_804 ( V_36 , V_37 ) ) {
F_153 ( L_199 ) ;
return - V_559 ;
}
if ( V_1211 && ! V_44 -> V_112 )
V_212 -> V_592 = true ;
if ( V_1211 && V_44 -> V_243 &&
V_2 -> V_451 . V_1224 &&
! F_9 ( V_212 -> V_134 != V_955 ) ) {
V_306 = V_2 -> V_451 . V_1224 ( V_37 ,
V_212 ) ;
if ( V_306 )
return V_306 ;
}
V_306 = 0 ;
if ( V_2 -> V_451 . V_1225 ) {
V_306 = V_2 -> V_451 . V_1225 ( V_37 , V_36 ) ;
if ( V_306 )
return V_306 ;
}
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
if ( V_1211 )
V_306 = F_365 ( V_212 ) ;
if ( ! V_306 )
V_306 = F_806 ( V_16 , V_37 ,
V_212 ) ;
}
return V_306 ;
}
static void F_807 ( struct V_15 * V_16 )
{
struct V_740 * V_47 ;
F_808 (dev, connector) {
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
F_809 ( struct V_740 * V_47 ,
struct V_43 * V_212 )
{
int V_1006 = V_212 -> V_751 ;
F_153 ( L_200 ,
V_47 -> V_40 . V_40 . V_241 ,
V_47 -> V_40 . V_8 ) ;
if ( V_47 -> V_40 . V_1226 . V_533 &&
V_47 -> V_40 . V_1226 . V_533 * 3 < V_1006 ) {
F_153 ( L_201 ,
V_1006 , V_47 -> V_40 . V_1226 . V_533 * 3 ) ;
V_212 -> V_751 = V_47 -> V_40 . V_1226 . V_533 * 3 ;
}
if ( V_47 -> V_40 . V_1226 . V_533 == 0 ) {
int type = V_47 -> V_40 . V_1227 ;
int V_1228 = 24 ;
if ( type == V_1229 ||
type == V_1230 )
V_1228 = 18 ;
if ( V_1006 > V_1228 ) {
F_153 ( L_202 ,
V_1006 , V_1228 ) ;
V_212 -> V_751 = V_1228 ;
}
}
}
static int
F_810 ( struct V_37 * V_38 ,
struct V_43 * V_212 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_45 * V_36 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_1006 , V_50 ;
if ( ( F_31 ( V_16 ) || F_13 ( V_16 ) || F_14 ( V_16 ) ) )
V_1006 = 10 * 3 ;
else if ( F_60 ( V_16 ) -> V_127 >= 5 )
V_1006 = 12 * 3 ;
else
V_1006 = 8 * 3 ;
V_212 -> V_751 = V_1006 ;
V_36 = V_212 -> V_40 . V_36 ;
F_24 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != & V_38 -> V_40 )
continue;
F_809 ( F_811 ( V_47 ) ,
V_212 ) ;
}
return V_1006 ;
}
static void F_812 ( const struct V_532 * V_446 )
{
F_153 ( L_203
L_204 ,
V_446 -> V_117 ,
V_446 -> V_561 , V_446 -> V_757 ,
V_446 -> V_913 , V_446 -> V_910 ,
V_446 -> V_562 , V_446 -> V_915 ,
V_446 -> V_916 , V_446 -> V_906 , V_446 -> type , V_446 -> V_354 ) ;
}
static void F_813 ( struct V_37 * V_38 ,
struct V_43 * V_212 ,
const char * V_1231 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_302 * V_170 ;
struct V_358 * V_358 ;
struct V_359 * V_36 ;
struct V_278 * V_114 ;
F_153 ( L_205 , V_38 -> V_40 . V_40 . V_241 ,
V_1231 , V_212 , F_80 ( V_38 -> V_119 ) ) ;
F_153 ( L_206 , F_814 ( V_212 -> V_121 ) ) ;
F_153 ( L_207 ,
V_212 -> V_751 , V_212 -> V_929 ) ;
F_153 ( L_208 ,
V_212 -> V_261 ,
V_212 -> V_473 ,
V_212 -> V_602 . V_822 , V_212 -> V_602 . V_823 ,
V_212 -> V_602 . V_824 , V_212 -> V_602 . V_825 ,
V_212 -> V_602 . V_821 ) ;
F_153 ( L_209 ,
V_212 -> V_531 ,
V_212 -> V_1232 ,
V_212 -> V_840 . V_822 , V_212 -> V_840 . V_823 ,
V_212 -> V_840 . V_824 , V_212 -> V_840 . V_825 ,
V_212 -> V_840 . V_821 ) ;
F_153 ( L_210 ,
V_212 -> V_531 ,
V_212 -> V_1232 ,
V_212 -> V_841 . V_822 ,
V_212 -> V_841 . V_823 ,
V_212 -> V_841 . V_824 ,
V_212 -> V_841 . V_825 ,
V_212 -> V_841 . V_821 ) ;
F_153 ( L_211 ,
V_212 -> V_1233 ,
V_212 -> V_1234 ) ;
F_153 ( L_212 ) ;
F_815 ( & V_212 -> V_40 . V_446 ) ;
F_153 ( L_213 ) ;
F_815 ( & V_212 -> V_40 . V_116 ) ;
F_812 ( & V_212 -> V_40 . V_116 ) ;
F_153 ( L_214 , V_212 -> V_864 ) ;
F_153 ( L_215 ,
V_212 -> V_387 , V_212 -> V_386 ) ;
F_153 ( L_216 ,
V_38 -> V_405 ,
V_212 -> V_404 . V_550 ,
V_212 -> V_404 . V_436 ) ;
F_153 ( L_217 ,
V_212 -> V_612 . V_613 ,
V_212 -> V_612 . V_617 ,
V_212 -> V_612 . V_1235 ) ;
F_153 ( L_218 ,
V_212 -> V_459 . V_566 ,
V_212 -> V_459 . V_297 ,
V_212 -> V_459 . V_180 ? L_219 : L_220 ) ;
F_153 ( L_221 , V_212 -> V_569 ) ;
F_153 ( L_222 , V_212 -> V_264 ) ;
if ( F_30 ( V_16 ) ) {
F_153 ( L_223
L_224
L_225 ,
V_212 -> V_1061 ,
V_212 -> V_213 . V_1236 ,
V_212 -> V_213 . V_1237 ,
V_212 -> V_213 . V_1238 ,
V_212 -> V_213 . V_1239 ,
V_212 -> V_213 . V_1240 ,
V_212 -> V_213 . V_1241 ,
V_212 -> V_213 . V_1242 ,
V_212 -> V_213 . V_1243 ,
V_212 -> V_213 . V_1244 ,
V_212 -> V_213 . V_1245 ,
V_212 -> V_213 . V_1246 ) ;
} else if ( F_436 ( V_16 ) || F_437 ( V_16 ) ) {
F_153 ( L_226
L_227 ,
V_212 -> V_1061 ,
V_212 -> V_213 . V_1069 ,
V_212 -> V_213 . V_1247 ,
V_212 -> V_213 . V_1248 ) ;
} else if ( F_71 ( V_16 ) ) {
F_153 ( L_228 ,
V_212 -> V_1061 ,
V_212 -> V_213 . V_1249 ,
V_212 -> V_213 . V_1250 ) ;
} else {
F_153 ( L_229
L_230 ,
V_212 -> V_213 . V_87 ,
V_212 -> V_213 . V_215 ,
V_212 -> V_213 . V_735 ,
V_212 -> V_213 . V_736 ) ;
}
F_153 ( L_231 ) ;
F_816 (plane, &dev->mode_config.plane_list, head) {
V_358 = F_219 ( V_170 ) ;
if ( V_358 -> V_119 != V_38 -> V_119 )
continue;
V_36 = F_220 ( V_170 -> V_36 ) ;
V_114 = V_36 -> V_40 . V_114 ;
if ( ! V_114 ) {
F_153 ( L_232
L_233 ,
V_170 -> type == V_1217 ? L_234 : L_235 ,
V_170 -> V_40 . V_241 , V_358 -> V_119 ,
( V_38 -> V_40 . V_113 == V_170 ) ? 0 : V_358 -> V_170 + 1 ,
F_224 ( V_170 ) , V_36 -> V_436 ) ;
continue;
}
F_153 ( L_236 ,
V_170 -> type == V_1217 ? L_234 : L_235 ,
V_170 -> V_40 . V_241 , V_358 -> V_119 ,
V_38 -> V_40 . V_113 == V_170 ? 0 : V_358 -> V_170 + 1 ,
F_224 ( V_170 ) ) ;
F_153 ( L_237 ,
V_114 -> V_40 . V_241 , V_114 -> V_353 , V_114 -> V_273 , V_114 -> V_274 ) ;
F_153 ( L_238 ,
V_36 -> V_436 ,
V_36 -> V_373 . V_374 >> 16 , V_36 -> V_373 . y1 >> 16 ,
F_257 ( & V_36 -> V_373 ) >> 16 ,
F_258 ( & V_36 -> V_373 ) >> 16 ,
V_36 -> V_377 . V_374 , V_36 -> V_377 . y1 ,
F_257 ( & V_36 -> V_377 ) , F_258 ( & V_36 -> V_377 ) ) ;
}
}
static bool F_817 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_46 * V_47 ;
unsigned int V_1251 = 0 ;
F_818 (connector, dev) {
struct V_48 * V_49 ;
struct V_41 * V_42 ;
V_49 = F_819 ( V_36 , V_47 ) ;
if ( ! V_49 )
V_49 = V_47 -> V_36 ;
if ( ! V_49 -> V_52 )
continue;
V_42 = F_25 ( V_49 -> V_52 ) ;
F_9 ( ! V_49 -> V_38 ) ;
switch ( V_42 -> type ) {
unsigned int V_229 ;
case V_630 :
if ( F_9 ( ! F_71 ( V_16 ) ) )
break;
case V_524 :
case V_63 :
case V_525 :
V_229 = 1 << F_350 ( & V_42 -> V_40 ) -> V_217 ;
if ( V_1251 & V_229 )
return false ;
V_1251 |= V_229 ;
default:
break;
}
}
return true ;
}
static void
F_820 ( struct V_43 * V_44 )
{
struct V_35 V_1252 ;
struct V_403 V_404 ;
struct V_137 V_213 ;
enum V_542 V_134 ;
T_2 V_1061 ;
bool V_637 ;
V_1252 = V_44 -> V_40 ;
V_404 = V_44 -> V_404 ;
V_134 = V_44 -> V_134 ;
V_213 = V_44 -> V_213 ;
V_1061 = V_44 -> V_1061 ;
V_637 = V_44 -> V_459 . V_637 ;
memset ( V_44 , 0 , sizeof *V_44 ) ;
V_44 -> V_40 = V_1252 ;
V_44 -> V_404 = V_404 ;
V_44 -> V_134 = V_134 ;
V_44 -> V_213 = V_213 ;
V_44 -> V_1061 = V_1061 ;
V_44 -> V_459 . V_637 = V_637 ;
}
static int
F_821 ( struct V_111 * V_38 ,
struct V_43 * V_212 )
{
struct V_45 * V_36 = V_212 -> V_40 . V_36 ;
struct V_41 * V_42 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_1253 , V_306 = - V_559 ;
int V_50 ;
bool V_478 = true ;
F_820 ( V_212 ) ;
V_212 -> V_121 =
(enum V_118 ) F_50 ( V_38 ) -> V_119 ;
if ( ! ( V_212 -> V_40 . V_116 . V_354 &
( V_537 | V_1254 ) ) )
V_212 -> V_40 . V_116 . V_354 |= V_1254 ;
if ( ! ( V_212 -> V_40 . V_116 . V_354 &
( V_539 | V_1255 ) ) )
V_212 -> V_40 . V_116 . V_354 |= V_1255 ;
V_1253 = F_810 ( F_50 ( V_38 ) ,
V_212 ) ;
if ( V_1253 < 0 )
goto V_808;
F_698 ( & V_212 -> V_40 . V_446 ,
& V_212 -> V_387 ,
& V_212 -> V_386 ) ;
V_1256:
V_212 -> V_864 = 0 ;
V_212 -> V_606 = 1 ;
F_822 ( & V_212 -> V_40 . V_116 ,
V_1257 ) ;
F_24 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != V_38 )
continue;
V_42 = F_25 ( V_49 -> V_52 ) ;
if ( ! ( V_42 -> V_1258 ( V_42 , V_212 ) ) ) {
F_153 ( L_239 ) ;
goto V_808;
}
}
if ( ! V_212 -> V_864 )
V_212 -> V_864 = V_212 -> V_40 . V_116 . V_117
* V_212 -> V_606 ;
V_306 = F_517 ( F_50 ( V_38 ) , V_212 ) ;
if ( V_306 < 0 ) {
F_153 ( L_240 ) ;
goto V_808;
}
if ( V_306 == V_753 ) {
if ( F_6 ( ! V_478 , L_241 ) ) {
V_306 = - V_559 ;
goto V_808;
}
F_153 ( L_242 ) ;
V_478 = false ;
goto V_1256;
}
V_212 -> V_929 = V_212 -> V_751 == 6 * 3 ;
F_153 ( L_243 ,
V_1253 , V_212 -> V_751 , V_212 -> V_929 ) ;
V_808:
return V_306 ;
}
static void
F_823 ( struct V_45 * V_36 )
{
struct V_111 * V_38 ;
struct V_35 * V_44 ;
int V_50 ;
F_471 (state, crtc, crtc_state, i) {
F_50 ( V_38 ) -> V_115 = F_273 ( V_38 -> V_36 ) ;
if ( V_38 -> V_36 -> V_112 )
V_38 -> V_1259 = V_38 -> V_36 -> V_116 ;
else
V_38 -> V_1259 . V_117 = 0 ;
if ( F_392 ( V_36 , V_38 -> V_113 ) ) {
struct V_279 * V_280 = V_38 -> V_113 -> V_36 ;
V_38 -> V_113 -> V_114 = V_280 -> V_114 ;
V_38 -> V_313 = V_280 -> V_365 >> 16 ;
V_38 -> V_314 = V_280 -> V_366 >> 16 ;
}
}
}
static bool F_824 ( int V_1260 , int V_1261 )
{
int V_1262 ;
if ( V_1260 == V_1261 )
return true ;
if ( ! V_1260 || ! V_1261 )
return false ;
V_1262 = abs ( V_1260 - V_1261 ) ;
if ( ( ( ( ( V_1262 + V_1260 + V_1261 ) * 100 ) ) / ( V_1260 + V_1261 ) ) < 105 )
return true ;
return false ;
}
static bool
F_825 ( unsigned int V_79 , unsigned int V_84 ,
unsigned int V_80 , unsigned int V_1263 ,
bool V_1264 )
{
if ( V_79 == V_80 && V_84 == V_1263 )
return true ;
if ( V_1264 || ! V_79 || ! V_84 || ! V_80 || ! V_1263 )
return false ;
F_826 ( V_812 > V_109 ) ;
if ( V_84 > V_1263 ) {
while ( V_84 > V_1263 ) {
V_80 <<= 1 ;
V_1263 <<= 1 ;
}
} else if ( V_84 < V_1263 ) {
while ( V_84 < V_1263 ) {
V_79 <<= 1 ;
V_84 <<= 1 ;
}
}
if ( V_84 != V_1263 )
return false ;
return F_824 ( V_79 , V_80 ) ;
}
static bool
F_827 ( const struct V_819 * V_820 ,
struct V_819 * V_837 ,
bool V_1265 )
{
if ( V_820 -> V_821 == V_837 -> V_821 &&
F_825 ( V_820 -> V_822 , V_820 -> V_823 ,
V_837 -> V_822 , V_837 -> V_823 , ! V_1265 ) &&
F_825 ( V_820 -> V_824 , V_820 -> V_825 ,
V_837 -> V_824 , V_837 -> V_825 , ! V_1265 ) ) {
if ( V_1265 )
* V_837 = * V_820 ;
return true ;
}
return false ;
}
static bool
F_828 ( struct V_15 * V_16 ,
struct V_43 * V_1266 ,
struct V_43 * V_212 ,
bool V_1265 )
{
bool V_306 = true ;
#define F_829 ( T_10 , ... ) \
do { \
if (!adjust) \
DRM_ERROR(fmt, ##__VA_ARGS__); \
else \
DRM_DEBUG_KMS(fmt, ##__VA_ARGS__); \
} while (0)
#define F_830 ( V_8 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_831 ( V_8 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_832 ( V_8 ) \
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
#define F_833 ( V_8 , T_11 ) \
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
#define F_834 ( V_8 , T_11 ) \
if ((current_config->name != pipe_config->name) && \
(current_config->alt_name != pipe_config->name)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i or %i, found %i)\n", \
current_config->name, \
current_config->alt_name, \
pipe_config->name); \
ret = false; \
}
#define F_835 ( V_8 , V_636 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
ret = false; \
}
#define F_836 ( V_8 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_837 ( T_12 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_831 ( V_121 ) ;
F_831 ( V_261 ) ;
F_831 ( V_473 ) ;
F_832 ( V_602 ) ;
F_831 ( V_531 ) ;
F_831 ( V_1232 ) ;
if ( F_60 ( V_16 ) -> V_127 < 8 ) {
F_832 ( V_840 ) ;
if ( V_1266 -> V_838 )
F_832 ( V_841 ) ;
} else
F_833 ( V_840 , V_841 ) ;
F_831 ( V_260 ) ;
F_831 ( V_40 . V_116 . V_561 ) ;
F_831 ( V_40 . V_116 . V_910 ) ;
F_831 ( V_40 . V_116 . V_911 ) ;
F_831 ( V_40 . V_116 . V_912 ) ;
F_831 ( V_40 . V_116 . V_757 ) ;
F_831 ( V_40 . V_116 . V_913 ) ;
F_831 ( V_40 . V_116 . V_562 ) ;
F_831 ( V_40 . V_116 . V_906 ) ;
F_831 ( V_40 . V_116 . V_914 ) ;
F_831 ( V_40 . V_116 . V_907 ) ;
F_831 ( V_40 . V_116 . V_915 ) ;
F_831 ( V_40 . V_116 . V_916 ) ;
F_831 ( V_606 ) ;
F_831 ( V_1267 ) ;
if ( ( F_60 ( V_16 ) -> V_127 < 8 && ! F_240 ( V_16 ) ) ||
F_13 ( V_16 ) || F_14 ( V_16 ) )
F_831 ( V_938 ) ;
F_831 ( V_1234 ) ;
F_831 ( V_1233 ) ;
F_835 ( V_40 . V_116 . V_354 ,
V_909 ) ;
if ( ! F_837 ( V_1268 ) ) {
F_835 ( V_40 . V_116 . V_354 ,
V_537 ) ;
F_835 ( V_40 . V_116 . V_354 ,
V_1254 ) ;
F_835 ( V_40 . V_116 . V_354 ,
V_539 ) ;
F_835 ( V_40 . V_116 . V_354 ,
V_1255 ) ;
}
F_830 ( V_612 . V_613 ) ;
if ( F_60 ( V_16 ) -> V_127 < 4 )
F_831 ( V_612 . V_617 ) ;
F_830 ( V_612 . V_1235 ) ;
if ( ! V_1265 ) {
F_831 ( V_387 ) ;
F_831 ( V_386 ) ;
F_831 ( V_459 . V_180 ) ;
if ( V_1266 -> V_459 . V_180 ) {
F_830 ( V_459 . V_566 ) ;
F_830 ( V_459 . V_297 ) ;
}
F_831 ( V_404 . V_436 ) ;
}
if ( F_240 ( V_16 ) )
F_831 ( V_569 ) ;
F_831 ( V_264 ) ;
F_830 ( V_1061 ) ;
F_831 ( V_134 ) ;
F_830 ( V_213 . V_87 ) ;
F_830 ( V_213 . V_215 ) ;
F_830 ( V_213 . V_735 ) ;
F_830 ( V_213 . V_736 ) ;
F_830 ( V_213 . V_1249 ) ;
F_830 ( V_213 . V_1250 ) ;
F_830 ( V_213 . V_1069 ) ;
F_830 ( V_213 . V_1247 ) ;
F_830 ( V_213 . V_1248 ) ;
if ( F_31 ( V_16 ) || F_60 ( V_16 ) -> V_127 >= 5 )
F_831 ( V_751 ) ;
F_836 ( V_40 . V_116 . V_117 ) ;
F_836 ( V_864 ) ;
#undef F_830
#undef F_831
#undef F_834
#undef F_835
#undef F_836
#undef F_837
#undef F_829
return V_306 ;
}
static void F_838 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_1269 V_1270 , * V_1271 ;
struct V_37 * V_37 ;
int V_170 ;
if ( F_60 ( V_16 ) -> V_127 < 9 )
return;
F_839 ( V_2 , & V_1270 ) ;
V_1271 = & V_2 -> V_585 . V_1272 . V_1273 ;
F_140 (dev, intel_crtc) {
struct V_1274 * V_1275 , * V_1276 ;
const enum V_119 V_119 = V_37 -> V_119 ;
if ( ! V_37 -> V_112 )
continue;
F_840 (dev_priv, pipe, plane) {
V_1275 = & V_1270 . V_170 [ V_119 ] [ V_170 ] ;
V_1276 = & V_1271 -> V_170 [ V_119 ] [ V_170 ] ;
if ( F_841 ( V_1275 , V_1276 ) )
continue;
F_132 ( L_244
L_245 ,
F_80 ( V_119 ) , V_170 + 1 ,
V_1276 -> V_400 , V_1276 -> V_1106 ,
V_1275 -> V_400 , V_1275 -> V_1106 ) ;
}
V_1275 = & V_1270 . V_170 [ V_119 ] [ V_1277 ] ;
V_1276 = & V_1271 -> V_170 [ V_119 ] [ V_1277 ] ;
if ( F_841 ( V_1275 , V_1276 ) )
continue;
F_132 ( L_246
L_245 ,
F_80 ( V_119 ) ,
V_1276 -> V_400 , V_1276 -> V_1106 ,
V_1275 -> V_400 , V_1275 -> V_1106 ) ;
}
}
static void
F_842 ( struct V_15 * V_16 ,
struct V_45 * V_595 )
{
struct V_48 * V_1278 ;
struct V_46 * V_47 ;
int V_50 ;
F_24 (old_state, connector, old_conn_state, i) {
struct V_635 * V_42 = V_47 -> V_42 ;
struct V_48 * V_36 = V_47 -> V_36 ;
F_495 ( F_811 ( V_47 ) ) ;
F_65 ( V_36 -> V_52 != V_42 ,
L_247 ) ;
}
}
static void
F_843 ( struct V_15 * V_16 )
{
struct V_41 * V_42 ;
struct V_740 * V_47 ;
F_605 (dev, encoder) {
bool V_180 = false ;
enum V_119 V_119 ;
F_153 ( L_248 ,
V_42 -> V_40 . V_40 . V_241 ,
V_42 -> V_40 . V_8 ) ;
F_808 (dev, connector) {
if ( V_47 -> V_40 . V_36 -> V_52 != & V_42 -> V_40 )
continue;
V_180 = true ;
F_65 ( V_47 -> V_40 . V_36 -> V_38 !=
V_42 -> V_40 . V_38 ,
L_249 ) ;
}
F_65 ( ! ! V_42 -> V_40 . V_38 != V_180 ,
L_250
L_251 ,
! ! V_42 -> V_40 . V_38 , V_180 ) ;
if ( ! V_42 -> V_40 . V_38 ) {
bool V_112 ;
V_112 = V_42 -> V_139 ( V_42 , & V_119 ) ;
F_65 ( V_112 ,
L_252 ,
F_80 ( V_119 ) ) ;
}
}
}
static void
F_844 ( struct V_15 * V_16 , struct V_45 * V_595 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_41 * V_42 ;
struct V_35 * V_458 ;
struct V_111 * V_38 ;
int V_50 ;
F_471 (old_state, crtc, old_crtc_state, i) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_43 * V_212 , * V_1279 ;
bool V_112 ;
if ( ! F_19 ( V_38 -> V_36 ) &&
! F_273 ( V_38 -> V_36 ) -> V_1280 )
continue;
F_845 ( V_38 , V_458 ) ;
V_212 = F_273 ( V_458 ) ;
memset ( V_212 , 0 , sizeof( * V_212 ) ) ;
V_212 -> V_40 . V_38 = V_38 ;
V_212 -> V_40 . V_36 = V_595 ;
F_153 ( L_253 ,
V_38 -> V_40 . V_241 ) ;
V_112 = V_2 -> V_451 . V_1281 ( V_37 ,
V_212 ) ;
if ( ( V_37 -> V_119 == V_147 && V_2 -> V_166 & V_167 ) ||
( V_37 -> V_119 == V_156 && V_2 -> V_166 & V_168 ) )
V_112 = V_38 -> V_36 -> V_112 ;
F_65 ( V_38 -> V_36 -> V_112 != V_112 ,
L_254
L_251 , V_38 -> V_36 -> V_112 , V_112 ) ;
F_65 ( V_37 -> V_112 != V_38 -> V_36 -> V_112 ,
L_255
L_251 , V_38 -> V_36 -> V_112 , V_37 -> V_112 ) ;
F_22 (dev, crtc, encoder) {
enum V_119 V_119 ;
V_112 = V_42 -> V_139 ( V_42 , & V_119 ) ;
F_65 ( V_112 != V_38 -> V_36 -> V_112 ,
L_256 ,
V_42 -> V_40 . V_40 . V_241 , V_112 , V_38 -> V_36 -> V_112 ) ;
F_65 ( V_112 && V_37 -> V_119 != V_119 ,
L_257 ,
F_80 ( V_119 ) ) ;
if ( V_112 )
V_42 -> V_1282 ( V_42 , V_212 ) ;
}
if ( ! V_38 -> V_36 -> V_112 )
continue;
V_1279 = F_273 ( V_38 -> V_36 ) ;
if ( ! F_828 ( V_16 , V_1279 ,
V_212 , false ) ) {
F_65 ( 1 , L_258 ) ;
F_813 ( V_37 , V_212 ,
L_259 ) ;
F_813 ( V_37 , V_1279 ,
L_260 ) ;
}
}
}
static void
F_846 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_38 ;
struct V_137 V_213 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_543 ; V_50 ++ ) {
struct V_133 * V_136 = & V_2 -> V_135 [ V_50 ] ;
int V_1283 = 0 , V_723 = 0 ;
bool V_112 ;
memset ( & V_213 , 0 , sizeof( V_213 ) ) ;
F_153 ( L_261 , V_136 -> V_8 ) ;
V_112 = V_136 -> V_139 ( V_2 , V_136 , & V_213 ) ;
F_65 ( V_136 -> V_112 > F_847 ( V_136 -> V_115 . V_238 ) ,
L_262 ,
V_136 -> V_112 , F_847 ( V_136 -> V_115 . V_238 ) ) ;
F_65 ( V_136 -> V_112 && ! V_136 -> V_239 ,
L_263 ) ;
F_65 ( V_136 -> V_239 && ! V_136 -> V_112 ,
L_264 ) ;
F_65 ( V_136 -> V_239 != V_112 ,
L_265 ,
V_136 -> V_239 , V_112 ) ;
F_140 (dev, crtc) {
if ( V_38 -> V_40 . V_36 -> V_243 && F_68 ( V_38 ) == V_136 )
V_1283 ++ ;
if ( V_38 -> V_112 && F_68 ( V_38 ) == V_136 )
V_723 ++ ;
}
F_65 ( V_136 -> V_112 != V_723 ,
L_266 ,
V_136 -> V_112 , V_723 ) ;
F_65 ( F_847 ( V_136 -> V_115 . V_238 ) != V_1283 ,
L_267 ,
F_847 ( V_136 -> V_115 . V_238 ) , V_1283 ) ;
F_65 ( V_136 -> V_239 && memcmp ( & V_136 -> V_115 . V_138 , & V_213 ,
sizeof( V_213 ) ) ,
L_268 ) ;
}
}
static void
F_848 ( struct V_15 * V_16 ,
struct V_45 * V_595 )
{
F_838 ( V_16 ) ;
F_842 ( V_16 , V_595 ) ;
F_843 ( V_16 ) ;
F_844 ( V_16 , V_595 ) ;
F_846 ( V_16 ) ;
}
void F_849 ( const struct V_43 * V_212 ,
int V_1284 )
{
F_6 ( ! F_824 ( V_212 -> V_40 . V_116 . V_117 , V_1284 ) ,
L_269 ,
V_212 -> V_40 . V_116 . V_117 , V_1284 ) ;
}
static void F_850 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
if ( F_33 ( V_16 ) ) {
const struct V_532 * V_116 = & V_38 -> V_115 -> V_40 . V_116 ;
int V_922 ;
V_922 = V_116 -> V_906 ;
if ( V_116 -> V_354 & V_909 )
V_922 /= 2 ;
V_38 -> V_263 = V_922 - 1 ;
} else if ( F_71 ( V_16 ) &&
F_21 ( V_38 , V_63 ) ) {
V_38 -> V_263 = 2 ;
} else
V_38 -> V_263 = 1 ;
}
static void F_851 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_1 * V_2 = F_185 ( V_16 ) ;
struct V_541 * V_134 = NULL ;
struct V_111 * V_38 ;
struct V_35 * V_44 ;
int V_50 ;
if ( ! V_2 -> V_451 . V_1224 )
return;
F_471 (state, crtc, crtc_state, i) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_1285 = F_273 ( V_38 -> V_36 ) -> V_134 ;
if ( ! F_19 ( V_44 ) )
continue;
F_273 ( V_44 ) -> V_134 = V_955 ;
if ( V_1285 == V_955 )
continue;
if ( ! V_134 )
V_134 = F_359 ( V_36 ) ;
V_134 [ V_1285 ] . V_238 &= ~ ( 1 << V_37 -> V_119 ) ;
}
}
static int F_852 ( struct V_45 * V_36 )
{
struct V_35 * V_44 ;
struct V_37 * V_37 ;
struct V_111 * V_38 ;
struct V_43 * V_1286 = NULL ;
struct V_43 * V_745 = NULL ;
enum V_119 V_1287 = V_608 , V_1288 = V_608 ;
int V_50 ;
F_471 (state, crtc, crtc_state, i) {
V_37 = F_50 ( V_38 ) ;
if ( ! V_44 -> V_112 || ! F_19 ( V_44 ) )
continue;
if ( V_1286 ) {
V_745 = F_273 ( V_44 ) ;
break;
} else {
V_1286 = F_273 ( V_44 ) ;
V_1287 = V_37 -> V_119 ;
}
}
if ( ! V_1286 )
return 0 ;
F_140 (state->dev, intel_crtc) {
struct V_43 * V_212 ;
V_212 = F_504 ( V_36 , V_37 ) ;
if ( F_505 ( V_212 ) )
return F_506 ( V_212 ) ;
V_212 -> V_604 = V_608 ;
if ( ! V_212 -> V_40 . V_112 ||
F_19 ( & V_212 -> V_40 ) )
continue;
if ( V_1288 != V_608 )
return 0 ;
V_1288 = V_37 -> V_119 ;
}
if ( V_1288 != V_608 )
V_1286 -> V_604 = V_1288 ;
else if ( V_745 )
V_745 -> V_604 = V_1287 ;
return 0 ;
}
static int F_853 ( struct V_45 * V_36 )
{
struct V_111 * V_38 ;
struct V_35 * V_44 ;
int V_306 = 0 ;
F_222 (state->dev, crtc) {
V_44 = F_709 ( V_36 , V_38 ) ;
if ( F_505 ( V_44 ) )
return F_506 ( V_44 ) ;
if ( ! V_44 -> V_112 || F_19 ( V_44 ) )
continue;
V_44 -> V_1211 = true ;
V_306 = F_854 ( V_36 , V_38 ) ;
if ( V_306 )
break;
V_306 = F_855 ( V_36 , V_38 ) ;
if ( V_306 )
break;
}
return V_306 ;
}
static int F_856 ( struct V_45 * V_36 )
{
struct V_719 * V_360 = F_362 ( V_36 ) ;
struct V_1 * V_2 = V_36 -> V_16 -> V_17 ;
struct V_111 * V_38 ;
struct V_35 * V_44 ;
int V_306 = 0 , V_50 ;
if ( ! F_817 ( V_36 ) ) {
F_153 ( L_270 ) ;
return - V_559 ;
}
V_360 -> V_597 = true ;
V_360 -> V_723 = V_2 -> V_723 ;
F_471 (state, crtc, crtc_state, i) {
if ( V_44 -> V_112 )
V_360 -> V_723 |= 1 << V_50 ;
else
V_360 -> V_723 &= ~ ( 1 << V_50 ) ;
}
if ( V_2 -> V_451 . V_1289 ) {
V_306 = V_2 -> V_451 . V_1289 ( V_36 ) ;
if ( ! V_306 && V_360 -> V_722 != V_2 -> V_651 )
V_306 = F_853 ( V_36 ) ;
if ( V_306 < 0 )
return V_306 ;
F_153 ( L_271 ,
V_360 -> V_704 , V_360 -> V_722 ) ;
} else
F_362 ( V_36 ) -> V_704 = V_2 -> V_1290 ;
F_851 ( V_36 ) ;
if ( F_240 ( V_2 ) )
return F_852 ( V_36 ) ;
return 0 ;
}
static void F_857 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_719 * V_360 = F_362 ( V_36 ) ;
struct V_111 * V_38 ;
struct V_35 * V_1051 ;
struct V_302 * V_170 ;
struct V_279 * V_1291 ;
F_858 (crtc, dev) {
V_1051 = F_859 ( V_36 , V_38 ) ? :
V_38 -> V_36 ;
if ( V_1051 -> V_112 )
V_360 -> V_1292 . V_1293 ++ ;
}
F_860 (plane, dev) {
V_1291 = F_392 ( V_36 , V_170 ) ? :
V_170 -> V_36 ;
if ( ! F_220 ( V_1291 ) -> V_362 )
continue;
V_360 -> V_1292 . V_1294 = true ;
if ( V_1291 -> V_371 != V_1291 -> V_367 >> 16 ||
V_1291 -> V_372 != V_1291 -> V_368 >> 16 )
V_360 -> V_1292 . V_1295 = true ;
}
}
static int F_861 ( struct V_15 * V_16 ,
struct V_45 * V_36 )
{
struct V_1 * V_2 = F_185 ( V_16 ) ;
struct V_719 * V_360 = F_362 ( V_36 ) ;
struct V_111 * V_38 ;
struct V_35 * V_44 ;
int V_306 , V_50 ;
bool V_1296 = false ;
V_306 = F_862 ( V_16 , V_36 ) ;
if ( V_306 )
return V_306 ;
F_471 (state, crtc, crtc_state, i) {
struct V_43 * V_212 =
F_273 ( V_44 ) ;
memset ( & F_50 ( V_38 ) -> V_589 , 0 ,
sizeof( struct V_588 ) ) ;
if ( V_44 -> V_446 . V_1297 != V_38 -> V_36 -> V_446 . V_1297 )
V_44 -> V_1211 = true ;
if ( ! V_44 -> V_243 ) {
if ( F_19 ( V_44 ) )
V_1296 = true ;
continue;
}
if ( ! F_19 ( V_44 ) )
continue;
V_306 = F_854 ( V_36 , V_38 ) ;
if ( V_306 )
return V_306 ;
V_306 = F_821 ( V_38 , V_212 ) ;
if ( V_306 )
return V_306 ;
if ( V_754 . V_1298 &&
F_828 ( V_16 ,
F_273 ( V_38 -> V_36 ) ,
V_212 , true ) ) {
V_44 -> V_1211 = false ;
F_273 ( V_44 ) -> V_1280 = true ;
}
if ( F_19 ( V_44 ) ) {
V_1296 = true ;
V_306 = F_855 ( V_36 , V_38 ) ;
if ( V_306 )
return V_306 ;
}
F_813 ( F_50 ( V_38 ) , V_212 ,
F_19 ( V_44 ) ?
L_272 : L_273 ) ;
}
if ( V_1296 ) {
V_306 = F_856 ( V_36 ) ;
if ( V_306 )
return V_306 ;
} else
V_360 -> V_704 = V_2 -> V_651 ;
V_306 = F_863 ( V_16 , V_36 ) ;
if ( V_306 )
return V_306 ;
F_864 ( V_2 , V_36 ) ;
F_857 ( V_36 ) ;
return 0 ;
}
static int F_865 ( struct V_15 * V_16 ,
struct V_45 * V_36 ,
bool V_1299 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_279 * V_280 ;
struct V_35 * V_44 ;
struct V_302 * V_170 ;
struct V_111 * V_38 ;
int V_50 , V_306 ;
if ( V_1299 ) {
F_153 ( L_274 ) ;
return - V_559 ;
}
F_471 (state, crtc, crtc_state, i) {
if ( V_36 -> V_1300 )
continue;
V_306 = F_320 ( V_38 ) ;
if ( V_306 )
return V_306 ;
if ( F_289 ( & F_50 ( V_38 ) -> V_493 ) >= 2 )
F_785 ( V_2 -> V_498 ) ;
}
V_306 = F_866 ( & V_16 -> V_307 ) ;
if ( V_306 )
return V_306 ;
V_306 = F_867 ( V_16 , V_36 ) ;
if ( ! V_306 && ! V_1299 && ! F_288 ( & V_2 -> V_454 ) ) {
T_1 V_455 ;
V_455 = F_289 ( & V_2 -> V_454 . V_455 ) ;
F_4 ( & V_16 -> V_307 ) ;
F_868 (state, plane, plane_state, i) {
struct V_359 * V_359 =
F_220 ( V_280 ) ;
if ( ! V_359 -> V_1301 )
continue;
V_306 = F_764 ( V_359 -> V_1301 ,
V_455 , true ,
NULL , NULL ) ;
if ( V_306 == - V_1207 )
V_306 = 0 ;
if ( V_306 )
break;
}
if ( ! V_306 )
return 0 ;
F_2 ( & V_16 -> V_307 ) ;
F_869 ( V_16 , V_36 ) ;
}
F_4 ( & V_16 -> V_307 ) ;
return V_306 ;
}
static void F_870 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
unsigned V_238 )
{
unsigned V_1302 [ V_1303 ] ;
enum V_119 V_119 ;
int V_306 ;
if ( ! V_238 )
return;
F_93 (dev_priv, pipe) {
struct V_111 * V_38 = V_2 -> V_120 [ V_119 ] ;
if ( ! ( ( 1 << V_119 ) & V_238 ) )
continue;
V_306 = F_103 ( V_38 ) ;
if ( F_9 ( V_306 != 0 ) ) {
V_238 &= ~ ( 1 << V_119 ) ;
continue;
}
V_1302 [ V_119 ] = F_775 ( V_38 ) ;
}
F_93 (dev_priv, pipe) {
struct V_111 * V_38 = V_2 -> V_120 [ V_119 ] ;
long V_1304 ;
if ( ! ( ( 1 << V_119 ) & V_238 ) )
continue;
V_1304 = F_871 ( V_16 -> V_1305 [ V_119 ] . V_1306 ,
V_1302 [ V_119 ] !=
F_775 ( V_38 ) ,
F_872 ( 50 ) ) ;
F_9 ( ! V_1304 ) ;
F_104 ( V_38 ) ;
}
}
static bool F_873 ( struct V_43 * V_44 )
{
if ( V_44 -> V_1218 )
return true ;
if ( V_44 -> V_592 )
return true ;
if ( V_44 -> V_600 )
return true ;
return false ;
}
static int F_874 ( struct V_15 * V_16 ,
struct V_45 * V_36 ,
bool V_1299 )
{
struct V_719 * V_360 = F_362 ( V_36 ) ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_35 * V_44 ;
struct V_111 * V_38 ;
int V_306 = 0 , V_50 ;
bool V_1307 = V_360 -> V_597 ;
unsigned long V_1308 [ V_1303 ] = {} ;
unsigned V_1309 = 0 ;
V_306 = F_865 ( V_16 , V_36 , V_1299 ) ;
if ( V_306 ) {
F_801 ( L_275 , V_306 ) ;
return V_306 ;
}
F_875 ( V_16 , V_36 ) ;
V_2 -> V_585 . V_115 = F_362 ( V_36 ) -> V_1292 ;
if ( V_360 -> V_597 ) {
memcpy ( V_2 -> V_720 , V_360 -> V_720 ,
sizeof( V_360 -> V_720 ) ) ;
V_2 -> V_723 = V_360 -> V_723 ;
V_2 -> V_1290 = V_360 -> V_704 ;
F_155 ( V_2 , V_1310 ) ;
}
F_471 (state, crtc, crtc_state, i) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
if ( F_19 ( V_38 -> V_36 ) ||
F_273 ( V_38 -> V_36 ) -> V_1280 ) {
V_1307 = true ;
V_1308 [ F_50 ( V_38 ) -> V_119 ] =
F_431 ( V_38 ,
F_273 ( V_38 -> V_36 ) ) ;
}
if ( ! F_19 ( V_38 -> V_36 ) )
continue;
F_391 ( F_273 ( V_44 ) ) ;
if ( V_44 -> V_112 ) {
F_394 ( V_38 , V_44 -> V_363 ) ;
V_2 -> V_451 . V_738 ( V_38 ) ;
V_37 -> V_112 = false ;
F_490 ( V_37 ) ;
F_156 ( V_37 ) ;
F_384 ( V_2 ) ;
F_385 ( V_2 ) ;
if ( ! V_38 -> V_36 -> V_112 )
F_389 ( V_38 ) ;
}
}
F_823 ( V_36 ) ;
if ( V_360 -> V_597 ) {
F_361 ( V_36 ) ;
F_876 ( V_36 -> V_16 , V_36 ) ;
if ( V_2 -> V_451 . V_1311 &&
V_360 -> V_722 != V_2 -> V_651 )
V_2 -> V_451 . V_1311 ( V_36 ) ;
}
F_471 (state, crtc, crtc_state, i) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
bool V_597 = F_19 ( V_38 -> V_36 ) ;
struct V_43 * V_212 =
F_273 ( V_38 -> V_36 ) ;
bool V_1280 = ! V_597 && V_212 -> V_1280 ;
if ( V_597 && V_38 -> V_36 -> V_112 ) {
F_850 ( F_50 ( V_38 ) ) ;
V_2 -> V_451 . V_1312 ( V_38 ) ;
}
if ( ! V_597 )
F_391 ( F_273 ( V_44 ) ) ;
if ( V_38 -> V_36 -> V_112 && V_37 -> V_589 . V_593 )
F_877 ( V_37 ) ;
if ( V_38 -> V_36 -> V_112 &&
( V_38 -> V_36 -> V_1313 || V_1280 ) )
F_878 ( V_44 ) ;
if ( V_212 -> V_40 . V_112 && F_873 ( V_212 ) )
V_1309 |= 1 << V_50 ;
}
if ( ! V_36 -> V_1300 )
F_870 ( V_16 , V_2 , V_1309 ) ;
F_471 (state, crtc, crtc_state, i) {
F_387 ( F_50 ( V_38 ) ) ;
if ( V_1308 [ V_50 ] )
F_433 ( V_2 , V_1308 [ V_50 ] ) ;
}
if ( V_360 -> V_597 )
F_88 ( V_2 , V_1310 ) ;
F_2 ( & V_16 -> V_307 ) ;
F_869 ( V_16 , V_36 ) ;
F_4 ( & V_16 -> V_307 ) ;
if ( V_1307 )
F_848 ( V_16 , V_36 ) ;
F_711 ( V_36 ) ;
F_879 ( V_2 ) ;
return 0 ;
}
void F_880 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_45 * V_36 ;
struct V_35 * V_44 ;
int V_306 ;
V_36 = F_705 ( V_16 ) ;
if ( ! V_36 ) {
F_153 ( L_276 ,
V_38 -> V_40 . V_241 ) ;
return;
}
V_36 -> V_1120 = F_796 ( V_38 ) ;
V_478:
V_44 = F_709 ( V_36 , V_38 ) ;
V_306 = F_492 ( V_44 ) ;
if ( ! V_306 ) {
if ( ! V_44 -> V_112 )
goto V_956;
V_44 -> V_1211 = true ;
V_306 = F_710 ( V_36 ) ;
}
if ( V_306 == - V_310 ) {
F_797 ( V_36 ) ;
F_712 ( V_36 -> V_1120 ) ;
goto V_478;
}
if ( V_306 )
V_956:
F_711 ( V_36 ) ;
}
static bool F_881 ( struct V_1 * V_2 ,
struct V_133 * V_136 ,
struct V_137 * V_138 )
{
T_2 V_10 ;
if ( ! F_87 ( V_2 , V_242 ) )
return false ;
V_10 = F_11 ( F_882 ( V_136 -> V_241 ) ) ;
V_138 -> V_87 = V_10 ;
V_138 -> V_735 = F_11 ( F_883 ( V_136 -> V_241 ) ) ;
V_138 -> V_736 = F_11 ( F_884 ( V_136 -> V_241 ) ) ;
F_88 ( V_2 , V_242 ) ;
return V_10 & V_130 ;
}
static void F_885 ( struct V_1 * V_2 ,
struct V_133 * V_136 )
{
F_129 ( F_883 ( V_136 -> V_241 ) , V_136 -> V_115 . V_138 . V_735 ) ;
F_129 ( F_884 ( V_136 -> V_241 ) , V_136 -> V_115 . V_138 . V_736 ) ;
}
static void F_886 ( struct V_1 * V_2 ,
struct V_133 * V_136 )
{
F_105 ( V_2 ) ;
F_129 ( F_882 ( V_136 -> V_241 ) , V_136 -> V_115 . V_138 . V_87 ) ;
F_130 ( F_882 ( V_136 -> V_241 ) ) ;
F_131 ( 150 ) ;
F_129 ( F_882 ( V_136 -> V_241 ) , V_136 -> V_115 . V_138 . V_87 ) ;
F_130 ( F_882 ( V_136 -> V_241 ) ) ;
F_131 ( 200 ) ;
}
static void F_887 ( struct V_1 * V_2 ,
struct V_133 * V_136 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_37 * V_38 ;
F_140 (dev, crtc) {
if ( F_68 ( V_38 ) == V_136 )
F_108 ( V_2 , V_38 -> V_119 ) ;
}
F_129 ( F_882 ( V_136 -> V_241 ) , 0 ) ;
F_130 ( F_882 ( V_136 -> V_241 ) ) ;
F_131 ( 200 ) ;
}
static void F_888 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
int V_50 ;
V_2 -> V_543 = 2 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_543 ; V_50 ++ ) {
V_2 -> V_135 [ V_50 ] . V_241 = V_50 ;
V_2 -> V_135 [ V_50 ] . V_8 = V_1314 [ V_50 ] ;
V_2 -> V_135 [ V_50 ] . V_240 = F_885 ;
V_2 -> V_135 [ V_50 ] . V_243 = F_886 ;
V_2 -> V_135 [ V_50 ] . V_244 = F_887 ;
V_2 -> V_135 [ V_50 ] . V_139 =
F_881 ;
}
}
static void F_889 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_71 ( V_16 ) )
F_890 ( V_16 ) ;
else if ( F_106 ( V_16 ) || F_107 ( V_16 ) )
F_888 ( V_16 ) ;
else
V_2 -> V_543 = 0 ;
F_142 ( V_2 -> V_543 > V_1315 ) ;
}
int
F_891 ( struct V_302 * V_170 ,
const struct V_279 * V_1316 )
{
struct V_15 * V_16 = V_170 -> V_16 ;
struct V_278 * V_114 = V_1316 -> V_114 ;
struct V_358 * V_358 = F_219 ( V_170 ) ;
struct V_303 * V_304 = F_195 ( V_114 ) ;
struct V_303 * V_1317 = F_195 ( V_170 -> V_36 -> V_114 ) ;
int V_306 = 0 ;
if ( ! V_304 && ! V_1317 )
return 0 ;
if ( V_1317 ) {
struct V_35 * V_44 =
F_859 ( V_1316 -> V_36 , V_170 -> V_36 -> V_38 ) ;
if ( F_19 ( V_44 ) )
V_306 = F_892 ( V_1317 , true ) ;
if ( V_306 && V_306 != - V_1207 )
return V_306 ;
}
if ( V_304 && V_304 -> V_40 . V_1185 ) {
long V_1304 ;
V_1304 = F_766 ( V_304 -> V_40 . V_1185 -> V_1186 ,
false , true ,
V_1192 ) ;
if ( V_1304 == - V_1318 )
return V_1304 ;
F_6 ( V_1304 < 0 , L_277 , V_1304 ) ;
}
if ( ! V_304 ) {
V_306 = 0 ;
} else if ( V_170 -> type == V_1217 &&
F_60 ( V_16 ) -> V_1319 ) {
int V_1320 = F_143 ( V_16 ) ? 16 * 1024 : 256 ;
V_306 = F_893 ( V_304 , V_1320 ) ;
if ( V_306 )
F_153 ( L_278 ) ;
} else {
V_306 = F_194 ( V_170 , V_114 , V_1316 ) ;
}
if ( V_306 == 0 ) {
if ( V_304 ) {
struct V_359 * V_280 =
F_220 ( V_1316 ) ;
F_728 ( & V_280 -> V_1301 ,
V_304 -> V_1187 ) ;
}
F_791 ( V_1317 , V_304 , V_358 -> V_381 ) ;
}
return V_306 ;
}
void
F_894 ( struct V_302 * V_170 ,
const struct V_279 * V_595 )
{
struct V_15 * V_16 = V_170 -> V_16 ;
struct V_358 * V_358 = F_219 ( V_170 ) ;
struct V_359 * V_730 ;
struct V_303 * V_1317 = F_195 ( V_595 -> V_114 ) ;
struct V_303 * V_304 = F_195 ( V_170 -> V_36 -> V_114 ) ;
V_730 = F_220 ( V_595 ) ;
if ( ! V_304 && ! V_1317 )
return;
if ( V_1317 && ( V_170 -> type != V_1217 ||
! F_60 ( V_16 ) -> V_1319 ) )
F_203 ( V_595 -> V_114 , V_595 ) ;
if ( ( V_1317 && ( V_1317 -> V_380 & V_358 -> V_381 ) ) ||
( V_304 && ! ( V_304 -> V_380 & V_358 -> V_381 ) ) )
F_791 ( V_1317 , V_304 , V_358 -> V_381 ) ;
F_728 ( & V_730 -> V_1301 , NULL ) ;
}
int
F_895 ( struct V_37 * V_37 , struct V_43 * V_44 )
{
int V_1321 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_117 , V_704 ;
if ( ! V_37 || ! V_44 -> V_40 . V_243 )
return V_1322 ;
V_16 = V_37 -> V_40 . V_16 ;
V_2 = V_16 -> V_17 ;
V_117 = V_44 -> V_40 . V_116 . V_117 ;
V_704 = F_362 ( V_44 -> V_40 . V_36 ) -> V_704 ;
if ( F_47 ( ! V_117 || V_704 < V_117 ) )
return V_1322 ;
V_1321 = V_90 ( ( 1 << 16 ) * 3 - 1 , ( 1 << 8 ) * ( ( V_704 << 8 ) / V_117 ) ) ;
return V_1321 ;
}
static int
F_896 ( struct V_302 * V_170 ,
struct V_43 * V_44 ,
struct V_359 * V_36 )
{
struct V_111 * V_38 = V_36 -> V_40 . V_38 ;
struct V_278 * V_114 = V_36 -> V_40 . V_114 ;
int V_1323 = V_1322 ;
int V_1321 = V_1322 ;
bool V_1324 = false ;
if ( F_60 ( V_170 -> V_16 ) -> V_127 >= 9 ) {
if ( V_36 -> V_563 . V_354 == V_564 ) {
V_1323 = 1 ;
V_1321 = F_895 ( F_50 ( V_38 ) , V_44 ) ;
}
V_1324 = true ;
}
return F_897 ( V_170 , V_38 , V_114 , & V_36 -> V_373 ,
& V_36 -> V_377 , & V_36 -> V_1325 ,
V_1323 , V_1321 ,
V_1324 , true ,
& V_36 -> V_362 ) ;
}
static void F_898 ( struct V_111 * V_38 ,
struct V_35 * V_458 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_43 * V_730 =
F_273 ( V_458 ) ;
bool V_597 = F_19 ( V_38 -> V_36 ) ;
F_761 ( V_37 ) ;
if ( V_597 )
return;
if ( F_273 ( V_38 -> V_36 ) -> V_1280 )
F_290 ( V_37 , V_730 ) ;
else if ( F_60 ( V_16 ) -> V_127 >= 9 )
F_252 ( V_37 ) ;
}
static void F_899 ( struct V_111 * V_38 ,
struct V_35 * V_458 )
{
struct V_37 * V_37 = F_50 ( V_38 ) ;
F_762 ( V_37 ) ;
}
void F_900 ( struct V_302 * V_170 )
{
struct V_358 * V_358 = F_219 ( V_170 ) ;
F_901 ( V_170 ) ;
F_221 ( V_358 ) ;
}
static struct V_302 * F_902 ( struct V_15 * V_16 ,
int V_119 )
{
struct V_358 * V_113 ;
struct V_359 * V_36 ;
const T_2 * V_1326 ;
unsigned int V_1327 ;
V_113 = F_499 ( sizeof( * V_113 ) , V_743 ) ;
if ( V_113 == NULL )
return NULL ;
V_36 = F_903 ( & V_113 -> V_40 ) ;
if ( ! V_36 ) {
F_221 ( V_113 ) ;
return NULL ;
}
V_113 -> V_40 . V_36 = & V_36 -> V_40 ;
V_113 -> V_1328 = false ;
V_113 -> V_1329 = 1 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
V_113 -> V_1328 = true ;
V_36 -> V_436 = - 1 ;
}
V_113 -> V_119 = V_119 ;
V_113 -> V_170 = V_119 ;
V_113 -> V_381 = F_904 ( V_119 ) ;
V_113 -> V_1330 = F_896 ;
if ( F_905 ( V_16 ) && F_60 ( V_16 ) -> V_127 < 4 )
V_113 -> V_170 = ! V_119 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
V_1326 = V_1331 ;
V_1327 = F_308 ( V_1331 ) ;
V_113 -> V_449 = F_256 ;
V_113 -> V_364 = F_266 ;
} else if ( F_10 ( V_16 ) ) {
V_1326 = V_1332 ;
V_1327 = F_308 ( V_1332 ) ;
V_113 -> V_449 = F_239 ;
V_113 -> V_364 = F_238 ;
} else if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
V_1326 = V_1332 ;
V_1327 = F_308 ( V_1332 ) ;
V_113 -> V_449 = F_226 ;
V_113 -> V_364 = F_238 ;
} else {
V_1326 = V_1333 ;
V_1327 = F_308 ( V_1333 ) ;
V_113 -> V_449 = F_226 ;
V_113 -> V_364 = F_238 ;
}
F_906 ( V_16 , & V_113 -> V_40 , 0 ,
& V_1334 ,
V_1326 , V_1327 ,
V_1219 , NULL ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 )
F_907 ( V_16 , V_113 ) ;
F_908 ( & V_113 -> V_40 , & V_1335 ) ;
return & V_113 -> V_40 ;
}
void F_907 ( struct V_15 * V_16 , struct V_358 * V_170 )
{
if ( ! V_16 -> V_1115 . V_1336 ) {
unsigned long V_354 = F_232 ( V_423 ) |
F_232 ( V_392 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 )
V_354 |= F_232 ( V_424 ) | F_232 ( V_427 ) ;
V_16 -> V_1115 . V_1336 =
F_909 ( V_16 , V_354 ) ;
}
if ( V_16 -> V_1115 . V_1336 )
F_910 ( & V_170 -> V_40 . V_40 ,
V_16 -> V_1115 . V_1336 ,
V_170 -> V_40 . V_36 -> V_288 ) ;
}
static int
F_911 ( struct V_302 * V_170 ,
struct V_43 * V_44 ,
struct V_359 * V_36 )
{
struct V_111 * V_38 = V_44 -> V_40 . V_38 ;
struct V_278 * V_114 = V_36 -> V_40 . V_114 ;
struct V_303 * V_304 = F_195 ( V_114 ) ;
enum V_119 V_119 = F_219 ( V_170 ) -> V_119 ;
unsigned V_352 ;
int V_306 ;
V_306 = F_897 ( V_170 , V_38 , V_114 , & V_36 -> V_373 ,
& V_36 -> V_377 , & V_36 -> V_1325 ,
V_1322 ,
V_1322 ,
true , true , & V_36 -> V_362 ) ;
if ( V_306 )
return V_306 ;
if ( ! V_304 )
return 0 ;
if ( ! F_681 ( V_170 -> V_16 , V_36 -> V_40 . V_371 , V_36 -> V_40 . V_372 ) ) {
F_912 ( L_279 ,
V_36 -> V_40 . V_371 , V_36 -> V_40 . V_372 ) ;
return - V_559 ;
}
V_352 = F_675 ( V_36 -> V_40 . V_371 ) * 4 ;
if ( V_304 -> V_40 . V_297 < V_352 * V_36 -> V_40 . V_372 ) {
F_153 ( L_280 ) ;
return - V_742 ;
}
if ( V_114 -> V_294 [ 0 ] != V_269 ) {
F_153 ( L_281 ) ;
return - V_559 ;
}
if ( F_14 ( V_170 -> V_16 ) && V_119 == V_523 &&
V_36 -> V_362 && V_36 -> V_40 . V_369 < 0 ) {
F_153 ( L_282 ) ;
return - V_559 ;
}
return 0 ;
}
static void
F_913 ( struct V_302 * V_170 ,
struct V_111 * V_38 )
{
struct V_37 * V_37 = F_50 ( V_38 ) ;
V_37 -> V_1099 = 0 ;
F_679 ( V_38 , NULL ) ;
}
static void
F_914 ( struct V_302 * V_170 ,
const struct V_43 * V_44 ,
const struct V_359 * V_36 )
{
struct V_111 * V_38 = V_44 -> V_40 . V_38 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_15 * V_16 = V_170 -> V_16 ;
struct V_303 * V_304 = F_195 ( V_36 -> V_40 . V_114 ) ;
T_2 V_1193 ;
if ( ! V_304 )
V_1193 = 0 ;
else if ( ! F_60 ( V_16 ) -> V_1319 )
V_1193 = F_223 ( V_304 ) ;
else
V_1193 = V_304 -> V_1337 -> V_1338 ;
V_37 -> V_1099 = V_1193 ;
F_679 ( V_38 , V_36 ) ;
}
static struct V_302 * F_915 ( struct V_15 * V_16 ,
int V_119 )
{
struct V_358 * V_1339 ;
struct V_359 * V_36 ;
V_1339 = F_499 ( sizeof( * V_1339 ) , V_743 ) ;
if ( V_1339 == NULL )
return NULL ;
V_36 = F_903 ( & V_1339 -> V_40 ) ;
if ( ! V_36 ) {
F_221 ( V_1339 ) ;
return NULL ;
}
V_1339 -> V_40 . V_36 = & V_36 -> V_40 ;
V_1339 -> V_1328 = false ;
V_1339 -> V_1329 = 1 ;
V_1339 -> V_119 = V_119 ;
V_1339 -> V_170 = V_119 ;
V_1339 -> V_381 = F_916 ( V_119 ) ;
V_1339 -> V_1330 = F_911 ;
V_1339 -> V_449 = F_914 ;
V_1339 -> V_364 = F_913 ;
F_906 ( V_16 , & V_1339 -> V_40 , 0 ,
& V_1334 ,
V_1340 ,
F_308 ( V_1340 ) ,
V_1217 , NULL ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
if ( ! V_16 -> V_1115 . V_1336 )
V_16 -> V_1115 . V_1336 =
F_909 ( V_16 ,
F_232 ( V_423 ) |
F_232 ( V_392 ) ) ;
if ( V_16 -> V_1115 . V_1336 )
F_910 ( & V_1339 -> V_40 . V_40 ,
V_16 -> V_1115 . V_1336 ,
V_36 -> V_40 . V_288 ) ;
}
if ( F_60 ( V_16 ) -> V_127 >= 9 )
V_36 -> V_436 = - 1 ;
F_908 ( & V_1339 -> V_40 , & V_1335 ) ;
return & V_1339 -> V_40 ;
}
static void F_673 ( struct V_15 * V_16 , struct V_37 * V_37 ,
struct V_43 * V_44 )
{
int V_50 ;
struct V_1341 * V_1341 ;
struct V_403 * V_404 = & V_44 -> V_404 ;
for ( V_50 = 0 ; V_50 < V_37 -> V_405 ; V_50 ++ ) {
V_1341 = & V_404 -> V_406 [ V_50 ] ;
V_1341 -> V_407 = 0 ;
V_1341 -> V_446 = V_1342 ;
}
V_404 -> V_436 = - 1 ;
}
static void F_917 ( struct V_15 * V_16 , int V_119 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 ;
struct V_43 * V_44 = NULL ;
struct V_302 * V_113 = NULL ;
struct V_302 * V_1339 = NULL ;
int V_50 , V_306 ;
V_37 = F_499 ( sizeof( * V_37 ) , V_743 ) ;
if ( V_37 == NULL )
return;
V_44 = F_499 ( sizeof( * V_44 ) , V_743 ) ;
if ( ! V_44 )
goto V_808;
V_37 -> V_115 = V_44 ;
V_37 -> V_40 . V_36 = & V_44 -> V_40 ;
V_44 -> V_40 . V_38 = & V_37 -> V_40 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
if ( V_119 == V_523 )
V_37 -> V_405 = 1 ;
else
V_37 -> V_405 = V_1343 ;
F_673 ( V_16 , V_37 , V_44 ) ;
}
V_113 = F_902 ( V_16 , V_119 ) ;
if ( ! V_113 )
goto V_808;
V_1339 = F_915 ( V_16 , V_119 ) ;
if ( ! V_1339 )
goto V_808;
V_306 = F_918 ( V_16 , & V_37 -> V_40 , V_113 ,
V_1339 , & V_1344 , NULL ) ;
if ( V_306 )
goto V_808;
F_919 ( & V_37 -> V_40 , 256 ) ;
for ( V_50 = 0 ; V_50 < 256 ; V_50 ++ ) {
V_37 -> V_579 [ V_50 ] = V_50 ;
V_37 -> V_580 [ V_50 ] = V_50 ;
V_37 -> V_581 [ V_50 ] = V_50 ;
}
V_37 -> V_119 = V_119 ;
V_37 -> V_170 = V_119 ;
if ( F_905 ( V_16 ) && F_60 ( V_16 ) -> V_127 < 4 ) {
F_153 ( L_283 ) ;
V_37 -> V_170 = ! V_119 ;
}
V_37 -> V_1090 = ~ 0 ;
V_37 -> V_1089 = ~ 0 ;
V_37 -> V_1091 = ~ 0 ;
V_37 -> V_585 . V_591 = true ;
F_142 ( V_119 >= F_308 ( V_2 -> V_1149 ) ||
V_2 -> V_1149 [ V_37 -> V_170 ] != NULL ) ;
V_2 -> V_1149 [ V_37 -> V_170 ] = & V_37 -> V_40 ;
V_2 -> V_120 [ V_37 -> V_119 ] = & V_37 -> V_40 ;
F_920 ( & V_37 -> V_40 , & V_1345 ) ;
F_9 ( F_157 ( & V_37 -> V_40 ) != V_37 -> V_119 ) ;
return;
V_808:
if ( V_113 )
F_901 ( V_113 ) ;
if ( V_1339 )
F_901 ( V_1339 ) ;
F_221 ( V_44 ) ;
F_221 ( V_37 ) ;
}
enum V_119 F_921 ( struct V_740 * V_47 )
{
struct V_635 * V_42 = V_47 -> V_40 . V_42 ;
struct V_15 * V_16 = V_47 -> V_40 . V_16 ;
F_9 ( ! F_922 ( & V_16 -> V_1115 . V_1117 ) ) ;
if ( ! V_42 || F_9 ( ! V_42 -> V_38 ) )
return V_608 ;
return F_50 ( V_42 -> V_38 ) -> V_119 ;
}
int F_923 ( struct V_15 * V_16 , void * V_1054 ,
struct V_1346 * V_1347 )
{
struct V_1348 * V_1349 = V_1054 ;
struct V_111 * V_1350 ;
struct V_37 * V_38 ;
V_1350 = F_924 ( V_16 , V_1349 -> V_1351 ) ;
if ( ! V_1350 ) {
F_132 ( L_284 ) ;
return - V_1352 ;
}
V_38 = F_50 ( V_1350 ) ;
V_1349 -> V_119 = V_38 -> V_119 ;
return 0 ;
}
static int F_925 ( struct V_41 * V_42 )
{
struct V_15 * V_16 = V_42 -> V_40 . V_16 ;
struct V_41 * V_1223 ;
int V_1353 = 0 ;
int V_1354 = 0 ;
F_605 (dev, source_encoder) {
if ( F_802 ( V_42 , V_1223 ) )
V_1353 |= ( 1 << V_1354 ) ;
V_1354 ++ ;
}
return V_1353 ;
}
static bool F_926 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! F_128 ( V_16 ) )
return false ;
if ( ( F_11 ( V_1355 ) & V_1356 ) == 0 )
return false ;
if ( F_18 ( V_16 ) && ( F_11 ( V_649 ) & V_1357 ) )
return false ;
return true ;
}
static bool F_927 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 )
return false ;
if ( F_523 ( V_16 ) || F_439 ( V_16 ) )
return false ;
if ( F_14 ( V_16 ) )
return false ;
if ( F_928 ( V_16 ) && F_11 ( V_1358 ) & V_1359 )
return false ;
if ( F_71 ( V_16 ) && F_11 ( F_929 ( V_618 ) ) & V_1360 )
return false ;
if ( ! V_2 -> V_827 . V_1361 )
return false ;
return true ;
}
static void F_930 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_41 * V_42 ;
bool V_1362 = false ;
F_931 ( V_16 ) ;
if ( F_927 ( V_16 ) )
F_932 ( V_16 ) ;
if ( F_30 ( V_16 ) ) {
F_933 ( V_16 , V_618 ) ;
F_933 ( V_16 , V_231 ) ;
F_933 ( V_16 , V_233 ) ;
} else if ( F_71 ( V_16 ) ) {
int V_101 ;
V_101 = F_11 ( F_929 ( V_618 ) ) & V_1363 ;
if ( V_101 || F_436 ( V_16 ) || F_437 ( V_16 ) )
F_933 ( V_16 , V_618 ) ;
V_101 = F_11 ( V_1358 ) ;
if ( V_101 & V_1364 )
F_933 ( V_16 , V_231 ) ;
if ( V_101 & V_1365 )
F_933 ( V_16 , V_233 ) ;
if ( V_101 & V_1366 )
F_933 ( V_16 , V_235 ) ;
if ( ( F_436 ( V_16 ) || F_437 ( V_16 ) ) &&
( V_2 -> V_827 . V_1367 [ V_623 ] . V_1368 ||
V_2 -> V_827 . V_1367 [ V_623 ] . V_1369 ||
V_2 -> V_827 . V_1367 [ V_623 ] . V_1370 ) )
F_933 ( V_16 , V_623 ) ;
} else if ( F_10 ( V_16 ) ) {
int V_101 ;
V_1362 = F_934 ( V_16 , V_235 ) ;
if ( F_926 ( V_16 ) )
F_935 ( V_16 , V_1355 , V_618 ) ;
if ( F_11 ( V_209 ) & V_1371 ) {
V_101 = F_936 ( V_16 , V_1372 , V_231 ) ;
if ( ! V_101 )
F_937 ( V_16 , V_209 , V_231 ) ;
if ( ! V_101 && ( F_11 ( V_202 ) & V_1356 ) )
F_935 ( V_16 , V_202 , V_231 ) ;
}
if ( F_11 ( V_210 ) & V_1371 )
F_937 ( V_16 , V_210 , V_233 ) ;
if ( ! V_1362 && F_11 ( V_211 ) & V_1371 )
F_937 ( V_16 , V_211 , V_235 ) ;
if ( F_11 ( V_204 ) & V_1356 )
F_935 ( V_16 , V_204 , V_233 ) ;
if ( F_11 ( V_206 ) & V_1356 )
F_935 ( V_16 , V_206 , V_235 ) ;
} else if ( F_13 ( V_16 ) || F_14 ( V_16 ) ) {
if ( F_11 ( V_1373 ) & V_1371 &&
! F_934 ( V_16 , V_231 ) )
F_937 ( V_16 , V_1373 , V_231 ) ;
if ( F_11 ( V_1374 ) & V_1356 ||
F_934 ( V_16 , V_231 ) )
F_935 ( V_16 , V_1374 , V_231 ) ;
if ( F_11 ( V_1375 ) & V_1371 &&
! F_934 ( V_16 , V_233 ) )
F_937 ( V_16 , V_1375 , V_233 ) ;
if ( F_11 ( V_1376 ) & V_1356 ||
F_934 ( V_16 , V_233 ) )
F_935 ( V_16 , V_1376 , V_233 ) ;
if ( F_14 ( V_16 ) ) {
if ( F_11 ( V_1377 ) & V_1371 )
F_937 ( V_16 , V_1377 , V_235 ) ;
if ( F_11 ( V_1378 ) & V_1356 )
F_935 ( V_16 , V_1378 , V_235 ) ;
}
F_938 ( V_16 ) ;
} else if ( ! F_33 ( V_16 ) && ! F_32 ( V_16 ) ) {
bool V_101 = false ;
if ( F_11 ( V_1379 ) & V_1371 ) {
F_153 ( L_285 ) ;
V_101 = F_936 ( V_16 , V_1379 , V_231 ) ;
if ( ! V_101 && F_31 ( V_16 ) ) {
F_153 ( L_286 ) ;
F_937 ( V_16 , V_1380 , V_231 ) ;
}
if ( ! V_101 && F_31 ( V_16 ) )
F_935 ( V_16 , V_1381 , V_231 ) ;
}
if ( F_11 ( V_1379 ) & V_1371 ) {
F_153 ( L_287 ) ;
V_101 = F_936 ( V_16 , V_1382 , V_233 ) ;
}
if ( ! V_101 && ( F_11 ( V_1382 ) & V_1371 ) ) {
if ( F_31 ( V_16 ) ) {
F_153 ( L_288 ) ;
F_937 ( V_16 , V_1383 , V_233 ) ;
}
if ( F_31 ( V_16 ) )
F_935 ( V_16 , V_1384 , V_233 ) ;
}
if ( F_31 ( V_16 ) &&
( F_11 ( V_1385 ) & V_1356 ) )
F_935 ( V_16 , V_1385 , V_235 ) ;
} else if ( F_33 ( V_16 ) )
F_939 ( V_16 ) ;
if ( F_940 ( V_16 ) )
F_941 ( V_16 ) ;
F_942 ( V_16 ) ;
F_605 (dev, encoder) {
V_42 -> V_40 . V_1119 = V_42 -> V_238 ;
V_42 -> V_40 . V_1386 =
F_925 ( V_42 ) ;
}
F_615 ( V_16 ) ;
F_943 ( V_16 ) ;
}
static void F_944 ( struct V_278 * V_114 )
{
struct V_15 * V_16 = V_114 -> V_16 ;
struct V_947 * V_948 = F_213 ( V_114 ) ;
F_945 ( V_114 ) ;
F_2 ( & V_16 -> V_307 ) ;
F_9 ( ! V_948 -> V_304 -> V_1387 -- ) ;
F_214 ( & V_948 -> V_304 -> V_40 ) ;
F_4 ( & V_16 -> V_307 ) ;
F_221 ( V_948 ) ;
}
static int F_946 ( struct V_278 * V_114 ,
struct V_1346 * V_1347 ,
unsigned int * V_1388 )
{
struct V_947 * V_948 = F_213 ( V_114 ) ;
struct V_303 * V_304 = V_948 -> V_304 ;
if ( V_304 -> V_1389 . V_583 ) {
F_912 ( L_289 ) ;
return - V_559 ;
}
return F_947 ( V_1347 , & V_304 -> V_40 , V_1388 ) ;
}
static int F_948 ( struct V_278 * V_114 ,
struct V_1346 * V_1347 ,
unsigned V_354 , unsigned V_1390 ,
struct V_1391 * V_1392 ,
unsigned V_1393 )
{
struct V_15 * V_16 = V_114 -> V_16 ;
struct V_947 * V_948 = F_213 ( V_114 ) ;
struct V_303 * V_304 = V_948 -> V_304 ;
F_2 ( & V_16 -> V_307 ) ;
F_949 ( V_304 , false , V_1394 ) ;
F_4 ( & V_16 -> V_307 ) ;
return 0 ;
}
static
T_1 F_950 ( struct V_15 * V_16 , V_89 V_267 ,
T_2 V_274 )
{
T_1 V_127 = F_60 ( V_16 ) -> V_127 ;
if ( V_127 >= 9 ) {
int V_268 = F_184 ( V_274 , 0 ) ;
return V_90 ( 8192 * V_268 , 32768 ) ;
} else if ( V_127 >= 5 && ! F_13 ( V_16 ) && ! F_14 ( V_16 ) ) {
return 32 * 1024 ;
} else if ( V_127 >= 4 ) {
if ( V_267 == V_270 )
return 16 * 1024 ;
else
return 32 * 1024 ;
} else if ( V_127 >= 3 ) {
if ( V_267 == V_270 )
return 8 * 1024 ;
else
return 16 * 1024 ;
} else {
return 8 * 1024 ;
}
}
static int F_212 ( struct V_15 * V_16 ,
struct V_947 * V_948 ,
struct V_342 * V_343 ,
struct V_303 * V_304 )
{
struct V_1 * V_2 = F_185 ( V_16 ) ;
unsigned int V_946 ;
int V_306 ;
T_1 V_1395 , V_1396 ;
F_9 ( ! F_196 ( & V_16 -> V_307 ) ) ;
if ( V_343 -> V_354 & V_355 ) {
if ( ! ! ( V_304 -> V_349 == V_351 ) !=
! ! ( V_343 -> V_294 [ 0 ] == V_270 ) ) {
F_912 ( L_290 ) ;
return - V_559 ;
}
} else {
if ( V_304 -> V_349 == V_351 )
V_343 -> V_294 [ 0 ] = V_270 ;
else if ( V_304 -> V_349 == V_1397 ) {
F_912 ( L_291 ) ;
return - V_559 ;
}
}
switch ( V_343 -> V_294 [ 0 ] ) {
case V_271 :
case V_272 :
if ( F_60 ( V_16 ) -> V_127 < 9 ) {
F_912 ( L_292 ,
V_343 -> V_294 [ 0 ] ) ;
return - V_559 ;
}
case V_269 :
case V_270 :
break;
default:
F_912 ( L_293 ,
V_343 -> V_294 [ 0 ] ) ;
return - V_559 ;
}
V_1396 = F_243 ( V_2 ,
V_343 -> V_294 [ 0 ] ,
V_343 -> V_274 ) ;
if ( V_343 -> V_291 [ 0 ] & ( V_1396 - 1 ) ) {
F_912 ( L_294 ,
V_343 -> V_291 [ 0 ] , V_1396 ) ;
return - V_559 ;
}
V_1395 = F_950 ( V_16 , V_343 -> V_294 [ 0 ] ,
V_343 -> V_274 ) ;
if ( V_343 -> V_291 [ 0 ] > V_1395 ) {
F_912 ( L_295 ,
V_343 -> V_294 [ 0 ] != V_269 ?
L_296 : L_297 ,
V_343 -> V_291 [ 0 ] , V_1395 ) ;
return - V_559 ;
}
if ( V_343 -> V_294 [ 0 ] == V_270 &&
V_343 -> V_291 [ 0 ] != V_304 -> V_352 ) {
F_912 ( L_298 ,
V_343 -> V_291 [ 0 ] , V_304 -> V_352 ) ;
return - V_559 ;
}
switch ( V_343 -> V_274 ) {
case V_320 :
case V_324 :
case V_326 :
case V_338 :
break;
case V_322 :
if ( F_60 ( V_16 ) -> V_127 > 3 ) {
F_912 ( L_299 ,
F_951 ( V_343 -> V_274 ) ) ;
return - V_559 ;
}
break;
case V_337 :
if ( ! F_13 ( V_16 ) && ! F_14 ( V_16 ) &&
F_60 ( V_16 ) -> V_127 < 9 ) {
F_912 ( L_299 ,
F_951 ( V_343 -> V_274 ) ) ;
return - V_559 ;
}
break;
case V_328 :
case V_330 :
case V_332 :
if ( F_60 ( V_16 ) -> V_127 < 4 ) {
F_912 ( L_299 ,
F_951 ( V_343 -> V_274 ) ) ;
return - V_559 ;
}
break;
case V_1398 :
if ( ! F_13 ( V_16 ) && ! F_14 ( V_16 ) ) {
F_912 ( L_299 ,
F_951 ( V_343 -> V_274 ) ) ;
return - V_559 ;
}
break;
case V_411 :
case V_416 :
case V_414 :
case V_418 :
if ( F_60 ( V_16 ) -> V_127 < 5 ) {
F_912 ( L_299 ,
F_951 ( V_343 -> V_274 ) ) ;
return - V_559 ;
}
break;
default:
F_912 ( L_299 ,
F_951 ( V_343 -> V_274 ) ) ;
return - V_559 ;
}
if ( V_343 -> V_293 [ 0 ] != 0 )
return - V_559 ;
V_946 = F_183 ( V_16 , V_343 -> V_273 ,
V_343 -> V_274 ,
V_343 -> V_294 [ 0 ] ) ;
if ( V_304 -> V_40 . V_297 < V_946 * V_343 -> V_291 [ 0 ] )
return - V_559 ;
F_952 ( & V_948 -> V_40 , V_343 ) ;
V_948 -> V_304 = V_304 ;
V_306 = F_953 ( V_16 , & V_948 -> V_40 , & V_1399 ) ;
if ( V_306 ) {
F_132 ( L_300 , V_306 ) ;
return V_306 ;
}
V_948 -> V_304 -> V_1387 ++ ;
return 0 ;
}
static struct V_278 *
F_954 ( struct V_15 * V_16 ,
struct V_1346 * V_1400 ,
const struct V_342 * V_1401 )
{
struct V_278 * V_114 ;
struct V_303 * V_304 ;
struct V_342 V_343 = * V_1401 ;
V_304 = F_955 ( F_956 ( V_16 , V_1400 ,
V_343 . V_1402 [ 0 ] ) ) ;
if ( & V_304 -> V_40 == NULL )
return F_684 ( - V_1352 ) ;
V_114 = F_685 ( V_16 , & V_343 , V_304 ) ;
if ( F_505 ( V_114 ) )
F_693 ( & V_304 -> V_40 ) ;
return V_114 ;
}
static inline void F_957 ( struct V_15 * V_16 )
{
}
static void F_958 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_10 ( V_16 ) || F_31 ( V_16 ) )
V_2 -> V_451 . V_942 = F_45 ;
else if ( F_14 ( V_16 ) )
V_2 -> V_451 . V_942 = F_51 ;
else if ( F_13 ( V_16 ) )
V_2 -> V_451 . V_942 = F_49 ;
else if ( F_32 ( V_16 ) )
V_2 -> V_451 . V_942 = F_44 ;
else
V_2 -> V_451 . V_942 = F_43 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
V_2 -> V_451 . V_1281 = F_672 ;
V_2 -> V_451 . V_1403 =
F_641 ;
V_2 -> V_451 . V_1224 =
F_664 ;
V_2 -> V_451 . V_1312 = F_406 ;
V_2 -> V_451 . V_738 = F_416 ;
} else if ( F_71 ( V_16 ) ) {
V_2 -> V_451 . V_1281 = F_672 ;
V_2 -> V_451 . V_1403 =
F_644 ;
V_2 -> V_451 . V_1224 =
F_664 ;
V_2 -> V_451 . V_1312 = F_406 ;
V_2 -> V_451 . V_738 = F_416 ;
} else if ( F_10 ( V_16 ) ) {
V_2 -> V_451 . V_1281 = F_645 ;
V_2 -> V_451 . V_1403 =
F_644 ;
V_2 -> V_451 . V_1224 =
F_634 ;
V_2 -> V_451 . V_1312 = F_397 ;
V_2 -> V_451 . V_738 = F_414 ;
} else if ( F_13 ( V_16 ) || F_14 ( V_16 ) ) {
V_2 -> V_451 . V_1281 = F_602 ;
V_2 -> V_451 . V_1403 =
F_600 ;
V_2 -> V_451 . V_1224 = F_597 ;
V_2 -> V_451 . V_1312 = F_477 ;
V_2 -> V_451 . V_738 = F_488 ;
} else {
V_2 -> V_451 . V_1281 = F_602 ;
V_2 -> V_451 . V_1403 =
F_600 ;
V_2 -> V_451 . V_1224 = F_597 ;
V_2 -> V_451 . V_1312 = F_486 ;
V_2 -> V_451 . V_738 = F_488 ;
}
if ( F_436 ( V_16 ) || F_437 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_519 ;
else if ( F_30 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_520 ;
else if ( F_241 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_521 ;
else if ( F_240 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_522 ;
else if ( F_13 ( V_16 ) || F_14 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_524 ;
else if ( F_18 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_525 ;
else if ( F_588 ( V_16 ) || F_191 ( V_16 ) ||
F_306 ( V_16 ) || F_297 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_526 ;
else if ( F_538 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_540 ;
else if ( F_192 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_541 ;
else if ( F_32 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_529 ;
else if ( F_539 ( V_16 ) || F_31 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_542 ;
else if ( F_516 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_527 ;
else if ( F_589 ( V_16 ) || F_82 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_528 ;
else if ( F_959 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_531 ;
else if ( F_83 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_532 ;
else if ( F_960 ( V_16 ) )
V_2 -> V_451 . V_653 =
F_533 ;
else {
F_6 ( ! F_143 ( V_16 ) , L_301 ) ;
V_2 -> V_451 . V_653 =
F_536 ;
}
if ( F_18 ( V_16 ) ) {
V_2 -> V_451 . V_527 = F_298 ;
} else if ( F_306 ( V_16 ) ) {
V_2 -> V_451 . V_527 = F_304 ;
} else if ( F_297 ( V_16 ) ) {
V_2 -> V_451 . V_527 = F_307 ;
} else if ( F_240 ( V_16 ) || F_241 ( V_16 ) ) {
V_2 -> V_451 . V_527 = V_1404 ;
if ( F_241 ( V_16 ) ) {
V_2 -> V_451 . V_1311 =
F_663 ;
V_2 -> V_451 . V_1289 =
F_662 ;
}
} else if ( F_13 ( V_16 ) || F_14 ( V_16 ) ) {
V_2 -> V_451 . V_1311 =
F_476 ;
V_2 -> V_451 . V_1289 =
F_472 ;
} else if ( F_30 ( V_16 ) ) {
V_2 -> V_451 . V_1311 =
F_659 ;
V_2 -> V_451 . V_1289 =
F_473 ;
}
switch ( F_60 ( V_16 ) -> V_127 ) {
case 2 :
V_2 -> V_451 . V_1206 = F_743 ;
break;
case 3 :
V_2 -> V_451 . V_1206 = F_747 ;
break;
case 4 :
case 5 :
V_2 -> V_451 . V_1206 = F_748 ;
break;
case 6 :
V_2 -> V_451 . V_1206 = F_749 ;
break;
case 7 :
case 8 :
V_2 -> V_451 . V_1206 = F_750 ;
break;
case 9 :
default:
V_2 -> V_451 . V_1206 = F_772 ;
}
F_961 ( & V_2 -> V_1405 ) ;
}
static void F_962 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_166 |= V_167 ;
F_963 ( L_302 ) ;
}
static void F_964 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_166 |= V_168 ;
F_963 ( L_303 ) ;
}
static void F_965 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_166 |= V_829 ;
F_963 ( L_304 ) ;
}
static void F_966 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_166 |= V_1406 ;
F_963 ( L_305 ) ;
}
static void F_967 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_166 |= V_1407 ;
F_963 ( L_306 ) ;
}
static int F_968 ( const struct V_1408 * V_241 )
{
F_963 ( L_307 , V_241 -> V_1409 ) ;
return 1 ;
}
static void F_969 ( struct V_15 * V_16 )
{
struct V_1410 * V_1411 = V_16 -> V_770 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < F_308 ( V_1412 ) ; V_50 ++ ) {
struct V_1413 * V_1414 = & V_1412 [ V_50 ] ;
if ( V_1411 -> V_1415 == V_1414 -> V_1415 &&
( V_1411 -> V_1416 == V_1414 -> V_1416 ||
V_1414 -> V_1416 == V_1417 ) &&
( V_1411 -> V_1418 == V_1414 -> V_1418 ||
V_1414 -> V_1418 == V_1417 ) )
V_1414 -> V_1419 ( V_16 ) ;
}
for ( V_50 = 0 ; V_50 < F_308 ( V_1420 ) ; V_50 ++ ) {
if ( F_970 ( * V_1420 [ V_50 ] . V_1421 ) != 0 )
V_1420 [ V_50 ] . V_1419 ( V_16 ) ;
}
}
static void F_971 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_13 V_1422 ;
T_5 V_1423 = F_972 ( V_16 ) ;
F_973 ( V_16 -> V_770 , V_1424 ) ;
F_974 ( V_1425 , V_1426 ) ;
V_1422 = F_975 ( V_1427 ) ;
F_974 ( V_1422 | 1 << 5 , V_1427 ) ;
F_976 ( V_16 -> V_770 , V_1424 ) ;
F_131 ( 300 ) ;
F_129 ( V_1423 , V_1428 ) ;
F_130 ( V_1423 ) ;
}
void F_281 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
F_440 ( V_16 ) ;
V_2 -> V_1290 = V_2 -> V_651 ;
F_977 ( V_16 ) ;
F_978 ( V_16 ) ;
}
static void F_979 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_185 ( V_16 ) ;
struct V_45 * V_36 ;
struct V_111 * V_38 ;
struct V_35 * V_1051 ;
struct V_1111 V_1112 ;
int V_306 ;
int V_50 ;
if ( ! V_2 -> V_451 . V_1429 )
return;
F_980 ( & V_1112 , 0 ) ;
V_478:
V_306 = F_981 ( V_16 , & V_1112 ) ;
if ( V_306 == - V_310 ) {
F_712 ( & V_1112 ) ;
goto V_478;
} else if ( F_9 ( V_306 ) ) {
goto V_808;
}
V_36 = F_982 ( V_16 , & V_1112 ) ;
if ( F_9 ( F_505 ( V_36 ) ) )
goto V_808;
V_306 = F_861 ( V_16 , V_36 ) ;
if ( V_306 ) {
F_6 ( true , L_308 ) ;
goto V_808;
}
F_185 ( V_16 ) -> V_585 . V_115 = F_362 ( V_36 ) -> V_1292 ;
F_471 (state, crtc, cstate, i) {
struct V_43 * V_1430 = F_273 ( V_1051 ) ;
V_2 -> V_451 . V_1429 ( V_1430 ) ;
}
F_711 ( V_36 ) ;
V_808:
F_983 ( & V_1112 ) ;
F_984 ( & V_1112 ) ;
}
void F_985 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
int V_175 , V_306 ;
enum V_119 V_119 ;
struct V_37 * V_38 ;
F_986 ( V_16 ) ;
V_16 -> V_1115 . V_1431 = 0 ;
V_16 -> V_1115 . V_1432 = 0 ;
V_16 -> V_1115 . V_1433 = 24 ;
V_16 -> V_1115 . V_1434 = 1 ;
V_16 -> V_1115 . V_1435 = true ;
V_16 -> V_1115 . V_1436 = & V_1437 ;
F_969 ( V_16 ) ;
F_987 ( V_16 ) ;
if ( F_60 ( V_16 ) -> V_746 == 0 )
return;
if ( F_106 ( V_16 ) || F_107 ( V_16 ) ) {
bool V_1438 = ! ! ( F_11 ( V_181 ) &
V_969 ) ;
if ( V_2 -> V_827 . V_828 != V_1438 ) {
F_153 ( L_309 ,
V_1438 ? L_73 : L_74 ,
V_2 -> V_827 . V_828 ? L_73 : L_74 ) ;
V_2 -> V_827 . V_828 = V_1438 ;
}
}
F_958 ( V_16 ) ;
F_988 ( V_16 ) ;
if ( F_33 ( V_16 ) ) {
V_16 -> V_1115 . V_1439 = 2048 ;
V_16 -> V_1115 . V_1440 = 2048 ;
} else if ( F_989 ( V_16 ) ) {
V_16 -> V_1115 . V_1439 = 4096 ;
V_16 -> V_1115 . V_1440 = 4096 ;
} else {
V_16 -> V_1115 . V_1439 = 8192 ;
V_16 -> V_1115 . V_1440 = 8192 ;
}
if ( F_82 ( V_16 ) || F_83 ( V_16 ) ) {
V_16 -> V_1115 . V_1441 = F_82 ( V_16 ) ? 64 : 512 ;
V_16 -> V_1115 . V_1442 = 1023 ;
} else if ( F_33 ( V_16 ) ) {
V_16 -> V_1115 . V_1441 = V_1443 ;
V_16 -> V_1115 . V_1442 = V_1444 ;
} else {
V_16 -> V_1115 . V_1441 = V_1445 ;
V_16 -> V_1115 . V_1442 = V_1446 ;
}
V_16 -> V_1115 . V_1447 = V_2 -> V_347 . V_1448 ;
F_153 ( L_310 ,
F_60 ( V_16 ) -> V_746 ,
F_60 ( V_16 ) -> V_746 > 1 ? L_311 : L_312 ) ;
F_93 (dev_priv, pipe) {
F_917 ( V_16 , V_119 ) ;
F_95 (dev_priv, pipe, sprite) {
V_306 = F_990 ( V_16 , V_119 , V_175 ) ;
if ( V_306 )
F_153 ( L_313 ,
F_80 ( V_119 ) , F_98 ( V_119 , V_175 ) , V_306 ) ;
}
}
F_15 ( V_2 ) ;
F_440 ( V_16 ) ;
F_889 ( V_16 ) ;
F_971 ( V_16 ) ;
F_930 ( V_16 ) ;
F_276 ( V_16 ) ;
F_991 ( V_16 ) ;
F_286 ( V_16 ) ;
F_140 (dev, crtc) {
struct V_340 V_341 = {} ;
if ( ! V_38 -> V_112 )
continue;
V_2 -> V_451 . V_1403 ( V_38 ,
& V_341 ) ;
F_218 ( V_38 , & V_341 ) ;
}
F_979 ( V_16 ) ;
}
static void F_992 ( struct V_15 * V_16 )
{
struct V_740 * V_47 ;
struct V_46 * V_1449 = NULL ;
struct V_1109 V_1450 ;
struct V_1111 * V_1112 = V_16 -> V_1115 . V_1120 ;
F_808 (dev, connector) {
if ( V_47 -> V_42 -> type == V_64 ) {
V_1449 = & V_47 -> V_40 ;
break;
}
}
if ( ! V_1449 )
return;
if ( F_701 ( V_1449 , NULL , & V_1450 , V_1112 ) )
F_713 ( V_1449 , & V_1450 , V_1112 ) ;
}
static bool
F_993 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 ;
if ( F_60 ( V_16 ) -> V_746 == 1 )
return true ;
V_10 = F_11 ( F_90 ( ! V_38 -> V_170 ) ) ;
if ( ( V_10 & V_171 ) &&
( ! ! ( V_10 & V_173 ) == V_38 -> V_119 ) )
return false ;
return true ;
}
static bool F_994 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_41 * V_42 ;
F_22 (dev, &crtc->base, encoder)
return true ;
return false ;
}
static bool F_995 ( struct V_41 * V_42 )
{
struct V_15 * V_16 = V_42 -> V_40 . V_16 ;
struct V_740 * V_47 ;
F_996 (dev, &encoder->base, connector)
return true ;
return false ;
}
static void F_997 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_5 V_9 = F_61 ( V_38 -> V_115 -> V_121 ) ;
F_129 ( V_9 , F_11 ( V_9 ) & ~ V_1451 ) ;
F_998 ( & V_38 -> V_40 ) ;
if ( V_38 -> V_112 ) {
struct V_358 * V_170 ;
F_403 ( & V_38 -> V_40 ) ;
F_999 (dev, crtc, plane) {
if ( V_170 -> V_40 . type == V_1219 )
continue;
V_170 -> V_364 ( & V_170 -> V_40 , & V_38 -> V_40 ) ;
}
}
if ( F_60 ( V_16 ) -> V_127 < 4 && ! F_993 ( V_38 ) ) {
bool V_170 ;
F_153 ( L_314 ,
V_38 -> V_40 . V_40 . V_241 ) ;
V_170 = V_38 -> V_170 ;
F_220 ( V_38 -> V_40 . V_113 -> V_36 ) -> V_362 = true ;
V_38 -> V_170 = ! V_170 ;
F_489 ( & V_38 -> V_40 ) ;
V_38 -> V_170 = V_170 ;
}
if ( V_2 -> V_166 & V_167 &&
V_38 -> V_119 == V_147 && ! V_38 -> V_112 ) {
F_992 ( V_16 ) ;
}
if ( ! F_994 ( V_38 ) )
F_489 ( & V_38 -> V_40 ) ;
if ( V_38 -> V_112 != V_38 -> V_40 . V_36 -> V_112 ) {
struct V_41 * V_42 ;
F_153 ( L_315 ,
V_38 -> V_40 . V_40 . V_241 ,
V_38 -> V_40 . V_36 -> V_243 ? L_219 : L_220 ,
V_38 -> V_112 ? L_219 : L_220 ) ;
F_9 ( F_708 ( V_38 -> V_40 . V_36 , NULL ) < 0 ) ;
V_38 -> V_40 . V_36 -> V_112 = V_38 -> V_112 ;
V_38 -> V_40 . V_180 = V_38 -> V_112 ;
V_38 -> V_40 . V_36 -> V_1452 = 0 ;
V_38 -> V_40 . V_36 -> V_1453 = 0 ;
F_9 ( V_38 -> V_112 ) ;
F_22 (dev, &crtc->base, encoder)
V_42 -> V_40 . V_38 = NULL ;
}
if ( V_38 -> V_112 || F_170 ( V_16 ) ) {
V_38 -> V_1454 = true ;
V_38 -> V_1455 = true ;
}
}
static void F_1000 ( struct V_41 * V_42 )
{
struct V_740 * V_47 ;
struct V_15 * V_16 = V_42 -> V_40 . V_16 ;
bool V_1456 = V_42 -> V_40 . V_38 &&
F_50 ( V_42 -> V_40 . V_38 ) -> V_112 ;
if ( F_995 ( V_42 ) && ! V_1456 ) {
F_153 ( L_316 ,
V_42 -> V_40 . V_40 . V_241 ,
V_42 -> V_40 . V_8 ) ;
if ( V_42 -> V_40 . V_38 ) {
F_153 ( L_317 ,
V_42 -> V_40 . V_40 . V_241 ,
V_42 -> V_40 . V_8 ) ;
V_42 -> V_244 ( V_42 ) ;
if ( V_42 -> V_610 )
V_42 -> V_610 ( V_42 ) ;
}
V_42 -> V_40 . V_38 = NULL ;
F_808 (dev, connector) {
if ( V_47 -> V_42 != V_42 )
continue;
V_47 -> V_40 . V_1457 = V_1458 ;
V_47 -> V_40 . V_42 = NULL ;
}
}
}
void F_1001 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_5 V_1423 = F_972 ( V_16 ) ;
if ( ! ( F_11 ( V_1423 ) & V_1428 ) ) {
F_153 ( L_318 ) ;
F_971 ( V_16 ) ;
}
}
void F_1002 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! F_87 ( V_2 , V_1459 ) )
return;
F_1001 ( V_16 ) ;
F_88 ( V_2 , V_1459 ) ;
}
static bool F_1003 ( struct V_358 * V_170 )
{
struct V_1 * V_2 = F_185 ( V_170 -> V_40 . V_16 ) ;
return F_11 ( F_90 ( V_170 -> V_170 ) ) & V_171 ;
}
static void F_1004 ( struct V_37 * V_38 )
{
struct V_302 * V_113 = V_38 -> V_40 . V_113 ;
struct V_359 * V_280 =
F_220 ( V_113 -> V_36 ) ;
V_280 -> V_362 = V_38 -> V_112 &&
F_1003 ( F_219 ( V_113 ) ) ;
if ( V_280 -> V_362 )
V_38 -> V_40 . V_36 -> V_363 |= 1 << F_224 ( V_113 ) ;
}
static void F_1005 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 ;
struct V_37 * V_38 ;
struct V_41 * V_42 ;
struct V_740 * V_47 ;
int V_50 ;
V_2 -> V_723 = 0 ;
F_140 (dev, crtc) {
struct V_43 * V_44 = V_38 -> V_115 ;
int V_721 = 0 ;
F_845 ( & V_38 -> V_40 , & V_44 -> V_40 ) ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_40 . V_38 = & V_38 -> V_40 ;
V_44 -> V_40 . V_112 = V_44 -> V_40 . V_243 =
V_2 -> V_451 . V_1281 ( V_38 , V_44 ) ;
V_38 -> V_40 . V_180 = V_44 -> V_40 . V_243 ;
V_38 -> V_112 = V_44 -> V_40 . V_112 ;
if ( V_44 -> V_40 . V_112 ) {
V_2 -> V_723 |= 1 << V_38 -> V_119 ;
if ( F_241 ( V_2 ) ) {
V_721 = F_513 ( V_44 ) ;
if ( V_44 -> V_569 )
V_721 = F_189 ( V_721 * 100 , 95 ) ;
} else if ( F_13 ( V_2 ) ||
F_14 ( V_2 ) ||
F_30 ( V_2 ) )
V_721 = V_44 -> V_40 . V_116 . V_117 ;
else
F_9 ( V_2 -> V_451 . V_1289 ) ;
}
V_2 -> V_720 [ V_38 -> V_119 ] = V_721 ;
F_1004 ( V_38 ) ;
F_153 ( L_319 ,
V_38 -> V_40 . V_40 . V_241 ,
V_38 -> V_112 ? L_219 : L_220 ) ;
}
for ( V_50 = 0 ; V_50 < V_2 -> V_543 ; V_50 ++ ) {
struct V_133 * V_136 = & V_2 -> V_135 [ V_50 ] ;
V_136 -> V_239 = V_136 -> V_139 ( V_2 , V_136 ,
& V_136 -> V_115 . V_138 ) ;
V_136 -> V_112 = 0 ;
V_136 -> V_115 . V_238 = 0 ;
F_140 (dev, crtc) {
if ( V_38 -> V_112 && F_68 ( V_38 ) == V_136 ) {
V_136 -> V_112 ++ ;
V_136 -> V_115 . V_238 |= 1 << V_38 -> V_119 ;
}
}
F_153 ( L_320 ,
V_136 -> V_8 , V_136 -> V_115 . V_238 , V_136 -> V_239 ) ;
if ( V_136 -> V_115 . V_238 )
F_155 ( V_2 , V_242 ) ;
}
F_605 (dev, encoder) {
V_119 = 0 ;
if ( V_42 -> V_139 ( V_42 , & V_119 ) ) {
V_38 = F_50 ( V_2 -> V_120 [ V_119 ] ) ;
V_42 -> V_40 . V_38 = & V_38 -> V_40 ;
V_42 -> V_1282 ( V_42 , V_38 -> V_115 ) ;
} else {
V_42 -> V_40 . V_38 = NULL ;
}
F_153 ( L_321 ,
V_42 -> V_40 . V_40 . V_241 ,
V_42 -> V_40 . V_8 ,
V_42 -> V_40 . V_38 ? L_219 : L_220 ,
F_80 ( V_119 ) ) ;
}
F_808 (dev, connector) {
if ( V_47 -> V_139 ( V_47 ) ) {
V_47 -> V_40 . V_1457 = V_1460 ;
V_42 = V_47 -> V_42 ;
V_47 -> V_40 . V_42 = & V_42 -> V_40 ;
if ( V_42 -> V_40 . V_38 &&
V_42 -> V_40 . V_38 -> V_36 -> V_112 ) {
V_42 -> V_40 . V_38 -> V_36 -> V_1452 |=
1 << F_1006 ( & V_47 -> V_40 ) ;
V_42 -> V_40 . V_38 -> V_36 -> V_1453 |=
1 << F_1007 ( & V_42 -> V_40 ) ;
}
} else {
V_47 -> V_40 . V_1457 = V_1458 ;
V_47 -> V_40 . V_42 = NULL ;
}
F_153 ( L_322 ,
V_47 -> V_40 . V_40 . V_241 ,
V_47 -> V_40 . V_8 ,
V_47 -> V_40 . V_42 ? L_219 : L_220 ) ;
}
F_140 (dev, crtc) {
V_38 -> V_40 . V_1259 = V_38 -> V_115 -> V_40 . V_116 ;
memset ( & V_38 -> V_40 . V_446 , 0 , sizeof( V_38 -> V_40 . V_446 ) ) ;
if ( V_38 -> V_40 . V_36 -> V_112 ) {
F_592 ( & V_38 -> V_40 . V_446 , V_38 -> V_115 ) ;
F_592 ( & V_38 -> V_40 . V_36 -> V_116 , V_38 -> V_115 ) ;
F_9 ( F_708 ( V_38 -> V_40 . V_36 , & V_38 -> V_40 . V_446 ) ) ;
V_38 -> V_40 . V_36 -> V_446 . V_1297 = V_1461 ;
F_1008 ( & V_38 -> V_40 , & V_38 -> V_40 . V_1259 ) ;
F_850 ( V_38 ) ;
}
}
}
static void
F_991 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 ;
struct V_37 * V_38 ;
struct V_41 * V_42 ;
int V_50 ;
F_1005 ( V_16 ) ;
F_605 (dev, encoder) {
F_1000 ( V_42 ) ;
}
F_93 (dev_priv, pipe) {
V_38 = F_50 ( V_2 -> V_120 [ V_119 ] ) ;
F_997 ( V_38 ) ;
F_813 ( V_38 , V_38 -> V_115 ,
L_323 ) ;
}
F_807 ( V_16 ) ;
for ( V_50 = 0 ; V_50 < V_2 -> V_543 ; V_50 ++ ) {
struct V_133 * V_136 = & V_2 -> V_135 [ V_50 ] ;
if ( ! V_136 -> V_239 || V_136 -> V_112 )
continue;
F_153 ( L_324 , V_136 -> V_8 ) ;
V_136 -> V_244 ( V_2 , V_136 ) ;
V_136 -> V_239 = false ;
}
if ( F_13 ( V_16 ) || F_14 ( V_16 ) )
F_1009 ( V_16 ) ;
else if ( F_1010 ( V_16 ) )
F_1011 ( V_16 ) ;
else if ( F_10 ( V_16 ) )
F_1012 ( V_16 ) ;
F_140 (dev, crtc) {
unsigned long V_1308 ;
V_1308 = F_431 ( & V_38 -> V_40 , V_38 -> V_115 ) ;
if ( F_9 ( V_1308 ) )
F_433 ( V_2 , V_1308 ) ;
}
F_1013 ( V_2 , false ) ;
F_1014 ( V_2 ) ;
}
void F_284 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_185 ( V_16 ) ;
struct V_45 * V_36 = V_2 -> V_739 ;
struct V_1111 V_1112 ;
int V_306 ;
bool V_1462 = false ;
V_2 -> V_739 = NULL ;
F_2 ( & V_16 -> V_1115 . V_1118 ) ;
F_980 ( & V_1112 , 0 ) ;
V_478:
V_306 = F_981 ( V_16 , & V_1112 ) ;
if ( V_306 == 0 && ! V_1462 ) {
V_1462 = true ;
F_991 ( V_16 ) ;
F_1002 ( V_16 ) ;
}
if ( V_306 == 0 && V_36 ) {
struct V_35 * V_44 ;
struct V_111 * V_38 ;
int V_50 ;
V_36 -> V_1120 = & V_1112 ;
F_471 (state, crtc, crtc_state, i) {
V_44 -> V_1211 = true ;
}
V_306 = F_710 ( V_36 ) ;
}
if ( V_306 == - V_310 ) {
F_712 ( & V_1112 ) ;
goto V_478;
}
F_983 ( & V_1112 ) ;
F_984 ( & V_1112 ) ;
F_4 ( & V_16 -> V_1115 . V_1118 ) ;
if ( V_306 ) {
F_132 ( L_325 , V_306 ) ;
F_711 ( V_36 ) ;
}
}
void F_1015 ( struct V_15 * V_16 )
{
struct V_111 * V_357 ;
struct V_303 * V_304 ;
int V_306 ;
F_1016 ( V_16 ) ;
F_281 ( V_16 ) ;
F_1017 ( V_16 ) ;
F_222 (dev, c) {
V_304 = F_195 ( V_357 -> V_113 -> V_114 ) ;
if ( V_304 == NULL )
continue;
F_2 ( & V_16 -> V_307 ) ;
V_306 = F_194 ( V_357 -> V_113 ,
V_357 -> V_113 -> V_114 ,
V_357 -> V_113 -> V_36 ) ;
F_4 ( & V_16 -> V_307 ) ;
if ( V_306 ) {
F_132 ( L_326 ,
F_50 ( V_357 ) -> V_119 ) ;
F_216 ( V_357 -> V_113 -> V_114 ) ;
V_357 -> V_113 -> V_114 = NULL ;
V_357 -> V_113 -> V_38 = V_357 -> V_113 -> V_36 -> V_38 = NULL ;
F_215 ( V_357 -> V_113 ) ;
V_357 -> V_36 -> V_363 &= ~ ( 1 << F_224 ( V_357 -> V_113 ) ) ;
}
}
F_1018 ( V_16 ) ;
}
void F_1019 ( struct V_740 * V_740 )
{
struct V_46 * V_47 = & V_740 -> V_40 ;
F_1020 ( V_47 ) ;
F_1021 ( V_47 ) ;
}
void F_1022 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_740 * V_47 ;
F_1023 ( V_16 ) ;
F_1024 ( V_16 ) ;
F_1025 ( V_2 ) ;
F_1026 ( V_16 ) ;
F_1027 () ;
F_1028 ( V_2 ) ;
F_1029 () ;
F_808 (dev, connector)
V_47 -> V_1463 ( V_47 ) ;
F_1030 ( V_16 ) ;
F_1031 ( V_16 ) ;
F_1032 ( V_16 ) ;
F_1033 ( V_16 ) ;
}
struct V_635 * F_1034 ( struct V_46 * V_47 )
{
return & F_702 ( V_47 ) -> V_40 ;
}
void F_1035 ( struct V_740 * V_47 ,
struct V_41 * V_42 )
{
V_47 -> V_42 = V_42 ;
F_1036 ( & V_47 -> V_40 ,
& V_42 -> V_40 ) ;
}
int F_1037 ( struct V_15 * V_16 , bool V_36 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
unsigned V_9 = F_60 ( V_16 ) -> V_127 >= 6 ? V_1464 : V_1465 ;
T_7 V_1466 ;
if ( F_530 ( V_2 -> V_1467 , V_9 , & V_1466 ) ) {
F_132 ( L_327 ) ;
return - V_1207 ;
}
if ( ! ! ( V_1466 & V_1468 ) == ! V_36 )
return 0 ;
if ( V_36 )
V_1466 &= ~ V_1468 ;
else
V_1466 |= V_1468 ;
if ( F_1038 ( V_2 -> V_1467 , V_9 , V_1466 ) ) {
F_132 ( L_328 ) ;
return - V_1207 ;
}
return 0 ;
}
struct V_1469 *
F_1039 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_1469 * error ;
int V_1470 [] = {
V_256 ,
V_1471 ,
V_1472 ,
V_605 ,
} ;
int V_50 ;
if ( F_60 ( V_16 ) -> V_746 == 0 )
return NULL ;
error = F_499 ( sizeof( * error ) , V_1473 ) ;
if ( error == NULL )
return NULL ;
if ( F_240 ( V_16 ) || F_241 ( V_16 ) )
error -> V_1474 = F_11 ( V_1022 ) ;
F_93 (dev_priv, i) {
error -> V_119 [ V_50 ] . V_1475 =
F_1040 ( V_2 ,
F_428 ( V_50 ) ) ;
if ( ! error -> V_119 [ V_50 ] . V_1475 )
continue;
error -> V_1339 [ V_50 ] . V_613 = F_11 ( F_84 ( V_50 ) ) ;
error -> V_1339 [ V_50 ] . V_1476 = F_11 ( F_680 ( V_50 ) ) ;
error -> V_1339 [ V_50 ] . V_40 = F_11 ( F_677 ( V_50 ) ) ;
error -> V_170 [ V_50 ] . V_613 = F_11 ( F_90 ( V_50 ) ) ;
error -> V_170 [ V_50 ] . V_352 = F_11 ( F_233 ( V_50 ) ) ;
if ( F_60 ( V_16 ) -> V_127 <= 3 ) {
error -> V_170 [ V_50 ] . V_297 = F_11 ( F_227 ( V_50 ) ) ;
error -> V_170 [ V_50 ] . V_566 = F_11 ( F_228 ( V_50 ) ) ;
}
if ( F_60 ( V_16 ) -> V_127 <= 7 && ! F_240 ( V_16 ) )
error -> V_170 [ V_50 ] . V_1193 = F_11 ( F_237 ( V_50 ) ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
error -> V_170 [ V_50 ] . V_1477 = F_11 ( F_234 ( V_50 ) ) ;
error -> V_170 [ V_50 ] . V_1478 = F_11 ( F_235 ( V_50 ) ) ;
}
error -> V_119 [ V_50 ] . V_1479 = F_11 ( F_292 ( V_50 ) ) ;
if ( F_170 ( V_16 ) )
error -> V_119 [ V_50 ] . V_1480 = F_11 ( F_1041 ( V_50 ) ) ;
}
error -> V_1481 = F_60 ( V_16 ) -> V_746 ;
if ( F_71 ( V_2 -> V_16 ) )
error -> V_1481 ++ ;
for ( V_50 = 0 ; V_50 < error -> V_1481 ; V_50 ++ ) {
enum V_118 V_121 = V_1470 [ V_50 ] ;
error -> V_118 [ V_50 ] . V_1475 =
F_1040 ( V_2 ,
F_86 ( V_121 ) ) ;
if ( ! error -> V_118 [ V_50 ] . V_1475 )
continue;
error -> V_118 [ V_50 ] . V_121 = V_121 ;
error -> V_118 [ V_50 ] . V_1482 = F_11 ( F_61 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_919 = F_11 ( F_334 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_1483 = F_11 ( F_336 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_926 = F_11 ( F_338 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_922 = F_11 ( F_340 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_1305 = F_11 ( F_342 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_1142 = F_11 ( F_344 ( V_121 ) ) ;
}
return error ;
}
void
F_1042 ( struct V_1484 * V_79 ,
struct V_15 * V_16 ,
struct V_1469 * error )
{
struct V_1 * V_2 = V_16 -> V_17 ;
int V_50 ;
if ( ! error )
return;
F_1043 ( V_79 , L_329 , F_60 ( V_16 ) -> V_746 ) ;
if ( F_240 ( V_16 ) || F_241 ( V_16 ) )
F_1043 ( V_79 , L_330 ,
error -> V_1474 ) ;
F_93 (dev_priv, i) {
F_1043 ( V_79 , L_331 , V_50 ) ;
F_1043 ( V_79 , L_332 ,
F_66 ( error -> V_119 [ V_50 ] . V_1475 ) ) ;
F_1043 ( V_79 , L_333 , error -> V_119 [ V_50 ] . V_1479 ) ;
F_1043 ( V_79 , L_334 , error -> V_119 [ V_50 ] . V_1480 ) ;
F_1043 ( V_79 , L_335 , V_50 ) ;
F_1043 ( V_79 , L_336 , error -> V_170 [ V_50 ] . V_613 ) ;
F_1043 ( V_79 , L_337 , error -> V_170 [ V_50 ] . V_352 ) ;
if ( F_60 ( V_16 ) -> V_127 <= 3 ) {
F_1043 ( V_79 , L_338 , error -> V_170 [ V_50 ] . V_297 ) ;
F_1043 ( V_79 , L_339 , error -> V_170 [ V_50 ] . V_566 ) ;
}
if ( F_60 ( V_16 ) -> V_127 <= 7 && ! F_240 ( V_16 ) )
F_1043 ( V_79 , L_340 , error -> V_170 [ V_50 ] . V_1193 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
F_1043 ( V_79 , L_341 , error -> V_170 [ V_50 ] . V_1477 ) ;
F_1043 ( V_79 , L_342 , error -> V_170 [ V_50 ] . V_1478 ) ;
}
F_1043 ( V_79 , L_343 , V_50 ) ;
F_1043 ( V_79 , L_336 , error -> V_1339 [ V_50 ] . V_613 ) ;
F_1043 ( V_79 , L_339 , error -> V_1339 [ V_50 ] . V_1476 ) ;
F_1043 ( V_79 , L_344 , error -> V_1339 [ V_50 ] . V_40 ) ;
}
for ( V_50 = 0 ; V_50 < error -> V_1481 ; V_50 ++ ) {
F_1043 ( V_79 , L_345 ,
F_814 ( error -> V_118 [ V_50 ] . V_121 ) ) ;
F_1043 ( V_79 , L_332 ,
F_66 ( error -> V_118 [ V_50 ] . V_1475 ) ) ;
F_1043 ( V_79 , L_346 , error -> V_118 [ V_50 ] . V_1482 ) ;
F_1043 ( V_79 , L_347 , error -> V_118 [ V_50 ] . V_919 ) ;
F_1043 ( V_79 , L_348 , error -> V_118 [ V_50 ] . V_1483 ) ;
F_1043 ( V_79 , L_349 , error -> V_118 [ V_50 ] . V_926 ) ;
F_1043 ( V_79 , L_350 , error -> V_118 [ V_50 ] . V_922 ) ;
F_1043 ( V_79 , L_351 , error -> V_118 [ V_50 ] . V_1305 ) ;
F_1043 ( V_79 , L_352 , error -> V_118 [ V_50 ] . V_1142 ) ;
}
}
