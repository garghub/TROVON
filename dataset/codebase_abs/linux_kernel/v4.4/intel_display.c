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
if ( F_13 ( V_16 ) )
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
static void F_14 ( struct V_1 * V_2 )
{
if ( ! F_13 ( V_2 ) )
return;
V_2 -> V_31 = F_5 ( V_2 , L_2 ,
V_32 ) ;
F_15 ( L_3 , V_2 -> V_31 ) ;
}
static inline T_1
F_16 ( struct V_15 * V_16 )
{
if ( F_17 ( V_16 ) ) {
struct V_1 * V_2 = V_16 -> V_17 ;
return ( F_11 ( V_33 ) & V_34 ) + 2 ;
} else
return 27 ;
}
static bool
F_18 ( struct V_35 * V_36 )
{
return F_19 ( V_36 ) ;
}
bool F_20 ( struct V_37 * V_38 , enum V_39 type )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_41 * V_42 ;
F_21 (dev, &crtc->base, encoder)
if ( V_42 -> type == type )
return true ;
return false ;
}
static bool F_22 ( const struct V_43 * V_44 ,
int type )
{
struct V_45 * V_36 = V_44 -> V_40 . V_36 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_41 * V_42 ;
int V_50 , V_51 = 0 ;
F_23 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != V_44 -> V_40 . V_38 )
continue;
V_51 ++ ;
V_42 = F_24 ( V_49 -> V_52 ) ;
if ( V_42 -> type == type )
return true ;
}
F_9 ( V_51 == 0 ) ;
return false ;
}
static const T_3 *
F_25 ( struct V_43 * V_44 , int V_53 )
{
struct V_15 * V_16 = V_44 -> V_40 . V_38 -> V_16 ;
const T_3 * V_54 ;
if ( F_22 ( V_44 , V_55 ) ) {
if ( F_26 ( V_16 ) ) {
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
F_27 ( struct V_43 * V_44 )
{
struct V_15 * V_16 = V_44 -> V_40 . V_38 -> V_16 ;
const T_3 * V_54 ;
if ( F_22 ( V_44 , V_55 ) ) {
if ( F_26 ( V_16 ) )
V_54 = & V_61 ;
else
V_54 = & V_62 ;
} else if ( F_22 ( V_44 , V_63 ) ||
F_22 ( V_44 , V_64 ) ) {
V_54 = & V_65 ;
} else if ( F_22 ( V_44 , V_66 ) ) {
V_54 = & V_67 ;
} else
V_54 = & V_68 ;
return V_54 ;
}
static const T_3 *
F_28 ( struct V_43 * V_44 , int V_53 )
{
struct V_15 * V_16 = V_44 -> V_40 . V_38 -> V_16 ;
const T_3 * V_54 ;
if ( F_29 ( V_16 ) )
V_54 = & V_69 ;
else if ( F_10 ( V_16 ) )
V_54 = F_25 ( V_44 , V_53 ) ;
else if ( F_30 ( V_16 ) ) {
V_54 = F_27 ( V_44 ) ;
} else if ( F_31 ( V_16 ) ) {
if ( F_22 ( V_44 , V_55 ) )
V_54 = & V_70 ;
else
V_54 = & V_71 ;
} else if ( F_32 ( V_16 ) ) {
V_54 = & V_72 ;
} else if ( F_13 ( V_16 ) ) {
V_54 = & V_73 ;
} else if ( ! F_33 ( V_16 ) ) {
if ( F_22 ( V_44 , V_55 ) )
V_54 = & V_74 ;
else
V_54 = & V_68 ;
} else {
if ( F_22 ( V_44 , V_55 ) )
V_54 = & V_75 ;
else if ( F_22 ( V_44 , V_76 ) )
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
if ( ! F_31 ( V_16 ) && ! F_13 ( V_16 ) && ! F_29 ( V_16 ) )
if ( clock -> V_88 <= clock -> V_80 )
F_41 ( L_8 ) ;
if ( ! F_13 ( V_16 ) && ! F_29 ( V_16 ) ) {
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
if ( F_22 ( V_44 , V_55 ) ) {
if ( F_26 ( V_16 ) )
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
if ( F_32 ( V_16 ) ) {
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
return F_51 ( F_28 ( V_44 , V_53 ) , V_44 ,
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
T_1 V_9 = F_57 ( V_119 ) ;
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
int V_9 = F_61 ( V_121 ) ;
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
int V_146 ;
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
} else if ( F_13 ( V_16 ) ) {
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
if ( ( V_119 == V_148 && V_2 -> V_165 & V_166 ) ||
( V_119 == V_157 && V_2 -> V_165 & V_167 ) )
V_36 = true ;
if ( ! F_86 ( V_2 ,
F_87 ( V_121 ) ) ) {
V_130 = false ;
} else {
T_1 V_10 = F_11 ( F_61 ( V_121 ) ) ;
V_130 = ! ! ( V_10 & V_168 ) ;
}
F_66 ( V_130 != V_36 ,
L_26 ,
F_80 ( V_119 ) , F_63 ( V_36 ) , F_63 ( V_130 ) ) ;
}
static void F_88 ( struct V_1 * V_2 ,
enum V_169 V_169 , bool V_36 )
{
T_1 V_10 ;
bool V_130 ;
V_10 = F_11 ( F_89 ( V_169 ) ) ;
V_130 = ! ! ( V_10 & V_170 ) ;
F_66 ( V_130 != V_36 ,
L_27 ,
F_90 ( V_169 ) , F_63 ( V_36 ) , F_63 ( V_130 ) ) ;
}
static void F_91 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_50 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
T_1 V_10 = F_11 ( F_89 ( V_119 ) ) ;
F_66 ( V_10 & V_170 ,
L_28 ,
F_90 ( V_119 ) ) ;
return;
}
F_92 (dev_priv, i) {
T_1 V_10 = F_11 ( F_89 ( V_50 ) ) ;
enum V_119 V_171 = ( V_10 & V_172 ) >>
V_173 ;
F_66 ( ( V_10 & V_170 ) && V_119 == V_171 ,
L_29 ,
F_90 ( V_50 ) , F_80 ( V_119 ) ) ;
}
}
static void F_93 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_174 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
F_94 (dev_priv, pipe, sprite) {
T_1 V_10 = F_11 ( F_95 ( V_119 , V_174 ) ) ;
F_66 ( V_10 & V_175 ,
L_30 ,
V_174 , F_80 ( V_119 ) ) ;
}
} else if ( F_13 ( V_16 ) ) {
F_94 (dev_priv, pipe, sprite) {
T_1 V_10 = F_11 ( F_96 ( V_119 , V_174 ) ) ;
F_66 ( V_10 & V_176 ,
L_31 ,
F_97 ( V_119 , V_174 ) , F_80 ( V_119 ) ) ;
}
} else if ( F_60 ( V_16 ) -> V_127 >= 7 ) {
T_1 V_10 = F_11 ( F_98 ( V_119 ) ) ;
F_66 ( V_10 & V_177 ,
L_31 ,
F_90 ( V_119 ) , F_80 ( V_119 ) ) ;
} else if ( F_60 ( V_16 ) -> V_127 >= 5 ) {
T_1 V_10 = F_11 ( F_99 ( V_119 ) ) ;
F_66 ( V_10 & V_178 ,
L_31 ,
F_90 ( V_119 ) , F_80 ( V_119 ) ) ;
}
}
static void F_100 ( struct V_111 * V_38 )
{
if ( F_101 ( F_102 ( V_38 ) == 0 ) )
F_103 ( V_38 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
T_1 V_10 ;
bool V_129 ;
F_101 ( ! ( F_105 ( V_2 -> V_16 ) || F_106 ( V_2 -> V_16 ) ) ) ;
V_10 = F_11 ( V_179 ) ;
V_129 = ! ! ( V_10 & ( V_180 | V_181 |
V_182 ) ) ;
F_66 ( ! V_129 , L_32 ) ;
}
static void F_107 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
T_1 V_10 ;
bool V_129 ;
V_10 = F_11 ( F_108 ( V_119 ) ) ;
V_129 = ! ! ( V_10 & V_183 ) ;
F_66 ( V_129 ,
L_33 ,
F_80 ( V_119 ) ) ;
}
static bool F_109 ( struct V_1 * V_2 ,
enum V_119 V_119 , T_1 V_150 , T_1 V_10 )
{
if ( ( V_10 & V_184 ) == 0 )
return false ;
if ( F_106 ( V_2 -> V_16 ) ) {
T_1 V_185 = F_110 ( V_119 ) ;
T_1 V_186 = F_11 ( V_185 ) ;
if ( ( V_186 & V_187 ) != V_150 )
return false ;
} else if ( F_32 ( V_2 -> V_16 ) ) {
if ( ( V_10 & V_188 ) != F_111 ( V_119 ) )
return false ;
} else {
if ( ( V_10 & V_189 ) != ( V_119 << 30 ) )
return false ;
}
return true ;
}
static bool F_112 ( struct V_1 * V_2 ,
enum V_119 V_119 , T_1 V_10 )
{
if ( ( V_10 & V_190 ) == 0 )
return false ;
if ( F_106 ( V_2 -> V_16 ) ) {
if ( ( V_10 & V_191 ) != F_113 ( V_119 ) )
return false ;
} else if ( F_32 ( V_2 -> V_16 ) ) {
if ( ( V_10 & V_192 ) != F_114 ( V_119 ) )
return false ;
} else {
if ( ( V_10 & V_193 ) != F_115 ( V_119 ) )
return false ;
}
return true ;
}
static bool F_116 ( struct V_1 * V_2 ,
enum V_119 V_119 , T_1 V_10 )
{
if ( ( V_10 & V_194 ) == 0 )
return false ;
if ( F_106 ( V_2 -> V_16 ) ) {
if ( ( V_10 & V_195 ) != F_117 ( V_119 ) )
return false ;
} else {
if ( ( V_10 & V_196 ) != F_118 ( V_119 ) )
return false ;
}
return true ;
}
static bool F_119 ( struct V_1 * V_2 ,
enum V_119 V_119 , T_1 V_10 )
{
if ( ( V_10 & V_197 ) == 0 )
return false ;
if ( F_106 ( V_2 -> V_16 ) ) {
if ( ( V_10 & V_195 ) != F_117 ( V_119 ) )
return false ;
} else {
if ( ( V_10 & V_198 ) != F_120 ( V_119 ) )
return false ;
}
return true ;
}
static void F_121 ( struct V_1 * V_2 ,
enum V_119 V_119 , int V_9 , T_1 V_150 )
{
T_1 V_10 = F_11 ( V_9 ) ;
F_66 ( F_109 ( V_2 , V_119 , V_150 , V_10 ) ,
L_34 ,
V_9 , F_80 ( V_119 ) ) ;
F_66 ( F_105 ( V_2 -> V_16 ) && ( V_10 & V_184 ) == 0
&& ( V_10 & V_199 ) ,
L_35 ) ;
}
static void F_122 ( struct V_1 * V_2 ,
enum V_119 V_119 , int V_9 )
{
T_1 V_10 = F_11 ( V_9 ) ;
F_66 ( F_112 ( V_2 , V_119 , V_10 ) ,
L_36 ,
V_9 , F_80 ( V_119 ) ) ;
F_66 ( F_105 ( V_2 -> V_16 ) && ( V_10 & V_190 ) == 0
&& ( V_10 & V_200 ) ,
L_37 ) ;
}
static void F_123 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
T_1 V_10 ;
F_121 ( V_2 , V_119 , V_201 , V_202 ) ;
F_121 ( V_2 , V_119 , V_203 , V_204 ) ;
F_121 ( V_2 , V_119 , V_205 , V_206 ) ;
V_10 = F_11 ( V_207 ) ;
F_66 ( F_119 ( V_2 , V_119 , V_10 ) ,
L_38 ,
F_80 ( V_119 ) ) ;
V_10 = F_11 ( V_155 ) ;
F_66 ( F_116 ( V_2 , V_119 , V_10 ) ,
L_39 ,
F_80 ( V_119 ) ) ;
F_122 ( V_2 , V_119 , V_208 ) ;
F_122 ( V_2 , V_119 , V_209 ) ;
F_122 ( V_2 , V_119 , V_210 ) ;
}
static void F_124 ( struct V_37 * V_38 ,
const struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_9 = F_65 ( V_38 -> V_119 ) ;
T_1 V_87 = V_211 -> V_212 . V_87 ;
F_125 ( V_2 , V_38 -> V_119 ) ;
F_126 ( ! F_13 ( V_2 -> V_16 ) ) ;
if ( F_127 ( V_2 -> V_16 ) )
F_78 ( V_2 , V_38 -> V_119 ) ;
F_128 ( V_9 , V_87 ) ;
F_129 ( V_9 ) ;
F_130 ( 150 ) ;
if ( F_62 ( ( ( F_11 ( V_9 ) & V_213 ) == V_213 ) , 1 ) )
F_131 ( L_40 , V_38 -> V_119 ) ;
F_128 ( F_132 ( V_38 -> V_119 ) , V_211 -> V_212 . V_214 ) ;
F_129 ( F_132 ( V_38 -> V_119 ) ) ;
F_128 ( V_9 , V_87 ) ;
F_129 ( V_9 ) ;
F_130 ( 150 ) ;
F_128 ( V_9 , V_87 ) ;
F_129 ( V_9 ) ;
F_130 ( 150 ) ;
F_128 ( V_9 , V_87 ) ;
F_129 ( V_9 ) ;
F_130 ( 150 ) ;
}
static void F_133 ( struct V_37 * V_38 ,
const struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
enum V_215 V_216 = F_134 ( V_119 ) ;
T_1 V_217 ;
F_125 ( V_2 , V_38 -> V_119 ) ;
F_126 ( ! F_32 ( V_2 -> V_16 ) ) ;
F_2 ( & V_2 -> V_5 ) ;
V_217 = F_135 ( V_2 , V_119 , F_136 ( V_216 ) ) ;
V_217 |= V_218 ;
F_137 ( V_2 , V_119 , F_136 ( V_216 ) , V_217 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_130 ( 1 ) ;
F_128 ( F_65 ( V_119 ) , V_211 -> V_212 . V_87 ) ;
if ( F_62 ( ( ( F_11 ( F_65 ( V_119 ) ) & V_213 ) == V_213 ) , 1 ) )
F_131 ( L_41 , V_119 ) ;
F_128 ( F_132 ( V_119 ) , V_211 -> V_212 . V_214 ) ;
F_129 ( F_132 ( V_119 ) ) ;
}
static int F_138 ( struct V_15 * V_16 )
{
struct V_37 * V_38 ;
int V_219 = 0 ;
F_139 (dev, crtc)
V_219 += V_38 -> V_40 . V_36 -> V_112 &&
F_20 ( V_38 , V_76 ) ;
return V_219 ;
}
static void F_140 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_9 = F_65 ( V_38 -> V_119 ) ;
T_1 V_87 = V_38 -> V_115 -> V_212 . V_87 ;
F_125 ( V_2 , V_38 -> V_119 ) ;
F_126 ( F_60 ( V_16 ) -> V_127 >= 5 ) ;
if ( F_127 ( V_16 ) && ! F_141 ( V_16 ) )
F_78 ( V_2 , V_38 -> V_119 ) ;
if ( F_141 ( V_16 ) && F_138 ( V_16 ) > 0 ) {
V_87 |= V_220 ;
F_128 ( F_65 ( ! V_38 -> V_119 ) ,
F_11 ( F_65 ( ! V_38 -> V_119 ) ) | V_220 ) ;
}
F_128 ( V_9 , 0 ) ;
F_128 ( V_9 , V_87 ) ;
F_129 ( V_9 ) ;
F_130 ( 150 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
F_128 ( F_132 ( V_38 -> V_119 ) ,
V_38 -> V_115 -> V_212 . V_214 ) ;
} else {
F_128 ( V_9 , V_87 ) ;
}
F_128 ( V_9 , V_87 ) ;
F_129 ( V_9 ) ;
F_130 ( 150 ) ;
F_128 ( V_9 , V_87 ) ;
F_129 ( V_9 ) ;
F_130 ( 150 ) ;
F_128 ( V_9 , V_87 ) ;
F_129 ( V_9 ) ;
F_130 ( 150 ) ;
}
static void F_142 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 = V_38 -> V_119 ;
if ( F_141 ( V_16 ) &&
F_20 ( V_38 , V_76 ) &&
! F_138 ( V_16 ) ) {
F_128 ( F_65 ( V_157 ) ,
F_11 ( F_65 ( V_157 ) ) & ~ V_220 ) ;
F_128 ( F_65 ( V_148 ) ,
F_11 ( F_65 ( V_148 ) ) & ~ V_220 ) ;
}
if ( ( V_119 == V_148 && V_2 -> V_165 & V_166 ) ||
( V_119 == V_157 && V_2 -> V_165 & V_167 ) )
return;
F_125 ( V_2 , V_119 ) ;
F_128 ( F_65 ( V_119 ) , V_221 ) ;
F_129 ( F_65 ( V_119 ) ) ;
}
static void F_143 ( struct V_1 * V_2 , enum V_119 V_119 )
{
T_1 V_10 ;
F_125 ( V_2 , V_119 ) ;
V_10 = V_221 ;
if ( V_119 == V_157 )
V_10 = V_222 | V_223 ;
F_128 ( F_65 ( V_119 ) , V_10 ) ;
F_129 ( F_65 ( V_119 ) ) ;
}
static void F_144 ( struct V_1 * V_2 , enum V_119 V_119 )
{
enum V_215 V_216 = F_134 ( V_119 ) ;
T_1 V_10 ;
F_125 ( V_2 , V_119 ) ;
V_10 = V_224 |
V_223 | V_221 ;
if ( V_119 != V_148 )
V_10 |= V_222 ;
F_128 ( F_65 ( V_119 ) , V_10 ) ;
F_129 ( F_65 ( V_119 ) ) ;
F_2 ( & V_2 -> V_5 ) ;
V_10 = F_135 ( V_2 , V_119 , F_136 ( V_216 ) ) ;
V_10 &= ~ V_218 ;
F_137 ( V_2 , V_119 , F_136 ( V_216 ) , V_10 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
void F_145 ( struct V_1 * V_2 ,
struct V_225 * V_226 ,
unsigned int V_227 )
{
T_1 V_228 ;
int V_229 ;
switch ( V_226 -> V_216 ) {
case V_230 :
V_228 = V_231 ;
V_229 = F_65 ( 0 ) ;
break;
case V_232 :
V_228 = V_233 ;
V_229 = F_65 ( 0 ) ;
V_227 <<= 4 ;
break;
case V_234 :
V_228 = V_235 ;
V_229 = V_236 ;
break;
default:
F_146 () ;
}
if ( F_62 ( ( F_11 ( V_229 ) & V_228 ) == V_227 , 1000 ) )
F_6 ( 1 , L_42 ,
F_147 ( V_226 -> V_216 ) , F_11 ( V_229 ) & V_228 , V_227 ) ;
}
static void F_148 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_134 * V_137 = F_68 ( V_38 ) ;
if ( F_9 ( V_137 == NULL ) )
return;
F_9 ( ! V_137 -> V_115 . V_237 ) ;
if ( V_137 -> V_112 == 0 ) {
F_15 ( L_43 , V_137 -> V_8 ) ;
F_9 ( V_137 -> V_238 ) ;
F_149 ( V_2 , V_137 ) ;
V_137 -> V_239 ( V_2 , V_137 ) ;
}
}
static void F_150 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_134 * V_137 = F_68 ( V_38 ) ;
if ( F_9 ( V_137 == NULL ) )
return;
if ( F_9 ( V_137 -> V_115 . V_237 == 0 ) )
return;
F_151 ( L_44 ,
V_137 -> V_8 , V_137 -> V_112 , V_137 -> V_238 ,
V_38 -> V_40 . V_40 . V_240 ) ;
if ( V_137 -> V_112 ++ ) {
F_9 ( ! V_137 -> V_238 ) ;
F_152 ( V_2 , V_137 ) ;
return;
}
F_9 ( V_137 -> V_238 ) ;
F_153 ( V_2 , V_241 ) ;
F_151 ( L_45 , V_137 -> V_8 ) ;
V_137 -> V_242 ( V_2 , V_137 ) ;
V_137 -> V_238 = true ;
}
static void F_154 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_134 * V_137 = F_68 ( V_38 ) ;
if ( F_60 ( V_16 ) -> V_127 < 5 )
return;
if ( V_137 == NULL )
return;
if ( F_9 ( ! ( V_137 -> V_115 . V_237 & ( 1 << F_155 ( & V_38 -> V_40 ) ) ) ) )
return;
F_151 ( L_46 ,
V_137 -> V_8 , V_137 -> V_112 , V_137 -> V_238 ,
V_38 -> V_40 . V_40 . V_240 ) ;
if ( F_9 ( V_137 -> V_112 == 0 ) ) {
F_149 ( V_2 , V_137 ) ;
return;
}
F_152 ( V_2 , V_137 ) ;
F_9 ( ! V_137 -> V_238 ) ;
if ( -- V_137 -> V_112 )
return;
F_151 ( L_47 , V_137 -> V_8 ) ;
V_137 -> V_243 ( V_2 , V_137 ) ;
V_137 -> V_238 = false ;
F_156 ( V_2 , V_241 ) ;
}
static void F_157 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_111 * V_38 = V_2 -> V_120 [ V_119 ] ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_2 V_9 , V_10 , V_244 ;
F_126 ( ! F_10 ( V_16 ) ) ;
F_152 ( V_2 ,
F_68 ( V_37 ) ) ;
F_158 ( V_2 , V_119 ) ;
F_159 ( V_2 , V_119 ) ;
if ( F_106 ( V_16 ) ) {
V_9 = F_160 ( V_119 ) ;
V_10 = F_11 ( V_9 ) ;
V_10 |= V_245 ;
F_128 ( V_9 , V_10 ) ;
}
V_9 = F_108 ( V_119 ) ;
V_10 = F_11 ( V_9 ) ;
V_244 = F_11 ( F_61 ( V_119 ) ) ;
if ( F_105 ( V_2 -> V_16 ) ) {
V_10 &= ~ V_246 ;
if ( F_20 ( V_37 , V_63 ) )
V_10 |= V_247 ;
else
V_10 |= V_244 & V_246 ;
}
V_10 &= ~ V_248 ;
if ( ( V_244 & V_249 ) == V_250 )
if ( F_105 ( V_2 -> V_16 ) &&
F_20 ( V_37 , V_66 ) )
V_10 |= V_251 ;
else
V_10 |= V_252 ;
else
V_10 |= V_253 ;
F_128 ( V_9 , V_10 | V_183 ) ;
if ( F_62 ( F_11 ( V_9 ) & V_254 , 100 ) )
F_131 ( L_48 , F_80 ( V_119 ) ) ;
}
static void F_161 ( struct V_1 * V_2 ,
enum V_118 V_121 )
{
T_1 V_10 , V_244 ;
F_126 ( ! F_10 ( V_2 -> V_16 ) ) ;
F_158 ( V_2 , (enum V_119 ) V_121 ) ;
F_159 ( V_2 , V_255 ) ;
V_10 = F_11 ( F_160 ( V_148 ) ) ;
V_10 |= V_245 ;
F_128 ( F_160 ( V_148 ) , V_10 ) ;
V_10 = V_183 ;
V_244 = F_11 ( F_61 ( V_121 ) ) ;
if ( ( V_244 & V_256 ) ==
V_250 )
V_10 |= V_252 ;
else
V_10 |= V_253 ;
F_128 ( V_257 , V_10 ) ;
if ( F_62 ( F_11 ( V_257 ) & V_254 , 100 ) )
F_131 ( L_49 ) ;
}
static void F_162 ( struct V_1 * V_2 ,
enum V_119 V_119 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_9 , V_10 ;
F_163 ( V_2 , V_119 ) ;
F_164 ( V_2 , V_119 ) ;
F_123 ( V_2 , V_119 ) ;
V_9 = F_108 ( V_119 ) ;
V_10 = F_11 ( V_9 ) ;
V_10 &= ~ V_183 ;
F_128 ( V_9 , V_10 ) ;
if ( F_62 ( ( F_11 ( V_9 ) & V_254 ) == 0 , 50 ) )
F_131 ( L_50 , F_80 ( V_119 ) ) ;
if ( ! F_105 ( V_16 ) ) {
V_9 = F_160 ( V_119 ) ;
V_10 = F_11 ( V_9 ) ;
V_10 &= ~ V_245 ;
F_128 ( V_9 , V_10 ) ;
}
}
static void F_165 ( struct V_1 * V_2 )
{
T_1 V_10 ;
V_10 = F_11 ( V_257 ) ;
V_10 &= ~ V_183 ;
F_128 ( V_257 , V_10 ) ;
if ( F_62 ( ( F_11 ( V_257 ) & V_254 ) == 0 , 50 ) )
F_131 ( L_51 ) ;
V_10 = F_11 ( F_160 ( V_148 ) ) ;
V_10 &= ~ V_245 ;
F_128 ( F_160 ( V_148 ) , V_10 ) ;
}
static void F_166 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 = V_38 -> V_119 ;
enum V_118 V_121 = F_55 ( V_2 ,
V_119 ) ;
enum V_119 V_258 ;
int V_9 ;
T_1 V_10 ;
F_151 ( L_52 , F_80 ( V_119 ) ) ;
F_91 ( V_2 , V_119 ) ;
F_167 ( V_2 , V_119 ) ;
F_93 ( V_2 , V_119 ) ;
if ( F_168 ( V_2 -> V_16 ) )
V_258 = V_255 ;
else
V_258 = V_119 ;
if ( F_169 ( V_2 -> V_16 ) )
if ( F_20 ( V_38 , V_259 ) )
F_170 ( V_2 ) ;
else
F_171 ( V_2 , V_119 ) ;
else {
if ( V_38 -> V_115 -> V_260 ) {
F_172 ( V_2 , V_258 ) ;
F_76 ( V_2 ,
(enum V_119 ) V_121 ) ;
}
}
V_9 = F_61 ( V_121 ) ;
V_10 = F_11 ( V_9 ) ;
if ( V_10 & V_168 ) {
F_9 ( ! ( ( V_119 == V_148 && V_2 -> V_165 & V_166 ) ||
( V_119 == V_157 && V_2 -> V_165 & V_167 ) ) ) ;
return;
}
F_128 ( V_9 , V_10 | V_168 ) ;
F_129 ( V_9 ) ;
}
static void F_173 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_40 . V_16 -> V_17 ;
enum V_118 V_121 = V_38 -> V_115 -> V_121 ;
enum V_119 V_119 = V_38 -> V_119 ;
int V_9 ;
T_1 V_10 ;
F_151 ( L_53 , F_80 ( V_119 ) ) ;
F_91 ( V_2 , V_119 ) ;
F_167 ( V_2 , V_119 ) ;
F_93 ( V_2 , V_119 ) ;
V_9 = F_61 ( V_121 ) ;
V_10 = F_11 ( V_9 ) ;
if ( ( V_10 & V_168 ) == 0 )
return;
if ( V_38 -> V_115 -> V_261 )
V_10 &= ~ V_262 ;
if ( ! ( V_119 == V_148 && V_2 -> V_165 & V_166 ) &&
! ( V_119 == V_157 && V_2 -> V_165 & V_167 ) )
V_10 &= ~ V_168 ;
F_128 ( V_9 , V_10 ) ;
if ( ( V_10 & V_168 ) == 0 )
F_59 ( V_38 ) ;
}
static bool F_174 ( struct V_15 * V_16 )
{
#ifdef F_175
if ( F_60 ( V_16 ) -> V_127 >= 6 && V_263 )
return true ;
#endif
return false ;
}
unsigned int
F_176 ( struct V_15 * V_16 , T_2 V_264 ,
V_89 V_265 , unsigned int V_169 )
{
unsigned int V_266 ;
T_2 V_267 ;
switch ( V_265 ) {
case V_268 :
V_266 = 1 ;
break;
case V_269 :
V_266 = F_33 ( V_16 ) ? 16 : 8 ;
break;
case V_270 :
V_266 = 32 ;
break;
case V_271 :
V_267 = F_177 ( V_264 , V_169 ) ;
switch ( V_267 ) {
default:
case 1 :
V_266 = 64 ;
break;
case 2 :
case 4 :
V_266 = 32 ;
break;
case 8 :
V_266 = 16 ;
break;
case 16 :
F_178 ( 1 ,
L_54 ) ;
V_266 = 16 ;
break;
}
break;
default:
F_179 ( V_265 ) ;
V_266 = 1 ;
break;
}
return V_266 ;
}
unsigned int
F_180 ( struct V_15 * V_16 , unsigned int V_272 ,
T_2 V_264 , V_89 V_265 )
{
return F_181 ( V_272 , F_176 ( V_16 , V_264 ,
V_265 , 0 ) ) ;
}
static int
F_182 ( struct V_273 * V_274 , struct V_275 * V_114 ,
const struct V_276 * V_277 )
{
struct V_278 * V_279 = & V_274 -> V_280 ;
unsigned int V_266 , V_281 ;
* V_274 = V_282 ;
if ( ! V_277 )
return 0 ;
if ( ! F_183 ( V_277 -> V_283 ) )
return 0 ;
* V_274 = V_284 ;
V_279 -> V_272 = V_114 -> V_272 ;
V_279 -> V_264 = V_114 -> V_264 ;
V_279 -> V_285 = V_114 -> V_286 [ 0 ] ;
V_279 -> V_287 = V_114 -> V_288 [ 1 ] ;
V_279 -> V_289 = V_114 -> V_290 [ 0 ] ;
V_266 = F_176 ( V_114 -> V_16 , V_114 -> V_264 ,
V_114 -> V_290 [ 0 ] , 0 ) ;
V_281 = V_291 / V_266 ;
V_279 -> V_292 = F_184 ( V_114 -> V_286 [ 0 ] , V_281 ) ;
V_279 -> V_293 = F_184 ( V_114 -> V_272 , V_266 ) ;
V_279 -> V_294 = V_279 -> V_292 * V_279 -> V_293 * V_291 ;
if ( V_279 -> V_264 == V_295 ) {
V_266 = F_176 ( V_114 -> V_16 , V_114 -> V_264 ,
V_114 -> V_290 [ 0 ] , 1 ) ;
V_281 = V_291 / V_266 ;
V_279 -> V_296 = F_184 ( V_114 -> V_286 [ 0 ] , V_281 ) ;
V_279 -> V_297 = F_184 ( V_114 -> V_272 / 2 ,
V_266 ) ;
V_279 -> V_298 = V_279 -> V_296 * V_279 -> V_297 *
V_291 ;
}
return 0 ;
}
static unsigned int F_185 ( struct V_1 * V_2 )
{
if ( F_60 ( V_2 ) -> V_127 >= 9 )
return 256 * 1024 ;
else if ( F_186 ( V_2 ) || F_187 ( V_2 ) ||
F_13 ( V_2 ) )
return 128 * 1024 ;
else if ( F_60 ( V_2 ) -> V_127 >= 4 )
return 4 * 1024 ;
else
return 0 ;
}
int
F_188 ( struct V_299 * V_169 ,
struct V_275 * V_114 ,
const struct V_276 * V_277 ,
struct V_300 * V_301 ,
struct V_302 * * V_303 )
{
struct V_15 * V_16 = V_114 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_304 * V_305 = F_189 ( V_114 ) ;
struct V_273 V_274 ;
T_1 V_306 ;
int V_307 ;
F_9 ( ! F_190 ( & V_16 -> V_308 ) ) ;
switch ( V_114 -> V_290 [ 0 ] ) {
case V_268 :
V_306 = F_185 ( V_2 ) ;
break;
case V_269 :
if ( F_60 ( V_16 ) -> V_127 >= 9 )
V_306 = 256 * 1024 ;
else {
V_306 = 0 ;
}
break;
case V_270 :
case V_271 :
if ( F_178 ( F_60 ( V_16 ) -> V_127 < 9 ,
L_55 ) )
return - V_309 ;
V_306 = 1 * 1024 * 1024 ;
break;
default:
F_179 ( V_114 -> V_290 [ 0 ] ) ;
return - V_309 ;
}
V_307 = F_182 ( & V_274 , V_114 , V_277 ) ;
if ( V_307 )
return V_307 ;
if ( F_174 ( V_16 ) && V_306 < 256 * 1024 )
V_306 = 256 * 1024 ;
F_191 ( V_2 ) ;
V_2 -> V_310 . V_311 = false ;
V_307 = F_192 ( V_305 , V_306 , V_301 ,
V_303 , & V_274 ) ;
if ( V_307 )
goto V_312;
if ( V_274 . type == V_313 ) {
V_307 = F_193 ( V_305 ) ;
if ( V_307 == - V_314 ) {
V_307 = - V_315 ;
goto V_316;
} else if ( V_307 )
goto V_316;
F_194 ( V_305 ) ;
}
V_2 -> V_310 . V_311 = true ;
F_195 ( V_2 ) ;
return 0 ;
V_316:
F_196 ( V_305 , & V_274 ) ;
V_312:
V_2 -> V_310 . V_311 = true ;
F_195 ( V_2 ) ;
return V_307 ;
}
static void F_197 ( struct V_275 * V_114 ,
const struct V_276 * V_277 )
{
struct V_304 * V_305 = F_189 ( V_114 ) ;
struct V_273 V_274 ;
int V_307 ;
F_9 ( ! F_190 ( & V_305 -> V_40 . V_16 -> V_308 ) ) ;
V_307 = F_182 ( & V_274 , V_114 , V_277 ) ;
F_178 ( V_307 , L_56 ) ;
if ( V_274 . type == V_313 )
F_198 ( V_305 ) ;
F_196 ( V_305 , & V_274 ) ;
}
unsigned long F_199 ( struct V_1 * V_2 ,
int * V_317 , int * V_318 ,
unsigned int V_319 ,
unsigned int V_320 ,
unsigned int V_285 )
{
if ( V_319 != V_321 ) {
unsigned int V_322 , V_323 ;
V_322 = * V_318 / 8 ;
* V_318 %= 8 ;
V_323 = * V_317 / ( 512 / V_320 ) ;
* V_317 %= 512 / V_320 ;
return V_322 * V_285 * 8 + V_323 * 4096 ;
} else {
unsigned int V_306 = F_185 ( V_2 ) - 1 ;
unsigned int V_324 ;
V_324 = * V_318 * V_285 + * V_317 * V_320 ;
* V_318 = ( V_324 & V_306 ) / V_285 ;
* V_317 = ( ( V_324 & V_306 ) - * V_318 * V_285 ) / V_320 ;
return V_324 & ~ V_306 ;
}
}
static int F_200 ( int V_325 )
{
switch ( V_325 ) {
case V_326 :
return V_327 ;
case V_328 :
return V_329 ;
case V_330 :
return V_331 ;
default:
case V_332 :
return V_333 ;
case V_334 :
return V_335 ;
case V_336 :
return V_337 ;
case V_338 :
return V_339 ;
}
}
static int F_201 ( int V_325 , bool V_340 , bool V_341 )
{
switch ( V_325 ) {
case V_342 :
return V_331 ;
default:
case V_343 :
if ( V_340 ) {
if ( V_341 )
return V_344 ;
else
return V_335 ;
} else {
if ( V_341 )
return V_345 ;
else
return V_333 ;
}
case V_346 :
if ( V_340 )
return V_339 ;
else
return V_337 ;
}
}
static bool
F_202 ( struct V_37 * V_38 ,
struct V_347 * V_348 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = F_203 ( V_16 ) ;
struct V_304 * V_305 = NULL ;
struct V_349 V_350 = { 0 } ;
struct V_275 * V_114 = & V_348 -> V_114 -> V_40 ;
T_1 V_351 = F_204 ( V_348 -> V_40 , V_291 ) ;
T_1 V_352 = F_205 ( V_348 -> V_40 + V_348 -> V_294 ,
V_291 ) ;
V_352 -= V_351 ;
if ( V_348 -> V_294 == 0 )
return false ;
if ( V_352 * 2 > V_2 -> V_353 . V_354 )
return false ;
V_305 = F_206 ( V_16 ,
V_351 ,
V_351 ,
V_352 ) ;
if ( ! V_305 )
return false ;
V_305 -> V_319 = V_348 -> V_355 ;
if ( V_305 -> V_319 == V_356 )
V_305 -> V_357 = V_114 -> V_286 [ 0 ] ;
V_350 . V_264 = V_114 -> V_264 ;
V_350 . V_358 = V_114 -> V_358 ;
V_350 . V_272 = V_114 -> V_272 ;
V_350 . V_286 [ 0 ] = V_114 -> V_286 [ 0 ] ;
V_350 . V_290 [ 0 ] = V_114 -> V_290 [ 0 ] ;
V_350 . V_359 = V_360 ;
F_2 ( & V_16 -> V_308 ) ;
if ( F_207 ( V_16 , F_208 ( V_114 ) ,
& V_350 , V_305 ) ) {
F_151 ( L_57 ) ;
goto V_361;
}
F_4 ( & V_16 -> V_308 ) ;
F_151 ( L_58 , V_305 ) ;
return true ;
V_361:
F_209 ( & V_305 -> V_40 ) ;
F_4 ( & V_16 -> V_308 ) ;
return false ;
}
static void
F_210 ( struct V_299 * V_169 )
{
if ( V_169 -> V_114 == V_169 -> V_36 -> V_114 )
return;
if ( V_169 -> V_36 -> V_114 )
F_211 ( V_169 -> V_36 -> V_114 ) ;
V_169 -> V_36 -> V_114 = V_169 -> V_114 ;
if ( V_169 -> V_36 -> V_114 )
F_212 ( V_169 -> V_36 -> V_114 ) ;
}
static void
F_213 ( struct V_37 * V_37 ,
struct V_347 * V_348 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_111 * V_362 ;
struct V_37 * V_50 ;
struct V_304 * V_305 ;
struct V_299 * V_113 = V_37 -> V_40 . V_113 ;
struct V_276 * V_277 = V_113 -> V_36 ;
struct V_35 * V_44 = V_37 -> V_40 . V_36 ;
struct V_363 * V_363 = F_214 ( V_113 ) ;
struct V_275 * V_114 ;
if ( ! V_348 -> V_114 )
return;
if ( F_202 ( V_37 , V_348 ) ) {
V_114 = & V_348 -> V_114 -> V_40 ;
goto V_364;
}
F_215 ( V_348 -> V_114 ) ;
F_216 (dev, c) {
V_50 = F_50 ( V_362 ) ;
if ( V_362 == & V_37 -> V_40 )
continue;
if ( ! V_50 -> V_112 )
continue;
V_114 = V_362 -> V_113 -> V_114 ;
if ( ! V_114 )
continue;
V_305 = F_189 ( V_114 ) ;
if ( F_217 ( V_305 ) == V_348 -> V_40 ) {
F_212 ( V_114 ) ;
goto V_364;
}
}
F_218 ( V_277 ) -> V_365 = false ;
V_44 -> V_366 &= ~ ( 1 << F_219 ( V_113 ) ) ;
F_220 ( & V_37 -> V_40 ) ;
V_363 -> V_367 ( V_113 , & V_37 -> V_40 ) ;
return;
V_364:
V_277 -> V_368 = 0 ;
V_277 -> V_369 = 0 ;
V_277 -> V_370 = V_114 -> V_358 << 16 ;
V_277 -> V_371 = V_114 -> V_272 << 16 ;
V_277 -> V_372 = 0 ;
V_277 -> V_373 = 0 ;
V_277 -> V_374 = V_114 -> V_358 ;
V_277 -> V_375 = V_114 -> V_272 ;
V_305 = F_189 ( V_114 ) ;
if ( V_305 -> V_319 != V_321 )
V_2 -> V_376 = true ;
F_212 ( V_114 ) ;
V_113 -> V_114 = V_113 -> V_36 -> V_114 = V_114 ;
V_113 -> V_38 = V_113 -> V_36 -> V_38 = & V_37 -> V_40 ;
V_37 -> V_40 . V_36 -> V_366 |= ( 1 << F_219 ( V_113 ) ) ;
V_305 -> V_377 |= F_214 ( V_113 ) -> V_378 ;
}
static void F_221 ( struct V_111 * V_38 ,
struct V_275 * V_114 ,
int V_317 , int V_318 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_299 * V_113 = V_38 -> V_113 ;
bool V_365 = F_218 ( V_113 -> V_36 ) -> V_365 ;
struct V_304 * V_305 ;
int V_169 = V_37 -> V_169 ;
unsigned long V_379 ;
T_1 V_380 ;
T_1 V_9 = F_89 ( V_169 ) ;
int V_381 ;
if ( ! V_365 || ! V_114 ) {
F_128 ( V_9 , 0 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 )
F_128 ( F_222 ( V_169 ) , 0 ) ;
else
F_128 ( F_223 ( V_169 ) , 0 ) ;
F_129 ( V_9 ) ;
return;
}
V_305 = F_189 ( V_114 ) ;
if ( F_9 ( V_305 == NULL ) )
return;
V_381 = F_177 ( V_114 -> V_264 , 0 ) ;
V_380 = V_382 ;
V_380 |= V_170 ;
if ( F_60 ( V_16 ) -> V_127 < 4 ) {
if ( V_37 -> V_119 == V_157 )
V_380 |= V_383 ;
F_128 ( F_224 ( V_169 ) ,
( ( V_37 -> V_115 -> V_384 - 1 ) << 16 ) |
( V_37 -> V_115 -> V_385 - 1 ) ) ;
F_128 ( F_225 ( V_169 ) , 0 ) ;
} else if ( F_32 ( V_16 ) && V_169 == V_386 ) {
F_128 ( F_226 ( V_169 ) ,
( ( V_37 -> V_115 -> V_384 - 1 ) << 16 ) |
( V_37 -> V_115 -> V_385 - 1 ) ) ;
F_128 ( F_227 ( V_169 ) , 0 ) ;
F_128 ( F_228 ( V_169 ) , 0 ) ;
}
switch ( V_114 -> V_264 ) {
case V_327 :
V_380 |= V_326 ;
break;
case V_329 :
V_380 |= V_328 ;
break;
case V_331 :
V_380 |= V_330 ;
break;
case V_333 :
V_380 |= V_332 ;
break;
case V_335 :
V_380 |= V_334 ;
break;
case V_337 :
V_380 |= V_336 ;
break;
case V_339 :
V_380 |= V_338 ;
break;
default:
F_146 () ;
}
if ( F_60 ( V_16 ) -> V_127 >= 4 &&
V_305 -> V_319 != V_321 )
V_380 |= V_387 ;
if ( F_30 ( V_16 ) )
V_380 |= V_388 ;
V_379 = V_318 * V_114 -> V_286 [ 0 ] + V_317 * V_381 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
V_37 -> V_389 =
F_199 ( V_2 ,
& V_317 , & V_318 , V_305 -> V_319 ,
V_381 ,
V_114 -> V_286 [ 0 ] ) ;
V_379 -= V_37 -> V_389 ;
} else {
V_37 -> V_389 = V_379 ;
}
if ( V_38 -> V_113 -> V_36 -> V_283 == F_229 ( V_390 ) ) {
V_380 |= V_391 ;
V_317 += ( V_37 -> V_115 -> V_385 - 1 ) ;
V_318 += ( V_37 -> V_115 -> V_384 - 1 ) ;
V_379 +=
( V_37 -> V_115 -> V_384 - 1 ) * V_114 -> V_286 [ 0 ] +
( V_37 -> V_115 -> V_385 - 1 ) * V_381 ;
}
V_37 -> V_392 = V_317 ;
V_37 -> V_393 = V_318 ;
F_128 ( V_9 , V_380 ) ;
F_128 ( F_230 ( V_169 ) , V_114 -> V_286 [ 0 ] ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
F_128 ( F_222 ( V_169 ) ,
F_217 ( V_305 ) + V_37 -> V_389 ) ;
F_128 ( F_231 ( V_169 ) , ( V_318 << 16 ) | V_317 ) ;
F_128 ( F_232 ( V_169 ) , V_379 ) ;
} else
F_128 ( F_223 ( V_169 ) , F_217 ( V_305 ) + V_379 ) ;
F_129 ( V_9 ) ;
}
static void F_233 ( struct V_111 * V_38 ,
struct V_275 * V_114 ,
int V_317 , int V_318 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_299 * V_113 = V_38 -> V_113 ;
bool V_365 = F_218 ( V_113 -> V_36 ) -> V_365 ;
struct V_304 * V_305 ;
int V_169 = V_37 -> V_169 ;
unsigned long V_379 ;
T_1 V_380 ;
T_1 V_9 = F_89 ( V_169 ) ;
int V_381 ;
if ( ! V_365 || ! V_114 ) {
F_128 ( V_9 , 0 ) ;
F_128 ( F_222 ( V_169 ) , 0 ) ;
F_129 ( V_9 ) ;
return;
}
V_305 = F_189 ( V_114 ) ;
if ( F_9 ( V_305 == NULL ) )
return;
V_381 = F_177 ( V_114 -> V_264 , 0 ) ;
V_380 = V_382 ;
V_380 |= V_170 ;
if ( F_234 ( V_16 ) || F_235 ( V_16 ) )
V_380 |= V_394 ;
switch ( V_114 -> V_264 ) {
case V_327 :
V_380 |= V_326 ;
break;
case V_331 :
V_380 |= V_330 ;
break;
case V_333 :
V_380 |= V_332 ;
break;
case V_335 :
V_380 |= V_334 ;
break;
case V_337 :
V_380 |= V_336 ;
break;
case V_339 :
V_380 |= V_338 ;
break;
default:
F_146 () ;
}
if ( V_305 -> V_319 != V_321 )
V_380 |= V_387 ;
if ( ! F_234 ( V_16 ) && ! F_235 ( V_16 ) )
V_380 |= V_388 ;
V_379 = V_318 * V_114 -> V_286 [ 0 ] + V_317 * V_381 ;
V_37 -> V_389 =
F_199 ( V_2 ,
& V_317 , & V_318 , V_305 -> V_319 ,
V_381 ,
V_114 -> V_286 [ 0 ] ) ;
V_379 -= V_37 -> V_389 ;
if ( V_38 -> V_113 -> V_36 -> V_283 == F_229 ( V_390 ) ) {
V_380 |= V_391 ;
if ( ! F_234 ( V_16 ) && ! F_235 ( V_16 ) ) {
V_317 += ( V_37 -> V_115 -> V_385 - 1 ) ;
V_318 += ( V_37 -> V_115 -> V_384 - 1 ) ;
V_379 +=
( V_37 -> V_115 -> V_384 - 1 ) * V_114 -> V_286 [ 0 ] +
( V_37 -> V_115 -> V_385 - 1 ) * V_381 ;
}
}
V_37 -> V_392 = V_317 ;
V_37 -> V_393 = V_318 ;
F_128 ( V_9 , V_380 ) ;
F_128 ( F_230 ( V_169 ) , V_114 -> V_286 [ 0 ] ) ;
F_128 ( F_222 ( V_169 ) ,
F_217 ( V_305 ) + V_37 -> V_389 ) ;
if ( F_234 ( V_16 ) || F_235 ( V_16 ) ) {
F_128 ( F_236 ( V_169 ) , ( V_318 << 16 ) | V_317 ) ;
} else {
F_128 ( F_231 ( V_169 ) , ( V_318 << 16 ) | V_317 ) ;
F_128 ( F_232 ( V_169 ) , V_379 ) ;
}
F_129 ( V_9 ) ;
}
T_1 F_237 ( struct V_15 * V_16 , V_89 V_289 ,
T_2 V_264 )
{
T_1 V_395 = F_177 ( V_264 , 0 ) * 8 ;
switch ( V_289 ) {
case V_268 :
return 64 ;
case V_269 :
if ( F_60 ( V_16 ) -> V_127 == 2 )
return 128 ;
return 512 ;
case V_270 :
return 128 ;
case V_271 :
if ( V_395 == 8 )
return 64 ;
else
return 128 ;
default:
F_179 ( V_289 ) ;
return 64 ;
}
}
unsigned long F_238 ( struct V_363 * V_363 ,
struct V_304 * V_305 ,
unsigned int V_169 )
{
const struct V_273 * V_274 = & V_282 ;
struct V_396 * V_397 ;
unsigned char * V_324 ;
if ( F_183 ( V_363 -> V_40 . V_36 -> V_283 ) )
V_274 = & V_284 ;
V_397 = F_239 ( V_305 , V_274 ) ;
if ( F_6 ( ! V_397 , L_59 ,
V_274 -> type ) )
return - 1 ;
V_324 = ( unsigned char * ) V_397 -> V_398 . V_399 ;
if ( V_169 == 1 ) {
V_324 += V_397 -> V_400 . V_280 . V_401 *
V_291 ;
}
return ( unsigned long ) V_324 ;
}
static void F_240 ( struct V_37 * V_37 , int V_240 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_128 ( F_241 ( V_37 -> V_119 , V_240 ) , 0 ) ;
F_128 ( F_242 ( V_37 -> V_119 , V_240 ) , 0 ) ;
F_128 ( F_243 ( V_37 -> V_119 , V_240 ) , 0 ) ;
}
static void F_244 ( struct V_37 * V_37 )
{
struct V_402 * V_403 ;
int V_50 ;
V_403 = & V_37 -> V_115 -> V_403 ;
for ( V_50 = 0 ; V_50 < V_37 -> V_404 ; V_50 ++ ) {
if ( ! V_403 -> V_405 [ V_50 ] . V_406 )
F_240 ( V_37 , V_50 ) ;
}
}
T_1 F_245 ( T_2 V_264 )
{
switch ( V_264 ) {
case V_327 :
return V_407 ;
case V_331 :
return V_342 ;
case V_335 :
return V_343 | V_408 ;
case V_333 :
return V_343 ;
case V_344 :
return V_343 | V_408 |
V_409 ;
case V_345 :
return V_343 |
V_409 ;
case V_337 :
return V_346 ;
case V_339 :
return V_408 | V_346 ;
case V_410 :
return V_411 | V_412 ;
case V_413 :
return V_411 | V_414 ;
case V_415 :
return V_411 | V_416 ;
case V_417 :
return V_411 | V_418 ;
default:
F_179 ( V_264 ) ;
}
return 0 ;
}
T_1 F_246 ( V_89 V_289 )
{
switch ( V_289 ) {
case V_268 :
break;
case V_269 :
return V_419 ;
case V_270 :
return V_420 ;
case V_271 :
return V_421 ;
default:
F_179 ( V_289 ) ;
}
return 0 ;
}
T_1 F_247 ( unsigned int V_283 )
{
switch ( V_283 ) {
case F_229 ( V_422 ) :
break;
case F_229 ( V_423 ) :
return V_424 ;
case F_229 ( V_390 ) :
return V_425 ;
case F_229 ( V_426 ) :
return V_427 ;
default:
F_179 ( V_283 ) ;
}
return 0 ;
}
static void F_248 ( struct V_111 * V_38 ,
struct V_275 * V_114 ,
int V_317 , int V_318 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_299 * V_169 = V_38 -> V_113 ;
bool V_365 = F_218 ( V_169 -> V_36 ) -> V_365 ;
struct V_304 * V_305 ;
int V_119 = V_37 -> V_119 ;
T_1 V_428 , V_429 , V_357 ;
T_1 V_266 , V_430 , V_431 ;
unsigned int V_283 ;
int V_432 , V_433 ;
unsigned long V_434 ;
struct V_43 * V_44 = V_37 -> V_115 ;
struct V_435 * V_277 ;
int V_368 = 0 , V_369 = 0 , V_370 = 0 , V_371 = 0 ;
int V_436 = 0 , V_437 = 0 , V_438 = 0 , V_439 = 0 ;
int V_440 = - 1 ;
V_277 = F_218 ( V_169 -> V_36 ) ;
if ( ! V_365 || ! V_114 ) {
F_128 ( F_95 ( V_119 , 0 ) , 0 ) ;
F_128 ( F_249 ( V_119 , 0 ) , 0 ) ;
F_129 ( F_95 ( V_119 , 0 ) ) ;
return;
}
V_428 = V_175 |
V_441 |
V_442 ;
V_428 |= F_245 ( V_114 -> V_264 ) ;
V_428 |= F_246 ( V_114 -> V_290 [ 0 ] ) ;
V_428 |= V_443 ;
V_283 = V_169 -> V_36 -> V_283 ;
V_428 |= F_247 ( V_283 ) ;
V_305 = F_189 ( V_114 ) ;
V_429 = F_237 ( V_16 , V_114 -> V_290 [ 0 ] ,
V_114 -> V_264 ) ;
V_434 = F_238 ( F_214 ( V_169 ) , V_305 , 0 ) ;
F_9 ( F_250 ( & V_277 -> V_444 ) == 0 ) ;
V_440 = V_277 -> V_440 ;
V_368 = V_277 -> V_444 . V_445 >> 16 ;
V_369 = V_277 -> V_444 . y1 >> 16 ;
V_370 = F_250 ( & V_277 -> V_444 ) >> 16 ;
V_371 = F_251 ( & V_277 -> V_444 ) >> 16 ;
V_436 = V_277 -> V_446 . V_445 ;
V_437 = V_277 -> V_446 . y1 ;
V_438 = F_250 ( & V_277 -> V_446 ) ;
V_439 = F_251 ( & V_277 -> V_446 ) ;
F_9 ( V_317 != V_368 || V_318 != V_369 ) ;
if ( F_183 ( V_283 ) ) {
V_266 = F_176 ( V_16 , V_114 -> V_264 ,
V_114 -> V_290 [ 0 ] , 0 ) ;
V_357 = F_184 ( V_114 -> V_272 , V_266 ) ;
V_432 = V_357 * V_266 - V_318 - V_371 ;
V_433 = V_317 ;
V_431 = ( V_370 - 1 ) << 16 | ( V_371 - 1 ) ;
} else {
V_357 = V_114 -> V_286 [ 0 ] / V_429 ;
V_432 = V_317 ;
V_433 = V_318 ;
V_431 = ( V_371 - 1 ) << 16 | ( V_370 - 1 ) ;
}
V_430 = V_433 << 16 | V_432 ;
V_37 -> V_392 = V_432 ;
V_37 -> V_393 = V_433 ;
F_128 ( F_95 ( V_119 , 0 ) , V_428 ) ;
F_128 ( F_252 ( V_119 , 0 ) , V_430 ) ;
F_128 ( F_253 ( V_119 , 0 ) , V_431 ) ;
F_128 ( F_254 ( V_119 , 0 ) , V_357 ) ;
if ( V_440 >= 0 ) {
T_2 V_447 = 0 ;
F_9 ( ! V_438 || ! V_439 ) ;
V_447 = V_448 | F_255 ( 0 ) |
V_44 -> V_403 . V_405 [ V_440 ] . V_449 ;
F_128 ( F_241 ( V_119 , V_440 ) , V_447 ) ;
F_128 ( F_256 ( V_119 , V_440 ) , 0 ) ;
F_128 ( F_242 ( V_119 , V_440 ) , ( V_436 << 16 ) | V_437 ) ;
F_128 ( F_243 ( V_119 , V_440 ) , ( V_438 << 16 ) | V_439 ) ;
F_128 ( F_257 ( V_119 , 0 ) , 0 ) ;
} else {
F_128 ( F_257 ( V_119 , 0 ) , ( V_437 << 16 ) | V_436 ) ;
}
F_128 ( F_249 ( V_119 , 0 ) , V_434 ) ;
F_129 ( F_249 ( V_119 , 0 ) ) ;
}
static int
F_258 ( struct V_111 * V_38 , struct V_275 * V_114 ,
int V_317 , int V_318 , enum V_450 V_36 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
if ( V_2 -> V_451 . V_452 )
V_2 -> V_451 . V_452 ( V_2 ) ;
V_2 -> V_453 . V_454 ( V_38 , V_114 , V_317 , V_318 ) ;
return 0 ;
}
static void F_259 ( struct V_15 * V_16 )
{
struct V_111 * V_38 ;
F_216 (dev, crtc) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_169 V_169 = V_37 -> V_169 ;
F_260 ( V_16 , V_169 ) ;
F_261 ( V_16 , V_169 ) ;
}
}
static void F_262 ( struct V_15 * V_16 )
{
struct V_111 * V_38 ;
F_216 (dev, crtc) {
struct V_363 * V_169 = F_214 ( V_38 -> V_113 ) ;
struct V_435 * V_277 ;
F_263 ( V_38 , & V_169 -> V_40 ) ;
V_277 = F_218 ( V_169 -> V_40 . V_36 ) ;
if ( V_277 -> V_40 . V_114 )
V_169 -> V_455 ( & V_169 -> V_40 , V_277 ) ;
F_264 ( V_38 ) ;
}
}
void F_265 ( struct V_15 * V_16 )
{
if ( F_33 ( V_16 ) )
return;
if ( F_60 ( V_16 ) -> V_127 >= 5 || F_30 ( V_16 ) )
return;
F_266 ( V_16 ) ;
F_267 ( V_16 ) ;
}
void F_268 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_203 ( V_16 ) ;
F_259 ( V_16 ) ;
if ( F_33 ( V_16 ) )
return;
if ( F_60 ( V_16 ) -> V_127 >= 5 || F_30 ( V_16 ) ) {
F_262 ( V_16 ) ;
return;
}
F_269 ( V_2 ) ;
F_270 ( V_2 ) ;
F_271 ( V_16 ) ;
F_272 ( & V_2 -> V_456 ) ;
if ( V_2 -> V_453 . V_457 )
V_2 -> V_453 . V_457 ( V_16 ) ;
F_273 ( & V_2 -> V_456 ) ;
F_274 ( V_16 ) ;
F_275 ( V_2 ) ;
F_276 ( V_16 ) ;
}
static void
F_277 ( struct V_275 * V_458 )
{
struct V_304 * V_305 = F_189 ( V_458 ) ;
struct V_1 * V_2 = F_203 ( V_305 -> V_40 . V_16 ) ;
bool V_459 = V_2 -> V_310 . V_311 ;
int V_307 ;
V_2 -> V_310 . V_311 = false ;
V_307 = F_278 ( V_305 , true ) ;
V_2 -> V_310 . V_311 = V_459 ;
F_9 ( V_307 ) ;
}
static bool F_279 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
bool V_460 ;
if ( F_280 ( & V_2 -> V_461 ) ||
V_37 -> V_462 != F_281 ( & V_2 -> V_461 . V_462 ) )
return false ;
F_272 ( & V_16 -> V_463 ) ;
V_460 = F_50 ( V_38 ) -> V_464 != NULL ;
F_273 ( & V_16 -> V_463 ) ;
return V_460 ;
}
static void F_282 ( struct V_37 * V_38 ,
struct V_43 * V_465 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_43 * V_211 =
F_283 ( V_38 -> V_40 . V_36 ) ;
V_38 -> V_40 . V_449 = V_38 -> V_40 . V_36 -> V_449 ;
F_151 ( L_60 ,
V_465 -> V_385 , V_465 -> V_384 ,
V_211 -> V_385 , V_211 -> V_384 ) ;
if ( F_71 ( V_16 ) )
F_284 ( & V_38 -> V_40 ) ;
F_128 ( F_285 ( V_38 -> V_119 ) ,
( ( V_211 -> V_385 - 1 ) << 16 ) |
( V_211 -> V_384 - 1 ) ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
F_244 ( V_38 ) ;
if ( V_211 -> V_466 . V_129 )
F_286 ( V_38 ) ;
} else if ( F_10 ( V_16 ) ) {
if ( V_211 -> V_466 . V_129 )
F_287 ( V_38 ) ;
else if ( V_465 -> V_466 . V_129 )
F_288 ( V_38 , true ) ;
}
}
static void F_289 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_1 V_9 , V_467 ;
V_9 = F_73 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
if ( F_290 ( V_16 ) ) {
V_467 &= ~ V_468 ;
V_467 |= V_468 | V_469 ;
} else {
V_467 &= ~ V_470 ;
V_467 |= V_470 | V_469 ;
}
F_128 ( V_9 , V_467 ) ;
V_9 = F_75 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
if ( F_106 ( V_16 ) ) {
V_467 &= ~ V_471 ;
V_467 |= V_472 ;
} else {
V_467 &= ~ V_470 ;
V_467 |= V_470 ;
}
F_128 ( V_9 , V_467 | V_473 ) ;
F_129 ( V_9 ) ;
F_130 ( 1000 ) ;
if ( F_290 ( V_16 ) )
F_128 ( V_9 , F_11 ( V_9 ) | V_474 |
V_475 ) ;
}
static void F_291 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_1 V_9 , V_467 , V_476 ;
F_292 ( V_2 , V_119 ) ;
V_9 = F_293 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_477 ;
V_467 &= ~ V_478 ;
F_128 ( V_9 , V_467 ) ;
F_11 ( V_9 ) ;
F_130 ( 150 ) ;
V_9 = F_73 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_479 ;
V_467 |= F_294 ( V_37 -> V_115 -> V_480 ) ;
V_467 &= ~ V_470 ;
V_467 |= V_481 ;
F_128 ( V_9 , V_467 | V_142 ) ;
V_9 = F_75 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_470 ;
V_467 |= V_481 ;
F_128 ( V_9 , V_467 | V_143 ) ;
F_129 ( V_9 ) ;
F_130 ( 150 ) ;
F_128 ( F_295 ( V_119 ) , V_482 ) ;
F_128 ( F_295 ( V_119 ) , V_482 |
V_483 ) ;
V_9 = F_296 ( V_119 ) ;
for ( V_476 = 0 ; V_476 < 5 ; V_476 ++ ) {
V_467 = F_11 ( V_9 ) ;
F_151 ( L_61 , V_467 ) ;
if ( ( V_467 & V_478 ) ) {
F_151 ( L_62 ) ;
F_128 ( V_9 , V_467 | V_478 ) ;
break;
}
}
if ( V_476 == 5 )
F_131 ( L_63 ) ;
V_9 = F_73 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_470 ;
V_467 |= V_484 ;
F_128 ( V_9 , V_467 ) ;
V_9 = F_75 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_470 ;
V_467 |= V_484 ;
F_128 ( V_9 , V_467 ) ;
F_129 ( V_9 ) ;
F_130 ( 150 ) ;
V_9 = F_296 ( V_119 ) ;
for ( V_476 = 0 ; V_476 < 5 ; V_476 ++ ) {
V_467 = F_11 ( V_9 ) ;
F_151 ( L_61 , V_467 ) ;
if ( V_467 & V_477 ) {
F_128 ( V_9 , V_467 | V_477 ) ;
F_151 ( L_64 ) ;
break;
}
}
if ( V_476 == 5 )
F_131 ( L_65 ) ;
F_151 ( L_66 ) ;
}
static void F_297 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_1 V_9 , V_467 , V_50 , V_485 ;
V_9 = F_293 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_477 ;
V_467 &= ~ V_478 ;
F_128 ( V_9 , V_467 ) ;
F_129 ( V_9 ) ;
F_130 ( 150 ) ;
V_9 = F_73 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_479 ;
V_467 |= F_294 ( V_37 -> V_115 -> V_480 ) ;
V_467 &= ~ V_470 ;
V_467 |= V_481 ;
V_467 &= ~ V_486 ;
V_467 |= V_487 ;
F_128 ( V_9 , V_467 | V_142 ) ;
F_128 ( F_298 ( V_119 ) ,
V_488 | V_489 ) ;
V_9 = F_75 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
if ( F_106 ( V_16 ) ) {
V_467 &= ~ V_471 ;
V_467 |= V_490 ;
} else {
V_467 &= ~ V_470 ;
V_467 |= V_481 ;
}
F_128 ( V_9 , V_467 | V_143 ) ;
F_129 ( V_9 ) ;
F_130 ( 150 ) ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
V_9 = F_73 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_486 ;
V_467 |= V_491 [ V_50 ] ;
F_128 ( V_9 , V_467 ) ;
F_129 ( V_9 ) ;
F_130 ( 500 ) ;
for ( V_485 = 0 ; V_485 < 5 ; V_485 ++ ) {
V_9 = F_296 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
F_151 ( L_61 , V_467 ) ;
if ( V_467 & V_478 ) {
F_128 ( V_9 , V_467 | V_478 ) ;
F_151 ( L_62 ) ;
break;
}
F_130 ( 50 ) ;
}
if ( V_485 < 5 )
break;
}
if ( V_50 == 4 )
F_131 ( L_63 ) ;
V_9 = F_73 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_470 ;
V_467 |= V_484 ;
if ( F_299 ( V_16 ) ) {
V_467 &= ~ V_486 ;
V_467 |= V_487 ;
}
F_128 ( V_9 , V_467 ) ;
V_9 = F_75 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
if ( F_106 ( V_16 ) ) {
V_467 &= ~ V_471 ;
V_467 |= V_492 ;
} else {
V_467 &= ~ V_470 ;
V_467 |= V_484 ;
}
F_128 ( V_9 , V_467 ) ;
F_129 ( V_9 ) ;
F_130 ( 150 ) ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
V_9 = F_73 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_486 ;
V_467 |= V_491 [ V_50 ] ;
F_128 ( V_9 , V_467 ) ;
F_129 ( V_9 ) ;
F_130 ( 500 ) ;
for ( V_485 = 0 ; V_485 < 5 ; V_485 ++ ) {
V_9 = F_296 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
F_151 ( L_61 , V_467 ) ;
if ( V_467 & V_477 ) {
F_128 ( V_9 , V_467 | V_477 ) ;
F_151 ( L_64 ) ;
break;
}
F_130 ( 50 ) ;
}
if ( V_485 < 5 )
break;
}
if ( V_50 == 4 )
F_131 ( L_65 ) ;
F_151 ( L_67 ) ;
}
static void F_300 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_1 V_9 , V_467 , V_50 , V_493 ;
V_9 = F_293 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_477 ;
V_467 &= ~ V_478 ;
F_128 ( V_9 , V_467 ) ;
F_129 ( V_9 ) ;
F_130 ( 150 ) ;
F_151 ( L_68 ,
F_11 ( F_296 ( V_119 ) ) ) ;
for ( V_493 = 0 ; V_493 < F_301 ( V_491 ) * 2 ; V_493 ++ ) {
V_9 = F_73 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ ( V_494 | V_468 ) ;
V_467 &= ~ V_142 ;
F_128 ( V_9 , V_467 ) ;
V_9 = F_75 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_494 ;
V_467 &= ~ V_471 ;
V_467 &= ~ V_143 ;
F_128 ( V_9 , V_467 ) ;
V_9 = F_73 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_479 ;
V_467 |= F_294 ( V_37 -> V_115 -> V_480 ) ;
V_467 |= V_495 ;
V_467 &= ~ V_486 ;
V_467 |= V_491 [ V_493 / 2 ] ;
V_467 |= V_496 ;
F_128 ( V_9 , V_467 | V_142 ) ;
F_128 ( F_298 ( V_119 ) ,
V_488 | V_489 ) ;
V_9 = F_75 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 |= V_490 ;
V_467 |= V_496 ;
F_128 ( V_9 , V_467 | V_143 ) ;
F_129 ( V_9 ) ;
F_130 ( 1 ) ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
V_9 = F_296 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
F_151 ( L_61 , V_467 ) ;
if ( V_467 & V_478 ||
( F_11 ( V_9 ) & V_478 ) ) {
F_128 ( V_9 , V_467 | V_478 ) ;
F_151 ( L_69 ,
V_50 ) ;
break;
}
F_130 ( 1 ) ;
}
if ( V_50 == 4 ) {
F_151 ( L_70 , V_493 / 2 ) ;
continue;
}
V_9 = F_73 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_468 ;
V_467 |= V_497 ;
F_128 ( V_9 , V_467 ) ;
V_9 = F_75 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_471 ;
V_467 |= V_492 ;
F_128 ( V_9 , V_467 ) ;
F_129 ( V_9 ) ;
F_130 ( 2 ) ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
V_9 = F_296 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
F_151 ( L_61 , V_467 ) ;
if ( V_467 & V_477 ||
( F_11 ( V_9 ) & V_477 ) ) {
F_128 ( V_9 , V_467 | V_477 ) ;
F_151 ( L_71 ,
V_50 ) ;
goto V_498;
}
F_130 ( 2 ) ;
}
if ( V_50 == 4 )
F_151 ( L_72 , V_493 / 2 ) ;
}
V_498:
F_151 ( L_67 ) ;
}
static void F_302 ( struct V_37 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_37 -> V_119 ;
T_1 V_9 , V_467 ;
V_9 = F_75 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ ( V_479 | ( 0x7 << 16 ) ) ;
V_467 |= F_294 ( V_37 -> V_115 -> V_480 ) ;
V_467 |= ( F_11 ( F_61 ( V_119 ) ) & V_246 ) << 11 ;
F_128 ( V_9 , V_467 | V_145 ) ;
F_129 ( V_9 ) ;
F_130 ( 200 ) ;
V_467 = F_11 ( V_9 ) ;
F_128 ( V_9 , V_467 | V_499 ) ;
F_129 ( V_9 ) ;
F_130 ( 200 ) ;
V_9 = F_73 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
if ( ( V_467 & V_144 ) == 0 ) {
F_128 ( V_9 , V_467 | V_144 ) ;
F_129 ( V_9 ) ;
F_130 ( 100 ) ;
}
}
static void F_303 ( struct V_37 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_37 -> V_119 ;
T_1 V_9 , V_467 ;
V_9 = F_75 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
F_128 ( V_9 , V_467 & ~ V_499 ) ;
V_9 = F_73 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
F_128 ( V_9 , V_467 & ~ V_144 ) ;
F_129 ( V_9 ) ;
F_130 ( 100 ) ;
V_9 = F_75 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
F_128 ( V_9 , V_467 & ~ V_145 ) ;
F_129 ( V_9 ) ;
F_130 ( 100 ) ;
}
static void F_304 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_1 V_9 , V_467 ;
V_9 = F_73 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
F_128 ( V_9 , V_467 & ~ V_142 ) ;
F_129 ( V_9 ) ;
V_9 = F_75 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ ( 0x7 << 16 ) ;
V_467 |= ( F_11 ( F_61 ( V_119 ) ) & V_246 ) << 11 ;
F_128 ( V_9 , V_467 & ~ V_143 ) ;
F_129 ( V_9 ) ;
F_130 ( 100 ) ;
if ( F_105 ( V_16 ) )
F_128 ( F_295 ( V_119 ) , V_482 ) ;
V_9 = F_73 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ V_470 ;
V_467 |= V_481 ;
F_128 ( V_9 , V_467 ) ;
V_9 = F_75 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
if ( F_106 ( V_16 ) ) {
V_467 &= ~ V_471 ;
V_467 |= V_490 ;
} else {
V_467 &= ~ V_470 ;
V_467 |= V_481 ;
}
V_467 &= ~ ( 0x07 << 16 ) ;
V_467 |= ( F_11 ( F_61 ( V_119 ) ) & V_246 ) << 11 ;
F_128 ( V_9 , V_467 ) ;
F_129 ( V_9 ) ;
F_130 ( 100 ) ;
}
bool F_305 ( struct V_15 * V_16 )
{
struct V_37 * V_38 ;
F_139 (dev, crtc) {
if ( F_281 ( & V_38 -> V_500 ) == 0 )
continue;
if ( V_38 -> V_464 )
F_306 ( V_16 , V_38 -> V_119 ) ;
return true ;
}
return false ;
}
static void F_307 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = F_203 ( V_37 -> V_40 . V_16 ) ;
struct V_501 * V_502 = V_37 -> V_464 ;
F_308 () ;
V_37 -> V_464 = NULL ;
if ( V_502 -> V_503 )
F_309 ( V_37 -> V_40 . V_16 ,
V_37 -> V_119 ,
V_502 -> V_503 ) ;
F_103 ( & V_37 -> V_40 ) ;
F_310 ( & V_2 -> V_504 ) ;
F_311 ( V_2 -> V_505 , & V_502 -> V_502 ) ;
F_312 ( V_37 -> V_169 ,
V_502 -> V_506 ) ;
}
void F_313 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_9 ( F_314 ( & V_2 -> V_504 ) ) ;
if ( F_9 ( F_315 ( V_2 -> V_504 ,
! F_279 ( V_38 ) ,
60 * V_507 ) == 0 ) ) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
F_272 ( & V_16 -> V_463 ) ;
if ( V_37 -> V_464 ) {
F_178 ( 1 , L_73 ) ;
F_307 ( V_37 ) ;
}
F_273 ( & V_16 -> V_463 ) ;
}
if ( V_38 -> V_113 -> V_114 ) {
F_2 ( & V_16 -> V_308 ) ;
F_277 ( V_38 -> V_113 -> V_114 ) ;
F_4 ( & V_16 -> V_308 ) ;
}
}
static void F_316 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int clock = F_50 ( V_38 ) -> V_115 -> V_40 . V_116 . V_117 ;
T_1 V_508 , V_509 , V_510 , V_511 = 0 ;
T_1 V_467 ;
F_2 ( & V_2 -> V_5 ) ;
F_128 ( V_512 , V_513 ) ;
F_317 ( V_2 , V_514 ,
F_318 ( V_2 , V_514 , V_515 ) |
V_516 ,
V_515 ) ;
if ( clock == 20000 ) {
V_510 = 1 ;
V_508 = 0x41 ;
V_509 = 0x20 ;
} else {
T_1 V_517 = 172800 * 1000 ;
T_1 V_518 = 64 ;
T_1 V_519 , V_520 , V_521 ;
V_519 = ( V_517 / clock ) ;
V_520 = V_519 / V_518 ;
V_521 = V_519 % V_518 ;
V_510 = 0 ;
V_508 = V_520 - 2 ;
V_509 = V_521 ;
}
F_9 ( F_319 ( V_508 ) &
~ V_522 ) ;
F_9 ( F_320 ( V_511 ) &
~ V_523 ) ;
F_151 ( L_74 ,
clock ,
V_510 ,
V_508 ,
V_511 ,
V_509 ) ;
V_467 = F_318 ( V_2 , V_524 , V_515 ) ;
V_467 &= ~ V_522 ;
V_467 |= F_319 ( V_508 ) ;
V_467 &= ~ V_523 ;
V_467 |= F_321 ( V_509 ) ;
V_467 |= F_320 ( V_511 ) ;
V_467 |= V_525 ;
F_317 ( V_2 , V_524 , V_467 , V_515 ) ;
V_467 = F_318 ( V_2 , V_526 , V_515 ) ;
V_467 &= ~ F_322 ( 1 ) ;
V_467 |= F_322 ( V_510 ) ;
F_317 ( V_2 , V_526 , V_467 , V_515 ) ;
V_467 = F_318 ( V_2 , V_514 , V_515 ) ;
V_467 &= ~ V_516 ;
F_317 ( V_2 , V_514 , V_467 , V_515 ) ;
F_130 ( 24 ) ;
F_128 ( V_512 , V_527 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_323 ( struct V_37 * V_38 ,
enum V_119 V_258 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_118 V_121 = V_38 -> V_115 -> V_121 ;
F_128 ( F_324 ( V_258 ) ,
F_11 ( F_325 ( V_121 ) ) ) ;
F_128 ( F_326 ( V_258 ) ,
F_11 ( F_327 ( V_121 ) ) ) ;
F_128 ( F_328 ( V_258 ) ,
F_11 ( F_329 ( V_121 ) ) ) ;
F_128 ( F_330 ( V_258 ) ,
F_11 ( F_331 ( V_121 ) ) ) ;
F_128 ( F_332 ( V_258 ) ,
F_11 ( F_333 ( V_121 ) ) ) ;
F_128 ( F_334 ( V_258 ) ,
F_11 ( F_335 ( V_121 ) ) ) ;
F_128 ( F_336 ( V_258 ) ,
F_11 ( F_337 ( V_121 ) ) ) ;
}
static void F_338 ( struct V_15 * V_16 , bool V_242 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_467 ;
V_467 = F_11 ( V_528 ) ;
if ( ! ! ( V_467 & V_529 ) == V_242 )
return;
F_9 ( F_11 ( F_75 ( V_157 ) ) & V_143 ) ;
F_9 ( F_11 ( F_75 ( V_530 ) ) & V_143 ) ;
V_467 &= ~ V_529 ;
if ( V_242 )
V_467 |= V_529 ;
F_151 ( L_75 , V_242 ? L_76 : L_77 ) ;
F_128 ( V_528 , V_467 ) ;
F_129 ( V_528 ) ;
}
static void F_339 ( struct V_37 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
switch ( V_37 -> V_119 ) {
case V_148 :
break;
case V_157 :
if ( V_37 -> V_115 -> V_480 > 2 )
F_338 ( V_16 , false ) ;
else
F_338 ( V_16 , true ) ;
break;
case V_530 :
F_338 ( V_16 , true ) ;
break;
default:
F_146 () ;
}
}
static void F_340 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_1 V_9 , V_467 ;
F_107 ( V_2 , V_119 ) ;
if ( F_290 ( V_16 ) )
F_339 ( V_37 ) ;
F_128 ( F_341 ( V_119 ) ,
F_11 ( F_342 ( V_119 ) ) & V_531 ) ;
V_2 -> V_453 . V_532 ( V_38 ) ;
if ( F_106 ( V_16 ) ) {
T_1 V_533 ;
V_467 = F_11 ( V_534 ) ;
V_467 |= F_343 ( V_119 ) ;
V_533 = F_344 ( V_119 ) ;
if ( V_37 -> V_115 -> V_135 == V_535 )
V_467 |= V_533 ;
else
V_467 &= ~ V_533 ;
F_128 ( V_534 , V_467 ) ;
}
F_150 ( V_37 ) ;
F_78 ( V_2 , V_119 ) ;
F_323 ( V_37 , V_119 ) ;
F_289 ( V_38 ) ;
if ( F_106 ( V_16 ) && V_37 -> V_115 -> V_536 ) {
T_1 V_537 = ( F_11 ( F_61 ( V_119 ) ) & V_246 ) >> 5 ;
V_9 = F_110 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ ( V_187 |
V_538 |
V_539 ) ;
V_467 |= V_540 ;
V_467 |= V_537 << 9 ;
if ( V_38 -> V_449 . V_359 & V_541 )
V_467 |= V_542 ;
if ( V_38 -> V_449 . V_359 & V_543 )
V_467 |= V_544 ;
switch ( F_345 ( V_38 ) ) {
case V_201 :
V_467 |= V_202 ;
break;
case V_203 :
V_467 |= V_204 ;
break;
case V_205 :
V_467 |= V_206 ;
break;
default:
F_146 () ;
}
F_128 ( V_9 , V_467 ) ;
}
F_157 ( V_2 , V_119 ) ;
}
static void F_346 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_118 V_121 = V_37 -> V_115 -> V_121 ;
F_107 ( V_2 , V_255 ) ;
F_316 ( V_38 ) ;
F_323 ( V_37 , V_148 ) ;
F_161 ( V_2 , V_121 ) ;
}
struct V_134 * F_347 ( struct V_37 * V_38 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_38 -> V_40 . V_16 -> V_17 ;
struct V_134 * V_137 ;
struct V_545 * V_135 ;
enum V_546 V_50 ;
int V_91 = V_2 -> V_547 ;
V_135 = F_348 ( V_44 -> V_40 . V_36 ) ;
if ( F_105 ( V_2 -> V_16 ) ) {
V_50 = (enum V_546 ) V_38 -> V_119 ;
V_137 = & V_2 -> V_136 [ V_50 ] ;
F_151 ( L_78 ,
V_38 -> V_40 . V_40 . V_240 , V_137 -> V_8 ) ;
F_9 ( V_135 [ V_50 ] . V_237 ) ;
goto V_101;
}
if ( F_29 ( V_2 -> V_16 ) ) {
struct V_41 * V_42 ;
struct V_225 * V_548 ;
V_42 = F_349 ( V_44 ) ;
if ( F_9 ( ! V_42 ) )
return NULL ;
V_548 = F_350 ( & V_42 -> V_40 ) ;
V_50 = (enum V_546 ) V_548 -> V_216 ;
V_137 = & V_2 -> V_136 [ V_50 ] ;
F_151 ( L_78 ,
V_38 -> V_40 . V_40 . V_240 , V_137 -> V_8 ) ;
F_9 ( V_135 [ V_50 ] . V_237 ) ;
goto V_101;
} else if ( F_60 ( V_2 ) -> V_127 < 9 && F_71 ( V_2 ) )
V_91 = 2 ;
for ( V_50 = 0 ; V_50 < V_91 ; V_50 ++ ) {
V_137 = & V_2 -> V_136 [ V_50 ] ;
if ( V_135 [ V_50 ] . V_237 == 0 )
continue;
if ( memcmp ( & V_44 -> V_212 ,
& V_135 [ V_50 ] . V_139 ,
sizeof( V_44 -> V_212 ) ) == 0 ) {
F_151 ( L_79 ,
V_38 -> V_40 . V_40 . V_240 , V_137 -> V_8 ,
V_135 [ V_50 ] . V_237 ,
V_137 -> V_112 ) ;
goto V_101;
}
}
for ( V_50 = 0 ; V_50 < V_2 -> V_547 ; V_50 ++ ) {
V_137 = & V_2 -> V_136 [ V_50 ] ;
if ( V_135 [ V_50 ] . V_237 == 0 ) {
F_151 ( L_80 ,
V_38 -> V_40 . V_40 . V_240 , V_137 -> V_8 ) ;
goto V_101;
}
}
return NULL ;
V_101:
if ( V_135 [ V_50 ] . V_237 == 0 )
V_135 [ V_50 ] . V_139 =
V_44 -> V_212 ;
V_44 -> V_135 = V_50 ;
F_15 ( L_81 , V_137 -> V_8 ,
F_80 ( V_38 -> V_119 ) ) ;
V_135 [ V_50 ] . V_237 |= 1 << V_38 -> V_119 ;
return V_137 ;
}
static void F_351 ( struct V_45 * V_36 )
{
struct V_1 * V_2 = F_203 ( V_36 -> V_16 ) ;
struct V_545 * V_135 ;
struct V_134 * V_137 ;
enum V_546 V_50 ;
if ( ! F_352 ( V_36 ) -> V_549 )
return;
V_135 = F_352 ( V_36 ) -> V_135 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_547 ; V_50 ++ ) {
V_137 = & V_2 -> V_136 [ V_50 ] ;
V_137 -> V_115 = V_135 [ V_50 ] ;
}
}
static void F_353 ( struct V_15 * V_16 , int V_119 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
int V_550 = F_57 ( V_119 ) ;
T_1 V_467 ;
V_467 = F_11 ( V_550 ) ;
F_130 ( 500 ) ;
if ( F_62 ( F_11 ( V_550 ) != V_467 , 5 ) ) {
if ( F_62 ( F_11 ( V_550 ) != V_467 , 5 ) )
F_131 ( L_82 , F_80 ( V_119 ) ) ;
}
}
static int
F_354 ( struct V_43 * V_44 , bool V_551 ,
unsigned V_552 , int * V_440 , unsigned int V_283 ,
int V_370 , int V_371 , int V_438 , int V_439 )
{
struct V_402 * V_403 =
& V_44 -> V_403 ;
struct V_37 * V_37 =
F_50 ( V_44 -> V_40 . V_38 ) ;
int V_553 ;
V_553 = F_183 ( V_283 ) ?
( V_371 != V_438 || V_370 != V_439 ) :
( V_370 != V_438 || V_371 != V_439 ) ;
if ( V_551 || ! V_553 ) {
if ( * V_440 >= 0 ) {
V_403 -> V_554 &= ~ ( 1 << V_552 ) ;
V_403 -> V_405 [ * V_440 ] . V_406 = 0 ;
F_151 ( L_83
L_84 ,
V_37 -> V_119 , V_552 , * V_440 ,
V_403 -> V_554 ) ;
* V_440 = - 1 ;
}
return 0 ;
}
if ( V_370 < V_555 || V_371 < V_556 ||
V_438 < V_557 || V_439 < V_558 ||
V_370 > V_559 || V_371 > V_560 ||
V_438 > V_561 || V_439 > V_562 ) {
F_151 ( L_85
L_86 ,
V_37 -> V_119 , V_552 , V_370 , V_371 , V_438 , V_439 ) ;
return - V_309 ;
}
V_403 -> V_554 |= ( 1 << V_552 ) ;
F_151 ( L_83
L_87 ,
V_37 -> V_119 , V_552 , V_370 , V_371 , V_438 , V_439 ,
V_403 -> V_554 ) ;
return 0 ;
}
int F_355 ( struct V_43 * V_36 )
{
struct V_37 * V_37 = F_50 ( V_36 -> V_40 . V_38 ) ;
const struct V_563 * V_116 = & V_36 -> V_40 . V_116 ;
F_151 ( L_88 ,
V_37 -> V_40 . V_40 . V_240 , V_37 -> V_119 , V_564 ) ;
return F_354 ( V_36 , ! V_36 -> V_40 . V_112 , V_564 ,
& V_36 -> V_403 . V_440 , V_422 ,
V_36 -> V_385 , V_36 -> V_384 ,
V_116 -> V_565 , V_116 -> V_566 ) ;
}
static int F_356 ( struct V_43 * V_44 ,
struct V_435 * V_277 )
{
struct V_37 * V_37 = F_50 ( V_44 -> V_40 . V_38 ) ;
struct V_363 * V_363 =
F_214 ( V_277 -> V_40 . V_169 ) ;
struct V_275 * V_114 = V_277 -> V_40 . V_114 ;
int V_307 ;
bool V_551 = ! V_114 || ! V_277 -> V_365 ;
F_151 ( L_89 ,
V_363 -> V_40 . V_40 . V_240 , V_37 -> V_119 ,
F_219 ( & V_363 -> V_40 ) ) ;
V_307 = F_354 ( V_44 , V_551 ,
F_219 ( & V_363 -> V_40 ) ,
& V_277 -> V_440 ,
V_277 -> V_40 . V_283 ,
F_250 ( & V_277 -> V_444 ) >> 16 ,
F_251 ( & V_277 -> V_444 ) >> 16 ,
F_250 ( & V_277 -> V_446 ) ,
F_251 ( & V_277 -> V_446 ) ) ;
if ( V_307 || V_277 -> V_440 < 0 )
return V_307 ;
if ( V_277 -> V_567 . V_359 != V_568 ) {
F_151 ( L_90 ,
V_363 -> V_40 . V_40 . V_240 ) ;
return - V_309 ;
}
switch ( V_114 -> V_264 ) {
case V_331 :
case V_335 :
case V_333 :
case V_344 :
case V_345 :
case V_337 :
case V_339 :
case V_410 :
case V_413 :
case V_415 :
case V_417 :
break;
default:
F_151 ( L_91 ,
V_363 -> V_40 . V_40 . V_240 , V_114 -> V_40 . V_240 , V_114 -> V_264 ) ;
return - V_309 ;
}
return 0 ;
}
static void F_357 ( struct V_37 * V_38 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_38 -> V_404 ; V_50 ++ )
F_240 ( V_38 , V_50 ) ;
}
static void F_286 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
struct V_402 * V_403 =
& V_38 -> V_115 -> V_403 ;
F_151 ( L_92 , V_38 -> V_115 ) ;
if ( V_38 -> V_115 -> V_466 . V_129 ) {
int V_240 ;
if ( F_9 ( V_38 -> V_115 -> V_403 . V_440 < 0 ) ) {
F_131 ( L_93 ) ;
return;
}
V_240 = V_403 -> V_440 ;
F_128 ( F_241 ( V_119 , V_240 ) , V_448 |
V_569 | V_403 -> V_405 [ V_240 ] . V_449 ) ;
F_128 ( F_242 ( V_119 , V_240 ) , V_38 -> V_115 -> V_466 . V_570 ) ;
F_128 ( F_243 ( V_119 , V_240 ) , V_38 -> V_115 -> V_466 . V_294 ) ;
F_151 ( L_94 , V_38 -> V_115 , V_240 ) ;
}
}
static void F_287 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
if ( V_38 -> V_115 -> V_466 . V_129 ) {
if ( F_290 ( V_16 ) || F_234 ( V_16 ) )
F_128 ( F_358 ( V_119 ) , V_571 | V_572 |
F_359 ( V_119 ) ) ;
else
F_128 ( F_358 ( V_119 ) , V_571 | V_572 ) ;
F_128 ( F_360 ( V_119 ) , V_38 -> V_115 -> V_466 . V_570 ) ;
F_128 ( F_361 ( V_119 ) , V_38 -> V_115 -> V_466 . V_294 ) ;
}
}
void F_362 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! V_38 -> V_115 -> V_573 )
return;
F_306 ( V_16 , V_38 -> V_119 ) ;
F_363 ( V_2 , V_38 -> V_169 ) ;
if ( F_235 ( V_16 ) ) {
F_2 ( & V_2 -> V_574 . V_575 ) ;
F_9 ( F_364 ( V_2 , V_576 , 0xc0000000 ) ) ;
F_4 ( & V_2 -> V_574 . V_575 ) ;
} else {
F_128 ( V_577 , V_578 ) ;
if ( F_62 ( F_365 ( V_577 ) & V_578 , 50 ) )
F_131 ( L_95 ) ;
}
}
void F_366 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! V_38 -> V_115 -> V_573 )
return;
F_363 ( V_2 , V_38 -> V_169 ) ;
if ( F_235 ( V_16 ) ) {
F_2 ( & V_2 -> V_574 . V_575 ) ;
F_9 ( F_364 ( V_2 , V_576 , 0 ) ) ;
F_4 ( & V_2 -> V_574 . V_575 ) ;
if ( F_62 ( ( F_11 ( V_577 ) & V_578 ) == 0 , 42 ) )
F_131 ( L_96 ) ;
} else {
F_128 ( V_577 , 0 ) ;
F_129 ( V_577 ) ;
}
F_306 ( V_16 , V_38 -> V_119 ) ;
}
static void F_367 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_119 V_119 = V_37 -> V_119 ;
int V_50 ;
bool V_579 = false ;
if ( ! V_38 -> V_36 -> V_112 )
return;
if ( F_169 ( V_2 -> V_16 ) ) {
if ( F_20 ( V_37 , V_259 ) )
F_170 ( V_2 ) ;
else
F_171 ( V_2 , V_119 ) ;
}
if ( F_234 ( V_16 ) && V_37 -> V_115 -> V_573 &&
( ( F_11 ( F_368 ( V_119 ) ) & V_580 ) ==
V_581 ) ) {
F_366 ( V_37 ) ;
V_579 = true ;
}
for ( V_50 = 0 ; V_50 < 256 ; V_50 ++ ) {
T_1 V_582 ;
if ( F_169 ( V_16 ) )
V_582 = F_369 ( V_119 , V_50 ) ;
else
V_582 = F_370 ( V_119 , V_50 ) ;
F_128 ( V_582 ,
( V_37 -> V_583 [ V_50 ] << 16 ) |
( V_37 -> V_584 [ V_50 ] << 8 ) |
V_37 -> V_585 [ V_50 ] ) ;
}
if ( V_579 )
F_362 ( V_37 ) ;
}
static void F_371 ( struct V_37 * V_37 )
{
if ( V_37 -> V_586 ) {
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_2 ( & V_16 -> V_308 ) ;
V_2 -> V_310 . V_311 = false ;
( void ) F_372 ( V_37 -> V_586 ) ;
V_2 -> V_310 . V_311 = true ;
F_4 ( & V_16 -> V_308 ) ;
}
}
static void
F_373 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
if ( F_235 ( V_16 ) )
F_306 ( V_16 , V_119 ) ;
F_362 ( V_37 ) ;
if ( F_33 ( V_16 ) )
F_374 ( V_2 , V_119 , true ) ;
if ( F_169 ( V_16 ) )
F_375 ( V_2 ) ;
}
static void
F_220 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
if ( F_33 ( V_16 ) )
F_374 ( V_2 , V_119 , false ) ;
if ( F_169 ( V_16 ) ) {
F_376 ( V_2 , false ) ;
V_2 -> V_587 . V_588 . V_589 = false ;
F_306 ( V_16 , V_119 ) ;
}
F_366 ( V_37 ) ;
}
static void F_377 ( struct V_37 * V_38 )
{
struct V_590 * V_591 = & V_38 -> V_591 ;
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_299 * V_169 ;
if ( V_591 -> V_592 )
F_306 ( V_16 , V_38 -> V_119 ) ;
F_378 ( V_16 , V_591 -> V_593 ) ;
if ( V_591 -> V_594 )
V_38 -> V_587 . V_595 = true ;
if ( V_38 -> V_591 . V_596 )
F_379 ( & V_38 -> V_40 ) ;
if ( V_591 -> V_597 )
F_380 ( V_2 ) ;
if ( V_591 -> V_598 )
F_373 ( & V_38 -> V_40 ) ;
F_381 (plane, dev, atomic->update_sprite_watermarks)
F_382 ( V_169 , & V_38 -> V_40 ,
0 , 0 , 0 , false , false ) ;
memset ( V_591 , 0 , sizeof( * V_591 ) ) ;
}
static void F_383 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_590 * V_591 = & V_38 -> V_591 ;
struct V_299 * V_81 ;
F_381 (p, dev, atomic->disabled_planes) {
struct V_363 * V_169 = F_214 ( V_81 ) ;
F_2 ( & V_16 -> V_308 ) ;
F_384 ( F_189 ( V_169 -> V_40 . V_114 ) , NULL ,
V_169 -> V_378 ) ;
F_4 ( & V_16 -> V_308 ) ;
}
if ( V_591 -> V_599 )
F_313 ( & V_38 -> V_40 ) ;
if ( V_591 -> V_452 )
F_385 ( V_38 ) ;
if ( V_38 -> V_591 . V_600 )
F_366 ( V_38 ) ;
if ( V_591 -> V_601 )
F_220 ( & V_38 -> V_40 ) ;
if ( V_591 -> V_594 ) {
V_38 -> V_587 . V_595 = false ;
F_376 ( V_2 , false ) ;
}
}
static void F_386 ( struct V_111 * V_38 , unsigned V_366 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_299 * V_81 ;
int V_119 = V_37 -> V_119 ;
F_371 ( V_37 ) ;
F_381 (p, dev, plane_mask)
F_214 ( V_81 ) -> V_367 ( V_81 , V_38 ) ;
F_378 ( V_16 , F_387 ( V_119 ) ) ;
}
static void F_388 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 ;
if ( F_9 ( V_37 -> V_112 ) )
return;
if ( V_37 -> V_115 -> V_260 )
F_148 ( V_37 ) ;
if ( V_37 -> V_115 -> V_536 )
F_389 ( V_37 , V_602 ) ;
F_390 ( V_37 ) ;
if ( V_37 -> V_115 -> V_260 ) {
F_391 ( V_37 ,
& V_37 -> V_115 -> V_603 , NULL ) ;
}
F_392 ( V_38 ) ;
V_37 -> V_112 = true ;
F_374 ( V_2 , V_119 , true ) ;
F_393 ( V_2 , V_119 , true ) ;
F_21 (dev, crtc, encoder)
if ( V_42 -> V_604 )
V_42 -> V_604 ( V_42 ) ;
if ( V_37 -> V_115 -> V_260 ) {
F_302 ( V_37 ) ;
} else {
F_163 ( V_2 , V_119 ) ;
F_164 ( V_2 , V_119 ) ;
}
F_287 ( V_37 ) ;
F_367 ( V_38 ) ;
F_379 ( V_38 ) ;
F_166 ( V_37 ) ;
if ( V_37 -> V_115 -> V_260 )
F_340 ( V_38 ) ;
F_100 ( V_38 ) ;
F_394 ( V_38 ) ;
F_21 (dev, crtc, encoder)
V_42 -> V_242 ( V_42 ) ;
if ( F_106 ( V_16 ) )
F_353 ( V_16 , V_37 -> V_119 ) ;
}
static bool F_395 ( struct V_37 * V_38 )
{
return F_396 ( V_38 -> V_40 . V_16 ) && V_38 -> V_119 == V_148 ;
}
static void F_397 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 , V_605 ;
struct V_43 * V_211 =
F_283 ( V_38 -> V_36 ) ;
bool V_606 = F_20 ( V_37 , V_259 ) ;
if ( F_9 ( V_37 -> V_112 ) )
return;
if ( F_68 ( V_37 ) )
F_150 ( V_37 ) ;
if ( V_37 -> V_115 -> V_536 )
F_389 ( V_37 , V_602 ) ;
F_390 ( V_37 ) ;
if ( V_37 -> V_115 -> V_121 != V_607 ) {
F_128 ( F_398 ( V_37 -> V_115 -> V_121 ) ,
V_37 -> V_115 -> V_608 - 1 ) ;
}
if ( V_37 -> V_115 -> V_260 ) {
F_391 ( V_37 ,
& V_37 -> V_115 -> V_603 , NULL ) ;
}
F_399 ( V_38 ) ;
F_284 ( V_38 ) ;
V_37 -> V_112 = true ;
F_374 ( V_2 , V_119 , true ) ;
F_21 (dev, crtc, encoder) {
if ( V_42 -> V_609 )
V_42 -> V_609 ( V_42 ) ;
if ( V_42 -> V_604 )
V_42 -> V_604 ( V_42 ) ;
}
if ( V_37 -> V_115 -> V_260 ) {
F_393 ( V_2 , V_255 ,
true ) ;
V_2 -> V_453 . V_532 ( V_38 ) ;
}
if ( ! V_606 )
F_400 ( V_37 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 )
F_286 ( V_37 ) ;
else
F_287 ( V_37 ) ;
F_367 ( V_38 ) ;
F_401 ( V_38 ) ;
if ( ! V_606 )
F_402 ( V_38 ) ;
F_379 ( V_38 ) ;
F_166 ( V_37 ) ;
if ( V_37 -> V_115 -> V_260 )
F_346 ( V_38 ) ;
if ( V_37 -> V_115 -> V_610 && ! V_606 )
F_403 ( V_38 , true ) ;
F_100 ( V_38 ) ;
F_394 ( V_38 ) ;
F_21 (dev, crtc, encoder) {
V_42 -> V_242 ( V_42 ) ;
F_404 ( V_42 , true ) ;
}
V_605 = V_211 -> V_605 ;
if ( F_234 ( V_16 ) && V_605 != V_611 ) {
F_306 ( V_16 , V_605 ) ;
F_306 ( V_16 , V_605 ) ;
}
}
static void F_288 ( struct V_37 * V_38 , bool V_612 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
if ( V_612 || V_38 -> V_115 -> V_466 . V_129 ) {
F_128 ( F_358 ( V_119 ) , 0 ) ;
F_128 ( F_360 ( V_119 ) , 0 ) ;
F_128 ( F_361 ( V_119 ) , 0 ) ;
}
}
static void F_405 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 ;
T_1 V_9 , V_467 ;
F_21 (dev, crtc, encoder)
V_42 -> V_243 ( V_42 ) ;
F_406 ( V_38 ) ;
F_100 ( V_38 ) ;
if ( V_37 -> V_115 -> V_260 )
F_393 ( V_2 , V_119 , false ) ;
F_173 ( V_37 ) ;
F_288 ( V_37 , false ) ;
if ( V_37 -> V_115 -> V_260 )
F_304 ( V_38 ) ;
F_21 (dev, crtc, encoder)
if ( V_42 -> V_613 )
V_42 -> V_613 ( V_42 ) ;
if ( V_37 -> V_115 -> V_260 ) {
F_162 ( V_2 , V_119 ) ;
if ( F_106 ( V_16 ) ) {
V_9 = F_110 ( V_119 ) ;
V_467 = F_11 ( V_9 ) ;
V_467 &= ~ ( V_540 |
V_187 ) ;
V_467 |= V_614 ;
F_128 ( V_9 , V_467 ) ;
V_467 = F_11 ( V_534 ) ;
V_467 &= ~ ( F_343 ( V_119 ) | F_344 ( V_119 ) ) ;
F_128 ( V_534 , V_467 ) ;
}
F_303 ( V_37 ) ;
}
}
static void F_407 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
enum V_118 V_121 = V_37 -> V_115 -> V_121 ;
bool V_606 = F_20 ( V_37 , V_259 ) ;
F_21 (dev, crtc, encoder) {
F_404 ( V_42 , false ) ;
V_42 -> V_243 ( V_42 ) ;
}
F_406 ( V_38 ) ;
F_100 ( V_38 ) ;
if ( V_37 -> V_115 -> V_260 )
F_393 ( V_2 , V_255 ,
false ) ;
F_173 ( V_37 ) ;
if ( V_37 -> V_115 -> V_610 )
F_403 ( V_38 , false ) ;
if ( ! V_606 )
F_408 ( V_2 , V_121 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 )
F_357 ( V_37 ) ;
else
F_288 ( V_37 , false ) ;
if ( ! V_606 )
F_409 ( V_37 ) ;
if ( V_37 -> V_115 -> V_260 ) {
F_165 ( V_2 ) ;
F_410 ( V_38 ) ;
}
F_21 (dev, crtc, encoder)
if ( V_42 -> V_613 )
V_42 -> V_613 ( V_42 ) ;
}
static void F_411 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_43 * V_211 = V_38 -> V_115 ;
if ( ! V_211 -> V_615 . V_616 )
return;
F_9 ( F_11 ( V_617 ) & V_618 ) ;
F_125 ( V_2 , V_38 -> V_119 ) ;
F_128 ( V_619 , V_211 -> V_615 . V_620 ) ;
F_128 ( V_617 , V_211 -> V_615 . V_616 ) ;
F_128 ( F_412 ( V_38 -> V_119 ) , 0 ) ;
}
static enum V_621 F_413 ( enum V_216 V_216 )
{
switch ( V_216 ) {
case V_622 :
return V_623 ;
case V_230 :
return V_624 ;
case V_232 :
return V_625 ;
case V_234 :
return V_626 ;
case V_627 :
return V_628 ;
default:
F_179 ( V_216 ) ;
return V_629 ;
}
}
static enum V_621 F_414 ( enum V_216 V_216 )
{
switch ( V_216 ) {
case V_622 :
return V_630 ;
case V_230 :
return V_631 ;
case V_232 :
return V_632 ;
case V_234 :
return V_633 ;
case V_627 :
return V_633 ;
default:
F_179 ( V_216 ) ;
return V_630 ;
}
}
enum V_621
F_415 ( struct V_41 * V_41 )
{
struct V_15 * V_16 = V_41 -> V_40 . V_16 ;
struct V_225 * V_548 ;
switch ( V_41 -> type ) {
case V_634 :
F_47 ( ! F_71 ( V_16 ) ) ;
case V_635 :
case V_63 :
case V_636 :
V_548 = F_350 ( & V_41 -> V_40 ) ;
return F_413 ( V_548 -> V_216 ) ;
case V_637 :
V_548 = F_416 ( & V_41 -> V_40 ) -> V_113 ;
return F_413 ( V_548 -> V_216 ) ;
case V_64 :
return V_638 ;
case V_259 :
return V_639 ;
default:
return V_629 ;
}
}
enum V_621
F_417 ( struct V_41 * V_41 )
{
struct V_15 * V_16 = V_41 -> V_40 . V_16 ;
struct V_225 * V_548 ;
switch ( V_41 -> type ) {
case V_634 :
case V_63 :
F_47 ( ! F_71 ( V_16 ) ) ;
case V_635 :
case V_636 :
V_548 = F_350 ( & V_41 -> V_40 ) ;
return F_414 ( V_548 -> V_216 ) ;
case V_637 :
V_548 = F_416 ( & V_41 -> V_40 ) -> V_113 ;
return F_414 ( V_548 -> V_216 ) ;
default:
F_179 ( V_41 -> type ) ;
return V_630 ;
}
}
static unsigned long F_418 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_41 * V_41 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_119 V_119 = V_37 -> V_119 ;
unsigned long V_640 ;
enum V_118 V_118 ;
if ( ! V_38 -> V_36 -> V_112 )
return 0 ;
V_118 = F_55 ( V_16 -> V_17 , V_119 ) ;
V_640 = F_229 ( F_419 ( V_119 ) ) ;
V_640 |= F_229 ( F_87 ( V_118 ) ) ;
if ( V_37 -> V_115 -> V_466 . V_129 ||
V_37 -> V_115 -> V_466 . V_641 )
V_640 |= F_229 ( F_420 ( V_119 ) ) ;
F_21 (dev, crtc, intel_encoder)
V_640 |= F_229 ( F_415 ( V_41 ) ) ;
return V_640 ;
}
static unsigned long F_421 ( struct V_111 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_621 V_642 ;
unsigned long V_643 , V_644 , V_645 ;
V_645 = V_37 -> V_646 ;
V_37 -> V_646 = V_644 = F_418 ( V_38 ) ;
V_643 = V_644 & ~ V_645 ;
F_422 (domain, domains)
F_153 ( V_2 , V_642 ) ;
return V_645 & ~ V_644 ;
}
static void F_423 ( struct V_1 * V_2 ,
unsigned long V_643 )
{
enum V_621 V_642 ;
F_422 (domain, domains)
F_156 ( V_2 , V_642 ) ;
}
static void F_424 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
unsigned long V_647 [ V_648 ] = {} ;
struct V_35 * V_44 ;
struct V_111 * V_38 ;
int V_50 ;
F_425 (state, crtc, crtc_state, i) {
if ( F_18 ( V_38 -> V_36 ) )
V_647 [ F_50 ( V_38 ) -> V_119 ] =
F_421 ( V_38 ) ;
}
if ( V_2 -> V_453 . V_649 ) {
unsigned int V_650 = F_352 ( V_36 ) -> V_650 ;
if ( V_650 != V_2 -> V_651 &&
! F_9 ( ! V_36 -> V_652 ) )
V_2 -> V_453 . V_649 ( V_36 ) ;
}
for ( V_50 = 0 ; V_50 < V_648 ; V_50 ++ )
if ( V_647 [ V_50 ] )
F_423 ( V_2 , V_647 [ V_50 ] ) ;
}
static int F_426 ( struct V_1 * V_2 )
{
int V_653 = V_2 -> V_653 ;
if ( F_60 ( V_2 ) -> V_127 >= 9 ||
F_234 ( V_2 ) || F_235 ( V_2 ) )
return V_653 ;
else if ( F_32 ( V_2 ) )
return V_653 * 95 / 100 ;
else if ( F_60 ( V_2 ) -> V_127 < 4 )
return 2 * V_653 * 90 / 100 ;
else
return V_653 * 90 / 100 ;
}
static void F_427 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_428 ( V_16 ) ) {
T_1 V_54 = F_11 ( V_654 ) & V_655 ;
if ( V_54 == V_656 )
V_2 -> V_653 = 675000 ;
else if ( V_54 == V_657 )
V_2 -> V_653 = 540000 ;
else if ( V_54 == V_658 )
V_2 -> V_653 = 450000 ;
else
V_2 -> V_653 = 337500 ;
} else if ( F_235 ( V_16 ) ) {
if ( F_11 ( V_659 ) & V_660 )
V_2 -> V_653 = 450000 ;
else if ( F_429 ( V_16 ) )
V_2 -> V_653 = 450000 ;
else if ( F_430 ( V_16 ) )
V_2 -> V_653 = 540000 ;
else
V_2 -> V_653 = 675000 ;
} else if ( F_32 ( V_16 ) ) {
V_2 -> V_653 = 320000 ;
} else if ( F_13 ( V_16 ) ) {
V_2 -> V_653 = 400000 ;
} else {
V_2 -> V_653 = V_2 -> V_651 ;
}
V_2 -> V_661 = F_426 ( V_2 ) ;
F_15 ( L_97 ,
V_2 -> V_653 ) ;
F_15 ( L_98 ,
V_2 -> V_661 ) ;
}
static void F_431 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_651 = V_2 -> V_453 . V_662 ( V_16 ) ;
F_15 ( L_99 ,
V_2 -> V_651 ) ;
if ( F_13 ( V_16 ) ) {
F_128 ( V_663 , F_184 ( V_2 -> V_651 , 1000 ) ) ;
}
if ( V_2 -> V_653 == 0 )
F_427 ( V_16 ) ;
}
static void F_432 ( struct V_15 * V_16 , int V_664 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_11 ;
T_2 V_665 ;
T_2 V_666 ;
int V_307 ;
switch ( V_664 ) {
case 144000 :
V_11 = V_667 ;
V_665 = F_433 ( 60 ) ;
break;
case 288000 :
V_11 = V_668 ;
V_665 = F_433 ( 60 ) ;
break;
case 384000 :
V_11 = V_669 ;
V_665 = F_433 ( 60 ) ;
break;
case 576000 :
V_11 = V_670 ;
V_665 = F_433 ( 60 ) ;
break;
case 624000 :
V_11 = V_670 ;
V_665 = F_433 ( 65 ) ;
break;
case 19200 :
V_665 = 0 ;
V_11 = 0 ;
break;
default:
F_131 ( L_100 , V_664 ) ;
return;
}
F_2 ( & V_2 -> V_574 . V_575 ) ;
V_307 = F_364 ( V_2 , V_671 ,
0x80000000 ) ;
F_4 ( & V_2 -> V_574 . V_575 ) ;
if ( V_307 ) {
F_131 ( L_101 ,
V_307 , V_664 ) ;
return;
}
V_666 = F_11 ( V_672 ) & V_673 ;
V_666 = V_666 * 500 + 1000 ;
if ( V_664 == 19200 || V_664 == 624000 ||
V_666 == 624000 ) {
F_128 ( V_674 , ~ V_675 ) ;
if ( F_62 ( ! ( F_11 ( V_674 ) & V_676 ) ,
1 ) )
F_131 ( L_102 ) ;
}
if ( V_664 != 19200 ) {
T_2 V_10 ;
V_10 = F_11 ( V_677 ) ;
V_10 &= ~ V_678 ;
V_10 |= V_665 ;
F_128 ( V_677 , V_10 ) ;
F_128 ( V_674 , V_675 ) ;
if ( F_62 ( F_11 ( V_674 ) & V_676 , 1 ) )
F_131 ( L_103 ) ;
V_10 = F_11 ( V_672 ) ;
V_10 &= ~ V_679 ;
V_10 |= V_11 ;
V_10 &= ~ V_680 ;
if ( V_664 >= 500000 )
V_10 |= V_680 ;
V_10 &= ~ V_673 ;
V_10 |= ( V_664 - 1000 ) / 500 ;
F_128 ( V_672 , V_10 ) ;
}
F_2 ( & V_2 -> V_574 . V_575 ) ;
V_307 = F_364 ( V_2 , V_671 ,
F_184 ( V_664 , 25000 ) ) ;
F_4 ( & V_2 -> V_574 . V_575 ) ;
if ( V_307 ) {
F_131 ( L_104 ,
V_307 , V_664 ) ;
return;
}
F_431 ( V_16 ) ;
}
void F_434 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_10 ;
V_10 = F_11 ( V_681 ) ;
V_10 &= ~ V_682 ;
F_128 ( V_681 , V_10 ) ;
F_153 ( V_2 , V_241 ) ;
if ( F_11 ( V_674 ) & V_675 ) {
F_151 ( L_105 ) ;
return;
}
F_432 ( V_16 , 624000 ) ;
F_128 ( V_683 , F_11 ( V_683 ) | V_684 ) ;
F_129 ( V_683 ) ;
F_130 ( 10 ) ;
if ( ! ( F_11 ( V_683 ) & V_685 ) )
F_131 ( L_106 ) ;
}
void F_435 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
F_128 ( V_683 , F_11 ( V_683 ) & ~ V_684 ) ;
F_129 ( V_683 ) ;
F_130 ( 10 ) ;
if ( F_11 ( V_683 ) & V_685 )
F_131 ( L_107 ) ;
F_432 ( V_16 , 19200 ) ;
F_156 ( V_2 , V_241 ) ;
}
static unsigned int F_436 ( unsigned int V_686 )
{
return ( V_686 - 1000 ) / 500 ;
}
static unsigned int F_437 ( unsigned int V_686 )
{
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < F_301 ( V_687 ) ; V_50 ++ ) {
const struct V_688 * V_689 = & V_687 [ V_50 ] ;
if ( V_689 -> V_686 == V_686 )
return V_689 -> V_85 ;
}
return 8100 ;
}
static void
F_438 ( struct V_1 * V_2 , unsigned int V_690 )
{
unsigned int V_691 ;
T_1 V_10 ;
V_10 = F_11 ( V_672 ) ;
V_10 &= ~ V_692 | ~ V_673 ;
V_10 |= V_693 ;
if ( V_690 == 8640 )
V_691 = 308570 ;
else
V_691 = 337500 ;
V_10 = V_693 | F_436 ( V_691 ) ;
F_128 ( V_672 , V_10 ) ;
F_129 ( V_672 ) ;
V_10 = F_11 ( V_694 ) ;
V_10 &= ~ ( F_439 ( V_695 ) | F_440 ( V_695 ) |
F_441 ( V_695 ) ) ;
V_10 |= F_442 ( V_695 ) ;
if ( V_690 == 8640 )
V_10 |= F_443 ( V_696 ,
V_695 ) ;
else
V_10 |= F_443 ( V_697 ,
V_695 ) ;
F_128 ( V_694 , V_10 ) ;
F_129 ( V_694 ) ;
F_128 ( V_698 , F_11 ( V_698 ) | V_699 ) ;
if ( F_62 ( F_11 ( V_698 ) & V_700 , 5 ) )
F_131 ( L_108 ) ;
}
static bool F_444 ( struct V_1 * V_2 )
{
int V_307 ;
T_1 V_10 ;
V_10 = V_701 ;
F_2 ( & V_2 -> V_574 . V_575 ) ;
V_307 = F_445 ( V_2 , V_702 , & V_10 ) ;
F_4 ( & V_2 -> V_574 . V_575 ) ;
return V_307 == 0 && ( V_10 & V_703 ) ;
}
static bool F_446 ( struct V_1 * V_2 )
{
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < 15 ; V_50 ++ ) {
if ( F_444 ( V_2 ) )
return true ;
F_130 ( 10 ) ;
}
return false ;
}
static void F_447 ( struct V_1 * V_2 , unsigned int V_686 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_1 V_704 , V_705 ;
F_15 ( L_109 , V_686 ) ;
if ( ! F_446 ( V_2 ) ) {
F_131 ( L_110 ) ;
return;
}
switch( V_686 ) {
case 450000 :
case 432000 :
V_704 = V_706 ;
V_705 = 1 ;
break;
case 540000 :
V_704 = V_707 ;
V_705 = 2 ;
break;
case 308570 :
case 337500 :
default:
V_704 = V_693 ;
V_705 = 0 ;
break;
case 617140 :
case 675000 :
V_704 = V_708 ;
V_705 = 3 ;
break;
}
F_128 ( V_672 , V_704 | F_436 ( V_686 ) ) ;
F_129 ( V_672 ) ;
F_2 ( & V_2 -> V_574 . V_575 ) ;
F_364 ( V_2 , V_702 , V_705 ) ;
F_4 ( & V_2 -> V_574 . V_575 ) ;
F_431 ( V_16 ) ;
}
void F_448 ( struct V_1 * V_2 )
{
F_128 ( V_683 , F_11 ( V_683 ) & ~ V_684 ) ;
F_129 ( V_683 ) ;
F_130 ( 10 ) ;
if ( F_11 ( V_683 ) & V_685 )
F_131 ( L_111 ) ;
if ( V_2 -> V_709 . V_710 ) {
F_128 ( V_698 , F_11 ( V_698 ) &
~ V_699 ) ;
if ( F_62 ( ! ( F_11 ( V_698 ) & V_700 ) , 1 ) )
F_131 ( L_112 ) ;
}
F_156 ( V_2 , V_241 ) ;
}
void F_449 ( struct V_1 * V_2 )
{
T_1 V_10 ;
unsigned int V_690 ;
V_10 = F_11 ( V_681 ) ;
F_128 ( V_681 , V_10 | V_682 ) ;
F_153 ( V_2 , V_241 ) ;
if ( ! ( F_11 ( V_698 ) & V_699 ) ) {
V_690 = F_437 ( V_2 -> V_711 ) ;
F_438 ( V_2 , V_690 ) ;
}
F_447 ( V_2 , V_2 -> V_711 ) ;
F_128 ( V_683 , F_11 ( V_683 ) | V_684 ) ;
F_129 ( V_683 ) ;
F_130 ( 10 ) ;
if ( ! ( F_11 ( V_683 ) & V_685 ) )
F_131 ( L_113 ) ;
}
static void F_450 ( struct V_15 * V_16 , int V_650 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 , V_712 ;
F_9 ( V_2 -> V_453 . V_662 ( V_16 )
!= V_2 -> V_651 ) ;
if ( V_650 >= 320000 )
V_712 = 2 ;
else if ( V_650 == 266667 )
V_712 = 1 ;
else
V_712 = 0 ;
F_2 ( & V_2 -> V_574 . V_575 ) ;
V_10 = F_451 ( V_2 , V_713 ) ;
V_10 &= ~ V_714 ;
V_10 |= ( V_712 << V_715 ) ;
F_452 ( V_2 , V_713 , V_10 ) ;
if ( F_62 ( ( F_451 ( V_2 , V_713 ) &
V_716 ) == ( V_712 << V_717 ) ,
50 ) ) {
F_131 ( L_114 ) ;
}
F_4 ( & V_2 -> V_574 . V_575 ) ;
F_2 ( & V_2 -> V_5 ) ;
if ( V_650 == 400000 ) {
T_1 V_11 ;
V_11 = F_7 ( V_2 -> V_3 << 1 , V_650 ) - 1 ;
V_10 = F_3 ( V_2 , V_718 ) ;
V_10 &= ~ V_12 ;
V_10 |= V_11 ;
F_453 ( V_2 , V_718 , V_10 ) ;
if ( F_62 ( ( F_3 ( V_2 , V_718 ) &
V_13 ) == ( V_11 << V_14 ) ,
50 ) )
F_131 ( L_114 ) ;
}
V_10 = F_454 ( V_2 , V_719 ) ;
V_10 &= ~ 0x7f ;
if ( V_650 == 400000 )
V_10 |= 4500 / 250 ;
else
V_10 |= 3000 / 250 ;
F_455 ( V_2 , V_719 , V_10 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_431 ( V_16 ) ;
}
static void F_456 ( struct V_15 * V_16 , int V_650 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 , V_712 ;
F_9 ( V_2 -> V_453 . V_662 ( V_16 )
!= V_2 -> V_651 ) ;
switch ( V_650 ) {
case 333333 :
case 320000 :
case 266667 :
case 200000 :
break;
default:
F_179 ( V_650 ) ;
return;
}
V_712 = F_7 ( V_2 -> V_3 << 1 , V_650 ) - 1 ;
F_2 ( & V_2 -> V_574 . V_575 ) ;
V_10 = F_451 ( V_2 , V_713 ) ;
V_10 &= ~ V_720 ;
V_10 |= ( V_712 << V_721 ) ;
F_452 ( V_2 , V_713 , V_10 ) ;
if ( F_62 ( ( F_451 ( V_2 , V_713 ) &
V_722 ) == ( V_712 << V_723 ) ,
50 ) ) {
F_131 ( L_114 ) ;
}
F_4 ( & V_2 -> V_574 . V_575 ) ;
F_431 ( V_16 ) ;
}
static int F_457 ( struct V_1 * V_2 ,
int V_724 )
{
int V_725 = ( V_2 -> V_3 << 1 ) % 320000 != 0 ? 333333 : 320000 ;
int V_54 = F_32 ( V_2 ) ? 95 : 90 ;
if ( ! F_32 ( V_2 ) &&
V_724 > V_725 * V_54 / 100 )
return 400000 ;
else if ( V_724 > 266667 * V_54 / 100 )
return V_725 ;
else if ( V_724 > 0 )
return 266667 ;
else
return 200000 ;
}
static int F_458 ( struct V_1 * V_2 ,
int V_724 )
{
if ( V_724 > 576000 * 9 / 10 )
return 624000 ;
else if ( V_724 > 384000 * 9 / 10 )
return 576000 ;
else if ( V_724 > 288000 * 9 / 10 )
return 384000 ;
else if ( V_724 > 144000 * 9 / 10 )
return 288000 ;
else
return 144000 ;
}
static int F_459 ( struct V_15 * V_16 ,
struct V_45 * V_36 )
{
struct V_37 * V_37 ;
struct V_43 * V_44 ;
int V_724 = 0 ;
F_139 (dev, intel_crtc) {
V_44 = F_460 ( V_36 , V_37 ) ;
if ( F_461 ( V_44 ) )
return F_462 ( V_44 ) ;
if ( ! V_44 -> V_40 . V_242 )
continue;
V_724 = V_91 ( V_724 ,
V_44 -> V_40 . V_116 . V_117 ) ;
}
return V_724 ;
}
static int F_463 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_724 = F_459 ( V_16 , V_36 ) ;
if ( V_724 < 0 )
return V_724 ;
F_352 ( V_36 ) -> V_650 =
F_457 ( V_2 , V_724 ) ;
return 0 ;
}
static int F_464 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_724 = F_459 ( V_16 , V_36 ) ;
if ( V_724 < 0 )
return V_724 ;
F_352 ( V_36 ) -> V_650 =
F_458 ( V_2 , V_724 ) ;
return 0 ;
}
static void F_465 ( struct V_1 * V_2 )
{
unsigned int V_726 , V_727 ;
if ( F_32 ( V_2 ) )
V_727 = F_466 ( 12 ) ;
else
V_727 = F_466 ( 8 ) ;
if ( V_2 -> V_651 >= V_2 -> V_31 ) {
if ( F_32 ( V_2 ) )
V_726 = V_728 ;
else
V_726 = F_466 ( 15 ) ;
} else {
V_726 = V_727 ;
}
F_128 ( V_729 , V_730 |
V_727 ) ;
F_128 ( V_729 , V_730 |
V_726 | V_731 ) ;
F_9 ( F_11 ( V_729 ) & V_731 ) ;
}
static void F_467 ( struct V_45 * V_732 )
{
struct V_15 * V_16 = V_732 -> V_16 ;
unsigned int V_733 = F_352 ( V_732 ) -> V_650 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_153 ( V_2 , V_734 ) ;
if ( F_32 ( V_16 ) )
F_456 ( V_16 , V_733 ) ;
else
F_450 ( V_16 , V_733 ) ;
F_465 ( V_2 ) ;
F_156 ( V_2 , V_734 ) ;
}
static void F_468 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = F_203 ( V_16 ) ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 ;
bool V_606 ;
if ( F_9 ( V_37 -> V_112 ) )
return;
V_606 = F_20 ( V_37 , V_259 ) ;
if ( V_37 -> V_115 -> V_536 )
F_389 ( V_37 , V_602 ) ;
F_390 ( V_37 ) ;
if ( F_32 ( V_16 ) && V_119 == V_157 ) {
struct V_1 * V_2 = V_16 -> V_17 ;
F_128 ( F_469 ( V_119 ) , V_735 ) ;
F_128 ( F_470 ( V_119 ) , 0 ) ;
}
F_471 ( V_37 ) ;
V_37 -> V_112 = true ;
F_374 ( V_2 , V_119 , true ) ;
F_21 (dev, crtc, encoder)
if ( V_42 -> V_609 )
V_42 -> V_609 ( V_42 ) ;
if ( ! V_606 ) {
if ( F_32 ( V_16 ) ) {
F_472 ( V_37 , V_37 -> V_115 ) ;
F_133 ( V_37 , V_37 -> V_115 ) ;
} else {
F_473 ( V_37 , V_37 -> V_115 ) ;
F_124 ( V_37 , V_37 -> V_115 ) ;
}
}
F_21 (dev, crtc, encoder)
if ( V_42 -> V_604 )
V_42 -> V_604 ( V_42 ) ;
F_411 ( V_37 ) ;
F_367 ( V_38 ) ;
F_166 ( V_37 ) ;
F_100 ( V_38 ) ;
F_394 ( V_38 ) ;
F_21 (dev, crtc, encoder)
V_42 -> V_242 ( V_42 ) ;
}
static void F_474 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_128 ( F_475 ( V_38 -> V_119 ) , V_38 -> V_115 -> V_212 . V_736 ) ;
F_128 ( F_476 ( V_38 -> V_119 ) , V_38 -> V_115 -> V_212 . V_737 ) ;
}
static void F_477 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = F_203 ( V_16 ) ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 ;
if ( F_9 ( V_37 -> V_112 ) )
return;
F_474 ( V_37 ) ;
if ( V_37 -> V_115 -> V_536 )
F_389 ( V_37 , V_602 ) ;
F_390 ( V_37 ) ;
F_471 ( V_37 ) ;
V_37 -> V_112 = true ;
if ( ! F_33 ( V_16 ) )
F_374 ( V_2 , V_119 , true ) ;
F_21 (dev, crtc, encoder)
if ( V_42 -> V_604 )
V_42 -> V_604 ( V_42 ) ;
F_140 ( V_37 ) ;
F_411 ( V_37 ) ;
F_367 ( V_38 ) ;
F_379 ( V_38 ) ;
F_166 ( V_37 ) ;
F_100 ( V_38 ) ;
F_394 ( V_38 ) ;
F_21 (dev, crtc, encoder)
V_42 -> V_242 ( V_42 ) ;
}
static void F_478 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! V_38 -> V_115 -> V_615 . V_616 )
return;
F_125 ( V_2 , V_38 -> V_119 ) ;
F_15 ( L_115 ,
F_11 ( V_617 ) ) ;
F_128 ( V_617 , 0 ) ;
}
static void F_479 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_41 * V_42 ;
int V_119 = V_37 -> V_119 ;
F_306 ( V_16 , V_119 ) ;
F_21 (dev, crtc, encoder)
V_42 -> V_243 ( V_42 ) ;
F_406 ( V_38 ) ;
F_100 ( V_38 ) ;
F_173 ( V_37 ) ;
F_478 ( V_37 ) ;
F_21 (dev, crtc, encoder)
if ( V_42 -> V_613 )
V_42 -> V_613 ( V_42 ) ;
if ( ! F_20 ( V_37 , V_259 ) ) {
if ( F_32 ( V_16 ) )
F_144 ( V_2 , V_119 ) ;
else if ( F_13 ( V_16 ) )
F_143 ( V_2 , V_119 ) ;
else
F_142 ( V_37 ) ;
}
F_21 (dev, crtc, encoder)
if ( V_42 -> V_738 )
V_42 -> V_738 ( V_42 ) ;
if ( ! F_33 ( V_16 ) )
F_374 ( V_2 , V_119 , false ) ;
}
static void F_480 ( struct V_111 * V_38 )
{
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_1 * V_2 = F_203 ( V_38 -> V_16 ) ;
enum V_621 V_642 ;
unsigned long V_643 ;
if ( ! V_37 -> V_112 )
return;
if ( F_218 ( V_38 -> V_113 -> V_36 ) -> V_365 ) {
F_313 ( V_38 ) ;
F_220 ( V_38 ) ;
F_386 ( V_38 , 1 << F_219 ( V_38 -> V_113 ) ) ;
F_218 ( V_38 -> V_113 -> V_36 ) -> V_365 = false ;
}
V_2 -> V_453 . V_739 ( V_38 ) ;
V_37 -> V_112 = false ;
F_379 ( V_38 ) ;
F_154 ( V_37 ) ;
V_643 = V_37 -> V_646 ;
F_422 (domain, domains)
F_156 ( V_2 , V_642 ) ;
V_37 -> V_646 = 0 ;
}
int F_267 ( struct V_15 * V_16 )
{
struct V_740 * V_115 = & V_16 -> V_741 ;
struct V_742 * V_743 = V_115 -> V_744 ;
struct V_45 * V_36 ;
struct V_111 * V_38 ;
unsigned V_237 = 0 ;
int V_307 = 0 ;
if ( F_9 ( ! V_743 ) )
return 0 ;
F_481 ( & V_743 -> V_745 ) ;
V_36 = F_482 ( V_16 ) ;
if ( F_9 ( ! V_36 ) )
return - V_746 ;
V_36 -> V_744 = V_743 ;
V_36 -> V_652 = true ;
F_216 (dev, crtc) {
struct V_35 * V_44 =
F_483 ( V_36 , V_38 ) ;
V_307 = F_484 ( V_44 ) ;
if ( V_307 )
goto free;
if ( ! V_44 -> V_112 )
continue;
V_44 -> V_112 = false ;
V_237 |= 1 << F_155 ( V_38 ) ;
}
if ( V_237 ) {
V_307 = F_485 ( V_36 ) ;
if ( ! V_307 ) {
F_216 (dev, crtc)
if ( V_237 & ( 1 << F_155 ( V_38 ) ) )
V_38 -> V_36 -> V_112 = true ;
return V_307 ;
}
}
free:
if ( V_307 )
F_131 ( L_116 , V_307 ) ;
F_486 ( V_36 ) ;
return V_307 ;
}
void F_487 ( struct V_747 * V_42 )
{
struct V_41 * V_41 = F_24 ( V_42 ) ;
F_488 ( V_42 ) ;
F_215 ( V_41 ) ;
}
static void F_489 ( struct V_748 * V_47 )
{
struct V_111 * V_38 = V_47 -> V_40 . V_36 -> V_38 ;
F_151 ( L_117 ,
V_47 -> V_40 . V_40 . V_240 ,
V_47 -> V_40 . V_8 ) ;
if ( V_47 -> V_140 ( V_47 ) ) {
struct V_41 * V_42 = V_47 -> V_42 ;
struct V_48 * V_749 = V_47 -> V_40 . V_36 ;
F_66 ( ! V_38 ,
L_118 ) ;
if ( ! V_38 )
return;
F_66 ( ! V_38 -> V_36 -> V_112 ,
L_119 ) ;
if ( ! V_42 || V_42 -> type == V_637 )
return;
F_66 ( V_749 -> V_52 != & V_42 -> V_40 ,
L_120 ) ;
F_66 ( V_749 -> V_38 != V_42 -> V_40 . V_38 ,
L_121 ) ;
} else {
F_66 ( V_38 && V_38 -> V_36 -> V_112 ,
L_122 ) ;
F_66 ( ! V_38 && V_47 -> V_40 . V_36 -> V_52 ,
L_123 ) ;
}
}
int F_490 ( struct V_748 * V_47 )
{
struct V_48 * V_49 ;
V_49 = F_491 ( sizeof *V_49 , V_750 ) ;
if ( ! V_49 )
return - V_746 ;
V_47 -> V_40 . V_36 = V_49 ;
return 0 ;
}
struct V_748 * F_492 ( void )
{
struct V_748 * V_47 ;
V_47 = F_491 ( sizeof *V_47 , V_750 ) ;
if ( ! V_47 )
return NULL ;
if ( F_490 ( V_47 ) < 0 ) {
F_215 ( V_47 ) ;
return NULL ;
}
return V_47 ;
}
bool F_493 ( struct V_748 * V_47 )
{
enum V_119 V_119 = 0 ;
struct V_41 * V_42 = V_47 -> V_42 ;
return V_42 -> V_140 ( V_42 , & V_119 ) ;
}
static int F_494 ( struct V_43 * V_44 )
{
if ( V_44 -> V_40 . V_242 && V_44 -> V_260 )
return V_44 -> V_480 ;
return 0 ;
}
static int F_495 ( struct V_15 * V_16 , enum V_119 V_119 ,
struct V_43 * V_211 )
{
struct V_45 * V_36 = V_211 -> V_40 . V_36 ;
struct V_37 * V_751 ;
struct V_43 * V_752 ;
F_151 ( L_124 ,
F_80 ( V_119 ) , V_211 -> V_480 ) ;
if ( V_211 -> V_480 > 4 ) {
F_151 ( L_125 ,
F_80 ( V_119 ) , V_211 -> V_480 ) ;
return - V_309 ;
}
if ( F_234 ( V_16 ) || F_235 ( V_16 ) ) {
if ( V_211 -> V_480 > 2 ) {
F_151 ( L_126 ,
V_211 -> V_480 ) ;
return - V_309 ;
} else {
return 0 ;
}
}
if ( F_60 ( V_16 ) -> V_753 == 2 )
return 0 ;
switch ( V_119 ) {
case V_148 :
return 0 ;
case V_157 :
if ( V_211 -> V_480 <= 2 )
return 0 ;
V_751 = F_50 ( F_496 ( V_16 , V_530 ) ) ;
V_752 =
F_460 ( V_36 , V_751 ) ;
if ( F_461 ( V_752 ) )
return F_462 ( V_752 ) ;
if ( F_494 ( V_752 ) > 0 ) {
F_151 ( L_127 ,
F_80 ( V_119 ) , V_211 -> V_480 ) ;
return - V_309 ;
}
return 0 ;
case V_530 :
if ( V_211 -> V_480 > 2 ) {
F_151 ( L_128 ,
F_80 ( V_119 ) , V_211 -> V_480 ) ;
return - V_309 ;
}
V_751 = F_50 ( F_496 ( V_16 , V_157 ) ) ;
V_752 =
F_460 ( V_36 , V_751 ) ;
if ( F_461 ( V_752 ) )
return F_462 ( V_752 ) ;
if ( F_494 ( V_752 ) > 2 ) {
F_151 ( L_129 ) ;
return - V_309 ;
}
return 0 ;
default:
F_146 () ;
}
}
static int F_497 ( struct V_37 * V_37 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
const struct V_563 * V_116 = & V_211 -> V_40 . V_116 ;
int V_754 , V_755 , V_756 , V_307 ;
bool V_757 = false ;
V_485:
V_755 = F_16 ( V_16 ) * F_498 ( 100 ) / F_499 ( 1 ) / 10 ;
V_756 = V_116 -> V_117 ;
V_754 = F_500 ( V_756 , V_755 ,
V_211 -> V_758 ) ;
V_211 -> V_480 = V_754 ;
F_501 ( V_211 -> V_758 , V_754 , V_756 ,
V_755 , & V_211 -> V_603 ) ;
V_307 = F_495 ( V_37 -> V_40 . V_16 ,
V_37 -> V_119 , V_211 ) ;
if ( V_307 == - V_309 && V_211 -> V_758 > 6 * 3 ) {
V_211 -> V_758 -= 2 * 3 ;
F_151 ( L_130 ,
V_211 -> V_758 ) ;
V_757 = true ;
V_211 -> V_759 = true ;
goto V_485;
}
if ( V_757 )
return V_760 ;
return V_307 ;
}
static bool F_502 ( struct V_1 * V_2 ,
struct V_43 * V_211 )
{
if ( V_211 -> V_758 > 24 )
return false ;
if ( F_234 ( V_2 -> V_16 ) )
return true ;
return F_503 ( V_211 ) <=
V_2 -> V_653 * 95 / 100 ;
}
static void F_504 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
V_211 -> V_573 = V_761 . V_762 &&
F_395 ( V_38 ) &&
F_502 ( V_2 , V_211 ) ;
}
static int F_505 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
const struct V_563 * V_116 = & V_211 -> V_40 . V_116 ;
if ( F_60 ( V_16 ) -> V_127 < 4 ) {
int V_763 = V_2 -> V_653 ;
if ( ( V_38 -> V_119 == V_148 || F_506 ( V_16 ) ) &&
V_116 -> V_117 > V_763 * 9 / 10 ) {
V_763 *= 2 ;
V_211 -> V_261 = true ;
}
if ( V_116 -> V_117 > V_763 * 9 / 10 )
return - V_309 ;
}
if ( ( F_22 ( V_211 , V_55 ) &&
F_26 ( V_16 ) ) || V_211 -> V_261 )
V_211 -> V_385 &= ~ 1 ;
if ( ( F_60 ( V_16 ) -> V_127 > 4 || F_30 ( V_16 ) ) &&
V_116 -> V_764 == V_116 -> V_565 )
return - V_309 ;
if ( F_396 ( V_16 ) )
F_504 ( V_38 , V_211 ) ;
if ( V_211 -> V_260 )
return F_497 ( V_38 , V_211 ) ;
return 0 ;
}
static int F_507 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_203 ( V_16 ) ;
T_2 V_765 = F_11 ( V_698 ) ;
T_2 V_766 = F_11 ( V_672 ) ;
T_2 V_767 ;
if ( ! ( V_765 & V_699 ) )
return 24000 ;
if ( ( V_766 & V_692 ) == V_707 )
return 540000 ;
V_767 = ( F_11 ( V_694 ) &
F_441 ( V_695 ) ) >> 1 ;
if ( V_767 == V_768 ||
V_767 == V_696 ) {
switch ( V_766 & V_692 ) {
case V_706 :
return 432000 ;
case V_693 :
return 308570 ;
case V_708 :
return 617140 ;
default:
F_6 ( 1 , L_131 ) ;
}
} else {
switch ( V_766 & V_692 ) {
case V_706 :
return 450000 ;
case V_693 :
return 337500 ;
case V_708 :
return 675000 ;
default:
F_6 ( 1 , L_131 ) ;
}
}
return 24000 ;
}
static int F_508 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_203 ( V_16 ) ;
T_2 V_766 = F_11 ( V_672 ) ;
T_2 V_769 = F_11 ( V_677 ) & V_678 ;
T_2 V_770 = F_11 ( V_674 ) ;
int V_650 ;
if ( ! ( V_770 & V_675 ) )
return 19200 ;
V_650 = 19200 * V_769 / 2 ;
switch ( V_766 & V_679 ) {
case V_670 :
return V_650 ;
case V_669 :
return V_650 * 2 / 3 ;
case V_668 :
return V_650 / 2 ;
case V_667 :
return V_650 / 4 ;
}
return 19200 ;
}
static int F_509 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_771 = F_11 ( V_772 ) ;
T_2 V_686 = V_771 & V_773 ;
if ( V_771 & V_774 )
return 800000 ;
else if ( F_11 ( V_659 ) & V_660 )
return 450000 ;
else if ( V_686 == V_775 )
return 450000 ;
else if ( V_686 == V_776 )
return 540000 ;
else if ( V_686 == V_777 )
return 337500 ;
else
return 675000 ;
}
static int F_510 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_771 = F_11 ( V_772 ) ;
T_2 V_686 = V_771 & V_773 ;
if ( V_771 & V_774 )
return 800000 ;
else if ( F_11 ( V_659 ) & V_660 )
return 450000 ;
else if ( V_686 == V_775 )
return 450000 ;
else if ( F_511 ( V_16 ) )
return 337500 ;
else
return 540000 ;
}
static int F_512 ( struct V_15 * V_16 )
{
return F_5 ( F_203 ( V_16 ) , L_132 ,
V_718 ) ;
}
static int F_513 ( struct V_15 * V_16 )
{
return 450000 ;
}
static int F_514 ( struct V_15 * V_16 )
{
return 400000 ;
}
static int F_515 ( struct V_15 * V_16 )
{
return 333333 ;
}
static int F_516 ( struct V_15 * V_16 )
{
return 200000 ;
}
static int F_517 ( struct V_15 * V_16 )
{
T_5 V_778 = 0 ;
F_518 ( V_16 -> V_779 , V_780 , & V_778 ) ;
switch ( V_778 & V_781 ) {
case V_782 :
return 266667 ;
case V_783 :
return 333333 ;
case V_784 :
return 444444 ;
case V_785 :
return 200000 ;
default:
F_131 ( L_133 , V_778 ) ;
case V_786 :
return 133333 ;
case V_787 :
return 166667 ;
}
}
static int F_519 ( struct V_15 * V_16 )
{
T_5 V_778 = 0 ;
F_518 ( V_16 -> V_779 , V_780 , & V_778 ) ;
if ( V_778 & V_788 )
return 133333 ;
else {
switch ( V_778 & V_781 ) {
case V_789 :
return 333333 ;
default:
case V_790 :
return 190000 ;
}
}
}
static int F_520 ( struct V_15 * V_16 )
{
return 266667 ;
}
static int F_521 ( struct V_15 * V_16 )
{
T_5 V_791 = 0 ;
if ( V_16 -> V_779 -> V_792 == 0x1 )
return 133333 ;
F_522 ( V_16 -> V_779 -> V_793 ,
F_523 ( 0 , 3 ) , V_794 , & V_791 ) ;
switch ( V_791 & V_795 ) {
case V_796 :
case V_797 :
case V_798 :
return 200000 ;
case V_799 :
return 250000 ;
case V_800 :
return 133333 ;
case V_801 :
case V_802 :
case V_803 :
return 266667 ;
}
return 0 ;
}
static int F_524 ( struct V_15 * V_16 )
{
return 133333 ;
}
static unsigned int F_525 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
static const unsigned int V_804 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 6400000 ,
} ;
static const unsigned int V_805 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 2666667 ,
} ;
static const unsigned int V_806 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 3333333 ,
[ 5 ] = 3566667 ,
[ 6 ] = 4266667 ,
} ;
static const unsigned int V_807 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
} ;
static const unsigned int V_808 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 2666667 ,
[ 5 ] = 4266667 ,
} ;
const unsigned int * V_809 ;
unsigned int V_85 ;
T_6 V_217 = 0 ;
if ( F_526 ( V_16 ) )
V_809 = V_808 ;
else if ( F_30 ( V_16 ) )
V_809 = V_807 ;
else if ( F_187 ( V_16 ) )
V_809 = V_806 ;
else if ( F_31 ( V_16 ) )
V_809 = V_805 ;
else if ( F_527 ( V_16 ) )
V_809 = V_804 ;
else
return 0 ;
V_217 = F_11 ( F_127 ( V_16 ) ? V_810 : V_811 ) ;
V_85 = V_809 [ V_217 & 0x7 ] ;
if ( V_85 == 0 )
F_131 ( L_134 , V_217 ) ;
else
F_151 ( L_135 , V_85 ) ;
return V_85 ;
}
static int F_528 ( struct V_15 * V_16 )
{
unsigned int V_812 , V_85 = F_525 ( V_16 ) ;
T_7 V_217 = 0 ;
F_518 ( V_16 -> V_779 , V_780 , & V_217 ) ;
V_812 = ( V_217 >> 12 ) & 0x1 ;
switch ( V_85 ) {
case 2666667 :
case 4000000 :
case 5333333 :
return V_812 ? 333333 : 222222 ;
case 3200000 :
return V_812 ? 320000 : 228571 ;
default:
F_131 ( L_136 , V_85 , V_217 ) ;
return 222222 ;
}
}
static int F_529 ( struct V_15 * V_16 )
{
static const T_6 V_813 [] = { 16 , 10 , 8 } ;
static const T_6 V_814 [] = { 20 , 12 , 10 } ;
static const T_6 V_815 [] = { 24 , 16 , 14 } ;
const T_6 * V_816 ;
unsigned int V_812 , V_85 = F_525 ( V_16 ) ;
T_7 V_217 = 0 ;
F_518 ( V_16 -> V_779 , V_780 , & V_217 ) ;
V_812 = ( ( V_217 >> 8 ) & 0x1f ) - 1 ;
if ( V_812 >= F_301 ( V_813 ) )
goto V_817;
switch ( V_85 ) {
case 3200000 :
V_816 = V_813 ;
break;
case 4000000 :
V_816 = V_814 ;
break;
case 5333333 :
V_816 = V_815 ;
break;
default:
goto V_817;
}
return F_7 ( V_85 , V_816 [ V_812 ] ) ;
V_817:
F_131 ( L_137 , V_85 , V_217 ) ;
return 200000 ;
}
static int F_530 ( struct V_15 * V_16 )
{
static const T_6 V_813 [] = { 12 , 10 , 8 , 7 , 5 , 16 } ;
static const T_6 V_814 [] = { 14 , 12 , 10 , 8 , 6 , 20 } ;
static const T_6 V_818 [] = { 20 , 14 , 12 , 10 , 8 , 24 } ;
static const T_6 V_815 [] = { 20 , 16 , 12 , 12 , 8 , 28 } ;
const T_6 * V_816 ;
unsigned int V_812 , V_85 = F_525 ( V_16 ) ;
T_7 V_217 = 0 ;
F_518 ( V_16 -> V_779 , V_780 , & V_217 ) ;
V_812 = ( V_217 >> 4 ) & 0x7 ;
if ( V_812 >= F_301 ( V_813 ) )
goto V_817;
switch ( V_85 ) {
case 3200000 :
V_816 = V_813 ;
break;
case 4000000 :
V_816 = V_814 ;
break;
case 4800000 :
V_816 = V_818 ;
break;
case 5333333 :
V_816 = V_815 ;
break;
default:
goto V_817;
}
return F_7 ( V_85 , V_816 [ V_812 ] ) ;
V_817:
F_131 ( L_138 , V_85 , V_217 ) ;
return 190476 ;
}
static void
F_531 ( T_2 * V_819 , T_2 * V_820 )
{
while ( * V_819 > V_821 ||
* V_820 > V_821 ) {
* V_819 >>= 1 ;
* V_820 >>= 1 ;
}
}
static void F_532 ( unsigned int V_79 , unsigned int V_84 ,
T_2 * V_822 , T_2 * V_823 )
{
* V_823 = F_533 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_822 = F_48 ( ( V_89 ) V_79 * * V_823 , V_84 ) ;
F_531 ( V_822 , V_823 ) ;
}
void
F_501 ( int V_395 , int V_824 ,
int V_825 , int V_826 ,
struct V_827 * V_828 )
{
V_828 -> V_829 = 64 ;
F_532 ( V_395 * V_825 ,
V_826 * V_824 * 8 ,
& V_828 -> V_830 , & V_828 -> V_831 ) ;
F_532 ( V_825 , V_826 ,
& V_828 -> V_832 , & V_828 -> V_833 ) ;
}
static inline bool F_534 ( struct V_1 * V_2 )
{
if ( V_761 . V_834 >= 0 )
return V_761 . V_834 != 0 ;
return V_2 -> V_835 . V_836
&& ! ( V_2 -> V_165 & V_837 ) ;
}
static int F_53 ( const struct V_43 * V_44 ,
int V_51 )
{
struct V_15 * V_16 = V_44 -> V_40 . V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_53 ;
F_9 ( ! V_44 -> V_40 . V_36 ) ;
if ( F_13 ( V_16 ) || F_29 ( V_16 ) ) {
V_53 = 100000 ;
} else if ( F_22 ( V_44 , V_55 ) &&
F_534 ( V_2 ) && V_51 < 2 ) {
V_53 = V_2 -> V_835 . V_838 ;
F_151 ( L_139 , V_53 ) ;
} else if ( ! F_33 ( V_16 ) ) {
V_53 = 96000 ;
} else {
V_53 = 48000 ;
}
return V_53 ;
}
static T_2 F_535 ( struct V_87 * V_87 )
{
return ( 1 << V_87 -> V_84 ) << 16 | V_87 -> V_80 ;
}
static T_2 F_536 ( struct V_87 * V_87 )
{
return V_87 -> V_84 << 16 | V_87 -> V_88 << 8 | V_87 -> V_80 ;
}
static void F_537 ( struct V_37 * V_38 ,
struct V_43 * V_44 ,
T_4 * V_839 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
T_1 V_840 , V_841 = 0 ;
if ( F_31 ( V_16 ) ) {
V_840 = F_535 ( & V_44 -> V_87 ) ;
if ( V_839 )
V_841 = F_535 ( V_839 ) ;
} else {
V_840 = F_536 ( & V_44 -> V_87 ) ;
if ( V_839 )
V_841 = F_536 ( V_839 ) ;
}
V_44 -> V_212 . V_736 = V_840 ;
V_38 -> V_842 = false ;
if ( F_22 ( V_44 , V_55 ) &&
V_839 ) {
V_44 -> V_212 . V_737 = V_841 ;
V_38 -> V_842 = true ;
} else {
V_44 -> V_212 . V_737 = V_840 ;
}
}
static void F_538 ( struct V_1 * V_2 , enum V_119
V_119 )
{
T_1 V_843 ;
V_843 = F_135 ( V_2 , V_119 , F_539 ( 1 ) ) ;
V_843 &= 0xffffff00 ;
V_843 |= 0x00000030 ;
F_137 ( V_2 , V_119 , F_539 ( 1 ) , V_843 ) ;
V_843 = F_135 ( V_2 , V_119 , V_844 ) ;
V_843 &= 0x8cffffff ;
V_843 = 0x8c000000 ;
F_137 ( V_2 , V_119 , V_844 , V_843 ) ;
V_843 = F_135 ( V_2 , V_119 , F_539 ( 1 ) ) ;
V_843 &= 0xffffff00 ;
F_137 ( V_2 , V_119 , F_539 ( 1 ) , V_843 ) ;
V_843 = F_135 ( V_2 , V_119 , V_844 ) ;
V_843 &= 0x00ffffff ;
V_843 |= 0xb0000000 ;
F_137 ( V_2 , V_119 , V_844 , V_843 ) ;
}
static void F_540 ( struct V_37 * V_38 ,
struct V_827 * V_828 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
F_128 ( F_541 ( V_119 ) , F_542 ( V_828 -> V_829 ) | V_828 -> V_830 ) ;
F_128 ( F_543 ( V_119 ) , V_828 -> V_831 ) ;
F_128 ( F_544 ( V_119 ) , V_828 -> V_832 ) ;
F_128 ( F_545 ( V_119 ) , V_828 -> V_833 ) ;
}
static void F_391 ( struct V_37 * V_38 ,
struct V_827 * V_828 ,
struct V_827 * V_845 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
enum V_118 V_118 = V_38 -> V_115 -> V_121 ;
if ( F_60 ( V_16 ) -> V_127 >= 5 ) {
F_128 ( F_342 ( V_118 ) , F_542 ( V_828 -> V_829 ) | V_828 -> V_830 ) ;
F_128 ( F_546 ( V_118 ) , V_828 -> V_831 ) ;
F_128 ( F_547 ( V_118 ) , V_828 -> V_832 ) ;
F_128 ( F_548 ( V_118 ) , V_828 -> V_833 ) ;
if ( V_845 && ( F_32 ( V_16 ) || F_60 ( V_16 ) -> V_127 < 8 ) &&
V_38 -> V_115 -> V_846 ) {
F_128 ( F_549 ( V_118 ) ,
F_542 ( V_845 -> V_829 ) | V_845 -> V_830 ) ;
F_128 ( F_550 ( V_118 ) , V_845 -> V_831 ) ;
F_128 ( F_551 ( V_118 ) , V_845 -> V_832 ) ;
F_128 ( F_552 ( V_118 ) , V_845 -> V_833 ) ;
}
} else {
F_128 ( F_553 ( V_119 ) , F_542 ( V_828 -> V_829 ) | V_828 -> V_830 ) ;
F_128 ( F_554 ( V_119 ) , V_828 -> V_831 ) ;
F_128 ( F_555 ( V_119 ) , V_828 -> V_832 ) ;
F_128 ( F_556 ( V_119 ) , V_828 -> V_833 ) ;
}
}
void F_389 ( struct V_37 * V_38 , enum V_847 V_828 )
{
struct V_827 * V_848 , * V_849 = NULL ;
if ( V_828 == V_602 ) {
V_848 = & V_38 -> V_115 -> V_848 ;
V_849 = & V_38 -> V_115 -> V_849 ;
} else if ( V_828 == V_850 ) {
V_848 = & V_38 -> V_115 -> V_849 ;
} else {
F_131 ( L_140 ) ;
return;
}
if ( V_38 -> V_115 -> V_260 )
F_540 ( V_38 , & V_38 -> V_115 -> V_848 ) ;
else
F_391 ( V_38 , V_848 , V_849 ) ;
}
static void F_557 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
T_1 V_87 , V_214 ;
V_87 = V_851 | V_223 |
V_221 | V_852 ;
if ( V_38 -> V_119 == V_157 )
V_87 |= V_222 ;
V_87 |= V_131 ;
V_211 -> V_212 . V_87 = V_87 ;
V_214 = ( V_211 -> V_608 - 1 )
<< V_853 ;
V_211 -> V_212 . V_214 = V_214 ;
}
static void F_473 ( struct V_37 * V_38 ,
const struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
T_1 V_854 ;
T_1 V_855 , V_856 , V_857 , V_858 , V_859 ;
T_1 V_860 , V_843 ;
F_2 ( & V_2 -> V_5 ) ;
V_855 = V_211 -> V_87 . V_84 ;
V_856 = V_211 -> V_87 . V_88 ;
V_857 = V_211 -> V_87 . V_80 ;
V_858 = V_211 -> V_87 . V_82 ;
V_859 = V_211 -> V_87 . V_83 ;
if ( V_119 == V_157 )
F_538 ( V_2 , V_119 ) ;
F_137 ( V_2 , V_119 , V_861 , 0x0100000f ) ;
V_843 = F_135 ( V_2 , V_119 , F_558 ( V_119 ) ) ;
V_843 &= 0x00ffffff ;
F_137 ( V_2 , V_119 , F_558 ( V_119 ) , V_843 ) ;
F_137 ( V_2 , V_119 , V_862 , 0x610 ) ;
V_854 = ( ( V_856 << V_863 ) | ( V_857 & V_864 ) ) ;
V_854 |= ( ( V_858 << V_865 ) | ( V_859 << V_866 ) ) ;
V_854 |= ( ( V_855 << V_867 ) ) ;
V_854 |= ( 1 << V_868 ) ;
V_854 |= ( V_869 << V_870 ) ;
F_137 ( V_2 , V_119 , F_559 ( V_119 ) , V_854 ) ;
V_854 |= V_871 ;
F_137 ( V_2 , V_119 , F_559 ( V_119 ) , V_854 ) ;
if ( V_211 -> V_872 == 162000 ||
F_20 ( V_38 , V_64 ) ||
F_20 ( V_38 , V_63 ) )
F_137 ( V_2 , V_119 , F_560 ( V_119 ) ,
0x009f0003 ) ;
else
F_137 ( V_2 , V_119 , F_560 ( V_119 ) ,
0x00d0000f ) ;
if ( V_211 -> V_536 ) {
if ( V_119 == V_148 )
F_137 ( V_2 , V_119 , F_561 ( V_119 ) ,
0x0df40000 ) ;
else
F_137 ( V_2 , V_119 , F_561 ( V_119 ) ,
0x0df70000 ) ;
} else {
if ( V_119 == V_148 )
F_137 ( V_2 , V_119 , F_561 ( V_119 ) ,
0x0df70000 ) ;
else
F_137 ( V_2 , V_119 , F_561 ( V_119 ) ,
0x0df40000 ) ;
}
V_860 = F_135 ( V_2 , V_119 , F_562 ( V_119 ) ) ;
V_860 = ( V_860 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_20 ( V_38 , V_635 ) ||
F_20 ( V_38 , V_636 ) )
V_860 |= 0x01000000 ;
F_137 ( V_2 , V_119 , F_562 ( V_119 ) , V_860 ) ;
F_137 ( V_2 , V_119 , F_563 ( V_119 ) , 0x87871000 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_564 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
V_211 -> V_212 . V_87 = V_224 |
V_223 | V_221 |
V_131 ;
if ( V_38 -> V_119 != V_148 )
V_211 -> V_212 . V_87 |= V_222 ;
V_211 -> V_212 . V_214 =
( V_211 -> V_608 - 1 ) << V_853 ;
}
static void F_472 ( struct V_37 * V_38 ,
const struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_38 -> V_119 ;
int V_229 = F_65 ( V_38 -> V_119 ) ;
enum V_215 V_216 = F_134 ( V_119 ) ;
T_1 V_873 , V_874 ;
T_1 V_855 , V_856 , V_857 , V_858 , V_859 , V_875 ;
T_1 V_876 ;
int V_85 ;
V_855 = V_211 -> V_87 . V_84 ;
V_875 = V_211 -> V_87 . V_80 & 0x3fffff ;
V_856 = V_211 -> V_87 . V_88 ;
V_857 = V_211 -> V_87 . V_80 >> 22 ;
V_858 = V_211 -> V_87 . V_82 ;
V_859 = V_211 -> V_87 . V_83 ;
V_85 = V_211 -> V_87 . V_85 ;
V_876 = 0 ;
V_873 = 0 ;
F_128 ( V_229 ,
V_211 -> V_212 . V_87 & ~ V_131 ) ;
F_2 ( & V_2 -> V_5 ) ;
F_137 ( V_2 , V_119 , F_565 ( V_216 ) ,
5 << V_877 |
V_858 << V_878 |
V_859 << V_879 |
1 << V_880 ) ;
F_137 ( V_2 , V_119 , F_566 ( V_216 ) , V_857 ) ;
F_137 ( V_2 , V_119 , F_567 ( V_216 ) ,
V_881 |
1 << V_882 ) ;
F_137 ( V_2 , V_119 , F_568 ( V_216 ) , V_875 ) ;
V_876 = F_135 ( V_2 , V_119 , F_569 ( V_216 ) ) ;
V_876 &= ~ ( V_883 | V_884 ) ;
V_876 |= ( 2 << V_885 ) ;
if ( V_875 )
V_876 |= V_884 ;
F_137 ( V_2 , V_119 , F_569 ( V_216 ) , V_876 ) ;
V_876 = F_135 ( V_2 , V_119 , F_570 ( V_216 ) ) ;
V_876 &= ~ ( V_886 |
V_887 ) ;
V_876 |= ( 0x5 << V_888 ) ;
if ( ! V_875 )
V_876 |= V_887 ;
F_137 ( V_2 , V_119 , F_570 ( V_216 ) , V_876 ) ;
if ( V_85 == 5400000 ) {
V_873 |= ( 0x3 << V_889 ) ;
V_873 |= ( 0x8 << V_890 ) ;
V_873 |= ( 0x1 << V_891 ) ;
V_874 = 0x9 ;
} else if ( V_85 <= 6200000 ) {
V_873 |= ( 0x5 << V_889 ) ;
V_873 |= ( 0xB << V_890 ) ;
V_873 |= ( 0x3 << V_891 ) ;
V_874 = 0x9 ;
} else if ( V_85 <= 6480000 ) {
V_873 |= ( 0x4 << V_889 ) ;
V_873 |= ( 0x9 << V_890 ) ;
V_873 |= ( 0x3 << V_891 ) ;
V_874 = 0x8 ;
} else {
V_873 |= ( 0x4 << V_889 ) ;
V_873 |= ( 0x9 << V_890 ) ;
V_873 |= ( 0x3 << V_891 ) ;
V_874 = 0 ;
}
F_137 ( V_2 , V_119 , F_571 ( V_216 ) , V_873 ) ;
V_876 = F_135 ( V_2 , V_119 , F_572 ( V_216 ) ) ;
V_876 &= ~ V_892 ;
V_876 |= ( V_874 << V_893 ) ;
F_137 ( V_2 , V_119 , F_572 ( V_216 ) , V_876 ) ;
F_137 ( V_2 , V_119 , F_136 ( V_216 ) ,
F_135 ( V_2 , V_119 , F_136 ( V_216 ) ) |
V_894 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
void F_573 ( struct V_15 * V_16 , enum V_119 V_119 ,
const struct V_87 * V_87 )
{
struct V_37 * V_38 =
F_50 ( F_496 ( V_16 , V_119 ) ) ;
struct V_43 V_211 = {
. V_40 . V_38 = & V_38 -> V_40 ,
. V_608 = 1 ,
. V_87 = * V_87 ,
} ;
if ( F_32 ( V_16 ) ) {
F_564 ( V_38 , & V_211 ) ;
F_472 ( V_38 , & V_211 ) ;
F_133 ( V_38 , & V_211 ) ;
} else {
F_557 ( V_38 , & V_211 ) ;
F_473 ( V_38 , & V_211 ) ;
F_124 ( V_38 , & V_211 ) ;
}
}
void F_574 ( struct V_15 * V_16 , enum V_119 V_119 )
{
if ( F_32 ( V_16 ) )
F_144 ( F_203 ( V_16 ) , V_119 ) ;
else
F_143 ( F_203 ( V_16 ) , V_119 ) ;
}
static void F_575 ( struct V_37 * V_38 ,
struct V_43 * V_44 ,
T_4 * V_839 ,
int V_51 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_87 ;
bool V_895 ;
struct V_87 * clock = & V_44 -> V_87 ;
F_537 ( V_38 , V_44 , V_839 ) ;
V_895 = F_22 ( V_44 , V_66 ) ||
F_22 ( V_44 , V_63 ) ;
V_87 = V_221 ;
if ( F_22 ( V_44 , V_55 ) )
V_87 |= V_896 ;
else
V_87 |= V_897 ;
if ( F_576 ( V_16 ) || F_577 ( V_16 ) || F_527 ( V_16 ) ) {
V_87 |= ( V_44 -> V_608 - 1 )
<< V_898 ;
}
if ( V_895 )
V_87 |= V_899 ;
if ( V_44 -> V_536 )
V_87 |= V_899 ;
if ( F_31 ( V_16 ) )
V_87 |= ( 1 << ( clock -> V_82 - 1 ) ) << V_900 ;
else {
V_87 |= ( 1 << ( clock -> V_82 - 1 ) ) << V_901 ;
if ( F_30 ( V_16 ) && V_839 )
V_87 |= ( 1 << ( V_839 -> V_82 - 1 ) ) << V_902 ;
}
switch ( clock -> V_83 ) {
case 5 :
V_87 |= V_903 ;
break;
case 7 :
V_87 |= V_904 ;
break;
case 10 :
V_87 |= V_905 ;
break;
case 14 :
V_87 |= V_906 ;
break;
}
if ( F_60 ( V_16 ) -> V_127 >= 4 )
V_87 |= ( 6 << V_907 ) ;
if ( V_44 -> V_908 )
V_87 |= V_909 ;
else if ( F_22 ( V_44 , V_55 ) &&
F_534 ( V_2 ) && V_51 < 2 )
V_87 |= V_910 ;
else
V_87 |= V_911 ;
V_87 |= V_131 ;
V_44 -> V_212 . V_87 = V_87 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
T_1 V_214 = ( V_44 -> V_608 - 1 )
<< V_853 ;
V_44 -> V_212 . V_214 = V_214 ;
}
}
static void F_578 ( struct V_37 * V_38 ,
struct V_43 * V_44 ,
T_4 * V_839 ,
int V_51 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_87 ;
struct V_87 * clock = & V_44 -> V_87 ;
F_537 ( V_38 , V_44 , V_839 ) ;
V_87 = V_221 ;
if ( F_22 ( V_44 , V_55 ) ) {
V_87 |= ( 1 << ( clock -> V_82 - 1 ) ) << V_901 ;
} else {
if ( clock -> V_82 == 2 )
V_87 |= V_912 ;
else
V_87 |= ( clock -> V_82 - 2 ) << V_901 ;
if ( clock -> V_83 == 4 )
V_87 |= V_913 ;
}
if ( ! F_141 ( V_16 ) && F_22 ( V_44 , V_76 ) )
V_87 |= V_220 ;
if ( F_22 ( V_44 , V_55 ) &&
F_534 ( V_2 ) && V_51 < 2 )
V_87 |= V_910 ;
else
V_87 |= V_911 ;
V_87 |= V_131 ;
V_44 -> V_212 . V_87 = V_87 ;
}
static void F_390 ( struct V_37 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 = V_37 -> V_119 ;
enum V_118 V_121 = V_37 -> V_115 -> V_121 ;
const struct V_563 * V_116 = & V_37 -> V_115 -> V_40 . V_116 ;
T_2 V_914 , V_915 ;
int V_916 = 0 ;
V_914 = V_116 -> V_914 ;
V_915 = V_116 -> V_915 ;
if ( V_116 -> V_359 & V_917 ) {
V_914 -= 1 ;
V_915 -= 1 ;
if ( F_20 ( V_37 , V_66 ) )
V_916 = ( V_116 -> V_918 - 1 ) / 2 ;
else
V_916 = V_116 -> V_764 -
V_116 -> V_918 / 2 ;
if ( V_916 < 0 )
V_916 += V_116 -> V_918 ;
}
if ( F_60 ( V_16 ) -> V_127 > 3 )
F_128 ( F_337 ( V_121 ) , V_916 ) ;
F_128 ( F_325 ( V_121 ) ,
( V_116 -> V_565 - 1 ) |
( ( V_116 -> V_918 - 1 ) << 16 ) ) ;
F_128 ( F_327 ( V_121 ) ,
( V_116 -> V_919 - 1 ) |
( ( V_116 -> V_920 - 1 ) << 16 ) ) ;
F_128 ( F_329 ( V_121 ) ,
( V_116 -> V_764 - 1 ) |
( ( V_116 -> V_921 - 1 ) << 16 ) ) ;
F_128 ( F_331 ( V_121 ) ,
( V_116 -> V_566 - 1 ) |
( ( V_914 - 1 ) << 16 ) ) ;
F_128 ( F_333 ( V_121 ) ,
( V_116 -> V_922 - 1 ) |
( ( V_915 - 1 ) << 16 ) ) ;
F_128 ( F_335 ( V_121 ) ,
( V_116 -> V_923 - 1 ) |
( ( V_116 -> V_924 - 1 ) << 16 ) ) ;
if ( F_234 ( V_16 ) && V_121 == V_607 &&
( V_119 == V_157 || V_119 == V_530 ) )
F_128 ( F_331 ( V_119 ) , F_11 ( F_331 ( V_121 ) ) ) ;
F_128 ( F_285 ( V_119 ) ,
( ( V_37 -> V_115 -> V_385 - 1 ) << 16 ) |
( V_37 -> V_115 -> V_384 - 1 ) ) ;
}
static void F_579 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_118 V_121 = V_211 -> V_121 ;
T_2 V_217 ;
V_217 = F_11 ( F_325 ( V_121 ) ) ;
V_211 -> V_40 . V_116 . V_565 = ( V_217 & 0xffff ) + 1 ;
V_211 -> V_40 . V_116 . V_918 = ( ( V_217 >> 16 ) & 0xffff ) + 1 ;
V_217 = F_11 ( F_327 ( V_121 ) ) ;
V_211 -> V_40 . V_116 . V_919 = ( V_217 & 0xffff ) + 1 ;
V_211 -> V_40 . V_116 . V_920 = ( ( V_217 >> 16 ) & 0xffff ) + 1 ;
V_217 = F_11 ( F_329 ( V_121 ) ) ;
V_211 -> V_40 . V_116 . V_764 = ( V_217 & 0xffff ) + 1 ;
V_211 -> V_40 . V_116 . V_921 = ( ( V_217 >> 16 ) & 0xffff ) + 1 ;
V_217 = F_11 ( F_331 ( V_121 ) ) ;
V_211 -> V_40 . V_116 . V_566 = ( V_217 & 0xffff ) + 1 ;
V_211 -> V_40 . V_116 . V_914 = ( ( V_217 >> 16 ) & 0xffff ) + 1 ;
V_217 = F_11 ( F_333 ( V_121 ) ) ;
V_211 -> V_40 . V_116 . V_922 = ( V_217 & 0xffff ) + 1 ;
V_211 -> V_40 . V_116 . V_915 = ( ( V_217 >> 16 ) & 0xffff ) + 1 ;
V_217 = F_11 ( F_335 ( V_121 ) ) ;
V_211 -> V_40 . V_116 . V_923 = ( V_217 & 0xffff ) + 1 ;
V_211 -> V_40 . V_116 . V_924 = ( ( V_217 >> 16 ) & 0xffff ) + 1 ;
if ( F_11 ( F_61 ( V_121 ) ) & V_249 ) {
V_211 -> V_40 . V_116 . V_359 |= V_917 ;
V_211 -> V_40 . V_116 . V_914 += 1 ;
V_211 -> V_40 . V_116 . V_915 += 1 ;
}
V_217 = F_11 ( F_285 ( V_38 -> V_119 ) ) ;
V_211 -> V_384 = ( V_217 & 0xffff ) + 1 ;
V_211 -> V_385 = ( ( V_217 >> 16 ) & 0xffff ) + 1 ;
V_211 -> V_40 . V_449 . V_925 = V_211 -> V_384 ;
V_211 -> V_40 . V_449 . V_926 = V_211 -> V_385 ;
}
void F_580 ( struct V_563 * V_449 ,
struct V_43 * V_211 )
{
V_449 -> V_926 = V_211 -> V_40 . V_116 . V_565 ;
V_449 -> V_927 = V_211 -> V_40 . V_116 . V_918 ;
V_449 -> V_928 = V_211 -> V_40 . V_116 . V_764 ;
V_449 -> V_929 = V_211 -> V_40 . V_116 . V_921 ;
V_449 -> V_925 = V_211 -> V_40 . V_116 . V_566 ;
V_449 -> V_930 = V_211 -> V_40 . V_116 . V_914 ;
V_449 -> V_931 = V_211 -> V_40 . V_116 . V_923 ;
V_449 -> V_932 = V_211 -> V_40 . V_116 . V_924 ;
V_449 -> V_359 = V_211 -> V_40 . V_116 . V_359 ;
V_449 -> type = V_933 ;
V_449 -> clock = V_211 -> V_40 . V_116 . V_117 ;
V_449 -> V_359 |= V_211 -> V_40 . V_116 . V_359 ;
V_449 -> V_934 = F_581 ( V_449 ) ;
V_449 -> V_935 = F_582 ( V_449 ) ;
F_583 ( V_449 ) ;
}
static void F_471 ( struct V_37 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_936 ;
V_936 = 0 ;
if ( ( V_37 -> V_119 == V_148 && V_2 -> V_165 & V_166 ) ||
( V_37 -> V_119 == V_157 && V_2 -> V_165 & V_167 ) )
V_936 |= F_11 ( F_61 ( V_37 -> V_119 ) ) & V_168 ;
if ( V_37 -> V_115 -> V_261 )
V_936 |= V_262 ;
if ( F_30 ( V_16 ) || F_13 ( V_16 ) ) {
if ( V_37 -> V_115 -> V_937 && V_37 -> V_115 -> V_758 != 30 )
V_936 |= V_938 |
V_939 ;
switch ( V_37 -> V_115 -> V_758 ) {
case 18 :
V_936 |= V_940 ;
break;
case 24 :
V_936 |= V_247 ;
break;
case 30 :
V_936 |= V_941 ;
break;
default:
F_146 () ;
}
}
if ( F_584 ( V_16 ) ) {
if ( V_37 -> V_842 ) {
F_151 ( L_141 ) ;
V_936 |= V_942 ;
} else {
F_151 ( L_142 ) ;
}
}
if ( V_37 -> V_115 -> V_40 . V_116 . V_359 & V_917 ) {
if ( F_60 ( V_16 ) -> V_127 < 4 ||
F_20 ( V_37 , V_66 ) )
V_936 |= V_943 ;
else
V_936 |= V_944 ;
} else
V_936 |= V_945 ;
if ( F_13 ( V_16 ) && V_37 -> V_115 -> V_946 )
V_936 |= V_947 ;
F_128 ( F_61 ( V_37 -> V_119 ) , V_936 ) ;
F_129 ( F_61 ( V_37 -> V_119 ) ) ;
}
static int F_585 ( struct V_37 * V_38 ,
struct V_43 * V_44 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_53 , V_51 = 0 ;
T_4 clock ;
bool V_948 ;
bool V_606 = false ;
struct V_41 * V_42 ;
const T_3 * V_54 ;
struct V_45 * V_36 = V_44 -> V_40 . V_36 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_50 ;
memset ( & V_44 -> V_212 , 0 ,
sizeof( V_44 -> V_212 ) ) ;
F_23 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != & V_38 -> V_40 )
continue;
V_42 = F_24 ( V_49 -> V_52 ) ;
switch ( V_42 -> type ) {
case V_259 :
V_606 = true ;
break;
default:
break;
}
V_51 ++ ;
}
if ( V_606 )
return 0 ;
if ( ! V_44 -> V_949 ) {
V_53 = F_53 ( V_44 , V_51 ) ;
V_54 = F_28 ( V_44 , V_53 ) ;
V_948 = V_2 -> V_453 . V_950 ( V_54 , V_44 ,
V_44 -> V_872 ,
V_53 , NULL , & clock ) ;
if ( ! V_948 ) {
F_131 ( L_143 ) ;
return - V_309 ;
}
V_44 -> V_87 . V_84 = clock . V_84 ;
V_44 -> V_87 . V_88 = clock . V_88 ;
V_44 -> V_87 . V_80 = clock . V_80 ;
V_44 -> V_87 . V_82 = clock . V_82 ;
V_44 -> V_87 . V_83 = clock . V_83 ;
}
if ( F_33 ( V_16 ) ) {
F_578 ( V_38 , V_44 , NULL ,
V_51 ) ;
} else if ( F_32 ( V_16 ) ) {
F_564 ( V_38 , V_44 ) ;
} else if ( F_13 ( V_16 ) ) {
F_557 ( V_38 , V_44 ) ;
} else {
F_575 ( V_38 , V_44 , NULL ,
V_51 ) ;
}
return 0 ;
}
static void F_586 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_217 ;
if ( F_60 ( V_16 ) -> V_127 <= 3 && ( F_141 ( V_16 ) || ! F_127 ( V_16 ) ) )
return;
V_217 = F_11 ( V_617 ) ;
if ( ! ( V_217 & V_618 ) )
return;
if ( F_60 ( V_16 ) -> V_127 < 4 ) {
if ( V_38 -> V_119 != V_157 )
return;
} else {
if ( ( V_217 & V_951 ) != ( V_38 -> V_119 << V_952 ) )
return;
}
V_211 -> V_615 . V_616 = V_217 ;
V_211 -> V_615 . V_620 = F_11 ( V_619 ) ;
if ( F_60 ( V_16 ) -> V_127 < 5 )
V_211 -> V_615 . V_953 =
F_11 ( V_159 ) & V_954 ;
}
static void F_587 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_211 -> V_121 ;
T_4 clock ;
T_1 V_854 ;
int V_53 = 100000 ;
if ( ! ( V_211 -> V_212 . V_87 & V_131 ) )
return;
F_2 ( & V_2 -> V_5 ) ;
V_854 = F_135 ( V_2 , V_119 , F_559 ( V_119 ) ) ;
F_4 ( & V_2 -> V_5 ) ;
clock . V_88 = ( V_854 >> V_863 ) & 7 ;
clock . V_80 = V_854 & V_864 ;
clock . V_84 = ( V_854 >> V_867 ) & 0xf ;
clock . V_82 = ( V_854 >> V_865 ) & 7 ;
clock . V_83 = ( V_854 >> V_866 ) & 0x1f ;
V_211 -> V_872 = F_37 ( V_53 , & clock ) ;
}
static void
F_588 ( struct V_37 * V_38 ,
struct V_347 * V_348 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 , V_40 , V_324 ;
int V_119 = V_38 -> V_119 , V_169 = V_38 -> V_169 ;
int V_955 , V_264 ;
unsigned int V_956 ;
struct V_275 * V_114 ;
struct V_957 * V_958 ;
V_10 = F_11 ( F_89 ( V_169 ) ) ;
if ( ! ( V_10 & V_170 ) )
return;
V_958 = F_491 ( sizeof( * V_958 ) , V_750 ) ;
if ( ! V_958 ) {
F_151 ( L_144 ) ;
return;
}
V_114 = & V_958 -> V_40 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
if ( V_10 & V_387 ) {
V_348 -> V_355 = V_356 ;
V_114 -> V_290 [ 0 ] = V_269 ;
}
}
V_264 = V_10 & V_959 ;
V_955 = F_200 ( V_264 ) ;
V_114 -> V_264 = V_955 ;
V_114 -> V_395 = F_177 ( V_955 , 0 ) * 8 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
if ( V_348 -> V_355 )
V_324 = F_11 ( F_231 ( V_169 ) ) ;
else
V_324 = F_11 ( F_232 ( V_169 ) ) ;
V_40 = F_11 ( F_222 ( V_169 ) ) & 0xfffff000 ;
} else {
V_40 = F_11 ( F_223 ( V_169 ) ) ;
}
V_348 -> V_40 = V_40 ;
V_10 = F_11 ( F_285 ( V_119 ) ) ;
V_114 -> V_358 = ( ( V_10 >> 16 ) & 0xfff ) + 1 ;
V_114 -> V_272 = ( ( V_10 >> 0 ) & 0xfff ) + 1 ;
V_10 = F_11 ( F_230 ( V_119 ) ) ;
V_114 -> V_286 [ 0 ] = V_10 & 0xffffffc0 ;
V_956 = F_180 ( V_16 , V_114 -> V_272 ,
V_114 -> V_264 ,
V_114 -> V_290 [ 0 ] ) ;
V_348 -> V_294 = V_114 -> V_286 [ 0 ] * V_956 ;
F_151 ( L_145 ,
F_80 ( V_119 ) , V_169 , V_114 -> V_358 , V_114 -> V_272 ,
V_114 -> V_395 , V_40 , V_114 -> V_286 [ 0 ] ,
V_348 -> V_294 ) ;
V_348 -> V_114 = V_958 ;
}
static void F_589 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_211 -> V_121 ;
enum V_215 V_216 = F_134 ( V_119 ) ;
T_4 clock ;
T_1 V_960 , V_961 , V_962 , V_963 , V_964 ;
int V_53 = 100000 ;
F_2 ( & V_2 -> V_5 ) ;
V_960 = F_135 ( V_2 , V_119 , F_565 ( V_216 ) ) ;
V_961 = F_135 ( V_2 , V_119 , F_566 ( V_216 ) ) ;
V_962 = F_135 ( V_2 , V_119 , F_567 ( V_216 ) ) ;
V_963 = F_135 ( V_2 , V_119 , F_568 ( V_216 ) ) ;
V_964 = F_135 ( V_2 , V_119 , F_569 ( V_216 ) ) ;
F_4 ( & V_2 -> V_5 ) ;
clock . V_88 = ( V_962 & 0x7 ) == V_881 ? 2 : 0 ;
clock . V_80 = ( V_961 & 0xff ) << 22 ;
if ( V_964 & V_884 )
clock . V_80 |= V_963 & 0x3fffff ;
clock . V_84 = ( V_962 >> V_882 ) & 0xf ;
clock . V_82 = ( V_960 >> V_878 ) & 0x7 ;
clock . V_83 = ( V_960 >> V_879 ) & 0x1f ;
V_211 -> V_872 = F_38 ( V_53 , & clock ) ;
}
static bool F_590 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_217 ;
if ( ! F_86 ( V_2 ,
F_419 ( V_38 -> V_119 ) ) )
return false ;
V_211 -> V_121 = (enum V_118 ) V_38 -> V_119 ;
V_211 -> V_135 = V_965 ;
V_217 = F_11 ( F_61 ( V_38 -> V_119 ) ) ;
if ( ! ( V_217 & V_168 ) )
return false ;
if ( F_30 ( V_16 ) || F_13 ( V_16 ) ) {
switch ( V_217 & V_246 ) {
case V_940 :
V_211 -> V_758 = 18 ;
break;
case V_247 :
V_211 -> V_758 = 24 ;
break;
case V_941 :
V_211 -> V_758 = 30 ;
break;
default:
break;
}
}
if ( F_13 ( V_16 ) && ( V_217 & V_947 ) )
V_211 -> V_946 = true ;
if ( F_60 ( V_16 ) -> V_127 < 4 )
V_211 -> V_261 = V_217 & V_262 ;
F_579 ( V_38 , V_211 ) ;
F_586 ( V_38 , V_211 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
V_217 = F_11 ( F_132 ( V_38 -> V_119 ) ) ;
V_211 -> V_608 =
( ( V_217 & V_966 )
>> V_853 ) + 1 ;
V_211 -> V_212 . V_214 = V_217 ;
} else if ( F_576 ( V_16 ) || F_577 ( V_16 ) || F_527 ( V_16 ) ) {
V_217 = F_11 ( F_65 ( V_38 -> V_119 ) ) ;
V_211 -> V_608 =
( ( V_217 & V_967 )
>> V_898 ) + 1 ;
} else {
V_211 -> V_608 = 1 ;
}
V_211 -> V_212 . V_87 = F_11 ( F_65 ( V_38 -> V_119 ) ) ;
if ( ! F_13 ( V_16 ) ) {
if ( F_141 ( V_16 ) )
V_211 -> V_212 . V_87 &= ~ V_220 ;
V_211 -> V_212 . V_736 = F_11 ( F_475 ( V_38 -> V_119 ) ) ;
V_211 -> V_212 . V_737 = F_11 ( F_476 ( V_38 -> V_119 ) ) ;
} else {
V_211 -> V_212 . V_87 &= ~ ( V_213 |
V_233 |
V_231 ) ;
}
if ( F_32 ( V_16 ) )
F_589 ( V_38 , V_211 ) ;
else if ( F_13 ( V_16 ) )
F_587 ( V_38 , V_211 ) ;
else
F_591 ( V_38 , V_211 ) ;
V_211 -> V_40 . V_116 . V_117 =
V_211 -> V_872 / V_211 -> V_608 ;
return true ;
}
static void F_592 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_41 * V_42 ;
T_1 V_10 , V_968 ;
bool V_969 = false ;
bool V_970 = false ;
bool V_971 = false ;
bool V_972 = false ;
bool V_973 = false ;
F_593 (dev, encoder) {
switch ( V_42 -> type ) {
case V_55 :
V_971 = true ;
V_969 = true ;
break;
case V_636 :
V_971 = true ;
if ( F_350 ( & V_42 -> V_40 ) -> V_216 == V_622 )
V_970 = true ;
break;
default:
break;
}
}
if ( F_105 ( V_16 ) ) {
V_972 = V_2 -> V_835 . V_974 ;
V_973 = V_972 ;
} else {
V_972 = false ;
V_973 = true ;
}
F_151 ( L_146 ,
V_971 , V_969 , V_972 ) ;
V_10 = F_11 ( V_179 ) ;
V_968 = V_10 ;
V_968 &= ~ V_181 ;
if ( V_972 )
V_968 |= V_975 ;
else
V_968 |= V_976 ;
V_968 &= ~ V_180 ;
V_968 &= ~ V_977 ;
V_968 &= ~ V_978 ;
if ( V_971 ) {
V_968 |= V_979 ;
if ( F_534 ( V_2 ) && V_973 )
V_968 |= V_978 ;
if ( V_970 ) {
if ( F_534 ( V_2 ) && V_973 )
V_968 |= V_980 ;
else
V_968 |= V_981 ;
} else
V_968 |= V_982 ;
} else {
V_968 |= V_983 ;
V_968 |= V_982 ;
}
if ( V_968 == V_10 )
return;
V_10 &= ~ V_181 ;
if ( V_972 )
V_10 |= V_975 ;
else
V_10 |= V_976 ;
if ( V_971 ) {
V_10 &= ~ V_180 ;
V_10 |= V_979 ;
if ( F_534 ( V_2 ) && V_973 ) {
F_151 ( L_147 ) ;
V_10 |= V_978 ;
} else
V_10 &= ~ V_978 ;
F_128 ( V_179 , V_10 ) ;
F_129 ( V_179 ) ;
F_130 ( 200 ) ;
V_10 &= ~ V_977 ;
if ( V_970 ) {
if ( F_534 ( V_2 ) && V_973 ) {
F_151 ( L_148 ) ;
V_10 |= V_980 ;
} else
V_10 |= V_981 ;
} else
V_10 |= V_982 ;
F_128 ( V_179 , V_10 ) ;
F_129 ( V_179 ) ;
F_130 ( 200 ) ;
} else {
F_151 ( L_149 ) ;
V_10 &= ~ V_977 ;
V_10 |= V_982 ;
F_128 ( V_179 , V_10 ) ;
F_129 ( V_179 ) ;
F_130 ( 200 ) ;
V_10 &= ~ V_180 ;
V_10 |= V_983 ;
V_10 &= ~ V_978 ;
F_128 ( V_179 , V_10 ) ;
F_129 ( V_179 ) ;
F_130 ( 200 ) ;
}
F_126 ( V_10 != V_968 ) ;
}
static void F_594 ( struct V_1 * V_2 )
{
T_2 V_217 ;
V_217 = F_11 ( V_984 ) ;
V_217 |= V_985 ;
F_128 ( V_984 , V_217 ) ;
if ( F_595 ( F_11 ( V_984 ) &
V_986 , 100 ) )
F_131 ( L_150 ) ;
V_217 = F_11 ( V_984 ) ;
V_217 &= ~ V_985 ;
F_128 ( V_984 , V_217 ) ;
if ( F_595 ( ( F_11 ( V_984 ) &
V_986 ) == 0 , 100 ) )
F_131 ( L_151 ) ;
}
static void F_596 ( struct V_1 * V_2 )
{
T_2 V_217 ;
V_217 = F_318 ( V_2 , 0x8008 , V_987 ) ;
V_217 &= ~ ( 0xFF << 24 ) ;
V_217 |= ( 0x12 << 24 ) ;
F_317 ( V_2 , 0x8008 , V_217 , V_987 ) ;
V_217 = F_318 ( V_2 , 0x2008 , V_987 ) ;
V_217 |= ( 1 << 11 ) ;
F_317 ( V_2 , 0x2008 , V_217 , V_987 ) ;
V_217 = F_318 ( V_2 , 0x2108 , V_987 ) ;
V_217 |= ( 1 << 11 ) ;
F_317 ( V_2 , 0x2108 , V_217 , V_987 ) ;
V_217 = F_318 ( V_2 , 0x206C , V_987 ) ;
V_217 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_317 ( V_2 , 0x206C , V_217 , V_987 ) ;
V_217 = F_318 ( V_2 , 0x216C , V_987 ) ;
V_217 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_317 ( V_2 , 0x216C , V_217 , V_987 ) ;
V_217 = F_318 ( V_2 , 0x2080 , V_987 ) ;
V_217 &= ~ ( 7 << 13 ) ;
V_217 |= ( 5 << 13 ) ;
F_317 ( V_2 , 0x2080 , V_217 , V_987 ) ;
V_217 = F_318 ( V_2 , 0x2180 , V_987 ) ;
V_217 &= ~ ( 7 << 13 ) ;
V_217 |= ( 5 << 13 ) ;
F_317 ( V_2 , 0x2180 , V_217 , V_987 ) ;
V_217 = F_318 ( V_2 , 0x208C , V_987 ) ;
V_217 &= ~ 0xFF ;
V_217 |= 0x1C ;
F_317 ( V_2 , 0x208C , V_217 , V_987 ) ;
V_217 = F_318 ( V_2 , 0x218C , V_987 ) ;
V_217 &= ~ 0xFF ;
V_217 |= 0x1C ;
F_317 ( V_2 , 0x218C , V_217 , V_987 ) ;
V_217 = F_318 ( V_2 , 0x2098 , V_987 ) ;
V_217 &= ~ ( 0xFF << 16 ) ;
V_217 |= ( 0x1C << 16 ) ;
F_317 ( V_2 , 0x2098 , V_217 , V_987 ) ;
V_217 = F_318 ( V_2 , 0x2198 , V_987 ) ;
V_217 &= ~ ( 0xFF << 16 ) ;
V_217 |= ( 0x1C << 16 ) ;
F_317 ( V_2 , 0x2198 , V_217 , V_987 ) ;
V_217 = F_318 ( V_2 , 0x20C4 , V_987 ) ;
V_217 |= ( 1 << 27 ) ;
F_317 ( V_2 , 0x20C4 , V_217 , V_987 ) ;
V_217 = F_318 ( V_2 , 0x21C4 , V_987 ) ;
V_217 |= ( 1 << 27 ) ;
F_317 ( V_2 , 0x21C4 , V_217 , V_987 ) ;
V_217 = F_318 ( V_2 , 0x20EC , V_987 ) ;
V_217 &= ~ ( 0xF << 28 ) ;
V_217 |= ( 4 << 28 ) ;
F_317 ( V_2 , 0x20EC , V_217 , V_987 ) ;
V_217 = F_318 ( V_2 , 0x21EC , V_987 ) ;
V_217 &= ~ ( 0xF << 28 ) ;
V_217 |= ( 4 << 28 ) ;
F_317 ( V_2 , 0x21EC , V_217 , V_987 ) ;
}
static void F_597 ( struct V_15 * V_16 , bool V_988 ,
bool V_989 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_9 , V_217 ;
if ( F_6 ( V_989 && ! V_988 , L_152 ) )
V_988 = true ;
if ( F_6 ( F_598 ( V_16 ) && V_989 , L_153 ) )
V_989 = false ;
F_2 ( & V_2 -> V_5 ) ;
V_217 = F_318 ( V_2 , V_990 , V_515 ) ;
V_217 &= ~ V_516 ;
V_217 |= V_991 ;
F_317 ( V_2 , V_990 , V_217 , V_515 ) ;
F_130 ( 24 ) ;
if ( V_988 ) {
V_217 = F_318 ( V_2 , V_990 , V_515 ) ;
V_217 &= ~ V_991 ;
F_317 ( V_2 , V_990 , V_217 , V_515 ) ;
if ( V_989 ) {
F_594 ( V_2 ) ;
F_596 ( V_2 ) ;
}
}
V_9 = F_598 ( V_16 ) ? V_992 : V_993 ;
V_217 = F_318 ( V_2 , V_9 , V_515 ) ;
V_217 |= V_994 ;
F_317 ( V_2 , V_9 , V_217 , V_515 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_599 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_9 , V_217 ;
F_2 ( & V_2 -> V_5 ) ;
V_9 = F_598 ( V_16 ) ? V_992 : V_993 ;
V_217 = F_318 ( V_2 , V_9 , V_515 ) ;
V_217 &= ~ V_994 ;
F_317 ( V_2 , V_9 , V_217 , V_515 ) ;
V_217 = F_318 ( V_2 , V_990 , V_515 ) ;
if ( ! ( V_217 & V_516 ) ) {
if ( ! ( V_217 & V_991 ) ) {
V_217 |= V_991 ;
F_317 ( V_2 , V_990 , V_217 , V_515 ) ;
F_130 ( 32 ) ;
}
V_217 |= V_516 ;
F_317 ( V_2 , V_990 , V_217 , V_515 ) ;
}
F_4 ( & V_2 -> V_5 ) ;
}
static void F_600 ( struct V_15 * V_16 )
{
struct V_41 * V_42 ;
bool V_995 = false ;
F_593 (dev, encoder) {
switch ( V_42 -> type ) {
case V_64 :
V_995 = true ;
break;
default:
break;
}
}
if ( V_995 )
F_597 ( V_16 , true , true ) ;
else
F_599 ( V_16 ) ;
}
void F_601 ( struct V_15 * V_16 )
{
if ( F_105 ( V_16 ) || F_106 ( V_16 ) )
F_592 ( V_16 ) ;
else if ( F_168 ( V_16 ) )
F_600 ( V_16 ) ;
}
static int F_602 ( struct V_43 * V_44 )
{
struct V_15 * V_16 = V_44 -> V_40 . V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_45 * V_36 = V_44 -> V_40 . V_36 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_41 * V_42 ;
int V_51 = 0 , V_50 ;
bool V_996 = false ;
F_23 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != V_44 -> V_40 . V_38 )
continue;
V_42 = F_24 ( V_49 -> V_52 ) ;
switch ( V_42 -> type ) {
case V_55 :
V_996 = true ;
break;
default:
break;
}
V_51 ++ ;
}
if ( V_996 && F_534 ( V_2 ) && V_51 < 2 ) {
F_151 ( L_139 ,
V_2 -> V_835 . V_838 ) ;
return V_2 -> V_835 . V_838 ;
}
return 120000 ;
}
static void F_392 ( struct V_111 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_2 V_10 ;
V_10 = 0 ;
switch ( V_37 -> V_115 -> V_758 ) {
case 18 :
V_10 |= V_940 ;
break;
case 24 :
V_10 |= V_247 ;
break;
case 30 :
V_10 |= V_941 ;
break;
case 36 :
V_10 |= V_997 ;
break;
default:
F_146 () ;
}
if ( V_37 -> V_115 -> V_937 )
V_10 |= ( V_938 | V_939 ) ;
if ( V_37 -> V_115 -> V_40 . V_116 . V_359 & V_917 )
V_10 |= V_250 ;
else
V_10 |= V_945 ;
if ( V_37 -> V_115 -> V_946 )
V_10 |= V_947 ;
F_128 ( F_61 ( V_119 ) , V_10 ) ;
F_129 ( F_61 ( V_119 ) ) ;
}
static void F_284 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_7 V_998 = 0x7800 ;
if ( V_37 -> V_115 -> V_946 )
V_998 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_128 ( F_603 ( V_119 ) , V_998 << 16 ) ;
F_128 ( F_604 ( V_119 ) , 0 ) ;
F_128 ( F_605 ( V_119 ) , V_998 ) ;
F_128 ( F_606 ( V_119 ) , 0 ) ;
F_128 ( F_607 ( V_119 ) , 0 ) ;
F_128 ( F_608 ( V_119 ) , V_998 << 16 ) ;
F_128 ( F_609 ( V_119 ) , 0 ) ;
F_128 ( F_610 ( V_119 ) , 0 ) ;
F_128 ( F_611 ( V_119 ) , 0 ) ;
if ( F_60 ( V_16 ) -> V_127 > 6 ) {
T_7 V_999 = 0 ;
if ( V_37 -> V_115 -> V_946 )
V_999 = ( 16 * ( 1 << 12 ) / 255 ) & 0x1fff ;
F_128 ( F_612 ( V_119 ) , V_999 ) ;
F_128 ( F_613 ( V_119 ) , V_999 ) ;
F_128 ( F_614 ( V_119 ) , V_999 ) ;
F_128 ( F_615 ( V_119 ) , 0 ) ;
} else {
T_2 V_449 = V_1000 ;
if ( V_37 -> V_115 -> V_946 )
V_449 |= V_1001 ;
F_128 ( F_615 ( V_119 ) , V_449 ) ;
}
}
static void F_399 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_119 V_119 = V_37 -> V_119 ;
enum V_118 V_121 = V_37 -> V_115 -> V_121 ;
T_2 V_10 ;
V_10 = 0 ;
if ( F_234 ( V_16 ) && V_37 -> V_115 -> V_937 )
V_10 |= ( V_938 | V_939 ) ;
if ( V_37 -> V_115 -> V_40 . V_116 . V_359 & V_917 )
V_10 |= V_250 ;
else
V_10 |= V_945 ;
F_128 ( F_61 ( V_121 ) , V_10 ) ;
F_129 ( F_61 ( V_121 ) ) ;
F_128 ( F_368 ( V_37 -> V_119 ) , V_1002 ) ;
F_129 ( F_368 ( V_37 -> V_119 ) ) ;
if ( F_235 ( V_16 ) || F_60 ( V_16 ) -> V_127 >= 9 ) {
V_10 = 0 ;
switch ( V_37 -> V_115 -> V_758 ) {
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
F_146 () ;
}
if ( V_37 -> V_115 -> V_937 )
V_10 |= V_1007 | V_1008 ;
F_128 ( F_616 ( V_119 ) , V_10 ) ;
}
}
static bool F_617 ( struct V_111 * V_38 ,
struct V_43 * V_44 ,
T_4 * clock ,
bool * V_1009 ,
T_4 * V_839 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_53 ;
const T_3 * V_54 ;
bool V_307 ;
V_53 = F_602 ( V_44 ) ;
V_54 = F_28 ( V_44 , V_53 ) ;
V_307 = V_2 -> V_453 . V_950 ( V_54 , V_44 ,
V_44 -> V_872 ,
V_53 , NULL , clock ) ;
if ( ! V_307 )
return false ;
return true ;
}
int F_500 ( int V_110 , int V_755 , int V_1010 )
{
T_1 V_1011 = V_110 * V_1010 * 21 / 20 ;
return F_184 ( V_1011 , V_755 * 8 ) ;
}
static bool F_618 ( struct V_87 * V_87 , int V_1012 )
{
return F_35 ( V_87 ) < V_1012 * V_87 -> V_84 ;
}
static T_2 F_619 ( struct V_37 * V_37 ,
struct V_43 * V_44 ,
T_1 * V_840 ,
T_4 * V_839 , T_1 * V_841 )
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
bool V_996 = false , V_895 = false ;
F_23 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != V_44 -> V_40 . V_38 )
continue;
V_42 = F_24 ( V_49 -> V_52 ) ;
switch ( V_42 -> type ) {
case V_55 :
V_996 = true ;
break;
case V_66 :
case V_63 :
V_895 = true ;
break;
default:
break;
}
V_51 ++ ;
}
V_1012 = 21 ;
if ( V_996 ) {
if ( ( F_534 ( V_2 ) &&
V_2 -> V_835 . V_838 == 100000 ) ||
( F_105 ( V_16 ) && F_26 ( V_16 ) ) )
V_1012 = 25 ;
} else if ( V_44 -> V_908 )
V_1012 = 20 ;
if ( F_618 ( & V_44 -> V_87 , V_1012 ) )
* V_840 |= V_1013 ;
if ( V_841 && ( V_839 -> V_79 < V_1012 * V_839 -> V_84 ) )
* V_841 |= V_1013 ;
V_87 = 0 ;
if ( V_996 )
V_87 |= V_896 ;
else
V_87 |= V_897 ;
V_87 |= ( V_44 -> V_608 - 1 )
<< V_1014 ;
if ( V_895 )
V_87 |= V_899 ;
if ( V_44 -> V_536 )
V_87 |= V_899 ;
V_87 |= ( 1 << ( V_44 -> V_87 . V_82 - 1 ) ) << V_901 ;
V_87 |= ( 1 << ( V_44 -> V_87 . V_82 - 1 ) ) << V_902 ;
switch ( V_44 -> V_87 . V_83 ) {
case 5 :
V_87 |= V_903 ;
break;
case 7 :
V_87 |= V_904 ;
break;
case 10 :
V_87 |= V_905 ;
break;
case 14 :
V_87 |= V_906 ;
break;
}
if ( V_996 && F_534 ( V_2 ) && V_51 < 2 )
V_87 |= V_910 ;
else
V_87 |= V_911 ;
return V_87 | V_131 ;
}
static int F_620 ( struct V_37 * V_38 ,
struct V_43 * V_44 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
T_4 clock , V_839 ;
T_1 V_87 = 0 , V_840 = 0 , V_841 = 0 ;
bool V_948 , V_1009 = false ;
bool V_996 = false ;
struct V_134 * V_137 ;
memset ( & V_44 -> V_212 , 0 ,
sizeof( V_44 -> V_212 ) ) ;
V_996 = F_20 ( V_38 , V_55 ) ;
F_6 ( ! ( F_105 ( V_16 ) || F_106 ( V_16 ) ) ,
L_154 , F_621 ( V_16 ) ) ;
V_948 = F_617 ( & V_38 -> V_40 , V_44 , & clock ,
& V_1009 , & V_839 ) ;
if ( ! V_948 && ! V_44 -> V_949 ) {
F_131 ( L_143 ) ;
return - V_309 ;
}
if ( ! V_44 -> V_949 ) {
V_44 -> V_87 . V_84 = clock . V_84 ;
V_44 -> V_87 . V_88 = clock . V_88 ;
V_44 -> V_87 . V_80 = clock . V_80 ;
V_44 -> V_87 . V_82 = clock . V_82 ;
V_44 -> V_87 . V_83 = clock . V_83 ;
}
if ( V_44 -> V_260 ) {
V_840 = F_536 ( & V_44 -> V_87 ) ;
if ( V_1009 )
V_841 = F_536 ( & V_839 ) ;
V_87 = F_619 ( V_38 , V_44 ,
& V_840 , & V_839 ,
V_1009 ? & V_841 : NULL ) ;
V_44 -> V_212 . V_87 = V_87 ;
V_44 -> V_212 . V_736 = V_840 ;
if ( V_1009 )
V_44 -> V_212 . V_737 = V_841 ;
else
V_44 -> V_212 . V_737 = V_840 ;
V_137 = F_347 ( V_38 , V_44 ) ;
if ( V_137 == NULL ) {
F_15 ( L_155 ,
F_80 ( V_38 -> V_119 ) ) ;
return - V_309 ;
}
}
if ( V_996 && V_1009 )
V_38 -> V_842 = true ;
else
V_38 -> V_842 = false ;
return 0 ;
}
static void F_622 ( struct V_37 * V_38 ,
struct V_827 * V_828 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 = V_38 -> V_119 ;
V_828 -> V_832 = F_11 ( F_544 ( V_119 ) ) ;
V_828 -> V_833 = F_11 ( F_545 ( V_119 ) ) ;
V_828 -> V_830 = F_11 ( F_541 ( V_119 ) )
& ~ V_531 ;
V_828 -> V_831 = F_11 ( F_543 ( V_119 ) ) ;
V_828 -> V_829 = ( ( F_11 ( F_541 ( V_119 ) )
& V_531 ) >> V_1015 ) + 1 ;
}
static void F_623 ( struct V_37 * V_38 ,
enum V_118 V_118 ,
struct V_827 * V_828 ,
struct V_827 * V_845 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 = V_38 -> V_119 ;
if ( F_60 ( V_16 ) -> V_127 >= 5 ) {
V_828 -> V_832 = F_11 ( F_547 ( V_118 ) ) ;
V_828 -> V_833 = F_11 ( F_548 ( V_118 ) ) ;
V_828 -> V_830 = F_11 ( F_342 ( V_118 ) )
& ~ V_531 ;
V_828 -> V_831 = F_11 ( F_546 ( V_118 ) ) ;
V_828 -> V_829 = ( ( F_11 ( F_342 ( V_118 ) )
& V_531 ) >> V_1015 ) + 1 ;
if ( V_845 && F_60 ( V_16 ) -> V_127 < 8 &&
V_38 -> V_115 -> V_846 ) {
V_845 -> V_832 = F_11 ( F_551 ( V_118 ) ) ;
V_845 -> V_833 = F_11 ( F_552 ( V_118 ) ) ;
V_845 -> V_830 = F_11 ( F_549 ( V_118 ) )
& ~ V_531 ;
V_845 -> V_831 = F_11 ( F_550 ( V_118 ) ) ;
V_845 -> V_829 = ( ( F_11 ( F_549 ( V_118 ) )
& V_531 ) >> V_1015 ) + 1 ;
}
} else {
V_828 -> V_832 = F_11 ( F_555 ( V_119 ) ) ;
V_828 -> V_833 = F_11 ( F_556 ( V_119 ) ) ;
V_828 -> V_830 = F_11 ( F_553 ( V_119 ) )
& ~ V_531 ;
V_828 -> V_831 = F_11 ( F_554 ( V_119 ) ) ;
V_828 -> V_829 = ( ( F_11 ( F_553 ( V_119 ) )
& V_531 ) >> V_1015 ) + 1 ;
}
}
void F_624 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
if ( V_211 -> V_260 )
F_622 ( V_38 , & V_211 -> V_848 ) ;
else
F_623 ( V_38 , V_211 -> V_121 ,
& V_211 -> V_848 ,
& V_211 -> V_849 ) ;
}
static void F_625 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
F_623 ( V_38 , V_211 -> V_121 ,
& V_211 -> V_603 , NULL ) ;
}
static void F_626 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_402 * V_403 = & V_211 -> V_403 ;
T_2 V_447 = 0 ;
int V_240 = - 1 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_38 -> V_404 ; V_50 ++ ) {
V_447 = F_11 ( F_241 ( V_38 -> V_119 , V_50 ) ) ;
if ( V_447 & V_448 && ! ( V_447 & V_1016 ) ) {
V_240 = V_50 ;
V_211 -> V_466 . V_129 = true ;
V_211 -> V_466 . V_570 = F_11 ( F_242 ( V_38 -> V_119 , V_50 ) ) ;
V_211 -> V_466 . V_294 = F_11 ( F_243 ( V_38 -> V_119 , V_50 ) ) ;
break;
}
}
V_403 -> V_440 = V_240 ;
if ( V_240 >= 0 ) {
V_403 -> V_554 |= ( 1 << V_564 ) ;
} else {
V_403 -> V_554 &= ~ ( 1 << V_564 ) ;
}
}
static void
F_627 ( struct V_37 * V_38 ,
struct V_347 * V_348 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 , V_40 , V_324 , V_1017 , V_355 ;
int V_119 = V_38 -> V_119 ;
int V_955 , V_264 ;
unsigned int V_956 ;
struct V_275 * V_114 ;
struct V_957 * V_958 ;
V_958 = F_491 ( sizeof( * V_958 ) , V_750 ) ;
if ( ! V_958 ) {
F_151 ( L_144 ) ;
return;
}
V_114 = & V_958 -> V_40 ;
V_10 = F_11 ( F_95 ( V_119 , 0 ) ) ;
if ( ! ( V_10 & V_175 ) )
goto error;
V_264 = V_10 & V_1018 ;
V_955 = F_201 ( V_264 ,
V_10 & V_408 ,
V_10 & V_1019 ) ;
V_114 -> V_264 = V_955 ;
V_114 -> V_395 = F_177 ( V_955 , 0 ) * 8 ;
V_355 = V_10 & V_1020 ;
switch ( V_355 ) {
case V_1021 :
V_114 -> V_290 [ 0 ] = V_268 ;
break;
case V_419 :
V_348 -> V_355 = V_356 ;
V_114 -> V_290 [ 0 ] = V_269 ;
break;
case V_420 :
V_114 -> V_290 [ 0 ] = V_270 ;
break;
case V_421 :
V_114 -> V_290 [ 0 ] = V_271 ;
break;
default:
F_179 ( V_355 ) ;
goto error;
}
V_40 = F_11 ( F_249 ( V_119 , 0 ) ) & 0xfffff000 ;
V_348 -> V_40 = V_40 ;
V_324 = F_11 ( F_252 ( V_119 , 0 ) ) ;
V_10 = F_11 ( F_253 ( V_119 , 0 ) ) ;
V_114 -> V_272 = ( ( V_10 >> 16 ) & 0xfff ) + 1 ;
V_114 -> V_358 = ( ( V_10 >> 0 ) & 0x1fff ) + 1 ;
V_10 = F_11 ( F_254 ( V_119 , 0 ) ) ;
V_1017 = F_237 ( V_16 , V_114 -> V_290 [ 0 ] ,
V_114 -> V_264 ) ;
V_114 -> V_286 [ 0 ] = ( V_10 & 0x3ff ) * V_1017 ;
V_956 = F_180 ( V_16 , V_114 -> V_272 ,
V_114 -> V_264 ,
V_114 -> V_290 [ 0 ] ) ;
V_348 -> V_294 = V_114 -> V_286 [ 0 ] * V_956 ;
F_151 ( L_156 ,
F_80 ( V_119 ) , V_114 -> V_358 , V_114 -> V_272 ,
V_114 -> V_395 , V_40 , V_114 -> V_286 [ 0 ] ,
V_348 -> V_294 ) ;
V_348 -> V_114 = V_958 ;
return;
error:
F_215 ( V_114 ) ;
}
static void F_628 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_217 ;
V_217 = F_11 ( F_358 ( V_38 -> V_119 ) ) ;
if ( V_217 & V_571 ) {
V_211 -> V_466 . V_129 = true ;
V_211 -> V_466 . V_570 = F_11 ( F_360 ( V_38 -> V_119 ) ) ;
V_211 -> V_466 . V_294 = F_11 ( F_361 ( V_38 -> V_119 ) ) ;
if ( F_629 ( V_16 ) ) {
F_9 ( ( V_217 & V_1022 ) !=
F_359 ( V_38 -> V_119 ) ) ;
}
}
}
static void
F_630 ( struct V_37 * V_38 ,
struct V_347 * V_348 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 , V_40 , V_324 ;
int V_119 = V_38 -> V_119 ;
int V_955 , V_264 ;
unsigned int V_956 ;
struct V_275 * V_114 ;
struct V_957 * V_958 ;
V_10 = F_11 ( F_89 ( V_119 ) ) ;
if ( ! ( V_10 & V_170 ) )
return;
V_958 = F_491 ( sizeof( * V_958 ) , V_750 ) ;
if ( ! V_958 ) {
F_151 ( L_144 ) ;
return;
}
V_114 = & V_958 -> V_40 ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
if ( V_10 & V_387 ) {
V_348 -> V_355 = V_356 ;
V_114 -> V_290 [ 0 ] = V_269 ;
}
}
V_264 = V_10 & V_959 ;
V_955 = F_200 ( V_264 ) ;
V_114 -> V_264 = V_955 ;
V_114 -> V_395 = F_177 ( V_955 , 0 ) * 8 ;
V_40 = F_11 ( F_222 ( V_119 ) ) & 0xfffff000 ;
if ( F_234 ( V_16 ) || F_235 ( V_16 ) ) {
V_324 = F_11 ( F_236 ( V_119 ) ) ;
} else {
if ( V_348 -> V_355 )
V_324 = F_11 ( F_231 ( V_119 ) ) ;
else
V_324 = F_11 ( F_232 ( V_119 ) ) ;
}
V_348 -> V_40 = V_40 ;
V_10 = F_11 ( F_285 ( V_119 ) ) ;
V_114 -> V_358 = ( ( V_10 >> 16 ) & 0xfff ) + 1 ;
V_114 -> V_272 = ( ( V_10 >> 0 ) & 0xfff ) + 1 ;
V_10 = F_11 ( F_230 ( V_119 ) ) ;
V_114 -> V_286 [ 0 ] = V_10 & 0xffffffc0 ;
V_956 = F_180 ( V_16 , V_114 -> V_272 ,
V_114 -> V_264 ,
V_114 -> V_290 [ 0 ] ) ;
V_348 -> V_294 = V_114 -> V_286 [ 0 ] * V_956 ;
F_151 ( L_156 ,
F_80 ( V_119 ) , V_114 -> V_358 , V_114 -> V_272 ,
V_114 -> V_395 , V_40 , V_114 -> V_286 [ 0 ] ,
V_348 -> V_294 ) ;
V_348 -> V_114 = V_958 ;
}
static bool F_631 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_217 ;
if ( ! F_86 ( V_2 ,
F_419 ( V_38 -> V_119 ) ) )
return false ;
V_211 -> V_121 = (enum V_118 ) V_38 -> V_119 ;
V_211 -> V_135 = V_965 ;
V_217 = F_11 ( F_61 ( V_38 -> V_119 ) ) ;
if ( ! ( V_217 & V_168 ) )
return false ;
switch ( V_217 & V_246 ) {
case V_940 :
V_211 -> V_758 = 18 ;
break;
case V_247 :
V_211 -> V_758 = 24 ;
break;
case V_941 :
V_211 -> V_758 = 30 ;
break;
case V_997 :
V_211 -> V_758 = 36 ;
break;
default:
break;
}
if ( V_217 & V_947 )
V_211 -> V_946 = true ;
if ( F_11 ( F_108 ( V_38 -> V_119 ) ) & V_183 ) {
struct V_134 * V_137 ;
V_211 -> V_260 = true ;
V_217 = F_11 ( F_75 ( V_38 -> V_119 ) ) ;
V_211 -> V_480 = ( ( V_479 & V_217 ) >>
V_1023 ) + 1 ;
F_625 ( V_38 , V_211 ) ;
if ( F_105 ( V_2 -> V_16 ) ) {
V_211 -> V_135 =
(enum V_546 ) V_38 -> V_119 ;
} else {
V_217 = F_11 ( V_534 ) ;
if ( V_217 & F_344 ( V_38 -> V_119 ) )
V_211 -> V_135 = V_535 ;
else
V_211 -> V_135 = V_1024 ;
}
V_137 = & V_2 -> V_136 [ V_211 -> V_135 ] ;
F_9 ( ! V_137 -> V_140 ( V_2 , V_137 ,
& V_211 -> V_212 ) ) ;
V_217 = V_211 -> V_212 . V_87 ;
V_211 -> V_608 =
( ( V_217 & V_1025 )
>> V_1014 ) + 1 ;
F_632 ( V_38 , V_211 ) ;
} else {
V_211 -> V_608 = 1 ;
}
F_579 ( V_38 , V_211 ) ;
F_628 ( V_38 , V_211 ) ;
return true ;
}
static void F_633 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_37 * V_38 ;
F_139 (dev, crtc)
F_66 ( V_38 -> V_112 , L_157 ,
F_80 ( V_38 -> V_119 ) ) ;
F_66 ( F_11 ( V_1026 ) , L_158 ) ;
F_66 ( F_11 ( V_1027 ) & V_1028 , L_159 ) ;
F_66 ( F_11 ( V_1029 ) & V_1030 , L_160 ) ;
F_66 ( F_11 ( V_1031 ) & V_1030 , L_161 ) ;
F_66 ( F_11 ( V_1032 ) & V_1033 , L_162 ) ;
F_66 ( F_11 ( V_1034 ) & V_1035 ,
L_163 ) ;
if ( F_234 ( V_16 ) )
F_66 ( F_11 ( V_1036 ) & V_1035 ,
L_164 ) ;
F_66 ( F_11 ( V_1037 ) & V_1038 ,
L_165 ) ;
F_66 ( F_11 ( V_1039 ) & V_1040 ,
L_166 ) ;
F_66 ( F_11 ( V_1041 ) & V_1042 , L_167 ) ;
F_66 ( F_634 ( V_2 ) , L_168 ) ;
}
static T_2 F_635 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_234 ( V_16 ) )
return F_11 ( V_1043 ) ;
else
return F_11 ( V_1044 ) ;
}
static void F_636 ( struct V_1 * V_2 , T_2 V_10 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_234 ( V_16 ) ) {
F_2 ( & V_2 -> V_574 . V_575 ) ;
if ( F_364 ( V_2 , V_1045 ,
V_10 ) )
F_131 ( L_169 ) ;
F_4 ( & V_2 -> V_574 . V_575 ) ;
} else {
F_128 ( V_1044 , V_10 ) ;
F_129 ( V_1044 ) ;
}
}
static void F_637 ( struct V_1 * V_2 ,
bool V_1046 , bool V_1047 )
{
T_2 V_10 ;
F_633 ( V_2 ) ;
V_10 = F_11 ( V_772 ) ;
if ( V_1046 ) {
V_10 |= V_774 ;
F_128 ( V_772 , V_10 ) ;
if ( F_595 ( F_11 ( V_772 ) &
V_1048 , 1 ) )
F_131 ( L_170 ) ;
V_10 = F_11 ( V_772 ) ;
}
V_10 |= V_1049 ;
F_128 ( V_772 , V_10 ) ;
F_129 ( V_772 ) ;
if ( F_62 ( ( F_11 ( V_772 ) & V_700 ) == 0 , 1 ) )
F_131 ( L_171 ) ;
V_10 = F_635 ( V_2 ) ;
V_10 |= V_1050 ;
F_636 ( V_2 , V_10 ) ;
F_638 ( 100 ) ;
if ( F_62 ( ( F_635 ( V_2 ) & V_1051 ) == 0 ,
1 ) )
F_131 ( L_172 ) ;
if ( V_1047 ) {
V_10 = F_11 ( V_772 ) ;
V_10 |= V_1052 ;
F_128 ( V_772 , V_10 ) ;
F_129 ( V_772 ) ;
}
}
static void F_639 ( struct V_1 * V_2 )
{
T_2 V_10 ;
V_10 = F_11 ( V_772 ) ;
if ( ( V_10 & ( V_700 | V_1049 | V_774 |
V_1052 ) ) == V_700 )
return;
F_640 ( V_2 , V_1053 ) ;
if ( V_10 & V_1052 ) {
V_10 &= ~ V_1052 ;
F_128 ( V_772 , V_10 ) ;
F_129 ( V_772 ) ;
}
V_10 = F_635 ( V_2 ) ;
V_10 |= V_1054 ;
V_10 &= ~ V_1050 ;
F_636 ( V_2 , V_10 ) ;
V_10 = F_11 ( V_772 ) ;
V_10 &= ~ V_1049 ;
F_128 ( V_772 , V_10 ) ;
if ( F_62 ( F_11 ( V_772 ) & V_700 , 5 ) )
F_131 ( L_173 ) ;
if ( V_10 & V_774 ) {
V_10 = F_11 ( V_772 ) ;
V_10 &= ~ V_774 ;
F_128 ( V_772 , V_10 ) ;
if ( F_595 ( ( F_11 ( V_772 ) &
V_1048 ) == 0 , 1 ) )
F_131 ( L_174 ) ;
}
F_641 ( V_2 , V_1053 ) ;
F_431 ( V_2 -> V_16 ) ;
}
void F_642 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_10 ;
F_151 ( L_175 ) ;
if ( F_598 ( V_16 ) ) {
V_10 = F_11 ( V_1055 ) ;
V_10 &= ~ V_1056 ;
F_128 ( V_1055 , V_10 ) ;
}
F_599 ( V_16 ) ;
F_637 ( V_2 , true , true ) ;
}
void F_643 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_10 ;
F_151 ( L_176 ) ;
F_639 ( V_2 ) ;
F_600 ( V_16 ) ;
if ( F_598 ( V_16 ) ) {
V_10 = F_11 ( V_1055 ) ;
V_10 |= V_1056 ;
F_128 ( V_1055 , V_10 ) ;
}
F_644 ( V_16 ) ;
}
static void F_645 ( struct V_45 * V_732 )
{
struct V_15 * V_16 = V_732 -> V_16 ;
unsigned int V_733 = F_352 ( V_732 ) -> V_650 ;
F_432 ( V_16 , V_733 ) ;
}
static int F_646 ( struct V_45 * V_36 )
{
struct V_37 * V_37 ;
struct V_43 * V_44 ;
int V_1057 = 0 ;
F_139 (state->dev, intel_crtc) {
int V_1058 ;
V_44 = F_460 ( V_36 , V_37 ) ;
if ( F_461 ( V_44 ) )
return F_462 ( V_44 ) ;
if ( ! V_44 -> V_40 . V_242 )
continue;
V_1058 = F_503 ( V_44 ) ;
if ( F_235 ( V_36 -> V_16 ) && V_44 -> V_573 )
V_1058 = F_184 ( V_1058 * 100 , 95 ) ;
V_1057 = V_91 ( V_1057 , V_1058 ) ;
}
return V_1057 ;
}
static void F_647 ( struct V_15 * V_16 , int V_650 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_10 , V_1059 ;
int V_307 ;
if ( F_6 ( ( F_11 ( V_772 ) &
( V_1049 | V_700 |
V_1060 | V_1061 |
V_1062 | V_1052 |
V_774 ) ) != V_700 ,
L_177 ) )
return;
F_2 ( & V_2 -> V_574 . V_575 ) ;
V_307 = F_364 ( V_2 ,
V_1063 , 0x0 ) ;
F_4 ( & V_2 -> V_574 . V_575 ) ;
if ( V_307 ) {
F_131 ( L_178 ) ;
return;
}
V_10 = F_11 ( V_772 ) ;
V_10 |= V_774 ;
F_128 ( V_772 , V_10 ) ;
if ( F_595 ( F_11 ( V_772 ) &
V_1048 , 1 ) )
F_131 ( L_170 ) ;
V_10 = F_11 ( V_772 ) ;
V_10 &= ~ V_773 ;
switch ( V_650 ) {
case 450000 :
V_10 |= V_775 ;
V_1059 = 0 ;
break;
case 540000 :
V_10 |= V_776 ;
V_1059 = 1 ;
break;
case 337500 :
V_10 |= V_777 ;
V_1059 = 2 ;
break;
case 675000 :
V_10 |= V_1064 ;
V_1059 = 3 ;
break;
default:
F_6 ( 1 , L_179 ) ;
return;
}
F_128 ( V_772 , V_10 ) ;
V_10 = F_11 ( V_772 ) ;
V_10 &= ~ V_774 ;
F_128 ( V_772 , V_10 ) ;
if ( F_595 ( ( F_11 ( V_772 ) &
V_1048 ) == 0 , 1 ) )
F_131 ( L_174 ) ;
F_2 ( & V_2 -> V_574 . V_575 ) ;
F_364 ( V_2 , V_671 , V_1059 ) ;
F_4 ( & V_2 -> V_574 . V_575 ) ;
F_431 ( V_16 ) ;
F_6 ( V_650 != V_2 -> V_651 ,
L_180 ,
V_650 , V_2 -> V_651 ) ;
}
static int F_648 ( struct V_45 * V_36 )
{
struct V_1 * V_2 = F_203 ( V_36 -> V_16 ) ;
int V_724 = F_646 ( V_36 ) ;
int V_650 ;
if ( V_724 > 540000 )
V_650 = 675000 ;
else if ( V_724 > 450000 )
V_650 = 540000 ;
else if ( V_724 > 337500 )
V_650 = 450000 ;
else
V_650 = 337500 ;
if ( V_650 > V_2 -> V_653 ) {
F_131 ( L_181 ,
V_650 , V_2 -> V_653 ) ;
V_650 = V_2 -> V_653 ;
}
F_352 ( V_36 ) -> V_650 = V_650 ;
return 0 ;
}
static void F_649 ( struct V_45 * V_732 )
{
struct V_15 * V_16 = V_732 -> V_16 ;
unsigned int V_733 = F_352 ( V_732 ) -> V_650 ;
F_647 ( V_16 , V_733 ) ;
}
static int F_650 ( struct V_37 * V_38 ,
struct V_43 * V_44 )
{
if ( ! F_651 ( V_38 , V_44 ) )
return - V_309 ;
V_38 -> V_842 = false ;
return 0 ;
}
static void F_652 ( struct V_1 * V_2 ,
enum V_216 V_216 ,
struct V_43 * V_211 )
{
switch ( V_216 ) {
case V_622 :
V_211 -> V_1065 = V_695 ;
V_211 -> V_135 = V_1066 ;
break;
case V_230 :
V_211 -> V_1065 = V_1067 ;
V_211 -> V_135 = V_1068 ;
break;
case V_232 :
V_211 -> V_1065 = V_1069 ;
V_211 -> V_135 = V_1070 ;
break;
default:
F_131 ( L_182 ) ;
}
}
static void F_653 ( struct V_1 * V_2 ,
enum V_216 V_216 ,
struct V_43 * V_211 )
{
T_1 V_467 , V_1071 ;
V_467 = F_11 ( V_1072 ) & F_654 ( V_216 ) ;
V_211 -> V_1065 = V_467 >> ( V_216 * 3 + 1 ) ;
switch ( V_211 -> V_1065 ) {
case V_695 :
V_1071 = F_11 ( V_694 ) ;
V_211 -> V_212 . V_1073 = V_1071 & 0x3f ;
break;
case V_1067 :
V_211 -> V_135 = V_1066 ;
break;
case V_1069 :
V_211 -> V_135 = V_1068 ;
break;
case V_1074 :
V_211 -> V_135 = V_1070 ;
break;
}
}
static void F_655 ( struct V_1 * V_2 ,
enum V_216 V_216 ,
struct V_43 * V_211 )
{
V_211 -> V_1065 = F_11 ( F_656 ( V_216 ) ) ;
switch ( V_211 -> V_1065 ) {
case V_1075 :
V_211 -> V_135 = V_1076 ;
break;
case V_1077 :
V_211 -> V_135 = V_1078 ;
break;
case V_1079 :
V_211 -> V_135 = V_1080 ;
}
}
static void F_657 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_134 * V_137 ;
enum V_216 V_216 ;
T_2 V_217 ;
V_217 = F_11 ( F_72 ( V_211 -> V_121 ) ) ;
V_216 = ( V_217 & V_1081 ) >> V_1082 ;
if ( F_428 ( V_16 ) )
F_653 ( V_2 , V_216 , V_211 ) ;
else if ( F_29 ( V_16 ) )
F_652 ( V_2 , V_216 , V_211 ) ;
else
F_655 ( V_2 , V_216 , V_211 ) ;
if ( V_211 -> V_135 >= 0 ) {
V_137 = & V_2 -> V_136 [ V_211 -> V_135 ] ;
F_9 ( ! V_137 -> V_140 ( V_2 , V_137 ,
& V_211 -> V_212 ) ) ;
}
if ( F_60 ( V_16 ) -> V_127 < 9 &&
( V_216 == V_627 ) && F_11 ( V_257 ) & V_183 ) {
V_211 -> V_260 = true ;
V_217 = F_11 ( F_75 ( V_148 ) ) ;
V_211 -> V_480 = ( ( V_479 & V_217 ) >>
V_1023 ) + 1 ;
F_625 ( V_38 , V_211 ) ;
}
}
static bool F_658 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_621 V_1083 ;
T_2 V_217 ;
if ( ! F_86 ( V_2 ,
F_419 ( V_38 -> V_119 ) ) )
return false ;
V_211 -> V_121 = (enum V_118 ) V_38 -> V_119 ;
V_211 -> V_135 = V_965 ;
V_217 = F_11 ( F_72 ( V_607 ) ) ;
if ( V_217 & V_141 ) {
enum V_119 V_1084 ;
switch ( V_217 & V_1085 ) {
default:
F_6 ( 1 , L_183 ) ;
case V_1086 :
case V_1087 :
V_1084 = V_148 ;
break;
case V_1088 :
V_1084 = V_157 ;
break;
case V_1089 :
V_1084 = V_530 ;
break;
}
if ( V_1084 == V_38 -> V_119 )
V_211 -> V_121 = V_607 ;
}
if ( ! F_86 ( V_2 ,
F_87 ( V_211 -> V_121 ) ) )
return false ;
V_217 = F_11 ( F_61 ( V_211 -> V_121 ) ) ;
if ( ! ( V_217 & V_168 ) )
return false ;
F_657 ( V_38 , V_211 ) ;
F_579 ( V_38 , V_211 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
F_659 ( V_16 , V_38 , V_211 ) ;
}
V_1083 = F_420 ( V_38 -> V_119 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
V_211 -> V_403 . V_440 = - 1 ;
V_211 -> V_403 . V_554 &= ~ ( 1 << V_564 ) ;
}
if ( F_86 ( V_2 , V_1083 ) ) {
if ( F_60 ( V_16 ) -> V_127 >= 9 )
F_626 ( V_38 , V_211 ) ;
else
F_628 ( V_38 , V_211 ) ;
}
if ( F_234 ( V_16 ) )
V_211 -> V_573 = F_395 ( V_38 ) &&
( F_11 ( V_577 ) & V_578 ) ;
if ( V_211 -> V_121 != V_607 ) {
V_211 -> V_608 =
F_11 ( F_398 ( V_211 -> V_121 ) ) + 1 ;
} else {
V_211 -> V_608 = 1 ;
}
return true ;
}
static void F_660 ( struct V_111 * V_38 , T_1 V_40 , bool V_238 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_2 V_1090 = 0 , V_294 = 0 ;
if ( V_238 ) {
unsigned int V_358 = V_37 -> V_40 . V_1091 -> V_36 -> V_374 ;
unsigned int V_272 = V_37 -> V_40 . V_1091 -> V_36 -> V_375 ;
unsigned int V_357 = F_661 ( V_358 ) * 4 ;
switch ( V_357 ) {
default:
F_178 ( 1 , L_184 ,
V_358 , V_357 ) ;
V_357 = 256 ;
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
}
V_1090 |= V_163 |
V_1092 |
V_1093 |
F_662 ( V_357 ) ;
V_294 = ( V_272 << 12 ) | V_358 ;
}
if ( V_37 -> V_1094 != 0 &&
( V_37 -> V_1095 != V_40 ||
V_37 -> V_1096 != V_294 ||
V_37 -> V_1094 != V_1090 ) ) {
F_128 ( F_84 ( V_148 ) , 0 ) ;
F_129 ( F_84 ( V_148 ) ) ;
V_37 -> V_1094 = 0 ;
}
if ( V_37 -> V_1095 != V_40 ) {
F_128 ( F_663 ( V_148 ) , V_40 ) ;
V_37 -> V_1095 = V_40 ;
}
if ( V_37 -> V_1096 != V_294 ) {
F_128 ( V_1097 , V_294 ) ;
V_37 -> V_1096 = V_294 ;
}
if ( V_37 -> V_1094 != V_1090 ) {
F_128 ( F_84 ( V_148 ) , V_1090 ) ;
F_129 ( F_84 ( V_148 ) ) ;
V_37 -> V_1094 = V_1090 ;
}
}
static void F_664 ( struct V_111 * V_38 , T_1 V_40 , bool V_238 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
T_2 V_1090 = 0 ;
if ( V_238 ) {
V_1090 = V_1098 ;
switch ( V_37 -> V_40 . V_1091 -> V_36 -> V_374 ) {
case 64 :
V_1090 |= V_1099 ;
break;
case 128 :
V_1090 |= V_1100 ;
break;
case 256 :
V_1090 |= V_1101 ;
break;
default:
F_179 ( V_37 -> V_40 . V_1091 -> V_36 -> V_374 ) ;
return;
}
V_1090 |= V_119 << 28 ;
if ( F_71 ( V_16 ) )
V_1090 |= V_1102 ;
}
if ( V_38 -> V_1091 -> V_36 -> V_283 == F_229 ( V_390 ) )
V_1090 |= V_1103 ;
if ( V_37 -> V_1094 != V_1090 ) {
F_128 ( F_84 ( V_119 ) , V_1090 ) ;
F_129 ( F_84 ( V_119 ) ) ;
V_37 -> V_1094 = V_1090 ;
}
F_128 ( F_663 ( V_119 ) , V_40 ) ;
F_129 ( F_663 ( V_119 ) ) ;
V_37 -> V_1095 = V_40 ;
}
static void F_665 ( struct V_111 * V_38 ,
bool V_238 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
int V_119 = V_37 -> V_119 ;
struct V_276 * V_1104 = V_38 -> V_1091 -> V_36 ;
int V_317 = V_1104 -> V_372 ;
int V_318 = V_1104 -> V_373 ;
T_1 V_40 = 0 , V_570 = 0 ;
V_40 = V_37 -> V_1105 ;
if ( V_317 >= V_37 -> V_115 -> V_385 )
V_238 = false ;
if ( V_318 >= V_37 -> V_115 -> V_384 )
V_238 = false ;
if ( V_317 < 0 ) {
if ( V_317 + V_1104 -> V_374 <= 0 )
V_238 = false ;
V_570 |= V_1106 << V_1107 ;
V_317 = - V_317 ;
}
V_570 |= V_317 << V_1107 ;
if ( V_318 < 0 ) {
if ( V_318 + V_1104 -> V_375 <= 0 )
V_238 = false ;
V_570 |= V_1106 << V_1108 ;
V_318 = - V_318 ;
}
V_570 |= V_318 << V_1108 ;
F_128 ( F_666 ( V_119 ) , V_570 ) ;
if ( F_169 ( V_16 ) &&
V_38 -> V_1091 -> V_36 -> V_283 == F_229 ( V_390 ) ) {
V_40 += ( V_1104 -> V_375 *
V_1104 -> V_374 - 1 ) * 4 ;
}
if ( F_82 ( V_16 ) || F_83 ( V_16 ) )
F_660 ( V_38 , V_40 , V_238 ) ;
else
F_664 ( V_38 , V_40 , V_238 ) ;
}
static bool F_667 ( struct V_15 * V_16 ,
T_2 V_358 , T_2 V_272 )
{
if ( V_358 == 0 || V_272 == 0 )
return false ;
if ( F_82 ( V_16 ) || F_83 ( V_16 ) ) {
if ( ( V_358 & 63 ) != 0 )
return false ;
if ( V_358 > ( F_82 ( V_16 ) ? 64 : 512 ) )
return false ;
if ( V_272 > 1023 )
return false ;
} else {
switch ( V_358 | V_272 ) {
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
static void F_668 ( struct V_111 * V_38 , T_5 * V_1109 , T_5 * V_1110 ,
T_5 * V_1111 , T_2 V_399 , T_2 V_294 )
{
int V_1112 = ( V_399 + V_294 > 256 ) ? 256 : V_399 + V_294 , V_50 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
for ( V_50 = V_399 ; V_50 < V_1112 ; V_50 ++ ) {
V_37 -> V_583 [ V_50 ] = V_1109 [ V_50 ] >> 8 ;
V_37 -> V_584 [ V_50 ] = V_1110 [ V_50 ] >> 8 ;
V_37 -> V_585 [ V_50 ] = V_1111 [ V_50 ] >> 8 ;
}
F_367 ( V_38 ) ;
}
struct V_275 *
F_669 ( struct V_15 * V_16 ,
struct V_349 * V_350 ,
struct V_304 * V_305 )
{
struct V_957 * V_958 ;
int V_307 ;
V_958 = F_491 ( sizeof( * V_958 ) , V_750 ) ;
if ( ! V_958 ) {
F_209 ( & V_305 -> V_40 ) ;
return F_670 ( - V_746 ) ;
}
V_307 = F_207 ( V_16 , V_958 , V_350 , V_305 ) ;
if ( V_307 )
goto V_98;
return & V_958 -> V_40 ;
V_98:
F_209 ( & V_305 -> V_40 ) ;
F_215 ( V_958 ) ;
return F_670 ( V_307 ) ;
}
static struct V_275 *
F_671 ( struct V_15 * V_16 ,
struct V_349 * V_350 ,
struct V_304 * V_305 )
{
struct V_275 * V_114 ;
int V_307 ;
V_307 = F_672 ( V_16 ) ;
if ( V_307 )
return F_670 ( V_307 ) ;
V_114 = F_669 ( V_16 , V_350 , V_305 ) ;
F_4 ( & V_16 -> V_308 ) ;
return V_114 ;
}
static T_1
F_673 ( int V_358 , int V_1010 )
{
T_1 V_285 = F_184 ( V_358 * V_1010 , 8 ) ;
return F_181 ( V_285 , 64 ) ;
}
static T_1
F_674 ( struct V_563 * V_449 , int V_1010 )
{
T_1 V_285 = F_673 ( V_449 -> V_926 , V_1010 ) ;
return F_675 ( V_285 * V_449 -> V_925 ) ;
}
static struct V_275 *
F_676 ( struct V_15 * V_16 ,
struct V_563 * V_449 ,
int V_1113 , int V_1010 )
{
struct V_304 * V_305 ;
struct V_349 V_350 = { 0 } ;
V_305 = F_677 ( V_16 ,
F_674 ( V_449 , V_1010 ) ) ;
if ( V_305 == NULL )
return F_670 ( - V_746 ) ;
V_350 . V_358 = V_449 -> V_926 ;
V_350 . V_272 = V_449 -> V_925 ;
V_350 . V_286 [ 0 ] = F_673 ( V_350 . V_358 ,
V_1010 ) ;
V_350 . V_264 = F_678 ( V_1010 , V_1113 ) ;
return F_671 ( V_16 , & V_350 , V_305 ) ;
}
static struct V_275 *
F_679 ( struct V_15 * V_16 ,
struct V_563 * V_449 )
{
#ifdef F_680
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_304 * V_305 ;
struct V_275 * V_114 ;
if ( ! V_2 -> V_1114 )
return NULL ;
if ( ! V_2 -> V_1114 -> V_114 )
return NULL ;
V_305 = V_2 -> V_1114 -> V_114 -> V_305 ;
F_126 ( ! V_305 ) ;
V_114 = & V_2 -> V_1114 -> V_114 -> V_40 ;
if ( V_114 -> V_286 [ 0 ] < F_673 ( V_449 -> V_926 ,
V_114 -> V_395 ) )
return NULL ;
if ( V_305 -> V_40 . V_294 < V_449 -> V_925 * V_114 -> V_286 [ 0 ] )
return NULL ;
return V_114 ;
#else
return NULL ;
#endif
}
static int F_681 ( struct V_45 * V_36 ,
struct V_111 * V_38 ,
struct V_563 * V_449 ,
struct V_275 * V_114 ,
int V_317 , int V_318 )
{
struct V_276 * V_277 ;
int V_926 , V_925 ;
int V_307 ;
V_277 = F_682 ( V_36 , V_38 -> V_113 ) ;
if ( F_461 ( V_277 ) )
return F_462 ( V_277 ) ;
if ( V_449 )
F_683 ( V_449 , & V_926 , & V_925 ) ;
else
V_926 = V_925 = 0 ;
V_307 = F_684 ( V_277 , V_114 ? V_38 : NULL ) ;
if ( V_307 )
return V_307 ;
F_685 ( V_277 , V_114 ) ;
V_277 -> V_372 = 0 ;
V_277 -> V_373 = 0 ;
V_277 -> V_374 = V_926 ;
V_277 -> V_375 = V_925 ;
V_277 -> V_368 = V_317 << 16 ;
V_277 -> V_369 = V_318 << 16 ;
V_277 -> V_370 = V_926 << 16 ;
V_277 -> V_371 = V_925 << 16 ;
return 0 ;
}
bool F_686 ( struct V_46 * V_47 ,
struct V_563 * V_449 ,
struct V_1115 * V_1116 ,
struct V_742 * V_743 )
{
struct V_37 * V_37 ;
struct V_41 * V_41 =
F_687 ( V_47 ) ;
struct V_111 * V_1117 ;
struct V_747 * V_42 = & V_41 -> V_40 ;
struct V_111 * V_38 = NULL ;
struct V_15 * V_16 = V_42 -> V_16 ;
struct V_275 * V_114 ;
struct V_740 * V_115 = & V_16 -> V_741 ;
struct V_45 * V_36 = NULL ;
struct V_48 * V_49 ;
struct V_43 * V_44 ;
int V_307 , V_50 = - 1 ;
F_151 ( L_185 ,
V_47 -> V_40 . V_240 , V_47 -> V_8 ,
V_42 -> V_40 . V_240 , V_42 -> V_8 ) ;
V_485:
V_307 = F_688 ( & V_115 -> V_1118 , V_743 ) ;
if ( V_307 )
goto V_817;
if ( V_42 -> V_38 ) {
V_38 = V_42 -> V_38 ;
V_307 = F_688 ( & V_38 -> V_1119 , V_743 ) ;
if ( V_307 )
goto V_817;
V_307 = F_688 ( & V_38 -> V_113 -> V_1119 , V_743 ) ;
if ( V_307 )
goto V_817;
V_1116 -> V_1120 = V_47 -> V_1121 ;
V_1116 -> V_1122 = false ;
if ( V_47 -> V_1121 != V_1123 )
V_47 -> V_1124 -> V_1121 ( V_47 , V_1123 ) ;
return true ;
}
F_216 (dev, possible_crtc) {
V_50 ++ ;
if ( ! ( V_42 -> V_1125 & ( 1 << V_50 ) ) )
continue;
if ( V_1117 -> V_36 -> V_242 )
continue;
V_38 = V_1117 ;
break;
}
if ( ! V_38 ) {
F_151 ( L_186 ) ;
goto V_817;
}
V_307 = F_688 ( & V_38 -> V_1119 , V_743 ) ;
if ( V_307 )
goto V_817;
V_307 = F_688 ( & V_38 -> V_113 -> V_1119 , V_743 ) ;
if ( V_307 )
goto V_817;
V_37 = F_50 ( V_38 ) ;
V_1116 -> V_1120 = V_47 -> V_1121 ;
V_1116 -> V_1122 = true ;
V_1116 -> V_1126 = NULL ;
V_36 = F_482 ( V_16 ) ;
if ( ! V_36 )
return false ;
V_36 -> V_744 = V_743 ;
V_49 = F_689 ( V_36 , V_47 ) ;
if ( F_461 ( V_49 ) ) {
V_307 = F_462 ( V_49 ) ;
goto V_817;
}
V_49 -> V_38 = V_38 ;
V_49 -> V_52 = & V_41 -> V_40 ;
V_44 = F_460 ( V_36 , V_37 ) ;
if ( F_461 ( V_44 ) ) {
V_307 = F_462 ( V_44 ) ;
goto V_817;
}
V_44 -> V_40 . V_112 = V_44 -> V_40 . V_242 = true ;
if ( ! V_449 )
V_449 = & V_1127 ;
V_114 = F_679 ( V_16 , V_449 ) ;
if ( V_114 == NULL ) {
F_151 ( L_187 ) ;
V_114 = F_676 ( V_16 , V_449 , 24 , 32 ) ;
V_1116 -> V_1126 = V_114 ;
} else
F_151 ( L_188 ) ;
if ( F_461 ( V_114 ) ) {
F_151 ( L_189 ) ;
goto V_817;
}
V_307 = F_681 ( V_36 , V_38 , V_449 , V_114 , 0 , 0 ) ;
if ( V_307 )
goto V_817;
F_690 ( & V_44 -> V_40 . V_449 , V_449 ) ;
if ( F_485 ( V_36 ) ) {
F_151 ( L_190 ) ;
if ( V_1116 -> V_1126 )
V_1116 -> V_1126 -> V_1124 -> V_1128 ( V_1116 -> V_1126 ) ;
goto V_817;
}
V_38 -> V_113 -> V_38 = V_38 ;
F_306 ( V_16 , V_37 -> V_119 ) ;
return true ;
V_817:
F_486 ( V_36 ) ;
V_36 = NULL ;
if ( V_307 == - V_314 ) {
F_691 ( V_743 ) ;
goto V_485;
}
return false ;
}
void F_692 ( struct V_46 * V_47 ,
struct V_1115 * V_1116 ,
struct V_742 * V_743 )
{
struct V_15 * V_16 = V_47 -> V_16 ;
struct V_41 * V_41 =
F_687 ( V_47 ) ;
struct V_747 * V_42 = & V_41 -> V_40 ;
struct V_111 * V_38 = V_42 -> V_38 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_45 * V_36 ;
struct V_48 * V_49 ;
struct V_43 * V_44 ;
int V_307 ;
F_151 ( L_185 ,
V_47 -> V_40 . V_240 , V_47 -> V_8 ,
V_42 -> V_40 . V_240 , V_42 -> V_8 ) ;
if ( V_1116 -> V_1122 ) {
V_36 = F_482 ( V_16 ) ;
if ( ! V_36 )
goto V_817;
V_36 -> V_744 = V_743 ;
V_49 = F_689 ( V_36 , V_47 ) ;
if ( F_461 ( V_49 ) )
goto V_817;
V_44 = F_460 ( V_36 , V_37 ) ;
if ( F_461 ( V_44 ) )
goto V_817;
V_49 -> V_52 = NULL ;
V_49 -> V_38 = NULL ;
V_44 -> V_40 . V_242 = V_44 -> V_40 . V_112 = false ;
V_307 = F_681 ( V_36 , V_38 , NULL , NULL ,
0 , 0 ) ;
if ( V_307 )
goto V_817;
V_307 = F_485 ( V_36 ) ;
if ( V_307 )
goto V_817;
if ( V_1116 -> V_1126 ) {
F_693 ( V_1116 -> V_1126 ) ;
F_211 ( V_1116 -> V_1126 ) ;
}
return;
}
if ( V_1116 -> V_1120 != V_1123 )
V_47 -> V_1124 -> V_1121 ( V_47 , V_1116 -> V_1120 ) ;
return;
V_817:
F_151 ( L_191 ) ;
F_486 ( V_36 ) ;
}
static int F_694 ( struct V_15 * V_16 ,
const struct V_43 * V_211 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_87 = V_211 -> V_212 . V_87 ;
if ( ( V_87 & V_1129 ) == V_910 )
return V_2 -> V_835 . V_838 ;
else if ( F_10 ( V_16 ) )
return 120000 ;
else if ( ! F_33 ( V_16 ) )
return 96000 ;
else
return 48000 ;
}
static void F_591 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_119 = V_211 -> V_121 ;
T_1 V_87 = V_211 -> V_212 . V_87 ;
T_1 V_840 ;
T_4 clock ;
int V_872 ;
int V_53 = F_694 ( V_16 , V_211 ) ;
if ( ( V_87 & V_1130 ) == 0 )
V_840 = V_211 -> V_212 . V_736 ;
else
V_840 = V_211 -> V_212 . V_737 ;
clock . V_88 = ( V_840 & V_1131 ) >> V_1132 ;
if ( F_31 ( V_16 ) ) {
clock . V_84 = F_695 ( ( V_840 & V_1133 ) >> V_1134 ) - 1 ;
clock . V_80 = ( V_840 & V_1135 ) >> V_1136 ;
} else {
clock . V_84 = ( V_840 & V_1137 ) >> V_1134 ;
clock . V_80 = ( V_840 & V_1138 ) >> V_1136 ;
}
if ( ! F_33 ( V_16 ) ) {
if ( F_31 ( V_16 ) )
clock . V_82 = F_695 ( ( V_87 & V_1139 ) >>
V_900 ) ;
else
clock . V_82 = F_695 ( ( V_87 & V_1140 ) >>
V_901 ) ;
switch ( V_87 & V_1141 ) {
case V_897 :
clock . V_83 = V_87 & V_903 ?
5 : 10 ;
break;
case V_896 :
clock . V_83 = V_87 & V_904 ?
7 : 14 ;
break;
default:
F_151 ( L_192
L_193 , ( int ) ( V_87 & V_1141 ) ) ;
return;
}
if ( F_31 ( V_16 ) )
V_872 = F_34 ( V_53 , & clock ) ;
else
V_872 = F_36 ( V_53 , & clock ) ;
} else {
T_1 V_1142 = F_141 ( V_16 ) ? 0 : F_11 ( V_159 ) ;
bool V_996 = ( V_119 == 1 ) && ( V_1142 & V_194 ) ;
if ( V_996 ) {
clock . V_82 = F_695 ( ( V_87 & V_1143 ) >>
V_901 ) ;
if ( V_1142 & V_1144 )
clock . V_83 = 7 ;
else
clock . V_83 = 14 ;
} else {
if ( V_87 & V_912 )
clock . V_82 = 2 ;
else {
clock . V_82 = ( ( V_87 & V_1145 ) >>
V_901 ) + 2 ;
}
if ( V_87 & V_913 )
clock . V_83 = 4 ;
else
clock . V_83 = 2 ;
}
V_872 = F_36 ( V_53 , & clock ) ;
}
V_211 -> V_872 = V_872 ;
}
int F_696 ( int V_1146 ,
const struct V_827 * V_828 )
{
if ( ! V_828 -> V_833 )
return 0 ;
return F_48 ( ( V_1147 ) V_828 -> V_832 * V_1146 , V_828 -> V_833 ) ;
}
static void F_632 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
F_591 ( V_38 , V_211 ) ;
V_211 -> V_40 . V_116 . V_117 =
F_696 ( F_16 ( V_16 ) * 10000 ,
& V_211 -> V_603 ) ;
}
struct V_563 * F_697 ( struct V_15 * V_16 ,
struct V_111 * V_38 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
enum V_118 V_121 = V_37 -> V_115 -> V_121 ;
struct V_563 * V_449 ;
struct V_43 V_211 ;
int V_1148 = F_11 ( F_325 ( V_121 ) ) ;
int V_934 = F_11 ( F_329 ( V_121 ) ) ;
int V_1149 = F_11 ( F_331 ( V_121 ) ) ;
int V_1150 = F_11 ( F_335 ( V_121 ) ) ;
enum V_119 V_119 = V_37 -> V_119 ;
V_449 = F_491 ( sizeof( * V_449 ) , V_750 ) ;
if ( ! V_449 )
return NULL ;
V_211 . V_121 = (enum V_118 ) V_119 ;
V_211 . V_608 = 1 ;
V_211 . V_212 . V_87 = F_11 ( F_65 ( V_119 ) ) ;
V_211 . V_212 . V_736 = F_11 ( F_475 ( V_119 ) ) ;
V_211 . V_212 . V_737 = F_11 ( F_476 ( V_119 ) ) ;
F_591 ( V_37 , & V_211 ) ;
V_449 -> clock = V_211 . V_872 / V_211 . V_608 ;
V_449 -> V_926 = ( V_1148 & 0xffff ) + 1 ;
V_449 -> V_927 = ( ( V_1148 & 0xffff0000 ) >> 16 ) + 1 ;
V_449 -> V_928 = ( V_934 & 0xffff ) + 1 ;
V_449 -> V_929 = ( ( V_934 & 0xffff0000 ) >> 16 ) + 1 ;
V_449 -> V_925 = ( V_1149 & 0xffff ) + 1 ;
V_449 -> V_930 = ( ( V_1149 & 0xffff0000 ) >> 16 ) + 1 ;
V_449 -> V_931 = ( V_1150 & 0xffff ) + 1 ;
V_449 -> V_932 = ( ( V_1150 & 0xffff0000 ) >> 16 ) + 1 ;
F_583 ( V_449 ) ;
return V_449 ;
}
void F_698 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( V_2 -> V_310 . V_1151 )
return;
F_191 ( V_2 ) ;
F_699 ( V_2 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 6 )
F_700 ( V_2 ) ;
V_2 -> V_310 . V_1151 = true ;
}
void F_701 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! V_2 -> V_310 . V_1151 )
return;
V_2 -> V_310 . V_1151 = false ;
if ( F_60 ( V_16 ) -> V_127 >= 6 )
F_702 ( V_16 -> V_17 ) ;
F_195 ( V_2 ) ;
}
static void F_703 ( struct V_111 * V_38 )
{
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_501 * V_502 ;
F_272 ( & V_16 -> V_463 ) ;
V_502 = V_37 -> V_464 ;
V_37 -> V_464 = NULL ;
F_273 ( & V_16 -> V_463 ) ;
if ( V_502 ) {
F_704 ( & V_502 -> V_502 ) ;
F_215 ( V_502 ) ;
}
F_705 ( V_38 ) ;
F_215 ( V_37 ) ;
}
static void F_706 ( struct V_1152 * V_1153 )
{
struct V_501 * V_502 =
F_707 ( V_1153 , struct V_501 , V_502 ) ;
struct V_37 * V_38 = F_50 ( V_502 -> V_38 ) ;
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_299 * V_113 = V_38 -> V_40 . V_113 ;
F_2 ( & V_16 -> V_308 ) ;
F_197 ( V_502 -> V_458 , V_113 -> V_36 ) ;
F_209 ( & V_502 -> V_506 -> V_40 ) ;
if ( V_502 -> V_1154 )
F_708 ( & V_502 -> V_1154 , NULL ) ;
F_4 ( & V_16 -> V_308 ) ;
F_709 ( V_16 , F_214 ( V_113 ) -> V_378 ) ;
F_211 ( V_502 -> V_458 ) ;
F_126 ( F_281 ( & V_38 -> V_500 ) == 0 ) ;
F_710 ( & V_38 -> V_500 ) ;
F_215 ( V_502 ) ;
}
static void F_711 ( struct V_15 * V_16 ,
struct V_111 * V_38 )
{
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_501 * V_502 ;
unsigned long V_359 ;
if ( V_37 == NULL )
return;
F_712 ( & V_16 -> V_463 , V_359 ) ;
V_502 = V_37 -> V_464 ;
F_308 () ;
if ( V_502 == NULL || F_281 ( & V_502 -> V_460 ) < V_1155 ) {
F_713 ( & V_16 -> V_463 , V_359 ) ;
return;
}
F_307 ( V_37 ) ;
F_713 ( & V_16 -> V_463 , V_359 ) ;
}
void F_714 ( struct V_15 * V_16 , int V_119 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_111 * V_38 = V_2 -> V_120 [ V_119 ] ;
F_711 ( V_16 , V_38 ) ;
}
void F_261 ( struct V_15 * V_16 , int V_169 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_111 * V_38 = V_2 -> V_1156 [ V_169 ] ;
F_711 ( V_16 , V_38 ) ;
}
static bool F_715 ( T_1 V_1157 , T_1 V_1158 )
{
return ! ( ( V_1157 - V_1158 ) & 0x80000000 ) ;
}
static bool F_716 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_280 ( & V_2 -> V_461 ) ||
V_38 -> V_462 != F_281 ( & V_2 -> V_461 . V_462 ) )
return true ;
if ( F_60 ( V_16 ) -> V_127 < 5 && ! F_30 ( V_16 ) )
return true ;
return ( F_11 ( F_717 ( V_38 -> V_169 ) ) & ~ 0xfff ) ==
V_38 -> V_464 -> V_1159 &&
F_715 ( F_11 ( F_718 ( V_38 -> V_119 ) ) ,
V_38 -> V_464 -> V_1160 ) ;
}
void F_260 ( struct V_15 * V_16 , int V_169 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 =
F_50 ( V_2 -> V_1156 [ V_169 ] ) ;
unsigned long V_359 ;
F_712 ( & V_16 -> V_463 , V_359 ) ;
if ( V_37 -> V_464 && F_716 ( V_37 ) )
F_719 ( & V_37 -> V_464 -> V_460 ) ;
F_713 ( & V_16 -> V_463 , V_359 ) ;
}
static inline void F_720 ( struct V_501 * V_502 )
{
F_721 () ;
F_722 ( & V_502 -> V_460 , V_1161 ) ;
F_721 () ;
}
static int F_723 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_275 * V_114 ,
struct V_304 * V_305 ,
struct V_302 * V_1162 ,
T_2 V_359 )
{
struct V_300 * V_1163 = V_1162 -> V_1163 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_1 V_1164 ;
int V_307 ;
V_307 = F_724 ( V_1162 , 6 ) ;
if ( V_307 )
return V_307 ;
if ( V_37 -> V_169 )
V_1164 = V_1165 ;
else
V_1164 = V_1166 ;
F_725 ( V_1163 , V_1167 | V_1164 ) ;
F_725 ( V_1163 , V_1168 ) ;
F_725 ( V_1163 , V_1169 |
F_726 ( V_37 -> V_169 ) ) ;
F_725 ( V_1163 , V_114 -> V_286 [ 0 ] ) ;
F_725 ( V_1163 , V_37 -> V_464 -> V_1159 ) ;
F_725 ( V_1163 , 0 ) ;
F_720 ( V_37 -> V_464 ) ;
return 0 ;
}
static int F_727 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_275 * V_114 ,
struct V_304 * V_305 ,
struct V_302 * V_1162 ,
T_2 V_359 )
{
struct V_300 * V_1163 = V_1162 -> V_1163 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_1 V_1164 ;
int V_307 ;
V_307 = F_724 ( V_1162 , 6 ) ;
if ( V_307 )
return V_307 ;
if ( V_37 -> V_169 )
V_1164 = V_1165 ;
else
V_1164 = V_1166 ;
F_725 ( V_1163 , V_1167 | V_1164 ) ;
F_725 ( V_1163 , V_1168 ) ;
F_725 ( V_1163 , V_1170 |
F_726 ( V_37 -> V_169 ) ) ;
F_725 ( V_1163 , V_114 -> V_286 [ 0 ] ) ;
F_725 ( V_1163 , V_37 -> V_464 -> V_1159 ) ;
F_725 ( V_1163 , V_1168 ) ;
F_720 ( V_37 -> V_464 ) ;
return 0 ;
}
static int F_728 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_275 * V_114 ,
struct V_304 * V_305 ,
struct V_302 * V_1162 ,
T_2 V_359 )
{
struct V_300 * V_1163 = V_1162 -> V_1163 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_2 V_1171 , V_1172 ;
int V_307 ;
V_307 = F_724 ( V_1162 , 4 ) ;
if ( V_307 )
return V_307 ;
F_725 ( V_1163 , V_1169 |
F_726 ( V_37 -> V_169 ) ) ;
F_725 ( V_1163 , V_114 -> V_286 [ 0 ] ) ;
F_725 ( V_1163 , V_37 -> V_464 -> V_1159 |
V_305 -> V_319 ) ;
V_1171 = 0 ;
V_1172 = F_11 ( F_285 ( V_37 -> V_119 ) ) & 0x0fff0fff ;
F_725 ( V_1163 , V_1171 | V_1172 ) ;
F_720 ( V_37 -> V_464 ) ;
return 0 ;
}
static int F_729 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_275 * V_114 ,
struct V_304 * V_305 ,
struct V_302 * V_1162 ,
T_2 V_359 )
{
struct V_300 * V_1163 = V_1162 -> V_1163 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_2 V_1171 , V_1172 ;
int V_307 ;
V_307 = F_724 ( V_1162 , 4 ) ;
if ( V_307 )
return V_307 ;
F_725 ( V_1163 , V_1169 |
F_726 ( V_37 -> V_169 ) ) ;
F_725 ( V_1163 , V_114 -> V_286 [ 0 ] | V_305 -> V_319 ) ;
F_725 ( V_1163 , V_37 -> V_464 -> V_1159 ) ;
V_1171 = 0 ;
V_1172 = F_11 ( F_285 ( V_37 -> V_119 ) ) & 0x0fff0fff ;
F_725 ( V_1163 , V_1171 | V_1172 ) ;
F_720 ( V_37 -> V_464 ) ;
return 0 ;
}
static int F_730 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_275 * V_114 ,
struct V_304 * V_305 ,
struct V_302 * V_1162 ,
T_2 V_359 )
{
struct V_300 * V_1163 = V_1162 -> V_1163 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
T_2 V_1173 = 0 ;
int V_1174 , V_307 ;
switch ( V_37 -> V_169 ) {
case V_1175 :
V_1173 = V_1176 ;
break;
case V_386 :
V_1173 = V_1177 ;
break;
case V_1178 :
V_1173 = V_1179 ;
break;
default:
F_178 ( 1 , L_194 ) ;
return - V_1180 ;
}
V_1174 = 4 ;
if ( V_1163 -> V_240 == V_1181 ) {
V_1174 += 6 ;
if ( F_731 ( V_16 ) )
V_1174 += 2 ;
}
V_307 = F_732 ( V_1162 ) ;
if ( V_307 )
return V_307 ;
V_307 = F_724 ( V_1162 , V_1174 ) ;
if ( V_307 )
return V_307 ;
if ( V_1163 -> V_240 == V_1181 ) {
F_725 ( V_1163 , F_733 ( 1 ) ) ;
F_725 ( V_1163 , V_1182 ) ;
F_725 ( V_1163 , ~ ( V_1183 |
V_1184 |
V_1185 ) ) ;
if ( F_731 ( V_16 ) )
F_725 ( V_1163 , V_1186 |
V_1187 ) ;
else
F_725 ( V_1163 , V_1188 |
V_1187 ) ;
F_725 ( V_1163 , V_1182 ) ;
F_725 ( V_1163 , V_1163 -> V_1189 . V_1159 + 256 ) ;
if ( F_731 ( V_16 ) ) {
F_725 ( V_1163 , 0 ) ;
F_725 ( V_1163 , V_1168 ) ;
}
}
F_725 ( V_1163 , V_1170 | V_1173 ) ;
F_725 ( V_1163 , ( V_114 -> V_286 [ 0 ] | V_305 -> V_319 ) ) ;
F_725 ( V_1163 , V_37 -> V_464 -> V_1159 ) ;
F_725 ( V_1163 , ( V_1168 ) ) ;
F_720 ( V_37 -> V_464 ) ;
return 0 ;
}
static bool F_734 ( struct V_300 * V_1163 ,
struct V_304 * V_305 )
{
if ( V_1163 == NULL )
return true ;
if ( F_60 ( V_1163 -> V_16 ) -> V_127 < 5 )
return false ;
if ( V_761 . F_734 < 0 )
return false ;
else if ( V_761 . F_734 > 0 )
return true ;
else if ( V_761 . V_1190 )
return true ;
else
return V_1163 != F_735 ( V_305 -> V_1191 ) ;
}
static void F_736 ( struct V_37 * V_37 ,
struct V_501 * V_502 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_275 * V_114 = V_37 -> V_40 . V_113 -> V_114 ;
const enum V_119 V_119 = V_37 -> V_119 ;
T_1 V_1192 , V_357 ;
V_1192 = F_11 ( F_95 ( V_119 , 0 ) ) ;
V_1192 &= ~ V_1020 ;
switch ( V_114 -> V_290 [ 0 ] ) {
case V_268 :
break;
case V_269 :
V_1192 |= V_419 ;
break;
case V_270 :
V_1192 |= V_420 ;
break;
case V_271 :
V_1192 |= V_421 ;
break;
default:
F_179 ( V_114 -> V_290 [ 0 ] ) ;
}
V_357 = V_114 -> V_286 [ 0 ] /
F_237 ( V_16 , V_114 -> V_290 [ 0 ] ,
V_114 -> V_264 ) ;
F_128 ( F_95 ( V_119 , 0 ) , V_1192 ) ;
F_128 ( F_254 ( V_119 , 0 ) , V_357 ) ;
F_128 ( F_249 ( V_119 , 0 ) , V_502 -> V_1159 ) ;
F_129 ( F_249 ( V_119 , 0 ) ) ;
}
static void F_737 ( struct V_37 * V_37 ,
struct V_501 * V_502 )
{
struct V_15 * V_16 = V_37 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_957 * V_958 =
F_208 ( V_37 -> V_40 . V_113 -> V_114 ) ;
struct V_304 * V_305 = V_958 -> V_305 ;
T_1 V_380 ;
T_1 V_9 ;
V_9 = F_89 ( V_37 -> V_169 ) ;
V_380 = F_11 ( V_9 ) ;
if ( V_305 -> V_319 != V_321 )
V_380 |= V_387 ;
else
V_380 &= ~ V_387 ;
F_128 ( V_9 , V_380 ) ;
F_128 ( F_222 ( V_37 -> V_169 ) , V_502 -> V_1159 ) ;
F_129 ( F_222 ( V_37 -> V_169 ) ) ;
}
static void F_738 ( struct V_1193 * V_1194 )
{
struct V_37 * V_38 = V_1194 -> V_38 ;
struct V_501 * V_502 ;
F_272 ( & V_38 -> V_40 . V_16 -> V_463 ) ;
V_502 = V_38 -> V_464 ;
F_273 ( & V_38 -> V_40 . V_16 -> V_463 ) ;
if ( V_502 == NULL )
return;
F_720 ( V_502 ) ;
F_739 ( V_38 ) ;
if ( F_60 ( V_1194 -> V_761 ) -> V_127 >= 9 )
F_736 ( V_38 , V_502 ) ;
else
F_737 ( V_38 , V_502 ) ;
F_740 ( V_38 ) ;
}
static void F_741 ( struct V_1152 * V_502 )
{
struct V_1193 * V_1194 =
F_707 ( V_502 , struct V_1193 , V_502 ) ;
if ( V_1194 -> V_1162 ) {
F_9 ( F_742 ( V_1194 -> V_1162 ,
V_1194 -> V_38 -> V_462 ,
false , NULL ,
& V_1194 -> V_761 -> V_574 . V_1195 ) ) ;
F_743 ( V_1194 -> V_1162 ) ;
}
F_738 ( V_1194 ) ;
F_215 ( V_1194 ) ;
}
static int F_744 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_275 * V_114 ,
struct V_304 * V_305 ,
struct V_300 * V_1163 ,
T_2 V_359 )
{
struct V_1193 * V_1194 ;
V_1194 = F_745 ( sizeof( * V_1194 ) , V_750 ) ;
if ( V_1194 == NULL )
return - V_746 ;
V_1194 -> V_761 = F_203 ( V_16 ) ;
V_1194 -> V_1162 = F_746 ( V_305 -> V_1191 ) ;
V_1194 -> V_38 = F_50 ( V_38 ) ;
F_747 ( & V_1194 -> V_502 , F_741 ) ;
F_748 ( & V_1194 -> V_502 ) ;
return 0 ;
}
static int F_749 ( struct V_15 * V_16 ,
struct V_111 * V_38 ,
struct V_275 * V_114 ,
struct V_304 * V_305 ,
struct V_302 * V_1162 ,
T_2 V_359 )
{
return - V_1180 ;
}
static bool F_750 ( struct V_15 * V_16 ,
struct V_111 * V_38 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_501 * V_502 = V_37 -> V_464 ;
T_1 V_1196 ;
if ( F_281 ( & V_502 -> V_460 ) >= V_1155 )
return true ;
if ( F_281 ( & V_502 -> V_460 ) < V_1161 )
return false ;
if ( ! V_502 -> V_1197 )
return false ;
if ( V_502 -> V_1198 == 0 ) {
if ( V_502 -> V_1154 &&
! F_751 ( V_502 -> V_1154 , true ) )
return false ;
V_502 -> V_1198 = F_752 ( V_38 ) ;
}
if ( F_752 ( V_38 ) - V_502 -> V_1198 < 3 )
return false ;
if ( F_60 ( V_16 ) -> V_127 >= 4 )
V_1196 = F_753 ( F_11 ( F_222 ( V_37 -> V_169 ) ) ) ;
else
V_1196 = F_11 ( F_223 ( V_37 -> V_169 ) ) ;
return V_1196 == V_502 -> V_1159 ;
}
void F_754 ( struct V_15 * V_16 , int V_119 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_111 * V_38 = V_2 -> V_120 [ V_119 ] ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_501 * V_502 ;
F_9 ( ! F_755 () ) ;
if ( V_38 == NULL )
return;
F_756 ( & V_16 -> V_463 ) ;
V_502 = V_37 -> V_464 ;
if ( V_502 != NULL && F_750 ( V_16 , V_38 ) ) {
F_178 ( 1 , L_195 ,
V_502 -> V_1199 , F_757 ( V_16 , V_119 ) ) ;
F_307 ( V_37 ) ;
V_502 = NULL ;
}
if ( V_502 != NULL &&
F_757 ( V_16 , V_119 ) - V_502 -> V_1199 > 1 )
F_758 ( V_16 , V_502 -> V_1154 ) ;
F_759 ( & V_16 -> V_463 ) ;
}
static int F_760 ( struct V_111 * V_38 ,
struct V_275 * V_114 ,
struct V_1200 * V_503 ,
T_2 V_1201 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_275 * V_458 = V_38 -> V_113 -> V_114 ;
struct V_304 * V_305 = F_189 ( V_114 ) ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_299 * V_113 = V_38 -> V_113 ;
enum V_119 V_119 = V_37 -> V_119 ;
struct V_501 * V_502 ;
struct V_300 * V_1163 ;
bool V_1194 ;
struct V_302 * V_1202 = NULL ;
int V_307 ;
if ( F_9 ( F_189 ( V_458 ) == NULL ) )
return - V_315 ;
if ( V_114 -> V_264 != V_38 -> V_113 -> V_114 -> V_264 )
return - V_309 ;
if ( F_60 ( V_16 ) -> V_127 > 3 &&
( V_114 -> V_288 [ 0 ] != V_38 -> V_113 -> V_114 -> V_288 [ 0 ] ||
V_114 -> V_286 [ 0 ] != V_38 -> V_113 -> V_114 -> V_286 [ 0 ] ) )
return - V_309 ;
if ( F_761 ( & V_2 -> V_461 ) )
goto V_1203;
V_502 = F_491 ( sizeof( * V_502 ) , V_750 ) ;
if ( V_502 == NULL )
return - V_746 ;
V_502 -> V_503 = V_503 ;
V_502 -> V_38 = V_38 ;
V_502 -> V_458 = V_458 ;
F_747 ( & V_502 -> V_502 , F_706 ) ;
V_307 = F_102 ( V_38 ) ;
if ( V_307 )
goto V_1204;
F_272 ( & V_16 -> V_463 ) ;
if ( V_37 -> V_464 ) {
if ( F_750 ( V_16 , V_38 ) ) {
F_15 ( L_196 ) ;
F_307 ( V_37 ) ;
} else {
F_15 ( L_197 ) ;
F_273 ( & V_16 -> V_463 ) ;
F_103 ( V_38 ) ;
F_215 ( V_502 ) ;
return - V_315 ;
}
}
V_37 -> V_464 = V_502 ;
F_273 ( & V_16 -> V_463 ) ;
if ( F_281 ( & V_37 -> V_500 ) >= 2 )
F_762 ( V_2 -> V_505 ) ;
F_212 ( V_502 -> V_458 ) ;
F_763 ( & V_305 -> V_40 ) ;
V_38 -> V_113 -> V_114 = V_114 ;
F_210 ( V_38 -> V_113 ) ;
V_502 -> V_506 = V_305 ;
V_307 = F_672 ( V_16 ) ;
if ( V_307 )
goto V_1205;
F_764 ( & V_37 -> V_500 ) ;
V_37 -> V_462 = F_281 ( & V_2 -> V_461 . V_462 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 5 || F_30 ( V_16 ) )
V_502 -> V_1160 = F_11 ( F_718 ( V_119 ) ) + 1 ;
if ( F_13 ( V_16 ) ) {
V_1163 = & V_2 -> V_1163 [ V_1206 ] ;
if ( V_305 -> V_319 != F_189 ( V_502 -> V_458 ) -> V_319 )
V_1163 = NULL ;
} else if ( F_290 ( V_16 ) || F_234 ( V_16 ) ) {
V_1163 = & V_2 -> V_1163 [ V_1206 ] ;
} else if ( F_60 ( V_16 ) -> V_127 >= 7 ) {
V_1163 = F_735 ( V_305 -> V_1191 ) ;
if ( V_1163 == NULL || V_1163 -> V_240 != V_1181 )
V_1163 = & V_2 -> V_1163 [ V_1206 ] ;
} else {
V_1163 = & V_2 -> V_1163 [ V_1181 ] ;
}
V_1194 = F_734 ( V_1163 , V_305 ) ;
V_307 = F_188 ( V_38 -> V_113 , V_114 ,
V_38 -> V_113 -> V_36 ,
V_1194 ? F_735 ( V_305 -> V_1191 ) : V_1163 , & V_1202 ) ;
if ( V_307 )
goto V_1207;
V_502 -> V_1159 = F_238 ( F_214 ( V_113 ) ,
V_305 , 0 ) ;
V_502 -> V_1159 += V_37 -> V_389 ;
if ( V_1194 ) {
V_307 = F_744 ( V_16 , V_38 , V_114 , V_305 , V_1163 ,
V_1201 ) ;
if ( V_307 )
goto V_1208;
F_708 ( & V_502 -> V_1154 ,
V_305 -> V_1191 ) ;
} else {
if ( ! V_1202 ) {
V_307 = F_765 ( V_1163 , V_1163 -> V_1209 , & V_1202 ) ;
if ( V_307 )
goto V_1208;
}
V_307 = V_2 -> V_453 . V_1210 ( V_16 , V_38 , V_114 , V_305 , V_1202 ,
V_1201 ) ;
if ( V_307 )
goto V_1208;
F_708 ( & V_502 -> V_1154 , V_1202 ) ;
}
if ( V_1202 )
F_766 ( V_1202 ) ;
V_502 -> V_1199 = F_752 ( V_38 ) ;
V_502 -> V_1197 = true ;
F_384 ( F_189 ( V_502 -> V_458 ) , V_305 ,
F_214 ( V_113 ) -> V_378 ) ;
F_4 ( & V_16 -> V_308 ) ;
F_385 ( V_37 ) ;
F_767 ( V_16 ,
F_214 ( V_113 ) -> V_378 ) ;
F_768 ( V_37 -> V_169 , V_305 ) ;
return 0 ;
V_1208:
F_197 ( V_114 , V_38 -> V_113 -> V_36 ) ;
V_1207:
if ( V_1202 )
F_769 ( V_1202 ) ;
F_710 ( & V_37 -> V_500 ) ;
F_4 ( & V_16 -> V_308 ) ;
V_1205:
V_38 -> V_113 -> V_114 = V_458 ;
F_210 ( V_38 -> V_113 ) ;
F_770 ( & V_305 -> V_40 ) ;
F_211 ( V_502 -> V_458 ) ;
F_272 ( & V_16 -> V_463 ) ;
V_37 -> V_464 = NULL ;
F_273 ( & V_16 -> V_463 ) ;
F_103 ( V_38 ) ;
V_1204:
F_215 ( V_502 ) ;
if ( V_307 == - V_1211 ) {
struct V_45 * V_36 ;
struct V_276 * V_277 ;
V_1203:
V_36 = F_482 ( V_16 ) ;
if ( ! V_36 )
return - V_746 ;
V_36 -> V_744 = F_771 ( V_38 ) ;
V_485:
V_277 = F_682 ( V_36 , V_113 ) ;
V_307 = F_484 ( V_277 ) ;
if ( ! V_307 ) {
F_685 ( V_277 , V_114 ) ;
V_307 = F_684 ( V_277 , V_38 ) ;
if ( ! V_307 )
V_307 = F_485 ( V_36 ) ;
}
if ( V_307 == - V_314 ) {
F_691 ( V_36 -> V_744 ) ;
F_772 ( V_36 ) ;
goto V_485;
}
if ( V_307 )
F_486 ( V_36 ) ;
if ( V_307 == 0 && V_503 ) {
F_272 ( & V_16 -> V_463 ) ;
F_309 ( V_16 , V_119 , V_503 ) ;
F_273 ( & V_16 -> V_463 ) ;
}
}
return V_307 ;
}
static bool F_773 ( struct V_299 * V_169 ,
struct V_276 * V_36 )
{
if ( ! V_169 -> V_36 -> V_114 || ! V_36 -> V_114 ||
V_169 -> V_36 -> V_114 -> V_290 [ 0 ] != V_36 -> V_114 -> V_290 [ 0 ] ||
V_169 -> V_36 -> V_283 != V_36 -> V_283 )
return true ;
if ( V_169 -> V_36 -> V_374 != V_36 -> V_374 )
return true ;
return false ;
}
int F_774 ( struct V_35 * V_44 ,
struct V_276 * V_277 )
{
struct V_111 * V_38 = V_44 -> V_38 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_299 * V_169 = V_277 -> V_169 ;
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_435 * V_1212 =
F_218 ( V_169 -> V_36 ) ;
int V_1213 = V_37 -> V_40 . V_40 . V_240 , V_307 ;
int V_50 = F_219 ( V_169 ) ;
bool V_1214 = F_18 ( V_44 ) ;
bool V_1215 = V_38 -> V_36 -> V_112 ;
bool V_1216 = V_44 -> V_112 ;
bool V_1217 , V_1218 , V_365 , V_1219 ;
struct V_275 * V_114 = V_277 -> V_114 ;
if ( V_44 && F_60 ( V_16 ) -> V_127 >= 9 &&
V_169 -> type != V_1220 ) {
V_307 = F_356 (
F_283 ( V_44 ) ,
F_218 ( V_277 ) ) ;
if ( V_307 )
return V_307 ;
}
if ( V_1212 -> V_40 . V_114 && ! V_114 )
V_37 -> V_591 . V_1221 |= 1 << V_50 ;
V_1219 = V_1212 -> V_365 ;
V_365 = F_218 ( V_277 ) -> V_365 ;
if ( ! V_1215 && F_9 ( V_1219 ) )
V_1219 = false ;
if ( ! V_1216 && F_9 ( V_365 ) )
V_365 = false ;
if ( ! V_1219 && ! V_365 )
return 0 ;
V_1217 = V_1219 && ( ! V_365 || V_1214 ) ;
V_1218 = V_365 && ( ! V_1219 || V_1214 ) ;
F_775 ( L_198 , V_1213 ,
V_169 -> V_40 . V_240 , V_114 ? V_114 -> V_40 . V_240 : - 1 ) ;
F_775 ( L_199 ,
V_169 -> V_40 . V_240 , V_1219 , V_365 ,
V_1217 , V_1218 , V_1214 ) ;
if ( V_1218 ) {
V_37 -> V_591 . V_1222 = true ;
if ( V_169 -> type != V_1220 ) {
V_37 -> V_591 . V_594 = true ;
V_37 -> V_591 . V_592 = true ;
V_37 -> V_591 . V_596 = true ;
}
} else if ( V_1217 ) {
V_37 -> V_591 . V_596 = true ;
if ( V_169 -> type != V_1220 ) {
if ( V_1216 )
V_37 -> V_591 . V_592 = true ;
V_37 -> V_591 . V_594 = true ;
}
} else if ( F_773 ( V_169 , V_277 ) ) {
V_37 -> V_591 . V_1222 = true ;
}
if ( V_365 || V_1219 )
V_37 -> V_591 . V_593 |=
F_214 ( V_169 ) -> V_378 ;
switch ( V_169 -> type ) {
case V_1223 :
V_37 -> V_591 . V_599 = true ;
V_37 -> V_591 . V_601 = V_1217 ;
V_37 -> V_591 . V_598 = V_1218 ;
if ( V_1217 ) {
V_37 -> V_591 . V_600 = true ;
V_37 -> V_591 . V_452 = true ;
}
if ( V_365 &&
F_60 ( V_16 ) -> V_127 <= 4 && ! F_30 ( V_16 ) &&
V_2 -> V_451 . V_38 == V_37 &&
V_277 -> V_283 != F_229 ( V_422 ) )
V_37 -> V_591 . V_452 = true ;
if ( V_1218 && F_235 ( V_16 ) )
V_37 -> V_591 . V_592 = true ;
V_37 -> V_591 . V_597 |= V_365 || V_1214 ;
break;
case V_1220 :
break;
case V_1224 :
if ( V_1217 && ! V_1214 ) {
V_37 -> V_591 . V_592 = true ;
V_37 -> V_591 . V_1225 |=
1 << V_50 ;
}
}
return 0 ;
}
static bool F_776 ( const struct V_41 * V_1157 ,
const struct V_41 * V_1158 )
{
return V_1157 == V_1158 || ( V_1157 -> V_1226 & ( 1 << V_1158 -> type ) &&
V_1158 -> V_1226 & ( 1 << V_1157 -> type ) ) ;
}
static bool F_777 ( struct V_45 * V_36 ,
struct V_37 * V_38 ,
struct V_41 * V_42 )
{
struct V_41 * V_1227 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_50 ;
F_23 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != & V_38 -> V_40 )
continue;
V_1227 =
F_24 ( V_49 -> V_52 ) ;
if ( ! F_776 ( V_42 , V_1227 ) )
return false ;
}
return true ;
}
static bool F_778 ( struct V_45 * V_36 ,
struct V_37 * V_38 )
{
struct V_41 * V_42 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_50 ;
F_23 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != & V_38 -> V_40 )
continue;
V_42 = F_24 ( V_49 -> V_52 ) ;
if ( ! F_777 ( V_36 , V_38 , V_42 ) )
return false ;
}
return true ;
}
static int F_779 ( struct V_111 * V_38 ,
struct V_35 * V_44 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_43 * V_211 =
F_283 ( V_44 ) ;
struct V_45 * V_36 = V_44 -> V_36 ;
int V_307 ;
bool V_1214 = F_18 ( V_44 ) ;
if ( V_1214 && ! F_778 ( V_36 , V_37 ) ) {
F_151 ( L_200 ) ;
return - V_309 ;
}
if ( V_1214 && ! V_44 -> V_112 )
V_37 -> V_591 . V_596 = true ;
if ( V_1214 && V_44 -> V_242 &&
V_2 -> V_453 . V_1228 &&
! F_9 ( V_211 -> V_135 != V_965 ) ) {
V_307 = V_2 -> V_453 . V_1228 ( V_37 ,
V_211 ) ;
if ( V_307 )
return V_307 ;
}
V_307 = 0 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
if ( V_1214 )
V_307 = F_355 ( V_211 ) ;
if ( ! V_307 )
V_307 = F_780 ( V_16 , V_37 ,
V_211 ) ;
}
return V_307 ;
}
static void F_781 ( struct V_15 * V_16 )
{
struct V_748 * V_47 ;
F_782 (dev, connector) {
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
F_783 ( struct V_748 * V_47 ,
struct V_43 * V_211 )
{
int V_1010 = V_211 -> V_758 ;
F_151 ( L_201 ,
V_47 -> V_40 . V_40 . V_240 ,
V_47 -> V_40 . V_8 ) ;
if ( V_47 -> V_40 . V_1229 . V_537 &&
V_47 -> V_40 . V_1229 . V_537 * 3 < V_1010 ) {
F_151 ( L_202 ,
V_1010 , V_47 -> V_40 . V_1229 . V_537 * 3 ) ;
V_211 -> V_758 = V_47 -> V_40 . V_1229 . V_537 * 3 ;
}
if ( V_47 -> V_40 . V_1229 . V_537 == 0 && V_1010 > 24 ) {
F_151 ( L_203 ,
V_1010 ) ;
V_211 -> V_758 = 24 ;
}
}
static int
F_784 ( struct V_37 * V_38 ,
struct V_43 * V_211 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_45 * V_36 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_1010 , V_50 ;
if ( ( F_30 ( V_16 ) || F_13 ( V_16 ) ) )
V_1010 = 10 * 3 ;
else if ( F_60 ( V_16 ) -> V_127 >= 5 )
V_1010 = 12 * 3 ;
else
V_1010 = 8 * 3 ;
V_211 -> V_758 = V_1010 ;
V_36 = V_211 -> V_40 . V_36 ;
F_23 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != & V_38 -> V_40 )
continue;
F_783 ( F_785 ( V_47 ) ,
V_211 ) ;
}
return V_1010 ;
}
static void F_786 ( const struct V_563 * V_449 )
{
F_151 ( L_204
L_205 ,
V_449 -> V_117 ,
V_449 -> V_565 , V_449 -> V_764 ,
V_449 -> V_921 , V_449 -> V_918 ,
V_449 -> V_566 , V_449 -> V_923 ,
V_449 -> V_924 , V_449 -> V_914 , V_449 -> type , V_449 -> V_359 ) ;
}
static void F_787 ( struct V_37 * V_38 ,
struct V_43 * V_211 ,
const char * V_1230 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_299 * V_169 ;
struct V_363 * V_363 ;
struct V_435 * V_36 ;
struct V_275 * V_114 ;
F_151 ( L_206 , V_38 -> V_40 . V_40 . V_240 ,
V_1230 , V_211 , F_80 ( V_38 -> V_119 ) ) ;
F_151 ( L_207 , F_788 ( V_211 -> V_121 ) ) ;
F_151 ( L_208 ,
V_211 -> V_758 , V_211 -> V_937 ) ;
F_151 ( L_209 ,
V_211 -> V_260 ,
V_211 -> V_480 ,
V_211 -> V_603 . V_830 , V_211 -> V_603 . V_831 ,
V_211 -> V_603 . V_832 , V_211 -> V_603 . V_833 ,
V_211 -> V_603 . V_829 ) ;
F_151 ( L_210 ,
V_211 -> V_536 ,
V_211 -> V_1231 ,
V_211 -> V_848 . V_830 , V_211 -> V_848 . V_831 ,
V_211 -> V_848 . V_832 , V_211 -> V_848 . V_833 ,
V_211 -> V_848 . V_829 ) ;
F_151 ( L_211 ,
V_211 -> V_536 ,
V_211 -> V_1231 ,
V_211 -> V_849 . V_830 ,
V_211 -> V_849 . V_831 ,
V_211 -> V_849 . V_832 ,
V_211 -> V_849 . V_833 ,
V_211 -> V_849 . V_829 ) ;
F_151 ( L_212 ,
V_211 -> V_1232 ,
V_211 -> V_1233 ) ;
F_151 ( L_213 ) ;
F_789 ( & V_211 -> V_40 . V_449 ) ;
F_151 ( L_214 ) ;
F_789 ( & V_211 -> V_40 . V_116 ) ;
F_786 ( & V_211 -> V_40 . V_116 ) ;
F_151 ( L_215 , V_211 -> V_872 ) ;
F_151 ( L_216 ,
V_211 -> V_385 , V_211 -> V_384 ) ;
F_151 ( L_217 ,
V_38 -> V_404 ,
V_211 -> V_403 . V_554 ,
V_211 -> V_403 . V_440 ) ;
F_151 ( L_218 ,
V_211 -> V_615 . V_616 ,
V_211 -> V_615 . V_620 ,
V_211 -> V_615 . V_953 ) ;
F_151 ( L_219 ,
V_211 -> V_466 . V_570 ,
V_211 -> V_466 . V_294 ,
V_211 -> V_466 . V_129 ? L_220 : L_221 ) ;
F_151 ( L_222 , V_211 -> V_573 ) ;
F_151 ( L_223 , V_211 -> V_261 ) ;
if ( F_29 ( V_16 ) ) {
F_151 ( L_224
L_225
L_226 ,
V_211 -> V_1065 ,
V_211 -> V_212 . V_1234 ,
V_211 -> V_212 . V_1235 ,
V_211 -> V_212 . V_1236 ,
V_211 -> V_212 . V_1237 ,
V_211 -> V_212 . V_1238 ,
V_211 -> V_212 . V_1239 ,
V_211 -> V_212 . V_1240 ,
V_211 -> V_212 . V_1241 ,
V_211 -> V_212 . V_1242 ,
V_211 -> V_212 . V_1243 ,
V_211 -> V_212 . V_1244 ) ;
} else if ( F_428 ( V_16 ) ) {
F_151 ( L_227
L_228 ,
V_211 -> V_1065 ,
V_211 -> V_212 . V_1073 ,
V_211 -> V_212 . V_1245 ,
V_211 -> V_212 . V_1246 ) ;
} else if ( F_71 ( V_16 ) ) {
F_151 ( L_229 ,
V_211 -> V_1065 ,
V_211 -> V_212 . V_1247 ,
V_211 -> V_212 . V_1248 ) ;
} else {
F_151 ( L_230
L_231 ,
V_211 -> V_212 . V_87 ,
V_211 -> V_212 . V_214 ,
V_211 -> V_212 . V_736 ,
V_211 -> V_212 . V_737 ) ;
}
F_151 ( L_232 ) ;
F_790 (plane, &dev->mode_config.plane_list, head) {
V_363 = F_214 ( V_169 ) ;
if ( V_363 -> V_119 != V_38 -> V_119 )
continue;
V_36 = F_218 ( V_169 -> V_36 ) ;
V_114 = V_36 -> V_40 . V_114 ;
if ( ! V_114 ) {
F_151 ( L_233
L_234 ,
V_169 -> type == V_1220 ? L_235 : L_236 ,
V_169 -> V_40 . V_240 , V_363 -> V_119 ,
( V_38 -> V_40 . V_113 == V_169 ) ? 0 : V_363 -> V_169 + 1 ,
F_219 ( V_169 ) , V_36 -> V_440 ) ;
continue;
}
F_151 ( L_237 ,
V_169 -> type == V_1220 ? L_235 : L_236 ,
V_169 -> V_40 . V_240 , V_363 -> V_119 ,
V_38 -> V_40 . V_113 == V_169 ? 0 : V_363 -> V_169 + 1 ,
F_219 ( V_169 ) ) ;
F_151 ( L_238 ,
V_114 -> V_40 . V_240 , V_114 -> V_358 , V_114 -> V_272 , V_114 -> V_264 ) ;
F_151 ( L_239 ,
V_36 -> V_440 ,
V_36 -> V_444 . V_445 >> 16 , V_36 -> V_444 . y1 >> 16 ,
F_250 ( & V_36 -> V_444 ) >> 16 ,
F_251 ( & V_36 -> V_444 ) >> 16 ,
V_36 -> V_446 . V_445 , V_36 -> V_446 . y1 ,
F_250 ( & V_36 -> V_446 ) , F_251 ( & V_36 -> V_446 ) ) ;
}
}
static bool F_791 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_46 * V_47 ;
unsigned int V_1249 = 0 ;
F_792 (connector, dev) {
struct V_48 * V_49 ;
struct V_41 * V_42 ;
V_49 = F_793 ( V_36 , V_47 ) ;
if ( ! V_49 )
V_49 = V_47 -> V_36 ;
if ( ! V_49 -> V_52 )
continue;
V_42 = F_24 ( V_49 -> V_52 ) ;
F_9 ( ! V_49 -> V_38 ) ;
switch ( V_42 -> type ) {
unsigned int V_228 ;
case V_634 :
if ( F_9 ( ! F_71 ( V_16 ) ) )
break;
case V_635 :
case V_63 :
case V_636 :
V_228 = 1 << F_350 ( & V_42 -> V_40 ) -> V_216 ;
if ( V_1249 & V_228 )
return false ;
V_1249 |= V_228 ;
default:
break;
}
}
return true ;
}
static void
F_794 ( struct V_43 * V_44 )
{
struct V_35 V_1250 ;
struct V_402 V_403 ;
struct V_138 V_212 ;
enum V_546 V_135 ;
T_2 V_1065 ;
bool V_641 ;
V_1250 = V_44 -> V_40 ;
V_403 = V_44 -> V_403 ;
V_135 = V_44 -> V_135 ;
V_212 = V_44 -> V_212 ;
V_1065 = V_44 -> V_1065 ;
V_641 = V_44 -> V_466 . V_641 ;
memset ( V_44 , 0 , sizeof *V_44 ) ;
V_44 -> V_40 = V_1250 ;
V_44 -> V_403 = V_403 ;
V_44 -> V_135 = V_135 ;
V_44 -> V_212 = V_212 ;
V_44 -> V_1065 = V_1065 ;
V_44 -> V_466 . V_641 = V_641 ;
}
static int
F_795 ( struct V_111 * V_38 ,
struct V_43 * V_211 )
{
struct V_45 * V_36 = V_211 -> V_40 . V_36 ;
struct V_41 * V_42 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_1251 , V_307 = - V_309 ;
int V_50 ;
bool V_485 = true ;
F_794 ( V_211 ) ;
V_211 -> V_121 =
(enum V_118 ) F_50 ( V_38 ) -> V_119 ;
if ( ! ( V_211 -> V_40 . V_116 . V_359 &
( V_541 | V_1252 ) ) )
V_211 -> V_40 . V_116 . V_359 |= V_1252 ;
if ( ! ( V_211 -> V_40 . V_116 . V_359 &
( V_543 | V_1253 ) ) )
V_211 -> V_40 . V_116 . V_359 |= V_1253 ;
V_1251 = F_784 ( F_50 ( V_38 ) ,
V_211 ) ;
if ( V_1251 < 0 )
goto V_817;
F_683 ( & V_211 -> V_40 . V_449 ,
& V_211 -> V_385 ,
& V_211 -> V_384 ) ;
V_1254:
V_211 -> V_872 = 0 ;
V_211 -> V_608 = 1 ;
F_796 ( & V_211 -> V_40 . V_116 ,
V_1255 ) ;
F_23 (state, connector, connector_state, i) {
if ( V_49 -> V_38 != V_38 )
continue;
V_42 = F_24 ( V_49 -> V_52 ) ;
if ( ! ( V_42 -> V_1256 ( V_42 , V_211 ) ) ) {
F_151 ( L_240 ) ;
goto V_817;
}
}
if ( ! V_211 -> V_872 )
V_211 -> V_872 = V_211 -> V_40 . V_116 . V_117
* V_211 -> V_608 ;
V_307 = F_505 ( F_50 ( V_38 ) , V_211 ) ;
if ( V_307 < 0 ) {
F_151 ( L_241 ) ;
goto V_817;
}
if ( V_307 == V_760 ) {
if ( F_6 ( ! V_485 , L_242 ) ) {
V_307 = - V_309 ;
goto V_817;
}
F_151 ( L_243 ) ;
V_485 = false ;
goto V_1254;
}
V_211 -> V_937 = V_211 -> V_758 == 6 * 3 ;
F_151 ( L_244 ,
V_1251 , V_211 -> V_758 , V_211 -> V_937 ) ;
V_817:
return V_307 ;
}
static void
F_797 ( struct V_45 * V_36 )
{
struct V_111 * V_38 ;
struct V_35 * V_44 ;
int V_50 ;
F_425 (state, crtc, crtc_state, i) {
F_50 ( V_38 ) -> V_115 = F_283 ( V_38 -> V_36 ) ;
if ( V_38 -> V_36 -> V_112 )
V_38 -> V_1257 = V_38 -> V_36 -> V_116 ;
else
V_38 -> V_1257 . V_117 = 0 ;
}
}
static bool F_798 ( int V_1258 , int V_1259 )
{
int V_1260 ;
if ( V_1258 == V_1259 )
return true ;
if ( ! V_1258 || ! V_1259 )
return false ;
V_1260 = abs ( V_1258 - V_1259 ) ;
if ( ( ( ( ( V_1260 + V_1258 + V_1259 ) * 100 ) ) / ( V_1258 + V_1259 ) ) < 105 )
return true ;
return false ;
}
static bool
F_799 ( unsigned int V_79 , unsigned int V_84 ,
unsigned int V_80 , unsigned int V_1261 ,
bool V_1262 )
{
if ( V_79 == V_80 && V_84 == V_1261 )
return true ;
if ( V_1262 || ! V_79 || ! V_84 || ! V_80 || ! V_1261 )
return false ;
F_800 ( V_821 > V_109 ) ;
if ( V_79 > V_80 ) {
while ( V_79 > V_80 ) {
V_80 <<= 1 ;
V_1261 <<= 1 ;
}
} else if ( V_79 < V_80 ) {
while ( V_79 < V_80 ) {
V_79 <<= 1 ;
V_84 <<= 1 ;
}
}
return V_79 == V_80 && V_84 == V_1261 ;
}
static bool
F_801 ( const struct V_827 * V_828 ,
struct V_827 * V_845 ,
bool V_1263 )
{
if ( V_828 -> V_829 == V_845 -> V_829 &&
F_799 ( V_828 -> V_830 , V_828 -> V_831 ,
V_845 -> V_830 , V_845 -> V_831 , ! V_1263 ) &&
F_799 ( V_828 -> V_832 , V_828 -> V_833 ,
V_845 -> V_832 , V_845 -> V_833 , ! V_1263 ) ) {
if ( V_1263 )
* V_845 = * V_828 ;
return true ;
}
return false ;
}
static bool
F_802 ( struct V_15 * V_16 ,
struct V_43 * V_1264 ,
struct V_43 * V_211 ,
bool V_1263 )
{
bool V_307 = true ;
#define F_803 ( T_8 , ... ) \
do { \
if (!adjust) \
DRM_ERROR(fmt, ##__VA_ARGS__); \
else \
DRM_DEBUG_KMS(fmt, ##__VA_ARGS__); \
} while (0)
#define F_804 ( V_8 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_805 ( V_8 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_806 ( V_8 ) \
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
#define F_807 ( V_8 , T_9 ) \
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
#define F_808 ( V_8 , T_9 ) \
if ((current_config->name != pipe_config->name) && \
(current_config->alt_name != pipe_config->name)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i or %i, found %i)\n", \
current_config->name, \
current_config->alt_name, \
pipe_config->name); \
ret = false; \
}
#define F_809 ( V_8 , V_640 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
ret = false; \
}
#define F_810 ( V_8 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_811 ( T_10 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_805 ( V_121 ) ;
F_805 ( V_260 ) ;
F_805 ( V_480 ) ;
F_806 ( V_603 ) ;
F_805 ( V_536 ) ;
F_805 ( V_1231 ) ;
if ( F_60 ( V_16 ) -> V_127 < 8 ) {
F_806 ( V_848 ) ;
if ( V_1264 -> V_846 )
F_806 ( V_849 ) ;
} else
F_807 ( V_848 , V_849 ) ;
F_805 ( V_40 . V_116 . V_565 ) ;
F_805 ( V_40 . V_116 . V_918 ) ;
F_805 ( V_40 . V_116 . V_919 ) ;
F_805 ( V_40 . V_116 . V_920 ) ;
F_805 ( V_40 . V_116 . V_764 ) ;
F_805 ( V_40 . V_116 . V_921 ) ;
F_805 ( V_40 . V_116 . V_566 ) ;
F_805 ( V_40 . V_116 . V_914 ) ;
F_805 ( V_40 . V_116 . V_922 ) ;
F_805 ( V_40 . V_116 . V_915 ) ;
F_805 ( V_40 . V_116 . V_923 ) ;
F_805 ( V_40 . V_116 . V_924 ) ;
F_805 ( V_608 ) ;
F_805 ( V_1265 ) ;
if ( ( F_60 ( V_16 ) -> V_127 < 8 && ! F_234 ( V_16 ) ) ||
F_13 ( V_16 ) )
F_805 ( V_946 ) ;
F_805 ( V_1233 ) ;
F_805 ( V_1232 ) ;
F_809 ( V_40 . V_116 . V_359 ,
V_917 ) ;
if ( ! F_811 ( V_1266 ) ) {
F_809 ( V_40 . V_116 . V_359 ,
V_541 ) ;
F_809 ( V_40 . V_116 . V_359 ,
V_1252 ) ;
F_809 ( V_40 . V_116 . V_359 ,
V_543 ) ;
F_809 ( V_40 . V_116 . V_359 ,
V_1253 ) ;
}
F_804 ( V_615 . V_616 ) ;
if ( F_60 ( V_16 ) -> V_127 < 4 )
F_805 ( V_615 . V_620 ) ;
F_804 ( V_615 . V_953 ) ;
if ( ! V_1263 ) {
F_805 ( V_385 ) ;
F_805 ( V_384 ) ;
F_805 ( V_466 . V_129 ) ;
if ( V_1264 -> V_466 . V_129 ) {
F_804 ( V_466 . V_570 ) ;
F_804 ( V_466 . V_294 ) ;
}
F_805 ( V_403 . V_440 ) ;
}
if ( F_234 ( V_16 ) )
F_805 ( V_573 ) ;
F_805 ( V_261 ) ;
F_804 ( V_1065 ) ;
F_805 ( V_135 ) ;
F_804 ( V_212 . V_87 ) ;
F_804 ( V_212 . V_214 ) ;
F_804 ( V_212 . V_736 ) ;
F_804 ( V_212 . V_737 ) ;
F_804 ( V_212 . V_1247 ) ;
F_804 ( V_212 . V_1248 ) ;
F_804 ( V_212 . V_1073 ) ;
F_804 ( V_212 . V_1245 ) ;
F_804 ( V_212 . V_1246 ) ;
if ( F_30 ( V_16 ) || F_60 ( V_16 ) -> V_127 >= 5 )
F_805 ( V_758 ) ;
F_810 ( V_40 . V_116 . V_117 ) ;
F_810 ( V_872 ) ;
#undef F_804
#undef F_805
#undef F_808
#undef F_809
#undef F_810
#undef F_811
#undef F_803
return V_307 ;
}
static void F_812 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_1267 V_1268 , * V_1269 ;
struct V_37 * V_37 ;
int V_169 ;
if ( F_60 ( V_16 ) -> V_127 < 9 )
return;
F_813 ( V_2 , & V_1268 ) ;
V_1269 = & V_2 -> V_587 . V_1270 . V_1271 ;
F_139 (dev, intel_crtc) {
struct V_1272 * V_1273 , * V_1274 ;
const enum V_119 V_119 = V_37 -> V_119 ;
if ( ! V_37 -> V_112 )
continue;
F_814 (dev_priv, pipe, plane) {
V_1273 = & V_1268 . V_169 [ V_119 ] [ V_169 ] ;
V_1274 = & V_1269 -> V_169 [ V_119 ] [ V_169 ] ;
if ( F_815 ( V_1273 , V_1274 ) )
continue;
F_131 ( L_245
L_246 ,
F_80 ( V_119 ) , V_169 + 1 ,
V_1274 -> V_399 , V_1274 -> V_1112 ,
V_1273 -> V_399 , V_1273 -> V_1112 ) ;
}
V_1273 = & V_1268 . V_169 [ V_119 ] [ V_1275 ] ;
V_1274 = & V_1269 -> V_169 [ V_119 ] [ V_1275 ] ;
if ( F_815 ( V_1273 , V_1274 ) )
continue;
F_131 ( L_247
L_246 ,
F_80 ( V_119 ) ,
V_1274 -> V_399 , V_1274 -> V_1112 ,
V_1273 -> V_399 , V_1273 -> V_1112 ) ;
}
}
static void
F_816 ( struct V_15 * V_16 ,
struct V_45 * V_732 )
{
struct V_48 * V_1276 ;
struct V_46 * V_47 ;
int V_50 ;
F_23 (old_state, connector, old_conn_state, i) {
struct V_747 * V_42 = V_47 -> V_42 ;
struct V_48 * V_36 = V_47 -> V_36 ;
F_489 ( F_785 ( V_47 ) ) ;
F_66 ( V_36 -> V_52 != V_42 ,
L_248 ) ;
}
}
static void
F_817 ( struct V_15 * V_16 )
{
struct V_41 * V_42 ;
struct V_748 * V_47 ;
F_593 (dev, encoder) {
bool V_129 = false ;
enum V_119 V_119 ;
F_151 ( L_249 ,
V_42 -> V_40 . V_40 . V_240 ,
V_42 -> V_40 . V_8 ) ;
F_782 (dev, connector) {
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
F_818 ( struct V_15 * V_16 , struct V_45 * V_732 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_41 * V_42 ;
struct V_35 * V_465 ;
struct V_111 * V_38 ;
int V_50 ;
F_425 (old_state, crtc, old_crtc_state, i) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_43 * V_211 , * V_1277 ;
bool V_112 ;
if ( ! F_18 ( V_38 -> V_36 ) &&
! F_283 ( V_38 -> V_36 ) -> V_1278 )
continue;
F_819 ( V_38 , V_465 ) ;
V_211 = F_283 ( V_465 ) ;
memset ( V_211 , 0 , sizeof( * V_211 ) ) ;
V_211 -> V_40 . V_38 = V_38 ;
V_211 -> V_40 . V_36 = V_732 ;
F_151 ( L_254 ,
V_38 -> V_40 . V_240 ) ;
V_112 = V_2 -> V_453 . V_1279 ( V_37 ,
V_211 ) ;
if ( ( V_37 -> V_119 == V_148 && V_2 -> V_165 & V_166 ) ||
( V_37 -> V_119 == V_157 && V_2 -> V_165 & V_167 ) )
V_112 = V_38 -> V_36 -> V_112 ;
F_66 ( V_38 -> V_36 -> V_112 != V_112 ,
L_255
L_252 , V_38 -> V_36 -> V_112 , V_112 ) ;
F_66 ( V_37 -> V_112 != V_38 -> V_36 -> V_112 ,
L_256
L_252 , V_38 -> V_36 -> V_112 , V_37 -> V_112 ) ;
F_21 (dev, crtc, encoder) {
enum V_119 V_119 ;
V_112 = V_42 -> V_140 ( V_42 , & V_119 ) ;
F_66 ( V_112 != V_38 -> V_36 -> V_112 ,
L_257 ,
V_42 -> V_40 . V_40 . V_240 , V_112 , V_38 -> V_36 -> V_112 ) ;
F_66 ( V_112 && V_37 -> V_119 != V_119 ,
L_258 ,
F_80 ( V_119 ) ) ;
if ( V_112 )
V_42 -> V_1280 ( V_42 , V_211 ) ;
}
if ( ! V_38 -> V_36 -> V_112 )
continue;
V_1277 = F_283 ( V_38 -> V_36 ) ;
if ( ! F_802 ( V_16 , V_1277 ,
V_211 , false ) ) {
F_66 ( 1 , L_259 ) ;
F_787 ( V_37 , V_211 ,
L_260 ) ;
F_787 ( V_37 , V_1277 ,
L_261 ) ;
}
}
}
static void
F_820 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_38 ;
struct V_138 V_212 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_547 ; V_50 ++ ) {
struct V_134 * V_137 = & V_2 -> V_136 [ V_50 ] ;
int V_1281 = 0 , V_1282 = 0 ;
bool V_112 ;
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
F_151 ( L_262 , V_137 -> V_8 ) ;
V_112 = V_137 -> V_140 ( V_2 , V_137 , & V_212 ) ;
F_66 ( V_137 -> V_112 > F_821 ( V_137 -> V_115 . V_237 ) ,
L_263 ,
V_137 -> V_112 , F_821 ( V_137 -> V_115 . V_237 ) ) ;
F_66 ( V_137 -> V_112 && ! V_137 -> V_238 ,
L_264 ) ;
F_66 ( V_137 -> V_238 && ! V_137 -> V_112 ,
L_265 ) ;
F_66 ( V_137 -> V_238 != V_112 ,
L_266 ,
V_137 -> V_238 , V_112 ) ;
F_139 (dev, crtc) {
if ( V_38 -> V_40 . V_36 -> V_242 && F_68 ( V_38 ) == V_137 )
V_1281 ++ ;
if ( V_38 -> V_112 && F_68 ( V_38 ) == V_137 )
V_1282 ++ ;
}
F_66 ( V_137 -> V_112 != V_1282 ,
L_267 ,
V_137 -> V_112 , V_1282 ) ;
F_66 ( F_821 ( V_137 -> V_115 . V_237 ) != V_1281 ,
L_268 ,
F_821 ( V_137 -> V_115 . V_237 ) , V_1281 ) ;
F_66 ( V_137 -> V_238 && memcmp ( & V_137 -> V_115 . V_139 , & V_212 ,
sizeof( V_212 ) ) ,
L_269 ) ;
}
}
static void
F_822 ( struct V_15 * V_16 ,
struct V_45 * V_732 )
{
F_812 ( V_16 ) ;
F_816 ( V_16 , V_732 ) ;
F_817 ( V_16 ) ;
F_818 ( V_16 , V_732 ) ;
F_820 ( V_16 ) ;
}
void F_823 ( const struct V_43 * V_211 ,
int V_1283 )
{
F_6 ( ! F_798 ( V_211 -> V_40 . V_116 . V_117 , V_1283 ) ,
L_270 ,
V_211 -> V_40 . V_116 . V_117 , V_1283 ) ;
}
static void F_824 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
if ( F_33 ( V_16 ) ) {
const struct V_563 * V_116 = & V_38 -> V_115 -> V_40 . V_116 ;
int V_930 ;
V_930 = V_116 -> V_914 ;
if ( V_116 -> V_359 & V_917 )
V_930 /= 2 ;
V_38 -> V_1284 = V_930 - 1 ;
} else if ( F_71 ( V_16 ) &&
F_20 ( V_38 , V_63 ) ) {
V_38 -> V_1284 = 2 ;
} else
V_38 -> V_1284 = 1 ;
}
static void F_825 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_1 * V_2 = F_203 ( V_16 ) ;
struct V_545 * V_135 = NULL ;
struct V_37 * V_37 ;
struct V_43 * V_43 ;
struct V_111 * V_38 ;
struct V_35 * V_44 ;
int V_50 ;
if ( ! V_2 -> V_453 . V_1228 )
return;
F_425 (state, crtc, crtc_state, i) {
int V_87 ;
V_37 = F_50 ( V_38 ) ;
V_43 = F_283 ( V_44 ) ;
V_87 = V_43 -> V_135 ;
if ( ! F_18 ( V_44 ) || V_87 == V_965 )
continue;
V_43 -> V_135 = V_965 ;
if ( ! V_135 )
V_135 = F_348 ( V_36 ) ;
V_135 [ V_87 ] . V_237 &= ~ ( 1 << V_37 -> V_119 ) ;
}
}
static int F_826 ( struct V_45 * V_36 )
{
struct V_35 * V_44 ;
struct V_37 * V_37 ;
struct V_111 * V_38 ;
struct V_43 * V_1285 = NULL ;
struct V_43 * V_752 = NULL ;
enum V_119 V_1286 = V_611 , V_1287 = V_611 ;
int V_50 ;
F_425 (state, crtc, crtc_state, i) {
V_37 = F_50 ( V_38 ) ;
if ( ! V_44 -> V_112 || ! F_18 ( V_44 ) )
continue;
if ( V_1285 ) {
V_752 = F_283 ( V_44 ) ;
break;
} else {
V_1285 = F_283 ( V_44 ) ;
V_1286 = V_37 -> V_119 ;
}
}
if ( ! V_1285 )
return 0 ;
F_139 (state->dev, intel_crtc) {
struct V_43 * V_211 ;
V_211 = F_460 ( V_36 , V_37 ) ;
if ( F_461 ( V_211 ) )
return F_462 ( V_211 ) ;
V_211 -> V_605 = V_611 ;
if ( ! V_211 -> V_40 . V_112 ||
F_18 ( & V_211 -> V_40 ) )
continue;
if ( V_1287 != V_611 )
return 0 ;
V_1287 = V_37 -> V_119 ;
}
if ( V_1287 != V_611 )
V_1285 -> V_605 = V_1287 ;
else if ( V_752 )
V_752 -> V_605 = V_1286 ;
return 0 ;
}
static int F_827 ( struct V_45 * V_36 )
{
struct V_111 * V_38 ;
struct V_35 * V_44 ;
int V_307 = 0 ;
F_216 (state->dev, crtc) {
V_44 = F_483 ( V_36 , V_38 ) ;
if ( F_461 ( V_44 ) )
return F_462 ( V_44 ) ;
if ( ! V_44 -> V_112 || F_18 ( V_44 ) )
continue;
V_44 -> V_1214 = true ;
V_307 = F_828 ( V_36 , V_38 ) ;
if ( V_307 )
break;
V_307 = F_829 ( V_36 , V_38 ) ;
if ( V_307 )
break;
}
return V_307 ;
}
static int F_830 ( struct V_45 * V_36 )
{
struct V_15 * V_16 = V_36 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_307 ;
if ( ! F_791 ( V_36 ) ) {
F_151 ( L_271 ) ;
return - V_309 ;
}
if ( V_2 -> V_453 . V_1288 ) {
unsigned int V_650 ;
V_307 = V_2 -> V_453 . V_1288 ( V_36 ) ;
V_650 = F_352 ( V_36 ) -> V_650 ;
if ( ! V_307 && V_650 != V_2 -> V_651 )
V_307 = F_827 ( V_36 ) ;
if ( V_307 < 0 )
return V_307 ;
} else
F_352 ( V_36 ) -> V_650 = V_2 -> V_651 ;
F_825 ( V_36 ) ;
if ( F_234 ( V_16 ) )
return F_826 ( V_36 ) ;
return 0 ;
}
static int F_831 ( struct V_15 * V_16 ,
struct V_45 * V_36 )
{
struct V_111 * V_38 ;
struct V_35 * V_44 ;
int V_307 , V_50 ;
bool V_1289 = false ;
V_307 = F_832 ( V_16 , V_36 ) ;
if ( V_307 )
return V_307 ;
F_425 (state, crtc, crtc_state, i) {
struct V_43 * V_211 =
F_283 ( V_44 ) ;
memset ( & F_50 ( V_38 ) -> V_591 , 0 ,
sizeof( struct V_590 ) ) ;
if ( V_44 -> V_449 . V_1290 != V_38 -> V_36 -> V_449 . V_1290 )
V_44 -> V_1214 = true ;
if ( ! V_44 -> V_242 ) {
if ( F_18 ( V_44 ) )
V_1289 = true ;
continue;
}
if ( ! F_18 ( V_44 ) )
continue;
V_307 = F_828 ( V_36 , V_38 ) ;
if ( V_307 )
return V_307 ;
V_307 = F_795 ( V_38 , V_211 ) ;
if ( V_307 )
return V_307 ;
if ( V_761 . V_1291 &&
F_802 ( V_36 -> V_16 ,
F_283 ( V_38 -> V_36 ) ,
V_211 , true ) ) {
V_44 -> V_1214 = false ;
F_283 ( V_44 ) -> V_1278 = true ;
}
if ( F_18 ( V_44 ) ) {
V_1289 = true ;
V_307 = F_829 ( V_36 , V_38 ) ;
if ( V_307 )
return V_307 ;
}
F_787 ( F_50 ( V_38 ) , V_211 ,
F_18 ( V_44 ) ?
L_272 : L_273 ) ;
}
if ( V_1289 ) {
V_307 = F_830 ( V_36 ) ;
if ( V_307 )
return V_307 ;
} else
F_352 ( V_36 ) -> V_650 =
F_203 ( V_36 -> V_16 ) -> V_651 ;
return F_833 ( V_36 -> V_16 , V_36 ) ;
}
static int F_834 ( struct V_15 * V_16 ,
struct V_45 * V_36 ,
bool V_1292 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_111 * V_38 ;
struct V_35 * V_44 ;
int V_307 = 0 ;
int V_50 ;
bool V_1289 = false ;
if ( V_1292 ) {
F_151 ( L_274 ) ;
return - V_309 ;
}
V_307 = F_835 ( V_16 , V_36 ) ;
if ( V_307 )
return V_307 ;
F_836 ( V_16 , V_36 ) ;
F_425 (state, crtc, crtc_state, i) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
if ( ! F_18 ( V_38 -> V_36 ) )
continue;
V_1289 = true ;
F_383 ( V_37 ) ;
if ( V_44 -> V_112 ) {
F_386 ( V_38 , V_44 -> V_366 ) ;
V_2 -> V_453 . V_739 ( V_38 ) ;
V_37 -> V_112 = false ;
F_154 ( V_37 ) ;
}
}
F_797 ( V_36 ) ;
if ( V_1289 ) {
F_351 ( V_36 ) ;
F_837 ( V_36 -> V_16 , V_36 ) ;
F_424 ( V_36 ) ;
}
F_425 (state, crtc, crtc_state, i) {
struct V_37 * V_37 = F_50 ( V_38 ) ;
bool V_1293 = F_18 ( V_38 -> V_36 ) ;
bool V_1278 = ! V_1293 &&
F_283 ( V_38 -> V_36 ) -> V_1278 ;
unsigned long V_647 = 0 ;
if ( V_1293 && V_38 -> V_36 -> V_112 ) {
F_824 ( F_50 ( V_38 ) ) ;
V_2 -> V_453 . V_1294 ( V_38 ) ;
}
if ( V_1278 ) {
V_647 = F_421 ( V_38 ) ;
V_1289 = true ;
}
if ( ! V_1293 )
F_383 ( V_37 ) ;
F_838 ( V_44 ) ;
if ( V_647 )
F_423 ( V_2 , V_647 ) ;
F_377 ( V_37 ) ;
}
F_839 ( V_16 , V_36 ) ;
F_840 ( V_16 , V_36 ) ;
if ( V_1289 )
F_822 ( V_16 , V_36 ) ;
F_486 ( V_36 ) ;
return 0 ;
}
void F_841 ( struct V_111 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_45 * V_36 ;
struct V_35 * V_44 ;
int V_307 ;
V_36 = F_482 ( V_16 ) ;
if ( ! V_36 ) {
F_151 ( L_275 ,
V_38 -> V_40 . V_240 ) ;
return;
}
V_36 -> V_744 = F_771 ( V_38 ) ;
V_485:
V_44 = F_483 ( V_36 , V_38 ) ;
V_307 = F_484 ( V_44 ) ;
if ( ! V_307 ) {
if ( ! V_44 -> V_112 )
goto V_1295;
V_44 -> V_1214 = true ;
V_307 = F_485 ( V_36 ) ;
}
if ( V_307 == - V_314 ) {
F_772 ( V_36 ) ;
F_691 ( V_36 -> V_744 ) ;
goto V_485;
}
if ( V_307 )
V_1295:
F_486 ( V_36 ) ;
}
static bool F_842 ( struct V_1 * V_2 ,
struct V_134 * V_137 ,
struct V_138 * V_139 )
{
T_2 V_10 ;
if ( ! F_86 ( V_2 , V_241 ) )
return false ;
V_10 = F_11 ( F_843 ( V_137 -> V_240 ) ) ;
V_139 -> V_87 = V_10 ;
V_139 -> V_736 = F_11 ( F_844 ( V_137 -> V_240 ) ) ;
V_139 -> V_737 = F_11 ( F_845 ( V_137 -> V_240 ) ) ;
return V_10 & V_131 ;
}
static void F_846 ( struct V_1 * V_2 ,
struct V_134 * V_137 )
{
F_128 ( F_844 ( V_137 -> V_240 ) , V_137 -> V_115 . V_139 . V_736 ) ;
F_128 ( F_845 ( V_137 -> V_240 ) , V_137 -> V_115 . V_139 . V_737 ) ;
}
static void F_847 ( struct V_1 * V_2 ,
struct V_134 * V_137 )
{
F_104 ( V_2 ) ;
F_128 ( F_843 ( V_137 -> V_240 ) , V_137 -> V_115 . V_139 . V_87 ) ;
F_129 ( F_843 ( V_137 -> V_240 ) ) ;
F_130 ( 150 ) ;
F_128 ( F_843 ( V_137 -> V_240 ) , V_137 -> V_115 . V_139 . V_87 ) ;
F_129 ( F_843 ( V_137 -> V_240 ) ) ;
F_130 ( 200 ) ;
}
static void F_848 ( struct V_1 * V_2 ,
struct V_134 * V_137 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_37 * V_38 ;
F_139 (dev, crtc) {
if ( F_68 ( V_38 ) == V_137 )
F_107 ( V_2 , V_38 -> V_119 ) ;
}
F_128 ( F_843 ( V_137 -> V_240 ) , 0 ) ;
F_129 ( F_843 ( V_137 -> V_240 ) ) ;
F_130 ( 200 ) ;
}
static void F_849 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
int V_50 ;
V_2 -> V_547 = 2 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_547 ; V_50 ++ ) {
V_2 -> V_136 [ V_50 ] . V_240 = V_50 ;
V_2 -> V_136 [ V_50 ] . V_8 = V_1296 [ V_50 ] ;
V_2 -> V_136 [ V_50 ] . V_239 = F_846 ;
V_2 -> V_136 [ V_50 ] . V_242 = F_847 ;
V_2 -> V_136 [ V_50 ] . V_243 = F_848 ;
V_2 -> V_136 [ V_50 ] . V_140 =
F_842 ;
}
}
static void F_850 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_71 ( V_16 ) )
F_851 ( V_16 ) ;
else if ( F_105 ( V_16 ) || F_106 ( V_16 ) )
F_849 ( V_16 ) ;
else
V_2 -> V_547 = 0 ;
F_126 ( V_2 -> V_547 > V_1297 ) ;
}
int
F_852 ( struct V_299 * V_169 ,
const struct V_276 * V_1298 )
{
struct V_15 * V_16 = V_169 -> V_16 ;
struct V_275 * V_114 = V_1298 -> V_114 ;
struct V_363 * V_363 = F_214 ( V_169 ) ;
struct V_304 * V_305 = F_189 ( V_114 ) ;
struct V_304 * V_1299 = F_189 ( V_169 -> V_114 ) ;
int V_307 = 0 ;
if ( ! V_305 )
return 0 ;
F_2 ( & V_16 -> V_308 ) ;
if ( V_169 -> type == V_1220 &&
F_60 ( V_16 ) -> V_1300 ) {
int V_1301 = F_141 ( V_16 ) ? 16 * 1024 : 256 ;
V_307 = F_853 ( V_305 , V_1301 ) ;
if ( V_307 )
F_151 ( L_276 ) ;
} else {
V_307 = F_188 ( V_169 , V_114 , V_1298 , NULL , NULL ) ;
}
if ( V_307 == 0 )
F_384 ( V_1299 , V_305 , V_363 -> V_378 ) ;
F_4 ( & V_16 -> V_308 ) ;
return V_307 ;
}
void
F_854 ( struct V_299 * V_169 ,
const struct V_276 * V_732 )
{
struct V_15 * V_16 = V_169 -> V_16 ;
struct V_304 * V_305 = F_189 ( V_732 -> V_114 ) ;
if ( ! V_305 )
return;
if ( V_169 -> type != V_1220 ||
! F_60 ( V_16 ) -> V_1300 ) {
F_2 ( & V_16 -> V_308 ) ;
F_197 ( V_732 -> V_114 , V_732 ) ;
F_4 ( & V_16 -> V_308 ) ;
}
}
int
F_855 ( struct V_37 * V_37 , struct V_43 * V_44 )
{
int V_1302 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_117 , V_650 ;
if ( ! V_37 || ! V_44 )
return V_1303 ;
V_16 = V_37 -> V_40 . V_16 ;
V_2 = V_16 -> V_17 ;
V_117 = V_44 -> V_40 . V_116 . V_117 ;
V_650 = F_352 ( V_44 -> V_40 . V_36 ) -> V_650 ;
if ( ! V_117 || ! V_650 )
return V_1303 ;
V_1302 = V_90 ( ( 1 << 16 ) * 3 - 1 , ( 1 << 8 ) * ( ( V_650 << 8 ) / V_117 ) ) ;
return V_1302 ;
}
static int
F_856 ( struct V_299 * V_169 ,
struct V_43 * V_44 ,
struct V_435 * V_36 )
{
struct V_111 * V_38 = V_36 -> V_40 . V_38 ;
struct V_275 * V_114 = V_36 -> V_40 . V_114 ;
int V_1304 = V_1303 ;
int V_1302 = V_1303 ;
bool V_1305 = false ;
if ( F_60 ( V_169 -> V_16 ) -> V_127 >= 9 &&
V_36 -> V_567 . V_359 == V_568 ) {
V_1304 = 1 ;
V_1302 = F_855 ( F_50 ( V_38 ) , V_44 ) ;
V_1305 = true ;
}
return F_857 ( V_169 , V_38 , V_114 , & V_36 -> V_444 ,
& V_36 -> V_446 , & V_36 -> V_1306 ,
V_1304 , V_1302 ,
V_1305 , true ,
& V_36 -> V_365 ) ;
}
static void
F_858 ( struct V_299 * V_169 ,
struct V_435 * V_36 )
{
struct V_111 * V_38 = V_36 -> V_40 . V_38 ;
struct V_275 * V_114 = V_36 -> V_40 . V_114 ;
struct V_15 * V_16 = V_169 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 ;
struct V_1307 * V_444 = & V_36 -> V_444 ;
V_38 = V_38 ? V_38 : V_169 -> V_38 ;
V_37 = F_50 ( V_38 ) ;
V_169 -> V_114 = V_114 ;
V_38 -> V_317 = V_444 -> V_445 >> 16 ;
V_38 -> V_318 = V_444 -> y1 >> 16 ;
if ( ! V_38 -> V_36 -> V_112 )
return;
V_2 -> V_453 . V_454 ( V_38 , V_114 ,
V_36 -> V_444 . V_445 >> 16 ,
V_36 -> V_444 . y1 >> 16 ) ;
}
static void
F_859 ( struct V_299 * V_169 ,
struct V_111 * V_38 )
{
struct V_15 * V_16 = V_169 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_453 . V_454 ( V_38 , NULL , 0 , 0 ) ;
}
static void F_860 ( struct V_111 * V_38 ,
struct V_35 * V_465 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_37 * V_37 = F_50 ( V_38 ) ;
struct V_43 * V_1308 =
F_283 ( V_465 ) ;
bool V_1293 = F_18 ( V_38 -> V_36 ) ;
if ( V_37 -> V_591 . V_1222 )
F_379 ( V_38 ) ;
if ( V_38 -> V_36 -> V_112 )
F_739 ( V_37 ) ;
if ( V_1293 )
return;
if ( F_283 ( V_38 -> V_36 ) -> V_1278 )
F_282 ( V_37 , V_1308 ) ;
else if ( F_60 ( V_16 ) -> V_127 >= 9 )
F_244 ( V_37 ) ;
}
static void F_861 ( struct V_111 * V_38 ,
struct V_35 * V_465 )
{
struct V_37 * V_37 = F_50 ( V_38 ) ;
if ( V_38 -> V_36 -> V_112 )
F_740 ( V_37 ) ;
}
void F_862 ( struct V_299 * V_169 )
{
struct V_363 * V_363 = F_214 ( V_169 ) ;
F_863 ( V_169 ) ;
F_215 ( V_363 ) ;
}
static struct V_299 * F_864 ( struct V_15 * V_16 ,
int V_119 )
{
struct V_363 * V_113 ;
struct V_435 * V_36 ;
const T_2 * V_1309 ;
unsigned int V_1310 ;
V_113 = F_491 ( sizeof( * V_113 ) , V_750 ) ;
if ( V_113 == NULL )
return NULL ;
V_36 = F_865 ( & V_113 -> V_40 ) ;
if ( ! V_36 ) {
F_215 ( V_113 ) ;
return NULL ;
}
V_113 -> V_40 . V_36 = & V_36 -> V_40 ;
V_113 -> V_1311 = false ;
V_113 -> V_1312 = 1 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
V_113 -> V_1311 = true ;
V_36 -> V_440 = - 1 ;
}
V_113 -> V_119 = V_119 ;
V_113 -> V_169 = V_119 ;
V_113 -> V_378 = F_866 ( V_119 ) ;
V_113 -> V_1313 = F_856 ;
V_113 -> V_455 = F_858 ;
V_113 -> V_367 = F_859 ;
if ( F_867 ( V_16 ) && F_60 ( V_16 ) -> V_127 < 4 )
V_113 -> V_169 = ! V_119 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
V_1309 = V_1314 ;
V_1310 = F_301 ( V_1314 ) ;
} else if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
V_1309 = V_1315 ;
V_1310 = F_301 ( V_1315 ) ;
} else {
V_1309 = V_1316 ;
V_1310 = F_301 ( V_1316 ) ;
}
F_868 ( V_16 , & V_113 -> V_40 , 0 ,
& V_1317 ,
V_1309 , V_1310 ,
V_1223 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 )
F_869 ( V_16 , V_113 ) ;
F_870 ( & V_113 -> V_40 , & V_1318 ) ;
return & V_113 -> V_40 ;
}
void F_869 ( struct V_15 * V_16 , struct V_363 * V_169 )
{
if ( ! V_16 -> V_741 . V_1319 ) {
unsigned long V_359 = F_229 ( V_422 ) |
F_229 ( V_390 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 9 )
V_359 |= F_229 ( V_423 ) | F_229 ( V_426 ) ;
V_16 -> V_741 . V_1319 =
F_871 ( V_16 , V_359 ) ;
}
if ( V_16 -> V_741 . V_1319 )
F_872 ( & V_169 -> V_40 . V_40 ,
V_16 -> V_741 . V_1319 ,
V_169 -> V_40 . V_36 -> V_283 ) ;
}
static int
F_873 ( struct V_299 * V_169 ,
struct V_43 * V_44 ,
struct V_435 * V_36 )
{
struct V_111 * V_38 = V_44 -> V_40 . V_38 ;
struct V_275 * V_114 = V_36 -> V_40 . V_114 ;
struct V_304 * V_305 = F_189 ( V_114 ) ;
enum V_119 V_119 = F_214 ( V_169 ) -> V_119 ;
unsigned V_357 ;
int V_307 ;
V_307 = F_857 ( V_169 , V_38 , V_114 , & V_36 -> V_444 ,
& V_36 -> V_446 , & V_36 -> V_1306 ,
V_1303 ,
V_1303 ,
true , true , & V_36 -> V_365 ) ;
if ( V_307 )
return V_307 ;
if ( ! V_305 )
return 0 ;
if ( ! F_667 ( V_169 -> V_16 , V_36 -> V_40 . V_374 , V_36 -> V_40 . V_375 ) ) {
F_874 ( L_277 ,
V_36 -> V_40 . V_374 , V_36 -> V_40 . V_375 ) ;
return - V_309 ;
}
V_357 = F_661 ( V_36 -> V_40 . V_374 ) * 4 ;
if ( V_305 -> V_40 . V_294 < V_357 * V_36 -> V_40 . V_375 ) {
F_151 ( L_278 ) ;
return - V_746 ;
}
if ( V_114 -> V_290 [ 0 ] != V_268 ) {
F_151 ( L_279 ) ;
return - V_309 ;
}
if ( F_32 ( V_169 -> V_16 ) && V_119 == V_530 &&
V_36 -> V_365 && V_36 -> V_40 . V_372 < 0 ) {
F_151 ( L_280 ) ;
return - V_309 ;
}
return 0 ;
}
static void
F_875 ( struct V_299 * V_169 ,
struct V_111 * V_38 )
{
F_665 ( V_38 , false ) ;
}
static void
F_876 ( struct V_299 * V_169 ,
struct V_435 * V_36 )
{
struct V_111 * V_38 = V_36 -> V_40 . V_38 ;
struct V_15 * V_16 = V_169 -> V_16 ;
struct V_37 * V_37 ;
struct V_304 * V_305 = F_189 ( V_36 -> V_40 . V_114 ) ;
T_2 V_1196 ;
V_38 = V_38 ? V_38 : V_169 -> V_38 ;
V_37 = F_50 ( V_38 ) ;
if ( ! V_305 )
V_1196 = 0 ;
else if ( ! F_60 ( V_16 ) -> V_1300 )
V_1196 = F_217 ( V_305 ) ;
else
V_1196 = V_305 -> V_1320 -> V_1321 ;
V_37 -> V_1105 = V_1196 ;
if ( V_38 -> V_36 -> V_112 )
F_665 ( V_38 , V_36 -> V_365 ) ;
}
static struct V_299 * F_877 ( struct V_15 * V_16 ,
int V_119 )
{
struct V_363 * V_1091 ;
struct V_435 * V_36 ;
V_1091 = F_491 ( sizeof( * V_1091 ) , V_750 ) ;
if ( V_1091 == NULL )
return NULL ;
V_36 = F_865 ( & V_1091 -> V_40 ) ;
if ( ! V_36 ) {
F_215 ( V_1091 ) ;
return NULL ;
}
V_1091 -> V_40 . V_36 = & V_36 -> V_40 ;
V_1091 -> V_1311 = false ;
V_1091 -> V_1312 = 1 ;
V_1091 -> V_119 = V_119 ;
V_1091 -> V_169 = V_119 ;
V_1091 -> V_378 = F_878 ( V_119 ) ;
V_1091 -> V_1313 = F_873 ;
V_1091 -> V_455 = F_876 ;
V_1091 -> V_367 = F_875 ;
F_868 ( V_16 , & V_1091 -> V_40 , 0 ,
& V_1317 ,
V_1322 ,
F_301 ( V_1322 ) ,
V_1220 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
if ( ! V_16 -> V_741 . V_1319 )
V_16 -> V_741 . V_1319 =
F_871 ( V_16 ,
F_229 ( V_422 ) |
F_229 ( V_390 ) ) ;
if ( V_16 -> V_741 . V_1319 )
F_872 ( & V_1091 -> V_40 . V_40 ,
V_16 -> V_741 . V_1319 ,
V_36 -> V_40 . V_283 ) ;
}
if ( F_60 ( V_16 ) -> V_127 >= 9 )
V_36 -> V_440 = - 1 ;
F_870 ( & V_1091 -> V_40 , & V_1318 ) ;
return & V_1091 -> V_40 ;
}
static void F_659 ( struct V_15 * V_16 , struct V_37 * V_37 ,
struct V_43 * V_44 )
{
int V_50 ;
struct V_1323 * V_1323 ;
struct V_402 * V_403 = & V_44 -> V_403 ;
for ( V_50 = 0 ; V_50 < V_37 -> V_404 ; V_50 ++ ) {
V_1323 = & V_403 -> V_405 [ V_50 ] ;
V_1323 -> V_406 = 0 ;
V_1323 -> V_449 = V_1324 ;
}
V_403 -> V_440 = - 1 ;
}
static void F_879 ( struct V_15 * V_16 , int V_119 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_37 * V_37 ;
struct V_43 * V_44 = NULL ;
struct V_299 * V_113 = NULL ;
struct V_299 * V_1091 = NULL ;
int V_50 , V_307 ;
V_37 = F_491 ( sizeof( * V_37 ) , V_750 ) ;
if ( V_37 == NULL )
return;
V_44 = F_491 ( sizeof( * V_44 ) , V_750 ) ;
if ( ! V_44 )
goto V_817;
V_37 -> V_115 = V_44 ;
V_37 -> V_40 . V_36 = & V_44 -> V_40 ;
V_44 -> V_40 . V_38 = & V_37 -> V_40 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
if ( V_119 == V_530 )
V_37 -> V_404 = 1 ;
else
V_37 -> V_404 = V_1325 ;
F_659 ( V_16 , V_37 , V_44 ) ;
}
V_113 = F_864 ( V_16 , V_119 ) ;
if ( ! V_113 )
goto V_817;
V_1091 = F_877 ( V_16 , V_119 ) ;
if ( ! V_1091 )
goto V_817;
V_307 = F_880 ( V_16 , & V_37 -> V_40 , V_113 ,
V_1091 , & V_1326 ) ;
if ( V_307 )
goto V_817;
F_881 ( & V_37 -> V_40 , 256 ) ;
for ( V_50 = 0 ; V_50 < 256 ; V_50 ++ ) {
V_37 -> V_583 [ V_50 ] = V_50 ;
V_37 -> V_584 [ V_50 ] = V_50 ;
V_37 -> V_585 [ V_50 ] = V_50 ;
}
V_37 -> V_119 = V_119 ;
V_37 -> V_169 = V_119 ;
if ( F_867 ( V_16 ) && F_60 ( V_16 ) -> V_127 < 4 ) {
F_151 ( L_281 ) ;
V_37 -> V_169 = ! V_119 ;
}
V_37 -> V_1095 = ~ 0 ;
V_37 -> V_1094 = ~ 0 ;
V_37 -> V_1096 = ~ 0 ;
V_37 -> V_587 . V_595 = true ;
F_126 ( V_119 >= F_301 ( V_2 -> V_1156 ) ||
V_2 -> V_1156 [ V_37 -> V_169 ] != NULL ) ;
V_2 -> V_1156 [ V_37 -> V_169 ] = & V_37 -> V_40 ;
V_2 -> V_120 [ V_37 -> V_119 ] = & V_37 -> V_40 ;
F_882 ( & V_37 -> V_40 , & V_1327 ) ;
F_9 ( F_155 ( & V_37 -> V_40 ) != V_37 -> V_119 ) ;
return;
V_817:
if ( V_113 )
F_863 ( V_113 ) ;
if ( V_1091 )
F_863 ( V_1091 ) ;
F_215 ( V_44 ) ;
F_215 ( V_37 ) ;
}
enum V_119 F_883 ( struct V_748 * V_47 )
{
struct V_747 * V_42 = V_47 -> V_40 . V_42 ;
struct V_15 * V_16 = V_47 -> V_40 . V_16 ;
F_9 ( ! F_884 ( & V_16 -> V_741 . V_1118 ) ) ;
if ( ! V_42 || F_9 ( ! V_42 -> V_38 ) )
return V_611 ;
return F_50 ( V_42 -> V_38 ) -> V_119 ;
}
int F_885 ( struct V_15 * V_16 , void * V_1059 ,
struct V_1328 * V_1329 )
{
struct V_1330 * V_1331 = V_1059 ;
struct V_111 * V_1332 ;
struct V_37 * V_38 ;
V_1332 = F_886 ( V_16 , V_1331 -> V_1333 ) ;
if ( ! V_1332 ) {
F_131 ( L_282 ) ;
return - V_1334 ;
}
V_38 = F_50 ( V_1332 ) ;
V_1331 -> V_119 = V_38 -> V_119 ;
return 0 ;
}
static int F_887 ( struct V_41 * V_42 )
{
struct V_15 * V_16 = V_42 -> V_40 . V_16 ;
struct V_41 * V_1227 ;
int V_1335 = 0 ;
int V_1336 = 0 ;
F_593 (dev, source_encoder) {
if ( F_776 ( V_42 , V_1227 ) )
V_1335 |= ( 1 << V_1336 ) ;
V_1336 ++ ;
}
return V_1335 ;
}
static bool F_888 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! F_127 ( V_16 ) )
return false ;
if ( ( F_11 ( V_1337 ) & V_1338 ) == 0 )
return false ;
if ( F_17 ( V_16 ) && ( F_11 ( V_659 ) & V_1339 ) )
return false ;
return true ;
}
static bool F_889 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 )
return false ;
if ( F_511 ( V_16 ) || F_430 ( V_16 ) )
return false ;
if ( F_32 ( V_16 ) )
return false ;
if ( F_13 ( V_16 ) && ! V_2 -> V_835 . V_1340 )
return false ;
return true ;
}
static void F_890 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_41 * V_42 ;
bool V_1341 = false ;
F_891 ( V_16 ) ;
if ( F_889 ( V_16 ) )
F_892 ( V_16 ) ;
if ( F_29 ( V_16 ) ) {
F_893 ( V_16 , V_622 ) ;
F_893 ( V_16 , V_230 ) ;
F_893 ( V_16 , V_232 ) ;
} else if ( F_71 ( V_16 ) ) {
int V_101 ;
V_101 = F_11 ( F_894 ( V_622 ) ) & V_1342 ;
if ( V_101 || F_428 ( V_16 ) )
F_893 ( V_16 , V_622 ) ;
V_101 = F_11 ( V_1343 ) ;
if ( V_101 & V_1344 )
F_893 ( V_16 , V_230 ) ;
if ( V_101 & V_1345 )
F_893 ( V_16 , V_232 ) ;
if ( V_101 & V_1346 )
F_893 ( V_16 , V_234 ) ;
if ( F_428 ( V_16 ) &&
( V_2 -> V_835 . V_1347 [ V_627 ] . V_1348 ||
V_2 -> V_835 . V_1347 [ V_627 ] . V_1349 ||
V_2 -> V_835 . V_1347 [ V_627 ] . V_1350 ) )
F_893 ( V_16 , V_627 ) ;
} else if ( F_10 ( V_16 ) ) {
int V_101 ;
V_1341 = F_895 ( V_16 , V_234 ) ;
if ( F_888 ( V_16 ) )
F_896 ( V_16 , V_1337 , V_622 ) ;
if ( F_11 ( V_208 ) & V_1351 ) {
V_101 = F_897 ( V_16 , V_1352 , true ) ;
if ( ! V_101 )
F_898 ( V_16 , V_208 , V_230 ) ;
if ( ! V_101 && ( F_11 ( V_201 ) & V_1338 ) )
F_896 ( V_16 , V_201 , V_230 ) ;
}
if ( F_11 ( V_209 ) & V_1351 )
F_898 ( V_16 , V_209 , V_232 ) ;
if ( ! V_1341 && F_11 ( V_210 ) & V_1351 )
F_898 ( V_16 , V_210 , V_234 ) ;
if ( F_11 ( V_203 ) & V_1338 )
F_896 ( V_16 , V_203 , V_232 ) ;
if ( F_11 ( V_205 ) & V_1338 )
F_896 ( V_16 , V_205 , V_234 ) ;
} else if ( F_13 ( V_16 ) ) {
if ( F_11 ( V_1353 ) & V_1351 &&
! F_895 ( V_16 , V_230 ) )
F_898 ( V_16 , V_1353 , V_230 ) ;
if ( F_11 ( V_1354 ) & V_1338 ||
F_895 ( V_16 , V_230 ) )
F_896 ( V_16 , V_1354 , V_230 ) ;
if ( F_11 ( V_1355 ) & V_1351 &&
! F_895 ( V_16 , V_232 ) )
F_898 ( V_16 , V_1355 , V_232 ) ;
if ( F_11 ( V_1356 ) & V_1338 ||
F_895 ( V_16 , V_232 ) )
F_896 ( V_16 , V_1356 , V_232 ) ;
if ( F_32 ( V_16 ) ) {
if ( F_11 ( V_1357 ) & V_1351 )
F_898 ( V_16 , V_1357 , V_234 ) ;
if ( F_11 ( V_1358 ) & V_1338 )
F_896 ( V_16 , V_1358 , V_234 ) ;
}
F_899 ( V_16 ) ;
} else if ( ! F_33 ( V_16 ) && ! F_31 ( V_16 ) ) {
bool V_101 = false ;
if ( F_11 ( V_1359 ) & V_1351 ) {
F_151 ( L_283 ) ;
V_101 = F_897 ( V_16 , V_1359 , true ) ;
if ( ! V_101 && F_30 ( V_16 ) ) {
F_151 ( L_284 ) ;
F_898 ( V_16 , V_1360 , V_230 ) ;
}
if ( ! V_101 && F_30 ( V_16 ) )
F_896 ( V_16 , V_1361 , V_230 ) ;
}
if ( F_11 ( V_1359 ) & V_1351 ) {
F_151 ( L_285 ) ;
V_101 = F_897 ( V_16 , V_1362 , false ) ;
}
if ( ! V_101 && ( F_11 ( V_1362 ) & V_1351 ) ) {
if ( F_30 ( V_16 ) ) {
F_151 ( L_286 ) ;
F_898 ( V_16 , V_1363 , V_232 ) ;
}
if ( F_30 ( V_16 ) )
F_896 ( V_16 , V_1364 , V_232 ) ;
}
if ( F_30 ( V_16 ) &&
( F_11 ( V_1365 ) & V_1338 ) )
F_896 ( V_16 , V_1365 , V_234 ) ;
} else if ( F_33 ( V_16 ) )
F_900 ( V_16 ) ;
if ( F_901 ( V_16 ) )
F_902 ( V_16 ) ;
F_903 ( V_16 ) ;
F_593 (dev, encoder) {
V_42 -> V_40 . V_1125 = V_42 -> V_237 ;
V_42 -> V_40 . V_1366 =
F_887 ( V_42 ) ;
}
F_601 ( V_16 ) ;
F_904 ( V_16 ) ;
}
static void F_905 ( struct V_275 * V_114 )
{
struct V_15 * V_16 = V_114 -> V_16 ;
struct V_957 * V_958 = F_208 ( V_114 ) ;
F_906 ( V_114 ) ;
F_2 ( & V_16 -> V_308 ) ;
F_9 ( ! V_958 -> V_305 -> V_1367 -- ) ;
F_209 ( & V_958 -> V_305 -> V_40 ) ;
F_4 ( & V_16 -> V_308 ) ;
F_215 ( V_958 ) ;
}
static int F_907 ( struct V_275 * V_114 ,
struct V_1328 * V_1329 ,
unsigned int * V_1368 )
{
struct V_957 * V_958 = F_208 ( V_114 ) ;
struct V_304 * V_305 = V_958 -> V_305 ;
if ( V_305 -> V_1369 . V_310 ) {
F_874 ( L_287 ) ;
return - V_309 ;
}
return F_908 ( V_1329 , & V_305 -> V_40 , V_1368 ) ;
}
static int F_909 ( struct V_275 * V_114 ,
struct V_1328 * V_1329 ,
unsigned V_359 , unsigned V_1370 ,
struct V_1371 * V_1372 ,
unsigned V_1373 )
{
struct V_15 * V_16 = V_114 -> V_16 ;
struct V_957 * V_958 = F_208 ( V_114 ) ;
struct V_304 * V_305 = V_958 -> V_305 ;
F_2 ( & V_16 -> V_308 ) ;
F_910 ( V_305 , false , V_1374 ) ;
F_4 ( & V_16 -> V_308 ) ;
return 0 ;
}
static
T_1 F_911 ( struct V_15 * V_16 , V_89 V_289 ,
T_2 V_264 )
{
T_1 V_127 = F_60 ( V_16 ) -> V_127 ;
if ( V_127 >= 9 ) {
return V_90 ( 8192 * F_177 ( V_264 , 0 ) , 32768 ) ;
} else if ( V_127 >= 5 && ! F_13 ( V_16 ) ) {
return 32 * 1024 ;
} else if ( V_127 >= 4 ) {
if ( V_289 == V_269 )
return 16 * 1024 ;
else
return 32 * 1024 ;
} else if ( V_127 >= 3 ) {
if ( V_289 == V_269 )
return 8 * 1024 ;
else
return 16 * 1024 ;
} else {
return 8 * 1024 ;
}
}
static int F_207 ( struct V_15 * V_16 ,
struct V_957 * V_958 ,
struct V_349 * V_350 ,
struct V_304 * V_305 )
{
unsigned int V_956 ;
int V_307 ;
T_1 V_1375 , V_1376 ;
F_9 ( ! F_190 ( & V_16 -> V_308 ) ) ;
if ( V_350 -> V_359 & V_360 ) {
if ( ! ! ( V_305 -> V_319 == V_356 ) !=
! ! ( V_350 -> V_290 [ 0 ] == V_269 ) ) {
F_874 ( L_288 ) ;
return - V_309 ;
}
} else {
if ( V_305 -> V_319 == V_356 )
V_350 -> V_290 [ 0 ] = V_269 ;
else if ( V_305 -> V_319 == V_1377 ) {
F_874 ( L_289 ) ;
return - V_309 ;
}
}
switch ( V_350 -> V_290 [ 0 ] ) {
case V_270 :
case V_271 :
if ( F_60 ( V_16 ) -> V_127 < 9 ) {
F_874 ( L_290 ,
V_350 -> V_290 [ 0 ] ) ;
return - V_309 ;
}
case V_268 :
case V_269 :
break;
default:
F_874 ( L_291 ,
V_350 -> V_290 [ 0 ] ) ;
return - V_309 ;
}
V_1376 = F_237 ( V_16 , V_350 -> V_290 [ 0 ] ,
V_350 -> V_264 ) ;
if ( V_350 -> V_286 [ 0 ] & ( V_1376 - 1 ) ) {
F_874 ( L_292 ,
V_350 -> V_286 [ 0 ] , V_1376 ) ;
return - V_309 ;
}
V_1375 = F_911 ( V_16 , V_350 -> V_290 [ 0 ] ,
V_350 -> V_264 ) ;
if ( V_350 -> V_286 [ 0 ] > V_1375 ) {
F_874 ( L_293 ,
V_350 -> V_290 [ 0 ] != V_268 ?
L_294 : L_295 ,
V_350 -> V_286 [ 0 ] , V_1375 ) ;
return - V_309 ;
}
if ( V_350 -> V_290 [ 0 ] == V_269 &&
V_350 -> V_286 [ 0 ] != V_305 -> V_357 ) {
F_874 ( L_296 ,
V_350 -> V_286 [ 0 ] , V_305 -> V_357 ) ;
return - V_309 ;
}
switch ( V_350 -> V_264 ) {
case V_327 :
case V_331 :
case V_333 :
case V_345 :
break;
case V_329 :
if ( F_60 ( V_16 ) -> V_127 > 3 ) {
F_874 ( L_297 ,
F_912 ( V_350 -> V_264 ) ) ;
return - V_309 ;
}
break;
case V_344 :
if ( ! F_13 ( V_16 ) && F_60 ( V_16 ) -> V_127 < 9 ) {
F_874 ( L_297 ,
F_912 ( V_350 -> V_264 ) ) ;
return - V_309 ;
}
break;
case V_335 :
case V_337 :
case V_339 :
if ( F_60 ( V_16 ) -> V_127 < 4 ) {
F_874 ( L_297 ,
F_912 ( V_350 -> V_264 ) ) ;
return - V_309 ;
}
break;
case V_1378 :
if ( ! F_13 ( V_16 ) ) {
F_874 ( L_297 ,
F_912 ( V_350 -> V_264 ) ) ;
return - V_309 ;
}
break;
case V_410 :
case V_415 :
case V_413 :
case V_417 :
if ( F_60 ( V_16 ) -> V_127 < 5 ) {
F_874 ( L_297 ,
F_912 ( V_350 -> V_264 ) ) ;
return - V_309 ;
}
break;
default:
F_874 ( L_297 ,
F_912 ( V_350 -> V_264 ) ) ;
return - V_309 ;
}
if ( V_350 -> V_288 [ 0 ] != 0 )
return - V_309 ;
V_956 = F_180 ( V_16 , V_350 -> V_272 ,
V_350 -> V_264 ,
V_350 -> V_290 [ 0 ] ) ;
if ( V_305 -> V_40 . V_294 < V_956 * V_350 -> V_286 [ 0 ] )
return - V_309 ;
F_913 ( & V_958 -> V_40 , V_350 ) ;
V_958 -> V_305 = V_305 ;
V_958 -> V_305 -> V_1367 ++ ;
V_307 = F_914 ( V_16 , & V_958 -> V_40 , & V_1379 ) ;
if ( V_307 ) {
F_131 ( L_298 , V_307 ) ;
return V_307 ;
}
return 0 ;
}
static struct V_275 *
F_915 ( struct V_15 * V_16 ,
struct V_1328 * V_1380 ,
struct V_349 * V_1381 )
{
struct V_304 * V_305 ;
struct V_349 V_350 = * V_1381 ;
V_305 = F_916 ( F_917 ( V_16 , V_1380 ,
V_350 . V_1382 [ 0 ] ) ) ;
if ( & V_305 -> V_40 == NULL )
return F_670 ( - V_1334 ) ;
return F_671 ( V_16 , & V_350 , V_305 ) ;
}
static inline void F_918 ( struct V_15 * V_16 )
{
}
static void F_919 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_10 ( V_16 ) || F_30 ( V_16 ) )
V_2 -> V_453 . V_950 = F_45 ;
else if ( F_32 ( V_16 ) )
V_2 -> V_453 . V_950 = F_51 ;
else if ( F_13 ( V_16 ) )
V_2 -> V_453 . V_950 = F_49 ;
else if ( F_31 ( V_16 ) )
V_2 -> V_453 . V_950 = F_44 ;
else
V_2 -> V_453 . V_950 = F_43 ;
if ( F_60 ( V_16 ) -> V_127 >= 9 ) {
V_2 -> V_453 . V_1279 = F_658 ;
V_2 -> V_453 . V_1383 =
F_627 ;
V_2 -> V_453 . V_1228 =
F_650 ;
V_2 -> V_453 . V_1294 = F_397 ;
V_2 -> V_453 . V_739 = F_407 ;
V_2 -> V_453 . V_454 =
F_248 ;
} else if ( F_71 ( V_16 ) ) {
V_2 -> V_453 . V_1279 = F_658 ;
V_2 -> V_453 . V_1383 =
F_630 ;
V_2 -> V_453 . V_1228 =
F_650 ;
V_2 -> V_453 . V_1294 = F_397 ;
V_2 -> V_453 . V_739 = F_407 ;
V_2 -> V_453 . V_454 =
F_233 ;
} else if ( F_10 ( V_16 ) ) {
V_2 -> V_453 . V_1279 = F_631 ;
V_2 -> V_453 . V_1383 =
F_630 ;
V_2 -> V_453 . V_1228 =
F_620 ;
V_2 -> V_453 . V_1294 = F_388 ;
V_2 -> V_453 . V_739 = F_405 ;
V_2 -> V_453 . V_454 =
F_233 ;
} else if ( F_13 ( V_16 ) ) {
V_2 -> V_453 . V_1279 = F_590 ;
V_2 -> V_453 . V_1383 =
F_588 ;
V_2 -> V_453 . V_1228 = F_585 ;
V_2 -> V_453 . V_1294 = F_468 ;
V_2 -> V_453 . V_739 = F_479 ;
V_2 -> V_453 . V_454 =
F_221 ;
} else {
V_2 -> V_453 . V_1279 = F_590 ;
V_2 -> V_453 . V_1383 =
F_588 ;
V_2 -> V_453 . V_1228 = F_585 ;
V_2 -> V_453 . V_1294 = F_477 ;
V_2 -> V_453 . V_739 = F_479 ;
V_2 -> V_453 . V_454 =
F_221 ;
}
if ( F_428 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_507 ;
else if ( F_29 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_508 ;
else if ( F_235 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_509 ;
else if ( F_234 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_510 ;
else if ( F_13 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_512 ;
else if ( F_17 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_513 ;
else if ( F_576 ( V_16 ) || F_186 ( V_16 ) ||
F_299 ( V_16 ) || F_290 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_514 ;
else if ( F_526 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_528 ;
else if ( F_187 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_529 ;
else if ( F_31 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_517 ;
else if ( F_527 ( V_16 ) || F_30 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_530 ;
else if ( F_506 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_515 ;
else if ( F_577 ( V_16 ) || F_82 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_516 ;
else if ( F_31 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_517 ;
else if ( F_920 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_519 ;
else if ( F_83 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_520 ;
else if ( F_921 ( V_16 ) )
V_2 -> V_453 . V_662 =
F_521 ;
else {
F_6 ( ! F_141 ( V_16 ) , L_299 ) ;
V_2 -> V_453 . V_662 =
F_524 ;
}
if ( F_17 ( V_16 ) ) {
V_2 -> V_453 . V_532 = F_291 ;
} else if ( F_299 ( V_16 ) ) {
V_2 -> V_453 . V_532 = F_297 ;
} else if ( F_290 ( V_16 ) ) {
V_2 -> V_453 . V_532 = F_300 ;
} else if ( F_234 ( V_16 ) || F_235 ( V_16 ) ) {
V_2 -> V_453 . V_532 = V_1384 ;
if ( F_235 ( V_16 ) ) {
V_2 -> V_453 . V_649 =
F_649 ;
V_2 -> V_453 . V_1288 =
F_648 ;
}
} else if ( F_13 ( V_16 ) ) {
V_2 -> V_453 . V_649 =
F_467 ;
V_2 -> V_453 . V_1288 =
F_463 ;
} else if ( F_29 ( V_16 ) ) {
V_2 -> V_453 . V_649 =
F_645 ;
V_2 -> V_453 . V_1288 =
F_464 ;
}
switch ( F_60 ( V_16 ) -> V_127 ) {
case 2 :
V_2 -> V_453 . V_1210 = F_723 ;
break;
case 3 :
V_2 -> V_453 . V_1210 = F_727 ;
break;
case 4 :
case 5 :
V_2 -> V_453 . V_1210 = F_728 ;
break;
case 6 :
V_2 -> V_453 . V_1210 = F_729 ;
break;
case 7 :
case 8 :
V_2 -> V_453 . V_1210 = F_730 ;
break;
case 9 :
default:
V_2 -> V_453 . V_1210 = F_749 ;
}
F_922 ( & V_2 -> V_1385 ) ;
}
static void F_923 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_165 |= V_166 ;
F_924 ( L_300 ) ;
}
static void F_925 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_165 |= V_167 ;
F_924 ( L_301 ) ;
}
static void F_926 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_165 |= V_837 ;
F_924 ( L_302 ) ;
}
static void F_927 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_165 |= V_1386 ;
F_924 ( L_303 ) ;
}
static void F_928 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_165 |= V_1387 ;
F_924 ( L_304 ) ;
}
static int F_929 ( const struct V_1388 * V_240 )
{
F_924 ( L_305 , V_240 -> V_1389 ) ;
return 1 ;
}
static void F_930 ( struct V_15 * V_16 )
{
struct V_1390 * V_1391 = V_16 -> V_779 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < F_301 ( V_1392 ) ; V_50 ++ ) {
struct V_1393 * V_1394 = & V_1392 [ V_50 ] ;
if ( V_1391 -> V_1395 == V_1394 -> V_1395 &&
( V_1391 -> V_1396 == V_1394 -> V_1396 ||
V_1394 -> V_1396 == V_1397 ) &&
( V_1391 -> V_1398 == V_1394 -> V_1398 ||
V_1394 -> V_1398 == V_1397 ) )
V_1394 -> V_1399 ( V_16 ) ;
}
for ( V_50 = 0 ; V_50 < F_301 ( V_1400 ) ; V_50 ++ ) {
if ( F_931 ( * V_1400 [ V_50 ] . V_1401 ) != 0 )
V_1400 [ V_50 ] . V_1399 ( V_16 ) ;
}
}
static void F_932 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_11 V_1402 ;
T_1 V_1403 = F_933 ( V_16 ) ;
F_934 ( V_16 -> V_779 , V_1404 ) ;
F_935 ( V_1405 , V_1406 ) ;
V_1402 = F_936 ( V_1407 ) ;
F_935 ( V_1402 | 1 << 5 , V_1407 ) ;
F_937 ( V_16 -> V_779 , V_1404 ) ;
F_130 ( 300 ) ;
F_128 ( V_1403 , V_1408 ) ;
F_129 ( V_1403 ) ;
}
void F_271 ( struct V_15 * V_16 )
{
F_431 ( V_16 ) ;
F_644 ( V_16 ) ;
F_938 ( V_16 ) ;
F_939 ( V_16 ) ;
}
void F_940 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
int V_174 , V_307 ;
enum V_119 V_119 ;
struct V_37 * V_38 ;
F_941 ( V_16 ) ;
V_16 -> V_741 . V_1409 = 0 ;
V_16 -> V_741 . V_1410 = 0 ;
V_16 -> V_741 . V_1411 = 24 ;
V_16 -> V_741 . V_1412 = 1 ;
V_16 -> V_741 . V_1413 = true ;
V_16 -> V_741 . V_1124 = & V_1414 ;
F_930 ( V_16 ) ;
F_942 ( V_16 ) ;
if ( F_60 ( V_16 ) -> V_753 == 0 )
return;
if ( F_105 ( V_16 ) || F_106 ( V_16 ) ) {
bool V_1415 = ! ! ( F_11 ( V_179 ) &
V_978 ) ;
if ( V_2 -> V_835 . V_836 != V_1415 ) {
F_151 ( L_306 ,
V_1415 ? L_76 : L_77 ,
V_2 -> V_835 . V_836 ? L_76 : L_77 ) ;
V_2 -> V_835 . V_836 = V_1415 ;
}
}
F_919 ( V_16 ) ;
F_943 ( V_16 ) ;
if ( F_33 ( V_16 ) ) {
V_16 -> V_741 . V_1416 = 2048 ;
V_16 -> V_741 . V_1417 = 2048 ;
} else if ( F_944 ( V_16 ) ) {
V_16 -> V_741 . V_1416 = 4096 ;
V_16 -> V_741 . V_1417 = 4096 ;
} else {
V_16 -> V_741 . V_1416 = 8192 ;
V_16 -> V_741 . V_1417 = 8192 ;
}
if ( F_82 ( V_16 ) || F_83 ( V_16 ) ) {
V_16 -> V_741 . V_1418 = F_82 ( V_16 ) ? 64 : 512 ;
V_16 -> V_741 . V_1419 = 1023 ;
} else if ( F_33 ( V_16 ) ) {
V_16 -> V_741 . V_1418 = V_1420 ;
V_16 -> V_741 . V_1419 = V_1421 ;
} else {
V_16 -> V_741 . V_1418 = V_1422 ;
V_16 -> V_741 . V_1419 = V_1423 ;
}
V_16 -> V_741 . V_1424 = V_2 -> V_353 . V_1425 ;
F_151 ( L_307 ,
F_60 ( V_16 ) -> V_753 ,
F_60 ( V_16 ) -> V_753 > 1 ? L_308 : L_309 ) ;
F_92 (dev_priv, pipe) {
F_879 ( V_16 , V_119 ) ;
F_94 (dev_priv, pipe, sprite) {
V_307 = F_945 ( V_16 , V_119 , V_174 ) ;
if ( V_307 )
F_151 ( L_310 ,
F_80 ( V_119 ) , F_97 ( V_119 , V_174 ) , V_307 ) ;
}
}
F_14 ( V_2 ) ;
F_431 ( V_16 ) ;
F_850 ( V_16 ) ;
F_932 ( V_16 ) ;
F_890 ( V_16 ) ;
F_946 ( V_2 ) ;
F_266 ( V_16 ) ;
F_947 ( V_16 ) ;
F_276 ( V_16 ) ;
F_139 (dev, crtc) {
struct V_347 V_348 = {} ;
if ( ! V_38 -> V_112 )
continue;
V_2 -> V_453 . V_1383 ( V_38 ,
& V_348 ) ;
F_213 ( V_38 , & V_348 ) ;
}
}
static void F_948 ( struct V_15 * V_16 )
{
struct V_748 * V_47 ;
struct V_46 * V_1426 = NULL ;
struct V_1115 V_1122 ;
struct V_742 * V_743 = V_16 -> V_741 . V_744 ;
F_782 (dev, connector) {
if ( V_47 -> V_42 -> type == V_64 ) {
V_1426 = & V_47 -> V_40 ;
break;
}
}
if ( ! V_1426 )
return;
if ( F_686 ( V_1426 , NULL , & V_1122 , V_743 ) )
F_692 ( V_1426 , & V_1122 , V_743 ) ;
}
static bool
F_949 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_10 ;
if ( F_60 ( V_16 ) -> V_753 == 1 )
return true ;
V_10 = F_11 ( F_89 ( ! V_38 -> V_169 ) ) ;
if ( ( V_10 & V_170 ) &&
( ! ! ( V_10 & V_172 ) == V_38 -> V_119 ) )
return false ;
return true ;
}
static bool F_950 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_41 * V_42 ;
F_21 (dev, &crtc->base, encoder)
return true ;
return false ;
}
static void F_951 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_40 . V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_9 ;
V_9 = F_61 ( V_38 -> V_115 -> V_121 ) ;
F_128 ( V_9 , F_11 ( V_9 ) & ~ V_1427 ) ;
F_952 ( & V_38 -> V_40 ) ;
if ( V_38 -> V_112 ) {
struct V_363 * V_169 ;
F_394 ( & V_38 -> V_40 ) ;
F_953 (dev, crtc, plane) {
if ( V_169 -> V_40 . type == V_1223 )
continue;
V_169 -> V_367 ( & V_169 -> V_40 , & V_38 -> V_40 ) ;
}
}
if ( F_60 ( V_16 ) -> V_127 < 4 && ! F_949 ( V_38 ) ) {
bool V_169 ;
F_151 ( L_311 ,
V_38 -> V_40 . V_40 . V_240 ) ;
V_169 = V_38 -> V_169 ;
F_218 ( V_38 -> V_40 . V_113 -> V_36 ) -> V_365 = true ;
V_38 -> V_169 = ! V_169 ;
F_480 ( & V_38 -> V_40 ) ;
V_38 -> V_169 = V_169 ;
}
if ( V_2 -> V_165 & V_166 &&
V_38 -> V_119 == V_148 && ! V_38 -> V_112 ) {
F_948 ( V_16 ) ;
}
if ( ! F_950 ( V_38 ) )
F_480 ( & V_38 -> V_40 ) ;
if ( V_38 -> V_112 != V_38 -> V_40 . V_36 -> V_112 ) {
struct V_41 * V_42 ;
F_151 ( L_312 ,
V_38 -> V_40 . V_40 . V_240 ,
V_38 -> V_40 . V_36 -> V_242 ? L_220 : L_221 ,
V_38 -> V_112 ? L_220 : L_221 ) ;
F_9 ( F_954 ( V_38 -> V_40 . V_36 , NULL ) < 0 ) ;
V_38 -> V_40 . V_36 -> V_112 = V_38 -> V_112 ;
V_38 -> V_40 . V_129 = V_38 -> V_112 ;
F_9 ( V_38 -> V_112 ) ;
F_21 (dev, &crtc->base, encoder)
V_42 -> V_40 . V_38 = NULL ;
}
if ( V_38 -> V_112 || F_169 ( V_16 ) ) {
V_38 -> V_1428 = true ;
V_38 -> V_1429 = true ;
}
}
static void F_955 ( struct V_41 * V_42 )
{
struct V_748 * V_47 ;
struct V_15 * V_16 = V_42 -> V_40 . V_16 ;
bool V_112 = false ;
bool V_1430 = V_42 -> V_40 . V_38 &&
F_50 ( V_42 -> V_40 . V_38 ) -> V_112 ;
F_782 (dev, connector) {
if ( V_47 -> V_40 . V_42 != & V_42 -> V_40 )
continue;
V_112 = true ;
break;
}
if ( V_112 && ! V_1430 ) {
F_151 ( L_313 ,
V_42 -> V_40 . V_40 . V_240 ,
V_42 -> V_40 . V_8 ) ;
if ( V_42 -> V_40 . V_38 ) {
F_151 ( L_314 ,
V_42 -> V_40 . V_40 . V_240 ,
V_42 -> V_40 . V_8 ) ;
V_42 -> V_243 ( V_42 ) ;
if ( V_42 -> V_613 )
V_42 -> V_613 ( V_42 ) ;
}
V_42 -> V_40 . V_38 = NULL ;
F_782 (dev, connector) {
if ( V_47 -> V_42 != V_42 )
continue;
V_47 -> V_40 . V_1121 = V_1431 ;
V_47 -> V_40 . V_42 = NULL ;
}
}
}
void F_956 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_1403 = F_933 ( V_16 ) ;
if ( ! ( F_11 ( V_1403 ) & V_1408 ) ) {
F_151 ( L_315 ) ;
F_932 ( V_16 ) ;
}
}
void F_957 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! F_86 ( V_2 , V_1432 ) )
return;
F_956 ( V_16 ) ;
}
static bool F_958 ( struct V_363 * V_169 )
{
struct V_1 * V_2 = F_203 ( V_169 -> V_40 . V_16 ) ;
return F_11 ( F_89 ( V_169 -> V_169 ) ) & V_170 ;
}
static void F_959 ( struct V_37 * V_38 )
{
struct V_299 * V_113 = V_38 -> V_40 . V_113 ;
struct V_435 * V_277 =
F_218 ( V_113 -> V_36 ) ;
V_277 -> V_365 =
F_958 ( F_214 ( V_113 ) ) ;
if ( V_277 -> V_365 )
V_38 -> V_40 . V_36 -> V_366 |= 1 << F_219 ( V_113 ) ;
}
static void F_960 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 ;
struct V_37 * V_38 ;
struct V_41 * V_42 ;
struct V_748 * V_47 ;
int V_50 ;
F_139 (dev, crtc) {
F_819 ( & V_38 -> V_40 , V_38 -> V_40 . V_36 ) ;
memset ( V_38 -> V_115 , 0 , sizeof( * V_38 -> V_115 ) ) ;
V_38 -> V_115 -> V_40 . V_38 = & V_38 -> V_40 ;
V_38 -> V_112 = V_2 -> V_453 . V_1279 ( V_38 ,
V_38 -> V_115 ) ;
V_38 -> V_40 . V_36 -> V_112 = V_38 -> V_112 ;
V_38 -> V_40 . V_129 = V_38 -> V_112 ;
F_959 ( V_38 ) ;
F_151 ( L_316 ,
V_38 -> V_40 . V_40 . V_240 ,
V_38 -> V_112 ? L_220 : L_221 ) ;
}
for ( V_50 = 0 ; V_50 < V_2 -> V_547 ; V_50 ++ ) {
struct V_134 * V_137 = & V_2 -> V_136 [ V_50 ] ;
V_137 -> V_238 = V_137 -> V_140 ( V_2 , V_137 ,
& V_137 -> V_115 . V_139 ) ;
V_137 -> V_112 = 0 ;
V_137 -> V_115 . V_237 = 0 ;
F_139 (dev, crtc) {
if ( V_38 -> V_112 && F_68 ( V_38 ) == V_137 ) {
V_137 -> V_112 ++ ;
V_137 -> V_115 . V_237 |= 1 << V_38 -> V_119 ;
}
}
F_151 ( L_317 ,
V_137 -> V_8 , V_137 -> V_115 . V_237 , V_137 -> V_238 ) ;
if ( V_137 -> V_115 . V_237 )
F_153 ( V_2 , V_241 ) ;
}
F_593 (dev, encoder) {
V_119 = 0 ;
if ( V_42 -> V_140 ( V_42 , & V_119 ) ) {
V_38 = F_50 ( V_2 -> V_120 [ V_119 ] ) ;
V_42 -> V_40 . V_38 = & V_38 -> V_40 ;
V_42 -> V_1280 ( V_42 , V_38 -> V_115 ) ;
} else {
V_42 -> V_40 . V_38 = NULL ;
}
F_151 ( L_318 ,
V_42 -> V_40 . V_40 . V_240 ,
V_42 -> V_40 . V_8 ,
V_42 -> V_40 . V_38 ? L_220 : L_221 ,
F_80 ( V_119 ) ) ;
}
F_782 (dev, connector) {
if ( V_47 -> V_140 ( V_47 ) ) {
V_47 -> V_40 . V_1121 = V_1123 ;
V_47 -> V_40 . V_42 = & V_47 -> V_42 -> V_40 ;
} else {
V_47 -> V_40 . V_1121 = V_1431 ;
V_47 -> V_40 . V_42 = NULL ;
}
F_151 ( L_319 ,
V_47 -> V_40 . V_40 . V_240 ,
V_47 -> V_40 . V_8 ,
V_47 -> V_40 . V_42 ? L_220 : L_221 ) ;
}
F_139 (dev, crtc) {
V_38 -> V_40 . V_1257 = V_38 -> V_115 -> V_40 . V_116 ;
memset ( & V_38 -> V_40 . V_449 , 0 , sizeof( V_38 -> V_40 . V_449 ) ) ;
if ( V_38 -> V_40 . V_36 -> V_112 ) {
F_580 ( & V_38 -> V_40 . V_449 , V_38 -> V_115 ) ;
F_580 ( & V_38 -> V_40 . V_36 -> V_116 , V_38 -> V_115 ) ;
F_9 ( F_954 ( V_38 -> V_40 . V_36 , & V_38 -> V_40 . V_449 ) ) ;
V_38 -> V_40 . V_36 -> V_449 . V_1290 = V_1433 ;
F_961 ( & V_38 -> V_40 , & V_38 -> V_40 . V_1257 ) ;
F_824 ( V_38 ) ;
}
}
}
static void
F_947 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
enum V_119 V_119 ;
struct V_37 * V_38 ;
struct V_41 * V_42 ;
int V_50 ;
F_960 ( V_16 ) ;
F_593 (dev, encoder) {
F_955 ( V_42 ) ;
}
F_92 (dev_priv, pipe) {
V_38 = F_50 ( V_2 -> V_120 [ V_119 ] ) ;
F_951 ( V_38 ) ;
F_787 ( V_38 , V_38 -> V_115 ,
L_320 ) ;
}
F_781 ( V_16 ) ;
for ( V_50 = 0 ; V_50 < V_2 -> V_547 ; V_50 ++ ) {
struct V_134 * V_137 = & V_2 -> V_136 [ V_50 ] ;
if ( ! V_137 -> V_238 || V_137 -> V_112 )
continue;
F_151 ( L_321 , V_137 -> V_8 ) ;
V_137 -> V_243 ( V_2 , V_137 ) ;
V_137 -> V_238 = false ;
}
if ( F_13 ( V_16 ) )
F_962 ( V_16 ) ;
else if ( F_963 ( V_16 ) )
F_964 ( V_16 ) ;
else if ( F_10 ( V_16 ) )
F_965 ( V_16 ) ;
F_139 (dev, crtc) {
unsigned long V_647 ;
V_647 = F_421 ( & V_38 -> V_40 ) ;
if ( F_9 ( V_647 ) )
F_423 ( V_2 , V_647 ) ;
}
F_966 ( V_2 , false ) ;
}
void F_274 ( struct V_15 * V_16 )
{
struct V_45 * V_36 = F_482 ( V_16 ) ;
struct V_748 * V_1434 ;
struct V_363 * V_169 ;
struct V_111 * V_38 ;
int V_307 ;
if ( ! V_36 )
return;
V_36 -> V_744 = V_16 -> V_741 . V_744 ;
F_348 ( V_36 ) ;
F_216 (dev, crtc) {
struct V_35 * V_44 =
F_483 ( V_36 , V_38 ) ;
V_307 = F_484 ( V_44 ) ;
if ( V_307 )
goto V_98;
V_44 -> V_1214 = true ;
}
F_967 (dev, plane) {
V_307 = F_484 ( F_682 ( V_36 , & V_169 -> V_40 ) ) ;
if ( V_307 )
goto V_98;
}
F_782 (dev, conn) {
V_307 = F_484 ( F_689 ( V_36 , & V_1434 -> V_40 ) ) ;
if ( V_307 )
goto V_98;
}
F_947 ( V_16 ) ;
F_957 ( V_16 ) ;
V_307 = F_485 ( V_36 ) ;
if ( ! V_307 )
return;
V_98:
F_131 ( L_322 , V_307 ) ;
F_486 ( V_36 ) ;
}
void F_968 ( struct V_15 * V_16 )
{
struct V_111 * V_362 ;
struct V_304 * V_305 ;
int V_307 ;
F_2 ( & V_16 -> V_308 ) ;
F_969 ( V_16 ) ;
F_4 ( & V_16 -> V_308 ) ;
F_271 ( V_16 ) ;
F_970 ( V_16 ) ;
F_216 (dev, c) {
V_305 = F_189 ( V_362 -> V_113 -> V_114 ) ;
if ( V_305 == NULL )
continue;
F_2 ( & V_16 -> V_308 ) ;
V_307 = F_188 ( V_362 -> V_113 ,
V_362 -> V_113 -> V_114 ,
V_362 -> V_113 -> V_36 ,
NULL , NULL ) ;
F_4 ( & V_16 -> V_308 ) ;
if ( V_307 ) {
F_131 ( L_323 ,
F_50 ( V_362 ) -> V_119 ) ;
F_211 ( V_362 -> V_113 -> V_114 ) ;
V_362 -> V_113 -> V_114 = NULL ;
V_362 -> V_113 -> V_38 = V_362 -> V_113 -> V_36 -> V_38 = NULL ;
F_210 ( V_362 -> V_113 ) ;
V_362 -> V_36 -> V_366 &= ~ ( 1 << F_219 ( V_362 -> V_113 ) ) ;
}
}
F_971 ( V_16 ) ;
}
void F_972 ( struct V_748 * V_748 )
{
struct V_46 * V_47 = & V_748 -> V_40 ;
F_973 ( V_47 ) ;
F_974 ( V_47 ) ;
}
void F_975 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_46 * V_47 ;
F_976 ( V_16 ) ;
F_977 ( V_16 ) ;
F_978 ( V_2 ) ;
F_979 ( V_16 ) ;
F_980 () ;
F_946 ( V_2 ) ;
F_981 () ;
F_790 (connector, &dev->mode_config.connector_list, head) {
struct V_748 * V_748 ;
V_748 = F_785 ( V_47 ) ;
V_748 -> V_1435 ( V_748 ) ;
}
F_982 ( V_16 ) ;
F_983 ( V_16 ) ;
F_2 ( & V_16 -> V_308 ) ;
F_984 ( V_16 ) ;
F_4 ( & V_16 -> V_308 ) ;
}
struct V_747 * F_985 ( struct V_46 * V_47 )
{
return & F_687 ( V_47 ) -> V_40 ;
}
void F_986 ( struct V_748 * V_47 ,
struct V_41 * V_42 )
{
V_47 -> V_42 = V_42 ;
F_987 ( & V_47 -> V_40 ,
& V_42 -> V_40 ) ;
}
int F_988 ( struct V_15 * V_16 , bool V_36 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
unsigned V_9 = F_60 ( V_16 ) -> V_127 >= 6 ? V_1436 : V_1437 ;
T_5 V_1438 ;
if ( F_518 ( V_2 -> V_1439 , V_9 , & V_1438 ) ) {
F_131 ( L_324 ) ;
return - V_1211 ;
}
if ( ! ! ( V_1438 & V_1440 ) == ! V_36 )
return 0 ;
if ( V_36 )
V_1438 &= ~ V_1440 ;
else
V_1438 |= V_1440 ;
if ( F_989 ( V_2 -> V_1439 , V_9 , V_1438 ) ) {
F_131 ( L_325 ) ;
return - V_1211 ;
}
return 0 ;
}
struct V_1441 *
F_990 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_1441 * error ;
int V_1442 [] = {
V_255 ,
V_1443 ,
V_1444 ,
V_607 ,
} ;
int V_50 ;
if ( F_60 ( V_16 ) -> V_753 == 0 )
return NULL ;
error = F_491 ( sizeof( * error ) , V_1445 ) ;
if ( error == NULL )
return NULL ;
if ( F_234 ( V_16 ) || F_235 ( V_16 ) )
error -> V_1446 = F_11 ( V_1026 ) ;
F_92 (dev_priv, i) {
error -> V_119 [ V_50 ] . V_1447 =
F_991 ( V_2 ,
F_419 ( V_50 ) ) ;
if ( ! error -> V_119 [ V_50 ] . V_1447 )
continue;
error -> V_1091 [ V_50 ] . V_616 = F_11 ( F_84 ( V_50 ) ) ;
error -> V_1091 [ V_50 ] . V_1448 = F_11 ( F_666 ( V_50 ) ) ;
error -> V_1091 [ V_50 ] . V_40 = F_11 ( F_663 ( V_50 ) ) ;
error -> V_169 [ V_50 ] . V_616 = F_11 ( F_89 ( V_50 ) ) ;
error -> V_169 [ V_50 ] . V_357 = F_11 ( F_230 ( V_50 ) ) ;
if ( F_60 ( V_16 ) -> V_127 <= 3 ) {
error -> V_169 [ V_50 ] . V_294 = F_11 ( F_224 ( V_50 ) ) ;
error -> V_169 [ V_50 ] . V_570 = F_11 ( F_225 ( V_50 ) ) ;
}
if ( F_60 ( V_16 ) -> V_127 <= 7 && ! F_234 ( V_16 ) )
error -> V_169 [ V_50 ] . V_1196 = F_11 ( F_223 ( V_50 ) ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
error -> V_169 [ V_50 ] . V_1449 = F_11 ( F_222 ( V_50 ) ) ;
error -> V_169 [ V_50 ] . V_1450 = F_11 ( F_231 ( V_50 ) ) ;
}
error -> V_119 [ V_50 ] . V_1451 = F_11 ( F_285 ( V_50 ) ) ;
if ( F_169 ( V_16 ) )
error -> V_119 [ V_50 ] . V_1452 = F_11 ( F_992 ( V_50 ) ) ;
}
error -> V_1453 = F_60 ( V_16 ) -> V_753 ;
if ( F_71 ( V_2 -> V_16 ) )
error -> V_1453 ++ ;
for ( V_50 = 0 ; V_50 < error -> V_1453 ; V_50 ++ ) {
enum V_118 V_121 = V_1442 [ V_50 ] ;
error -> V_118 [ V_50 ] . V_1447 =
F_991 ( V_2 ,
F_87 ( V_121 ) ) ;
if ( ! error -> V_118 [ V_50 ] . V_1447 )
continue;
error -> V_118 [ V_50 ] . V_121 = V_121 ;
error -> V_118 [ V_50 ] . V_1454 = F_11 ( F_61 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_927 = F_11 ( F_325 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_1455 = F_11 ( F_327 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_934 = F_11 ( F_329 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_930 = F_11 ( F_331 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_1456 = F_11 ( F_333 ( V_121 ) ) ;
error -> V_118 [ V_50 ] . V_1150 = F_11 ( F_335 ( V_121 ) ) ;
}
return error ;
}
void
F_993 ( struct V_1457 * V_79 ,
struct V_15 * V_16 ,
struct V_1441 * error )
{
struct V_1 * V_2 = V_16 -> V_17 ;
int V_50 ;
if ( ! error )
return;
F_994 ( V_79 , L_326 , F_60 ( V_16 ) -> V_753 ) ;
if ( F_234 ( V_16 ) || F_235 ( V_16 ) )
F_994 ( V_79 , L_327 ,
error -> V_1446 ) ;
F_92 (dev_priv, i) {
F_994 ( V_79 , L_328 , V_50 ) ;
F_994 ( V_79 , L_329 ,
error -> V_119 [ V_50 ] . V_1447 ? L_14 : L_15 ) ;
F_994 ( V_79 , L_330 , error -> V_119 [ V_50 ] . V_1451 ) ;
F_994 ( V_79 , L_331 , error -> V_119 [ V_50 ] . V_1452 ) ;
F_994 ( V_79 , L_332 , V_50 ) ;
F_994 ( V_79 , L_333 , error -> V_169 [ V_50 ] . V_616 ) ;
F_994 ( V_79 , L_334 , error -> V_169 [ V_50 ] . V_357 ) ;
if ( F_60 ( V_16 ) -> V_127 <= 3 ) {
F_994 ( V_79 , L_335 , error -> V_169 [ V_50 ] . V_294 ) ;
F_994 ( V_79 , L_336 , error -> V_169 [ V_50 ] . V_570 ) ;
}
if ( F_60 ( V_16 ) -> V_127 <= 7 && ! F_234 ( V_16 ) )
F_994 ( V_79 , L_337 , error -> V_169 [ V_50 ] . V_1196 ) ;
if ( F_60 ( V_16 ) -> V_127 >= 4 ) {
F_994 ( V_79 , L_338 , error -> V_169 [ V_50 ] . V_1449 ) ;
F_994 ( V_79 , L_339 , error -> V_169 [ V_50 ] . V_1450 ) ;
}
F_994 ( V_79 , L_340 , V_50 ) ;
F_994 ( V_79 , L_333 , error -> V_1091 [ V_50 ] . V_616 ) ;
F_994 ( V_79 , L_336 , error -> V_1091 [ V_50 ] . V_1448 ) ;
F_994 ( V_79 , L_341 , error -> V_1091 [ V_50 ] . V_40 ) ;
}
for ( V_50 = 0 ; V_50 < error -> V_1453 ; V_50 ++ ) {
F_994 ( V_79 , L_342 ,
F_788 ( error -> V_118 [ V_50 ] . V_121 ) ) ;
F_994 ( V_79 , L_329 ,
error -> V_118 [ V_50 ] . V_1447 ? L_14 : L_15 ) ;
F_994 ( V_79 , L_343 , error -> V_118 [ V_50 ] . V_1454 ) ;
F_994 ( V_79 , L_344 , error -> V_118 [ V_50 ] . V_927 ) ;
F_994 ( V_79 , L_345 , error -> V_118 [ V_50 ] . V_1455 ) ;
F_994 ( V_79 , L_346 , error -> V_118 [ V_50 ] . V_934 ) ;
F_994 ( V_79 , L_347 , error -> V_118 [ V_50 ] . V_930 ) ;
F_994 ( V_79 , L_348 , error -> V_118 [ V_50 ] . V_1456 ) ;
F_994 ( V_79 , L_349 , error -> V_118 [ V_50 ] . V_1150 ) ;
}
}
void F_995 ( struct V_15 * V_16 , struct V_1328 * V_1329 )
{
struct V_37 * V_38 ;
F_139 (dev, crtc) {
struct V_501 * V_502 ;
F_272 ( & V_16 -> V_463 ) ;
V_502 = V_38 -> V_464 ;
if ( V_502 && V_502 -> V_503 &&
V_502 -> V_503 -> V_40 . V_1458 == V_1329 ) {
F_215 ( V_502 -> V_503 ) ;
V_502 -> V_503 = NULL ;
}
F_273 ( & V_16 -> V_463 ) ;
}
}
