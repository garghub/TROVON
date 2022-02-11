static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
if ( ! V_3 -> V_5 )
return V_3 -> V_6 ;
else
return & V_3 -> V_5 -> V_7 [ V_4 ] -> V_8 ;
}
int
F_2 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
F_3 ( ! F_4 ( V_10 ) ) ;
return F_5 ( V_14 ) & V_15 ;
}
static inline T_1
F_6 ( struct V_9 * V_10 )
{
if ( F_7 ( V_10 ) ) {
struct V_11 * V_12 = V_10 -> V_13 ;
return ( F_5 ( V_16 ) & V_17 ) + 2 ;
} else
return 27 ;
}
static void F_8 ( int V_18 , T_2 * clock )
{
clock -> V_19 = clock -> V_20 * clock -> V_21 ;
clock -> V_22 = clock -> V_23 * clock -> V_24 ;
if ( F_3 ( clock -> V_25 == 0 || clock -> V_22 == 0 ) )
return;
clock -> V_26 = F_9 ( V_18 * clock -> V_19 , clock -> V_25 ) ;
clock -> V_27 = F_9 ( clock -> V_26 , clock -> V_22 ) ;
}
bool F_10 ( struct V_28 * V_29 , enum V_30 type )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_6 ;
F_11 (dev, &crtc->base, encoder)
if ( V_6 -> type == type )
return true ;
return false ;
}
static bool F_12 ( const struct V_31 * V_32 ,
int type )
{
struct V_33 * V_34 = V_32 -> V_8 . V_34 ;
struct V_35 * V_36 ;
struct V_1 * V_6 ;
int V_37 , V_38 = 0 ;
for ( V_37 = 0 ; V_37 < V_34 -> V_39 ; V_37 ++ ) {
if ( ! V_34 -> V_40 [ V_37 ] )
continue;
V_36 = V_34 -> V_41 [ V_37 ] ;
if ( V_36 -> V_29 != V_32 -> V_8 . V_29 )
continue;
V_38 ++ ;
V_6 = F_13 ( V_36 -> V_42 ) ;
if ( V_6 -> type == type )
return true ;
}
F_3 ( V_38 == 0 ) ;
return false ;
}
static const T_3 *
F_14 ( struct V_31 * V_32 , int V_18 )
{
struct V_9 * V_10 = V_32 -> V_8 . V_29 -> V_10 ;
const T_3 * V_43 ;
if ( F_12 ( V_32 , V_44 ) ) {
if ( F_15 ( V_10 ) ) {
if ( V_18 == 100000 )
V_43 = & V_45 ;
else
V_43 = & V_46 ;
} else {
if ( V_18 == 100000 )
V_43 = & V_47 ;
else
V_43 = & V_48 ;
}
} else
V_43 = & V_49 ;
return V_43 ;
}
static const T_3 *
F_16 ( struct V_31 * V_32 )
{
struct V_9 * V_10 = V_32 -> V_8 . V_29 -> V_10 ;
const T_3 * V_43 ;
if ( F_12 ( V_32 , V_44 ) ) {
if ( F_15 ( V_10 ) )
V_43 = & V_50 ;
else
V_43 = & V_51 ;
} else if ( F_12 ( V_32 , V_52 ) ||
F_12 ( V_32 , V_53 ) ) {
V_43 = & V_54 ;
} else if ( F_12 ( V_32 , V_55 ) ) {
V_43 = & V_56 ;
} else
V_43 = & V_57 ;
return V_43 ;
}
static const T_3 *
F_17 ( struct V_31 * V_32 , int V_18 )
{
struct V_9 * V_10 = V_32 -> V_8 . V_29 -> V_10 ;
const T_3 * V_43 ;
if ( F_4 ( V_10 ) )
V_43 = F_14 ( V_32 , V_18 ) ;
else if ( F_18 ( V_10 ) ) {
V_43 = F_16 ( V_32 ) ;
} else if ( F_19 ( V_10 ) ) {
if ( F_12 ( V_32 , V_44 ) )
V_43 = & V_58 ;
else
V_43 = & V_59 ;
} else if ( F_20 ( V_10 ) ) {
V_43 = & V_60 ;
} else if ( F_21 ( V_10 ) ) {
V_43 = & V_61 ;
} else if ( ! F_22 ( V_10 ) ) {
if ( F_12 ( V_32 , V_44 ) )
V_43 = & V_62 ;
else
V_43 = & V_57 ;
} else {
if ( F_12 ( V_32 , V_44 ) )
V_43 = & V_63 ;
else if ( F_12 ( V_32 , V_64 ) )
V_43 = & V_65 ;
else
V_43 = & V_66 ;
}
return V_43 ;
}
static void F_23 ( int V_18 , T_2 * clock )
{
clock -> V_19 = clock -> V_21 + 2 ;
clock -> V_22 = clock -> V_23 * clock -> V_24 ;
if ( F_3 ( clock -> V_25 == 0 || clock -> V_22 == 0 ) )
return;
clock -> V_26 = F_9 ( V_18 * clock -> V_19 , clock -> V_25 ) ;
clock -> V_27 = F_9 ( clock -> V_26 , clock -> V_22 ) ;
}
static T_4 F_24 ( struct V_67 * V_67 )
{
return 5 * ( V_67 -> V_20 + 2 ) + ( V_67 -> V_21 + 2 ) ;
}
static void F_25 ( int V_18 , T_2 * clock )
{
clock -> V_19 = F_24 ( clock ) ;
clock -> V_22 = clock -> V_23 * clock -> V_24 ;
if ( F_3 ( clock -> V_25 + 2 == 0 || clock -> V_22 == 0 ) )
return;
clock -> V_26 = F_9 ( V_18 * clock -> V_19 , clock -> V_25 + 2 ) ;
clock -> V_27 = F_9 ( clock -> V_26 , clock -> V_22 ) ;
}
static void F_26 ( int V_18 , T_2 * clock )
{
clock -> V_19 = clock -> V_20 * clock -> V_21 ;
clock -> V_22 = clock -> V_23 * clock -> V_24 ;
if ( F_3 ( clock -> V_25 == 0 || clock -> V_22 == 0 ) )
return;
clock -> V_26 = F_27 ( ( V_68 ) V_18 * clock -> V_19 ,
clock -> V_25 << 22 ) ;
clock -> V_27 = F_9 ( clock -> V_26 , clock -> V_22 ) ;
}
static bool F_28 ( struct V_9 * V_10 ,
const T_3 * V_43 ,
const T_2 * clock )
{
if ( clock -> V_25 < V_43 -> V_25 . V_69 || V_43 -> V_25 . V_70 < clock -> V_25 )
F_29 ( L_1 ) ;
if ( clock -> V_23 < V_43 -> V_23 . V_69 || V_43 -> V_23 . V_70 < clock -> V_23 )
F_29 ( L_2 ) ;
if ( clock -> V_21 < V_43 -> V_21 . V_69 || V_43 -> V_21 . V_70 < clock -> V_21 )
F_29 ( L_3 ) ;
if ( clock -> V_20 < V_43 -> V_20 . V_69 || V_43 -> V_20 . V_70 < clock -> V_20 )
F_29 ( L_4 ) ;
if ( ! F_19 ( V_10 ) && ! F_21 ( V_10 ) )
if ( clock -> V_20 <= clock -> V_21 )
F_29 ( L_5 ) ;
if ( ! F_21 ( V_10 ) ) {
if ( clock -> V_22 < V_43 -> V_22 . V_69 || V_43 -> V_22 . V_70 < clock -> V_22 )
F_29 ( L_6 ) ;
if ( clock -> V_19 < V_43 -> V_19 . V_69 || V_43 -> V_19 . V_70 < clock -> V_19 )
F_29 ( L_7 ) ;
}
if ( clock -> V_26 < V_43 -> V_26 . V_69 || V_43 -> V_26 . V_70 < clock -> V_26 )
F_29 ( L_8 ) ;
if ( clock -> V_27 < V_43 -> V_27 . V_69 || V_43 -> V_27 . V_70 < clock -> V_27 )
F_29 ( L_9 ) ;
return true ;
}
static bool
F_30 ( const T_3 * V_43 ,
struct V_31 * V_32 ,
int V_71 , int V_18 , T_2 * V_72 ,
T_2 * V_73 )
{
struct V_28 * V_29 = F_31 ( V_32 -> V_8 . V_29 ) ;
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock ;
int V_74 = V_71 ;
if ( F_12 ( V_32 , V_44 ) ) {
if ( F_15 ( V_10 ) )
clock . V_24 = V_43 -> V_24 . V_75 ;
else
clock . V_24 = V_43 -> V_24 . V_76 ;
} else {
if ( V_71 < V_43 -> V_24 . V_77 )
clock . V_24 = V_43 -> V_24 . V_76 ;
else
clock . V_24 = V_43 -> V_24 . V_75 ;
}
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
for ( clock . V_20 = V_43 -> V_20 . V_69 ; clock . V_20 <= V_43 -> V_20 . V_70 ;
clock . V_20 ++ ) {
for ( clock . V_21 = V_43 -> V_21 . V_69 ;
clock . V_21 <= V_43 -> V_21 . V_70 ; clock . V_21 ++ ) {
if ( clock . V_21 >= clock . V_20 )
break;
for ( clock . V_25 = V_43 -> V_25 . V_69 ;
clock . V_25 <= V_43 -> V_25 . V_70 ; clock . V_25 ++ ) {
for ( clock . V_23 = V_43 -> V_23 . V_69 ;
clock . V_23 <= V_43 -> V_23 . V_70 ; clock . V_23 ++ ) {
int V_78 ;
F_25 ( V_18 , & clock ) ;
if ( ! F_28 ( V_10 , V_43 ,
& clock ) )
continue;
if ( V_72 &&
clock . V_22 != V_72 -> V_22 )
continue;
V_78 = abs ( clock . V_27 - V_71 ) ;
if ( V_78 < V_74 ) {
* V_73 = clock ;
V_74 = V_78 ;
}
}
}
}
}
return ( V_74 != V_71 ) ;
}
static bool
F_32 ( const T_3 * V_43 ,
struct V_31 * V_32 ,
int V_71 , int V_18 , T_2 * V_72 ,
T_2 * V_73 )
{
struct V_28 * V_29 = F_31 ( V_32 -> V_8 . V_29 ) ;
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock ;
int V_74 = V_71 ;
if ( F_12 ( V_32 , V_44 ) ) {
if ( F_15 ( V_10 ) )
clock . V_24 = V_43 -> V_24 . V_75 ;
else
clock . V_24 = V_43 -> V_24 . V_76 ;
} else {
if ( V_71 < V_43 -> V_24 . V_77 )
clock . V_24 = V_43 -> V_24 . V_76 ;
else
clock . V_24 = V_43 -> V_24 . V_75 ;
}
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
for ( clock . V_20 = V_43 -> V_20 . V_69 ; clock . V_20 <= V_43 -> V_20 . V_70 ;
clock . V_20 ++ ) {
for ( clock . V_21 = V_43 -> V_21 . V_69 ;
clock . V_21 <= V_43 -> V_21 . V_70 ; clock . V_21 ++ ) {
for ( clock . V_25 = V_43 -> V_25 . V_69 ;
clock . V_25 <= V_43 -> V_25 . V_70 ; clock . V_25 ++ ) {
for ( clock . V_23 = V_43 -> V_23 . V_69 ;
clock . V_23 <= V_43 -> V_23 . V_70 ; clock . V_23 ++ ) {
int V_78 ;
F_23 ( V_18 , & clock ) ;
if ( ! F_28 ( V_10 , V_43 ,
& clock ) )
continue;
if ( V_72 &&
clock . V_22 != V_72 -> V_22 )
continue;
V_78 = abs ( clock . V_27 - V_71 ) ;
if ( V_78 < V_74 ) {
* V_73 = clock ;
V_74 = V_78 ;
}
}
}
}
}
return ( V_74 != V_71 ) ;
}
static bool
F_33 ( const T_3 * V_43 ,
struct V_31 * V_32 ,
int V_71 , int V_18 , T_2 * V_72 ,
T_2 * V_73 )
{
struct V_28 * V_29 = F_31 ( V_32 -> V_8 . V_29 ) ;
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock ;
int V_79 ;
bool V_80 ;
int V_81 = ( V_71 >> 8 ) + ( V_71 >> 9 ) ;
V_80 = false ;
if ( F_12 ( V_32 , V_44 ) ) {
if ( F_15 ( V_10 ) )
clock . V_24 = V_43 -> V_24 . V_75 ;
else
clock . V_24 = V_43 -> V_24 . V_76 ;
} else {
if ( V_71 < V_43 -> V_24 . V_77 )
clock . V_24 = V_43 -> V_24 . V_76 ;
else
clock . V_24 = V_43 -> V_24 . V_75 ;
}
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
V_79 = V_43 -> V_25 . V_70 ;
for ( clock . V_25 = V_43 -> V_25 . V_69 ; clock . V_25 <= V_79 ; clock . V_25 ++ ) {
for ( clock . V_20 = V_43 -> V_20 . V_70 ;
clock . V_20 >= V_43 -> V_20 . V_69 ; clock . V_20 -- ) {
for ( clock . V_21 = V_43 -> V_21 . V_70 ;
clock . V_21 >= V_43 -> V_21 . V_69 ; clock . V_21 -- ) {
for ( clock . V_23 = V_43 -> V_23 . V_70 ;
clock . V_23 >= V_43 -> V_23 . V_69 ; clock . V_23 -- ) {
int V_78 ;
F_25 ( V_18 , & clock ) ;
if ( ! F_28 ( V_10 , V_43 ,
& clock ) )
continue;
V_78 = abs ( clock . V_27 - V_71 ) ;
if ( V_78 < V_81 ) {
* V_73 = clock ;
V_81 = V_78 ;
V_79 = clock . V_25 ;
V_80 = true ;
}
}
}
}
}
return V_80 ;
}
static bool F_34 ( struct V_9 * V_10 , int V_82 ,
const T_2 * V_83 ,
const T_2 * V_73 ,
unsigned int V_84 ,
unsigned int * V_85 )
{
if ( F_20 ( V_10 ) ) {
* V_85 = 0 ;
return V_83 -> V_22 > V_73 -> V_22 ;
}
if ( F_35 ( ! V_82 ) )
return false ;
* V_85 = F_36 ( 1000000ULL *
abs ( V_82 - V_83 -> V_27 ) ,
V_82 ) ;
if ( * V_85 < 100 && V_83 -> V_22 > V_73 -> V_22 ) {
* V_85 = 0 ;
return true ;
}
return * V_85 + 10 < V_84 ;
}
static bool
F_37 ( const T_3 * V_43 ,
struct V_31 * V_32 ,
int V_71 , int V_18 , T_2 * V_72 ,
T_2 * V_73 )
{
struct V_28 * V_29 = F_31 ( V_32 -> V_8 . V_29 ) ;
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock ;
unsigned int V_86 = 1000000 ;
int V_79 = V_69 ( V_43 -> V_25 . V_70 , V_18 / 19200 ) ;
bool V_80 = false ;
V_71 *= 5 ;
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
for ( clock . V_25 = V_43 -> V_25 . V_69 ; clock . V_25 <= V_79 ; clock . V_25 ++ ) {
for ( clock . V_23 = V_43 -> V_23 . V_70 ; clock . V_23 >= V_43 -> V_23 . V_69 ; clock . V_23 -- ) {
for ( clock . V_24 = V_43 -> V_24 . V_75 ; clock . V_24 >= V_43 -> V_24 . V_76 ;
clock . V_24 -= clock . V_24 > 10 ? 2 : 1 ) {
clock . V_22 = clock . V_23 * clock . V_24 ;
for ( clock . V_20 = V_43 -> V_20 . V_69 ; clock . V_20 <= V_43 -> V_20 . V_70 ; clock . V_20 ++ ) {
unsigned int V_87 ;
clock . V_21 = F_9 ( V_71 * clock . V_22 * clock . V_25 ,
V_18 * clock . V_20 ) ;
F_8 ( V_18 , & clock ) ;
if ( ! F_28 ( V_10 , V_43 ,
& clock ) )
continue;
if ( ! F_34 ( V_10 , V_71 ,
& clock ,
V_73 ,
V_86 , & V_87 ) )
continue;
* V_73 = clock ;
V_86 = V_87 ;
V_80 = true ;
}
}
}
}
return V_80 ;
}
static bool
F_38 ( const T_3 * V_43 ,
struct V_31 * V_32 ,
int V_71 , int V_18 , T_2 * V_72 ,
T_2 * V_73 )
{
struct V_28 * V_29 = F_31 ( V_32 -> V_8 . V_29 ) ;
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
unsigned int V_84 ;
T_2 clock ;
V_68 V_21 ;
int V_80 = false ;
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
V_84 = 1000000 ;
clock . V_25 = 1 , clock . V_20 = 2 ;
V_71 *= 5 ;
for ( clock . V_23 = V_43 -> V_23 . V_70 ; clock . V_23 >= V_43 -> V_23 . V_69 ; clock . V_23 -- ) {
for ( clock . V_24 = V_43 -> V_24 . V_75 ;
clock . V_24 >= V_43 -> V_24 . V_76 ;
clock . V_24 -= clock . V_24 > 10 ? 2 : 1 ) {
unsigned int V_85 ;
clock . V_22 = clock . V_23 * clock . V_24 ;
V_21 = F_27 ( ( ( V_68 ) V_71 * clock . V_22 *
clock . V_25 ) << 22 , V_18 * clock . V_20 ) ;
if ( V_21 > V_88 / clock . V_20 )
continue;
clock . V_21 = V_21 ;
F_26 ( V_18 , & clock ) ;
if ( ! F_28 ( V_10 , V_43 , & clock ) )
continue;
if ( ! F_34 ( V_10 , V_71 , & clock , V_73 ,
V_84 , & V_85 ) )
continue;
* V_73 = clock ;
V_84 = V_85 ;
V_80 = true ;
}
}
return V_80 ;
}
bool F_39 ( struct V_89 * V_29 )
{
struct V_28 * V_28 = F_31 ( V_29 ) ;
return V_28 -> V_90 && V_29 -> V_91 -> V_34 -> V_92 &&
V_28 -> V_93 -> V_8 . V_94 . V_95 ;
}
enum V_96 F_40 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_89 * V_29 = V_12 -> V_97 [ V_4 ] ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
return V_28 -> V_93 -> V_98 ;
}
static bool F_41 ( struct V_9 * V_10 , enum V_4 V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_99 = F_42 ( V_4 ) ;
T_1 V_100 , V_101 ;
T_1 V_102 ;
if ( F_22 ( V_10 ) )
V_102 = V_103 ;
else
V_102 = V_104 ;
V_100 = F_5 ( V_99 ) & V_102 ;
F_43 ( 5 ) ;
V_101 = F_5 ( V_99 ) & V_102 ;
return V_100 == V_101 ;
}
static void F_44 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_96 V_98 = V_29 -> V_93 -> V_98 ;
enum V_4 V_4 = V_29 -> V_4 ;
if ( F_45 ( V_10 ) -> V_105 >= 4 ) {
int V_99 = F_46 ( V_98 ) ;
if ( F_47 ( ( F_5 ( V_99 ) & V_106 ) == 0 ,
100 ) )
F_48 ( 1 , L_10 ) ;
} else {
if ( F_47 ( F_41 ( V_10 , V_4 ) , 100 ) )
F_48 ( 1 , L_10 ) ;
}
}
bool F_49 ( struct V_11 * V_12 ,
struct V_107 * V_108 )
{
T_1 V_109 ;
if ( F_50 ( V_12 -> V_10 ) ) {
switch ( V_108 -> V_108 ) {
case V_110 :
V_109 = V_111 ;
break;
case V_112 :
V_109 = V_113 ;
break;
case V_114 :
V_109 = V_115 ;
break;
default:
return true ;
}
} else {
switch ( V_108 -> V_108 ) {
case V_110 :
V_109 = V_116 ;
break;
case V_112 :
V_109 = V_117 ;
break;
case V_114 :
V_109 = V_118 ;
break;
default:
return true ;
}
}
return F_5 ( V_119 ) & V_109 ;
}
static const char * F_51 ( bool V_120 )
{
return V_120 ? L_11 : L_12 ;
}
void F_52 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_34 )
{
int V_99 ;
T_1 V_121 ;
bool V_122 ;
V_99 = F_53 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_122 = ! ! ( V_121 & V_123 ) ;
F_54 ( V_122 != V_34 ,
L_13 ,
F_51 ( V_34 ) , F_51 ( V_122 ) ) ;
}
static void F_55 ( struct V_11 * V_12 , bool V_34 )
{
T_1 V_121 ;
bool V_122 ;
F_56 ( & V_12 -> V_124 ) ;
V_121 = F_57 ( V_12 , V_125 ) ;
F_58 ( & V_12 -> V_124 ) ;
V_122 = V_121 & V_126 ;
F_54 ( V_122 != V_34 ,
L_14 ,
F_51 ( V_34 ) , F_51 ( V_122 ) ) ;
}
struct V_127 *
F_59 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
if ( V_29 -> V_93 -> V_128 < 0 )
return NULL ;
return & V_12 -> V_129 [ V_29 -> V_93 -> V_128 ] ;
}
void F_60 ( struct V_11 * V_12 ,
struct V_127 * V_130 ,
bool V_34 )
{
bool V_122 ;
struct V_131 V_132 ;
if ( F_48 ( ! V_130 ,
L_15 , F_51 ( V_34 ) ) )
return;
V_122 = V_130 -> V_133 ( V_12 , V_130 , & V_132 ) ;
F_54 ( V_122 != V_34 ,
L_16 ,
V_130 -> V_134 , F_51 ( V_34 ) , F_51 ( V_122 ) ) ;
}
static void F_61 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_34 )
{
int V_99 ;
T_1 V_121 ;
bool V_122 ;
enum V_96 V_98 = F_40 ( V_12 ,
V_4 ) ;
if ( F_62 ( V_12 -> V_10 ) ) {
V_99 = F_63 ( V_98 ) ;
V_121 = F_5 ( V_99 ) ;
V_122 = ! ! ( V_121 & V_135 ) ;
} else {
V_99 = F_64 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_122 = ! ! ( V_121 & V_136 ) ;
}
F_54 ( V_122 != V_34 ,
L_17 ,
F_51 ( V_34 ) , F_51 ( V_122 ) ) ;
}
static void F_65 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_34 )
{
int V_99 ;
T_1 V_121 ;
bool V_122 ;
V_99 = F_66 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_122 = ! ! ( V_121 & V_137 ) ;
F_54 ( V_122 != V_34 ,
L_18 ,
F_51 ( V_34 ) , F_51 ( V_122 ) ) ;
}
static void F_67 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_99 ;
T_1 V_121 ;
if ( F_45 ( V_12 -> V_10 ) -> V_105 == 5 )
return;
if ( F_62 ( V_12 -> V_10 ) )
return;
V_99 = F_64 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
F_54 ( ! ( V_121 & V_138 ) , L_19 ) ;
}
void F_68 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_34 )
{
int V_99 ;
T_1 V_121 ;
bool V_122 ;
V_99 = F_66 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_122 = ! ! ( V_121 & V_139 ) ;
F_54 ( V_122 != V_34 ,
L_20 ,
F_51 ( V_34 ) , F_51 ( V_122 ) ) ;
}
void F_69 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_140 ;
T_1 V_121 ;
enum V_4 V_141 = V_142 ;
bool V_143 = true ;
if ( F_3 ( F_62 ( V_10 ) ) )
return;
if ( F_4 ( V_10 ) ) {
T_1 V_144 ;
V_140 = V_145 ;
V_144 = F_5 ( V_146 ) & V_147 ;
if ( V_144 == V_148 &&
F_5 ( V_149 ) & V_150 )
V_141 = V_151 ;
} else if ( F_21 ( V_10 ) ) {
V_140 = F_70 ( V_4 ) ;
V_141 = V_4 ;
} else {
V_140 = V_152 ;
if ( F_5 ( V_153 ) & V_150 )
V_141 = V_151 ;
}
V_121 = F_5 ( V_140 ) ;
if ( ! ( V_121 & V_154 ) ||
( ( V_121 & V_155 ) == V_156 ) )
V_143 = false ;
F_54 ( V_141 == V_4 && V_143 ,
L_21 ,
F_71 ( V_4 ) ) ;
}
static void F_72 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_34 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
bool V_122 ;
if ( F_73 ( V_10 ) || F_74 ( V_10 ) )
V_122 = F_5 ( V_157 ) & V_158 ;
else
V_122 = F_5 ( F_75 ( V_4 ) ) & V_159 ;
F_54 ( V_122 != V_34 ,
L_22 ,
F_71 ( V_4 ) , F_51 ( V_34 ) , F_51 ( V_122 ) ) ;
}
void F_76 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_34 )
{
int V_99 ;
T_1 V_121 ;
bool V_122 ;
enum V_96 V_98 = F_40 ( V_12 ,
V_4 ) ;
if ( ( V_4 == V_142 && V_12 -> V_160 & V_161 ) ||
( V_4 == V_151 && V_12 -> V_160 & V_162 ) )
V_34 = true ;
if ( ! F_77 ( V_12 ,
F_78 ( V_98 ) ) ) {
V_122 = false ;
} else {
V_99 = F_46 ( V_98 ) ;
V_121 = F_5 ( V_99 ) ;
V_122 = ! ! ( V_121 & V_163 ) ;
}
F_54 ( V_122 != V_34 ,
L_23 ,
F_71 ( V_4 ) , F_51 ( V_34 ) , F_51 ( V_122 ) ) ;
}
static void F_79 ( struct V_11 * V_12 ,
enum V_164 V_164 , bool V_34 )
{
int V_99 ;
T_1 V_121 ;
bool V_122 ;
V_99 = F_80 ( V_164 ) ;
V_121 = F_5 ( V_99 ) ;
V_122 = ! ! ( V_121 & V_165 ) ;
F_54 ( V_122 != V_34 ,
L_24 ,
F_81 ( V_164 ) , F_51 ( V_34 ) , F_51 ( V_122 ) ) ;
}
static void F_82 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_99 , V_37 ;
T_1 V_121 ;
int V_166 ;
if ( F_45 ( V_10 ) -> V_105 >= 4 ) {
V_99 = F_80 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
F_54 ( V_121 & V_165 ,
L_25 ,
F_81 ( V_4 ) ) ;
return;
}
F_83 (dev_priv, i) {
V_99 = F_80 ( V_37 ) ;
V_121 = F_5 ( V_99 ) ;
V_166 = ( V_121 & V_167 ) >>
V_168 ;
F_54 ( ( V_121 & V_165 ) && V_4 == V_166 ,
L_26 ,
F_81 ( V_37 ) , F_71 ( V_4 ) ) ;
}
}
static void F_84 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_99 , V_169 ;
T_1 V_121 ;
if ( F_45 ( V_10 ) -> V_105 >= 9 ) {
F_85 (dev_priv, pipe, sprite) {
V_121 = F_5 ( F_86 ( V_4 , V_169 ) ) ;
F_54 ( V_121 & V_170 ,
L_27 ,
V_169 , F_71 ( V_4 ) ) ;
}
} else if ( F_21 ( V_10 ) ) {
F_85 (dev_priv, pipe, sprite) {
V_99 = F_87 ( V_4 , V_169 ) ;
V_121 = F_5 ( V_99 ) ;
F_54 ( V_121 & V_171 ,
L_28 ,
F_88 ( V_4 , V_169 ) , F_71 ( V_4 ) ) ;
}
} else if ( F_45 ( V_10 ) -> V_105 >= 7 ) {
V_99 = F_89 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
F_54 ( V_121 & V_172 ,
L_28 ,
F_81 ( V_4 ) , F_71 ( V_4 ) ) ;
} else if ( F_45 ( V_10 ) -> V_105 >= 5 ) {
V_99 = F_90 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
F_54 ( V_121 & V_173 ,
L_28 ,
F_81 ( V_4 ) , F_71 ( V_4 ) ) ;
}
}
static void F_91 ( struct V_89 * V_29 )
{
if ( F_92 ( F_93 ( V_29 ) == 0 ) )
F_94 ( V_29 ) ;
}
static void F_95 ( struct V_11 * V_12 )
{
T_1 V_121 ;
bool V_120 ;
F_92 ( ! ( F_50 ( V_12 -> V_10 ) || F_96 ( V_12 -> V_10 ) ) ) ;
V_121 = F_5 ( V_174 ) ;
V_120 = ! ! ( V_121 & ( V_175 | V_176 |
V_177 ) ) ;
F_54 ( ! V_120 , L_29 ) ;
}
static void F_97 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_99 ;
T_1 V_121 ;
bool V_120 ;
V_99 = F_98 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_120 = ! ! ( V_121 & V_178 ) ;
F_54 ( V_120 ,
L_30 ,
F_71 ( V_4 ) ) ;
}
static bool F_99 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_144 , T_1 V_121 )
{
if ( ( V_121 & V_179 ) == 0 )
return false ;
if ( F_96 ( V_12 -> V_10 ) ) {
T_1 V_180 = F_100 ( V_4 ) ;
T_1 V_181 = F_5 ( V_180 ) ;
if ( ( V_181 & V_182 ) != V_144 )
return false ;
} else if ( F_20 ( V_12 -> V_10 ) ) {
if ( ( V_121 & V_183 ) != F_101 ( V_4 ) )
return false ;
} else {
if ( ( V_121 & V_184 ) != ( V_4 << 30 ) )
return false ;
}
return true ;
}
static bool F_102 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_121 )
{
if ( ( V_121 & V_185 ) == 0 )
return false ;
if ( F_96 ( V_12 -> V_10 ) ) {
if ( ( V_121 & V_186 ) != F_103 ( V_4 ) )
return false ;
} else if ( F_20 ( V_12 -> V_10 ) ) {
if ( ( V_121 & V_187 ) != F_104 ( V_4 ) )
return false ;
} else {
if ( ( V_121 & V_188 ) != F_105 ( V_4 ) )
return false ;
}
return true ;
}
static bool F_106 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_121 )
{
if ( ( V_121 & V_189 ) == 0 )
return false ;
if ( F_96 ( V_12 -> V_10 ) ) {
if ( ( V_121 & V_190 ) != F_107 ( V_4 ) )
return false ;
} else {
if ( ( V_121 & V_191 ) != F_108 ( V_4 ) )
return false ;
}
return true ;
}
static bool F_109 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_121 )
{
if ( ( V_121 & V_192 ) == 0 )
return false ;
if ( F_96 ( V_12 -> V_10 ) ) {
if ( ( V_121 & V_190 ) != F_107 ( V_4 ) )
return false ;
} else {
if ( ( V_121 & V_193 ) != F_110 ( V_4 ) )
return false ;
}
return true ;
}
static void F_111 ( struct V_11 * V_12 ,
enum V_4 V_4 , int V_99 , T_1 V_144 )
{
T_1 V_121 = F_5 ( V_99 ) ;
F_54 ( F_99 ( V_12 , V_4 , V_144 , V_121 ) ,
L_31 ,
V_99 , F_71 ( V_4 ) ) ;
F_54 ( F_50 ( V_12 -> V_10 ) && ( V_121 & V_179 ) == 0
&& ( V_121 & V_194 ) ,
L_32 ) ;
}
static void F_112 ( struct V_11 * V_12 ,
enum V_4 V_4 , int V_99 )
{
T_1 V_121 = F_5 ( V_99 ) ;
F_54 ( F_102 ( V_12 , V_4 , V_121 ) ,
L_33 ,
V_99 , F_71 ( V_4 ) ) ;
F_54 ( F_50 ( V_12 -> V_10 ) && ( V_121 & V_185 ) == 0
&& ( V_121 & V_195 ) ,
L_34 ) ;
}
static void F_113 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_99 ;
T_1 V_121 ;
F_111 ( V_12 , V_4 , V_196 , V_197 ) ;
F_111 ( V_12 , V_4 , V_198 , V_199 ) ;
F_111 ( V_12 , V_4 , V_200 , V_201 ) ;
V_99 = V_202 ;
V_121 = F_5 ( V_99 ) ;
F_54 ( F_109 ( V_12 , V_4 , V_121 ) ,
L_35 ,
F_71 ( V_4 ) ) ;
V_99 = V_149 ;
V_121 = F_5 ( V_99 ) ;
F_54 ( F_106 ( V_12 , V_4 , V_121 ) ,
L_36 ,
F_71 ( V_4 ) ) ;
F_112 ( V_12 , V_4 , V_203 ) ;
F_112 ( V_12 , V_4 , V_204 ) ;
F_112 ( V_12 , V_4 , V_205 ) ;
}
static void F_114 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_21 ( V_10 ) )
return;
if ( F_20 ( V_10 ) ) {
F_115 ( V_206 ) = V_207 ;
F_115 ( V_208 ) = V_209 ;
} else {
F_115 ( V_206 ) = V_209 ;
}
}
static void F_116 ( struct V_28 * V_29 ,
const struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_99 = F_53 ( V_29 -> V_4 ) ;
T_1 V_67 = V_210 -> V_211 . V_67 ;
F_117 ( V_12 , V_29 -> V_4 ) ;
F_118 ( ! F_21 ( V_12 -> V_10 ) ) ;
if ( F_119 ( V_12 -> V_10 ) )
F_69 ( V_12 , V_29 -> V_4 ) ;
F_120 ( V_99 , V_67 ) ;
F_121 ( V_99 ) ;
F_122 ( 150 ) ;
if ( F_47 ( ( ( F_5 ( V_99 ) & V_212 ) == V_212 ) , 1 ) )
F_123 ( L_37 , V_29 -> V_4 ) ;
F_120 ( F_124 ( V_29 -> V_4 ) , V_210 -> V_211 . V_213 ) ;
F_121 ( F_124 ( V_29 -> V_4 ) ) ;
F_120 ( V_99 , V_67 ) ;
F_121 ( V_99 ) ;
F_122 ( 150 ) ;
F_120 ( V_99 , V_67 ) ;
F_121 ( V_99 ) ;
F_122 ( 150 ) ;
F_120 ( V_99 , V_67 ) ;
F_121 ( V_99 ) ;
F_122 ( 150 ) ;
}
static void F_125 ( struct V_28 * V_29 ,
const struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
enum V_214 V_108 = F_126 ( V_4 ) ;
T_1 V_215 ;
F_117 ( V_12 , V_29 -> V_4 ) ;
F_118 ( ! F_20 ( V_12 -> V_10 ) ) ;
F_56 ( & V_12 -> V_124 ) ;
V_215 = F_127 ( V_12 , V_4 , F_128 ( V_108 ) ) ;
V_215 |= V_216 ;
F_129 ( V_12 , V_4 , F_128 ( V_108 ) , V_215 ) ;
F_122 ( 1 ) ;
F_120 ( F_53 ( V_4 ) , V_210 -> V_211 . V_67 ) ;
if ( F_47 ( ( ( F_5 ( F_53 ( V_4 ) ) & V_212 ) == V_212 ) , 1 ) )
F_123 ( L_38 , V_4 ) ;
F_120 ( F_124 ( V_4 ) , V_210 -> V_211 . V_213 ) ;
F_121 ( F_124 ( V_4 ) ) ;
F_58 ( & V_12 -> V_124 ) ;
}
static int F_130 ( struct V_9 * V_10 )
{
struct V_28 * V_29 ;
int V_217 = 0 ;
F_131 (dev, crtc)
V_217 += V_29 -> V_90 &&
F_10 ( V_29 , V_64 ) ;
return V_217 ;
}
static void F_132 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_99 = F_53 ( V_29 -> V_4 ) ;
T_1 V_67 = V_29 -> V_93 -> V_211 . V_67 ;
F_117 ( V_12 , V_29 -> V_4 ) ;
F_118 ( F_45 ( V_10 ) -> V_105 >= 5 ) ;
if ( F_119 ( V_10 ) && ! F_133 ( V_10 ) )
F_69 ( V_12 , V_29 -> V_4 ) ;
if ( F_133 ( V_10 ) && F_130 ( V_10 ) > 0 ) {
V_67 |= V_218 ;
F_120 ( F_53 ( ! V_29 -> V_4 ) ,
F_5 ( F_53 ( ! V_29 -> V_4 ) ) | V_218 ) ;
}
F_121 ( V_99 ) ;
F_122 ( 150 ) ;
if ( F_45 ( V_10 ) -> V_105 >= 4 ) {
F_120 ( F_124 ( V_29 -> V_4 ) ,
V_29 -> V_93 -> V_211 . V_213 ) ;
} else {
F_120 ( V_99 , V_67 ) ;
}
F_120 ( V_99 , V_67 ) ;
F_121 ( V_99 ) ;
F_122 ( 150 ) ;
F_120 ( V_99 , V_67 ) ;
F_121 ( V_99 ) ;
F_122 ( 150 ) ;
F_120 ( V_99 , V_67 ) ;
F_121 ( V_99 ) ;
F_122 ( 150 ) ;
}
static void F_134 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
if ( F_133 ( V_10 ) &&
F_10 ( V_29 , V_64 ) &&
F_130 ( V_10 ) == 1 ) {
F_120 ( F_53 ( V_151 ) ,
F_5 ( F_53 ( V_151 ) ) & ~ V_218 ) ;
F_120 ( F_53 ( V_142 ) ,
F_5 ( F_53 ( V_142 ) ) & ~ V_218 ) ;
}
if ( ( V_4 == V_142 && V_12 -> V_160 & V_161 ) ||
( V_4 == V_151 && V_12 -> V_160 & V_162 ) )
return;
F_117 ( V_12 , V_4 ) ;
F_120 ( F_53 ( V_4 ) , 0 ) ;
F_121 ( F_53 ( V_4 ) ) ;
}
static void F_135 ( struct V_11 * V_12 , enum V_4 V_4 )
{
T_1 V_121 = 0 ;
F_117 ( V_12 , V_4 ) ;
if ( V_4 == V_151 )
V_121 = V_219 | V_220 ;
F_120 ( F_53 ( V_4 ) , V_121 ) ;
F_121 ( F_53 ( V_4 ) ) ;
}
static void F_136 ( struct V_11 * V_12 , enum V_4 V_4 )
{
enum V_214 V_108 = F_126 ( V_4 ) ;
T_1 V_121 ;
F_117 ( V_12 , V_4 ) ;
V_121 = V_221 | V_220 ;
if ( V_4 != V_142 )
V_121 |= V_219 ;
F_120 ( F_53 ( V_4 ) , V_121 ) ;
F_121 ( F_53 ( V_4 ) ) ;
F_56 ( & V_12 -> V_124 ) ;
V_121 = F_127 ( V_12 , V_4 , F_128 ( V_108 ) ) ;
V_121 &= ~ V_216 ;
F_129 ( V_12 , V_4 , F_128 ( V_108 ) , V_121 ) ;
if ( V_4 != V_151 ) {
V_121 = F_127 ( V_12 , V_4 , V_222 ) ;
V_121 &= ~ ( V_223 | V_224 ) ;
F_129 ( V_12 , V_4 , V_222 , V_121 ) ;
} else {
V_121 = F_127 ( V_12 , V_4 , V_225 ) ;
V_121 &= ~ ( V_226 | V_227 ) ;
F_129 ( V_12 , V_4 , V_225 , V_121 ) ;
}
F_58 ( & V_12 -> V_124 ) ;
}
void F_137 ( struct V_11 * V_12 ,
struct V_107 * V_228 )
{
T_1 V_229 ;
int V_230 ;
switch ( V_228 -> V_108 ) {
case V_110 :
V_229 = V_231 ;
V_230 = F_53 ( 0 ) ;
break;
case V_112 :
V_229 = V_232 ;
V_230 = F_53 ( 0 ) ;
break;
case V_114 :
V_229 = V_233 ;
V_230 = V_234 ;
break;
default:
F_138 () ;
}
if ( F_47 ( ( F_5 ( V_230 ) & V_229 ) == 0 , 1000 ) )
F_48 ( 1 , L_39 ,
F_139 ( V_228 -> V_108 ) , F_5 ( V_230 ) ) ;
}
static void F_140 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_127 * V_130 = F_59 ( V_29 ) ;
if ( F_3 ( V_130 == NULL ) )
return;
F_3 ( ! V_130 -> V_93 . V_235 ) ;
if ( V_130 -> V_90 == 0 ) {
F_141 ( L_40 , V_130 -> V_134 ) ;
F_3 ( V_130 -> V_236 ) ;
F_142 ( V_12 , V_130 ) ;
V_130 -> V_237 ( V_12 , V_130 ) ;
}
}
static void F_143 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_127 * V_130 = F_59 ( V_29 ) ;
if ( F_3 ( V_130 == NULL ) )
return;
if ( F_3 ( V_130 -> V_93 . V_235 == 0 ) )
return;
F_144 ( L_41 ,
V_130 -> V_134 , V_130 -> V_90 , V_130 -> V_236 ,
V_29 -> V_8 . V_8 . V_238 ) ;
if ( V_130 -> V_90 ++ ) {
F_3 ( ! V_130 -> V_236 ) ;
F_145 ( V_12 , V_130 ) ;
return;
}
F_3 ( V_130 -> V_236 ) ;
F_146 ( V_12 , V_239 ) ;
F_144 ( L_42 , V_130 -> V_134 ) ;
V_130 -> V_240 ( V_12 , V_130 ) ;
V_130 -> V_236 = true ;
}
static void F_147 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_127 * V_130 = F_59 ( V_29 ) ;
F_118 ( F_45 ( V_10 ) -> V_105 < 5 ) ;
if ( F_3 ( V_130 == NULL ) )
return;
if ( F_3 ( V_130 -> V_93 . V_235 == 0 ) )
return;
F_144 ( L_43 ,
V_130 -> V_134 , V_130 -> V_90 , V_130 -> V_236 ,
V_29 -> V_8 . V_8 . V_238 ) ;
if ( F_3 ( V_130 -> V_90 == 0 ) ) {
F_142 ( V_12 , V_130 ) ;
return;
}
F_145 ( V_12 , V_130 ) ;
F_3 ( ! V_130 -> V_236 ) ;
if ( -- V_130 -> V_90 )
return;
F_144 ( L_44 , V_130 -> V_134 ) ;
V_130 -> V_241 ( V_12 , V_130 ) ;
V_130 -> V_236 = false ;
F_148 ( V_12 , V_239 ) ;
}
static void F_149 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_89 * V_29 = V_12 -> V_97 [ V_4 ] ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
T_4 V_99 , V_121 , V_242 ;
F_118 ( ! F_4 ( V_10 ) ) ;
F_145 ( V_12 ,
F_59 ( V_28 ) ) ;
F_150 ( V_12 , V_4 ) ;
F_151 ( V_12 , V_4 ) ;
if ( F_96 ( V_10 ) ) {
V_99 = F_152 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_121 |= V_243 ;
F_120 ( V_99 , V_121 ) ;
}
V_99 = F_98 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_242 = F_5 ( F_46 ( V_4 ) ) ;
if ( F_50 ( V_12 -> V_10 ) ) {
V_121 &= ~ V_244 ;
V_121 |= V_242 & V_244 ;
}
V_121 &= ~ V_245 ;
if ( ( V_242 & V_246 ) == V_247 )
if ( F_50 ( V_12 -> V_10 ) &&
F_10 ( V_28 , V_55 ) )
V_121 |= V_248 ;
else
V_121 |= V_249 ;
else
V_121 |= V_250 ;
F_120 ( V_99 , V_121 | V_178 ) ;
if ( F_47 ( F_5 ( V_99 ) & V_251 , 100 ) )
F_123 ( L_45 , F_71 ( V_4 ) ) ;
}
static void F_153 ( struct V_11 * V_12 ,
enum V_96 V_98 )
{
T_1 V_121 , V_242 ;
F_118 ( ! F_4 ( V_12 -> V_10 ) ) ;
F_150 ( V_12 , (enum V_4 ) V_98 ) ;
F_151 ( V_12 , V_252 ) ;
V_121 = F_5 ( V_253 ) ;
V_121 |= V_243 ;
F_120 ( V_253 , V_121 ) ;
V_121 = V_178 ;
V_242 = F_5 ( F_46 ( V_98 ) ) ;
if ( ( V_242 & V_254 ) ==
V_247 )
V_121 |= V_249 ;
else
V_121 |= V_250 ;
F_120 ( V_255 , V_121 ) ;
if ( F_47 ( F_5 ( V_255 ) & V_251 , 100 ) )
F_123 ( L_46 ) ;
}
static void F_154 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_99 , V_121 ;
F_155 ( V_12 , V_4 ) ;
F_156 ( V_12 , V_4 ) ;
F_113 ( V_12 , V_4 ) ;
V_99 = F_98 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_121 &= ~ V_178 ;
F_120 ( V_99 , V_121 ) ;
if ( F_47 ( ( F_5 ( V_99 ) & V_251 ) == 0 , 50 ) )
F_123 ( L_47 , F_71 ( V_4 ) ) ;
if ( ! F_50 ( V_10 ) ) {
V_99 = F_152 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_121 &= ~ V_243 ;
F_120 ( V_99 , V_121 ) ;
}
}
static void F_157 ( struct V_11 * V_12 )
{
T_1 V_121 ;
V_121 = F_5 ( V_255 ) ;
V_121 &= ~ V_178 ;
F_120 ( V_255 , V_121 ) ;
if ( F_47 ( ( F_5 ( V_255 ) & V_251 ) == 0 , 50 ) )
F_123 ( L_48 ) ;
V_121 = F_5 ( V_253 ) ;
V_121 &= ~ V_243 ;
F_120 ( V_253 , V_121 ) ;
}
static void F_158 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
enum V_96 V_98 = F_40 ( V_12 ,
V_4 ) ;
enum V_4 V_256 ;
int V_99 ;
T_1 V_121 ;
F_82 ( V_12 , V_4 ) ;
F_159 ( V_12 , V_4 ) ;
F_84 ( V_12 , V_4 ) ;
if ( F_160 ( V_12 -> V_10 ) )
V_256 = V_252 ;
else
V_256 = V_4 ;
if ( ! F_4 ( V_12 -> V_10 ) )
if ( F_10 ( V_29 , V_257 ) )
F_161 ( V_12 ) ;
else
F_162 ( V_12 , V_4 ) ;
else {
if ( V_29 -> V_93 -> V_258 ) {
F_163 ( V_12 , V_256 ) ;
F_67 ( V_12 ,
(enum V_4 ) V_98 ) ;
}
}
V_99 = F_46 ( V_98 ) ;
V_121 = F_5 ( V_99 ) ;
if ( V_121 & V_163 ) {
F_3 ( ! ( ( V_4 == V_142 && V_12 -> V_160 & V_161 ) ||
( V_4 == V_151 && V_12 -> V_160 & V_162 ) ) ) ;
return;
}
F_120 ( V_99 , V_121 | V_163 ) ;
F_121 ( V_99 ) ;
}
static void F_164 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
enum V_96 V_98 = V_29 -> V_93 -> V_98 ;
enum V_4 V_4 = V_29 -> V_4 ;
int V_99 ;
T_1 V_121 ;
F_82 ( V_12 , V_4 ) ;
F_159 ( V_12 , V_4 ) ;
F_84 ( V_12 , V_4 ) ;
V_99 = F_46 ( V_98 ) ;
V_121 = F_5 ( V_99 ) ;
if ( ( V_121 & V_163 ) == 0 )
return;
if ( V_29 -> V_93 -> V_259 )
V_121 &= ~ V_260 ;
if ( ! ( V_4 == V_142 && V_12 -> V_160 & V_161 ) &&
! ( V_4 == V_151 && V_12 -> V_160 & V_162 ) )
V_121 &= ~ V_163 ;
F_120 ( V_99 , V_121 ) ;
if ( ( V_121 & V_163 ) == 0 )
F_44 ( V_29 ) ;
}
void F_165 ( struct V_11 * V_12 ,
enum V_164 V_164 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_1 V_99 = F_45 ( V_10 ) -> V_105 >= 4 ? F_166 ( V_164 ) : F_167 ( V_164 ) ;
F_120 ( V_99 , F_5 ( V_99 ) ) ;
F_121 ( V_99 ) ;
}
static void F_168 ( struct V_261 * V_164 ,
struct V_89 * V_29 )
{
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
F_169 ( V_12 , V_28 -> V_4 ) ;
if ( V_28 -> V_262 )
return;
V_28 -> V_262 = true ;
V_12 -> V_263 . V_264 ( V_29 , V_164 -> V_92 ,
V_29 -> V_265 , V_29 -> V_266 ) ;
if ( F_170 ( V_10 ) )
F_171 ( V_10 , V_28 -> V_4 ) ;
}
static void F_172 ( struct V_261 * V_164 ,
struct V_89 * V_29 )
{
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
if ( F_3 ( ! V_28 -> V_90 ) )
return;
if ( ! V_28 -> V_262 )
return;
V_28 -> V_262 = false ;
V_12 -> V_263 . V_264 ( V_29 , V_164 -> V_92 ,
V_29 -> V_265 , V_29 -> V_266 ) ;
}
static bool F_173 ( struct V_9 * V_10 )
{
#ifdef F_174
if ( F_45 ( V_10 ) -> V_105 >= 6 && V_267 )
return true ;
#endif
return false ;
}
unsigned int
F_175 ( struct V_9 * V_10 , T_4 V_268 ,
V_68 V_269 )
{
unsigned int V_270 ;
T_4 V_271 ;
switch ( V_269 ) {
case V_272 :
V_270 = 1 ;
break;
case V_273 :
V_270 = F_22 ( V_10 ) ? 16 : 8 ;
break;
case V_274 :
V_270 = 32 ;
break;
case V_275 :
V_271 = F_176 ( V_268 , 0 ) ;
switch ( V_271 ) {
default:
case 1 :
V_270 = 64 ;
break;
case 2 :
case 4 :
V_270 = 32 ;
break;
case 8 :
V_270 = 16 ;
break;
case 16 :
F_177 ( 1 ,
L_49 ) ;
V_270 = 16 ;
break;
}
break;
default:
F_178 ( V_269 ) ;
V_270 = 1 ;
break;
}
return V_270 ;
}
unsigned int
F_179 ( struct V_9 * V_10 , unsigned int V_276 ,
T_4 V_268 , V_68 V_269 )
{
return F_180 ( V_276 , F_175 ( V_10 , V_268 ,
V_269 ) ) ;
}
static int
F_181 ( struct V_277 * V_278 , struct V_279 * V_92 ,
const struct V_280 * V_281 )
{
struct V_282 * V_283 = & V_278 -> V_284 ;
* V_278 = V_285 ;
if ( ! V_281 )
return 0 ;
if ( ! F_182 ( V_281 -> V_286 ) )
return 0 ;
* V_278 = V_287 ;
V_283 -> V_276 = V_92 -> V_276 ;
V_283 -> V_268 = V_92 -> V_268 ;
V_283 -> V_288 = V_92 -> V_289 [ 0 ] ;
V_283 -> V_290 = V_92 -> V_291 [ 0 ] ;
if ( ! ( V_283 -> V_290 == V_274 ||
V_283 -> V_290 == V_275 ) ) {
F_144 (
L_50 ) ;
return - V_292 ;
}
return 0 ;
}
int
F_183 ( struct V_261 * V_164 ,
struct V_279 * V_92 ,
const struct V_280 * V_281 ,
struct V_293 * V_294 )
{
struct V_9 * V_10 = V_92 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_295 * V_296 = F_184 ( V_92 ) ;
struct V_277 V_278 ;
T_1 V_297 ;
int V_298 ;
F_3 ( ! F_185 ( & V_10 -> V_299 ) ) ;
switch ( V_92 -> V_291 [ 0 ] ) {
case V_272 :
if ( F_45 ( V_10 ) -> V_105 >= 9 )
V_297 = 256 * 1024 ;
else if ( F_186 ( V_10 ) || F_187 ( V_10 ) )
V_297 = 128 * 1024 ;
else if ( F_45 ( V_10 ) -> V_105 >= 4 )
V_297 = 4 * 1024 ;
else
V_297 = 64 * 1024 ;
break;
case V_273 :
if ( F_45 ( V_10 ) -> V_105 >= 9 )
V_297 = 256 * 1024 ;
else {
V_297 = 0 ;
}
break;
case V_274 :
case V_275 :
if ( F_177 ( F_45 ( V_10 ) -> V_105 < 9 ,
L_51 ) )
return - V_292 ;
V_297 = 1 * 1024 * 1024 ;
break;
default:
F_178 ( V_92 -> V_291 [ 0 ] ) ;
return - V_292 ;
}
V_298 = F_181 ( & V_278 , V_92 , V_281 ) ;
if ( V_298 )
return V_298 ;
if ( F_173 ( V_10 ) && V_297 < 256 * 1024 )
V_297 = 256 * 1024 ;
F_188 ( V_12 ) ;
V_12 -> V_300 . V_301 = false ;
V_298 = F_189 ( V_296 , V_297 , V_294 ,
& V_278 ) ;
if ( V_298 )
goto V_302;
V_298 = F_190 ( V_296 ) ;
if ( V_298 )
goto V_303;
F_191 ( V_296 ) ;
V_12 -> V_300 . V_301 = true ;
F_192 ( V_12 ) ;
return 0 ;
V_303:
F_193 ( V_296 , & V_278 ) ;
V_302:
V_12 -> V_300 . V_301 = true ;
F_192 ( V_12 ) ;
return V_298 ;
}
static void F_194 ( struct V_279 * V_92 ,
const struct V_280 * V_281 )
{
struct V_295 * V_296 = F_184 ( V_92 ) ;
struct V_277 V_278 ;
int V_298 ;
F_3 ( ! F_185 ( & V_296 -> V_8 . V_10 -> V_299 ) ) ;
V_298 = F_181 ( & V_278 , V_92 , V_281 ) ;
F_177 ( V_298 , L_52 ) ;
F_195 ( V_296 ) ;
F_193 ( V_296 , & V_278 ) ;
}
unsigned long F_196 ( int * V_265 , int * V_266 ,
unsigned int V_304 ,
unsigned int V_305 ,
unsigned int V_288 )
{
if ( V_304 != V_306 ) {
unsigned int V_307 , V_308 ;
V_307 = * V_266 / 8 ;
* V_266 %= 8 ;
V_308 = * V_265 / ( 512 / V_305 ) ;
* V_265 %= 512 / V_305 ;
return V_307 * V_288 * 8 + V_308 * 4096 ;
} else {
unsigned int V_309 ;
V_309 = * V_266 * V_288 + * V_265 * V_305 ;
* V_266 = 0 ;
* V_265 = ( V_309 & 4095 ) / V_305 ;
return V_309 & - 4096 ;
}
}
static int F_197 ( int V_310 )
{
switch ( V_310 ) {
case V_311 :
return V_312 ;
case V_313 :
return V_314 ;
case V_315 :
return V_316 ;
default:
case V_317 :
return V_318 ;
case V_319 :
return V_320 ;
case V_321 :
return V_322 ;
case V_323 :
return V_324 ;
}
}
static int F_198 ( int V_310 , bool V_325 , bool V_326 )
{
switch ( V_310 ) {
case V_327 :
return V_316 ;
default:
case V_328 :
if ( V_325 ) {
if ( V_326 )
return V_329 ;
else
return V_320 ;
} else {
if ( V_326 )
return V_330 ;
else
return V_318 ;
}
case V_331 :
if ( V_325 )
return V_324 ;
else
return V_322 ;
}
}
static bool
F_199 ( struct V_28 * V_29 ,
struct V_332 * V_333 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_295 * V_296 = NULL ;
struct V_334 V_335 = { 0 } ;
struct V_279 * V_92 = & V_333 -> V_92 -> V_8 ;
T_1 V_336 = F_200 ( V_333 -> V_8 , V_337 ) ;
T_1 V_338 = F_201 ( V_333 -> V_8 + V_333 -> V_339 ,
V_337 ) ;
V_338 -= V_336 ;
if ( V_333 -> V_339 == 0 )
return false ;
V_296 = F_202 ( V_10 ,
V_336 ,
V_336 ,
V_338 ) ;
if ( ! V_296 )
return false ;
V_296 -> V_304 = V_333 -> V_340 ;
if ( V_296 -> V_304 == V_341 )
V_296 -> V_342 = V_92 -> V_289 [ 0 ] ;
V_335 . V_268 = V_92 -> V_268 ;
V_335 . V_343 = V_92 -> V_343 ;
V_335 . V_276 = V_92 -> V_276 ;
V_335 . V_289 [ 0 ] = V_92 -> V_289 [ 0 ] ;
V_335 . V_291 [ 0 ] = V_92 -> V_291 [ 0 ] ;
V_335 . V_344 = V_345 ;
F_56 ( & V_10 -> V_299 ) ;
if ( F_203 ( V_10 , F_204 ( V_92 ) ,
& V_335 , V_296 ) ) {
F_144 ( L_53 ) ;
goto V_346;
}
F_58 ( & V_10 -> V_299 ) ;
F_144 ( L_54 , V_296 ) ;
return true ;
V_346:
F_205 ( & V_296 -> V_8 ) ;
F_58 ( & V_10 -> V_299 ) ;
return false ;
}
static void
F_206 ( struct V_261 * V_164 )
{
if ( V_164 -> V_92 == V_164 -> V_34 -> V_92 )
return;
if ( V_164 -> V_34 -> V_92 )
F_207 ( V_164 -> V_34 -> V_92 ) ;
V_164 -> V_34 -> V_92 = V_164 -> V_92 ;
if ( V_164 -> V_34 -> V_92 )
F_208 ( V_164 -> V_34 -> V_92 ) ;
}
static void
F_209 ( struct V_28 * V_28 ,
struct V_332 * V_333 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_347 ;
struct V_28 * V_37 ;
struct V_295 * V_296 ;
struct V_261 * V_91 = V_28 -> V_8 . V_91 ;
struct V_279 * V_92 ;
if ( ! V_333 -> V_92 )
return;
if ( F_199 ( V_28 , V_333 ) ) {
V_92 = & V_333 -> V_92 -> V_8 ;
goto V_348;
}
F_210 ( V_333 -> V_92 ) ;
F_211 (dev, c) {
V_37 = F_31 ( V_347 ) ;
if ( V_347 == & V_28 -> V_8 )
continue;
if ( ! V_37 -> V_90 )
continue;
V_92 = V_347 -> V_91 -> V_92 ;
if ( ! V_92 )
continue;
V_296 = F_184 ( V_92 ) ;
if ( F_212 ( V_296 ) == V_333 -> V_8 ) {
F_208 ( V_92 ) ;
goto V_348;
}
}
return;
V_348:
V_296 = F_184 ( V_92 ) ;
if ( V_296 -> V_304 != V_306 )
V_12 -> V_349 = true ;
V_91 -> V_92 = V_92 ;
V_91 -> V_34 -> V_29 = & V_28 -> V_8 ;
V_91 -> V_29 = & V_28 -> V_8 ;
F_206 ( V_91 ) ;
V_296 -> V_350 |= F_213 ( V_28 -> V_4 ) ;
}
static void F_214 ( struct V_89 * V_29 ,
struct V_279 * V_92 ,
int V_265 , int V_266 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_295 * V_296 ;
int V_164 = V_28 -> V_164 ;
unsigned long V_351 ;
T_1 V_352 ;
T_1 V_99 = F_80 ( V_164 ) ;
int V_353 ;
if ( ! V_28 -> V_262 ) {
F_120 ( V_99 , 0 ) ;
if ( F_45 ( V_10 ) -> V_105 >= 4 )
F_120 ( F_166 ( V_164 ) , 0 ) ;
else
F_120 ( F_167 ( V_164 ) , 0 ) ;
F_121 ( V_99 ) ;
return;
}
V_296 = F_184 ( V_92 ) ;
if ( F_3 ( V_296 == NULL ) )
return;
V_353 = F_176 ( V_92 -> V_268 , 0 ) ;
V_352 = V_354 ;
V_352 |= V_165 ;
if ( F_45 ( V_10 ) -> V_105 < 4 ) {
if ( V_28 -> V_4 == V_151 )
V_352 |= V_355 ;
F_120 ( F_215 ( V_164 ) ,
( ( V_28 -> V_93 -> V_356 - 1 ) << 16 ) |
( V_28 -> V_93 -> V_357 - 1 ) ) ;
F_120 ( F_216 ( V_164 ) , 0 ) ;
} else if ( F_20 ( V_10 ) && V_164 == V_358 ) {
F_120 ( F_217 ( V_164 ) ,
( ( V_28 -> V_93 -> V_356 - 1 ) << 16 ) |
( V_28 -> V_93 -> V_357 - 1 ) ) ;
F_120 ( F_218 ( V_164 ) , 0 ) ;
F_120 ( F_219 ( V_164 ) , 0 ) ;
}
switch ( V_92 -> V_268 ) {
case V_312 :
V_352 |= V_311 ;
break;
case V_314 :
case V_359 :
V_352 |= V_313 ;
break;
case V_316 :
V_352 |= V_315 ;
break;
case V_318 :
case V_330 :
V_352 |= V_317 ;
break;
case V_320 :
case V_329 :
V_352 |= V_319 ;
break;
case V_322 :
case V_360 :
V_352 |= V_321 ;
break;
case V_324 :
case V_361 :
V_352 |= V_323 ;
break;
default:
F_138 () ;
}
if ( F_45 ( V_10 ) -> V_105 >= 4 &&
V_296 -> V_304 != V_306 )
V_352 |= V_362 ;
if ( F_18 ( V_10 ) )
V_352 |= V_363 ;
V_351 = V_266 * V_92 -> V_289 [ 0 ] + V_265 * V_353 ;
if ( F_45 ( V_10 ) -> V_105 >= 4 ) {
V_28 -> V_364 =
F_196 ( & V_265 , & V_266 , V_296 -> V_304 ,
V_353 ,
V_92 -> V_289 [ 0 ] ) ;
V_351 -= V_28 -> V_364 ;
} else {
V_28 -> V_364 = V_351 ;
}
if ( V_29 -> V_91 -> V_34 -> V_286 == F_220 ( V_365 ) ) {
V_352 |= V_366 ;
V_265 += ( V_28 -> V_93 -> V_357 - 1 ) ;
V_266 += ( V_28 -> V_93 -> V_356 - 1 ) ;
V_351 +=
( V_28 -> V_93 -> V_356 - 1 ) * V_92 -> V_289 [ 0 ] +
( V_28 -> V_93 -> V_357 - 1 ) * V_353 ;
}
F_120 ( V_99 , V_352 ) ;
F_120 ( F_221 ( V_164 ) , V_92 -> V_289 [ 0 ] ) ;
if ( F_45 ( V_10 ) -> V_105 >= 4 ) {
F_120 ( F_166 ( V_164 ) ,
F_212 ( V_296 ) + V_28 -> V_364 ) ;
F_120 ( F_222 ( V_164 ) , ( V_266 << 16 ) | V_265 ) ;
F_120 ( F_223 ( V_164 ) , V_351 ) ;
} else
F_120 ( F_167 ( V_164 ) , F_212 ( V_296 ) + V_351 ) ;
F_121 ( V_99 ) ;
}
static void F_224 ( struct V_89 * V_29 ,
struct V_279 * V_92 ,
int V_265 , int V_266 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_295 * V_296 ;
int V_164 = V_28 -> V_164 ;
unsigned long V_351 ;
T_1 V_352 ;
T_1 V_99 = F_80 ( V_164 ) ;
int V_353 ;
if ( ! V_28 -> V_262 ) {
F_120 ( V_99 , 0 ) ;
F_120 ( F_166 ( V_164 ) , 0 ) ;
F_121 ( V_99 ) ;
return;
}
V_296 = F_184 ( V_92 ) ;
if ( F_3 ( V_296 == NULL ) )
return;
V_353 = F_176 ( V_92 -> V_268 , 0 ) ;
V_352 = V_354 ;
V_352 |= V_165 ;
if ( F_225 ( V_10 ) || F_170 ( V_10 ) )
V_352 |= V_367 ;
switch ( V_92 -> V_268 ) {
case V_312 :
V_352 |= V_311 ;
break;
case V_316 :
V_352 |= V_315 ;
break;
case V_318 :
case V_330 :
V_352 |= V_317 ;
break;
case V_320 :
case V_329 :
V_352 |= V_319 ;
break;
case V_322 :
case V_360 :
V_352 |= V_321 ;
break;
case V_324 :
case V_361 :
V_352 |= V_323 ;
break;
default:
F_138 () ;
}
if ( V_296 -> V_304 != V_306 )
V_352 |= V_362 ;
if ( ! F_225 ( V_10 ) && ! F_170 ( V_10 ) )
V_352 |= V_363 ;
V_351 = V_266 * V_92 -> V_289 [ 0 ] + V_265 * V_353 ;
V_28 -> V_364 =
F_196 ( & V_265 , & V_266 , V_296 -> V_304 ,
V_353 ,
V_92 -> V_289 [ 0 ] ) ;
V_351 -= V_28 -> V_364 ;
if ( V_29 -> V_91 -> V_34 -> V_286 == F_220 ( V_365 ) ) {
V_352 |= V_366 ;
if ( ! F_225 ( V_10 ) && ! F_170 ( V_10 ) ) {
V_265 += ( V_28 -> V_93 -> V_357 - 1 ) ;
V_266 += ( V_28 -> V_93 -> V_356 - 1 ) ;
V_351 +=
( V_28 -> V_93 -> V_356 - 1 ) * V_92 -> V_289 [ 0 ] +
( V_28 -> V_93 -> V_357 - 1 ) * V_353 ;
}
}
F_120 ( V_99 , V_352 ) ;
F_120 ( F_221 ( V_164 ) , V_92 -> V_289 [ 0 ] ) ;
F_120 ( F_166 ( V_164 ) ,
F_212 ( V_296 ) + V_28 -> V_364 ) ;
if ( F_225 ( V_10 ) || F_170 ( V_10 ) ) {
F_120 ( F_226 ( V_164 ) , ( V_266 << 16 ) | V_265 ) ;
} else {
F_120 ( F_222 ( V_164 ) , ( V_266 << 16 ) | V_265 ) ;
F_120 ( F_223 ( V_164 ) , V_351 ) ;
}
F_121 ( V_99 ) ;
}
T_1 F_227 ( struct V_9 * V_10 , V_68 V_290 ,
T_4 V_268 )
{
T_1 V_368 = F_176 ( V_268 , 0 ) * 8 ;
switch ( V_290 ) {
case V_272 :
return 64 ;
case V_273 :
if ( F_45 ( V_10 ) -> V_105 == 2 )
return 128 ;
return 512 ;
case V_274 :
return 128 ;
case V_275 :
if ( V_368 == 8 )
return 64 ;
else
return 128 ;
default:
F_178 ( V_290 ) ;
return 64 ;
}
}
unsigned long F_228 ( struct V_369 * V_369 ,
struct V_295 * V_296 )
{
const struct V_277 * V_278 = & V_285 ;
if ( F_182 ( V_369 -> V_8 . V_34 -> V_286 ) )
V_278 = & V_287 ;
return F_229 ( V_296 , V_278 ) ;
}
static void F_230 ( struct V_89 * V_29 ,
struct V_279 * V_92 ,
int V_265 , int V_266 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_295 * V_296 ;
int V_4 = V_28 -> V_4 ;
T_1 V_370 , V_371 ;
unsigned long V_372 ;
if ( ! V_28 -> V_262 ) {
F_120 ( F_86 ( V_4 , 0 ) , 0 ) ;
F_120 ( F_231 ( V_4 , 0 ) , 0 ) ;
F_121 ( F_86 ( V_4 , 0 ) ) ;
return;
}
V_370 = V_170 |
V_373 |
V_374 ;
switch ( V_92 -> V_268 ) {
case V_316 :
V_370 |= V_327 ;
break;
case V_318 :
V_370 |= V_328 ;
break;
case V_330 :
V_370 |= V_328 ;
V_370 |= V_375 ;
break;
case V_320 :
V_370 |= V_376 ;
V_370 |= V_328 ;
break;
case V_329 :
V_370 |= V_376 ;
V_370 |= V_328 ;
V_370 |= V_375 ;
break;
case V_322 :
V_370 |= V_331 ;
break;
case V_324 :
V_370 |= V_376 ;
V_370 |= V_331 ;
break;
default:
F_138 () ;
}
switch ( V_92 -> V_291 [ 0 ] ) {
case V_272 :
break;
case V_273 :
V_370 |= V_377 ;
break;
case V_274 :
V_370 |= V_378 ;
break;
case V_275 :
V_370 |= V_379 ;
break;
default:
F_178 ( V_92 -> V_291 [ 0 ] ) ;
}
V_370 |= V_380 ;
if ( V_29 -> V_91 -> V_34 -> V_286 == F_220 ( V_365 ) )
V_370 |= V_381 ;
V_296 = F_184 ( V_92 ) ;
V_371 = F_227 ( V_10 , V_92 -> V_291 [ 0 ] ,
V_92 -> V_268 ) ;
V_372 = F_228 ( F_232 ( V_29 -> V_91 ) , V_296 ) ;
F_120 ( F_86 ( V_4 , 0 ) , V_370 ) ;
F_120 ( F_233 ( V_4 , 0 ) , 0 ) ;
F_120 ( F_234 ( V_4 , 0 ) , ( V_266 << 16 ) | V_265 ) ;
F_120 ( F_235 ( V_4 , 0 ) ,
( V_28 -> V_93 -> V_356 - 1 ) << 16 |
( V_28 -> V_93 -> V_357 - 1 ) ) ;
F_120 ( F_236 ( V_4 , 0 ) , V_92 -> V_289 [ 0 ] / V_371 ) ;
F_120 ( F_231 ( V_4 , 0 ) , V_372 ) ;
F_121 ( F_231 ( V_4 , 0 ) ) ;
}
static int
F_237 ( struct V_89 * V_29 , struct V_279 * V_92 ,
int V_265 , int V_266 , enum V_382 V_34 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_12 -> V_263 . V_383 )
V_12 -> V_263 . V_383 ( V_10 ) ;
V_12 -> V_263 . V_264 ( V_29 , V_92 , V_265 , V_266 ) ;
return 0 ;
}
static void F_238 ( struct V_9 * V_10 )
{
struct V_89 * V_29 ;
F_211 (dev, crtc) {
struct V_28 * V_28 = F_31 ( V_29 ) ;
enum V_164 V_164 = V_28 -> V_164 ;
F_239 ( V_10 , V_164 ) ;
F_240 ( V_10 , V_164 ) ;
}
}
static void F_241 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_29 ;
F_211 (dev, crtc) {
struct V_28 * V_28 = F_31 ( V_29 ) ;
F_242 ( & V_29 -> V_384 , NULL ) ;
if ( V_28 -> V_90 && V_29 -> V_91 -> V_92 )
V_12 -> V_263 . V_264 ( V_29 ,
V_29 -> V_91 -> V_92 ,
V_29 -> V_265 ,
V_29 -> V_266 ) ;
F_243 ( & V_29 -> V_384 ) ;
}
}
void F_244 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_245 ( V_10 ) ;
struct V_28 * V_29 ;
if ( F_22 ( V_10 ) )
return;
if ( F_45 ( V_10 ) -> V_105 >= 5 || F_18 ( V_10 ) )
return;
F_246 ( V_10 ) ;
F_131 (dev, crtc) {
if ( V_29 -> V_90 )
V_12 -> V_263 . V_385 ( & V_29 -> V_8 ) ;
}
}
void F_247 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_245 ( V_10 ) ;
F_238 ( V_10 ) ;
if ( F_22 ( V_10 ) )
return;
if ( F_45 ( V_10 ) -> V_105 >= 5 || F_18 ( V_10 ) ) {
F_241 ( V_10 ) ;
return;
}
F_248 ( V_12 ) ;
F_249 ( V_12 ) ;
F_250 ( V_10 ) ;
F_251 ( & V_12 -> V_386 ) ;
if ( V_12 -> V_263 . V_387 )
V_12 -> V_263 . V_387 ( V_10 ) ;
F_252 ( & V_12 -> V_386 ) ;
F_253 ( V_10 , true ) ;
F_254 ( V_12 ) ;
F_255 ( V_10 ) ;
}
static int
F_256 ( struct V_279 * V_388 )
{
struct V_295 * V_296 = F_184 ( V_388 ) ;
struct V_11 * V_12 = V_296 -> V_8 . V_10 -> V_13 ;
bool V_389 = V_12 -> V_300 . V_301 ;
int V_298 ;
V_12 -> V_300 . V_301 = false ;
V_298 = F_257 ( V_296 ) ;
V_12 -> V_300 . V_301 = V_389 ;
return V_298 ;
}
static bool F_258 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
bool V_390 ;
if ( F_259 ( & V_12 -> V_391 ) ||
V_28 -> V_392 != F_260 ( & V_12 -> V_391 . V_392 ) )
return false ;
F_251 ( & V_10 -> V_393 ) ;
V_390 = F_31 ( V_29 ) -> V_394 != NULL ;
F_252 ( & V_10 -> V_393 ) ;
return V_390 ;
}
static void F_261 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
const struct V_395 * V_94 ;
if ( ! V_396 . V_397 )
return;
V_94 = & V_29 -> V_93 -> V_8 . V_94 ;
F_120 ( F_262 ( V_29 -> V_4 ) ,
( ( V_94 -> V_398 - 1 ) << 16 ) |
( V_94 -> V_399 - 1 ) ) ;
if ( ! V_29 -> V_93 -> V_400 . V_120 &&
( F_10 ( V_29 , V_44 ) ||
F_10 ( V_29 , V_401 ) ) ) {
F_120 ( F_263 ( V_29 -> V_4 ) , 0 ) ;
F_120 ( F_264 ( V_29 -> V_4 ) , 0 ) ;
F_120 ( F_265 ( V_29 -> V_4 ) , 0 ) ;
}
V_29 -> V_93 -> V_357 = V_94 -> V_398 ;
V_29 -> V_93 -> V_356 = V_94 -> V_399 ;
}
static void F_266 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_402 ;
V_99 = F_64 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
if ( F_267 ( V_10 ) ) {
V_402 &= ~ V_403 ;
V_402 |= V_403 | V_404 ;
} else {
V_402 &= ~ V_405 ;
V_402 |= V_405 | V_404 ;
}
F_120 ( V_99 , V_402 ) ;
V_99 = F_66 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
if ( F_96 ( V_10 ) ) {
V_402 &= ~ V_406 ;
V_402 |= V_407 ;
} else {
V_402 &= ~ V_405 ;
V_402 |= V_405 ;
}
F_120 ( V_99 , V_402 | V_408 ) ;
F_121 ( V_99 ) ;
F_122 ( 1000 ) ;
if ( F_267 ( V_10 ) )
F_120 ( V_99 , F_5 ( V_99 ) | V_409 |
V_410 ) ;
}
static void F_268 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_402 , V_411 ;
F_169 ( V_12 , V_4 ) ;
V_99 = F_269 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_412 ;
V_402 &= ~ V_413 ;
F_120 ( V_99 , V_402 ) ;
F_5 ( V_99 ) ;
F_122 ( 150 ) ;
V_99 = F_64 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_414 ;
V_402 |= F_270 ( V_28 -> V_93 -> V_415 ) ;
V_402 &= ~ V_405 ;
V_402 |= V_416 ;
F_120 ( V_99 , V_402 | V_136 ) ;
V_99 = F_66 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_405 ;
V_402 |= V_416 ;
F_120 ( V_99 , V_402 | V_137 ) ;
F_121 ( V_99 ) ;
F_122 ( 150 ) ;
F_120 ( F_271 ( V_4 ) , V_417 ) ;
F_120 ( F_271 ( V_4 ) , V_417 |
V_418 ) ;
V_99 = F_272 ( V_4 ) ;
for ( V_411 = 0 ; V_411 < 5 ; V_411 ++ ) {
V_402 = F_5 ( V_99 ) ;
F_144 ( L_55 , V_402 ) ;
if ( ( V_402 & V_413 ) ) {
F_144 ( L_56 ) ;
F_120 ( V_99 , V_402 | V_413 ) ;
break;
}
}
if ( V_411 == 5 )
F_123 ( L_57 ) ;
V_99 = F_64 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_405 ;
V_402 |= V_419 ;
F_120 ( V_99 , V_402 ) ;
V_99 = F_66 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_405 ;
V_402 |= V_419 ;
F_120 ( V_99 , V_402 ) ;
F_121 ( V_99 ) ;
F_122 ( 150 ) ;
V_99 = F_272 ( V_4 ) ;
for ( V_411 = 0 ; V_411 < 5 ; V_411 ++ ) {
V_402 = F_5 ( V_99 ) ;
F_144 ( L_55 , V_402 ) ;
if ( V_402 & V_412 ) {
F_120 ( V_99 , V_402 | V_412 ) ;
F_144 ( L_58 ) ;
break;
}
}
if ( V_411 == 5 )
F_123 ( L_59 ) ;
F_144 ( L_60 ) ;
}
static void F_273 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_402 , V_37 , V_420 ;
V_99 = F_269 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_412 ;
V_402 &= ~ V_413 ;
F_120 ( V_99 , V_402 ) ;
F_121 ( V_99 ) ;
F_122 ( 150 ) ;
V_99 = F_64 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_414 ;
V_402 |= F_270 ( V_28 -> V_93 -> V_415 ) ;
V_402 &= ~ V_405 ;
V_402 |= V_416 ;
V_402 &= ~ V_421 ;
V_402 |= V_422 ;
F_120 ( V_99 , V_402 | V_136 ) ;
F_120 ( F_274 ( V_4 ) ,
V_423 | V_424 ) ;
V_99 = F_66 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
if ( F_96 ( V_10 ) ) {
V_402 &= ~ V_406 ;
V_402 |= V_425 ;
} else {
V_402 &= ~ V_405 ;
V_402 |= V_416 ;
}
F_120 ( V_99 , V_402 | V_137 ) ;
F_121 ( V_99 ) ;
F_122 ( 150 ) ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ ) {
V_99 = F_64 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_421 ;
V_402 |= V_426 [ V_37 ] ;
F_120 ( V_99 , V_402 ) ;
F_121 ( V_99 ) ;
F_122 ( 500 ) ;
for ( V_420 = 0 ; V_420 < 5 ; V_420 ++ ) {
V_99 = F_272 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
F_144 ( L_55 , V_402 ) ;
if ( V_402 & V_413 ) {
F_120 ( V_99 , V_402 | V_413 ) ;
F_144 ( L_56 ) ;
break;
}
F_122 ( 50 ) ;
}
if ( V_420 < 5 )
break;
}
if ( V_37 == 4 )
F_123 ( L_57 ) ;
V_99 = F_64 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_405 ;
V_402 |= V_419 ;
if ( F_275 ( V_10 ) ) {
V_402 &= ~ V_421 ;
V_402 |= V_422 ;
}
F_120 ( V_99 , V_402 ) ;
V_99 = F_66 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
if ( F_96 ( V_10 ) ) {
V_402 &= ~ V_406 ;
V_402 |= V_427 ;
} else {
V_402 &= ~ V_405 ;
V_402 |= V_419 ;
}
F_120 ( V_99 , V_402 ) ;
F_121 ( V_99 ) ;
F_122 ( 150 ) ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ ) {
V_99 = F_64 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_421 ;
V_402 |= V_426 [ V_37 ] ;
F_120 ( V_99 , V_402 ) ;
F_121 ( V_99 ) ;
F_122 ( 500 ) ;
for ( V_420 = 0 ; V_420 < 5 ; V_420 ++ ) {
V_99 = F_272 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
F_144 ( L_55 , V_402 ) ;
if ( V_402 & V_412 ) {
F_120 ( V_99 , V_402 | V_412 ) ;
F_144 ( L_58 ) ;
break;
}
F_122 ( 50 ) ;
}
if ( V_420 < 5 )
break;
}
if ( V_37 == 4 )
F_123 ( L_59 ) ;
F_144 ( L_61 ) ;
}
static void F_276 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_402 , V_37 , V_428 ;
V_99 = F_269 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_412 ;
V_402 &= ~ V_413 ;
F_120 ( V_99 , V_402 ) ;
F_121 ( V_99 ) ;
F_122 ( 150 ) ;
F_144 ( L_62 ,
F_5 ( F_272 ( V_4 ) ) ) ;
for ( V_428 = 0 ; V_428 < F_277 ( V_426 ) * 2 ; V_428 ++ ) {
V_99 = F_64 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ ( V_429 | V_403 ) ;
V_402 &= ~ V_136 ;
F_120 ( V_99 , V_402 ) ;
V_99 = F_66 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_429 ;
V_402 &= ~ V_406 ;
V_402 &= ~ V_137 ;
F_120 ( V_99 , V_402 ) ;
V_99 = F_64 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_414 ;
V_402 |= F_270 ( V_28 -> V_93 -> V_415 ) ;
V_402 |= V_430 ;
V_402 &= ~ V_421 ;
V_402 |= V_426 [ V_428 / 2 ] ;
V_402 |= V_431 ;
F_120 ( V_99 , V_402 | V_136 ) ;
F_120 ( F_274 ( V_4 ) ,
V_423 | V_424 ) ;
V_99 = F_66 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 |= V_425 ;
V_402 |= V_431 ;
F_120 ( V_99 , V_402 | V_137 ) ;
F_121 ( V_99 ) ;
F_122 ( 1 ) ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ ) {
V_99 = F_272 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
F_144 ( L_55 , V_402 ) ;
if ( V_402 & V_413 ||
( F_5 ( V_99 ) & V_413 ) ) {
F_120 ( V_99 , V_402 | V_413 ) ;
F_144 ( L_63 ,
V_37 ) ;
break;
}
F_122 ( 1 ) ;
}
if ( V_37 == 4 ) {
F_144 ( L_64 , V_428 / 2 ) ;
continue;
}
V_99 = F_64 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_403 ;
V_402 |= V_432 ;
F_120 ( V_99 , V_402 ) ;
V_99 = F_66 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_406 ;
V_402 |= V_427 ;
F_120 ( V_99 , V_402 ) ;
F_121 ( V_99 ) ;
F_122 ( 2 ) ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ ) {
V_99 = F_272 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
F_144 ( L_55 , V_402 ) ;
if ( V_402 & V_412 ||
( F_5 ( V_99 ) & V_412 ) ) {
F_120 ( V_99 , V_402 | V_412 ) ;
F_144 ( L_65 ,
V_37 ) ;
goto V_433;
}
F_122 ( 2 ) ;
}
if ( V_37 == 4 )
F_144 ( L_66 , V_428 / 2 ) ;
}
V_433:
F_144 ( L_61 ) ;
}
static void F_278 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_402 ;
V_99 = F_66 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ ( V_414 | ( 0x7 << 16 ) ) ;
V_402 |= F_270 ( V_28 -> V_93 -> V_415 ) ;
V_402 |= ( F_5 ( F_46 ( V_4 ) ) & V_244 ) << 11 ;
F_120 ( V_99 , V_402 | V_139 ) ;
F_121 ( V_99 ) ;
F_122 ( 200 ) ;
V_402 = F_5 ( V_99 ) ;
F_120 ( V_99 , V_402 | V_434 ) ;
F_121 ( V_99 ) ;
F_122 ( 200 ) ;
V_99 = F_64 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
if ( ( V_402 & V_138 ) == 0 ) {
F_120 ( V_99 , V_402 | V_138 ) ;
F_121 ( V_99 ) ;
F_122 ( 100 ) ;
}
}
static void F_279 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_402 ;
V_99 = F_66 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
F_120 ( V_99 , V_402 & ~ V_434 ) ;
V_99 = F_64 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
F_120 ( V_99 , V_402 & ~ V_138 ) ;
F_121 ( V_99 ) ;
F_122 ( 100 ) ;
V_99 = F_66 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
F_120 ( V_99 , V_402 & ~ V_139 ) ;
F_121 ( V_99 ) ;
F_122 ( 100 ) ;
}
static void F_280 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_402 ;
V_99 = F_64 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
F_120 ( V_99 , V_402 & ~ V_136 ) ;
F_121 ( V_99 ) ;
V_99 = F_66 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ ( 0x7 << 16 ) ;
V_402 |= ( F_5 ( F_46 ( V_4 ) ) & V_244 ) << 11 ;
F_120 ( V_99 , V_402 & ~ V_137 ) ;
F_121 ( V_99 ) ;
F_122 ( 100 ) ;
if ( F_50 ( V_10 ) )
F_120 ( F_271 ( V_4 ) , V_417 ) ;
V_99 = F_64 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ V_405 ;
V_402 |= V_416 ;
F_120 ( V_99 , V_402 ) ;
V_99 = F_66 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
if ( F_96 ( V_10 ) ) {
V_402 &= ~ V_406 ;
V_402 |= V_425 ;
} else {
V_402 &= ~ V_405 ;
V_402 |= V_416 ;
}
V_402 &= ~ ( 0x07 << 16 ) ;
V_402 |= ( F_5 ( F_46 ( V_4 ) ) & V_244 ) << 11 ;
F_120 ( V_99 , V_402 ) ;
F_121 ( V_99 ) ;
F_122 ( 100 ) ;
}
bool F_281 ( struct V_9 * V_10 )
{
struct V_28 * V_29 ;
F_131 (dev, crtc) {
if ( F_260 ( & V_29 -> V_435 ) == 0 )
continue;
if ( V_29 -> V_394 )
F_171 ( V_10 , V_29 -> V_4 ) ;
return true ;
}
return false ;
}
static void F_282 ( struct V_28 * V_28 )
{
struct V_11 * V_12 = F_245 ( V_28 -> V_8 . V_10 ) ;
struct V_436 * V_437 = V_28 -> V_394 ;
F_283 () ;
V_28 -> V_394 = NULL ;
if ( V_437 -> V_438 )
F_284 ( V_28 -> V_8 . V_10 ,
V_28 -> V_4 ,
V_437 -> V_438 ) ;
F_94 ( & V_28 -> V_8 ) ;
F_285 ( & V_12 -> V_439 ) ;
F_286 ( V_12 -> V_440 , & V_437 -> V_437 ) ;
F_287 ( V_28 -> V_164 ,
V_437 -> V_441 ) ;
}
void F_288 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_3 ( F_289 ( & V_12 -> V_439 ) ) ;
if ( F_3 ( F_290 ( V_12 -> V_439 ,
! F_258 ( V_29 ) ,
60 * V_442 ) == 0 ) ) {
struct V_28 * V_28 = F_31 ( V_29 ) ;
F_251 ( & V_10 -> V_393 ) ;
if ( V_28 -> V_394 ) {
F_177 ( 1 , L_67 ) ;
F_282 ( V_28 ) ;
}
F_252 ( & V_10 -> V_393 ) ;
}
if ( V_29 -> V_91 -> V_92 ) {
F_56 ( & V_10 -> V_299 ) ;
F_256 ( V_29 -> V_91 -> V_92 ) ;
F_58 ( & V_10 -> V_299 ) ;
}
}
static void F_291 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int clock = F_31 ( V_29 ) -> V_93 -> V_8 . V_94 . V_95 ;
T_1 V_443 , V_444 , V_445 , V_446 = 0 ;
T_1 V_402 ;
F_56 ( & V_12 -> V_124 ) ;
F_120 ( V_447 , V_448 ) ;
F_292 ( V_12 , V_449 ,
F_293 ( V_12 , V_449 , V_450 ) |
V_451 ,
V_450 ) ;
if ( clock == 20000 ) {
V_445 = 1 ;
V_443 = 0x41 ;
V_444 = 0x20 ;
} else {
T_1 V_452 = 172800 * 1000 ;
T_1 V_453 = 64 ;
T_1 V_454 , V_455 , V_456 ;
V_454 = ( V_452 / clock ) ;
V_455 = V_454 / V_453 ;
V_456 = V_454 % V_453 ;
V_445 = 0 ;
V_443 = V_455 - 2 ;
V_444 = V_456 ;
}
F_3 ( F_294 ( V_443 ) &
~ V_457 ) ;
F_3 ( F_295 ( V_446 ) &
~ V_458 ) ;
F_144 ( L_68 ,
clock ,
V_445 ,
V_443 ,
V_446 ,
V_444 ) ;
V_402 = F_293 ( V_12 , V_459 , V_450 ) ;
V_402 &= ~ V_457 ;
V_402 |= F_294 ( V_443 ) ;
V_402 &= ~ V_458 ;
V_402 |= F_296 ( V_444 ) ;
V_402 |= F_295 ( V_446 ) ;
V_402 |= V_460 ;
F_292 ( V_12 , V_459 , V_402 , V_450 ) ;
V_402 = F_293 ( V_12 , V_461 , V_450 ) ;
V_402 &= ~ F_297 ( 1 ) ;
V_402 |= F_297 ( V_445 ) ;
F_292 ( V_12 , V_461 , V_402 , V_450 ) ;
V_402 = F_293 ( V_12 , V_449 , V_450 ) ;
V_402 &= ~ V_451 ;
F_292 ( V_12 , V_449 , V_402 , V_450 ) ;
F_122 ( 24 ) ;
F_120 ( V_447 , V_462 ) ;
F_58 ( & V_12 -> V_124 ) ;
}
static void F_298 ( struct V_28 * V_29 ,
enum V_4 V_256 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_96 V_98 = V_29 -> V_93 -> V_98 ;
F_120 ( F_299 ( V_256 ) ,
F_5 ( F_300 ( V_98 ) ) ) ;
F_120 ( F_301 ( V_256 ) ,
F_5 ( F_302 ( V_98 ) ) ) ;
F_120 ( F_303 ( V_256 ) ,
F_5 ( F_304 ( V_98 ) ) ) ;
F_120 ( F_305 ( V_256 ) ,
F_5 ( F_306 ( V_98 ) ) ) ;
F_120 ( F_307 ( V_256 ) ,
F_5 ( F_308 ( V_98 ) ) ) ;
F_120 ( F_309 ( V_256 ) ,
F_5 ( F_310 ( V_98 ) ) ) ;
F_120 ( F_311 ( V_256 ) ,
F_5 ( F_312 ( V_98 ) ) ) ;
}
static void F_313 ( struct V_9 * V_10 , bool V_240 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_402 ;
V_402 = F_5 ( V_463 ) ;
if ( ! ! ( V_402 & V_464 ) == V_240 )
return;
F_3 ( F_5 ( F_66 ( V_151 ) ) & V_137 ) ;
F_3 ( F_5 ( F_66 ( V_465 ) ) & V_137 ) ;
V_402 &= ~ V_464 ;
if ( V_240 )
V_402 |= V_464 ;
F_144 ( L_69 , V_240 ? L_70 : L_71 ) ;
F_120 ( V_463 , V_402 ) ;
F_121 ( V_463 ) ;
}
static void F_314 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
switch ( V_28 -> V_4 ) {
case V_142 :
break;
case V_151 :
if ( V_28 -> V_93 -> V_415 > 2 )
F_313 ( V_10 , false ) ;
else
F_313 ( V_10 , true ) ;
break;
case V_465 :
F_313 ( V_10 , true ) ;
break;
default:
F_138 () ;
}
}
static void F_315 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_402 ;
F_97 ( V_12 , V_4 ) ;
if ( F_267 ( V_10 ) )
F_314 ( V_28 ) ;
F_120 ( F_316 ( V_4 ) ,
F_5 ( F_317 ( V_4 ) ) & V_466 ) ;
V_12 -> V_263 . V_467 ( V_29 ) ;
if ( F_96 ( V_10 ) ) {
T_1 V_468 ;
V_402 = F_5 ( V_469 ) ;
V_402 |= F_318 ( V_4 ) ;
V_468 = F_319 ( V_4 ) ;
if ( V_28 -> V_93 -> V_128 == V_470 )
V_402 |= V_468 ;
else
V_402 &= ~ V_468 ;
F_120 ( V_469 , V_402 ) ;
}
F_143 ( V_28 ) ;
F_69 ( V_12 , V_4 ) ;
F_298 ( V_28 , V_4 ) ;
F_266 ( V_29 ) ;
if ( F_96 ( V_10 ) && V_28 -> V_93 -> V_471 ) {
T_1 V_472 = ( F_5 ( F_46 ( V_4 ) ) & V_244 ) >> 5 ;
V_99 = F_100 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ ( V_182 |
V_473 |
V_474 ) ;
V_402 |= ( V_475 |
V_476 ) ;
V_402 |= V_472 << 9 ;
if ( V_29 -> V_477 . V_344 & V_478 )
V_402 |= V_479 ;
if ( V_29 -> V_477 . V_344 & V_480 )
V_402 |= V_481 ;
switch ( F_320 ( V_29 ) ) {
case V_196 :
V_402 |= V_197 ;
break;
case V_198 :
V_402 |= V_199 ;
break;
case V_200 :
V_402 |= V_201 ;
break;
default:
F_138 () ;
}
F_120 ( V_99 , V_402 ) ;
}
F_149 ( V_12 , V_4 ) ;
}
static void F_321 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
enum V_96 V_98 = V_28 -> V_93 -> V_98 ;
F_97 ( V_12 , V_252 ) ;
F_291 ( V_29 ) ;
F_298 ( V_28 , V_142 ) ;
F_153 ( V_12 , V_98 ) ;
}
void F_322 ( struct V_28 * V_29 )
{
struct V_127 * V_130 = F_59 ( V_29 ) ;
if ( V_130 == NULL )
return;
if ( ! ( V_130 -> V_93 . V_235 & ( 1 << V_29 -> V_4 ) ) ) {
F_48 ( 1 , L_72 , V_130 -> V_134 ) ;
return;
}
V_130 -> V_93 . V_235 &= ~ ( 1 << V_29 -> V_4 ) ;
if ( V_130 -> V_93 . V_235 == 0 ) {
F_3 ( V_130 -> V_236 ) ;
F_3 ( V_130 -> V_90 ) ;
}
V_29 -> V_93 -> V_128 = V_482 ;
}
struct V_127 * F_323 ( struct V_28 * V_29 ,
struct V_31 * V_32 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
struct V_127 * V_130 ;
enum V_483 V_37 ;
if ( F_50 ( V_12 -> V_10 ) ) {
V_37 = (enum V_483 ) V_29 -> V_4 ;
V_130 = & V_12 -> V_129 [ V_37 ] ;
F_144 ( L_73 ,
V_29 -> V_8 . V_8 . V_238 , V_130 -> V_134 ) ;
F_3 ( V_130 -> V_484 -> V_235 ) ;
goto V_80;
}
for ( V_37 = 0 ; V_37 < V_12 -> V_485 ; V_37 ++ ) {
V_130 = & V_12 -> V_129 [ V_37 ] ;
if ( V_130 -> V_484 -> V_235 == 0 )
continue;
if ( memcmp ( & V_32 -> V_211 ,
& V_130 -> V_484 -> V_132 ,
sizeof( V_130 -> V_484 -> V_132 ) ) == 0 ) {
F_144 ( L_74 ,
V_29 -> V_8 . V_8 . V_238 , V_130 -> V_134 ,
V_130 -> V_484 -> V_235 ,
V_130 -> V_90 ) ;
goto V_80;
}
}
for ( V_37 = 0 ; V_37 < V_12 -> V_485 ; V_37 ++ ) {
V_130 = & V_12 -> V_129 [ V_37 ] ;
if ( V_130 -> V_484 -> V_235 == 0 ) {
F_144 ( L_75 ,
V_29 -> V_8 . V_8 . V_238 , V_130 -> V_134 ) ;
goto V_80;
}
}
return NULL ;
V_80:
if ( V_130 -> V_484 -> V_235 == 0 )
V_130 -> V_484 -> V_132 = V_32 -> V_211 ;
V_32 -> V_128 = V_37 ;
F_141 ( L_76 , V_130 -> V_134 ,
F_71 ( V_29 -> V_4 ) ) ;
V_130 -> V_484 -> V_235 |= 1 << V_29 -> V_4 ;
return V_130 ;
}
static int F_324 ( struct V_11 * V_12 ,
unsigned V_486 )
{
struct V_127 * V_130 ;
enum V_483 V_37 ;
for ( V_37 = 0 ; V_37 < V_12 -> V_485 ; V_37 ++ ) {
V_130 = & V_12 -> V_129 [ V_37 ] ;
V_130 -> V_484 = F_325 ( & V_130 -> V_93 , sizeof V_130 -> V_93 ,
V_487 ) ;
if ( ! V_130 -> V_484 )
goto V_488;
V_130 -> V_484 -> V_235 &= ~ V_486 ;
}
return 0 ;
V_488:
while ( -- V_37 >= 0 ) {
V_130 = & V_12 -> V_129 [ V_37 ] ;
F_210 ( V_130 -> V_484 ) ;
V_130 -> V_484 = NULL ;
}
return - V_489 ;
}
static void F_326 ( struct V_11 * V_12 )
{
struct V_127 * V_130 ;
enum V_483 V_37 ;
for ( V_37 = 0 ; V_37 < V_12 -> V_485 ; V_37 ++ ) {
V_130 = & V_12 -> V_129 [ V_37 ] ;
F_3 ( V_130 -> V_484 == & V_130 -> V_93 ) ;
V_130 -> V_93 = * V_130 -> V_484 ;
F_210 ( V_130 -> V_484 ) ;
V_130 -> V_484 = NULL ;
}
}
static void F_327 ( struct V_11 * V_12 )
{
struct V_127 * V_130 ;
enum V_483 V_37 ;
for ( V_37 = 0 ; V_37 < V_12 -> V_485 ; V_37 ++ ) {
V_130 = & V_12 -> V_129 [ V_37 ] ;
F_3 ( V_130 -> V_484 == & V_130 -> V_93 ) ;
F_210 ( V_130 -> V_484 ) ;
V_130 -> V_484 = NULL ;
}
}
static void F_328 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_490 = F_42 ( V_4 ) ;
T_1 V_402 ;
V_402 = F_5 ( V_490 ) ;
F_122 ( 500 ) ;
if ( F_47 ( F_5 ( V_490 ) != V_402 , 5 ) ) {
if ( F_47 ( F_5 ( V_490 ) != V_402 , 5 ) )
F_123 ( L_77 , F_71 ( V_4 ) ) ;
}
}
static void F_329 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_93 -> V_400 . V_120 ) {
F_120 ( F_330 ( V_4 ) , V_491 ) ;
F_120 ( F_331 ( V_4 ) , V_29 -> V_93 -> V_400 . V_492 ) ;
F_120 ( F_332 ( V_4 ) , V_29 -> V_93 -> V_400 . V_339 ) ;
}
}
static void F_333 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_93 -> V_400 . V_120 ) {
if ( F_267 ( V_10 ) || F_225 ( V_10 ) )
F_120 ( F_263 ( V_4 ) , V_493 | V_494 |
F_334 ( V_4 ) ) ;
else
F_120 ( F_263 ( V_4 ) , V_493 | V_494 ) ;
F_120 ( F_264 ( V_4 ) , V_29 -> V_93 -> V_400 . V_492 ) ;
F_120 ( F_265 ( V_4 ) , V_29 -> V_93 -> V_400 . V_339 ) ;
}
}
static void F_335 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_4 V_4 = F_31 ( V_29 ) -> V_4 ;
struct V_261 * V_164 ;
struct V_369 * V_369 ;
F_336 (plane, &dev->mode_config.plane_list) {
V_369 = F_232 ( V_164 ) ;
if ( V_369 -> V_4 == V_4 )
F_337 ( & V_369 -> V_8 ) ;
}
}
static void F_338 ( struct V_261 * V_164 )
{
struct V_369 * V_369 = F_232 ( V_164 ) ;
struct V_280 * V_34 =
V_164 -> V_495 -> V_496 ( V_164 ) ;
struct V_497 * V_498 = F_339 ( V_34 ) ;
V_498 -> V_499 = false ;
V_369 -> V_500 ( V_164 , V_498 ) ;
F_340 ( V_164 , V_34 ) ;
}
static void F_341 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_4 V_4 = F_31 ( V_29 ) -> V_4 ;
struct V_261 * V_164 ;
struct V_369 * V_369 ;
F_336 (plane, &dev->mode_config.plane_list) {
V_369 = F_232 ( V_164 ) ;
if ( V_164 -> V_92 && V_369 -> V_4 == V_4 )
F_338 ( V_164 ) ;
}
}
void F_342 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_93 -> V_501 )
return;
F_171 ( V_10 , V_29 -> V_4 ) ;
F_343 ( V_12 , V_29 -> V_164 ) ;
if ( F_170 ( V_10 ) ) {
F_56 ( & V_12 -> V_502 . V_503 ) ;
F_3 ( F_344 ( V_12 , V_504 , 0xc0000000 ) ) ;
F_58 ( & V_12 -> V_502 . V_503 ) ;
} else {
F_120 ( V_505 , V_506 ) ;
if ( F_47 ( F_345 ( V_505 ) & V_506 , 50 ) )
F_123 ( L_78 ) ;
}
}
void F_346 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_93 -> V_501 )
return;
F_343 ( V_12 , V_29 -> V_164 ) ;
if ( F_170 ( V_10 ) ) {
F_56 ( & V_12 -> V_502 . V_503 ) ;
F_3 ( F_344 ( V_12 , V_504 , 0 ) ) ;
F_58 ( & V_12 -> V_502 . V_503 ) ;
if ( F_47 ( ( F_5 ( V_505 ) & V_506 ) == 0 , 42 ) )
F_123 ( L_79 ) ;
} else {
F_120 ( V_505 , 0 ) ;
F_121 ( V_505 ) ;
}
F_171 ( V_10 , V_29 -> V_4 ) ;
}
static void F_347 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
int V_507 = F_348 ( V_4 ) ;
int V_37 ;
bool V_508 = false ;
if ( ! V_29 -> V_34 -> V_240 || ! V_28 -> V_90 )
return;
if ( ! F_4 ( V_12 -> V_10 ) ) {
if ( F_10 ( V_28 , V_257 ) )
F_161 ( V_12 ) ;
else
F_162 ( V_12 , V_4 ) ;
}
if ( ! F_349 ( V_10 ) )
V_507 = F_350 ( V_4 ) ;
if ( F_225 ( V_10 ) && V_28 -> V_93 -> V_501 &&
( ( F_5 ( F_351 ( V_4 ) ) & V_509 ) ==
V_510 ) ) {
F_346 ( V_28 ) ;
V_508 = true ;
}
for ( V_37 = 0 ; V_37 < 256 ; V_37 ++ ) {
F_120 ( V_507 + 4 * V_37 ,
( V_28 -> V_511 [ V_37 ] << 16 ) |
( V_28 -> V_512 [ V_37 ] << 8 ) |
V_28 -> V_513 [ V_37 ] ) ;
}
if ( V_508 )
F_342 ( V_28 ) ;
}
static void F_352 ( struct V_28 * V_28 , bool V_240 )
{
if ( ! V_240 && V_28 -> V_514 ) {
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_56 ( & V_10 -> V_299 ) ;
V_12 -> V_300 . V_301 = false ;
( void ) F_353 ( V_28 -> V_514 ) ;
V_12 -> V_300 . V_301 = true ;
F_58 ( & V_10 -> V_299 ) ;
}
}
static void F_354 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
F_168 ( V_29 -> V_91 , V_29 ) ;
F_335 ( V_29 ) ;
F_355 ( V_29 , true ) ;
F_352 ( V_28 , true ) ;
F_342 ( V_28 ) ;
F_56 ( & V_10 -> V_299 ) ;
F_356 ( V_10 ) ;
F_58 ( & V_10 -> V_299 ) ;
F_357 ( V_10 , F_358 ( V_4 ) ) ;
}
static void F_359 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
F_288 ( V_29 ) ;
if ( V_12 -> V_515 . V_29 == V_28 )
F_360 ( V_10 ) ;
F_346 ( V_28 ) ;
F_352 ( V_28 , false ) ;
F_355 ( V_29 , false ) ;
F_341 ( V_29 ) ;
F_172 ( V_29 -> V_91 , V_29 ) ;
F_357 ( V_10 , F_358 ( V_4 ) ) ;
}
static void F_361 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
F_3 ( ! V_29 -> V_34 -> V_240 ) ;
if ( V_28 -> V_90 )
return;
if ( V_28 -> V_93 -> V_258 )
F_140 ( V_28 ) ;
if ( V_28 -> V_93 -> V_471 )
F_362 ( V_28 , V_516 ) ;
F_363 ( V_28 ) ;
if ( V_28 -> V_93 -> V_258 ) {
F_364 ( V_28 ,
& V_28 -> V_93 -> V_517 , NULL ) ;
}
F_365 ( V_29 ) ;
V_28 -> V_90 = true ;
F_366 ( V_12 , V_4 , true ) ;
F_367 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_518 )
V_6 -> V_518 ( V_6 ) ;
if ( V_28 -> V_93 -> V_258 ) {
F_278 ( V_28 ) ;
} else {
F_155 ( V_12 , V_4 ) ;
F_156 ( V_12 , V_4 ) ;
}
F_333 ( V_28 ) ;
F_347 ( V_29 ) ;
F_368 ( V_29 ) ;
F_158 ( V_28 ) ;
if ( V_28 -> V_93 -> V_258 )
F_315 ( V_29 ) ;
F_91 ( V_29 ) ;
F_369 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_240 ( V_6 ) ;
if ( F_96 ( V_10 ) )
F_328 ( V_10 , V_28 -> V_4 ) ;
F_354 ( V_29 ) ;
}
static bool F_370 ( struct V_28 * V_29 )
{
return F_371 ( V_29 -> V_8 . V_10 ) && V_29 -> V_4 == V_142 ;
}
static void F_372 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_28 * V_519 , * V_520 = NULL ;
F_131 (dev, crtc_it) {
if ( ! V_519 -> V_90 || V_519 == V_29 )
continue;
if ( V_520 )
return;
V_520 = V_519 ;
}
if ( ! V_520 )
return;
F_171 ( V_10 , V_520 -> V_4 ) ;
F_171 ( V_10 , V_520 -> V_4 ) ;
}
static void F_373 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
F_3 ( ! V_29 -> V_34 -> V_240 ) ;
if ( V_28 -> V_90 )
return;
if ( F_59 ( V_28 ) )
F_143 ( V_28 ) ;
if ( V_28 -> V_93 -> V_471 )
F_362 ( V_28 , V_516 ) ;
F_363 ( V_28 ) ;
if ( V_28 -> V_93 -> V_98 != V_521 ) {
F_120 ( F_374 ( V_28 -> V_93 -> V_98 ) ,
V_28 -> V_93 -> V_522 - 1 ) ;
}
if ( V_28 -> V_93 -> V_258 ) {
F_364 ( V_28 ,
& V_28 -> V_93 -> V_517 , NULL ) ;
}
F_375 ( V_29 ) ;
F_376 ( V_29 ) ;
V_28 -> V_90 = true ;
F_366 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_518 )
V_6 -> V_518 ( V_6 ) ;
if ( V_28 -> V_93 -> V_258 ) {
F_367 ( V_12 , V_252 ,
true ) ;
V_12 -> V_263 . V_467 ( V_29 ) ;
}
F_377 ( V_28 ) ;
if ( F_378 ( V_10 ) )
F_329 ( V_28 ) ;
else
F_333 ( V_28 ) ;
F_347 ( V_29 ) ;
F_379 ( V_29 ) ;
F_380 ( V_29 ) ;
F_368 ( V_29 ) ;
F_158 ( V_28 ) ;
if ( V_28 -> V_93 -> V_258 )
F_321 ( V_29 ) ;
if ( V_28 -> V_93 -> V_523 )
F_381 ( V_29 , true ) ;
F_91 ( V_29 ) ;
F_369 ( V_29 ) ;
F_11 (dev, crtc, encoder) {
V_6 -> V_240 ( V_6 ) ;
F_382 ( V_6 , true ) ;
}
F_372 ( V_28 ) ;
F_354 ( V_29 ) ;
}
static void F_383 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_93 -> V_400 . V_120 ) {
F_120 ( F_330 ( V_4 ) , 0 ) ;
F_120 ( F_331 ( V_4 ) , 0 ) ;
F_120 ( F_332 ( V_4 ) , 0 ) ;
}
}
static void F_384 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_93 -> V_400 . V_120 ) {
F_120 ( F_263 ( V_4 ) , 0 ) ;
F_120 ( F_264 ( V_4 ) , 0 ) ;
F_120 ( F_265 ( V_4 ) , 0 ) ;
}
}
static void F_385 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_402 ;
if ( ! V_28 -> V_90 )
return;
F_359 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_241 ( V_6 ) ;
F_386 ( V_29 ) ;
F_91 ( V_29 ) ;
if ( V_28 -> V_93 -> V_258 )
F_367 ( V_12 , V_4 , false ) ;
F_164 ( V_28 ) ;
F_384 ( V_28 ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_524 )
V_6 -> V_524 ( V_6 ) ;
if ( V_28 -> V_93 -> V_258 ) {
F_280 ( V_29 ) ;
F_154 ( V_12 , V_4 ) ;
if ( F_96 ( V_10 ) ) {
V_99 = F_100 ( V_4 ) ;
V_402 = F_5 ( V_99 ) ;
V_402 &= ~ ( V_475 |
V_182 ) ;
V_402 |= V_525 ;
F_120 ( V_99 , V_402 ) ;
V_402 = F_5 ( V_469 ) ;
V_402 &= ~ ( F_318 ( V_4 ) | F_319 ( V_4 ) ) ;
F_120 ( V_469 , V_402 ) ;
}
F_147 ( V_28 ) ;
F_279 ( V_28 ) ;
}
V_28 -> V_90 = false ;
F_368 ( V_29 ) ;
F_56 ( & V_10 -> V_299 ) ;
F_356 ( V_10 ) ;
F_58 ( & V_10 -> V_299 ) ;
}
static void F_387 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_1 * V_6 ;
enum V_96 V_98 = V_28 -> V_93 -> V_98 ;
if ( ! V_28 -> V_90 )
return;
F_359 ( V_29 ) ;
F_11 (dev, crtc, encoder) {
F_382 ( V_6 , false ) ;
V_6 -> V_241 ( V_6 ) ;
}
F_386 ( V_29 ) ;
F_91 ( V_29 ) ;
if ( V_28 -> V_93 -> V_258 )
F_367 ( V_12 , V_252 ,
false ) ;
F_164 ( V_28 ) ;
if ( V_28 -> V_93 -> V_523 )
F_381 ( V_29 , false ) ;
F_388 ( V_12 , V_98 ) ;
if ( F_378 ( V_10 ) )
F_383 ( V_28 ) ;
else
F_384 ( V_28 ) ;
F_389 ( V_28 ) ;
if ( V_28 -> V_93 -> V_258 ) {
F_157 ( V_12 ) ;
F_390 ( V_29 ) ;
}
F_11 (dev, crtc, encoder)
if ( V_6 -> V_524 )
V_6 -> V_524 ( V_6 ) ;
V_28 -> V_90 = false ;
F_368 ( V_29 ) ;
F_56 ( & V_10 -> V_299 ) ;
F_356 ( V_10 ) ;
F_58 ( & V_10 -> V_299 ) ;
if ( F_59 ( V_28 ) )
F_147 ( V_28 ) ;
}
static void F_391 ( struct V_89 * V_29 )
{
struct V_28 * V_28 = F_31 ( V_29 ) ;
F_322 ( V_28 ) ;
}
static void F_392 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_31 * V_210 = V_29 -> V_93 ;
if ( ! V_210 -> V_526 . V_527 )
return;
F_3 ( F_5 ( V_528 ) & V_529 ) ;
F_117 ( V_12 , V_29 -> V_4 ) ;
F_120 ( V_530 , V_210 -> V_526 . V_531 ) ;
F_120 ( V_528 , V_210 -> V_526 . V_527 ) ;
F_120 ( F_393 ( V_29 -> V_4 ) , 0 ) ;
}
static enum V_532 F_394 ( enum V_108 V_108 )
{
switch ( V_108 ) {
case V_533 :
return V_534 ;
case V_110 :
return V_535 ;
case V_112 :
return V_536 ;
case V_114 :
return V_537 ;
default:
F_35 ( 1 ) ;
return V_538 ;
}
}
enum V_532
F_395 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_8 . V_10 ;
struct V_107 * V_539 ;
switch ( V_1 -> type ) {
case V_540 :
F_35 ( ! F_62 ( V_10 ) ) ;
case V_541 :
case V_52 :
case V_401 :
V_539 = F_396 ( & V_1 -> V_8 ) ;
return F_394 ( V_539 -> V_108 ) ;
case V_542 :
V_539 = F_397 ( & V_1 -> V_8 ) -> V_91 ;
return F_394 ( V_539 -> V_108 ) ;
case V_53 :
return V_543 ;
case V_257 :
return V_544 ;
default:
return V_538 ;
}
}
static unsigned long F_398 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_1 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
unsigned long V_545 ;
enum V_96 V_96 ;
V_96 = F_40 ( V_10 -> V_13 , V_4 ) ;
V_545 = F_220 ( F_399 ( V_4 ) ) ;
V_545 |= F_220 ( F_78 ( V_96 ) ) ;
if ( V_28 -> V_93 -> V_400 . V_120 ||
V_28 -> V_93 -> V_400 . V_546 )
V_545 |= F_220 ( F_400 ( V_4 ) ) ;
F_11 (dev, crtc, intel_encoder)
V_545 |= F_220 ( F_395 ( V_1 ) ) ;
return V_545 ;
}
static void F_401 ( struct V_33 * V_34 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned long V_547 [ V_548 ] = { 0 , } ;
struct V_28 * V_29 ;
F_131 (dev, crtc) {
enum V_532 V_549 ;
if ( ! V_29 -> V_8 . V_34 -> V_240 )
continue;
V_547 [ V_29 -> V_4 ] = F_398 ( & V_29 -> V_8 ) ;
F_402 (domain, pipe_domains[crtc->pipe])
F_146 ( V_12 , V_549 ) ;
}
if ( V_12 -> V_263 . V_550 )
V_12 -> V_263 . V_550 ( V_34 ) ;
F_131 (dev, crtc) {
enum V_532 V_549 ;
F_402 (domain, crtc->enabled_power_domains)
F_148 ( V_12 , V_549 ) ;
V_29 -> V_551 = V_547 [ V_29 -> V_4 ] ;
}
F_403 ( V_12 , false ) ;
}
static int F_404 ( struct V_11 * V_12 )
{
int V_552 , V_553 [] = { 800 , 1600 , 2000 , 2400 } ;
F_56 ( & V_12 -> V_124 ) ;
V_552 = F_57 ( V_12 , V_554 ) &
V_555 ;
F_58 ( & V_12 -> V_124 ) ;
return V_553 [ V_552 ] * 1000 ;
}
static void F_405 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_556 = V_12 -> V_263 . V_557 ( V_10 ) ;
F_141 ( L_80 ,
V_12 -> V_556 ) ;
F_120 ( V_558 , F_406 ( V_12 -> V_556 , 1000 ) ) ;
}
static void F_407 ( struct V_9 * V_10 , int V_559 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_121 , V_560 ;
F_3 ( V_12 -> V_263 . V_557 ( V_10 ) != V_12 -> V_556 ) ;
if ( V_559 >= 320000 )
V_560 = 2 ;
else if ( V_559 == 266667 )
V_560 = 1 ;
else
V_560 = 0 ;
F_56 ( & V_12 -> V_502 . V_503 ) ;
V_121 = F_408 ( V_12 , V_561 ) ;
V_121 &= ~ V_562 ;
V_121 |= ( V_560 << V_563 ) ;
F_409 ( V_12 , V_561 , V_121 ) ;
if ( F_47 ( ( F_408 ( V_12 , V_561 ) &
V_564 ) == ( V_560 << V_565 ) ,
50 ) ) {
F_123 ( L_81 ) ;
}
F_58 ( & V_12 -> V_502 . V_503 ) ;
if ( V_559 == 400000 ) {
T_1 V_566 ;
V_566 = F_9 ( V_12 -> V_552 << 1 , V_559 ) - 1 ;
F_56 ( & V_12 -> V_124 ) ;
V_121 = F_57 ( V_12 , V_567 ) ;
V_121 &= ~ V_568 ;
V_121 |= V_566 ;
F_410 ( V_12 , V_567 , V_121 ) ;
if ( F_47 ( ( F_57 ( V_12 , V_567 ) &
V_569 ) == ( V_566 << V_570 ) ,
50 ) )
F_123 ( L_81 ) ;
F_58 ( & V_12 -> V_124 ) ;
}
F_56 ( & V_12 -> V_124 ) ;
V_121 = F_411 ( V_12 , V_571 ) ;
V_121 &= ~ 0x7f ;
if ( V_559 == 400000 )
V_121 |= 4500 / 250 ;
else
V_121 |= 3000 / 250 ;
F_412 ( V_12 , V_571 , V_121 ) ;
F_58 ( & V_12 -> V_124 ) ;
F_405 ( V_10 ) ;
}
static void F_413 ( struct V_9 * V_10 , int V_559 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_121 , V_560 ;
F_3 ( V_12 -> V_263 . V_557 ( V_10 ) != V_12 -> V_556 ) ;
switch ( V_559 ) {
case 333333 :
case 320000 :
case 266667 :
case 200000 :
break;
default:
F_178 ( V_559 ) ;
return;
}
V_560 = F_9 ( V_12 -> V_552 << 1 , V_559 ) - 1 ;
F_56 ( & V_12 -> V_502 . V_503 ) ;
V_121 = F_408 ( V_12 , V_561 ) ;
V_121 &= ~ V_572 ;
V_121 |= ( V_560 << V_573 ) ;
F_409 ( V_12 , V_561 , V_121 ) ;
if ( F_47 ( ( F_408 ( V_12 , V_561 ) &
V_574 ) == ( V_560 << V_575 ) ,
50 ) ) {
F_123 ( L_81 ) ;
}
F_58 ( & V_12 -> V_502 . V_503 ) ;
F_405 ( V_10 ) ;
}
static int F_414 ( struct V_11 * V_12 ,
int V_576 )
{
int V_577 = ( V_12 -> V_552 << 1 ) % 320000 != 0 ? 333333 : 320000 ;
int V_43 = F_20 ( V_12 ) ? 95 : 90 ;
if ( ! F_20 ( V_12 ) &&
V_576 > V_577 * V_43 / 100 )
return 400000 ;
else if ( V_576 > 266667 * V_43 / 100 )
return V_577 ;
else if ( V_576 > 0 )
return 266667 ;
else
return 200000 ;
}
static int F_415 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_28 * V_28 ;
int V_576 = 0 ;
F_131 (dev, intel_crtc) {
if ( V_28 -> V_578 )
V_576 = V_70 ( V_576 ,
V_28 -> V_484 -> V_8 . V_94 . V_95 ) ;
}
return V_576 ;
}
static void F_416 ( struct V_9 * V_10 ,
unsigned * V_579 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 ;
int V_576 = F_415 ( V_12 ) ;
if ( F_414 ( V_12 , V_576 ) ==
V_12 -> V_556 )
return;
F_131 (dev, intel_crtc)
if ( V_28 -> V_8 . V_34 -> V_240 )
* V_579 |= ( 1 << V_28 -> V_4 ) ;
}
static void F_417 ( struct V_11 * V_12 )
{
unsigned int V_580 , V_581 ;
if ( F_20 ( V_12 ) )
V_581 = F_418 ( 12 ) ;
else
V_581 = F_418 ( 8 ) ;
if ( F_9 ( V_12 -> V_556 , 1000 ) >= V_12 -> V_502 . V_582 ) {
if ( F_20 ( V_12 ) )
V_580 = V_583 ;
else
V_580 = F_418 ( 15 ) ;
} else {
V_580 = V_581 ;
}
F_120 ( V_584 , V_585 |
V_581 ) ;
F_120 ( V_584 , V_585 |
V_580 | V_586 ) ;
F_3 ( F_5 ( V_584 ) & V_586 ) ;
}
static void F_419 ( struct V_33 * V_34 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_576 = F_415 ( V_12 ) ;
int V_587 = F_414 ( V_12 , V_576 ) ;
if ( V_587 != V_12 -> V_556 ) {
F_146 ( V_12 , V_588 ) ;
if ( F_20 ( V_10 ) )
F_413 ( V_10 , V_587 ) ;
else
F_407 ( V_10 , V_587 ) ;
F_417 ( V_12 ) ;
F_148 ( V_12 , V_588 ) ;
}
}
static void F_420 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = F_245 ( V_10 ) ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
bool V_589 ;
F_3 ( ! V_29 -> V_34 -> V_240 ) ;
if ( V_28 -> V_90 )
return;
V_589 = F_10 ( V_28 , V_257 ) ;
if ( ! V_589 ) {
if ( F_20 ( V_10 ) )
F_421 ( V_28 , V_28 -> V_93 ) ;
else
F_422 ( V_28 , V_28 -> V_93 ) ;
}
if ( V_28 -> V_93 -> V_471 )
F_362 ( V_28 , V_516 ) ;
F_363 ( V_28 ) ;
if ( F_20 ( V_10 ) && V_4 == V_151 ) {
struct V_11 * V_12 = V_10 -> V_13 ;
F_120 ( F_423 ( V_4 ) , V_590 ) ;
F_120 ( F_424 ( V_4 ) , 0 ) ;
}
F_425 ( V_28 ) ;
V_28 -> V_90 = true ;
F_366 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_591 )
V_6 -> V_591 ( V_6 ) ;
if ( ! V_589 ) {
if ( F_20 ( V_10 ) )
F_125 ( V_28 , V_28 -> V_93 ) ;
else
F_116 ( V_28 , V_28 -> V_93 ) ;
}
F_11 (dev, crtc, encoder)
if ( V_6 -> V_518 )
V_6 -> V_518 ( V_6 ) ;
F_392 ( V_28 ) ;
F_347 ( V_29 ) ;
F_368 ( V_29 ) ;
F_158 ( V_28 ) ;
F_91 ( V_29 ) ;
F_369 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_240 ( V_6 ) ;
F_354 ( V_29 ) ;
F_426 ( V_12 ) ;
}
static void F_427 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_120 ( F_428 ( V_29 -> V_4 ) , V_29 -> V_93 -> V_211 . V_592 ) ;
F_120 ( F_429 ( V_29 -> V_4 ) , V_29 -> V_93 -> V_211 . V_593 ) ;
}
static void F_430 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = F_245 ( V_10 ) ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
F_3 ( ! V_29 -> V_34 -> V_240 ) ;
if ( V_28 -> V_90 )
return;
F_427 ( V_28 ) ;
if ( V_28 -> V_93 -> V_471 )
F_362 ( V_28 , V_516 ) ;
F_363 ( V_28 ) ;
F_425 ( V_28 ) ;
V_28 -> V_90 = true ;
if ( ! F_22 ( V_10 ) )
F_366 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_518 )
V_6 -> V_518 ( V_6 ) ;
F_132 ( V_28 ) ;
F_392 ( V_28 ) ;
F_347 ( V_29 ) ;
F_368 ( V_29 ) ;
F_158 ( V_28 ) ;
F_91 ( V_29 ) ;
F_369 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_240 ( V_6 ) ;
F_354 ( V_29 ) ;
if ( F_22 ( V_10 ) )
F_366 ( V_12 , V_4 , true ) ;
F_426 ( V_12 ) ;
}
static void F_431 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_93 -> V_526 . V_527 )
return;
F_117 ( V_12 , V_29 -> V_4 ) ;
F_141 ( L_82 ,
F_5 ( V_528 ) ) ;
F_120 ( V_528 , 0 ) ;
}
static void F_432 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
if ( ! V_28 -> V_90 )
return;
if ( F_22 ( V_10 ) )
F_366 ( V_12 , V_4 , false ) ;
F_433 ( V_12 , false ) ;
F_359 ( V_29 ) ;
F_171 ( V_10 , V_4 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_241 ( V_6 ) ;
F_386 ( V_29 ) ;
F_91 ( V_29 ) ;
F_164 ( V_28 ) ;
F_431 ( V_28 ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_524 )
V_6 -> V_524 ( V_6 ) ;
if ( ! F_10 ( V_28 , V_257 ) ) {
if ( F_20 ( V_10 ) )
F_136 ( V_12 , V_4 ) ;
else if ( F_21 ( V_10 ) )
F_135 ( V_12 , V_4 ) ;
else
F_134 ( V_28 ) ;
}
if ( ! F_22 ( V_10 ) )
F_366 ( V_12 , V_4 , false ) ;
V_28 -> V_90 = false ;
F_368 ( V_29 ) ;
F_56 ( & V_10 -> V_299 ) ;
F_356 ( V_10 ) ;
F_58 ( & V_10 -> V_299 ) ;
}
static void F_434 ( struct V_89 * V_29 )
{
}
void F_435 ( struct V_89 * V_29 , bool V_240 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
enum V_532 V_549 ;
unsigned long V_594 ;
if ( V_240 ) {
if ( ! V_28 -> V_90 ) {
V_594 = F_398 ( V_29 ) ;
F_402 (domain, domains)
F_146 ( V_12 , V_549 ) ;
V_28 -> V_551 = V_594 ;
V_12 -> V_263 . V_595 ( V_29 ) ;
}
} else {
if ( V_28 -> V_90 ) {
V_12 -> V_263 . V_385 ( V_29 ) ;
V_594 = V_28 -> V_551 ;
F_402 (domain, domains)
F_148 ( V_12 , V_549 ) ;
V_28 -> V_551 = 0 ;
}
}
}
void F_436 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_1 ;
bool V_240 = false ;
F_11 (dev, crtc, intel_encoder)
V_240 |= V_1 -> V_596 ;
F_435 ( V_29 , V_240 ) ;
}
static void F_437 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_597 * V_3 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_3 ( ! V_29 -> V_34 -> V_240 ) ;
V_12 -> V_263 . V_385 ( V_29 ) ;
V_12 -> V_263 . V_598 ( V_29 ) ;
V_29 -> V_91 -> V_495 -> V_599 ( V_29 -> V_91 ) ;
F_438 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_3 -> V_6 || ! V_3 -> V_6 -> V_29 )
continue;
if ( V_3 -> V_6 -> V_29 != V_29 )
continue;
V_3 -> V_600 = V_601 ;
F_13 ( V_3 -> V_6 ) -> V_596 = false ;
}
}
void F_439 ( struct V_602 * V_6 )
{
struct V_1 * V_1 = F_13 ( V_6 ) ;
F_440 ( V_6 ) ;
F_210 ( V_1 ) ;
}
static void F_441 ( struct V_1 * V_6 , int V_477 )
{
if ( V_477 == V_603 ) {
V_6 -> V_596 = true ;
F_436 ( V_6 -> V_8 . V_29 ) ;
} else {
V_6 -> V_596 = false ;
F_436 ( V_6 -> V_8 . V_29 ) ;
}
}
static void F_442 ( struct V_2 * V_3 )
{
if ( V_3 -> V_133 ( V_3 ) ) {
struct V_1 * V_6 = V_3 -> V_6 ;
struct V_89 * V_29 ;
bool V_604 ;
enum V_4 V_4 ;
F_144 ( L_83 ,
V_3 -> V_8 . V_8 . V_238 ,
V_3 -> V_8 . V_134 ) ;
if ( V_3 -> V_5 )
return;
F_54 ( V_3 -> V_8 . V_600 == V_601 ,
L_84 ) ;
F_54 ( V_3 -> V_8 . V_6 != & V_6 -> V_8 ,
L_85 ) ;
if ( V_6 ) {
F_54 ( ! V_6 -> V_596 ,
L_86 ) ;
V_604 = V_6 -> V_133 ( V_6 , & V_4 ) ;
F_54 ( ! V_604 , L_87 ) ;
if ( F_92 ( ! V_6 -> V_8 . V_29 ) )
return;
V_29 = V_6 -> V_8 . V_29 ;
F_54 ( ! V_29 -> V_34 -> V_240 ,
L_88 ) ;
F_54 ( ! F_31 ( V_29 ) -> V_90 , L_89 ) ;
F_54 ( V_4 != F_31 ( V_29 ) -> V_4 ,
L_90 ) ;
}
}
}
int F_443 ( struct V_2 * V_3 )
{
struct V_35 * V_36 ;
V_36 = F_444 ( sizeof *V_36 , V_487 ) ;
if ( ! V_36 )
return - V_489 ;
V_3 -> V_8 . V_34 = V_36 ;
return 0 ;
}
struct V_2 * F_445 ( void )
{
struct V_2 * V_3 ;
V_3 = F_444 ( sizeof *V_3 , V_487 ) ;
if ( ! V_3 )
return NULL ;
if ( F_443 ( V_3 ) < 0 ) {
F_210 ( V_3 ) ;
return NULL ;
}
return V_3 ;
}
void F_446 ( struct V_597 * V_3 , int V_477 )
{
if ( V_477 != V_603 )
V_477 = V_601 ;
if ( V_477 == V_3 -> V_600 )
return;
V_3 -> V_600 = V_477 ;
if ( V_3 -> V_6 )
F_441 ( F_13 ( V_3 -> V_6 ) , V_477 ) ;
F_447 ( V_3 -> V_10 ) ;
}
bool F_448 ( struct V_2 * V_3 )
{
enum V_4 V_4 = 0 ;
struct V_1 * V_6 = V_3 -> V_6 ;
return V_6 -> V_133 ( V_6 , & V_4 ) ;
}
static int F_449 ( struct V_9 * V_10 , enum V_4 V_4 )
{
struct V_28 * V_29 =
F_31 ( F_450 ( V_10 , V_4 ) ) ;
if ( V_29 -> V_8 . V_34 -> V_240 &&
V_29 -> V_93 -> V_258 )
return V_29 -> V_93 -> V_415 ;
return 0 ;
}
static bool F_451 ( struct V_9 * V_10 , enum V_4 V_4 ,
struct V_31 * V_210 )
{
F_144 ( L_91 ,
F_71 ( V_4 ) , V_210 -> V_415 ) ;
if ( V_210 -> V_415 > 4 ) {
F_144 ( L_92 ,
F_71 ( V_4 ) , V_210 -> V_415 ) ;
return false ;
}
if ( F_225 ( V_10 ) || F_170 ( V_10 ) ) {
if ( V_210 -> V_415 > 2 ) {
F_144 ( L_93 ,
V_210 -> V_415 ) ;
return false ;
} else {
return true ;
}
}
if ( F_45 ( V_10 ) -> V_605 == 2 )
return true ;
switch ( V_4 ) {
case V_142 :
return true ;
case V_151 :
if ( V_210 -> V_415 > 2 &&
F_449 ( V_10 , V_465 ) > 0 ) {
F_144 ( L_94 ,
F_71 ( V_4 ) , V_210 -> V_415 ) ;
return false ;
}
return true ;
case V_465 :
if ( V_210 -> V_415 > 2 ) {
F_144 ( L_95 ,
F_71 ( V_4 ) , V_210 -> V_415 ) ;
return false ;
}
if ( F_449 ( V_10 , V_151 ) > 2 ) {
F_144 ( L_96 ) ;
return false ;
}
return true ;
default:
F_138 () ;
}
}
static int F_452 ( struct V_28 * V_28 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_395 * V_94 = & V_210 -> V_8 . V_94 ;
int V_606 , V_607 , V_608 ;
bool V_609 , V_610 = false ;
V_420:
V_607 = F_6 ( V_10 ) * F_453 ( 100 ) / F_454 ( 1 ) / 10 ;
V_608 = V_94 -> V_95 ;
V_606 = F_455 ( V_608 , V_607 ,
V_210 -> V_611 ) ;
V_210 -> V_415 = V_606 ;
F_456 ( V_210 -> V_611 , V_606 , V_608 ,
V_607 , & V_210 -> V_517 ) ;
V_609 = F_451 ( V_28 -> V_8 . V_10 ,
V_28 -> V_4 , V_210 ) ;
if ( ! V_609 && V_210 -> V_611 > 6 * 3 ) {
V_210 -> V_611 -= 2 * 3 ;
F_144 ( L_97 ,
V_210 -> V_611 ) ;
V_610 = true ;
V_210 -> V_612 = true ;
goto V_420;
}
if ( V_610 )
return V_613 ;
return V_609 ? 0 : - V_292 ;
}
static void F_457 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
V_210 -> V_501 = V_396 . V_614 &&
F_370 ( V_29 ) &&
V_210 -> V_611 <= 24 ;
}
static int F_458 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_395 * V_94 = & V_210 -> V_8 . V_94 ;
if ( F_45 ( V_10 ) -> V_105 < 4 ) {
int V_615 =
V_12 -> V_263 . V_557 ( V_10 ) ;
if ( ( V_29 -> V_4 == V_142 || F_459 ( V_10 ) ) &&
V_94 -> V_95 > V_615 * 9 / 10 ) {
V_615 *= 2 ;
V_210 -> V_259 = true ;
}
if ( V_94 -> V_95 > V_615 * 9 / 10 )
return - V_292 ;
}
if ( ( F_12 ( V_210 , V_44 ) &&
F_15 ( V_10 ) ) || V_210 -> V_259 )
V_210 -> V_357 &= ~ 1 ;
if ( ( F_45 ( V_10 ) -> V_105 > 4 || F_18 ( V_10 ) ) &&
V_94 -> V_616 == V_94 -> V_617 )
return - V_292 ;
if ( ( F_18 ( V_10 ) || F_21 ( V_10 ) ) && V_210 -> V_611 > 10 * 3 ) {
V_210 -> V_611 = 10 * 3 ;
} else if ( F_45 ( V_10 ) -> V_105 <= 4 && V_210 -> V_611 > 8 * 3 ) {
V_210 -> V_611 = 8 * 3 ;
}
if ( F_371 ( V_10 ) )
F_457 ( V_29 , V_210 ) ;
if ( V_210 -> V_258 )
return F_452 ( V_29 , V_210 ) ;
return 0 ;
}
static int F_460 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_121 ;
int V_566 ;
if ( V_12 -> V_552 == 0 )
V_12 -> V_552 = F_404 ( V_12 ) ;
F_56 ( & V_12 -> V_124 ) ;
V_121 = F_57 ( V_12 , V_567 ) ;
F_58 ( & V_12 -> V_124 ) ;
V_566 = V_121 & V_568 ;
F_48 ( ( V_121 & V_569 ) !=
( V_566 << V_570 ) ,
L_98 ) ;
return F_9 ( V_12 -> V_552 << 1 , V_566 + 1 ) ;
}
static int F_461 ( struct V_9 * V_10 )
{
return 400000 ;
}
static int F_462 ( struct V_9 * V_10 )
{
return 333000 ;
}
static int F_463 ( struct V_9 * V_10 )
{
return 200000 ;
}
static int F_464 ( struct V_9 * V_10 )
{
T_5 V_618 = 0 ;
F_465 ( V_10 -> V_619 , V_620 , & V_618 ) ;
switch ( V_618 & V_621 ) {
case V_622 :
return 267000 ;
case V_623 :
return 333000 ;
case V_624 :
return 444000 ;
case V_625 :
return 200000 ;
default:
F_123 ( L_99 , V_618 ) ;
case V_626 :
return 133000 ;
case V_627 :
return 167000 ;
}
}
static int F_466 ( struct V_9 * V_10 )
{
T_5 V_618 = 0 ;
F_465 ( V_10 -> V_619 , V_620 , & V_618 ) ;
if ( V_618 & V_628 )
return 133000 ;
else {
switch ( V_618 & V_621 ) {
case V_629 :
return 333000 ;
default:
case V_630 :
return 190000 ;
}
}
}
static int F_467 ( struct V_9 * V_10 )
{
return 266000 ;
}
static int F_468 ( struct V_9 * V_10 )
{
T_5 V_631 = 0 ;
switch ( V_631 & V_632 ) {
case V_633 :
case V_634 :
return 200000 ;
case V_635 :
return 250000 ;
case V_636 :
return 133000 ;
}
return 0 ;
}
static int F_469 ( struct V_9 * V_10 )
{
return 133000 ;
}
static void
F_470 ( T_4 * V_637 , T_4 * V_638 )
{
while ( * V_637 > V_639 ||
* V_638 > V_639 ) {
* V_637 >>= 1 ;
* V_638 >>= 1 ;
}
}
static void F_471 ( unsigned int V_19 , unsigned int V_25 ,
T_4 * V_640 , T_4 * V_641 )
{
* V_641 = F_472 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_640 = F_36 ( ( V_68 ) V_19 * * V_641 , V_25 ) ;
F_470 ( V_640 , V_641 ) ;
}
void
F_456 ( int V_368 , int V_642 ,
int V_643 , int V_644 ,
struct V_645 * V_646 )
{
V_646 -> V_647 = 64 ;
F_471 ( V_368 * V_643 ,
V_644 * V_642 * 8 ,
& V_646 -> V_648 , & V_646 -> V_649 ) ;
F_471 ( V_643 , V_644 ,
& V_646 -> V_650 , & V_646 -> V_651 ) ;
}
static inline bool F_473 ( struct V_11 * V_12 )
{
if ( V_396 . V_652 >= 0 )
return V_396 . V_652 != 0 ;
return V_12 -> V_653 . V_654
&& ! ( V_12 -> V_160 & V_655 ) ;
}
static int F_474 ( const struct V_31 * V_32 ,
int V_38 )
{
struct V_9 * V_10 = V_32 -> V_8 . V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_18 ;
F_3 ( ! V_32 -> V_8 . V_34 ) ;
if ( F_21 ( V_10 ) ) {
V_18 = 100000 ;
} else if ( F_12 ( V_32 , V_44 ) &&
F_473 ( V_12 ) && V_38 < 2 ) {
V_18 = V_12 -> V_653 . V_656 ;
F_144 ( L_100 , V_18 ) ;
} else if ( ! F_22 ( V_10 ) ) {
V_18 = 96000 ;
} else {
V_18 = 48000 ;
}
return V_18 ;
}
static T_4 F_475 ( struct V_67 * V_67 )
{
return ( 1 << V_67 -> V_25 ) << 16 | V_67 -> V_21 ;
}
static T_4 F_476 ( struct V_67 * V_67 )
{
return V_67 -> V_25 << 16 | V_67 -> V_20 << 8 | V_67 -> V_21 ;
}
static void F_477 ( struct V_28 * V_29 ,
struct V_31 * V_32 ,
T_2 * V_657 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_1 V_658 , V_659 = 0 ;
if ( F_19 ( V_10 ) ) {
V_658 = F_475 ( & V_32 -> V_67 ) ;
if ( V_657 )
V_659 = F_475 ( V_657 ) ;
} else {
V_658 = F_476 ( & V_32 -> V_67 ) ;
if ( V_657 )
V_659 = F_476 ( V_657 ) ;
}
V_32 -> V_211 . V_592 = V_658 ;
V_29 -> V_660 = false ;
if ( F_12 ( V_32 , V_44 ) &&
V_657 ) {
V_32 -> V_211 . V_593 = V_659 ;
V_29 -> V_660 = true ;
} else {
V_32 -> V_211 . V_593 = V_658 ;
}
}
static void F_478 ( struct V_11 * V_12 , enum V_4
V_4 )
{
T_1 V_661 ;
V_661 = F_127 ( V_12 , V_4 , F_479 ( 1 ) ) ;
V_661 &= 0xffffff00 ;
V_661 |= 0x00000030 ;
F_129 ( V_12 , V_4 , F_479 ( 1 ) , V_661 ) ;
V_661 = F_127 ( V_12 , V_4 , V_662 ) ;
V_661 &= 0x8cffffff ;
V_661 = 0x8c000000 ;
F_129 ( V_12 , V_4 , V_662 , V_661 ) ;
V_661 = F_127 ( V_12 , V_4 , F_479 ( 1 ) ) ;
V_661 &= 0xffffff00 ;
F_129 ( V_12 , V_4 , F_479 ( 1 ) , V_661 ) ;
V_661 = F_127 ( V_12 , V_4 , V_662 ) ;
V_661 &= 0x00ffffff ;
V_661 |= 0xb0000000 ;
F_129 ( V_12 , V_4 , V_662 , V_661 ) ;
}
static void F_480 ( struct V_28 * V_29 ,
struct V_645 * V_646 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
F_120 ( F_481 ( V_4 ) , F_482 ( V_646 -> V_647 ) | V_646 -> V_648 ) ;
F_120 ( F_483 ( V_4 ) , V_646 -> V_649 ) ;
F_120 ( F_484 ( V_4 ) , V_646 -> V_650 ) ;
F_120 ( F_485 ( V_4 ) , V_646 -> V_651 ) ;
}
static void F_364 ( struct V_28 * V_29 ,
struct V_645 * V_646 ,
struct V_645 * V_663 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
enum V_96 V_96 = V_29 -> V_93 -> V_98 ;
if ( F_45 ( V_10 ) -> V_105 >= 5 ) {
F_120 ( F_317 ( V_96 ) , F_482 ( V_646 -> V_647 ) | V_646 -> V_648 ) ;
F_120 ( F_486 ( V_96 ) , V_646 -> V_649 ) ;
F_120 ( F_487 ( V_96 ) , V_646 -> V_650 ) ;
F_120 ( F_488 ( V_96 ) , V_646 -> V_651 ) ;
if ( V_663 && ( F_20 ( V_10 ) || F_45 ( V_10 ) -> V_105 < 8 ) &&
V_29 -> V_93 -> V_664 ) {
F_120 ( F_489 ( V_96 ) ,
F_482 ( V_663 -> V_647 ) | V_663 -> V_648 ) ;
F_120 ( F_490 ( V_96 ) , V_663 -> V_649 ) ;
F_120 ( F_491 ( V_96 ) , V_663 -> V_650 ) ;
F_120 ( F_492 ( V_96 ) , V_663 -> V_651 ) ;
}
} else {
F_120 ( F_493 ( V_4 ) , F_482 ( V_646 -> V_647 ) | V_646 -> V_648 ) ;
F_120 ( F_494 ( V_4 ) , V_646 -> V_649 ) ;
F_120 ( F_495 ( V_4 ) , V_646 -> V_650 ) ;
F_120 ( F_496 ( V_4 ) , V_646 -> V_651 ) ;
}
}
void F_362 ( struct V_28 * V_29 , enum V_665 V_646 )
{
struct V_645 * V_666 , * V_667 = NULL ;
if ( V_646 == V_516 ) {
V_666 = & V_29 -> V_93 -> V_666 ;
V_667 = & V_29 -> V_93 -> V_667 ;
} else if ( V_646 == V_668 ) {
V_666 = & V_29 -> V_93 -> V_667 ;
} else {
F_123 ( L_101 ) ;
return;
}
if ( V_29 -> V_93 -> V_258 )
F_480 ( V_29 , & V_29 -> V_93 -> V_666 ) ;
else
F_364 ( V_29 , V_666 , V_667 ) ;
}
static void F_497 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
T_1 V_67 , V_213 ;
V_67 = V_669 | V_220 |
V_670 | V_671 ;
if ( V_29 -> V_4 == V_151 )
V_67 |= V_219 ;
V_67 |= V_123 ;
V_210 -> V_211 . V_67 = V_67 ;
V_213 = ( V_210 -> V_522 - 1 )
<< V_672 ;
V_210 -> V_211 . V_213 = V_213 ;
}
static void F_422 ( struct V_28 * V_29 ,
const struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
T_1 V_673 ;
T_1 V_674 , V_675 , V_676 , V_677 , V_678 ;
T_1 V_679 , V_661 ;
F_56 ( & V_12 -> V_124 ) ;
V_674 = V_210 -> V_67 . V_25 ;
V_675 = V_210 -> V_67 . V_20 ;
V_676 = V_210 -> V_67 . V_21 ;
V_677 = V_210 -> V_67 . V_23 ;
V_678 = V_210 -> V_67 . V_24 ;
if ( V_4 == V_151 )
F_478 ( V_12 , V_4 ) ;
F_129 ( V_12 , V_4 , V_680 , 0x0100000f ) ;
V_661 = F_127 ( V_12 , V_4 , F_498 ( V_4 ) ) ;
V_661 &= 0x00ffffff ;
F_129 ( V_12 , V_4 , F_498 ( V_4 ) , V_661 ) ;
F_129 ( V_12 , V_4 , V_681 , 0x610 ) ;
V_673 = ( ( V_675 << V_682 ) | ( V_676 & V_683 ) ) ;
V_673 |= ( ( V_677 << V_684 ) | ( V_678 << V_685 ) ) ;
V_673 |= ( ( V_674 << V_686 ) ) ;
V_673 |= ( 1 << V_687 ) ;
V_673 |= ( V_688 << V_689 ) ;
F_129 ( V_12 , V_4 , F_499 ( V_4 ) , V_673 ) ;
V_673 |= V_690 ;
F_129 ( V_12 , V_4 , F_499 ( V_4 ) , V_673 ) ;
if ( V_210 -> V_691 == 162000 ||
F_10 ( V_29 , V_53 ) ||
F_10 ( V_29 , V_52 ) )
F_129 ( V_12 , V_4 , F_500 ( V_4 ) ,
0x009f0003 ) ;
else
F_129 ( V_12 , V_4 , F_500 ( V_4 ) ,
0x00d0000f ) ;
if ( V_210 -> V_471 ) {
if ( V_4 == V_142 )
F_129 ( V_12 , V_4 , F_501 ( V_4 ) ,
0x0df40000 ) ;
else
F_129 ( V_12 , V_4 , F_501 ( V_4 ) ,
0x0df70000 ) ;
} else {
if ( V_4 == V_142 )
F_129 ( V_12 , V_4 , F_501 ( V_4 ) ,
0x0df70000 ) ;
else
F_129 ( V_12 , V_4 , F_501 ( V_4 ) ,
0x0df40000 ) ;
}
V_679 = F_127 ( V_12 , V_4 , F_502 ( V_4 ) ) ;
V_679 = ( V_679 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_10 ( V_29 , V_541 ) ||
F_10 ( V_29 , V_401 ) )
V_679 |= 0x01000000 ;
F_129 ( V_12 , V_4 , F_502 ( V_4 ) , V_679 ) ;
F_129 ( V_12 , V_4 , F_503 ( V_4 ) , 0x87871000 ) ;
F_58 ( & V_12 -> V_124 ) ;
}
static void F_504 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
V_210 -> V_211 . V_67 = V_221 |
V_220 | V_670 |
V_123 ;
if ( V_29 -> V_4 != V_142 )
V_210 -> V_211 . V_67 |= V_219 ;
V_210 -> V_211 . V_213 =
( V_210 -> V_522 - 1 ) << V_672 ;
}
static void F_421 ( struct V_28 * V_29 ,
const struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
int V_230 = F_53 ( V_29 -> V_4 ) ;
enum V_214 V_108 = F_126 ( V_4 ) ;
T_1 V_692 , V_693 ;
T_1 V_674 , V_675 , V_676 , V_677 , V_678 , V_694 ;
T_1 V_695 ;
int V_26 ;
V_674 = V_210 -> V_67 . V_25 ;
V_694 = V_210 -> V_67 . V_21 & 0x3fffff ;
V_675 = V_210 -> V_67 . V_20 ;
V_676 = V_210 -> V_67 . V_21 >> 22 ;
V_677 = V_210 -> V_67 . V_23 ;
V_678 = V_210 -> V_67 . V_24 ;
V_26 = V_210 -> V_67 . V_26 ;
V_695 = 0 ;
V_692 = 0 ;
F_120 ( V_230 ,
V_210 -> V_211 . V_67 & ~ V_123 ) ;
F_56 ( & V_12 -> V_124 ) ;
F_129 ( V_12 , V_4 , F_505 ( V_108 ) ,
5 << V_696 |
V_677 << V_697 |
V_678 << V_698 |
1 << V_699 ) ;
F_129 ( V_12 , V_4 , F_506 ( V_108 ) , V_676 ) ;
F_129 ( V_12 , V_4 , F_507 ( V_108 ) ,
V_700 |
1 << V_701 ) ;
if ( V_694 )
F_129 ( V_12 , V_4 , F_508 ( V_108 ) , V_694 ) ;
V_695 = F_127 ( V_12 , V_4 , F_509 ( V_108 ) ) ;
V_695 &= ~ ( V_702 | V_703 ) ;
V_695 |= ( 2 << V_704 ) ;
if ( V_694 )
V_695 |= V_703 ;
F_129 ( V_12 , V_4 , F_509 ( V_108 ) , V_695 ) ;
V_695 = F_127 ( V_12 , V_4 , F_510 ( V_108 ) ) ;
V_695 &= ~ ( V_705 |
V_706 ) ;
V_695 |= ( 0x5 << V_707 ) ;
if ( ! V_694 )
V_695 |= V_706 ;
F_129 ( V_12 , V_4 , F_510 ( V_108 ) , V_695 ) ;
if ( V_26 == 5400000 ) {
V_692 |= ( 0x3 << V_708 ) ;
V_692 |= ( 0x8 << V_709 ) ;
V_692 |= ( 0x1 << V_710 ) ;
V_693 = 0x9 ;
} else if ( V_26 <= 6200000 ) {
V_692 |= ( 0x5 << V_708 ) ;
V_692 |= ( 0xB << V_709 ) ;
V_692 |= ( 0x3 << V_710 ) ;
V_693 = 0x9 ;
} else if ( V_26 <= 6480000 ) {
V_692 |= ( 0x4 << V_708 ) ;
V_692 |= ( 0x9 << V_709 ) ;
V_692 |= ( 0x3 << V_710 ) ;
V_693 = 0x8 ;
} else {
V_692 |= ( 0x4 << V_708 ) ;
V_692 |= ( 0x9 << V_709 ) ;
V_692 |= ( 0x3 << V_710 ) ;
V_693 = 0 ;
}
F_129 ( V_12 , V_4 , F_511 ( V_108 ) , V_692 ) ;
V_695 = F_127 ( V_12 , V_4 , F_512 ( V_108 ) ) ;
V_695 &= ~ V_711 ;
V_695 |= ( V_693 << V_712 ) ;
F_129 ( V_12 , V_4 , F_512 ( V_108 ) , V_695 ) ;
F_129 ( V_12 , V_4 , F_128 ( V_108 ) ,
F_127 ( V_12 , V_4 , F_128 ( V_108 ) ) |
V_713 ) ;
F_58 ( & V_12 -> V_124 ) ;
}
void F_513 ( struct V_9 * V_10 , enum V_4 V_4 ,
const struct V_67 * V_67 )
{
struct V_28 * V_29 =
F_31 ( F_450 ( V_10 , V_4 ) ) ;
struct V_31 V_210 = {
. V_8 . V_29 = & V_29 -> V_8 ,
. V_522 = 1 ,
. V_67 = * V_67 ,
} ;
if ( F_20 ( V_10 ) ) {
F_504 ( V_29 , & V_210 ) ;
F_421 ( V_29 , & V_210 ) ;
F_125 ( V_29 , & V_210 ) ;
} else {
F_497 ( V_29 , & V_210 ) ;
F_422 ( V_29 , & V_210 ) ;
F_116 ( V_29 , & V_210 ) ;
}
}
void F_514 ( struct V_9 * V_10 , enum V_4 V_4 )
{
if ( F_20 ( V_10 ) )
F_136 ( F_245 ( V_10 ) , V_4 ) ;
else
F_135 ( F_245 ( V_10 ) , V_4 ) ;
}
static void F_515 ( struct V_28 * V_29 ,
struct V_31 * V_32 ,
T_2 * V_657 ,
int V_38 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_67 ;
bool V_714 ;
struct V_67 * clock = & V_32 -> V_67 ;
F_477 ( V_29 , V_32 , V_657 ) ;
V_714 = F_12 ( V_32 , V_55 ) ||
F_12 ( V_32 , V_52 ) ;
V_67 = V_670 ;
if ( F_12 ( V_32 , V_44 ) )
V_67 |= V_715 ;
else
V_67 |= V_716 ;
if ( F_516 ( V_10 ) || F_517 ( V_10 ) || F_518 ( V_10 ) ) {
V_67 |= ( V_32 -> V_522 - 1 )
<< V_717 ;
}
if ( V_714 )
V_67 |= V_718 ;
if ( V_32 -> V_471 )
V_67 |= V_718 ;
if ( F_19 ( V_10 ) )
V_67 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_719 ;
else {
V_67 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_720 ;
if ( F_18 ( V_10 ) && V_657 )
V_67 |= ( 1 << ( V_657 -> V_23 - 1 ) ) << V_721 ;
}
switch ( clock -> V_24 ) {
case 5 :
V_67 |= V_722 ;
break;
case 7 :
V_67 |= V_723 ;
break;
case 10 :
V_67 |= V_724 ;
break;
case 14 :
V_67 |= V_725 ;
break;
}
if ( F_45 ( V_10 ) -> V_105 >= 4 )
V_67 |= ( 6 << V_726 ) ;
if ( V_32 -> V_727 )
V_67 |= V_728 ;
else if ( F_12 ( V_32 , V_44 ) &&
F_473 ( V_12 ) && V_38 < 2 )
V_67 |= V_729 ;
else
V_67 |= V_730 ;
V_67 |= V_123 ;
V_32 -> V_211 . V_67 = V_67 ;
if ( F_45 ( V_10 ) -> V_105 >= 4 ) {
T_1 V_213 = ( V_32 -> V_522 - 1 )
<< V_672 ;
V_32 -> V_211 . V_213 = V_213 ;
}
}
static void F_519 ( struct V_28 * V_29 ,
struct V_31 * V_32 ,
T_2 * V_657 ,
int V_38 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_67 ;
struct V_67 * clock = & V_32 -> V_67 ;
F_477 ( V_29 , V_32 , V_657 ) ;
V_67 = V_670 ;
if ( F_12 ( V_32 , V_44 ) ) {
V_67 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_720 ;
} else {
if ( clock -> V_23 == 2 )
V_67 |= V_731 ;
else
V_67 |= ( clock -> V_23 - 2 ) << V_720 ;
if ( clock -> V_24 == 4 )
V_67 |= V_732 ;
}
if ( ! F_133 ( V_10 ) && F_12 ( V_32 , V_64 ) )
V_67 |= V_218 ;
if ( F_12 ( V_32 , V_44 ) &&
F_473 ( V_12 ) && V_38 < 2 )
V_67 |= V_729 ;
else
V_67 |= V_730 ;
V_67 |= V_123 ;
V_32 -> V_211 . V_67 = V_67 ;
}
static void F_363 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_28 -> V_4 ;
enum V_96 V_98 = V_28 -> V_93 -> V_98 ;
struct V_395 * V_94 =
& V_28 -> V_93 -> V_8 . V_94 ;
T_4 V_733 , V_734 ;
int V_735 = 0 ;
V_733 = V_94 -> V_733 ;
V_734 = V_94 -> V_734 ;
if ( V_94 -> V_344 & V_736 ) {
V_733 -= 1 ;
V_734 -= 1 ;
if ( F_10 ( V_28 , V_55 ) )
V_735 = ( V_94 -> V_737 - 1 ) / 2 ;
else
V_735 = V_94 -> V_738 -
V_94 -> V_737 / 2 ;
if ( V_735 < 0 )
V_735 += V_94 -> V_737 ;
}
if ( F_45 ( V_10 ) -> V_105 > 3 )
F_120 ( F_312 ( V_98 ) , V_735 ) ;
F_120 ( F_300 ( V_98 ) ,
( V_94 -> V_398 - 1 ) |
( ( V_94 -> V_737 - 1 ) << 16 ) ) ;
F_120 ( F_302 ( V_98 ) ,
( V_94 -> V_739 - 1 ) |
( ( V_94 -> V_740 - 1 ) << 16 ) ) ;
F_120 ( F_304 ( V_98 ) ,
( V_94 -> V_738 - 1 ) |
( ( V_94 -> V_741 - 1 ) << 16 ) ) ;
F_120 ( F_306 ( V_98 ) ,
( V_94 -> V_399 - 1 ) |
( ( V_733 - 1 ) << 16 ) ) ;
F_120 ( F_308 ( V_98 ) ,
( V_94 -> V_742 - 1 ) |
( ( V_734 - 1 ) << 16 ) ) ;
F_120 ( F_310 ( V_98 ) ,
( V_94 -> V_743 - 1 ) |
( ( V_94 -> V_744 - 1 ) << 16 ) ) ;
if ( F_225 ( V_10 ) && V_98 == V_521 &&
( V_4 == V_151 || V_4 == V_465 ) )
F_120 ( F_306 ( V_4 ) , F_5 ( F_306 ( V_98 ) ) ) ;
F_120 ( F_262 ( V_4 ) ,
( ( V_28 -> V_93 -> V_357 - 1 ) << 16 ) |
( V_28 -> V_93 -> V_356 - 1 ) ) ;
}
static void F_520 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_96 V_98 = V_210 -> V_98 ;
T_4 V_215 ;
V_215 = F_5 ( F_300 ( V_98 ) ) ;
V_210 -> V_8 . V_94 . V_398 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_8 . V_94 . V_737 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_215 = F_5 ( F_302 ( V_98 ) ) ;
V_210 -> V_8 . V_94 . V_739 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_8 . V_94 . V_740 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_215 = F_5 ( F_304 ( V_98 ) ) ;
V_210 -> V_8 . V_94 . V_738 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_8 . V_94 . V_741 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_215 = F_5 ( F_306 ( V_98 ) ) ;
V_210 -> V_8 . V_94 . V_399 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_8 . V_94 . V_733 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_215 = F_5 ( F_308 ( V_98 ) ) ;
V_210 -> V_8 . V_94 . V_742 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_8 . V_94 . V_734 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_215 = F_5 ( F_310 ( V_98 ) ) ;
V_210 -> V_8 . V_94 . V_743 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_8 . V_94 . V_744 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
if ( F_5 ( F_46 ( V_98 ) ) & V_246 ) {
V_210 -> V_8 . V_94 . V_344 |= V_736 ;
V_210 -> V_8 . V_94 . V_733 += 1 ;
V_210 -> V_8 . V_94 . V_734 += 1 ;
}
V_215 = F_5 ( F_262 ( V_29 -> V_4 ) ) ;
V_210 -> V_356 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_357 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_210 -> V_8 . V_477 . V_745 = V_210 -> V_356 ;
V_210 -> V_8 . V_477 . V_617 = V_210 -> V_357 ;
}
void F_521 ( struct V_395 * V_477 ,
struct V_31 * V_210 )
{
V_477 -> V_617 = V_210 -> V_8 . V_94 . V_398 ;
V_477 -> V_746 = V_210 -> V_8 . V_94 . V_737 ;
V_477 -> V_616 = V_210 -> V_8 . V_94 . V_738 ;
V_477 -> V_747 = V_210 -> V_8 . V_94 . V_741 ;
V_477 -> V_745 = V_210 -> V_8 . V_94 . V_399 ;
V_477 -> V_748 = V_210 -> V_8 . V_94 . V_733 ;
V_477 -> V_749 = V_210 -> V_8 . V_94 . V_743 ;
V_477 -> V_750 = V_210 -> V_8 . V_94 . V_744 ;
V_477 -> V_344 = V_210 -> V_8 . V_94 . V_344 ;
V_477 -> clock = V_210 -> V_8 . V_94 . V_95 ;
V_477 -> V_344 |= V_210 -> V_8 . V_94 . V_344 ;
}
static void F_425 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_751 ;
V_751 = 0 ;
if ( ( V_28 -> V_4 == V_142 && V_12 -> V_160 & V_161 ) ||
( V_28 -> V_4 == V_151 && V_12 -> V_160 & V_162 ) )
V_751 |= F_5 ( F_46 ( V_28 -> V_4 ) ) & V_163 ;
if ( V_28 -> V_93 -> V_259 )
V_751 |= V_260 ;
if ( F_18 ( V_10 ) || F_21 ( V_10 ) ) {
if ( V_28 -> V_93 -> V_752 && V_28 -> V_93 -> V_611 != 30 )
V_751 |= V_753 |
V_754 ;
switch ( V_28 -> V_93 -> V_611 ) {
case 18 :
V_751 |= V_755 ;
break;
case 24 :
V_751 |= V_756 ;
break;
case 30 :
V_751 |= V_757 ;
break;
default:
F_138 () ;
}
}
if ( F_522 ( V_10 ) ) {
if ( V_28 -> V_660 ) {
F_144 ( L_102 ) ;
V_751 |= V_758 ;
} else {
F_144 ( L_103 ) ;
}
}
if ( V_28 -> V_93 -> V_8 . V_94 . V_344 & V_736 ) {
if ( F_45 ( V_10 ) -> V_105 < 4 ||
F_10 ( V_28 , V_55 ) )
V_751 |= V_759 ;
else
V_751 |= V_760 ;
} else
V_751 |= V_761 ;
if ( F_21 ( V_10 ) && V_28 -> V_93 -> V_762 )
V_751 |= V_763 ;
F_120 ( F_46 ( V_28 -> V_4 ) , V_751 ) ;
F_121 ( F_46 ( V_28 -> V_4 ) ) ;
}
static int F_523 ( struct V_28 * V_29 ,
struct V_31 * V_32 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_18 , V_38 = 0 ;
T_2 clock , V_657 ;
bool V_764 , V_765 = false ;
bool V_766 = false , V_589 = false ;
struct V_1 * V_6 ;
const T_3 * V_43 ;
struct V_33 * V_34 = V_32 -> V_8 . V_34 ;
struct V_35 * V_36 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_34 -> V_39 ; V_37 ++ ) {
if ( ! V_34 -> V_40 [ V_37 ] )
continue;
V_36 = V_34 -> V_41 [ V_37 ] ;
if ( V_36 -> V_29 != & V_29 -> V_8 )
continue;
V_6 = F_13 ( V_36 -> V_42 ) ;
switch ( V_6 -> type ) {
case V_44 :
V_766 = true ;
break;
case V_257 :
V_589 = true ;
break;
default:
break;
}
V_38 ++ ;
}
if ( V_589 )
return 0 ;
if ( ! V_32 -> V_767 ) {
V_18 = F_474 ( V_32 , V_38 ) ;
V_43 = F_17 ( V_32 , V_18 ) ;
V_764 = V_12 -> V_263 . V_768 ( V_43 , V_32 ,
V_32 -> V_691 ,
V_18 , NULL , & clock ) ;
if ( ! V_764 ) {
F_123 ( L_104 ) ;
return - V_292 ;
}
if ( V_766 && V_12 -> V_769 ) {
V_765 =
V_12 -> V_263 . V_768 ( V_43 , V_32 ,
V_12 -> V_770 ,
V_18 , & clock ,
& V_657 ) ;
}
V_32 -> V_67 . V_25 = clock . V_25 ;
V_32 -> V_67 . V_20 = clock . V_20 ;
V_32 -> V_67 . V_21 = clock . V_21 ;
V_32 -> V_67 . V_23 = clock . V_23 ;
V_32 -> V_67 . V_24 = clock . V_24 ;
}
if ( F_22 ( V_10 ) ) {
F_519 ( V_29 , V_32 ,
V_765 ? & V_657 : NULL ,
V_38 ) ;
} else if ( F_20 ( V_10 ) ) {
F_504 ( V_29 , V_32 ) ;
} else if ( F_21 ( V_10 ) ) {
F_497 ( V_29 , V_32 ) ;
} else {
F_515 ( V_29 , V_32 ,
V_765 ? & V_657 : NULL ,
V_38 ) ;
}
return 0 ;
}
static void F_524 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_215 ;
if ( F_45 ( V_10 ) -> V_105 <= 3 && ( F_133 ( V_10 ) || ! F_119 ( V_10 ) ) )
return;
V_215 = F_5 ( V_528 ) ;
if ( ! ( V_215 & V_529 ) )
return;
if ( F_45 ( V_10 ) -> V_105 < 4 ) {
if ( V_29 -> V_4 != V_151 )
return;
} else {
if ( ( V_215 & V_771 ) != ( V_29 -> V_4 << V_772 ) )
return;
}
V_210 -> V_526 . V_527 = V_215 ;
V_210 -> V_526 . V_531 = F_5 ( V_530 ) ;
if ( F_45 ( V_10 ) -> V_105 < 5 )
V_210 -> V_526 . V_773 =
F_5 ( V_153 ) & V_774 ;
}
static void F_525 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_210 -> V_98 ;
T_2 clock ;
T_1 V_673 ;
int V_18 = 100000 ;
if ( ! ( V_210 -> V_211 . V_67 & V_123 ) )
return;
F_56 ( & V_12 -> V_124 ) ;
V_673 = F_127 ( V_12 , V_4 , F_499 ( V_4 ) ) ;
F_58 ( & V_12 -> V_124 ) ;
clock . V_20 = ( V_673 >> V_682 ) & 7 ;
clock . V_21 = V_673 & V_683 ;
clock . V_25 = ( V_673 >> V_686 ) & 0xf ;
clock . V_23 = ( V_673 >> V_684 ) & 7 ;
clock . V_24 = ( V_673 >> V_685 ) & 0x1f ;
F_8 ( V_18 , & clock ) ;
V_210 -> V_691 = clock . V_27 / 5 ;
}
static void
F_526 ( struct V_28 * V_29 ,
struct V_332 * V_333 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_121 , V_8 , V_309 ;
int V_4 = V_29 -> V_4 , V_164 = V_29 -> V_164 ;
int V_775 , V_268 ;
unsigned int V_776 ;
struct V_279 * V_92 ;
struct V_777 * V_778 ;
V_121 = F_5 ( F_80 ( V_164 ) ) ;
if ( ! ( V_121 & V_165 ) )
return;
V_778 = F_444 ( sizeof( * V_778 ) , V_487 ) ;
if ( ! V_778 ) {
F_144 ( L_105 ) ;
return;
}
V_92 = & V_778 -> V_8 ;
if ( F_45 ( V_10 ) -> V_105 >= 4 ) {
if ( V_121 & V_362 ) {
V_333 -> V_340 = V_341 ;
V_92 -> V_291 [ 0 ] = V_273 ;
}
}
V_268 = V_121 & V_779 ;
V_775 = F_197 ( V_268 ) ;
V_92 -> V_268 = V_775 ;
V_92 -> V_368 = F_176 ( V_775 , 0 ) * 8 ;
if ( F_45 ( V_10 ) -> V_105 >= 4 ) {
if ( V_333 -> V_340 )
V_309 = F_5 ( F_222 ( V_164 ) ) ;
else
V_309 = F_5 ( F_223 ( V_164 ) ) ;
V_8 = F_5 ( F_166 ( V_164 ) ) & 0xfffff000 ;
} else {
V_8 = F_5 ( F_167 ( V_164 ) ) ;
}
V_333 -> V_8 = V_8 ;
V_121 = F_5 ( F_262 ( V_4 ) ) ;
V_92 -> V_343 = ( ( V_121 >> 16 ) & 0xfff ) + 1 ;
V_92 -> V_276 = ( ( V_121 >> 0 ) & 0xfff ) + 1 ;
V_121 = F_5 ( F_221 ( V_4 ) ) ;
V_92 -> V_289 [ 0 ] = V_121 & 0xffffffc0 ;
V_776 = F_179 ( V_10 , V_92 -> V_276 ,
V_92 -> V_268 ,
V_92 -> V_291 [ 0 ] ) ;
V_333 -> V_339 = V_92 -> V_289 [ 0 ] * V_776 ;
F_144 ( L_106 ,
F_71 ( V_4 ) , V_164 , V_92 -> V_343 , V_92 -> V_276 ,
V_92 -> V_368 , V_8 , V_92 -> V_289 [ 0 ] ,
V_333 -> V_339 ) ;
V_333 -> V_92 = V_778 ;
}
static void F_527 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_210 -> V_98 ;
enum V_214 V_108 = F_126 ( V_4 ) ;
T_2 clock ;
T_1 V_780 , V_781 , V_782 , V_783 ;
int V_18 = 100000 ;
F_56 ( & V_12 -> V_124 ) ;
V_780 = F_127 ( V_12 , V_4 , F_505 ( V_108 ) ) ;
V_781 = F_127 ( V_12 , V_4 , F_506 ( V_108 ) ) ;
V_782 = F_127 ( V_12 , V_4 , F_507 ( V_108 ) ) ;
V_783 = F_127 ( V_12 , V_4 , F_508 ( V_108 ) ) ;
F_58 ( & V_12 -> V_124 ) ;
clock . V_20 = ( V_782 & 0x7 ) == V_700 ? 2 : 0 ;
clock . V_21 = ( ( V_781 & 0xff ) << 22 ) | ( V_783 & 0x3fffff ) ;
clock . V_25 = ( V_782 >> V_701 ) & 0xf ;
clock . V_23 = ( V_780 >> V_697 ) & 0x7 ;
clock . V_24 = ( V_780 >> V_698 ) & 0x1f ;
F_26 ( V_18 , & clock ) ;
V_210 -> V_691 = clock . V_27 / 5 ;
}
static bool F_528 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_215 ;
if ( ! F_77 ( V_12 ,
F_399 ( V_29 -> V_4 ) ) )
return false ;
V_210 -> V_98 = (enum V_96 ) V_29 -> V_4 ;
V_210 -> V_128 = V_482 ;
V_215 = F_5 ( F_46 ( V_29 -> V_4 ) ) ;
if ( ! ( V_215 & V_163 ) )
return false ;
if ( F_18 ( V_10 ) || F_21 ( V_10 ) ) {
switch ( V_215 & V_244 ) {
case V_755 :
V_210 -> V_611 = 18 ;
break;
case V_756 :
V_210 -> V_611 = 24 ;
break;
case V_757 :
V_210 -> V_611 = 30 ;
break;
default:
break;
}
}
if ( F_21 ( V_10 ) && ( V_215 & V_763 ) )
V_210 -> V_762 = true ;
if ( F_45 ( V_10 ) -> V_105 < 4 )
V_210 -> V_259 = V_215 & V_260 ;
F_520 ( V_29 , V_210 ) ;
F_524 ( V_29 , V_210 ) ;
if ( F_45 ( V_10 ) -> V_105 >= 4 ) {
V_215 = F_5 ( F_124 ( V_29 -> V_4 ) ) ;
V_210 -> V_522 =
( ( V_215 & V_784 )
>> V_672 ) + 1 ;
V_210 -> V_211 . V_213 = V_215 ;
} else if ( F_516 ( V_10 ) || F_517 ( V_10 ) || F_518 ( V_10 ) ) {
V_215 = F_5 ( F_53 ( V_29 -> V_4 ) ) ;
V_210 -> V_522 =
( ( V_215 & V_785 )
>> V_717 ) + 1 ;
} else {
V_210 -> V_522 = 1 ;
}
V_210 -> V_211 . V_67 = F_5 ( F_53 ( V_29 -> V_4 ) ) ;
if ( ! F_21 ( V_10 ) ) {
if ( F_133 ( V_10 ) )
V_210 -> V_211 . V_67 &= ~ V_218 ;
V_210 -> V_211 . V_592 = F_5 ( F_428 ( V_29 -> V_4 ) ) ;
V_210 -> V_211 . V_593 = F_5 ( F_429 ( V_29 -> V_4 ) ) ;
} else {
V_210 -> V_211 . V_67 &= ~ ( V_212 |
V_232 |
V_231 ) ;
}
if ( F_20 ( V_10 ) )
F_527 ( V_29 , V_210 ) ;
else if ( F_21 ( V_10 ) )
F_525 ( V_29 , V_210 ) ;
else
F_529 ( V_29 , V_210 ) ;
return true ;
}
static void F_530 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
T_1 V_121 , V_786 ;
bool V_787 = false ;
bool V_788 = false ;
bool V_789 = false ;
bool V_790 = false ;
bool V_791 = false ;
F_531 (dev, encoder) {
switch ( V_6 -> type ) {
case V_44 :
V_789 = true ;
V_787 = true ;
break;
case V_401 :
V_789 = true ;
if ( F_396 ( & V_6 -> V_8 ) -> V_108 == V_533 )
V_788 = true ;
break;
default:
break;
}
}
if ( F_50 ( V_10 ) ) {
V_790 = V_12 -> V_653 . V_792 ;
V_791 = V_790 ;
} else {
V_790 = false ;
V_791 = true ;
}
F_144 ( L_107 ,
V_789 , V_787 , V_790 ) ;
V_121 = F_5 ( V_174 ) ;
V_786 = V_121 ;
V_786 &= ~ V_176 ;
if ( V_790 )
V_786 |= V_793 ;
else
V_786 |= V_794 ;
V_786 &= ~ V_175 ;
V_786 &= ~ V_795 ;
V_786 &= ~ V_796 ;
if ( V_789 ) {
V_786 |= V_797 ;
if ( F_473 ( V_12 ) && V_791 )
V_786 |= V_796 ;
if ( V_788 ) {
if ( F_473 ( V_12 ) && V_791 )
V_786 |= V_798 ;
else
V_786 |= V_799 ;
} else
V_786 |= V_800 ;
} else {
V_786 |= V_801 ;
V_786 |= V_800 ;
}
if ( V_786 == V_121 )
return;
V_121 &= ~ V_176 ;
if ( V_790 )
V_121 |= V_793 ;
else
V_121 |= V_794 ;
if ( V_789 ) {
V_121 &= ~ V_175 ;
V_121 |= V_797 ;
if ( F_473 ( V_12 ) && V_791 ) {
F_144 ( L_108 ) ;
V_121 |= V_796 ;
} else
V_121 &= ~ V_796 ;
F_120 ( V_174 , V_121 ) ;
F_121 ( V_174 ) ;
F_122 ( 200 ) ;
V_121 &= ~ V_795 ;
if ( V_788 ) {
if ( F_473 ( V_12 ) && V_791 ) {
F_144 ( L_109 ) ;
V_121 |= V_798 ;
} else
V_121 |= V_799 ;
} else
V_121 |= V_800 ;
F_120 ( V_174 , V_121 ) ;
F_121 ( V_174 ) ;
F_122 ( 200 ) ;
} else {
F_144 ( L_110 ) ;
V_121 &= ~ V_795 ;
V_121 |= V_800 ;
F_120 ( V_174 , V_121 ) ;
F_121 ( V_174 ) ;
F_122 ( 200 ) ;
V_121 &= ~ V_175 ;
V_121 |= V_801 ;
V_121 &= ~ V_796 ;
F_120 ( V_174 , V_121 ) ;
F_121 ( V_174 ) ;
F_122 ( 200 ) ;
}
F_118 ( V_121 != V_786 ) ;
}
static void F_532 ( struct V_11 * V_12 )
{
T_4 V_215 ;
V_215 = F_5 ( V_802 ) ;
V_215 |= V_803 ;
F_120 ( V_802 , V_215 ) ;
if ( F_533 ( F_5 ( V_802 ) &
V_804 , 100 ) )
F_123 ( L_111 ) ;
V_215 = F_5 ( V_802 ) ;
V_215 &= ~ V_803 ;
F_120 ( V_802 , V_215 ) ;
if ( F_533 ( ( F_5 ( V_802 ) &
V_804 ) == 0 , 100 ) )
F_123 ( L_112 ) ;
}
static void F_534 ( struct V_11 * V_12 )
{
T_4 V_215 ;
V_215 = F_293 ( V_12 , 0x8008 , V_805 ) ;
V_215 &= ~ ( 0xFF << 24 ) ;
V_215 |= ( 0x12 << 24 ) ;
F_292 ( V_12 , 0x8008 , V_215 , V_805 ) ;
V_215 = F_293 ( V_12 , 0x2008 , V_805 ) ;
V_215 |= ( 1 << 11 ) ;
F_292 ( V_12 , 0x2008 , V_215 , V_805 ) ;
V_215 = F_293 ( V_12 , 0x2108 , V_805 ) ;
V_215 |= ( 1 << 11 ) ;
F_292 ( V_12 , 0x2108 , V_215 , V_805 ) ;
V_215 = F_293 ( V_12 , 0x206C , V_805 ) ;
V_215 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_292 ( V_12 , 0x206C , V_215 , V_805 ) ;
V_215 = F_293 ( V_12 , 0x216C , V_805 ) ;
V_215 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_292 ( V_12 , 0x216C , V_215 , V_805 ) ;
V_215 = F_293 ( V_12 , 0x2080 , V_805 ) ;
V_215 &= ~ ( 7 << 13 ) ;
V_215 |= ( 5 << 13 ) ;
F_292 ( V_12 , 0x2080 , V_215 , V_805 ) ;
V_215 = F_293 ( V_12 , 0x2180 , V_805 ) ;
V_215 &= ~ ( 7 << 13 ) ;
V_215 |= ( 5 << 13 ) ;
F_292 ( V_12 , 0x2180 , V_215 , V_805 ) ;
V_215 = F_293 ( V_12 , 0x208C , V_805 ) ;
V_215 &= ~ 0xFF ;
V_215 |= 0x1C ;
F_292 ( V_12 , 0x208C , V_215 , V_805 ) ;
V_215 = F_293 ( V_12 , 0x218C , V_805 ) ;
V_215 &= ~ 0xFF ;
V_215 |= 0x1C ;
F_292 ( V_12 , 0x218C , V_215 , V_805 ) ;
V_215 = F_293 ( V_12 , 0x2098 , V_805 ) ;
V_215 &= ~ ( 0xFF << 16 ) ;
V_215 |= ( 0x1C << 16 ) ;
F_292 ( V_12 , 0x2098 , V_215 , V_805 ) ;
V_215 = F_293 ( V_12 , 0x2198 , V_805 ) ;
V_215 &= ~ ( 0xFF << 16 ) ;
V_215 |= ( 0x1C << 16 ) ;
F_292 ( V_12 , 0x2198 , V_215 , V_805 ) ;
V_215 = F_293 ( V_12 , 0x20C4 , V_805 ) ;
V_215 |= ( 1 << 27 ) ;
F_292 ( V_12 , 0x20C4 , V_215 , V_805 ) ;
V_215 = F_293 ( V_12 , 0x21C4 , V_805 ) ;
V_215 |= ( 1 << 27 ) ;
F_292 ( V_12 , 0x21C4 , V_215 , V_805 ) ;
V_215 = F_293 ( V_12 , 0x20EC , V_805 ) ;
V_215 &= ~ ( 0xF << 28 ) ;
V_215 |= ( 4 << 28 ) ;
F_292 ( V_12 , 0x20EC , V_215 , V_805 ) ;
V_215 = F_293 ( V_12 , 0x21EC , V_805 ) ;
V_215 &= ~ ( 0xF << 28 ) ;
V_215 |= ( 4 << 28 ) ;
F_292 ( V_12 , 0x21EC , V_215 , V_805 ) ;
}
static void F_535 ( struct V_9 * V_10 , bool V_806 ,
bool V_807 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_99 , V_215 ;
if ( F_48 ( V_807 && ! V_806 , L_113 ) )
V_806 = true ;
if ( F_48 ( V_12 -> V_808 == V_809 &&
V_807 , L_114 ) )
V_807 = false ;
F_56 ( & V_12 -> V_124 ) ;
V_215 = F_293 ( V_12 , V_810 , V_450 ) ;
V_215 &= ~ V_451 ;
V_215 |= V_811 ;
F_292 ( V_12 , V_810 , V_215 , V_450 ) ;
F_122 ( 24 ) ;
if ( V_806 ) {
V_215 = F_293 ( V_12 , V_810 , V_450 ) ;
V_215 &= ~ V_811 ;
F_292 ( V_12 , V_810 , V_215 , V_450 ) ;
if ( V_807 ) {
F_532 ( V_12 ) ;
F_534 ( V_12 ) ;
}
}
V_99 = ( V_12 -> V_808 == V_809 ) ?
V_812 : V_813 ;
V_215 = F_293 ( V_12 , V_99 , V_450 ) ;
V_215 |= V_814 ;
F_292 ( V_12 , V_99 , V_215 , V_450 ) ;
F_58 ( & V_12 -> V_124 ) ;
}
static void F_536 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_99 , V_215 ;
F_56 ( & V_12 -> V_124 ) ;
V_99 = ( V_12 -> V_808 == V_809 ) ?
V_812 : V_813 ;
V_215 = F_293 ( V_12 , V_99 , V_450 ) ;
V_215 &= ~ V_814 ;
F_292 ( V_12 , V_99 , V_215 , V_450 ) ;
V_215 = F_293 ( V_12 , V_810 , V_450 ) ;
if ( ! ( V_215 & V_451 ) ) {
if ( ! ( V_215 & V_811 ) ) {
V_215 |= V_811 ;
F_292 ( V_12 , V_810 , V_215 , V_450 ) ;
F_122 ( 32 ) ;
}
V_215 |= V_451 ;
F_292 ( V_12 , V_810 , V_215 , V_450 ) ;
}
F_58 ( & V_12 -> V_124 ) ;
}
static void F_537 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
bool V_815 = false ;
F_531 (dev, encoder) {
switch ( V_6 -> type ) {
case V_53 :
V_815 = true ;
break;
default:
break;
}
}
if ( V_815 )
F_535 ( V_10 , true , true ) ;
else
F_536 ( V_10 ) ;
}
void F_538 ( struct V_9 * V_10 )
{
if ( F_50 ( V_10 ) || F_96 ( V_10 ) )
F_530 ( V_10 ) ;
else if ( F_160 ( V_10 ) )
F_537 ( V_10 ) ;
}
static int F_539 ( struct V_31 * V_32 )
{
struct V_9 * V_10 = V_32 -> V_8 . V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_33 * V_34 = V_32 -> V_8 . V_34 ;
struct V_35 * V_36 ;
struct V_1 * V_6 ;
int V_38 = 0 , V_37 ;
bool V_766 = false ;
for ( V_37 = 0 ; V_37 < V_34 -> V_39 ; V_37 ++ ) {
if ( ! V_34 -> V_40 [ V_37 ] )
continue;
V_36 = V_34 -> V_41 [ V_37 ] ;
if ( V_36 -> V_29 != V_32 -> V_8 . V_29 )
continue;
V_6 = F_13 ( V_36 -> V_42 ) ;
switch ( V_6 -> type ) {
case V_44 :
V_766 = true ;
break;
default:
break;
}
V_38 ++ ;
}
if ( V_766 && F_473 ( V_12 ) && V_38 < 2 ) {
F_144 ( L_100 ,
V_12 -> V_653 . V_656 ) ;
return V_12 -> V_653 . V_656 ;
}
return 120000 ;
}
static void F_365 ( struct V_89 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_4 V_121 ;
V_121 = 0 ;
switch ( V_28 -> V_93 -> V_611 ) {
case 18 :
V_121 |= V_755 ;
break;
case 24 :
V_121 |= V_756 ;
break;
case 30 :
V_121 |= V_757 ;
break;
case 36 :
V_121 |= V_816 ;
break;
default:
F_138 () ;
}
if ( V_28 -> V_93 -> V_752 )
V_121 |= ( V_753 | V_754 ) ;
if ( V_28 -> V_93 -> V_8 . V_94 . V_344 & V_736 )
V_121 |= V_247 ;
else
V_121 |= V_761 ;
if ( V_28 -> V_93 -> V_762 )
V_121 |= V_763 ;
F_120 ( F_46 ( V_4 ) , V_121 ) ;
F_121 ( F_46 ( V_4 ) ) ;
}
static void F_376 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_6 V_817 = 0x7800 ;
if ( V_28 -> V_93 -> V_762 )
V_817 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_120 ( F_540 ( V_4 ) , V_817 << 16 ) ;
F_120 ( F_541 ( V_4 ) , 0 ) ;
F_120 ( F_542 ( V_4 ) , V_817 ) ;
F_120 ( F_543 ( V_4 ) , 0 ) ;
F_120 ( F_544 ( V_4 ) , 0 ) ;
F_120 ( F_545 ( V_4 ) , V_817 << 16 ) ;
F_120 ( F_546 ( V_4 ) , 0 ) ;
F_120 ( F_547 ( V_4 ) , 0 ) ;
F_120 ( F_548 ( V_4 ) , 0 ) ;
if ( F_45 ( V_10 ) -> V_105 > 6 ) {
T_6 V_818 = 0 ;
if ( V_28 -> V_93 -> V_762 )
V_818 = ( 16 * ( 1 << 12 ) / 255 ) & 0x1fff ;
F_120 ( F_549 ( V_4 ) , V_818 ) ;
F_120 ( F_550 ( V_4 ) , V_818 ) ;
F_120 ( F_551 ( V_4 ) , V_818 ) ;
F_120 ( F_552 ( V_4 ) , 0 ) ;
} else {
T_4 V_477 = V_819 ;
if ( V_28 -> V_93 -> V_762 )
V_477 |= V_820 ;
F_120 ( F_552 ( V_4 ) , V_477 ) ;
}
}
static void F_375 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
enum V_96 V_98 = V_28 -> V_93 -> V_98 ;
T_4 V_121 ;
V_121 = 0 ;
if ( F_225 ( V_10 ) && V_28 -> V_93 -> V_752 )
V_121 |= ( V_753 | V_754 ) ;
if ( V_28 -> V_93 -> V_8 . V_94 . V_344 & V_736 )
V_121 |= V_247 ;
else
V_121 |= V_761 ;
F_120 ( F_46 ( V_98 ) , V_121 ) ;
F_121 ( F_46 ( V_98 ) ) ;
F_120 ( F_351 ( V_28 -> V_4 ) , V_821 ) ;
F_121 ( F_351 ( V_28 -> V_4 ) ) ;
if ( F_170 ( V_10 ) || F_45 ( V_10 ) -> V_105 >= 9 ) {
V_121 = 0 ;
switch ( V_28 -> V_93 -> V_611 ) {
case 18 :
V_121 |= V_822 ;
break;
case 24 :
V_121 |= V_823 ;
break;
case 30 :
V_121 |= V_824 ;
break;
case 36 :
V_121 |= V_825 ;
break;
default:
F_138 () ;
}
if ( V_28 -> V_93 -> V_752 )
V_121 |= V_826 | V_827 ;
F_120 ( F_553 ( V_4 ) , V_121 ) ;
}
}
static bool F_554 ( struct V_89 * V_29 ,
struct V_31 * V_32 ,
T_2 * clock ,
bool * V_765 ,
T_2 * V_657 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_18 ;
const T_3 * V_43 ;
bool V_298 , V_766 = false ;
V_766 = F_12 ( V_32 , V_44 ) ;
V_18 = F_539 ( V_32 ) ;
V_43 = F_17 ( V_32 , V_18 ) ;
V_298 = V_12 -> V_263 . V_768 ( V_43 , V_32 ,
V_32 -> V_691 ,
V_18 , NULL , clock ) ;
if ( ! V_298 )
return false ;
if ( V_766 && V_12 -> V_769 ) {
* V_765 =
V_12 -> V_263 . V_768 ( V_43 , V_32 ,
V_12 -> V_770 ,
V_18 , clock ,
V_657 ) ;
}
return true ;
}
int F_455 ( int V_828 , int V_607 , int V_829 )
{
T_1 V_830 = V_828 * V_829 * 21 / 20 ;
return F_406 ( V_830 , V_607 * 8 ) ;
}
static bool F_555 ( struct V_67 * V_67 , int V_831 )
{
return F_24 ( V_67 ) < V_831 * V_67 -> V_25 ;
}
static T_4 F_556 ( struct V_28 * V_28 ,
struct V_31 * V_32 ,
T_1 * V_658 ,
T_2 * V_657 , T_1 * V_659 )
{
struct V_89 * V_29 = & V_28 -> V_8 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_33 * V_34 = V_32 -> V_8 . V_34 ;
struct V_35 * V_36 ;
struct V_1 * V_6 ;
T_4 V_67 ;
int V_831 , V_38 = 0 , V_37 ;
bool V_766 = false , V_714 = false ;
for ( V_37 = 0 ; V_37 < V_34 -> V_39 ; V_37 ++ ) {
if ( ! V_34 -> V_40 [ V_37 ] )
continue;
V_36 = V_34 -> V_41 [ V_37 ] ;
if ( V_36 -> V_29 != V_32 -> V_8 . V_29 )
continue;
V_6 = F_13 ( V_36 -> V_42 ) ;
switch ( V_6 -> type ) {
case V_44 :
V_766 = true ;
break;
case V_55 :
case V_52 :
V_714 = true ;
break;
default:
break;
}
V_38 ++ ;
}
V_831 = 21 ;
if ( V_766 ) {
if ( ( F_473 ( V_12 ) &&
V_12 -> V_653 . V_656 == 100000 ) ||
( F_50 ( V_10 ) && F_15 ( V_10 ) ) )
V_831 = 25 ;
} else if ( V_32 -> V_727 )
V_831 = 20 ;
if ( F_555 ( & V_32 -> V_67 , V_831 ) )
* V_658 |= V_832 ;
if ( V_659 && ( V_657 -> V_19 < V_831 * V_657 -> V_25 ) )
* V_659 |= V_832 ;
V_67 = 0 ;
if ( V_766 )
V_67 |= V_715 ;
else
V_67 |= V_716 ;
V_67 |= ( V_32 -> V_522 - 1 )
<< V_833 ;
if ( V_714 )
V_67 |= V_718 ;
if ( V_32 -> V_471 )
V_67 |= V_718 ;
V_67 |= ( 1 << ( V_32 -> V_67 . V_23 - 1 ) ) << V_720 ;
V_67 |= ( 1 << ( V_32 -> V_67 . V_23 - 1 ) ) << V_721 ;
switch ( V_32 -> V_67 . V_24 ) {
case 5 :
V_67 |= V_722 ;
break;
case 7 :
V_67 |= V_723 ;
break;
case 10 :
V_67 |= V_724 ;
break;
case 14 :
V_67 |= V_725 ;
break;
}
if ( V_766 && F_473 ( V_12 ) && V_38 < 2 )
V_67 |= V_729 ;
else
V_67 |= V_730 ;
return V_67 | V_123 ;
}
static int F_557 ( struct V_28 * V_29 ,
struct V_31 * V_32 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock , V_657 ;
T_1 V_67 = 0 , V_658 = 0 , V_659 = 0 ;
bool V_764 , V_765 = false ;
bool V_766 = false ;
struct V_127 * V_130 ;
V_766 = F_10 ( V_29 , V_44 ) ;
F_48 ( ! ( F_50 ( V_10 ) || F_96 ( V_10 ) ) ,
L_115 , F_558 ( V_10 ) ) ;
V_764 = F_554 ( & V_29 -> V_8 , V_32 , & clock ,
& V_765 , & V_657 ) ;
if ( ! V_764 && ! V_32 -> V_767 ) {
F_123 ( L_104 ) ;
return - V_292 ;
}
if ( ! V_32 -> V_767 ) {
V_32 -> V_67 . V_25 = clock . V_25 ;
V_32 -> V_67 . V_20 = clock . V_20 ;
V_32 -> V_67 . V_21 = clock . V_21 ;
V_32 -> V_67 . V_23 = clock . V_23 ;
V_32 -> V_67 . V_24 = clock . V_24 ;
}
if ( V_32 -> V_258 ) {
V_658 = F_476 ( & V_32 -> V_67 ) ;
if ( V_765 )
V_659 = F_476 ( & V_657 ) ;
V_67 = F_556 ( V_29 , V_32 ,
& V_658 , & V_657 ,
V_765 ? & V_659 : NULL ) ;
V_32 -> V_211 . V_67 = V_67 ;
V_32 -> V_211 . V_592 = V_658 ;
if ( V_765 )
V_32 -> V_211 . V_593 = V_659 ;
else
V_32 -> V_211 . V_593 = V_658 ;
V_130 = F_323 ( V_29 , V_32 ) ;
if ( V_130 == NULL ) {
F_141 ( L_116 ,
F_71 ( V_29 -> V_4 ) ) ;
return - V_292 ;
}
}
if ( V_766 && V_765 )
V_29 -> V_660 = true ;
else
V_29 -> V_660 = false ;
return 0 ;
}
static void F_559 ( struct V_28 * V_29 ,
struct V_645 * V_646 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
V_646 -> V_650 = F_5 ( F_484 ( V_4 ) ) ;
V_646 -> V_651 = F_5 ( F_485 ( V_4 ) ) ;
V_646 -> V_648 = F_5 ( F_481 ( V_4 ) )
& ~ V_466 ;
V_646 -> V_649 = F_5 ( F_483 ( V_4 ) ) ;
V_646 -> V_647 = ( ( F_5 ( F_481 ( V_4 ) )
& V_466 ) >> V_834 ) + 1 ;
}
static void F_560 ( struct V_28 * V_29 ,
enum V_96 V_96 ,
struct V_645 * V_646 ,
struct V_645 * V_663 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
if ( F_45 ( V_10 ) -> V_105 >= 5 ) {
V_646 -> V_650 = F_5 ( F_487 ( V_96 ) ) ;
V_646 -> V_651 = F_5 ( F_488 ( V_96 ) ) ;
V_646 -> V_648 = F_5 ( F_317 ( V_96 ) )
& ~ V_466 ;
V_646 -> V_649 = F_5 ( F_486 ( V_96 ) ) ;
V_646 -> V_647 = ( ( F_5 ( F_317 ( V_96 ) )
& V_466 ) >> V_834 ) + 1 ;
if ( V_663 && F_45 ( V_10 ) -> V_105 < 8 &&
V_29 -> V_93 -> V_664 ) {
V_663 -> V_650 = F_5 ( F_491 ( V_96 ) ) ;
V_663 -> V_651 = F_5 ( F_492 ( V_96 ) ) ;
V_663 -> V_648 = F_5 ( F_489 ( V_96 ) )
& ~ V_466 ;
V_663 -> V_649 = F_5 ( F_490 ( V_96 ) ) ;
V_663 -> V_647 = ( ( F_5 ( F_489 ( V_96 ) )
& V_466 ) >> V_834 ) + 1 ;
}
} else {
V_646 -> V_650 = F_5 ( F_495 ( V_4 ) ) ;
V_646 -> V_651 = F_5 ( F_496 ( V_4 ) ) ;
V_646 -> V_648 = F_5 ( F_493 ( V_4 ) )
& ~ V_466 ;
V_646 -> V_649 = F_5 ( F_494 ( V_4 ) ) ;
V_646 -> V_647 = ( ( F_5 ( F_493 ( V_4 ) )
& V_466 ) >> V_834 ) + 1 ;
}
}
void F_561 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
if ( V_210 -> V_258 )
F_559 ( V_29 , & V_210 -> V_666 ) ;
else
F_560 ( V_29 , V_210 -> V_98 ,
& V_210 -> V_666 ,
& V_210 -> V_667 ) ;
}
static void F_562 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
F_560 ( V_29 , V_210 -> V_98 ,
& V_210 -> V_517 , NULL ) ;
}
static void F_563 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_215 ;
V_215 = F_5 ( F_330 ( V_29 -> V_4 ) ) ;
if ( V_215 & V_491 ) {
V_210 -> V_400 . V_120 = true ;
V_210 -> V_400 . V_492 = F_5 ( F_331 ( V_29 -> V_4 ) ) ;
V_210 -> V_400 . V_339 = F_5 ( F_332 ( V_29 -> V_4 ) ) ;
}
}
static void
F_564 ( struct V_28 * V_29 ,
struct V_332 * V_333 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_121 , V_8 , V_309 , V_835 , V_340 ;
int V_4 = V_29 -> V_4 ;
int V_775 , V_268 ;
unsigned int V_776 ;
struct V_279 * V_92 ;
struct V_777 * V_778 ;
V_778 = F_444 ( sizeof( * V_778 ) , V_487 ) ;
if ( ! V_778 ) {
F_144 ( L_105 ) ;
return;
}
V_92 = & V_778 -> V_8 ;
V_121 = F_5 ( F_86 ( V_4 , 0 ) ) ;
if ( ! ( V_121 & V_170 ) )
goto error;
V_268 = V_121 & V_836 ;
V_775 = F_198 ( V_268 ,
V_121 & V_376 ,
V_121 & V_837 ) ;
V_92 -> V_268 = V_775 ;
V_92 -> V_368 = F_176 ( V_775 , 0 ) * 8 ;
V_340 = V_121 & V_838 ;
switch ( V_340 ) {
case V_839 :
V_92 -> V_291 [ 0 ] = V_272 ;
break;
case V_377 :
V_333 -> V_340 = V_341 ;
V_92 -> V_291 [ 0 ] = V_273 ;
break;
case V_378 :
V_92 -> V_291 [ 0 ] = V_274 ;
break;
case V_379 :
V_92 -> V_291 [ 0 ] = V_275 ;
break;
default:
F_178 ( V_340 ) ;
goto error;
}
V_8 = F_5 ( F_231 ( V_4 , 0 ) ) & 0xfffff000 ;
V_333 -> V_8 = V_8 ;
V_309 = F_5 ( F_234 ( V_4 , 0 ) ) ;
V_121 = F_5 ( F_235 ( V_4 , 0 ) ) ;
V_92 -> V_276 = ( ( V_121 >> 16 ) & 0xfff ) + 1 ;
V_92 -> V_343 = ( ( V_121 >> 0 ) & 0x1fff ) + 1 ;
V_121 = F_5 ( F_236 ( V_4 , 0 ) ) ;
V_835 = F_227 ( V_10 , V_92 -> V_291 [ 0 ] ,
V_92 -> V_268 ) ;
V_92 -> V_289 [ 0 ] = ( V_121 & 0x3ff ) * V_835 ;
V_776 = F_179 ( V_10 , V_92 -> V_276 ,
V_92 -> V_268 ,
V_92 -> V_291 [ 0 ] ) ;
V_333 -> V_339 = V_92 -> V_289 [ 0 ] * V_776 ;
F_144 ( L_117 ,
F_71 ( V_4 ) , V_92 -> V_343 , V_92 -> V_276 ,
V_92 -> V_368 , V_8 , V_92 -> V_289 [ 0 ] ,
V_333 -> V_339 ) ;
V_333 -> V_92 = V_778 ;
return;
error:
F_210 ( V_92 ) ;
}
static void F_565 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_215 ;
V_215 = F_5 ( F_263 ( V_29 -> V_4 ) ) ;
if ( V_215 & V_493 ) {
V_210 -> V_400 . V_120 = true ;
V_210 -> V_400 . V_492 = F_5 ( F_264 ( V_29 -> V_4 ) ) ;
V_210 -> V_400 . V_339 = F_5 ( F_265 ( V_29 -> V_4 ) ) ;
if ( F_566 ( V_10 ) ) {
F_3 ( ( V_215 & V_840 ) !=
F_334 ( V_29 -> V_4 ) ) ;
}
}
}
static void
F_567 ( struct V_28 * V_29 ,
struct V_332 * V_333 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_121 , V_8 , V_309 ;
int V_4 = V_29 -> V_4 ;
int V_775 , V_268 ;
unsigned int V_776 ;
struct V_279 * V_92 ;
struct V_777 * V_778 ;
V_121 = F_5 ( F_80 ( V_4 ) ) ;
if ( ! ( V_121 & V_165 ) )
return;
V_778 = F_444 ( sizeof( * V_778 ) , V_487 ) ;
if ( ! V_778 ) {
F_144 ( L_105 ) ;
return;
}
V_92 = & V_778 -> V_8 ;
if ( F_45 ( V_10 ) -> V_105 >= 4 ) {
if ( V_121 & V_362 ) {
V_333 -> V_340 = V_341 ;
V_92 -> V_291 [ 0 ] = V_273 ;
}
}
V_268 = V_121 & V_779 ;
V_775 = F_197 ( V_268 ) ;
V_92 -> V_268 = V_775 ;
V_92 -> V_368 = F_176 ( V_775 , 0 ) * 8 ;
V_8 = F_5 ( F_166 ( V_4 ) ) & 0xfffff000 ;
if ( F_225 ( V_10 ) || F_170 ( V_10 ) ) {
V_309 = F_5 ( F_226 ( V_4 ) ) ;
} else {
if ( V_333 -> V_340 )
V_309 = F_5 ( F_222 ( V_4 ) ) ;
else
V_309 = F_5 ( F_223 ( V_4 ) ) ;
}
V_333 -> V_8 = V_8 ;
V_121 = F_5 ( F_262 ( V_4 ) ) ;
V_92 -> V_343 = ( ( V_121 >> 16 ) & 0xfff ) + 1 ;
V_92 -> V_276 = ( ( V_121 >> 0 ) & 0xfff ) + 1 ;
V_121 = F_5 ( F_221 ( V_4 ) ) ;
V_92 -> V_289 [ 0 ] = V_121 & 0xffffffc0 ;
V_776 = F_179 ( V_10 , V_92 -> V_276 ,
V_92 -> V_268 ,
V_92 -> V_291 [ 0 ] ) ;
V_333 -> V_339 = V_92 -> V_289 [ 0 ] * V_776 ;
F_144 ( L_117 ,
F_71 ( V_4 ) , V_92 -> V_343 , V_92 -> V_276 ,
V_92 -> V_368 , V_8 , V_92 -> V_289 [ 0 ] ,
V_333 -> V_339 ) ;
V_333 -> V_92 = V_778 ;
}
static bool F_568 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_215 ;
if ( ! F_77 ( V_12 ,
F_399 ( V_29 -> V_4 ) ) )
return false ;
V_210 -> V_98 = (enum V_96 ) V_29 -> V_4 ;
V_210 -> V_128 = V_482 ;
V_215 = F_5 ( F_46 ( V_29 -> V_4 ) ) ;
if ( ! ( V_215 & V_163 ) )
return false ;
switch ( V_215 & V_244 ) {
case V_755 :
V_210 -> V_611 = 18 ;
break;
case V_756 :
V_210 -> V_611 = 24 ;
break;
case V_757 :
V_210 -> V_611 = 30 ;
break;
case V_816 :
V_210 -> V_611 = 36 ;
break;
default:
break;
}
if ( V_215 & V_763 )
V_210 -> V_762 = true ;
if ( F_5 ( F_98 ( V_29 -> V_4 ) ) & V_178 ) {
struct V_127 * V_130 ;
V_210 -> V_258 = true ;
V_215 = F_5 ( F_66 ( V_29 -> V_4 ) ) ;
V_210 -> V_415 = ( ( V_414 & V_215 ) >>
V_841 ) + 1 ;
F_562 ( V_29 , V_210 ) ;
if ( F_50 ( V_12 -> V_10 ) ) {
V_210 -> V_128 =
(enum V_483 ) V_29 -> V_4 ;
} else {
V_215 = F_5 ( V_469 ) ;
if ( V_215 & F_319 ( V_29 -> V_4 ) )
V_210 -> V_128 = V_470 ;
else
V_210 -> V_128 = V_842 ;
}
V_130 = & V_12 -> V_129 [ V_210 -> V_128 ] ;
F_3 ( ! V_130 -> V_133 ( V_12 , V_130 ,
& V_210 -> V_211 ) ) ;
V_215 = V_210 -> V_211 . V_67 ;
V_210 -> V_522 =
( ( V_215 & V_843 )
>> V_833 ) + 1 ;
F_569 ( V_29 , V_210 ) ;
} else {
V_210 -> V_522 = 1 ;
}
F_520 ( V_29 , V_210 ) ;
F_565 ( V_29 , V_210 ) ;
return true ;
}
static void F_570 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_28 * V_29 ;
F_131 (dev, crtc)
F_54 ( V_29 -> V_90 , L_118 ,
F_71 ( V_29 -> V_4 ) ) ;
F_54 ( F_5 ( V_844 ) , L_119 ) ;
F_54 ( F_5 ( V_845 ) & V_846 , L_120 ) ;
F_54 ( F_5 ( V_847 ) & V_848 , L_121 ) ;
F_54 ( F_5 ( V_849 ) & V_848 , L_122 ) ;
F_54 ( F_5 ( V_850 ) & V_851 , L_123 ) ;
F_54 ( F_5 ( V_852 ) & V_853 ,
L_124 ) ;
if ( F_225 ( V_10 ) )
F_54 ( F_5 ( V_854 ) & V_853 ,
L_125 ) ;
F_54 ( F_5 ( V_855 ) & V_856 ,
L_126 ) ;
F_54 ( F_5 ( V_857 ) & V_858 ,
L_127 ) ;
F_54 ( F_5 ( V_859 ) & V_860 , L_128 ) ;
F_54 ( F_571 ( V_12 ) , L_129 ) ;
}
static T_4 F_572 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
if ( F_225 ( V_10 ) )
return F_5 ( V_861 ) ;
else
return F_5 ( V_862 ) ;
}
static void F_573 ( struct V_11 * V_12 , T_4 V_121 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
if ( F_225 ( V_10 ) ) {
F_56 ( & V_12 -> V_502 . V_503 ) ;
if ( F_344 ( V_12 , V_863 ,
V_121 ) )
F_123 ( L_130 ) ;
F_58 ( & V_12 -> V_502 . V_503 ) ;
} else {
F_120 ( V_862 , V_121 ) ;
F_121 ( V_862 ) ;
}
}
static void F_574 ( struct V_11 * V_12 ,
bool V_864 , bool V_865 )
{
T_4 V_121 ;
F_570 ( V_12 ) ;
V_121 = F_5 ( V_866 ) ;
if ( V_864 ) {
V_121 |= V_867 ;
F_120 ( V_866 , V_121 ) ;
if ( F_533 ( F_5 ( V_866 ) &
V_868 , 1 ) )
F_123 ( L_131 ) ;
V_121 = F_5 ( V_866 ) ;
}
V_121 |= V_869 ;
F_120 ( V_866 , V_121 ) ;
F_121 ( V_866 ) ;
if ( F_47 ( ( F_5 ( V_866 ) & V_870 ) == 0 , 1 ) )
F_123 ( L_132 ) ;
V_121 = F_572 ( V_12 ) ;
V_121 |= V_871 ;
F_573 ( V_12 , V_121 ) ;
F_575 ( 100 ) ;
if ( F_47 ( ( F_572 ( V_12 ) & V_872 ) == 0 ,
1 ) )
F_123 ( L_133 ) ;
if ( V_865 ) {
V_121 = F_5 ( V_866 ) ;
V_121 |= V_873 ;
F_120 ( V_866 , V_121 ) ;
F_121 ( V_866 ) ;
}
}
static void F_576 ( struct V_11 * V_12 )
{
T_4 V_121 ;
V_121 = F_5 ( V_866 ) ;
if ( ( V_121 & ( V_870 | V_869 | V_867 |
V_873 ) ) == V_870 )
return;
F_577 ( V_12 , V_874 ) ;
if ( V_121 & V_873 ) {
V_121 &= ~ V_873 ;
F_120 ( V_866 , V_121 ) ;
F_121 ( V_866 ) ;
}
V_121 = F_572 ( V_12 ) ;
V_121 |= V_875 ;
V_121 &= ~ V_871 ;
F_573 ( V_12 , V_121 ) ;
V_121 = F_5 ( V_866 ) ;
V_121 &= ~ V_869 ;
F_120 ( V_866 , V_121 ) ;
if ( F_47 ( F_5 ( V_866 ) & V_870 , 5 ) )
F_123 ( L_134 ) ;
if ( V_121 & V_867 ) {
V_121 = F_5 ( V_866 ) ;
V_121 &= ~ V_867 ;
F_120 ( V_866 , V_121 ) ;
if ( F_533 ( ( F_5 ( V_866 ) &
V_868 ) == 0 , 1 ) )
F_123 ( L_135 ) ;
}
F_578 ( V_12 , V_874 ) ;
}
void F_579 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_121 ;
F_144 ( L_136 ) ;
if ( V_12 -> V_808 == V_809 ) {
V_121 = F_5 ( V_876 ) ;
V_121 &= ~ V_877 ;
F_120 ( V_876 , V_121 ) ;
}
F_536 ( V_10 ) ;
F_574 ( V_12 , true , true ) ;
}
void F_580 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_121 ;
F_144 ( L_137 ) ;
F_576 ( V_12 ) ;
F_537 ( V_10 ) ;
if ( V_12 -> V_808 == V_809 ) {
V_121 = F_5 ( V_876 ) ;
V_121 |= V_877 ;
F_120 ( V_876 , V_121 ) ;
}
F_581 ( V_10 ) ;
}
static int F_582 ( struct V_28 * V_29 ,
struct V_31 * V_32 )
{
if ( ! F_583 ( V_29 , V_32 ) )
return - V_292 ;
V_29 -> V_660 = false ;
return 0 ;
}
static void F_584 ( struct V_11 * V_12 ,
enum V_108 V_108 ,
struct V_31 * V_210 )
{
T_1 V_402 , V_878 ;
V_402 = F_5 ( V_879 ) & F_585 ( V_108 ) ;
V_210 -> V_880 = V_402 >> ( V_108 * 3 + 1 ) ;
switch ( V_210 -> V_880 ) {
case V_881 :
V_878 = F_5 ( V_882 ) ;
V_210 -> V_211 . V_883 = V_878 & 0x3f ;
break;
case V_884 :
V_210 -> V_128 = V_885 ;
break;
case V_886 :
V_210 -> V_128 = V_887 ;
break;
case V_888 :
V_210 -> V_128 = V_889 ;
break;
}
}
static void F_586 ( struct V_11 * V_12 ,
enum V_108 V_108 ,
struct V_31 * V_210 )
{
V_210 -> V_880 = F_5 ( F_587 ( V_108 ) ) ;
switch ( V_210 -> V_880 ) {
case V_890 :
V_210 -> V_128 = V_891 ;
break;
case V_892 :
V_210 -> V_128 = V_893 ;
break;
}
}
static void F_588 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_127 * V_130 ;
enum V_108 V_108 ;
T_4 V_215 ;
V_215 = F_5 ( F_63 ( V_210 -> V_98 ) ) ;
V_108 = ( V_215 & V_894 ) >> V_895 ;
if ( F_378 ( V_10 ) )
F_584 ( V_12 , V_108 , V_210 ) ;
else
F_586 ( V_12 , V_108 , V_210 ) ;
if ( V_210 -> V_128 >= 0 ) {
V_130 = & V_12 -> V_129 [ V_210 -> V_128 ] ;
F_3 ( ! V_130 -> V_133 ( V_12 , V_130 ,
& V_210 -> V_211 ) ) ;
}
if ( F_45 ( V_10 ) -> V_105 < 9 &&
( V_108 == V_896 ) && F_5 ( V_255 ) & V_178 ) {
V_210 -> V_258 = true ;
V_215 = F_5 ( F_66 ( V_142 ) ) ;
V_210 -> V_415 = ( ( V_414 & V_215 ) >>
V_841 ) + 1 ;
F_562 ( V_29 , V_210 ) ;
}
}
static bool F_589 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_532 V_897 ;
T_4 V_215 ;
if ( ! F_77 ( V_12 ,
F_399 ( V_29 -> V_4 ) ) )
return false ;
V_210 -> V_98 = (enum V_96 ) V_29 -> V_4 ;
V_210 -> V_128 = V_482 ;
V_215 = F_5 ( F_63 ( V_521 ) ) ;
if ( V_215 & V_135 ) {
enum V_4 V_898 ;
switch ( V_215 & V_899 ) {
default:
F_48 ( 1 , L_138 ) ;
case V_900 :
case V_901 :
V_898 = V_142 ;
break;
case V_902 :
V_898 = V_151 ;
break;
case V_903 :
V_898 = V_465 ;
break;
}
if ( V_898 == V_29 -> V_4 )
V_210 -> V_98 = V_521 ;
}
if ( ! F_77 ( V_12 ,
F_78 ( V_210 -> V_98 ) ) )
return false ;
V_215 = F_5 ( F_46 ( V_210 -> V_98 ) ) ;
if ( ! ( V_215 & V_163 ) )
return false ;
F_588 ( V_29 , V_210 ) ;
F_520 ( V_29 , V_210 ) ;
V_897 = F_400 ( V_29 -> V_4 ) ;
if ( F_77 ( V_12 , V_897 ) ) {
if ( F_378 ( V_10 ) )
F_563 ( V_29 , V_210 ) ;
else
F_565 ( V_29 , V_210 ) ;
}
if ( F_225 ( V_10 ) )
V_210 -> V_501 = F_370 ( V_29 ) &&
( F_5 ( V_505 ) & V_506 ) ;
if ( V_210 -> V_98 != V_521 ) {
V_210 -> V_522 =
F_5 ( F_374 ( V_210 -> V_98 ) ) + 1 ;
} else {
V_210 -> V_522 = 1 ;
}
return true ;
}
static void F_590 ( struct V_89 * V_29 , T_1 V_8 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
T_4 V_904 = 0 , V_339 = 0 ;
if ( V_8 ) {
unsigned int V_343 = V_28 -> V_8 . V_905 -> V_34 -> V_906 ;
unsigned int V_276 = V_28 -> V_8 . V_905 -> V_34 -> V_907 ;
unsigned int V_342 = F_591 ( V_343 ) * 4 ;
switch ( V_342 ) {
default:
F_177 ( 1 , L_139 ,
V_343 , V_342 ) ;
V_342 = 256 ;
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
}
V_904 |= V_158 |
V_908 |
V_909 |
F_592 ( V_342 ) ;
V_339 = ( V_276 << 12 ) | V_343 ;
}
if ( V_28 -> V_910 != 0 &&
( V_28 -> V_911 != V_8 ||
V_28 -> V_912 != V_339 ||
V_28 -> V_910 != V_904 ) ) {
F_120 ( V_157 , 0 ) ;
F_121 ( V_157 ) ;
V_28 -> V_910 = 0 ;
}
if ( V_28 -> V_911 != V_8 ) {
F_120 ( V_913 , V_8 ) ;
V_28 -> V_911 = V_8 ;
}
if ( V_28 -> V_912 != V_339 ) {
F_120 ( V_914 , V_339 ) ;
V_28 -> V_912 = V_339 ;
}
if ( V_28 -> V_910 != V_904 ) {
F_120 ( V_157 , V_904 ) ;
F_121 ( V_157 ) ;
V_28 -> V_910 = V_904 ;
}
}
static void F_593 ( struct V_89 * V_29 , T_1 V_8 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_4 V_904 ;
V_904 = 0 ;
if ( V_8 ) {
V_904 = V_915 ;
switch ( V_28 -> V_8 . V_905 -> V_34 -> V_906 ) {
case 64 :
V_904 |= V_916 ;
break;
case 128 :
V_904 |= V_917 ;
break;
case 256 :
V_904 |= V_918 ;
break;
default:
F_178 ( V_28 -> V_8 . V_905 -> V_34 -> V_906 ) ;
return;
}
V_904 |= V_4 << 28 ;
if ( F_225 ( V_10 ) || F_170 ( V_10 ) )
V_904 |= V_919 ;
}
if ( V_29 -> V_905 -> V_34 -> V_286 == F_220 ( V_365 ) )
V_904 |= V_920 ;
if ( V_28 -> V_910 != V_904 ) {
F_120 ( F_75 ( V_4 ) , V_904 ) ;
F_121 ( F_75 ( V_4 ) ) ;
V_28 -> V_910 = V_904 ;
}
F_120 ( F_594 ( V_4 ) , V_8 ) ;
F_121 ( F_594 ( V_4 ) ) ;
V_28 -> V_911 = V_8 ;
}
static void F_355 ( struct V_89 * V_29 ,
bool V_236 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
int V_265 = V_29 -> V_921 ;
int V_266 = V_29 -> V_922 ;
T_1 V_8 = 0 , V_492 = 0 ;
if ( V_236 )
V_8 = V_28 -> V_923 ;
if ( V_265 >= V_28 -> V_93 -> V_357 )
V_8 = 0 ;
if ( V_266 >= V_28 -> V_93 -> V_356 )
V_8 = 0 ;
if ( V_265 < 0 ) {
if ( V_265 + V_28 -> V_8 . V_905 -> V_34 -> V_906 <= 0 )
V_8 = 0 ;
V_492 |= V_924 << V_925 ;
V_265 = - V_265 ;
}
V_492 |= V_265 << V_925 ;
if ( V_266 < 0 ) {
if ( V_266 + V_28 -> V_8 . V_905 -> V_34 -> V_907 <= 0 )
V_8 = 0 ;
V_492 |= V_924 << V_926 ;
V_266 = - V_266 ;
}
V_492 |= V_266 << V_926 ;
if ( V_8 == 0 && V_28 -> V_911 == 0 )
return;
F_120 ( F_595 ( V_4 ) , V_492 ) ;
if ( F_349 ( V_10 ) &&
V_29 -> V_905 -> V_34 -> V_286 == F_220 ( V_365 ) ) {
V_8 += ( V_28 -> V_8 . V_905 -> V_34 -> V_907 *
V_28 -> V_8 . V_905 -> V_34 -> V_906 - 1 ) * 4 ;
}
if ( F_73 ( V_10 ) || F_74 ( V_10 ) )
F_590 ( V_29 , V_8 ) ;
else
F_593 ( V_29 , V_8 ) ;
}
static bool F_596 ( struct V_9 * V_10 ,
T_4 V_343 , T_4 V_276 )
{
if ( V_343 == 0 || V_276 == 0 )
return false ;
if ( F_73 ( V_10 ) || F_74 ( V_10 ) ) {
if ( ( V_343 & 63 ) != 0 )
return false ;
if ( V_343 > ( F_73 ( V_10 ) ? 64 : 512 ) )
return false ;
if ( V_276 > 1023 )
return false ;
} else {
switch ( V_343 | V_276 ) {
case 256 :
case 128 :
if ( F_22 ( V_10 ) )
return false ;
case 64 :
break;
default:
return false ;
}
}
return true ;
}
static void F_597 ( struct V_89 * V_29 , T_5 * V_927 , T_5 * V_928 ,
T_5 * V_929 , T_4 V_930 , T_4 V_339 )
{
int V_931 = ( V_930 + V_339 > 256 ) ? 256 : V_930 + V_339 , V_37 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
for ( V_37 = V_930 ; V_37 < V_931 ; V_37 ++ ) {
V_28 -> V_511 [ V_37 ] = V_927 [ V_37 ] >> 8 ;
V_28 -> V_512 [ V_37 ] = V_928 [ V_37 ] >> 8 ;
V_28 -> V_513 [ V_37 ] = V_929 [ V_37 ] >> 8 ;
}
F_347 ( V_29 ) ;
}
struct V_279 *
F_598 ( struct V_9 * V_10 ,
struct V_334 * V_335 ,
struct V_295 * V_296 )
{
struct V_777 * V_778 ;
int V_298 ;
V_778 = F_444 ( sizeof( * V_778 ) , V_487 ) ;
if ( ! V_778 ) {
F_205 ( & V_296 -> V_8 ) ;
return F_599 ( - V_489 ) ;
}
V_298 = F_203 ( V_10 , V_778 , V_335 , V_296 ) ;
if ( V_298 )
goto V_74;
return & V_778 -> V_8 ;
V_74:
F_205 ( & V_296 -> V_8 ) ;
F_210 ( V_778 ) ;
return F_599 ( V_298 ) ;
}
static struct V_279 *
F_600 ( struct V_9 * V_10 ,
struct V_334 * V_335 ,
struct V_295 * V_296 )
{
struct V_279 * V_92 ;
int V_298 ;
V_298 = F_601 ( V_10 ) ;
if ( V_298 )
return F_599 ( V_298 ) ;
V_92 = F_598 ( V_10 , V_335 , V_296 ) ;
F_58 ( & V_10 -> V_299 ) ;
return V_92 ;
}
static T_1
F_602 ( int V_343 , int V_829 )
{
T_1 V_288 = F_406 ( V_343 * V_829 , 8 ) ;
return F_180 ( V_288 , 64 ) ;
}
static T_1
F_603 ( struct V_395 * V_477 , int V_829 )
{
T_1 V_288 = F_602 ( V_477 -> V_617 , V_829 ) ;
return F_604 ( V_288 * V_477 -> V_745 ) ;
}
static struct V_279 *
F_605 ( struct V_9 * V_10 ,
struct V_395 * V_477 ,
int V_932 , int V_829 )
{
struct V_295 * V_296 ;
struct V_334 V_335 = { 0 } ;
V_296 = F_606 ( V_10 ,
F_603 ( V_477 , V_829 ) ) ;
if ( V_296 == NULL )
return F_599 ( - V_489 ) ;
V_335 . V_343 = V_477 -> V_617 ;
V_335 . V_276 = V_477 -> V_745 ;
V_335 . V_289 [ 0 ] = F_602 ( V_335 . V_343 ,
V_829 ) ;
V_335 . V_268 = F_607 ( V_829 , V_932 ) ;
return F_600 ( V_10 , & V_335 , V_296 ) ;
}
static struct V_279 *
F_608 ( struct V_9 * V_10 ,
struct V_395 * V_477 )
{
#ifdef F_609
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_295 * V_296 ;
struct V_279 * V_92 ;
if ( ! V_12 -> V_933 )
return NULL ;
if ( ! V_12 -> V_933 -> V_92 )
return NULL ;
V_296 = V_12 -> V_933 -> V_92 -> V_296 ;
F_118 ( ! V_296 ) ;
V_92 = & V_12 -> V_933 -> V_92 -> V_8 ;
if ( V_92 -> V_289 [ 0 ] < F_602 ( V_477 -> V_617 ,
V_92 -> V_368 ) )
return NULL ;
if ( V_296 -> V_8 . V_339 < V_477 -> V_745 * V_92 -> V_289 [ 0 ] )
return NULL ;
return V_92 ;
#else
return NULL ;
#endif
}
bool F_610 ( struct V_597 * V_3 ,
struct V_395 * V_477 ,
struct V_934 * V_935 ,
struct V_936 * V_937 )
{
struct V_28 * V_28 ;
struct V_1 * V_1 =
F_611 ( V_3 ) ;
struct V_89 * V_938 ;
struct V_602 * V_6 = & V_1 -> V_8 ;
struct V_89 * V_29 = NULL ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_279 * V_92 ;
struct V_939 * V_93 = & V_10 -> V_940 ;
struct V_33 * V_34 = NULL ;
struct V_35 * V_36 ;
int V_298 , V_37 = - 1 ;
F_144 ( L_140 ,
V_3 -> V_8 . V_238 , V_3 -> V_134 ,
V_6 -> V_8 . V_238 , V_6 -> V_134 ) ;
V_420:
V_298 = F_242 ( & V_93 -> V_941 , V_937 ) ;
if ( V_298 )
goto V_942;
if ( V_6 -> V_29 ) {
V_29 = V_6 -> V_29 ;
V_298 = F_242 ( & V_29 -> V_384 , V_937 ) ;
if ( V_298 )
goto V_942;
V_298 = F_242 ( & V_29 -> V_91 -> V_384 , V_937 ) ;
if ( V_298 )
goto V_942;
V_935 -> V_943 = V_3 -> V_600 ;
V_935 -> V_944 = false ;
if ( V_3 -> V_600 != V_603 )
V_3 -> V_495 -> V_600 ( V_3 , V_603 ) ;
return true ;
}
F_211 (dev, possible_crtc) {
V_37 ++ ;
if ( ! ( V_6 -> V_945 & ( 1 << V_37 ) ) )
continue;
if ( V_938 -> V_34 -> V_240 )
continue;
if ( F_31 ( V_938 ) -> V_578 )
continue;
V_29 = V_938 ;
break;
}
if ( ! V_29 ) {
F_144 ( L_141 ) ;
goto V_942;
}
V_298 = F_242 ( & V_29 -> V_384 , V_937 ) ;
if ( V_298 )
goto V_942;
V_298 = F_242 ( & V_29 -> V_91 -> V_384 , V_937 ) ;
if ( V_298 )
goto V_942;
V_1 -> V_946 = F_31 ( V_29 ) ;
F_612 ( V_3 ) -> V_947 = V_1 ;
V_28 = F_31 ( V_29 ) ;
V_28 -> V_578 = true ;
V_28 -> V_484 = V_28 -> V_93 ;
V_935 -> V_943 = V_3 -> V_600 ;
V_935 -> V_944 = true ;
V_935 -> V_948 = NULL ;
V_34 = F_613 ( V_10 ) ;
if ( ! V_34 )
return false ;
V_34 -> V_949 = V_937 ;
V_36 = F_614 ( V_34 , V_3 ) ;
if ( F_615 ( V_36 ) ) {
V_298 = F_616 ( V_36 ) ;
goto V_950;
}
V_36 -> V_29 = V_29 ;
V_36 -> V_42 = & V_1 -> V_8 ;
if ( ! V_477 )
V_477 = & V_951 ;
V_92 = F_608 ( V_10 , V_477 ) ;
if ( V_92 == NULL ) {
F_144 ( L_142 ) ;
V_92 = F_605 ( V_10 , V_477 , 24 , 32 ) ;
V_935 -> V_948 = V_92 ;
} else
F_144 ( L_143 ) ;
if ( F_615 ( V_92 ) ) {
F_144 ( L_144 ) ;
goto V_950;
}
if ( F_617 ( V_29 , V_477 , 0 , 0 , V_92 , V_34 ) ) {
F_144 ( L_145 ) ;
if ( V_935 -> V_948 )
V_935 -> V_948 -> V_495 -> V_952 ( V_935 -> V_948 ) ;
goto V_950;
}
V_29 -> V_91 -> V_29 = V_29 ;
F_171 ( V_10 , V_28 -> V_4 ) ;
return true ;
V_950:
V_28 -> V_578 = V_29 -> V_34 -> V_240 ;
if ( V_28 -> V_578 )
V_28 -> V_484 = V_28 -> V_93 ;
else
V_28 -> V_484 = NULL ;
V_942:
if ( V_34 ) {
F_618 ( V_34 ) ;
V_34 = NULL ;
}
if ( V_298 == - V_953 ) {
F_619 ( V_937 ) ;
goto V_420;
}
return false ;
}
void F_620 ( struct V_597 * V_3 ,
struct V_934 * V_935 ,
struct V_936 * V_937 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_1 * V_1 =
F_611 ( V_3 ) ;
struct V_602 * V_6 = & V_1 -> V_8 ;
struct V_89 * V_29 = V_6 -> V_29 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
F_144 ( L_140 ,
V_3 -> V_8 . V_238 , V_3 -> V_134 ,
V_6 -> V_8 . V_238 , V_6 -> V_134 ) ;
if ( V_935 -> V_944 ) {
V_34 = F_613 ( V_10 ) ;
if ( ! V_34 )
goto V_950;
V_34 -> V_949 = V_937 ;
V_36 = F_614 ( V_34 , V_3 ) ;
if ( F_615 ( V_36 ) )
goto V_950;
F_612 ( V_3 ) -> V_947 = NULL ;
V_1 -> V_946 = NULL ;
V_28 -> V_578 = false ;
V_28 -> V_484 = NULL ;
V_36 -> V_42 = NULL ;
V_36 -> V_29 = NULL ;
F_617 ( V_29 , NULL , 0 , 0 , NULL , V_34 ) ;
F_618 ( V_34 ) ;
if ( V_935 -> V_948 ) {
F_621 ( V_935 -> V_948 ) ;
F_207 ( V_935 -> V_948 ) ;
}
return;
}
if ( V_935 -> V_943 != V_603 )
V_3 -> V_495 -> V_600 ( V_3 , V_935 -> V_943 ) ;
return;
V_950:
F_144 ( L_146 ) ;
F_618 ( V_34 ) ;
}
static int F_622 ( struct V_9 * V_10 ,
const struct V_31 * V_210 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_67 = V_210 -> V_211 . V_67 ;
if ( ( V_67 & V_954 ) == V_729 )
return V_12 -> V_653 . V_656 ;
else if ( F_4 ( V_10 ) )
return 120000 ;
else if ( ! F_22 ( V_10 ) )
return 96000 ;
else
return 48000 ;
}
static void F_529 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_210 -> V_98 ;
T_1 V_67 = V_210 -> V_211 . V_67 ;
T_1 V_658 ;
T_2 clock ;
int V_18 = F_622 ( V_10 , V_210 ) ;
if ( ( V_67 & V_955 ) == 0 )
V_658 = V_210 -> V_211 . V_592 ;
else
V_658 = V_210 -> V_211 . V_593 ;
clock . V_20 = ( V_658 & V_956 ) >> V_957 ;
if ( F_19 ( V_10 ) ) {
clock . V_25 = F_623 ( ( V_658 & V_958 ) >> V_959 ) - 1 ;
clock . V_21 = ( V_658 & V_960 ) >> V_961 ;
} else {
clock . V_25 = ( V_658 & V_962 ) >> V_959 ;
clock . V_21 = ( V_658 & V_963 ) >> V_961 ;
}
if ( ! F_22 ( V_10 ) ) {
if ( F_19 ( V_10 ) )
clock . V_23 = F_623 ( ( V_67 & V_964 ) >>
V_719 ) ;
else
clock . V_23 = F_623 ( ( V_67 & V_965 ) >>
V_720 ) ;
switch ( V_67 & V_966 ) {
case V_716 :
clock . V_24 = V_67 & V_722 ?
5 : 10 ;
break;
case V_715 :
clock . V_24 = V_67 & V_723 ?
7 : 14 ;
break;
default:
F_144 ( L_147
L_148 , ( int ) ( V_67 & V_966 ) ) ;
return;
}
if ( F_19 ( V_10 ) )
F_23 ( V_18 , & clock ) ;
else
F_25 ( V_18 , & clock ) ;
} else {
T_1 V_967 = F_133 ( V_10 ) ? 0 : F_5 ( V_153 ) ;
bool V_766 = ( V_4 == 1 ) && ( V_967 & V_189 ) ;
if ( V_766 ) {
clock . V_23 = F_623 ( ( V_67 & V_968 ) >>
V_720 ) ;
if ( V_967 & V_969 )
clock . V_24 = 7 ;
else
clock . V_24 = 14 ;
} else {
if ( V_67 & V_731 )
clock . V_23 = 2 ;
else {
clock . V_23 = ( ( V_67 & V_970 ) >>
V_720 ) + 2 ;
}
if ( V_67 & V_732 )
clock . V_24 = 4 ;
else
clock . V_24 = 2 ;
}
F_25 ( V_18 , & clock ) ;
}
V_210 -> V_691 = clock . V_27 ;
}
int F_624 ( int V_971 ,
const struct V_645 * V_646 )
{
if ( ! V_646 -> V_651 )
return 0 ;
return F_36 ( ( V_972 ) V_646 -> V_650 * V_971 , V_646 -> V_651 ) ;
}
static void F_569 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
F_529 ( V_29 , V_210 ) ;
V_210 -> V_8 . V_94 . V_95 =
F_624 ( F_6 ( V_10 ) * 10000 ,
& V_210 -> V_517 ) ;
}
struct V_395 * F_625 ( struct V_9 * V_10 ,
struct V_89 * V_29 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
enum V_96 V_98 = V_28 -> V_93 -> V_98 ;
struct V_395 * V_477 ;
struct V_31 V_210 ;
int V_973 = F_5 ( F_300 ( V_98 ) ) ;
int V_974 = F_5 ( F_304 ( V_98 ) ) ;
int V_975 = F_5 ( F_306 ( V_98 ) ) ;
int V_976 = F_5 ( F_310 ( V_98 ) ) ;
enum V_4 V_4 = V_28 -> V_4 ;
V_477 = F_444 ( sizeof( * V_477 ) , V_487 ) ;
if ( ! V_477 )
return NULL ;
V_210 . V_98 = (enum V_96 ) V_4 ;
V_210 . V_522 = 1 ;
V_210 . V_211 . V_67 = F_5 ( F_53 ( V_4 ) ) ;
V_210 . V_211 . V_592 = F_5 ( F_428 ( V_4 ) ) ;
V_210 . V_211 . V_593 = F_5 ( F_429 ( V_4 ) ) ;
F_529 ( V_28 , & V_210 ) ;
V_477 -> clock = V_210 . V_691 / V_210 . V_522 ;
V_477 -> V_617 = ( V_973 & 0xffff ) + 1 ;
V_477 -> V_746 = ( ( V_973 & 0xffff0000 ) >> 16 ) + 1 ;
V_477 -> V_616 = ( V_974 & 0xffff ) + 1 ;
V_477 -> V_747 = ( ( V_974 & 0xffff0000 ) >> 16 ) + 1 ;
V_477 -> V_745 = ( V_975 & 0xffff ) + 1 ;
V_477 -> V_748 = ( ( V_975 & 0xffff0000 ) >> 16 ) + 1 ;
V_477 -> V_749 = ( V_976 & 0xffff ) + 1 ;
V_477 -> V_750 = ( ( V_976 & 0xffff0000 ) >> 16 ) + 1 ;
F_626 ( V_477 ) ;
return V_477 ;
}
static void F_627 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
if ( ! F_349 ( V_10 ) )
return;
if ( ! V_12 -> V_769 )
return;
if ( ! F_522 ( V_10 ) && V_28 -> V_660 ) {
int V_4 = V_28 -> V_4 ;
int V_230 = F_53 ( V_4 ) ;
int V_67 ;
F_141 ( L_149 ) ;
F_69 ( V_12 , V_4 ) ;
V_67 = F_5 ( V_230 ) ;
V_67 |= V_955 ;
F_120 ( V_230 , V_67 ) ;
F_171 ( V_10 , V_4 ) ;
V_67 = F_5 ( V_230 ) ;
if ( ! ( V_67 & V_955 ) )
F_141 ( L_150 ) ;
}
}
void F_628 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_12 -> V_300 . V_977 )
return;
F_188 ( V_12 ) ;
F_629 ( V_12 ) ;
if ( F_45 ( V_10 ) -> V_105 >= 6 )
F_630 ( V_12 ) ;
V_12 -> V_300 . V_977 = true ;
}
void F_631 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_29 ;
if ( ! V_12 -> V_300 . V_977 )
return;
V_12 -> V_300 . V_977 = false ;
F_211 (dev, crtc) {
if ( ! V_29 -> V_91 -> V_92 )
continue;
F_627 ( V_29 ) ;
}
if ( F_45 ( V_10 ) -> V_105 >= 6 )
F_632 ( V_10 -> V_13 ) ;
F_192 ( V_12 ) ;
}
static void F_633 ( struct V_28 * V_29 ,
struct V_31 * V_32 )
{
F_210 ( V_29 -> V_93 ) ;
V_29 -> V_93 = V_32 ;
V_29 -> V_8 . V_34 = & V_32 -> V_8 ;
}
static void F_634 ( struct V_89 * V_29 )
{
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_436 * V_437 ;
F_251 ( & V_10 -> V_393 ) ;
V_437 = V_28 -> V_394 ;
V_28 -> V_394 = NULL ;
F_252 ( & V_10 -> V_393 ) ;
if ( V_437 ) {
F_635 ( & V_437 -> V_437 ) ;
F_210 ( V_437 ) ;
}
F_633 ( V_28 , NULL ) ;
F_636 ( V_29 ) ;
F_210 ( V_28 ) ;
}
static void F_637 ( struct V_978 * V_979 )
{
struct V_436 * V_437 =
F_638 ( V_979 , struct V_436 , V_437 ) ;
struct V_9 * V_10 = V_437 -> V_29 -> V_10 ;
enum V_4 V_4 = F_31 ( V_437 -> V_29 ) -> V_4 ;
F_56 ( & V_10 -> V_299 ) ;
F_194 ( V_437 -> V_388 , V_437 -> V_29 -> V_91 -> V_34 ) ;
F_205 ( & V_437 -> V_441 -> V_8 ) ;
F_356 ( V_10 ) ;
if ( V_437 -> V_980 )
F_639 ( & V_437 -> V_980 , NULL ) ;
F_58 ( & V_10 -> V_299 ) ;
F_640 ( V_10 , F_213 ( V_4 ) ) ;
F_207 ( V_437 -> V_388 ) ;
F_118 ( F_260 ( & F_31 ( V_437 -> V_29 ) -> V_435 ) == 0 ) ;
F_641 ( & F_31 ( V_437 -> V_29 ) -> V_435 ) ;
F_210 ( V_437 ) ;
}
static void F_642 ( struct V_9 * V_10 ,
struct V_89 * V_29 )
{
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_436 * V_437 ;
unsigned long V_344 ;
if ( V_28 == NULL )
return;
F_643 ( & V_10 -> V_393 , V_344 ) ;
V_437 = V_28 -> V_394 ;
F_283 () ;
if ( V_437 == NULL || F_260 ( & V_437 -> V_390 ) < V_981 ) {
F_644 ( & V_10 -> V_393 , V_344 ) ;
return;
}
F_282 ( V_28 ) ;
F_644 ( & V_10 -> V_393 , V_344 ) ;
}
void F_645 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_29 = V_12 -> V_97 [ V_4 ] ;
F_642 ( V_10 , V_29 ) ;
}
void F_240 ( struct V_9 * V_10 , int V_164 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_29 = V_12 -> V_982 [ V_164 ] ;
F_642 ( V_10 , V_29 ) ;
}
static bool F_646 ( T_1 V_983 , T_1 V_984 )
{
return ! ( ( V_983 - V_984 ) & 0x80000000 ) ;
}
static bool F_647 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_259 ( & V_12 -> V_391 ) ||
V_29 -> V_392 != F_260 ( & V_12 -> V_391 . V_392 ) )
return true ;
if ( F_45 ( V_10 ) -> V_105 < 5 && ! F_18 ( V_10 ) )
return true ;
return ( F_5 ( F_648 ( V_29 -> V_164 ) ) & ~ 0xfff ) ==
V_29 -> V_394 -> V_985 &&
F_646 ( F_5 ( F_649 ( V_29 -> V_4 ) ) ,
V_29 -> V_394 -> V_986 ) ;
}
void F_239 ( struct V_9 * V_10 , int V_164 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 =
F_31 ( V_12 -> V_982 [ V_164 ] ) ;
unsigned long V_344 ;
F_643 ( & V_10 -> V_393 , V_344 ) ;
if ( V_28 -> V_394 && F_647 ( V_28 ) )
F_650 ( & V_28 -> V_394 -> V_390 ) ;
F_644 ( & V_10 -> V_393 , V_344 ) ;
}
static inline void F_651 ( struct V_28 * V_28 )
{
F_652 () ;
F_653 ( & V_28 -> V_394 -> V_390 , V_987 ) ;
F_652 () ;
}
static int F_654 ( struct V_9 * V_10 ,
struct V_89 * V_29 ,
struct V_279 * V_92 ,
struct V_295 * V_296 ,
struct V_293 * V_988 ,
T_4 V_344 )
{
struct V_28 * V_28 = F_31 ( V_29 ) ;
T_1 V_989 ;
int V_298 ;
V_298 = F_655 ( V_988 , 6 ) ;
if ( V_298 )
return V_298 ;
if ( V_28 -> V_164 )
V_989 = V_990 ;
else
V_989 = V_991 ;
F_656 ( V_988 , V_992 | V_989 ) ;
F_656 ( V_988 , V_993 ) ;
F_656 ( V_988 , V_994 |
F_657 ( V_28 -> V_164 ) ) ;
F_656 ( V_988 , V_92 -> V_289 [ 0 ] ) ;
F_656 ( V_988 , V_28 -> V_394 -> V_985 ) ;
F_656 ( V_988 , 0 ) ;
F_651 ( V_28 ) ;
F_658 ( V_988 ) ;
return 0 ;
}
static int F_659 ( struct V_9 * V_10 ,
struct V_89 * V_29 ,
struct V_279 * V_92 ,
struct V_295 * V_296 ,
struct V_293 * V_988 ,
T_4 V_344 )
{
struct V_28 * V_28 = F_31 ( V_29 ) ;
T_1 V_989 ;
int V_298 ;
V_298 = F_655 ( V_988 , 6 ) ;
if ( V_298 )
return V_298 ;
if ( V_28 -> V_164 )
V_989 = V_990 ;
else
V_989 = V_991 ;
F_656 ( V_988 , V_992 | V_989 ) ;
F_656 ( V_988 , V_993 ) ;
F_656 ( V_988 , V_995 |
F_657 ( V_28 -> V_164 ) ) ;
F_656 ( V_988 , V_92 -> V_289 [ 0 ] ) ;
F_656 ( V_988 , V_28 -> V_394 -> V_985 ) ;
F_656 ( V_988 , V_993 ) ;
F_651 ( V_28 ) ;
F_658 ( V_988 ) ;
return 0 ;
}
static int F_660 ( struct V_9 * V_10 ,
struct V_89 * V_29 ,
struct V_279 * V_92 ,
struct V_295 * V_296 ,
struct V_293 * V_988 ,
T_4 V_344 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
T_4 V_996 , V_997 ;
int V_298 ;
V_298 = F_655 ( V_988 , 4 ) ;
if ( V_298 )
return V_298 ;
F_656 ( V_988 , V_994 |
F_657 ( V_28 -> V_164 ) ) ;
F_656 ( V_988 , V_92 -> V_289 [ 0 ] ) ;
F_656 ( V_988 , V_28 -> V_394 -> V_985 |
V_296 -> V_304 ) ;
V_996 = 0 ;
V_997 = F_5 ( F_262 ( V_28 -> V_4 ) ) & 0x0fff0fff ;
F_656 ( V_988 , V_996 | V_997 ) ;
F_651 ( V_28 ) ;
F_658 ( V_988 ) ;
return 0 ;
}
static int F_661 ( struct V_9 * V_10 ,
struct V_89 * V_29 ,
struct V_279 * V_92 ,
struct V_295 * V_296 ,
struct V_293 * V_988 ,
T_4 V_344 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
T_4 V_996 , V_997 ;
int V_298 ;
V_298 = F_655 ( V_988 , 4 ) ;
if ( V_298 )
return V_298 ;
F_656 ( V_988 , V_994 |
F_657 ( V_28 -> V_164 ) ) ;
F_656 ( V_988 , V_92 -> V_289 [ 0 ] | V_296 -> V_304 ) ;
F_656 ( V_988 , V_28 -> V_394 -> V_985 ) ;
V_996 = 0 ;
V_997 = F_5 ( F_262 ( V_28 -> V_4 ) ) & 0x0fff0fff ;
F_656 ( V_988 , V_996 | V_997 ) ;
F_651 ( V_28 ) ;
F_658 ( V_988 ) ;
return 0 ;
}
static int F_662 ( struct V_9 * V_10 ,
struct V_89 * V_29 ,
struct V_279 * V_92 ,
struct V_295 * V_296 ,
struct V_293 * V_988 ,
T_4 V_344 )
{
struct V_28 * V_28 = F_31 ( V_29 ) ;
T_4 V_998 = 0 ;
int V_999 , V_298 ;
switch ( V_28 -> V_164 ) {
case V_1000 :
V_998 = V_1001 ;
break;
case V_358 :
V_998 = V_1002 ;
break;
case V_1003 :
V_998 = V_1004 ;
break;
default:
F_177 ( 1 , L_151 ) ;
return - V_1005 ;
}
V_999 = 4 ;
if ( V_988 -> V_238 == V_1006 ) {
V_999 += 6 ;
if ( F_663 ( V_10 ) )
V_999 += 2 ;
}
V_298 = F_664 ( V_988 ) ;
if ( V_298 )
return V_298 ;
V_298 = F_655 ( V_988 , V_999 ) ;
if ( V_298 )
return V_298 ;
if ( V_988 -> V_238 == V_1006 ) {
F_656 ( V_988 , F_665 ( 1 ) ) ;
F_656 ( V_988 , V_1007 ) ;
F_656 ( V_988 , ~ ( V_1008 |
V_1009 |
V_1010 ) ) ;
if ( F_663 ( V_10 ) )
F_656 ( V_988 , F_666 ( 1 ) |
V_1011 ) ;
else
F_656 ( V_988 , F_667 ( 1 ) |
V_1011 ) ;
F_656 ( V_988 , V_1007 ) ;
F_656 ( V_988 , V_988 -> V_1012 . V_985 + 256 ) ;
if ( F_663 ( V_10 ) ) {
F_656 ( V_988 , 0 ) ;
F_656 ( V_988 , V_993 ) ;
}
}
F_656 ( V_988 , V_995 | V_998 ) ;
F_656 ( V_988 , ( V_92 -> V_289 [ 0 ] | V_296 -> V_304 ) ) ;
F_656 ( V_988 , V_28 -> V_394 -> V_985 ) ;
F_656 ( V_988 , ( V_993 ) ) ;
F_651 ( V_28 ) ;
F_658 ( V_988 ) ;
return 0 ;
}
static bool F_668 ( struct V_293 * V_988 ,
struct V_295 * V_296 )
{
if ( V_988 == NULL )
return true ;
if ( F_45 ( V_988 -> V_10 ) -> V_105 < 5 )
return false ;
if ( V_396 . F_668 < 0 )
return false ;
else if ( V_396 . F_668 > 0 )
return true ;
else if ( V_396 . V_1013 )
return true ;
else
return V_988 != F_669 ( V_296 -> V_1014 ) ;
}
static void F_670 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_279 * V_92 = V_28 -> V_8 . V_91 -> V_92 ;
struct V_777 * V_778 = F_204 ( V_92 ) ;
struct V_295 * V_296 = V_778 -> V_296 ;
const enum V_4 V_4 = V_28 -> V_4 ;
T_1 V_1015 , V_342 ;
V_1015 = F_5 ( F_86 ( V_4 , 0 ) ) ;
V_1015 &= ~ V_838 ;
if ( V_296 -> V_304 == V_341 )
V_1015 |= V_377 ;
V_342 = V_92 -> V_289 [ 0 ] >> 6 ;
if ( V_296 -> V_304 == V_341 )
V_342 = V_92 -> V_289 [ 0 ] >> 9 ;
F_120 ( F_86 ( V_4 , 0 ) , V_1015 ) ;
F_120 ( F_236 ( V_4 , 0 ) , V_342 ) ;
F_120 ( F_231 ( V_4 , 0 ) , V_28 -> V_394 -> V_985 ) ;
F_121 ( F_231 ( V_4 , 0 ) ) ;
}
static void F_671 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_777 * V_778 =
F_204 ( V_28 -> V_8 . V_91 -> V_92 ) ;
struct V_295 * V_296 = V_778 -> V_296 ;
T_1 V_352 ;
T_1 V_99 ;
V_99 = F_80 ( V_28 -> V_164 ) ;
V_352 = F_5 ( V_99 ) ;
if ( V_296 -> V_304 != V_306 )
V_352 |= V_362 ;
else
V_352 &= ~ V_362 ;
F_120 ( V_99 , V_352 ) ;
F_120 ( F_166 ( V_28 -> V_164 ) ,
V_28 -> V_394 -> V_985 ) ;
F_121 ( F_166 ( V_28 -> V_164 ) ) ;
}
static void F_672 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
bool V_1016 ;
T_1 V_1017 ;
F_651 ( V_28 ) ;
V_1016 = F_673 ( V_28 , & V_1017 ) ;
if ( F_45 ( V_10 ) -> V_105 >= 9 )
F_670 ( V_28 ) ;
else
F_671 ( V_28 ) ;
if ( V_1016 )
F_674 ( V_28 , V_1017 ) ;
}
static void F_675 ( struct V_978 * V_437 )
{
struct V_28 * V_29 =
F_638 ( V_437 , struct V_28 , V_1018 . V_437 ) ;
struct V_1019 * V_1018 ;
V_1018 = & V_29 -> V_1018 ;
if ( V_1018 -> V_1020 )
F_3 ( F_676 ( V_1018 -> V_1020 ,
V_29 -> V_392 ,
false , NULL , NULL ) != 0 ) ;
F_672 ( V_29 ) ;
if ( V_1018 -> V_1020 ) {
F_56 ( & V_29 -> V_8 . V_10 -> V_299 ) ;
F_639 ( & V_1018 -> V_1020 , NULL ) ;
F_58 ( & V_29 -> V_8 . V_10 -> V_299 ) ;
}
}
static int F_677 ( struct V_9 * V_10 ,
struct V_89 * V_29 ,
struct V_279 * V_92 ,
struct V_295 * V_296 ,
struct V_293 * V_988 ,
T_4 V_344 )
{
struct V_28 * V_28 = F_31 ( V_29 ) ;
F_639 ( & V_28 -> V_1018 . V_1020 ,
V_296 -> V_1021 ) ;
F_678 ( & V_28 -> V_1018 . V_437 ) ;
return 0 ;
}
static int F_679 ( struct V_9 * V_10 ,
struct V_89 * V_29 ,
struct V_279 * V_92 ,
struct V_295 * V_296 ,
struct V_293 * V_988 ,
T_4 V_344 )
{
return - V_1005 ;
}
static bool F_680 ( struct V_9 * V_10 ,
struct V_89 * V_29 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_436 * V_437 = V_28 -> V_394 ;
T_1 V_1022 ;
if ( F_260 ( & V_437 -> V_390 ) >= V_981 )
return true ;
if ( ! V_437 -> V_1023 )
return false ;
if ( V_437 -> V_1024 == 0 ) {
if ( V_437 -> V_980 &&
! F_681 ( V_437 -> V_980 , true ) )
return false ;
V_437 -> V_1024 = F_682 ( V_29 ) ;
}
if ( F_682 ( V_29 ) - V_437 -> V_1024 < 3 )
return false ;
if ( F_45 ( V_10 ) -> V_105 >= 4 )
V_1022 = F_683 ( F_5 ( F_166 ( V_28 -> V_164 ) ) ) ;
else
V_1022 = F_5 ( F_167 ( V_28 -> V_164 ) ) ;
return V_1022 == V_437 -> V_985 ;
}
void F_684 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_29 = V_12 -> V_97 [ V_4 ] ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
F_3 ( ! F_685 () ) ;
if ( V_29 == NULL )
return;
F_686 ( & V_10 -> V_393 ) ;
if ( V_28 -> V_394 && F_680 ( V_10 , V_29 ) ) {
F_177 ( 1 , L_152 ,
V_28 -> V_394 -> V_1025 ,
F_687 ( V_10 , V_4 ) ) ;
F_282 ( V_28 ) ;
}
F_688 ( & V_10 -> V_393 ) ;
}
static int F_689 ( struct V_89 * V_29 ,
struct V_279 * V_92 ,
struct V_1026 * V_438 ,
T_4 V_1027 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_279 * V_388 = V_29 -> V_91 -> V_92 ;
struct V_295 * V_296 = F_184 ( V_92 ) ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_261 * V_91 = V_29 -> V_91 ;
enum V_4 V_4 = V_28 -> V_4 ;
struct V_436 * V_437 ;
struct V_293 * V_988 ;
int V_298 ;
if ( F_3 ( F_184 ( V_388 ) == NULL ) )
return - V_1028 ;
if ( V_92 -> V_268 != V_29 -> V_91 -> V_92 -> V_268 )
return - V_292 ;
if ( F_45 ( V_10 ) -> V_105 > 3 &&
( V_92 -> V_1029 [ 0 ] != V_29 -> V_91 -> V_92 -> V_1029 [ 0 ] ||
V_92 -> V_289 [ 0 ] != V_29 -> V_91 -> V_92 -> V_289 [ 0 ] ) )
return - V_292 ;
if ( F_690 ( & V_12 -> V_391 ) )
goto V_1030;
V_437 = F_444 ( sizeof( * V_437 ) , V_487 ) ;
if ( V_437 == NULL )
return - V_489 ;
V_437 -> V_438 = V_438 ;
V_437 -> V_29 = V_29 ;
V_437 -> V_388 = V_388 ;
F_691 ( & V_437 -> V_437 , F_637 ) ;
V_298 = F_93 ( V_29 ) ;
if ( V_298 )
goto V_1031;
F_251 ( & V_10 -> V_393 ) ;
if ( V_28 -> V_394 ) {
if ( F_680 ( V_10 , V_29 ) ) {
F_141 ( L_153 ) ;
F_282 ( V_28 ) ;
} else {
F_141 ( L_154 ) ;
F_252 ( & V_10 -> V_393 ) ;
F_94 ( V_29 ) ;
F_210 ( V_437 ) ;
return - V_1028 ;
}
}
V_28 -> V_394 = V_437 ;
F_252 ( & V_10 -> V_393 ) ;
if ( F_260 ( & V_28 -> V_435 ) >= 2 )
F_692 ( V_12 -> V_440 ) ;
F_208 ( V_437 -> V_388 ) ;
F_693 ( & V_296 -> V_8 ) ;
V_29 -> V_91 -> V_92 = V_92 ;
F_206 ( V_29 -> V_91 ) ;
V_437 -> V_441 = V_296 ;
V_298 = F_601 ( V_10 ) ;
if ( V_298 )
goto V_488;
F_694 ( & V_28 -> V_435 ) ;
V_28 -> V_392 = F_260 ( & V_12 -> V_391 . V_392 ) ;
if ( F_45 ( V_10 ) -> V_105 >= 5 || F_18 ( V_10 ) )
V_437 -> V_986 = F_5 ( F_649 ( V_4 ) ) + 1 ;
if ( F_21 ( V_10 ) ) {
V_988 = & V_12 -> V_988 [ V_1032 ] ;
if ( V_296 -> V_304 != F_184 ( V_437 -> V_388 ) -> V_304 )
V_988 = NULL ;
} else if ( F_267 ( V_10 ) || F_225 ( V_10 ) ) {
V_988 = & V_12 -> V_988 [ V_1032 ] ;
} else if ( F_45 ( V_10 ) -> V_105 >= 7 ) {
V_988 = F_669 ( V_296 -> V_1014 ) ;
if ( V_988 == NULL || V_988 -> V_238 != V_1006 )
V_988 = & V_12 -> V_988 [ V_1032 ] ;
} else {
V_988 = & V_12 -> V_988 [ V_1006 ] ;
}
V_298 = F_183 ( V_29 -> V_91 , V_92 ,
V_29 -> V_91 -> V_34 , V_988 ) ;
if ( V_298 )
goto V_1033;
V_437 -> V_985 = F_228 ( F_232 ( V_91 ) , V_296 )
+ V_28 -> V_364 ;
if ( F_668 ( V_988 , V_296 ) ) {
V_298 = F_677 ( V_10 , V_29 , V_92 , V_296 , V_988 ,
V_1027 ) ;
if ( V_298 )
goto V_1034;
F_639 ( & V_437 -> V_980 ,
V_296 -> V_1021 ) ;
} else {
V_298 = V_12 -> V_263 . V_1035 ( V_10 , V_29 , V_92 , V_296 , V_988 ,
V_1027 ) ;
if ( V_298 )
goto V_1034;
F_639 ( & V_437 -> V_980 ,
F_695 ( V_988 ) ) ;
}
V_437 -> V_1025 = F_682 ( V_29 ) ;
V_437 -> V_1023 = true ;
F_696 ( F_184 ( V_437 -> V_388 ) , V_296 ,
F_213 ( V_4 ) ) ;
F_360 ( V_10 ) ;
F_697 ( V_10 , F_213 ( V_4 ) ) ;
F_58 ( & V_10 -> V_299 ) ;
F_698 ( V_28 -> V_164 , V_296 ) ;
return 0 ;
V_1034:
F_194 ( V_92 , V_29 -> V_91 -> V_34 ) ;
V_1033:
F_641 ( & V_28 -> V_435 ) ;
F_58 ( & V_10 -> V_299 ) ;
V_488:
V_29 -> V_91 -> V_92 = V_388 ;
F_206 ( V_29 -> V_91 ) ;
F_699 ( & V_296 -> V_8 ) ;
F_207 ( V_437 -> V_388 ) ;
F_251 ( & V_10 -> V_393 ) ;
V_28 -> V_394 = NULL ;
F_252 ( & V_10 -> V_393 ) ;
F_94 ( V_29 ) ;
V_1031:
F_210 ( V_437 ) ;
if ( V_298 == - V_1036 ) {
V_1030:
V_298 = F_337 ( V_91 ) ;
if ( V_298 == 0 && V_438 ) {
F_251 ( & V_10 -> V_393 ) ;
F_284 ( V_10 , V_4 , V_438 ) ;
F_252 ( & V_10 -> V_393 ) ;
}
}
return V_298 ;
}
static void F_700 ( struct V_9 * V_10 )
{
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_701 (dev, connector) {
V_3 -> V_947 =
F_13 ( V_3 -> V_8 . V_6 ) ;
}
F_531 (dev, encoder) {
V_6 -> V_946 =
F_31 ( V_6 -> V_8 . V_29 ) ;
}
F_131 (dev, crtc) {
V_29 -> V_578 = V_29 -> V_8 . V_34 -> V_240 ;
if ( V_29 -> V_578 )
V_29 -> V_484 = V_29 -> V_93 ;
else
V_29 -> V_484 = NULL ;
}
}
static void F_702 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
F_701 (dev, connector) {
if ( V_3 -> V_8 . V_6 ) {
V_3 -> V_8 . V_34 -> V_42 =
V_3 -> V_8 . V_6 ;
V_3 -> V_8 . V_34 -> V_29 =
V_3 -> V_8 . V_6 -> V_29 ;
} else {
V_3 -> V_8 . V_34 -> V_42 = NULL ;
V_3 -> V_8 . V_34 -> V_29 = NULL ;
}
}
}
static void F_703 ( struct V_9 * V_10 )
{
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_701 (dev, connector) {
V_3 -> V_8 . V_6 = & V_3 -> V_947 -> V_8 ;
}
F_531 (dev, encoder) {
V_6 -> V_8 . V_29 = & V_6 -> V_946 -> V_8 ;
}
F_131 (dev, crtc) {
V_29 -> V_8 . V_34 -> V_240 = V_29 -> V_578 ;
V_29 -> V_8 . V_120 = V_29 -> V_578 ;
}
F_702 ( V_10 ) ;
}
static void
F_704 ( struct V_2 * V_3 ,
struct V_31 * V_210 )
{
int V_829 = V_210 -> V_611 ;
F_144 ( L_155 ,
V_3 -> V_8 . V_8 . V_238 ,
V_3 -> V_8 . V_134 ) ;
if ( V_3 -> V_8 . V_1037 . V_472 &&
V_3 -> V_8 . V_1037 . V_472 * 3 < V_829 ) {
F_144 ( L_156 ,
V_829 , V_3 -> V_8 . V_1037 . V_472 * 3 ) ;
V_210 -> V_611 = V_3 -> V_8 . V_1037 . V_472 * 3 ;
}
if ( V_3 -> V_8 . V_1037 . V_472 == 0 && V_829 > 24 ) {
F_144 ( L_157 ,
V_829 ) ;
V_210 -> V_611 = 24 ;
}
}
static int
F_705 ( struct V_28 * V_29 ,
struct V_279 * V_92 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_33 * V_34 ;
struct V_2 * V_3 ;
int V_829 , V_37 ;
switch ( V_92 -> V_268 ) {
case V_312 :
V_829 = 8 * 3 ;
break;
case V_314 :
case V_359 :
if ( F_3 ( F_45 ( V_10 ) -> V_105 > 3 ) )
return - V_292 ;
case V_316 :
V_829 = 6 * 3 ;
break;
case V_320 :
case V_329 :
if ( F_3 ( F_45 ( V_10 ) -> V_105 < 4 ) )
return - V_292 ;
case V_318 :
case V_330 :
V_829 = 8 * 3 ;
break;
case V_322 :
case V_360 :
case V_324 :
case V_361 :
if ( F_3 ( F_45 ( V_10 ) -> V_105 < 4 ) )
return - V_292 ;
V_829 = 10 * 3 ;
break;
default:
F_144 ( L_158 ) ;
return - V_292 ;
}
V_210 -> V_611 = V_829 ;
V_34 = V_210 -> V_8 . V_34 ;
for ( V_37 = 0 ; V_37 < V_34 -> V_39 ; V_37 ++ ) {
if ( ! V_34 -> V_40 [ V_37 ] )
continue;
V_3 = F_612 ( V_34 -> V_40 [ V_37 ] ) ;
if ( V_34 -> V_41 [ V_37 ] -> V_29 != & V_29 -> V_8 )
continue;
F_704 ( V_3 , V_210 ) ;
}
return V_829 ;
}
static void F_706 ( const struct V_395 * V_477 )
{
F_144 ( L_159
L_160 ,
V_477 -> V_95 ,
V_477 -> V_398 , V_477 -> V_738 ,
V_477 -> V_741 , V_477 -> V_737 ,
V_477 -> V_399 , V_477 -> V_743 ,
V_477 -> V_744 , V_477 -> V_733 , V_477 -> type , V_477 -> V_344 ) ;
}
static void F_707 ( struct V_28 * V_29 ,
struct V_31 * V_210 ,
const char * V_1038 )
{
F_144 ( L_161 , V_29 -> V_8 . V_8 . V_238 ,
V_1038 , F_71 ( V_29 -> V_4 ) ) ;
F_144 ( L_162 , F_708 ( V_210 -> V_98 ) ) ;
F_144 ( L_163 ,
V_210 -> V_611 , V_210 -> V_752 ) ;
F_144 ( L_164 ,
V_210 -> V_258 ,
V_210 -> V_415 ,
V_210 -> V_517 . V_648 , V_210 -> V_517 . V_649 ,
V_210 -> V_517 . V_650 , V_210 -> V_517 . V_651 ,
V_210 -> V_517 . V_647 ) ;
F_144 ( L_165 ,
V_210 -> V_471 ,
V_210 -> V_666 . V_648 , V_210 -> V_666 . V_649 ,
V_210 -> V_666 . V_650 , V_210 -> V_666 . V_651 ,
V_210 -> V_666 . V_647 ) ;
F_144 ( L_166 ,
V_210 -> V_471 ,
V_210 -> V_667 . V_648 ,
V_210 -> V_667 . V_649 ,
V_210 -> V_667 . V_650 ,
V_210 -> V_667 . V_651 ,
V_210 -> V_667 . V_647 ) ;
F_144 ( L_167 ,
V_210 -> V_1039 ,
V_210 -> V_1040 ) ;
F_144 ( L_168 ) ;
F_709 ( & V_210 -> V_8 . V_477 ) ;
F_144 ( L_169 ) ;
F_709 ( & V_210 -> V_8 . V_94 ) ;
F_706 ( & V_210 -> V_8 . V_94 ) ;
F_144 ( L_170 , V_210 -> V_691 ) ;
F_144 ( L_171 ,
V_210 -> V_357 , V_210 -> V_356 ) ;
F_144 ( L_172 ,
V_210 -> V_526 . V_527 ,
V_210 -> V_526 . V_531 ,
V_210 -> V_526 . V_773 ) ;
F_144 ( L_173 ,
V_210 -> V_400 . V_492 ,
V_210 -> V_400 . V_339 ,
V_210 -> V_400 . V_120 ? L_174 : L_175 ) ;
F_144 ( L_176 , V_210 -> V_501 ) ;
F_144 ( L_177 , V_210 -> V_259 ) ;
}
static bool F_710 ( const struct V_1 * V_983 ,
const struct V_1 * V_984 )
{
return V_983 == V_984 || ( V_983 -> V_1041 & ( 1 << V_984 -> type ) &&
V_984 -> V_1041 & ( 1 << V_983 -> type ) ) ;
}
static bool F_711 ( struct V_28 * V_29 ,
struct V_1 * V_6 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_1042 ;
F_531 (dev, source_encoder) {
if ( V_1042 -> V_946 != V_29 )
continue;
if ( ! F_710 ( V_6 , V_1042 ) )
return false ;
}
return true ;
}
static bool F_712 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_6 ;
F_531 (dev, encoder) {
if ( V_6 -> V_946 != V_29 )
continue;
if ( ! F_711 ( V_29 , V_6 ) )
return false ;
}
return true ;
}
static bool F_713 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
unsigned int V_1043 = 0 ;
F_701 (dev, connector) {
struct V_1 * V_6 = V_3 -> V_947 ;
if ( ! V_6 )
continue;
F_3 ( ! V_6 -> V_946 ) ;
switch ( V_6 -> type ) {
unsigned int V_229 ;
case V_540 :
if ( F_3 ( ! F_62 ( V_10 ) ) )
break;
case V_541 :
case V_52 :
case V_401 :
V_229 = 1 << F_396 ( & V_6 -> V_8 ) -> V_108 ;
if ( V_1043 & V_229 )
return false ;
V_1043 |= V_229 ;
default:
break;
}
}
return true ;
}
static void
F_714 ( struct V_31 * V_32 )
{
struct V_1044 V_1045 ;
V_1045 = V_32 -> V_8 ;
memset ( V_32 , 0 , sizeof *V_32 ) ;
V_32 -> V_8 = V_1045 ;
}
static struct V_31 *
F_715 ( struct V_89 * V_29 ,
struct V_279 * V_92 ,
struct V_395 * V_477 ,
struct V_33 * V_34 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
struct V_35 * V_36 ;
struct V_31 * V_210 ;
int V_1046 , V_298 = - V_292 ;
int V_37 ;
bool V_420 = true ;
if ( ! F_712 ( F_31 ( V_29 ) ) ) {
F_144 ( L_178 ) ;
return F_599 ( - V_292 ) ;
}
if ( ! F_713 ( V_10 ) ) {
F_144 ( L_179 ) ;
return F_599 ( - V_292 ) ;
}
V_210 = F_716 ( V_34 , F_31 ( V_29 ) ) ;
if ( F_615 ( V_210 ) )
return V_210 ;
F_714 ( V_210 ) ;
V_210 -> V_8 . V_29 = V_29 ;
F_717 ( & V_210 -> V_8 . V_94 , V_477 ) ;
F_717 ( & V_210 -> V_8 . V_477 , V_477 ) ;
V_210 -> V_98 =
(enum V_96 ) F_31 ( V_29 ) -> V_4 ;
V_210 -> V_128 = V_482 ;
if ( ! ( V_210 -> V_8 . V_94 . V_344 &
( V_478 | V_1047 ) ) )
V_210 -> V_8 . V_94 . V_344 |= V_1047 ;
if ( ! ( V_210 -> V_8 . V_94 . V_344 &
( V_480 | V_1048 ) ) )
V_210 -> V_8 . V_94 . V_344 |= V_1048 ;
V_1046 = F_705 ( F_31 ( V_29 ) ,
V_92 , V_210 ) ;
if ( V_1046 < 0 )
goto V_950;
F_718 ( & V_210 -> V_8 . V_477 ,
& V_210 -> V_357 ,
& V_210 -> V_356 ) ;
V_1049:
V_210 -> V_691 = 0 ;
V_210 -> V_522 = 1 ;
F_719 ( & V_210 -> V_8 . V_94 ,
V_1050 ) ;
for ( V_37 = 0 ; V_37 < V_34 -> V_39 ; V_37 ++ ) {
V_3 = F_612 ( V_34 -> V_40 [ V_37 ] ) ;
if ( ! V_3 )
continue;
V_36 = V_34 -> V_41 [ V_37 ] ;
if ( V_36 -> V_29 != V_29 )
continue;
V_6 = F_13 ( V_36 -> V_42 ) ;
if ( ! ( V_6 -> V_1051 ( V_6 , V_210 ) ) ) {
F_144 ( L_180 ) ;
goto V_950;
}
}
if ( ! V_210 -> V_691 )
V_210 -> V_691 = V_210 -> V_8 . V_94 . V_95
* V_210 -> V_522 ;
V_298 = F_458 ( F_31 ( V_29 ) , V_210 ) ;
if ( V_298 < 0 ) {
F_144 ( L_181 ) ;
goto V_950;
}
if ( V_298 == V_613 ) {
if ( F_48 ( ! V_420 , L_182 ) ) {
V_298 = - V_292 ;
goto V_950;
}
F_144 ( L_183 ) ;
V_420 = false ;
goto V_1049;
}
V_210 -> V_752 = V_210 -> V_611 != V_1046 ;
F_144 ( L_184 ,
V_1046 , V_210 -> V_611 , V_210 -> V_752 ) ;
return V_210 ;
V_950:
return F_599 ( V_298 ) ;
}
static void
F_720 ( struct V_89 * V_29 , unsigned * V_1052 ,
unsigned * V_579 , unsigned * V_1053 )
{
struct V_28 * V_28 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
struct V_89 * V_1054 ;
* V_1053 = * V_1052 = * V_579 = 0 ;
F_701 (dev, connector) {
if ( V_3 -> V_8 . V_6 == & V_3 -> V_947 -> V_8 )
continue;
if ( V_3 -> V_8 . V_6 ) {
V_1054 = V_3 -> V_8 . V_6 -> V_29 ;
* V_579 |= 1 << F_31 ( V_1054 ) -> V_4 ;
}
if ( V_3 -> V_947 )
* V_579 |=
1 << V_3 -> V_947 -> V_946 -> V_4 ;
}
F_531 (dev, encoder) {
if ( V_6 -> V_8 . V_29 == & V_6 -> V_946 -> V_8 )
continue;
if ( V_6 -> V_8 . V_29 ) {
V_1054 = V_6 -> V_8 . V_29 ;
* V_579 |= 1 << F_31 ( V_1054 ) -> V_4 ;
}
if ( V_6 -> V_946 )
* V_579 |= 1 << V_6 -> V_946 -> V_4 ;
}
F_131 (dev, intel_crtc) {
if ( V_28 -> V_8 . V_34 -> V_240 == V_28 -> V_578 )
continue;
if ( ! V_28 -> V_578 )
* V_1053 |= 1 << V_28 -> V_4 ;
else
* V_579 |= 1 << V_28 -> V_4 ;
}
V_28 = F_31 ( V_29 ) ;
if ( V_28 -> V_578 )
* V_579 |= 1 << V_28 -> V_4 ;
if ( * V_579 )
* V_1052 = * V_579 ;
* V_1052 &= ~ ( * V_1053 ) ;
* V_579 &= ~ ( * V_1053 ) ;
* V_1052 &= 1 << V_28 -> V_4 ;
* V_579 &= 1 << V_28 -> V_4 ;
F_144 ( L_185 ,
* V_1052 , * V_579 , * V_1053 ) ;
}
static bool F_721 ( struct V_89 * V_29 )
{
struct V_602 * V_6 ;
struct V_9 * V_10 = V_29 -> V_10 ;
F_438 (encoder, &dev->mode_config.encoder_list, head)
if ( V_6 -> V_29 == V_29 )
return true ;
return false ;
}
static void
F_722 ( struct V_9 * V_10 , unsigned V_579 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 ;
struct V_28 * V_28 ;
struct V_597 * V_3 ;
F_326 ( V_12 ) ;
F_531 (dev, intel_encoder) {
if ( ! V_1 -> V_8 . V_29 )
continue;
V_28 = F_31 ( V_1 -> V_8 . V_29 ) ;
if ( V_579 & ( 1 << V_28 -> V_4 ) )
V_1 -> V_596 = false ;
}
F_703 ( V_10 ) ;
F_131 (dev, intel_crtc) {
F_3 ( V_28 -> V_8 . V_34 -> V_240 != F_721 ( & V_28 -> V_8 ) ) ;
F_3 ( V_28 -> V_484 &&
V_28 -> V_484 != V_28 -> V_93 ) ;
F_3 ( V_28 -> V_8 . V_34 -> V_240 != ! ! V_28 -> V_484 ) ;
}
F_438 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_3 -> V_6 || ! V_3 -> V_6 -> V_29 )
continue;
V_28 = F_31 ( V_3 -> V_6 -> V_29 ) ;
if ( V_579 & ( 1 << V_28 -> V_4 ) ) {
struct V_1055 * V_1056 =
V_10 -> V_940 . V_1056 ;
V_3 -> V_600 = V_603 ;
F_723 ( & V_3 -> V_8 ,
V_1056 ,
V_603 ) ;
V_1 = F_13 ( V_3 -> V_6 ) ;
V_1 -> V_596 = true ;
}
}
}
static bool F_724 ( int V_1057 , int V_1058 )
{
int V_1059 ;
if ( V_1057 == V_1058 )
return true ;
if ( ! V_1057 || ! V_1058 )
return false ;
V_1059 = abs ( V_1057 - V_1058 ) ;
if ( ( ( ( ( V_1059 + V_1057 + V_1058 ) * 100 ) ) / ( V_1057 + V_1058 ) ) < 105 )
return true ;
return false ;
}
static bool
F_725 ( struct V_9 * V_10 ,
struct V_31 * V_1060 ,
struct V_31 * V_210 )
{
#define F_726 ( V_134 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_727 ( V_134 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_728 ( V_134 , T_7 ) \
if ((current_config->name != pipe_config->name) && \
(current_config->alt_name != pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i or %i, found %i)\n", \
current_config->name, \
current_config->alt_name, \
pipe_config->name); \
return false; \
}
#define F_729 ( V_134 , V_545 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
DRM_ERROR("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
return false; \
}
#define F_730 ( V_134 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_731 ( T_8 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_727 ( V_98 ) ;
F_727 ( V_258 ) ;
F_727 ( V_415 ) ;
F_727 ( V_517 . V_648 ) ;
F_727 ( V_517 . V_649 ) ;
F_727 ( V_517 . V_650 ) ;
F_727 ( V_517 . V_651 ) ;
F_727 ( V_517 . V_647 ) ;
F_727 ( V_471 ) ;
if ( F_45 ( V_10 ) -> V_105 < 8 ) {
F_727 ( V_666 . V_648 ) ;
F_727 ( V_666 . V_649 ) ;
F_727 ( V_666 . V_650 ) ;
F_727 ( V_666 . V_651 ) ;
F_727 ( V_666 . V_647 ) ;
if ( V_1060 -> V_664 ) {
F_727 ( V_667 . V_648 ) ;
F_727 ( V_667 . V_649 ) ;
F_727 ( V_667 . V_650 ) ;
F_727 ( V_667 . V_651 ) ;
F_727 ( V_667 . V_647 ) ;
}
} else {
F_728 ( V_666 . V_648 , V_667 . V_648 ) ;
F_728 ( V_666 . V_649 , V_667 . V_649 ) ;
F_728 ( V_666 . V_650 , V_667 . V_650 ) ;
F_728 ( V_666 . V_651 , V_667 . V_651 ) ;
F_728 ( V_666 . V_647 , V_667 . V_647 ) ;
}
F_727 ( V_8 . V_94 . V_398 ) ;
F_727 ( V_8 . V_94 . V_737 ) ;
F_727 ( V_8 . V_94 . V_739 ) ;
F_727 ( V_8 . V_94 . V_740 ) ;
F_727 ( V_8 . V_94 . V_738 ) ;
F_727 ( V_8 . V_94 . V_741 ) ;
F_727 ( V_8 . V_94 . V_399 ) ;
F_727 ( V_8 . V_94 . V_733 ) ;
F_727 ( V_8 . V_94 . V_742 ) ;
F_727 ( V_8 . V_94 . V_734 ) ;
F_727 ( V_8 . V_94 . V_743 ) ;
F_727 ( V_8 . V_94 . V_744 ) ;
F_727 ( V_522 ) ;
F_727 ( V_1061 ) ;
if ( ( F_45 ( V_10 ) -> V_105 < 8 && ! F_225 ( V_10 ) ) ||
F_21 ( V_10 ) )
F_727 ( V_762 ) ;
F_727 ( V_1040 ) ;
F_727 ( V_1039 ) ;
F_729 ( V_8 . V_94 . V_344 ,
V_736 ) ;
if ( ! F_731 ( V_1062 ) ) {
F_729 ( V_8 . V_94 . V_344 ,
V_478 ) ;
F_729 ( V_8 . V_94 . V_344 ,
V_1047 ) ;
F_729 ( V_8 . V_94 . V_344 ,
V_480 ) ;
F_729 ( V_8 . V_94 . V_344 ,
V_1048 ) ;
}
F_727 ( V_357 ) ;
F_727 ( V_356 ) ;
if ( ! F_731 ( V_1063 ) ) {
F_727 ( V_526 . V_527 ) ;
if ( F_45 ( V_10 ) -> V_105 < 4 )
F_727 ( V_526 . V_531 ) ;
F_727 ( V_526 . V_773 ) ;
}
F_727 ( V_400 . V_120 ) ;
if ( V_1060 -> V_400 . V_120 ) {
F_727 ( V_400 . V_492 ) ;
F_727 ( V_400 . V_339 ) ;
}
if ( F_225 ( V_10 ) )
F_727 ( V_501 ) ;
F_727 ( V_259 ) ;
F_726 ( V_880 ) ;
F_727 ( V_128 ) ;
F_726 ( V_211 . V_67 ) ;
F_726 ( V_211 . V_213 ) ;
F_726 ( V_211 . V_592 ) ;
F_726 ( V_211 . V_593 ) ;
F_726 ( V_211 . V_1064 ) ;
F_726 ( V_211 . V_883 ) ;
F_726 ( V_211 . V_1065 ) ;
F_726 ( V_211 . V_1066 ) ;
if ( F_18 ( V_10 ) || F_45 ( V_10 ) -> V_105 >= 5 )
F_727 ( V_611 ) ;
F_730 ( V_8 . V_94 . V_95 ) ;
F_730 ( V_691 ) ;
#undef F_726
#undef F_727
#undef F_728
#undef F_729
#undef F_730
#undef F_731
return true ;
}
static void F_732 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1067 V_1068 , * V_1069 ;
struct V_28 * V_28 ;
int V_164 ;
if ( F_45 ( V_10 ) -> V_105 < 9 )
return;
F_733 ( V_12 , & V_1068 ) ;
V_1069 = & V_12 -> V_1070 . V_1071 . V_1072 ;
F_131 (dev, intel_crtc) {
struct V_1073 * V_1074 , * V_1075 ;
const enum V_4 V_4 = V_28 -> V_4 ;
if ( ! V_28 -> V_90 )
continue;
F_734 (dev_priv, pipe, plane) {
V_1074 = & V_1068 . V_164 [ V_4 ] [ V_164 ] ;
V_1075 = & V_1069 -> V_164 [ V_4 ] [ V_164 ] ;
if ( F_735 ( V_1074 , V_1075 ) )
continue;
F_123 ( L_186
L_187 ,
F_71 ( V_4 ) , V_164 + 1 ,
V_1075 -> V_930 , V_1075 -> V_931 ,
V_1074 -> V_930 , V_1074 -> V_931 ) ;
}
V_1074 = & V_1068 . V_905 [ V_4 ] ;
V_1075 = & V_1069 -> V_905 [ V_4 ] ;
if ( F_735 ( V_1074 , V_1075 ) )
continue;
F_123 ( L_188
L_187 ,
F_71 ( V_4 ) ,
V_1075 -> V_930 , V_1075 -> V_931 ,
V_1074 -> V_930 , V_1074 -> V_931 ) ;
}
}
static void
F_736 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
F_701 (dev, connector) {
F_442 ( V_3 ) ;
F_54 ( & V_3 -> V_947 -> V_8 != V_3 -> V_8 . V_6 ,
L_189 ) ;
}
}
static void
F_737 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_531 (dev, encoder) {
bool V_120 = false ;
bool V_90 = false ;
enum V_4 V_4 , V_1076 ;
F_144 ( L_190 ,
V_6 -> V_8 . V_8 . V_238 ,
V_6 -> V_8 . V_134 ) ;
F_54 ( & V_6 -> V_946 -> V_8 != V_6 -> V_8 . V_29 ,
L_191 ) ;
F_54 ( V_6 -> V_596 && ! V_6 -> V_8 . V_29 ,
L_192 ) ;
F_701 (dev, connector) {
if ( V_3 -> V_8 . V_6 != & V_6 -> V_8 )
continue;
V_120 = true ;
if ( V_3 -> V_8 . V_600 != V_601 )
V_90 = true ;
}
if ( ! V_120 && V_6 -> V_8 . V_1077 == V_1078 )
continue;
F_54 ( ! ! V_6 -> V_8 . V_29 != V_120 ,
L_193
L_194 ,
! ! V_6 -> V_8 . V_29 , V_120 ) ;
F_54 ( V_90 && ! V_6 -> V_8 . V_29 ,
L_195 ) ;
F_54 ( V_6 -> V_596 != V_90 ,
L_196
L_194 , V_90 , V_6 -> V_596 ) ;
V_90 = V_6 -> V_133 ( V_6 , & V_4 ) ;
F_54 ( V_90 != V_6 -> V_596 ,
L_197
L_194 ,
V_6 -> V_596 , V_90 ) ;
if ( ! V_6 -> V_8 . V_29 )
continue;
V_1076 = F_31 ( V_6 -> V_8 . V_29 ) -> V_4 ;
F_54 ( V_90 && V_4 != V_1076 ,
L_198
L_194 ,
V_1076 , V_4 ) ;
}
}
static void
F_738 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_31 V_210 ;
F_131 (dev, crtc) {
bool V_120 = false ;
bool V_90 = false ;
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
F_144 ( L_199 ,
V_29 -> V_8 . V_8 . V_238 ) ;
F_54 ( V_29 -> V_90 && ! V_29 -> V_8 . V_34 -> V_240 ,
L_200 ) ;
F_531 (dev, encoder) {
if ( V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
V_120 = true ;
if ( V_6 -> V_596 )
V_90 = true ;
}
F_54 ( V_90 != V_29 -> V_90 ,
L_201
L_194 , V_90 , V_29 -> V_90 ) ;
F_54 ( V_120 != V_29 -> V_8 . V_34 -> V_240 ,
L_202
L_194 , V_120 ,
V_29 -> V_8 . V_34 -> V_240 ) ;
V_90 = V_12 -> V_263 . V_1079 ( V_29 ,
& V_210 ) ;
if ( ( V_29 -> V_4 == V_142 && V_12 -> V_160 & V_161 ) ||
( V_29 -> V_4 == V_151 && V_12 -> V_160 & V_162 ) )
V_90 = V_29 -> V_90 ;
F_531 (dev, encoder) {
enum V_4 V_4 ;
if ( V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
if ( V_6 -> V_133 ( V_6 , & V_4 ) )
V_6 -> V_1080 ( V_6 , & V_210 ) ;
}
F_54 ( V_29 -> V_90 != V_90 ,
L_203
L_194 , V_29 -> V_90 , V_90 ) ;
if ( V_90 &&
! F_725 ( V_10 , V_29 -> V_93 , & V_210 ) ) {
F_54 ( 1 , L_204 ) ;
F_707 ( V_29 , & V_210 ,
L_205 ) ;
F_707 ( V_29 , V_29 -> V_93 ,
L_206 ) ;
}
}
}
static void
F_739 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 ;
struct V_131 V_211 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_12 -> V_485 ; V_37 ++ ) {
struct V_127 * V_130 = & V_12 -> V_129 [ V_37 ] ;
int V_1081 = 0 , V_1082 = 0 ;
bool V_90 ;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
F_144 ( L_207 , V_130 -> V_134 ) ;
V_90 = V_130 -> V_133 ( V_12 , V_130 , & V_211 ) ;
F_54 ( V_130 -> V_90 > F_740 ( V_130 -> V_93 . V_235 ) ,
L_208 ,
V_130 -> V_90 , F_740 ( V_130 -> V_93 . V_235 ) ) ;
F_54 ( V_130 -> V_90 && ! V_130 -> V_236 ,
L_209 ) ;
F_54 ( V_130 -> V_236 && ! V_130 -> V_90 ,
L_210 ) ;
F_54 ( V_130 -> V_236 != V_90 ,
L_211 ,
V_130 -> V_236 , V_90 ) ;
F_131 (dev, crtc) {
if ( V_29 -> V_8 . V_34 -> V_240 && F_59 ( V_29 ) == V_130 )
V_1081 ++ ;
if ( V_29 -> V_90 && F_59 ( V_29 ) == V_130 )
V_1082 ++ ;
}
F_54 ( V_130 -> V_90 != V_1082 ,
L_212 ,
V_130 -> V_90 , V_1082 ) ;
F_54 ( F_740 ( V_130 -> V_93 . V_235 ) != V_1081 ,
L_213 ,
F_740 ( V_130 -> V_93 . V_235 ) , V_1081 ) ;
F_54 ( V_130 -> V_236 && memcmp ( & V_130 -> V_93 . V_132 , & V_211 ,
sizeof( V_211 ) ) ,
L_214 ) ;
}
}
void
F_447 ( struct V_9 * V_10 )
{
F_732 ( V_10 ) ;
F_736 ( V_10 ) ;
F_737 ( V_10 ) ;
F_738 ( V_10 ) ;
F_739 ( V_10 ) ;
}
void F_741 ( const struct V_31 * V_210 ,
int V_1083 )
{
F_48 ( ! F_724 ( V_210 -> V_8 . V_94 . V_95 , V_1083 ) ,
L_215 ,
V_210 -> V_8 . V_94 . V_95 , V_1083 ) ;
}
static void F_742 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
if ( F_22 ( V_10 ) ) {
const struct V_395 * V_477 = & V_29 -> V_93 -> V_8 . V_94 ;
int V_748 ;
V_748 = V_477 -> V_733 ;
if ( V_477 -> V_344 & V_736 )
V_748 /= 2 ;
V_29 -> V_1084 = V_748 - 1 ;
} else if ( F_62 ( V_10 ) &&
F_10 ( V_29 , V_52 ) ) {
V_29 -> V_1084 = 2 ;
} else
V_29 -> V_1084 = 1 ;
}
static struct V_31 *
F_743 ( struct V_89 * V_29 ,
struct V_395 * V_477 ,
struct V_279 * V_92 ,
struct V_33 * V_34 ,
unsigned * V_1052 ,
unsigned * V_579 ,
unsigned * V_1053 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_31 * V_210 = NULL ;
struct V_28 * V_28 ;
int V_298 = 0 ;
V_298 = F_744 ( V_34 , V_29 ) ;
if ( V_298 )
return F_599 ( V_298 ) ;
F_720 ( V_29 , V_1052 ,
V_579 , V_1053 ) ;
F_745 (dev, *disable_pipes, intel_crtc) {
V_210 = F_716 ( V_34 , V_28 ) ;
if ( F_615 ( V_210 ) )
return V_210 ;
V_210 -> V_8 . V_240 = false ;
}
F_745 (dev, *modeset_pipes, intel_crtc) {
if ( F_3 ( & V_28 -> V_8 != V_29 ) )
continue;
V_210 = F_715 ( V_29 , V_92 , V_477 , V_34 ) ;
if ( F_615 ( V_210 ) )
return V_210 ;
F_707 ( F_31 ( V_29 ) , V_210 ,
L_216 ) ;
}
return F_716 ( V_34 , F_31 ( V_29 ) ) ; ;
}
static int F_746 ( struct V_9 * V_10 ,
unsigned V_1052 ,
unsigned V_1053 )
{
struct V_11 * V_12 = F_245 ( V_10 ) ;
unsigned V_486 = V_1052 | V_1053 ;
struct V_28 * V_28 ;
int V_298 = 0 ;
if ( ! V_12 -> V_263 . V_1085 )
return 0 ;
V_298 = F_324 ( V_12 , V_486 ) ;
if ( V_298 )
goto V_1086;
F_745 (dev, modeset_pipes, intel_crtc) {
struct V_31 * V_34 = V_28 -> V_484 ;
V_298 = V_12 -> V_263 . V_1085 ( V_28 ,
V_34 ) ;
if ( V_298 ) {
F_327 ( V_12 ) ;
goto V_1086;
}
}
V_1086:
return V_298 ;
}
static int F_747 ( struct V_89 * V_29 ,
struct V_395 * V_477 ,
int V_265 , int V_266 , struct V_279 * V_92 ,
struct V_31 * V_210 ,
unsigned V_1052 ,
unsigned V_579 ,
unsigned V_1053 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_395 * V_1087 ;
struct V_31 * V_1088 = NULL ;
struct V_28 * V_28 ;
int V_298 = 0 ;
V_1087 = F_748 ( sizeof( * V_1087 ) , V_487 ) ;
if ( ! V_1087 )
return - V_489 ;
V_1088 = F_748 ( sizeof( * V_1088 ) , V_487 ) ;
if ( ! V_1088 ) {
V_298 = - V_489 ;
goto V_1086;
}
* V_1087 = V_29 -> V_477 ;
if ( V_1052 )
F_31 ( V_29 ) -> V_484 = V_210 ;
if ( F_21 ( V_10 ) ) {
F_416 ( V_10 , & V_579 ) ;
V_579 &= ~ V_1053 ;
}
V_298 = F_746 ( V_10 , V_1052 , V_1053 ) ;
if ( V_298 )
goto V_1086;
F_745 (dev, disable_pipes, intel_crtc)
F_437 ( & V_28 -> V_8 ) ;
F_745 (dev, prepare_pipes, intel_crtc) {
if ( V_28 -> V_8 . V_34 -> V_240 )
V_12 -> V_263 . V_385 ( & V_28 -> V_8 ) ;
}
if ( V_1052 ) {
V_29 -> V_477 = * V_477 ;
F_633 ( F_31 ( V_29 ) , V_210 ) ;
F_749 ( V_29 ,
& V_210 -> V_8 . V_94 ) ;
}
F_722 ( V_10 , V_579 ) ;
F_401 ( V_210 -> V_8 . V_34 ) ;
F_745 (dev, modeset_pipes, intel_crtc) {
struct V_261 * V_91 = V_28 -> V_8 . V_91 ;
int V_745 , V_617 ;
F_718 ( V_477 , & V_617 , & V_745 ) ;
V_298 = V_91 -> V_495 -> V_1089 ( V_91 , & V_28 -> V_8 ,
V_92 , 0 , 0 ,
V_617 , V_745 ,
V_265 << 16 , V_266 << 16 ,
V_617 << 16 , V_745 << 16 ) ;
}
F_745 (dev, prepare_pipes, intel_crtc) {
F_742 ( V_28 ) ;
V_12 -> V_263 . V_595 ( & V_28 -> V_8 ) ;
}
V_1086:
if ( V_298 && V_29 -> V_34 -> V_240 )
V_29 -> V_477 = * V_1087 ;
if ( V_298 == 0 && V_210 ) {
struct V_28 * V_28 = F_31 ( V_29 ) ;
memcpy ( V_1088 , V_28 -> V_93 ,
sizeof *V_1088 ) ;
V_28 -> V_93 = V_1088 ;
V_28 -> V_8 . V_34 = & V_1088 -> V_8 ;
if ( V_1052 )
V_28 -> V_484 = V_28 -> V_93 ;
} else {
F_210 ( V_1088 ) ;
}
F_210 ( V_1087 ) ;
return V_298 ;
}
static int F_750 ( struct V_89 * V_29 ,
struct V_395 * V_477 ,
int V_265 , int V_266 , struct V_279 * V_92 ,
struct V_31 * V_210 ,
unsigned V_1052 ,
unsigned V_579 ,
unsigned V_1053 )
{
int V_298 ;
V_298 = F_747 ( V_29 , V_477 , V_265 , V_266 , V_92 , V_210 , V_1052 ,
V_579 , V_1053 ) ;
if ( V_298 == 0 )
F_447 ( V_29 -> V_10 ) ;
return V_298 ;
}
static int F_617 ( struct V_89 * V_29 ,
struct V_395 * V_477 ,
int V_265 , int V_266 , struct V_279 * V_92 ,
struct V_33 * V_34 )
{
struct V_31 * V_210 ;
unsigned V_1052 , V_579 , V_1053 ;
int V_298 = 0 ;
V_210 = F_743 ( V_29 , V_477 , V_92 , V_34 ,
& V_1052 ,
& V_579 ,
& V_1053 ) ;
if ( F_615 ( V_210 ) ) {
V_298 = F_616 ( V_210 ) ;
goto V_1090;
}
V_298 = F_750 ( V_29 , V_477 , V_265 , V_266 , V_92 , V_210 ,
V_1052 , V_579 ,
V_1053 ) ;
if ( V_298 )
goto V_1090;
V_1090:
return V_298 ;
}
void F_751 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_33 * V_34 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
struct V_35 * V_36 ;
V_34 = F_613 ( V_10 ) ;
if ( ! V_34 ) {
F_144 ( L_217 ,
V_29 -> V_8 . V_238 ) ;
return;
}
V_34 -> V_949 = V_10 -> V_940 . V_949 ;
F_531 (dev, encoder) {
if ( & V_6 -> V_946 -> V_8 != V_29 )
continue;
F_701 (dev, connector) {
if ( V_3 -> V_947 != V_6 )
continue;
V_36 = F_614 ( V_34 , & V_3 -> V_8 ) ;
if ( F_615 ( V_36 ) ) {
F_144 ( L_218 ,
V_3 -> V_8 . V_8 . V_238 ,
V_3 -> V_8 . V_134 ,
F_616 ( V_36 ) ) ;
continue;
}
V_36 -> V_29 = V_29 ;
V_36 -> V_42 = & V_6 -> V_8 ;
}
}
F_617 ( V_29 , & V_29 -> V_477 , V_29 -> V_265 , V_29 -> V_266 , V_29 -> V_91 -> V_92 ,
V_34 ) ;
F_618 ( V_34 ) ;
}
static void F_752 ( struct V_1091 * V_93 )
{
if ( ! V_93 )
return;
F_210 ( V_93 -> V_1092 ) ;
F_210 ( V_93 -> V_1093 ) ;
F_210 ( V_93 -> V_1094 ) ;
F_210 ( V_93 ) ;
}
static int F_753 ( struct V_9 * V_10 ,
struct V_1091 * V_93 )
{
struct V_89 * V_29 ;
struct V_602 * V_6 ;
struct V_597 * V_3 ;
int V_217 ;
V_93 -> V_1094 =
F_754 ( V_10 -> V_940 . V_1095 ,
sizeof( bool ) , V_487 ) ;
if ( ! V_93 -> V_1094 )
return - V_489 ;
V_93 -> V_1093 =
F_754 ( V_10 -> V_940 . V_1096 ,
sizeof( struct V_89 * ) , V_487 ) ;
if ( ! V_93 -> V_1093 )
return - V_489 ;
V_93 -> V_1092 =
F_754 ( V_10 -> V_940 . V_39 ,
sizeof( struct V_602 * ) , V_487 ) ;
if ( ! V_93 -> V_1092 )
return - V_489 ;
V_217 = 0 ;
F_211 (dev, crtc) {
V_93 -> V_1094 [ V_217 ++ ] = V_29 -> V_34 -> V_240 ;
}
V_217 = 0 ;
F_438 (encoder, &dev->mode_config.encoder_list, head) {
V_93 -> V_1093 [ V_217 ++ ] = V_6 -> V_29 ;
}
V_217 = 0 ;
F_438 (connector, &dev->mode_config.connector_list, head) {
V_93 -> V_1092 [ V_217 ++ ] = V_3 -> V_6 ;
}
return 0 ;
}
static void F_755 ( struct V_9 * V_10 ,
struct V_1091 * V_93 )
{
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
int V_217 ;
V_217 = 0 ;
F_131 (dev, crtc) {
V_29 -> V_578 = V_93 -> V_1094 [ V_217 ++ ] ;
if ( V_29 -> V_578 )
V_29 -> V_484 = V_29 -> V_93 ;
else
V_29 -> V_484 = NULL ;
}
V_217 = 0 ;
F_531 (dev, encoder) {
V_6 -> V_946 =
F_31 ( V_93 -> V_1093 [ V_217 ++ ] ) ;
}
V_217 = 0 ;
F_701 (dev, connector) {
V_3 -> V_947 =
F_13 ( V_93 -> V_1092 [ V_217 ++ ] ) ;
}
}
static bool
F_756 ( struct V_1097 * V_1098 )
{
int V_37 ;
if ( V_1098 -> V_38 == 0 )
return false ;
if ( F_3 ( V_1098 -> V_40 == NULL ) )
return false ;
for ( V_37 = 0 ; V_37 < V_1098 -> V_38 ; V_37 ++ )
if ( V_1098 -> V_40 [ V_37 ] -> V_6 &&
V_1098 -> V_40 [ V_37 ] -> V_6 -> V_29 == V_1098 -> V_29 &&
V_1098 -> V_40 [ V_37 ] -> V_600 != V_603 )
return true ;
return false ;
}
static void
F_757 ( struct V_1097 * V_1098 ,
struct V_1091 * V_93 )
{
if ( F_756 ( V_1098 ) ) {
V_93 -> V_1099 = true ;
} else if ( V_1098 -> V_29 -> V_91 -> V_92 != V_1098 -> V_92 ) {
if ( V_1098 -> V_29 -> V_91 -> V_92 == NULL ) {
struct V_28 * V_28 =
F_31 ( V_1098 -> V_29 ) ;
if ( V_28 -> V_90 ) {
F_144 ( L_219 ) ;
V_93 -> V_1100 = true ;
} else {
F_144 ( L_220 ) ;
V_93 -> V_1099 = true ;
}
} else if ( V_1098 -> V_92 == NULL ) {
V_93 -> V_1099 = true ;
} else if ( V_1098 -> V_92 -> V_268 !=
V_1098 -> V_29 -> V_91 -> V_92 -> V_268 ) {
V_93 -> V_1099 = true ;
} else {
V_93 -> V_1100 = true ;
}
}
if ( V_1098 -> V_92 && ( V_1098 -> V_265 != V_1098 -> V_29 -> V_265 || V_1098 -> V_266 != V_1098 -> V_29 -> V_266 ) )
V_93 -> V_1100 = true ;
if ( V_1098 -> V_477 && ! F_758 ( V_1098 -> V_477 , & V_1098 -> V_29 -> V_477 ) ) {
F_144 ( L_221 ) ;
F_709 ( & V_1098 -> V_29 -> V_477 ) ;
F_709 ( V_1098 -> V_477 ) ;
V_93 -> V_1099 = true ;
}
F_144 ( L_222 ,
V_1098 -> V_29 -> V_8 . V_238 , V_93 -> V_1099 , V_93 -> V_1100 ) ;
}
static int
F_759 ( struct V_9 * V_10 ,
struct V_1097 * V_1098 ,
struct V_1091 * V_93 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 ;
struct V_35 * V_36 ;
struct V_1 * V_6 ;
struct V_28 * V_29 ;
int V_1101 ;
F_3 ( ! V_1098 -> V_92 && ( V_1098 -> V_38 != 0 ) ) ;
F_3 ( V_1098 -> V_92 && ( V_1098 -> V_38 == 0 ) ) ;
F_701 (dev, connector) {
for ( V_1101 = 0 ; V_1101 < V_1098 -> V_38 ; V_1101 ++ ) {
if ( V_1098 -> V_40 [ V_1101 ] == & V_3 -> V_8 ) {
V_3 -> V_947 = F_1 ( V_3 , F_31 ( V_1098 -> V_29 ) -> V_4 ) ;
break;
}
}
if ( ( ! V_1098 -> V_92 || V_1101 == V_1098 -> V_38 ) &&
V_3 -> V_8 . V_6 &&
V_3 -> V_8 . V_6 -> V_29 == V_1098 -> V_29 ) {
V_3 -> V_947 = NULL ;
F_144 ( L_223 ,
V_3 -> V_8 . V_8 . V_238 ,
V_3 -> V_8 . V_134 ) ;
}
if ( & V_3 -> V_947 -> V_8 != V_3 -> V_8 . V_6 ) {
F_144 ( L_224 ,
V_3 -> V_8 . V_8 . V_238 ,
V_3 -> V_8 . V_134 ) ;
V_93 -> V_1099 = true ;
}
}
F_701 (dev, connector) {
struct V_89 * V_946 ;
if ( ! V_3 -> V_947 )
continue;
V_946 = V_3 -> V_947 -> V_8 . V_29 ;
for ( V_1101 = 0 ; V_1101 < V_1098 -> V_38 ; V_1101 ++ ) {
if ( V_1098 -> V_40 [ V_1101 ] == & V_3 -> V_8 )
V_946 = V_1098 -> V_29 ;
}
if ( ! F_760 ( & V_3 -> V_947 -> V_8 ,
V_946 ) ) {
return - V_292 ;
}
V_3 -> V_947 -> V_946 = F_31 ( V_946 ) ;
V_36 =
F_614 ( V_34 , & V_3 -> V_8 ) ;
if ( F_615 ( V_36 ) )
return F_616 ( V_36 ) ;
V_36 -> V_29 = V_946 ;
V_36 -> V_42 = & V_3 -> V_947 -> V_8 ;
F_144 ( L_225 ,
V_3 -> V_8 . V_8 . V_238 ,
V_3 -> V_8 . V_134 ,
V_946 -> V_8 . V_238 ) ;
}
F_531 (dev, encoder) {
int V_38 = 0 ;
F_701 (dev, connector) {
if ( V_3 -> V_947 == V_6 ) {
F_3 ( ! V_3 -> V_947 -> V_946 ) ;
V_38 ++ ;
}
}
if ( V_38 == 0 )
V_6 -> V_946 = NULL ;
else if ( V_38 > 1 )
return - V_292 ;
if ( & V_6 -> V_946 -> V_8 != V_6 -> V_8 . V_29 ) {
F_144 ( L_226 ,
V_6 -> V_8 . V_8 . V_238 ,
V_6 -> V_8 . V_134 ) ;
V_93 -> V_1099 = true ;
}
}
F_701 (dev, connector) {
V_36 =
F_614 ( V_34 , & V_3 -> V_8 ) ;
if ( F_615 ( V_36 ) )
return F_616 ( V_36 ) ;
if ( V_3 -> V_947 ) {
if ( V_3 -> V_947 != V_3 -> V_6 )
V_3 -> V_6 = V_3 -> V_947 ;
} else {
V_36 -> V_29 = NULL ;
}
}
F_131 (dev, crtc) {
V_29 -> V_578 = false ;
F_531 (dev, encoder) {
if ( V_6 -> V_946 == V_29 ) {
V_29 -> V_578 = true ;
break;
}
}
if ( V_29 -> V_578 != V_29 -> V_8 . V_34 -> V_240 ) {
F_144 ( L_227 ,
V_29 -> V_8 . V_8 . V_238 ,
V_29 -> V_578 ? L_70 : L_71 ) ;
V_93 -> V_1099 = true ;
}
if ( V_29 -> V_578 )
V_29 -> V_484 = V_29 -> V_93 ;
else
V_29 -> V_484 = NULL ;
}
return 0 ;
}
static void F_761 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_144 ( L_228 ,
F_71 ( V_29 -> V_4 ) ) ;
F_701 (dev, connector) {
if ( V_3 -> V_947 &&
V_3 -> V_947 -> V_946 == V_29 )
V_3 -> V_947 = NULL ;
}
F_531 (dev, encoder) {
if ( V_6 -> V_946 == V_29 )
V_6 -> V_946 = NULL ;
}
V_29 -> V_578 = false ;
V_29 -> V_484 = NULL ;
}
static int F_762 ( struct V_1097 * V_1098 )
{
struct V_9 * V_10 ;
struct V_1097 V_1102 ;
struct V_33 * V_34 = NULL ;
struct V_1091 * V_93 ;
struct V_31 * V_210 ;
unsigned V_1052 , V_579 , V_1053 ;
int V_298 ;
F_118 ( ! V_1098 ) ;
F_118 ( ! V_1098 -> V_29 ) ;
F_118 ( ! V_1098 -> V_29 -> V_1103 ) ;
F_118 ( ! V_1098 -> V_477 && V_1098 -> V_92 ) ;
F_118 ( V_1098 -> V_92 && V_1098 -> V_38 == 0 ) ;
if ( V_1098 -> V_92 ) {
F_144 ( L_229 ,
V_1098 -> V_29 -> V_8 . V_238 , V_1098 -> V_92 -> V_8 . V_238 ,
( int ) V_1098 -> V_38 , V_1098 -> V_265 , V_1098 -> V_266 ) ;
} else {
F_144 ( L_230 , V_1098 -> V_29 -> V_8 . V_238 ) ;
}
V_10 = V_1098 -> V_29 -> V_10 ;
V_298 = - V_489 ;
V_93 = F_444 ( sizeof( * V_93 ) , V_487 ) ;
if ( ! V_93 )
goto V_1104;
V_298 = F_753 ( V_10 , V_93 ) ;
if ( V_298 )
goto V_1104;
V_1102 . V_29 = V_1098 -> V_29 ;
V_1102 . V_477 = & V_1098 -> V_29 -> V_477 ;
V_1102 . V_265 = V_1098 -> V_29 -> V_265 ;
V_1102 . V_266 = V_1098 -> V_29 -> V_266 ;
V_1102 . V_92 = V_1098 -> V_29 -> V_91 -> V_92 ;
F_757 ( V_1098 , V_93 ) ;
V_34 = F_613 ( V_10 ) ;
if ( ! V_34 ) {
V_298 = - V_489 ;
goto V_1104;
}
V_34 -> V_949 = V_10 -> V_940 . V_949 ;
V_298 = F_759 ( V_10 , V_1098 , V_93 , V_34 ) ;
if ( V_298 )
goto V_950;
V_210 = F_743 ( V_1098 -> V_29 , V_1098 -> V_477 ,
V_1098 -> V_92 , V_34 ,
& V_1052 ,
& V_579 ,
& V_1053 ) ;
if ( F_615 ( V_210 ) ) {
V_298 = F_616 ( V_210 ) ;
goto V_950;
} else if ( V_210 ) {
if ( V_210 -> V_1039 !=
F_31 ( V_1098 -> V_29 ) -> V_93 -> V_1039 )
V_93 -> V_1099 = true ;
}
F_261 ( F_31 ( V_1098 -> V_29 ) ) ;
if ( V_93 -> V_1099 ) {
V_298 = F_750 ( V_1098 -> V_29 , V_1098 -> V_477 ,
V_1098 -> V_265 , V_1098 -> V_266 , V_1098 -> V_92 , V_210 ,
V_1052 , V_579 ,
V_1053 ) ;
} else if ( V_93 -> V_1100 ) {
struct V_28 * V_28 = F_31 ( V_1098 -> V_29 ) ;
struct V_261 * V_91 = V_1098 -> V_29 -> V_91 ;
int V_745 , V_617 ;
F_718 ( V_1098 -> V_477 , & V_617 , & V_745 ) ;
V_298 = V_91 -> V_495 -> V_1089 ( V_91 , V_1098 -> V_29 , V_1098 -> V_92 ,
0 , 0 , V_617 , V_745 ,
V_1098 -> V_265 << 16 , V_1098 -> V_266 << 16 ,
V_617 << 16 , V_745 << 16 ) ;
if ( ! V_28 -> V_262 && V_298 == 0 ) {
F_3 ( ! V_28 -> V_90 ) ;
F_168 ( V_1098 -> V_29 -> V_91 , V_1098 -> V_29 ) ;
}
if ( V_396 . V_397 && V_298 == 0 )
F_447 ( V_1098 -> V_29 -> V_10 ) ;
}
if ( V_298 ) {
F_144 ( L_231 ,
V_1098 -> V_29 -> V_8 . V_238 , V_298 ) ;
V_950:
F_755 ( V_10 , V_93 ) ;
F_763 ( V_34 ) ;
if ( F_31 ( V_1102 . V_29 ) -> V_578 && ! V_1102 . V_92 )
F_761 ( F_31 ( V_1102 . V_29 ) ) ;
if ( V_93 -> V_1099 &&
F_617 ( V_1102 . V_29 , V_1102 . V_477 ,
V_1102 . V_265 , V_1102 . V_266 , V_1102 . V_92 ,
V_34 ) )
F_123 ( L_232 ) ;
}
V_1104:
if ( V_34 )
F_618 ( V_34 ) ;
F_752 ( V_93 ) ;
return V_298 ;
}
static bool F_764 ( struct V_11 * V_12 ,
struct V_127 * V_130 ,
struct V_131 * V_132 )
{
T_4 V_121 ;
if ( ! F_77 ( V_12 , V_239 ) )
return false ;
V_121 = F_5 ( F_765 ( V_130 -> V_238 ) ) ;
V_132 -> V_67 = V_121 ;
V_132 -> V_592 = F_5 ( F_766 ( V_130 -> V_238 ) ) ;
V_132 -> V_593 = F_5 ( F_767 ( V_130 -> V_238 ) ) ;
return V_121 & V_123 ;
}
static void F_768 ( struct V_11 * V_12 ,
struct V_127 * V_130 )
{
F_120 ( F_766 ( V_130 -> V_238 ) , V_130 -> V_93 . V_132 . V_592 ) ;
F_120 ( F_767 ( V_130 -> V_238 ) , V_130 -> V_93 . V_132 . V_593 ) ;
}
static void F_769 ( struct V_11 * V_12 ,
struct V_127 * V_130 )
{
F_95 ( V_12 ) ;
F_120 ( F_765 ( V_130 -> V_238 ) , V_130 -> V_93 . V_132 . V_67 ) ;
F_121 ( F_765 ( V_130 -> V_238 ) ) ;
F_122 ( 150 ) ;
F_120 ( F_765 ( V_130 -> V_238 ) , V_130 -> V_93 . V_132 . V_67 ) ;
F_121 ( F_765 ( V_130 -> V_238 ) ) ;
F_122 ( 200 ) ;
}
static void F_770 ( struct V_11 * V_12 ,
struct V_127 * V_130 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_28 * V_29 ;
F_131 (dev, crtc) {
if ( F_59 ( V_29 ) == V_130 )
F_97 ( V_12 , V_29 -> V_4 ) ;
}
F_120 ( F_765 ( V_130 -> V_238 ) , 0 ) ;
F_121 ( F_765 ( V_130 -> V_238 ) ) ;
F_122 ( 200 ) ;
}
static void F_771 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_37 ;
V_12 -> V_485 = 2 ;
for ( V_37 = 0 ; V_37 < V_12 -> V_485 ; V_37 ++ ) {
V_12 -> V_129 [ V_37 ] . V_238 = V_37 ;
V_12 -> V_129 [ V_37 ] . V_134 = V_1105 [ V_37 ] ;
V_12 -> V_129 [ V_37 ] . V_237 = F_768 ;
V_12 -> V_129 [ V_37 ] . V_240 = F_769 ;
V_12 -> V_129 [ V_37 ] . V_241 = F_770 ;
V_12 -> V_129 [ V_37 ] . V_133 =
F_764 ;
}
}
static void F_772 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_62 ( V_10 ) )
F_773 ( V_10 ) ;
else if ( F_50 ( V_10 ) || F_96 ( V_10 ) )
F_771 ( V_10 ) ;
else
V_12 -> V_485 = 0 ;
F_118 ( V_12 -> V_485 > V_1106 ) ;
}
bool F_774 ( struct V_261 * V_164 ,
struct V_280 * V_34 )
{
if ( ! V_164 -> V_34 -> V_92 || ! V_34 -> V_92 ||
V_164 -> V_34 -> V_92 -> V_291 [ 0 ] != V_34 -> V_92 -> V_291 [ 0 ] ||
V_164 -> V_34 -> V_286 != V_34 -> V_286 )
return true ;
return false ;
}
int
F_775 ( struct V_261 * V_164 ,
struct V_279 * V_92 ,
const struct V_280 * V_1107 )
{
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_369 * V_369 = F_232 ( V_164 ) ;
enum V_4 V_4 = V_369 -> V_4 ;
struct V_295 * V_296 = F_184 ( V_92 ) ;
struct V_295 * V_1108 = F_184 ( V_164 -> V_92 ) ;
unsigned V_350 = 0 ;
int V_298 = 0 ;
if ( ! V_296 )
return 0 ;
switch ( V_164 -> type ) {
case V_1109 :
V_350 = F_213 ( V_4 ) ;
break;
case V_1110 :
V_350 = F_776 ( V_4 ) ;
break;
case V_1111 :
V_350 = F_777 ( V_4 ) ;
break;
}
F_56 ( & V_10 -> V_299 ) ;
if ( V_164 -> type == V_1110 &&
F_45 ( V_10 ) -> V_1112 ) {
int V_1113 = F_133 ( V_10 ) ? 16 * 1024 : 256 ;
V_298 = F_778 ( V_296 , V_1113 ) ;
if ( V_298 )
F_144 ( L_233 ) ;
} else {
V_298 = F_183 ( V_164 , V_92 , V_1107 , NULL ) ;
}
if ( V_298 == 0 )
F_696 ( V_1108 , V_296 , V_350 ) ;
F_58 ( & V_10 -> V_299 ) ;
return V_298 ;
}
void
F_779 ( struct V_261 * V_164 ,
struct V_279 * V_92 ,
const struct V_280 * V_1114 )
{
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_295 * V_296 = F_184 ( V_92 ) ;
if ( F_3 ( ! V_296 ) )
return;
if ( V_164 -> type != V_1110 ||
! F_45 ( V_10 ) -> V_1112 ) {
F_56 ( & V_10 -> V_299 ) ;
F_194 ( V_92 , V_1114 ) ;
F_58 ( & V_10 -> V_299 ) ;
}
}
static int
F_780 ( struct V_261 * V_164 ,
struct V_497 * V_34 )
{
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_29 = V_34 -> V_8 . V_29 ;
struct V_28 * V_28 ;
struct V_279 * V_92 = V_34 -> V_8 . V_92 ;
struct V_1115 * V_1116 = & V_34 -> V_1117 ;
struct V_1115 * V_1118 = & V_34 -> V_1118 ;
const struct V_1115 * V_1119 = & V_34 -> V_1119 ;
int V_298 ;
V_29 = V_29 ? V_29 : V_164 -> V_29 ;
V_28 = F_31 ( V_29 ) ;
V_298 = F_781 ( V_164 , V_29 , V_92 ,
V_1118 , V_1116 , V_1119 ,
V_1120 ,
V_1120 ,
false , true , & V_34 -> V_499 ) ;
if ( V_298 )
return V_298 ;
if ( V_28 -> V_90 ) {
V_28 -> V_1121 . V_1122 = true ;
if ( V_28 -> V_262 &&
F_45 ( V_10 ) -> V_105 <= 4 && ! F_18 ( V_10 ) &&
V_12 -> V_515 . V_29 == V_28 &&
V_34 -> V_8 . V_286 != F_220 ( V_1123 ) ) {
V_28 -> V_1121 . V_383 = true ;
}
if ( V_34 -> V_499 ) {
if ( F_170 ( V_10 ) && ! V_28 -> V_262 )
V_28 -> V_1121 . V_1124 = true ;
}
V_28 -> V_1121 . V_1125 |=
F_213 ( V_28 -> V_4 ) ;
V_28 -> V_1121 . V_1126 = true ;
if ( F_774 ( V_164 , & V_34 -> V_8 ) )
V_28 -> V_1121 . V_1127 = true ;
}
return 0 ;
}
static void
F_782 ( struct V_261 * V_164 ,
struct V_497 * V_34 )
{
struct V_89 * V_29 = V_34 -> V_8 . V_29 ;
struct V_279 * V_92 = V_34 -> V_8 . V_92 ;
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 ;
struct V_1115 * V_1118 = & V_34 -> V_1118 ;
V_29 = V_29 ? V_29 : V_164 -> V_29 ;
V_28 = F_31 ( V_29 ) ;
V_164 -> V_92 = V_92 ;
V_29 -> V_265 = V_1118 -> V_1128 >> 16 ;
V_29 -> V_266 = V_1118 -> y1 >> 16 ;
if ( V_28 -> V_90 ) {
if ( V_34 -> V_499 ) {
F_261 ( V_28 ) ;
V_28 -> V_262 = true ;
V_12 -> V_263 . V_264 ( V_29 , V_164 -> V_92 ,
V_29 -> V_265 , V_29 -> V_266 ) ;
} else {
F_172 ( V_164 , V_29 ) ;
}
}
}
static void F_783 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_369 * V_369 ;
struct V_261 * V_22 ;
unsigned V_1125 = 0 ;
F_438 (p, &dev->mode_config.plane_list, head) {
V_369 = F_232 ( V_22 ) ;
if ( V_28 -> V_1121 . V_1129 &
( 1 << F_784 ( V_22 ) ) ) {
switch ( V_22 -> type ) {
case V_1109 :
V_1125 = F_213 ( V_369 -> V_4 ) ;
break;
case V_1110 :
V_1125 = F_776 ( V_369 -> V_4 ) ;
break;
case V_1111 :
V_1125 = F_777 ( V_369 -> V_4 ) ;
break;
}
F_56 ( & V_10 -> V_299 ) ;
F_696 ( F_184 ( V_22 -> V_92 ) , NULL , V_1125 ) ;
F_58 ( & V_10 -> V_299 ) ;
}
}
if ( V_28 -> V_1121 . V_1122 )
F_288 ( V_29 ) ;
if ( V_28 -> V_1121 . V_383 )
F_360 ( V_10 ) ;
if ( V_28 -> V_1121 . V_1130 )
F_785 ( V_29 ) ;
if ( V_28 -> V_1121 . V_1127 )
F_368 ( V_29 ) ;
F_188 ( V_12 ) ;
if ( V_28 -> V_90 )
V_28 -> V_1121 . V_1131 =
F_673 ( V_28 ,
& V_28 -> V_1121 . V_1017 ) ;
}
static void F_786 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_31 ( V_29 ) ;
struct V_261 * V_22 ;
if ( V_28 -> V_1121 . V_1131 )
F_674 ( V_28 ,
V_28 -> V_1121 . V_1017 ) ;
F_192 ( V_12 ) ;
if ( V_28 -> V_1121 . V_1124 )
F_171 ( V_10 , V_28 -> V_4 ) ;
F_357 ( V_10 , V_28 -> V_1121 . V_1125 ) ;
if ( V_28 -> V_1121 . V_1126 ) {
F_56 ( & V_10 -> V_299 ) ;
F_356 ( V_10 ) ;
F_58 ( & V_10 -> V_299 ) ;
}
if ( V_28 -> V_1121 . V_1132 )
F_787 ( V_29 ) ;
F_336 (p, &dev->mode_config.plane_list)
if ( V_28 -> V_1121 . V_1133 & F_784 ( V_22 ) )
F_788 ( V_22 , V_29 , 0 , 0 , 0 ,
false , false ) ;
memset ( & V_28 -> V_1121 , 0 , sizeof( V_28 -> V_1121 ) ) ;
}
void F_789 ( struct V_261 * V_164 )
{
struct V_369 * V_369 = F_232 ( V_164 ) ;
F_790 ( V_164 ) ;
F_210 ( V_369 ) ;
}
static struct V_261 * F_791 ( struct V_9 * V_10 ,
int V_4 )
{
struct V_369 * V_91 ;
struct V_497 * V_34 ;
const T_4 * V_1134 ;
int V_1135 ;
V_91 = F_444 ( sizeof( * V_91 ) , V_487 ) ;
if ( V_91 == NULL )
return NULL ;
V_34 = F_792 ( & V_91 -> V_8 ) ;
if ( ! V_34 ) {
F_210 ( V_91 ) ;
return NULL ;
}
V_91 -> V_8 . V_34 = & V_34 -> V_8 ;
V_91 -> V_1136 = false ;
V_91 -> V_1137 = 1 ;
V_91 -> V_4 = V_4 ;
V_91 -> V_164 = V_4 ;
V_91 -> V_1138 = F_780 ;
V_91 -> V_500 = F_782 ;
if ( F_793 ( V_10 ) && F_45 ( V_10 ) -> V_105 < 4 )
V_91 -> V_164 = ! V_4 ;
if ( F_45 ( V_10 ) -> V_105 <= 3 ) {
V_1134 = V_1139 ;
V_1135 = F_277 ( V_1139 ) ;
} else {
V_1134 = V_1140 ;
V_1135 = F_277 ( V_1140 ) ;
}
F_794 ( V_10 , & V_91 -> V_8 , 0 ,
& V_1141 ,
V_1134 , V_1135 ,
V_1109 ) ;
if ( F_45 ( V_10 ) -> V_105 >= 4 ) {
if ( ! V_10 -> V_940 . V_1142 )
V_10 -> V_940 . V_1142 =
F_795 ( V_10 ,
F_220 ( V_1123 ) |
F_220 ( V_365 ) ) ;
if ( V_10 -> V_940 . V_1142 )
F_796 ( & V_91 -> V_8 . V_8 ,
V_10 -> V_940 . V_1142 ,
V_34 -> V_8 . V_286 ) ;
}
F_797 ( & V_91 -> V_8 , & V_1143 ) ;
return & V_91 -> V_8 ;
}
static int
F_798 ( struct V_261 * V_164 ,
struct V_497 * V_34 )
{
struct V_89 * V_29 = V_34 -> V_8 . V_29 ;
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_279 * V_92 = V_34 -> V_8 . V_92 ;
struct V_1115 * V_1116 = & V_34 -> V_1117 ;
struct V_1115 * V_1118 = & V_34 -> V_1118 ;
const struct V_1115 * V_1119 = & V_34 -> V_1119 ;
struct V_295 * V_296 = F_184 ( V_92 ) ;
struct V_28 * V_28 ;
unsigned V_342 ;
int V_298 ;
V_29 = V_29 ? V_29 : V_164 -> V_29 ;
V_28 = F_31 ( V_29 ) ;
V_298 = F_781 ( V_164 , V_29 , V_92 ,
V_1118 , V_1116 , V_1119 ,
V_1120 ,
V_1120 ,
true , true , & V_34 -> V_499 ) ;
if ( V_298 )
return V_298 ;
if ( ! V_296 )
goto V_1144;
if ( ! F_596 ( V_10 , V_34 -> V_8 . V_906 , V_34 -> V_8 . V_907 ) ) {
F_799 ( L_234 ,
V_34 -> V_8 . V_906 , V_34 -> V_8 . V_907 ) ;
return - V_292 ;
}
V_342 = F_591 ( V_34 -> V_8 . V_906 ) * 4 ;
if ( V_296 -> V_8 . V_339 < V_342 * V_34 -> V_8 . V_907 ) {
F_144 ( L_235 ) ;
return - V_489 ;
}
if ( V_92 -> V_291 [ 0 ] != V_272 ) {
F_144 ( L_236 ) ;
V_298 = - V_292 ;
}
V_1144:
if ( V_28 -> V_90 ) {
if ( V_164 -> V_34 -> V_906 != V_34 -> V_8 . V_906 )
V_28 -> V_1121 . V_1127 = true ;
V_28 -> V_1121 . V_1125 |=
F_776 ( V_28 -> V_4 ) ;
}
return V_298 ;
}
static void
F_800 ( struct V_261 * V_164 ,
struct V_497 * V_34 )
{
struct V_89 * V_29 = V_34 -> V_8 . V_29 ;
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_28 * V_28 ;
struct V_295 * V_296 = F_184 ( V_34 -> V_8 . V_92 ) ;
T_4 V_1022 ;
V_29 = V_29 ? V_29 : V_164 -> V_29 ;
V_28 = F_31 ( V_29 ) ;
V_164 -> V_92 = V_34 -> V_8 . V_92 ;
V_29 -> V_921 = V_34 -> V_8 . V_1145 ;
V_29 -> V_922 = V_34 -> V_8 . V_1146 ;
if ( V_28 -> V_1147 == V_296 )
goto V_1148;
if ( ! V_296 )
V_1022 = 0 ;
else if ( ! F_45 ( V_10 ) -> V_1112 )
V_1022 = F_212 ( V_296 ) ;
else
V_1022 = V_296 -> V_1149 -> V_1150 ;
V_28 -> V_923 = V_1022 ;
V_28 -> V_1147 = V_296 ;
V_1148:
if ( V_28 -> V_90 )
F_355 ( V_29 , V_34 -> V_499 ) ;
}
static struct V_261 * F_801 ( struct V_9 * V_10 ,
int V_4 )
{
struct V_369 * V_905 ;
struct V_497 * V_34 ;
V_905 = F_444 ( sizeof( * V_905 ) , V_487 ) ;
if ( V_905 == NULL )
return NULL ;
V_34 = F_792 ( & V_905 -> V_8 ) ;
if ( ! V_34 ) {
F_210 ( V_905 ) ;
return NULL ;
}
V_905 -> V_8 . V_34 = & V_34 -> V_8 ;
V_905 -> V_1136 = false ;
V_905 -> V_1137 = 1 ;
V_905 -> V_4 = V_4 ;
V_905 -> V_164 = V_4 ;
V_905 -> V_1138 = F_798 ;
V_905 -> V_500 = F_800 ;
F_794 ( V_10 , & V_905 -> V_8 , 0 ,
& V_1141 ,
V_1151 ,
F_277 ( V_1151 ) ,
V_1110 ) ;
if ( F_45 ( V_10 ) -> V_105 >= 4 ) {
if ( ! V_10 -> V_940 . V_1142 )
V_10 -> V_940 . V_1142 =
F_795 ( V_10 ,
F_220 ( V_1123 ) |
F_220 ( V_365 ) ) ;
if ( V_10 -> V_940 . V_1142 )
F_796 ( & V_905 -> V_8 . V_8 ,
V_10 -> V_940 . V_1142 ,
V_34 -> V_8 . V_286 ) ;
}
F_797 ( & V_905 -> V_8 , & V_1143 ) ;
return & V_905 -> V_8 ;
}
static void F_802 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 ;
struct V_31 * V_32 = NULL ;
struct V_261 * V_91 = NULL ;
struct V_261 * V_905 = NULL ;
int V_37 , V_298 ;
V_28 = F_444 ( sizeof( * V_28 ) , V_487 ) ;
if ( V_28 == NULL )
return;
V_32 = F_444 ( sizeof( * V_32 ) , V_487 ) ;
if ( ! V_32 )
goto V_950;
F_633 ( V_28 , V_32 ) ;
V_32 -> V_8 . V_29 = & V_28 -> V_8 ;
V_91 = F_791 ( V_10 , V_4 ) ;
if ( ! V_91 )
goto V_950;
V_905 = F_801 ( V_10 , V_4 ) ;
if ( ! V_905 )
goto V_950;
V_298 = F_803 ( V_10 , & V_28 -> V_8 , V_91 ,
V_905 , & V_1152 ) ;
if ( V_298 )
goto V_950;
F_804 ( & V_28 -> V_8 , 256 ) ;
for ( V_37 = 0 ; V_37 < 256 ; V_37 ++ ) {
V_28 -> V_511 [ V_37 ] = V_37 ;
V_28 -> V_512 [ V_37 ] = V_37 ;
V_28 -> V_513 [ V_37 ] = V_37 ;
}
V_28 -> V_4 = V_4 ;
V_28 -> V_164 = V_4 ;
if ( F_793 ( V_10 ) && F_45 ( V_10 ) -> V_105 < 4 ) {
F_144 ( L_237 ) ;
V_28 -> V_164 = ! V_4 ;
}
V_28 -> V_911 = ~ 0 ;
V_28 -> V_910 = ~ 0 ;
V_28 -> V_912 = ~ 0 ;
F_118 ( V_4 >= F_277 ( V_12 -> V_982 ) ||
V_12 -> V_982 [ V_28 -> V_164 ] != NULL ) ;
V_12 -> V_982 [ V_28 -> V_164 ] = & V_28 -> V_8 ;
V_12 -> V_97 [ V_28 -> V_4 ] = & V_28 -> V_8 ;
F_691 ( & V_28 -> V_1018 . V_437 , F_675 ) ;
F_805 ( & V_28 -> V_8 , & V_1153 ) ;
F_3 ( F_806 ( & V_28 -> V_8 ) != V_28 -> V_4 ) ;
return;
V_950:
if ( V_91 )
F_790 ( V_91 ) ;
if ( V_905 )
F_790 ( V_905 ) ;
F_210 ( V_32 ) ;
F_210 ( V_28 ) ;
}
enum V_4 F_807 ( struct V_2 * V_3 )
{
struct V_602 * V_6 = V_3 -> V_8 . V_6 ;
struct V_9 * V_10 = V_3 -> V_8 . V_10 ;
F_3 ( ! F_808 ( & V_10 -> V_940 . V_941 ) ) ;
if ( ! V_6 || F_3 ( ! V_6 -> V_29 ) )
return V_1154 ;
return F_31 ( V_6 -> V_29 ) -> V_4 ;
}
int F_809 ( struct V_9 * V_10 , void * V_1155 ,
struct V_1156 * V_1157 )
{
struct V_1158 * V_1159 = V_1155 ;
struct V_89 * V_1160 ;
struct V_28 * V_29 ;
V_1160 = F_810 ( V_10 , V_1159 -> V_1161 ) ;
if ( ! V_1160 ) {
F_123 ( L_238 ) ;
return - V_1162 ;
}
V_29 = F_31 ( V_1160 ) ;
V_1159 -> V_4 = V_29 -> V_4 ;
return 0 ;
}
static int F_811 ( struct V_1 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_8 . V_10 ;
struct V_1 * V_1042 ;
int V_1163 = 0 ;
int V_1164 = 0 ;
F_531 (dev, source_encoder) {
if ( F_710 ( V_6 , V_1042 ) )
V_1163 |= ( 1 << V_1164 ) ;
V_1164 ++ ;
}
return V_1163 ;
}
static bool F_812 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_119 ( V_10 ) )
return false ;
if ( ( F_5 ( V_1165 ) & V_1166 ) == 0 )
return false ;
if ( F_7 ( V_10 ) && ( F_5 ( V_1167 ) & V_1168 ) )
return false ;
return true ;
}
static bool F_813 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_45 ( V_10 ) -> V_105 >= 9 )
return false ;
if ( F_814 ( V_10 ) || F_815 ( V_10 ) )
return false ;
if ( F_20 ( V_10 ) )
return false ;
if ( F_21 ( V_10 ) && ! V_12 -> V_653 . V_1169 )
return false ;
return true ;
}
static void F_816 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
bool V_1170 = false ;
F_817 ( V_10 ) ;
if ( F_813 ( V_10 ) )
F_818 ( V_10 ) ;
if ( F_62 ( V_10 ) ) {
int V_80 ;
V_80 = F_5 ( V_1171 ) & V_1172 ;
if ( V_80 ||
( F_378 ( V_10 ) && F_819 ( V_10 ) < V_1173 ) )
F_820 ( V_10 , V_533 ) ;
V_80 = F_5 ( V_1174 ) ;
if ( V_80 & V_1175 )
F_820 ( V_10 , V_110 ) ;
if ( V_80 & V_1176 )
F_820 ( V_10 , V_112 ) ;
if ( V_80 & V_1177 )
F_820 ( V_10 , V_114 ) ;
} else if ( F_4 ( V_10 ) ) {
int V_80 ;
V_1170 = F_821 ( V_10 , V_114 ) ;
if ( F_812 ( V_10 ) )
F_822 ( V_10 , V_1165 , V_533 ) ;
if ( F_5 ( V_203 ) & V_1178 ) {
V_80 = F_823 ( V_10 , V_1179 , true ) ;
if ( ! V_80 )
F_824 ( V_10 , V_203 , V_110 ) ;
if ( ! V_80 && ( F_5 ( V_196 ) & V_1166 ) )
F_822 ( V_10 , V_196 , V_110 ) ;
}
if ( F_5 ( V_204 ) & V_1178 )
F_824 ( V_10 , V_204 , V_112 ) ;
if ( ! V_1170 && F_5 ( V_205 ) & V_1178 )
F_824 ( V_10 , V_205 , V_114 ) ;
if ( F_5 ( V_198 ) & V_1166 )
F_822 ( V_10 , V_198 , V_112 ) ;
if ( F_5 ( V_200 ) & V_1166 )
F_822 ( V_10 , V_200 , V_114 ) ;
} else if ( F_21 ( V_10 ) ) {
if ( F_5 ( V_1180 + V_1181 ) & V_1178 &&
! F_821 ( V_10 , V_110 ) )
F_824 ( V_10 , V_1180 + V_1181 ,
V_110 ) ;
if ( F_5 ( V_1180 + V_1182 ) & V_1166 ||
F_821 ( V_10 , V_110 ) )
F_822 ( V_10 , V_1180 + V_1182 , V_110 ) ;
if ( F_5 ( V_1180 + V_1183 ) & V_1178 &&
! F_821 ( V_10 , V_112 ) )
F_824 ( V_10 , V_1180 + V_1183 ,
V_112 ) ;
if ( F_5 ( V_1180 + V_1184 ) & V_1166 ||
F_821 ( V_10 , V_112 ) )
F_822 ( V_10 , V_1180 + V_1184 , V_112 ) ;
if ( F_20 ( V_10 ) ) {
if ( F_5 ( V_1180 + V_1185 ) & V_1178 )
F_824 ( V_10 , V_1180 + V_1185 ,
V_114 ) ;
if ( F_5 ( V_1180 + V_1186 ) & V_1166 )
F_822 ( V_10 , V_1180 + V_1186 , V_114 ) ;
}
F_825 ( V_10 ) ;
} else if ( F_826 ( V_10 ) ) {
bool V_80 = false ;
if ( F_5 ( V_1187 ) & V_1178 ) {
F_144 ( L_239 ) ;
V_80 = F_823 ( V_10 , V_1187 , true ) ;
if ( ! V_80 && F_827 ( V_10 ) ) {
F_144 ( L_240 ) ;
F_824 ( V_10 , V_1181 , V_110 ) ;
}
if ( ! V_80 && F_828 ( V_10 ) )
F_822 ( V_10 , V_1182 , V_110 ) ;
}
if ( F_5 ( V_1187 ) & V_1178 ) {
F_144 ( L_241 ) ;
V_80 = F_823 ( V_10 , V_1188 , false ) ;
}
if ( ! V_80 && ( F_5 ( V_1188 ) & V_1178 ) ) {
if ( F_827 ( V_10 ) ) {
F_144 ( L_242 ) ;
F_824 ( V_10 , V_1183 , V_112 ) ;
}
if ( F_828 ( V_10 ) )
F_822 ( V_10 , V_1184 , V_112 ) ;
}
if ( F_828 ( V_10 ) &&
( F_5 ( V_1186 ) & V_1166 ) )
F_822 ( V_10 , V_1186 , V_114 ) ;
} else if ( F_22 ( V_10 ) )
F_829 ( V_10 ) ;
if ( F_830 ( V_10 ) )
F_831 ( V_10 ) ;
F_832 ( V_10 ) ;
F_531 (dev, encoder) {
V_6 -> V_8 . V_945 = V_6 -> V_235 ;
V_6 -> V_8 . V_1189 =
F_811 ( V_6 ) ;
}
F_538 ( V_10 ) ;
F_833 ( V_10 ) ;
}
static void F_834 ( struct V_279 * V_92 )
{
struct V_9 * V_10 = V_92 -> V_10 ;
struct V_777 * V_778 = F_204 ( V_92 ) ;
F_835 ( V_92 ) ;
F_56 ( & V_10 -> V_299 ) ;
F_3 ( ! V_778 -> V_296 -> V_1190 -- ) ;
F_205 ( & V_778 -> V_296 -> V_8 ) ;
F_58 ( & V_10 -> V_299 ) ;
F_210 ( V_778 ) ;
}
static int F_836 ( struct V_279 * V_92 ,
struct V_1156 * V_1157 ,
unsigned int * V_1191 )
{
struct V_777 * V_778 = F_204 ( V_92 ) ;
struct V_295 * V_296 = V_778 -> V_296 ;
return F_837 ( V_1157 , & V_296 -> V_8 , V_1191 ) ;
}
static
T_1 F_838 ( struct V_9 * V_10 , V_68 V_290 ,
T_4 V_268 )
{
T_1 V_105 = F_45 ( V_10 ) -> V_105 ;
if ( V_105 >= 9 ) {
return V_69 ( 8192 * F_176 ( V_268 , 0 ) , 32768 ) ;
} else if ( V_105 >= 5 && ! F_21 ( V_10 ) ) {
return 32 * 1024 ;
} else if ( V_105 >= 4 ) {
if ( V_290 == V_273 )
return 16 * 1024 ;
else
return 32 * 1024 ;
} else if ( V_105 >= 3 ) {
if ( V_290 == V_273 )
return 8 * 1024 ;
else
return 16 * 1024 ;
} else {
return 8 * 1024 ;
}
}
static int F_203 ( struct V_9 * V_10 ,
struct V_777 * V_778 ,
struct V_334 * V_335 ,
struct V_295 * V_296 )
{
unsigned int V_776 ;
int V_298 ;
T_1 V_1192 , V_1193 ;
F_3 ( ! F_185 ( & V_10 -> V_299 ) ) ;
if ( V_335 -> V_344 & V_345 ) {
if ( ! ! ( V_296 -> V_304 == V_341 ) !=
! ! ( V_335 -> V_291 [ 0 ] == V_273 ) ) {
F_799 ( L_243 ) ;
return - V_292 ;
}
} else {
if ( V_296 -> V_304 == V_341 )
V_335 -> V_291 [ 0 ] = V_273 ;
else if ( V_296 -> V_304 == V_1194 ) {
F_799 ( L_244 ) ;
return - V_292 ;
}
}
switch ( V_335 -> V_291 [ 0 ] ) {
case V_274 :
case V_275 :
if ( F_45 ( V_10 ) -> V_105 < 9 ) {
F_799 ( L_245 ,
V_335 -> V_291 [ 0 ] ) ;
return - V_292 ;
}
case V_272 :
case V_273 :
break;
default:
F_799 ( L_246 ,
V_335 -> V_291 [ 0 ] ) ;
return - V_292 ;
}
V_1193 = F_227 ( V_10 , V_335 -> V_291 [ 0 ] ,
V_335 -> V_268 ) ;
if ( V_335 -> V_289 [ 0 ] & ( V_1193 - 1 ) ) {
F_799 ( L_247 ,
V_335 -> V_289 [ 0 ] , V_1193 ) ;
return - V_292 ;
}
V_1192 = F_838 ( V_10 , V_335 -> V_291 [ 0 ] ,
V_335 -> V_268 ) ;
if ( V_335 -> V_289 [ 0 ] > V_1192 ) {
F_799 ( L_248 ,
V_335 -> V_291 [ 0 ] != V_272 ?
L_249 : L_250 ,
V_335 -> V_289 [ 0 ] , V_1192 ) ;
return - V_292 ;
}
if ( V_335 -> V_291 [ 0 ] == V_273 &&
V_335 -> V_289 [ 0 ] != V_296 -> V_342 ) {
F_799 ( L_251 ,
V_335 -> V_289 [ 0 ] , V_296 -> V_342 ) ;
return - V_292 ;
}
switch ( V_335 -> V_268 ) {
case V_312 :
case V_316 :
case V_318 :
case V_330 :
break;
case V_314 :
case V_359 :
if ( F_45 ( V_10 ) -> V_105 > 3 ) {
F_799 ( L_252 ,
F_839 ( V_335 -> V_268 ) ) ;
return - V_292 ;
}
break;
case V_320 :
case V_329 :
case V_322 :
case V_360 :
case V_324 :
case V_361 :
if ( F_45 ( V_10 ) -> V_105 < 4 ) {
F_799 ( L_252 ,
F_839 ( V_335 -> V_268 ) ) ;
return - V_292 ;
}
break;
case V_1195 :
case V_1196 :
case V_1197 :
case V_1198 :
if ( F_45 ( V_10 ) -> V_105 < 5 ) {
F_799 ( L_252 ,
F_839 ( V_335 -> V_268 ) ) ;
return - V_292 ;
}
break;
default:
F_799 ( L_252 ,
F_839 ( V_335 -> V_268 ) ) ;
return - V_292 ;
}
if ( V_335 -> V_1029 [ 0 ] != 0 )
return - V_292 ;
V_776 = F_179 ( V_10 , V_335 -> V_276 ,
V_335 -> V_268 ,
V_335 -> V_291 [ 0 ] ) ;
if ( V_296 -> V_8 . V_339 < V_776 * V_335 -> V_289 [ 0 ] )
return - V_292 ;
F_840 ( & V_778 -> V_8 , V_335 ) ;
V_778 -> V_296 = V_296 ;
V_778 -> V_296 -> V_1190 ++ ;
V_298 = F_841 ( V_10 , & V_778 -> V_8 , & V_1199 ) ;
if ( V_298 ) {
F_123 ( L_253 , V_298 ) ;
return V_298 ;
}
return 0 ;
}
static struct V_279 *
F_842 ( struct V_9 * V_10 ,
struct V_1156 * V_1200 ,
struct V_334 * V_335 )
{
struct V_295 * V_296 ;
V_296 = F_843 ( F_844 ( V_10 , V_1200 ,
V_335 -> V_1201 [ 0 ] ) ) ;
if ( & V_296 -> V_8 == NULL )
return F_599 ( - V_1162 ) ;
return F_600 ( V_10 , V_335 , V_296 ) ;
}
static inline void F_845 ( struct V_9 * V_10 )
{
}
static void F_846 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_4 ( V_10 ) || F_18 ( V_10 ) )
V_12 -> V_263 . V_768 = F_33 ;
else if ( F_20 ( V_10 ) )
V_12 -> V_263 . V_768 = F_38 ;
else if ( F_21 ( V_10 ) )
V_12 -> V_263 . V_768 = F_37 ;
else if ( F_19 ( V_10 ) )
V_12 -> V_263 . V_768 = F_32 ;
else
V_12 -> V_263 . V_768 = F_30 ;
if ( F_45 ( V_10 ) -> V_105 >= 9 ) {
V_12 -> V_263 . V_1079 = F_589 ;
V_12 -> V_263 . V_1202 =
F_564 ;
V_12 -> V_263 . V_1085 =
F_582 ;
V_12 -> V_263 . V_595 = F_373 ;
V_12 -> V_263 . V_385 = F_387 ;
V_12 -> V_263 . V_598 = F_391 ;
V_12 -> V_263 . V_264 =
F_230 ;
} else if ( F_62 ( V_10 ) ) {
V_12 -> V_263 . V_1079 = F_589 ;
V_12 -> V_263 . V_1202 =
F_567 ;
V_12 -> V_263 . V_1085 =
F_582 ;
V_12 -> V_263 . V_595 = F_373 ;
V_12 -> V_263 . V_385 = F_387 ;
V_12 -> V_263 . V_598 = F_391 ;
V_12 -> V_263 . V_264 =
F_224 ;
} else if ( F_4 ( V_10 ) ) {
V_12 -> V_263 . V_1079 = F_568 ;
V_12 -> V_263 . V_1202 =
F_567 ;
V_12 -> V_263 . V_1085 =
F_557 ;
V_12 -> V_263 . V_595 = F_361 ;
V_12 -> V_263 . V_385 = F_385 ;
V_12 -> V_263 . V_598 = F_391 ;
V_12 -> V_263 . V_264 =
F_224 ;
} else if ( F_21 ( V_10 ) ) {
V_12 -> V_263 . V_1079 = F_528 ;
V_12 -> V_263 . V_1202 =
F_526 ;
V_12 -> V_263 . V_1085 = F_523 ;
V_12 -> V_263 . V_595 = F_420 ;
V_12 -> V_263 . V_385 = F_432 ;
V_12 -> V_263 . V_598 = F_434 ;
V_12 -> V_263 . V_264 =
F_214 ;
} else {
V_12 -> V_263 . V_1079 = F_528 ;
V_12 -> V_263 . V_1202 =
F_526 ;
V_12 -> V_263 . V_1085 = F_523 ;
V_12 -> V_263 . V_595 = F_430 ;
V_12 -> V_263 . V_385 = F_432 ;
V_12 -> V_263 . V_598 = F_434 ;
V_12 -> V_263 . V_264 =
F_214 ;
}
if ( F_21 ( V_10 ) )
V_12 -> V_263 . V_557 =
F_460 ;
else if ( F_516 ( V_10 ) || ( F_518 ( V_10 ) && ! F_847 ( V_10 ) ) )
V_12 -> V_263 . V_557 =
F_461 ;
else if ( F_459 ( V_10 ) )
V_12 -> V_263 . V_557 =
F_462 ;
else if ( F_517 ( V_10 ) || F_73 ( V_10 ) )
V_12 -> V_263 . V_557 =
F_463 ;
else if ( F_19 ( V_10 ) )
V_12 -> V_263 . V_557 =
F_464 ;
else if ( F_848 ( V_10 ) )
V_12 -> V_263 . V_557 =
F_466 ;
else if ( F_74 ( V_10 ) )
V_12 -> V_263 . V_557 =
F_467 ;
else if ( F_849 ( V_10 ) )
V_12 -> V_263 . V_557 =
F_468 ;
else
V_12 -> V_263 . V_557 =
F_469 ;
if ( F_7 ( V_10 ) ) {
V_12 -> V_263 . V_467 = F_268 ;
} else if ( F_275 ( V_10 ) ) {
V_12 -> V_263 . V_467 = F_273 ;
} else if ( F_267 ( V_10 ) ) {
V_12 -> V_263 . V_467 = F_276 ;
} else if ( F_225 ( V_10 ) || F_170 ( V_10 ) ) {
V_12 -> V_263 . V_467 = V_1203 ;
} else if ( F_21 ( V_10 ) ) {
V_12 -> V_263 . V_550 =
F_419 ;
}
switch ( F_45 ( V_10 ) -> V_105 ) {
case 2 :
V_12 -> V_263 . V_1035 = F_654 ;
break;
case 3 :
V_12 -> V_263 . V_1035 = F_659 ;
break;
case 4 :
case 5 :
V_12 -> V_263 . V_1035 = F_660 ;
break;
case 6 :
V_12 -> V_263 . V_1035 = F_661 ;
break;
case 7 :
case 8 :
V_12 -> V_263 . V_1035 = F_662 ;
break;
case 9 :
default:
V_12 -> V_263 . V_1035 = F_679 ;
}
F_850 ( V_10 ) ;
F_851 ( & V_12 -> V_1204 ) ;
}
static void F_852 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_160 |= V_161 ;
F_853 ( L_254 ) ;
}
static void F_854 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_160 |= V_162 ;
F_853 ( L_255 ) ;
}
static void F_855 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_160 |= V_655 ;
F_853 ( L_256 ) ;
}
static void F_856 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_160 |= V_1205 ;
F_853 ( L_257 ) ;
}
static void F_857 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_160 |= V_1206 ;
F_853 ( L_258 ) ;
}
static int F_858 ( const struct V_1207 * V_238 )
{
F_853 ( L_259 , V_238 -> V_1208 ) ;
return 1 ;
}
static void F_859 ( struct V_9 * V_10 )
{
struct V_1209 * V_1210 = V_10 -> V_619 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < F_277 ( V_1211 ) ; V_37 ++ ) {
struct V_1212 * V_1213 = & V_1211 [ V_37 ] ;
if ( V_1210 -> V_1214 == V_1213 -> V_1214 &&
( V_1210 -> V_1215 == V_1213 -> V_1215 ||
V_1213 -> V_1215 == V_1216 ) &&
( V_1210 -> V_1217 == V_1213 -> V_1217 ||
V_1213 -> V_1217 == V_1216 ) )
V_1213 -> V_1218 ( V_10 ) ;
}
for ( V_37 = 0 ; V_37 < F_277 ( V_1219 ) ; V_37 ++ ) {
if ( F_860 ( * V_1219 [ V_37 ] . V_1220 ) != 0 )
V_1219 [ V_37 ] . V_1218 ( V_10 ) ;
}
}
static void F_861 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_9 V_1221 ;
T_1 V_1222 = F_862 ( V_10 ) ;
F_863 ( V_10 -> V_619 , V_1223 ) ;
F_864 ( V_1224 , V_1225 ) ;
V_1221 = F_865 ( V_1226 ) ;
F_864 ( V_1221 | 1 << 5 , V_1226 ) ;
F_866 ( V_10 -> V_619 , V_1223 ) ;
F_122 ( 300 ) ;
F_120 ( V_1222 , V_1227 ) ;
F_121 ( V_1222 ) ;
}
void F_250 ( struct V_9 * V_10 )
{
F_581 ( V_10 ) ;
if ( F_21 ( V_10 ) )
F_405 ( V_10 ) ;
F_867 ( V_10 ) ;
F_868 ( V_10 ) ;
}
void F_869 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_169 , V_298 ;
enum V_4 V_4 ;
struct V_28 * V_29 ;
F_870 ( V_10 ) ;
V_10 -> V_940 . V_1228 = 0 ;
V_10 -> V_940 . V_1229 = 0 ;
V_10 -> V_940 . V_1230 = 24 ;
V_10 -> V_940 . V_1231 = 1 ;
V_10 -> V_940 . V_1232 = true ;
V_10 -> V_940 . V_495 = & V_1233 ;
F_859 ( V_10 ) ;
F_871 ( V_10 ) ;
if ( F_45 ( V_10 ) -> V_605 == 0 )
return;
F_846 ( V_10 ) ;
F_872 ( V_10 ) ;
if ( F_22 ( V_10 ) ) {
V_10 -> V_940 . V_1234 = 2048 ;
V_10 -> V_940 . V_1235 = 2048 ;
} else if ( F_873 ( V_10 ) ) {
V_10 -> V_940 . V_1234 = 4096 ;
V_10 -> V_940 . V_1235 = 4096 ;
} else {
V_10 -> V_940 . V_1234 = 8192 ;
V_10 -> V_940 . V_1235 = 8192 ;
}
if ( F_73 ( V_10 ) || F_74 ( V_10 ) ) {
V_10 -> V_940 . V_1236 = F_73 ( V_10 ) ? 64 : 512 ;
V_10 -> V_940 . V_1237 = 1023 ;
} else if ( F_22 ( V_10 ) ) {
V_10 -> V_940 . V_1236 = V_1238 ;
V_10 -> V_940 . V_1237 = V_1239 ;
} else {
V_10 -> V_940 . V_1236 = V_1240 ;
V_10 -> V_940 . V_1237 = V_1241 ;
}
V_10 -> V_940 . V_1242 = V_12 -> V_1243 . V_1244 ;
F_144 ( L_260 ,
F_45 ( V_10 ) -> V_605 ,
F_45 ( V_10 ) -> V_605 > 1 ? L_261 : L_262 ) ;
F_83 (dev_priv, pipe) {
F_802 ( V_10 , V_4 ) ;
F_85 (dev_priv, pipe, sprite) {
V_298 = F_874 ( V_10 , V_4 , V_169 ) ;
if ( V_298 )
F_144 ( L_263 ,
F_71 ( V_4 ) , F_88 ( V_4 , V_169 ) , V_298 ) ;
}
}
F_114 ( V_10 ) ;
F_772 ( V_10 ) ;
F_861 ( V_10 ) ;
F_816 ( V_10 ) ;
F_360 ( V_10 ) ;
F_246 ( V_10 ) ;
F_253 ( V_10 , false ) ;
F_255 ( V_10 ) ;
F_131 (dev, crtc) {
if ( ! V_29 -> V_90 )
continue;
if ( V_12 -> V_263 . V_1202 ) {
V_12 -> V_263 . V_1202 ( V_29 ,
& V_29 -> V_333 ) ;
F_209 ( V_29 , & V_29 -> V_333 ) ;
}
}
}
static void F_875 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
struct V_597 * V_1245 = NULL ;
struct V_934 V_944 ;
struct V_936 * V_937 = V_10 -> V_940 . V_949 ;
F_701 (dev, connector) {
if ( V_3 -> V_6 -> type == V_53 ) {
V_1245 = & V_3 -> V_8 ;
break;
}
}
if ( ! V_1245 )
return;
if ( F_610 ( V_1245 , NULL , & V_944 , V_937 ) )
F_620 ( V_1245 , & V_944 , V_937 ) ;
}
static bool
F_876 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_99 , V_121 ;
if ( F_45 ( V_10 ) -> V_605 == 1 )
return true ;
V_99 = F_80 ( ! V_29 -> V_164 ) ;
V_121 = F_5 ( V_99 ) ;
if ( ( V_121 & V_165 ) &&
( ! ! ( V_121 & V_167 ) == V_29 -> V_4 ) )
return false ;
return true ;
}
static void F_877 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_99 ;
V_99 = F_46 ( V_29 -> V_93 -> V_98 ) ;
F_120 ( V_99 , F_5 ( V_99 ) & ~ V_1246 ) ;
F_878 ( & V_29 -> V_8 ) ;
if ( V_29 -> V_90 ) {
F_742 ( V_29 ) ;
F_369 ( & V_29 -> V_8 ) ;
}
if ( F_45 ( V_10 ) -> V_105 < 4 && ! F_876 ( V_29 ) ) {
struct V_2 * V_3 ;
bool V_164 ;
F_144 ( L_264 ,
V_29 -> V_8 . V_8 . V_238 ) ;
V_164 = V_29 -> V_164 ;
V_29 -> V_164 = ! V_164 ;
V_29 -> V_262 = true ;
V_12 -> V_263 . V_385 ( & V_29 -> V_8 ) ;
V_29 -> V_164 = V_164 ;
F_701 (dev, connector) {
if ( V_3 -> V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
V_3 -> V_8 . V_600 = V_601 ;
V_3 -> V_8 . V_6 = NULL ;
}
F_701 (dev, connector)
if ( V_3 -> V_6 -> V_8 . V_29 == & V_29 -> V_8 ) {
V_3 -> V_6 -> V_8 . V_29 = NULL ;
V_3 -> V_6 -> V_596 = false ;
}
F_3 ( V_29 -> V_90 ) ;
V_29 -> V_8 . V_34 -> V_240 = false ;
V_29 -> V_8 . V_120 = false ;
}
if ( V_12 -> V_160 & V_161 &&
V_29 -> V_4 == V_142 && ! V_29 -> V_90 ) {
F_875 ( V_10 ) ;
}
F_436 ( & V_29 -> V_8 ) ;
if ( V_29 -> V_90 != V_29 -> V_8 . V_34 -> V_240 ) {
struct V_1 * V_6 ;
F_144 ( L_265 ,
V_29 -> V_8 . V_8 . V_238 ,
V_29 -> V_8 . V_34 -> V_240 ? L_174 : L_175 ,
V_29 -> V_90 ? L_174 : L_175 ) ;
V_29 -> V_8 . V_34 -> V_240 = V_29 -> V_90 ;
V_29 -> V_8 . V_120 = V_29 -> V_90 ;
F_3 ( V_29 -> V_90 ) ;
F_11 (dev, &crtc->base, encoder) {
F_3 ( V_6 -> V_596 ) ;
V_6 -> V_8 . V_29 = NULL ;
}
}
if ( V_29 -> V_90 || F_349 ( V_10 ) ) {
V_29 -> V_1247 = true ;
V_29 -> V_1248 = true ;
}
}
static void F_879 ( struct V_1 * V_6 )
{
struct V_2 * V_3 ;
struct V_9 * V_10 = V_6 -> V_8 . V_10 ;
bool V_1249 = V_6 -> V_8 . V_29 &&
F_31 ( V_6 -> V_8 . V_29 ) -> V_90 ;
if ( V_6 -> V_596 && ! V_1249 ) {
F_144 ( L_266 ,
V_6 -> V_8 . V_8 . V_238 ,
V_6 -> V_8 . V_134 ) ;
if ( V_6 -> V_8 . V_29 ) {
F_144 ( L_267 ,
V_6 -> V_8 . V_8 . V_238 ,
V_6 -> V_8 . V_134 ) ;
V_6 -> V_241 ( V_6 ) ;
if ( V_6 -> V_524 )
V_6 -> V_524 ( V_6 ) ;
}
V_6 -> V_8 . V_29 = NULL ;
V_6 -> V_596 = false ;
F_701 (dev, connector) {
if ( V_3 -> V_6 != V_6 )
continue;
V_3 -> V_8 . V_600 = V_601 ;
V_3 -> V_8 . V_6 = NULL ;
}
}
}
void F_880 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_1222 = F_862 ( V_10 ) ;
if ( ! ( F_5 ( V_1222 ) & V_1227 ) ) {
F_144 ( L_268 ) ;
F_861 ( V_10 ) ;
}
}
void F_881 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_77 ( V_12 , V_1250 ) )
return;
F_880 ( V_10 ) ;
}
static bool F_882 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
if ( ! V_29 -> V_90 )
return false ;
return F_5 ( F_80 ( V_29 -> V_164 ) ) & V_165 ;
}
static void F_883 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
int V_37 ;
F_131 (dev, crtc) {
memset ( V_29 -> V_93 , 0 , sizeof( * V_29 -> V_93 ) ) ;
V_29 -> V_93 -> V_160 |= V_1063 ;
V_29 -> V_90 = V_12 -> V_263 . V_1079 ( V_29 ,
V_29 -> V_93 ) ;
V_29 -> V_8 . V_34 -> V_240 = V_29 -> V_90 ;
V_29 -> V_8 . V_120 = V_29 -> V_90 ;
V_29 -> V_262 = F_882 ( V_29 ) ;
F_144 ( L_269 ,
V_29 -> V_8 . V_8 . V_238 ,
V_29 -> V_90 ? L_174 : L_175 ) ;
}
for ( V_37 = 0 ; V_37 < V_12 -> V_485 ; V_37 ++ ) {
struct V_127 * V_130 = & V_12 -> V_129 [ V_37 ] ;
V_130 -> V_236 = V_130 -> V_133 ( V_12 , V_130 ,
& V_130 -> V_93 . V_132 ) ;
V_130 -> V_90 = 0 ;
V_130 -> V_93 . V_235 = 0 ;
F_131 (dev, crtc) {
if ( V_29 -> V_90 && F_59 ( V_29 ) == V_130 ) {
V_130 -> V_90 ++ ;
V_130 -> V_93 . V_235 |= 1 << V_29 -> V_4 ;
}
}
F_144 ( L_270 ,
V_130 -> V_134 , V_130 -> V_93 . V_235 , V_130 -> V_236 ) ;
if ( V_130 -> V_93 . V_235 )
F_146 ( V_12 , V_239 ) ;
}
F_531 (dev, encoder) {
V_4 = 0 ;
if ( V_6 -> V_133 ( V_6 , & V_4 ) ) {
V_29 = F_31 ( V_12 -> V_97 [ V_4 ] ) ;
V_6 -> V_8 . V_29 = & V_29 -> V_8 ;
V_6 -> V_1080 ( V_6 , V_29 -> V_93 ) ;
} else {
V_6 -> V_8 . V_29 = NULL ;
}
V_6 -> V_596 = false ;
F_144 ( L_271 ,
V_6 -> V_8 . V_8 . V_238 ,
V_6 -> V_8 . V_134 ,
V_6 -> V_8 . V_29 ? L_174 : L_175 ,
F_71 ( V_4 ) ) ;
}
F_701 (dev, connector) {
if ( V_3 -> V_133 ( V_3 ) ) {
V_3 -> V_8 . V_600 = V_603 ;
V_3 -> V_6 -> V_596 = true ;
V_3 -> V_8 . V_6 = & V_3 -> V_6 -> V_8 ;
} else {
V_3 -> V_8 . V_600 = V_601 ;
V_3 -> V_8 . V_6 = NULL ;
}
F_144 ( L_272 ,
V_3 -> V_8 . V_8 . V_238 ,
V_3 -> V_8 . V_134 ,
V_3 -> V_8 . V_6 ? L_174 : L_175 ) ;
}
}
void F_253 ( struct V_9 * V_10 ,
bool V_1251 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_6 ;
int V_37 ;
F_883 ( V_10 ) ;
F_131 (dev, crtc) {
if ( V_29 -> V_90 && V_396 . V_397 ) {
F_521 ( & V_29 -> V_8 . V_477 ,
V_29 -> V_93 ) ;
F_144 ( L_273 ,
V_29 -> V_8 . V_8 . V_238 ) ;
F_709 ( & V_29 -> V_8 . V_477 ) ;
}
}
F_531 (dev, encoder) {
F_879 ( V_6 ) ;
}
F_83 (dev_priv, pipe) {
V_29 = F_31 ( V_12 -> V_97 [ V_4 ] ) ;
F_877 ( V_29 ) ;
F_707 ( V_29 , V_29 -> V_93 ,
L_274 ) ;
}
F_702 ( V_10 ) ;
for ( V_37 = 0 ; V_37 < V_12 -> V_485 ; V_37 ++ ) {
struct V_127 * V_130 = & V_12 -> V_129 [ V_37 ] ;
if ( ! V_130 -> V_236 || V_130 -> V_90 )
continue;
F_144 ( L_275 , V_130 -> V_134 ) ;
V_130 -> V_241 ( V_12 , V_130 ) ;
V_130 -> V_236 = false ;
}
if ( F_884 ( V_10 ) )
F_885 ( V_10 ) ;
else if ( F_4 ( V_10 ) )
F_886 ( V_10 ) ;
if ( V_1251 ) {
F_881 ( V_10 ) ;
F_83 (dev_priv, pipe) {
struct V_89 * V_29 =
V_12 -> V_97 [ V_4 ] ;
F_751 ( V_29 ) ;
}
} else {
F_700 ( V_10 ) ;
}
F_447 ( V_10 ) ;
}
void F_887 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_347 ;
struct V_295 * V_296 ;
int V_298 ;
F_56 ( & V_10 -> V_299 ) ;
F_888 ( V_10 ) ;
F_58 ( & V_10 -> V_299 ) ;
if ( F_50 ( V_10 ) || F_96 ( V_10 ) )
V_12 -> V_653 . V_654 = ! ! ( F_5 ( V_174 ) &
V_796 ) ;
F_250 ( V_10 ) ;
F_889 ( V_10 ) ;
F_211 (dev, c) {
V_296 = F_184 ( V_347 -> V_91 -> V_92 ) ;
if ( V_296 == NULL )
continue;
F_56 ( & V_10 -> V_299 ) ;
V_298 = F_183 ( V_347 -> V_91 ,
V_347 -> V_91 -> V_92 ,
V_347 -> V_91 -> V_34 ,
NULL ) ;
F_58 ( & V_10 -> V_299 ) ;
if ( V_298 ) {
F_123 ( L_276 ,
F_31 ( V_347 ) -> V_4 ) ;
F_207 ( V_347 -> V_91 -> V_92 ) ;
V_347 -> V_91 -> V_92 = NULL ;
F_206 ( V_347 -> V_91 ) ;
}
}
F_890 ( V_10 ) ;
}
void F_891 ( struct V_2 * V_2 )
{
struct V_597 * V_3 = & V_2 -> V_8 ;
F_892 ( V_3 ) ;
F_893 ( V_3 ) ;
}
void F_894 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_597 * V_3 ;
F_895 ( V_10 ) ;
F_896 ( V_10 ) ;
F_897 ( V_12 ) ;
F_898 ( V_10 ) ;
F_56 ( & V_10 -> V_299 ) ;
F_899 () ;
F_360 ( V_10 ) ;
F_58 ( & V_10 -> V_299 ) ;
F_900 () ;
F_438 (connector, &dev->mode_config.connector_list, head) {
struct V_2 * V_2 ;
V_2 = F_612 ( V_3 ) ;
V_2 -> V_1252 ( V_2 ) ;
}
F_901 ( V_10 ) ;
F_902 ( V_10 ) ;
F_56 ( & V_10 -> V_299 ) ;
F_903 ( V_10 ) ;
F_58 ( & V_10 -> V_299 ) ;
}
struct V_602 * F_904 ( struct V_597 * V_3 )
{
return & F_611 ( V_3 ) -> V_8 ;
}
void F_905 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
V_3 -> V_6 = V_6 ;
F_906 ( & V_3 -> V_8 ,
& V_6 -> V_8 ) ;
}
int F_907 ( struct V_9 * V_10 , bool V_34 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned V_99 = F_45 ( V_10 ) -> V_105 >= 6 ? V_1253 : V_1254 ;
T_5 V_1255 ;
if ( F_465 ( V_12 -> V_1256 , V_99 , & V_1255 ) ) {
F_123 ( L_277 ) ;
return - V_1036 ;
}
if ( ! ! ( V_1255 & V_1257 ) == ! V_34 )
return 0 ;
if ( V_34 )
V_1255 &= ~ V_1257 ;
else
V_1255 |= V_1257 ;
if ( F_908 ( V_12 -> V_1256 , V_99 , V_1255 ) ) {
F_123 ( L_278 ) ;
return - V_1036 ;
}
return 0 ;
}
struct V_1258 *
F_909 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1258 * error ;
int V_1259 [] = {
V_252 ,
V_1260 ,
V_1261 ,
V_521 ,
} ;
int V_37 ;
if ( F_45 ( V_10 ) -> V_605 == 0 )
return NULL ;
error = F_444 ( sizeof( * error ) , V_1262 ) ;
if ( error == NULL )
return NULL ;
if ( F_225 ( V_10 ) || F_170 ( V_10 ) )
error -> V_1263 = F_5 ( V_844 ) ;
F_83 (dev_priv, i) {
error -> V_4 [ V_37 ] . V_1264 =
F_910 ( V_12 ,
F_399 ( V_37 ) ) ;
if ( ! error -> V_4 [ V_37 ] . V_1264 )
continue;
error -> V_905 [ V_37 ] . V_527 = F_5 ( F_75 ( V_37 ) ) ;
error -> V_905 [ V_37 ] . V_1265 = F_5 ( F_595 ( V_37 ) ) ;
error -> V_905 [ V_37 ] . V_8 = F_5 ( F_594 ( V_37 ) ) ;
error -> V_164 [ V_37 ] . V_527 = F_5 ( F_80 ( V_37 ) ) ;
error -> V_164 [ V_37 ] . V_342 = F_5 ( F_221 ( V_37 ) ) ;
if ( F_45 ( V_10 ) -> V_105 <= 3 ) {
error -> V_164 [ V_37 ] . V_339 = F_5 ( F_215 ( V_37 ) ) ;
error -> V_164 [ V_37 ] . V_492 = F_5 ( F_216 ( V_37 ) ) ;
}
if ( F_45 ( V_10 ) -> V_105 <= 7 && ! F_225 ( V_10 ) )
error -> V_164 [ V_37 ] . V_1022 = F_5 ( F_167 ( V_37 ) ) ;
if ( F_45 ( V_10 ) -> V_105 >= 4 ) {
error -> V_164 [ V_37 ] . V_1266 = F_5 ( F_166 ( V_37 ) ) ;
error -> V_164 [ V_37 ] . V_1267 = F_5 ( F_222 ( V_37 ) ) ;
}
error -> V_4 [ V_37 ] . V_1268 = F_5 ( F_262 ( V_37 ) ) ;
if ( F_349 ( V_10 ) )
error -> V_4 [ V_37 ] . V_1269 = F_5 ( F_911 ( V_37 ) ) ;
}
error -> V_1270 = F_45 ( V_10 ) -> V_605 ;
if ( F_62 ( V_12 -> V_10 ) )
error -> V_1270 ++ ;
for ( V_37 = 0 ; V_37 < error -> V_1270 ; V_37 ++ ) {
enum V_96 V_98 = V_1259 [ V_37 ] ;
error -> V_96 [ V_37 ] . V_1264 =
F_910 ( V_12 ,
F_78 ( V_98 ) ) ;
if ( ! error -> V_96 [ V_37 ] . V_1264 )
continue;
error -> V_96 [ V_37 ] . V_98 = V_98 ;
error -> V_96 [ V_37 ] . V_1271 = F_5 ( F_46 ( V_98 ) ) ;
error -> V_96 [ V_37 ] . V_746 = F_5 ( F_300 ( V_98 ) ) ;
error -> V_96 [ V_37 ] . V_1272 = F_5 ( F_302 ( V_98 ) ) ;
error -> V_96 [ V_37 ] . V_974 = F_5 ( F_304 ( V_98 ) ) ;
error -> V_96 [ V_37 ] . V_748 = F_5 ( F_306 ( V_98 ) ) ;
error -> V_96 [ V_37 ] . V_1273 = F_5 ( F_308 ( V_98 ) ) ;
error -> V_96 [ V_37 ] . V_976 = F_5 ( F_310 ( V_98 ) ) ;
}
return error ;
}
void
F_912 ( struct V_1274 * V_19 ,
struct V_9 * V_10 ,
struct V_1258 * error )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_37 ;
if ( ! error )
return;
F_913 ( V_19 , L_279 , F_45 ( V_10 ) -> V_605 ) ;
if ( F_225 ( V_10 ) || F_170 ( V_10 ) )
F_913 ( V_19 , L_280 ,
error -> V_1263 ) ;
F_83 (dev_priv, i) {
F_913 ( V_19 , L_281 , V_37 ) ;
F_913 ( V_19 , L_282 ,
error -> V_4 [ V_37 ] . V_1264 ? L_11 : L_12 ) ;
F_913 ( V_19 , L_283 , error -> V_4 [ V_37 ] . V_1268 ) ;
F_913 ( V_19 , L_284 , error -> V_4 [ V_37 ] . V_1269 ) ;
F_913 ( V_19 , L_285 , V_37 ) ;
F_913 ( V_19 , L_286 , error -> V_164 [ V_37 ] . V_527 ) ;
F_913 ( V_19 , L_287 , error -> V_164 [ V_37 ] . V_342 ) ;
if ( F_45 ( V_10 ) -> V_105 <= 3 ) {
F_913 ( V_19 , L_288 , error -> V_164 [ V_37 ] . V_339 ) ;
F_913 ( V_19 , L_289 , error -> V_164 [ V_37 ] . V_492 ) ;
}
if ( F_45 ( V_10 ) -> V_105 <= 7 && ! F_225 ( V_10 ) )
F_913 ( V_19 , L_290 , error -> V_164 [ V_37 ] . V_1022 ) ;
if ( F_45 ( V_10 ) -> V_105 >= 4 ) {
F_913 ( V_19 , L_291 , error -> V_164 [ V_37 ] . V_1266 ) ;
F_913 ( V_19 , L_292 , error -> V_164 [ V_37 ] . V_1267 ) ;
}
F_913 ( V_19 , L_293 , V_37 ) ;
F_913 ( V_19 , L_286 , error -> V_905 [ V_37 ] . V_527 ) ;
F_913 ( V_19 , L_289 , error -> V_905 [ V_37 ] . V_1265 ) ;
F_913 ( V_19 , L_294 , error -> V_905 [ V_37 ] . V_8 ) ;
}
for ( V_37 = 0 ; V_37 < error -> V_1270 ; V_37 ++ ) {
F_913 ( V_19 , L_295 ,
F_708 ( error -> V_96 [ V_37 ] . V_98 ) ) ;
F_913 ( V_19 , L_282 ,
error -> V_96 [ V_37 ] . V_1264 ? L_11 : L_12 ) ;
F_913 ( V_19 , L_296 , error -> V_96 [ V_37 ] . V_1271 ) ;
F_913 ( V_19 , L_297 , error -> V_96 [ V_37 ] . V_746 ) ;
F_913 ( V_19 , L_298 , error -> V_96 [ V_37 ] . V_1272 ) ;
F_913 ( V_19 , L_299 , error -> V_96 [ V_37 ] . V_974 ) ;
F_913 ( V_19 , L_300 , error -> V_96 [ V_37 ] . V_748 ) ;
F_913 ( V_19 , L_301 , error -> V_96 [ V_37 ] . V_1273 ) ;
F_913 ( V_19 , L_302 , error -> V_96 [ V_37 ] . V_976 ) ;
}
}
void F_914 ( struct V_9 * V_10 , struct V_1156 * V_1157 )
{
struct V_28 * V_29 ;
F_131 (dev, crtc) {
struct V_436 * V_437 ;
F_251 ( & V_10 -> V_393 ) ;
V_437 = V_29 -> V_394 ;
if ( V_437 && V_437 -> V_438 &&
V_437 -> V_438 -> V_8 . V_1275 == V_1157 ) {
F_210 ( V_437 -> V_438 ) ;
V_437 -> V_438 = NULL ;
}
F_252 ( & V_10 -> V_393 ) ;
}
}
