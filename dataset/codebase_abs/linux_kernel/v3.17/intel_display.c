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
static bool F_10 ( struct V_28 * V_29 , int type )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_6 ;
F_11 (dev, crtc, encoder)
if ( V_6 -> type == type )
return true ;
return false ;
}
static const T_3 * F_12 ( struct V_28 * V_29 ,
int V_18 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
const T_3 * V_30 ;
if ( F_10 ( V_29 , V_31 ) ) {
if ( F_13 ( V_10 ) ) {
if ( V_18 == 100000 )
V_30 = & V_32 ;
else
V_30 = & V_33 ;
} else {
if ( V_18 == 100000 )
V_30 = & V_34 ;
else
V_30 = & V_35 ;
}
} else
V_30 = & V_36 ;
return V_30 ;
}
static const T_3 * F_14 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
const T_3 * V_30 ;
if ( F_10 ( V_29 , V_31 ) ) {
if ( F_13 ( V_10 ) )
V_30 = & V_37 ;
else
V_30 = & V_38 ;
} else if ( F_10 ( V_29 , V_39 ) ||
F_10 ( V_29 , V_40 ) ) {
V_30 = & V_41 ;
} else if ( F_10 ( V_29 , V_42 ) ) {
V_30 = & V_43 ;
} else
V_30 = & V_44 ;
return V_30 ;
}
static const T_3 * F_15 ( struct V_28 * V_29 , int V_18 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
const T_3 * V_30 ;
if ( F_4 ( V_10 ) )
V_30 = F_12 ( V_29 , V_18 ) ;
else if ( F_16 ( V_10 ) ) {
V_30 = F_14 ( V_29 ) ;
} else if ( F_17 ( V_10 ) ) {
if ( F_10 ( V_29 , V_31 ) )
V_30 = & V_45 ;
else
V_30 = & V_46 ;
} else if ( F_18 ( V_10 ) ) {
V_30 = & V_47 ;
} else if ( F_19 ( V_10 ) ) {
V_30 = & V_48 ;
} else if ( ! F_20 ( V_10 ) ) {
if ( F_10 ( V_29 , V_31 ) )
V_30 = & V_49 ;
else
V_30 = & V_44 ;
} else {
if ( F_10 ( V_29 , V_31 ) )
V_30 = & V_50 ;
else if ( F_10 ( V_29 , V_51 ) )
V_30 = & V_52 ;
else
V_30 = & V_53 ;
}
return V_30 ;
}
static void F_21 ( int V_18 , T_2 * clock )
{
clock -> V_19 = clock -> V_21 + 2 ;
clock -> V_22 = clock -> V_23 * clock -> V_24 ;
if ( F_3 ( clock -> V_25 == 0 || clock -> V_22 == 0 ) )
return;
clock -> V_26 = F_9 ( V_18 * clock -> V_19 , clock -> V_25 ) ;
clock -> V_27 = F_9 ( clock -> V_26 , clock -> V_22 ) ;
}
static T_4 F_22 ( struct V_54 * V_54 )
{
return 5 * ( V_54 -> V_20 + 2 ) + ( V_54 -> V_21 + 2 ) ;
}
static void F_23 ( int V_18 , T_2 * clock )
{
clock -> V_19 = F_22 ( clock ) ;
clock -> V_22 = clock -> V_23 * clock -> V_24 ;
if ( F_3 ( clock -> V_25 + 2 == 0 || clock -> V_22 == 0 ) )
return;
clock -> V_26 = F_9 ( V_18 * clock -> V_19 , clock -> V_25 + 2 ) ;
clock -> V_27 = F_9 ( clock -> V_26 , clock -> V_22 ) ;
}
static void F_24 ( int V_18 , T_2 * clock )
{
clock -> V_19 = clock -> V_20 * clock -> V_21 ;
clock -> V_22 = clock -> V_23 * clock -> V_24 ;
if ( F_3 ( clock -> V_25 == 0 || clock -> V_22 == 0 ) )
return;
clock -> V_26 = F_25 ( ( V_55 ) V_18 * clock -> V_19 ,
clock -> V_25 << 22 ) ;
clock -> V_27 = F_9 ( clock -> V_26 , clock -> V_22 ) ;
}
static bool F_26 ( struct V_9 * V_10 ,
const T_3 * V_30 ,
const T_2 * clock )
{
if ( clock -> V_25 < V_30 -> V_25 . V_56 || V_30 -> V_25 . V_57 < clock -> V_25 )
F_27 ( L_1 ) ;
if ( clock -> V_23 < V_30 -> V_23 . V_56 || V_30 -> V_23 . V_57 < clock -> V_23 )
F_27 ( L_2 ) ;
if ( clock -> V_21 < V_30 -> V_21 . V_56 || V_30 -> V_21 . V_57 < clock -> V_21 )
F_27 ( L_3 ) ;
if ( clock -> V_20 < V_30 -> V_20 . V_56 || V_30 -> V_20 . V_57 < clock -> V_20 )
F_27 ( L_4 ) ;
if ( ! F_17 ( V_10 ) && ! F_19 ( V_10 ) )
if ( clock -> V_20 <= clock -> V_21 )
F_27 ( L_5 ) ;
if ( ! F_19 ( V_10 ) ) {
if ( clock -> V_22 < V_30 -> V_22 . V_56 || V_30 -> V_22 . V_57 < clock -> V_22 )
F_27 ( L_6 ) ;
if ( clock -> V_19 < V_30 -> V_19 . V_56 || V_30 -> V_19 . V_57 < clock -> V_19 )
F_27 ( L_7 ) ;
}
if ( clock -> V_26 < V_30 -> V_26 . V_56 || V_30 -> V_26 . V_57 < clock -> V_26 )
F_27 ( L_8 ) ;
if ( clock -> V_27 < V_30 -> V_27 . V_56 || V_30 -> V_27 . V_57 < clock -> V_27 )
F_27 ( L_9 ) ;
return true ;
}
static bool
F_28 ( const T_3 * V_30 , struct V_28 * V_29 ,
int V_58 , int V_18 , T_2 * V_59 ,
T_2 * V_60 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
T_2 clock ;
int V_61 = V_58 ;
if ( F_10 ( V_29 , V_31 ) ) {
if ( F_13 ( V_10 ) )
clock . V_24 = V_30 -> V_24 . V_62 ;
else
clock . V_24 = V_30 -> V_24 . V_63 ;
} else {
if ( V_58 < V_30 -> V_24 . V_64 )
clock . V_24 = V_30 -> V_24 . V_63 ;
else
clock . V_24 = V_30 -> V_24 . V_62 ;
}
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
for ( clock . V_20 = V_30 -> V_20 . V_56 ; clock . V_20 <= V_30 -> V_20 . V_57 ;
clock . V_20 ++ ) {
for ( clock . V_21 = V_30 -> V_21 . V_56 ;
clock . V_21 <= V_30 -> V_21 . V_57 ; clock . V_21 ++ ) {
if ( clock . V_21 >= clock . V_20 )
break;
for ( clock . V_25 = V_30 -> V_25 . V_56 ;
clock . V_25 <= V_30 -> V_25 . V_57 ; clock . V_25 ++ ) {
for ( clock . V_23 = V_30 -> V_23 . V_56 ;
clock . V_23 <= V_30 -> V_23 . V_57 ; clock . V_23 ++ ) {
int V_65 ;
F_23 ( V_18 , & clock ) ;
if ( ! F_26 ( V_10 , V_30 ,
& clock ) )
continue;
if ( V_59 &&
clock . V_22 != V_59 -> V_22 )
continue;
V_65 = abs ( clock . V_27 - V_58 ) ;
if ( V_65 < V_61 ) {
* V_60 = clock ;
V_61 = V_65 ;
}
}
}
}
}
return ( V_61 != V_58 ) ;
}
static bool
F_29 ( const T_3 * V_30 , struct V_28 * V_29 ,
int V_58 , int V_18 , T_2 * V_59 ,
T_2 * V_60 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
T_2 clock ;
int V_61 = V_58 ;
if ( F_10 ( V_29 , V_31 ) ) {
if ( F_13 ( V_10 ) )
clock . V_24 = V_30 -> V_24 . V_62 ;
else
clock . V_24 = V_30 -> V_24 . V_63 ;
} else {
if ( V_58 < V_30 -> V_24 . V_64 )
clock . V_24 = V_30 -> V_24 . V_63 ;
else
clock . V_24 = V_30 -> V_24 . V_62 ;
}
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
for ( clock . V_20 = V_30 -> V_20 . V_56 ; clock . V_20 <= V_30 -> V_20 . V_57 ;
clock . V_20 ++ ) {
for ( clock . V_21 = V_30 -> V_21 . V_56 ;
clock . V_21 <= V_30 -> V_21 . V_57 ; clock . V_21 ++ ) {
for ( clock . V_25 = V_30 -> V_25 . V_56 ;
clock . V_25 <= V_30 -> V_25 . V_57 ; clock . V_25 ++ ) {
for ( clock . V_23 = V_30 -> V_23 . V_56 ;
clock . V_23 <= V_30 -> V_23 . V_57 ; clock . V_23 ++ ) {
int V_65 ;
F_21 ( V_18 , & clock ) ;
if ( ! F_26 ( V_10 , V_30 ,
& clock ) )
continue;
if ( V_59 &&
clock . V_22 != V_59 -> V_22 )
continue;
V_65 = abs ( clock . V_27 - V_58 ) ;
if ( V_65 < V_61 ) {
* V_60 = clock ;
V_61 = V_65 ;
}
}
}
}
}
return ( V_61 != V_58 ) ;
}
static bool
F_30 ( const T_3 * V_30 , struct V_28 * V_29 ,
int V_58 , int V_18 , T_2 * V_59 ,
T_2 * V_60 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
T_2 clock ;
int V_66 ;
bool V_67 ;
int V_68 = ( V_58 >> 8 ) + ( V_58 >> 9 ) ;
V_67 = false ;
if ( F_10 ( V_29 , V_31 ) ) {
if ( F_13 ( V_10 ) )
clock . V_24 = V_30 -> V_24 . V_62 ;
else
clock . V_24 = V_30 -> V_24 . V_63 ;
} else {
if ( V_58 < V_30 -> V_24 . V_64 )
clock . V_24 = V_30 -> V_24 . V_63 ;
else
clock . V_24 = V_30 -> V_24 . V_62 ;
}
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_66 = V_30 -> V_25 . V_57 ;
for ( clock . V_25 = V_30 -> V_25 . V_56 ; clock . V_25 <= V_66 ; clock . V_25 ++ ) {
for ( clock . V_20 = V_30 -> V_20 . V_57 ;
clock . V_20 >= V_30 -> V_20 . V_56 ; clock . V_20 -- ) {
for ( clock . V_21 = V_30 -> V_21 . V_57 ;
clock . V_21 >= V_30 -> V_21 . V_56 ; clock . V_21 -- ) {
for ( clock . V_23 = V_30 -> V_23 . V_57 ;
clock . V_23 >= V_30 -> V_23 . V_56 ; clock . V_23 -- ) {
int V_65 ;
F_23 ( V_18 , & clock ) ;
if ( ! F_26 ( V_10 , V_30 ,
& clock ) )
continue;
V_65 = abs ( clock . V_27 - V_58 ) ;
if ( V_65 < V_68 ) {
* V_60 = clock ;
V_68 = V_65 ;
V_66 = clock . V_25 ;
V_67 = true ;
}
}
}
}
}
return V_67 ;
}
static bool
F_31 ( const T_3 * V_30 , struct V_28 * V_29 ,
int V_58 , int V_18 , T_2 * V_59 ,
T_2 * V_60 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
T_2 clock ;
unsigned int V_69 = 1000000 ;
int V_66 = V_56 ( V_30 -> V_25 . V_57 , V_18 / 19200 ) ;
bool V_67 = false ;
V_58 *= 5 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
for ( clock . V_25 = V_30 -> V_25 . V_56 ; clock . V_25 <= V_66 ; clock . V_25 ++ ) {
for ( clock . V_23 = V_30 -> V_23 . V_57 ; clock . V_23 >= V_30 -> V_23 . V_56 ; clock . V_23 -- ) {
for ( clock . V_24 = V_30 -> V_24 . V_62 ; clock . V_24 >= V_30 -> V_24 . V_63 ;
clock . V_24 -= clock . V_24 > 10 ? 2 : 1 ) {
clock . V_22 = clock . V_23 * clock . V_24 ;
for ( clock . V_20 = V_30 -> V_20 . V_56 ; clock . V_20 <= V_30 -> V_20 . V_57 ; clock . V_20 ++ ) {
unsigned int V_70 , V_71 ;
clock . V_21 = F_9 ( V_58 * clock . V_22 * clock . V_25 ,
V_18 * clock . V_20 ) ;
F_8 ( V_18 , & clock ) ;
if ( ! F_26 ( V_10 , V_30 ,
& clock ) )
continue;
V_71 = abs ( clock . V_27 - V_58 ) ;
V_70 = F_32 ( 1000000ULL * V_71 , V_58 ) ;
if ( V_70 < 100 && clock . V_22 > V_60 -> V_22 ) {
V_69 = 0 ;
* V_60 = clock ;
V_67 = true ;
}
if ( V_69 >= 10 && V_70 < V_69 - 10 ) {
V_69 = V_70 ;
* V_60 = clock ;
V_67 = true ;
}
}
}
}
}
return V_67 ;
}
static bool
F_33 ( const T_3 * V_30 , struct V_28 * V_29 ,
int V_58 , int V_18 , T_2 * V_59 ,
T_2 * V_60 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
T_2 clock ;
V_55 V_21 ;
int V_67 = false ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
clock . V_25 = 1 , clock . V_20 = 2 ;
V_58 *= 5 ;
for ( clock . V_23 = V_30 -> V_23 . V_57 ; clock . V_23 >= V_30 -> V_23 . V_56 ; clock . V_23 -- ) {
for ( clock . V_24 = V_30 -> V_24 . V_62 ;
clock . V_24 >= V_30 -> V_24 . V_63 ;
clock . V_24 -= clock . V_24 > 10 ? 2 : 1 ) {
clock . V_22 = clock . V_23 * clock . V_24 ;
V_21 = F_25 ( ( ( V_55 ) V_58 * clock . V_22 *
clock . V_25 ) << 22 , V_18 * clock . V_20 ) ;
if ( V_21 > V_72 / clock . V_20 )
continue;
clock . V_21 = V_21 ;
F_24 ( V_18 , & clock ) ;
if ( ! F_26 ( V_10 , V_30 , & clock ) )
continue;
if ( clock . V_22 > V_60 -> V_22 ) {
* V_60 = clock ;
V_67 = true ;
}
}
}
return V_67 ;
}
bool F_34 ( struct V_28 * V_29 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
return V_73 -> V_74 && V_29 -> V_75 -> V_76 &&
V_73 -> V_77 . V_78 . V_79 ;
}
enum V_80 F_36 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_28 * V_29 = V_12 -> V_81 [ V_4 ] ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
return V_73 -> V_77 . V_82 ;
}
static void F_37 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_83 , V_84 = F_38 ( V_4 ) ;
V_83 = F_5 ( V_84 ) ;
if ( F_39 ( F_40 ( V_84 ) != V_83 , 50 ) )
F_41 ( 1 , L_10 ) ;
}
void F_42 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_85 = F_43 ( V_4 ) ;
if ( F_16 ( V_10 ) || F_44 ( V_10 ) -> V_86 >= 5 ) {
F_37 ( V_10 , V_4 ) ;
return;
}
F_45 ( V_85 ,
F_5 ( V_85 ) | V_87 ) ;
if ( F_39 ( F_5 ( V_85 ) &
V_87 ,
50 ) )
F_46 ( L_10 ) ;
}
static bool F_47 ( struct V_9 * V_10 , enum V_4 V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_88 = F_48 ( V_4 ) ;
T_1 V_89 , V_90 ;
T_1 V_91 ;
if ( F_20 ( V_10 ) )
V_91 = V_92 ;
else
V_91 = V_93 ;
V_89 = F_5 ( V_88 ) & V_91 ;
F_49 ( 5 ) ;
V_90 = F_5 ( V_88 ) & V_91 ;
return V_89 == V_90 ;
}
void F_50 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_80 V_82 = F_36 ( V_12 ,
V_4 ) ;
if ( F_44 ( V_10 ) -> V_86 >= 4 ) {
int V_88 = F_51 ( V_82 ) ;
if ( F_39 ( ( F_5 ( V_88 ) & V_94 ) == 0 ,
100 ) )
F_41 ( 1 , L_11 ) ;
} else {
if ( F_39 ( F_47 ( V_10 , V_4 ) , 100 ) )
F_41 ( 1 , L_11 ) ;
}
}
bool F_52 ( struct V_11 * V_12 ,
struct V_95 * V_96 )
{
T_1 V_97 ;
if ( F_53 ( V_12 -> V_10 ) ) {
switch ( V_96 -> V_96 ) {
case V_98 :
V_97 = V_99 ;
break;
case V_100 :
V_97 = V_101 ;
break;
case V_102 :
V_97 = V_103 ;
break;
default:
return true ;
}
} else {
switch ( V_96 -> V_96 ) {
case V_98 :
V_97 = V_104 ;
break;
case V_100 :
V_97 = V_105 ;
break;
case V_102 :
V_97 = V_106 ;
break;
default:
return true ;
}
}
return F_5 ( V_107 ) & V_97 ;
}
static const char * F_54 ( bool V_108 )
{
return V_108 ? L_12 : L_13 ;
}
void F_55 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_109 )
{
int V_88 ;
T_1 V_110 ;
bool V_111 ;
V_88 = F_56 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_111 = ! ! ( V_110 & V_112 ) ;
F_41 ( V_111 != V_109 ,
L_14 ,
F_54 ( V_109 ) , F_54 ( V_111 ) ) ;
}
static void F_57 ( struct V_11 * V_12 , bool V_109 )
{
T_1 V_110 ;
bool V_111 ;
F_58 ( & V_12 -> V_113 ) ;
V_110 = F_59 ( V_12 , V_114 ) ;
F_60 ( & V_12 -> V_113 ) ;
V_111 = V_110 & V_115 ;
F_41 ( V_111 != V_109 ,
L_15 ,
F_54 ( V_109 ) , F_54 ( V_111 ) ) ;
}
struct V_116 *
F_61 ( struct V_73 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
if ( V_29 -> V_77 . V_117 < 0 )
return NULL ;
return & V_12 -> V_118 [ V_29 -> V_77 . V_117 ] ;
}
void F_62 ( struct V_11 * V_12 ,
struct V_116 * V_119 ,
bool V_109 )
{
bool V_111 ;
struct V_120 V_121 ;
if ( F_41 ( ! V_119 ,
L_16 , F_54 ( V_109 ) ) )
return;
V_111 = V_119 -> V_122 ( V_12 , V_119 , & V_121 ) ;
F_41 ( V_111 != V_109 ,
L_17 ,
V_119 -> V_123 , F_54 ( V_109 ) , F_54 ( V_111 ) ) ;
}
static void F_63 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_109 )
{
int V_88 ;
T_1 V_110 ;
bool V_111 ;
enum V_80 V_82 = F_36 ( V_12 ,
V_4 ) ;
if ( F_64 ( V_12 -> V_10 ) ) {
V_88 = F_65 ( V_82 ) ;
V_110 = F_5 ( V_88 ) ;
V_111 = ! ! ( V_110 & V_124 ) ;
} else {
V_88 = F_66 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_111 = ! ! ( V_110 & V_125 ) ;
}
F_41 ( V_111 != V_109 ,
L_18 ,
F_54 ( V_109 ) , F_54 ( V_111 ) ) ;
}
static void F_67 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_109 )
{
int V_88 ;
T_1 V_110 ;
bool V_111 ;
V_88 = F_68 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_111 = ! ! ( V_110 & V_126 ) ;
F_41 ( V_111 != V_109 ,
L_19 ,
F_54 ( V_109 ) , F_54 ( V_111 ) ) ;
}
static void F_69 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_88 ;
T_1 V_110 ;
if ( F_44 ( V_12 -> V_10 ) -> V_86 == 5 )
return;
if ( F_64 ( V_12 -> V_10 ) )
return;
V_88 = F_66 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
F_41 ( ! ( V_110 & V_127 ) , L_20 ) ;
}
void F_70 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_109 )
{
int V_88 ;
T_1 V_110 ;
bool V_111 ;
V_88 = F_68 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_111 = ! ! ( V_110 & V_128 ) ;
F_41 ( V_111 != V_109 ,
L_21 ,
F_54 ( V_109 ) , F_54 ( V_111 ) ) ;
}
static void F_71 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_129 , V_130 ;
T_1 V_110 ;
enum V_4 V_131 = V_132 ;
bool V_133 = true ;
if ( F_4 ( V_12 -> V_10 ) ) {
V_129 = V_134 ;
V_130 = V_135 ;
} else {
V_129 = V_136 ;
V_130 = V_137 ;
}
V_110 = F_5 ( V_129 ) ;
if ( ! ( V_110 & V_138 ) ||
( ( V_110 & V_139 ) == V_139 ) )
V_133 = false ;
if ( F_5 ( V_130 ) & V_140 )
V_131 = V_141 ;
F_41 ( V_131 == V_4 && V_133 ,
L_22 ,
F_72 ( V_4 ) ) ;
}
static void F_73 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_109 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
bool V_111 ;
if ( F_74 ( V_10 ) || F_75 ( V_10 ) )
V_111 = F_5 ( V_142 ) & V_143 ;
else
V_111 = F_5 ( F_76 ( V_4 ) ) & V_144 ;
F_41 ( V_111 != V_109 ,
L_23 ,
F_72 ( V_4 ) , F_54 ( V_109 ) , F_54 ( V_111 ) ) ;
}
void F_77 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_109 )
{
int V_88 ;
T_1 V_110 ;
bool V_111 ;
enum V_80 V_82 = F_36 ( V_12 ,
V_4 ) ;
if ( V_4 == V_132 && V_12 -> V_145 & V_146 )
V_109 = true ;
if ( ! F_78 ( V_12 ,
F_79 ( V_82 ) ) ) {
V_111 = false ;
} else {
V_88 = F_51 ( V_82 ) ;
V_110 = F_5 ( V_88 ) ;
V_111 = ! ! ( V_110 & V_147 ) ;
}
F_41 ( V_111 != V_109 ,
L_24 ,
F_72 ( V_4 ) , F_54 ( V_109 ) , F_54 ( V_111 ) ) ;
}
static void F_80 ( struct V_11 * V_12 ,
enum V_148 V_148 , bool V_109 )
{
int V_88 ;
T_1 V_110 ;
bool V_111 ;
V_88 = F_81 ( V_148 ) ;
V_110 = F_5 ( V_88 ) ;
V_111 = ! ! ( V_110 & V_149 ) ;
F_41 ( V_111 != V_109 ,
L_25 ,
F_82 ( V_148 ) , F_54 ( V_109 ) , F_54 ( V_111 ) ) ;
}
static void F_83 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_88 , V_150 ;
T_1 V_110 ;
int V_151 ;
if ( F_44 ( V_10 ) -> V_86 >= 4 ) {
V_88 = F_81 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
F_41 ( V_110 & V_149 ,
L_26 ,
F_82 ( V_4 ) ) ;
return;
}
F_84 (i) {
V_88 = F_81 ( V_150 ) ;
V_110 = F_5 ( V_88 ) ;
V_151 = ( V_110 & V_152 ) >>
V_153 ;
F_41 ( ( V_110 & V_149 ) && V_4 == V_151 ,
L_27 ,
F_82 ( V_150 ) , F_72 ( V_4 ) ) ;
}
}
static void F_85 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_88 , V_154 ;
T_1 V_110 ;
if ( F_19 ( V_10 ) ) {
F_86 (pipe, sprite) {
V_88 = F_87 ( V_4 , V_154 ) ;
V_110 = F_5 ( V_88 ) ;
F_41 ( V_110 & V_155 ,
L_28 ,
F_88 ( V_4 , V_154 ) , F_72 ( V_4 ) ) ;
}
} else if ( F_44 ( V_10 ) -> V_86 >= 7 ) {
V_88 = F_89 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
F_41 ( V_110 & V_156 ,
L_28 ,
F_82 ( V_4 ) , F_72 ( V_4 ) ) ;
} else if ( F_44 ( V_10 ) -> V_86 >= 5 ) {
V_88 = F_90 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
F_41 ( V_110 & V_157 ,
L_28 ,
F_82 ( V_4 ) , F_72 ( V_4 ) ) ;
}
}
static void F_91 ( struct V_11 * V_12 )
{
T_1 V_110 ;
bool V_108 ;
F_3 ( ! ( F_53 ( V_12 -> V_10 ) || F_92 ( V_12 -> V_10 ) ) ) ;
V_110 = F_5 ( V_158 ) ;
V_108 = ! ! ( V_110 & ( V_159 | V_160 |
V_161 ) ) ;
F_41 ( ! V_108 , L_29 ) ;
}
static void F_93 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_88 ;
T_1 V_110 ;
bool V_108 ;
V_88 = F_94 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_108 = ! ! ( V_110 & V_162 ) ;
F_41 ( V_108 ,
L_30 ,
F_72 ( V_4 ) ) ;
}
static bool F_95 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_163 , T_1 V_110 )
{
if ( ( V_110 & V_164 ) == 0 )
return false ;
if ( F_92 ( V_12 -> V_10 ) ) {
T_1 V_165 = F_96 ( V_4 ) ;
T_1 V_166 = F_5 ( V_165 ) ;
if ( ( V_166 & V_167 ) != V_163 )
return false ;
} else if ( F_18 ( V_12 -> V_10 ) ) {
if ( ( V_110 & V_168 ) != F_97 ( V_4 ) )
return false ;
} else {
if ( ( V_110 & V_169 ) != ( V_4 << 30 ) )
return false ;
}
return true ;
}
static bool F_98 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_110 )
{
if ( ( V_110 & V_170 ) == 0 )
return false ;
if ( F_92 ( V_12 -> V_10 ) ) {
if ( ( V_110 & V_171 ) != F_99 ( V_4 ) )
return false ;
} else if ( F_18 ( V_12 -> V_10 ) ) {
if ( ( V_110 & V_172 ) != F_100 ( V_4 ) )
return false ;
} else {
if ( ( V_110 & V_173 ) != F_101 ( V_4 ) )
return false ;
}
return true ;
}
static bool F_102 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_110 )
{
if ( ( V_110 & V_174 ) == 0 )
return false ;
if ( F_92 ( V_12 -> V_10 ) ) {
if ( ( V_110 & V_175 ) != F_103 ( V_4 ) )
return false ;
} else {
if ( ( V_110 & V_176 ) != F_104 ( V_4 ) )
return false ;
}
return true ;
}
static bool F_105 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_110 )
{
if ( ( V_110 & V_177 ) == 0 )
return false ;
if ( F_92 ( V_12 -> V_10 ) ) {
if ( ( V_110 & V_175 ) != F_103 ( V_4 ) )
return false ;
} else {
if ( ( V_110 & V_178 ) != F_106 ( V_4 ) )
return false ;
}
return true ;
}
static void F_107 ( struct V_11 * V_12 ,
enum V_4 V_4 , int V_88 , T_1 V_163 )
{
T_1 V_110 = F_5 ( V_88 ) ;
F_41 ( F_95 ( V_12 , V_4 , V_163 , V_110 ) ,
L_31 ,
V_88 , F_72 ( V_4 ) ) ;
F_41 ( F_53 ( V_12 -> V_10 ) && ( V_110 & V_164 ) == 0
&& ( V_110 & V_179 ) ,
L_32 ) ;
}
static void F_108 ( struct V_11 * V_12 ,
enum V_4 V_4 , int V_88 )
{
T_1 V_110 = F_5 ( V_88 ) ;
F_41 ( F_98 ( V_12 , V_4 , V_110 ) ,
L_33 ,
V_88 , F_72 ( V_4 ) ) ;
F_41 ( F_53 ( V_12 -> V_10 ) && ( V_110 & V_170 ) == 0
&& ( V_110 & V_180 ) ,
L_34 ) ;
}
static void F_109 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_88 ;
T_1 V_110 ;
F_107 ( V_12 , V_4 , V_181 , V_182 ) ;
F_107 ( V_12 , V_4 , V_183 , V_184 ) ;
F_107 ( V_12 , V_4 , V_185 , V_186 ) ;
V_88 = V_187 ;
V_110 = F_5 ( V_88 ) ;
F_41 ( F_105 ( V_12 , V_4 , V_110 ) ,
L_35 ,
F_72 ( V_4 ) ) ;
V_88 = V_135 ;
V_110 = F_5 ( V_88 ) ;
F_41 ( F_102 ( V_12 , V_4 , V_110 ) ,
L_36 ,
F_72 ( V_4 ) ) ;
F_108 ( V_12 , V_4 , V_188 ) ;
F_108 ( V_12 , V_4 , V_189 ) ;
F_108 ( V_12 , V_4 , V_190 ) ;
}
static void F_110 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_19 ( V_10 ) )
return;
if ( F_18 ( V_10 ) ) {
F_111 ( V_191 ) = V_192 ;
F_111 ( V_193 ) = V_194 ;
} else {
F_111 ( V_191 ) = V_194 ;
}
}
static void F_112 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_18 ( V_10 ) ) {
enum V_195 V_196 ;
T_1 V_110 ;
for ( V_196 = V_191 ; V_196 < V_197 ; V_196 ++ ) {
if ( F_39 ( F_5 ( V_198 ) &
F_113 ( V_196 ) , 1 ) )
F_114 ( L_37 , V_196 ) ;
V_110 = F_5 ( V_199 ) ;
F_45 ( V_199 ,
F_115 ( V_196 , V_110 ) ) ;
}
}
}
static void F_116 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_88 = F_56 ( V_29 -> V_4 ) ;
T_1 V_54 = V_29 -> V_77 . V_200 . V_54 ;
F_117 ( V_12 , V_29 -> V_4 ) ;
F_118 ( ! F_19 ( V_12 -> V_10 ) ) ;
if ( F_119 ( V_12 -> V_10 ) && ! F_120 ( V_12 -> V_10 ) )
F_71 ( V_12 , V_29 -> V_4 ) ;
F_45 ( V_88 , V_54 ) ;
F_121 ( V_88 ) ;
F_122 ( 150 ) ;
if ( F_39 ( ( ( F_5 ( V_88 ) & V_201 ) == V_201 ) , 1 ) )
F_114 ( L_38 , V_29 -> V_4 ) ;
F_45 ( F_123 ( V_29 -> V_4 ) , V_29 -> V_77 . V_200 . V_202 ) ;
F_121 ( F_123 ( V_29 -> V_4 ) ) ;
F_45 ( V_88 , V_54 ) ;
F_121 ( V_88 ) ;
F_122 ( 150 ) ;
F_45 ( V_88 , V_54 ) ;
F_121 ( V_88 ) ;
F_122 ( 150 ) ;
F_45 ( V_88 , V_54 ) ;
F_121 ( V_88 ) ;
F_122 ( 150 ) ;
}
static void F_124 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
enum V_203 V_96 = F_125 ( V_4 ) ;
T_1 V_204 ;
F_117 ( V_12 , V_29 -> V_4 ) ;
F_118 ( ! F_18 ( V_12 -> V_10 ) ) ;
F_58 ( & V_12 -> V_113 ) ;
V_204 = F_126 ( V_12 , V_4 , F_127 ( V_96 ) ) ;
V_204 |= V_205 ;
F_128 ( V_12 , V_4 , F_127 ( V_96 ) , V_204 ) ;
F_122 ( 1 ) ;
F_45 ( F_56 ( V_4 ) , V_29 -> V_77 . V_200 . V_54 ) ;
if ( F_39 ( ( ( F_5 ( F_56 ( V_4 ) ) & V_201 ) == V_201 ) , 1 ) )
F_114 ( L_39 , V_4 ) ;
F_45 ( F_123 ( V_4 ) , V_29 -> V_77 . V_200 . V_202 ) ;
F_121 ( F_123 ( V_4 ) ) ;
F_60 ( & V_12 -> V_113 ) ;
}
static void F_129 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_88 = F_56 ( V_29 -> V_4 ) ;
T_1 V_54 = V_29 -> V_77 . V_200 . V_54 ;
F_117 ( V_12 , V_29 -> V_4 ) ;
F_118 ( F_44 ( V_10 ) -> V_86 >= 5 ) ;
if ( F_119 ( V_10 ) && ! F_120 ( V_10 ) )
F_71 ( V_12 , V_29 -> V_4 ) ;
F_45 ( V_88 , V_54 ) ;
F_121 ( V_88 ) ;
F_122 ( 150 ) ;
if ( F_44 ( V_10 ) -> V_86 >= 4 ) {
F_45 ( F_123 ( V_29 -> V_4 ) ,
V_29 -> V_77 . V_200 . V_202 ) ;
} else {
F_45 ( V_88 , V_54 ) ;
}
F_45 ( V_88 , V_54 ) ;
F_121 ( V_88 ) ;
F_122 ( 150 ) ;
F_45 ( V_88 , V_54 ) ;
F_121 ( V_88 ) ;
F_122 ( 150 ) ;
F_45 ( V_88 , V_54 ) ;
F_121 ( V_88 ) ;
F_122 ( 150 ) ;
}
static void F_130 ( struct V_11 * V_12 , enum V_4 V_4 )
{
if ( V_4 == V_132 && ( V_12 -> V_145 & V_146 ) )
return;
F_117 ( V_12 , V_4 ) ;
F_45 ( F_56 ( V_4 ) , 0 ) ;
F_121 ( F_56 ( V_4 ) ) ;
}
static void F_131 ( struct V_11 * V_12 , enum V_4 V_4 )
{
T_1 V_110 = 0 ;
F_117 ( V_12 , V_4 ) ;
if ( V_4 == V_141 )
V_110 = V_206 | V_207 ;
F_45 ( F_56 ( V_4 ) , V_110 ) ;
F_121 ( F_56 ( V_4 ) ) ;
}
static void F_132 ( struct V_11 * V_12 , enum V_4 V_4 )
{
enum V_203 V_96 = F_125 ( V_4 ) ;
T_1 V_110 ;
F_117 ( V_12 , V_4 ) ;
V_110 = V_208 ;
if ( V_4 != V_132 )
V_110 |= V_206 ;
F_45 ( F_56 ( V_4 ) , V_110 ) ;
F_121 ( F_56 ( V_4 ) ) ;
F_58 ( & V_12 -> V_113 ) ;
V_110 = F_126 ( V_12 , V_4 , F_127 ( V_96 ) ) ;
V_110 &= ~ V_205 ;
F_128 ( V_12 , V_4 , F_127 ( V_96 ) , V_110 ) ;
if ( V_4 != V_141 ) {
V_110 = F_126 ( V_12 , V_4 , V_209 ) ;
V_110 &= ~ ( V_210 | V_211 ) ;
F_128 ( V_12 , V_4 , V_209 , V_110 ) ;
} else {
V_110 = F_126 ( V_12 , V_4 , V_212 ) ;
V_110 &= ~ ( V_213 | V_214 ) ;
F_128 ( V_12 , V_4 , V_212 , V_110 ) ;
}
F_60 ( & V_12 -> V_113 ) ;
}
void F_133 ( struct V_11 * V_12 ,
struct V_95 * V_215 )
{
T_1 V_216 ;
int V_217 ;
switch ( V_215 -> V_96 ) {
case V_98 :
V_216 = V_218 ;
V_217 = F_56 ( 0 ) ;
break;
case V_100 :
V_216 = V_219 ;
V_217 = F_56 ( 0 ) ;
break;
case V_102 :
V_216 = V_220 ;
V_217 = V_221 ;
break;
default:
F_134 () ;
}
if ( F_39 ( ( F_5 ( V_217 ) & V_216 ) == 0 , 1000 ) )
F_41 ( 1 , L_40 ,
F_135 ( V_215 -> V_96 ) , F_5 ( V_217 ) ) ;
}
static void F_136 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_116 * V_119 = F_61 ( V_29 ) ;
if ( F_3 ( V_119 == NULL ) )
return;
F_3 ( ! V_119 -> V_222 ) ;
if ( V_119 -> V_74 == 0 ) {
F_137 ( L_41 , V_119 -> V_123 ) ;
F_3 ( V_119 -> V_223 ) ;
F_138 ( V_12 , V_119 ) ;
V_119 -> V_224 ( V_12 , V_119 ) ;
}
}
static void F_139 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_116 * V_119 = F_61 ( V_29 ) ;
if ( F_3 ( V_119 == NULL ) )
return;
if ( F_3 ( V_119 -> V_222 == 0 ) )
return;
F_46 ( L_42 ,
V_119 -> V_123 , V_119 -> V_74 , V_119 -> V_223 ,
V_29 -> V_8 . V_8 . V_225 ) ;
if ( V_119 -> V_74 ++ ) {
F_3 ( ! V_119 -> V_223 ) ;
F_140 ( V_12 , V_119 ) ;
return;
}
F_3 ( V_119 -> V_223 ) ;
F_141 ( V_12 , V_226 ) ;
F_46 ( L_43 , V_119 -> V_123 ) ;
V_119 -> V_227 ( V_12 , V_119 ) ;
V_119 -> V_223 = true ;
}
void F_142 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_116 * V_119 = F_61 ( V_29 ) ;
F_118 ( F_44 ( V_10 ) -> V_86 < 5 ) ;
if ( F_3 ( V_119 == NULL ) )
return;
if ( F_3 ( V_119 -> V_222 == 0 ) )
return;
F_46 ( L_44 ,
V_119 -> V_123 , V_119 -> V_74 , V_119 -> V_223 ,
V_29 -> V_8 . V_8 . V_225 ) ;
if ( F_3 ( V_119 -> V_74 == 0 ) ) {
F_138 ( V_12 , V_119 ) ;
return;
}
F_140 ( V_12 , V_119 ) ;
F_3 ( ! V_119 -> V_223 ) ;
if ( -- V_119 -> V_74 )
return;
F_46 ( L_45 , V_119 -> V_123 ) ;
V_119 -> V_228 ( V_12 , V_119 ) ;
V_119 -> V_223 = false ;
F_143 ( V_12 , V_226 ) ;
}
static void F_144 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_28 * V_29 = V_12 -> V_81 [ V_4 ] ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
T_4 V_88 , V_110 , V_229 ;
F_118 ( F_44 ( V_10 ) -> V_86 < 5 ) ;
F_140 ( V_12 ,
F_61 ( V_73 ) ) ;
F_145 ( V_12 , V_4 ) ;
F_146 ( V_12 , V_4 ) ;
if ( F_92 ( V_10 ) ) {
V_88 = F_147 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_110 |= V_230 ;
F_45 ( V_88 , V_110 ) ;
}
V_88 = F_94 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_229 = F_5 ( F_51 ( V_4 ) ) ;
if ( F_53 ( V_12 -> V_10 ) ) {
V_110 &= ~ V_231 ;
V_110 |= V_229 & V_231 ;
}
V_110 &= ~ V_232 ;
if ( ( V_229 & V_233 ) == V_234 )
if ( F_53 ( V_12 -> V_10 ) &&
F_10 ( V_29 , V_42 ) )
V_110 |= V_235 ;
else
V_110 |= V_236 ;
else
V_110 |= V_237 ;
F_45 ( V_88 , V_110 | V_162 ) ;
if ( F_39 ( F_5 ( V_88 ) & V_238 , 100 ) )
F_114 ( L_46 , F_72 ( V_4 ) ) ;
}
static void F_148 ( struct V_11 * V_12 ,
enum V_80 V_82 )
{
T_1 V_110 , V_229 ;
F_118 ( F_44 ( V_12 -> V_10 ) -> V_86 < 5 ) ;
F_145 ( V_12 , (enum V_4 ) V_82 ) ;
F_146 ( V_12 , V_239 ) ;
V_110 = F_5 ( V_240 ) ;
V_110 |= V_230 ;
F_45 ( V_240 , V_110 ) ;
V_110 = V_162 ;
V_229 = F_5 ( F_51 ( V_82 ) ) ;
if ( ( V_229 & V_241 ) ==
V_234 )
V_110 |= V_236 ;
else
V_110 |= V_237 ;
F_45 ( V_242 , V_110 ) ;
if ( F_39 ( F_5 ( V_242 ) & V_238 , 100 ) )
F_114 ( L_47 ) ;
}
static void F_149 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_88 , V_110 ;
F_150 ( V_12 , V_4 ) ;
F_151 ( V_12 , V_4 ) ;
F_109 ( V_12 , V_4 ) ;
V_88 = F_94 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_110 &= ~ V_162 ;
F_45 ( V_88 , V_110 ) ;
if ( F_39 ( ( F_5 ( V_88 ) & V_238 ) == 0 , 50 ) )
F_114 ( L_48 , F_72 ( V_4 ) ) ;
if ( ! F_53 ( V_10 ) ) {
V_88 = F_147 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_110 &= ~ V_230 ;
F_45 ( V_88 , V_110 ) ;
}
}
static void F_152 ( struct V_11 * V_12 )
{
T_1 V_110 ;
V_110 = F_5 ( V_242 ) ;
V_110 &= ~ V_162 ;
F_45 ( V_242 , V_110 ) ;
if ( F_39 ( ( F_5 ( V_242 ) & V_238 ) == 0 , 50 ) )
F_114 ( L_49 ) ;
V_110 = F_5 ( V_240 ) ;
V_110 &= ~ V_230 ;
F_45 ( V_240 , V_110 ) ;
}
static void F_153 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
enum V_80 V_82 = F_36 ( V_12 ,
V_4 ) ;
enum V_4 V_243 ;
int V_88 ;
T_1 V_110 ;
F_83 ( V_12 , V_4 ) ;
F_154 ( V_12 , V_4 ) ;
F_85 ( V_12 , V_4 ) ;
if ( F_155 ( V_12 -> V_10 ) )
V_243 = V_239 ;
else
V_243 = V_4 ;
if ( ! F_4 ( V_12 -> V_10 ) )
if ( F_10 ( & V_29 -> V_8 , V_244 ) )
F_156 ( V_12 ) ;
else
F_157 ( V_12 , V_4 ) ;
else {
if ( V_29 -> V_77 . V_245 ) {
F_158 ( V_12 , V_243 ) ;
F_69 ( V_12 ,
(enum V_4 ) V_82 ) ;
}
}
V_88 = F_51 ( V_82 ) ;
V_110 = F_5 ( V_88 ) ;
if ( V_110 & V_147 ) {
F_3 ( ! ( V_4 == V_132 &&
V_12 -> V_145 & V_146 ) ) ;
return;
}
F_45 ( V_88 , V_110 | V_147 ) ;
F_121 ( V_88 ) ;
}
static void F_159 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
enum V_80 V_82 = F_36 ( V_12 ,
V_4 ) ;
int V_88 ;
T_1 V_110 ;
F_83 ( V_12 , V_4 ) ;
F_154 ( V_12 , V_4 ) ;
F_85 ( V_12 , V_4 ) ;
if ( V_4 == V_132 && ( V_12 -> V_145 & V_146 ) )
return;
V_88 = F_51 ( V_82 ) ;
V_110 = F_5 ( V_88 ) ;
if ( ( V_110 & V_147 ) == 0 )
return;
F_45 ( V_88 , V_110 & ~ V_147 ) ;
F_50 ( V_12 -> V_10 , V_4 ) ;
}
void F_160 ( struct V_11 * V_12 ,
enum V_148 V_148 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_1 V_88 = F_44 ( V_10 ) -> V_86 >= 4 ? F_161 ( V_148 ) : F_162 ( V_148 ) ;
F_45 ( V_88 , F_5 ( V_88 ) ) ;
F_121 ( V_88 ) ;
}
static void F_163 ( struct V_11 * V_12 ,
enum V_148 V_148 , enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_73 * V_73 =
F_35 ( V_12 -> V_81 [ V_4 ] ) ;
int V_88 ;
T_1 V_110 ;
F_164 ( V_12 , V_4 ) ;
if ( V_73 -> V_246 )
return;
V_73 -> V_246 = true ;
V_88 = F_81 ( V_148 ) ;
V_110 = F_5 ( V_88 ) ;
F_3 ( V_110 & V_149 ) ;
F_45 ( V_88 , V_110 | V_149 ) ;
F_160 ( V_12 , V_148 ) ;
if ( F_165 ( V_10 ) )
F_42 ( V_10 , V_73 -> V_4 ) ;
}
static void F_166 ( struct V_11 * V_12 ,
enum V_148 V_148 , enum V_4 V_4 )
{
struct V_73 * V_73 =
F_35 ( V_12 -> V_81 [ V_4 ] ) ;
int V_88 ;
T_1 V_110 ;
if ( ! V_73 -> V_246 )
return;
V_73 -> V_246 = false ;
V_88 = F_81 ( V_148 ) ;
V_110 = F_5 ( V_88 ) ;
F_3 ( ( V_110 & V_149 ) == 0 ) ;
F_45 ( V_88 , V_110 & ~ V_149 ) ;
F_160 ( V_12 , V_148 ) ;
}
static bool F_167 ( struct V_9 * V_10 )
{
#ifdef F_168
if ( F_44 ( V_10 ) -> V_86 >= 6 && V_247 )
return true ;
#endif
return false ;
}
static int F_169 ( struct V_9 * V_10 , int V_248 , bool V_249 )
{
int V_250 ;
V_250 = V_249 ? ( F_20 ( V_10 ) ? 16 : 8 ) : 1 ;
return F_170 ( V_248 , V_250 ) ;
}
int
F_171 ( struct V_9 * V_10 ,
struct V_251 * V_252 ,
struct V_253 * V_254 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_255 ;
int V_256 ;
F_3 ( ! F_172 ( & V_10 -> V_257 ) ) ;
switch ( V_252 -> V_258 ) {
case V_259 :
if ( F_173 ( V_10 ) || F_174 ( V_10 ) )
V_255 = 128 * 1024 ;
else if ( F_44 ( V_10 ) -> V_86 >= 4 )
V_255 = 4 * 1024 ;
else
V_255 = 64 * 1024 ;
break;
case V_260 :
V_255 = 0 ;
break;
case V_261 :
F_41 ( 1 , L_50 ) ;
return - V_262 ;
default:
F_134 () ;
}
if ( F_167 ( V_10 ) && V_255 < 256 * 1024 )
V_255 = 256 * 1024 ;
F_175 ( V_12 ) ;
V_12 -> V_263 . V_264 = false ;
V_256 = F_176 ( V_252 , V_255 , V_254 ) ;
if ( V_256 )
goto V_265;
V_256 = F_177 ( V_252 ) ;
if ( V_256 )
goto V_266;
F_178 ( V_252 ) ;
V_12 -> V_263 . V_264 = true ;
F_179 ( V_12 ) ;
return 0 ;
V_266:
F_180 ( V_252 ) ;
V_265:
V_12 -> V_263 . V_264 = true ;
F_179 ( V_12 ) ;
return V_256 ;
}
void F_181 ( struct V_251 * V_252 )
{
F_3 ( ! F_172 ( & V_252 -> V_8 . V_10 -> V_257 ) ) ;
F_182 ( V_252 ) ;
F_180 ( V_252 ) ;
}
unsigned long F_183 ( int * V_267 , int * V_268 ,
unsigned int V_258 ,
unsigned int V_269 ,
unsigned int V_270 )
{
if ( V_258 != V_259 ) {
unsigned int V_271 , V_272 ;
V_271 = * V_268 / 8 ;
* V_268 %= 8 ;
V_272 = * V_267 / ( 512 / V_269 ) ;
* V_267 %= 512 / V_269 ;
return V_271 * V_270 * 8 + V_272 * 4096 ;
} else {
unsigned int V_273 ;
V_273 = * V_268 * V_270 + * V_267 * V_269 ;
* V_268 = 0 ;
* V_267 = ( V_273 & 4095 ) / V_269 ;
return V_273 & - 4096 ;
}
}
int F_184 ( int V_274 )
{
switch ( V_274 ) {
case V_275 :
return V_276 ;
case V_277 :
return V_278 ;
case V_279 :
return V_280 ;
default:
case V_281 :
return V_282 ;
case V_283 :
return V_284 ;
case V_285 :
return V_286 ;
case V_287 :
return V_288 ;
}
}
static bool F_185 ( struct V_73 * V_29 ,
struct V_289 * V_290 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_251 * V_252 = NULL ;
struct V_291 V_292 = { 0 } ;
T_1 V_8 = V_290 -> V_8 ;
if ( V_290 -> V_293 == 0 )
return false ;
V_252 = F_186 ( V_10 , V_8 , V_8 ,
V_290 -> V_293 ) ;
if ( ! V_252 )
return false ;
if ( V_290 -> V_249 ) {
V_252 -> V_258 = V_260 ;
V_252 -> V_294 = V_29 -> V_8 . V_75 -> V_76 -> V_295 [ 0 ] ;
}
V_292 . V_296 = V_29 -> V_8 . V_75 -> V_76 -> V_296 ;
V_292 . V_297 = V_29 -> V_8 . V_75 -> V_76 -> V_297 ;
V_292 . V_248 = V_29 -> V_8 . V_75 -> V_76 -> V_248 ;
V_292 . V_295 [ 0 ] = V_29 -> V_8 . V_75 -> V_76 -> V_295 [ 0 ] ;
F_58 ( & V_10 -> V_257 ) ;
if ( F_187 ( V_10 , F_188 ( V_29 -> V_8 . V_75 -> V_76 ) ,
& V_292 , V_252 ) ) {
F_46 ( L_51 ) ;
goto V_298;
}
V_252 -> V_299 = F_189 ( V_29 -> V_4 ) ;
F_60 ( & V_10 -> V_257 ) ;
F_46 ( L_52 , V_252 ) ;
return true ;
V_298:
F_190 ( & V_252 -> V_8 ) ;
F_60 ( & V_10 -> V_257 ) ;
return false ;
}
static void F_191 ( struct V_73 * V_73 ,
struct V_289 * V_290 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_28 * V_300 ;
struct V_73 * V_150 ;
struct V_251 * V_252 ;
if ( ! V_73 -> V_8 . V_75 -> V_76 )
return;
if ( F_185 ( V_73 , V_290 ) )
return;
F_192 ( V_73 -> V_8 . V_75 -> V_76 ) ;
V_73 -> V_8 . V_75 -> V_76 = NULL ;
F_193 (dev, c) {
V_150 = F_35 ( V_300 ) ;
if ( V_300 == & V_73 -> V_8 )
continue;
if ( ! V_150 -> V_74 )
continue;
V_252 = F_194 ( V_300 -> V_75 -> V_76 ) ;
if ( V_252 == NULL )
continue;
if ( F_195 ( V_252 ) == V_290 -> V_8 ) {
F_196 ( V_300 -> V_75 -> V_76 ) ;
V_73 -> V_8 . V_75 -> V_76 = V_300 -> V_75 -> V_76 ;
V_252 -> V_299 |= F_189 ( V_73 -> V_4 ) ;
break;
}
}
}
static void F_197 ( struct V_28 * V_29 ,
struct V_301 * V_76 ,
int V_267 , int V_268 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_251 * V_252 = F_194 ( V_76 ) ;
int V_148 = V_73 -> V_148 ;
unsigned long V_302 ;
T_1 V_303 ;
T_1 V_88 ;
V_88 = F_81 ( V_148 ) ;
V_303 = F_5 ( V_88 ) ;
V_303 &= ~ V_304 ;
switch ( V_76 -> V_296 ) {
case V_276 :
V_303 |= V_275 ;
break;
case V_278 :
case V_305 :
V_303 |= V_277 ;
break;
case V_280 :
V_303 |= V_279 ;
break;
case V_282 :
case V_306 :
V_303 |= V_281 ;
break;
case V_284 :
case V_307 :
V_303 |= V_283 ;
break;
case V_286 :
case V_308 :
V_303 |= V_285 ;
break;
case V_288 :
case V_309 :
V_303 |= V_287 ;
break;
default:
F_134 () ;
}
if ( F_44 ( V_10 ) -> V_86 >= 4 ) {
if ( V_252 -> V_258 != V_259 )
V_303 |= V_310 ;
else
V_303 &= ~ V_310 ;
}
if ( F_16 ( V_10 ) )
V_303 |= V_311 ;
F_45 ( V_88 , V_303 ) ;
V_302 = V_268 * V_76 -> V_295 [ 0 ] + V_267 * ( V_76 -> V_312 / 8 ) ;
if ( F_44 ( V_10 ) -> V_86 >= 4 ) {
V_73 -> V_313 =
F_183 ( & V_267 , & V_268 , V_252 -> V_258 ,
V_76 -> V_312 / 8 ,
V_76 -> V_295 [ 0 ] ) ;
V_302 -= V_73 -> V_313 ;
} else {
V_73 -> V_313 = V_302 ;
}
F_46 ( L_53 ,
F_195 ( V_252 ) , V_302 , V_267 , V_268 ,
V_76 -> V_295 [ 0 ] ) ;
F_45 ( F_198 ( V_148 ) , V_76 -> V_295 [ 0 ] ) ;
if ( F_44 ( V_10 ) -> V_86 >= 4 ) {
F_45 ( F_161 ( V_148 ) ,
F_195 ( V_252 ) + V_73 -> V_313 ) ;
F_45 ( F_199 ( V_148 ) , ( V_268 << 16 ) | V_267 ) ;
F_45 ( F_200 ( V_148 ) , V_302 ) ;
} else
F_45 ( F_162 ( V_148 ) , F_195 ( V_252 ) + V_302 ) ;
F_121 ( V_88 ) ;
}
static void F_201 ( struct V_28 * V_29 ,
struct V_301 * V_76 ,
int V_267 , int V_268 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_251 * V_252 = F_194 ( V_76 ) ;
int V_148 = V_73 -> V_148 ;
unsigned long V_302 ;
T_1 V_303 ;
T_1 V_88 ;
V_88 = F_81 ( V_148 ) ;
V_303 = F_5 ( V_88 ) ;
V_303 &= ~ V_304 ;
switch ( V_76 -> V_296 ) {
case V_276 :
V_303 |= V_275 ;
break;
case V_280 :
V_303 |= V_279 ;
break;
case V_282 :
case V_306 :
V_303 |= V_281 ;
break;
case V_284 :
case V_307 :
V_303 |= V_283 ;
break;
case V_286 :
case V_308 :
V_303 |= V_285 ;
break;
case V_288 :
case V_309 :
V_303 |= V_287 ;
break;
default:
F_134 () ;
}
if ( V_252 -> V_258 != V_259 )
V_303 |= V_310 ;
else
V_303 &= ~ V_310 ;
if ( F_202 ( V_10 ) || F_165 ( V_10 ) )
V_303 &= ~ V_311 ;
else
V_303 |= V_311 ;
F_45 ( V_88 , V_303 ) ;
V_302 = V_268 * V_76 -> V_295 [ 0 ] + V_267 * ( V_76 -> V_312 / 8 ) ;
V_73 -> V_313 =
F_183 ( & V_267 , & V_268 , V_252 -> V_258 ,
V_76 -> V_312 / 8 ,
V_76 -> V_295 [ 0 ] ) ;
V_302 -= V_73 -> V_313 ;
F_46 ( L_53 ,
F_195 ( V_252 ) , V_302 , V_267 , V_268 ,
V_76 -> V_295 [ 0 ] ) ;
F_45 ( F_198 ( V_148 ) , V_76 -> V_295 [ 0 ] ) ;
F_45 ( F_161 ( V_148 ) ,
F_195 ( V_252 ) + V_73 -> V_313 ) ;
if ( F_202 ( V_10 ) || F_165 ( V_10 ) ) {
F_45 ( F_203 ( V_148 ) , ( V_268 << 16 ) | V_267 ) ;
} else {
F_45 ( F_199 ( V_148 ) , ( V_268 << 16 ) | V_267 ) ;
F_45 ( F_200 ( V_148 ) , V_302 ) ;
}
F_121 ( V_88 ) ;
}
static int
F_204 ( struct V_28 * V_29 , struct V_301 * V_76 ,
int V_267 , int V_268 , enum V_314 V_109 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_12 -> V_315 . V_316 )
V_12 -> V_315 . V_316 ( V_10 ) ;
F_205 ( V_10 , F_35 ( V_29 ) -> V_4 ) ;
V_12 -> V_315 . V_317 ( V_29 , V_76 , V_267 , V_268 ) ;
return 0 ;
}
void F_206 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 ;
F_193 (dev, crtc) {
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_148 V_148 = V_73 -> V_148 ;
F_207 ( V_10 , V_148 ) ;
F_208 ( V_10 , V_148 ) ;
}
F_193 (dev, crtc) {
struct V_73 * V_73 = F_35 ( V_29 ) ;
F_209 ( & V_29 -> V_318 , NULL ) ;
if ( V_73 -> V_74 && V_29 -> V_75 -> V_76 )
V_12 -> V_315 . V_317 ( V_29 ,
V_29 -> V_75 -> V_76 ,
V_29 -> V_267 ,
V_29 -> V_268 ) ;
F_210 ( & V_29 -> V_318 ) ;
}
}
static int
F_211 ( struct V_301 * V_319 )
{
struct V_251 * V_252 = F_194 ( V_319 ) ;
struct V_11 * V_12 = V_252 -> V_8 . V_10 -> V_13 ;
bool V_320 = V_12 -> V_263 . V_264 ;
int V_256 ;
V_12 -> V_263 . V_264 = false ;
V_256 = F_212 ( V_252 ) ;
V_12 -> V_263 . V_264 = V_320 ;
return V_256 ;
}
static bool F_213 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
unsigned long V_321 ;
bool V_322 ;
if ( F_214 ( & V_12 -> V_323 ) ||
V_73 -> V_324 != F_215 ( & V_12 -> V_323 . V_324 ) )
return false ;
F_216 ( & V_10 -> V_325 , V_321 ) ;
V_322 = F_35 ( V_29 ) -> V_326 != NULL ;
F_217 ( & V_10 -> V_325 , V_321 ) ;
return V_322 ;
}
static int
F_218 ( struct V_28 * V_29 , int V_267 , int V_268 ,
struct V_301 * V_76 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_4 V_4 = V_73 -> V_4 ;
struct V_301 * V_319 = V_29 -> V_75 -> V_76 ;
struct V_251 * V_252 = F_194 ( V_76 ) ;
struct V_251 * V_327 = F_194 ( V_319 ) ;
int V_256 ;
if ( F_213 ( V_29 ) ) {
F_114 ( L_54 ) ;
return - V_328 ;
}
if ( ! V_76 ) {
F_114 ( L_55 ) ;
return 0 ;
}
if ( V_73 -> V_148 > F_44 ( V_10 ) -> V_329 ) {
F_114 ( L_56 ,
F_82 ( V_73 -> V_148 ) ,
F_44 ( V_10 ) -> V_329 ) ;
return - V_262 ;
}
F_58 ( & V_10 -> V_257 ) ;
V_256 = F_171 ( V_10 , V_252 , NULL ) ;
if ( V_256 == 0 )
F_219 ( V_327 , V_252 ,
F_189 ( V_4 ) ) ;
F_60 ( & V_10 -> V_257 ) ;
if ( V_256 != 0 ) {
F_114 ( L_57 ) ;
return V_256 ;
}
if ( V_330 . V_331 ) {
const struct V_332 * V_78 =
& V_73 -> V_77 . V_78 ;
F_45 ( F_220 ( V_73 -> V_4 ) ,
( ( V_78 -> V_333 - 1 ) << 16 ) |
( V_78 -> V_334 - 1 ) ) ;
if ( ! V_73 -> V_77 . V_335 . V_108 &&
( F_10 ( V_29 , V_31 ) ||
F_10 ( V_29 , V_336 ) ) ) {
F_45 ( F_221 ( V_73 -> V_4 ) , 0 ) ;
F_45 ( F_222 ( V_73 -> V_4 ) , 0 ) ;
F_45 ( F_223 ( V_73 -> V_4 ) , 0 ) ;
}
V_73 -> V_77 . V_337 = V_78 -> V_333 ;
V_73 -> V_77 . V_338 = V_78 -> V_334 ;
}
V_12 -> V_315 . V_317 ( V_29 , V_76 , V_267 , V_268 ) ;
if ( V_73 -> V_74 )
F_224 ( V_10 , F_189 ( V_4 ) ) ;
V_29 -> V_75 -> V_76 = V_76 ;
V_29 -> V_267 = V_267 ;
V_29 -> V_268 = V_268 ;
if ( V_319 ) {
if ( V_73 -> V_74 && V_319 != V_76 )
F_42 ( V_10 , V_73 -> V_4 ) ;
F_58 ( & V_10 -> V_257 ) ;
F_181 ( V_327 ) ;
F_60 ( & V_10 -> V_257 ) ;
}
F_58 ( & V_10 -> V_257 ) ;
F_225 ( V_10 ) ;
F_60 ( & V_10 -> V_257 ) ;
return 0 ;
}
static void F_226 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_339 ;
V_88 = F_66 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
if ( F_227 ( V_10 ) ) {
V_339 &= ~ V_340 ;
V_339 |= V_340 | V_341 ;
} else {
V_339 &= ~ V_342 ;
V_339 |= V_342 | V_341 ;
}
F_45 ( V_88 , V_339 ) ;
V_88 = F_68 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
if ( F_92 ( V_10 ) ) {
V_339 &= ~ V_343 ;
V_339 |= V_344 ;
} else {
V_339 &= ~ V_342 ;
V_339 |= V_342 ;
}
F_45 ( V_88 , V_339 | V_345 ) ;
F_121 ( V_88 ) ;
F_122 ( 1000 ) ;
if ( F_227 ( V_10 ) )
F_45 ( V_88 , F_5 ( V_88 ) | V_346 |
V_347 ) ;
}
static bool F_228 ( struct V_73 * V_29 )
{
return V_29 -> V_8 . V_108 && V_29 -> V_74 &&
V_29 -> V_77 . V_245 ;
}
static void F_229 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_348 =
F_35 ( V_12 -> V_81 [ V_141 ] ) ;
struct V_73 * V_349 =
F_35 ( V_12 -> V_81 [ V_350 ] ) ;
T_4 V_339 ;
if ( ! F_228 ( V_348 ) &&
! F_228 ( V_349 ) ) {
F_3 ( F_5 ( F_68 ( V_141 ) ) & V_126 ) ;
F_3 ( F_5 ( F_68 ( V_350 ) ) & V_126 ) ;
V_339 = F_5 ( V_351 ) ;
V_339 &= ~ V_352 ;
F_46 ( L_58 ) ;
F_45 ( V_351 , V_339 ) ;
}
}
static void F_230 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_339 , V_353 ;
F_164 ( V_12 , V_4 ) ;
V_88 = F_231 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_354 ;
V_339 &= ~ V_355 ;
F_45 ( V_88 , V_339 ) ;
F_5 ( V_88 ) ;
F_122 ( 150 ) ;
V_88 = F_66 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_356 ;
V_339 |= F_232 ( V_73 -> V_77 . V_357 ) ;
V_339 &= ~ V_342 ;
V_339 |= V_358 ;
F_45 ( V_88 , V_339 | V_125 ) ;
V_88 = F_68 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_342 ;
V_339 |= V_358 ;
F_45 ( V_88 , V_339 | V_126 ) ;
F_121 ( V_88 ) ;
F_122 ( 150 ) ;
F_45 ( F_233 ( V_4 ) , V_359 ) ;
F_45 ( F_233 ( V_4 ) , V_359 |
V_360 ) ;
V_88 = F_234 ( V_4 ) ;
for ( V_353 = 0 ; V_353 < 5 ; V_353 ++ ) {
V_339 = F_5 ( V_88 ) ;
F_46 ( L_59 , V_339 ) ;
if ( ( V_339 & V_355 ) ) {
F_46 ( L_60 ) ;
F_45 ( V_88 , V_339 | V_355 ) ;
break;
}
}
if ( V_353 == 5 )
F_114 ( L_61 ) ;
V_88 = F_66 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_342 ;
V_339 |= V_361 ;
F_45 ( V_88 , V_339 ) ;
V_88 = F_68 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_342 ;
V_339 |= V_361 ;
F_45 ( V_88 , V_339 ) ;
F_121 ( V_88 ) ;
F_122 ( 150 ) ;
V_88 = F_234 ( V_4 ) ;
for ( V_353 = 0 ; V_353 < 5 ; V_353 ++ ) {
V_339 = F_5 ( V_88 ) ;
F_46 ( L_59 , V_339 ) ;
if ( V_339 & V_354 ) {
F_45 ( V_88 , V_339 | V_354 ) ;
F_46 ( L_62 ) ;
break;
}
}
if ( V_353 == 5 )
F_114 ( L_63 ) ;
F_46 ( L_64 ) ;
}
static void F_235 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_339 , V_150 , V_362 ;
V_88 = F_231 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_354 ;
V_339 &= ~ V_355 ;
F_45 ( V_88 , V_339 ) ;
F_121 ( V_88 ) ;
F_122 ( 150 ) ;
V_88 = F_66 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_356 ;
V_339 |= F_232 ( V_73 -> V_77 . V_357 ) ;
V_339 &= ~ V_342 ;
V_339 |= V_358 ;
V_339 &= ~ V_363 ;
V_339 |= V_364 ;
F_45 ( V_88 , V_339 | V_125 ) ;
F_45 ( F_236 ( V_4 ) ,
V_365 | V_366 ) ;
V_88 = F_68 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
if ( F_92 ( V_10 ) ) {
V_339 &= ~ V_343 ;
V_339 |= V_367 ;
} else {
V_339 &= ~ V_342 ;
V_339 |= V_358 ;
}
F_45 ( V_88 , V_339 | V_126 ) ;
F_121 ( V_88 ) ;
F_122 ( 150 ) ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
V_88 = F_66 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_363 ;
V_339 |= V_368 [ V_150 ] ;
F_45 ( V_88 , V_339 ) ;
F_121 ( V_88 ) ;
F_122 ( 500 ) ;
for ( V_362 = 0 ; V_362 < 5 ; V_362 ++ ) {
V_88 = F_234 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
F_46 ( L_59 , V_339 ) ;
if ( V_339 & V_355 ) {
F_45 ( V_88 , V_339 | V_355 ) ;
F_46 ( L_60 ) ;
break;
}
F_122 ( 50 ) ;
}
if ( V_362 < 5 )
break;
}
if ( V_150 == 4 )
F_114 ( L_61 ) ;
V_88 = F_66 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_342 ;
V_339 |= V_361 ;
if ( F_237 ( V_10 ) ) {
V_339 &= ~ V_363 ;
V_339 |= V_364 ;
}
F_45 ( V_88 , V_339 ) ;
V_88 = F_68 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
if ( F_92 ( V_10 ) ) {
V_339 &= ~ V_343 ;
V_339 |= V_369 ;
} else {
V_339 &= ~ V_342 ;
V_339 |= V_361 ;
}
F_45 ( V_88 , V_339 ) ;
F_121 ( V_88 ) ;
F_122 ( 150 ) ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
V_88 = F_66 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_363 ;
V_339 |= V_368 [ V_150 ] ;
F_45 ( V_88 , V_339 ) ;
F_121 ( V_88 ) ;
F_122 ( 500 ) ;
for ( V_362 = 0 ; V_362 < 5 ; V_362 ++ ) {
V_88 = F_234 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
F_46 ( L_59 , V_339 ) ;
if ( V_339 & V_354 ) {
F_45 ( V_88 , V_339 | V_354 ) ;
F_46 ( L_62 ) ;
break;
}
F_122 ( 50 ) ;
}
if ( V_362 < 5 )
break;
}
if ( V_150 == 4 )
F_114 ( L_63 ) ;
F_46 ( L_65 ) ;
}
static void F_238 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_339 , V_150 , V_370 ;
V_88 = F_231 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_354 ;
V_339 &= ~ V_355 ;
F_45 ( V_88 , V_339 ) ;
F_121 ( V_88 ) ;
F_122 ( 150 ) ;
F_46 ( L_66 ,
F_5 ( F_234 ( V_4 ) ) ) ;
for ( V_370 = 0 ; V_370 < F_239 ( V_368 ) * 2 ; V_370 ++ ) {
V_88 = F_66 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ ( V_371 | V_340 ) ;
V_339 &= ~ V_125 ;
F_45 ( V_88 , V_339 ) ;
V_88 = F_68 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_371 ;
V_339 &= ~ V_343 ;
V_339 &= ~ V_126 ;
F_45 ( V_88 , V_339 ) ;
V_88 = F_66 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_356 ;
V_339 |= F_232 ( V_73 -> V_77 . V_357 ) ;
V_339 |= V_372 ;
V_339 &= ~ V_363 ;
V_339 |= V_368 [ V_370 / 2 ] ;
V_339 |= V_373 ;
F_45 ( V_88 , V_339 | V_125 ) ;
F_45 ( F_236 ( V_4 ) ,
V_365 | V_366 ) ;
V_88 = F_68 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 |= V_367 ;
V_339 |= V_373 ;
F_45 ( V_88 , V_339 | V_126 ) ;
F_121 ( V_88 ) ;
F_122 ( 1 ) ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
V_88 = F_234 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
F_46 ( L_59 , V_339 ) ;
if ( V_339 & V_355 ||
( F_5 ( V_88 ) & V_355 ) ) {
F_45 ( V_88 , V_339 | V_355 ) ;
F_46 ( L_67 ,
V_150 ) ;
break;
}
F_122 ( 1 ) ;
}
if ( V_150 == 4 ) {
F_46 ( L_68 , V_370 / 2 ) ;
continue;
}
V_88 = F_66 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_340 ;
V_339 |= V_374 ;
F_45 ( V_88 , V_339 ) ;
V_88 = F_68 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_343 ;
V_339 |= V_369 ;
F_45 ( V_88 , V_339 ) ;
F_121 ( V_88 ) ;
F_122 ( 2 ) ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
V_88 = F_234 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
F_46 ( L_59 , V_339 ) ;
if ( V_339 & V_354 ||
( F_5 ( V_88 ) & V_354 ) ) {
F_45 ( V_88 , V_339 | V_354 ) ;
F_46 ( L_69 ,
V_150 ) ;
goto V_375;
}
F_122 ( 2 ) ;
}
if ( V_150 == 4 )
F_46 ( L_70 , V_370 / 2 ) ;
}
V_375:
F_46 ( L_65 ) ;
}
static void F_240 ( struct V_73 * V_73 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_339 ;
V_88 = F_68 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ ( V_356 | ( 0x7 << 16 ) ) ;
V_339 |= F_232 ( V_73 -> V_77 . V_357 ) ;
V_339 |= ( F_5 ( F_51 ( V_4 ) ) & V_231 ) << 11 ;
F_45 ( V_88 , V_339 | V_128 ) ;
F_121 ( V_88 ) ;
F_122 ( 200 ) ;
V_339 = F_5 ( V_88 ) ;
F_45 ( V_88 , V_339 | V_376 ) ;
F_121 ( V_88 ) ;
F_122 ( 200 ) ;
V_88 = F_66 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
if ( ( V_339 & V_127 ) == 0 ) {
F_45 ( V_88 , V_339 | V_127 ) ;
F_121 ( V_88 ) ;
F_122 ( 100 ) ;
}
}
static void F_241 ( struct V_73 * V_73 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_339 ;
V_88 = F_68 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
F_45 ( V_88 , V_339 & ~ V_376 ) ;
V_88 = F_66 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
F_45 ( V_88 , V_339 & ~ V_127 ) ;
F_121 ( V_88 ) ;
F_122 ( 100 ) ;
V_88 = F_68 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
F_45 ( V_88 , V_339 & ~ V_128 ) ;
F_121 ( V_88 ) ;
F_122 ( 100 ) ;
}
static void F_242 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_339 ;
V_88 = F_66 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
F_45 ( V_88 , V_339 & ~ V_125 ) ;
F_121 ( V_88 ) ;
V_88 = F_68 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ ( 0x7 << 16 ) ;
V_339 |= ( F_5 ( F_51 ( V_4 ) ) & V_231 ) << 11 ;
F_45 ( V_88 , V_339 & ~ V_126 ) ;
F_121 ( V_88 ) ;
F_122 ( 100 ) ;
if ( F_53 ( V_10 ) )
F_45 ( F_233 ( V_4 ) , V_359 ) ;
V_88 = F_66 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ V_342 ;
V_339 |= V_358 ;
F_45 ( V_88 , V_339 ) ;
V_88 = F_68 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
if ( F_92 ( V_10 ) ) {
V_339 &= ~ V_343 ;
V_339 |= V_367 ;
} else {
V_339 &= ~ V_342 ;
V_339 |= V_358 ;
}
V_339 &= ~ ( 0x07 << 16 ) ;
V_339 |= ( F_5 ( F_51 ( V_4 ) ) & V_231 ) << 11 ;
F_45 ( V_88 , V_339 ) ;
F_121 ( V_88 ) ;
F_122 ( 100 ) ;
}
bool F_243 ( struct V_9 * V_10 )
{
struct V_73 * V_29 ;
F_244 (dev, crtc) {
if ( F_215 ( & V_29 -> V_377 ) == 0 )
continue;
if ( V_29 -> V_326 )
F_42 ( V_10 , V_29 -> V_4 ) ;
return true ;
}
return false ;
}
void F_245 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_29 -> V_75 -> V_76 == NULL )
return;
F_3 ( F_246 ( & V_12 -> V_378 ) ) ;
F_3 ( F_247 ( V_12 -> V_378 ,
! F_213 ( V_29 ) ,
60 * V_379 ) == 0 ) ;
F_58 ( & V_10 -> V_257 ) ;
F_211 ( V_29 -> V_75 -> V_76 ) ;
F_60 ( & V_10 -> V_257 ) ;
}
static void F_248 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int clock = F_35 ( V_29 ) -> V_77 . V_78 . V_79 ;
T_1 V_380 , V_381 , V_382 , V_383 = 0 ;
T_1 V_339 ;
F_58 ( & V_12 -> V_113 ) ;
F_45 ( V_384 , V_385 ) ;
F_249 ( V_12 , V_386 ,
F_250 ( V_12 , V_386 , V_387 ) |
V_388 ,
V_387 ) ;
if ( clock == 20000 ) {
V_382 = 1 ;
V_380 = 0x41 ;
V_381 = 0x20 ;
} else {
T_1 V_389 = 172800 * 1000 ;
T_1 V_390 = 64 ;
T_1 V_391 , V_392 , V_393 ;
V_391 = ( V_389 / clock ) ;
V_392 = V_391 / V_390 ;
V_393 = V_391 % V_390 ;
V_382 = 0 ;
V_380 = V_392 - 2 ;
V_381 = V_393 ;
}
F_3 ( F_251 ( V_380 ) &
~ V_394 ) ;
F_3 ( F_252 ( V_383 ) &
~ V_395 ) ;
F_46 ( L_71 ,
clock ,
V_382 ,
V_380 ,
V_383 ,
V_381 ) ;
V_339 = F_250 ( V_12 , V_396 , V_387 ) ;
V_339 &= ~ V_394 ;
V_339 |= F_251 ( V_380 ) ;
V_339 &= ~ V_395 ;
V_339 |= F_253 ( V_381 ) ;
V_339 |= F_252 ( V_383 ) ;
V_339 |= V_397 ;
F_249 ( V_12 , V_396 , V_339 , V_387 ) ;
V_339 = F_250 ( V_12 , V_398 , V_387 ) ;
V_339 &= ~ F_254 ( 1 ) ;
V_339 |= F_254 ( V_382 ) ;
F_249 ( V_12 , V_398 , V_339 , V_387 ) ;
V_339 = F_250 ( V_12 , V_386 , V_387 ) ;
V_339 &= ~ V_388 ;
F_249 ( V_12 , V_386 , V_339 , V_387 ) ;
F_122 ( 24 ) ;
F_45 ( V_384 , V_399 ) ;
F_60 ( & V_12 -> V_113 ) ;
}
static void F_255 ( struct V_73 * V_29 ,
enum V_4 V_243 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_80 V_82 = V_29 -> V_77 . V_82 ;
F_45 ( F_256 ( V_243 ) ,
F_5 ( F_257 ( V_82 ) ) ) ;
F_45 ( F_258 ( V_243 ) ,
F_5 ( F_259 ( V_82 ) ) ) ;
F_45 ( F_260 ( V_243 ) ,
F_5 ( F_261 ( V_82 ) ) ) ;
F_45 ( F_262 ( V_243 ) ,
F_5 ( F_263 ( V_82 ) ) ) ;
F_45 ( F_264 ( V_243 ) ,
F_5 ( F_265 ( V_82 ) ) ) ;
F_45 ( F_266 ( V_243 ) ,
F_5 ( F_267 ( V_82 ) ) ) ;
F_45 ( F_268 ( V_243 ) ,
F_5 ( F_269 ( V_82 ) ) ) ;
}
static void F_270 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_339 ;
V_339 = F_5 ( V_351 ) ;
if ( V_339 & V_352 )
return;
F_3 ( F_5 ( F_68 ( V_141 ) ) & V_126 ) ;
F_3 ( F_5 ( F_68 ( V_350 ) ) & V_126 ) ;
V_339 |= V_352 ;
F_46 ( L_72 ) ;
F_45 ( V_351 , V_339 ) ;
F_121 ( V_351 ) ;
}
static void F_271 ( struct V_73 * V_73 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
switch ( V_73 -> V_4 ) {
case V_132 :
break;
case V_141 :
if ( V_73 -> V_77 . V_357 > 2 )
F_3 ( F_5 ( V_351 ) & V_352 ) ;
else
F_270 ( V_10 ) ;
break;
case V_350 :
F_270 ( V_10 ) ;
break;
default:
F_134 () ;
}
}
static void F_272 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_339 ;
F_93 ( V_12 , V_4 ) ;
if ( F_227 ( V_10 ) )
F_271 ( V_73 ) ;
F_45 ( F_273 ( V_4 ) ,
F_5 ( F_274 ( V_4 ) ) & V_400 ) ;
V_12 -> V_315 . V_401 ( V_29 ) ;
if ( F_92 ( V_10 ) ) {
T_1 V_402 ;
V_339 = F_5 ( V_403 ) ;
V_339 |= F_275 ( V_4 ) ;
V_402 = F_276 ( V_4 ) ;
if ( V_73 -> V_77 . V_117 == V_404 )
V_339 |= V_402 ;
else
V_339 &= ~ V_402 ;
F_45 ( V_403 , V_339 ) ;
}
F_139 ( V_73 ) ;
F_71 ( V_12 , V_4 ) ;
F_255 ( V_73 , V_4 ) ;
F_226 ( V_29 ) ;
if ( F_92 ( V_10 ) &&
( F_10 ( V_29 , V_405 ) ||
F_10 ( V_29 , V_336 ) ) ) {
T_1 V_406 = ( F_5 ( F_51 ( V_4 ) ) & V_231 ) >> 5 ;
V_88 = F_96 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ ( V_167 |
V_407 |
V_408 ) ;
V_339 |= ( V_409 |
V_410 ) ;
V_339 |= V_406 << 9 ;
if ( V_29 -> V_411 . V_321 & V_412 )
V_339 |= V_413 ;
if ( V_29 -> V_411 . V_321 & V_414 )
V_339 |= V_415 ;
switch ( F_277 ( V_29 ) ) {
case V_181 :
V_339 |= V_182 ;
break;
case V_183 :
V_339 |= V_184 ;
break;
case V_185 :
V_339 |= V_186 ;
break;
default:
F_134 () ;
}
F_45 ( V_88 , V_339 ) ;
}
F_144 ( V_12 , V_4 ) ;
}
static void F_278 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_80 V_82 = V_73 -> V_77 . V_82 ;
F_93 ( V_12 , V_239 ) ;
F_248 ( V_29 ) ;
F_255 ( V_73 , V_132 ) ;
F_148 ( V_12 , V_82 ) ;
}
void F_279 ( struct V_73 * V_29 )
{
struct V_116 * V_119 = F_61 ( V_29 ) ;
if ( V_119 == NULL )
return;
if ( V_119 -> V_222 == 0 ) {
F_41 ( 1 , L_73 , V_119 -> V_123 ) ;
return;
}
if ( -- V_119 -> V_222 == 0 ) {
F_3 ( V_119 -> V_223 ) ;
F_3 ( V_119 -> V_74 ) ;
}
V_29 -> V_77 . V_117 = V_416 ;
}
struct V_116 * F_280 ( struct V_73 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
struct V_116 * V_119 = F_61 ( V_29 ) ;
enum V_417 V_150 ;
if ( V_119 ) {
F_46 ( L_74 ,
V_29 -> V_8 . V_8 . V_225 , V_119 -> V_123 ) ;
F_279 ( V_29 ) ;
}
if ( F_53 ( V_12 -> V_10 ) ) {
V_150 = (enum V_417 ) V_29 -> V_4 ;
V_119 = & V_12 -> V_118 [ V_150 ] ;
F_46 ( L_75 ,
V_29 -> V_8 . V_8 . V_225 , V_119 -> V_123 ) ;
F_3 ( V_119 -> V_222 ) ;
goto V_67;
}
for ( V_150 = 0 ; V_150 < V_12 -> V_418 ; V_150 ++ ) {
V_119 = & V_12 -> V_118 [ V_150 ] ;
if ( V_119 -> V_222 == 0 )
continue;
if ( memcmp ( & V_29 -> V_77 . V_200 , & V_119 -> V_121 ,
sizeof( V_119 -> V_121 ) ) == 0 ) {
F_46 ( L_76 ,
V_29 -> V_8 . V_8 . V_225 ,
V_119 -> V_123 , V_119 -> V_222 , V_119 -> V_74 ) ;
goto V_67;
}
}
for ( V_150 = 0 ; V_150 < V_12 -> V_418 ; V_150 ++ ) {
V_119 = & V_12 -> V_118 [ V_150 ] ;
if ( V_119 -> V_222 == 0 ) {
F_46 ( L_77 ,
V_29 -> V_8 . V_8 . V_225 , V_119 -> V_123 ) ;
goto V_67;
}
}
return NULL ;
V_67:
if ( V_119 -> V_222 == 0 )
V_119 -> V_121 = V_29 -> V_77 . V_200 ;
V_29 -> V_77 . V_117 = V_150 ;
F_137 ( L_78 , V_119 -> V_123 ,
F_72 ( V_29 -> V_4 ) ) ;
V_119 -> V_222 ++ ;
return V_119 ;
}
static void F_281 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_419 = F_48 ( V_4 ) ;
T_1 V_339 ;
V_339 = F_5 ( V_419 ) ;
F_122 ( 500 ) ;
if ( F_39 ( F_5 ( V_419 ) != V_339 , 5 ) ) {
if ( F_39 ( F_5 ( V_419 ) != V_339 , 5 ) )
F_114 ( L_79 , F_72 ( V_4 ) ) ;
}
}
static void F_282 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_77 . V_335 . V_108 ) {
if ( F_227 ( V_10 ) || F_202 ( V_10 ) )
F_45 ( F_221 ( V_4 ) , V_420 | V_421 |
F_283 ( V_4 ) ) ;
else
F_45 ( F_221 ( V_4 ) , V_420 | V_421 ) ;
F_45 ( F_222 ( V_4 ) , V_29 -> V_77 . V_335 . V_422 ) ;
F_45 ( F_223 ( V_4 ) , V_29 -> V_77 . V_335 . V_293 ) ;
}
}
static void F_284 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_4 V_4 = F_35 ( V_29 ) -> V_4 ;
struct V_423 * V_148 ;
struct V_424 * V_424 ;
F_285 (plane, &dev->mode_config.plane_list) {
V_424 = F_286 ( V_148 ) ;
if ( V_424 -> V_4 == V_4 )
F_287 ( & V_424 -> V_8 ) ;
}
}
static void F_288 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_4 V_4 = F_35 ( V_29 ) -> V_4 ;
struct V_423 * V_148 ;
struct V_424 * V_424 ;
F_285 (plane, &dev->mode_config.plane_list) {
V_424 = F_286 ( V_148 ) ;
if ( V_424 -> V_4 == V_4 )
F_289 ( & V_424 -> V_8 ) ;
}
}
void F_290 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_77 . V_425 )
return;
F_42 ( V_10 , V_29 -> V_4 ) ;
F_291 ( V_12 , V_29 -> V_148 ) ;
if ( F_165 ( V_10 ) ) {
F_58 ( & V_12 -> V_426 . V_427 ) ;
F_3 ( F_292 ( V_12 , V_428 , 0xc0000000 ) ) ;
F_60 ( & V_12 -> V_426 . V_427 ) ;
} else {
F_45 ( V_429 , V_430 ) ;
if ( F_39 ( F_40 ( V_429 ) & V_430 , 50 ) )
F_114 ( L_80 ) ;
}
}
void F_293 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_77 . V_425 )
return;
F_291 ( V_12 , V_29 -> V_148 ) ;
if ( F_165 ( V_10 ) ) {
F_58 ( & V_12 -> V_426 . V_427 ) ;
F_3 ( F_292 ( V_12 , V_428 , 0 ) ) ;
F_60 ( & V_12 -> V_426 . V_427 ) ;
if ( F_39 ( ( F_5 ( V_429 ) & V_430 ) == 0 , 42 ) )
F_114 ( L_81 ) ;
} else {
F_45 ( V_429 , 0 ) ;
F_121 ( V_429 ) ;
}
F_42 ( V_10 , V_29 -> V_4 ) ;
}
static void F_294 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_4 V_4 = V_73 -> V_4 ;
int V_431 = F_295 ( V_4 ) ;
int V_150 ;
bool V_432 = false ;
if ( ! V_29 -> V_108 || ! V_73 -> V_74 )
return;
if ( ! F_4 ( V_12 -> V_10 ) ) {
if ( F_10 ( V_29 , V_244 ) )
F_156 ( V_12 ) ;
else
F_157 ( V_12 , V_4 ) ;
}
if ( ! F_296 ( V_10 ) )
V_431 = F_297 ( V_4 ) ;
if ( F_202 ( V_10 ) && V_73 -> V_77 . V_425 &&
( ( F_5 ( F_298 ( V_4 ) ) & V_433 ) ==
V_434 ) ) {
F_293 ( V_73 ) ;
V_432 = true ;
}
for ( V_150 = 0 ; V_150 < 256 ; V_150 ++ ) {
F_45 ( V_431 + 4 * V_150 ,
( V_73 -> V_435 [ V_150 ] << 16 ) |
( V_73 -> V_436 [ V_150 ] << 8 ) |
V_73 -> V_437 [ V_150 ] ) ;
}
if ( V_432 )
F_290 ( V_73 ) ;
}
static void F_299 ( struct V_73 * V_73 , bool V_227 )
{
if ( ! V_227 && V_73 -> V_438 ) {
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_58 ( & V_10 -> V_257 ) ;
V_12 -> V_263 . V_264 = false ;
( void ) F_300 ( V_73 -> V_438 ) ;
V_12 -> V_263 . V_264 = true ;
F_60 ( & V_10 -> V_257 ) ;
}
}
static void F_301 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
int V_148 = V_73 -> V_148 ;
F_302 ( V_10 , V_4 ) ;
F_163 ( V_12 , V_148 , V_4 ) ;
F_284 ( V_29 ) ;
F_303 ( V_29 , true ) ;
F_299 ( V_73 , true ) ;
F_290 ( V_73 ) ;
F_58 ( & V_10 -> V_257 ) ;
F_225 ( V_10 ) ;
F_60 ( & V_10 -> V_257 ) ;
F_224 ( V_10 , F_304 ( V_4 ) ) ;
}
static void F_305 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
int V_148 = V_73 -> V_148 ;
F_245 ( V_29 ) ;
if ( V_12 -> V_439 . V_148 == V_148 )
F_306 ( V_10 ) ;
F_293 ( V_73 ) ;
F_299 ( V_73 , false ) ;
F_303 ( V_29 , false ) ;
F_288 ( V_29 ) ;
F_166 ( V_12 , V_148 , V_4 ) ;
F_224 ( V_10 , F_304 ( V_4 ) ) ;
F_307 ( V_10 , V_4 ) ;
}
static void F_308 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_73 -> V_4 ;
enum V_148 V_148 = V_73 -> V_148 ;
F_3 ( ! V_29 -> V_108 ) ;
if ( V_73 -> V_74 )
return;
if ( V_73 -> V_77 . V_245 )
F_136 ( V_73 ) ;
if ( V_73 -> V_77 . V_440 )
F_309 ( V_73 ) ;
F_310 ( V_73 ) ;
if ( V_73 -> V_77 . V_245 ) {
F_311 ( V_73 ,
& V_73 -> V_77 . V_441 ) ;
}
F_312 ( V_29 ) ;
F_45 ( F_81 ( V_148 ) , V_442 ) ;
F_121 ( F_81 ( V_148 ) ) ;
V_12 -> V_315 . V_317 ( V_29 , V_29 -> V_75 -> V_76 ,
V_29 -> V_267 , V_29 -> V_268 ) ;
V_73 -> V_74 = true ;
F_313 ( V_10 , V_4 , true ) ;
F_314 ( V_10 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_443 )
V_6 -> V_443 ( V_6 ) ;
if ( V_73 -> V_77 . V_245 ) {
F_240 ( V_73 ) ;
} else {
F_150 ( V_12 , V_4 ) ;
F_151 ( V_12 , V_4 ) ;
}
F_282 ( V_73 ) ;
F_294 ( V_29 ) ;
F_315 ( V_29 ) ;
F_153 ( V_73 ) ;
if ( V_73 -> V_77 . V_245 )
F_272 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_227 ( V_6 ) ;
if ( F_92 ( V_10 ) )
F_281 ( V_10 , V_73 -> V_4 ) ;
F_301 ( V_29 ) ;
}
static bool F_316 ( struct V_73 * V_29 )
{
return F_317 ( V_29 -> V_8 . V_10 ) && V_29 -> V_4 == V_132 ;
}
static void F_318 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_73 * V_444 , * V_445 = NULL ;
F_244 (dev, crtc_it) {
if ( ! V_444 -> V_74 || V_444 == V_29 )
continue;
if ( V_445 )
return;
V_445 = V_444 ;
}
if ( ! V_445 )
return;
F_42 ( V_10 , V_445 -> V_4 ) ;
F_42 ( V_10 , V_445 -> V_4 ) ;
}
static void F_319 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_73 -> V_4 ;
enum V_148 V_148 = V_73 -> V_148 ;
F_3 ( ! V_29 -> V_108 ) ;
if ( V_73 -> V_74 )
return;
if ( F_61 ( V_73 ) )
F_139 ( V_73 ) ;
if ( V_73 -> V_77 . V_440 )
F_309 ( V_73 ) ;
F_310 ( V_73 ) ;
if ( V_73 -> V_77 . V_245 ) {
F_311 ( V_73 ,
& V_73 -> V_77 . V_441 ) ;
}
F_320 ( V_29 ) ;
F_321 ( V_29 ) ;
F_45 ( F_81 ( V_148 ) , V_442 | V_446 ) ;
F_121 ( F_81 ( V_148 ) ) ;
V_12 -> V_315 . V_317 ( V_29 , V_29 -> V_75 -> V_76 ,
V_29 -> V_267 , V_29 -> V_268 ) ;
V_73 -> V_74 = true ;
F_313 ( V_10 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_443 )
V_6 -> V_443 ( V_6 ) ;
if ( V_73 -> V_77 . V_245 ) {
F_314 ( V_10 , V_239 , true ) ;
V_12 -> V_315 . V_401 ( V_29 ) ;
}
F_322 ( V_73 ) ;
F_282 ( V_73 ) ;
F_294 ( V_29 ) ;
F_323 ( V_29 ) ;
F_324 ( V_29 ) ;
F_315 ( V_29 ) ;
F_153 ( V_73 ) ;
if ( V_73 -> V_77 . V_245 )
F_278 ( V_29 ) ;
if ( V_73 -> V_77 . V_447 )
F_325 ( V_29 , true ) ;
F_11 (dev, crtc, encoder) {
V_6 -> V_227 ( V_6 ) ;
F_326 ( V_6 , true ) ;
}
F_318 ( V_73 ) ;
F_301 ( V_29 ) ;
}
static void F_327 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_77 . V_335 . V_108 ) {
F_45 ( F_221 ( V_4 ) , 0 ) ;
F_45 ( F_222 ( V_4 ) , 0 ) ;
F_45 ( F_223 ( V_4 ) , 0 ) ;
}
}
static void F_328 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_339 ;
if ( ! V_73 -> V_74 )
return;
F_305 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_228 ( V_6 ) ;
if ( V_73 -> V_77 . V_245 )
F_314 ( V_10 , V_4 , false ) ;
F_159 ( V_12 , V_4 ) ;
F_327 ( V_73 ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_448 )
V_6 -> V_448 ( V_6 ) ;
if ( V_73 -> V_77 . V_245 ) {
F_242 ( V_29 ) ;
F_149 ( V_12 , V_4 ) ;
F_314 ( V_10 , V_4 , true ) ;
if ( F_92 ( V_10 ) ) {
V_88 = F_96 ( V_4 ) ;
V_339 = F_5 ( V_88 ) ;
V_339 &= ~ ( V_409 |
V_167 ) ;
V_339 |= V_449 ;
F_45 ( V_88 , V_339 ) ;
V_339 = F_5 ( V_403 ) ;
V_339 &= ~ ( F_275 ( V_4 ) | F_276 ( V_4 ) ) ;
F_45 ( V_403 , V_339 ) ;
}
F_142 ( V_73 ) ;
F_241 ( V_73 ) ;
}
V_73 -> V_74 = false ;
F_315 ( V_29 ) ;
F_58 ( & V_10 -> V_257 ) ;
F_225 ( V_10 ) ;
F_60 ( & V_10 -> V_257 ) ;
}
static void F_329 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_73 -> V_4 ;
enum V_80 V_82 = V_73 -> V_77 . V_82 ;
if ( ! V_73 -> V_74 )
return;
F_305 ( V_29 ) ;
F_11 (dev, crtc, encoder) {
F_326 ( V_6 , false ) ;
V_6 -> V_228 ( V_6 ) ;
}
if ( V_73 -> V_77 . V_245 )
F_314 ( V_10 , V_239 , false ) ;
F_159 ( V_12 , V_4 ) ;
if ( V_73 -> V_77 . V_447 )
F_325 ( V_29 , false ) ;
F_330 ( V_12 , V_82 ) ;
F_327 ( V_73 ) ;
F_331 ( V_73 ) ;
if ( V_73 -> V_77 . V_245 ) {
F_152 ( V_12 ) ;
F_314 ( V_10 , V_239 , true ) ;
F_332 ( V_29 ) ;
}
F_11 (dev, crtc, encoder)
if ( V_6 -> V_448 )
V_6 -> V_448 ( V_6 ) ;
V_73 -> V_74 = false ;
F_315 ( V_29 ) ;
F_58 ( & V_10 -> V_257 ) ;
F_225 ( V_10 ) ;
F_60 ( & V_10 -> V_257 ) ;
if ( F_61 ( V_73 ) )
F_142 ( V_73 ) ;
}
static void F_333 ( struct V_28 * V_29 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
F_279 ( V_73 ) ;
}
static void F_334 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_450 * V_451 = & V_29 -> V_77 ;
if ( ! V_29 -> V_77 . V_452 . V_453 )
return;
F_3 ( F_5 ( V_454 ) & V_455 ) ;
F_117 ( V_12 , V_29 -> V_4 ) ;
F_45 ( V_456 , V_451 -> V_452 . V_457 ) ;
F_45 ( V_454 , V_451 -> V_452 . V_453 ) ;
F_45 ( F_335 ( V_29 -> V_4 ) , 0 ) ;
}
static enum V_458 F_336 ( enum V_96 V_96 )
{
switch ( V_96 ) {
case V_459 :
return V_460 ;
case V_98 :
return V_461 ;
case V_100 :
return V_462 ;
case V_102 :
return V_463 ;
default:
F_337 ( 1 ) ;
return V_464 ;
}
}
enum V_458
F_338 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_8 . V_10 ;
struct V_95 * V_465 ;
switch ( V_1 -> type ) {
case V_466 :
F_337 ( ! F_64 ( V_10 ) ) ;
case V_405 :
case V_39 :
case V_336 :
V_465 = F_339 ( & V_1 -> V_8 ) ;
return F_336 ( V_465 -> V_96 ) ;
case V_467 :
V_465 = F_340 ( & V_1 -> V_8 ) -> V_75 ;
return F_336 ( V_465 -> V_96 ) ;
case V_40 :
return V_468 ;
case V_244 :
return V_469 ;
default:
return V_464 ;
}
}
static unsigned long F_341 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_1 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_4 V_4 = V_73 -> V_4 ;
unsigned long V_470 ;
enum V_80 V_80 ;
V_80 = F_36 ( V_10 -> V_13 , V_4 ) ;
V_470 = F_342 ( F_343 ( V_4 ) ) ;
V_470 |= F_342 ( F_79 ( V_80 ) ) ;
if ( V_73 -> V_77 . V_335 . V_108 ||
V_73 -> V_77 . V_335 . V_471 )
V_470 |= F_342 ( F_344 ( V_4 ) ) ;
F_11 (dev, crtc, intel_encoder)
V_470 |= F_342 ( F_338 ( V_1 ) ) ;
return V_470 ;
}
void F_345 ( struct V_11 * V_12 ,
bool V_227 )
{
if ( V_12 -> V_472 . V_473 == V_227 )
return;
if ( V_227 )
F_141 ( V_12 , V_474 ) ;
else
F_143 ( V_12 , V_474 ) ;
V_12 -> V_472 . V_473 = V_227 ;
}
static void F_346 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned long V_475 [ V_476 ] = { 0 , } ;
struct V_73 * V_29 ;
F_244 (dev, crtc) {
enum V_458 V_477 ;
if ( ! V_29 -> V_8 . V_108 )
continue;
V_475 [ V_29 -> V_4 ] = F_341 ( & V_29 -> V_8 ) ;
F_347 (domain, pipe_domains[crtc->pipe])
F_141 ( V_12 , V_477 ) ;
}
F_244 (dev, crtc) {
enum V_458 V_477 ;
F_347 (domain, crtc->enabled_power_domains)
F_143 ( V_12 , V_477 ) ;
V_29 -> V_478 = V_475 [ V_29 -> V_4 ] ;
}
F_345 ( V_12 , false ) ;
}
static int F_348 ( struct V_11 * V_12 )
{
int V_479 , V_480 [] = { 800 , 1600 , 2000 , 2400 } ;
F_58 ( & V_12 -> V_113 ) ;
V_479 = F_59 ( V_12 , V_481 ) &
V_482 ;
F_60 ( & V_12 -> V_113 ) ;
return V_480 [ V_479 ] * 1000 ;
}
static void F_349 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_483 = V_12 -> V_315 . V_484 ( V_10 ) ;
F_137 ( L_82 ,
V_12 -> V_483 ) ;
F_45 ( V_485 , V_12 -> V_483 ) ;
}
static void F_350 ( struct V_9 * V_10 , int V_486 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_110 , V_487 ;
F_3 ( V_12 -> V_315 . V_484 ( V_10 ) != V_12 -> V_483 ) ;
if ( V_486 >= 320000 )
V_487 = 2 ;
else if ( V_486 == 266667 )
V_487 = 1 ;
else
V_487 = 0 ;
F_58 ( & V_12 -> V_426 . V_427 ) ;
V_110 = F_351 ( V_12 , V_488 ) ;
V_110 &= ~ V_489 ;
V_110 |= ( V_487 << V_490 ) ;
F_352 ( V_12 , V_488 , V_110 ) ;
if ( F_39 ( ( F_351 ( V_12 , V_488 ) &
V_491 ) == ( V_487 << V_492 ) ,
50 ) ) {
F_114 ( L_83 ) ;
}
F_60 ( & V_12 -> V_426 . V_427 ) ;
if ( V_486 == 400000 ) {
T_1 V_493 , V_26 ;
V_26 = F_348 ( V_12 ) ;
V_493 = F_9 ( V_26 << 1 , V_486 ) - 1 ;
F_58 ( & V_12 -> V_113 ) ;
V_110 = F_59 ( V_12 , V_494 ) ;
V_110 &= ~ V_495 ;
V_110 |= V_493 ;
F_353 ( V_12 , V_494 , V_110 ) ;
if ( F_39 ( ( F_59 ( V_12 , V_494 ) &
V_496 ) == ( V_493 << V_497 ) ,
50 ) )
F_114 ( L_83 ) ;
F_60 ( & V_12 -> V_113 ) ;
}
F_58 ( & V_12 -> V_113 ) ;
V_110 = F_354 ( V_12 , V_498 ) ;
V_110 &= ~ 0x7f ;
if ( V_486 == 400000 )
V_110 |= 4500 / 250 ;
else
V_110 |= 3000 / 250 ;
F_355 ( V_12 , V_498 , V_110 ) ;
F_60 ( & V_12 -> V_113 ) ;
F_349 ( V_10 ) ;
}
static int F_356 ( struct V_11 * V_12 ,
int V_499 )
{
int V_26 = F_348 ( V_12 ) ;
int V_500 = ( V_26 << 1 ) % 320000 != 0 ? 333333 : 320000 ;
if ( V_499 > V_500 * 9 / 10 )
return 400000 ;
else if ( V_499 > 266667 * 9 / 10 )
return V_500 ;
else if ( V_499 > 0 )
return 266667 ;
else
return 200000 ;
}
static int F_357 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_73 * V_73 ;
int V_499 = 0 ;
F_244 (dev, intel_crtc) {
if ( V_73 -> V_501 )
V_499 = V_57 ( V_499 ,
V_73 -> V_502 -> V_78 . V_79 ) ;
}
return V_499 ;
}
static void F_358 ( struct V_9 * V_10 ,
unsigned * V_503 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 ;
int V_499 = F_357 ( V_12 ) ;
if ( F_356 ( V_12 , V_499 ) ==
V_12 -> V_483 )
return;
F_244 (dev, intel_crtc)
if ( V_73 -> V_8 . V_108 )
* V_503 |= ( 1 << V_73 -> V_4 ) ;
}
static void F_359 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_499 = F_357 ( V_12 ) ;
int V_504 = F_356 ( V_12 , V_499 ) ;
if ( V_504 != V_12 -> V_483 )
F_350 ( V_10 , V_504 ) ;
F_346 ( V_10 ) ;
}
static void F_360 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_73 -> V_4 ;
int V_148 = V_73 -> V_148 ;
bool V_505 ;
T_1 V_303 ;
F_3 ( ! V_29 -> V_108 ) ;
if ( V_73 -> V_74 )
return;
V_505 = F_10 ( V_29 , V_244 ) ;
if ( ! V_505 && ! F_18 ( V_10 ) )
F_361 ( V_73 ) ;
V_303 = V_442 ;
if ( V_73 -> V_77 . V_440 )
F_309 ( V_73 ) ;
F_310 ( V_73 ) ;
F_45 ( F_362 ( V_148 ) ,
( ( V_73 -> V_77 . V_338 - 1 ) << 16 ) |
( V_73 -> V_77 . V_337 - 1 ) ) ;
F_45 ( F_363 ( V_148 ) , 0 ) ;
F_364 ( V_73 ) ;
F_45 ( F_81 ( V_148 ) , V_303 ) ;
F_121 ( F_81 ( V_148 ) ) ;
V_12 -> V_315 . V_317 ( V_29 , V_29 -> V_75 -> V_76 ,
V_29 -> V_267 , V_29 -> V_268 ) ;
V_73 -> V_74 = true ;
F_313 ( V_10 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_506 )
V_6 -> V_506 ( V_6 ) ;
if ( ! V_505 ) {
if ( F_18 ( V_10 ) )
F_124 ( V_73 ) ;
else
F_116 ( V_73 ) ;
}
F_11 (dev, crtc, encoder)
if ( V_6 -> V_443 )
V_6 -> V_443 ( V_6 ) ;
F_334 ( V_73 ) ;
F_294 ( V_29 ) ;
F_315 ( V_29 ) ;
F_153 ( V_73 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_227 ( V_6 ) ;
F_301 ( V_29 ) ;
F_365 ( V_10 ) ;
}
static void F_366 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_45 ( F_367 ( V_29 -> V_4 ) , V_29 -> V_77 . V_200 . V_507 ) ;
F_45 ( F_368 ( V_29 -> V_4 ) , V_29 -> V_77 . V_200 . V_508 ) ;
}
static void F_369 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_73 -> V_4 ;
int V_148 = V_73 -> V_148 ;
T_1 V_303 ;
F_3 ( ! V_29 -> V_108 ) ;
if ( V_73 -> V_74 )
return;
F_366 ( V_73 ) ;
V_303 = V_442 ;
if ( V_4 == 0 )
V_303 &= ~ V_152 ;
else
V_303 |= V_509 ;
if ( V_73 -> V_77 . V_440 )
F_309 ( V_73 ) ;
F_310 ( V_73 ) ;
F_45 ( F_362 ( V_148 ) ,
( ( V_73 -> V_77 . V_338 - 1 ) << 16 ) |
( V_73 -> V_77 . V_337 - 1 ) ) ;
F_45 ( F_363 ( V_148 ) , 0 ) ;
F_364 ( V_73 ) ;
F_45 ( F_81 ( V_148 ) , V_303 ) ;
F_121 ( F_81 ( V_148 ) ) ;
V_12 -> V_315 . V_317 ( V_29 , V_29 -> V_75 -> V_76 ,
V_29 -> V_267 , V_29 -> V_268 ) ;
V_73 -> V_74 = true ;
if ( ! F_20 ( V_10 ) )
F_313 ( V_10 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_443 )
V_6 -> V_443 ( V_6 ) ;
F_129 ( V_73 ) ;
F_334 ( V_73 ) ;
F_294 ( V_29 ) ;
F_315 ( V_29 ) ;
F_153 ( V_73 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_227 ( V_6 ) ;
F_301 ( V_29 ) ;
if ( F_20 ( V_10 ) )
F_313 ( V_10 , V_4 , true ) ;
F_365 ( V_10 ) ;
}
static void F_370 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_77 . V_452 . V_453 )
return;
F_117 ( V_12 , V_29 -> V_4 ) ;
F_137 ( L_84 ,
F_5 ( V_454 ) ) ;
F_45 ( V_454 , 0 ) ;
}
static void F_371 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_73 -> V_4 ;
if ( ! V_73 -> V_74 )
return;
if ( F_20 ( V_10 ) )
F_313 ( V_10 , V_4 , false ) ;
F_372 ( V_12 , false ) ;
F_305 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_228 ( V_6 ) ;
F_42 ( V_10 , V_4 ) ;
F_159 ( V_12 , V_4 ) ;
F_370 ( V_73 ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_448 )
V_6 -> V_448 ( V_6 ) ;
if ( ! F_10 ( V_29 , V_244 ) ) {
if ( F_18 ( V_10 ) )
F_132 ( V_12 , V_4 ) ;
else if ( F_19 ( V_10 ) )
F_131 ( V_12 , V_4 ) ;
else
F_130 ( V_12 , V_4 ) ;
}
if ( ! F_20 ( V_10 ) )
F_313 ( V_10 , V_4 , false ) ;
V_73 -> V_74 = false ;
F_315 ( V_29 ) ;
F_58 ( & V_10 -> V_257 ) ;
F_225 ( V_10 ) ;
F_60 ( & V_10 -> V_257 ) ;
}
static void F_373 ( struct V_28 * V_29 )
{
}
static void F_374 ( struct V_28 * V_29 ,
bool V_108 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_510 * V_511 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
if ( ! V_10 -> V_75 -> V_512 )
return;
V_511 = V_10 -> V_75 -> V_512 -> V_513 ;
if ( ! V_511 -> V_514 )
return;
switch ( V_4 ) {
case 0 :
V_511 -> V_514 -> V_515 = V_108 ? V_29 -> V_411 . V_516 : 0 ;
V_511 -> V_514 -> V_517 = V_108 ? V_29 -> V_411 . V_518 : 0 ;
break;
case 1 :
V_511 -> V_514 -> V_519 = V_108 ? V_29 -> V_411 . V_516 : 0 ;
V_511 -> V_514 -> V_520 = V_108 ? V_29 -> V_411 . V_518 : 0 ;
break;
default:
F_114 ( L_85 , F_72 ( V_4 ) ) ;
break;
}
}
void F_375 ( struct V_28 * V_29 , bool V_227 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_458 V_477 ;
unsigned long V_521 ;
if ( V_227 ) {
if ( ! V_73 -> V_74 ) {
V_521 = F_341 ( V_29 ) ;
F_347 (domain, domains)
F_141 ( V_12 , V_477 ) ;
V_73 -> V_478 = V_521 ;
V_12 -> V_315 . V_522 ( V_29 ) ;
}
} else {
if ( V_73 -> V_74 ) {
V_12 -> V_315 . V_523 ( V_29 ) ;
V_521 = V_73 -> V_478 ;
F_347 (domain, domains)
F_143 ( V_12 , V_477 ) ;
V_73 -> V_478 = 0 ;
}
}
}
void F_376 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_1 ;
bool V_227 = false ;
F_11 (dev, crtc, intel_encoder)
V_227 |= V_1 -> V_524 ;
F_375 ( V_29 , V_227 ) ;
F_374 ( V_29 , V_227 ) ;
}
static void F_377 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_525 * V_3 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_251 * V_327 = F_194 ( V_29 -> V_75 -> V_76 ) ;
enum V_4 V_4 = F_35 ( V_29 ) -> V_4 ;
F_3 ( ! V_29 -> V_108 ) ;
V_12 -> V_315 . V_523 ( V_29 ) ;
F_374 ( V_29 , false ) ;
V_12 -> V_315 . V_526 ( V_29 ) ;
if ( V_29 -> V_75 -> V_76 ) {
F_58 ( & V_10 -> V_257 ) ;
F_181 ( V_327 ) ;
F_219 ( V_327 , NULL ,
F_189 ( V_4 ) ) ;
F_60 ( & V_10 -> V_257 ) ;
V_29 -> V_75 -> V_76 = NULL ;
}
F_378 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_3 -> V_6 || ! V_3 -> V_6 -> V_29 )
continue;
if ( V_3 -> V_6 -> V_29 != V_29 )
continue;
V_3 -> V_527 = V_528 ;
F_379 ( V_3 -> V_6 ) -> V_524 = false ;
}
}
void F_380 ( struct V_529 * V_6 )
{
struct V_1 * V_1 = F_379 ( V_6 ) ;
F_381 ( V_6 ) ;
F_192 ( V_1 ) ;
}
static void F_382 ( struct V_1 * V_6 , int V_411 )
{
if ( V_411 == V_530 ) {
V_6 -> V_524 = true ;
F_376 ( V_6 -> V_8 . V_29 ) ;
} else {
V_6 -> V_524 = false ;
F_376 ( V_6 -> V_8 . V_29 ) ;
}
}
static void F_383 ( struct V_2 * V_3 )
{
if ( V_3 -> V_122 ( V_3 ) ) {
struct V_1 * V_6 = V_3 -> V_6 ;
struct V_28 * V_29 ;
bool V_531 ;
enum V_4 V_4 ;
F_46 ( L_86 ,
V_3 -> V_8 . V_8 . V_225 ,
V_3 -> V_8 . V_123 ) ;
if ( V_3 -> V_5 )
return;
F_41 ( V_3 -> V_8 . V_527 == V_528 ,
L_87 ) ;
F_41 ( V_3 -> V_8 . V_6 != & V_6 -> V_8 ,
L_88 ) ;
if ( V_6 ) {
F_41 ( ! V_6 -> V_524 ,
L_89 ) ;
V_531 = V_6 -> V_122 ( V_6 , & V_4 ) ;
F_41 ( ! V_531 , L_90 ) ;
if ( F_3 ( ! V_6 -> V_8 . V_29 ) )
return;
V_29 = V_6 -> V_8 . V_29 ;
F_41 ( ! V_29 -> V_108 , L_91 ) ;
F_41 ( ! F_35 ( V_29 ) -> V_74 , L_92 ) ;
F_41 ( V_4 != F_35 ( V_29 ) -> V_4 ,
L_93 ) ;
}
}
}
void F_384 ( struct V_525 * V_3 , int V_411 )
{
if ( V_411 != V_530 )
V_411 = V_528 ;
if ( V_411 == V_3 -> V_527 )
return;
V_3 -> V_527 = V_411 ;
if ( V_3 -> V_6 )
F_382 ( F_379 ( V_3 -> V_6 ) , V_411 ) ;
F_385 ( V_3 -> V_10 ) ;
}
bool F_386 ( struct V_2 * V_3 )
{
enum V_4 V_4 = 0 ;
struct V_1 * V_6 = V_3 -> V_6 ;
return V_6 -> V_122 ( V_6 , & V_4 ) ;
}
static bool F_387 ( struct V_9 * V_10 , enum V_4 V_4 ,
struct V_450 * V_451 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_348 =
F_35 ( V_12 -> V_81 [ V_141 ] ) ;
F_46 ( L_94 ,
F_72 ( V_4 ) , V_451 -> V_357 ) ;
if ( V_451 -> V_357 > 4 ) {
F_46 ( L_95 ,
F_72 ( V_4 ) , V_451 -> V_357 ) ;
return false ;
}
if ( F_202 ( V_10 ) || F_165 ( V_10 ) ) {
if ( V_451 -> V_357 > 2 ) {
F_46 ( L_96 ,
V_451 -> V_357 ) ;
return false ;
} else {
return true ;
}
}
if ( F_44 ( V_10 ) -> V_329 == 2 )
return true ;
switch ( V_4 ) {
case V_132 :
return true ;
case V_141 :
if ( V_12 -> V_81 [ V_350 ] -> V_108 &&
V_451 -> V_357 > 2 ) {
F_46 ( L_97 ,
F_72 ( V_4 ) , V_451 -> V_357 ) ;
return false ;
}
return true ;
case V_350 :
if ( ! F_228 ( V_348 ) ||
V_348 -> V_77 . V_357 <= 2 ) {
if ( V_451 -> V_357 > 2 ) {
F_46 ( L_97 ,
F_72 ( V_4 ) , V_451 -> V_357 ) ;
return false ;
}
} else {
F_46 ( L_98 ) ;
return false ;
}
return true ;
default:
F_134 () ;
}
}
static int F_388 ( struct V_73 * V_73 ,
struct V_450 * V_451 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_332 * V_78 = & V_451 -> V_78 ;
int V_532 , V_533 , V_534 ;
bool V_535 , V_536 = false ;
V_362:
V_533 = F_6 ( V_10 ) * F_389 ( 100 ) / F_390 ( 1 ) / 10 ;
V_534 = V_78 -> V_79 ;
V_532 = F_391 ( V_534 , V_533 ,
V_451 -> V_537 ) ;
V_451 -> V_357 = V_532 ;
F_392 ( V_451 -> V_537 , V_532 , V_534 ,
V_533 , & V_451 -> V_441 ) ;
V_535 = F_387 ( V_73 -> V_8 . V_10 ,
V_73 -> V_4 , V_451 ) ;
if ( ! V_535 && V_451 -> V_537 > 6 * 3 ) {
V_451 -> V_537 -= 2 * 3 ;
F_46 ( L_99 ,
V_451 -> V_537 ) ;
V_536 = true ;
V_451 -> V_538 = true ;
goto V_362;
}
if ( V_536 )
return V_539 ;
return V_535 ? 0 : - V_262 ;
}
static void F_393 ( struct V_73 * V_29 ,
struct V_450 * V_451 )
{
V_451 -> V_425 = V_330 . V_540 &&
F_316 ( V_29 ) &&
V_451 -> V_537 <= 24 ;
}
static int F_394 ( struct V_73 * V_29 ,
struct V_450 * V_451 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_332 * V_78 = & V_451 -> V_78 ;
if ( F_44 ( V_10 ) -> V_86 < 4 ) {
struct V_11 * V_12 = V_10 -> V_13 ;
int V_541 =
V_12 -> V_315 . V_484 ( V_10 ) ;
if ( ( V_29 -> V_4 == V_132 || F_395 ( V_10 ) ) &&
V_78 -> V_79 > V_541 * 9 / 10 ) {
V_541 *= 2 ;
V_451 -> V_542 = true ;
}
if ( V_78 -> V_79 > V_541 * 9 / 10 )
return - V_262 ;
}
if ( ( F_10 ( & V_29 -> V_8 , V_31 ) &&
F_13 ( V_10 ) ) || V_451 -> V_542 )
V_451 -> V_337 &= ~ 1 ;
if ( ( F_44 ( V_10 ) -> V_86 > 4 || F_16 ( V_10 ) ) &&
V_78 -> V_543 == V_78 -> V_516 )
return - V_262 ;
if ( ( F_16 ( V_10 ) || F_19 ( V_10 ) ) && V_451 -> V_537 > 10 * 3 ) {
V_451 -> V_537 = 10 * 3 ;
} else if ( F_44 ( V_10 ) -> V_86 <= 4 && V_451 -> V_537 > 8 * 3 ) {
V_451 -> V_537 = 8 * 3 ;
}
if ( F_317 ( V_10 ) )
F_393 ( V_29 , V_451 ) ;
if ( F_53 ( V_10 ) || F_92 ( V_10 ) || F_64 ( V_10 ) )
V_451 -> V_117 = V_29 -> V_77 . V_117 ;
if ( V_451 -> V_245 )
return F_388 ( V_29 , V_451 ) ;
return 0 ;
}
static int F_396 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_26 = F_348 ( V_12 ) ;
T_1 V_110 ;
int V_493 ;
F_58 ( & V_12 -> V_113 ) ;
V_110 = F_59 ( V_12 , V_494 ) ;
F_60 ( & V_12 -> V_113 ) ;
V_493 = V_110 & V_495 ;
F_41 ( ( V_110 & V_496 ) !=
( V_493 << V_497 ) ,
L_100 ) ;
return F_9 ( V_26 << 1 , V_493 + 1 ) ;
}
static int F_397 ( struct V_9 * V_10 )
{
return 400000 ;
}
static int F_398 ( struct V_9 * V_10 )
{
return 333000 ;
}
static int F_399 ( struct V_9 * V_10 )
{
return 200000 ;
}
static int F_400 ( struct V_9 * V_10 )
{
T_5 V_544 = 0 ;
F_401 ( V_10 -> V_545 , V_546 , & V_544 ) ;
switch ( V_544 & V_547 ) {
case V_548 :
return 267000 ;
case V_549 :
return 333000 ;
case V_550 :
return 444000 ;
case V_551 :
return 200000 ;
default:
F_114 ( L_101 , V_544 ) ;
case V_552 :
return 133000 ;
case V_553 :
return 167000 ;
}
}
static int F_402 ( struct V_9 * V_10 )
{
T_5 V_544 = 0 ;
F_401 ( V_10 -> V_545 , V_546 , & V_544 ) ;
if ( V_544 & V_554 )
return 133000 ;
else {
switch ( V_544 & V_547 ) {
case V_555 :
return 333000 ;
default:
case V_556 :
return 190000 ;
}
}
}
static int F_403 ( struct V_9 * V_10 )
{
return 266000 ;
}
static int F_404 ( struct V_9 * V_10 )
{
T_5 V_557 = 0 ;
switch ( V_557 & V_558 ) {
case V_559 :
case V_560 :
return 200000 ;
case V_561 :
return 250000 ;
case V_562 :
return 133000 ;
}
return 0 ;
}
static int F_405 ( struct V_9 * V_10 )
{
return 133000 ;
}
static void
F_406 ( T_4 * V_563 , T_4 * V_564 )
{
while ( * V_563 > V_565 ||
* V_564 > V_565 ) {
* V_563 >>= 1 ;
* V_564 >>= 1 ;
}
}
static void F_407 ( unsigned int V_19 , unsigned int V_25 ,
T_4 * V_566 , T_4 * V_567 )
{
* V_567 = F_408 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_566 = F_32 ( ( V_55 ) V_19 * * V_567 , V_25 ) ;
F_406 ( V_566 , V_567 ) ;
}
void
F_392 ( int V_312 , int V_568 ,
int V_569 , int V_570 ,
struct V_571 * V_572 )
{
V_572 -> V_573 = 64 ;
F_407 ( V_312 * V_569 ,
V_570 * V_568 * 8 ,
& V_572 -> V_574 , & V_572 -> V_575 ) ;
F_407 ( V_569 , V_570 ,
& V_572 -> V_576 , & V_572 -> V_577 ) ;
}
static inline bool F_409 ( struct V_11 * V_12 )
{
if ( V_330 . V_578 >= 0 )
return V_330 . V_578 != 0 ;
return V_12 -> V_579 . V_580
&& ! ( V_12 -> V_145 & V_581 ) ;
}
static int F_410 ( struct V_28 * V_29 , int V_582 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_18 ;
if ( F_19 ( V_10 ) ) {
V_18 = 100000 ;
} else if ( F_10 ( V_29 , V_31 ) &&
F_409 ( V_12 ) && V_582 < 2 ) {
V_18 = V_12 -> V_579 . V_583 ;
F_46 ( L_102 , V_18 ) ;
} else if ( ! F_20 ( V_10 ) ) {
V_18 = 96000 ;
} else {
V_18 = 48000 ;
}
return V_18 ;
}
static T_4 F_411 ( struct V_54 * V_54 )
{
return ( 1 << V_54 -> V_25 ) << 16 | V_54 -> V_21 ;
}
static T_4 F_412 ( struct V_54 * V_54 )
{
return V_54 -> V_25 << 16 | V_54 -> V_20 << 8 | V_54 -> V_21 ;
}
static void F_413 ( struct V_73 * V_29 ,
T_2 * V_584 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_1 V_585 , V_586 = 0 ;
if ( F_17 ( V_10 ) ) {
V_585 = F_411 ( & V_29 -> V_77 . V_54 ) ;
if ( V_584 )
V_586 = F_411 ( V_584 ) ;
} else {
V_585 = F_412 ( & V_29 -> V_77 . V_54 ) ;
if ( V_584 )
V_586 = F_412 ( V_584 ) ;
}
V_29 -> V_77 . V_200 . V_507 = V_585 ;
V_29 -> V_587 = false ;
if ( F_10 ( & V_29 -> V_8 , V_31 ) &&
V_584 && V_330 . V_588 ) {
V_29 -> V_77 . V_200 . V_508 = V_586 ;
V_29 -> V_587 = true ;
} else {
V_29 -> V_77 . V_200 . V_508 = V_585 ;
}
}
static void F_414 ( struct V_11 * V_12 , enum V_4
V_4 )
{
T_1 V_589 ;
V_589 = F_126 ( V_12 , V_4 , F_415 ( 1 ) ) ;
V_589 &= 0xffffff00 ;
V_589 |= 0x00000030 ;
F_128 ( V_12 , V_4 , F_415 ( 1 ) , V_589 ) ;
V_589 = F_126 ( V_12 , V_4 , V_590 ) ;
V_589 &= 0x8cffffff ;
V_589 = 0x8c000000 ;
F_128 ( V_12 , V_4 , V_590 , V_589 ) ;
V_589 = F_126 ( V_12 , V_4 , F_415 ( 1 ) ) ;
V_589 &= 0xffffff00 ;
F_128 ( V_12 , V_4 , F_415 ( 1 ) , V_589 ) ;
V_589 = F_126 ( V_12 , V_4 , V_590 ) ;
V_589 &= 0x00ffffff ;
V_589 |= 0xb0000000 ;
F_128 ( V_12 , V_4 , V_590 , V_589 ) ;
}
static void F_416 ( struct V_73 * V_29 ,
struct V_571 * V_572 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
F_45 ( F_417 ( V_4 ) , F_418 ( V_572 -> V_573 ) | V_572 -> V_574 ) ;
F_45 ( F_419 ( V_4 ) , V_572 -> V_575 ) ;
F_45 ( F_420 ( V_4 ) , V_572 -> V_576 ) ;
F_45 ( F_421 ( V_4 ) , V_572 -> V_577 ) ;
}
static void F_311 ( struct V_73 * V_29 ,
struct V_571 * V_572 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
enum V_80 V_80 = V_29 -> V_77 . V_82 ;
if ( F_44 ( V_10 ) -> V_86 >= 5 ) {
F_45 ( F_274 ( V_80 ) , F_418 ( V_572 -> V_573 ) | V_572 -> V_574 ) ;
F_45 ( F_422 ( V_80 ) , V_572 -> V_575 ) ;
F_45 ( F_423 ( V_80 ) , V_572 -> V_576 ) ;
F_45 ( F_424 ( V_80 ) , V_572 -> V_577 ) ;
} else {
F_45 ( F_425 ( V_4 ) , F_418 ( V_572 -> V_573 ) | V_572 -> V_574 ) ;
F_45 ( F_426 ( V_4 ) , V_572 -> V_575 ) ;
F_45 ( F_427 ( V_4 ) , V_572 -> V_576 ) ;
F_45 ( F_428 ( V_4 ) , V_572 -> V_577 ) ;
}
}
static void F_309 ( struct V_73 * V_29 )
{
if ( V_29 -> V_77 . V_245 )
F_416 ( V_29 , & V_29 -> V_77 . V_591 ) ;
else
F_311 ( V_29 , & V_29 -> V_77 . V_591 ) ;
}
static void F_429 ( struct V_73 * V_29 )
{
T_1 V_54 , V_202 ;
V_54 = V_592 | V_207 |
V_593 | V_594 ;
if ( V_29 -> V_4 == V_141 )
V_54 |= V_206 ;
V_54 |= V_112 ;
V_29 -> V_77 . V_200 . V_54 = V_54 ;
V_202 = ( V_29 -> V_77 . V_595 - 1 )
<< V_596 ;
V_29 -> V_77 . V_200 . V_202 = V_202 ;
}
static void F_361 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
T_1 V_597 ;
T_1 V_598 , V_599 , V_600 , V_601 , V_602 ;
T_1 V_603 , V_589 ;
F_58 ( & V_12 -> V_113 ) ;
V_598 = V_29 -> V_77 . V_54 . V_25 ;
V_599 = V_29 -> V_77 . V_54 . V_20 ;
V_600 = V_29 -> V_77 . V_54 . V_21 ;
V_601 = V_29 -> V_77 . V_54 . V_23 ;
V_602 = V_29 -> V_77 . V_54 . V_24 ;
if ( V_4 == V_141 )
F_414 ( V_12 , V_4 ) ;
F_128 ( V_12 , V_4 , V_604 , 0x0100000f ) ;
V_589 = F_126 ( V_12 , V_4 , F_430 ( V_4 ) ) ;
V_589 &= 0x00ffffff ;
F_128 ( V_12 , V_4 , F_430 ( V_4 ) , V_589 ) ;
F_128 ( V_12 , V_4 , V_605 , 0x610 ) ;
V_597 = ( ( V_599 << V_606 ) | ( V_600 & V_607 ) ) ;
V_597 |= ( ( V_601 << V_608 ) | ( V_602 << V_609 ) ) ;
V_597 |= ( ( V_598 << V_610 ) ) ;
V_597 |= ( 1 << V_611 ) ;
V_597 |= ( V_612 << V_613 ) ;
F_128 ( V_12 , V_4 , F_431 ( V_4 ) , V_597 ) ;
V_597 |= V_614 ;
F_128 ( V_12 , V_4 , F_431 ( V_4 ) , V_597 ) ;
if ( V_29 -> V_77 . V_615 == 162000 ||
F_10 ( & V_29 -> V_8 , V_40 ) ||
F_10 ( & V_29 -> V_8 , V_39 ) )
F_128 ( V_12 , V_4 , F_432 ( V_4 ) ,
0x009f0003 ) ;
else
F_128 ( V_12 , V_4 , F_432 ( V_4 ) ,
0x00d0000f ) ;
if ( F_10 ( & V_29 -> V_8 , V_336 ) ||
F_10 ( & V_29 -> V_8 , V_405 ) ) {
if ( V_4 == V_132 )
F_128 ( V_12 , V_4 , F_433 ( V_4 ) ,
0x0df40000 ) ;
else
F_128 ( V_12 , V_4 , F_433 ( V_4 ) ,
0x0df70000 ) ;
} else {
if ( V_4 == V_132 )
F_128 ( V_12 , V_4 , F_433 ( V_4 ) ,
0x0df70000 ) ;
else
F_128 ( V_12 , V_4 , F_433 ( V_4 ) ,
0x0df40000 ) ;
}
V_603 = F_126 ( V_12 , V_4 , F_434 ( V_4 ) ) ;
V_603 = ( V_603 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_10 ( & V_29 -> V_8 , V_405 ) ||
F_10 ( & V_29 -> V_8 , V_336 ) )
V_603 |= 0x01000000 ;
F_128 ( V_12 , V_4 , F_434 ( V_4 ) , V_603 ) ;
F_128 ( V_12 , V_4 , F_435 ( V_4 ) , 0x87871000 ) ;
F_60 ( & V_12 -> V_113 ) ;
}
static void F_436 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
int V_217 = F_56 ( V_29 -> V_4 ) ;
enum V_203 V_96 = F_125 ( V_4 ) ;
T_1 V_616 , V_617 ;
T_1 V_598 , V_599 , V_600 , V_601 , V_602 , V_618 ;
int V_18 ;
V_29 -> V_77 . V_200 . V_54 = V_208 |
V_207 | V_593 |
V_112 ;
if ( V_4 != V_132 )
V_29 -> V_77 . V_200 . V_54 |= V_206 ;
V_29 -> V_77 . V_200 . V_202 =
( V_29 -> V_77 . V_595 - 1 ) << V_596 ;
V_598 = V_29 -> V_77 . V_54 . V_25 ;
V_618 = V_29 -> V_77 . V_54 . V_21 & 0x3fffff ;
V_599 = V_29 -> V_77 . V_54 . V_20 ;
V_600 = V_29 -> V_77 . V_54 . V_21 >> 22 ;
V_601 = V_29 -> V_77 . V_54 . V_23 ;
V_602 = V_29 -> V_77 . V_54 . V_24 ;
F_45 ( V_217 ,
V_29 -> V_77 . V_200 . V_54 & ~ V_112 ) ;
F_58 ( & V_12 -> V_113 ) ;
F_128 ( V_12 , V_4 , F_437 ( V_96 ) ,
5 << V_619 |
V_601 << V_620 |
V_602 << V_621 |
1 << V_622 ) ;
F_128 ( V_12 , V_4 , F_438 ( V_96 ) , V_600 ) ;
F_128 ( V_12 , V_4 , F_439 ( V_96 ) ,
V_623 |
1 << V_624 ) ;
F_128 ( V_12 , V_4 , F_440 ( V_96 ) , V_618 ) ;
F_128 ( V_12 , V_4 , F_441 ( V_96 ) ,
V_625 |
( 2 << V_626 ) ) ;
V_18 = F_410 ( & V_29 -> V_8 , 0 ) ;
V_616 = 5 << V_627 |
2 << V_628 ;
if ( V_18 == 100000 )
V_617 = 11 ;
else if ( V_18 == 38400 )
V_617 = 10 ;
else
V_617 = 9 ;
V_616 |= V_617 << V_629 ;
F_128 ( V_12 , V_4 , F_442 ( V_96 ) , V_616 ) ;
F_128 ( V_12 , V_4 , F_127 ( V_96 ) ,
F_126 ( V_12 , V_4 , F_127 ( V_96 ) ) |
V_630 ) ;
F_60 ( & V_12 -> V_113 ) ;
}
static void F_443 ( struct V_73 * V_29 ,
T_2 * V_584 ,
int V_582 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_54 ;
bool V_631 ;
struct V_54 * clock = & V_29 -> V_77 . V_54 ;
F_413 ( V_29 , V_584 ) ;
V_631 = F_10 ( & V_29 -> V_8 , V_42 ) ||
F_10 ( & V_29 -> V_8 , V_39 ) ;
V_54 = V_593 ;
if ( F_10 ( & V_29 -> V_8 , V_31 ) )
V_54 |= V_632 ;
else
V_54 |= V_633 ;
if ( F_444 ( V_10 ) || F_445 ( V_10 ) || F_446 ( V_10 ) ) {
V_54 |= ( V_29 -> V_77 . V_595 - 1 )
<< V_634 ;
}
if ( V_631 )
V_54 |= V_635 ;
if ( F_10 ( & V_29 -> V_8 , V_405 ) )
V_54 |= V_635 ;
if ( F_17 ( V_10 ) )
V_54 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_636 ;
else {
V_54 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_637 ;
if ( F_16 ( V_10 ) && V_584 )
V_54 |= ( 1 << ( V_584 -> V_23 - 1 ) ) << V_638 ;
}
switch ( clock -> V_24 ) {
case 5 :
V_54 |= V_639 ;
break;
case 7 :
V_54 |= V_640 ;
break;
case 10 :
V_54 |= V_641 ;
break;
case 14 :
V_54 |= V_642 ;
break;
}
if ( F_44 ( V_10 ) -> V_86 >= 4 )
V_54 |= ( 6 << V_643 ) ;
if ( V_29 -> V_77 . V_644 )
V_54 |= V_645 ;
else if ( F_10 ( & V_29 -> V_8 , V_31 ) &&
F_409 ( V_12 ) && V_582 < 2 )
V_54 |= V_646 ;
else
V_54 |= V_647 ;
V_54 |= V_112 ;
V_29 -> V_77 . V_200 . V_54 = V_54 ;
if ( F_44 ( V_10 ) -> V_86 >= 4 ) {
T_1 V_202 = ( V_29 -> V_77 . V_595 - 1 )
<< V_596 ;
V_29 -> V_77 . V_200 . V_202 = V_202 ;
}
}
static void F_447 ( struct V_73 * V_29 ,
T_2 * V_584 ,
int V_582 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_54 ;
struct V_54 * clock = & V_29 -> V_77 . V_54 ;
F_413 ( V_29 , V_584 ) ;
V_54 = V_593 ;
if ( F_10 ( & V_29 -> V_8 , V_31 ) ) {
V_54 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_637 ;
} else {
if ( clock -> V_23 == 2 )
V_54 |= V_648 ;
else
V_54 |= ( clock -> V_23 - 2 ) << V_637 ;
if ( clock -> V_24 == 4 )
V_54 |= V_649 ;
}
if ( F_10 ( & V_29 -> V_8 , V_51 ) )
V_54 |= V_650 ;
if ( F_10 ( & V_29 -> V_8 , V_31 ) &&
F_409 ( V_12 ) && V_582 < 2 )
V_54 |= V_646 ;
else
V_54 |= V_647 ;
V_54 |= V_112 ;
V_29 -> V_77 . V_200 . V_54 = V_54 ;
}
static void F_310 ( struct V_73 * V_73 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_73 -> V_4 ;
enum V_80 V_82 = V_73 -> V_77 . V_82 ;
struct V_332 * V_78 =
& V_73 -> V_77 . V_78 ;
T_4 V_651 , V_652 ;
int V_653 = 0 ;
V_651 = V_78 -> V_651 ;
V_652 = V_78 -> V_652 ;
if ( V_78 -> V_321 & V_654 ) {
V_651 -= 1 ;
V_652 -= 1 ;
if ( F_10 ( & V_73 -> V_8 , V_42 ) )
V_653 = ( V_78 -> V_655 - 1 ) / 2 ;
else
V_653 = V_78 -> V_656 -
V_78 -> V_655 / 2 ;
if ( V_653 < 0 )
V_653 += V_78 -> V_655 ;
}
if ( F_44 ( V_10 ) -> V_86 > 3 )
F_45 ( F_269 ( V_82 ) , V_653 ) ;
F_45 ( F_257 ( V_82 ) ,
( V_78 -> V_333 - 1 ) |
( ( V_78 -> V_655 - 1 ) << 16 ) ) ;
F_45 ( F_259 ( V_82 ) ,
( V_78 -> V_657 - 1 ) |
( ( V_78 -> V_658 - 1 ) << 16 ) ) ;
F_45 ( F_261 ( V_82 ) ,
( V_78 -> V_656 - 1 ) |
( ( V_78 -> V_659 - 1 ) << 16 ) ) ;
F_45 ( F_263 ( V_82 ) ,
( V_78 -> V_334 - 1 ) |
( ( V_651 - 1 ) << 16 ) ) ;
F_45 ( F_265 ( V_82 ) ,
( V_78 -> V_660 - 1 ) |
( ( V_652 - 1 ) << 16 ) ) ;
F_45 ( F_267 ( V_82 ) ,
( V_78 -> V_661 - 1 ) |
( ( V_78 -> V_662 - 1 ) << 16 ) ) ;
if ( F_202 ( V_10 ) && V_82 == V_663 &&
( V_4 == V_141 || V_4 == V_350 ) )
F_45 ( F_263 ( V_4 ) , F_5 ( F_263 ( V_82 ) ) ) ;
F_45 ( F_220 ( V_4 ) ,
( ( V_73 -> V_77 . V_337 - 1 ) << 16 ) |
( V_73 -> V_77 . V_338 - 1 ) ) ;
}
static void F_448 ( struct V_73 * V_29 ,
struct V_450 * V_451 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_80 V_82 = V_451 -> V_82 ;
T_4 V_204 ;
V_204 = F_5 ( F_257 ( V_82 ) ) ;
V_451 -> V_78 . V_333 = ( V_204 & 0xffff ) + 1 ;
V_451 -> V_78 . V_655 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_204 = F_5 ( F_259 ( V_82 ) ) ;
V_451 -> V_78 . V_657 = ( V_204 & 0xffff ) + 1 ;
V_451 -> V_78 . V_658 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_204 = F_5 ( F_261 ( V_82 ) ) ;
V_451 -> V_78 . V_656 = ( V_204 & 0xffff ) + 1 ;
V_451 -> V_78 . V_659 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_204 = F_5 ( F_263 ( V_82 ) ) ;
V_451 -> V_78 . V_334 = ( V_204 & 0xffff ) + 1 ;
V_451 -> V_78 . V_651 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_204 = F_5 ( F_265 ( V_82 ) ) ;
V_451 -> V_78 . V_660 = ( V_204 & 0xffff ) + 1 ;
V_451 -> V_78 . V_652 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_204 = F_5 ( F_267 ( V_82 ) ) ;
V_451 -> V_78 . V_661 = ( V_204 & 0xffff ) + 1 ;
V_451 -> V_78 . V_662 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
if ( F_5 ( F_51 ( V_82 ) ) & V_233 ) {
V_451 -> V_78 . V_321 |= V_654 ;
V_451 -> V_78 . V_651 += 1 ;
V_451 -> V_78 . V_652 += 1 ;
}
V_204 = F_5 ( F_220 ( V_29 -> V_4 ) ) ;
V_451 -> V_338 = ( V_204 & 0xffff ) + 1 ;
V_451 -> V_337 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_451 -> V_664 . V_518 = V_451 -> V_338 ;
V_451 -> V_664 . V_516 = V_451 -> V_337 ;
}
void F_449 ( struct V_332 * V_411 ,
struct V_450 * V_451 )
{
V_411 -> V_516 = V_451 -> V_78 . V_333 ;
V_411 -> V_665 = V_451 -> V_78 . V_655 ;
V_411 -> V_543 = V_451 -> V_78 . V_656 ;
V_411 -> V_666 = V_451 -> V_78 . V_659 ;
V_411 -> V_518 = V_451 -> V_78 . V_334 ;
V_411 -> V_667 = V_451 -> V_78 . V_651 ;
V_411 -> V_668 = V_451 -> V_78 . V_661 ;
V_411 -> V_669 = V_451 -> V_78 . V_662 ;
V_411 -> V_321 = V_451 -> V_78 . V_321 ;
V_411 -> clock = V_451 -> V_78 . V_79 ;
V_411 -> V_321 |= V_451 -> V_78 . V_321 ;
}
static void F_364 ( struct V_73 * V_73 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_670 ;
V_670 = 0 ;
if ( V_12 -> V_145 & V_146 &&
F_5 ( F_51 ( V_73 -> V_4 ) ) & V_147 )
V_670 |= V_147 ;
if ( V_73 -> V_77 . V_542 )
V_670 |= V_671 ;
if ( F_16 ( V_10 ) || F_19 ( V_10 ) ) {
if ( V_73 -> V_77 . V_672 && V_73 -> V_77 . V_537 != 30 )
V_670 |= V_673 |
V_674 ;
switch ( V_73 -> V_77 . V_537 ) {
case 18 :
V_670 |= V_675 ;
break;
case 24 :
V_670 |= V_676 ;
break;
case 30 :
V_670 |= V_677 ;
break;
default:
F_134 () ;
}
}
if ( F_450 ( V_10 ) ) {
if ( V_73 -> V_587 ) {
F_46 ( L_103 ) ;
V_670 |= V_678 ;
} else {
F_46 ( L_104 ) ;
}
}
if ( V_73 -> V_77 . V_78 . V_321 & V_654 ) {
if ( F_44 ( V_10 ) -> V_86 < 4 ||
F_10 ( & V_73 -> V_8 , V_42 ) )
V_670 |= V_679 ;
else
V_670 |= V_680 ;
} else
V_670 |= V_681 ;
if ( F_19 ( V_10 ) && V_73 -> V_77 . V_682 )
V_670 |= V_683 ;
F_45 ( F_51 ( V_73 -> V_4 ) , V_670 ) ;
F_121 ( F_51 ( V_73 -> V_4 ) ) ;
}
static int F_451 ( struct V_28 * V_29 ,
int V_267 , int V_268 ,
struct V_301 * V_76 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_18 , V_582 = 0 ;
T_2 clock , V_584 ;
bool V_684 , V_685 = false ;
bool V_686 = false , V_505 = false ;
struct V_1 * V_6 ;
const T_3 * V_30 ;
F_11 (dev, crtc, encoder) {
switch ( V_6 -> type ) {
case V_31 :
V_686 = true ;
break;
case V_244 :
V_505 = true ;
break;
}
V_582 ++ ;
}
if ( V_505 )
return 0 ;
if ( ! V_73 -> V_77 . V_687 ) {
V_18 = F_410 ( V_29 , V_582 ) ;
V_30 = F_15 ( V_29 , V_18 ) ;
V_684 = V_12 -> V_315 . V_688 ( V_30 , V_29 ,
V_73 -> V_77 . V_615 ,
V_18 , NULL , & clock ) ;
if ( ! V_684 ) {
F_114 ( L_105 ) ;
return - V_262 ;
}
if ( V_686 && V_12 -> V_689 ) {
V_685 =
V_12 -> V_315 . V_688 ( V_30 , V_29 ,
V_12 -> V_690 ,
V_18 , & clock ,
& V_584 ) ;
}
V_73 -> V_77 . V_54 . V_25 = clock . V_25 ;
V_73 -> V_77 . V_54 . V_20 = clock . V_20 ;
V_73 -> V_77 . V_54 . V_21 = clock . V_21 ;
V_73 -> V_77 . V_54 . V_23 = clock . V_23 ;
V_73 -> V_77 . V_54 . V_24 = clock . V_24 ;
}
if ( F_20 ( V_10 ) ) {
F_447 ( V_73 ,
V_685 ? & V_584 : NULL ,
V_582 ) ;
} else if ( F_18 ( V_10 ) ) {
F_436 ( V_73 ) ;
} else if ( F_19 ( V_10 ) ) {
F_429 ( V_73 ) ;
} else {
F_443 ( V_73 ,
V_685 ? & V_584 : NULL ,
V_582 ) ;
}
return 0 ;
}
static void F_452 ( struct V_73 * V_29 ,
struct V_450 * V_451 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_204 ;
if ( F_44 ( V_10 ) -> V_86 <= 3 && ( F_120 ( V_10 ) || ! F_119 ( V_10 ) ) )
return;
V_204 = F_5 ( V_454 ) ;
if ( ! ( V_204 & V_455 ) )
return;
if ( F_44 ( V_10 ) -> V_86 < 4 ) {
if ( V_29 -> V_4 != V_141 )
return;
} else {
if ( ( V_204 & V_691 ) != ( V_29 -> V_4 << V_692 ) )
return;
}
V_451 -> V_452 . V_453 = V_204 ;
V_451 -> V_452 . V_457 = F_5 ( V_456 ) ;
if ( F_44 ( V_10 ) -> V_86 < 5 )
V_451 -> V_452 . V_693 =
F_5 ( V_137 ) & V_694 ;
}
static void F_453 ( struct V_73 * V_29 ,
struct V_450 * V_451 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_451 -> V_82 ;
T_2 clock ;
T_1 V_597 ;
int V_18 = 100000 ;
if ( ! ( V_451 -> V_200 . V_54 & V_112 ) )
return;
F_58 ( & V_12 -> V_113 ) ;
V_597 = F_126 ( V_12 , V_4 , F_431 ( V_4 ) ) ;
F_60 ( & V_12 -> V_113 ) ;
clock . V_20 = ( V_597 >> V_606 ) & 7 ;
clock . V_21 = V_597 & V_607 ;
clock . V_25 = ( V_597 >> V_610 ) & 0xf ;
clock . V_23 = ( V_597 >> V_608 ) & 7 ;
clock . V_24 = ( V_597 >> V_609 ) & 0x1f ;
F_8 ( V_18 , & clock ) ;
V_451 -> V_615 = clock . V_27 / 5 ;
}
static void F_454 ( struct V_73 * V_29 ,
struct V_289 * V_290 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_110 , V_8 , V_273 ;
int V_4 = V_29 -> V_4 , V_148 = V_29 -> V_148 ;
int V_695 , V_296 ;
int V_696 ;
V_29 -> V_8 . V_75 -> V_76 = F_455 ( sizeof( struct V_697 ) , V_698 ) ;
if ( ! V_29 -> V_8 . V_75 -> V_76 ) {
F_46 ( L_106 ) ;
return;
}
V_110 = F_5 ( F_81 ( V_148 ) ) ;
if ( F_44 ( V_10 ) -> V_86 >= 4 )
if ( V_110 & V_310 )
V_290 -> V_249 = true ;
V_296 = V_110 & V_304 ;
V_695 = F_184 ( V_296 ) ;
V_29 -> V_8 . V_75 -> V_76 -> V_296 = V_695 ;
V_29 -> V_8 . V_75 -> V_76 -> V_312 =
F_456 ( V_695 , 0 ) * 8 ;
if ( F_44 ( V_10 ) -> V_86 >= 4 ) {
if ( V_290 -> V_249 )
V_273 = F_5 ( F_199 ( V_148 ) ) ;
else
V_273 = F_5 ( F_200 ( V_148 ) ) ;
V_8 = F_5 ( F_161 ( V_148 ) ) & 0xfffff000 ;
} else {
V_8 = F_5 ( F_162 ( V_148 ) ) ;
}
V_290 -> V_8 = V_8 ;
V_110 = F_5 ( F_220 ( V_4 ) ) ;
V_29 -> V_8 . V_75 -> V_76 -> V_297 = ( ( V_110 >> 16 ) & 0xfff ) + 1 ;
V_29 -> V_8 . V_75 -> V_76 -> V_248 = ( ( V_110 >> 0 ) & 0xfff ) + 1 ;
V_110 = F_5 ( F_198 ( V_4 ) ) ;
V_29 -> V_8 . V_75 -> V_76 -> V_295 [ 0 ] = V_110 & 0xffffff80 ;
V_696 = F_169 ( V_10 , V_29 -> V_8 . V_75 -> V_76 -> V_248 ,
V_290 -> V_249 ) ;
V_290 -> V_293 = F_457 ( V_29 -> V_8 . V_75 -> V_76 -> V_295 [ 0 ] *
V_696 ) ;
F_46 ( L_107 ,
V_4 , V_148 , V_29 -> V_8 . V_75 -> V_76 -> V_297 ,
V_29 -> V_8 . V_75 -> V_76 -> V_248 ,
V_29 -> V_8 . V_75 -> V_76 -> V_312 , V_8 ,
V_29 -> V_8 . V_75 -> V_76 -> V_295 [ 0 ] ,
V_290 -> V_293 ) ;
}
static void F_458 ( struct V_73 * V_29 ,
struct V_450 * V_451 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_451 -> V_82 ;
enum V_203 V_96 = F_125 ( V_4 ) ;
T_2 clock ;
T_1 V_699 , V_700 , V_701 , V_702 ;
int V_18 = 100000 ;
F_58 ( & V_12 -> V_113 ) ;
V_699 = F_126 ( V_12 , V_4 , F_437 ( V_96 ) ) ;
V_700 = F_126 ( V_12 , V_4 , F_438 ( V_96 ) ) ;
V_701 = F_126 ( V_12 , V_4 , F_439 ( V_96 ) ) ;
V_702 = F_126 ( V_12 , V_4 , F_440 ( V_96 ) ) ;
F_60 ( & V_12 -> V_113 ) ;
clock . V_20 = ( V_701 & 0x7 ) == V_623 ? 2 : 0 ;
clock . V_21 = ( ( V_700 & 0xff ) << 22 ) | ( V_702 & 0x3fffff ) ;
clock . V_25 = ( V_701 >> V_624 ) & 0xf ;
clock . V_23 = ( V_699 >> V_620 ) & 0x7 ;
clock . V_24 = ( V_699 >> V_621 ) & 0x1f ;
F_24 ( V_18 , & clock ) ;
V_451 -> V_615 = clock . V_27 / 5 ;
}
static bool F_459 ( struct V_73 * V_29 ,
struct V_450 * V_451 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_204 ;
if ( ! F_78 ( V_12 ,
F_343 ( V_29 -> V_4 ) ) )
return false ;
V_451 -> V_82 = (enum V_80 ) V_29 -> V_4 ;
V_451 -> V_117 = V_416 ;
V_204 = F_5 ( F_51 ( V_29 -> V_4 ) ) ;
if ( ! ( V_204 & V_147 ) )
return false ;
if ( F_16 ( V_10 ) || F_19 ( V_10 ) ) {
switch ( V_204 & V_231 ) {
case V_675 :
V_451 -> V_537 = 18 ;
break;
case V_676 :
V_451 -> V_537 = 24 ;
break;
case V_677 :
V_451 -> V_537 = 30 ;
break;
default:
break;
}
}
if ( F_19 ( V_10 ) && ( V_204 & V_683 ) )
V_451 -> V_682 = true ;
if ( F_44 ( V_10 ) -> V_86 < 4 )
V_451 -> V_542 = V_204 & V_671 ;
F_448 ( V_29 , V_451 ) ;
F_452 ( V_29 , V_451 ) ;
if ( F_44 ( V_10 ) -> V_86 >= 4 ) {
V_204 = F_5 ( F_123 ( V_29 -> V_4 ) ) ;
V_451 -> V_595 =
( ( V_204 & V_703 )
>> V_596 ) + 1 ;
V_451 -> V_200 . V_202 = V_204 ;
} else if ( F_444 ( V_10 ) || F_445 ( V_10 ) || F_446 ( V_10 ) ) {
V_204 = F_5 ( F_56 ( V_29 -> V_4 ) ) ;
V_451 -> V_595 =
( ( V_204 & V_704 )
>> V_634 ) + 1 ;
} else {
V_451 -> V_595 = 1 ;
}
V_451 -> V_200 . V_54 = F_5 ( F_56 ( V_29 -> V_4 ) ) ;
if ( ! F_19 ( V_10 ) ) {
V_451 -> V_200 . V_507 = F_5 ( F_367 ( V_29 -> V_4 ) ) ;
V_451 -> V_200 . V_508 = F_5 ( F_368 ( V_29 -> V_4 ) ) ;
} else {
V_451 -> V_200 . V_54 &= ~ ( V_201 |
V_219 |
V_218 ) ;
}
if ( F_18 ( V_10 ) )
F_458 ( V_29 , V_451 ) ;
else if ( F_19 ( V_10 ) )
F_453 ( V_29 , V_451 ) ;
else
F_460 ( V_29 , V_451 ) ;
return true ;
}
static void F_461 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_705 * V_706 = & V_10 -> V_706 ;
struct V_1 * V_6 ;
T_1 V_110 , V_707 ;
bool V_708 = false ;
bool V_709 = false ;
bool V_710 = false ;
bool V_711 = false ;
bool V_712 = false ;
F_378 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_6 -> type ) {
case V_31 :
V_710 = true ;
V_708 = true ;
break;
case V_336 :
V_710 = true ;
if ( F_339 ( & V_6 -> V_8 ) -> V_96 == V_459 )
V_709 = true ;
break;
}
}
if ( F_53 ( V_10 ) ) {
V_711 = V_12 -> V_579 . V_713 ;
V_712 = V_711 ;
} else {
V_711 = false ;
V_712 = true ;
}
F_46 ( L_108 ,
V_710 , V_708 , V_711 ) ;
V_110 = F_5 ( V_158 ) ;
V_707 = V_110 ;
V_707 &= ~ V_160 ;
if ( V_711 )
V_707 |= V_714 ;
else
V_707 |= V_715 ;
V_707 &= ~ V_159 ;
V_707 &= ~ V_716 ;
V_707 &= ~ V_717 ;
if ( V_710 ) {
V_707 |= V_718 ;
if ( F_409 ( V_12 ) && V_712 )
V_707 |= V_717 ;
if ( V_709 ) {
if ( F_409 ( V_12 ) && V_712 )
V_707 |= V_719 ;
else
V_707 |= V_720 ;
} else
V_707 |= V_721 ;
} else {
V_707 |= V_722 ;
V_707 |= V_721 ;
}
if ( V_707 == V_110 )
return;
V_110 &= ~ V_160 ;
if ( V_711 )
V_110 |= V_714 ;
else
V_110 |= V_715 ;
if ( V_710 ) {
V_110 &= ~ V_159 ;
V_110 |= V_718 ;
if ( F_409 ( V_12 ) && V_712 ) {
F_46 ( L_109 ) ;
V_110 |= V_717 ;
} else
V_110 &= ~ V_717 ;
F_45 ( V_158 , V_110 ) ;
F_121 ( V_158 ) ;
F_122 ( 200 ) ;
V_110 &= ~ V_716 ;
if ( V_709 ) {
if ( F_409 ( V_12 ) && V_712 ) {
F_46 ( L_110 ) ;
V_110 |= V_719 ;
} else
V_110 |= V_720 ;
} else
V_110 |= V_721 ;
F_45 ( V_158 , V_110 ) ;
F_121 ( V_158 ) ;
F_122 ( 200 ) ;
} else {
F_46 ( L_111 ) ;
V_110 &= ~ V_716 ;
V_110 |= V_721 ;
F_45 ( V_158 , V_110 ) ;
F_121 ( V_158 ) ;
F_122 ( 200 ) ;
V_110 &= ~ V_159 ;
V_110 |= V_722 ;
V_110 &= ~ V_717 ;
F_45 ( V_158 , V_110 ) ;
F_121 ( V_158 ) ;
F_122 ( 200 ) ;
}
F_118 ( V_110 != V_707 ) ;
}
static void F_462 ( struct V_11 * V_12 )
{
T_4 V_204 ;
V_204 = F_5 ( V_723 ) ;
V_204 |= V_724 ;
F_45 ( V_723 , V_204 ) ;
if ( F_463 ( F_5 ( V_723 ) &
V_725 , 100 ) )
F_114 ( L_112 ) ;
V_204 = F_5 ( V_723 ) ;
V_204 &= ~ V_724 ;
F_45 ( V_723 , V_204 ) ;
if ( F_463 ( ( F_5 ( V_723 ) &
V_725 ) == 0 , 100 ) )
F_114 ( L_113 ) ;
}
static void F_464 ( struct V_11 * V_12 )
{
T_4 V_204 ;
V_204 = F_250 ( V_12 , 0x8008 , V_726 ) ;
V_204 &= ~ ( 0xFF << 24 ) ;
V_204 |= ( 0x12 << 24 ) ;
F_249 ( V_12 , 0x8008 , V_204 , V_726 ) ;
V_204 = F_250 ( V_12 , 0x2008 , V_726 ) ;
V_204 |= ( 1 << 11 ) ;
F_249 ( V_12 , 0x2008 , V_204 , V_726 ) ;
V_204 = F_250 ( V_12 , 0x2108 , V_726 ) ;
V_204 |= ( 1 << 11 ) ;
F_249 ( V_12 , 0x2108 , V_204 , V_726 ) ;
V_204 = F_250 ( V_12 , 0x206C , V_726 ) ;
V_204 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_249 ( V_12 , 0x206C , V_204 , V_726 ) ;
V_204 = F_250 ( V_12 , 0x216C , V_726 ) ;
V_204 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_249 ( V_12 , 0x216C , V_204 , V_726 ) ;
V_204 = F_250 ( V_12 , 0x2080 , V_726 ) ;
V_204 &= ~ ( 7 << 13 ) ;
V_204 |= ( 5 << 13 ) ;
F_249 ( V_12 , 0x2080 , V_204 , V_726 ) ;
V_204 = F_250 ( V_12 , 0x2180 , V_726 ) ;
V_204 &= ~ ( 7 << 13 ) ;
V_204 |= ( 5 << 13 ) ;
F_249 ( V_12 , 0x2180 , V_204 , V_726 ) ;
V_204 = F_250 ( V_12 , 0x208C , V_726 ) ;
V_204 &= ~ 0xFF ;
V_204 |= 0x1C ;
F_249 ( V_12 , 0x208C , V_204 , V_726 ) ;
V_204 = F_250 ( V_12 , 0x218C , V_726 ) ;
V_204 &= ~ 0xFF ;
V_204 |= 0x1C ;
F_249 ( V_12 , 0x218C , V_204 , V_726 ) ;
V_204 = F_250 ( V_12 , 0x2098 , V_726 ) ;
V_204 &= ~ ( 0xFF << 16 ) ;
V_204 |= ( 0x1C << 16 ) ;
F_249 ( V_12 , 0x2098 , V_204 , V_726 ) ;
V_204 = F_250 ( V_12 , 0x2198 , V_726 ) ;
V_204 &= ~ ( 0xFF << 16 ) ;
V_204 |= ( 0x1C << 16 ) ;
F_249 ( V_12 , 0x2198 , V_204 , V_726 ) ;
V_204 = F_250 ( V_12 , 0x20C4 , V_726 ) ;
V_204 |= ( 1 << 27 ) ;
F_249 ( V_12 , 0x20C4 , V_204 , V_726 ) ;
V_204 = F_250 ( V_12 , 0x21C4 , V_726 ) ;
V_204 |= ( 1 << 27 ) ;
F_249 ( V_12 , 0x21C4 , V_204 , V_726 ) ;
V_204 = F_250 ( V_12 , 0x20EC , V_726 ) ;
V_204 &= ~ ( 0xF << 28 ) ;
V_204 |= ( 4 << 28 ) ;
F_249 ( V_12 , 0x20EC , V_204 , V_726 ) ;
V_204 = F_250 ( V_12 , 0x21EC , V_726 ) ;
V_204 &= ~ ( 0xF << 28 ) ;
V_204 |= ( 4 << 28 ) ;
F_249 ( V_12 , 0x21EC , V_204 , V_726 ) ;
}
static void F_465 ( struct V_9 * V_10 , bool V_727 ,
bool V_728 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_88 , V_204 ;
if ( F_41 ( V_728 && ! V_727 , L_114 ) )
V_727 = true ;
if ( F_41 ( V_12 -> V_729 == V_730 &&
V_728 , L_115 ) )
V_728 = false ;
F_58 ( & V_12 -> V_113 ) ;
V_204 = F_250 ( V_12 , V_731 , V_387 ) ;
V_204 &= ~ V_388 ;
V_204 |= V_732 ;
F_249 ( V_12 , V_731 , V_204 , V_387 ) ;
F_122 ( 24 ) ;
if ( V_727 ) {
V_204 = F_250 ( V_12 , V_731 , V_387 ) ;
V_204 &= ~ V_732 ;
F_249 ( V_12 , V_731 , V_204 , V_387 ) ;
if ( V_728 ) {
F_462 ( V_12 ) ;
F_464 ( V_12 ) ;
}
}
V_88 = ( V_12 -> V_729 == V_730 ) ?
V_733 : V_734 ;
V_204 = F_250 ( V_12 , V_88 , V_387 ) ;
V_204 |= V_735 ;
F_249 ( V_12 , V_88 , V_204 , V_387 ) ;
F_60 ( & V_12 -> V_113 ) ;
}
static void F_466 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_88 , V_204 ;
F_58 ( & V_12 -> V_113 ) ;
V_88 = ( V_12 -> V_729 == V_730 ) ?
V_733 : V_734 ;
V_204 = F_250 ( V_12 , V_88 , V_387 ) ;
V_204 &= ~ V_735 ;
F_249 ( V_12 , V_88 , V_204 , V_387 ) ;
V_204 = F_250 ( V_12 , V_731 , V_387 ) ;
if ( ! ( V_204 & V_388 ) ) {
if ( ! ( V_204 & V_732 ) ) {
V_204 |= V_732 ;
F_249 ( V_12 , V_731 , V_204 , V_387 ) ;
F_122 ( 32 ) ;
}
V_204 |= V_388 ;
F_249 ( V_12 , V_731 , V_204 , V_387 ) ;
}
F_60 ( & V_12 -> V_113 ) ;
}
static void F_467 ( struct V_9 * V_10 )
{
struct V_705 * V_706 = & V_10 -> V_706 ;
struct V_1 * V_6 ;
bool V_736 = false ;
F_378 (encoder, &mode_config->encoder_list, base.head) {
switch ( V_6 -> type ) {
case V_40 :
V_736 = true ;
break;
}
}
if ( V_736 )
F_465 ( V_10 , true , true ) ;
else
F_466 ( V_10 ) ;
}
void F_468 ( struct V_9 * V_10 )
{
if ( F_53 ( V_10 ) || F_92 ( V_10 ) )
F_461 ( V_10 ) ;
else if ( F_155 ( V_10 ) )
F_467 ( V_10 ) ;
}
static int F_469 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
int V_582 = 0 ;
bool V_686 = false ;
F_11 (dev, crtc, encoder) {
switch ( V_6 -> type ) {
case V_31 :
V_686 = true ;
break;
}
V_582 ++ ;
}
if ( V_686 && F_409 ( V_12 ) && V_582 < 2 ) {
F_46 ( L_102 ,
V_12 -> V_579 . V_583 ) ;
return V_12 -> V_579 . V_583 ;
}
return 120000 ;
}
static void F_312 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_4 V_110 ;
V_110 = 0 ;
switch ( V_73 -> V_77 . V_537 ) {
case 18 :
V_110 |= V_675 ;
break;
case 24 :
V_110 |= V_676 ;
break;
case 30 :
V_110 |= V_677 ;
break;
case 36 :
V_110 |= V_737 ;
break;
default:
F_134 () ;
}
if ( V_73 -> V_77 . V_672 )
V_110 |= ( V_673 | V_674 ) ;
if ( V_73 -> V_77 . V_78 . V_321 & V_654 )
V_110 |= V_234 ;
else
V_110 |= V_681 ;
if ( V_73 -> V_77 . V_682 )
V_110 |= V_683 ;
F_45 ( F_51 ( V_4 ) , V_110 ) ;
F_121 ( F_51 ( V_4 ) ) ;
}
static void F_321 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_6 V_738 = 0x7800 ;
if ( V_73 -> V_77 . V_682 )
V_738 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_45 ( F_470 ( V_4 ) , V_738 << 16 ) ;
F_45 ( F_471 ( V_4 ) , 0 ) ;
F_45 ( F_472 ( V_4 ) , V_738 ) ;
F_45 ( F_473 ( V_4 ) , 0 ) ;
F_45 ( F_474 ( V_4 ) , 0 ) ;
F_45 ( F_475 ( V_4 ) , V_738 << 16 ) ;
F_45 ( F_476 ( V_4 ) , 0 ) ;
F_45 ( F_477 ( V_4 ) , 0 ) ;
F_45 ( F_478 ( V_4 ) , 0 ) ;
if ( F_44 ( V_10 ) -> V_86 > 6 ) {
T_6 V_739 = 0 ;
if ( V_73 -> V_77 . V_682 )
V_739 = ( 16 * ( 1 << 12 ) / 255 ) & 0x1fff ;
F_45 ( F_479 ( V_4 ) , V_739 ) ;
F_45 ( F_480 ( V_4 ) , V_739 ) ;
F_45 ( F_481 ( V_4 ) , V_739 ) ;
F_45 ( F_482 ( V_4 ) , 0 ) ;
} else {
T_4 V_411 = V_740 ;
if ( V_73 -> V_77 . V_682 )
V_411 |= V_741 ;
F_45 ( F_482 ( V_4 ) , V_411 ) ;
}
}
static void F_320 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_4 V_4 = V_73 -> V_4 ;
enum V_80 V_82 = V_73 -> V_77 . V_82 ;
T_4 V_110 ;
V_110 = 0 ;
if ( F_202 ( V_10 ) && V_73 -> V_77 . V_672 )
V_110 |= ( V_673 | V_674 ) ;
if ( V_73 -> V_77 . V_78 . V_321 & V_654 )
V_110 |= V_234 ;
else
V_110 |= V_681 ;
F_45 ( F_51 ( V_82 ) , V_110 ) ;
F_121 ( F_51 ( V_82 ) ) ;
F_45 ( F_298 ( V_73 -> V_4 ) , V_742 ) ;
F_121 ( F_298 ( V_73 -> V_4 ) ) ;
if ( F_165 ( V_10 ) ) {
V_110 = 0 ;
switch ( V_73 -> V_77 . V_537 ) {
case 18 :
V_110 |= V_743 ;
break;
case 24 :
V_110 |= V_744 ;
break;
case 30 :
V_110 |= V_745 ;
break;
case 36 :
V_110 |= V_746 ;
break;
default:
F_134 () ;
}
if ( V_73 -> V_77 . V_672 )
V_110 |= V_747 | V_748 ;
F_45 ( F_483 ( V_4 ) , V_110 ) ;
}
}
static bool F_484 ( struct V_28 * V_29 ,
T_2 * clock ,
bool * V_685 ,
T_2 * V_584 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 ;
int V_18 ;
const T_3 * V_30 ;
bool V_256 , V_686 = false ;
F_11 (dev, crtc, intel_encoder) {
switch ( V_1 -> type ) {
case V_31 :
V_686 = true ;
break;
}
}
V_18 = F_469 ( V_29 ) ;
V_30 = F_15 ( V_29 , V_18 ) ;
V_256 = V_12 -> V_315 . V_688 ( V_30 , V_29 ,
F_35 ( V_29 ) -> V_77 . V_615 ,
V_18 , NULL , clock ) ;
if ( ! V_256 )
return false ;
if ( V_686 && V_12 -> V_689 ) {
* V_685 =
V_12 -> V_315 . V_688 ( V_30 , V_29 ,
V_12 -> V_690 ,
V_18 , clock ,
V_584 ) ;
}
return true ;
}
int F_391 ( int V_749 , int V_533 , int V_750 )
{
T_1 V_751 = V_749 * V_750 * 21 / 20 ;
return F_485 ( V_751 , V_533 * 8 ) ;
}
static bool F_486 ( struct V_54 * V_54 , int V_752 )
{
return F_22 ( V_54 ) < V_752 * V_54 -> V_25 ;
}
static T_4 F_487 ( struct V_73 * V_73 ,
T_1 * V_585 ,
T_2 * V_584 , T_1 * V_586 )
{
struct V_28 * V_29 = & V_73 -> V_8 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 ;
T_4 V_54 ;
int V_752 , V_582 = 0 ;
bool V_686 = false , V_631 = false ;
F_11 (dev, crtc, intel_encoder) {
switch ( V_1 -> type ) {
case V_31 :
V_686 = true ;
break;
case V_42 :
case V_39 :
V_631 = true ;
break;
}
V_582 ++ ;
}
V_752 = 21 ;
if ( V_686 ) {
if ( ( F_409 ( V_12 ) &&
V_12 -> V_579 . V_583 == 100000 ) ||
( F_53 ( V_10 ) && F_13 ( V_10 ) ) )
V_752 = 25 ;
} else if ( V_73 -> V_77 . V_644 )
V_752 = 20 ;
if ( F_486 ( & V_73 -> V_77 . V_54 , V_752 ) )
* V_585 |= V_753 ;
if ( V_586 && ( V_584 -> V_19 < V_752 * V_584 -> V_25 ) )
* V_586 |= V_753 ;
V_54 = 0 ;
if ( V_686 )
V_54 |= V_632 ;
else
V_54 |= V_633 ;
V_54 |= ( V_73 -> V_77 . V_595 - 1 )
<< V_754 ;
if ( V_631 )
V_54 |= V_635 ;
if ( V_73 -> V_77 . V_440 )
V_54 |= V_635 ;
V_54 |= ( 1 << ( V_73 -> V_77 . V_54 . V_23 - 1 ) ) << V_637 ;
V_54 |= ( 1 << ( V_73 -> V_77 . V_54 . V_23 - 1 ) ) << V_638 ;
switch ( V_73 -> V_77 . V_54 . V_24 ) {
case 5 :
V_54 |= V_639 ;
break;
case 7 :
V_54 |= V_640 ;
break;
case 10 :
V_54 |= V_641 ;
break;
case 14 :
V_54 |= V_642 ;
break;
}
if ( V_686 && F_409 ( V_12 ) && V_582 < 2 )
V_54 |= V_646 ;
else
V_54 |= V_647 ;
return V_54 | V_112 ;
}
static int F_488 ( struct V_28 * V_29 ,
int V_267 , int V_268 ,
struct V_301 * V_76 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_582 = 0 ;
T_2 clock , V_584 ;
T_1 V_54 = 0 , V_585 = 0 , V_586 = 0 ;
bool V_684 , V_685 = false ;
bool V_686 = false ;
struct V_1 * V_6 ;
struct V_116 * V_119 ;
F_11 (dev, crtc, encoder) {
switch ( V_6 -> type ) {
case V_31 :
V_686 = true ;
break;
}
V_582 ++ ;
}
F_41 ( ! ( F_53 ( V_10 ) || F_92 ( V_10 ) ) ,
L_116 , F_489 ( V_10 ) ) ;
V_684 = F_484 ( V_29 , & clock ,
& V_685 , & V_584 ) ;
if ( ! V_684 && ! V_73 -> V_77 . V_687 ) {
F_114 ( L_105 ) ;
return - V_262 ;
}
if ( ! V_73 -> V_77 . V_687 ) {
V_73 -> V_77 . V_54 . V_25 = clock . V_25 ;
V_73 -> V_77 . V_54 . V_20 = clock . V_20 ;
V_73 -> V_77 . V_54 . V_21 = clock . V_21 ;
V_73 -> V_77 . V_54 . V_23 = clock . V_23 ;
V_73 -> V_77 . V_54 . V_24 = clock . V_24 ;
}
if ( V_73 -> V_77 . V_245 ) {
V_585 = F_412 ( & V_73 -> V_77 . V_54 ) ;
if ( V_685 )
V_586 = F_412 ( & V_584 ) ;
V_54 = F_487 ( V_73 ,
& V_585 , & V_584 ,
V_685 ? & V_586 : NULL ) ;
V_73 -> V_77 . V_200 . V_54 = V_54 ;
V_73 -> V_77 . V_200 . V_507 = V_585 ;
if ( V_685 )
V_73 -> V_77 . V_200 . V_508 = V_586 ;
else
V_73 -> V_77 . V_200 . V_508 = V_585 ;
V_119 = F_280 ( V_73 ) ;
if ( V_119 == NULL ) {
F_137 ( L_117 ,
F_72 ( V_73 -> V_4 ) ) ;
return - V_262 ;
}
} else
F_279 ( V_73 ) ;
if ( V_686 && V_685 && V_330 . V_588 )
V_73 -> V_587 = true ;
else
V_73 -> V_587 = false ;
return 0 ;
}
static void F_490 ( struct V_73 * V_29 ,
struct V_571 * V_572 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
V_572 -> V_576 = F_5 ( F_420 ( V_4 ) ) ;
V_572 -> V_577 = F_5 ( F_421 ( V_4 ) ) ;
V_572 -> V_574 = F_5 ( F_417 ( V_4 ) )
& ~ V_400 ;
V_572 -> V_575 = F_5 ( F_419 ( V_4 ) ) ;
V_572 -> V_573 = ( ( F_5 ( F_417 ( V_4 ) )
& V_400 ) >> V_755 ) + 1 ;
}
static void F_491 ( struct V_73 * V_29 ,
enum V_80 V_80 ,
struct V_571 * V_572 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
if ( F_44 ( V_10 ) -> V_86 >= 5 ) {
V_572 -> V_576 = F_5 ( F_423 ( V_80 ) ) ;
V_572 -> V_577 = F_5 ( F_424 ( V_80 ) ) ;
V_572 -> V_574 = F_5 ( F_274 ( V_80 ) )
& ~ V_400 ;
V_572 -> V_575 = F_5 ( F_422 ( V_80 ) ) ;
V_572 -> V_573 = ( ( F_5 ( F_274 ( V_80 ) )
& V_400 ) >> V_755 ) + 1 ;
} else {
V_572 -> V_576 = F_5 ( F_427 ( V_4 ) ) ;
V_572 -> V_577 = F_5 ( F_428 ( V_4 ) ) ;
V_572 -> V_574 = F_5 ( F_425 ( V_4 ) )
& ~ V_400 ;
V_572 -> V_575 = F_5 ( F_426 ( V_4 ) ) ;
V_572 -> V_573 = ( ( F_5 ( F_425 ( V_4 ) )
& V_400 ) >> V_755 ) + 1 ;
}
}
void F_492 ( struct V_73 * V_29 ,
struct V_450 * V_451 )
{
if ( V_29 -> V_77 . V_245 )
F_490 ( V_29 , & V_451 -> V_591 ) ;
else
F_491 ( V_29 , V_451 -> V_82 ,
& V_451 -> V_591 ) ;
}
static void F_493 ( struct V_73 * V_29 ,
struct V_450 * V_451 )
{
F_491 ( V_29 , V_451 -> V_82 ,
& V_451 -> V_441 ) ;
}
static void F_494 ( struct V_73 * V_29 ,
struct V_450 * V_451 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_204 ;
V_204 = F_5 ( F_221 ( V_29 -> V_4 ) ) ;
if ( V_204 & V_420 ) {
V_451 -> V_335 . V_108 = true ;
V_451 -> V_335 . V_422 = F_5 ( F_222 ( V_29 -> V_4 ) ) ;
V_451 -> V_335 . V_293 = F_5 ( F_223 ( V_29 -> V_4 ) ) ;
if ( F_495 ( V_10 ) ) {
F_3 ( ( V_204 & V_756 ) !=
F_283 ( V_29 -> V_4 ) ) ;
}
}
}
static void F_496 ( struct V_73 * V_29 ,
struct V_289 * V_290 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_110 , V_8 , V_273 ;
int V_4 = V_29 -> V_4 , V_148 = V_29 -> V_148 ;
int V_695 , V_296 ;
int V_696 ;
V_29 -> V_8 . V_75 -> V_76 = F_455 ( sizeof( struct V_697 ) , V_698 ) ;
if ( ! V_29 -> V_8 . V_75 -> V_76 ) {
F_46 ( L_106 ) ;
return;
}
V_110 = F_5 ( F_81 ( V_148 ) ) ;
if ( F_44 ( V_10 ) -> V_86 >= 4 )
if ( V_110 & V_310 )
V_290 -> V_249 = true ;
V_296 = V_110 & V_304 ;
V_695 = F_184 ( V_296 ) ;
V_29 -> V_8 . V_75 -> V_76 -> V_296 = V_695 ;
V_29 -> V_8 . V_75 -> V_76 -> V_312 =
F_456 ( V_695 , 0 ) * 8 ;
V_8 = F_5 ( F_161 ( V_148 ) ) & 0xfffff000 ;
if ( F_202 ( V_10 ) || F_165 ( V_10 ) ) {
V_273 = F_5 ( F_203 ( V_148 ) ) ;
} else {
if ( V_290 -> V_249 )
V_273 = F_5 ( F_199 ( V_148 ) ) ;
else
V_273 = F_5 ( F_200 ( V_148 ) ) ;
}
V_290 -> V_8 = V_8 ;
V_110 = F_5 ( F_220 ( V_4 ) ) ;
V_29 -> V_8 . V_75 -> V_76 -> V_297 = ( ( V_110 >> 16 ) & 0xfff ) + 1 ;
V_29 -> V_8 . V_75 -> V_76 -> V_248 = ( ( V_110 >> 0 ) & 0xfff ) + 1 ;
V_110 = F_5 ( F_198 ( V_4 ) ) ;
V_29 -> V_8 . V_75 -> V_76 -> V_295 [ 0 ] = V_110 & 0xffffff80 ;
V_696 = F_169 ( V_10 , V_29 -> V_8 . V_75 -> V_76 -> V_248 ,
V_290 -> V_249 ) ;
V_290 -> V_293 = F_457 ( V_29 -> V_8 . V_75 -> V_76 -> V_295 [ 0 ] *
V_696 ) ;
F_46 ( L_107 ,
V_4 , V_148 , V_29 -> V_8 . V_75 -> V_76 -> V_297 ,
V_29 -> V_8 . V_75 -> V_76 -> V_248 ,
V_29 -> V_8 . V_75 -> V_76 -> V_312 , V_8 ,
V_29 -> V_8 . V_75 -> V_76 -> V_295 [ 0 ] ,
V_290 -> V_293 ) ;
}
static bool F_497 ( struct V_73 * V_29 ,
struct V_450 * V_451 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_204 ;
if ( ! F_78 ( V_12 ,
F_343 ( V_29 -> V_4 ) ) )
return false ;
V_451 -> V_82 = (enum V_80 ) V_29 -> V_4 ;
V_451 -> V_117 = V_416 ;
V_204 = F_5 ( F_51 ( V_29 -> V_4 ) ) ;
if ( ! ( V_204 & V_147 ) )
return false ;
switch ( V_204 & V_231 ) {
case V_675 :
V_451 -> V_537 = 18 ;
break;
case V_676 :
V_451 -> V_537 = 24 ;
break;
case V_677 :
V_451 -> V_537 = 30 ;
break;
case V_737 :
V_451 -> V_537 = 36 ;
break;
default:
break;
}
if ( V_204 & V_683 )
V_451 -> V_682 = true ;
if ( F_5 ( F_94 ( V_29 -> V_4 ) ) & V_162 ) {
struct V_116 * V_119 ;
V_451 -> V_245 = true ;
V_204 = F_5 ( F_68 ( V_29 -> V_4 ) ) ;
V_451 -> V_357 = ( ( V_356 & V_204 ) >>
V_757 ) + 1 ;
F_493 ( V_29 , V_451 ) ;
if ( F_53 ( V_12 -> V_10 ) ) {
V_451 -> V_117 =
(enum V_417 ) V_29 -> V_4 ;
} else {
V_204 = F_5 ( V_403 ) ;
if ( V_204 & F_276 ( V_29 -> V_4 ) )
V_451 -> V_117 = V_404 ;
else
V_451 -> V_117 = V_758 ;
}
V_119 = & V_12 -> V_118 [ V_451 -> V_117 ] ;
F_3 ( ! V_119 -> V_122 ( V_12 , V_119 ,
& V_451 -> V_200 ) ) ;
V_204 = V_451 -> V_200 . V_54 ;
V_451 -> V_595 =
( ( V_204 & V_759 )
>> V_754 ) + 1 ;
F_498 ( V_29 , V_451 ) ;
} else {
V_451 -> V_595 = 1 ;
}
F_448 ( V_29 , V_451 ) ;
F_494 ( V_29 , V_451 ) ;
return true ;
}
static void F_499 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_73 * V_29 ;
F_244 (dev, crtc)
F_41 ( V_29 -> V_74 , L_118 ,
F_72 ( V_29 -> V_4 ) ) ;
F_41 ( F_5 ( V_760 ) , L_119 ) ;
F_41 ( F_5 ( V_761 ) & V_762 , L_120 ) ;
F_41 ( F_5 ( V_763 ) & V_764 , L_121 ) ;
F_41 ( F_5 ( V_765 ) & V_764 , L_122 ) ;
F_41 ( F_5 ( V_766 ) & V_767 , L_123 ) ;
F_41 ( F_5 ( V_768 ) & V_769 ,
L_124 ) ;
if ( F_202 ( V_10 ) )
F_41 ( F_5 ( V_770 ) & V_769 ,
L_125 ) ;
F_41 ( F_5 ( V_771 ) & V_772 ,
L_126 ) ;
F_41 ( F_5 ( V_773 ) & V_774 ,
L_127 ) ;
F_41 ( F_5 ( V_775 ) & V_776 , L_128 ) ;
F_41 ( F_500 ( V_12 ) , L_129 ) ;
}
static T_4 F_501 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
if ( F_202 ( V_10 ) )
return F_5 ( V_777 ) ;
else
return F_5 ( V_778 ) ;
}
static void F_502 ( struct V_11 * V_12 , T_4 V_110 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
if ( F_202 ( V_10 ) ) {
F_58 ( & V_12 -> V_426 . V_427 ) ;
if ( F_292 ( V_12 , V_779 ,
V_110 ) )
F_114 ( L_130 ) ;
F_60 ( & V_12 -> V_426 . V_427 ) ;
} else {
F_45 ( V_778 , V_110 ) ;
F_121 ( V_778 ) ;
}
}
static void F_503 ( struct V_11 * V_12 ,
bool V_780 , bool V_781 )
{
T_4 V_110 ;
F_499 ( V_12 ) ;
V_110 = F_5 ( V_782 ) ;
if ( V_780 ) {
V_110 |= V_783 ;
F_45 ( V_782 , V_110 ) ;
if ( F_463 ( F_5 ( V_782 ) &
V_784 , 1 ) )
F_114 ( L_131 ) ;
V_110 = F_5 ( V_782 ) ;
}
V_110 |= V_785 ;
F_45 ( V_782 , V_110 ) ;
F_121 ( V_782 ) ;
if ( F_39 ( ( F_5 ( V_782 ) & V_786 ) == 0 , 1 ) )
F_114 ( L_132 ) ;
V_110 = F_501 ( V_12 ) ;
V_110 |= V_787 ;
F_502 ( V_12 , V_110 ) ;
F_504 ( 100 ) ;
if ( F_39 ( ( F_501 ( V_12 ) & V_788 ) == 0 ,
1 ) )
F_114 ( L_133 ) ;
if ( V_781 ) {
V_110 = F_5 ( V_782 ) ;
V_110 |= V_789 ;
F_45 ( V_782 , V_110 ) ;
F_121 ( V_782 ) ;
}
}
static void F_505 ( struct V_11 * V_12 )
{
T_4 V_110 ;
unsigned long V_790 ;
V_110 = F_5 ( V_782 ) ;
if ( ( V_110 & ( V_786 | V_785 | V_783 |
V_789 ) ) == V_786 )
return;
F_216 ( & V_12 -> V_791 . V_792 , V_790 ) ;
if ( V_12 -> V_791 . V_793 ++ == 0 )
V_12 -> V_791 . V_794 . V_795 ( V_12 , V_796 ) ;
F_217 ( & V_12 -> V_791 . V_792 , V_790 ) ;
if ( V_110 & V_789 ) {
V_110 &= ~ V_789 ;
F_45 ( V_782 , V_110 ) ;
F_121 ( V_782 ) ;
}
V_110 = F_501 ( V_12 ) ;
V_110 |= V_797 ;
V_110 &= ~ V_787 ;
F_502 ( V_12 , V_110 ) ;
V_110 = F_5 ( V_782 ) ;
V_110 &= ~ V_785 ;
F_45 ( V_782 , V_110 ) ;
if ( F_39 ( F_5 ( V_782 ) & V_786 , 5 ) )
F_114 ( L_134 ) ;
if ( V_110 & V_783 ) {
V_110 = F_5 ( V_782 ) ;
V_110 &= ~ V_783 ;
F_45 ( V_782 , V_110 ) ;
if ( F_463 ( ( F_5 ( V_782 ) &
V_784 ) == 0 , 1 ) )
F_114 ( L_135 ) ;
}
F_216 ( & V_12 -> V_791 . V_792 , V_790 ) ;
if ( -- V_12 -> V_791 . V_793 == 0 )
V_12 -> V_791 . V_794 . V_798 ( V_12 , V_796 ) ;
F_217 ( & V_12 -> V_791 . V_792 , V_790 ) ;
}
void F_506 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_110 ;
F_46 ( L_136 ) ;
if ( V_12 -> V_729 == V_730 ) {
V_110 = F_5 ( V_799 ) ;
V_110 &= ~ V_800 ;
F_45 ( V_799 , V_110 ) ;
}
F_466 ( V_10 ) ;
F_503 ( V_12 , true , true ) ;
}
void F_507 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_110 ;
F_46 ( L_137 ) ;
F_505 ( V_12 ) ;
F_467 ( V_10 ) ;
if ( V_12 -> V_729 == V_730 ) {
V_110 = F_5 ( V_799 ) ;
V_110 |= V_800 ;
F_45 ( V_799 , V_110 ) ;
}
F_508 ( V_10 ) ;
}
static void F_509 ( struct V_9 * V_10 )
{
F_346 ( V_10 ) ;
}
static void F_510 ( struct V_9 * V_10 )
{
F_346 ( V_10 ) ;
}
static int F_511 ( struct V_28 * V_29 ,
int V_267 , int V_268 ,
struct V_301 * V_76 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
if ( ! F_512 ( V_73 ) )
return - V_262 ;
V_73 -> V_587 = false ;
return 0 ;
}
static void F_513 ( struct V_73 * V_29 ,
struct V_450 * V_451 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_116 * V_119 ;
enum V_96 V_96 ;
T_4 V_204 ;
V_204 = F_5 ( F_65 ( V_451 -> V_82 ) ) ;
V_96 = ( V_204 & V_801 ) >> V_802 ;
V_451 -> V_803 = F_5 ( F_514 ( V_96 ) ) ;
switch ( V_451 -> V_803 ) {
case V_804 :
V_451 -> V_117 = V_805 ;
break;
case V_806 :
V_451 -> V_117 = V_807 ;
break;
}
if ( V_451 -> V_117 >= 0 ) {
V_119 = & V_12 -> V_118 [ V_451 -> V_117 ] ;
F_3 ( ! V_119 -> V_122 ( V_12 , V_119 ,
& V_451 -> V_200 ) ) ;
}
if ( ( V_96 == V_808 ) && F_5 ( V_242 ) & V_162 ) {
V_451 -> V_245 = true ;
V_204 = F_5 ( F_68 ( V_132 ) ) ;
V_451 -> V_357 = ( ( V_356 & V_204 ) >>
V_757 ) + 1 ;
F_493 ( V_29 , V_451 ) ;
}
}
static bool F_515 ( struct V_73 * V_29 ,
struct V_450 * V_451 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_458 V_809 ;
T_4 V_204 ;
if ( ! F_78 ( V_12 ,
F_343 ( V_29 -> V_4 ) ) )
return false ;
V_451 -> V_82 = (enum V_80 ) V_29 -> V_4 ;
V_451 -> V_117 = V_416 ;
V_204 = F_5 ( F_65 ( V_663 ) ) ;
if ( V_204 & V_124 ) {
enum V_4 V_810 ;
switch ( V_204 & V_811 ) {
default:
F_41 ( 1 , L_138 ) ;
case V_812 :
case V_813 :
V_810 = V_132 ;
break;
case V_814 :
V_810 = V_141 ;
break;
case V_815 :
V_810 = V_350 ;
break;
}
if ( V_810 == V_29 -> V_4 )
V_451 -> V_82 = V_663 ;
}
if ( ! F_78 ( V_12 ,
F_79 ( V_451 -> V_82 ) ) )
return false ;
V_204 = F_5 ( F_51 ( V_451 -> V_82 ) ) ;
if ( ! ( V_204 & V_147 ) )
return false ;
F_513 ( V_29 , V_451 ) ;
F_448 ( V_29 , V_451 ) ;
V_809 = F_344 ( V_29 -> V_4 ) ;
if ( F_78 ( V_12 , V_809 ) )
F_494 ( V_29 , V_451 ) ;
if ( F_202 ( V_10 ) )
V_451 -> V_425 = F_316 ( V_29 ) &&
( F_5 ( V_429 ) & V_430 ) ;
V_451 -> V_595 = 1 ;
return true ;
}
static T_1 F_516 ( struct V_332 * V_411 )
{
int V_150 ;
for ( V_150 = 0 ; V_150 < F_239 ( V_816 ) ; V_150 ++ ) {
if ( V_411 -> clock == V_816 [ V_150 ] . clock )
break;
}
if ( V_150 == F_239 ( V_816 ) ) {
F_46 ( L_139 , V_411 -> clock ) ;
V_150 = 1 ;
}
F_46 ( L_140 ,
V_816 [ V_150 ] . clock ,
V_816 [ V_150 ] . V_77 ) ;
return V_816 [ V_150 ] . V_77 ;
}
static bool F_517 ( struct V_525 * V_3 ,
int V_817 , T_4 V_818 ,
int V_819 , T_4 V_820 ,
int V_821 )
{
struct V_11 * V_12 = V_3 -> V_10 -> V_13 ;
T_7 * V_822 = V_3 -> V_822 ;
T_4 V_150 ;
V_150 = F_5 ( V_817 ) ;
V_150 &= V_818 ;
if ( ! V_822 [ 0 ] )
return ! V_150 ;
if ( ! V_150 )
return false ;
V_150 = F_5 ( V_819 ) ;
V_150 &= ~ V_820 ;
F_45 ( V_819 , V_150 ) ;
for ( V_150 = 0 ; V_150 < V_822 [ 2 ] ; V_150 ++ )
if ( F_5 ( V_821 ) != * ( ( T_4 * ) V_822 + V_150 ) )
return false ;
return true ;
}
static void F_518 ( struct V_525 * V_3 ,
struct V_28 * V_29 ,
struct V_332 * V_411 )
{
struct V_11 * V_12 = V_3 -> V_10 -> V_13 ;
T_7 * V_822 = V_3 -> V_822 ;
T_4 V_823 ;
T_4 V_824 ;
T_4 V_150 ;
V_150 = F_5 ( V_825 ) ;
if ( V_150 == V_826 || V_150 == V_827 )
V_823 = V_828 ;
else
V_823 = V_829 ;
if ( F_517 ( V_3 ,
V_830 , V_823 ,
V_830 , V_831 ,
V_832 ) )
return;
V_150 = F_5 ( V_830 ) ;
V_150 &= ~ ( V_823 | V_831 ) ;
V_824 = ( V_150 >> 9 ) & 0x1f ;
F_45 ( V_830 , V_150 ) ;
if ( ! V_822 [ 0 ] )
return;
V_824 = F_408 ( T_7 , V_822 [ 2 ] , V_824 ) ;
F_137 ( L_141 , V_824 ) ;
for ( V_150 = 0 ; V_150 < V_824 ; V_150 ++ )
F_45 ( V_832 , * ( ( T_4 * ) V_822 + V_150 ) ) ;
V_150 = F_5 ( V_830 ) ;
V_150 |= V_823 ;
F_45 ( V_830 , V_150 ) ;
}
static void F_519 ( struct V_525 * V_3 ,
struct V_28 * V_29 ,
struct V_332 * V_411 )
{
struct V_11 * V_12 = V_3 -> V_10 -> V_13 ;
T_7 * V_822 = V_3 -> V_822 ;
T_4 V_823 ;
T_4 V_150 ;
int V_824 ;
int V_4 = F_35 ( V_29 ) -> V_4 ;
int V_204 ;
int V_833 = F_520 ( V_4 ) ;
int V_834 = F_521 ( V_4 ) ;
int V_835 = F_522 ( V_4 ) ;
int V_836 = V_837 ;
F_137 ( L_142 ) ;
V_204 = F_5 ( V_836 ) ;
V_204 |= ( V_838 << ( V_4 * 4 ) ) ;
F_45 ( V_836 , V_204 ) ;
F_121 ( V_836 ) ;
F_117 ( V_12 , F_35 ( V_29 ) -> V_4 ) ;
V_204 = F_5 ( V_836 ) ;
F_137 ( L_143 , V_204 ) ;
V_204 |= ( V_839 << ( V_4 * 4 ) ) ;
F_45 ( V_836 , V_204 ) ;
V_204 = F_5 ( V_836 ) ;
F_137 ( L_144 , V_204 ) ;
V_204 = F_5 ( V_835 ) ;
F_137 ( L_145 , V_204 ) ;
V_204 &= ~ ( V_840 | V_841 ) ;
F_45 ( V_835 , V_204 ) ;
F_137 ( L_146 , F_72 ( V_4 ) ) ;
V_823 = V_839 << ( V_4 * 4 ) ;
if ( F_10 ( V_29 , V_405 ) ) {
F_137 ( L_147 ) ;
V_822 [ 5 ] |= ( 1 << 2 ) ;
F_45 ( V_835 , V_840 ) ;
} else {
F_45 ( V_835 , F_516 ( V_411 ) ) ;
}
if ( F_517 ( V_3 ,
V_836 , V_823 ,
V_834 , V_842 ,
V_833 ) )
return;
V_150 = F_5 ( V_836 ) ;
V_150 &= ~ V_823 ;
F_45 ( V_836 , V_150 ) ;
if ( ! V_822 [ 0 ] )
return;
V_150 = F_5 ( V_834 ) ;
V_150 &= ~ V_842 ;
F_45 ( V_834 , V_150 ) ;
V_150 = ( V_150 >> 29 ) & V_843 ;
F_137 ( L_148 , V_150 ) ;
V_824 = F_408 ( T_7 , V_822 [ 2 ] , 21 ) ;
F_137 ( L_141 , V_824 ) ;
for ( V_150 = 0 ; V_150 < V_824 ; V_150 ++ )
F_45 ( V_833 , * ( ( T_4 * ) V_822 + V_150 ) ) ;
V_150 = F_5 ( V_836 ) ;
V_150 |= V_823 ;
F_45 ( V_836 , V_150 ) ;
}
static void F_523 ( struct V_525 * V_3 ,
struct V_28 * V_29 ,
struct V_332 * V_411 )
{
struct V_11 * V_12 = V_3 -> V_10 -> V_13 ;
T_7 * V_822 = V_3 -> V_822 ;
T_4 V_823 ;
T_4 V_150 ;
int V_824 ;
int V_833 ;
int V_835 ;
int V_834 ;
int V_836 ;
int V_4 = F_35 ( V_29 ) -> V_4 ;
if ( F_53 ( V_3 -> V_10 ) ) {
V_833 = F_524 ( V_4 ) ;
V_835 = F_525 ( V_4 ) ;
V_834 = F_526 ( V_4 ) ;
V_836 = V_844 ;
} else if ( F_19 ( V_3 -> V_10 ) ) {
V_833 = F_527 ( V_4 ) ;
V_835 = F_528 ( V_4 ) ;
V_834 = F_529 ( V_4 ) ;
V_836 = V_845 ;
} else {
V_833 = F_530 ( V_4 ) ;
V_835 = F_531 ( V_4 ) ;
V_834 = F_532 ( V_4 ) ;
V_836 = V_846 ;
}
F_137 ( L_146 , F_72 ( V_4 ) ) ;
if ( F_19 ( V_3 -> V_10 ) ) {
struct V_1 * V_1 ;
struct V_95 * V_465 ;
V_1 = F_533 ( V_3 ) ;
V_465 = F_339 ( & V_1 -> V_8 ) ;
V_150 = V_465 -> V_96 ;
} else {
V_150 = F_5 ( V_834 ) ;
V_150 = ( V_150 >> 29 ) & V_843 ;
}
if ( ! V_150 ) {
F_137 ( L_149 ) ;
V_823 = V_847 ;
V_823 |= V_847 << 4 ;
V_823 |= V_847 << 8 ;
} else {
F_137 ( L_150 , F_135 ( V_150 ) ) ;
V_823 = V_847 << ( ( V_150 - 1 ) * 4 ) ;
}
if ( F_10 ( V_29 , V_405 ) ) {
F_137 ( L_147 ) ;
V_822 [ 5 ] |= ( 1 << 2 ) ;
F_45 ( V_835 , V_840 ) ;
} else {
F_45 ( V_835 , F_516 ( V_411 ) ) ;
}
if ( F_517 ( V_3 ,
V_836 , V_823 ,
V_834 , V_842 ,
V_833 ) )
return;
V_150 = F_5 ( V_836 ) ;
V_150 &= ~ V_823 ;
F_45 ( V_836 , V_150 ) ;
if ( ! V_822 [ 0 ] )
return;
V_150 = F_5 ( V_834 ) ;
V_150 &= ~ V_842 ;
F_45 ( V_834 , V_150 ) ;
V_824 = F_408 ( T_7 , V_822 [ 2 ] , 21 ) ;
F_137 ( L_141 , V_824 ) ;
for ( V_150 = 0 ; V_150 < V_824 ; V_150 ++ )
F_45 ( V_833 , * ( ( T_4 * ) V_822 + V_150 ) ) ;
V_150 = F_5 ( V_836 ) ;
V_150 |= V_823 ;
F_45 ( V_836 , V_150 ) ;
}
void F_534 ( struct V_529 * V_6 ,
struct V_332 * V_411 )
{
struct V_28 * V_29 = V_6 -> V_29 ;
struct V_525 * V_3 ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
V_3 = F_535 ( V_6 , V_411 ) ;
if ( ! V_3 )
return;
F_137 ( L_151 ,
V_3 -> V_8 . V_225 ,
V_3 -> V_123 ,
V_3 -> V_6 -> V_8 . V_225 ,
V_3 -> V_6 -> V_123 ) ;
V_3 -> V_822 [ 6 ] = F_536 ( V_3 , V_411 ) / 2 ;
if ( V_12 -> V_315 . V_848 )
V_12 -> V_315 . V_848 ( V_3 , V_29 , V_411 ) ;
}
static void F_537 ( struct V_28 * V_29 , T_1 V_8 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
T_4 V_849 ;
if ( V_8 != V_73 -> V_850 ) {
if ( V_73 -> V_851 ) {
F_45 ( V_142 , 0 ) ;
F_121 ( V_142 ) ;
V_73 -> V_851 = 0 ;
}
F_45 ( V_852 , V_8 ) ;
F_121 ( V_852 ) ;
}
V_849 = 0 ;
if ( V_8 )
V_849 = ( V_143 |
V_853 |
V_854 ) ;
if ( V_73 -> V_851 != V_849 ) {
F_45 ( V_142 , V_849 ) ;
F_121 ( V_142 ) ;
V_73 -> V_851 = V_849 ;
}
}
static void F_538 ( struct V_28 * V_29 , T_1 V_8 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_4 V_849 ;
V_849 = 0 ;
if ( V_8 ) {
V_849 = V_855 ;
switch ( V_73 -> V_856 ) {
case 64 :
V_849 |= V_857 ;
break;
case 128 :
V_849 |= V_858 ;
break;
case 256 :
V_849 |= V_859 ;
break;
default:
F_3 ( 1 ) ;
return;
}
V_849 |= V_4 << 28 ;
}
if ( V_73 -> V_851 != V_849 ) {
F_45 ( F_76 ( V_4 ) , V_849 ) ;
F_121 ( F_76 ( V_4 ) ) ;
V_73 -> V_851 = V_849 ;
}
F_45 ( F_539 ( V_4 ) , V_8 ) ;
F_121 ( F_539 ( V_4 ) ) ;
}
static void F_540 ( struct V_28 * V_29 , T_1 V_8 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_4 V_849 ;
V_849 = 0 ;
if ( V_8 ) {
V_849 = V_855 ;
switch ( V_73 -> V_856 ) {
case 64 :
V_849 |= V_857 ;
break;
case 128 :
V_849 |= V_858 ;
break;
case 256 :
V_849 |= V_859 ;
break;
default:
F_3 ( 1 ) ;
return;
}
}
if ( F_202 ( V_10 ) || F_165 ( V_10 ) )
V_849 |= V_860 ;
if ( V_73 -> V_851 != V_849 ) {
F_45 ( F_76 ( V_4 ) , V_849 ) ;
F_121 ( F_76 ( V_4 ) ) ;
V_73 -> V_851 = V_849 ;
}
F_45 ( F_539 ( V_4 ) , V_8 ) ;
F_121 ( F_539 ( V_4 ) ) ;
}
static void F_303 ( struct V_28 * V_29 ,
bool V_223 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
int V_267 = V_29 -> V_861 ;
int V_268 = V_29 -> V_862 ;
T_1 V_8 = 0 , V_422 = 0 ;
if ( V_223 )
V_8 = V_73 -> V_863 ;
if ( V_267 >= V_73 -> V_77 . V_337 )
V_8 = 0 ;
if ( V_268 >= V_73 -> V_77 . V_338 )
V_8 = 0 ;
if ( V_267 < 0 ) {
if ( V_267 + V_73 -> V_856 <= 0 )
V_8 = 0 ;
V_422 |= V_864 << V_865 ;
V_267 = - V_267 ;
}
V_422 |= V_267 << V_865 ;
if ( V_268 < 0 ) {
if ( V_268 + V_73 -> V_866 <= 0 )
V_8 = 0 ;
V_422 |= V_864 << V_867 ;
V_268 = - V_268 ;
}
V_422 |= V_268 << V_867 ;
if ( V_8 == 0 && V_73 -> V_850 == 0 )
return;
F_45 ( F_541 ( V_4 ) , V_422 ) ;
if ( F_227 ( V_10 ) || F_202 ( V_10 ) || F_165 ( V_10 ) )
F_540 ( V_29 , V_8 ) ;
else if ( F_74 ( V_10 ) || F_75 ( V_10 ) )
F_537 ( V_29 , V_8 ) ;
else
F_538 ( V_29 , V_8 ) ;
V_73 -> V_850 = V_8 ;
}
static int F_542 ( struct V_28 * V_29 ,
struct V_251 * V_252 ,
T_4 V_297 , T_4 V_248 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_4 V_4 = V_73 -> V_4 ;
unsigned V_868 ;
T_4 V_869 ;
int V_256 ;
if ( ! V_252 ) {
F_46 ( L_152 ) ;
V_869 = 0 ;
V_252 = NULL ;
F_58 ( & V_10 -> V_257 ) ;
goto V_870;
}
if ( ! ( ( V_297 == 64 && V_248 == 64 ) ||
( V_297 == 128 && V_248 == 128 && ! F_20 ( V_10 ) ) ||
( V_297 == 256 && V_248 == 256 && ! F_20 ( V_10 ) ) ) ) {
F_543 ( L_153 ) ;
return - V_262 ;
}
if ( V_252 -> V_8 . V_293 < V_297 * V_248 * 4 ) {
F_46 ( L_154 ) ;
V_256 = - V_871 ;
goto V_872;
}
F_58 ( & V_10 -> V_257 ) ;
if ( ! F_44 ( V_10 ) -> V_873 ) {
unsigned V_255 ;
if ( V_252 -> V_258 ) {
F_46 ( L_155 ) ;
V_256 = - V_262 ;
goto V_874;
}
F_175 ( V_12 ) ;
V_255 = 0 ;
if ( F_167 ( V_10 ) )
V_255 = 64 * 1024 ;
V_256 = F_176 ( V_252 , V_255 , NULL ) ;
if ( V_256 ) {
F_46 ( L_156 ) ;
F_179 ( V_12 ) ;
goto V_874;
}
V_256 = F_544 ( V_252 ) ;
if ( V_256 ) {
F_46 ( L_157 ) ;
F_179 ( V_12 ) ;
goto V_875;
}
V_869 = F_195 ( V_252 ) ;
F_179 ( V_12 ) ;
} else {
int V_876 = F_120 ( V_10 ) ? 16 * 1024 : 256 ;
V_256 = F_545 ( V_252 , V_876 ) ;
if ( V_256 ) {
F_46 ( L_158 ) ;
goto V_874;
}
V_869 = V_252 -> V_877 -> V_878 ;
}
if ( F_20 ( V_10 ) )
F_45 ( V_879 , ( V_248 << 12 ) | V_297 ) ;
V_870:
if ( V_73 -> V_880 ) {
if ( ! F_44 ( V_10 ) -> V_873 )
F_180 ( V_73 -> V_880 ) ;
}
F_219 ( V_73 -> V_880 , V_252 ,
F_546 ( V_4 ) ) ;
F_60 ( & V_10 -> V_257 ) ;
V_868 = V_73 -> V_856 ;
V_73 -> V_863 = V_869 ;
V_73 -> V_880 = V_252 ;
V_73 -> V_856 = V_297 ;
V_73 -> V_866 = V_248 ;
if ( V_73 -> V_74 ) {
if ( V_868 != V_297 )
F_315 ( V_29 ) ;
F_303 ( V_29 , V_73 -> V_880 != NULL ) ;
}
F_224 ( V_10 , F_546 ( V_4 ) ) ;
return 0 ;
V_875:
F_180 ( V_252 ) ;
V_874:
F_60 ( & V_10 -> V_257 ) ;
V_872:
F_547 ( & V_252 -> V_8 ) ;
return V_256 ;
}
static void F_548 ( struct V_28 * V_29 , T_5 * V_881 , T_5 * V_882 ,
T_5 * V_883 , T_4 V_884 , T_4 V_293 )
{
int V_885 = ( V_884 + V_293 > 256 ) ? 256 : V_884 + V_293 , V_150 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
for ( V_150 = V_884 ; V_150 < V_885 ; V_150 ++ ) {
V_73 -> V_435 [ V_150 ] = V_881 [ V_150 ] >> 8 ;
V_73 -> V_436 [ V_150 ] = V_882 [ V_150 ] >> 8 ;
V_73 -> V_437 [ V_150 ] = V_883 [ V_150 ] >> 8 ;
}
F_294 ( V_29 ) ;
}
struct V_301 *
F_549 ( struct V_9 * V_10 ,
struct V_291 * V_292 ,
struct V_251 * V_252 )
{
struct V_697 * V_886 ;
int V_256 ;
V_886 = F_455 ( sizeof( * V_886 ) , V_698 ) ;
if ( ! V_886 ) {
F_547 ( & V_252 -> V_8 ) ;
return F_550 ( - V_871 ) ;
}
V_256 = F_187 ( V_10 , V_886 , V_292 , V_252 ) ;
if ( V_256 )
goto V_61;
return & V_886 -> V_8 ;
V_61:
F_547 ( & V_252 -> V_8 ) ;
F_192 ( V_886 ) ;
return F_550 ( V_256 ) ;
}
static struct V_301 *
F_551 ( struct V_9 * V_10 ,
struct V_291 * V_292 ,
struct V_251 * V_252 )
{
struct V_301 * V_76 ;
int V_256 ;
V_256 = F_552 ( V_10 ) ;
if ( V_256 )
return F_550 ( V_256 ) ;
V_76 = F_549 ( V_10 , V_292 , V_252 ) ;
F_60 ( & V_10 -> V_257 ) ;
return V_76 ;
}
static T_1
F_553 ( int V_297 , int V_750 )
{
T_1 V_270 = F_485 ( V_297 * V_750 , 8 ) ;
return F_170 ( V_270 , 64 ) ;
}
static T_1
F_554 ( struct V_332 * V_411 , int V_750 )
{
T_1 V_270 = F_553 ( V_411 -> V_516 , V_750 ) ;
return F_457 ( V_270 * V_411 -> V_518 ) ;
}
static struct V_301 *
F_555 ( struct V_9 * V_10 ,
struct V_332 * V_411 ,
int V_887 , int V_750 )
{
struct V_251 * V_252 ;
struct V_291 V_292 = { 0 } ;
V_252 = F_556 ( V_10 ,
F_554 ( V_411 , V_750 ) ) ;
if ( V_252 == NULL )
return F_550 ( - V_871 ) ;
V_292 . V_297 = V_411 -> V_516 ;
V_292 . V_248 = V_411 -> V_518 ;
V_292 . V_295 [ 0 ] = F_553 ( V_292 . V_297 ,
V_750 ) ;
V_292 . V_296 = F_557 ( V_750 , V_887 ) ;
return F_551 ( V_10 , & V_292 , V_252 ) ;
}
static struct V_301 *
F_558 ( struct V_9 * V_10 ,
struct V_332 * V_411 )
{
#ifdef F_559
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_251 * V_252 ;
struct V_301 * V_76 ;
if ( ! V_12 -> V_888 )
return NULL ;
if ( ! V_12 -> V_888 -> V_76 )
return NULL ;
V_252 = V_12 -> V_888 -> V_76 -> V_252 ;
F_118 ( ! V_252 ) ;
V_76 = & V_12 -> V_888 -> V_76 -> V_8 ;
if ( V_76 -> V_295 [ 0 ] < F_553 ( V_411 -> V_516 ,
V_76 -> V_312 ) )
return NULL ;
if ( V_252 -> V_8 . V_293 < V_411 -> V_518 * V_76 -> V_295 [ 0 ] )
return NULL ;
return V_76 ;
#else
return NULL ;
#endif
}
bool F_560 ( struct V_525 * V_3 ,
struct V_332 * V_411 ,
struct V_889 * V_890 ,
struct V_891 * V_892 )
{
struct V_73 * V_73 ;
struct V_1 * V_1 =
F_533 ( V_3 ) ;
struct V_28 * V_893 ;
struct V_529 * V_6 = & V_1 -> V_8 ;
struct V_28 * V_29 = NULL ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_301 * V_76 ;
struct V_705 * V_77 = & V_10 -> V_706 ;
int V_256 , V_150 = - 1 ;
F_46 ( L_159 ,
V_3 -> V_8 . V_225 , V_3 -> V_123 ,
V_6 -> V_8 . V_225 , V_6 -> V_123 ) ;
V_362:
V_256 = F_209 ( & V_77 -> V_894 , V_892 ) ;
if ( V_256 )
goto V_895;
if ( V_6 -> V_29 ) {
V_29 = V_6 -> V_29 ;
V_256 = F_209 ( & V_29 -> V_318 , V_892 ) ;
if ( V_256 )
goto V_895;
V_890 -> V_896 = V_3 -> V_527 ;
V_890 -> V_897 = false ;
if ( V_3 -> V_527 != V_530 )
V_3 -> V_794 -> V_527 ( V_3 , V_530 ) ;
return true ;
}
F_193 (dev, possible_crtc) {
V_150 ++ ;
if ( ! ( V_6 -> V_898 & ( 1 << V_150 ) ) )
continue;
if ( V_893 -> V_108 )
continue;
if ( F_35 ( V_893 ) -> V_501 )
continue;
V_29 = V_893 ;
break;
}
if ( ! V_29 ) {
F_46 ( L_160 ) ;
goto V_895;
}
V_256 = F_209 ( & V_29 -> V_318 , V_892 ) ;
if ( V_256 )
goto V_895;
V_1 -> V_899 = F_35 ( V_29 ) ;
F_561 ( V_3 ) -> V_900 = V_1 ;
V_73 = F_35 ( V_29 ) ;
V_73 -> V_501 = true ;
V_73 -> V_502 = & V_73 -> V_77 ;
V_890 -> V_896 = V_3 -> V_527 ;
V_890 -> V_897 = true ;
V_890 -> V_901 = NULL ;
if ( ! V_411 )
V_411 = & V_902 ;
V_76 = F_558 ( V_10 , V_411 ) ;
if ( V_76 == NULL ) {
F_46 ( L_161 ) ;
V_76 = F_555 ( V_10 , V_411 , 24 , 32 ) ;
V_890 -> V_901 = V_76 ;
} else
F_46 ( L_162 ) ;
if ( F_562 ( V_76 ) ) {
F_46 ( L_163 ) ;
goto V_872;
}
if ( F_563 ( V_29 , V_411 , 0 , 0 , V_76 ) ) {
F_46 ( L_164 ) ;
if ( V_890 -> V_901 )
V_890 -> V_901 -> V_794 -> V_903 ( V_890 -> V_901 ) ;
goto V_872;
}
F_42 ( V_10 , V_73 -> V_4 ) ;
return true ;
V_872:
V_73 -> V_501 = V_29 -> V_108 ;
if ( V_73 -> V_501 )
V_73 -> V_502 = & V_73 -> V_77 ;
else
V_73 -> V_502 = NULL ;
V_895:
if ( V_256 == - V_904 ) {
F_564 ( V_892 ) ;
goto V_362;
}
return false ;
}
void F_565 ( struct V_525 * V_3 ,
struct V_889 * V_890 )
{
struct V_1 * V_1 =
F_533 ( V_3 ) ;
struct V_529 * V_6 = & V_1 -> V_8 ;
struct V_28 * V_29 = V_6 -> V_29 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
F_46 ( L_159 ,
V_3 -> V_8 . V_225 , V_3 -> V_123 ,
V_6 -> V_8 . V_225 , V_6 -> V_123 ) ;
if ( V_890 -> V_897 ) {
F_561 ( V_3 ) -> V_900 = NULL ;
V_1 -> V_899 = NULL ;
V_73 -> V_501 = false ;
V_73 -> V_502 = NULL ;
F_563 ( V_29 , NULL , 0 , 0 , NULL ) ;
if ( V_890 -> V_901 ) {
F_566 ( V_890 -> V_901 ) ;
F_567 ( V_890 -> V_901 ) ;
}
return;
}
if ( V_890 -> V_896 != V_530 )
V_3 -> V_794 -> V_527 ( V_3 , V_890 -> V_896 ) ;
}
static int F_568 ( struct V_9 * V_10 ,
const struct V_450 * V_451 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_54 = V_451 -> V_200 . V_54 ;
if ( ( V_54 & V_905 ) == V_646 )
return V_12 -> V_579 . V_583 ;
else if ( F_4 ( V_10 ) )
return 120000 ;
else if ( ! F_20 ( V_10 ) )
return 96000 ;
else
return 48000 ;
}
static void F_460 ( struct V_73 * V_29 ,
struct V_450 * V_451 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_451 -> V_82 ;
T_1 V_54 = V_451 -> V_200 . V_54 ;
T_1 V_585 ;
T_2 clock ;
int V_18 = F_568 ( V_10 , V_451 ) ;
if ( ( V_54 & V_906 ) == 0 )
V_585 = V_451 -> V_200 . V_507 ;
else
V_585 = V_451 -> V_200 . V_508 ;
clock . V_20 = ( V_585 & V_907 ) >> V_908 ;
if ( F_17 ( V_10 ) ) {
clock . V_25 = F_569 ( ( V_585 & V_909 ) >> V_910 ) - 1 ;
clock . V_21 = ( V_585 & V_911 ) >> V_912 ;
} else {
clock . V_25 = ( V_585 & V_913 ) >> V_910 ;
clock . V_21 = ( V_585 & V_914 ) >> V_912 ;
}
if ( ! F_20 ( V_10 ) ) {
if ( F_17 ( V_10 ) )
clock . V_23 = F_569 ( ( V_54 & V_915 ) >>
V_636 ) ;
else
clock . V_23 = F_569 ( ( V_54 & V_916 ) >>
V_637 ) ;
switch ( V_54 & V_917 ) {
case V_633 :
clock . V_24 = V_54 & V_639 ?
5 : 10 ;
break;
case V_632 :
clock . V_24 = V_54 & V_640 ?
7 : 14 ;
break;
default:
F_46 ( L_165
L_166 , ( int ) ( V_54 & V_917 ) ) ;
return;
}
if ( F_17 ( V_10 ) )
F_21 ( V_18 , & clock ) ;
else
F_23 ( V_18 , & clock ) ;
} else {
T_1 V_918 = F_120 ( V_10 ) ? 0 : F_5 ( V_137 ) ;
bool V_686 = ( V_4 == 1 ) && ( V_918 & V_174 ) ;
if ( V_686 ) {
clock . V_23 = F_569 ( ( V_54 & V_919 ) >>
V_637 ) ;
if ( V_918 & V_920 )
clock . V_24 = 7 ;
else
clock . V_24 = 14 ;
} else {
if ( V_54 & V_648 )
clock . V_23 = 2 ;
else {
clock . V_23 = ( ( V_54 & V_921 ) >>
V_637 ) + 2 ;
}
if ( V_54 & V_649 )
clock . V_24 = 4 ;
else
clock . V_24 = 2 ;
}
F_23 ( V_18 , & clock ) ;
}
V_451 -> V_615 = clock . V_27 ;
}
int F_570 ( int V_922 ,
const struct V_571 * V_572 )
{
if ( ! V_572 -> V_577 )
return 0 ;
return F_32 ( ( V_923 ) V_572 -> V_576 * V_922 , V_572 -> V_577 ) ;
}
static void F_498 ( struct V_73 * V_29 ,
struct V_450 * V_451 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
F_460 ( V_29 , V_451 ) ;
V_451 -> V_78 . V_79 =
F_570 ( F_6 ( V_10 ) * 10000 ,
& V_451 -> V_441 ) ;
}
struct V_332 * F_571 ( struct V_9 * V_10 ,
struct V_28 * V_29 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_80 V_82 = V_73 -> V_77 . V_82 ;
struct V_332 * V_411 ;
struct V_450 V_451 ;
int V_924 = F_5 ( F_257 ( V_82 ) ) ;
int V_925 = F_5 ( F_261 ( V_82 ) ) ;
int V_926 = F_5 ( F_263 ( V_82 ) ) ;
int V_927 = F_5 ( F_267 ( V_82 ) ) ;
enum V_4 V_4 = V_73 -> V_4 ;
V_411 = F_455 ( sizeof( * V_411 ) , V_698 ) ;
if ( ! V_411 )
return NULL ;
V_451 . V_82 = (enum V_80 ) V_4 ;
V_451 . V_595 = 1 ;
V_451 . V_200 . V_54 = F_5 ( F_56 ( V_4 ) ) ;
V_451 . V_200 . V_507 = F_5 ( F_367 ( V_4 ) ) ;
V_451 . V_200 . V_508 = F_5 ( F_368 ( V_4 ) ) ;
F_460 ( V_73 , & V_451 ) ;
V_411 -> clock = V_451 . V_615 / V_451 . V_595 ;
V_411 -> V_516 = ( V_924 & 0xffff ) + 1 ;
V_411 -> V_665 = ( ( V_924 & 0xffff0000 ) >> 16 ) + 1 ;
V_411 -> V_543 = ( V_925 & 0xffff ) + 1 ;
V_411 -> V_666 = ( ( V_925 & 0xffff0000 ) >> 16 ) + 1 ;
V_411 -> V_518 = ( V_926 & 0xffff ) + 1 ;
V_411 -> V_667 = ( ( V_926 & 0xffff0000 ) >> 16 ) + 1 ;
V_411 -> V_668 = ( V_927 & 0xffff ) + 1 ;
V_411 -> V_669 = ( ( V_927 & 0xffff0000 ) >> 16 ) + 1 ;
F_572 ( V_411 ) ;
return V_411 ;
}
static void F_205 ( struct V_9 * V_10 ,
enum V_4 V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_217 = F_56 ( V_4 ) ;
int V_54 ;
if ( ! F_296 ( V_10 ) )
return;
if ( ! V_12 -> V_689 )
return;
V_54 = F_5 ( V_217 ) ;
if ( ! F_450 ( V_10 ) && ( V_54 & V_906 ) ) {
F_137 ( L_167 ) ;
F_71 ( V_12 , V_4 ) ;
V_54 &= ~ V_906 ;
F_45 ( V_217 , V_54 ) ;
F_42 ( V_10 , V_4 ) ;
V_54 = F_5 ( V_217 ) ;
if ( V_54 & V_906 )
F_137 ( L_168 ) ;
}
}
static void F_573 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
if ( ! F_296 ( V_10 ) )
return;
if ( ! V_12 -> V_689 )
return;
if ( ! F_450 ( V_10 ) && V_73 -> V_587 ) {
int V_4 = V_73 -> V_4 ;
int V_217 = F_56 ( V_4 ) ;
int V_54 ;
F_137 ( L_169 ) ;
F_71 ( V_12 , V_4 ) ;
V_54 = F_5 ( V_217 ) ;
V_54 |= V_906 ;
F_45 ( V_217 , V_54 ) ;
F_42 ( V_10 , V_4 ) ;
V_54 = F_5 ( V_217 ) ;
if ( ! ( V_54 & V_906 ) )
F_137 ( L_170 ) ;
}
}
void F_574 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_12 -> V_263 . V_928 )
return;
F_175 ( V_12 ) ;
F_575 ( V_12 ) ;
V_12 -> V_263 . V_928 = true ;
}
void F_576 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 ;
if ( ! V_12 -> V_263 . V_928 )
return;
V_12 -> V_263 . V_928 = false ;
if ( ! V_330 . V_588 )
goto V_929;
F_193 (dev, crtc) {
if ( ! V_29 -> V_75 -> V_76 )
continue;
F_573 ( V_29 ) ;
}
if ( F_44 ( V_10 ) -> V_86 >= 6 )
F_577 ( V_10 -> V_13 ) ;
V_929:
F_179 ( V_12 ) ;
}
static void F_578 ( struct V_9 * V_10 ,
unsigned V_299 ,
struct V_253 * V_930 )
{
enum V_4 V_4 ;
if ( ! V_330 . V_588 )
return;
F_84 (pipe) {
if ( ! ( V_299 & F_304 ( V_4 ) ) )
continue;
F_205 ( V_10 , V_4 ) ;
if ( V_930 && F_579 ( V_10 ) )
V_930 -> V_931 = true ;
}
}
void F_580 ( struct V_251 * V_252 ,
struct V_253 * V_930 )
{
struct V_9 * V_10 = V_252 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_3 ( ! F_172 ( & V_10 -> V_257 ) ) ;
if ( ! V_252 -> V_299 )
return;
if ( V_930 ) {
F_58 ( & V_12 -> V_932 . V_792 ) ;
V_12 -> V_932 . V_933
|= V_252 -> V_299 ;
V_12 -> V_932 . V_934
&= ~ V_252 -> V_299 ;
F_60 ( & V_12 -> V_932 . V_792 ) ;
}
F_578 ( V_10 , V_252 -> V_299 , V_930 ) ;
F_581 ( V_10 , V_252 -> V_299 ) ;
}
void F_582 ( struct V_9 * V_10 ,
unsigned V_299 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
F_58 ( & V_12 -> V_932 . V_792 ) ;
V_299 &= ~ V_12 -> V_932 . V_933 ;
F_60 ( & V_12 -> V_932 . V_792 ) ;
F_578 ( V_10 , V_299 , NULL ) ;
F_583 ( V_10 , V_299 ) ;
}
void F_584 ( struct V_251 * V_252 ,
bool V_935 )
{
struct V_9 * V_10 = V_252 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned V_299 ;
F_3 ( ! F_172 ( & V_10 -> V_257 ) ) ;
if ( ! V_252 -> V_299 )
return;
V_299 = V_252 -> V_299 ;
if ( V_935 ) {
F_58 ( & V_12 -> V_932 . V_792 ) ;
V_299 &= V_12 -> V_932 . V_933 ;
V_12 -> V_932 . V_933 &= ~ V_299 ;
F_60 ( & V_12 -> V_932 . V_792 ) ;
}
F_582 ( V_10 , V_299 ) ;
}
void F_585 ( struct V_9 * V_10 ,
unsigned V_299 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
F_58 ( & V_12 -> V_932 . V_792 ) ;
V_12 -> V_932 . V_934
|= V_299 ;
F_60 ( & V_12 -> V_932 . V_792 ) ;
}
void F_586 ( struct V_9 * V_10 ,
unsigned V_299 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
F_58 ( & V_12 -> V_932 . V_792 ) ;
V_299 &= V_12 -> V_932 . V_934 ;
V_12 -> V_932 . V_934 &= ~ V_299 ;
F_60 ( & V_12 -> V_932 . V_792 ) ;
F_582 ( V_10 , V_299 ) ;
}
static void F_587 ( struct V_28 * V_29 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_936 * V_937 ;
unsigned long V_321 ;
F_216 ( & V_10 -> V_325 , V_321 ) ;
V_937 = V_73 -> V_326 ;
V_73 -> V_326 = NULL ;
F_217 ( & V_10 -> V_325 , V_321 ) ;
if ( V_937 ) {
F_588 ( & V_937 -> V_937 ) ;
F_192 ( V_937 ) ;
}
F_589 ( V_29 ) ;
F_192 ( V_73 ) ;
}
static void F_590 ( struct V_938 * V_939 )
{
struct V_936 * V_937 =
F_591 ( V_939 , struct V_936 , V_937 ) ;
struct V_9 * V_10 = V_937 -> V_29 -> V_10 ;
enum V_4 V_4 = F_35 ( V_937 -> V_29 ) -> V_4 ;
F_58 ( & V_10 -> V_257 ) ;
F_181 ( V_937 -> V_940 ) ;
F_190 ( & V_937 -> V_941 -> V_8 ) ;
F_190 ( & V_937 -> V_940 -> V_8 ) ;
F_225 ( V_10 ) ;
F_60 ( & V_10 -> V_257 ) ;
F_586 ( V_10 , F_189 ( V_4 ) ) ;
F_118 ( F_215 ( & F_35 ( V_937 -> V_29 ) -> V_377 ) == 0 ) ;
F_592 ( & F_35 ( V_937 -> V_29 ) -> V_377 ) ;
F_192 ( V_937 ) ;
}
static void F_593 ( struct V_9 * V_10 ,
struct V_28 * V_29 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_936 * V_937 ;
unsigned long V_321 ;
if ( V_73 == NULL )
return;
F_216 ( & V_10 -> V_325 , V_321 ) ;
V_937 = V_73 -> V_326 ;
F_594 () ;
if ( V_937 == NULL || F_215 ( & V_937 -> V_322 ) < V_942 ) {
F_217 ( & V_10 -> V_325 , V_321 ) ;
return;
}
F_594 () ;
V_73 -> V_326 = NULL ;
if ( V_937 -> V_943 )
F_595 ( V_10 , V_73 -> V_4 , V_937 -> V_943 ) ;
F_596 ( V_29 ) ;
F_217 ( & V_10 -> V_325 , V_321 ) ;
F_597 ( & V_12 -> V_378 ) ;
F_598 ( V_12 -> V_944 , & V_937 -> V_937 ) ;
F_599 ( V_73 -> V_148 , V_937 -> V_941 ) ;
}
void F_600 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 = V_12 -> V_81 [ V_4 ] ;
F_593 ( V_10 , V_29 ) ;
}
void F_208 ( struct V_9 * V_10 , int V_148 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 = V_12 -> V_945 [ V_148 ] ;
F_593 ( V_10 , V_29 ) ;
}
static bool F_601 ( T_1 V_946 , T_1 V_947 )
{
return ! ( ( V_946 - V_947 ) & 0x80000000 ) ;
}
static bool F_602 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_44 ( V_10 ) -> V_86 < 5 && ! F_16 ( V_10 ) )
return true ;
return ( F_5 ( F_603 ( V_29 -> V_148 ) ) & ~ 0xfff ) ==
V_29 -> V_326 -> V_948 &&
F_601 ( F_5 ( F_604 ( V_29 -> V_4 ) ) ,
V_29 -> V_326 -> V_949 ) ;
}
void F_207 ( struct V_9 * V_10 , int V_148 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 =
F_35 ( V_12 -> V_945 [ V_148 ] ) ;
unsigned long V_321 ;
F_216 ( & V_10 -> V_325 , V_321 ) ;
if ( V_73 -> V_326 && F_602 ( V_73 ) )
F_605 ( & V_73 -> V_326 -> V_322 ) ;
F_217 ( & V_10 -> V_325 , V_321 ) ;
}
static inline void F_606 ( struct V_73 * V_73 )
{
F_607 () ;
F_608 ( & V_73 -> V_326 -> V_322 , V_950 ) ;
F_607 () ;
}
static int F_609 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
struct V_301 * V_76 ,
struct V_251 * V_252 ,
struct V_253 * V_930 ,
T_4 V_321 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
T_1 V_951 ;
int V_256 ;
V_256 = F_610 ( V_930 , 6 ) ;
if ( V_256 )
return V_256 ;
if ( V_73 -> V_148 )
V_951 = V_952 ;
else
V_951 = V_953 ;
F_611 ( V_930 , V_954 | V_951 ) ;
F_611 ( V_930 , V_955 ) ;
F_611 ( V_930 , V_956 |
F_612 ( V_73 -> V_148 ) ) ;
F_611 ( V_930 , V_76 -> V_295 [ 0 ] ) ;
F_611 ( V_930 , V_73 -> V_326 -> V_948 ) ;
F_611 ( V_930 , 0 ) ;
F_606 ( V_73 ) ;
F_613 ( V_930 ) ;
return 0 ;
}
static int F_614 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
struct V_301 * V_76 ,
struct V_251 * V_252 ,
struct V_253 * V_930 ,
T_4 V_321 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
T_1 V_951 ;
int V_256 ;
V_256 = F_610 ( V_930 , 6 ) ;
if ( V_256 )
return V_256 ;
if ( V_73 -> V_148 )
V_951 = V_952 ;
else
V_951 = V_953 ;
F_611 ( V_930 , V_954 | V_951 ) ;
F_611 ( V_930 , V_955 ) ;
F_611 ( V_930 , V_957 |
F_612 ( V_73 -> V_148 ) ) ;
F_611 ( V_930 , V_76 -> V_295 [ 0 ] ) ;
F_611 ( V_930 , V_73 -> V_326 -> V_948 ) ;
F_611 ( V_930 , V_955 ) ;
F_606 ( V_73 ) ;
F_613 ( V_930 ) ;
return 0 ;
}
static int F_615 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
struct V_301 * V_76 ,
struct V_251 * V_252 ,
struct V_253 * V_930 ,
T_4 V_321 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
T_4 V_958 , V_959 ;
int V_256 ;
V_256 = F_610 ( V_930 , 4 ) ;
if ( V_256 )
return V_256 ;
F_611 ( V_930 , V_956 |
F_612 ( V_73 -> V_148 ) ) ;
F_611 ( V_930 , V_76 -> V_295 [ 0 ] ) ;
F_611 ( V_930 , V_73 -> V_326 -> V_948 |
V_252 -> V_258 ) ;
V_958 = 0 ;
V_959 = F_5 ( F_220 ( V_73 -> V_4 ) ) & 0x0fff0fff ;
F_611 ( V_930 , V_958 | V_959 ) ;
F_606 ( V_73 ) ;
F_613 ( V_930 ) ;
return 0 ;
}
static int F_616 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
struct V_301 * V_76 ,
struct V_251 * V_252 ,
struct V_253 * V_930 ,
T_4 V_321 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
T_4 V_958 , V_959 ;
int V_256 ;
V_256 = F_610 ( V_930 , 4 ) ;
if ( V_256 )
return V_256 ;
F_611 ( V_930 , V_956 |
F_612 ( V_73 -> V_148 ) ) ;
F_611 ( V_930 , V_76 -> V_295 [ 0 ] | V_252 -> V_258 ) ;
F_611 ( V_930 , V_73 -> V_326 -> V_948 ) ;
V_958 = 0 ;
V_959 = F_5 ( F_220 ( V_73 -> V_4 ) ) & 0x0fff0fff ;
F_611 ( V_930 , V_958 | V_959 ) ;
F_606 ( V_73 ) ;
F_613 ( V_930 ) ;
return 0 ;
}
static int F_617 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
struct V_301 * V_76 ,
struct V_251 * V_252 ,
struct V_253 * V_930 ,
T_4 V_321 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
T_4 V_960 = 0 ;
int V_824 , V_256 ;
switch ( V_73 -> V_148 ) {
case V_961 :
V_960 = V_962 ;
break;
case V_963 :
V_960 = V_964 ;
break;
case V_965 :
V_960 = V_966 ;
break;
default:
F_618 ( 1 , L_171 ) ;
return - V_967 ;
}
V_824 = 4 ;
if ( V_930 -> V_225 == V_968 ) {
V_824 += 6 ;
if ( F_619 ( V_10 ) )
V_824 += 2 ;
}
V_256 = F_620 ( V_930 ) ;
if ( V_256 )
return V_256 ;
V_256 = F_610 ( V_930 , V_824 ) ;
if ( V_256 )
return V_256 ;
if ( V_930 -> V_225 == V_968 ) {
F_611 ( V_930 , F_621 ( 1 ) ) ;
F_611 ( V_930 , V_969 ) ;
F_611 ( V_930 , ~ ( V_970 |
V_971 |
V_972 ) ) ;
if ( F_619 ( V_10 ) )
F_611 ( V_930 , F_622 ( 1 ) |
V_973 ) ;
else
F_611 ( V_930 , F_623 ( 1 ) |
V_973 ) ;
F_611 ( V_930 , V_969 ) ;
F_611 ( V_930 , V_930 -> V_974 . V_948 + 256 ) ;
if ( F_619 ( V_10 ) ) {
F_611 ( V_930 , 0 ) ;
F_611 ( V_930 , V_955 ) ;
}
}
F_611 ( V_930 , V_957 | V_960 ) ;
F_611 ( V_930 , ( V_76 -> V_295 [ 0 ] | V_252 -> V_258 ) ) ;
F_611 ( V_930 , V_73 -> V_326 -> V_948 ) ;
F_611 ( V_930 , ( V_955 ) ) ;
F_606 ( V_73 ) ;
F_613 ( V_930 ) ;
return 0 ;
}
static bool F_624 ( struct V_253 * V_930 ,
struct V_251 * V_252 )
{
if ( V_930 == NULL )
return true ;
if ( F_44 ( V_930 -> V_10 ) -> V_86 < 5 )
return false ;
if ( V_330 . F_624 < 0 )
return false ;
else if ( V_330 . F_624 > 0 )
return true ;
else
return V_930 != V_252 -> V_930 ;
}
static void F_625 ( struct V_73 * V_73 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_697 * V_886 =
F_188 ( V_73 -> V_8 . V_75 -> V_76 ) ;
struct V_251 * V_252 = V_886 -> V_252 ;
T_1 V_303 ;
T_1 V_88 ;
F_606 ( V_73 ) ;
V_88 = F_81 ( V_73 -> V_148 ) ;
V_303 = F_5 ( V_88 ) ;
if ( F_44 ( V_10 ) -> V_86 >= 4 ) {
if ( V_252 -> V_258 != V_259 )
V_303 |= V_310 ;
else
V_303 &= ~ V_310 ;
}
F_45 ( V_88 , V_303 ) ;
F_45 ( F_161 ( V_73 -> V_148 ) ,
V_73 -> V_326 -> V_948 ) ;
F_121 ( F_161 ( V_73 -> V_148 ) ) ;
}
static int F_626 ( struct V_251 * V_252 )
{
struct V_253 * V_930 ;
int V_256 ;
F_627 ( & V_252 -> V_8 . V_10 -> V_257 ) ;
if ( ! V_252 -> V_975 )
return 0 ;
V_930 = V_252 -> V_930 ;
if ( F_628 ( V_930 -> V_976 ( V_930 , true ) ,
V_252 -> V_975 ) )
return 0 ;
V_256 = F_629 ( V_930 , V_252 -> V_975 ) ;
if ( V_256 )
return V_256 ;
if ( F_3 ( ! V_930 -> V_977 ( V_930 ) ) )
return 0 ;
return 1 ;
}
void F_630 ( struct V_253 * V_930 )
{
struct V_11 * V_12 = F_631 ( V_930 -> V_10 ) ;
struct V_73 * V_73 ;
unsigned long V_978 ;
T_1 V_979 ;
V_979 = V_930 -> V_976 ( V_930 , false ) ;
F_216 ( & V_12 -> V_980 , V_978 ) ;
F_244 (ring->dev, intel_crtc) {
struct V_981 * V_982 ;
V_982 = & V_73 -> V_982 ;
if ( V_982 -> V_979 == 0 )
continue;
if ( V_930 -> V_225 != V_982 -> V_983 )
continue;
if ( F_628 ( V_979 , V_982 -> V_979 ) ) {
F_625 ( V_73 ) ;
V_982 -> V_979 = 0 ;
V_930 -> V_984 ( V_930 ) ;
}
}
F_217 ( & V_12 -> V_980 , V_978 ) ;
}
static int F_632 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
struct V_301 * V_76 ,
struct V_251 * V_252 ,
struct V_253 * V_930 ,
T_4 V_321 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
unsigned long V_978 ;
int V_256 ;
if ( F_3 ( V_73 -> V_982 . V_979 ) )
return - V_328 ;
V_256 = F_626 ( V_252 ) ;
if ( V_256 < 0 )
return V_256 ;
if ( V_256 == 0 ) {
F_625 ( V_73 ) ;
return 0 ;
}
F_216 ( & V_12 -> V_980 , V_978 ) ;
V_73 -> V_982 . V_979 = V_252 -> V_975 ;
V_73 -> V_982 . V_983 = V_252 -> V_930 -> V_225 ;
F_217 ( & V_12 -> V_980 , V_978 ) ;
F_630 ( V_252 -> V_930 ) ;
return 0 ;
}
static int F_633 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
struct V_301 * V_76 ,
struct V_251 * V_252 ,
struct V_253 * V_930 ,
T_4 V_321 )
{
return - V_967 ;
}
static int F_634 ( struct V_28 * V_29 ,
struct V_301 * V_76 ,
struct V_985 * V_943 ,
T_4 V_986 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_301 * V_319 = V_29 -> V_75 -> V_76 ;
struct V_251 * V_252 = F_194 ( V_76 ) ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_4 V_4 = V_73 -> V_4 ;
struct V_936 * V_937 ;
struct V_253 * V_930 ;
unsigned long V_321 ;
int V_256 ;
if ( F_3 ( F_194 ( V_319 ) == NULL ) )
return - V_328 ;
if ( V_76 -> V_296 != V_29 -> V_75 -> V_76 -> V_296 )
return - V_262 ;
if ( F_44 ( V_10 ) -> V_86 > 3 &&
( V_76 -> V_987 [ 0 ] != V_29 -> V_75 -> V_76 -> V_987 [ 0 ] ||
V_76 -> V_295 [ 0 ] != V_29 -> V_75 -> V_76 -> V_295 [ 0 ] ) )
return - V_262 ;
if ( F_635 ( & V_12 -> V_323 ) )
goto V_988;
V_937 = F_455 ( sizeof( * V_937 ) , V_698 ) ;
if ( V_937 == NULL )
return - V_871 ;
V_937 -> V_943 = V_943 ;
V_937 -> V_29 = V_29 ;
V_937 -> V_940 = F_194 ( V_319 ) ;
F_636 ( & V_937 -> V_937 , F_590 ) ;
V_256 = F_637 ( V_29 ) ;
if ( V_256 )
goto V_989;
F_216 ( & V_10 -> V_325 , V_321 ) ;
if ( V_73 -> V_326 ) {
F_217 ( & V_10 -> V_325 , V_321 ) ;
F_192 ( V_937 ) ;
F_596 ( V_29 ) ;
F_137 ( L_172 ) ;
return - V_328 ;
}
V_73 -> V_326 = V_937 ;
F_217 ( & V_10 -> V_325 , V_321 ) ;
if ( F_215 ( & V_73 -> V_377 ) >= 2 )
F_638 ( V_12 -> V_944 ) ;
V_256 = F_552 ( V_10 ) ;
if ( V_256 )
goto V_990;
F_639 ( & V_937 -> V_940 -> V_8 ) ;
F_639 ( & V_252 -> V_8 ) ;
V_29 -> V_75 -> V_76 = V_76 ;
V_937 -> V_941 = V_252 ;
V_937 -> V_991 = true ;
F_640 ( & V_73 -> V_377 ) ;
V_73 -> V_324 = F_215 ( & V_12 -> V_323 . V_324 ) ;
if ( F_44 ( V_10 ) -> V_86 >= 5 || F_16 ( V_10 ) )
V_937 -> V_949 = F_5 ( F_604 ( V_4 ) ) + 1 ;
if ( F_19 ( V_10 ) ) {
V_930 = & V_12 -> V_930 [ V_992 ] ;
if ( V_252 -> V_258 != V_937 -> V_940 -> V_258 )
V_930 = NULL ;
} else if ( F_227 ( V_10 ) ) {
V_930 = & V_12 -> V_930 [ V_992 ] ;
} else if ( F_44 ( V_10 ) -> V_86 >= 7 ) {
V_930 = V_252 -> V_930 ;
if ( V_930 == NULL || V_930 -> V_225 != V_968 )
V_930 = & V_12 -> V_930 [ V_992 ] ;
} else {
V_930 = & V_12 -> V_930 [ V_968 ] ;
}
V_256 = F_171 ( V_10 , V_252 , V_930 ) ;
if ( V_256 )
goto V_993;
V_937 -> V_948 =
F_195 ( V_252 ) + V_73 -> V_313 ;
if ( F_624 ( V_930 , V_252 ) )
V_256 = F_632 ( V_10 , V_29 , V_76 , V_252 , V_930 ,
V_986 ) ;
else
V_256 = V_12 -> V_315 . V_994 ( V_10 , V_29 , V_76 , V_252 , V_930 ,
V_986 ) ;
if ( V_256 )
goto V_995;
F_219 ( V_937 -> V_940 , V_252 ,
F_189 ( V_4 ) ) ;
F_306 ( V_10 ) ;
F_585 ( V_10 , F_189 ( V_4 ) ) ;
F_60 ( & V_10 -> V_257 ) ;
F_641 ( V_73 -> V_148 , V_252 ) ;
return 0 ;
V_995:
F_181 ( V_252 ) ;
V_993:
F_592 ( & V_73 -> V_377 ) ;
V_29 -> V_75 -> V_76 = V_319 ;
F_190 ( & V_937 -> V_940 -> V_8 ) ;
F_190 ( & V_252 -> V_8 ) ;
F_60 ( & V_10 -> V_257 ) ;
V_990:
F_216 ( & V_10 -> V_325 , V_321 ) ;
V_73 -> V_326 = NULL ;
F_217 ( & V_10 -> V_325 , V_321 ) ;
F_596 ( V_29 ) ;
V_989:
F_192 ( V_937 ) ;
if ( V_256 == - V_996 ) {
V_988:
F_245 ( V_29 ) ;
V_256 = F_218 ( V_29 , V_29 -> V_267 , V_29 -> V_268 , V_76 ) ;
if ( V_256 == 0 && V_943 )
F_595 ( V_10 , V_4 , V_943 ) ;
}
return V_256 ;
}
static void F_642 ( struct V_9 * V_10 )
{
struct V_73 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_378 (connector, &dev->mode_config.connector_list,
base.head) {
V_3 -> V_900 =
F_379 ( V_3 -> V_8 . V_6 ) ;
}
F_378 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_6 -> V_899 =
F_35 ( V_6 -> V_8 . V_29 ) ;
}
F_244 (dev, crtc) {
V_29 -> V_501 = V_29 -> V_8 . V_108 ;
if ( V_29 -> V_501 )
V_29 -> V_502 = & V_29 -> V_77 ;
else
V_29 -> V_502 = NULL ;
}
}
static void F_643 ( struct V_9 * V_10 )
{
struct V_73 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_378 (connector, &dev->mode_config.connector_list,
base.head) {
V_3 -> V_8 . V_6 = & V_3 -> V_900 -> V_8 ;
}
F_378 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_6 -> V_8 . V_29 = & V_6 -> V_899 -> V_8 ;
}
F_244 (dev, crtc) {
V_29 -> V_8 . V_108 = V_29 -> V_501 ;
}
}
static void
F_644 ( struct V_2 * V_3 ,
struct V_450 * V_451 )
{
int V_750 = V_451 -> V_537 ;
F_46 ( L_173 ,
V_3 -> V_8 . V_8 . V_225 ,
V_3 -> V_8 . V_123 ) ;
if ( V_3 -> V_8 . V_997 . V_406 &&
V_3 -> V_8 . V_997 . V_406 * 3 < V_750 ) {
F_46 ( L_174 ,
V_750 , V_3 -> V_8 . V_997 . V_406 * 3 ) ;
V_451 -> V_537 = V_3 -> V_8 . V_997 . V_406 * 3 ;
}
if ( V_3 -> V_8 . V_997 . V_406 == 0 && V_750 > 24 ) {
F_46 ( L_175 ,
V_750 ) ;
V_451 -> V_537 = 24 ;
}
}
static int
F_645 ( struct V_73 * V_29 ,
struct V_301 * V_76 ,
struct V_450 * V_451 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_2 * V_3 ;
int V_750 ;
switch ( V_76 -> V_296 ) {
case V_276 :
V_750 = 8 * 3 ;
break;
case V_278 :
case V_305 :
if ( F_3 ( F_44 ( V_10 ) -> V_86 > 3 ) )
return - V_262 ;
case V_280 :
V_750 = 6 * 3 ;
break;
case V_284 :
case V_307 :
if ( F_3 ( F_44 ( V_10 ) -> V_86 < 4 ) )
return - V_262 ;
case V_282 :
case V_306 :
V_750 = 8 * 3 ;
break;
case V_286 :
case V_308 :
case V_288 :
case V_309 :
if ( F_3 ( F_44 ( V_10 ) -> V_86 < 4 ) )
return - V_262 ;
V_750 = 10 * 3 ;
break;
default:
F_46 ( L_176 ) ;
return - V_262 ;
}
V_451 -> V_537 = V_750 ;
F_378 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_3 -> V_900 ||
V_3 -> V_900 -> V_899 != V_29 )
continue;
F_644 ( V_3 , V_451 ) ;
}
return V_750 ;
}
static void F_646 ( const struct V_332 * V_411 )
{
F_46 ( L_177
L_178 ,
V_411 -> V_79 ,
V_411 -> V_333 , V_411 -> V_656 ,
V_411 -> V_659 , V_411 -> V_655 ,
V_411 -> V_334 , V_411 -> V_661 ,
V_411 -> V_662 , V_411 -> V_651 , V_411 -> type , V_411 -> V_321 ) ;
}
static void F_647 ( struct V_73 * V_29 ,
struct V_450 * V_451 ,
const char * V_998 )
{
F_46 ( L_179 , V_29 -> V_8 . V_8 . V_225 ,
V_998 , F_72 ( V_29 -> V_4 ) ) ;
F_46 ( L_180 , F_648 ( V_451 -> V_82 ) ) ;
F_46 ( L_181 ,
V_451 -> V_537 , V_451 -> V_672 ) ;
F_46 ( L_182 ,
V_451 -> V_245 ,
V_451 -> V_357 ,
V_451 -> V_441 . V_574 , V_451 -> V_441 . V_575 ,
V_451 -> V_441 . V_576 , V_451 -> V_441 . V_577 ,
V_451 -> V_441 . V_573 ) ;
F_46 ( L_183 ,
V_451 -> V_440 ,
V_451 -> V_591 . V_574 , V_451 -> V_591 . V_575 ,
V_451 -> V_591 . V_576 , V_451 -> V_591 . V_577 ,
V_451 -> V_591 . V_573 ) ;
F_46 ( L_184 ) ;
F_649 ( & V_451 -> V_664 ) ;
F_46 ( L_185 ) ;
F_649 ( & V_451 -> V_78 ) ;
F_646 ( & V_451 -> V_78 ) ;
F_46 ( L_186 , V_451 -> V_615 ) ;
F_46 ( L_187 ,
V_451 -> V_337 , V_451 -> V_338 ) ;
F_46 ( L_188 ,
V_451 -> V_452 . V_453 ,
V_451 -> V_452 . V_457 ,
V_451 -> V_452 . V_693 ) ;
F_46 ( L_189 ,
V_451 -> V_335 . V_422 ,
V_451 -> V_335 . V_293 ,
V_451 -> V_335 . V_108 ? L_190 : L_191 ) ;
F_46 ( L_192 , V_451 -> V_425 ) ;
F_46 ( L_193 , V_451 -> V_542 ) ;
}
static bool F_650 ( const struct V_1 * V_946 ,
const struct V_1 * V_947 )
{
return V_946 == V_947 || ( V_946 -> V_999 & ( 1 << V_947 -> type ) &&
V_947 -> V_999 & ( 1 << V_946 -> type ) ) ;
}
static bool F_651 ( struct V_73 * V_29 ,
struct V_1 * V_6 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_1000 ;
F_378 (source_encoder,
&dev->mode_config.encoder_list, base.head) {
if ( V_1000 -> V_899 != V_29 )
continue;
if ( ! F_650 ( V_6 , V_1000 ) )
return false ;
}
return true ;
}
static bool F_652 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_6 ;
F_378 (encoder,
&dev->mode_config.encoder_list, base.head) {
if ( V_6 -> V_899 != V_29 )
continue;
if ( ! F_651 ( V_29 , V_6 ) )
return false ;
}
return true ;
}
static struct V_450 *
F_653 ( struct V_28 * V_29 ,
struct V_301 * V_76 ,
struct V_332 * V_411 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_6 ;
struct V_450 * V_451 ;
int V_1001 , V_256 = - V_262 ;
bool V_362 = true ;
if ( ! F_652 ( F_35 ( V_29 ) ) ) {
F_46 ( L_194 ) ;
return F_550 ( - V_262 ) ;
}
V_451 = F_455 ( sizeof( * V_451 ) , V_698 ) ;
if ( ! V_451 )
return F_550 ( - V_871 ) ;
F_654 ( & V_451 -> V_78 , V_411 ) ;
F_654 ( & V_451 -> V_664 , V_411 ) ;
V_451 -> V_82 =
(enum V_80 ) F_35 ( V_29 ) -> V_4 ;
V_451 -> V_117 = V_416 ;
if ( ! ( V_451 -> V_78 . V_321 &
( V_412 | V_1002 ) ) )
V_451 -> V_78 . V_321 |= V_1002 ;
if ( ! ( V_451 -> V_78 . V_321 &
( V_414 | V_1003 ) ) )
V_451 -> V_78 . V_321 |= V_1003 ;
V_1001 = F_645 ( F_35 ( V_29 ) ,
V_76 , V_451 ) ;
if ( V_1001 < 0 )
goto V_872;
F_655 ( & V_451 -> V_664 , V_1004 ) ;
V_451 -> V_337 = V_451 -> V_664 . V_333 ;
V_451 -> V_338 = V_451 -> V_664 . V_334 ;
V_1005:
V_451 -> V_615 = 0 ;
V_451 -> V_595 = 1 ;
F_655 ( & V_451 -> V_78 , V_1004 ) ;
F_378 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( & V_6 -> V_899 -> V_8 != V_29 )
continue;
if ( ! ( V_6 -> V_1006 ( V_6 , V_451 ) ) ) {
F_46 ( L_195 ) ;
goto V_872;
}
}
if ( ! V_451 -> V_615 )
V_451 -> V_615 = V_451 -> V_78 . V_79
* V_451 -> V_595 ;
V_256 = F_394 ( F_35 ( V_29 ) , V_451 ) ;
if ( V_256 < 0 ) {
F_46 ( L_196 ) ;
goto V_872;
}
if ( V_256 == V_539 ) {
if ( F_41 ( ! V_362 , L_197 ) ) {
V_256 = - V_262 ;
goto V_872;
}
F_46 ( L_198 ) ;
V_362 = false ;
goto V_1005;
}
V_451 -> V_672 = V_451 -> V_537 != V_1001 ;
F_46 ( L_199 ,
V_1001 , V_451 -> V_537 , V_451 -> V_672 ) ;
return V_451 ;
V_872:
F_192 ( V_451 ) ;
return F_550 ( V_256 ) ;
}
static void
F_656 ( struct V_28 * V_29 , unsigned * V_1007 ,
unsigned * V_503 , unsigned * V_1008 )
{
struct V_73 * V_73 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
struct V_28 * V_1009 ;
* V_1008 = * V_1007 = * V_503 = 0 ;
F_378 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_8 . V_6 == & V_3 -> V_900 -> V_8 )
continue;
if ( V_3 -> V_8 . V_6 ) {
V_1009 = V_3 -> V_8 . V_6 -> V_29 ;
* V_503 |= 1 << F_35 ( V_1009 ) -> V_4 ;
}
if ( V_3 -> V_900 )
* V_503 |=
1 << V_3 -> V_900 -> V_899 -> V_4 ;
}
F_378 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_6 -> V_8 . V_29 == & V_6 -> V_899 -> V_8 )
continue;
if ( V_6 -> V_8 . V_29 ) {
V_1009 = V_6 -> V_8 . V_29 ;
* V_503 |= 1 << F_35 ( V_1009 ) -> V_4 ;
}
if ( V_6 -> V_899 )
* V_503 |= 1 << V_6 -> V_899 -> V_4 ;
}
F_244 (dev, intel_crtc) {
if ( V_73 -> V_8 . V_108 == V_73 -> V_501 )
continue;
if ( ! V_73 -> V_501 )
* V_1008 |= 1 << V_73 -> V_4 ;
else
* V_503 |= 1 << V_73 -> V_4 ;
}
V_73 = F_35 ( V_29 ) ;
if ( V_73 -> V_501 )
* V_503 |= 1 << V_73 -> V_4 ;
if ( * V_503 )
* V_1007 = * V_503 ;
* V_1007 &= ~ ( * V_1008 ) ;
* V_503 &= ~ ( * V_1008 ) ;
* V_1007 &= 1 << V_73 -> V_4 ;
* V_503 &= 1 << V_73 -> V_4 ;
F_46 ( L_200 ,
* V_1007 , * V_503 , * V_1008 ) ;
}
static bool F_657 ( struct V_28 * V_29 )
{
struct V_529 * V_6 ;
struct V_9 * V_10 = V_29 -> V_10 ;
F_378 (encoder, &dev->mode_config.encoder_list, head)
if ( V_6 -> V_29 == V_29 )
return true ;
return false ;
}
static void
F_658 ( struct V_9 * V_10 , unsigned V_503 )
{
struct V_1 * V_1 ;
struct V_73 * V_73 ;
struct V_525 * V_3 ;
F_378 (intel_encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_1 -> V_8 . V_29 )
continue;
V_73 = F_35 ( V_1 -> V_8 . V_29 ) ;
if ( V_503 & ( 1 << V_73 -> V_4 ) )
V_1 -> V_524 = false ;
}
F_643 ( V_10 ) ;
F_244 (dev, intel_crtc) {
F_3 ( V_73 -> V_8 . V_108 != F_657 ( & V_73 -> V_8 ) ) ;
F_3 ( V_73 -> V_502 &&
V_73 -> V_502 != & V_73 -> V_77 ) ;
F_3 ( V_73 -> V_8 . V_108 != ! ! V_73 -> V_502 ) ;
}
F_378 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_3 -> V_6 || ! V_3 -> V_6 -> V_29 )
continue;
V_73 = F_35 ( V_3 -> V_6 -> V_29 ) ;
if ( V_503 & ( 1 << V_73 -> V_4 ) ) {
struct V_1010 * V_1011 =
V_10 -> V_706 . V_1011 ;
V_3 -> V_527 = V_530 ;
F_659 ( & V_3 -> V_8 ,
V_1011 ,
V_530 ) ;
V_1 = F_379 ( V_3 -> V_6 ) ;
V_1 -> V_524 = true ;
}
}
}
static bool F_660 ( int V_1012 , int V_1013 )
{
int V_71 ;
if ( V_1012 == V_1013 )
return true ;
if ( ! V_1012 || ! V_1013 )
return false ;
V_71 = abs ( V_1012 - V_1013 ) ;
if ( ( ( ( ( V_71 + V_1012 + V_1013 ) * 100 ) ) / ( V_1012 + V_1013 ) ) < 105 )
return true ;
return false ;
}
static bool
F_661 ( struct V_9 * V_10 ,
struct V_450 * V_1014 ,
struct V_450 * V_451 )
{
#define F_662 ( V_123 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_663 ( V_123 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_664 ( V_123 , V_470 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
DRM_ERROR("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
return false; \
}
#define F_665 ( V_123 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_666 ( T_8 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_663 ( V_82 ) ;
F_663 ( V_245 ) ;
F_663 ( V_357 ) ;
F_663 ( V_441 . V_574 ) ;
F_663 ( V_441 . V_575 ) ;
F_663 ( V_441 . V_576 ) ;
F_663 ( V_441 . V_577 ) ;
F_663 ( V_441 . V_573 ) ;
F_663 ( V_440 ) ;
F_663 ( V_591 . V_574 ) ;
F_663 ( V_591 . V_575 ) ;
F_663 ( V_591 . V_576 ) ;
F_663 ( V_591 . V_577 ) ;
F_663 ( V_591 . V_573 ) ;
F_663 ( V_78 . V_333 ) ;
F_663 ( V_78 . V_655 ) ;
F_663 ( V_78 . V_657 ) ;
F_663 ( V_78 . V_658 ) ;
F_663 ( V_78 . V_656 ) ;
F_663 ( V_78 . V_659 ) ;
F_663 ( V_78 . V_334 ) ;
F_663 ( V_78 . V_651 ) ;
F_663 ( V_78 . V_660 ) ;
F_663 ( V_78 . V_652 ) ;
F_663 ( V_78 . V_661 ) ;
F_663 ( V_78 . V_662 ) ;
F_663 ( V_595 ) ;
F_663 ( V_1015 ) ;
if ( ( F_44 ( V_10 ) -> V_86 < 8 && ! F_202 ( V_10 ) ) ||
F_19 ( V_10 ) )
F_663 ( V_682 ) ;
F_663 ( V_1016 ) ;
F_664 ( V_78 . V_321 ,
V_654 ) ;
if ( ! F_666 ( V_1017 ) ) {
F_664 ( V_78 . V_321 ,
V_412 ) ;
F_664 ( V_78 . V_321 ,
V_1002 ) ;
F_664 ( V_78 . V_321 ,
V_414 ) ;
F_664 ( V_78 . V_321 ,
V_1003 ) ;
}
F_663 ( V_337 ) ;
F_663 ( V_338 ) ;
if ( ! F_666 ( V_1018 ) ) {
F_663 ( V_452 . V_453 ) ;
if ( F_44 ( V_10 ) -> V_86 < 4 )
F_663 ( V_452 . V_457 ) ;
F_663 ( V_452 . V_693 ) ;
}
F_663 ( V_335 . V_108 ) ;
if ( V_1014 -> V_335 . V_108 ) {
F_663 ( V_335 . V_422 ) ;
F_663 ( V_335 . V_293 ) ;
}
if ( F_202 ( V_10 ) )
F_663 ( V_425 ) ;
F_663 ( V_542 ) ;
F_662 ( V_803 ) ;
F_663 ( V_117 ) ;
F_662 ( V_200 . V_54 ) ;
F_662 ( V_200 . V_202 ) ;
F_662 ( V_200 . V_507 ) ;
F_662 ( V_200 . V_508 ) ;
F_662 ( V_200 . V_1019 ) ;
if ( F_16 ( V_10 ) || F_44 ( V_10 ) -> V_86 >= 5 )
F_663 ( V_537 ) ;
F_665 ( V_78 . V_79 ) ;
F_665 ( V_615 ) ;
#undef F_662
#undef F_663
#undef F_664
#undef F_665
#undef F_666
return true ;
}
static void
F_667 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
F_378 (connector, &dev->mode_config.connector_list,
base.head) {
F_383 ( V_3 ) ;
F_41 ( & V_3 -> V_900 -> V_8 != V_3 -> V_8 . V_6 ,
L_201 ) ;
}
}
static void
F_668 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_378 (encoder, &dev->mode_config.encoder_list,
base.head) {
bool V_108 = false ;
bool V_74 = false ;
enum V_4 V_4 , V_1020 ;
F_46 ( L_202 ,
V_6 -> V_8 . V_8 . V_225 ,
V_6 -> V_8 . V_123 ) ;
F_41 ( & V_6 -> V_899 -> V_8 != V_6 -> V_8 . V_29 ,
L_203 ) ;
F_41 ( V_6 -> V_524 && ! V_6 -> V_8 . V_29 ,
L_204 ) ;
F_378 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_8 . V_6 != & V_6 -> V_8 )
continue;
V_108 = true ;
if ( V_3 -> V_8 . V_527 != V_528 )
V_74 = true ;
}
if ( ! V_108 && V_6 -> V_8 . V_1021 == V_1022 )
continue;
F_41 ( ! ! V_6 -> V_8 . V_29 != V_108 ,
L_205
L_206 ,
! ! V_6 -> V_8 . V_29 , V_108 ) ;
F_41 ( V_74 && ! V_6 -> V_8 . V_29 ,
L_207 ) ;
F_41 ( V_6 -> V_524 != V_74 ,
L_208
L_206 , V_74 , V_6 -> V_524 ) ;
V_74 = V_6 -> V_122 ( V_6 , & V_4 ) ;
F_41 ( V_74 != V_6 -> V_524 ,
L_209
L_206 ,
V_6 -> V_524 , V_74 ) ;
if ( ! V_6 -> V_8 . V_29 )
continue;
V_1020 = F_35 ( V_6 -> V_8 . V_29 ) -> V_4 ;
F_41 ( V_74 && V_4 != V_1020 ,
L_210
L_206 ,
V_1020 , V_4 ) ;
}
}
static void
F_669 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_29 ;
struct V_1 * V_6 ;
struct V_450 V_451 ;
F_244 (dev, crtc) {
bool V_108 = false ;
bool V_74 = false ;
memset ( & V_451 , 0 , sizeof( V_451 ) ) ;
F_46 ( L_211 ,
V_29 -> V_8 . V_8 . V_225 ) ;
F_41 ( V_29 -> V_74 && ! V_29 -> V_8 . V_108 ,
L_212 ) ;
F_378 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
V_108 = true ;
if ( V_6 -> V_524 )
V_74 = true ;
}
F_41 ( V_74 != V_29 -> V_74 ,
L_213
L_206 , V_74 , V_29 -> V_74 ) ;
F_41 ( V_108 != V_29 -> V_8 . V_108 ,
L_214
L_206 , V_108 , V_29 -> V_8 . V_108 ) ;
V_74 = V_12 -> V_315 . V_1023 ( V_29 ,
& V_451 ) ;
if ( V_29 -> V_4 == V_132 && V_12 -> V_145 & V_146 )
V_74 = V_29 -> V_74 ;
F_378 (encoder, &dev->mode_config.encoder_list,
base.head) {
enum V_4 V_4 ;
if ( V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
if ( V_6 -> V_122 ( V_6 , & V_4 ) )
V_6 -> V_1024 ( V_6 , & V_451 ) ;
}
F_41 ( V_29 -> V_74 != V_74 ,
L_215
L_206 , V_29 -> V_74 , V_74 ) ;
if ( V_74 &&
! F_661 ( V_10 , & V_29 -> V_77 , & V_451 ) ) {
F_41 ( 1 , L_216 ) ;
F_647 ( V_29 , & V_451 ,
L_217 ) ;
F_647 ( V_29 , & V_29 -> V_77 ,
L_218 ) ;
}
}
}
static void
F_670 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_29 ;
struct V_120 V_200 ;
int V_150 ;
for ( V_150 = 0 ; V_150 < V_12 -> V_418 ; V_150 ++ ) {
struct V_116 * V_119 = & V_12 -> V_118 [ V_150 ] ;
int V_1025 = 0 , V_1026 = 0 ;
bool V_74 ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
F_46 ( L_219 , V_119 -> V_123 ) ;
V_74 = V_119 -> V_122 ( V_12 , V_119 , & V_200 ) ;
F_41 ( V_119 -> V_74 > V_119 -> V_222 ,
L_220 ,
V_119 -> V_74 , V_119 -> V_222 ) ;
F_41 ( V_119 -> V_74 && ! V_119 -> V_223 ,
L_221 ) ;
F_41 ( V_119 -> V_223 && ! V_119 -> V_74 ,
L_222 ) ;
F_41 ( V_119 -> V_223 != V_74 ,
L_223 ,
V_119 -> V_223 , V_74 ) ;
F_244 (dev, crtc) {
if ( V_29 -> V_8 . V_108 && F_61 ( V_29 ) == V_119 )
V_1025 ++ ;
if ( V_29 -> V_74 && F_61 ( V_29 ) == V_119 )
V_1026 ++ ;
}
F_41 ( V_119 -> V_74 != V_1026 ,
L_224 ,
V_119 -> V_74 , V_1026 ) ;
F_41 ( V_119 -> V_222 != V_1025 ,
L_225 ,
V_119 -> V_222 , V_1025 ) ;
F_41 ( V_119 -> V_223 && memcmp ( & V_119 -> V_121 , & V_200 ,
sizeof( V_200 ) ) ,
L_226 ) ;
}
}
void
F_385 ( struct V_9 * V_10 )
{
F_667 ( V_10 ) ;
F_668 ( V_10 ) ;
F_669 ( V_10 ) ;
F_670 ( V_10 ) ;
}
void F_671 ( const struct V_450 * V_451 ,
int V_1027 )
{
F_41 ( ! F_660 ( V_451 -> V_78 . V_79 , V_1027 ) ,
L_227 ,
V_451 -> V_78 . V_79 , V_1027 ) ;
}
static void F_672 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
if ( F_20 ( V_10 ) ) {
const struct V_332 * V_411 = & V_29 -> V_77 . V_78 ;
int V_667 ;
V_667 = V_411 -> V_651 ;
if ( V_411 -> V_321 & V_654 )
V_667 /= 2 ;
V_29 -> V_1028 = V_667 - 1 ;
} else if ( F_64 ( V_10 ) &&
F_10 ( & V_29 -> V_8 , V_39 ) ) {
V_29 -> V_1028 = 2 ;
} else
V_29 -> V_1028 = 1 ;
}
static int F_673 ( struct V_28 * V_29 ,
struct V_332 * V_411 ,
int V_267 , int V_268 , struct V_301 * V_76 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_332 * V_1029 ;
struct V_450 * V_451 = NULL ;
struct V_73 * V_73 ;
unsigned V_1008 , V_503 , V_1007 ;
int V_256 = 0 ;
V_1029 = F_674 ( sizeof( * V_1029 ) , V_698 ) ;
if ( ! V_1029 )
return - V_871 ;
F_656 ( V_29 , & V_1007 ,
& V_503 , & V_1008 ) ;
* V_1029 = V_29 -> V_411 ;
if ( V_1007 ) {
V_451 = F_653 ( V_29 , V_76 , V_411 ) ;
if ( F_562 ( V_451 ) ) {
V_256 = F_675 ( V_451 ) ;
V_451 = NULL ;
goto V_929;
}
F_647 ( F_35 ( V_29 ) , V_451 ,
L_228 ) ;
F_35 ( V_29 ) -> V_502 = V_451 ;
}
if ( F_19 ( V_10 ) ) {
F_358 ( V_10 , & V_503 ) ;
V_503 &= ~ V_1008 ;
}
F_676 (dev, disable_pipes, intel_crtc)
F_377 ( & V_73 -> V_8 ) ;
F_676 (dev, prepare_pipes, intel_crtc) {
if ( V_73 -> V_8 . V_108 )
V_12 -> V_315 . V_523 ( & V_73 -> V_8 ) ;
}
if ( V_1007 ) {
V_29 -> V_411 = * V_411 ;
F_35 ( V_29 ) -> V_77 = * V_451 ;
F_35 ( V_29 ) -> V_502 = & F_35 ( V_29 ) -> V_77 ;
F_677 ( V_29 ,
& V_451 -> V_78 ) ;
}
F_658 ( V_10 , V_503 ) ;
if ( V_12 -> V_315 . V_1030 )
V_12 -> V_315 . V_1030 ( V_10 ) ;
F_676 (dev, modeset_pipes, intel_crtc) {
struct V_301 * V_319 = V_29 -> V_75 -> V_76 ;
struct V_251 * V_327 = F_194 ( V_319 ) ;
struct V_251 * V_252 = F_194 ( V_76 ) ;
F_58 ( & V_10 -> V_257 ) ;
V_256 = F_171 ( V_10 ,
V_252 ,
NULL ) ;
if ( V_256 != 0 ) {
F_114 ( L_57 ) ;
F_60 ( & V_10 -> V_257 ) ;
goto V_1031;
}
if ( V_319 )
F_181 ( V_327 ) ;
F_219 ( V_327 , V_252 ,
F_189 ( V_73 -> V_4 ) ) ;
F_60 ( & V_10 -> V_257 ) ;
V_29 -> V_75 -> V_76 = V_76 ;
V_29 -> V_267 = V_267 ;
V_29 -> V_268 = V_268 ;
V_256 = V_12 -> V_315 . V_1032 ( & V_73 -> V_8 ,
V_267 , V_268 , V_76 ) ;
if ( V_256 )
goto V_1031;
}
F_676 (dev, prepare_pipes, intel_crtc) {
F_672 ( V_73 ) ;
V_12 -> V_315 . V_522 ( & V_73 -> V_8 ) ;
}
V_1031:
if ( V_256 && V_29 -> V_108 )
V_29 -> V_411 = * V_1029 ;
V_929:
F_192 ( V_451 ) ;
F_192 ( V_1029 ) ;
return V_256 ;
}
static int F_563 ( struct V_28 * V_29 ,
struct V_332 * V_411 ,
int V_267 , int V_268 , struct V_301 * V_76 )
{
int V_256 ;
V_256 = F_673 ( V_29 , V_411 , V_267 , V_268 , V_76 ) ;
if ( V_256 == 0 )
F_385 ( V_29 -> V_10 ) ;
return V_256 ;
}
void F_678 ( struct V_28 * V_29 )
{
F_563 ( V_29 , & V_29 -> V_411 , V_29 -> V_267 , V_29 -> V_268 , V_29 -> V_75 -> V_76 ) ;
}
static void F_679 ( struct V_1033 * V_77 )
{
if ( ! V_77 )
return;
F_192 ( V_77 -> V_1034 ) ;
F_192 ( V_77 -> V_1035 ) ;
F_192 ( V_77 -> V_1036 ) ;
F_192 ( V_77 ) ;
}
static int F_680 ( struct V_9 * V_10 ,
struct V_1033 * V_77 )
{
struct V_28 * V_29 ;
struct V_529 * V_6 ;
struct V_525 * V_3 ;
int V_1037 ;
V_77 -> V_1036 =
F_681 ( V_10 -> V_706 . V_1038 ,
sizeof( bool ) , V_698 ) ;
if ( ! V_77 -> V_1036 )
return - V_871 ;
V_77 -> V_1035 =
F_681 ( V_10 -> V_706 . V_1039 ,
sizeof( struct V_28 * ) , V_698 ) ;
if ( ! V_77 -> V_1035 )
return - V_871 ;
V_77 -> V_1034 =
F_681 ( V_10 -> V_706 . V_1040 ,
sizeof( struct V_529 * ) , V_698 ) ;
if ( ! V_77 -> V_1034 )
return - V_871 ;
V_1037 = 0 ;
F_193 (dev, crtc) {
V_77 -> V_1036 [ V_1037 ++ ] = V_29 -> V_108 ;
}
V_1037 = 0 ;
F_378 (encoder, &dev->mode_config.encoder_list, head) {
V_77 -> V_1035 [ V_1037 ++ ] = V_6 -> V_29 ;
}
V_1037 = 0 ;
F_378 (connector, &dev->mode_config.connector_list, head) {
V_77 -> V_1034 [ V_1037 ++ ] = V_3 -> V_6 ;
}
return 0 ;
}
static void F_682 ( struct V_9 * V_10 ,
struct V_1033 * V_77 )
{
struct V_73 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
int V_1037 ;
V_1037 = 0 ;
F_244 (dev, crtc) {
V_29 -> V_501 = V_77 -> V_1036 [ V_1037 ++ ] ;
if ( V_29 -> V_501 )
V_29 -> V_502 = & V_29 -> V_77 ;
else
V_29 -> V_502 = NULL ;
}
V_1037 = 0 ;
F_378 (encoder, &dev->mode_config.encoder_list, base.head) {
V_6 -> V_899 =
F_35 ( V_77 -> V_1035 [ V_1037 ++ ] ) ;
}
V_1037 = 0 ;
F_378 (connector, &dev->mode_config.connector_list, base.head) {
V_3 -> V_900 =
F_379 ( V_77 -> V_1034 [ V_1037 ++ ] ) ;
}
}
static bool
F_683 ( struct V_1041 * V_1042 )
{
int V_150 ;
if ( V_1042 -> V_582 == 0 )
return false ;
if ( F_3 ( V_1042 -> V_1043 == NULL ) )
return false ;
for ( V_150 = 0 ; V_150 < V_1042 -> V_582 ; V_150 ++ )
if ( V_1042 -> V_1043 [ V_150 ] -> V_6 &&
V_1042 -> V_1043 [ V_150 ] -> V_6 -> V_29 == V_1042 -> V_29 &&
V_1042 -> V_1043 [ V_150 ] -> V_527 != V_530 )
return true ;
return false ;
}
static void
F_684 ( struct V_1041 * V_1042 ,
struct V_1033 * V_77 )
{
if ( F_683 ( V_1042 ) ) {
V_77 -> V_1044 = true ;
} else if ( V_1042 -> V_29 -> V_75 -> V_76 != V_1042 -> V_76 ) {
if ( V_1042 -> V_29 -> V_75 -> V_76 == NULL ) {
struct V_73 * V_73 =
F_35 ( V_1042 -> V_29 ) ;
if ( V_73 -> V_74 ) {
F_46 ( L_229 ) ;
V_77 -> V_1045 = true ;
} else {
F_46 ( L_230 ) ;
V_77 -> V_1044 = true ;
}
} else if ( V_1042 -> V_76 == NULL ) {
V_77 -> V_1044 = true ;
} else if ( V_1042 -> V_76 -> V_296 !=
V_1042 -> V_29 -> V_75 -> V_76 -> V_296 ) {
V_77 -> V_1044 = true ;
} else {
V_77 -> V_1045 = true ;
}
}
if ( V_1042 -> V_76 && ( V_1042 -> V_267 != V_1042 -> V_29 -> V_267 || V_1042 -> V_268 != V_1042 -> V_29 -> V_268 ) )
V_77 -> V_1045 = true ;
if ( V_1042 -> V_411 && ! F_685 ( V_1042 -> V_411 , & V_1042 -> V_29 -> V_411 ) ) {
F_46 ( L_231 ) ;
F_649 ( & V_1042 -> V_29 -> V_411 ) ;
F_649 ( V_1042 -> V_411 ) ;
V_77 -> V_1044 = true ;
}
F_46 ( L_232 ,
V_1042 -> V_29 -> V_8 . V_225 , V_77 -> V_1044 , V_77 -> V_1045 ) ;
}
static int
F_686 ( struct V_9 * V_10 ,
struct V_1041 * V_1042 ,
struct V_1033 * V_77 )
{
struct V_2 * V_3 ;
struct V_1 * V_6 ;
struct V_73 * V_29 ;
int V_1046 ;
F_3 ( ! V_1042 -> V_76 && ( V_1042 -> V_582 != 0 ) ) ;
F_3 ( V_1042 -> V_76 && ( V_1042 -> V_582 == 0 ) ) ;
F_378 (connector, &dev->mode_config.connector_list,
base.head) {
for ( V_1046 = 0 ; V_1046 < V_1042 -> V_582 ; V_1046 ++ ) {
if ( V_1042 -> V_1043 [ V_1046 ] == & V_3 -> V_8 ) {
V_3 -> V_900 = F_1 ( V_3 , F_35 ( V_1042 -> V_29 ) -> V_4 ) ;
break;
}
}
if ( ( ! V_1042 -> V_76 || V_1046 == V_1042 -> V_582 ) &&
V_3 -> V_8 . V_6 &&
V_3 -> V_8 . V_6 -> V_29 == V_1042 -> V_29 ) {
V_3 -> V_900 = NULL ;
F_46 ( L_233 ,
V_3 -> V_8 . V_8 . V_225 ,
V_3 -> V_8 . V_123 ) ;
}
if ( & V_3 -> V_900 -> V_8 != V_3 -> V_8 . V_6 ) {
F_46 ( L_234 ) ;
V_77 -> V_1044 = true ;
}
}
F_378 (connector, &dev->mode_config.connector_list,
base.head) {
struct V_28 * V_899 ;
if ( ! V_3 -> V_900 )
continue;
V_899 = V_3 -> V_900 -> V_8 . V_29 ;
for ( V_1046 = 0 ; V_1046 < V_1042 -> V_582 ; V_1046 ++ ) {
if ( V_1042 -> V_1043 [ V_1046 ] == & V_3 -> V_8 )
V_899 = V_1042 -> V_29 ;
}
if ( ! F_687 ( & V_3 -> V_900 -> V_8 ,
V_899 ) ) {
return - V_262 ;
}
V_3 -> V_900 -> V_899 = F_35 ( V_899 ) ;
F_46 ( L_235 ,
V_3 -> V_8 . V_8 . V_225 ,
V_3 -> V_8 . V_123 ,
V_899 -> V_8 . V_225 ) ;
}
F_378 (encoder, &dev->mode_config.encoder_list,
base.head) {
int V_582 = 0 ;
F_378 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_900 == V_6 ) {
F_3 ( ! V_3 -> V_900 -> V_899 ) ;
V_582 ++ ;
}
}
if ( V_582 == 0 )
V_6 -> V_899 = NULL ;
else if ( V_582 > 1 )
return - V_262 ;
if ( & V_6 -> V_899 -> V_8 != V_6 -> V_8 . V_29 ) {
F_46 ( L_236 ) ;
V_77 -> V_1044 = true ;
}
}
F_378 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_900 )
if ( V_3 -> V_900 != V_3 -> V_6 )
V_3 -> V_6 = V_3 -> V_900 ;
}
F_244 (dev, crtc) {
V_29 -> V_501 = false ;
F_378 (encoder,
&dev->mode_config.encoder_list,
base.head) {
if ( V_6 -> V_899 == V_29 ) {
V_29 -> V_501 = true ;
break;
}
}
if ( V_29 -> V_501 != V_29 -> V_8 . V_108 ) {
F_46 ( L_237 ,
V_29 -> V_501 ? L_238 : L_239 ) ;
V_77 -> V_1044 = true ;
}
if ( V_29 -> V_501 )
V_29 -> V_502 = & V_29 -> V_77 ;
else
V_29 -> V_502 = NULL ;
}
return 0 ;
}
static void F_688 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_46 ( L_240 ,
F_72 ( V_29 -> V_4 ) ) ;
F_378 (connector, &dev->mode_config.connector_list, base.head) {
if ( V_3 -> V_900 &&
V_3 -> V_900 -> V_899 == V_29 )
V_3 -> V_900 = NULL ;
}
F_378 (encoder, &dev->mode_config.encoder_list, base.head) {
if ( V_6 -> V_899 == V_29 )
V_6 -> V_899 = NULL ;
}
V_29 -> V_501 = false ;
V_29 -> V_502 = NULL ;
}
static int F_689 ( struct V_1041 * V_1042 )
{
struct V_9 * V_10 ;
struct V_1041 V_1047 ;
struct V_1033 * V_77 ;
int V_256 ;
F_118 ( ! V_1042 ) ;
F_118 ( ! V_1042 -> V_29 ) ;
F_118 ( ! V_1042 -> V_29 -> V_1048 ) ;
F_118 ( ! V_1042 -> V_411 && V_1042 -> V_76 ) ;
F_118 ( V_1042 -> V_76 && V_1042 -> V_582 == 0 ) ;
if ( V_1042 -> V_76 ) {
F_46 ( L_241 ,
V_1042 -> V_29 -> V_8 . V_225 , V_1042 -> V_76 -> V_8 . V_225 ,
( int ) V_1042 -> V_582 , V_1042 -> V_267 , V_1042 -> V_268 ) ;
} else {
F_46 ( L_242 , V_1042 -> V_29 -> V_8 . V_225 ) ;
}
V_10 = V_1042 -> V_29 -> V_10 ;
V_256 = - V_871 ;
V_77 = F_455 ( sizeof( * V_77 ) , V_698 ) ;
if ( ! V_77 )
goto V_1049;
V_256 = F_680 ( V_10 , V_77 ) ;
if ( V_256 )
goto V_1049;
V_1047 . V_29 = V_1042 -> V_29 ;
V_1047 . V_411 = & V_1042 -> V_29 -> V_411 ;
V_1047 . V_267 = V_1042 -> V_29 -> V_267 ;
V_1047 . V_268 = V_1042 -> V_29 -> V_268 ;
V_1047 . V_76 = V_1042 -> V_29 -> V_75 -> V_76 ;
F_684 ( V_1042 , V_77 ) ;
V_256 = F_686 ( V_10 , V_1042 , V_77 ) ;
if ( V_256 )
goto V_872;
if ( V_77 -> V_1044 ) {
V_256 = F_563 ( V_1042 -> V_29 , V_1042 -> V_411 ,
V_1042 -> V_267 , V_1042 -> V_268 , V_1042 -> V_76 ) ;
} else if ( V_77 -> V_1045 ) {
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_1042 -> V_29 ) ;
F_245 ( V_1042 -> V_29 ) ;
V_256 = F_218 ( V_1042 -> V_29 ,
V_1042 -> V_267 , V_1042 -> V_268 , V_1042 -> V_76 ) ;
if ( ! V_73 -> V_246 && V_256 == 0 ) {
F_3 ( ! V_73 -> V_74 ) ;
F_163 ( V_12 , V_73 -> V_148 ,
V_73 -> V_4 ) ;
}
if ( V_330 . V_331 && V_256 == 0 )
F_385 ( V_1042 -> V_29 -> V_10 ) ;
}
if ( V_256 ) {
F_46 ( L_243 ,
V_1042 -> V_29 -> V_8 . V_225 , V_256 ) ;
V_872:
F_682 ( V_10 , V_77 ) ;
if ( F_35 ( V_1047 . V_29 ) -> V_501 && ! V_1047 . V_76 )
F_688 ( F_35 ( V_1047 . V_29 ) ) ;
if ( V_77 -> V_1044 &&
F_563 ( V_1047 . V_29 , V_1047 . V_411 ,
V_1047 . V_267 , V_1047 . V_268 , V_1047 . V_76 ) )
F_114 ( L_244 ) ;
}
V_1049:
F_679 ( V_77 ) ;
return V_256 ;
}
static bool F_690 ( struct V_11 * V_12 ,
struct V_116 * V_119 ,
struct V_120 * V_121 )
{
T_4 V_110 ;
if ( ! F_78 ( V_12 , V_226 ) )
return false ;
V_110 = F_5 ( F_691 ( V_119 -> V_225 ) ) ;
V_121 -> V_54 = V_110 ;
V_121 -> V_507 = F_5 ( F_692 ( V_119 -> V_225 ) ) ;
V_121 -> V_508 = F_5 ( F_693 ( V_119 -> V_225 ) ) ;
return V_110 & V_112 ;
}
static void F_694 ( struct V_11 * V_12 ,
struct V_116 * V_119 )
{
F_45 ( F_692 ( V_119 -> V_225 ) , V_119 -> V_121 . V_507 ) ;
F_45 ( F_693 ( V_119 -> V_225 ) , V_119 -> V_121 . V_508 ) ;
}
static void F_695 ( struct V_11 * V_12 ,
struct V_116 * V_119 )
{
F_91 ( V_12 ) ;
F_45 ( F_691 ( V_119 -> V_225 ) , V_119 -> V_121 . V_54 ) ;
F_121 ( F_691 ( V_119 -> V_225 ) ) ;
F_122 ( 150 ) ;
F_45 ( F_691 ( V_119 -> V_225 ) , V_119 -> V_121 . V_54 ) ;
F_121 ( F_691 ( V_119 -> V_225 ) ) ;
F_122 ( 200 ) ;
}
static void F_696 ( struct V_11 * V_12 ,
struct V_116 * V_119 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_73 * V_29 ;
F_244 (dev, crtc) {
if ( F_61 ( V_29 ) == V_119 )
F_93 ( V_12 , V_29 -> V_4 ) ;
}
F_45 ( F_691 ( V_119 -> V_225 ) , 0 ) ;
F_121 ( F_691 ( V_119 -> V_225 ) ) ;
F_122 ( 200 ) ;
}
static void F_697 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_150 ;
V_12 -> V_418 = 2 ;
for ( V_150 = 0 ; V_150 < V_12 -> V_418 ; V_150 ++ ) {
V_12 -> V_118 [ V_150 ] . V_225 = V_150 ;
V_12 -> V_118 [ V_150 ] . V_123 = V_1050 [ V_150 ] ;
V_12 -> V_118 [ V_150 ] . V_224 = F_694 ;
V_12 -> V_118 [ V_150 ] . V_227 = F_695 ;
V_12 -> V_118 [ V_150 ] . V_228 = F_696 ;
V_12 -> V_118 [ V_150 ] . V_122 =
F_690 ;
}
}
static void F_698 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_64 ( V_10 ) )
F_699 ( V_10 ) ;
else if ( F_53 ( V_10 ) || F_92 ( V_10 ) )
F_697 ( V_10 ) ;
else
V_12 -> V_418 = 0 ;
F_118 ( V_12 -> V_418 > V_1051 ) ;
}
static int
F_700 ( struct V_423 * V_148 )
{
struct V_9 * V_10 = V_148 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_424 * V_424 = F_286 ( V_148 ) ;
struct V_73 * V_73 ;
if ( ! V_148 -> V_76 )
return 0 ;
F_118 ( ! V_148 -> V_29 ) ;
V_73 = F_35 ( V_148 -> V_29 ) ;
if ( ! V_73 -> V_246 )
goto V_1052;
F_245 ( V_148 -> V_29 ) ;
F_166 ( V_12 , V_424 -> V_148 ,
V_424 -> V_4 ) ;
V_1052:
F_58 ( & V_10 -> V_257 ) ;
F_219 ( F_194 ( V_148 -> V_76 ) , NULL ,
F_189 ( V_73 -> V_4 ) ) ;
F_181 ( F_194 ( V_148 -> V_76 ) ) ;
F_60 ( & V_10 -> V_257 ) ;
V_148 -> V_76 = NULL ;
return 0 ;
}
static int
F_701 ( struct V_423 * V_148 , struct V_28 * V_29 ,
struct V_301 * V_76 , int V_1053 , int V_1054 ,
unsigned int V_1055 , unsigned int V_1056 ,
T_4 V_1057 , T_4 V_1058 ,
T_4 V_1059 , T_4 V_1060 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_424 * V_424 = F_286 ( V_148 ) ;
struct V_251 * V_252 = F_194 ( V_76 ) ;
struct V_251 * V_327 = F_194 ( V_148 -> V_76 ) ;
struct V_1061 V_1062 = {
. V_1063 = V_1053 ,
. y1 = V_1054 ,
. V_1064 = V_1053 + V_1055 ,
. V_1065 = V_1054 + V_1056 ,
} ;
struct V_1061 V_1066 = {
. V_1063 = V_1057 ,
. y1 = V_1058 ,
. V_1064 = V_1057 + V_1059 ,
. V_1065 = V_1058 + V_1060 ,
} ;
const struct V_1061 V_1067 = {
. V_1064 = V_73 -> V_74 ? V_73 -> V_77 . V_337 : 0 ,
. V_1065 = V_73 -> V_74 ? V_73 -> V_77 . V_338 : 0 ,
} ;
bool V_1068 ;
int V_256 ;
V_256 = F_702 ( V_148 , V_29 , V_76 ,
& V_1066 , & V_1062 , & V_1067 ,
V_1069 ,
V_1069 ,
false , true , & V_1068 ) ;
if ( V_256 )
return V_256 ;
if ( ! V_29 -> V_108 ) {
F_58 ( & V_10 -> V_257 ) ;
if ( V_148 -> V_76 )
F_181 ( V_327 ) ;
F_219 ( V_327 , V_252 ,
F_189 ( V_73 -> V_4 ) ) ;
V_256 = F_171 ( V_10 , V_252 , NULL ) ;
F_60 ( & V_10 -> V_257 ) ;
return V_256 ;
}
F_245 ( V_29 ) ;
if ( ! V_1068 ) {
F_58 ( & V_10 -> V_257 ) ;
if ( V_148 -> V_76 != V_76 ) {
V_256 = F_171 ( V_10 , V_252 , NULL ) ;
if ( V_256 ) {
F_60 ( & V_10 -> V_257 ) ;
return V_256 ;
}
}
F_219 ( V_327 , V_252 ,
F_189 ( V_73 -> V_4 ) ) ;
if ( V_73 -> V_246 )
F_166 ( V_12 ,
V_424 -> V_148 ,
V_424 -> V_4 ) ;
if ( V_148 -> V_76 != V_76 )
if ( V_148 -> V_76 )
F_181 ( V_327 ) ;
F_60 ( & V_10 -> V_257 ) ;
return 0 ;
}
V_256 = F_218 ( V_29 , V_1066 . V_1063 , V_1066 . y1 , V_76 ) ;
if ( V_256 )
return V_256 ;
if ( ! V_73 -> V_246 )
F_163 ( V_12 , V_73 -> V_148 ,
V_73 -> V_4 ) ;
return 0 ;
}
static void F_703 ( struct V_423 * V_148 )
{
struct V_424 * V_424 = F_286 ( V_148 ) ;
F_704 ( V_148 ) ;
F_192 ( V_424 ) ;
}
static struct V_423 * F_705 ( struct V_9 * V_10 ,
int V_4 )
{
struct V_424 * V_75 ;
const T_4 * V_1070 ;
int V_1071 ;
V_75 = F_455 ( sizeof( * V_75 ) , V_698 ) ;
if ( V_75 == NULL )
return NULL ;
V_75 -> V_1072 = false ;
V_75 -> V_1073 = 1 ;
V_75 -> V_4 = V_4 ;
V_75 -> V_148 = V_4 ;
if ( F_706 ( V_10 ) && F_44 ( V_10 ) -> V_86 < 4 )
V_75 -> V_148 = ! V_4 ;
if ( F_44 ( V_10 ) -> V_86 <= 3 ) {
V_1070 = V_1074 ;
V_1071 = F_239 ( V_1074 ) ;
} else {
V_1070 = V_1075 ;
V_1071 = F_239 ( V_1075 ) ;
}
F_707 ( V_10 , & V_75 -> V_8 , 0 ,
& V_1076 ,
V_1070 , V_1071 ,
V_1077 ) ;
return & V_75 -> V_8 ;
}
static int
F_708 ( struct V_423 * V_148 )
{
if ( ! V_148 -> V_76 )
return 0 ;
F_118 ( ! V_148 -> V_29 ) ;
return F_542 ( V_148 -> V_29 , NULL , 0 , 0 ) ;
}
static int
F_709 ( struct V_423 * V_148 , struct V_28 * V_29 ,
struct V_301 * V_76 , int V_1053 , int V_1054 ,
unsigned int V_1055 , unsigned int V_1056 ,
T_4 V_1057 , T_4 V_1058 ,
T_4 V_1059 , T_4 V_1060 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_697 * V_886 = F_188 ( V_76 ) ;
struct V_251 * V_252 = V_886 -> V_252 ;
struct V_1061 V_1062 = {
. V_1063 = V_1053 ,
. y1 = V_1054 ,
. V_1064 = V_1053 + V_1055 ,
. V_1065 = V_1054 + V_1056 ,
} ;
struct V_1061 V_1066 = {
. V_1063 = V_1057 ,
. y1 = V_1058 ,
. V_1064 = V_1057 + V_1059 ,
. V_1065 = V_1058 + V_1060 ,
} ;
const struct V_1061 V_1067 = {
. V_1064 = V_73 -> V_74 ? V_73 -> V_77 . V_337 : 0 ,
. V_1065 = V_73 -> V_74 ? V_73 -> V_77 . V_338 : 0 ,
} ;
bool V_1068 ;
int V_256 ;
V_256 = F_702 ( V_148 , V_29 , V_76 ,
& V_1066 , & V_1062 , & V_1067 ,
V_1069 ,
V_1069 ,
true , true , & V_1068 ) ;
if ( V_256 )
return V_256 ;
V_29 -> V_861 = V_1053 ;
V_29 -> V_862 = V_1054 ;
if ( V_76 != V_29 -> V_1078 -> V_76 ) {
return F_542 ( V_29 , V_252 , V_1055 , V_1056 ) ;
} else {
F_303 ( V_29 , V_1068 ) ;
return 0 ;
}
}
static struct V_423 * F_710 ( struct V_9 * V_10 ,
int V_4 )
{
struct V_424 * V_1078 ;
V_1078 = F_455 ( sizeof( * V_1078 ) , V_698 ) ;
if ( V_1078 == NULL )
return NULL ;
V_1078 -> V_1072 = false ;
V_1078 -> V_1073 = 1 ;
V_1078 -> V_4 = V_4 ;
V_1078 -> V_148 = V_4 ;
F_707 ( V_10 , & V_1078 -> V_8 , 0 ,
& V_1079 ,
V_1080 ,
F_239 ( V_1080 ) ,
V_1081 ) ;
return & V_1078 -> V_8 ;
}
static void F_711 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 ;
struct V_423 * V_75 = NULL ;
struct V_423 * V_1078 = NULL ;
int V_150 , V_256 ;
V_73 = F_455 ( sizeof( * V_73 ) , V_698 ) ;
if ( V_73 == NULL )
return;
V_75 = F_705 ( V_10 , V_4 ) ;
if ( ! V_75 )
goto V_872;
V_1078 = F_710 ( V_10 , V_4 ) ;
if ( ! V_1078 )
goto V_872;
V_256 = F_712 ( V_10 , & V_73 -> V_8 , V_75 ,
V_1078 , & V_1082 ) ;
if ( V_256 )
goto V_872;
F_713 ( & V_73 -> V_8 , 256 ) ;
for ( V_150 = 0 ; V_150 < 256 ; V_150 ++ ) {
V_73 -> V_435 [ V_150 ] = V_150 ;
V_73 -> V_436 [ V_150 ] = V_150 ;
V_73 -> V_437 [ V_150 ] = V_150 ;
}
V_73 -> V_4 = V_4 ;
V_73 -> V_148 = V_4 ;
if ( F_706 ( V_10 ) && F_44 ( V_10 ) -> V_86 < 4 ) {
F_46 ( L_245 ) ;
V_73 -> V_148 = ! V_4 ;
}
V_73 -> V_850 = ~ 0 ;
V_73 -> V_851 = ~ 0 ;
F_714 ( & V_73 -> V_1083 ) ;
F_118 ( V_4 >= F_239 ( V_12 -> V_945 ) ||
V_12 -> V_945 [ V_73 -> V_148 ] != NULL ) ;
V_12 -> V_945 [ V_73 -> V_148 ] = & V_73 -> V_8 ;
V_12 -> V_81 [ V_73 -> V_4 ] = & V_73 -> V_8 ;
F_715 ( & V_73 -> V_8 , & V_1084 ) ;
F_3 ( F_716 ( & V_73 -> V_8 ) != V_73 -> V_4 ) ;
return;
V_872:
if ( V_75 )
F_704 ( V_75 ) ;
if ( V_1078 )
F_704 ( V_1078 ) ;
F_192 ( V_73 ) ;
}
enum V_4 F_717 ( struct V_2 * V_3 )
{
struct V_529 * V_6 = V_3 -> V_8 . V_6 ;
struct V_9 * V_10 = V_3 -> V_8 . V_10 ;
F_3 ( ! F_718 ( & V_10 -> V_706 . V_894 ) ) ;
if ( ! V_6 )
return V_1085 ;
return F_35 ( V_6 -> V_29 ) -> V_4 ;
}
int F_719 ( struct V_9 * V_10 , void * V_1086 ,
struct V_1087 * V_1088 )
{
struct V_1089 * V_1090 = V_1086 ;
struct V_28 * V_1091 ;
struct V_73 * V_29 ;
if ( ! F_720 ( V_10 , V_1092 ) )
return - V_967 ;
V_1091 = F_721 ( V_10 , V_1090 -> V_1093 ) ;
if ( ! V_1091 ) {
F_114 ( L_246 ) ;
return - V_1094 ;
}
V_29 = F_35 ( V_1091 ) ;
V_1090 -> V_4 = V_29 -> V_4 ;
return 0 ;
}
static int F_722 ( struct V_1 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_8 . V_10 ;
struct V_1 * V_1000 ;
int V_1095 = 0 ;
int V_1096 = 0 ;
F_378 (source_encoder,
&dev->mode_config.encoder_list, base.head) {
if ( F_650 ( V_6 , V_1000 ) )
V_1095 |= ( 1 << V_1096 ) ;
V_1096 ++ ;
}
return V_1095 ;
}
static bool F_723 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_119 ( V_10 ) )
return false ;
if ( ( F_5 ( V_1097 ) & V_1098 ) == 0 )
return false ;
if ( F_7 ( V_10 ) && ( F_5 ( V_1099 ) & V_1100 ) )
return false ;
return true ;
}
const char * F_724 ( int V_1101 )
{
static const char * V_1102 [] = {
[ V_1103 ] = L_247 ,
[ V_40 ] = L_248 ,
[ V_51 ] = L_249 ,
[ V_42 ] = L_250 ,
[ V_31 ] = L_251 ,
[ V_1104 ] = L_252 ,
[ V_39 ] = L_253 ,
[ V_405 ] = L_254 ,
[ V_336 ] = L_255 ,
[ V_244 ] = L_256 ,
[ V_466 ] = L_257 ,
} ;
if ( V_1101 < 0 || V_1101 >= F_239 ( V_1102 ) || ! V_1102 [ V_1101 ] )
return L_258 ;
return V_1102 [ V_1101 ] ;
}
static bool F_725 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_726 ( V_10 ) )
return false ;
if ( F_18 ( V_10 ) )
return false ;
if ( F_19 ( V_10 ) && ! V_12 -> V_579 . V_1105 )
return false ;
return true ;
}
static void F_727 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
bool V_1106 = false ;
F_728 ( V_10 ) ;
if ( F_725 ( V_10 ) )
F_729 ( V_10 ) ;
if ( F_64 ( V_10 ) ) {
int V_67 ;
V_67 = F_5 ( V_1107 ) & V_1108 ;
if ( V_67 )
F_730 ( V_10 , V_459 ) ;
V_67 = F_5 ( V_1109 ) ;
if ( V_67 & V_1110 )
F_730 ( V_10 , V_98 ) ;
if ( V_67 & V_1111 )
F_730 ( V_10 , V_100 ) ;
if ( V_67 & V_1112 )
F_730 ( V_10 , V_102 ) ;
} else if ( F_4 ( V_10 ) ) {
int V_67 ;
V_1106 = F_731 ( V_10 , V_102 ) ;
if ( F_723 ( V_10 ) )
F_732 ( V_10 , V_1097 , V_459 ) ;
if ( F_5 ( V_188 ) & V_1113 ) {
V_67 = F_733 ( V_10 , V_1114 , true ) ;
if ( ! V_67 )
F_734 ( V_10 , V_188 , V_98 ) ;
if ( ! V_67 && ( F_5 ( V_181 ) & V_1098 ) )
F_732 ( V_10 , V_181 , V_98 ) ;
}
if ( F_5 ( V_189 ) & V_1113 )
F_734 ( V_10 , V_189 , V_100 ) ;
if ( ! V_1106 && F_5 ( V_190 ) & V_1113 )
F_734 ( V_10 , V_190 , V_102 ) ;
if ( F_5 ( V_183 ) & V_1098 )
F_732 ( V_10 , V_183 , V_100 ) ;
if ( F_5 ( V_185 ) & V_1098 )
F_732 ( V_10 , V_185 , V_102 ) ;
} else if ( F_19 ( V_10 ) ) {
if ( F_5 ( V_1115 + V_1116 ) & V_1113 ) {
F_734 ( V_10 , V_1115 + V_1116 ,
V_98 ) ;
if ( F_5 ( V_1115 + V_1117 ) & V_1098 )
F_732 ( V_10 , V_1115 + V_1117 , V_98 ) ;
}
if ( F_5 ( V_1115 + V_1118 ) & V_1113 ) {
F_734 ( V_10 , V_1115 + V_1118 ,
V_100 ) ;
if ( F_5 ( V_1115 + V_1119 ) & V_1098 )
F_732 ( V_10 , V_1115 + V_1119 , V_100 ) ;
}
if ( F_18 ( V_10 ) ) {
if ( F_5 ( V_1115 + V_1120 ) & V_1113 ) {
F_734 ( V_10 , V_1115 + V_1120 ,
V_102 ) ;
if ( F_5 ( V_1115 + V_1121 ) & V_1098 )
F_732 ( V_10 , V_1115 + V_1121 , V_102 ) ;
}
}
F_735 ( V_10 ) ;
} else if ( F_736 ( V_10 ) ) {
bool V_67 = false ;
if ( F_5 ( V_1122 ) & V_1113 ) {
F_46 ( L_259 ) ;
V_67 = F_733 ( V_10 , V_1122 , true ) ;
if ( ! V_67 && F_737 ( V_10 ) ) {
F_46 ( L_260 ) ;
F_734 ( V_10 , V_1116 , V_98 ) ;
}
if ( ! V_67 && F_738 ( V_10 ) )
F_732 ( V_10 , V_1117 , V_98 ) ;
}
if ( F_5 ( V_1122 ) & V_1113 ) {
F_46 ( L_261 ) ;
V_67 = F_733 ( V_10 , V_1123 , false ) ;
}
if ( ! V_67 && ( F_5 ( V_1123 ) & V_1113 ) ) {
if ( F_737 ( V_10 ) ) {
F_46 ( L_262 ) ;
F_734 ( V_10 , V_1118 , V_100 ) ;
}
if ( F_738 ( V_10 ) )
F_732 ( V_10 , V_1119 , V_100 ) ;
}
if ( F_738 ( V_10 ) &&
( F_5 ( V_1121 ) & V_1098 ) )
F_732 ( V_10 , V_1121 , V_102 ) ;
} else if ( F_20 ( V_10 ) )
F_739 ( V_10 ) ;
if ( F_740 ( V_10 ) )
F_741 ( V_10 ) ;
F_742 ( V_10 ) ;
F_378 (encoder, &dev->mode_config.encoder_list, base.head) {
V_6 -> V_8 . V_898 = V_6 -> V_1124 ;
V_6 -> V_8 . V_1125 =
F_722 ( V_6 ) ;
}
F_468 ( V_10 ) ;
F_743 ( V_10 ) ;
}
static void F_744 ( struct V_301 * V_76 )
{
struct V_9 * V_10 = V_76 -> V_10 ;
struct V_697 * V_886 = F_188 ( V_76 ) ;
F_745 ( V_76 ) ;
F_58 ( & V_10 -> V_257 ) ;
F_3 ( ! V_886 -> V_252 -> V_1126 -- ) ;
F_190 ( & V_886 -> V_252 -> V_8 ) ;
F_60 ( & V_10 -> V_257 ) ;
F_192 ( V_886 ) ;
}
static int F_746 ( struct V_301 * V_76 ,
struct V_1087 * V_1088 ,
unsigned int * V_1127 )
{
struct V_697 * V_886 = F_188 ( V_76 ) ;
struct V_251 * V_252 = V_886 -> V_252 ;
return F_747 ( V_1088 , & V_252 -> V_8 , V_1127 ) ;
}
static int F_187 ( struct V_9 * V_10 ,
struct V_697 * V_886 ,
struct V_291 * V_292 ,
struct V_251 * V_252 )
{
int V_696 ;
int V_1128 ;
int V_256 ;
F_3 ( ! F_172 ( & V_10 -> V_257 ) ) ;
if ( V_252 -> V_258 == V_261 ) {
F_543 ( L_263 ) ;
return - V_262 ;
}
if ( V_292 -> V_295 [ 0 ] & 63 ) {
F_543 ( L_264 ,
V_292 -> V_295 [ 0 ] ) ;
return - V_262 ;
}
if ( F_44 ( V_10 ) -> V_86 >= 5 && ! F_19 ( V_10 ) ) {
V_1128 = 32 * 1024 ;
} else if ( F_44 ( V_10 ) -> V_86 >= 4 ) {
if ( V_252 -> V_258 )
V_1128 = 16 * 1024 ;
else
V_1128 = 32 * 1024 ;
} else if ( F_44 ( V_10 ) -> V_86 >= 3 ) {
if ( V_252 -> V_258 )
V_1128 = 8 * 1024 ;
else
V_1128 = 16 * 1024 ;
} else
V_1128 = 8 * 1024 ;
if ( V_292 -> V_295 [ 0 ] > V_1128 ) {
F_543 ( L_265 ,
V_252 -> V_258 ? L_266 : L_267 ,
V_292 -> V_295 [ 0 ] , V_1128 ) ;
return - V_262 ;
}
if ( V_252 -> V_258 != V_259 &&
V_292 -> V_295 [ 0 ] != V_252 -> V_294 ) {
F_543 ( L_268 ,
V_292 -> V_295 [ 0 ] , V_252 -> V_294 ) ;
return - V_262 ;
}
switch ( V_292 -> V_296 ) {
case V_276 :
case V_280 :
case V_282 :
case V_306 :
break;
case V_278 :
case V_305 :
if ( F_44 ( V_10 ) -> V_86 > 3 ) {
F_543 ( L_269 ,
F_748 ( V_292 -> V_296 ) ) ;
return - V_262 ;
}
break;
case V_284 :
case V_307 :
case V_286 :
case V_308 :
case V_288 :
case V_309 :
if ( F_44 ( V_10 ) -> V_86 < 4 ) {
F_543 ( L_269 ,
F_748 ( V_292 -> V_296 ) ) ;
return - V_262 ;
}
break;
case V_1129 :
case V_1130 :
case V_1131 :
case V_1132 :
if ( F_44 ( V_10 ) -> V_86 < 5 ) {
F_543 ( L_269 ,
F_748 ( V_292 -> V_296 ) ) ;
return - V_262 ;
}
break;
default:
F_543 ( L_269 ,
F_748 ( V_292 -> V_296 ) ) ;
return - V_262 ;
}
if ( V_292 -> V_987 [ 0 ] != 0 )
return - V_262 ;
V_696 = F_169 ( V_10 , V_292 -> V_248 ,
V_252 -> V_258 ) ;
if ( V_252 -> V_8 . V_293 < V_696 * V_292 -> V_295 [ 0 ] )
return - V_262 ;
F_749 ( & V_886 -> V_8 , V_292 ) ;
V_886 -> V_252 = V_252 ;
V_886 -> V_252 -> V_1126 ++ ;
V_256 = F_750 ( V_10 , & V_886 -> V_8 , & V_1133 ) ;
if ( V_256 ) {
F_114 ( L_270 , V_256 ) ;
return V_256 ;
}
return 0 ;
}
static struct V_301 *
F_751 ( struct V_9 * V_10 ,
struct V_1087 * V_1134 ,
struct V_291 * V_292 )
{
struct V_251 * V_252 ;
V_252 = F_752 ( F_753 ( V_10 , V_1134 ,
V_292 -> V_1135 [ 0 ] ) ) ;
if ( & V_252 -> V_8 == NULL )
return F_550 ( - V_1094 ) ;
return F_551 ( V_10 , V_292 , V_252 ) ;
}
static inline void F_754 ( struct V_9 * V_10 )
{
}
static void F_755 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_4 ( V_10 ) || F_16 ( V_10 ) )
V_12 -> V_315 . V_688 = F_30 ;
else if ( F_18 ( V_10 ) )
V_12 -> V_315 . V_688 = F_33 ;
else if ( F_19 ( V_10 ) )
V_12 -> V_315 . V_688 = F_31 ;
else if ( F_17 ( V_10 ) )
V_12 -> V_315 . V_688 = F_29 ;
else
V_12 -> V_315 . V_688 = F_28 ;
if ( F_64 ( V_10 ) ) {
V_12 -> V_315 . V_1023 = F_515 ;
V_12 -> V_315 . V_1136 = F_496 ;
V_12 -> V_315 . V_1032 = F_511 ;
V_12 -> V_315 . V_522 = F_319 ;
V_12 -> V_315 . V_523 = F_329 ;
V_12 -> V_315 . V_526 = F_333 ;
V_12 -> V_315 . V_317 =
F_201 ;
} else if ( F_4 ( V_10 ) ) {
V_12 -> V_315 . V_1023 = F_497 ;
V_12 -> V_315 . V_1136 = F_496 ;
V_12 -> V_315 . V_1032 = F_488 ;
V_12 -> V_315 . V_522 = F_308 ;
V_12 -> V_315 . V_523 = F_328 ;
V_12 -> V_315 . V_526 = F_333 ;
V_12 -> V_315 . V_317 =
F_201 ;
} else if ( F_19 ( V_10 ) ) {
V_12 -> V_315 . V_1023 = F_459 ;
V_12 -> V_315 . V_1136 = F_454 ;
V_12 -> V_315 . V_1032 = F_451 ;
V_12 -> V_315 . V_522 = F_360 ;
V_12 -> V_315 . V_523 = F_371 ;
V_12 -> V_315 . V_526 = F_373 ;
V_12 -> V_315 . V_317 =
F_197 ;
} else {
V_12 -> V_315 . V_1023 = F_459 ;
V_12 -> V_315 . V_1136 = F_454 ;
V_12 -> V_315 . V_1032 = F_451 ;
V_12 -> V_315 . V_522 = F_369 ;
V_12 -> V_315 . V_523 = F_371 ;
V_12 -> V_315 . V_526 = F_373 ;
V_12 -> V_315 . V_317 =
F_197 ;
}
if ( F_19 ( V_10 ) )
V_12 -> V_315 . V_484 =
F_396 ;
else if ( F_444 ( V_10 ) || ( F_446 ( V_10 ) && ! F_756 ( V_10 ) ) )
V_12 -> V_315 . V_484 =
F_397 ;
else if ( F_395 ( V_10 ) )
V_12 -> V_315 . V_484 =
F_398 ;
else if ( F_445 ( V_10 ) || F_74 ( V_10 ) )
V_12 -> V_315 . V_484 =
F_399 ;
else if ( F_17 ( V_10 ) )
V_12 -> V_315 . V_484 =
F_400 ;
else if ( F_757 ( V_10 ) )
V_12 -> V_315 . V_484 =
F_402 ;
else if ( F_75 ( V_10 ) )
V_12 -> V_315 . V_484 =
F_403 ;
else if ( F_758 ( V_10 ) )
V_12 -> V_315 . V_484 =
F_404 ;
else
V_12 -> V_315 . V_484 =
F_405 ;
if ( F_4 ( V_10 ) ) {
if ( F_7 ( V_10 ) ) {
V_12 -> V_315 . V_401 = F_230 ;
V_12 -> V_315 . V_848 = F_523 ;
} else if ( F_237 ( V_10 ) ) {
V_12 -> V_315 . V_401 = F_235 ;
V_12 -> V_315 . V_848 = F_523 ;
V_12 -> V_315 . V_1030 =
F_509 ;
} else if ( F_227 ( V_10 ) ) {
V_12 -> V_315 . V_401 = F_238 ;
V_12 -> V_315 . V_848 = F_523 ;
V_12 -> V_315 . V_1030 =
F_229 ;
} else if ( F_202 ( V_10 ) || F_619 ( V_10 ) ) {
V_12 -> V_315 . V_401 = V_1137 ;
V_12 -> V_315 . V_848 = F_519 ;
V_12 -> V_315 . V_1030 =
F_510 ;
}
} else if ( F_16 ( V_10 ) ) {
V_12 -> V_315 . V_848 = F_518 ;
} else if ( F_19 ( V_10 ) ) {
V_12 -> V_315 . V_1030 =
F_359 ;
V_12 -> V_315 . V_848 = F_523 ;
}
V_12 -> V_315 . V_994 = F_633 ;
switch ( F_44 ( V_10 ) -> V_86 ) {
case 2 :
V_12 -> V_315 . V_994 = F_609 ;
break;
case 3 :
V_12 -> V_315 . V_994 = F_614 ;
break;
case 4 :
case 5 :
V_12 -> V_315 . V_994 = F_615 ;
break;
case 6 :
V_12 -> V_315 . V_994 = F_616 ;
break;
case 7 :
case 8 :
V_12 -> V_315 . V_994 = F_617 ;
break;
}
F_759 ( V_10 ) ;
}
static void F_760 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_145 |= V_146 ;
F_761 ( L_271 ) ;
}
static void F_762 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_145 |= V_581 ;
F_761 ( L_272 ) ;
}
static void F_763 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_145 |= V_1138 ;
F_761 ( L_273 ) ;
}
static void F_764 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_145 |= V_1139 ;
F_761 ( L_274 ) ;
}
static int F_765 ( const struct V_1140 * V_225 )
{
F_761 ( L_275 , V_225 -> V_1141 ) ;
return 1 ;
}
static void F_766 ( struct V_9 * V_10 )
{
struct V_1142 * V_1143 = V_10 -> V_545 ;
int V_150 ;
for ( V_150 = 0 ; V_150 < F_239 ( V_1144 ) ; V_150 ++ ) {
struct V_1145 * V_1146 = & V_1144 [ V_150 ] ;
if ( V_1143 -> V_1147 == V_1146 -> V_1147 &&
( V_1143 -> V_1148 == V_1146 -> V_1148 ||
V_1146 -> V_1148 == V_1149 ) &&
( V_1143 -> V_1150 == V_1146 -> V_1150 ||
V_1146 -> V_1150 == V_1149 ) )
V_1146 -> V_1151 ( V_10 ) ;
}
for ( V_150 = 0 ; V_150 < F_239 ( V_1152 ) ; V_150 ++ ) {
if ( F_767 ( * V_1152 [ V_150 ] . V_1153 ) != 0 )
V_1152 [ V_150 ] . V_1151 ( V_10 ) ;
}
}
static void F_768 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_9 V_1154 ;
T_1 V_1155 = F_769 ( V_10 ) ;
F_770 ( V_10 -> V_545 , V_1156 ) ;
F_771 ( V_1157 , V_1158 ) ;
V_1154 = F_772 ( V_1159 ) ;
F_771 ( V_1154 | 1 << 5 , V_1159 ) ;
F_773 ( V_10 -> V_545 , V_1156 ) ;
F_122 ( 300 ) ;
F_45 ( V_1155 , V_1160 ) ;
F_121 ( V_1155 ) ;
}
void F_774 ( struct V_9 * V_10 )
{
F_508 ( V_10 ) ;
if ( F_19 ( V_10 ) )
F_349 ( V_10 ) ;
F_775 ( V_10 ) ;
F_112 ( V_10 ) ;
F_776 ( V_10 ) ;
}
void F_777 ( struct V_9 * V_10 )
{
F_778 ( V_10 ) ;
}
void F_779 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_154 , V_256 ;
enum V_4 V_4 ;
struct V_73 * V_29 ;
F_780 ( V_10 ) ;
V_10 -> V_706 . V_1161 = 0 ;
V_10 -> V_706 . V_1162 = 0 ;
V_10 -> V_706 . V_1163 = 24 ;
V_10 -> V_706 . V_1164 = 1 ;
V_10 -> V_706 . V_794 = & V_1165 ;
F_766 ( V_10 ) ;
F_781 ( V_10 ) ;
if ( F_44 ( V_10 ) -> V_329 == 0 )
return;
F_755 ( V_10 ) ;
if ( F_20 ( V_10 ) ) {
V_10 -> V_706 . V_1166 = 2048 ;
V_10 -> V_706 . V_1167 = 2048 ;
} else if ( F_782 ( V_10 ) ) {
V_10 -> V_706 . V_1166 = 4096 ;
V_10 -> V_706 . V_1167 = 4096 ;
} else {
V_10 -> V_706 . V_1166 = 8192 ;
V_10 -> V_706 . V_1167 = 8192 ;
}
if ( F_20 ( V_10 ) ) {
V_10 -> V_706 . V_856 = V_1168 ;
V_10 -> V_706 . V_866 = V_1169 ;
} else {
V_10 -> V_706 . V_856 = V_1170 ;
V_10 -> V_706 . V_866 = V_1171 ;
}
V_10 -> V_706 . V_1172 = V_12 -> V_1173 . V_1174 ;
F_46 ( L_276 ,
F_44 ( V_10 ) -> V_329 ,
F_44 ( V_10 ) -> V_329 > 1 ? L_277 : L_278 ) ;
F_84 (pipe) {
F_711 ( V_10 , V_4 ) ;
F_86 (pipe, sprite) {
V_256 = F_783 ( V_10 , V_4 , V_154 ) ;
if ( V_256 )
F_46 ( L_279 ,
F_72 ( V_4 ) , F_88 ( V_4 , V_154 ) , V_256 ) ;
}
}
F_110 ( V_10 ) ;
F_112 ( V_10 ) ;
F_698 ( V_10 ) ;
F_768 ( V_10 ) ;
F_727 ( V_10 ) ;
F_306 ( V_10 ) ;
F_784 ( V_10 ) ;
F_785 ( V_10 , false ) ;
F_786 ( V_10 ) ;
F_244 (dev, crtc) {
if ( ! V_29 -> V_74 )
continue;
if ( V_12 -> V_315 . V_1136 ) {
V_12 -> V_315 . V_1136 ( V_29 ,
& V_29 -> V_290 ) ;
F_191 ( V_29 , & V_29 -> V_290 ) ;
}
}
}
static void F_787 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
struct V_525 * V_1175 = NULL ;
struct V_889 V_897 ;
struct V_891 * V_892 = V_10 -> V_706 . V_1176 ;
F_378 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_6 -> type == V_40 ) {
V_1175 = & V_3 -> V_8 ;
break;
}
}
if ( ! V_1175 )
return;
if ( F_560 ( V_1175 , NULL , & V_897 , V_892 ) )
F_565 ( V_1175 , & V_897 ) ;
}
static bool
F_788 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_88 , V_110 ;
if ( F_44 ( V_10 ) -> V_329 == 1 )
return true ;
V_88 = F_81 ( ! V_29 -> V_148 ) ;
V_110 = F_5 ( V_88 ) ;
if ( ( V_110 & V_149 ) &&
( ! ! ( V_110 & V_152 ) == V_29 -> V_4 ) )
return false ;
return true ;
}
static void F_789 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_88 ;
V_88 = F_51 ( V_29 -> V_77 . V_82 ) ;
F_45 ( V_88 , F_5 ( V_88 ) & ~ V_1177 ) ;
if ( V_29 -> V_74 )
F_302 ( V_10 , V_29 -> V_4 ) ;
else
F_307 ( V_10 , V_29 -> V_4 ) ;
if ( F_44 ( V_10 ) -> V_86 < 4 && ! F_788 ( V_29 ) ) {
struct V_2 * V_3 ;
bool V_148 ;
F_46 ( L_280 ,
V_29 -> V_8 . V_8 . V_225 ) ;
V_148 = V_29 -> V_148 ;
V_29 -> V_148 = ! V_148 ;
V_29 -> V_246 = true ;
V_12 -> V_315 . V_523 ( & V_29 -> V_8 ) ;
V_29 -> V_148 = V_148 ;
F_378 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
V_3 -> V_8 . V_527 = V_528 ;
V_3 -> V_8 . V_6 = NULL ;
}
F_378 (connector, &dev->mode_config.connector_list,
base.head)
if ( V_3 -> V_6 -> V_8 . V_29 == & V_29 -> V_8 ) {
V_3 -> V_6 -> V_8 . V_29 = NULL ;
V_3 -> V_6 -> V_524 = false ;
}
F_3 ( V_29 -> V_74 ) ;
V_29 -> V_8 . V_108 = false ;
}
if ( V_12 -> V_145 & V_146 &&
V_29 -> V_4 == V_132 && ! V_29 -> V_74 ) {
F_787 ( V_10 ) ;
}
F_376 ( & V_29 -> V_8 ) ;
if ( V_29 -> V_74 != V_29 -> V_8 . V_108 ) {
struct V_1 * V_6 ;
F_46 ( L_281 ,
V_29 -> V_8 . V_8 . V_225 ,
V_29 -> V_8 . V_108 ? L_190 : L_191 ,
V_29 -> V_74 ? L_190 : L_191 ) ;
V_29 -> V_8 . V_108 = V_29 -> V_74 ;
F_3 ( V_29 -> V_74 ) ;
F_11 (dev, &crtc->base, encoder) {
F_3 ( V_6 -> V_524 ) ;
V_6 -> V_8 . V_29 = NULL ;
}
}
if ( V_29 -> V_74 || F_19 ( V_10 ) || F_44 ( V_10 ) -> V_86 < 5 ) {
V_29 -> V_1178 = true ;
V_29 -> V_1179 = true ;
F_672 ( V_29 ) ;
}
}
static void F_790 ( struct V_1 * V_6 )
{
struct V_2 * V_3 ;
struct V_9 * V_10 = V_6 -> V_8 . V_10 ;
bool V_1180 = V_6 -> V_8 . V_29 &&
F_35 ( V_6 -> V_8 . V_29 ) -> V_74 ;
if ( V_6 -> V_524 && ! V_1180 ) {
F_46 ( L_282 ,
V_6 -> V_8 . V_8 . V_225 ,
V_6 -> V_8 . V_123 ) ;
if ( V_6 -> V_8 . V_29 ) {
F_46 ( L_283 ,
V_6 -> V_8 . V_8 . V_225 ,
V_6 -> V_8 . V_123 ) ;
V_6 -> V_228 ( V_6 ) ;
if ( V_6 -> V_448 )
V_6 -> V_448 ( V_6 ) ;
}
V_6 -> V_8 . V_29 = NULL ;
V_6 -> V_524 = false ;
F_378 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_6 != V_6 )
continue;
V_3 -> V_8 . V_527 = V_528 ;
V_3 -> V_8 . V_6 = NULL ;
}
}
}
void F_791 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_1155 = F_769 ( V_10 ) ;
if ( ! ( F_5 ( V_1155 ) & V_1160 ) ) {
F_46 ( L_284 ) ;
F_768 ( V_10 ) ;
}
}
void F_792 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_78 ( V_12 , V_1181 ) )
return;
F_791 ( V_10 ) ;
}
static bool F_793 ( struct V_73 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
if ( ! V_29 -> V_74 )
return false ;
return F_5 ( F_81 ( V_29 -> V_148 ) ) & V_149 ;
}
static void F_794 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 ;
struct V_73 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
int V_150 ;
F_244 (dev, crtc) {
memset ( & V_29 -> V_77 , 0 , sizeof( V_29 -> V_77 ) ) ;
V_29 -> V_77 . V_145 |= V_1018 ;
V_29 -> V_74 = V_12 -> V_315 . V_1023 ( V_29 ,
& V_29 -> V_77 ) ;
V_29 -> V_8 . V_108 = V_29 -> V_74 ;
V_29 -> V_246 = F_793 ( V_29 ) ;
F_46 ( L_285 ,
V_29 -> V_8 . V_8 . V_225 ,
V_29 -> V_74 ? L_190 : L_191 ) ;
}
for ( V_150 = 0 ; V_150 < V_12 -> V_418 ; V_150 ++ ) {
struct V_116 * V_119 = & V_12 -> V_118 [ V_150 ] ;
V_119 -> V_223 = V_119 -> V_122 ( V_12 , V_119 , & V_119 -> V_121 ) ;
V_119 -> V_74 = 0 ;
F_244 (dev, crtc) {
if ( V_29 -> V_74 && F_61 ( V_29 ) == V_119 )
V_119 -> V_74 ++ ;
}
V_119 -> V_222 = V_119 -> V_74 ;
F_46 ( L_286 ,
V_119 -> V_123 , V_119 -> V_222 , V_119 -> V_223 ) ;
if ( V_119 -> V_222 )
F_141 ( V_12 , V_226 ) ;
}
F_378 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_4 = 0 ;
if ( V_6 -> V_122 ( V_6 , & V_4 ) ) {
V_29 = F_35 ( V_12 -> V_81 [ V_4 ] ) ;
V_6 -> V_8 . V_29 = & V_29 -> V_8 ;
V_6 -> V_1024 ( V_6 , & V_29 -> V_77 ) ;
} else {
V_6 -> V_8 . V_29 = NULL ;
}
V_6 -> V_524 = false ;
F_46 ( L_287 ,
V_6 -> V_8 . V_8 . V_225 ,
V_6 -> V_8 . V_123 ,
V_6 -> V_8 . V_29 ? L_190 : L_191 ,
F_72 ( V_4 ) ) ;
}
F_378 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_122 ( V_3 ) ) {
V_3 -> V_8 . V_527 = V_530 ;
V_3 -> V_6 -> V_524 = true ;
V_3 -> V_8 . V_6 = & V_3 -> V_6 -> V_8 ;
} else {
V_3 -> V_8 . V_527 = V_528 ;
V_3 -> V_8 . V_6 = NULL ;
}
F_46 ( L_288 ,
V_3 -> V_8 . V_8 . V_225 ,
V_3 -> V_8 . V_123 ,
V_3 -> V_8 . V_6 ? L_190 : L_191 ) ;
}
}
void F_785 ( struct V_9 * V_10 ,
bool V_1182 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 ;
struct V_73 * V_29 ;
struct V_1 * V_6 ;
int V_150 ;
F_794 ( V_10 ) ;
F_244 (dev, crtc) {
if ( V_29 -> V_74 && V_330 . V_331 ) {
F_449 ( & V_29 -> V_8 . V_411 , & V_29 -> V_77 ) ;
F_46 ( L_289 ,
V_29 -> V_8 . V_8 . V_225 ) ;
F_649 ( & V_29 -> V_8 . V_411 ) ;
}
}
F_378 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_790 ( V_6 ) ;
}
F_84 (pipe) {
V_29 = F_35 ( V_12 -> V_81 [ V_4 ] ) ;
F_789 ( V_29 ) ;
F_647 ( V_29 , & V_29 -> V_77 , L_290 ) ;
}
for ( V_150 = 0 ; V_150 < V_12 -> V_418 ; V_150 ++ ) {
struct V_116 * V_119 = & V_12 -> V_118 [ V_150 ] ;
if ( ! V_119 -> V_223 || V_119 -> V_74 )
continue;
F_46 ( L_291 , V_119 -> V_123 ) ;
V_119 -> V_228 ( V_12 , V_119 ) ;
V_119 -> V_223 = false ;
}
if ( F_4 ( V_10 ) )
F_795 ( V_10 ) ;
if ( V_1182 ) {
F_792 ( V_10 ) ;
F_84 (pipe) {
struct V_28 * V_29 =
V_12 -> V_81 [ V_4 ] ;
F_673 ( V_29 , & V_29 -> V_411 , V_29 -> V_267 , V_29 -> V_268 ,
V_29 -> V_75 -> V_76 ) ;
}
} else {
F_642 ( V_10 ) ;
}
F_385 ( V_10 ) ;
}
void F_796 ( struct V_9 * V_10 )
{
struct V_28 * V_300 ;
struct V_251 * V_252 ;
F_58 ( & V_10 -> V_257 ) ;
F_797 ( V_10 ) ;
F_60 ( & V_10 -> V_257 ) ;
F_774 ( V_10 ) ;
F_798 ( V_10 ) ;
F_58 ( & V_10 -> V_257 ) ;
F_193 (dev, c) {
V_252 = F_194 ( V_300 -> V_75 -> V_76 ) ;
if ( V_252 == NULL )
continue;
if ( F_171 ( V_10 , V_252 , NULL ) ) {
F_114 ( L_292 ,
F_35 ( V_300 ) -> V_4 ) ;
F_567 ( V_300 -> V_75 -> V_76 ) ;
V_300 -> V_75 -> V_76 = NULL ;
}
}
F_60 ( & V_10 -> V_257 ) ;
}
void F_799 ( struct V_2 * V_2 )
{
struct V_525 * V_3 = & V_2 -> V_8 ;
F_800 ( V_3 ) ;
F_801 ( V_3 ) ;
}
void F_802 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_525 * V_3 ;
F_803 ( V_10 ) ;
F_804 ( V_12 ) ;
V_12 -> V_1183 . V_1184 = true ;
F_805 ( V_10 ) ;
F_58 ( & V_10 -> V_257 ) ;
F_806 () ;
F_306 ( V_10 ) ;
F_807 ( V_10 ) ;
F_808 ( V_10 ) ;
F_60 ( & V_10 -> V_257 ) ;
F_809 () ;
F_378 (connector, &dev->mode_config.connector_list, head) {
struct V_2 * V_2 ;
V_2 = F_561 ( V_3 ) ;
V_2 -> V_1185 ( V_2 ) ;
}
F_810 ( V_10 ) ;
F_811 ( V_10 ) ;
F_58 ( & V_10 -> V_257 ) ;
F_812 ( V_10 ) ;
F_60 ( & V_10 -> V_257 ) ;
}
struct V_529 * F_813 ( struct V_525 * V_3 )
{
return & F_533 ( V_3 ) -> V_8 ;
}
void F_814 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
V_3 -> V_6 = V_6 ;
F_815 ( & V_3 -> V_8 ,
& V_6 -> V_8 ) ;
}
int F_816 ( struct V_9 * V_10 , bool V_109 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned V_88 = F_44 ( V_10 ) -> V_86 >= 6 ? V_1186 : V_1187 ;
T_5 V_1188 ;
if ( F_401 ( V_12 -> V_1189 , V_88 , & V_1188 ) ) {
F_114 ( L_293 ) ;
return - V_996 ;
}
if ( ! ! ( V_1188 & V_1190 ) == ! V_109 )
return 0 ;
if ( V_109 )
V_1188 &= ~ V_1190 ;
else
V_1188 |= V_1190 ;
if ( F_817 ( V_12 -> V_1189 , V_88 , V_1188 ) ) {
F_114 ( L_294 ) ;
return - V_996 ;
}
return 0 ;
}
struct V_1191 *
F_818 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1191 * error ;
int V_1192 [] = {
V_239 ,
V_1193 ,
V_1194 ,
V_663 ,
} ;
int V_150 ;
if ( F_44 ( V_10 ) -> V_329 == 0 )
return NULL ;
error = F_455 ( sizeof( * error ) , V_1195 ) ;
if ( error == NULL )
return NULL ;
if ( F_202 ( V_10 ) || F_165 ( V_10 ) )
error -> V_1196 = F_5 ( V_760 ) ;
F_84 (i) {
error -> V_4 [ V_150 ] . V_1197 =
F_819 ( V_12 ,
F_343 ( V_150 ) ) ;
if ( ! error -> V_4 [ V_150 ] . V_1197 )
continue;
error -> V_1078 [ V_150 ] . V_453 = F_5 ( F_76 ( V_150 ) ) ;
error -> V_1078 [ V_150 ] . V_1198 = F_5 ( F_541 ( V_150 ) ) ;
error -> V_1078 [ V_150 ] . V_8 = F_5 ( F_539 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_453 = F_5 ( F_81 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_294 = F_5 ( F_198 ( V_150 ) ) ;
if ( F_44 ( V_10 ) -> V_86 <= 3 ) {
error -> V_148 [ V_150 ] . V_293 = F_5 ( F_362 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_422 = F_5 ( F_363 ( V_150 ) ) ;
}
if ( F_44 ( V_10 ) -> V_86 <= 7 && ! F_202 ( V_10 ) )
error -> V_148 [ V_150 ] . V_869 = F_5 ( F_162 ( V_150 ) ) ;
if ( F_44 ( V_10 ) -> V_86 >= 4 ) {
error -> V_148 [ V_150 ] . V_1199 = F_5 ( F_161 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_1200 = F_5 ( F_199 ( V_150 ) ) ;
}
error -> V_4 [ V_150 ] . V_1201 = F_5 ( F_220 ( V_150 ) ) ;
if ( F_296 ( V_10 ) )
error -> V_4 [ V_150 ] . V_1202 = F_5 ( F_43 ( V_150 ) ) ;
}
error -> V_1203 = F_44 ( V_10 ) -> V_329 ;
if ( F_64 ( V_12 -> V_10 ) )
error -> V_1203 ++ ;
for ( V_150 = 0 ; V_150 < error -> V_1203 ; V_150 ++ ) {
enum V_80 V_82 = V_1192 [ V_150 ] ;
error -> V_80 [ V_150 ] . V_1197 =
F_819 ( V_12 ,
F_79 ( V_82 ) ) ;
if ( ! error -> V_80 [ V_150 ] . V_1197 )
continue;
error -> V_80 [ V_150 ] . V_82 = V_82 ;
error -> V_80 [ V_150 ] . V_1204 = F_5 ( F_51 ( V_82 ) ) ;
error -> V_80 [ V_150 ] . V_665 = F_5 ( F_257 ( V_82 ) ) ;
error -> V_80 [ V_150 ] . V_1205 = F_5 ( F_259 ( V_82 ) ) ;
error -> V_80 [ V_150 ] . V_925 = F_5 ( F_261 ( V_82 ) ) ;
error -> V_80 [ V_150 ] . V_667 = F_5 ( F_263 ( V_82 ) ) ;
error -> V_80 [ V_150 ] . V_1206 = F_5 ( F_265 ( V_82 ) ) ;
error -> V_80 [ V_150 ] . V_927 = F_5 ( F_267 ( V_82 ) ) ;
}
return error ;
}
void
F_820 ( struct V_1207 * V_19 ,
struct V_9 * V_10 ,
struct V_1191 * error )
{
int V_150 ;
if ( ! error )
return;
F_821 ( V_19 , L_295 , F_44 ( V_10 ) -> V_329 ) ;
if ( F_202 ( V_10 ) || F_165 ( V_10 ) )
F_821 ( V_19 , L_296 ,
error -> V_1196 ) ;
F_84 (i) {
F_821 ( V_19 , L_297 , V_150 ) ;
F_821 ( V_19 , L_298 ,
error -> V_4 [ V_150 ] . V_1197 ? L_12 : L_13 ) ;
F_821 ( V_19 , L_299 , error -> V_4 [ V_150 ] . V_1201 ) ;
F_821 ( V_19 , L_300 , error -> V_4 [ V_150 ] . V_1202 ) ;
F_821 ( V_19 , L_301 , V_150 ) ;
F_821 ( V_19 , L_302 , error -> V_148 [ V_150 ] . V_453 ) ;
F_821 ( V_19 , L_303 , error -> V_148 [ V_150 ] . V_294 ) ;
if ( F_44 ( V_10 ) -> V_86 <= 3 ) {
F_821 ( V_19 , L_304 , error -> V_148 [ V_150 ] . V_293 ) ;
F_821 ( V_19 , L_305 , error -> V_148 [ V_150 ] . V_422 ) ;
}
if ( F_44 ( V_10 ) -> V_86 <= 7 && ! F_202 ( V_10 ) )
F_821 ( V_19 , L_306 , error -> V_148 [ V_150 ] . V_869 ) ;
if ( F_44 ( V_10 ) -> V_86 >= 4 ) {
F_821 ( V_19 , L_307 , error -> V_148 [ V_150 ] . V_1199 ) ;
F_821 ( V_19 , L_308 , error -> V_148 [ V_150 ] . V_1200 ) ;
}
F_821 ( V_19 , L_309 , V_150 ) ;
F_821 ( V_19 , L_302 , error -> V_1078 [ V_150 ] . V_453 ) ;
F_821 ( V_19 , L_305 , error -> V_1078 [ V_150 ] . V_1198 ) ;
F_821 ( V_19 , L_310 , error -> V_1078 [ V_150 ] . V_8 ) ;
}
for ( V_150 = 0 ; V_150 < error -> V_1203 ; V_150 ++ ) {
F_821 ( V_19 , L_311 ,
F_648 ( error -> V_80 [ V_150 ] . V_82 ) ) ;
F_821 ( V_19 , L_298 ,
error -> V_80 [ V_150 ] . V_1197 ? L_12 : L_13 ) ;
F_821 ( V_19 , L_312 , error -> V_80 [ V_150 ] . V_1204 ) ;
F_821 ( V_19 , L_313 , error -> V_80 [ V_150 ] . V_665 ) ;
F_821 ( V_19 , L_314 , error -> V_80 [ V_150 ] . V_1205 ) ;
F_821 ( V_19 , L_315 , error -> V_80 [ V_150 ] . V_925 ) ;
F_821 ( V_19 , L_316 , error -> V_80 [ V_150 ] . V_667 ) ;
F_821 ( V_19 , L_317 , error -> V_80 [ V_150 ] . V_1206 ) ;
F_821 ( V_19 , L_318 , error -> V_80 [ V_150 ] . V_927 ) ;
}
}
