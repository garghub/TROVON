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
return V_64 -> V_65 && V_21 -> V_66 -> V_67 &&
V_64 -> V_68 . V_69 . V_70 ;
}
enum V_71 F_31 ( struct V_3 * V_4 ,
enum V_72 V_72 )
{
struct V_20 * V_21 = V_4 -> V_73 [ V_72 ] ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
return V_64 -> V_68 . V_74 ;
}
static void F_32 ( struct V_1 * V_2 , int V_72 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_75 , V_76 = F_33 ( V_72 ) ;
V_75 = F_4 ( V_76 ) ;
if ( F_34 ( F_35 ( V_76 ) != V_75 , 50 ) )
F_36 ( L_10 ) ;
}
void F_37 ( struct V_1 * V_2 , int V_72 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_77 = F_38 ( V_72 ) ;
if ( F_15 ( V_2 ) || F_39 ( V_2 ) -> V_78 >= 5 ) {
F_32 ( V_2 , V_72 ) ;
return;
}
F_40 ( V_77 ,
F_4 ( V_77 ) | V_79 ) ;
if ( F_34 ( F_4 ( V_77 ) &
V_79 ,
50 ) )
F_36 ( L_10 ) ;
}
static bool F_41 ( struct V_1 * V_2 , enum V_72 V_72 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_80 = F_42 ( V_72 ) ;
T_1 V_81 , V_82 ;
T_1 V_83 ;
if ( F_18 ( V_2 ) )
V_83 = V_84 ;
else
V_83 = V_85 ;
V_81 = F_4 ( V_80 ) & V_83 ;
F_43 ( 5 ) ;
V_82 = F_4 ( V_80 ) & V_83 ;
return V_81 == V_82 ;
}
void F_44 ( struct V_1 * V_2 , int V_72 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_71 V_74 = F_31 ( V_4 ,
V_72 ) ;
if ( F_39 ( V_2 ) -> V_78 >= 4 ) {
int V_80 = F_45 ( V_74 ) ;
if ( F_34 ( ( F_4 ( V_80 ) & V_86 ) == 0 ,
100 ) )
F_46 ( 1 , L_11 ) ;
} else {
if ( F_34 ( F_41 ( V_2 , V_72 ) , 100 ) )
F_46 ( 1 , L_11 ) ;
}
}
bool F_47 ( struct V_3 * V_4 ,
struct V_87 * V_88 )
{
T_1 V_89 ;
if ( F_48 ( V_4 -> V_2 ) ) {
switch( V_88 -> V_88 ) {
case V_90 :
V_89 = V_91 ;
break;
case V_92 :
V_89 = V_93 ;
break;
case V_94 :
V_89 = V_95 ;
break;
default:
return true ;
}
} else {
switch( V_88 -> V_88 ) {
case V_90 :
V_89 = V_96 ;
break;
case V_92 :
V_89 = V_97 ;
break;
case V_94 :
V_89 = V_98 ;
break;
default:
return true ;
}
}
return F_4 ( V_99 ) & V_89 ;
}
static const char * F_49 ( bool V_100 )
{
return V_100 ? L_12 : L_13 ;
}
void F_50 ( struct V_3 * V_4 ,
enum V_72 V_72 , bool V_101 )
{
int V_80 ;
T_1 V_102 ;
bool V_103 ;
V_80 = F_51 ( V_72 ) ;
V_102 = F_4 ( V_80 ) ;
V_103 = ! ! ( V_102 & V_104 ) ;
F_46 ( V_103 != V_101 ,
L_14 ,
F_49 ( V_101 ) , F_49 ( V_103 ) ) ;
}
static void F_52 ( struct V_3 * V_4 , bool V_101 )
{
T_1 V_102 ;
bool V_103 ;
F_53 ( & V_4 -> V_105 ) ;
V_102 = F_54 ( V_4 , V_106 ) ;
F_55 ( & V_4 -> V_105 ) ;
V_103 = V_102 & V_107 ;
F_46 ( V_103 != V_101 ,
L_15 ,
F_49 ( V_101 ) , F_49 ( V_103 ) ) ;
}
struct V_108 *
F_56 ( struct V_64 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_109 . V_2 -> V_5 ;
if ( V_21 -> V_68 . V_110 < 0 )
return NULL ;
return & V_4 -> V_111 [ V_21 -> V_68 . V_110 ] ;
}
void F_57 ( struct V_3 * V_4 ,
struct V_108 * V_112 ,
bool V_101 )
{
bool V_103 ;
struct V_113 V_114 ;
if ( F_58 ( V_4 -> V_2 ) ) {
F_59 ( L_16 ) ;
return;
}
if ( F_46 ( ! V_112 ,
L_17 , F_49 ( V_101 ) ) )
return;
V_103 = V_112 -> V_115 ( V_4 , V_112 , & V_114 ) ;
F_46 ( V_103 != V_101 ,
L_18 ,
V_112 -> V_116 , F_49 ( V_101 ) , F_49 ( V_103 ) ) ;
}
static void F_60 ( struct V_3 * V_4 ,
enum V_72 V_72 , bool V_101 )
{
int V_80 ;
T_1 V_102 ;
bool V_103 ;
enum V_71 V_74 = F_31 ( V_4 ,
V_72 ) ;
if ( F_61 ( V_4 -> V_2 ) ) {
V_80 = F_62 ( V_74 ) ;
V_102 = F_4 ( V_80 ) ;
V_103 = ! ! ( V_102 & V_117 ) ;
} else {
V_80 = F_63 ( V_72 ) ;
V_102 = F_4 ( V_80 ) ;
V_103 = ! ! ( V_102 & V_118 ) ;
}
F_46 ( V_103 != V_101 ,
L_19 ,
F_49 ( V_101 ) , F_49 ( V_103 ) ) ;
}
static void F_64 ( struct V_3 * V_4 ,
enum V_72 V_72 , bool V_101 )
{
int V_80 ;
T_1 V_102 ;
bool V_103 ;
V_80 = F_65 ( V_72 ) ;
V_102 = F_4 ( V_80 ) ;
V_103 = ! ! ( V_102 & V_119 ) ;
F_46 ( V_103 != V_101 ,
L_20 ,
F_49 ( V_101 ) , F_49 ( V_103 ) ) ;
}
static void F_66 ( struct V_3 * V_4 ,
enum V_72 V_72 )
{
int V_80 ;
T_1 V_102 ;
if ( F_39 ( V_4 -> V_2 ) -> V_78 == 5 )
return;
if ( F_61 ( V_4 -> V_2 ) )
return;
V_80 = F_63 ( V_72 ) ;
V_102 = F_4 ( V_80 ) ;
F_46 ( ! ( V_102 & V_120 ) , L_21 ) ;
}
void F_67 ( struct V_3 * V_4 ,
enum V_72 V_72 , bool V_101 )
{
int V_80 ;
T_1 V_102 ;
bool V_103 ;
V_80 = F_65 ( V_72 ) ;
V_102 = F_4 ( V_80 ) ;
V_103 = ! ! ( V_102 & V_121 ) ;
F_46 ( V_103 != V_101 ,
L_22 ,
F_49 ( V_101 ) , F_49 ( V_103 ) ) ;
}
static void F_68 ( struct V_3 * V_4 ,
enum V_72 V_72 )
{
int V_122 , V_123 ;
T_1 V_102 ;
enum V_72 V_124 = V_125 ;
bool V_126 = true ;
if ( F_3 ( V_4 -> V_2 ) ) {
V_122 = V_127 ;
V_123 = V_128 ;
} else {
V_122 = V_129 ;
V_123 = V_130 ;
}
V_102 = F_4 ( V_122 ) ;
if ( ! ( V_102 & V_131 ) ||
( ( V_102 & V_132 ) == V_132 ) )
V_126 = false ;
if ( F_4 ( V_123 ) & V_133 )
V_124 = V_134 ;
F_46 ( V_124 == V_72 && V_126 ,
L_23 ,
F_69 ( V_72 ) ) ;
}
static void F_70 ( struct V_3 * V_4 ,
enum V_72 V_72 , bool V_101 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
bool V_103 ;
if ( F_71 ( V_2 ) || F_72 ( V_2 ) )
V_103 = F_4 ( V_135 ) & V_136 ;
else if ( F_39 ( V_2 ) -> V_78 <= 6 || F_17 ( V_2 ) )
V_103 = F_4 ( F_73 ( V_72 ) ) & V_137 ;
else
V_103 = F_4 ( F_74 ( V_72 ) ) & V_137 ;
F_46 ( V_103 != V_101 ,
L_24 ,
F_69 ( V_72 ) , F_49 ( V_101 ) , F_49 ( V_103 ) ) ;
}
void F_75 ( struct V_3 * V_4 ,
enum V_72 V_72 , bool V_101 )
{
int V_80 ;
T_1 V_102 ;
bool V_103 ;
enum V_71 V_74 = F_31 ( V_4 ,
V_72 ) ;
if ( V_72 == V_125 && V_4 -> V_138 & V_139 )
V_101 = true ;
if ( ! F_76 ( V_4 ,
F_77 ( V_74 ) ) ) {
V_103 = false ;
} else {
V_80 = F_45 ( V_74 ) ;
V_102 = F_4 ( V_80 ) ;
V_103 = ! ! ( V_102 & V_140 ) ;
}
F_46 ( V_103 != V_101 ,
L_25 ,
F_69 ( V_72 ) , F_49 ( V_101 ) , F_49 ( V_103 ) ) ;
}
static void F_78 ( struct V_3 * V_4 ,
enum V_141 V_141 , bool V_101 )
{
int V_80 ;
T_1 V_102 ;
bool V_103 ;
V_80 = F_79 ( V_141 ) ;
V_102 = F_4 ( V_80 ) ;
V_103 = ! ! ( V_102 & V_142 ) ;
F_46 ( V_103 != V_101 ,
L_26 ,
F_80 ( V_141 ) , F_49 ( V_101 ) , F_49 ( V_103 ) ) ;
}
static void F_81 ( struct V_3 * V_4 ,
enum V_72 V_72 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_80 , V_143 ;
T_1 V_102 ;
int V_144 ;
if ( F_39 ( V_2 ) -> V_78 >= 4 ) {
V_80 = F_79 ( V_72 ) ;
V_102 = F_4 ( V_80 ) ;
F_46 ( V_102 & V_142 ,
L_27 ,
F_80 ( V_72 ) ) ;
return;
}
F_82 (i) {
V_80 = F_79 ( V_143 ) ;
V_102 = F_4 ( V_80 ) ;
V_144 = ( V_102 & V_145 ) >>
V_146 ;
F_46 ( ( V_102 & V_142 ) && V_72 == V_144 ,
L_28 ,
F_80 ( V_143 ) , F_69 ( V_72 ) ) ;
}
}
static void F_83 ( struct V_3 * V_4 ,
enum V_72 V_72 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_80 , V_147 ;
T_1 V_102 ;
if ( F_17 ( V_2 ) ) {
F_84 (pipe, sprite) {
V_80 = F_85 ( V_72 , V_147 ) ;
V_102 = F_4 ( V_80 ) ;
F_46 ( V_102 & V_148 ,
L_29 ,
F_86 ( V_72 , V_147 ) , F_69 ( V_72 ) ) ;
}
} else if ( F_39 ( V_2 ) -> V_78 >= 7 ) {
V_80 = F_87 ( V_72 ) ;
V_102 = F_4 ( V_80 ) ;
F_46 ( V_102 & V_149 ,
L_29 ,
F_80 ( V_72 ) , F_69 ( V_72 ) ) ;
} else if ( F_39 ( V_2 ) -> V_78 >= 5 ) {
V_80 = F_88 ( V_72 ) ;
V_102 = F_4 ( V_80 ) ;
F_46 ( V_102 & V_150 ,
L_29 ,
F_80 ( V_72 ) , F_69 ( V_72 ) ) ;
}
}
static void F_89 ( struct V_3 * V_4 )
{
T_1 V_102 ;
bool V_100 ;
F_2 ( ! ( F_48 ( V_4 -> V_2 ) || F_90 ( V_4 -> V_2 ) ) ) ;
V_102 = F_4 ( V_151 ) ;
V_100 = ! ! ( V_102 & ( V_152 | V_153 |
V_154 ) ) ;
F_46 ( ! V_100 , L_30 ) ;
}
static void F_91 ( struct V_3 * V_4 ,
enum V_72 V_72 )
{
int V_80 ;
T_1 V_102 ;
bool V_100 ;
V_80 = F_92 ( V_72 ) ;
V_102 = F_4 ( V_80 ) ;
V_100 = ! ! ( V_102 & V_155 ) ;
F_46 ( V_100 ,
L_31 ,
F_69 ( V_72 ) ) ;
}
static bool F_93 ( struct V_3 * V_4 ,
enum V_72 V_72 , T_1 V_156 , T_1 V_102 )
{
if ( ( V_102 & V_157 ) == 0 )
return false ;
if ( F_90 ( V_4 -> V_2 ) ) {
T_1 V_158 = F_94 ( V_72 ) ;
T_1 V_159 = F_4 ( V_158 ) ;
if ( ( V_159 & V_160 ) != V_156 )
return false ;
} else {
if ( ( V_102 & V_161 ) != ( V_72 << 30 ) )
return false ;
}
return true ;
}
static bool F_95 ( struct V_3 * V_4 ,
enum V_72 V_72 , T_1 V_102 )
{
if ( ( V_102 & V_162 ) == 0 )
return false ;
if ( F_90 ( V_4 -> V_2 ) ) {
if ( ( V_102 & V_163 ) != F_96 ( V_72 ) )
return false ;
} else {
if ( ( V_102 & V_164 ) != F_97 ( V_72 ) )
return false ;
}
return true ;
}
static bool F_98 ( struct V_3 * V_4 ,
enum V_72 V_72 , T_1 V_102 )
{
if ( ( V_102 & V_165 ) == 0 )
return false ;
if ( F_90 ( V_4 -> V_2 ) ) {
if ( ( V_102 & V_166 ) != F_99 ( V_72 ) )
return false ;
} else {
if ( ( V_102 & V_167 ) != F_100 ( V_72 ) )
return false ;
}
return true ;
}
static bool F_101 ( struct V_3 * V_4 ,
enum V_72 V_72 , T_1 V_102 )
{
if ( ( V_102 & V_168 ) == 0 )
return false ;
if ( F_90 ( V_4 -> V_2 ) ) {
if ( ( V_102 & V_166 ) != F_99 ( V_72 ) )
return false ;
} else {
if ( ( V_102 & V_169 ) != F_102 ( V_72 ) )
return false ;
}
return true ;
}
static void F_103 ( struct V_3 * V_4 ,
enum V_72 V_72 , int V_80 , T_1 V_156 )
{
T_1 V_102 = F_4 ( V_80 ) ;
F_46 ( F_93 ( V_4 , V_72 , V_156 , V_102 ) ,
L_32 ,
V_80 , F_69 ( V_72 ) ) ;
F_46 ( F_48 ( V_4 -> V_2 ) && ( V_102 & V_157 ) == 0
&& ( V_102 & V_170 ) ,
L_33 ) ;
}
static void F_104 ( struct V_3 * V_4 ,
enum V_72 V_72 , int V_80 )
{
T_1 V_102 = F_4 ( V_80 ) ;
F_46 ( F_95 ( V_4 , V_72 , V_102 ) ,
L_34 ,
V_80 , F_69 ( V_72 ) ) ;
F_46 ( F_48 ( V_4 -> V_2 ) && ( V_102 & V_162 ) == 0
&& ( V_102 & V_171 ) ,
L_35 ) ;
}
static void F_105 ( struct V_3 * V_4 ,
enum V_72 V_72 )
{
int V_80 ;
T_1 V_102 ;
F_103 ( V_4 , V_72 , V_172 , V_173 ) ;
F_103 ( V_4 , V_72 , V_174 , V_175 ) ;
F_103 ( V_4 , V_72 , V_176 , V_177 ) ;
V_80 = V_178 ;
V_102 = F_4 ( V_80 ) ;
F_46 ( F_101 ( V_4 , V_72 , V_102 ) ,
L_36 ,
F_69 ( V_72 ) ) ;
V_80 = V_128 ;
V_102 = F_4 ( V_80 ) ;
F_46 ( F_98 ( V_4 , V_72 , V_102 ) ,
L_37 ,
F_69 ( V_72 ) ) ;
F_104 ( V_4 , V_72 , V_179 ) ;
F_104 ( V_4 , V_72 , V_180 ) ;
F_104 ( V_4 , V_72 , V_181 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_17 ( V_2 ) )
return;
F_107 ( V_182 ) = V_183 ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_17 ( V_2 ) )
return;
F_40 ( F_51 ( V_134 ) , F_4 ( F_51 ( V_134 ) ) |
V_184 |
V_185 ) ;
F_40 ( V_186 , F_4 ( V_186 ) | V_187 ) ;
}
static void F_109 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_80 = F_51 ( V_21 -> V_72 ) ;
T_1 V_47 = V_21 -> V_68 . V_188 . V_47 ;
F_110 ( V_4 , V_21 -> V_72 ) ;
F_111 ( ! F_17 ( V_4 -> V_2 ) ) ;
if ( F_112 ( V_4 -> V_2 ) && ! F_113 ( V_4 -> V_2 ) )
F_68 ( V_4 , V_21 -> V_72 ) ;
F_40 ( V_80 , V_47 ) ;
F_114 ( V_80 ) ;
F_115 ( 150 ) ;
if ( F_34 ( ( ( F_4 ( V_80 ) & V_189 ) == V_189 ) , 1 ) )
F_116 ( L_38 , V_21 -> V_72 ) ;
F_40 ( F_117 ( V_21 -> V_72 ) , V_21 -> V_68 . V_188 . V_190 ) ;
F_114 ( F_117 ( V_21 -> V_72 ) ) ;
F_40 ( V_80 , V_47 ) ;
F_114 ( V_80 ) ;
F_115 ( 150 ) ;
F_40 ( V_80 , V_47 ) ;
F_114 ( V_80 ) ;
F_115 ( 150 ) ;
F_40 ( V_80 , V_47 ) ;
F_114 ( V_80 ) ;
F_115 ( 150 ) ;
}
static void F_118 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_80 = F_51 ( V_21 -> V_72 ) ;
T_1 V_47 = V_21 -> V_68 . V_188 . V_47 ;
F_110 ( V_4 , V_21 -> V_72 ) ;
F_111 ( F_39 ( V_2 ) -> V_78 >= 5 ) ;
if ( F_112 ( V_2 ) && ! F_113 ( V_2 ) )
F_68 ( V_4 , V_21 -> V_72 ) ;
F_40 ( V_80 , V_47 ) ;
F_114 ( V_80 ) ;
F_115 ( 150 ) ;
if ( F_39 ( V_2 ) -> V_78 >= 4 ) {
F_40 ( F_117 ( V_21 -> V_72 ) ,
V_21 -> V_68 . V_188 . V_190 ) ;
} else {
F_40 ( V_80 , V_47 ) ;
}
F_40 ( V_80 , V_47 ) ;
F_114 ( V_80 ) ;
F_115 ( 150 ) ;
F_40 ( V_80 , V_47 ) ;
F_114 ( V_80 ) ;
F_115 ( 150 ) ;
F_40 ( V_80 , V_47 ) ;
F_114 ( V_80 ) ;
F_115 ( 150 ) ;
}
static void F_119 ( struct V_3 * V_4 , enum V_72 V_72 )
{
if ( V_72 == V_125 && ( V_4 -> V_138 & V_139 ) )
return;
F_110 ( V_4 , V_72 ) ;
F_40 ( F_51 ( V_72 ) , 0 ) ;
F_114 ( F_51 ( V_72 ) ) ;
}
static void F_120 ( struct V_3 * V_4 , enum V_72 V_72 )
{
T_1 V_102 = 0 ;
F_110 ( V_4 , V_72 ) ;
if ( V_72 == V_134 )
V_102 = V_185 | V_184 ;
F_40 ( F_51 ( V_72 ) , V_102 ) ;
F_114 ( F_51 ( V_72 ) ) ;
}
void F_121 ( struct V_3 * V_4 ,
struct V_87 * V_191 )
{
T_1 V_192 ;
switch ( V_191 -> V_88 ) {
case V_90 :
V_192 = V_193 ;
break;
case V_92 :
V_192 = V_194 ;
break;
default:
F_122 () ;
}
if ( F_34 ( ( F_4 ( F_51 ( 0 ) ) & V_192 ) == 0 , 1000 ) )
F_46 ( 1 , L_39 ,
F_123 ( V_191 -> V_88 ) , F_4 ( F_51 ( 0 ) ) ) ;
}
static void F_124 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_112 = F_56 ( V_21 ) ;
F_111 ( F_39 ( V_2 ) -> V_78 < 5 ) ;
if ( F_2 ( V_112 == NULL ) )
return;
if ( F_2 ( V_112 -> V_195 == 0 ) )
return;
F_36 ( L_40 ,
V_112 -> V_116 , V_112 -> V_65 , V_112 -> V_196 ,
V_21 -> V_109 . V_109 . V_197 ) ;
if ( V_112 -> V_65 ++ ) {
F_2 ( ! V_112 -> V_196 ) ;
F_125 ( V_4 , V_112 ) ;
return;
}
F_2 ( V_112 -> V_196 ) ;
F_36 ( L_41 , V_112 -> V_116 ) ;
V_112 -> V_198 ( V_4 , V_112 ) ;
V_112 -> V_196 = true ;
}
static void F_126 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_112 = F_56 ( V_21 ) ;
F_111 ( F_39 ( V_2 ) -> V_78 < 5 ) ;
if ( F_2 ( V_112 == NULL ) )
return;
if ( F_2 ( V_112 -> V_195 == 0 ) )
return;
F_36 ( L_42 ,
V_112 -> V_116 , V_112 -> V_65 , V_112 -> V_196 ,
V_21 -> V_109 . V_109 . V_197 ) ;
if ( F_2 ( V_112 -> V_65 == 0 ) ) {
F_127 ( V_4 , V_112 ) ;
return;
}
F_125 ( V_4 , V_112 ) ;
F_2 ( ! V_112 -> V_196 ) ;
if ( -- V_112 -> V_65 )
return;
F_36 ( L_43 , V_112 -> V_116 ) ;
V_112 -> V_199 ( V_4 , V_112 ) ;
V_112 -> V_196 = false ;
}
static void F_128 ( struct V_3 * V_4 ,
enum V_72 V_72 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_20 * V_21 = V_4 -> V_73 [ V_72 ] ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
T_4 V_80 , V_102 , V_200 ;
F_111 ( F_39 ( V_2 ) -> V_78 < 5 ) ;
F_125 ( V_4 ,
F_56 ( V_64 ) ) ;
F_129 ( V_4 , V_72 ) ;
F_130 ( V_4 , V_72 ) ;
if ( F_90 ( V_2 ) ) {
V_80 = F_131 ( V_72 ) ;
V_102 = F_4 ( V_80 ) ;
V_102 |= V_201 ;
F_40 ( V_80 , V_102 ) ;
}
V_80 = F_92 ( V_72 ) ;
V_102 = F_4 ( V_80 ) ;
V_200 = F_4 ( F_45 ( V_72 ) ) ;
if ( F_48 ( V_4 -> V_2 ) ) {
V_102 &= ~ V_202 ;
V_102 |= V_200 & V_202 ;
}
V_102 &= ~ V_203 ;
if ( ( V_200 & V_204 ) == V_205 )
if ( F_48 ( V_4 -> V_2 ) &&
F_9 ( V_21 , V_36 ) )
V_102 |= V_206 ;
else
V_102 |= V_207 ;
else
V_102 |= V_208 ;
F_40 ( V_80 , V_102 | V_155 ) ;
if ( F_34 ( F_4 ( V_80 ) & V_209 , 100 ) )
F_116 ( L_44 , F_69 ( V_72 ) ) ;
}
static void F_132 ( struct V_3 * V_4 ,
enum V_71 V_74 )
{
T_1 V_102 , V_200 ;
F_111 ( F_39 ( V_4 -> V_2 ) -> V_78 < 5 ) ;
F_129 ( V_4 , (enum V_72 ) V_74 ) ;
F_130 ( V_4 , V_210 ) ;
V_102 = F_4 ( V_211 ) ;
V_102 |= V_201 ;
F_40 ( V_211 , V_102 ) ;
V_102 = V_155 ;
V_200 = F_4 ( F_45 ( V_74 ) ) ;
if ( ( V_200 & V_212 ) ==
V_205 )
V_102 |= V_207 ;
else
V_102 |= V_208 ;
F_40 ( V_213 , V_102 ) ;
if ( F_34 ( F_4 ( V_213 ) & V_209 , 100 ) )
F_116 ( L_45 ) ;
}
static void F_133 ( struct V_3 * V_4 ,
enum V_72 V_72 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_80 , V_102 ;
F_134 ( V_4 , V_72 ) ;
F_135 ( V_4 , V_72 ) ;
F_105 ( V_4 , V_72 ) ;
V_80 = F_92 ( V_72 ) ;
V_102 = F_4 ( V_80 ) ;
V_102 &= ~ V_155 ;
F_40 ( V_80 , V_102 ) ;
if ( F_34 ( ( F_4 ( V_80 ) & V_209 ) == 0 , 50 ) )
F_116 ( L_46 , F_69 ( V_72 ) ) ;
if ( ! F_48 ( V_2 ) ) {
V_80 = F_131 ( V_72 ) ;
V_102 = F_4 ( V_80 ) ;
V_102 &= ~ V_201 ;
F_40 ( V_80 , V_102 ) ;
}
}
static void F_136 ( struct V_3 * V_4 )
{
T_1 V_102 ;
V_102 = F_4 ( V_213 ) ;
V_102 &= ~ V_155 ;
F_40 ( V_213 , V_102 ) ;
if ( F_34 ( ( F_4 ( V_213 ) & V_209 ) == 0 , 50 ) )
F_116 ( L_47 ) ;
V_102 = F_4 ( V_211 ) ;
V_102 &= ~ V_201 ;
F_40 ( V_211 , V_102 ) ;
}
static void F_137 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_72 V_72 = V_21 -> V_72 ;
enum V_71 V_74 = F_31 ( V_4 ,
V_72 ) ;
enum V_72 V_214 ;
int V_80 ;
T_1 V_102 ;
F_81 ( V_4 , V_72 ) ;
F_138 ( V_4 , V_72 ) ;
F_83 ( V_4 , V_72 ) ;
if ( F_58 ( V_4 -> V_2 ) )
V_214 = V_210 ;
else
V_214 = V_72 ;
if ( ! F_3 ( V_4 -> V_2 ) )
if ( F_9 ( & V_21 -> V_109 , V_215 ) )
F_139 ( V_4 ) ;
else
F_140 ( V_4 , V_72 ) ;
else {
if ( V_21 -> V_68 . V_216 ) {
F_141 ( V_4 , V_214 ) ;
F_66 ( V_4 ,
(enum V_72 ) V_74 ) ;
}
}
V_80 = F_45 ( V_74 ) ;
V_102 = F_4 ( V_80 ) ;
if ( V_102 & V_140 ) {
F_2 ( ! ( V_72 == V_125 &&
V_4 -> V_138 & V_139 ) ) ;
return;
}
F_40 ( V_80 , V_102 | V_140 ) ;
F_114 ( V_80 ) ;
if ( F_39 ( V_2 ) -> V_78 <= 7 && ! F_142 ( V_2 ) )
F_37 ( V_4 -> V_2 , V_72 ) ;
}
static void F_143 ( struct V_3 * V_4 ,
enum V_72 V_72 )
{
enum V_71 V_74 = F_31 ( V_4 ,
V_72 ) ;
int V_80 ;
T_1 V_102 ;
F_81 ( V_4 , V_72 ) ;
F_138 ( V_4 , V_72 ) ;
F_83 ( V_4 , V_72 ) ;
if ( V_72 == V_125 && ( V_4 -> V_138 & V_139 ) )
return;
V_80 = F_45 ( V_74 ) ;
V_102 = F_4 ( V_80 ) ;
if ( ( V_102 & V_140 ) == 0 )
return;
F_40 ( V_80 , V_102 & ~ V_140 ) ;
F_44 ( V_4 -> V_2 , V_72 ) ;
}
void F_144 ( struct V_3 * V_4 ,
enum V_141 V_141 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_80 = F_39 ( V_2 ) -> V_78 >= 4 ? F_145 ( V_141 ) : F_146 ( V_141 ) ;
F_40 ( V_80 , F_4 ( V_80 ) ) ;
F_114 ( V_80 ) ;
}
static void F_147 ( struct V_3 * V_4 ,
enum V_141 V_141 , enum V_72 V_72 )
{
struct V_64 * V_64 =
F_30 ( V_4 -> V_73 [ V_72 ] ) ;
int V_80 ;
T_1 V_102 ;
F_148 ( V_4 , V_72 ) ;
F_46 ( V_64 -> V_217 , L_48 ) ;
V_64 -> V_217 = true ;
V_80 = F_79 ( V_141 ) ;
V_102 = F_4 ( V_80 ) ;
if ( V_102 & V_142 )
return;
F_40 ( V_80 , V_102 | V_142 ) ;
F_144 ( V_4 , V_141 ) ;
F_37 ( V_4 -> V_2 , V_72 ) ;
}
static void F_149 ( struct V_3 * V_4 ,
enum V_141 V_141 , enum V_72 V_72 )
{
struct V_64 * V_64 =
F_30 ( V_4 -> V_73 [ V_72 ] ) ;
int V_80 ;
T_1 V_102 ;
F_46 ( ! V_64 -> V_217 , L_49 ) ;
V_64 -> V_217 = false ;
V_80 = F_79 ( V_141 ) ;
V_102 = F_4 ( V_80 ) ;
if ( ( V_102 & V_142 ) == 0 )
return;
F_40 ( V_80 , V_102 & ~ V_142 ) ;
F_144 ( V_4 , V_141 ) ;
F_37 ( V_4 -> V_2 , V_72 ) ;
}
static bool F_150 ( struct V_1 * V_2 )
{
#ifdef F_151
if ( F_39 ( V_2 ) -> V_78 >= 6 && V_218 )
return true ;
#endif
return false ;
}
static int F_152 ( struct V_1 * V_2 , int V_219 , bool V_220 )
{
int V_221 ;
V_221 = V_220 ? ( F_18 ( V_2 ) ? 16 : 8 ) : 1 ;
return F_153 ( V_219 , V_221 ) ;
}
int
F_154 ( struct V_1 * V_2 ,
struct V_222 * V_223 ,
struct V_224 * V_225 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_226 ;
int V_227 ;
switch ( V_223 -> V_228 ) {
case V_229 :
if ( F_155 ( V_2 ) || F_156 ( V_2 ) )
V_226 = 128 * 1024 ;
else if ( F_39 ( V_2 ) -> V_78 >= 4 )
V_226 = 4 * 1024 ;
else
V_226 = 64 * 1024 ;
break;
case V_230 :
V_226 = 0 ;
break;
case V_231 :
F_46 ( 1 , L_50 ) ;
return - V_232 ;
default:
F_122 () ;
}
if ( F_150 ( V_2 ) && V_226 < 256 * 1024 )
V_226 = 256 * 1024 ;
V_4 -> V_233 . V_234 = false ;
V_227 = F_157 ( V_223 , V_226 , V_225 ) ;
if ( V_227 )
goto V_235;
V_227 = F_158 ( V_223 ) ;
if ( V_227 )
goto V_236;
F_159 ( V_223 ) ;
V_4 -> V_233 . V_234 = true ;
return 0 ;
V_236:
F_160 ( V_223 ) ;
V_235:
V_4 -> V_233 . V_234 = true ;
return V_227 ;
}
void F_161 ( struct V_222 * V_223 )
{
F_162 ( V_223 ) ;
F_160 ( V_223 ) ;
}
unsigned long F_163 ( int * V_237 , int * V_238 ,
unsigned int V_228 ,
unsigned int V_239 ,
unsigned int V_240 )
{
if ( V_228 != V_229 ) {
unsigned int V_241 , V_242 ;
V_241 = * V_238 / 8 ;
* V_238 %= 8 ;
V_242 = * V_237 / ( 512 / V_239 ) ;
* V_237 %= 512 / V_239 ;
return V_241 * V_240 * 8 + V_242 * 4096 ;
} else {
unsigned int V_243 ;
V_243 = * V_238 * V_240 + * V_237 * V_239 ;
* V_238 = 0 ;
* V_237 = ( V_243 & 4095 ) / V_239 ;
return V_243 & - 4096 ;
}
}
int F_164 ( int V_244 )
{
switch ( V_244 ) {
case V_245 :
return V_246 ;
case V_247 :
return V_248 ;
case V_249 :
return V_250 ;
default:
case V_251 :
return V_252 ;
case V_253 :
return V_254 ;
case V_255 :
return V_256 ;
case V_257 :
return V_258 ;
}
}
static bool F_165 ( struct V_64 * V_21 ,
struct V_259 * V_260 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_222 * V_223 = NULL ;
struct V_261 V_262 = { 0 } ;
T_1 V_109 = V_260 -> V_109 ;
if ( V_260 -> V_263 == 0 )
return false ;
V_223 = F_166 ( V_2 , V_109 , V_109 ,
V_260 -> V_263 ) ;
if ( ! V_223 )
return false ;
if ( V_260 -> V_220 ) {
V_223 -> V_228 = V_230 ;
V_223 -> V_264 = V_21 -> V_109 . V_66 -> V_67 -> V_265 [ 0 ] ;
}
V_262 . V_266 = V_21 -> V_109 . V_66 -> V_67 -> V_266 ;
V_262 . V_267 = V_21 -> V_109 . V_66 -> V_67 -> V_267 ;
V_262 . V_219 = V_21 -> V_109 . V_66 -> V_67 -> V_219 ;
V_262 . V_265 [ 0 ] = V_21 -> V_109 . V_66 -> V_67 -> V_265 [ 0 ] ;
F_53 ( & V_2 -> V_268 ) ;
if ( F_167 ( V_2 , F_168 ( V_21 -> V_109 . V_66 -> V_67 ) ,
& V_262 , V_223 ) ) {
F_36 ( L_51 ) ;
goto V_269;
}
F_55 ( & V_2 -> V_268 ) ;
F_36 ( L_52 , V_223 ) ;
return true ;
V_269:
F_169 ( & V_223 -> V_109 ) ;
F_55 ( & V_2 -> V_268 ) ;
return false ;
}
static void F_170 ( struct V_64 * V_64 ,
struct V_259 * V_260 )
{
struct V_1 * V_2 = V_64 -> V_109 . V_2 ;
struct V_20 * V_270 ;
struct V_64 * V_143 ;
struct V_271 * V_67 ;
if ( ! V_64 -> V_109 . V_66 -> V_67 )
return;
if ( F_165 ( V_64 , V_260 ) )
return;
F_171 ( V_64 -> V_109 . V_66 -> V_67 ) ;
V_64 -> V_109 . V_66 -> V_67 = NULL ;
F_172 (c, &dev->mode_config.crtc_list, head) {
V_143 = F_30 ( V_270 ) ;
if ( V_270 == & V_64 -> V_109 )
continue;
if ( ! V_143 -> V_65 || ! V_270 -> V_66 -> V_67 )
continue;
V_67 = F_168 ( V_270 -> V_66 -> V_67 ) ;
if ( F_173 ( V_67 -> V_223 ) == V_260 -> V_109 ) {
F_174 ( V_270 -> V_66 -> V_67 ) ;
V_64 -> V_109 . V_66 -> V_67 = V_270 -> V_66 -> V_67 ;
break;
}
}
}
static int F_175 ( struct V_20 * V_21 ,
struct V_272 * V_67 ,
int V_237 , int V_238 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_271 * V_273 ;
struct V_222 * V_223 ;
int V_141 = V_64 -> V_141 ;
unsigned long V_274 ;
T_1 V_275 ;
T_1 V_80 ;
switch ( V_141 ) {
case 0 :
case 1 :
break;
default:
F_116 ( L_53 , F_80 ( V_141 ) ) ;
return - V_232 ;
}
V_273 = F_168 ( V_67 ) ;
V_223 = V_273 -> V_223 ;
V_80 = F_79 ( V_141 ) ;
V_275 = F_4 ( V_80 ) ;
V_275 &= ~ V_276 ;
switch ( V_67 -> V_266 ) {
case V_246 :
V_275 |= V_245 ;
break;
case V_248 :
case V_277 :
V_275 |= V_247 ;
break;
case V_250 :
V_275 |= V_249 ;
break;
case V_252 :
case V_278 :
V_275 |= V_251 ;
break;
case V_254 :
case V_279 :
V_275 |= V_253 ;
break;
case V_256 :
case V_280 :
V_275 |= V_255 ;
break;
case V_258 :
case V_281 :
V_275 |= V_257 ;
break;
default:
F_122 () ;
}
if ( F_39 ( V_2 ) -> V_78 >= 4 ) {
if ( V_223 -> V_228 != V_229 )
V_275 |= V_282 ;
else
V_275 &= ~ V_282 ;
}
if ( F_15 ( V_2 ) )
V_275 |= V_283 ;
F_40 ( V_80 , V_275 ) ;
V_274 = V_238 * V_67 -> V_265 [ 0 ] + V_237 * ( V_67 -> V_284 / 8 ) ;
if ( F_39 ( V_2 ) -> V_78 >= 4 ) {
V_64 -> V_285 =
F_163 ( & V_237 , & V_238 , V_223 -> V_228 ,
V_67 -> V_284 / 8 ,
V_67 -> V_265 [ 0 ] ) ;
V_274 -= V_64 -> V_285 ;
} else {
V_64 -> V_285 = V_274 ;
}
F_36 ( L_54 ,
F_173 ( V_223 ) , V_274 , V_237 , V_238 ,
V_67 -> V_265 [ 0 ] ) ;
F_40 ( F_176 ( V_141 ) , V_67 -> V_265 [ 0 ] ) ;
if ( F_39 ( V_2 ) -> V_78 >= 4 ) {
F_40 ( F_145 ( V_141 ) ,
F_173 ( V_223 ) + V_64 -> V_285 ) ;
F_40 ( F_177 ( V_141 ) , ( V_238 << 16 ) | V_237 ) ;
F_40 ( F_178 ( V_141 ) , V_274 ) ;
} else
F_40 ( F_146 ( V_141 ) , F_173 ( V_223 ) + V_274 ) ;
F_114 ( V_80 ) ;
return 0 ;
}
static int F_179 ( struct V_20 * V_21 ,
struct V_272 * V_67 ,
int V_237 , int V_238 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_271 * V_273 ;
struct V_222 * V_223 ;
int V_141 = V_64 -> V_141 ;
unsigned long V_274 ;
T_1 V_275 ;
T_1 V_80 ;
switch ( V_141 ) {
case 0 :
case 1 :
case 2 :
break;
default:
F_116 ( L_53 , F_80 ( V_141 ) ) ;
return - V_232 ;
}
V_273 = F_168 ( V_67 ) ;
V_223 = V_273 -> V_223 ;
V_80 = F_79 ( V_141 ) ;
V_275 = F_4 ( V_80 ) ;
V_275 &= ~ V_276 ;
switch ( V_67 -> V_266 ) {
case V_246 :
V_275 |= V_245 ;
break;
case V_250 :
V_275 |= V_249 ;
break;
case V_252 :
case V_278 :
V_275 |= V_251 ;
break;
case V_254 :
case V_279 :
V_275 |= V_253 ;
break;
case V_256 :
case V_280 :
V_275 |= V_255 ;
break;
case V_258 :
case V_281 :
V_275 |= V_257 ;
break;
default:
F_122 () ;
}
if ( V_223 -> V_228 != V_229 )
V_275 |= V_282 ;
else
V_275 &= ~ V_282 ;
if ( F_142 ( V_2 ) || F_180 ( V_2 ) )
V_275 &= ~ V_283 ;
else
V_275 |= V_283 ;
F_40 ( V_80 , V_275 ) ;
V_274 = V_238 * V_67 -> V_265 [ 0 ] + V_237 * ( V_67 -> V_284 / 8 ) ;
V_64 -> V_285 =
F_163 ( & V_237 , & V_238 , V_223 -> V_228 ,
V_67 -> V_284 / 8 ,
V_67 -> V_265 [ 0 ] ) ;
V_274 -= V_64 -> V_285 ;
F_36 ( L_54 ,
F_173 ( V_223 ) , V_274 , V_237 , V_238 ,
V_67 -> V_265 [ 0 ] ) ;
F_40 ( F_176 ( V_141 ) , V_67 -> V_265 [ 0 ] ) ;
F_40 ( F_145 ( V_141 ) ,
F_173 ( V_223 ) + V_64 -> V_285 ) ;
if ( F_142 ( V_2 ) || F_180 ( V_2 ) ) {
F_40 ( F_181 ( V_141 ) , ( V_238 << 16 ) | V_237 ) ;
} else {
F_40 ( F_177 ( V_141 ) , ( V_238 << 16 ) | V_237 ) ;
F_40 ( F_178 ( V_141 ) , V_274 ) ;
}
F_114 ( V_80 ) ;
return 0 ;
}
static int
F_182 ( struct V_20 * V_21 , struct V_272 * V_67 ,
int V_237 , int V_238 , enum V_286 V_101 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_287 . V_288 )
V_4 -> V_287 . V_288 ( V_2 ) ;
F_183 ( V_21 ) ;
return V_4 -> V_287 . V_289 ( V_21 , V_67 , V_237 , V_238 ) ;
}
void F_184 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 ;
F_172 (crtc, &dev->mode_config.crtc_list, head) {
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_141 V_141 = V_64 -> V_141 ;
F_185 ( V_2 , V_141 ) ;
F_186 ( V_2 , V_141 ) ;
}
F_172 (crtc, &dev->mode_config.crtc_list, head) {
struct V_64 * V_64 = F_30 ( V_21 ) ;
F_53 ( & V_21 -> V_290 ) ;
if ( V_64 -> V_65 && V_21 -> V_66 -> V_67 )
V_4 -> V_287 . V_289 ( V_21 ,
V_21 -> V_66 -> V_67 ,
V_21 -> V_237 ,
V_21 -> V_238 ) ;
F_55 ( & V_21 -> V_290 ) ;
}
}
static int
F_187 ( struct V_272 * V_291 )
{
struct V_222 * V_223 = F_168 ( V_291 ) -> V_223 ;
struct V_3 * V_4 = V_223 -> V_109 . V_2 -> V_5 ;
bool V_292 = V_4 -> V_233 . V_234 ;
int V_227 ;
V_4 -> V_233 . V_234 = false ;
V_227 = F_188 ( V_223 ) ;
V_4 -> V_233 . V_234 = V_292 ;
return V_227 ;
}
static bool F_189 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
unsigned long V_293 ;
bool V_294 ;
if ( F_190 ( & V_4 -> V_295 ) ||
V_64 -> V_296 != F_191 ( & V_4 -> V_295 . V_296 ) )
return false ;
F_192 ( & V_2 -> V_297 , V_293 ) ;
V_294 = F_30 ( V_21 ) -> V_298 != NULL ;
F_193 ( & V_2 -> V_297 , V_293 ) ;
return V_294 ;
}
static int
F_194 ( struct V_20 * V_21 , int V_237 , int V_238 ,
struct V_272 * V_67 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_272 * V_291 ;
int V_227 ;
if ( F_189 ( V_21 ) ) {
F_116 ( L_55 ) ;
return - V_299 ;
}
if ( ! V_67 ) {
F_116 ( L_56 ) ;
return 0 ;
}
if ( V_64 -> V_141 > F_39 ( V_2 ) -> V_300 ) {
F_116 ( L_57 ,
F_80 ( V_64 -> V_141 ) ,
F_39 ( V_2 ) -> V_300 ) ;
return - V_232 ;
}
F_53 ( & V_2 -> V_268 ) ;
V_227 = F_154 ( V_2 ,
F_168 ( V_67 ) -> V_223 ,
NULL ) ;
F_55 ( & V_2 -> V_268 ) ;
if ( V_227 != 0 ) {
F_116 ( L_58 ) ;
return V_227 ;
}
if ( V_301 . V_302 ) {
const struct V_303 * V_69 =
& V_64 -> V_68 . V_69 ;
F_40 ( F_195 ( V_64 -> V_72 ) ,
( ( V_69 -> V_304 - 1 ) << 16 ) |
( V_69 -> V_305 - 1 ) ) ;
if ( ! V_64 -> V_68 . V_306 . V_100 &&
( F_9 ( V_21 , V_25 ) ||
F_9 ( V_21 , V_307 ) ) ) {
F_40 ( F_196 ( V_64 -> V_72 ) , 0 ) ;
F_40 ( F_197 ( V_64 -> V_72 ) , 0 ) ;
F_40 ( F_198 ( V_64 -> V_72 ) , 0 ) ;
}
V_64 -> V_68 . V_308 = V_69 -> V_304 ;
V_64 -> V_68 . V_309 = V_69 -> V_305 ;
}
V_227 = V_4 -> V_287 . V_289 ( V_21 , V_67 , V_237 , V_238 ) ;
if ( V_227 ) {
F_53 ( & V_2 -> V_268 ) ;
F_161 ( F_168 ( V_67 ) -> V_223 ) ;
F_55 ( & V_2 -> V_268 ) ;
F_116 ( L_59 ) ;
return V_227 ;
}
V_291 = V_21 -> V_66 -> V_67 ;
V_21 -> V_66 -> V_67 = V_67 ;
V_21 -> V_237 = V_237 ;
V_21 -> V_238 = V_238 ;
if ( V_291 ) {
if ( V_64 -> V_65 && V_291 != V_67 )
F_37 ( V_2 , V_64 -> V_72 ) ;
F_53 ( & V_2 -> V_268 ) ;
F_161 ( F_168 ( V_291 ) -> V_223 ) ;
F_55 ( & V_2 -> V_268 ) ;
}
F_53 ( & V_2 -> V_268 ) ;
F_199 ( V_2 ) ;
F_200 ( V_2 ) ;
F_55 ( & V_2 -> V_268 ) ;
return 0 ;
}
static void F_201 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
T_1 V_80 , V_310 ;
V_80 = F_63 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
if ( F_202 ( V_2 ) ) {
V_310 &= ~ V_311 ;
V_310 |= V_311 | V_312 ;
} else {
V_310 &= ~ V_313 ;
V_310 |= V_313 | V_312 ;
}
F_40 ( V_80 , V_310 ) ;
V_80 = F_65 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
if ( F_90 ( V_2 ) ) {
V_310 &= ~ V_314 ;
V_310 |= V_315 ;
} else {
V_310 &= ~ V_313 ;
V_310 |= V_313 ;
}
F_40 ( V_80 , V_310 | V_316 ) ;
F_114 ( V_80 ) ;
F_115 ( 1000 ) ;
if ( F_202 ( V_2 ) )
F_40 ( V_80 , F_4 ( V_80 ) | V_317 |
V_318 ) ;
}
static bool F_203 ( struct V_64 * V_21 )
{
return V_21 -> V_109 . V_100 && V_21 -> V_65 &&
V_21 -> V_68 . V_216 ;
}
static void F_204 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_319 =
F_30 ( V_4 -> V_73 [ V_134 ] ) ;
struct V_64 * V_320 =
F_30 ( V_4 -> V_73 [ V_321 ] ) ;
T_4 V_310 ;
if ( ! F_203 ( V_319 ) &&
! F_203 ( V_320 ) ) {
F_2 ( F_4 ( F_65 ( V_134 ) ) & V_119 ) ;
F_2 ( F_4 ( F_65 ( V_321 ) ) & V_119 ) ;
V_310 = F_4 ( V_322 ) ;
V_310 &= ~ V_323 ;
F_36 ( L_60 ) ;
F_40 ( V_322 , V_310 ) ;
}
}
static void F_205 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
int V_141 = V_64 -> V_141 ;
T_1 V_80 , V_310 , V_324 ;
F_148 ( V_4 , V_72 ) ;
F_206 ( V_4 , V_141 ) ;
V_80 = F_207 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_325 ;
V_310 &= ~ V_326 ;
F_40 ( V_80 , V_310 ) ;
F_4 ( V_80 ) ;
F_115 ( 150 ) ;
V_80 = F_63 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_327 ;
V_310 |= F_208 ( V_64 -> V_68 . V_328 ) ;
V_310 &= ~ V_313 ;
V_310 |= V_329 ;
F_40 ( V_80 , V_310 | V_118 ) ;
V_80 = F_65 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_313 ;
V_310 |= V_329 ;
F_40 ( V_80 , V_310 | V_119 ) ;
F_114 ( V_80 ) ;
F_115 ( 150 ) ;
F_40 ( F_209 ( V_72 ) , V_330 ) ;
F_40 ( F_209 ( V_72 ) , V_330 |
V_331 ) ;
V_80 = F_210 ( V_72 ) ;
for ( V_324 = 0 ; V_324 < 5 ; V_324 ++ ) {
V_310 = F_4 ( V_80 ) ;
F_36 ( L_61 , V_310 ) ;
if ( ( V_310 & V_326 ) ) {
F_36 ( L_62 ) ;
F_40 ( V_80 , V_310 | V_326 ) ;
break;
}
}
if ( V_324 == 5 )
F_116 ( L_63 ) ;
V_80 = F_63 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_313 ;
V_310 |= V_332 ;
F_40 ( V_80 , V_310 ) ;
V_80 = F_65 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_313 ;
V_310 |= V_332 ;
F_40 ( V_80 , V_310 ) ;
F_114 ( V_80 ) ;
F_115 ( 150 ) ;
V_80 = F_210 ( V_72 ) ;
for ( V_324 = 0 ; V_324 < 5 ; V_324 ++ ) {
V_310 = F_4 ( V_80 ) ;
F_36 ( L_61 , V_310 ) ;
if ( V_310 & V_325 ) {
F_40 ( V_80 , V_310 | V_325 ) ;
F_36 ( L_64 ) ;
break;
}
}
if ( V_324 == 5 )
F_116 ( L_65 ) ;
F_36 ( L_66 ) ;
}
static void F_211 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
T_1 V_80 , V_310 , V_143 , V_333 ;
V_80 = F_207 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_325 ;
V_310 &= ~ V_326 ;
F_40 ( V_80 , V_310 ) ;
F_114 ( V_80 ) ;
F_115 ( 150 ) ;
V_80 = F_63 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_327 ;
V_310 |= F_208 ( V_64 -> V_68 . V_328 ) ;
V_310 &= ~ V_313 ;
V_310 |= V_329 ;
V_310 &= ~ V_334 ;
V_310 |= V_335 ;
F_40 ( V_80 , V_310 | V_118 ) ;
F_40 ( F_212 ( V_72 ) ,
V_336 | V_337 ) ;
V_80 = F_65 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
if ( F_90 ( V_2 ) ) {
V_310 &= ~ V_314 ;
V_310 |= V_338 ;
} else {
V_310 &= ~ V_313 ;
V_310 |= V_329 ;
}
F_40 ( V_80 , V_310 | V_119 ) ;
F_114 ( V_80 ) ;
F_115 ( 150 ) ;
for ( V_143 = 0 ; V_143 < 4 ; V_143 ++ ) {
V_80 = F_63 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_334 ;
V_310 |= V_339 [ V_143 ] ;
F_40 ( V_80 , V_310 ) ;
F_114 ( V_80 ) ;
F_115 ( 500 ) ;
for ( V_333 = 0 ; V_333 < 5 ; V_333 ++ ) {
V_80 = F_210 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
F_36 ( L_61 , V_310 ) ;
if ( V_310 & V_326 ) {
F_40 ( V_80 , V_310 | V_326 ) ;
F_36 ( L_62 ) ;
break;
}
F_115 ( 50 ) ;
}
if ( V_333 < 5 )
break;
}
if ( V_143 == 4 )
F_116 ( L_63 ) ;
V_80 = F_63 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_313 ;
V_310 |= V_332 ;
if ( F_213 ( V_2 ) ) {
V_310 &= ~ V_334 ;
V_310 |= V_335 ;
}
F_40 ( V_80 , V_310 ) ;
V_80 = F_65 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
if ( F_90 ( V_2 ) ) {
V_310 &= ~ V_314 ;
V_310 |= V_340 ;
} else {
V_310 &= ~ V_313 ;
V_310 |= V_332 ;
}
F_40 ( V_80 , V_310 ) ;
F_114 ( V_80 ) ;
F_115 ( 150 ) ;
for ( V_143 = 0 ; V_143 < 4 ; V_143 ++ ) {
V_80 = F_63 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_334 ;
V_310 |= V_339 [ V_143 ] ;
F_40 ( V_80 , V_310 ) ;
F_114 ( V_80 ) ;
F_115 ( 500 ) ;
for ( V_333 = 0 ; V_333 < 5 ; V_333 ++ ) {
V_80 = F_210 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
F_36 ( L_61 , V_310 ) ;
if ( V_310 & V_325 ) {
F_40 ( V_80 , V_310 | V_325 ) ;
F_36 ( L_64 ) ;
break;
}
F_115 ( 50 ) ;
}
if ( V_333 < 5 )
break;
}
if ( V_143 == 4 )
F_116 ( L_65 ) ;
F_36 ( L_67 ) ;
}
static void F_214 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
T_1 V_80 , V_310 , V_143 , V_341 ;
V_80 = F_207 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_325 ;
V_310 &= ~ V_326 ;
F_40 ( V_80 , V_310 ) ;
F_114 ( V_80 ) ;
F_115 ( 150 ) ;
F_36 ( L_68 ,
F_4 ( F_210 ( V_72 ) ) ) ;
for ( V_341 = 0 ; V_341 < F_215 ( V_339 ) * 2 ; V_341 ++ ) {
V_80 = F_63 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ ( V_342 | V_311 ) ;
V_310 &= ~ V_118 ;
F_40 ( V_80 , V_310 ) ;
V_80 = F_65 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_342 ;
V_310 &= ~ V_314 ;
V_310 &= ~ V_119 ;
F_40 ( V_80 , V_310 ) ;
V_80 = F_63 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_327 ;
V_310 |= F_208 ( V_64 -> V_68 . V_328 ) ;
V_310 |= V_343 ;
V_310 &= ~ V_334 ;
V_310 |= V_339 [ V_341 / 2 ] ;
V_310 |= V_344 ;
F_40 ( V_80 , V_310 | V_118 ) ;
F_40 ( F_212 ( V_72 ) ,
V_336 | V_337 ) ;
V_80 = F_65 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 |= V_338 ;
V_310 |= V_344 ;
F_40 ( V_80 , V_310 | V_119 ) ;
F_114 ( V_80 ) ;
F_115 ( 1 ) ;
for ( V_143 = 0 ; V_143 < 4 ; V_143 ++ ) {
V_80 = F_210 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
F_36 ( L_61 , V_310 ) ;
if ( V_310 & V_326 ||
( F_4 ( V_80 ) & V_326 ) ) {
F_40 ( V_80 , V_310 | V_326 ) ;
F_36 ( L_69 ,
V_143 ) ;
break;
}
F_115 ( 1 ) ;
}
if ( V_143 == 4 ) {
F_36 ( L_70 , V_341 / 2 ) ;
continue;
}
V_80 = F_63 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_311 ;
V_310 |= V_345 ;
F_40 ( V_80 , V_310 ) ;
V_80 = F_65 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_314 ;
V_310 |= V_340 ;
F_40 ( V_80 , V_310 ) ;
F_114 ( V_80 ) ;
F_115 ( 2 ) ;
for ( V_143 = 0 ; V_143 < 4 ; V_143 ++ ) {
V_80 = F_210 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
F_36 ( L_61 , V_310 ) ;
if ( V_310 & V_325 ||
( F_4 ( V_80 ) & V_325 ) ) {
F_40 ( V_80 , V_310 | V_325 ) ;
F_36 ( L_71 ,
V_143 ) ;
goto V_346;
}
F_115 ( 2 ) ;
}
if ( V_143 == 4 )
F_36 ( L_72 , V_341 / 2 ) ;
}
V_346:
F_36 ( L_67 ) ;
}
static void F_216 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_72 = V_64 -> V_72 ;
T_1 V_80 , V_310 ;
V_80 = F_65 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ ( V_327 | ( 0x7 << 16 ) ) ;
V_310 |= F_208 ( V_64 -> V_68 . V_328 ) ;
V_310 |= ( F_4 ( F_45 ( V_72 ) ) & V_202 ) << 11 ;
F_40 ( V_80 , V_310 | V_121 ) ;
F_114 ( V_80 ) ;
F_115 ( 200 ) ;
V_310 = F_4 ( V_80 ) ;
F_40 ( V_80 , V_310 | V_347 ) ;
F_114 ( V_80 ) ;
F_115 ( 200 ) ;
V_80 = F_63 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
if ( ( V_310 & V_120 ) == 0 ) {
F_40 ( V_80 , V_310 | V_120 ) ;
F_114 ( V_80 ) ;
F_115 ( 100 ) ;
}
}
static void F_217 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_72 = V_64 -> V_72 ;
T_1 V_80 , V_310 ;
V_80 = F_65 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
F_40 ( V_80 , V_310 & ~ V_347 ) ;
V_80 = F_63 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
F_40 ( V_80 , V_310 & ~ V_120 ) ;
F_114 ( V_80 ) ;
F_115 ( 100 ) ;
V_80 = F_65 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
F_40 ( V_80 , V_310 & ~ V_121 ) ;
F_114 ( V_80 ) ;
F_115 ( 100 ) ;
}
static void F_218 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
T_1 V_80 , V_310 ;
V_80 = F_63 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
F_40 ( V_80 , V_310 & ~ V_118 ) ;
F_114 ( V_80 ) ;
V_80 = F_65 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ ( 0x7 << 16 ) ;
V_310 |= ( F_4 ( F_45 ( V_72 ) ) & V_202 ) << 11 ;
F_40 ( V_80 , V_310 & ~ V_119 ) ;
F_114 ( V_80 ) ;
F_115 ( 100 ) ;
if ( F_48 ( V_2 ) ) {
F_40 ( F_209 ( V_72 ) , V_330 ) ;
}
V_80 = F_63 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ V_313 ;
V_310 |= V_329 ;
F_40 ( V_80 , V_310 ) ;
V_80 = F_65 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
if ( F_90 ( V_2 ) ) {
V_310 &= ~ V_314 ;
V_310 |= V_338 ;
} else {
V_310 &= ~ V_313 ;
V_310 |= V_329 ;
}
V_310 &= ~ ( 0x07 << 16 ) ;
V_310 |= ( F_4 ( F_45 ( V_72 ) ) & V_202 ) << 11 ;
F_40 ( V_80 , V_310 ) ;
F_114 ( V_80 ) ;
F_115 ( 100 ) ;
}
bool F_219 ( struct V_1 * V_2 )
{
struct V_64 * V_21 ;
F_172 (crtc, &dev->mode_config.crtc_list, base.head) {
if ( F_191 ( & V_21 -> V_348 ) == 0 )
continue;
if ( V_21 -> V_298 )
F_37 ( V_2 , V_21 -> V_72 ) ;
return true ;
}
return false ;
}
static void F_220 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_21 -> V_66 -> V_67 == NULL )
return;
F_2 ( F_221 ( & V_4 -> V_349 ) ) ;
F_222 ( V_4 -> V_349 ,
! F_189 ( V_21 ) ) ;
F_53 ( & V_2 -> V_268 ) ;
F_187 ( V_21 -> V_66 -> V_67 ) ;
F_55 ( & V_2 -> V_268 ) ;
}
static void F_223 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int clock = F_30 ( V_21 ) -> V_68 . V_69 . V_70 ;
T_1 V_350 , V_351 , V_352 , V_353 = 0 ;
T_1 V_310 ;
F_53 ( & V_4 -> V_105 ) ;
F_40 ( V_354 , V_355 ) ;
F_224 ( V_4 , V_356 ,
F_225 ( V_4 , V_356 , V_357 ) |
V_358 ,
V_357 ) ;
if ( clock == 20000 ) {
V_352 = 1 ;
V_350 = 0x41 ;
V_351 = 0x20 ;
} else {
T_1 V_359 = 172800 * 1000 ;
T_1 V_360 = 64 ;
T_1 V_361 , V_362 , V_363 ;
V_361 = ( V_359 / clock ) ;
V_362 = V_361 / V_360 ;
V_363 = V_361 % V_360 ;
V_352 = 0 ;
V_350 = V_362 - 2 ;
V_351 = V_363 ;
}
F_2 ( F_226 ( V_350 ) &
~ V_364 ) ;
F_2 ( F_227 ( V_353 ) &
~ V_365 ) ;
F_36 ( L_73 ,
clock ,
V_352 ,
V_350 ,
V_353 ,
V_351 ) ;
V_310 = F_225 ( V_4 , V_366 , V_357 ) ;
V_310 &= ~ V_364 ;
V_310 |= F_226 ( V_350 ) ;
V_310 &= ~ V_365 ;
V_310 |= F_228 ( V_351 ) ;
V_310 |= F_227 ( V_353 ) ;
V_310 |= V_367 ;
F_224 ( V_4 , V_366 , V_310 , V_357 ) ;
V_310 = F_225 ( V_4 , V_368 , V_357 ) ;
V_310 &= ~ F_229 ( 1 ) ;
V_310 |= F_229 ( V_352 ) ;
F_224 ( V_4 , V_368 , V_310 , V_357 ) ;
V_310 = F_225 ( V_4 , V_356 , V_357 ) ;
V_310 &= ~ V_358 ;
F_224 ( V_4 , V_356 , V_310 , V_357 ) ;
F_115 ( 24 ) ;
F_40 ( V_354 , V_369 ) ;
F_55 ( & V_4 -> V_105 ) ;
}
static void F_230 ( struct V_64 * V_21 ,
enum V_72 V_214 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_71 V_74 = V_21 -> V_68 . V_74 ;
F_40 ( F_231 ( V_214 ) ,
F_4 ( F_232 ( V_74 ) ) ) ;
F_40 ( F_233 ( V_214 ) ,
F_4 ( F_234 ( V_74 ) ) ) ;
F_40 ( F_235 ( V_214 ) ,
F_4 ( F_236 ( V_74 ) ) ) ;
F_40 ( F_237 ( V_214 ) ,
F_4 ( F_238 ( V_74 ) ) ) ;
F_40 ( F_239 ( V_214 ) ,
F_4 ( F_240 ( V_74 ) ) ) ;
F_40 ( F_241 ( V_214 ) ,
F_4 ( F_242 ( V_74 ) ) ) ;
F_40 ( F_243 ( V_214 ) ,
F_4 ( F_244 ( V_74 ) ) ) ;
}
static void F_245 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_310 ;
V_310 = F_4 ( V_322 ) ;
if ( V_310 & V_323 )
return;
F_2 ( F_4 ( F_65 ( V_134 ) ) & V_119 ) ;
F_2 ( F_4 ( F_65 ( V_321 ) ) & V_119 ) ;
V_310 |= V_323 ;
F_36 ( L_74 ) ;
F_40 ( V_322 , V_310 ) ;
F_114 ( V_322 ) ;
}
static void F_246 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_64 -> V_72 ) {
case V_125 :
break;
case V_134 :
if ( V_64 -> V_68 . V_328 > 2 )
F_2 ( F_4 ( V_322 ) & V_323 ) ;
else
F_245 ( V_2 ) ;
break;
case V_321 :
F_245 ( V_2 ) ;
break;
default:
F_122 () ;
}
}
static void F_247 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
T_1 V_80 , V_310 ;
F_91 ( V_4 , V_72 ) ;
if ( F_202 ( V_2 ) )
F_246 ( V_64 ) ;
F_40 ( F_248 ( V_72 ) ,
F_4 ( F_249 ( V_72 ) ) & V_370 ) ;
V_4 -> V_287 . V_371 ( V_21 ) ;
if ( F_90 ( V_2 ) ) {
T_1 V_372 ;
V_310 = F_4 ( V_373 ) ;
V_310 |= F_250 ( V_72 ) ;
V_372 = F_251 ( V_72 ) ;
if ( V_64 -> V_68 . V_110 == V_374 )
V_310 |= V_372 ;
else
V_310 &= ~ V_372 ;
F_40 ( V_373 , V_310 ) ;
}
F_124 ( V_64 ) ;
F_68 ( V_4 , V_72 ) ;
F_230 ( V_64 , V_72 ) ;
F_201 ( V_21 ) ;
if ( F_90 ( V_2 ) &&
( F_9 ( V_21 , V_375 ) ||
F_9 ( V_21 , V_307 ) ) ) {
T_1 V_376 = ( F_4 ( F_45 ( V_72 ) ) & V_202 ) >> 5 ;
V_80 = F_94 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ ( V_160 |
V_377 |
V_378 ) ;
V_310 |= ( V_379 |
V_380 ) ;
V_310 |= V_376 << 9 ;
if ( V_21 -> V_381 . V_293 & V_382 )
V_310 |= V_383 ;
if ( V_21 -> V_381 . V_293 & V_384 )
V_310 |= V_385 ;
switch ( F_252 ( V_21 ) ) {
case V_172 :
V_310 |= V_173 ;
break;
case V_174 :
V_310 |= V_175 ;
break;
case V_176 :
V_310 |= V_177 ;
break;
default:
F_122 () ;
}
F_40 ( V_80 , V_310 ) ;
}
F_128 ( V_4 , V_72 ) ;
}
static void F_253 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_71 V_74 = V_64 -> V_68 . V_74 ;
F_91 ( V_4 , V_210 ) ;
F_223 ( V_21 ) ;
F_230 ( V_64 , V_125 ) ;
F_132 ( V_4 , V_74 ) ;
}
static void F_254 ( struct V_64 * V_21 )
{
struct V_108 * V_112 = F_56 ( V_21 ) ;
if ( V_112 == NULL )
return;
if ( V_112 -> V_195 == 0 ) {
F_46 ( 1 , L_75 , V_112 -> V_116 ) ;
return;
}
if ( -- V_112 -> V_195 == 0 ) {
F_2 ( V_112 -> V_196 ) ;
F_2 ( V_112 -> V_65 ) ;
}
V_21 -> V_68 . V_110 = V_386 ;
}
static struct V_108 * F_255 ( struct V_64 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_109 . V_2 -> V_5 ;
struct V_108 * V_112 = F_56 ( V_21 ) ;
enum V_387 V_143 ;
if ( V_112 ) {
F_36 ( L_76 ,
V_21 -> V_109 . V_109 . V_197 , V_112 -> V_116 ) ;
F_254 ( V_21 ) ;
}
if ( F_48 ( V_4 -> V_2 ) ) {
V_143 = (enum V_387 ) V_21 -> V_72 ;
V_112 = & V_4 -> V_111 [ V_143 ] ;
F_36 ( L_77 ,
V_21 -> V_109 . V_109 . V_197 , V_112 -> V_116 ) ;
goto V_59;
}
for ( V_143 = 0 ; V_143 < V_4 -> V_388 ; V_143 ++ ) {
V_112 = & V_4 -> V_111 [ V_143 ] ;
if ( V_112 -> V_195 == 0 )
continue;
if ( memcmp ( & V_21 -> V_68 . V_188 , & V_112 -> V_114 ,
sizeof( V_112 -> V_114 ) ) == 0 ) {
F_36 ( L_78 ,
V_21 -> V_109 . V_109 . V_197 ,
V_112 -> V_116 , V_112 -> V_195 , V_112 -> V_65 ) ;
goto V_59;
}
}
for ( V_143 = 0 ; V_143 < V_4 -> V_388 ; V_143 ++ ) {
V_112 = & V_4 -> V_111 [ V_143 ] ;
if ( V_112 -> V_195 == 0 ) {
F_36 ( L_79 ,
V_21 -> V_109 . V_109 . V_197 , V_112 -> V_116 ) ;
goto V_59;
}
}
return NULL ;
V_59:
V_21 -> V_68 . V_110 = V_143 ;
F_59 ( L_80 , V_112 -> V_116 ,
F_69 ( V_21 -> V_72 ) ) ;
if ( V_112 -> V_65 == 0 ) {
memcpy ( & V_112 -> V_114 , & V_21 -> V_68 . V_188 ,
sizeof( V_112 -> V_114 ) ) ;
F_59 ( L_81 , V_112 -> V_116 ) ;
F_2 ( V_112 -> V_196 ) ;
F_127 ( V_4 , V_112 ) ;
V_112 -> V_389 ( V_4 , V_112 ) ;
}
V_112 -> V_195 ++ ;
return V_112 ;
}
static void F_256 ( struct V_1 * V_2 , int V_72 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_390 = F_42 ( V_72 ) ;
T_1 V_310 ;
V_310 = F_4 ( V_390 ) ;
F_115 ( 500 ) ;
if ( F_34 ( F_4 ( V_390 ) != V_310 , 5 ) ) {
if ( F_34 ( F_4 ( V_390 ) != V_310 , 5 ) )
F_116 ( L_82 , F_69 ( V_72 ) ) ;
}
}
static void F_257 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_72 = V_21 -> V_72 ;
if ( V_21 -> V_68 . V_306 . V_100 ) {
if ( F_202 ( V_2 ) || F_142 ( V_2 ) )
F_40 ( F_196 ( V_72 ) , V_391 | V_392 |
F_258 ( V_72 ) ) ;
else
F_40 ( F_196 ( V_72 ) , V_391 | V_392 ) ;
F_40 ( F_197 ( V_72 ) , V_21 -> V_68 . V_306 . V_393 ) ;
F_40 ( F_198 ( V_72 ) , V_21 -> V_68 . V_306 . V_263 ) ;
}
}
static void F_259 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
enum V_72 V_72 = F_30 ( V_21 ) -> V_72 ;
struct V_394 * V_141 ;
struct V_395 * V_395 ;
F_260 (plane, &dev->mode_config.plane_list) {
V_395 = F_261 ( V_141 ) ;
if ( V_395 -> V_72 == V_72 )
F_262 ( & V_395 -> V_109 ) ;
}
}
static void F_263 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
enum V_72 V_72 = F_30 ( V_21 ) -> V_72 ;
struct V_394 * V_141 ;
struct V_395 * V_395 ;
F_260 (plane, &dev->mode_config.plane_list) {
V_395 = F_261 ( V_141 ) ;
if ( V_395 -> V_72 == V_72 )
F_264 ( & V_395 -> V_109 ) ;
}
}
void F_265 ( struct V_64 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_109 . V_2 -> V_5 ;
if ( ! V_21 -> V_68 . V_396 )
return;
F_206 ( V_4 , V_21 -> V_141 ) ;
if ( F_180 ( V_21 -> V_109 . V_2 ) ) {
F_53 ( & V_4 -> V_397 . V_398 ) ;
F_2 ( F_266 ( V_4 , V_399 , 0xc0000000 ) ) ;
F_55 ( & V_4 -> V_397 . V_398 ) ;
} else {
F_40 ( V_400 , V_401 ) ;
if ( F_34 ( F_35 ( V_400 ) & V_401 , 50 ) )
F_116 ( L_83 ) ;
}
}
void F_267 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_21 -> V_68 . V_396 )
return;
F_206 ( V_4 , V_21 -> V_141 ) ;
if ( F_180 ( V_21 -> V_109 . V_2 ) ) {
F_53 ( & V_4 -> V_397 . V_398 ) ;
F_2 ( F_266 ( V_4 , V_399 , 0 ) ) ;
F_55 ( & V_4 -> V_397 . V_398 ) ;
} else {
F_40 ( V_400 , 0 ) ;
F_114 ( V_400 ) ;
}
F_37 ( V_2 , V_21 -> V_72 ) ;
}
static void F_268 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_72 V_72 = V_64 -> V_72 ;
int V_402 = F_269 ( V_72 ) ;
int V_143 ;
bool V_403 = false ;
if ( ! V_21 -> V_100 || ! V_64 -> V_65 )
return;
if ( ! F_3 ( V_4 -> V_2 ) ) {
if ( F_9 ( V_21 , V_215 ) )
F_139 ( V_4 ) ;
else
F_140 ( V_4 , V_72 ) ;
}
if ( F_3 ( V_2 ) )
V_402 = F_270 ( V_72 ) ;
if ( F_142 ( V_2 ) && V_64 -> V_68 . V_396 &&
( ( F_4 ( F_271 ( V_72 ) ) & V_404 ) ==
V_405 ) ) {
F_267 ( V_64 ) ;
V_403 = true ;
}
for ( V_143 = 0 ; V_143 < 256 ; V_143 ++ ) {
F_40 ( V_402 + 4 * V_143 ,
( V_64 -> V_406 [ V_143 ] << 16 ) |
( V_64 -> V_407 [ V_143 ] << 8 ) |
V_64 -> V_408 [ V_143 ] ) ;
}
if ( V_403 )
F_265 ( V_64 ) ;
}
static void F_272 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_72 = V_64 -> V_72 ;
int V_141 = V_64 -> V_141 ;
F_2 ( ! V_21 -> V_100 ) ;
if ( V_64 -> V_65 )
return;
V_64 -> V_65 = true ;
F_273 ( V_2 , V_72 , true ) ;
F_274 ( V_2 , V_72 , true ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_409 )
V_23 -> V_409 ( V_23 ) ;
if ( V_64 -> V_68 . V_216 ) {
F_216 ( V_64 ) ;
} else {
F_134 ( V_4 , V_72 ) ;
F_135 ( V_4 , V_72 ) ;
}
F_257 ( V_64 ) ;
F_268 ( V_21 ) ;
F_275 ( V_21 ) ;
F_137 ( V_64 ) ;
F_147 ( V_4 , V_141 , V_72 ) ;
F_259 ( V_21 ) ;
F_276 ( V_21 , true ) ;
if ( V_64 -> V_68 . V_216 )
F_247 ( V_21 ) ;
F_53 ( & V_2 -> V_268 ) ;
F_199 ( V_2 ) ;
F_55 ( & V_2 -> V_268 ) ;
F_10 (dev, crtc, encoder)
V_23 -> V_198 ( V_23 ) ;
if ( F_90 ( V_2 ) )
F_256 ( V_2 , V_64 -> V_72 ) ;
F_37 ( V_2 , V_64 -> V_72 ) ;
}
static bool F_277 ( struct V_64 * V_21 )
{
return F_278 ( V_21 -> V_109 . V_2 ) && V_21 -> V_72 == V_125 ;
}
static void F_279 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
int V_141 = V_64 -> V_141 ;
F_147 ( V_4 , V_141 , V_72 ) ;
F_259 ( V_21 ) ;
F_276 ( V_21 , true ) ;
F_265 ( V_64 ) ;
F_53 ( & V_2 -> V_268 ) ;
F_199 ( V_2 ) ;
F_55 ( & V_2 -> V_268 ) ;
}
static void F_280 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
int V_141 = V_64 -> V_141 ;
F_220 ( V_21 ) ;
F_281 ( V_2 , V_72 ) ;
if ( V_4 -> V_410 . V_141 == V_141 )
F_282 ( V_2 ) ;
F_267 ( V_64 ) ;
F_276 ( V_21 , false ) ;
F_263 ( V_21 ) ;
F_149 ( V_4 , V_141 , V_72 ) ;
}
static void F_283 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_64 * V_411 , * V_412 = NULL ;
F_172 (crtc_it, &dev->mode_config.crtc_list, base.head) {
if ( ! V_411 -> V_65 || V_411 == V_21 )
continue;
if ( V_412 )
return;
V_412 = V_411 ;
}
if ( ! V_412 )
return;
F_37 ( V_2 , V_412 -> V_72 ) ;
F_37 ( V_2 , V_412 -> V_72 ) ;
}
static void F_284 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_72 = V_64 -> V_72 ;
F_2 ( ! V_21 -> V_100 ) ;
if ( V_64 -> V_65 )
return;
V_64 -> V_65 = true ;
F_273 ( V_2 , V_72 , true ) ;
if ( V_64 -> V_68 . V_216 )
F_274 ( V_2 , V_210 , true ) ;
if ( V_64 -> V_68 . V_216 )
V_4 -> V_287 . V_371 ( V_21 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_409 )
V_23 -> V_409 ( V_23 ) ;
F_285 ( V_64 ) ;
F_257 ( V_64 ) ;
F_268 ( V_21 ) ;
F_286 ( V_21 ) ;
F_287 ( V_21 ) ;
F_275 ( V_21 ) ;
F_137 ( V_64 ) ;
if ( V_64 -> V_68 . V_216 )
F_253 ( V_21 ) ;
F_10 (dev, crtc, encoder) {
V_23 -> V_198 ( V_23 ) ;
F_288 ( V_23 , true ) ;
}
F_283 ( V_64 ) ;
F_279 ( V_21 ) ;
}
static void F_289 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_72 = V_21 -> V_72 ;
if ( V_21 -> V_68 . V_306 . V_100 ) {
F_40 ( F_196 ( V_72 ) , 0 ) ;
F_40 ( F_197 ( V_72 ) , 0 ) ;
F_40 ( F_198 ( V_72 ) , 0 ) ;
}
}
static void F_290 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_72 = V_64 -> V_72 ;
int V_141 = V_64 -> V_141 ;
T_1 V_80 , V_310 ;
if ( ! V_64 -> V_65 )
return;
F_10 (dev, crtc, encoder)
V_23 -> V_199 ( V_23 ) ;
F_220 ( V_21 ) ;
F_281 ( V_2 , V_72 ) ;
if ( V_4 -> V_410 . V_141 == V_141 )
F_282 ( V_2 ) ;
F_276 ( V_21 , false ) ;
F_263 ( V_21 ) ;
F_149 ( V_4 , V_141 , V_72 ) ;
if ( V_64 -> V_68 . V_216 )
F_274 ( V_2 , V_72 , false ) ;
F_143 ( V_4 , V_72 ) ;
F_289 ( V_64 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_413 )
V_23 -> V_413 ( V_23 ) ;
if ( V_64 -> V_68 . V_216 ) {
F_218 ( V_21 ) ;
F_133 ( V_4 , V_72 ) ;
F_274 ( V_2 , V_72 , true ) ;
if ( F_90 ( V_2 ) ) {
V_80 = F_94 ( V_72 ) ;
V_310 = F_4 ( V_80 ) ;
V_310 &= ~ ( V_379 |
V_160 ) ;
V_310 |= V_414 ;
F_40 ( V_80 , V_310 ) ;
V_310 = F_4 ( V_373 ) ;
V_310 &= ~ ( F_250 ( V_72 ) | F_251 ( V_72 ) ) ;
F_40 ( V_373 , V_310 ) ;
}
F_126 ( V_64 ) ;
F_217 ( V_64 ) ;
}
V_64 -> V_65 = false ;
F_275 ( V_21 ) ;
F_53 ( & V_2 -> V_268 ) ;
F_199 ( V_2 ) ;
F_55 ( & V_2 -> V_268 ) ;
}
static void F_291 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_72 = V_64 -> V_72 ;
enum V_71 V_74 = V_64 -> V_68 . V_74 ;
if ( ! V_64 -> V_65 )
return;
F_280 ( V_21 ) ;
F_10 (dev, crtc, encoder) {
F_288 ( V_23 , false ) ;
V_23 -> V_199 ( V_23 ) ;
}
if ( V_64 -> V_68 . V_216 )
F_274 ( V_2 , V_210 , false ) ;
F_143 ( V_4 , V_72 ) ;
F_292 ( V_4 , V_74 ) ;
F_289 ( V_64 ) ;
F_293 ( V_64 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_413 )
V_23 -> V_413 ( V_23 ) ;
if ( V_64 -> V_68 . V_216 ) {
F_136 ( V_4 ) ;
F_274 ( V_2 , V_210 , true ) ;
F_294 ( V_21 ) ;
}
V_64 -> V_65 = false ;
F_275 ( V_21 ) ;
F_53 ( & V_2 -> V_268 ) ;
F_199 ( V_2 ) ;
F_55 ( & V_2 -> V_268 ) ;
}
static void F_295 ( struct V_20 * V_21 )
{
struct V_64 * V_64 = F_30 ( V_21 ) ;
F_254 ( V_64 ) ;
}
static void F_296 ( struct V_20 * V_21 )
{
F_297 ( V_21 ) ;
}
static void F_298 ( struct V_64 * V_64 , bool V_198 )
{
if ( ! V_198 && V_64 -> V_415 ) {
struct V_1 * V_2 = V_64 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_53 ( & V_2 -> V_268 ) ;
V_4 -> V_233 . V_234 = false ;
( void ) F_299 ( V_64 -> V_415 ) ;
V_4 -> V_233 . V_234 = true ;
F_55 ( & V_2 -> V_268 ) ;
}
}
static void
F_300 ( struct V_3 * V_4 , enum V_72 V_72 )
{
T_1 V_416 = F_4 ( F_73 ( V_72 ) ) ;
if ( ( V_416 & V_137 ) == 0 ) {
T_1 V_417 = F_4 ( V_418 ) ;
F_40 ( V_418 , V_417 & ~ V_419 ) ;
F_40 ( F_73 ( V_72 ) , V_420 ) ;
F_37 ( V_4 -> V_2 , V_72 ) ;
F_40 ( F_73 ( V_72 ) , V_416 ) ;
F_40 ( F_301 ( V_72 ) , F_4 ( F_301 ( V_72 ) ) ) ;
F_40 ( V_418 , V_417 ) ;
}
}
static void F_302 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_421 * V_422 = & V_21 -> V_68 ;
if ( ! V_21 -> V_68 . V_423 . V_424 )
return;
F_2 ( F_4 ( V_425 ) & V_426 ) ;
F_110 ( V_4 , V_21 -> V_72 ) ;
F_40 ( V_427 , V_422 -> V_423 . V_428 ) ;
F_40 ( V_425 , V_422 -> V_423 . V_424 ) ;
F_40 ( F_303 ( V_21 -> V_72 ) , 0 ) ;
}
enum V_429
F_304 ( struct V_22 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_109 . V_2 ;
struct V_87 * V_430 ;
switch ( V_22 -> type ) {
case V_431 :
F_305 ( ! F_61 ( V_2 ) ) ;
case V_375 :
case V_33 :
case V_307 :
V_430 = F_306 ( & V_22 -> V_109 ) ;
switch ( V_430 -> V_88 ) {
case V_432 :
return V_433 ;
case V_90 :
return V_434 ;
case V_92 :
return V_435 ;
case V_94 :
return V_436 ;
default:
F_305 ( 1 ) ;
return V_437 ;
}
case V_34 :
return V_438 ;
case V_215 :
return V_439 ;
default:
return V_437 ;
}
}
static unsigned long F_307 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_22 * V_22 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_72 V_72 = V_64 -> V_72 ;
bool V_440 = V_64 -> V_68 . V_306 . V_100 ;
unsigned long V_441 ;
enum V_71 V_71 ;
V_71 = F_31 ( V_2 -> V_5 , V_72 ) ;
V_441 = F_308 ( F_309 ( V_72 ) ) ;
V_441 |= F_308 ( F_77 ( V_71 ) ) ;
if ( V_440 )
V_441 |= F_308 ( F_310 ( V_72 ) ) ;
F_10 (dev, crtc, intel_encoder)
V_441 |= F_308 ( F_304 ( V_22 ) ) ;
return V_441 ;
}
void F_311 ( struct V_3 * V_4 ,
bool V_198 )
{
if ( V_4 -> V_442 . V_443 == V_198 )
return;
if ( V_198 )
F_312 ( V_4 , V_444 ) ;
else
F_313 ( V_4 , V_444 ) ;
V_4 -> V_442 . V_443 = V_198 ;
}
static void F_314 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_445 [ V_446 ] = { 0 , } ;
struct V_64 * V_21 ;
F_172 (crtc, &dev->mode_config.crtc_list, base.head) {
enum V_429 V_447 ;
if ( ! V_21 -> V_109 . V_100 )
continue;
V_445 [ V_21 -> V_72 ] = F_307 ( & V_21 -> V_109 ) ;
F_315 (domain, pipe_domains[crtc->pipe])
F_312 ( V_4 , V_447 ) ;
}
F_172 (crtc, &dev->mode_config.crtc_list, base.head) {
enum V_429 V_447 ;
F_315 (domain, crtc->enabled_power_domains)
F_313 ( V_4 , V_447 ) ;
V_21 -> V_448 = V_445 [ V_21 -> V_72 ] ;
}
F_311 ( V_4 , false ) ;
}
int F_316 ( struct V_3 * V_4 )
{
int V_449 , V_450 [] = { 800 , 1600 , 2000 , 2400 } ;
F_53 ( & V_4 -> V_105 ) ;
V_449 = F_54 ( V_4 , V_451 ) &
V_452 ;
F_55 ( & V_4 -> V_105 ) ;
return V_450 [ V_449 ] ;
}
static void F_317 ( struct V_1 * V_2 , int V_453 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_102 , V_454 ;
if ( V_453 >= 320 )
V_454 = 2 ;
else if ( V_453 == 266 )
V_454 = 1 ;
else
V_454 = 0 ;
F_53 ( & V_4 -> V_397 . V_398 ) ;
V_102 = F_318 ( V_4 , V_455 ) ;
V_102 &= ~ V_456 ;
V_102 |= ( V_454 << V_457 ) ;
F_319 ( V_4 , V_455 , V_102 ) ;
if ( F_34 ( ( F_318 ( V_4 , V_455 ) &
V_458 ) == ( V_454 << V_459 ) ,
50 ) ) {
F_116 ( L_84 ) ;
}
F_55 ( & V_4 -> V_397 . V_398 ) ;
if ( V_453 == 400 ) {
T_1 V_460 , V_18 ;
V_18 = F_316 ( V_4 ) ;
V_460 = ( ( V_18 << 1 ) / V_453 ) - 1 ;
F_53 ( & V_4 -> V_105 ) ;
V_102 = F_54 ( V_4 , V_461 ) ;
V_102 &= ~ 0xf ;
V_102 |= V_460 ;
F_320 ( V_4 , V_461 , V_102 ) ;
F_55 ( & V_4 -> V_105 ) ;
}
F_53 ( & V_4 -> V_105 ) ;
V_102 = F_321 ( V_4 , V_462 ) ;
V_102 &= ~ 0x7f ;
if ( V_453 == 400 )
V_102 |= 4500 / 250 ;
else
V_102 |= 3000 / 250 ;
F_322 ( V_4 , V_462 , V_102 ) ;
F_55 ( & V_4 -> V_105 ) ;
F_323 ( V_2 ) ;
}
static int F_324 ( struct V_3 * V_4 )
{
int V_463 , V_18 ;
int V_460 ;
V_18 = F_316 ( V_4 ) ;
F_53 ( & V_4 -> V_105 ) ;
V_460 = F_54 ( V_4 , V_461 ) ;
F_55 ( & V_4 -> V_105 ) ;
V_460 &= 0xf ;
V_463 = ( V_18 << 1 ) / ( V_460 + 1 ) ;
return V_463 ;
}
static int F_325 ( struct V_3 * V_4 ,
int V_464 )
{
int V_463 ;
V_463 = F_324 ( V_4 ) ;
if ( V_464 > 288000 ) {
return 400 ;
} else if ( V_464 > 240000 ) {
return 320 ;
} else
return 266 ;
}
static int F_326 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_64 * V_64 ;
int V_464 = 0 ;
F_172 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_64 -> V_465 )
V_464 = V_49 ( V_464 ,
V_64 -> V_466 -> V_69 . V_70 ) ;
}
return V_464 ;
}
static void F_327 ( struct V_1 * V_2 ,
unsigned * V_467 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 ;
int V_464 = F_326 ( V_4 ) ;
int V_463 = F_324 ( V_4 ) ;
if ( F_325 ( V_4 , V_464 ) == V_463 )
return;
F_172 (intel_crtc, &dev->mode_config.crtc_list,
base.head)
if ( V_64 -> V_109 . V_100 )
* V_467 |= ( 1 << V_64 -> V_72 ) ;
}
static void F_328 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_464 = F_326 ( V_4 ) ;
int V_463 = F_324 ( V_4 ) ;
int V_468 = F_325 ( V_4 , V_464 ) ;
if ( V_468 != V_463 )
F_317 ( V_2 , V_468 ) ;
F_314 ( V_2 ) ;
}
static void F_329 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_72 = V_64 -> V_72 ;
int V_141 = V_64 -> V_141 ;
bool V_469 ;
F_2 ( ! V_21 -> V_100 ) ;
if ( V_64 -> V_65 )
return;
V_64 -> V_65 = true ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_470 )
V_23 -> V_470 ( V_23 ) ;
V_469 = F_9 ( V_21 , V_215 ) ;
if ( ! V_469 )
F_109 ( V_64 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_409 )
V_23 -> V_409 ( V_23 ) ;
F_302 ( V_64 ) ;
F_268 ( V_21 ) ;
F_275 ( V_21 ) ;
F_137 ( V_64 ) ;
F_273 ( V_2 , V_72 , true ) ;
F_147 ( V_4 , V_141 , V_72 ) ;
F_259 ( V_21 ) ;
F_276 ( V_21 , true ) ;
F_199 ( V_2 ) ;
F_10 (dev, crtc, encoder)
V_23 -> V_198 ( V_23 ) ;
}
static void F_330 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_72 = V_64 -> V_72 ;
int V_141 = V_64 -> V_141 ;
F_2 ( ! V_21 -> V_100 ) ;
if ( V_64 -> V_65 )
return;
V_64 -> V_65 = true ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_409 )
V_23 -> V_409 ( V_23 ) ;
F_118 ( V_64 ) ;
F_302 ( V_64 ) ;
F_268 ( V_21 ) ;
F_275 ( V_21 ) ;
F_137 ( V_64 ) ;
F_273 ( V_2 , V_72 , true ) ;
F_147 ( V_4 , V_141 , V_72 ) ;
F_259 ( V_21 ) ;
if ( F_15 ( V_2 ) )
F_300 ( V_4 , V_72 ) ;
F_276 ( V_21 , true ) ;
F_298 ( V_64 , true ) ;
F_199 ( V_2 ) ;
F_10 (dev, crtc, encoder)
V_23 -> V_198 ( V_23 ) ;
}
static void F_331 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_21 -> V_68 . V_423 . V_424 )
return;
F_110 ( V_4 , V_21 -> V_72 ) ;
F_59 ( L_85 ,
F_4 ( V_425 ) ) ;
F_40 ( V_425 , 0 ) ;
}
static void F_332 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_22 * V_23 ;
int V_72 = V_64 -> V_72 ;
int V_141 = V_64 -> V_141 ;
if ( ! V_64 -> V_65 )
return;
F_10 (dev, crtc, encoder)
V_23 -> V_199 ( V_23 ) ;
F_220 ( V_21 ) ;
F_281 ( V_2 , V_72 ) ;
if ( V_4 -> V_410 . V_141 == V_141 )
F_282 ( V_2 ) ;
F_298 ( V_64 , false ) ;
F_276 ( V_21 , false ) ;
F_263 ( V_21 ) ;
F_149 ( V_4 , V_141 , V_72 ) ;
F_273 ( V_2 , V_72 , false ) ;
F_143 ( V_4 , V_72 ) ;
F_331 ( V_64 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_413 )
V_23 -> V_413 ( V_23 ) ;
if ( F_17 ( V_2 ) && ! F_9 ( V_21 , V_215 ) )
F_120 ( V_4 , V_72 ) ;
else if ( ! F_17 ( V_2 ) )
F_119 ( V_4 , V_72 ) ;
V_64 -> V_65 = false ;
F_275 ( V_21 ) ;
F_199 ( V_2 ) ;
}
static void F_333 ( struct V_20 * V_21 )
{
}
static void F_334 ( struct V_20 * V_21 ,
bool V_100 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_471 * V_472 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
if ( ! V_2 -> V_66 -> V_473 )
return;
V_472 = V_2 -> V_66 -> V_473 -> V_474 ;
if ( ! V_472 -> V_475 )
return;
switch ( V_72 ) {
case 0 :
V_472 -> V_475 -> V_476 = V_100 ? V_21 -> V_381 . V_477 : 0 ;
V_472 -> V_475 -> V_478 = V_100 ? V_21 -> V_381 . V_479 : 0 ;
break;
case 1 :
V_472 -> V_475 -> V_480 = V_100 ? V_21 -> V_381 . V_477 : 0 ;
V_472 -> V_475 -> V_481 = V_100 ? V_21 -> V_381 . V_479 : 0 ;
break;
default:
F_116 ( L_86 , F_69 ( V_72 ) ) ;
break;
}
}
void F_335 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_22 ;
bool V_198 = false ;
F_10 (dev, crtc, intel_encoder)
V_198 |= V_22 -> V_482 ;
if ( V_198 )
V_4 -> V_287 . V_483 ( V_21 ) ;
else
V_4 -> V_287 . V_484 ( V_21 ) ;
F_334 ( V_21 , V_198 ) ;
}
static void F_336 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_485 * V_486 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
F_2 ( ! V_21 -> V_100 ) ;
V_4 -> V_287 . V_484 ( V_21 ) ;
V_64 -> V_487 = false ;
F_334 ( V_21 , false ) ;
V_4 -> V_287 . V_488 ( V_21 ) ;
F_337 ( V_2 -> V_5 , F_30 ( V_21 ) -> V_141 ) ;
F_138 ( V_4 , F_30 ( V_21 ) -> V_72 ) ;
F_110 ( V_2 -> V_5 , F_30 ( V_21 ) -> V_72 ) ;
if ( V_21 -> V_66 -> V_67 ) {
F_53 ( & V_2 -> V_268 ) ;
F_161 ( F_168 ( V_21 -> V_66 -> V_67 ) -> V_223 ) ;
F_55 ( & V_2 -> V_268 ) ;
V_21 -> V_66 -> V_67 = NULL ;
}
F_172 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_486 -> V_23 || ! V_486 -> V_23 -> V_21 )
continue;
if ( V_486 -> V_23 -> V_21 != V_21 )
continue;
V_486 -> V_489 = V_490 ;
F_338 ( V_486 -> V_23 ) -> V_482 = false ;
}
}
void F_339 ( struct V_491 * V_23 )
{
struct V_22 * V_22 = F_338 ( V_23 ) ;
F_340 ( V_23 ) ;
F_171 ( V_22 ) ;
}
static void F_341 ( struct V_22 * V_23 , int V_381 )
{
if ( V_381 == V_492 ) {
V_23 -> V_482 = true ;
F_335 ( V_23 -> V_109 . V_21 ) ;
} else {
V_23 -> V_482 = false ;
F_335 ( V_23 -> V_109 . V_21 ) ;
}
}
static void F_342 ( struct V_493 * V_486 )
{
if ( V_486 -> V_115 ( V_486 ) ) {
struct V_22 * V_23 = V_486 -> V_23 ;
struct V_20 * V_21 ;
bool V_494 ;
enum V_72 V_72 ;
F_36 ( L_87 ,
V_486 -> V_109 . V_109 . V_197 ,
F_343 ( & V_486 -> V_109 ) ) ;
F_46 ( V_486 -> V_109 . V_489 == V_490 ,
L_88 ) ;
F_46 ( V_486 -> V_109 . V_23 != & V_23 -> V_109 ,
L_89 ) ;
F_46 ( ! V_23 -> V_482 ,
L_90 ) ;
V_494 = V_23 -> V_115 ( V_23 , & V_72 ) ;
F_46 ( ! V_494 , L_91 ) ;
if ( F_2 ( ! V_23 -> V_109 . V_21 ) )
return;
V_21 = V_23 -> V_109 . V_21 ;
F_46 ( ! V_21 -> V_100 , L_92 ) ;
F_46 ( ! F_30 ( V_21 ) -> V_65 , L_93 ) ;
F_46 ( V_72 != F_30 ( V_21 ) -> V_72 ,
L_94 ) ;
}
}
void F_344 ( struct V_485 * V_486 , int V_381 )
{
if ( V_381 != V_492 )
V_381 = V_490 ;
if ( V_381 == V_486 -> V_489 )
return;
V_486 -> V_489 = V_381 ;
if ( V_486 -> V_23 )
F_341 ( F_338 ( V_486 -> V_23 ) , V_381 ) ;
F_345 ( V_486 -> V_2 ) ;
}
bool F_346 ( struct V_493 * V_486 )
{
enum V_72 V_72 = 0 ;
struct V_22 * V_23 = V_486 -> V_23 ;
return V_23 -> V_115 ( V_23 , & V_72 ) ;
}
static bool F_347 ( struct V_1 * V_2 , enum V_72 V_72 ,
struct V_421 * V_422 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_319 =
F_30 ( V_4 -> V_73 [ V_134 ] ) ;
F_36 ( L_95 ,
F_69 ( V_72 ) , V_422 -> V_328 ) ;
if ( V_422 -> V_328 > 4 ) {
F_36 ( L_96 ,
F_69 ( V_72 ) , V_422 -> V_328 ) ;
return false ;
}
if ( F_142 ( V_2 ) || F_180 ( V_2 ) ) {
if ( V_422 -> V_328 > 2 ) {
F_36 ( L_97 ,
V_422 -> V_328 ) ;
return false ;
} else {
return true ;
}
}
if ( F_39 ( V_2 ) -> V_300 == 2 )
return true ;
switch ( V_72 ) {
case V_125 :
return true ;
case V_134 :
if ( V_4 -> V_73 [ V_321 ] -> V_100 &&
V_422 -> V_328 > 2 ) {
F_36 ( L_98 ,
F_69 ( V_72 ) , V_422 -> V_328 ) ;
return false ;
}
return true ;
case V_321 :
if ( ! F_203 ( V_319 ) ||
V_319 -> V_68 . V_328 <= 2 ) {
if ( V_422 -> V_328 > 2 ) {
F_36 ( L_98 ,
F_69 ( V_72 ) , V_422 -> V_328 ) ;
return false ;
}
} else {
F_36 ( L_99 ) ;
return false ;
}
return true ;
default:
F_122 () ;
}
}
static int F_348 ( struct V_64 * V_64 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = V_64 -> V_109 . V_2 ;
struct V_303 * V_69 = & V_422 -> V_69 ;
int V_495 , V_496 , V_497 ;
bool V_498 , V_499 = false ;
V_333:
V_496 = F_5 ( V_2 ) * F_349 ( 100 ) / F_350 ( 1 ) / 10 ;
V_497 = V_69 -> V_70 ;
V_495 = F_351 ( V_497 , V_496 ,
V_422 -> V_500 ) ;
V_422 -> V_328 = V_495 ;
F_352 ( V_422 -> V_500 , V_495 , V_497 ,
V_496 , & V_422 -> V_501 ) ;
V_498 = F_347 ( V_64 -> V_109 . V_2 ,
V_64 -> V_72 , V_422 ) ;
if ( ! V_498 && V_422 -> V_500 > 6 * 3 ) {
V_422 -> V_500 -= 2 * 3 ;
F_36 ( L_100 ,
V_422 -> V_500 ) ;
V_499 = true ;
V_422 -> V_502 = true ;
goto V_333;
}
if ( V_499 )
return V_503 ;
return V_498 ? 0 : - V_232 ;
}
static void F_353 ( struct V_64 * V_21 ,
struct V_421 * V_422 )
{
V_422 -> V_396 = V_301 . V_504 &&
F_277 ( V_21 ) &&
V_422 -> V_500 <= 24 ;
}
static int F_354 ( struct V_64 * V_21 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_303 * V_69 = & V_422 -> V_69 ;
if ( F_39 ( V_2 ) -> V_78 < 4 ) {
struct V_3 * V_4 = V_2 -> V_5 ;
int V_505 =
V_4 -> V_287 . V_506 ( V_2 ) ;
if ( ( V_21 -> V_72 == V_125 || F_355 ( V_2 ) ) &&
V_69 -> V_70 > V_505 * 9 / 10 ) {
V_505 *= 2 ;
V_422 -> V_507 = true ;
}
if ( V_69 -> V_70 > V_505 * 9 / 10 )
return - V_232 ;
}
if ( ( F_9 ( & V_21 -> V_109 , V_25 ) &&
F_12 ( V_2 ) ) || V_422 -> V_507 )
V_422 -> V_308 &= ~ 1 ;
if ( ( F_39 ( V_2 ) -> V_78 > 4 || F_15 ( V_2 ) ) &&
V_69 -> V_508 == V_69 -> V_477 )
return - V_232 ;
if ( ( F_15 ( V_2 ) || F_17 ( V_2 ) ) && V_422 -> V_500 > 10 * 3 ) {
V_422 -> V_500 = 10 * 3 ;
} else if ( F_39 ( V_2 ) -> V_78 <= 4 && V_422 -> V_500 > 8 * 3 ) {
V_422 -> V_500 = 8 * 3 ;
}
if ( F_278 ( V_2 ) )
F_353 ( V_21 , V_422 ) ;
if ( F_48 ( V_2 ) || F_90 ( V_2 ) )
V_422 -> V_110 = V_21 -> V_68 . V_110 ;
if ( V_422 -> V_216 )
return F_348 ( V_21 , V_422 ) ;
return 0 ;
}
static int F_356 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_357 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_358 ( struct V_1 * V_2 )
{
return 333000 ;
}
static int F_359 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_360 ( struct V_1 * V_2 )
{
T_5 V_509 = 0 ;
F_361 ( V_2 -> V_510 , V_511 , & V_509 ) ;
switch ( V_509 & V_512 ) {
case V_513 :
return 267000 ;
case V_514 :
return 333000 ;
case V_515 :
return 444000 ;
case V_516 :
return 200000 ;
default:
F_116 ( L_101 , V_509 ) ;
case V_517 :
return 133000 ;
case V_518 :
return 167000 ;
}
}
static int F_362 ( struct V_1 * V_2 )
{
T_5 V_509 = 0 ;
F_361 ( V_2 -> V_510 , V_511 , & V_509 ) ;
if ( V_509 & V_519 )
return 133000 ;
else {
switch ( V_509 & V_512 ) {
case V_520 :
return 333000 ;
default:
case V_521 :
return 190000 ;
}
}
}
static int F_363 ( struct V_1 * V_2 )
{
return 266000 ;
}
static int F_364 ( struct V_1 * V_2 )
{
T_5 V_522 = 0 ;
switch ( V_522 & V_523 ) {
case V_524 :
case V_525 :
return 200000 ;
case V_526 :
return 250000 ;
case V_527 :
return 133000 ;
}
return 0 ;
}
static int F_365 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_366 ( T_4 * V_528 , T_4 * V_529 )
{
while ( * V_528 > V_530 ||
* V_529 > V_530 ) {
* V_528 >>= 1 ;
* V_529 >>= 1 ;
}
}
static void F_367 ( unsigned int V_11 , unsigned int V_17 ,
T_4 * V_531 , T_4 * V_532 )
{
* V_532 = F_368 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_531 = F_28 ( ( V_533 ) V_11 * * V_532 , V_17 ) ;
F_366 ( V_531 , V_532 ) ;
}
void
F_352 ( int V_284 , int V_534 ,
int V_535 , int V_536 ,
struct V_537 * V_538 )
{
V_538 -> V_539 = 64 ;
F_367 ( V_284 * V_535 ,
V_536 * V_534 * 8 ,
& V_538 -> V_540 , & V_538 -> V_541 ) ;
F_367 ( V_535 , V_536 ,
& V_538 -> V_542 , & V_538 -> V_543 ) ;
}
static inline bool F_369 ( struct V_3 * V_4 )
{
if ( V_301 . V_544 >= 0 )
return V_301 . V_544 != 0 ;
return V_4 -> V_545 . V_546
&& ! ( V_4 -> V_138 & V_547 ) ;
}
static int F_370 ( struct V_20 * V_21 , int V_548 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_10 ;
if ( F_17 ( V_2 ) ) {
V_10 = 100000 ;
} else if ( F_9 ( V_21 , V_25 ) &&
F_369 ( V_4 ) && V_548 < 2 ) {
V_10 = V_4 -> V_545 . V_549 ;
F_36 ( L_102 , V_10 ) ;
} else if ( ! F_18 ( V_2 ) ) {
V_10 = 96000 ;
} else {
V_10 = 48000 ;
}
return V_10 ;
}
static T_4 F_371 ( struct V_47 * V_47 )
{
return ( 1 << V_47 -> V_17 ) << 16 | V_47 -> V_13 ;
}
static T_4 F_372 ( struct V_47 * V_47 )
{
return V_47 -> V_17 << 16 | V_47 -> V_12 << 8 | V_47 -> V_13 ;
}
static void F_373 ( struct V_64 * V_21 ,
T_2 * V_550 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_72 = V_21 -> V_72 ;
T_1 V_551 , V_552 = 0 ;
if ( F_16 ( V_2 ) ) {
V_551 = F_371 ( & V_21 -> V_68 . V_47 ) ;
if ( V_550 )
V_552 = F_371 ( V_550 ) ;
} else {
V_551 = F_372 ( & V_21 -> V_68 . V_47 ) ;
if ( V_550 )
V_552 = F_372 ( V_550 ) ;
}
F_40 ( F_374 ( V_72 ) , V_551 ) ;
V_21 -> V_68 . V_188 . V_553 = V_551 ;
V_21 -> V_554 = false ;
if ( F_9 ( & V_21 -> V_109 , V_25 ) &&
V_550 && V_301 . V_555 ) {
F_40 ( F_375 ( V_72 ) , V_552 ) ;
V_21 -> V_68 . V_188 . V_556 = V_552 ;
V_21 -> V_554 = true ;
} else {
F_40 ( F_375 ( V_72 ) , V_551 ) ;
V_21 -> V_68 . V_188 . V_556 = V_551 ;
}
}
static void F_376 ( struct V_3 * V_4 , enum V_72
V_72 )
{
T_1 V_557 ;
V_557 = F_377 ( V_4 , V_72 , F_378 ( 1 ) ) ;
V_557 &= 0xffffff00 ;
V_557 |= 0x00000030 ;
F_379 ( V_4 , V_72 , F_378 ( 1 ) , V_557 ) ;
V_557 = F_377 ( V_4 , V_72 , V_558 ) ;
V_557 &= 0x8cffffff ;
V_557 = 0x8c000000 ;
F_379 ( V_4 , V_72 , V_558 , V_557 ) ;
V_557 = F_377 ( V_4 , V_72 , F_378 ( 1 ) ) ;
V_557 &= 0xffffff00 ;
F_379 ( V_4 , V_72 , F_378 ( 1 ) , V_557 ) ;
V_557 = F_377 ( V_4 , V_72 , V_558 ) ;
V_557 &= 0x00ffffff ;
V_557 |= 0xb0000000 ;
F_379 ( V_4 , V_72 , V_558 , V_557 ) ;
}
static void F_380 ( struct V_64 * V_21 ,
struct V_537 * V_538 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_72 = V_21 -> V_72 ;
F_40 ( F_381 ( V_72 ) , F_382 ( V_538 -> V_539 ) | V_538 -> V_540 ) ;
F_40 ( F_383 ( V_72 ) , V_538 -> V_541 ) ;
F_40 ( F_384 ( V_72 ) , V_538 -> V_542 ) ;
F_40 ( F_385 ( V_72 ) , V_538 -> V_543 ) ;
}
static void F_386 ( struct V_64 * V_21 ,
struct V_537 * V_538 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_72 = V_21 -> V_72 ;
enum V_71 V_71 = V_21 -> V_68 . V_74 ;
if ( F_39 ( V_2 ) -> V_78 >= 5 ) {
F_40 ( F_249 ( V_71 ) , F_382 ( V_538 -> V_539 ) | V_538 -> V_540 ) ;
F_40 ( F_387 ( V_71 ) , V_538 -> V_541 ) ;
F_40 ( F_388 ( V_71 ) , V_538 -> V_542 ) ;
F_40 ( F_389 ( V_71 ) , V_538 -> V_543 ) ;
} else {
F_40 ( F_390 ( V_72 ) , F_382 ( V_538 -> V_539 ) | V_538 -> V_540 ) ;
F_40 ( F_391 ( V_72 ) , V_538 -> V_541 ) ;
F_40 ( F_392 ( V_72 ) , V_538 -> V_542 ) ;
F_40 ( F_393 ( V_72 ) , V_538 -> V_543 ) ;
}
}
static void F_394 ( struct V_64 * V_21 )
{
if ( V_21 -> V_68 . V_216 )
F_380 ( V_21 , & V_21 -> V_68 . V_559 ) ;
else
F_386 ( V_21 , & V_21 -> V_68 . V_559 ) ;
}
static void F_395 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_72 = V_21 -> V_72 ;
T_1 V_47 , V_560 ;
T_1 V_561 , V_562 , V_563 , V_564 , V_565 ;
T_1 V_566 , V_557 , V_190 ;
F_53 ( & V_4 -> V_105 ) ;
V_561 = V_21 -> V_68 . V_47 . V_17 ;
V_562 = V_21 -> V_68 . V_47 . V_12 ;
V_563 = V_21 -> V_68 . V_47 . V_13 ;
V_564 = V_21 -> V_68 . V_47 . V_15 ;
V_565 = V_21 -> V_68 . V_47 . V_16 ;
if ( V_72 )
F_376 ( V_4 , V_72 ) ;
F_379 ( V_4 , V_72 , V_567 , 0x0100000f ) ;
V_557 = F_377 ( V_4 , V_72 , F_396 ( V_72 ) ) ;
V_557 &= 0x00ffffff ;
F_379 ( V_4 , V_72 , F_396 ( V_72 ) , V_557 ) ;
F_379 ( V_4 , V_72 , V_568 , 0x610 ) ;
V_560 = ( ( V_562 << V_569 ) | ( V_563 & V_570 ) ) ;
V_560 |= ( ( V_564 << V_571 ) | ( V_565 << V_572 ) ) ;
V_560 |= ( ( V_561 << V_573 ) ) ;
V_560 |= ( 1 << V_574 ) ;
V_560 |= ( V_575 << V_576 ) ;
F_379 ( V_4 , V_72 , F_397 ( V_72 ) , V_560 ) ;
V_560 |= V_577 ;
F_379 ( V_4 , V_72 , F_397 ( V_72 ) , V_560 ) ;
if ( V_21 -> V_68 . V_578 == 162000 ||
F_9 ( & V_21 -> V_109 , V_34 ) ||
F_9 ( & V_21 -> V_109 , V_33 ) )
F_379 ( V_4 , V_72 , F_398 ( V_72 ) ,
0x009f0003 ) ;
else
F_379 ( V_4 , V_72 , F_398 ( V_72 ) ,
0x00d0000f ) ;
if ( F_9 ( & V_21 -> V_109 , V_307 ) ||
F_9 ( & V_21 -> V_109 , V_375 ) ) {
if ( ! V_72 )
F_379 ( V_4 , V_72 , F_399 ( V_72 ) ,
0x0df40000 ) ;
else
F_379 ( V_4 , V_72 , F_399 ( V_72 ) ,
0x0df70000 ) ;
} else {
if ( ! V_72 )
F_379 ( V_4 , V_72 , F_399 ( V_72 ) ,
0x0df70000 ) ;
else
F_379 ( V_4 , V_72 , F_399 ( V_72 ) ,
0x0df40000 ) ;
}
V_566 = F_377 ( V_4 , V_72 , F_400 ( V_72 ) ) ;
V_566 = ( V_566 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_9 ( & V_21 -> V_109 , V_375 ) ||
F_9 ( & V_21 -> V_109 , V_307 ) )
V_566 |= 0x01000000 ;
F_379 ( V_4 , V_72 , F_400 ( V_72 ) , V_566 ) ;
F_379 ( V_4 , V_72 , F_401 ( V_72 ) , 0x87871000 ) ;
V_47 = V_579 | V_184 |
V_580 | V_581 ;
if ( V_72 == V_134 )
V_47 |= V_185 ;
V_47 |= V_104 ;
V_21 -> V_68 . V_188 . V_47 = V_47 ;
V_190 = ( V_21 -> V_68 . V_582 - 1 )
<< V_583 ;
V_21 -> V_68 . V_188 . V_190 = V_190 ;
if ( V_21 -> V_68 . V_584 )
F_394 ( V_21 ) ;
F_55 ( & V_4 -> V_105 ) ;
}
static void F_402 ( struct V_64 * V_21 ,
T_2 * V_550 ,
int V_548 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_47 ;
bool V_585 ;
struct V_47 * clock = & V_21 -> V_68 . V_47 ;
F_373 ( V_21 , V_550 ) ;
V_585 = F_9 ( & V_21 -> V_109 , V_36 ) ||
F_9 ( & V_21 -> V_109 , V_33 ) ;
V_47 = V_580 ;
if ( F_9 ( & V_21 -> V_109 , V_25 ) )
V_47 |= V_586 ;
else
V_47 |= V_587 ;
if ( F_403 ( V_2 ) || F_404 ( V_2 ) || F_405 ( V_2 ) ) {
V_47 |= ( V_21 -> V_68 . V_582 - 1 )
<< V_588 ;
}
if ( V_585 )
V_47 |= V_589 ;
if ( F_9 ( & V_21 -> V_109 , V_375 ) )
V_47 |= V_589 ;
if ( F_16 ( V_2 ) )
V_47 |= ( 1 << ( clock -> V_15 - 1 ) ) << V_590 ;
else {
V_47 |= ( 1 << ( clock -> V_15 - 1 ) ) << V_591 ;
if ( F_15 ( V_2 ) && V_550 )
V_47 |= ( 1 << ( V_550 -> V_15 - 1 ) ) << V_592 ;
}
switch ( clock -> V_16 ) {
case 5 :
V_47 |= V_593 ;
break;
case 7 :
V_47 |= V_594 ;
break;
case 10 :
V_47 |= V_595 ;
break;
case 14 :
V_47 |= V_596 ;
break;
}
if ( F_39 ( V_2 ) -> V_78 >= 4 )
V_47 |= ( 6 << V_597 ) ;
if ( V_21 -> V_68 . V_598 )
V_47 |= V_599 ;
else if ( F_9 ( & V_21 -> V_109 , V_25 ) &&
F_369 ( V_4 ) && V_548 < 2 )
V_47 |= V_600 ;
else
V_47 |= V_601 ;
V_47 |= V_104 ;
V_21 -> V_68 . V_188 . V_47 = V_47 ;
if ( F_39 ( V_2 ) -> V_78 >= 4 ) {
T_1 V_190 = ( V_21 -> V_68 . V_582 - 1 )
<< V_583 ;
V_21 -> V_68 . V_188 . V_190 = V_190 ;
}
if ( V_21 -> V_68 . V_584 )
F_394 ( V_21 ) ;
}
static void F_406 ( struct V_64 * V_21 ,
T_2 * V_550 ,
int V_548 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_47 ;
struct V_47 * clock = & V_21 -> V_68 . V_47 ;
F_373 ( V_21 , V_550 ) ;
V_47 = V_580 ;
if ( F_9 ( & V_21 -> V_109 , V_25 ) ) {
V_47 |= ( 1 << ( clock -> V_15 - 1 ) ) << V_591 ;
} else {
if ( clock -> V_15 == 2 )
V_47 |= V_602 ;
else
V_47 |= ( clock -> V_15 - 2 ) << V_591 ;
if ( clock -> V_16 == 4 )
V_47 |= V_603 ;
}
if ( F_9 ( & V_21 -> V_109 , V_44 ) )
V_47 |= V_604 ;
if ( F_9 ( & V_21 -> V_109 , V_25 ) &&
F_369 ( V_4 ) && V_548 < 2 )
V_47 |= V_600 ;
else
V_47 |= V_601 ;
V_47 |= V_104 ;
V_21 -> V_68 . V_188 . V_47 = V_47 ;
}
static void F_407 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_72 V_72 = V_64 -> V_72 ;
enum V_71 V_74 = V_64 -> V_68 . V_74 ;
struct V_303 * V_69 =
& V_64 -> V_68 . V_69 ;
T_4 V_605 , V_606 ;
int V_607 = 0 ;
V_605 = V_69 -> V_605 ;
V_606 = V_69 -> V_606 ;
if ( V_69 -> V_293 & V_608 ) {
V_605 -= 1 ;
V_606 -= 1 ;
if ( F_9 ( & V_64 -> V_109 , V_36 ) )
V_607 = ( V_69 -> V_609 - 1 ) / 2 ;
else
V_607 = V_69 -> V_610 -
V_69 -> V_609 / 2 ;
if ( V_607 < 0 )
V_607 += V_69 -> V_609 ;
}
if ( F_39 ( V_2 ) -> V_78 > 3 )
F_40 ( F_244 ( V_74 ) , V_607 ) ;
F_40 ( F_232 ( V_74 ) ,
( V_69 -> V_304 - 1 ) |
( ( V_69 -> V_609 - 1 ) << 16 ) ) ;
F_40 ( F_234 ( V_74 ) ,
( V_69 -> V_611 - 1 ) |
( ( V_69 -> V_612 - 1 ) << 16 ) ) ;
F_40 ( F_236 ( V_74 ) ,
( V_69 -> V_610 - 1 ) |
( ( V_69 -> V_613 - 1 ) << 16 ) ) ;
F_40 ( F_238 ( V_74 ) ,
( V_69 -> V_305 - 1 ) |
( ( V_605 - 1 ) << 16 ) ) ;
F_40 ( F_240 ( V_74 ) ,
( V_69 -> V_614 - 1 ) |
( ( V_606 - 1 ) << 16 ) ) ;
F_40 ( F_242 ( V_74 ) ,
( V_69 -> V_615 - 1 ) |
( ( V_69 -> V_616 - 1 ) << 16 ) ) ;
if ( F_142 ( V_2 ) && V_74 == V_617 &&
( V_72 == V_134 || V_72 == V_321 ) )
F_40 ( F_238 ( V_72 ) , F_4 ( F_238 ( V_74 ) ) ) ;
F_40 ( F_195 ( V_72 ) ,
( ( V_64 -> V_68 . V_308 - 1 ) << 16 ) |
( V_64 -> V_68 . V_309 - 1 ) ) ;
}
static void F_408 ( struct V_64 * V_21 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_71 V_74 = V_422 -> V_74 ;
T_4 V_618 ;
V_618 = F_4 ( F_232 ( V_74 ) ) ;
V_422 -> V_69 . V_304 = ( V_618 & 0xffff ) + 1 ;
V_422 -> V_69 . V_609 = ( ( V_618 >> 16 ) & 0xffff ) + 1 ;
V_618 = F_4 ( F_234 ( V_74 ) ) ;
V_422 -> V_69 . V_611 = ( V_618 & 0xffff ) + 1 ;
V_422 -> V_69 . V_612 = ( ( V_618 >> 16 ) & 0xffff ) + 1 ;
V_618 = F_4 ( F_236 ( V_74 ) ) ;
V_422 -> V_69 . V_610 = ( V_618 & 0xffff ) + 1 ;
V_422 -> V_69 . V_613 = ( ( V_618 >> 16 ) & 0xffff ) + 1 ;
V_618 = F_4 ( F_238 ( V_74 ) ) ;
V_422 -> V_69 . V_305 = ( V_618 & 0xffff ) + 1 ;
V_422 -> V_69 . V_605 = ( ( V_618 >> 16 ) & 0xffff ) + 1 ;
V_618 = F_4 ( F_240 ( V_74 ) ) ;
V_422 -> V_69 . V_614 = ( V_618 & 0xffff ) + 1 ;
V_422 -> V_69 . V_606 = ( ( V_618 >> 16 ) & 0xffff ) + 1 ;
V_618 = F_4 ( F_242 ( V_74 ) ) ;
V_422 -> V_69 . V_615 = ( V_618 & 0xffff ) + 1 ;
V_422 -> V_69 . V_616 = ( ( V_618 >> 16 ) & 0xffff ) + 1 ;
if ( F_4 ( F_45 ( V_74 ) ) & V_204 ) {
V_422 -> V_69 . V_293 |= V_608 ;
V_422 -> V_69 . V_605 += 1 ;
V_422 -> V_69 . V_606 += 1 ;
}
V_618 = F_4 ( F_195 ( V_21 -> V_72 ) ) ;
V_422 -> V_309 = ( V_618 & 0xffff ) + 1 ;
V_422 -> V_308 = ( ( V_618 >> 16 ) & 0xffff ) + 1 ;
V_422 -> V_619 . V_479 = V_422 -> V_309 ;
V_422 -> V_619 . V_477 = V_422 -> V_308 ;
}
void F_409 ( struct V_303 * V_381 ,
struct V_421 * V_422 )
{
V_381 -> V_477 = V_422 -> V_69 . V_304 ;
V_381 -> V_620 = V_422 -> V_69 . V_609 ;
V_381 -> V_508 = V_422 -> V_69 . V_610 ;
V_381 -> V_621 = V_422 -> V_69 . V_613 ;
V_381 -> V_479 = V_422 -> V_69 . V_305 ;
V_381 -> V_622 = V_422 -> V_69 . V_605 ;
V_381 -> V_623 = V_422 -> V_69 . V_615 ;
V_381 -> V_624 = V_422 -> V_69 . V_616 ;
V_381 -> V_293 = V_422 -> V_69 . V_293 ;
V_381 -> clock = V_422 -> V_69 . V_70 ;
V_381 -> V_293 |= V_422 -> V_69 . V_293 ;
}
static void F_410 ( struct V_64 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_625 ;
V_625 = 0 ;
if ( V_4 -> V_138 & V_139 &&
F_4 ( F_45 ( V_64 -> V_72 ) ) & V_140 )
V_625 |= V_140 ;
if ( V_64 -> V_68 . V_507 )
V_625 |= V_626 ;
if ( F_15 ( V_2 ) || F_17 ( V_2 ) ) {
if ( V_64 -> V_68 . V_627 && V_64 -> V_68 . V_500 != 30 )
V_625 |= V_628 |
V_629 ;
switch ( V_64 -> V_68 . V_500 ) {
case 18 :
V_625 |= V_630 ;
break;
case 24 :
V_625 |= V_631 ;
break;
case 30 :
V_625 |= V_632 ;
break;
default:
F_122 () ;
}
}
if ( F_411 ( V_2 ) ) {
if ( V_64 -> V_554 ) {
F_36 ( L_103 ) ;
V_625 |= V_633 ;
} else {
F_36 ( L_104 ) ;
}
}
if ( V_64 -> V_68 . V_69 . V_293 & V_608 ) {
if ( F_39 ( V_2 ) -> V_78 < 4 ||
F_9 ( & V_64 -> V_109 , V_36 ) )
V_625 |= V_634 ;
else
V_625 |= V_635 ;
} else
V_625 |= V_636 ;
if ( F_17 ( V_2 ) && V_64 -> V_68 . V_637 )
V_625 |= V_638 ;
F_40 ( F_45 ( V_64 -> V_72 ) , V_625 ) ;
F_114 ( F_45 ( V_64 -> V_72 ) ) ;
}
static int F_412 ( struct V_20 * V_21 ,
int V_237 , int V_238 ,
struct V_272 * V_67 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
int V_141 = V_64 -> V_141 ;
int V_10 , V_548 = 0 ;
T_2 clock , V_550 ;
T_1 V_275 ;
bool V_639 , V_640 = false ;
bool V_641 = false , V_469 = false ;
struct V_22 * V_23 ;
const T_3 * V_24 ;
int V_227 ;
F_10 (dev, crtc, encoder) {
switch ( V_23 -> type ) {
case V_25 :
V_641 = true ;
break;
case V_215 :
V_469 = true ;
break;
}
V_548 ++ ;
}
if ( V_469 )
goto V_642;
if ( ! V_64 -> V_68 . V_643 ) {
V_10 = F_370 ( V_21 , V_548 ) ;
V_24 = F_14 ( V_21 , V_10 ) ;
V_639 = V_4 -> V_287 . V_644 ( V_24 , V_21 ,
V_64 -> V_68 . V_578 ,
V_10 , NULL , & clock ) ;
if ( ! V_639 ) {
F_116 ( L_105 ) ;
return - V_232 ;
}
if ( V_641 && V_4 -> V_645 ) {
V_640 =
V_4 -> V_287 . V_644 ( V_24 , V_21 ,
V_4 -> V_646 ,
V_10 , & clock ,
& V_550 ) ;
}
V_64 -> V_68 . V_47 . V_17 = clock . V_17 ;
V_64 -> V_68 . V_47 . V_12 = clock . V_12 ;
V_64 -> V_68 . V_47 . V_13 = clock . V_13 ;
V_64 -> V_68 . V_47 . V_15 = clock . V_15 ;
V_64 -> V_68 . V_47 . V_16 = clock . V_16 ;
}
if ( F_18 ( V_2 ) ) {
F_406 ( V_64 ,
V_640 ? & V_550 : NULL ,
V_548 ) ;
} else if ( F_17 ( V_2 ) ) {
F_395 ( V_64 ) ;
} else {
F_402 ( V_64 ,
V_640 ? & V_550 : NULL ,
V_548 ) ;
}
V_642:
V_275 = V_647 ;
if ( ! F_17 ( V_2 ) ) {
if ( V_72 == 0 )
V_275 &= ~ V_145 ;
else
V_275 |= V_648 ;
}
F_407 ( V_64 ) ;
F_40 ( F_413 ( V_141 ) ,
( ( V_64 -> V_68 . V_309 - 1 ) << 16 ) |
( V_64 -> V_68 . V_308 - 1 ) ) ;
F_40 ( F_414 ( V_141 ) , 0 ) ;
F_410 ( V_64 ) ;
F_40 ( F_79 ( V_141 ) , V_275 ) ;
F_114 ( F_79 ( V_141 ) ) ;
V_227 = F_194 ( V_21 , V_237 , V_238 , V_67 ) ;
return V_227 ;
}
static void F_415 ( struct V_64 * V_21 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_618 ;
if ( F_39 ( V_2 ) -> V_78 <= 3 && ( F_113 ( V_2 ) || ! F_112 ( V_2 ) ) )
return;
V_618 = F_4 ( V_425 ) ;
if ( ! ( V_618 & V_426 ) )
return;
if ( F_39 ( V_2 ) -> V_78 < 4 ) {
if ( V_21 -> V_72 != V_134 )
return;
} else {
if ( ( V_618 & V_649 ) != ( V_21 -> V_72 << V_650 ) )
return;
}
V_422 -> V_423 . V_424 = V_618 ;
V_422 -> V_423 . V_428 = F_4 ( V_427 ) ;
if ( F_39 ( V_2 ) -> V_78 < 5 )
V_422 -> V_423 . V_651 =
F_4 ( V_130 ) & V_652 ;
}
static void F_416 ( struct V_64 * V_21 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_72 = V_422 -> V_74 ;
T_2 clock ;
T_1 V_560 ;
int V_10 = 100000 ;
F_53 ( & V_4 -> V_105 ) ;
V_560 = F_377 ( V_4 , V_72 , F_397 ( V_72 ) ) ;
F_55 ( & V_4 -> V_105 ) ;
clock . V_12 = ( V_560 >> V_569 ) & 7 ;
clock . V_13 = V_560 & V_570 ;
clock . V_17 = ( V_560 >> V_573 ) & 0xf ;
clock . V_15 = ( V_560 >> V_571 ) & 7 ;
clock . V_16 = ( V_560 >> V_572 ) & 0x1f ;
F_7 ( V_10 , & clock ) ;
V_422 -> V_578 = clock . V_19 / 5 ;
}
static void F_417 ( struct V_64 * V_21 ,
struct V_259 * V_260 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_102 , V_109 , V_243 ;
int V_72 = V_21 -> V_72 , V_141 = V_21 -> V_141 ;
int V_653 , V_266 ;
int V_654 ;
V_21 -> V_109 . V_66 -> V_67 = F_418 ( sizeof( struct V_271 ) , V_655 ) ;
if ( ! V_21 -> V_109 . V_66 -> V_67 ) {
F_36 ( L_106 ) ;
return;
}
V_102 = F_4 ( F_79 ( V_141 ) ) ;
if ( F_39 ( V_2 ) -> V_78 >= 4 )
if ( V_102 & V_282 )
V_260 -> V_220 = true ;
V_266 = V_102 & V_276 ;
V_653 = F_164 ( V_266 ) ;
V_21 -> V_109 . V_66 -> V_67 -> V_266 = V_653 ;
V_21 -> V_109 . V_66 -> V_67 -> V_284 =
F_419 ( V_653 , 0 ) * 8 ;
if ( F_39 ( V_2 ) -> V_78 >= 4 ) {
if ( V_260 -> V_220 )
V_243 = F_4 ( F_177 ( V_141 ) ) ;
else
V_243 = F_4 ( F_178 ( V_141 ) ) ;
V_109 = F_4 ( F_145 ( V_141 ) ) & 0xfffff000 ;
} else {
V_109 = F_4 ( F_146 ( V_141 ) ) ;
}
V_260 -> V_109 = V_109 ;
V_102 = F_4 ( F_195 ( V_72 ) ) ;
V_21 -> V_109 . V_66 -> V_67 -> V_267 = ( ( V_102 >> 16 ) & 0xfff ) + 1 ;
V_21 -> V_109 . V_66 -> V_67 -> V_219 = ( ( V_102 >> 0 ) & 0xfff ) + 1 ;
V_102 = F_4 ( F_176 ( V_72 ) ) ;
V_21 -> V_109 . V_66 -> V_67 -> V_265 [ 0 ] = V_102 & 0xffffff80 ;
V_654 = F_152 ( V_2 , V_21 -> V_109 . V_66 -> V_67 -> V_219 ,
V_260 -> V_220 ) ;
V_260 -> V_263 = F_153 ( V_21 -> V_109 . V_66 -> V_67 -> V_265 [ 0 ] *
V_654 , V_656 ) ;
F_36 ( L_107 ,
V_72 , V_141 , V_21 -> V_109 . V_66 -> V_67 -> V_267 ,
V_21 -> V_109 . V_66 -> V_67 -> V_219 ,
V_21 -> V_109 . V_66 -> V_67 -> V_284 , V_109 ,
V_21 -> V_109 . V_66 -> V_67 -> V_265 [ 0 ] ,
V_260 -> V_263 ) ;
}
static bool F_420 ( struct V_64 * V_21 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_618 ;
if ( ! F_76 ( V_4 ,
F_309 ( V_21 -> V_72 ) ) )
return false ;
V_422 -> V_74 = (enum V_71 ) V_21 -> V_72 ;
V_422 -> V_110 = V_386 ;
V_618 = F_4 ( F_45 ( V_21 -> V_72 ) ) ;
if ( ! ( V_618 & V_140 ) )
return false ;
if ( F_15 ( V_2 ) || F_17 ( V_2 ) ) {
switch ( V_618 & V_202 ) {
case V_630 :
V_422 -> V_500 = 18 ;
break;
case V_631 :
V_422 -> V_500 = 24 ;
break;
case V_632 :
V_422 -> V_500 = 30 ;
break;
default:
break;
}
}
if ( F_39 ( V_2 ) -> V_78 < 4 )
V_422 -> V_507 = V_618 & V_626 ;
F_408 ( V_21 , V_422 ) ;
F_415 ( V_21 , V_422 ) ;
if ( F_39 ( V_2 ) -> V_78 >= 4 ) {
V_618 = F_4 ( F_117 ( V_21 -> V_72 ) ) ;
V_422 -> V_582 =
( ( V_618 & V_657 )
>> V_583 ) + 1 ;
V_422 -> V_188 . V_190 = V_618 ;
} else if ( F_403 ( V_2 ) || F_404 ( V_2 ) || F_405 ( V_2 ) ) {
V_618 = F_4 ( F_51 ( V_21 -> V_72 ) ) ;
V_422 -> V_582 =
( ( V_618 & V_658 )
>> V_588 ) + 1 ;
} else {
V_422 -> V_582 = 1 ;
}
V_422 -> V_188 . V_47 = F_4 ( F_51 ( V_21 -> V_72 ) ) ;
if ( ! F_17 ( V_2 ) ) {
V_422 -> V_188 . V_553 = F_4 ( F_374 ( V_21 -> V_72 ) ) ;
V_422 -> V_188 . V_556 = F_4 ( F_375 ( V_21 -> V_72 ) ) ;
} else {
V_422 -> V_188 . V_47 &= ~ ( V_189 |
V_194 |
V_193 ) ;
}
if ( F_17 ( V_2 ) )
F_416 ( V_21 , V_422 ) ;
else
F_421 ( V_21 , V_422 ) ;
return true ;
}
static void F_422 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_659 * V_660 = & V_2 -> V_660 ;
struct V_22 * V_23 ;
T_1 V_102 , V_661 ;
bool V_662 = false ;
bool V_663 = false ;
bool V_664 = false ;
bool V_665 = false ;
bool V_666 = false ;
F_172 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_23 -> type ) {
case V_25 :
V_664 = true ;
V_662 = true ;
break;
case V_307 :
V_664 = true ;
if ( F_306 ( & V_23 -> V_109 ) -> V_88 == V_432 )
V_663 = true ;
break;
}
}
if ( F_48 ( V_2 ) ) {
V_665 = V_4 -> V_545 . V_667 ;
V_666 = V_665 ;
} else {
V_665 = false ;
V_666 = true ;
}
F_36 ( L_108 ,
V_664 , V_662 , V_665 ) ;
V_102 = F_4 ( V_151 ) ;
V_661 = V_102 ;
V_661 &= ~ V_153 ;
if ( V_665 )
V_661 |= V_668 ;
else
V_661 |= V_669 ;
V_661 &= ~ V_152 ;
V_661 &= ~ V_670 ;
V_661 &= ~ V_671 ;
if ( V_664 ) {
V_661 |= V_672 ;
if ( F_369 ( V_4 ) && V_666 )
V_661 |= V_671 ;
if ( V_663 ) {
if ( F_369 ( V_4 ) && V_666 )
V_661 |= V_673 ;
else
V_661 |= V_674 ;
} else
V_661 |= V_675 ;
} else {
V_661 |= V_676 ;
V_661 |= V_675 ;
}
if ( V_661 == V_102 )
return;
V_102 &= ~ V_153 ;
if ( V_665 )
V_102 |= V_668 ;
else
V_102 |= V_669 ;
if ( V_664 ) {
V_102 &= ~ V_152 ;
V_102 |= V_672 ;
if ( F_369 ( V_4 ) && V_666 ) {
F_36 ( L_109 ) ;
V_102 |= V_671 ;
} else
V_102 &= ~ V_671 ;
F_40 ( V_151 , V_102 ) ;
F_114 ( V_151 ) ;
F_115 ( 200 ) ;
V_102 &= ~ V_670 ;
if ( V_663 ) {
if ( F_369 ( V_4 ) && V_666 ) {
F_36 ( L_110 ) ;
V_102 |= V_673 ;
}
else
V_102 |= V_674 ;
} else
V_102 |= V_675 ;
F_40 ( V_151 , V_102 ) ;
F_114 ( V_151 ) ;
F_115 ( 200 ) ;
} else {
F_36 ( L_111 ) ;
V_102 &= ~ V_670 ;
V_102 |= V_675 ;
F_40 ( V_151 , V_102 ) ;
F_114 ( V_151 ) ;
F_115 ( 200 ) ;
V_102 &= ~ V_152 ;
V_102 |= V_676 ;
V_102 &= ~ V_671 ;
F_40 ( V_151 , V_102 ) ;
F_114 ( V_151 ) ;
F_115 ( 200 ) ;
}
F_111 ( V_102 != V_661 ) ;
}
static void F_423 ( struct V_3 * V_4 )
{
T_4 V_618 ;
V_618 = F_4 ( V_677 ) ;
V_618 |= V_678 ;
F_40 ( V_677 , V_618 ) ;
if ( F_424 ( F_4 ( V_677 ) &
V_679 , 100 ) )
F_116 ( L_112 ) ;
V_618 = F_4 ( V_677 ) ;
V_618 &= ~ V_678 ;
F_40 ( V_677 , V_618 ) ;
if ( F_424 ( ( F_4 ( V_677 ) &
V_679 ) == 0 , 100 ) )
F_116 ( L_113 ) ;
}
static void F_425 ( struct V_3 * V_4 )
{
T_4 V_618 ;
V_618 = F_225 ( V_4 , 0x8008 , V_680 ) ;
V_618 &= ~ ( 0xFF << 24 ) ;
V_618 |= ( 0x12 << 24 ) ;
F_224 ( V_4 , 0x8008 , V_618 , V_680 ) ;
V_618 = F_225 ( V_4 , 0x2008 , V_680 ) ;
V_618 |= ( 1 << 11 ) ;
F_224 ( V_4 , 0x2008 , V_618 , V_680 ) ;
V_618 = F_225 ( V_4 , 0x2108 , V_680 ) ;
V_618 |= ( 1 << 11 ) ;
F_224 ( V_4 , 0x2108 , V_618 , V_680 ) ;
V_618 = F_225 ( V_4 , 0x206C , V_680 ) ;
V_618 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_224 ( V_4 , 0x206C , V_618 , V_680 ) ;
V_618 = F_225 ( V_4 , 0x216C , V_680 ) ;
V_618 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_224 ( V_4 , 0x216C , V_618 , V_680 ) ;
V_618 = F_225 ( V_4 , 0x2080 , V_680 ) ;
V_618 &= ~ ( 7 << 13 ) ;
V_618 |= ( 5 << 13 ) ;
F_224 ( V_4 , 0x2080 , V_618 , V_680 ) ;
V_618 = F_225 ( V_4 , 0x2180 , V_680 ) ;
V_618 &= ~ ( 7 << 13 ) ;
V_618 |= ( 5 << 13 ) ;
F_224 ( V_4 , 0x2180 , V_618 , V_680 ) ;
V_618 = F_225 ( V_4 , 0x208C , V_680 ) ;
V_618 &= ~ 0xFF ;
V_618 |= 0x1C ;
F_224 ( V_4 , 0x208C , V_618 , V_680 ) ;
V_618 = F_225 ( V_4 , 0x218C , V_680 ) ;
V_618 &= ~ 0xFF ;
V_618 |= 0x1C ;
F_224 ( V_4 , 0x218C , V_618 , V_680 ) ;
V_618 = F_225 ( V_4 , 0x2098 , V_680 ) ;
V_618 &= ~ ( 0xFF << 16 ) ;
V_618 |= ( 0x1C << 16 ) ;
F_224 ( V_4 , 0x2098 , V_618 , V_680 ) ;
V_618 = F_225 ( V_4 , 0x2198 , V_680 ) ;
V_618 &= ~ ( 0xFF << 16 ) ;
V_618 |= ( 0x1C << 16 ) ;
F_224 ( V_4 , 0x2198 , V_618 , V_680 ) ;
V_618 = F_225 ( V_4 , 0x20C4 , V_680 ) ;
V_618 |= ( 1 << 27 ) ;
F_224 ( V_4 , 0x20C4 , V_618 , V_680 ) ;
V_618 = F_225 ( V_4 , 0x21C4 , V_680 ) ;
V_618 |= ( 1 << 27 ) ;
F_224 ( V_4 , 0x21C4 , V_618 , V_680 ) ;
V_618 = F_225 ( V_4 , 0x20EC , V_680 ) ;
V_618 &= ~ ( 0xF << 28 ) ;
V_618 |= ( 4 << 28 ) ;
F_224 ( V_4 , 0x20EC , V_618 , V_680 ) ;
V_618 = F_225 ( V_4 , 0x21EC , V_680 ) ;
V_618 &= ~ ( 0xF << 28 ) ;
V_618 |= ( 4 << 28 ) ;
F_224 ( V_4 , 0x21EC , V_618 , V_680 ) ;
}
static void F_426 ( struct V_1 * V_2 , bool V_681 ,
bool V_682 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_80 , V_618 ;
if ( F_46 ( V_682 && ! V_681 , L_114 ) )
V_681 = true ;
if ( F_46 ( V_4 -> V_683 == V_684 &&
V_682 , L_115 ) )
V_682 = false ;
F_53 ( & V_4 -> V_105 ) ;
V_618 = F_225 ( V_4 , V_685 , V_357 ) ;
V_618 &= ~ V_358 ;
V_618 |= V_686 ;
F_224 ( V_4 , V_685 , V_618 , V_357 ) ;
F_115 ( 24 ) ;
if ( V_681 ) {
V_618 = F_225 ( V_4 , V_685 , V_357 ) ;
V_618 &= ~ V_686 ;
F_224 ( V_4 , V_685 , V_618 , V_357 ) ;
if ( V_682 ) {
F_423 ( V_4 ) ;
F_425 ( V_4 ) ;
}
}
V_80 = ( V_4 -> V_683 == V_684 ) ?
V_687 : V_688 ;
V_618 = F_225 ( V_4 , V_80 , V_357 ) ;
V_618 |= V_689 ;
F_224 ( V_4 , V_80 , V_618 , V_357 ) ;
F_55 ( & V_4 -> V_105 ) ;
}
static void F_427 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_80 , V_618 ;
F_53 ( & V_4 -> V_105 ) ;
V_80 = ( V_4 -> V_683 == V_684 ) ?
V_687 : V_688 ;
V_618 = F_225 ( V_4 , V_80 , V_357 ) ;
V_618 &= ~ V_689 ;
F_224 ( V_4 , V_80 , V_618 , V_357 ) ;
V_618 = F_225 ( V_4 , V_685 , V_357 ) ;
if ( ! ( V_618 & V_358 ) ) {
if ( ! ( V_618 & V_686 ) ) {
V_618 |= V_686 ;
F_224 ( V_4 , V_685 , V_618 , V_357 ) ;
F_115 ( 32 ) ;
}
V_618 |= V_358 ;
F_224 ( V_4 , V_685 , V_618 , V_357 ) ;
}
F_55 ( & V_4 -> V_105 ) ;
}
static void F_428 ( struct V_1 * V_2 )
{
struct V_659 * V_660 = & V_2 -> V_660 ;
struct V_22 * V_23 ;
bool V_690 = false ;
F_172 (encoder, &mode_config->encoder_list, base.head) {
switch ( V_23 -> type ) {
case V_34 :
V_690 = true ;
break;
}
}
if ( V_690 )
F_426 ( V_2 , true , true ) ;
else
F_427 ( V_2 ) ;
}
void F_429 ( struct V_1 * V_2 )
{
if ( F_48 ( V_2 ) || F_90 ( V_2 ) )
F_422 ( V_2 ) ;
else if ( F_58 ( V_2 ) )
F_428 ( V_2 ) ;
}
static int F_430 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_23 ;
int V_548 = 0 ;
bool V_641 = false ;
F_10 (dev, crtc, encoder) {
switch ( V_23 -> type ) {
case V_25 :
V_641 = true ;
break;
}
V_548 ++ ;
}
if ( V_641 && F_369 ( V_4 ) && V_548 < 2 ) {
F_36 ( L_102 ,
V_4 -> V_545 . V_549 ) ;
return V_4 -> V_545 . V_549 ;
}
return 120000 ;
}
static void F_431 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
T_4 V_102 ;
V_102 = 0 ;
switch ( V_64 -> V_68 . V_500 ) {
case 18 :
V_102 |= V_630 ;
break;
case 24 :
V_102 |= V_631 ;
break;
case 30 :
V_102 |= V_632 ;
break;
case 36 :
V_102 |= V_691 ;
break;
default:
F_122 () ;
}
if ( V_64 -> V_68 . V_627 )
V_102 |= ( V_628 | V_629 ) ;
if ( V_64 -> V_68 . V_69 . V_293 & V_608 )
V_102 |= V_205 ;
else
V_102 |= V_636 ;
if ( V_64 -> V_68 . V_637 )
V_102 |= V_638 ;
F_40 ( F_45 ( V_72 ) , V_102 ) ;
F_114 ( F_45 ( V_72 ) ) ;
}
static void F_432 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
T_6 V_692 = 0x7800 ;
if ( V_64 -> V_68 . V_637 )
V_692 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_40 ( F_433 ( V_72 ) , V_692 << 16 ) ;
F_40 ( F_434 ( V_72 ) , 0 ) ;
F_40 ( F_435 ( V_72 ) , V_692 ) ;
F_40 ( F_436 ( V_72 ) , 0 ) ;
F_40 ( F_437 ( V_72 ) , 0 ) ;
F_40 ( F_438 ( V_72 ) , V_692 << 16 ) ;
F_40 ( F_439 ( V_72 ) , 0 ) ;
F_40 ( F_440 ( V_72 ) , 0 ) ;
F_40 ( F_441 ( V_72 ) , 0 ) ;
if ( F_39 ( V_2 ) -> V_78 > 6 ) {
T_6 V_693 = 0 ;
if ( V_64 -> V_68 . V_637 )
V_693 = ( 16 * ( 1 << 12 ) / 255 ) & 0x1fff ;
F_40 ( F_442 ( V_72 ) , V_693 ) ;
F_40 ( F_443 ( V_72 ) , V_693 ) ;
F_40 ( F_444 ( V_72 ) , V_693 ) ;
F_40 ( F_445 ( V_72 ) , 0 ) ;
} else {
T_4 V_381 = V_694 ;
if ( V_64 -> V_68 . V_637 )
V_381 |= V_695 ;
F_40 ( F_445 ( V_72 ) , V_381 ) ;
}
}
static void F_446 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_72 V_72 = V_64 -> V_72 ;
enum V_71 V_74 = V_64 -> V_68 . V_74 ;
T_4 V_102 ;
V_102 = 0 ;
if ( F_142 ( V_2 ) && V_64 -> V_68 . V_627 )
V_102 |= ( V_628 | V_629 ) ;
if ( V_64 -> V_68 . V_69 . V_293 & V_608 )
V_102 |= V_205 ;
else
V_102 |= V_636 ;
F_40 ( F_45 ( V_74 ) , V_102 ) ;
F_114 ( F_45 ( V_74 ) ) ;
F_40 ( F_271 ( V_64 -> V_72 ) , V_696 ) ;
F_114 ( F_271 ( V_64 -> V_72 ) ) ;
if ( F_180 ( V_2 ) ) {
V_102 = 0 ;
switch ( V_64 -> V_68 . V_500 ) {
case 18 :
V_102 |= V_697 ;
break;
case 24 :
V_102 |= V_698 ;
break;
case 30 :
V_102 |= V_699 ;
break;
case 36 :
V_102 |= V_700 ;
break;
default:
F_122 () ;
}
if ( V_64 -> V_68 . V_627 )
V_102 |= V_701 | V_702 ;
F_40 ( F_447 ( V_72 ) , V_102 ) ;
}
}
static bool F_448 ( struct V_20 * V_21 ,
T_2 * clock ,
bool * V_640 ,
T_2 * V_550 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_22 ;
int V_10 ;
const T_3 * V_24 ;
bool V_227 , V_641 = false ;
F_10 (dev, crtc, intel_encoder) {
switch ( V_22 -> type ) {
case V_25 :
V_641 = true ;
break;
}
}
V_10 = F_430 ( V_21 ) ;
V_24 = F_14 ( V_21 , V_10 ) ;
V_227 = V_4 -> V_287 . V_644 ( V_24 , V_21 ,
F_30 ( V_21 ) -> V_68 . V_578 ,
V_10 , NULL , clock ) ;
if ( ! V_227 )
return false ;
if ( V_641 && V_4 -> V_645 ) {
* V_640 =
V_4 -> V_287 . V_644 ( V_24 , V_21 ,
V_4 -> V_646 ,
V_10 , clock ,
V_550 ) ;
}
return true ;
}
int F_351 ( int V_703 , int V_496 , int V_704 )
{
T_1 V_705 = V_703 * V_704 * 21 / 20 ;
return F_449 ( V_705 , V_496 * 8 ) ;
}
static bool F_450 ( struct V_47 * V_47 , int V_706 )
{
return F_20 ( V_47 ) < V_706 * V_47 -> V_17 ;
}
static T_4 F_451 ( struct V_64 * V_64 ,
T_1 * V_551 ,
T_2 * V_550 , T_1 * V_552 )
{
struct V_20 * V_21 = & V_64 -> V_109 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_22 ;
T_4 V_47 ;
int V_706 , V_548 = 0 ;
bool V_641 = false , V_585 = false ;
F_10 (dev, crtc, intel_encoder) {
switch ( V_22 -> type ) {
case V_25 :
V_641 = true ;
break;
case V_36 :
case V_33 :
V_585 = true ;
break;
}
V_548 ++ ;
}
V_706 = 21 ;
if ( V_641 ) {
if ( ( F_369 ( V_4 ) &&
V_4 -> V_545 . V_549 == 100000 ) ||
( F_48 ( V_2 ) && F_12 ( V_2 ) ) )
V_706 = 25 ;
} else if ( V_64 -> V_68 . V_598 )
V_706 = 20 ;
if ( F_450 ( & V_64 -> V_68 . V_47 , V_706 ) )
* V_551 |= V_707 ;
if ( V_552 && ( V_550 -> V_11 < V_706 * V_550 -> V_17 ) )
* V_552 |= V_707 ;
V_47 = 0 ;
if ( V_641 )
V_47 |= V_586 ;
else
V_47 |= V_587 ;
V_47 |= ( V_64 -> V_68 . V_582 - 1 )
<< V_708 ;
if ( V_585 )
V_47 |= V_589 ;
if ( V_64 -> V_68 . V_584 )
V_47 |= V_589 ;
V_47 |= ( 1 << ( V_64 -> V_68 . V_47 . V_15 - 1 ) ) << V_591 ;
V_47 |= ( 1 << ( V_64 -> V_68 . V_47 . V_15 - 1 ) ) << V_592 ;
switch ( V_64 -> V_68 . V_47 . V_16 ) {
case 5 :
V_47 |= V_593 ;
break;
case 7 :
V_47 |= V_594 ;
break;
case 10 :
V_47 |= V_595 ;
break;
case 14 :
V_47 |= V_596 ;
break;
}
if ( V_641 && F_369 ( V_4 ) && V_548 < 2 )
V_47 |= V_600 ;
else
V_47 |= V_601 ;
return V_47 | V_104 ;
}
static int F_452 ( struct V_20 * V_21 ,
int V_237 , int V_238 ,
struct V_272 * V_67 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
int V_141 = V_64 -> V_141 ;
int V_548 = 0 ;
T_2 clock , V_550 ;
T_1 V_47 = 0 , V_551 = 0 , V_552 = 0 ;
bool V_639 , V_640 = false ;
bool V_641 = false ;
struct V_22 * V_23 ;
struct V_108 * V_112 ;
int V_227 ;
F_10 (dev, crtc, encoder) {
switch ( V_23 -> type ) {
case V_25 :
V_641 = true ;
break;
}
V_548 ++ ;
}
F_46 ( ! ( F_48 ( V_2 ) || F_90 ( V_2 ) ) ,
L_116 , F_453 ( V_2 ) ) ;
V_639 = F_448 ( V_21 , & clock ,
& V_640 , & V_550 ) ;
if ( ! V_639 && ! V_64 -> V_68 . V_643 ) {
F_116 ( L_105 ) ;
return - V_232 ;
}
if ( ! V_64 -> V_68 . V_643 ) {
V_64 -> V_68 . V_47 . V_17 = clock . V_17 ;
V_64 -> V_68 . V_47 . V_12 = clock . V_12 ;
V_64 -> V_68 . V_47 . V_13 = clock . V_13 ;
V_64 -> V_68 . V_47 . V_15 = clock . V_15 ;
V_64 -> V_68 . V_47 . V_16 = clock . V_16 ;
}
if ( V_64 -> V_68 . V_216 ) {
V_551 = F_372 ( & V_64 -> V_68 . V_47 ) ;
if ( V_640 )
V_552 = F_372 ( & V_550 ) ;
V_47 = F_451 ( V_64 ,
& V_551 , & V_550 ,
V_640 ? & V_552 : NULL ) ;
V_64 -> V_68 . V_188 . V_47 = V_47 ;
V_64 -> V_68 . V_188 . V_553 = V_551 ;
if ( V_640 )
V_64 -> V_68 . V_188 . V_556 = V_552 ;
else
V_64 -> V_68 . V_188 . V_556 = V_551 ;
V_112 = F_255 ( V_64 ) ;
if ( V_112 == NULL ) {
F_59 ( L_117 ,
F_69 ( V_72 ) ) ;
return - V_232 ;
}
} else
F_254 ( V_64 ) ;
if ( V_64 -> V_68 . V_584 )
F_394 ( V_64 ) ;
if ( V_641 && V_640 && V_301 . V_555 )
V_64 -> V_554 = true ;
else
V_64 -> V_554 = false ;
F_407 ( V_64 ) ;
if ( V_64 -> V_68 . V_216 ) {
F_386 ( V_64 ,
& V_64 -> V_68 . V_501 ) ;
}
F_431 ( V_21 ) ;
F_40 ( F_79 ( V_141 ) , V_647 ) ;
F_114 ( F_79 ( V_141 ) ) ;
V_227 = F_194 ( V_21 , V_237 , V_238 , V_67 ) ;
return V_227 ;
}
static void F_454 ( struct V_64 * V_21 ,
struct V_537 * V_538 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_72 V_72 = V_21 -> V_72 ;
V_538 -> V_542 = F_4 ( F_384 ( V_72 ) ) ;
V_538 -> V_543 = F_4 ( F_385 ( V_72 ) ) ;
V_538 -> V_540 = F_4 ( F_381 ( V_72 ) )
& ~ V_370 ;
V_538 -> V_541 = F_4 ( F_383 ( V_72 ) ) ;
V_538 -> V_539 = ( ( F_4 ( F_381 ( V_72 ) )
& V_370 ) >> V_709 ) + 1 ;
}
static void F_455 ( struct V_64 * V_21 ,
enum V_71 V_71 ,
struct V_537 * V_538 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_72 V_72 = V_21 -> V_72 ;
if ( F_39 ( V_2 ) -> V_78 >= 5 ) {
V_538 -> V_542 = F_4 ( F_388 ( V_71 ) ) ;
V_538 -> V_543 = F_4 ( F_389 ( V_71 ) ) ;
V_538 -> V_540 = F_4 ( F_249 ( V_71 ) )
& ~ V_370 ;
V_538 -> V_541 = F_4 ( F_387 ( V_71 ) ) ;
V_538 -> V_539 = ( ( F_4 ( F_249 ( V_71 ) )
& V_370 ) >> V_709 ) + 1 ;
} else {
V_538 -> V_542 = F_4 ( F_392 ( V_72 ) ) ;
V_538 -> V_543 = F_4 ( F_393 ( V_72 ) ) ;
V_538 -> V_540 = F_4 ( F_390 ( V_72 ) )
& ~ V_370 ;
V_538 -> V_541 = F_4 ( F_391 ( V_72 ) ) ;
V_538 -> V_539 = ( ( F_4 ( F_390 ( V_72 ) )
& V_370 ) >> V_709 ) + 1 ;
}
}
void F_456 ( struct V_64 * V_21 ,
struct V_421 * V_422 )
{
if ( V_21 -> V_68 . V_216 )
F_454 ( V_21 , & V_422 -> V_559 ) ;
else
F_455 ( V_21 , V_422 -> V_74 ,
& V_422 -> V_559 ) ;
}
static void F_457 ( struct V_64 * V_21 ,
struct V_421 * V_422 )
{
F_455 ( V_21 , V_422 -> V_74 ,
& V_422 -> V_501 ) ;
}
static void F_458 ( struct V_64 * V_21 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_618 ;
V_618 = F_4 ( F_196 ( V_21 -> V_72 ) ) ;
if ( V_618 & V_391 ) {
V_422 -> V_306 . V_100 = true ;
V_422 -> V_306 . V_393 = F_4 ( F_197 ( V_21 -> V_72 ) ) ;
V_422 -> V_306 . V_263 = F_4 ( F_198 ( V_21 -> V_72 ) ) ;
if ( F_459 ( V_2 ) ) {
F_2 ( ( V_618 & V_710 ) !=
F_258 ( V_21 -> V_72 ) ) ;
}
}
}
static void F_460 ( struct V_64 * V_21 ,
struct V_259 * V_260 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_102 , V_109 , V_243 ;
int V_72 = V_21 -> V_72 , V_141 = V_21 -> V_141 ;
int V_653 , V_266 ;
int V_654 ;
V_21 -> V_109 . V_66 -> V_67 = F_418 ( sizeof( struct V_271 ) , V_655 ) ;
if ( ! V_21 -> V_109 . V_66 -> V_67 ) {
F_36 ( L_106 ) ;
return;
}
V_102 = F_4 ( F_79 ( V_141 ) ) ;
if ( F_39 ( V_2 ) -> V_78 >= 4 )
if ( V_102 & V_282 )
V_260 -> V_220 = true ;
V_266 = V_102 & V_276 ;
V_653 = F_164 ( V_266 ) ;
V_21 -> V_109 . V_66 -> V_67 -> V_266 = V_653 ;
V_21 -> V_109 . V_66 -> V_67 -> V_284 =
F_419 ( V_653 , 0 ) * 8 ;
V_109 = F_4 ( F_145 ( V_141 ) ) & 0xfffff000 ;
if ( F_142 ( V_2 ) || F_180 ( V_2 ) ) {
V_243 = F_4 ( F_181 ( V_141 ) ) ;
} else {
if ( V_260 -> V_220 )
V_243 = F_4 ( F_177 ( V_141 ) ) ;
else
V_243 = F_4 ( F_178 ( V_141 ) ) ;
}
V_260 -> V_109 = V_109 ;
V_102 = F_4 ( F_195 ( V_72 ) ) ;
V_21 -> V_109 . V_66 -> V_67 -> V_267 = ( ( V_102 >> 16 ) & 0xfff ) + 1 ;
V_21 -> V_109 . V_66 -> V_67 -> V_219 = ( ( V_102 >> 0 ) & 0xfff ) + 1 ;
V_102 = F_4 ( F_176 ( V_72 ) ) ;
V_21 -> V_109 . V_66 -> V_67 -> V_265 [ 0 ] = V_102 & 0xffffff80 ;
V_654 = F_152 ( V_2 , V_21 -> V_109 . V_66 -> V_67 -> V_219 ,
V_260 -> V_220 ) ;
V_260 -> V_263 = F_153 ( V_21 -> V_109 . V_66 -> V_67 -> V_265 [ 0 ] *
V_654 , V_656 ) ;
F_36 ( L_107 ,
V_72 , V_141 , V_21 -> V_109 . V_66 -> V_67 -> V_267 ,
V_21 -> V_109 . V_66 -> V_67 -> V_219 ,
V_21 -> V_109 . V_66 -> V_67 -> V_284 , V_109 ,
V_21 -> V_109 . V_66 -> V_67 -> V_265 [ 0 ] ,
V_260 -> V_263 ) ;
}
static bool F_461 ( struct V_64 * V_21 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_618 ;
V_422 -> V_74 = (enum V_71 ) V_21 -> V_72 ;
V_422 -> V_110 = V_386 ;
V_618 = F_4 ( F_45 ( V_21 -> V_72 ) ) ;
if ( ! ( V_618 & V_140 ) )
return false ;
switch ( V_618 & V_202 ) {
case V_630 :
V_422 -> V_500 = 18 ;
break;
case V_631 :
V_422 -> V_500 = 24 ;
break;
case V_632 :
V_422 -> V_500 = 30 ;
break;
case V_691 :
V_422 -> V_500 = 36 ;
break;
default:
break;
}
if ( F_4 ( F_92 ( V_21 -> V_72 ) ) & V_155 ) {
struct V_108 * V_112 ;
V_422 -> V_216 = true ;
V_618 = F_4 ( F_65 ( V_21 -> V_72 ) ) ;
V_422 -> V_328 = ( ( V_327 & V_618 ) >>
V_711 ) + 1 ;
F_457 ( V_21 , V_422 ) ;
if ( F_48 ( V_4 -> V_2 ) ) {
V_422 -> V_110 =
(enum V_387 ) V_21 -> V_72 ;
} else {
V_618 = F_4 ( V_373 ) ;
if ( V_618 & F_251 ( V_21 -> V_72 ) )
V_422 -> V_110 = V_374 ;
else
V_422 -> V_110 = V_712 ;
}
V_112 = & V_4 -> V_111 [ V_422 -> V_110 ] ;
F_2 ( ! V_112 -> V_115 ( V_4 , V_112 ,
& V_422 -> V_188 ) ) ;
V_618 = V_422 -> V_188 . V_47 ;
V_422 -> V_582 =
( ( V_618 & V_713 )
>> V_708 ) + 1 ;
F_462 ( V_21 , V_422 ) ;
} else {
V_422 -> V_582 = 1 ;
}
F_408 ( V_21 , V_422 ) ;
F_458 ( V_21 , V_422 ) ;
return true ;
}
static void F_463 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_714 * V_715 = & V_4 -> V_716 ;
struct V_64 * V_21 ;
unsigned long V_717 ;
T_4 V_102 ;
F_172 (crtc, &dev->mode_config.crtc_list, base.head)
F_46 ( V_21 -> V_65 , L_118 ,
F_69 ( V_21 -> V_72 ) ) ;
F_46 ( F_4 ( V_718 ) , L_119 ) ;
F_46 ( V_715 -> V_719 , L_120 ) ;
F_46 ( V_715 -> V_720 , L_121 ) ;
F_46 ( V_715 -> V_721 , L_122 ) ;
F_46 ( F_4 ( V_722 ) & V_723 , L_123 ) ;
F_46 ( F_4 ( V_724 ) & V_725 ,
L_124 ) ;
F_46 ( F_4 ( V_726 ) & V_725 ,
L_125 ) ;
F_46 ( F_4 ( V_727 ) & V_728 ,
L_126 ) ;
F_46 ( F_4 ( V_729 ) & V_730 ,
L_127 ) ;
F_46 ( F_4 ( V_731 ) & V_732 , L_128 ) ;
F_192 ( & V_4 -> V_733 , V_717 ) ;
V_102 = F_4 ( V_734 ) ;
F_46 ( ( V_102 | V_735 ) != 0xffffffff ,
L_129 , V_102 ) ;
V_102 = F_4 ( V_736 ) ;
F_46 ( ( V_102 | V_737 ) != 0xffffffff ,
L_130 , V_102 ) ;
F_193 ( & V_4 -> V_733 , V_717 ) ;
}
static void F_464 ( struct V_3 * V_4 ,
bool V_738 , bool V_739 )
{
T_4 V_102 ;
F_463 ( V_4 ) ;
V_102 = F_4 ( V_740 ) ;
if ( V_738 ) {
V_102 |= V_741 ;
F_40 ( V_740 , V_102 ) ;
if ( F_424 ( F_4 ( V_740 ) &
V_742 , 1 ) )
F_116 ( L_131 ) ;
V_102 = F_4 ( V_740 ) ;
}
V_102 |= V_743 ;
F_40 ( V_740 , V_102 ) ;
F_114 ( V_740 ) ;
if ( F_34 ( ( F_4 ( V_740 ) & V_744 ) == 0 , 1 ) )
F_116 ( L_132 ) ;
V_102 = F_4 ( V_745 ) ;
V_102 |= V_746 ;
F_53 ( & V_4 -> V_397 . V_398 ) ;
if ( F_266 ( V_4 , V_747 , V_102 ) )
F_116 ( L_133 ) ;
F_55 ( & V_4 -> V_397 . V_398 ) ;
F_114 ( V_745 ) ;
F_465 ( 100 ) ;
if ( F_34 ( ( F_4 ( V_745 ) & V_748 ) == 0 , 1 ) )
F_116 ( L_134 ) ;
if ( V_739 ) {
V_102 = F_4 ( V_740 ) ;
V_102 |= V_749 ;
F_40 ( V_740 , V_102 ) ;
F_114 ( V_740 ) ;
}
}
static void F_466 ( struct V_3 * V_4 )
{
T_4 V_102 ;
unsigned long V_717 ;
V_102 = F_4 ( V_740 ) ;
if ( ( V_102 & ( V_744 | V_743 | V_741 |
V_749 ) ) == V_744 )
return;
F_192 ( & V_4 -> V_750 . V_751 , V_717 ) ;
if ( V_4 -> V_750 . V_752 ++ == 0 )
V_4 -> V_750 . V_753 . V_754 ( V_4 , V_755 ) ;
F_193 ( & V_4 -> V_750 . V_751 , V_717 ) ;
if ( V_102 & V_749 ) {
V_102 &= ~ V_749 ;
F_40 ( V_740 , V_102 ) ;
F_114 ( V_740 ) ;
}
V_102 = F_4 ( V_745 ) ;
V_102 |= V_756 ;
V_102 &= ~ V_746 ;
F_53 ( & V_4 -> V_397 . V_398 ) ;
if ( F_266 ( V_4 , V_747 , V_102 ) )
F_116 ( L_135 ) ;
F_55 ( & V_4 -> V_397 . V_398 ) ;
F_114 ( V_745 ) ;
V_102 = F_4 ( V_740 ) ;
V_102 &= ~ V_743 ;
F_40 ( V_740 , V_102 ) ;
if ( F_34 ( F_4 ( V_740 ) & V_744 , 5 ) )
F_116 ( L_136 ) ;
if ( V_102 & V_741 ) {
V_102 = F_4 ( V_740 ) ;
V_102 &= ~ V_741 ;
F_40 ( V_740 , V_102 ) ;
if ( F_424 ( ( F_4 ( V_740 ) &
V_742 ) == 0 , 1 ) )
F_116 ( L_137 ) ;
}
F_192 ( & V_4 -> V_750 . V_751 , V_717 ) ;
if ( -- V_4 -> V_750 . V_752 == 0 )
V_4 -> V_750 . V_753 . V_757 ( V_4 , V_755 ) ;
F_193 ( & V_4 -> V_750 . V_751 , V_717 ) ;
}
void F_467 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_102 ;
F_2 ( ! F_468 ( V_2 ) ) ;
F_36 ( L_138 ) ;
if ( V_4 -> V_683 == V_684 ) {
V_102 = F_4 ( V_758 ) ;
V_102 &= ~ V_759 ;
F_40 ( V_758 , V_102 ) ;
}
F_427 ( V_2 ) ;
F_469 ( V_2 ) ;
F_464 ( V_4 , true , true ) ;
}
void F_470 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_102 ;
F_2 ( ! F_468 ( V_2 ) ) ;
F_36 ( L_139 ) ;
F_466 ( V_4 ) ;
F_471 ( V_2 ) ;
F_428 ( V_2 ) ;
if ( V_4 -> V_683 == V_684 ) {
V_102 = F_4 ( V_758 ) ;
V_102 |= V_759 ;
F_40 ( V_758 , V_102 ) ;
}
F_472 ( V_2 ) ;
F_473 ( V_2 ) ;
F_53 ( & V_4 -> V_397 . V_398 ) ;
F_474 ( V_2 ) ;
F_55 ( & V_4 -> V_397 . V_398 ) ;
}
static void F_475 ( struct V_1 * V_2 )
{
F_314 ( V_2 ) ;
}
static int F_476 ( struct V_20 * V_21 ,
int V_237 , int V_238 ,
struct V_272 * V_67 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_141 = V_64 -> V_141 ;
int V_227 ;
if ( ! F_477 ( V_64 ) )
return - V_232 ;
F_478 ( V_64 ) ;
if ( V_64 -> V_68 . V_584 )
F_394 ( V_64 ) ;
V_64 -> V_554 = false ;
F_407 ( V_64 ) ;
if ( V_64 -> V_68 . V_216 ) {
F_386 ( V_64 ,
& V_64 -> V_68 . V_501 ) ;
}
F_446 ( V_21 ) ;
F_432 ( V_21 ) ;
F_40 ( F_79 ( V_141 ) , V_647 | V_760 ) ;
F_114 ( F_79 ( V_141 ) ) ;
V_227 = F_194 ( V_21 , V_237 , V_238 , V_67 ) ;
return V_227 ;
}
static bool F_479 ( struct V_64 * V_21 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_429 V_761 ;
T_4 V_618 ;
if ( ! F_76 ( V_4 ,
F_309 ( V_21 -> V_72 ) ) )
return false ;
V_422 -> V_74 = (enum V_71 ) V_21 -> V_72 ;
V_422 -> V_110 = V_386 ;
V_618 = F_4 ( F_62 ( V_617 ) ) ;
if ( V_618 & V_117 ) {
enum V_72 V_762 ;
switch ( V_618 & V_763 ) {
default:
F_46 ( 1 , L_140 ) ;
case V_764 :
case V_765 :
V_762 = V_125 ;
break;
case V_766 :
V_762 = V_134 ;
break;
case V_767 :
V_762 = V_321 ;
break;
}
if ( V_762 == V_21 -> V_72 )
V_422 -> V_74 = V_617 ;
}
if ( ! F_76 ( V_4 ,
F_77 ( V_422 -> V_74 ) ) )
return false ;
V_618 = F_4 ( F_45 ( V_422 -> V_74 ) ) ;
if ( ! ( V_618 & V_140 ) )
return false ;
V_618 = F_4 ( F_62 ( V_422 -> V_74 ) ) ;
if ( ( V_618 & V_768 ) == F_480 ( V_769 ) &&
F_4 ( V_213 ) & V_155 ) {
V_422 -> V_216 = true ;
V_618 = F_4 ( F_65 ( V_125 ) ) ;
V_422 -> V_328 = ( ( V_327 & V_618 ) >>
V_711 ) + 1 ;
F_457 ( V_21 , V_422 ) ;
}
F_408 ( V_21 , V_422 ) ;
V_761 = F_310 ( V_21 -> V_72 ) ;
if ( F_76 ( V_4 , V_761 ) )
F_458 ( V_21 , V_422 ) ;
if ( F_142 ( V_2 ) )
V_422 -> V_396 = F_277 ( V_21 ) &&
( F_4 ( V_400 ) & V_401 ) ;
V_422 -> V_582 = 1 ;
return true ;
}
static int F_481 ( struct V_20 * V_21 ,
int V_237 , int V_238 ,
struct V_272 * V_67 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_23 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_303 * V_381 = & V_64 -> V_68 . V_619 ;
int V_72 = V_64 -> V_72 ;
int V_227 ;
F_482 ( V_2 , V_72 ) ;
V_227 = V_4 -> V_287 . V_770 ( V_21 , V_237 , V_238 , V_67 ) ;
F_483 ( V_2 , V_72 ) ;
if ( V_227 != 0 )
return V_227 ;
F_10 (dev, crtc, encoder) {
F_36 ( L_141 ,
V_23 -> V_109 . V_109 . V_197 ,
F_484 ( & V_23 -> V_109 ) ,
V_381 -> V_109 . V_197 , V_381 -> V_116 ) ;
V_23 -> V_389 ( V_23 ) ;
}
return 0 ;
}
static T_1 F_485 ( struct V_303 * V_381 )
{
int V_143 ;
for ( V_143 = 0 ; V_143 < F_215 ( V_771 ) ; V_143 ++ ) {
if ( V_381 -> clock == V_771 [ V_143 ] . clock )
break;
}
if ( V_143 == F_215 ( V_771 ) ) {
F_36 ( L_142 , V_381 -> clock ) ;
V_143 = 1 ;
}
F_36 ( L_143 ,
V_771 [ V_143 ] . clock ,
V_771 [ V_143 ] . V_68 ) ;
return V_771 [ V_143 ] . V_68 ;
}
static bool F_486 ( struct V_485 * V_486 ,
int V_772 , T_4 V_773 ,
int V_774 , T_4 V_775 ,
int V_776 )
{
struct V_3 * V_4 = V_486 -> V_2 -> V_5 ;
T_7 * V_777 = V_486 -> V_777 ;
T_4 V_143 ;
V_143 = F_4 ( V_772 ) ;
V_143 &= V_773 ;
if ( ! V_777 [ 0 ] )
return ! V_143 ;
if ( ! V_143 )
return false ;
V_143 = F_4 ( V_774 ) ;
V_143 &= ~ V_775 ;
F_40 ( V_774 , V_143 ) ;
for ( V_143 = 0 ; V_143 < V_777 [ 2 ] ; V_143 ++ )
if ( F_4 ( V_776 ) != * ( ( T_4 * ) V_777 + V_143 ) )
return false ;
return true ;
}
static void F_487 ( struct V_485 * V_486 ,
struct V_20 * V_21 ,
struct V_303 * V_381 )
{
struct V_3 * V_4 = V_486 -> V_2 -> V_5 ;
T_7 * V_777 = V_486 -> V_777 ;
T_4 V_778 ;
T_4 V_779 ;
T_4 V_143 ;
V_143 = F_4 ( V_780 ) ;
if ( V_143 == V_781 || V_143 == V_782 )
V_778 = V_783 ;
else
V_778 = V_784 ;
if ( F_486 ( V_486 ,
V_785 , V_778 ,
V_785 , V_786 ,
V_787 ) )
return;
V_143 = F_4 ( V_785 ) ;
V_143 &= ~ ( V_778 | V_786 ) ;
V_779 = ( V_143 >> 9 ) & 0x1f ;
F_40 ( V_785 , V_143 ) ;
if ( ! V_777 [ 0 ] )
return;
V_779 = F_368 ( T_7 , V_777 [ 2 ] , V_779 ) ;
F_59 ( L_144 , V_779 ) ;
for ( V_143 = 0 ; V_143 < V_779 ; V_143 ++ )
F_40 ( V_787 , * ( ( T_4 * ) V_777 + V_143 ) ) ;
V_143 = F_4 ( V_785 ) ;
V_143 |= V_778 ;
F_40 ( V_785 , V_143 ) ;
}
static void F_488 ( struct V_485 * V_486 ,
struct V_20 * V_21 ,
struct V_303 * V_381 )
{
struct V_3 * V_4 = V_486 -> V_2 -> V_5 ;
T_7 * V_777 = V_486 -> V_777 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
T_4 V_778 ;
T_4 V_143 ;
int V_779 ;
int V_72 = F_30 ( V_21 ) -> V_72 ;
int V_618 ;
int V_788 = F_489 ( V_72 ) ;
int V_789 = F_490 ( V_72 ) ;
int V_790 = F_491 ( V_72 ) ;
int V_791 = V_792 ;
F_59 ( L_145 ) ;
F_59 ( L_146 ) ;
V_618 = F_4 ( V_791 ) ;
V_618 |= ( V_793 << ( V_72 * 4 ) ) ;
F_40 ( V_791 , V_618 ) ;
F_37 ( V_2 , V_72 ) ;
V_618 = F_4 ( V_791 ) ;
F_59 ( L_147 , V_618 ) ;
V_618 |= ( V_794 << ( V_72 * 4 ) ) ;
F_40 ( V_791 , V_618 ) ;
V_618 = F_4 ( V_791 ) ;
F_59 ( L_148 , V_618 ) ;
V_618 = F_4 ( V_790 ) ;
F_59 ( L_149 , V_618 ) ;
V_618 &= ~ ( V_795 | V_796 ) ;
F_40 ( V_790 , V_618 ) ;
F_59 ( L_150 , F_69 ( V_72 ) ) ;
V_778 = V_794 << ( V_72 * 4 ) ;
V_64 -> V_487 = true ;
if ( F_9 ( V_21 , V_375 ) ) {
F_59 ( L_151 ) ;
V_777 [ 5 ] |= ( 1 << 2 ) ;
F_40 ( V_790 , V_795 ) ;
} else {
F_40 ( V_790 , F_485 ( V_381 ) ) ;
}
if ( F_486 ( V_486 ,
V_791 , V_778 ,
V_789 , V_797 ,
V_788 ) )
return;
V_143 = F_4 ( V_791 ) ;
V_143 &= ~ V_778 ;
F_40 ( V_791 , V_143 ) ;
if ( ! V_777 [ 0 ] )
return;
V_143 = F_4 ( V_789 ) ;
V_143 &= ~ V_797 ;
F_40 ( V_789 , V_143 ) ;
V_143 = ( V_143 >> 29 ) & V_798 ;
F_59 ( L_152 , V_143 ) ;
V_779 = F_368 ( T_7 , V_777 [ 2 ] , 21 ) ;
F_59 ( L_144 , V_779 ) ;
for ( V_143 = 0 ; V_143 < V_779 ; V_143 ++ )
F_40 ( V_788 , * ( ( T_4 * ) V_777 + V_143 ) ) ;
V_143 = F_4 ( V_791 ) ;
V_143 |= V_778 ;
F_40 ( V_791 , V_143 ) ;
}
static void F_492 ( struct V_485 * V_486 ,
struct V_20 * V_21 ,
struct V_303 * V_381 )
{
struct V_3 * V_4 = V_486 -> V_2 -> V_5 ;
T_7 * V_777 = V_486 -> V_777 ;
T_4 V_778 ;
T_4 V_143 ;
int V_779 ;
int V_788 ;
int V_790 ;
int V_789 ;
int V_791 ;
int V_72 = F_30 ( V_21 ) -> V_72 ;
if ( F_48 ( V_486 -> V_2 ) ) {
V_788 = F_493 ( V_72 ) ;
V_790 = F_494 ( V_72 ) ;
V_789 = F_495 ( V_72 ) ;
V_791 = V_799 ;
} else if ( F_17 ( V_486 -> V_2 ) ) {
V_788 = F_496 ( V_72 ) ;
V_790 = F_497 ( V_72 ) ;
V_789 = F_498 ( V_72 ) ;
V_791 = V_800 ;
} else {
V_788 = F_499 ( V_72 ) ;
V_790 = F_500 ( V_72 ) ;
V_789 = F_501 ( V_72 ) ;
V_791 = V_801 ;
}
F_59 ( L_150 , F_69 ( V_72 ) ) ;
if ( F_17 ( V_486 -> V_2 ) ) {
struct V_22 * V_22 ;
struct V_87 * V_430 ;
V_22 = F_502 ( V_486 ) ;
V_430 = F_306 ( & V_22 -> V_109 ) ;
V_143 = V_430 -> V_88 ;
} else {
V_143 = F_4 ( V_789 ) ;
V_143 = ( V_143 >> 29 ) & V_798 ;
}
if ( ! V_143 ) {
F_59 ( L_153 ) ;
V_778 = V_802 ;
V_778 |= V_802 << 4 ;
V_778 |= V_802 << 8 ;
} else {
F_59 ( L_154 , F_123 ( V_143 ) ) ;
V_778 = V_802 << ( ( V_143 - 1 ) * 4 ) ;
}
if ( F_9 ( V_21 , V_375 ) ) {
F_59 ( L_151 ) ;
V_777 [ 5 ] |= ( 1 << 2 ) ;
F_40 ( V_790 , V_795 ) ;
} else {
F_40 ( V_790 , F_485 ( V_381 ) ) ;
}
if ( F_486 ( V_486 ,
V_791 , V_778 ,
V_789 , V_797 ,
V_788 ) )
return;
V_143 = F_4 ( V_791 ) ;
V_143 &= ~ V_778 ;
F_40 ( V_791 , V_143 ) ;
if ( ! V_777 [ 0 ] )
return;
V_143 = F_4 ( V_789 ) ;
V_143 &= ~ V_797 ;
F_40 ( V_789 , V_143 ) ;
V_779 = F_368 ( T_7 , V_777 [ 2 ] , 21 ) ;
F_59 ( L_144 , V_779 ) ;
for ( V_143 = 0 ; V_143 < V_779 ; V_143 ++ )
F_40 ( V_788 , * ( ( T_4 * ) V_777 + V_143 ) ) ;
V_143 = F_4 ( V_791 ) ;
V_143 |= V_778 ;
F_40 ( V_791 , V_143 ) ;
}
void F_503 ( struct V_491 * V_23 ,
struct V_303 * V_381 )
{
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_485 * V_486 ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_486 = F_504 ( V_23 , V_381 ) ;
if ( ! V_486 )
return;
F_59 ( L_155 ,
V_486 -> V_109 . V_197 ,
F_343 ( V_486 ) ,
V_486 -> V_23 -> V_109 . V_197 ,
F_484 ( V_486 -> V_23 ) ) ;
V_486 -> V_777 [ 6 ] = F_505 ( V_486 , V_381 ) / 2 ;
if ( V_4 -> V_287 . V_803 )
V_4 -> V_287 . V_803 ( V_486 , V_21 , V_381 ) ;
}
static void F_506 ( struct V_20 * V_21 , T_1 V_109 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
bool V_804 = V_109 != 0 ;
T_1 V_416 ;
if ( V_64 -> V_805 == V_804 )
return;
V_416 = F_4 ( V_135 ) ;
if ( V_804 ) {
F_40 ( V_806 , V_109 ) ;
V_416 &= ~ ( V_807 ) ;
V_416 |= V_136 |
V_808 |
V_809 ;
} else
V_416 &= ~ ( V_136 | V_808 ) ;
F_40 ( V_135 , V_416 ) ;
V_64 -> V_805 = V_804 ;
}
static void F_507 ( struct V_20 * V_21 , T_1 V_109 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
bool V_804 = V_109 != 0 ;
if ( V_64 -> V_805 != V_804 ) {
T_8 V_267 = V_64 -> V_810 ;
T_4 V_416 = F_4 ( F_73 ( V_72 ) ) ;
if ( V_109 ) {
V_416 &= ~ ( V_137 | V_811 ) ;
V_416 |= V_812 ;
switch ( V_267 ) {
case 64 :
V_416 |= V_420 ;
break;
case 128 :
V_416 |= V_813 ;
break;
case 256 :
V_416 |= V_814 ;
break;
default:
F_2 ( 1 ) ;
return;
}
V_416 |= V_72 << 28 ;
} else {
V_416 &= ~ ( V_137 | V_812 ) ;
V_416 |= V_815 ;
}
F_40 ( F_73 ( V_72 ) , V_416 ) ;
V_64 -> V_805 = V_804 ;
}
F_114 ( F_73 ( V_72 ) ) ;
F_40 ( F_301 ( V_72 ) , V_109 ) ;
F_114 ( F_301 ( V_72 ) ) ;
}
static void F_508 ( struct V_20 * V_21 , T_1 V_109 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
bool V_804 = V_109 != 0 ;
if ( V_64 -> V_805 != V_804 ) {
T_8 V_267 = V_64 -> V_810 ;
T_4 V_416 = F_4 ( F_74 ( V_72 ) ) ;
if ( V_109 ) {
V_416 &= ~ V_137 ;
V_416 |= V_812 ;
switch ( V_267 ) {
case 64 :
V_416 |= V_420 ;
break;
case 128 :
V_416 |= V_813 ;
break;
case 256 :
V_416 |= V_814 ;
break;
default:
F_2 ( 1 ) ;
return;
}
} else {
V_416 &= ~ ( V_137 | V_812 ) ;
V_416 |= V_815 ;
}
if ( F_142 ( V_2 ) || F_180 ( V_2 ) ) {
V_416 |= V_816 ;
V_416 &= ~ V_817 ;
}
F_40 ( F_74 ( V_72 ) , V_416 ) ;
V_64 -> V_805 = V_804 ;
}
F_114 ( F_74 ( V_72 ) ) ;
F_40 ( F_509 ( V_72 ) , V_109 ) ;
F_114 ( F_509 ( V_72 ) ) ;
}
static void F_276 ( struct V_20 * V_21 ,
bool V_196 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
int V_237 = V_64 -> V_818 ;
int V_238 = V_64 -> V_819 ;
T_1 V_109 = 0 , V_393 = 0 ;
bool V_804 ;
if ( V_196 )
V_109 = V_64 -> V_820 ;
if ( V_237 >= V_64 -> V_68 . V_308 )
V_109 = 0 ;
if ( V_238 >= V_64 -> V_68 . V_309 )
V_109 = 0 ;
if ( V_237 < 0 ) {
if ( V_237 + V_64 -> V_810 <= 0 )
V_109 = 0 ;
V_393 |= V_821 << V_822 ;
V_237 = - V_237 ;
}
V_393 |= V_237 << V_822 ;
if ( V_238 < 0 ) {
if ( V_238 + V_64 -> V_823 <= 0 )
V_109 = 0 ;
V_393 |= V_821 << V_824 ;
V_238 = - V_238 ;
}
V_393 |= V_238 << V_824 ;
V_804 = V_109 != 0 ;
if ( ! V_804 && ! V_64 -> V_805 )
return;
if ( F_202 ( V_2 ) || F_142 ( V_2 ) || F_180 ( V_2 ) ) {
F_40 ( F_510 ( V_72 ) , V_393 ) ;
F_508 ( V_21 , V_109 ) ;
} else {
F_40 ( F_511 ( V_72 ) , V_393 ) ;
if ( F_71 ( V_2 ) || F_72 ( V_2 ) )
F_506 ( V_21 , V_109 ) ;
else
F_507 ( V_21 , V_109 ) ;
}
}
static int F_512 ( struct V_20 * V_21 ,
struct V_825 * V_826 ,
T_4 V_827 ,
T_4 V_267 , T_4 V_219 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_222 * V_223 ;
unsigned V_828 ;
T_4 V_829 ;
int V_227 ;
if ( ! V_827 ) {
F_36 ( L_156 ) ;
V_829 = 0 ;
V_223 = NULL ;
F_53 ( & V_2 -> V_268 ) ;
goto V_830;
}
if ( ! ( ( V_267 == 64 && V_219 == 64 ) ||
( V_267 == 128 && V_219 == 128 && ! F_18 ( V_2 ) ) ||
( V_267 == 256 && V_219 == 256 && ! F_18 ( V_2 ) ) ) ) {
F_513 ( L_157 ) ;
return - V_232 ;
}
V_223 = F_514 ( F_515 ( V_2 , V_826 , V_827 ) ) ;
if ( & V_223 -> V_109 == NULL )
return - V_831 ;
if ( V_223 -> V_109 . V_263 < V_267 * V_219 * 4 ) {
F_36 ( L_158 ) ;
V_227 = - V_832 ;
goto V_833;
}
F_53 ( & V_2 -> V_268 ) ;
if ( ! F_39 ( V_2 ) -> V_834 ) {
unsigned V_226 ;
if ( V_223 -> V_228 ) {
F_36 ( L_159 ) ;
V_227 = - V_232 ;
goto V_835;
}
V_226 = 0 ;
if ( F_150 ( V_2 ) )
V_226 = 64 * 1024 ;
V_227 = F_157 ( V_223 , V_226 , NULL ) ;
if ( V_227 ) {
F_36 ( L_160 ) ;
goto V_835;
}
V_227 = F_516 ( V_223 ) ;
if ( V_227 ) {
F_36 ( L_161 ) ;
goto V_836;
}
V_829 = F_173 ( V_223 ) ;
} else {
int V_837 = F_113 ( V_2 ) ? 16 * 1024 : 256 ;
V_227 = F_517 ( V_223 , V_837 ) ;
if ( V_227 ) {
F_36 ( L_162 ) ;
goto V_835;
}
V_829 = V_223 -> V_838 -> V_839 ;
}
if ( F_18 ( V_2 ) )
F_40 ( V_840 , ( V_219 << 12 ) | V_267 ) ;
V_830:
if ( V_64 -> V_841 ) {
if ( ! F_39 ( V_2 ) -> V_834 )
F_160 ( V_64 -> V_841 ) ;
F_169 ( & V_64 -> V_841 -> V_109 ) ;
}
F_55 ( & V_2 -> V_268 ) ;
V_828 = V_64 -> V_810 ;
V_64 -> V_820 = V_829 ;
V_64 -> V_841 = V_223 ;
V_64 -> V_810 = V_267 ;
V_64 -> V_823 = V_219 ;
if ( V_64 -> V_65 ) {
if ( V_828 != V_267 )
F_275 ( V_21 ) ;
F_276 ( V_21 , V_64 -> V_841 != NULL ) ;
}
return 0 ;
V_836:
F_160 ( V_223 ) ;
V_835:
F_55 ( & V_2 -> V_268 ) ;
V_833:
F_518 ( & V_223 -> V_109 ) ;
return V_227 ;
}
static int F_519 ( struct V_20 * V_21 , int V_237 , int V_238 )
{
struct V_64 * V_64 = F_30 ( V_21 ) ;
V_64 -> V_818 = F_520 ( int , V_237 , V_842 , V_843 ) ;
V_64 -> V_819 = F_520 ( int , V_238 , V_842 , V_843 ) ;
if ( V_64 -> V_65 )
F_276 ( V_21 , V_64 -> V_841 != NULL ) ;
return 0 ;
}
static void F_521 ( struct V_20 * V_21 , T_5 * V_844 , T_5 * V_845 ,
T_5 * V_846 , T_4 V_847 , T_4 V_263 )
{
int V_848 = ( V_847 + V_263 > 256 ) ? 256 : V_847 + V_263 , V_143 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
for ( V_143 = V_847 ; V_143 < V_848 ; V_143 ++ ) {
V_64 -> V_406 [ V_143 ] = V_844 [ V_143 ] >> 8 ;
V_64 -> V_407 [ V_143 ] = V_845 [ V_143 ] >> 8 ;
V_64 -> V_408 [ V_143 ] = V_846 [ V_143 ] >> 8 ;
}
F_268 ( V_21 ) ;
}
struct V_272 *
F_522 ( struct V_1 * V_2 ,
struct V_261 * V_262 ,
struct V_222 * V_223 )
{
struct V_271 * V_273 ;
int V_227 ;
V_273 = F_418 ( sizeof( * V_273 ) , V_655 ) ;
if ( ! V_273 ) {
F_518 ( & V_223 -> V_109 ) ;
return F_523 ( - V_832 ) ;
}
V_227 = F_167 ( V_2 , V_273 , V_262 , V_223 ) ;
if ( V_227 )
goto V_53;
return & V_273 -> V_109 ;
V_53:
F_518 ( & V_223 -> V_109 ) ;
F_171 ( V_273 ) ;
return F_523 ( V_227 ) ;
}
static struct V_272 *
F_524 ( struct V_1 * V_2 ,
struct V_261 * V_262 ,
struct V_222 * V_223 )
{
struct V_272 * V_67 ;
int V_227 ;
V_227 = F_525 ( V_2 ) ;
if ( V_227 )
return F_523 ( V_227 ) ;
V_67 = F_522 ( V_2 , V_262 , V_223 ) ;
F_55 ( & V_2 -> V_268 ) ;
return V_67 ;
}
static T_1
F_526 ( int V_267 , int V_704 )
{
T_1 V_240 = F_449 ( V_267 * V_704 , 8 ) ;
return F_153 ( V_240 , 64 ) ;
}
static T_1
F_527 ( struct V_303 * V_381 , int V_704 )
{
T_1 V_240 = F_526 ( V_381 -> V_477 , V_704 ) ;
return F_153 ( V_240 * V_381 -> V_479 , V_656 ) ;
}
static struct V_272 *
F_528 ( struct V_1 * V_2 ,
struct V_303 * V_381 ,
int V_849 , int V_704 )
{
struct V_222 * V_223 ;
struct V_261 V_262 = { 0 } ;
V_223 = F_529 ( V_2 ,
F_527 ( V_381 , V_704 ) ) ;
if ( V_223 == NULL )
return F_523 ( - V_832 ) ;
V_262 . V_267 = V_381 -> V_477 ;
V_262 . V_219 = V_381 -> V_479 ;
V_262 . V_265 [ 0 ] = F_526 ( V_262 . V_267 ,
V_704 ) ;
V_262 . V_266 = F_530 ( V_704 , V_849 ) ;
return F_524 ( V_2 , & V_262 , V_223 ) ;
}
static struct V_272 *
F_531 ( struct V_1 * V_2 ,
struct V_303 * V_381 )
{
#ifdef F_532
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_222 * V_223 ;
struct V_272 * V_67 ;
if ( ! V_4 -> V_850 )
return NULL ;
if ( ! V_4 -> V_850 -> V_67 )
return NULL ;
V_223 = V_4 -> V_850 -> V_67 -> V_223 ;
F_111 ( ! V_223 ) ;
V_67 = & V_4 -> V_850 -> V_67 -> V_109 ;
if ( V_67 -> V_265 [ 0 ] < F_526 ( V_381 -> V_477 ,
V_67 -> V_284 ) )
return NULL ;
if ( V_223 -> V_109 . V_263 < V_381 -> V_479 * V_67 -> V_265 [ 0 ] )
return NULL ;
return V_67 ;
#else
return NULL ;
#endif
}
bool F_533 ( struct V_485 * V_486 ,
struct V_303 * V_381 ,
struct V_851 * V_852 )
{
struct V_64 * V_64 ;
struct V_22 * V_22 =
F_502 ( V_486 ) ;
struct V_20 * V_853 ;
struct V_491 * V_23 = & V_22 -> V_109 ;
struct V_20 * V_21 = NULL ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_272 * V_67 ;
int V_143 = - 1 ;
F_36 ( L_163 ,
V_486 -> V_109 . V_197 , F_343 ( V_486 ) ,
V_23 -> V_109 . V_197 , F_484 ( V_23 ) ) ;
if ( V_23 -> V_21 ) {
V_21 = V_23 -> V_21 ;
F_53 ( & V_21 -> V_290 ) ;
V_852 -> V_854 = V_486 -> V_489 ;
V_852 -> V_855 = false ;
if ( V_486 -> V_489 != V_492 )
V_486 -> V_753 -> V_489 ( V_486 , V_492 ) ;
return true ;
}
F_172 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_143 ++ ;
if ( ! ( V_23 -> V_856 & ( 1 << V_143 ) ) )
continue;
if ( ! V_853 -> V_100 ) {
V_21 = V_853 ;
break;
}
}
if ( ! V_21 ) {
F_36 ( L_164 ) ;
return false ;
}
F_53 ( & V_21 -> V_290 ) ;
V_22 -> V_857 = F_30 ( V_21 ) ;
F_534 ( V_486 ) -> V_858 = V_22 ;
V_64 = F_30 ( V_21 ) ;
V_64 -> V_465 = true ;
V_64 -> V_466 = & V_64 -> V_68 ;
V_852 -> V_854 = V_486 -> V_489 ;
V_852 -> V_855 = true ;
V_852 -> V_859 = NULL ;
if ( ! V_381 )
V_381 = & V_860 ;
V_67 = F_531 ( V_2 , V_381 ) ;
if ( V_67 == NULL ) {
F_36 ( L_165 ) ;
V_67 = F_528 ( V_2 , V_381 , 24 , 32 ) ;
V_852 -> V_859 = V_67 ;
} else
F_36 ( L_166 ) ;
if ( F_535 ( V_67 ) ) {
F_36 ( L_167 ) ;
goto V_833;
}
if ( F_536 ( V_21 , V_381 , 0 , 0 , V_67 ) ) {
F_36 ( L_168 ) ;
if ( V_852 -> V_859 )
V_852 -> V_859 -> V_753 -> V_861 ( V_852 -> V_859 ) ;
goto V_833;
}
F_37 ( V_2 , V_64 -> V_72 ) ;
return true ;
V_833:
V_64 -> V_465 = V_21 -> V_100 ;
if ( V_64 -> V_465 )
V_64 -> V_466 = & V_64 -> V_68 ;
else
V_64 -> V_466 = NULL ;
F_55 ( & V_21 -> V_290 ) ;
return false ;
}
void F_537 ( struct V_485 * V_486 ,
struct V_851 * V_852 )
{
struct V_22 * V_22 =
F_502 ( V_486 ) ;
struct V_491 * V_23 = & V_22 -> V_109 ;
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
F_36 ( L_163 ,
V_486 -> V_109 . V_197 , F_343 ( V_486 ) ,
V_23 -> V_109 . V_197 , F_484 ( V_23 ) ) ;
if ( V_852 -> V_855 ) {
F_534 ( V_486 ) -> V_858 = NULL ;
V_22 -> V_857 = NULL ;
V_64 -> V_465 = false ;
V_64 -> V_466 = NULL ;
F_536 ( V_21 , NULL , 0 , 0 , NULL ) ;
if ( V_852 -> V_859 ) {
F_538 ( V_852 -> V_859 ) ;
F_539 ( V_852 -> V_859 ) ;
}
F_55 ( & V_21 -> V_290 ) ;
return;
}
if ( V_852 -> V_854 != V_492 )
V_486 -> V_753 -> V_489 ( V_486 , V_852 -> V_854 ) ;
F_55 ( & V_21 -> V_290 ) ;
}
static int F_540 ( struct V_1 * V_2 ,
const struct V_421 * V_422 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_47 = V_422 -> V_188 . V_47 ;
if ( ( V_47 & V_862 ) == V_600 )
return V_4 -> V_545 . V_549 ;
else if ( F_3 ( V_2 ) )
return 120000 ;
else if ( ! F_18 ( V_2 ) )
return 96000 ;
else
return 48000 ;
}
static void F_421 ( struct V_64 * V_21 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_72 = V_422 -> V_74 ;
T_1 V_47 = V_422 -> V_188 . V_47 ;
T_1 V_551 ;
T_2 clock ;
int V_10 = F_540 ( V_2 , V_422 ) ;
if ( ( V_47 & V_863 ) == 0 )
V_551 = V_422 -> V_188 . V_553 ;
else
V_551 = V_422 -> V_188 . V_556 ;
clock . V_12 = ( V_551 & V_864 ) >> V_865 ;
if ( F_16 ( V_2 ) ) {
clock . V_17 = F_541 ( ( V_551 & V_866 ) >> V_867 ) - 1 ;
clock . V_13 = ( V_551 & V_868 ) >> V_869 ;
} else {
clock . V_17 = ( V_551 & V_870 ) >> V_867 ;
clock . V_13 = ( V_551 & V_871 ) >> V_869 ;
}
if ( ! F_18 ( V_2 ) ) {
if ( F_16 ( V_2 ) )
clock . V_15 = F_541 ( ( V_47 & V_872 ) >>
V_590 ) ;
else
clock . V_15 = F_541 ( ( V_47 & V_873 ) >>
V_591 ) ;
switch ( V_47 & V_874 ) {
case V_587 :
clock . V_16 = V_47 & V_593 ?
5 : 10 ;
break;
case V_586 :
clock . V_16 = V_47 & V_594 ?
7 : 14 ;
break;
default:
F_36 ( L_169
L_170 , ( int ) ( V_47 & V_874 ) ) ;
return;
}
if ( F_16 ( V_2 ) )
F_19 ( V_10 , & clock ) ;
else
F_21 ( V_10 , & clock ) ;
} else {
T_1 V_875 = F_113 ( V_2 ) ? 0 : F_4 ( V_130 ) ;
bool V_641 = ( V_72 == 1 ) && ( V_875 & V_165 ) ;
if ( V_641 ) {
clock . V_15 = F_541 ( ( V_47 & V_876 ) >>
V_591 ) ;
if ( V_875 & V_877 )
clock . V_16 = 7 ;
else
clock . V_16 = 14 ;
} else {
if ( V_47 & V_602 )
clock . V_15 = 2 ;
else {
clock . V_15 = ( ( V_47 & V_878 ) >>
V_591 ) + 2 ;
}
if ( V_47 & V_603 )
clock . V_16 = 4 ;
else
clock . V_16 = 2 ;
}
F_21 ( V_10 , & clock ) ;
}
V_422 -> V_578 = clock . V_19 ;
}
int F_542 ( int V_879 ,
const struct V_537 * V_538 )
{
if ( ! V_538 -> V_543 )
return 0 ;
return F_28 ( ( V_880 ) V_538 -> V_542 * V_879 , V_538 -> V_543 ) ;
}
static void F_462 ( struct V_64 * V_21 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
F_421 ( V_21 , V_422 ) ;
V_422 -> V_69 . V_70 =
F_542 ( F_5 ( V_2 ) * 10000 ,
& V_422 -> V_501 ) ;
}
struct V_303 * F_543 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
enum V_71 V_74 = V_64 -> V_68 . V_74 ;
struct V_303 * V_381 ;
struct V_421 V_422 ;
int V_881 = F_4 ( F_232 ( V_74 ) ) ;
int V_882 = F_4 ( F_236 ( V_74 ) ) ;
int V_883 = F_4 ( F_238 ( V_74 ) ) ;
int V_884 = F_4 ( F_242 ( V_74 ) ) ;
enum V_72 V_72 = V_64 -> V_72 ;
V_381 = F_418 ( sizeof( * V_381 ) , V_655 ) ;
if ( ! V_381 )
return NULL ;
V_422 . V_74 = (enum V_71 ) V_72 ;
V_422 . V_582 = 1 ;
V_422 . V_188 . V_47 = F_4 ( F_51 ( V_72 ) ) ;
V_422 . V_188 . V_553 = F_4 ( F_374 ( V_72 ) ) ;
V_422 . V_188 . V_556 = F_4 ( F_375 ( V_72 ) ) ;
F_421 ( V_64 , & V_422 ) ;
V_381 -> clock = V_422 . V_578 / V_422 . V_582 ;
V_381 -> V_477 = ( V_881 & 0xffff ) + 1 ;
V_381 -> V_620 = ( ( V_881 & 0xffff0000 ) >> 16 ) + 1 ;
V_381 -> V_508 = ( V_882 & 0xffff ) + 1 ;
V_381 -> V_621 = ( ( V_882 & 0xffff0000 ) >> 16 ) + 1 ;
V_381 -> V_479 = ( V_883 & 0xffff ) + 1 ;
V_381 -> V_622 = ( ( V_883 & 0xffff0000 ) >> 16 ) + 1 ;
V_381 -> V_623 = ( V_884 & 0xffff ) + 1 ;
V_381 -> V_624 = ( ( V_884 & 0xffff0000 ) >> 16 ) + 1 ;
F_544 ( V_381 ) ;
return V_381 ;
}
static void F_183 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
int V_72 = V_64 -> V_72 ;
int V_885 = F_51 ( V_72 ) ;
int V_47 ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_645 )
return;
V_47 = F_4 ( V_885 ) ;
if ( ! F_411 ( V_2 ) && ( V_47 & V_863 ) ) {
F_59 ( L_171 ) ;
F_68 ( V_4 , V_72 ) ;
V_47 &= ~ V_863 ;
F_40 ( V_885 , V_47 ) ;
F_37 ( V_2 , V_72 ) ;
V_47 = F_4 ( V_885 ) ;
if ( V_47 & V_863 )
F_59 ( L_172 ) ;
}
}
static void F_545 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_645 )
return;
if ( ! F_411 ( V_2 ) && V_64 -> V_554 ) {
int V_72 = V_64 -> V_72 ;
int V_885 = F_51 ( V_72 ) ;
int V_47 ;
F_59 ( L_173 ) ;
F_68 ( V_4 , V_72 ) ;
V_47 = F_4 ( V_885 ) ;
V_47 |= V_863 ;
F_40 ( V_885 , V_47 ) ;
F_37 ( V_2 , V_72 ) ;
V_47 = F_4 ( V_885 ) ;
if ( ! ( V_47 & V_863 ) )
F_59 ( L_174 ) ;
}
}
void F_546 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_233 . V_886 )
return;
F_547 ( V_4 ) ;
F_548 ( V_4 ) ;
V_4 -> V_233 . V_886 = true ;
}
void F_549 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 ;
if ( ! V_4 -> V_233 . V_886 )
return;
V_4 -> V_233 . V_886 = false ;
if ( ! V_301 . V_555 )
goto V_887;
F_172 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_21 -> V_66 -> V_67 )
continue;
F_545 ( V_21 ) ;
}
if ( F_39 ( V_2 ) -> V_78 >= 6 )
F_550 ( V_2 -> V_5 ) ;
V_887:
F_551 ( V_4 ) ;
}
void F_552 ( struct V_222 * V_223 ,
struct V_224 * V_888 )
{
struct V_1 * V_2 = V_223 -> V_109 . V_2 ;
struct V_20 * V_21 ;
if ( ! V_301 . V_555 )
return;
F_172 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_21 -> V_66 -> V_67 )
continue;
if ( F_168 ( V_21 -> V_66 -> V_67 ) -> V_223 != V_223 )
continue;
F_183 ( V_21 ) ;
if ( V_888 && F_553 ( V_2 ) )
V_888 -> V_889 = true ;
}
}
static void F_554 ( struct V_20 * V_21 )
{
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_890 * V_891 ;
unsigned long V_293 ;
F_192 ( & V_2 -> V_297 , V_293 ) ;
V_891 = V_64 -> V_298 ;
V_64 -> V_298 = NULL ;
F_193 ( & V_2 -> V_297 , V_293 ) ;
if ( V_891 ) {
F_555 ( & V_891 -> V_891 ) ;
F_171 ( V_891 ) ;
}
F_512 ( V_21 , NULL , 0 , 0 , 0 ) ;
F_556 ( V_21 ) ;
F_171 ( V_64 ) ;
}
static void F_557 ( struct V_892 * V_893 )
{
struct V_890 * V_891 =
F_558 ( V_893 , struct V_890 , V_891 ) ;
struct V_1 * V_2 = V_891 -> V_21 -> V_2 ;
F_53 ( & V_2 -> V_268 ) ;
F_161 ( V_891 -> V_894 ) ;
F_169 ( & V_891 -> V_895 -> V_109 ) ;
F_169 ( & V_891 -> V_894 -> V_109 ) ;
F_199 ( V_2 ) ;
F_55 ( & V_2 -> V_268 ) ;
F_111 ( F_191 ( & F_30 ( V_891 -> V_21 ) -> V_348 ) == 0 ) ;
F_559 ( & F_30 ( V_891 -> V_21 ) -> V_348 ) ;
F_171 ( V_891 ) ;
}
static void F_560 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_890 * V_891 ;
unsigned long V_293 ;
if ( V_64 == NULL )
return;
F_192 ( & V_2 -> V_297 , V_293 ) ;
V_891 = V_64 -> V_298 ;
F_561 () ;
if ( V_891 == NULL || F_191 ( & V_891 -> V_294 ) < V_896 ) {
F_193 ( & V_2 -> V_297 , V_293 ) ;
return;
}
F_561 () ;
V_64 -> V_298 = NULL ;
if ( V_891 -> V_897 )
F_562 ( V_2 , V_64 -> V_72 , V_891 -> V_897 ) ;
F_563 ( V_2 , V_64 -> V_72 ) ;
F_193 ( & V_2 -> V_297 , V_293 ) ;
F_564 ( & V_4 -> V_349 ) ;
F_565 ( V_4 -> V_898 , & V_891 -> V_891 ) ;
F_566 ( V_64 -> V_141 , V_891 -> V_895 ) ;
}
void F_567 ( struct V_1 * V_2 , int V_72 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 = V_4 -> V_73 [ V_72 ] ;
F_560 ( V_2 , V_21 ) ;
}
void F_186 ( struct V_1 * V_2 , int V_141 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 = V_4 -> V_899 [ V_141 ] ;
F_560 ( V_2 , V_21 ) ;
}
void F_185 ( struct V_1 * V_2 , int V_141 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 =
F_30 ( V_4 -> V_899 [ V_141 ] ) ;
unsigned long V_293 ;
F_192 ( & V_2 -> V_297 , V_293 ) ;
if ( V_64 -> V_298 )
F_568 ( & V_64 -> V_298 -> V_294 ) ;
F_193 ( & V_2 -> V_297 , V_293 ) ;
}
inline static void F_569 ( struct V_64 * V_64 )
{
F_570 () ;
F_571 ( & V_64 -> V_298 -> V_294 , V_900 ) ;
F_570 () ;
}
static int F_572 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_272 * V_67 ,
struct V_222 * V_223 ,
T_4 V_293 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
T_1 V_901 ;
struct V_224 * V_888 = & V_4 -> V_888 [ V_902 ] ;
int V_227 ;
V_227 = F_154 ( V_2 , V_223 , V_888 ) ;
if ( V_227 )
goto V_53;
V_227 = F_573 ( V_888 , 6 ) ;
if ( V_227 )
goto V_236;
if ( V_64 -> V_141 )
V_901 = V_903 ;
else
V_901 = V_904 ;
F_574 ( V_888 , V_905 | V_901 ) ;
F_574 ( V_888 , V_906 ) ;
F_574 ( V_888 , V_907 |
F_575 ( V_64 -> V_141 ) ) ;
F_574 ( V_888 , V_67 -> V_265 [ 0 ] ) ;
F_574 ( V_888 , F_173 ( V_223 ) + V_64 -> V_285 ) ;
F_574 ( V_888 , 0 ) ;
F_569 ( V_64 ) ;
F_576 ( V_888 ) ;
return 0 ;
V_236:
F_161 ( V_223 ) ;
V_53:
return V_227 ;
}
static int F_577 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_272 * V_67 ,
struct V_222 * V_223 ,
T_4 V_293 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
T_1 V_901 ;
struct V_224 * V_888 = & V_4 -> V_888 [ V_902 ] ;
int V_227 ;
V_227 = F_154 ( V_2 , V_223 , V_888 ) ;
if ( V_227 )
goto V_53;
V_227 = F_573 ( V_888 , 6 ) ;
if ( V_227 )
goto V_236;
if ( V_64 -> V_141 )
V_901 = V_903 ;
else
V_901 = V_904 ;
F_574 ( V_888 , V_905 | V_901 ) ;
F_574 ( V_888 , V_906 ) ;
F_574 ( V_888 , V_908 |
F_575 ( V_64 -> V_141 ) ) ;
F_574 ( V_888 , V_67 -> V_265 [ 0 ] ) ;
F_574 ( V_888 , F_173 ( V_223 ) + V_64 -> V_285 ) ;
F_574 ( V_888 , V_906 ) ;
F_569 ( V_64 ) ;
F_576 ( V_888 ) ;
return 0 ;
V_236:
F_161 ( V_223 ) ;
V_53:
return V_227 ;
}
static int F_578 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_272 * V_67 ,
struct V_222 * V_223 ,
T_4 V_293 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
T_4 V_909 , V_910 ;
struct V_224 * V_888 = & V_4 -> V_888 [ V_902 ] ;
int V_227 ;
V_227 = F_154 ( V_2 , V_223 , V_888 ) ;
if ( V_227 )
goto V_53;
V_227 = F_573 ( V_888 , 4 ) ;
if ( V_227 )
goto V_236;
F_574 ( V_888 , V_907 |
F_575 ( V_64 -> V_141 ) ) ;
F_574 ( V_888 , V_67 -> V_265 [ 0 ] ) ;
F_574 ( V_888 ,
( F_173 ( V_223 ) + V_64 -> V_285 ) |
V_223 -> V_228 ) ;
V_909 = 0 ;
V_910 = F_4 ( F_195 ( V_64 -> V_72 ) ) & 0x0fff0fff ;
F_574 ( V_888 , V_909 | V_910 ) ;
F_569 ( V_64 ) ;
F_576 ( V_888 ) ;
return 0 ;
V_236:
F_161 ( V_223 ) ;
V_53:
return V_227 ;
}
static int F_579 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_272 * V_67 ,
struct V_222 * V_223 ,
T_4 V_293 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_224 * V_888 = & V_4 -> V_888 [ V_902 ] ;
T_4 V_909 , V_910 ;
int V_227 ;
V_227 = F_154 ( V_2 , V_223 , V_888 ) ;
if ( V_227 )
goto V_53;
V_227 = F_573 ( V_888 , 4 ) ;
if ( V_227 )
goto V_236;
F_574 ( V_888 , V_907 |
F_575 ( V_64 -> V_141 ) ) ;
F_574 ( V_888 , V_67 -> V_265 [ 0 ] | V_223 -> V_228 ) ;
F_574 ( V_888 , F_173 ( V_223 ) + V_64 -> V_285 ) ;
V_909 = 0 ;
V_910 = F_4 ( F_195 ( V_64 -> V_72 ) ) & 0x0fff0fff ;
F_574 ( V_888 , V_909 | V_910 ) ;
F_569 ( V_64 ) ;
F_576 ( V_888 ) ;
return 0 ;
V_236:
F_161 ( V_223 ) ;
V_53:
return V_227 ;
}
static int F_580 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_272 * V_67 ,
struct V_222 * V_223 ,
T_4 V_293 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_224 * V_888 ;
T_4 V_911 = 0 ;
int V_779 , V_227 ;
V_888 = V_223 -> V_888 ;
if ( F_17 ( V_2 ) || V_888 == NULL || V_888 -> V_197 != V_902 )
V_888 = & V_4 -> V_888 [ V_912 ] ;
V_227 = F_154 ( V_2 , V_223 , V_888 ) ;
if ( V_227 )
goto V_53;
switch( V_64 -> V_141 ) {
case V_913 :
V_911 = V_914 ;
break;
case V_915 :
V_911 = V_916 ;
break;
case V_917 :
V_911 = V_918 ;
break;
default:
F_581 ( 1 , L_175 ) ;
V_227 = - V_919 ;
goto V_236;
}
V_779 = 4 ;
if ( V_888 -> V_197 == V_902 )
V_779 += 6 ;
V_227 = F_582 ( V_888 ) ;
if ( V_227 )
goto V_236;
V_227 = F_573 ( V_888 , V_779 ) ;
if ( V_227 )
goto V_236;
if ( V_888 -> V_197 == V_902 ) {
F_574 ( V_888 , F_583 ( 1 ) ) ;
F_574 ( V_888 , V_920 ) ;
F_574 ( V_888 , ~ ( V_921 |
V_922 |
V_923 ) ) ;
F_574 ( V_888 , F_584 ( 1 ) |
V_924 ) ;
F_574 ( V_888 , V_920 ) ;
F_574 ( V_888 , V_888 -> V_925 . V_926 + 256 ) ;
}
F_574 ( V_888 , V_908 | V_911 ) ;
F_574 ( V_888 , ( V_67 -> V_265 [ 0 ] | V_223 -> V_228 ) ) ;
F_574 ( V_888 , F_173 ( V_223 ) + V_64 -> V_285 ) ;
F_574 ( V_888 , ( V_906 ) ) ;
F_569 ( V_64 ) ;
F_576 ( V_888 ) ;
return 0 ;
V_236:
F_161 ( V_223 ) ;
V_53:
return V_227 ;
}
static int F_585 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_272 * V_67 ,
struct V_222 * V_223 ,
T_4 V_293 )
{
return - V_919 ;
}
static int F_586 ( struct V_20 * V_21 ,
struct V_272 * V_67 ,
struct V_927 * V_897 ,
T_4 V_928 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_272 * V_291 = V_21 -> V_66 -> V_67 ;
struct V_222 * V_223 = F_168 ( V_67 ) -> V_223 ;
struct V_64 * V_64 = F_30 ( V_21 ) ;
struct V_890 * V_891 ;
unsigned long V_293 ;
int V_227 ;
if ( V_67 -> V_266 != V_21 -> V_66 -> V_67 -> V_266 )
return - V_232 ;
if ( F_39 ( V_2 ) -> V_78 > 3 &&
( V_67 -> V_929 [ 0 ] != V_21 -> V_66 -> V_67 -> V_929 [ 0 ] ||
V_67 -> V_265 [ 0 ] != V_21 -> V_66 -> V_67 -> V_265 [ 0 ] ) )
return - V_232 ;
if ( F_587 ( & V_4 -> V_295 ) )
goto V_930;
V_891 = F_418 ( sizeof( * V_891 ) , V_655 ) ;
if ( V_891 == NULL )
return - V_832 ;
V_891 -> V_897 = V_897 ;
V_891 -> V_21 = V_21 ;
V_891 -> V_894 = F_168 ( V_291 ) -> V_223 ;
F_588 ( & V_891 -> V_891 , F_557 ) ;
V_227 = F_589 ( V_2 , V_64 -> V_72 ) ;
if ( V_227 )
goto V_931;
F_192 ( & V_2 -> V_297 , V_293 ) ;
if ( V_64 -> V_298 ) {
F_193 ( & V_2 -> V_297 , V_293 ) ;
F_171 ( V_891 ) ;
F_563 ( V_2 , V_64 -> V_72 ) ;
F_59 ( L_176 ) ;
return - V_299 ;
}
V_64 -> V_298 = V_891 ;
F_193 ( & V_2 -> V_297 , V_293 ) ;
if ( F_191 ( & V_64 -> V_348 ) >= 2 )
F_590 ( V_4 -> V_898 ) ;
V_227 = F_525 ( V_2 ) ;
if ( V_227 )
goto V_932;
F_591 ( & V_891 -> V_894 -> V_109 ) ;
F_591 ( & V_223 -> V_109 ) ;
V_21 -> V_66 -> V_67 = V_67 ;
V_891 -> V_895 = V_223 ;
V_891 -> V_933 = true ;
F_592 ( & V_64 -> V_348 ) ;
V_64 -> V_296 = F_191 ( & V_4 -> V_295 . V_296 ) ;
V_227 = V_4 -> V_287 . V_934 ( V_2 , V_21 , V_67 , V_223 , V_928 ) ;
if ( V_227 )
goto V_935;
F_282 ( V_2 ) ;
F_552 ( V_223 , NULL ) ;
F_55 ( & V_2 -> V_268 ) ;
F_593 ( V_64 -> V_141 , V_223 ) ;
return 0 ;
V_935:
F_559 ( & V_64 -> V_348 ) ;
V_21 -> V_66 -> V_67 = V_291 ;
F_169 ( & V_891 -> V_894 -> V_109 ) ;
F_169 ( & V_223 -> V_109 ) ;
F_55 ( & V_2 -> V_268 ) ;
V_932:
F_192 ( & V_2 -> V_297 , V_293 ) ;
V_64 -> V_298 = NULL ;
F_193 ( & V_2 -> V_297 , V_293 ) ;
F_563 ( V_2 , V_64 -> V_72 ) ;
V_931:
F_171 ( V_891 ) ;
if ( V_227 == - V_936 ) {
V_930:
F_220 ( V_21 ) ;
V_227 = F_194 ( V_21 , V_21 -> V_237 , V_21 -> V_238 , V_67 ) ;
if ( V_227 == 0 && V_897 )
F_562 ( V_2 , V_64 -> V_72 , V_897 ) ;
}
return V_227 ;
}
static void F_594 ( struct V_1 * V_2 )
{
struct V_64 * V_21 ;
struct V_22 * V_23 ;
struct V_493 * V_486 ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
V_486 -> V_858 =
F_338 ( V_486 -> V_109 . V_23 ) ;
}
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_23 -> V_857 =
F_30 ( V_23 -> V_109 . V_21 ) ;
}
F_172 (crtc, &dev->mode_config.crtc_list,
base.head) {
V_21 -> V_465 = V_21 -> V_109 . V_100 ;
if ( V_21 -> V_465 )
V_21 -> V_466 = & V_21 -> V_68 ;
else
V_21 -> V_466 = NULL ;
}
}
static void F_595 ( struct V_1 * V_2 )
{
struct V_64 * V_21 ;
struct V_22 * V_23 ;
struct V_493 * V_486 ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
V_486 -> V_109 . V_23 = & V_486 -> V_858 -> V_109 ;
}
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_23 -> V_109 . V_21 = & V_23 -> V_857 -> V_109 ;
}
F_172 (crtc, &dev->mode_config.crtc_list,
base.head) {
V_21 -> V_109 . V_100 = V_21 -> V_465 ;
}
}
static void
F_596 ( struct V_493 * V_486 ,
struct V_421 * V_422 )
{
int V_704 = V_422 -> V_500 ;
F_36 ( L_177 ,
V_486 -> V_109 . V_109 . V_197 ,
F_343 ( & V_486 -> V_109 ) ) ;
if ( V_486 -> V_109 . V_937 . V_376 &&
V_486 -> V_109 . V_937 . V_376 * 3 < V_704 ) {
F_36 ( L_178 ,
V_704 , V_486 -> V_109 . V_937 . V_376 * 3 ) ;
V_422 -> V_500 = V_486 -> V_109 . V_937 . V_376 * 3 ;
}
if ( V_486 -> V_109 . V_937 . V_376 == 0 && V_704 > 24 ) {
F_36 ( L_179 ,
V_704 ) ;
V_422 -> V_500 = 24 ;
}
}
static int
F_597 ( struct V_64 * V_21 ,
struct V_272 * V_67 ,
struct V_421 * V_422 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_493 * V_486 ;
int V_704 ;
switch ( V_67 -> V_266 ) {
case V_246 :
V_704 = 8 * 3 ;
break;
case V_248 :
case V_277 :
if ( F_2 ( F_39 ( V_2 ) -> V_78 > 3 ) )
return - V_232 ;
case V_250 :
V_704 = 6 * 3 ;
break;
case V_254 :
case V_279 :
if ( F_2 ( F_39 ( V_2 ) -> V_78 < 4 ) )
return - V_232 ;
case V_252 :
case V_278 :
V_704 = 8 * 3 ;
break;
case V_256 :
case V_280 :
case V_258 :
case V_281 :
if ( F_2 ( F_39 ( V_2 ) -> V_78 < 4 ) )
return - V_232 ;
V_704 = 10 * 3 ;
break;
default:
F_36 ( L_180 ) ;
return - V_232 ;
}
V_422 -> V_500 = V_704 ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_486 -> V_858 ||
V_486 -> V_858 -> V_857 != V_21 )
continue;
F_596 ( V_486 , V_422 ) ;
}
return V_704 ;
}
static void F_598 ( const struct V_303 * V_381 )
{
F_36 ( L_181
L_182 ,
V_381 -> V_70 ,
V_381 -> V_304 , V_381 -> V_610 ,
V_381 -> V_613 , V_381 -> V_609 ,
V_381 -> V_305 , V_381 -> V_615 ,
V_381 -> V_616 , V_381 -> V_605 , V_381 -> type , V_381 -> V_293 ) ;
}
static void F_599 ( struct V_64 * V_21 ,
struct V_421 * V_422 ,
const char * V_938 )
{
F_36 ( L_183 , V_21 -> V_109 . V_109 . V_197 ,
V_938 , F_69 ( V_21 -> V_72 ) ) ;
F_36 ( L_184 , F_600 ( V_422 -> V_74 ) ) ;
F_36 ( L_185 ,
V_422 -> V_500 , V_422 -> V_627 ) ;
F_36 ( L_186 ,
V_422 -> V_216 ,
V_422 -> V_328 ,
V_422 -> V_501 . V_540 , V_422 -> V_501 . V_541 ,
V_422 -> V_501 . V_542 , V_422 -> V_501 . V_543 ,
V_422 -> V_501 . V_539 ) ;
F_36 ( L_187 ,
V_422 -> V_584 ,
V_422 -> V_559 . V_540 , V_422 -> V_559 . V_541 ,
V_422 -> V_559 . V_542 , V_422 -> V_559 . V_543 ,
V_422 -> V_559 . V_539 ) ;
F_36 ( L_188 ) ;
F_601 ( & V_422 -> V_619 ) ;
F_36 ( L_189 ) ;
F_601 ( & V_422 -> V_69 ) ;
F_598 ( & V_422 -> V_69 ) ;
F_36 ( L_190 , V_422 -> V_578 ) ;
F_36 ( L_191 ,
V_422 -> V_308 , V_422 -> V_309 ) ;
F_36 ( L_192 ,
V_422 -> V_423 . V_424 ,
V_422 -> V_423 . V_428 ,
V_422 -> V_423 . V_651 ) ;
F_36 ( L_193 ,
V_422 -> V_306 . V_393 ,
V_422 -> V_306 . V_263 ,
V_422 -> V_306 . V_100 ? L_194 : L_195 ) ;
F_36 ( L_196 , V_422 -> V_396 ) ;
F_36 ( L_197 , V_422 -> V_507 ) ;
}
static bool F_602 ( const struct V_22 * V_939 ,
const struct V_22 * V_940 )
{
return V_939 == V_940 || ( V_939 -> V_941 & ( 1 << V_940 -> type ) &&
V_940 -> V_941 & ( 1 << V_939 -> type ) ) ;
}
static bool F_603 ( struct V_64 * V_21 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_22 * V_942 ;
F_172 (source_encoder,
&dev->mode_config.encoder_list, base.head) {
if ( V_942 -> V_857 != V_21 )
continue;
if ( ! F_602 ( V_23 , V_942 ) )
return false ;
}
return true ;
}
static bool F_604 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_22 * V_23 ;
F_172 (encoder,
&dev->mode_config.encoder_list, base.head) {
if ( V_23 -> V_857 != V_21 )
continue;
if ( ! F_603 ( V_21 , V_23 ) )
return false ;
}
return true ;
}
static struct V_421 *
F_605 ( struct V_20 * V_21 ,
struct V_272 * V_67 ,
struct V_303 * V_381 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_22 * V_23 ;
struct V_421 * V_422 ;
int V_943 , V_227 = - V_232 ;
bool V_333 = true ;
if ( ! F_604 ( F_30 ( V_21 ) ) ) {
F_36 ( L_198 ) ;
return F_523 ( - V_232 ) ;
}
V_422 = F_418 ( sizeof( * V_422 ) , V_655 ) ;
if ( ! V_422 )
return F_523 ( - V_832 ) ;
F_606 ( & V_422 -> V_69 , V_381 ) ;
F_606 ( & V_422 -> V_619 , V_381 ) ;
V_422 -> V_74 =
(enum V_71 ) F_30 ( V_21 ) -> V_72 ;
V_422 -> V_110 = V_386 ;
if ( ! ( V_422 -> V_69 . V_293 &
( V_382 | V_944 ) ) )
V_422 -> V_69 . V_293 |= V_944 ;
if ( ! ( V_422 -> V_69 . V_293 &
( V_384 | V_945 ) ) )
V_422 -> V_69 . V_293 |= V_945 ;
V_943 = F_597 ( F_30 ( V_21 ) ,
V_67 , V_422 ) ;
if ( V_943 < 0 )
goto V_833;
F_607 ( & V_422 -> V_619 , V_946 ) ;
V_422 -> V_308 = V_422 -> V_619 . V_304 ;
V_422 -> V_309 = V_422 -> V_619 . V_305 ;
V_947:
V_422 -> V_578 = 0 ;
V_422 -> V_582 = 1 ;
F_607 ( & V_422 -> V_69 , V_946 ) ;
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( & V_23 -> V_857 -> V_109 != V_21 )
continue;
if ( ! ( V_23 -> V_948 ( V_23 , V_422 ) ) ) {
F_36 ( L_199 ) ;
goto V_833;
}
}
if ( ! V_422 -> V_578 )
V_422 -> V_578 = V_422 -> V_69 . V_70
* V_422 -> V_582 ;
V_227 = F_354 ( F_30 ( V_21 ) , V_422 ) ;
if ( V_227 < 0 ) {
F_36 ( L_200 ) ;
goto V_833;
}
if ( V_227 == V_503 ) {
if ( F_46 ( ! V_333 , L_201 ) ) {
V_227 = - V_232 ;
goto V_833;
}
F_36 ( L_202 ) ;
V_333 = false ;
goto V_947;
}
V_422 -> V_627 = V_422 -> V_500 != V_943 ;
F_36 ( L_203 ,
V_943 , V_422 -> V_500 , V_422 -> V_627 ) ;
return V_422 ;
V_833:
F_171 ( V_422 ) ;
return F_523 ( V_227 ) ;
}
static void
F_608 ( struct V_20 * V_21 , unsigned * V_949 ,
unsigned * V_467 , unsigned * V_950 )
{
struct V_64 * V_64 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_22 * V_23 ;
struct V_493 * V_486 ;
struct V_20 * V_951 ;
* V_950 = * V_949 = * V_467 = 0 ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_486 -> V_109 . V_23 == & V_486 -> V_858 -> V_109 )
continue;
if ( V_486 -> V_109 . V_23 ) {
V_951 = V_486 -> V_109 . V_23 -> V_21 ;
* V_467 |= 1 << F_30 ( V_951 ) -> V_72 ;
}
if ( V_486 -> V_858 )
* V_467 |=
1 << V_486 -> V_858 -> V_857 -> V_72 ;
}
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_23 -> V_109 . V_21 == & V_23 -> V_857 -> V_109 )
continue;
if ( V_23 -> V_109 . V_21 ) {
V_951 = V_23 -> V_109 . V_21 ;
* V_467 |= 1 << F_30 ( V_951 ) -> V_72 ;
}
if ( V_23 -> V_857 )
* V_467 |= 1 << V_23 -> V_857 -> V_72 ;
}
F_172 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_64 -> V_109 . V_100 == V_64 -> V_465 )
continue;
if ( ! V_64 -> V_465 )
* V_950 |= 1 << V_64 -> V_72 ;
else
* V_467 |= 1 << V_64 -> V_72 ;
}
V_64 = F_30 ( V_21 ) ;
if ( V_64 -> V_465 )
* V_467 |= 1 << V_64 -> V_72 ;
if ( * V_467 )
* V_949 = * V_467 ;
* V_949 &= ~ ( * V_950 ) ;
* V_467 &= ~ ( * V_950 ) ;
* V_949 &= 1 << V_64 -> V_72 ;
* V_467 &= 1 << V_64 -> V_72 ;
F_36 ( L_204 ,
* V_949 , * V_467 , * V_950 ) ;
}
static bool F_609 ( struct V_20 * V_21 )
{
struct V_491 * V_23 ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_172 (encoder, &dev->mode_config.encoder_list, head)
if ( V_23 -> V_21 == V_21 )
return true ;
return false ;
}
static void
F_610 ( struct V_1 * V_2 , unsigned V_467 )
{
struct V_22 * V_22 ;
struct V_64 * V_64 ;
struct V_485 * V_486 ;
F_172 (intel_encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_22 -> V_109 . V_21 )
continue;
V_64 = F_30 ( V_22 -> V_109 . V_21 ) ;
if ( V_467 & ( 1 << V_64 -> V_72 ) )
V_22 -> V_482 = false ;
}
F_595 ( V_2 ) ;
F_172 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
F_2 ( V_64 -> V_109 . V_100 != F_609 ( & V_64 -> V_109 ) ) ;
F_2 ( V_64 -> V_466 &&
V_64 -> V_466 != & V_64 -> V_68 ) ;
F_2 ( V_64 -> V_109 . V_100 != ! ! V_64 -> V_466 ) ;
}
F_172 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_486 -> V_23 || ! V_486 -> V_23 -> V_21 )
continue;
V_64 = F_30 ( V_486 -> V_23 -> V_21 ) ;
if ( V_467 & ( 1 << V_64 -> V_72 ) ) {
struct V_952 * V_953 =
V_2 -> V_660 . V_953 ;
V_486 -> V_489 = V_492 ;
F_611 ( & V_486 -> V_109 ,
V_953 ,
V_492 ) ;
V_22 = F_338 ( V_486 -> V_23 ) ;
V_22 -> V_482 = true ;
}
}
}
static bool F_612 ( int V_954 , int V_955 )
{
int V_63 ;
if ( V_954 == V_955 )
return true ;
if ( ! V_954 || ! V_955 )
return false ;
V_63 = abs ( V_954 - V_955 ) ;
if ( ( ( ( ( V_63 + V_954 + V_955 ) * 100 ) ) / ( V_954 + V_955 ) ) < 105 )
return true ;
return false ;
}
static bool
F_613 ( struct V_1 * V_2 ,
struct V_421 * V_956 ,
struct V_421 * V_422 )
{
#define F_614 ( V_116 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_615 ( V_116 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_616 ( V_116 , V_441 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
DRM_ERROR("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
return false; \
}
#define F_617 ( V_116 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_618 ( T_9 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_615 ( V_74 ) ;
F_615 ( V_216 ) ;
F_615 ( V_328 ) ;
F_615 ( V_501 . V_540 ) ;
F_615 ( V_501 . V_541 ) ;
F_615 ( V_501 . V_542 ) ;
F_615 ( V_501 . V_543 ) ;
F_615 ( V_501 . V_539 ) ;
F_615 ( V_584 ) ;
F_615 ( V_559 . V_540 ) ;
F_615 ( V_559 . V_541 ) ;
F_615 ( V_559 . V_542 ) ;
F_615 ( V_559 . V_543 ) ;
F_615 ( V_559 . V_539 ) ;
F_615 ( V_69 . V_304 ) ;
F_615 ( V_69 . V_609 ) ;
F_615 ( V_69 . V_611 ) ;
F_615 ( V_69 . V_612 ) ;
F_615 ( V_69 . V_610 ) ;
F_615 ( V_69 . V_613 ) ;
F_615 ( V_69 . V_305 ) ;
F_615 ( V_69 . V_605 ) ;
F_615 ( V_69 . V_614 ) ;
F_615 ( V_69 . V_606 ) ;
F_615 ( V_69 . V_615 ) ;
F_615 ( V_69 . V_616 ) ;
F_615 ( V_582 ) ;
F_616 ( V_69 . V_293 ,
V_608 ) ;
if ( ! F_618 ( V_957 ) ) {
F_616 ( V_69 . V_293 ,
V_382 ) ;
F_616 ( V_69 . V_293 ,
V_944 ) ;
F_616 ( V_69 . V_293 ,
V_384 ) ;
F_616 ( V_69 . V_293 ,
V_945 ) ;
}
F_615 ( V_308 ) ;
F_615 ( V_309 ) ;
if ( ! F_618 ( V_958 ) ) {
F_615 ( V_423 . V_424 ) ;
if ( F_39 ( V_2 ) -> V_78 < 4 )
F_615 ( V_423 . V_428 ) ;
F_615 ( V_423 . V_651 ) ;
}
F_615 ( V_306 . V_100 ) ;
if ( V_956 -> V_306 . V_100 ) {
F_615 ( V_306 . V_393 ) ;
F_615 ( V_306 . V_263 ) ;
}
if ( F_142 ( V_2 ) )
F_615 ( V_396 ) ;
F_615 ( V_507 ) ;
F_615 ( V_110 ) ;
F_614 ( V_188 . V_47 ) ;
F_614 ( V_188 . V_190 ) ;
F_614 ( V_188 . V_553 ) ;
F_614 ( V_188 . V_556 ) ;
if ( F_15 ( V_2 ) || F_39 ( V_2 ) -> V_78 >= 5 )
F_615 ( V_500 ) ;
F_617 ( V_69 . V_70 ) ;
F_617 ( V_578 ) ;
#undef F_614
#undef F_615
#undef F_616
#undef F_617
#undef F_618
return true ;
}
static void
F_619 ( struct V_1 * V_2 )
{
struct V_493 * V_486 ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
F_342 ( V_486 ) ;
F_46 ( & V_486 -> V_858 -> V_109 != V_486 -> V_109 . V_23 ,
L_205 ) ;
}
}
static void
F_620 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_493 * V_486 ;
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
bool V_100 = false ;
bool V_65 = false ;
enum V_72 V_72 , V_959 ;
F_36 ( L_206 ,
V_23 -> V_109 . V_109 . V_197 ,
F_484 ( & V_23 -> V_109 ) ) ;
F_46 ( & V_23 -> V_857 -> V_109 != V_23 -> V_109 . V_21 ,
L_207 ) ;
F_46 ( V_23 -> V_482 && ! V_23 -> V_109 . V_21 ,
L_208 ) ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_486 -> V_109 . V_23 != & V_23 -> V_109 )
continue;
V_100 = true ;
if ( V_486 -> V_109 . V_489 != V_490 )
V_65 = true ;
}
F_46 ( ! ! V_23 -> V_109 . V_21 != V_100 ,
L_209
L_210 ,
! ! V_23 -> V_109 . V_21 , V_100 ) ;
F_46 ( V_65 && ! V_23 -> V_109 . V_21 ,
L_211 ) ;
F_46 ( V_23 -> V_482 != V_65 ,
L_212
L_210 , V_65 , V_23 -> V_482 ) ;
V_65 = V_23 -> V_115 ( V_23 , & V_72 ) ;
F_46 ( V_65 != V_23 -> V_482 ,
L_213
L_210 ,
V_23 -> V_482 , V_65 ) ;
if ( ! V_23 -> V_109 . V_21 )
continue;
V_959 = F_30 ( V_23 -> V_109 . V_21 ) -> V_72 ;
F_46 ( V_65 && V_72 != V_959 ,
L_214
L_210 ,
V_959 , V_72 ) ;
}
}
static void
F_621 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_21 ;
struct V_22 * V_23 ;
struct V_421 V_422 ;
F_172 (crtc, &dev->mode_config.crtc_list,
base.head) {
bool V_100 = false ;
bool V_65 = false ;
memset ( & V_422 , 0 , sizeof( V_422 ) ) ;
F_36 ( L_215 ,
V_21 -> V_109 . V_109 . V_197 ) ;
F_46 ( V_21 -> V_65 && ! V_21 -> V_109 . V_100 ,
L_216 ) ;
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_23 -> V_109 . V_21 != & V_21 -> V_109 )
continue;
V_100 = true ;
if ( V_23 -> V_482 )
V_65 = true ;
}
F_46 ( V_65 != V_21 -> V_65 ,
L_217
L_210 , V_65 , V_21 -> V_65 ) ;
F_46 ( V_100 != V_21 -> V_109 . V_100 ,
L_218
L_210 , V_100 , V_21 -> V_109 . V_100 ) ;
V_65 = V_4 -> V_287 . V_960 ( V_21 ,
& V_422 ) ;
if ( V_21 -> V_72 == V_125 && V_4 -> V_138 & V_139 )
V_65 = V_21 -> V_65 ;
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
enum V_72 V_72 ;
if ( V_23 -> V_109 . V_21 != & V_21 -> V_109 )
continue;
if ( V_23 -> V_115 ( V_23 , & V_72 ) )
V_23 -> V_961 ( V_23 , & V_422 ) ;
}
F_46 ( V_21 -> V_65 != V_65 ,
L_219
L_210 , V_21 -> V_65 , V_65 ) ;
if ( V_65 &&
! F_613 ( V_2 , & V_21 -> V_68 , & V_422 ) ) {
F_46 ( 1 , L_220 ) ;
F_599 ( V_21 , & V_422 ,
L_221 ) ;
F_599 ( V_21 , & V_21 -> V_68 ,
L_222 ) ;
}
}
}
static void
F_622 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_21 ;
struct V_113 V_188 ;
int V_143 ;
for ( V_143 = 0 ; V_143 < V_4 -> V_388 ; V_143 ++ ) {
struct V_108 * V_112 = & V_4 -> V_111 [ V_143 ] ;
int V_962 = 0 , V_963 = 0 ;
bool V_65 ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
F_36 ( L_223 , V_112 -> V_116 ) ;
V_65 = V_112 -> V_115 ( V_4 , V_112 , & V_188 ) ;
F_46 ( V_112 -> V_65 > V_112 -> V_195 ,
L_224 ,
V_112 -> V_65 , V_112 -> V_195 ) ;
F_46 ( V_112 -> V_65 && ! V_112 -> V_196 ,
L_225 ) ;
F_46 ( V_112 -> V_196 && ! V_112 -> V_65 ,
L_226 ) ;
F_46 ( V_112 -> V_196 != V_65 ,
L_227 ,
V_112 -> V_196 , V_65 ) ;
F_172 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_21 -> V_109 . V_100 && F_56 ( V_21 ) == V_112 )
V_962 ++ ;
if ( V_21 -> V_65 && F_56 ( V_21 ) == V_112 )
V_963 ++ ;
}
F_46 ( V_112 -> V_65 != V_963 ,
L_228 ,
V_112 -> V_65 , V_963 ) ;
F_46 ( V_112 -> V_195 != V_962 ,
L_229 ,
V_112 -> V_195 , V_962 ) ;
F_46 ( V_112 -> V_196 && memcmp ( & V_112 -> V_114 , & V_188 ,
sizeof( V_188 ) ) ,
L_230 ) ;
}
}
void
F_345 ( struct V_1 * V_2 )
{
F_619 ( V_2 ) ;
F_620 ( V_2 ) ;
F_621 ( V_2 ) ;
F_622 ( V_2 ) ;
}
void F_623 ( const struct V_421 * V_422 ,
int V_964 )
{
F_46 ( ! F_612 ( V_422 -> V_69 . V_70 , V_964 ) ,
L_231 ,
V_422 -> V_69 . V_70 , V_964 ) ;
}
static int F_624 ( struct V_20 * V_21 ,
struct V_303 * V_381 ,
int V_237 , int V_238 , struct V_272 * V_67 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_303 * V_965 ;
struct V_421 * V_422 = NULL ;
struct V_64 * V_64 ;
unsigned V_950 , V_467 , V_949 ;
int V_227 = 0 ;
V_965 = F_625 ( sizeof( * V_965 ) , V_655 ) ;
if ( ! V_965 )
return - V_832 ;
F_608 ( V_21 , & V_949 ,
& V_467 , & V_950 ) ;
* V_965 = V_21 -> V_381 ;
if ( V_949 ) {
V_422 = F_605 ( V_21 , V_67 , V_381 ) ;
if ( F_535 ( V_422 ) ) {
V_227 = F_626 ( V_422 ) ;
V_422 = NULL ;
goto V_887;
}
F_599 ( F_30 ( V_21 ) , V_422 ,
L_232 ) ;
F_30 ( V_21 ) -> V_466 = V_422 ;
}
if ( F_17 ( V_2 ) ) {
F_327 ( V_2 , & V_467 ) ;
V_467 &= ~ V_950 ;
}
F_627 (dev, disable_pipes, intel_crtc)
F_336 ( & V_64 -> V_109 ) ;
F_627 (dev, prepare_pipes, intel_crtc) {
if ( V_64 -> V_109 . V_100 )
V_4 -> V_287 . V_484 ( & V_64 -> V_109 ) ;
}
if ( V_949 ) {
V_21 -> V_381 = * V_381 ;
F_30 ( V_21 ) -> V_68 = * V_422 ;
F_30 ( V_21 ) -> V_466 = & F_30 ( V_21 ) -> V_68 ;
F_628 ( V_21 ,
& V_422 -> V_69 ) ;
}
F_610 ( V_2 , V_467 ) ;
if ( V_4 -> V_287 . V_966 )
V_4 -> V_287 . V_966 ( V_2 ) ;
F_627 (dev, modeset_pipes, intel_crtc) {
V_227 = F_481 ( & V_64 -> V_109 ,
V_237 , V_238 , V_67 ) ;
if ( V_227 )
goto V_967;
}
F_627 (dev, prepare_pipes, intel_crtc)
V_4 -> V_287 . V_483 ( & V_64 -> V_109 ) ;
V_967:
if ( V_227 && V_21 -> V_100 )
V_21 -> V_381 = * V_965 ;
V_887:
F_171 ( V_422 ) ;
F_171 ( V_965 ) ;
return V_227 ;
}
static int F_536 ( struct V_20 * V_21 ,
struct V_303 * V_381 ,
int V_237 , int V_238 , struct V_272 * V_67 )
{
int V_227 ;
V_227 = F_624 ( V_21 , V_381 , V_237 , V_238 , V_67 ) ;
if ( V_227 == 0 )
F_345 ( V_21 -> V_2 ) ;
return V_227 ;
}
void F_629 ( struct V_20 * V_21 )
{
F_536 ( V_21 , & V_21 -> V_381 , V_21 -> V_237 , V_21 -> V_238 , V_21 -> V_66 -> V_67 ) ;
}
static void F_630 ( struct V_968 * V_68 )
{
if ( ! V_68 )
return;
F_171 ( V_68 -> V_969 ) ;
F_171 ( V_68 -> V_970 ) ;
F_171 ( V_68 -> V_971 ) ;
F_171 ( V_68 ) ;
}
static int F_631 ( struct V_1 * V_2 ,
struct V_968 * V_68 )
{
struct V_20 * V_21 ;
struct V_491 * V_23 ;
struct V_485 * V_486 ;
int V_972 ;
V_68 -> V_971 =
F_632 ( V_2 -> V_660 . V_973 ,
sizeof( bool ) , V_655 ) ;
if ( ! V_68 -> V_971 )
return - V_832 ;
V_68 -> V_970 =
F_632 ( V_2 -> V_660 . V_974 ,
sizeof( struct V_20 * ) , V_655 ) ;
if ( ! V_68 -> V_970 )
return - V_832 ;
V_68 -> V_969 =
F_632 ( V_2 -> V_660 . V_975 ,
sizeof( struct V_491 * ) , V_655 ) ;
if ( ! V_68 -> V_969 )
return - V_832 ;
V_972 = 0 ;
F_172 (crtc, &dev->mode_config.crtc_list, head) {
V_68 -> V_971 [ V_972 ++ ] = V_21 -> V_100 ;
}
V_972 = 0 ;
F_172 (encoder, &dev->mode_config.encoder_list, head) {
V_68 -> V_970 [ V_972 ++ ] = V_23 -> V_21 ;
}
V_972 = 0 ;
F_172 (connector, &dev->mode_config.connector_list, head) {
V_68 -> V_969 [ V_972 ++ ] = V_486 -> V_23 ;
}
return 0 ;
}
static void F_633 ( struct V_1 * V_2 ,
struct V_968 * V_68 )
{
struct V_64 * V_21 ;
struct V_22 * V_23 ;
struct V_493 * V_486 ;
int V_972 ;
V_972 = 0 ;
F_172 (crtc, &dev->mode_config.crtc_list, base.head) {
V_21 -> V_465 = V_68 -> V_971 [ V_972 ++ ] ;
if ( V_21 -> V_465 )
V_21 -> V_466 = & V_21 -> V_68 ;
else
V_21 -> V_466 = NULL ;
}
V_972 = 0 ;
F_172 (encoder, &dev->mode_config.encoder_list, base.head) {
V_23 -> V_857 =
F_30 ( V_68 -> V_970 [ V_972 ++ ] ) ;
}
V_972 = 0 ;
F_172 (connector, &dev->mode_config.connector_list, base.head) {
V_486 -> V_858 =
F_338 ( V_68 -> V_969 [ V_972 ++ ] ) ;
}
}
static bool
F_634 ( struct V_976 * V_977 )
{
int V_143 ;
if ( V_977 -> V_548 == 0 )
return false ;
if ( F_2 ( V_977 -> V_978 == NULL ) )
return false ;
for ( V_143 = 0 ; V_143 < V_977 -> V_548 ; V_143 ++ )
if ( V_977 -> V_978 [ V_143 ] -> V_23 &&
V_977 -> V_978 [ V_143 ] -> V_23 -> V_21 == V_977 -> V_21 &&
V_977 -> V_978 [ V_143 ] -> V_489 != V_492 )
return true ;
return false ;
}
static void
F_635 ( struct V_976 * V_977 ,
struct V_968 * V_68 )
{
if ( F_634 ( V_977 ) ) {
V_68 -> V_979 = true ;
} else if ( V_977 -> V_21 -> V_66 -> V_67 != V_977 -> V_67 ) {
if ( V_977 -> V_21 -> V_66 -> V_67 == NULL ) {
struct V_64 * V_64 =
F_30 ( V_977 -> V_21 ) ;
if ( V_64 -> V_65 && V_301 . V_302 ) {
F_36 ( L_233 ) ;
V_68 -> V_980 = true ;
} else {
F_36 ( L_234 ) ;
V_68 -> V_979 = true ;
}
} else if ( V_977 -> V_67 == NULL ) {
V_68 -> V_979 = true ;
} else if ( V_977 -> V_67 -> V_266 !=
V_977 -> V_21 -> V_66 -> V_67 -> V_266 ) {
V_68 -> V_979 = true ;
} else {
V_68 -> V_980 = true ;
}
}
if ( V_977 -> V_67 && ( V_977 -> V_237 != V_977 -> V_21 -> V_237 || V_977 -> V_238 != V_977 -> V_21 -> V_238 ) )
V_68 -> V_980 = true ;
if ( V_977 -> V_381 && ! F_636 ( V_977 -> V_381 , & V_977 -> V_21 -> V_381 ) ) {
F_36 ( L_235 ) ;
F_601 ( & V_977 -> V_21 -> V_381 ) ;
F_601 ( V_977 -> V_381 ) ;
V_68 -> V_979 = true ;
}
F_36 ( L_236 ,
V_977 -> V_21 -> V_109 . V_197 , V_68 -> V_979 , V_68 -> V_980 ) ;
}
static int
F_637 ( struct V_1 * V_2 ,
struct V_976 * V_977 ,
struct V_968 * V_68 )
{
struct V_493 * V_486 ;
struct V_22 * V_23 ;
struct V_64 * V_21 ;
int V_981 ;
F_2 ( ! V_977 -> V_67 && ( V_977 -> V_548 != 0 ) ) ;
F_2 ( V_977 -> V_67 && ( V_977 -> V_548 == 0 ) ) ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
for ( V_981 = 0 ; V_981 < V_977 -> V_548 ; V_981 ++ ) {
if ( V_977 -> V_978 [ V_981 ] == & V_486 -> V_109 ) {
V_486 -> V_858 = V_486 -> V_23 ;
break;
}
}
if ( ( ! V_977 -> V_67 || V_981 == V_977 -> V_548 ) &&
V_486 -> V_109 . V_23 &&
V_486 -> V_109 . V_23 -> V_21 == V_977 -> V_21 ) {
V_486 -> V_858 = NULL ;
F_36 ( L_237 ,
V_486 -> V_109 . V_109 . V_197 ,
F_343 ( & V_486 -> V_109 ) ) ;
}
if ( & V_486 -> V_858 -> V_109 != V_486 -> V_109 . V_23 ) {
F_36 ( L_238 ) ;
V_68 -> V_979 = true ;
}
}
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
struct V_20 * V_857 ;
if ( ! V_486 -> V_858 )
continue;
V_857 = V_486 -> V_858 -> V_109 . V_21 ;
for ( V_981 = 0 ; V_981 < V_977 -> V_548 ; V_981 ++ ) {
if ( V_977 -> V_978 [ V_981 ] == & V_486 -> V_109 )
V_857 = V_977 -> V_21 ;
}
if ( ! F_638 ( & V_486 -> V_858 -> V_109 ,
V_857 ) ) {
return - V_232 ;
}
V_486 -> V_23 -> V_857 = F_30 ( V_857 ) ;
F_36 ( L_239 ,
V_486 -> V_109 . V_109 . V_197 ,
F_343 ( & V_486 -> V_109 ) ,
V_857 -> V_109 . V_197 ) ;
}
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
int V_548 = 0 ;
F_172 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_486 -> V_858 == V_23 ) {
F_2 ( ! V_486 -> V_858 -> V_857 ) ;
V_548 ++ ;
}
}
if ( V_548 == 0 )
V_23 -> V_857 = NULL ;
else if ( V_548 > 1 )
return - V_232 ;
if ( & V_23 -> V_857 -> V_109 != V_23 -> V_109 . V_21 ) {
F_36 ( L_240 ) ;
V_68 -> V_979 = true ;
}
}
F_172 (crtc, &dev->mode_config.crtc_list,
base.head) {
V_21 -> V_465 = false ;
F_172 (encoder,
&dev->mode_config.encoder_list,
base.head) {
if ( V_23 -> V_857 == V_21 ) {
V_21 -> V_465 = true ;
break;
}
}
if ( V_21 -> V_465 != V_21 -> V_109 . V_100 ) {
F_36 ( L_241 ,
V_21 -> V_465 ? L_242 : L_243 ) ;
V_68 -> V_979 = true ;
}
if ( V_21 -> V_465 )
V_21 -> V_466 = & V_21 -> V_68 ;
else
V_21 -> V_466 = NULL ;
}
return 0 ;
}
static void F_639 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_22 * V_23 ;
struct V_493 * V_486 ;
F_36 ( L_244 ,
F_69 ( V_21 -> V_72 ) ) ;
F_172 (connector, &dev->mode_config.connector_list, base.head) {
if ( V_486 -> V_858 &&
V_486 -> V_858 -> V_857 == V_21 )
V_486 -> V_858 = NULL ;
}
F_172 (encoder, &dev->mode_config.encoder_list, base.head) {
if ( V_23 -> V_857 == V_21 )
V_23 -> V_857 = NULL ;
}
V_21 -> V_465 = false ;
V_21 -> V_466 = NULL ;
}
static int F_640 ( struct V_976 * V_977 )
{
struct V_1 * V_2 ;
struct V_976 V_982 ;
struct V_968 * V_68 ;
int V_227 ;
F_111 ( ! V_977 ) ;
F_111 ( ! V_977 -> V_21 ) ;
F_111 ( ! V_977 -> V_21 -> V_983 ) ;
F_111 ( ! V_977 -> V_381 && V_977 -> V_67 ) ;
F_111 ( V_977 -> V_67 && V_977 -> V_548 == 0 ) ;
if ( V_977 -> V_67 ) {
F_36 ( L_245 ,
V_977 -> V_21 -> V_109 . V_197 , V_977 -> V_67 -> V_109 . V_197 ,
( int ) V_977 -> V_548 , V_977 -> V_237 , V_977 -> V_238 ) ;
} else {
F_36 ( L_246 , V_977 -> V_21 -> V_109 . V_197 ) ;
}
V_2 = V_977 -> V_21 -> V_2 ;
V_227 = - V_832 ;
V_68 = F_418 ( sizeof( * V_68 ) , V_655 ) ;
if ( ! V_68 )
goto V_984;
V_227 = F_631 ( V_2 , V_68 ) ;
if ( V_227 )
goto V_984;
V_982 . V_21 = V_977 -> V_21 ;
V_982 . V_381 = & V_977 -> V_21 -> V_381 ;
V_982 . V_237 = V_977 -> V_21 -> V_237 ;
V_982 . V_238 = V_977 -> V_21 -> V_238 ;
V_982 . V_67 = V_977 -> V_21 -> V_66 -> V_67 ;
F_635 ( V_977 , V_68 ) ;
V_227 = F_637 ( V_2 , V_977 , V_68 ) ;
if ( V_227 )
goto V_833;
if ( V_68 -> V_979 ) {
V_227 = F_536 ( V_977 -> V_21 , V_977 -> V_381 ,
V_977 -> V_237 , V_977 -> V_238 , V_977 -> V_67 ) ;
} else if ( V_68 -> V_980 ) {
F_220 ( V_977 -> V_21 ) ;
V_227 = F_194 ( V_977 -> V_21 ,
V_977 -> V_237 , V_977 -> V_238 , V_977 -> V_67 ) ;
if ( V_301 . V_302 && V_227 == 0 )
F_345 ( V_977 -> V_21 -> V_2 ) ;
}
if ( V_227 ) {
F_36 ( L_247 ,
V_977 -> V_21 -> V_109 . V_197 , V_227 ) ;
V_833:
F_633 ( V_2 , V_68 ) ;
if ( F_30 ( V_982 . V_21 ) -> V_465 && ! V_982 . V_67 )
F_639 ( F_30 ( V_982 . V_21 ) ) ;
if ( V_68 -> V_979 &&
F_536 ( V_982 . V_21 , V_982 . V_381 ,
V_982 . V_237 , V_982 . V_238 , V_982 . V_67 ) )
F_116 ( L_248 ) ;
}
V_984:
F_630 ( V_68 ) ;
return V_227 ;
}
static void F_641 ( struct V_1 * V_2 )
{
if ( F_61 ( V_2 ) )
F_642 ( V_2 ) ;
}
static bool F_643 ( struct V_3 * V_4 ,
struct V_108 * V_112 ,
struct V_113 * V_114 )
{
T_4 V_102 ;
V_102 = F_4 ( F_644 ( V_112 -> V_197 ) ) ;
V_114 -> V_47 = V_102 ;
V_114 -> V_553 = F_4 ( F_645 ( V_112 -> V_197 ) ) ;
V_114 -> V_556 = F_4 ( F_646 ( V_112 -> V_197 ) ) ;
return V_102 & V_104 ;
}
static void F_647 ( struct V_3 * V_4 ,
struct V_108 * V_112 )
{
F_40 ( F_645 ( V_112 -> V_197 ) , V_112 -> V_114 . V_553 ) ;
F_40 ( F_646 ( V_112 -> V_197 ) , V_112 -> V_114 . V_556 ) ;
}
static void F_648 ( struct V_3 * V_4 ,
struct V_108 * V_112 )
{
F_89 ( V_4 ) ;
F_40 ( F_644 ( V_112 -> V_197 ) , V_112 -> V_114 . V_47 ) ;
F_114 ( F_644 ( V_112 -> V_197 ) ) ;
F_115 ( 150 ) ;
F_40 ( F_644 ( V_112 -> V_197 ) , V_112 -> V_114 . V_47 ) ;
F_114 ( F_644 ( V_112 -> V_197 ) ) ;
F_115 ( 200 ) ;
}
static void F_649 ( struct V_3 * V_4 ,
struct V_108 * V_112 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_64 * V_21 ;
F_172 (crtc, &dev->mode_config.crtc_list, base.head) {
if ( F_56 ( V_21 ) == V_112 )
F_91 ( V_4 , V_21 -> V_72 ) ;
}
F_40 ( F_644 ( V_112 -> V_197 ) , 0 ) ;
F_114 ( F_644 ( V_112 -> V_197 ) ) ;
F_115 ( 200 ) ;
}
static void F_650 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_143 ;
V_4 -> V_388 = 2 ;
for ( V_143 = 0 ; V_143 < V_4 -> V_388 ; V_143 ++ ) {
V_4 -> V_111 [ V_143 ] . V_197 = V_143 ;
V_4 -> V_111 [ V_143 ] . V_116 = V_985 [ V_143 ] ;
V_4 -> V_111 [ V_143 ] . V_389 = F_647 ;
V_4 -> V_111 [ V_143 ] . V_198 = F_648 ;
V_4 -> V_111 [ V_143 ] . V_199 = F_649 ;
V_4 -> V_111 [ V_143 ] . V_115 =
F_643 ;
}
}
static void F_651 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_48 ( V_2 ) || F_90 ( V_2 ) )
F_650 ( V_2 ) ;
else
V_4 -> V_388 = 0 ;
F_111 ( V_4 -> V_388 > V_986 ) ;
}
static void F_652 ( struct V_1 * V_2 , int V_72 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_64 ;
int V_143 ;
V_64 = F_418 ( sizeof( * V_64 ) , V_655 ) ;
if ( V_64 == NULL )
return;
F_653 ( V_2 , & V_64 -> V_109 , & V_987 ) ;
if ( F_18 ( V_2 ) ) {
V_64 -> V_988 = V_989 ;
V_64 -> V_990 = V_991 ;
} else {
V_64 -> V_988 = V_992 ;
V_64 -> V_990 = V_993 ;
}
V_2 -> V_660 . V_810 = V_64 -> V_988 ;
V_2 -> V_660 . V_823 = V_64 -> V_990 ;
F_654 ( & V_64 -> V_109 , 256 ) ;
for ( V_143 = 0 ; V_143 < 256 ; V_143 ++ ) {
V_64 -> V_406 [ V_143 ] = V_143 ;
V_64 -> V_407 [ V_143 ] = V_143 ;
V_64 -> V_408 [ V_143 ] = V_143 ;
}
V_64 -> V_72 = V_72 ;
V_64 -> V_141 = V_72 ;
if ( F_655 ( V_2 ) && F_39 ( V_2 ) -> V_78 < 4 ) {
F_36 ( L_249 ) ;
V_64 -> V_141 = ! V_72 ;
}
F_111 ( V_72 >= F_215 ( V_4 -> V_899 ) ||
V_4 -> V_899 [ V_64 -> V_141 ] != NULL ) ;
V_4 -> V_899 [ V_64 -> V_141 ] = & V_64 -> V_109 ;
V_4 -> V_73 [ V_64 -> V_72 ] = & V_64 -> V_109 ;
F_656 ( & V_64 -> V_109 , & V_994 ) ;
}
enum V_72 F_657 ( struct V_493 * V_486 )
{
struct V_491 * V_23 = V_486 -> V_109 . V_23 ;
F_2 ( ! F_658 ( & V_486 -> V_109 . V_2 -> V_660 . V_290 ) ) ;
if ( ! V_23 )
return V_995 ;
return F_30 ( V_23 -> V_21 ) -> V_72 ;
}
int F_659 ( struct V_1 * V_2 , void * V_996 ,
struct V_825 * V_826 )
{
struct V_997 * V_998 = V_996 ;
struct V_999 * V_1000 ;
struct V_64 * V_21 ;
if ( ! F_660 ( V_2 , V_1001 ) )
return - V_919 ;
V_1000 = F_661 ( V_2 , V_998 -> V_1002 ,
V_1003 ) ;
if ( ! V_1000 ) {
F_116 ( L_250 ) ;
return - V_831 ;
}
V_21 = F_30 ( F_662 ( V_1000 ) ) ;
V_998 -> V_72 = V_21 -> V_72 ;
return 0 ;
}
static int F_663 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_109 . V_2 ;
struct V_22 * V_942 ;
int V_1004 = 0 ;
int V_1005 = 0 ;
F_172 (source_encoder,
&dev->mode_config.encoder_list, base.head) {
if ( F_602 ( V_23 , V_942 ) )
V_1004 |= ( 1 << V_1005 ) ;
V_1005 ++ ;
}
return V_1004 ;
}
static bool F_664 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_112 ( V_2 ) )
return false ;
if ( ( F_4 ( V_1006 ) & V_1007 ) == 0 )
return false ;
if ( F_6 ( V_2 ) && ( F_4 ( V_1008 ) & V_1009 ) )
return false ;
return true ;
}
const char * F_665 ( int V_1010 )
{
static const char * V_1011 [] = {
[ V_1012 ] = L_251 ,
[ V_34 ] = L_252 ,
[ V_44 ] = L_253 ,
[ V_36 ] = L_254 ,
[ V_25 ] = L_255 ,
[ V_1013 ] = L_256 ,
[ V_33 ] = L_257 ,
[ V_375 ] = L_258 ,
[ V_307 ] = L_259 ,
[ V_215 ] = L_260 ,
[ V_431 ] = L_261 ,
} ;
if ( V_1010 < 0 || V_1010 >= F_215 ( V_1011 ) || ! V_1011 [ V_1010 ] )
return L_262 ;
return V_1011 [ V_1010 ] ;
}
static void F_666 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_23 ;
bool V_1014 = false ;
F_667 ( V_2 ) ;
if ( ! F_668 ( V_2 ) )
F_669 ( V_2 ) ;
if ( F_61 ( V_2 ) ) {
int V_59 ;
V_59 = F_4 ( V_1015 ) & V_1016 ;
if ( V_59 )
F_670 ( V_2 , V_432 ) ;
V_59 = F_4 ( V_1017 ) ;
if ( V_59 & V_1018 )
F_670 ( V_2 , V_90 ) ;
if ( V_59 & V_1019 )
F_670 ( V_2 , V_92 ) ;
if ( V_59 & V_1020 )
F_670 ( V_2 , V_94 ) ;
} else if ( F_3 ( V_2 ) ) {
int V_59 ;
V_1014 = F_671 ( V_2 , V_94 ) ;
if ( F_664 ( V_2 ) )
F_672 ( V_2 , V_1006 , V_432 ) ;
if ( F_4 ( V_179 ) & V_1021 ) {
V_59 = F_673 ( V_2 , V_1022 , true ) ;
if ( ! V_59 )
F_674 ( V_2 , V_179 , V_90 ) ;
if ( ! V_59 && ( F_4 ( V_172 ) & V_1007 ) )
F_672 ( V_2 , V_172 , V_90 ) ;
}
if ( F_4 ( V_180 ) & V_1021 )
F_674 ( V_2 , V_180 , V_92 ) ;
if ( ! V_1014 && F_4 ( V_181 ) & V_1021 )
F_674 ( V_2 , V_181 , V_94 ) ;
if ( F_4 ( V_174 ) & V_1007 )
F_672 ( V_2 , V_174 , V_92 ) ;
if ( F_4 ( V_176 ) & V_1007 )
F_672 ( V_2 , V_176 , V_94 ) ;
} else if ( F_17 ( V_2 ) ) {
if ( F_4 ( V_1023 + V_1024 ) & V_1021 ) {
F_674 ( V_2 , V_1023 + V_1024 ,
V_90 ) ;
if ( F_4 ( V_1023 + V_1025 ) & V_1007 )
F_672 ( V_2 , V_1023 + V_1025 , V_90 ) ;
}
if ( F_4 ( V_1023 + V_1026 ) & V_1021 ) {
F_674 ( V_2 , V_1023 + V_1026 ,
V_92 ) ;
if ( F_4 ( V_1023 + V_1027 ) & V_1007 )
F_672 ( V_2 , V_1023 + V_1027 , V_92 ) ;
}
F_675 ( V_2 ) ;
} else if ( F_676 ( V_2 ) ) {
bool V_59 = false ;
if ( F_4 ( V_1028 ) & V_1021 ) {
F_36 ( L_263 ) ;
V_59 = F_673 ( V_2 , V_1028 , true ) ;
if ( ! V_59 && F_677 ( V_2 ) ) {
F_36 ( L_264 ) ;
F_674 ( V_2 , V_1024 , V_90 ) ;
}
if ( ! V_59 && F_678 ( V_2 ) )
F_672 ( V_2 , V_1025 , V_90 ) ;
}
if ( F_4 ( V_1028 ) & V_1021 ) {
F_36 ( L_265 ) ;
V_59 = F_673 ( V_2 , V_1029 , false ) ;
}
if ( ! V_59 && ( F_4 ( V_1029 ) & V_1021 ) ) {
if ( F_677 ( V_2 ) ) {
F_36 ( L_266 ) ;
F_674 ( V_2 , V_1026 , V_92 ) ;
}
if ( F_678 ( V_2 ) )
F_672 ( V_2 , V_1027 , V_92 ) ;
}
if ( F_678 ( V_2 ) &&
( F_4 ( V_1030 ) & V_1007 ) )
F_672 ( V_2 , V_1030 , V_94 ) ;
} else if ( F_18 ( V_2 ) )
F_679 ( V_2 ) ;
if ( F_680 ( V_2 ) )
F_681 ( V_2 ) ;
F_172 (encoder, &dev->mode_config.encoder_list, base.head) {
V_23 -> V_109 . V_856 = V_23 -> V_1031 ;
V_23 -> V_109 . V_1032 =
F_663 ( V_23 ) ;
}
F_429 ( V_2 ) ;
F_682 ( V_2 ) ;
}
static void F_683 ( struct V_272 * V_67 )
{
struct V_271 * V_273 = F_168 ( V_67 ) ;
F_684 ( V_67 ) ;
F_2 ( ! V_273 -> V_223 -> V_1033 -- ) ;
F_518 ( & V_273 -> V_223 -> V_109 ) ;
F_171 ( V_273 ) ;
}
static int F_685 ( struct V_272 * V_67 ,
struct V_825 * V_826 ,
unsigned int * V_827 )
{
struct V_271 * V_273 = F_168 ( V_67 ) ;
struct V_222 * V_223 = V_273 -> V_223 ;
return F_686 ( V_826 , & V_223 -> V_109 , V_827 ) ;
}
static int F_167 ( struct V_1 * V_2 ,
struct V_271 * V_273 ,
struct V_261 * V_262 ,
struct V_222 * V_223 )
{
int V_654 ;
int V_1034 ;
int V_227 ;
F_2 ( ! F_658 ( & V_2 -> V_268 ) ) ;
if ( V_223 -> V_228 == V_231 ) {
F_513 ( L_267 ) ;
return - V_232 ;
}
if ( V_262 -> V_265 [ 0 ] & 63 ) {
F_513 ( L_268 ,
V_262 -> V_265 [ 0 ] ) ;
return - V_232 ;
}
if ( F_39 ( V_2 ) -> V_78 >= 5 && ! F_17 ( V_2 ) ) {
V_1034 = 32 * 1024 ;
} else if ( F_39 ( V_2 ) -> V_78 >= 4 ) {
if ( V_223 -> V_228 )
V_1034 = 16 * 1024 ;
else
V_1034 = 32 * 1024 ;
} else if ( F_39 ( V_2 ) -> V_78 >= 3 ) {
if ( V_223 -> V_228 )
V_1034 = 8 * 1024 ;
else
V_1034 = 16 * 1024 ;
} else
V_1034 = 8 * 1024 ;
if ( V_262 -> V_265 [ 0 ] > V_1034 ) {
F_513 ( L_269 ,
V_223 -> V_228 ? L_270 : L_271 ,
V_262 -> V_265 [ 0 ] , V_1034 ) ;
return - V_232 ;
}
if ( V_223 -> V_228 != V_229 &&
V_262 -> V_265 [ 0 ] != V_223 -> V_264 ) {
F_513 ( L_272 ,
V_262 -> V_265 [ 0 ] , V_223 -> V_264 ) ;
return - V_232 ;
}
switch ( V_262 -> V_266 ) {
case V_246 :
case V_250 :
case V_252 :
case V_278 :
break;
case V_248 :
case V_277 :
if ( F_39 ( V_2 ) -> V_78 > 3 ) {
F_513 ( L_273 ,
F_687 ( V_262 -> V_266 ) ) ;
return - V_232 ;
}
break;
case V_254 :
case V_279 :
case V_256 :
case V_280 :
case V_258 :
case V_281 :
if ( F_39 ( V_2 ) -> V_78 < 4 ) {
F_513 ( L_273 ,
F_687 ( V_262 -> V_266 ) ) ;
return - V_232 ;
}
break;
case V_1035 :
case V_1036 :
case V_1037 :
case V_1038 :
if ( F_39 ( V_2 ) -> V_78 < 5 ) {
F_513 ( L_273 ,
F_687 ( V_262 -> V_266 ) ) ;
return - V_232 ;
}
break;
default:
F_513 ( L_273 ,
F_687 ( V_262 -> V_266 ) ) ;
return - V_232 ;
}
if ( V_262 -> V_929 [ 0 ] != 0 )
return - V_232 ;
V_654 = F_152 ( V_2 , V_262 -> V_219 ,
V_223 -> V_228 ) ;
if ( V_223 -> V_109 . V_263 < V_654 * V_262 -> V_265 [ 0 ] )
return - V_232 ;
F_688 ( & V_273 -> V_109 , V_262 ) ;
V_273 -> V_223 = V_223 ;
V_273 -> V_223 -> V_1033 ++ ;
V_227 = F_689 ( V_2 , & V_273 -> V_109 , & V_1039 ) ;
if ( V_227 ) {
F_116 ( L_274 , V_227 ) ;
return V_227 ;
}
return 0 ;
}
static struct V_272 *
F_690 ( struct V_1 * V_2 ,
struct V_825 * V_1040 ,
struct V_261 * V_262 )
{
struct V_222 * V_223 ;
V_223 = F_514 ( F_515 ( V_2 , V_1040 ,
V_262 -> V_1041 [ 0 ] ) ) ;
if ( & V_223 -> V_109 == NULL )
return F_523 ( - V_831 ) ;
return F_524 ( V_2 , V_262 , V_223 ) ;
}
static inline void F_691 ( struct V_1 * V_2 )
{
}
static void F_692 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_3 ( V_2 ) || F_15 ( V_2 ) )
V_4 -> V_287 . V_644 = F_26 ;
else if ( F_17 ( V_2 ) )
V_4 -> V_287 . V_644 = F_27 ;
else if ( F_16 ( V_2 ) )
V_4 -> V_287 . V_644 = F_25 ;
else
V_4 -> V_287 . V_644 = F_24 ;
if ( F_61 ( V_2 ) ) {
V_4 -> V_287 . V_960 = F_479 ;
V_4 -> V_287 . V_1042 = F_460 ;
V_4 -> V_287 . V_770 = F_476 ;
V_4 -> V_287 . V_483 = F_284 ;
V_4 -> V_287 . V_484 = F_291 ;
V_4 -> V_287 . V_488 = F_296 ;
V_4 -> V_287 . V_289 =
F_179 ;
} else if ( F_3 ( V_2 ) ) {
V_4 -> V_287 . V_960 = F_461 ;
V_4 -> V_287 . V_1042 = F_460 ;
V_4 -> V_287 . V_770 = F_452 ;
V_4 -> V_287 . V_483 = F_272 ;
V_4 -> V_287 . V_484 = F_290 ;
V_4 -> V_287 . V_488 = F_295 ;
V_4 -> V_287 . V_289 =
F_179 ;
} else if ( F_17 ( V_2 ) ) {
V_4 -> V_287 . V_960 = F_420 ;
V_4 -> V_287 . V_1042 = F_417 ;
V_4 -> V_287 . V_770 = F_412 ;
V_4 -> V_287 . V_483 = F_329 ;
V_4 -> V_287 . V_484 = F_332 ;
V_4 -> V_287 . V_488 = F_333 ;
V_4 -> V_287 . V_289 =
F_175 ;
} else {
V_4 -> V_287 . V_960 = F_420 ;
V_4 -> V_287 . V_1042 = F_417 ;
V_4 -> V_287 . V_770 = F_412 ;
V_4 -> V_287 . V_483 = F_330 ;
V_4 -> V_287 . V_484 = F_332 ;
V_4 -> V_287 . V_488 = F_333 ;
V_4 -> V_287 . V_289 =
F_175 ;
}
if ( F_17 ( V_2 ) )
V_4 -> V_287 . V_506 =
F_356 ;
else if ( F_403 ( V_2 ) || ( F_405 ( V_2 ) && ! F_693 ( V_2 ) ) )
V_4 -> V_287 . V_506 =
F_357 ;
else if ( F_355 ( V_2 ) )
V_4 -> V_287 . V_506 =
F_358 ;
else if ( F_404 ( V_2 ) || F_71 ( V_2 ) )
V_4 -> V_287 . V_506 =
F_359 ;
else if ( F_16 ( V_2 ) )
V_4 -> V_287 . V_506 =
F_360 ;
else if ( F_694 ( V_2 ) )
V_4 -> V_287 . V_506 =
F_362 ;
else if ( F_72 ( V_2 ) )
V_4 -> V_287 . V_506 =
F_363 ;
else if ( F_695 ( V_2 ) )
V_4 -> V_287 . V_506 =
F_364 ;
else
V_4 -> V_287 . V_506 =
F_365 ;
if ( F_3 ( V_2 ) ) {
if ( F_6 ( V_2 ) ) {
V_4 -> V_287 . V_371 = F_205 ;
V_4 -> V_287 . V_803 = F_492 ;
} else if ( F_213 ( V_2 ) ) {
V_4 -> V_287 . V_371 = F_211 ;
V_4 -> V_287 . V_803 = F_492 ;
} else if ( F_202 ( V_2 ) ) {
V_4 -> V_287 . V_371 = F_214 ;
V_4 -> V_287 . V_803 = F_492 ;
V_4 -> V_287 . V_966 =
F_204 ;
} else if ( F_142 ( V_2 ) || F_696 ( V_2 ) ) {
V_4 -> V_287 . V_371 = V_1043 ;
V_4 -> V_287 . V_803 = F_488 ;
V_4 -> V_287 . V_966 =
F_475 ;
}
} else if ( F_15 ( V_2 ) ) {
V_4 -> V_287 . V_803 = F_487 ;
} else if ( F_17 ( V_2 ) ) {
V_4 -> V_287 . V_966 =
F_328 ;
V_4 -> V_287 . V_803 = F_492 ;
}
V_4 -> V_287 . V_934 = F_585 ;
switch ( F_39 ( V_2 ) -> V_78 ) {
case 2 :
V_4 -> V_287 . V_934 = F_572 ;
break;
case 3 :
V_4 -> V_287 . V_934 = F_577 ;
break;
case 4 :
case 5 :
V_4 -> V_287 . V_934 = F_578 ;
break;
case 6 :
V_4 -> V_287 . V_934 = F_579 ;
break;
case 7 :
case 8 :
V_4 -> V_287 . V_934 = F_580 ;
break;
}
F_697 ( V_2 ) ;
}
static void F_698 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_138 |= V_139 ;
F_699 ( L_275 ) ;
}
static void F_700 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_138 |= V_547 ;
F_699 ( L_276 ) ;
}
static void F_701 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_138 |= V_1044 ;
F_699 ( L_277 ) ;
}
static int F_702 ( const struct V_1045 * V_197 )
{
F_699 ( L_278 , V_197 -> V_1046 ) ;
return 1 ;
}
static void F_703 ( struct V_1 * V_2 )
{
struct V_1047 * V_1048 = V_2 -> V_510 ;
int V_143 ;
for ( V_143 = 0 ; V_143 < F_215 ( V_1049 ) ; V_143 ++ ) {
struct V_1050 * V_1051 = & V_1049 [ V_143 ] ;
if ( V_1048 -> V_1052 == V_1051 -> V_1052 &&
( V_1048 -> V_1053 == V_1051 -> V_1053 ||
V_1051 -> V_1053 == V_1054 ) &&
( V_1048 -> V_1055 == V_1051 -> V_1055 ||
V_1051 -> V_1055 == V_1054 ) )
V_1051 -> V_1056 ( V_2 ) ;
}
for ( V_143 = 0 ; V_143 < F_215 ( V_1057 ) ; V_143 ++ ) {
if ( F_704 ( * V_1057 [ V_143 ] . V_1058 ) != 0 )
V_1057 [ V_143 ] . V_1056 ( V_2 ) ;
}
}
static void F_705 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_10 V_1059 ;
T_1 V_1060 = F_706 ( V_2 ) ;
F_707 ( V_2 -> V_510 , V_1061 ) ;
F_708 ( V_1062 , V_1063 ) ;
V_1059 = F_709 ( V_1064 ) ;
F_708 ( V_1059 | 1 << 5 , V_1064 ) ;
F_710 ( V_2 -> V_510 , V_1061 ) ;
F_115 ( 300 ) ;
F_40 ( V_1060 , V_1065 ) ;
F_114 ( V_1060 ) ;
}
void F_711 ( struct V_1 * V_2 )
{
F_472 ( V_2 ) ;
F_712 ( V_2 ) ;
F_108 ( V_2 ) ;
F_53 ( & V_2 -> V_268 ) ;
F_713 ( V_2 ) ;
F_55 ( & V_2 -> V_268 ) ;
}
void F_714 ( struct V_1 * V_2 )
{
F_715 ( V_2 ) ;
}
void F_716 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_147 , V_227 ;
enum V_72 V_72 ;
struct V_64 * V_21 ;
F_717 ( V_2 ) ;
V_2 -> V_660 . V_1066 = 0 ;
V_2 -> V_660 . V_1067 = 0 ;
V_2 -> V_660 . V_1068 = 24 ;
V_2 -> V_660 . V_1069 = 1 ;
V_2 -> V_660 . V_753 = & V_1070 ;
F_703 ( V_2 ) ;
F_718 ( V_2 ) ;
if ( F_39 ( V_2 ) -> V_300 == 0 )
return;
F_692 ( V_2 ) ;
if ( F_18 ( V_2 ) ) {
V_2 -> V_660 . V_1071 = 2048 ;
V_2 -> V_660 . V_1072 = 2048 ;
} else if ( F_719 ( V_2 ) ) {
V_2 -> V_660 . V_1071 = 4096 ;
V_2 -> V_660 . V_1072 = 4096 ;
} else {
V_2 -> V_660 . V_1071 = 8192 ;
V_2 -> V_660 . V_1072 = 8192 ;
}
V_2 -> V_660 . V_1073 = V_4 -> V_1074 . V_1075 ;
F_36 ( L_279 ,
F_39 ( V_2 ) -> V_300 ,
F_39 ( V_2 ) -> V_300 > 1 ? L_280 : L_281 ) ;
F_82 (pipe) {
F_652 ( V_2 , V_72 ) ;
F_84 (pipe, sprite) {
V_227 = F_720 ( V_2 , V_72 , V_147 ) ;
if ( V_227 )
F_36 ( L_282 ,
F_69 ( V_72 ) , F_86 ( V_72 , V_147 ) , V_227 ) ;
}
}
F_106 ( V_2 ) ;
F_108 ( V_2 ) ;
F_641 ( V_2 ) ;
F_651 ( V_2 ) ;
F_705 ( V_2 ) ;
F_666 ( V_2 ) ;
F_282 ( V_2 ) ;
F_53 ( & V_2 -> V_660 . V_290 ) ;
F_721 ( V_2 , false ) ;
F_55 ( & V_2 -> V_660 . V_290 ) ;
F_172 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( ! V_21 -> V_65 )
continue;
if ( V_4 -> V_287 . V_1042 ) {
V_4 -> V_287 . V_1042 ( V_21 ,
& V_21 -> V_260 ) ;
F_170 ( V_21 , & V_21 -> V_260 ) ;
}
}
}
static void F_722 ( struct V_1 * V_2 )
{
struct V_493 * V_486 ;
struct V_485 * V_1076 = NULL ;
struct V_851 V_855 ;
F_172 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_486 -> V_23 -> type == V_34 ) {
V_1076 = & V_486 -> V_109 ;
break;
}
}
if ( ! V_1076 )
return;
if ( F_533 ( V_1076 , NULL , & V_855 ) )
F_537 ( V_1076 , & V_855 ) ;
}
static bool
F_723 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_80 , V_102 ;
if ( F_39 ( V_2 ) -> V_300 == 1 )
return true ;
V_80 = F_79 ( ! V_21 -> V_141 ) ;
V_102 = F_4 ( V_80 ) ;
if ( ( V_102 & V_142 ) &&
( ! ! ( V_102 & V_145 ) == V_21 -> V_72 ) )
return false ;
return true ;
}
static void F_724 ( struct V_64 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_109 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_80 ;
V_80 = F_45 ( V_21 -> V_68 . V_74 ) ;
F_40 ( V_80 , F_4 ( V_80 ) & ~ V_1077 ) ;
if ( F_39 ( V_2 ) -> V_78 < 4 && ! F_723 ( V_21 ) ) {
struct V_493 * V_486 ;
bool V_141 ;
F_36 ( L_283 ,
V_21 -> V_109 . V_109 . V_197 ) ;
V_141 = V_21 -> V_141 ;
V_21 -> V_141 = ! V_141 ;
V_4 -> V_287 . V_484 ( & V_21 -> V_109 ) ;
V_21 -> V_141 = V_141 ;
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_486 -> V_23 -> V_109 . V_21 != & V_21 -> V_109 )
continue;
V_486 -> V_109 . V_489 = V_490 ;
V_486 -> V_109 . V_23 = NULL ;
}
F_172 (connector, &dev->mode_config.connector_list,
base.head)
if ( V_486 -> V_23 -> V_109 . V_21 == & V_21 -> V_109 ) {
V_486 -> V_23 -> V_109 . V_21 = NULL ;
V_486 -> V_23 -> V_482 = false ;
}
F_2 ( V_21 -> V_65 ) ;
V_21 -> V_109 . V_100 = false ;
}
if ( V_4 -> V_138 & V_139 &&
V_21 -> V_72 == V_125 && ! V_21 -> V_65 ) {
F_722 ( V_2 ) ;
}
F_335 ( & V_21 -> V_109 ) ;
if ( V_21 -> V_65 != V_21 -> V_109 . V_100 ) {
struct V_22 * V_23 ;
F_36 ( L_284 ,
V_21 -> V_109 . V_109 . V_197 ,
V_21 -> V_109 . V_100 ? L_194 : L_195 ,
V_21 -> V_65 ? L_194 : L_195 ) ;
V_21 -> V_109 . V_100 = V_21 -> V_65 ;
F_2 ( V_21 -> V_65 ) ;
F_10 (dev, &crtc->base, encoder) {
F_2 ( V_23 -> V_482 ) ;
V_23 -> V_109 . V_21 = NULL ;
}
}
if ( V_21 -> V_65 ) {
V_21 -> V_1078 = true ;
V_21 -> V_1079 = true ;
}
}
static void F_725 ( struct V_22 * V_23 )
{
struct V_493 * V_486 ;
struct V_1 * V_2 = V_23 -> V_109 . V_2 ;
bool V_1080 = V_23 -> V_109 . V_21 &&
F_30 ( V_23 -> V_109 . V_21 ) -> V_65 ;
if ( V_23 -> V_482 && ! V_1080 ) {
F_36 ( L_285 ,
V_23 -> V_109 . V_109 . V_197 ,
F_484 ( & V_23 -> V_109 ) ) ;
if ( V_23 -> V_109 . V_21 ) {
F_36 ( L_286 ,
V_23 -> V_109 . V_109 . V_197 ,
F_484 ( & V_23 -> V_109 ) ) ;
V_23 -> V_199 ( V_23 ) ;
}
V_23 -> V_109 . V_21 = NULL ;
V_23 -> V_482 = false ;
F_172 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_486 -> V_23 != V_23 )
continue;
V_486 -> V_109 . V_489 = V_490 ;
V_486 -> V_109 . V_23 = NULL ;
}
}
}
void F_726 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_1060 = F_706 ( V_2 ) ;
if ( ! ( F_4 ( V_1060 ) & V_1065 ) ) {
F_36 ( L_287 ) ;
F_705 ( V_2 ) ;
}
}
void F_727 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_76 ( V_4 , V_1081 ) )
return;
F_726 ( V_2 ) ;
}
static void F_728 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_72 V_72 ;
struct V_64 * V_21 ;
struct V_22 * V_23 ;
struct V_493 * V_486 ;
int V_143 ;
F_172 (crtc, &dev->mode_config.crtc_list,
base.head) {
memset ( & V_21 -> V_68 , 0 , sizeof( V_21 -> V_68 ) ) ;
V_21 -> V_68 . V_138 |= V_958 ;
V_21 -> V_65 = V_4 -> V_287 . V_960 ( V_21 ,
& V_21 -> V_68 ) ;
V_21 -> V_109 . V_100 = V_21 -> V_65 ;
V_21 -> V_217 = V_21 -> V_65 ;
F_36 ( L_288 ,
V_21 -> V_109 . V_109 . V_197 ,
V_21 -> V_65 ? L_194 : L_195 ) ;
}
if ( F_61 ( V_2 ) )
F_729 ( V_2 ) ;
for ( V_143 = 0 ; V_143 < V_4 -> V_388 ; V_143 ++ ) {
struct V_108 * V_112 = & V_4 -> V_111 [ V_143 ] ;
V_112 -> V_196 = V_112 -> V_115 ( V_4 , V_112 , & V_112 -> V_114 ) ;
V_112 -> V_65 = 0 ;
F_172 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_21 -> V_65 && F_56 ( V_21 ) == V_112 )
V_112 -> V_65 ++ ;
}
V_112 -> V_195 = V_112 -> V_65 ;
F_36 ( L_289 ,
V_112 -> V_116 , V_112 -> V_195 , V_112 -> V_196 ) ;
}
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_72 = 0 ;
if ( V_23 -> V_115 ( V_23 , & V_72 ) ) {
V_21 = F_30 ( V_4 -> V_73 [ V_72 ] ) ;
V_23 -> V_109 . V_21 = & V_21 -> V_109 ;
V_23 -> V_961 ( V_23 , & V_21 -> V_68 ) ;
} else {
V_23 -> V_109 . V_21 = NULL ;
}
V_23 -> V_482 = false ;
F_36 ( L_290 ,
V_23 -> V_109 . V_109 . V_197 ,
F_484 ( & V_23 -> V_109 ) ,
V_23 -> V_109 . V_21 ? L_194 : L_195 ,
F_69 ( V_72 ) ) ;
}
F_172 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_486 -> V_115 ( V_486 ) ) {
V_486 -> V_109 . V_489 = V_492 ;
V_486 -> V_23 -> V_482 = true ;
V_486 -> V_109 . V_23 = & V_486 -> V_23 -> V_109 ;
} else {
V_486 -> V_109 . V_489 = V_490 ;
V_486 -> V_109 . V_23 = NULL ;
}
F_36 ( L_291 ,
V_486 -> V_109 . V_109 . V_197 ,
F_343 ( & V_486 -> V_109 ) ,
V_486 -> V_109 . V_23 ? L_194 : L_195 ) ;
}
}
void F_721 ( struct V_1 * V_2 ,
bool V_1082 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_72 V_72 ;
struct V_64 * V_21 ;
struct V_22 * V_23 ;
int V_143 ;
F_728 ( V_2 ) ;
F_172 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_21 -> V_65 && V_301 . V_302 ) {
F_409 ( & V_21 -> V_109 . V_381 , & V_21 -> V_68 ) ;
F_36 ( L_292 ,
V_21 -> V_109 . V_109 . V_197 ) ;
F_601 ( & V_21 -> V_109 . V_381 ) ;
}
}
F_172 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_725 ( V_23 ) ;
}
F_82 (pipe) {
V_21 = F_30 ( V_4 -> V_73 [ V_72 ] ) ;
F_724 ( V_21 ) ;
F_599 ( V_21 , & V_21 -> V_68 , L_293 ) ;
}
for ( V_143 = 0 ; V_143 < V_4 -> V_388 ; V_143 ++ ) {
struct V_108 * V_112 = & V_4 -> V_111 [ V_143 ] ;
if ( ! V_112 -> V_196 || V_112 -> V_65 )
continue;
F_36 ( L_294 , V_112 -> V_116 ) ;
V_112 -> V_199 ( V_4 , V_112 ) ;
V_112 -> V_196 = false ;
}
if ( F_3 ( V_2 ) )
F_730 ( V_2 ) ;
if ( V_1082 ) {
F_727 ( V_2 ) ;
F_82 (pipe) {
struct V_20 * V_21 =
V_4 -> V_73 [ V_72 ] ;
F_624 ( V_21 , & V_21 -> V_381 , V_21 -> V_237 , V_21 -> V_238 ,
V_21 -> V_66 -> V_67 ) ;
}
} else {
F_594 ( V_2 ) ;
}
F_345 ( V_2 ) ;
}
void F_731 ( struct V_1 * V_2 )
{
struct V_20 * V_270 ;
struct V_271 * V_67 ;
F_53 ( & V_2 -> V_268 ) ;
F_732 ( V_2 ) ;
F_55 ( & V_2 -> V_268 ) ;
F_711 ( V_2 ) ;
F_733 ( V_2 ) ;
F_53 ( & V_2 -> V_268 ) ;
F_172 (c, &dev->mode_config.crtc_list, head) {
if ( ! V_270 -> V_66 -> V_67 )
continue;
V_67 = F_168 ( V_270 -> V_66 -> V_67 ) ;
if ( F_154 ( V_2 , V_67 -> V_223 , NULL ) ) {
F_116 ( L_295 ,
F_30 ( V_270 ) -> V_72 ) ;
F_539 ( V_270 -> V_66 -> V_67 ) ;
V_270 -> V_66 -> V_67 = NULL ;
}
}
F_55 ( & V_2 -> V_268 ) ;
}
void F_734 ( struct V_493 * V_493 )
{
struct V_485 * V_486 = & V_493 -> V_109 ;
F_735 ( V_486 ) ;
F_736 ( V_486 ) ;
}
void F_737 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_485 * V_486 ;
F_738 ( V_2 ) ;
F_555 ( & V_4 -> V_1083 ) ;
F_739 ( V_2 ) ;
F_53 ( & V_2 -> V_268 ) ;
F_740 () ;
F_172 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_21 -> V_66 -> V_67 )
continue;
F_183 ( V_21 ) ;
}
F_282 ( V_2 ) ;
F_741 ( V_2 ) ;
F_742 ( V_2 ) ;
F_55 ( & V_2 -> V_268 ) ;
F_743 () ;
F_172 (connector, &dev->mode_config.connector_list, head) {
struct V_493 * V_493 ;
V_493 = F_534 ( V_486 ) ;
V_493 -> V_1084 ( V_493 ) ;
}
F_744 ( V_2 ) ;
F_745 ( V_2 ) ;
F_53 ( & V_2 -> V_268 ) ;
F_746 ( V_2 ) ;
F_55 ( & V_2 -> V_268 ) ;
}
struct V_491 * F_747 ( struct V_485 * V_486 )
{
return & F_502 ( V_486 ) -> V_109 ;
}
void F_748 ( struct V_493 * V_486 ,
struct V_22 * V_23 )
{
V_486 -> V_23 = V_23 ;
F_749 ( & V_486 -> V_109 ,
& V_23 -> V_109 ) ;
}
int F_750 ( struct V_1 * V_2 , bool V_101 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned V_80 = F_39 ( V_2 ) -> V_78 >= 6 ? V_1085 : V_1086 ;
T_5 V_1087 ;
if ( F_361 ( V_4 -> V_1088 , V_80 , & V_1087 ) ) {
F_116 ( L_296 ) ;
return - V_936 ;
}
if ( ! ! ( V_1087 & V_1089 ) == ! V_101 )
return 0 ;
if ( V_101 )
V_1087 &= ~ V_1089 ;
else
V_1087 |= V_1089 ;
if ( F_751 ( V_4 -> V_1088 , V_80 , V_1087 ) ) {
F_116 ( L_297 ) ;
return - V_936 ;
}
return 0 ;
}
struct V_1090 *
F_752 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_1090 * error ;
int V_1091 [] = {
V_210 ,
V_1092 ,
V_1093 ,
V_617 ,
} ;
int V_143 ;
if ( F_39 ( V_2 ) -> V_300 == 0 )
return NULL ;
error = F_418 ( sizeof( * error ) , V_1094 ) ;
if ( error == NULL )
return NULL ;
if ( F_142 ( V_2 ) || F_180 ( V_2 ) )
error -> V_1095 = F_4 ( V_718 ) ;
F_82 (i) {
error -> V_72 [ V_143 ] . V_1096 =
F_753 ( V_4 ,
F_309 ( V_143 ) ) ;
if ( ! error -> V_72 [ V_143 ] . V_1096 )
continue;
if ( F_39 ( V_2 ) -> V_78 <= 6 || F_17 ( V_2 ) ) {
error -> V_1097 [ V_143 ] . V_424 = F_4 ( F_73 ( V_143 ) ) ;
error -> V_1097 [ V_143 ] . V_1098 = F_4 ( F_511 ( V_143 ) ) ;
error -> V_1097 [ V_143 ] . V_109 = F_4 ( F_301 ( V_143 ) ) ;
} else {
error -> V_1097 [ V_143 ] . V_424 = F_4 ( F_74 ( V_143 ) ) ;
error -> V_1097 [ V_143 ] . V_1098 = F_4 ( F_510 ( V_143 ) ) ;
error -> V_1097 [ V_143 ] . V_109 = F_4 ( F_509 ( V_143 ) ) ;
}
error -> V_141 [ V_143 ] . V_424 = F_4 ( F_79 ( V_143 ) ) ;
error -> V_141 [ V_143 ] . V_264 = F_4 ( F_176 ( V_143 ) ) ;
if ( F_39 ( V_2 ) -> V_78 <= 3 ) {
error -> V_141 [ V_143 ] . V_263 = F_4 ( F_413 ( V_143 ) ) ;
error -> V_141 [ V_143 ] . V_393 = F_4 ( F_414 ( V_143 ) ) ;
}
if ( F_39 ( V_2 ) -> V_78 <= 7 && ! F_142 ( V_2 ) )
error -> V_141 [ V_143 ] . V_829 = F_4 ( F_146 ( V_143 ) ) ;
if ( F_39 ( V_2 ) -> V_78 >= 4 ) {
error -> V_141 [ V_143 ] . V_1099 = F_4 ( F_145 ( V_143 ) ) ;
error -> V_141 [ V_143 ] . V_1100 = F_4 ( F_177 ( V_143 ) ) ;
}
error -> V_72 [ V_143 ] . V_1101 = F_4 ( F_195 ( V_143 ) ) ;
}
error -> V_1102 = F_39 ( V_2 ) -> V_300 ;
if ( F_61 ( V_4 -> V_2 ) )
error -> V_1102 ++ ;
for ( V_143 = 0 ; V_143 < error -> V_1102 ; V_143 ++ ) {
enum V_71 V_74 = V_1091 [ V_143 ] ;
error -> V_71 [ V_143 ] . V_1096 =
F_753 ( V_4 ,
F_77 ( V_74 ) ) ;
if ( ! error -> V_71 [ V_143 ] . V_1096 )
continue;
error -> V_71 [ V_143 ] . V_74 = V_74 ;
error -> V_71 [ V_143 ] . V_1103 = F_4 ( F_45 ( V_74 ) ) ;
error -> V_71 [ V_143 ] . V_620 = F_4 ( F_232 ( V_74 ) ) ;
error -> V_71 [ V_143 ] . V_1104 = F_4 ( F_234 ( V_74 ) ) ;
error -> V_71 [ V_143 ] . V_882 = F_4 ( F_236 ( V_74 ) ) ;
error -> V_71 [ V_143 ] . V_622 = F_4 ( F_238 ( V_74 ) ) ;
error -> V_71 [ V_143 ] . V_1105 = F_4 ( F_240 ( V_74 ) ) ;
error -> V_71 [ V_143 ] . V_884 = F_4 ( F_242 ( V_74 ) ) ;
}
return error ;
}
void
F_754 ( struct V_1106 * V_11 ,
struct V_1 * V_2 ,
struct V_1090 * error )
{
int V_143 ;
if ( ! error )
return;
F_755 ( V_11 , L_298 , F_39 ( V_2 ) -> V_300 ) ;
if ( F_142 ( V_2 ) || F_180 ( V_2 ) )
F_755 ( V_11 , L_299 ,
error -> V_1095 ) ;
F_82 (i) {
F_755 ( V_11 , L_300 , V_143 ) ;
F_755 ( V_11 , L_301 ,
error -> V_72 [ V_143 ] . V_1096 ? L_12 : L_13 ) ;
F_755 ( V_11 , L_302 , error -> V_72 [ V_143 ] . V_1101 ) ;
F_755 ( V_11 , L_303 , V_143 ) ;
F_755 ( V_11 , L_304 , error -> V_141 [ V_143 ] . V_424 ) ;
F_755 ( V_11 , L_305 , error -> V_141 [ V_143 ] . V_264 ) ;
if ( F_39 ( V_2 ) -> V_78 <= 3 ) {
F_755 ( V_11 , L_306 , error -> V_141 [ V_143 ] . V_263 ) ;
F_755 ( V_11 , L_307 , error -> V_141 [ V_143 ] . V_393 ) ;
}
if ( F_39 ( V_2 ) -> V_78 <= 7 && ! F_142 ( V_2 ) )
F_755 ( V_11 , L_308 , error -> V_141 [ V_143 ] . V_829 ) ;
if ( F_39 ( V_2 ) -> V_78 >= 4 ) {
F_755 ( V_11 , L_309 , error -> V_141 [ V_143 ] . V_1099 ) ;
F_755 ( V_11 , L_310 , error -> V_141 [ V_143 ] . V_1100 ) ;
}
F_755 ( V_11 , L_311 , V_143 ) ;
F_755 ( V_11 , L_304 , error -> V_1097 [ V_143 ] . V_424 ) ;
F_755 ( V_11 , L_307 , error -> V_1097 [ V_143 ] . V_1098 ) ;
F_755 ( V_11 , L_312 , error -> V_1097 [ V_143 ] . V_109 ) ;
}
for ( V_143 = 0 ; V_143 < error -> V_1102 ; V_143 ++ ) {
F_755 ( V_11 , L_313 ,
F_600 ( error -> V_71 [ V_143 ] . V_74 ) ) ;
F_755 ( V_11 , L_301 ,
error -> V_71 [ V_143 ] . V_1096 ? L_12 : L_13 ) ;
F_755 ( V_11 , L_314 , error -> V_71 [ V_143 ] . V_1103 ) ;
F_755 ( V_11 , L_315 , error -> V_71 [ V_143 ] . V_620 ) ;
F_755 ( V_11 , L_316 , error -> V_71 [ V_143 ] . V_1104 ) ;
F_755 ( V_11 , L_317 , error -> V_71 [ V_143 ] . V_882 ) ;
F_755 ( V_11 , L_318 , error -> V_71 [ V_143 ] . V_622 ) ;
F_755 ( V_11 , L_319 , error -> V_71 [ V_143 ] . V_1105 ) ;
F_755 ( V_11 , L_320 , error -> V_71 [ V_143 ] . V_884 ) ;
}
}
