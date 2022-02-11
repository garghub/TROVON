int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( ! F_3 ( V_2 ) ) ;
return F_4 ( V_6 ) & V_7 ;
}
static inline T_1
F_5 ( struct V_1 * V_2 )
{
if ( F_6 ( V_2 ) ) {
struct V_3 * V_4 = V_2 -> V_5 ;
return ( F_4 ( V_8 ) & V_9 ) + 2 ;
} else
return 27 ;
}
static void F_7 ( int V_10 , T_2 * clock )
{
clock -> V_11 = clock -> V_12 * clock -> V_13 ;
clock -> V_14 = clock -> V_15 * clock -> V_16 ;
clock -> V_17 = F_8 ( V_10 * clock -> V_11 , clock -> V_18 ) ;
clock -> V_19 = F_8 ( clock -> V_17 , clock -> V_14 ) ;
}
static bool F_9 ( struct V_20 * V_21 , int type )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_22 * V_23 ;
F_10 (dev, crtc, encoder)
if ( V_23 -> type == type )
return true ;
return false ;
}
static const T_3 * F_11 ( struct V_20 * V_21 ,
int V_10 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
const T_3 * V_24 ;
if ( F_9 ( V_21 , V_25 ) ) {
if ( F_12 ( V_2 ) ) {
if ( V_10 == 100000 )
V_24 = & V_26 ;
else
V_24 = & V_27 ;
} else {
if ( V_10 == 100000 )
V_24 = & V_28 ;
else
V_24 = & V_29 ;
}
} else
V_24 = & V_30 ;
return V_24 ;
}
static const T_3 * F_13 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
const T_3 * V_24 ;
if ( F_9 ( V_21 , V_25 ) ) {
if ( F_12 ( V_2 ) )
V_24 = & V_31 ;
else
V_24 = & V_32 ;
} else if ( F_9 ( V_21 , V_33 ) ||
F_9 ( V_21 , V_34 ) ) {
V_24 = & V_35 ;
} else if ( F_9 ( V_21 , V_36 ) ) {
V_24 = & V_37 ;
} else
V_24 = & V_38 ;
return V_24 ;
}
static const T_3 * F_14 ( struct V_20 * V_21 , int V_10 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
const T_3 * V_24 ;
if ( F_3 ( V_2 ) )
V_24 = F_11 ( V_21 , V_10 ) ;
else if ( F_15 ( V_2 ) ) {
V_24 = F_13 ( V_21 ) ;
} else if ( F_16 ( V_2 ) ) {
if ( F_9 ( V_21 , V_25 ) )
V_24 = & V_39 ;
else
V_24 = & V_40 ;
} else if ( F_17 ( V_2 ) ) {
V_24 = & V_41 ;
} else if ( ! F_18 ( V_2 ) ) {
if ( F_9 ( V_21 , V_25 ) )
V_24 = & V_42 ;
else
V_24 = & V_38 ;
} else {
if ( F_9 ( V_21 , V_25 ) )
V_24 = & V_43 ;
else if ( F_9 ( V_21 , V_44 ) )
V_24 = & V_45 ;
else
V_24 = & V_46 ;
}
return V_24 ;
}
static void F_19 ( int V_10 , T_2 * clock )
{
clock -> V_11 = clock -> V_13 + 2 ;
clock -> V_14 = clock -> V_15 * clock -> V_16 ;
clock -> V_17 = F_8 ( V_10 * clock -> V_11 , clock -> V_18 ) ;
clock -> V_19 = F_8 ( clock -> V_17 , clock -> V_14 ) ;
}
static T_4 F_20 ( struct V_47 * V_47 )
{
return 5 * ( V_47 -> V_12 + 2 ) + ( V_47 -> V_13 + 2 ) ;
}
static void F_21 ( int V_10 , T_2 * clock )
{
clock -> V_11 = F_20 ( clock ) ;
clock -> V_14 = clock -> V_15 * clock -> V_16 ;
clock -> V_17 = F_8 ( V_10 * clock -> V_11 , clock -> V_18 + 2 ) ;
clock -> V_19 = F_8 ( clock -> V_17 , clock -> V_14 ) ;
}
static bool F_22 ( struct V_1 * V_2 ,
const T_3 * V_24 ,
const T_2 * clock )
{
if ( clock -> V_18 < V_24 -> V_18 . V_48 || V_24 -> V_18 . V_49 < clock -> V_18 )
F_23 ( L_1 ) ;
if ( clock -> V_15 < V_24 -> V_15 . V_48 || V_24 -> V_15 . V_49 < clock -> V_15 )
F_23 ( L_2 ) ;
if ( clock -> V_13 < V_24 -> V_13 . V_48 || V_24 -> V_13 . V_49 < clock -> V_13 )
F_23 ( L_3 ) ;
if ( clock -> V_12 < V_24 -> V_12 . V_48 || V_24 -> V_12 . V_49 < clock -> V_12 )
F_23 ( L_4 ) ;
if ( ! F_16 ( V_2 ) && ! F_17 ( V_2 ) )
if ( clock -> V_12 <= clock -> V_13 )
F_23 ( L_5 ) ;
if ( ! F_17 ( V_2 ) ) {
if ( clock -> V_14 < V_24 -> V_14 . V_48 || V_24 -> V_14 . V_49 < clock -> V_14 )
F_23 ( L_6 ) ;
if ( clock -> V_11 < V_24 -> V_11 . V_48 || V_24 -> V_11 . V_49 < clock -> V_11 )
F_23 ( L_7 ) ;
}
if ( clock -> V_17 < V_24 -> V_17 . V_48 || V_24 -> V_17 . V_49 < clock -> V_17 )
F_23 ( L_8 ) ;
if ( clock -> V_19 < V_24 -> V_19 . V_48 || V_24 -> V_19 . V_49 < clock -> V_19 )
F_23 ( L_9 ) ;
return true ;
}
static bool
F_24 ( const T_3 * V_24 , struct V_20 * V_21 ,
int V_50 , int V_10 , T_2 * V_51 ,
T_2 * V_52 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_2 clock ;
int V_53 = V_50 ;
if ( F_9 ( V_21 , V_25 ) ) {
if ( F_12 ( V_2 ) )
clock . V_16 = V_24 -> V_16 . V_54 ;
else
clock . V_16 = V_24 -> V_16 . V_55 ;
} else {
if ( V_50 < V_24 -> V_16 . V_56 )
clock . V_16 = V_24 -> V_16 . V_55 ;
else
clock . V_16 = V_24 -> V_16 . V_54 ;
}
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
for ( clock . V_12 = V_24 -> V_12 . V_48 ; clock . V_12 <= V_24 -> V_12 . V_49 ;
clock . V_12 ++ ) {
for ( clock . V_13 = V_24 -> V_13 . V_48 ;
clock . V_13 <= V_24 -> V_13 . V_49 ; clock . V_13 ++ ) {
if ( clock . V_13 >= clock . V_12 )
break;
for ( clock . V_18 = V_24 -> V_18 . V_48 ;
clock . V_18 <= V_24 -> V_18 . V_49 ; clock . V_18 ++ ) {
for ( clock . V_15 = V_24 -> V_15 . V_48 ;
clock . V_15 <= V_24 -> V_15 . V_49 ; clock . V_15 ++ ) {
int V_57 ;
F_21 ( V_10 , & clock ) ;
if ( ! F_22 ( V_2 , V_24 ,
& clock ) )
continue;
if ( V_51 &&
clock . V_14 != V_51 -> V_14 )
continue;
V_57 = abs ( clock . V_19 - V_50 ) ;
if ( V_57 < V_53 ) {
* V_52 = clock ;
V_53 = V_57 ;
}
}
}
}
}
return ( V_53 != V_50 ) ;
}
static bool
F_25 ( const T_3 * V_24 , struct V_20 * V_21 ,
int V_50 , int V_10 , T_2 * V_51 ,
T_2 * V_52 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_2 clock ;
int V_53 = V_50 ;
if ( F_9 ( V_21 , V_25 ) ) {
if ( F_12 ( V_2 ) )
clock . V_16 = V_24 -> V_16 . V_54 ;
else
clock . V_16 = V_24 -> V_16 . V_55 ;
} else {
if ( V_50 < V_24 -> V_16 . V_56 )
clock . V_16 = V_24 -> V_16 . V_55 ;
else
clock . V_16 = V_24 -> V_16 . V_54 ;
}
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
for ( clock . V_12 = V_24 -> V_12 . V_48 ; clock . V_12 <= V_24 -> V_12 . V_49 ;
clock . V_12 ++ ) {
for ( clock . V_13 = V_24 -> V_13 . V_48 ;
clock . V_13 <= V_24 -> V_13 . V_49 ; clock . V_13 ++ ) {
for ( clock . V_18 = V_24 -> V_18 . V_48 ;
clock . V_18 <= V_24 -> V_18 . V_49 ; clock . V_18 ++ ) {
for ( clock . V_15 = V_24 -> V_15 . V_48 ;
clock . V_15 <= V_24 -> V_15 . V_49 ; clock . V_15 ++ ) {
int V_57 ;
F_19 ( V_10 , & clock ) ;
if ( ! F_22 ( V_2 , V_24 ,
& clock ) )
continue;
if ( V_51 &&
clock . V_14 != V_51 -> V_14 )
continue;
V_57 = abs ( clock . V_19 - V_50 ) ;
if ( V_57 < V_53 ) {
* V_52 = clock ;
V_53 = V_57 ;
}
}
}
}
}
return ( V_53 != V_50 ) ;
}
static bool
F_26 ( const T_3 * V_24 , struct V_20 * V_21 ,
int V_50 , int V_10 , T_2 * V_51 ,
T_2 * V_52 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_2 clock ;
int V_58 ;
bool V_59 ;
int V_60 = ( V_50 >> 8 ) + ( V_50 >> 9 ) ;
V_59 = false ;
if ( F_9 ( V_21 , V_25 ) ) {
if ( F_12 ( V_2 ) )
clock . V_16 = V_24 -> V_16 . V_54 ;
else
clock . V_16 = V_24 -> V_16 . V_55 ;
} else {
if ( V_50 < V_24 -> V_16 . V_56 )
clock . V_16 = V_24 -> V_16 . V_55 ;
else
clock . V_16 = V_24 -> V_16 . V_54 ;
}
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_58 = V_24 -> V_18 . V_49 ;
for ( clock . V_18 = V_24 -> V_18 . V_48 ; clock . V_18 <= V_58 ; clock . V_18 ++ ) {
for ( clock . V_12 = V_24 -> V_12 . V_49 ;
clock . V_12 >= V_24 -> V_12 . V_48 ; clock . V_12 -- ) {
for ( clock . V_13 = V_24 -> V_13 . V_49 ;
clock . V_13 >= V_24 -> V_13 . V_48 ; clock . V_13 -- ) {
for ( clock . V_15 = V_24 -> V_15 . V_49 ;
clock . V_15 >= V_24 -> V_15 . V_48 ; clock . V_15 -- ) {
int V_57 ;
F_21 ( V_10 , & clock ) ;
if ( ! F_22 ( V_2 , V_24 ,
& clock ) )
continue;
V_57 = abs ( clock . V_19 - V_50 ) ;
if ( V_57 < V_60 ) {
* V_52 = clock ;
V_60 = V_57 ;
V_58 = clock . V_18 ;
V_59 = true ;
}
}
}
}
}
return V_59 ;
}
static bool
F_27 ( const T_3 * V_24 , struct V_20 * V_21 ,
int V_50 , int V_10 , T_2 * V_51 ,
T_2 * V_52 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_2 clock ;
unsigned int V_61 = 1000000 ;
int V_58 = V_48 ( V_24 -> V_18 . V_49 , V_10 / 19200 ) ;
bool V_59 = false ;
V_50 *= 5 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
for ( clock . V_18 = V_24 -> V_18 . V_48 ; clock . V_18 <= V_58 ; clock . V_18 ++ ) {
for ( clock . V_15 = V_24 -> V_15 . V_49 ; clock . V_15 >= V_24 -> V_15 . V_48 ; clock . V_15 -- ) {
for ( clock . V_16 = V_24 -> V_16 . V_54 ; clock . V_16 >= V_24 -> V_16 . V_55 ;
clock . V_16 -= clock . V_16 > 10 ? 2 : 1 ) {
clock . V_14 = clock . V_15 * clock . V_16 ;
for ( clock . V_12 = V_24 -> V_12 . V_48 ; clock . V_12 <= V_24 -> V_12 . V_49 ; clock . V_12 ++ ) {
unsigned int V_62 , V_63 ;
clock . V_13 = F_8 ( V_50 * clock . V_14 * clock . V_18 ,
V_10 * clock . V_12 ) ;
F_7 ( V_10 , & clock ) ;
if ( ! F_22 ( V_2 , V_24 ,
& clock ) )
continue;
V_63 = abs ( clock . V_19 - V_50 ) ;
V_62 = F_28 ( 1000000ULL * V_63 , V_50 ) ;
if ( V_62 < 100 && clock . V_14 > V_52 -> V_14 ) {
V_61 = 0 ;
* V_52 = clock ;
V_59 = true ;
}
if ( V_61 >= 10 && V_62 < V_61 - 10 ) {
V_61 = V_62 ;
* V_52 = clock ;
V_59 = true ;
}
}
}
}
}
return V_59 ;
}
bool F_29 ( struct V_20 * V_21 )
{
struct V_64 * V_64 = F_30 ( V_21 ) ;
return V_64 -> V_65 && V_21 -> V_66 &&
V_64 -> V_67 . V_68 . V_69 ;
}
enum V_70 F_31 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
struct V_20 * V_21 = V_4 -> V_72 [ V_71 ] ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
return V_64 -> V_67 . V_73 ;
}
static void F_32 ( struct V_1 * V_2 , int V_71 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_74 , V_75 = F_33 ( V_71 ) ;
V_74 = F_4 ( V_75 ) ;
if ( F_34 ( F_35 ( V_75 ) != V_74 , 50 ) )
F_36 ( L_10 ) ;
}
void F_37 ( struct V_1 * V_2 , int V_71 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_76 = F_38 ( V_71 ) ;
if ( F_39 ( V_2 ) -> V_77 >= 5 ) {
F_32 ( V_2 , V_71 ) ;
return;
}
F_40 ( V_76 ,
F_4 ( V_76 ) | V_78 ) ;
if ( F_34 ( F_4 ( V_76 ) &
V_78 ,
50 ) )
F_36 ( L_10 ) ;
}
static bool F_41 ( struct V_1 * V_2 , enum V_71 V_71 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_79 = F_42 ( V_71 ) ;
T_1 V_80 , V_81 ;
T_1 V_82 ;
if ( F_18 ( V_2 ) )
V_82 = V_83 ;
else
V_82 = V_84 ;
V_80 = F_4 ( V_79 ) & V_82 ;
F_43 ( 5 ) ;
V_81 = F_4 ( V_79 ) & V_82 ;
return V_80 == V_81 ;
}
void F_44 ( struct V_1 * V_2 , int V_71 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_70 V_73 = F_31 ( V_4 ,
V_71 ) ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
int V_79 = F_45 ( V_73 ) ;
if ( F_34 ( ( F_4 ( V_79 ) & V_85 ) == 0 ,
100 ) )
F_46 ( 1 , L_11 ) ;
} else {
if ( F_34 ( F_41 ( V_2 , V_71 ) , 100 ) )
F_46 ( 1 , L_11 ) ;
}
}
bool F_47 ( struct V_3 * V_4 ,
struct V_86 * V_87 )
{
T_1 V_88 ;
if ( F_48 ( V_4 -> V_2 ) ) {
switch( V_87 -> V_87 ) {
case V_89 :
V_88 = V_90 ;
break;
case V_91 :
V_88 = V_92 ;
break;
case V_93 :
V_88 = V_94 ;
break;
default:
return true ;
}
} else {
switch( V_87 -> V_87 ) {
case V_89 :
V_88 = V_95 ;
break;
case V_91 :
V_88 = V_96 ;
break;
case V_93 :
V_88 = V_97 ;
break;
default:
return true ;
}
}
return F_4 ( V_98 ) & V_88 ;
}
static const char * F_49 ( bool V_99 )
{
return V_99 ? L_12 : L_13 ;
}
void F_50 ( struct V_3 * V_4 ,
enum V_71 V_71 , bool V_100 )
{
int V_79 ;
T_1 V_101 ;
bool V_102 ;
V_79 = F_51 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
V_102 = ! ! ( V_101 & V_103 ) ;
F_46 ( V_102 != V_100 ,
L_14 ,
F_49 ( V_100 ) , F_49 ( V_102 ) ) ;
}
static void F_52 ( struct V_3 * V_4 , bool V_100 )
{
T_1 V_101 ;
bool V_102 ;
F_53 ( & V_4 -> V_104 ) ;
V_101 = F_54 ( V_4 , V_105 ) ;
F_55 ( & V_4 -> V_104 ) ;
V_102 = V_101 & V_106 ;
F_46 ( V_102 != V_100 ,
L_15 ,
F_49 ( V_100 ) , F_49 ( V_102 ) ) ;
}
struct V_107 *
F_56 ( struct V_64 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_108 . V_2 -> V_5 ;
if ( V_21 -> V_67 . V_109 < 0 )
return NULL ;
return & V_4 -> V_110 [ V_21 -> V_67 . V_109 ] ;
}
void F_57 ( struct V_3 * V_4 ,
struct V_107 * V_111 ,
bool V_100 )
{
bool V_102 ;
struct V_112 V_113 ;
if ( F_58 ( V_4 -> V_2 ) ) {
F_59 ( L_16 ) ;
return;
}
if ( F_46 ( ! V_111 ,
L_17 , F_49 ( V_100 ) ) )
return;
V_102 = V_111 -> V_114 ( V_4 , V_111 , & V_113 ) ;
F_46 ( V_102 != V_100 ,
L_18 ,
V_111 -> V_115 , F_49 ( V_100 ) , F_49 ( V_102 ) ) ;
}
static void F_60 ( struct V_3 * V_4 ,
enum V_71 V_71 , bool V_100 )
{
int V_79 ;
T_1 V_101 ;
bool V_102 ;
enum V_70 V_73 = F_31 ( V_4 ,
V_71 ) ;
if ( F_61 ( V_4 -> V_2 ) ) {
V_79 = F_62 ( V_73 ) ;
V_101 = F_4 ( V_79 ) ;
V_102 = ! ! ( V_101 & V_116 ) ;
} else {
V_79 = F_63 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
V_102 = ! ! ( V_101 & V_117 ) ;
}
F_46 ( V_102 != V_100 ,
L_19 ,
F_49 ( V_100 ) , F_49 ( V_102 ) ) ;
}
static void F_64 ( struct V_3 * V_4 ,
enum V_71 V_71 , bool V_100 )
{
int V_79 ;
T_1 V_101 ;
bool V_102 ;
V_79 = F_65 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
V_102 = ! ! ( V_101 & V_118 ) ;
F_46 ( V_102 != V_100 ,
L_20 ,
F_49 ( V_100 ) , F_49 ( V_102 ) ) ;
}
static void F_66 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
int V_79 ;
T_1 V_101 ;
if ( V_4 -> V_119 -> V_77 == 5 )
return;
if ( F_61 ( V_4 -> V_2 ) )
return;
V_79 = F_63 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
F_46 ( ! ( V_101 & V_120 ) , L_21 ) ;
}
void F_67 ( struct V_3 * V_4 ,
enum V_71 V_71 , bool V_100 )
{
int V_79 ;
T_1 V_101 ;
bool V_102 ;
V_79 = F_65 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
V_102 = ! ! ( V_101 & V_121 ) ;
F_46 ( V_102 != V_100 ,
L_22 ,
F_49 ( V_100 ) , F_49 ( V_102 ) ) ;
}
static void F_68 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
int V_122 , V_123 ;
T_1 V_101 ;
enum V_71 V_124 = V_125 ;
bool V_126 = true ;
if ( F_3 ( V_4 -> V_2 ) ) {
V_122 = V_127 ;
V_123 = V_128 ;
} else {
V_122 = V_129 ;
V_123 = V_130 ;
}
V_101 = F_4 ( V_122 ) ;
if ( ! ( V_101 & V_131 ) ||
( ( V_101 & V_132 ) == V_132 ) )
V_126 = false ;
if ( F_4 ( V_123 ) & V_133 )
V_124 = V_134 ;
F_46 ( V_124 == V_71 && V_126 ,
L_23 ,
F_69 ( V_71 ) ) ;
}
static void F_70 ( struct V_3 * V_4 ,
enum V_71 V_71 , bool V_100 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
bool V_102 ;
if ( F_71 ( V_2 ) || F_72 ( V_2 ) )
V_102 = F_4 ( F_73 ( V_71 ) ) & V_135 ;
else if ( F_74 ( V_2 ) || F_75 ( V_2 ) )
V_102 = F_4 ( V_136 ) & V_137 ;
else
V_102 = F_4 ( F_76 ( V_71 ) ) & V_135 ;
F_46 ( V_102 != V_100 ,
L_24 ,
F_69 ( V_71 ) , F_49 ( V_100 ) , F_49 ( V_102 ) ) ;
}
void F_77 ( struct V_3 * V_4 ,
enum V_71 V_71 , bool V_100 )
{
int V_79 ;
T_1 V_101 ;
bool V_102 ;
enum V_70 V_73 = F_31 ( V_4 ,
V_71 ) ;
if ( V_71 == V_125 && V_4 -> V_138 & V_139 )
V_100 = true ;
if ( ! F_78 ( V_4 -> V_2 ,
F_79 ( V_73 ) ) ) {
V_102 = false ;
} else {
V_79 = F_45 ( V_73 ) ;
V_101 = F_4 ( V_79 ) ;
V_102 = ! ! ( V_101 & V_140 ) ;
}
F_46 ( V_102 != V_100 ,
L_25 ,
F_69 ( V_71 ) , F_49 ( V_100 ) , F_49 ( V_102 ) ) ;
}
static void F_80 ( struct V_3 * V_4 ,
enum V_141 V_141 , bool V_100 )
{
int V_79 ;
T_1 V_101 ;
bool V_102 ;
V_79 = F_81 ( V_141 ) ;
V_101 = F_4 ( V_79 ) ;
V_102 = ! ! ( V_101 & V_142 ) ;
F_46 ( V_102 != V_100 ,
L_26 ,
F_82 ( V_141 ) , F_49 ( V_100 ) , F_49 ( V_102 ) ) ;
}
static void F_83 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_79 , V_143 ;
T_1 V_101 ;
int V_144 ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
V_79 = F_81 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
F_46 ( ( V_101 & V_142 ) ,
L_27 ,
F_82 ( V_71 ) ) ;
return;
}
F_84 (i) {
V_79 = F_81 ( V_143 ) ;
V_101 = F_4 ( V_79 ) ;
V_144 = ( V_101 & V_145 ) >>
V_146 ;
F_46 ( ( V_101 & V_142 ) && V_71 == V_144 ,
L_28 ,
F_82 ( V_143 ) , F_69 ( V_71 ) ) ;
}
}
static void F_85 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_79 , V_143 ;
T_1 V_101 ;
if ( F_17 ( V_2 ) ) {
for ( V_143 = 0 ; V_143 < V_4 -> V_147 ; V_143 ++ ) {
V_79 = F_86 ( V_71 , V_143 ) ;
V_101 = F_4 ( V_79 ) ;
F_46 ( ( V_101 & V_148 ) ,
L_29 ,
F_87 ( V_71 , V_143 ) , F_69 ( V_71 ) ) ;
}
} else if ( F_39 ( V_2 ) -> V_77 >= 7 ) {
V_79 = F_88 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
F_46 ( ( V_101 & V_149 ) ,
L_29 ,
F_82 ( V_71 ) , F_69 ( V_71 ) ) ;
} else if ( F_39 ( V_2 ) -> V_77 >= 5 ) {
V_79 = F_89 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
F_46 ( ( V_101 & V_150 ) ,
L_29 ,
F_82 ( V_71 ) , F_69 ( V_71 ) ) ;
}
}
static void F_90 ( struct V_3 * V_4 )
{
T_1 V_101 ;
bool V_99 ;
if ( F_58 ( V_4 -> V_2 ) ) {
F_59 ( L_30 ) ;
return;
}
V_101 = F_4 ( V_151 ) ;
V_99 = ! ! ( V_101 & ( V_152 | V_153 |
V_154 ) ) ;
F_46 ( ! V_99 , L_31 ) ;
}
static void F_91 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
int V_79 ;
T_1 V_101 ;
bool V_99 ;
V_79 = F_92 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
V_99 = ! ! ( V_101 & V_155 ) ;
F_46 ( V_99 ,
L_32 ,
F_69 ( V_71 ) ) ;
}
static bool F_93 ( struct V_3 * V_4 ,
enum V_71 V_71 , T_1 V_156 , T_1 V_101 )
{
if ( ( V_101 & V_157 ) == 0 )
return false ;
if ( F_94 ( V_4 -> V_2 ) ) {
T_1 V_158 = F_95 ( V_71 ) ;
T_1 V_159 = F_4 ( V_158 ) ;
if ( ( V_159 & V_160 ) != V_156 )
return false ;
} else {
if ( ( V_101 & V_161 ) != ( V_71 << 30 ) )
return false ;
}
return true ;
}
static bool F_96 ( struct V_3 * V_4 ,
enum V_71 V_71 , T_1 V_101 )
{
if ( ( V_101 & V_162 ) == 0 )
return false ;
if ( F_94 ( V_4 -> V_2 ) ) {
if ( ( V_101 & V_163 ) != F_97 ( V_71 ) )
return false ;
} else {
if ( ( V_101 & V_164 ) != F_98 ( V_71 ) )
return false ;
}
return true ;
}
static bool F_99 ( struct V_3 * V_4 ,
enum V_71 V_71 , T_1 V_101 )
{
if ( ( V_101 & V_165 ) == 0 )
return false ;
if ( F_94 ( V_4 -> V_2 ) ) {
if ( ( V_101 & V_166 ) != F_100 ( V_71 ) )
return false ;
} else {
if ( ( V_101 & V_167 ) != F_101 ( V_71 ) )
return false ;
}
return true ;
}
static bool F_102 ( struct V_3 * V_4 ,
enum V_71 V_71 , T_1 V_101 )
{
if ( ( V_101 & V_168 ) == 0 )
return false ;
if ( F_94 ( V_4 -> V_2 ) ) {
if ( ( V_101 & V_166 ) != F_100 ( V_71 ) )
return false ;
} else {
if ( ( V_101 & V_169 ) != F_103 ( V_71 ) )
return false ;
}
return true ;
}
static void F_104 ( struct V_3 * V_4 ,
enum V_71 V_71 , int V_79 , T_1 V_156 )
{
T_1 V_101 = F_4 ( V_79 ) ;
F_46 ( F_93 ( V_4 , V_71 , V_156 , V_101 ) ,
L_33 ,
V_79 , F_69 ( V_71 ) ) ;
F_46 ( F_48 ( V_4 -> V_2 ) && ( V_101 & V_157 ) == 0
&& ( V_101 & V_170 ) ,
L_34 ) ;
}
static void F_105 ( struct V_3 * V_4 ,
enum V_71 V_71 , int V_79 )
{
T_1 V_101 = F_4 ( V_79 ) ;
F_46 ( F_96 ( V_4 , V_71 , V_101 ) ,
L_35 ,
V_79 , F_69 ( V_71 ) ) ;
F_46 ( F_48 ( V_4 -> V_2 ) && ( V_101 & V_162 ) == 0
&& ( V_101 & V_171 ) ,
L_36 ) ;
}
static void F_106 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
int V_79 ;
T_1 V_101 ;
F_104 ( V_4 , V_71 , V_172 , V_173 ) ;
F_104 ( V_4 , V_71 , V_174 , V_175 ) ;
F_104 ( V_4 , V_71 , V_176 , V_177 ) ;
V_79 = V_178 ;
V_101 = F_4 ( V_79 ) ;
F_46 ( F_102 ( V_4 , V_71 , V_101 ) ,
L_37 ,
F_69 ( V_71 ) ) ;
V_79 = V_128 ;
V_101 = F_4 ( V_79 ) ;
F_46 ( F_99 ( V_4 , V_71 , V_101 ) ,
L_38 ,
F_69 ( V_71 ) ) ;
F_105 ( V_4 , V_71 , V_179 ) ;
F_105 ( V_4 , V_71 , V_180 ) ;
F_105 ( V_4 , V_71 , V_181 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_17 ( V_2 ) )
return;
F_40 ( V_182 , F_4 ( V_182 ) | V_183 ) ;
}
static void F_108 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_79 = F_51 ( V_21 -> V_71 ) ;
T_1 V_47 = V_21 -> V_67 . V_184 . V_47 ;
F_109 ( V_4 , V_21 -> V_71 ) ;
F_110 ( ! F_17 ( V_4 -> V_2 ) ) ;
if ( F_111 ( V_4 -> V_2 ) && ! F_112 ( V_4 -> V_2 ) )
F_68 ( V_4 , V_21 -> V_71 ) ;
F_40 ( V_79 , V_47 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
if ( F_34 ( ( ( F_4 ( V_79 ) & V_185 ) == V_185 ) , 1 ) )
F_115 ( L_39 , V_21 -> V_71 ) ;
F_40 ( F_116 ( V_21 -> V_71 ) , V_21 -> V_67 . V_184 . V_186 ) ;
F_113 ( F_116 ( V_21 -> V_71 ) ) ;
F_40 ( V_79 , V_47 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
F_40 ( V_79 , V_47 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
F_40 ( V_79 , V_47 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
}
static void F_117 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_79 = F_51 ( V_21 -> V_71 ) ;
T_1 V_47 = V_21 -> V_67 . V_184 . V_47 ;
F_109 ( V_4 , V_21 -> V_71 ) ;
F_110 ( V_4 -> V_119 -> V_77 >= 5 ) ;
if ( F_111 ( V_2 ) && ! F_112 ( V_2 ) )
F_68 ( V_4 , V_21 -> V_71 ) ;
F_40 ( V_79 , V_47 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
F_40 ( F_116 ( V_21 -> V_71 ) ,
V_21 -> V_67 . V_184 . V_186 ) ;
} else {
F_40 ( V_79 , V_47 ) ;
}
F_40 ( V_79 , V_47 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
F_40 ( V_79 , V_47 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
F_40 ( V_79 , V_47 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
}
static void F_118 ( struct V_3 * V_4 , enum V_71 V_71 )
{
if ( V_71 == V_125 && ( V_4 -> V_138 & V_139 ) )
return;
F_109 ( V_4 , V_71 ) ;
F_40 ( F_51 ( V_71 ) , 0 ) ;
F_113 ( F_51 ( V_71 ) ) ;
}
static void F_119 ( struct V_3 * V_4 , enum V_71 V_71 )
{
T_1 V_101 = 0 ;
F_109 ( V_4 , V_71 ) ;
if ( V_71 == V_134 )
V_101 = V_187 ;
F_40 ( F_51 ( V_71 ) , V_101 ) ;
F_113 ( F_51 ( V_71 ) ) ;
}
void F_120 ( struct V_3 * V_4 , int V_87 )
{
T_1 V_188 ;
if ( ! V_87 )
V_188 = V_189 ;
else
V_188 = V_190 ;
if ( F_34 ( ( F_4 ( F_51 ( 0 ) ) & V_188 ) == 0 , 1000 ) )
F_46 ( 1 , L_40 ,
'B' + V_87 , F_4 ( F_51 ( 0 ) ) ) ;
}
static void F_121 ( struct V_64 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_108 . V_2 -> V_5 ;
struct V_107 * V_111 = F_56 ( V_21 ) ;
F_110 ( V_4 -> V_119 -> V_77 < 5 ) ;
if ( F_2 ( V_111 == NULL ) )
return;
if ( F_2 ( V_111 -> V_191 == 0 ) )
return;
F_36 ( L_41 ,
V_111 -> V_115 , V_111 -> V_65 , V_111 -> V_192 ,
V_21 -> V_108 . V_108 . V_193 ) ;
if ( V_111 -> V_65 ++ ) {
F_2 ( ! V_111 -> V_192 ) ;
F_122 ( V_4 , V_111 ) ;
return;
}
F_2 ( V_111 -> V_192 ) ;
F_36 ( L_42 , V_111 -> V_115 ) ;
V_111 -> V_194 ( V_4 , V_111 ) ;
V_111 -> V_192 = true ;
}
static void F_123 ( struct V_64 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_108 . V_2 -> V_5 ;
struct V_107 * V_111 = F_56 ( V_21 ) ;
F_110 ( V_4 -> V_119 -> V_77 < 5 ) ;
if ( F_2 ( V_111 == NULL ) )
return;
if ( F_2 ( V_111 -> V_191 == 0 ) )
return;
F_36 ( L_43 ,
V_111 -> V_115 , V_111 -> V_65 , V_111 -> V_192 ,
V_21 -> V_108 . V_108 . V_193 ) ;
if ( F_2 ( V_111 -> V_65 == 0 ) ) {
F_124 ( V_4 , V_111 ) ;
return;
}
F_122 ( V_4 , V_111 ) ;
F_2 ( ! V_111 -> V_192 ) ;
if ( -- V_111 -> V_65 )
return;
F_36 ( L_44 , V_111 -> V_115 ) ;
V_111 -> V_195 ( V_4 , V_111 ) ;
V_111 -> V_192 = false ;
}
static void F_125 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_20 * V_21 = V_4 -> V_72 [ V_71 ] ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
T_4 V_79 , V_101 , V_196 ;
F_110 ( V_4 -> V_119 -> V_77 < 5 ) ;
F_122 ( V_4 ,
F_56 ( V_64 ) ) ;
F_126 ( V_4 , V_71 ) ;
F_127 ( V_4 , V_71 ) ;
if ( F_94 ( V_2 ) ) {
V_79 = F_128 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
V_101 |= V_197 ;
F_40 ( V_79 , V_101 ) ;
}
V_79 = F_92 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
V_196 = F_4 ( F_45 ( V_71 ) ) ;
if ( F_48 ( V_4 -> V_2 ) ) {
V_101 &= ~ V_198 ;
V_101 |= V_196 & V_198 ;
}
V_101 &= ~ V_199 ;
if ( ( V_196 & V_200 ) == V_201 )
if ( F_48 ( V_4 -> V_2 ) &&
F_9 ( V_21 , V_36 ) )
V_101 |= V_202 ;
else
V_101 |= V_203 ;
else
V_101 |= V_204 ;
F_40 ( V_79 , V_101 | V_155 ) ;
if ( F_34 ( F_4 ( V_79 ) & V_205 , 100 ) )
F_115 ( L_45 , F_69 ( V_71 ) ) ;
}
static void F_129 ( struct V_3 * V_4 ,
enum V_70 V_73 )
{
T_1 V_101 , V_196 ;
F_110 ( V_4 -> V_119 -> V_77 < 5 ) ;
F_126 ( V_4 , (enum V_71 ) V_73 ) ;
F_127 ( V_4 , V_206 ) ;
V_101 = F_4 ( V_207 ) ;
V_101 |= V_197 ;
F_40 ( V_207 , V_101 ) ;
V_101 = V_155 ;
V_196 = F_4 ( F_45 ( V_73 ) ) ;
if ( ( V_196 & V_208 ) ==
V_201 )
V_101 |= V_203 ;
else
V_101 |= V_204 ;
F_40 ( V_209 , V_101 ) ;
if ( F_34 ( F_4 ( V_209 ) & V_205 , 100 ) )
F_115 ( L_46 ) ;
}
static void F_130 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_79 , V_101 ;
F_131 ( V_4 , V_71 ) ;
F_132 ( V_4 , V_71 ) ;
F_106 ( V_4 , V_71 ) ;
V_79 = F_92 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
V_101 &= ~ V_155 ;
F_40 ( V_79 , V_101 ) ;
if ( F_34 ( ( F_4 ( V_79 ) & V_205 ) == 0 , 50 ) )
F_115 ( L_47 , F_69 ( V_71 ) ) ;
if ( ! F_48 ( V_2 ) ) {
V_79 = F_128 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
V_101 &= ~ V_197 ;
F_40 ( V_79 , V_101 ) ;
}
}
static void F_133 ( struct V_3 * V_4 )
{
T_1 V_101 ;
V_101 = F_4 ( V_209 ) ;
V_101 &= ~ V_155 ;
F_40 ( V_209 , V_101 ) ;
if ( F_34 ( ( F_4 ( V_209 ) & V_205 ) == 0 , 50 ) )
F_115 ( L_48 ) ;
V_101 = F_4 ( V_207 ) ;
V_101 &= ~ V_197 ;
F_40 ( V_207 , V_101 ) ;
}
static void F_134 ( struct V_3 * V_4 , enum V_71 V_71 ,
bool V_210 , bool V_211 )
{
enum V_70 V_73 = F_31 ( V_4 ,
V_71 ) ;
enum V_71 V_212 ;
int V_79 ;
T_1 V_101 ;
F_83 ( V_4 , V_71 ) ;
F_135 ( V_4 , V_71 ) ;
F_85 ( V_4 , V_71 ) ;
if ( F_58 ( V_4 -> V_2 ) )
V_212 = V_206 ;
else
V_212 = V_71 ;
if ( ! F_3 ( V_4 -> V_2 ) )
if ( V_211 )
F_136 ( V_4 ) ;
else
F_137 ( V_4 , V_71 ) ;
else {
if ( V_210 ) {
F_138 ( V_4 , V_212 ) ;
F_66 ( V_4 ,
(enum V_71 ) V_73 ) ;
}
}
V_79 = F_45 ( V_73 ) ;
V_101 = F_4 ( V_79 ) ;
if ( V_101 & V_140 )
return;
F_40 ( V_79 , V_101 | V_140 ) ;
F_37 ( V_4 -> V_2 , V_71 ) ;
}
static void F_139 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
enum V_70 V_73 = F_31 ( V_4 ,
V_71 ) ;
int V_79 ;
T_1 V_101 ;
F_83 ( V_4 , V_71 ) ;
F_135 ( V_4 , V_71 ) ;
F_85 ( V_4 , V_71 ) ;
if ( V_71 == V_125 && ( V_4 -> V_138 & V_139 ) )
return;
V_79 = F_45 ( V_73 ) ;
V_101 = F_4 ( V_79 ) ;
if ( ( V_101 & V_140 ) == 0 )
return;
F_40 ( V_79 , V_101 & ~ V_140 ) ;
F_44 ( V_4 -> V_2 , V_71 ) ;
}
void F_140 ( struct V_3 * V_4 ,
enum V_141 V_141 )
{
T_1 V_79 = V_4 -> V_119 -> V_77 >= 4 ? F_141 ( V_141 ) : F_142 ( V_141 ) ;
F_40 ( V_79 , F_4 ( V_79 ) ) ;
F_113 ( V_79 ) ;
}
static void F_143 ( struct V_3 * V_4 ,
enum V_141 V_141 , enum V_71 V_71 )
{
struct V_64 * V_64 =
F_30 ( V_4 -> V_72 [ V_71 ] ) ;
int V_79 ;
T_1 V_101 ;
F_144 ( V_4 , V_71 ) ;
F_46 ( V_64 -> V_213 , L_49 ) ;
V_64 -> V_213 = true ;
V_79 = F_81 ( V_141 ) ;
V_101 = F_4 ( V_79 ) ;
if ( V_101 & V_142 )
return;
F_40 ( V_79 , V_101 | V_142 ) ;
F_140 ( V_4 , V_141 ) ;
F_37 ( V_4 -> V_2 , V_71 ) ;
}
static void F_145 ( struct V_3 * V_4 ,
enum V_141 V_141 , enum V_71 V_71 )
{
struct V_64 * V_64 =
F_30 ( V_4 -> V_72 [ V_71 ] ) ;
int V_79 ;
T_1 V_101 ;
F_46 ( ! V_64 -> V_213 , L_50 ) ;
V_64 -> V_213 = false ;
V_79 = F_81 ( V_141 ) ;
V_101 = F_4 ( V_79 ) ;
if ( ( V_101 & V_142 ) == 0 )
return;
F_40 ( V_79 , V_101 & ~ V_142 ) ;
F_140 ( V_4 , V_141 ) ;
F_37 ( V_4 -> V_2 , V_71 ) ;
}
static bool F_146 ( struct V_1 * V_2 )
{
#ifdef F_147
if ( F_39 ( V_2 ) -> V_77 >= 6 && V_214 )
return true ;
#endif
return false ;
}
int
F_148 ( struct V_1 * V_2 ,
struct V_215 * V_216 ,
struct V_217 * V_218 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_219 ;
int V_220 ;
switch ( V_216 -> V_221 ) {
case V_222 :
if ( F_149 ( V_2 ) || F_150 ( V_2 ) )
V_219 = 128 * 1024 ;
else if ( F_39 ( V_2 ) -> V_77 >= 4 )
V_219 = 4 * 1024 ;
else
V_219 = 64 * 1024 ;
break;
case V_223 :
V_219 = 0 ;
break;
case V_224 :
F_46 ( 1 , L_51 ) ;
return - V_225 ;
default:
F_151 () ;
}
if ( F_146 ( V_2 ) && V_219 < 256 * 1024 )
V_219 = 256 * 1024 ;
V_4 -> V_226 . V_227 = false ;
V_220 = F_152 ( V_216 , V_219 , V_218 ) ;
if ( V_220 )
goto V_228;
V_220 = F_153 ( V_216 ) ;
if ( V_220 )
goto V_229;
F_154 ( V_216 ) ;
V_4 -> V_226 . V_227 = true ;
return 0 ;
V_229:
F_155 ( V_216 ) ;
V_228:
V_4 -> V_226 . V_227 = true ;
return V_220 ;
}
void F_156 ( struct V_215 * V_216 )
{
F_157 ( V_216 ) ;
F_155 ( V_216 ) ;
}
unsigned long F_158 ( int * V_230 , int * V_231 ,
unsigned int V_221 ,
unsigned int V_232 ,
unsigned int V_233 )
{
if ( V_221 != V_222 ) {
unsigned int V_234 , V_235 ;
V_234 = * V_231 / 8 ;
* V_231 %= 8 ;
V_235 = * V_230 / ( 512 / V_232 ) ;
* V_230 %= 512 / V_232 ;
return V_234 * V_233 * 8 + V_235 * 4096 ;
} else {
unsigned int V_236 ;
V_236 = * V_231 * V_233 + * V_230 * V_232 ;
* V_231 = 0 ;
* V_230 = ( V_236 & 4095 ) / V_232 ;
return V_236 & - 4096 ;
}
}
static int F_159 ( struct V_20 * V_21 , struct V_237 * V_66 ,
int V_230 , int V_231 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_238 * V_239 ;
struct V_215 * V_216 ;
int V_141 = V_64 -> V_141 ;
unsigned long V_240 ;
T_1 V_241 ;
T_1 V_79 ;
switch ( V_141 ) {
case 0 :
case 1 :
break;
default:
F_115 ( L_52 , F_82 ( V_141 ) ) ;
return - V_225 ;
}
V_239 = F_160 ( V_66 ) ;
V_216 = V_239 -> V_216 ;
V_79 = F_81 ( V_141 ) ;
V_241 = F_4 ( V_79 ) ;
V_241 &= ~ V_242 ;
switch ( V_66 -> V_243 ) {
case V_244 :
V_241 |= V_245 ;
break;
case V_246 :
case V_247 :
V_241 |= V_248 ;
break;
case V_249 :
V_241 |= V_250 ;
break;
case V_251 :
case V_252 :
V_241 |= V_253 ;
break;
case V_254 :
case V_255 :
V_241 |= V_256 ;
break;
case V_257 :
case V_258 :
V_241 |= V_259 ;
break;
case V_260 :
case V_261 :
V_241 |= V_262 ;
break;
default:
F_151 () ;
}
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
if ( V_216 -> V_221 != V_222 )
V_241 |= V_263 ;
else
V_241 &= ~ V_263 ;
}
if ( F_15 ( V_2 ) )
V_241 |= V_264 ;
F_40 ( V_79 , V_241 ) ;
V_240 = V_231 * V_66 -> V_265 [ 0 ] + V_230 * ( V_66 -> V_266 / 8 ) ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
V_64 -> V_267 =
F_158 ( & V_230 , & V_231 , V_216 -> V_221 ,
V_66 -> V_266 / 8 ,
V_66 -> V_265 [ 0 ] ) ;
V_240 -= V_64 -> V_267 ;
} else {
V_64 -> V_267 = V_240 ;
}
F_36 ( L_53 ,
F_161 ( V_216 ) , V_240 , V_230 , V_231 ,
V_66 -> V_265 [ 0 ] ) ;
F_40 ( F_162 ( V_141 ) , V_66 -> V_265 [ 0 ] ) ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
F_163 ( F_141 ( V_141 ) ,
F_161 ( V_216 ) + V_64 -> V_267 ) ;
F_40 ( F_164 ( V_141 ) , ( V_231 << 16 ) | V_230 ) ;
F_40 ( F_165 ( V_141 ) , V_240 ) ;
} else
F_40 ( F_142 ( V_141 ) , F_161 ( V_216 ) + V_240 ) ;
F_113 ( V_79 ) ;
return 0 ;
}
static int F_166 ( struct V_20 * V_21 ,
struct V_237 * V_66 , int V_230 , int V_231 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_238 * V_239 ;
struct V_215 * V_216 ;
int V_141 = V_64 -> V_141 ;
unsigned long V_240 ;
T_1 V_241 ;
T_1 V_79 ;
switch ( V_141 ) {
case 0 :
case 1 :
case 2 :
break;
default:
F_115 ( L_52 , F_82 ( V_141 ) ) ;
return - V_225 ;
}
V_239 = F_160 ( V_66 ) ;
V_216 = V_239 -> V_216 ;
V_79 = F_81 ( V_141 ) ;
V_241 = F_4 ( V_79 ) ;
V_241 &= ~ V_242 ;
switch ( V_66 -> V_243 ) {
case V_244 :
V_241 |= V_245 ;
break;
case V_249 :
V_241 |= V_250 ;
break;
case V_251 :
case V_252 :
V_241 |= V_253 ;
break;
case V_254 :
case V_255 :
V_241 |= V_256 ;
break;
case V_257 :
case V_258 :
V_241 |= V_259 ;
break;
case V_260 :
case V_261 :
V_241 |= V_262 ;
break;
default:
F_151 () ;
}
if ( V_216 -> V_221 != V_222 )
V_241 |= V_263 ;
else
V_241 &= ~ V_263 ;
if ( F_72 ( V_2 ) || F_167 ( V_2 ) )
V_241 &= ~ V_264 ;
else
V_241 |= V_264 ;
F_40 ( V_79 , V_241 ) ;
V_240 = V_231 * V_66 -> V_265 [ 0 ] + V_230 * ( V_66 -> V_266 / 8 ) ;
V_64 -> V_267 =
F_158 ( & V_230 , & V_231 , V_216 -> V_221 ,
V_66 -> V_266 / 8 ,
V_66 -> V_265 [ 0 ] ) ;
V_240 -= V_64 -> V_267 ;
F_36 ( L_53 ,
F_161 ( V_216 ) , V_240 , V_230 , V_231 ,
V_66 -> V_265 [ 0 ] ) ;
F_40 ( F_162 ( V_141 ) , V_66 -> V_265 [ 0 ] ) ;
F_163 ( F_141 ( V_141 ) ,
F_161 ( V_216 ) + V_64 -> V_267 ) ;
if ( F_72 ( V_2 ) || F_167 ( V_2 ) ) {
F_40 ( F_168 ( V_141 ) , ( V_231 << 16 ) | V_230 ) ;
} else {
F_40 ( F_164 ( V_141 ) , ( V_231 << 16 ) | V_230 ) ;
F_40 ( F_165 ( V_141 ) , V_240 ) ;
}
F_113 ( V_79 ) ;
return 0 ;
}
static int
F_169 ( struct V_20 * V_21 , struct V_237 * V_66 ,
int V_230 , int V_231 , enum V_268 V_100 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_269 . V_270 )
V_4 -> V_269 . V_270 ( V_2 ) ;
F_170 ( V_21 ) ;
return V_4 -> V_269 . V_271 ( V_21 , V_66 , V_230 , V_231 ) ;
}
void F_171 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 ;
F_172 (crtc, &dev->mode_config.crtc_list, head) {
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_141 V_141 = V_64 -> V_141 ;
F_173 ( V_2 , V_141 ) ;
F_174 ( V_2 , V_141 ) ;
}
F_172 (crtc, &dev->mode_config.crtc_list, head) {
struct V_64 * V_64 = F_30 ( V_21 ) ;
F_53 ( & V_21 -> V_272 ) ;
if ( V_64 -> V_65 )
V_4 -> V_269 . V_271 ( V_21 , V_21 -> V_66 ,
V_21 -> V_230 , V_21 -> V_231 ) ;
F_55 ( & V_21 -> V_272 ) ;
}
}
static int
F_175 ( struct V_237 * V_273 )
{
struct V_215 * V_216 = F_160 ( V_273 ) -> V_216 ;
struct V_3 * V_4 = V_216 -> V_108 . V_2 -> V_5 ;
bool V_274 = V_4 -> V_226 . V_227 ;
int V_220 ;
V_4 -> V_226 . V_227 = false ;
V_220 = F_176 ( V_216 ) ;
V_4 -> V_226 . V_227 = V_274 ;
return V_220 ;
}
static void F_177 ( struct V_20 * V_21 , int V_230 , int V_231 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_275 * V_276 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
if ( ! V_2 -> V_277 -> V_278 )
return;
V_276 = V_2 -> V_277 -> V_278 -> V_279 ;
if ( ! V_276 -> V_280 )
return;
switch ( V_64 -> V_71 ) {
case 0 :
V_276 -> V_280 -> V_281 = V_230 ;
V_276 -> V_280 -> V_282 = V_231 ;
break;
case 1 :
V_276 -> V_280 -> V_283 = V_230 ;
V_276 -> V_280 -> V_284 = V_231 ;
break;
default:
break;
}
}
static int
F_178 ( struct V_20 * V_21 , int V_230 , int V_231 ,
struct V_237 * V_66 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_237 * V_273 ;
int V_220 ;
if ( ! V_66 ) {
F_115 ( L_54 ) ;
return 0 ;
}
if ( V_64 -> V_141 > F_39 ( V_2 ) -> V_285 ) {
F_115 ( L_55 ,
F_82 ( V_64 -> V_141 ) ,
F_39 ( V_2 ) -> V_285 ) ;
return - V_225 ;
}
F_53 ( & V_2 -> V_286 ) ;
V_220 = F_148 ( V_2 ,
F_160 ( V_66 ) -> V_216 ,
NULL ) ;
if ( V_220 != 0 ) {
F_55 ( & V_2 -> V_286 ) ;
F_115 ( L_56 ) ;
return V_220 ;
}
if ( V_287 ) {
const struct V_288 * V_68 =
& V_64 -> V_67 . V_68 ;
F_40 ( F_179 ( V_64 -> V_71 ) ,
( ( V_68 -> V_289 - 1 ) << 16 ) |
( V_68 -> V_290 - 1 ) ) ;
if ( ! V_64 -> V_67 . V_291 . V_99 &&
( F_9 ( V_21 , V_25 ) ||
F_9 ( V_21 , V_292 ) ) ) {
F_40 ( F_180 ( V_64 -> V_71 ) , 0 ) ;
F_40 ( F_181 ( V_64 -> V_71 ) , 0 ) ;
F_40 ( F_182 ( V_64 -> V_71 ) , 0 ) ;
}
}
V_220 = V_4 -> V_269 . V_271 ( V_21 , V_66 , V_230 , V_231 ) ;
if ( V_220 ) {
F_156 ( F_160 ( V_66 ) -> V_216 ) ;
F_55 ( & V_2 -> V_286 ) ;
F_115 ( L_57 ) ;
return V_220 ;
}
V_273 = V_21 -> V_66 ;
V_21 -> V_66 = V_66 ;
V_21 -> V_230 = V_230 ;
V_21 -> V_231 = V_231 ;
if ( V_273 ) {
if ( V_64 -> V_65 && V_273 != V_66 )
F_37 ( V_2 , V_64 -> V_71 ) ;
F_156 ( F_160 ( V_273 ) -> V_216 ) ;
}
F_183 ( V_2 ) ;
F_184 ( V_2 ) ;
F_55 ( & V_2 -> V_286 ) ;
F_177 ( V_21 , V_230 , V_231 ) ;
return 0 ;
}
static void F_185 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
T_1 V_79 , V_293 ;
V_79 = F_63 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
if ( F_71 ( V_2 ) ) {
V_293 &= ~ V_294 ;
V_293 |= V_294 | V_295 ;
} else {
V_293 &= ~ V_296 ;
V_293 |= V_296 | V_295 ;
}
F_40 ( V_79 , V_293 ) ;
V_79 = F_65 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
if ( F_94 ( V_2 ) ) {
V_293 &= ~ V_297 ;
V_293 |= V_298 ;
} else {
V_293 &= ~ V_296 ;
V_293 |= V_296 ;
}
F_40 ( V_79 , V_293 | V_299 ) ;
F_113 ( V_79 ) ;
F_114 ( 1000 ) ;
if ( F_71 ( V_2 ) )
F_40 ( V_79 , F_4 ( V_79 ) | V_300 |
V_301 ) ;
}
static bool F_186 ( struct V_64 * V_21 )
{
return V_21 -> V_108 . V_99 && V_21 -> V_65 &&
V_21 -> V_67 . V_302 ;
}
static void F_187 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_303 =
F_30 ( V_4 -> V_72 [ V_134 ] ) ;
struct V_64 * V_304 =
F_30 ( V_4 -> V_72 [ V_305 ] ) ;
T_4 V_293 ;
if ( ! F_186 ( V_303 ) &&
! F_186 ( V_304 ) ) {
F_2 ( F_4 ( F_65 ( V_134 ) ) & V_118 ) ;
F_2 ( F_4 ( F_65 ( V_305 ) ) & V_118 ) ;
V_293 = F_4 ( V_306 ) ;
V_293 &= ~ V_307 ;
F_36 ( L_58 ) ;
F_40 ( V_306 , V_293 ) ;
}
}
static void F_188 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
T_1 V_79 , V_293 , V_308 ;
F_144 ( V_4 , V_71 ) ;
F_189 ( V_4 , V_141 ) ;
V_79 = F_190 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_309 ;
V_293 &= ~ V_310 ;
F_40 ( V_79 , V_293 ) ;
F_4 ( V_79 ) ;
F_114 ( 150 ) ;
V_79 = F_63 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_311 ;
V_293 |= F_191 ( V_64 -> V_67 . V_312 ) ;
V_293 &= ~ V_296 ;
V_293 |= V_313 ;
F_40 ( V_79 , V_293 | V_117 ) ;
V_79 = F_65 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_296 ;
V_293 |= V_313 ;
F_40 ( V_79 , V_293 | V_118 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
F_40 ( F_192 ( V_71 ) , V_314 ) ;
F_40 ( F_192 ( V_71 ) , V_314 |
V_315 ) ;
V_79 = F_193 ( V_71 ) ;
for ( V_308 = 0 ; V_308 < 5 ; V_308 ++ ) {
V_293 = F_4 ( V_79 ) ;
F_36 ( L_59 , V_293 ) ;
if ( ( V_293 & V_310 ) ) {
F_36 ( L_60 ) ;
F_40 ( V_79 , V_293 | V_310 ) ;
break;
}
}
if ( V_308 == 5 )
F_115 ( L_61 ) ;
V_79 = F_63 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_296 ;
V_293 |= V_316 ;
F_40 ( V_79 , V_293 ) ;
V_79 = F_65 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_296 ;
V_293 |= V_316 ;
F_40 ( V_79 , V_293 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
V_79 = F_193 ( V_71 ) ;
for ( V_308 = 0 ; V_308 < 5 ; V_308 ++ ) {
V_293 = F_4 ( V_79 ) ;
F_36 ( L_59 , V_293 ) ;
if ( V_293 & V_309 ) {
F_40 ( V_79 , V_293 | V_309 ) ;
F_36 ( L_62 ) ;
break;
}
}
if ( V_308 == 5 )
F_115 ( L_63 ) ;
F_36 ( L_64 ) ;
}
static void F_194 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
T_1 V_79 , V_293 , V_143 , V_317 ;
V_79 = F_190 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_309 ;
V_293 &= ~ V_310 ;
F_40 ( V_79 , V_293 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
V_79 = F_63 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_311 ;
V_293 |= F_191 ( V_64 -> V_67 . V_312 ) ;
V_293 &= ~ V_296 ;
V_293 |= V_313 ;
V_293 &= ~ V_318 ;
V_293 |= V_319 ;
F_40 ( V_79 , V_293 | V_117 ) ;
F_40 ( F_195 ( V_71 ) ,
V_320 | V_321 ) ;
V_79 = F_65 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
if ( F_94 ( V_2 ) ) {
V_293 &= ~ V_297 ;
V_293 |= V_322 ;
} else {
V_293 &= ~ V_296 ;
V_293 |= V_313 ;
}
F_40 ( V_79 , V_293 | V_118 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
for ( V_143 = 0 ; V_143 < 4 ; V_143 ++ ) {
V_79 = F_63 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_318 ;
V_293 |= V_323 [ V_143 ] ;
F_40 ( V_79 , V_293 ) ;
F_113 ( V_79 ) ;
F_114 ( 500 ) ;
for ( V_317 = 0 ; V_317 < 5 ; V_317 ++ ) {
V_79 = F_193 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
F_36 ( L_59 , V_293 ) ;
if ( V_293 & V_310 ) {
F_40 ( V_79 , V_293 | V_310 ) ;
F_36 ( L_60 ) ;
break;
}
F_114 ( 50 ) ;
}
if ( V_317 < 5 )
break;
}
if ( V_143 == 4 )
F_115 ( L_61 ) ;
V_79 = F_63 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_296 ;
V_293 |= V_316 ;
if ( F_196 ( V_2 ) ) {
V_293 &= ~ V_318 ;
V_293 |= V_319 ;
}
F_40 ( V_79 , V_293 ) ;
V_79 = F_65 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
if ( F_94 ( V_2 ) ) {
V_293 &= ~ V_297 ;
V_293 |= V_324 ;
} else {
V_293 &= ~ V_296 ;
V_293 |= V_316 ;
}
F_40 ( V_79 , V_293 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
for ( V_143 = 0 ; V_143 < 4 ; V_143 ++ ) {
V_79 = F_63 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_318 ;
V_293 |= V_323 [ V_143 ] ;
F_40 ( V_79 , V_293 ) ;
F_113 ( V_79 ) ;
F_114 ( 500 ) ;
for ( V_317 = 0 ; V_317 < 5 ; V_317 ++ ) {
V_79 = F_193 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
F_36 ( L_59 , V_293 ) ;
if ( V_293 & V_309 ) {
F_40 ( V_79 , V_293 | V_309 ) ;
F_36 ( L_62 ) ;
break;
}
F_114 ( 50 ) ;
}
if ( V_317 < 5 )
break;
}
if ( V_143 == 4 )
F_115 ( L_63 ) ;
F_36 ( L_65 ) ;
}
static void F_197 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
T_1 V_79 , V_293 , V_143 , V_325 ;
V_79 = F_190 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_309 ;
V_293 &= ~ V_310 ;
F_40 ( V_79 , V_293 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
F_36 ( L_66 ,
F_4 ( F_193 ( V_71 ) ) ) ;
for ( V_325 = 0 ; V_325 < F_198 ( V_323 ) * 2 ; V_325 ++ ) {
V_79 = F_63 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ ( V_326 | V_294 ) ;
V_293 &= ~ V_117 ;
F_40 ( V_79 , V_293 ) ;
V_79 = F_65 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_326 ;
V_293 &= ~ V_297 ;
V_293 &= ~ V_118 ;
F_40 ( V_79 , V_293 ) ;
V_79 = F_63 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_311 ;
V_293 |= F_191 ( V_64 -> V_67 . V_312 ) ;
V_293 |= V_327 ;
V_293 &= ~ V_318 ;
V_293 |= V_323 [ V_325 / 2 ] ;
V_293 |= V_328 ;
F_40 ( V_79 , V_293 | V_117 ) ;
F_40 ( F_195 ( V_71 ) ,
V_320 | V_321 ) ;
V_79 = F_65 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 |= V_322 ;
V_293 |= V_328 ;
F_40 ( V_79 , V_293 | V_118 ) ;
F_113 ( V_79 ) ;
F_114 ( 1 ) ;
for ( V_143 = 0 ; V_143 < 4 ; V_143 ++ ) {
V_79 = F_193 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
F_36 ( L_59 , V_293 ) ;
if ( V_293 & V_310 ||
( F_4 ( V_79 ) & V_310 ) ) {
F_40 ( V_79 , V_293 | V_310 ) ;
F_36 ( L_67 ,
V_143 ) ;
break;
}
F_114 ( 1 ) ;
}
if ( V_143 == 4 ) {
F_36 ( L_68 , V_325 / 2 ) ;
continue;
}
V_79 = F_63 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_294 ;
V_293 |= V_329 ;
F_40 ( V_79 , V_293 ) ;
V_79 = F_65 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_297 ;
V_293 |= V_324 ;
F_40 ( V_79 , V_293 ) ;
F_113 ( V_79 ) ;
F_114 ( 2 ) ;
for ( V_143 = 0 ; V_143 < 4 ; V_143 ++ ) {
V_79 = F_193 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
F_36 ( L_59 , V_293 ) ;
if ( V_293 & V_309 ||
( F_4 ( V_79 ) & V_309 ) ) {
F_40 ( V_79 , V_293 | V_309 ) ;
F_36 ( L_69 ,
V_143 ) ;
goto V_330;
}
F_114 ( 2 ) ;
}
if ( V_143 == 4 )
F_36 ( L_70 , V_325 / 2 ) ;
}
V_330:
F_36 ( L_65 ) ;
}
static void F_199 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_64 -> V_71 ;
T_1 V_79 , V_293 ;
V_79 = F_65 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ ( V_311 | ( 0x7 << 16 ) ) ;
V_293 |= F_191 ( V_64 -> V_67 . V_312 ) ;
V_293 |= ( F_4 ( F_45 ( V_71 ) ) & V_198 ) << 11 ;
F_40 ( V_79 , V_293 | V_121 ) ;
F_113 ( V_79 ) ;
F_114 ( 200 ) ;
V_293 = F_4 ( V_79 ) ;
F_40 ( V_79 , V_293 | V_331 ) ;
F_113 ( V_79 ) ;
F_114 ( 200 ) ;
V_79 = F_63 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
if ( ( V_293 & V_120 ) == 0 ) {
F_40 ( V_79 , V_293 | V_120 ) ;
F_113 ( V_79 ) ;
F_114 ( 100 ) ;
}
}
static void F_200 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_64 -> V_71 ;
T_1 V_79 , V_293 ;
V_79 = F_65 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
F_40 ( V_79 , V_293 & ~ V_331 ) ;
V_79 = F_63 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
F_40 ( V_79 , V_293 & ~ V_120 ) ;
F_113 ( V_79 ) ;
F_114 ( 100 ) ;
V_79 = F_65 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
F_40 ( V_79 , V_293 & ~ V_121 ) ;
F_113 ( V_79 ) ;
F_114 ( 100 ) ;
}
static void F_201 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
T_1 V_79 , V_293 ;
V_79 = F_63 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
F_40 ( V_79 , V_293 & ~ V_117 ) ;
F_113 ( V_79 ) ;
V_79 = F_65 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ ( 0x7 << 16 ) ;
V_293 |= ( F_4 ( F_45 ( V_71 ) ) & V_198 ) << 11 ;
F_40 ( V_79 , V_293 & ~ V_118 ) ;
F_113 ( V_79 ) ;
F_114 ( 100 ) ;
if ( F_48 ( V_2 ) ) {
F_40 ( F_192 ( V_71 ) , V_314 ) ;
}
V_79 = F_63 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ V_296 ;
V_293 |= V_313 ;
F_40 ( V_79 , V_293 ) ;
V_79 = F_65 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
if ( F_94 ( V_2 ) ) {
V_293 &= ~ V_297 ;
V_293 |= V_322 ;
} else {
V_293 &= ~ V_296 ;
V_293 |= V_313 ;
}
V_293 &= ~ ( 0x07 << 16 ) ;
V_293 |= ( F_4 ( F_45 ( V_71 ) ) & V_198 ) << 11 ;
F_40 ( V_79 , V_293 ) ;
F_113 ( V_79 ) ;
F_114 ( 100 ) ;
}
static bool F_202 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
unsigned long V_332 ;
bool V_333 ;
if ( F_203 ( & V_4 -> V_334 ) ||
V_64 -> V_335 != F_204 ( & V_4 -> V_334 . V_335 ) )
return false ;
F_205 ( & V_2 -> V_336 , V_332 ) ;
V_333 = F_30 ( V_21 ) -> V_337 != NULL ;
F_206 ( & V_2 -> V_336 , V_332 ) ;
return V_333 ;
}
static void F_207 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_21 -> V_66 == NULL )
return;
F_2 ( F_208 ( & V_4 -> V_338 ) ) ;
F_209 ( V_4 -> V_338 ,
! F_202 ( V_21 ) ) ;
F_53 ( & V_2 -> V_286 ) ;
F_175 ( V_21 -> V_66 ) ;
F_55 ( & V_2 -> V_286 ) ;
}
static void F_210 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int clock = F_30 ( V_21 ) -> V_67 . V_68 . V_69 ;
T_1 V_339 , V_340 , V_341 , V_342 = 0 ;
T_1 V_293 ;
F_53 ( & V_4 -> V_104 ) ;
F_40 ( V_343 , V_344 ) ;
F_211 ( V_4 , V_345 ,
F_212 ( V_4 , V_345 , V_346 ) |
V_347 ,
V_346 ) ;
if ( clock == 20000 ) {
V_341 = 1 ;
V_339 = 0x41 ;
V_340 = 0x20 ;
} else {
T_1 V_348 = 172800 * 1000 ;
T_1 V_349 = 64 ;
T_1 V_350 , V_351 , V_352 ;
V_350 = ( V_348 / clock ) ;
V_351 = V_350 / V_349 ;
V_352 = V_350 % V_349 ;
V_341 = 0 ;
V_339 = V_351 - 2 ;
V_340 = V_352 ;
}
F_2 ( F_213 ( V_339 ) &
~ V_353 ) ;
F_2 ( F_214 ( V_342 ) &
~ V_354 ) ;
F_36 ( L_71 ,
clock ,
V_341 ,
V_339 ,
V_342 ,
V_340 ) ;
V_293 = F_212 ( V_4 , V_355 , V_346 ) ;
V_293 &= ~ V_353 ;
V_293 |= F_213 ( V_339 ) ;
V_293 &= ~ V_354 ;
V_293 |= F_215 ( V_340 ) ;
V_293 |= F_214 ( V_342 ) ;
V_293 |= V_356 ;
F_211 ( V_4 , V_355 , V_293 , V_346 ) ;
V_293 = F_212 ( V_4 , V_357 , V_346 ) ;
V_293 &= ~ F_216 ( 1 ) ;
V_293 |= F_216 ( V_341 ) ;
F_211 ( V_4 , V_357 , V_293 , V_346 ) ;
V_293 = F_212 ( V_4 , V_345 , V_346 ) ;
V_293 &= ~ V_347 ;
F_211 ( V_4 , V_345 , V_293 , V_346 ) ;
F_114 ( 24 ) ;
F_40 ( V_343 , V_358 ) ;
F_55 ( & V_4 -> V_104 ) ;
}
static void F_217 ( struct V_64 * V_21 ,
enum V_71 V_212 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_70 V_73 = V_21 -> V_67 . V_73 ;
F_40 ( F_218 ( V_212 ) ,
F_4 ( F_219 ( V_73 ) ) ) ;
F_40 ( F_220 ( V_212 ) ,
F_4 ( F_221 ( V_73 ) ) ) ;
F_40 ( F_222 ( V_212 ) ,
F_4 ( F_223 ( V_73 ) ) ) ;
F_40 ( F_224 ( V_212 ) ,
F_4 ( F_225 ( V_73 ) ) ) ;
F_40 ( F_226 ( V_212 ) ,
F_4 ( F_227 ( V_73 ) ) ) ;
F_40 ( F_228 ( V_212 ) ,
F_4 ( F_229 ( V_73 ) ) ) ;
F_40 ( F_230 ( V_212 ) ,
F_4 ( F_231 ( V_73 ) ) ) ;
}
static void F_232 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_293 ;
V_293 = F_4 ( V_306 ) ;
if ( V_293 & V_307 )
return;
F_2 ( F_4 ( F_65 ( V_134 ) ) & V_118 ) ;
F_2 ( F_4 ( F_65 ( V_305 ) ) & V_118 ) ;
V_293 |= V_307 ;
F_36 ( L_72 ) ;
F_40 ( V_306 , V_293 ) ;
F_113 ( V_306 ) ;
}
static void F_233 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_64 -> V_71 ) {
case V_125 :
break;
case V_134 :
if ( V_64 -> V_67 . V_312 > 2 )
F_2 ( F_4 ( V_306 ) & V_307 ) ;
else
F_232 ( V_2 ) ;
break;
case V_305 :
F_232 ( V_2 ) ;
break;
default:
F_151 () ;
}
}
static void F_234 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
T_1 V_79 , V_293 ;
F_91 ( V_4 , V_71 ) ;
if ( F_71 ( V_2 ) )
F_233 ( V_64 ) ;
F_40 ( F_235 ( V_71 ) ,
F_4 ( F_236 ( V_71 ) ) & V_359 ) ;
V_4 -> V_269 . V_360 ( V_21 ) ;
if ( F_94 ( V_2 ) ) {
T_1 V_361 ;
V_293 = F_4 ( V_362 ) ;
V_293 |= F_237 ( V_71 ) ;
V_361 = F_238 ( V_71 ) ;
if ( V_64 -> V_67 . V_109 == V_363 )
V_293 |= V_361 ;
else
V_293 &= ~ V_361 ;
F_40 ( V_362 , V_293 ) ;
}
F_121 ( V_64 ) ;
F_68 ( V_4 , V_71 ) ;
F_217 ( V_64 , V_71 ) ;
F_185 ( V_21 ) ;
if ( F_94 ( V_2 ) &&
( F_9 ( V_21 , V_364 ) ||
F_9 ( V_21 , V_292 ) ) ) {
T_1 V_365 = ( F_4 ( F_45 ( V_71 ) ) & V_198 ) >> 5 ;
V_79 = F_95 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ ( V_160 |
V_366 |
V_367 ) ;
V_293 |= ( V_368 |
V_369 ) ;
V_293 |= V_365 << 9 ;
if ( V_21 -> V_370 . V_332 & V_371 )
V_293 |= V_372 ;
if ( V_21 -> V_370 . V_332 & V_373 )
V_293 |= V_374 ;
switch ( F_239 ( V_21 ) ) {
case V_172 :
V_293 |= V_173 ;
break;
case V_174 :
V_293 |= V_175 ;
break;
case V_176 :
V_293 |= V_177 ;
break;
default:
F_151 () ;
}
F_40 ( V_79 , V_293 ) ;
}
F_125 ( V_4 , V_71 ) ;
}
static void F_240 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_70 V_73 = V_64 -> V_67 . V_73 ;
F_91 ( V_4 , V_206 ) ;
F_210 ( V_21 ) ;
F_217 ( V_64 , V_125 ) ;
F_129 ( V_4 , V_73 ) ;
}
static void F_241 ( struct V_64 * V_21 )
{
struct V_107 * V_111 = F_56 ( V_21 ) ;
if ( V_111 == NULL )
return;
if ( V_111 -> V_191 == 0 ) {
F_46 ( 1 , L_73 , V_111 -> V_115 ) ;
return;
}
if ( -- V_111 -> V_191 == 0 ) {
F_2 ( V_111 -> V_192 ) ;
F_2 ( V_111 -> V_65 ) ;
}
V_21 -> V_67 . V_109 = V_375 ;
}
static struct V_107 * F_242 ( struct V_64 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_108 . V_2 -> V_5 ;
struct V_107 * V_111 = F_56 ( V_21 ) ;
enum V_376 V_143 ;
if ( V_111 ) {
F_36 ( L_74 ,
V_21 -> V_108 . V_108 . V_193 , V_111 -> V_115 ) ;
F_241 ( V_21 ) ;
}
if ( F_48 ( V_4 -> V_2 ) ) {
V_143 = (enum V_376 ) V_21 -> V_71 ;
V_111 = & V_4 -> V_110 [ V_143 ] ;
F_36 ( L_75 ,
V_21 -> V_108 . V_108 . V_193 , V_111 -> V_115 ) ;
goto V_59;
}
for ( V_143 = 0 ; V_143 < V_4 -> V_377 ; V_143 ++ ) {
V_111 = & V_4 -> V_110 [ V_143 ] ;
if ( V_111 -> V_191 == 0 )
continue;
if ( memcmp ( & V_21 -> V_67 . V_184 , & V_111 -> V_113 ,
sizeof( V_111 -> V_113 ) ) == 0 ) {
F_36 ( L_76 ,
V_21 -> V_108 . V_108 . V_193 ,
V_111 -> V_115 , V_111 -> V_191 , V_111 -> V_65 ) ;
goto V_59;
}
}
for ( V_143 = 0 ; V_143 < V_4 -> V_377 ; V_143 ++ ) {
V_111 = & V_4 -> V_110 [ V_143 ] ;
if ( V_111 -> V_191 == 0 ) {
F_36 ( L_77 ,
V_21 -> V_108 . V_108 . V_193 , V_111 -> V_115 ) ;
goto V_59;
}
}
return NULL ;
V_59:
V_21 -> V_67 . V_109 = V_143 ;
F_59 ( L_78 , V_111 -> V_115 ,
F_69 ( V_21 -> V_71 ) ) ;
if ( V_111 -> V_65 == 0 ) {
memcpy ( & V_111 -> V_113 , & V_21 -> V_67 . V_184 ,
sizeof( V_111 -> V_113 ) ) ;
F_59 ( L_79 , V_111 -> V_115 ) ;
F_2 ( V_111 -> V_192 ) ;
F_124 ( V_4 , V_111 ) ;
V_111 -> V_378 ( V_4 , V_111 ) ;
}
V_111 -> V_191 ++ ;
return V_111 ;
}
static void F_243 ( struct V_1 * V_2 , int V_71 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_379 = F_42 ( V_71 ) ;
T_1 V_293 ;
V_293 = F_4 ( V_379 ) ;
F_114 ( 500 ) ;
if ( F_34 ( F_4 ( V_379 ) != V_293 , 5 ) ) {
if ( F_34 ( F_4 ( V_379 ) != V_293 , 5 ) )
F_115 ( L_80 , F_69 ( V_71 ) ) ;
}
}
static void F_244 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_21 -> V_71 ;
if ( V_21 -> V_67 . V_291 . V_99 ) {
if ( F_71 ( V_2 ) || F_72 ( V_2 ) )
F_40 ( F_180 ( V_71 ) , V_380 | V_381 |
F_245 ( V_71 ) ) ;
else
F_40 ( F_180 ( V_71 ) , V_380 | V_381 ) ;
F_40 ( F_181 ( V_71 ) , V_21 -> V_67 . V_291 . V_382 ) ;
F_40 ( F_182 ( V_71 ) , V_21 -> V_67 . V_291 . V_383 ) ;
}
}
static void F_246 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
enum V_71 V_71 = F_30 ( V_21 ) -> V_71 ;
struct V_384 * V_384 ;
F_172 (intel_plane, &dev->mode_config.plane_list, base.head)
if ( V_384 -> V_71 == V_71 )
F_247 ( & V_384 -> V_108 ) ;
}
static void F_248 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
enum V_71 V_71 = F_30 ( V_21 ) -> V_71 ;
struct V_384 * V_384 ;
F_172 (intel_plane, &dev->mode_config.plane_list, base.head)
if ( V_384 -> V_71 == V_71 )
F_249 ( & V_384 -> V_108 ) ;
}
void F_250 ( struct V_64 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_108 . V_2 -> V_5 ;
if ( ! V_21 -> V_67 . V_385 )
return;
F_189 ( V_4 , V_21 -> V_141 ) ;
if ( F_167 ( V_21 -> V_108 . V_2 ) ) {
F_53 ( & V_4 -> V_386 . V_387 ) ;
F_2 ( F_251 ( V_4 , V_388 , 0xc0000000 ) ) ;
F_55 ( & V_4 -> V_386 . V_387 ) ;
} else {
F_40 ( V_389 , V_390 ) ;
if ( F_34 ( F_35 ( V_389 ) & V_390 , 50 ) )
F_115 ( L_81 ) ;
}
}
void F_252 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_21 -> V_67 . V_385 )
return;
F_189 ( V_4 , V_21 -> V_141 ) ;
if ( F_167 ( V_21 -> V_108 . V_2 ) ) {
F_53 ( & V_4 -> V_386 . V_387 ) ;
F_2 ( F_251 ( V_4 , V_388 , 0 ) ) ;
F_55 ( & V_4 -> V_386 . V_387 ) ;
} else
F_40 ( V_389 , 0 ) ;
F_113 ( V_389 ) ;
F_37 ( V_2 , V_21 -> V_71 ) ;
}
static void F_253 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_71 V_71 = V_64 -> V_71 ;
int V_391 = F_254 ( V_71 ) ;
int V_143 ;
bool V_392 = false ;
if ( ! V_21 -> V_99 || ! V_64 -> V_65 )
return;
if ( ! F_3 ( V_4 -> V_2 ) ) {
if ( F_9 ( V_21 , V_393 ) )
F_136 ( V_4 ) ;
else
F_137 ( V_4 , V_71 ) ;
}
if ( F_3 ( V_2 ) )
V_391 = F_255 ( V_71 ) ;
if ( V_64 -> V_67 . V_385 &&
( ( F_4 ( F_256 ( V_71 ) ) & V_394 ) ==
V_395 ) ) {
F_252 ( V_64 ) ;
V_392 = true ;
}
for ( V_143 = 0 ; V_143 < 256 ; V_143 ++ ) {
F_40 ( V_391 + 4 * V_143 ,
( V_64 -> V_396 [ V_143 ] << 16 ) |
( V_64 -> V_397 [ V_143 ] << 8 ) |
V_64 -> V_398 [ V_143 ] ) ;
}
if ( V_392 )
F_250 ( V_64 ) ;
}
static void F_257 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
F_2 ( ! V_21 -> V_99 ) ;
if ( V_64 -> V_65 )
return;
V_64 -> V_65 = true ;
F_258 ( V_2 , V_71 , true ) ;
F_259 ( V_2 , V_71 , true ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_399 )
V_23 -> V_399 ( V_23 ) ;
if ( V_64 -> V_67 . V_302 ) {
F_199 ( V_64 ) ;
} else {
F_131 ( V_4 , V_71 ) ;
F_132 ( V_4 , V_71 ) ;
}
F_244 ( V_64 ) ;
F_253 ( V_21 ) ;
F_260 ( V_21 ) ;
F_134 ( V_4 , V_71 ,
V_64 -> V_67 . V_302 , false ) ;
F_143 ( V_4 , V_141 , V_71 ) ;
F_246 ( V_21 ) ;
F_261 ( V_21 , true ) ;
if ( V_64 -> V_67 . V_302 )
F_234 ( V_21 ) ;
F_53 ( & V_2 -> V_286 ) ;
F_183 ( V_2 ) ;
F_55 ( & V_2 -> V_286 ) ;
F_10 (dev, crtc, encoder)
V_23 -> V_194 ( V_23 ) ;
if ( F_94 ( V_2 ) )
F_243 ( V_2 , V_64 -> V_71 ) ;
F_37 ( V_2 , V_64 -> V_71 ) ;
}
static bool F_262 ( struct V_64 * V_21 )
{
return F_263 ( V_21 -> V_108 . V_2 ) && V_21 -> V_71 == V_125 ;
}
static void F_264 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
F_143 ( V_4 , V_141 , V_71 ) ;
F_246 ( V_21 ) ;
F_261 ( V_21 , true ) ;
F_250 ( V_64 ) ;
F_53 ( & V_2 -> V_286 ) ;
F_183 ( V_2 ) ;
F_55 ( & V_2 -> V_286 ) ;
}
static void F_265 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
F_207 ( V_21 ) ;
F_266 ( V_2 , V_71 ) ;
if ( V_4 -> V_400 . V_141 == V_141 )
F_267 ( V_2 ) ;
F_252 ( V_64 ) ;
F_261 ( V_21 , false ) ;
F_248 ( V_21 ) ;
F_145 ( V_4 , V_141 , V_71 ) ;
}
static void F_268 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_64 * V_401 , * V_402 = NULL ;
F_172 (crtc_it, &dev->mode_config.crtc_list, base.head) {
if ( ! V_401 -> V_65 || V_401 == V_21 )
continue;
if ( V_402 )
return;
V_402 = V_401 ;
}
if ( ! V_402 )
return;
F_37 ( V_2 , V_402 -> V_71 ) ;
F_37 ( V_2 , V_402 -> V_71 ) ;
}
static void F_269 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_71 = V_64 -> V_71 ;
F_2 ( ! V_21 -> V_99 ) ;
if ( V_64 -> V_65 )
return;
V_64 -> V_65 = true ;
F_258 ( V_2 , V_71 , true ) ;
if ( V_64 -> V_67 . V_302 )
F_259 ( V_2 , V_206 , true ) ;
if ( V_64 -> V_67 . V_302 )
V_4 -> V_269 . V_360 ( V_21 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_399 )
V_23 -> V_399 ( V_23 ) ;
F_270 ( V_64 ) ;
F_244 ( V_64 ) ;
F_253 ( V_21 ) ;
F_271 ( V_21 ) ;
F_272 ( V_21 ) ;
F_260 ( V_21 ) ;
F_134 ( V_4 , V_71 ,
V_64 -> V_67 . V_302 , false ) ;
if ( V_64 -> V_67 . V_302 )
F_240 ( V_21 ) ;
F_10 (dev, crtc, encoder) {
V_23 -> V_194 ( V_23 ) ;
F_273 ( V_23 , true ) ;
}
F_268 ( V_64 ) ;
F_264 ( V_21 ) ;
F_37 ( V_2 , V_64 -> V_71 ) ;
}
static void F_274 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_21 -> V_71 ;
if ( V_21 -> V_67 . V_291 . V_99 ) {
F_40 ( F_180 ( V_71 ) , 0 ) ;
F_40 ( F_181 ( V_71 ) , 0 ) ;
F_40 ( F_182 ( V_71 ) , 0 ) ;
}
}
static void F_275 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
T_1 V_79 , V_293 ;
if ( ! V_64 -> V_65 )
return;
F_10 (dev, crtc, encoder)
V_23 -> V_195 ( V_23 ) ;
F_207 ( V_21 ) ;
F_266 ( V_2 , V_71 ) ;
if ( V_4 -> V_400 . V_141 == V_141 )
F_267 ( V_2 ) ;
F_261 ( V_21 , false ) ;
F_248 ( V_21 ) ;
F_145 ( V_4 , V_141 , V_71 ) ;
if ( V_64 -> V_67 . V_302 )
F_259 ( V_2 , V_71 , false ) ;
F_139 ( V_4 , V_71 ) ;
F_274 ( V_64 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_403 )
V_23 -> V_403 ( V_23 ) ;
if ( V_64 -> V_67 . V_302 ) {
F_201 ( V_21 ) ;
F_130 ( V_4 , V_71 ) ;
F_259 ( V_2 , V_71 , true ) ;
if ( F_94 ( V_2 ) ) {
V_79 = F_95 ( V_71 ) ;
V_293 = F_4 ( V_79 ) ;
V_293 &= ~ ( V_368 |
V_160 ) ;
V_293 |= V_404 ;
F_40 ( V_79 , V_293 ) ;
V_293 = F_4 ( V_362 ) ;
V_293 &= ~ ( F_237 ( V_71 ) | F_238 ( V_71 ) ) ;
F_40 ( V_362 , V_293 ) ;
}
F_123 ( V_64 ) ;
F_200 ( V_64 ) ;
}
V_64 -> V_65 = false ;
F_260 ( V_21 ) ;
F_53 ( & V_2 -> V_286 ) ;
F_183 ( V_2 ) ;
F_55 ( & V_2 -> V_286 ) ;
}
static void F_276 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_71 = V_64 -> V_71 ;
enum V_70 V_73 = V_64 -> V_67 . V_73 ;
if ( ! V_64 -> V_65 )
return;
F_265 ( V_21 ) ;
F_10 (dev, crtc, encoder) {
F_273 ( V_23 , false ) ;
V_23 -> V_195 ( V_23 ) ;
}
if ( V_64 -> V_67 . V_302 )
F_259 ( V_2 , V_206 , false ) ;
F_139 ( V_4 , V_71 ) ;
F_277 ( V_4 , V_73 ) ;
F_274 ( V_64 ) ;
F_278 ( V_64 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_403 )
V_23 -> V_403 ( V_23 ) ;
if ( V_64 -> V_67 . V_302 ) {
F_133 ( V_4 ) ;
F_259 ( V_2 , V_206 , true ) ;
F_279 ( V_21 ) ;
}
V_64 -> V_65 = false ;
F_260 ( V_21 ) ;
F_53 ( & V_2 -> V_286 ) ;
F_183 ( V_2 ) ;
F_55 ( & V_2 -> V_286 ) ;
}
static void F_280 ( struct V_20 * V_21 )
{
struct V_64 * V_64 = F_30 ( V_21 ) ;
F_241 ( V_64 ) ;
}
static void F_281 ( struct V_20 * V_21 )
{
F_282 ( V_21 ) ;
}
static void F_283 ( struct V_64 * V_64 , bool V_194 )
{
if ( ! V_194 && V_64 -> V_405 ) {
struct V_1 * V_2 = V_64 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_53 ( & V_2 -> V_286 ) ;
V_4 -> V_226 . V_227 = false ;
( void ) F_284 ( V_64 -> V_405 ) ;
V_4 -> V_226 . V_227 = true ;
F_55 ( & V_2 -> V_286 ) ;
}
}
static void
F_285 ( struct V_3 * V_4 , enum V_71 V_71 )
{
T_1 V_406 = F_4 ( F_76 ( V_71 ) ) ;
if ( ( V_406 & V_135 ) == 0 ) {
T_1 V_407 = F_4 ( V_408 ) ;
F_40 ( V_408 , V_407 & ~ V_409 ) ;
F_40 ( F_76 ( V_71 ) , V_410 ) ;
F_37 ( V_4 -> V_2 , V_71 ) ;
F_40 ( F_76 ( V_71 ) , V_406 ) ;
F_40 ( F_286 ( V_71 ) , F_4 ( F_286 ( V_71 ) ) ) ;
F_40 ( V_408 , V_407 ) ;
}
}
static void F_287 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_411 * V_412 = & V_21 -> V_67 ;
if ( ! V_21 -> V_67 . V_413 . V_414 )
return;
F_2 ( F_4 ( V_415 ) & V_416 ) ;
F_109 ( V_4 , V_21 -> V_71 ) ;
F_40 ( V_417 , V_412 -> V_413 . V_418 ) ;
F_40 ( V_415 , V_412 -> V_413 . V_414 ) ;
F_40 ( F_288 ( V_21 -> V_71 ) , 0 ) ;
}
static void F_289 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
bool V_419 ;
F_2 ( ! V_21 -> V_99 ) ;
if ( V_64 -> V_65 )
return;
V_64 -> V_65 = true ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_420 )
V_23 -> V_420 ( V_23 ) ;
V_419 = F_9 ( V_21 , V_393 ) ;
if ( ! V_419 )
F_108 ( V_64 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_399 )
V_23 -> V_399 ( V_23 ) ;
F_287 ( V_64 ) ;
F_253 ( V_21 ) ;
F_260 ( V_21 ) ;
F_134 ( V_4 , V_71 , false , V_419 ) ;
F_143 ( V_4 , V_141 , V_71 ) ;
F_246 ( V_21 ) ;
F_261 ( V_21 , true ) ;
F_183 ( V_2 ) ;
F_10 (dev, crtc, encoder)
V_23 -> V_194 ( V_23 ) ;
}
static void F_290 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
F_2 ( ! V_21 -> V_99 ) ;
if ( V_64 -> V_65 )
return;
V_64 -> V_65 = true ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_399 )
V_23 -> V_399 ( V_23 ) ;
F_117 ( V_64 ) ;
F_287 ( V_64 ) ;
F_253 ( V_21 ) ;
F_260 ( V_21 ) ;
F_134 ( V_4 , V_71 , false , false ) ;
F_143 ( V_4 , V_141 , V_71 ) ;
F_246 ( V_21 ) ;
if ( F_15 ( V_2 ) )
F_285 ( V_4 , V_71 ) ;
F_261 ( V_21 , true ) ;
F_283 ( V_64 , true ) ;
F_183 ( V_2 ) ;
F_10 (dev, crtc, encoder)
V_23 -> V_194 ( V_23 ) ;
}
static void F_291 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_21 -> V_67 . V_413 . V_414 )
return;
F_109 ( V_4 , V_21 -> V_71 ) ;
F_59 ( L_82 ,
F_4 ( V_415 ) ) ;
F_40 ( V_415 , 0 ) ;
}
static void F_292 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
if ( ! V_64 -> V_65 )
return;
F_10 (dev, crtc, encoder)
V_23 -> V_195 ( V_23 ) ;
F_207 ( V_21 ) ;
F_266 ( V_2 , V_71 ) ;
if ( V_4 -> V_400 . V_141 == V_141 )
F_267 ( V_2 ) ;
F_283 ( V_64 , false ) ;
F_261 ( V_21 , false ) ;
F_248 ( V_21 ) ;
F_145 ( V_4 , V_141 , V_71 ) ;
F_139 ( V_4 , V_71 ) ;
F_291 ( V_64 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_403 )
V_23 -> V_403 ( V_23 ) ;
if ( F_17 ( V_2 ) && ! F_9 ( V_21 , V_393 ) )
F_119 ( V_4 , V_71 ) ;
else if ( ! F_17 ( V_2 ) )
F_118 ( V_4 , V_71 ) ;
V_64 -> V_65 = false ;
F_260 ( V_21 ) ;
F_183 ( V_2 ) ;
}
static void F_293 ( struct V_20 * V_21 )
{
}
static void F_294 ( struct V_20 * V_21 ,
bool V_99 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_275 * V_276 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
if ( ! V_2 -> V_277 -> V_278 )
return;
V_276 = V_2 -> V_277 -> V_278 -> V_279 ;
if ( ! V_276 -> V_280 )
return;
switch ( V_71 ) {
case 0 :
V_276 -> V_280 -> V_421 = V_99 ? V_21 -> V_370 . V_422 : 0 ;
V_276 -> V_280 -> V_423 = V_99 ? V_21 -> V_370 . V_424 : 0 ;
break;
case 1 :
V_276 -> V_280 -> V_425 = V_99 ? V_21 -> V_370 . V_422 : 0 ;
V_276 -> V_280 -> V_426 = V_99 ? V_21 -> V_370 . V_424 : 0 ;
break;
default:
F_115 ( L_83 , F_69 ( V_71 ) ) ;
break;
}
}
void F_295 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_22 ;
bool V_194 = false ;
F_10 (dev, crtc, intel_encoder)
V_194 |= V_22 -> V_427 ;
if ( V_194 )
V_4 -> V_269 . V_428 ( V_21 ) ;
else
V_4 -> V_269 . V_429 ( V_21 ) ;
F_294 ( V_21 , V_194 ) ;
}
static void F_296 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_430 * V_431 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
F_2 ( ! V_21 -> V_99 ) ;
V_4 -> V_269 . V_429 ( V_21 ) ;
V_64 -> V_432 = false ;
F_294 ( V_21 , false ) ;
V_4 -> V_269 . V_433 ( V_21 ) ;
F_297 ( V_2 -> V_5 , F_30 ( V_21 ) -> V_141 ) ;
F_135 ( V_4 , F_30 ( V_21 ) -> V_71 ) ;
F_109 ( V_2 -> V_5 , F_30 ( V_21 ) -> V_71 ) ;
if ( V_21 -> V_66 ) {
F_53 ( & V_2 -> V_286 ) ;
F_156 ( F_160 ( V_21 -> V_66 ) -> V_216 ) ;
F_55 ( & V_2 -> V_286 ) ;
V_21 -> V_66 = NULL ;
}
F_172 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_431 -> V_23 || ! V_431 -> V_23 -> V_21 )
continue;
if ( V_431 -> V_23 -> V_21 != V_21 )
continue;
V_431 -> V_434 = V_435 ;
F_298 ( V_431 -> V_23 ) -> V_427 = false ;
}
}
void F_299 ( struct V_436 * V_23 )
{
struct V_22 * V_22 = F_298 ( V_23 ) ;
F_300 ( V_23 ) ;
F_301 ( V_22 ) ;
}
static void F_302 ( struct V_22 * V_23 , int V_370 )
{
if ( V_370 == V_437 ) {
V_23 -> V_427 = true ;
F_295 ( V_23 -> V_108 . V_21 ) ;
} else {
V_23 -> V_427 = false ;
F_295 ( V_23 -> V_108 . V_21 ) ;
}
}
static void F_303 ( struct V_438 * V_431 )
{
if ( V_431 -> V_114 ( V_431 ) ) {
struct V_22 * V_23 = V_431 -> V_23 ;
struct V_20 * V_21 ;
bool V_439 ;
enum V_71 V_71 ;
F_36 ( L_84 ,
V_431 -> V_108 . V_108 . V_193 ,
F_304 ( & V_431 -> V_108 ) ) ;
F_46 ( V_431 -> V_108 . V_434 == V_435 ,
L_85 ) ;
F_46 ( V_431 -> V_108 . V_23 != & V_23 -> V_108 ,
L_86 ) ;
F_46 ( ! V_23 -> V_427 ,
L_87 ) ;
V_439 = V_23 -> V_114 ( V_23 , & V_71 ) ;
F_46 ( ! V_439 , L_88 ) ;
if ( F_2 ( ! V_23 -> V_108 . V_21 ) )
return;
V_21 = V_23 -> V_108 . V_21 ;
F_46 ( ! V_21 -> V_99 , L_89 ) ;
F_46 ( ! F_30 ( V_21 ) -> V_65 , L_90 ) ;
F_46 ( V_71 != F_30 ( V_21 ) -> V_71 ,
L_91 ) ;
}
}
void F_305 ( struct V_430 * V_431 , int V_370 )
{
if ( V_370 != V_437 )
V_370 = V_435 ;
if ( V_370 == V_431 -> V_434 )
return;
V_431 -> V_434 = V_370 ;
if ( V_431 -> V_23 )
F_302 ( F_298 ( V_431 -> V_23 ) , V_370 ) ;
F_306 ( V_431 -> V_2 ) ;
}
bool F_307 ( struct V_438 * V_431 )
{
enum V_71 V_71 = 0 ;
struct V_22 * V_23 = V_431 -> V_23 ;
return V_23 -> V_114 ( V_23 , & V_71 ) ;
}
static bool F_308 ( struct V_1 * V_2 , enum V_71 V_71 ,
struct V_411 * V_412 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_303 =
F_30 ( V_4 -> V_72 [ V_134 ] ) ;
F_36 ( L_92 ,
F_69 ( V_71 ) , V_412 -> V_312 ) ;
if ( V_412 -> V_312 > 4 ) {
F_36 ( L_93 ,
F_69 ( V_71 ) , V_412 -> V_312 ) ;
return false ;
}
if ( F_72 ( V_2 ) || F_167 ( V_2 ) ) {
if ( V_412 -> V_312 > 2 ) {
F_36 ( L_94 ,
V_412 -> V_312 ) ;
return false ;
} else {
return true ;
}
}
if ( F_39 ( V_2 ) -> V_285 == 2 )
return true ;
switch ( V_71 ) {
case V_125 :
return true ;
case V_134 :
if ( V_4 -> V_72 [ V_305 ] -> V_99 &&
V_412 -> V_312 > 2 ) {
F_36 ( L_95 ,
F_69 ( V_71 ) , V_412 -> V_312 ) ;
return false ;
}
return true ;
case V_305 :
if ( ! F_186 ( V_303 ) ||
V_303 -> V_67 . V_312 <= 2 ) {
if ( V_412 -> V_312 > 2 ) {
F_36 ( L_95 ,
F_69 ( V_71 ) , V_412 -> V_312 ) ;
return false ;
}
} else {
F_36 ( L_96 ) ;
return false ;
}
return true ;
default:
F_151 () ;
}
}
static int F_309 ( struct V_64 * V_64 ,
struct V_411 * V_412 )
{
struct V_1 * V_2 = V_64 -> V_108 . V_2 ;
struct V_288 * V_68 = & V_412 -> V_68 ;
int V_440 , V_441 , V_442 ;
bool V_443 , V_444 = false ;
V_317:
V_441 = F_5 ( V_2 ) * F_310 ( 100 ) / F_311 ( 1 ) / 10 ;
V_442 = V_68 -> V_69 ;
V_440 = F_312 ( V_442 , V_441 ,
V_412 -> V_445 ) ;
V_412 -> V_312 = V_440 ;
F_313 ( V_412 -> V_445 , V_440 , V_442 ,
V_441 , & V_412 -> V_446 ) ;
V_443 = F_308 ( V_64 -> V_108 . V_2 ,
V_64 -> V_71 , V_412 ) ;
if ( ! V_443 && V_412 -> V_445 > 6 * 3 ) {
V_412 -> V_445 -= 2 * 3 ;
F_36 ( L_97 ,
V_412 -> V_445 ) ;
V_444 = true ;
V_412 -> V_447 = true ;
goto V_317;
}
if ( V_444 )
return V_448 ;
return V_443 ? 0 : - V_225 ;
}
static void F_314 ( struct V_64 * V_21 ,
struct V_411 * V_412 )
{
V_412 -> V_385 = V_449 &&
F_262 ( V_21 ) &&
V_412 -> V_445 <= 24 ;
}
static int F_315 ( struct V_64 * V_21 ,
struct V_411 * V_412 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_288 * V_68 = & V_412 -> V_68 ;
if ( F_39 ( V_2 ) -> V_77 < 4 ) {
struct V_3 * V_4 = V_2 -> V_5 ;
int V_450 =
V_4 -> V_269 . V_451 ( V_2 ) ;
if ( ( V_21 -> V_71 == V_125 || F_316 ( V_2 ) ) &&
V_68 -> V_69 > V_450 * 9 / 10 ) {
V_450 *= 2 ;
V_412 -> V_452 = true ;
}
if ( V_68 -> V_69 > V_450 * 9 / 10 )
return - V_225 ;
}
if ( ( F_9 ( & V_21 -> V_108 , V_25 ) &&
F_12 ( V_2 ) ) || V_412 -> V_452 )
V_412 -> V_453 &= ~ 1 ;
if ( ( F_39 ( V_2 ) -> V_77 > 4 || F_15 ( V_2 ) ) &&
V_68 -> V_454 == V_68 -> V_422 )
return - V_225 ;
if ( ( F_15 ( V_2 ) || F_17 ( V_2 ) ) && V_412 -> V_445 > 10 * 3 ) {
V_412 -> V_445 = 10 * 3 ;
} else if ( F_39 ( V_2 ) -> V_77 <= 4 && V_412 -> V_445 > 8 * 3 ) {
V_412 -> V_445 = 8 * 3 ;
}
if ( F_263 ( V_2 ) )
F_314 ( V_21 , V_412 ) ;
if ( F_48 ( V_2 ) || F_94 ( V_2 ) )
V_412 -> V_109 = V_21 -> V_67 . V_109 ;
if ( V_412 -> V_302 )
return F_309 ( V_21 , V_412 ) ;
return 0 ;
}
static int F_317 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_318 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_319 ( struct V_1 * V_2 )
{
return 333000 ;
}
static int F_320 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_321 ( struct V_1 * V_2 )
{
T_5 V_455 = 0 ;
F_322 ( V_2 -> V_456 , V_457 , & V_455 ) ;
switch ( V_455 & V_458 ) {
case V_459 :
return 267000 ;
case V_460 :
return 333000 ;
case V_461 :
return 444000 ;
case V_462 :
return 200000 ;
default:
F_115 ( L_98 , V_455 ) ;
case V_463 :
return 133000 ;
case V_464 :
return 167000 ;
}
}
static int F_323 ( struct V_1 * V_2 )
{
T_5 V_455 = 0 ;
F_322 ( V_2 -> V_456 , V_457 , & V_455 ) ;
if ( V_455 & V_465 )
return 133000 ;
else {
switch ( V_455 & V_458 ) {
case V_466 :
return 333000 ;
default:
case V_467 :
return 190000 ;
}
}
}
static int F_324 ( struct V_1 * V_2 )
{
return 266000 ;
}
static int F_325 ( struct V_1 * V_2 )
{
T_5 V_468 = 0 ;
switch ( V_468 & V_469 ) {
case V_470 :
case V_471 :
return 200000 ;
case V_472 :
return 250000 ;
case V_473 :
return 133000 ;
}
return 0 ;
}
static int F_326 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_327 ( T_4 * V_474 , T_4 * V_475 )
{
while ( * V_474 > V_476 ||
* V_475 > V_476 ) {
* V_474 >>= 1 ;
* V_475 >>= 1 ;
}
}
static void F_328 ( unsigned int V_11 , unsigned int V_18 ,
T_4 * V_477 , T_4 * V_478 )
{
* V_478 = F_329 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_477 = F_28 ( ( V_479 ) V_11 * * V_478 , V_18 ) ;
F_327 ( V_477 , V_478 ) ;
}
void
F_313 ( int V_266 , int V_480 ,
int V_481 , int V_482 ,
struct V_483 * V_484 )
{
V_484 -> V_485 = 64 ;
F_328 ( V_266 * V_481 ,
V_482 * V_480 * 8 ,
& V_484 -> V_486 , & V_484 -> V_487 ) ;
F_328 ( V_481 , V_482 ,
& V_484 -> V_488 , & V_484 -> V_489 ) ;
}
static inline bool F_330 ( struct V_3 * V_4 )
{
if ( V_490 >= 0 )
return V_490 != 0 ;
return V_4 -> V_491 . V_492
&& ! ( V_4 -> V_138 & V_493 ) ;
}
static int F_331 ( struct V_20 * V_21 , int V_494 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_10 ;
if ( F_17 ( V_2 ) ) {
V_10 = 100000 ;
} else if ( F_9 ( V_21 , V_25 ) &&
F_330 ( V_4 ) && V_494 < 2 ) {
V_10 = V_4 -> V_491 . V_495 * 1000 ;
F_36 ( L_99 ,
V_10 / 1000 ) ;
} else if ( ! F_18 ( V_2 ) ) {
V_10 = 96000 ;
} else {
V_10 = 48000 ;
}
return V_10 ;
}
static T_4 F_332 ( struct V_47 * V_47 )
{
return ( 1 << V_47 -> V_18 ) << 16 | V_47 -> V_13 ;
}
static T_4 F_333 ( struct V_47 * V_47 )
{
return V_47 -> V_18 << 16 | V_47 -> V_12 << 8 | V_47 -> V_13 ;
}
static void F_334 ( struct V_64 * V_21 ,
T_2 * V_496 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_21 -> V_71 ;
T_1 V_497 , V_498 = 0 ;
if ( F_16 ( V_2 ) ) {
V_497 = F_332 ( & V_21 -> V_67 . V_47 ) ;
if ( V_496 )
V_498 = F_332 ( V_496 ) ;
} else {
V_497 = F_333 ( & V_21 -> V_67 . V_47 ) ;
if ( V_496 )
V_498 = F_333 ( V_496 ) ;
}
F_40 ( F_335 ( V_71 ) , V_497 ) ;
V_21 -> V_67 . V_184 . V_499 = V_497 ;
V_21 -> V_500 = false ;
if ( F_9 ( & V_21 -> V_108 , V_25 ) &&
V_496 && V_501 ) {
F_40 ( F_336 ( V_71 ) , V_498 ) ;
V_21 -> V_67 . V_184 . V_502 = V_498 ;
V_21 -> V_500 = true ;
} else {
F_40 ( F_336 ( V_71 ) , V_497 ) ;
V_21 -> V_67 . V_184 . V_502 = V_497 ;
}
}
static void F_337 ( struct V_3 * V_4 , enum V_71
V_71 )
{
T_1 V_503 ;
V_503 = F_338 ( V_4 , V_71 , F_339 ( 1 ) ) ;
V_503 &= 0xffffff00 ;
V_503 |= 0x00000030 ;
F_340 ( V_4 , V_71 , F_339 ( 1 ) , V_503 ) ;
V_503 = F_338 ( V_4 , V_71 , V_504 ) ;
V_503 &= 0x8cffffff ;
V_503 = 0x8c000000 ;
F_340 ( V_4 , V_71 , V_504 , V_503 ) ;
V_503 = F_338 ( V_4 , V_71 , F_339 ( 1 ) ) ;
V_503 &= 0xffffff00 ;
F_340 ( V_4 , V_71 , F_339 ( 1 ) , V_503 ) ;
V_503 = F_338 ( V_4 , V_71 , V_504 ) ;
V_503 &= 0x00ffffff ;
V_503 |= 0xb0000000 ;
F_340 ( V_4 , V_71 , V_504 , V_503 ) ;
}
static void F_341 ( struct V_64 * V_21 ,
struct V_483 * V_484 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_21 -> V_71 ;
F_40 ( F_342 ( V_71 ) , F_343 ( V_484 -> V_485 ) | V_484 -> V_486 ) ;
F_40 ( F_344 ( V_71 ) , V_484 -> V_487 ) ;
F_40 ( F_345 ( V_71 ) , V_484 -> V_488 ) ;
F_40 ( F_346 ( V_71 ) , V_484 -> V_489 ) ;
}
static void F_347 ( struct V_64 * V_21 ,
struct V_483 * V_484 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_21 -> V_71 ;
enum V_70 V_70 = V_21 -> V_67 . V_73 ;
if ( F_39 ( V_2 ) -> V_77 >= 5 ) {
F_40 ( F_236 ( V_70 ) , F_343 ( V_484 -> V_485 ) | V_484 -> V_486 ) ;
F_40 ( F_348 ( V_70 ) , V_484 -> V_487 ) ;
F_40 ( F_349 ( V_70 ) , V_484 -> V_488 ) ;
F_40 ( F_350 ( V_70 ) , V_484 -> V_489 ) ;
} else {
F_40 ( F_351 ( V_71 ) , F_343 ( V_484 -> V_485 ) | V_484 -> V_486 ) ;
F_40 ( F_352 ( V_71 ) , V_484 -> V_487 ) ;
F_40 ( F_353 ( V_71 ) , V_484 -> V_488 ) ;
F_40 ( F_354 ( V_71 ) , V_484 -> V_489 ) ;
}
}
static void F_355 ( struct V_64 * V_21 )
{
if ( V_21 -> V_67 . V_302 )
F_341 ( V_21 , & V_21 -> V_67 . V_505 ) ;
else
F_347 ( V_21 , & V_21 -> V_67 . V_505 ) ;
}
static void F_356 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_21 -> V_71 ;
T_1 V_47 , V_506 ;
T_1 V_507 , V_508 , V_509 , V_510 , V_511 ;
T_1 V_512 , V_503 , V_186 ;
F_53 ( & V_4 -> V_104 ) ;
V_507 = V_21 -> V_67 . V_47 . V_18 ;
V_508 = V_21 -> V_67 . V_47 . V_12 ;
V_509 = V_21 -> V_67 . V_47 . V_13 ;
V_510 = V_21 -> V_67 . V_47 . V_15 ;
V_511 = V_21 -> V_67 . V_47 . V_16 ;
if ( V_71 )
F_337 ( V_4 , V_71 ) ;
F_340 ( V_4 , V_71 , V_513 , 0x0100000f ) ;
V_503 = F_338 ( V_4 , V_71 , F_357 ( V_71 ) ) ;
V_503 &= 0x00ffffff ;
F_340 ( V_4 , V_71 , F_357 ( V_71 ) , V_503 ) ;
F_340 ( V_4 , V_71 , V_514 , 0x610 ) ;
V_506 = ( ( V_508 << V_515 ) | ( V_509 & V_516 ) ) ;
V_506 |= ( ( V_510 << V_517 ) | ( V_511 << V_518 ) ) ;
V_506 |= ( ( V_507 << V_519 ) ) ;
V_506 |= ( 1 << V_520 ) ;
V_506 |= ( V_521 << V_522 ) ;
F_340 ( V_4 , V_71 , F_358 ( V_71 ) , V_506 ) ;
V_506 |= V_523 ;
F_340 ( V_4 , V_71 , F_358 ( V_71 ) , V_506 ) ;
if ( V_21 -> V_67 . V_524 == 162000 ||
F_9 ( & V_21 -> V_108 , V_34 ) ||
F_9 ( & V_21 -> V_108 , V_33 ) )
F_340 ( V_4 , V_71 , F_359 ( V_71 ) ,
0x009f0003 ) ;
else
F_340 ( V_4 , V_71 , F_359 ( V_71 ) ,
0x00d0000f ) ;
if ( F_9 ( & V_21 -> V_108 , V_292 ) ||
F_9 ( & V_21 -> V_108 , V_364 ) ) {
if ( ! V_71 )
F_340 ( V_4 , V_71 , F_360 ( V_71 ) ,
0x0df40000 ) ;
else
F_340 ( V_4 , V_71 , F_360 ( V_71 ) ,
0x0df70000 ) ;
} else {
if ( ! V_71 )
F_340 ( V_4 , V_71 , F_360 ( V_71 ) ,
0x0df70000 ) ;
else
F_340 ( V_4 , V_71 , F_360 ( V_71 ) ,
0x0df40000 ) ;
}
V_512 = F_338 ( V_4 , V_71 , F_361 ( V_71 ) ) ;
V_512 = ( V_512 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_9 ( & V_21 -> V_108 , V_364 ) ||
F_9 ( & V_21 -> V_108 , V_292 ) )
V_512 |= 0x01000000 ;
F_340 ( V_4 , V_71 , F_361 ( V_71 ) , V_512 ) ;
F_340 ( V_4 , V_71 , F_362 ( V_71 ) , 0x87871000 ) ;
V_47 = V_525 | V_526 |
V_527 | V_528 ;
if ( V_71 == V_134 )
V_47 |= V_187 ;
V_47 |= V_103 ;
V_21 -> V_67 . V_184 . V_47 = V_47 ;
V_186 = ( V_21 -> V_67 . V_529 - 1 )
<< V_530 ;
V_21 -> V_67 . V_184 . V_186 = V_186 ;
if ( V_21 -> V_67 . V_531 )
F_355 ( V_21 ) ;
F_55 ( & V_4 -> V_104 ) ;
}
static void F_363 ( struct V_64 * V_21 ,
T_2 * V_496 ,
int V_494 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_47 ;
bool V_532 ;
struct V_47 * clock = & V_21 -> V_67 . V_47 ;
F_334 ( V_21 , V_496 ) ;
V_532 = F_9 ( & V_21 -> V_108 , V_36 ) ||
F_9 ( & V_21 -> V_108 , V_33 ) ;
V_47 = V_527 ;
if ( F_9 ( & V_21 -> V_108 , V_25 ) )
V_47 |= V_533 ;
else
V_47 |= V_534 ;
if ( F_364 ( V_2 ) || F_365 ( V_2 ) || F_366 ( V_2 ) ) {
V_47 |= ( V_21 -> V_67 . V_529 - 1 )
<< V_535 ;
}
if ( V_532 )
V_47 |= V_536 ;
if ( F_9 ( & V_21 -> V_108 , V_364 ) )
V_47 |= V_536 ;
if ( F_16 ( V_2 ) )
V_47 |= ( 1 << ( clock -> V_15 - 1 ) ) << V_537 ;
else {
V_47 |= ( 1 << ( clock -> V_15 - 1 ) ) << V_538 ;
if ( F_15 ( V_2 ) && V_496 )
V_47 |= ( 1 << ( V_496 -> V_15 - 1 ) ) << V_539 ;
}
switch ( clock -> V_16 ) {
case 5 :
V_47 |= V_540 ;
break;
case 7 :
V_47 |= V_541 ;
break;
case 10 :
V_47 |= V_542 ;
break;
case 14 :
V_47 |= V_543 ;
break;
}
if ( F_39 ( V_2 ) -> V_77 >= 4 )
V_47 |= ( 6 << V_544 ) ;
if ( V_21 -> V_67 . V_545 )
V_47 |= V_546 ;
else if ( F_9 ( & V_21 -> V_108 , V_25 ) &&
F_330 ( V_4 ) && V_494 < 2 )
V_47 |= V_547 ;
else
V_47 |= V_548 ;
V_47 |= V_103 ;
V_21 -> V_67 . V_184 . V_47 = V_47 ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
T_1 V_186 = ( V_21 -> V_67 . V_529 - 1 )
<< V_530 ;
V_21 -> V_67 . V_184 . V_186 = V_186 ;
}
if ( V_21 -> V_67 . V_531 )
F_355 ( V_21 ) ;
}
static void F_367 ( struct V_64 * V_21 ,
T_2 * V_496 ,
int V_494 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_47 ;
struct V_47 * clock = & V_21 -> V_67 . V_47 ;
F_334 ( V_21 , V_496 ) ;
V_47 = V_527 ;
if ( F_9 ( & V_21 -> V_108 , V_25 ) ) {
V_47 |= ( 1 << ( clock -> V_15 - 1 ) ) << V_538 ;
} else {
if ( clock -> V_15 == 2 )
V_47 |= V_549 ;
else
V_47 |= ( clock -> V_15 - 2 ) << V_538 ;
if ( clock -> V_16 == 4 )
V_47 |= V_550 ;
}
if ( F_9 ( & V_21 -> V_108 , V_44 ) )
V_47 |= V_551 ;
if ( F_9 ( & V_21 -> V_108 , V_25 ) &&
F_330 ( V_4 ) && V_494 < 2 )
V_47 |= V_547 ;
else
V_47 |= V_548 ;
V_47 |= V_103 ;
V_21 -> V_67 . V_184 . V_47 = V_47 ;
}
static void F_368 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_71 V_71 = V_64 -> V_71 ;
enum V_70 V_73 = V_64 -> V_67 . V_73 ;
struct V_288 * V_68 =
& V_64 -> V_67 . V_68 ;
T_4 V_552 , V_553 , V_554 ;
V_553 = V_68 -> V_553 ;
V_554 = V_68 -> V_554 ;
if ( ! F_18 ( V_2 ) && V_68 -> V_332 & V_555 ) {
V_553 -= 1 ;
V_554 -= 1 ;
V_552 = V_68 -> V_556
- V_68 -> V_557 / 2 ;
} else {
V_552 = 0 ;
}
if ( F_39 ( V_2 ) -> V_77 > 3 )
F_40 ( F_231 ( V_73 ) , V_552 ) ;
F_40 ( F_219 ( V_73 ) ,
( V_68 -> V_289 - 1 ) |
( ( V_68 -> V_557 - 1 ) << 16 ) ) ;
F_40 ( F_221 ( V_73 ) ,
( V_68 -> V_558 - 1 ) |
( ( V_68 -> V_559 - 1 ) << 16 ) ) ;
F_40 ( F_223 ( V_73 ) ,
( V_68 -> V_556 - 1 ) |
( ( V_68 -> V_560 - 1 ) << 16 ) ) ;
F_40 ( F_225 ( V_73 ) ,
( V_68 -> V_290 - 1 ) |
( ( V_553 - 1 ) << 16 ) ) ;
F_40 ( F_227 ( V_73 ) ,
( V_68 -> V_561 - 1 ) |
( ( V_554 - 1 ) << 16 ) ) ;
F_40 ( F_229 ( V_73 ) ,
( V_68 -> V_562 - 1 ) |
( ( V_68 -> V_563 - 1 ) << 16 ) ) ;
if ( F_72 ( V_2 ) && V_73 == V_564 &&
( V_71 == V_134 || V_71 == V_305 ) )
F_40 ( F_225 ( V_71 ) , F_4 ( F_225 ( V_73 ) ) ) ;
F_40 ( F_179 ( V_71 ) ,
( ( V_64 -> V_67 . V_453 - 1 ) << 16 ) |
( V_64 -> V_67 . V_565 - 1 ) ) ;
}
static void F_369 ( struct V_64 * V_21 ,
struct V_411 * V_412 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_70 V_73 = V_412 -> V_73 ;
T_4 V_566 ;
V_566 = F_4 ( F_219 ( V_73 ) ) ;
V_412 -> V_68 . V_289 = ( V_566 & 0xffff ) + 1 ;
V_412 -> V_68 . V_557 = ( ( V_566 >> 16 ) & 0xffff ) + 1 ;
V_566 = F_4 ( F_221 ( V_73 ) ) ;
V_412 -> V_68 . V_558 = ( V_566 & 0xffff ) + 1 ;
V_412 -> V_68 . V_559 = ( ( V_566 >> 16 ) & 0xffff ) + 1 ;
V_566 = F_4 ( F_223 ( V_73 ) ) ;
V_412 -> V_68 . V_556 = ( V_566 & 0xffff ) + 1 ;
V_412 -> V_68 . V_560 = ( ( V_566 >> 16 ) & 0xffff ) + 1 ;
V_566 = F_4 ( F_225 ( V_73 ) ) ;
V_412 -> V_68 . V_290 = ( V_566 & 0xffff ) + 1 ;
V_412 -> V_68 . V_553 = ( ( V_566 >> 16 ) & 0xffff ) + 1 ;
V_566 = F_4 ( F_227 ( V_73 ) ) ;
V_412 -> V_68 . V_561 = ( V_566 & 0xffff ) + 1 ;
V_412 -> V_68 . V_554 = ( ( V_566 >> 16 ) & 0xffff ) + 1 ;
V_566 = F_4 ( F_229 ( V_73 ) ) ;
V_412 -> V_68 . V_562 = ( V_566 & 0xffff ) + 1 ;
V_412 -> V_68 . V_563 = ( ( V_566 >> 16 ) & 0xffff ) + 1 ;
if ( F_4 ( F_45 ( V_73 ) ) & V_200 ) {
V_412 -> V_68 . V_332 |= V_555 ;
V_412 -> V_68 . V_553 += 1 ;
V_412 -> V_68 . V_554 += 1 ;
}
V_566 = F_4 ( F_179 ( V_21 -> V_71 ) ) ;
V_412 -> V_565 = ( V_566 & 0xffff ) + 1 ;
V_412 -> V_453 = ( ( V_566 >> 16 ) & 0xffff ) + 1 ;
V_412 -> V_567 . V_424 = V_412 -> V_565 ;
V_412 -> V_567 . V_422 = V_412 -> V_453 ;
}
static void F_370 ( struct V_64 * V_64 ,
struct V_411 * V_412 )
{
struct V_20 * V_21 = & V_64 -> V_108 ;
V_21 -> V_370 . V_422 = V_412 -> V_68 . V_289 ;
V_21 -> V_370 . V_568 = V_412 -> V_68 . V_557 ;
V_21 -> V_370 . V_454 = V_412 -> V_68 . V_556 ;
V_21 -> V_370 . V_569 = V_412 -> V_68 . V_560 ;
V_21 -> V_370 . V_424 = V_412 -> V_68 . V_290 ;
V_21 -> V_370 . V_570 = V_412 -> V_68 . V_553 ;
V_21 -> V_370 . V_571 = V_412 -> V_68 . V_562 ;
V_21 -> V_370 . V_572 = V_412 -> V_68 . V_563 ;
V_21 -> V_370 . V_332 = V_412 -> V_68 . V_332 ;
V_21 -> V_370 . clock = V_412 -> V_68 . V_69 ;
V_21 -> V_370 . V_332 |= V_412 -> V_68 . V_332 ;
}
static void F_371 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_573 ;
V_573 = 0 ;
if ( V_4 -> V_138 & V_139 &&
F_4 ( F_45 ( V_64 -> V_71 ) ) & V_140 )
V_573 |= V_140 ;
if ( V_64 -> V_67 . V_452 )
V_573 |= V_574 ;
if ( F_15 ( V_2 ) || F_17 ( V_2 ) ) {
if ( V_64 -> V_67 . V_575 && V_64 -> V_67 . V_445 != 30 )
V_573 |= V_576 |
V_577 ;
switch ( V_64 -> V_67 . V_445 ) {
case 18 :
V_573 |= V_578 ;
break;
case 24 :
V_573 |= V_579 ;
break;
case 30 :
V_573 |= V_580 ;
break;
default:
F_151 () ;
}
}
if ( F_372 ( V_2 ) ) {
if ( V_64 -> V_500 ) {
F_36 ( L_100 ) ;
V_573 |= V_581 ;
} else {
F_36 ( L_101 ) ;
}
}
if ( ! F_18 ( V_2 ) &&
V_64 -> V_67 . V_68 . V_332 & V_555 )
V_573 |= V_582 ;
else
V_573 |= V_583 ;
if ( F_17 ( V_2 ) && V_64 -> V_67 . V_584 )
V_573 |= V_585 ;
F_40 ( F_45 ( V_64 -> V_71 ) , V_573 ) ;
F_113 ( F_45 ( V_64 -> V_71 ) ) ;
}
static int F_373 ( struct V_20 * V_21 ,
int V_230 , int V_231 ,
struct V_237 * V_66 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
int V_10 , V_494 = 0 ;
T_2 clock , V_496 ;
T_1 V_241 ;
bool V_586 , V_587 = false ;
bool V_588 = false , V_419 = false ;
struct V_22 * V_23 ;
const T_3 * V_24 ;
int V_220 ;
F_10 (dev, crtc, encoder) {
switch ( V_23 -> type ) {
case V_25 :
V_588 = true ;
break;
case V_393 :
V_419 = true ;
break;
}
V_494 ++ ;
}
if ( V_419 )
goto V_589;
if ( ! V_64 -> V_67 . V_590 ) {
V_10 = F_331 ( V_21 , V_494 ) ;
V_24 = F_14 ( V_21 , V_10 ) ;
V_586 = V_4 -> V_269 . V_591 ( V_24 , V_21 ,
V_64 -> V_67 . V_524 ,
V_10 , NULL , & clock ) ;
if ( ! V_586 ) {
F_115 ( L_102 ) ;
return - V_225 ;
}
if ( V_588 && V_4 -> V_592 ) {
V_587 =
V_4 -> V_269 . V_591 ( V_24 , V_21 ,
V_4 -> V_593 ,
V_10 , & clock ,
& V_496 ) ;
}
V_64 -> V_67 . V_47 . V_18 = clock . V_18 ;
V_64 -> V_67 . V_47 . V_12 = clock . V_12 ;
V_64 -> V_67 . V_47 . V_13 = clock . V_13 ;
V_64 -> V_67 . V_47 . V_15 = clock . V_15 ;
V_64 -> V_67 . V_47 . V_16 = clock . V_16 ;
}
if ( F_18 ( V_2 ) ) {
F_367 ( V_64 ,
V_587 ? & V_496 : NULL ,
V_494 ) ;
} else if ( F_17 ( V_2 ) ) {
F_356 ( V_64 ) ;
} else {
F_363 ( V_64 ,
V_587 ? & V_496 : NULL ,
V_494 ) ;
}
V_589:
V_241 = V_594 ;
if ( ! F_17 ( V_2 ) ) {
if ( V_71 == 0 )
V_241 &= ~ V_145 ;
else
V_241 |= V_595 ;
}
F_368 ( V_64 ) ;
F_40 ( F_374 ( V_141 ) ,
( ( V_64 -> V_67 . V_565 - 1 ) << 16 ) |
( V_64 -> V_67 . V_453 - 1 ) ) ;
F_40 ( F_375 ( V_141 ) , 0 ) ;
F_371 ( V_64 ) ;
F_40 ( F_81 ( V_141 ) , V_241 ) ;
F_113 ( F_81 ( V_141 ) ) ;
V_220 = F_178 ( V_21 , V_230 , V_231 , V_66 ) ;
return V_220 ;
}
static void F_376 ( struct V_64 * V_21 ,
struct V_411 * V_412 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_566 ;
V_566 = F_4 ( V_415 ) ;
if ( ! ( V_566 & V_416 ) )
return;
if ( F_39 ( V_2 ) -> V_77 < 4 ) {
if ( V_21 -> V_71 != V_134 )
return;
} else {
if ( ( V_566 & V_596 ) != ( V_21 -> V_71 << V_597 ) )
return;
}
V_412 -> V_413 . V_414 = V_566 ;
V_412 -> V_413 . V_418 = F_4 ( V_417 ) ;
if ( F_39 ( V_2 ) -> V_77 < 5 )
V_412 -> V_413 . V_598 =
F_4 ( V_130 ) & V_599 ;
}
static void F_377 ( struct V_64 * V_21 ,
struct V_411 * V_412 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_412 -> V_73 ;
T_2 clock ;
T_1 V_506 ;
int V_10 = 100000 ;
F_53 ( & V_4 -> V_104 ) ;
V_506 = F_338 ( V_4 , V_71 , F_358 ( V_71 ) ) ;
F_55 ( & V_4 -> V_104 ) ;
clock . V_12 = ( V_506 >> V_515 ) & 7 ;
clock . V_13 = V_506 & V_516 ;
clock . V_18 = ( V_506 >> V_519 ) & 0xf ;
clock . V_15 = ( V_506 >> V_517 ) & 7 ;
clock . V_16 = ( V_506 >> V_518 ) & 0x1f ;
F_7 ( V_10 , & clock ) ;
V_412 -> V_524 = clock . V_19 / 5 ;
}
static bool F_378 ( struct V_64 * V_21 ,
struct V_411 * V_412 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_566 ;
V_412 -> V_73 = (enum V_70 ) V_21 -> V_71 ;
V_412 -> V_109 = V_375 ;
V_566 = F_4 ( F_45 ( V_21 -> V_71 ) ) ;
if ( ! ( V_566 & V_140 ) )
return false ;
if ( F_15 ( V_2 ) || F_17 ( V_2 ) ) {
switch ( V_566 & V_198 ) {
case V_578 :
V_412 -> V_445 = 18 ;
break;
case V_579 :
V_412 -> V_445 = 24 ;
break;
case V_580 :
V_412 -> V_445 = 30 ;
break;
default:
break;
}
}
if ( F_39 ( V_2 ) -> V_77 < 4 )
V_412 -> V_452 = V_566 & V_574 ;
F_369 ( V_21 , V_412 ) ;
F_376 ( V_21 , V_412 ) ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
V_566 = F_4 ( F_116 ( V_21 -> V_71 ) ) ;
V_412 -> V_529 =
( ( V_566 & V_600 )
>> V_530 ) + 1 ;
V_412 -> V_184 . V_186 = V_566 ;
} else if ( F_364 ( V_2 ) || F_365 ( V_2 ) || F_366 ( V_2 ) ) {
V_566 = F_4 ( F_51 ( V_21 -> V_71 ) ) ;
V_412 -> V_529 =
( ( V_566 & V_601 )
>> V_535 ) + 1 ;
} else {
V_412 -> V_529 = 1 ;
}
V_412 -> V_184 . V_47 = F_4 ( F_51 ( V_21 -> V_71 ) ) ;
if ( ! F_17 ( V_2 ) ) {
V_412 -> V_184 . V_499 = F_4 ( F_335 ( V_21 -> V_71 ) ) ;
V_412 -> V_184 . V_502 = F_4 ( F_336 ( V_21 -> V_71 ) ) ;
} else {
V_412 -> V_184 . V_47 &= ~ ( V_185 |
V_190 |
V_189 ) ;
}
if ( F_17 ( V_2 ) )
F_377 ( V_21 , V_412 ) ;
else
F_379 ( V_21 , V_412 ) ;
return true ;
}
static void F_380 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_602 * V_603 = & V_2 -> V_603 ;
struct V_22 * V_23 ;
T_1 V_101 , V_604 ;
bool V_605 = false ;
bool V_606 = false ;
bool V_607 = false ;
bool V_608 = false ;
bool V_609 = false ;
F_172 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_23 -> type ) {
case V_25 :
V_607 = true ;
V_605 = true ;
break;
case V_292 :
V_607 = true ;
if ( F_381 ( & V_23 -> V_108 ) -> V_87 == V_610 )
V_606 = true ;
break;
}
}
if ( F_48 ( V_2 ) ) {
V_608 = V_4 -> V_491 . V_611 ;
V_609 = V_608 ;
} else {
V_608 = false ;
V_609 = true ;
}
F_36 ( L_103 ,
V_607 , V_605 , V_608 ) ;
V_101 = F_4 ( V_151 ) ;
V_604 = V_101 ;
V_604 &= ~ V_153 ;
if ( V_608 )
V_604 |= V_612 ;
else
V_604 |= V_613 ;
V_604 &= ~ V_152 ;
V_604 &= ~ V_614 ;
V_604 &= ~ V_615 ;
if ( V_607 ) {
V_604 |= V_616 ;
if ( F_330 ( V_4 ) && V_609 )
V_604 |= V_615 ;
if ( V_606 ) {
if ( F_330 ( V_4 ) && V_609 )
V_604 |= V_617 ;
else
V_604 |= V_618 ;
} else
V_604 |= V_619 ;
} else {
V_604 |= V_620 ;
V_604 |= V_619 ;
}
if ( V_604 == V_101 )
return;
V_101 &= ~ V_153 ;
if ( V_608 )
V_101 |= V_612 ;
else
V_101 |= V_613 ;
if ( V_607 ) {
V_101 &= ~ V_152 ;
V_101 |= V_616 ;
if ( F_330 ( V_4 ) && V_609 ) {
F_36 ( L_104 ) ;
V_101 |= V_615 ;
} else
V_101 &= ~ V_615 ;
F_40 ( V_151 , V_101 ) ;
F_113 ( V_151 ) ;
F_114 ( 200 ) ;
V_101 &= ~ V_614 ;
if ( V_606 ) {
if ( F_330 ( V_4 ) && V_609 ) {
F_36 ( L_105 ) ;
V_101 |= V_617 ;
}
else
V_101 |= V_618 ;
} else
V_101 |= V_619 ;
F_40 ( V_151 , V_101 ) ;
F_113 ( V_151 ) ;
F_114 ( 200 ) ;
} else {
F_36 ( L_106 ) ;
V_101 &= ~ V_614 ;
V_101 |= V_619 ;
F_40 ( V_151 , V_101 ) ;
F_113 ( V_151 ) ;
F_114 ( 200 ) ;
V_101 &= ~ V_152 ;
V_101 |= V_620 ;
V_101 &= ~ V_615 ;
F_40 ( V_151 , V_101 ) ;
F_113 ( V_151 ) ;
F_114 ( 200 ) ;
}
F_110 ( V_101 != V_604 ) ;
}
static void F_382 ( struct V_3 * V_4 )
{
T_4 V_566 ;
V_566 = F_4 ( V_621 ) ;
V_566 |= V_622 ;
F_40 ( V_621 , V_566 ) ;
if ( F_383 ( F_4 ( V_621 ) &
V_623 , 100 ) )
F_115 ( L_107 ) ;
V_566 = F_4 ( V_621 ) ;
V_566 &= ~ V_622 ;
F_40 ( V_621 , V_566 ) ;
if ( F_383 ( ( F_4 ( V_621 ) &
V_623 ) == 0 , 100 ) )
F_115 ( L_108 ) ;
}
static void F_384 ( struct V_3 * V_4 )
{
T_4 V_566 ;
V_566 = F_212 ( V_4 , 0x8008 , V_624 ) ;
V_566 &= ~ ( 0xFF << 24 ) ;
V_566 |= ( 0x12 << 24 ) ;
F_211 ( V_4 , 0x8008 , V_566 , V_624 ) ;
V_566 = F_212 ( V_4 , 0x2008 , V_624 ) ;
V_566 |= ( 1 << 11 ) ;
F_211 ( V_4 , 0x2008 , V_566 , V_624 ) ;
V_566 = F_212 ( V_4 , 0x2108 , V_624 ) ;
V_566 |= ( 1 << 11 ) ;
F_211 ( V_4 , 0x2108 , V_566 , V_624 ) ;
V_566 = F_212 ( V_4 , 0x206C , V_624 ) ;
V_566 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_211 ( V_4 , 0x206C , V_566 , V_624 ) ;
V_566 = F_212 ( V_4 , 0x216C , V_624 ) ;
V_566 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_211 ( V_4 , 0x216C , V_566 , V_624 ) ;
V_566 = F_212 ( V_4 , 0x2080 , V_624 ) ;
V_566 &= ~ ( 7 << 13 ) ;
V_566 |= ( 5 << 13 ) ;
F_211 ( V_4 , 0x2080 , V_566 , V_624 ) ;
V_566 = F_212 ( V_4 , 0x2180 , V_624 ) ;
V_566 &= ~ ( 7 << 13 ) ;
V_566 |= ( 5 << 13 ) ;
F_211 ( V_4 , 0x2180 , V_566 , V_624 ) ;
V_566 = F_212 ( V_4 , 0x208C , V_624 ) ;
V_566 &= ~ 0xFF ;
V_566 |= 0x1C ;
F_211 ( V_4 , 0x208C , V_566 , V_624 ) ;
V_566 = F_212 ( V_4 , 0x218C , V_624 ) ;
V_566 &= ~ 0xFF ;
V_566 |= 0x1C ;
F_211 ( V_4 , 0x218C , V_566 , V_624 ) ;
V_566 = F_212 ( V_4 , 0x2098 , V_624 ) ;
V_566 &= ~ ( 0xFF << 16 ) ;
V_566 |= ( 0x1C << 16 ) ;
F_211 ( V_4 , 0x2098 , V_566 , V_624 ) ;
V_566 = F_212 ( V_4 , 0x2198 , V_624 ) ;
V_566 &= ~ ( 0xFF << 16 ) ;
V_566 |= ( 0x1C << 16 ) ;
F_211 ( V_4 , 0x2198 , V_566 , V_624 ) ;
V_566 = F_212 ( V_4 , 0x20C4 , V_624 ) ;
V_566 |= ( 1 << 27 ) ;
F_211 ( V_4 , 0x20C4 , V_566 , V_624 ) ;
V_566 = F_212 ( V_4 , 0x21C4 , V_624 ) ;
V_566 |= ( 1 << 27 ) ;
F_211 ( V_4 , 0x21C4 , V_566 , V_624 ) ;
V_566 = F_212 ( V_4 , 0x20EC , V_624 ) ;
V_566 &= ~ ( 0xF << 28 ) ;
V_566 |= ( 4 << 28 ) ;
F_211 ( V_4 , 0x20EC , V_566 , V_624 ) ;
V_566 = F_212 ( V_4 , 0x21EC , V_624 ) ;
V_566 &= ~ ( 0xF << 28 ) ;
V_566 |= ( 4 << 28 ) ;
F_211 ( V_4 , 0x21EC , V_566 , V_624 ) ;
}
static void F_385 ( struct V_1 * V_2 , bool V_625 ,
bool V_626 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_79 , V_566 ;
if ( F_46 ( V_626 && ! V_625 , L_109 ) )
V_625 = true ;
if ( F_46 ( V_4 -> V_627 == V_628 &&
V_626 , L_110 ) )
V_626 = false ;
F_53 ( & V_4 -> V_104 ) ;
V_566 = F_212 ( V_4 , V_629 , V_346 ) ;
V_566 &= ~ V_347 ;
V_566 |= V_630 ;
F_211 ( V_4 , V_629 , V_566 , V_346 ) ;
F_114 ( 24 ) ;
if ( V_625 ) {
V_566 = F_212 ( V_4 , V_629 , V_346 ) ;
V_566 &= ~ V_630 ;
F_211 ( V_4 , V_629 , V_566 , V_346 ) ;
if ( V_626 ) {
F_382 ( V_4 ) ;
F_384 ( V_4 ) ;
}
}
V_79 = ( V_4 -> V_627 == V_628 ) ?
V_631 : V_632 ;
V_566 = F_212 ( V_4 , V_79 , V_346 ) ;
V_566 |= V_633 ;
F_211 ( V_4 , V_79 , V_566 , V_346 ) ;
F_55 ( & V_4 -> V_104 ) ;
}
static void F_386 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_79 , V_566 ;
F_53 ( & V_4 -> V_104 ) ;
V_79 = ( V_4 -> V_627 == V_628 ) ?
V_631 : V_632 ;
V_566 = F_212 ( V_4 , V_79 , V_346 ) ;
V_566 &= ~ V_633 ;
F_211 ( V_4 , V_79 , V_566 , V_346 ) ;
V_566 = F_212 ( V_4 , V_629 , V_346 ) ;
if ( ! ( V_566 & V_347 ) ) {
if ( ! ( V_566 & V_630 ) ) {
V_566 |= V_630 ;
F_211 ( V_4 , V_629 , V_566 , V_346 ) ;
F_114 ( 32 ) ;
}
V_566 |= V_347 ;
F_211 ( V_4 , V_629 , V_566 , V_346 ) ;
}
F_55 ( & V_4 -> V_104 ) ;
}
static void F_387 ( struct V_1 * V_2 )
{
struct V_602 * V_603 = & V_2 -> V_603 ;
struct V_22 * V_23 ;
bool V_634 = false ;
F_172 (encoder, &mode_config->encoder_list, base.head) {
switch ( V_23 -> type ) {
case V_34 :
V_634 = true ;
break;
}
}
if ( V_634 )
F_385 ( V_2 , true , true ) ;
else
F_386 ( V_2 ) ;
}
void F_388 ( struct V_1 * V_2 )
{
if ( F_48 ( V_2 ) || F_94 ( V_2 ) )
F_380 ( V_2 ) ;
else if ( F_58 ( V_2 ) )
F_387 ( V_2 ) ;
}
static int F_389 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_23 ;
int V_494 = 0 ;
bool V_588 = false ;
F_10 (dev, crtc, encoder) {
switch ( V_23 -> type ) {
case V_25 :
V_588 = true ;
break;
}
V_494 ++ ;
}
if ( V_588 && F_330 ( V_4 ) && V_494 < 2 ) {
F_36 ( L_99 ,
V_4 -> V_491 . V_495 ) ;
return V_4 -> V_491 . V_495 * 1000 ;
}
return 120000 ;
}
static void F_390 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
T_4 V_101 ;
V_101 = 0 ;
switch ( V_64 -> V_67 . V_445 ) {
case 18 :
V_101 |= V_578 ;
break;
case 24 :
V_101 |= V_579 ;
break;
case 30 :
V_101 |= V_580 ;
break;
case 36 :
V_101 |= V_635 ;
break;
default:
F_151 () ;
}
if ( V_64 -> V_67 . V_575 )
V_101 |= ( V_576 | V_577 ) ;
if ( V_64 -> V_67 . V_68 . V_332 & V_555 )
V_101 |= V_201 ;
else
V_101 |= V_583 ;
if ( V_64 -> V_67 . V_584 )
V_101 |= V_585 ;
F_40 ( F_45 ( V_71 ) , V_101 ) ;
F_113 ( F_45 ( V_71 ) ) ;
}
static void F_391 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
T_6 V_636 = 0x7800 ;
if ( V_64 -> V_67 . V_584 )
V_636 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_40 ( F_392 ( V_71 ) , V_636 << 16 ) ;
F_40 ( F_393 ( V_71 ) , 0 ) ;
F_40 ( F_394 ( V_71 ) , V_636 ) ;
F_40 ( F_395 ( V_71 ) , 0 ) ;
F_40 ( F_396 ( V_71 ) , 0 ) ;
F_40 ( F_397 ( V_71 ) , V_636 << 16 ) ;
F_40 ( F_398 ( V_71 ) , 0 ) ;
F_40 ( F_399 ( V_71 ) , 0 ) ;
F_40 ( F_400 ( V_71 ) , 0 ) ;
if ( F_39 ( V_2 ) -> V_77 > 6 ) {
T_6 V_637 = 0 ;
if ( V_64 -> V_67 . V_584 )
V_637 = ( 16 * ( 1 << 12 ) / 255 ) & 0x1fff ;
F_40 ( F_401 ( V_71 ) , V_637 ) ;
F_40 ( F_402 ( V_71 ) , V_637 ) ;
F_40 ( F_403 ( V_71 ) , V_637 ) ;
F_40 ( F_404 ( V_71 ) , 0 ) ;
} else {
T_4 V_370 = V_638 ;
if ( V_64 -> V_67 . V_584 )
V_370 |= V_639 ;
F_40 ( F_404 ( V_71 ) , V_370 ) ;
}
}
static void F_405 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_71 V_71 = V_64 -> V_71 ;
enum V_70 V_73 = V_64 -> V_67 . V_73 ;
T_4 V_101 ;
V_101 = 0 ;
if ( F_72 ( V_2 ) && V_64 -> V_67 . V_575 )
V_101 |= ( V_576 | V_577 ) ;
if ( V_64 -> V_67 . V_68 . V_332 & V_555 )
V_101 |= V_201 ;
else
V_101 |= V_583 ;
F_40 ( F_45 ( V_73 ) , V_101 ) ;
F_113 ( F_45 ( V_73 ) ) ;
F_40 ( F_256 ( V_64 -> V_71 ) , V_640 ) ;
F_113 ( F_256 ( V_64 -> V_71 ) ) ;
if ( F_167 ( V_2 ) ) {
V_101 = 0 ;
switch ( V_64 -> V_67 . V_445 ) {
case 18 :
V_101 |= V_641 ;
break;
case 24 :
V_101 |= V_642 ;
break;
case 30 :
V_101 |= V_643 ;
break;
case 36 :
V_101 |= V_644 ;
break;
default:
F_151 () ;
}
if ( V_64 -> V_67 . V_575 )
V_101 |= V_645 | V_646 ;
F_40 ( F_406 ( V_71 ) , V_101 ) ;
}
}
static bool F_407 ( struct V_20 * V_21 ,
T_2 * clock ,
bool * V_587 ,
T_2 * V_496 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_22 ;
int V_10 ;
const T_3 * V_24 ;
bool V_220 , V_588 = false ;
F_10 (dev, crtc, intel_encoder) {
switch ( V_22 -> type ) {
case V_25 :
V_588 = true ;
break;
}
}
V_10 = F_389 ( V_21 ) ;
V_24 = F_14 ( V_21 , V_10 ) ;
V_220 = V_4 -> V_269 . V_591 ( V_24 , V_21 ,
F_30 ( V_21 ) -> V_67 . V_524 ,
V_10 , NULL , clock ) ;
if ( ! V_220 )
return false ;
if ( V_588 && V_4 -> V_592 ) {
* V_587 =
V_4 -> V_269 . V_591 ( V_24 , V_21 ,
V_4 -> V_593 ,
V_10 , clock ,
V_496 ) ;
}
return true ;
}
int F_312 ( int V_647 , int V_441 , int V_648 )
{
T_1 V_649 = V_647 * V_648 * 21 / 20 ;
return V_649 / ( V_441 * 8 ) + 1 ;
}
static bool F_408 ( struct V_47 * V_47 , int V_650 )
{
return F_20 ( V_47 ) < V_650 * V_47 -> V_18 ;
}
static T_4 F_409 ( struct V_64 * V_64 ,
T_1 * V_497 ,
T_2 * V_496 , T_1 * V_498 )
{
struct V_20 * V_21 = & V_64 -> V_108 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_22 ;
T_4 V_47 ;
int V_650 , V_494 = 0 ;
bool V_588 = false , V_532 = false ;
F_10 (dev, crtc, intel_encoder) {
switch ( V_22 -> type ) {
case V_25 :
V_588 = true ;
break;
case V_36 :
case V_33 :
V_532 = true ;
break;
}
V_494 ++ ;
}
V_650 = 21 ;
if ( V_588 ) {
if ( ( F_330 ( V_4 ) &&
V_4 -> V_491 . V_495 == 100 ) ||
( F_48 ( V_2 ) && F_12 ( V_2 ) ) )
V_650 = 25 ;
} else if ( V_64 -> V_67 . V_545 )
V_650 = 20 ;
if ( F_408 ( & V_64 -> V_67 . V_47 , V_650 ) )
* V_497 |= V_651 ;
if ( V_498 && ( V_496 -> V_11 < V_650 * V_496 -> V_18 ) )
* V_498 |= V_651 ;
V_47 = 0 ;
if ( V_588 )
V_47 |= V_533 ;
else
V_47 |= V_534 ;
V_47 |= ( V_64 -> V_67 . V_529 - 1 )
<< V_652 ;
if ( V_532 )
V_47 |= V_536 ;
if ( V_64 -> V_67 . V_531 )
V_47 |= V_536 ;
V_47 |= ( 1 << ( V_64 -> V_67 . V_47 . V_15 - 1 ) ) << V_538 ;
V_47 |= ( 1 << ( V_64 -> V_67 . V_47 . V_15 - 1 ) ) << V_539 ;
switch ( V_64 -> V_67 . V_47 . V_16 ) {
case 5 :
V_47 |= V_540 ;
break;
case 7 :
V_47 |= V_541 ;
break;
case 10 :
V_47 |= V_542 ;
break;
case 14 :
V_47 |= V_543 ;
break;
}
if ( V_588 && F_330 ( V_4 ) && V_494 < 2 )
V_47 |= V_547 ;
else
V_47 |= V_548 ;
return V_47 | V_103 ;
}
static int F_410 ( struct V_20 * V_21 ,
int V_230 , int V_231 ,
struct V_237 * V_66 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
int V_494 = 0 ;
T_2 clock , V_496 ;
T_1 V_47 = 0 , V_497 = 0 , V_498 = 0 ;
bool V_586 , V_587 = false ;
bool V_588 = false ;
struct V_22 * V_23 ;
struct V_107 * V_111 ;
int V_220 ;
F_10 (dev, crtc, encoder) {
switch ( V_23 -> type ) {
case V_25 :
V_588 = true ;
break;
}
V_494 ++ ;
}
F_46 ( ! ( F_48 ( V_2 ) || F_94 ( V_2 ) ) ,
L_111 , F_411 ( V_2 ) ) ;
V_586 = F_407 ( V_21 , & clock ,
& V_587 , & V_496 ) ;
if ( ! V_586 && ! V_64 -> V_67 . V_590 ) {
F_115 ( L_102 ) ;
return - V_225 ;
}
if ( ! V_64 -> V_67 . V_590 ) {
V_64 -> V_67 . V_47 . V_18 = clock . V_18 ;
V_64 -> V_67 . V_47 . V_12 = clock . V_12 ;
V_64 -> V_67 . V_47 . V_13 = clock . V_13 ;
V_64 -> V_67 . V_47 . V_15 = clock . V_15 ;
V_64 -> V_67 . V_47 . V_16 = clock . V_16 ;
}
if ( V_64 -> V_67 . V_302 ) {
V_497 = F_333 ( & V_64 -> V_67 . V_47 ) ;
if ( V_587 )
V_498 = F_333 ( & V_496 ) ;
V_47 = F_409 ( V_64 ,
& V_497 , & V_496 ,
V_587 ? & V_498 : NULL ) ;
V_64 -> V_67 . V_184 . V_47 = V_47 ;
V_64 -> V_67 . V_184 . V_499 = V_497 ;
if ( V_587 )
V_64 -> V_67 . V_184 . V_502 = V_498 ;
else
V_64 -> V_67 . V_184 . V_502 = V_497 ;
V_111 = F_242 ( V_64 ) ;
if ( V_111 == NULL ) {
F_59 ( L_112 ,
F_69 ( V_71 ) ) ;
return - V_225 ;
}
} else
F_241 ( V_64 ) ;
if ( V_64 -> V_67 . V_531 )
F_355 ( V_64 ) ;
if ( V_588 && V_587 && V_501 )
V_64 -> V_500 = true ;
else
V_64 -> V_500 = false ;
F_368 ( V_64 ) ;
if ( V_64 -> V_67 . V_302 ) {
F_347 ( V_64 ,
& V_64 -> V_67 . V_446 ) ;
}
F_390 ( V_21 ) ;
F_40 ( F_81 ( V_141 ) , V_594 ) ;
F_113 ( F_81 ( V_141 ) ) ;
V_220 = F_178 ( V_21 , V_230 , V_231 , V_66 ) ;
return V_220 ;
}
static void F_412 ( struct V_64 * V_21 ,
struct V_483 * V_484 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_71 V_71 = V_21 -> V_71 ;
V_484 -> V_488 = F_4 ( F_345 ( V_71 ) ) ;
V_484 -> V_489 = F_4 ( F_346 ( V_71 ) ) ;
V_484 -> V_486 = F_4 ( F_342 ( V_71 ) )
& ~ V_359 ;
V_484 -> V_487 = F_4 ( F_344 ( V_71 ) ) ;
V_484 -> V_485 = ( ( F_4 ( F_342 ( V_71 ) )
& V_359 ) >> V_653 ) + 1 ;
}
static void F_413 ( struct V_64 * V_21 ,
enum V_70 V_70 ,
struct V_483 * V_484 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_71 V_71 = V_21 -> V_71 ;
if ( F_39 ( V_2 ) -> V_77 >= 5 ) {
V_484 -> V_488 = F_4 ( F_349 ( V_70 ) ) ;
V_484 -> V_489 = F_4 ( F_350 ( V_70 ) ) ;
V_484 -> V_486 = F_4 ( F_236 ( V_70 ) )
& ~ V_359 ;
V_484 -> V_487 = F_4 ( F_348 ( V_70 ) ) ;
V_484 -> V_485 = ( ( F_4 ( F_236 ( V_70 ) )
& V_359 ) >> V_653 ) + 1 ;
} else {
V_484 -> V_488 = F_4 ( F_353 ( V_71 ) ) ;
V_484 -> V_489 = F_4 ( F_354 ( V_71 ) ) ;
V_484 -> V_486 = F_4 ( F_351 ( V_71 ) )
& ~ V_359 ;
V_484 -> V_487 = F_4 ( F_352 ( V_71 ) ) ;
V_484 -> V_485 = ( ( F_4 ( F_351 ( V_71 ) )
& V_359 ) >> V_653 ) + 1 ;
}
}
void F_414 ( struct V_64 * V_21 ,
struct V_411 * V_412 )
{
if ( V_21 -> V_67 . V_302 )
F_412 ( V_21 , & V_412 -> V_505 ) ;
else
F_413 ( V_21 , V_412 -> V_73 ,
& V_412 -> V_505 ) ;
}
static void F_415 ( struct V_64 * V_21 ,
struct V_411 * V_412 )
{
F_413 ( V_21 , V_412 -> V_73 ,
& V_412 -> V_446 ) ;
}
static void F_416 ( struct V_64 * V_21 ,
struct V_411 * V_412 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_566 ;
V_566 = F_4 ( F_180 ( V_21 -> V_71 ) ) ;
if ( V_566 & V_380 ) {
V_412 -> V_291 . V_99 = true ;
V_412 -> V_291 . V_382 = F_4 ( F_181 ( V_21 -> V_71 ) ) ;
V_412 -> V_291 . V_383 = F_4 ( F_182 ( V_21 -> V_71 ) ) ;
if ( F_417 ( V_2 ) ) {
F_2 ( ( V_566 & V_654 ) !=
F_245 ( V_21 -> V_71 ) ) ;
}
}
}
static bool F_418 ( struct V_64 * V_21 ,
struct V_411 * V_412 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_566 ;
V_412 -> V_73 = (enum V_70 ) V_21 -> V_71 ;
V_412 -> V_109 = V_375 ;
V_566 = F_4 ( F_45 ( V_21 -> V_71 ) ) ;
if ( ! ( V_566 & V_140 ) )
return false ;
switch ( V_566 & V_198 ) {
case V_578 :
V_412 -> V_445 = 18 ;
break;
case V_579 :
V_412 -> V_445 = 24 ;
break;
case V_580 :
V_412 -> V_445 = 30 ;
break;
case V_635 :
V_412 -> V_445 = 36 ;
break;
default:
break;
}
if ( F_4 ( F_92 ( V_21 -> V_71 ) ) & V_155 ) {
struct V_107 * V_111 ;
V_412 -> V_302 = true ;
V_566 = F_4 ( F_65 ( V_21 -> V_71 ) ) ;
V_412 -> V_312 = ( ( V_311 & V_566 ) >>
V_655 ) + 1 ;
F_415 ( V_21 , V_412 ) ;
if ( F_48 ( V_4 -> V_2 ) ) {
V_412 -> V_109 =
(enum V_376 ) V_21 -> V_71 ;
} else {
V_566 = F_4 ( V_362 ) ;
if ( V_566 & F_238 ( V_21 -> V_71 ) )
V_412 -> V_109 = V_363 ;
else
V_412 -> V_109 = V_656 ;
}
V_111 = & V_4 -> V_110 [ V_412 -> V_109 ] ;
F_2 ( ! V_111 -> V_114 ( V_4 , V_111 ,
& V_412 -> V_184 ) ) ;
V_566 = V_412 -> V_184 . V_47 ;
V_412 -> V_529 =
( ( V_566 & V_657 )
>> V_652 ) + 1 ;
F_419 ( V_21 , V_412 ) ;
} else {
V_412 -> V_529 = 1 ;
}
F_369 ( V_21 , V_412 ) ;
F_416 ( V_21 , V_412 ) ;
return true ;
}
static void F_420 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_658 * V_659 = & V_4 -> V_660 ;
struct V_64 * V_21 ;
unsigned long V_661 ;
T_4 V_101 ;
F_172 (crtc, &dev->mode_config.crtc_list, base.head)
F_46 ( V_21 -> V_65 , L_113 ,
F_69 ( V_21 -> V_71 ) ) ;
F_46 ( F_4 ( V_662 ) , L_114 ) ;
F_46 ( V_659 -> V_663 , L_115 ) ;
F_46 ( V_659 -> V_664 , L_116 ) ;
F_46 ( V_659 -> V_665 , L_117 ) ;
F_46 ( F_4 ( V_666 ) & V_667 , L_118 ) ;
F_46 ( F_4 ( V_668 ) & V_669 ,
L_119 ) ;
F_46 ( F_4 ( V_670 ) & V_669 ,
L_120 ) ;
F_46 ( F_4 ( V_671 ) & V_672 ,
L_121 ) ;
F_46 ( F_4 ( V_673 ) & V_674 ,
L_122 ) ;
F_46 ( F_4 ( V_675 ) & V_676 , L_123 ) ;
F_205 ( & V_4 -> V_677 , V_661 ) ;
V_101 = F_4 ( V_678 ) ;
F_46 ( ( V_101 & ~ V_679 ) != V_101 ,
L_124 , V_101 ) ;
V_101 = F_4 ( V_680 ) ;
F_46 ( ( V_101 | V_681 ) != 0xffffffff ,
L_125 , V_101 ) ;
F_206 ( & V_4 -> V_677 , V_661 ) ;
}
static void F_421 ( struct V_3 * V_4 ,
bool V_682 , bool V_683 )
{
T_4 V_101 ;
F_420 ( V_4 ) ;
V_101 = F_4 ( V_684 ) ;
if ( V_682 ) {
V_101 |= V_685 ;
F_40 ( V_684 , V_101 ) ;
if ( F_383 ( F_4 ( V_684 ) &
V_686 , 1 ) )
F_115 ( L_126 ) ;
V_101 = F_4 ( V_684 ) ;
}
V_101 |= V_687 ;
F_40 ( V_684 , V_101 ) ;
F_113 ( V_684 ) ;
if ( F_34 ( ( F_4 ( V_684 ) & V_688 ) == 0 , 1 ) )
F_115 ( L_127 ) ;
V_101 = F_4 ( V_689 ) ;
V_101 |= V_690 ;
F_53 ( & V_4 -> V_386 . V_387 ) ;
if ( F_251 ( V_4 , V_691 , V_101 ) )
F_115 ( L_128 ) ;
F_55 ( & V_4 -> V_386 . V_387 ) ;
F_113 ( V_689 ) ;
F_422 ( 100 ) ;
if ( F_34 ( ( F_4 ( V_689 ) & V_692 ) == 0 , 1 ) )
F_115 ( L_129 ) ;
if ( V_683 ) {
V_101 = F_4 ( V_684 ) ;
V_101 |= V_693 ;
F_40 ( V_684 , V_101 ) ;
F_113 ( V_684 ) ;
}
}
static void F_423 ( struct V_3 * V_4 )
{
T_4 V_101 ;
V_101 = F_4 ( V_684 ) ;
if ( ( V_101 & ( V_688 | V_687 | V_685 |
V_693 ) ) == V_688 )
return;
F_424 ( V_4 ) ;
if ( V_101 & V_693 ) {
V_101 &= ~ V_693 ;
F_40 ( V_684 , V_101 ) ;
F_113 ( V_684 ) ;
}
V_101 = F_4 ( V_689 ) ;
V_101 |= V_694 ;
V_101 &= ~ V_690 ;
F_53 ( & V_4 -> V_386 . V_387 ) ;
if ( F_251 ( V_4 , V_691 , V_101 ) )
F_115 ( L_130 ) ;
F_55 ( & V_4 -> V_386 . V_387 ) ;
F_113 ( V_689 ) ;
V_101 = F_4 ( V_684 ) ;
V_101 &= ~ V_687 ;
F_40 ( V_684 , V_101 ) ;
if ( F_34 ( F_4 ( V_684 ) & V_688 , 5 ) )
F_115 ( L_131 ) ;
if ( V_101 & V_685 ) {
V_101 = F_4 ( V_684 ) ;
V_101 &= ~ V_685 ;
F_40 ( V_684 , V_101 ) ;
if ( F_383 ( ( F_4 ( V_684 ) &
V_686 ) == 0 , 1 ) )
F_115 ( L_132 ) ;
}
F_425 ( V_4 ) ;
}
void F_426 ( struct V_695 * V_696 )
{
struct V_3 * V_4 =
F_427 ( F_428 ( V_696 ) , struct V_3 ,
V_697 . V_698 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_101 ;
if ( V_4 -> V_697 . V_99 )
return;
F_36 ( L_133 ) ;
V_4 -> V_697 . V_99 = true ;
if ( V_4 -> V_627 == V_628 ) {
V_101 = F_4 ( V_699 ) ;
V_101 &= ~ V_700 ;
F_40 ( V_699 , V_101 ) ;
}
F_386 ( V_2 ) ;
F_429 ( V_2 ) ;
F_421 ( V_4 , true , true ) ;
}
static void F_430 ( struct V_3 * V_4 )
{
F_2 ( ! F_431 ( & V_4 -> V_697 . V_701 ) ) ;
F_46 ( V_4 -> V_697 . V_702 < 1 ,
L_134 , V_4 -> V_697 . V_702 ) ;
V_4 -> V_697 . V_702 -- ;
if ( V_4 -> V_697 . V_702 != 0 )
return;
F_432 ( & V_4 -> V_697 . V_698 ,
F_433 ( V_703 ) ) ;
}
static void F_434 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_101 ;
F_2 ( ! F_431 ( & V_4 -> V_697 . V_701 ) ) ;
F_46 ( V_4 -> V_697 . V_702 < 0 ,
L_134 , V_4 -> V_697 . V_702 ) ;
V_4 -> V_697 . V_702 ++ ;
if ( V_4 -> V_697 . V_702 != 1 )
return;
F_435 ( & V_4 -> V_697 . V_698 ) ;
if ( ! V_4 -> V_697 . V_99 )
return;
F_36 ( L_135 ) ;
F_423 ( V_4 ) ;
F_436 ( V_2 ) ;
F_387 ( V_2 ) ;
if ( V_4 -> V_627 == V_628 ) {
V_101 = F_4 ( V_699 ) ;
V_101 |= V_700 ;
F_40 ( V_699 , V_101 ) ;
}
F_437 ( V_2 ) ;
F_438 ( V_2 ) ;
F_53 ( & V_4 -> V_386 . V_387 ) ;
F_439 ( V_2 ) ;
F_55 ( & V_4 -> V_386 . V_387 ) ;
V_4 -> V_697 . V_99 = false ;
}
void F_440 ( struct V_3 * V_4 )
{
if ( ! F_441 ( V_4 -> V_2 ) )
return;
F_53 ( & V_4 -> V_697 . V_701 ) ;
F_430 ( V_4 ) ;
F_55 ( & V_4 -> V_697 . V_701 ) ;
}
void F_442 ( struct V_3 * V_4 )
{
if ( ! F_441 ( V_4 -> V_2 ) )
return;
F_53 ( & V_4 -> V_697 . V_701 ) ;
F_434 ( V_4 ) ;
F_55 ( & V_4 -> V_697 . V_701 ) ;
}
static bool F_443 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_64 * V_21 ;
T_4 V_101 ;
F_172 (crtc, &dev->mode_config.crtc_list, base.head)
if ( V_21 -> V_108 . V_99 )
return false ;
V_101 = F_4 ( V_662 ) ;
if ( V_101 != 0 ) {
F_36 ( L_136 ) ;
return false ;
}
return true ;
}
static void F_444 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_704 ;
if ( ! F_441 ( V_4 -> V_2 ) )
return;
if ( ! V_705 )
return;
F_53 ( & V_4 -> V_697 . V_701 ) ;
V_704 = F_443 ( V_4 ) ;
if ( V_704 == V_4 -> V_697 . V_706 )
goto V_707;
V_4 -> V_697 . V_706 = V_704 ;
if ( V_704 )
F_430 ( V_4 ) ;
else
F_434 ( V_4 ) ;
V_707:
F_55 ( & V_4 -> V_697 . V_701 ) ;
}
static void F_445 ( struct V_3 * V_4 )
{
if ( ! F_441 ( V_4 -> V_2 ) )
return;
F_53 ( & V_4 -> V_697 . V_701 ) ;
if ( ! V_4 -> V_697 . V_708 ) {
V_4 -> V_697 . V_708 = true ;
F_430 ( V_4 ) ;
}
F_55 ( & V_4 -> V_697 . V_701 ) ;
}
static void F_446 ( struct V_3 * V_4 )
{
if ( ! F_441 ( V_4 -> V_2 ) )
return;
F_53 ( & V_4 -> V_697 . V_701 ) ;
if ( V_4 -> V_697 . V_708 ) {
V_4 -> V_697 . V_708 = false ;
F_434 ( V_4 ) ;
}
F_55 ( & V_4 -> V_697 . V_701 ) ;
}
static unsigned long F_447 ( struct V_1 * V_2 ,
enum V_71 V_71 , bool V_709 )
{
unsigned long V_710 ;
enum V_70 V_70 ;
V_70 = F_31 ( V_2 -> V_5 , V_71 ) ;
V_710 = F_448 ( F_449 ( V_71 ) ) ;
V_710 |= F_448 ( F_79 ( V_70 ) ) ;
if ( V_709 )
V_710 |= F_448 ( F_450 ( V_71 ) ) ;
return V_710 ;
}
void F_451 ( struct V_1 * V_2 , bool V_194 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_711 . V_712 == V_194 )
return;
if ( V_194 )
F_452 ( V_2 , V_713 ) ;
else
F_453 ( V_2 , V_713 ) ;
V_4 -> V_711 . V_712 = V_194 ;
}
static void F_454 ( struct V_1 * V_2 )
{
unsigned long V_714 [ V_715 ] = { 0 , } ;
struct V_64 * V_21 ;
F_172 (crtc, &dev->mode_config.crtc_list, base.head) {
enum V_716 V_717 ;
if ( ! V_21 -> V_108 . V_99 )
continue;
V_714 [ V_21 -> V_71 ] = F_447 ( V_2 ,
V_21 -> V_71 ,
V_21 -> V_67 . V_291 . V_99 ) ;
F_455 (domain, pipe_domains[crtc->pipe])
F_452 ( V_2 , V_717 ) ;
}
F_172 (crtc, &dev->mode_config.crtc_list, base.head) {
enum V_716 V_717 ;
F_455 (domain, crtc->enabled_power_domains)
F_453 ( V_2 , V_717 ) ;
V_21 -> V_718 = V_714 [ V_21 -> V_71 ] ;
}
F_451 ( V_2 , false ) ;
}
static void F_456 ( struct V_1 * V_2 )
{
F_454 ( V_2 ) ;
F_444 ( V_2 ) ;
}
static int F_457 ( struct V_20 * V_21 ,
int V_230 , int V_231 ,
struct V_237 * V_66 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_141 = V_64 -> V_141 ;
int V_220 ;
if ( ! F_458 ( V_21 ) )
return - V_225 ;
if ( V_64 -> V_67 . V_531 )
F_355 ( V_64 ) ;
V_64 -> V_500 = false ;
F_368 ( V_64 ) ;
if ( V_64 -> V_67 . V_302 ) {
F_347 ( V_64 ,
& V_64 -> V_67 . V_446 ) ;
}
F_405 ( V_21 ) ;
F_391 ( V_21 ) ;
F_40 ( F_81 ( V_141 ) , V_594 | V_719 ) ;
F_113 ( F_81 ( V_141 ) ) ;
V_220 = F_178 ( V_21 , V_230 , V_231 , V_66 ) ;
return V_220 ;
}
static bool F_459 ( struct V_64 * V_21 ,
struct V_411 * V_412 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_716 V_720 ;
T_4 V_566 ;
V_412 -> V_73 = (enum V_70 ) V_21 -> V_71 ;
V_412 -> V_109 = V_375 ;
V_566 = F_4 ( F_62 ( V_564 ) ) ;
if ( V_566 & V_116 ) {
enum V_71 V_721 ;
switch ( V_566 & V_722 ) {
default:
F_46 ( 1 , L_137 ) ;
case V_723 :
case V_724 :
V_721 = V_125 ;
break;
case V_725 :
V_721 = V_134 ;
break;
case V_726 :
V_721 = V_305 ;
break;
}
if ( V_721 == V_21 -> V_71 )
V_412 -> V_73 = V_564 ;
}
if ( ! F_78 ( V_2 ,
F_79 ( V_412 -> V_73 ) ) )
return false ;
V_566 = F_4 ( F_45 ( V_412 -> V_73 ) ) ;
if ( ! ( V_566 & V_140 ) )
return false ;
V_566 = F_4 ( F_62 ( V_412 -> V_73 ) ) ;
if ( ( V_566 & V_727 ) == F_460 ( V_728 ) &&
F_4 ( V_209 ) & V_155 ) {
V_412 -> V_302 = true ;
V_566 = F_4 ( F_65 ( V_125 ) ) ;
V_412 -> V_312 = ( ( V_311 & V_566 ) >>
V_655 ) + 1 ;
F_415 ( V_21 , V_412 ) ;
}
F_369 ( V_21 , V_412 ) ;
V_720 = F_450 ( V_21 -> V_71 ) ;
if ( F_78 ( V_2 , V_720 ) )
F_416 ( V_21 , V_412 ) ;
V_412 -> V_385 = F_262 ( V_21 ) &&
( F_4 ( V_389 ) & V_390 ) ;
V_412 -> V_529 = 1 ;
return true ;
}
static int F_461 ( struct V_20 * V_21 ,
int V_230 , int V_231 ,
struct V_237 * V_66 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_23 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_288 * V_370 = & V_64 -> V_67 . V_567 ;
int V_71 = V_64 -> V_71 ;
int V_220 ;
F_462 ( V_2 , V_71 ) ;
V_220 = V_4 -> V_269 . V_729 ( V_21 , V_230 , V_231 , V_66 ) ;
F_463 ( V_2 , V_71 ) ;
if ( V_220 != 0 )
return V_220 ;
F_10 (dev, crtc, encoder) {
F_36 ( L_138 ,
V_23 -> V_108 . V_108 . V_193 ,
F_464 ( & V_23 -> V_108 ) ,
V_370 -> V_108 . V_193 , V_370 -> V_115 ) ;
V_23 -> V_378 ( V_23 ) ;
}
return 0 ;
}
static T_1 F_465 ( struct V_288 * V_370 )
{
int V_143 ;
for ( V_143 = 0 ; V_143 < F_198 ( V_730 ) ; V_143 ++ ) {
if ( V_370 -> clock == V_730 [ V_143 ] . clock )
break;
}
if ( V_143 == F_198 ( V_730 ) ) {
F_36 ( L_139 , V_370 -> clock ) ;
V_143 = 1 ;
}
F_36 ( L_140 ,
V_730 [ V_143 ] . clock ,
V_730 [ V_143 ] . V_67 ) ;
return V_730 [ V_143 ] . V_67 ;
}
static bool F_466 ( struct V_430 * V_431 ,
int V_731 , T_4 V_732 ,
int V_733 , T_4 V_734 ,
int V_735 )
{
struct V_3 * V_4 = V_431 -> V_2 -> V_5 ;
T_7 * V_736 = V_431 -> V_736 ;
T_4 V_143 ;
V_143 = F_4 ( V_731 ) ;
V_143 &= V_732 ;
if ( ! V_736 [ 0 ] )
return ! V_143 ;
if ( ! V_143 )
return false ;
V_143 = F_4 ( V_733 ) ;
V_143 &= ~ V_734 ;
F_40 ( V_733 , V_143 ) ;
for ( V_143 = 0 ; V_143 < V_736 [ 2 ] ; V_143 ++ )
if ( F_4 ( V_735 ) != * ( ( T_4 * ) V_736 + V_143 ) )
return false ;
return true ;
}
static void F_467 ( struct V_430 * V_431 ,
struct V_20 * V_21 ,
struct V_288 * V_370 )
{
struct V_3 * V_4 = V_431 -> V_2 -> V_5 ;
T_7 * V_736 = V_431 -> V_736 ;
T_4 V_737 ;
T_4 V_738 ;
T_4 V_143 ;
V_143 = F_4 ( V_739 ) ;
if ( V_143 == V_740 || V_143 == V_741 )
V_737 = V_742 ;
else
V_737 = V_743 ;
if ( F_466 ( V_431 ,
V_744 , V_737 ,
V_744 , V_745 ,
V_746 ) )
return;
V_143 = F_4 ( V_744 ) ;
V_143 &= ~ ( V_737 | V_745 ) ;
V_738 = ( V_143 >> 9 ) & 0x1f ;
F_40 ( V_744 , V_143 ) ;
if ( ! V_736 [ 0 ] )
return;
V_738 = F_329 ( T_7 , V_736 [ 2 ] , V_738 ) ;
F_59 ( L_141 , V_738 ) ;
for ( V_143 = 0 ; V_143 < V_738 ; V_143 ++ )
F_40 ( V_746 , * ( ( T_4 * ) V_736 + V_143 ) ) ;
V_143 = F_4 ( V_744 ) ;
V_143 |= V_737 ;
F_40 ( V_744 , V_143 ) ;
}
static void F_468 ( struct V_430 * V_431 ,
struct V_20 * V_21 ,
struct V_288 * V_370 )
{
struct V_3 * V_4 = V_431 -> V_2 -> V_5 ;
T_7 * V_736 = V_431 -> V_736 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
T_4 V_737 ;
T_4 V_143 ;
int V_738 ;
int V_71 = F_30 ( V_21 ) -> V_71 ;
int V_566 ;
int V_747 = F_469 ( V_71 ) ;
int V_748 = F_470 ( V_71 ) ;
int V_749 = F_471 ( V_71 ) ;
int V_750 = V_751 ;
F_59 ( L_142 ) ;
F_59 ( L_143 ) ;
V_566 = F_4 ( V_750 ) ;
V_566 |= ( V_752 << ( V_71 * 4 ) ) ;
F_40 ( V_750 , V_566 ) ;
F_37 ( V_2 , V_71 ) ;
V_566 = F_4 ( V_750 ) ;
F_59 ( L_144 , V_566 ) ;
V_566 |= ( V_753 << ( V_71 * 4 ) ) ;
F_40 ( V_750 , V_566 ) ;
V_566 = F_4 ( V_750 ) ;
F_59 ( L_145 , V_566 ) ;
V_566 = F_4 ( V_749 ) ;
F_59 ( L_146 , V_566 ) ;
V_566 &= ~ ( V_754 | V_755 ) ;
F_40 ( V_749 , V_566 ) ;
F_59 ( L_147 , F_69 ( V_71 ) ) ;
V_737 = V_753 << ( V_71 * 4 ) ;
V_64 -> V_432 = true ;
if ( F_9 ( V_21 , V_364 ) ) {
F_59 ( L_148 ) ;
V_736 [ 5 ] |= ( 1 << 2 ) ;
F_40 ( V_749 , V_754 ) ;
} else {
F_40 ( V_749 , F_465 ( V_370 ) ) ;
}
if ( F_466 ( V_431 ,
V_750 , V_737 ,
V_748 , V_756 ,
V_747 ) )
return;
V_143 = F_4 ( V_750 ) ;
V_143 &= ~ V_737 ;
F_40 ( V_750 , V_143 ) ;
if ( ! V_736 [ 0 ] )
return;
V_143 = F_4 ( V_748 ) ;
V_143 &= ~ V_756 ;
F_40 ( V_748 , V_143 ) ;
V_143 = ( V_143 >> 29 ) & V_757 ;
F_59 ( L_149 , V_143 ) ;
V_738 = F_329 ( T_7 , V_736 [ 2 ] , 21 ) ;
F_59 ( L_141 , V_738 ) ;
for ( V_143 = 0 ; V_143 < V_738 ; V_143 ++ )
F_40 ( V_747 , * ( ( T_4 * ) V_736 + V_143 ) ) ;
V_143 = F_4 ( V_750 ) ;
V_143 |= V_737 ;
F_40 ( V_750 , V_143 ) ;
}
static void F_472 ( struct V_430 * V_431 ,
struct V_20 * V_21 ,
struct V_288 * V_370 )
{
struct V_3 * V_4 = V_431 -> V_2 -> V_5 ;
T_7 * V_736 = V_431 -> V_736 ;
T_4 V_737 ;
T_4 V_143 ;
int V_738 ;
int V_747 ;
int V_749 ;
int V_748 ;
int V_750 ;
int V_71 = F_30 ( V_21 ) -> V_71 ;
if ( F_48 ( V_431 -> V_2 ) ) {
V_747 = F_473 ( V_71 ) ;
V_749 = F_474 ( V_71 ) ;
V_748 = F_475 ( V_71 ) ;
V_750 = V_758 ;
} else if ( F_17 ( V_431 -> V_2 ) ) {
V_747 = F_476 ( V_71 ) ;
V_749 = F_477 ( V_71 ) ;
V_748 = F_478 ( V_71 ) ;
V_750 = V_759 ;
} else {
V_747 = F_479 ( V_71 ) ;
V_749 = F_480 ( V_71 ) ;
V_748 = F_481 ( V_71 ) ;
V_750 = V_760 ;
}
F_59 ( L_147 , F_69 ( V_71 ) ) ;
if ( F_17 ( V_431 -> V_2 ) ) {
struct V_22 * V_22 ;
struct V_86 * V_761 ;
V_22 = F_482 ( V_431 ) ;
V_761 = F_381 ( & V_22 -> V_108 ) ;
V_143 = V_761 -> V_87 ;
} else {
V_143 = F_4 ( V_748 ) ;
V_143 = ( V_143 >> 29 ) & V_757 ;
}
if ( ! V_143 ) {
F_59 ( L_150 ) ;
V_737 = V_762 ;
V_737 |= V_762 << 4 ;
V_737 |= V_762 << 8 ;
} else {
F_59 ( L_151 , F_483 ( V_143 ) ) ;
V_737 = V_762 << ( ( V_143 - 1 ) * 4 ) ;
}
if ( F_9 ( V_21 , V_364 ) ) {
F_59 ( L_148 ) ;
V_736 [ 5 ] |= ( 1 << 2 ) ;
F_40 ( V_749 , V_754 ) ;
} else {
F_40 ( V_749 , F_465 ( V_370 ) ) ;
}
if ( F_466 ( V_431 ,
V_750 , V_737 ,
V_748 , V_756 ,
V_747 ) )
return;
V_143 = F_4 ( V_750 ) ;
V_143 &= ~ V_737 ;
F_40 ( V_750 , V_143 ) ;
if ( ! V_736 [ 0 ] )
return;
V_143 = F_4 ( V_748 ) ;
V_143 &= ~ V_756 ;
F_40 ( V_748 , V_143 ) ;
V_738 = F_329 ( T_7 , V_736 [ 2 ] , 21 ) ;
F_59 ( L_141 , V_738 ) ;
for ( V_143 = 0 ; V_143 < V_738 ; V_143 ++ )
F_40 ( V_747 , * ( ( T_4 * ) V_736 + V_143 ) ) ;
V_143 = F_4 ( V_750 ) ;
V_143 |= V_737 ;
F_40 ( V_750 , V_143 ) ;
}
void F_484 ( struct V_436 * V_23 ,
struct V_288 * V_370 )
{
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_430 * V_431 ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_431 = F_485 ( V_23 , V_370 ) ;
if ( ! V_431 )
return;
F_59 ( L_152 ,
V_431 -> V_108 . V_193 ,
F_304 ( V_431 ) ,
V_431 -> V_23 -> V_108 . V_193 ,
F_464 ( V_431 -> V_23 ) ) ;
V_431 -> V_736 [ 6 ] = F_486 ( V_431 , V_370 ) / 2 ;
if ( V_4 -> V_269 . V_763 )
V_4 -> V_269 . V_763 ( V_431 , V_21 , V_370 ) ;
}
static void F_487 ( struct V_20 * V_21 , T_1 V_108 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
bool V_764 = V_108 != 0 ;
T_1 V_406 ;
if ( V_64 -> V_765 == V_764 )
return;
V_406 = F_4 ( V_136 ) ;
if ( V_764 ) {
F_40 ( V_766 , V_108 ) ;
V_406 &= ~ ( V_767 ) ;
V_406 |= V_137 |
V_768 |
V_769 ;
} else
V_406 &= ~ ( V_137 | V_768 ) ;
F_40 ( V_136 , V_406 ) ;
V_64 -> V_765 = V_764 ;
}
static void F_488 ( struct V_20 * V_21 , T_1 V_108 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
bool V_764 = V_108 != 0 ;
if ( V_64 -> V_765 != V_764 ) {
T_4 V_406 = F_4 ( F_76 ( V_71 ) ) ;
if ( V_108 ) {
V_406 &= ~ ( V_135 | V_770 ) ;
V_406 |= V_410 | V_771 ;
V_406 |= V_71 << 28 ;
} else {
V_406 &= ~ ( V_135 | V_771 ) ;
V_406 |= V_772 ;
}
F_40 ( F_76 ( V_71 ) , V_406 ) ;
V_64 -> V_765 = V_764 ;
}
F_113 ( F_76 ( V_71 ) ) ;
F_40 ( F_286 ( V_71 ) , V_108 ) ;
F_113 ( F_286 ( V_71 ) ) ;
}
static void F_489 ( struct V_20 * V_21 , T_1 V_108 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
bool V_764 = V_108 != 0 ;
if ( V_64 -> V_765 != V_764 ) {
T_4 V_406 = F_4 ( F_73 ( V_71 ) ) ;
if ( V_108 ) {
V_406 &= ~ V_135 ;
V_406 |= V_410 | V_771 ;
} else {
V_406 &= ~ ( V_135 | V_771 ) ;
V_406 |= V_772 ;
}
if ( F_72 ( V_2 ) || F_167 ( V_2 ) ) {
V_406 |= V_773 ;
V_406 &= ~ V_774 ;
}
F_40 ( F_73 ( V_71 ) , V_406 ) ;
V_64 -> V_765 = V_764 ;
}
F_113 ( F_73 ( V_71 ) ) ;
F_40 ( F_490 ( V_71 ) , V_108 ) ;
F_113 ( F_490 ( V_71 ) ) ;
}
static void F_261 ( struct V_20 * V_21 ,
bool V_192 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
int V_230 = V_64 -> V_775 ;
int V_231 = V_64 -> V_776 ;
T_1 V_108 = 0 , V_382 = 0 ;
bool V_764 ;
if ( V_192 )
V_108 = V_64 -> V_777 ;
if ( V_230 >= V_64 -> V_67 . V_453 )
V_108 = 0 ;
if ( V_231 >= V_64 -> V_67 . V_565 )
V_108 = 0 ;
if ( V_230 < 0 ) {
if ( V_230 + V_64 -> V_778 <= 0 )
V_108 = 0 ;
V_382 |= V_779 << V_780 ;
V_230 = - V_230 ;
}
V_382 |= V_230 << V_780 ;
if ( V_231 < 0 ) {
if ( V_231 + V_64 -> V_781 <= 0 )
V_108 = 0 ;
V_382 |= V_779 << V_782 ;
V_231 = - V_231 ;
}
V_382 |= V_231 << V_782 ;
V_764 = V_108 != 0 ;
if ( ! V_764 && ! V_64 -> V_765 )
return;
if ( F_71 ( V_2 ) || F_72 ( V_2 ) || F_167 ( V_2 ) ) {
F_40 ( F_491 ( V_71 ) , V_382 ) ;
F_489 ( V_21 , V_108 ) ;
} else {
F_40 ( F_492 ( V_71 ) , V_382 ) ;
if ( F_74 ( V_2 ) || F_75 ( V_2 ) )
F_487 ( V_21 , V_108 ) ;
else
F_488 ( V_21 , V_108 ) ;
}
}
static int F_493 ( struct V_20 * V_21 ,
struct V_783 * V_784 ,
T_4 V_785 ,
T_4 V_786 , T_4 V_787 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_215 * V_216 ;
T_4 V_788 ;
int V_220 ;
if ( ! V_785 ) {
F_36 ( L_153 ) ;
V_788 = 0 ;
V_216 = NULL ;
F_53 ( & V_2 -> V_286 ) ;
goto V_789;
}
if ( V_786 != 64 || V_787 != 64 ) {
F_115 ( L_154 ) ;
return - V_225 ;
}
V_216 = F_494 ( F_495 ( V_2 , V_784 , V_785 ) ) ;
if ( & V_216 -> V_108 == NULL )
return - V_790 ;
if ( V_216 -> V_108 . V_383 < V_786 * V_787 * 4 ) {
F_115 ( L_155 ) ;
V_220 = - V_791 ;
goto V_792;
}
F_53 ( & V_2 -> V_286 ) ;
if ( ! V_4 -> V_119 -> V_793 ) {
unsigned V_219 ;
if ( V_216 -> V_221 ) {
F_115 ( L_156 ) ;
V_220 = - V_225 ;
goto V_794;
}
V_219 = 0 ;
if ( F_146 ( V_2 ) )
V_219 = 64 * 1024 ;
V_220 = F_152 ( V_216 , V_219 , NULL ) ;
if ( V_220 ) {
F_115 ( L_157 ) ;
goto V_794;
}
V_220 = F_496 ( V_216 ) ;
if ( V_220 ) {
F_115 ( L_158 ) ;
goto V_795;
}
V_788 = F_161 ( V_216 ) ;
} else {
int V_796 = F_112 ( V_2 ) ? 16 * 1024 : 256 ;
V_220 = F_497 ( V_2 , V_216 ,
( V_64 -> V_71 == 0 ) ? V_797 : V_798 ,
V_796 ) ;
if ( V_220 ) {
F_115 ( L_159 ) ;
goto V_794;
}
V_788 = V_216 -> V_799 -> V_785 -> V_800 ;
}
if ( F_18 ( V_2 ) )
F_40 ( V_801 , ( V_787 << 12 ) | V_786 ) ;
V_789:
if ( V_64 -> V_802 ) {
if ( V_4 -> V_119 -> V_793 ) {
if ( V_64 -> V_802 != V_216 )
F_498 ( V_2 , V_64 -> V_802 ) ;
} else
F_155 ( V_64 -> V_802 ) ;
F_499 ( & V_64 -> V_802 -> V_108 ) ;
}
F_55 ( & V_2 -> V_286 ) ;
V_64 -> V_777 = V_788 ;
V_64 -> V_802 = V_216 ;
V_64 -> V_778 = V_786 ;
V_64 -> V_781 = V_787 ;
if ( V_64 -> V_65 )
F_261 ( V_21 , V_64 -> V_802 != NULL ) ;
return 0 ;
V_795:
F_155 ( V_216 ) ;
V_794:
F_55 ( & V_2 -> V_286 ) ;
V_792:
F_500 ( & V_216 -> V_108 ) ;
return V_220 ;
}
static int F_501 ( struct V_20 * V_21 , int V_230 , int V_231 )
{
struct V_64 * V_64 = F_30 ( V_21 ) ;
V_64 -> V_775 = F_502 ( int , V_230 , V_803 , V_804 ) ;
V_64 -> V_776 = F_502 ( int , V_231 , V_803 , V_804 ) ;
if ( V_64 -> V_65 )
F_261 ( V_21 , V_64 -> V_802 != NULL ) ;
return 0 ;
}
static void F_503 ( struct V_20 * V_21 , T_5 * V_805 , T_5 * V_806 ,
T_5 * V_807 , T_4 V_808 , T_4 V_383 )
{
int V_809 = ( V_808 + V_383 > 256 ) ? 256 : V_808 + V_383 , V_143 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
for ( V_143 = V_808 ; V_143 < V_809 ; V_143 ++ ) {
V_64 -> V_396 [ V_143 ] = V_805 [ V_143 ] >> 8 ;
V_64 -> V_397 [ V_143 ] = V_806 [ V_143 ] >> 8 ;
V_64 -> V_398 [ V_143 ] = V_807 [ V_143 ] >> 8 ;
}
F_253 ( V_21 ) ;
}
static struct V_237 *
F_504 ( struct V_1 * V_2 ,
struct V_810 * V_811 ,
struct V_215 * V_216 )
{
struct V_238 * V_239 ;
int V_220 ;
V_239 = F_505 ( sizeof( * V_239 ) , V_812 ) ;
if ( ! V_239 ) {
F_500 ( & V_216 -> V_108 ) ;
return F_506 ( - V_791 ) ;
}
V_220 = F_507 ( V_2 ) ;
if ( V_220 )
goto V_53;
V_220 = F_508 ( V_2 , V_239 , V_811 , V_216 ) ;
F_55 ( & V_2 -> V_286 ) ;
if ( V_220 )
goto V_53;
return & V_239 -> V_108 ;
V_53:
F_500 ( & V_216 -> V_108 ) ;
F_301 ( V_239 ) ;
return F_506 ( V_220 ) ;
}
static T_1
F_509 ( int V_786 , int V_648 )
{
T_1 V_233 = F_510 ( V_786 * V_648 , 8 ) ;
return F_511 ( V_233 , 64 ) ;
}
static T_1
F_512 ( struct V_288 * V_370 , int V_648 )
{
T_1 V_233 = F_509 ( V_370 -> V_422 , V_648 ) ;
return F_511 ( V_233 * V_370 -> V_424 , V_813 ) ;
}
static struct V_237 *
F_513 ( struct V_1 * V_2 ,
struct V_288 * V_370 ,
int V_814 , int V_648 )
{
struct V_215 * V_216 ;
struct V_810 V_811 = { 0 } ;
V_216 = F_514 ( V_2 ,
F_512 ( V_370 , V_648 ) ) ;
if ( V_216 == NULL )
return F_506 ( - V_791 ) ;
V_811 . V_786 = V_370 -> V_422 ;
V_811 . V_787 = V_370 -> V_424 ;
V_811 . V_265 [ 0 ] = F_509 ( V_811 . V_786 ,
V_648 ) ;
V_811 . V_243 = F_515 ( V_648 , V_814 ) ;
return F_504 ( V_2 , & V_811 , V_216 ) ;
}
static struct V_237 *
F_516 ( struct V_1 * V_2 ,
struct V_288 * V_370 )
{
#ifdef F_517
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_215 * V_216 ;
struct V_237 * V_66 ;
if ( V_4 -> V_815 == NULL )
return NULL ;
V_216 = V_4 -> V_815 -> V_816 . V_216 ;
if ( V_216 == NULL )
return NULL ;
V_66 = & V_4 -> V_815 -> V_816 . V_108 ;
if ( V_66 -> V_265 [ 0 ] < F_509 ( V_370 -> V_422 ,
V_66 -> V_266 ) )
return NULL ;
if ( V_216 -> V_108 . V_383 < V_370 -> V_424 * V_66 -> V_265 [ 0 ] )
return NULL ;
return V_66 ;
#else
return NULL ;
#endif
}
bool F_518 ( struct V_430 * V_431 ,
struct V_288 * V_370 ,
struct V_817 * V_818 )
{
struct V_64 * V_64 ;
struct V_22 * V_22 =
F_482 ( V_431 ) ;
struct V_20 * V_819 ;
struct V_436 * V_23 = & V_22 -> V_108 ;
struct V_20 * V_21 = NULL ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_237 * V_66 ;
int V_143 = - 1 ;
F_36 ( L_160 ,
V_431 -> V_108 . V_193 , F_304 ( V_431 ) ,
V_23 -> V_108 . V_193 , F_464 ( V_23 ) ) ;
if ( V_23 -> V_21 ) {
V_21 = V_23 -> V_21 ;
F_53 ( & V_21 -> V_272 ) ;
V_818 -> V_820 = V_431 -> V_434 ;
V_818 -> V_821 = false ;
if ( V_431 -> V_434 != V_437 )
V_431 -> V_822 -> V_434 ( V_431 , V_437 ) ;
return true ;
}
F_172 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_143 ++ ;
if ( ! ( V_23 -> V_823 & ( 1 << V_143 ) ) )
continue;
if ( ! V_819 -> V_99 ) {
V_21 = V_819 ;
break;
}
}
if ( ! V_21 ) {
F_36 ( L_161 ) ;
return false ;
}
F_53 ( & V_21 -> V_272 ) ;
V_22 -> V_824 = F_30 ( V_21 ) ;
F_519 ( V_431 ) -> V_825 = V_22 ;
V_64 = F_30 ( V_21 ) ;
V_818 -> V_820 = V_431 -> V_434 ;
V_818 -> V_821 = true ;
V_818 -> V_826 = NULL ;
if ( ! V_370 )
V_370 = & V_827 ;
V_66 = F_516 ( V_2 , V_370 ) ;
if ( V_66 == NULL ) {
F_36 ( L_162 ) ;
V_66 = F_513 ( V_2 , V_370 , 24 , 32 ) ;
V_818 -> V_826 = V_66 ;
} else
F_36 ( L_163 ) ;
if ( F_520 ( V_66 ) ) {
F_36 ( L_164 ) ;
F_55 ( & V_21 -> V_272 ) ;
return false ;
}
if ( F_521 ( V_21 , V_370 , 0 , 0 , V_66 ) ) {
F_36 ( L_165 ) ;
if ( V_818 -> V_826 )
V_818 -> V_826 -> V_822 -> V_828 ( V_818 -> V_826 ) ;
F_55 ( & V_21 -> V_272 ) ;
return false ;
}
F_37 ( V_2 , V_64 -> V_71 ) ;
return true ;
}
void F_522 ( struct V_430 * V_431 ,
struct V_817 * V_818 )
{
struct V_22 * V_22 =
F_482 ( V_431 ) ;
struct V_436 * V_23 = & V_22 -> V_108 ;
struct V_20 * V_21 = V_23 -> V_21 ;
F_36 ( L_160 ,
V_431 -> V_108 . V_193 , F_304 ( V_431 ) ,
V_23 -> V_108 . V_193 , F_464 ( V_23 ) ) ;
if ( V_818 -> V_821 ) {
F_519 ( V_431 ) -> V_825 = NULL ;
V_22 -> V_824 = NULL ;
F_521 ( V_21 , NULL , 0 , 0 , NULL ) ;
if ( V_818 -> V_826 ) {
F_523 ( V_818 -> V_826 ) ;
F_524 ( V_818 -> V_826 ) ;
}
F_55 ( & V_21 -> V_272 ) ;
return;
}
if ( V_818 -> V_820 != V_437 )
V_431 -> V_822 -> V_434 ( V_431 , V_818 -> V_820 ) ;
F_55 ( & V_21 -> V_272 ) ;
}
static int F_525 ( struct V_1 * V_2 ,
const struct V_411 * V_412 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_47 = V_412 -> V_184 . V_47 ;
if ( ( V_47 & V_829 ) == V_547 )
return V_4 -> V_491 . V_495 * 1000 ;
else if ( F_3 ( V_2 ) )
return 120000 ;
else if ( ! F_18 ( V_2 ) )
return 96000 ;
else
return 48000 ;
}
static void F_379 ( struct V_64 * V_21 ,
struct V_411 * V_412 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_412 -> V_73 ;
T_1 V_47 = V_412 -> V_184 . V_47 ;
T_1 V_497 ;
T_2 clock ;
int V_10 = F_525 ( V_2 , V_412 ) ;
if ( ( V_47 & V_830 ) == 0 )
V_497 = V_412 -> V_184 . V_499 ;
else
V_497 = V_412 -> V_184 . V_502 ;
clock . V_12 = ( V_497 & V_831 ) >> V_832 ;
if ( F_16 ( V_2 ) ) {
clock . V_18 = F_526 ( ( V_497 & V_833 ) >> V_834 ) - 1 ;
clock . V_13 = ( V_497 & V_835 ) >> V_836 ;
} else {
clock . V_18 = ( V_497 & V_837 ) >> V_834 ;
clock . V_13 = ( V_497 & V_838 ) >> V_836 ;
}
if ( ! F_18 ( V_2 ) ) {
if ( F_16 ( V_2 ) )
clock . V_15 = F_526 ( ( V_47 & V_839 ) >>
V_537 ) ;
else
clock . V_15 = F_526 ( ( V_47 & V_840 ) >>
V_538 ) ;
switch ( V_47 & V_841 ) {
case V_534 :
clock . V_16 = V_47 & V_540 ?
5 : 10 ;
break;
case V_533 :
clock . V_16 = V_47 & V_541 ?
7 : 14 ;
break;
default:
F_36 ( L_166
L_167 , ( int ) ( V_47 & V_841 ) ) ;
return;
}
if ( F_16 ( V_2 ) )
F_19 ( V_10 , & clock ) ;
else
F_21 ( V_10 , & clock ) ;
} else {
bool V_588 = ( V_71 == 1 ) && ( F_4 ( V_130 ) & V_165 ) ;
if ( V_588 ) {
clock . V_15 = F_526 ( ( V_47 & V_842 ) >>
V_538 ) ;
clock . V_16 = 14 ;
} else {
if ( V_47 & V_549 )
clock . V_15 = 2 ;
else {
clock . V_15 = ( ( V_47 & V_843 ) >>
V_538 ) + 2 ;
}
if ( V_47 & V_550 )
clock . V_16 = 4 ;
else
clock . V_16 = 2 ;
}
F_21 ( V_10 , & clock ) ;
}
V_412 -> V_524 = clock . V_19 ;
}
int F_527 ( int V_844 ,
const struct V_483 * V_484 )
{
if ( ! V_484 -> V_489 )
return 0 ;
return F_28 ( ( V_845 ) V_484 -> V_488 * V_844 , V_484 -> V_489 ) ;
}
static void F_419 ( struct V_64 * V_21 ,
struct V_411 * V_412 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
F_379 ( V_21 , V_412 ) ;
V_412 -> V_68 . V_69 =
F_527 ( F_5 ( V_2 ) * 10000 ,
& V_412 -> V_446 ) ;
}
struct V_288 * F_528 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_70 V_73 = V_64 -> V_67 . V_73 ;
struct V_288 * V_370 ;
struct V_411 V_412 ;
int V_846 = F_4 ( F_219 ( V_73 ) ) ;
int V_847 = F_4 ( F_223 ( V_73 ) ) ;
int V_848 = F_4 ( F_225 ( V_73 ) ) ;
int V_849 = F_4 ( F_229 ( V_73 ) ) ;
enum V_71 V_71 = V_64 -> V_71 ;
V_370 = F_505 ( sizeof( * V_370 ) , V_812 ) ;
if ( ! V_370 )
return NULL ;
V_412 . V_73 = (enum V_70 ) V_71 ;
V_412 . V_529 = 1 ;
V_412 . V_184 . V_47 = F_4 ( F_51 ( V_71 ) ) ;
V_412 . V_184 . V_499 = F_4 ( F_335 ( V_71 ) ) ;
V_412 . V_184 . V_502 = F_4 ( F_336 ( V_71 ) ) ;
F_379 ( V_64 , & V_412 ) ;
V_370 -> clock = V_412 . V_524 / V_412 . V_529 ;
V_370 -> V_422 = ( V_846 & 0xffff ) + 1 ;
V_370 -> V_568 = ( ( V_846 & 0xffff0000 ) >> 16 ) + 1 ;
V_370 -> V_454 = ( V_847 & 0xffff ) + 1 ;
V_370 -> V_569 = ( ( V_847 & 0xffff0000 ) >> 16 ) + 1 ;
V_370 -> V_424 = ( V_848 & 0xffff ) + 1 ;
V_370 -> V_570 = ( ( V_848 & 0xffff0000 ) >> 16 ) + 1 ;
V_370 -> V_571 = ( V_849 & 0xffff ) + 1 ;
V_370 -> V_572 = ( ( V_849 & 0xffff0000 ) >> 16 ) + 1 ;
F_529 ( V_370 ) ;
return V_370 ;
}
static void F_170 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_8 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
int V_850 = F_51 ( V_71 ) ;
int V_47 ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_592 )
return;
V_47 = F_4 ( V_850 ) ;
if ( ! F_372 ( V_2 ) && ( V_47 & V_830 ) ) {
F_59 ( L_168 ) ;
F_68 ( V_4 , V_71 ) ;
V_47 &= ~ V_830 ;
F_40 ( V_850 , V_47 ) ;
F_37 ( V_2 , V_71 ) ;
V_47 = F_4 ( V_850 ) ;
if ( V_47 & V_830 )
F_59 ( L_169 ) ;
}
}
static void F_530 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_8 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_592 )
return;
if ( ! F_372 ( V_2 ) && V_64 -> V_500 ) {
int V_71 = V_64 -> V_71 ;
int V_850 = F_51 ( V_71 ) ;
int V_47 ;
F_59 ( L_170 ) ;
F_68 ( V_4 , V_71 ) ;
V_47 = F_4 ( V_850 ) ;
V_47 |= V_830 ;
F_40 ( V_850 , V_47 ) ;
F_37 ( V_2 , V_71 ) ;
V_47 = F_4 ( V_850 ) ;
if ( ! ( V_47 & V_830 ) )
F_59 ( L_171 ) ;
}
}
void F_531 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_446 ( V_4 ) ;
F_532 ( V_4 ) ;
}
void F_533 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 ;
F_445 ( V_4 ) ;
if ( ! V_501 )
return;
F_172 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_21 -> V_66 )
continue;
F_530 ( V_21 ) ;
}
if ( V_4 -> V_119 -> V_77 >= 6 )
F_534 ( V_2 -> V_5 ) ;
}
void F_535 ( struct V_215 * V_216 ,
struct V_217 * V_851 )
{
struct V_1 * V_2 = V_216 -> V_108 . V_2 ;
struct V_20 * V_21 ;
if ( ! V_501 )
return;
F_172 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_21 -> V_66 )
continue;
if ( F_160 ( V_21 -> V_66 ) -> V_216 != V_216 )
continue;
F_170 ( V_21 ) ;
if ( V_851 && F_536 ( V_2 ) )
V_851 -> V_852 = true ;
}
}
static void F_537 ( struct V_20 * V_21 )
{
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_853 * V_854 ;
unsigned long V_332 ;
F_205 ( & V_2 -> V_336 , V_332 ) ;
V_854 = V_64 -> V_337 ;
V_64 -> V_337 = NULL ;
F_206 ( & V_2 -> V_336 , V_332 ) ;
if ( V_854 ) {
F_538 ( & V_854 -> V_854 ) ;
F_301 ( V_854 ) ;
}
F_493 ( V_21 , NULL , 0 , 0 , 0 ) ;
F_539 ( V_21 ) ;
F_301 ( V_64 ) ;
}
static void F_540 ( struct V_695 * V_696 )
{
struct V_853 * V_854 =
F_427 ( V_696 , struct V_853 , V_854 ) ;
struct V_1 * V_2 = V_854 -> V_21 -> V_2 ;
F_53 ( & V_2 -> V_286 ) ;
F_156 ( V_854 -> V_855 ) ;
F_499 ( & V_854 -> V_856 -> V_108 ) ;
F_499 ( & V_854 -> V_855 -> V_108 ) ;
F_183 ( V_2 ) ;
F_55 ( & V_2 -> V_286 ) ;
F_110 ( F_204 ( & F_30 ( V_854 -> V_21 ) -> V_857 ) == 0 ) ;
F_541 ( & F_30 ( V_854 -> V_21 ) -> V_857 ) ;
F_301 ( V_854 ) ;
}
static void F_542 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_853 * V_854 ;
unsigned long V_332 ;
if ( V_64 == NULL )
return;
F_205 ( & V_2 -> V_336 , V_332 ) ;
V_854 = V_64 -> V_337 ;
F_543 () ;
if ( V_854 == NULL || F_204 ( & V_854 -> V_333 ) < V_858 ) {
F_206 ( & V_2 -> V_336 , V_332 ) ;
return;
}
F_543 () ;
V_64 -> V_337 = NULL ;
if ( V_854 -> V_859 )
F_544 ( V_2 , V_64 -> V_71 , V_854 -> V_859 ) ;
F_545 ( V_2 , V_64 -> V_71 ) ;
F_206 ( & V_2 -> V_336 , V_332 ) ;
F_546 ( & V_4 -> V_338 ) ;
F_547 ( V_4 -> V_860 , & V_854 -> V_854 ) ;
F_548 ( V_64 -> V_141 , V_854 -> V_856 ) ;
}
void F_549 ( struct V_1 * V_2 , int V_71 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 = V_4 -> V_72 [ V_71 ] ;
F_542 ( V_2 , V_21 ) ;
}
void F_174 ( struct V_1 * V_2 , int V_141 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 = V_4 -> V_861 [ V_141 ] ;
F_542 ( V_2 , V_21 ) ;
}
void F_173 ( struct V_1 * V_2 , int V_141 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 =
F_30 ( V_4 -> V_861 [ V_141 ] ) ;
unsigned long V_332 ;
F_205 ( & V_2 -> V_336 , V_332 ) ;
if ( V_64 -> V_337 )
F_550 ( & V_64 -> V_337 -> V_333 ) ;
F_206 ( & V_2 -> V_336 , V_332 ) ;
}
inline static void F_551 ( struct V_64 * V_64 )
{
F_552 () ;
F_553 ( & V_64 -> V_337 -> V_333 , V_862 ) ;
F_552 () ;
}
static int F_554 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_237 * V_66 ,
struct V_215 * V_216 ,
T_4 V_332 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
T_1 V_863 ;
struct V_217 * V_851 = & V_4 -> V_851 [ V_864 ] ;
int V_220 ;
V_220 = F_148 ( V_2 , V_216 , V_851 ) ;
if ( V_220 )
goto V_53;
V_220 = F_555 ( V_851 , 6 ) ;
if ( V_220 )
goto V_229;
if ( V_64 -> V_141 )
V_863 = V_865 ;
else
V_863 = V_866 ;
F_556 ( V_851 , V_867 | V_863 ) ;
F_556 ( V_851 , V_868 ) ;
F_556 ( V_851 , V_869 |
F_557 ( V_64 -> V_141 ) ) ;
F_556 ( V_851 , V_66 -> V_265 [ 0 ] ) ;
F_556 ( V_851 , F_161 ( V_216 ) + V_64 -> V_267 ) ;
F_556 ( V_851 , 0 ) ;
F_551 ( V_64 ) ;
F_558 ( V_851 ) ;
return 0 ;
V_229:
F_156 ( V_216 ) ;
V_53:
return V_220 ;
}
static int F_559 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_237 * V_66 ,
struct V_215 * V_216 ,
T_4 V_332 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
T_1 V_863 ;
struct V_217 * V_851 = & V_4 -> V_851 [ V_864 ] ;
int V_220 ;
V_220 = F_148 ( V_2 , V_216 , V_851 ) ;
if ( V_220 )
goto V_53;
V_220 = F_555 ( V_851 , 6 ) ;
if ( V_220 )
goto V_229;
if ( V_64 -> V_141 )
V_863 = V_865 ;
else
V_863 = V_866 ;
F_556 ( V_851 , V_867 | V_863 ) ;
F_556 ( V_851 , V_868 ) ;
F_556 ( V_851 , V_870 |
F_557 ( V_64 -> V_141 ) ) ;
F_556 ( V_851 , V_66 -> V_265 [ 0 ] ) ;
F_556 ( V_851 , F_161 ( V_216 ) + V_64 -> V_267 ) ;
F_556 ( V_851 , V_868 ) ;
F_551 ( V_64 ) ;
F_558 ( V_851 ) ;
return 0 ;
V_229:
F_156 ( V_216 ) ;
V_53:
return V_220 ;
}
static int F_560 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_237 * V_66 ,
struct V_215 * V_216 ,
T_4 V_332 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
T_4 V_871 , V_872 ;
struct V_217 * V_851 = & V_4 -> V_851 [ V_864 ] ;
int V_220 ;
V_220 = F_148 ( V_2 , V_216 , V_851 ) ;
if ( V_220 )
goto V_53;
V_220 = F_555 ( V_851 , 4 ) ;
if ( V_220 )
goto V_229;
F_556 ( V_851 , V_869 |
F_557 ( V_64 -> V_141 ) ) ;
F_556 ( V_851 , V_66 -> V_265 [ 0 ] ) ;
F_556 ( V_851 ,
( F_161 ( V_216 ) + V_64 -> V_267 ) |
V_216 -> V_221 ) ;
V_871 = 0 ;
V_872 = F_4 ( F_179 ( V_64 -> V_71 ) ) & 0x0fff0fff ;
F_556 ( V_851 , V_871 | V_872 ) ;
F_551 ( V_64 ) ;
F_558 ( V_851 ) ;
return 0 ;
V_229:
F_156 ( V_216 ) ;
V_53:
return V_220 ;
}
static int F_561 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_237 * V_66 ,
struct V_215 * V_216 ,
T_4 V_332 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_217 * V_851 = & V_4 -> V_851 [ V_864 ] ;
T_4 V_871 , V_872 ;
int V_220 ;
V_220 = F_148 ( V_2 , V_216 , V_851 ) ;
if ( V_220 )
goto V_53;
V_220 = F_555 ( V_851 , 4 ) ;
if ( V_220 )
goto V_229;
F_556 ( V_851 , V_869 |
F_557 ( V_64 -> V_141 ) ) ;
F_556 ( V_851 , V_66 -> V_265 [ 0 ] | V_216 -> V_221 ) ;
F_556 ( V_851 , F_161 ( V_216 ) + V_64 -> V_267 ) ;
V_871 = 0 ;
V_872 = F_4 ( F_179 ( V_64 -> V_71 ) ) & 0x0fff0fff ;
F_556 ( V_851 , V_871 | V_872 ) ;
F_551 ( V_64 ) ;
F_558 ( V_851 ) ;
return 0 ;
V_229:
F_156 ( V_216 ) ;
V_53:
return V_220 ;
}
static int F_562 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_237 * V_66 ,
struct V_215 * V_216 ,
T_4 V_332 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_217 * V_851 ;
T_4 V_873 = 0 ;
int V_738 , V_220 ;
V_851 = V_216 -> V_851 ;
if ( F_17 ( V_2 ) || V_851 == NULL || V_851 -> V_193 != V_864 )
V_851 = & V_4 -> V_851 [ V_874 ] ;
V_220 = F_148 ( V_2 , V_216 , V_851 ) ;
if ( V_220 )
goto V_53;
switch( V_64 -> V_141 ) {
case V_875 :
V_873 = V_876 ;
break;
case V_877 :
V_873 = V_878 ;
break;
case V_879 :
V_873 = V_880 ;
break;
default:
F_563 ( 1 , L_172 ) ;
V_220 = - V_881 ;
goto V_229;
}
V_738 = 4 ;
if ( V_851 -> V_193 == V_864 )
V_738 += 6 ;
V_220 = F_555 ( V_851 , V_738 ) ;
if ( V_220 )
goto V_229;
if ( V_851 -> V_193 == V_864 ) {
F_556 ( V_851 , F_564 ( 1 ) ) ;
F_556 ( V_851 , V_882 ) ;
F_556 ( V_851 , ~ ( V_883 |
V_884 |
V_885 ) ) ;
F_556 ( V_851 , F_565 ( 1 ) |
V_886 ) ;
F_556 ( V_851 , V_882 ) ;
F_556 ( V_851 , V_851 -> V_887 . V_888 + 256 ) ;
}
F_556 ( V_851 , V_870 | V_873 ) ;
F_556 ( V_851 , ( V_66 -> V_265 [ 0 ] | V_216 -> V_221 ) ) ;
F_556 ( V_851 , F_161 ( V_216 ) + V_64 -> V_267 ) ;
F_556 ( V_851 , ( V_868 ) ) ;
F_551 ( V_64 ) ;
F_558 ( V_851 ) ;
return 0 ;
V_229:
F_156 ( V_216 ) ;
V_53:
return V_220 ;
}
static int F_566 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_237 * V_66 ,
struct V_215 * V_216 ,
T_4 V_332 )
{
return - V_881 ;
}
static int F_567 ( struct V_20 * V_21 ,
struct V_237 * V_66 ,
struct V_889 * V_859 ,
T_4 V_890 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_237 * V_273 = V_21 -> V_66 ;
struct V_215 * V_216 = F_160 ( V_66 ) -> V_216 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_853 * V_854 ;
unsigned long V_332 ;
int V_220 ;
if ( V_66 -> V_243 != V_21 -> V_66 -> V_243 )
return - V_225 ;
if ( F_39 ( V_2 ) -> V_77 > 3 &&
( V_66 -> V_891 [ 0 ] != V_21 -> V_66 -> V_891 [ 0 ] ||
V_66 -> V_265 [ 0 ] != V_21 -> V_66 -> V_265 [ 0 ] ) )
return - V_225 ;
V_854 = F_505 ( sizeof( * V_854 ) , V_812 ) ;
if ( V_854 == NULL )
return - V_791 ;
V_854 -> V_859 = V_859 ;
V_854 -> V_21 = V_21 ;
V_854 -> V_855 = F_160 ( V_273 ) -> V_216 ;
F_568 ( & V_854 -> V_854 , F_540 ) ;
V_220 = F_569 ( V_2 , V_64 -> V_71 ) ;
if ( V_220 )
goto V_892;
F_205 ( & V_2 -> V_336 , V_332 ) ;
if ( V_64 -> V_337 ) {
F_206 ( & V_2 -> V_336 , V_332 ) ;
F_301 ( V_854 ) ;
F_545 ( V_2 , V_64 -> V_71 ) ;
F_59 ( L_173 ) ;
return - V_893 ;
}
V_64 -> V_337 = V_854 ;
F_206 ( & V_2 -> V_336 , V_332 ) ;
if ( F_204 ( & V_64 -> V_857 ) >= 2 )
F_570 ( V_4 -> V_860 ) ;
V_220 = F_507 ( V_2 ) ;
if ( V_220 )
goto V_894;
F_571 ( & V_854 -> V_855 -> V_108 ) ;
F_571 ( & V_216 -> V_108 ) ;
V_21 -> V_66 = V_66 ;
V_854 -> V_856 = V_216 ;
V_854 -> V_895 = true ;
F_572 ( & V_64 -> V_857 ) ;
V_64 -> V_335 = F_204 ( & V_4 -> V_334 . V_335 ) ;
V_220 = V_4 -> V_269 . V_896 ( V_2 , V_21 , V_66 , V_216 , V_890 ) ;
if ( V_220 )
goto V_897;
F_267 ( V_2 ) ;
F_535 ( V_216 , NULL ) ;
F_55 ( & V_2 -> V_286 ) ;
F_573 ( V_64 -> V_141 , V_216 ) ;
return 0 ;
V_897:
F_541 ( & V_64 -> V_857 ) ;
V_21 -> V_66 = V_273 ;
F_499 ( & V_854 -> V_855 -> V_108 ) ;
F_499 ( & V_216 -> V_108 ) ;
F_55 ( & V_2 -> V_286 ) ;
V_894:
F_205 ( & V_2 -> V_336 , V_332 ) ;
V_64 -> V_337 = NULL ;
F_206 ( & V_2 -> V_336 , V_332 ) ;
F_545 ( V_2 , V_64 -> V_71 ) ;
V_892:
F_301 ( V_854 ) ;
return V_220 ;
}
static bool F_574 ( struct V_436 * V_23 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 ;
struct V_20 * V_566 ;
int V_898 = 1 ;
F_46 ( ! V_21 , L_174 ) ;
V_2 = V_21 -> V_2 ;
F_172 (tmp, &dev->mode_config.crtc_list, head) {
if ( V_566 == V_21 )
break;
V_898 <<= 1 ;
}
if ( V_23 -> V_823 & V_898 )
return true ;
return false ;
}
static void F_575 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_438 * V_431 ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
V_431 -> V_825 =
F_298 ( V_431 -> V_108 . V_23 ) ;
}
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_23 -> V_824 =
F_30 ( V_23 -> V_108 . V_21 ) ;
}
}
static void F_576 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_438 * V_431 ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
V_431 -> V_108 . V_23 = & V_431 -> V_825 -> V_108 ;
}
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_23 -> V_108 . V_21 = & V_23 -> V_824 -> V_108 ;
}
}
static void
F_577 ( struct V_438 * V_431 ,
struct V_411 * V_412 )
{
int V_648 = V_412 -> V_445 ;
F_36 ( L_175 ,
V_431 -> V_108 . V_108 . V_193 ,
F_304 ( & V_431 -> V_108 ) ) ;
if ( V_431 -> V_108 . V_899 . V_365 &&
V_431 -> V_108 . V_899 . V_365 * 3 < V_648 ) {
F_36 ( L_176 ,
V_648 , V_431 -> V_108 . V_899 . V_365 * 3 ) ;
V_412 -> V_445 = V_431 -> V_108 . V_899 . V_365 * 3 ;
}
if ( V_431 -> V_108 . V_899 . V_365 == 0 && V_648 > 24 ) {
F_36 ( L_177 ,
V_648 ) ;
V_412 -> V_445 = 24 ;
}
}
static int
F_578 ( struct V_64 * V_21 ,
struct V_237 * V_66 ,
struct V_411 * V_412 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_438 * V_431 ;
int V_648 ;
switch ( V_66 -> V_243 ) {
case V_244 :
V_648 = 8 * 3 ;
break;
case V_246 :
case V_247 :
if ( F_2 ( F_39 ( V_2 ) -> V_77 > 3 ) )
return - V_225 ;
case V_249 :
V_648 = 6 * 3 ;
break;
case V_254 :
case V_255 :
if ( F_2 ( F_39 ( V_2 ) -> V_77 < 4 ) )
return - V_225 ;
case V_251 :
case V_252 :
V_648 = 8 * 3 ;
break;
case V_257 :
case V_258 :
case V_260 :
case V_261 :
if ( F_2 ( F_39 ( V_2 ) -> V_77 < 4 ) )
return - V_225 ;
V_648 = 10 * 3 ;
break;
default:
F_36 ( L_178 ) ;
return - V_225 ;
}
V_412 -> V_445 = V_648 ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_431 -> V_825 ||
V_431 -> V_825 -> V_824 != V_21 )
continue;
F_577 ( V_431 , V_412 ) ;
}
return V_648 ;
}
static void F_579 ( const struct V_288 * V_370 )
{
F_36 ( L_179
L_180 ,
V_370 -> V_69 ,
V_370 -> V_289 , V_370 -> V_556 ,
V_370 -> V_560 , V_370 -> V_557 ,
V_370 -> V_290 , V_370 -> V_562 ,
V_370 -> V_563 , V_370 -> V_553 , V_370 -> type , V_370 -> V_332 ) ;
}
static void F_580 ( struct V_64 * V_21 ,
struct V_411 * V_412 ,
const char * V_900 )
{
F_36 ( L_181 , V_21 -> V_108 . V_108 . V_193 ,
V_900 , F_69 ( V_21 -> V_71 ) ) ;
F_36 ( L_182 , F_581 ( V_412 -> V_73 ) ) ;
F_36 ( L_183 ,
V_412 -> V_445 , V_412 -> V_575 ) ;
F_36 ( L_184 ,
V_412 -> V_302 ,
V_412 -> V_312 ,
V_412 -> V_446 . V_486 , V_412 -> V_446 . V_487 ,
V_412 -> V_446 . V_488 , V_412 -> V_446 . V_489 ,
V_412 -> V_446 . V_485 ) ;
F_36 ( L_185 ,
V_412 -> V_531 ,
V_412 -> V_505 . V_486 , V_412 -> V_505 . V_487 ,
V_412 -> V_505 . V_488 , V_412 -> V_505 . V_489 ,
V_412 -> V_505 . V_485 ) ;
F_36 ( L_186 ) ;
F_582 ( & V_412 -> V_567 ) ;
F_36 ( L_187 ) ;
F_582 ( & V_412 -> V_68 ) ;
F_579 ( & V_412 -> V_68 ) ;
F_36 ( L_188 , V_412 -> V_524 ) ;
F_36 ( L_189 ,
V_412 -> V_453 , V_412 -> V_565 ) ;
F_36 ( L_190 ,
V_412 -> V_413 . V_414 ,
V_412 -> V_413 . V_418 ,
V_412 -> V_413 . V_598 ) ;
F_36 ( L_191 ,
V_412 -> V_291 . V_382 ,
V_412 -> V_291 . V_383 ,
V_412 -> V_291 . V_99 ? L_192 : L_193 ) ;
F_36 ( L_194 , V_412 -> V_385 ) ;
F_36 ( L_195 , V_412 -> V_452 ) ;
}
static bool F_583 ( struct V_20 * V_21 )
{
int V_901 = 0 ;
bool V_902 = false ;
struct V_22 * V_23 ;
F_172 (encoder, &crtc->dev->mode_config.encoder_list,
base.head) {
if ( & V_23 -> V_824 -> V_108 != V_21 )
continue;
V_901 ++ ;
if ( ! V_23 -> V_903 )
V_902 = true ;
}
return ! ( V_901 > 1 && V_902 ) ;
}
static struct V_411 *
F_584 ( struct V_20 * V_21 ,
struct V_237 * V_66 ,
struct V_288 * V_370 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_22 * V_23 ;
struct V_411 * V_412 ;
int V_904 , V_220 = - V_225 ;
bool V_317 = true ;
if ( ! F_583 ( V_21 ) ) {
F_36 ( L_196 ) ;
return F_506 ( - V_225 ) ;
}
V_412 = F_505 ( sizeof( * V_412 ) , V_812 ) ;
if ( ! V_412 )
return F_506 ( - V_791 ) ;
F_585 ( & V_412 -> V_68 , V_370 ) ;
F_585 ( & V_412 -> V_567 , V_370 ) ;
V_412 -> V_73 =
(enum V_70 ) F_30 ( V_21 ) -> V_71 ;
V_412 -> V_109 = V_375 ;
if ( ! ( V_412 -> V_68 . V_332 &
( V_371 | V_905 ) ) )
V_412 -> V_68 . V_332 |= V_905 ;
if ( ! ( V_412 -> V_68 . V_332 &
( V_373 | V_906 ) ) )
V_412 -> V_68 . V_332 |= V_906 ;
V_904 = F_578 ( F_30 ( V_21 ) ,
V_66 , V_412 ) ;
if ( V_904 < 0 )
goto V_792;
F_586 ( & V_412 -> V_567 , V_907 ) ;
V_412 -> V_453 = V_412 -> V_567 . V_289 ;
V_412 -> V_565 = V_412 -> V_567 . V_290 ;
V_908:
V_412 -> V_524 = 0 ;
V_412 -> V_529 = 1 ;
F_586 ( & V_412 -> V_68 , V_907 ) ;
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( & V_23 -> V_824 -> V_108 != V_21 )
continue;
if ( ! ( V_23 -> V_909 ( V_23 , V_412 ) ) ) {
F_36 ( L_197 ) ;
goto V_792;
}
}
if ( ! V_412 -> V_524 )
V_412 -> V_524 = V_412 -> V_68 . V_69
* V_412 -> V_529 ;
V_220 = F_315 ( F_30 ( V_21 ) , V_412 ) ;
if ( V_220 < 0 ) {
F_36 ( L_198 ) ;
goto V_792;
}
if ( V_220 == V_448 ) {
if ( F_46 ( ! V_317 , L_199 ) ) {
V_220 = - V_225 ;
goto V_792;
}
F_36 ( L_200 ) ;
V_317 = false ;
goto V_908;
}
V_412 -> V_575 = V_412 -> V_445 != V_904 ;
F_36 ( L_201 ,
V_904 , V_412 -> V_445 , V_412 -> V_575 ) ;
return V_412 ;
V_792:
F_301 ( V_412 ) ;
return F_506 ( V_220 ) ;
}
static void
F_587 ( struct V_20 * V_21 , unsigned * V_910 ,
unsigned * V_911 , unsigned * V_912 )
{
struct V_64 * V_64 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_22 * V_23 ;
struct V_438 * V_431 ;
struct V_20 * V_913 ;
* V_912 = * V_910 = * V_911 = 0 ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_431 -> V_108 . V_23 == & V_431 -> V_825 -> V_108 )
continue;
if ( V_431 -> V_108 . V_23 ) {
V_913 = V_431 -> V_108 . V_23 -> V_21 ;
* V_911 |= 1 << F_30 ( V_913 ) -> V_71 ;
}
if ( V_431 -> V_825 )
* V_911 |=
1 << V_431 -> V_825 -> V_824 -> V_71 ;
}
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_23 -> V_108 . V_21 == & V_23 -> V_824 -> V_108 )
continue;
if ( V_23 -> V_108 . V_21 ) {
V_913 = V_23 -> V_108 . V_21 ;
* V_911 |= 1 << F_30 ( V_913 ) -> V_71 ;
}
if ( V_23 -> V_824 )
* V_911 |= 1 << V_23 -> V_824 -> V_71 ;
}
F_172 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
bool V_914 = false ;
if ( ! V_64 -> V_108 . V_99 )
continue;
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_23 -> V_824 == V_64 )
V_914 = true ;
}
if ( ! V_914 )
* V_912 |= 1 << V_64 -> V_71 ;
}
V_64 = F_30 ( V_21 ) ;
if ( V_21 -> V_99 )
* V_911 |= 1 << V_64 -> V_71 ;
if ( * V_911 )
* V_910 = * V_911 ;
* V_910 &= ~ ( * V_912 ) ;
* V_911 &= ~ ( * V_912 ) ;
* V_910 &= 1 << V_64 -> V_71 ;
* V_911 &= 1 << V_64 -> V_71 ;
F_36 ( L_202 ,
* V_910 , * V_911 , * V_912 ) ;
}
static bool F_588 ( struct V_20 * V_21 )
{
struct V_436 * V_23 ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_172 (encoder, &dev->mode_config.encoder_list, head)
if ( V_23 -> V_21 == V_21 )
return true ;
return false ;
}
static void
F_589 ( struct V_1 * V_2 , unsigned V_911 )
{
struct V_22 * V_22 ;
struct V_64 * V_64 ;
struct V_430 * V_431 ;
F_172 (intel_encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_22 -> V_108 . V_21 )
continue;
V_64 = F_30 ( V_22 -> V_108 . V_21 ) ;
if ( V_911 & ( 1 << V_64 -> V_71 ) )
V_22 -> V_427 = false ;
}
F_576 ( V_2 ) ;
F_172 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
V_64 -> V_108 . V_99 = F_588 ( & V_64 -> V_108 ) ;
}
F_172 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_431 -> V_23 || ! V_431 -> V_23 -> V_21 )
continue;
V_64 = F_30 ( V_431 -> V_23 -> V_21 ) ;
if ( V_911 & ( 1 << V_64 -> V_71 ) ) {
struct V_915 * V_916 =
V_2 -> V_603 . V_916 ;
V_431 -> V_434 = V_437 ;
F_590 ( & V_431 -> V_108 ,
V_916 ,
V_437 ) ;
V_22 = F_298 ( V_431 -> V_23 ) ;
V_22 -> V_427 = true ;
}
}
}
static bool F_591 ( int V_917 , int V_918 )
{
int V_63 ;
if ( V_917 == V_918 )
return true ;
if ( ! V_917 || ! V_918 )
return false ;
V_63 = abs ( V_917 - V_918 ) ;
if ( ( ( ( ( V_63 + V_917 + V_918 ) * 100 ) ) / ( V_917 + V_918 ) ) < 105 )
return true ;
return false ;
}
static bool
F_592 ( struct V_1 * V_2 ,
struct V_411 * V_919 ,
struct V_411 * V_412 )
{
#define F_593 ( V_115 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_594 ( V_115 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_595 ( V_115 , V_710 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
DRM_ERROR("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
return false; \
}
#define F_596 ( V_115 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_597 ( T_9 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_594 ( V_73 ) ;
F_594 ( V_302 ) ;
F_594 ( V_312 ) ;
F_594 ( V_446 . V_486 ) ;
F_594 ( V_446 . V_487 ) ;
F_594 ( V_446 . V_488 ) ;
F_594 ( V_446 . V_489 ) ;
F_594 ( V_446 . V_485 ) ;
F_594 ( V_531 ) ;
F_594 ( V_505 . V_486 ) ;
F_594 ( V_505 . V_487 ) ;
F_594 ( V_505 . V_488 ) ;
F_594 ( V_505 . V_489 ) ;
F_594 ( V_505 . V_485 ) ;
F_594 ( V_68 . V_289 ) ;
F_594 ( V_68 . V_557 ) ;
F_594 ( V_68 . V_558 ) ;
F_594 ( V_68 . V_559 ) ;
F_594 ( V_68 . V_556 ) ;
F_594 ( V_68 . V_560 ) ;
F_594 ( V_68 . V_290 ) ;
F_594 ( V_68 . V_553 ) ;
F_594 ( V_68 . V_561 ) ;
F_594 ( V_68 . V_554 ) ;
F_594 ( V_68 . V_562 ) ;
F_594 ( V_68 . V_563 ) ;
F_594 ( V_529 ) ;
F_595 ( V_68 . V_332 ,
V_555 ) ;
if ( ! F_597 ( V_920 ) ) {
F_595 ( V_68 . V_332 ,
V_371 ) ;
F_595 ( V_68 . V_332 ,
V_905 ) ;
F_595 ( V_68 . V_332 ,
V_373 ) ;
F_595 ( V_68 . V_332 ,
V_906 ) ;
}
F_594 ( V_453 ) ;
F_594 ( V_565 ) ;
F_594 ( V_413 . V_414 ) ;
if ( F_39 ( V_2 ) -> V_77 < 4 )
F_594 ( V_413 . V_418 ) ;
F_594 ( V_413 . V_598 ) ;
F_594 ( V_291 . V_99 ) ;
if ( V_919 -> V_291 . V_99 ) {
F_594 ( V_291 . V_382 ) ;
F_594 ( V_291 . V_383 ) ;
}
F_594 ( V_385 ) ;
F_594 ( V_452 ) ;
F_594 ( V_109 ) ;
F_593 ( V_184 . V_47 ) ;
F_593 ( V_184 . V_186 ) ;
F_593 ( V_184 . V_499 ) ;
F_593 ( V_184 . V_502 ) ;
if ( F_15 ( V_2 ) || F_39 ( V_2 ) -> V_77 >= 5 )
F_594 ( V_445 ) ;
if ( ! F_61 ( V_2 ) ) {
F_596 ( V_68 . V_69 ) ;
F_596 ( V_524 ) ;
}
#undef F_593
#undef F_594
#undef F_595
#undef F_596
#undef F_597
return true ;
}
static void
F_598 ( struct V_1 * V_2 )
{
struct V_438 * V_431 ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
F_303 ( V_431 ) ;
F_46 ( & V_431 -> V_825 -> V_108 != V_431 -> V_108 . V_23 ,
L_203 ) ;
}
}
static void
F_599 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_438 * V_431 ;
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
bool V_99 = false ;
bool V_65 = false ;
enum V_71 V_71 , V_921 ;
F_36 ( L_204 ,
V_23 -> V_108 . V_108 . V_193 ,
F_464 ( & V_23 -> V_108 ) ) ;
F_46 ( & V_23 -> V_824 -> V_108 != V_23 -> V_108 . V_21 ,
L_205 ) ;
F_46 ( V_23 -> V_427 && ! V_23 -> V_108 . V_21 ,
L_206 ) ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_431 -> V_108 . V_23 != & V_23 -> V_108 )
continue;
V_99 = true ;
if ( V_431 -> V_108 . V_434 != V_435 )
V_65 = true ;
}
F_46 ( ! ! V_23 -> V_108 . V_21 != V_99 ,
L_207
L_208 ,
! ! V_23 -> V_108 . V_21 , V_99 ) ;
F_46 ( V_65 && ! V_23 -> V_108 . V_21 ,
L_209 ) ;
F_46 ( V_23 -> V_427 != V_65 ,
L_210
L_208 , V_65 , V_23 -> V_427 ) ;
V_65 = V_23 -> V_114 ( V_23 , & V_71 ) ;
F_46 ( V_65 != V_23 -> V_427 ,
L_211
L_208 ,
V_23 -> V_427 , V_65 ) ;
if ( ! V_23 -> V_108 . V_21 )
continue;
V_921 = F_30 ( V_23 -> V_108 . V_21 ) -> V_71 ;
F_46 ( V_65 && V_71 != V_921 ,
L_212
L_208 ,
V_921 , V_71 ) ;
}
}
static void
F_600 ( struct V_1 * V_2 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_64 * V_21 ;
struct V_22 * V_23 ;
struct V_411 V_412 ;
F_172 (crtc, &dev->mode_config.crtc_list,
base.head) {
bool V_99 = false ;
bool V_65 = false ;
memset ( & V_412 , 0 , sizeof( V_412 ) ) ;
F_36 ( L_213 ,
V_21 -> V_108 . V_108 . V_193 ) ;
F_46 ( V_21 -> V_65 && ! V_21 -> V_108 . V_99 ,
L_214 ) ;
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_23 -> V_108 . V_21 != & V_21 -> V_108 )
continue;
V_99 = true ;
if ( V_23 -> V_427 )
V_65 = true ;
}
F_46 ( V_65 != V_21 -> V_65 ,
L_215
L_208 , V_65 , V_21 -> V_65 ) ;
F_46 ( V_99 != V_21 -> V_108 . V_99 ,
L_216
L_208 , V_99 , V_21 -> V_108 . V_99 ) ;
V_65 = V_4 -> V_269 . V_922 ( V_21 ,
& V_412 ) ;
if ( V_21 -> V_71 == V_125 && V_4 -> V_138 & V_139 )
V_65 = V_21 -> V_65 ;
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
enum V_71 V_71 ;
if ( V_23 -> V_108 . V_21 != & V_21 -> V_108 )
continue;
if ( V_23 -> V_114 ( V_23 , & V_71 ) )
V_23 -> V_923 ( V_23 , & V_412 ) ;
}
F_46 ( V_21 -> V_65 != V_65 ,
L_217
L_208 , V_21 -> V_65 , V_65 ) ;
if ( V_65 &&
! F_592 ( V_2 , & V_21 -> V_67 , & V_412 ) ) {
F_46 ( 1 , L_218 ) ;
F_580 ( V_21 , & V_412 ,
L_219 ) ;
F_580 ( V_21 , & V_21 -> V_67 ,
L_220 ) ;
}
}
}
static void
F_601 ( struct V_1 * V_2 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_64 * V_21 ;
struct V_112 V_184 ;
int V_143 ;
for ( V_143 = 0 ; V_143 < V_4 -> V_377 ; V_143 ++ ) {
struct V_107 * V_111 = & V_4 -> V_110 [ V_143 ] ;
int V_924 = 0 , V_925 = 0 ;
bool V_65 ;
memset ( & V_184 , 0 , sizeof( V_184 ) ) ;
F_36 ( L_221 , V_111 -> V_115 ) ;
V_65 = V_111 -> V_114 ( V_4 , V_111 , & V_184 ) ;
F_46 ( V_111 -> V_65 > V_111 -> V_191 ,
L_222 ,
V_111 -> V_65 , V_111 -> V_191 ) ;
F_46 ( V_111 -> V_65 && ! V_111 -> V_192 ,
L_223 ) ;
F_46 ( V_111 -> V_192 && ! V_111 -> V_65 ,
L_224 ) ;
F_46 ( V_111 -> V_192 != V_65 ,
L_225 ,
V_111 -> V_192 , V_65 ) ;
F_172 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_21 -> V_108 . V_99 && F_56 ( V_21 ) == V_111 )
V_924 ++ ;
if ( V_21 -> V_65 && F_56 ( V_21 ) == V_111 )
V_925 ++ ;
}
F_46 ( V_111 -> V_65 != V_925 ,
L_226 ,
V_111 -> V_65 , V_925 ) ;
F_46 ( V_111 -> V_191 != V_924 ,
L_227 ,
V_111 -> V_191 , V_924 ) ;
F_46 ( V_111 -> V_192 && memcmp ( & V_111 -> V_113 , & V_184 ,
sizeof( V_184 ) ) ,
L_228 ) ;
}
}
void
F_306 ( struct V_1 * V_2 )
{
F_598 ( V_2 ) ;
F_599 ( V_2 ) ;
F_600 ( V_2 ) ;
F_601 ( V_2 ) ;
}
void F_602 ( const struct V_411 * V_412 ,
int V_926 )
{
F_46 ( ! F_591 ( V_412 -> V_68 . V_69 , V_926 ) ,
L_229 ,
V_412 -> V_68 . V_69 , V_926 ) ;
}
static int F_603 ( struct V_20 * V_21 ,
struct V_288 * V_370 ,
int V_230 , int V_231 , struct V_237 * V_66 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_8 * V_4 = V_2 -> V_5 ;
struct V_288 * V_927 , * V_928 ;
struct V_411 * V_412 = NULL ;
struct V_64 * V_64 ;
unsigned V_912 , V_911 , V_910 ;
int V_220 = 0 ;
V_927 = F_604 ( 2 , sizeof( * V_927 ) , V_812 ) ;
if ( ! V_927 )
return - V_791 ;
V_928 = V_927 + 1 ;
F_587 ( V_21 , & V_910 ,
& V_911 , & V_912 ) ;
* V_928 = V_21 -> V_929 ;
* V_927 = V_21 -> V_370 ;
if ( V_910 ) {
V_412 = F_584 ( V_21 , V_66 , V_370 ) ;
if ( F_520 ( V_412 ) ) {
V_220 = F_605 ( V_412 ) ;
V_412 = NULL ;
goto V_930;
}
F_580 ( F_30 ( V_21 ) , V_412 ,
L_230 ) ;
}
F_606 (dev, disable_pipes, intel_crtc)
F_296 ( & V_64 -> V_108 ) ;
F_606 (dev, prepare_pipes, intel_crtc) {
if ( V_64 -> V_108 . V_99 )
V_4 -> V_269 . V_429 ( & V_64 -> V_108 ) ;
}
if ( V_910 ) {
V_21 -> V_370 = * V_370 ;
F_30 ( V_21 ) -> V_67 = * V_412 ;
}
F_589 ( V_2 , V_911 ) ;
if ( V_4 -> V_269 . V_931 )
V_4 -> V_269 . V_931 ( V_2 ) ;
F_606 (dev, modeset_pipes, intel_crtc) {
V_220 = F_461 ( & V_64 -> V_108 ,
V_230 , V_231 , V_66 ) ;
if ( V_220 )
goto V_707;
}
F_606 (dev, prepare_pipes, intel_crtc)
V_4 -> V_269 . V_428 ( & V_64 -> V_108 ) ;
if ( V_910 ) {
V_21 -> V_929 = V_412 -> V_68 ;
F_607 ( V_21 ) ;
}
V_707:
if ( V_220 && V_21 -> V_99 ) {
V_21 -> V_929 = * V_928 ;
V_21 -> V_370 = * V_927 ;
}
V_930:
F_301 ( V_412 ) ;
F_301 ( V_927 ) ;
return V_220 ;
}
static int F_521 ( struct V_20 * V_21 ,
struct V_288 * V_370 ,
int V_230 , int V_231 , struct V_237 * V_66 )
{
int V_220 ;
V_220 = F_603 ( V_21 , V_370 , V_230 , V_231 , V_66 ) ;
if ( V_220 == 0 )
F_306 ( V_21 -> V_2 ) ;
return V_220 ;
}
void F_608 ( struct V_20 * V_21 )
{
F_521 ( V_21 , & V_21 -> V_370 , V_21 -> V_230 , V_21 -> V_231 , V_21 -> V_66 ) ;
}
static void F_609 ( struct V_932 * V_67 )
{
if ( ! V_67 )
return;
F_301 ( V_67 -> V_933 ) ;
F_301 ( V_67 -> V_934 ) ;
F_301 ( V_67 ) ;
}
static int F_610 ( struct V_1 * V_2 ,
struct V_932 * V_67 )
{
struct V_436 * V_23 ;
struct V_430 * V_431 ;
int V_935 ;
V_67 -> V_934 =
F_604 ( V_2 -> V_603 . V_936 ,
sizeof( struct V_20 * ) , V_812 ) ;
if ( ! V_67 -> V_934 )
return - V_791 ;
V_67 -> V_933 =
F_604 ( V_2 -> V_603 . V_937 ,
sizeof( struct V_436 * ) , V_812 ) ;
if ( ! V_67 -> V_933 )
return - V_791 ;
V_935 = 0 ;
F_172 (encoder, &dev->mode_config.encoder_list, head) {
V_67 -> V_934 [ V_935 ++ ] = V_23 -> V_21 ;
}
V_935 = 0 ;
F_172 (connector, &dev->mode_config.connector_list, head) {
V_67 -> V_933 [ V_935 ++ ] = V_431 -> V_23 ;
}
return 0 ;
}
static void F_611 ( struct V_1 * V_2 ,
struct V_932 * V_67 )
{
struct V_22 * V_23 ;
struct V_438 * V_431 ;
int V_935 ;
V_935 = 0 ;
F_172 (encoder, &dev->mode_config.encoder_list, base.head) {
V_23 -> V_824 =
F_30 ( V_67 -> V_934 [ V_935 ++ ] ) ;
}
V_935 = 0 ;
F_172 (connector, &dev->mode_config.connector_list, base.head) {
V_431 -> V_825 =
F_298 ( V_67 -> V_933 [ V_935 ++ ] ) ;
}
}
static bool
F_612 ( struct V_938 * V_939 )
{
int V_143 ;
if ( V_939 -> V_494 == 0 )
return false ;
if ( F_2 ( V_939 -> V_940 == NULL ) )
return false ;
for ( V_143 = 0 ; V_143 < V_939 -> V_494 ; V_143 ++ )
if ( V_939 -> V_940 [ V_143 ] -> V_23 &&
V_939 -> V_940 [ V_143 ] -> V_23 -> V_21 == V_939 -> V_21 &&
V_939 -> V_940 [ V_143 ] -> V_434 != V_437 )
return true ;
return false ;
}
static void
F_613 ( struct V_938 * V_939 ,
struct V_932 * V_67 )
{
if ( F_612 ( V_939 ) ) {
V_67 -> V_941 = true ;
} else if ( V_939 -> V_21 -> V_66 != V_939 -> V_66 ) {
if ( V_939 -> V_21 -> V_66 == NULL ) {
struct V_64 * V_64 =
F_30 ( V_939 -> V_21 ) ;
if ( V_64 -> V_65 && V_287 ) {
F_36 ( L_231 ) ;
V_67 -> V_942 = true ;
} else {
F_36 ( L_232 ) ;
V_67 -> V_941 = true ;
}
} else if ( V_939 -> V_66 == NULL ) {
V_67 -> V_941 = true ;
} else if ( V_939 -> V_66 -> V_243 !=
V_939 -> V_21 -> V_66 -> V_243 ) {
V_67 -> V_941 = true ;
} else {
V_67 -> V_942 = true ;
}
}
if ( V_939 -> V_66 && ( V_939 -> V_230 != V_939 -> V_21 -> V_230 || V_939 -> V_231 != V_939 -> V_21 -> V_231 ) )
V_67 -> V_942 = true ;
if ( V_939 -> V_370 && ! F_614 ( V_939 -> V_370 , & V_939 -> V_21 -> V_370 ) ) {
F_36 ( L_233 ) ;
F_582 ( & V_939 -> V_21 -> V_370 ) ;
F_582 ( V_939 -> V_370 ) ;
V_67 -> V_941 = true ;
}
F_36 ( L_234 ,
V_939 -> V_21 -> V_108 . V_193 , V_67 -> V_941 , V_67 -> V_942 ) ;
}
static int
F_615 ( struct V_1 * V_2 ,
struct V_938 * V_939 ,
struct V_932 * V_67 )
{
struct V_20 * V_824 ;
struct V_438 * V_431 ;
struct V_22 * V_23 ;
int V_943 ;
F_2 ( ! V_939 -> V_66 && ( V_939 -> V_494 != 0 ) ) ;
F_2 ( V_939 -> V_66 && ( V_939 -> V_494 == 0 ) ) ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
for ( V_943 = 0 ; V_943 < V_939 -> V_494 ; V_943 ++ ) {
if ( V_939 -> V_940 [ V_943 ] == & V_431 -> V_108 ) {
V_431 -> V_825 = V_431 -> V_23 ;
break;
}
}
if ( ( ! V_939 -> V_66 || V_943 == V_939 -> V_494 ) &&
V_431 -> V_108 . V_23 &&
V_431 -> V_108 . V_23 -> V_21 == V_939 -> V_21 ) {
V_431 -> V_825 = NULL ;
F_36 ( L_235 ,
V_431 -> V_108 . V_108 . V_193 ,
F_304 ( & V_431 -> V_108 ) ) ;
}
if ( & V_431 -> V_825 -> V_108 != V_431 -> V_108 . V_23 ) {
F_36 ( L_236 ) ;
V_67 -> V_941 = true ;
}
}
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_431 -> V_825 )
continue;
V_824 = V_431 -> V_825 -> V_108 . V_21 ;
for ( V_943 = 0 ; V_943 < V_939 -> V_494 ; V_943 ++ ) {
if ( V_939 -> V_940 [ V_943 ] == & V_431 -> V_108 )
V_824 = V_939 -> V_21 ;
}
if ( ! F_574 ( & V_431 -> V_825 -> V_108 ,
V_824 ) ) {
return - V_225 ;
}
V_431 -> V_23 -> V_824 = F_30 ( V_824 ) ;
F_36 ( L_237 ,
V_431 -> V_108 . V_108 . V_193 ,
F_304 ( & V_431 -> V_108 ) ,
V_824 -> V_108 . V_193 ) ;
}
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_172 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_431 -> V_825 == V_23 ) {
F_2 ( ! V_431 -> V_825 -> V_824 ) ;
goto V_944;
}
}
V_23 -> V_824 = NULL ;
V_944:
if ( & V_23 -> V_824 -> V_108 != V_23 -> V_108 . V_21 ) {
F_36 ( L_238 ) ;
V_67 -> V_941 = true ;
}
}
return 0 ;
}
static int F_616 ( struct V_938 * V_939 )
{
struct V_1 * V_2 ;
struct V_938 V_945 ;
struct V_932 * V_67 ;
int V_220 ;
F_110 ( ! V_939 ) ;
F_110 ( ! V_939 -> V_21 ) ;
F_110 ( ! V_939 -> V_21 -> V_946 ) ;
F_110 ( ! V_939 -> V_370 && V_939 -> V_66 ) ;
F_110 ( V_939 -> V_66 && V_939 -> V_494 == 0 ) ;
if ( V_939 -> V_66 ) {
F_36 ( L_239 ,
V_939 -> V_21 -> V_108 . V_193 , V_939 -> V_66 -> V_108 . V_193 ,
( int ) V_939 -> V_494 , V_939 -> V_230 , V_939 -> V_231 ) ;
} else {
F_36 ( L_240 , V_939 -> V_21 -> V_108 . V_193 ) ;
}
V_2 = V_939 -> V_21 -> V_2 ;
V_220 = - V_791 ;
V_67 = F_505 ( sizeof( * V_67 ) , V_812 ) ;
if ( ! V_67 )
goto V_947;
V_220 = F_610 ( V_2 , V_67 ) ;
if ( V_220 )
goto V_947;
V_945 . V_21 = V_939 -> V_21 ;
V_945 . V_370 = & V_939 -> V_21 -> V_370 ;
V_945 . V_230 = V_939 -> V_21 -> V_230 ;
V_945 . V_231 = V_939 -> V_21 -> V_231 ;
V_945 . V_66 = V_939 -> V_21 -> V_66 ;
F_613 ( V_939 , V_67 ) ;
V_220 = F_615 ( V_2 , V_939 , V_67 ) ;
if ( V_220 )
goto V_792;
if ( V_67 -> V_941 ) {
V_220 = F_521 ( V_939 -> V_21 , V_939 -> V_370 ,
V_939 -> V_230 , V_939 -> V_231 , V_939 -> V_66 ) ;
} else if ( V_67 -> V_942 ) {
F_207 ( V_939 -> V_21 ) ;
V_220 = F_178 ( V_939 -> V_21 ,
V_939 -> V_230 , V_939 -> V_231 , V_939 -> V_66 ) ;
}
if ( V_220 ) {
F_36 ( L_241 ,
V_939 -> V_21 -> V_108 . V_193 , V_220 ) ;
V_792:
F_611 ( V_2 , V_67 ) ;
if ( V_67 -> V_941 &&
F_521 ( V_945 . V_21 , V_945 . V_370 ,
V_945 . V_230 , V_945 . V_231 , V_945 . V_66 ) )
F_115 ( L_242 ) ;
}
V_947:
F_609 ( V_67 ) ;
return V_220 ;
}
static void F_617 ( struct V_1 * V_2 )
{
if ( F_61 ( V_2 ) )
F_618 ( V_2 ) ;
}
static bool F_619 ( struct V_3 * V_4 ,
struct V_107 * V_111 ,
struct V_112 * V_113 )
{
T_4 V_101 ;
V_101 = F_4 ( F_620 ( V_111 -> V_193 ) ) ;
V_113 -> V_47 = V_101 ;
V_113 -> V_499 = F_4 ( F_621 ( V_111 -> V_193 ) ) ;
V_113 -> V_502 = F_4 ( F_622 ( V_111 -> V_193 ) ) ;
return V_101 & V_103 ;
}
static void F_623 ( struct V_3 * V_4 ,
struct V_107 * V_111 )
{
F_40 ( F_621 ( V_111 -> V_193 ) , V_111 -> V_113 . V_499 ) ;
F_40 ( F_622 ( V_111 -> V_193 ) , V_111 -> V_113 . V_502 ) ;
}
static void F_624 ( struct V_3 * V_4 ,
struct V_107 * V_111 )
{
F_90 ( V_4 ) ;
F_40 ( F_620 ( V_111 -> V_193 ) , V_111 -> V_113 . V_47 ) ;
F_113 ( F_620 ( V_111 -> V_193 ) ) ;
F_114 ( 150 ) ;
F_40 ( F_620 ( V_111 -> V_193 ) , V_111 -> V_113 . V_47 ) ;
F_113 ( F_620 ( V_111 -> V_193 ) ) ;
F_114 ( 200 ) ;
}
static void F_625 ( struct V_3 * V_4 ,
struct V_107 * V_111 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_64 * V_21 ;
F_172 (crtc, &dev->mode_config.crtc_list, base.head) {
if ( F_56 ( V_21 ) == V_111 )
F_91 ( V_4 , V_21 -> V_71 ) ;
}
F_40 ( F_620 ( V_111 -> V_193 ) , 0 ) ;
F_113 ( F_620 ( V_111 -> V_193 ) ) ;
F_114 ( 200 ) ;
}
static void F_626 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_143 ;
V_4 -> V_377 = 2 ;
for ( V_143 = 0 ; V_143 < V_4 -> V_377 ; V_143 ++ ) {
V_4 -> V_110 [ V_143 ] . V_193 = V_143 ;
V_4 -> V_110 [ V_143 ] . V_115 = V_948 [ V_143 ] ;
V_4 -> V_110 [ V_143 ] . V_378 = F_623 ;
V_4 -> V_110 [ V_143 ] . V_194 = F_624 ;
V_4 -> V_110 [ V_143 ] . V_195 = F_625 ;
V_4 -> V_110 [ V_143 ] . V_114 =
F_619 ;
}
}
static void F_627 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_48 ( V_2 ) || F_94 ( V_2 ) )
F_626 ( V_2 ) ;
else
V_4 -> V_377 = 0 ;
F_110 ( V_4 -> V_377 > V_949 ) ;
F_36 ( L_243 ,
V_4 -> V_377 ) ;
}
static void F_628 ( struct V_1 * V_2 , int V_71 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 ;
int V_143 ;
V_64 = F_505 ( sizeof( * V_64 ) , V_812 ) ;
if ( V_64 == NULL )
return;
F_629 ( V_2 , & V_64 -> V_108 , & V_950 ) ;
F_630 ( & V_64 -> V_108 , 256 ) ;
for ( V_143 = 0 ; V_143 < 256 ; V_143 ++ ) {
V_64 -> V_396 [ V_143 ] = V_143 ;
V_64 -> V_397 [ V_143 ] = V_143 ;
V_64 -> V_398 [ V_143 ] = V_143 ;
}
V_64 -> V_71 = V_71 ;
V_64 -> V_141 = V_71 ;
if ( F_111 ( V_2 ) && F_631 ( V_2 ) ) {
F_36 ( L_244 ) ;
V_64 -> V_141 = ! V_71 ;
}
F_110 ( V_71 >= F_198 ( V_4 -> V_861 ) ||
V_4 -> V_861 [ V_64 -> V_141 ] != NULL ) ;
V_4 -> V_861 [ V_64 -> V_141 ] = & V_64 -> V_108 ;
V_4 -> V_72 [ V_64 -> V_71 ] = & V_64 -> V_108 ;
F_632 ( & V_64 -> V_108 , & V_951 ) ;
}
enum V_71 F_633 ( struct V_438 * V_431 )
{
struct V_436 * V_23 = V_431 -> V_108 . V_23 ;
F_2 ( ! F_431 ( & V_431 -> V_108 . V_2 -> V_603 . V_272 ) ) ;
if ( ! V_23 )
return V_952 ;
return F_30 ( V_23 -> V_21 ) -> V_71 ;
}
int F_634 ( struct V_1 * V_2 , void * V_953 ,
struct V_783 * V_784 )
{
struct V_954 * V_955 = V_953 ;
struct V_956 * V_957 ;
struct V_64 * V_21 ;
if ( ! F_635 ( V_2 , V_958 ) )
return - V_881 ;
V_957 = F_636 ( V_2 , V_955 -> V_959 ,
V_960 ) ;
if ( ! V_957 ) {
F_115 ( L_245 ) ;
return - V_790 ;
}
V_21 = F_30 ( F_637 ( V_957 ) ) ;
V_955 -> V_71 = V_21 -> V_71 ;
return 0 ;
}
static int F_638 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_108 . V_2 ;
struct V_22 * V_961 ;
int V_962 = 0 ;
int V_963 = 0 ;
F_172 (source_encoder,
&dev->mode_config.encoder_list, base.head) {
if ( V_23 == V_961 )
V_962 |= ( 1 << V_963 ) ;
if ( V_23 -> V_903 && V_961 -> V_903 )
V_962 |= ( 1 << V_963 ) ;
V_963 ++ ;
}
return V_962 ;
}
static bool F_639 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_111 ( V_2 ) )
return false ;
if ( ( F_4 ( V_964 ) & V_965 ) == 0 )
return false ;
if ( F_6 ( V_2 ) &&
( F_4 ( V_966 ) & V_967 ) )
return false ;
return true ;
}
static void F_640 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_23 ;
bool V_968 = false ;
F_641 ( V_2 ) ;
if ( ! F_642 ( V_2 ) )
F_643 ( V_2 ) ;
if ( F_61 ( V_2 ) ) {
int V_59 ;
V_59 = F_4 ( V_969 ) & V_970 ;
if ( V_59 )
F_644 ( V_2 , V_610 ) ;
V_59 = F_4 ( V_971 ) ;
if ( V_59 & V_972 )
F_644 ( V_2 , V_89 ) ;
if ( V_59 & V_973 )
F_644 ( V_2 , V_91 ) ;
if ( V_59 & V_974 )
F_644 ( V_2 , V_93 ) ;
} else if ( F_3 ( V_2 ) ) {
int V_59 ;
V_968 = F_645 ( V_2 , V_93 ) ;
if ( F_639 ( V_2 ) )
F_646 ( V_2 , V_964 , V_610 ) ;
if ( F_4 ( V_179 ) & V_975 ) {
V_59 = F_647 ( V_2 , V_976 , true ) ;
if ( ! V_59 )
F_648 ( V_2 , V_179 , V_89 ) ;
if ( ! V_59 && ( F_4 ( V_172 ) & V_965 ) )
F_646 ( V_2 , V_172 , V_89 ) ;
}
if ( F_4 ( V_180 ) & V_975 )
F_648 ( V_2 , V_180 , V_91 ) ;
if ( ! V_968 && F_4 ( V_181 ) & V_975 )
F_648 ( V_2 , V_181 , V_93 ) ;
if ( F_4 ( V_174 ) & V_965 )
F_646 ( V_2 , V_174 , V_91 ) ;
if ( F_4 ( V_176 ) & V_965 )
F_646 ( V_2 , V_176 , V_93 ) ;
} else if ( F_17 ( V_2 ) ) {
if ( F_4 ( V_977 + V_978 ) & V_975 ) {
F_648 ( V_2 , V_977 + V_978 ,
V_89 ) ;
if ( F_4 ( V_977 + V_979 ) & V_965 )
F_646 ( V_2 , V_977 + V_979 , V_89 ) ;
}
if ( F_4 ( V_977 + V_980 ) & V_975 ) {
F_648 ( V_2 , V_977 + V_980 ,
V_91 ) ;
if ( F_4 ( V_977 + V_981 ) & V_965 )
F_646 ( V_2 , V_977 + V_981 , V_91 ) ;
}
F_649 ( V_2 ) ;
} else if ( F_650 ( V_2 ) ) {
bool V_59 = false ;
if ( F_4 ( V_982 ) & V_975 ) {
F_36 ( L_246 ) ;
V_59 = F_647 ( V_2 , V_982 , true ) ;
if ( ! V_59 && F_651 ( V_2 ) ) {
F_36 ( L_247 ) ;
F_648 ( V_2 , V_978 , V_89 ) ;
}
if ( ! V_59 && F_652 ( V_2 ) )
F_646 ( V_2 , V_979 , V_89 ) ;
}
if ( F_4 ( V_982 ) & V_975 ) {
F_36 ( L_248 ) ;
V_59 = F_647 ( V_2 , V_983 , false ) ;
}
if ( ! V_59 && ( F_4 ( V_983 ) & V_975 ) ) {
if ( F_651 ( V_2 ) ) {
F_36 ( L_249 ) ;
F_648 ( V_2 , V_980 , V_91 ) ;
}
if ( F_652 ( V_2 ) )
F_646 ( V_2 , V_981 , V_91 ) ;
}
if ( F_652 ( V_2 ) &&
( F_4 ( V_984 ) & V_965 ) )
F_646 ( V_2 , V_984 , V_93 ) ;
} else if ( F_18 ( V_2 ) )
F_653 ( V_2 ) ;
if ( F_654 ( V_2 ) )
F_655 ( V_2 ) ;
F_172 (encoder, &dev->mode_config.encoder_list, base.head) {
V_23 -> V_108 . V_823 = V_23 -> V_898 ;
V_23 -> V_108 . V_985 =
F_638 ( V_23 ) ;
}
F_388 ( V_2 ) ;
F_656 ( V_2 ) ;
}
void F_657 ( struct V_238 * V_66 )
{
F_658 ( & V_66 -> V_108 ) ;
F_2 ( ! V_66 -> V_216 -> V_986 -- ) ;
F_500 ( & V_66 -> V_216 -> V_108 ) ;
}
static void F_659 ( struct V_237 * V_66 )
{
struct V_238 * V_239 = F_160 ( V_66 ) ;
F_657 ( V_239 ) ;
F_301 ( V_239 ) ;
}
static int F_660 ( struct V_237 * V_66 ,
struct V_783 * V_784 ,
unsigned int * V_785 )
{
struct V_238 * V_239 = F_160 ( V_66 ) ;
struct V_215 * V_216 = V_239 -> V_216 ;
return F_661 ( V_784 , & V_216 -> V_108 , V_785 ) ;
}
int F_508 ( struct V_1 * V_2 ,
struct V_238 * V_239 ,
struct V_810 * V_811 ,
struct V_215 * V_216 )
{
int V_987 , V_988 ;
int V_989 ;
int V_220 ;
F_2 ( ! F_431 ( & V_2 -> V_286 ) ) ;
if ( V_216 -> V_221 == V_224 ) {
F_662 ( L_250 ) ;
return - V_225 ;
}
if ( V_811 -> V_265 [ 0 ] & 63 ) {
F_662 ( L_251 ,
V_811 -> V_265 [ 0 ] ) ;
return - V_225 ;
}
if ( F_39 ( V_2 ) -> V_77 >= 5 && ! F_17 ( V_2 ) ) {
V_989 = 32 * 1024 ;
} else if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
if ( V_216 -> V_221 )
V_989 = 16 * 1024 ;
else
V_989 = 32 * 1024 ;
} else if ( F_39 ( V_2 ) -> V_77 >= 3 ) {
if ( V_216 -> V_221 )
V_989 = 8 * 1024 ;
else
V_989 = 16 * 1024 ;
} else
V_989 = 8 * 1024 ;
if ( V_811 -> V_265 [ 0 ] > V_989 ) {
F_662 ( L_252 ,
V_216 -> V_221 ? L_253 : L_254 ,
V_811 -> V_265 [ 0 ] , V_989 ) ;
return - V_225 ;
}
if ( V_216 -> V_221 != V_222 &&
V_811 -> V_265 [ 0 ] != V_216 -> V_990 ) {
F_662 ( L_255 ,
V_811 -> V_265 [ 0 ] , V_216 -> V_990 ) ;
return - V_225 ;
}
switch ( V_811 -> V_243 ) {
case V_244 :
case V_249 :
case V_251 :
case V_252 :
break;
case V_246 :
case V_247 :
if ( F_39 ( V_2 ) -> V_77 > 3 ) {
F_662 ( L_256 ,
F_663 ( V_811 -> V_243 ) ) ;
return - V_225 ;
}
break;
case V_254 :
case V_255 :
case V_257 :
case V_258 :
case V_260 :
case V_261 :
if ( F_39 ( V_2 ) -> V_77 < 4 ) {
F_662 ( L_256 ,
F_663 ( V_811 -> V_243 ) ) ;
return - V_225 ;
}
break;
case V_991 :
case V_992 :
case V_993 :
case V_994 :
if ( F_39 ( V_2 ) -> V_77 < 5 ) {
F_662 ( L_256 ,
F_663 ( V_811 -> V_243 ) ) ;
return - V_225 ;
}
break;
default:
F_662 ( L_256 ,
F_663 ( V_811 -> V_243 ) ) ;
return - V_225 ;
}
if ( V_811 -> V_891 [ 0 ] != 0 )
return - V_225 ;
V_988 = F_18 ( V_2 ) ? 16 : 8 ;
V_987 = F_511 ( V_811 -> V_787 ,
V_216 -> V_221 ? V_988 : 1 ) ;
if ( V_216 -> V_108 . V_383 < V_987 * V_811 -> V_265 [ 0 ] )
return - V_225 ;
F_664 ( & V_239 -> V_108 , V_811 ) ;
V_239 -> V_216 = V_216 ;
V_239 -> V_216 -> V_986 ++ ;
V_220 = F_665 ( V_2 , & V_239 -> V_108 , & V_995 ) ;
if ( V_220 ) {
F_115 ( L_257 , V_220 ) ;
return V_220 ;
}
return 0 ;
}
static struct V_237 *
F_666 ( struct V_1 * V_2 ,
struct V_783 * V_996 ,
struct V_810 * V_811 )
{
struct V_215 * V_216 ;
V_216 = F_494 ( F_495 ( V_2 , V_996 ,
V_811 -> V_997 [ 0 ] ) ) ;
if ( & V_216 -> V_108 == NULL )
return F_506 ( - V_790 ) ;
return F_504 ( V_2 , V_811 , V_216 ) ;
}
static inline void F_667 ( struct V_1 * V_2 )
{
}
static void F_668 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_3 ( V_2 ) || F_15 ( V_2 ) )
V_4 -> V_269 . V_591 = F_26 ;
else if ( F_17 ( V_2 ) )
V_4 -> V_269 . V_591 = F_27 ;
else if ( F_16 ( V_2 ) )
V_4 -> V_269 . V_591 = F_25 ;
else
V_4 -> V_269 . V_591 = F_24 ;
if ( F_61 ( V_2 ) ) {
V_4 -> V_269 . V_922 = F_459 ;
V_4 -> V_269 . V_729 = F_457 ;
V_4 -> V_269 . V_428 = F_269 ;
V_4 -> V_269 . V_429 = F_276 ;
V_4 -> V_269 . V_433 = F_281 ;
V_4 -> V_269 . V_271 = F_166 ;
} else if ( F_3 ( V_2 ) ) {
V_4 -> V_269 . V_922 = F_418 ;
V_4 -> V_269 . V_729 = F_410 ;
V_4 -> V_269 . V_428 = F_257 ;
V_4 -> V_269 . V_429 = F_275 ;
V_4 -> V_269 . V_433 = F_280 ;
V_4 -> V_269 . V_271 = F_166 ;
} else if ( F_17 ( V_2 ) ) {
V_4 -> V_269 . V_922 = F_378 ;
V_4 -> V_269 . V_729 = F_373 ;
V_4 -> V_269 . V_428 = F_289 ;
V_4 -> V_269 . V_429 = F_292 ;
V_4 -> V_269 . V_433 = F_293 ;
V_4 -> V_269 . V_271 = F_159 ;
} else {
V_4 -> V_269 . V_922 = F_378 ;
V_4 -> V_269 . V_729 = F_373 ;
V_4 -> V_269 . V_428 = F_290 ;
V_4 -> V_269 . V_429 = F_292 ;
V_4 -> V_269 . V_433 = F_293 ;
V_4 -> V_269 . V_271 = F_159 ;
}
if ( F_17 ( V_2 ) )
V_4 -> V_269 . V_451 =
F_317 ;
else if ( F_364 ( V_2 ) || ( F_366 ( V_2 ) && ! F_669 ( V_2 ) ) )
V_4 -> V_269 . V_451 =
F_318 ;
else if ( F_316 ( V_2 ) )
V_4 -> V_269 . V_451 =
F_319 ;
else if ( F_365 ( V_2 ) || F_74 ( V_2 ) )
V_4 -> V_269 . V_451 =
F_320 ;
else if ( F_16 ( V_2 ) )
V_4 -> V_269 . V_451 =
F_321 ;
else if ( F_670 ( V_2 ) )
V_4 -> V_269 . V_451 =
F_323 ;
else if ( F_75 ( V_2 ) )
V_4 -> V_269 . V_451 =
F_324 ;
else if ( F_671 ( V_2 ) )
V_4 -> V_269 . V_451 =
F_325 ;
else
V_4 -> V_269 . V_451 =
F_326 ;
if ( F_3 ( V_2 ) ) {
if ( F_6 ( V_2 ) ) {
V_4 -> V_269 . V_360 = F_188 ;
V_4 -> V_269 . V_763 = F_472 ;
} else if ( F_196 ( V_2 ) ) {
V_4 -> V_269 . V_360 = F_194 ;
V_4 -> V_269 . V_763 = F_472 ;
} else if ( F_71 ( V_2 ) ) {
V_4 -> V_269 . V_360 = F_197 ;
V_4 -> V_269 . V_763 = F_472 ;
V_4 -> V_269 . V_931 =
F_187 ;
} else if ( F_72 ( V_2 ) || F_672 ( V_2 ) ) {
V_4 -> V_269 . V_360 = V_998 ;
V_4 -> V_269 . V_763 = F_468 ;
V_4 -> V_269 . V_931 =
F_456 ;
}
} else if ( F_15 ( V_2 ) ) {
V_4 -> V_269 . V_763 = F_467 ;
} else if ( F_17 ( V_2 ) )
V_4 -> V_269 . V_763 = F_472 ;
V_4 -> V_269 . V_896 = F_566 ;
switch ( F_39 ( V_2 ) -> V_77 ) {
case 2 :
V_4 -> V_269 . V_896 = F_554 ;
break;
case 3 :
V_4 -> V_269 . V_896 = F_559 ;
break;
case 4 :
case 5 :
V_4 -> V_269 . V_896 = F_560 ;
break;
case 6 :
V_4 -> V_269 . V_896 = F_561 ;
break;
case 7 :
case 8 :
V_4 -> V_269 . V_896 = F_562 ;
break;
}
}
static void F_673 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_138 |= V_139 ;
F_674 ( L_258 ) ;
}
static void F_675 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_138 |= V_493 ;
F_674 ( L_259 ) ;
}
static void F_676 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_138 |= V_999 ;
F_674 ( L_260 ) ;
}
static void F_677 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_138 |= V_1000 ;
F_674 ( L_261 ) ;
}
static int F_678 ( const struct V_1001 * V_193 )
{
F_674 ( L_262 , V_193 -> V_1002 ) ;
return 1 ;
}
static void F_679 ( struct V_1 * V_2 )
{
struct V_1003 * V_1004 = V_2 -> V_456 ;
int V_143 ;
for ( V_143 = 0 ; V_143 < F_198 ( V_1005 ) ; V_143 ++ ) {
struct V_1006 * V_1007 = & V_1005 [ V_143 ] ;
if ( V_1004 -> V_1008 == V_1007 -> V_1008 &&
( V_1004 -> V_1009 == V_1007 -> V_1009 ||
V_1007 -> V_1009 == V_1010 ) &&
( V_1004 -> V_1011 == V_1007 -> V_1011 ||
V_1007 -> V_1011 == V_1010 ) )
V_1007 -> V_1012 ( V_2 ) ;
}
for ( V_143 = 0 ; V_143 < F_198 ( V_1013 ) ; V_143 ++ ) {
if ( F_680 ( * V_1013 [ V_143 ] . V_1014 ) != 0 )
V_1013 [ V_143 ] . V_1012 ( V_2 ) ;
}
}
static void F_681 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_10 V_1015 ;
T_1 V_1016 = F_682 ( V_2 ) ;
F_683 ( V_2 -> V_456 , V_1017 ) ;
F_684 ( V_1018 , V_1019 ) ;
V_1015 = F_685 ( V_1020 ) ;
F_684 ( V_1015 | 1 << 5 , V_1020 ) ;
F_686 ( V_2 -> V_456 , V_1017 ) ;
F_114 ( 300 ) ;
F_40 ( V_1016 , V_1021 ) ;
F_113 ( V_1016 ) ;
}
void F_687 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_437 ( V_2 ) ;
F_688 ( V_2 ) ;
if ( F_17 ( V_2 ) )
F_40 ( F_51 ( V_134 ) , F_4 ( F_51 ( V_134 ) ) |
V_187 ) ;
F_107 ( V_2 ) ;
F_53 ( & V_2 -> V_286 ) ;
F_689 ( V_2 ) ;
F_55 ( & V_2 -> V_286 ) ;
}
void F_690 ( struct V_1 * V_2 )
{
F_691 ( V_2 ) ;
}
void F_692 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_143 , V_325 , V_220 ;
F_693 ( V_2 ) ;
V_2 -> V_603 . V_1022 = 0 ;
V_2 -> V_603 . V_1023 = 0 ;
V_2 -> V_603 . V_1024 = 24 ;
V_2 -> V_603 . V_1025 = 1 ;
V_2 -> V_603 . V_822 = & V_1026 ;
F_679 ( V_2 ) ;
F_694 ( V_2 ) ;
if ( F_39 ( V_2 ) -> V_285 == 0 )
return;
F_668 ( V_2 ) ;
if ( F_18 ( V_2 ) ) {
V_2 -> V_603 . V_1027 = 2048 ;
V_2 -> V_603 . V_1028 = 2048 ;
} else if ( F_631 ( V_2 ) ) {
V_2 -> V_603 . V_1027 = 4096 ;
V_2 -> V_603 . V_1028 = 4096 ;
} else {
V_2 -> V_603 . V_1027 = 8192 ;
V_2 -> V_603 . V_1028 = 8192 ;
}
V_2 -> V_603 . V_1029 = V_4 -> V_1030 . V_1031 ;
F_36 ( L_263 ,
F_39 ( V_2 ) -> V_285 ,
F_39 ( V_2 ) -> V_285 > 1 ? L_264 : L_265 ) ;
F_84 (i) {
F_628 ( V_2 , V_143 ) ;
for ( V_325 = 0 ; V_325 < V_4 -> V_147 ; V_325 ++ ) {
V_220 = F_695 ( V_2 , V_143 , V_325 ) ;
if ( V_220 )
F_36 ( L_266 ,
F_69 ( V_143 ) , F_87 ( V_143 , V_325 ) , V_220 ) ;
}
}
F_617 ( V_2 ) ;
F_627 ( V_2 ) ;
F_681 ( V_2 ) ;
F_640 ( V_2 ) ;
F_267 ( V_2 ) ;
}
static void
F_696 ( struct V_438 * V_431 )
{
V_431 -> V_108 . V_434 = V_435 ;
V_431 -> V_108 . V_23 = NULL ;
V_431 -> V_23 -> V_427 = false ;
V_431 -> V_23 -> V_108 . V_21 = NULL ;
}
static void F_697 ( struct V_1 * V_2 )
{
struct V_438 * V_431 ;
struct V_430 * V_1032 = NULL ;
struct V_817 V_821 ;
F_172 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_431 -> V_23 -> type == V_34 ) {
V_1032 = & V_431 -> V_108 ;
break;
}
}
if ( ! V_1032 )
return;
if ( F_518 ( V_1032 , NULL , & V_821 ) )
F_522 ( V_1032 , & V_821 ) ;
}
static bool
F_698 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_79 , V_101 ;
if ( F_39 ( V_2 ) -> V_285 == 1 )
return true ;
V_79 = F_81 ( ! V_21 -> V_141 ) ;
V_101 = F_4 ( V_79 ) ;
if ( ( V_101 & V_142 ) &&
( ! ! ( V_101 & V_145 ) == V_21 -> V_71 ) )
return false ;
return true ;
}
static void F_699 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_79 ;
V_79 = F_45 ( V_21 -> V_67 . V_73 ) ;
F_40 ( V_79 , F_4 ( V_79 ) & ~ V_1033 ) ;
if ( F_39 ( V_2 ) -> V_77 < 4 && ! F_698 ( V_21 ) ) {
struct V_438 * V_431 ;
bool V_141 ;
F_36 ( L_267 ,
V_21 -> V_108 . V_108 . V_193 ) ;
V_141 = V_21 -> V_141 ;
V_21 -> V_141 = ! V_141 ;
V_4 -> V_269 . V_429 ( & V_21 -> V_108 ) ;
V_21 -> V_141 = V_141 ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_431 -> V_23 -> V_108 . V_21 != & V_21 -> V_108 )
continue;
F_696 ( V_431 ) ;
}
F_2 ( V_21 -> V_65 ) ;
V_21 -> V_108 . V_99 = false ;
}
if ( V_4 -> V_138 & V_139 &&
V_21 -> V_71 == V_125 && ! V_21 -> V_65 ) {
F_697 ( V_2 ) ;
}
F_295 ( & V_21 -> V_108 ) ;
if ( V_21 -> V_65 != V_21 -> V_108 . V_99 ) {
struct V_22 * V_23 ;
F_36 ( L_268 ,
V_21 -> V_108 . V_108 . V_193 ,
V_21 -> V_108 . V_99 ? L_192 : L_193 ,
V_21 -> V_65 ? L_192 : L_193 ) ;
V_21 -> V_108 . V_99 = V_21 -> V_65 ;
F_2 ( V_21 -> V_65 ) ;
F_10 (dev, &crtc->base, encoder) {
F_2 ( V_23 -> V_427 ) ;
V_23 -> V_108 . V_21 = NULL ;
}
}
}
static void F_700 ( struct V_22 * V_23 )
{
struct V_438 * V_431 ;
struct V_1 * V_2 = V_23 -> V_108 . V_2 ;
bool V_1034 = V_23 -> V_108 . V_21 &&
F_30 ( V_23 -> V_108 . V_21 ) -> V_65 ;
if ( V_23 -> V_427 && ! V_1034 ) {
F_36 ( L_269 ,
V_23 -> V_108 . V_108 . V_193 ,
F_464 ( & V_23 -> V_108 ) ) ;
if ( V_23 -> V_108 . V_21 ) {
F_36 ( L_270 ,
V_23 -> V_108 . V_108 . V_193 ,
F_464 ( & V_23 -> V_108 ) ) ;
V_23 -> V_195 ( V_23 ) ;
}
F_172 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_431 -> V_23 != V_23 )
continue;
F_696 ( V_431 ) ;
}
}
}
void F_701 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_1016 = F_682 ( V_2 ) ;
if ( F_702 ( V_2 ) &&
( F_4 ( V_662 ) & V_1035 ) == 0 )
return;
if ( ! ( F_4 ( V_1016 ) & V_1021 ) ) {
F_36 ( L_271 ) ;
F_681 ( V_2 ) ;
}
}
static void F_703 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_71 V_71 ;
struct V_64 * V_21 ;
struct V_22 * V_23 ;
struct V_438 * V_431 ;
int V_143 ;
F_172 (crtc, &dev->mode_config.crtc_list,
base.head) {
memset ( & V_21 -> V_67 , 0 , sizeof( V_21 -> V_67 ) ) ;
V_21 -> V_65 = V_4 -> V_269 . V_922 ( V_21 ,
& V_21 -> V_67 ) ;
V_21 -> V_108 . V_99 = V_21 -> V_65 ;
V_21 -> V_213 = V_21 -> V_65 ;
F_36 ( L_272 ,
V_21 -> V_108 . V_108 . V_193 ,
V_21 -> V_65 ? L_192 : L_193 ) ;
}
if ( F_61 ( V_2 ) )
F_704 ( V_2 ) ;
for ( V_143 = 0 ; V_143 < V_4 -> V_377 ; V_143 ++ ) {
struct V_107 * V_111 = & V_4 -> V_110 [ V_143 ] ;
V_111 -> V_192 = V_111 -> V_114 ( V_4 , V_111 , & V_111 -> V_113 ) ;
V_111 -> V_65 = 0 ;
F_172 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_21 -> V_65 && F_56 ( V_21 ) == V_111 )
V_111 -> V_65 ++ ;
}
V_111 -> V_191 = V_111 -> V_65 ;
F_36 ( L_273 ,
V_111 -> V_115 , V_111 -> V_191 , V_111 -> V_192 ) ;
}
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_71 = 0 ;
if ( V_23 -> V_114 ( V_23 , & V_71 ) ) {
V_21 = F_30 ( V_4 -> V_72 [ V_71 ] ) ;
V_23 -> V_108 . V_21 = & V_21 -> V_108 ;
V_23 -> V_923 ( V_23 , & V_21 -> V_67 ) ;
} else {
V_23 -> V_108 . V_21 = NULL ;
}
V_23 -> V_427 = false ;
F_36 ( L_274 ,
V_23 -> V_108 . V_108 . V_193 ,
F_464 ( & V_23 -> V_108 ) ,
V_23 -> V_108 . V_21 ? L_192 : L_193 ,
F_69 ( V_71 ) ) ;
}
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_431 -> V_114 ( V_431 ) ) {
V_431 -> V_108 . V_434 = V_437 ;
V_431 -> V_23 -> V_427 = true ;
V_431 -> V_108 . V_23 = & V_431 -> V_23 -> V_108 ;
} else {
V_431 -> V_108 . V_434 = V_435 ;
V_431 -> V_108 . V_23 = NULL ;
}
F_36 ( L_275 ,
V_431 -> V_108 . V_108 . V_193 ,
F_304 ( & V_431 -> V_108 ) ,
V_431 -> V_108 . V_23 ? L_192 : L_193 ) ;
}
}
void F_705 ( struct V_1 * V_2 ,
bool V_1036 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_71 V_71 ;
struct V_64 * V_21 ;
struct V_22 * V_23 ;
int V_143 ;
F_703 ( V_2 ) ;
F_172 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_21 -> V_65 && V_287 ) {
F_370 ( V_21 , & V_21 -> V_67 ) ;
F_36 ( L_276 ,
V_21 -> V_108 . V_108 . V_193 ) ;
F_582 ( & V_21 -> V_108 . V_370 ) ;
}
}
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_700 ( V_23 ) ;
}
F_84 (pipe) {
V_21 = F_30 ( V_4 -> V_72 [ V_71 ] ) ;
F_699 ( V_21 ) ;
F_580 ( V_21 , & V_21 -> V_67 , L_277 ) ;
}
for ( V_143 = 0 ; V_143 < V_4 -> V_377 ; V_143 ++ ) {
struct V_107 * V_111 = & V_4 -> V_110 [ V_143 ] ;
if ( ! V_111 -> V_192 || V_111 -> V_65 )
continue;
F_36 ( L_278 , V_111 -> V_115 ) ;
V_111 -> V_195 ( V_4 , V_111 ) ;
V_111 -> V_192 = false ;
}
if ( F_72 ( V_2 ) )
F_706 ( V_2 ) ;
if ( V_1036 ) {
F_701 ( V_2 ) ;
F_84 (pipe) {
struct V_20 * V_21 =
V_4 -> V_72 [ V_71 ] ;
F_603 ( V_21 , & V_21 -> V_370 , V_21 -> V_230 , V_21 -> V_231 ,
V_21 -> V_66 ) ;
}
} else {
F_575 ( V_2 ) ;
}
F_306 ( V_2 ) ;
}
void F_707 ( struct V_1 * V_2 )
{
F_687 ( V_2 ) ;
F_708 ( V_2 ) ;
F_53 ( & V_2 -> V_603 . V_272 ) ;
F_709 ( V_2 ) ;
F_705 ( V_2 , false ) ;
F_55 ( & V_2 -> V_603 . V_272 ) ;
}
void F_710 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_430 * V_431 ;
F_711 ( V_2 ) ;
F_538 ( & V_4 -> V_1037 ) ;
F_712 ( V_2 ) ;
F_53 ( & V_2 -> V_286 ) ;
F_713 () ;
F_172 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_21 -> V_66 )
continue;
F_170 ( V_21 ) ;
}
F_267 ( V_2 ) ;
F_714 ( V_2 ) ;
F_715 ( V_2 ) ;
F_55 ( & V_2 -> V_286 ) ;
F_716 () ;
F_717 ( V_2 ) ;
F_172 (connector, &dev->mode_config.connector_list, head)
F_718 ( V_431 ) ;
F_719 ( V_2 ) ;
F_720 ( V_2 ) ;
}
struct V_436 * F_721 ( struct V_430 * V_431 )
{
return & F_482 ( V_431 ) -> V_108 ;
}
void F_722 ( struct V_438 * V_431 ,
struct V_22 * V_23 )
{
V_431 -> V_23 = V_23 ;
F_723 ( & V_431 -> V_108 ,
& V_23 -> V_108 ) ;
}
int F_724 ( struct V_1 * V_2 , bool V_100 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned V_79 = F_39 ( V_2 ) -> V_77 >= 6 ? V_1038 : V_1039 ;
T_5 V_1040 ;
F_322 ( V_4 -> V_1041 , V_79 , & V_1040 ) ;
if ( V_100 )
V_1040 &= ~ V_1042 ;
else
V_1040 |= V_1042 ;
F_725 ( V_4 -> V_1041 , V_79 , V_1040 ) ;
return 0 ;
}
struct V_1043 *
F_726 ( struct V_1 * V_2 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_1043 * error ;
int V_1044 [] = {
V_206 ,
V_1045 ,
V_1046 ,
V_564 ,
} ;
int V_143 ;
if ( F_39 ( V_2 ) -> V_285 == 0 )
return NULL ;
error = F_505 ( sizeof( * error ) , V_1047 ) ;
if ( error == NULL )
return NULL ;
if ( F_702 ( V_2 ) )
error -> V_1048 = F_4 ( V_662 ) ;
F_84 (i) {
if ( ! F_78 ( V_2 , F_449 ( V_143 ) ) )
continue;
if ( F_39 ( V_2 ) -> V_77 <= 6 || F_17 ( V_2 ) ) {
error -> V_1049 [ V_143 ] . V_414 = F_4 ( F_76 ( V_143 ) ) ;
error -> V_1049 [ V_143 ] . V_1050 = F_4 ( F_492 ( V_143 ) ) ;
error -> V_1049 [ V_143 ] . V_108 = F_4 ( F_286 ( V_143 ) ) ;
} else {
error -> V_1049 [ V_143 ] . V_414 = F_4 ( F_73 ( V_143 ) ) ;
error -> V_1049 [ V_143 ] . V_1050 = F_4 ( F_491 ( V_143 ) ) ;
error -> V_1049 [ V_143 ] . V_108 = F_4 ( F_490 ( V_143 ) ) ;
}
error -> V_141 [ V_143 ] . V_414 = F_4 ( F_81 ( V_143 ) ) ;
error -> V_141 [ V_143 ] . V_990 = F_4 ( F_162 ( V_143 ) ) ;
if ( F_39 ( V_2 ) -> V_77 <= 3 ) {
error -> V_141 [ V_143 ] . V_383 = F_4 ( F_374 ( V_143 ) ) ;
error -> V_141 [ V_143 ] . V_382 = F_4 ( F_375 ( V_143 ) ) ;
}
if ( F_39 ( V_2 ) -> V_77 <= 7 && ! F_72 ( V_2 ) )
error -> V_141 [ V_143 ] . V_788 = F_4 ( F_142 ( V_143 ) ) ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
error -> V_141 [ V_143 ] . V_1051 = F_4 ( F_141 ( V_143 ) ) ;
error -> V_141 [ V_143 ] . V_1052 = F_4 ( F_164 ( V_143 ) ) ;
}
error -> V_71 [ V_143 ] . V_1053 = F_4 ( F_179 ( V_143 ) ) ;
}
error -> V_1054 = F_39 ( V_2 ) -> V_285 ;
if ( F_61 ( V_4 -> V_2 ) )
error -> V_1054 ++ ;
for ( V_143 = 0 ; V_143 < error -> V_1054 ; V_143 ++ ) {
enum V_70 V_73 = V_1044 [ V_143 ] ;
if ( ! F_78 ( V_2 ,
F_79 ( V_73 ) ) )
continue;
error -> V_70 [ V_143 ] . V_73 = V_73 ;
error -> V_70 [ V_143 ] . V_1055 = F_4 ( F_45 ( V_73 ) ) ;
error -> V_70 [ V_143 ] . V_568 = F_4 ( F_219 ( V_73 ) ) ;
error -> V_70 [ V_143 ] . V_1056 = F_4 ( F_221 ( V_73 ) ) ;
error -> V_70 [ V_143 ] . V_847 = F_4 ( F_223 ( V_73 ) ) ;
error -> V_70 [ V_143 ] . V_570 = F_4 ( F_225 ( V_73 ) ) ;
error -> V_70 [ V_143 ] . V_1057 = F_4 ( F_227 ( V_73 ) ) ;
error -> V_70 [ V_143 ] . V_849 = F_4 ( F_229 ( V_73 ) ) ;
}
return error ;
}
void
F_727 ( struct V_1058 * V_11 ,
struct V_1 * V_2 ,
struct V_1043 * error )
{
int V_143 ;
if ( ! error )
return;
F_728 ( V_11 , L_279 , F_39 ( V_2 ) -> V_285 ) ;
if ( F_702 ( V_2 ) )
F_728 ( V_11 , L_280 ,
error -> V_1048 ) ;
F_84 (i) {
F_728 ( V_11 , L_281 , V_143 ) ;
F_728 ( V_11 , L_282 , error -> V_71 [ V_143 ] . V_1053 ) ;
F_728 ( V_11 , L_283 , V_143 ) ;
F_728 ( V_11 , L_284 , error -> V_141 [ V_143 ] . V_414 ) ;
F_728 ( V_11 , L_285 , error -> V_141 [ V_143 ] . V_990 ) ;
if ( F_39 ( V_2 ) -> V_77 <= 3 ) {
F_728 ( V_11 , L_286 , error -> V_141 [ V_143 ] . V_383 ) ;
F_728 ( V_11 , L_287 , error -> V_141 [ V_143 ] . V_382 ) ;
}
if ( F_39 ( V_2 ) -> V_77 <= 7 && ! F_72 ( V_2 ) )
F_728 ( V_11 , L_288 , error -> V_141 [ V_143 ] . V_788 ) ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
F_728 ( V_11 , L_289 , error -> V_141 [ V_143 ] . V_1051 ) ;
F_728 ( V_11 , L_290 , error -> V_141 [ V_143 ] . V_1052 ) ;
}
F_728 ( V_11 , L_291 , V_143 ) ;
F_728 ( V_11 , L_284 , error -> V_1049 [ V_143 ] . V_414 ) ;
F_728 ( V_11 , L_287 , error -> V_1049 [ V_143 ] . V_1050 ) ;
F_728 ( V_11 , L_292 , error -> V_1049 [ V_143 ] . V_108 ) ;
}
for ( V_143 = 0 ; V_143 < error -> V_1054 ; V_143 ++ ) {
F_728 ( V_11 , L_293 ,
F_581 ( error -> V_70 [ V_143 ] . V_73 ) ) ;
F_728 ( V_11 , L_294 , error -> V_70 [ V_143 ] . V_1055 ) ;
F_728 ( V_11 , L_295 , error -> V_70 [ V_143 ] . V_568 ) ;
F_728 ( V_11 , L_296 , error -> V_70 [ V_143 ] . V_1056 ) ;
F_728 ( V_11 , L_297 , error -> V_70 [ V_143 ] . V_847 ) ;
F_728 ( V_11 , L_298 , error -> V_70 [ V_143 ] . V_570 ) ;
F_728 ( V_11 , L_299 , error -> V_70 [ V_143 ] . V_1057 ) ;
F_728 ( V_11 , L_300 , error -> V_70 [ V_143 ] . V_849 ) ;
}
}
