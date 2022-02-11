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
if ( F_2 ( clock -> V_17 == 0 || clock -> V_14 == 0 ) )
return;
clock -> V_18 = F_8 ( V_10 * clock -> V_11 , clock -> V_17 ) ;
clock -> V_19 = F_8 ( clock -> V_18 , clock -> V_14 ) ;
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
if ( F_2 ( clock -> V_17 == 0 || clock -> V_14 == 0 ) )
return;
clock -> V_18 = F_8 ( V_10 * clock -> V_11 , clock -> V_17 ) ;
clock -> V_19 = F_8 ( clock -> V_18 , clock -> V_14 ) ;
}
static T_4 F_20 ( struct V_47 * V_47 )
{
return 5 * ( V_47 -> V_12 + 2 ) + ( V_47 -> V_13 + 2 ) ;
}
static void F_21 ( int V_10 , T_2 * clock )
{
clock -> V_11 = F_20 ( clock ) ;
clock -> V_14 = clock -> V_15 * clock -> V_16 ;
if ( F_2 ( clock -> V_17 + 2 == 0 || clock -> V_14 == 0 ) )
return;
clock -> V_18 = F_8 ( V_10 * clock -> V_11 , clock -> V_17 + 2 ) ;
clock -> V_19 = F_8 ( clock -> V_18 , clock -> V_14 ) ;
}
static bool F_22 ( struct V_1 * V_2 ,
const T_3 * V_24 ,
const T_2 * clock )
{
if ( clock -> V_17 < V_24 -> V_17 . V_48 || V_24 -> V_17 . V_49 < clock -> V_17 )
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
if ( clock -> V_18 < V_24 -> V_18 . V_48 || V_24 -> V_18 . V_49 < clock -> V_18 )
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
for ( clock . V_17 = V_24 -> V_17 . V_48 ;
clock . V_17 <= V_24 -> V_17 . V_49 ; clock . V_17 ++ ) {
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
for ( clock . V_17 = V_24 -> V_17 . V_48 ;
clock . V_17 <= V_24 -> V_17 . V_49 ; clock . V_17 ++ ) {
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
V_58 = V_24 -> V_17 . V_49 ;
for ( clock . V_17 = V_24 -> V_17 . V_48 ; clock . V_17 <= V_58 ; clock . V_17 ++ ) {
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
V_58 = clock . V_17 ;
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
int V_58 = V_48 ( V_24 -> V_17 . V_49 , V_10 / 19200 ) ;
bool V_59 = false ;
V_50 *= 5 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
for ( clock . V_17 = V_24 -> V_17 . V_48 ; clock . V_17 <= V_58 ; clock . V_17 ++ ) {
for ( clock . V_15 = V_24 -> V_15 . V_49 ; clock . V_15 >= V_24 -> V_15 . V_48 ; clock . V_15 -- ) {
for ( clock . V_16 = V_24 -> V_16 . V_54 ; clock . V_16 >= V_24 -> V_16 . V_55 ;
clock . V_16 -= clock . V_16 > 10 ? 2 : 1 ) {
clock . V_14 = clock . V_15 * clock . V_16 ;
for ( clock . V_12 = V_24 -> V_12 . V_48 ; clock . V_12 <= V_24 -> V_12 . V_49 ; clock . V_12 ++ ) {
unsigned int V_62 , V_63 ;
clock . V_13 = F_8 ( V_50 * clock . V_14 * clock . V_17 ,
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
if ( F_15 ( V_2 ) || F_39 ( V_2 ) -> V_77 >= 5 ) {
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
V_102 = F_4 ( V_135 ) & V_136 ;
else if ( F_39 ( V_2 ) -> V_77 <= 6 || F_17 ( V_2 ) )
V_102 = F_4 ( F_73 ( V_71 ) ) & V_137 ;
else
V_102 = F_4 ( F_74 ( V_71 ) ) & V_137 ;
F_46 ( V_102 != V_100 ,
L_24 ,
F_69 ( V_71 ) , F_49 ( V_100 ) , F_49 ( V_102 ) ) ;
}
void F_75 ( struct V_3 * V_4 ,
enum V_71 V_71 , bool V_100 )
{
int V_79 ;
T_1 V_101 ;
bool V_102 ;
enum V_70 V_73 = F_31 ( V_4 ,
V_71 ) ;
if ( V_71 == V_125 && V_4 -> V_138 & V_139 )
V_100 = true ;
if ( ! F_76 ( V_4 -> V_2 ,
F_77 ( V_73 ) ) ) {
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
static void F_78 ( struct V_3 * V_4 ,
enum V_141 V_141 , bool V_100 )
{
int V_79 ;
T_1 V_101 ;
bool V_102 ;
V_79 = F_79 ( V_141 ) ;
V_101 = F_4 ( V_79 ) ;
V_102 = ! ! ( V_101 & V_142 ) ;
F_46 ( V_102 != V_100 ,
L_26 ,
F_80 ( V_141 ) , F_49 ( V_100 ) , F_49 ( V_102 ) ) ;
}
static void F_81 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_79 , V_143 ;
T_1 V_101 ;
int V_144 ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
V_79 = F_79 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
F_46 ( ( V_101 & V_142 ) ,
L_27 ,
F_80 ( V_71 ) ) ;
return;
}
F_82 (i) {
V_79 = F_79 ( V_143 ) ;
V_101 = F_4 ( V_79 ) ;
V_144 = ( V_101 & V_145 ) >>
V_146 ;
F_46 ( ( V_101 & V_142 ) && V_71 == V_144 ,
L_28 ,
F_80 ( V_143 ) , F_69 ( V_71 ) ) ;
}
}
static void F_83 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_79 , V_143 ;
T_1 V_101 ;
if ( F_17 ( V_2 ) ) {
for ( V_143 = 0 ; V_143 < V_4 -> V_147 ; V_143 ++ ) {
V_79 = F_84 ( V_71 , V_143 ) ;
V_101 = F_4 ( V_79 ) ;
F_46 ( ( V_101 & V_148 ) ,
L_29 ,
F_85 ( V_71 , V_143 ) , F_69 ( V_71 ) ) ;
}
} else if ( F_39 ( V_2 ) -> V_77 >= 7 ) {
V_79 = F_86 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
F_46 ( ( V_101 & V_149 ) ,
L_29 ,
F_80 ( V_71 ) , F_69 ( V_71 ) ) ;
} else if ( F_39 ( V_2 ) -> V_77 >= 5 ) {
V_79 = F_87 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
F_46 ( ( V_101 & V_150 ) ,
L_29 ,
F_80 ( V_71 ) , F_69 ( V_71 ) ) ;
}
}
static void F_88 ( struct V_3 * V_4 )
{
T_1 V_101 ;
bool V_99 ;
F_2 ( ! ( F_48 ( V_4 -> V_2 ) || F_89 ( V_4 -> V_2 ) ) ) ;
V_101 = F_4 ( V_151 ) ;
V_99 = ! ! ( V_101 & ( V_152 | V_153 |
V_154 ) ) ;
F_46 ( ! V_99 , L_30 ) ;
}
static void F_90 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
int V_79 ;
T_1 V_101 ;
bool V_99 ;
V_79 = F_91 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
V_99 = ! ! ( V_101 & V_155 ) ;
F_46 ( V_99 ,
L_31 ,
F_69 ( V_71 ) ) ;
}
static bool F_92 ( struct V_3 * V_4 ,
enum V_71 V_71 , T_1 V_156 , T_1 V_101 )
{
if ( ( V_101 & V_157 ) == 0 )
return false ;
if ( F_89 ( V_4 -> V_2 ) ) {
T_1 V_158 = F_93 ( V_71 ) ;
T_1 V_159 = F_4 ( V_158 ) ;
if ( ( V_159 & V_160 ) != V_156 )
return false ;
} else {
if ( ( V_101 & V_161 ) != ( V_71 << 30 ) )
return false ;
}
return true ;
}
static bool F_94 ( struct V_3 * V_4 ,
enum V_71 V_71 , T_1 V_101 )
{
if ( ( V_101 & V_162 ) == 0 )
return false ;
if ( F_89 ( V_4 -> V_2 ) ) {
if ( ( V_101 & V_163 ) != F_95 ( V_71 ) )
return false ;
} else {
if ( ( V_101 & V_164 ) != F_96 ( V_71 ) )
return false ;
}
return true ;
}
static bool F_97 ( struct V_3 * V_4 ,
enum V_71 V_71 , T_1 V_101 )
{
if ( ( V_101 & V_165 ) == 0 )
return false ;
if ( F_89 ( V_4 -> V_2 ) ) {
if ( ( V_101 & V_166 ) != F_98 ( V_71 ) )
return false ;
} else {
if ( ( V_101 & V_167 ) != F_99 ( V_71 ) )
return false ;
}
return true ;
}
static bool F_100 ( struct V_3 * V_4 ,
enum V_71 V_71 , T_1 V_101 )
{
if ( ( V_101 & V_168 ) == 0 )
return false ;
if ( F_89 ( V_4 -> V_2 ) ) {
if ( ( V_101 & V_166 ) != F_98 ( V_71 ) )
return false ;
} else {
if ( ( V_101 & V_169 ) != F_101 ( V_71 ) )
return false ;
}
return true ;
}
static void F_102 ( struct V_3 * V_4 ,
enum V_71 V_71 , int V_79 , T_1 V_156 )
{
T_1 V_101 = F_4 ( V_79 ) ;
F_46 ( F_92 ( V_4 , V_71 , V_156 , V_101 ) ,
L_32 ,
V_79 , F_69 ( V_71 ) ) ;
F_46 ( F_48 ( V_4 -> V_2 ) && ( V_101 & V_157 ) == 0
&& ( V_101 & V_170 ) ,
L_33 ) ;
}
static void F_103 ( struct V_3 * V_4 ,
enum V_71 V_71 , int V_79 )
{
T_1 V_101 = F_4 ( V_79 ) ;
F_46 ( F_94 ( V_4 , V_71 , V_101 ) ,
L_34 ,
V_79 , F_69 ( V_71 ) ) ;
F_46 ( F_48 ( V_4 -> V_2 ) && ( V_101 & V_162 ) == 0
&& ( V_101 & V_171 ) ,
L_35 ) ;
}
static void F_104 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
int V_79 ;
T_1 V_101 ;
F_102 ( V_4 , V_71 , V_172 , V_173 ) ;
F_102 ( V_4 , V_71 , V_174 , V_175 ) ;
F_102 ( V_4 , V_71 , V_176 , V_177 ) ;
V_79 = V_178 ;
V_101 = F_4 ( V_79 ) ;
F_46 ( F_100 ( V_4 , V_71 , V_101 ) ,
L_36 ,
F_69 ( V_71 ) ) ;
V_79 = V_128 ;
V_101 = F_4 ( V_79 ) ;
F_46 ( F_97 ( V_4 , V_71 , V_101 ) ,
L_37 ,
F_69 ( V_71 ) ) ;
F_103 ( V_4 , V_71 , V_179 ) ;
F_103 ( V_4 , V_71 , V_180 ) ;
F_103 ( V_4 , V_71 , V_181 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_17 ( V_2 ) )
return;
F_106 ( V_182 ) = V_183 ;
}
static void F_107 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_17 ( V_2 ) )
return;
F_40 ( F_51 ( V_134 ) , F_4 ( F_51 ( V_134 ) ) |
V_184 |
V_185 ) ;
F_40 ( V_186 , F_4 ( V_186 ) | V_187 ) ;
}
static void F_108 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_79 = F_51 ( V_21 -> V_71 ) ;
T_1 V_47 = V_21 -> V_67 . V_188 . V_47 ;
F_109 ( V_4 , V_21 -> V_71 ) ;
F_110 ( ! F_17 ( V_4 -> V_2 ) ) ;
if ( F_111 ( V_4 -> V_2 ) && ! F_112 ( V_4 -> V_2 ) )
F_68 ( V_4 , V_21 -> V_71 ) ;
F_40 ( V_79 , V_47 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
if ( F_34 ( ( ( F_4 ( V_79 ) & V_189 ) == V_189 ) , 1 ) )
F_115 ( L_38 , V_21 -> V_71 ) ;
F_40 ( F_116 ( V_21 -> V_71 ) , V_21 -> V_67 . V_188 . V_190 ) ;
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
T_1 V_47 = V_21 -> V_67 . V_188 . V_47 ;
F_109 ( V_4 , V_21 -> V_71 ) ;
F_110 ( V_4 -> V_119 -> V_77 >= 5 ) ;
if ( F_111 ( V_2 ) && ! F_112 ( V_2 ) )
F_68 ( V_4 , V_21 -> V_71 ) ;
F_40 ( V_79 , V_47 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
F_40 ( F_116 ( V_21 -> V_71 ) ,
V_21 -> V_67 . V_188 . V_190 ) ;
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
V_101 = V_185 | V_184 ;
F_40 ( F_51 ( V_71 ) , V_101 ) ;
F_113 ( F_51 ( V_71 ) ) ;
}
void F_120 ( struct V_3 * V_4 ,
struct V_86 * V_191 )
{
T_1 V_192 ;
switch ( V_191 -> V_87 ) {
case V_89 :
V_192 = V_193 ;
break;
case V_91 :
V_192 = V_194 ;
break;
default:
F_121 () ;
}
if ( F_34 ( ( F_4 ( F_51 ( 0 ) ) & V_192 ) == 0 , 1000 ) )
F_46 ( 1 , L_39 ,
F_122 ( V_191 -> V_87 ) , F_4 ( F_51 ( 0 ) ) ) ;
}
static void F_123 ( struct V_64 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_108 . V_2 -> V_5 ;
struct V_107 * V_111 = F_56 ( V_21 ) ;
F_110 ( V_4 -> V_119 -> V_77 < 5 ) ;
if ( F_2 ( V_111 == NULL ) )
return;
if ( F_2 ( V_111 -> V_195 == 0 ) )
return;
F_36 ( L_40 ,
V_111 -> V_115 , V_111 -> V_65 , V_111 -> V_196 ,
V_21 -> V_108 . V_108 . V_197 ) ;
if ( V_111 -> V_65 ++ ) {
F_2 ( ! V_111 -> V_196 ) ;
F_124 ( V_4 , V_111 ) ;
return;
}
F_2 ( V_111 -> V_196 ) ;
F_36 ( L_41 , V_111 -> V_115 ) ;
V_111 -> V_198 ( V_4 , V_111 ) ;
V_111 -> V_196 = true ;
}
static void F_125 ( struct V_64 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_108 . V_2 -> V_5 ;
struct V_107 * V_111 = F_56 ( V_21 ) ;
F_110 ( V_4 -> V_119 -> V_77 < 5 ) ;
if ( F_2 ( V_111 == NULL ) )
return;
if ( F_2 ( V_111 -> V_195 == 0 ) )
return;
F_36 ( L_42 ,
V_111 -> V_115 , V_111 -> V_65 , V_111 -> V_196 ,
V_21 -> V_108 . V_108 . V_197 ) ;
if ( F_2 ( V_111 -> V_65 == 0 ) ) {
F_126 ( V_4 , V_111 ) ;
return;
}
F_124 ( V_4 , V_111 ) ;
F_2 ( ! V_111 -> V_196 ) ;
if ( -- V_111 -> V_65 )
return;
F_36 ( L_43 , V_111 -> V_115 ) ;
V_111 -> V_199 ( V_4 , V_111 ) ;
V_111 -> V_196 = false ;
}
static void F_127 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_20 * V_21 = V_4 -> V_72 [ V_71 ] ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
T_4 V_79 , V_101 , V_200 ;
F_110 ( V_4 -> V_119 -> V_77 < 5 ) ;
F_124 ( V_4 ,
F_56 ( V_64 ) ) ;
F_128 ( V_4 , V_71 ) ;
F_129 ( V_4 , V_71 ) ;
if ( F_89 ( V_2 ) ) {
V_79 = F_130 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
V_101 |= V_201 ;
F_40 ( V_79 , V_101 ) ;
}
V_79 = F_91 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
V_200 = F_4 ( F_45 ( V_71 ) ) ;
if ( F_48 ( V_4 -> V_2 ) ) {
V_101 &= ~ V_202 ;
V_101 |= V_200 & V_202 ;
}
V_101 &= ~ V_203 ;
if ( ( V_200 & V_204 ) == V_205 )
if ( F_48 ( V_4 -> V_2 ) &&
F_9 ( V_21 , V_36 ) )
V_101 |= V_206 ;
else
V_101 |= V_207 ;
else
V_101 |= V_208 ;
F_40 ( V_79 , V_101 | V_155 ) ;
if ( F_34 ( F_4 ( V_79 ) & V_209 , 100 ) )
F_115 ( L_44 , F_69 ( V_71 ) ) ;
}
static void F_131 ( struct V_3 * V_4 ,
enum V_70 V_73 )
{
T_1 V_101 , V_200 ;
F_110 ( V_4 -> V_119 -> V_77 < 5 ) ;
F_128 ( V_4 , (enum V_71 ) V_73 ) ;
F_129 ( V_4 , V_210 ) ;
V_101 = F_4 ( V_211 ) ;
V_101 |= V_201 ;
F_40 ( V_211 , V_101 ) ;
V_101 = V_155 ;
V_200 = F_4 ( F_45 ( V_73 ) ) ;
if ( ( V_200 & V_212 ) ==
V_205 )
V_101 |= V_207 ;
else
V_101 |= V_208 ;
F_40 ( V_213 , V_101 ) ;
if ( F_34 ( F_4 ( V_213 ) & V_209 , 100 ) )
F_115 ( L_45 ) ;
}
static void F_132 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_79 , V_101 ;
F_133 ( V_4 , V_71 ) ;
F_134 ( V_4 , V_71 ) ;
F_104 ( V_4 , V_71 ) ;
V_79 = F_91 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
V_101 &= ~ V_155 ;
F_40 ( V_79 , V_101 ) ;
if ( F_34 ( ( F_4 ( V_79 ) & V_209 ) == 0 , 50 ) )
F_115 ( L_46 , F_69 ( V_71 ) ) ;
if ( ! F_48 ( V_2 ) ) {
V_79 = F_130 ( V_71 ) ;
V_101 = F_4 ( V_79 ) ;
V_101 &= ~ V_201 ;
F_40 ( V_79 , V_101 ) ;
}
}
static void F_135 ( struct V_3 * V_4 )
{
T_1 V_101 ;
V_101 = F_4 ( V_213 ) ;
V_101 &= ~ V_155 ;
F_40 ( V_213 , V_101 ) ;
if ( F_34 ( ( F_4 ( V_213 ) & V_209 ) == 0 , 50 ) )
F_115 ( L_47 ) ;
V_101 = F_4 ( V_211 ) ;
V_101 &= ~ V_201 ;
F_40 ( V_211 , V_101 ) ;
}
static void F_136 ( struct V_3 * V_4 , enum V_71 V_71 ,
bool V_214 , bool V_215 )
{
enum V_70 V_73 = F_31 ( V_4 ,
V_71 ) ;
enum V_71 V_216 ;
int V_79 ;
T_1 V_101 ;
F_81 ( V_4 , V_71 ) ;
F_137 ( V_4 , V_71 ) ;
F_83 ( V_4 , V_71 ) ;
if ( F_58 ( V_4 -> V_2 ) )
V_216 = V_210 ;
else
V_216 = V_71 ;
if ( ! F_3 ( V_4 -> V_2 ) )
if ( V_215 )
F_138 ( V_4 ) ;
else
F_139 ( V_4 , V_71 ) ;
else {
if ( V_214 ) {
F_140 ( V_4 , V_216 ) ;
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
static void F_141 ( struct V_3 * V_4 ,
enum V_71 V_71 )
{
enum V_70 V_73 = F_31 ( V_4 ,
V_71 ) ;
int V_79 ;
T_1 V_101 ;
F_81 ( V_4 , V_71 ) ;
F_137 ( V_4 , V_71 ) ;
F_83 ( V_4 , V_71 ) ;
if ( V_71 == V_125 && ( V_4 -> V_138 & V_139 ) )
return;
V_79 = F_45 ( V_73 ) ;
V_101 = F_4 ( V_79 ) ;
if ( ( V_101 & V_140 ) == 0 )
return;
F_40 ( V_79 , V_101 & ~ V_140 ) ;
F_44 ( V_4 -> V_2 , V_71 ) ;
}
void F_142 ( struct V_3 * V_4 ,
enum V_141 V_141 )
{
T_1 V_79 = V_4 -> V_119 -> V_77 >= 4 ? F_143 ( V_141 ) : F_144 ( V_141 ) ;
F_40 ( V_79 , F_4 ( V_79 ) ) ;
F_113 ( V_79 ) ;
}
static void F_145 ( struct V_3 * V_4 ,
enum V_141 V_141 , enum V_71 V_71 )
{
struct V_64 * V_64 =
F_30 ( V_4 -> V_72 [ V_71 ] ) ;
int V_79 ;
T_1 V_101 ;
F_146 ( V_4 , V_71 ) ;
F_46 ( V_64 -> V_217 , L_48 ) ;
V_64 -> V_217 = true ;
V_79 = F_79 ( V_141 ) ;
V_101 = F_4 ( V_79 ) ;
if ( V_101 & V_142 )
return;
F_40 ( V_79 , V_101 | V_142 ) ;
F_142 ( V_4 , V_141 ) ;
F_37 ( V_4 -> V_2 , V_71 ) ;
}
static void F_147 ( struct V_3 * V_4 ,
enum V_141 V_141 , enum V_71 V_71 )
{
struct V_64 * V_64 =
F_30 ( V_4 -> V_72 [ V_71 ] ) ;
int V_79 ;
T_1 V_101 ;
F_46 ( ! V_64 -> V_217 , L_49 ) ;
V_64 -> V_217 = false ;
V_79 = F_79 ( V_141 ) ;
V_101 = F_4 ( V_79 ) ;
if ( ( V_101 & V_142 ) == 0 )
return;
F_40 ( V_79 , V_101 & ~ V_142 ) ;
F_142 ( V_4 , V_141 ) ;
F_37 ( V_4 -> V_2 , V_71 ) ;
}
static bool F_148 ( struct V_1 * V_2 )
{
#ifdef F_149
if ( F_39 ( V_2 ) -> V_77 >= 6 && V_218 )
return true ;
#endif
return false ;
}
int
F_150 ( struct V_1 * V_2 ,
struct V_219 * V_220 ,
struct V_221 * V_222 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_223 ;
int V_224 ;
switch ( V_220 -> V_225 ) {
case V_226 :
if ( F_151 ( V_2 ) || F_152 ( V_2 ) )
V_223 = 128 * 1024 ;
else if ( F_39 ( V_2 ) -> V_77 >= 4 )
V_223 = 4 * 1024 ;
else
V_223 = 64 * 1024 ;
break;
case V_227 :
V_223 = 0 ;
break;
case V_228 :
F_46 ( 1 , L_50 ) ;
return - V_229 ;
default:
F_121 () ;
}
if ( F_148 ( V_2 ) && V_223 < 256 * 1024 )
V_223 = 256 * 1024 ;
V_4 -> V_230 . V_231 = false ;
V_224 = F_153 ( V_220 , V_223 , V_222 ) ;
if ( V_224 )
goto V_232;
V_224 = F_154 ( V_220 ) ;
if ( V_224 )
goto V_233;
F_155 ( V_220 ) ;
V_4 -> V_230 . V_231 = true ;
return 0 ;
V_233:
F_156 ( V_220 ) ;
V_232:
V_4 -> V_230 . V_231 = true ;
return V_224 ;
}
void F_157 ( struct V_219 * V_220 )
{
F_158 ( V_220 ) ;
F_156 ( V_220 ) ;
}
unsigned long F_159 ( int * V_234 , int * V_235 ,
unsigned int V_225 ,
unsigned int V_236 ,
unsigned int V_237 )
{
if ( V_225 != V_226 ) {
unsigned int V_238 , V_239 ;
V_238 = * V_235 / 8 ;
* V_235 %= 8 ;
V_239 = * V_234 / ( 512 / V_236 ) ;
* V_234 %= 512 / V_236 ;
return V_238 * V_237 * 8 + V_239 * 4096 ;
} else {
unsigned int V_240 ;
V_240 = * V_235 * V_237 + * V_234 * V_236 ;
* V_235 = 0 ;
* V_234 = ( V_240 & 4095 ) / V_236 ;
return V_240 & - 4096 ;
}
}
static int F_160 ( struct V_20 * V_21 , struct V_241 * V_66 ,
int V_234 , int V_235 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_242 * V_243 ;
struct V_219 * V_220 ;
int V_141 = V_64 -> V_141 ;
unsigned long V_244 ;
T_1 V_245 ;
T_1 V_79 ;
switch ( V_141 ) {
case 0 :
case 1 :
break;
default:
F_115 ( L_51 , F_80 ( V_141 ) ) ;
return - V_229 ;
}
V_243 = F_161 ( V_66 ) ;
V_220 = V_243 -> V_220 ;
V_79 = F_79 ( V_141 ) ;
V_245 = F_4 ( V_79 ) ;
V_245 &= ~ V_246 ;
switch ( V_66 -> V_247 ) {
case V_248 :
V_245 |= V_249 ;
break;
case V_250 :
case V_251 :
V_245 |= V_252 ;
break;
case V_253 :
V_245 |= V_254 ;
break;
case V_255 :
case V_256 :
V_245 |= V_257 ;
break;
case V_258 :
case V_259 :
V_245 |= V_260 ;
break;
case V_261 :
case V_262 :
V_245 |= V_263 ;
break;
case V_264 :
case V_265 :
V_245 |= V_266 ;
break;
default:
F_121 () ;
}
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
if ( V_220 -> V_225 != V_226 )
V_245 |= V_267 ;
else
V_245 &= ~ V_267 ;
}
if ( F_15 ( V_2 ) )
V_245 |= V_268 ;
F_40 ( V_79 , V_245 ) ;
V_244 = V_235 * V_66 -> V_269 [ 0 ] + V_234 * ( V_66 -> V_270 / 8 ) ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
V_64 -> V_271 =
F_159 ( & V_234 , & V_235 , V_220 -> V_225 ,
V_66 -> V_270 / 8 ,
V_66 -> V_269 [ 0 ] ) ;
V_244 -= V_64 -> V_271 ;
} else {
V_64 -> V_271 = V_244 ;
}
F_36 ( L_52 ,
F_162 ( V_220 ) , V_244 , V_234 , V_235 ,
V_66 -> V_269 [ 0 ] ) ;
F_40 ( F_163 ( V_141 ) , V_66 -> V_269 [ 0 ] ) ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
F_40 ( F_143 ( V_141 ) ,
F_162 ( V_220 ) + V_64 -> V_271 ) ;
F_40 ( F_164 ( V_141 ) , ( V_235 << 16 ) | V_234 ) ;
F_40 ( F_165 ( V_141 ) , V_244 ) ;
} else
F_40 ( F_144 ( V_141 ) , F_162 ( V_220 ) + V_244 ) ;
F_113 ( V_79 ) ;
return 0 ;
}
static int F_166 ( struct V_20 * V_21 ,
struct V_241 * V_66 , int V_234 , int V_235 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_242 * V_243 ;
struct V_219 * V_220 ;
int V_141 = V_64 -> V_141 ;
unsigned long V_244 ;
T_1 V_245 ;
T_1 V_79 ;
switch ( V_141 ) {
case 0 :
case 1 :
case 2 :
break;
default:
F_115 ( L_51 , F_80 ( V_141 ) ) ;
return - V_229 ;
}
V_243 = F_161 ( V_66 ) ;
V_220 = V_243 -> V_220 ;
V_79 = F_79 ( V_141 ) ;
V_245 = F_4 ( V_79 ) ;
V_245 &= ~ V_246 ;
switch ( V_66 -> V_247 ) {
case V_248 :
V_245 |= V_249 ;
break;
case V_253 :
V_245 |= V_254 ;
break;
case V_255 :
case V_256 :
V_245 |= V_257 ;
break;
case V_258 :
case V_259 :
V_245 |= V_260 ;
break;
case V_261 :
case V_262 :
V_245 |= V_263 ;
break;
case V_264 :
case V_265 :
V_245 |= V_266 ;
break;
default:
F_121 () ;
}
if ( V_220 -> V_225 != V_226 )
V_245 |= V_267 ;
else
V_245 &= ~ V_267 ;
if ( F_167 ( V_2 ) || F_168 ( V_2 ) )
V_245 &= ~ V_268 ;
else
V_245 |= V_268 ;
F_40 ( V_79 , V_245 ) ;
V_244 = V_235 * V_66 -> V_269 [ 0 ] + V_234 * ( V_66 -> V_270 / 8 ) ;
V_64 -> V_271 =
F_159 ( & V_234 , & V_235 , V_220 -> V_225 ,
V_66 -> V_270 / 8 ,
V_66 -> V_269 [ 0 ] ) ;
V_244 -= V_64 -> V_271 ;
F_36 ( L_52 ,
F_162 ( V_220 ) , V_244 , V_234 , V_235 ,
V_66 -> V_269 [ 0 ] ) ;
F_40 ( F_163 ( V_141 ) , V_66 -> V_269 [ 0 ] ) ;
F_40 ( F_143 ( V_141 ) ,
F_162 ( V_220 ) + V_64 -> V_271 ) ;
if ( F_167 ( V_2 ) || F_168 ( V_2 ) ) {
F_40 ( F_169 ( V_141 ) , ( V_235 << 16 ) | V_234 ) ;
} else {
F_40 ( F_164 ( V_141 ) , ( V_235 << 16 ) | V_234 ) ;
F_40 ( F_165 ( V_141 ) , V_244 ) ;
}
F_113 ( V_79 ) ;
return 0 ;
}
static int
F_170 ( struct V_20 * V_21 , struct V_241 * V_66 ,
int V_234 , int V_235 , enum V_272 V_100 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_273 . V_274 )
V_4 -> V_273 . V_274 ( V_2 ) ;
F_171 ( V_21 ) ;
return V_4 -> V_273 . V_275 ( V_21 , V_66 , V_234 , V_235 ) ;
}
void F_172 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 ;
F_173 (crtc, &dev->mode_config.crtc_list, head) {
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_141 V_141 = V_64 -> V_141 ;
F_174 ( V_2 , V_141 ) ;
F_175 ( V_2 , V_141 ) ;
}
F_173 (crtc, &dev->mode_config.crtc_list, head) {
struct V_64 * V_64 = F_30 ( V_21 ) ;
F_53 ( & V_21 -> V_276 ) ;
if ( V_64 -> V_65 && V_21 -> V_66 )
V_4 -> V_273 . V_275 ( V_21 , V_21 -> V_66 ,
V_21 -> V_234 , V_21 -> V_235 ) ;
F_55 ( & V_21 -> V_276 ) ;
}
}
static int
F_176 ( struct V_241 * V_277 )
{
struct V_219 * V_220 = F_161 ( V_277 ) -> V_220 ;
struct V_3 * V_4 = V_220 -> V_108 . V_2 -> V_5 ;
bool V_278 = V_4 -> V_230 . V_231 ;
int V_224 ;
V_4 -> V_230 . V_231 = false ;
V_224 = F_177 ( V_220 ) ;
V_4 -> V_230 . V_231 = V_278 ;
return V_224 ;
}
static void F_178 ( struct V_20 * V_21 , int V_234 , int V_235 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_279 * V_280 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
if ( ! V_2 -> V_281 -> V_282 )
return;
V_280 = V_2 -> V_281 -> V_282 -> V_283 ;
if ( ! V_280 -> V_284 )
return;
switch ( V_64 -> V_71 ) {
case 0 :
V_280 -> V_284 -> V_285 = V_234 ;
V_280 -> V_284 -> V_286 = V_235 ;
break;
case 1 :
V_280 -> V_284 -> V_287 = V_234 ;
V_280 -> V_284 -> V_288 = V_235 ;
break;
default:
break;
}
}
static int
F_179 ( struct V_20 * V_21 , int V_234 , int V_235 ,
struct V_241 * V_66 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_241 * V_277 ;
int V_224 ;
if ( ! V_66 ) {
F_115 ( L_53 ) ;
return 0 ;
}
if ( V_64 -> V_141 > F_39 ( V_2 ) -> V_289 ) {
F_115 ( L_54 ,
F_80 ( V_64 -> V_141 ) ,
F_39 ( V_2 ) -> V_289 ) ;
return - V_229 ;
}
F_53 ( & V_2 -> V_290 ) ;
V_224 = F_150 ( V_2 ,
F_161 ( V_66 ) -> V_220 ,
NULL ) ;
if ( V_224 != 0 ) {
F_55 ( & V_2 -> V_290 ) ;
F_115 ( L_55 ) ;
return V_224 ;
}
if ( V_291 ) {
const struct V_292 * V_68 =
& V_64 -> V_67 . V_68 ;
F_40 ( F_180 ( V_64 -> V_71 ) ,
( ( V_68 -> V_293 - 1 ) << 16 ) |
( V_68 -> V_294 - 1 ) ) ;
if ( ! V_64 -> V_67 . V_295 . V_99 &&
( F_9 ( V_21 , V_25 ) ||
F_9 ( V_21 , V_296 ) ) ) {
F_40 ( F_181 ( V_64 -> V_71 ) , 0 ) ;
F_40 ( F_182 ( V_64 -> V_71 ) , 0 ) ;
F_40 ( F_183 ( V_64 -> V_71 ) , 0 ) ;
}
V_64 -> V_67 . V_297 = V_68 -> V_293 ;
V_64 -> V_67 . V_298 = V_68 -> V_294 ;
}
V_224 = V_4 -> V_273 . V_275 ( V_21 , V_66 , V_234 , V_235 ) ;
if ( V_224 ) {
F_157 ( F_161 ( V_66 ) -> V_220 ) ;
F_55 ( & V_2 -> V_290 ) ;
F_115 ( L_56 ) ;
return V_224 ;
}
V_277 = V_21 -> V_66 ;
V_21 -> V_66 = V_66 ;
V_21 -> V_234 = V_234 ;
V_21 -> V_235 = V_235 ;
if ( V_277 ) {
if ( V_64 -> V_65 && V_277 != V_66 )
F_37 ( V_2 , V_64 -> V_71 ) ;
F_157 ( F_161 ( V_277 ) -> V_220 ) ;
}
F_184 ( V_2 ) ;
F_185 ( V_2 ) ;
F_55 ( & V_2 -> V_290 ) ;
F_178 ( V_21 , V_234 , V_235 ) ;
return 0 ;
}
static void F_186 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
T_1 V_79 , V_299 ;
V_79 = F_63 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
if ( F_187 ( V_2 ) ) {
V_299 &= ~ V_300 ;
V_299 |= V_300 | V_301 ;
} else {
V_299 &= ~ V_302 ;
V_299 |= V_302 | V_301 ;
}
F_40 ( V_79 , V_299 ) ;
V_79 = F_65 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
if ( F_89 ( V_2 ) ) {
V_299 &= ~ V_303 ;
V_299 |= V_304 ;
} else {
V_299 &= ~ V_302 ;
V_299 |= V_302 ;
}
F_40 ( V_79 , V_299 | V_305 ) ;
F_113 ( V_79 ) ;
F_114 ( 1000 ) ;
if ( F_187 ( V_2 ) )
F_40 ( V_79 , F_4 ( V_79 ) | V_306 |
V_307 ) ;
}
static bool F_188 ( struct V_64 * V_21 )
{
return V_21 -> V_108 . V_99 && V_21 -> V_65 &&
V_21 -> V_67 . V_308 ;
}
static void F_189 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_309 =
F_30 ( V_4 -> V_72 [ V_134 ] ) ;
struct V_64 * V_310 =
F_30 ( V_4 -> V_72 [ V_311 ] ) ;
T_4 V_299 ;
if ( ! F_188 ( V_309 ) &&
! F_188 ( V_310 ) ) {
F_2 ( F_4 ( F_65 ( V_134 ) ) & V_118 ) ;
F_2 ( F_4 ( F_65 ( V_311 ) ) & V_118 ) ;
V_299 = F_4 ( V_312 ) ;
V_299 &= ~ V_313 ;
F_36 ( L_57 ) ;
F_40 ( V_312 , V_299 ) ;
}
}
static void F_190 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
T_1 V_79 , V_299 , V_314 ;
F_146 ( V_4 , V_71 ) ;
F_191 ( V_4 , V_141 ) ;
V_79 = F_192 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_315 ;
V_299 &= ~ V_316 ;
F_40 ( V_79 , V_299 ) ;
F_4 ( V_79 ) ;
F_114 ( 150 ) ;
V_79 = F_63 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_317 ;
V_299 |= F_193 ( V_64 -> V_67 . V_318 ) ;
V_299 &= ~ V_302 ;
V_299 |= V_319 ;
F_40 ( V_79 , V_299 | V_117 ) ;
V_79 = F_65 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_302 ;
V_299 |= V_319 ;
F_40 ( V_79 , V_299 | V_118 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
F_40 ( F_194 ( V_71 ) , V_320 ) ;
F_40 ( F_194 ( V_71 ) , V_320 |
V_321 ) ;
V_79 = F_195 ( V_71 ) ;
for ( V_314 = 0 ; V_314 < 5 ; V_314 ++ ) {
V_299 = F_4 ( V_79 ) ;
F_36 ( L_58 , V_299 ) ;
if ( ( V_299 & V_316 ) ) {
F_36 ( L_59 ) ;
F_40 ( V_79 , V_299 | V_316 ) ;
break;
}
}
if ( V_314 == 5 )
F_115 ( L_60 ) ;
V_79 = F_63 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_302 ;
V_299 |= V_322 ;
F_40 ( V_79 , V_299 ) ;
V_79 = F_65 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_302 ;
V_299 |= V_322 ;
F_40 ( V_79 , V_299 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
V_79 = F_195 ( V_71 ) ;
for ( V_314 = 0 ; V_314 < 5 ; V_314 ++ ) {
V_299 = F_4 ( V_79 ) ;
F_36 ( L_58 , V_299 ) ;
if ( V_299 & V_315 ) {
F_40 ( V_79 , V_299 | V_315 ) ;
F_36 ( L_61 ) ;
break;
}
}
if ( V_314 == 5 )
F_115 ( L_62 ) ;
F_36 ( L_63 ) ;
}
static void F_196 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
T_1 V_79 , V_299 , V_143 , V_323 ;
V_79 = F_192 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_315 ;
V_299 &= ~ V_316 ;
F_40 ( V_79 , V_299 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
V_79 = F_63 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_317 ;
V_299 |= F_193 ( V_64 -> V_67 . V_318 ) ;
V_299 &= ~ V_302 ;
V_299 |= V_319 ;
V_299 &= ~ V_324 ;
V_299 |= V_325 ;
F_40 ( V_79 , V_299 | V_117 ) ;
F_40 ( F_197 ( V_71 ) ,
V_326 | V_327 ) ;
V_79 = F_65 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
if ( F_89 ( V_2 ) ) {
V_299 &= ~ V_303 ;
V_299 |= V_328 ;
} else {
V_299 &= ~ V_302 ;
V_299 |= V_319 ;
}
F_40 ( V_79 , V_299 | V_118 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
for ( V_143 = 0 ; V_143 < 4 ; V_143 ++ ) {
V_79 = F_63 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_324 ;
V_299 |= V_329 [ V_143 ] ;
F_40 ( V_79 , V_299 ) ;
F_113 ( V_79 ) ;
F_114 ( 500 ) ;
for ( V_323 = 0 ; V_323 < 5 ; V_323 ++ ) {
V_79 = F_195 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
F_36 ( L_58 , V_299 ) ;
if ( V_299 & V_316 ) {
F_40 ( V_79 , V_299 | V_316 ) ;
F_36 ( L_59 ) ;
break;
}
F_114 ( 50 ) ;
}
if ( V_323 < 5 )
break;
}
if ( V_143 == 4 )
F_115 ( L_60 ) ;
V_79 = F_63 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_302 ;
V_299 |= V_322 ;
if ( F_198 ( V_2 ) ) {
V_299 &= ~ V_324 ;
V_299 |= V_325 ;
}
F_40 ( V_79 , V_299 ) ;
V_79 = F_65 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
if ( F_89 ( V_2 ) ) {
V_299 &= ~ V_303 ;
V_299 |= V_330 ;
} else {
V_299 &= ~ V_302 ;
V_299 |= V_322 ;
}
F_40 ( V_79 , V_299 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
for ( V_143 = 0 ; V_143 < 4 ; V_143 ++ ) {
V_79 = F_63 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_324 ;
V_299 |= V_329 [ V_143 ] ;
F_40 ( V_79 , V_299 ) ;
F_113 ( V_79 ) ;
F_114 ( 500 ) ;
for ( V_323 = 0 ; V_323 < 5 ; V_323 ++ ) {
V_79 = F_195 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
F_36 ( L_58 , V_299 ) ;
if ( V_299 & V_315 ) {
F_40 ( V_79 , V_299 | V_315 ) ;
F_36 ( L_61 ) ;
break;
}
F_114 ( 50 ) ;
}
if ( V_323 < 5 )
break;
}
if ( V_143 == 4 )
F_115 ( L_62 ) ;
F_36 ( L_64 ) ;
}
static void F_199 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
T_1 V_79 , V_299 , V_143 , V_331 ;
V_79 = F_192 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_315 ;
V_299 &= ~ V_316 ;
F_40 ( V_79 , V_299 ) ;
F_113 ( V_79 ) ;
F_114 ( 150 ) ;
F_36 ( L_65 ,
F_4 ( F_195 ( V_71 ) ) ) ;
for ( V_331 = 0 ; V_331 < F_200 ( V_329 ) * 2 ; V_331 ++ ) {
V_79 = F_63 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ ( V_332 | V_300 ) ;
V_299 &= ~ V_117 ;
F_40 ( V_79 , V_299 ) ;
V_79 = F_65 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_332 ;
V_299 &= ~ V_303 ;
V_299 &= ~ V_118 ;
F_40 ( V_79 , V_299 ) ;
V_79 = F_63 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_317 ;
V_299 |= F_193 ( V_64 -> V_67 . V_318 ) ;
V_299 |= V_333 ;
V_299 &= ~ V_324 ;
V_299 |= V_329 [ V_331 / 2 ] ;
V_299 |= V_334 ;
F_40 ( V_79 , V_299 | V_117 ) ;
F_40 ( F_197 ( V_71 ) ,
V_326 | V_327 ) ;
V_79 = F_65 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 |= V_328 ;
V_299 |= V_334 ;
F_40 ( V_79 , V_299 | V_118 ) ;
F_113 ( V_79 ) ;
F_114 ( 1 ) ;
for ( V_143 = 0 ; V_143 < 4 ; V_143 ++ ) {
V_79 = F_195 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
F_36 ( L_58 , V_299 ) ;
if ( V_299 & V_316 ||
( F_4 ( V_79 ) & V_316 ) ) {
F_40 ( V_79 , V_299 | V_316 ) ;
F_36 ( L_66 ,
V_143 ) ;
break;
}
F_114 ( 1 ) ;
}
if ( V_143 == 4 ) {
F_36 ( L_67 , V_331 / 2 ) ;
continue;
}
V_79 = F_63 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_300 ;
V_299 |= V_335 ;
F_40 ( V_79 , V_299 ) ;
V_79 = F_65 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_303 ;
V_299 |= V_330 ;
F_40 ( V_79 , V_299 ) ;
F_113 ( V_79 ) ;
F_114 ( 2 ) ;
for ( V_143 = 0 ; V_143 < 4 ; V_143 ++ ) {
V_79 = F_195 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
F_36 ( L_58 , V_299 ) ;
if ( V_299 & V_315 ||
( F_4 ( V_79 ) & V_315 ) ) {
F_40 ( V_79 , V_299 | V_315 ) ;
F_36 ( L_68 ,
V_143 ) ;
goto V_336;
}
F_114 ( 2 ) ;
}
if ( V_143 == 4 )
F_36 ( L_69 , V_331 / 2 ) ;
}
V_336:
F_36 ( L_64 ) ;
}
static void F_201 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_64 -> V_71 ;
T_1 V_79 , V_299 ;
V_79 = F_65 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ ( V_317 | ( 0x7 << 16 ) ) ;
V_299 |= F_193 ( V_64 -> V_67 . V_318 ) ;
V_299 |= ( F_4 ( F_45 ( V_71 ) ) & V_202 ) << 11 ;
F_40 ( V_79 , V_299 | V_121 ) ;
F_113 ( V_79 ) ;
F_114 ( 200 ) ;
V_299 = F_4 ( V_79 ) ;
F_40 ( V_79 , V_299 | V_337 ) ;
F_113 ( V_79 ) ;
F_114 ( 200 ) ;
V_79 = F_63 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
if ( ( V_299 & V_120 ) == 0 ) {
F_40 ( V_79 , V_299 | V_120 ) ;
F_113 ( V_79 ) ;
F_114 ( 100 ) ;
}
}
static void F_202 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_64 -> V_71 ;
T_1 V_79 , V_299 ;
V_79 = F_65 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
F_40 ( V_79 , V_299 & ~ V_337 ) ;
V_79 = F_63 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
F_40 ( V_79 , V_299 & ~ V_120 ) ;
F_113 ( V_79 ) ;
F_114 ( 100 ) ;
V_79 = F_65 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
F_40 ( V_79 , V_299 & ~ V_121 ) ;
F_113 ( V_79 ) ;
F_114 ( 100 ) ;
}
static void F_203 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
T_1 V_79 , V_299 ;
V_79 = F_63 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
F_40 ( V_79 , V_299 & ~ V_117 ) ;
F_113 ( V_79 ) ;
V_79 = F_65 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ ( 0x7 << 16 ) ;
V_299 |= ( F_4 ( F_45 ( V_71 ) ) & V_202 ) << 11 ;
F_40 ( V_79 , V_299 & ~ V_118 ) ;
F_113 ( V_79 ) ;
F_114 ( 100 ) ;
if ( F_48 ( V_2 ) ) {
F_40 ( F_194 ( V_71 ) , V_320 ) ;
}
V_79 = F_63 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ V_302 ;
V_299 |= V_319 ;
F_40 ( V_79 , V_299 ) ;
V_79 = F_65 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
if ( F_89 ( V_2 ) ) {
V_299 &= ~ V_303 ;
V_299 |= V_328 ;
} else {
V_299 &= ~ V_302 ;
V_299 |= V_319 ;
}
V_299 &= ~ ( 0x07 << 16 ) ;
V_299 |= ( F_4 ( F_45 ( V_71 ) ) & V_202 ) << 11 ;
F_40 ( V_79 , V_299 ) ;
F_113 ( V_79 ) ;
F_114 ( 100 ) ;
}
static bool F_204 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
unsigned long V_338 ;
bool V_339 ;
if ( F_205 ( & V_4 -> V_340 ) ||
V_64 -> V_341 != F_206 ( & V_4 -> V_340 . V_341 ) )
return false ;
F_207 ( & V_2 -> V_342 , V_338 ) ;
V_339 = F_30 ( V_21 ) -> V_343 != NULL ;
F_208 ( & V_2 -> V_342 , V_338 ) ;
return V_339 ;
}
bool F_209 ( struct V_1 * V_2 )
{
struct V_64 * V_21 ;
F_173 (crtc, &dev->mode_config.crtc_list, base.head) {
if ( F_206 ( & V_21 -> V_344 ) == 0 )
continue;
if ( V_21 -> V_343 )
F_37 ( V_2 , V_21 -> V_71 ) ;
return true ;
}
return false ;
}
static void F_210 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_21 -> V_66 == NULL )
return;
F_2 ( F_211 ( & V_4 -> V_345 ) ) ;
F_212 ( V_4 -> V_345 ,
! F_204 ( V_21 ) ) ;
F_53 ( & V_2 -> V_290 ) ;
F_176 ( V_21 -> V_66 ) ;
F_55 ( & V_2 -> V_290 ) ;
}
static void F_213 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int clock = F_30 ( V_21 ) -> V_67 . V_68 . V_69 ;
T_1 V_346 , V_347 , V_348 , V_349 = 0 ;
T_1 V_299 ;
F_53 ( & V_4 -> V_104 ) ;
F_40 ( V_350 , V_351 ) ;
F_214 ( V_4 , V_352 ,
F_215 ( V_4 , V_352 , V_353 ) |
V_354 ,
V_353 ) ;
if ( clock == 20000 ) {
V_348 = 1 ;
V_346 = 0x41 ;
V_347 = 0x20 ;
} else {
T_1 V_355 = 172800 * 1000 ;
T_1 V_356 = 64 ;
T_1 V_357 , V_358 , V_359 ;
V_357 = ( V_355 / clock ) ;
V_358 = V_357 / V_356 ;
V_359 = V_357 % V_356 ;
V_348 = 0 ;
V_346 = V_358 - 2 ;
V_347 = V_359 ;
}
F_2 ( F_216 ( V_346 ) &
~ V_360 ) ;
F_2 ( F_217 ( V_349 ) &
~ V_361 ) ;
F_36 ( L_70 ,
clock ,
V_348 ,
V_346 ,
V_349 ,
V_347 ) ;
V_299 = F_215 ( V_4 , V_362 , V_353 ) ;
V_299 &= ~ V_360 ;
V_299 |= F_216 ( V_346 ) ;
V_299 &= ~ V_361 ;
V_299 |= F_218 ( V_347 ) ;
V_299 |= F_217 ( V_349 ) ;
V_299 |= V_363 ;
F_214 ( V_4 , V_362 , V_299 , V_353 ) ;
V_299 = F_215 ( V_4 , V_364 , V_353 ) ;
V_299 &= ~ F_219 ( 1 ) ;
V_299 |= F_219 ( V_348 ) ;
F_214 ( V_4 , V_364 , V_299 , V_353 ) ;
V_299 = F_215 ( V_4 , V_352 , V_353 ) ;
V_299 &= ~ V_354 ;
F_214 ( V_4 , V_352 , V_299 , V_353 ) ;
F_114 ( 24 ) ;
F_40 ( V_350 , V_365 ) ;
F_55 ( & V_4 -> V_104 ) ;
}
static void F_220 ( struct V_64 * V_21 ,
enum V_71 V_216 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_70 V_73 = V_21 -> V_67 . V_73 ;
F_40 ( F_221 ( V_216 ) ,
F_4 ( F_222 ( V_73 ) ) ) ;
F_40 ( F_223 ( V_216 ) ,
F_4 ( F_224 ( V_73 ) ) ) ;
F_40 ( F_225 ( V_216 ) ,
F_4 ( F_226 ( V_73 ) ) ) ;
F_40 ( F_227 ( V_216 ) ,
F_4 ( F_228 ( V_73 ) ) ) ;
F_40 ( F_229 ( V_216 ) ,
F_4 ( F_230 ( V_73 ) ) ) ;
F_40 ( F_231 ( V_216 ) ,
F_4 ( F_232 ( V_73 ) ) ) ;
F_40 ( F_233 ( V_216 ) ,
F_4 ( F_234 ( V_73 ) ) ) ;
}
static void F_235 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_299 ;
V_299 = F_4 ( V_312 ) ;
if ( V_299 & V_313 )
return;
F_2 ( F_4 ( F_65 ( V_134 ) ) & V_118 ) ;
F_2 ( F_4 ( F_65 ( V_311 ) ) & V_118 ) ;
V_299 |= V_313 ;
F_36 ( L_71 ) ;
F_40 ( V_312 , V_299 ) ;
F_113 ( V_312 ) ;
}
static void F_236 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_64 -> V_71 ) {
case V_125 :
break;
case V_134 :
if ( V_64 -> V_67 . V_318 > 2 )
F_2 ( F_4 ( V_312 ) & V_313 ) ;
else
F_235 ( V_2 ) ;
break;
case V_311 :
F_235 ( V_2 ) ;
break;
default:
F_121 () ;
}
}
static void F_237 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
T_1 V_79 , V_299 ;
F_90 ( V_4 , V_71 ) ;
if ( F_187 ( V_2 ) )
F_236 ( V_64 ) ;
F_40 ( F_238 ( V_71 ) ,
F_4 ( F_239 ( V_71 ) ) & V_366 ) ;
V_4 -> V_273 . V_367 ( V_21 ) ;
if ( F_89 ( V_2 ) ) {
T_1 V_368 ;
V_299 = F_4 ( V_369 ) ;
V_299 |= F_240 ( V_71 ) ;
V_368 = F_241 ( V_71 ) ;
if ( V_64 -> V_67 . V_109 == V_370 )
V_299 |= V_368 ;
else
V_299 &= ~ V_368 ;
F_40 ( V_369 , V_299 ) ;
}
F_123 ( V_64 ) ;
F_68 ( V_4 , V_71 ) ;
F_220 ( V_64 , V_71 ) ;
F_186 ( V_21 ) ;
if ( F_89 ( V_2 ) &&
( F_9 ( V_21 , V_371 ) ||
F_9 ( V_21 , V_296 ) ) ) {
T_1 V_372 = ( F_4 ( F_45 ( V_71 ) ) & V_202 ) >> 5 ;
V_79 = F_93 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ ( V_160 |
V_373 |
V_374 ) ;
V_299 |= ( V_375 |
V_376 ) ;
V_299 |= V_372 << 9 ;
if ( V_21 -> V_377 . V_338 & V_378 )
V_299 |= V_379 ;
if ( V_21 -> V_377 . V_338 & V_380 )
V_299 |= V_381 ;
switch ( F_242 ( V_21 ) ) {
case V_172 :
V_299 |= V_173 ;
break;
case V_174 :
V_299 |= V_175 ;
break;
case V_176 :
V_299 |= V_177 ;
break;
default:
F_121 () ;
}
F_40 ( V_79 , V_299 ) ;
}
F_127 ( V_4 , V_71 ) ;
}
static void F_243 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_70 V_73 = V_64 -> V_67 . V_73 ;
F_90 ( V_4 , V_210 ) ;
F_213 ( V_21 ) ;
F_220 ( V_64 , V_125 ) ;
F_131 ( V_4 , V_73 ) ;
}
static void F_244 ( struct V_64 * V_21 )
{
struct V_107 * V_111 = F_56 ( V_21 ) ;
if ( V_111 == NULL )
return;
if ( V_111 -> V_195 == 0 ) {
F_46 ( 1 , L_72 , V_111 -> V_115 ) ;
return;
}
if ( -- V_111 -> V_195 == 0 ) {
F_2 ( V_111 -> V_196 ) ;
F_2 ( V_111 -> V_65 ) ;
}
V_21 -> V_67 . V_109 = V_382 ;
}
static struct V_107 * F_245 ( struct V_64 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_108 . V_2 -> V_5 ;
struct V_107 * V_111 = F_56 ( V_21 ) ;
enum V_383 V_143 ;
if ( V_111 ) {
F_36 ( L_73 ,
V_21 -> V_108 . V_108 . V_197 , V_111 -> V_115 ) ;
F_244 ( V_21 ) ;
}
if ( F_48 ( V_4 -> V_2 ) ) {
V_143 = (enum V_383 ) V_21 -> V_71 ;
V_111 = & V_4 -> V_110 [ V_143 ] ;
F_36 ( L_74 ,
V_21 -> V_108 . V_108 . V_197 , V_111 -> V_115 ) ;
goto V_59;
}
for ( V_143 = 0 ; V_143 < V_4 -> V_384 ; V_143 ++ ) {
V_111 = & V_4 -> V_110 [ V_143 ] ;
if ( V_111 -> V_195 == 0 )
continue;
if ( memcmp ( & V_21 -> V_67 . V_188 , & V_111 -> V_113 ,
sizeof( V_111 -> V_113 ) ) == 0 ) {
F_36 ( L_75 ,
V_21 -> V_108 . V_108 . V_197 ,
V_111 -> V_115 , V_111 -> V_195 , V_111 -> V_65 ) ;
goto V_59;
}
}
for ( V_143 = 0 ; V_143 < V_4 -> V_384 ; V_143 ++ ) {
V_111 = & V_4 -> V_110 [ V_143 ] ;
if ( V_111 -> V_195 == 0 ) {
F_36 ( L_76 ,
V_21 -> V_108 . V_108 . V_197 , V_111 -> V_115 ) ;
goto V_59;
}
}
return NULL ;
V_59:
V_21 -> V_67 . V_109 = V_143 ;
F_59 ( L_77 , V_111 -> V_115 ,
F_69 ( V_21 -> V_71 ) ) ;
if ( V_111 -> V_65 == 0 ) {
memcpy ( & V_111 -> V_113 , & V_21 -> V_67 . V_188 ,
sizeof( V_111 -> V_113 ) ) ;
F_59 ( L_78 , V_111 -> V_115 ) ;
F_2 ( V_111 -> V_196 ) ;
F_126 ( V_4 , V_111 ) ;
V_111 -> V_385 ( V_4 , V_111 ) ;
}
V_111 -> V_195 ++ ;
return V_111 ;
}
static void F_246 ( struct V_1 * V_2 , int V_71 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_386 = F_42 ( V_71 ) ;
T_1 V_299 ;
V_299 = F_4 ( V_386 ) ;
F_114 ( 500 ) ;
if ( F_34 ( F_4 ( V_386 ) != V_299 , 5 ) ) {
if ( F_34 ( F_4 ( V_386 ) != V_299 , 5 ) )
F_115 ( L_79 , F_69 ( V_71 ) ) ;
}
}
static void F_247 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_21 -> V_71 ;
if ( V_21 -> V_67 . V_295 . V_99 ) {
if ( F_187 ( V_2 ) || F_167 ( V_2 ) )
F_40 ( F_181 ( V_71 ) , V_387 | V_388 |
F_248 ( V_71 ) ) ;
else
F_40 ( F_181 ( V_71 ) , V_387 | V_388 ) ;
F_40 ( F_182 ( V_71 ) , V_21 -> V_67 . V_295 . V_389 ) ;
F_40 ( F_183 ( V_71 ) , V_21 -> V_67 . V_295 . V_390 ) ;
}
}
static void F_249 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
enum V_71 V_71 = F_30 ( V_21 ) -> V_71 ;
struct V_391 * V_391 ;
F_173 (intel_plane, &dev->mode_config.plane_list, base.head)
if ( V_391 -> V_71 == V_71 )
F_250 ( & V_391 -> V_108 ) ;
}
static void F_251 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
enum V_71 V_71 = F_30 ( V_21 ) -> V_71 ;
struct V_391 * V_391 ;
F_173 (intel_plane, &dev->mode_config.plane_list, base.head)
if ( V_391 -> V_71 == V_71 )
F_252 ( & V_391 -> V_108 ) ;
}
void F_253 ( struct V_64 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_108 . V_2 -> V_5 ;
if ( ! V_21 -> V_67 . V_392 )
return;
F_191 ( V_4 , V_21 -> V_141 ) ;
if ( F_168 ( V_21 -> V_108 . V_2 ) ) {
F_53 ( & V_4 -> V_393 . V_394 ) ;
F_2 ( F_254 ( V_4 , V_395 , 0xc0000000 ) ) ;
F_55 ( & V_4 -> V_393 . V_394 ) ;
} else {
F_40 ( V_396 , V_397 ) ;
if ( F_34 ( F_35 ( V_396 ) & V_397 , 50 ) )
F_115 ( L_80 ) ;
}
}
void F_255 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_21 -> V_67 . V_392 )
return;
F_191 ( V_4 , V_21 -> V_141 ) ;
if ( F_168 ( V_21 -> V_108 . V_2 ) ) {
F_53 ( & V_4 -> V_393 . V_394 ) ;
F_2 ( F_254 ( V_4 , V_395 , 0 ) ) ;
F_55 ( & V_4 -> V_393 . V_394 ) ;
} else {
F_40 ( V_396 , 0 ) ;
F_113 ( V_396 ) ;
}
F_37 ( V_2 , V_21 -> V_71 ) ;
}
static void F_256 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_71 V_71 = V_64 -> V_71 ;
int V_398 = F_257 ( V_71 ) ;
int V_143 ;
bool V_399 = false ;
if ( ! V_21 -> V_99 || ! V_64 -> V_65 )
return;
if ( ! F_3 ( V_4 -> V_2 ) ) {
if ( F_9 ( V_21 , V_400 ) )
F_138 ( V_4 ) ;
else
F_139 ( V_4 , V_71 ) ;
}
if ( F_3 ( V_2 ) )
V_398 = F_258 ( V_71 ) ;
if ( F_167 ( V_2 ) && V_64 -> V_67 . V_392 &&
( ( F_4 ( F_259 ( V_71 ) ) & V_401 ) ==
V_402 ) ) {
F_255 ( V_64 ) ;
V_399 = true ;
}
for ( V_143 = 0 ; V_143 < 256 ; V_143 ++ ) {
F_40 ( V_398 + 4 * V_143 ,
( V_64 -> V_403 [ V_143 ] << 16 ) |
( V_64 -> V_404 [ V_143 ] << 8 ) |
V_64 -> V_405 [ V_143 ] ) ;
}
if ( V_399 )
F_253 ( V_64 ) ;
}
static void F_260 ( struct V_20 * V_21 )
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
F_261 ( V_2 , V_71 , true ) ;
F_262 ( V_2 , V_71 , true ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_406 )
V_23 -> V_406 ( V_23 ) ;
if ( V_64 -> V_67 . V_308 ) {
F_201 ( V_64 ) ;
} else {
F_133 ( V_4 , V_71 ) ;
F_134 ( V_4 , V_71 ) ;
}
F_247 ( V_64 ) ;
F_256 ( V_21 ) ;
F_263 ( V_21 ) ;
F_136 ( V_4 , V_71 ,
V_64 -> V_67 . V_308 , false ) ;
F_145 ( V_4 , V_141 , V_71 ) ;
F_249 ( V_21 ) ;
F_264 ( V_21 , true ) ;
if ( V_64 -> V_67 . V_308 )
F_237 ( V_21 ) ;
F_53 ( & V_2 -> V_290 ) ;
F_184 ( V_2 ) ;
F_55 ( & V_2 -> V_290 ) ;
F_10 (dev, crtc, encoder)
V_23 -> V_198 ( V_23 ) ;
if ( F_89 ( V_2 ) )
F_246 ( V_2 , V_64 -> V_71 ) ;
F_37 ( V_2 , V_64 -> V_71 ) ;
}
static bool F_265 ( struct V_64 * V_21 )
{
return F_266 ( V_21 -> V_108 . V_2 ) && V_21 -> V_71 == V_125 ;
}
static void F_267 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
F_145 ( V_4 , V_141 , V_71 ) ;
F_249 ( V_21 ) ;
F_264 ( V_21 , true ) ;
F_253 ( V_64 ) ;
F_53 ( & V_2 -> V_290 ) ;
F_184 ( V_2 ) ;
F_55 ( & V_2 -> V_290 ) ;
}
static void F_268 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
F_210 ( V_21 ) ;
F_269 ( V_2 , V_71 ) ;
if ( V_4 -> V_407 . V_141 == V_141 )
F_270 ( V_2 ) ;
F_255 ( V_64 ) ;
F_264 ( V_21 , false ) ;
F_251 ( V_21 ) ;
F_147 ( V_4 , V_141 , V_71 ) ;
}
static void F_271 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_64 * V_408 , * V_409 = NULL ;
F_173 (crtc_it, &dev->mode_config.crtc_list, base.head) {
if ( ! V_408 -> V_65 || V_408 == V_21 )
continue;
if ( V_409 )
return;
V_409 = V_408 ;
}
if ( ! V_409 )
return;
F_37 ( V_2 , V_409 -> V_71 ) ;
F_37 ( V_2 , V_409 -> V_71 ) ;
}
static void F_272 ( struct V_20 * V_21 )
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
F_261 ( V_2 , V_71 , true ) ;
if ( V_64 -> V_67 . V_308 )
F_262 ( V_2 , V_210 , true ) ;
if ( V_64 -> V_67 . V_308 )
V_4 -> V_273 . V_367 ( V_21 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_406 )
V_23 -> V_406 ( V_23 ) ;
F_273 ( V_64 ) ;
F_247 ( V_64 ) ;
F_256 ( V_21 ) ;
F_274 ( V_21 ) ;
F_275 ( V_21 ) ;
F_263 ( V_21 ) ;
F_136 ( V_4 , V_71 ,
V_64 -> V_67 . V_308 , false ) ;
if ( V_64 -> V_67 . V_308 )
F_243 ( V_21 ) ;
F_10 (dev, crtc, encoder) {
V_23 -> V_198 ( V_23 ) ;
F_276 ( V_23 , true ) ;
}
F_271 ( V_64 ) ;
F_267 ( V_21 ) ;
F_37 ( V_2 , V_64 -> V_71 ) ;
}
static void F_277 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_21 -> V_71 ;
if ( V_21 -> V_67 . V_295 . V_99 ) {
F_40 ( F_181 ( V_71 ) , 0 ) ;
F_40 ( F_182 ( V_71 ) , 0 ) ;
F_40 ( F_183 ( V_71 ) , 0 ) ;
}
}
static void F_278 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
T_1 V_79 , V_299 ;
if ( ! V_64 -> V_65 )
return;
F_10 (dev, crtc, encoder)
V_23 -> V_199 ( V_23 ) ;
F_210 ( V_21 ) ;
F_269 ( V_2 , V_71 ) ;
if ( V_4 -> V_407 . V_141 == V_141 )
F_270 ( V_2 ) ;
F_264 ( V_21 , false ) ;
F_251 ( V_21 ) ;
F_147 ( V_4 , V_141 , V_71 ) ;
if ( V_64 -> V_67 . V_308 )
F_262 ( V_2 , V_71 , false ) ;
F_141 ( V_4 , V_71 ) ;
F_277 ( V_64 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_410 )
V_23 -> V_410 ( V_23 ) ;
if ( V_64 -> V_67 . V_308 ) {
F_203 ( V_21 ) ;
F_132 ( V_4 , V_71 ) ;
F_262 ( V_2 , V_71 , true ) ;
if ( F_89 ( V_2 ) ) {
V_79 = F_93 ( V_71 ) ;
V_299 = F_4 ( V_79 ) ;
V_299 &= ~ ( V_375 |
V_160 ) ;
V_299 |= V_411 ;
F_40 ( V_79 , V_299 ) ;
V_299 = F_4 ( V_369 ) ;
V_299 &= ~ ( F_240 ( V_71 ) | F_241 ( V_71 ) ) ;
F_40 ( V_369 , V_299 ) ;
}
F_125 ( V_64 ) ;
F_202 ( V_64 ) ;
}
V_64 -> V_65 = false ;
F_263 ( V_21 ) ;
F_53 ( & V_2 -> V_290 ) ;
F_184 ( V_2 ) ;
F_55 ( & V_2 -> V_290 ) ;
}
static void F_279 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_71 = V_64 -> V_71 ;
enum V_70 V_73 = V_64 -> V_67 . V_73 ;
if ( ! V_64 -> V_65 )
return;
F_268 ( V_21 ) ;
F_10 (dev, crtc, encoder) {
F_276 ( V_23 , false ) ;
V_23 -> V_199 ( V_23 ) ;
}
if ( V_64 -> V_67 . V_308 )
F_262 ( V_2 , V_210 , false ) ;
F_141 ( V_4 , V_71 ) ;
F_280 ( V_4 , V_73 ) ;
F_277 ( V_64 ) ;
F_281 ( V_64 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_410 )
V_23 -> V_410 ( V_23 ) ;
if ( V_64 -> V_67 . V_308 ) {
F_135 ( V_4 ) ;
F_262 ( V_2 , V_210 , true ) ;
F_282 ( V_21 ) ;
}
V_64 -> V_65 = false ;
F_263 ( V_21 ) ;
F_53 ( & V_2 -> V_290 ) ;
F_184 ( V_2 ) ;
F_55 ( & V_2 -> V_290 ) ;
}
static void F_283 ( struct V_20 * V_21 )
{
struct V_64 * V_64 = F_30 ( V_21 ) ;
F_244 ( V_64 ) ;
}
static void F_284 ( struct V_20 * V_21 )
{
F_285 ( V_21 ) ;
}
static void F_286 ( struct V_64 * V_64 , bool V_198 )
{
if ( ! V_198 && V_64 -> V_412 ) {
struct V_1 * V_2 = V_64 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_53 ( & V_2 -> V_290 ) ;
V_4 -> V_230 . V_231 = false ;
( void ) F_287 ( V_64 -> V_412 ) ;
V_4 -> V_230 . V_231 = true ;
F_55 ( & V_2 -> V_290 ) ;
}
}
static void
F_288 ( struct V_3 * V_4 , enum V_71 V_71 )
{
T_1 V_413 = F_4 ( F_73 ( V_71 ) ) ;
if ( ( V_413 & V_137 ) == 0 ) {
T_1 V_414 = F_4 ( V_415 ) ;
F_40 ( V_415 , V_414 & ~ V_416 ) ;
F_40 ( F_73 ( V_71 ) , V_417 ) ;
F_37 ( V_4 -> V_2 , V_71 ) ;
F_40 ( F_73 ( V_71 ) , V_413 ) ;
F_40 ( F_289 ( V_71 ) , F_4 ( F_289 ( V_71 ) ) ) ;
F_40 ( V_415 , V_414 ) ;
}
}
static void F_290 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_418 * V_419 = & V_21 -> V_67 ;
if ( ! V_21 -> V_67 . V_420 . V_421 )
return;
F_2 ( F_4 ( V_422 ) & V_423 ) ;
F_109 ( V_4 , V_21 -> V_71 ) ;
F_40 ( V_424 , V_419 -> V_420 . V_425 ) ;
F_40 ( V_422 , V_419 -> V_420 . V_421 ) ;
F_40 ( F_291 ( V_21 -> V_71 ) , 0 ) ;
}
int F_292 ( struct V_3 * V_4 )
{
int V_426 , V_427 [] = { 800 , 1600 , 2000 , 2400 } ;
F_53 ( & V_4 -> V_104 ) ;
V_426 = F_54 ( V_4 , V_428 ) &
V_429 ;
F_55 ( & V_4 -> V_104 ) ;
return V_427 [ V_426 ] ;
}
static void F_293 ( struct V_1 * V_2 , int V_430 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_101 , V_431 ;
if ( V_430 >= 320 )
V_431 = 2 ;
else if ( V_430 == 266 )
V_431 = 1 ;
else
V_431 = 0 ;
F_53 ( & V_4 -> V_393 . V_394 ) ;
V_101 = F_294 ( V_4 , V_432 ) ;
V_101 &= ~ V_433 ;
V_101 |= ( V_431 << V_434 ) ;
F_295 ( V_4 , V_432 , V_101 ) ;
if ( F_34 ( ( F_294 ( V_4 , V_432 ) &
V_435 ) == ( V_431 << V_436 ) ,
50 ) ) {
F_115 ( L_81 ) ;
}
F_55 ( & V_4 -> V_393 . V_394 ) ;
if ( V_430 == 400 ) {
T_1 V_437 , V_18 ;
V_18 = F_292 ( V_4 ) ;
V_437 = ( ( V_18 << 1 ) / V_430 ) - 1 ;
F_53 ( & V_4 -> V_104 ) ;
V_101 = F_54 ( V_4 , V_438 ) ;
V_101 &= ~ 0xf ;
V_101 |= V_437 ;
F_296 ( V_4 , V_438 , V_101 ) ;
F_55 ( & V_4 -> V_104 ) ;
}
F_53 ( & V_4 -> V_104 ) ;
V_101 = F_297 ( V_4 , V_439 ) ;
V_101 &= ~ 0x7f ;
if ( V_430 == 400 )
V_101 |= 4500 / 250 ;
else
V_101 |= 3000 / 250 ;
F_298 ( V_4 , V_439 , V_101 ) ;
F_55 ( & V_4 -> V_104 ) ;
F_299 ( V_2 ) ;
}
static int F_300 ( struct V_3 * V_4 )
{
int V_440 , V_18 ;
int V_437 ;
V_18 = F_292 ( V_4 ) ;
F_53 ( & V_4 -> V_104 ) ;
V_437 = F_54 ( V_4 , V_438 ) ;
F_55 ( & V_4 -> V_104 ) ;
V_437 &= 0xf ;
V_440 = ( V_18 << 1 ) / ( V_437 + 1 ) ;
return V_440 ;
}
static int F_301 ( struct V_3 * V_4 ,
int V_441 )
{
int V_440 ;
V_440 = F_300 ( V_4 ) ;
if ( V_441 > 288000 ) {
return 400 ;
} else if ( V_441 > 240000 ) {
return 320 ;
} else
return 266 ;
}
static int F_302 ( struct V_3 * V_4 ,
unsigned V_442 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_64 * V_64 ;
int V_441 = 0 ;
F_173 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_442 & ( 1 << V_64 -> V_71 ) )
V_441 = V_49 ( V_441 ,
V_419 -> V_68 . V_69 ) ;
else if ( V_64 -> V_108 . V_99 )
V_441 = V_49 ( V_441 ,
V_64 -> V_67 . V_68 . V_69 ) ;
}
return V_441 ;
}
static void F_303 ( struct V_1 * V_2 ,
unsigned * V_443 ,
unsigned V_442 ,
struct V_418 * V_419 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 ;
int V_441 = F_302 ( V_4 , V_442 ,
V_419 ) ;
int V_440 = F_300 ( V_4 ) ;
if ( F_301 ( V_4 , V_441 ) == V_440 )
return;
F_173 (intel_crtc, &dev->mode_config.crtc_list,
base.head)
if ( V_64 -> V_108 . V_99 )
* V_443 |= ( 1 << V_64 -> V_71 ) ;
}
static void F_304 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_441 = F_302 ( V_4 , 0 , NULL ) ;
int V_440 = F_300 ( V_4 ) ;
int V_444 = F_301 ( V_4 , V_441 ) ;
if ( V_444 != V_440 )
F_293 ( V_2 , V_444 ) ;
}
static void F_305 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
bool V_445 ;
F_2 ( ! V_21 -> V_99 ) ;
if ( V_64 -> V_65 )
return;
V_64 -> V_65 = true ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_446 )
V_23 -> V_446 ( V_23 ) ;
V_445 = F_9 ( V_21 , V_400 ) ;
if ( ! V_445 )
F_108 ( V_64 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_406 )
V_23 -> V_406 ( V_23 ) ;
F_290 ( V_64 ) ;
F_256 ( V_21 ) ;
F_263 ( V_21 ) ;
F_136 ( V_4 , V_71 , false , V_445 ) ;
F_145 ( V_4 , V_141 , V_71 ) ;
F_249 ( V_21 ) ;
F_264 ( V_21 , true ) ;
F_184 ( V_2 ) ;
F_10 (dev, crtc, encoder)
V_23 -> V_198 ( V_23 ) ;
}
static void F_306 ( struct V_20 * V_21 )
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
if ( V_23 -> V_406 )
V_23 -> V_406 ( V_23 ) ;
F_117 ( V_64 ) ;
F_290 ( V_64 ) ;
F_256 ( V_21 ) ;
F_263 ( V_21 ) ;
F_136 ( V_4 , V_71 , false , false ) ;
F_145 ( V_4 , V_141 , V_71 ) ;
F_249 ( V_21 ) ;
if ( F_15 ( V_2 ) )
F_288 ( V_4 , V_71 ) ;
F_264 ( V_21 , true ) ;
F_286 ( V_64 , true ) ;
F_184 ( V_2 ) ;
F_10 (dev, crtc, encoder)
V_23 -> V_198 ( V_23 ) ;
}
static void F_307 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_21 -> V_67 . V_420 . V_421 )
return;
F_109 ( V_4 , V_21 -> V_71 ) ;
F_59 ( L_82 ,
F_4 ( V_422 ) ) ;
F_40 ( V_422 , 0 ) ;
}
static void F_308 ( struct V_20 * V_21 )
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
V_23 -> V_199 ( V_23 ) ;
F_210 ( V_21 ) ;
F_269 ( V_2 , V_71 ) ;
if ( V_4 -> V_407 . V_141 == V_141 )
F_270 ( V_2 ) ;
F_286 ( V_64 , false ) ;
F_264 ( V_21 , false ) ;
F_251 ( V_21 ) ;
F_147 ( V_4 , V_141 , V_71 ) ;
F_141 ( V_4 , V_71 ) ;
F_307 ( V_64 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_410 )
V_23 -> V_410 ( V_23 ) ;
if ( F_17 ( V_2 ) && ! F_9 ( V_21 , V_400 ) )
F_119 ( V_4 , V_71 ) ;
else if ( ! F_17 ( V_2 ) )
F_118 ( V_4 , V_71 ) ;
V_64 -> V_65 = false ;
F_263 ( V_21 ) ;
F_184 ( V_2 ) ;
}
static void F_309 ( struct V_20 * V_21 )
{
}
static void F_310 ( struct V_20 * V_21 ,
bool V_99 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_279 * V_280 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
if ( ! V_2 -> V_281 -> V_282 )
return;
V_280 = V_2 -> V_281 -> V_282 -> V_283 ;
if ( ! V_280 -> V_284 )
return;
switch ( V_71 ) {
case 0 :
V_280 -> V_284 -> V_447 = V_99 ? V_21 -> V_377 . V_448 : 0 ;
V_280 -> V_284 -> V_449 = V_99 ? V_21 -> V_377 . V_450 : 0 ;
break;
case 1 :
V_280 -> V_284 -> V_451 = V_99 ? V_21 -> V_377 . V_448 : 0 ;
V_280 -> V_284 -> V_452 = V_99 ? V_21 -> V_377 . V_450 : 0 ;
break;
default:
F_115 ( L_83 , F_69 ( V_71 ) ) ;
break;
}
}
void F_311 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_22 ;
bool V_198 = false ;
F_10 (dev, crtc, intel_encoder)
V_198 |= V_22 -> V_453 ;
if ( V_198 )
V_4 -> V_273 . V_454 ( V_21 ) ;
else
V_4 -> V_273 . V_455 ( V_21 ) ;
F_310 ( V_21 , V_198 ) ;
}
static void F_312 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_456 * V_457 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
F_2 ( ! V_21 -> V_99 ) ;
V_4 -> V_273 . V_455 ( V_21 ) ;
V_64 -> V_458 = false ;
F_310 ( V_21 , false ) ;
V_4 -> V_273 . V_459 ( V_21 ) ;
F_313 ( V_2 -> V_5 , F_30 ( V_21 ) -> V_141 ) ;
F_137 ( V_4 , F_30 ( V_21 ) -> V_71 ) ;
F_109 ( V_2 -> V_5 , F_30 ( V_21 ) -> V_71 ) ;
if ( V_21 -> V_66 ) {
F_53 ( & V_2 -> V_290 ) ;
F_157 ( F_161 ( V_21 -> V_66 ) -> V_220 ) ;
F_55 ( & V_2 -> V_290 ) ;
V_21 -> V_66 = NULL ;
}
F_173 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_457 -> V_23 || ! V_457 -> V_23 -> V_21 )
continue;
if ( V_457 -> V_23 -> V_21 != V_21 )
continue;
V_457 -> V_460 = V_461 ;
F_314 ( V_457 -> V_23 ) -> V_453 = false ;
}
}
void F_315 ( struct V_462 * V_23 )
{
struct V_22 * V_22 = F_314 ( V_23 ) ;
F_316 ( V_23 ) ;
F_317 ( V_22 ) ;
}
static void F_318 ( struct V_22 * V_23 , int V_377 )
{
if ( V_377 == V_463 ) {
V_23 -> V_453 = true ;
F_311 ( V_23 -> V_108 . V_21 ) ;
} else {
V_23 -> V_453 = false ;
F_311 ( V_23 -> V_108 . V_21 ) ;
}
}
static void F_319 ( struct V_464 * V_457 )
{
if ( V_457 -> V_114 ( V_457 ) ) {
struct V_22 * V_23 = V_457 -> V_23 ;
struct V_20 * V_21 ;
bool V_465 ;
enum V_71 V_71 ;
F_36 ( L_84 ,
V_457 -> V_108 . V_108 . V_197 ,
F_320 ( & V_457 -> V_108 ) ) ;
F_46 ( V_457 -> V_108 . V_460 == V_461 ,
L_85 ) ;
F_46 ( V_457 -> V_108 . V_23 != & V_23 -> V_108 ,
L_86 ) ;
F_46 ( ! V_23 -> V_453 ,
L_87 ) ;
V_465 = V_23 -> V_114 ( V_23 , & V_71 ) ;
F_46 ( ! V_465 , L_88 ) ;
if ( F_2 ( ! V_23 -> V_108 . V_21 ) )
return;
V_21 = V_23 -> V_108 . V_21 ;
F_46 ( ! V_21 -> V_99 , L_89 ) ;
F_46 ( ! F_30 ( V_21 ) -> V_65 , L_90 ) ;
F_46 ( V_71 != F_30 ( V_21 ) -> V_71 ,
L_91 ) ;
}
}
void F_321 ( struct V_456 * V_457 , int V_377 )
{
if ( V_377 != V_463 )
V_377 = V_461 ;
if ( V_377 == V_457 -> V_460 )
return;
V_457 -> V_460 = V_377 ;
if ( V_457 -> V_23 )
F_318 ( F_314 ( V_457 -> V_23 ) , V_377 ) ;
F_322 ( V_457 -> V_2 ) ;
}
bool F_323 ( struct V_464 * V_457 )
{
enum V_71 V_71 = 0 ;
struct V_22 * V_23 = V_457 -> V_23 ;
return V_23 -> V_114 ( V_23 , & V_71 ) ;
}
static bool F_324 ( struct V_1 * V_2 , enum V_71 V_71 ,
struct V_418 * V_419 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_309 =
F_30 ( V_4 -> V_72 [ V_134 ] ) ;
F_36 ( L_92 ,
F_69 ( V_71 ) , V_419 -> V_318 ) ;
if ( V_419 -> V_318 > 4 ) {
F_36 ( L_93 ,
F_69 ( V_71 ) , V_419 -> V_318 ) ;
return false ;
}
if ( F_167 ( V_2 ) || F_168 ( V_2 ) ) {
if ( V_419 -> V_318 > 2 ) {
F_36 ( L_94 ,
V_419 -> V_318 ) ;
return false ;
} else {
return true ;
}
}
if ( F_39 ( V_2 ) -> V_289 == 2 )
return true ;
switch ( V_71 ) {
case V_125 :
return true ;
case V_134 :
if ( V_4 -> V_72 [ V_311 ] -> V_99 &&
V_419 -> V_318 > 2 ) {
F_36 ( L_95 ,
F_69 ( V_71 ) , V_419 -> V_318 ) ;
return false ;
}
return true ;
case V_311 :
if ( ! F_188 ( V_309 ) ||
V_309 -> V_67 . V_318 <= 2 ) {
if ( V_419 -> V_318 > 2 ) {
F_36 ( L_95 ,
F_69 ( V_71 ) , V_419 -> V_318 ) ;
return false ;
}
} else {
F_36 ( L_96 ) ;
return false ;
}
return true ;
default:
F_121 () ;
}
}
static int F_325 ( struct V_64 * V_64 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_64 -> V_108 . V_2 ;
struct V_292 * V_68 = & V_419 -> V_68 ;
int V_466 , V_467 , V_468 ;
bool V_469 , V_470 = false ;
V_323:
V_467 = F_5 ( V_2 ) * F_326 ( 100 ) / F_327 ( 1 ) / 10 ;
V_468 = V_68 -> V_69 ;
V_466 = F_328 ( V_468 , V_467 ,
V_419 -> V_471 ) ;
V_419 -> V_318 = V_466 ;
F_329 ( V_419 -> V_471 , V_466 , V_468 ,
V_467 , & V_419 -> V_472 ) ;
V_469 = F_324 ( V_64 -> V_108 . V_2 ,
V_64 -> V_71 , V_419 ) ;
if ( ! V_469 && V_419 -> V_471 > 6 * 3 ) {
V_419 -> V_471 -= 2 * 3 ;
F_36 ( L_97 ,
V_419 -> V_471 ) ;
V_470 = true ;
V_419 -> V_473 = true ;
goto V_323;
}
if ( V_470 )
return V_474 ;
return V_469 ? 0 : - V_229 ;
}
static void F_330 ( struct V_64 * V_21 ,
struct V_418 * V_419 )
{
V_419 -> V_392 = V_475 &&
F_265 ( V_21 ) &&
V_419 -> V_471 <= 24 ;
}
static int F_331 ( struct V_64 * V_21 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_292 * V_68 = & V_419 -> V_68 ;
if ( F_39 ( V_2 ) -> V_77 < 4 ) {
struct V_3 * V_4 = V_2 -> V_5 ;
int V_476 =
V_4 -> V_273 . V_477 ( V_2 ) ;
if ( ( V_21 -> V_71 == V_125 || F_332 ( V_2 ) ) &&
V_68 -> V_69 > V_476 * 9 / 10 ) {
V_476 *= 2 ;
V_419 -> V_478 = true ;
}
if ( V_68 -> V_69 > V_476 * 9 / 10 )
return - V_229 ;
}
if ( ( F_9 ( & V_21 -> V_108 , V_25 ) &&
F_12 ( V_2 ) ) || V_419 -> V_478 )
V_419 -> V_297 &= ~ 1 ;
if ( ( F_39 ( V_2 ) -> V_77 > 4 || F_15 ( V_2 ) ) &&
V_68 -> V_479 == V_68 -> V_448 )
return - V_229 ;
if ( ( F_15 ( V_2 ) || F_17 ( V_2 ) ) && V_419 -> V_471 > 10 * 3 ) {
V_419 -> V_471 = 10 * 3 ;
} else if ( F_39 ( V_2 ) -> V_77 <= 4 && V_419 -> V_471 > 8 * 3 ) {
V_419 -> V_471 = 8 * 3 ;
}
if ( F_266 ( V_2 ) )
F_330 ( V_21 , V_419 ) ;
if ( F_48 ( V_2 ) || F_89 ( V_2 ) )
V_419 -> V_109 = V_21 -> V_67 . V_109 ;
if ( V_419 -> V_308 )
return F_325 ( V_21 , V_419 ) ;
return 0 ;
}
static int F_333 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_334 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_335 ( struct V_1 * V_2 )
{
return 333000 ;
}
static int F_336 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_337 ( struct V_1 * V_2 )
{
T_5 V_480 = 0 ;
F_338 ( V_2 -> V_481 , V_482 , & V_480 ) ;
switch ( V_480 & V_483 ) {
case V_484 :
return 267000 ;
case V_485 :
return 333000 ;
case V_486 :
return 444000 ;
case V_487 :
return 200000 ;
default:
F_115 ( L_98 , V_480 ) ;
case V_488 :
return 133000 ;
case V_489 :
return 167000 ;
}
}
static int F_339 ( struct V_1 * V_2 )
{
T_5 V_480 = 0 ;
F_338 ( V_2 -> V_481 , V_482 , & V_480 ) ;
if ( V_480 & V_490 )
return 133000 ;
else {
switch ( V_480 & V_483 ) {
case V_491 :
return 333000 ;
default:
case V_492 :
return 190000 ;
}
}
}
static int F_340 ( struct V_1 * V_2 )
{
return 266000 ;
}
static int F_341 ( struct V_1 * V_2 )
{
T_5 V_493 = 0 ;
switch ( V_493 & V_494 ) {
case V_495 :
case V_496 :
return 200000 ;
case V_497 :
return 250000 ;
case V_498 :
return 133000 ;
}
return 0 ;
}
static int F_342 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_343 ( T_4 * V_499 , T_4 * V_500 )
{
while ( * V_499 > V_501 ||
* V_500 > V_501 ) {
* V_499 >>= 1 ;
* V_500 >>= 1 ;
}
}
static void F_344 ( unsigned int V_11 , unsigned int V_17 ,
T_4 * V_502 , T_4 * V_503 )
{
* V_503 = F_345 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_502 = F_28 ( ( V_504 ) V_11 * * V_503 , V_17 ) ;
F_343 ( V_502 , V_503 ) ;
}
void
F_329 ( int V_270 , int V_505 ,
int V_506 , int V_507 ,
struct V_508 * V_509 )
{
V_509 -> V_510 = 64 ;
F_344 ( V_270 * V_506 ,
V_507 * V_505 * 8 ,
& V_509 -> V_511 , & V_509 -> V_512 ) ;
F_344 ( V_506 , V_507 ,
& V_509 -> V_513 , & V_509 -> V_514 ) ;
}
static inline bool F_346 ( struct V_3 * V_4 )
{
if ( V_515 >= 0 )
return V_515 != 0 ;
return V_4 -> V_516 . V_517
&& ! ( V_4 -> V_138 & V_518 ) ;
}
static int F_347 ( struct V_20 * V_21 , int V_519 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_10 ;
if ( F_17 ( V_2 ) ) {
V_10 = 100000 ;
} else if ( F_9 ( V_21 , V_25 ) &&
F_346 ( V_4 ) && V_519 < 2 ) {
V_10 = V_4 -> V_516 . V_520 ;
F_36 ( L_99 , V_10 ) ;
} else if ( ! F_18 ( V_2 ) ) {
V_10 = 96000 ;
} else {
V_10 = 48000 ;
}
return V_10 ;
}
static T_4 F_348 ( struct V_47 * V_47 )
{
return ( 1 << V_47 -> V_17 ) << 16 | V_47 -> V_13 ;
}
static T_4 F_349 ( struct V_47 * V_47 )
{
return V_47 -> V_17 << 16 | V_47 -> V_12 << 8 | V_47 -> V_13 ;
}
static void F_350 ( struct V_64 * V_21 ,
T_2 * V_521 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_21 -> V_71 ;
T_1 V_522 , V_523 = 0 ;
if ( F_16 ( V_2 ) ) {
V_522 = F_348 ( & V_21 -> V_67 . V_47 ) ;
if ( V_521 )
V_523 = F_348 ( V_521 ) ;
} else {
V_522 = F_349 ( & V_21 -> V_67 . V_47 ) ;
if ( V_521 )
V_523 = F_349 ( V_521 ) ;
}
F_40 ( F_351 ( V_71 ) , V_522 ) ;
V_21 -> V_67 . V_188 . V_524 = V_522 ;
V_21 -> V_525 = false ;
if ( F_9 ( & V_21 -> V_108 , V_25 ) &&
V_521 && V_526 ) {
F_40 ( F_352 ( V_71 ) , V_523 ) ;
V_21 -> V_67 . V_188 . V_527 = V_523 ;
V_21 -> V_525 = true ;
} else {
F_40 ( F_352 ( V_71 ) , V_522 ) ;
V_21 -> V_67 . V_188 . V_527 = V_522 ;
}
}
static void F_353 ( struct V_3 * V_4 , enum V_71
V_71 )
{
T_1 V_528 ;
V_528 = F_354 ( V_4 , V_71 , F_355 ( 1 ) ) ;
V_528 &= 0xffffff00 ;
V_528 |= 0x00000030 ;
F_356 ( V_4 , V_71 , F_355 ( 1 ) , V_528 ) ;
V_528 = F_354 ( V_4 , V_71 , V_529 ) ;
V_528 &= 0x8cffffff ;
V_528 = 0x8c000000 ;
F_356 ( V_4 , V_71 , V_529 , V_528 ) ;
V_528 = F_354 ( V_4 , V_71 , F_355 ( 1 ) ) ;
V_528 &= 0xffffff00 ;
F_356 ( V_4 , V_71 , F_355 ( 1 ) , V_528 ) ;
V_528 = F_354 ( V_4 , V_71 , V_529 ) ;
V_528 &= 0x00ffffff ;
V_528 |= 0xb0000000 ;
F_356 ( V_4 , V_71 , V_529 , V_528 ) ;
}
static void F_357 ( struct V_64 * V_21 ,
struct V_508 * V_509 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_21 -> V_71 ;
F_40 ( F_358 ( V_71 ) , F_359 ( V_509 -> V_510 ) | V_509 -> V_511 ) ;
F_40 ( F_360 ( V_71 ) , V_509 -> V_512 ) ;
F_40 ( F_361 ( V_71 ) , V_509 -> V_513 ) ;
F_40 ( F_362 ( V_71 ) , V_509 -> V_514 ) ;
}
static void F_363 ( struct V_64 * V_21 ,
struct V_508 * V_509 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_21 -> V_71 ;
enum V_70 V_70 = V_21 -> V_67 . V_73 ;
if ( F_39 ( V_2 ) -> V_77 >= 5 ) {
F_40 ( F_239 ( V_70 ) , F_359 ( V_509 -> V_510 ) | V_509 -> V_511 ) ;
F_40 ( F_364 ( V_70 ) , V_509 -> V_512 ) ;
F_40 ( F_365 ( V_70 ) , V_509 -> V_513 ) ;
F_40 ( F_366 ( V_70 ) , V_509 -> V_514 ) ;
} else {
F_40 ( F_367 ( V_71 ) , F_359 ( V_509 -> V_510 ) | V_509 -> V_511 ) ;
F_40 ( F_368 ( V_71 ) , V_509 -> V_512 ) ;
F_40 ( F_369 ( V_71 ) , V_509 -> V_513 ) ;
F_40 ( F_370 ( V_71 ) , V_509 -> V_514 ) ;
}
}
static void F_371 ( struct V_64 * V_21 )
{
if ( V_21 -> V_67 . V_308 )
F_357 ( V_21 , & V_21 -> V_67 . V_530 ) ;
else
F_363 ( V_21 , & V_21 -> V_67 . V_530 ) ;
}
static void F_372 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_21 -> V_71 ;
T_1 V_47 , V_531 ;
T_1 V_532 , V_533 , V_534 , V_535 , V_536 ;
T_1 V_537 , V_528 , V_190 ;
F_53 ( & V_4 -> V_104 ) ;
V_532 = V_21 -> V_67 . V_47 . V_17 ;
V_533 = V_21 -> V_67 . V_47 . V_12 ;
V_534 = V_21 -> V_67 . V_47 . V_13 ;
V_535 = V_21 -> V_67 . V_47 . V_15 ;
V_536 = V_21 -> V_67 . V_47 . V_16 ;
if ( V_71 )
F_353 ( V_4 , V_71 ) ;
F_356 ( V_4 , V_71 , V_538 , 0x0100000f ) ;
V_528 = F_354 ( V_4 , V_71 , F_373 ( V_71 ) ) ;
V_528 &= 0x00ffffff ;
F_356 ( V_4 , V_71 , F_373 ( V_71 ) , V_528 ) ;
F_356 ( V_4 , V_71 , V_539 , 0x610 ) ;
V_531 = ( ( V_533 << V_540 ) | ( V_534 & V_541 ) ) ;
V_531 |= ( ( V_535 << V_542 ) | ( V_536 << V_543 ) ) ;
V_531 |= ( ( V_532 << V_544 ) ) ;
V_531 |= ( 1 << V_545 ) ;
V_531 |= ( V_546 << V_547 ) ;
F_356 ( V_4 , V_71 , F_374 ( V_71 ) , V_531 ) ;
V_531 |= V_548 ;
F_356 ( V_4 , V_71 , F_374 ( V_71 ) , V_531 ) ;
if ( V_21 -> V_67 . V_549 == 162000 ||
F_9 ( & V_21 -> V_108 , V_34 ) ||
F_9 ( & V_21 -> V_108 , V_33 ) )
F_356 ( V_4 , V_71 , F_375 ( V_71 ) ,
0x009f0003 ) ;
else
F_356 ( V_4 , V_71 , F_375 ( V_71 ) ,
0x00d0000f ) ;
if ( F_9 ( & V_21 -> V_108 , V_296 ) ||
F_9 ( & V_21 -> V_108 , V_371 ) ) {
if ( ! V_71 )
F_356 ( V_4 , V_71 , F_376 ( V_71 ) ,
0x0df40000 ) ;
else
F_356 ( V_4 , V_71 , F_376 ( V_71 ) ,
0x0df70000 ) ;
} else {
if ( ! V_71 )
F_356 ( V_4 , V_71 , F_376 ( V_71 ) ,
0x0df70000 ) ;
else
F_356 ( V_4 , V_71 , F_376 ( V_71 ) ,
0x0df40000 ) ;
}
V_537 = F_354 ( V_4 , V_71 , F_377 ( V_71 ) ) ;
V_537 = ( V_537 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_9 ( & V_21 -> V_108 , V_371 ) ||
F_9 ( & V_21 -> V_108 , V_296 ) )
V_537 |= 0x01000000 ;
F_356 ( V_4 , V_71 , F_377 ( V_71 ) , V_537 ) ;
F_356 ( V_4 , V_71 , F_378 ( V_71 ) , 0x87871000 ) ;
V_47 = V_550 | V_184 |
V_551 | V_552 ;
if ( V_71 == V_134 )
V_47 |= V_185 ;
V_47 |= V_103 ;
V_21 -> V_67 . V_188 . V_47 = V_47 ;
V_190 = ( V_21 -> V_67 . V_553 - 1 )
<< V_554 ;
V_21 -> V_67 . V_188 . V_190 = V_190 ;
if ( V_21 -> V_67 . V_555 )
F_371 ( V_21 ) ;
F_55 ( & V_4 -> V_104 ) ;
}
static void F_379 ( struct V_64 * V_21 ,
T_2 * V_521 ,
int V_519 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_47 ;
bool V_556 ;
struct V_47 * clock = & V_21 -> V_67 . V_47 ;
F_350 ( V_21 , V_521 ) ;
V_556 = F_9 ( & V_21 -> V_108 , V_36 ) ||
F_9 ( & V_21 -> V_108 , V_33 ) ;
V_47 = V_551 ;
if ( F_9 ( & V_21 -> V_108 , V_25 ) )
V_47 |= V_557 ;
else
V_47 |= V_558 ;
if ( F_380 ( V_2 ) || F_381 ( V_2 ) || F_382 ( V_2 ) ) {
V_47 |= ( V_21 -> V_67 . V_553 - 1 )
<< V_559 ;
}
if ( V_556 )
V_47 |= V_560 ;
if ( F_9 ( & V_21 -> V_108 , V_371 ) )
V_47 |= V_560 ;
if ( F_16 ( V_2 ) )
V_47 |= ( 1 << ( clock -> V_15 - 1 ) ) << V_561 ;
else {
V_47 |= ( 1 << ( clock -> V_15 - 1 ) ) << V_562 ;
if ( F_15 ( V_2 ) && V_521 )
V_47 |= ( 1 << ( V_521 -> V_15 - 1 ) ) << V_563 ;
}
switch ( clock -> V_16 ) {
case 5 :
V_47 |= V_564 ;
break;
case 7 :
V_47 |= V_565 ;
break;
case 10 :
V_47 |= V_566 ;
break;
case 14 :
V_47 |= V_567 ;
break;
}
if ( F_39 ( V_2 ) -> V_77 >= 4 )
V_47 |= ( 6 << V_568 ) ;
if ( V_21 -> V_67 . V_569 )
V_47 |= V_570 ;
else if ( F_9 ( & V_21 -> V_108 , V_25 ) &&
F_346 ( V_4 ) && V_519 < 2 )
V_47 |= V_571 ;
else
V_47 |= V_572 ;
V_47 |= V_103 ;
V_21 -> V_67 . V_188 . V_47 = V_47 ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
T_1 V_190 = ( V_21 -> V_67 . V_553 - 1 )
<< V_554 ;
V_21 -> V_67 . V_188 . V_190 = V_190 ;
}
if ( V_21 -> V_67 . V_555 )
F_371 ( V_21 ) ;
}
static void F_383 ( struct V_64 * V_21 ,
T_2 * V_521 ,
int V_519 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_47 ;
struct V_47 * clock = & V_21 -> V_67 . V_47 ;
F_350 ( V_21 , V_521 ) ;
V_47 = V_551 ;
if ( F_9 ( & V_21 -> V_108 , V_25 ) ) {
V_47 |= ( 1 << ( clock -> V_15 - 1 ) ) << V_562 ;
} else {
if ( clock -> V_15 == 2 )
V_47 |= V_573 ;
else
V_47 |= ( clock -> V_15 - 2 ) << V_562 ;
if ( clock -> V_16 == 4 )
V_47 |= V_574 ;
}
if ( F_9 ( & V_21 -> V_108 , V_44 ) )
V_47 |= V_575 ;
if ( F_9 ( & V_21 -> V_108 , V_25 ) &&
F_346 ( V_4 ) && V_519 < 2 )
V_47 |= V_571 ;
else
V_47 |= V_572 ;
V_47 |= V_103 ;
V_21 -> V_67 . V_188 . V_47 = V_47 ;
}
static void F_384 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_71 V_71 = V_64 -> V_71 ;
enum V_70 V_73 = V_64 -> V_67 . V_73 ;
struct V_292 * V_68 =
& V_64 -> V_67 . V_68 ;
T_4 V_576 , V_577 , V_578 ;
V_577 = V_68 -> V_577 ;
V_578 = V_68 -> V_578 ;
if ( ! F_18 ( V_2 ) && V_68 -> V_338 & V_579 ) {
V_577 -= 1 ;
V_578 -= 1 ;
V_576 = V_68 -> V_580
- V_68 -> V_581 / 2 ;
} else {
V_576 = 0 ;
}
if ( F_39 ( V_2 ) -> V_77 > 3 )
F_40 ( F_234 ( V_73 ) , V_576 ) ;
F_40 ( F_222 ( V_73 ) ,
( V_68 -> V_293 - 1 ) |
( ( V_68 -> V_581 - 1 ) << 16 ) ) ;
F_40 ( F_224 ( V_73 ) ,
( V_68 -> V_582 - 1 ) |
( ( V_68 -> V_583 - 1 ) << 16 ) ) ;
F_40 ( F_226 ( V_73 ) ,
( V_68 -> V_580 - 1 ) |
( ( V_68 -> V_584 - 1 ) << 16 ) ) ;
F_40 ( F_228 ( V_73 ) ,
( V_68 -> V_294 - 1 ) |
( ( V_577 - 1 ) << 16 ) ) ;
F_40 ( F_230 ( V_73 ) ,
( V_68 -> V_585 - 1 ) |
( ( V_578 - 1 ) << 16 ) ) ;
F_40 ( F_232 ( V_73 ) ,
( V_68 -> V_586 - 1 ) |
( ( V_68 -> V_587 - 1 ) << 16 ) ) ;
if ( F_167 ( V_2 ) && V_73 == V_588 &&
( V_71 == V_134 || V_71 == V_311 ) )
F_40 ( F_228 ( V_71 ) , F_4 ( F_228 ( V_73 ) ) ) ;
F_40 ( F_180 ( V_71 ) ,
( ( V_64 -> V_67 . V_297 - 1 ) << 16 ) |
( V_64 -> V_67 . V_298 - 1 ) ) ;
}
static void F_385 ( struct V_64 * V_21 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_70 V_73 = V_419 -> V_73 ;
T_4 V_589 ;
V_589 = F_4 ( F_222 ( V_73 ) ) ;
V_419 -> V_68 . V_293 = ( V_589 & 0xffff ) + 1 ;
V_419 -> V_68 . V_581 = ( ( V_589 >> 16 ) & 0xffff ) + 1 ;
V_589 = F_4 ( F_224 ( V_73 ) ) ;
V_419 -> V_68 . V_582 = ( V_589 & 0xffff ) + 1 ;
V_419 -> V_68 . V_583 = ( ( V_589 >> 16 ) & 0xffff ) + 1 ;
V_589 = F_4 ( F_226 ( V_73 ) ) ;
V_419 -> V_68 . V_580 = ( V_589 & 0xffff ) + 1 ;
V_419 -> V_68 . V_584 = ( ( V_589 >> 16 ) & 0xffff ) + 1 ;
V_589 = F_4 ( F_228 ( V_73 ) ) ;
V_419 -> V_68 . V_294 = ( V_589 & 0xffff ) + 1 ;
V_419 -> V_68 . V_577 = ( ( V_589 >> 16 ) & 0xffff ) + 1 ;
V_589 = F_4 ( F_230 ( V_73 ) ) ;
V_419 -> V_68 . V_585 = ( V_589 & 0xffff ) + 1 ;
V_419 -> V_68 . V_578 = ( ( V_589 >> 16 ) & 0xffff ) + 1 ;
V_589 = F_4 ( F_232 ( V_73 ) ) ;
V_419 -> V_68 . V_586 = ( V_589 & 0xffff ) + 1 ;
V_419 -> V_68 . V_587 = ( ( V_589 >> 16 ) & 0xffff ) + 1 ;
if ( F_4 ( F_45 ( V_73 ) ) & V_204 ) {
V_419 -> V_68 . V_338 |= V_579 ;
V_419 -> V_68 . V_577 += 1 ;
V_419 -> V_68 . V_578 += 1 ;
}
V_589 = F_4 ( F_180 ( V_21 -> V_71 ) ) ;
V_419 -> V_298 = ( V_589 & 0xffff ) + 1 ;
V_419 -> V_297 = ( ( V_589 >> 16 ) & 0xffff ) + 1 ;
V_419 -> V_590 . V_450 = V_419 -> V_298 ;
V_419 -> V_590 . V_448 = V_419 -> V_297 ;
}
static void F_386 ( struct V_64 * V_64 ,
struct V_418 * V_419 )
{
struct V_20 * V_21 = & V_64 -> V_108 ;
V_21 -> V_377 . V_448 = V_419 -> V_68 . V_293 ;
V_21 -> V_377 . V_591 = V_419 -> V_68 . V_581 ;
V_21 -> V_377 . V_479 = V_419 -> V_68 . V_580 ;
V_21 -> V_377 . V_592 = V_419 -> V_68 . V_584 ;
V_21 -> V_377 . V_450 = V_419 -> V_68 . V_294 ;
V_21 -> V_377 . V_593 = V_419 -> V_68 . V_577 ;
V_21 -> V_377 . V_594 = V_419 -> V_68 . V_586 ;
V_21 -> V_377 . V_595 = V_419 -> V_68 . V_587 ;
V_21 -> V_377 . V_338 = V_419 -> V_68 . V_338 ;
V_21 -> V_377 . clock = V_419 -> V_68 . V_69 ;
V_21 -> V_377 . V_338 |= V_419 -> V_68 . V_338 ;
}
static void F_387 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_596 ;
V_596 = 0 ;
if ( V_4 -> V_138 & V_139 &&
F_4 ( F_45 ( V_64 -> V_71 ) ) & V_140 )
V_596 |= V_140 ;
if ( V_64 -> V_67 . V_478 )
V_596 |= V_597 ;
if ( F_15 ( V_2 ) || F_17 ( V_2 ) ) {
if ( V_64 -> V_67 . V_598 && V_64 -> V_67 . V_471 != 30 )
V_596 |= V_599 |
V_600 ;
switch ( V_64 -> V_67 . V_471 ) {
case 18 :
V_596 |= V_601 ;
break;
case 24 :
V_596 |= V_602 ;
break;
case 30 :
V_596 |= V_603 ;
break;
default:
F_121 () ;
}
}
if ( F_388 ( V_2 ) ) {
if ( V_64 -> V_525 ) {
F_36 ( L_100 ) ;
V_596 |= V_604 ;
} else {
F_36 ( L_101 ) ;
}
}
if ( ! F_18 ( V_2 ) &&
V_64 -> V_67 . V_68 . V_338 & V_579 )
V_596 |= V_605 ;
else
V_596 |= V_606 ;
if ( F_17 ( V_2 ) && V_64 -> V_67 . V_607 )
V_596 |= V_608 ;
F_40 ( F_45 ( V_64 -> V_71 ) , V_596 ) ;
F_113 ( F_45 ( V_64 -> V_71 ) ) ;
}
static int F_389 ( struct V_20 * V_21 ,
int V_234 , int V_235 ,
struct V_241 * V_66 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
int V_10 , V_519 = 0 ;
T_2 clock , V_521 ;
T_1 V_245 ;
bool V_609 , V_610 = false ;
bool V_611 = false , V_445 = false ;
struct V_22 * V_23 ;
const T_3 * V_24 ;
int V_224 ;
F_10 (dev, crtc, encoder) {
switch ( V_23 -> type ) {
case V_25 :
V_611 = true ;
break;
case V_400 :
V_445 = true ;
break;
}
V_519 ++ ;
}
if ( V_445 )
goto V_612;
if ( ! V_64 -> V_67 . V_613 ) {
V_10 = F_347 ( V_21 , V_519 ) ;
V_24 = F_14 ( V_21 , V_10 ) ;
V_609 = V_4 -> V_273 . V_614 ( V_24 , V_21 ,
V_64 -> V_67 . V_549 ,
V_10 , NULL , & clock ) ;
if ( ! V_609 ) {
F_115 ( L_102 ) ;
return - V_229 ;
}
if ( V_611 && V_4 -> V_615 ) {
V_610 =
V_4 -> V_273 . V_614 ( V_24 , V_21 ,
V_4 -> V_616 ,
V_10 , & clock ,
& V_521 ) ;
}
V_64 -> V_67 . V_47 . V_17 = clock . V_17 ;
V_64 -> V_67 . V_47 . V_12 = clock . V_12 ;
V_64 -> V_67 . V_47 . V_13 = clock . V_13 ;
V_64 -> V_67 . V_47 . V_15 = clock . V_15 ;
V_64 -> V_67 . V_47 . V_16 = clock . V_16 ;
}
if ( F_18 ( V_2 ) ) {
F_383 ( V_64 ,
V_610 ? & V_521 : NULL ,
V_519 ) ;
} else if ( F_17 ( V_2 ) ) {
F_372 ( V_64 ) ;
} else {
F_379 ( V_64 ,
V_610 ? & V_521 : NULL ,
V_519 ) ;
}
V_612:
V_245 = V_617 ;
if ( ! F_17 ( V_2 ) ) {
if ( V_71 == 0 )
V_245 &= ~ V_145 ;
else
V_245 |= V_618 ;
}
F_384 ( V_64 ) ;
F_40 ( F_390 ( V_141 ) ,
( ( V_64 -> V_67 . V_298 - 1 ) << 16 ) |
( V_64 -> V_67 . V_297 - 1 ) ) ;
F_40 ( F_391 ( V_141 ) , 0 ) ;
F_387 ( V_64 ) ;
F_40 ( F_79 ( V_141 ) , V_245 ) ;
F_113 ( F_79 ( V_141 ) ) ;
V_224 = F_179 ( V_21 , V_234 , V_235 , V_66 ) ;
return V_224 ;
}
static void F_392 ( struct V_64 * V_21 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_589 ;
if ( F_39 ( V_2 ) -> V_77 <= 3 && ( F_112 ( V_2 ) || ! F_111 ( V_2 ) ) )
return;
V_589 = F_4 ( V_422 ) ;
if ( ! ( V_589 & V_423 ) )
return;
if ( F_39 ( V_2 ) -> V_77 < 4 ) {
if ( V_21 -> V_71 != V_134 )
return;
} else {
if ( ( V_589 & V_619 ) != ( V_21 -> V_71 << V_620 ) )
return;
}
V_419 -> V_420 . V_421 = V_589 ;
V_419 -> V_420 . V_425 = F_4 ( V_424 ) ;
if ( F_39 ( V_2 ) -> V_77 < 5 )
V_419 -> V_420 . V_621 =
F_4 ( V_130 ) & V_622 ;
}
static void F_393 ( struct V_64 * V_21 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_419 -> V_73 ;
T_2 clock ;
T_1 V_531 ;
int V_10 = 100000 ;
F_53 ( & V_4 -> V_104 ) ;
V_531 = F_354 ( V_4 , V_71 , F_374 ( V_71 ) ) ;
F_55 ( & V_4 -> V_104 ) ;
clock . V_12 = ( V_531 >> V_540 ) & 7 ;
clock . V_13 = V_531 & V_541 ;
clock . V_17 = ( V_531 >> V_544 ) & 0xf ;
clock . V_15 = ( V_531 >> V_542 ) & 7 ;
clock . V_16 = ( V_531 >> V_543 ) & 0x1f ;
F_7 ( V_10 , & clock ) ;
V_419 -> V_549 = clock . V_19 / 5 ;
}
static bool F_394 ( struct V_64 * V_21 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_589 ;
V_419 -> V_73 = (enum V_70 ) V_21 -> V_71 ;
V_419 -> V_109 = V_382 ;
V_589 = F_4 ( F_45 ( V_21 -> V_71 ) ) ;
if ( ! ( V_589 & V_140 ) )
return false ;
if ( F_15 ( V_2 ) || F_17 ( V_2 ) ) {
switch ( V_589 & V_202 ) {
case V_601 :
V_419 -> V_471 = 18 ;
break;
case V_602 :
V_419 -> V_471 = 24 ;
break;
case V_603 :
V_419 -> V_471 = 30 ;
break;
default:
break;
}
}
if ( F_39 ( V_2 ) -> V_77 < 4 )
V_419 -> V_478 = V_589 & V_597 ;
F_385 ( V_21 , V_419 ) ;
F_392 ( V_21 , V_419 ) ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
V_589 = F_4 ( F_116 ( V_21 -> V_71 ) ) ;
V_419 -> V_553 =
( ( V_589 & V_623 )
>> V_554 ) + 1 ;
V_419 -> V_188 . V_190 = V_589 ;
} else if ( F_380 ( V_2 ) || F_381 ( V_2 ) || F_382 ( V_2 ) ) {
V_589 = F_4 ( F_51 ( V_21 -> V_71 ) ) ;
V_419 -> V_553 =
( ( V_589 & V_624 )
>> V_559 ) + 1 ;
} else {
V_419 -> V_553 = 1 ;
}
V_419 -> V_188 . V_47 = F_4 ( F_51 ( V_21 -> V_71 ) ) ;
if ( ! F_17 ( V_2 ) ) {
V_419 -> V_188 . V_524 = F_4 ( F_351 ( V_21 -> V_71 ) ) ;
V_419 -> V_188 . V_527 = F_4 ( F_352 ( V_21 -> V_71 ) ) ;
} else {
V_419 -> V_188 . V_47 &= ~ ( V_189 |
V_194 |
V_193 ) ;
}
if ( F_17 ( V_2 ) )
F_393 ( V_21 , V_419 ) ;
else
F_395 ( V_21 , V_419 ) ;
return true ;
}
static void F_396 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_625 * V_626 = & V_2 -> V_626 ;
struct V_22 * V_23 ;
T_1 V_101 , V_627 ;
bool V_628 = false ;
bool V_629 = false ;
bool V_630 = false ;
bool V_631 = false ;
bool V_632 = false ;
F_173 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_23 -> type ) {
case V_25 :
V_630 = true ;
V_628 = true ;
break;
case V_296 :
V_630 = true ;
if ( F_397 ( & V_23 -> V_108 ) -> V_87 == V_633 )
V_629 = true ;
break;
}
}
if ( F_48 ( V_2 ) ) {
V_631 = V_4 -> V_516 . V_634 ;
V_632 = V_631 ;
} else {
V_631 = false ;
V_632 = true ;
}
F_36 ( L_103 ,
V_630 , V_628 , V_631 ) ;
V_101 = F_4 ( V_151 ) ;
V_627 = V_101 ;
V_627 &= ~ V_153 ;
if ( V_631 )
V_627 |= V_635 ;
else
V_627 |= V_636 ;
V_627 &= ~ V_152 ;
V_627 &= ~ V_637 ;
V_627 &= ~ V_638 ;
if ( V_630 ) {
V_627 |= V_639 ;
if ( F_346 ( V_4 ) && V_632 )
V_627 |= V_638 ;
if ( V_629 ) {
if ( F_346 ( V_4 ) && V_632 )
V_627 |= V_640 ;
else
V_627 |= V_641 ;
} else
V_627 |= V_642 ;
} else {
V_627 |= V_643 ;
V_627 |= V_642 ;
}
if ( V_627 == V_101 )
return;
V_101 &= ~ V_153 ;
if ( V_631 )
V_101 |= V_635 ;
else
V_101 |= V_636 ;
if ( V_630 ) {
V_101 &= ~ V_152 ;
V_101 |= V_639 ;
if ( F_346 ( V_4 ) && V_632 ) {
F_36 ( L_104 ) ;
V_101 |= V_638 ;
} else
V_101 &= ~ V_638 ;
F_40 ( V_151 , V_101 ) ;
F_113 ( V_151 ) ;
F_114 ( 200 ) ;
V_101 &= ~ V_637 ;
if ( V_629 ) {
if ( F_346 ( V_4 ) && V_632 ) {
F_36 ( L_105 ) ;
V_101 |= V_640 ;
}
else
V_101 |= V_641 ;
} else
V_101 |= V_642 ;
F_40 ( V_151 , V_101 ) ;
F_113 ( V_151 ) ;
F_114 ( 200 ) ;
} else {
F_36 ( L_106 ) ;
V_101 &= ~ V_637 ;
V_101 |= V_642 ;
F_40 ( V_151 , V_101 ) ;
F_113 ( V_151 ) ;
F_114 ( 200 ) ;
V_101 &= ~ V_152 ;
V_101 |= V_643 ;
V_101 &= ~ V_638 ;
F_40 ( V_151 , V_101 ) ;
F_113 ( V_151 ) ;
F_114 ( 200 ) ;
}
F_110 ( V_101 != V_627 ) ;
}
static void F_398 ( struct V_3 * V_4 )
{
T_4 V_589 ;
V_589 = F_4 ( V_644 ) ;
V_589 |= V_645 ;
F_40 ( V_644 , V_589 ) ;
if ( F_399 ( F_4 ( V_644 ) &
V_646 , 100 ) )
F_115 ( L_107 ) ;
V_589 = F_4 ( V_644 ) ;
V_589 &= ~ V_645 ;
F_40 ( V_644 , V_589 ) ;
if ( F_399 ( ( F_4 ( V_644 ) &
V_646 ) == 0 , 100 ) )
F_115 ( L_108 ) ;
}
static void F_400 ( struct V_3 * V_4 )
{
T_4 V_589 ;
V_589 = F_215 ( V_4 , 0x8008 , V_647 ) ;
V_589 &= ~ ( 0xFF << 24 ) ;
V_589 |= ( 0x12 << 24 ) ;
F_214 ( V_4 , 0x8008 , V_589 , V_647 ) ;
V_589 = F_215 ( V_4 , 0x2008 , V_647 ) ;
V_589 |= ( 1 << 11 ) ;
F_214 ( V_4 , 0x2008 , V_589 , V_647 ) ;
V_589 = F_215 ( V_4 , 0x2108 , V_647 ) ;
V_589 |= ( 1 << 11 ) ;
F_214 ( V_4 , 0x2108 , V_589 , V_647 ) ;
V_589 = F_215 ( V_4 , 0x206C , V_647 ) ;
V_589 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_214 ( V_4 , 0x206C , V_589 , V_647 ) ;
V_589 = F_215 ( V_4 , 0x216C , V_647 ) ;
V_589 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_214 ( V_4 , 0x216C , V_589 , V_647 ) ;
V_589 = F_215 ( V_4 , 0x2080 , V_647 ) ;
V_589 &= ~ ( 7 << 13 ) ;
V_589 |= ( 5 << 13 ) ;
F_214 ( V_4 , 0x2080 , V_589 , V_647 ) ;
V_589 = F_215 ( V_4 , 0x2180 , V_647 ) ;
V_589 &= ~ ( 7 << 13 ) ;
V_589 |= ( 5 << 13 ) ;
F_214 ( V_4 , 0x2180 , V_589 , V_647 ) ;
V_589 = F_215 ( V_4 , 0x208C , V_647 ) ;
V_589 &= ~ 0xFF ;
V_589 |= 0x1C ;
F_214 ( V_4 , 0x208C , V_589 , V_647 ) ;
V_589 = F_215 ( V_4 , 0x218C , V_647 ) ;
V_589 &= ~ 0xFF ;
V_589 |= 0x1C ;
F_214 ( V_4 , 0x218C , V_589 , V_647 ) ;
V_589 = F_215 ( V_4 , 0x2098 , V_647 ) ;
V_589 &= ~ ( 0xFF << 16 ) ;
V_589 |= ( 0x1C << 16 ) ;
F_214 ( V_4 , 0x2098 , V_589 , V_647 ) ;
V_589 = F_215 ( V_4 , 0x2198 , V_647 ) ;
V_589 &= ~ ( 0xFF << 16 ) ;
V_589 |= ( 0x1C << 16 ) ;
F_214 ( V_4 , 0x2198 , V_589 , V_647 ) ;
V_589 = F_215 ( V_4 , 0x20C4 , V_647 ) ;
V_589 |= ( 1 << 27 ) ;
F_214 ( V_4 , 0x20C4 , V_589 , V_647 ) ;
V_589 = F_215 ( V_4 , 0x21C4 , V_647 ) ;
V_589 |= ( 1 << 27 ) ;
F_214 ( V_4 , 0x21C4 , V_589 , V_647 ) ;
V_589 = F_215 ( V_4 , 0x20EC , V_647 ) ;
V_589 &= ~ ( 0xF << 28 ) ;
V_589 |= ( 4 << 28 ) ;
F_214 ( V_4 , 0x20EC , V_589 , V_647 ) ;
V_589 = F_215 ( V_4 , 0x21EC , V_647 ) ;
V_589 &= ~ ( 0xF << 28 ) ;
V_589 |= ( 4 << 28 ) ;
F_214 ( V_4 , 0x21EC , V_589 , V_647 ) ;
}
static void F_401 ( struct V_1 * V_2 , bool V_648 ,
bool V_649 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_79 , V_589 ;
if ( F_46 ( V_649 && ! V_648 , L_109 ) )
V_648 = true ;
if ( F_46 ( V_4 -> V_650 == V_651 &&
V_649 , L_110 ) )
V_649 = false ;
F_53 ( & V_4 -> V_104 ) ;
V_589 = F_215 ( V_4 , V_652 , V_353 ) ;
V_589 &= ~ V_354 ;
V_589 |= V_653 ;
F_214 ( V_4 , V_652 , V_589 , V_353 ) ;
F_114 ( 24 ) ;
if ( V_648 ) {
V_589 = F_215 ( V_4 , V_652 , V_353 ) ;
V_589 &= ~ V_653 ;
F_214 ( V_4 , V_652 , V_589 , V_353 ) ;
if ( V_649 ) {
F_398 ( V_4 ) ;
F_400 ( V_4 ) ;
}
}
V_79 = ( V_4 -> V_650 == V_651 ) ?
V_654 : V_655 ;
V_589 = F_215 ( V_4 , V_79 , V_353 ) ;
V_589 |= V_656 ;
F_214 ( V_4 , V_79 , V_589 , V_353 ) ;
F_55 ( & V_4 -> V_104 ) ;
}
static void F_402 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_79 , V_589 ;
F_53 ( & V_4 -> V_104 ) ;
V_79 = ( V_4 -> V_650 == V_651 ) ?
V_654 : V_655 ;
V_589 = F_215 ( V_4 , V_79 , V_353 ) ;
V_589 &= ~ V_656 ;
F_214 ( V_4 , V_79 , V_589 , V_353 ) ;
V_589 = F_215 ( V_4 , V_652 , V_353 ) ;
if ( ! ( V_589 & V_354 ) ) {
if ( ! ( V_589 & V_653 ) ) {
V_589 |= V_653 ;
F_214 ( V_4 , V_652 , V_589 , V_353 ) ;
F_114 ( 32 ) ;
}
V_589 |= V_354 ;
F_214 ( V_4 , V_652 , V_589 , V_353 ) ;
}
F_55 ( & V_4 -> V_104 ) ;
}
static void F_403 ( struct V_1 * V_2 )
{
struct V_625 * V_626 = & V_2 -> V_626 ;
struct V_22 * V_23 ;
bool V_657 = false ;
F_173 (encoder, &mode_config->encoder_list, base.head) {
switch ( V_23 -> type ) {
case V_34 :
V_657 = true ;
break;
}
}
if ( V_657 )
F_401 ( V_2 , true , true ) ;
else
F_402 ( V_2 ) ;
}
void F_404 ( struct V_1 * V_2 )
{
if ( F_48 ( V_2 ) || F_89 ( V_2 ) )
F_396 ( V_2 ) ;
else if ( F_58 ( V_2 ) )
F_403 ( V_2 ) ;
}
static int F_405 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_23 ;
int V_519 = 0 ;
bool V_611 = false ;
F_10 (dev, crtc, encoder) {
switch ( V_23 -> type ) {
case V_25 :
V_611 = true ;
break;
}
V_519 ++ ;
}
if ( V_611 && F_346 ( V_4 ) && V_519 < 2 ) {
F_36 ( L_99 ,
V_4 -> V_516 . V_520 ) ;
return V_4 -> V_516 . V_520 ;
}
return 120000 ;
}
static void F_406 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
T_4 V_101 ;
V_101 = 0 ;
switch ( V_64 -> V_67 . V_471 ) {
case 18 :
V_101 |= V_601 ;
break;
case 24 :
V_101 |= V_602 ;
break;
case 30 :
V_101 |= V_603 ;
break;
case 36 :
V_101 |= V_658 ;
break;
default:
F_121 () ;
}
if ( V_64 -> V_67 . V_598 )
V_101 |= ( V_599 | V_600 ) ;
if ( V_64 -> V_67 . V_68 . V_338 & V_579 )
V_101 |= V_205 ;
else
V_101 |= V_606 ;
if ( V_64 -> V_67 . V_607 )
V_101 |= V_608 ;
F_40 ( F_45 ( V_71 ) , V_101 ) ;
F_113 ( F_45 ( V_71 ) ) ;
}
static void F_407 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
T_6 V_659 = 0x7800 ;
if ( V_64 -> V_67 . V_607 )
V_659 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_40 ( F_408 ( V_71 ) , V_659 << 16 ) ;
F_40 ( F_409 ( V_71 ) , 0 ) ;
F_40 ( F_410 ( V_71 ) , V_659 ) ;
F_40 ( F_411 ( V_71 ) , 0 ) ;
F_40 ( F_412 ( V_71 ) , 0 ) ;
F_40 ( F_413 ( V_71 ) , V_659 << 16 ) ;
F_40 ( F_414 ( V_71 ) , 0 ) ;
F_40 ( F_415 ( V_71 ) , 0 ) ;
F_40 ( F_416 ( V_71 ) , 0 ) ;
if ( F_39 ( V_2 ) -> V_77 > 6 ) {
T_6 V_660 = 0 ;
if ( V_64 -> V_67 . V_607 )
V_660 = ( 16 * ( 1 << 12 ) / 255 ) & 0x1fff ;
F_40 ( F_417 ( V_71 ) , V_660 ) ;
F_40 ( F_418 ( V_71 ) , V_660 ) ;
F_40 ( F_419 ( V_71 ) , V_660 ) ;
F_40 ( F_420 ( V_71 ) , 0 ) ;
} else {
T_4 V_377 = V_661 ;
if ( V_64 -> V_67 . V_607 )
V_377 |= V_662 ;
F_40 ( F_420 ( V_71 ) , V_377 ) ;
}
}
static void F_421 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_71 V_71 = V_64 -> V_71 ;
enum V_70 V_73 = V_64 -> V_67 . V_73 ;
T_4 V_101 ;
V_101 = 0 ;
if ( F_167 ( V_2 ) && V_64 -> V_67 . V_598 )
V_101 |= ( V_599 | V_600 ) ;
if ( V_64 -> V_67 . V_68 . V_338 & V_579 )
V_101 |= V_205 ;
else
V_101 |= V_606 ;
F_40 ( F_45 ( V_73 ) , V_101 ) ;
F_113 ( F_45 ( V_73 ) ) ;
F_40 ( F_259 ( V_64 -> V_71 ) , V_663 ) ;
F_113 ( F_259 ( V_64 -> V_71 ) ) ;
if ( F_168 ( V_2 ) ) {
V_101 = 0 ;
switch ( V_64 -> V_67 . V_471 ) {
case 18 :
V_101 |= V_664 ;
break;
case 24 :
V_101 |= V_665 ;
break;
case 30 :
V_101 |= V_666 ;
break;
case 36 :
V_101 |= V_667 ;
break;
default:
F_121 () ;
}
if ( V_64 -> V_67 . V_598 )
V_101 |= V_668 | V_669 ;
F_40 ( F_422 ( V_71 ) , V_101 ) ;
}
}
static bool F_423 ( struct V_20 * V_21 ,
T_2 * clock ,
bool * V_610 ,
T_2 * V_521 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_22 ;
int V_10 ;
const T_3 * V_24 ;
bool V_224 , V_611 = false ;
F_10 (dev, crtc, intel_encoder) {
switch ( V_22 -> type ) {
case V_25 :
V_611 = true ;
break;
}
}
V_10 = F_405 ( V_21 ) ;
V_24 = F_14 ( V_21 , V_10 ) ;
V_224 = V_4 -> V_273 . V_614 ( V_24 , V_21 ,
F_30 ( V_21 ) -> V_67 . V_549 ,
V_10 , NULL , clock ) ;
if ( ! V_224 )
return false ;
if ( V_611 && V_4 -> V_615 ) {
* V_610 =
V_4 -> V_273 . V_614 ( V_24 , V_21 ,
V_4 -> V_616 ,
V_10 , clock ,
V_521 ) ;
}
return true ;
}
int F_328 ( int V_670 , int V_467 , int V_671 )
{
T_1 V_672 = V_670 * V_671 * 21 / 20 ;
return V_672 / ( V_467 * 8 ) + 1 ;
}
static bool F_424 ( struct V_47 * V_47 , int V_673 )
{
return F_20 ( V_47 ) < V_673 * V_47 -> V_17 ;
}
static T_4 F_425 ( struct V_64 * V_64 ,
T_1 * V_522 ,
T_2 * V_521 , T_1 * V_523 )
{
struct V_20 * V_21 = & V_64 -> V_108 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_22 ;
T_4 V_47 ;
int V_673 , V_519 = 0 ;
bool V_611 = false , V_556 = false ;
F_10 (dev, crtc, intel_encoder) {
switch ( V_22 -> type ) {
case V_25 :
V_611 = true ;
break;
case V_36 :
case V_33 :
V_556 = true ;
break;
}
V_519 ++ ;
}
V_673 = 21 ;
if ( V_611 ) {
if ( ( F_346 ( V_4 ) &&
V_4 -> V_516 . V_520 == 100000 ) ||
( F_48 ( V_2 ) && F_12 ( V_2 ) ) )
V_673 = 25 ;
} else if ( V_64 -> V_67 . V_569 )
V_673 = 20 ;
if ( F_424 ( & V_64 -> V_67 . V_47 , V_673 ) )
* V_522 |= V_674 ;
if ( V_523 && ( V_521 -> V_11 < V_673 * V_521 -> V_17 ) )
* V_523 |= V_674 ;
V_47 = 0 ;
if ( V_611 )
V_47 |= V_557 ;
else
V_47 |= V_558 ;
V_47 |= ( V_64 -> V_67 . V_553 - 1 )
<< V_675 ;
if ( V_556 )
V_47 |= V_560 ;
if ( V_64 -> V_67 . V_555 )
V_47 |= V_560 ;
V_47 |= ( 1 << ( V_64 -> V_67 . V_47 . V_15 - 1 ) ) << V_562 ;
V_47 |= ( 1 << ( V_64 -> V_67 . V_47 . V_15 - 1 ) ) << V_563 ;
switch ( V_64 -> V_67 . V_47 . V_16 ) {
case 5 :
V_47 |= V_564 ;
break;
case 7 :
V_47 |= V_565 ;
break;
case 10 :
V_47 |= V_566 ;
break;
case 14 :
V_47 |= V_567 ;
break;
}
if ( V_611 && F_346 ( V_4 ) && V_519 < 2 )
V_47 |= V_571 ;
else
V_47 |= V_572 ;
return V_47 | V_103 ;
}
static int F_426 ( struct V_20 * V_21 ,
int V_234 , int V_235 ,
struct V_241 * V_66 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
int V_141 = V_64 -> V_141 ;
int V_519 = 0 ;
T_2 clock , V_521 ;
T_1 V_47 = 0 , V_522 = 0 , V_523 = 0 ;
bool V_609 , V_610 = false ;
bool V_611 = false ;
struct V_22 * V_23 ;
struct V_107 * V_111 ;
int V_224 ;
F_10 (dev, crtc, encoder) {
switch ( V_23 -> type ) {
case V_25 :
V_611 = true ;
break;
}
V_519 ++ ;
}
F_46 ( ! ( F_48 ( V_2 ) || F_89 ( V_2 ) ) ,
L_111 , F_427 ( V_2 ) ) ;
V_609 = F_423 ( V_21 , & clock ,
& V_610 , & V_521 ) ;
if ( ! V_609 && ! V_64 -> V_67 . V_613 ) {
F_115 ( L_102 ) ;
return - V_229 ;
}
if ( ! V_64 -> V_67 . V_613 ) {
V_64 -> V_67 . V_47 . V_17 = clock . V_17 ;
V_64 -> V_67 . V_47 . V_12 = clock . V_12 ;
V_64 -> V_67 . V_47 . V_13 = clock . V_13 ;
V_64 -> V_67 . V_47 . V_15 = clock . V_15 ;
V_64 -> V_67 . V_47 . V_16 = clock . V_16 ;
}
if ( V_64 -> V_67 . V_308 ) {
V_522 = F_349 ( & V_64 -> V_67 . V_47 ) ;
if ( V_610 )
V_523 = F_349 ( & V_521 ) ;
V_47 = F_425 ( V_64 ,
& V_522 , & V_521 ,
V_610 ? & V_523 : NULL ) ;
V_64 -> V_67 . V_188 . V_47 = V_47 ;
V_64 -> V_67 . V_188 . V_524 = V_522 ;
if ( V_610 )
V_64 -> V_67 . V_188 . V_527 = V_523 ;
else
V_64 -> V_67 . V_188 . V_527 = V_522 ;
V_111 = F_245 ( V_64 ) ;
if ( V_111 == NULL ) {
F_59 ( L_112 ,
F_69 ( V_71 ) ) ;
return - V_229 ;
}
} else
F_244 ( V_64 ) ;
if ( V_64 -> V_67 . V_555 )
F_371 ( V_64 ) ;
if ( V_611 && V_610 && V_526 )
V_64 -> V_525 = true ;
else
V_64 -> V_525 = false ;
F_384 ( V_64 ) ;
if ( V_64 -> V_67 . V_308 ) {
F_363 ( V_64 ,
& V_64 -> V_67 . V_472 ) ;
}
F_406 ( V_21 ) ;
F_40 ( F_79 ( V_141 ) , V_617 ) ;
F_113 ( F_79 ( V_141 ) ) ;
V_224 = F_179 ( V_21 , V_234 , V_235 , V_66 ) ;
return V_224 ;
}
static void F_428 ( struct V_64 * V_21 ,
struct V_508 * V_509 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_71 V_71 = V_21 -> V_71 ;
V_509 -> V_513 = F_4 ( F_361 ( V_71 ) ) ;
V_509 -> V_514 = F_4 ( F_362 ( V_71 ) ) ;
V_509 -> V_511 = F_4 ( F_358 ( V_71 ) )
& ~ V_366 ;
V_509 -> V_512 = F_4 ( F_360 ( V_71 ) ) ;
V_509 -> V_510 = ( ( F_4 ( F_358 ( V_71 ) )
& V_366 ) >> V_676 ) + 1 ;
}
static void F_429 ( struct V_64 * V_21 ,
enum V_70 V_70 ,
struct V_508 * V_509 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_71 V_71 = V_21 -> V_71 ;
if ( F_39 ( V_2 ) -> V_77 >= 5 ) {
V_509 -> V_513 = F_4 ( F_365 ( V_70 ) ) ;
V_509 -> V_514 = F_4 ( F_366 ( V_70 ) ) ;
V_509 -> V_511 = F_4 ( F_239 ( V_70 ) )
& ~ V_366 ;
V_509 -> V_512 = F_4 ( F_364 ( V_70 ) ) ;
V_509 -> V_510 = ( ( F_4 ( F_239 ( V_70 ) )
& V_366 ) >> V_676 ) + 1 ;
} else {
V_509 -> V_513 = F_4 ( F_369 ( V_71 ) ) ;
V_509 -> V_514 = F_4 ( F_370 ( V_71 ) ) ;
V_509 -> V_511 = F_4 ( F_367 ( V_71 ) )
& ~ V_366 ;
V_509 -> V_512 = F_4 ( F_368 ( V_71 ) ) ;
V_509 -> V_510 = ( ( F_4 ( F_367 ( V_71 ) )
& V_366 ) >> V_676 ) + 1 ;
}
}
void F_430 ( struct V_64 * V_21 ,
struct V_418 * V_419 )
{
if ( V_21 -> V_67 . V_308 )
F_428 ( V_21 , & V_419 -> V_530 ) ;
else
F_429 ( V_21 , V_419 -> V_73 ,
& V_419 -> V_530 ) ;
}
static void F_431 ( struct V_64 * V_21 ,
struct V_418 * V_419 )
{
F_429 ( V_21 , V_419 -> V_73 ,
& V_419 -> V_472 ) ;
}
static void F_432 ( struct V_64 * V_21 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_589 ;
V_589 = F_4 ( F_181 ( V_21 -> V_71 ) ) ;
if ( V_589 & V_387 ) {
V_419 -> V_295 . V_99 = true ;
V_419 -> V_295 . V_389 = F_4 ( F_182 ( V_21 -> V_71 ) ) ;
V_419 -> V_295 . V_390 = F_4 ( F_183 ( V_21 -> V_71 ) ) ;
if ( F_433 ( V_2 ) ) {
F_2 ( ( V_589 & V_677 ) !=
F_248 ( V_21 -> V_71 ) ) ;
}
}
}
static bool F_434 ( struct V_64 * V_21 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_589 ;
V_419 -> V_73 = (enum V_70 ) V_21 -> V_71 ;
V_419 -> V_109 = V_382 ;
V_589 = F_4 ( F_45 ( V_21 -> V_71 ) ) ;
if ( ! ( V_589 & V_140 ) )
return false ;
switch ( V_589 & V_202 ) {
case V_601 :
V_419 -> V_471 = 18 ;
break;
case V_602 :
V_419 -> V_471 = 24 ;
break;
case V_603 :
V_419 -> V_471 = 30 ;
break;
case V_658 :
V_419 -> V_471 = 36 ;
break;
default:
break;
}
if ( F_4 ( F_91 ( V_21 -> V_71 ) ) & V_155 ) {
struct V_107 * V_111 ;
V_419 -> V_308 = true ;
V_589 = F_4 ( F_65 ( V_21 -> V_71 ) ) ;
V_419 -> V_318 = ( ( V_317 & V_589 ) >>
V_678 ) + 1 ;
F_431 ( V_21 , V_419 ) ;
if ( F_48 ( V_4 -> V_2 ) ) {
V_419 -> V_109 =
(enum V_383 ) V_21 -> V_71 ;
} else {
V_589 = F_4 ( V_369 ) ;
if ( V_589 & F_241 ( V_21 -> V_71 ) )
V_419 -> V_109 = V_370 ;
else
V_419 -> V_109 = V_679 ;
}
V_111 = & V_4 -> V_110 [ V_419 -> V_109 ] ;
F_2 ( ! V_111 -> V_114 ( V_4 , V_111 ,
& V_419 -> V_188 ) ) ;
V_589 = V_419 -> V_188 . V_47 ;
V_419 -> V_553 =
( ( V_589 & V_680 )
>> V_675 ) + 1 ;
F_435 ( V_21 , V_419 ) ;
} else {
V_419 -> V_553 = 1 ;
}
F_385 ( V_21 , V_419 ) ;
F_432 ( V_21 , V_419 ) ;
return true ;
}
static void F_436 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_681 * V_682 = & V_4 -> V_683 ;
struct V_64 * V_21 ;
unsigned long V_684 ;
T_4 V_101 ;
F_173 (crtc, &dev->mode_config.crtc_list, base.head)
F_46 ( V_21 -> V_65 , L_113 ,
F_69 ( V_21 -> V_71 ) ) ;
F_46 ( F_4 ( V_685 ) , L_114 ) ;
F_46 ( V_682 -> V_686 , L_115 ) ;
F_46 ( V_682 -> V_687 , L_116 ) ;
F_46 ( V_682 -> V_688 , L_117 ) ;
F_46 ( F_4 ( V_689 ) & V_690 , L_118 ) ;
F_46 ( F_4 ( V_691 ) & V_692 ,
L_119 ) ;
F_46 ( F_4 ( V_693 ) & V_692 ,
L_120 ) ;
F_46 ( F_4 ( V_694 ) & V_695 ,
L_121 ) ;
F_46 ( F_4 ( V_696 ) & V_697 ,
L_122 ) ;
F_46 ( F_4 ( V_698 ) & V_699 , L_123 ) ;
F_207 ( & V_4 -> V_700 , V_684 ) ;
V_101 = F_4 ( V_701 ) ;
F_46 ( ( V_101 | V_702 ) != 0xffffffff ,
L_124 , V_101 ) ;
V_101 = F_4 ( V_703 ) ;
F_46 ( ( V_101 | V_704 ) != 0xffffffff ,
L_125 , V_101 ) ;
F_208 ( & V_4 -> V_700 , V_684 ) ;
}
static void F_437 ( struct V_3 * V_4 ,
bool V_705 , bool V_706 )
{
T_4 V_101 ;
F_436 ( V_4 ) ;
V_101 = F_4 ( V_707 ) ;
if ( V_705 ) {
V_101 |= V_708 ;
F_40 ( V_707 , V_101 ) ;
if ( F_399 ( F_4 ( V_707 ) &
V_709 , 1 ) )
F_115 ( L_126 ) ;
V_101 = F_4 ( V_707 ) ;
}
V_101 |= V_710 ;
F_40 ( V_707 , V_101 ) ;
F_113 ( V_707 ) ;
if ( F_34 ( ( F_4 ( V_707 ) & V_711 ) == 0 , 1 ) )
F_115 ( L_127 ) ;
V_101 = F_4 ( V_712 ) ;
V_101 |= V_713 ;
F_53 ( & V_4 -> V_393 . V_394 ) ;
if ( F_254 ( V_4 , V_714 , V_101 ) )
F_115 ( L_128 ) ;
F_55 ( & V_4 -> V_393 . V_394 ) ;
F_113 ( V_712 ) ;
F_438 ( 100 ) ;
if ( F_34 ( ( F_4 ( V_712 ) & V_715 ) == 0 , 1 ) )
F_115 ( L_129 ) ;
if ( V_706 ) {
V_101 = F_4 ( V_707 ) ;
V_101 |= V_716 ;
F_40 ( V_707 , V_101 ) ;
F_113 ( V_707 ) ;
}
}
static void F_439 ( struct V_3 * V_4 )
{
T_4 V_101 ;
V_101 = F_4 ( V_707 ) ;
if ( ( V_101 & ( V_711 | V_710 | V_708 |
V_716 ) ) == V_711 )
return;
F_440 ( V_4 , V_717 ) ;
if ( V_101 & V_716 ) {
V_101 &= ~ V_716 ;
F_40 ( V_707 , V_101 ) ;
F_113 ( V_707 ) ;
}
V_101 = F_4 ( V_712 ) ;
V_101 |= V_718 ;
V_101 &= ~ V_713 ;
F_53 ( & V_4 -> V_393 . V_394 ) ;
if ( F_254 ( V_4 , V_714 , V_101 ) )
F_115 ( L_130 ) ;
F_55 ( & V_4 -> V_393 . V_394 ) ;
F_113 ( V_712 ) ;
V_101 = F_4 ( V_707 ) ;
V_101 &= ~ V_710 ;
F_40 ( V_707 , V_101 ) ;
if ( F_34 ( F_4 ( V_707 ) & V_711 , 5 ) )
F_115 ( L_131 ) ;
if ( V_101 & V_708 ) {
V_101 = F_4 ( V_707 ) ;
V_101 &= ~ V_708 ;
F_40 ( V_707 , V_101 ) ;
if ( F_399 ( ( F_4 ( V_707 ) &
V_709 ) == 0 , 1 ) )
F_115 ( L_132 ) ;
}
F_441 ( V_4 , V_717 ) ;
}
void F_442 ( struct V_719 * V_720 )
{
struct V_3 * V_4 =
F_443 ( F_444 ( V_720 ) , struct V_3 ,
V_721 . V_722 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_101 ;
F_2 ( ! F_445 ( V_2 ) ) ;
if ( V_4 -> V_721 . V_99 )
return;
F_36 ( L_133 ) ;
V_4 -> V_721 . V_99 = true ;
if ( V_4 -> V_650 == V_651 ) {
V_101 = F_4 ( V_723 ) ;
V_101 &= ~ V_724 ;
F_40 ( V_723 , V_101 ) ;
}
F_402 ( V_2 ) ;
F_446 ( V_2 ) ;
F_437 ( V_4 , true , true ) ;
F_447 ( V_4 ) ;
}
static void F_448 ( struct V_3 * V_4 )
{
F_2 ( ! F_449 ( & V_4 -> V_721 . V_725 ) ) ;
F_46 ( V_4 -> V_721 . V_726 < 1 ,
L_134 , V_4 -> V_721 . V_726 ) ;
V_4 -> V_721 . V_726 -- ;
if ( V_4 -> V_721 . V_726 != 0 )
return;
F_450 ( & V_4 -> V_721 . V_722 ,
F_451 ( V_727 ) ) ;
}
static void F_452 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_101 ;
F_2 ( ! F_449 ( & V_4 -> V_721 . V_725 ) ) ;
F_46 ( V_4 -> V_721 . V_726 < 0 ,
L_134 , V_4 -> V_721 . V_726 ) ;
V_4 -> V_721 . V_726 ++ ;
if ( V_4 -> V_721 . V_726 != 1 )
return;
F_2 ( ! F_445 ( V_2 ) ) ;
F_453 ( & V_4 -> V_721 . V_722 ) ;
if ( ! V_4 -> V_721 . V_99 )
return;
F_36 ( L_135 ) ;
F_454 ( V_4 ) ;
F_439 ( V_4 ) ;
F_455 ( V_2 ) ;
F_403 ( V_2 ) ;
if ( V_4 -> V_650 == V_651 ) {
V_101 = F_4 ( V_723 ) ;
V_101 |= V_724 ;
F_40 ( V_723 , V_101 ) ;
}
F_456 ( V_2 ) ;
F_457 ( V_2 ) ;
F_53 ( & V_4 -> V_393 . V_394 ) ;
F_458 ( V_2 ) ;
F_55 ( & V_4 -> V_393 . V_394 ) ;
V_4 -> V_721 . V_99 = false ;
}
void F_459 ( struct V_3 * V_4 )
{
if ( ! F_445 ( V_4 -> V_2 ) )
return;
F_53 ( & V_4 -> V_721 . V_725 ) ;
F_448 ( V_4 ) ;
F_55 ( & V_4 -> V_721 . V_725 ) ;
}
void F_460 ( struct V_3 * V_4 )
{
if ( ! F_445 ( V_4 -> V_2 ) )
return;
F_53 ( & V_4 -> V_721 . V_725 ) ;
F_452 ( V_4 ) ;
F_55 ( & V_4 -> V_721 . V_725 ) ;
}
static bool F_461 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_64 * V_21 ;
T_4 V_101 ;
F_173 (crtc, &dev->mode_config.crtc_list, base.head)
if ( V_21 -> V_108 . V_99 )
return false ;
V_101 = F_4 ( V_685 ) ;
if ( V_101 != 0 ) {
F_36 ( L_136 ) ;
return false ;
}
return true ;
}
static void F_462 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_728 ;
if ( ! F_445 ( V_4 -> V_2 ) )
return;
if ( ! V_729 )
return;
F_53 ( & V_4 -> V_721 . V_725 ) ;
V_728 = F_461 ( V_4 ) ;
if ( V_728 == V_4 -> V_721 . V_730 )
goto V_731;
V_4 -> V_721 . V_730 = V_728 ;
if ( V_728 )
F_448 ( V_4 ) ;
else
F_452 ( V_4 ) ;
V_731:
F_55 ( & V_4 -> V_721 . V_725 ) ;
}
static void F_463 ( struct V_3 * V_4 )
{
if ( ! F_445 ( V_4 -> V_2 ) )
return;
F_53 ( & V_4 -> V_721 . V_725 ) ;
if ( ! V_4 -> V_721 . V_732 ) {
V_4 -> V_721 . V_732 = true ;
F_448 ( V_4 ) ;
}
F_55 ( & V_4 -> V_721 . V_725 ) ;
}
static void F_464 ( struct V_3 * V_4 )
{
if ( ! F_445 ( V_4 -> V_2 ) )
return;
F_53 ( & V_4 -> V_721 . V_725 ) ;
if ( V_4 -> V_721 . V_732 ) {
V_4 -> V_721 . V_732 = false ;
F_452 ( V_4 ) ;
}
F_55 ( & V_4 -> V_721 . V_725 ) ;
}
static unsigned long F_465 ( struct V_1 * V_2 ,
enum V_71 V_71 , bool V_733 )
{
unsigned long V_734 ;
enum V_70 V_70 ;
V_70 = F_31 ( V_2 -> V_5 , V_71 ) ;
V_734 = F_466 ( F_467 ( V_71 ) ) ;
V_734 |= F_466 ( F_77 ( V_70 ) ) ;
if ( V_733 )
V_734 |= F_466 ( F_468 ( V_71 ) ) ;
return V_734 ;
}
void F_469 ( struct V_1 * V_2 , bool V_198 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_735 . V_736 == V_198 )
return;
if ( V_198 )
F_470 ( V_2 , V_737 ) ;
else
F_471 ( V_2 , V_737 ) ;
V_4 -> V_735 . V_736 = V_198 ;
}
static void F_472 ( struct V_1 * V_2 )
{
unsigned long V_738 [ V_739 ] = { 0 , } ;
struct V_64 * V_21 ;
F_173 (crtc, &dev->mode_config.crtc_list, base.head) {
enum V_740 V_741 ;
if ( ! V_21 -> V_108 . V_99 )
continue;
V_738 [ V_21 -> V_71 ] = F_465 ( V_2 ,
V_21 -> V_71 ,
V_21 -> V_67 . V_295 . V_99 ) ;
F_473 (domain, pipe_domains[crtc->pipe])
F_470 ( V_2 , V_741 ) ;
}
F_173 (crtc, &dev->mode_config.crtc_list, base.head) {
enum V_740 V_741 ;
F_473 (domain, crtc->enabled_power_domains)
F_471 ( V_2 , V_741 ) ;
V_21 -> V_742 = V_738 [ V_21 -> V_71 ] ;
}
F_469 ( V_2 , false ) ;
}
static void F_474 ( struct V_1 * V_2 )
{
F_472 ( V_2 ) ;
F_462 ( V_2 ) ;
}
static int F_475 ( struct V_20 * V_21 ,
int V_234 , int V_235 ,
struct V_241 * V_66 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_141 = V_64 -> V_141 ;
int V_224 ;
if ( ! F_476 ( V_64 ) )
return - V_229 ;
F_477 ( V_64 ) ;
if ( V_64 -> V_67 . V_555 )
F_371 ( V_64 ) ;
V_64 -> V_525 = false ;
F_384 ( V_64 ) ;
if ( V_64 -> V_67 . V_308 ) {
F_363 ( V_64 ,
& V_64 -> V_67 . V_472 ) ;
}
F_421 ( V_21 ) ;
F_407 ( V_21 ) ;
F_40 ( F_79 ( V_141 ) , V_617 | V_743 ) ;
F_113 ( F_79 ( V_141 ) ) ;
V_224 = F_179 ( V_21 , V_234 , V_235 , V_66 ) ;
return V_224 ;
}
static bool F_478 ( struct V_64 * V_21 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_740 V_744 ;
T_4 V_589 ;
V_419 -> V_73 = (enum V_70 ) V_21 -> V_71 ;
V_419 -> V_109 = V_382 ;
V_589 = F_4 ( F_62 ( V_588 ) ) ;
if ( V_589 & V_116 ) {
enum V_71 V_745 ;
switch ( V_589 & V_746 ) {
default:
F_46 ( 1 , L_137 ) ;
case V_747 :
case V_748 :
V_745 = V_125 ;
break;
case V_749 :
V_745 = V_134 ;
break;
case V_750 :
V_745 = V_311 ;
break;
}
if ( V_745 == V_21 -> V_71 )
V_419 -> V_73 = V_588 ;
}
if ( ! F_76 ( V_2 ,
F_77 ( V_419 -> V_73 ) ) )
return false ;
V_589 = F_4 ( F_45 ( V_419 -> V_73 ) ) ;
if ( ! ( V_589 & V_140 ) )
return false ;
V_589 = F_4 ( F_62 ( V_419 -> V_73 ) ) ;
if ( ( V_589 & V_751 ) == F_479 ( V_752 ) &&
F_4 ( V_213 ) & V_155 ) {
V_419 -> V_308 = true ;
V_589 = F_4 ( F_65 ( V_125 ) ) ;
V_419 -> V_318 = ( ( V_317 & V_589 ) >>
V_678 ) + 1 ;
F_431 ( V_21 , V_419 ) ;
}
F_385 ( V_21 , V_419 ) ;
V_744 = F_468 ( V_21 -> V_71 ) ;
if ( F_76 ( V_2 , V_744 ) )
F_432 ( V_21 , V_419 ) ;
if ( F_167 ( V_2 ) )
V_419 -> V_392 = F_265 ( V_21 ) &&
( F_4 ( V_396 ) & V_397 ) ;
V_419 -> V_553 = 1 ;
return true ;
}
static int F_480 ( struct V_20 * V_21 ,
int V_234 , int V_235 ,
struct V_241 * V_66 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_23 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_292 * V_377 = & V_64 -> V_67 . V_590 ;
int V_71 = V_64 -> V_71 ;
int V_224 ;
F_481 ( V_2 , V_71 ) ;
V_224 = V_4 -> V_273 . V_753 ( V_21 , V_234 , V_235 , V_66 ) ;
F_482 ( V_2 , V_71 ) ;
if ( V_224 != 0 )
return V_224 ;
F_10 (dev, crtc, encoder) {
F_36 ( L_138 ,
V_23 -> V_108 . V_108 . V_197 ,
F_483 ( & V_23 -> V_108 ) ,
V_377 -> V_108 . V_197 , V_377 -> V_115 ) ;
V_23 -> V_385 ( V_23 ) ;
}
return 0 ;
}
static T_1 F_484 ( struct V_292 * V_377 )
{
int V_143 ;
for ( V_143 = 0 ; V_143 < F_200 ( V_754 ) ; V_143 ++ ) {
if ( V_377 -> clock == V_754 [ V_143 ] . clock )
break;
}
if ( V_143 == F_200 ( V_754 ) ) {
F_36 ( L_139 , V_377 -> clock ) ;
V_143 = 1 ;
}
F_36 ( L_140 ,
V_754 [ V_143 ] . clock ,
V_754 [ V_143 ] . V_67 ) ;
return V_754 [ V_143 ] . V_67 ;
}
static bool F_485 ( struct V_456 * V_457 ,
int V_755 , T_4 V_756 ,
int V_757 , T_4 V_758 ,
int V_759 )
{
struct V_3 * V_4 = V_457 -> V_2 -> V_5 ;
T_7 * V_760 = V_457 -> V_760 ;
T_4 V_143 ;
V_143 = F_4 ( V_755 ) ;
V_143 &= V_756 ;
if ( ! V_760 [ 0 ] )
return ! V_143 ;
if ( ! V_143 )
return false ;
V_143 = F_4 ( V_757 ) ;
V_143 &= ~ V_758 ;
F_40 ( V_757 , V_143 ) ;
for ( V_143 = 0 ; V_143 < V_760 [ 2 ] ; V_143 ++ )
if ( F_4 ( V_759 ) != * ( ( T_4 * ) V_760 + V_143 ) )
return false ;
return true ;
}
static void F_486 ( struct V_456 * V_457 ,
struct V_20 * V_21 ,
struct V_292 * V_377 )
{
struct V_3 * V_4 = V_457 -> V_2 -> V_5 ;
T_7 * V_760 = V_457 -> V_760 ;
T_4 V_761 ;
T_4 V_762 ;
T_4 V_143 ;
V_143 = F_4 ( V_763 ) ;
if ( V_143 == V_764 || V_143 == V_765 )
V_761 = V_766 ;
else
V_761 = V_767 ;
if ( F_485 ( V_457 ,
V_768 , V_761 ,
V_768 , V_769 ,
V_770 ) )
return;
V_143 = F_4 ( V_768 ) ;
V_143 &= ~ ( V_761 | V_769 ) ;
V_762 = ( V_143 >> 9 ) & 0x1f ;
F_40 ( V_768 , V_143 ) ;
if ( ! V_760 [ 0 ] )
return;
V_762 = F_345 ( T_7 , V_760 [ 2 ] , V_762 ) ;
F_59 ( L_141 , V_762 ) ;
for ( V_143 = 0 ; V_143 < V_762 ; V_143 ++ )
F_40 ( V_770 , * ( ( T_4 * ) V_760 + V_143 ) ) ;
V_143 = F_4 ( V_768 ) ;
V_143 |= V_761 ;
F_40 ( V_768 , V_143 ) ;
}
static void F_487 ( struct V_456 * V_457 ,
struct V_20 * V_21 ,
struct V_292 * V_377 )
{
struct V_3 * V_4 = V_457 -> V_2 -> V_5 ;
T_7 * V_760 = V_457 -> V_760 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
T_4 V_761 ;
T_4 V_143 ;
int V_762 ;
int V_71 = F_30 ( V_21 ) -> V_71 ;
int V_589 ;
int V_771 = F_488 ( V_71 ) ;
int V_772 = F_489 ( V_71 ) ;
int V_773 = F_490 ( V_71 ) ;
int V_774 = V_775 ;
F_59 ( L_142 ) ;
F_59 ( L_143 ) ;
V_589 = F_4 ( V_774 ) ;
V_589 |= ( V_776 << ( V_71 * 4 ) ) ;
F_40 ( V_774 , V_589 ) ;
F_37 ( V_2 , V_71 ) ;
V_589 = F_4 ( V_774 ) ;
F_59 ( L_144 , V_589 ) ;
V_589 |= ( V_777 << ( V_71 * 4 ) ) ;
F_40 ( V_774 , V_589 ) ;
V_589 = F_4 ( V_774 ) ;
F_59 ( L_145 , V_589 ) ;
V_589 = F_4 ( V_773 ) ;
F_59 ( L_146 , V_589 ) ;
V_589 &= ~ ( V_778 | V_779 ) ;
F_40 ( V_773 , V_589 ) ;
F_59 ( L_147 , F_69 ( V_71 ) ) ;
V_761 = V_777 << ( V_71 * 4 ) ;
V_64 -> V_458 = true ;
if ( F_9 ( V_21 , V_371 ) ) {
F_59 ( L_148 ) ;
V_760 [ 5 ] |= ( 1 << 2 ) ;
F_40 ( V_773 , V_778 ) ;
} else {
F_40 ( V_773 , F_484 ( V_377 ) ) ;
}
if ( F_485 ( V_457 ,
V_774 , V_761 ,
V_772 , V_780 ,
V_771 ) )
return;
V_143 = F_4 ( V_774 ) ;
V_143 &= ~ V_761 ;
F_40 ( V_774 , V_143 ) ;
if ( ! V_760 [ 0 ] )
return;
V_143 = F_4 ( V_772 ) ;
V_143 &= ~ V_780 ;
F_40 ( V_772 , V_143 ) ;
V_143 = ( V_143 >> 29 ) & V_781 ;
F_59 ( L_149 , V_143 ) ;
V_762 = F_345 ( T_7 , V_760 [ 2 ] , 21 ) ;
F_59 ( L_141 , V_762 ) ;
for ( V_143 = 0 ; V_143 < V_762 ; V_143 ++ )
F_40 ( V_771 , * ( ( T_4 * ) V_760 + V_143 ) ) ;
V_143 = F_4 ( V_774 ) ;
V_143 |= V_761 ;
F_40 ( V_774 , V_143 ) ;
}
static void F_491 ( struct V_456 * V_457 ,
struct V_20 * V_21 ,
struct V_292 * V_377 )
{
struct V_3 * V_4 = V_457 -> V_2 -> V_5 ;
T_7 * V_760 = V_457 -> V_760 ;
T_4 V_761 ;
T_4 V_143 ;
int V_762 ;
int V_771 ;
int V_773 ;
int V_772 ;
int V_774 ;
int V_71 = F_30 ( V_21 ) -> V_71 ;
if ( F_48 ( V_457 -> V_2 ) ) {
V_771 = F_492 ( V_71 ) ;
V_773 = F_493 ( V_71 ) ;
V_772 = F_494 ( V_71 ) ;
V_774 = V_782 ;
} else if ( F_17 ( V_457 -> V_2 ) ) {
V_771 = F_495 ( V_71 ) ;
V_773 = F_496 ( V_71 ) ;
V_772 = F_497 ( V_71 ) ;
V_774 = V_783 ;
} else {
V_771 = F_498 ( V_71 ) ;
V_773 = F_499 ( V_71 ) ;
V_772 = F_500 ( V_71 ) ;
V_774 = V_784 ;
}
F_59 ( L_147 , F_69 ( V_71 ) ) ;
if ( F_17 ( V_457 -> V_2 ) ) {
struct V_22 * V_22 ;
struct V_86 * V_785 ;
V_22 = F_501 ( V_457 ) ;
V_785 = F_397 ( & V_22 -> V_108 ) ;
V_143 = V_785 -> V_87 ;
} else {
V_143 = F_4 ( V_772 ) ;
V_143 = ( V_143 >> 29 ) & V_781 ;
}
if ( ! V_143 ) {
F_59 ( L_150 ) ;
V_761 = V_786 ;
V_761 |= V_786 << 4 ;
V_761 |= V_786 << 8 ;
} else {
F_59 ( L_151 , F_122 ( V_143 ) ) ;
V_761 = V_786 << ( ( V_143 - 1 ) * 4 ) ;
}
if ( F_9 ( V_21 , V_371 ) ) {
F_59 ( L_148 ) ;
V_760 [ 5 ] |= ( 1 << 2 ) ;
F_40 ( V_773 , V_778 ) ;
} else {
F_40 ( V_773 , F_484 ( V_377 ) ) ;
}
if ( F_485 ( V_457 ,
V_774 , V_761 ,
V_772 , V_780 ,
V_771 ) )
return;
V_143 = F_4 ( V_774 ) ;
V_143 &= ~ V_761 ;
F_40 ( V_774 , V_143 ) ;
if ( ! V_760 [ 0 ] )
return;
V_143 = F_4 ( V_772 ) ;
V_143 &= ~ V_780 ;
F_40 ( V_772 , V_143 ) ;
V_762 = F_345 ( T_7 , V_760 [ 2 ] , 21 ) ;
F_59 ( L_141 , V_762 ) ;
for ( V_143 = 0 ; V_143 < V_762 ; V_143 ++ )
F_40 ( V_771 , * ( ( T_4 * ) V_760 + V_143 ) ) ;
V_143 = F_4 ( V_774 ) ;
V_143 |= V_761 ;
F_40 ( V_774 , V_143 ) ;
}
void F_502 ( struct V_462 * V_23 ,
struct V_292 * V_377 )
{
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_456 * V_457 ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_457 = F_503 ( V_23 , V_377 ) ;
if ( ! V_457 )
return;
F_59 ( L_152 ,
V_457 -> V_108 . V_197 ,
F_320 ( V_457 ) ,
V_457 -> V_23 -> V_108 . V_197 ,
F_483 ( V_457 -> V_23 ) ) ;
V_457 -> V_760 [ 6 ] = F_504 ( V_457 , V_377 ) / 2 ;
if ( V_4 -> V_273 . V_787 )
V_4 -> V_273 . V_787 ( V_457 , V_21 , V_377 ) ;
}
static void F_505 ( struct V_20 * V_21 , T_1 V_108 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
bool V_788 = V_108 != 0 ;
T_1 V_413 ;
if ( V_64 -> V_789 == V_788 )
return;
V_413 = F_4 ( V_135 ) ;
if ( V_788 ) {
F_40 ( V_790 , V_108 ) ;
V_413 &= ~ ( V_791 ) ;
V_413 |= V_136 |
V_792 |
V_793 ;
} else
V_413 &= ~ ( V_136 | V_792 ) ;
F_40 ( V_135 , V_413 ) ;
V_64 -> V_789 = V_788 ;
}
static void F_506 ( struct V_20 * V_21 , T_1 V_108 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
bool V_788 = V_108 != 0 ;
if ( V_64 -> V_789 != V_788 ) {
T_4 V_413 = F_4 ( F_73 ( V_71 ) ) ;
if ( V_108 ) {
V_413 &= ~ ( V_137 | V_794 ) ;
V_413 |= V_417 | V_795 ;
V_413 |= V_71 << 28 ;
} else {
V_413 &= ~ ( V_137 | V_795 ) ;
V_413 |= V_796 ;
}
F_40 ( F_73 ( V_71 ) , V_413 ) ;
V_64 -> V_789 = V_788 ;
}
F_113 ( F_73 ( V_71 ) ) ;
F_40 ( F_289 ( V_71 ) , V_108 ) ;
F_113 ( F_289 ( V_71 ) ) ;
}
static void F_507 ( struct V_20 * V_21 , T_1 V_108 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
bool V_788 = V_108 != 0 ;
if ( V_64 -> V_789 != V_788 ) {
T_4 V_413 = F_4 ( F_74 ( V_71 ) ) ;
if ( V_108 ) {
V_413 &= ~ V_137 ;
V_413 |= V_417 | V_795 ;
} else {
V_413 &= ~ ( V_137 | V_795 ) ;
V_413 |= V_796 ;
}
if ( F_167 ( V_2 ) || F_168 ( V_2 ) ) {
V_413 |= V_797 ;
V_413 &= ~ V_798 ;
}
F_40 ( F_74 ( V_71 ) , V_413 ) ;
V_64 -> V_789 = V_788 ;
}
F_113 ( F_74 ( V_71 ) ) ;
F_40 ( F_508 ( V_71 ) , V_108 ) ;
F_113 ( F_508 ( V_71 ) ) ;
}
static void F_264 ( struct V_20 * V_21 ,
bool V_196 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
int V_234 = V_64 -> V_799 ;
int V_235 = V_64 -> V_800 ;
T_1 V_108 = 0 , V_389 = 0 ;
bool V_788 ;
if ( V_196 )
V_108 = V_64 -> V_801 ;
if ( V_234 >= V_64 -> V_67 . V_297 )
V_108 = 0 ;
if ( V_235 >= V_64 -> V_67 . V_298 )
V_108 = 0 ;
if ( V_234 < 0 ) {
if ( V_234 + V_64 -> V_802 <= 0 )
V_108 = 0 ;
V_389 |= V_803 << V_804 ;
V_234 = - V_234 ;
}
V_389 |= V_234 << V_804 ;
if ( V_235 < 0 ) {
if ( V_235 + V_64 -> V_805 <= 0 )
V_108 = 0 ;
V_389 |= V_803 << V_806 ;
V_235 = - V_235 ;
}
V_389 |= V_235 << V_806 ;
V_788 = V_108 != 0 ;
if ( ! V_788 && ! V_64 -> V_789 )
return;
if ( F_187 ( V_2 ) || F_167 ( V_2 ) || F_168 ( V_2 ) ) {
F_40 ( F_509 ( V_71 ) , V_389 ) ;
F_507 ( V_21 , V_108 ) ;
} else {
F_40 ( F_510 ( V_71 ) , V_389 ) ;
if ( F_71 ( V_2 ) || F_72 ( V_2 ) )
F_505 ( V_21 , V_108 ) ;
else
F_506 ( V_21 , V_108 ) ;
}
}
static int F_511 ( struct V_20 * V_21 ,
struct V_807 * V_808 ,
T_4 V_809 ,
T_4 V_810 , T_4 V_811 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_219 * V_220 ;
T_4 V_812 ;
int V_224 ;
if ( ! V_809 ) {
F_36 ( L_153 ) ;
V_812 = 0 ;
V_220 = NULL ;
F_53 ( & V_2 -> V_290 ) ;
goto V_813;
}
if ( V_810 != 64 || V_811 != 64 ) {
F_115 ( L_154 ) ;
return - V_229 ;
}
V_220 = F_512 ( F_513 ( V_2 , V_808 , V_809 ) ) ;
if ( & V_220 -> V_108 == NULL )
return - V_814 ;
if ( V_220 -> V_108 . V_390 < V_810 * V_811 * 4 ) {
F_115 ( L_155 ) ;
V_224 = - V_815 ;
goto V_816;
}
F_53 ( & V_2 -> V_290 ) ;
if ( ! V_4 -> V_119 -> V_817 ) {
unsigned V_223 ;
if ( V_220 -> V_225 ) {
F_115 ( L_156 ) ;
V_224 = - V_229 ;
goto V_818;
}
V_223 = 0 ;
if ( F_148 ( V_2 ) )
V_223 = 64 * 1024 ;
V_224 = F_153 ( V_220 , V_223 , NULL ) ;
if ( V_224 ) {
F_115 ( L_157 ) ;
goto V_818;
}
V_224 = F_514 ( V_220 ) ;
if ( V_224 ) {
F_115 ( L_158 ) ;
goto V_819;
}
V_812 = F_162 ( V_220 ) ;
} else {
int V_820 = F_112 ( V_2 ) ? 16 * 1024 : 256 ;
V_224 = F_515 ( V_2 , V_220 ,
( V_64 -> V_71 == 0 ) ? V_821 : V_822 ,
V_820 ) ;
if ( V_224 ) {
F_115 ( L_159 ) ;
goto V_818;
}
V_812 = V_220 -> V_823 -> V_809 -> V_824 ;
}
if ( F_18 ( V_2 ) )
F_40 ( V_825 , ( V_811 << 12 ) | V_810 ) ;
V_813:
if ( V_64 -> V_826 ) {
if ( V_4 -> V_119 -> V_817 ) {
if ( V_64 -> V_826 != V_220 )
F_516 ( V_2 , V_64 -> V_826 ) ;
} else
F_156 ( V_64 -> V_826 ) ;
F_517 ( & V_64 -> V_826 -> V_108 ) ;
}
F_55 ( & V_2 -> V_290 ) ;
V_64 -> V_801 = V_812 ;
V_64 -> V_826 = V_220 ;
V_64 -> V_802 = V_810 ;
V_64 -> V_805 = V_811 ;
if ( V_64 -> V_65 )
F_264 ( V_21 , V_64 -> V_826 != NULL ) ;
return 0 ;
V_819:
F_156 ( V_220 ) ;
V_818:
F_55 ( & V_2 -> V_290 ) ;
V_816:
F_518 ( & V_220 -> V_108 ) ;
return V_224 ;
}
static int F_519 ( struct V_20 * V_21 , int V_234 , int V_235 )
{
struct V_64 * V_64 = F_30 ( V_21 ) ;
V_64 -> V_799 = F_520 ( int , V_234 , V_827 , V_828 ) ;
V_64 -> V_800 = F_520 ( int , V_235 , V_827 , V_828 ) ;
if ( V_64 -> V_65 )
F_264 ( V_21 , V_64 -> V_826 != NULL ) ;
return 0 ;
}
static void F_521 ( struct V_20 * V_21 , T_5 * V_829 , T_5 * V_830 ,
T_5 * V_831 , T_4 V_832 , T_4 V_390 )
{
int V_833 = ( V_832 + V_390 > 256 ) ? 256 : V_832 + V_390 , V_143 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
for ( V_143 = V_832 ; V_143 < V_833 ; V_143 ++ ) {
V_64 -> V_403 [ V_143 ] = V_829 [ V_143 ] >> 8 ;
V_64 -> V_404 [ V_143 ] = V_830 [ V_143 ] >> 8 ;
V_64 -> V_405 [ V_143 ] = V_831 [ V_143 ] >> 8 ;
}
F_256 ( V_21 ) ;
}
static struct V_241 *
F_522 ( struct V_1 * V_2 ,
struct V_834 * V_835 ,
struct V_219 * V_220 )
{
struct V_242 * V_243 ;
int V_224 ;
V_243 = F_523 ( sizeof( * V_243 ) , V_836 ) ;
if ( ! V_243 ) {
F_518 ( & V_220 -> V_108 ) ;
return F_524 ( - V_815 ) ;
}
V_224 = F_525 ( V_2 ) ;
if ( V_224 )
goto V_53;
V_224 = F_526 ( V_2 , V_243 , V_835 , V_220 ) ;
F_55 ( & V_2 -> V_290 ) ;
if ( V_224 )
goto V_53;
return & V_243 -> V_108 ;
V_53:
F_518 ( & V_220 -> V_108 ) ;
F_317 ( V_243 ) ;
return F_524 ( V_224 ) ;
}
static T_1
F_527 ( int V_810 , int V_671 )
{
T_1 V_237 = F_528 ( V_810 * V_671 , 8 ) ;
return F_529 ( V_237 , 64 ) ;
}
static T_1
F_530 ( struct V_292 * V_377 , int V_671 )
{
T_1 V_237 = F_527 ( V_377 -> V_448 , V_671 ) ;
return F_529 ( V_237 * V_377 -> V_450 , V_837 ) ;
}
static struct V_241 *
F_531 ( struct V_1 * V_2 ,
struct V_292 * V_377 ,
int V_838 , int V_671 )
{
struct V_219 * V_220 ;
struct V_834 V_835 = { 0 } ;
V_220 = F_532 ( V_2 ,
F_530 ( V_377 , V_671 ) ) ;
if ( V_220 == NULL )
return F_524 ( - V_815 ) ;
V_835 . V_810 = V_377 -> V_448 ;
V_835 . V_811 = V_377 -> V_450 ;
V_835 . V_269 [ 0 ] = F_527 ( V_835 . V_810 ,
V_671 ) ;
V_835 . V_247 = F_533 ( V_671 , V_838 ) ;
return F_522 ( V_2 , & V_835 , V_220 ) ;
}
static struct V_241 *
F_534 ( struct V_1 * V_2 ,
struct V_292 * V_377 )
{
#ifdef F_535
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_219 * V_220 ;
struct V_241 * V_66 ;
if ( V_4 -> V_839 == NULL )
return NULL ;
V_220 = V_4 -> V_839 -> V_840 . V_220 ;
if ( V_220 == NULL )
return NULL ;
V_66 = & V_4 -> V_839 -> V_840 . V_108 ;
if ( V_66 -> V_269 [ 0 ] < F_527 ( V_377 -> V_448 ,
V_66 -> V_270 ) )
return NULL ;
if ( V_220 -> V_108 . V_390 < V_377 -> V_450 * V_66 -> V_269 [ 0 ] )
return NULL ;
return V_66 ;
#else
return NULL ;
#endif
}
bool F_536 ( struct V_456 * V_457 ,
struct V_292 * V_377 ,
struct V_841 * V_842 )
{
struct V_64 * V_64 ;
struct V_22 * V_22 =
F_501 ( V_457 ) ;
struct V_20 * V_843 ;
struct V_462 * V_23 = & V_22 -> V_108 ;
struct V_20 * V_21 = NULL ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_241 * V_66 ;
int V_143 = - 1 ;
F_36 ( L_160 ,
V_457 -> V_108 . V_197 , F_320 ( V_457 ) ,
V_23 -> V_108 . V_197 , F_483 ( V_23 ) ) ;
if ( V_23 -> V_21 ) {
V_21 = V_23 -> V_21 ;
F_53 ( & V_21 -> V_276 ) ;
V_842 -> V_844 = V_457 -> V_460 ;
V_842 -> V_845 = false ;
if ( V_457 -> V_460 != V_463 )
V_457 -> V_846 -> V_460 ( V_457 , V_463 ) ;
return true ;
}
F_173 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_143 ++ ;
if ( ! ( V_23 -> V_847 & ( 1 << V_143 ) ) )
continue;
if ( ! V_843 -> V_99 ) {
V_21 = V_843 ;
break;
}
}
if ( ! V_21 ) {
F_36 ( L_161 ) ;
return false ;
}
F_53 ( & V_21 -> V_276 ) ;
V_22 -> V_848 = F_30 ( V_21 ) ;
F_537 ( V_457 ) -> V_849 = V_22 ;
V_64 = F_30 ( V_21 ) ;
V_842 -> V_844 = V_457 -> V_460 ;
V_842 -> V_845 = true ;
V_842 -> V_850 = NULL ;
if ( ! V_377 )
V_377 = & V_851 ;
V_66 = F_534 ( V_2 , V_377 ) ;
if ( V_66 == NULL ) {
F_36 ( L_162 ) ;
V_66 = F_531 ( V_2 , V_377 , 24 , 32 ) ;
V_842 -> V_850 = V_66 ;
} else
F_36 ( L_163 ) ;
if ( F_538 ( V_66 ) ) {
F_36 ( L_164 ) ;
F_55 ( & V_21 -> V_276 ) ;
return false ;
}
if ( F_539 ( V_21 , V_377 , 0 , 0 , V_66 ) ) {
F_36 ( L_165 ) ;
if ( V_842 -> V_850 )
V_842 -> V_850 -> V_846 -> V_852 ( V_842 -> V_850 ) ;
F_55 ( & V_21 -> V_276 ) ;
return false ;
}
F_37 ( V_2 , V_64 -> V_71 ) ;
return true ;
}
void F_540 ( struct V_456 * V_457 ,
struct V_841 * V_842 )
{
struct V_22 * V_22 =
F_501 ( V_457 ) ;
struct V_462 * V_23 = & V_22 -> V_108 ;
struct V_20 * V_21 = V_23 -> V_21 ;
F_36 ( L_160 ,
V_457 -> V_108 . V_197 , F_320 ( V_457 ) ,
V_23 -> V_108 . V_197 , F_483 ( V_23 ) ) ;
if ( V_842 -> V_845 ) {
F_537 ( V_457 ) -> V_849 = NULL ;
V_22 -> V_848 = NULL ;
F_539 ( V_21 , NULL , 0 , 0 , NULL ) ;
if ( V_842 -> V_850 ) {
F_541 ( V_842 -> V_850 ) ;
F_542 ( V_842 -> V_850 ) ;
}
F_55 ( & V_21 -> V_276 ) ;
return;
}
if ( V_842 -> V_844 != V_463 )
V_457 -> V_846 -> V_460 ( V_457 , V_842 -> V_844 ) ;
F_55 ( & V_21 -> V_276 ) ;
}
static int F_543 ( struct V_1 * V_2 ,
const struct V_418 * V_419 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_47 = V_419 -> V_188 . V_47 ;
if ( ( V_47 & V_853 ) == V_571 )
return V_4 -> V_516 . V_520 ;
else if ( F_3 ( V_2 ) )
return 120000 ;
else if ( ! F_18 ( V_2 ) )
return 96000 ;
else
return 48000 ;
}
static void F_395 ( struct V_64 * V_21 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_71 = V_419 -> V_73 ;
T_1 V_47 = V_419 -> V_188 . V_47 ;
T_1 V_522 ;
T_2 clock ;
int V_10 = F_543 ( V_2 , V_419 ) ;
if ( ( V_47 & V_854 ) == 0 )
V_522 = V_419 -> V_188 . V_524 ;
else
V_522 = V_419 -> V_188 . V_527 ;
clock . V_12 = ( V_522 & V_855 ) >> V_856 ;
if ( F_16 ( V_2 ) ) {
clock . V_17 = F_544 ( ( V_522 & V_857 ) >> V_858 ) - 1 ;
clock . V_13 = ( V_522 & V_859 ) >> V_860 ;
} else {
clock . V_17 = ( V_522 & V_861 ) >> V_858 ;
clock . V_13 = ( V_522 & V_862 ) >> V_860 ;
}
if ( ! F_18 ( V_2 ) ) {
if ( F_16 ( V_2 ) )
clock . V_15 = F_544 ( ( V_47 & V_863 ) >>
V_561 ) ;
else
clock . V_15 = F_544 ( ( V_47 & V_864 ) >>
V_562 ) ;
switch ( V_47 & V_865 ) {
case V_558 :
clock . V_16 = V_47 & V_564 ?
5 : 10 ;
break;
case V_557 :
clock . V_16 = V_47 & V_565 ?
7 : 14 ;
break;
default:
F_36 ( L_166
L_167 , ( int ) ( V_47 & V_865 ) ) ;
return;
}
if ( F_16 ( V_2 ) )
F_19 ( V_10 , & clock ) ;
else
F_21 ( V_10 , & clock ) ;
} else {
T_1 V_866 = F_112 ( V_2 ) ? 0 : F_4 ( V_130 ) ;
bool V_611 = ( V_71 == 1 ) && ( V_866 & V_165 ) ;
if ( V_611 ) {
clock . V_15 = F_544 ( ( V_47 & V_867 ) >>
V_562 ) ;
if ( V_866 & V_868 )
clock . V_16 = 7 ;
else
clock . V_16 = 14 ;
} else {
if ( V_47 & V_573 )
clock . V_15 = 2 ;
else {
clock . V_15 = ( ( V_47 & V_869 ) >>
V_562 ) + 2 ;
}
if ( V_47 & V_574 )
clock . V_16 = 4 ;
else
clock . V_16 = 2 ;
}
F_21 ( V_10 , & clock ) ;
}
V_419 -> V_549 = clock . V_19 ;
}
int F_545 ( int V_870 ,
const struct V_508 * V_509 )
{
if ( ! V_509 -> V_514 )
return 0 ;
return F_28 ( ( V_871 ) V_509 -> V_513 * V_870 , V_509 -> V_514 ) ;
}
static void F_435 ( struct V_64 * V_21 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
F_395 ( V_21 , V_419 ) ;
V_419 -> V_68 . V_69 =
F_545 ( F_5 ( V_2 ) * 10000 ,
& V_419 -> V_472 ) ;
}
struct V_292 * F_546 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_70 V_73 = V_64 -> V_67 . V_73 ;
struct V_292 * V_377 ;
struct V_418 V_419 ;
int V_872 = F_4 ( F_222 ( V_73 ) ) ;
int V_873 = F_4 ( F_226 ( V_73 ) ) ;
int V_874 = F_4 ( F_228 ( V_73 ) ) ;
int V_875 = F_4 ( F_232 ( V_73 ) ) ;
enum V_71 V_71 = V_64 -> V_71 ;
V_377 = F_523 ( sizeof( * V_377 ) , V_836 ) ;
if ( ! V_377 )
return NULL ;
V_419 . V_73 = (enum V_70 ) V_71 ;
V_419 . V_553 = 1 ;
V_419 . V_188 . V_47 = F_4 ( F_51 ( V_71 ) ) ;
V_419 . V_188 . V_524 = F_4 ( F_351 ( V_71 ) ) ;
V_419 . V_188 . V_527 = F_4 ( F_352 ( V_71 ) ) ;
F_395 ( V_64 , & V_419 ) ;
V_377 -> clock = V_419 . V_549 / V_419 . V_553 ;
V_377 -> V_448 = ( V_872 & 0xffff ) + 1 ;
V_377 -> V_591 = ( ( V_872 & 0xffff0000 ) >> 16 ) + 1 ;
V_377 -> V_479 = ( V_873 & 0xffff ) + 1 ;
V_377 -> V_592 = ( ( V_873 & 0xffff0000 ) >> 16 ) + 1 ;
V_377 -> V_450 = ( V_874 & 0xffff ) + 1 ;
V_377 -> V_593 = ( ( V_874 & 0xffff0000 ) >> 16 ) + 1 ;
V_377 -> V_594 = ( V_875 & 0xffff ) + 1 ;
V_377 -> V_595 = ( ( V_875 & 0xffff0000 ) >> 16 ) + 1 ;
F_547 ( V_377 ) ;
return V_377 ;
}
static void F_171 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_8 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_71 = V_64 -> V_71 ;
int V_876 = F_51 ( V_71 ) ;
int V_47 ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_615 )
return;
V_47 = F_4 ( V_876 ) ;
if ( ! F_388 ( V_2 ) && ( V_47 & V_854 ) ) {
F_59 ( L_168 ) ;
F_68 ( V_4 , V_71 ) ;
V_47 &= ~ V_854 ;
F_40 ( V_876 , V_47 ) ;
F_37 ( V_2 , V_71 ) ;
V_47 = F_4 ( V_876 ) ;
if ( V_47 & V_854 )
F_59 ( L_169 ) ;
}
}
static void F_548 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_8 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_615 )
return;
if ( ! F_388 ( V_2 ) && V_64 -> V_525 ) {
int V_71 = V_64 -> V_71 ;
int V_876 = F_51 ( V_71 ) ;
int V_47 ;
F_59 ( L_170 ) ;
F_68 ( V_4 , V_71 ) ;
V_47 = F_4 ( V_876 ) ;
V_47 |= V_854 ;
F_40 ( V_876 , V_47 ) ;
F_37 ( V_2 , V_71 ) ;
V_47 = F_4 ( V_876 ) ;
if ( ! ( V_47 & V_854 ) )
F_59 ( L_171 ) ;
}
}
void F_549 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_464 ( V_4 ) ;
F_550 ( V_4 ) ;
}
void F_551 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 ;
F_463 ( V_4 ) ;
if ( ! V_526 )
return;
F_173 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_21 -> V_66 )
continue;
F_548 ( V_21 ) ;
}
if ( V_4 -> V_119 -> V_77 >= 6 )
F_552 ( V_2 -> V_5 ) ;
}
void F_553 ( struct V_219 * V_220 ,
struct V_221 * V_877 )
{
struct V_1 * V_2 = V_220 -> V_108 . V_2 ;
struct V_20 * V_21 ;
if ( ! V_526 )
return;
F_173 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_21 -> V_66 )
continue;
if ( F_161 ( V_21 -> V_66 ) -> V_220 != V_220 )
continue;
F_171 ( V_21 ) ;
if ( V_877 && F_554 ( V_2 ) )
V_877 -> V_878 = true ;
}
}
static void F_555 ( struct V_20 * V_21 )
{
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_879 * V_880 ;
unsigned long V_338 ;
F_207 ( & V_2 -> V_342 , V_338 ) ;
V_880 = V_64 -> V_343 ;
V_64 -> V_343 = NULL ;
F_208 ( & V_2 -> V_342 , V_338 ) ;
if ( V_880 ) {
F_556 ( & V_880 -> V_880 ) ;
F_317 ( V_880 ) ;
}
F_511 ( V_21 , NULL , 0 , 0 , 0 ) ;
F_557 ( V_21 ) ;
F_317 ( V_64 ) ;
}
static void F_558 ( struct V_719 * V_720 )
{
struct V_879 * V_880 =
F_443 ( V_720 , struct V_879 , V_880 ) ;
struct V_1 * V_2 = V_880 -> V_21 -> V_2 ;
F_53 ( & V_2 -> V_290 ) ;
F_157 ( V_880 -> V_881 ) ;
F_517 ( & V_880 -> V_882 -> V_108 ) ;
F_517 ( & V_880 -> V_881 -> V_108 ) ;
F_184 ( V_2 ) ;
F_55 ( & V_2 -> V_290 ) ;
F_110 ( F_206 ( & F_30 ( V_880 -> V_21 ) -> V_344 ) == 0 ) ;
F_559 ( & F_30 ( V_880 -> V_21 ) -> V_344 ) ;
F_317 ( V_880 ) ;
}
static void F_560 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_879 * V_880 ;
unsigned long V_338 ;
if ( V_64 == NULL )
return;
F_207 ( & V_2 -> V_342 , V_338 ) ;
V_880 = V_64 -> V_343 ;
F_561 () ;
if ( V_880 == NULL || F_206 ( & V_880 -> V_339 ) < V_883 ) {
F_208 ( & V_2 -> V_342 , V_338 ) ;
return;
}
F_561 () ;
V_64 -> V_343 = NULL ;
if ( V_880 -> V_884 )
F_562 ( V_2 , V_64 -> V_71 , V_880 -> V_884 ) ;
F_563 ( V_2 , V_64 -> V_71 ) ;
F_208 ( & V_2 -> V_342 , V_338 ) ;
F_564 ( & V_4 -> V_345 ) ;
F_565 ( V_4 -> V_885 , & V_880 -> V_880 ) ;
F_566 ( V_64 -> V_141 , V_880 -> V_882 ) ;
}
void F_567 ( struct V_1 * V_2 , int V_71 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 = V_4 -> V_72 [ V_71 ] ;
F_560 ( V_2 , V_21 ) ;
}
void F_175 ( struct V_1 * V_2 , int V_141 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 = V_4 -> V_886 [ V_141 ] ;
F_560 ( V_2 , V_21 ) ;
}
void F_174 ( struct V_1 * V_2 , int V_141 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 =
F_30 ( V_4 -> V_886 [ V_141 ] ) ;
unsigned long V_338 ;
F_207 ( & V_2 -> V_342 , V_338 ) ;
if ( V_64 -> V_343 )
F_568 ( & V_64 -> V_343 -> V_339 ) ;
F_208 ( & V_2 -> V_342 , V_338 ) ;
}
inline static void F_569 ( struct V_64 * V_64 )
{
F_570 () ;
F_571 ( & V_64 -> V_343 -> V_339 , V_887 ) ;
F_570 () ;
}
static int F_572 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_241 * V_66 ,
struct V_219 * V_220 ,
T_4 V_338 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
T_1 V_888 ;
struct V_221 * V_877 = & V_4 -> V_877 [ V_889 ] ;
int V_224 ;
V_224 = F_150 ( V_2 , V_220 , V_877 ) ;
if ( V_224 )
goto V_53;
V_224 = F_573 ( V_877 , 6 ) ;
if ( V_224 )
goto V_233;
if ( V_64 -> V_141 )
V_888 = V_890 ;
else
V_888 = V_891 ;
F_574 ( V_877 , V_892 | V_888 ) ;
F_574 ( V_877 , V_893 ) ;
F_574 ( V_877 , V_894 |
F_575 ( V_64 -> V_141 ) ) ;
F_574 ( V_877 , V_66 -> V_269 [ 0 ] ) ;
F_574 ( V_877 , F_162 ( V_220 ) + V_64 -> V_271 ) ;
F_574 ( V_877 , 0 ) ;
F_569 ( V_64 ) ;
F_576 ( V_877 ) ;
return 0 ;
V_233:
F_157 ( V_220 ) ;
V_53:
return V_224 ;
}
static int F_577 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_241 * V_66 ,
struct V_219 * V_220 ,
T_4 V_338 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
T_1 V_888 ;
struct V_221 * V_877 = & V_4 -> V_877 [ V_889 ] ;
int V_224 ;
V_224 = F_150 ( V_2 , V_220 , V_877 ) ;
if ( V_224 )
goto V_53;
V_224 = F_573 ( V_877 , 6 ) ;
if ( V_224 )
goto V_233;
if ( V_64 -> V_141 )
V_888 = V_890 ;
else
V_888 = V_891 ;
F_574 ( V_877 , V_892 | V_888 ) ;
F_574 ( V_877 , V_893 ) ;
F_574 ( V_877 , V_895 |
F_575 ( V_64 -> V_141 ) ) ;
F_574 ( V_877 , V_66 -> V_269 [ 0 ] ) ;
F_574 ( V_877 , F_162 ( V_220 ) + V_64 -> V_271 ) ;
F_574 ( V_877 , V_893 ) ;
F_569 ( V_64 ) ;
F_576 ( V_877 ) ;
return 0 ;
V_233:
F_157 ( V_220 ) ;
V_53:
return V_224 ;
}
static int F_578 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_241 * V_66 ,
struct V_219 * V_220 ,
T_4 V_338 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
T_4 V_896 , V_897 ;
struct V_221 * V_877 = & V_4 -> V_877 [ V_889 ] ;
int V_224 ;
V_224 = F_150 ( V_2 , V_220 , V_877 ) ;
if ( V_224 )
goto V_53;
V_224 = F_573 ( V_877 , 4 ) ;
if ( V_224 )
goto V_233;
F_574 ( V_877 , V_894 |
F_575 ( V_64 -> V_141 ) ) ;
F_574 ( V_877 , V_66 -> V_269 [ 0 ] ) ;
F_574 ( V_877 ,
( F_162 ( V_220 ) + V_64 -> V_271 ) |
V_220 -> V_225 ) ;
V_896 = 0 ;
V_897 = F_4 ( F_180 ( V_64 -> V_71 ) ) & 0x0fff0fff ;
F_574 ( V_877 , V_896 | V_897 ) ;
F_569 ( V_64 ) ;
F_576 ( V_877 ) ;
return 0 ;
V_233:
F_157 ( V_220 ) ;
V_53:
return V_224 ;
}
static int F_579 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_241 * V_66 ,
struct V_219 * V_220 ,
T_4 V_338 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_221 * V_877 = & V_4 -> V_877 [ V_889 ] ;
T_4 V_896 , V_897 ;
int V_224 ;
V_224 = F_150 ( V_2 , V_220 , V_877 ) ;
if ( V_224 )
goto V_53;
V_224 = F_573 ( V_877 , 4 ) ;
if ( V_224 )
goto V_233;
F_574 ( V_877 , V_894 |
F_575 ( V_64 -> V_141 ) ) ;
F_574 ( V_877 , V_66 -> V_269 [ 0 ] | V_220 -> V_225 ) ;
F_574 ( V_877 , F_162 ( V_220 ) + V_64 -> V_271 ) ;
V_896 = 0 ;
V_897 = F_4 ( F_180 ( V_64 -> V_71 ) ) & 0x0fff0fff ;
F_574 ( V_877 , V_896 | V_897 ) ;
F_569 ( V_64 ) ;
F_576 ( V_877 ) ;
return 0 ;
V_233:
F_157 ( V_220 ) ;
V_53:
return V_224 ;
}
static int F_580 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_241 * V_66 ,
struct V_219 * V_220 ,
T_4 V_338 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_221 * V_877 ;
T_4 V_898 = 0 ;
int V_762 , V_224 ;
V_877 = V_220 -> V_877 ;
if ( F_17 ( V_2 ) || V_877 == NULL || V_877 -> V_197 != V_889 )
V_877 = & V_4 -> V_877 [ V_899 ] ;
V_224 = F_150 ( V_2 , V_220 , V_877 ) ;
if ( V_224 )
goto V_53;
switch( V_64 -> V_141 ) {
case V_900 :
V_898 = V_901 ;
break;
case V_902 :
V_898 = V_903 ;
break;
case V_904 :
V_898 = V_905 ;
break;
default:
F_581 ( 1 , L_172 ) ;
V_224 = - V_906 ;
goto V_233;
}
V_762 = 4 ;
if ( V_877 -> V_197 == V_889 )
V_762 += 6 ;
V_224 = F_582 ( V_877 ) ;
if ( V_224 )
goto V_233;
V_224 = F_573 ( V_877 , V_762 ) ;
if ( V_224 )
goto V_233;
if ( V_877 -> V_197 == V_889 ) {
F_574 ( V_877 , F_583 ( 1 ) ) ;
F_574 ( V_877 , V_907 ) ;
F_574 ( V_877 , ~ ( V_908 |
V_909 |
V_910 ) ) ;
F_574 ( V_877 , F_584 ( 1 ) |
V_911 ) ;
F_574 ( V_877 , V_907 ) ;
F_574 ( V_877 , V_877 -> V_912 . V_913 + 256 ) ;
}
F_574 ( V_877 , V_895 | V_898 ) ;
F_574 ( V_877 , ( V_66 -> V_269 [ 0 ] | V_220 -> V_225 ) ) ;
F_574 ( V_877 , F_162 ( V_220 ) + V_64 -> V_271 ) ;
F_574 ( V_877 , ( V_893 ) ) ;
F_569 ( V_64 ) ;
F_576 ( V_877 ) ;
return 0 ;
V_233:
F_157 ( V_220 ) ;
V_53:
return V_224 ;
}
static int F_585 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_241 * V_66 ,
struct V_219 * V_220 ,
T_4 V_338 )
{
return - V_906 ;
}
static int F_586 ( struct V_20 * V_21 ,
struct V_241 * V_66 ,
struct V_914 * V_884 ,
T_4 V_915 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_241 * V_277 = V_21 -> V_66 ;
struct V_219 * V_220 = F_161 ( V_66 ) -> V_220 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_879 * V_880 ;
unsigned long V_338 ;
int V_224 ;
if ( V_66 -> V_247 != V_21 -> V_66 -> V_247 )
return - V_229 ;
if ( F_39 ( V_2 ) -> V_77 > 3 &&
( V_66 -> V_916 [ 0 ] != V_21 -> V_66 -> V_916 [ 0 ] ||
V_66 -> V_269 [ 0 ] != V_21 -> V_66 -> V_269 [ 0 ] ) )
return - V_229 ;
V_880 = F_523 ( sizeof( * V_880 ) , V_836 ) ;
if ( V_880 == NULL )
return - V_815 ;
V_880 -> V_884 = V_884 ;
V_880 -> V_21 = V_21 ;
V_880 -> V_881 = F_161 ( V_277 ) -> V_220 ;
F_587 ( & V_880 -> V_880 , F_558 ) ;
V_224 = F_588 ( V_2 , V_64 -> V_71 ) ;
if ( V_224 )
goto V_917;
F_207 ( & V_2 -> V_342 , V_338 ) ;
if ( V_64 -> V_343 ) {
F_208 ( & V_2 -> V_342 , V_338 ) ;
F_317 ( V_880 ) ;
F_563 ( V_2 , V_64 -> V_71 ) ;
F_59 ( L_173 ) ;
return - V_918 ;
}
V_64 -> V_343 = V_880 ;
F_208 ( & V_2 -> V_342 , V_338 ) ;
if ( F_206 ( & V_64 -> V_344 ) >= 2 )
F_589 ( V_4 -> V_885 ) ;
V_224 = F_525 ( V_2 ) ;
if ( V_224 )
goto V_919;
F_590 ( & V_880 -> V_881 -> V_108 ) ;
F_590 ( & V_220 -> V_108 ) ;
V_21 -> V_66 = V_66 ;
V_880 -> V_882 = V_220 ;
V_880 -> V_920 = true ;
F_591 ( & V_64 -> V_344 ) ;
V_64 -> V_341 = F_206 ( & V_4 -> V_340 . V_341 ) ;
V_224 = V_4 -> V_273 . V_921 ( V_2 , V_21 , V_66 , V_220 , V_915 ) ;
if ( V_224 )
goto V_922;
F_270 ( V_2 ) ;
F_553 ( V_220 , NULL ) ;
F_55 ( & V_2 -> V_290 ) ;
F_592 ( V_64 -> V_141 , V_220 ) ;
return 0 ;
V_922:
F_559 ( & V_64 -> V_344 ) ;
V_21 -> V_66 = V_277 ;
F_517 ( & V_880 -> V_881 -> V_108 ) ;
F_517 ( & V_220 -> V_108 ) ;
F_55 ( & V_2 -> V_290 ) ;
V_919:
F_207 ( & V_2 -> V_342 , V_338 ) ;
V_64 -> V_343 = NULL ;
F_208 ( & V_2 -> V_342 , V_338 ) ;
F_563 ( V_2 , V_64 -> V_71 ) ;
V_917:
F_317 ( V_880 ) ;
return V_224 ;
}
static void F_593 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_464 * V_457 ;
F_173 (connector, &dev->mode_config.connector_list,
base.head) {
V_457 -> V_849 =
F_314 ( V_457 -> V_108 . V_23 ) ;
}
F_173 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_23 -> V_848 =
F_30 ( V_23 -> V_108 . V_21 ) ;
}
}
static void F_594 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_464 * V_457 ;
F_173 (connector, &dev->mode_config.connector_list,
base.head) {
V_457 -> V_108 . V_23 = & V_457 -> V_849 -> V_108 ;
}
F_173 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_23 -> V_108 . V_21 = & V_23 -> V_848 -> V_108 ;
}
}
static void
F_595 ( struct V_464 * V_457 ,
struct V_418 * V_419 )
{
int V_671 = V_419 -> V_471 ;
F_36 ( L_174 ,
V_457 -> V_108 . V_108 . V_197 ,
F_320 ( & V_457 -> V_108 ) ) ;
if ( V_457 -> V_108 . V_923 . V_372 &&
V_457 -> V_108 . V_923 . V_372 * 3 < V_671 ) {
F_36 ( L_175 ,
V_671 , V_457 -> V_108 . V_923 . V_372 * 3 ) ;
V_419 -> V_471 = V_457 -> V_108 . V_923 . V_372 * 3 ;
}
if ( V_457 -> V_108 . V_923 . V_372 == 0 && V_671 > 24 ) {
F_36 ( L_176 ,
V_671 ) ;
V_419 -> V_471 = 24 ;
}
}
static int
F_596 ( struct V_64 * V_21 ,
struct V_241 * V_66 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_464 * V_457 ;
int V_671 ;
switch ( V_66 -> V_247 ) {
case V_248 :
V_671 = 8 * 3 ;
break;
case V_250 :
case V_251 :
if ( F_2 ( F_39 ( V_2 ) -> V_77 > 3 ) )
return - V_229 ;
case V_253 :
V_671 = 6 * 3 ;
break;
case V_258 :
case V_259 :
if ( F_2 ( F_39 ( V_2 ) -> V_77 < 4 ) )
return - V_229 ;
case V_255 :
case V_256 :
V_671 = 8 * 3 ;
break;
case V_261 :
case V_262 :
case V_264 :
case V_265 :
if ( F_2 ( F_39 ( V_2 ) -> V_77 < 4 ) )
return - V_229 ;
V_671 = 10 * 3 ;
break;
default:
F_36 ( L_177 ) ;
return - V_229 ;
}
V_419 -> V_471 = V_671 ;
F_173 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_457 -> V_849 ||
V_457 -> V_849 -> V_848 != V_21 )
continue;
F_595 ( V_457 , V_419 ) ;
}
return V_671 ;
}
static void F_597 ( const struct V_292 * V_377 )
{
F_36 ( L_178
L_179 ,
V_377 -> V_69 ,
V_377 -> V_293 , V_377 -> V_580 ,
V_377 -> V_584 , V_377 -> V_581 ,
V_377 -> V_294 , V_377 -> V_586 ,
V_377 -> V_587 , V_377 -> V_577 , V_377 -> type , V_377 -> V_338 ) ;
}
static void F_598 ( struct V_64 * V_21 ,
struct V_418 * V_419 ,
const char * V_924 )
{
F_36 ( L_180 , V_21 -> V_108 . V_108 . V_197 ,
V_924 , F_69 ( V_21 -> V_71 ) ) ;
F_36 ( L_181 , F_599 ( V_419 -> V_73 ) ) ;
F_36 ( L_182 ,
V_419 -> V_471 , V_419 -> V_598 ) ;
F_36 ( L_183 ,
V_419 -> V_308 ,
V_419 -> V_318 ,
V_419 -> V_472 . V_511 , V_419 -> V_472 . V_512 ,
V_419 -> V_472 . V_513 , V_419 -> V_472 . V_514 ,
V_419 -> V_472 . V_510 ) ;
F_36 ( L_184 ,
V_419 -> V_555 ,
V_419 -> V_530 . V_511 , V_419 -> V_530 . V_512 ,
V_419 -> V_530 . V_513 , V_419 -> V_530 . V_514 ,
V_419 -> V_530 . V_510 ) ;
F_36 ( L_185 ) ;
F_600 ( & V_419 -> V_590 ) ;
F_36 ( L_186 ) ;
F_600 ( & V_419 -> V_68 ) ;
F_597 ( & V_419 -> V_68 ) ;
F_36 ( L_187 , V_419 -> V_549 ) ;
F_36 ( L_188 ,
V_419 -> V_297 , V_419 -> V_298 ) ;
F_36 ( L_189 ,
V_419 -> V_420 . V_421 ,
V_419 -> V_420 . V_425 ,
V_419 -> V_420 . V_621 ) ;
F_36 ( L_190 ,
V_419 -> V_295 . V_389 ,
V_419 -> V_295 . V_390 ,
V_419 -> V_295 . V_99 ? L_191 : L_192 ) ;
F_36 ( L_193 , V_419 -> V_392 ) ;
F_36 ( L_194 , V_419 -> V_478 ) ;
}
static bool F_601 ( struct V_20 * V_21 )
{
int V_925 = 0 ;
bool V_926 = false ;
struct V_22 * V_23 ;
F_173 (encoder, &crtc->dev->mode_config.encoder_list,
base.head) {
if ( & V_23 -> V_848 -> V_108 != V_21 )
continue;
V_925 ++ ;
if ( ! V_23 -> V_927 )
V_926 = true ;
}
return ! ( V_925 > 1 && V_926 ) ;
}
static struct V_418 *
F_602 ( struct V_20 * V_21 ,
struct V_241 * V_66 ,
struct V_292 * V_377 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_22 * V_23 ;
struct V_418 * V_419 ;
int V_928 , V_224 = - V_229 ;
bool V_323 = true ;
if ( ! F_601 ( V_21 ) ) {
F_36 ( L_195 ) ;
return F_524 ( - V_229 ) ;
}
V_419 = F_523 ( sizeof( * V_419 ) , V_836 ) ;
if ( ! V_419 )
return F_524 ( - V_815 ) ;
F_603 ( & V_419 -> V_68 , V_377 ) ;
F_603 ( & V_419 -> V_590 , V_377 ) ;
V_419 -> V_73 =
(enum V_70 ) F_30 ( V_21 ) -> V_71 ;
V_419 -> V_109 = V_382 ;
if ( ! ( V_419 -> V_68 . V_338 &
( V_378 | V_929 ) ) )
V_419 -> V_68 . V_338 |= V_929 ;
if ( ! ( V_419 -> V_68 . V_338 &
( V_380 | V_930 ) ) )
V_419 -> V_68 . V_338 |= V_930 ;
V_928 = F_596 ( F_30 ( V_21 ) ,
V_66 , V_419 ) ;
if ( V_928 < 0 )
goto V_816;
F_604 ( & V_419 -> V_590 , V_931 ) ;
V_419 -> V_297 = V_419 -> V_590 . V_293 ;
V_419 -> V_298 = V_419 -> V_590 . V_294 ;
V_932:
V_419 -> V_549 = 0 ;
V_419 -> V_553 = 1 ;
F_604 ( & V_419 -> V_68 , V_931 ) ;
F_173 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( & V_23 -> V_848 -> V_108 != V_21 )
continue;
if ( ! ( V_23 -> V_933 ( V_23 , V_419 ) ) ) {
F_36 ( L_196 ) ;
goto V_816;
}
}
if ( ! V_419 -> V_549 )
V_419 -> V_549 = V_419 -> V_68 . V_69
* V_419 -> V_553 ;
V_224 = F_331 ( F_30 ( V_21 ) , V_419 ) ;
if ( V_224 < 0 ) {
F_36 ( L_197 ) ;
goto V_816;
}
if ( V_224 == V_474 ) {
if ( F_46 ( ! V_323 , L_198 ) ) {
V_224 = - V_229 ;
goto V_816;
}
F_36 ( L_199 ) ;
V_323 = false ;
goto V_932;
}
V_419 -> V_598 = V_419 -> V_471 != V_928 ;
F_36 ( L_200 ,
V_928 , V_419 -> V_471 , V_419 -> V_598 ) ;
return V_419 ;
V_816:
F_317 ( V_419 ) ;
return F_524 ( V_224 ) ;
}
static void
F_605 ( struct V_20 * V_21 , unsigned * V_442 ,
unsigned * V_443 , unsigned * V_934 )
{
struct V_64 * V_64 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_22 * V_23 ;
struct V_464 * V_457 ;
struct V_20 * V_935 ;
* V_934 = * V_442 = * V_443 = 0 ;
F_173 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_457 -> V_108 . V_23 == & V_457 -> V_849 -> V_108 )
continue;
if ( V_457 -> V_108 . V_23 ) {
V_935 = V_457 -> V_108 . V_23 -> V_21 ;
* V_443 |= 1 << F_30 ( V_935 ) -> V_71 ;
}
if ( V_457 -> V_849 )
* V_443 |=
1 << V_457 -> V_849 -> V_848 -> V_71 ;
}
F_173 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_23 -> V_108 . V_21 == & V_23 -> V_848 -> V_108 )
continue;
if ( V_23 -> V_108 . V_21 ) {
V_935 = V_23 -> V_108 . V_21 ;
* V_443 |= 1 << F_30 ( V_935 ) -> V_71 ;
}
if ( V_23 -> V_848 )
* V_443 |= 1 << V_23 -> V_848 -> V_71 ;
}
F_173 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
bool V_936 = false ;
if ( ! V_64 -> V_108 . V_99 )
continue;
F_173 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_23 -> V_848 == V_64 )
V_936 = true ;
}
if ( ! V_936 )
* V_934 |= 1 << V_64 -> V_71 ;
}
V_64 = F_30 ( V_21 ) ;
if ( V_21 -> V_99 )
* V_443 |= 1 << V_64 -> V_71 ;
if ( * V_443 )
* V_442 = * V_443 ;
* V_442 &= ~ ( * V_934 ) ;
* V_443 &= ~ ( * V_934 ) ;
* V_442 &= 1 << V_64 -> V_71 ;
* V_443 &= 1 << V_64 -> V_71 ;
F_36 ( L_201 ,
* V_442 , * V_443 , * V_934 ) ;
}
static bool F_606 ( struct V_20 * V_21 )
{
struct V_462 * V_23 ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_173 (encoder, &dev->mode_config.encoder_list, head)
if ( V_23 -> V_21 == V_21 )
return true ;
return false ;
}
static void
F_607 ( struct V_1 * V_2 , unsigned V_443 )
{
struct V_22 * V_22 ;
struct V_64 * V_64 ;
struct V_456 * V_457 ;
F_173 (intel_encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_22 -> V_108 . V_21 )
continue;
V_64 = F_30 ( V_22 -> V_108 . V_21 ) ;
if ( V_443 & ( 1 << V_64 -> V_71 ) )
V_22 -> V_453 = false ;
}
F_594 ( V_2 ) ;
F_173 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
V_64 -> V_108 . V_99 = F_606 ( & V_64 -> V_108 ) ;
}
F_173 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_457 -> V_23 || ! V_457 -> V_23 -> V_21 )
continue;
V_64 = F_30 ( V_457 -> V_23 -> V_21 ) ;
if ( V_443 & ( 1 << V_64 -> V_71 ) ) {
struct V_937 * V_938 =
V_2 -> V_626 . V_938 ;
V_457 -> V_460 = V_463 ;
F_608 ( & V_457 -> V_108 ,
V_938 ,
V_463 ) ;
V_22 = F_314 ( V_457 -> V_23 ) ;
V_22 -> V_453 = true ;
}
}
}
static bool F_609 ( int V_939 , int V_940 )
{
int V_63 ;
if ( V_939 == V_940 )
return true ;
if ( ! V_939 || ! V_940 )
return false ;
V_63 = abs ( V_939 - V_940 ) ;
if ( ( ( ( ( V_63 + V_939 + V_940 ) * 100 ) ) / ( V_939 + V_940 ) ) < 105 )
return true ;
return false ;
}
static bool
F_610 ( struct V_1 * V_2 ,
struct V_418 * V_941 ,
struct V_418 * V_419 )
{
#define F_611 ( V_115 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_612 ( V_115 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_613 ( V_115 , V_734 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
DRM_ERROR("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
return false; \
}
#define F_614 ( V_115 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_615 ( T_9 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_612 ( V_73 ) ;
F_612 ( V_308 ) ;
F_612 ( V_318 ) ;
F_612 ( V_472 . V_511 ) ;
F_612 ( V_472 . V_512 ) ;
F_612 ( V_472 . V_513 ) ;
F_612 ( V_472 . V_514 ) ;
F_612 ( V_472 . V_510 ) ;
F_612 ( V_555 ) ;
F_612 ( V_530 . V_511 ) ;
F_612 ( V_530 . V_512 ) ;
F_612 ( V_530 . V_513 ) ;
F_612 ( V_530 . V_514 ) ;
F_612 ( V_530 . V_510 ) ;
F_612 ( V_68 . V_293 ) ;
F_612 ( V_68 . V_581 ) ;
F_612 ( V_68 . V_582 ) ;
F_612 ( V_68 . V_583 ) ;
F_612 ( V_68 . V_580 ) ;
F_612 ( V_68 . V_584 ) ;
F_612 ( V_68 . V_294 ) ;
F_612 ( V_68 . V_577 ) ;
F_612 ( V_68 . V_585 ) ;
F_612 ( V_68 . V_578 ) ;
F_612 ( V_68 . V_586 ) ;
F_612 ( V_68 . V_587 ) ;
F_612 ( V_553 ) ;
F_613 ( V_68 . V_338 ,
V_579 ) ;
if ( ! F_615 ( V_942 ) ) {
F_613 ( V_68 . V_338 ,
V_378 ) ;
F_613 ( V_68 . V_338 ,
V_929 ) ;
F_613 ( V_68 . V_338 ,
V_380 ) ;
F_613 ( V_68 . V_338 ,
V_930 ) ;
}
F_612 ( V_297 ) ;
F_612 ( V_298 ) ;
F_612 ( V_420 . V_421 ) ;
if ( F_39 ( V_2 ) -> V_77 < 4 )
F_612 ( V_420 . V_425 ) ;
F_612 ( V_420 . V_621 ) ;
F_612 ( V_295 . V_99 ) ;
if ( V_941 -> V_295 . V_99 ) {
F_612 ( V_295 . V_389 ) ;
F_612 ( V_295 . V_390 ) ;
}
if ( F_167 ( V_2 ) )
F_612 ( V_392 ) ;
F_612 ( V_478 ) ;
F_612 ( V_109 ) ;
F_611 ( V_188 . V_47 ) ;
F_611 ( V_188 . V_190 ) ;
F_611 ( V_188 . V_524 ) ;
F_611 ( V_188 . V_527 ) ;
if ( F_15 ( V_2 ) || F_39 ( V_2 ) -> V_77 >= 5 )
F_612 ( V_471 ) ;
if ( ! F_61 ( V_2 ) ) {
F_614 ( V_68 . V_69 ) ;
F_614 ( V_549 ) ;
}
#undef F_611
#undef F_612
#undef F_613
#undef F_614
#undef F_615
return true ;
}
static void
F_616 ( struct V_1 * V_2 )
{
struct V_464 * V_457 ;
F_173 (connector, &dev->mode_config.connector_list,
base.head) {
F_319 ( V_457 ) ;
F_46 ( & V_457 -> V_849 -> V_108 != V_457 -> V_108 . V_23 ,
L_202 ) ;
}
}
static void
F_617 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_464 * V_457 ;
F_173 (encoder, &dev->mode_config.encoder_list,
base.head) {
bool V_99 = false ;
bool V_65 = false ;
enum V_71 V_71 , V_943 ;
F_36 ( L_203 ,
V_23 -> V_108 . V_108 . V_197 ,
F_483 ( & V_23 -> V_108 ) ) ;
F_46 ( & V_23 -> V_848 -> V_108 != V_23 -> V_108 . V_21 ,
L_204 ) ;
F_46 ( V_23 -> V_453 && ! V_23 -> V_108 . V_21 ,
L_205 ) ;
F_173 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_457 -> V_108 . V_23 != & V_23 -> V_108 )
continue;
V_99 = true ;
if ( V_457 -> V_108 . V_460 != V_461 )
V_65 = true ;
}
F_46 ( ! ! V_23 -> V_108 . V_21 != V_99 ,
L_206
L_207 ,
! ! V_23 -> V_108 . V_21 , V_99 ) ;
F_46 ( V_65 && ! V_23 -> V_108 . V_21 ,
L_208 ) ;
F_46 ( V_23 -> V_453 != V_65 ,
L_209
L_207 , V_65 , V_23 -> V_453 ) ;
V_65 = V_23 -> V_114 ( V_23 , & V_71 ) ;
F_46 ( V_65 != V_23 -> V_453 ,
L_210
L_207 ,
V_23 -> V_453 , V_65 ) ;
if ( ! V_23 -> V_108 . V_21 )
continue;
V_943 = F_30 ( V_23 -> V_108 . V_21 ) -> V_71 ;
F_46 ( V_65 && V_71 != V_943 ,
L_211
L_207 ,
V_943 , V_71 ) ;
}
}
static void
F_618 ( struct V_1 * V_2 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_64 * V_21 ;
struct V_22 * V_23 ;
struct V_418 V_419 ;
F_173 (crtc, &dev->mode_config.crtc_list,
base.head) {
bool V_99 = false ;
bool V_65 = false ;
memset ( & V_419 , 0 , sizeof( V_419 ) ) ;
F_36 ( L_212 ,
V_21 -> V_108 . V_108 . V_197 ) ;
F_46 ( V_21 -> V_65 && ! V_21 -> V_108 . V_99 ,
L_213 ) ;
F_173 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_23 -> V_108 . V_21 != & V_21 -> V_108 )
continue;
V_99 = true ;
if ( V_23 -> V_453 )
V_65 = true ;
}
F_46 ( V_65 != V_21 -> V_65 ,
L_214
L_207 , V_65 , V_21 -> V_65 ) ;
F_46 ( V_99 != V_21 -> V_108 . V_99 ,
L_215
L_207 , V_99 , V_21 -> V_108 . V_99 ) ;
V_65 = V_4 -> V_273 . V_944 ( V_21 ,
& V_419 ) ;
if ( V_21 -> V_71 == V_125 && V_4 -> V_138 & V_139 )
V_65 = V_21 -> V_65 ;
F_173 (encoder, &dev->mode_config.encoder_list,
base.head) {
enum V_71 V_71 ;
if ( V_23 -> V_108 . V_21 != & V_21 -> V_108 )
continue;
if ( V_23 -> V_114 ( V_23 , & V_71 ) )
V_23 -> V_945 ( V_23 , & V_419 ) ;
}
F_46 ( V_21 -> V_65 != V_65 ,
L_216
L_207 , V_21 -> V_65 , V_65 ) ;
if ( V_65 &&
! F_610 ( V_2 , & V_21 -> V_67 , & V_419 ) ) {
F_46 ( 1 , L_217 ) ;
F_598 ( V_21 , & V_419 ,
L_218 ) ;
F_598 ( V_21 , & V_21 -> V_67 ,
L_219 ) ;
}
}
}
static void
F_619 ( struct V_1 * V_2 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_64 * V_21 ;
struct V_112 V_188 ;
int V_143 ;
for ( V_143 = 0 ; V_143 < V_4 -> V_384 ; V_143 ++ ) {
struct V_107 * V_111 = & V_4 -> V_110 [ V_143 ] ;
int V_946 = 0 , V_947 = 0 ;
bool V_65 ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
F_36 ( L_220 , V_111 -> V_115 ) ;
V_65 = V_111 -> V_114 ( V_4 , V_111 , & V_188 ) ;
F_46 ( V_111 -> V_65 > V_111 -> V_195 ,
L_221 ,
V_111 -> V_65 , V_111 -> V_195 ) ;
F_46 ( V_111 -> V_65 && ! V_111 -> V_196 ,
L_222 ) ;
F_46 ( V_111 -> V_196 && ! V_111 -> V_65 ,
L_223 ) ;
F_46 ( V_111 -> V_196 != V_65 ,
L_224 ,
V_111 -> V_196 , V_65 ) ;
F_173 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_21 -> V_108 . V_99 && F_56 ( V_21 ) == V_111 )
V_946 ++ ;
if ( V_21 -> V_65 && F_56 ( V_21 ) == V_111 )
V_947 ++ ;
}
F_46 ( V_111 -> V_65 != V_947 ,
L_225 ,
V_111 -> V_65 , V_947 ) ;
F_46 ( V_111 -> V_195 != V_946 ,
L_226 ,
V_111 -> V_195 , V_946 ) ;
F_46 ( V_111 -> V_196 && memcmp ( & V_111 -> V_113 , & V_188 ,
sizeof( V_188 ) ) ,
L_227 ) ;
}
}
void
F_322 ( struct V_1 * V_2 )
{
F_616 ( V_2 ) ;
F_617 ( V_2 ) ;
F_618 ( V_2 ) ;
F_619 ( V_2 ) ;
}
void F_620 ( const struct V_418 * V_419 ,
int V_948 )
{
F_46 ( ! F_609 ( V_419 -> V_68 . V_69 , V_948 ) ,
L_228 ,
V_419 -> V_68 . V_69 , V_948 ) ;
}
static int F_621 ( struct V_20 * V_21 ,
struct V_292 * V_377 ,
int V_234 , int V_235 , struct V_241 * V_66 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_8 * V_4 = V_2 -> V_5 ;
struct V_292 * V_949 ;
struct V_418 * V_419 = NULL ;
struct V_64 * V_64 ;
unsigned V_934 , V_443 , V_442 ;
int V_224 = 0 ;
V_949 = F_622 ( sizeof( * V_949 ) , V_836 ) ;
if ( ! V_949 )
return - V_815 ;
F_605 ( V_21 , & V_442 ,
& V_443 , & V_934 ) ;
* V_949 = V_21 -> V_377 ;
if ( V_442 ) {
V_419 = F_602 ( V_21 , V_66 , V_377 ) ;
if ( F_538 ( V_419 ) ) {
V_224 = F_623 ( V_419 ) ;
V_419 = NULL ;
goto V_950;
}
F_598 ( F_30 ( V_21 ) , V_419 ,
L_229 ) ;
}
if ( F_17 ( V_2 ) ) {
F_303 ( V_2 , & V_443 ,
V_442 , V_419 ) ;
V_443 &= ~ V_934 ;
}
F_624 (dev, disable_pipes, intel_crtc)
F_312 ( & V_64 -> V_108 ) ;
F_624 (dev, prepare_pipes, intel_crtc) {
if ( V_64 -> V_108 . V_99 )
V_4 -> V_273 . V_455 ( & V_64 -> V_108 ) ;
}
if ( V_442 ) {
V_21 -> V_377 = * V_377 ;
F_30 ( V_21 ) -> V_67 = * V_419 ;
F_625 ( V_21 ,
& V_419 -> V_68 ) ;
}
F_607 ( V_2 , V_443 ) ;
if ( V_4 -> V_273 . V_951 )
V_4 -> V_273 . V_951 ( V_2 ) ;
F_624 (dev, modeset_pipes, intel_crtc) {
V_224 = F_480 ( & V_64 -> V_108 ,
V_234 , V_235 , V_66 ) ;
if ( V_224 )
goto V_731;
}
F_624 (dev, prepare_pipes, intel_crtc)
V_4 -> V_273 . V_454 ( & V_64 -> V_108 ) ;
V_731:
if ( V_224 && V_21 -> V_99 )
V_21 -> V_377 = * V_949 ;
V_950:
F_317 ( V_419 ) ;
F_317 ( V_949 ) ;
return V_224 ;
}
static int F_539 ( struct V_20 * V_21 ,
struct V_292 * V_377 ,
int V_234 , int V_235 , struct V_241 * V_66 )
{
int V_224 ;
V_224 = F_621 ( V_21 , V_377 , V_234 , V_235 , V_66 ) ;
if ( V_224 == 0 )
F_322 ( V_21 -> V_2 ) ;
return V_224 ;
}
void F_626 ( struct V_20 * V_21 )
{
F_539 ( V_21 , & V_21 -> V_377 , V_21 -> V_234 , V_21 -> V_235 , V_21 -> V_66 ) ;
}
static void F_627 ( struct V_952 * V_67 )
{
if ( ! V_67 )
return;
F_317 ( V_67 -> V_953 ) ;
F_317 ( V_67 -> V_954 ) ;
F_317 ( V_67 ) ;
}
static int F_628 ( struct V_1 * V_2 ,
struct V_952 * V_67 )
{
struct V_462 * V_23 ;
struct V_456 * V_457 ;
int V_955 ;
V_67 -> V_954 =
F_629 ( V_2 -> V_626 . V_956 ,
sizeof( struct V_20 * ) , V_836 ) ;
if ( ! V_67 -> V_954 )
return - V_815 ;
V_67 -> V_953 =
F_629 ( V_2 -> V_626 . V_957 ,
sizeof( struct V_462 * ) , V_836 ) ;
if ( ! V_67 -> V_953 )
return - V_815 ;
V_955 = 0 ;
F_173 (encoder, &dev->mode_config.encoder_list, head) {
V_67 -> V_954 [ V_955 ++ ] = V_23 -> V_21 ;
}
V_955 = 0 ;
F_173 (connector, &dev->mode_config.connector_list, head) {
V_67 -> V_953 [ V_955 ++ ] = V_457 -> V_23 ;
}
return 0 ;
}
static void F_630 ( struct V_1 * V_2 ,
struct V_952 * V_67 )
{
struct V_22 * V_23 ;
struct V_464 * V_457 ;
int V_955 ;
V_955 = 0 ;
F_173 (encoder, &dev->mode_config.encoder_list, base.head) {
V_23 -> V_848 =
F_30 ( V_67 -> V_954 [ V_955 ++ ] ) ;
}
V_955 = 0 ;
F_173 (connector, &dev->mode_config.connector_list, base.head) {
V_457 -> V_849 =
F_314 ( V_67 -> V_953 [ V_955 ++ ] ) ;
}
}
static bool
F_631 ( struct V_958 * V_959 )
{
int V_143 ;
if ( V_959 -> V_519 == 0 )
return false ;
if ( F_2 ( V_959 -> V_960 == NULL ) )
return false ;
for ( V_143 = 0 ; V_143 < V_959 -> V_519 ; V_143 ++ )
if ( V_959 -> V_960 [ V_143 ] -> V_23 &&
V_959 -> V_960 [ V_143 ] -> V_23 -> V_21 == V_959 -> V_21 &&
V_959 -> V_960 [ V_143 ] -> V_460 != V_463 )
return true ;
return false ;
}
static void
F_632 ( struct V_958 * V_959 ,
struct V_952 * V_67 )
{
if ( F_631 ( V_959 ) ) {
V_67 -> V_961 = true ;
} else if ( V_959 -> V_21 -> V_66 != V_959 -> V_66 ) {
if ( V_959 -> V_21 -> V_66 == NULL ) {
struct V_64 * V_64 =
F_30 ( V_959 -> V_21 ) ;
if ( V_64 -> V_65 && V_291 ) {
F_36 ( L_230 ) ;
V_67 -> V_962 = true ;
} else {
F_36 ( L_231 ) ;
V_67 -> V_961 = true ;
}
} else if ( V_959 -> V_66 == NULL ) {
V_67 -> V_961 = true ;
} else if ( V_959 -> V_66 -> V_247 !=
V_959 -> V_21 -> V_66 -> V_247 ) {
V_67 -> V_961 = true ;
} else {
V_67 -> V_962 = true ;
}
}
if ( V_959 -> V_66 && ( V_959 -> V_234 != V_959 -> V_21 -> V_234 || V_959 -> V_235 != V_959 -> V_21 -> V_235 ) )
V_67 -> V_962 = true ;
if ( V_959 -> V_377 && ! F_633 ( V_959 -> V_377 , & V_959 -> V_21 -> V_377 ) ) {
F_36 ( L_232 ) ;
F_600 ( & V_959 -> V_21 -> V_377 ) ;
F_600 ( V_959 -> V_377 ) ;
V_67 -> V_961 = true ;
}
F_36 ( L_233 ,
V_959 -> V_21 -> V_108 . V_197 , V_67 -> V_961 , V_67 -> V_962 ) ;
}
static int
F_634 ( struct V_1 * V_2 ,
struct V_958 * V_959 ,
struct V_952 * V_67 )
{
struct V_20 * V_848 ;
struct V_464 * V_457 ;
struct V_22 * V_23 ;
int V_963 ;
F_2 ( ! V_959 -> V_66 && ( V_959 -> V_519 != 0 ) ) ;
F_2 ( V_959 -> V_66 && ( V_959 -> V_519 == 0 ) ) ;
F_173 (connector, &dev->mode_config.connector_list,
base.head) {
for ( V_963 = 0 ; V_963 < V_959 -> V_519 ; V_963 ++ ) {
if ( V_959 -> V_960 [ V_963 ] == & V_457 -> V_108 ) {
V_457 -> V_849 = V_457 -> V_23 ;
break;
}
}
if ( ( ! V_959 -> V_66 || V_963 == V_959 -> V_519 ) &&
V_457 -> V_108 . V_23 &&
V_457 -> V_108 . V_23 -> V_21 == V_959 -> V_21 ) {
V_457 -> V_849 = NULL ;
F_36 ( L_234 ,
V_457 -> V_108 . V_108 . V_197 ,
F_320 ( & V_457 -> V_108 ) ) ;
}
if ( & V_457 -> V_849 -> V_108 != V_457 -> V_108 . V_23 ) {
F_36 ( L_235 ) ;
V_67 -> V_961 = true ;
}
}
F_173 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_457 -> V_849 )
continue;
V_848 = V_457 -> V_849 -> V_108 . V_21 ;
for ( V_963 = 0 ; V_963 < V_959 -> V_519 ; V_963 ++ ) {
if ( V_959 -> V_960 [ V_963 ] == & V_457 -> V_108 )
V_848 = V_959 -> V_21 ;
}
if ( ! F_635 ( & V_457 -> V_849 -> V_108 ,
V_848 ) ) {
return - V_229 ;
}
V_457 -> V_23 -> V_848 = F_30 ( V_848 ) ;
F_36 ( L_236 ,
V_457 -> V_108 . V_108 . V_197 ,
F_320 ( & V_457 -> V_108 ) ,
V_848 -> V_108 . V_197 ) ;
}
F_173 (encoder, &dev->mode_config.encoder_list,
base.head) {
int V_519 = 0 ;
F_173 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_457 -> V_849 == V_23 ) {
F_2 ( ! V_457 -> V_849 -> V_848 ) ;
V_519 ++ ;
}
}
if ( V_519 == 0 )
V_23 -> V_848 = NULL ;
else if ( V_519 > 1 )
return - V_229 ;
if ( & V_23 -> V_848 -> V_108 != V_23 -> V_108 . V_21 ) {
F_36 ( L_237 ) ;
V_67 -> V_961 = true ;
}
}
return 0 ;
}
static int F_636 ( struct V_958 * V_959 )
{
struct V_1 * V_2 ;
struct V_958 V_964 ;
struct V_952 * V_67 ;
int V_224 ;
F_110 ( ! V_959 ) ;
F_110 ( ! V_959 -> V_21 ) ;
F_110 ( ! V_959 -> V_21 -> V_965 ) ;
F_110 ( ! V_959 -> V_377 && V_959 -> V_66 ) ;
F_110 ( V_959 -> V_66 && V_959 -> V_519 == 0 ) ;
if ( V_959 -> V_66 ) {
F_36 ( L_238 ,
V_959 -> V_21 -> V_108 . V_197 , V_959 -> V_66 -> V_108 . V_197 ,
( int ) V_959 -> V_519 , V_959 -> V_234 , V_959 -> V_235 ) ;
} else {
F_36 ( L_239 , V_959 -> V_21 -> V_108 . V_197 ) ;
}
V_2 = V_959 -> V_21 -> V_2 ;
V_224 = - V_815 ;
V_67 = F_523 ( sizeof( * V_67 ) , V_836 ) ;
if ( ! V_67 )
goto V_966;
V_224 = F_628 ( V_2 , V_67 ) ;
if ( V_224 )
goto V_966;
V_964 . V_21 = V_959 -> V_21 ;
V_964 . V_377 = & V_959 -> V_21 -> V_377 ;
V_964 . V_234 = V_959 -> V_21 -> V_234 ;
V_964 . V_235 = V_959 -> V_21 -> V_235 ;
V_964 . V_66 = V_959 -> V_21 -> V_66 ;
F_632 ( V_959 , V_67 ) ;
V_224 = F_634 ( V_2 , V_959 , V_67 ) ;
if ( V_224 )
goto V_816;
if ( V_67 -> V_961 ) {
V_224 = F_539 ( V_959 -> V_21 , V_959 -> V_377 ,
V_959 -> V_234 , V_959 -> V_235 , V_959 -> V_66 ) ;
} else if ( V_67 -> V_962 ) {
F_210 ( V_959 -> V_21 ) ;
V_224 = F_179 ( V_959 -> V_21 ,
V_959 -> V_234 , V_959 -> V_235 , V_959 -> V_66 ) ;
if ( V_291 && V_224 == 0 )
F_322 ( V_959 -> V_21 -> V_2 ) ;
}
if ( V_224 ) {
F_36 ( L_240 ,
V_959 -> V_21 -> V_108 . V_197 , V_224 ) ;
V_816:
F_630 ( V_2 , V_67 ) ;
if ( V_67 -> V_961 &&
F_539 ( V_964 . V_21 , V_964 . V_377 ,
V_964 . V_234 , V_964 . V_235 , V_964 . V_66 ) )
F_115 ( L_241 ) ;
}
V_966:
F_627 ( V_67 ) ;
return V_224 ;
}
static void F_637 ( struct V_1 * V_2 )
{
if ( F_61 ( V_2 ) )
F_638 ( V_2 ) ;
}
static bool F_639 ( struct V_3 * V_4 ,
struct V_107 * V_111 ,
struct V_112 * V_113 )
{
T_4 V_101 ;
V_101 = F_4 ( F_640 ( V_111 -> V_197 ) ) ;
V_113 -> V_47 = V_101 ;
V_113 -> V_524 = F_4 ( F_641 ( V_111 -> V_197 ) ) ;
V_113 -> V_527 = F_4 ( F_642 ( V_111 -> V_197 ) ) ;
return V_101 & V_103 ;
}
static void F_643 ( struct V_3 * V_4 ,
struct V_107 * V_111 )
{
F_40 ( F_641 ( V_111 -> V_197 ) , V_111 -> V_113 . V_524 ) ;
F_40 ( F_642 ( V_111 -> V_197 ) , V_111 -> V_113 . V_527 ) ;
}
static void F_644 ( struct V_3 * V_4 ,
struct V_107 * V_111 )
{
F_88 ( V_4 ) ;
F_40 ( F_640 ( V_111 -> V_197 ) , V_111 -> V_113 . V_47 ) ;
F_113 ( F_640 ( V_111 -> V_197 ) ) ;
F_114 ( 150 ) ;
F_40 ( F_640 ( V_111 -> V_197 ) , V_111 -> V_113 . V_47 ) ;
F_113 ( F_640 ( V_111 -> V_197 ) ) ;
F_114 ( 200 ) ;
}
static void F_645 ( struct V_3 * V_4 ,
struct V_107 * V_111 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_64 * V_21 ;
F_173 (crtc, &dev->mode_config.crtc_list, base.head) {
if ( F_56 ( V_21 ) == V_111 )
F_90 ( V_4 , V_21 -> V_71 ) ;
}
F_40 ( F_640 ( V_111 -> V_197 ) , 0 ) ;
F_113 ( F_640 ( V_111 -> V_197 ) ) ;
F_114 ( 200 ) ;
}
static void F_646 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_143 ;
V_4 -> V_384 = 2 ;
for ( V_143 = 0 ; V_143 < V_4 -> V_384 ; V_143 ++ ) {
V_4 -> V_110 [ V_143 ] . V_197 = V_143 ;
V_4 -> V_110 [ V_143 ] . V_115 = V_967 [ V_143 ] ;
V_4 -> V_110 [ V_143 ] . V_385 = F_643 ;
V_4 -> V_110 [ V_143 ] . V_198 = F_644 ;
V_4 -> V_110 [ V_143 ] . V_199 = F_645 ;
V_4 -> V_110 [ V_143 ] . V_114 =
F_639 ;
}
}
static void F_647 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_48 ( V_2 ) || F_89 ( V_2 ) )
F_646 ( V_2 ) ;
else
V_4 -> V_384 = 0 ;
F_110 ( V_4 -> V_384 > V_968 ) ;
}
static void F_648 ( struct V_1 * V_2 , int V_71 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 ;
int V_143 ;
V_64 = F_523 ( sizeof( * V_64 ) , V_836 ) ;
if ( V_64 == NULL )
return;
F_649 ( V_2 , & V_64 -> V_108 , & V_969 ) ;
F_650 ( & V_64 -> V_108 , 256 ) ;
for ( V_143 = 0 ; V_143 < 256 ; V_143 ++ ) {
V_64 -> V_403 [ V_143 ] = V_143 ;
V_64 -> V_404 [ V_143 ] = V_143 ;
V_64 -> V_405 [ V_143 ] = V_143 ;
}
V_64 -> V_71 = V_71 ;
V_64 -> V_141 = V_71 ;
if ( F_651 ( V_2 ) && F_39 ( V_2 ) -> V_77 < 4 ) {
F_36 ( L_242 ) ;
V_64 -> V_141 = ! V_71 ;
}
F_110 ( V_71 >= F_200 ( V_4 -> V_886 ) ||
V_4 -> V_886 [ V_64 -> V_141 ] != NULL ) ;
V_4 -> V_886 [ V_64 -> V_141 ] = & V_64 -> V_108 ;
V_4 -> V_72 [ V_64 -> V_71 ] = & V_64 -> V_108 ;
F_652 ( & V_64 -> V_108 , & V_970 ) ;
}
enum V_71 F_653 ( struct V_464 * V_457 )
{
struct V_462 * V_23 = V_457 -> V_108 . V_23 ;
F_2 ( ! F_449 ( & V_457 -> V_108 . V_2 -> V_626 . V_276 ) ) ;
if ( ! V_23 )
return V_971 ;
return F_30 ( V_23 -> V_21 ) -> V_71 ;
}
int F_654 ( struct V_1 * V_2 , void * V_972 ,
struct V_807 * V_808 )
{
struct V_973 * V_974 = V_972 ;
struct V_975 * V_976 ;
struct V_64 * V_21 ;
if ( ! F_655 ( V_2 , V_977 ) )
return - V_906 ;
V_976 = F_656 ( V_2 , V_974 -> V_978 ,
V_979 ) ;
if ( ! V_976 ) {
F_115 ( L_243 ) ;
return - V_814 ;
}
V_21 = F_30 ( F_657 ( V_976 ) ) ;
V_974 -> V_71 = V_21 -> V_71 ;
return 0 ;
}
static int F_658 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_108 . V_2 ;
struct V_22 * V_980 ;
int V_981 = 0 ;
int V_982 = 0 ;
F_173 (source_encoder,
&dev->mode_config.encoder_list, base.head) {
if ( V_23 == V_980 )
V_981 |= ( 1 << V_982 ) ;
if ( V_23 -> V_927 && V_980 -> V_927 )
V_981 |= ( 1 << V_982 ) ;
V_982 ++ ;
}
return V_981 ;
}
static bool F_659 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_111 ( V_2 ) )
return false ;
if ( ( F_4 ( V_983 ) & V_984 ) == 0 )
return false ;
if ( F_6 ( V_2 ) &&
( F_4 ( V_985 ) & V_986 ) )
return false ;
return true ;
}
const char * F_660 ( int V_987 )
{
static const char * V_988 [] = {
[ V_989 ] = L_244 ,
[ V_34 ] = L_245 ,
[ V_44 ] = L_246 ,
[ V_36 ] = L_247 ,
[ V_25 ] = L_248 ,
[ V_990 ] = L_249 ,
[ V_33 ] = L_250 ,
[ V_371 ] = L_251 ,
[ V_296 ] = L_252 ,
[ V_400 ] = L_253 ,
[ V_991 ] = L_254 ,
} ;
if ( V_987 < 0 || V_987 >= F_200 ( V_988 ) || ! V_988 [ V_987 ] )
return L_255 ;
return V_988 [ V_987 ] ;
}
static void F_661 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_23 ;
bool V_992 = false ;
F_662 ( V_2 ) ;
if ( ! F_663 ( V_2 ) )
F_664 ( V_2 ) ;
if ( F_61 ( V_2 ) ) {
int V_59 ;
V_59 = F_4 ( V_993 ) & V_994 ;
if ( V_59 )
F_665 ( V_2 , V_633 ) ;
V_59 = F_4 ( V_995 ) ;
if ( V_59 & V_996 )
F_665 ( V_2 , V_89 ) ;
if ( V_59 & V_997 )
F_665 ( V_2 , V_91 ) ;
if ( V_59 & V_998 )
F_665 ( V_2 , V_93 ) ;
} else if ( F_3 ( V_2 ) ) {
int V_59 ;
V_992 = F_666 ( V_2 , V_93 ) ;
if ( F_659 ( V_2 ) )
F_667 ( V_2 , V_983 , V_633 ) ;
if ( F_4 ( V_179 ) & V_999 ) {
V_59 = F_668 ( V_2 , V_1000 , true ) ;
if ( ! V_59 )
F_669 ( V_2 , V_179 , V_89 ) ;
if ( ! V_59 && ( F_4 ( V_172 ) & V_984 ) )
F_667 ( V_2 , V_172 , V_89 ) ;
}
if ( F_4 ( V_180 ) & V_999 )
F_669 ( V_2 , V_180 , V_91 ) ;
if ( ! V_992 && F_4 ( V_181 ) & V_999 )
F_669 ( V_2 , V_181 , V_93 ) ;
if ( F_4 ( V_174 ) & V_984 )
F_667 ( V_2 , V_174 , V_91 ) ;
if ( F_4 ( V_176 ) & V_984 )
F_667 ( V_2 , V_176 , V_93 ) ;
} else if ( F_17 ( V_2 ) ) {
if ( F_4 ( V_1001 + V_1002 ) & V_999 ) {
F_669 ( V_2 , V_1001 + V_1002 ,
V_89 ) ;
if ( F_4 ( V_1001 + V_1003 ) & V_984 )
F_667 ( V_2 , V_1001 + V_1003 , V_89 ) ;
}
if ( F_4 ( V_1001 + V_1004 ) & V_999 ) {
F_669 ( V_2 , V_1001 + V_1004 ,
V_91 ) ;
if ( F_4 ( V_1001 + V_1005 ) & V_984 )
F_667 ( V_2 , V_1001 + V_1005 , V_91 ) ;
}
F_670 ( V_2 ) ;
} else if ( F_671 ( V_2 ) ) {
bool V_59 = false ;
if ( F_4 ( V_1006 ) & V_999 ) {
F_36 ( L_256 ) ;
V_59 = F_668 ( V_2 , V_1006 , true ) ;
if ( ! V_59 && F_672 ( V_2 ) ) {
F_36 ( L_257 ) ;
F_669 ( V_2 , V_1002 , V_89 ) ;
}
if ( ! V_59 && F_673 ( V_2 ) )
F_667 ( V_2 , V_1003 , V_89 ) ;
}
if ( F_4 ( V_1006 ) & V_999 ) {
F_36 ( L_258 ) ;
V_59 = F_668 ( V_2 , V_1007 , false ) ;
}
if ( ! V_59 && ( F_4 ( V_1007 ) & V_999 ) ) {
if ( F_672 ( V_2 ) ) {
F_36 ( L_259 ) ;
F_669 ( V_2 , V_1004 , V_91 ) ;
}
if ( F_673 ( V_2 ) )
F_667 ( V_2 , V_1005 , V_91 ) ;
}
if ( F_673 ( V_2 ) &&
( F_4 ( V_1008 ) & V_984 ) )
F_667 ( V_2 , V_1008 , V_93 ) ;
} else if ( F_18 ( V_2 ) )
F_674 ( V_2 ) ;
if ( F_675 ( V_2 ) )
F_676 ( V_2 ) ;
F_173 (encoder, &dev->mode_config.encoder_list, base.head) {
V_23 -> V_108 . V_847 = V_23 -> V_1009 ;
V_23 -> V_108 . V_1010 =
F_658 ( V_23 ) ;
}
F_404 ( V_2 ) ;
F_677 ( V_2 ) ;
}
void F_678 ( struct V_242 * V_66 )
{
F_679 ( & V_66 -> V_108 ) ;
F_2 ( ! V_66 -> V_220 -> V_1011 -- ) ;
F_518 ( & V_66 -> V_220 -> V_108 ) ;
}
static void F_680 ( struct V_241 * V_66 )
{
struct V_242 * V_243 = F_161 ( V_66 ) ;
F_678 ( V_243 ) ;
F_317 ( V_243 ) ;
}
static int F_681 ( struct V_241 * V_66 ,
struct V_807 * V_808 ,
unsigned int * V_809 )
{
struct V_242 * V_243 = F_161 ( V_66 ) ;
struct V_219 * V_220 = V_243 -> V_220 ;
return F_682 ( V_808 , & V_220 -> V_108 , V_809 ) ;
}
int F_526 ( struct V_1 * V_2 ,
struct V_242 * V_243 ,
struct V_834 * V_835 ,
struct V_219 * V_220 )
{
int V_1012 , V_1013 ;
int V_1014 ;
int V_224 ;
F_2 ( ! F_449 ( & V_2 -> V_290 ) ) ;
if ( V_220 -> V_225 == V_228 ) {
F_683 ( L_260 ) ;
return - V_229 ;
}
if ( V_835 -> V_269 [ 0 ] & 63 ) {
F_683 ( L_261 ,
V_835 -> V_269 [ 0 ] ) ;
return - V_229 ;
}
if ( F_39 ( V_2 ) -> V_77 >= 5 && ! F_17 ( V_2 ) ) {
V_1014 = 32 * 1024 ;
} else if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
if ( V_220 -> V_225 )
V_1014 = 16 * 1024 ;
else
V_1014 = 32 * 1024 ;
} else if ( F_39 ( V_2 ) -> V_77 >= 3 ) {
if ( V_220 -> V_225 )
V_1014 = 8 * 1024 ;
else
V_1014 = 16 * 1024 ;
} else
V_1014 = 8 * 1024 ;
if ( V_835 -> V_269 [ 0 ] > V_1014 ) {
F_683 ( L_262 ,
V_220 -> V_225 ? L_263 : L_264 ,
V_835 -> V_269 [ 0 ] , V_1014 ) ;
return - V_229 ;
}
if ( V_220 -> V_225 != V_226 &&
V_835 -> V_269 [ 0 ] != V_220 -> V_1015 ) {
F_683 ( L_265 ,
V_835 -> V_269 [ 0 ] , V_220 -> V_1015 ) ;
return - V_229 ;
}
switch ( V_835 -> V_247 ) {
case V_248 :
case V_253 :
case V_255 :
case V_256 :
break;
case V_250 :
case V_251 :
if ( F_39 ( V_2 ) -> V_77 > 3 ) {
F_683 ( L_266 ,
F_684 ( V_835 -> V_247 ) ) ;
return - V_229 ;
}
break;
case V_258 :
case V_259 :
case V_261 :
case V_262 :
case V_264 :
case V_265 :
if ( F_39 ( V_2 ) -> V_77 < 4 ) {
F_683 ( L_266 ,
F_684 ( V_835 -> V_247 ) ) ;
return - V_229 ;
}
break;
case V_1016 :
case V_1017 :
case V_1018 :
case V_1019 :
if ( F_39 ( V_2 ) -> V_77 < 5 ) {
F_683 ( L_266 ,
F_684 ( V_835 -> V_247 ) ) ;
return - V_229 ;
}
break;
default:
F_683 ( L_266 ,
F_684 ( V_835 -> V_247 ) ) ;
return - V_229 ;
}
if ( V_835 -> V_916 [ 0 ] != 0 )
return - V_229 ;
V_1013 = F_18 ( V_2 ) ? 16 : 8 ;
V_1012 = F_529 ( V_835 -> V_811 ,
V_220 -> V_225 ? V_1013 : 1 ) ;
if ( V_220 -> V_108 . V_390 < V_1012 * V_835 -> V_269 [ 0 ] )
return - V_229 ;
F_685 ( & V_243 -> V_108 , V_835 ) ;
V_243 -> V_220 = V_220 ;
V_243 -> V_220 -> V_1011 ++ ;
V_224 = F_686 ( V_2 , & V_243 -> V_108 , & V_1020 ) ;
if ( V_224 ) {
F_115 ( L_267 , V_224 ) ;
return V_224 ;
}
return 0 ;
}
static struct V_241 *
F_687 ( struct V_1 * V_2 ,
struct V_807 * V_1021 ,
struct V_834 * V_835 )
{
struct V_219 * V_220 ;
V_220 = F_512 ( F_513 ( V_2 , V_1021 ,
V_835 -> V_1022 [ 0 ] ) ) ;
if ( & V_220 -> V_108 == NULL )
return F_524 ( - V_814 ) ;
return F_522 ( V_2 , V_835 , V_220 ) ;
}
static inline void F_688 ( struct V_1 * V_2 )
{
}
static void F_689 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_3 ( V_2 ) || F_15 ( V_2 ) )
V_4 -> V_273 . V_614 = F_26 ;
else if ( F_17 ( V_2 ) )
V_4 -> V_273 . V_614 = F_27 ;
else if ( F_16 ( V_2 ) )
V_4 -> V_273 . V_614 = F_25 ;
else
V_4 -> V_273 . V_614 = F_24 ;
if ( F_61 ( V_2 ) ) {
V_4 -> V_273 . V_944 = F_478 ;
V_4 -> V_273 . V_753 = F_475 ;
V_4 -> V_273 . V_454 = F_272 ;
V_4 -> V_273 . V_455 = F_279 ;
V_4 -> V_273 . V_459 = F_284 ;
V_4 -> V_273 . V_275 = F_166 ;
} else if ( F_3 ( V_2 ) ) {
V_4 -> V_273 . V_944 = F_434 ;
V_4 -> V_273 . V_753 = F_426 ;
V_4 -> V_273 . V_454 = F_260 ;
V_4 -> V_273 . V_455 = F_278 ;
V_4 -> V_273 . V_459 = F_283 ;
V_4 -> V_273 . V_275 = F_166 ;
} else if ( F_17 ( V_2 ) ) {
V_4 -> V_273 . V_944 = F_394 ;
V_4 -> V_273 . V_753 = F_389 ;
V_4 -> V_273 . V_454 = F_305 ;
V_4 -> V_273 . V_455 = F_308 ;
V_4 -> V_273 . V_459 = F_309 ;
V_4 -> V_273 . V_275 = F_160 ;
} else {
V_4 -> V_273 . V_944 = F_394 ;
V_4 -> V_273 . V_753 = F_389 ;
V_4 -> V_273 . V_454 = F_306 ;
V_4 -> V_273 . V_455 = F_308 ;
V_4 -> V_273 . V_459 = F_309 ;
V_4 -> V_273 . V_275 = F_160 ;
}
if ( F_17 ( V_2 ) )
V_4 -> V_273 . V_477 =
F_333 ;
else if ( F_380 ( V_2 ) || ( F_382 ( V_2 ) && ! F_690 ( V_2 ) ) )
V_4 -> V_273 . V_477 =
F_334 ;
else if ( F_332 ( V_2 ) )
V_4 -> V_273 . V_477 =
F_335 ;
else if ( F_381 ( V_2 ) || F_71 ( V_2 ) )
V_4 -> V_273 . V_477 =
F_336 ;
else if ( F_16 ( V_2 ) )
V_4 -> V_273 . V_477 =
F_337 ;
else if ( F_691 ( V_2 ) )
V_4 -> V_273 . V_477 =
F_339 ;
else if ( F_72 ( V_2 ) )
V_4 -> V_273 . V_477 =
F_340 ;
else if ( F_692 ( V_2 ) )
V_4 -> V_273 . V_477 =
F_341 ;
else
V_4 -> V_273 . V_477 =
F_342 ;
if ( F_3 ( V_2 ) ) {
if ( F_6 ( V_2 ) ) {
V_4 -> V_273 . V_367 = F_190 ;
V_4 -> V_273 . V_787 = F_491 ;
} else if ( F_198 ( V_2 ) ) {
V_4 -> V_273 . V_367 = F_196 ;
V_4 -> V_273 . V_787 = F_491 ;
} else if ( F_187 ( V_2 ) ) {
V_4 -> V_273 . V_367 = F_199 ;
V_4 -> V_273 . V_787 = F_491 ;
V_4 -> V_273 . V_951 =
F_189 ;
} else if ( F_167 ( V_2 ) || F_693 ( V_2 ) ) {
V_4 -> V_273 . V_367 = V_1023 ;
V_4 -> V_273 . V_787 = F_487 ;
V_4 -> V_273 . V_951 =
F_474 ;
}
} else if ( F_15 ( V_2 ) ) {
V_4 -> V_273 . V_787 = F_486 ;
} else if ( F_17 ( V_2 ) ) {
V_4 -> V_273 . V_951 =
F_304 ;
V_4 -> V_273 . V_787 = F_491 ;
}
V_4 -> V_273 . V_921 = F_585 ;
switch ( F_39 ( V_2 ) -> V_77 ) {
case 2 :
V_4 -> V_273 . V_921 = F_572 ;
break;
case 3 :
V_4 -> V_273 . V_921 = F_577 ;
break;
case 4 :
case 5 :
V_4 -> V_273 . V_921 = F_578 ;
break;
case 6 :
V_4 -> V_273 . V_921 = F_579 ;
break;
case 7 :
case 8 :
V_4 -> V_273 . V_921 = F_580 ;
break;
}
F_694 ( V_2 ) ;
}
static void F_695 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_138 |= V_139 ;
F_696 ( L_268 ) ;
}
static void F_697 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_138 |= V_518 ;
F_696 ( L_269 ) ;
}
static void F_698 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_138 |= V_1024 ;
F_696 ( L_270 ) ;
}
static int F_699 ( const struct V_1025 * V_197 )
{
F_696 ( L_271 , V_197 -> V_1026 ) ;
return 1 ;
}
static void F_700 ( struct V_1 * V_2 )
{
struct V_1027 * V_1028 = V_2 -> V_481 ;
int V_143 ;
for ( V_143 = 0 ; V_143 < F_200 ( V_1029 ) ; V_143 ++ ) {
struct V_1030 * V_1031 = & V_1029 [ V_143 ] ;
if ( V_1028 -> V_1032 == V_1031 -> V_1032 &&
( V_1028 -> V_1033 == V_1031 -> V_1033 ||
V_1031 -> V_1033 == V_1034 ) &&
( V_1028 -> V_1035 == V_1031 -> V_1035 ||
V_1031 -> V_1035 == V_1034 ) )
V_1031 -> V_1036 ( V_2 ) ;
}
for ( V_143 = 0 ; V_143 < F_200 ( V_1037 ) ; V_143 ++ ) {
if ( F_701 ( * V_1037 [ V_143 ] . V_1038 ) != 0 )
V_1037 [ V_143 ] . V_1036 ( V_2 ) ;
}
}
static void F_702 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_10 V_1039 ;
T_1 V_1040 = F_703 ( V_2 ) ;
F_704 ( V_2 -> V_481 , V_1041 ) ;
F_705 ( V_1042 , V_1043 ) ;
V_1039 = F_706 ( V_1044 ) ;
F_705 ( V_1039 | 1 << 5 , V_1044 ) ;
F_707 ( V_2 -> V_481 , V_1041 ) ;
F_114 ( 300 ) ;
F_40 ( V_1040 , V_1045 ) ;
F_113 ( V_1040 ) ;
}
void F_708 ( struct V_1 * V_2 )
{
F_456 ( V_2 ) ;
F_709 ( V_2 ) ;
F_107 ( V_2 ) ;
F_53 ( & V_2 -> V_290 ) ;
F_710 ( V_2 ) ;
F_55 ( & V_2 -> V_290 ) ;
}
void F_711 ( struct V_1 * V_2 )
{
F_712 ( V_2 ) ;
}
void F_713 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_143 , V_331 , V_224 ;
F_714 ( V_2 ) ;
V_2 -> V_626 . V_1046 = 0 ;
V_2 -> V_626 . V_1047 = 0 ;
V_2 -> V_626 . V_1048 = 24 ;
V_2 -> V_626 . V_1049 = 1 ;
V_2 -> V_626 . V_846 = & V_1050 ;
F_700 ( V_2 ) ;
F_715 ( V_2 ) ;
if ( F_39 ( V_2 ) -> V_289 == 0 )
return;
F_689 ( V_2 ) ;
if ( F_18 ( V_2 ) ) {
V_2 -> V_626 . V_1051 = 2048 ;
V_2 -> V_626 . V_1052 = 2048 ;
} else if ( F_716 ( V_2 ) ) {
V_2 -> V_626 . V_1051 = 4096 ;
V_2 -> V_626 . V_1052 = 4096 ;
} else {
V_2 -> V_626 . V_1051 = 8192 ;
V_2 -> V_626 . V_1052 = 8192 ;
}
V_2 -> V_626 . V_1053 = V_4 -> V_1054 . V_1055 ;
F_36 ( L_272 ,
F_39 ( V_2 ) -> V_289 ,
F_39 ( V_2 ) -> V_289 > 1 ? L_273 : L_274 ) ;
F_82 (i) {
F_648 ( V_2 , V_143 ) ;
for ( V_331 = 0 ; V_331 < V_4 -> V_147 ; V_331 ++ ) {
V_224 = F_717 ( V_2 , V_143 , V_331 ) ;
if ( V_224 )
F_36 ( L_275 ,
F_69 ( V_143 ) , F_85 ( V_143 , V_331 ) , V_224 ) ;
}
}
F_105 ( V_2 ) ;
F_107 ( V_2 ) ;
F_637 ( V_2 ) ;
F_647 ( V_2 ) ;
F_702 ( V_2 ) ;
F_661 ( V_2 ) ;
F_270 ( V_2 ) ;
}
static void
F_718 ( struct V_464 * V_457 )
{
V_457 -> V_108 . V_460 = V_461 ;
V_457 -> V_108 . V_23 = NULL ;
V_457 -> V_23 -> V_453 = false ;
V_457 -> V_23 -> V_108 . V_21 = NULL ;
}
static void F_719 ( struct V_1 * V_2 )
{
struct V_464 * V_457 ;
struct V_456 * V_1056 = NULL ;
struct V_841 V_845 ;
F_173 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_457 -> V_23 -> type == V_34 ) {
V_1056 = & V_457 -> V_108 ;
break;
}
}
if ( ! V_1056 )
return;
if ( F_536 ( V_1056 , NULL , & V_845 ) )
F_540 ( V_1056 , & V_845 ) ;
}
static bool
F_720 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_79 , V_101 ;
if ( F_39 ( V_2 ) -> V_289 == 1 )
return true ;
V_79 = F_79 ( ! V_21 -> V_141 ) ;
V_101 = F_4 ( V_79 ) ;
if ( ( V_101 & V_142 ) &&
( ! ! ( V_101 & V_145 ) == V_21 -> V_71 ) )
return false ;
return true ;
}
static void F_721 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_108 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_79 ;
V_79 = F_45 ( V_21 -> V_67 . V_73 ) ;
F_40 ( V_79 , F_4 ( V_79 ) & ~ V_1057 ) ;
if ( F_39 ( V_2 ) -> V_77 < 4 && ! F_720 ( V_21 ) ) {
struct V_464 * V_457 ;
bool V_141 ;
F_36 ( L_276 ,
V_21 -> V_108 . V_108 . V_197 ) ;
V_141 = V_21 -> V_141 ;
V_21 -> V_141 = ! V_141 ;
V_4 -> V_273 . V_455 ( & V_21 -> V_108 ) ;
V_21 -> V_141 = V_141 ;
F_173 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_457 -> V_23 -> V_108 . V_21 != & V_21 -> V_108 )
continue;
F_718 ( V_457 ) ;
}
F_2 ( V_21 -> V_65 ) ;
V_21 -> V_108 . V_99 = false ;
}
if ( V_4 -> V_138 & V_139 &&
V_21 -> V_71 == V_125 && ! V_21 -> V_65 ) {
F_719 ( V_2 ) ;
}
F_311 ( & V_21 -> V_108 ) ;
if ( V_21 -> V_65 != V_21 -> V_108 . V_99 ) {
struct V_22 * V_23 ;
F_36 ( L_277 ,
V_21 -> V_108 . V_108 . V_197 ,
V_21 -> V_108 . V_99 ? L_191 : L_192 ,
V_21 -> V_65 ? L_191 : L_192 ) ;
V_21 -> V_108 . V_99 = V_21 -> V_65 ;
F_2 ( V_21 -> V_65 ) ;
F_10 (dev, &crtc->base, encoder) {
F_2 ( V_23 -> V_453 ) ;
V_23 -> V_108 . V_21 = NULL ;
}
}
}
static void F_722 ( struct V_22 * V_23 )
{
struct V_464 * V_457 ;
struct V_1 * V_2 = V_23 -> V_108 . V_2 ;
bool V_1058 = V_23 -> V_108 . V_21 &&
F_30 ( V_23 -> V_108 . V_21 ) -> V_65 ;
if ( V_23 -> V_453 && ! V_1058 ) {
F_36 ( L_278 ,
V_23 -> V_108 . V_108 . V_197 ,
F_483 ( & V_23 -> V_108 ) ) ;
if ( V_23 -> V_108 . V_21 ) {
F_36 ( L_279 ,
V_23 -> V_108 . V_108 . V_197 ,
F_483 ( & V_23 -> V_108 ) ) ;
V_23 -> V_199 ( V_23 ) ;
}
F_173 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_457 -> V_23 != V_23 )
continue;
F_718 ( V_457 ) ;
}
}
}
void F_723 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_1040 = F_703 ( V_2 ) ;
if ( ( F_167 ( V_2 ) || F_168 ( V_2 ) ) &&
( F_4 ( V_685 ) & V_1059 ) == 0 )
return;
if ( ! ( F_4 ( V_1040 ) & V_1045 ) ) {
F_36 ( L_280 ) ;
F_702 ( V_2 ) ;
}
}
static void F_724 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_71 V_71 ;
struct V_64 * V_21 ;
struct V_22 * V_23 ;
struct V_464 * V_457 ;
int V_143 ;
F_173 (crtc, &dev->mode_config.crtc_list,
base.head) {
memset ( & V_21 -> V_67 , 0 , sizeof( V_21 -> V_67 ) ) ;
V_21 -> V_65 = V_4 -> V_273 . V_944 ( V_21 ,
& V_21 -> V_67 ) ;
V_21 -> V_108 . V_99 = V_21 -> V_65 ;
V_21 -> V_217 = V_21 -> V_65 ;
F_36 ( L_281 ,
V_21 -> V_108 . V_108 . V_197 ,
V_21 -> V_65 ? L_191 : L_192 ) ;
}
if ( F_61 ( V_2 ) )
F_725 ( V_2 ) ;
for ( V_143 = 0 ; V_143 < V_4 -> V_384 ; V_143 ++ ) {
struct V_107 * V_111 = & V_4 -> V_110 [ V_143 ] ;
V_111 -> V_196 = V_111 -> V_114 ( V_4 , V_111 , & V_111 -> V_113 ) ;
V_111 -> V_65 = 0 ;
F_173 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_21 -> V_65 && F_56 ( V_21 ) == V_111 )
V_111 -> V_65 ++ ;
}
V_111 -> V_195 = V_111 -> V_65 ;
F_36 ( L_282 ,
V_111 -> V_115 , V_111 -> V_195 , V_111 -> V_196 ) ;
}
F_173 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_71 = 0 ;
if ( V_23 -> V_114 ( V_23 , & V_71 ) ) {
V_21 = F_30 ( V_4 -> V_72 [ V_71 ] ) ;
V_23 -> V_108 . V_21 = & V_21 -> V_108 ;
V_23 -> V_945 ( V_23 , & V_21 -> V_67 ) ;
} else {
V_23 -> V_108 . V_21 = NULL ;
}
V_23 -> V_453 = false ;
F_36 ( L_283 ,
V_23 -> V_108 . V_108 . V_197 ,
F_483 ( & V_23 -> V_108 ) ,
V_23 -> V_108 . V_21 ? L_191 : L_192 ,
F_69 ( V_71 ) ) ;
}
F_173 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_457 -> V_114 ( V_457 ) ) {
V_457 -> V_108 . V_460 = V_463 ;
V_457 -> V_23 -> V_453 = true ;
V_457 -> V_108 . V_23 = & V_457 -> V_23 -> V_108 ;
} else {
V_457 -> V_108 . V_460 = V_461 ;
V_457 -> V_108 . V_23 = NULL ;
}
F_36 ( L_284 ,
V_457 -> V_108 . V_108 . V_197 ,
F_320 ( & V_457 -> V_108 ) ,
V_457 -> V_108 . V_23 ? L_191 : L_192 ) ;
}
}
void F_726 ( struct V_1 * V_2 ,
bool V_1060 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_71 V_71 ;
struct V_64 * V_21 ;
struct V_22 * V_23 ;
int V_143 ;
F_724 ( V_2 ) ;
F_173 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_21 -> V_65 && V_291 ) {
F_386 ( V_21 , & V_21 -> V_67 ) ;
F_36 ( L_285 ,
V_21 -> V_108 . V_108 . V_197 ) ;
F_600 ( & V_21 -> V_108 . V_377 ) ;
}
}
F_173 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_722 ( V_23 ) ;
}
F_82 (pipe) {
V_21 = F_30 ( V_4 -> V_72 [ V_71 ] ) ;
F_721 ( V_21 ) ;
F_598 ( V_21 , & V_21 -> V_67 , L_286 ) ;
}
for ( V_143 = 0 ; V_143 < V_4 -> V_384 ; V_143 ++ ) {
struct V_107 * V_111 = & V_4 -> V_110 [ V_143 ] ;
if ( ! V_111 -> V_196 || V_111 -> V_65 )
continue;
F_36 ( L_287 , V_111 -> V_115 ) ;
V_111 -> V_199 ( V_4 , V_111 ) ;
V_111 -> V_196 = false ;
}
if ( F_3 ( V_2 ) )
F_727 ( V_2 ) ;
if ( V_1060 ) {
F_723 ( V_2 ) ;
F_82 (pipe) {
struct V_20 * V_21 =
V_4 -> V_72 [ V_71 ] ;
F_621 ( V_21 , & V_21 -> V_377 , V_21 -> V_234 , V_21 -> V_235 ,
V_21 -> V_66 ) ;
}
} else {
F_593 ( V_2 ) ;
}
F_322 ( V_2 ) ;
}
void F_728 ( struct V_1 * V_2 )
{
F_708 ( V_2 ) ;
F_729 ( V_2 ) ;
F_53 ( & V_2 -> V_626 . V_276 ) ;
F_730 ( V_2 ) ;
F_726 ( V_2 , false ) ;
F_55 ( & V_2 -> V_626 . V_276 ) ;
}
void F_731 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_456 * V_457 ;
F_732 ( V_2 ) ;
F_556 ( & V_4 -> V_1061 ) ;
F_733 ( V_2 ) ;
F_53 ( & V_2 -> V_290 ) ;
F_734 () ;
F_173 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_21 -> V_66 )
continue;
F_171 ( V_21 ) ;
}
F_270 ( V_2 ) ;
F_735 ( V_2 ) ;
F_736 ( V_2 ) ;
F_55 ( & V_2 -> V_290 ) ;
F_737 () ;
F_173 (connector, &dev->mode_config.connector_list, head) {
F_738 ( V_457 ) ;
F_739 ( V_457 ) ;
}
F_740 ( V_2 ) ;
F_741 ( V_2 ) ;
}
struct V_462 * F_742 ( struct V_456 * V_457 )
{
return & F_501 ( V_457 ) -> V_108 ;
}
void F_743 ( struct V_464 * V_457 ,
struct V_22 * V_23 )
{
V_457 -> V_23 = V_23 ;
F_744 ( & V_457 -> V_108 ,
& V_23 -> V_108 ) ;
}
int F_745 ( struct V_1 * V_2 , bool V_100 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned V_79 = F_39 ( V_2 ) -> V_77 >= 6 ? V_1062 : V_1063 ;
T_5 V_1064 ;
F_338 ( V_4 -> V_1065 , V_79 , & V_1064 ) ;
if ( V_100 )
V_1064 &= ~ V_1066 ;
else
V_1064 |= V_1066 ;
F_746 ( V_4 -> V_1065 , V_79 , V_1064 ) ;
return 0 ;
}
struct V_1067 *
F_747 ( struct V_1 * V_2 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_1067 * error ;
int V_1068 [] = {
V_210 ,
V_1069 ,
V_1070 ,
V_588 ,
} ;
int V_143 ;
if ( F_39 ( V_2 ) -> V_289 == 0 )
return NULL ;
error = F_523 ( sizeof( * error ) , V_1071 ) ;
if ( error == NULL )
return NULL ;
if ( F_167 ( V_2 ) || F_168 ( V_2 ) )
error -> V_1072 = F_4 ( V_685 ) ;
F_82 (i) {
error -> V_71 [ V_143 ] . V_1073 =
F_748 ( V_2 , F_467 ( V_143 ) ) ;
if ( ! error -> V_71 [ V_143 ] . V_1073 )
continue;
if ( F_39 ( V_2 ) -> V_77 <= 6 || F_17 ( V_2 ) ) {
error -> V_1074 [ V_143 ] . V_421 = F_4 ( F_73 ( V_143 ) ) ;
error -> V_1074 [ V_143 ] . V_1075 = F_4 ( F_510 ( V_143 ) ) ;
error -> V_1074 [ V_143 ] . V_108 = F_4 ( F_289 ( V_143 ) ) ;
} else {
error -> V_1074 [ V_143 ] . V_421 = F_4 ( F_74 ( V_143 ) ) ;
error -> V_1074 [ V_143 ] . V_1075 = F_4 ( F_509 ( V_143 ) ) ;
error -> V_1074 [ V_143 ] . V_108 = F_4 ( F_508 ( V_143 ) ) ;
}
error -> V_141 [ V_143 ] . V_421 = F_4 ( F_79 ( V_143 ) ) ;
error -> V_141 [ V_143 ] . V_1015 = F_4 ( F_163 ( V_143 ) ) ;
if ( F_39 ( V_2 ) -> V_77 <= 3 ) {
error -> V_141 [ V_143 ] . V_390 = F_4 ( F_390 ( V_143 ) ) ;
error -> V_141 [ V_143 ] . V_389 = F_4 ( F_391 ( V_143 ) ) ;
}
if ( F_39 ( V_2 ) -> V_77 <= 7 && ! F_167 ( V_2 ) )
error -> V_141 [ V_143 ] . V_812 = F_4 ( F_144 ( V_143 ) ) ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
error -> V_141 [ V_143 ] . V_1076 = F_4 ( F_143 ( V_143 ) ) ;
error -> V_141 [ V_143 ] . V_1077 = F_4 ( F_164 ( V_143 ) ) ;
}
error -> V_71 [ V_143 ] . V_1078 = F_4 ( F_180 ( V_143 ) ) ;
}
error -> V_1079 = F_39 ( V_2 ) -> V_289 ;
if ( F_61 ( V_4 -> V_2 ) )
error -> V_1079 ++ ;
for ( V_143 = 0 ; V_143 < error -> V_1079 ; V_143 ++ ) {
enum V_70 V_73 = V_1068 [ V_143 ] ;
error -> V_70 [ V_143 ] . V_1073 =
F_748 ( V_2 ,
F_77 ( V_73 ) ) ;
if ( ! error -> V_70 [ V_143 ] . V_1073 )
continue;
error -> V_70 [ V_143 ] . V_73 = V_73 ;
error -> V_70 [ V_143 ] . V_1080 = F_4 ( F_45 ( V_73 ) ) ;
error -> V_70 [ V_143 ] . V_591 = F_4 ( F_222 ( V_73 ) ) ;
error -> V_70 [ V_143 ] . V_1081 = F_4 ( F_224 ( V_73 ) ) ;
error -> V_70 [ V_143 ] . V_873 = F_4 ( F_226 ( V_73 ) ) ;
error -> V_70 [ V_143 ] . V_593 = F_4 ( F_228 ( V_73 ) ) ;
error -> V_70 [ V_143 ] . V_1082 = F_4 ( F_230 ( V_73 ) ) ;
error -> V_70 [ V_143 ] . V_875 = F_4 ( F_232 ( V_73 ) ) ;
}
return error ;
}
void
F_749 ( struct V_1083 * V_11 ,
struct V_1 * V_2 ,
struct V_1067 * error )
{
int V_143 ;
if ( ! error )
return;
F_750 ( V_11 , L_288 , F_39 ( V_2 ) -> V_289 ) ;
if ( F_167 ( V_2 ) || F_168 ( V_2 ) )
F_750 ( V_11 , L_289 ,
error -> V_1072 ) ;
F_82 (i) {
F_750 ( V_11 , L_290 , V_143 ) ;
F_750 ( V_11 , L_291 ,
error -> V_71 [ V_143 ] . V_1073 ? L_12 : L_13 ) ;
F_750 ( V_11 , L_292 , error -> V_71 [ V_143 ] . V_1078 ) ;
F_750 ( V_11 , L_293 , V_143 ) ;
F_750 ( V_11 , L_294 , error -> V_141 [ V_143 ] . V_421 ) ;
F_750 ( V_11 , L_295 , error -> V_141 [ V_143 ] . V_1015 ) ;
if ( F_39 ( V_2 ) -> V_77 <= 3 ) {
F_750 ( V_11 , L_296 , error -> V_141 [ V_143 ] . V_390 ) ;
F_750 ( V_11 , L_297 , error -> V_141 [ V_143 ] . V_389 ) ;
}
if ( F_39 ( V_2 ) -> V_77 <= 7 && ! F_167 ( V_2 ) )
F_750 ( V_11 , L_298 , error -> V_141 [ V_143 ] . V_812 ) ;
if ( F_39 ( V_2 ) -> V_77 >= 4 ) {
F_750 ( V_11 , L_299 , error -> V_141 [ V_143 ] . V_1076 ) ;
F_750 ( V_11 , L_300 , error -> V_141 [ V_143 ] . V_1077 ) ;
}
F_750 ( V_11 , L_301 , V_143 ) ;
F_750 ( V_11 , L_294 , error -> V_1074 [ V_143 ] . V_421 ) ;
F_750 ( V_11 , L_297 , error -> V_1074 [ V_143 ] . V_1075 ) ;
F_750 ( V_11 , L_302 , error -> V_1074 [ V_143 ] . V_108 ) ;
}
for ( V_143 = 0 ; V_143 < error -> V_1079 ; V_143 ++ ) {
F_750 ( V_11 , L_303 ,
F_599 ( error -> V_70 [ V_143 ] . V_73 ) ) ;
F_750 ( V_11 , L_291 ,
error -> V_70 [ V_143 ] . V_1073 ? L_12 : L_13 ) ;
F_750 ( V_11 , L_304 , error -> V_70 [ V_143 ] . V_1080 ) ;
F_750 ( V_11 , L_305 , error -> V_70 [ V_143 ] . V_591 ) ;
F_750 ( V_11 , L_306 , error -> V_70 [ V_143 ] . V_1081 ) ;
F_750 ( V_11 , L_307 , error -> V_70 [ V_143 ] . V_873 ) ;
F_750 ( V_11 , L_308 , error -> V_70 [ V_143 ] . V_593 ) ;
F_750 ( V_11 , L_309 , error -> V_70 [ V_143 ] . V_1082 ) ;
F_750 ( V_11 , L_310 , error -> V_70 [ V_143 ] . V_875 ) ;
}
}
