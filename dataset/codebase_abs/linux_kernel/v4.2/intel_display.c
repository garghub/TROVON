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
struct V_35 * V_3 ;
struct V_36 * V_37 ;
struct V_1 * V_6 ;
int V_38 , V_39 = 0 ;
F_13 (state, connector, connector_state, i) {
if ( V_37 -> V_29 != V_32 -> V_8 . V_29 )
continue;
V_39 ++ ;
V_6 = F_14 ( V_37 -> V_40 ) ;
if ( V_6 -> type == type )
return true ;
}
F_3 ( V_39 == 0 ) ;
return false ;
}
static const T_3 *
F_15 ( struct V_31 * V_32 , int V_18 )
{
struct V_9 * V_10 = V_32 -> V_8 . V_29 -> V_10 ;
const T_3 * V_41 ;
if ( F_12 ( V_32 , V_42 ) ) {
if ( F_16 ( V_10 ) ) {
if ( V_18 == 100000 )
V_41 = & V_43 ;
else
V_41 = & V_44 ;
} else {
if ( V_18 == 100000 )
V_41 = & V_45 ;
else
V_41 = & V_46 ;
}
} else
V_41 = & V_47 ;
return V_41 ;
}
static const T_3 *
F_17 ( struct V_31 * V_32 )
{
struct V_9 * V_10 = V_32 -> V_8 . V_29 -> V_10 ;
const T_3 * V_41 ;
if ( F_12 ( V_32 , V_42 ) ) {
if ( F_16 ( V_10 ) )
V_41 = & V_48 ;
else
V_41 = & V_49 ;
} else if ( F_12 ( V_32 , V_50 ) ||
F_12 ( V_32 , V_51 ) ) {
V_41 = & V_52 ;
} else if ( F_12 ( V_32 , V_53 ) ) {
V_41 = & V_54 ;
} else
V_41 = & V_55 ;
return V_41 ;
}
static const T_3 *
F_18 ( struct V_31 * V_32 , int V_18 )
{
struct V_9 * V_10 = V_32 -> V_8 . V_29 -> V_10 ;
const T_3 * V_41 ;
if ( F_19 ( V_10 ) )
V_41 = & V_56 ;
else if ( F_4 ( V_10 ) )
V_41 = F_15 ( V_32 , V_18 ) ;
else if ( F_20 ( V_10 ) ) {
V_41 = F_17 ( V_32 ) ;
} else if ( F_21 ( V_10 ) ) {
if ( F_12 ( V_32 , V_42 ) )
V_41 = & V_57 ;
else
V_41 = & V_58 ;
} else if ( F_22 ( V_10 ) ) {
V_41 = & V_59 ;
} else if ( F_23 ( V_10 ) ) {
V_41 = & V_60 ;
} else if ( ! F_24 ( V_10 ) ) {
if ( F_12 ( V_32 , V_42 ) )
V_41 = & V_61 ;
else
V_41 = & V_55 ;
} else {
if ( F_12 ( V_32 , V_42 ) )
V_41 = & V_62 ;
else if ( F_12 ( V_32 , V_63 ) )
V_41 = & V_64 ;
else
V_41 = & V_65 ;
}
return V_41 ;
}
static void F_25 ( int V_18 , T_2 * clock )
{
clock -> V_19 = clock -> V_21 + 2 ;
clock -> V_22 = clock -> V_23 * clock -> V_24 ;
if ( F_3 ( clock -> V_25 == 0 || clock -> V_22 == 0 ) )
return;
clock -> V_26 = F_9 ( V_18 * clock -> V_19 , clock -> V_25 ) ;
clock -> V_27 = F_9 ( clock -> V_26 , clock -> V_22 ) ;
}
static T_4 F_26 ( struct V_66 * V_66 )
{
return 5 * ( V_66 -> V_20 + 2 ) + ( V_66 -> V_21 + 2 ) ;
}
static void F_27 ( int V_18 , T_2 * clock )
{
clock -> V_19 = F_26 ( clock ) ;
clock -> V_22 = clock -> V_23 * clock -> V_24 ;
if ( F_3 ( clock -> V_25 + 2 == 0 || clock -> V_22 == 0 ) )
return;
clock -> V_26 = F_9 ( V_18 * clock -> V_19 , clock -> V_25 + 2 ) ;
clock -> V_27 = F_9 ( clock -> V_26 , clock -> V_22 ) ;
}
static void F_28 ( int V_18 , T_2 * clock )
{
clock -> V_19 = clock -> V_20 * clock -> V_21 ;
clock -> V_22 = clock -> V_23 * clock -> V_24 ;
if ( F_3 ( clock -> V_25 == 0 || clock -> V_22 == 0 ) )
return;
clock -> V_26 = F_29 ( ( V_67 ) V_18 * clock -> V_19 ,
clock -> V_25 << 22 ) ;
clock -> V_27 = F_9 ( clock -> V_26 , clock -> V_22 ) ;
}
static bool F_30 ( struct V_9 * V_10 ,
const T_3 * V_41 ,
const T_2 * clock )
{
if ( clock -> V_25 < V_41 -> V_25 . V_68 || V_41 -> V_25 . V_69 < clock -> V_25 )
F_31 ( L_1 ) ;
if ( clock -> V_23 < V_41 -> V_23 . V_68 || V_41 -> V_23 . V_69 < clock -> V_23 )
F_31 ( L_2 ) ;
if ( clock -> V_21 < V_41 -> V_21 . V_68 || V_41 -> V_21 . V_69 < clock -> V_21 )
F_31 ( L_3 ) ;
if ( clock -> V_20 < V_41 -> V_20 . V_68 || V_41 -> V_20 . V_69 < clock -> V_20 )
F_31 ( L_4 ) ;
if ( ! F_21 ( V_10 ) && ! F_23 ( V_10 ) && ! F_19 ( V_10 ) )
if ( clock -> V_20 <= clock -> V_21 )
F_31 ( L_5 ) ;
if ( ! F_23 ( V_10 ) && ! F_19 ( V_10 ) ) {
if ( clock -> V_22 < V_41 -> V_22 . V_68 || V_41 -> V_22 . V_69 < clock -> V_22 )
F_31 ( L_6 ) ;
if ( clock -> V_19 < V_41 -> V_19 . V_68 || V_41 -> V_19 . V_69 < clock -> V_19 )
F_31 ( L_7 ) ;
}
if ( clock -> V_26 < V_41 -> V_26 . V_68 || V_41 -> V_26 . V_69 < clock -> V_26 )
F_31 ( L_8 ) ;
if ( clock -> V_27 < V_41 -> V_27 . V_68 || V_41 -> V_27 . V_69 < clock -> V_27 )
F_31 ( L_9 ) ;
return true ;
}
static bool
F_32 ( const T_3 * V_41 ,
struct V_31 * V_32 ,
int V_70 , int V_18 , T_2 * V_71 ,
T_2 * V_72 )
{
struct V_28 * V_29 = F_33 ( V_32 -> V_8 . V_29 ) ;
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock ;
int V_73 = V_70 ;
if ( F_12 ( V_32 , V_42 ) ) {
if ( F_16 ( V_10 ) )
clock . V_24 = V_41 -> V_24 . V_74 ;
else
clock . V_24 = V_41 -> V_24 . V_75 ;
} else {
if ( V_70 < V_41 -> V_24 . V_76 )
clock . V_24 = V_41 -> V_24 . V_75 ;
else
clock . V_24 = V_41 -> V_24 . V_74 ;
}
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
for ( clock . V_20 = V_41 -> V_20 . V_68 ; clock . V_20 <= V_41 -> V_20 . V_69 ;
clock . V_20 ++ ) {
for ( clock . V_21 = V_41 -> V_21 . V_68 ;
clock . V_21 <= V_41 -> V_21 . V_69 ; clock . V_21 ++ ) {
if ( clock . V_21 >= clock . V_20 )
break;
for ( clock . V_25 = V_41 -> V_25 . V_68 ;
clock . V_25 <= V_41 -> V_25 . V_69 ; clock . V_25 ++ ) {
for ( clock . V_23 = V_41 -> V_23 . V_68 ;
clock . V_23 <= V_41 -> V_23 . V_69 ; clock . V_23 ++ ) {
int V_77 ;
F_27 ( V_18 , & clock ) ;
if ( ! F_30 ( V_10 , V_41 ,
& clock ) )
continue;
if ( V_71 &&
clock . V_22 != V_71 -> V_22 )
continue;
V_77 = abs ( clock . V_27 - V_70 ) ;
if ( V_77 < V_73 ) {
* V_72 = clock ;
V_73 = V_77 ;
}
}
}
}
}
return ( V_73 != V_70 ) ;
}
static bool
F_34 ( const T_3 * V_41 ,
struct V_31 * V_32 ,
int V_70 , int V_18 , T_2 * V_71 ,
T_2 * V_72 )
{
struct V_28 * V_29 = F_33 ( V_32 -> V_8 . V_29 ) ;
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock ;
int V_73 = V_70 ;
if ( F_12 ( V_32 , V_42 ) ) {
if ( F_16 ( V_10 ) )
clock . V_24 = V_41 -> V_24 . V_74 ;
else
clock . V_24 = V_41 -> V_24 . V_75 ;
} else {
if ( V_70 < V_41 -> V_24 . V_76 )
clock . V_24 = V_41 -> V_24 . V_75 ;
else
clock . V_24 = V_41 -> V_24 . V_74 ;
}
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
for ( clock . V_20 = V_41 -> V_20 . V_68 ; clock . V_20 <= V_41 -> V_20 . V_69 ;
clock . V_20 ++ ) {
for ( clock . V_21 = V_41 -> V_21 . V_68 ;
clock . V_21 <= V_41 -> V_21 . V_69 ; clock . V_21 ++ ) {
for ( clock . V_25 = V_41 -> V_25 . V_68 ;
clock . V_25 <= V_41 -> V_25 . V_69 ; clock . V_25 ++ ) {
for ( clock . V_23 = V_41 -> V_23 . V_68 ;
clock . V_23 <= V_41 -> V_23 . V_69 ; clock . V_23 ++ ) {
int V_77 ;
F_25 ( V_18 , & clock ) ;
if ( ! F_30 ( V_10 , V_41 ,
& clock ) )
continue;
if ( V_71 &&
clock . V_22 != V_71 -> V_22 )
continue;
V_77 = abs ( clock . V_27 - V_70 ) ;
if ( V_77 < V_73 ) {
* V_72 = clock ;
V_73 = V_77 ;
}
}
}
}
}
return ( V_73 != V_70 ) ;
}
static bool
F_35 ( const T_3 * V_41 ,
struct V_31 * V_32 ,
int V_70 , int V_18 , T_2 * V_71 ,
T_2 * V_72 )
{
struct V_28 * V_29 = F_33 ( V_32 -> V_8 . V_29 ) ;
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock ;
int V_78 ;
bool V_79 ;
int V_80 = ( V_70 >> 8 ) + ( V_70 >> 9 ) ;
V_79 = false ;
if ( F_12 ( V_32 , V_42 ) ) {
if ( F_16 ( V_10 ) )
clock . V_24 = V_41 -> V_24 . V_74 ;
else
clock . V_24 = V_41 -> V_24 . V_75 ;
} else {
if ( V_70 < V_41 -> V_24 . V_76 )
clock . V_24 = V_41 -> V_24 . V_75 ;
else
clock . V_24 = V_41 -> V_24 . V_74 ;
}
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_78 = V_41 -> V_25 . V_69 ;
for ( clock . V_25 = V_41 -> V_25 . V_68 ; clock . V_25 <= V_78 ; clock . V_25 ++ ) {
for ( clock . V_20 = V_41 -> V_20 . V_69 ;
clock . V_20 >= V_41 -> V_20 . V_68 ; clock . V_20 -- ) {
for ( clock . V_21 = V_41 -> V_21 . V_69 ;
clock . V_21 >= V_41 -> V_21 . V_68 ; clock . V_21 -- ) {
for ( clock . V_23 = V_41 -> V_23 . V_69 ;
clock . V_23 >= V_41 -> V_23 . V_68 ; clock . V_23 -- ) {
int V_77 ;
F_27 ( V_18 , & clock ) ;
if ( ! F_30 ( V_10 , V_41 ,
& clock ) )
continue;
V_77 = abs ( clock . V_27 - V_70 ) ;
if ( V_77 < V_80 ) {
* V_72 = clock ;
V_80 = V_77 ;
V_78 = clock . V_25 ;
V_79 = true ;
}
}
}
}
}
return V_79 ;
}
static bool F_36 ( struct V_9 * V_10 , int V_81 ,
const T_2 * V_82 ,
const T_2 * V_72 ,
unsigned int V_83 ,
unsigned int * V_84 )
{
if ( F_22 ( V_10 ) ) {
* V_84 = 0 ;
return V_82 -> V_22 > V_72 -> V_22 ;
}
if ( F_37 ( ! V_81 ) )
return false ;
* V_84 = F_38 ( 1000000ULL *
abs ( V_81 - V_82 -> V_27 ) ,
V_81 ) ;
if ( * V_84 < 100 && V_82 -> V_22 > V_72 -> V_22 ) {
* V_84 = 0 ;
return true ;
}
return * V_84 + 10 < V_83 ;
}
static bool
F_39 ( const T_3 * V_41 ,
struct V_31 * V_32 ,
int V_70 , int V_18 , T_2 * V_71 ,
T_2 * V_72 )
{
struct V_28 * V_29 = F_33 ( V_32 -> V_8 . V_29 ) ;
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock ;
unsigned int V_85 = 1000000 ;
int V_78 = V_68 ( V_41 -> V_25 . V_69 , V_18 / 19200 ) ;
bool V_79 = false ;
V_70 *= 5 ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
for ( clock . V_25 = V_41 -> V_25 . V_68 ; clock . V_25 <= V_78 ; clock . V_25 ++ ) {
for ( clock . V_23 = V_41 -> V_23 . V_69 ; clock . V_23 >= V_41 -> V_23 . V_68 ; clock . V_23 -- ) {
for ( clock . V_24 = V_41 -> V_24 . V_74 ; clock . V_24 >= V_41 -> V_24 . V_75 ;
clock . V_24 -= clock . V_24 > 10 ? 2 : 1 ) {
clock . V_22 = clock . V_23 * clock . V_24 ;
for ( clock . V_20 = V_41 -> V_20 . V_68 ; clock . V_20 <= V_41 -> V_20 . V_69 ; clock . V_20 ++ ) {
unsigned int V_86 ;
clock . V_21 = F_9 ( V_70 * clock . V_22 * clock . V_25 ,
V_18 * clock . V_20 ) ;
F_8 ( V_18 , & clock ) ;
if ( ! F_30 ( V_10 , V_41 ,
& clock ) )
continue;
if ( ! F_36 ( V_10 , V_70 ,
& clock ,
V_72 ,
V_85 , & V_86 ) )
continue;
* V_72 = clock ;
V_85 = V_86 ;
V_79 = true ;
}
}
}
}
return V_79 ;
}
static bool
F_40 ( const T_3 * V_41 ,
struct V_31 * V_32 ,
int V_70 , int V_18 , T_2 * V_71 ,
T_2 * V_72 )
{
struct V_28 * V_29 = F_33 ( V_32 -> V_8 . V_29 ) ;
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
unsigned int V_83 ;
T_2 clock ;
V_67 V_21 ;
int V_79 = false ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_83 = 1000000 ;
clock . V_25 = 1 , clock . V_20 = 2 ;
V_70 *= 5 ;
for ( clock . V_23 = V_41 -> V_23 . V_69 ; clock . V_23 >= V_41 -> V_23 . V_68 ; clock . V_23 -- ) {
for ( clock . V_24 = V_41 -> V_24 . V_74 ;
clock . V_24 >= V_41 -> V_24 . V_75 ;
clock . V_24 -= clock . V_24 > 10 ? 2 : 1 ) {
unsigned int V_84 ;
clock . V_22 = clock . V_23 * clock . V_24 ;
V_21 = F_29 ( ( ( V_67 ) V_70 * clock . V_22 *
clock . V_25 ) << 22 , V_18 * clock . V_20 ) ;
if ( V_21 > V_87 / clock . V_20 )
continue;
clock . V_21 = V_21 ;
F_28 ( V_18 , & clock ) ;
if ( ! F_30 ( V_10 , V_41 , & clock ) )
continue;
if ( ! F_36 ( V_10 , V_70 , & clock , V_72 ,
V_83 , & V_84 ) )
continue;
* V_72 = clock ;
V_83 = V_84 ;
V_79 = true ;
}
}
return V_79 ;
}
bool F_41 ( struct V_31 * V_32 , int V_88 ,
T_2 * V_72 )
{
int V_18 = F_42 ( V_32 , 0 ) ;
return F_40 ( F_18 ( V_32 , V_18 ) , V_32 ,
V_88 , V_18 , NULL , V_72 ) ;
}
bool F_43 ( struct V_89 * V_29 )
{
struct V_28 * V_28 = F_33 ( V_29 ) ;
return V_28 -> V_90 && V_29 -> V_91 -> V_34 -> V_92 &&
V_28 -> V_93 -> V_8 . V_94 . V_95 ;
}
enum V_96 F_44 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_89 * V_29 = V_12 -> V_97 [ V_4 ] ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
return V_28 -> V_93 -> V_98 ;
}
static bool F_45 ( struct V_9 * V_10 , enum V_4 V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_99 = F_46 ( V_4 ) ;
T_1 V_100 , V_101 ;
T_1 V_102 ;
if ( F_24 ( V_10 ) )
V_102 = V_103 ;
else
V_102 = V_104 ;
V_100 = F_5 ( V_99 ) & V_102 ;
F_47 ( 5 ) ;
V_101 = F_5 ( V_99 ) & V_102 ;
return V_100 == V_101 ;
}
static void F_48 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_96 V_98 = V_29 -> V_93 -> V_98 ;
enum V_4 V_4 = V_29 -> V_4 ;
if ( F_49 ( V_10 ) -> V_105 >= 4 ) {
int V_99 = F_50 ( V_98 ) ;
if ( F_51 ( ( F_5 ( V_99 ) & V_106 ) == 0 ,
100 ) )
F_52 ( 1 , L_10 ) ;
} else {
if ( F_51 ( F_45 ( V_10 , V_4 ) , 100 ) )
F_52 ( 1 , L_10 ) ;
}
}
bool F_53 ( struct V_11 * V_12 ,
struct V_107 * V_108 )
{
T_1 V_109 ;
if ( F_54 ( V_12 -> V_10 ) ) {
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
static const char * F_55 ( bool V_120 )
{
return V_120 ? L_11 : L_12 ;
}
void F_56 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_34 )
{
int V_99 ;
T_1 V_121 ;
bool V_122 ;
V_99 = F_57 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_122 = ! ! ( V_121 & V_123 ) ;
F_58 ( V_122 != V_34 ,
L_13 ,
F_55 ( V_34 ) , F_55 ( V_122 ) ) ;
}
static void F_59 ( struct V_11 * V_12 , bool V_34 )
{
T_1 V_121 ;
bool V_122 ;
F_60 ( & V_12 -> V_124 ) ;
V_121 = F_61 ( V_12 , V_125 ) ;
F_62 ( & V_12 -> V_124 ) ;
V_122 = V_121 & V_126 ;
F_58 ( V_122 != V_34 ,
L_14 ,
F_55 ( V_34 ) , F_55 ( V_122 ) ) ;
}
struct V_127 *
F_63 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
if ( V_29 -> V_93 -> V_128 < 0 )
return NULL ;
return & V_12 -> V_129 [ V_29 -> V_93 -> V_128 ] ;
}
void F_64 ( struct V_11 * V_12 ,
struct V_127 * V_130 ,
bool V_34 )
{
bool V_122 ;
struct V_131 V_132 ;
if ( F_52 ( ! V_130 ,
L_15 , F_55 ( V_34 ) ) )
return;
V_122 = V_130 -> V_133 ( V_12 , V_130 , & V_132 ) ;
F_58 ( V_122 != V_34 ,
L_16 ,
V_130 -> V_134 , F_55 ( V_34 ) , F_55 ( V_122 ) ) ;
}
static void F_65 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_34 )
{
int V_99 ;
T_1 V_121 ;
bool V_122 ;
enum V_96 V_98 = F_44 ( V_12 ,
V_4 ) ;
if ( F_66 ( V_12 -> V_10 ) ) {
V_99 = F_67 ( V_98 ) ;
V_121 = F_5 ( V_99 ) ;
V_122 = ! ! ( V_121 & V_135 ) ;
} else {
V_99 = F_68 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_122 = ! ! ( V_121 & V_136 ) ;
}
F_58 ( V_122 != V_34 ,
L_17 ,
F_55 ( V_34 ) , F_55 ( V_122 ) ) ;
}
static void F_69 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_34 )
{
int V_99 ;
T_1 V_121 ;
bool V_122 ;
V_99 = F_70 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_122 = ! ! ( V_121 & V_137 ) ;
F_58 ( V_122 != V_34 ,
L_18 ,
F_55 ( V_34 ) , F_55 ( V_122 ) ) ;
}
static void F_71 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_99 ;
T_1 V_121 ;
if ( F_49 ( V_12 -> V_10 ) -> V_105 == 5 )
return;
if ( F_66 ( V_12 -> V_10 ) )
return;
V_99 = F_68 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
F_58 ( ! ( V_121 & V_138 ) , L_19 ) ;
}
void F_72 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_34 )
{
int V_99 ;
T_1 V_121 ;
bool V_122 ;
V_99 = F_70 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_122 = ! ! ( V_121 & V_139 ) ;
F_58 ( V_122 != V_34 ,
L_20 ,
F_55 ( V_34 ) , F_55 ( V_122 ) ) ;
}
void F_73 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_140 ;
T_1 V_121 ;
enum V_4 V_141 = V_142 ;
bool V_143 = true ;
if ( F_3 ( F_66 ( V_10 ) ) )
return;
if ( F_4 ( V_10 ) ) {
T_1 V_144 ;
V_140 = V_145 ;
V_144 = F_5 ( V_146 ) & V_147 ;
if ( V_144 == V_148 &&
F_5 ( V_149 ) & V_150 )
V_141 = V_151 ;
} else if ( F_23 ( V_10 ) ) {
V_140 = F_74 ( V_4 ) ;
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
F_58 ( V_141 == V_4 && V_143 ,
L_21 ,
F_75 ( V_4 ) ) ;
}
static void F_76 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_34 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
bool V_122 ;
if ( F_77 ( V_10 ) || F_78 ( V_10 ) )
V_122 = F_5 ( V_157 ) & V_158 ;
else
V_122 = F_5 ( F_79 ( V_4 ) ) & V_159 ;
F_58 ( V_122 != V_34 ,
L_22 ,
F_75 ( V_4 ) , F_55 ( V_34 ) , F_55 ( V_122 ) ) ;
}
void F_80 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_34 )
{
int V_99 ;
T_1 V_121 ;
bool V_122 ;
enum V_96 V_98 = F_44 ( V_12 ,
V_4 ) ;
if ( ( V_4 == V_142 && V_12 -> V_160 & V_161 ) ||
( V_4 == V_151 && V_12 -> V_160 & V_162 ) )
V_34 = true ;
if ( ! F_81 ( V_12 ,
F_82 ( V_98 ) ) ) {
V_122 = false ;
} else {
V_99 = F_50 ( V_98 ) ;
V_121 = F_5 ( V_99 ) ;
V_122 = ! ! ( V_121 & V_163 ) ;
}
F_58 ( V_122 != V_34 ,
L_23 ,
F_75 ( V_4 ) , F_55 ( V_34 ) , F_55 ( V_122 ) ) ;
}
static void F_83 ( struct V_11 * V_12 ,
enum V_164 V_164 , bool V_34 )
{
int V_99 ;
T_1 V_121 ;
bool V_122 ;
V_99 = F_84 ( V_164 ) ;
V_121 = F_5 ( V_99 ) ;
V_122 = ! ! ( V_121 & V_165 ) ;
F_58 ( V_122 != V_34 ,
L_24 ,
F_85 ( V_164 ) , F_55 ( V_34 ) , F_55 ( V_122 ) ) ;
}
static void F_86 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_99 , V_38 ;
T_1 V_121 ;
int V_166 ;
if ( F_49 ( V_10 ) -> V_105 >= 4 ) {
V_99 = F_84 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
F_58 ( V_121 & V_165 ,
L_25 ,
F_85 ( V_4 ) ) ;
return;
}
F_87 (dev_priv, i) {
V_99 = F_84 ( V_38 ) ;
V_121 = F_5 ( V_99 ) ;
V_166 = ( V_121 & V_167 ) >>
V_168 ;
F_58 ( ( V_121 & V_165 ) && V_4 == V_166 ,
L_26 ,
F_85 ( V_38 ) , F_75 ( V_4 ) ) ;
}
}
static void F_88 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_99 , V_169 ;
T_1 V_121 ;
if ( F_49 ( V_10 ) -> V_105 >= 9 ) {
F_89 (dev_priv, pipe, sprite) {
V_121 = F_5 ( F_90 ( V_4 , V_169 ) ) ;
F_58 ( V_121 & V_170 ,
L_27 ,
V_169 , F_75 ( V_4 ) ) ;
}
} else if ( F_23 ( V_10 ) ) {
F_89 (dev_priv, pipe, sprite) {
V_99 = F_91 ( V_4 , V_169 ) ;
V_121 = F_5 ( V_99 ) ;
F_58 ( V_121 & V_171 ,
L_28 ,
F_92 ( V_4 , V_169 ) , F_75 ( V_4 ) ) ;
}
} else if ( F_49 ( V_10 ) -> V_105 >= 7 ) {
V_99 = F_93 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
F_58 ( V_121 & V_172 ,
L_28 ,
F_85 ( V_4 ) , F_75 ( V_4 ) ) ;
} else if ( F_49 ( V_10 ) -> V_105 >= 5 ) {
V_99 = F_94 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
F_58 ( V_121 & V_173 ,
L_28 ,
F_85 ( V_4 ) , F_75 ( V_4 ) ) ;
}
}
static void F_95 ( struct V_89 * V_29 )
{
if ( F_96 ( F_97 ( V_29 ) == 0 ) )
F_98 ( V_29 ) ;
}
static void F_99 ( struct V_11 * V_12 )
{
T_1 V_121 ;
bool V_120 ;
F_96 ( ! ( F_54 ( V_12 -> V_10 ) || F_100 ( V_12 -> V_10 ) ) ) ;
V_121 = F_5 ( V_174 ) ;
V_120 = ! ! ( V_121 & ( V_175 | V_176 |
V_177 ) ) ;
F_58 ( ! V_120 , L_29 ) ;
}
static void F_101 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_99 ;
T_1 V_121 ;
bool V_120 ;
V_99 = F_102 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_120 = ! ! ( V_121 & V_178 ) ;
F_58 ( V_120 ,
L_30 ,
F_75 ( V_4 ) ) ;
}
static bool F_103 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_144 , T_1 V_121 )
{
if ( ( V_121 & V_179 ) == 0 )
return false ;
if ( F_100 ( V_12 -> V_10 ) ) {
T_1 V_180 = F_104 ( V_4 ) ;
T_1 V_181 = F_5 ( V_180 ) ;
if ( ( V_181 & V_182 ) != V_144 )
return false ;
} else if ( F_22 ( V_12 -> V_10 ) ) {
if ( ( V_121 & V_183 ) != F_105 ( V_4 ) )
return false ;
} else {
if ( ( V_121 & V_184 ) != ( V_4 << 30 ) )
return false ;
}
return true ;
}
static bool F_106 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_121 )
{
if ( ( V_121 & V_185 ) == 0 )
return false ;
if ( F_100 ( V_12 -> V_10 ) ) {
if ( ( V_121 & V_186 ) != F_107 ( V_4 ) )
return false ;
} else if ( F_22 ( V_12 -> V_10 ) ) {
if ( ( V_121 & V_187 ) != F_108 ( V_4 ) )
return false ;
} else {
if ( ( V_121 & V_188 ) != F_109 ( V_4 ) )
return false ;
}
return true ;
}
static bool F_110 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_121 )
{
if ( ( V_121 & V_189 ) == 0 )
return false ;
if ( F_100 ( V_12 -> V_10 ) ) {
if ( ( V_121 & V_190 ) != F_111 ( V_4 ) )
return false ;
} else {
if ( ( V_121 & V_191 ) != F_112 ( V_4 ) )
return false ;
}
return true ;
}
static bool F_113 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_121 )
{
if ( ( V_121 & V_192 ) == 0 )
return false ;
if ( F_100 ( V_12 -> V_10 ) ) {
if ( ( V_121 & V_190 ) != F_111 ( V_4 ) )
return false ;
} else {
if ( ( V_121 & V_193 ) != F_114 ( V_4 ) )
return false ;
}
return true ;
}
static void F_115 ( struct V_11 * V_12 ,
enum V_4 V_4 , int V_99 , T_1 V_144 )
{
T_1 V_121 = F_5 ( V_99 ) ;
F_58 ( F_103 ( V_12 , V_4 , V_144 , V_121 ) ,
L_31 ,
V_99 , F_75 ( V_4 ) ) ;
F_58 ( F_54 ( V_12 -> V_10 ) && ( V_121 & V_179 ) == 0
&& ( V_121 & V_194 ) ,
L_32 ) ;
}
static void F_116 ( struct V_11 * V_12 ,
enum V_4 V_4 , int V_99 )
{
T_1 V_121 = F_5 ( V_99 ) ;
F_58 ( F_106 ( V_12 , V_4 , V_121 ) ,
L_33 ,
V_99 , F_75 ( V_4 ) ) ;
F_58 ( F_54 ( V_12 -> V_10 ) && ( V_121 & V_185 ) == 0
&& ( V_121 & V_195 ) ,
L_34 ) ;
}
static void F_117 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_99 ;
T_1 V_121 ;
F_115 ( V_12 , V_4 , V_196 , V_197 ) ;
F_115 ( V_12 , V_4 , V_198 , V_199 ) ;
F_115 ( V_12 , V_4 , V_200 , V_201 ) ;
V_99 = V_202 ;
V_121 = F_5 ( V_99 ) ;
F_58 ( F_113 ( V_12 , V_4 , V_121 ) ,
L_35 ,
F_75 ( V_4 ) ) ;
V_99 = V_149 ;
V_121 = F_5 ( V_99 ) ;
F_58 ( F_110 ( V_12 , V_4 , V_121 ) ,
L_36 ,
F_75 ( V_4 ) ) ;
F_116 ( V_12 , V_4 , V_203 ) ;
F_116 ( V_12 , V_4 , V_204 ) ;
F_116 ( V_12 , V_4 , V_205 ) ;
}
static void F_118 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_23 ( V_10 ) )
return;
if ( F_22 ( V_10 ) ) {
F_119 ( V_206 ) = V_207 ;
F_119 ( V_208 ) = V_209 ;
} else {
F_119 ( V_206 ) = V_209 ;
}
}
static void F_120 ( struct V_28 * V_29 ,
const struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_99 = F_57 ( V_29 -> V_4 ) ;
T_1 V_66 = V_210 -> V_211 . V_66 ;
F_121 ( V_12 , V_29 -> V_4 ) ;
F_122 ( ! F_23 ( V_12 -> V_10 ) ) ;
if ( F_123 ( V_12 -> V_10 ) )
F_73 ( V_12 , V_29 -> V_4 ) ;
F_124 ( V_99 , V_66 ) ;
F_125 ( V_99 ) ;
F_126 ( 150 ) ;
if ( F_51 ( ( ( F_5 ( V_99 ) & V_212 ) == V_212 ) , 1 ) )
F_127 ( L_37 , V_29 -> V_4 ) ;
F_124 ( F_128 ( V_29 -> V_4 ) , V_210 -> V_211 . V_213 ) ;
F_125 ( F_128 ( V_29 -> V_4 ) ) ;
F_124 ( V_99 , V_66 ) ;
F_125 ( V_99 ) ;
F_126 ( 150 ) ;
F_124 ( V_99 , V_66 ) ;
F_125 ( V_99 ) ;
F_126 ( 150 ) ;
F_124 ( V_99 , V_66 ) ;
F_125 ( V_99 ) ;
F_126 ( 150 ) ;
}
static void F_129 ( struct V_28 * V_29 ,
const struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
enum V_214 V_108 = F_130 ( V_4 ) ;
T_1 V_215 ;
F_121 ( V_12 , V_29 -> V_4 ) ;
F_122 ( ! F_22 ( V_12 -> V_10 ) ) ;
F_60 ( & V_12 -> V_124 ) ;
V_215 = F_131 ( V_12 , V_4 , F_132 ( V_108 ) ) ;
V_215 |= V_216 ;
F_133 ( V_12 , V_4 , F_132 ( V_108 ) , V_215 ) ;
F_62 ( & V_12 -> V_124 ) ;
F_126 ( 1 ) ;
F_124 ( F_57 ( V_4 ) , V_210 -> V_211 . V_66 ) ;
if ( F_51 ( ( ( F_5 ( F_57 ( V_4 ) ) & V_212 ) == V_212 ) , 1 ) )
F_127 ( L_38 , V_4 ) ;
F_124 ( F_128 ( V_4 ) , V_210 -> V_211 . V_213 ) ;
F_125 ( F_128 ( V_4 ) ) ;
}
static int F_134 ( struct V_9 * V_10 )
{
struct V_28 * V_29 ;
int V_217 = 0 ;
F_135 (dev, crtc)
V_217 += V_29 -> V_90 &&
F_10 ( V_29 , V_63 ) ;
return V_217 ;
}
static void F_136 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_99 = F_57 ( V_29 -> V_4 ) ;
T_1 V_66 = V_29 -> V_93 -> V_211 . V_66 ;
F_121 ( V_12 , V_29 -> V_4 ) ;
F_122 ( F_49 ( V_10 ) -> V_105 >= 5 ) ;
if ( F_123 ( V_10 ) && ! F_137 ( V_10 ) )
F_73 ( V_12 , V_29 -> V_4 ) ;
if ( F_137 ( V_10 ) && F_134 ( V_10 ) > 0 ) {
V_66 |= V_218 ;
F_124 ( F_57 ( ! V_29 -> V_4 ) ,
F_5 ( F_57 ( ! V_29 -> V_4 ) ) | V_218 ) ;
}
F_125 ( V_99 ) ;
F_126 ( 150 ) ;
if ( F_49 ( V_10 ) -> V_105 >= 4 ) {
F_124 ( F_128 ( V_29 -> V_4 ) ,
V_29 -> V_93 -> V_211 . V_213 ) ;
} else {
F_124 ( V_99 , V_66 ) ;
}
F_124 ( V_99 , V_66 ) ;
F_125 ( V_99 ) ;
F_126 ( 150 ) ;
F_124 ( V_99 , V_66 ) ;
F_125 ( V_99 ) ;
F_126 ( 150 ) ;
F_124 ( V_99 , V_66 ) ;
F_125 ( V_99 ) ;
F_126 ( 150 ) ;
}
static void F_138 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
if ( F_137 ( V_10 ) &&
F_10 ( V_29 , V_63 ) &&
F_134 ( V_10 ) == 1 ) {
F_124 ( F_57 ( V_151 ) ,
F_5 ( F_57 ( V_151 ) ) & ~ V_218 ) ;
F_124 ( F_57 ( V_142 ) ,
F_5 ( F_57 ( V_142 ) ) & ~ V_218 ) ;
}
if ( ( V_4 == V_142 && V_12 -> V_160 & V_161 ) ||
( V_4 == V_151 && V_12 -> V_160 & V_162 ) )
return;
F_121 ( V_12 , V_4 ) ;
F_124 ( F_57 ( V_4 ) , 0 ) ;
F_125 ( F_57 ( V_4 ) ) ;
}
static void F_139 ( struct V_11 * V_12 , enum V_4 V_4 )
{
T_1 V_121 = 0 ;
F_121 ( V_12 , V_4 ) ;
if ( V_4 == V_151 )
V_121 = V_219 | V_220 ;
F_124 ( F_57 ( V_4 ) , V_121 ) ;
F_125 ( F_57 ( V_4 ) ) ;
}
static void F_140 ( struct V_11 * V_12 , enum V_4 V_4 )
{
enum V_214 V_108 = F_130 ( V_4 ) ;
T_1 V_121 ;
F_121 ( V_12 , V_4 ) ;
V_121 = V_221 | V_220 ;
if ( V_4 != V_142 )
V_121 |= V_219 ;
F_124 ( F_57 ( V_4 ) , V_121 ) ;
F_125 ( F_57 ( V_4 ) ) ;
F_60 ( & V_12 -> V_124 ) ;
V_121 = F_131 ( V_12 , V_4 , F_132 ( V_108 ) ) ;
V_121 &= ~ V_216 ;
F_133 ( V_12 , V_4 , F_132 ( V_108 ) , V_121 ) ;
if ( V_4 != V_151 ) {
V_121 = F_131 ( V_12 , V_4 , V_222 ) ;
V_121 &= ~ ( V_223 | V_224 ) ;
F_133 ( V_12 , V_4 , V_222 , V_121 ) ;
} else {
V_121 = F_131 ( V_12 , V_4 , V_225 ) ;
V_121 &= ~ ( V_226 | V_227 ) ;
F_133 ( V_12 , V_4 , V_225 , V_121 ) ;
}
F_62 ( & V_12 -> V_124 ) ;
}
void F_141 ( struct V_11 * V_12 ,
struct V_107 * V_228 ,
unsigned int V_229 )
{
T_1 V_230 ;
int V_231 ;
switch ( V_228 -> V_108 ) {
case V_110 :
V_230 = V_232 ;
V_231 = F_57 ( 0 ) ;
break;
case V_112 :
V_230 = V_233 ;
V_231 = F_57 ( 0 ) ;
V_229 <<= 4 ;
break;
case V_114 :
V_230 = V_234 ;
V_231 = V_235 ;
break;
default:
F_142 () ;
}
if ( F_51 ( ( F_5 ( V_231 ) & V_230 ) == V_229 , 1000 ) )
F_52 ( 1 , L_39 ,
F_143 ( V_228 -> V_108 ) , F_5 ( V_231 ) & V_230 , V_229 ) ;
}
static void F_144 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_127 * V_130 = F_63 ( V_29 ) ;
if ( F_3 ( V_130 == NULL ) )
return;
F_3 ( ! V_130 -> V_93 . V_236 ) ;
if ( V_130 -> V_90 == 0 ) {
F_145 ( L_40 , V_130 -> V_134 ) ;
F_3 ( V_130 -> V_237 ) ;
F_146 ( V_12 , V_130 ) ;
V_130 -> V_238 ( V_12 , V_130 ) ;
}
}
static void F_147 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_127 * V_130 = F_63 ( V_29 ) ;
if ( F_3 ( V_130 == NULL ) )
return;
if ( F_3 ( V_130 -> V_93 . V_236 == 0 ) )
return;
F_148 ( L_41 ,
V_130 -> V_134 , V_130 -> V_90 , V_130 -> V_237 ,
V_29 -> V_8 . V_8 . V_239 ) ;
if ( V_130 -> V_90 ++ ) {
F_3 ( ! V_130 -> V_237 ) ;
F_149 ( V_12 , V_130 ) ;
return;
}
F_3 ( V_130 -> V_237 ) ;
F_150 ( V_12 , V_240 ) ;
F_148 ( L_42 , V_130 -> V_134 ) ;
V_130 -> V_241 ( V_12 , V_130 ) ;
V_130 -> V_237 = true ;
}
static void F_151 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_127 * V_130 = F_63 ( V_29 ) ;
F_122 ( F_49 ( V_10 ) -> V_105 < 5 ) ;
if ( F_3 ( V_130 == NULL ) )
return;
if ( F_3 ( V_130 -> V_93 . V_236 == 0 ) )
return;
F_148 ( L_43 ,
V_130 -> V_134 , V_130 -> V_90 , V_130 -> V_237 ,
V_29 -> V_8 . V_8 . V_239 ) ;
if ( F_3 ( V_130 -> V_90 == 0 ) ) {
F_146 ( V_12 , V_130 ) ;
return;
}
F_149 ( V_12 , V_130 ) ;
F_3 ( ! V_130 -> V_237 ) ;
if ( -- V_130 -> V_90 )
return;
F_148 ( L_44 , V_130 -> V_134 ) ;
V_130 -> V_242 ( V_12 , V_130 ) ;
V_130 -> V_237 = false ;
F_152 ( V_12 , V_240 ) ;
}
static void F_153 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_89 * V_29 = V_12 -> V_97 [ V_4 ] ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
T_4 V_99 , V_121 , V_243 ;
F_122 ( ! F_4 ( V_10 ) ) ;
F_149 ( V_12 ,
F_63 ( V_28 ) ) ;
F_154 ( V_12 , V_4 ) ;
F_155 ( V_12 , V_4 ) ;
if ( F_100 ( V_10 ) ) {
V_99 = F_156 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_121 |= V_244 ;
F_124 ( V_99 , V_121 ) ;
}
V_99 = F_102 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_243 = F_5 ( F_50 ( V_4 ) ) ;
if ( F_54 ( V_12 -> V_10 ) ) {
V_121 &= ~ V_245 ;
V_121 |= V_243 & V_245 ;
}
V_121 &= ~ V_246 ;
if ( ( V_243 & V_247 ) == V_248 )
if ( F_54 ( V_12 -> V_10 ) &&
F_10 ( V_28 , V_53 ) )
V_121 |= V_249 ;
else
V_121 |= V_250 ;
else
V_121 |= V_251 ;
F_124 ( V_99 , V_121 | V_178 ) ;
if ( F_51 ( F_5 ( V_99 ) & V_252 , 100 ) )
F_127 ( L_45 , F_75 ( V_4 ) ) ;
}
static void F_157 ( struct V_11 * V_12 ,
enum V_96 V_98 )
{
T_1 V_121 , V_243 ;
F_122 ( ! F_4 ( V_12 -> V_10 ) ) ;
F_154 ( V_12 , (enum V_4 ) V_98 ) ;
F_155 ( V_12 , V_253 ) ;
V_121 = F_5 ( V_254 ) ;
V_121 |= V_244 ;
F_124 ( V_254 , V_121 ) ;
V_121 = V_178 ;
V_243 = F_5 ( F_50 ( V_98 ) ) ;
if ( ( V_243 & V_255 ) ==
V_248 )
V_121 |= V_250 ;
else
V_121 |= V_251 ;
F_124 ( V_256 , V_121 ) ;
if ( F_51 ( F_5 ( V_256 ) & V_252 , 100 ) )
F_127 ( L_46 ) ;
}
static void F_158 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_99 , V_121 ;
F_159 ( V_12 , V_4 ) ;
F_160 ( V_12 , V_4 ) ;
F_117 ( V_12 , V_4 ) ;
V_99 = F_102 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_121 &= ~ V_178 ;
F_124 ( V_99 , V_121 ) ;
if ( F_51 ( ( F_5 ( V_99 ) & V_252 ) == 0 , 50 ) )
F_127 ( L_47 , F_75 ( V_4 ) ) ;
if ( ! F_54 ( V_10 ) ) {
V_99 = F_156 ( V_4 ) ;
V_121 = F_5 ( V_99 ) ;
V_121 &= ~ V_244 ;
F_124 ( V_99 , V_121 ) ;
}
}
static void F_161 ( struct V_11 * V_12 )
{
T_1 V_121 ;
V_121 = F_5 ( V_256 ) ;
V_121 &= ~ V_178 ;
F_124 ( V_256 , V_121 ) ;
if ( F_51 ( ( F_5 ( V_256 ) & V_252 ) == 0 , 50 ) )
F_127 ( L_48 ) ;
V_121 = F_5 ( V_254 ) ;
V_121 &= ~ V_244 ;
F_124 ( V_254 , V_121 ) ;
}
static void F_162 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
enum V_96 V_98 = F_44 ( V_12 ,
V_4 ) ;
enum V_4 V_257 ;
int V_99 ;
T_1 V_121 ;
F_86 ( V_12 , V_4 ) ;
F_163 ( V_12 , V_4 ) ;
F_88 ( V_12 , V_4 ) ;
if ( F_164 ( V_12 -> V_10 ) )
V_257 = V_253 ;
else
V_257 = V_4 ;
if ( F_165 ( V_12 -> V_10 ) )
if ( F_10 ( V_29 , V_258 ) )
F_166 ( V_12 ) ;
else
F_167 ( V_12 , V_4 ) ;
else {
if ( V_29 -> V_93 -> V_259 ) {
F_168 ( V_12 , V_257 ) ;
F_71 ( V_12 ,
(enum V_4 ) V_98 ) ;
}
}
V_99 = F_50 ( V_98 ) ;
V_121 = F_5 ( V_99 ) ;
if ( V_121 & V_163 ) {
F_3 ( ! ( ( V_4 == V_142 && V_12 -> V_160 & V_161 ) ||
( V_4 == V_151 && V_12 -> V_160 & V_162 ) ) ) ;
return;
}
F_124 ( V_99 , V_121 | V_163 ) ;
F_125 ( V_99 ) ;
}
static void F_169 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
enum V_96 V_98 = V_29 -> V_93 -> V_98 ;
enum V_4 V_4 = V_29 -> V_4 ;
int V_99 ;
T_1 V_121 ;
F_86 ( V_12 , V_4 ) ;
F_163 ( V_12 , V_4 ) ;
F_88 ( V_12 , V_4 ) ;
V_99 = F_50 ( V_98 ) ;
V_121 = F_5 ( V_99 ) ;
if ( ( V_121 & V_163 ) == 0 )
return;
if ( V_29 -> V_93 -> V_260 )
V_121 &= ~ V_261 ;
if ( ! ( V_4 == V_142 && V_12 -> V_160 & V_161 ) &&
! ( V_4 == V_151 && V_12 -> V_160 & V_162 ) )
V_121 &= ~ V_163 ;
F_124 ( V_99 , V_121 ) ;
if ( ( V_121 & V_163 ) == 0 )
F_48 ( V_29 ) ;
}
static void F_170 ( struct V_262 * V_164 ,
struct V_89 * V_29 )
{
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
F_171 ( V_12 , V_28 -> V_4 ) ;
F_172 ( V_164 -> V_34 ) -> V_263 = true ;
V_12 -> V_264 . V_265 ( V_29 , V_164 -> V_92 ,
V_29 -> V_266 , V_29 -> V_267 ) ;
}
static bool F_173 ( struct V_9 * V_10 )
{
#ifdef F_174
if ( F_49 ( V_10 ) -> V_105 >= 6 && V_268 )
return true ;
#endif
return false ;
}
unsigned int
F_175 ( struct V_9 * V_10 , T_4 V_269 ,
V_67 V_270 )
{
unsigned int V_271 ;
T_4 V_272 ;
switch ( V_270 ) {
case V_273 :
V_271 = 1 ;
break;
case V_274 :
V_271 = F_24 ( V_10 ) ? 16 : 8 ;
break;
case V_275 :
V_271 = 32 ;
break;
case V_276 :
V_272 = F_176 ( V_269 , 0 ) ;
switch ( V_272 ) {
default:
case 1 :
V_271 = 64 ;
break;
case 2 :
case 4 :
V_271 = 32 ;
break;
case 8 :
V_271 = 16 ;
break;
case 16 :
F_177 ( 1 ,
L_49 ) ;
V_271 = 16 ;
break;
}
break;
default:
F_178 ( V_270 ) ;
V_271 = 1 ;
break;
}
return V_271 ;
}
unsigned int
F_179 ( struct V_9 * V_10 , unsigned int V_277 ,
T_4 V_269 , V_67 V_270 )
{
return F_180 ( V_277 , F_175 ( V_10 , V_269 ,
V_270 ) ) ;
}
static int
F_181 ( struct V_278 * V_279 , struct V_280 * V_92 ,
const struct V_281 * V_282 )
{
struct V_283 * V_284 = & V_279 -> V_285 ;
* V_279 = V_286 ;
if ( ! V_282 )
return 0 ;
if ( ! F_182 ( V_282 -> V_287 ) )
return 0 ;
* V_279 = V_288 ;
V_284 -> V_277 = V_92 -> V_277 ;
V_284 -> V_269 = V_92 -> V_269 ;
V_284 -> V_289 = V_92 -> V_290 [ 0 ] ;
V_284 -> V_291 = V_92 -> V_292 [ 0 ] ;
return 0 ;
}
int
F_183 ( struct V_262 * V_164 ,
struct V_280 * V_92 ,
const struct V_281 * V_282 ,
struct V_293 * V_294 )
{
struct V_9 * V_10 = V_92 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_295 * V_296 = F_184 ( V_92 ) ;
struct V_278 V_279 ;
T_1 V_297 ;
int V_298 ;
F_3 ( ! F_185 ( & V_10 -> V_299 ) ) ;
switch ( V_92 -> V_292 [ 0 ] ) {
case V_273 :
if ( F_49 ( V_10 ) -> V_105 >= 9 )
V_297 = 256 * 1024 ;
else if ( F_186 ( V_10 ) || F_187 ( V_10 ) )
V_297 = 128 * 1024 ;
else if ( F_49 ( V_10 ) -> V_105 >= 4 )
V_297 = 4 * 1024 ;
else
V_297 = 64 * 1024 ;
break;
case V_274 :
if ( F_49 ( V_10 ) -> V_105 >= 9 )
V_297 = 256 * 1024 ;
else {
V_297 = 0 ;
}
break;
case V_275 :
case V_276 :
if ( F_177 ( F_49 ( V_10 ) -> V_105 < 9 ,
L_50 ) )
return - V_300 ;
V_297 = 1 * 1024 * 1024 ;
break;
default:
F_178 ( V_92 -> V_292 [ 0 ] ) ;
return - V_300 ;
}
V_298 = F_181 ( & V_279 , V_92 , V_282 ) ;
if ( V_298 )
return V_298 ;
if ( F_173 ( V_10 ) && V_297 < 256 * 1024 )
V_297 = 256 * 1024 ;
F_188 ( V_12 ) ;
V_12 -> V_301 . V_302 = false ;
V_298 = F_189 ( V_296 , V_297 , V_294 ,
& V_279 ) ;
if ( V_298 )
goto V_303;
V_298 = F_190 ( V_296 ) ;
if ( V_298 )
goto V_304;
F_191 ( V_296 ) ;
V_12 -> V_301 . V_302 = true ;
F_192 ( V_12 ) ;
return 0 ;
V_304:
F_193 ( V_296 , & V_279 ) ;
V_303:
V_12 -> V_301 . V_302 = true ;
F_192 ( V_12 ) ;
return V_298 ;
}
static void F_194 ( struct V_280 * V_92 ,
const struct V_281 * V_282 )
{
struct V_295 * V_296 = F_184 ( V_92 ) ;
struct V_278 V_279 ;
int V_298 ;
F_3 ( ! F_185 ( & V_296 -> V_8 . V_10 -> V_299 ) ) ;
V_298 = F_181 ( & V_279 , V_92 , V_282 ) ;
F_177 ( V_298 , L_51 ) ;
F_195 ( V_296 ) ;
F_193 ( V_296 , & V_279 ) ;
}
unsigned long F_196 ( int * V_266 , int * V_267 ,
unsigned int V_305 ,
unsigned int V_306 ,
unsigned int V_289 )
{
if ( V_305 != V_307 ) {
unsigned int V_308 , V_309 ;
V_308 = * V_267 / 8 ;
* V_267 %= 8 ;
V_309 = * V_266 / ( 512 / V_306 ) ;
* V_266 %= 512 / V_306 ;
return V_308 * V_289 * 8 + V_309 * 4096 ;
} else {
unsigned int V_310 ;
V_310 = * V_267 * V_289 + * V_266 * V_306 ;
* V_267 = 0 ;
* V_266 = ( V_310 & 4095 ) / V_306 ;
return V_310 & - 4096 ;
}
}
static int F_197 ( int V_311 )
{
switch ( V_311 ) {
case V_312 :
return V_313 ;
case V_314 :
return V_315 ;
case V_316 :
return V_317 ;
default:
case V_318 :
return V_319 ;
case V_320 :
return V_321 ;
case V_322 :
return V_323 ;
case V_324 :
return V_325 ;
}
}
static int F_198 ( int V_311 , bool V_326 , bool V_327 )
{
switch ( V_311 ) {
case V_328 :
return V_317 ;
default:
case V_329 :
if ( V_326 ) {
if ( V_327 )
return V_330 ;
else
return V_321 ;
} else {
if ( V_327 )
return V_331 ;
else
return V_319 ;
}
case V_332 :
if ( V_326 )
return V_325 ;
else
return V_323 ;
}
}
static bool
F_199 ( struct V_28 * V_29 ,
struct V_333 * V_334 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_295 * V_296 = NULL ;
struct V_335 V_336 = { 0 } ;
struct V_280 * V_92 = & V_334 -> V_92 -> V_8 ;
T_1 V_337 = F_200 ( V_334 -> V_8 , V_338 ) ;
T_1 V_339 = F_201 ( V_334 -> V_8 + V_334 -> V_340 ,
V_338 ) ;
V_339 -= V_337 ;
if ( V_334 -> V_340 == 0 )
return false ;
V_296 = F_202 ( V_10 ,
V_337 ,
V_337 ,
V_339 ) ;
if ( ! V_296 )
return false ;
V_296 -> V_305 = V_334 -> V_341 ;
if ( V_296 -> V_305 == V_342 )
V_296 -> V_343 = V_92 -> V_290 [ 0 ] ;
V_336 . V_269 = V_92 -> V_269 ;
V_336 . V_344 = V_92 -> V_344 ;
V_336 . V_277 = V_92 -> V_277 ;
V_336 . V_290 [ 0 ] = V_92 -> V_290 [ 0 ] ;
V_336 . V_292 [ 0 ] = V_92 -> V_292 [ 0 ] ;
V_336 . V_345 = V_346 ;
F_60 ( & V_10 -> V_299 ) ;
if ( F_203 ( V_10 , F_204 ( V_92 ) ,
& V_336 , V_296 ) ) {
F_148 ( L_52 ) ;
goto V_347;
}
F_62 ( & V_10 -> V_299 ) ;
F_148 ( L_53 , V_296 ) ;
return true ;
V_347:
F_205 ( & V_296 -> V_8 ) ;
F_62 ( & V_10 -> V_299 ) ;
return false ;
}
static void
F_206 ( struct V_262 * V_164 )
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
struct V_333 * V_334 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_348 ;
struct V_28 * V_38 ;
struct V_295 * V_296 ;
struct V_262 * V_91 = V_28 -> V_8 . V_91 ;
struct V_280 * V_92 ;
if ( ! V_334 -> V_92 )
return;
if ( F_199 ( V_28 , V_334 ) ) {
V_92 = & V_334 -> V_92 -> V_8 ;
goto V_349;
}
F_210 ( V_334 -> V_92 ) ;
F_211 (dev, c) {
V_38 = F_33 ( V_348 ) ;
if ( V_348 == & V_28 -> V_8 )
continue;
if ( ! V_38 -> V_90 )
continue;
V_92 = V_348 -> V_91 -> V_92 ;
if ( ! V_92 )
continue;
V_296 = F_184 ( V_92 ) ;
if ( F_212 ( V_296 ) == V_334 -> V_8 ) {
F_208 ( V_92 ) ;
goto V_349;
}
}
return;
V_349:
V_296 = F_184 ( V_92 ) ;
if ( V_296 -> V_305 != V_307 )
V_12 -> V_350 = true ;
V_91 -> V_92 = V_92 ;
V_91 -> V_34 -> V_29 = & V_28 -> V_8 ;
V_91 -> V_29 = & V_28 -> V_8 ;
F_206 ( V_91 ) ;
V_296 -> V_351 |= F_213 ( V_28 -> V_4 ) ;
}
static void F_214 ( struct V_89 * V_29 ,
struct V_280 * V_92 ,
int V_266 , int V_267 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_262 * V_91 = V_29 -> V_91 ;
bool V_263 = F_172 ( V_91 -> V_34 ) -> V_263 ;
struct V_295 * V_296 ;
int V_164 = V_28 -> V_164 ;
unsigned long V_352 ;
T_1 V_353 ;
T_1 V_99 = F_84 ( V_164 ) ;
int V_354 ;
if ( ! V_263 || ! V_92 ) {
F_124 ( V_99 , 0 ) ;
if ( F_49 ( V_10 ) -> V_105 >= 4 )
F_124 ( F_215 ( V_164 ) , 0 ) ;
else
F_124 ( F_216 ( V_164 ) , 0 ) ;
F_125 ( V_99 ) ;
return;
}
V_296 = F_184 ( V_92 ) ;
if ( F_3 ( V_296 == NULL ) )
return;
V_354 = F_176 ( V_92 -> V_269 , 0 ) ;
V_353 = V_355 ;
V_353 |= V_165 ;
if ( F_49 ( V_10 ) -> V_105 < 4 ) {
if ( V_28 -> V_4 == V_151 )
V_353 |= V_356 ;
F_124 ( F_217 ( V_164 ) ,
( ( V_28 -> V_93 -> V_357 - 1 ) << 16 ) |
( V_28 -> V_93 -> V_358 - 1 ) ) ;
F_124 ( F_218 ( V_164 ) , 0 ) ;
} else if ( F_22 ( V_10 ) && V_164 == V_359 ) {
F_124 ( F_219 ( V_164 ) ,
( ( V_28 -> V_93 -> V_357 - 1 ) << 16 ) |
( V_28 -> V_93 -> V_358 - 1 ) ) ;
F_124 ( F_220 ( V_164 ) , 0 ) ;
F_124 ( F_221 ( V_164 ) , 0 ) ;
}
switch ( V_92 -> V_269 ) {
case V_313 :
V_353 |= V_312 ;
break;
case V_315 :
V_353 |= V_314 ;
break;
case V_317 :
V_353 |= V_316 ;
break;
case V_319 :
V_353 |= V_318 ;
break;
case V_321 :
V_353 |= V_320 ;
break;
case V_323 :
V_353 |= V_322 ;
break;
case V_325 :
V_353 |= V_324 ;
break;
default:
F_142 () ;
}
if ( F_49 ( V_10 ) -> V_105 >= 4 &&
V_296 -> V_305 != V_307 )
V_353 |= V_360 ;
if ( F_20 ( V_10 ) )
V_353 |= V_361 ;
V_352 = V_267 * V_92 -> V_290 [ 0 ] + V_266 * V_354 ;
if ( F_49 ( V_10 ) -> V_105 >= 4 ) {
V_28 -> V_362 =
F_196 ( & V_266 , & V_267 , V_296 -> V_305 ,
V_354 ,
V_92 -> V_290 [ 0 ] ) ;
V_352 -= V_28 -> V_362 ;
} else {
V_28 -> V_362 = V_352 ;
}
if ( V_29 -> V_91 -> V_34 -> V_287 == F_222 ( V_363 ) ) {
V_353 |= V_364 ;
V_266 += ( V_28 -> V_93 -> V_358 - 1 ) ;
V_267 += ( V_28 -> V_93 -> V_357 - 1 ) ;
V_352 +=
( V_28 -> V_93 -> V_357 - 1 ) * V_92 -> V_290 [ 0 ] +
( V_28 -> V_93 -> V_358 - 1 ) * V_354 ;
}
F_124 ( V_99 , V_353 ) ;
F_124 ( F_223 ( V_164 ) , V_92 -> V_290 [ 0 ] ) ;
if ( F_49 ( V_10 ) -> V_105 >= 4 ) {
F_124 ( F_215 ( V_164 ) ,
F_212 ( V_296 ) + V_28 -> V_362 ) ;
F_124 ( F_224 ( V_164 ) , ( V_267 << 16 ) | V_266 ) ;
F_124 ( F_225 ( V_164 ) , V_352 ) ;
} else
F_124 ( F_216 ( V_164 ) , F_212 ( V_296 ) + V_352 ) ;
F_125 ( V_99 ) ;
}
static void F_226 ( struct V_89 * V_29 ,
struct V_280 * V_92 ,
int V_266 , int V_267 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_262 * V_91 = V_29 -> V_91 ;
bool V_263 = F_172 ( V_91 -> V_34 ) -> V_263 ;
struct V_295 * V_296 ;
int V_164 = V_28 -> V_164 ;
unsigned long V_352 ;
T_1 V_353 ;
T_1 V_99 = F_84 ( V_164 ) ;
int V_354 ;
if ( ! V_263 || ! V_92 ) {
F_124 ( V_99 , 0 ) ;
F_124 ( F_215 ( V_164 ) , 0 ) ;
F_125 ( V_99 ) ;
return;
}
V_296 = F_184 ( V_92 ) ;
if ( F_3 ( V_296 == NULL ) )
return;
V_354 = F_176 ( V_92 -> V_269 , 0 ) ;
V_353 = V_355 ;
V_353 |= V_165 ;
if ( F_227 ( V_10 ) || F_228 ( V_10 ) )
V_353 |= V_365 ;
switch ( V_92 -> V_269 ) {
case V_313 :
V_353 |= V_312 ;
break;
case V_317 :
V_353 |= V_316 ;
break;
case V_319 :
V_353 |= V_318 ;
break;
case V_321 :
V_353 |= V_320 ;
break;
case V_323 :
V_353 |= V_322 ;
break;
case V_325 :
V_353 |= V_324 ;
break;
default:
F_142 () ;
}
if ( V_296 -> V_305 != V_307 )
V_353 |= V_360 ;
if ( ! F_227 ( V_10 ) && ! F_228 ( V_10 ) )
V_353 |= V_361 ;
V_352 = V_267 * V_92 -> V_290 [ 0 ] + V_266 * V_354 ;
V_28 -> V_362 =
F_196 ( & V_266 , & V_267 , V_296 -> V_305 ,
V_354 ,
V_92 -> V_290 [ 0 ] ) ;
V_352 -= V_28 -> V_362 ;
if ( V_29 -> V_91 -> V_34 -> V_287 == F_222 ( V_363 ) ) {
V_353 |= V_364 ;
if ( ! F_227 ( V_10 ) && ! F_228 ( V_10 ) ) {
V_266 += ( V_28 -> V_93 -> V_358 - 1 ) ;
V_267 += ( V_28 -> V_93 -> V_357 - 1 ) ;
V_352 +=
( V_28 -> V_93 -> V_357 - 1 ) * V_92 -> V_290 [ 0 ] +
( V_28 -> V_93 -> V_358 - 1 ) * V_354 ;
}
}
F_124 ( V_99 , V_353 ) ;
F_124 ( F_223 ( V_164 ) , V_92 -> V_290 [ 0 ] ) ;
F_124 ( F_215 ( V_164 ) ,
F_212 ( V_296 ) + V_28 -> V_362 ) ;
if ( F_227 ( V_10 ) || F_228 ( V_10 ) ) {
F_124 ( F_229 ( V_164 ) , ( V_267 << 16 ) | V_266 ) ;
} else {
F_124 ( F_224 ( V_164 ) , ( V_267 << 16 ) | V_266 ) ;
F_124 ( F_225 ( V_164 ) , V_352 ) ;
}
F_125 ( V_99 ) ;
}
T_1 F_230 ( struct V_9 * V_10 , V_67 V_291 ,
T_4 V_269 )
{
T_1 V_366 = F_176 ( V_269 , 0 ) * 8 ;
switch ( V_291 ) {
case V_273 :
return 64 ;
case V_274 :
if ( F_49 ( V_10 ) -> V_105 == 2 )
return 128 ;
return 512 ;
case V_275 :
return 128 ;
case V_276 :
if ( V_366 == 8 )
return 64 ;
else
return 128 ;
default:
F_178 ( V_291 ) ;
return 64 ;
}
}
unsigned long F_231 ( struct V_367 * V_367 ,
struct V_295 * V_296 )
{
const struct V_278 * V_279 = & V_286 ;
if ( F_182 ( V_367 -> V_8 . V_34 -> V_287 ) )
V_279 = & V_288 ;
return F_232 ( V_296 , V_279 ) ;
}
void F_233 ( struct V_28 * V_28 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_368 * V_369 ;
int V_38 ;
if ( ! V_28 || ! V_28 -> V_93 )
return;
V_10 = V_28 -> V_8 . V_10 ;
V_12 = V_10 -> V_13 ;
V_369 = & V_28 -> V_93 -> V_369 ;
for ( V_38 = 0 ; V_38 < V_28 -> V_370 ; V_38 ++ ) {
if ( ! V_369 -> V_371 [ V_38 ] . V_372 ) {
F_124 ( F_234 ( V_28 -> V_4 , V_38 ) , 0 ) ;
F_124 ( F_235 ( V_28 -> V_4 , V_38 ) , 0 ) ;
F_124 ( F_236 ( V_28 -> V_4 , V_38 ) , 0 ) ;
F_148 ( L_54 ,
V_28 -> V_8 . V_8 . V_239 , V_28 -> V_4 , V_38 ) ;
}
}
}
T_1 F_237 ( T_4 V_269 )
{
switch ( V_269 ) {
case V_313 :
return V_373 ;
case V_317 :
return V_328 ;
case V_321 :
return V_329 | V_374 ;
case V_319 :
return V_329 ;
case V_330 :
return V_329 | V_374 |
V_375 ;
case V_331 :
return V_329 |
V_375 ;
case V_323 :
return V_332 ;
case V_325 :
return V_374 | V_332 ;
case V_376 :
return V_377 | V_378 ;
case V_379 :
return V_377 | V_380 ;
case V_381 :
return V_377 | V_382 ;
case V_383 :
return V_377 | V_384 ;
default:
F_178 ( V_269 ) ;
}
return 0 ;
}
T_1 F_238 ( V_67 V_291 )
{
switch ( V_291 ) {
case V_273 :
break;
case V_274 :
return V_385 ;
case V_275 :
return V_386 ;
case V_276 :
return V_387 ;
default:
F_178 ( V_291 ) ;
}
return 0 ;
}
T_1 F_239 ( unsigned int V_287 )
{
switch ( V_287 ) {
case F_222 ( V_388 ) :
break;
case F_222 ( V_389 ) :
return V_390 ;
case F_222 ( V_363 ) :
return V_391 ;
case F_222 ( V_392 ) :
return V_393 ;
default:
F_178 ( V_287 ) ;
}
return 0 ;
}
static void F_240 ( struct V_89 * V_29 ,
struct V_280 * V_92 ,
int V_266 , int V_267 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_262 * V_164 = V_29 -> V_91 ;
bool V_263 = F_172 ( V_164 -> V_34 ) -> V_263 ;
struct V_295 * V_296 ;
int V_4 = V_28 -> V_4 ;
T_1 V_394 , V_395 , V_343 ;
T_1 V_271 , V_396 , V_397 ;
unsigned int V_287 ;
int V_398 , V_399 ;
unsigned long V_400 ;
struct V_31 * V_32 = V_28 -> V_93 ;
struct V_401 * V_282 ;
int V_402 = 0 , V_403 = 0 , V_404 = 0 , V_405 = 0 ;
int V_406 = 0 , V_407 = 0 , V_408 = 0 , V_409 = 0 ;
int V_410 = - 1 ;
V_282 = F_172 ( V_164 -> V_34 ) ;
if ( ! V_263 || ! V_92 ) {
F_124 ( F_90 ( V_4 , 0 ) , 0 ) ;
F_124 ( F_241 ( V_4 , 0 ) , 0 ) ;
F_125 ( F_90 ( V_4 , 0 ) ) ;
return;
}
V_394 = V_170 |
V_411 |
V_412 ;
V_394 |= F_237 ( V_92 -> V_269 ) ;
V_394 |= F_238 ( V_92 -> V_292 [ 0 ] ) ;
V_394 |= V_413 ;
V_287 = V_164 -> V_34 -> V_287 ;
V_394 |= F_239 ( V_287 ) ;
V_296 = F_184 ( V_92 ) ;
V_395 = F_230 ( V_10 , V_92 -> V_292 [ 0 ] ,
V_92 -> V_269 ) ;
V_400 = F_231 ( F_242 ( V_164 ) , V_296 ) ;
if ( F_243 ( & V_282 -> V_414 ) ) {
V_410 = V_282 -> V_410 ;
V_402 = V_282 -> V_414 . V_415 >> 16 ;
V_403 = V_282 -> V_414 . y1 >> 16 ;
V_404 = F_243 ( & V_282 -> V_414 ) >> 16 ;
V_405 = F_244 ( & V_282 -> V_414 ) >> 16 ;
V_406 = V_282 -> V_416 . V_415 ;
V_407 = V_282 -> V_416 . y1 ;
V_408 = F_243 ( & V_282 -> V_416 ) ;
V_409 = F_244 ( & V_282 -> V_416 ) ;
F_3 ( V_266 != V_402 || V_267 != V_403 ) ;
} else {
V_404 = V_28 -> V_93 -> V_358 ;
V_405 = V_28 -> V_93 -> V_357 ;
}
if ( F_182 ( V_287 ) ) {
V_271 = F_175 ( V_10 , V_92 -> V_269 ,
V_92 -> V_292 [ 0 ] ) ;
V_343 = F_245 ( V_92 -> V_277 , V_271 ) ;
V_398 = V_343 * V_271 - V_267 - V_405 ;
V_399 = V_266 ;
V_397 = ( V_404 - 1 ) << 16 | ( V_405 - 1 ) ;
} else {
V_343 = V_92 -> V_290 [ 0 ] / V_395 ;
V_398 = V_266 ;
V_399 = V_267 ;
V_397 = ( V_405 - 1 ) << 16 | ( V_404 - 1 ) ;
}
V_396 = V_399 << 16 | V_398 ;
F_124 ( F_90 ( V_4 , 0 ) , V_394 ) ;
F_124 ( F_246 ( V_4 , 0 ) , V_396 ) ;
F_124 ( F_247 ( V_4 , 0 ) , V_397 ) ;
F_124 ( F_248 ( V_4 , 0 ) , V_343 ) ;
if ( V_410 >= 0 ) {
T_4 V_417 = 0 ;
F_3 ( ! V_408 || ! V_409 ) ;
V_417 = V_418 | F_249 ( 0 ) |
V_32 -> V_369 . V_371 [ V_410 ] . V_419 ;
F_124 ( F_234 ( V_4 , V_410 ) , V_417 ) ;
F_124 ( F_250 ( V_4 , V_410 ) , 0 ) ;
F_124 ( F_235 ( V_4 , V_410 ) , ( V_406 << 16 ) | V_407 ) ;
F_124 ( F_236 ( V_4 , V_410 ) , ( V_408 << 16 ) | V_409 ) ;
F_124 ( F_251 ( V_4 , 0 ) , 0 ) ;
} else {
F_124 ( F_251 ( V_4 , 0 ) , ( V_407 << 16 ) | V_406 ) ;
}
F_124 ( F_241 ( V_4 , 0 ) , V_400 ) ;
F_125 ( F_241 ( V_4 , 0 ) ) ;
}
static int
F_252 ( struct V_89 * V_29 , struct V_280 * V_92 ,
int V_266 , int V_267 , enum V_420 V_34 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_12 -> V_264 . V_421 )
V_12 -> V_264 . V_421 ( V_10 ) ;
V_12 -> V_264 . V_265 ( V_29 , V_92 , V_266 , V_267 ) ;
return 0 ;
}
static void F_253 ( struct V_9 * V_10 )
{
struct V_89 * V_29 ;
F_211 (dev, crtc) {
struct V_28 * V_28 = F_33 ( V_29 ) ;
enum V_164 V_164 = V_28 -> V_164 ;
F_254 ( V_10 , V_164 ) ;
F_255 ( V_10 , V_164 ) ;
}
}
static void F_256 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_29 ;
F_211 (dev, crtc) {
struct V_28 * V_28 = F_33 ( V_29 ) ;
F_257 ( & V_29 -> V_422 , NULL ) ;
if ( V_28 -> V_90 && V_29 -> V_91 -> V_92 )
V_12 -> V_264 . V_265 ( V_29 ,
V_29 -> V_91 -> V_92 ,
V_29 -> V_266 ,
V_29 -> V_267 ) ;
F_258 ( & V_29 -> V_422 ) ;
}
}
void F_259 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = F_260 ( V_29 -> V_8 . V_10 ) ;
if ( ! V_29 -> V_90 )
return;
F_261 ( & V_29 -> V_8 ) ;
V_12 -> V_264 . V_423 ( & V_29 -> V_8 ) ;
V_12 -> V_264 . V_424 ( & V_29 -> V_8 ) ;
F_262 ( & V_29 -> V_8 ) ;
}
void F_263 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_260 ( V_10 ) ;
struct V_28 * V_29 ;
if ( F_24 ( V_10 ) )
return;
if ( F_49 ( V_10 ) -> V_105 >= 5 || F_20 ( V_10 ) )
return;
F_264 ( V_10 ) ;
F_135 (dev, crtc) {
if ( ! V_29 -> V_90 )
continue;
F_261 ( & V_29 -> V_8 ) ;
V_12 -> V_264 . V_423 ( & V_29 -> V_8 ) ;
}
}
void F_265 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_260 ( V_10 ) ;
F_253 ( V_10 ) ;
if ( F_24 ( V_10 ) )
return;
if ( F_49 ( V_10 ) -> V_105 >= 5 || F_20 ( V_10 ) ) {
F_256 ( V_10 ) ;
return;
}
F_266 ( V_12 ) ;
F_267 ( V_12 ) ;
F_268 ( V_10 ) ;
F_269 ( & V_12 -> V_425 ) ;
if ( V_12 -> V_264 . V_426 )
V_12 -> V_264 . V_426 ( V_10 ) ;
F_270 ( & V_12 -> V_425 ) ;
F_271 ( V_10 , true ) ;
F_272 ( V_12 ) ;
F_273 ( V_10 ) ;
}
static void
F_274 ( struct V_280 * V_427 )
{
struct V_295 * V_296 = F_184 ( V_427 ) ;
struct V_11 * V_12 = F_260 ( V_296 -> V_8 . V_10 ) ;
bool V_428 = V_12 -> V_301 . V_302 ;
int V_298 ;
V_12 -> V_301 . V_302 = false ;
V_298 = F_275 ( V_296 , true ) ;
V_12 -> V_301 . V_302 = V_428 ;
F_3 ( V_298 ) ;
}
static bool F_276 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
bool V_429 ;
if ( F_277 ( & V_12 -> V_430 ) ||
V_28 -> V_431 != F_278 ( & V_12 -> V_430 . V_431 ) )
return false ;
F_269 ( & V_10 -> V_432 ) ;
V_429 = F_33 ( V_29 ) -> V_433 != NULL ;
F_270 ( & V_10 -> V_432 ) ;
return V_429 ;
}
static void F_279 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
const struct V_434 * V_94 ;
if ( ! V_435 . V_436 )
return;
V_94 = & V_29 -> V_93 -> V_8 . V_94 ;
F_124 ( F_280 ( V_29 -> V_4 ) ,
( ( V_94 -> V_437 - 1 ) << 16 ) |
( V_94 -> V_438 - 1 ) ) ;
if ( ! V_29 -> V_93 -> V_439 . V_120 &&
( F_10 ( V_29 , V_42 ) ||
F_10 ( V_29 , V_440 ) ) ) {
F_124 ( F_281 ( V_29 -> V_4 ) , 0 ) ;
F_124 ( F_282 ( V_29 -> V_4 ) , 0 ) ;
F_124 ( F_283 ( V_29 -> V_4 ) , 0 ) ;
}
V_29 -> V_93 -> V_358 = V_94 -> V_437 ;
V_29 -> V_93 -> V_357 = V_94 -> V_438 ;
}
static void F_284 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_441 ;
V_99 = F_68 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
if ( F_285 ( V_10 ) ) {
V_441 &= ~ V_442 ;
V_441 |= V_442 | V_443 ;
} else {
V_441 &= ~ V_444 ;
V_441 |= V_444 | V_443 ;
}
F_124 ( V_99 , V_441 ) ;
V_99 = F_70 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
if ( F_100 ( V_10 ) ) {
V_441 &= ~ V_445 ;
V_441 |= V_446 ;
} else {
V_441 &= ~ V_444 ;
V_441 |= V_444 ;
}
F_124 ( V_99 , V_441 | V_447 ) ;
F_125 ( V_99 ) ;
F_126 ( 1000 ) ;
if ( F_285 ( V_10 ) )
F_124 ( V_99 , F_5 ( V_99 ) | V_448 |
V_449 ) ;
}
static void F_286 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_441 , V_450 ;
F_171 ( V_12 , V_4 ) ;
V_99 = F_287 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_451 ;
V_441 &= ~ V_452 ;
F_124 ( V_99 , V_441 ) ;
F_5 ( V_99 ) ;
F_126 ( 150 ) ;
V_99 = F_68 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_453 ;
V_441 |= F_288 ( V_28 -> V_93 -> V_454 ) ;
V_441 &= ~ V_444 ;
V_441 |= V_455 ;
F_124 ( V_99 , V_441 | V_136 ) ;
V_99 = F_70 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_444 ;
V_441 |= V_455 ;
F_124 ( V_99 , V_441 | V_137 ) ;
F_125 ( V_99 ) ;
F_126 ( 150 ) ;
F_124 ( F_289 ( V_4 ) , V_456 ) ;
F_124 ( F_289 ( V_4 ) , V_456 |
V_457 ) ;
V_99 = F_290 ( V_4 ) ;
for ( V_450 = 0 ; V_450 < 5 ; V_450 ++ ) {
V_441 = F_5 ( V_99 ) ;
F_148 ( L_55 , V_441 ) ;
if ( ( V_441 & V_452 ) ) {
F_148 ( L_56 ) ;
F_124 ( V_99 , V_441 | V_452 ) ;
break;
}
}
if ( V_450 == 5 )
F_127 ( L_57 ) ;
V_99 = F_68 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_444 ;
V_441 |= V_458 ;
F_124 ( V_99 , V_441 ) ;
V_99 = F_70 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_444 ;
V_441 |= V_458 ;
F_124 ( V_99 , V_441 ) ;
F_125 ( V_99 ) ;
F_126 ( 150 ) ;
V_99 = F_290 ( V_4 ) ;
for ( V_450 = 0 ; V_450 < 5 ; V_450 ++ ) {
V_441 = F_5 ( V_99 ) ;
F_148 ( L_55 , V_441 ) ;
if ( V_441 & V_451 ) {
F_124 ( V_99 , V_441 | V_451 ) ;
F_148 ( L_58 ) ;
break;
}
}
if ( V_450 == 5 )
F_127 ( L_59 ) ;
F_148 ( L_60 ) ;
}
static void F_291 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_441 , V_38 , V_459 ;
V_99 = F_287 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_451 ;
V_441 &= ~ V_452 ;
F_124 ( V_99 , V_441 ) ;
F_125 ( V_99 ) ;
F_126 ( 150 ) ;
V_99 = F_68 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_453 ;
V_441 |= F_288 ( V_28 -> V_93 -> V_454 ) ;
V_441 &= ~ V_444 ;
V_441 |= V_455 ;
V_441 &= ~ V_460 ;
V_441 |= V_461 ;
F_124 ( V_99 , V_441 | V_136 ) ;
F_124 ( F_292 ( V_4 ) ,
V_462 | V_463 ) ;
V_99 = F_70 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
if ( F_100 ( V_10 ) ) {
V_441 &= ~ V_445 ;
V_441 |= V_464 ;
} else {
V_441 &= ~ V_444 ;
V_441 |= V_455 ;
}
F_124 ( V_99 , V_441 | V_137 ) ;
F_125 ( V_99 ) ;
F_126 ( 150 ) ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
V_99 = F_68 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_460 ;
V_441 |= V_465 [ V_38 ] ;
F_124 ( V_99 , V_441 ) ;
F_125 ( V_99 ) ;
F_126 ( 500 ) ;
for ( V_459 = 0 ; V_459 < 5 ; V_459 ++ ) {
V_99 = F_290 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
F_148 ( L_55 , V_441 ) ;
if ( V_441 & V_452 ) {
F_124 ( V_99 , V_441 | V_452 ) ;
F_148 ( L_56 ) ;
break;
}
F_126 ( 50 ) ;
}
if ( V_459 < 5 )
break;
}
if ( V_38 == 4 )
F_127 ( L_57 ) ;
V_99 = F_68 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_444 ;
V_441 |= V_458 ;
if ( F_293 ( V_10 ) ) {
V_441 &= ~ V_460 ;
V_441 |= V_461 ;
}
F_124 ( V_99 , V_441 ) ;
V_99 = F_70 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
if ( F_100 ( V_10 ) ) {
V_441 &= ~ V_445 ;
V_441 |= V_466 ;
} else {
V_441 &= ~ V_444 ;
V_441 |= V_458 ;
}
F_124 ( V_99 , V_441 ) ;
F_125 ( V_99 ) ;
F_126 ( 150 ) ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
V_99 = F_68 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_460 ;
V_441 |= V_465 [ V_38 ] ;
F_124 ( V_99 , V_441 ) ;
F_125 ( V_99 ) ;
F_126 ( 500 ) ;
for ( V_459 = 0 ; V_459 < 5 ; V_459 ++ ) {
V_99 = F_290 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
F_148 ( L_55 , V_441 ) ;
if ( V_441 & V_451 ) {
F_124 ( V_99 , V_441 | V_451 ) ;
F_148 ( L_58 ) ;
break;
}
F_126 ( 50 ) ;
}
if ( V_459 < 5 )
break;
}
if ( V_38 == 4 )
F_127 ( L_59 ) ;
F_148 ( L_61 ) ;
}
static void F_294 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_441 , V_38 , V_467 ;
V_99 = F_287 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_451 ;
V_441 &= ~ V_452 ;
F_124 ( V_99 , V_441 ) ;
F_125 ( V_99 ) ;
F_126 ( 150 ) ;
F_148 ( L_62 ,
F_5 ( F_290 ( V_4 ) ) ) ;
for ( V_467 = 0 ; V_467 < F_295 ( V_465 ) * 2 ; V_467 ++ ) {
V_99 = F_68 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ ( V_468 | V_442 ) ;
V_441 &= ~ V_136 ;
F_124 ( V_99 , V_441 ) ;
V_99 = F_70 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_468 ;
V_441 &= ~ V_445 ;
V_441 &= ~ V_137 ;
F_124 ( V_99 , V_441 ) ;
V_99 = F_68 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_453 ;
V_441 |= F_288 ( V_28 -> V_93 -> V_454 ) ;
V_441 |= V_469 ;
V_441 &= ~ V_460 ;
V_441 |= V_465 [ V_467 / 2 ] ;
V_441 |= V_470 ;
F_124 ( V_99 , V_441 | V_136 ) ;
F_124 ( F_292 ( V_4 ) ,
V_462 | V_463 ) ;
V_99 = F_70 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 |= V_464 ;
V_441 |= V_470 ;
F_124 ( V_99 , V_441 | V_137 ) ;
F_125 ( V_99 ) ;
F_126 ( 1 ) ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
V_99 = F_290 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
F_148 ( L_55 , V_441 ) ;
if ( V_441 & V_452 ||
( F_5 ( V_99 ) & V_452 ) ) {
F_124 ( V_99 , V_441 | V_452 ) ;
F_148 ( L_63 ,
V_38 ) ;
break;
}
F_126 ( 1 ) ;
}
if ( V_38 == 4 ) {
F_148 ( L_64 , V_467 / 2 ) ;
continue;
}
V_99 = F_68 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_442 ;
V_441 |= V_471 ;
F_124 ( V_99 , V_441 ) ;
V_99 = F_70 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_445 ;
V_441 |= V_466 ;
F_124 ( V_99 , V_441 ) ;
F_125 ( V_99 ) ;
F_126 ( 2 ) ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
V_99 = F_290 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
F_148 ( L_55 , V_441 ) ;
if ( V_441 & V_451 ||
( F_5 ( V_99 ) & V_451 ) ) {
F_124 ( V_99 , V_441 | V_451 ) ;
F_148 ( L_65 ,
V_38 ) ;
goto V_472;
}
F_126 ( 2 ) ;
}
if ( V_38 == 4 )
F_148 ( L_66 , V_467 / 2 ) ;
}
V_472:
F_148 ( L_61 ) ;
}
static void F_296 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_441 ;
V_99 = F_70 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ ( V_453 | ( 0x7 << 16 ) ) ;
V_441 |= F_288 ( V_28 -> V_93 -> V_454 ) ;
V_441 |= ( F_5 ( F_50 ( V_4 ) ) & V_245 ) << 11 ;
F_124 ( V_99 , V_441 | V_139 ) ;
F_125 ( V_99 ) ;
F_126 ( 200 ) ;
V_441 = F_5 ( V_99 ) ;
F_124 ( V_99 , V_441 | V_473 ) ;
F_125 ( V_99 ) ;
F_126 ( 200 ) ;
V_99 = F_68 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
if ( ( V_441 & V_138 ) == 0 ) {
F_124 ( V_99 , V_441 | V_138 ) ;
F_125 ( V_99 ) ;
F_126 ( 100 ) ;
}
}
static void F_297 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_441 ;
V_99 = F_70 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
F_124 ( V_99 , V_441 & ~ V_473 ) ;
V_99 = F_68 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
F_124 ( V_99 , V_441 & ~ V_138 ) ;
F_125 ( V_99 ) ;
F_126 ( 100 ) ;
V_99 = F_70 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
F_124 ( V_99 , V_441 & ~ V_139 ) ;
F_125 ( V_99 ) ;
F_126 ( 100 ) ;
}
static void F_298 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_441 ;
V_99 = F_68 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
F_124 ( V_99 , V_441 & ~ V_136 ) ;
F_125 ( V_99 ) ;
V_99 = F_70 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ ( 0x7 << 16 ) ;
V_441 |= ( F_5 ( F_50 ( V_4 ) ) & V_245 ) << 11 ;
F_124 ( V_99 , V_441 & ~ V_137 ) ;
F_125 ( V_99 ) ;
F_126 ( 100 ) ;
if ( F_54 ( V_10 ) )
F_124 ( F_289 ( V_4 ) , V_456 ) ;
V_99 = F_68 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ V_444 ;
V_441 |= V_455 ;
F_124 ( V_99 , V_441 ) ;
V_99 = F_70 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
if ( F_100 ( V_10 ) ) {
V_441 &= ~ V_445 ;
V_441 |= V_464 ;
} else {
V_441 &= ~ V_444 ;
V_441 |= V_455 ;
}
V_441 &= ~ ( 0x07 << 16 ) ;
V_441 |= ( F_5 ( F_50 ( V_4 ) ) & V_245 ) << 11 ;
F_124 ( V_99 , V_441 ) ;
F_125 ( V_99 ) ;
F_126 ( 100 ) ;
}
bool F_299 ( struct V_9 * V_10 )
{
struct V_28 * V_29 ;
F_135 (dev, crtc) {
if ( F_278 ( & V_29 -> V_474 ) == 0 )
continue;
if ( V_29 -> V_433 )
F_300 ( V_10 , V_29 -> V_4 ) ;
return true ;
}
return false ;
}
static void F_301 ( struct V_28 * V_28 )
{
struct V_11 * V_12 = F_260 ( V_28 -> V_8 . V_10 ) ;
struct V_475 * V_476 = V_28 -> V_433 ;
F_302 () ;
V_28 -> V_433 = NULL ;
if ( V_476 -> V_477 )
F_303 ( V_28 -> V_8 . V_10 ,
V_28 -> V_4 ,
V_476 -> V_477 ) ;
F_98 ( & V_28 -> V_8 ) ;
F_304 ( & V_12 -> V_478 ) ;
F_305 ( V_12 -> V_479 , & V_476 -> V_476 ) ;
F_306 ( V_28 -> V_164 ,
V_476 -> V_480 ) ;
}
void F_307 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_3 ( F_308 ( & V_12 -> V_478 ) ) ;
if ( F_3 ( F_309 ( V_12 -> V_478 ,
! F_276 ( V_29 ) ,
60 * V_481 ) == 0 ) ) {
struct V_28 * V_28 = F_33 ( V_29 ) ;
F_269 ( & V_10 -> V_432 ) ;
if ( V_28 -> V_433 ) {
F_177 ( 1 , L_67 ) ;
F_301 ( V_28 ) ;
}
F_270 ( & V_10 -> V_432 ) ;
}
if ( V_29 -> V_91 -> V_92 ) {
F_60 ( & V_10 -> V_299 ) ;
F_274 ( V_29 -> V_91 -> V_92 ) ;
F_62 ( & V_10 -> V_299 ) ;
}
}
static void F_310 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int clock = F_33 ( V_29 ) -> V_93 -> V_8 . V_94 . V_95 ;
T_1 V_482 , V_483 , V_484 , V_485 = 0 ;
T_1 V_441 ;
F_60 ( & V_12 -> V_124 ) ;
F_124 ( V_486 , V_487 ) ;
F_311 ( V_12 , V_488 ,
F_312 ( V_12 , V_488 , V_489 ) |
V_490 ,
V_489 ) ;
if ( clock == 20000 ) {
V_484 = 1 ;
V_482 = 0x41 ;
V_483 = 0x20 ;
} else {
T_1 V_491 = 172800 * 1000 ;
T_1 V_492 = 64 ;
T_1 V_493 , V_494 , V_495 ;
V_493 = ( V_491 / clock ) ;
V_494 = V_493 / V_492 ;
V_495 = V_493 % V_492 ;
V_484 = 0 ;
V_482 = V_494 - 2 ;
V_483 = V_495 ;
}
F_3 ( F_313 ( V_482 ) &
~ V_496 ) ;
F_3 ( F_314 ( V_485 ) &
~ V_497 ) ;
F_148 ( L_68 ,
clock ,
V_484 ,
V_482 ,
V_485 ,
V_483 ) ;
V_441 = F_312 ( V_12 , V_498 , V_489 ) ;
V_441 &= ~ V_496 ;
V_441 |= F_313 ( V_482 ) ;
V_441 &= ~ V_497 ;
V_441 |= F_315 ( V_483 ) ;
V_441 |= F_314 ( V_485 ) ;
V_441 |= V_499 ;
F_311 ( V_12 , V_498 , V_441 , V_489 ) ;
V_441 = F_312 ( V_12 , V_500 , V_489 ) ;
V_441 &= ~ F_316 ( 1 ) ;
V_441 |= F_316 ( V_484 ) ;
F_311 ( V_12 , V_500 , V_441 , V_489 ) ;
V_441 = F_312 ( V_12 , V_488 , V_489 ) ;
V_441 &= ~ V_490 ;
F_311 ( V_12 , V_488 , V_441 , V_489 ) ;
F_126 ( 24 ) ;
F_124 ( V_486 , V_501 ) ;
F_62 ( & V_12 -> V_124 ) ;
}
static void F_317 ( struct V_28 * V_29 ,
enum V_4 V_257 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_96 V_98 = V_29 -> V_93 -> V_98 ;
F_124 ( F_318 ( V_257 ) ,
F_5 ( F_319 ( V_98 ) ) ) ;
F_124 ( F_320 ( V_257 ) ,
F_5 ( F_321 ( V_98 ) ) ) ;
F_124 ( F_322 ( V_257 ) ,
F_5 ( F_323 ( V_98 ) ) ) ;
F_124 ( F_324 ( V_257 ) ,
F_5 ( F_325 ( V_98 ) ) ) ;
F_124 ( F_326 ( V_257 ) ,
F_5 ( F_327 ( V_98 ) ) ) ;
F_124 ( F_328 ( V_257 ) ,
F_5 ( F_329 ( V_98 ) ) ) ;
F_124 ( F_330 ( V_257 ) ,
F_5 ( F_331 ( V_98 ) ) ) ;
}
static void F_332 ( struct V_9 * V_10 , bool V_241 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_441 ;
V_441 = F_5 ( V_502 ) ;
if ( ! ! ( V_441 & V_503 ) == V_241 )
return;
F_3 ( F_5 ( F_70 ( V_151 ) ) & V_137 ) ;
F_3 ( F_5 ( F_70 ( V_504 ) ) & V_137 ) ;
V_441 &= ~ V_503 ;
if ( V_241 )
V_441 |= V_503 ;
F_148 ( L_69 , V_241 ? L_70 : L_71 ) ;
F_124 ( V_502 , V_441 ) ;
F_125 ( V_502 ) ;
}
static void F_333 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
switch ( V_28 -> V_4 ) {
case V_142 :
break;
case V_151 :
if ( V_28 -> V_93 -> V_454 > 2 )
F_332 ( V_10 , false ) ;
else
F_332 ( V_10 , true ) ;
break;
case V_504 :
F_332 ( V_10 , true ) ;
break;
default:
F_142 () ;
}
}
static void F_334 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_441 ;
F_101 ( V_12 , V_4 ) ;
if ( F_285 ( V_10 ) )
F_333 ( V_28 ) ;
F_124 ( F_335 ( V_4 ) ,
F_5 ( F_336 ( V_4 ) ) & V_505 ) ;
V_12 -> V_264 . V_506 ( V_29 ) ;
if ( F_100 ( V_10 ) ) {
T_1 V_507 ;
V_441 = F_5 ( V_508 ) ;
V_441 |= F_337 ( V_4 ) ;
V_507 = F_338 ( V_4 ) ;
if ( V_28 -> V_93 -> V_128 == V_509 )
V_441 |= V_507 ;
else
V_441 &= ~ V_507 ;
F_124 ( V_508 , V_441 ) ;
}
F_147 ( V_28 ) ;
F_73 ( V_12 , V_4 ) ;
F_317 ( V_28 , V_4 ) ;
F_284 ( V_29 ) ;
if ( F_100 ( V_10 ) && V_28 -> V_93 -> V_510 ) {
T_1 V_511 = ( F_5 ( F_50 ( V_4 ) ) & V_245 ) >> 5 ;
V_99 = F_104 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ ( V_182 |
V_512 |
V_513 ) ;
V_441 |= V_514 ;
V_441 |= V_511 << 9 ;
if ( V_29 -> V_419 . V_345 & V_515 )
V_441 |= V_516 ;
if ( V_29 -> V_419 . V_345 & V_517 )
V_441 |= V_518 ;
switch ( F_339 ( V_29 ) ) {
case V_196 :
V_441 |= V_197 ;
break;
case V_198 :
V_441 |= V_199 ;
break;
case V_200 :
V_441 |= V_201 ;
break;
default:
F_142 () ;
}
F_124 ( V_99 , V_441 ) ;
}
F_153 ( V_12 , V_4 ) ;
}
static void F_340 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
enum V_96 V_98 = V_28 -> V_93 -> V_98 ;
F_101 ( V_12 , V_253 ) ;
F_310 ( V_29 ) ;
F_317 ( V_28 , V_142 ) ;
F_157 ( V_12 , V_98 ) ;
}
void F_341 ( struct V_28 * V_29 )
{
struct V_127 * V_130 = F_63 ( V_29 ) ;
if ( V_130 == NULL )
return;
if ( ! ( V_130 -> V_93 . V_236 & ( 1 << V_29 -> V_4 ) ) ) {
F_52 ( 1 , L_72 , V_130 -> V_134 ) ;
return;
}
V_130 -> V_93 . V_236 &= ~ ( 1 << V_29 -> V_4 ) ;
if ( V_130 -> V_93 . V_236 == 0 ) {
F_3 ( V_130 -> V_237 ) ;
F_3 ( V_130 -> V_90 ) ;
}
V_29 -> V_93 -> V_128 = V_519 ;
}
struct V_127 * F_342 ( struct V_28 * V_29 ,
struct V_31 * V_32 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
struct V_127 * V_130 ;
enum V_520 V_38 ;
if ( F_54 ( V_12 -> V_10 ) ) {
V_38 = (enum V_520 ) V_29 -> V_4 ;
V_130 = & V_12 -> V_129 [ V_38 ] ;
F_148 ( L_73 ,
V_29 -> V_8 . V_8 . V_239 , V_130 -> V_134 ) ;
F_3 ( V_130 -> V_521 -> V_236 ) ;
goto V_79;
}
if ( F_19 ( V_12 -> V_10 ) ) {
struct V_1 * V_6 ;
struct V_107 * V_522 ;
V_6 = F_343 ( V_32 ) ;
if ( F_3 ( ! V_6 ) )
return NULL ;
V_522 = F_344 ( & V_6 -> V_8 ) ;
V_38 = (enum V_520 ) V_522 -> V_108 ;
V_130 = & V_12 -> V_129 [ V_38 ] ;
F_148 ( L_73 ,
V_29 -> V_8 . V_8 . V_239 , V_130 -> V_134 ) ;
F_3 ( V_130 -> V_521 -> V_236 ) ;
goto V_79;
}
for ( V_38 = 0 ; V_38 < V_12 -> V_523 ; V_38 ++ ) {
V_130 = & V_12 -> V_129 [ V_38 ] ;
if ( V_130 -> V_521 -> V_236 == 0 )
continue;
if ( memcmp ( & V_32 -> V_211 ,
& V_130 -> V_521 -> V_132 ,
sizeof( V_130 -> V_521 -> V_132 ) ) == 0 ) {
F_148 ( L_74 ,
V_29 -> V_8 . V_8 . V_239 , V_130 -> V_134 ,
V_130 -> V_521 -> V_236 ,
V_130 -> V_90 ) ;
goto V_79;
}
}
for ( V_38 = 0 ; V_38 < V_12 -> V_523 ; V_38 ++ ) {
V_130 = & V_12 -> V_129 [ V_38 ] ;
if ( V_130 -> V_521 -> V_236 == 0 ) {
F_148 ( L_75 ,
V_29 -> V_8 . V_8 . V_239 , V_130 -> V_134 ) ;
goto V_79;
}
}
return NULL ;
V_79:
if ( V_130 -> V_521 -> V_236 == 0 )
V_130 -> V_521 -> V_132 = V_32 -> V_211 ;
V_32 -> V_128 = V_38 ;
F_145 ( L_76 , V_130 -> V_134 ,
F_75 ( V_29 -> V_4 ) ) ;
V_130 -> V_521 -> V_236 |= 1 << V_29 -> V_4 ;
return V_130 ;
}
static int F_345 ( struct V_11 * V_12 ,
unsigned V_524 )
{
struct V_127 * V_130 ;
enum V_520 V_38 ;
for ( V_38 = 0 ; V_38 < V_12 -> V_523 ; V_38 ++ ) {
V_130 = & V_12 -> V_129 [ V_38 ] ;
V_130 -> V_521 = F_346 ( & V_130 -> V_93 , sizeof V_130 -> V_93 ,
V_525 ) ;
if ( ! V_130 -> V_521 )
goto V_526;
V_130 -> V_521 -> V_236 &= ~ V_524 ;
}
return 0 ;
V_526:
while ( -- V_38 >= 0 ) {
V_130 = & V_12 -> V_129 [ V_38 ] ;
F_210 ( V_130 -> V_521 ) ;
V_130 -> V_521 = NULL ;
}
return - V_527 ;
}
static void F_347 ( struct V_11 * V_12 )
{
struct V_127 * V_130 ;
enum V_520 V_38 ;
for ( V_38 = 0 ; V_38 < V_12 -> V_523 ; V_38 ++ ) {
V_130 = & V_12 -> V_129 [ V_38 ] ;
F_3 ( V_130 -> V_521 == & V_130 -> V_93 ) ;
V_130 -> V_93 = * V_130 -> V_521 ;
F_210 ( V_130 -> V_521 ) ;
V_130 -> V_521 = NULL ;
}
}
static void F_348 ( struct V_11 * V_12 )
{
struct V_127 * V_130 ;
enum V_520 V_38 ;
for ( V_38 = 0 ; V_38 < V_12 -> V_523 ; V_38 ++ ) {
V_130 = & V_12 -> V_129 [ V_38 ] ;
F_3 ( V_130 -> V_521 == & V_130 -> V_93 ) ;
F_210 ( V_130 -> V_521 ) ;
V_130 -> V_521 = NULL ;
}
}
static void F_349 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_528 = F_46 ( V_4 ) ;
T_1 V_441 ;
V_441 = F_5 ( V_528 ) ;
F_126 ( 500 ) ;
if ( F_51 ( F_5 ( V_528 ) != V_441 , 5 ) ) {
if ( F_51 ( F_5 ( V_528 ) != V_441 , 5 ) )
F_127 ( L_77 , F_75 ( V_4 ) ) ;
}
}
int
F_350 (
struct V_28 * V_28 , struct V_31 * V_32 ,
struct V_367 * V_367 , struct V_401 * V_282 ,
int V_529 )
{
int V_530 ;
int V_531 ;
int V_404 , V_405 , V_408 , V_409 ;
int * V_410 ;
struct V_280 * V_92 ;
struct V_368 * V_369 ;
unsigned int V_287 ;
if ( ! V_28 || ! V_32 )
return 0 ;
V_369 = & V_32 -> V_369 ;
V_531 = V_367 ? F_351 ( & V_367 -> V_8 ) : V_532 ;
V_92 = V_367 ? V_282 -> V_8 . V_92 : NULL ;
if ( V_367 ) {
V_404 = F_243 ( & V_282 -> V_414 ) >> 16 ;
V_405 = F_244 ( & V_282 -> V_414 ) >> 16 ;
V_408 = F_243 ( & V_282 -> V_416 ) ;
V_409 = F_244 ( & V_282 -> V_416 ) ;
V_410 = & V_282 -> V_410 ;
V_287 = V_282 -> V_8 . V_287 ;
} else {
struct V_434 * V_94 =
& V_32 -> V_8 . V_94 ;
V_404 = V_32 -> V_358 ;
V_405 = V_32 -> V_357 ;
V_408 = V_94 -> V_533 ;
V_409 = V_94 -> V_534 ;
V_410 = & V_369 -> V_410 ;
V_287 = V_388 ;
}
V_530 = F_182 ( V_287 ) ?
( V_405 != V_408 || V_404 != V_409 ) :
( V_404 != V_408 || V_405 != V_409 ) ;
if ( V_529 || ! V_530 || ( V_367 &&
( ! V_92 || ! V_282 -> V_263 ) ) ) {
if ( * V_410 >= 0 ) {
V_369 -> V_535 &= ~ ( 1 << V_531 ) ;
V_369 -> V_371 [ * V_410 ] . V_372 = 0 ;
F_148 ( L_78
L_79 ,
V_28 -> V_4 , * V_410 , V_367 ? L_80 : L_81 ,
V_367 ? V_367 -> V_8 . V_8 . V_239 :
V_28 -> V_8 . V_8 . V_239 , V_32 ,
V_369 -> V_535 ) ;
* V_410 = - 1 ;
}
return 0 ;
}
if ( V_404 < V_536 || V_405 < V_537 ||
V_408 < V_538 || V_409 < V_539 ||
V_404 > V_540 || V_405 > V_541 ||
V_408 > V_542 || V_409 > V_543 ) {
F_148 ( L_82
L_83 ,
V_367 ? L_80 : L_81 ,
V_367 ? V_367 -> V_8 . V_8 . V_239 : V_28 -> V_8 . V_8 . V_239 ,
V_28 -> V_4 , V_531 , V_404 , V_405 , V_408 , V_409 ) ;
return - V_300 ;
}
if ( F_3 ( V_367 &&
V_367 -> V_544 . V_345 != V_545 ) ) {
F_148 ( L_84 ,
V_367 -> V_8 . V_8 . V_239 , V_404 , V_405 , V_408 , V_409 ) ;
return - V_300 ;
}
if ( V_367 ) {
switch ( V_92 -> V_269 ) {
case V_317 :
case V_321 :
case V_319 :
case V_330 :
case V_331 :
case V_323 :
case V_325 :
case V_376 :
case V_379 :
case V_381 :
case V_383 :
break;
default:
F_148 ( L_85 ,
V_367 -> V_8 . V_8 . V_239 , V_92 -> V_8 . V_239 , V_92 -> V_269 ) ;
return - V_300 ;
}
}
V_369 -> V_535 |= ( 1 << V_531 ) ;
F_148 ( L_86
L_79 ,
V_367 ? L_80 : L_81 ,
V_367 ? V_367 -> V_8 . V_8 . V_239 : V_28 -> V_8 . V_8 . V_239 ,
V_404 , V_405 , V_408 , V_409 , V_32 , V_369 -> V_535 ) ;
return 0 ;
}
static void F_352 ( struct V_28 * V_29 , int V_241 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
struct V_368 * V_369 =
& V_29 -> V_93 -> V_369 ;
F_148 ( L_87 , V_29 -> V_93 ) ;
F_350 ( V_29 , V_29 -> V_93 , NULL , NULL , ! V_241 ) ;
F_353 ( V_29 -> V_8 . V_10 , V_29 , V_29 -> V_93 ) ;
F_233 ( V_29 ) ;
if ( ! V_241 )
return;
if ( V_29 -> V_93 -> V_439 . V_120 ) {
int V_239 ;
if ( F_3 ( V_29 -> V_93 -> V_369 . V_410 < 0 ) ) {
F_127 ( L_88 ) ;
return;
}
V_239 = V_369 -> V_410 ;
F_124 ( F_234 ( V_4 , V_239 ) , V_418 |
V_546 | V_369 -> V_371 [ V_239 ] . V_419 ) ;
F_124 ( F_235 ( V_4 , V_239 ) , V_29 -> V_93 -> V_439 . V_547 ) ;
F_124 ( F_236 ( V_4 , V_239 ) , V_29 -> V_93 -> V_439 . V_340 ) ;
F_148 ( L_89 , V_29 -> V_93 , V_239 ) ;
}
}
static void F_354 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_93 -> V_439 . V_120 ) {
if ( F_285 ( V_10 ) || F_227 ( V_10 ) )
F_124 ( F_281 ( V_4 ) , V_548 | V_549 |
F_355 ( V_4 ) ) ;
else
F_124 ( F_281 ( V_4 ) , V_548 | V_549 ) ;
F_124 ( F_282 ( V_4 ) , V_29 -> V_93 -> V_439 . V_547 ) ;
F_124 ( F_283 ( V_4 ) , V_29 -> V_93 -> V_439 . V_340 ) ;
}
}
static void F_356 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_4 V_4 = F_33 ( V_29 ) -> V_4 ;
struct V_262 * V_164 ;
struct V_367 * V_367 ;
F_357 (plane, &dev->mode_config.plane_list) {
V_367 = F_242 ( V_164 ) ;
if ( V_367 -> V_4 == V_4 )
F_358 ( & V_367 -> V_8 ) ;
}
}
void F_359 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_93 -> V_550 )
return;
F_300 ( V_10 , V_29 -> V_4 ) ;
F_360 ( V_12 , V_29 -> V_164 ) ;
if ( F_228 ( V_10 ) ) {
F_60 ( & V_12 -> V_551 . V_552 ) ;
F_3 ( F_361 ( V_12 , V_553 , 0xc0000000 ) ) ;
F_62 ( & V_12 -> V_551 . V_552 ) ;
} else {
F_124 ( V_554 , V_555 ) ;
if ( F_51 ( F_362 ( V_554 ) & V_555 , 50 ) )
F_127 ( L_90 ) ;
}
}
void F_363 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_93 -> V_550 )
return;
F_360 ( V_12 , V_29 -> V_164 ) ;
if ( F_228 ( V_10 ) ) {
F_60 ( & V_12 -> V_551 . V_552 ) ;
F_3 ( F_361 ( V_12 , V_553 , 0 ) ) ;
F_62 ( & V_12 -> V_551 . V_552 ) ;
if ( F_51 ( ( F_5 ( V_554 ) & V_555 ) == 0 , 42 ) )
F_127 ( L_91 ) ;
} else {
F_124 ( V_554 , 0 ) ;
F_125 ( V_554 ) ;
}
F_300 ( V_10 , V_29 -> V_4 ) ;
}
static void F_364 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
int V_556 = F_365 ( V_4 ) ;
int V_38 ;
bool V_557 = false ;
if ( ! V_29 -> V_34 -> V_241 || ! V_28 -> V_90 )
return;
if ( F_165 ( V_12 -> V_10 ) ) {
if ( F_10 ( V_28 , V_258 ) )
F_166 ( V_12 ) ;
else
F_167 ( V_12 , V_4 ) ;
}
if ( ! F_165 ( V_10 ) )
V_556 = F_366 ( V_4 ) ;
if ( F_227 ( V_10 ) && V_28 -> V_93 -> V_550 &&
( ( F_5 ( F_367 ( V_4 ) ) & V_558 ) ==
V_559 ) ) {
F_363 ( V_28 ) ;
V_557 = true ;
}
for ( V_38 = 0 ; V_38 < 256 ; V_38 ++ ) {
F_124 ( V_556 + 4 * V_38 ,
( V_28 -> V_560 [ V_38 ] << 16 ) |
( V_28 -> V_561 [ V_38 ] << 8 ) |
V_28 -> V_562 [ V_38 ] ) ;
}
if ( V_557 )
F_359 ( V_28 ) ;
}
static void F_368 ( struct V_28 * V_28 )
{
if ( V_28 -> V_563 ) {
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_60 ( & V_10 -> V_299 ) ;
V_12 -> V_301 . V_302 = false ;
( void ) F_369 ( V_28 -> V_563 ) ;
V_12 -> V_301 . V_302 = true ;
F_62 ( & V_10 -> V_299 ) ;
}
}
static void
F_370 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
if ( F_228 ( V_10 ) )
F_300 ( V_10 , V_4 ) ;
F_359 ( V_28 ) ;
F_60 ( & V_10 -> V_299 ) ;
F_371 ( V_10 ) ;
F_62 ( & V_10 -> V_299 ) ;
if ( F_24 ( V_10 ) )
F_372 ( V_12 , V_4 , true ) ;
if ( F_165 ( V_10 ) )
F_373 ( V_12 ) ;
}
static void
F_374 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
if ( F_24 ( V_10 ) )
F_372 ( V_12 , V_4 , false ) ;
if ( F_165 ( V_10 ) )
F_375 ( V_12 , false ) ;
F_60 ( & V_10 -> V_299 ) ;
if ( V_12 -> V_564 . V_29 == V_28 )
F_376 ( V_10 ) ;
F_62 ( & V_10 -> V_299 ) ;
F_363 ( V_28 ) ;
}
static void F_262 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
F_170 ( V_29 -> V_91 , V_29 ) ;
F_356 ( V_29 ) ;
F_377 ( V_29 , true ) ;
F_370 ( V_29 ) ;
F_378 ( V_10 , F_379 ( V_4 ) ) ;
}
static void F_261 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_367 * V_367 ;
int V_4 = V_28 -> V_4 ;
if ( ! V_28 -> V_90 )
return;
F_307 ( V_29 ) ;
F_374 ( V_29 ) ;
F_368 ( V_28 ) ;
F_380 (dev, intel_plane) {
if ( V_367 -> V_4 == V_4 ) {
struct V_89 * V_565 = V_367 -> V_8 . V_29 ;
V_367 -> V_566 ( & V_367 -> V_8 ,
V_565 ? : V_29 , true ) ;
}
}
F_378 ( V_10 , F_379 ( V_4 ) ) ;
}
static void F_381 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
F_3 ( ! V_29 -> V_34 -> V_241 ) ;
if ( V_28 -> V_90 )
return;
if ( V_28 -> V_93 -> V_259 )
F_144 ( V_28 ) ;
if ( V_28 -> V_93 -> V_510 )
F_382 ( V_28 , V_567 ) ;
F_383 ( V_28 ) ;
if ( V_28 -> V_93 -> V_259 ) {
F_384 ( V_28 ,
& V_28 -> V_93 -> V_568 , NULL ) ;
}
F_385 ( V_29 ) ;
V_28 -> V_90 = true ;
F_372 ( V_12 , V_4 , true ) ;
F_386 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_569 )
V_6 -> V_569 ( V_6 ) ;
if ( V_28 -> V_93 -> V_259 ) {
F_296 ( V_28 ) ;
} else {
F_159 ( V_12 , V_4 ) ;
F_160 ( V_12 , V_4 ) ;
}
F_354 ( V_28 ) ;
F_364 ( V_29 ) ;
F_387 ( V_29 ) ;
F_162 ( V_28 ) ;
if ( V_28 -> V_93 -> V_259 )
F_334 ( V_29 ) ;
F_95 ( V_29 ) ;
F_388 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_241 ( V_6 ) ;
if ( F_100 ( V_10 ) )
F_349 ( V_10 , V_28 -> V_4 ) ;
}
static bool F_389 ( struct V_28 * V_29 )
{
return F_390 ( V_29 -> V_8 . V_10 ) && V_29 -> V_4 == V_142 ;
}
static void F_391 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_28 * V_570 , * V_571 = NULL ;
F_135 (dev, crtc_it) {
if ( ! V_570 -> V_90 || V_570 == V_29 )
continue;
if ( V_571 )
return;
V_571 = V_570 ;
}
if ( ! V_571 )
return;
F_300 ( V_10 , V_571 -> V_4 ) ;
F_300 ( V_10 , V_571 -> V_4 ) ;
}
static void F_392 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
F_3 ( ! V_29 -> V_34 -> V_241 ) ;
if ( V_28 -> V_90 )
return;
if ( F_63 ( V_28 ) )
F_147 ( V_28 ) ;
if ( V_28 -> V_93 -> V_510 )
F_382 ( V_28 , V_567 ) ;
F_383 ( V_28 ) ;
if ( V_28 -> V_93 -> V_98 != V_572 ) {
F_124 ( F_393 ( V_28 -> V_93 -> V_98 ) ,
V_28 -> V_93 -> V_573 - 1 ) ;
}
if ( V_28 -> V_93 -> V_259 ) {
F_384 ( V_28 ,
& V_28 -> V_93 -> V_568 , NULL ) ;
}
F_394 ( V_29 ) ;
F_395 ( V_29 ) ;
V_28 -> V_90 = true ;
F_372 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_569 )
V_6 -> V_569 ( V_6 ) ;
if ( V_28 -> V_93 -> V_259 ) {
F_386 ( V_12 , V_253 ,
true ) ;
V_12 -> V_264 . V_506 ( V_29 ) ;
}
F_396 ( V_28 ) ;
if ( F_49 ( V_10 ) -> V_105 == 9 )
F_352 ( V_28 , 1 ) ;
else if ( F_49 ( V_10 ) -> V_105 < 9 )
F_354 ( V_28 ) ;
else
F_178 ( F_49 ( V_10 ) -> V_105 ) ;
F_364 ( V_29 ) ;
F_397 ( V_29 ) ;
F_398 ( V_29 ) ;
F_387 ( V_29 ) ;
F_162 ( V_28 ) ;
if ( V_28 -> V_93 -> V_259 )
F_340 ( V_29 ) ;
if ( V_28 -> V_93 -> V_574 )
F_399 ( V_29 , true ) ;
F_95 ( V_29 ) ;
F_388 ( V_29 ) ;
F_11 (dev, crtc, encoder) {
V_6 -> V_241 ( V_6 ) ;
F_400 ( V_6 , true ) ;
}
F_391 ( V_28 ) ;
}
static void F_401 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_93 -> V_439 . V_120 ) {
F_124 ( F_281 ( V_4 ) , 0 ) ;
F_124 ( F_282 ( V_4 ) , 0 ) ;
F_124 ( F_283 ( V_4 ) , 0 ) ;
}
}
static void F_402 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
T_1 V_99 , V_441 ;
if ( ! V_28 -> V_90 )
return;
F_11 (dev, crtc, encoder)
V_6 -> V_242 ( V_6 ) ;
F_403 ( V_29 ) ;
F_95 ( V_29 ) ;
if ( V_28 -> V_93 -> V_259 )
F_386 ( V_12 , V_4 , false ) ;
F_169 ( V_28 ) ;
F_401 ( V_28 ) ;
if ( V_28 -> V_93 -> V_259 )
F_298 ( V_29 ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_575 )
V_6 -> V_575 ( V_6 ) ;
if ( V_28 -> V_93 -> V_259 ) {
F_158 ( V_12 , V_4 ) ;
if ( F_100 ( V_10 ) ) {
V_99 = F_104 ( V_4 ) ;
V_441 = F_5 ( V_99 ) ;
V_441 &= ~ ( V_514 |
V_182 ) ;
V_441 |= V_576 ;
F_124 ( V_99 , V_441 ) ;
V_441 = F_5 ( V_508 ) ;
V_441 &= ~ ( F_337 ( V_4 ) | F_338 ( V_4 ) ) ;
F_124 ( V_508 , V_441 ) ;
}
F_151 ( V_28 ) ;
F_297 ( V_28 ) ;
}
V_28 -> V_90 = false ;
F_387 ( V_29 ) ;
F_60 ( & V_10 -> V_299 ) ;
F_371 ( V_10 ) ;
F_62 ( & V_10 -> V_299 ) ;
}
static void F_404 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_1 * V_6 ;
enum V_96 V_98 = V_28 -> V_93 -> V_98 ;
if ( ! V_28 -> V_90 )
return;
F_11 (dev, crtc, encoder) {
F_400 ( V_6 , false ) ;
V_6 -> V_242 ( V_6 ) ;
}
F_403 ( V_29 ) ;
F_95 ( V_29 ) ;
if ( V_28 -> V_93 -> V_259 )
F_386 ( V_12 , V_253 ,
false ) ;
F_169 ( V_28 ) ;
if ( V_28 -> V_93 -> V_574 )
F_399 ( V_29 , false ) ;
F_405 ( V_12 , V_98 ) ;
if ( F_49 ( V_10 ) -> V_105 == 9 )
F_352 ( V_28 , 0 ) ;
else if ( F_49 ( V_10 ) -> V_105 < 9 )
F_401 ( V_28 ) ;
else
F_178 ( F_49 ( V_10 ) -> V_105 ) ;
F_406 ( V_28 ) ;
if ( V_28 -> V_93 -> V_259 ) {
F_161 ( V_12 ) ;
F_407 ( V_29 ) ;
}
F_11 (dev, crtc, encoder)
if ( V_6 -> V_575 )
V_6 -> V_575 ( V_6 ) ;
V_28 -> V_90 = false ;
F_387 ( V_29 ) ;
F_60 ( & V_10 -> V_299 ) ;
F_371 ( V_10 ) ;
F_62 ( & V_10 -> V_299 ) ;
if ( F_63 ( V_28 ) )
F_151 ( V_28 ) ;
}
static void F_408 ( struct V_89 * V_29 )
{
struct V_28 * V_28 = F_33 ( V_29 ) ;
F_341 ( V_28 ) ;
}
static void F_409 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_31 * V_210 = V_29 -> V_93 ;
if ( ! V_210 -> V_577 . V_578 )
return;
F_3 ( F_5 ( V_579 ) & V_580 ) ;
F_121 ( V_12 , V_29 -> V_4 ) ;
F_124 ( V_581 , V_210 -> V_577 . V_582 ) ;
F_124 ( V_579 , V_210 -> V_577 . V_578 ) ;
F_124 ( F_410 ( V_29 -> V_4 ) , 0 ) ;
}
static enum V_583 F_411 ( enum V_108 V_108 )
{
switch ( V_108 ) {
case V_584 :
return V_585 ;
case V_110 :
return V_586 ;
case V_112 :
return V_587 ;
case V_114 :
return V_588 ;
default:
F_37 ( 1 ) ;
return V_589 ;
}
}
enum V_583
F_412 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_8 . V_10 ;
struct V_107 * V_522 ;
switch ( V_1 -> type ) {
case V_590 :
F_37 ( ! F_66 ( V_10 ) ) ;
case V_591 :
case V_50 :
case V_440 :
V_522 = F_344 ( & V_1 -> V_8 ) ;
return F_411 ( V_522 -> V_108 ) ;
case V_592 :
V_522 = F_413 ( & V_1 -> V_8 ) -> V_91 ;
return F_411 ( V_522 -> V_108 ) ;
case V_51 :
return V_593 ;
case V_258 :
return V_594 ;
default:
return V_589 ;
}
}
static unsigned long F_414 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_1 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
unsigned long V_595 ;
enum V_96 V_96 ;
V_96 = F_44 ( V_10 -> V_13 , V_4 ) ;
V_595 = F_222 ( F_415 ( V_4 ) ) ;
V_595 |= F_222 ( F_82 ( V_96 ) ) ;
if ( V_28 -> V_93 -> V_439 . V_120 ||
V_28 -> V_93 -> V_439 . V_596 )
V_595 |= F_222 ( F_416 ( V_4 ) ) ;
F_11 (dev, crtc, intel_encoder)
V_595 |= F_222 ( F_412 ( V_1 ) ) ;
return V_595 ;
}
static void F_417 ( struct V_33 * V_34 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned long V_597 [ V_598 ] = { 0 , } ;
struct V_28 * V_29 ;
F_135 (dev, crtc) {
enum V_583 V_599 ;
if ( ! V_29 -> V_8 . V_34 -> V_241 )
continue;
V_597 [ V_29 -> V_4 ] = F_414 ( & V_29 -> V_8 ) ;
F_418 (domain, pipe_domains[crtc->pipe])
F_150 ( V_12 , V_599 ) ;
}
if ( V_12 -> V_264 . V_600 )
V_12 -> V_264 . V_600 ( V_34 ) ;
F_135 (dev, crtc) {
enum V_583 V_599 ;
F_418 (domain, crtc->enabled_power_domains)
F_152 ( V_12 , V_599 ) ;
V_29 -> V_601 = V_597 [ V_29 -> V_4 ] ;
}
F_419 ( V_12 , false ) ;
}
void F_420 ( struct V_9 * V_10 , int V_602 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_603 ;
T_4 V_604 ;
T_4 V_605 ;
int V_298 ;
switch ( V_602 ) {
case 144000 :
V_603 = V_606 ;
V_604 = F_421 ( 60 ) ;
break;
case 288000 :
V_603 = V_607 ;
V_604 = F_421 ( 60 ) ;
break;
case 384000 :
V_603 = V_608 ;
V_604 = F_421 ( 60 ) ;
break;
case 576000 :
V_603 = V_609 ;
V_604 = F_421 ( 60 ) ;
break;
case 624000 :
V_603 = V_609 ;
V_604 = F_421 ( 65 ) ;
break;
case 19200 :
V_604 = 0 ;
V_603 = 0 ;
break;
default:
F_127 ( L_92 , V_602 ) ;
return;
}
F_60 ( & V_12 -> V_551 . V_552 ) ;
V_298 = F_361 ( V_12 , V_610 ,
0x80000000 ) ;
F_62 ( & V_12 -> V_551 . V_552 ) ;
if ( V_298 ) {
F_127 ( L_93 ,
V_298 , V_602 ) ;
return;
}
V_605 = F_5 ( V_611 ) & V_612 ;
V_605 = V_605 * 500 + 1000 ;
if ( V_602 == 19200 || V_602 == 624000 ||
V_605 == 624000 ) {
F_124 ( V_613 , ~ V_614 ) ;
if ( F_51 ( ! ( F_5 ( V_613 ) & V_615 ) ,
1 ) )
F_127 ( L_94 ) ;
}
if ( V_602 != 19200 ) {
T_4 V_121 ;
V_121 = F_5 ( V_616 ) ;
V_121 &= ~ V_617 ;
V_121 |= V_604 ;
F_124 ( V_616 , V_121 ) ;
F_124 ( V_613 , V_614 ) ;
if ( F_51 ( F_5 ( V_613 ) & V_615 , 1 ) )
F_127 ( L_95 ) ;
V_121 = F_5 ( V_611 ) ;
V_121 &= ~ V_618 ;
V_121 |= V_603 ;
V_121 &= ~ V_619 ;
if ( V_602 >= 500000 )
V_121 |= V_619 ;
V_121 &= ~ V_612 ;
V_121 |= ( V_602 - 1000 ) / 500 ;
F_124 ( V_611 , V_121 ) ;
}
F_60 ( & V_12 -> V_551 . V_552 ) ;
V_298 = F_361 ( V_12 , V_610 ,
F_245 ( V_602 , 25000 ) ) ;
F_62 ( & V_12 -> V_551 . V_552 ) ;
if ( V_298 ) {
F_127 ( L_96 ,
V_298 , V_602 ) ;
return;
}
V_12 -> V_620 = V_602 ;
}
void F_422 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_121 ;
V_121 = F_5 ( V_621 ) ;
V_121 &= ~ V_622 ;
F_124 ( V_621 , V_121 ) ;
F_150 ( V_12 , V_240 ) ;
if ( F_5 ( V_613 ) & V_614 ) {
F_148 ( L_97 ) ;
return;
}
F_420 ( V_10 , 624000 ) ;
F_124 ( V_623 , F_5 ( V_623 ) | V_624 ) ;
F_125 ( V_623 ) ;
F_126 ( 10 ) ;
if ( ! ( F_5 ( V_623 ) & V_625 ) )
F_127 ( L_98 ) ;
}
void F_423 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
F_124 ( V_623 , F_5 ( V_623 ) & ~ V_624 ) ;
F_125 ( V_623 ) ;
F_126 ( 10 ) ;
if ( F_5 ( V_623 ) & V_625 )
F_127 ( L_99 ) ;
F_420 ( V_10 , 19200 ) ;
F_152 ( V_12 , V_240 ) ;
}
static unsigned int F_424 ( unsigned int V_626 )
{
return ( V_626 - 1000 ) / 500 ;
}
static unsigned int F_425 ( unsigned int V_626 )
{
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < F_295 ( V_627 ) ; V_38 ++ ) {
const struct V_628 * V_629 = & V_627 [ V_38 ] ;
if ( V_629 -> V_626 == V_626 )
return V_629 -> V_26 ;
}
return 8100 ;
}
static void
F_426 ( struct V_11 * V_12 , unsigned int V_630 )
{
unsigned int V_631 ;
T_1 V_121 ;
V_121 = F_5 ( V_611 ) ;
V_121 &= ~ V_632 | ~ V_612 ;
V_121 |= V_633 ;
if ( V_630 == 8640 )
V_631 = 308570 ;
else
V_631 = 337500 ;
V_121 = V_633 | F_424 ( V_631 ) ;
F_124 ( V_611 , V_121 ) ;
F_125 ( V_611 ) ;
V_121 = F_5 ( V_634 ) ;
V_121 &= ~ ( F_427 ( V_635 ) | F_428 ( V_635 ) |
F_429 ( V_635 ) ) ;
V_121 |= F_430 ( V_635 ) ;
if ( V_630 == 8640 )
V_121 |= F_431 ( V_636 ,
V_635 ) ;
else
V_121 |= F_431 ( V_637 ,
V_635 ) ;
F_124 ( V_634 , V_121 ) ;
F_125 ( V_634 ) ;
F_124 ( V_638 , F_5 ( V_638 ) | V_639 ) ;
if ( F_51 ( F_5 ( V_638 ) & V_640 , 5 ) )
F_127 ( L_100 ) ;
}
static bool F_432 ( struct V_11 * V_12 )
{
int V_298 ;
T_1 V_121 ;
V_121 = V_641 ;
F_60 ( & V_12 -> V_551 . V_552 ) ;
V_298 = F_433 ( V_12 , V_642 , & V_121 ) ;
F_62 ( & V_12 -> V_551 . V_552 ) ;
return V_298 == 0 && ( V_121 & V_643 ) ;
}
static bool F_434 ( struct V_11 * V_12 )
{
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < 15 ; V_38 ++ ) {
if ( F_432 ( V_12 ) )
return true ;
F_126 ( 10 ) ;
}
return false ;
}
static void F_435 ( struct V_11 * V_12 , unsigned int V_626 )
{
T_1 V_644 , V_645 ;
F_145 ( L_101 , V_626 ) ;
if ( ! F_434 ( V_12 ) ) {
F_127 ( L_102 ) ;
return;
}
switch( V_626 ) {
case 450000 :
case 432000 :
V_644 = V_646 ;
V_645 = 1 ;
break;
case 540000 :
V_644 = V_647 ;
V_645 = 2 ;
break;
case 308570 :
case 337500 :
default:
V_644 = V_633 ;
V_645 = 0 ;
break;
case 617140 :
case 675000 :
V_644 = V_648 ;
V_645 = 3 ;
break;
}
F_124 ( V_611 , V_644 | F_424 ( V_626 ) ) ;
F_125 ( V_611 ) ;
F_60 ( & V_12 -> V_551 . V_552 ) ;
F_361 ( V_12 , V_642 , V_645 ) ;
F_62 ( & V_12 -> V_551 . V_552 ) ;
}
void F_436 ( struct V_11 * V_12 )
{
F_124 ( V_623 , F_5 ( V_623 ) & ~ V_624 ) ;
F_125 ( V_623 ) ;
F_126 ( 10 ) ;
if ( F_5 ( V_623 ) & V_625 )
F_127 ( L_103 ) ;
F_124 ( V_638 , F_5 ( V_638 ) & ~ V_639 ) ;
if ( F_51 ( ! ( F_5 ( V_638 ) & V_640 ) , 1 ) )
F_127 ( L_104 ) ;
F_152 ( V_12 , V_240 ) ;
}
void F_437 ( struct V_11 * V_12 )
{
T_1 V_121 ;
unsigned int V_630 ;
V_121 = F_5 ( V_621 ) ;
F_124 ( V_621 , V_121 | V_622 ) ;
F_150 ( V_12 , V_240 ) ;
if ( F_5 ( V_638 ) & V_639 ) {
F_145 ( L_105 ) ;
return;
}
V_630 = F_425 ( V_12 -> V_649 ) ;
F_426 ( V_12 , V_630 ) ;
F_435 ( V_12 , V_12 -> V_649 ) ;
F_124 ( V_623 , F_5 ( V_623 ) | V_624 ) ;
F_125 ( V_623 ) ;
F_126 ( 10 ) ;
if ( ! ( F_5 ( V_623 ) & V_625 ) )
F_127 ( L_106 ) ;
}
static int F_438 ( struct V_11 * V_12 )
{
int V_650 , V_651 [] = { 800 , 1600 , 2000 , 2400 } ;
F_60 ( & V_12 -> V_124 ) ;
V_650 = F_61 ( V_12 , V_652 ) &
V_653 ;
F_62 ( & V_12 -> V_124 ) ;
return V_651 [ V_650 ] * 1000 ;
}
static void F_439 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_620 = V_12 -> V_264 . V_654 ( V_10 ) ;
F_145 ( L_107 ,
V_12 -> V_620 ) ;
F_124 ( V_655 , F_245 ( V_12 -> V_620 , 1000 ) ) ;
}
static void F_440 ( struct V_9 * V_10 , int V_656 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_121 , V_657 ;
F_3 ( V_12 -> V_264 . V_654 ( V_10 )
!= V_12 -> V_620 ) ;
if ( V_656 >= 320000 )
V_657 = 2 ;
else if ( V_656 == 266667 )
V_657 = 1 ;
else
V_657 = 0 ;
F_60 ( & V_12 -> V_551 . V_552 ) ;
V_121 = F_441 ( V_12 , V_658 ) ;
V_121 &= ~ V_659 ;
V_121 |= ( V_657 << V_660 ) ;
F_442 ( V_12 , V_658 , V_121 ) ;
if ( F_51 ( ( F_441 ( V_12 , V_658 ) &
V_661 ) == ( V_657 << V_662 ) ,
50 ) ) {
F_127 ( L_108 ) ;
}
F_62 ( & V_12 -> V_551 . V_552 ) ;
F_60 ( & V_12 -> V_124 ) ;
if ( V_656 == 400000 ) {
T_1 V_603 ;
V_603 = F_9 ( V_12 -> V_650 << 1 , V_656 ) - 1 ;
V_121 = F_61 ( V_12 , V_663 ) ;
V_121 &= ~ V_664 ;
V_121 |= V_603 ;
F_443 ( V_12 , V_663 , V_121 ) ;
if ( F_51 ( ( F_61 ( V_12 , V_663 ) &
V_665 ) == ( V_603 << V_666 ) ,
50 ) )
F_127 ( L_108 ) ;
}
V_121 = F_444 ( V_12 , V_667 ) ;
V_121 &= ~ 0x7f ;
if ( V_656 == 400000 )
V_121 |= 4500 / 250 ;
else
V_121 |= 3000 / 250 ;
F_445 ( V_12 , V_667 , V_121 ) ;
F_62 ( & V_12 -> V_124 ) ;
F_439 ( V_10 ) ;
}
static void F_446 ( struct V_9 * V_10 , int V_656 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_121 , V_657 ;
F_3 ( V_12 -> V_264 . V_654 ( V_10 )
!= V_12 -> V_620 ) ;
switch ( V_656 ) {
case 333333 :
case 320000 :
case 266667 :
case 200000 :
break;
default:
F_178 ( V_656 ) ;
return;
}
V_657 = F_9 ( V_12 -> V_650 << 1 , V_656 ) - 1 ;
F_60 ( & V_12 -> V_551 . V_552 ) ;
V_121 = F_441 ( V_12 , V_658 ) ;
V_121 &= ~ V_668 ;
V_121 |= ( V_657 << V_669 ) ;
F_442 ( V_12 , V_658 , V_121 ) ;
if ( F_51 ( ( F_441 ( V_12 , V_658 ) &
V_670 ) == ( V_657 << V_671 ) ,
50 ) ) {
F_127 ( L_108 ) ;
}
F_62 ( & V_12 -> V_551 . V_552 ) ;
F_439 ( V_10 ) ;
}
static int F_447 ( struct V_11 * V_12 ,
int V_672 )
{
int V_673 = ( V_12 -> V_650 << 1 ) % 320000 != 0 ? 333333 : 320000 ;
int V_41 = F_22 ( V_12 ) ? 95 : 90 ;
if ( ! F_22 ( V_12 ) &&
V_672 > V_673 * V_41 / 100 )
return 400000 ;
else if ( V_672 > 266667 * V_41 / 100 )
return V_673 ;
else if ( V_672 > 0 )
return 266667 ;
else
return 200000 ;
}
static int F_448 ( struct V_11 * V_12 ,
int V_672 )
{
if ( V_672 > 576000 * 9 / 10 )
return 624000 ;
else if ( V_672 > 384000 * 9 / 10 )
return 576000 ;
else if ( V_672 > 288000 * 9 / 10 )
return 384000 ;
else if ( V_672 > 144000 * 9 / 10 )
return 288000 ;
else
return 144000 ;
}
static int F_449 ( struct V_9 * V_10 ,
struct V_33 * V_34 )
{
struct V_28 * V_28 ;
struct V_31 * V_32 ;
int V_672 = 0 ;
F_135 (dev, intel_crtc) {
if ( V_34 )
V_32 =
F_450 ( V_34 , V_28 ) ;
else
V_32 = V_28 -> V_93 ;
if ( F_451 ( V_32 ) )
return F_452 ( V_32 ) ;
if ( ! V_32 -> V_8 . V_241 )
continue;
V_672 = V_69 ( V_672 ,
V_32 -> V_8 . V_94 . V_95 ) ;
}
return V_672 ;
}
static int F_453 ( struct V_33 * V_34 )
{
struct V_11 * V_12 = F_260 ( V_34 -> V_10 ) ;
struct V_89 * V_29 ;
struct V_674 * V_32 ;
int V_672 = F_449 ( V_34 -> V_10 , V_34 ) ;
int V_656 , V_38 ;
if ( V_672 < 0 )
return V_672 ;
if ( F_23 ( V_12 ) )
V_656 = F_447 ( V_12 , V_672 ) ;
else
V_656 = F_448 ( V_12 , V_672 ) ;
if ( V_656 == V_12 -> V_620 )
return 0 ;
F_211 (state->dev, crtc) {
if ( ! V_29 -> V_34 -> V_241 )
continue;
V_32 = F_454 ( V_34 , V_29 ) ;
if ( F_451 ( V_32 ) )
return F_452 ( V_32 ) ;
}
F_455 (state, crtc, crtc_state, i)
if ( V_32 -> V_241 )
V_32 -> V_675 = true ;
return 0 ;
}
static void F_456 ( struct V_11 * V_12 )
{
unsigned int V_676 , V_677 ;
if ( F_22 ( V_12 ) )
V_677 = F_457 ( 12 ) ;
else
V_677 = F_457 ( 8 ) ;
if ( F_9 ( V_12 -> V_620 , 1000 ) >= V_12 -> V_551 . V_678 ) {
if ( F_22 ( V_12 ) )
V_676 = V_679 ;
else
V_676 = F_457 ( 15 ) ;
} else {
V_676 = V_677 ;
}
F_124 ( V_680 , V_681 |
V_677 ) ;
F_124 ( V_680 , V_681 |
V_676 | V_682 ) ;
F_3 ( F_5 ( V_680 ) & V_682 ) ;
}
static void F_458 ( struct V_33 * V_683 )
{
struct V_9 * V_10 = V_683 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_672 = F_449 ( V_10 , NULL ) ;
int V_684 ;
if ( F_3 ( V_672 < 0 ) )
return;
V_684 = F_447 ( V_12 , V_672 ) ;
if ( V_684 != V_12 -> V_620 ) {
F_150 ( V_12 , V_685 ) ;
if ( F_22 ( V_10 ) )
F_446 ( V_10 , V_684 ) ;
else
F_440 ( V_10 , V_684 ) ;
F_456 ( V_12 ) ;
F_152 ( V_12 , V_685 ) ;
}
}
static void F_459 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = F_260 ( V_10 ) ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
bool V_686 ;
F_3 ( ! V_29 -> V_34 -> V_241 ) ;
if ( V_28 -> V_90 )
return;
V_686 = F_10 ( V_28 , V_258 ) ;
if ( ! V_686 ) {
if ( F_22 ( V_10 ) )
F_460 ( V_28 , V_28 -> V_93 ) ;
else
F_461 ( V_28 , V_28 -> V_93 ) ;
}
if ( V_28 -> V_93 -> V_510 )
F_382 ( V_28 , V_567 ) ;
F_383 ( V_28 ) ;
if ( F_22 ( V_10 ) && V_4 == V_151 ) {
struct V_11 * V_12 = V_10 -> V_13 ;
F_124 ( F_462 ( V_4 ) , V_687 ) ;
F_124 ( F_463 ( V_4 ) , 0 ) ;
}
F_464 ( V_28 ) ;
V_28 -> V_90 = true ;
F_372 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_688 )
V_6 -> V_688 ( V_6 ) ;
if ( ! V_686 ) {
if ( F_22 ( V_10 ) )
F_129 ( V_28 , V_28 -> V_93 ) ;
else
F_120 ( V_28 , V_28 -> V_93 ) ;
}
F_11 (dev, crtc, encoder)
if ( V_6 -> V_569 )
V_6 -> V_569 ( V_6 ) ;
F_409 ( V_28 ) ;
F_364 ( V_29 ) ;
F_387 ( V_29 ) ;
F_162 ( V_28 ) ;
F_95 ( V_29 ) ;
F_388 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_241 ( V_6 ) ;
}
static void F_465 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_124 ( F_466 ( V_29 -> V_4 ) , V_29 -> V_93 -> V_211 . V_689 ) ;
F_124 ( F_467 ( V_29 -> V_4 ) , V_29 -> V_93 -> V_211 . V_690 ) ;
}
static void F_468 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = F_260 ( V_10 ) ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
F_3 ( ! V_29 -> V_34 -> V_241 ) ;
if ( V_28 -> V_90 )
return;
F_465 ( V_28 ) ;
if ( V_28 -> V_93 -> V_510 )
F_382 ( V_28 , V_567 ) ;
F_383 ( V_28 ) ;
F_464 ( V_28 ) ;
V_28 -> V_90 = true ;
if ( ! F_24 ( V_10 ) )
F_372 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_569 )
V_6 -> V_569 ( V_6 ) ;
F_136 ( V_28 ) ;
F_409 ( V_28 ) ;
F_364 ( V_29 ) ;
F_387 ( V_29 ) ;
F_162 ( V_28 ) ;
F_95 ( V_29 ) ;
F_388 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_241 ( V_6 ) ;
}
static void F_469 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_93 -> V_577 . V_578 )
return;
F_121 ( V_12 , V_29 -> V_4 ) ;
F_145 ( L_109 ,
F_5 ( V_579 ) ) ;
F_124 ( V_579 , 0 ) ;
}
static void F_470 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
if ( ! V_28 -> V_90 )
return;
F_300 ( V_10 , V_4 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_242 ( V_6 ) ;
F_403 ( V_29 ) ;
F_95 ( V_29 ) ;
F_169 ( V_28 ) ;
F_469 ( V_28 ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_575 )
V_6 -> V_575 ( V_6 ) ;
if ( ! F_10 ( V_28 , V_258 ) ) {
if ( F_22 ( V_10 ) )
F_140 ( V_12 , V_4 ) ;
else if ( F_23 ( V_10 ) )
F_139 ( V_12 , V_4 ) ;
else
F_138 ( V_28 ) ;
}
if ( ! F_24 ( V_10 ) )
F_372 ( V_12 , V_4 , false ) ;
V_28 -> V_90 = false ;
F_387 ( V_29 ) ;
F_60 ( & V_10 -> V_299 ) ;
F_371 ( V_10 ) ;
F_62 ( & V_10 -> V_299 ) ;
}
static void F_471 ( struct V_89 * V_29 )
{
}
void F_472 ( struct V_89 * V_29 , bool V_241 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
enum V_583 V_599 ;
unsigned long V_691 ;
if ( V_241 ) {
if ( ! V_28 -> V_90 ) {
V_691 = F_414 ( V_29 ) ;
F_418 (domain, domains)
F_150 ( V_12 , V_599 ) ;
V_28 -> V_601 = V_691 ;
V_12 -> V_264 . V_424 ( V_29 ) ;
F_262 ( V_29 ) ;
}
} else {
if ( V_28 -> V_90 ) {
F_261 ( V_29 ) ;
V_12 -> V_264 . V_423 ( V_29 ) ;
V_691 = V_28 -> V_601 ;
F_418 (domain, domains)
F_152 ( V_12 , V_599 ) ;
V_28 -> V_601 = 0 ;
}
}
}
void F_473 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_1 ;
bool V_241 = false ;
F_11 (dev, crtc, intel_encoder)
V_241 |= V_1 -> V_692 ;
F_472 ( V_29 , V_241 ) ;
V_29 -> V_34 -> V_90 = V_241 ;
}
static void F_474 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_35 * V_3 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_261 ( V_29 ) ;
V_12 -> V_264 . V_423 ( V_29 ) ;
V_12 -> V_264 . V_693 ( V_29 ) ;
F_475 ( V_29 -> V_91 ) ;
F_476 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_3 -> V_6 || ! V_3 -> V_6 -> V_29 )
continue;
if ( V_3 -> V_6 -> V_29 != V_29 )
continue;
V_3 -> V_694 = V_695 ;
F_14 ( V_3 -> V_6 ) -> V_692 = false ;
}
}
void F_477 ( struct V_696 * V_6 )
{
struct V_1 * V_1 = F_14 ( V_6 ) ;
F_478 ( V_6 ) ;
F_210 ( V_1 ) ;
}
static void F_479 ( struct V_1 * V_6 , int V_419 )
{
if ( V_419 == V_697 ) {
V_6 -> V_692 = true ;
F_473 ( V_6 -> V_8 . V_29 ) ;
} else {
V_6 -> V_692 = false ;
F_473 ( V_6 -> V_8 . V_29 ) ;
}
}
static void F_480 ( struct V_2 * V_3 )
{
if ( V_3 -> V_133 ( V_3 ) ) {
struct V_1 * V_6 = V_3 -> V_6 ;
struct V_89 * V_29 ;
bool V_698 ;
enum V_4 V_4 ;
F_148 ( L_110 ,
V_3 -> V_8 . V_8 . V_239 ,
V_3 -> V_8 . V_134 ) ;
if ( V_3 -> V_5 )
return;
F_58 ( V_3 -> V_8 . V_694 == V_695 ,
L_111 ) ;
F_58 ( V_3 -> V_8 . V_6 != & V_6 -> V_8 ,
L_112 ) ;
if ( V_6 ) {
F_58 ( ! V_6 -> V_692 ,
L_113 ) ;
V_698 = V_6 -> V_133 ( V_6 , & V_4 ) ;
F_58 ( ! V_698 , L_114 ) ;
if ( F_96 ( ! V_6 -> V_8 . V_29 ) )
return;
V_29 = V_6 -> V_8 . V_29 ;
F_58 ( ! V_29 -> V_34 -> V_241 ,
L_115 ) ;
F_58 ( ! F_33 ( V_29 ) -> V_90 , L_116 ) ;
F_58 ( V_4 != F_33 ( V_29 ) -> V_4 ,
L_117 ) ;
}
}
}
int F_481 ( struct V_2 * V_3 )
{
struct V_36 * V_37 ;
V_37 = F_482 ( sizeof *V_37 , V_525 ) ;
if ( ! V_37 )
return - V_527 ;
V_3 -> V_8 . V_34 = V_37 ;
return 0 ;
}
struct V_2 * F_483 ( void )
{
struct V_2 * V_3 ;
V_3 = F_482 ( sizeof *V_3 , V_525 ) ;
if ( ! V_3 )
return NULL ;
if ( F_481 ( V_3 ) < 0 ) {
F_210 ( V_3 ) ;
return NULL ;
}
return V_3 ;
}
void F_484 ( struct V_35 * V_3 , int V_419 )
{
if ( V_419 != V_697 )
V_419 = V_695 ;
if ( V_419 == V_3 -> V_694 )
return;
V_3 -> V_694 = V_419 ;
if ( V_3 -> V_6 )
F_479 ( F_14 ( V_3 -> V_6 ) , V_419 ) ;
F_485 ( V_3 -> V_10 ) ;
}
bool F_486 ( struct V_2 * V_3 )
{
enum V_4 V_4 = 0 ;
struct V_1 * V_6 = V_3 -> V_6 ;
return V_6 -> V_133 ( V_6 , & V_4 ) ;
}
static int F_487 ( struct V_31 * V_32 )
{
if ( V_32 -> V_8 . V_241 && V_32 -> V_259 )
return V_32 -> V_454 ;
return 0 ;
}
static int F_488 ( struct V_9 * V_10 , enum V_4 V_4 ,
struct V_31 * V_210 )
{
struct V_33 * V_34 = V_210 -> V_8 . V_34 ;
struct V_28 * V_699 ;
struct V_31 * V_700 ;
F_148 ( L_118 ,
F_75 ( V_4 ) , V_210 -> V_454 ) ;
if ( V_210 -> V_454 > 4 ) {
F_148 ( L_119 ,
F_75 ( V_4 ) , V_210 -> V_454 ) ;
return - V_300 ;
}
if ( F_227 ( V_10 ) || F_228 ( V_10 ) ) {
if ( V_210 -> V_454 > 2 ) {
F_148 ( L_120 ,
V_210 -> V_454 ) ;
return - V_300 ;
} else {
return 0 ;
}
}
if ( F_49 ( V_10 ) -> V_701 == 2 )
return 0 ;
switch ( V_4 ) {
case V_142 :
return 0 ;
case V_151 :
if ( V_210 -> V_454 <= 2 )
return 0 ;
V_699 = F_33 ( F_489 ( V_10 , V_504 ) ) ;
V_700 =
F_450 ( V_34 , V_699 ) ;
if ( F_451 ( V_700 ) )
return F_452 ( V_700 ) ;
if ( F_487 ( V_700 ) > 0 ) {
F_148 ( L_121 ,
F_75 ( V_4 ) , V_210 -> V_454 ) ;
return - V_300 ;
}
return 0 ;
case V_504 :
if ( V_210 -> V_454 > 2 ) {
F_148 ( L_122 ,
F_75 ( V_4 ) , V_210 -> V_454 ) ;
return - V_300 ;
}
V_699 = F_33 ( F_489 ( V_10 , V_151 ) ) ;
V_700 =
F_450 ( V_34 , V_699 ) ;
if ( F_451 ( V_700 ) )
return F_452 ( V_700 ) ;
if ( F_487 ( V_700 ) > 2 ) {
F_148 ( L_123 ) ;
return - V_300 ;
}
return 0 ;
default:
F_142 () ;
}
}
static int F_490 ( struct V_28 * V_28 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_434 * V_94 = & V_210 -> V_8 . V_94 ;
int V_702 , V_703 , V_704 , V_298 ;
bool V_705 = false ;
V_459:
V_703 = F_6 ( V_10 ) * F_491 ( 100 ) / F_492 ( 1 ) / 10 ;
V_704 = V_94 -> V_95 ;
V_702 = F_493 ( V_704 , V_703 ,
V_210 -> V_706 ) ;
V_210 -> V_454 = V_702 ;
F_494 ( V_210 -> V_706 , V_702 , V_704 ,
V_703 , & V_210 -> V_568 ) ;
V_298 = F_488 ( V_28 -> V_8 . V_10 ,
V_28 -> V_4 , V_210 ) ;
if ( V_298 == - V_300 && V_210 -> V_706 > 6 * 3 ) {
V_210 -> V_706 -= 2 * 3 ;
F_148 ( L_124 ,
V_210 -> V_706 ) ;
V_705 = true ;
V_210 -> V_707 = true ;
goto V_459;
}
if ( V_705 )
return V_708 ;
return V_298 ;
}
static void F_495 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
V_210 -> V_550 = V_435 . V_709 &&
F_389 ( V_29 ) &&
V_210 -> V_706 <= 24 ;
}
static int F_496 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_434 * V_94 = & V_210 -> V_8 . V_94 ;
int V_298 ;
if ( F_49 ( V_10 ) -> V_105 < 4 ) {
int V_710 =
V_12 -> V_264 . V_654 ( V_10 ) ;
if ( ( V_29 -> V_4 == V_142 || F_497 ( V_10 ) ) &&
V_94 -> V_95 > V_710 * 9 / 10 ) {
V_710 *= 2 ;
V_210 -> V_260 = true ;
}
if ( V_94 -> V_95 > V_710 * 9 / 10 )
return - V_300 ;
}
if ( ( F_12 ( V_210 , V_42 ) &&
F_16 ( V_10 ) ) || V_210 -> V_260 )
V_210 -> V_358 &= ~ 1 ;
if ( ( F_49 ( V_10 ) -> V_105 > 4 || F_20 ( V_10 ) ) &&
V_94 -> V_711 == V_94 -> V_533 )
return - V_300 ;
if ( F_390 ( V_10 ) )
F_495 ( V_29 , V_210 ) ;
if ( V_210 -> V_259 )
return F_490 ( V_29 , V_210 ) ;
V_298 = 0 ;
F_148 ( L_125 ,
V_29 , V_210 -> V_8 . V_34 ) ;
V_298 = F_353 ( V_10 , V_29 , V_210 ) ;
return V_298 ;
}
static int F_498 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_260 ( V_10 ) ;
T_4 V_712 = F_5 ( V_638 ) ;
T_4 V_713 = F_5 ( V_611 ) ;
T_4 V_714 ;
if ( ! ( V_712 & V_639 ) ) {
F_52 ( 1 , L_126 ) ;
return 24000 ;
}
if ( ( V_713 & V_632 ) == V_647 )
return 540000 ;
V_714 = ( F_5 ( V_634 ) &
F_429 ( V_635 ) ) >> 1 ;
if ( V_714 == V_715 ||
V_714 == V_636 ) {
switch ( V_713 & V_632 ) {
case V_646 :
return 432000 ;
case V_633 :
return 308570 ;
case V_648 :
return 617140 ;
default:
F_52 ( 1 , L_127 ) ;
}
} else {
switch ( V_713 & V_632 ) {
case V_646 :
return 450000 ;
case V_633 :
return 337500 ;
case V_648 :
return 675000 ;
default:
F_52 ( 1 , L_127 ) ;
}
}
return 24000 ;
}
static int F_499 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_716 = F_5 ( V_717 ) ;
T_4 V_626 = V_716 & V_718 ;
if ( V_716 & V_719 )
return 800000 ;
else if ( F_5 ( V_720 ) & V_721 )
return 450000 ;
else if ( V_626 == V_722 )
return 450000 ;
else if ( V_626 == V_723 )
return 540000 ;
else if ( V_626 == V_724 )
return 337500 ;
else
return 675000 ;
}
static int F_500 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_716 = F_5 ( V_717 ) ;
T_4 V_626 = V_716 & V_718 ;
if ( V_716 & V_719 )
return 800000 ;
else if ( F_5 ( V_720 ) & V_721 )
return 450000 ;
else if ( V_626 == V_722 )
return 450000 ;
else if ( F_501 ( V_10 ) )
return 337500 ;
else
return 540000 ;
}
static int F_502 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_121 ;
int V_603 ;
if ( V_12 -> V_650 == 0 )
V_12 -> V_650 = F_438 ( V_12 ) ;
F_60 ( & V_12 -> V_124 ) ;
V_121 = F_61 ( V_12 , V_663 ) ;
F_62 ( & V_12 -> V_124 ) ;
V_603 = V_121 & V_664 ;
F_52 ( ( V_121 & V_665 ) !=
( V_603 << V_666 ) ,
L_128 ) ;
return F_9 ( V_12 -> V_650 << 1 , V_603 + 1 ) ;
}
static int F_503 ( struct V_9 * V_10 )
{
return 450000 ;
}
static int F_504 ( struct V_9 * V_10 )
{
return 400000 ;
}
static int F_505 ( struct V_9 * V_10 )
{
return 333333 ;
}
static int F_506 ( struct V_9 * V_10 )
{
return 200000 ;
}
static int F_507 ( struct V_9 * V_10 )
{
T_5 V_725 = 0 ;
F_508 ( V_10 -> V_726 , V_727 , & V_725 ) ;
switch ( V_725 & V_728 ) {
case V_729 :
return 266667 ;
case V_730 :
return 333333 ;
case V_731 :
return 444444 ;
case V_732 :
return 200000 ;
default:
F_127 ( L_129 , V_725 ) ;
case V_733 :
return 133333 ;
case V_734 :
return 166667 ;
}
}
static int F_509 ( struct V_9 * V_10 )
{
T_5 V_725 = 0 ;
F_508 ( V_10 -> V_726 , V_727 , & V_725 ) ;
if ( V_725 & V_735 )
return 133333 ;
else {
switch ( V_725 & V_728 ) {
case V_736 :
return 333333 ;
default:
case V_737 :
return 190000 ;
}
}
}
static int F_510 ( struct V_9 * V_10 )
{
return 266667 ;
}
static int F_511 ( struct V_9 * V_10 )
{
T_5 V_738 = 0 ;
switch ( V_738 & V_739 ) {
case V_740 :
case V_741 :
return 200000 ;
case V_742 :
return 250000 ;
case V_743 :
return 133333 ;
}
return 0 ;
}
static int F_512 ( struct V_9 * V_10 )
{
return 133333 ;
}
static void
F_513 ( T_4 * V_744 , T_4 * V_745 )
{
while ( * V_744 > V_746 ||
* V_745 > V_746 ) {
* V_744 >>= 1 ;
* V_745 >>= 1 ;
}
}
static void F_514 ( unsigned int V_19 , unsigned int V_25 ,
T_4 * V_747 , T_4 * V_748 )
{
* V_748 = F_515 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_747 = F_38 ( ( V_67 ) V_19 * * V_748 , V_25 ) ;
F_513 ( V_747 , V_748 ) ;
}
void
F_494 ( int V_366 , int V_749 ,
int V_750 , int V_751 ,
struct V_752 * V_753 )
{
V_753 -> V_754 = 64 ;
F_514 ( V_366 * V_750 ,
V_751 * V_749 * 8 ,
& V_753 -> V_755 , & V_753 -> V_756 ) ;
F_514 ( V_750 , V_751 ,
& V_753 -> V_757 , & V_753 -> V_758 ) ;
}
static inline bool F_516 ( struct V_11 * V_12 )
{
if ( V_435 . V_759 >= 0 )
return V_435 . V_759 != 0 ;
return V_12 -> V_760 . V_761
&& ! ( V_12 -> V_160 & V_762 ) ;
}
static int F_42 ( const struct V_31 * V_32 ,
int V_39 )
{
struct V_9 * V_10 = V_32 -> V_8 . V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_18 ;
F_3 ( ! V_32 -> V_8 . V_34 ) ;
if ( F_23 ( V_10 ) || F_19 ( V_10 ) ) {
V_18 = 100000 ;
} else if ( F_12 ( V_32 , V_42 ) &&
F_516 ( V_12 ) && V_39 < 2 ) {
V_18 = V_12 -> V_760 . V_763 ;
F_148 ( L_130 , V_18 ) ;
} else if ( ! F_24 ( V_10 ) ) {
V_18 = 96000 ;
} else {
V_18 = 48000 ;
}
return V_18 ;
}
static T_4 F_517 ( struct V_66 * V_66 )
{
return ( 1 << V_66 -> V_25 ) << 16 | V_66 -> V_21 ;
}
static T_4 F_518 ( struct V_66 * V_66 )
{
return V_66 -> V_25 << 16 | V_66 -> V_20 << 8 | V_66 -> V_21 ;
}
static void F_519 ( struct V_28 * V_29 ,
struct V_31 * V_32 ,
T_2 * V_764 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_1 V_765 , V_766 = 0 ;
if ( F_21 ( V_10 ) ) {
V_765 = F_517 ( & V_32 -> V_66 ) ;
if ( V_764 )
V_766 = F_517 ( V_764 ) ;
} else {
V_765 = F_518 ( & V_32 -> V_66 ) ;
if ( V_764 )
V_766 = F_518 ( V_764 ) ;
}
V_32 -> V_211 . V_689 = V_765 ;
V_29 -> V_767 = false ;
if ( F_12 ( V_32 , V_42 ) &&
V_764 ) {
V_32 -> V_211 . V_690 = V_766 ;
V_29 -> V_767 = true ;
} else {
V_32 -> V_211 . V_690 = V_765 ;
}
}
static void F_520 ( struct V_11 * V_12 , enum V_4
V_4 )
{
T_1 V_768 ;
V_768 = F_131 ( V_12 , V_4 , F_521 ( 1 ) ) ;
V_768 &= 0xffffff00 ;
V_768 |= 0x00000030 ;
F_133 ( V_12 , V_4 , F_521 ( 1 ) , V_768 ) ;
V_768 = F_131 ( V_12 , V_4 , V_769 ) ;
V_768 &= 0x8cffffff ;
V_768 = 0x8c000000 ;
F_133 ( V_12 , V_4 , V_769 , V_768 ) ;
V_768 = F_131 ( V_12 , V_4 , F_521 ( 1 ) ) ;
V_768 &= 0xffffff00 ;
F_133 ( V_12 , V_4 , F_521 ( 1 ) , V_768 ) ;
V_768 = F_131 ( V_12 , V_4 , V_769 ) ;
V_768 &= 0x00ffffff ;
V_768 |= 0xb0000000 ;
F_133 ( V_12 , V_4 , V_769 , V_768 ) ;
}
static void F_522 ( struct V_28 * V_29 ,
struct V_752 * V_753 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
F_124 ( F_523 ( V_4 ) , F_524 ( V_753 -> V_754 ) | V_753 -> V_755 ) ;
F_124 ( F_525 ( V_4 ) , V_753 -> V_756 ) ;
F_124 ( F_526 ( V_4 ) , V_753 -> V_757 ) ;
F_124 ( F_527 ( V_4 ) , V_753 -> V_758 ) ;
}
static void F_384 ( struct V_28 * V_29 ,
struct V_752 * V_753 ,
struct V_752 * V_770 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
enum V_96 V_96 = V_29 -> V_93 -> V_98 ;
if ( F_49 ( V_10 ) -> V_105 >= 5 ) {
F_124 ( F_336 ( V_96 ) , F_524 ( V_753 -> V_754 ) | V_753 -> V_755 ) ;
F_124 ( F_528 ( V_96 ) , V_753 -> V_756 ) ;
F_124 ( F_529 ( V_96 ) , V_753 -> V_757 ) ;
F_124 ( F_530 ( V_96 ) , V_753 -> V_758 ) ;
if ( V_770 && ( F_22 ( V_10 ) || F_49 ( V_10 ) -> V_105 < 8 ) &&
V_29 -> V_93 -> V_771 ) {
F_124 ( F_531 ( V_96 ) ,
F_524 ( V_770 -> V_754 ) | V_770 -> V_755 ) ;
F_124 ( F_532 ( V_96 ) , V_770 -> V_756 ) ;
F_124 ( F_533 ( V_96 ) , V_770 -> V_757 ) ;
F_124 ( F_534 ( V_96 ) , V_770 -> V_758 ) ;
}
} else {
F_124 ( F_535 ( V_4 ) , F_524 ( V_753 -> V_754 ) | V_753 -> V_755 ) ;
F_124 ( F_536 ( V_4 ) , V_753 -> V_756 ) ;
F_124 ( F_537 ( V_4 ) , V_753 -> V_757 ) ;
F_124 ( F_538 ( V_4 ) , V_753 -> V_758 ) ;
}
}
void F_382 ( struct V_28 * V_29 , enum V_772 V_753 )
{
struct V_752 * V_773 , * V_774 = NULL ;
if ( V_753 == V_567 ) {
V_773 = & V_29 -> V_93 -> V_773 ;
V_774 = & V_29 -> V_93 -> V_774 ;
} else if ( V_753 == V_775 ) {
V_773 = & V_29 -> V_93 -> V_774 ;
} else {
F_127 ( L_131 ) ;
return;
}
if ( V_29 -> V_93 -> V_259 )
F_522 ( V_29 , & V_29 -> V_93 -> V_773 ) ;
else
F_384 ( V_29 , V_773 , V_774 ) ;
}
static void F_539 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
T_1 V_66 , V_213 ;
V_66 = V_776 | V_220 |
V_777 | V_778 ;
if ( V_29 -> V_4 == V_151 )
V_66 |= V_219 ;
V_66 |= V_123 ;
V_210 -> V_211 . V_66 = V_66 ;
V_213 = ( V_210 -> V_573 - 1 )
<< V_779 ;
V_210 -> V_211 . V_213 = V_213 ;
}
static void F_461 ( struct V_28 * V_29 ,
const struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
T_1 V_780 ;
T_1 V_781 , V_782 , V_783 , V_784 , V_785 ;
T_1 V_786 , V_768 ;
F_60 ( & V_12 -> V_124 ) ;
V_781 = V_210 -> V_66 . V_25 ;
V_782 = V_210 -> V_66 . V_20 ;
V_783 = V_210 -> V_66 . V_21 ;
V_784 = V_210 -> V_66 . V_23 ;
V_785 = V_210 -> V_66 . V_24 ;
if ( V_4 == V_151 )
F_520 ( V_12 , V_4 ) ;
F_133 ( V_12 , V_4 , V_787 , 0x0100000f ) ;
V_768 = F_131 ( V_12 , V_4 , F_540 ( V_4 ) ) ;
V_768 &= 0x00ffffff ;
F_133 ( V_12 , V_4 , F_540 ( V_4 ) , V_768 ) ;
F_133 ( V_12 , V_4 , V_788 , 0x610 ) ;
V_780 = ( ( V_782 << V_789 ) | ( V_783 & V_790 ) ) ;
V_780 |= ( ( V_784 << V_791 ) | ( V_785 << V_792 ) ) ;
V_780 |= ( ( V_781 << V_793 ) ) ;
V_780 |= ( 1 << V_794 ) ;
V_780 |= ( V_795 << V_796 ) ;
F_133 ( V_12 , V_4 , F_541 ( V_4 ) , V_780 ) ;
V_780 |= V_797 ;
F_133 ( V_12 , V_4 , F_541 ( V_4 ) , V_780 ) ;
if ( V_210 -> V_798 == 162000 ||
F_10 ( V_29 , V_51 ) ||
F_10 ( V_29 , V_50 ) )
F_133 ( V_12 , V_4 , F_542 ( V_4 ) ,
0x009f0003 ) ;
else
F_133 ( V_12 , V_4 , F_542 ( V_4 ) ,
0x00d0000f ) ;
if ( V_210 -> V_510 ) {
if ( V_4 == V_142 )
F_133 ( V_12 , V_4 , F_543 ( V_4 ) ,
0x0df40000 ) ;
else
F_133 ( V_12 , V_4 , F_543 ( V_4 ) ,
0x0df70000 ) ;
} else {
if ( V_4 == V_142 )
F_133 ( V_12 , V_4 , F_543 ( V_4 ) ,
0x0df70000 ) ;
else
F_133 ( V_12 , V_4 , F_543 ( V_4 ) ,
0x0df40000 ) ;
}
V_786 = F_131 ( V_12 , V_4 , F_544 ( V_4 ) ) ;
V_786 = ( V_786 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_10 ( V_29 , V_591 ) ||
F_10 ( V_29 , V_440 ) )
V_786 |= 0x01000000 ;
F_133 ( V_12 , V_4 , F_544 ( V_4 ) , V_786 ) ;
F_133 ( V_12 , V_4 , F_545 ( V_4 ) , 0x87871000 ) ;
F_62 ( & V_12 -> V_124 ) ;
}
static void F_546 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
V_210 -> V_211 . V_66 = V_221 |
V_220 | V_777 |
V_123 ;
if ( V_29 -> V_4 != V_142 )
V_210 -> V_211 . V_66 |= V_219 ;
V_210 -> V_211 . V_213 =
( V_210 -> V_573 - 1 ) << V_779 ;
}
static void F_460 ( struct V_28 * V_29 ,
const struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
int V_231 = F_57 ( V_29 -> V_4 ) ;
enum V_214 V_108 = F_130 ( V_4 ) ;
T_1 V_799 , V_800 ;
T_1 V_781 , V_782 , V_783 , V_784 , V_785 , V_801 ;
T_1 V_802 ;
int V_26 ;
V_781 = V_210 -> V_66 . V_25 ;
V_801 = V_210 -> V_66 . V_21 & 0x3fffff ;
V_782 = V_210 -> V_66 . V_20 ;
V_783 = V_210 -> V_66 . V_21 >> 22 ;
V_784 = V_210 -> V_66 . V_23 ;
V_785 = V_210 -> V_66 . V_24 ;
V_26 = V_210 -> V_66 . V_26 ;
V_802 = 0 ;
V_799 = 0 ;
F_124 ( V_231 ,
V_210 -> V_211 . V_66 & ~ V_123 ) ;
F_60 ( & V_12 -> V_124 ) ;
F_133 ( V_12 , V_4 , F_547 ( V_108 ) ,
5 << V_803 |
V_784 << V_804 |
V_785 << V_805 |
1 << V_806 ) ;
F_133 ( V_12 , V_4 , F_548 ( V_108 ) , V_783 ) ;
F_133 ( V_12 , V_4 , F_549 ( V_108 ) ,
V_807 |
1 << V_808 ) ;
if ( V_801 )
F_133 ( V_12 , V_4 , F_550 ( V_108 ) , V_801 ) ;
V_802 = F_131 ( V_12 , V_4 , F_551 ( V_108 ) ) ;
V_802 &= ~ ( V_809 | V_810 ) ;
V_802 |= ( 2 << V_811 ) ;
if ( V_801 )
V_802 |= V_810 ;
F_133 ( V_12 , V_4 , F_551 ( V_108 ) , V_802 ) ;
V_802 = F_131 ( V_12 , V_4 , F_552 ( V_108 ) ) ;
V_802 &= ~ ( V_812 |
V_813 ) ;
V_802 |= ( 0x5 << V_814 ) ;
if ( ! V_801 )
V_802 |= V_813 ;
F_133 ( V_12 , V_4 , F_552 ( V_108 ) , V_802 ) ;
if ( V_26 == 5400000 ) {
V_799 |= ( 0x3 << V_815 ) ;
V_799 |= ( 0x8 << V_816 ) ;
V_799 |= ( 0x1 << V_817 ) ;
V_800 = 0x9 ;
} else if ( V_26 <= 6200000 ) {
V_799 |= ( 0x5 << V_815 ) ;
V_799 |= ( 0xB << V_816 ) ;
V_799 |= ( 0x3 << V_817 ) ;
V_800 = 0x9 ;
} else if ( V_26 <= 6480000 ) {
V_799 |= ( 0x4 << V_815 ) ;
V_799 |= ( 0x9 << V_816 ) ;
V_799 |= ( 0x3 << V_817 ) ;
V_800 = 0x8 ;
} else {
V_799 |= ( 0x4 << V_815 ) ;
V_799 |= ( 0x9 << V_816 ) ;
V_799 |= ( 0x3 << V_817 ) ;
V_800 = 0 ;
}
F_133 ( V_12 , V_4 , F_553 ( V_108 ) , V_799 ) ;
V_802 = F_131 ( V_12 , V_4 , F_554 ( V_108 ) ) ;
V_802 &= ~ V_818 ;
V_802 |= ( V_800 << V_819 ) ;
F_133 ( V_12 , V_4 , F_554 ( V_108 ) , V_802 ) ;
F_133 ( V_12 , V_4 , F_132 ( V_108 ) ,
F_131 ( V_12 , V_4 , F_132 ( V_108 ) ) |
V_820 ) ;
F_62 ( & V_12 -> V_124 ) ;
}
void F_555 ( struct V_9 * V_10 , enum V_4 V_4 ,
const struct V_66 * V_66 )
{
struct V_28 * V_29 =
F_33 ( F_489 ( V_10 , V_4 ) ) ;
struct V_31 V_210 = {
. V_8 . V_29 = & V_29 -> V_8 ,
. V_573 = 1 ,
. V_66 = * V_66 ,
} ;
if ( F_22 ( V_10 ) ) {
F_546 ( V_29 , & V_210 ) ;
F_460 ( V_29 , & V_210 ) ;
F_129 ( V_29 , & V_210 ) ;
} else {
F_539 ( V_29 , & V_210 ) ;
F_461 ( V_29 , & V_210 ) ;
F_120 ( V_29 , & V_210 ) ;
}
}
void F_556 ( struct V_9 * V_10 , enum V_4 V_4 )
{
if ( F_22 ( V_10 ) )
F_140 ( F_260 ( V_10 ) , V_4 ) ;
else
F_139 ( F_260 ( V_10 ) , V_4 ) ;
}
static void F_557 ( struct V_28 * V_29 ,
struct V_31 * V_32 ,
T_2 * V_764 ,
int V_39 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_66 ;
bool V_821 ;
struct V_66 * clock = & V_32 -> V_66 ;
F_519 ( V_29 , V_32 , V_764 ) ;
V_821 = F_12 ( V_32 , V_53 ) ||
F_12 ( V_32 , V_50 ) ;
V_66 = V_777 ;
if ( F_12 ( V_32 , V_42 ) )
V_66 |= V_822 ;
else
V_66 |= V_823 ;
if ( F_558 ( V_10 ) || F_559 ( V_10 ) || F_560 ( V_10 ) ) {
V_66 |= ( V_32 -> V_573 - 1 )
<< V_824 ;
}
if ( V_821 )
V_66 |= V_825 ;
if ( V_32 -> V_510 )
V_66 |= V_825 ;
if ( F_21 ( V_10 ) )
V_66 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_826 ;
else {
V_66 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_827 ;
if ( F_20 ( V_10 ) && V_764 )
V_66 |= ( 1 << ( V_764 -> V_23 - 1 ) ) << V_828 ;
}
switch ( clock -> V_24 ) {
case 5 :
V_66 |= V_829 ;
break;
case 7 :
V_66 |= V_830 ;
break;
case 10 :
V_66 |= V_831 ;
break;
case 14 :
V_66 |= V_832 ;
break;
}
if ( F_49 ( V_10 ) -> V_105 >= 4 )
V_66 |= ( 6 << V_833 ) ;
if ( V_32 -> V_834 )
V_66 |= V_835 ;
else if ( F_12 ( V_32 , V_42 ) &&
F_516 ( V_12 ) && V_39 < 2 )
V_66 |= V_836 ;
else
V_66 |= V_837 ;
V_66 |= V_123 ;
V_32 -> V_211 . V_66 = V_66 ;
if ( F_49 ( V_10 ) -> V_105 >= 4 ) {
T_1 V_213 = ( V_32 -> V_573 - 1 )
<< V_779 ;
V_32 -> V_211 . V_213 = V_213 ;
}
}
static void F_561 ( struct V_28 * V_29 ,
struct V_31 * V_32 ,
T_2 * V_764 ,
int V_39 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_66 ;
struct V_66 * clock = & V_32 -> V_66 ;
F_519 ( V_29 , V_32 , V_764 ) ;
V_66 = V_777 ;
if ( F_12 ( V_32 , V_42 ) ) {
V_66 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_827 ;
} else {
if ( clock -> V_23 == 2 )
V_66 |= V_838 ;
else
V_66 |= ( clock -> V_23 - 2 ) << V_827 ;
if ( clock -> V_24 == 4 )
V_66 |= V_839 ;
}
if ( ! F_137 ( V_10 ) && F_12 ( V_32 , V_63 ) )
V_66 |= V_218 ;
if ( F_12 ( V_32 , V_42 ) &&
F_516 ( V_12 ) && V_39 < 2 )
V_66 |= V_836 ;
else
V_66 |= V_837 ;
V_66 |= V_123 ;
V_32 -> V_211 . V_66 = V_66 ;
}
static void F_383 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_28 -> V_4 ;
enum V_96 V_98 = V_28 -> V_93 -> V_98 ;
struct V_434 * V_94 =
& V_28 -> V_93 -> V_8 . V_94 ;
T_4 V_840 , V_841 ;
int V_842 = 0 ;
V_840 = V_94 -> V_840 ;
V_841 = V_94 -> V_841 ;
if ( V_94 -> V_345 & V_843 ) {
V_840 -= 1 ;
V_841 -= 1 ;
if ( F_10 ( V_28 , V_53 ) )
V_842 = ( V_94 -> V_844 - 1 ) / 2 ;
else
V_842 = V_94 -> V_845 -
V_94 -> V_844 / 2 ;
if ( V_842 < 0 )
V_842 += V_94 -> V_844 ;
}
if ( F_49 ( V_10 ) -> V_105 > 3 )
F_124 ( F_331 ( V_98 ) , V_842 ) ;
F_124 ( F_319 ( V_98 ) ,
( V_94 -> V_437 - 1 ) |
( ( V_94 -> V_844 - 1 ) << 16 ) ) ;
F_124 ( F_321 ( V_98 ) ,
( V_94 -> V_846 - 1 ) |
( ( V_94 -> V_847 - 1 ) << 16 ) ) ;
F_124 ( F_323 ( V_98 ) ,
( V_94 -> V_845 - 1 ) |
( ( V_94 -> V_848 - 1 ) << 16 ) ) ;
F_124 ( F_325 ( V_98 ) ,
( V_94 -> V_438 - 1 ) |
( ( V_840 - 1 ) << 16 ) ) ;
F_124 ( F_327 ( V_98 ) ,
( V_94 -> V_849 - 1 ) |
( ( V_841 - 1 ) << 16 ) ) ;
F_124 ( F_329 ( V_98 ) ,
( V_94 -> V_850 - 1 ) |
( ( V_94 -> V_851 - 1 ) << 16 ) ) ;
if ( F_227 ( V_10 ) && V_98 == V_572 &&
( V_4 == V_151 || V_4 == V_504 ) )
F_124 ( F_325 ( V_4 ) , F_5 ( F_325 ( V_98 ) ) ) ;
F_124 ( F_280 ( V_4 ) ,
( ( V_28 -> V_93 -> V_358 - 1 ) << 16 ) |
( V_28 -> V_93 -> V_357 - 1 ) ) ;
}
static void F_562 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_96 V_98 = V_210 -> V_98 ;
T_4 V_215 ;
V_215 = F_5 ( F_319 ( V_98 ) ) ;
V_210 -> V_8 . V_94 . V_437 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_8 . V_94 . V_844 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_215 = F_5 ( F_321 ( V_98 ) ) ;
V_210 -> V_8 . V_94 . V_846 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_8 . V_94 . V_847 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_215 = F_5 ( F_323 ( V_98 ) ) ;
V_210 -> V_8 . V_94 . V_845 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_8 . V_94 . V_848 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_215 = F_5 ( F_325 ( V_98 ) ) ;
V_210 -> V_8 . V_94 . V_438 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_8 . V_94 . V_840 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_215 = F_5 ( F_327 ( V_98 ) ) ;
V_210 -> V_8 . V_94 . V_849 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_8 . V_94 . V_841 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_215 = F_5 ( F_329 ( V_98 ) ) ;
V_210 -> V_8 . V_94 . V_850 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_8 . V_94 . V_851 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
if ( F_5 ( F_50 ( V_98 ) ) & V_247 ) {
V_210 -> V_8 . V_94 . V_345 |= V_843 ;
V_210 -> V_8 . V_94 . V_840 += 1 ;
V_210 -> V_8 . V_94 . V_841 += 1 ;
}
V_215 = F_5 ( F_280 ( V_29 -> V_4 ) ) ;
V_210 -> V_357 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_358 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_210 -> V_8 . V_419 . V_534 = V_210 -> V_357 ;
V_210 -> V_8 . V_419 . V_533 = V_210 -> V_358 ;
}
void F_563 ( struct V_434 * V_419 ,
struct V_31 * V_210 )
{
V_419 -> V_533 = V_210 -> V_8 . V_94 . V_437 ;
V_419 -> V_852 = V_210 -> V_8 . V_94 . V_844 ;
V_419 -> V_711 = V_210 -> V_8 . V_94 . V_845 ;
V_419 -> V_853 = V_210 -> V_8 . V_94 . V_848 ;
V_419 -> V_534 = V_210 -> V_8 . V_94 . V_438 ;
V_419 -> V_854 = V_210 -> V_8 . V_94 . V_840 ;
V_419 -> V_855 = V_210 -> V_8 . V_94 . V_850 ;
V_419 -> V_856 = V_210 -> V_8 . V_94 . V_851 ;
V_419 -> V_345 = V_210 -> V_8 . V_94 . V_345 ;
V_419 -> clock = V_210 -> V_8 . V_94 . V_95 ;
V_419 -> V_345 |= V_210 -> V_8 . V_94 . V_345 ;
}
static void F_464 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_857 ;
V_857 = 0 ;
if ( ( V_28 -> V_4 == V_142 && V_12 -> V_160 & V_161 ) ||
( V_28 -> V_4 == V_151 && V_12 -> V_160 & V_162 ) )
V_857 |= F_5 ( F_50 ( V_28 -> V_4 ) ) & V_163 ;
if ( V_28 -> V_93 -> V_260 )
V_857 |= V_261 ;
if ( F_20 ( V_10 ) || F_23 ( V_10 ) ) {
if ( V_28 -> V_93 -> V_858 && V_28 -> V_93 -> V_706 != 30 )
V_857 |= V_859 |
V_860 ;
switch ( V_28 -> V_93 -> V_706 ) {
case 18 :
V_857 |= V_861 ;
break;
case 24 :
V_857 |= V_862 ;
break;
case 30 :
V_857 |= V_863 ;
break;
default:
F_142 () ;
}
}
if ( F_564 ( V_10 ) ) {
if ( V_28 -> V_767 ) {
F_148 ( L_132 ) ;
V_857 |= V_864 ;
} else {
F_148 ( L_133 ) ;
}
}
if ( V_28 -> V_93 -> V_8 . V_94 . V_345 & V_843 ) {
if ( F_49 ( V_10 ) -> V_105 < 4 ||
F_10 ( V_28 , V_53 ) )
V_857 |= V_865 ;
else
V_857 |= V_866 ;
} else
V_857 |= V_867 ;
if ( F_23 ( V_10 ) && V_28 -> V_93 -> V_868 )
V_857 |= V_869 ;
F_124 ( F_50 ( V_28 -> V_4 ) , V_857 ) ;
F_125 ( F_50 ( V_28 -> V_4 ) ) ;
}
static int F_565 ( struct V_28 * V_29 ,
struct V_31 * V_32 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_18 , V_39 = 0 ;
T_2 clock , V_764 ;
bool V_870 , V_871 = false ;
bool V_872 = false , V_686 = false ;
struct V_1 * V_6 ;
const T_3 * V_41 ;
struct V_33 * V_34 = V_32 -> V_8 . V_34 ;
struct V_35 * V_3 ;
struct V_36 * V_37 ;
int V_38 ;
memset ( & V_32 -> V_211 , 0 ,
sizeof( V_32 -> V_211 ) ) ;
F_13 (state, connector, connector_state, i) {
if ( V_37 -> V_29 != & V_29 -> V_8 )
continue;
V_6 = F_14 ( V_37 -> V_40 ) ;
switch ( V_6 -> type ) {
case V_42 :
V_872 = true ;
break;
case V_258 :
V_686 = true ;
break;
default:
break;
}
V_39 ++ ;
}
if ( V_686 )
return 0 ;
if ( ! V_32 -> V_873 ) {
V_18 = F_42 ( V_32 , V_39 ) ;
V_41 = F_18 ( V_32 , V_18 ) ;
V_870 = V_12 -> V_264 . V_874 ( V_41 , V_32 ,
V_32 -> V_798 ,
V_18 , NULL , & clock ) ;
if ( ! V_870 ) {
F_127 ( L_134 ) ;
return - V_300 ;
}
if ( V_872 && V_12 -> V_875 ) {
V_871 =
V_12 -> V_264 . V_874 ( V_41 , V_32 ,
V_12 -> V_876 ,
V_18 , & clock ,
& V_764 ) ;
}
V_32 -> V_66 . V_25 = clock . V_25 ;
V_32 -> V_66 . V_20 = clock . V_20 ;
V_32 -> V_66 . V_21 = clock . V_21 ;
V_32 -> V_66 . V_23 = clock . V_23 ;
V_32 -> V_66 . V_24 = clock . V_24 ;
}
if ( F_24 ( V_10 ) ) {
F_561 ( V_29 , V_32 ,
V_871 ? & V_764 : NULL ,
V_39 ) ;
} else if ( F_22 ( V_10 ) ) {
F_546 ( V_29 , V_32 ) ;
} else if ( F_23 ( V_10 ) ) {
F_539 ( V_29 , V_32 ) ;
} else {
F_557 ( V_29 , V_32 ,
V_871 ? & V_764 : NULL ,
V_39 ) ;
}
return 0 ;
}
static void F_566 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_215 ;
if ( F_49 ( V_10 ) -> V_105 <= 3 && ( F_137 ( V_10 ) || ! F_123 ( V_10 ) ) )
return;
V_215 = F_5 ( V_579 ) ;
if ( ! ( V_215 & V_580 ) )
return;
if ( F_49 ( V_10 ) -> V_105 < 4 ) {
if ( V_29 -> V_4 != V_151 )
return;
} else {
if ( ( V_215 & V_877 ) != ( V_29 -> V_4 << V_878 ) )
return;
}
V_210 -> V_577 . V_578 = V_215 ;
V_210 -> V_577 . V_582 = F_5 ( V_581 ) ;
if ( F_49 ( V_10 ) -> V_105 < 5 )
V_210 -> V_577 . V_879 =
F_5 ( V_153 ) & V_880 ;
}
static void F_567 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_210 -> V_98 ;
T_2 clock ;
T_1 V_780 ;
int V_18 = 100000 ;
if ( ! ( V_210 -> V_211 . V_66 & V_123 ) )
return;
F_60 ( & V_12 -> V_124 ) ;
V_780 = F_131 ( V_12 , V_4 , F_541 ( V_4 ) ) ;
F_62 ( & V_12 -> V_124 ) ;
clock . V_20 = ( V_780 >> V_789 ) & 7 ;
clock . V_21 = V_780 & V_790 ;
clock . V_25 = ( V_780 >> V_793 ) & 0xf ;
clock . V_23 = ( V_780 >> V_791 ) & 7 ;
clock . V_24 = ( V_780 >> V_792 ) & 0x1f ;
F_8 ( V_18 , & clock ) ;
V_210 -> V_798 = clock . V_27 / 5 ;
}
static void
F_568 ( struct V_28 * V_29 ,
struct V_333 * V_334 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_121 , V_8 , V_310 ;
int V_4 = V_29 -> V_4 , V_164 = V_29 -> V_164 ;
int V_881 , V_269 ;
unsigned int V_882 ;
struct V_280 * V_92 ;
struct V_883 * V_884 ;
V_121 = F_5 ( F_84 ( V_164 ) ) ;
if ( ! ( V_121 & V_165 ) )
return;
V_884 = F_482 ( sizeof( * V_884 ) , V_525 ) ;
if ( ! V_884 ) {
F_148 ( L_135 ) ;
return;
}
V_92 = & V_884 -> V_8 ;
if ( F_49 ( V_10 ) -> V_105 >= 4 ) {
if ( V_121 & V_360 ) {
V_334 -> V_341 = V_342 ;
V_92 -> V_292 [ 0 ] = V_274 ;
}
}
V_269 = V_121 & V_885 ;
V_881 = F_197 ( V_269 ) ;
V_92 -> V_269 = V_881 ;
V_92 -> V_366 = F_176 ( V_881 , 0 ) * 8 ;
if ( F_49 ( V_10 ) -> V_105 >= 4 ) {
if ( V_334 -> V_341 )
V_310 = F_5 ( F_224 ( V_164 ) ) ;
else
V_310 = F_5 ( F_225 ( V_164 ) ) ;
V_8 = F_5 ( F_215 ( V_164 ) ) & 0xfffff000 ;
} else {
V_8 = F_5 ( F_216 ( V_164 ) ) ;
}
V_334 -> V_8 = V_8 ;
V_121 = F_5 ( F_280 ( V_4 ) ) ;
V_92 -> V_344 = ( ( V_121 >> 16 ) & 0xfff ) + 1 ;
V_92 -> V_277 = ( ( V_121 >> 0 ) & 0xfff ) + 1 ;
V_121 = F_5 ( F_223 ( V_4 ) ) ;
V_92 -> V_290 [ 0 ] = V_121 & 0xffffffc0 ;
V_882 = F_179 ( V_10 , V_92 -> V_277 ,
V_92 -> V_269 ,
V_92 -> V_292 [ 0 ] ) ;
V_334 -> V_340 = V_92 -> V_290 [ 0 ] * V_882 ;
F_148 ( L_136 ,
F_75 ( V_4 ) , V_164 , V_92 -> V_344 , V_92 -> V_277 ,
V_92 -> V_366 , V_8 , V_92 -> V_290 [ 0 ] ,
V_334 -> V_340 ) ;
V_334 -> V_92 = V_884 ;
}
static void F_569 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_210 -> V_98 ;
enum V_214 V_108 = F_130 ( V_4 ) ;
T_2 clock ;
T_1 V_886 , V_887 , V_888 , V_889 , V_890 ;
int V_18 = 100000 ;
F_60 ( & V_12 -> V_124 ) ;
V_886 = F_131 ( V_12 , V_4 , F_547 ( V_108 ) ) ;
V_887 = F_131 ( V_12 , V_4 , F_548 ( V_108 ) ) ;
V_888 = F_131 ( V_12 , V_4 , F_549 ( V_108 ) ) ;
V_889 = F_131 ( V_12 , V_4 , F_550 ( V_108 ) ) ;
V_890 = F_131 ( V_12 , V_4 , F_551 ( V_108 ) ) ;
F_62 ( & V_12 -> V_124 ) ;
clock . V_20 = ( V_888 & 0x7 ) == V_807 ? 2 : 0 ;
clock . V_21 = ( V_887 & 0xff ) << 22 ;
if ( V_890 & V_810 )
clock . V_21 |= V_889 & 0x3fffff ;
clock . V_25 = ( V_888 >> V_808 ) & 0xf ;
clock . V_23 = ( V_886 >> V_804 ) & 0x7 ;
clock . V_24 = ( V_886 >> V_805 ) & 0x1f ;
F_28 ( V_18 , & clock ) ;
V_210 -> V_798 = clock . V_27 / 5 ;
}
static bool F_570 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_215 ;
if ( ! F_81 ( V_12 ,
F_415 ( V_29 -> V_4 ) ) )
return false ;
V_210 -> V_98 = (enum V_96 ) V_29 -> V_4 ;
V_210 -> V_128 = V_519 ;
V_215 = F_5 ( F_50 ( V_29 -> V_4 ) ) ;
if ( ! ( V_215 & V_163 ) )
return false ;
if ( F_20 ( V_10 ) || F_23 ( V_10 ) ) {
switch ( V_215 & V_245 ) {
case V_861 :
V_210 -> V_706 = 18 ;
break;
case V_862 :
V_210 -> V_706 = 24 ;
break;
case V_863 :
V_210 -> V_706 = 30 ;
break;
default:
break;
}
}
if ( F_23 ( V_10 ) && ( V_215 & V_869 ) )
V_210 -> V_868 = true ;
if ( F_49 ( V_10 ) -> V_105 < 4 )
V_210 -> V_260 = V_215 & V_261 ;
F_562 ( V_29 , V_210 ) ;
F_566 ( V_29 , V_210 ) ;
if ( F_49 ( V_10 ) -> V_105 >= 4 ) {
V_215 = F_5 ( F_128 ( V_29 -> V_4 ) ) ;
V_210 -> V_573 =
( ( V_215 & V_891 )
>> V_779 ) + 1 ;
V_210 -> V_211 . V_213 = V_215 ;
} else if ( F_558 ( V_10 ) || F_559 ( V_10 ) || F_560 ( V_10 ) ) {
V_215 = F_5 ( F_57 ( V_29 -> V_4 ) ) ;
V_210 -> V_573 =
( ( V_215 & V_892 )
>> V_824 ) + 1 ;
} else {
V_210 -> V_573 = 1 ;
}
V_210 -> V_211 . V_66 = F_5 ( F_57 ( V_29 -> V_4 ) ) ;
if ( ! F_23 ( V_10 ) ) {
if ( F_137 ( V_10 ) )
V_210 -> V_211 . V_66 &= ~ V_218 ;
V_210 -> V_211 . V_689 = F_5 ( F_466 ( V_29 -> V_4 ) ) ;
V_210 -> V_211 . V_690 = F_5 ( F_467 ( V_29 -> V_4 ) ) ;
} else {
V_210 -> V_211 . V_66 &= ~ ( V_212 |
V_233 |
V_232 ) ;
}
if ( F_22 ( V_10 ) )
F_569 ( V_29 , V_210 ) ;
else if ( F_23 ( V_10 ) )
F_567 ( V_29 , V_210 ) ;
else
F_571 ( V_29 , V_210 ) ;
return true ;
}
static void F_572 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
T_1 V_121 , V_893 ;
bool V_894 = false ;
bool V_895 = false ;
bool V_896 = false ;
bool V_897 = false ;
bool V_898 = false ;
F_573 (dev, encoder) {
switch ( V_6 -> type ) {
case V_42 :
V_896 = true ;
V_894 = true ;
break;
case V_440 :
V_896 = true ;
if ( F_344 ( & V_6 -> V_8 ) -> V_108 == V_584 )
V_895 = true ;
break;
default:
break;
}
}
if ( F_54 ( V_10 ) ) {
V_897 = V_12 -> V_760 . V_899 ;
V_898 = V_897 ;
} else {
V_897 = false ;
V_898 = true ;
}
F_148 ( L_137 ,
V_896 , V_894 , V_897 ) ;
V_121 = F_5 ( V_174 ) ;
V_893 = V_121 ;
V_893 &= ~ V_176 ;
if ( V_897 )
V_893 |= V_900 ;
else
V_893 |= V_901 ;
V_893 &= ~ V_175 ;
V_893 &= ~ V_902 ;
V_893 &= ~ V_903 ;
if ( V_896 ) {
V_893 |= V_904 ;
if ( F_516 ( V_12 ) && V_898 )
V_893 |= V_903 ;
if ( V_895 ) {
if ( F_516 ( V_12 ) && V_898 )
V_893 |= V_905 ;
else
V_893 |= V_906 ;
} else
V_893 |= V_907 ;
} else {
V_893 |= V_908 ;
V_893 |= V_907 ;
}
if ( V_893 == V_121 )
return;
V_121 &= ~ V_176 ;
if ( V_897 )
V_121 |= V_900 ;
else
V_121 |= V_901 ;
if ( V_896 ) {
V_121 &= ~ V_175 ;
V_121 |= V_904 ;
if ( F_516 ( V_12 ) && V_898 ) {
F_148 ( L_138 ) ;
V_121 |= V_903 ;
} else
V_121 &= ~ V_903 ;
F_124 ( V_174 , V_121 ) ;
F_125 ( V_174 ) ;
F_126 ( 200 ) ;
V_121 &= ~ V_902 ;
if ( V_895 ) {
if ( F_516 ( V_12 ) && V_898 ) {
F_148 ( L_139 ) ;
V_121 |= V_905 ;
} else
V_121 |= V_906 ;
} else
V_121 |= V_907 ;
F_124 ( V_174 , V_121 ) ;
F_125 ( V_174 ) ;
F_126 ( 200 ) ;
} else {
F_148 ( L_140 ) ;
V_121 &= ~ V_902 ;
V_121 |= V_907 ;
F_124 ( V_174 , V_121 ) ;
F_125 ( V_174 ) ;
F_126 ( 200 ) ;
V_121 &= ~ V_175 ;
V_121 |= V_908 ;
V_121 &= ~ V_903 ;
F_124 ( V_174 , V_121 ) ;
F_125 ( V_174 ) ;
F_126 ( 200 ) ;
}
F_122 ( V_121 != V_893 ) ;
}
static void F_574 ( struct V_11 * V_12 )
{
T_4 V_215 ;
V_215 = F_5 ( V_909 ) ;
V_215 |= V_910 ;
F_124 ( V_909 , V_215 ) ;
if ( F_575 ( F_5 ( V_909 ) &
V_911 , 100 ) )
F_127 ( L_141 ) ;
V_215 = F_5 ( V_909 ) ;
V_215 &= ~ V_910 ;
F_124 ( V_909 , V_215 ) ;
if ( F_575 ( ( F_5 ( V_909 ) &
V_911 ) == 0 , 100 ) )
F_127 ( L_142 ) ;
}
static void F_576 ( struct V_11 * V_12 )
{
T_4 V_215 ;
V_215 = F_312 ( V_12 , 0x8008 , V_912 ) ;
V_215 &= ~ ( 0xFF << 24 ) ;
V_215 |= ( 0x12 << 24 ) ;
F_311 ( V_12 , 0x8008 , V_215 , V_912 ) ;
V_215 = F_312 ( V_12 , 0x2008 , V_912 ) ;
V_215 |= ( 1 << 11 ) ;
F_311 ( V_12 , 0x2008 , V_215 , V_912 ) ;
V_215 = F_312 ( V_12 , 0x2108 , V_912 ) ;
V_215 |= ( 1 << 11 ) ;
F_311 ( V_12 , 0x2108 , V_215 , V_912 ) ;
V_215 = F_312 ( V_12 , 0x206C , V_912 ) ;
V_215 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_311 ( V_12 , 0x206C , V_215 , V_912 ) ;
V_215 = F_312 ( V_12 , 0x216C , V_912 ) ;
V_215 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_311 ( V_12 , 0x216C , V_215 , V_912 ) ;
V_215 = F_312 ( V_12 , 0x2080 , V_912 ) ;
V_215 &= ~ ( 7 << 13 ) ;
V_215 |= ( 5 << 13 ) ;
F_311 ( V_12 , 0x2080 , V_215 , V_912 ) ;
V_215 = F_312 ( V_12 , 0x2180 , V_912 ) ;
V_215 &= ~ ( 7 << 13 ) ;
V_215 |= ( 5 << 13 ) ;
F_311 ( V_12 , 0x2180 , V_215 , V_912 ) ;
V_215 = F_312 ( V_12 , 0x208C , V_912 ) ;
V_215 &= ~ 0xFF ;
V_215 |= 0x1C ;
F_311 ( V_12 , 0x208C , V_215 , V_912 ) ;
V_215 = F_312 ( V_12 , 0x218C , V_912 ) ;
V_215 &= ~ 0xFF ;
V_215 |= 0x1C ;
F_311 ( V_12 , 0x218C , V_215 , V_912 ) ;
V_215 = F_312 ( V_12 , 0x2098 , V_912 ) ;
V_215 &= ~ ( 0xFF << 16 ) ;
V_215 |= ( 0x1C << 16 ) ;
F_311 ( V_12 , 0x2098 , V_215 , V_912 ) ;
V_215 = F_312 ( V_12 , 0x2198 , V_912 ) ;
V_215 &= ~ ( 0xFF << 16 ) ;
V_215 |= ( 0x1C << 16 ) ;
F_311 ( V_12 , 0x2198 , V_215 , V_912 ) ;
V_215 = F_312 ( V_12 , 0x20C4 , V_912 ) ;
V_215 |= ( 1 << 27 ) ;
F_311 ( V_12 , 0x20C4 , V_215 , V_912 ) ;
V_215 = F_312 ( V_12 , 0x21C4 , V_912 ) ;
V_215 |= ( 1 << 27 ) ;
F_311 ( V_12 , 0x21C4 , V_215 , V_912 ) ;
V_215 = F_312 ( V_12 , 0x20EC , V_912 ) ;
V_215 &= ~ ( 0xF << 28 ) ;
V_215 |= ( 4 << 28 ) ;
F_311 ( V_12 , 0x20EC , V_215 , V_912 ) ;
V_215 = F_312 ( V_12 , 0x21EC , V_912 ) ;
V_215 &= ~ ( 0xF << 28 ) ;
V_215 |= ( 4 << 28 ) ;
F_311 ( V_12 , 0x21EC , V_215 , V_912 ) ;
}
static void F_577 ( struct V_9 * V_10 , bool V_913 ,
bool V_914 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_99 , V_215 ;
if ( F_52 ( V_914 && ! V_913 , L_143 ) )
V_913 = true ;
if ( F_52 ( V_12 -> V_915 == V_916 &&
V_914 , L_144 ) )
V_914 = false ;
F_60 ( & V_12 -> V_124 ) ;
V_215 = F_312 ( V_12 , V_917 , V_489 ) ;
V_215 &= ~ V_490 ;
V_215 |= V_918 ;
F_311 ( V_12 , V_917 , V_215 , V_489 ) ;
F_126 ( 24 ) ;
if ( V_913 ) {
V_215 = F_312 ( V_12 , V_917 , V_489 ) ;
V_215 &= ~ V_918 ;
F_311 ( V_12 , V_917 , V_215 , V_489 ) ;
if ( V_914 ) {
F_574 ( V_12 ) ;
F_576 ( V_12 ) ;
}
}
V_99 = ( V_12 -> V_915 == V_916 ) ?
V_919 : V_920 ;
V_215 = F_312 ( V_12 , V_99 , V_489 ) ;
V_215 |= V_921 ;
F_311 ( V_12 , V_99 , V_215 , V_489 ) ;
F_62 ( & V_12 -> V_124 ) ;
}
static void F_578 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_99 , V_215 ;
F_60 ( & V_12 -> V_124 ) ;
V_99 = ( V_12 -> V_915 == V_916 ) ?
V_919 : V_920 ;
V_215 = F_312 ( V_12 , V_99 , V_489 ) ;
V_215 &= ~ V_921 ;
F_311 ( V_12 , V_99 , V_215 , V_489 ) ;
V_215 = F_312 ( V_12 , V_917 , V_489 ) ;
if ( ! ( V_215 & V_490 ) ) {
if ( ! ( V_215 & V_918 ) ) {
V_215 |= V_918 ;
F_311 ( V_12 , V_917 , V_215 , V_489 ) ;
F_126 ( 32 ) ;
}
V_215 |= V_490 ;
F_311 ( V_12 , V_917 , V_215 , V_489 ) ;
}
F_62 ( & V_12 -> V_124 ) ;
}
static void F_579 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
bool V_922 = false ;
F_573 (dev, encoder) {
switch ( V_6 -> type ) {
case V_51 :
V_922 = true ;
break;
default:
break;
}
}
if ( V_922 )
F_577 ( V_10 , true , true ) ;
else
F_578 ( V_10 ) ;
}
void F_580 ( struct V_9 * V_10 )
{
if ( F_54 ( V_10 ) || F_100 ( V_10 ) )
F_572 ( V_10 ) ;
else if ( F_164 ( V_10 ) )
F_579 ( V_10 ) ;
}
static int F_581 ( struct V_31 * V_32 )
{
struct V_9 * V_10 = V_32 -> V_8 . V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_33 * V_34 = V_32 -> V_8 . V_34 ;
struct V_35 * V_3 ;
struct V_36 * V_37 ;
struct V_1 * V_6 ;
int V_39 = 0 , V_38 ;
bool V_872 = false ;
F_13 (state, connector, connector_state, i) {
if ( V_37 -> V_29 != V_32 -> V_8 . V_29 )
continue;
V_6 = F_14 ( V_37 -> V_40 ) ;
switch ( V_6 -> type ) {
case V_42 :
V_872 = true ;
break;
default:
break;
}
V_39 ++ ;
}
if ( V_872 && F_516 ( V_12 ) && V_39 < 2 ) {
F_148 ( L_130 ,
V_12 -> V_760 . V_763 ) ;
return V_12 -> V_760 . V_763 ;
}
return 120000 ;
}
static void F_385 ( struct V_89 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_4 V_121 ;
V_121 = 0 ;
switch ( V_28 -> V_93 -> V_706 ) {
case 18 :
V_121 |= V_861 ;
break;
case 24 :
V_121 |= V_862 ;
break;
case 30 :
V_121 |= V_863 ;
break;
case 36 :
V_121 |= V_923 ;
break;
default:
F_142 () ;
}
if ( V_28 -> V_93 -> V_858 )
V_121 |= ( V_859 | V_860 ) ;
if ( V_28 -> V_93 -> V_8 . V_94 . V_345 & V_843 )
V_121 |= V_248 ;
else
V_121 |= V_867 ;
if ( V_28 -> V_93 -> V_868 )
V_121 |= V_869 ;
F_124 ( F_50 ( V_4 ) , V_121 ) ;
F_125 ( F_50 ( V_4 ) ) ;
}
static void F_395 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_6 V_924 = 0x7800 ;
if ( V_28 -> V_93 -> V_868 )
V_924 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_124 ( F_582 ( V_4 ) , V_924 << 16 ) ;
F_124 ( F_583 ( V_4 ) , 0 ) ;
F_124 ( F_584 ( V_4 ) , V_924 ) ;
F_124 ( F_585 ( V_4 ) , 0 ) ;
F_124 ( F_586 ( V_4 ) , 0 ) ;
F_124 ( F_587 ( V_4 ) , V_924 << 16 ) ;
F_124 ( F_588 ( V_4 ) , 0 ) ;
F_124 ( F_589 ( V_4 ) , 0 ) ;
F_124 ( F_590 ( V_4 ) , 0 ) ;
if ( F_49 ( V_10 ) -> V_105 > 6 ) {
T_6 V_925 = 0 ;
if ( V_28 -> V_93 -> V_868 )
V_925 = ( 16 * ( 1 << 12 ) / 255 ) & 0x1fff ;
F_124 ( F_591 ( V_4 ) , V_925 ) ;
F_124 ( F_592 ( V_4 ) , V_925 ) ;
F_124 ( F_593 ( V_4 ) , V_925 ) ;
F_124 ( F_594 ( V_4 ) , 0 ) ;
} else {
T_4 V_419 = V_926 ;
if ( V_28 -> V_93 -> V_868 )
V_419 |= V_927 ;
F_124 ( F_594 ( V_4 ) , V_419 ) ;
}
}
static void F_394 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
enum V_96 V_98 = V_28 -> V_93 -> V_98 ;
T_4 V_121 ;
V_121 = 0 ;
if ( F_227 ( V_10 ) && V_28 -> V_93 -> V_858 )
V_121 |= ( V_859 | V_860 ) ;
if ( V_28 -> V_93 -> V_8 . V_94 . V_345 & V_843 )
V_121 |= V_248 ;
else
V_121 |= V_867 ;
F_124 ( F_50 ( V_98 ) , V_121 ) ;
F_125 ( F_50 ( V_98 ) ) ;
F_124 ( F_367 ( V_28 -> V_4 ) , V_928 ) ;
F_125 ( F_367 ( V_28 -> V_4 ) ) ;
if ( F_228 ( V_10 ) || F_49 ( V_10 ) -> V_105 >= 9 ) {
V_121 = 0 ;
switch ( V_28 -> V_93 -> V_706 ) {
case 18 :
V_121 |= V_929 ;
break;
case 24 :
V_121 |= V_930 ;
break;
case 30 :
V_121 |= V_931 ;
break;
case 36 :
V_121 |= V_932 ;
break;
default:
F_142 () ;
}
if ( V_28 -> V_93 -> V_858 )
V_121 |= V_933 | V_934 ;
F_124 ( F_595 ( V_4 ) , V_121 ) ;
}
}
static bool F_596 ( struct V_89 * V_29 ,
struct V_31 * V_32 ,
T_2 * clock ,
bool * V_871 ,
T_2 * V_764 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_18 ;
const T_3 * V_41 ;
bool V_298 , V_872 = false ;
V_872 = F_12 ( V_32 , V_42 ) ;
V_18 = F_581 ( V_32 ) ;
V_41 = F_18 ( V_32 , V_18 ) ;
V_298 = V_12 -> V_264 . V_874 ( V_41 , V_32 ,
V_32 -> V_798 ,
V_18 , NULL , clock ) ;
if ( ! V_298 )
return false ;
if ( V_872 && V_12 -> V_875 ) {
* V_871 =
V_12 -> V_264 . V_874 ( V_41 , V_32 ,
V_12 -> V_876 ,
V_18 , clock ,
V_764 ) ;
}
return true ;
}
int F_493 ( int V_88 , int V_703 , int V_935 )
{
T_1 V_936 = V_88 * V_935 * 21 / 20 ;
return F_245 ( V_936 , V_703 * 8 ) ;
}
static bool F_597 ( struct V_66 * V_66 , int V_937 )
{
return F_26 ( V_66 ) < V_937 * V_66 -> V_25 ;
}
static T_4 F_598 ( struct V_28 * V_28 ,
struct V_31 * V_32 ,
T_1 * V_765 ,
T_2 * V_764 , T_1 * V_766 )
{
struct V_89 * V_29 = & V_28 -> V_8 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_33 * V_34 = V_32 -> V_8 . V_34 ;
struct V_35 * V_3 ;
struct V_36 * V_37 ;
struct V_1 * V_6 ;
T_4 V_66 ;
int V_937 , V_39 = 0 , V_38 ;
bool V_872 = false , V_821 = false ;
F_13 (state, connector, connector_state, i) {
if ( V_37 -> V_29 != V_32 -> V_8 . V_29 )
continue;
V_6 = F_14 ( V_37 -> V_40 ) ;
switch ( V_6 -> type ) {
case V_42 :
V_872 = true ;
break;
case V_53 :
case V_50 :
V_821 = true ;
break;
default:
break;
}
V_39 ++ ;
}
V_937 = 21 ;
if ( V_872 ) {
if ( ( F_516 ( V_12 ) &&
V_12 -> V_760 . V_763 == 100000 ) ||
( F_54 ( V_10 ) && F_16 ( V_10 ) ) )
V_937 = 25 ;
} else if ( V_32 -> V_834 )
V_937 = 20 ;
if ( F_597 ( & V_32 -> V_66 , V_937 ) )
* V_765 |= V_938 ;
if ( V_766 && ( V_764 -> V_19 < V_937 * V_764 -> V_25 ) )
* V_766 |= V_938 ;
V_66 = 0 ;
if ( V_872 )
V_66 |= V_822 ;
else
V_66 |= V_823 ;
V_66 |= ( V_32 -> V_573 - 1 )
<< V_939 ;
if ( V_821 )
V_66 |= V_825 ;
if ( V_32 -> V_510 )
V_66 |= V_825 ;
V_66 |= ( 1 << ( V_32 -> V_66 . V_23 - 1 ) ) << V_827 ;
V_66 |= ( 1 << ( V_32 -> V_66 . V_23 - 1 ) ) << V_828 ;
switch ( V_32 -> V_66 . V_24 ) {
case 5 :
V_66 |= V_829 ;
break;
case 7 :
V_66 |= V_830 ;
break;
case 10 :
V_66 |= V_831 ;
break;
case 14 :
V_66 |= V_832 ;
break;
}
if ( V_872 && F_516 ( V_12 ) && V_39 < 2 )
V_66 |= V_836 ;
else
V_66 |= V_837 ;
return V_66 | V_123 ;
}
static int F_599 ( struct V_28 * V_29 ,
struct V_31 * V_32 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock , V_764 ;
T_1 V_66 = 0 , V_765 = 0 , V_766 = 0 ;
bool V_870 , V_871 = false ;
bool V_872 = false ;
struct V_127 * V_130 ;
memset ( & V_32 -> V_211 , 0 ,
sizeof( V_32 -> V_211 ) ) ;
V_872 = F_10 ( V_29 , V_42 ) ;
F_52 ( ! ( F_54 ( V_10 ) || F_100 ( V_10 ) ) ,
L_145 , F_600 ( V_10 ) ) ;
V_870 = F_596 ( & V_29 -> V_8 , V_32 , & clock ,
& V_871 , & V_764 ) ;
if ( ! V_870 && ! V_32 -> V_873 ) {
F_127 ( L_134 ) ;
return - V_300 ;
}
if ( ! V_32 -> V_873 ) {
V_32 -> V_66 . V_25 = clock . V_25 ;
V_32 -> V_66 . V_20 = clock . V_20 ;
V_32 -> V_66 . V_21 = clock . V_21 ;
V_32 -> V_66 . V_23 = clock . V_23 ;
V_32 -> V_66 . V_24 = clock . V_24 ;
}
if ( V_32 -> V_259 ) {
V_765 = F_518 ( & V_32 -> V_66 ) ;
if ( V_871 )
V_766 = F_518 ( & V_764 ) ;
V_66 = F_598 ( V_29 , V_32 ,
& V_765 , & V_764 ,
V_871 ? & V_766 : NULL ) ;
V_32 -> V_211 . V_66 = V_66 ;
V_32 -> V_211 . V_689 = V_765 ;
if ( V_871 )
V_32 -> V_211 . V_690 = V_766 ;
else
V_32 -> V_211 . V_690 = V_765 ;
V_130 = F_342 ( V_29 , V_32 ) ;
if ( V_130 == NULL ) {
F_145 ( L_146 ,
F_75 ( V_29 -> V_4 ) ) ;
return - V_300 ;
}
}
if ( V_872 && V_871 )
V_29 -> V_767 = true ;
else
V_29 -> V_767 = false ;
return 0 ;
}
static void F_601 ( struct V_28 * V_29 ,
struct V_752 * V_753 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
V_753 -> V_757 = F_5 ( F_526 ( V_4 ) ) ;
V_753 -> V_758 = F_5 ( F_527 ( V_4 ) ) ;
V_753 -> V_755 = F_5 ( F_523 ( V_4 ) )
& ~ V_505 ;
V_753 -> V_756 = F_5 ( F_525 ( V_4 ) ) ;
V_753 -> V_754 = ( ( F_5 ( F_523 ( V_4 ) )
& V_505 ) >> V_940 ) + 1 ;
}
static void F_602 ( struct V_28 * V_29 ,
enum V_96 V_96 ,
struct V_752 * V_753 ,
struct V_752 * V_770 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
if ( F_49 ( V_10 ) -> V_105 >= 5 ) {
V_753 -> V_757 = F_5 ( F_529 ( V_96 ) ) ;
V_753 -> V_758 = F_5 ( F_530 ( V_96 ) ) ;
V_753 -> V_755 = F_5 ( F_336 ( V_96 ) )
& ~ V_505 ;
V_753 -> V_756 = F_5 ( F_528 ( V_96 ) ) ;
V_753 -> V_754 = ( ( F_5 ( F_336 ( V_96 ) )
& V_505 ) >> V_940 ) + 1 ;
if ( V_770 && F_49 ( V_10 ) -> V_105 < 8 &&
V_29 -> V_93 -> V_771 ) {
V_770 -> V_757 = F_5 ( F_533 ( V_96 ) ) ;
V_770 -> V_758 = F_5 ( F_534 ( V_96 ) ) ;
V_770 -> V_755 = F_5 ( F_531 ( V_96 ) )
& ~ V_505 ;
V_770 -> V_756 = F_5 ( F_532 ( V_96 ) ) ;
V_770 -> V_754 = ( ( F_5 ( F_531 ( V_96 ) )
& V_505 ) >> V_940 ) + 1 ;
}
} else {
V_753 -> V_757 = F_5 ( F_537 ( V_4 ) ) ;
V_753 -> V_758 = F_5 ( F_538 ( V_4 ) ) ;
V_753 -> V_755 = F_5 ( F_535 ( V_4 ) )
& ~ V_505 ;
V_753 -> V_756 = F_5 ( F_536 ( V_4 ) ) ;
V_753 -> V_754 = ( ( F_5 ( F_535 ( V_4 ) )
& V_505 ) >> V_940 ) + 1 ;
}
}
void F_603 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
if ( V_210 -> V_259 )
F_601 ( V_29 , & V_210 -> V_773 ) ;
else
F_602 ( V_29 , V_210 -> V_98 ,
& V_210 -> V_773 ,
& V_210 -> V_774 ) ;
}
static void F_604 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
F_602 ( V_29 , V_210 -> V_98 ,
& V_210 -> V_568 , NULL ) ;
}
static void F_605 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_368 * V_369 = & V_210 -> V_369 ;
T_4 V_417 = 0 ;
int V_239 = - 1 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_29 -> V_370 ; V_38 ++ ) {
V_417 = F_5 ( F_234 ( V_29 -> V_4 , V_38 ) ) ;
if ( V_417 & V_418 && ! ( V_417 & V_941 ) ) {
V_239 = V_38 ;
V_210 -> V_439 . V_120 = true ;
V_210 -> V_439 . V_547 = F_5 ( F_235 ( V_29 -> V_4 , V_38 ) ) ;
V_210 -> V_439 . V_340 = F_5 ( F_236 ( V_29 -> V_4 , V_38 ) ) ;
break;
}
}
V_369 -> V_410 = V_239 ;
if ( V_239 >= 0 ) {
V_369 -> V_535 |= ( 1 << V_532 ) ;
} else {
V_369 -> V_535 &= ~ ( 1 << V_532 ) ;
}
}
static void
F_606 ( struct V_28 * V_29 ,
struct V_333 * V_334 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_121 , V_8 , V_310 , V_942 , V_341 ;
int V_4 = V_29 -> V_4 ;
int V_881 , V_269 ;
unsigned int V_882 ;
struct V_280 * V_92 ;
struct V_883 * V_884 ;
V_884 = F_482 ( sizeof( * V_884 ) , V_525 ) ;
if ( ! V_884 ) {
F_148 ( L_135 ) ;
return;
}
V_92 = & V_884 -> V_8 ;
V_121 = F_5 ( F_90 ( V_4 , 0 ) ) ;
if ( ! ( V_121 & V_170 ) )
goto error;
V_269 = V_121 & V_943 ;
V_881 = F_198 ( V_269 ,
V_121 & V_374 ,
V_121 & V_944 ) ;
V_92 -> V_269 = V_881 ;
V_92 -> V_366 = F_176 ( V_881 , 0 ) * 8 ;
V_341 = V_121 & V_945 ;
switch ( V_341 ) {
case V_946 :
V_92 -> V_292 [ 0 ] = V_273 ;
break;
case V_385 :
V_334 -> V_341 = V_342 ;
V_92 -> V_292 [ 0 ] = V_274 ;
break;
case V_386 :
V_92 -> V_292 [ 0 ] = V_275 ;
break;
case V_387 :
V_92 -> V_292 [ 0 ] = V_276 ;
break;
default:
F_178 ( V_341 ) ;
goto error;
}
V_8 = F_5 ( F_241 ( V_4 , 0 ) ) & 0xfffff000 ;
V_334 -> V_8 = V_8 ;
V_310 = F_5 ( F_246 ( V_4 , 0 ) ) ;
V_121 = F_5 ( F_247 ( V_4 , 0 ) ) ;
V_92 -> V_277 = ( ( V_121 >> 16 ) & 0xfff ) + 1 ;
V_92 -> V_344 = ( ( V_121 >> 0 ) & 0x1fff ) + 1 ;
V_121 = F_5 ( F_248 ( V_4 , 0 ) ) ;
V_942 = F_230 ( V_10 , V_92 -> V_292 [ 0 ] ,
V_92 -> V_269 ) ;
V_92 -> V_290 [ 0 ] = ( V_121 & 0x3ff ) * V_942 ;
V_882 = F_179 ( V_10 , V_92 -> V_277 ,
V_92 -> V_269 ,
V_92 -> V_292 [ 0 ] ) ;
V_334 -> V_340 = V_92 -> V_290 [ 0 ] * V_882 ;
F_148 ( L_147 ,
F_75 ( V_4 ) , V_92 -> V_344 , V_92 -> V_277 ,
V_92 -> V_366 , V_8 , V_92 -> V_290 [ 0 ] ,
V_334 -> V_340 ) ;
V_334 -> V_92 = V_884 ;
return;
error:
F_210 ( V_92 ) ;
}
static void F_607 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_215 ;
V_215 = F_5 ( F_281 ( V_29 -> V_4 ) ) ;
if ( V_215 & V_548 ) {
V_210 -> V_439 . V_120 = true ;
V_210 -> V_439 . V_547 = F_5 ( F_282 ( V_29 -> V_4 ) ) ;
V_210 -> V_439 . V_340 = F_5 ( F_283 ( V_29 -> V_4 ) ) ;
if ( F_608 ( V_10 ) ) {
F_3 ( ( V_215 & V_947 ) !=
F_355 ( V_29 -> V_4 ) ) ;
}
}
}
static void
F_609 ( struct V_28 * V_29 ,
struct V_333 * V_334 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_121 , V_8 , V_310 ;
int V_4 = V_29 -> V_4 ;
int V_881 , V_269 ;
unsigned int V_882 ;
struct V_280 * V_92 ;
struct V_883 * V_884 ;
V_121 = F_5 ( F_84 ( V_4 ) ) ;
if ( ! ( V_121 & V_165 ) )
return;
V_884 = F_482 ( sizeof( * V_884 ) , V_525 ) ;
if ( ! V_884 ) {
F_148 ( L_135 ) ;
return;
}
V_92 = & V_884 -> V_8 ;
if ( F_49 ( V_10 ) -> V_105 >= 4 ) {
if ( V_121 & V_360 ) {
V_334 -> V_341 = V_342 ;
V_92 -> V_292 [ 0 ] = V_274 ;
}
}
V_269 = V_121 & V_885 ;
V_881 = F_197 ( V_269 ) ;
V_92 -> V_269 = V_881 ;
V_92 -> V_366 = F_176 ( V_881 , 0 ) * 8 ;
V_8 = F_5 ( F_215 ( V_4 ) ) & 0xfffff000 ;
if ( F_227 ( V_10 ) || F_228 ( V_10 ) ) {
V_310 = F_5 ( F_229 ( V_4 ) ) ;
} else {
if ( V_334 -> V_341 )
V_310 = F_5 ( F_224 ( V_4 ) ) ;
else
V_310 = F_5 ( F_225 ( V_4 ) ) ;
}
V_334 -> V_8 = V_8 ;
V_121 = F_5 ( F_280 ( V_4 ) ) ;
V_92 -> V_344 = ( ( V_121 >> 16 ) & 0xfff ) + 1 ;
V_92 -> V_277 = ( ( V_121 >> 0 ) & 0xfff ) + 1 ;
V_121 = F_5 ( F_223 ( V_4 ) ) ;
V_92 -> V_290 [ 0 ] = V_121 & 0xffffffc0 ;
V_882 = F_179 ( V_10 , V_92 -> V_277 ,
V_92 -> V_269 ,
V_92 -> V_292 [ 0 ] ) ;
V_334 -> V_340 = V_92 -> V_290 [ 0 ] * V_882 ;
F_148 ( L_147 ,
F_75 ( V_4 ) , V_92 -> V_344 , V_92 -> V_277 ,
V_92 -> V_366 , V_8 , V_92 -> V_290 [ 0 ] ,
V_334 -> V_340 ) ;
V_334 -> V_92 = V_884 ;
}
static bool F_610 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_215 ;
if ( ! F_81 ( V_12 ,
F_415 ( V_29 -> V_4 ) ) )
return false ;
V_210 -> V_98 = (enum V_96 ) V_29 -> V_4 ;
V_210 -> V_128 = V_519 ;
V_215 = F_5 ( F_50 ( V_29 -> V_4 ) ) ;
if ( ! ( V_215 & V_163 ) )
return false ;
switch ( V_215 & V_245 ) {
case V_861 :
V_210 -> V_706 = 18 ;
break;
case V_862 :
V_210 -> V_706 = 24 ;
break;
case V_863 :
V_210 -> V_706 = 30 ;
break;
case V_923 :
V_210 -> V_706 = 36 ;
break;
default:
break;
}
if ( V_215 & V_869 )
V_210 -> V_868 = true ;
if ( F_5 ( F_102 ( V_29 -> V_4 ) ) & V_178 ) {
struct V_127 * V_130 ;
V_210 -> V_259 = true ;
V_215 = F_5 ( F_70 ( V_29 -> V_4 ) ) ;
V_210 -> V_454 = ( ( V_453 & V_215 ) >>
V_948 ) + 1 ;
F_604 ( V_29 , V_210 ) ;
if ( F_54 ( V_12 -> V_10 ) ) {
V_210 -> V_128 =
(enum V_520 ) V_29 -> V_4 ;
} else {
V_215 = F_5 ( V_508 ) ;
if ( V_215 & F_338 ( V_29 -> V_4 ) )
V_210 -> V_128 = V_509 ;
else
V_210 -> V_128 = V_949 ;
}
V_130 = & V_12 -> V_129 [ V_210 -> V_128 ] ;
F_3 ( ! V_130 -> V_133 ( V_12 , V_130 ,
& V_210 -> V_211 ) ) ;
V_215 = V_210 -> V_211 . V_66 ;
V_210 -> V_573 =
( ( V_215 & V_950 )
>> V_939 ) + 1 ;
F_611 ( V_29 , V_210 ) ;
} else {
V_210 -> V_573 = 1 ;
}
F_562 ( V_29 , V_210 ) ;
F_607 ( V_29 , V_210 ) ;
return true ;
}
static void F_612 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_28 * V_29 ;
F_135 (dev, crtc)
F_58 ( V_29 -> V_90 , L_148 ,
F_75 ( V_29 -> V_4 ) ) ;
F_58 ( F_5 ( V_951 ) , L_149 ) ;
F_58 ( F_5 ( V_952 ) & V_953 , L_150 ) ;
F_58 ( F_5 ( V_954 ) & V_955 , L_151 ) ;
F_58 ( F_5 ( V_956 ) & V_955 , L_152 ) ;
F_58 ( F_5 ( V_957 ) & V_958 , L_153 ) ;
F_58 ( F_5 ( V_959 ) & V_960 ,
L_154 ) ;
if ( F_227 ( V_10 ) )
F_58 ( F_5 ( V_961 ) & V_960 ,
L_155 ) ;
F_58 ( F_5 ( V_962 ) & V_963 ,
L_156 ) ;
F_58 ( F_5 ( V_964 ) & V_965 ,
L_157 ) ;
F_58 ( F_5 ( V_966 ) & V_967 , L_158 ) ;
F_58 ( F_613 ( V_12 ) , L_159 ) ;
}
static T_4 F_614 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
if ( F_227 ( V_10 ) )
return F_5 ( V_968 ) ;
else
return F_5 ( V_969 ) ;
}
static void F_615 ( struct V_11 * V_12 , T_4 V_121 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
if ( F_227 ( V_10 ) ) {
F_60 ( & V_12 -> V_551 . V_552 ) ;
if ( F_361 ( V_12 , V_970 ,
V_121 ) )
F_127 ( L_160 ) ;
F_62 ( & V_12 -> V_551 . V_552 ) ;
} else {
F_124 ( V_969 , V_121 ) ;
F_125 ( V_969 ) ;
}
}
static void F_616 ( struct V_11 * V_12 ,
bool V_971 , bool V_972 )
{
T_4 V_121 ;
F_612 ( V_12 ) ;
V_121 = F_5 ( V_717 ) ;
if ( V_971 ) {
V_121 |= V_719 ;
F_124 ( V_717 , V_121 ) ;
if ( F_575 ( F_5 ( V_717 ) &
V_973 , 1 ) )
F_127 ( L_161 ) ;
V_121 = F_5 ( V_717 ) ;
}
V_121 |= V_974 ;
F_124 ( V_717 , V_121 ) ;
F_125 ( V_717 ) ;
if ( F_51 ( ( F_5 ( V_717 ) & V_640 ) == 0 , 1 ) )
F_127 ( L_162 ) ;
V_121 = F_614 ( V_12 ) ;
V_121 |= V_975 ;
F_615 ( V_12 , V_121 ) ;
F_617 ( 100 ) ;
if ( F_51 ( ( F_614 ( V_12 ) & V_976 ) == 0 ,
1 ) )
F_127 ( L_163 ) ;
if ( V_972 ) {
V_121 = F_5 ( V_717 ) ;
V_121 |= V_977 ;
F_124 ( V_717 , V_121 ) ;
F_125 ( V_717 ) ;
}
}
static void F_618 ( struct V_11 * V_12 )
{
T_4 V_121 ;
V_121 = F_5 ( V_717 ) ;
if ( ( V_121 & ( V_640 | V_974 | V_719 |
V_977 ) ) == V_640 )
return;
F_619 ( V_12 , V_978 ) ;
if ( V_121 & V_977 ) {
V_121 &= ~ V_977 ;
F_124 ( V_717 , V_121 ) ;
F_125 ( V_717 ) ;
}
V_121 = F_614 ( V_12 ) ;
V_121 |= V_979 ;
V_121 &= ~ V_975 ;
F_615 ( V_12 , V_121 ) ;
V_121 = F_5 ( V_717 ) ;
V_121 &= ~ V_974 ;
F_124 ( V_717 , V_121 ) ;
if ( F_51 ( F_5 ( V_717 ) & V_640 , 5 ) )
F_127 ( L_164 ) ;
if ( V_121 & V_719 ) {
V_121 = F_5 ( V_717 ) ;
V_121 &= ~ V_719 ;
F_124 ( V_717 , V_121 ) ;
if ( F_575 ( ( F_5 ( V_717 ) &
V_973 ) == 0 , 1 ) )
F_127 ( L_165 ) ;
}
F_620 ( V_12 , V_978 ) ;
}
void F_621 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_121 ;
F_148 ( L_166 ) ;
if ( V_12 -> V_915 == V_916 ) {
V_121 = F_5 ( V_980 ) ;
V_121 &= ~ V_981 ;
F_124 ( V_980 , V_121 ) ;
}
F_578 ( V_10 ) ;
F_616 ( V_12 , true , true ) ;
}
void F_622 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_121 ;
F_148 ( L_167 ) ;
F_618 ( V_12 ) ;
F_579 ( V_10 ) ;
if ( V_12 -> V_915 == V_916 ) {
V_121 = F_5 ( V_980 ) ;
V_121 |= V_981 ;
F_124 ( V_980 , V_121 ) ;
}
F_623 ( V_10 ) ;
}
static void F_624 ( struct V_33 * V_683 )
{
struct V_9 * V_10 = V_683 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_672 = F_449 ( V_10 , NULL ) ;
int V_684 ;
if ( F_3 ( V_672 < 0 ) )
return;
V_684 = F_448 ( V_12 , V_672 ) ;
if ( V_684 != V_12 -> V_620 )
F_420 ( V_10 , V_684 ) ;
}
static int F_625 ( struct V_28 * V_29 ,
struct V_31 * V_32 )
{
if ( ! F_626 ( V_29 , V_32 ) )
return - V_300 ;
V_29 -> V_767 = false ;
return 0 ;
}
static void F_627 ( struct V_11 * V_12 ,
enum V_108 V_108 ,
struct V_31 * V_210 )
{
switch ( V_108 ) {
case V_584 :
V_210 -> V_982 = V_635 ;
V_210 -> V_128 = V_983 ;
break;
case V_110 :
V_210 -> V_982 = V_984 ;
V_210 -> V_128 = V_985 ;
break;
case V_112 :
V_210 -> V_982 = V_986 ;
V_210 -> V_128 = V_987 ;
break;
default:
F_127 ( L_168 ) ;
}
}
static void F_628 ( struct V_11 * V_12 ,
enum V_108 V_108 ,
struct V_31 * V_210 )
{
T_1 V_441 , V_988 ;
V_441 = F_5 ( V_989 ) & F_629 ( V_108 ) ;
V_210 -> V_982 = V_441 >> ( V_108 * 3 + 1 ) ;
switch ( V_210 -> V_982 ) {
case V_635 :
V_988 = F_5 ( V_634 ) ;
V_210 -> V_211 . V_990 = V_988 & 0x3f ;
break;
case V_984 :
V_210 -> V_128 = V_983 ;
break;
case V_986 :
V_210 -> V_128 = V_985 ;
break;
case V_991 :
V_210 -> V_128 = V_987 ;
break;
}
}
static void F_630 ( struct V_11 * V_12 ,
enum V_108 V_108 ,
struct V_31 * V_210 )
{
V_210 -> V_982 = F_5 ( F_631 ( V_108 ) ) ;
switch ( V_210 -> V_982 ) {
case V_992 :
V_210 -> V_128 = V_993 ;
break;
case V_994 :
V_210 -> V_128 = V_995 ;
break;
}
}
static void F_632 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_127 * V_130 ;
enum V_108 V_108 ;
T_4 V_215 ;
V_215 = F_5 ( F_67 ( V_210 -> V_98 ) ) ;
V_108 = ( V_215 & V_996 ) >> V_997 ;
if ( F_633 ( V_10 ) )
F_628 ( V_12 , V_108 , V_210 ) ;
else if ( F_19 ( V_10 ) )
F_627 ( V_12 , V_108 , V_210 ) ;
else
F_630 ( V_12 , V_108 , V_210 ) ;
if ( V_210 -> V_128 >= 0 ) {
V_130 = & V_12 -> V_129 [ V_210 -> V_128 ] ;
F_3 ( ! V_130 -> V_133 ( V_12 , V_130 ,
& V_210 -> V_211 ) ) ;
}
if ( F_49 ( V_10 ) -> V_105 < 9 &&
( V_108 == V_998 ) && F_5 ( V_256 ) & V_178 ) {
V_210 -> V_259 = true ;
V_215 = F_5 ( F_70 ( V_142 ) ) ;
V_210 -> V_454 = ( ( V_453 & V_215 ) >>
V_948 ) + 1 ;
F_604 ( V_29 , V_210 ) ;
}
}
static bool F_634 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_583 V_999 ;
T_4 V_215 ;
if ( ! F_81 ( V_12 ,
F_415 ( V_29 -> V_4 ) ) )
return false ;
V_210 -> V_98 = (enum V_96 ) V_29 -> V_4 ;
V_210 -> V_128 = V_519 ;
V_215 = F_5 ( F_67 ( V_572 ) ) ;
if ( V_215 & V_135 ) {
enum V_4 V_1000 ;
switch ( V_215 & V_1001 ) {
default:
F_52 ( 1 , L_169 ) ;
case V_1002 :
case V_1003 :
V_1000 = V_142 ;
break;
case V_1004 :
V_1000 = V_151 ;
break;
case V_1005 :
V_1000 = V_504 ;
break;
}
if ( V_1000 == V_29 -> V_4 )
V_210 -> V_98 = V_572 ;
}
if ( ! F_81 ( V_12 ,
F_82 ( V_210 -> V_98 ) ) )
return false ;
V_215 = F_5 ( F_50 ( V_210 -> V_98 ) ) ;
if ( ! ( V_215 & V_163 ) )
return false ;
F_632 ( V_29 , V_210 ) ;
F_562 ( V_29 , V_210 ) ;
if ( F_49 ( V_10 ) -> V_105 >= 9 ) {
F_635 ( V_10 , V_29 , V_210 ) ;
}
V_999 = F_416 ( V_29 -> V_4 ) ;
if ( F_49 ( V_10 ) -> V_105 >= 9 ) {
V_210 -> V_369 . V_410 = - 1 ;
V_210 -> V_369 . V_535 &= ~ ( 1 << V_532 ) ;
}
if ( F_81 ( V_12 , V_999 ) ) {
if ( F_49 ( V_10 ) -> V_105 == 9 )
F_605 ( V_29 , V_210 ) ;
else if ( F_49 ( V_10 ) -> V_105 < 9 )
F_607 ( V_29 , V_210 ) ;
else
F_178 ( F_49 ( V_10 ) -> V_105 ) ;
}
if ( F_227 ( V_10 ) )
V_210 -> V_550 = F_389 ( V_29 ) &&
( F_5 ( V_554 ) & V_555 ) ;
if ( V_210 -> V_98 != V_572 ) {
V_210 -> V_573 =
F_5 ( F_393 ( V_210 -> V_98 ) ) + 1 ;
} else {
V_210 -> V_573 = 1 ;
}
return true ;
}
static void F_636 ( struct V_89 * V_29 , T_1 V_8 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
T_4 V_1006 = 0 , V_340 = 0 ;
if ( V_8 ) {
unsigned int V_344 = V_28 -> V_8 . V_1007 -> V_34 -> V_1008 ;
unsigned int V_277 = V_28 -> V_8 . V_1007 -> V_34 -> V_1009 ;
unsigned int V_343 = F_637 ( V_344 ) * 4 ;
switch ( V_343 ) {
default:
F_177 ( 1 , L_170 ,
V_344 , V_343 ) ;
V_343 = 256 ;
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
}
V_1006 |= V_158 |
V_1010 |
V_1011 |
F_638 ( V_343 ) ;
V_340 = ( V_277 << 12 ) | V_344 ;
}
if ( V_28 -> V_1012 != 0 &&
( V_28 -> V_1013 != V_8 ||
V_28 -> V_1014 != V_340 ||
V_28 -> V_1012 != V_1006 ) ) {
F_124 ( V_157 , 0 ) ;
F_125 ( V_157 ) ;
V_28 -> V_1012 = 0 ;
}
if ( V_28 -> V_1013 != V_8 ) {
F_124 ( V_1015 , V_8 ) ;
V_28 -> V_1013 = V_8 ;
}
if ( V_28 -> V_1014 != V_340 ) {
F_124 ( V_1016 , V_340 ) ;
V_28 -> V_1014 = V_340 ;
}
if ( V_28 -> V_1012 != V_1006 ) {
F_124 ( V_157 , V_1006 ) ;
F_125 ( V_157 ) ;
V_28 -> V_1012 = V_1006 ;
}
}
static void F_639 ( struct V_89 * V_29 , T_1 V_8 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_4 V_1006 ;
V_1006 = 0 ;
if ( V_8 ) {
V_1006 = V_1017 ;
switch ( V_28 -> V_8 . V_1007 -> V_34 -> V_1008 ) {
case 64 :
V_1006 |= V_1018 ;
break;
case 128 :
V_1006 |= V_1019 ;
break;
case 256 :
V_1006 |= V_1020 ;
break;
default:
F_178 ( V_28 -> V_8 . V_1007 -> V_34 -> V_1008 ) ;
return;
}
V_1006 |= V_4 << 28 ;
if ( F_227 ( V_10 ) || F_228 ( V_10 ) )
V_1006 |= V_1021 ;
}
if ( V_29 -> V_1007 -> V_34 -> V_287 == F_222 ( V_363 ) )
V_1006 |= V_1022 ;
if ( V_28 -> V_1012 != V_1006 ) {
F_124 ( F_79 ( V_4 ) , V_1006 ) ;
F_125 ( F_79 ( V_4 ) ) ;
V_28 -> V_1012 = V_1006 ;
}
F_124 ( F_640 ( V_4 ) , V_8 ) ;
F_125 ( F_640 ( V_4 ) ) ;
V_28 -> V_1013 = V_8 ;
}
static void F_377 ( struct V_89 * V_29 ,
bool V_237 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
int V_266 = V_29 -> V_1023 ;
int V_267 = V_29 -> V_1024 ;
T_1 V_8 = 0 , V_547 = 0 ;
if ( V_237 )
V_8 = V_28 -> V_1025 ;
if ( V_266 >= V_28 -> V_93 -> V_358 )
V_8 = 0 ;
if ( V_267 >= V_28 -> V_93 -> V_357 )
V_8 = 0 ;
if ( V_266 < 0 ) {
if ( V_266 + V_28 -> V_8 . V_1007 -> V_34 -> V_1008 <= 0 )
V_8 = 0 ;
V_547 |= V_1026 << V_1027 ;
V_266 = - V_266 ;
}
V_547 |= V_266 << V_1027 ;
if ( V_267 < 0 ) {
if ( V_267 + V_28 -> V_8 . V_1007 -> V_34 -> V_1009 <= 0 )
V_8 = 0 ;
V_547 |= V_1026 << V_1028 ;
V_267 = - V_267 ;
}
V_547 |= V_267 << V_1028 ;
if ( V_8 == 0 && V_28 -> V_1013 == 0 )
return;
F_124 ( F_641 ( V_4 ) , V_547 ) ;
if ( F_165 ( V_10 ) &&
V_29 -> V_1007 -> V_34 -> V_287 == F_222 ( V_363 ) ) {
V_8 += ( V_28 -> V_8 . V_1007 -> V_34 -> V_1009 *
V_28 -> V_8 . V_1007 -> V_34 -> V_1008 - 1 ) * 4 ;
}
if ( F_77 ( V_10 ) || F_78 ( V_10 ) )
F_636 ( V_29 , V_8 ) ;
else
F_639 ( V_29 , V_8 ) ;
}
static bool F_642 ( struct V_9 * V_10 ,
T_4 V_344 , T_4 V_277 )
{
if ( V_344 == 0 || V_277 == 0 )
return false ;
if ( F_77 ( V_10 ) || F_78 ( V_10 ) ) {
if ( ( V_344 & 63 ) != 0 )
return false ;
if ( V_344 > ( F_77 ( V_10 ) ? 64 : 512 ) )
return false ;
if ( V_277 > 1023 )
return false ;
} else {
switch ( V_344 | V_277 ) {
case 256 :
case 128 :
if ( F_24 ( V_10 ) )
return false ;
case 64 :
break;
default:
return false ;
}
}
return true ;
}
static void F_643 ( struct V_89 * V_29 , T_5 * V_1029 , T_5 * V_1030 ,
T_5 * V_1031 , T_4 V_1032 , T_4 V_340 )
{
int V_1033 = ( V_1032 + V_340 > 256 ) ? 256 : V_1032 + V_340 , V_38 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
for ( V_38 = V_1032 ; V_38 < V_1033 ; V_38 ++ ) {
V_28 -> V_560 [ V_38 ] = V_1029 [ V_38 ] >> 8 ;
V_28 -> V_561 [ V_38 ] = V_1030 [ V_38 ] >> 8 ;
V_28 -> V_562 [ V_38 ] = V_1031 [ V_38 ] >> 8 ;
}
F_364 ( V_29 ) ;
}
struct V_280 *
F_644 ( struct V_9 * V_10 ,
struct V_335 * V_336 ,
struct V_295 * V_296 )
{
struct V_883 * V_884 ;
int V_298 ;
V_884 = F_482 ( sizeof( * V_884 ) , V_525 ) ;
if ( ! V_884 ) {
F_205 ( & V_296 -> V_8 ) ;
return F_645 ( - V_527 ) ;
}
V_298 = F_203 ( V_10 , V_884 , V_336 , V_296 ) ;
if ( V_298 )
goto V_73;
return & V_884 -> V_8 ;
V_73:
F_205 ( & V_296 -> V_8 ) ;
F_210 ( V_884 ) ;
return F_645 ( V_298 ) ;
}
static struct V_280 *
F_646 ( struct V_9 * V_10 ,
struct V_335 * V_336 ,
struct V_295 * V_296 )
{
struct V_280 * V_92 ;
int V_298 ;
V_298 = F_647 ( V_10 ) ;
if ( V_298 )
return F_645 ( V_298 ) ;
V_92 = F_644 ( V_10 , V_336 , V_296 ) ;
F_62 ( & V_10 -> V_299 ) ;
return V_92 ;
}
static T_1
F_648 ( int V_344 , int V_935 )
{
T_1 V_289 = F_245 ( V_344 * V_935 , 8 ) ;
return F_180 ( V_289 , 64 ) ;
}
static T_1
F_649 ( struct V_434 * V_419 , int V_935 )
{
T_1 V_289 = F_648 ( V_419 -> V_533 , V_935 ) ;
return F_650 ( V_289 * V_419 -> V_534 ) ;
}
static struct V_280 *
F_651 ( struct V_9 * V_10 ,
struct V_434 * V_419 ,
int V_1034 , int V_935 )
{
struct V_295 * V_296 ;
struct V_335 V_336 = { 0 } ;
V_296 = F_652 ( V_10 ,
F_649 ( V_419 , V_935 ) ) ;
if ( V_296 == NULL )
return F_645 ( - V_527 ) ;
V_336 . V_344 = V_419 -> V_533 ;
V_336 . V_277 = V_419 -> V_534 ;
V_336 . V_290 [ 0 ] = F_648 ( V_336 . V_344 ,
V_935 ) ;
V_336 . V_269 = F_653 ( V_935 , V_1034 ) ;
return F_646 ( V_10 , & V_336 , V_296 ) ;
}
static struct V_280 *
F_654 ( struct V_9 * V_10 ,
struct V_434 * V_419 )
{
#ifdef F_655
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_295 * V_296 ;
struct V_280 * V_92 ;
if ( ! V_12 -> V_1035 )
return NULL ;
if ( ! V_12 -> V_1035 -> V_92 )
return NULL ;
V_296 = V_12 -> V_1035 -> V_92 -> V_296 ;
F_122 ( ! V_296 ) ;
V_92 = & V_12 -> V_1035 -> V_92 -> V_8 ;
if ( V_92 -> V_290 [ 0 ] < F_648 ( V_419 -> V_533 ,
V_92 -> V_366 ) )
return NULL ;
if ( V_296 -> V_8 . V_340 < V_419 -> V_534 * V_92 -> V_290 [ 0 ] )
return NULL ;
return V_92 ;
#else
return NULL ;
#endif
}
static int F_656 ( struct V_33 * V_34 ,
struct V_89 * V_29 ,
struct V_434 * V_419 ,
struct V_280 * V_92 ,
int V_266 , int V_267 )
{
struct V_281 * V_282 ;
int V_533 , V_534 ;
int V_298 ;
V_282 = F_657 ( V_34 , V_29 -> V_91 ) ;
if ( F_451 ( V_282 ) )
return F_452 ( V_282 ) ;
if ( V_419 )
F_658 ( V_419 , & V_533 , & V_534 ) ;
else
V_533 = V_534 = 0 ;
V_298 = F_659 ( V_282 , V_92 ? V_29 : NULL ) ;
if ( V_298 )
return V_298 ;
F_660 ( V_282 , V_92 ) ;
V_282 -> V_1036 = 0 ;
V_282 -> V_1037 = 0 ;
V_282 -> V_1008 = V_533 ;
V_282 -> V_1009 = V_534 ;
V_282 -> V_402 = V_266 << 16 ;
V_282 -> V_403 = V_267 << 16 ;
V_282 -> V_404 = V_533 << 16 ;
V_282 -> V_405 = V_534 << 16 ;
return 0 ;
}
bool F_661 ( struct V_35 * V_3 ,
struct V_434 * V_419 ,
struct V_1038 * V_1039 ,
struct V_1040 * V_1041 )
{
struct V_28 * V_28 ;
struct V_1 * V_1 =
F_662 ( V_3 ) ;
struct V_89 * V_1042 ;
struct V_696 * V_6 = & V_1 -> V_8 ;
struct V_89 * V_29 = NULL ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_280 * V_92 ;
struct V_1043 * V_93 = & V_10 -> V_1044 ;
struct V_33 * V_34 = NULL ;
struct V_36 * V_37 ;
struct V_31 * V_32 ;
int V_298 , V_38 = - 1 ;
F_148 ( L_171 ,
V_3 -> V_8 . V_239 , V_3 -> V_134 ,
V_6 -> V_8 . V_239 , V_6 -> V_134 ) ;
V_459:
V_298 = F_257 ( & V_93 -> V_1045 , V_1041 ) ;
if ( V_298 )
goto V_1046;
if ( V_6 -> V_29 ) {
V_29 = V_6 -> V_29 ;
V_298 = F_257 ( & V_29 -> V_422 , V_1041 ) ;
if ( V_298 )
goto V_1046;
V_298 = F_257 ( & V_29 -> V_91 -> V_422 , V_1041 ) ;
if ( V_298 )
goto V_1046;
V_1039 -> V_1047 = V_3 -> V_694 ;
V_1039 -> V_1048 = false ;
if ( V_3 -> V_694 != V_697 )
V_3 -> V_1049 -> V_694 ( V_3 , V_697 ) ;
return true ;
}
F_211 (dev, possible_crtc) {
V_38 ++ ;
if ( ! ( V_6 -> V_1050 & ( 1 << V_38 ) ) )
continue;
if ( V_1042 -> V_34 -> V_241 )
continue;
if ( F_33 ( V_1042 ) -> V_1051 )
continue;
V_29 = V_1042 ;
break;
}
if ( ! V_29 ) {
F_148 ( L_172 ) ;
goto V_1046;
}
V_298 = F_257 ( & V_29 -> V_422 , V_1041 ) ;
if ( V_298 )
goto V_1046;
V_298 = F_257 ( & V_29 -> V_91 -> V_422 , V_1041 ) ;
if ( V_298 )
goto V_1046;
V_1 -> V_1052 = F_33 ( V_29 ) ;
F_663 ( V_3 ) -> V_1053 = V_1 ;
V_28 = F_33 ( V_29 ) ;
V_28 -> V_1051 = true ;
V_1039 -> V_1047 = V_3 -> V_694 ;
V_1039 -> V_1048 = true ;
V_1039 -> V_1054 = NULL ;
V_34 = F_664 ( V_10 ) ;
if ( ! V_34 )
return false ;
V_34 -> V_1055 = V_1041 ;
V_37 = F_665 ( V_34 , V_3 ) ;
if ( F_451 ( V_37 ) ) {
V_298 = F_452 ( V_37 ) ;
goto V_1056;
}
V_37 -> V_29 = V_29 ;
V_37 -> V_40 = & V_1 -> V_8 ;
V_32 = F_450 ( V_34 , V_28 ) ;
if ( F_451 ( V_32 ) ) {
V_298 = F_452 ( V_32 ) ;
goto V_1056;
}
V_32 -> V_8 . V_90 = V_32 -> V_8 . V_241 = true ;
if ( ! V_419 )
V_419 = & V_1057 ;
V_92 = F_654 ( V_10 , V_419 ) ;
if ( V_92 == NULL ) {
F_148 ( L_173 ) ;
V_92 = F_651 ( V_10 , V_419 , 24 , 32 ) ;
V_1039 -> V_1054 = V_92 ;
} else
F_148 ( L_174 ) ;
if ( F_451 ( V_92 ) ) {
F_148 ( L_175 ) ;
goto V_1056;
}
V_298 = F_656 ( V_34 , V_29 , V_419 , V_92 , 0 , 0 ) ;
if ( V_298 )
goto V_1056;
F_666 ( & V_32 -> V_8 . V_419 , V_419 ) ;
if ( F_667 ( V_29 , V_34 , true ) ) {
F_148 ( L_176 ) ;
if ( V_1039 -> V_1054 )
V_1039 -> V_1054 -> V_1049 -> V_1058 ( V_1039 -> V_1054 ) ;
goto V_1056;
}
V_29 -> V_91 -> V_29 = V_29 ;
F_300 ( V_10 , V_28 -> V_4 ) ;
return true ;
V_1056:
V_28 -> V_1051 = V_29 -> V_34 -> V_241 ;
V_1046:
F_668 ( V_34 ) ;
V_34 = NULL ;
if ( V_298 == - V_1059 ) {
F_669 ( V_1041 ) ;
goto V_459;
}
return false ;
}
void F_670 ( struct V_35 * V_3 ,
struct V_1038 * V_1039 ,
struct V_1040 * V_1041 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_1 * V_1 =
F_662 ( V_3 ) ;
struct V_696 * V_6 = & V_1 -> V_8 ;
struct V_89 * V_29 = V_6 -> V_29 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_33 * V_34 ;
struct V_36 * V_37 ;
struct V_31 * V_32 ;
int V_298 ;
F_148 ( L_171 ,
V_3 -> V_8 . V_239 , V_3 -> V_134 ,
V_6 -> V_8 . V_239 , V_6 -> V_134 ) ;
if ( V_1039 -> V_1048 ) {
V_34 = F_664 ( V_10 ) ;
if ( ! V_34 )
goto V_1056;
V_34 -> V_1055 = V_1041 ;
V_37 = F_665 ( V_34 , V_3 ) ;
if ( F_451 ( V_37 ) )
goto V_1056;
V_32 = F_450 ( V_34 , V_28 ) ;
if ( F_451 ( V_32 ) )
goto V_1056;
F_663 ( V_3 ) -> V_1053 = NULL ;
V_1 -> V_1052 = NULL ;
V_28 -> V_1051 = false ;
V_37 -> V_40 = NULL ;
V_37 -> V_29 = NULL ;
V_32 -> V_8 . V_241 = V_32 -> V_8 . V_90 = false ;
V_298 = F_656 ( V_34 , V_29 , NULL , NULL ,
0 , 0 ) ;
if ( V_298 )
goto V_1056;
V_298 = F_667 ( V_29 , V_34 , true ) ;
if ( V_298 )
goto V_1056;
if ( V_1039 -> V_1054 ) {
F_671 ( V_1039 -> V_1054 ) ;
F_207 ( V_1039 -> V_1054 ) ;
}
return;
}
if ( V_1039 -> V_1047 != V_697 )
V_3 -> V_1049 -> V_694 ( V_3 , V_1039 -> V_1047 ) ;
return;
V_1056:
F_148 ( L_177 ) ;
F_668 ( V_34 ) ;
}
static int F_672 ( struct V_9 * V_10 ,
const struct V_31 * V_210 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_66 = V_210 -> V_211 . V_66 ;
if ( ( V_66 & V_1060 ) == V_836 )
return V_12 -> V_760 . V_763 ;
else if ( F_4 ( V_10 ) )
return 120000 ;
else if ( ! F_24 ( V_10 ) )
return 96000 ;
else
return 48000 ;
}
static void F_571 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_210 -> V_98 ;
T_1 V_66 = V_210 -> V_211 . V_66 ;
T_1 V_765 ;
T_2 clock ;
int V_18 = F_672 ( V_10 , V_210 ) ;
if ( ( V_66 & V_1061 ) == 0 )
V_765 = V_210 -> V_211 . V_689 ;
else
V_765 = V_210 -> V_211 . V_690 ;
clock . V_20 = ( V_765 & V_1062 ) >> V_1063 ;
if ( F_21 ( V_10 ) ) {
clock . V_25 = F_673 ( ( V_765 & V_1064 ) >> V_1065 ) - 1 ;
clock . V_21 = ( V_765 & V_1066 ) >> V_1067 ;
} else {
clock . V_25 = ( V_765 & V_1068 ) >> V_1065 ;
clock . V_21 = ( V_765 & V_1069 ) >> V_1067 ;
}
if ( ! F_24 ( V_10 ) ) {
if ( F_21 ( V_10 ) )
clock . V_23 = F_673 ( ( V_66 & V_1070 ) >>
V_826 ) ;
else
clock . V_23 = F_673 ( ( V_66 & V_1071 ) >>
V_827 ) ;
switch ( V_66 & V_1072 ) {
case V_823 :
clock . V_24 = V_66 & V_829 ?
5 : 10 ;
break;
case V_822 :
clock . V_24 = V_66 & V_830 ?
7 : 14 ;
break;
default:
F_148 ( L_178
L_179 , ( int ) ( V_66 & V_1072 ) ) ;
return;
}
if ( F_21 ( V_10 ) )
F_25 ( V_18 , & clock ) ;
else
F_27 ( V_18 , & clock ) ;
} else {
T_1 V_1073 = F_137 ( V_10 ) ? 0 : F_5 ( V_153 ) ;
bool V_872 = ( V_4 == 1 ) && ( V_1073 & V_189 ) ;
if ( V_872 ) {
clock . V_23 = F_673 ( ( V_66 & V_1074 ) >>
V_827 ) ;
if ( V_1073 & V_1075 )
clock . V_24 = 7 ;
else
clock . V_24 = 14 ;
} else {
if ( V_66 & V_838 )
clock . V_23 = 2 ;
else {
clock . V_23 = ( ( V_66 & V_1076 ) >>
V_827 ) + 2 ;
}
if ( V_66 & V_839 )
clock . V_24 = 4 ;
else
clock . V_24 = 2 ;
}
F_27 ( V_18 , & clock ) ;
}
V_210 -> V_798 = clock . V_27 ;
}
int F_674 ( int V_1077 ,
const struct V_752 * V_753 )
{
if ( ! V_753 -> V_758 )
return 0 ;
return F_38 ( ( V_1078 ) V_753 -> V_757 * V_1077 , V_753 -> V_758 ) ;
}
static void F_611 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
F_571 ( V_29 , V_210 ) ;
V_210 -> V_8 . V_94 . V_95 =
F_674 ( F_6 ( V_10 ) * 10000 ,
& V_210 -> V_568 ) ;
}
struct V_434 * F_675 ( struct V_9 * V_10 ,
struct V_89 * V_29 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
enum V_96 V_98 = V_28 -> V_93 -> V_98 ;
struct V_434 * V_419 ;
struct V_31 V_210 ;
int V_1079 = F_5 ( F_319 ( V_98 ) ) ;
int V_1080 = F_5 ( F_323 ( V_98 ) ) ;
int V_1081 = F_5 ( F_325 ( V_98 ) ) ;
int V_1082 = F_5 ( F_329 ( V_98 ) ) ;
enum V_4 V_4 = V_28 -> V_4 ;
V_419 = F_482 ( sizeof( * V_419 ) , V_525 ) ;
if ( ! V_419 )
return NULL ;
V_210 . V_98 = (enum V_96 ) V_4 ;
V_210 . V_573 = 1 ;
V_210 . V_211 . V_66 = F_5 ( F_57 ( V_4 ) ) ;
V_210 . V_211 . V_689 = F_5 ( F_466 ( V_4 ) ) ;
V_210 . V_211 . V_690 = F_5 ( F_467 ( V_4 ) ) ;
F_571 ( V_28 , & V_210 ) ;
V_419 -> clock = V_210 . V_798 / V_210 . V_573 ;
V_419 -> V_533 = ( V_1079 & 0xffff ) + 1 ;
V_419 -> V_852 = ( ( V_1079 & 0xffff0000 ) >> 16 ) + 1 ;
V_419 -> V_711 = ( V_1080 & 0xffff ) + 1 ;
V_419 -> V_853 = ( ( V_1080 & 0xffff0000 ) >> 16 ) + 1 ;
V_419 -> V_534 = ( V_1081 & 0xffff ) + 1 ;
V_419 -> V_854 = ( ( V_1081 & 0xffff0000 ) >> 16 ) + 1 ;
V_419 -> V_855 = ( V_1082 & 0xffff ) + 1 ;
V_419 -> V_856 = ( ( V_1082 & 0xffff0000 ) >> 16 ) + 1 ;
F_676 ( V_419 ) ;
return V_419 ;
}
static void F_677 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
if ( ! F_165 ( V_10 ) )
return;
if ( ! V_12 -> V_875 )
return;
if ( ! F_564 ( V_10 ) && V_28 -> V_767 ) {
int V_4 = V_28 -> V_4 ;
int V_231 = F_57 ( V_4 ) ;
int V_66 ;
F_145 ( L_180 ) ;
F_73 ( V_12 , V_4 ) ;
V_66 = F_5 ( V_231 ) ;
V_66 |= V_1061 ;
F_124 ( V_231 , V_66 ) ;
F_300 ( V_10 , V_4 ) ;
V_66 = F_5 ( V_231 ) ;
if ( ! ( V_66 & V_1061 ) )
F_145 ( L_181 ) ;
}
}
void F_678 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_12 -> V_301 . V_1083 )
return;
F_188 ( V_12 ) ;
F_679 ( V_12 ) ;
if ( F_49 ( V_10 ) -> V_105 >= 6 )
F_680 ( V_12 ) ;
V_12 -> V_301 . V_1083 = true ;
}
void F_681 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_29 ;
if ( ! V_12 -> V_301 . V_1083 )
return;
V_12 -> V_301 . V_1083 = false ;
F_211 (dev, crtc) {
if ( ! V_29 -> V_91 -> V_92 )
continue;
F_677 ( V_29 ) ;
}
if ( F_49 ( V_10 ) -> V_105 >= 6 )
F_682 ( V_10 -> V_13 ) ;
F_192 ( V_12 ) ;
}
static void F_683 ( struct V_89 * V_29 )
{
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_475 * V_476 ;
F_269 ( & V_10 -> V_432 ) ;
V_476 = V_28 -> V_433 ;
V_28 -> V_433 = NULL ;
F_270 ( & V_10 -> V_432 ) ;
if ( V_476 ) {
F_684 ( & V_476 -> V_476 ) ;
F_210 ( V_476 ) ;
}
F_685 ( V_29 ) ;
F_210 ( V_28 ) ;
}
static void F_686 ( struct V_1084 * V_1085 )
{
struct V_475 * V_476 =
F_687 ( V_1085 , struct V_475 , V_476 ) ;
struct V_9 * V_10 = V_476 -> V_29 -> V_10 ;
enum V_4 V_4 = F_33 ( V_476 -> V_29 ) -> V_4 ;
F_60 ( & V_10 -> V_299 ) ;
F_194 ( V_476 -> V_427 , V_476 -> V_29 -> V_91 -> V_34 ) ;
F_205 ( & V_476 -> V_480 -> V_8 ) ;
F_371 ( V_10 ) ;
if ( V_476 -> V_1086 )
F_688 ( & V_476 -> V_1086 , NULL ) ;
F_62 ( & V_10 -> V_299 ) ;
F_689 ( V_10 , F_213 ( V_4 ) ) ;
F_207 ( V_476 -> V_427 ) ;
F_122 ( F_278 ( & F_33 ( V_476 -> V_29 ) -> V_474 ) == 0 ) ;
F_690 ( & F_33 ( V_476 -> V_29 ) -> V_474 ) ;
F_210 ( V_476 ) ;
}
static void F_691 ( struct V_9 * V_10 ,
struct V_89 * V_29 )
{
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_475 * V_476 ;
unsigned long V_345 ;
if ( V_28 == NULL )
return;
F_692 ( & V_10 -> V_432 , V_345 ) ;
V_476 = V_28 -> V_433 ;
F_302 () ;
if ( V_476 == NULL || F_278 ( & V_476 -> V_429 ) < V_1087 ) {
F_693 ( & V_10 -> V_432 , V_345 ) ;
return;
}
F_301 ( V_28 ) ;
F_693 ( & V_10 -> V_432 , V_345 ) ;
}
void F_694 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_29 = V_12 -> V_97 [ V_4 ] ;
F_691 ( V_10 , V_29 ) ;
}
void F_255 ( struct V_9 * V_10 , int V_164 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_29 = V_12 -> V_1088 [ V_164 ] ;
F_691 ( V_10 , V_29 ) ;
}
static bool F_695 ( T_1 V_1089 , T_1 V_1090 )
{
return ! ( ( V_1089 - V_1090 ) & 0x80000000 ) ;
}
static bool F_696 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_277 ( & V_12 -> V_430 ) ||
V_29 -> V_431 != F_278 ( & V_12 -> V_430 . V_431 ) )
return true ;
if ( F_49 ( V_10 ) -> V_105 < 5 && ! F_20 ( V_10 ) )
return true ;
return ( F_5 ( F_697 ( V_29 -> V_164 ) ) & ~ 0xfff ) ==
V_29 -> V_433 -> V_1091 &&
F_695 ( F_5 ( F_698 ( V_29 -> V_4 ) ) ,
V_29 -> V_433 -> V_1092 ) ;
}
void F_254 ( struct V_9 * V_10 , int V_164 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 =
F_33 ( V_12 -> V_1088 [ V_164 ] ) ;
unsigned long V_345 ;
F_692 ( & V_10 -> V_432 , V_345 ) ;
if ( V_28 -> V_433 && F_696 ( V_28 ) )
F_699 ( & V_28 -> V_433 -> V_429 ) ;
F_693 ( & V_10 -> V_432 , V_345 ) ;
}
static inline void F_700 ( struct V_28 * V_28 )
{
F_701 () ;
F_702 ( & V_28 -> V_433 -> V_429 , V_1093 ) ;
F_701 () ;
}
static int F_703 ( struct V_9 * V_10 ,
struct V_89 * V_29 ,
struct V_280 * V_92 ,
struct V_295 * V_296 ,
struct V_293 * V_1094 ,
T_4 V_345 )
{
struct V_28 * V_28 = F_33 ( V_29 ) ;
T_1 V_1095 ;
int V_298 ;
V_298 = F_704 ( V_1094 , 6 ) ;
if ( V_298 )
return V_298 ;
if ( V_28 -> V_164 )
V_1095 = V_1096 ;
else
V_1095 = V_1097 ;
F_705 ( V_1094 , V_1098 | V_1095 ) ;
F_705 ( V_1094 , V_1099 ) ;
F_705 ( V_1094 , V_1100 |
F_706 ( V_28 -> V_164 ) ) ;
F_705 ( V_1094 , V_92 -> V_290 [ 0 ] ) ;
F_705 ( V_1094 , V_28 -> V_433 -> V_1091 ) ;
F_705 ( V_1094 , 0 ) ;
F_700 ( V_28 ) ;
F_707 ( V_1094 ) ;
return 0 ;
}
static int F_708 ( struct V_9 * V_10 ,
struct V_89 * V_29 ,
struct V_280 * V_92 ,
struct V_295 * V_296 ,
struct V_293 * V_1094 ,
T_4 V_345 )
{
struct V_28 * V_28 = F_33 ( V_29 ) ;
T_1 V_1095 ;
int V_298 ;
V_298 = F_704 ( V_1094 , 6 ) ;
if ( V_298 )
return V_298 ;
if ( V_28 -> V_164 )
V_1095 = V_1096 ;
else
V_1095 = V_1097 ;
F_705 ( V_1094 , V_1098 | V_1095 ) ;
F_705 ( V_1094 , V_1099 ) ;
F_705 ( V_1094 , V_1101 |
F_706 ( V_28 -> V_164 ) ) ;
F_705 ( V_1094 , V_92 -> V_290 [ 0 ] ) ;
F_705 ( V_1094 , V_28 -> V_433 -> V_1091 ) ;
F_705 ( V_1094 , V_1099 ) ;
F_700 ( V_28 ) ;
F_707 ( V_1094 ) ;
return 0 ;
}
static int F_709 ( struct V_9 * V_10 ,
struct V_89 * V_29 ,
struct V_280 * V_92 ,
struct V_295 * V_296 ,
struct V_293 * V_1094 ,
T_4 V_345 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
T_4 V_1102 , V_1103 ;
int V_298 ;
V_298 = F_704 ( V_1094 , 4 ) ;
if ( V_298 )
return V_298 ;
F_705 ( V_1094 , V_1100 |
F_706 ( V_28 -> V_164 ) ) ;
F_705 ( V_1094 , V_92 -> V_290 [ 0 ] ) ;
F_705 ( V_1094 , V_28 -> V_433 -> V_1091 |
V_296 -> V_305 ) ;
V_1102 = 0 ;
V_1103 = F_5 ( F_280 ( V_28 -> V_4 ) ) & 0x0fff0fff ;
F_705 ( V_1094 , V_1102 | V_1103 ) ;
F_700 ( V_28 ) ;
F_707 ( V_1094 ) ;
return 0 ;
}
static int F_710 ( struct V_9 * V_10 ,
struct V_89 * V_29 ,
struct V_280 * V_92 ,
struct V_295 * V_296 ,
struct V_293 * V_1094 ,
T_4 V_345 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
T_4 V_1102 , V_1103 ;
int V_298 ;
V_298 = F_704 ( V_1094 , 4 ) ;
if ( V_298 )
return V_298 ;
F_705 ( V_1094 , V_1100 |
F_706 ( V_28 -> V_164 ) ) ;
F_705 ( V_1094 , V_92 -> V_290 [ 0 ] | V_296 -> V_305 ) ;
F_705 ( V_1094 , V_28 -> V_433 -> V_1091 ) ;
V_1102 = 0 ;
V_1103 = F_5 ( F_280 ( V_28 -> V_4 ) ) & 0x0fff0fff ;
F_705 ( V_1094 , V_1102 | V_1103 ) ;
F_700 ( V_28 ) ;
F_707 ( V_1094 ) ;
return 0 ;
}
static int F_711 ( struct V_9 * V_10 ,
struct V_89 * V_29 ,
struct V_280 * V_92 ,
struct V_295 * V_296 ,
struct V_293 * V_1094 ,
T_4 V_345 )
{
struct V_28 * V_28 = F_33 ( V_29 ) ;
T_4 V_1104 = 0 ;
int V_1105 , V_298 ;
switch ( V_28 -> V_164 ) {
case V_1106 :
V_1104 = V_1107 ;
break;
case V_359 :
V_1104 = V_1108 ;
break;
case V_1109 :
V_1104 = V_1110 ;
break;
default:
F_177 ( 1 , L_182 ) ;
return - V_1111 ;
}
V_1105 = 4 ;
if ( V_1094 -> V_239 == V_1112 ) {
V_1105 += 6 ;
if ( F_712 ( V_10 ) )
V_1105 += 2 ;
}
V_298 = F_713 ( V_1094 ) ;
if ( V_298 )
return V_298 ;
V_298 = F_704 ( V_1094 , V_1105 ) ;
if ( V_298 )
return V_298 ;
if ( V_1094 -> V_239 == V_1112 ) {
F_705 ( V_1094 , F_714 ( 1 ) ) ;
F_705 ( V_1094 , V_1113 ) ;
F_705 ( V_1094 , ~ ( V_1114 |
V_1115 |
V_1116 ) ) ;
if ( F_712 ( V_10 ) )
F_705 ( V_1094 , F_715 ( 1 ) |
V_1117 ) ;
else
F_705 ( V_1094 , F_716 ( 1 ) |
V_1117 ) ;
F_705 ( V_1094 , V_1113 ) ;
F_705 ( V_1094 , V_1094 -> V_1118 . V_1091 + 256 ) ;
if ( F_712 ( V_10 ) ) {
F_705 ( V_1094 , 0 ) ;
F_705 ( V_1094 , V_1099 ) ;
}
}
F_705 ( V_1094 , V_1101 | V_1104 ) ;
F_705 ( V_1094 , ( V_92 -> V_290 [ 0 ] | V_296 -> V_305 ) ) ;
F_705 ( V_1094 , V_28 -> V_433 -> V_1091 ) ;
F_705 ( V_1094 , ( V_1099 ) ) ;
F_700 ( V_28 ) ;
F_707 ( V_1094 ) ;
return 0 ;
}
static bool F_717 ( struct V_293 * V_1094 ,
struct V_295 * V_296 )
{
if ( V_1094 == NULL )
return true ;
if ( F_49 ( V_1094 -> V_10 ) -> V_105 < 5 )
return false ;
if ( V_435 . F_717 < 0 )
return false ;
else if ( V_435 . F_717 > 0 )
return true ;
else if ( V_435 . V_1119 )
return true ;
else
return V_1094 != F_718 ( V_296 -> V_1120 ) ;
}
static void F_719 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_280 * V_92 = V_28 -> V_8 . V_91 -> V_92 ;
const enum V_4 V_4 = V_28 -> V_4 ;
T_1 V_1121 , V_343 ;
V_1121 = F_5 ( F_90 ( V_4 , 0 ) ) ;
V_1121 &= ~ V_945 ;
switch ( V_92 -> V_292 [ 0 ] ) {
case V_273 :
break;
case V_274 :
V_1121 |= V_385 ;
break;
case V_275 :
V_1121 |= V_386 ;
break;
case V_276 :
V_1121 |= V_387 ;
break;
default:
F_178 ( V_92 -> V_292 [ 0 ] ) ;
}
V_343 = V_92 -> V_290 [ 0 ] /
F_230 ( V_10 , V_92 -> V_292 [ 0 ] ,
V_92 -> V_269 ) ;
F_124 ( F_90 ( V_4 , 0 ) , V_1121 ) ;
F_124 ( F_248 ( V_4 , 0 ) , V_343 ) ;
F_124 ( F_241 ( V_4 , 0 ) , V_28 -> V_433 -> V_1091 ) ;
F_125 ( F_241 ( V_4 , 0 ) ) ;
}
static void F_720 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_883 * V_884 =
F_204 ( V_28 -> V_8 . V_91 -> V_92 ) ;
struct V_295 * V_296 = V_884 -> V_296 ;
T_1 V_353 ;
T_1 V_99 ;
V_99 = F_84 ( V_28 -> V_164 ) ;
V_353 = F_5 ( V_99 ) ;
if ( V_296 -> V_305 != V_307 )
V_353 |= V_360 ;
else
V_353 &= ~ V_360 ;
F_124 ( V_99 , V_353 ) ;
F_124 ( F_215 ( V_28 -> V_164 ) ,
V_28 -> V_433 -> V_1091 ) ;
F_125 ( F_215 ( V_28 -> V_164 ) ) ;
}
static void F_721 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
bool V_1122 ;
T_1 V_1123 ;
F_700 ( V_28 ) ;
V_1122 = F_722 ( V_28 , & V_1123 ) ;
if ( F_49 ( V_10 ) -> V_105 >= 9 )
F_719 ( V_28 ) ;
else
F_720 ( V_28 ) ;
if ( V_1122 )
F_723 ( V_28 , V_1123 ) ;
}
static void F_724 ( struct V_1084 * V_476 )
{
struct V_1124 * V_1125 =
F_687 ( V_476 , struct V_1124 , V_476 ) ;
if ( V_1125 -> V_1126 )
F_3 ( F_725 ( V_1125 -> V_1126 ,
V_1125 -> V_29 -> V_431 ,
false , NULL ,
& V_1125 -> V_435 -> V_551 . V_1127 ) ) ;
F_721 ( V_1125 -> V_29 ) ;
F_726 ( V_1125 -> V_1126 ) ;
F_210 ( V_1125 ) ;
}
static int F_727 ( struct V_9 * V_10 ,
struct V_89 * V_29 ,
struct V_280 * V_92 ,
struct V_295 * V_296 ,
struct V_293 * V_1094 ,
T_4 V_345 )
{
struct V_1124 * V_1125 ;
V_1125 = F_728 ( sizeof( * V_1125 ) , V_525 ) ;
if ( V_1125 == NULL )
return - V_527 ;
V_1125 -> V_435 = F_260 ( V_10 ) ;
V_1125 -> V_1126 = F_729 ( V_296 -> V_1120 ) ;
V_1125 -> V_29 = F_33 ( V_29 ) ;
F_730 ( & V_1125 -> V_476 , F_724 ) ;
F_731 ( & V_1125 -> V_476 ) ;
return 0 ;
}
static int F_732 ( struct V_9 * V_10 ,
struct V_89 * V_29 ,
struct V_280 * V_92 ,
struct V_295 * V_296 ,
struct V_293 * V_1094 ,
T_4 V_345 )
{
return - V_1111 ;
}
static bool F_733 ( struct V_9 * V_10 ,
struct V_89 * V_29 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_475 * V_476 = V_28 -> V_433 ;
T_1 V_1128 ;
if ( F_278 ( & V_476 -> V_429 ) >= V_1087 )
return true ;
if ( ! V_476 -> V_1129 )
return false ;
if ( V_476 -> V_1130 == 0 ) {
if ( V_476 -> V_1086 &&
! F_734 ( V_476 -> V_1086 , true ) )
return false ;
V_476 -> V_1130 = F_735 ( V_29 ) ;
}
if ( F_735 ( V_29 ) - V_476 -> V_1130 < 3 )
return false ;
if ( F_49 ( V_10 ) -> V_105 >= 4 )
V_1128 = F_736 ( F_5 ( F_215 ( V_28 -> V_164 ) ) ) ;
else
V_1128 = F_5 ( F_216 ( V_28 -> V_164 ) ) ;
return V_1128 == V_476 -> V_1091 ;
}
void F_737 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_29 = V_12 -> V_97 [ V_4 ] ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_475 * V_476 ;
F_3 ( ! F_738 () ) ;
if ( V_29 == NULL )
return;
F_739 ( & V_10 -> V_432 ) ;
V_476 = V_28 -> V_433 ;
if ( V_476 != NULL && F_733 ( V_10 , V_29 ) ) {
F_177 ( 1 , L_183 ,
V_476 -> V_1131 , F_740 ( V_10 , V_4 ) ) ;
F_301 ( V_28 ) ;
V_476 = NULL ;
}
if ( V_476 != NULL &&
F_740 ( V_10 , V_4 ) - V_476 -> V_1131 > 1 )
F_741 ( V_10 , V_476 -> V_1086 ) ;
F_742 ( & V_10 -> V_432 ) ;
}
static int F_743 ( struct V_89 * V_29 ,
struct V_280 * V_92 ,
struct V_1132 * V_477 ,
T_4 V_1133 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_280 * V_427 = V_29 -> V_91 -> V_92 ;
struct V_295 * V_296 = F_184 ( V_92 ) ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_262 * V_91 = V_29 -> V_91 ;
enum V_4 V_4 = V_28 -> V_4 ;
struct V_475 * V_476 ;
struct V_293 * V_1094 ;
bool V_1125 ;
int V_298 ;
if ( F_3 ( F_184 ( V_427 ) == NULL ) )
return - V_1134 ;
if ( V_92 -> V_269 != V_29 -> V_91 -> V_92 -> V_269 )
return - V_300 ;
if ( F_49 ( V_10 ) -> V_105 > 3 &&
( V_92 -> V_1135 [ 0 ] != V_29 -> V_91 -> V_92 -> V_1135 [ 0 ] ||
V_92 -> V_290 [ 0 ] != V_29 -> V_91 -> V_92 -> V_290 [ 0 ] ) )
return - V_300 ;
if ( F_744 ( & V_12 -> V_430 ) )
goto V_1136;
V_476 = F_482 ( sizeof( * V_476 ) , V_525 ) ;
if ( V_476 == NULL )
return - V_527 ;
V_476 -> V_477 = V_477 ;
V_476 -> V_29 = V_29 ;
V_476 -> V_427 = V_427 ;
F_730 ( & V_476 -> V_476 , F_686 ) ;
V_298 = F_97 ( V_29 ) ;
if ( V_298 )
goto V_1137;
F_269 ( & V_10 -> V_432 ) ;
if ( V_28 -> V_433 ) {
if ( F_733 ( V_10 , V_29 ) ) {
F_145 ( L_184 ) ;
F_301 ( V_28 ) ;
} else {
F_145 ( L_185 ) ;
F_270 ( & V_10 -> V_432 ) ;
F_98 ( V_29 ) ;
F_210 ( V_476 ) ;
return - V_1134 ;
}
}
V_28 -> V_433 = V_476 ;
F_270 ( & V_10 -> V_432 ) ;
if ( F_278 ( & V_28 -> V_474 ) >= 2 )
F_745 ( V_12 -> V_479 ) ;
F_208 ( V_476 -> V_427 ) ;
F_746 ( & V_296 -> V_8 ) ;
V_29 -> V_91 -> V_92 = V_92 ;
F_206 ( V_29 -> V_91 ) ;
V_476 -> V_480 = V_296 ;
V_298 = F_647 ( V_10 ) ;
if ( V_298 )
goto V_526;
F_747 ( & V_28 -> V_474 ) ;
V_28 -> V_431 = F_278 ( & V_12 -> V_430 . V_431 ) ;
if ( F_49 ( V_10 ) -> V_105 >= 5 || F_20 ( V_10 ) )
V_476 -> V_1092 = F_5 ( F_698 ( V_4 ) ) + 1 ;
if ( F_23 ( V_10 ) ) {
V_1094 = & V_12 -> V_1094 [ V_1138 ] ;
if ( V_296 -> V_305 != F_184 ( V_476 -> V_427 ) -> V_305 )
V_1094 = NULL ;
} else if ( F_285 ( V_10 ) || F_227 ( V_10 ) ) {
V_1094 = & V_12 -> V_1094 [ V_1138 ] ;
} else if ( F_49 ( V_10 ) -> V_105 >= 7 ) {
V_1094 = F_718 ( V_296 -> V_1120 ) ;
if ( V_1094 == NULL || V_1094 -> V_239 != V_1112 )
V_1094 = & V_12 -> V_1094 [ V_1138 ] ;
} else {
V_1094 = & V_12 -> V_1094 [ V_1112 ] ;
}
V_1125 = F_717 ( V_1094 , V_296 ) ;
V_298 = F_183 ( V_29 -> V_91 , V_92 ,
V_29 -> V_91 -> V_34 ,
V_1125 ? F_718 ( V_296 -> V_1120 ) : V_1094 ) ;
if ( V_298 )
goto V_1139;
V_476 -> V_1091 = F_231 ( F_242 ( V_91 ) , V_296 )
+ V_28 -> V_362 ;
if ( V_1125 ) {
V_298 = F_727 ( V_10 , V_29 , V_92 , V_296 , V_1094 ,
V_1133 ) ;
if ( V_298 )
goto V_1140;
F_688 ( & V_476 -> V_1086 ,
V_296 -> V_1120 ) ;
} else {
if ( V_296 -> V_1120 ) {
V_298 = F_748 ( V_296 -> V_1120 ) ;
if ( V_298 )
goto V_1140;
}
V_298 = V_12 -> V_264 . V_1141 ( V_10 , V_29 , V_92 , V_296 , V_1094 ,
V_1133 ) ;
if ( V_298 )
goto V_1140;
F_688 ( & V_476 -> V_1086 ,
F_749 ( V_1094 ) ) ;
}
V_476 -> V_1131 = F_735 ( V_29 ) ;
V_476 -> V_1129 = true ;
F_750 ( F_184 ( V_476 -> V_427 ) , V_296 ,
F_213 ( V_4 ) ) ;
F_376 ( V_10 ) ;
F_751 ( V_10 , F_213 ( V_4 ) ) ;
F_62 ( & V_10 -> V_299 ) ;
F_752 ( V_28 -> V_164 , V_296 ) ;
return 0 ;
V_1140:
F_194 ( V_92 , V_29 -> V_91 -> V_34 ) ;
V_1139:
F_690 ( & V_28 -> V_474 ) ;
F_62 ( & V_10 -> V_299 ) ;
V_526:
V_29 -> V_91 -> V_92 = V_427 ;
F_206 ( V_29 -> V_91 ) ;
F_753 ( & V_296 -> V_8 ) ;
F_207 ( V_476 -> V_427 ) ;
F_269 ( & V_10 -> V_432 ) ;
V_28 -> V_433 = NULL ;
F_270 ( & V_10 -> V_432 ) ;
F_98 ( V_29 ) ;
V_1137:
F_210 ( V_476 ) ;
if ( V_298 == - V_1142 ) {
V_1136:
V_298 = F_358 ( V_91 ) ;
if ( V_298 == 0 && V_477 ) {
F_269 ( & V_10 -> V_432 ) ;
F_303 ( V_10 , V_4 , V_477 ) ;
F_270 ( & V_10 -> V_432 ) ;
}
}
return V_298 ;
}
static void F_754 ( struct V_9 * V_10 )
{
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_755 (dev, connector) {
V_3 -> V_1053 =
F_14 ( V_3 -> V_8 . V_6 ) ;
}
F_573 (dev, encoder) {
V_6 -> V_1052 =
F_33 ( V_6 -> V_8 . V_29 ) ;
}
F_135 (dev, crtc) {
V_29 -> V_1051 = V_29 -> V_8 . V_34 -> V_241 ;
}
}
static void F_756 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
F_755 (dev, connector) {
if ( V_3 -> V_8 . V_6 ) {
V_3 -> V_8 . V_34 -> V_40 =
V_3 -> V_8 . V_6 ;
V_3 -> V_8 . V_34 -> V_29 =
V_3 -> V_8 . V_6 -> V_29 ;
} else {
V_3 -> V_8 . V_34 -> V_40 = NULL ;
V_3 -> V_8 . V_34 -> V_29 = NULL ;
}
}
}
static void F_757 ( struct V_33 * V_34 )
{
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_755 (state->dev, connector) {
V_3 -> V_8 . V_6 = V_3 -> V_8 . V_34 -> V_40 ;
if ( V_3 -> V_8 . V_6 )
V_3 -> V_8 . V_6 -> V_29 =
V_3 -> V_8 . V_34 -> V_29 ;
}
F_573 (state->dev, encoder) {
int V_39 = 0 ;
F_755 (state->dev, connector)
if ( V_3 -> V_8 . V_6 == & V_6 -> V_8 )
V_39 ++ ;
if ( V_39 == 0 )
V_6 -> V_8 . V_29 = NULL ;
}
F_135 (state->dev, crtc) {
V_29 -> V_8 . V_120 = V_29 -> V_8 . V_34 -> V_241 ;
V_29 -> V_93 = F_758 ( V_29 -> V_8 . V_34 ) ;
}
}
static void
F_759 ( struct V_2 * V_3 ,
struct V_31 * V_210 )
{
int V_935 = V_210 -> V_706 ;
F_148 ( L_186 ,
V_3 -> V_8 . V_8 . V_239 ,
V_3 -> V_8 . V_134 ) ;
if ( V_3 -> V_8 . V_1143 . V_511 &&
V_3 -> V_8 . V_1143 . V_511 * 3 < V_935 ) {
F_148 ( L_187 ,
V_935 , V_3 -> V_8 . V_1143 . V_511 * 3 ) ;
V_210 -> V_706 = V_3 -> V_8 . V_1143 . V_511 * 3 ;
}
if ( V_3 -> V_8 . V_1143 . V_511 == 0 && V_935 > 24 ) {
F_148 ( L_188 ,
V_935 ) ;
V_210 -> V_706 = 24 ;
}
}
static int
F_760 ( struct V_28 * V_29 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_33 * V_34 ;
struct V_35 * V_3 ;
struct V_36 * V_37 ;
int V_935 , V_38 ;
if ( ( F_20 ( V_10 ) || F_23 ( V_10 ) ) )
V_935 = 10 * 3 ;
else if ( F_49 ( V_10 ) -> V_105 >= 5 )
V_935 = 12 * 3 ;
else
V_935 = 8 * 3 ;
V_210 -> V_706 = V_935 ;
V_34 = V_210 -> V_8 . V_34 ;
F_13 (state, connector, connector_state, i) {
if ( V_37 -> V_29 != & V_29 -> V_8 )
continue;
F_759 ( F_663 ( V_3 ) ,
V_210 ) ;
}
return V_935 ;
}
static void F_761 ( const struct V_434 * V_419 )
{
F_148 ( L_189
L_190 ,
V_419 -> V_95 ,
V_419 -> V_437 , V_419 -> V_845 ,
V_419 -> V_848 , V_419 -> V_844 ,
V_419 -> V_438 , V_419 -> V_850 ,
V_419 -> V_851 , V_419 -> V_840 , V_419 -> type , V_419 -> V_345 ) ;
}
static void F_762 ( struct V_28 * V_29 ,
struct V_31 * V_210 ,
const char * V_1144 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_262 * V_164 ;
struct V_367 * V_367 ;
struct V_401 * V_34 ;
struct V_280 * V_92 ;
F_148 ( L_191 , V_29 -> V_8 . V_8 . V_239 ,
V_1144 , V_210 , F_75 ( V_29 -> V_4 ) ) ;
F_148 ( L_192 , F_763 ( V_210 -> V_98 ) ) ;
F_148 ( L_193 ,
V_210 -> V_706 , V_210 -> V_858 ) ;
F_148 ( L_194 ,
V_210 -> V_259 ,
V_210 -> V_454 ,
V_210 -> V_568 . V_755 , V_210 -> V_568 . V_756 ,
V_210 -> V_568 . V_757 , V_210 -> V_568 . V_758 ,
V_210 -> V_568 . V_754 ) ;
F_148 ( L_195 ,
V_210 -> V_510 ,
V_210 -> V_773 . V_755 , V_210 -> V_773 . V_756 ,
V_210 -> V_773 . V_757 , V_210 -> V_773 . V_758 ,
V_210 -> V_773 . V_754 ) ;
F_148 ( L_196 ,
V_210 -> V_510 ,
V_210 -> V_774 . V_755 ,
V_210 -> V_774 . V_756 ,
V_210 -> V_774 . V_757 ,
V_210 -> V_774 . V_758 ,
V_210 -> V_774 . V_754 ) ;
F_148 ( L_197 ,
V_210 -> V_1145 ,
V_210 -> V_1146 ) ;
F_148 ( L_198 ) ;
F_764 ( & V_210 -> V_8 . V_419 ) ;
F_148 ( L_199 ) ;
F_764 ( & V_210 -> V_8 . V_94 ) ;
F_761 ( & V_210 -> V_8 . V_94 ) ;
F_148 ( L_200 , V_210 -> V_798 ) ;
F_148 ( L_201 ,
V_210 -> V_358 , V_210 -> V_357 ) ;
F_148 ( L_202 ,
V_29 -> V_370 ,
V_210 -> V_369 . V_535 ,
V_210 -> V_369 . V_410 ) ;
F_148 ( L_203 ,
V_210 -> V_577 . V_578 ,
V_210 -> V_577 . V_582 ,
V_210 -> V_577 . V_879 ) ;
F_148 ( L_204 ,
V_210 -> V_439 . V_547 ,
V_210 -> V_439 . V_340 ,
V_210 -> V_439 . V_120 ? L_205 : L_206 ) ;
F_148 ( L_207 , V_210 -> V_550 ) ;
F_148 ( L_208 , V_210 -> V_260 ) ;
if ( F_19 ( V_10 ) ) {
F_148 ( L_209
L_210
L_211 ,
V_210 -> V_982 ,
V_210 -> V_211 . V_1147 ,
V_210 -> V_211 . V_1148 ,
V_210 -> V_211 . V_1149 ,
V_210 -> V_211 . V_1150 ,
V_210 -> V_211 . V_1151 ,
V_210 -> V_211 . V_1152 ,
V_210 -> V_211 . V_1153 ,
V_210 -> V_211 . V_1154 ) ;
} else if ( F_633 ( V_10 ) ) {
F_148 ( L_212
L_213 ,
V_210 -> V_982 ,
V_210 -> V_211 . V_990 ,
V_210 -> V_211 . V_1155 ,
V_210 -> V_211 . V_1156 ) ;
} else if ( F_66 ( V_10 ) ) {
F_148 ( L_214 ,
V_210 -> V_982 ,
V_210 -> V_211 . V_1157 ) ;
} else {
F_148 ( L_215
L_216 ,
V_210 -> V_211 . V_66 ,
V_210 -> V_211 . V_213 ,
V_210 -> V_211 . V_689 ,
V_210 -> V_211 . V_690 ) ;
}
F_148 ( L_217 ) ;
F_476 (plane, &dev->mode_config.plane_list, head) {
V_367 = F_242 ( V_164 ) ;
if ( V_367 -> V_4 != V_29 -> V_4 )
continue;
V_34 = F_172 ( V_164 -> V_34 ) ;
V_92 = V_34 -> V_8 . V_92 ;
if ( ! V_92 ) {
F_148 ( L_218
L_219 ,
V_164 -> type == V_1158 ? L_220 : L_221 ,
V_164 -> V_8 . V_239 , V_367 -> V_4 ,
( V_29 -> V_8 . V_91 == V_164 ) ? 0 : V_367 -> V_164 + 1 ,
F_351 ( V_164 ) , V_34 -> V_410 ) ;
continue;
}
F_148 ( L_222 ,
V_164 -> type == V_1158 ? L_220 : L_221 ,
V_164 -> V_8 . V_239 , V_367 -> V_4 ,
V_29 -> V_8 . V_91 == V_164 ? 0 : V_367 -> V_164 + 1 ,
F_351 ( V_164 ) ) ;
F_148 ( L_223 ,
V_92 -> V_8 . V_239 , V_92 -> V_344 , V_92 -> V_277 , V_92 -> V_269 ) ;
F_148 ( L_224 ,
V_34 -> V_410 ,
V_34 -> V_414 . V_415 >> 16 , V_34 -> V_414 . y1 >> 16 ,
F_243 ( & V_34 -> V_414 ) >> 16 ,
F_244 ( & V_34 -> V_414 ) >> 16 ,
V_34 -> V_416 . V_415 , V_34 -> V_416 . y1 ,
F_243 ( & V_34 -> V_416 ) , F_244 ( & V_34 -> V_416 ) ) ;
}
}
static bool F_765 ( const struct V_1 * V_1089 ,
const struct V_1 * V_1090 )
{
return V_1089 == V_1090 || ( V_1089 -> V_1159 & ( 1 << V_1090 -> type ) &&
V_1090 -> V_1159 & ( 1 << V_1089 -> type ) ) ;
}
static bool F_766 ( struct V_33 * V_34 ,
struct V_28 * V_29 ,
struct V_1 * V_6 )
{
struct V_1 * V_1160 ;
struct V_35 * V_3 ;
struct V_36 * V_37 ;
int V_38 ;
F_13 (state, connector, connector_state, i) {
if ( V_37 -> V_29 != & V_29 -> V_8 )
continue;
V_1160 =
F_14 ( V_37 -> V_40 ) ;
if ( ! F_765 ( V_6 , V_1160 ) )
return false ;
}
return true ;
}
static bool F_767 ( struct V_33 * V_34 ,
struct V_28 * V_29 )
{
struct V_1 * V_6 ;
struct V_35 * V_3 ;
struct V_36 * V_37 ;
int V_38 ;
F_13 (state, connector, connector_state, i) {
if ( V_37 -> V_29 != & V_29 -> V_8 )
continue;
V_6 = F_14 ( V_37 -> V_40 ) ;
if ( ! F_766 ( V_34 , V_29 , V_6 ) )
return false ;
}
return true ;
}
static bool F_768 ( struct V_33 * V_34 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_1 * V_6 ;
struct V_35 * V_3 ;
struct V_36 * V_37 ;
unsigned int V_1161 = 0 ;
int V_38 ;
F_13 (state, connector, connector_state, i) {
if ( ! V_37 -> V_40 )
continue;
V_6 = F_14 ( V_37 -> V_40 ) ;
F_3 ( ! V_37 -> V_29 ) ;
switch ( V_6 -> type ) {
unsigned int V_230 ;
case V_590 :
if ( F_3 ( ! F_66 ( V_10 ) ) )
break;
case V_591 :
case V_50 :
case V_440 :
V_230 = 1 << F_344 ( & V_6 -> V_8 ) -> V_108 ;
if ( V_1161 & V_230 )
return false ;
V_1161 |= V_230 ;
default:
break;
}
}
return true ;
}
static void
F_769 ( struct V_31 * V_32 )
{
struct V_674 V_1162 ;
struct V_368 V_369 ;
struct V_131 V_211 ;
enum V_520 V_128 ;
T_4 V_982 ;
V_1162 = V_32 -> V_8 ;
V_369 = V_32 -> V_369 ;
V_128 = V_32 -> V_128 ;
V_211 = V_32 -> V_211 ;
V_982 = V_32 -> V_982 ;
memset ( V_32 , 0 , sizeof *V_32 ) ;
V_32 -> V_8 = V_1162 ;
V_32 -> V_369 = V_369 ;
V_32 -> V_128 = V_128 ;
V_32 -> V_211 = V_211 ;
V_32 -> V_982 = V_982 ;
}
static int
F_770 ( struct V_89 * V_29 ,
struct V_33 * V_34 ,
struct V_31 * V_210 )
{
struct V_1 * V_6 ;
struct V_35 * V_3 ;
struct V_36 * V_37 ;
int V_1163 , V_298 = - V_300 ;
int V_38 ;
bool V_459 = true ;
if ( ! F_767 ( V_34 , F_33 ( V_29 ) ) ) {
F_148 ( L_225 ) ;
return - V_300 ;
}
if ( ! F_768 ( V_34 ) ) {
F_148 ( L_226 ) ;
return - V_300 ;
}
F_769 ( V_210 ) ;
V_210 -> V_98 =
(enum V_96 ) F_33 ( V_29 ) -> V_4 ;
if ( ! ( V_210 -> V_8 . V_94 . V_345 &
( V_515 | V_1164 ) ) )
V_210 -> V_8 . V_94 . V_345 |= V_1164 ;
if ( ! ( V_210 -> V_8 . V_94 . V_345 &
( V_517 | V_1165 ) ) )
V_210 -> V_8 . V_94 . V_345 |= V_1165 ;
V_1163 = F_760 ( F_33 ( V_29 ) ,
V_210 ) ;
if ( V_1163 < 0 )
goto V_1056;
F_658 ( & V_210 -> V_8 . V_419 ,
& V_210 -> V_358 ,
& V_210 -> V_357 ) ;
V_1166:
V_210 -> V_798 = 0 ;
V_210 -> V_573 = 1 ;
F_771 ( & V_210 -> V_8 . V_94 ,
V_1167 ) ;
F_13 (state, connector, connector_state, i) {
if ( V_37 -> V_29 != V_29 )
continue;
V_6 = F_14 ( V_37 -> V_40 ) ;
if ( ! ( V_6 -> V_1168 ( V_6 , V_210 ) ) ) {
F_148 ( L_227 ) ;
goto V_1056;
}
}
if ( ! V_210 -> V_798 )
V_210 -> V_798 = V_210 -> V_8 . V_94 . V_95
* V_210 -> V_573 ;
V_298 = F_496 ( F_33 ( V_29 ) , V_210 ) ;
if ( V_298 < 0 ) {
F_148 ( L_228 ) ;
goto V_1056;
}
if ( V_298 == V_708 ) {
if ( F_52 ( ! V_459 , L_229 ) ) {
V_298 = - V_300 ;
goto V_1056;
}
F_148 ( L_230 ) ;
V_459 = false ;
goto V_1166;
}
V_210 -> V_858 = V_210 -> V_706 == 6 * 3 ;
F_148 ( L_231 ,
V_1163 , V_210 -> V_706 , V_210 -> V_858 ) ;
return 0 ;
V_1056:
return V_298 ;
}
static bool F_772 ( struct V_89 * V_29 )
{
struct V_696 * V_6 ;
struct V_9 * V_10 = V_29 -> V_10 ;
F_476 (encoder, &dev->mode_config.encoder_list, head)
if ( V_6 -> V_29 == V_29 )
return true ;
return false ;
}
static bool
F_773 ( struct V_674 * V_34 )
{
return V_34 -> V_675 || V_34 -> V_1169 ;
}
static void
F_774 ( struct V_33 * V_34 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 ;
struct V_89 * V_29 ;
struct V_674 * V_32 ;
struct V_35 * V_3 ;
int V_38 ;
F_347 ( V_12 ) ;
F_573 (dev, intel_encoder) {
if ( ! V_1 -> V_8 . V_29 )
continue;
F_455 (state, crtc, crtc_state, i) {
if ( V_29 != V_1 -> V_8 . V_29 )
continue;
if ( V_32 -> V_241 && F_773 ( V_32 ) )
V_1 -> V_692 = false ;
break;
}
}
F_775 ( V_34 -> V_10 , V_34 ) ;
F_757 ( V_34 ) ;
F_211 (dev, crtc) {
F_3 ( V_29 -> V_34 -> V_241 != F_772 ( V_29 ) ) ;
}
F_476 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_3 -> V_6 || ! V_3 -> V_6 -> V_29 )
continue;
F_455 (state, crtc, crtc_state, i) {
if ( V_29 != V_3 -> V_6 -> V_29 )
continue;
if ( V_29 -> V_34 -> V_241 && F_773 ( V_29 -> V_34 ) ) {
struct V_1170 * V_1171 =
V_10 -> V_1044 . V_1171 ;
V_3 -> V_694 = V_697 ;
F_776 ( & V_3 -> V_8 ,
V_1171 ,
V_697 ) ;
V_1 = F_14 ( V_3 -> V_6 ) ;
V_1 -> V_692 = true ;
}
break;
}
}
}
static bool F_777 ( int V_1172 , int V_1173 )
{
int V_1174 ;
if ( V_1172 == V_1173 )
return true ;
if ( ! V_1172 || ! V_1173 )
return false ;
V_1174 = abs ( V_1172 - V_1173 ) ;
if ( ( ( ( ( V_1174 + V_1172 + V_1173 ) * 100 ) ) / ( V_1172 + V_1173 ) ) < 105 )
return true ;
return false ;
}
static bool
F_778 ( struct V_9 * V_10 ,
struct V_31 * V_1175 ,
struct V_31 * V_210 )
{
#define F_779 ( V_134 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_780 ( V_134 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_781 ( V_134 , T_7 ) \
if ((current_config->name != pipe_config->name) && \
(current_config->alt_name != pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i or %i, found %i)\n", \
current_config->name, \
current_config->alt_name, \
pipe_config->name); \
return false; \
}
#define F_782 ( V_134 , V_595 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
DRM_ERROR("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
return false; \
}
#define F_783 ( V_134 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_784 ( T_8 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_780 ( V_98 ) ;
F_780 ( V_259 ) ;
F_780 ( V_454 ) ;
F_780 ( V_568 . V_755 ) ;
F_780 ( V_568 . V_756 ) ;
F_780 ( V_568 . V_757 ) ;
F_780 ( V_568 . V_758 ) ;
F_780 ( V_568 . V_754 ) ;
F_780 ( V_510 ) ;
if ( F_49 ( V_10 ) -> V_105 < 8 ) {
F_780 ( V_773 . V_755 ) ;
F_780 ( V_773 . V_756 ) ;
F_780 ( V_773 . V_757 ) ;
F_780 ( V_773 . V_758 ) ;
F_780 ( V_773 . V_754 ) ;
if ( V_1175 -> V_771 ) {
F_780 ( V_774 . V_755 ) ;
F_780 ( V_774 . V_756 ) ;
F_780 ( V_774 . V_757 ) ;
F_780 ( V_774 . V_758 ) ;
F_780 ( V_774 . V_754 ) ;
}
} else {
F_781 ( V_773 . V_755 , V_774 . V_755 ) ;
F_781 ( V_773 . V_756 , V_774 . V_756 ) ;
F_781 ( V_773 . V_757 , V_774 . V_757 ) ;
F_781 ( V_773 . V_758 , V_774 . V_758 ) ;
F_781 ( V_773 . V_754 , V_774 . V_754 ) ;
}
F_780 ( V_8 . V_94 . V_437 ) ;
F_780 ( V_8 . V_94 . V_844 ) ;
F_780 ( V_8 . V_94 . V_846 ) ;
F_780 ( V_8 . V_94 . V_847 ) ;
F_780 ( V_8 . V_94 . V_845 ) ;
F_780 ( V_8 . V_94 . V_848 ) ;
F_780 ( V_8 . V_94 . V_438 ) ;
F_780 ( V_8 . V_94 . V_840 ) ;
F_780 ( V_8 . V_94 . V_849 ) ;
F_780 ( V_8 . V_94 . V_841 ) ;
F_780 ( V_8 . V_94 . V_850 ) ;
F_780 ( V_8 . V_94 . V_851 ) ;
F_780 ( V_573 ) ;
F_780 ( V_1176 ) ;
if ( ( F_49 ( V_10 ) -> V_105 < 8 && ! F_227 ( V_10 ) ) ||
F_23 ( V_10 ) )
F_780 ( V_868 ) ;
F_780 ( V_1146 ) ;
F_780 ( V_1145 ) ;
F_782 ( V_8 . V_94 . V_345 ,
V_843 ) ;
if ( ! F_784 ( V_1177 ) ) {
F_782 ( V_8 . V_94 . V_345 ,
V_515 ) ;
F_782 ( V_8 . V_94 . V_345 ,
V_1164 ) ;
F_782 ( V_8 . V_94 . V_345 ,
V_517 ) ;
F_782 ( V_8 . V_94 . V_345 ,
V_1165 ) ;
}
F_780 ( V_358 ) ;
F_780 ( V_357 ) ;
if ( ! F_784 ( V_1178 ) ) {
F_780 ( V_577 . V_578 ) ;
if ( F_49 ( V_10 ) -> V_105 < 4 )
F_780 ( V_577 . V_582 ) ;
F_780 ( V_577 . V_879 ) ;
}
F_780 ( V_439 . V_120 ) ;
if ( V_1175 -> V_439 . V_120 ) {
F_780 ( V_439 . V_547 ) ;
F_780 ( V_439 . V_340 ) ;
}
F_780 ( V_369 . V_410 ) ;
if ( F_227 ( V_10 ) )
F_780 ( V_550 ) ;
F_780 ( V_260 ) ;
F_779 ( V_982 ) ;
F_780 ( V_128 ) ;
F_779 ( V_211 . V_66 ) ;
F_779 ( V_211 . V_213 ) ;
F_779 ( V_211 . V_689 ) ;
F_779 ( V_211 . V_690 ) ;
F_779 ( V_211 . V_1157 ) ;
F_779 ( V_211 . V_990 ) ;
F_779 ( V_211 . V_1155 ) ;
F_779 ( V_211 . V_1156 ) ;
if ( F_20 ( V_10 ) || F_49 ( V_10 ) -> V_105 >= 5 )
F_780 ( V_706 ) ;
F_783 ( V_8 . V_94 . V_95 ) ;
F_783 ( V_798 ) ;
#undef F_779
#undef F_780
#undef F_781
#undef F_782
#undef F_783
#undef F_784
return true ;
}
static void F_785 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1179 V_1180 , * V_1181 ;
struct V_28 * V_28 ;
int V_164 ;
if ( F_49 ( V_10 ) -> V_105 < 9 )
return;
F_786 ( V_12 , & V_1180 ) ;
V_1181 = & V_12 -> V_1182 . V_1183 . V_1184 ;
F_135 (dev, intel_crtc) {
struct V_1185 * V_1186 , * V_1187 ;
const enum V_4 V_4 = V_28 -> V_4 ;
if ( ! V_28 -> V_90 )
continue;
F_787 (dev_priv, pipe, plane) {
V_1186 = & V_1180 . V_164 [ V_4 ] [ V_164 ] ;
V_1187 = & V_1181 -> V_164 [ V_4 ] [ V_164 ] ;
if ( F_788 ( V_1186 , V_1187 ) )
continue;
F_127 ( L_232
L_233 ,
F_75 ( V_4 ) , V_164 + 1 ,
V_1187 -> V_1032 , V_1187 -> V_1033 ,
V_1186 -> V_1032 , V_1186 -> V_1033 ) ;
}
V_1186 = & V_1180 . V_1007 [ V_4 ] ;
V_1187 = & V_1181 -> V_1007 [ V_4 ] ;
if ( F_788 ( V_1186 , V_1187 ) )
continue;
F_127 ( L_234
L_233 ,
F_75 ( V_4 ) ,
V_1187 -> V_1032 , V_1187 -> V_1033 ,
V_1186 -> V_1032 , V_1186 -> V_1033 ) ;
}
}
static void
F_789 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
F_755 (dev, connector) {
F_480 ( V_3 ) ;
F_58 ( & V_3 -> V_1053 -> V_8 != V_3 -> V_8 . V_6 ,
L_235 ) ;
}
}
static void
F_790 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_573 (dev, encoder) {
bool V_120 = false ;
bool V_90 = false ;
enum V_4 V_4 , V_1188 ;
F_148 ( L_236 ,
V_6 -> V_8 . V_8 . V_239 ,
V_6 -> V_8 . V_134 ) ;
F_58 ( & V_6 -> V_1052 -> V_8 != V_6 -> V_8 . V_29 ,
L_237 ) ;
F_58 ( V_6 -> V_692 && ! V_6 -> V_8 . V_29 ,
L_238 ) ;
F_755 (dev, connector) {
if ( V_3 -> V_8 . V_6 != & V_6 -> V_8 )
continue;
V_120 = true ;
if ( V_3 -> V_8 . V_694 != V_695 )
V_90 = true ;
}
if ( ! V_120 && V_6 -> V_8 . V_1189 == V_1190 )
continue;
F_58 ( ! ! V_6 -> V_8 . V_29 != V_120 ,
L_239
L_240 ,
! ! V_6 -> V_8 . V_29 , V_120 ) ;
F_58 ( V_90 && ! V_6 -> V_8 . V_29 ,
L_241 ) ;
F_58 ( V_6 -> V_692 != V_90 ,
L_242
L_240 , V_90 , V_6 -> V_692 ) ;
V_90 = V_6 -> V_133 ( V_6 , & V_4 ) ;
F_58 ( V_90 != V_6 -> V_692 ,
L_243
L_240 ,
V_6 -> V_692 , V_90 ) ;
if ( ! V_6 -> V_8 . V_29 )
continue;
V_1188 = F_33 ( V_6 -> V_8 . V_29 ) -> V_4 ;
F_58 ( V_90 && V_4 != V_1188 ,
L_244
L_240 ,
V_1188 , V_4 ) ;
}
}
static void
F_791 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_31 V_210 ;
F_135 (dev, crtc) {
bool V_120 = false ;
bool V_90 = false ;
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
F_148 ( L_245 ,
V_29 -> V_8 . V_8 . V_239 ) ;
F_58 ( V_29 -> V_90 && ! V_29 -> V_8 . V_34 -> V_241 ,
L_246 ) ;
F_573 (dev, encoder) {
if ( V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
V_120 = true ;
if ( V_6 -> V_692 )
V_90 = true ;
}
F_58 ( V_90 != V_29 -> V_90 ,
L_247
L_240 , V_90 , V_29 -> V_90 ) ;
F_58 ( V_120 != V_29 -> V_8 . V_34 -> V_241 ,
L_248
L_240 , V_120 ,
V_29 -> V_8 . V_34 -> V_241 ) ;
V_90 = V_12 -> V_264 . V_1191 ( V_29 ,
& V_210 ) ;
if ( ( V_29 -> V_4 == V_142 && V_12 -> V_160 & V_161 ) ||
( V_29 -> V_4 == V_151 && V_12 -> V_160 & V_162 ) )
V_90 = V_29 -> V_90 ;
F_573 (dev, encoder) {
enum V_4 V_4 ;
if ( V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
if ( V_6 -> V_133 ( V_6 , & V_4 ) )
V_6 -> V_1192 ( V_6 , & V_210 ) ;
}
F_58 ( V_29 -> V_90 != V_90 ,
L_249
L_240 , V_29 -> V_90 , V_90 ) ;
if ( V_90 &&
! F_778 ( V_10 , V_29 -> V_93 , & V_210 ) ) {
F_58 ( 1 , L_250 ) ;
F_762 ( V_29 , & V_210 ,
L_251 ) ;
F_762 ( V_29 , V_29 -> V_93 ,
L_252 ) ;
}
}
}
static void
F_792 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 ;
struct V_131 V_211 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_12 -> V_523 ; V_38 ++ ) {
struct V_127 * V_130 = & V_12 -> V_129 [ V_38 ] ;
int V_1193 = 0 , V_1194 = 0 ;
bool V_90 ;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
F_148 ( L_253 , V_130 -> V_134 ) ;
V_90 = V_130 -> V_133 ( V_12 , V_130 , & V_211 ) ;
F_58 ( V_130 -> V_90 > F_793 ( V_130 -> V_93 . V_236 ) ,
L_254 ,
V_130 -> V_90 , F_793 ( V_130 -> V_93 . V_236 ) ) ;
F_58 ( V_130 -> V_90 && ! V_130 -> V_237 ,
L_255 ) ;
F_58 ( V_130 -> V_237 && ! V_130 -> V_90 ,
L_256 ) ;
F_58 ( V_130 -> V_237 != V_90 ,
L_257 ,
V_130 -> V_237 , V_90 ) ;
F_135 (dev, crtc) {
if ( V_29 -> V_8 . V_34 -> V_241 && F_63 ( V_29 ) == V_130 )
V_1193 ++ ;
if ( V_29 -> V_90 && F_63 ( V_29 ) == V_130 )
V_1194 ++ ;
}
F_58 ( V_130 -> V_90 != V_1194 ,
L_258 ,
V_130 -> V_90 , V_1194 ) ;
F_58 ( F_793 ( V_130 -> V_93 . V_236 ) != V_1193 ,
L_259 ,
F_793 ( V_130 -> V_93 . V_236 ) , V_1193 ) ;
F_58 ( V_130 -> V_237 && memcmp ( & V_130 -> V_93 . V_132 , & V_211 ,
sizeof( V_211 ) ) ,
L_260 ) ;
}
}
void
F_485 ( struct V_9 * V_10 )
{
F_785 ( V_10 ) ;
F_789 ( V_10 ) ;
F_790 ( V_10 ) ;
F_791 ( V_10 ) ;
F_792 ( V_10 ) ;
}
void F_794 ( const struct V_31 * V_210 ,
int V_1195 )
{
F_52 ( ! F_777 ( V_210 -> V_8 . V_94 . V_95 , V_1195 ) ,
L_261 ,
V_210 -> V_8 . V_94 . V_95 , V_1195 ) ;
}
static void F_795 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
if ( F_24 ( V_10 ) ) {
const struct V_434 * V_419 = & V_29 -> V_93 -> V_8 . V_94 ;
int V_854 ;
V_854 = V_419 -> V_840 ;
if ( V_419 -> V_345 & V_843 )
V_854 /= 2 ;
V_29 -> V_1196 = V_854 - 1 ;
} else if ( F_66 ( V_10 ) &&
F_10 ( V_29 , V_50 ) ) {
V_29 -> V_1196 = 2 ;
} else
V_29 -> V_1196 = 1 ;
}
static struct V_31 *
F_796 ( struct V_89 * V_29 ,
struct V_33 * V_34 )
{
struct V_31 * V_210 ;
int V_298 = 0 ;
V_298 = F_797 ( V_34 , V_29 ) ;
if ( V_298 )
return F_645 ( V_298 ) ;
V_298 = F_798 ( V_34 -> V_10 , V_34 ) ;
if ( V_298 )
return F_645 ( V_298 ) ;
V_210 = F_450 ( V_34 , F_33 ( V_29 ) ) ;
if ( F_451 ( V_210 ) )
return V_210 ;
if ( ! V_210 -> V_8 . V_241 )
return V_210 ;
V_298 = F_770 ( V_29 , V_34 , V_210 ) ;
if ( V_298 )
return F_645 ( V_298 ) ;
if ( V_210 -> V_1145 !=
F_33 ( V_29 ) -> V_93 -> V_1145 )
V_210 -> V_8 . V_675 = true ;
F_762 ( F_33 ( V_29 ) , V_210 , L_262 ) ;
V_298 = F_799 ( V_34 -> V_10 , V_34 ) ;
if ( V_298 )
return F_645 ( V_298 ) ;
return V_210 ;
}
static int F_800 ( struct V_33 * V_34 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_11 * V_12 = F_260 ( V_10 ) ;
unsigned V_524 = 0 ;
struct V_28 * V_28 ;
struct V_31 * V_31 ;
struct V_89 * V_29 ;
struct V_674 * V_32 ;
int V_298 = 0 ;
int V_38 ;
if ( ! V_12 -> V_264 . V_1197 )
return 0 ;
F_455 (state, crtc, crtc_state, i) {
V_28 = F_33 ( V_29 ) ;
V_31 = F_758 ( V_32 ) ;
if ( F_773 ( V_32 ) ) {
V_524 |= 1 << V_28 -> V_4 ;
V_31 -> V_128 = V_519 ;
}
}
V_298 = F_345 ( V_12 , V_524 ) ;
if ( V_298 )
goto V_1198;
F_455 (state, crtc, crtc_state, i) {
if ( ! F_773 ( V_32 ) || ! V_32 -> V_241 )
continue;
V_28 = F_33 ( V_29 ) ;
V_31 = F_758 ( V_32 ) ;
V_298 = V_12 -> V_264 . V_1197 ( V_28 ,
V_31 ) ;
if ( V_298 ) {
F_348 ( V_12 ) ;
goto V_1198;
}
}
V_1198:
return V_298 ;
}
static int F_801 ( struct V_33 * V_34 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
int V_298 ;
if ( F_23 ( V_10 ) || F_19 ( V_10 ) ) {
V_298 = F_453 ( V_34 ) ;
if ( V_298 )
return V_298 ;
}
V_298 = F_800 ( V_34 ) ;
if ( V_298 )
return V_298 ;
return 0 ;
}
static int F_802 ( struct V_89 * V_1199 ,
struct V_31 * V_210 )
{
struct V_9 * V_10 = V_1199 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_33 * V_34 = V_210 -> V_8 . V_34 ;
struct V_89 * V_29 ;
struct V_674 * V_32 ;
int V_298 = 0 ;
int V_38 ;
V_298 = F_801 ( V_34 ) ;
if ( V_298 < 0 )
return V_298 ;
V_298 = F_803 ( V_10 , V_34 ) ;
if ( V_298 )
return V_298 ;
F_455 (state, crtc, crtc_state, i) {
if ( ! F_773 ( V_32 ) )
continue;
if ( ! V_32 -> V_241 ) {
if ( V_29 -> V_34 -> V_241 )
F_474 ( V_29 ) ;
} else if ( V_29 -> V_34 -> V_241 ) {
F_261 ( V_29 ) ;
V_12 -> V_264 . V_423 ( V_29 ) ;
}
}
if ( V_210 -> V_8 . V_241 && F_773 ( & V_210 -> V_8 ) ) {
V_1199 -> V_419 = V_210 -> V_8 . V_419 ;
F_804 ( V_1199 ,
& V_210 -> V_8 . V_94 ) ;
}
F_774 ( V_34 ) ;
F_417 ( V_34 ) ;
F_455 (state, crtc, crtc_state, i) {
if ( ! F_773 ( V_29 -> V_34 ) || ! V_29 -> V_34 -> V_241 ) {
F_805 ( V_32 ) ;
continue;
}
F_795 ( F_33 ( V_29 ) ) ;
V_12 -> V_264 . V_424 ( V_29 ) ;
F_805 ( V_32 ) ;
}
F_806 ( V_10 , V_34 ) ;
F_668 ( V_34 ) ;
return 0 ;
}
static int F_807 ( struct V_89 * V_29 ,
struct V_31 * V_210 ,
bool V_1200 )
{
int V_298 ;
V_298 = F_802 ( V_29 , V_210 ) ;
if ( V_298 == 0 && V_1200 ) {
F_754 ( V_29 -> V_10 ) ;
F_485 ( V_29 -> V_10 ) ;
}
return V_298 ;
}
static int F_667 ( struct V_89 * V_29 ,
struct V_33 * V_34 ,
bool V_1200 )
{
struct V_31 * V_210 ;
int V_298 = 0 ;
V_210 = F_796 ( V_29 , V_34 ) ;
if ( F_451 ( V_210 ) ) {
V_298 = F_452 ( V_210 ) ;
goto V_1201;
}
V_298 = F_807 ( V_29 , V_210 , V_1200 ) ;
if ( V_298 )
goto V_1201;
V_1201:
return V_298 ;
}
void F_808 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_33 * V_34 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
struct V_36 * V_37 ;
struct V_31 * V_32 ;
int V_298 ;
V_34 = F_664 ( V_10 ) ;
if ( ! V_34 ) {
F_148 ( L_263 ,
V_29 -> V_8 . V_239 ) ;
return;
}
V_34 -> V_1055 = V_10 -> V_1044 . V_1055 ;
F_573 (dev, encoder) {
if ( & V_6 -> V_1052 -> V_8 != V_29 )
continue;
F_755 (dev, connector) {
if ( V_3 -> V_1053 != V_6 )
continue;
V_37 = F_665 ( V_34 , & V_3 -> V_8 ) ;
if ( F_451 ( V_37 ) ) {
F_148 ( L_264 ,
V_3 -> V_8 . V_8 . V_239 ,
V_3 -> V_8 . V_134 ,
F_452 ( V_37 ) ) ;
continue;
}
V_37 -> V_29 = V_29 ;
V_37 -> V_40 = & V_6 -> V_8 ;
}
}
V_32 = F_450 ( V_34 , F_33 ( V_29 ) ) ;
if ( F_451 ( V_32 ) ) {
F_148 ( L_265 ,
V_29 -> V_8 . V_239 , F_452 ( V_32 ) ) ;
F_668 ( V_34 ) ;
return;
}
V_32 -> V_8 . V_90 = V_32 -> V_8 . V_241 =
F_33 ( V_29 ) -> V_1051 ;
F_666 ( & V_32 -> V_8 . V_419 , & V_29 -> V_419 ) ;
F_656 ( V_34 , V_29 , & V_29 -> V_419 ,
V_29 -> V_91 -> V_92 , V_29 -> V_266 , V_29 -> V_267 ) ;
V_298 = F_667 ( V_29 , V_34 , false ) ;
if ( V_298 )
F_668 ( V_34 ) ;
}
static bool F_809 ( struct V_2 * V_3 ,
struct V_1202 * V_1203 )
{
int V_1204 ;
for ( V_1204 = 0 ; V_1204 < V_1203 -> V_39 ; V_1204 ++ )
if ( V_1203 -> V_1205 [ V_1204 ] == & V_3 -> V_8 )
return true ;
return false ;
}
static int
F_810 ( struct V_9 * V_10 ,
struct V_1202 * V_1203 ,
struct V_33 * V_34 )
{
struct V_2 * V_3 ;
struct V_35 * V_35 ;
struct V_36 * V_37 ;
struct V_89 * V_29 ;
struct V_674 * V_32 ;
int V_38 , V_298 ;
F_3 ( ! V_1203 -> V_92 && ( V_1203 -> V_39 != 0 ) ) ;
F_3 ( V_1203 -> V_92 && ( V_1203 -> V_39 == 0 ) ) ;
F_755 (dev, connector) {
bool V_1206 = F_809 ( V_3 , V_1203 ) ;
if ( ! V_1206 && V_3 -> V_8 . V_34 -> V_29 != V_1203 -> V_29 )
continue;
V_37 =
F_665 ( V_34 , & V_3 -> V_8 ) ;
if ( F_451 ( V_37 ) )
return F_452 ( V_37 ) ;
if ( V_1206 ) {
int V_4 = F_33 ( V_1203 -> V_29 ) -> V_4 ;
V_37 -> V_40 =
& F_1 ( V_3 , V_4 ) -> V_8 ;
}
if ( V_3 -> V_8 . V_34 -> V_29 != V_1203 -> V_29 )
continue;
if ( ! V_1203 -> V_92 || ! V_1206 ) {
V_37 -> V_40 = NULL ;
F_148 ( L_266 ,
V_3 -> V_8 . V_8 . V_239 ,
V_3 -> V_8 . V_134 ) ;
}
}
F_13 (state, drm_connector, connector_state, i) {
V_3 = F_663 ( V_35 ) ;
if ( ! V_37 -> V_40 ) {
V_298 = F_811 ( V_37 ,
NULL ) ;
if ( V_298 )
return V_298 ;
continue;
}
if ( F_809 ( V_3 , V_1203 ) ) {
struct V_89 * V_29 = V_3 -> V_8 . V_34 -> V_29 ;
if ( V_29 ) {
V_32 =
F_454 ( V_34 , V_29 ) ;
if ( F_451 ( V_32 ) )
return F_452 ( V_32 ) ;
}
V_298 = F_811 ( V_37 ,
V_1203 -> V_29 ) ;
if ( V_298 )
return V_298 ;
}
if ( ! F_812 ( V_37 -> V_40 ,
V_37 -> V_29 ) ) {
return - V_300 ;
}
F_148 ( L_267 ,
V_3 -> V_8 . V_8 . V_239 ,
V_3 -> V_8 . V_134 ,
V_37 -> V_29 -> V_8 . V_239 ) ;
if ( V_37 -> V_40 != & V_3 -> V_6 -> V_8 )
V_3 -> V_6 =
F_14 ( V_37 -> V_40 ) ;
}
F_455 (state, crtc, crtc_state, i) {
bool V_1207 ;
V_298 = F_797 ( V_34 , V_29 ) ;
if ( V_298 )
return V_298 ;
V_1207 = ! ! F_813 ( V_34 , V_29 ) ;
if ( V_1207 != V_32 -> V_241 )
V_32 -> V_241 =
V_32 -> V_90 = V_1207 ;
}
V_298 = F_656 ( V_34 , V_1203 -> V_29 , V_1203 -> V_419 ,
V_1203 -> V_92 , V_1203 -> V_266 , V_1203 -> V_267 ) ;
if ( V_298 )
return V_298 ;
V_32 = F_454 ( V_34 , V_1203 -> V_29 ) ;
if ( F_451 ( V_32 ) )
return F_452 ( V_32 ) ;
if ( V_1203 -> V_419 )
F_666 ( & V_32 -> V_419 , V_1203 -> V_419 ) ;
if ( V_1203 -> V_39 )
V_32 -> V_90 = true ;
return 0 ;
}
static int F_814 ( struct V_1202 * V_1203 )
{
struct V_9 * V_10 ;
struct V_33 * V_34 = NULL ;
struct V_31 * V_210 ;
int V_298 ;
F_122 ( ! V_1203 ) ;
F_122 ( ! V_1203 -> V_29 ) ;
F_122 ( ! V_1203 -> V_29 -> V_1208 ) ;
F_122 ( ! V_1203 -> V_419 && V_1203 -> V_92 ) ;
F_122 ( V_1203 -> V_92 && V_1203 -> V_39 == 0 ) ;
if ( V_1203 -> V_92 ) {
F_148 ( L_268 ,
V_1203 -> V_29 -> V_8 . V_239 , V_1203 -> V_92 -> V_8 . V_239 ,
( int ) V_1203 -> V_39 , V_1203 -> V_266 , V_1203 -> V_267 ) ;
} else {
F_148 ( L_269 , V_1203 -> V_29 -> V_8 . V_239 ) ;
}
V_10 = V_1203 -> V_29 -> V_10 ;
V_34 = F_664 ( V_10 ) ;
if ( ! V_34 )
return - V_527 ;
V_34 -> V_1055 = V_10 -> V_1044 . V_1055 ;
V_298 = F_810 ( V_10 , V_1203 , V_34 ) ;
if ( V_298 )
goto V_1201;
V_210 = F_796 ( V_1203 -> V_29 , V_34 ) ;
if ( F_451 ( V_210 ) ) {
V_298 = F_452 ( V_210 ) ;
goto V_1201;
}
F_279 ( F_33 ( V_1203 -> V_29 ) ) ;
V_298 = F_807 ( V_1203 -> V_29 , V_210 , true ) ;
if ( V_298 ) {
F_148 ( L_270 ,
V_1203 -> V_29 -> V_8 . V_239 , V_298 ) ;
}
V_1201:
if ( V_298 )
F_668 ( V_34 ) ;
return V_298 ;
}
static bool F_815 ( struct V_11 * V_12 ,
struct V_127 * V_130 ,
struct V_131 * V_132 )
{
T_4 V_121 ;
if ( ! F_81 ( V_12 , V_240 ) )
return false ;
V_121 = F_5 ( F_816 ( V_130 -> V_239 ) ) ;
V_132 -> V_66 = V_121 ;
V_132 -> V_689 = F_5 ( F_817 ( V_130 -> V_239 ) ) ;
V_132 -> V_690 = F_5 ( F_818 ( V_130 -> V_239 ) ) ;
return V_121 & V_123 ;
}
static void F_819 ( struct V_11 * V_12 ,
struct V_127 * V_130 )
{
F_124 ( F_817 ( V_130 -> V_239 ) , V_130 -> V_93 . V_132 . V_689 ) ;
F_124 ( F_818 ( V_130 -> V_239 ) , V_130 -> V_93 . V_132 . V_690 ) ;
}
static void F_820 ( struct V_11 * V_12 ,
struct V_127 * V_130 )
{
F_99 ( V_12 ) ;
F_124 ( F_816 ( V_130 -> V_239 ) , V_130 -> V_93 . V_132 . V_66 ) ;
F_125 ( F_816 ( V_130 -> V_239 ) ) ;
F_126 ( 150 ) ;
F_124 ( F_816 ( V_130 -> V_239 ) , V_130 -> V_93 . V_132 . V_66 ) ;
F_125 ( F_816 ( V_130 -> V_239 ) ) ;
F_126 ( 200 ) ;
}
static void F_821 ( struct V_11 * V_12 ,
struct V_127 * V_130 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_28 * V_29 ;
F_135 (dev, crtc) {
if ( F_63 ( V_29 ) == V_130 )
F_101 ( V_12 , V_29 -> V_4 ) ;
}
F_124 ( F_816 ( V_130 -> V_239 ) , 0 ) ;
F_125 ( F_816 ( V_130 -> V_239 ) ) ;
F_126 ( 200 ) ;
}
static void F_822 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_38 ;
V_12 -> V_523 = 2 ;
for ( V_38 = 0 ; V_38 < V_12 -> V_523 ; V_38 ++ ) {
V_12 -> V_129 [ V_38 ] . V_239 = V_38 ;
V_12 -> V_129 [ V_38 ] . V_134 = V_1209 [ V_38 ] ;
V_12 -> V_129 [ V_38 ] . V_238 = F_819 ;
V_12 -> V_129 [ V_38 ] . V_241 = F_820 ;
V_12 -> V_129 [ V_38 ] . V_242 = F_821 ;
V_12 -> V_129 [ V_38 ] . V_133 =
F_815 ;
}
}
static void F_823 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_66 ( V_10 ) )
F_824 ( V_10 ) ;
else if ( F_54 ( V_10 ) || F_100 ( V_10 ) )
F_822 ( V_10 ) ;
else
V_12 -> V_523 = 0 ;
F_122 ( V_12 -> V_523 > V_1210 ) ;
}
bool F_825 ( struct V_262 * V_164 ,
struct V_281 * V_34 )
{
if ( ! V_164 -> V_34 -> V_92 || ! V_34 -> V_92 ||
V_164 -> V_34 -> V_92 -> V_292 [ 0 ] != V_34 -> V_92 -> V_292 [ 0 ] ||
V_164 -> V_34 -> V_287 != V_34 -> V_287 )
return true ;
return false ;
}
int
F_826 ( struct V_262 * V_164 ,
struct V_280 * V_92 ,
const struct V_281 * V_1211 )
{
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_367 * V_367 = F_242 ( V_164 ) ;
enum V_4 V_4 = V_367 -> V_4 ;
struct V_295 * V_296 = F_184 ( V_92 ) ;
struct V_295 * V_1212 = F_184 ( V_164 -> V_92 ) ;
unsigned V_351 = 0 ;
int V_298 = 0 ;
if ( ! V_296 )
return 0 ;
switch ( V_164 -> type ) {
case V_1213 :
V_351 = F_213 ( V_4 ) ;
break;
case V_1158 :
V_351 = F_827 ( V_4 ) ;
break;
case V_1214 :
V_351 = F_828 ( V_4 ) ;
break;
}
F_60 ( & V_10 -> V_299 ) ;
if ( V_164 -> type == V_1158 &&
F_49 ( V_10 ) -> V_1215 ) {
int V_1216 = F_137 ( V_10 ) ? 16 * 1024 : 256 ;
V_298 = F_829 ( V_296 , V_1216 ) ;
if ( V_298 )
F_148 ( L_271 ) ;
} else {
V_298 = F_183 ( V_164 , V_92 , V_1211 , NULL ) ;
}
if ( V_298 == 0 )
F_750 ( V_1212 , V_296 , V_351 ) ;
F_62 ( & V_10 -> V_299 ) ;
return V_298 ;
}
void
F_830 ( struct V_262 * V_164 ,
struct V_280 * V_92 ,
const struct V_281 * V_683 )
{
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_295 * V_296 = F_184 ( V_92 ) ;
if ( F_3 ( ! V_296 ) )
return;
if ( V_164 -> type != V_1158 ||
! F_49 ( V_10 ) -> V_1215 ) {
F_60 ( & V_10 -> V_299 ) ;
F_194 ( V_92 , V_683 ) ;
F_62 ( & V_10 -> V_299 ) ;
}
}
int
F_831 ( struct V_28 * V_28 , struct V_31 * V_32 )
{
int V_1217 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_95 , V_656 ;
if ( ! V_28 || ! V_32 )
return V_1218 ;
V_10 = V_28 -> V_8 . V_10 ;
V_12 = V_10 -> V_13 ;
V_95 = V_32 -> V_8 . V_94 . V_95 ;
V_656 = V_12 -> V_264 . V_654 ( V_10 ) ;
if ( ! V_95 || ! V_656 )
return V_1218 ;
V_1217 = V_68 ( ( 1 << 16 ) * 3 - 1 , ( 1 << 8 ) * ( ( V_656 << 8 ) / V_95 ) ) ;
return V_1217 ;
}
static int
F_832 ( struct V_262 * V_164 ,
struct V_401 * V_34 )
{
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_29 = V_34 -> V_8 . V_29 ;
struct V_28 * V_28 ;
struct V_31 * V_32 ;
struct V_280 * V_92 = V_34 -> V_8 . V_92 ;
struct V_1219 * V_1220 = & V_34 -> V_416 ;
struct V_1219 * V_414 = & V_34 -> V_414 ;
const struct V_1219 * V_1221 = & V_34 -> V_1221 ;
bool V_1222 = false ;
int V_1217 = V_1218 ;
int V_1223 = V_1218 ;
int V_298 ;
V_29 = V_29 ? V_29 : V_164 -> V_29 ;
V_28 = F_33 ( V_29 ) ;
V_32 = V_34 -> V_8 . V_34 ?
F_450 ( V_34 -> V_8 . V_34 , V_28 ) : NULL ;
if ( F_49 ( V_10 ) -> V_105 >= 9 ) {
if ( F_242 ( V_164 ) -> V_544 . V_345 == V_545 ) {
V_1223 = 1 ;
V_1217 = F_831 ( V_28 , V_32 ) ;
}
V_1222 = true ;
}
V_298 = F_833 ( V_164 , V_29 , V_92 ,
V_414 , V_1220 , V_1221 ,
V_1223 ,
V_1217 ,
V_1222 , true ,
& V_34 -> V_263 ) ;
if ( V_298 )
return V_298 ;
if ( V_32 ? V_32 -> V_8 . V_90 : V_28 -> V_90 ) {
struct V_401 * V_683 =
F_172 ( V_164 -> V_34 ) ;
V_28 -> V_1224 . V_1225 = true ;
if ( V_34 -> V_263 &&
F_49 ( V_10 ) -> V_105 <= 4 && ! F_20 ( V_10 ) &&
V_12 -> V_564 . V_29 == V_28 &&
V_34 -> V_8 . V_287 != F_222 ( V_388 ) ) {
V_28 -> V_1224 . V_421 = true ;
}
if ( V_34 -> V_263 && ! V_683 -> V_263 ) {
if ( F_228 ( V_10 ) )
V_28 -> V_1224 . V_1226 = true ;
if ( V_32 )
V_28 -> V_1224 . V_1227 = true ;
}
if ( ! V_34 -> V_263 || ! V_92 )
V_28 -> V_1224 . V_1228 = true ;
if ( ! V_34 -> V_263 && V_683 -> V_263 &&
V_32 && ! F_773 ( & V_32 -> V_8 ) )
V_28 -> V_1224 . V_1229 = true ;
V_28 -> V_1224 . V_1230 |=
F_213 ( V_28 -> V_4 ) ;
V_28 -> V_1224 . V_1231 = true ;
if ( F_825 ( V_164 , & V_34 -> V_8 ) )
V_28 -> V_1224 . V_1232 = true ;
}
if ( F_49 ( V_10 ) -> V_105 >= 9 ) {
V_298 = F_350 ( V_28 , V_32 ,
F_242 ( V_164 ) , V_34 , 0 ) ;
if ( V_298 )
return V_298 ;
}
return 0 ;
}
static void
F_834 ( struct V_262 * V_164 ,
struct V_401 * V_34 )
{
struct V_89 * V_29 = V_34 -> V_8 . V_29 ;
struct V_280 * V_92 = V_34 -> V_8 . V_92 ;
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 ;
struct V_1219 * V_414 = & V_34 -> V_414 ;
V_29 = V_29 ? V_29 : V_164 -> V_29 ;
V_28 = F_33 ( V_29 ) ;
V_164 -> V_92 = V_92 ;
V_29 -> V_266 = V_414 -> V_415 >> 16 ;
V_29 -> V_267 = V_414 -> y1 >> 16 ;
if ( V_28 -> V_90 ) {
if ( V_34 -> V_263 )
F_279 ( V_28 ) ;
V_12 -> V_264 . V_265 ( V_29 , V_164 -> V_92 ,
V_29 -> V_266 , V_29 -> V_267 ) ;
}
}
static void
F_835 ( struct V_262 * V_164 ,
struct V_89 * V_29 ,
bool V_1233 )
{
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_264 . V_265 ( V_29 , NULL , 0 , 0 ) ;
}
static void F_836 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_367 * V_367 ;
struct V_262 * V_22 ;
unsigned V_1230 = 0 ;
F_476 (p, &dev->mode_config.plane_list, head) {
V_367 = F_242 ( V_22 ) ;
if ( V_28 -> V_1224 . V_1234 &
( 1 << F_351 ( V_22 ) ) ) {
switch ( V_22 -> type ) {
case V_1213 :
V_1230 = F_213 ( V_367 -> V_4 ) ;
break;
case V_1158 :
V_1230 = F_827 ( V_367 -> V_4 ) ;
break;
case V_1214 :
V_1230 = F_828 ( V_367 -> V_4 ) ;
break;
}
F_60 ( & V_10 -> V_299 ) ;
F_750 ( F_184 ( V_22 -> V_92 ) , NULL , V_1230 ) ;
F_62 ( & V_10 -> V_299 ) ;
}
}
if ( V_28 -> V_1224 . V_1225 )
F_307 ( V_29 ) ;
if ( V_28 -> V_1224 . V_421 )
F_376 ( V_10 ) ;
if ( V_28 -> V_1224 . V_1228 )
F_363 ( V_28 ) ;
if ( V_28 -> V_1224 . V_1229 )
F_374 ( V_29 ) ;
if ( V_28 -> V_1224 . V_1232 )
F_387 ( V_29 ) ;
F_188 ( V_12 ) ;
if ( V_28 -> V_90 )
V_28 -> V_1224 . V_1235 =
F_722 ( V_28 ,
& V_28 -> V_1224 . V_1123 ) ;
}
static void F_837 ( struct V_89 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_33 ( V_29 ) ;
struct V_262 * V_22 ;
if ( V_28 -> V_1224 . V_1235 )
F_723 ( V_28 ,
V_28 -> V_1224 . V_1123 ) ;
F_192 ( V_12 ) ;
if ( V_28 -> V_1224 . V_1226 )
F_300 ( V_10 , V_28 -> V_4 ) ;
F_378 ( V_10 , V_28 -> V_1224 . V_1230 ) ;
if ( V_28 -> V_1224 . V_1231 ) {
F_60 ( & V_10 -> V_299 ) ;
F_371 ( V_10 ) ;
F_62 ( & V_10 -> V_299 ) ;
}
if ( V_28 -> V_1224 . V_1227 )
F_370 ( V_29 ) ;
F_357 (p, &dev->mode_config.plane_list)
if ( V_28 -> V_1224 . V_1236 & F_351 ( V_22 ) )
F_838 ( V_22 , V_29 , 0 , 0 , 0 ,
false , false ) ;
memset ( & V_28 -> V_1224 , 0 , sizeof( V_28 -> V_1224 ) ) ;
}
void F_839 ( struct V_262 * V_164 )
{
struct V_367 * V_367 = F_242 ( V_164 ) ;
F_840 ( V_164 ) ;
F_210 ( V_367 ) ;
}
static struct V_262 * F_841 ( struct V_9 * V_10 ,
int V_4 )
{
struct V_367 * V_91 ;
struct V_401 * V_34 ;
const T_4 * V_1237 ;
int V_1238 ;
V_91 = F_482 ( sizeof( * V_91 ) , V_525 ) ;
if ( V_91 == NULL )
return NULL ;
V_34 = F_842 ( & V_91 -> V_8 ) ;
if ( ! V_34 ) {
F_210 ( V_91 ) ;
return NULL ;
}
V_91 -> V_8 . V_34 = & V_34 -> V_8 ;
V_91 -> V_1239 = false ;
V_91 -> V_1240 = 1 ;
if ( F_49 ( V_10 ) -> V_105 >= 9 ) {
V_91 -> V_1239 = true ;
V_34 -> V_410 = - 1 ;
}
V_91 -> V_4 = V_4 ;
V_91 -> V_164 = V_4 ;
V_91 -> V_1241 = F_832 ;
V_91 -> V_1242 = F_834 ;
V_91 -> V_566 = F_835 ;
V_91 -> V_544 . V_345 = V_545 ;
if ( F_843 ( V_10 ) && F_49 ( V_10 ) -> V_105 < 4 )
V_91 -> V_164 = ! V_4 ;
if ( F_49 ( V_10 ) -> V_105 >= 9 ) {
V_1237 = V_1243 ;
V_1238 = F_295 ( V_1243 ) ;
} else if ( F_49 ( V_10 ) -> V_105 >= 4 ) {
V_1237 = V_1244 ;
V_1238 = F_295 ( V_1244 ) ;
} else {
V_1237 = V_1245 ;
V_1238 = F_295 ( V_1245 ) ;
}
F_844 ( V_10 , & V_91 -> V_8 , 0 ,
& V_1246 ,
V_1237 , V_1238 ,
V_1213 ) ;
if ( F_49 ( V_10 ) -> V_105 >= 4 )
F_845 ( V_10 , V_91 ) ;
F_846 ( & V_91 -> V_8 , & V_1247 ) ;
return & V_91 -> V_8 ;
}
void F_845 ( struct V_9 * V_10 , struct V_367 * V_164 )
{
if ( ! V_10 -> V_1044 . V_1248 ) {
unsigned long V_345 = F_222 ( V_388 ) |
F_222 ( V_363 ) ;
if ( F_49 ( V_10 ) -> V_105 >= 9 )
V_345 |= F_222 ( V_389 ) | F_222 ( V_392 ) ;
V_10 -> V_1044 . V_1248 =
F_847 ( V_10 , V_345 ) ;
}
if ( V_10 -> V_1044 . V_1248 )
F_848 ( & V_164 -> V_8 . V_8 ,
V_10 -> V_1044 . V_1248 ,
V_164 -> V_8 . V_34 -> V_287 ) ;
}
static int
F_849 ( struct V_262 * V_164 ,
struct V_401 * V_34 )
{
struct V_89 * V_29 = V_34 -> V_8 . V_29 ;
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_280 * V_92 = V_34 -> V_8 . V_92 ;
struct V_1219 * V_1220 = & V_34 -> V_416 ;
struct V_1219 * V_414 = & V_34 -> V_414 ;
const struct V_1219 * V_1221 = & V_34 -> V_1221 ;
struct V_295 * V_296 = F_184 ( V_92 ) ;
struct V_28 * V_28 ;
unsigned V_343 ;
int V_298 ;
V_29 = V_29 ? V_29 : V_164 -> V_29 ;
V_28 = F_33 ( V_29 ) ;
V_298 = F_833 ( V_164 , V_29 , V_92 ,
V_414 , V_1220 , V_1221 ,
V_1218 ,
V_1218 ,
true , true , & V_34 -> V_263 ) ;
if ( V_298 )
return V_298 ;
if ( ! V_296 )
goto V_1249;
if ( ! F_642 ( V_10 , V_34 -> V_8 . V_1008 , V_34 -> V_8 . V_1009 ) ) {
F_850 ( L_272 ,
V_34 -> V_8 . V_1008 , V_34 -> V_8 . V_1009 ) ;
return - V_300 ;
}
V_343 = F_637 ( V_34 -> V_8 . V_1008 ) * 4 ;
if ( V_296 -> V_8 . V_340 < V_343 * V_34 -> V_8 . V_1009 ) {
F_148 ( L_273 ) ;
return - V_527 ;
}
if ( V_92 -> V_292 [ 0 ] != V_273 ) {
F_148 ( L_274 ) ;
V_298 = - V_300 ;
}
V_1249:
if ( V_28 -> V_90 ) {
if ( V_164 -> V_34 -> V_1008 != V_34 -> V_8 . V_1008 )
V_28 -> V_1224 . V_1232 = true ;
V_28 -> V_1224 . V_1230 |=
F_827 ( V_28 -> V_4 ) ;
}
return V_298 ;
}
static void
F_851 ( struct V_262 * V_164 ,
struct V_89 * V_29 ,
bool V_1233 )
{
struct V_28 * V_28 = F_33 ( V_29 ) ;
if ( ! V_1233 ) {
V_164 -> V_92 = NULL ;
V_28 -> V_1250 = NULL ;
V_28 -> V_1025 = 0 ;
}
F_377 ( V_29 , false ) ;
}
static void
F_852 ( struct V_262 * V_164 ,
struct V_401 * V_34 )
{
struct V_89 * V_29 = V_34 -> V_8 . V_29 ;
struct V_9 * V_10 = V_164 -> V_10 ;
struct V_28 * V_28 ;
struct V_295 * V_296 = F_184 ( V_34 -> V_8 . V_92 ) ;
T_4 V_1128 ;
V_29 = V_29 ? V_29 : V_164 -> V_29 ;
V_28 = F_33 ( V_29 ) ;
V_164 -> V_92 = V_34 -> V_8 . V_92 ;
V_29 -> V_1023 = V_34 -> V_8 . V_1036 ;
V_29 -> V_1024 = V_34 -> V_8 . V_1037 ;
if ( V_28 -> V_1250 == V_296 )
goto V_1251;
if ( ! V_296 )
V_1128 = 0 ;
else if ( ! F_49 ( V_10 ) -> V_1215 )
V_1128 = F_212 ( V_296 ) ;
else
V_1128 = V_296 -> V_1252 -> V_1253 ;
V_28 -> V_1025 = V_1128 ;
V_28 -> V_1250 = V_296 ;
V_1251:
if ( V_28 -> V_90 )
F_377 ( V_29 , V_34 -> V_263 ) ;
}
static struct V_262 * F_853 ( struct V_9 * V_10 ,
int V_4 )
{
struct V_367 * V_1007 ;
struct V_401 * V_34 ;
V_1007 = F_482 ( sizeof( * V_1007 ) , V_525 ) ;
if ( V_1007 == NULL )
return NULL ;
V_34 = F_842 ( & V_1007 -> V_8 ) ;
if ( ! V_34 ) {
F_210 ( V_1007 ) ;
return NULL ;
}
V_1007 -> V_8 . V_34 = & V_34 -> V_8 ;
V_1007 -> V_1239 = false ;
V_1007 -> V_1240 = 1 ;
V_1007 -> V_4 = V_4 ;
V_1007 -> V_164 = V_4 ;
V_1007 -> V_1241 = F_849 ;
V_1007 -> V_1242 = F_852 ;
V_1007 -> V_566 = F_851 ;
F_844 ( V_10 , & V_1007 -> V_8 , 0 ,
& V_1246 ,
V_1254 ,
F_295 ( V_1254 ) ,
V_1158 ) ;
if ( F_49 ( V_10 ) -> V_105 >= 4 ) {
if ( ! V_10 -> V_1044 . V_1248 )
V_10 -> V_1044 . V_1248 =
F_847 ( V_10 ,
F_222 ( V_388 ) |
F_222 ( V_363 ) ) ;
if ( V_10 -> V_1044 . V_1248 )
F_848 ( & V_1007 -> V_8 . V_8 ,
V_10 -> V_1044 . V_1248 ,
V_34 -> V_8 . V_287 ) ;
}
if ( F_49 ( V_10 ) -> V_105 >= 9 )
V_34 -> V_410 = - 1 ;
F_846 ( & V_1007 -> V_8 , & V_1247 ) ;
return & V_1007 -> V_8 ;
}
static void F_635 ( struct V_9 * V_10 , struct V_28 * V_28 ,
struct V_31 * V_32 )
{
int V_38 ;
struct V_1255 * V_1255 ;
struct V_368 * V_369 = & V_32 -> V_369 ;
for ( V_38 = 0 ; V_38 < V_28 -> V_370 ; V_38 ++ ) {
V_1255 = & V_369 -> V_371 [ V_38 ] ;
V_1255 -> V_372 = 0 ;
V_1255 -> V_239 = V_38 ;
V_1255 -> V_419 = V_1256 ;
}
V_369 -> V_410 = - 1 ;
}
static void F_854 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 ;
struct V_31 * V_32 = NULL ;
struct V_262 * V_91 = NULL ;
struct V_262 * V_1007 = NULL ;
int V_38 , V_298 ;
V_28 = F_482 ( sizeof( * V_28 ) , V_525 ) ;
if ( V_28 == NULL )
return;
V_32 = F_482 ( sizeof( * V_32 ) , V_525 ) ;
if ( ! V_32 )
goto V_1056;
V_28 -> V_93 = V_32 ;
V_28 -> V_8 . V_34 = & V_32 -> V_8 ;
V_32 -> V_8 . V_29 = & V_28 -> V_8 ;
if ( F_49 ( V_10 ) -> V_105 >= 9 ) {
if ( V_4 == V_504 )
V_28 -> V_370 = 1 ;
else
V_28 -> V_370 = V_1257 ;
F_635 ( V_10 , V_28 , V_32 ) ;
}
V_91 = F_841 ( V_10 , V_4 ) ;
if ( ! V_91 )
goto V_1056;
V_1007 = F_853 ( V_10 , V_4 ) ;
if ( ! V_1007 )
goto V_1056;
V_298 = F_855 ( V_10 , & V_28 -> V_8 , V_91 ,
V_1007 , & V_1258 ) ;
if ( V_298 )
goto V_1056;
F_856 ( & V_28 -> V_8 , 256 ) ;
for ( V_38 = 0 ; V_38 < 256 ; V_38 ++ ) {
V_28 -> V_560 [ V_38 ] = V_38 ;
V_28 -> V_561 [ V_38 ] = V_38 ;
V_28 -> V_562 [ V_38 ] = V_38 ;
}
V_28 -> V_4 = V_4 ;
V_28 -> V_164 = V_4 ;
if ( F_843 ( V_10 ) && F_49 ( V_10 ) -> V_105 < 4 ) {
F_148 ( L_275 ) ;
V_28 -> V_164 = ! V_4 ;
}
V_28 -> V_1013 = ~ 0 ;
V_28 -> V_1012 = ~ 0 ;
V_28 -> V_1014 = ~ 0 ;
F_122 ( V_4 >= F_295 ( V_12 -> V_1088 ) ||
V_12 -> V_1088 [ V_28 -> V_164 ] != NULL ) ;
V_12 -> V_1088 [ V_28 -> V_164 ] = & V_28 -> V_8 ;
V_12 -> V_97 [ V_28 -> V_4 ] = & V_28 -> V_8 ;
F_857 ( & V_28 -> V_8 , & V_1259 ) ;
F_3 ( F_858 ( & V_28 -> V_8 ) != V_28 -> V_4 ) ;
return;
V_1056:
if ( V_91 )
F_840 ( V_91 ) ;
if ( V_1007 )
F_840 ( V_1007 ) ;
F_210 ( V_32 ) ;
F_210 ( V_28 ) ;
}
enum V_4 F_859 ( struct V_2 * V_3 )
{
struct V_696 * V_6 = V_3 -> V_8 . V_6 ;
struct V_9 * V_10 = V_3 -> V_8 . V_10 ;
F_3 ( ! F_860 ( & V_10 -> V_1044 . V_1045 ) ) ;
if ( ! V_6 || F_3 ( ! V_6 -> V_29 ) )
return V_1260 ;
return F_33 ( V_6 -> V_29 ) -> V_4 ;
}
int F_861 ( struct V_9 * V_10 , void * V_1261 ,
struct V_1262 * V_1263 )
{
struct V_1264 * V_1265 = V_1261 ;
struct V_89 * V_1266 ;
struct V_28 * V_29 ;
V_1266 = F_862 ( V_10 , V_1265 -> V_1267 ) ;
if ( ! V_1266 ) {
F_127 ( L_276 ) ;
return - V_1268 ;
}
V_29 = F_33 ( V_1266 ) ;
V_1265 -> V_4 = V_29 -> V_4 ;
return 0 ;
}
static int F_863 ( struct V_1 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_8 . V_10 ;
struct V_1 * V_1160 ;
int V_1269 = 0 ;
int V_1270 = 0 ;
F_573 (dev, source_encoder) {
if ( F_765 ( V_6 , V_1160 ) )
V_1269 |= ( 1 << V_1270 ) ;
V_1270 ++ ;
}
return V_1269 ;
}
static bool F_864 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_123 ( V_10 ) )
return false ;
if ( ( F_5 ( V_1271 ) & V_1272 ) == 0 )
return false ;
if ( F_7 ( V_10 ) && ( F_5 ( V_720 ) & V_1273 ) )
return false ;
return true ;
}
static bool F_865 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_49 ( V_10 ) -> V_105 >= 9 )
return false ;
if ( F_501 ( V_10 ) || F_866 ( V_10 ) )
return false ;
if ( F_22 ( V_10 ) )
return false ;
if ( F_23 ( V_10 ) && ! V_12 -> V_760 . V_1274 )
return false ;
return true ;
}
static void F_867 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
bool V_1275 = false ;
F_868 ( V_10 ) ;
if ( F_865 ( V_10 ) )
F_869 ( V_10 ) ;
if ( F_19 ( V_10 ) ) {
F_870 ( V_10 , V_584 ) ;
F_870 ( V_10 , V_110 ) ;
F_870 ( V_10 , V_112 ) ;
} else if ( F_66 ( V_10 ) ) {
int V_79 ;
V_79 = F_5 ( V_1276 ) & V_1277 ;
if ( V_79 ||
( F_633 ( V_10 ) && F_871 ( V_10 ) < V_1278 ) )
F_870 ( V_10 , V_584 ) ;
V_79 = F_5 ( V_1279 ) ;
if ( V_79 & V_1280 )
F_870 ( V_10 , V_110 ) ;
if ( V_79 & V_1281 )
F_870 ( V_10 , V_112 ) ;
if ( V_79 & V_1282 )
F_870 ( V_10 , V_114 ) ;
} else if ( F_4 ( V_10 ) ) {
int V_79 ;
V_1275 = F_872 ( V_10 , V_114 ) ;
if ( F_864 ( V_10 ) )
F_873 ( V_10 , V_1271 , V_584 ) ;
if ( F_5 ( V_203 ) & V_1283 ) {
V_79 = F_874 ( V_10 , V_1284 , true ) ;
if ( ! V_79 )
F_875 ( V_10 , V_203 , V_110 ) ;
if ( ! V_79 && ( F_5 ( V_196 ) & V_1272 ) )
F_873 ( V_10 , V_196 , V_110 ) ;
}
if ( F_5 ( V_204 ) & V_1283 )
F_875 ( V_10 , V_204 , V_112 ) ;
if ( ! V_1275 && F_5 ( V_205 ) & V_1283 )
F_875 ( V_10 , V_205 , V_114 ) ;
if ( F_5 ( V_198 ) & V_1272 )
F_873 ( V_10 , V_198 , V_112 ) ;
if ( F_5 ( V_200 ) & V_1272 )
F_873 ( V_10 , V_200 , V_114 ) ;
} else if ( F_23 ( V_10 ) ) {
if ( F_5 ( V_1285 + V_1286 ) & V_1283 &&
! F_872 ( V_10 , V_110 ) )
F_875 ( V_10 , V_1285 + V_1286 ,
V_110 ) ;
if ( F_5 ( V_1285 + V_1287 ) & V_1272 ||
F_872 ( V_10 , V_110 ) )
F_873 ( V_10 , V_1285 + V_1287 , V_110 ) ;
if ( F_5 ( V_1285 + V_1288 ) & V_1283 &&
! F_872 ( V_10 , V_112 ) )
F_875 ( V_10 , V_1285 + V_1288 ,
V_112 ) ;
if ( F_5 ( V_1285 + V_1289 ) & V_1272 ||
F_872 ( V_10 , V_112 ) )
F_873 ( V_10 , V_1285 + V_1289 , V_112 ) ;
if ( F_22 ( V_10 ) ) {
if ( F_5 ( V_1285 + V_1290 ) & V_1283 )
F_875 ( V_10 , V_1285 + V_1290 ,
V_114 ) ;
if ( F_5 ( V_1285 + V_1291 ) & V_1272 )
F_873 ( V_10 , V_1285 + V_1291 , V_114 ) ;
}
F_876 ( V_10 ) ;
} else if ( F_877 ( V_10 ) ) {
bool V_79 = false ;
if ( F_5 ( V_1292 ) & V_1283 ) {
F_148 ( L_277 ) ;
V_79 = F_874 ( V_10 , V_1292 , true ) ;
if ( ! V_79 && F_878 ( V_10 ) ) {
F_148 ( L_278 ) ;
F_875 ( V_10 , V_1286 , V_110 ) ;
}
if ( ! V_79 && F_879 ( V_10 ) )
F_873 ( V_10 , V_1287 , V_110 ) ;
}
if ( F_5 ( V_1292 ) & V_1283 ) {
F_148 ( L_279 ) ;
V_79 = F_874 ( V_10 , V_1293 , false ) ;
}
if ( ! V_79 && ( F_5 ( V_1293 ) & V_1283 ) ) {
if ( F_878 ( V_10 ) ) {
F_148 ( L_280 ) ;
F_875 ( V_10 , V_1288 , V_112 ) ;
}
if ( F_879 ( V_10 ) )
F_873 ( V_10 , V_1289 , V_112 ) ;
}
if ( F_879 ( V_10 ) &&
( F_5 ( V_1291 ) & V_1272 ) )
F_873 ( V_10 , V_1291 , V_114 ) ;
} else if ( F_24 ( V_10 ) )
F_880 ( V_10 ) ;
if ( F_881 ( V_10 ) )
F_882 ( V_10 ) ;
F_883 ( V_10 ) ;
F_573 (dev, encoder) {
V_6 -> V_8 . V_1050 = V_6 -> V_236 ;
V_6 -> V_8 . V_1294 =
F_863 ( V_6 ) ;
}
F_580 ( V_10 ) ;
F_884 ( V_10 ) ;
}
static void F_885 ( struct V_280 * V_92 )
{
struct V_9 * V_10 = V_92 -> V_10 ;
struct V_883 * V_884 = F_204 ( V_92 ) ;
F_886 ( V_92 ) ;
F_60 ( & V_10 -> V_299 ) ;
F_3 ( ! V_884 -> V_296 -> V_1295 -- ) ;
F_205 ( & V_884 -> V_296 -> V_8 ) ;
F_62 ( & V_10 -> V_299 ) ;
F_210 ( V_884 ) ;
}
static int F_887 ( struct V_280 * V_92 ,
struct V_1262 * V_1263 ,
unsigned int * V_1296 )
{
struct V_883 * V_884 = F_204 ( V_92 ) ;
struct V_295 * V_296 = V_884 -> V_296 ;
return F_888 ( V_1263 , & V_296 -> V_8 , V_1296 ) ;
}
static
T_1 F_889 ( struct V_9 * V_10 , V_67 V_291 ,
T_4 V_269 )
{
T_1 V_105 = F_49 ( V_10 ) -> V_105 ;
if ( V_105 >= 9 ) {
return V_68 ( 8192 * F_176 ( V_269 , 0 ) , 32768 ) ;
} else if ( V_105 >= 5 && ! F_23 ( V_10 ) ) {
return 32 * 1024 ;
} else if ( V_105 >= 4 ) {
if ( V_291 == V_274 )
return 16 * 1024 ;
else
return 32 * 1024 ;
} else if ( V_105 >= 3 ) {
if ( V_291 == V_274 )
return 8 * 1024 ;
else
return 16 * 1024 ;
} else {
return 8 * 1024 ;
}
}
static int F_203 ( struct V_9 * V_10 ,
struct V_883 * V_884 ,
struct V_335 * V_336 ,
struct V_295 * V_296 )
{
unsigned int V_882 ;
int V_298 ;
T_1 V_1297 , V_1298 ;
F_3 ( ! F_185 ( & V_10 -> V_299 ) ) ;
if ( V_336 -> V_345 & V_346 ) {
if ( ! ! ( V_296 -> V_305 == V_342 ) !=
! ! ( V_336 -> V_292 [ 0 ] == V_274 ) ) {
F_850 ( L_281 ) ;
return - V_300 ;
}
} else {
if ( V_296 -> V_305 == V_342 )
V_336 -> V_292 [ 0 ] = V_274 ;
else if ( V_296 -> V_305 == V_1299 ) {
F_850 ( L_282 ) ;
return - V_300 ;
}
}
switch ( V_336 -> V_292 [ 0 ] ) {
case V_275 :
case V_276 :
if ( F_49 ( V_10 ) -> V_105 < 9 ) {
F_850 ( L_283 ,
V_336 -> V_292 [ 0 ] ) ;
return - V_300 ;
}
case V_273 :
case V_274 :
break;
default:
F_850 ( L_284 ,
V_336 -> V_292 [ 0 ] ) ;
return - V_300 ;
}
V_1298 = F_230 ( V_10 , V_336 -> V_292 [ 0 ] ,
V_336 -> V_269 ) ;
if ( V_336 -> V_290 [ 0 ] & ( V_1298 - 1 ) ) {
F_850 ( L_285 ,
V_336 -> V_290 [ 0 ] , V_1298 ) ;
return - V_300 ;
}
V_1297 = F_889 ( V_10 , V_336 -> V_292 [ 0 ] ,
V_336 -> V_269 ) ;
if ( V_336 -> V_290 [ 0 ] > V_1297 ) {
F_850 ( L_286 ,
V_336 -> V_292 [ 0 ] != V_273 ?
L_287 : L_288 ,
V_336 -> V_290 [ 0 ] , V_1297 ) ;
return - V_300 ;
}
if ( V_336 -> V_292 [ 0 ] == V_274 &&
V_336 -> V_290 [ 0 ] != V_296 -> V_343 ) {
F_850 ( L_289 ,
V_336 -> V_290 [ 0 ] , V_296 -> V_343 ) ;
return - V_300 ;
}
switch ( V_336 -> V_269 ) {
case V_313 :
case V_317 :
case V_319 :
case V_331 :
break;
case V_315 :
if ( F_49 ( V_10 ) -> V_105 > 3 ) {
F_850 ( L_290 ,
F_890 ( V_336 -> V_269 ) ) ;
return - V_300 ;
}
break;
case V_330 :
if ( ! F_23 ( V_10 ) && F_49 ( V_10 ) -> V_105 < 9 ) {
F_850 ( L_290 ,
F_890 ( V_336 -> V_269 ) ) ;
return - V_300 ;
}
break;
case V_321 :
case V_323 :
case V_325 :
if ( F_49 ( V_10 ) -> V_105 < 4 ) {
F_850 ( L_290 ,
F_890 ( V_336 -> V_269 ) ) ;
return - V_300 ;
}
break;
case V_1300 :
if ( ! F_23 ( V_10 ) ) {
F_850 ( L_290 ,
F_890 ( V_336 -> V_269 ) ) ;
return - V_300 ;
}
break;
case V_376 :
case V_381 :
case V_379 :
case V_383 :
if ( F_49 ( V_10 ) -> V_105 < 5 ) {
F_850 ( L_290 ,
F_890 ( V_336 -> V_269 ) ) ;
return - V_300 ;
}
break;
default:
F_850 ( L_290 ,
F_890 ( V_336 -> V_269 ) ) ;
return - V_300 ;
}
if ( V_336 -> V_1135 [ 0 ] != 0 )
return - V_300 ;
V_882 = F_179 ( V_10 , V_336 -> V_277 ,
V_336 -> V_269 ,
V_336 -> V_292 [ 0 ] ) ;
if ( V_296 -> V_8 . V_340 < V_882 * V_336 -> V_290 [ 0 ] )
return - V_300 ;
F_891 ( & V_884 -> V_8 , V_336 ) ;
V_884 -> V_296 = V_296 ;
V_884 -> V_296 -> V_1295 ++ ;
V_298 = F_892 ( V_10 , & V_884 -> V_8 , & V_1301 ) ;
if ( V_298 ) {
F_127 ( L_291 , V_298 ) ;
return V_298 ;
}
return 0 ;
}
static struct V_280 *
F_893 ( struct V_9 * V_10 ,
struct V_1262 * V_1302 ,
struct V_335 * V_336 )
{
struct V_295 * V_296 ;
V_296 = F_894 ( F_895 ( V_10 , V_1302 ,
V_336 -> V_1303 [ 0 ] ) ) ;
if ( & V_296 -> V_8 == NULL )
return F_645 ( - V_1268 ) ;
return F_646 ( V_10 , V_336 , V_296 ) ;
}
static inline void F_896 ( struct V_9 * V_10 )
{
}
static void F_897 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_4 ( V_10 ) || F_20 ( V_10 ) )
V_12 -> V_264 . V_874 = F_35 ;
else if ( F_22 ( V_10 ) )
V_12 -> V_264 . V_874 = F_40 ;
else if ( F_23 ( V_10 ) )
V_12 -> V_264 . V_874 = F_39 ;
else if ( F_21 ( V_10 ) )
V_12 -> V_264 . V_874 = F_34 ;
else
V_12 -> V_264 . V_874 = F_32 ;
if ( F_49 ( V_10 ) -> V_105 >= 9 ) {
V_12 -> V_264 . V_1191 = F_634 ;
V_12 -> V_264 . V_1304 =
F_606 ;
V_12 -> V_264 . V_1197 =
F_625 ;
V_12 -> V_264 . V_424 = F_392 ;
V_12 -> V_264 . V_423 = F_404 ;
V_12 -> V_264 . V_693 = F_408 ;
V_12 -> V_264 . V_265 =
F_240 ;
} else if ( F_66 ( V_10 ) ) {
V_12 -> V_264 . V_1191 = F_634 ;
V_12 -> V_264 . V_1304 =
F_609 ;
V_12 -> V_264 . V_1197 =
F_625 ;
V_12 -> V_264 . V_424 = F_392 ;
V_12 -> V_264 . V_423 = F_404 ;
V_12 -> V_264 . V_693 = F_408 ;
V_12 -> V_264 . V_265 =
F_226 ;
} else if ( F_4 ( V_10 ) ) {
V_12 -> V_264 . V_1191 = F_610 ;
V_12 -> V_264 . V_1304 =
F_609 ;
V_12 -> V_264 . V_1197 =
F_599 ;
V_12 -> V_264 . V_424 = F_381 ;
V_12 -> V_264 . V_423 = F_402 ;
V_12 -> V_264 . V_693 = F_408 ;
V_12 -> V_264 . V_265 =
F_226 ;
} else if ( F_23 ( V_10 ) ) {
V_12 -> V_264 . V_1191 = F_570 ;
V_12 -> V_264 . V_1304 =
F_568 ;
V_12 -> V_264 . V_1197 = F_565 ;
V_12 -> V_264 . V_424 = F_459 ;
V_12 -> V_264 . V_423 = F_470 ;
V_12 -> V_264 . V_693 = F_471 ;
V_12 -> V_264 . V_265 =
F_214 ;
} else {
V_12 -> V_264 . V_1191 = F_570 ;
V_12 -> V_264 . V_1304 =
F_568 ;
V_12 -> V_264 . V_1197 = F_565 ;
V_12 -> V_264 . V_424 = F_468 ;
V_12 -> V_264 . V_423 = F_470 ;
V_12 -> V_264 . V_693 = F_471 ;
V_12 -> V_264 . V_265 =
F_214 ;
}
if ( F_633 ( V_10 ) )
V_12 -> V_264 . V_654 =
F_498 ;
else if ( F_228 ( V_10 ) )
V_12 -> V_264 . V_654 =
F_499 ;
else if ( F_227 ( V_10 ) )
V_12 -> V_264 . V_654 =
F_500 ;
else if ( F_23 ( V_10 ) )
V_12 -> V_264 . V_654 =
F_502 ;
else if ( F_7 ( V_10 ) )
V_12 -> V_264 . V_654 =
F_503 ;
else if ( F_558 ( V_10 ) || F_186 ( V_10 ) ||
F_293 ( V_10 ) || F_285 ( V_10 ) || ( F_560 ( V_10 ) && ! F_898 ( V_10 ) ) )
V_12 -> V_264 . V_654 =
F_504 ;
else if ( F_497 ( V_10 ) )
V_12 -> V_264 . V_654 =
F_505 ;
else if ( F_559 ( V_10 ) || F_77 ( V_10 ) )
V_12 -> V_264 . V_654 =
F_506 ;
else if ( F_21 ( V_10 ) )
V_12 -> V_264 . V_654 =
F_507 ;
else if ( F_899 ( V_10 ) )
V_12 -> V_264 . V_654 =
F_509 ;
else if ( F_78 ( V_10 ) )
V_12 -> V_264 . V_654 =
F_510 ;
else if ( F_900 ( V_10 ) )
V_12 -> V_264 . V_654 =
F_511 ;
else
V_12 -> V_264 . V_654 =
F_512 ;
if ( F_7 ( V_10 ) ) {
V_12 -> V_264 . V_506 = F_286 ;
} else if ( F_293 ( V_10 ) ) {
V_12 -> V_264 . V_506 = F_291 ;
} else if ( F_285 ( V_10 ) ) {
V_12 -> V_264 . V_506 = F_294 ;
} else if ( F_227 ( V_10 ) || F_228 ( V_10 ) ) {
V_12 -> V_264 . V_506 = V_1305 ;
} else if ( F_23 ( V_10 ) ) {
V_12 -> V_264 . V_600 =
F_458 ;
} else if ( F_19 ( V_10 ) ) {
V_12 -> V_264 . V_600 =
F_624 ;
}
switch ( F_49 ( V_10 ) -> V_105 ) {
case 2 :
V_12 -> V_264 . V_1141 = F_703 ;
break;
case 3 :
V_12 -> V_264 . V_1141 = F_708 ;
break;
case 4 :
case 5 :
V_12 -> V_264 . V_1141 = F_709 ;
break;
case 6 :
V_12 -> V_264 . V_1141 = F_710 ;
break;
case 7 :
case 8 :
V_12 -> V_264 . V_1141 = F_711 ;
break;
case 9 :
default:
V_12 -> V_264 . V_1141 = F_732 ;
}
F_901 ( V_10 ) ;
F_902 ( & V_12 -> V_1306 ) ;
}
static void F_903 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_160 |= V_161 ;
F_904 ( L_292 ) ;
}
static void F_905 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_160 |= V_162 ;
F_904 ( L_293 ) ;
}
static void F_906 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_160 |= V_762 ;
F_904 ( L_294 ) ;
}
static void F_907 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_160 |= V_1307 ;
F_904 ( L_295 ) ;
}
static void F_908 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_160 |= V_1308 ;
F_904 ( L_296 ) ;
}
static int F_909 ( const struct V_1309 * V_239 )
{
F_904 ( L_297 , V_239 -> V_1310 ) ;
return 1 ;
}
static void F_910 ( struct V_9 * V_10 )
{
struct V_1311 * V_1312 = V_10 -> V_726 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < F_295 ( V_1313 ) ; V_38 ++ ) {
struct V_1314 * V_1315 = & V_1313 [ V_38 ] ;
if ( V_1312 -> V_1316 == V_1315 -> V_1316 &&
( V_1312 -> V_1317 == V_1315 -> V_1317 ||
V_1315 -> V_1317 == V_1318 ) &&
( V_1312 -> V_1319 == V_1315 -> V_1319 ||
V_1315 -> V_1319 == V_1318 ) )
V_1315 -> V_1320 ( V_10 ) ;
}
for ( V_38 = 0 ; V_38 < F_295 ( V_1321 ) ; V_38 ++ ) {
if ( F_911 ( * V_1321 [ V_38 ] . V_1322 ) != 0 )
V_1321 [ V_38 ] . V_1320 ( V_10 ) ;
}
}
static void F_912 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_9 V_1323 ;
T_1 V_1324 = F_913 ( V_10 ) ;
F_914 ( V_10 -> V_726 , V_1325 ) ;
F_915 ( V_1326 , V_1327 ) ;
V_1323 = F_916 ( V_1328 ) ;
F_915 ( V_1323 | 1 << 5 , V_1328 ) ;
F_917 ( V_10 -> V_726 , V_1325 ) ;
F_126 ( 300 ) ;
F_124 ( V_1324 , V_1329 ) ;
F_125 ( V_1324 ) ;
}
void F_268 ( struct V_9 * V_10 )
{
F_623 ( V_10 ) ;
if ( F_23 ( V_10 ) )
F_439 ( V_10 ) ;
F_918 ( V_10 ) ;
F_919 ( V_10 ) ;
}
void F_920 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_169 , V_298 ;
enum V_4 V_4 ;
struct V_28 * V_29 ;
F_921 ( V_10 ) ;
V_10 -> V_1044 . V_1330 = 0 ;
V_10 -> V_1044 . V_1331 = 0 ;
V_10 -> V_1044 . V_1332 = 24 ;
V_10 -> V_1044 . V_1333 = 1 ;
V_10 -> V_1044 . V_1334 = true ;
V_10 -> V_1044 . V_1049 = & V_1335 ;
F_910 ( V_10 ) ;
F_922 ( V_10 ) ;
if ( F_49 ( V_10 ) -> V_701 == 0 )
return;
F_897 ( V_10 ) ;
F_923 ( V_10 ) ;
if ( F_24 ( V_10 ) ) {
V_10 -> V_1044 . V_1336 = 2048 ;
V_10 -> V_1044 . V_1337 = 2048 ;
} else if ( F_924 ( V_10 ) ) {
V_10 -> V_1044 . V_1336 = 4096 ;
V_10 -> V_1044 . V_1337 = 4096 ;
} else {
V_10 -> V_1044 . V_1336 = 8192 ;
V_10 -> V_1044 . V_1337 = 8192 ;
}
if ( F_77 ( V_10 ) || F_78 ( V_10 ) ) {
V_10 -> V_1044 . V_1338 = F_77 ( V_10 ) ? 64 : 512 ;
V_10 -> V_1044 . V_1339 = 1023 ;
} else if ( F_24 ( V_10 ) ) {
V_10 -> V_1044 . V_1338 = V_1340 ;
V_10 -> V_1044 . V_1339 = V_1341 ;
} else {
V_10 -> V_1044 . V_1338 = V_1342 ;
V_10 -> V_1044 . V_1339 = V_1343 ;
}
V_10 -> V_1044 . V_1344 = V_12 -> V_1345 . V_1346 ;
F_148 ( L_298 ,
F_49 ( V_10 ) -> V_701 ,
F_49 ( V_10 ) -> V_701 > 1 ? L_299 : L_300 ) ;
F_87 (dev_priv, pipe) {
F_854 ( V_10 , V_4 ) ;
F_89 (dev_priv, pipe, sprite) {
V_298 = F_925 ( V_10 , V_4 , V_169 ) ;
if ( V_298 )
F_148 ( L_301 ,
F_75 ( V_4 ) , F_92 ( V_4 , V_169 ) , V_298 ) ;
}
}
F_118 ( V_10 ) ;
F_823 ( V_10 ) ;
F_912 ( V_10 ) ;
F_867 ( V_10 ) ;
F_376 ( V_10 ) ;
F_264 ( V_10 ) ;
F_271 ( V_10 , false ) ;
F_273 ( V_10 ) ;
F_135 (dev, crtc) {
if ( ! V_29 -> V_90 )
continue;
if ( V_12 -> V_264 . V_1304 ) {
V_12 -> V_264 . V_1304 ( V_29 ,
& V_29 -> V_334 ) ;
F_209 ( V_29 , & V_29 -> V_334 ) ;
}
}
}
static void F_926 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
struct V_35 * V_1347 = NULL ;
struct V_1038 V_1048 ;
struct V_1040 * V_1041 = V_10 -> V_1044 . V_1055 ;
F_755 (dev, connector) {
if ( V_3 -> V_6 -> type == V_51 ) {
V_1347 = & V_3 -> V_8 ;
break;
}
}
if ( ! V_1347 )
return;
if ( F_661 ( V_1347 , NULL , & V_1048 , V_1041 ) )
F_670 ( V_1347 , & V_1048 , V_1041 ) ;
}
static bool
F_927 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_99 , V_121 ;
if ( F_49 ( V_10 ) -> V_701 == 1 )
return true ;
V_99 = F_84 ( ! V_29 -> V_164 ) ;
V_121 = F_5 ( V_99 ) ;
if ( ( V_121 & V_165 ) &&
( ! ! ( V_121 & V_167 ) == V_29 -> V_4 ) )
return false ;
return true ;
}
static void F_928 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_99 ;
V_99 = F_50 ( V_29 -> V_93 -> V_98 ) ;
F_124 ( V_99 , F_5 ( V_99 ) & ~ V_1348 ) ;
F_929 ( & V_29 -> V_8 ) ;
if ( V_29 -> V_90 ) {
F_795 ( V_29 ) ;
F_388 ( & V_29 -> V_8 ) ;
}
if ( F_49 ( V_10 ) -> V_105 < 4 && ! F_927 ( V_29 ) ) {
struct V_2 * V_3 ;
bool V_164 ;
F_148 ( L_302 ,
V_29 -> V_8 . V_8 . V_239 ) ;
V_164 = V_29 -> V_164 ;
F_172 ( V_29 -> V_8 . V_91 -> V_34 ) -> V_263 = true ;
V_29 -> V_164 = ! V_164 ;
F_261 ( & V_29 -> V_8 ) ;
V_12 -> V_264 . V_423 ( & V_29 -> V_8 ) ;
V_29 -> V_164 = V_164 ;
F_755 (dev, connector) {
if ( V_3 -> V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
V_3 -> V_8 . V_694 = V_695 ;
V_3 -> V_8 . V_6 = NULL ;
}
F_755 (dev, connector)
if ( V_3 -> V_6 -> V_8 . V_29 == & V_29 -> V_8 ) {
V_3 -> V_6 -> V_8 . V_29 = NULL ;
V_3 -> V_6 -> V_692 = false ;
}
F_3 ( V_29 -> V_90 ) ;
V_29 -> V_8 . V_34 -> V_241 = false ;
V_29 -> V_8 . V_34 -> V_90 = false ;
V_29 -> V_8 . V_120 = false ;
}
if ( V_12 -> V_160 & V_161 &&
V_29 -> V_4 == V_142 && ! V_29 -> V_90 ) {
F_926 ( V_10 ) ;
}
F_473 ( & V_29 -> V_8 ) ;
if ( V_29 -> V_90 != V_29 -> V_8 . V_34 -> V_241 ) {
struct V_1 * V_6 ;
F_148 ( L_303 ,
V_29 -> V_8 . V_8 . V_239 ,
V_29 -> V_8 . V_34 -> V_241 ? L_205 : L_206 ,
V_29 -> V_90 ? L_205 : L_206 ) ;
V_29 -> V_8 . V_34 -> V_241 = V_29 -> V_90 ;
V_29 -> V_8 . V_34 -> V_90 = V_29 -> V_90 ;
V_29 -> V_8 . V_120 = V_29 -> V_90 ;
F_3 ( V_29 -> V_90 ) ;
F_11 (dev, &crtc->base, encoder) {
F_3 ( V_6 -> V_692 ) ;
V_6 -> V_8 . V_29 = NULL ;
}
}
if ( V_29 -> V_90 || F_165 ( V_10 ) ) {
V_29 -> V_1349 = true ;
V_29 -> V_1350 = true ;
}
}
static void F_930 ( struct V_1 * V_6 )
{
struct V_2 * V_3 ;
struct V_9 * V_10 = V_6 -> V_8 . V_10 ;
bool V_1351 = V_6 -> V_8 . V_29 &&
F_33 ( V_6 -> V_8 . V_29 ) -> V_90 ;
if ( V_6 -> V_692 && ! V_1351 ) {
F_148 ( L_304 ,
V_6 -> V_8 . V_8 . V_239 ,
V_6 -> V_8 . V_134 ) ;
if ( V_6 -> V_8 . V_29 ) {
F_148 ( L_305 ,
V_6 -> V_8 . V_8 . V_239 ,
V_6 -> V_8 . V_134 ) ;
V_6 -> V_242 ( V_6 ) ;
if ( V_6 -> V_575 )
V_6 -> V_575 ( V_6 ) ;
}
V_6 -> V_8 . V_29 = NULL ;
V_6 -> V_692 = false ;
F_755 (dev, connector) {
if ( V_3 -> V_6 != V_6 )
continue;
V_3 -> V_8 . V_694 = V_695 ;
V_3 -> V_8 . V_6 = NULL ;
}
}
}
void F_931 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_1324 = F_913 ( V_10 ) ;
if ( ! ( F_5 ( V_1324 ) & V_1329 ) ) {
F_148 ( L_306 ) ;
F_912 ( V_10 ) ;
}
}
void F_932 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_81 ( V_12 , V_1352 ) )
return;
F_931 ( V_10 ) ;
}
static bool F_933 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
if ( ! V_29 -> V_90 )
return false ;
return F_5 ( F_84 ( V_29 -> V_164 ) ) & V_165 ;
}
static void F_934 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
int V_38 ;
F_135 (dev, crtc) {
struct V_262 * V_91 = V_29 -> V_8 . V_91 ;
struct V_401 * V_282 ;
memset ( V_29 -> V_93 , 0 , sizeof( * V_29 -> V_93 ) ) ;
V_29 -> V_93 -> V_8 . V_29 = & V_29 -> V_8 ;
V_29 -> V_93 -> V_160 |= V_1178 ;
V_29 -> V_90 = V_12 -> V_264 . V_1191 ( V_29 ,
V_29 -> V_93 ) ;
V_29 -> V_8 . V_34 -> V_241 = V_29 -> V_90 ;
V_29 -> V_8 . V_34 -> V_90 = V_29 -> V_90 ;
V_29 -> V_8 . V_120 = V_29 -> V_90 ;
V_282 = F_172 ( V_91 -> V_34 ) ;
V_282 -> V_263 = F_933 ( V_29 ) ;
F_148 ( L_307 ,
V_29 -> V_8 . V_8 . V_239 ,
V_29 -> V_90 ? L_205 : L_206 ) ;
}
for ( V_38 = 0 ; V_38 < V_12 -> V_523 ; V_38 ++ ) {
struct V_127 * V_130 = & V_12 -> V_129 [ V_38 ] ;
V_130 -> V_237 = V_130 -> V_133 ( V_12 , V_130 ,
& V_130 -> V_93 . V_132 ) ;
V_130 -> V_90 = 0 ;
V_130 -> V_93 . V_236 = 0 ;
F_135 (dev, crtc) {
if ( V_29 -> V_90 && F_63 ( V_29 ) == V_130 ) {
V_130 -> V_90 ++ ;
V_130 -> V_93 . V_236 |= 1 << V_29 -> V_4 ;
}
}
F_148 ( L_308 ,
V_130 -> V_134 , V_130 -> V_93 . V_236 , V_130 -> V_237 ) ;
if ( V_130 -> V_93 . V_236 )
F_150 ( V_12 , V_240 ) ;
}
F_573 (dev, encoder) {
V_4 = 0 ;
if ( V_6 -> V_133 ( V_6 , & V_4 ) ) {
V_29 = F_33 ( V_12 -> V_97 [ V_4 ] ) ;
V_6 -> V_8 . V_29 = & V_29 -> V_8 ;
V_6 -> V_1192 ( V_6 , V_29 -> V_93 ) ;
} else {
V_6 -> V_8 . V_29 = NULL ;
}
V_6 -> V_692 = false ;
F_148 ( L_309 ,
V_6 -> V_8 . V_8 . V_239 ,
V_6 -> V_8 . V_134 ,
V_6 -> V_8 . V_29 ? L_205 : L_206 ,
F_75 ( V_4 ) ) ;
}
F_755 (dev, connector) {
if ( V_3 -> V_133 ( V_3 ) ) {
V_3 -> V_8 . V_694 = V_697 ;
V_3 -> V_6 -> V_692 = true ;
V_3 -> V_8 . V_6 = & V_3 -> V_6 -> V_8 ;
} else {
V_3 -> V_8 . V_694 = V_695 ;
V_3 -> V_8 . V_6 = NULL ;
}
F_148 ( L_310 ,
V_3 -> V_8 . V_8 . V_239 ,
V_3 -> V_8 . V_134 ,
V_3 -> V_8 . V_6 ? L_205 : L_206 ) ;
}
}
void F_271 ( struct V_9 * V_10 ,
bool V_1200 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_6 ;
int V_38 ;
F_934 ( V_10 ) ;
F_135 (dev, crtc) {
if ( V_29 -> V_90 && V_435 . V_436 ) {
F_563 ( & V_29 -> V_8 . V_419 ,
V_29 -> V_93 ) ;
F_148 ( L_311 ,
V_29 -> V_8 . V_8 . V_239 ) ;
F_764 ( & V_29 -> V_8 . V_419 ) ;
}
}
F_573 (dev, encoder) {
F_930 ( V_6 ) ;
}
F_87 (dev_priv, pipe) {
V_29 = F_33 ( V_12 -> V_97 [ V_4 ] ) ;
F_928 ( V_29 ) ;
F_762 ( V_29 , V_29 -> V_93 ,
L_312 ) ;
}
F_756 ( V_10 ) ;
for ( V_38 = 0 ; V_38 < V_12 -> V_523 ; V_38 ++ ) {
struct V_127 * V_130 = & V_12 -> V_129 [ V_38 ] ;
if ( ! V_130 -> V_237 || V_130 -> V_90 )
continue;
F_148 ( L_313 , V_130 -> V_134 ) ;
V_130 -> V_242 ( V_12 , V_130 ) ;
V_130 -> V_237 = false ;
}
if ( F_935 ( V_10 ) )
F_936 ( V_10 ) ;
else if ( F_4 ( V_10 ) )
F_937 ( V_10 ) ;
if ( V_1200 ) {
F_932 ( V_10 ) ;
F_87 (dev_priv, pipe) {
struct V_89 * V_29 =
V_12 -> V_97 [ V_4 ] ;
F_808 ( V_29 ) ;
}
} else {
F_754 ( V_10 ) ;
}
F_485 ( V_10 ) ;
}
void F_938 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_89 * V_348 ;
struct V_295 * V_296 ;
int V_298 ;
F_60 ( & V_10 -> V_299 ) ;
F_939 ( V_10 ) ;
F_62 ( & V_10 -> V_299 ) ;
if ( F_54 ( V_10 ) || F_100 ( V_10 ) )
V_12 -> V_760 . V_761 = ! ! ( F_5 ( V_174 ) &
V_903 ) ;
F_268 ( V_10 ) ;
F_940 ( V_10 ) ;
F_211 (dev, c) {
V_296 = F_184 ( V_348 -> V_91 -> V_92 ) ;
if ( V_296 == NULL )
continue;
F_60 ( & V_10 -> V_299 ) ;
V_298 = F_183 ( V_348 -> V_91 ,
V_348 -> V_91 -> V_92 ,
V_348 -> V_91 -> V_34 ,
NULL ) ;
F_62 ( & V_10 -> V_299 ) ;
if ( V_298 ) {
F_127 ( L_314 ,
F_33 ( V_348 ) -> V_4 ) ;
F_207 ( V_348 -> V_91 -> V_92 ) ;
V_348 -> V_91 -> V_92 = NULL ;
F_206 ( V_348 -> V_91 ) ;
}
}
F_941 ( V_10 ) ;
}
void F_942 ( struct V_2 * V_2 )
{
struct V_35 * V_3 = & V_2 -> V_8 ;
F_943 ( V_3 ) ;
F_944 ( V_3 ) ;
}
void F_945 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_35 * V_3 ;
F_946 ( V_10 ) ;
F_947 ( V_10 ) ;
F_948 ( V_12 ) ;
F_949 ( V_10 ) ;
F_60 ( & V_10 -> V_299 ) ;
F_950 () ;
F_376 ( V_10 ) ;
F_62 ( & V_10 -> V_299 ) ;
F_951 () ;
F_476 (connector, &dev->mode_config.connector_list, head) {
struct V_2 * V_2 ;
V_2 = F_663 ( V_3 ) ;
V_2 -> V_1353 ( V_2 ) ;
}
F_952 ( V_10 ) ;
F_953 ( V_10 ) ;
F_60 ( & V_10 -> V_299 ) ;
F_954 ( V_10 ) ;
F_62 ( & V_10 -> V_299 ) ;
}
struct V_696 * F_955 ( struct V_35 * V_3 )
{
return & F_662 ( V_3 ) -> V_8 ;
}
void F_956 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
V_3 -> V_6 = V_6 ;
F_957 ( & V_3 -> V_8 ,
& V_6 -> V_8 ) ;
}
int F_958 ( struct V_9 * V_10 , bool V_34 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned V_99 = F_49 ( V_10 ) -> V_105 >= 6 ? V_1354 : V_1355 ;
T_5 V_1356 ;
if ( F_508 ( V_12 -> V_1357 , V_99 , & V_1356 ) ) {
F_127 ( L_315 ) ;
return - V_1142 ;
}
if ( ! ! ( V_1356 & V_1358 ) == ! V_34 )
return 0 ;
if ( V_34 )
V_1356 &= ~ V_1358 ;
else
V_1356 |= V_1358 ;
if ( F_959 ( V_12 -> V_1357 , V_99 , V_1356 ) ) {
F_127 ( L_316 ) ;
return - V_1142 ;
}
return 0 ;
}
struct V_1359 *
F_960 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1359 * error ;
int V_1360 [] = {
V_253 ,
V_1361 ,
V_1362 ,
V_572 ,
} ;
int V_38 ;
if ( F_49 ( V_10 ) -> V_701 == 0 )
return NULL ;
error = F_482 ( sizeof( * error ) , V_1363 ) ;
if ( error == NULL )
return NULL ;
if ( F_227 ( V_10 ) || F_228 ( V_10 ) )
error -> V_1364 = F_5 ( V_951 ) ;
F_87 (dev_priv, i) {
error -> V_4 [ V_38 ] . V_1365 =
F_961 ( V_12 ,
F_415 ( V_38 ) ) ;
if ( ! error -> V_4 [ V_38 ] . V_1365 )
continue;
error -> V_1007 [ V_38 ] . V_578 = F_5 ( F_79 ( V_38 ) ) ;
error -> V_1007 [ V_38 ] . V_1366 = F_5 ( F_641 ( V_38 ) ) ;
error -> V_1007 [ V_38 ] . V_8 = F_5 ( F_640 ( V_38 ) ) ;
error -> V_164 [ V_38 ] . V_578 = F_5 ( F_84 ( V_38 ) ) ;
error -> V_164 [ V_38 ] . V_343 = F_5 ( F_223 ( V_38 ) ) ;
if ( F_49 ( V_10 ) -> V_105 <= 3 ) {
error -> V_164 [ V_38 ] . V_340 = F_5 ( F_217 ( V_38 ) ) ;
error -> V_164 [ V_38 ] . V_547 = F_5 ( F_218 ( V_38 ) ) ;
}
if ( F_49 ( V_10 ) -> V_105 <= 7 && ! F_227 ( V_10 ) )
error -> V_164 [ V_38 ] . V_1128 = F_5 ( F_216 ( V_38 ) ) ;
if ( F_49 ( V_10 ) -> V_105 >= 4 ) {
error -> V_164 [ V_38 ] . V_1367 = F_5 ( F_215 ( V_38 ) ) ;
error -> V_164 [ V_38 ] . V_1368 = F_5 ( F_224 ( V_38 ) ) ;
}
error -> V_4 [ V_38 ] . V_1369 = F_5 ( F_280 ( V_38 ) ) ;
if ( F_165 ( V_10 ) )
error -> V_4 [ V_38 ] . V_1370 = F_5 ( F_962 ( V_38 ) ) ;
}
error -> V_1371 = F_49 ( V_10 ) -> V_701 ;
if ( F_66 ( V_12 -> V_10 ) )
error -> V_1371 ++ ;
for ( V_38 = 0 ; V_38 < error -> V_1371 ; V_38 ++ ) {
enum V_96 V_98 = V_1360 [ V_38 ] ;
error -> V_96 [ V_38 ] . V_1365 =
F_961 ( V_12 ,
F_82 ( V_98 ) ) ;
if ( ! error -> V_96 [ V_38 ] . V_1365 )
continue;
error -> V_96 [ V_38 ] . V_98 = V_98 ;
error -> V_96 [ V_38 ] . V_1372 = F_5 ( F_50 ( V_98 ) ) ;
error -> V_96 [ V_38 ] . V_852 = F_5 ( F_319 ( V_98 ) ) ;
error -> V_96 [ V_38 ] . V_1373 = F_5 ( F_321 ( V_98 ) ) ;
error -> V_96 [ V_38 ] . V_1080 = F_5 ( F_323 ( V_98 ) ) ;
error -> V_96 [ V_38 ] . V_854 = F_5 ( F_325 ( V_98 ) ) ;
error -> V_96 [ V_38 ] . V_1374 = F_5 ( F_327 ( V_98 ) ) ;
error -> V_96 [ V_38 ] . V_1082 = F_5 ( F_329 ( V_98 ) ) ;
}
return error ;
}
void
F_963 ( struct V_1375 * V_19 ,
struct V_9 * V_10 ,
struct V_1359 * error )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_38 ;
if ( ! error )
return;
F_964 ( V_19 , L_317 , F_49 ( V_10 ) -> V_701 ) ;
if ( F_227 ( V_10 ) || F_228 ( V_10 ) )
F_964 ( V_19 , L_318 ,
error -> V_1364 ) ;
F_87 (dev_priv, i) {
F_964 ( V_19 , L_319 , V_38 ) ;
F_964 ( V_19 , L_320 ,
error -> V_4 [ V_38 ] . V_1365 ? L_11 : L_12 ) ;
F_964 ( V_19 , L_321 , error -> V_4 [ V_38 ] . V_1369 ) ;
F_964 ( V_19 , L_322 , error -> V_4 [ V_38 ] . V_1370 ) ;
F_964 ( V_19 , L_323 , V_38 ) ;
F_964 ( V_19 , L_324 , error -> V_164 [ V_38 ] . V_578 ) ;
F_964 ( V_19 , L_325 , error -> V_164 [ V_38 ] . V_343 ) ;
if ( F_49 ( V_10 ) -> V_105 <= 3 ) {
F_964 ( V_19 , L_326 , error -> V_164 [ V_38 ] . V_340 ) ;
F_964 ( V_19 , L_327 , error -> V_164 [ V_38 ] . V_547 ) ;
}
if ( F_49 ( V_10 ) -> V_105 <= 7 && ! F_227 ( V_10 ) )
F_964 ( V_19 , L_328 , error -> V_164 [ V_38 ] . V_1128 ) ;
if ( F_49 ( V_10 ) -> V_105 >= 4 ) {
F_964 ( V_19 , L_329 , error -> V_164 [ V_38 ] . V_1367 ) ;
F_964 ( V_19 , L_330 , error -> V_164 [ V_38 ] . V_1368 ) ;
}
F_964 ( V_19 , L_331 , V_38 ) ;
F_964 ( V_19 , L_324 , error -> V_1007 [ V_38 ] . V_578 ) ;
F_964 ( V_19 , L_327 , error -> V_1007 [ V_38 ] . V_1366 ) ;
F_964 ( V_19 , L_332 , error -> V_1007 [ V_38 ] . V_8 ) ;
}
for ( V_38 = 0 ; V_38 < error -> V_1371 ; V_38 ++ ) {
F_964 ( V_19 , L_333 ,
F_763 ( error -> V_96 [ V_38 ] . V_98 ) ) ;
F_964 ( V_19 , L_320 ,
error -> V_96 [ V_38 ] . V_1365 ? L_11 : L_12 ) ;
F_964 ( V_19 , L_334 , error -> V_96 [ V_38 ] . V_1372 ) ;
F_964 ( V_19 , L_335 , error -> V_96 [ V_38 ] . V_852 ) ;
F_964 ( V_19 , L_336 , error -> V_96 [ V_38 ] . V_1373 ) ;
F_964 ( V_19 , L_337 , error -> V_96 [ V_38 ] . V_1080 ) ;
F_964 ( V_19 , L_338 , error -> V_96 [ V_38 ] . V_854 ) ;
F_964 ( V_19 , L_339 , error -> V_96 [ V_38 ] . V_1374 ) ;
F_964 ( V_19 , L_340 , error -> V_96 [ V_38 ] . V_1082 ) ;
}
}
void F_965 ( struct V_9 * V_10 , struct V_1262 * V_1263 )
{
struct V_28 * V_29 ;
F_135 (dev, crtc) {
struct V_475 * V_476 ;
F_269 ( & V_10 -> V_432 ) ;
V_476 = V_29 -> V_433 ;
if ( V_476 && V_476 -> V_477 &&
V_476 -> V_477 -> V_8 . V_1376 == V_1263 ) {
F_210 ( V_476 -> V_477 ) ;
V_476 -> V_477 = NULL ;
}
F_270 ( & V_10 -> V_432 ) ;
}
}
