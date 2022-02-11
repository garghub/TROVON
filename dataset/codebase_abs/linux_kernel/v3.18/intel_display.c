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
F_41 ( 1 , L_10 ,
F_42 ( V_4 ) ) ;
}
void F_43 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_85 = F_44 ( V_4 ) ;
if ( F_16 ( V_10 ) || F_45 ( V_10 ) -> V_86 >= 5 ) {
F_37 ( V_10 , V_4 ) ;
return;
}
F_46 ( V_85 ,
F_5 ( V_85 ) | V_87 ) ;
if ( F_39 ( F_5 ( V_85 ) &
V_87 ,
50 ) )
F_47 ( L_10 ,
F_42 ( V_4 ) ) ;
}
static bool F_48 ( struct V_9 * V_10 , enum V_4 V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_88 = F_49 ( V_4 ) ;
T_1 V_89 , V_90 ;
T_1 V_91 ;
if ( F_20 ( V_10 ) )
V_91 = V_92 ;
else
V_91 = V_93 ;
V_89 = F_5 ( V_88 ) & V_91 ;
F_50 ( 5 ) ;
V_90 = F_5 ( V_88 ) & V_91 ;
return V_89 == V_90 ;
}
static void F_51 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_80 V_82 = V_29 -> V_77 . V_82 ;
enum V_4 V_4 = V_29 -> V_4 ;
if ( F_45 ( V_10 ) -> V_86 >= 4 ) {
int V_88 = F_52 ( V_82 ) ;
if ( F_39 ( ( F_5 ( V_88 ) & V_94 ) == 0 ,
100 ) )
F_41 ( 1 , L_11 ) ;
} else {
if ( F_39 ( F_48 ( V_10 , V_4 ) , 100 ) )
F_41 ( 1 , L_11 ) ;
}
}
bool F_53 ( struct V_11 * V_12 ,
struct V_95 * V_96 )
{
T_1 V_97 ;
if ( F_54 ( V_12 -> V_10 ) ) {
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
static const char * F_55 ( bool V_108 )
{
return V_108 ? L_12 : L_13 ;
}
void F_56 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_109 )
{
int V_88 ;
T_1 V_110 ;
bool V_111 ;
V_88 = F_57 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_111 = ! ! ( V_110 & V_112 ) ;
F_41 ( V_111 != V_109 ,
L_14 ,
F_55 ( V_109 ) , F_55 ( V_111 ) ) ;
}
static void F_58 ( struct V_11 * V_12 , bool V_109 )
{
T_1 V_110 ;
bool V_111 ;
F_59 ( & V_12 -> V_113 ) ;
V_110 = F_60 ( V_12 , V_114 ) ;
F_61 ( & V_12 -> V_113 ) ;
V_111 = V_110 & V_115 ;
F_41 ( V_111 != V_109 ,
L_15 ,
F_55 ( V_109 ) , F_55 ( V_111 ) ) ;
}
struct V_116 *
F_62 ( struct V_73 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
if ( V_29 -> V_77 . V_117 < 0 )
return NULL ;
return & V_12 -> V_118 [ V_29 -> V_77 . V_117 ] ;
}
void F_63 ( struct V_11 * V_12 ,
struct V_116 * V_119 ,
bool V_109 )
{
bool V_111 ;
struct V_120 V_121 ;
if ( F_41 ( ! V_119 ,
L_16 , F_55 ( V_109 ) ) )
return;
V_111 = V_119 -> V_122 ( V_12 , V_119 , & V_121 ) ;
F_41 ( V_111 != V_109 ,
L_17 ,
V_119 -> V_123 , F_55 ( V_109 ) , F_55 ( V_111 ) ) ;
}
static void F_64 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_109 )
{
int V_88 ;
T_1 V_110 ;
bool V_111 ;
enum V_80 V_82 = F_36 ( V_12 ,
V_4 ) ;
if ( F_65 ( V_12 -> V_10 ) ) {
V_88 = F_66 ( V_82 ) ;
V_110 = F_5 ( V_88 ) ;
V_111 = ! ! ( V_110 & V_124 ) ;
} else {
V_88 = F_67 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_111 = ! ! ( V_110 & V_125 ) ;
}
F_41 ( V_111 != V_109 ,
L_18 ,
F_55 ( V_109 ) , F_55 ( V_111 ) ) ;
}
static void F_68 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_109 )
{
int V_88 ;
T_1 V_110 ;
bool V_111 ;
V_88 = F_69 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_111 = ! ! ( V_110 & V_126 ) ;
F_41 ( V_111 != V_109 ,
L_19 ,
F_55 ( V_109 ) , F_55 ( V_111 ) ) ;
}
static void F_70 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_88 ;
T_1 V_110 ;
if ( F_45 ( V_12 -> V_10 ) -> V_86 == 5 )
return;
if ( F_65 ( V_12 -> V_10 ) )
return;
V_88 = F_67 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
F_41 ( ! ( V_110 & V_127 ) , L_20 ) ;
}
void F_71 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_109 )
{
int V_88 ;
T_1 V_110 ;
bool V_111 ;
V_88 = F_69 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_111 = ! ! ( V_110 & V_128 ) ;
F_41 ( V_111 != V_109 ,
L_21 ,
F_55 ( V_109 ) , F_55 ( V_111 ) ) ;
}
static void F_72 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_129 ;
T_1 V_110 ;
enum V_4 V_130 = V_131 ;
bool V_132 = true ;
if ( F_3 ( F_65 ( V_10 ) ) )
return;
if ( F_4 ( V_10 ) ) {
T_1 V_133 ;
V_129 = V_134 ;
V_133 = F_5 ( V_135 ) & V_136 ;
if ( V_133 == V_137 &&
F_5 ( V_138 ) & V_139 )
V_130 = V_140 ;
} else if ( F_19 ( V_10 ) ) {
V_129 = F_73 ( V_4 ) ;
V_130 = V_4 ;
} else {
V_129 = V_141 ;
if ( F_5 ( V_142 ) & V_139 )
V_130 = V_140 ;
}
V_110 = F_5 ( V_129 ) ;
if ( ! ( V_110 & V_143 ) ||
( ( V_110 & V_144 ) == V_145 ) )
V_132 = false ;
F_41 ( V_130 == V_4 && V_132 ,
L_22 ,
F_42 ( V_4 ) ) ;
}
static void F_74 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_109 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
bool V_111 ;
if ( F_75 ( V_10 ) || F_76 ( V_10 ) )
V_111 = F_5 ( V_146 ) & V_147 ;
else
V_111 = F_5 ( F_77 ( V_4 ) ) & V_148 ;
F_41 ( V_111 != V_109 ,
L_23 ,
F_42 ( V_4 ) , F_55 ( V_109 ) , F_55 ( V_111 ) ) ;
}
void F_78 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_109 )
{
int V_88 ;
T_1 V_110 ;
bool V_111 ;
enum V_80 V_82 = F_36 ( V_12 ,
V_4 ) ;
if ( ( V_4 == V_131 && V_12 -> V_149 & V_150 ) ||
( V_4 == V_140 && V_12 -> V_149 & V_151 ) )
V_109 = true ;
if ( ! F_79 ( V_12 ,
F_80 ( V_82 ) ) ) {
V_111 = false ;
} else {
V_88 = F_52 ( V_82 ) ;
V_110 = F_5 ( V_88 ) ;
V_111 = ! ! ( V_110 & V_152 ) ;
}
F_41 ( V_111 != V_109 ,
L_24 ,
F_42 ( V_4 ) , F_55 ( V_109 ) , F_55 ( V_111 ) ) ;
}
static void F_81 ( struct V_11 * V_12 ,
enum V_153 V_153 , bool V_109 )
{
int V_88 ;
T_1 V_110 ;
bool V_111 ;
V_88 = F_82 ( V_153 ) ;
V_110 = F_5 ( V_88 ) ;
V_111 = ! ! ( V_110 & V_154 ) ;
F_41 ( V_111 != V_109 ,
L_25 ,
F_83 ( V_153 ) , F_55 ( V_109 ) , F_55 ( V_111 ) ) ;
}
static void F_84 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_88 , V_155 ;
T_1 V_110 ;
int V_156 ;
if ( F_45 ( V_10 ) -> V_86 >= 4 ) {
V_88 = F_82 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
F_41 ( V_110 & V_154 ,
L_26 ,
F_83 ( V_4 ) ) ;
return;
}
F_85 (dev_priv, i) {
V_88 = F_82 ( V_155 ) ;
V_110 = F_5 ( V_88 ) ;
V_156 = ( V_110 & V_157 ) >>
V_158 ;
F_41 ( ( V_110 & V_154 ) && V_4 == V_156 ,
L_27 ,
F_83 ( V_155 ) , F_42 ( V_4 ) ) ;
}
}
static void F_86 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_88 , V_159 ;
T_1 V_110 ;
if ( F_19 ( V_10 ) ) {
F_87 (pipe, sprite) {
V_88 = F_88 ( V_4 , V_159 ) ;
V_110 = F_5 ( V_88 ) ;
F_41 ( V_110 & V_160 ,
L_28 ,
F_89 ( V_4 , V_159 ) , F_42 ( V_4 ) ) ;
}
} else if ( F_45 ( V_10 ) -> V_86 >= 7 ) {
V_88 = F_90 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
F_41 ( V_110 & V_161 ,
L_28 ,
F_83 ( V_4 ) , F_42 ( V_4 ) ) ;
} else if ( F_45 ( V_10 ) -> V_86 >= 5 ) {
V_88 = F_91 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
F_41 ( V_110 & V_162 ,
L_28 ,
F_83 ( V_4 ) , F_42 ( V_4 ) ) ;
}
}
static void F_92 ( struct V_28 * V_29 )
{
if ( F_3 ( F_93 ( V_29 ) == 0 ) )
F_94 ( V_29 ) ;
}
static void F_95 ( struct V_11 * V_12 )
{
T_1 V_110 ;
bool V_108 ;
F_3 ( ! ( F_54 ( V_12 -> V_10 ) || F_96 ( V_12 -> V_10 ) ) ) ;
V_110 = F_5 ( V_163 ) ;
V_108 = ! ! ( V_110 & ( V_164 | V_165 |
V_166 ) ) ;
F_41 ( ! V_108 , L_29 ) ;
}
static void F_97 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_88 ;
T_1 V_110 ;
bool V_108 ;
V_88 = F_98 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_108 = ! ! ( V_110 & V_167 ) ;
F_41 ( V_108 ,
L_30 ,
F_42 ( V_4 ) ) ;
}
static bool F_99 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_133 , T_1 V_110 )
{
if ( ( V_110 & V_168 ) == 0 )
return false ;
if ( F_96 ( V_12 -> V_10 ) ) {
T_1 V_169 = F_100 ( V_4 ) ;
T_1 V_170 = F_5 ( V_169 ) ;
if ( ( V_170 & V_171 ) != V_133 )
return false ;
} else if ( F_18 ( V_12 -> V_10 ) ) {
if ( ( V_110 & V_172 ) != F_101 ( V_4 ) )
return false ;
} else {
if ( ( V_110 & V_173 ) != ( V_4 << 30 ) )
return false ;
}
return true ;
}
static bool F_102 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_110 )
{
if ( ( V_110 & V_174 ) == 0 )
return false ;
if ( F_96 ( V_12 -> V_10 ) ) {
if ( ( V_110 & V_175 ) != F_103 ( V_4 ) )
return false ;
} else if ( F_18 ( V_12 -> V_10 ) ) {
if ( ( V_110 & V_176 ) != F_104 ( V_4 ) )
return false ;
} else {
if ( ( V_110 & V_177 ) != F_105 ( V_4 ) )
return false ;
}
return true ;
}
static bool F_106 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_110 )
{
if ( ( V_110 & V_178 ) == 0 )
return false ;
if ( F_96 ( V_12 -> V_10 ) ) {
if ( ( V_110 & V_179 ) != F_107 ( V_4 ) )
return false ;
} else {
if ( ( V_110 & V_180 ) != F_108 ( V_4 ) )
return false ;
}
return true ;
}
static bool F_109 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_110 )
{
if ( ( V_110 & V_181 ) == 0 )
return false ;
if ( F_96 ( V_12 -> V_10 ) ) {
if ( ( V_110 & V_179 ) != F_107 ( V_4 ) )
return false ;
} else {
if ( ( V_110 & V_182 ) != F_110 ( V_4 ) )
return false ;
}
return true ;
}
static void F_111 ( struct V_11 * V_12 ,
enum V_4 V_4 , int V_88 , T_1 V_133 )
{
T_1 V_110 = F_5 ( V_88 ) ;
F_41 ( F_99 ( V_12 , V_4 , V_133 , V_110 ) ,
L_31 ,
V_88 , F_42 ( V_4 ) ) ;
F_41 ( F_54 ( V_12 -> V_10 ) && ( V_110 & V_168 ) == 0
&& ( V_110 & V_183 ) ,
L_32 ) ;
}
static void F_112 ( struct V_11 * V_12 ,
enum V_4 V_4 , int V_88 )
{
T_1 V_110 = F_5 ( V_88 ) ;
F_41 ( F_102 ( V_12 , V_4 , V_110 ) ,
L_33 ,
V_88 , F_42 ( V_4 ) ) ;
F_41 ( F_54 ( V_12 -> V_10 ) && ( V_110 & V_174 ) == 0
&& ( V_110 & V_184 ) ,
L_34 ) ;
}
static void F_113 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_88 ;
T_1 V_110 ;
F_111 ( V_12 , V_4 , V_185 , V_186 ) ;
F_111 ( V_12 , V_4 , V_187 , V_188 ) ;
F_111 ( V_12 , V_4 , V_189 , V_190 ) ;
V_88 = V_191 ;
V_110 = F_5 ( V_88 ) ;
F_41 ( F_109 ( V_12 , V_4 , V_110 ) ,
L_35 ,
F_42 ( V_4 ) ) ;
V_88 = V_138 ;
V_110 = F_5 ( V_88 ) ;
F_41 ( F_106 ( V_12 , V_4 , V_110 ) ,
L_36 ,
F_42 ( V_4 ) ) ;
F_112 ( V_12 , V_4 , V_192 ) ;
F_112 ( V_12 , V_4 , V_193 ) ;
F_112 ( V_12 , V_4 , V_194 ) ;
}
static void F_114 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_19 ( V_10 ) )
return;
if ( F_18 ( V_10 ) ) {
F_115 ( V_195 ) = V_196 ;
F_115 ( V_197 ) = V_198 ;
} else {
F_115 ( V_195 ) = V_198 ;
}
}
static void F_116 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_88 = F_57 ( V_29 -> V_4 ) ;
T_1 V_54 = V_29 -> V_77 . V_199 . V_54 ;
F_117 ( V_12 , V_29 -> V_4 ) ;
F_118 ( ! F_19 ( V_12 -> V_10 ) ) ;
if ( F_119 ( V_12 -> V_10 ) )
F_72 ( V_12 , V_29 -> V_4 ) ;
F_46 ( V_88 , V_54 ) ;
F_120 ( V_88 ) ;
F_121 ( 150 ) ;
if ( F_39 ( ( ( F_5 ( V_88 ) & V_200 ) == V_200 ) , 1 ) )
F_122 ( L_37 , V_29 -> V_4 ) ;
F_46 ( F_123 ( V_29 -> V_4 ) , V_29 -> V_77 . V_199 . V_201 ) ;
F_120 ( F_123 ( V_29 -> V_4 ) ) ;
F_46 ( V_88 , V_54 ) ;
F_120 ( V_88 ) ;
F_121 ( 150 ) ;
F_46 ( V_88 , V_54 ) ;
F_120 ( V_88 ) ;
F_121 ( 150 ) ;
F_46 ( V_88 , V_54 ) ;
F_120 ( V_88 ) ;
F_121 ( 150 ) ;
}
static void F_124 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
enum V_202 V_96 = F_125 ( V_4 ) ;
T_1 V_203 ;
F_117 ( V_12 , V_29 -> V_4 ) ;
F_118 ( ! F_18 ( V_12 -> V_10 ) ) ;
F_59 ( & V_12 -> V_113 ) ;
V_203 = F_126 ( V_12 , V_4 , F_127 ( V_96 ) ) ;
V_203 |= V_204 ;
F_128 ( V_12 , V_4 , F_127 ( V_96 ) , V_203 ) ;
F_121 ( 1 ) ;
F_46 ( F_57 ( V_4 ) , V_29 -> V_77 . V_199 . V_54 ) ;
if ( F_39 ( ( ( F_5 ( F_57 ( V_4 ) ) & V_200 ) == V_200 ) , 1 ) )
F_122 ( L_38 , V_4 ) ;
F_46 ( F_123 ( V_4 ) , V_29 -> V_77 . V_199 . V_201 ) ;
F_120 ( F_123 ( V_4 ) ) ;
F_61 ( & V_12 -> V_113 ) ;
}
static int F_129 ( struct V_9 * V_10 )
{
struct V_73 * V_29 ;
int V_205 = 0 ;
F_130 (dev, crtc)
V_205 += V_29 -> V_74 &&
F_10 ( & V_29 -> V_8 , V_51 ) ;
return V_205 ;
}
static void F_131 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_88 = F_57 ( V_29 -> V_4 ) ;
T_1 V_54 = V_29 -> V_77 . V_199 . V_54 ;
F_117 ( V_12 , V_29 -> V_4 ) ;
F_118 ( F_45 ( V_10 ) -> V_86 >= 5 ) ;
if ( F_119 ( V_10 ) && ! F_132 ( V_10 ) )
F_72 ( V_12 , V_29 -> V_4 ) ;
if ( F_132 ( V_10 ) && F_129 ( V_10 ) > 0 ) {
V_54 |= V_206 ;
F_46 ( F_57 ( ! V_29 -> V_4 ) ,
F_5 ( F_57 ( ! V_29 -> V_4 ) ) | V_206 ) ;
}
F_120 ( V_88 ) ;
F_121 ( 150 ) ;
if ( F_45 ( V_10 ) -> V_86 >= 4 ) {
F_46 ( F_123 ( V_29 -> V_4 ) ,
V_29 -> V_77 . V_199 . V_201 ) ;
} else {
F_46 ( V_88 , V_54 ) ;
}
F_46 ( V_88 , V_54 ) ;
F_120 ( V_88 ) ;
F_121 ( 150 ) ;
F_46 ( V_88 , V_54 ) ;
F_120 ( V_88 ) ;
F_121 ( 150 ) ;
F_46 ( V_88 , V_54 ) ;
F_120 ( V_88 ) ;
F_121 ( 150 ) ;
}
static void F_133 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
if ( F_132 ( V_10 ) &&
F_10 ( & V_29 -> V_8 , V_51 ) &&
F_129 ( V_10 ) == 1 ) {
F_46 ( F_57 ( V_140 ) ,
F_5 ( F_57 ( V_140 ) ) & ~ V_206 ) ;
F_46 ( F_57 ( V_131 ) ,
F_5 ( F_57 ( V_131 ) ) & ~ V_206 ) ;
}
if ( ( V_4 == V_131 && V_12 -> V_149 & V_150 ) ||
( V_4 == V_140 && V_12 -> V_149 & V_151 ) )
return;
F_117 ( V_12 , V_4 ) ;
F_46 ( F_57 ( V_4 ) , 0 ) ;
F_120 ( F_57 ( V_4 ) ) ;
}
static void F_134 ( struct V_11 * V_12 , enum V_4 V_4 )
{
T_1 V_110 = 0 ;
F_117 ( V_12 , V_4 ) ;
if ( V_4 == V_140 )
V_110 = V_207 | V_208 ;
F_46 ( F_57 ( V_4 ) , V_110 ) ;
F_120 ( F_57 ( V_4 ) ) ;
}
static void F_135 ( struct V_11 * V_12 , enum V_4 V_4 )
{
enum V_202 V_96 = F_125 ( V_4 ) ;
T_1 V_110 ;
F_117 ( V_12 , V_4 ) ;
V_110 = V_209 | V_208 ;
if ( V_4 != V_131 )
V_110 |= V_207 ;
F_46 ( F_57 ( V_4 ) , V_110 ) ;
F_120 ( F_57 ( V_4 ) ) ;
F_59 ( & V_12 -> V_113 ) ;
V_110 = F_126 ( V_12 , V_4 , F_127 ( V_96 ) ) ;
V_110 &= ~ V_204 ;
F_128 ( V_12 , V_4 , F_127 ( V_96 ) , V_110 ) ;
if ( V_4 != V_140 ) {
V_110 = F_126 ( V_12 , V_4 , V_210 ) ;
V_110 &= ~ ( V_211 | V_212 ) ;
F_128 ( V_12 , V_4 , V_210 , V_110 ) ;
} else {
V_110 = F_126 ( V_12 , V_4 , V_213 ) ;
V_110 &= ~ ( V_214 | V_215 ) ;
F_128 ( V_12 , V_4 , V_213 , V_110 ) ;
}
F_61 ( & V_12 -> V_113 ) ;
}
void F_136 ( struct V_11 * V_12 ,
struct V_95 * V_216 )
{
T_1 V_217 ;
int V_218 ;
switch ( V_216 -> V_96 ) {
case V_98 :
V_217 = V_219 ;
V_218 = F_57 ( 0 ) ;
break;
case V_100 :
V_217 = V_220 ;
V_218 = F_57 ( 0 ) ;
break;
case V_102 :
V_217 = V_221 ;
V_218 = V_222 ;
break;
default:
F_137 () ;
}
if ( F_39 ( ( F_5 ( V_218 ) & V_217 ) == 0 , 1000 ) )
F_41 ( 1 , L_39 ,
F_138 ( V_216 -> V_96 ) , F_5 ( V_218 ) ) ;
}
static void F_139 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_116 * V_119 = F_62 ( V_29 ) ;
if ( F_3 ( V_119 == NULL ) )
return;
F_3 ( ! V_119 -> V_223 ) ;
if ( V_119 -> V_74 == 0 ) {
F_140 ( L_40 , V_119 -> V_123 ) ;
F_3 ( V_119 -> V_224 ) ;
F_141 ( V_12 , V_119 ) ;
V_119 -> V_225 ( V_12 , V_119 ) ;
}
}
static void F_142 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_116 * V_119 = F_62 ( V_29 ) ;
if ( F_3 ( V_119 == NULL ) )
return;
if ( F_3 ( V_119 -> V_223 == 0 ) )
return;
F_47 ( L_41 ,
V_119 -> V_123 , V_119 -> V_74 , V_119 -> V_224 ,
V_29 -> V_8 . V_8 . V_226 ) ;
if ( V_119 -> V_74 ++ ) {
F_3 ( ! V_119 -> V_224 ) ;
F_143 ( V_12 , V_119 ) ;
return;
}
F_3 ( V_119 -> V_224 ) ;
F_144 ( V_12 , V_227 ) ;
F_47 ( L_42 , V_119 -> V_123 ) ;
V_119 -> V_228 ( V_12 , V_119 ) ;
V_119 -> V_224 = true ;
}
static void F_145 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_116 * V_119 = F_62 ( V_29 ) ;
F_118 ( F_45 ( V_10 ) -> V_86 < 5 ) ;
if ( F_3 ( V_119 == NULL ) )
return;
if ( F_3 ( V_119 -> V_223 == 0 ) )
return;
F_47 ( L_43 ,
V_119 -> V_123 , V_119 -> V_74 , V_119 -> V_224 ,
V_29 -> V_8 . V_8 . V_226 ) ;
if ( F_3 ( V_119 -> V_74 == 0 ) ) {
F_141 ( V_12 , V_119 ) ;
return;
}
F_143 ( V_12 , V_119 ) ;
F_3 ( ! V_119 -> V_224 ) ;
if ( -- V_119 -> V_74 )
return;
F_47 ( L_44 , V_119 -> V_123 ) ;
V_119 -> V_229 ( V_12 , V_119 ) ;
V_119 -> V_224 = false ;
F_146 ( V_12 , V_227 ) ;
}
static void F_147 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_28 * V_29 = V_12 -> V_81 [ V_4 ] ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
T_4 V_88 , V_110 , V_230 ;
F_118 ( ! F_4 ( V_10 ) ) ;
F_143 ( V_12 ,
F_62 ( V_73 ) ) ;
F_148 ( V_12 , V_4 ) ;
F_149 ( V_12 , V_4 ) ;
if ( F_96 ( V_10 ) ) {
V_88 = F_150 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_110 |= V_231 ;
F_46 ( V_88 , V_110 ) ;
}
V_88 = F_98 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_230 = F_5 ( F_52 ( V_4 ) ) ;
if ( F_54 ( V_12 -> V_10 ) ) {
V_110 &= ~ V_232 ;
V_110 |= V_230 & V_232 ;
}
V_110 &= ~ V_233 ;
if ( ( V_230 & V_234 ) == V_235 )
if ( F_54 ( V_12 -> V_10 ) &&
F_10 ( V_29 , V_42 ) )
V_110 |= V_236 ;
else
V_110 |= V_237 ;
else
V_110 |= V_238 ;
F_46 ( V_88 , V_110 | V_167 ) ;
if ( F_39 ( F_5 ( V_88 ) & V_239 , 100 ) )
F_122 ( L_45 , F_42 ( V_4 ) ) ;
}
static void F_151 ( struct V_11 * V_12 ,
enum V_80 V_82 )
{
T_1 V_110 , V_230 ;
F_118 ( ! F_4 ( V_12 -> V_10 ) ) ;
F_148 ( V_12 , (enum V_4 ) V_82 ) ;
F_149 ( V_12 , V_240 ) ;
V_110 = F_5 ( V_241 ) ;
V_110 |= V_231 ;
F_46 ( V_241 , V_110 ) ;
V_110 = V_167 ;
V_230 = F_5 ( F_52 ( V_82 ) ) ;
if ( ( V_230 & V_242 ) ==
V_235 )
V_110 |= V_237 ;
else
V_110 |= V_238 ;
F_46 ( V_243 , V_110 ) ;
if ( F_39 ( F_5 ( V_243 ) & V_239 , 100 ) )
F_122 ( L_46 ) ;
}
static void F_152 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_88 , V_110 ;
F_153 ( V_12 , V_4 ) ;
F_154 ( V_12 , V_4 ) ;
F_113 ( V_12 , V_4 ) ;
V_88 = F_98 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_110 &= ~ V_167 ;
F_46 ( V_88 , V_110 ) ;
if ( F_39 ( ( F_5 ( V_88 ) & V_239 ) == 0 , 50 ) )
F_122 ( L_47 , F_42 ( V_4 ) ) ;
if ( ! F_54 ( V_10 ) ) {
V_88 = F_150 ( V_4 ) ;
V_110 = F_5 ( V_88 ) ;
V_110 &= ~ V_231 ;
F_46 ( V_88 , V_110 ) ;
}
}
static void F_155 ( struct V_11 * V_12 )
{
T_1 V_110 ;
V_110 = F_5 ( V_243 ) ;
V_110 &= ~ V_167 ;
F_46 ( V_243 , V_110 ) ;
if ( F_39 ( ( F_5 ( V_243 ) & V_239 ) == 0 , 50 ) )
F_122 ( L_48 ) ;
V_110 = F_5 ( V_241 ) ;
V_110 &= ~ V_231 ;
F_46 ( V_241 , V_110 ) ;
}
static void F_156 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
enum V_80 V_82 = F_36 ( V_12 ,
V_4 ) ;
enum V_4 V_244 ;
int V_88 ;
T_1 V_110 ;
F_84 ( V_12 , V_4 ) ;
F_157 ( V_12 , V_4 ) ;
F_86 ( V_12 , V_4 ) ;
if ( F_158 ( V_12 -> V_10 ) )
V_244 = V_240 ;
else
V_244 = V_4 ;
if ( ! F_4 ( V_12 -> V_10 ) )
if ( F_10 ( & V_29 -> V_8 , V_245 ) )
F_159 ( V_12 ) ;
else
F_160 ( V_12 , V_4 ) ;
else {
if ( V_29 -> V_77 . V_246 ) {
F_161 ( V_12 , V_244 ) ;
F_70 ( V_12 ,
(enum V_4 ) V_82 ) ;
}
}
V_88 = F_52 ( V_82 ) ;
V_110 = F_5 ( V_88 ) ;
if ( V_110 & V_152 ) {
F_3 ( ! ( ( V_4 == V_131 && V_12 -> V_149 & V_150 ) ||
( V_4 == V_140 && V_12 -> V_149 & V_151 ) ) ) ;
return;
}
F_46 ( V_88 , V_110 | V_152 ) ;
F_120 ( V_88 ) ;
}
static void F_162 ( struct V_73 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
enum V_80 V_82 = V_29 -> V_77 . V_82 ;
enum V_4 V_4 = V_29 -> V_4 ;
int V_88 ;
T_1 V_110 ;
F_84 ( V_12 , V_4 ) ;
F_157 ( V_12 , V_4 ) ;
F_86 ( V_12 , V_4 ) ;
V_88 = F_52 ( V_82 ) ;
V_110 = F_5 ( V_88 ) ;
if ( ( V_110 & V_152 ) == 0 )
return;
if ( V_29 -> V_77 . V_247 )
V_110 &= ~ V_248 ;
if ( ! ( V_4 == V_131 && V_12 -> V_149 & V_150 ) &&
! ( V_4 == V_140 && V_12 -> V_149 & V_151 ) )
V_110 &= ~ V_152 ;
F_46 ( V_88 , V_110 ) ;
if ( ( V_110 & V_152 ) == 0 )
F_51 ( V_29 ) ;
}
void F_163 ( struct V_11 * V_12 ,
enum V_153 V_153 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_1 V_88 = F_45 ( V_10 ) -> V_86 >= 4 ? F_164 ( V_153 ) : F_165 ( V_153 ) ;
F_46 ( V_88 , F_5 ( V_88 ) ) ;
F_120 ( V_88 ) ;
}
static void F_166 ( struct V_249 * V_153 ,
struct V_28 * V_29 )
{
struct V_9 * V_10 = V_153 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
F_167 ( V_12 , V_73 -> V_4 ) ;
if ( V_73 -> V_250 )
return;
V_73 -> V_250 = true ;
V_12 -> V_251 . V_252 ( V_29 , V_153 -> V_76 ,
V_29 -> V_253 , V_29 -> V_254 ) ;
if ( F_168 ( V_10 ) )
F_43 ( V_10 , V_73 -> V_4 ) ;
}
static void F_169 ( struct V_249 * V_153 ,
struct V_28 * V_29 )
{
struct V_9 * V_10 = V_153 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
F_167 ( V_12 , V_73 -> V_4 ) ;
if ( ! V_73 -> V_250 )
return;
V_73 -> V_250 = false ;
V_12 -> V_251 . V_252 ( V_29 , V_153 -> V_76 ,
V_29 -> V_253 , V_29 -> V_254 ) ;
}
static bool F_170 ( struct V_9 * V_10 )
{
#ifdef F_171
if ( F_45 ( V_10 ) -> V_86 >= 6 && V_255 )
return true ;
#endif
return false ;
}
static int F_172 ( struct V_9 * V_10 , int V_256 , bool V_257 )
{
int V_258 ;
V_258 = V_257 ? ( F_20 ( V_10 ) ? 16 : 8 ) : 1 ;
return F_173 ( V_256 , V_258 ) ;
}
int
F_174 ( struct V_9 * V_10 ,
struct V_259 * V_260 ,
struct V_261 * V_262 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_263 ;
int V_264 ;
F_3 ( ! F_175 ( & V_10 -> V_265 ) ) ;
switch ( V_260 -> V_266 ) {
case V_267 :
if ( F_176 ( V_10 ) || F_177 ( V_10 ) )
V_263 = 128 * 1024 ;
else if ( F_45 ( V_10 ) -> V_86 >= 4 )
V_263 = 4 * 1024 ;
else
V_263 = 64 * 1024 ;
break;
case V_268 :
V_263 = 0 ;
break;
case V_269 :
F_41 ( 1 , L_49 ) ;
return - V_270 ;
default:
F_137 () ;
}
if ( F_170 ( V_10 ) && V_263 < 256 * 1024 )
V_263 = 256 * 1024 ;
F_178 ( V_12 ) ;
V_12 -> V_271 . V_272 = false ;
V_264 = F_179 ( V_260 , V_263 , V_262 ) ;
if ( V_264 )
goto V_273;
V_264 = F_180 ( V_260 ) ;
if ( V_264 )
goto V_274;
F_181 ( V_260 ) ;
V_12 -> V_271 . V_272 = true ;
F_182 ( V_12 ) ;
return 0 ;
V_274:
F_183 ( V_260 ) ;
V_273:
V_12 -> V_271 . V_272 = true ;
F_182 ( V_12 ) ;
return V_264 ;
}
void F_184 ( struct V_259 * V_260 )
{
F_3 ( ! F_175 ( & V_260 -> V_8 . V_10 -> V_265 ) ) ;
F_185 ( V_260 ) ;
F_183 ( V_260 ) ;
}
unsigned long F_186 ( int * V_253 , int * V_254 ,
unsigned int V_266 ,
unsigned int V_275 ,
unsigned int V_276 )
{
if ( V_266 != V_267 ) {
unsigned int V_277 , V_278 ;
V_277 = * V_254 / 8 ;
* V_254 %= 8 ;
V_278 = * V_253 / ( 512 / V_275 ) ;
* V_253 %= 512 / V_275 ;
return V_277 * V_276 * 8 + V_278 * 4096 ;
} else {
unsigned int V_279 ;
V_279 = * V_254 * V_276 + * V_253 * V_275 ;
* V_254 = 0 ;
* V_253 = ( V_279 & 4095 ) / V_275 ;
return V_279 & - 4096 ;
}
}
int F_187 ( int V_280 )
{
switch ( V_280 ) {
case V_281 :
return V_282 ;
case V_283 :
return V_284 ;
case V_285 :
return V_286 ;
default:
case V_287 :
return V_288 ;
case V_289 :
return V_290 ;
case V_291 :
return V_292 ;
case V_293 :
return V_294 ;
}
}
static bool F_188 ( struct V_73 * V_29 ,
struct V_295 * V_296 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_259 * V_260 = NULL ;
struct V_297 V_298 = { 0 } ;
T_1 V_8 = V_296 -> V_8 ;
if ( V_296 -> V_299 == 0 )
return false ;
V_260 = F_189 ( V_10 , V_8 , V_8 ,
V_296 -> V_299 ) ;
if ( ! V_260 )
return false ;
if ( V_296 -> V_257 ) {
V_260 -> V_266 = V_268 ;
V_260 -> V_300 = V_29 -> V_8 . V_75 -> V_76 -> V_301 [ 0 ] ;
}
V_298 . V_302 = V_29 -> V_8 . V_75 -> V_76 -> V_302 ;
V_298 . V_303 = V_29 -> V_8 . V_75 -> V_76 -> V_303 ;
V_298 . V_256 = V_29 -> V_8 . V_75 -> V_76 -> V_256 ;
V_298 . V_301 [ 0 ] = V_29 -> V_8 . V_75 -> V_76 -> V_301 [ 0 ] ;
F_59 ( & V_10 -> V_265 ) ;
if ( F_190 ( V_10 , F_191 ( V_29 -> V_8 . V_75 -> V_76 ) ,
& V_298 , V_260 ) ) {
F_47 ( L_50 ) ;
goto V_304;
}
V_260 -> V_305 = F_192 ( V_29 -> V_4 ) ;
F_61 ( & V_10 -> V_265 ) ;
F_47 ( L_51 , V_260 ) ;
return true ;
V_304:
F_193 ( & V_260 -> V_8 ) ;
F_61 ( & V_10 -> V_265 ) ;
return false ;
}
static void F_194 ( struct V_73 * V_73 ,
struct V_295 * V_296 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_28 * V_306 ;
struct V_73 * V_155 ;
struct V_259 * V_260 ;
if ( ! V_73 -> V_8 . V_75 -> V_76 )
return;
if ( F_188 ( V_73 , V_296 ) )
return;
F_195 ( V_73 -> V_8 . V_75 -> V_76 ) ;
V_73 -> V_8 . V_75 -> V_76 = NULL ;
F_196 (dev, c) {
V_155 = F_35 ( V_306 ) ;
if ( V_306 == & V_73 -> V_8 )
continue;
if ( ! V_155 -> V_74 )
continue;
V_260 = F_197 ( V_306 -> V_75 -> V_76 ) ;
if ( V_260 == NULL )
continue;
if ( F_198 ( V_260 ) == V_296 -> V_8 ) {
F_199 ( V_306 -> V_75 -> V_76 ) ;
V_73 -> V_8 . V_75 -> V_76 = V_306 -> V_75 -> V_76 ;
V_260 -> V_305 |= F_192 ( V_73 -> V_4 ) ;
break;
}
}
}
static void F_200 ( struct V_28 * V_29 ,
struct V_307 * V_76 ,
int V_253 , int V_254 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_259 * V_260 ;
int V_153 = V_73 -> V_153 ;
unsigned long V_308 ;
T_1 V_309 ;
T_1 V_88 = F_82 ( V_153 ) ;
int V_310 ;
if ( ! V_73 -> V_250 ) {
F_46 ( V_88 , 0 ) ;
if ( F_45 ( V_10 ) -> V_86 >= 4 )
F_46 ( F_164 ( V_153 ) , 0 ) ;
else
F_46 ( F_165 ( V_153 ) , 0 ) ;
F_120 ( V_88 ) ;
return;
}
V_260 = F_197 ( V_76 ) ;
if ( F_3 ( V_260 == NULL ) )
return;
V_310 = F_201 ( V_76 -> V_302 , 0 ) ;
V_309 = V_311 ;
V_309 |= V_154 ;
if ( F_45 ( V_10 ) -> V_86 < 4 ) {
if ( V_73 -> V_4 == V_140 )
V_309 |= V_312 ;
F_46 ( F_202 ( V_153 ) ,
( ( V_73 -> V_77 . V_313 - 1 ) << 16 ) |
( V_73 -> V_77 . V_314 - 1 ) ) ;
F_46 ( F_203 ( V_153 ) , 0 ) ;
}
switch ( V_76 -> V_302 ) {
case V_282 :
V_309 |= V_281 ;
break;
case V_284 :
case V_315 :
V_309 |= V_283 ;
break;
case V_286 :
V_309 |= V_285 ;
break;
case V_288 :
case V_316 :
V_309 |= V_287 ;
break;
case V_290 :
case V_317 :
V_309 |= V_289 ;
break;
case V_292 :
case V_318 :
V_309 |= V_291 ;
break;
case V_294 :
case V_319 :
V_309 |= V_293 ;
break;
default:
F_137 () ;
}
if ( F_45 ( V_10 ) -> V_86 >= 4 &&
V_260 -> V_266 != V_267 )
V_309 |= V_320 ;
if ( F_16 ( V_10 ) )
V_309 |= V_321 ;
V_308 = V_254 * V_76 -> V_301 [ 0 ] + V_253 * V_310 ;
if ( F_45 ( V_10 ) -> V_86 >= 4 ) {
V_73 -> V_322 =
F_186 ( & V_253 , & V_254 , V_260 -> V_266 ,
V_310 ,
V_76 -> V_301 [ 0 ] ) ;
V_308 -= V_73 -> V_322 ;
} else {
V_73 -> V_322 = V_308 ;
}
if ( F_204 ( V_29 -> V_75 ) -> V_323 == F_205 ( V_324 ) ) {
V_309 |= V_325 ;
V_253 += ( V_73 -> V_77 . V_314 - 1 ) ;
V_254 += ( V_73 -> V_77 . V_313 - 1 ) ;
V_308 +=
( V_73 -> V_77 . V_313 - 1 ) * V_76 -> V_301 [ 0 ] +
( V_73 -> V_77 . V_314 - 1 ) * V_310 ;
}
F_46 ( V_88 , V_309 ) ;
F_47 ( L_52 ,
F_198 ( V_260 ) , V_308 , V_253 , V_254 ,
V_76 -> V_301 [ 0 ] ) ;
F_46 ( F_206 ( V_153 ) , V_76 -> V_301 [ 0 ] ) ;
if ( F_45 ( V_10 ) -> V_86 >= 4 ) {
F_46 ( F_164 ( V_153 ) ,
F_198 ( V_260 ) + V_73 -> V_322 ) ;
F_46 ( F_207 ( V_153 ) , ( V_254 << 16 ) | V_253 ) ;
F_46 ( F_208 ( V_153 ) , V_308 ) ;
} else
F_46 ( F_165 ( V_153 ) , F_198 ( V_260 ) + V_308 ) ;
F_120 ( V_88 ) ;
}
static void F_209 ( struct V_28 * V_29 ,
struct V_307 * V_76 ,
int V_253 , int V_254 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_259 * V_260 ;
int V_153 = V_73 -> V_153 ;
unsigned long V_308 ;
T_1 V_309 ;
T_1 V_88 = F_82 ( V_153 ) ;
int V_310 ;
if ( ! V_73 -> V_250 ) {
F_46 ( V_88 , 0 ) ;
F_46 ( F_164 ( V_153 ) , 0 ) ;
F_120 ( V_88 ) ;
return;
}
V_260 = F_197 ( V_76 ) ;
if ( F_3 ( V_260 == NULL ) )
return;
V_310 = F_201 ( V_76 -> V_302 , 0 ) ;
V_309 = V_311 ;
V_309 |= V_154 ;
if ( F_210 ( V_10 ) || F_168 ( V_10 ) )
V_309 |= V_326 ;
switch ( V_76 -> V_302 ) {
case V_282 :
V_309 |= V_281 ;
break;
case V_286 :
V_309 |= V_285 ;
break;
case V_288 :
case V_316 :
V_309 |= V_287 ;
break;
case V_290 :
case V_317 :
V_309 |= V_289 ;
break;
case V_292 :
case V_318 :
V_309 |= V_291 ;
break;
case V_294 :
case V_319 :
V_309 |= V_293 ;
break;
default:
F_137 () ;
}
if ( V_260 -> V_266 != V_267 )
V_309 |= V_320 ;
if ( ! F_210 ( V_10 ) && ! F_168 ( V_10 ) )
V_309 |= V_321 ;
V_308 = V_254 * V_76 -> V_301 [ 0 ] + V_253 * V_310 ;
V_73 -> V_322 =
F_186 ( & V_253 , & V_254 , V_260 -> V_266 ,
V_310 ,
V_76 -> V_301 [ 0 ] ) ;
V_308 -= V_73 -> V_322 ;
if ( F_204 ( V_29 -> V_75 ) -> V_323 == F_205 ( V_324 ) ) {
V_309 |= V_325 ;
if ( ! F_210 ( V_10 ) && ! F_168 ( V_10 ) ) {
V_253 += ( V_73 -> V_77 . V_314 - 1 ) ;
V_254 += ( V_73 -> V_77 . V_313 - 1 ) ;
V_308 +=
( V_73 -> V_77 . V_313 - 1 ) * V_76 -> V_301 [ 0 ] +
( V_73 -> V_77 . V_314 - 1 ) * V_310 ;
}
}
F_46 ( V_88 , V_309 ) ;
F_47 ( L_52 ,
F_198 ( V_260 ) , V_308 , V_253 , V_254 ,
V_76 -> V_301 [ 0 ] ) ;
F_46 ( F_206 ( V_153 ) , V_76 -> V_301 [ 0 ] ) ;
F_46 ( F_164 ( V_153 ) ,
F_198 ( V_260 ) + V_73 -> V_322 ) ;
if ( F_210 ( V_10 ) || F_168 ( V_10 ) ) {
F_46 ( F_211 ( V_153 ) , ( V_254 << 16 ) | V_253 ) ;
} else {
F_46 ( F_207 ( V_153 ) , ( V_254 << 16 ) | V_253 ) ;
F_46 ( F_208 ( V_153 ) , V_308 ) ;
}
F_120 ( V_88 ) ;
}
static int
F_212 ( struct V_28 * V_29 , struct V_307 * V_76 ,
int V_253 , int V_254 , enum V_327 V_109 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_12 -> V_251 . V_328 )
V_12 -> V_251 . V_328 ( V_10 ) ;
F_213 ( V_10 , F_35 ( V_29 ) -> V_4 ) ;
V_12 -> V_251 . V_252 ( V_29 , V_76 , V_253 , V_254 ) ;
return 0 ;
}
void F_214 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 ;
F_196 (dev, crtc) {
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_153 V_153 = V_73 -> V_153 ;
F_215 ( V_10 , V_153 ) ;
F_216 ( V_10 , V_153 ) ;
}
F_196 (dev, crtc) {
struct V_73 * V_73 = F_35 ( V_29 ) ;
F_217 ( & V_29 -> V_329 , NULL ) ;
if ( V_73 -> V_74 && V_29 -> V_75 -> V_76 )
V_12 -> V_251 . V_252 ( V_29 ,
V_29 -> V_75 -> V_76 ,
V_29 -> V_253 ,
V_29 -> V_254 ) ;
F_218 ( & V_29 -> V_329 ) ;
}
}
static int
F_219 ( struct V_307 * V_330 )
{
struct V_259 * V_260 = F_197 ( V_330 ) ;
struct V_11 * V_12 = V_260 -> V_8 . V_10 -> V_13 ;
bool V_331 = V_12 -> V_271 . V_272 ;
int V_264 ;
V_12 -> V_271 . V_272 = false ;
V_264 = F_220 ( V_260 ) ;
V_12 -> V_271 . V_272 = V_331 ;
return V_264 ;
}
static bool F_221 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
unsigned long V_332 ;
bool V_333 ;
if ( F_222 ( & V_12 -> V_334 ) ||
V_73 -> V_335 != F_223 ( & V_12 -> V_334 . V_335 ) )
return false ;
F_224 ( & V_10 -> V_336 , V_332 ) ;
V_333 = F_35 ( V_29 ) -> V_337 != NULL ;
F_225 ( & V_10 -> V_336 , V_332 ) ;
return V_333 ;
}
static int
F_226 ( struct V_28 * V_29 , int V_253 , int V_254 ,
struct V_307 * V_76 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_4 V_4 = V_73 -> V_4 ;
struct V_307 * V_330 = V_29 -> V_75 -> V_76 ;
struct V_259 * V_260 = F_197 ( V_76 ) ;
struct V_259 * V_338 = F_197 ( V_330 ) ;
int V_264 ;
if ( F_221 ( V_29 ) ) {
F_122 ( L_53 ) ;
return - V_339 ;
}
if ( ! V_76 ) {
F_122 ( L_54 ) ;
return 0 ;
}
if ( V_73 -> V_153 > F_45 ( V_10 ) -> V_340 ) {
F_122 ( L_55 ,
F_83 ( V_73 -> V_153 ) ,
F_45 ( V_10 ) -> V_340 ) ;
return - V_270 ;
}
F_59 ( & V_10 -> V_265 ) ;
V_264 = F_174 ( V_10 , V_260 , NULL ) ;
if ( V_264 == 0 )
F_227 ( V_338 , V_260 ,
F_192 ( V_4 ) ) ;
F_61 ( & V_10 -> V_265 ) ;
if ( V_264 != 0 ) {
F_122 ( L_56 ) ;
return V_264 ;
}
if ( V_341 . V_342 ) {
const struct V_343 * V_78 =
& V_73 -> V_77 . V_78 ;
F_46 ( F_228 ( V_73 -> V_4 ) ,
( ( V_78 -> V_344 - 1 ) << 16 ) |
( V_78 -> V_345 - 1 ) ) ;
if ( ! V_73 -> V_77 . V_346 . V_108 &&
( F_10 ( V_29 , V_31 ) ||
F_10 ( V_29 , V_347 ) ) ) {
F_46 ( F_229 ( V_73 -> V_4 ) , 0 ) ;
F_46 ( F_230 ( V_73 -> V_4 ) , 0 ) ;
F_46 ( F_231 ( V_73 -> V_4 ) , 0 ) ;
}
V_73 -> V_77 . V_314 = V_78 -> V_344 ;
V_73 -> V_77 . V_313 = V_78 -> V_345 ;
}
V_12 -> V_251 . V_252 ( V_29 , V_76 , V_253 , V_254 ) ;
if ( V_73 -> V_74 )
F_232 ( V_10 , F_192 ( V_4 ) ) ;
V_29 -> V_75 -> V_76 = V_76 ;
V_29 -> V_253 = V_253 ;
V_29 -> V_254 = V_254 ;
if ( V_330 ) {
if ( V_73 -> V_74 && V_330 != V_76 )
F_43 ( V_10 , V_73 -> V_4 ) ;
F_59 ( & V_10 -> V_265 ) ;
F_184 ( V_338 ) ;
F_61 ( & V_10 -> V_265 ) ;
}
F_59 ( & V_10 -> V_265 ) ;
F_233 ( V_10 ) ;
F_61 ( & V_10 -> V_265 ) ;
return 0 ;
}
static void F_234 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_348 ;
V_88 = F_67 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
if ( F_235 ( V_10 ) ) {
V_348 &= ~ V_349 ;
V_348 |= V_349 | V_350 ;
} else {
V_348 &= ~ V_351 ;
V_348 |= V_351 | V_350 ;
}
F_46 ( V_88 , V_348 ) ;
V_88 = F_69 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
if ( F_96 ( V_10 ) ) {
V_348 &= ~ V_352 ;
V_348 |= V_353 ;
} else {
V_348 &= ~ V_351 ;
V_348 |= V_351 ;
}
F_46 ( V_88 , V_348 | V_354 ) ;
F_120 ( V_88 ) ;
F_121 ( 1000 ) ;
if ( F_235 ( V_10 ) )
F_46 ( V_88 , F_5 ( V_88 ) | V_355 |
V_356 ) ;
}
static bool F_236 ( struct V_73 * V_29 )
{
return V_29 -> V_8 . V_108 && V_29 -> V_74 &&
V_29 -> V_77 . V_246 ;
}
static void F_237 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_357 =
F_35 ( V_12 -> V_81 [ V_140 ] ) ;
struct V_73 * V_358 =
F_35 ( V_12 -> V_81 [ V_359 ] ) ;
T_4 V_348 ;
if ( ! F_236 ( V_357 ) &&
! F_236 ( V_358 ) ) {
F_3 ( F_5 ( F_69 ( V_140 ) ) & V_126 ) ;
F_3 ( F_5 ( F_69 ( V_359 ) ) & V_126 ) ;
V_348 = F_5 ( V_360 ) ;
V_348 &= ~ V_361 ;
F_47 ( L_57 ) ;
F_46 ( V_360 , V_348 ) ;
}
}
static void F_238 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_348 , V_362 ;
F_167 ( V_12 , V_4 ) ;
V_88 = F_239 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_363 ;
V_348 &= ~ V_364 ;
F_46 ( V_88 , V_348 ) ;
F_5 ( V_88 ) ;
F_121 ( 150 ) ;
V_88 = F_67 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_365 ;
V_348 |= F_240 ( V_73 -> V_77 . V_366 ) ;
V_348 &= ~ V_351 ;
V_348 |= V_367 ;
F_46 ( V_88 , V_348 | V_125 ) ;
V_88 = F_69 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_351 ;
V_348 |= V_367 ;
F_46 ( V_88 , V_348 | V_126 ) ;
F_120 ( V_88 ) ;
F_121 ( 150 ) ;
F_46 ( F_241 ( V_4 ) , V_368 ) ;
F_46 ( F_241 ( V_4 ) , V_368 |
V_369 ) ;
V_88 = F_242 ( V_4 ) ;
for ( V_362 = 0 ; V_362 < 5 ; V_362 ++ ) {
V_348 = F_5 ( V_88 ) ;
F_47 ( L_58 , V_348 ) ;
if ( ( V_348 & V_364 ) ) {
F_47 ( L_59 ) ;
F_46 ( V_88 , V_348 | V_364 ) ;
break;
}
}
if ( V_362 == 5 )
F_122 ( L_60 ) ;
V_88 = F_67 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_351 ;
V_348 |= V_370 ;
F_46 ( V_88 , V_348 ) ;
V_88 = F_69 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_351 ;
V_348 |= V_370 ;
F_46 ( V_88 , V_348 ) ;
F_120 ( V_88 ) ;
F_121 ( 150 ) ;
V_88 = F_242 ( V_4 ) ;
for ( V_362 = 0 ; V_362 < 5 ; V_362 ++ ) {
V_348 = F_5 ( V_88 ) ;
F_47 ( L_58 , V_348 ) ;
if ( V_348 & V_363 ) {
F_46 ( V_88 , V_348 | V_363 ) ;
F_47 ( L_61 ) ;
break;
}
}
if ( V_362 == 5 )
F_122 ( L_62 ) ;
F_47 ( L_63 ) ;
}
static void F_243 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_348 , V_155 , V_371 ;
V_88 = F_239 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_363 ;
V_348 &= ~ V_364 ;
F_46 ( V_88 , V_348 ) ;
F_120 ( V_88 ) ;
F_121 ( 150 ) ;
V_88 = F_67 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_365 ;
V_348 |= F_240 ( V_73 -> V_77 . V_366 ) ;
V_348 &= ~ V_351 ;
V_348 |= V_367 ;
V_348 &= ~ V_372 ;
V_348 |= V_373 ;
F_46 ( V_88 , V_348 | V_125 ) ;
F_46 ( F_244 ( V_4 ) ,
V_374 | V_375 ) ;
V_88 = F_69 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
if ( F_96 ( V_10 ) ) {
V_348 &= ~ V_352 ;
V_348 |= V_376 ;
} else {
V_348 &= ~ V_351 ;
V_348 |= V_367 ;
}
F_46 ( V_88 , V_348 | V_126 ) ;
F_120 ( V_88 ) ;
F_121 ( 150 ) ;
for ( V_155 = 0 ; V_155 < 4 ; V_155 ++ ) {
V_88 = F_67 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_372 ;
V_348 |= V_377 [ V_155 ] ;
F_46 ( V_88 , V_348 ) ;
F_120 ( V_88 ) ;
F_121 ( 500 ) ;
for ( V_371 = 0 ; V_371 < 5 ; V_371 ++ ) {
V_88 = F_242 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
F_47 ( L_58 , V_348 ) ;
if ( V_348 & V_364 ) {
F_46 ( V_88 , V_348 | V_364 ) ;
F_47 ( L_59 ) ;
break;
}
F_121 ( 50 ) ;
}
if ( V_371 < 5 )
break;
}
if ( V_155 == 4 )
F_122 ( L_60 ) ;
V_88 = F_67 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_351 ;
V_348 |= V_370 ;
if ( F_245 ( V_10 ) ) {
V_348 &= ~ V_372 ;
V_348 |= V_373 ;
}
F_46 ( V_88 , V_348 ) ;
V_88 = F_69 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
if ( F_96 ( V_10 ) ) {
V_348 &= ~ V_352 ;
V_348 |= V_378 ;
} else {
V_348 &= ~ V_351 ;
V_348 |= V_370 ;
}
F_46 ( V_88 , V_348 ) ;
F_120 ( V_88 ) ;
F_121 ( 150 ) ;
for ( V_155 = 0 ; V_155 < 4 ; V_155 ++ ) {
V_88 = F_67 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_372 ;
V_348 |= V_377 [ V_155 ] ;
F_46 ( V_88 , V_348 ) ;
F_120 ( V_88 ) ;
F_121 ( 500 ) ;
for ( V_371 = 0 ; V_371 < 5 ; V_371 ++ ) {
V_88 = F_242 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
F_47 ( L_58 , V_348 ) ;
if ( V_348 & V_363 ) {
F_46 ( V_88 , V_348 | V_363 ) ;
F_47 ( L_61 ) ;
break;
}
F_121 ( 50 ) ;
}
if ( V_371 < 5 )
break;
}
if ( V_155 == 4 )
F_122 ( L_62 ) ;
F_47 ( L_64 ) ;
}
static void F_246 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_348 , V_155 , V_379 ;
V_88 = F_239 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_363 ;
V_348 &= ~ V_364 ;
F_46 ( V_88 , V_348 ) ;
F_120 ( V_88 ) ;
F_121 ( 150 ) ;
F_47 ( L_65 ,
F_5 ( F_242 ( V_4 ) ) ) ;
for ( V_379 = 0 ; V_379 < F_247 ( V_377 ) * 2 ; V_379 ++ ) {
V_88 = F_67 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ ( V_380 | V_349 ) ;
V_348 &= ~ V_125 ;
F_46 ( V_88 , V_348 ) ;
V_88 = F_69 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_380 ;
V_348 &= ~ V_352 ;
V_348 &= ~ V_126 ;
F_46 ( V_88 , V_348 ) ;
V_88 = F_67 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_365 ;
V_348 |= F_240 ( V_73 -> V_77 . V_366 ) ;
V_348 |= V_381 ;
V_348 &= ~ V_372 ;
V_348 |= V_377 [ V_379 / 2 ] ;
V_348 |= V_382 ;
F_46 ( V_88 , V_348 | V_125 ) ;
F_46 ( F_244 ( V_4 ) ,
V_374 | V_375 ) ;
V_88 = F_69 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 |= V_376 ;
V_348 |= V_382 ;
F_46 ( V_88 , V_348 | V_126 ) ;
F_120 ( V_88 ) ;
F_121 ( 1 ) ;
for ( V_155 = 0 ; V_155 < 4 ; V_155 ++ ) {
V_88 = F_242 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
F_47 ( L_58 , V_348 ) ;
if ( V_348 & V_364 ||
( F_5 ( V_88 ) & V_364 ) ) {
F_46 ( V_88 , V_348 | V_364 ) ;
F_47 ( L_66 ,
V_155 ) ;
break;
}
F_121 ( 1 ) ;
}
if ( V_155 == 4 ) {
F_47 ( L_67 , V_379 / 2 ) ;
continue;
}
V_88 = F_67 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_349 ;
V_348 |= V_383 ;
F_46 ( V_88 , V_348 ) ;
V_88 = F_69 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_352 ;
V_348 |= V_378 ;
F_46 ( V_88 , V_348 ) ;
F_120 ( V_88 ) ;
F_121 ( 2 ) ;
for ( V_155 = 0 ; V_155 < 4 ; V_155 ++ ) {
V_88 = F_242 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
F_47 ( L_58 , V_348 ) ;
if ( V_348 & V_363 ||
( F_5 ( V_88 ) & V_363 ) ) {
F_46 ( V_88 , V_348 | V_363 ) ;
F_47 ( L_68 ,
V_155 ) ;
goto V_384;
}
F_121 ( 2 ) ;
}
if ( V_155 == 4 )
F_47 ( L_69 , V_379 / 2 ) ;
}
V_384:
F_47 ( L_64 ) ;
}
static void F_248 ( struct V_73 * V_73 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_348 ;
V_88 = F_69 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ ( V_365 | ( 0x7 << 16 ) ) ;
V_348 |= F_240 ( V_73 -> V_77 . V_366 ) ;
V_348 |= ( F_5 ( F_52 ( V_4 ) ) & V_232 ) << 11 ;
F_46 ( V_88 , V_348 | V_128 ) ;
F_120 ( V_88 ) ;
F_121 ( 200 ) ;
V_348 = F_5 ( V_88 ) ;
F_46 ( V_88 , V_348 | V_385 ) ;
F_120 ( V_88 ) ;
F_121 ( 200 ) ;
V_88 = F_67 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
if ( ( V_348 & V_127 ) == 0 ) {
F_46 ( V_88 , V_348 | V_127 ) ;
F_120 ( V_88 ) ;
F_121 ( 100 ) ;
}
}
static void F_249 ( struct V_73 * V_73 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_348 ;
V_88 = F_69 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
F_46 ( V_88 , V_348 & ~ V_385 ) ;
V_88 = F_67 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
F_46 ( V_88 , V_348 & ~ V_127 ) ;
F_120 ( V_88 ) ;
F_121 ( 100 ) ;
V_88 = F_69 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
F_46 ( V_88 , V_348 & ~ V_128 ) ;
F_120 ( V_88 ) ;
F_121 ( 100 ) ;
}
static void F_250 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_348 ;
V_88 = F_67 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
F_46 ( V_88 , V_348 & ~ V_125 ) ;
F_120 ( V_88 ) ;
V_88 = F_69 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ ( 0x7 << 16 ) ;
V_348 |= ( F_5 ( F_52 ( V_4 ) ) & V_232 ) << 11 ;
F_46 ( V_88 , V_348 & ~ V_126 ) ;
F_120 ( V_88 ) ;
F_121 ( 100 ) ;
if ( F_54 ( V_10 ) )
F_46 ( F_241 ( V_4 ) , V_368 ) ;
V_88 = F_67 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ V_351 ;
V_348 |= V_367 ;
F_46 ( V_88 , V_348 ) ;
V_88 = F_69 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
if ( F_96 ( V_10 ) ) {
V_348 &= ~ V_352 ;
V_348 |= V_376 ;
} else {
V_348 &= ~ V_351 ;
V_348 |= V_367 ;
}
V_348 &= ~ ( 0x07 << 16 ) ;
V_348 |= ( F_5 ( F_52 ( V_4 ) ) & V_232 ) << 11 ;
F_46 ( V_88 , V_348 ) ;
F_120 ( V_88 ) ;
F_121 ( 100 ) ;
}
bool F_251 ( struct V_9 * V_10 )
{
struct V_73 * V_29 ;
F_130 (dev, crtc) {
if ( F_223 ( & V_29 -> V_386 ) == 0 )
continue;
if ( V_29 -> V_337 )
F_43 ( V_10 , V_29 -> V_4 ) ;
return true ;
}
return false ;
}
static void F_252 ( struct V_73 * V_73 )
{
struct V_11 * V_12 = F_253 ( V_73 -> V_8 . V_10 ) ;
struct V_387 * V_388 = V_73 -> V_337 ;
F_254 () ;
V_73 -> V_337 = NULL ;
if ( V_388 -> V_389 )
F_255 ( V_73 -> V_8 . V_10 ,
V_73 -> V_4 ,
V_388 -> V_389 ) ;
F_94 ( & V_73 -> V_8 ) ;
F_256 ( & V_12 -> V_390 ) ;
F_257 ( V_12 -> V_391 , & V_388 -> V_388 ) ;
F_258 ( V_73 -> V_153 ,
V_388 -> V_392 ) ;
}
void F_259 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_3 ( F_260 ( & V_12 -> V_390 ) ) ;
if ( F_3 ( F_261 ( V_12 -> V_390 ,
! F_221 ( V_29 ) ,
60 * V_393 ) == 0 ) ) {
struct V_73 * V_73 = F_35 ( V_29 ) ;
unsigned long V_332 ;
F_224 ( & V_10 -> V_336 , V_332 ) ;
if ( V_73 -> V_337 ) {
F_262 ( 1 , L_70 ) ;
F_252 ( V_73 ) ;
}
F_225 ( & V_10 -> V_336 , V_332 ) ;
}
if ( V_29 -> V_75 -> V_76 ) {
F_59 ( & V_10 -> V_265 ) ;
F_219 ( V_29 -> V_75 -> V_76 ) ;
F_61 ( & V_10 -> V_265 ) ;
}
}
static void F_263 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int clock = F_35 ( V_29 ) -> V_77 . V_78 . V_79 ;
T_1 V_394 , V_395 , V_396 , V_397 = 0 ;
T_1 V_348 ;
F_59 ( & V_12 -> V_113 ) ;
F_46 ( V_398 , V_399 ) ;
F_264 ( V_12 , V_400 ,
F_265 ( V_12 , V_400 , V_401 ) |
V_402 ,
V_401 ) ;
if ( clock == 20000 ) {
V_396 = 1 ;
V_394 = 0x41 ;
V_395 = 0x20 ;
} else {
T_1 V_403 = 172800 * 1000 ;
T_1 V_404 = 64 ;
T_1 V_405 , V_406 , V_407 ;
V_405 = ( V_403 / clock ) ;
V_406 = V_405 / V_404 ;
V_407 = V_405 % V_404 ;
V_396 = 0 ;
V_394 = V_406 - 2 ;
V_395 = V_407 ;
}
F_3 ( F_266 ( V_394 ) &
~ V_408 ) ;
F_3 ( F_267 ( V_397 ) &
~ V_409 ) ;
F_47 ( L_71 ,
clock ,
V_396 ,
V_394 ,
V_397 ,
V_395 ) ;
V_348 = F_265 ( V_12 , V_410 , V_401 ) ;
V_348 &= ~ V_408 ;
V_348 |= F_266 ( V_394 ) ;
V_348 &= ~ V_409 ;
V_348 |= F_268 ( V_395 ) ;
V_348 |= F_267 ( V_397 ) ;
V_348 |= V_411 ;
F_264 ( V_12 , V_410 , V_348 , V_401 ) ;
V_348 = F_265 ( V_12 , V_412 , V_401 ) ;
V_348 &= ~ F_269 ( 1 ) ;
V_348 |= F_269 ( V_396 ) ;
F_264 ( V_12 , V_412 , V_348 , V_401 ) ;
V_348 = F_265 ( V_12 , V_400 , V_401 ) ;
V_348 &= ~ V_402 ;
F_264 ( V_12 , V_400 , V_348 , V_401 ) ;
F_121 ( 24 ) ;
F_46 ( V_398 , V_413 ) ;
F_61 ( & V_12 -> V_113 ) ;
}
static void F_270 ( struct V_73 * V_29 ,
enum V_4 V_244 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_80 V_82 = V_29 -> V_77 . V_82 ;
F_46 ( F_271 ( V_244 ) ,
F_5 ( F_272 ( V_82 ) ) ) ;
F_46 ( F_273 ( V_244 ) ,
F_5 ( F_274 ( V_82 ) ) ) ;
F_46 ( F_275 ( V_244 ) ,
F_5 ( F_276 ( V_82 ) ) ) ;
F_46 ( F_277 ( V_244 ) ,
F_5 ( F_278 ( V_82 ) ) ) ;
F_46 ( F_279 ( V_244 ) ,
F_5 ( F_280 ( V_82 ) ) ) ;
F_46 ( F_281 ( V_244 ) ,
F_5 ( F_282 ( V_82 ) ) ) ;
F_46 ( F_283 ( V_244 ) ,
F_5 ( F_284 ( V_82 ) ) ) ;
}
static void F_285 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_348 ;
V_348 = F_5 ( V_360 ) ;
if ( V_348 & V_361 )
return;
F_3 ( F_5 ( F_69 ( V_140 ) ) & V_126 ) ;
F_3 ( F_5 ( F_69 ( V_359 ) ) & V_126 ) ;
V_348 |= V_361 ;
F_47 ( L_72 ) ;
F_46 ( V_360 , V_348 ) ;
F_120 ( V_360 ) ;
}
static void F_286 ( struct V_73 * V_73 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
switch ( V_73 -> V_4 ) {
case V_131 :
break;
case V_140 :
if ( V_73 -> V_77 . V_366 > 2 )
F_3 ( F_5 ( V_360 ) & V_361 ) ;
else
F_285 ( V_10 ) ;
break;
case V_359 :
F_285 ( V_10 ) ;
break;
default:
F_137 () ;
}
}
static void F_287 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_348 ;
F_97 ( V_12 , V_4 ) ;
if ( F_235 ( V_10 ) )
F_286 ( V_73 ) ;
F_46 ( F_288 ( V_4 ) ,
F_5 ( F_289 ( V_4 ) ) & V_414 ) ;
V_12 -> V_251 . V_415 ( V_29 ) ;
if ( F_96 ( V_10 ) ) {
T_1 V_416 ;
V_348 = F_5 ( V_417 ) ;
V_348 |= F_290 ( V_4 ) ;
V_416 = F_291 ( V_4 ) ;
if ( V_73 -> V_77 . V_117 == V_418 )
V_348 |= V_416 ;
else
V_348 &= ~ V_416 ;
F_46 ( V_417 , V_348 ) ;
}
F_142 ( V_73 ) ;
F_72 ( V_12 , V_4 ) ;
F_270 ( V_73 , V_4 ) ;
F_234 ( V_29 ) ;
if ( F_96 ( V_10 ) &&
( F_10 ( V_29 , V_419 ) ||
F_10 ( V_29 , V_347 ) ) ) {
T_1 V_420 = ( F_5 ( F_52 ( V_4 ) ) & V_232 ) >> 5 ;
V_88 = F_100 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ ( V_171 |
V_421 |
V_422 ) ;
V_348 |= ( V_423 |
V_424 ) ;
V_348 |= V_420 << 9 ;
if ( V_29 -> V_425 . V_332 & V_426 )
V_348 |= V_427 ;
if ( V_29 -> V_425 . V_332 & V_428 )
V_348 |= V_429 ;
switch ( F_292 ( V_29 ) ) {
case V_185 :
V_348 |= V_186 ;
break;
case V_187 :
V_348 |= V_188 ;
break;
case V_189 :
V_348 |= V_190 ;
break;
default:
F_137 () ;
}
F_46 ( V_88 , V_348 ) ;
}
F_147 ( V_12 , V_4 ) ;
}
static void F_293 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_80 V_82 = V_73 -> V_77 . V_82 ;
F_97 ( V_12 , V_240 ) ;
F_263 ( V_29 ) ;
F_270 ( V_73 , V_131 ) ;
F_151 ( V_12 , V_82 ) ;
}
void F_294 ( struct V_73 * V_29 )
{
struct V_116 * V_119 = F_62 ( V_29 ) ;
if ( V_119 == NULL )
return;
if ( V_119 -> V_223 == 0 ) {
F_41 ( 1 , L_73 , V_119 -> V_123 ) ;
return;
}
if ( -- V_119 -> V_223 == 0 ) {
F_3 ( V_119 -> V_224 ) ;
F_3 ( V_119 -> V_74 ) ;
}
V_29 -> V_77 . V_117 = V_430 ;
}
struct V_116 * F_295 ( struct V_73 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
struct V_116 * V_119 = F_62 ( V_29 ) ;
enum V_431 V_155 ;
if ( V_119 ) {
F_47 ( L_74 ,
V_29 -> V_8 . V_8 . V_226 , V_119 -> V_123 ) ;
F_294 ( V_29 ) ;
}
if ( F_54 ( V_12 -> V_10 ) ) {
V_155 = (enum V_431 ) V_29 -> V_4 ;
V_119 = & V_12 -> V_118 [ V_155 ] ;
F_47 ( L_75 ,
V_29 -> V_8 . V_8 . V_226 , V_119 -> V_123 ) ;
F_3 ( V_119 -> V_223 ) ;
goto V_67;
}
for ( V_155 = 0 ; V_155 < V_12 -> V_432 ; V_155 ++ ) {
V_119 = & V_12 -> V_118 [ V_155 ] ;
if ( V_119 -> V_223 == 0 )
continue;
if ( memcmp ( & V_29 -> V_77 . V_199 , & V_119 -> V_121 ,
sizeof( V_119 -> V_121 ) ) == 0 ) {
F_47 ( L_76 ,
V_29 -> V_8 . V_8 . V_226 ,
V_119 -> V_123 , V_119 -> V_223 , V_119 -> V_74 ) ;
goto V_67;
}
}
for ( V_155 = 0 ; V_155 < V_12 -> V_432 ; V_155 ++ ) {
V_119 = & V_12 -> V_118 [ V_155 ] ;
if ( V_119 -> V_223 == 0 ) {
F_47 ( L_77 ,
V_29 -> V_8 . V_8 . V_226 , V_119 -> V_123 ) ;
goto V_67;
}
}
return NULL ;
V_67:
if ( V_119 -> V_223 == 0 )
V_119 -> V_121 = V_29 -> V_77 . V_199 ;
V_29 -> V_77 . V_117 = V_155 ;
F_140 ( L_78 , V_119 -> V_123 ,
F_42 ( V_29 -> V_4 ) ) ;
V_119 -> V_223 ++ ;
return V_119 ;
}
static void F_296 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_433 = F_49 ( V_4 ) ;
T_1 V_348 ;
V_348 = F_5 ( V_433 ) ;
F_121 ( 500 ) ;
if ( F_39 ( F_5 ( V_433 ) != V_348 , 5 ) ) {
if ( F_39 ( F_5 ( V_433 ) != V_348 , 5 ) )
F_122 ( L_79 , F_42 ( V_4 ) ) ;
}
}
static void F_297 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_77 . V_346 . V_108 ) {
if ( F_235 ( V_10 ) || F_210 ( V_10 ) )
F_46 ( F_229 ( V_4 ) , V_434 | V_435 |
F_298 ( V_4 ) ) ;
else
F_46 ( F_229 ( V_4 ) , V_434 | V_435 ) ;
F_46 ( F_230 ( V_4 ) , V_29 -> V_77 . V_346 . V_436 ) ;
F_46 ( F_231 ( V_4 ) , V_29 -> V_77 . V_346 . V_299 ) ;
}
}
static void F_299 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_4 V_4 = F_35 ( V_29 ) -> V_4 ;
struct V_249 * V_153 ;
struct V_437 * V_437 ;
F_300 (plane, &dev->mode_config.plane_list) {
V_437 = F_204 ( V_153 ) ;
if ( V_437 -> V_4 == V_4 )
F_301 ( & V_437 -> V_8 ) ;
}
}
static void F_302 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_4 V_4 = F_35 ( V_29 ) -> V_4 ;
struct V_249 * V_153 ;
struct V_437 * V_437 ;
F_300 (plane, &dev->mode_config.plane_list) {
V_437 = F_204 ( V_153 ) ;
if ( V_437 -> V_4 == V_4 )
F_303 ( & V_437 -> V_8 ) ;
}
}
void F_304 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_77 . V_438 )
return;
F_43 ( V_10 , V_29 -> V_4 ) ;
F_305 ( V_12 , V_29 -> V_153 ) ;
if ( F_168 ( V_10 ) ) {
F_59 ( & V_12 -> V_439 . V_440 ) ;
F_3 ( F_306 ( V_12 , V_441 , 0xc0000000 ) ) ;
F_61 ( & V_12 -> V_439 . V_440 ) ;
} else {
F_46 ( V_442 , V_443 ) ;
if ( F_39 ( F_40 ( V_442 ) & V_443 , 50 ) )
F_122 ( L_80 ) ;
}
}
void F_307 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_77 . V_438 )
return;
F_305 ( V_12 , V_29 -> V_153 ) ;
if ( F_168 ( V_10 ) ) {
F_59 ( & V_12 -> V_439 . V_440 ) ;
F_3 ( F_306 ( V_12 , V_441 , 0 ) ) ;
F_61 ( & V_12 -> V_439 . V_440 ) ;
if ( F_39 ( ( F_5 ( V_442 ) & V_443 ) == 0 , 42 ) )
F_122 ( L_81 ) ;
} else {
F_46 ( V_442 , 0 ) ;
F_120 ( V_442 ) ;
}
F_43 ( V_10 , V_29 -> V_4 ) ;
}
static void F_308 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_4 V_4 = V_73 -> V_4 ;
int V_444 = F_309 ( V_4 ) ;
int V_155 ;
bool V_445 = false ;
if ( ! V_29 -> V_108 || ! V_73 -> V_74 )
return;
if ( ! F_4 ( V_12 -> V_10 ) ) {
if ( F_10 ( V_29 , V_245 ) )
F_159 ( V_12 ) ;
else
F_160 ( V_12 , V_4 ) ;
}
if ( ! F_310 ( V_10 ) )
V_444 = F_311 ( V_4 ) ;
if ( F_210 ( V_10 ) && V_73 -> V_77 . V_438 &&
( ( F_5 ( F_312 ( V_4 ) ) & V_446 ) ==
V_447 ) ) {
F_307 ( V_73 ) ;
V_445 = true ;
}
for ( V_155 = 0 ; V_155 < 256 ; V_155 ++ ) {
F_46 ( V_444 + 4 * V_155 ,
( V_73 -> V_448 [ V_155 ] << 16 ) |
( V_73 -> V_449 [ V_155 ] << 8 ) |
V_73 -> V_450 [ V_155 ] ) ;
}
if ( V_445 )
F_304 ( V_73 ) ;
}
static void F_313 ( struct V_73 * V_73 , bool V_228 )
{
if ( ! V_228 && V_73 -> V_451 ) {
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_59 ( & V_10 -> V_265 ) ;
V_12 -> V_271 . V_272 = false ;
( void ) F_314 ( V_73 -> V_451 ) ;
V_12 -> V_271 . V_272 = true ;
F_61 ( & V_10 -> V_265 ) ;
}
}
static void F_315 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
F_92 ( V_29 ) ;
F_316 ( V_10 , V_4 ) ;
F_166 ( V_29 -> V_75 , V_29 ) ;
F_299 ( V_29 ) ;
F_317 ( V_29 , true ) ;
F_313 ( V_73 , true ) ;
F_304 ( V_73 ) ;
F_59 ( & V_10 -> V_265 ) ;
F_233 ( V_10 ) ;
F_61 ( & V_10 -> V_265 ) ;
F_232 ( V_10 , F_318 ( V_4 ) ) ;
}
static void F_319 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
int V_153 = V_73 -> V_153 ;
F_259 ( V_29 ) ;
if ( V_12 -> V_452 . V_153 == V_153 )
F_320 ( V_10 ) ;
F_307 ( V_73 ) ;
F_313 ( V_73 , false ) ;
F_317 ( V_29 , false ) ;
F_302 ( V_29 ) ;
F_169 ( V_29 -> V_75 , V_29 ) ;
F_232 ( V_10 , F_318 ( V_4 ) ) ;
F_321 ( V_10 , V_4 ) ;
F_92 ( V_29 ) ;
}
static void F_322 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_73 -> V_4 ;
F_3 ( ! V_29 -> V_108 ) ;
if ( V_73 -> V_74 )
return;
if ( V_73 -> V_77 . V_246 )
F_139 ( V_73 ) ;
if ( V_73 -> V_77 . V_453 )
F_323 ( V_73 ) ;
F_324 ( V_73 ) ;
if ( V_73 -> V_77 . V_246 ) {
F_325 ( V_73 ,
& V_73 -> V_77 . V_454 , NULL ) ;
}
F_326 ( V_29 ) ;
V_73 -> V_74 = true ;
F_327 ( V_10 , V_4 , true ) ;
F_328 ( V_10 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_455 )
V_6 -> V_455 ( V_6 ) ;
if ( V_73 -> V_77 . V_246 ) {
F_248 ( V_73 ) ;
} else {
F_153 ( V_12 , V_4 ) ;
F_154 ( V_12 , V_4 ) ;
}
F_297 ( V_73 ) ;
F_308 ( V_29 ) ;
F_329 ( V_29 ) ;
F_156 ( V_73 ) ;
if ( V_73 -> V_77 . V_246 )
F_287 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_228 ( V_6 ) ;
if ( F_96 ( V_10 ) )
F_296 ( V_10 , V_73 -> V_4 ) ;
F_315 ( V_29 ) ;
}
static bool F_330 ( struct V_73 * V_29 )
{
return F_331 ( V_29 -> V_8 . V_10 ) && V_29 -> V_4 == V_131 ;
}
static void F_332 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_73 * V_456 , * V_457 = NULL ;
F_130 (dev, crtc_it) {
if ( ! V_456 -> V_74 || V_456 == V_29 )
continue;
if ( V_457 )
return;
V_457 = V_456 ;
}
if ( ! V_457 )
return;
F_43 ( V_10 , V_457 -> V_4 ) ;
F_43 ( V_10 , V_457 -> V_4 ) ;
}
static void F_333 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_73 -> V_4 ;
F_3 ( ! V_29 -> V_108 ) ;
if ( V_73 -> V_74 )
return;
if ( F_62 ( V_73 ) )
F_142 ( V_73 ) ;
if ( V_73 -> V_77 . V_453 )
F_323 ( V_73 ) ;
F_324 ( V_73 ) ;
if ( V_73 -> V_77 . V_82 != V_458 ) {
F_46 ( F_334 ( V_73 -> V_77 . V_82 ) ,
V_73 -> V_77 . V_459 - 1 ) ;
}
if ( V_73 -> V_77 . V_246 ) {
F_325 ( V_73 ,
& V_73 -> V_77 . V_454 , NULL ) ;
}
F_335 ( V_29 ) ;
F_336 ( V_29 ) ;
V_73 -> V_74 = true ;
F_327 ( V_10 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_455 )
V_6 -> V_455 ( V_6 ) ;
if ( V_73 -> V_77 . V_246 ) {
F_328 ( V_10 , V_240 , true ) ;
V_12 -> V_251 . V_415 ( V_29 ) ;
}
F_337 ( V_73 ) ;
F_297 ( V_73 ) ;
F_308 ( V_29 ) ;
F_338 ( V_29 ) ;
F_339 ( V_29 ) ;
F_329 ( V_29 ) ;
F_156 ( V_73 ) ;
if ( V_73 -> V_77 . V_246 )
F_293 ( V_29 ) ;
if ( V_73 -> V_77 . V_460 )
F_340 ( V_29 , true ) ;
F_11 (dev, crtc, encoder) {
V_6 -> V_228 ( V_6 ) ;
F_341 ( V_6 , true ) ;
}
F_332 ( V_73 ) ;
F_315 ( V_29 ) ;
}
static void F_342 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_77 . V_346 . V_108 ) {
F_46 ( F_229 ( V_4 ) , 0 ) ;
F_46 ( F_230 ( V_4 ) , 0 ) ;
F_46 ( F_231 ( V_4 ) , 0 ) ;
}
}
static void F_343 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_73 -> V_4 ;
T_1 V_88 , V_348 ;
if ( ! V_73 -> V_74 )
return;
F_319 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_229 ( V_6 ) ;
if ( V_73 -> V_77 . V_246 )
F_328 ( V_10 , V_4 , false ) ;
F_162 ( V_73 ) ;
F_342 ( V_73 ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_461 )
V_6 -> V_461 ( V_6 ) ;
if ( V_73 -> V_77 . V_246 ) {
F_250 ( V_29 ) ;
F_152 ( V_12 , V_4 ) ;
if ( F_96 ( V_10 ) ) {
V_88 = F_100 ( V_4 ) ;
V_348 = F_5 ( V_88 ) ;
V_348 &= ~ ( V_423 |
V_171 ) ;
V_348 |= V_462 ;
F_46 ( V_88 , V_348 ) ;
V_348 = F_5 ( V_417 ) ;
V_348 &= ~ ( F_290 ( V_4 ) | F_291 ( V_4 ) ) ;
F_46 ( V_417 , V_348 ) ;
}
F_145 ( V_73 ) ;
F_249 ( V_73 ) ;
}
V_73 -> V_74 = false ;
F_329 ( V_29 ) ;
F_59 ( & V_10 -> V_265 ) ;
F_233 ( V_10 ) ;
F_61 ( & V_10 -> V_265 ) ;
}
static void F_344 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_1 * V_6 ;
enum V_80 V_82 = V_73 -> V_77 . V_82 ;
if ( ! V_73 -> V_74 )
return;
F_319 ( V_29 ) ;
F_11 (dev, crtc, encoder) {
F_341 ( V_6 , false ) ;
V_6 -> V_229 ( V_6 ) ;
}
if ( V_73 -> V_77 . V_246 )
F_328 ( V_10 , V_240 , false ) ;
F_162 ( V_73 ) ;
if ( V_73 -> V_77 . V_460 )
F_340 ( V_29 , false ) ;
F_345 ( V_12 , V_82 ) ;
F_342 ( V_73 ) ;
F_346 ( V_73 ) ;
if ( V_73 -> V_77 . V_246 ) {
F_155 ( V_12 ) ;
F_347 ( V_29 ) ;
}
F_11 (dev, crtc, encoder)
if ( V_6 -> V_461 )
V_6 -> V_461 ( V_6 ) ;
V_73 -> V_74 = false ;
F_329 ( V_29 ) ;
F_59 ( & V_10 -> V_265 ) ;
F_233 ( V_10 ) ;
F_61 ( & V_10 -> V_265 ) ;
if ( F_62 ( V_73 ) )
F_145 ( V_73 ) ;
}
static void F_348 ( struct V_28 * V_29 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
F_294 ( V_73 ) ;
}
static void F_349 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_463 * V_464 = & V_29 -> V_77 ;
if ( ! V_29 -> V_77 . V_465 . V_466 )
return;
F_3 ( F_5 ( V_467 ) & V_468 ) ;
F_117 ( V_12 , V_29 -> V_4 ) ;
F_46 ( V_469 , V_464 -> V_465 . V_470 ) ;
F_46 ( V_467 , V_464 -> V_465 . V_466 ) ;
F_46 ( F_350 ( V_29 -> V_4 ) , 0 ) ;
}
static enum V_471 F_351 ( enum V_96 V_96 )
{
switch ( V_96 ) {
case V_472 :
return V_473 ;
case V_98 :
return V_474 ;
case V_100 :
return V_475 ;
case V_102 :
return V_476 ;
default:
F_352 ( 1 ) ;
return V_477 ;
}
}
enum V_471
F_353 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_8 . V_10 ;
struct V_95 * V_478 ;
switch ( V_1 -> type ) {
case V_479 :
F_352 ( ! F_65 ( V_10 ) ) ;
case V_419 :
case V_39 :
case V_347 :
V_478 = F_354 ( & V_1 -> V_8 ) ;
return F_351 ( V_478 -> V_96 ) ;
case V_480 :
V_478 = F_355 ( & V_1 -> V_8 ) -> V_75 ;
return F_351 ( V_478 -> V_96 ) ;
case V_40 :
return V_481 ;
case V_245 :
return V_482 ;
default:
return V_477 ;
}
}
static unsigned long F_356 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_1 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_4 V_4 = V_73 -> V_4 ;
unsigned long V_483 ;
enum V_80 V_80 ;
V_80 = F_36 ( V_10 -> V_13 , V_4 ) ;
V_483 = F_205 ( F_357 ( V_4 ) ) ;
V_483 |= F_205 ( F_80 ( V_80 ) ) ;
if ( V_73 -> V_77 . V_346 . V_108 ||
V_73 -> V_77 . V_346 . V_484 )
V_483 |= F_205 ( F_358 ( V_4 ) ) ;
F_11 (dev, crtc, intel_encoder)
V_483 |= F_205 ( F_353 ( V_1 ) ) ;
return V_483 ;
}
void F_359 ( struct V_11 * V_12 ,
bool V_228 )
{
if ( V_12 -> V_485 . V_486 == V_228 )
return;
if ( V_228 )
F_144 ( V_12 , V_487 ) ;
else
F_146 ( V_12 , V_487 ) ;
V_12 -> V_485 . V_486 = V_228 ;
}
static void F_360 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned long V_488 [ V_489 ] = { 0 , } ;
struct V_73 * V_29 ;
F_130 (dev, crtc) {
enum V_471 V_490 ;
if ( ! V_29 -> V_8 . V_108 )
continue;
V_488 [ V_29 -> V_4 ] = F_356 ( & V_29 -> V_8 ) ;
F_361 (domain, pipe_domains[crtc->pipe])
F_144 ( V_12 , V_490 ) ;
}
F_130 (dev, crtc) {
enum V_471 V_490 ;
F_361 (domain, crtc->enabled_power_domains)
F_146 ( V_12 , V_490 ) ;
V_29 -> V_491 = V_488 [ V_29 -> V_4 ] ;
}
F_359 ( V_12 , false ) ;
}
static int F_362 ( struct V_11 * V_12 )
{
int V_492 , V_493 [] = { 800 , 1600 , 2000 , 2400 } ;
F_59 ( & V_12 -> V_113 ) ;
V_492 = F_60 ( V_12 , V_494 ) &
V_495 ;
F_61 ( & V_12 -> V_113 ) ;
return V_493 [ V_492 ] * 1000 ;
}
static void F_363 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_496 = V_12 -> V_251 . V_497 ( V_10 ) ;
F_140 ( L_82 ,
V_12 -> V_496 ) ;
F_46 ( V_498 , F_364 ( V_12 -> V_496 , 1000 ) ) ;
}
static void F_365 ( struct V_9 * V_10 , int V_499 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_110 , V_500 ;
F_3 ( V_12 -> V_251 . V_497 ( V_10 ) != V_12 -> V_496 ) ;
if ( V_499 >= 320000 )
V_500 = 2 ;
else if ( V_499 == 266667 )
V_500 = 1 ;
else
V_500 = 0 ;
F_59 ( & V_12 -> V_439 . V_440 ) ;
V_110 = F_366 ( V_12 , V_501 ) ;
V_110 &= ~ V_502 ;
V_110 |= ( V_500 << V_503 ) ;
F_367 ( V_12 , V_501 , V_110 ) ;
if ( F_39 ( ( F_366 ( V_12 , V_501 ) &
V_504 ) == ( V_500 << V_505 ) ,
50 ) ) {
F_122 ( L_83 ) ;
}
F_61 ( & V_12 -> V_439 . V_440 ) ;
if ( V_499 == 400000 ) {
T_1 V_506 , V_26 ;
V_26 = F_362 ( V_12 ) ;
V_506 = F_9 ( V_26 << 1 , V_499 ) - 1 ;
F_59 ( & V_12 -> V_113 ) ;
V_110 = F_60 ( V_12 , V_507 ) ;
V_110 &= ~ V_508 ;
V_110 |= V_506 ;
F_368 ( V_12 , V_507 , V_110 ) ;
if ( F_39 ( ( F_60 ( V_12 , V_507 ) &
V_509 ) == ( V_506 << V_510 ) ,
50 ) )
F_122 ( L_83 ) ;
F_61 ( & V_12 -> V_113 ) ;
}
F_59 ( & V_12 -> V_113 ) ;
V_110 = F_369 ( V_12 , V_511 ) ;
V_110 &= ~ 0x7f ;
if ( V_499 == 400000 )
V_110 |= 4500 / 250 ;
else
V_110 |= 3000 / 250 ;
F_370 ( V_12 , V_511 , V_110 ) ;
F_61 ( & V_12 -> V_113 ) ;
F_363 ( V_10 ) ;
}
static void F_371 ( struct V_9 * V_10 , int V_499 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_110 , V_500 ;
F_3 ( V_12 -> V_251 . V_497 ( V_10 ) != V_12 -> V_496 ) ;
switch ( V_499 ) {
case 400000 :
V_500 = 3 ;
break;
case 333333 :
case 320000 :
V_500 = 2 ;
break;
case 266667 :
V_500 = 1 ;
break;
case 200000 :
V_500 = 0 ;
break;
default:
F_3 ( 1 ) ;
return;
}
F_59 ( & V_12 -> V_439 . V_440 ) ;
V_110 = F_366 ( V_12 , V_501 ) ;
V_110 &= ~ V_512 ;
V_110 |= ( V_500 << V_513 ) ;
F_367 ( V_12 , V_501 , V_110 ) ;
if ( F_39 ( ( F_366 ( V_12 , V_501 ) &
V_514 ) == ( V_500 << V_515 ) ,
50 ) ) {
F_122 ( L_83 ) ;
}
F_61 ( & V_12 -> V_439 . V_440 ) ;
F_363 ( V_10 ) ;
}
static int F_372 ( struct V_11 * V_12 ,
int V_516 )
{
int V_26 = F_362 ( V_12 ) ;
int V_517 = ( V_26 << 1 ) % 320000 != 0 ? 333333 : 320000 ;
if ( F_18 ( V_12 -> V_10 ) )
return 400000 ;
if ( V_516 > V_517 * 9 / 10 )
return 400000 ;
else if ( V_516 > 266667 * 9 / 10 )
return V_517 ;
else if ( V_516 > 0 )
return 266667 ;
else
return 200000 ;
}
static int F_373 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_73 * V_73 ;
int V_516 = 0 ;
F_130 (dev, intel_crtc) {
if ( V_73 -> V_518 )
V_516 = V_57 ( V_516 ,
V_73 -> V_519 -> V_78 . V_79 ) ;
}
return V_516 ;
}
static void F_374 ( struct V_9 * V_10 ,
unsigned * V_520 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 ;
int V_516 = F_373 ( V_12 ) ;
if ( F_372 ( V_12 , V_516 ) ==
V_12 -> V_496 )
return;
F_130 (dev, intel_crtc)
if ( V_73 -> V_8 . V_108 )
* V_520 |= ( 1 << V_73 -> V_4 ) ;
}
static void F_375 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_516 = F_373 ( V_12 ) ;
int V_521 = F_372 ( V_12 , V_516 ) ;
if ( V_521 != V_12 -> V_496 ) {
if ( F_18 ( V_10 ) )
F_371 ( V_10 , V_521 ) ;
else
F_365 ( V_10 , V_521 ) ;
}
F_360 ( V_10 ) ;
}
static void F_376 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_73 -> V_4 ;
bool V_522 ;
F_3 ( ! V_29 -> V_108 ) ;
if ( V_73 -> V_74 )
return;
V_522 = F_10 ( V_29 , V_245 ) ;
if ( ! V_522 ) {
if ( F_18 ( V_10 ) )
F_377 ( V_73 ) ;
else
F_378 ( V_73 ) ;
}
if ( V_73 -> V_77 . V_453 )
F_323 ( V_73 ) ;
F_324 ( V_73 ) ;
F_379 ( V_73 ) ;
V_73 -> V_74 = true ;
F_327 ( V_10 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_523 )
V_6 -> V_523 ( V_6 ) ;
if ( ! V_522 ) {
if ( F_18 ( V_10 ) )
F_124 ( V_73 ) ;
else
F_116 ( V_73 ) ;
}
F_11 (dev, crtc, encoder)
if ( V_6 -> V_455 )
V_6 -> V_455 ( V_6 ) ;
F_349 ( V_73 ) ;
F_308 ( V_29 ) ;
F_329 ( V_29 ) ;
F_156 ( V_73 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_228 ( V_6 ) ;
F_315 ( V_29 ) ;
F_380 ( V_10 ) ;
}
static void F_381 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_46 ( F_382 ( V_29 -> V_4 ) , V_29 -> V_77 . V_199 . V_524 ) ;
F_46 ( F_383 ( V_29 -> V_4 ) , V_29 -> V_77 . V_199 . V_525 ) ;
}
static void F_384 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_73 -> V_4 ;
F_3 ( ! V_29 -> V_108 ) ;
if ( V_73 -> V_74 )
return;
F_381 ( V_73 ) ;
if ( V_73 -> V_77 . V_453 )
F_323 ( V_73 ) ;
F_324 ( V_73 ) ;
F_379 ( V_73 ) ;
V_73 -> V_74 = true ;
if ( ! F_20 ( V_10 ) )
F_327 ( V_10 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_455 )
V_6 -> V_455 ( V_6 ) ;
F_131 ( V_73 ) ;
F_349 ( V_73 ) ;
F_308 ( V_29 ) ;
F_329 ( V_29 ) ;
F_156 ( V_73 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_228 ( V_6 ) ;
F_315 ( V_29 ) ;
if ( F_20 ( V_10 ) )
F_327 ( V_10 , V_4 , true ) ;
F_380 ( V_10 ) ;
}
static void F_385 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_77 . V_465 . V_466 )
return;
F_117 ( V_12 , V_29 -> V_4 ) ;
F_140 ( L_84 ,
F_5 ( V_467 ) ) ;
F_46 ( V_467 , 0 ) ;
}
static void F_386 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_73 -> V_4 ;
if ( ! V_73 -> V_74 )
return;
if ( F_20 ( V_10 ) )
F_327 ( V_10 , V_4 , false ) ;
F_387 ( V_12 , false ) ;
F_319 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_229 ( V_6 ) ;
F_43 ( V_10 , V_4 ) ;
F_162 ( V_73 ) ;
F_385 ( V_73 ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_461 )
V_6 -> V_461 ( V_6 ) ;
if ( ! F_10 ( V_29 , V_245 ) ) {
if ( F_18 ( V_10 ) )
F_135 ( V_12 , V_4 ) ;
else if ( F_19 ( V_10 ) )
F_134 ( V_12 , V_4 ) ;
else
F_133 ( V_73 ) ;
}
if ( ! F_20 ( V_10 ) )
F_327 ( V_10 , V_4 , false ) ;
V_73 -> V_74 = false ;
F_329 ( V_29 ) ;
F_59 ( & V_10 -> V_265 ) ;
F_233 ( V_10 ) ;
F_61 ( & V_10 -> V_265 ) ;
}
static void F_388 ( struct V_28 * V_29 )
{
}
static void F_389 ( struct V_28 * V_29 ,
bool V_108 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_526 * V_527 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
if ( ! V_10 -> V_75 -> V_528 )
return;
V_527 = V_10 -> V_75 -> V_528 -> V_529 ;
if ( ! V_527 -> V_530 )
return;
switch ( V_4 ) {
case 0 :
V_527 -> V_530 -> V_531 = V_108 ? V_29 -> V_425 . V_532 : 0 ;
V_527 -> V_530 -> V_533 = V_108 ? V_29 -> V_425 . V_534 : 0 ;
break;
case 1 :
V_527 -> V_530 -> V_535 = V_108 ? V_29 -> V_425 . V_532 : 0 ;
V_527 -> V_530 -> V_536 = V_108 ? V_29 -> V_425 . V_534 : 0 ;
break;
default:
F_122 ( L_85 , F_42 ( V_4 ) ) ;
break;
}
}
void F_390 ( struct V_28 * V_29 , bool V_228 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_471 V_490 ;
unsigned long V_537 ;
if ( V_228 ) {
if ( ! V_73 -> V_74 ) {
V_537 = F_356 ( V_29 ) ;
F_361 (domain, domains)
F_144 ( V_12 , V_490 ) ;
V_73 -> V_491 = V_537 ;
V_12 -> V_251 . V_538 ( V_29 ) ;
}
} else {
if ( V_73 -> V_74 ) {
V_12 -> V_251 . V_539 ( V_29 ) ;
V_537 = V_73 -> V_491 ;
F_361 (domain, domains)
F_146 ( V_12 , V_490 ) ;
V_73 -> V_491 = 0 ;
}
}
}
void F_391 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_1 ;
bool V_228 = false ;
F_11 (dev, crtc, intel_encoder)
V_228 |= V_1 -> V_540 ;
F_390 ( V_29 , V_228 ) ;
F_389 ( V_29 , V_228 ) ;
}
static void F_392 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_541 * V_3 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_259 * V_338 = F_197 ( V_29 -> V_75 -> V_76 ) ;
enum V_4 V_4 = F_35 ( V_29 ) -> V_4 ;
F_3 ( ! V_29 -> V_108 ) ;
V_12 -> V_251 . V_539 ( V_29 ) ;
F_389 ( V_29 , false ) ;
V_12 -> V_251 . V_542 ( V_29 ) ;
if ( V_29 -> V_75 -> V_76 ) {
F_59 ( & V_10 -> V_265 ) ;
F_184 ( V_338 ) ;
F_227 ( V_338 , NULL ,
F_192 ( V_4 ) ) ;
F_61 ( & V_10 -> V_265 ) ;
V_29 -> V_75 -> V_76 = NULL ;
}
F_393 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_3 -> V_6 || ! V_3 -> V_6 -> V_29 )
continue;
if ( V_3 -> V_6 -> V_29 != V_29 )
continue;
V_3 -> V_543 = V_544 ;
F_394 ( V_3 -> V_6 ) -> V_540 = false ;
}
}
void F_395 ( struct V_545 * V_6 )
{
struct V_1 * V_1 = F_394 ( V_6 ) ;
F_396 ( V_6 ) ;
F_195 ( V_1 ) ;
}
static void F_397 ( struct V_1 * V_6 , int V_425 )
{
if ( V_425 == V_546 ) {
V_6 -> V_540 = true ;
F_391 ( V_6 -> V_8 . V_29 ) ;
} else {
V_6 -> V_540 = false ;
F_391 ( V_6 -> V_8 . V_29 ) ;
}
}
static void F_398 ( struct V_2 * V_3 )
{
if ( V_3 -> V_122 ( V_3 ) ) {
struct V_1 * V_6 = V_3 -> V_6 ;
struct V_28 * V_29 ;
bool V_547 ;
enum V_4 V_4 ;
F_47 ( L_86 ,
V_3 -> V_8 . V_8 . V_226 ,
V_3 -> V_8 . V_123 ) ;
if ( V_3 -> V_5 )
return;
F_41 ( V_3 -> V_8 . V_543 == V_544 ,
L_87 ) ;
F_41 ( V_3 -> V_8 . V_6 != & V_6 -> V_8 ,
L_88 ) ;
if ( V_6 ) {
F_41 ( ! V_6 -> V_540 ,
L_89 ) ;
V_547 = V_6 -> V_122 ( V_6 , & V_4 ) ;
F_41 ( ! V_547 , L_90 ) ;
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
void F_399 ( struct V_541 * V_3 , int V_425 )
{
if ( V_425 != V_546 )
V_425 = V_544 ;
if ( V_425 == V_3 -> V_543 )
return;
V_3 -> V_543 = V_425 ;
if ( V_3 -> V_6 )
F_397 ( F_394 ( V_3 -> V_6 ) , V_425 ) ;
F_400 ( V_3 -> V_10 ) ;
}
bool F_401 ( struct V_2 * V_3 )
{
enum V_4 V_4 = 0 ;
struct V_1 * V_6 = V_3 -> V_6 ;
return V_6 -> V_122 ( V_6 , & V_4 ) ;
}
static bool F_402 ( struct V_9 * V_10 , enum V_4 V_4 ,
struct V_463 * V_464 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_357 =
F_35 ( V_12 -> V_81 [ V_140 ] ) ;
F_47 ( L_94 ,
F_42 ( V_4 ) , V_464 -> V_366 ) ;
if ( V_464 -> V_366 > 4 ) {
F_47 ( L_95 ,
F_42 ( V_4 ) , V_464 -> V_366 ) ;
return false ;
}
if ( F_210 ( V_10 ) || F_168 ( V_10 ) ) {
if ( V_464 -> V_366 > 2 ) {
F_47 ( L_96 ,
V_464 -> V_366 ) ;
return false ;
} else {
return true ;
}
}
if ( F_45 ( V_10 ) -> V_340 == 2 )
return true ;
switch ( V_4 ) {
case V_131 :
return true ;
case V_140 :
if ( V_12 -> V_81 [ V_359 ] -> V_108 &&
V_464 -> V_366 > 2 ) {
F_47 ( L_97 ,
F_42 ( V_4 ) , V_464 -> V_366 ) ;
return false ;
}
return true ;
case V_359 :
if ( ! F_236 ( V_357 ) ||
V_357 -> V_77 . V_366 <= 2 ) {
if ( V_464 -> V_366 > 2 ) {
F_47 ( L_97 ,
F_42 ( V_4 ) , V_464 -> V_366 ) ;
return false ;
}
} else {
F_47 ( L_98 ) ;
return false ;
}
return true ;
default:
F_137 () ;
}
}
static int F_403 ( struct V_73 * V_73 ,
struct V_463 * V_464 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_343 * V_78 = & V_464 -> V_78 ;
int V_548 , V_549 , V_550 ;
bool V_551 , V_552 = false ;
V_371:
V_549 = F_6 ( V_10 ) * F_404 ( 100 ) / F_405 ( 1 ) / 10 ;
V_550 = V_78 -> V_79 ;
V_548 = F_406 ( V_550 , V_549 ,
V_464 -> V_553 ) ;
V_464 -> V_366 = V_548 ;
F_407 ( V_464 -> V_553 , V_548 , V_550 ,
V_549 , & V_464 -> V_454 ) ;
V_551 = F_402 ( V_73 -> V_8 . V_10 ,
V_73 -> V_4 , V_464 ) ;
if ( ! V_551 && V_464 -> V_553 > 6 * 3 ) {
V_464 -> V_553 -= 2 * 3 ;
F_47 ( L_99 ,
V_464 -> V_553 ) ;
V_552 = true ;
V_464 -> V_554 = true ;
goto V_371;
}
if ( V_552 )
return V_555 ;
return V_551 ? 0 : - V_270 ;
}
static void F_408 ( struct V_73 * V_29 ,
struct V_463 * V_464 )
{
V_464 -> V_438 = V_341 . V_556 &&
F_330 ( V_29 ) &&
V_464 -> V_553 <= 24 ;
}
static int F_409 ( struct V_73 * V_29 ,
struct V_463 * V_464 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_343 * V_78 = & V_464 -> V_78 ;
if ( F_45 ( V_10 ) -> V_86 < 4 ) {
struct V_11 * V_12 = V_10 -> V_13 ;
int V_557 =
V_12 -> V_251 . V_497 ( V_10 ) ;
if ( ( V_29 -> V_4 == V_131 || F_410 ( V_10 ) ) &&
V_78 -> V_79 > V_557 * 9 / 10 ) {
V_557 *= 2 ;
V_464 -> V_247 = true ;
}
if ( V_78 -> V_79 > V_557 * 9 / 10 )
return - V_270 ;
}
if ( ( F_10 ( & V_29 -> V_8 , V_31 ) &&
F_13 ( V_10 ) ) || V_464 -> V_247 )
V_464 -> V_314 &= ~ 1 ;
if ( ( F_45 ( V_10 ) -> V_86 > 4 || F_16 ( V_10 ) ) &&
V_78 -> V_558 == V_78 -> V_532 )
return - V_270 ;
if ( ( F_16 ( V_10 ) || F_19 ( V_10 ) ) && V_464 -> V_553 > 10 * 3 ) {
V_464 -> V_553 = 10 * 3 ;
} else if ( F_45 ( V_10 ) -> V_86 <= 4 && V_464 -> V_553 > 8 * 3 ) {
V_464 -> V_553 = 8 * 3 ;
}
if ( F_331 ( V_10 ) )
F_408 ( V_29 , V_464 ) ;
if ( F_54 ( V_10 ) || F_96 ( V_10 ) || F_65 ( V_10 ) )
V_464 -> V_117 = V_29 -> V_77 . V_117 ;
if ( V_464 -> V_246 )
return F_403 ( V_29 , V_464 ) ;
return 0 ;
}
static int F_411 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_26 = F_362 ( V_12 ) ;
T_1 V_110 ;
int V_506 ;
if ( F_18 ( V_10 ) )
return 400000 ;
F_59 ( & V_12 -> V_113 ) ;
V_110 = F_60 ( V_12 , V_507 ) ;
F_61 ( & V_12 -> V_113 ) ;
V_506 = V_110 & V_508 ;
F_41 ( ( V_110 & V_509 ) !=
( V_506 << V_510 ) ,
L_100 ) ;
return F_9 ( V_26 << 1 , V_506 + 1 ) ;
}
static int F_412 ( struct V_9 * V_10 )
{
return 400000 ;
}
static int F_413 ( struct V_9 * V_10 )
{
return 333000 ;
}
static int F_414 ( struct V_9 * V_10 )
{
return 200000 ;
}
static int F_415 ( struct V_9 * V_10 )
{
T_5 V_559 = 0 ;
F_416 ( V_10 -> V_560 , V_561 , & V_559 ) ;
switch ( V_559 & V_562 ) {
case V_563 :
return 267000 ;
case V_564 :
return 333000 ;
case V_565 :
return 444000 ;
case V_566 :
return 200000 ;
default:
F_122 ( L_101 , V_559 ) ;
case V_567 :
return 133000 ;
case V_568 :
return 167000 ;
}
}
static int F_417 ( struct V_9 * V_10 )
{
T_5 V_559 = 0 ;
F_416 ( V_10 -> V_560 , V_561 , & V_559 ) ;
if ( V_559 & V_569 )
return 133000 ;
else {
switch ( V_559 & V_562 ) {
case V_570 :
return 333000 ;
default:
case V_571 :
return 190000 ;
}
}
}
static int F_418 ( struct V_9 * V_10 )
{
return 266000 ;
}
static int F_419 ( struct V_9 * V_10 )
{
T_5 V_572 = 0 ;
switch ( V_572 & V_573 ) {
case V_574 :
case V_575 :
return 200000 ;
case V_576 :
return 250000 ;
case V_577 :
return 133000 ;
}
return 0 ;
}
static int F_420 ( struct V_9 * V_10 )
{
return 133000 ;
}
static void
F_421 ( T_4 * V_578 , T_4 * V_579 )
{
while ( * V_578 > V_580 ||
* V_579 > V_580 ) {
* V_578 >>= 1 ;
* V_579 >>= 1 ;
}
}
static void F_422 ( unsigned int V_19 , unsigned int V_25 ,
T_4 * V_581 , T_4 * V_582 )
{
* V_582 = F_423 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_581 = F_32 ( ( V_55 ) V_19 * * V_582 , V_25 ) ;
F_421 ( V_581 , V_582 ) ;
}
void
F_407 ( int V_583 , int V_584 ,
int V_585 , int V_586 ,
struct V_587 * V_588 )
{
V_588 -> V_589 = 64 ;
F_422 ( V_583 * V_585 ,
V_586 * V_584 * 8 ,
& V_588 -> V_590 , & V_588 -> V_591 ) ;
F_422 ( V_585 , V_586 ,
& V_588 -> V_592 , & V_588 -> V_593 ) ;
}
static inline bool F_424 ( struct V_11 * V_12 )
{
if ( V_341 . V_594 >= 0 )
return V_341 . V_594 != 0 ;
return V_12 -> V_595 . V_596
&& ! ( V_12 -> V_149 & V_597 ) ;
}
static int F_425 ( struct V_28 * V_29 , int V_598 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_18 ;
if ( F_19 ( V_10 ) ) {
V_18 = 100000 ;
} else if ( F_10 ( V_29 , V_31 ) &&
F_424 ( V_12 ) && V_598 < 2 ) {
V_18 = V_12 -> V_595 . V_599 ;
F_47 ( L_102 , V_18 ) ;
} else if ( ! F_20 ( V_10 ) ) {
V_18 = 96000 ;
} else {
V_18 = 48000 ;
}
return V_18 ;
}
static T_4 F_426 ( struct V_54 * V_54 )
{
return ( 1 << V_54 -> V_25 ) << 16 | V_54 -> V_21 ;
}
static T_4 F_427 ( struct V_54 * V_54 )
{
return V_54 -> V_25 << 16 | V_54 -> V_20 << 8 | V_54 -> V_21 ;
}
static void F_428 ( struct V_73 * V_29 ,
T_2 * V_600 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_1 V_601 , V_602 = 0 ;
if ( F_17 ( V_10 ) ) {
V_601 = F_426 ( & V_29 -> V_77 . V_54 ) ;
if ( V_600 )
V_602 = F_426 ( V_600 ) ;
} else {
V_601 = F_427 ( & V_29 -> V_77 . V_54 ) ;
if ( V_600 )
V_602 = F_427 ( V_600 ) ;
}
V_29 -> V_77 . V_199 . V_524 = V_601 ;
V_29 -> V_603 = false ;
if ( F_10 ( & V_29 -> V_8 , V_31 ) &&
V_600 && V_341 . V_604 ) {
V_29 -> V_77 . V_199 . V_525 = V_602 ;
V_29 -> V_603 = true ;
} else {
V_29 -> V_77 . V_199 . V_525 = V_601 ;
}
}
static void F_429 ( struct V_11 * V_12 , enum V_4
V_4 )
{
T_1 V_605 ;
V_605 = F_126 ( V_12 , V_4 , F_430 ( 1 ) ) ;
V_605 &= 0xffffff00 ;
V_605 |= 0x00000030 ;
F_128 ( V_12 , V_4 , F_430 ( 1 ) , V_605 ) ;
V_605 = F_126 ( V_12 , V_4 , V_606 ) ;
V_605 &= 0x8cffffff ;
V_605 = 0x8c000000 ;
F_128 ( V_12 , V_4 , V_606 , V_605 ) ;
V_605 = F_126 ( V_12 , V_4 , F_430 ( 1 ) ) ;
V_605 &= 0xffffff00 ;
F_128 ( V_12 , V_4 , F_430 ( 1 ) , V_605 ) ;
V_605 = F_126 ( V_12 , V_4 , V_606 ) ;
V_605 &= 0x00ffffff ;
V_605 |= 0xb0000000 ;
F_128 ( V_12 , V_4 , V_606 , V_605 ) ;
}
static void F_431 ( struct V_73 * V_29 ,
struct V_587 * V_588 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
F_46 ( F_432 ( V_4 ) , F_433 ( V_588 -> V_589 ) | V_588 -> V_590 ) ;
F_46 ( F_434 ( V_4 ) , V_588 -> V_591 ) ;
F_46 ( F_435 ( V_4 ) , V_588 -> V_592 ) ;
F_46 ( F_436 ( V_4 ) , V_588 -> V_593 ) ;
}
static void F_325 ( struct V_73 * V_29 ,
struct V_587 * V_588 ,
struct V_587 * V_607 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
enum V_80 V_80 = V_29 -> V_77 . V_82 ;
if ( F_45 ( V_10 ) -> V_86 >= 5 ) {
F_46 ( F_289 ( V_80 ) , F_433 ( V_588 -> V_589 ) | V_588 -> V_590 ) ;
F_46 ( F_437 ( V_80 ) , V_588 -> V_591 ) ;
F_46 ( F_438 ( V_80 ) , V_588 -> V_592 ) ;
F_46 ( F_439 ( V_80 ) , V_588 -> V_593 ) ;
if ( V_607 && F_45 ( V_10 ) -> V_86 < 8 &&
V_29 -> V_77 . V_608 ) {
F_46 ( F_440 ( V_80 ) ,
F_433 ( V_607 -> V_589 ) | V_607 -> V_590 ) ;
F_46 ( F_441 ( V_80 ) , V_607 -> V_591 ) ;
F_46 ( F_442 ( V_80 ) , V_607 -> V_592 ) ;
F_46 ( F_443 ( V_80 ) , V_607 -> V_593 ) ;
}
} else {
F_46 ( F_444 ( V_4 ) , F_433 ( V_588 -> V_589 ) | V_588 -> V_590 ) ;
F_46 ( F_445 ( V_4 ) , V_588 -> V_591 ) ;
F_46 ( F_446 ( V_4 ) , V_588 -> V_592 ) ;
F_46 ( F_447 ( V_4 ) , V_588 -> V_593 ) ;
}
}
void F_323 ( struct V_73 * V_29 )
{
if ( V_29 -> V_77 . V_246 )
F_431 ( V_29 , & V_29 -> V_77 . V_609 ) ;
else
F_325 ( V_29 , & V_29 -> V_77 . V_609 ,
& V_29 -> V_77 . V_610 ) ;
}
static void F_448 ( struct V_73 * V_29 )
{
T_1 V_54 , V_201 ;
V_54 = V_611 | V_208 |
V_612 | V_613 ;
if ( V_29 -> V_4 == V_140 )
V_54 |= V_207 ;
V_54 |= V_112 ;
V_29 -> V_77 . V_199 . V_54 = V_54 ;
V_201 = ( V_29 -> V_77 . V_459 - 1 )
<< V_614 ;
V_29 -> V_77 . V_199 . V_201 = V_201 ;
}
static void F_378 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
T_1 V_615 ;
T_1 V_616 , V_617 , V_618 , V_619 , V_620 ;
T_1 V_621 , V_605 ;
F_59 ( & V_12 -> V_113 ) ;
V_616 = V_29 -> V_77 . V_54 . V_25 ;
V_617 = V_29 -> V_77 . V_54 . V_20 ;
V_618 = V_29 -> V_77 . V_54 . V_21 ;
V_619 = V_29 -> V_77 . V_54 . V_23 ;
V_620 = V_29 -> V_77 . V_54 . V_24 ;
if ( V_4 == V_140 )
F_429 ( V_12 , V_4 ) ;
F_128 ( V_12 , V_4 , V_622 , 0x0100000f ) ;
V_605 = F_126 ( V_12 , V_4 , F_449 ( V_4 ) ) ;
V_605 &= 0x00ffffff ;
F_128 ( V_12 , V_4 , F_449 ( V_4 ) , V_605 ) ;
F_128 ( V_12 , V_4 , V_623 , 0x610 ) ;
V_615 = ( ( V_617 << V_624 ) | ( V_618 & V_625 ) ) ;
V_615 |= ( ( V_619 << V_626 ) | ( V_620 << V_627 ) ) ;
V_615 |= ( ( V_616 << V_628 ) ) ;
V_615 |= ( 1 << V_629 ) ;
V_615 |= ( V_630 << V_631 ) ;
F_128 ( V_12 , V_4 , F_450 ( V_4 ) , V_615 ) ;
V_615 |= V_632 ;
F_128 ( V_12 , V_4 , F_450 ( V_4 ) , V_615 ) ;
if ( V_29 -> V_77 . V_633 == 162000 ||
F_10 ( & V_29 -> V_8 , V_40 ) ||
F_10 ( & V_29 -> V_8 , V_39 ) )
F_128 ( V_12 , V_4 , F_451 ( V_4 ) ,
0x009f0003 ) ;
else
F_128 ( V_12 , V_4 , F_451 ( V_4 ) ,
0x00d0000f ) ;
if ( F_10 ( & V_29 -> V_8 , V_347 ) ||
F_10 ( & V_29 -> V_8 , V_419 ) ) {
if ( V_4 == V_131 )
F_128 ( V_12 , V_4 , F_452 ( V_4 ) ,
0x0df40000 ) ;
else
F_128 ( V_12 , V_4 , F_452 ( V_4 ) ,
0x0df70000 ) ;
} else {
if ( V_4 == V_131 )
F_128 ( V_12 , V_4 , F_452 ( V_4 ) ,
0x0df70000 ) ;
else
F_128 ( V_12 , V_4 , F_452 ( V_4 ) ,
0x0df40000 ) ;
}
V_621 = F_126 ( V_12 , V_4 , F_453 ( V_4 ) ) ;
V_621 = ( V_621 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_10 ( & V_29 -> V_8 , V_419 ) ||
F_10 ( & V_29 -> V_8 , V_347 ) )
V_621 |= 0x01000000 ;
F_128 ( V_12 , V_4 , F_453 ( V_4 ) , V_621 ) ;
F_128 ( V_12 , V_4 , F_454 ( V_4 ) , 0x87871000 ) ;
F_61 ( & V_12 -> V_113 ) ;
}
static void F_455 ( struct V_73 * V_29 )
{
V_29 -> V_77 . V_199 . V_54 = V_209 |
V_208 | V_612 |
V_112 ;
if ( V_29 -> V_4 != V_131 )
V_29 -> V_77 . V_199 . V_54 |= V_207 ;
V_29 -> V_77 . V_199 . V_201 =
( V_29 -> V_77 . V_459 - 1 ) << V_614 ;
}
static void F_377 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
int V_218 = F_57 ( V_29 -> V_4 ) ;
enum V_202 V_96 = F_125 ( V_4 ) ;
T_1 V_634 , V_635 ;
T_1 V_616 , V_617 , V_618 , V_619 , V_620 , V_636 ;
int V_18 ;
V_616 = V_29 -> V_77 . V_54 . V_25 ;
V_636 = V_29 -> V_77 . V_54 . V_21 & 0x3fffff ;
V_617 = V_29 -> V_77 . V_54 . V_20 ;
V_618 = V_29 -> V_77 . V_54 . V_21 >> 22 ;
V_619 = V_29 -> V_77 . V_54 . V_23 ;
V_620 = V_29 -> V_77 . V_54 . V_24 ;
F_46 ( V_218 ,
V_29 -> V_77 . V_199 . V_54 & ~ V_112 ) ;
F_59 ( & V_12 -> V_113 ) ;
F_128 ( V_12 , V_4 , F_456 ( V_96 ) ,
5 << V_637 |
V_619 << V_638 |
V_620 << V_639 |
1 << V_640 ) ;
F_128 ( V_12 , V_4 , F_457 ( V_96 ) , V_618 ) ;
F_128 ( V_12 , V_4 , F_458 ( V_96 ) ,
V_641 |
1 << V_642 ) ;
F_128 ( V_12 , V_4 , F_459 ( V_96 ) , V_636 ) ;
F_128 ( V_12 , V_4 , F_460 ( V_96 ) ,
V_643 |
( 2 << V_644 ) ) ;
V_18 = F_425 ( & V_29 -> V_8 , 0 ) ;
V_634 = 5 << V_645 |
2 << V_646 ;
if ( V_18 == 100000 )
V_635 = 11 ;
else if ( V_18 == 38400 )
V_635 = 10 ;
else
V_635 = 9 ;
V_634 |= V_635 << V_647 ;
F_128 ( V_12 , V_4 , F_461 ( V_96 ) , V_634 ) ;
F_128 ( V_12 , V_4 , F_127 ( V_96 ) ,
F_126 ( V_12 , V_4 , F_127 ( V_96 ) ) |
V_648 ) ;
F_61 ( & V_12 -> V_113 ) ;
}
static void F_462 ( struct V_73 * V_29 ,
T_2 * V_600 ,
int V_598 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_54 ;
bool V_649 ;
struct V_54 * clock = & V_29 -> V_77 . V_54 ;
F_428 ( V_29 , V_600 ) ;
V_649 = F_10 ( & V_29 -> V_8 , V_42 ) ||
F_10 ( & V_29 -> V_8 , V_39 ) ;
V_54 = V_612 ;
if ( F_10 ( & V_29 -> V_8 , V_31 ) )
V_54 |= V_650 ;
else
V_54 |= V_651 ;
if ( F_463 ( V_10 ) || F_464 ( V_10 ) || F_465 ( V_10 ) ) {
V_54 |= ( V_29 -> V_77 . V_459 - 1 )
<< V_652 ;
}
if ( V_649 )
V_54 |= V_653 ;
if ( F_10 ( & V_29 -> V_8 , V_419 ) )
V_54 |= V_653 ;
if ( F_17 ( V_10 ) )
V_54 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_654 ;
else {
V_54 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_655 ;
if ( F_16 ( V_10 ) && V_600 )
V_54 |= ( 1 << ( V_600 -> V_23 - 1 ) ) << V_656 ;
}
switch ( clock -> V_24 ) {
case 5 :
V_54 |= V_657 ;
break;
case 7 :
V_54 |= V_658 ;
break;
case 10 :
V_54 |= V_659 ;
break;
case 14 :
V_54 |= V_660 ;
break;
}
if ( F_45 ( V_10 ) -> V_86 >= 4 )
V_54 |= ( 6 << V_661 ) ;
if ( V_29 -> V_77 . V_662 )
V_54 |= V_663 ;
else if ( F_10 ( & V_29 -> V_8 , V_31 ) &&
F_424 ( V_12 ) && V_598 < 2 )
V_54 |= V_664 ;
else
V_54 |= V_665 ;
V_54 |= V_112 ;
V_29 -> V_77 . V_199 . V_54 = V_54 ;
if ( F_45 ( V_10 ) -> V_86 >= 4 ) {
T_1 V_201 = ( V_29 -> V_77 . V_459 - 1 )
<< V_614 ;
V_29 -> V_77 . V_199 . V_201 = V_201 ;
}
}
static void F_466 ( struct V_73 * V_29 ,
T_2 * V_600 ,
int V_598 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_54 ;
struct V_54 * clock = & V_29 -> V_77 . V_54 ;
F_428 ( V_29 , V_600 ) ;
V_54 = V_612 ;
if ( F_10 ( & V_29 -> V_8 , V_31 ) ) {
V_54 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_655 ;
} else {
if ( clock -> V_23 == 2 )
V_54 |= V_666 ;
else
V_54 |= ( clock -> V_23 - 2 ) << V_655 ;
if ( clock -> V_24 == 4 )
V_54 |= V_667 ;
}
if ( ! F_132 ( V_10 ) && F_10 ( & V_29 -> V_8 , V_51 ) )
V_54 |= V_206 ;
if ( F_10 ( & V_29 -> V_8 , V_31 ) &&
F_424 ( V_12 ) && V_598 < 2 )
V_54 |= V_664 ;
else
V_54 |= V_665 ;
V_54 |= V_112 ;
V_29 -> V_77 . V_199 . V_54 = V_54 ;
}
static void F_324 ( struct V_73 * V_73 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_73 -> V_4 ;
enum V_80 V_82 = V_73 -> V_77 . V_82 ;
struct V_343 * V_78 =
& V_73 -> V_77 . V_78 ;
T_4 V_668 , V_669 ;
int V_670 = 0 ;
V_668 = V_78 -> V_668 ;
V_669 = V_78 -> V_669 ;
if ( V_78 -> V_332 & V_671 ) {
V_668 -= 1 ;
V_669 -= 1 ;
if ( F_10 ( & V_73 -> V_8 , V_42 ) )
V_670 = ( V_78 -> V_672 - 1 ) / 2 ;
else
V_670 = V_78 -> V_673 -
V_78 -> V_672 / 2 ;
if ( V_670 < 0 )
V_670 += V_78 -> V_672 ;
}
if ( F_45 ( V_10 ) -> V_86 > 3 )
F_46 ( F_284 ( V_82 ) , V_670 ) ;
F_46 ( F_272 ( V_82 ) ,
( V_78 -> V_344 - 1 ) |
( ( V_78 -> V_672 - 1 ) << 16 ) ) ;
F_46 ( F_274 ( V_82 ) ,
( V_78 -> V_674 - 1 ) |
( ( V_78 -> V_675 - 1 ) << 16 ) ) ;
F_46 ( F_276 ( V_82 ) ,
( V_78 -> V_673 - 1 ) |
( ( V_78 -> V_676 - 1 ) << 16 ) ) ;
F_46 ( F_278 ( V_82 ) ,
( V_78 -> V_345 - 1 ) |
( ( V_668 - 1 ) << 16 ) ) ;
F_46 ( F_280 ( V_82 ) ,
( V_78 -> V_677 - 1 ) |
( ( V_669 - 1 ) << 16 ) ) ;
F_46 ( F_282 ( V_82 ) ,
( V_78 -> V_678 - 1 ) |
( ( V_78 -> V_679 - 1 ) << 16 ) ) ;
if ( F_210 ( V_10 ) && V_82 == V_458 &&
( V_4 == V_140 || V_4 == V_359 ) )
F_46 ( F_278 ( V_4 ) , F_5 ( F_278 ( V_82 ) ) ) ;
F_46 ( F_228 ( V_4 ) ,
( ( V_73 -> V_77 . V_314 - 1 ) << 16 ) |
( V_73 -> V_77 . V_313 - 1 ) ) ;
}
static void F_467 ( struct V_73 * V_29 ,
struct V_463 * V_464 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_80 V_82 = V_464 -> V_82 ;
T_4 V_203 ;
V_203 = F_5 ( F_272 ( V_82 ) ) ;
V_464 -> V_78 . V_344 = ( V_203 & 0xffff ) + 1 ;
V_464 -> V_78 . V_672 = ( ( V_203 >> 16 ) & 0xffff ) + 1 ;
V_203 = F_5 ( F_274 ( V_82 ) ) ;
V_464 -> V_78 . V_674 = ( V_203 & 0xffff ) + 1 ;
V_464 -> V_78 . V_675 = ( ( V_203 >> 16 ) & 0xffff ) + 1 ;
V_203 = F_5 ( F_276 ( V_82 ) ) ;
V_464 -> V_78 . V_673 = ( V_203 & 0xffff ) + 1 ;
V_464 -> V_78 . V_676 = ( ( V_203 >> 16 ) & 0xffff ) + 1 ;
V_203 = F_5 ( F_278 ( V_82 ) ) ;
V_464 -> V_78 . V_345 = ( V_203 & 0xffff ) + 1 ;
V_464 -> V_78 . V_668 = ( ( V_203 >> 16 ) & 0xffff ) + 1 ;
V_203 = F_5 ( F_280 ( V_82 ) ) ;
V_464 -> V_78 . V_677 = ( V_203 & 0xffff ) + 1 ;
V_464 -> V_78 . V_669 = ( ( V_203 >> 16 ) & 0xffff ) + 1 ;
V_203 = F_5 ( F_282 ( V_82 ) ) ;
V_464 -> V_78 . V_678 = ( V_203 & 0xffff ) + 1 ;
V_464 -> V_78 . V_679 = ( ( V_203 >> 16 ) & 0xffff ) + 1 ;
if ( F_5 ( F_52 ( V_82 ) ) & V_234 ) {
V_464 -> V_78 . V_332 |= V_671 ;
V_464 -> V_78 . V_668 += 1 ;
V_464 -> V_78 . V_669 += 1 ;
}
V_203 = F_5 ( F_228 ( V_29 -> V_4 ) ) ;
V_464 -> V_313 = ( V_203 & 0xffff ) + 1 ;
V_464 -> V_314 = ( ( V_203 >> 16 ) & 0xffff ) + 1 ;
V_464 -> V_680 . V_534 = V_464 -> V_313 ;
V_464 -> V_680 . V_532 = V_464 -> V_314 ;
}
void F_468 ( struct V_343 * V_425 ,
struct V_463 * V_464 )
{
V_425 -> V_532 = V_464 -> V_78 . V_344 ;
V_425 -> V_681 = V_464 -> V_78 . V_672 ;
V_425 -> V_558 = V_464 -> V_78 . V_673 ;
V_425 -> V_682 = V_464 -> V_78 . V_676 ;
V_425 -> V_534 = V_464 -> V_78 . V_345 ;
V_425 -> V_683 = V_464 -> V_78 . V_668 ;
V_425 -> V_684 = V_464 -> V_78 . V_678 ;
V_425 -> V_685 = V_464 -> V_78 . V_679 ;
V_425 -> V_332 = V_464 -> V_78 . V_332 ;
V_425 -> clock = V_464 -> V_78 . V_79 ;
V_425 -> V_332 |= V_464 -> V_78 . V_332 ;
}
static void F_379 ( struct V_73 * V_73 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_686 ;
V_686 = 0 ;
if ( ( V_73 -> V_4 == V_131 && V_12 -> V_149 & V_150 ) ||
( V_73 -> V_4 == V_140 && V_12 -> V_149 & V_151 ) )
V_686 |= F_5 ( F_52 ( V_73 -> V_4 ) ) & V_152 ;
if ( V_73 -> V_77 . V_247 )
V_686 |= V_248 ;
if ( F_16 ( V_10 ) || F_19 ( V_10 ) ) {
if ( V_73 -> V_77 . V_687 && V_73 -> V_77 . V_553 != 30 )
V_686 |= V_688 |
V_689 ;
switch ( V_73 -> V_77 . V_553 ) {
case 18 :
V_686 |= V_690 ;
break;
case 24 :
V_686 |= V_691 ;
break;
case 30 :
V_686 |= V_692 ;
break;
default:
F_137 () ;
}
}
if ( F_469 ( V_10 ) ) {
if ( V_73 -> V_603 ) {
F_47 ( L_103 ) ;
V_686 |= V_693 ;
} else {
F_47 ( L_104 ) ;
}
}
if ( V_73 -> V_77 . V_78 . V_332 & V_671 ) {
if ( F_45 ( V_10 ) -> V_86 < 4 ||
F_10 ( & V_73 -> V_8 , V_42 ) )
V_686 |= V_694 ;
else
V_686 |= V_695 ;
} else
V_686 |= V_696 ;
if ( F_19 ( V_10 ) && V_73 -> V_77 . V_697 )
V_686 |= V_698 ;
F_46 ( F_52 ( V_73 -> V_4 ) , V_686 ) ;
F_120 ( F_52 ( V_73 -> V_4 ) ) ;
}
static int F_470 ( struct V_28 * V_29 ,
int V_253 , int V_254 ,
struct V_307 * V_76 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_18 , V_598 = 0 ;
T_2 clock , V_600 ;
bool V_699 , V_700 = false ;
bool V_701 = false , V_522 = false ;
struct V_1 * V_6 ;
const T_3 * V_30 ;
F_11 (dev, crtc, encoder) {
switch ( V_6 -> type ) {
case V_31 :
V_701 = true ;
break;
case V_245 :
V_522 = true ;
break;
}
V_598 ++ ;
}
if ( V_522 )
return 0 ;
if ( ! V_73 -> V_77 . V_702 ) {
V_18 = F_425 ( V_29 , V_598 ) ;
V_30 = F_15 ( V_29 , V_18 ) ;
V_699 = V_12 -> V_251 . V_703 ( V_30 , V_29 ,
V_73 -> V_77 . V_633 ,
V_18 , NULL , & clock ) ;
if ( ! V_699 ) {
F_122 ( L_105 ) ;
return - V_270 ;
}
if ( V_701 && V_12 -> V_704 ) {
V_700 =
V_12 -> V_251 . V_703 ( V_30 , V_29 ,
V_12 -> V_705 ,
V_18 , & clock ,
& V_600 ) ;
}
V_73 -> V_77 . V_54 . V_25 = clock . V_25 ;
V_73 -> V_77 . V_54 . V_20 = clock . V_20 ;
V_73 -> V_77 . V_54 . V_21 = clock . V_21 ;
V_73 -> V_77 . V_54 . V_23 = clock . V_23 ;
V_73 -> V_77 . V_54 . V_24 = clock . V_24 ;
}
if ( F_20 ( V_10 ) ) {
F_466 ( V_73 ,
V_700 ? & V_600 : NULL ,
V_598 ) ;
} else if ( F_18 ( V_10 ) ) {
F_455 ( V_73 ) ;
} else if ( F_19 ( V_10 ) ) {
F_448 ( V_73 ) ;
} else {
F_462 ( V_73 ,
V_700 ? & V_600 : NULL ,
V_598 ) ;
}
return 0 ;
}
static void F_471 ( struct V_73 * V_29 ,
struct V_463 * V_464 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_203 ;
if ( F_45 ( V_10 ) -> V_86 <= 3 && ( F_132 ( V_10 ) || ! F_119 ( V_10 ) ) )
return;
V_203 = F_5 ( V_467 ) ;
if ( ! ( V_203 & V_468 ) )
return;
if ( F_45 ( V_10 ) -> V_86 < 4 ) {
if ( V_29 -> V_4 != V_140 )
return;
} else {
if ( ( V_203 & V_706 ) != ( V_29 -> V_4 << V_707 ) )
return;
}
V_464 -> V_465 . V_466 = V_203 ;
V_464 -> V_465 . V_470 = F_5 ( V_469 ) ;
if ( F_45 ( V_10 ) -> V_86 < 5 )
V_464 -> V_465 . V_708 =
F_5 ( V_142 ) & V_709 ;
}
static void F_472 ( struct V_73 * V_29 ,
struct V_463 * V_464 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_464 -> V_82 ;
T_2 clock ;
T_1 V_615 ;
int V_18 = 100000 ;
if ( ! ( V_464 -> V_199 . V_54 & V_112 ) )
return;
F_59 ( & V_12 -> V_113 ) ;
V_615 = F_126 ( V_12 , V_4 , F_450 ( V_4 ) ) ;
F_61 ( & V_12 -> V_113 ) ;
clock . V_20 = ( V_615 >> V_624 ) & 7 ;
clock . V_21 = V_615 & V_625 ;
clock . V_25 = ( V_615 >> V_628 ) & 0xf ;
clock . V_23 = ( V_615 >> V_626 ) & 7 ;
clock . V_24 = ( V_615 >> V_627 ) & 0x1f ;
F_8 ( V_18 , & clock ) ;
V_464 -> V_633 = clock . V_27 / 5 ;
}
static void F_473 ( struct V_73 * V_29 ,
struct V_295 * V_296 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_110 , V_8 , V_279 ;
int V_4 = V_29 -> V_4 , V_153 = V_29 -> V_153 ;
int V_710 , V_302 ;
int V_711 ;
V_29 -> V_8 . V_75 -> V_76 = F_474 ( sizeof( struct V_712 ) , V_713 ) ;
if ( ! V_29 -> V_8 . V_75 -> V_76 ) {
F_47 ( L_106 ) ;
return;
}
V_110 = F_5 ( F_82 ( V_153 ) ) ;
if ( F_45 ( V_10 ) -> V_86 >= 4 )
if ( V_110 & V_320 )
V_296 -> V_257 = true ;
V_302 = V_110 & V_714 ;
V_710 = F_187 ( V_302 ) ;
V_29 -> V_8 . V_75 -> V_76 -> V_302 = V_710 ;
V_29 -> V_8 . V_75 -> V_76 -> V_583 =
F_201 ( V_710 , 0 ) * 8 ;
if ( F_45 ( V_10 ) -> V_86 >= 4 ) {
if ( V_296 -> V_257 )
V_279 = F_5 ( F_207 ( V_153 ) ) ;
else
V_279 = F_5 ( F_208 ( V_153 ) ) ;
V_8 = F_5 ( F_164 ( V_153 ) ) & 0xfffff000 ;
} else {
V_8 = F_5 ( F_165 ( V_153 ) ) ;
}
V_296 -> V_8 = V_8 ;
V_110 = F_5 ( F_228 ( V_4 ) ) ;
V_29 -> V_8 . V_75 -> V_76 -> V_303 = ( ( V_110 >> 16 ) & 0xfff ) + 1 ;
V_29 -> V_8 . V_75 -> V_76 -> V_256 = ( ( V_110 >> 0 ) & 0xfff ) + 1 ;
V_110 = F_5 ( F_206 ( V_4 ) ) ;
V_29 -> V_8 . V_75 -> V_76 -> V_301 [ 0 ] = V_110 & 0xffffffc0 ;
V_711 = F_172 ( V_10 , V_29 -> V_8 . V_75 -> V_76 -> V_256 ,
V_296 -> V_257 ) ;
V_296 -> V_299 = F_475 ( V_29 -> V_8 . V_75 -> V_76 -> V_301 [ 0 ] *
V_711 ) ;
F_47 ( L_107 ,
V_4 , V_153 , V_29 -> V_8 . V_75 -> V_76 -> V_303 ,
V_29 -> V_8 . V_75 -> V_76 -> V_256 ,
V_29 -> V_8 . V_75 -> V_76 -> V_583 , V_8 ,
V_29 -> V_8 . V_75 -> V_76 -> V_301 [ 0 ] ,
V_296 -> V_299 ) ;
}
static void F_476 ( struct V_73 * V_29 ,
struct V_463 * V_464 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_464 -> V_82 ;
enum V_202 V_96 = F_125 ( V_4 ) ;
T_2 clock ;
T_1 V_715 , V_716 , V_717 , V_718 ;
int V_18 = 100000 ;
F_59 ( & V_12 -> V_113 ) ;
V_715 = F_126 ( V_12 , V_4 , F_456 ( V_96 ) ) ;
V_716 = F_126 ( V_12 , V_4 , F_457 ( V_96 ) ) ;
V_717 = F_126 ( V_12 , V_4 , F_458 ( V_96 ) ) ;
V_718 = F_126 ( V_12 , V_4 , F_459 ( V_96 ) ) ;
F_61 ( & V_12 -> V_113 ) ;
clock . V_20 = ( V_717 & 0x7 ) == V_641 ? 2 : 0 ;
clock . V_21 = ( ( V_716 & 0xff ) << 22 ) | ( V_718 & 0x3fffff ) ;
clock . V_25 = ( V_717 >> V_642 ) & 0xf ;
clock . V_23 = ( V_715 >> V_638 ) & 0x7 ;
clock . V_24 = ( V_715 >> V_639 ) & 0x1f ;
F_24 ( V_18 , & clock ) ;
V_464 -> V_633 = clock . V_27 / 5 ;
}
static bool F_477 ( struct V_73 * V_29 ,
struct V_463 * V_464 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_203 ;
if ( ! F_79 ( V_12 ,
F_357 ( V_29 -> V_4 ) ) )
return false ;
V_464 -> V_82 = (enum V_80 ) V_29 -> V_4 ;
V_464 -> V_117 = V_430 ;
V_203 = F_5 ( F_52 ( V_29 -> V_4 ) ) ;
if ( ! ( V_203 & V_152 ) )
return false ;
if ( F_16 ( V_10 ) || F_19 ( V_10 ) ) {
switch ( V_203 & V_232 ) {
case V_690 :
V_464 -> V_553 = 18 ;
break;
case V_691 :
V_464 -> V_553 = 24 ;
break;
case V_692 :
V_464 -> V_553 = 30 ;
break;
default:
break;
}
}
if ( F_19 ( V_10 ) && ( V_203 & V_698 ) )
V_464 -> V_697 = true ;
if ( F_45 ( V_10 ) -> V_86 < 4 )
V_464 -> V_247 = V_203 & V_248 ;
F_467 ( V_29 , V_464 ) ;
F_471 ( V_29 , V_464 ) ;
if ( F_45 ( V_10 ) -> V_86 >= 4 ) {
V_203 = F_5 ( F_123 ( V_29 -> V_4 ) ) ;
V_464 -> V_459 =
( ( V_203 & V_719 )
>> V_614 ) + 1 ;
V_464 -> V_199 . V_201 = V_203 ;
} else if ( F_463 ( V_10 ) || F_464 ( V_10 ) || F_465 ( V_10 ) ) {
V_203 = F_5 ( F_57 ( V_29 -> V_4 ) ) ;
V_464 -> V_459 =
( ( V_203 & V_720 )
>> V_652 ) + 1 ;
} else {
V_464 -> V_459 = 1 ;
}
V_464 -> V_199 . V_54 = F_5 ( F_57 ( V_29 -> V_4 ) ) ;
if ( ! F_19 ( V_10 ) ) {
if ( F_132 ( V_10 ) )
V_464 -> V_199 . V_54 &= ~ V_206 ;
V_464 -> V_199 . V_524 = F_5 ( F_382 ( V_29 -> V_4 ) ) ;
V_464 -> V_199 . V_525 = F_5 ( F_383 ( V_29 -> V_4 ) ) ;
} else {
V_464 -> V_199 . V_54 &= ~ ( V_200 |
V_220 |
V_219 ) ;
}
if ( F_18 ( V_10 ) )
F_476 ( V_29 , V_464 ) ;
else if ( F_19 ( V_10 ) )
F_472 ( V_29 , V_464 ) ;
else
F_478 ( V_29 , V_464 ) ;
return true ;
}
static void F_479 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
T_1 V_110 , V_721 ;
bool V_722 = false ;
bool V_723 = false ;
bool V_724 = false ;
bool V_725 = false ;
bool V_726 = false ;
F_480 (dev, encoder) {
switch ( V_6 -> type ) {
case V_31 :
V_724 = true ;
V_722 = true ;
break;
case V_347 :
V_724 = true ;
if ( F_354 ( & V_6 -> V_8 ) -> V_96 == V_472 )
V_723 = true ;
break;
}
}
if ( F_54 ( V_10 ) ) {
V_725 = V_12 -> V_595 . V_727 ;
V_726 = V_725 ;
} else {
V_725 = false ;
V_726 = true ;
}
F_47 ( L_108 ,
V_724 , V_722 , V_725 ) ;
V_110 = F_5 ( V_163 ) ;
V_721 = V_110 ;
V_721 &= ~ V_165 ;
if ( V_725 )
V_721 |= V_728 ;
else
V_721 |= V_729 ;
V_721 &= ~ V_164 ;
V_721 &= ~ V_730 ;
V_721 &= ~ V_731 ;
if ( V_724 ) {
V_721 |= V_732 ;
if ( F_424 ( V_12 ) && V_726 )
V_721 |= V_731 ;
if ( V_723 ) {
if ( F_424 ( V_12 ) && V_726 )
V_721 |= V_733 ;
else
V_721 |= V_734 ;
} else
V_721 |= V_735 ;
} else {
V_721 |= V_736 ;
V_721 |= V_735 ;
}
if ( V_721 == V_110 )
return;
V_110 &= ~ V_165 ;
if ( V_725 )
V_110 |= V_728 ;
else
V_110 |= V_729 ;
if ( V_724 ) {
V_110 &= ~ V_164 ;
V_110 |= V_732 ;
if ( F_424 ( V_12 ) && V_726 ) {
F_47 ( L_109 ) ;
V_110 |= V_731 ;
} else
V_110 &= ~ V_731 ;
F_46 ( V_163 , V_110 ) ;
F_120 ( V_163 ) ;
F_121 ( 200 ) ;
V_110 &= ~ V_730 ;
if ( V_723 ) {
if ( F_424 ( V_12 ) && V_726 ) {
F_47 ( L_110 ) ;
V_110 |= V_733 ;
} else
V_110 |= V_734 ;
} else
V_110 |= V_735 ;
F_46 ( V_163 , V_110 ) ;
F_120 ( V_163 ) ;
F_121 ( 200 ) ;
} else {
F_47 ( L_111 ) ;
V_110 &= ~ V_730 ;
V_110 |= V_735 ;
F_46 ( V_163 , V_110 ) ;
F_120 ( V_163 ) ;
F_121 ( 200 ) ;
V_110 &= ~ V_164 ;
V_110 |= V_736 ;
V_110 &= ~ V_731 ;
F_46 ( V_163 , V_110 ) ;
F_120 ( V_163 ) ;
F_121 ( 200 ) ;
}
F_118 ( V_110 != V_721 ) ;
}
static void F_481 ( struct V_11 * V_12 )
{
T_4 V_203 ;
V_203 = F_5 ( V_737 ) ;
V_203 |= V_738 ;
F_46 ( V_737 , V_203 ) ;
if ( F_482 ( F_5 ( V_737 ) &
V_739 , 100 ) )
F_122 ( L_112 ) ;
V_203 = F_5 ( V_737 ) ;
V_203 &= ~ V_738 ;
F_46 ( V_737 , V_203 ) ;
if ( F_482 ( ( F_5 ( V_737 ) &
V_739 ) == 0 , 100 ) )
F_122 ( L_113 ) ;
}
static void F_483 ( struct V_11 * V_12 )
{
T_4 V_203 ;
V_203 = F_265 ( V_12 , 0x8008 , V_740 ) ;
V_203 &= ~ ( 0xFF << 24 ) ;
V_203 |= ( 0x12 << 24 ) ;
F_264 ( V_12 , 0x8008 , V_203 , V_740 ) ;
V_203 = F_265 ( V_12 , 0x2008 , V_740 ) ;
V_203 |= ( 1 << 11 ) ;
F_264 ( V_12 , 0x2008 , V_203 , V_740 ) ;
V_203 = F_265 ( V_12 , 0x2108 , V_740 ) ;
V_203 |= ( 1 << 11 ) ;
F_264 ( V_12 , 0x2108 , V_203 , V_740 ) ;
V_203 = F_265 ( V_12 , 0x206C , V_740 ) ;
V_203 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_264 ( V_12 , 0x206C , V_203 , V_740 ) ;
V_203 = F_265 ( V_12 , 0x216C , V_740 ) ;
V_203 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_264 ( V_12 , 0x216C , V_203 , V_740 ) ;
V_203 = F_265 ( V_12 , 0x2080 , V_740 ) ;
V_203 &= ~ ( 7 << 13 ) ;
V_203 |= ( 5 << 13 ) ;
F_264 ( V_12 , 0x2080 , V_203 , V_740 ) ;
V_203 = F_265 ( V_12 , 0x2180 , V_740 ) ;
V_203 &= ~ ( 7 << 13 ) ;
V_203 |= ( 5 << 13 ) ;
F_264 ( V_12 , 0x2180 , V_203 , V_740 ) ;
V_203 = F_265 ( V_12 , 0x208C , V_740 ) ;
V_203 &= ~ 0xFF ;
V_203 |= 0x1C ;
F_264 ( V_12 , 0x208C , V_203 , V_740 ) ;
V_203 = F_265 ( V_12 , 0x218C , V_740 ) ;
V_203 &= ~ 0xFF ;
V_203 |= 0x1C ;
F_264 ( V_12 , 0x218C , V_203 , V_740 ) ;
V_203 = F_265 ( V_12 , 0x2098 , V_740 ) ;
V_203 &= ~ ( 0xFF << 16 ) ;
V_203 |= ( 0x1C << 16 ) ;
F_264 ( V_12 , 0x2098 , V_203 , V_740 ) ;
V_203 = F_265 ( V_12 , 0x2198 , V_740 ) ;
V_203 &= ~ ( 0xFF << 16 ) ;
V_203 |= ( 0x1C << 16 ) ;
F_264 ( V_12 , 0x2198 , V_203 , V_740 ) ;
V_203 = F_265 ( V_12 , 0x20C4 , V_740 ) ;
V_203 |= ( 1 << 27 ) ;
F_264 ( V_12 , 0x20C4 , V_203 , V_740 ) ;
V_203 = F_265 ( V_12 , 0x21C4 , V_740 ) ;
V_203 |= ( 1 << 27 ) ;
F_264 ( V_12 , 0x21C4 , V_203 , V_740 ) ;
V_203 = F_265 ( V_12 , 0x20EC , V_740 ) ;
V_203 &= ~ ( 0xF << 28 ) ;
V_203 |= ( 4 << 28 ) ;
F_264 ( V_12 , 0x20EC , V_203 , V_740 ) ;
V_203 = F_265 ( V_12 , 0x21EC , V_740 ) ;
V_203 &= ~ ( 0xF << 28 ) ;
V_203 |= ( 4 << 28 ) ;
F_264 ( V_12 , 0x21EC , V_203 , V_740 ) ;
}
static void F_484 ( struct V_9 * V_10 , bool V_741 ,
bool V_742 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_88 , V_203 ;
if ( F_41 ( V_742 && ! V_741 , L_114 ) )
V_741 = true ;
if ( F_41 ( V_12 -> V_743 == V_744 &&
V_742 , L_115 ) )
V_742 = false ;
F_59 ( & V_12 -> V_113 ) ;
V_203 = F_265 ( V_12 , V_745 , V_401 ) ;
V_203 &= ~ V_402 ;
V_203 |= V_746 ;
F_264 ( V_12 , V_745 , V_203 , V_401 ) ;
F_121 ( 24 ) ;
if ( V_741 ) {
V_203 = F_265 ( V_12 , V_745 , V_401 ) ;
V_203 &= ~ V_746 ;
F_264 ( V_12 , V_745 , V_203 , V_401 ) ;
if ( V_742 ) {
F_481 ( V_12 ) ;
F_483 ( V_12 ) ;
}
}
V_88 = ( V_12 -> V_743 == V_744 ) ?
V_747 : V_748 ;
V_203 = F_265 ( V_12 , V_88 , V_401 ) ;
V_203 |= V_749 ;
F_264 ( V_12 , V_88 , V_203 , V_401 ) ;
F_61 ( & V_12 -> V_113 ) ;
}
static void F_485 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_88 , V_203 ;
F_59 ( & V_12 -> V_113 ) ;
V_88 = ( V_12 -> V_743 == V_744 ) ?
V_747 : V_748 ;
V_203 = F_265 ( V_12 , V_88 , V_401 ) ;
V_203 &= ~ V_749 ;
F_264 ( V_12 , V_88 , V_203 , V_401 ) ;
V_203 = F_265 ( V_12 , V_745 , V_401 ) ;
if ( ! ( V_203 & V_402 ) ) {
if ( ! ( V_203 & V_746 ) ) {
V_203 |= V_746 ;
F_264 ( V_12 , V_745 , V_203 , V_401 ) ;
F_121 ( 32 ) ;
}
V_203 |= V_402 ;
F_264 ( V_12 , V_745 , V_203 , V_401 ) ;
}
F_61 ( & V_12 -> V_113 ) ;
}
static void F_486 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
bool V_750 = false ;
F_480 (dev, encoder) {
switch ( V_6 -> type ) {
case V_40 :
V_750 = true ;
break;
}
}
if ( V_750 )
F_484 ( V_10 , true , true ) ;
else
F_485 ( V_10 ) ;
}
void F_487 ( struct V_9 * V_10 )
{
if ( F_54 ( V_10 ) || F_96 ( V_10 ) )
F_479 ( V_10 ) ;
else if ( F_158 ( V_10 ) )
F_486 ( V_10 ) ;
}
static int F_488 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
int V_598 = 0 ;
bool V_701 = false ;
F_11 (dev, crtc, encoder) {
switch ( V_6 -> type ) {
case V_31 :
V_701 = true ;
break;
}
V_598 ++ ;
}
if ( V_701 && F_424 ( V_12 ) && V_598 < 2 ) {
F_47 ( L_102 ,
V_12 -> V_595 . V_599 ) ;
return V_12 -> V_595 . V_599 ;
}
return 120000 ;
}
static void F_326 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_4 V_110 ;
V_110 = 0 ;
switch ( V_73 -> V_77 . V_553 ) {
case 18 :
V_110 |= V_690 ;
break;
case 24 :
V_110 |= V_691 ;
break;
case 30 :
V_110 |= V_692 ;
break;
case 36 :
V_110 |= V_751 ;
break;
default:
F_137 () ;
}
if ( V_73 -> V_77 . V_687 )
V_110 |= ( V_688 | V_689 ) ;
if ( V_73 -> V_77 . V_78 . V_332 & V_671 )
V_110 |= V_235 ;
else
V_110 |= V_696 ;
if ( V_73 -> V_77 . V_697 )
V_110 |= V_698 ;
F_46 ( F_52 ( V_4 ) , V_110 ) ;
F_120 ( F_52 ( V_4 ) ) ;
}
static void F_336 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_6 V_752 = 0x7800 ;
if ( V_73 -> V_77 . V_697 )
V_752 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_46 ( F_489 ( V_4 ) , V_752 << 16 ) ;
F_46 ( F_490 ( V_4 ) , 0 ) ;
F_46 ( F_491 ( V_4 ) , V_752 ) ;
F_46 ( F_492 ( V_4 ) , 0 ) ;
F_46 ( F_493 ( V_4 ) , 0 ) ;
F_46 ( F_494 ( V_4 ) , V_752 << 16 ) ;
F_46 ( F_495 ( V_4 ) , 0 ) ;
F_46 ( F_496 ( V_4 ) , 0 ) ;
F_46 ( F_497 ( V_4 ) , 0 ) ;
if ( F_45 ( V_10 ) -> V_86 > 6 ) {
T_6 V_753 = 0 ;
if ( V_73 -> V_77 . V_697 )
V_753 = ( 16 * ( 1 << 12 ) / 255 ) & 0x1fff ;
F_46 ( F_498 ( V_4 ) , V_753 ) ;
F_46 ( F_499 ( V_4 ) , V_753 ) ;
F_46 ( F_500 ( V_4 ) , V_753 ) ;
F_46 ( F_501 ( V_4 ) , 0 ) ;
} else {
T_4 V_425 = V_754 ;
if ( V_73 -> V_77 . V_697 )
V_425 |= V_755 ;
F_46 ( F_501 ( V_4 ) , V_425 ) ;
}
}
static void F_335 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_4 V_4 = V_73 -> V_4 ;
enum V_80 V_82 = V_73 -> V_77 . V_82 ;
T_4 V_110 ;
V_110 = 0 ;
if ( F_210 ( V_10 ) && V_73 -> V_77 . V_687 )
V_110 |= ( V_688 | V_689 ) ;
if ( V_73 -> V_77 . V_78 . V_332 & V_671 )
V_110 |= V_235 ;
else
V_110 |= V_696 ;
F_46 ( F_52 ( V_82 ) , V_110 ) ;
F_120 ( F_52 ( V_82 ) ) ;
F_46 ( F_312 ( V_73 -> V_4 ) , V_756 ) ;
F_120 ( F_312 ( V_73 -> V_4 ) ) ;
if ( F_168 ( V_10 ) ) {
V_110 = 0 ;
switch ( V_73 -> V_77 . V_553 ) {
case 18 :
V_110 |= V_757 ;
break;
case 24 :
V_110 |= V_758 ;
break;
case 30 :
V_110 |= V_759 ;
break;
case 36 :
V_110 |= V_760 ;
break;
default:
F_137 () ;
}
if ( V_73 -> V_77 . V_687 )
V_110 |= V_761 | V_762 ;
F_46 ( F_502 ( V_4 ) , V_110 ) ;
}
}
static bool F_503 ( struct V_28 * V_29 ,
T_2 * clock ,
bool * V_700 ,
T_2 * V_600 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 ;
int V_18 ;
const T_3 * V_30 ;
bool V_264 , V_701 = false ;
F_11 (dev, crtc, intel_encoder) {
switch ( V_1 -> type ) {
case V_31 :
V_701 = true ;
break;
}
}
V_18 = F_488 ( V_29 ) ;
V_30 = F_15 ( V_29 , V_18 ) ;
V_264 = V_12 -> V_251 . V_703 ( V_30 , V_29 ,
F_35 ( V_29 ) -> V_77 . V_633 ,
V_18 , NULL , clock ) ;
if ( ! V_264 )
return false ;
if ( V_701 && V_12 -> V_704 ) {
* V_700 =
V_12 -> V_251 . V_703 ( V_30 , V_29 ,
V_12 -> V_705 ,
V_18 , clock ,
V_600 ) ;
}
return true ;
}
int F_406 ( int V_763 , int V_549 , int V_764 )
{
T_1 V_765 = V_763 * V_764 * 21 / 20 ;
return F_364 ( V_765 , V_549 * 8 ) ;
}
static bool F_504 ( struct V_54 * V_54 , int V_766 )
{
return F_22 ( V_54 ) < V_766 * V_54 -> V_25 ;
}
static T_4 F_505 ( struct V_73 * V_73 ,
T_1 * V_601 ,
T_2 * V_600 , T_1 * V_602 )
{
struct V_28 * V_29 = & V_73 -> V_8 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 ;
T_4 V_54 ;
int V_766 , V_598 = 0 ;
bool V_701 = false , V_649 = false ;
F_11 (dev, crtc, intel_encoder) {
switch ( V_1 -> type ) {
case V_31 :
V_701 = true ;
break;
case V_42 :
case V_39 :
V_649 = true ;
break;
}
V_598 ++ ;
}
V_766 = 21 ;
if ( V_701 ) {
if ( ( F_424 ( V_12 ) &&
V_12 -> V_595 . V_599 == 100000 ) ||
( F_54 ( V_10 ) && F_13 ( V_10 ) ) )
V_766 = 25 ;
} else if ( V_73 -> V_77 . V_662 )
V_766 = 20 ;
if ( F_504 ( & V_73 -> V_77 . V_54 , V_766 ) )
* V_601 |= V_767 ;
if ( V_602 && ( V_600 -> V_19 < V_766 * V_600 -> V_25 ) )
* V_602 |= V_767 ;
V_54 = 0 ;
if ( V_701 )
V_54 |= V_650 ;
else
V_54 |= V_651 ;
V_54 |= ( V_73 -> V_77 . V_459 - 1 )
<< V_768 ;
if ( V_649 )
V_54 |= V_653 ;
if ( V_73 -> V_77 . V_453 )
V_54 |= V_653 ;
V_54 |= ( 1 << ( V_73 -> V_77 . V_54 . V_23 - 1 ) ) << V_655 ;
V_54 |= ( 1 << ( V_73 -> V_77 . V_54 . V_23 - 1 ) ) << V_656 ;
switch ( V_73 -> V_77 . V_54 . V_24 ) {
case 5 :
V_54 |= V_657 ;
break;
case 7 :
V_54 |= V_658 ;
break;
case 10 :
V_54 |= V_659 ;
break;
case 14 :
V_54 |= V_660 ;
break;
}
if ( V_701 && F_424 ( V_12 ) && V_598 < 2 )
V_54 |= V_664 ;
else
V_54 |= V_665 ;
return V_54 | V_112 ;
}
static int F_506 ( struct V_28 * V_29 ,
int V_253 , int V_254 ,
struct V_307 * V_76 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_598 = 0 ;
T_2 clock , V_600 ;
T_1 V_54 = 0 , V_601 = 0 , V_602 = 0 ;
bool V_699 , V_700 = false ;
bool V_701 = false ;
struct V_1 * V_6 ;
struct V_116 * V_119 ;
F_11 (dev, crtc, encoder) {
switch ( V_6 -> type ) {
case V_31 :
V_701 = true ;
break;
}
V_598 ++ ;
}
F_41 ( ! ( F_54 ( V_10 ) || F_96 ( V_10 ) ) ,
L_116 , F_507 ( V_10 ) ) ;
V_699 = F_503 ( V_29 , & clock ,
& V_700 , & V_600 ) ;
if ( ! V_699 && ! V_73 -> V_77 . V_702 ) {
F_122 ( L_105 ) ;
return - V_270 ;
}
if ( ! V_73 -> V_77 . V_702 ) {
V_73 -> V_77 . V_54 . V_25 = clock . V_25 ;
V_73 -> V_77 . V_54 . V_20 = clock . V_20 ;
V_73 -> V_77 . V_54 . V_21 = clock . V_21 ;
V_73 -> V_77 . V_54 . V_23 = clock . V_23 ;
V_73 -> V_77 . V_54 . V_24 = clock . V_24 ;
}
if ( V_73 -> V_77 . V_246 ) {
V_601 = F_427 ( & V_73 -> V_77 . V_54 ) ;
if ( V_700 )
V_602 = F_427 ( & V_600 ) ;
V_54 = F_505 ( V_73 ,
& V_601 , & V_600 ,
V_700 ? & V_602 : NULL ) ;
V_73 -> V_77 . V_199 . V_54 = V_54 ;
V_73 -> V_77 . V_199 . V_524 = V_601 ;
if ( V_700 )
V_73 -> V_77 . V_199 . V_525 = V_602 ;
else
V_73 -> V_77 . V_199 . V_525 = V_601 ;
V_119 = F_295 ( V_73 ) ;
if ( V_119 == NULL ) {
F_140 ( L_117 ,
F_42 ( V_73 -> V_4 ) ) ;
return - V_270 ;
}
} else
F_294 ( V_73 ) ;
if ( V_701 && V_700 && V_341 . V_604 )
V_73 -> V_603 = true ;
else
V_73 -> V_603 = false ;
return 0 ;
}
static void F_508 ( struct V_73 * V_29 ,
struct V_587 * V_588 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
V_588 -> V_592 = F_5 ( F_435 ( V_4 ) ) ;
V_588 -> V_593 = F_5 ( F_436 ( V_4 ) ) ;
V_588 -> V_590 = F_5 ( F_432 ( V_4 ) )
& ~ V_414 ;
V_588 -> V_591 = F_5 ( F_434 ( V_4 ) ) ;
V_588 -> V_589 = ( ( F_5 ( F_432 ( V_4 ) )
& V_414 ) >> V_769 ) + 1 ;
}
static void F_509 ( struct V_73 * V_29 ,
enum V_80 V_80 ,
struct V_587 * V_588 ,
struct V_587 * V_607 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
if ( F_45 ( V_10 ) -> V_86 >= 5 ) {
V_588 -> V_592 = F_5 ( F_438 ( V_80 ) ) ;
V_588 -> V_593 = F_5 ( F_439 ( V_80 ) ) ;
V_588 -> V_590 = F_5 ( F_289 ( V_80 ) )
& ~ V_414 ;
V_588 -> V_591 = F_5 ( F_437 ( V_80 ) ) ;
V_588 -> V_589 = ( ( F_5 ( F_289 ( V_80 ) )
& V_414 ) >> V_769 ) + 1 ;
if ( V_607 && F_45 ( V_10 ) -> V_86 < 8 &&
V_29 -> V_77 . V_608 ) {
V_607 -> V_592 = F_5 ( F_442 ( V_80 ) ) ;
V_607 -> V_593 = F_5 ( F_443 ( V_80 ) ) ;
V_607 -> V_590 = F_5 ( F_440 ( V_80 ) )
& ~ V_414 ;
V_607 -> V_591 = F_5 ( F_441 ( V_80 ) ) ;
V_607 -> V_589 = ( ( F_5 ( F_440 ( V_80 ) )
& V_414 ) >> V_769 ) + 1 ;
}
} else {
V_588 -> V_592 = F_5 ( F_446 ( V_4 ) ) ;
V_588 -> V_593 = F_5 ( F_447 ( V_4 ) ) ;
V_588 -> V_590 = F_5 ( F_444 ( V_4 ) )
& ~ V_414 ;
V_588 -> V_591 = F_5 ( F_445 ( V_4 ) ) ;
V_588 -> V_589 = ( ( F_5 ( F_444 ( V_4 ) )
& V_414 ) >> V_769 ) + 1 ;
}
}
void F_510 ( struct V_73 * V_29 ,
struct V_463 * V_464 )
{
if ( V_29 -> V_77 . V_246 )
F_508 ( V_29 , & V_464 -> V_609 ) ;
else
F_509 ( V_29 , V_464 -> V_82 ,
& V_464 -> V_609 ,
& V_464 -> V_610 ) ;
}
static void F_511 ( struct V_73 * V_29 ,
struct V_463 * V_464 )
{
F_509 ( V_29 , V_464 -> V_82 ,
& V_464 -> V_454 , NULL ) ;
}
static void F_512 ( struct V_73 * V_29 ,
struct V_463 * V_464 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_203 ;
V_203 = F_5 ( F_229 ( V_29 -> V_4 ) ) ;
if ( V_203 & V_434 ) {
V_464 -> V_346 . V_108 = true ;
V_464 -> V_346 . V_436 = F_5 ( F_230 ( V_29 -> V_4 ) ) ;
V_464 -> V_346 . V_299 = F_5 ( F_231 ( V_29 -> V_4 ) ) ;
if ( F_513 ( V_10 ) ) {
F_3 ( ( V_203 & V_770 ) !=
F_298 ( V_29 -> V_4 ) ) ;
}
}
}
static void F_514 ( struct V_73 * V_29 ,
struct V_295 * V_296 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_110 , V_8 , V_279 ;
int V_4 = V_29 -> V_4 , V_153 = V_29 -> V_153 ;
int V_710 , V_302 ;
int V_711 ;
V_29 -> V_8 . V_75 -> V_76 = F_474 ( sizeof( struct V_712 ) , V_713 ) ;
if ( ! V_29 -> V_8 . V_75 -> V_76 ) {
F_47 ( L_106 ) ;
return;
}
V_110 = F_5 ( F_82 ( V_153 ) ) ;
if ( F_45 ( V_10 ) -> V_86 >= 4 )
if ( V_110 & V_320 )
V_296 -> V_257 = true ;
V_302 = V_110 & V_714 ;
V_710 = F_187 ( V_302 ) ;
V_29 -> V_8 . V_75 -> V_76 -> V_302 = V_710 ;
V_29 -> V_8 . V_75 -> V_76 -> V_583 =
F_201 ( V_710 , 0 ) * 8 ;
V_8 = F_5 ( F_164 ( V_153 ) ) & 0xfffff000 ;
if ( F_210 ( V_10 ) || F_168 ( V_10 ) ) {
V_279 = F_5 ( F_211 ( V_153 ) ) ;
} else {
if ( V_296 -> V_257 )
V_279 = F_5 ( F_207 ( V_153 ) ) ;
else
V_279 = F_5 ( F_208 ( V_153 ) ) ;
}
V_296 -> V_8 = V_8 ;
V_110 = F_5 ( F_228 ( V_4 ) ) ;
V_29 -> V_8 . V_75 -> V_76 -> V_303 = ( ( V_110 >> 16 ) & 0xfff ) + 1 ;
V_29 -> V_8 . V_75 -> V_76 -> V_256 = ( ( V_110 >> 0 ) & 0xfff ) + 1 ;
V_110 = F_5 ( F_206 ( V_4 ) ) ;
V_29 -> V_8 . V_75 -> V_76 -> V_301 [ 0 ] = V_110 & 0xffffffc0 ;
V_711 = F_172 ( V_10 , V_29 -> V_8 . V_75 -> V_76 -> V_256 ,
V_296 -> V_257 ) ;
V_296 -> V_299 = F_475 ( V_29 -> V_8 . V_75 -> V_76 -> V_301 [ 0 ] *
V_711 ) ;
F_47 ( L_107 ,
V_4 , V_153 , V_29 -> V_8 . V_75 -> V_76 -> V_303 ,
V_29 -> V_8 . V_75 -> V_76 -> V_256 ,
V_29 -> V_8 . V_75 -> V_76 -> V_583 , V_8 ,
V_29 -> V_8 . V_75 -> V_76 -> V_301 [ 0 ] ,
V_296 -> V_299 ) ;
}
static bool F_515 ( struct V_73 * V_29 ,
struct V_463 * V_464 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_203 ;
if ( ! F_79 ( V_12 ,
F_357 ( V_29 -> V_4 ) ) )
return false ;
V_464 -> V_82 = (enum V_80 ) V_29 -> V_4 ;
V_464 -> V_117 = V_430 ;
V_203 = F_5 ( F_52 ( V_29 -> V_4 ) ) ;
if ( ! ( V_203 & V_152 ) )
return false ;
switch ( V_203 & V_232 ) {
case V_690 :
V_464 -> V_553 = 18 ;
break;
case V_691 :
V_464 -> V_553 = 24 ;
break;
case V_692 :
V_464 -> V_553 = 30 ;
break;
case V_751 :
V_464 -> V_553 = 36 ;
break;
default:
break;
}
if ( V_203 & V_698 )
V_464 -> V_697 = true ;
if ( F_5 ( F_98 ( V_29 -> V_4 ) ) & V_167 ) {
struct V_116 * V_119 ;
V_464 -> V_246 = true ;
V_203 = F_5 ( F_69 ( V_29 -> V_4 ) ) ;
V_464 -> V_366 = ( ( V_365 & V_203 ) >>
V_771 ) + 1 ;
F_511 ( V_29 , V_464 ) ;
if ( F_54 ( V_12 -> V_10 ) ) {
V_464 -> V_117 =
(enum V_431 ) V_29 -> V_4 ;
} else {
V_203 = F_5 ( V_417 ) ;
if ( V_203 & F_291 ( V_29 -> V_4 ) )
V_464 -> V_117 = V_418 ;
else
V_464 -> V_117 = V_772 ;
}
V_119 = & V_12 -> V_118 [ V_464 -> V_117 ] ;
F_3 ( ! V_119 -> V_122 ( V_12 , V_119 ,
& V_464 -> V_199 ) ) ;
V_203 = V_464 -> V_199 . V_54 ;
V_464 -> V_459 =
( ( V_203 & V_773 )
>> V_768 ) + 1 ;
F_516 ( V_29 , V_464 ) ;
} else {
V_464 -> V_459 = 1 ;
}
F_467 ( V_29 , V_464 ) ;
F_512 ( V_29 , V_464 ) ;
return true ;
}
static void F_517 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_73 * V_29 ;
F_130 (dev, crtc)
F_41 ( V_29 -> V_74 , L_118 ,
F_42 ( V_29 -> V_4 ) ) ;
F_41 ( F_5 ( V_774 ) , L_119 ) ;
F_41 ( F_5 ( V_775 ) & V_776 , L_120 ) ;
F_41 ( F_5 ( V_777 ) & V_778 , L_121 ) ;
F_41 ( F_5 ( V_779 ) & V_778 , L_122 ) ;
F_41 ( F_5 ( V_780 ) & V_781 , L_123 ) ;
F_41 ( F_5 ( V_782 ) & V_783 ,
L_124 ) ;
if ( F_210 ( V_10 ) )
F_41 ( F_5 ( V_784 ) & V_783 ,
L_125 ) ;
F_41 ( F_5 ( V_785 ) & V_786 ,
L_126 ) ;
F_41 ( F_5 ( V_787 ) & V_788 ,
L_127 ) ;
F_41 ( F_5 ( V_789 ) & V_790 , L_128 ) ;
F_41 ( F_518 ( V_12 ) , L_129 ) ;
}
static T_4 F_519 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
if ( F_210 ( V_10 ) )
return F_5 ( V_791 ) ;
else
return F_5 ( V_792 ) ;
}
static void F_520 ( struct V_11 * V_12 , T_4 V_110 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
if ( F_210 ( V_10 ) ) {
F_59 ( & V_12 -> V_439 . V_440 ) ;
if ( F_306 ( V_12 , V_793 ,
V_110 ) )
F_122 ( L_130 ) ;
F_61 ( & V_12 -> V_439 . V_440 ) ;
} else {
F_46 ( V_792 , V_110 ) ;
F_120 ( V_792 ) ;
}
}
static void F_521 ( struct V_11 * V_12 ,
bool V_794 , bool V_795 )
{
T_4 V_110 ;
F_517 ( V_12 ) ;
V_110 = F_5 ( V_796 ) ;
if ( V_794 ) {
V_110 |= V_797 ;
F_46 ( V_796 , V_110 ) ;
if ( F_482 ( F_5 ( V_796 ) &
V_798 , 1 ) )
F_122 ( L_131 ) ;
V_110 = F_5 ( V_796 ) ;
}
V_110 |= V_799 ;
F_46 ( V_796 , V_110 ) ;
F_120 ( V_796 ) ;
if ( F_39 ( ( F_5 ( V_796 ) & V_800 ) == 0 , 1 ) )
F_122 ( L_132 ) ;
V_110 = F_519 ( V_12 ) ;
V_110 |= V_801 ;
F_520 ( V_12 , V_110 ) ;
F_522 ( 100 ) ;
if ( F_39 ( ( F_519 ( V_12 ) & V_802 ) == 0 ,
1 ) )
F_122 ( L_133 ) ;
if ( V_795 ) {
V_110 = F_5 ( V_796 ) ;
V_110 |= V_803 ;
F_46 ( V_796 , V_110 ) ;
F_120 ( V_796 ) ;
}
}
static void F_523 ( struct V_11 * V_12 )
{
T_4 V_110 ;
unsigned long V_804 ;
V_110 = F_5 ( V_796 ) ;
if ( ( V_110 & ( V_800 | V_799 | V_797 |
V_803 ) ) == V_800 )
return;
F_224 ( & V_12 -> V_805 . V_806 , V_804 ) ;
if ( V_12 -> V_805 . V_807 ++ == 0 )
V_12 -> V_805 . V_808 . V_809 ( V_12 , V_810 ) ;
F_225 ( & V_12 -> V_805 . V_806 , V_804 ) ;
if ( V_110 & V_803 ) {
V_110 &= ~ V_803 ;
F_46 ( V_796 , V_110 ) ;
F_120 ( V_796 ) ;
}
V_110 = F_519 ( V_12 ) ;
V_110 |= V_811 ;
V_110 &= ~ V_801 ;
F_520 ( V_12 , V_110 ) ;
V_110 = F_5 ( V_796 ) ;
V_110 &= ~ V_799 ;
F_46 ( V_796 , V_110 ) ;
if ( F_39 ( F_5 ( V_796 ) & V_800 , 5 ) )
F_122 ( L_134 ) ;
if ( V_110 & V_797 ) {
V_110 = F_5 ( V_796 ) ;
V_110 &= ~ V_797 ;
F_46 ( V_796 , V_110 ) ;
if ( F_482 ( ( F_5 ( V_796 ) &
V_798 ) == 0 , 1 ) )
F_122 ( L_135 ) ;
}
F_224 ( & V_12 -> V_805 . V_806 , V_804 ) ;
if ( -- V_12 -> V_805 . V_807 == 0 )
V_12 -> V_805 . V_808 . V_812 ( V_12 , V_810 ) ;
F_225 ( & V_12 -> V_805 . V_806 , V_804 ) ;
}
void F_524 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_110 ;
F_47 ( L_136 ) ;
if ( V_12 -> V_743 == V_744 ) {
V_110 = F_5 ( V_813 ) ;
V_110 &= ~ V_814 ;
F_46 ( V_813 , V_110 ) ;
}
F_485 ( V_10 ) ;
F_521 ( V_12 , true , true ) ;
}
void F_525 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_110 ;
F_47 ( L_137 ) ;
F_523 ( V_12 ) ;
F_486 ( V_10 ) ;
if ( V_12 -> V_743 == V_744 ) {
V_110 = F_5 ( V_813 ) ;
V_110 |= V_814 ;
F_46 ( V_813 , V_110 ) ;
}
F_526 ( V_10 ) ;
}
static void F_527 ( struct V_9 * V_10 )
{
F_360 ( V_10 ) ;
}
static void F_528 ( struct V_9 * V_10 )
{
F_360 ( V_10 ) ;
}
static int F_529 ( struct V_28 * V_29 ,
int V_253 , int V_254 ,
struct V_307 * V_76 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
if ( ! F_530 ( V_73 ) )
return - V_270 ;
V_73 -> V_603 = false ;
return 0 ;
}
static void F_531 ( struct V_11 * V_12 ,
enum V_96 V_96 ,
struct V_463 * V_464 )
{
V_464 -> V_815 = F_5 ( F_532 ( V_96 ) ) ;
switch ( V_464 -> V_815 ) {
case V_816 :
V_464 -> V_117 = V_817 ;
break;
case V_818 :
V_464 -> V_117 = V_819 ;
break;
}
}
static void F_533 ( struct V_73 * V_29 ,
struct V_463 * V_464 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_116 * V_119 ;
enum V_96 V_96 ;
T_4 V_203 ;
V_203 = F_5 ( F_66 ( V_464 -> V_82 ) ) ;
V_96 = ( V_203 & V_820 ) >> V_821 ;
F_531 ( V_12 , V_96 , V_464 ) ;
if ( V_464 -> V_117 >= 0 ) {
V_119 = & V_12 -> V_118 [ V_464 -> V_117 ] ;
F_3 ( ! V_119 -> V_122 ( V_12 , V_119 ,
& V_464 -> V_199 ) ) ;
}
if ( ( V_96 == V_822 ) && F_5 ( V_243 ) & V_167 ) {
V_464 -> V_246 = true ;
V_203 = F_5 ( F_69 ( V_131 ) ) ;
V_464 -> V_366 = ( ( V_365 & V_203 ) >>
V_771 ) + 1 ;
F_511 ( V_29 , V_464 ) ;
}
}
static bool F_534 ( struct V_73 * V_29 ,
struct V_463 * V_464 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_471 V_823 ;
T_4 V_203 ;
if ( ! F_79 ( V_12 ,
F_357 ( V_29 -> V_4 ) ) )
return false ;
V_464 -> V_82 = (enum V_80 ) V_29 -> V_4 ;
V_464 -> V_117 = V_430 ;
V_203 = F_5 ( F_66 ( V_458 ) ) ;
if ( V_203 & V_124 ) {
enum V_4 V_824 ;
switch ( V_203 & V_825 ) {
default:
F_41 ( 1 , L_138 ) ;
case V_826 :
case V_827 :
V_824 = V_131 ;
break;
case V_828 :
V_824 = V_140 ;
break;
case V_829 :
V_824 = V_359 ;
break;
}
if ( V_824 == V_29 -> V_4 )
V_464 -> V_82 = V_458 ;
}
if ( ! F_79 ( V_12 ,
F_80 ( V_464 -> V_82 ) ) )
return false ;
V_203 = F_5 ( F_52 ( V_464 -> V_82 ) ) ;
if ( ! ( V_203 & V_152 ) )
return false ;
F_533 ( V_29 , V_464 ) ;
F_467 ( V_29 , V_464 ) ;
V_823 = F_358 ( V_29 -> V_4 ) ;
if ( F_79 ( V_12 , V_823 ) )
F_512 ( V_29 , V_464 ) ;
if ( F_210 ( V_10 ) )
V_464 -> V_438 = F_330 ( V_29 ) &&
( F_5 ( V_442 ) & V_443 ) ;
if ( V_464 -> V_82 != V_458 ) {
V_464 -> V_459 =
F_5 ( F_334 ( V_464 -> V_82 ) ) + 1 ;
} else {
V_464 -> V_459 = 1 ;
}
return true ;
}
static T_1 F_535 ( struct V_343 * V_425 )
{
int V_155 ;
for ( V_155 = 0 ; V_155 < F_247 ( V_830 ) ; V_155 ++ ) {
if ( V_425 -> clock == V_830 [ V_155 ] . clock )
break;
}
if ( V_155 == F_247 ( V_830 ) ) {
F_47 ( L_139 , V_425 -> clock ) ;
V_155 = 1 ;
}
F_47 ( L_140 ,
V_830 [ V_155 ] . clock ,
V_830 [ V_155 ] . V_77 ) ;
return V_830 [ V_155 ] . V_77 ;
}
static bool F_536 ( struct V_541 * V_3 ,
int V_831 , T_4 V_832 ,
int V_833 , T_4 V_834 ,
int V_835 )
{
struct V_11 * V_12 = V_3 -> V_10 -> V_13 ;
T_7 * V_836 = V_3 -> V_836 ;
T_4 V_155 ;
V_155 = F_5 ( V_831 ) ;
V_155 &= V_832 ;
if ( ! V_836 [ 0 ] )
return ! V_155 ;
if ( ! V_155 )
return false ;
V_155 = F_5 ( V_833 ) ;
V_155 &= ~ V_834 ;
F_46 ( V_833 , V_155 ) ;
for ( V_155 = 0 ; V_155 < V_836 [ 2 ] ; V_155 ++ )
if ( F_5 ( V_835 ) != * ( ( T_4 * ) V_836 + V_155 ) )
return false ;
return true ;
}
static void F_537 ( struct V_541 * V_3 ,
struct V_28 * V_29 ,
struct V_343 * V_425 )
{
struct V_11 * V_12 = V_3 -> V_10 -> V_13 ;
T_7 * V_836 = V_3 -> V_836 ;
T_4 V_837 ;
T_4 V_838 ;
T_4 V_155 ;
V_155 = F_5 ( V_839 ) ;
if ( V_155 == V_840 || V_155 == V_841 )
V_837 = V_842 ;
else
V_837 = V_843 ;
if ( F_536 ( V_3 ,
V_844 , V_837 ,
V_844 , V_845 ,
V_846 ) )
return;
V_155 = F_5 ( V_844 ) ;
V_155 &= ~ ( V_837 | V_845 ) ;
V_838 = ( V_155 >> 9 ) & 0x1f ;
F_46 ( V_844 , V_155 ) ;
if ( ! V_836 [ 0 ] )
return;
V_838 = F_423 ( T_7 , V_836 [ 2 ] , V_838 ) ;
F_140 ( L_141 , V_838 ) ;
for ( V_155 = 0 ; V_155 < V_838 ; V_155 ++ )
F_46 ( V_846 , * ( ( T_4 * ) V_836 + V_155 ) ) ;
V_155 = F_5 ( V_844 ) ;
V_155 |= V_837 ;
F_46 ( V_844 , V_155 ) ;
}
static void F_538 ( struct V_541 * V_3 ,
struct V_28 * V_29 ,
struct V_343 * V_425 )
{
struct V_11 * V_12 = V_3 -> V_10 -> V_13 ;
T_7 * V_836 = V_3 -> V_836 ;
T_4 V_837 ;
T_4 V_155 ;
int V_838 ;
int V_4 = F_35 ( V_29 ) -> V_4 ;
int V_203 ;
int V_847 = F_539 ( V_4 ) ;
int V_848 = F_540 ( V_4 ) ;
int V_849 = F_541 ( V_4 ) ;
int V_850 = V_851 ;
F_140 ( L_142 ) ;
V_203 = F_5 ( V_850 ) ;
V_203 |= ( V_852 << ( V_4 * 4 ) ) ;
F_46 ( V_850 , V_203 ) ;
F_120 ( V_850 ) ;
F_117 ( V_12 , F_35 ( V_29 ) -> V_4 ) ;
V_203 = F_5 ( V_850 ) ;
F_140 ( L_143 , V_203 ) ;
V_203 |= ( V_853 << ( V_4 * 4 ) ) ;
F_46 ( V_850 , V_203 ) ;
V_203 = F_5 ( V_850 ) ;
F_140 ( L_144 , V_203 ) ;
V_203 = F_5 ( V_849 ) ;
F_140 ( L_145 , V_203 ) ;
V_203 &= ~ ( V_854 | V_855 ) ;
F_46 ( V_849 , V_203 ) ;
F_140 ( L_146 , F_42 ( V_4 ) ) ;
V_837 = V_853 << ( V_4 * 4 ) ;
if ( F_10 ( V_29 , V_419 ) ) {
F_140 ( L_147 ) ;
V_836 [ 5 ] |= ( 1 << 2 ) ;
F_46 ( V_849 , V_854 ) ;
} else {
F_46 ( V_849 , F_535 ( V_425 ) ) ;
}
if ( F_536 ( V_3 ,
V_850 , V_837 ,
V_848 , V_856 ,
V_847 ) )
return;
V_155 = F_5 ( V_850 ) ;
V_155 &= ~ V_837 ;
F_46 ( V_850 , V_155 ) ;
if ( ! V_836 [ 0 ] )
return;
V_155 = F_5 ( V_848 ) ;
V_155 &= ~ V_856 ;
F_46 ( V_848 , V_155 ) ;
V_155 = ( V_155 >> 29 ) & V_857 ;
F_140 ( L_148 , V_155 ) ;
V_838 = F_423 ( T_7 , V_836 [ 2 ] , 21 ) ;
F_140 ( L_141 , V_838 ) ;
for ( V_155 = 0 ; V_155 < V_838 ; V_155 ++ )
F_46 ( V_847 , * ( ( T_4 * ) V_836 + V_155 ) ) ;
V_155 = F_5 ( V_850 ) ;
V_155 |= V_837 ;
F_46 ( V_850 , V_155 ) ;
}
static void F_542 ( struct V_541 * V_3 ,
struct V_28 * V_29 ,
struct V_343 * V_425 )
{
struct V_11 * V_12 = V_3 -> V_10 -> V_13 ;
T_7 * V_836 = V_3 -> V_836 ;
T_4 V_837 ;
T_4 V_155 ;
int V_838 ;
int V_847 ;
int V_849 ;
int V_848 ;
int V_850 ;
int V_4 = F_35 ( V_29 ) -> V_4 ;
if ( F_54 ( V_3 -> V_10 ) ) {
V_847 = F_543 ( V_4 ) ;
V_849 = F_544 ( V_4 ) ;
V_848 = F_545 ( V_4 ) ;
V_850 = V_858 ;
} else if ( F_19 ( V_3 -> V_10 ) ) {
V_847 = F_546 ( V_4 ) ;
V_849 = F_547 ( V_4 ) ;
V_848 = F_548 ( V_4 ) ;
V_850 = V_859 ;
} else {
V_847 = F_549 ( V_4 ) ;
V_849 = F_550 ( V_4 ) ;
V_848 = F_551 ( V_4 ) ;
V_850 = V_860 ;
}
F_140 ( L_146 , F_42 ( V_4 ) ) ;
if ( F_19 ( V_3 -> V_10 ) ) {
struct V_1 * V_1 ;
struct V_95 * V_478 ;
V_1 = F_552 ( V_3 ) ;
V_478 = F_354 ( & V_1 -> V_8 ) ;
V_155 = V_478 -> V_96 ;
} else {
V_155 = F_5 ( V_848 ) ;
V_155 = ( V_155 >> 29 ) & V_857 ;
}
if ( ! V_155 ) {
F_140 ( L_149 ) ;
V_837 = V_861 ;
V_837 |= V_861 << 4 ;
V_837 |= V_861 << 8 ;
} else {
F_140 ( L_150 , F_138 ( V_155 ) ) ;
V_837 = V_861 << ( ( V_155 - 1 ) * 4 ) ;
}
if ( F_10 ( V_29 , V_419 ) ) {
F_140 ( L_147 ) ;
V_836 [ 5 ] |= ( 1 << 2 ) ;
F_46 ( V_849 , V_854 ) ;
} else {
F_46 ( V_849 , F_535 ( V_425 ) ) ;
}
if ( F_536 ( V_3 ,
V_850 , V_837 ,
V_848 , V_856 ,
V_847 ) )
return;
V_155 = F_5 ( V_850 ) ;
V_155 &= ~ V_837 ;
F_46 ( V_850 , V_155 ) ;
if ( ! V_836 [ 0 ] )
return;
V_155 = F_5 ( V_848 ) ;
V_155 &= ~ V_856 ;
F_46 ( V_848 , V_155 ) ;
V_838 = F_423 ( T_7 , V_836 [ 2 ] , 21 ) ;
F_140 ( L_141 , V_838 ) ;
for ( V_155 = 0 ; V_155 < V_838 ; V_155 ++ )
F_46 ( V_847 , * ( ( T_4 * ) V_836 + V_155 ) ) ;
V_155 = F_5 ( V_850 ) ;
V_155 |= V_837 ;
F_46 ( V_850 , V_155 ) ;
}
void F_553 ( struct V_545 * V_6 ,
struct V_343 * V_425 )
{
struct V_28 * V_29 = V_6 -> V_29 ;
struct V_541 * V_3 ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
V_3 = F_554 ( V_6 , V_425 ) ;
if ( ! V_3 )
return;
F_140 ( L_151 ,
V_3 -> V_8 . V_226 ,
V_3 -> V_123 ,
V_3 -> V_6 -> V_8 . V_226 ,
V_3 -> V_6 -> V_123 ) ;
V_3 -> V_836 [ 6 ] = F_555 ( V_3 , V_425 ) / 2 ;
if ( V_12 -> V_251 . V_862 )
V_12 -> V_251 . V_862 ( V_3 , V_29 , V_425 ) ;
}
static void F_556 ( struct V_28 * V_29 , T_1 V_8 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
T_4 V_863 = 0 , V_299 = 0 ;
if ( V_8 ) {
unsigned int V_303 = V_73 -> V_864 ;
unsigned int V_256 = V_73 -> V_865 ;
unsigned int V_300 = F_557 ( V_303 ) * 4 ;
switch ( V_300 ) {
default:
F_262 ( 1 , L_152 ,
V_303 , V_300 ) ;
V_300 = 256 ;
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
}
V_863 |= V_147 |
V_866 |
V_867 |
F_558 ( V_300 ) ;
V_299 = ( V_256 << 12 ) | V_303 ;
}
if ( V_73 -> V_868 != 0 &&
( V_73 -> V_869 != V_8 ||
V_73 -> V_870 != V_299 ||
V_73 -> V_868 != V_863 ) ) {
F_46 ( V_146 , 0 ) ;
F_120 ( V_146 ) ;
V_73 -> V_868 = 0 ;
}
if ( V_73 -> V_869 != V_8 )
F_46 ( V_871 , V_8 ) ;
if ( V_73 -> V_870 != V_299 ) {
F_46 ( V_872 , V_299 ) ;
V_73 -> V_870 = V_299 ;
}
if ( V_73 -> V_868 != V_863 ) {
F_46 ( V_146 , V_863 ) ;
F_120 ( V_146 ) ;
V_73 -> V_868 = V_863 ;
}
}
static void F_559 ( struct V_28 * V_29 , T_1 V_8 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
T_4 V_863 ;
V_863 = 0 ;
if ( V_8 ) {
V_863 = V_873 ;
switch ( V_73 -> V_864 ) {
case 64 :
V_863 |= V_874 ;
break;
case 128 :
V_863 |= V_875 ;
break;
case 256 :
V_863 |= V_876 ;
break;
default:
F_3 ( 1 ) ;
return;
}
V_863 |= V_4 << 28 ;
}
if ( F_210 ( V_10 ) || F_168 ( V_10 ) )
V_863 |= V_877 ;
if ( V_73 -> V_868 != V_863 ) {
F_46 ( F_77 ( V_4 ) , V_863 ) ;
F_120 ( F_77 ( V_4 ) ) ;
V_73 -> V_868 = V_863 ;
}
F_46 ( F_560 ( V_4 ) , V_8 ) ;
F_120 ( F_560 ( V_4 ) ) ;
}
static void F_317 ( struct V_28 * V_29 ,
bool V_224 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
int V_4 = V_73 -> V_4 ;
int V_253 = V_29 -> V_878 ;
int V_254 = V_29 -> V_879 ;
T_1 V_8 = 0 , V_436 = 0 ;
if ( V_224 )
V_8 = V_73 -> V_880 ;
if ( V_253 >= V_73 -> V_77 . V_314 )
V_8 = 0 ;
if ( V_254 >= V_73 -> V_77 . V_313 )
V_8 = 0 ;
if ( V_253 < 0 ) {
if ( V_253 + V_73 -> V_864 <= 0 )
V_8 = 0 ;
V_436 |= V_881 << V_882 ;
V_253 = - V_253 ;
}
V_436 |= V_253 << V_882 ;
if ( V_254 < 0 ) {
if ( V_254 + V_73 -> V_865 <= 0 )
V_8 = 0 ;
V_436 |= V_881 << V_883 ;
V_254 = - V_254 ;
}
V_436 |= V_254 << V_883 ;
if ( V_8 == 0 && V_73 -> V_869 == 0 )
return;
F_46 ( F_561 ( V_4 ) , V_436 ) ;
if ( F_75 ( V_10 ) || F_76 ( V_10 ) )
F_556 ( V_29 , V_8 ) ;
else
F_559 ( V_29 , V_8 ) ;
V_73 -> V_869 = V_8 ;
}
static bool F_562 ( struct V_9 * V_10 ,
T_4 V_303 , T_4 V_256 )
{
if ( V_303 == 0 || V_256 == 0 )
return false ;
if ( F_75 ( V_10 ) || F_76 ( V_10 ) ) {
if ( ( V_303 & 63 ) != 0 )
return false ;
if ( V_303 > ( F_75 ( V_10 ) ? 64 : 512 ) )
return false ;
if ( V_256 > 1023 )
return false ;
} else {
switch ( V_303 | V_256 ) {
case 256 :
case 128 :
if ( F_20 ( V_10 ) )
return false ;
case 64 :
break;
default:
return false ;
}
}
return true ;
}
static int F_563 ( struct V_28 * V_29 ,
struct V_259 * V_260 ,
T_4 V_303 , T_4 V_256 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_4 V_4 = V_73 -> V_4 ;
unsigned V_884 , V_300 ;
T_4 V_885 ;
int V_264 ;
if ( ! V_260 ) {
F_47 ( L_153 ) ;
V_885 = 0 ;
F_59 ( & V_10 -> V_265 ) ;
goto V_886;
}
if ( ! F_562 ( V_10 , V_303 , V_256 ) ) {
F_564 ( L_154 ) ;
return - V_270 ;
}
V_300 = F_557 ( V_303 ) * 4 ;
if ( V_260 -> V_8 . V_299 < V_300 * V_256 ) {
F_47 ( L_155 ) ;
V_264 = - V_887 ;
goto V_888;
}
F_59 ( & V_10 -> V_265 ) ;
if ( ! F_45 ( V_10 ) -> V_889 ) {
unsigned V_263 ;
if ( V_260 -> V_266 ) {
F_47 ( L_156 ) ;
V_264 = - V_270 ;
goto V_890;
}
F_178 ( V_12 ) ;
V_263 = 0 ;
if ( F_170 ( V_10 ) )
V_263 = 64 * 1024 ;
V_264 = F_179 ( V_260 , V_263 , NULL ) ;
if ( V_264 ) {
F_47 ( L_157 ) ;
F_182 ( V_12 ) ;
goto V_890;
}
V_264 = F_565 ( V_260 ) ;
if ( V_264 ) {
F_47 ( L_158 ) ;
F_182 ( V_12 ) ;
goto V_891;
}
V_885 = F_198 ( V_260 ) ;
F_182 ( V_12 ) ;
} else {
int V_892 = F_132 ( V_10 ) ? 16 * 1024 : 256 ;
V_264 = F_566 ( V_260 , V_892 ) ;
if ( V_264 ) {
F_47 ( L_159 ) ;
goto V_890;
}
V_885 = V_260 -> V_893 -> V_894 ;
}
V_886:
if ( V_73 -> V_895 ) {
if ( ! F_45 ( V_10 ) -> V_889 )
F_183 ( V_73 -> V_895 ) ;
}
F_227 ( V_73 -> V_895 , V_260 ,
F_567 ( V_4 ) ) ;
F_61 ( & V_10 -> V_265 ) ;
V_884 = V_73 -> V_864 ;
V_73 -> V_880 = V_885 ;
V_73 -> V_895 = V_260 ;
V_73 -> V_864 = V_303 ;
V_73 -> V_865 = V_256 ;
if ( V_73 -> V_74 ) {
if ( V_884 != V_303 )
F_329 ( V_29 ) ;
F_317 ( V_29 , V_73 -> V_895 != NULL ) ;
}
F_232 ( V_10 , F_567 ( V_4 ) ) ;
return 0 ;
V_891:
F_183 ( V_260 ) ;
V_890:
F_61 ( & V_10 -> V_265 ) ;
V_888:
F_568 ( & V_260 -> V_8 ) ;
return V_264 ;
}
static void F_569 ( struct V_28 * V_29 , T_5 * V_896 , T_5 * V_897 ,
T_5 * V_898 , T_4 V_899 , T_4 V_299 )
{
int V_900 = ( V_899 + V_299 > 256 ) ? 256 : V_899 + V_299 , V_155 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
for ( V_155 = V_899 ; V_155 < V_900 ; V_155 ++ ) {
V_73 -> V_448 [ V_155 ] = V_896 [ V_155 ] >> 8 ;
V_73 -> V_449 [ V_155 ] = V_897 [ V_155 ] >> 8 ;
V_73 -> V_450 [ V_155 ] = V_898 [ V_155 ] >> 8 ;
}
F_308 ( V_29 ) ;
}
struct V_307 *
F_570 ( struct V_9 * V_10 ,
struct V_297 * V_298 ,
struct V_259 * V_260 )
{
struct V_712 * V_901 ;
int V_264 ;
V_901 = F_474 ( sizeof( * V_901 ) , V_713 ) ;
if ( ! V_901 ) {
F_568 ( & V_260 -> V_8 ) ;
return F_571 ( - V_887 ) ;
}
V_264 = F_190 ( V_10 , V_901 , V_298 , V_260 ) ;
if ( V_264 )
goto V_61;
return & V_901 -> V_8 ;
V_61:
F_568 ( & V_260 -> V_8 ) ;
F_195 ( V_901 ) ;
return F_571 ( V_264 ) ;
}
static struct V_307 *
F_572 ( struct V_9 * V_10 ,
struct V_297 * V_298 ,
struct V_259 * V_260 )
{
struct V_307 * V_76 ;
int V_264 ;
V_264 = F_573 ( V_10 ) ;
if ( V_264 )
return F_571 ( V_264 ) ;
V_76 = F_570 ( V_10 , V_298 , V_260 ) ;
F_61 ( & V_10 -> V_265 ) ;
return V_76 ;
}
static T_1
F_574 ( int V_303 , int V_764 )
{
T_1 V_276 = F_364 ( V_303 * V_764 , 8 ) ;
return F_173 ( V_276 , 64 ) ;
}
static T_1
F_575 ( struct V_343 * V_425 , int V_764 )
{
T_1 V_276 = F_574 ( V_425 -> V_532 , V_764 ) ;
return F_475 ( V_276 * V_425 -> V_534 ) ;
}
static struct V_307 *
F_576 ( struct V_9 * V_10 ,
struct V_343 * V_425 ,
int V_902 , int V_764 )
{
struct V_259 * V_260 ;
struct V_297 V_298 = { 0 } ;
V_260 = F_577 ( V_10 ,
F_575 ( V_425 , V_764 ) ) ;
if ( V_260 == NULL )
return F_571 ( - V_887 ) ;
V_298 . V_303 = V_425 -> V_532 ;
V_298 . V_256 = V_425 -> V_534 ;
V_298 . V_301 [ 0 ] = F_574 ( V_298 . V_303 ,
V_764 ) ;
V_298 . V_302 = F_578 ( V_764 , V_902 ) ;
return F_572 ( V_10 , & V_298 , V_260 ) ;
}
static struct V_307 *
F_579 ( struct V_9 * V_10 ,
struct V_343 * V_425 )
{
#ifdef F_580
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_259 * V_260 ;
struct V_307 * V_76 ;
if ( ! V_12 -> V_903 )
return NULL ;
if ( ! V_12 -> V_903 -> V_76 )
return NULL ;
V_260 = V_12 -> V_903 -> V_76 -> V_260 ;
F_118 ( ! V_260 ) ;
V_76 = & V_12 -> V_903 -> V_76 -> V_8 ;
if ( V_76 -> V_301 [ 0 ] < F_574 ( V_425 -> V_532 ,
V_76 -> V_583 ) )
return NULL ;
if ( V_260 -> V_8 . V_299 < V_425 -> V_534 * V_76 -> V_301 [ 0 ] )
return NULL ;
return V_76 ;
#else
return NULL ;
#endif
}
bool F_581 ( struct V_541 * V_3 ,
struct V_343 * V_425 ,
struct V_904 * V_905 ,
struct V_906 * V_907 )
{
struct V_73 * V_73 ;
struct V_1 * V_1 =
F_552 ( V_3 ) ;
struct V_28 * V_908 ;
struct V_545 * V_6 = & V_1 -> V_8 ;
struct V_28 * V_29 = NULL ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_307 * V_76 ;
struct V_909 * V_77 = & V_10 -> V_910 ;
int V_264 , V_155 = - 1 ;
F_47 ( L_160 ,
V_3 -> V_8 . V_226 , V_3 -> V_123 ,
V_6 -> V_8 . V_226 , V_6 -> V_123 ) ;
V_371:
V_264 = F_217 ( & V_77 -> V_911 , V_907 ) ;
if ( V_264 )
goto V_912;
if ( V_6 -> V_29 ) {
V_29 = V_6 -> V_29 ;
V_264 = F_217 ( & V_29 -> V_329 , V_907 ) ;
if ( V_264 )
goto V_912;
V_905 -> V_913 = V_3 -> V_543 ;
V_905 -> V_914 = false ;
if ( V_3 -> V_543 != V_546 )
V_3 -> V_808 -> V_543 ( V_3 , V_546 ) ;
return true ;
}
F_196 (dev, possible_crtc) {
V_155 ++ ;
if ( ! ( V_6 -> V_915 & ( 1 << V_155 ) ) )
continue;
if ( V_908 -> V_108 )
continue;
if ( F_35 ( V_908 ) -> V_518 )
continue;
V_29 = V_908 ;
break;
}
if ( ! V_29 ) {
F_47 ( L_161 ) ;
goto V_912;
}
V_264 = F_217 ( & V_29 -> V_329 , V_907 ) ;
if ( V_264 )
goto V_912;
V_1 -> V_916 = F_35 ( V_29 ) ;
F_582 ( V_3 ) -> V_917 = V_1 ;
V_73 = F_35 ( V_29 ) ;
V_73 -> V_518 = true ;
V_73 -> V_519 = & V_73 -> V_77 ;
V_905 -> V_913 = V_3 -> V_543 ;
V_905 -> V_914 = true ;
V_905 -> V_918 = NULL ;
if ( ! V_425 )
V_425 = & V_919 ;
V_76 = F_579 ( V_10 , V_425 ) ;
if ( V_76 == NULL ) {
F_47 ( L_162 ) ;
V_76 = F_576 ( V_10 , V_425 , 24 , 32 ) ;
V_905 -> V_918 = V_76 ;
} else
F_47 ( L_163 ) ;
if ( F_583 ( V_76 ) ) {
F_47 ( L_164 ) ;
goto V_888;
}
if ( F_584 ( V_29 , V_425 , 0 , 0 , V_76 ) ) {
F_47 ( L_165 ) ;
if ( V_905 -> V_918 )
V_905 -> V_918 -> V_808 -> V_920 ( V_905 -> V_918 ) ;
goto V_888;
}
F_43 ( V_10 , V_73 -> V_4 ) ;
return true ;
V_888:
V_73 -> V_518 = V_29 -> V_108 ;
if ( V_73 -> V_518 )
V_73 -> V_519 = & V_73 -> V_77 ;
else
V_73 -> V_519 = NULL ;
V_912:
if ( V_264 == - V_921 ) {
F_585 ( V_907 ) ;
goto V_371;
}
return false ;
}
void F_586 ( struct V_541 * V_3 ,
struct V_904 * V_905 )
{
struct V_1 * V_1 =
F_552 ( V_3 ) ;
struct V_545 * V_6 = & V_1 -> V_8 ;
struct V_28 * V_29 = V_6 -> V_29 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
F_47 ( L_160 ,
V_3 -> V_8 . V_226 , V_3 -> V_123 ,
V_6 -> V_8 . V_226 , V_6 -> V_123 ) ;
if ( V_905 -> V_914 ) {
F_582 ( V_3 ) -> V_917 = NULL ;
V_1 -> V_916 = NULL ;
V_73 -> V_518 = false ;
V_73 -> V_519 = NULL ;
F_584 ( V_29 , NULL , 0 , 0 , NULL ) ;
if ( V_905 -> V_918 ) {
F_587 ( V_905 -> V_918 ) ;
F_588 ( V_905 -> V_918 ) ;
}
return;
}
if ( V_905 -> V_913 != V_546 )
V_3 -> V_808 -> V_543 ( V_3 , V_905 -> V_913 ) ;
}
static int F_589 ( struct V_9 * V_10 ,
const struct V_463 * V_464 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_54 = V_464 -> V_199 . V_54 ;
if ( ( V_54 & V_922 ) == V_664 )
return V_12 -> V_595 . V_599 ;
else if ( F_4 ( V_10 ) )
return 120000 ;
else if ( ! F_20 ( V_10 ) )
return 96000 ;
else
return 48000 ;
}
static void F_478 ( struct V_73 * V_29 ,
struct V_463 * V_464 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_464 -> V_82 ;
T_1 V_54 = V_464 -> V_199 . V_54 ;
T_1 V_601 ;
T_2 clock ;
int V_18 = F_589 ( V_10 , V_464 ) ;
if ( ( V_54 & V_923 ) == 0 )
V_601 = V_464 -> V_199 . V_524 ;
else
V_601 = V_464 -> V_199 . V_525 ;
clock . V_20 = ( V_601 & V_924 ) >> V_925 ;
if ( F_17 ( V_10 ) ) {
clock . V_25 = F_590 ( ( V_601 & V_926 ) >> V_927 ) - 1 ;
clock . V_21 = ( V_601 & V_928 ) >> V_929 ;
} else {
clock . V_25 = ( V_601 & V_930 ) >> V_927 ;
clock . V_21 = ( V_601 & V_931 ) >> V_929 ;
}
if ( ! F_20 ( V_10 ) ) {
if ( F_17 ( V_10 ) )
clock . V_23 = F_590 ( ( V_54 & V_932 ) >>
V_654 ) ;
else
clock . V_23 = F_590 ( ( V_54 & V_933 ) >>
V_655 ) ;
switch ( V_54 & V_934 ) {
case V_651 :
clock . V_24 = V_54 & V_657 ?
5 : 10 ;
break;
case V_650 :
clock . V_24 = V_54 & V_658 ?
7 : 14 ;
break;
default:
F_47 ( L_166
L_167 , ( int ) ( V_54 & V_934 ) ) ;
return;
}
if ( F_17 ( V_10 ) )
F_21 ( V_18 , & clock ) ;
else
F_23 ( V_18 , & clock ) ;
} else {
T_1 V_935 = F_132 ( V_10 ) ? 0 : F_5 ( V_142 ) ;
bool V_701 = ( V_4 == 1 ) && ( V_935 & V_178 ) ;
if ( V_701 ) {
clock . V_23 = F_590 ( ( V_54 & V_936 ) >>
V_655 ) ;
if ( V_935 & V_937 )
clock . V_24 = 7 ;
else
clock . V_24 = 14 ;
} else {
if ( V_54 & V_666 )
clock . V_23 = 2 ;
else {
clock . V_23 = ( ( V_54 & V_938 ) >>
V_655 ) + 2 ;
}
if ( V_54 & V_667 )
clock . V_24 = 4 ;
else
clock . V_24 = 2 ;
}
F_23 ( V_18 , & clock ) ;
}
V_464 -> V_633 = clock . V_27 ;
}
int F_591 ( int V_939 ,
const struct V_587 * V_588 )
{
if ( ! V_588 -> V_593 )
return 0 ;
return F_32 ( ( V_940 ) V_588 -> V_592 * V_939 , V_588 -> V_593 ) ;
}
static void F_516 ( struct V_73 * V_29 ,
struct V_463 * V_464 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
F_478 ( V_29 , V_464 ) ;
V_464 -> V_78 . V_79 =
F_591 ( F_6 ( V_10 ) * 10000 ,
& V_464 -> V_454 ) ;
}
struct V_343 * F_592 ( struct V_9 * V_10 ,
struct V_28 * V_29 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_80 V_82 = V_73 -> V_77 . V_82 ;
struct V_343 * V_425 ;
struct V_463 V_464 ;
int V_941 = F_5 ( F_272 ( V_82 ) ) ;
int V_942 = F_5 ( F_276 ( V_82 ) ) ;
int V_943 = F_5 ( F_278 ( V_82 ) ) ;
int V_944 = F_5 ( F_282 ( V_82 ) ) ;
enum V_4 V_4 = V_73 -> V_4 ;
V_425 = F_474 ( sizeof( * V_425 ) , V_713 ) ;
if ( ! V_425 )
return NULL ;
V_464 . V_82 = (enum V_80 ) V_4 ;
V_464 . V_459 = 1 ;
V_464 . V_199 . V_54 = F_5 ( F_57 ( V_4 ) ) ;
V_464 . V_199 . V_524 = F_5 ( F_382 ( V_4 ) ) ;
V_464 . V_199 . V_525 = F_5 ( F_383 ( V_4 ) ) ;
F_478 ( V_73 , & V_464 ) ;
V_425 -> clock = V_464 . V_633 / V_464 . V_459 ;
V_425 -> V_532 = ( V_941 & 0xffff ) + 1 ;
V_425 -> V_681 = ( ( V_941 & 0xffff0000 ) >> 16 ) + 1 ;
V_425 -> V_558 = ( V_942 & 0xffff ) + 1 ;
V_425 -> V_682 = ( ( V_942 & 0xffff0000 ) >> 16 ) + 1 ;
V_425 -> V_534 = ( V_943 & 0xffff ) + 1 ;
V_425 -> V_683 = ( ( V_943 & 0xffff0000 ) >> 16 ) + 1 ;
V_425 -> V_684 = ( V_944 & 0xffff ) + 1 ;
V_425 -> V_685 = ( ( V_944 & 0xffff0000 ) >> 16 ) + 1 ;
F_593 ( V_425 ) ;
return V_425 ;
}
static void F_213 ( struct V_9 * V_10 ,
enum V_4 V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_218 = F_57 ( V_4 ) ;
int V_54 ;
if ( ! F_310 ( V_10 ) )
return;
if ( ! V_12 -> V_704 )
return;
V_54 = F_5 ( V_218 ) ;
if ( ! F_469 ( V_10 ) && ( V_54 & V_923 ) ) {
F_140 ( L_168 ) ;
F_72 ( V_12 , V_4 ) ;
V_54 &= ~ V_923 ;
F_46 ( V_218 , V_54 ) ;
F_43 ( V_10 , V_4 ) ;
V_54 = F_5 ( V_218 ) ;
if ( V_54 & V_923 )
F_140 ( L_169 ) ;
}
}
static void F_594 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
if ( ! F_310 ( V_10 ) )
return;
if ( ! V_12 -> V_704 )
return;
if ( ! F_469 ( V_10 ) && V_73 -> V_603 ) {
int V_4 = V_73 -> V_4 ;
int V_218 = F_57 ( V_4 ) ;
int V_54 ;
F_140 ( L_170 ) ;
F_72 ( V_12 , V_4 ) ;
V_54 = F_5 ( V_218 ) ;
V_54 |= V_923 ;
F_46 ( V_218 , V_54 ) ;
F_43 ( V_10 , V_4 ) ;
V_54 = F_5 ( V_218 ) ;
if ( ! ( V_54 & V_923 ) )
F_140 ( L_171 ) ;
}
}
void F_595 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_12 -> V_271 . V_945 )
return;
F_178 ( V_12 ) ;
F_596 ( V_12 ) ;
V_12 -> V_271 . V_945 = true ;
}
void F_597 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 ;
if ( ! V_12 -> V_271 . V_945 )
return;
V_12 -> V_271 . V_945 = false ;
if ( ! V_341 . V_604 )
goto V_946;
F_196 (dev, crtc) {
if ( ! V_29 -> V_75 -> V_76 )
continue;
F_594 ( V_29 ) ;
}
if ( F_45 ( V_10 ) -> V_86 >= 6 )
F_598 ( V_10 -> V_13 ) ;
V_946:
F_182 ( V_12 ) ;
}
static void F_599 ( struct V_9 * V_10 ,
unsigned V_305 ,
struct V_261 * V_947 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 ;
if ( ! V_341 . V_604 )
return;
F_85 (dev_priv, pipe) {
if ( ! ( V_305 & F_318 ( V_4 ) ) )
continue;
F_213 ( V_10 , V_4 ) ;
if ( V_947 && F_600 ( V_10 ) )
V_947 -> V_948 = true ;
}
}
void F_601 ( struct V_259 * V_260 ,
struct V_261 * V_947 )
{
struct V_9 * V_10 = V_260 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_3 ( ! F_175 ( & V_10 -> V_265 ) ) ;
if ( ! V_260 -> V_305 )
return;
if ( V_947 ) {
F_59 ( & V_12 -> V_949 . V_806 ) ;
V_12 -> V_949 . V_950
|= V_260 -> V_305 ;
V_12 -> V_949 . V_951
&= ~ V_260 -> V_305 ;
F_61 ( & V_12 -> V_949 . V_806 ) ;
}
F_599 ( V_10 , V_260 -> V_305 , V_947 ) ;
F_602 ( V_10 , V_260 -> V_305 ) ;
}
void F_603 ( struct V_9 * V_10 ,
unsigned V_305 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
F_59 ( & V_12 -> V_949 . V_806 ) ;
V_305 &= ~ V_12 -> V_949 . V_950 ;
F_61 ( & V_12 -> V_949 . V_806 ) ;
F_599 ( V_10 , V_305 , NULL ) ;
F_604 ( V_10 , V_305 ) ;
if ( F_168 ( V_10 ) )
F_605 ( V_10 , V_952 ) ;
}
void F_606 ( struct V_259 * V_260 ,
bool V_953 )
{
struct V_9 * V_10 = V_260 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned V_305 ;
F_3 ( ! F_175 ( & V_10 -> V_265 ) ) ;
if ( ! V_260 -> V_305 )
return;
V_305 = V_260 -> V_305 ;
if ( V_953 ) {
F_59 ( & V_12 -> V_949 . V_806 ) ;
V_305 &= V_12 -> V_949 . V_950 ;
V_12 -> V_949 . V_950 &= ~ V_305 ;
F_61 ( & V_12 -> V_949 . V_806 ) ;
}
F_603 ( V_10 , V_305 ) ;
}
void F_607 ( struct V_9 * V_10 ,
unsigned V_305 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
F_59 ( & V_12 -> V_949 . V_806 ) ;
V_12 -> V_949 . V_951
|= V_305 ;
F_61 ( & V_12 -> V_949 . V_806 ) ;
}
void F_608 ( struct V_9 * V_10 ,
unsigned V_305 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
F_59 ( & V_12 -> V_949 . V_806 ) ;
V_305 &= V_12 -> V_949 . V_951 ;
V_12 -> V_949 . V_951 &= ~ V_305 ;
F_61 ( & V_12 -> V_949 . V_806 ) ;
F_603 ( V_10 , V_305 ) ;
}
static void F_609 ( struct V_28 * V_29 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_387 * V_388 ;
unsigned long V_332 ;
F_224 ( & V_10 -> V_336 , V_332 ) ;
V_388 = V_73 -> V_337 ;
V_73 -> V_337 = NULL ;
F_225 ( & V_10 -> V_336 , V_332 ) ;
if ( V_388 ) {
F_610 ( & V_388 -> V_388 ) ;
F_195 ( V_388 ) ;
}
F_611 ( V_29 ) ;
F_195 ( V_73 ) ;
}
static void F_612 ( struct V_954 * V_955 )
{
struct V_387 * V_388 =
F_613 ( V_955 , struct V_387 , V_388 ) ;
struct V_9 * V_10 = V_388 -> V_29 -> V_10 ;
enum V_4 V_4 = F_35 ( V_388 -> V_29 ) -> V_4 ;
F_59 ( & V_10 -> V_265 ) ;
F_184 ( V_388 -> V_956 ) ;
F_193 ( & V_388 -> V_392 -> V_8 ) ;
F_193 ( & V_388 -> V_956 -> V_8 ) ;
F_233 ( V_10 ) ;
F_61 ( & V_10 -> V_265 ) ;
F_608 ( V_10 , F_192 ( V_4 ) ) ;
F_118 ( F_223 ( & F_35 ( V_388 -> V_29 ) -> V_386 ) == 0 ) ;
F_614 ( & F_35 ( V_388 -> V_29 ) -> V_386 ) ;
F_195 ( V_388 ) ;
}
static void F_615 ( struct V_9 * V_10 ,
struct V_28 * V_29 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_387 * V_388 ;
unsigned long V_332 ;
if ( V_73 == NULL )
return;
F_224 ( & V_10 -> V_336 , V_332 ) ;
V_388 = V_73 -> V_337 ;
F_254 () ;
if ( V_388 == NULL || F_223 ( & V_388 -> V_333 ) < V_957 ) {
F_225 ( & V_10 -> V_336 , V_332 ) ;
return;
}
F_252 ( V_73 ) ;
F_225 ( & V_10 -> V_336 , V_332 ) ;
}
void F_616 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 = V_12 -> V_81 [ V_4 ] ;
F_615 ( V_10 , V_29 ) ;
}
void F_216 ( struct V_9 * V_10 , int V_153 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 = V_12 -> V_958 [ V_153 ] ;
F_615 ( V_10 , V_29 ) ;
}
static bool F_617 ( T_1 V_959 , T_1 V_960 )
{
return ! ( ( V_959 - V_960 ) & 0x80000000 ) ;
}
static bool F_618 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_222 ( & V_12 -> V_334 ) ||
V_29 -> V_335 != F_223 ( & V_12 -> V_334 . V_335 ) )
return true ;
if ( F_45 ( V_10 ) -> V_86 < 5 && ! F_16 ( V_10 ) )
return true ;
return ( F_5 ( F_619 ( V_29 -> V_153 ) ) & ~ 0xfff ) ==
V_29 -> V_337 -> V_961 &&
F_617 ( F_5 ( F_620 ( V_29 -> V_4 ) ) ,
V_29 -> V_337 -> V_962 ) ;
}
void F_215 ( struct V_9 * V_10 , int V_153 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 =
F_35 ( V_12 -> V_958 [ V_153 ] ) ;
unsigned long V_332 ;
F_224 ( & V_10 -> V_336 , V_332 ) ;
if ( V_73 -> V_337 && F_618 ( V_73 ) )
F_621 ( & V_73 -> V_337 -> V_333 ) ;
F_225 ( & V_10 -> V_336 , V_332 ) ;
}
static inline void F_622 ( struct V_73 * V_73 )
{
F_623 () ;
F_624 ( & V_73 -> V_337 -> V_333 , V_963 ) ;
F_623 () ;
}
static int F_625 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
struct V_307 * V_76 ,
struct V_259 * V_260 ,
struct V_261 * V_947 ,
T_4 V_332 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
T_1 V_964 ;
int V_264 ;
V_264 = F_626 ( V_947 , 6 ) ;
if ( V_264 )
return V_264 ;
if ( V_73 -> V_153 )
V_964 = V_965 ;
else
V_964 = V_966 ;
F_627 ( V_947 , V_967 | V_964 ) ;
F_627 ( V_947 , V_968 ) ;
F_627 ( V_947 , V_969 |
F_628 ( V_73 -> V_153 ) ) ;
F_627 ( V_947 , V_76 -> V_301 [ 0 ] ) ;
F_627 ( V_947 , V_73 -> V_337 -> V_961 ) ;
F_627 ( V_947 , 0 ) ;
F_622 ( V_73 ) ;
F_629 ( V_947 ) ;
return 0 ;
}
static int F_630 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
struct V_307 * V_76 ,
struct V_259 * V_260 ,
struct V_261 * V_947 ,
T_4 V_332 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
T_1 V_964 ;
int V_264 ;
V_264 = F_626 ( V_947 , 6 ) ;
if ( V_264 )
return V_264 ;
if ( V_73 -> V_153 )
V_964 = V_965 ;
else
V_964 = V_966 ;
F_627 ( V_947 , V_967 | V_964 ) ;
F_627 ( V_947 , V_968 ) ;
F_627 ( V_947 , V_970 |
F_628 ( V_73 -> V_153 ) ) ;
F_627 ( V_947 , V_76 -> V_301 [ 0 ] ) ;
F_627 ( V_947 , V_73 -> V_337 -> V_961 ) ;
F_627 ( V_947 , V_968 ) ;
F_622 ( V_73 ) ;
F_629 ( V_947 ) ;
return 0 ;
}
static int F_631 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
struct V_307 * V_76 ,
struct V_259 * V_260 ,
struct V_261 * V_947 ,
T_4 V_332 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
T_4 V_971 , V_972 ;
int V_264 ;
V_264 = F_626 ( V_947 , 4 ) ;
if ( V_264 )
return V_264 ;
F_627 ( V_947 , V_969 |
F_628 ( V_73 -> V_153 ) ) ;
F_627 ( V_947 , V_76 -> V_301 [ 0 ] ) ;
F_627 ( V_947 , V_73 -> V_337 -> V_961 |
V_260 -> V_266 ) ;
V_971 = 0 ;
V_972 = F_5 ( F_228 ( V_73 -> V_4 ) ) & 0x0fff0fff ;
F_627 ( V_947 , V_971 | V_972 ) ;
F_622 ( V_73 ) ;
F_629 ( V_947 ) ;
return 0 ;
}
static int F_632 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
struct V_307 * V_76 ,
struct V_259 * V_260 ,
struct V_261 * V_947 ,
T_4 V_332 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
T_4 V_971 , V_972 ;
int V_264 ;
V_264 = F_626 ( V_947 , 4 ) ;
if ( V_264 )
return V_264 ;
F_627 ( V_947 , V_969 |
F_628 ( V_73 -> V_153 ) ) ;
F_627 ( V_947 , V_76 -> V_301 [ 0 ] | V_260 -> V_266 ) ;
F_627 ( V_947 , V_73 -> V_337 -> V_961 ) ;
V_971 = 0 ;
V_972 = F_5 ( F_228 ( V_73 -> V_4 ) ) & 0x0fff0fff ;
F_627 ( V_947 , V_971 | V_972 ) ;
F_622 ( V_73 ) ;
F_629 ( V_947 ) ;
return 0 ;
}
static int F_633 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
struct V_307 * V_76 ,
struct V_259 * V_260 ,
struct V_261 * V_947 ,
T_4 V_332 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
T_4 V_973 = 0 ;
int V_838 , V_264 ;
switch ( V_73 -> V_153 ) {
case V_974 :
V_973 = V_975 ;
break;
case V_976 :
V_973 = V_977 ;
break;
case V_978 :
V_973 = V_979 ;
break;
default:
F_262 ( 1 , L_172 ) ;
return - V_980 ;
}
V_838 = 4 ;
if ( V_947 -> V_226 == V_981 ) {
V_838 += 6 ;
if ( F_634 ( V_10 ) )
V_838 += 2 ;
}
V_264 = F_635 ( V_947 ) ;
if ( V_264 )
return V_264 ;
V_264 = F_626 ( V_947 , V_838 ) ;
if ( V_264 )
return V_264 ;
if ( V_947 -> V_226 == V_981 ) {
F_627 ( V_947 , F_636 ( 1 ) ) ;
F_627 ( V_947 , V_982 ) ;
F_627 ( V_947 , ~ ( V_983 |
V_984 |
V_985 ) ) ;
if ( F_634 ( V_10 ) )
F_627 ( V_947 , F_637 ( 1 ) |
V_986 ) ;
else
F_627 ( V_947 , F_638 ( 1 ) |
V_986 ) ;
F_627 ( V_947 , V_982 ) ;
F_627 ( V_947 , V_947 -> V_987 . V_961 + 256 ) ;
if ( F_634 ( V_10 ) ) {
F_627 ( V_947 , 0 ) ;
F_627 ( V_947 , V_968 ) ;
}
}
F_627 ( V_947 , V_970 | V_973 ) ;
F_627 ( V_947 , ( V_76 -> V_301 [ 0 ] | V_260 -> V_266 ) ) ;
F_627 ( V_947 , V_73 -> V_337 -> V_961 ) ;
F_627 ( V_947 , ( V_968 ) ) ;
F_622 ( V_73 ) ;
F_629 ( V_947 ) ;
return 0 ;
}
static bool F_639 ( struct V_261 * V_947 ,
struct V_259 * V_260 )
{
if ( V_947 == NULL )
return true ;
if ( F_45 ( V_947 -> V_10 ) -> V_86 < 5 )
return false ;
if ( V_341 . F_639 < 0 )
return false ;
else if ( V_341 . F_639 > 0 )
return true ;
else if ( V_341 . V_988 )
return true ;
else
return V_947 != V_260 -> V_947 ;
}
static void F_640 ( struct V_73 * V_73 )
{
struct V_9 * V_10 = V_73 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_712 * V_901 =
F_191 ( V_73 -> V_8 . V_75 -> V_76 ) ;
struct V_259 * V_260 = V_901 -> V_260 ;
T_1 V_309 ;
T_1 V_88 ;
F_622 ( V_73 ) ;
V_88 = F_82 ( V_73 -> V_153 ) ;
V_309 = F_5 ( V_88 ) ;
if ( F_45 ( V_10 ) -> V_86 >= 4 ) {
if ( V_260 -> V_266 != V_267 )
V_309 |= V_320 ;
else
V_309 &= ~ V_320 ;
}
F_46 ( V_88 , V_309 ) ;
F_46 ( F_164 ( V_73 -> V_153 ) ,
V_73 -> V_337 -> V_961 ) ;
F_120 ( F_164 ( V_73 -> V_153 ) ) ;
}
static int F_641 ( struct V_259 * V_260 )
{
struct V_261 * V_947 ;
int V_264 ;
F_642 ( & V_260 -> V_8 . V_10 -> V_265 ) ;
if ( ! V_260 -> V_989 )
return 0 ;
V_947 = V_260 -> V_947 ;
if ( F_643 ( V_947 -> V_990 ( V_947 , true ) ,
V_260 -> V_989 ) )
return 0 ;
V_264 = F_644 ( V_947 , V_260 -> V_989 ) ;
if ( V_264 )
return V_264 ;
if ( F_3 ( ! V_947 -> V_991 ( V_947 ) ) )
return 0 ;
return 1 ;
}
void F_645 ( struct V_261 * V_947 )
{
struct V_11 * V_12 = F_253 ( V_947 -> V_10 ) ;
struct V_73 * V_73 ;
unsigned long V_992 ;
T_1 V_993 ;
V_993 = V_947 -> V_990 ( V_947 , false ) ;
F_224 ( & V_12 -> V_994 , V_992 ) ;
F_130 (ring->dev, intel_crtc) {
struct V_995 * V_996 ;
V_996 = & V_73 -> V_996 ;
if ( V_996 -> V_993 == 0 )
continue;
if ( V_947 -> V_226 != V_996 -> V_997 )
continue;
if ( F_643 ( V_993 , V_996 -> V_993 ) ) {
F_640 ( V_73 ) ;
V_996 -> V_993 = 0 ;
V_947 -> V_998 ( V_947 ) ;
}
}
F_225 ( & V_12 -> V_994 , V_992 ) ;
}
static int F_646 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
struct V_307 * V_76 ,
struct V_259 * V_260 ,
struct V_261 * V_947 ,
T_4 V_332 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
unsigned long V_992 ;
int V_264 ;
if ( F_3 ( V_73 -> V_996 . V_993 ) )
return - V_339 ;
V_264 = F_641 ( V_260 ) ;
if ( V_264 < 0 )
return V_264 ;
if ( V_264 == 0 ) {
F_640 ( V_73 ) ;
return 0 ;
}
F_224 ( & V_12 -> V_994 , V_992 ) ;
V_73 -> V_996 . V_993 = V_260 -> V_989 ;
V_73 -> V_996 . V_997 = V_260 -> V_947 -> V_226 ;
F_225 ( & V_12 -> V_994 , V_992 ) ;
F_645 ( V_260 -> V_947 ) ;
return 0 ;
}
static int F_647 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
struct V_307 * V_76 ,
struct V_259 * V_260 ,
struct V_261 * V_947 ,
T_4 V_332 )
{
return - V_980 ;
}
static bool F_648 ( struct V_9 * V_10 ,
struct V_28 * V_29 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_387 * V_388 = V_73 -> V_337 ;
T_1 V_885 ;
if ( F_223 ( & V_388 -> V_333 ) >= V_957 )
return true ;
if ( ! V_388 -> V_999 )
return false ;
if ( V_388 -> V_1000 == 0 ) {
if ( V_388 -> V_1001 &&
! F_643 ( V_388 -> V_1001 -> V_990 ( V_388 -> V_1001 , true ) ,
V_388 -> V_1002 ) )
return false ;
V_388 -> V_1000 = F_649 ( V_10 , V_73 -> V_4 ) ;
}
if ( F_649 ( V_10 , V_73 -> V_4 ) - V_388 -> V_1000 < 3 )
return false ;
if ( F_45 ( V_10 ) -> V_86 >= 4 )
V_885 = F_650 ( F_5 ( F_164 ( V_73 -> V_153 ) ) ) ;
else
V_885 = F_5 ( F_165 ( V_73 -> V_153 ) ) ;
return V_885 == V_388 -> V_961 ;
}
void F_651 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 = V_12 -> V_81 [ V_4 ] ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
unsigned long V_332 ;
if ( V_29 == NULL )
return;
F_224 ( & V_10 -> V_336 , V_332 ) ;
if ( V_73 -> V_337 && F_648 ( V_10 , V_29 ) ) {
F_262 ( 1 , L_173 ,
V_73 -> V_337 -> V_1003 , F_649 ( V_10 , V_4 ) ) ;
F_252 ( V_73 ) ;
}
F_225 ( & V_10 -> V_336 , V_332 ) ;
}
static int F_652 ( struct V_28 * V_29 ,
struct V_307 * V_76 ,
struct V_1004 * V_389 ,
T_4 V_1005 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_307 * V_330 = V_29 -> V_75 -> V_76 ;
struct V_259 * V_260 = F_197 ( V_76 ) ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
enum V_4 V_4 = V_73 -> V_4 ;
struct V_387 * V_388 ;
struct V_261 * V_947 ;
unsigned long V_332 ;
int V_264 ;
if ( F_3 ( F_197 ( V_330 ) == NULL ) )
return - V_339 ;
if ( V_76 -> V_302 != V_29 -> V_75 -> V_76 -> V_302 )
return - V_270 ;
if ( F_45 ( V_10 ) -> V_86 > 3 &&
( V_76 -> V_1006 [ 0 ] != V_29 -> V_75 -> V_76 -> V_1006 [ 0 ] ||
V_76 -> V_301 [ 0 ] != V_29 -> V_75 -> V_76 -> V_301 [ 0 ] ) )
return - V_270 ;
if ( F_653 ( & V_12 -> V_334 ) )
goto V_1007;
V_388 = F_474 ( sizeof( * V_388 ) , V_713 ) ;
if ( V_388 == NULL )
return - V_887 ;
V_388 -> V_389 = V_389 ;
V_388 -> V_29 = V_29 ;
V_388 -> V_956 = F_197 ( V_330 ) ;
F_654 ( & V_388 -> V_388 , F_612 ) ;
V_264 = F_93 ( V_29 ) ;
if ( V_264 )
goto V_1008;
F_224 ( & V_10 -> V_336 , V_332 ) ;
if ( V_73 -> V_337 ) {
if ( F_648 ( V_10 , V_29 ) ) {
F_140 ( L_174 ) ;
F_252 ( V_73 ) ;
} else {
F_140 ( L_175 ) ;
F_225 ( & V_10 -> V_336 , V_332 ) ;
F_94 ( V_29 ) ;
F_195 ( V_388 ) ;
return - V_339 ;
}
}
V_73 -> V_337 = V_388 ;
F_225 ( & V_10 -> V_336 , V_332 ) ;
if ( F_223 ( & V_73 -> V_386 ) >= 2 )
F_655 ( V_12 -> V_391 ) ;
V_264 = F_573 ( V_10 ) ;
if ( V_264 )
goto V_1009;
F_656 ( & V_388 -> V_956 -> V_8 ) ;
F_656 ( & V_260 -> V_8 ) ;
V_29 -> V_75 -> V_76 = V_76 ;
V_388 -> V_392 = V_260 ;
F_657 ( & V_73 -> V_386 ) ;
V_73 -> V_335 = F_223 ( & V_12 -> V_334 . V_335 ) ;
if ( F_45 ( V_10 ) -> V_86 >= 5 || F_16 ( V_10 ) )
V_388 -> V_962 = F_5 ( F_620 ( V_4 ) ) + 1 ;
if ( F_19 ( V_10 ) ) {
V_947 = & V_12 -> V_947 [ V_1010 ] ;
if ( V_260 -> V_266 != V_388 -> V_956 -> V_266 )
V_947 = NULL ;
} else if ( F_235 ( V_10 ) ) {
V_947 = & V_12 -> V_947 [ V_1010 ] ;
} else if ( F_45 ( V_10 ) -> V_86 >= 7 ) {
V_947 = V_260 -> V_947 ;
if ( V_947 == NULL || V_947 -> V_226 != V_981 )
V_947 = & V_12 -> V_947 [ V_1010 ] ;
} else {
V_947 = & V_12 -> V_947 [ V_981 ] ;
}
V_264 = F_174 ( V_10 , V_260 , V_947 ) ;
if ( V_264 )
goto V_1011;
V_388 -> V_961 =
F_198 ( V_260 ) + V_73 -> V_322 ;
if ( F_639 ( V_947 , V_260 ) ) {
V_264 = F_646 ( V_10 , V_29 , V_76 , V_260 , V_947 ,
V_1005 ) ;
if ( V_264 )
goto V_1012;
V_388 -> V_1002 = V_260 -> V_989 ;
V_388 -> V_1001 = V_260 -> V_947 ;
} else {
V_264 = V_12 -> V_251 . V_1013 ( V_10 , V_29 , V_76 , V_260 , V_947 ,
V_1005 ) ;
if ( V_264 )
goto V_1012;
V_388 -> V_1002 = F_658 ( V_947 ) ;
V_388 -> V_1001 = V_947 ;
}
V_388 -> V_1003 = F_649 ( V_10 , V_73 -> V_4 ) ;
V_388 -> V_999 = true ;
F_227 ( V_388 -> V_956 , V_260 ,
F_192 ( V_4 ) ) ;
F_320 ( V_10 ) ;
F_607 ( V_10 , F_192 ( V_4 ) ) ;
F_61 ( & V_10 -> V_265 ) ;
F_659 ( V_73 -> V_153 , V_260 ) ;
return 0 ;
V_1012:
F_184 ( V_260 ) ;
V_1011:
F_614 ( & V_73 -> V_386 ) ;
V_29 -> V_75 -> V_76 = V_330 ;
F_193 ( & V_388 -> V_956 -> V_8 ) ;
F_193 ( & V_260 -> V_8 ) ;
F_61 ( & V_10 -> V_265 ) ;
V_1009:
F_224 ( & V_10 -> V_336 , V_332 ) ;
V_73 -> V_337 = NULL ;
F_225 ( & V_10 -> V_336 , V_332 ) ;
F_94 ( V_29 ) ;
V_1008:
F_195 ( V_388 ) ;
if ( V_264 == - V_1014 ) {
V_1007:
F_259 ( V_29 ) ;
V_264 = F_226 ( V_29 , V_29 -> V_253 , V_29 -> V_254 , V_76 ) ;
if ( V_264 == 0 && V_389 ) {
F_224 ( & V_10 -> V_336 , V_332 ) ;
F_255 ( V_10 , V_4 , V_389 ) ;
F_225 ( & V_10 -> V_336 , V_332 ) ;
}
}
return V_264 ;
}
static void F_660 ( struct V_9 * V_10 )
{
struct V_73 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_393 (connector, &dev->mode_config.connector_list,
base.head) {
V_3 -> V_917 =
F_394 ( V_3 -> V_8 . V_6 ) ;
}
F_480 (dev, encoder) {
V_6 -> V_916 =
F_35 ( V_6 -> V_8 . V_29 ) ;
}
F_130 (dev, crtc) {
V_29 -> V_518 = V_29 -> V_8 . V_108 ;
if ( V_29 -> V_518 )
V_29 -> V_519 = & V_29 -> V_77 ;
else
V_29 -> V_519 = NULL ;
}
}
static void F_661 ( struct V_9 * V_10 )
{
struct V_73 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_393 (connector, &dev->mode_config.connector_list,
base.head) {
V_3 -> V_8 . V_6 = & V_3 -> V_917 -> V_8 ;
}
F_480 (dev, encoder) {
V_6 -> V_8 . V_29 = & V_6 -> V_916 -> V_8 ;
}
F_130 (dev, crtc) {
V_29 -> V_8 . V_108 = V_29 -> V_518 ;
}
}
static void
F_662 ( struct V_2 * V_3 ,
struct V_463 * V_464 )
{
int V_764 = V_464 -> V_553 ;
F_47 ( L_176 ,
V_3 -> V_8 . V_8 . V_226 ,
V_3 -> V_8 . V_123 ) ;
if ( V_3 -> V_8 . V_1015 . V_420 &&
V_3 -> V_8 . V_1015 . V_420 * 3 < V_764 ) {
F_47 ( L_177 ,
V_764 , V_3 -> V_8 . V_1015 . V_420 * 3 ) ;
V_464 -> V_553 = V_3 -> V_8 . V_1015 . V_420 * 3 ;
}
if ( V_3 -> V_8 . V_1015 . V_420 == 0 && V_764 > 24 ) {
F_47 ( L_178 ,
V_764 ) ;
V_464 -> V_553 = 24 ;
}
}
static int
F_663 ( struct V_73 * V_29 ,
struct V_307 * V_76 ,
struct V_463 * V_464 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_2 * V_3 ;
int V_764 ;
switch ( V_76 -> V_302 ) {
case V_282 :
V_764 = 8 * 3 ;
break;
case V_284 :
case V_315 :
if ( F_3 ( F_45 ( V_10 ) -> V_86 > 3 ) )
return - V_270 ;
case V_286 :
V_764 = 6 * 3 ;
break;
case V_290 :
case V_317 :
if ( F_3 ( F_45 ( V_10 ) -> V_86 < 4 ) )
return - V_270 ;
case V_288 :
case V_316 :
V_764 = 8 * 3 ;
break;
case V_292 :
case V_318 :
case V_294 :
case V_319 :
if ( F_3 ( F_45 ( V_10 ) -> V_86 < 4 ) )
return - V_270 ;
V_764 = 10 * 3 ;
break;
default:
F_47 ( L_179 ) ;
return - V_270 ;
}
V_464 -> V_553 = V_764 ;
F_393 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_3 -> V_917 ||
V_3 -> V_917 -> V_916 != V_29 )
continue;
F_662 ( V_3 , V_464 ) ;
}
return V_764 ;
}
static void F_664 ( const struct V_343 * V_425 )
{
F_47 ( L_180
L_181 ,
V_425 -> V_79 ,
V_425 -> V_344 , V_425 -> V_673 ,
V_425 -> V_676 , V_425 -> V_672 ,
V_425 -> V_345 , V_425 -> V_678 ,
V_425 -> V_679 , V_425 -> V_668 , V_425 -> type , V_425 -> V_332 ) ;
}
static void F_665 ( struct V_73 * V_29 ,
struct V_463 * V_464 ,
const char * V_1016 )
{
F_47 ( L_182 , V_29 -> V_8 . V_8 . V_226 ,
V_1016 , F_42 ( V_29 -> V_4 ) ) ;
F_47 ( L_183 , F_666 ( V_464 -> V_82 ) ) ;
F_47 ( L_184 ,
V_464 -> V_553 , V_464 -> V_687 ) ;
F_47 ( L_185 ,
V_464 -> V_246 ,
V_464 -> V_366 ,
V_464 -> V_454 . V_590 , V_464 -> V_454 . V_591 ,
V_464 -> V_454 . V_592 , V_464 -> V_454 . V_593 ,
V_464 -> V_454 . V_589 ) ;
F_47 ( L_186 ,
V_464 -> V_453 ,
V_464 -> V_609 . V_590 , V_464 -> V_609 . V_591 ,
V_464 -> V_609 . V_592 , V_464 -> V_609 . V_593 ,
V_464 -> V_609 . V_589 ) ;
F_47 ( L_187 ,
V_464 -> V_453 ,
V_464 -> V_610 . V_590 ,
V_464 -> V_610 . V_591 ,
V_464 -> V_610 . V_592 ,
V_464 -> V_610 . V_593 ,
V_464 -> V_610 . V_589 ) ;
F_47 ( L_188 ) ;
F_667 ( & V_464 -> V_680 ) ;
F_47 ( L_189 ) ;
F_667 ( & V_464 -> V_78 ) ;
F_664 ( & V_464 -> V_78 ) ;
F_47 ( L_190 , V_464 -> V_633 ) ;
F_47 ( L_191 ,
V_464 -> V_314 , V_464 -> V_313 ) ;
F_47 ( L_192 ,
V_464 -> V_465 . V_466 ,
V_464 -> V_465 . V_470 ,
V_464 -> V_465 . V_708 ) ;
F_47 ( L_193 ,
V_464 -> V_346 . V_436 ,
V_464 -> V_346 . V_299 ,
V_464 -> V_346 . V_108 ? L_194 : L_195 ) ;
F_47 ( L_196 , V_464 -> V_438 ) ;
F_47 ( L_197 , V_464 -> V_247 ) ;
}
static bool F_668 ( const struct V_1 * V_959 ,
const struct V_1 * V_960 )
{
return V_959 == V_960 || ( V_959 -> V_1017 & ( 1 << V_960 -> type ) &&
V_960 -> V_1017 & ( 1 << V_959 -> type ) ) ;
}
static bool F_669 ( struct V_73 * V_29 ,
struct V_1 * V_6 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_1018 ;
F_480 (dev, source_encoder) {
if ( V_1018 -> V_916 != V_29 )
continue;
if ( ! F_668 ( V_6 , V_1018 ) )
return false ;
}
return true ;
}
static bool F_670 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_6 ;
F_480 (dev, encoder) {
if ( V_6 -> V_916 != V_29 )
continue;
if ( ! F_669 ( V_29 , V_6 ) )
return false ;
}
return true ;
}
static struct V_463 *
F_671 ( struct V_28 * V_29 ,
struct V_307 * V_76 ,
struct V_343 * V_425 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_6 ;
struct V_463 * V_464 ;
int V_1019 , V_264 = - V_270 ;
bool V_371 = true ;
if ( ! F_670 ( F_35 ( V_29 ) ) ) {
F_47 ( L_198 ) ;
return F_571 ( - V_270 ) ;
}
V_464 = F_474 ( sizeof( * V_464 ) , V_713 ) ;
if ( ! V_464 )
return F_571 ( - V_887 ) ;
F_672 ( & V_464 -> V_78 , V_425 ) ;
F_672 ( & V_464 -> V_680 , V_425 ) ;
V_464 -> V_82 =
(enum V_80 ) F_35 ( V_29 ) -> V_4 ;
V_464 -> V_117 = V_430 ;
if ( ! ( V_464 -> V_78 . V_332 &
( V_426 | V_1020 ) ) )
V_464 -> V_78 . V_332 |= V_1020 ;
if ( ! ( V_464 -> V_78 . V_332 &
( V_428 | V_1021 ) ) )
V_464 -> V_78 . V_332 |= V_1021 ;
V_1019 = F_663 ( F_35 ( V_29 ) ,
V_76 , V_464 ) ;
if ( V_1019 < 0 )
goto V_888;
F_673 ( & V_464 -> V_680 , V_1022 ) ;
V_464 -> V_314 = V_464 -> V_680 . V_344 ;
V_464 -> V_313 = V_464 -> V_680 . V_345 ;
V_1023:
V_464 -> V_633 = 0 ;
V_464 -> V_459 = 1 ;
F_673 ( & V_464 -> V_78 , V_1022 ) ;
F_480 (dev, encoder) {
if ( & V_6 -> V_916 -> V_8 != V_29 )
continue;
if ( ! ( V_6 -> V_1024 ( V_6 , V_464 ) ) ) {
F_47 ( L_199 ) ;
goto V_888;
}
}
if ( ! V_464 -> V_633 )
V_464 -> V_633 = V_464 -> V_78 . V_79
* V_464 -> V_459 ;
V_264 = F_409 ( F_35 ( V_29 ) , V_464 ) ;
if ( V_264 < 0 ) {
F_47 ( L_200 ) ;
goto V_888;
}
if ( V_264 == V_555 ) {
if ( F_41 ( ! V_371 , L_201 ) ) {
V_264 = - V_270 ;
goto V_888;
}
F_47 ( L_202 ) ;
V_371 = false ;
goto V_1023;
}
V_464 -> V_687 = V_464 -> V_553 != V_1019 ;
F_47 ( L_203 ,
V_1019 , V_464 -> V_553 , V_464 -> V_687 ) ;
return V_464 ;
V_888:
F_195 ( V_464 ) ;
return F_571 ( V_264 ) ;
}
static void
F_674 ( struct V_28 * V_29 , unsigned * V_1025 ,
unsigned * V_520 , unsigned * V_1026 )
{
struct V_73 * V_73 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
struct V_28 * V_1027 ;
* V_1026 = * V_1025 = * V_520 = 0 ;
F_393 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_8 . V_6 == & V_3 -> V_917 -> V_8 )
continue;
if ( V_3 -> V_8 . V_6 ) {
V_1027 = V_3 -> V_8 . V_6 -> V_29 ;
* V_520 |= 1 << F_35 ( V_1027 ) -> V_4 ;
}
if ( V_3 -> V_917 )
* V_520 |=
1 << V_3 -> V_917 -> V_916 -> V_4 ;
}
F_480 (dev, encoder) {
if ( V_6 -> V_8 . V_29 == & V_6 -> V_916 -> V_8 )
continue;
if ( V_6 -> V_8 . V_29 ) {
V_1027 = V_6 -> V_8 . V_29 ;
* V_520 |= 1 << F_35 ( V_1027 ) -> V_4 ;
}
if ( V_6 -> V_916 )
* V_520 |= 1 << V_6 -> V_916 -> V_4 ;
}
F_130 (dev, intel_crtc) {
if ( V_73 -> V_8 . V_108 == V_73 -> V_518 )
continue;
if ( ! V_73 -> V_518 )
* V_1026 |= 1 << V_73 -> V_4 ;
else
* V_520 |= 1 << V_73 -> V_4 ;
}
V_73 = F_35 ( V_29 ) ;
if ( V_73 -> V_518 )
* V_520 |= 1 << V_73 -> V_4 ;
if ( * V_520 )
* V_1025 = * V_520 ;
* V_1025 &= ~ ( * V_1026 ) ;
* V_520 &= ~ ( * V_1026 ) ;
* V_1025 &= 1 << V_73 -> V_4 ;
* V_520 &= 1 << V_73 -> V_4 ;
F_47 ( L_204 ,
* V_1025 , * V_520 , * V_1026 ) ;
}
static bool F_675 ( struct V_28 * V_29 )
{
struct V_545 * V_6 ;
struct V_9 * V_10 = V_29 -> V_10 ;
F_393 (encoder, &dev->mode_config.encoder_list, head)
if ( V_6 -> V_29 == V_29 )
return true ;
return false ;
}
static void
F_676 ( struct V_9 * V_10 , unsigned V_520 )
{
struct V_1 * V_1 ;
struct V_73 * V_73 ;
struct V_541 * V_3 ;
F_480 (dev, intel_encoder) {
if ( ! V_1 -> V_8 . V_29 )
continue;
V_73 = F_35 ( V_1 -> V_8 . V_29 ) ;
if ( V_520 & ( 1 << V_73 -> V_4 ) )
V_1 -> V_540 = false ;
}
F_661 ( V_10 ) ;
F_130 (dev, intel_crtc) {
F_3 ( V_73 -> V_8 . V_108 != F_675 ( & V_73 -> V_8 ) ) ;
F_3 ( V_73 -> V_519 &&
V_73 -> V_519 != & V_73 -> V_77 ) ;
F_3 ( V_73 -> V_8 . V_108 != ! ! V_73 -> V_519 ) ;
}
F_393 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_3 -> V_6 || ! V_3 -> V_6 -> V_29 )
continue;
V_73 = F_35 ( V_3 -> V_6 -> V_29 ) ;
if ( V_520 & ( 1 << V_73 -> V_4 ) ) {
struct V_1028 * V_1029 =
V_10 -> V_910 . V_1029 ;
V_3 -> V_543 = V_546 ;
F_677 ( & V_3 -> V_8 ,
V_1029 ,
V_546 ) ;
V_1 = F_394 ( V_3 -> V_6 ) ;
V_1 -> V_540 = true ;
}
}
}
static bool F_678 ( int V_1030 , int V_1031 )
{
int V_71 ;
if ( V_1030 == V_1031 )
return true ;
if ( ! V_1030 || ! V_1031 )
return false ;
V_71 = abs ( V_1030 - V_1031 ) ;
if ( ( ( ( ( V_71 + V_1030 + V_1031 ) * 100 ) ) / ( V_1030 + V_1031 ) ) < 105 )
return true ;
return false ;
}
static bool
F_679 ( struct V_9 * V_10 ,
struct V_463 * V_1032 ,
struct V_463 * V_464 )
{
#define F_680 ( V_123 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_681 ( V_123 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_682 ( V_123 , T_8 ) \
if ((current_config->name != pipe_config->name) && \
(current_config->alt_name != pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i or %i, found %i)\n", \
current_config->name, \
current_config->alt_name, \
pipe_config->name); \
return false; \
}
#define F_683 ( V_123 , V_483 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
DRM_ERROR("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
return false; \
}
#define F_684 ( V_123 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_685 ( T_9 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_681 ( V_82 ) ;
F_681 ( V_246 ) ;
F_681 ( V_366 ) ;
F_681 ( V_454 . V_590 ) ;
F_681 ( V_454 . V_591 ) ;
F_681 ( V_454 . V_592 ) ;
F_681 ( V_454 . V_593 ) ;
F_681 ( V_454 . V_589 ) ;
F_681 ( V_453 ) ;
if ( F_45 ( V_10 ) -> V_86 < 8 ) {
F_681 ( V_609 . V_590 ) ;
F_681 ( V_609 . V_591 ) ;
F_681 ( V_609 . V_592 ) ;
F_681 ( V_609 . V_593 ) ;
F_681 ( V_609 . V_589 ) ;
if ( V_1032 -> V_608 ) {
F_681 ( V_610 . V_590 ) ;
F_681 ( V_610 . V_591 ) ;
F_681 ( V_610 . V_592 ) ;
F_681 ( V_610 . V_593 ) ;
F_681 ( V_610 . V_589 ) ;
}
} else {
F_682 ( V_609 . V_590 , V_610 . V_590 ) ;
F_682 ( V_609 . V_591 , V_610 . V_591 ) ;
F_682 ( V_609 . V_592 , V_610 . V_592 ) ;
F_682 ( V_609 . V_593 , V_610 . V_593 ) ;
F_682 ( V_609 . V_589 , V_610 . V_589 ) ;
}
F_681 ( V_78 . V_344 ) ;
F_681 ( V_78 . V_672 ) ;
F_681 ( V_78 . V_674 ) ;
F_681 ( V_78 . V_675 ) ;
F_681 ( V_78 . V_673 ) ;
F_681 ( V_78 . V_676 ) ;
F_681 ( V_78 . V_345 ) ;
F_681 ( V_78 . V_668 ) ;
F_681 ( V_78 . V_677 ) ;
F_681 ( V_78 . V_669 ) ;
F_681 ( V_78 . V_678 ) ;
F_681 ( V_78 . V_679 ) ;
F_681 ( V_459 ) ;
F_681 ( V_1033 ) ;
if ( ( F_45 ( V_10 ) -> V_86 < 8 && ! F_210 ( V_10 ) ) ||
F_19 ( V_10 ) )
F_681 ( V_697 ) ;
F_681 ( V_1034 ) ;
F_683 ( V_78 . V_332 ,
V_671 ) ;
if ( ! F_685 ( V_1035 ) ) {
F_683 ( V_78 . V_332 ,
V_426 ) ;
F_683 ( V_78 . V_332 ,
V_1020 ) ;
F_683 ( V_78 . V_332 ,
V_428 ) ;
F_683 ( V_78 . V_332 ,
V_1021 ) ;
}
F_681 ( V_314 ) ;
F_681 ( V_313 ) ;
if ( ! F_685 ( V_1036 ) ) {
F_681 ( V_465 . V_466 ) ;
if ( F_45 ( V_10 ) -> V_86 < 4 )
F_681 ( V_465 . V_470 ) ;
F_681 ( V_465 . V_708 ) ;
}
F_681 ( V_346 . V_108 ) ;
if ( V_1032 -> V_346 . V_108 ) {
F_681 ( V_346 . V_436 ) ;
F_681 ( V_346 . V_299 ) ;
}
if ( F_210 ( V_10 ) )
F_681 ( V_438 ) ;
F_681 ( V_247 ) ;
F_680 ( V_815 ) ;
F_681 ( V_117 ) ;
F_680 ( V_199 . V_54 ) ;
F_680 ( V_199 . V_201 ) ;
F_680 ( V_199 . V_524 ) ;
F_680 ( V_199 . V_525 ) ;
F_680 ( V_199 . V_1037 ) ;
if ( F_16 ( V_10 ) || F_45 ( V_10 ) -> V_86 >= 5 )
F_681 ( V_553 ) ;
F_684 ( V_78 . V_79 ) ;
F_684 ( V_633 ) ;
#undef F_680
#undef F_681
#undef F_682
#undef F_683
#undef F_684
#undef F_685
return true ;
}
static void
F_686 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
F_393 (connector, &dev->mode_config.connector_list,
base.head) {
F_398 ( V_3 ) ;
F_41 ( & V_3 -> V_917 -> V_8 != V_3 -> V_8 . V_6 ,
L_205 ) ;
}
}
static void
F_687 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_480 (dev, encoder) {
bool V_108 = false ;
bool V_74 = false ;
enum V_4 V_4 , V_1038 ;
F_47 ( L_206 ,
V_6 -> V_8 . V_8 . V_226 ,
V_6 -> V_8 . V_123 ) ;
F_41 ( & V_6 -> V_916 -> V_8 != V_6 -> V_8 . V_29 ,
L_207 ) ;
F_41 ( V_6 -> V_540 && ! V_6 -> V_8 . V_29 ,
L_208 ) ;
F_393 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_8 . V_6 != & V_6 -> V_8 )
continue;
V_108 = true ;
if ( V_3 -> V_8 . V_543 != V_544 )
V_74 = true ;
}
if ( ! V_108 && V_6 -> V_8 . V_1039 == V_1040 )
continue;
F_41 ( ! ! V_6 -> V_8 . V_29 != V_108 ,
L_209
L_210 ,
! ! V_6 -> V_8 . V_29 , V_108 ) ;
F_41 ( V_74 && ! V_6 -> V_8 . V_29 ,
L_211 ) ;
F_41 ( V_6 -> V_540 != V_74 ,
L_212
L_210 , V_74 , V_6 -> V_540 ) ;
V_74 = V_6 -> V_122 ( V_6 , & V_4 ) ;
F_41 ( V_74 != V_6 -> V_540 ,
L_213
L_210 ,
V_6 -> V_540 , V_74 ) ;
if ( ! V_6 -> V_8 . V_29 )
continue;
V_1038 = F_35 ( V_6 -> V_8 . V_29 ) -> V_4 ;
F_41 ( V_74 && V_4 != V_1038 ,
L_214
L_210 ,
V_1038 , V_4 ) ;
}
}
static void
F_688 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_29 ;
struct V_1 * V_6 ;
struct V_463 V_464 ;
F_130 (dev, crtc) {
bool V_108 = false ;
bool V_74 = false ;
memset ( & V_464 , 0 , sizeof( V_464 ) ) ;
F_47 ( L_215 ,
V_29 -> V_8 . V_8 . V_226 ) ;
F_41 ( V_29 -> V_74 && ! V_29 -> V_8 . V_108 ,
L_216 ) ;
F_480 (dev, encoder) {
if ( V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
V_108 = true ;
if ( V_6 -> V_540 )
V_74 = true ;
}
F_41 ( V_74 != V_29 -> V_74 ,
L_217
L_210 , V_74 , V_29 -> V_74 ) ;
F_41 ( V_108 != V_29 -> V_8 . V_108 ,
L_218
L_210 , V_108 , V_29 -> V_8 . V_108 ) ;
V_74 = V_12 -> V_251 . V_1041 ( V_29 ,
& V_464 ) ;
if ( ( V_29 -> V_4 == V_131 && V_12 -> V_149 & V_150 ) ||
( V_29 -> V_4 == V_140 && V_12 -> V_149 & V_151 ) )
V_74 = V_29 -> V_74 ;
F_480 (dev, encoder) {
enum V_4 V_4 ;
if ( V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
if ( V_6 -> V_122 ( V_6 , & V_4 ) )
V_6 -> V_1042 ( V_6 , & V_464 ) ;
}
F_41 ( V_29 -> V_74 != V_74 ,
L_219
L_210 , V_29 -> V_74 , V_74 ) ;
if ( V_74 &&
! F_679 ( V_10 , & V_29 -> V_77 , & V_464 ) ) {
F_41 ( 1 , L_220 ) ;
F_665 ( V_29 , & V_464 ,
L_221 ) ;
F_665 ( V_29 , & V_29 -> V_77 ,
L_222 ) ;
}
}
}
static void
F_689 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_29 ;
struct V_120 V_199 ;
int V_155 ;
for ( V_155 = 0 ; V_155 < V_12 -> V_432 ; V_155 ++ ) {
struct V_116 * V_119 = & V_12 -> V_118 [ V_155 ] ;
int V_1043 = 0 , V_1044 = 0 ;
bool V_74 ;
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
F_47 ( L_223 , V_119 -> V_123 ) ;
V_74 = V_119 -> V_122 ( V_12 , V_119 , & V_199 ) ;
F_41 ( V_119 -> V_74 > V_119 -> V_223 ,
L_224 ,
V_119 -> V_74 , V_119 -> V_223 ) ;
F_41 ( V_119 -> V_74 && ! V_119 -> V_224 ,
L_225 ) ;
F_41 ( V_119 -> V_224 && ! V_119 -> V_74 ,
L_226 ) ;
F_41 ( V_119 -> V_224 != V_74 ,
L_227 ,
V_119 -> V_224 , V_74 ) ;
F_130 (dev, crtc) {
if ( V_29 -> V_8 . V_108 && F_62 ( V_29 ) == V_119 )
V_1043 ++ ;
if ( V_29 -> V_74 && F_62 ( V_29 ) == V_119 )
V_1044 ++ ;
}
F_41 ( V_119 -> V_74 != V_1044 ,
L_228 ,
V_119 -> V_74 , V_1044 ) ;
F_41 ( V_119 -> V_223 != V_1043 ,
L_229 ,
V_119 -> V_223 , V_1043 ) ;
F_41 ( V_119 -> V_224 && memcmp ( & V_119 -> V_121 , & V_199 ,
sizeof( V_199 ) ) ,
L_230 ) ;
}
}
void
F_400 ( struct V_9 * V_10 )
{
F_686 ( V_10 ) ;
F_687 ( V_10 ) ;
F_688 ( V_10 ) ;
F_689 ( V_10 ) ;
}
void F_690 ( const struct V_463 * V_464 ,
int V_1045 )
{
F_41 ( ! F_678 ( V_464 -> V_78 . V_79 , V_1045 ) ,
L_231 ,
V_464 -> V_78 . V_79 , V_1045 ) ;
}
static void F_691 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
if ( F_20 ( V_10 ) ) {
const struct V_343 * V_425 = & V_29 -> V_77 . V_78 ;
int V_683 ;
V_683 = V_425 -> V_668 ;
if ( V_425 -> V_332 & V_671 )
V_683 /= 2 ;
V_29 -> V_1046 = V_683 - 1 ;
} else if ( F_65 ( V_10 ) &&
F_10 ( & V_29 -> V_8 , V_39 ) ) {
V_29 -> V_1046 = 2 ;
} else
V_29 -> V_1046 = 1 ;
}
static int F_692 ( struct V_28 * V_29 ,
struct V_343 * V_425 ,
int V_253 , int V_254 , struct V_307 * V_76 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_343 * V_1047 ;
struct V_463 * V_464 = NULL ;
struct V_73 * V_73 ;
unsigned V_1026 , V_520 , V_1025 ;
int V_264 = 0 ;
V_1047 = F_693 ( sizeof( * V_1047 ) , V_713 ) ;
if ( ! V_1047 )
return - V_887 ;
F_674 ( V_29 , & V_1025 ,
& V_520 , & V_1026 ) ;
* V_1047 = V_29 -> V_425 ;
if ( V_1025 ) {
V_464 = F_671 ( V_29 , V_76 , V_425 ) ;
if ( F_583 ( V_464 ) ) {
V_264 = F_694 ( V_464 ) ;
V_464 = NULL ;
goto V_946;
}
F_665 ( F_35 ( V_29 ) , V_464 ,
L_232 ) ;
F_35 ( V_29 ) -> V_519 = V_464 ;
}
if ( F_19 ( V_10 ) ) {
F_374 ( V_10 , & V_520 ) ;
V_520 &= ~ V_1026 ;
}
F_695 (dev, disable_pipes, intel_crtc)
F_392 ( & V_73 -> V_8 ) ;
F_695 (dev, prepare_pipes, intel_crtc) {
if ( V_73 -> V_8 . V_108 )
V_12 -> V_251 . V_539 ( & V_73 -> V_8 ) ;
}
if ( V_1025 ) {
V_29 -> V_425 = * V_425 ;
F_35 ( V_29 ) -> V_77 = * V_464 ;
F_35 ( V_29 ) -> V_519 = & F_35 ( V_29 ) -> V_77 ;
F_696 ( V_29 ,
& V_464 -> V_78 ) ;
}
F_676 ( V_10 , V_520 ) ;
if ( V_12 -> V_251 . V_1048 )
V_12 -> V_251 . V_1048 ( V_10 ) ;
F_695 (dev, modeset_pipes, intel_crtc) {
struct V_307 * V_330 = V_29 -> V_75 -> V_76 ;
struct V_259 * V_338 = F_197 ( V_330 ) ;
struct V_259 * V_260 = F_197 ( V_76 ) ;
F_59 ( & V_10 -> V_265 ) ;
V_264 = F_174 ( V_10 ,
V_260 ,
NULL ) ;
if ( V_264 != 0 ) {
F_122 ( L_56 ) ;
F_61 ( & V_10 -> V_265 ) ;
goto V_1049;
}
if ( V_330 )
F_184 ( V_338 ) ;
F_227 ( V_338 , V_260 ,
F_192 ( V_73 -> V_4 ) ) ;
F_61 ( & V_10 -> V_265 ) ;
V_29 -> V_75 -> V_76 = V_76 ;
V_29 -> V_253 = V_253 ;
V_29 -> V_254 = V_254 ;
V_264 = V_12 -> V_251 . V_1050 ( & V_73 -> V_8 ,
V_253 , V_254 , V_76 ) ;
if ( V_264 )
goto V_1049;
}
F_695 (dev, prepare_pipes, intel_crtc) {
F_691 ( V_73 ) ;
V_12 -> V_251 . V_538 ( & V_73 -> V_8 ) ;
}
V_1049:
if ( V_264 && V_29 -> V_108 )
V_29 -> V_425 = * V_1047 ;
V_946:
F_195 ( V_464 ) ;
F_195 ( V_1047 ) ;
return V_264 ;
}
static int F_584 ( struct V_28 * V_29 ,
struct V_343 * V_425 ,
int V_253 , int V_254 , struct V_307 * V_76 )
{
int V_264 ;
V_264 = F_692 ( V_29 , V_425 , V_253 , V_254 , V_76 ) ;
if ( V_264 == 0 )
F_400 ( V_29 -> V_10 ) ;
return V_264 ;
}
void F_697 ( struct V_28 * V_29 )
{
F_584 ( V_29 , & V_29 -> V_425 , V_29 -> V_253 , V_29 -> V_254 , V_29 -> V_75 -> V_76 ) ;
}
static void F_698 ( struct V_1051 * V_77 )
{
if ( ! V_77 )
return;
F_195 ( V_77 -> V_1052 ) ;
F_195 ( V_77 -> V_1053 ) ;
F_195 ( V_77 -> V_1054 ) ;
F_195 ( V_77 ) ;
}
static int F_699 ( struct V_9 * V_10 ,
struct V_1051 * V_77 )
{
struct V_28 * V_29 ;
struct V_545 * V_6 ;
struct V_541 * V_3 ;
int V_205 ;
V_77 -> V_1054 =
F_700 ( V_10 -> V_910 . V_1055 ,
sizeof( bool ) , V_713 ) ;
if ( ! V_77 -> V_1054 )
return - V_887 ;
V_77 -> V_1053 =
F_700 ( V_10 -> V_910 . V_1056 ,
sizeof( struct V_28 * ) , V_713 ) ;
if ( ! V_77 -> V_1053 )
return - V_887 ;
V_77 -> V_1052 =
F_700 ( V_10 -> V_910 . V_1057 ,
sizeof( struct V_545 * ) , V_713 ) ;
if ( ! V_77 -> V_1052 )
return - V_887 ;
V_205 = 0 ;
F_196 (dev, crtc) {
V_77 -> V_1054 [ V_205 ++ ] = V_29 -> V_108 ;
}
V_205 = 0 ;
F_393 (encoder, &dev->mode_config.encoder_list, head) {
V_77 -> V_1053 [ V_205 ++ ] = V_6 -> V_29 ;
}
V_205 = 0 ;
F_393 (connector, &dev->mode_config.connector_list, head) {
V_77 -> V_1052 [ V_205 ++ ] = V_3 -> V_6 ;
}
return 0 ;
}
static void F_701 ( struct V_9 * V_10 ,
struct V_1051 * V_77 )
{
struct V_73 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
int V_205 ;
V_205 = 0 ;
F_130 (dev, crtc) {
V_29 -> V_518 = V_77 -> V_1054 [ V_205 ++ ] ;
if ( V_29 -> V_518 )
V_29 -> V_519 = & V_29 -> V_77 ;
else
V_29 -> V_519 = NULL ;
}
V_205 = 0 ;
F_480 (dev, encoder) {
V_6 -> V_916 =
F_35 ( V_77 -> V_1053 [ V_205 ++ ] ) ;
}
V_205 = 0 ;
F_393 (connector, &dev->mode_config.connector_list, base.head) {
V_3 -> V_917 =
F_394 ( V_77 -> V_1052 [ V_205 ++ ] ) ;
}
}
static bool
F_702 ( struct V_1058 * V_1059 )
{
int V_155 ;
if ( V_1059 -> V_598 == 0 )
return false ;
if ( F_3 ( V_1059 -> V_1060 == NULL ) )
return false ;
for ( V_155 = 0 ; V_155 < V_1059 -> V_598 ; V_155 ++ )
if ( V_1059 -> V_1060 [ V_155 ] -> V_6 &&
V_1059 -> V_1060 [ V_155 ] -> V_6 -> V_29 == V_1059 -> V_29 &&
V_1059 -> V_1060 [ V_155 ] -> V_543 != V_546 )
return true ;
return false ;
}
static void
F_703 ( struct V_1058 * V_1059 ,
struct V_1051 * V_77 )
{
if ( F_702 ( V_1059 ) ) {
V_77 -> V_1061 = true ;
} else if ( V_1059 -> V_29 -> V_75 -> V_76 != V_1059 -> V_76 ) {
if ( V_1059 -> V_29 -> V_75 -> V_76 == NULL ) {
struct V_73 * V_73 =
F_35 ( V_1059 -> V_29 ) ;
if ( V_73 -> V_74 ) {
F_47 ( L_233 ) ;
V_77 -> V_1062 = true ;
} else {
F_47 ( L_234 ) ;
V_77 -> V_1061 = true ;
}
} else if ( V_1059 -> V_76 == NULL ) {
V_77 -> V_1061 = true ;
} else if ( V_1059 -> V_76 -> V_302 !=
V_1059 -> V_29 -> V_75 -> V_76 -> V_302 ) {
V_77 -> V_1061 = true ;
} else {
V_77 -> V_1062 = true ;
}
}
if ( V_1059 -> V_76 && ( V_1059 -> V_253 != V_1059 -> V_29 -> V_253 || V_1059 -> V_254 != V_1059 -> V_29 -> V_254 ) )
V_77 -> V_1062 = true ;
if ( V_1059 -> V_425 && ! F_704 ( V_1059 -> V_425 , & V_1059 -> V_29 -> V_425 ) ) {
F_47 ( L_235 ) ;
F_667 ( & V_1059 -> V_29 -> V_425 ) ;
F_667 ( V_1059 -> V_425 ) ;
V_77 -> V_1061 = true ;
}
F_47 ( L_236 ,
V_1059 -> V_29 -> V_8 . V_226 , V_77 -> V_1061 , V_77 -> V_1062 ) ;
}
static int
F_705 ( struct V_9 * V_10 ,
struct V_1058 * V_1059 ,
struct V_1051 * V_77 )
{
struct V_2 * V_3 ;
struct V_1 * V_6 ;
struct V_73 * V_29 ;
int V_1063 ;
F_3 ( ! V_1059 -> V_76 && ( V_1059 -> V_598 != 0 ) ) ;
F_3 ( V_1059 -> V_76 && ( V_1059 -> V_598 == 0 ) ) ;
F_393 (connector, &dev->mode_config.connector_list,
base.head) {
for ( V_1063 = 0 ; V_1063 < V_1059 -> V_598 ; V_1063 ++ ) {
if ( V_1059 -> V_1060 [ V_1063 ] == & V_3 -> V_8 ) {
V_3 -> V_917 = F_1 ( V_3 , F_35 ( V_1059 -> V_29 ) -> V_4 ) ;
break;
}
}
if ( ( ! V_1059 -> V_76 || V_1063 == V_1059 -> V_598 ) &&
V_3 -> V_8 . V_6 &&
V_3 -> V_8 . V_6 -> V_29 == V_1059 -> V_29 ) {
V_3 -> V_917 = NULL ;
F_47 ( L_237 ,
V_3 -> V_8 . V_8 . V_226 ,
V_3 -> V_8 . V_123 ) ;
}
if ( & V_3 -> V_917 -> V_8 != V_3 -> V_8 . V_6 ) {
F_47 ( L_238 ) ;
V_77 -> V_1061 = true ;
}
}
F_393 (connector, &dev->mode_config.connector_list,
base.head) {
struct V_28 * V_916 ;
if ( ! V_3 -> V_917 )
continue;
V_916 = V_3 -> V_917 -> V_8 . V_29 ;
for ( V_1063 = 0 ; V_1063 < V_1059 -> V_598 ; V_1063 ++ ) {
if ( V_1059 -> V_1060 [ V_1063 ] == & V_3 -> V_8 )
V_916 = V_1059 -> V_29 ;
}
if ( ! F_706 ( & V_3 -> V_917 -> V_8 ,
V_916 ) ) {
return - V_270 ;
}
V_3 -> V_917 -> V_916 = F_35 ( V_916 ) ;
F_47 ( L_239 ,
V_3 -> V_8 . V_8 . V_226 ,
V_3 -> V_8 . V_123 ,
V_916 -> V_8 . V_226 ) ;
}
F_480 (dev, encoder) {
int V_598 = 0 ;
F_393 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_917 == V_6 ) {
F_3 ( ! V_3 -> V_917 -> V_916 ) ;
V_598 ++ ;
}
}
if ( V_598 == 0 )
V_6 -> V_916 = NULL ;
else if ( V_598 > 1 )
return - V_270 ;
if ( & V_6 -> V_916 -> V_8 != V_6 -> V_8 . V_29 ) {
F_47 ( L_240 ) ;
V_77 -> V_1061 = true ;
}
}
F_393 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_917 )
if ( V_3 -> V_917 != V_3 -> V_6 )
V_3 -> V_6 = V_3 -> V_917 ;
}
F_130 (dev, crtc) {
V_29 -> V_518 = false ;
F_480 (dev, encoder) {
if ( V_6 -> V_916 == V_29 ) {
V_29 -> V_518 = true ;
break;
}
}
if ( V_29 -> V_518 != V_29 -> V_8 . V_108 ) {
F_47 ( L_241 ,
V_29 -> V_518 ? L_242 : L_243 ) ;
V_77 -> V_1061 = true ;
}
if ( V_29 -> V_518 )
V_29 -> V_519 = & V_29 -> V_77 ;
else
V_29 -> V_519 = NULL ;
}
return 0 ;
}
static void F_707 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_47 ( L_244 ,
F_42 ( V_29 -> V_4 ) ) ;
F_393 (connector, &dev->mode_config.connector_list, base.head) {
if ( V_3 -> V_917 &&
V_3 -> V_917 -> V_916 == V_29 )
V_3 -> V_917 = NULL ;
}
F_480 (dev, encoder) {
if ( V_6 -> V_916 == V_29 )
V_6 -> V_916 = NULL ;
}
V_29 -> V_518 = false ;
V_29 -> V_519 = NULL ;
}
static int F_708 ( struct V_1058 * V_1059 )
{
struct V_9 * V_10 ;
struct V_1058 V_1064 ;
struct V_1051 * V_77 ;
int V_264 ;
F_118 ( ! V_1059 ) ;
F_118 ( ! V_1059 -> V_29 ) ;
F_118 ( ! V_1059 -> V_29 -> V_1065 ) ;
F_118 ( ! V_1059 -> V_425 && V_1059 -> V_76 ) ;
F_118 ( V_1059 -> V_76 && V_1059 -> V_598 == 0 ) ;
if ( V_1059 -> V_76 ) {
F_47 ( L_245 ,
V_1059 -> V_29 -> V_8 . V_226 , V_1059 -> V_76 -> V_8 . V_226 ,
( int ) V_1059 -> V_598 , V_1059 -> V_253 , V_1059 -> V_254 ) ;
} else {
F_47 ( L_246 , V_1059 -> V_29 -> V_8 . V_226 ) ;
}
V_10 = V_1059 -> V_29 -> V_10 ;
V_264 = - V_887 ;
V_77 = F_474 ( sizeof( * V_77 ) , V_713 ) ;
if ( ! V_77 )
goto V_1066;
V_264 = F_699 ( V_10 , V_77 ) ;
if ( V_264 )
goto V_1066;
V_1064 . V_29 = V_1059 -> V_29 ;
V_1064 . V_425 = & V_1059 -> V_29 -> V_425 ;
V_1064 . V_253 = V_1059 -> V_29 -> V_253 ;
V_1064 . V_254 = V_1059 -> V_29 -> V_254 ;
V_1064 . V_76 = V_1059 -> V_29 -> V_75 -> V_76 ;
F_703 ( V_1059 , V_77 ) ;
V_264 = F_705 ( V_10 , V_1059 , V_77 ) ;
if ( V_264 )
goto V_888;
if ( V_77 -> V_1061 ) {
V_264 = F_584 ( V_1059 -> V_29 , V_1059 -> V_425 ,
V_1059 -> V_253 , V_1059 -> V_254 , V_1059 -> V_76 ) ;
} else if ( V_77 -> V_1062 ) {
struct V_73 * V_73 = F_35 ( V_1059 -> V_29 ) ;
F_259 ( V_1059 -> V_29 ) ;
V_264 = F_226 ( V_1059 -> V_29 ,
V_1059 -> V_253 , V_1059 -> V_254 , V_1059 -> V_76 ) ;
if ( ! V_73 -> V_250 && V_264 == 0 ) {
F_3 ( ! V_73 -> V_74 ) ;
F_166 ( V_1059 -> V_29 -> V_75 , V_1059 -> V_29 ) ;
}
if ( V_341 . V_342 && V_264 == 0 )
F_400 ( V_1059 -> V_29 -> V_10 ) ;
}
if ( V_264 ) {
F_47 ( L_247 ,
V_1059 -> V_29 -> V_8 . V_226 , V_264 ) ;
V_888:
F_701 ( V_10 , V_77 ) ;
if ( F_35 ( V_1064 . V_29 ) -> V_518 && ! V_1064 . V_76 )
F_707 ( F_35 ( V_1064 . V_29 ) ) ;
if ( V_77 -> V_1061 &&
F_584 ( V_1064 . V_29 , V_1064 . V_425 ,
V_1064 . V_253 , V_1064 . V_254 , V_1064 . V_76 ) )
F_122 ( L_248 ) ;
}
V_1066:
F_698 ( V_77 ) ;
return V_264 ;
}
static bool F_709 ( struct V_11 * V_12 ,
struct V_116 * V_119 ,
struct V_120 * V_121 )
{
T_4 V_110 ;
if ( ! F_79 ( V_12 , V_227 ) )
return false ;
V_110 = F_5 ( F_710 ( V_119 -> V_226 ) ) ;
V_121 -> V_54 = V_110 ;
V_121 -> V_524 = F_5 ( F_711 ( V_119 -> V_226 ) ) ;
V_121 -> V_525 = F_5 ( F_712 ( V_119 -> V_226 ) ) ;
return V_110 & V_112 ;
}
static void F_713 ( struct V_11 * V_12 ,
struct V_116 * V_119 )
{
F_46 ( F_711 ( V_119 -> V_226 ) , V_119 -> V_121 . V_524 ) ;
F_46 ( F_712 ( V_119 -> V_226 ) , V_119 -> V_121 . V_525 ) ;
}
static void F_714 ( struct V_11 * V_12 ,
struct V_116 * V_119 )
{
F_95 ( V_12 ) ;
F_46 ( F_710 ( V_119 -> V_226 ) , V_119 -> V_121 . V_54 ) ;
F_120 ( F_710 ( V_119 -> V_226 ) ) ;
F_121 ( 150 ) ;
F_46 ( F_710 ( V_119 -> V_226 ) , V_119 -> V_121 . V_54 ) ;
F_120 ( F_710 ( V_119 -> V_226 ) ) ;
F_121 ( 200 ) ;
}
static void F_715 ( struct V_11 * V_12 ,
struct V_116 * V_119 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_73 * V_29 ;
F_130 (dev, crtc) {
if ( F_62 ( V_29 ) == V_119 )
F_97 ( V_12 , V_29 -> V_4 ) ;
}
F_46 ( F_710 ( V_119 -> V_226 ) , 0 ) ;
F_120 ( F_710 ( V_119 -> V_226 ) ) ;
F_121 ( 200 ) ;
}
static void F_716 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_155 ;
V_12 -> V_432 = 2 ;
for ( V_155 = 0 ; V_155 < V_12 -> V_432 ; V_155 ++ ) {
V_12 -> V_118 [ V_155 ] . V_226 = V_155 ;
V_12 -> V_118 [ V_155 ] . V_123 = V_1067 [ V_155 ] ;
V_12 -> V_118 [ V_155 ] . V_225 = F_713 ;
V_12 -> V_118 [ V_155 ] . V_228 = F_714 ;
V_12 -> V_118 [ V_155 ] . V_229 = F_715 ;
V_12 -> V_118 [ V_155 ] . V_122 =
F_709 ;
}
}
static void F_717 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_65 ( V_10 ) )
F_718 ( V_10 ) ;
else if ( F_54 ( V_10 ) || F_96 ( V_10 ) )
F_716 ( V_10 ) ;
else
V_12 -> V_432 = 0 ;
F_118 ( V_12 -> V_432 > V_1068 ) ;
}
static int
F_719 ( struct V_249 * V_153 )
{
struct V_9 * V_10 = V_153 -> V_10 ;
struct V_73 * V_73 ;
if ( ! V_153 -> V_76 )
return 0 ;
F_118 ( ! V_153 -> V_29 ) ;
V_73 = F_35 ( V_153 -> V_29 ) ;
if ( ! V_73 -> V_250 )
goto V_1069;
F_259 ( V_153 -> V_29 ) ;
F_169 ( V_153 , V_153 -> V_29 ) ;
V_1069:
F_59 ( & V_10 -> V_265 ) ;
F_227 ( F_197 ( V_153 -> V_76 ) , NULL ,
F_192 ( V_73 -> V_4 ) ) ;
F_184 ( F_197 ( V_153 -> V_76 ) ) ;
F_61 ( & V_10 -> V_265 ) ;
V_153 -> V_76 = NULL ;
return 0 ;
}
static int
F_720 ( struct V_249 * V_153 , struct V_28 * V_29 ,
struct V_307 * V_76 , int V_1070 , int V_1071 ,
unsigned int V_1072 , unsigned int V_1073 ,
T_4 V_1074 , T_4 V_1075 ,
T_4 V_1076 , T_4 V_1077 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_259 * V_260 = F_197 ( V_76 ) ;
struct V_259 * V_338 = F_197 ( V_153 -> V_76 ) ;
struct V_1078 V_1079 = {
. V_1080 = V_1070 ,
. y1 = V_1071 ,
. V_1081 = V_1070 + V_1072 ,
. V_1082 = V_1071 + V_1073 ,
} ;
struct V_1078 V_1083 = {
. V_1080 = V_1074 ,
. y1 = V_1075 ,
. V_1081 = V_1074 + V_1076 ,
. V_1082 = V_1075 + V_1077 ,
} ;
const struct V_1078 V_1084 = {
. V_1081 = V_73 -> V_74 ? V_73 -> V_77 . V_314 : 0 ,
. V_1082 = V_73 -> V_74 ? V_73 -> V_77 . V_313 : 0 ,
} ;
const struct {
int V_1070 , V_1071 ;
unsigned int V_1072 , V_1073 ;
T_4 V_1074 , V_1075 , V_1076 , V_1077 ;
} V_1085 = {
. V_1070 = V_1070 ,
. V_1071 = V_1071 ,
. V_1072 = V_1072 ,
. V_1073 = V_1073 ,
. V_1074 = V_1074 ,
. V_1075 = V_1075 ,
. V_1076 = V_1076 ,
. V_1077 = V_1077 ,
} ;
struct V_437 * V_437 = F_204 ( V_153 ) ;
bool V_1086 ;
int V_264 ;
V_264 = F_721 ( V_153 , V_29 , V_76 ,
& V_1083 , & V_1079 , & V_1084 ,
V_1087 ,
V_1087 ,
false , true , & V_1086 ) ;
if ( V_264 )
return V_264 ;
if ( ! V_29 -> V_108 ) {
F_59 ( & V_10 -> V_265 ) ;
if ( V_153 -> V_76 )
F_184 ( V_338 ) ;
F_227 ( V_338 , V_260 ,
F_192 ( V_73 -> V_4 ) ) ;
V_264 = F_174 ( V_10 , V_260 , NULL ) ;
F_61 ( & V_10 -> V_265 ) ;
return V_264 ;
}
F_259 ( V_29 ) ;
if ( ! V_1086 ) {
F_59 ( & V_10 -> V_265 ) ;
if ( V_153 -> V_76 != V_76 ) {
V_264 = F_174 ( V_10 , V_260 , NULL ) ;
if ( V_264 ) {
F_61 ( & V_10 -> V_265 ) ;
return V_264 ;
}
}
F_227 ( V_338 , V_260 ,
F_192 ( V_73 -> V_4 ) ) ;
if ( V_73 -> V_250 )
F_169 ( V_153 , V_29 ) ;
if ( V_153 -> V_76 != V_76 )
if ( V_153 -> V_76 )
F_184 ( V_338 ) ;
F_61 ( & V_10 -> V_265 ) ;
} else {
if ( V_73 && V_73 -> V_74 &&
V_73 -> V_250 ) {
if ( F_45 ( V_10 ) -> V_86 <= 4 && ! F_16 ( V_10 ) &&
V_12 -> V_452 . V_153 == V_73 -> V_153 &&
V_437 -> V_323 != F_205 ( V_1088 ) ) {
F_320 ( V_10 ) ;
}
}
V_264 = F_226 ( V_29 , V_1083 . V_1080 , V_1083 . y1 , V_76 ) ;
if ( V_264 )
return V_264 ;
if ( ! V_73 -> V_250 )
F_166 ( V_153 , V_29 ) ;
}
V_437 -> V_1070 = V_1085 . V_1070 ;
V_437 -> V_1071 = V_1085 . V_1071 ;
V_437 -> V_1072 = V_1085 . V_1072 ;
V_437 -> V_1073 = V_1085 . V_1073 ;
V_437 -> V_1074 = V_1085 . V_1074 ;
V_437 -> V_1075 = V_1085 . V_1075 ;
V_437 -> V_1076 = V_1085 . V_1076 ;
V_437 -> V_1077 = V_1085 . V_1077 ;
V_437 -> V_260 = V_260 ;
return 0 ;
}
static void F_722 ( struct V_249 * V_153 )
{
struct V_437 * V_437 = F_204 ( V_153 ) ;
F_723 ( V_153 ) ;
F_195 ( V_437 ) ;
}
static struct V_249 * F_724 ( struct V_9 * V_10 ,
int V_4 )
{
struct V_437 * V_75 ;
const T_4 * V_1089 ;
int V_1090 ;
V_75 = F_474 ( sizeof( * V_75 ) , V_713 ) ;
if ( V_75 == NULL )
return NULL ;
V_75 -> V_1091 = false ;
V_75 -> V_1092 = 1 ;
V_75 -> V_4 = V_4 ;
V_75 -> V_153 = V_4 ;
V_75 -> V_323 = F_205 ( V_1088 ) ;
if ( F_725 ( V_10 ) && F_45 ( V_10 ) -> V_86 < 4 )
V_75 -> V_153 = ! V_4 ;
if ( F_45 ( V_10 ) -> V_86 <= 3 ) {
V_1089 = V_1093 ;
V_1090 = F_247 ( V_1093 ) ;
} else {
V_1089 = V_1094 ;
V_1090 = F_247 ( V_1094 ) ;
}
F_726 ( V_10 , & V_75 -> V_8 , 0 ,
& V_1095 ,
V_1089 , V_1090 ,
V_1096 ) ;
if ( F_45 ( V_10 ) -> V_86 >= 4 ) {
if ( ! V_10 -> V_910 . V_1097 )
V_10 -> V_910 . V_1097 =
F_727 ( V_10 ,
F_205 ( V_1088 ) |
F_205 ( V_324 ) ) ;
if ( V_10 -> V_910 . V_1097 )
F_728 ( & V_75 -> V_8 . V_8 ,
V_10 -> V_910 . V_1097 ,
V_75 -> V_323 ) ;
}
return & V_75 -> V_8 ;
}
static int
F_729 ( struct V_249 * V_153 )
{
if ( ! V_153 -> V_76 )
return 0 ;
F_118 ( ! V_153 -> V_29 ) ;
return F_563 ( V_153 -> V_29 , NULL , 0 , 0 ) ;
}
static int
F_730 ( struct V_249 * V_153 , struct V_28 * V_29 ,
struct V_307 * V_76 , int V_1070 , int V_1071 ,
unsigned int V_1072 , unsigned int V_1073 ,
T_4 V_1074 , T_4 V_1075 ,
T_4 V_1076 , T_4 V_1077 )
{
struct V_73 * V_73 = F_35 ( V_29 ) ;
struct V_712 * V_901 = F_191 ( V_76 ) ;
struct V_259 * V_260 = V_901 -> V_260 ;
struct V_1078 V_1079 = {
. V_1080 = V_1070 ,
. y1 = V_1071 ,
. V_1081 = V_1070 + V_1072 ,
. V_1082 = V_1071 + V_1073 ,
} ;
struct V_1078 V_1083 = {
. V_1080 = V_1074 ,
. y1 = V_1075 ,
. V_1081 = V_1074 + V_1076 ,
. V_1082 = V_1075 + V_1077 ,
} ;
const struct V_1078 V_1084 = {
. V_1081 = V_73 -> V_74 ? V_73 -> V_77 . V_314 : 0 ,
. V_1082 = V_73 -> V_74 ? V_73 -> V_77 . V_313 : 0 ,
} ;
bool V_1086 ;
int V_264 ;
V_264 = F_721 ( V_153 , V_29 , V_76 ,
& V_1083 , & V_1079 , & V_1084 ,
V_1087 ,
V_1087 ,
true , true , & V_1086 ) ;
if ( V_264 )
return V_264 ;
V_29 -> V_878 = V_1070 ;
V_29 -> V_879 = V_1071 ;
if ( V_76 != V_29 -> V_1098 -> V_76 ) {
return F_563 ( V_29 , V_260 , V_1072 , V_1073 ) ;
} else {
F_317 ( V_29 , V_1086 ) ;
F_232 ( V_29 -> V_10 ,
F_567 ( V_73 -> V_4 ) ) ;
return 0 ;
}
}
static struct V_249 * F_731 ( struct V_9 * V_10 ,
int V_4 )
{
struct V_437 * V_1098 ;
V_1098 = F_474 ( sizeof( * V_1098 ) , V_713 ) ;
if ( V_1098 == NULL )
return NULL ;
V_1098 -> V_1091 = false ;
V_1098 -> V_1092 = 1 ;
V_1098 -> V_4 = V_4 ;
V_1098 -> V_153 = V_4 ;
F_726 ( V_10 , & V_1098 -> V_8 , 0 ,
& V_1099 ,
V_1100 ,
F_247 ( V_1100 ) ,
V_1101 ) ;
return & V_1098 -> V_8 ;
}
static void F_732 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_73 * V_73 ;
struct V_249 * V_75 = NULL ;
struct V_249 * V_1098 = NULL ;
int V_155 , V_264 ;
V_73 = F_474 ( sizeof( * V_73 ) , V_713 ) ;
if ( V_73 == NULL )
return;
V_75 = F_724 ( V_10 , V_4 ) ;
if ( ! V_75 )
goto V_888;
V_1098 = F_731 ( V_10 , V_4 ) ;
if ( ! V_1098 )
goto V_888;
V_264 = F_733 ( V_10 , & V_73 -> V_8 , V_75 ,
V_1098 , & V_1102 ) ;
if ( V_264 )
goto V_888;
F_734 ( & V_73 -> V_8 , 256 ) ;
for ( V_155 = 0 ; V_155 < 256 ; V_155 ++ ) {
V_73 -> V_448 [ V_155 ] = V_155 ;
V_73 -> V_449 [ V_155 ] = V_155 ;
V_73 -> V_450 [ V_155 ] = V_155 ;
}
V_73 -> V_4 = V_4 ;
V_73 -> V_153 = V_4 ;
if ( F_725 ( V_10 ) && F_45 ( V_10 ) -> V_86 < 4 ) {
F_47 ( L_249 ) ;
V_73 -> V_153 = ! V_4 ;
}
V_73 -> V_869 = ~ 0 ;
V_73 -> V_868 = ~ 0 ;
V_73 -> V_870 = ~ 0 ;
F_118 ( V_4 >= F_247 ( V_12 -> V_958 ) ||
V_12 -> V_958 [ V_73 -> V_153 ] != NULL ) ;
V_12 -> V_958 [ V_73 -> V_153 ] = & V_73 -> V_8 ;
V_12 -> V_81 [ V_73 -> V_4 ] = & V_73 -> V_8 ;
F_735 ( & V_73 -> V_8 , & V_1103 ) ;
F_3 ( F_736 ( & V_73 -> V_8 ) != V_73 -> V_4 ) ;
return;
V_888:
if ( V_75 )
F_723 ( V_75 ) ;
if ( V_1098 )
F_723 ( V_1098 ) ;
F_195 ( V_73 ) ;
}
enum V_4 F_737 ( struct V_2 * V_3 )
{
struct V_545 * V_6 = V_3 -> V_8 . V_6 ;
struct V_9 * V_10 = V_3 -> V_8 . V_10 ;
F_3 ( ! F_738 ( & V_10 -> V_910 . V_911 ) ) ;
if ( ! V_6 )
return V_1104 ;
return F_35 ( V_6 -> V_29 ) -> V_4 ;
}
int F_739 ( struct V_9 * V_10 , void * V_1105 ,
struct V_1106 * V_1107 )
{
struct V_1108 * V_1109 = V_1105 ;
struct V_28 * V_1110 ;
struct V_73 * V_29 ;
if ( ! F_740 ( V_10 , V_1111 ) )
return - V_980 ;
V_1110 = F_741 ( V_10 , V_1109 -> V_1112 ) ;
if ( ! V_1110 ) {
F_122 ( L_250 ) ;
return - V_1113 ;
}
V_29 = F_35 ( V_1110 ) ;
V_1109 -> V_4 = V_29 -> V_4 ;
return 0 ;
}
static int F_742 ( struct V_1 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_8 . V_10 ;
struct V_1 * V_1018 ;
int V_1114 = 0 ;
int V_1115 = 0 ;
F_480 (dev, source_encoder) {
if ( F_668 ( V_6 , V_1018 ) )
V_1114 |= ( 1 << V_1115 ) ;
V_1115 ++ ;
}
return V_1114 ;
}
static bool F_743 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_119 ( V_10 ) )
return false ;
if ( ( F_5 ( V_1116 ) & V_1117 ) == 0 )
return false ;
if ( F_7 ( V_10 ) && ( F_5 ( V_1118 ) & V_1119 ) )
return false ;
return true ;
}
const char * F_744 ( int V_1120 )
{
static const char * V_1121 [] = {
[ V_1122 ] = L_251 ,
[ V_40 ] = L_252 ,
[ V_51 ] = L_253 ,
[ V_42 ] = L_254 ,
[ V_31 ] = L_255 ,
[ V_1123 ] = L_256 ,
[ V_39 ] = L_257 ,
[ V_419 ] = L_258 ,
[ V_347 ] = L_259 ,
[ V_245 ] = L_260 ,
[ V_479 ] = L_261 ,
} ;
if ( V_1120 < 0 || V_1120 >= F_247 ( V_1121 ) || ! V_1121 [ V_1120 ] )
return L_262 ;
return V_1121 [ V_1120 ] ;
}
static bool F_745 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_746 ( V_10 ) )
return false ;
if ( F_18 ( V_10 ) )
return false ;
if ( F_19 ( V_10 ) && ! V_12 -> V_595 . V_1124 )
return false ;
return true ;
}
static void F_747 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
bool V_1125 = false ;
F_748 ( V_10 ) ;
if ( F_745 ( V_10 ) )
F_749 ( V_10 ) ;
if ( F_65 ( V_10 ) ) {
int V_67 ;
V_67 = F_5 ( V_1126 ) & V_1127 ;
if ( V_67 )
F_750 ( V_10 , V_472 ) ;
V_67 = F_5 ( V_1128 ) ;
if ( V_67 & V_1129 )
F_750 ( V_10 , V_98 ) ;
if ( V_67 & V_1130 )
F_750 ( V_10 , V_100 ) ;
if ( V_67 & V_1131 )
F_750 ( V_10 , V_102 ) ;
} else if ( F_4 ( V_10 ) ) {
int V_67 ;
V_1125 = F_751 ( V_10 , V_102 ) ;
if ( F_743 ( V_10 ) )
F_752 ( V_10 , V_1116 , V_472 ) ;
if ( F_5 ( V_192 ) & V_1132 ) {
V_67 = F_753 ( V_10 , V_1133 , true ) ;
if ( ! V_67 )
F_754 ( V_10 , V_192 , V_98 ) ;
if ( ! V_67 && ( F_5 ( V_185 ) & V_1117 ) )
F_752 ( V_10 , V_185 , V_98 ) ;
}
if ( F_5 ( V_193 ) & V_1132 )
F_754 ( V_10 , V_193 , V_100 ) ;
if ( ! V_1125 && F_5 ( V_194 ) & V_1132 )
F_754 ( V_10 , V_194 , V_102 ) ;
if ( F_5 ( V_187 ) & V_1117 )
F_752 ( V_10 , V_187 , V_100 ) ;
if ( F_5 ( V_189 ) & V_1117 )
F_752 ( V_10 , V_189 , V_102 ) ;
} else if ( F_19 ( V_10 ) ) {
if ( F_5 ( V_1134 + V_1135 ) & V_1132 )
F_754 ( V_10 , V_1134 + V_1135 ,
V_98 ) ;
if ( F_5 ( V_1134 + V_1136 ) & V_1117 ||
F_751 ( V_10 , V_98 ) )
F_752 ( V_10 , V_1134 + V_1136 , V_98 ) ;
if ( F_5 ( V_1134 + V_1137 ) & V_1132 )
F_754 ( V_10 , V_1134 + V_1137 ,
V_100 ) ;
if ( F_5 ( V_1134 + V_1138 ) & V_1117 ||
F_751 ( V_10 , V_100 ) )
F_752 ( V_10 , V_1134 + V_1138 , V_100 ) ;
if ( F_18 ( V_10 ) ) {
if ( F_5 ( V_1134 + V_1139 ) & V_1132 )
F_754 ( V_10 , V_1134 + V_1139 ,
V_102 ) ;
if ( F_5 ( V_1134 + V_1140 ) & V_1117 )
F_752 ( V_10 , V_1134 + V_1140 , V_102 ) ;
}
F_755 ( V_10 ) ;
} else if ( F_756 ( V_10 ) ) {
bool V_67 = false ;
if ( F_5 ( V_1141 ) & V_1132 ) {
F_47 ( L_263 ) ;
V_67 = F_753 ( V_10 , V_1141 , true ) ;
if ( ! V_67 && F_757 ( V_10 ) ) {
F_47 ( L_264 ) ;
F_754 ( V_10 , V_1135 , V_98 ) ;
}
if ( ! V_67 && F_758 ( V_10 ) )
F_752 ( V_10 , V_1136 , V_98 ) ;
}
if ( F_5 ( V_1141 ) & V_1132 ) {
F_47 ( L_265 ) ;
V_67 = F_753 ( V_10 , V_1142 , false ) ;
}
if ( ! V_67 && ( F_5 ( V_1142 ) & V_1132 ) ) {
if ( F_757 ( V_10 ) ) {
F_47 ( L_266 ) ;
F_754 ( V_10 , V_1137 , V_100 ) ;
}
if ( F_758 ( V_10 ) )
F_752 ( V_10 , V_1138 , V_100 ) ;
}
if ( F_758 ( V_10 ) &&
( F_5 ( V_1140 ) & V_1117 ) )
F_752 ( V_10 , V_1140 , V_102 ) ;
} else if ( F_20 ( V_10 ) )
F_759 ( V_10 ) ;
if ( F_760 ( V_10 ) )
F_761 ( V_10 ) ;
F_762 ( V_10 ) ;
F_480 (dev, encoder) {
V_6 -> V_8 . V_915 = V_6 -> V_1143 ;
V_6 -> V_8 . V_1144 =
F_742 ( V_6 ) ;
}
F_487 ( V_10 ) ;
F_763 ( V_10 ) ;
}
static void F_764 ( struct V_307 * V_76 )
{
struct V_9 * V_10 = V_76 -> V_10 ;
struct V_712 * V_901 = F_191 ( V_76 ) ;
F_765 ( V_76 ) ;
F_59 ( & V_10 -> V_265 ) ;
F_3 ( ! V_901 -> V_260 -> V_1145 -- ) ;
F_193 ( & V_901 -> V_260 -> V_8 ) ;
F_61 ( & V_10 -> V_265 ) ;
F_195 ( V_901 ) ;
}
static int F_766 ( struct V_307 * V_76 ,
struct V_1106 * V_1107 ,
unsigned int * V_1146 )
{
struct V_712 * V_901 = F_191 ( V_76 ) ;
struct V_259 * V_260 = V_901 -> V_260 ;
return F_767 ( V_1107 , & V_260 -> V_8 , V_1146 ) ;
}
static int F_190 ( struct V_9 * V_10 ,
struct V_712 * V_901 ,
struct V_297 * V_298 ,
struct V_259 * V_260 )
{
int V_711 ;
int V_1147 ;
int V_264 ;
F_3 ( ! F_175 ( & V_10 -> V_265 ) ) ;
if ( V_260 -> V_266 == V_269 ) {
F_564 ( L_267 ) ;
return - V_270 ;
}
if ( V_298 -> V_301 [ 0 ] & 63 ) {
F_564 ( L_268 ,
V_298 -> V_301 [ 0 ] ) ;
return - V_270 ;
}
if ( F_45 ( V_10 ) -> V_86 >= 5 && ! F_19 ( V_10 ) ) {
V_1147 = 32 * 1024 ;
} else if ( F_45 ( V_10 ) -> V_86 >= 4 ) {
if ( V_260 -> V_266 )
V_1147 = 16 * 1024 ;
else
V_1147 = 32 * 1024 ;
} else if ( F_45 ( V_10 ) -> V_86 >= 3 ) {
if ( V_260 -> V_266 )
V_1147 = 8 * 1024 ;
else
V_1147 = 16 * 1024 ;
} else
V_1147 = 8 * 1024 ;
if ( V_298 -> V_301 [ 0 ] > V_1147 ) {
F_564 ( L_269 ,
V_260 -> V_266 ? L_270 : L_271 ,
V_298 -> V_301 [ 0 ] , V_1147 ) ;
return - V_270 ;
}
if ( V_260 -> V_266 != V_267 &&
V_298 -> V_301 [ 0 ] != V_260 -> V_300 ) {
F_564 ( L_272 ,
V_298 -> V_301 [ 0 ] , V_260 -> V_300 ) ;
return - V_270 ;
}
switch ( V_298 -> V_302 ) {
case V_282 :
case V_286 :
case V_288 :
case V_316 :
break;
case V_284 :
case V_315 :
if ( F_45 ( V_10 ) -> V_86 > 3 ) {
F_564 ( L_273 ,
F_768 ( V_298 -> V_302 ) ) ;
return - V_270 ;
}
break;
case V_290 :
case V_317 :
case V_292 :
case V_318 :
case V_294 :
case V_319 :
if ( F_45 ( V_10 ) -> V_86 < 4 ) {
F_564 ( L_273 ,
F_768 ( V_298 -> V_302 ) ) ;
return - V_270 ;
}
break;
case V_1148 :
case V_1149 :
case V_1150 :
case V_1151 :
if ( F_45 ( V_10 ) -> V_86 < 5 ) {
F_564 ( L_273 ,
F_768 ( V_298 -> V_302 ) ) ;
return - V_270 ;
}
break;
default:
F_564 ( L_273 ,
F_768 ( V_298 -> V_302 ) ) ;
return - V_270 ;
}
if ( V_298 -> V_1006 [ 0 ] != 0 )
return - V_270 ;
V_711 = F_172 ( V_10 , V_298 -> V_256 ,
V_260 -> V_266 ) ;
if ( V_260 -> V_8 . V_299 < V_711 * V_298 -> V_301 [ 0 ] )
return - V_270 ;
F_769 ( & V_901 -> V_8 , V_298 ) ;
V_901 -> V_260 = V_260 ;
V_901 -> V_260 -> V_1145 ++ ;
V_264 = F_770 ( V_10 , & V_901 -> V_8 , & V_1152 ) ;
if ( V_264 ) {
F_122 ( L_274 , V_264 ) ;
return V_264 ;
}
return 0 ;
}
static struct V_307 *
F_771 ( struct V_9 * V_10 ,
struct V_1106 * V_1153 ,
struct V_297 * V_298 )
{
struct V_259 * V_260 ;
V_260 = F_772 ( F_773 ( V_10 , V_1153 ,
V_298 -> V_1154 [ 0 ] ) ) ;
if ( & V_260 -> V_8 == NULL )
return F_571 ( - V_1113 ) ;
return F_572 ( V_10 , V_298 , V_260 ) ;
}
static inline void F_774 ( struct V_9 * V_10 )
{
}
static void F_775 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_4 ( V_10 ) || F_16 ( V_10 ) )
V_12 -> V_251 . V_703 = F_30 ;
else if ( F_18 ( V_10 ) )
V_12 -> V_251 . V_703 = F_33 ;
else if ( F_19 ( V_10 ) )
V_12 -> V_251 . V_703 = F_31 ;
else if ( F_17 ( V_10 ) )
V_12 -> V_251 . V_703 = F_29 ;
else
V_12 -> V_251 . V_703 = F_28 ;
if ( F_65 ( V_10 ) ) {
V_12 -> V_251 . V_1041 = F_534 ;
V_12 -> V_251 . V_1155 = F_514 ;
V_12 -> V_251 . V_1050 = F_529 ;
V_12 -> V_251 . V_538 = F_333 ;
V_12 -> V_251 . V_539 = F_344 ;
V_12 -> V_251 . V_542 = F_348 ;
V_12 -> V_251 . V_252 =
F_209 ;
} else if ( F_4 ( V_10 ) ) {
V_12 -> V_251 . V_1041 = F_515 ;
V_12 -> V_251 . V_1155 = F_514 ;
V_12 -> V_251 . V_1050 = F_506 ;
V_12 -> V_251 . V_538 = F_322 ;
V_12 -> V_251 . V_539 = F_343 ;
V_12 -> V_251 . V_542 = F_348 ;
V_12 -> V_251 . V_252 =
F_209 ;
} else if ( F_19 ( V_10 ) ) {
V_12 -> V_251 . V_1041 = F_477 ;
V_12 -> V_251 . V_1155 = F_473 ;
V_12 -> V_251 . V_1050 = F_470 ;
V_12 -> V_251 . V_538 = F_376 ;
V_12 -> V_251 . V_539 = F_386 ;
V_12 -> V_251 . V_542 = F_388 ;
V_12 -> V_251 . V_252 =
F_200 ;
} else {
V_12 -> V_251 . V_1041 = F_477 ;
V_12 -> V_251 . V_1155 = F_473 ;
V_12 -> V_251 . V_1050 = F_470 ;
V_12 -> V_251 . V_538 = F_384 ;
V_12 -> V_251 . V_539 = F_386 ;
V_12 -> V_251 . V_542 = F_388 ;
V_12 -> V_251 . V_252 =
F_200 ;
}
if ( F_19 ( V_10 ) )
V_12 -> V_251 . V_497 =
F_411 ;
else if ( F_463 ( V_10 ) || ( F_465 ( V_10 ) && ! F_776 ( V_10 ) ) )
V_12 -> V_251 . V_497 =
F_412 ;
else if ( F_410 ( V_10 ) )
V_12 -> V_251 . V_497 =
F_413 ;
else if ( F_464 ( V_10 ) || F_75 ( V_10 ) )
V_12 -> V_251 . V_497 =
F_414 ;
else if ( F_17 ( V_10 ) )
V_12 -> V_251 . V_497 =
F_415 ;
else if ( F_777 ( V_10 ) )
V_12 -> V_251 . V_497 =
F_417 ;
else if ( F_76 ( V_10 ) )
V_12 -> V_251 . V_497 =
F_418 ;
else if ( F_778 ( V_10 ) )
V_12 -> V_251 . V_497 =
F_419 ;
else
V_12 -> V_251 . V_497 =
F_420 ;
if ( F_16 ( V_10 ) ) {
V_12 -> V_251 . V_862 = F_537 ;
} else if ( F_7 ( V_10 ) ) {
V_12 -> V_251 . V_415 = F_238 ;
V_12 -> V_251 . V_862 = F_542 ;
} else if ( F_245 ( V_10 ) ) {
V_12 -> V_251 . V_415 = F_243 ;
V_12 -> V_251 . V_862 = F_542 ;
V_12 -> V_251 . V_1048 =
F_527 ;
} else if ( F_235 ( V_10 ) ) {
V_12 -> V_251 . V_415 = F_246 ;
V_12 -> V_251 . V_862 = F_542 ;
V_12 -> V_251 . V_1048 =
F_237 ;
} else if ( F_210 ( V_10 ) || F_168 ( V_10 ) ) {
V_12 -> V_251 . V_415 = V_1156 ;
V_12 -> V_251 . V_862 = F_538 ;
V_12 -> V_251 . V_1048 =
F_528 ;
} else if ( F_19 ( V_10 ) ) {
V_12 -> V_251 . V_1048 =
F_375 ;
V_12 -> V_251 . V_862 = F_542 ;
}
V_12 -> V_251 . V_1013 = F_647 ;
switch ( F_45 ( V_10 ) -> V_86 ) {
case 2 :
V_12 -> V_251 . V_1013 = F_625 ;
break;
case 3 :
V_12 -> V_251 . V_1013 = F_630 ;
break;
case 4 :
case 5 :
V_12 -> V_251 . V_1013 = F_631 ;
break;
case 6 :
V_12 -> V_251 . V_1013 = F_632 ;
break;
case 7 :
case 8 :
V_12 -> V_251 . V_1013 = F_633 ;
break;
}
F_779 ( V_10 ) ;
F_780 ( & V_12 -> V_1157 ) ;
}
static void F_781 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_149 |= V_150 ;
F_782 ( L_275 ) ;
}
static void F_783 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_149 |= V_151 ;
F_782 ( L_276 ) ;
}
static void F_784 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_149 |= V_597 ;
F_782 ( L_277 ) ;
}
static void F_785 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_149 |= V_1158 ;
F_782 ( L_278 ) ;
}
static void F_786 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_149 |= V_1159 ;
F_782 ( L_279 ) ;
}
static int F_787 ( const struct V_1160 * V_226 )
{
F_782 ( L_280 , V_226 -> V_1161 ) ;
return 1 ;
}
static void F_788 ( struct V_9 * V_10 )
{
struct V_1162 * V_1163 = V_10 -> V_560 ;
int V_155 ;
for ( V_155 = 0 ; V_155 < F_247 ( V_1164 ) ; V_155 ++ ) {
struct V_1165 * V_1166 = & V_1164 [ V_155 ] ;
if ( V_1163 -> V_1167 == V_1166 -> V_1167 &&
( V_1163 -> V_1168 == V_1166 -> V_1168 ||
V_1166 -> V_1168 == V_1169 ) &&
( V_1163 -> V_1170 == V_1166 -> V_1170 ||
V_1166 -> V_1170 == V_1169 ) )
V_1166 -> V_1171 ( V_10 ) ;
}
for ( V_155 = 0 ; V_155 < F_247 ( V_1172 ) ; V_155 ++ ) {
if ( F_789 ( * V_1172 [ V_155 ] . V_1173 ) != 0 )
V_1172 [ V_155 ] . V_1171 ( V_10 ) ;
}
}
static void F_790 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_10 V_1174 ;
T_1 V_1175 = F_791 ( V_10 ) ;
F_792 ( V_10 -> V_560 , V_1176 ) ;
F_793 ( V_1177 , V_1178 ) ;
V_1174 = F_794 ( V_1179 ) ;
F_793 ( V_1174 | 1 << 5 , V_1179 ) ;
F_795 ( V_10 -> V_560 , V_1176 ) ;
F_121 ( 300 ) ;
F_46 ( V_1175 , V_12 -> V_1180 | V_1181 ) ;
F_120 ( V_1175 ) ;
}
void F_796 ( struct V_9 * V_10 )
{
F_526 ( V_10 ) ;
if ( F_19 ( V_10 ) )
F_363 ( V_10 ) ;
F_797 ( V_10 ) ;
F_798 ( V_10 ) ;
}
void F_799 ( struct V_9 * V_10 )
{
F_800 ( V_10 ) ;
}
void F_801 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_159 , V_264 ;
enum V_4 V_4 ;
struct V_73 * V_29 ;
F_802 ( V_10 ) ;
V_10 -> V_910 . V_1182 = 0 ;
V_10 -> V_910 . V_1183 = 0 ;
V_10 -> V_910 . V_1184 = 24 ;
V_10 -> V_910 . V_1185 = 1 ;
V_10 -> V_910 . V_808 = & V_1186 ;
F_788 ( V_10 ) ;
F_803 ( V_10 ) ;
if ( F_45 ( V_10 ) -> V_340 == 0 )
return;
F_775 ( V_10 ) ;
if ( F_20 ( V_10 ) ) {
V_10 -> V_910 . V_1187 = 2048 ;
V_10 -> V_910 . V_1188 = 2048 ;
} else if ( F_804 ( V_10 ) ) {
V_10 -> V_910 . V_1187 = 4096 ;
V_10 -> V_910 . V_1188 = 4096 ;
} else {
V_10 -> V_910 . V_1187 = 8192 ;
V_10 -> V_910 . V_1188 = 8192 ;
}
if ( F_75 ( V_10 ) || F_76 ( V_10 ) ) {
V_10 -> V_910 . V_864 = F_75 ( V_10 ) ? 64 : 512 ;
V_10 -> V_910 . V_865 = 1023 ;
} else if ( F_20 ( V_10 ) ) {
V_10 -> V_910 . V_864 = V_1189 ;
V_10 -> V_910 . V_865 = V_1190 ;
} else {
V_10 -> V_910 . V_864 = V_1191 ;
V_10 -> V_910 . V_865 = V_1192 ;
}
V_10 -> V_910 . V_1193 = V_12 -> V_1194 . V_1195 ;
F_47 ( L_281 ,
F_45 ( V_10 ) -> V_340 ,
F_45 ( V_10 ) -> V_340 > 1 ? L_282 : L_283 ) ;
F_85 (dev_priv, pipe) {
F_732 ( V_10 , V_4 ) ;
F_87 (pipe, sprite) {
V_264 = F_805 ( V_10 , V_4 , V_159 ) ;
if ( V_264 )
F_47 ( L_284 ,
F_42 ( V_4 ) , F_89 ( V_4 , V_159 ) , V_264 ) ;
}
}
F_114 ( V_10 ) ;
F_717 ( V_10 ) ;
V_12 -> V_1180 = F_5 ( F_791 ( V_10 ) ) ;
F_790 ( V_10 ) ;
F_747 ( V_10 ) ;
F_320 ( V_10 ) ;
F_806 ( V_10 ) ;
F_807 ( V_10 , false ) ;
F_808 ( V_10 ) ;
F_130 (dev, crtc) {
if ( ! V_29 -> V_74 )
continue;
if ( V_12 -> V_251 . V_1155 ) {
V_12 -> V_251 . V_1155 ( V_29 ,
& V_29 -> V_296 ) ;
F_194 ( V_29 , & V_29 -> V_296 ) ;
}
}
}
static void F_809 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
struct V_541 * V_1196 = NULL ;
struct V_904 V_914 ;
struct V_906 * V_907 = V_10 -> V_910 . V_1197 ;
F_393 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_6 -> type == V_40 ) {
V_1196 = & V_3 -> V_8 ;
break;
}
}
if ( ! V_1196 )
return;
if ( F_581 ( V_1196 , NULL , & V_914 , V_907 ) )
F_586 ( V_1196 , & V_914 ) ;
}
static bool
F_810 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_88 , V_110 ;
if ( F_45 ( V_10 ) -> V_340 == 1 )
return true ;
V_88 = F_82 ( ! V_29 -> V_153 ) ;
V_110 = F_5 ( V_88 ) ;
if ( ( V_110 & V_154 ) &&
( ! ! ( V_110 & V_157 ) == V_29 -> V_4 ) )
return false ;
return true ;
}
static void F_811 ( struct V_73 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_88 ;
V_88 = F_52 ( V_29 -> V_77 . V_82 ) ;
F_46 ( V_88 , F_5 ( V_88 ) & ~ V_1198 ) ;
if ( V_29 -> V_74 ) {
F_691 ( V_29 ) ;
F_316 ( V_10 , V_29 -> V_4 ) ;
} else
F_321 ( V_10 , V_29 -> V_4 ) ;
if ( F_45 ( V_10 ) -> V_86 < 4 && ! F_810 ( V_29 ) ) {
struct V_2 * V_3 ;
bool V_153 ;
F_47 ( L_285 ,
V_29 -> V_8 . V_8 . V_226 ) ;
V_153 = V_29 -> V_153 ;
V_29 -> V_153 = ! V_153 ;
V_29 -> V_250 = true ;
V_12 -> V_251 . V_539 ( & V_29 -> V_8 ) ;
V_29 -> V_153 = V_153 ;
F_393 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
V_3 -> V_8 . V_543 = V_544 ;
V_3 -> V_8 . V_6 = NULL ;
}
F_393 (connector, &dev->mode_config.connector_list,
base.head)
if ( V_3 -> V_6 -> V_8 . V_29 == & V_29 -> V_8 ) {
V_3 -> V_6 -> V_8 . V_29 = NULL ;
V_3 -> V_6 -> V_540 = false ;
}
F_3 ( V_29 -> V_74 ) ;
V_29 -> V_8 . V_108 = false ;
}
if ( V_12 -> V_149 & V_150 &&
V_29 -> V_4 == V_131 && ! V_29 -> V_74 ) {
F_809 ( V_10 ) ;
}
F_391 ( & V_29 -> V_8 ) ;
if ( V_29 -> V_74 != V_29 -> V_8 . V_108 ) {
struct V_1 * V_6 ;
F_47 ( L_286 ,
V_29 -> V_8 . V_8 . V_226 ,
V_29 -> V_8 . V_108 ? L_194 : L_195 ,
V_29 -> V_74 ? L_194 : L_195 ) ;
V_29 -> V_8 . V_108 = V_29 -> V_74 ;
F_3 ( V_29 -> V_74 ) ;
F_11 (dev, &crtc->base, encoder) {
F_3 ( V_6 -> V_540 ) ;
V_6 -> V_8 . V_29 = NULL ;
}
}
if ( V_29 -> V_74 || F_310 ( V_10 ) ) {
V_29 -> V_1199 = true ;
V_29 -> V_1200 = true ;
}
}
static void F_812 ( struct V_1 * V_6 )
{
struct V_2 * V_3 ;
struct V_9 * V_10 = V_6 -> V_8 . V_10 ;
bool V_1201 = V_6 -> V_8 . V_29 &&
F_35 ( V_6 -> V_8 . V_29 ) -> V_74 ;
if ( V_6 -> V_540 && ! V_1201 ) {
F_47 ( L_287 ,
V_6 -> V_8 . V_8 . V_226 ,
V_6 -> V_8 . V_123 ) ;
if ( V_6 -> V_8 . V_29 ) {
F_47 ( L_288 ,
V_6 -> V_8 . V_8 . V_226 ,
V_6 -> V_8 . V_123 ) ;
V_6 -> V_229 ( V_6 ) ;
if ( V_6 -> V_461 )
V_6 -> V_461 ( V_6 ) ;
}
V_6 -> V_8 . V_29 = NULL ;
V_6 -> V_540 = false ;
F_393 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_6 != V_6 )
continue;
V_3 -> V_8 . V_543 = V_544 ;
V_3 -> V_8 . V_6 = NULL ;
}
}
}
void F_813 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_1175 = F_791 ( V_10 ) ;
if ( ! ( F_5 ( V_1175 ) & V_1181 ) ) {
F_47 ( L_289 ) ;
F_790 ( V_10 ) ;
}
}
void F_814 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_79 ( V_12 , V_1202 ) )
return;
F_813 ( V_10 ) ;
}
static bool F_815 ( struct V_73 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
if ( ! V_29 -> V_74 )
return false ;
return F_5 ( F_82 ( V_29 -> V_153 ) ) & V_154 ;
}
static void F_816 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 ;
struct V_73 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
int V_155 ;
F_130 (dev, crtc) {
memset ( & V_29 -> V_77 , 0 , sizeof( V_29 -> V_77 ) ) ;
V_29 -> V_77 . V_149 |= V_1036 ;
V_29 -> V_74 = V_12 -> V_251 . V_1041 ( V_29 ,
& V_29 -> V_77 ) ;
V_29 -> V_8 . V_108 = V_29 -> V_74 ;
V_29 -> V_250 = F_815 ( V_29 ) ;
F_47 ( L_290 ,
V_29 -> V_8 . V_8 . V_226 ,
V_29 -> V_74 ? L_194 : L_195 ) ;
}
for ( V_155 = 0 ; V_155 < V_12 -> V_432 ; V_155 ++ ) {
struct V_116 * V_119 = & V_12 -> V_118 [ V_155 ] ;
V_119 -> V_224 = V_119 -> V_122 ( V_12 , V_119 , & V_119 -> V_121 ) ;
V_119 -> V_74 = 0 ;
F_130 (dev, crtc) {
if ( V_29 -> V_74 && F_62 ( V_29 ) == V_119 )
V_119 -> V_74 ++ ;
}
V_119 -> V_223 = V_119 -> V_74 ;
F_47 ( L_291 ,
V_119 -> V_123 , V_119 -> V_223 , V_119 -> V_224 ) ;
if ( V_119 -> V_223 )
F_144 ( V_12 , V_227 ) ;
}
F_480 (dev, encoder) {
V_4 = 0 ;
if ( V_6 -> V_122 ( V_6 , & V_4 ) ) {
V_29 = F_35 ( V_12 -> V_81 [ V_4 ] ) ;
V_6 -> V_8 . V_29 = & V_29 -> V_8 ;
V_6 -> V_1042 ( V_6 , & V_29 -> V_77 ) ;
} else {
V_6 -> V_8 . V_29 = NULL ;
}
V_6 -> V_540 = false ;
F_47 ( L_292 ,
V_6 -> V_8 . V_8 . V_226 ,
V_6 -> V_8 . V_123 ,
V_6 -> V_8 . V_29 ? L_194 : L_195 ,
F_42 ( V_4 ) ) ;
}
F_393 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_122 ( V_3 ) ) {
V_3 -> V_8 . V_543 = V_546 ;
V_3 -> V_6 -> V_540 = true ;
V_3 -> V_8 . V_6 = & V_3 -> V_6 -> V_8 ;
} else {
V_3 -> V_8 . V_543 = V_544 ;
V_3 -> V_8 . V_6 = NULL ;
}
F_47 ( L_293 ,
V_3 -> V_8 . V_8 . V_226 ,
V_3 -> V_8 . V_123 ,
V_3 -> V_8 . V_6 ? L_194 : L_195 ) ;
}
}
void F_807 ( struct V_9 * V_10 ,
bool V_1203 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 ;
struct V_73 * V_29 ;
struct V_1 * V_6 ;
int V_155 ;
F_816 ( V_10 ) ;
F_130 (dev, crtc) {
if ( V_29 -> V_74 && V_341 . V_342 ) {
F_468 ( & V_29 -> V_8 . V_425 , & V_29 -> V_77 ) ;
F_47 ( L_294 ,
V_29 -> V_8 . V_8 . V_226 ) ;
F_667 ( & V_29 -> V_8 . V_425 ) ;
}
}
F_480 (dev, encoder) {
F_812 ( V_6 ) ;
}
F_85 (dev_priv, pipe) {
V_29 = F_35 ( V_12 -> V_81 [ V_4 ] ) ;
F_811 ( V_29 ) ;
F_665 ( V_29 , & V_29 -> V_77 , L_295 ) ;
}
for ( V_155 = 0 ; V_155 < V_12 -> V_432 ; V_155 ++ ) {
struct V_116 * V_119 = & V_12 -> V_118 [ V_155 ] ;
if ( ! V_119 -> V_224 || V_119 -> V_74 )
continue;
F_47 ( L_296 , V_119 -> V_123 ) ;
V_119 -> V_229 ( V_12 , V_119 ) ;
V_119 -> V_224 = false ;
}
if ( F_4 ( V_10 ) )
F_817 ( V_10 ) ;
if ( V_1203 ) {
F_814 ( V_10 ) ;
F_85 (dev_priv, pipe) {
struct V_28 * V_29 =
V_12 -> V_81 [ V_4 ] ;
F_692 ( V_29 , & V_29 -> V_425 , V_29 -> V_253 , V_29 -> V_254 ,
V_29 -> V_75 -> V_76 ) ;
}
} else {
F_660 ( V_10 ) ;
}
F_400 ( V_10 ) ;
}
void F_818 ( struct V_9 * V_10 )
{
struct V_28 * V_306 ;
struct V_259 * V_260 ;
F_59 ( & V_10 -> V_265 ) ;
F_819 ( V_10 ) ;
F_61 ( & V_10 -> V_265 ) ;
F_796 ( V_10 ) ;
F_820 ( V_10 ) ;
F_59 ( & V_10 -> V_265 ) ;
F_196 (dev, c) {
V_260 = F_197 ( V_306 -> V_75 -> V_76 ) ;
if ( V_260 == NULL )
continue;
if ( F_174 ( V_10 , V_260 , NULL ) ) {
F_122 ( L_297 ,
F_35 ( V_306 ) -> V_4 ) ;
F_588 ( V_306 -> V_75 -> V_76 ) ;
V_306 -> V_75 -> V_76 = NULL ;
}
}
F_61 ( & V_10 -> V_265 ) ;
}
void F_821 ( struct V_2 * V_2 )
{
struct V_541 * V_3 = & V_2 -> V_8 ;
F_822 ( V_3 ) ;
F_823 ( V_3 ) ;
}
void F_824 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_541 * V_3 ;
F_825 ( V_10 ) ;
F_826 ( V_12 ) ;
V_12 -> V_1204 . V_1205 = true ;
F_827 ( V_10 ) ;
F_59 ( & V_10 -> V_265 ) ;
F_828 () ;
F_320 ( V_10 ) ;
F_829 ( V_10 ) ;
F_830 ( V_10 ) ;
F_61 ( & V_10 -> V_265 ) ;
F_831 () ;
F_393 (connector, &dev->mode_config.connector_list, head) {
struct V_2 * V_2 ;
V_2 = F_582 ( V_3 ) ;
V_2 -> V_1206 ( V_2 ) ;
}
F_832 ( V_10 ) ;
F_833 ( V_10 ) ;
F_59 ( & V_10 -> V_265 ) ;
F_834 ( V_10 ) ;
F_61 ( & V_10 -> V_265 ) ;
}
struct V_545 * F_835 ( struct V_541 * V_3 )
{
return & F_552 ( V_3 ) -> V_8 ;
}
void F_836 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
V_3 -> V_6 = V_6 ;
F_837 ( & V_3 -> V_8 ,
& V_6 -> V_8 ) ;
}
int F_838 ( struct V_9 * V_10 , bool V_109 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned V_88 = F_45 ( V_10 ) -> V_86 >= 6 ? V_1207 : V_1208 ;
T_5 V_1209 ;
if ( F_416 ( V_12 -> V_1210 , V_88 , & V_1209 ) ) {
F_122 ( L_298 ) ;
return - V_1014 ;
}
if ( ! ! ( V_1209 & V_1211 ) == ! V_109 )
return 0 ;
if ( V_109 )
V_1209 &= ~ V_1211 ;
else
V_1209 |= V_1211 ;
if ( F_839 ( V_12 -> V_1210 , V_88 , V_1209 ) ) {
F_122 ( L_299 ) ;
return - V_1014 ;
}
return 0 ;
}
struct V_1212 *
F_840 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1212 * error ;
int V_1213 [] = {
V_240 ,
V_1214 ,
V_1215 ,
V_458 ,
} ;
int V_155 ;
if ( F_45 ( V_10 ) -> V_340 == 0 )
return NULL ;
error = F_474 ( sizeof( * error ) , V_1216 ) ;
if ( error == NULL )
return NULL ;
if ( F_210 ( V_10 ) || F_168 ( V_10 ) )
error -> V_1217 = F_5 ( V_774 ) ;
F_85 (dev_priv, i) {
error -> V_4 [ V_155 ] . V_1218 =
F_841 ( V_12 ,
F_357 ( V_155 ) ) ;
if ( ! error -> V_4 [ V_155 ] . V_1218 )
continue;
error -> V_1098 [ V_155 ] . V_466 = F_5 ( F_77 ( V_155 ) ) ;
error -> V_1098 [ V_155 ] . V_1219 = F_5 ( F_561 ( V_155 ) ) ;
error -> V_1098 [ V_155 ] . V_8 = F_5 ( F_560 ( V_155 ) ) ;
error -> V_153 [ V_155 ] . V_466 = F_5 ( F_82 ( V_155 ) ) ;
error -> V_153 [ V_155 ] . V_300 = F_5 ( F_206 ( V_155 ) ) ;
if ( F_45 ( V_10 ) -> V_86 <= 3 ) {
error -> V_153 [ V_155 ] . V_299 = F_5 ( F_202 ( V_155 ) ) ;
error -> V_153 [ V_155 ] . V_436 = F_5 ( F_203 ( V_155 ) ) ;
}
if ( F_45 ( V_10 ) -> V_86 <= 7 && ! F_210 ( V_10 ) )
error -> V_153 [ V_155 ] . V_885 = F_5 ( F_165 ( V_155 ) ) ;
if ( F_45 ( V_10 ) -> V_86 >= 4 ) {
error -> V_153 [ V_155 ] . V_1220 = F_5 ( F_164 ( V_155 ) ) ;
error -> V_153 [ V_155 ] . V_1221 = F_5 ( F_207 ( V_155 ) ) ;
}
error -> V_4 [ V_155 ] . V_1222 = F_5 ( F_228 ( V_155 ) ) ;
if ( F_310 ( V_10 ) )
error -> V_4 [ V_155 ] . V_1223 = F_5 ( F_44 ( V_155 ) ) ;
}
error -> V_1224 = F_45 ( V_10 ) -> V_340 ;
if ( F_65 ( V_12 -> V_10 ) )
error -> V_1224 ++ ;
for ( V_155 = 0 ; V_155 < error -> V_1224 ; V_155 ++ ) {
enum V_80 V_82 = V_1213 [ V_155 ] ;
error -> V_80 [ V_155 ] . V_1218 =
F_841 ( V_12 ,
F_80 ( V_82 ) ) ;
if ( ! error -> V_80 [ V_155 ] . V_1218 )
continue;
error -> V_80 [ V_155 ] . V_82 = V_82 ;
error -> V_80 [ V_155 ] . V_1225 = F_5 ( F_52 ( V_82 ) ) ;
error -> V_80 [ V_155 ] . V_681 = F_5 ( F_272 ( V_82 ) ) ;
error -> V_80 [ V_155 ] . V_1226 = F_5 ( F_274 ( V_82 ) ) ;
error -> V_80 [ V_155 ] . V_942 = F_5 ( F_276 ( V_82 ) ) ;
error -> V_80 [ V_155 ] . V_683 = F_5 ( F_278 ( V_82 ) ) ;
error -> V_80 [ V_155 ] . V_1227 = F_5 ( F_280 ( V_82 ) ) ;
error -> V_80 [ V_155 ] . V_944 = F_5 ( F_282 ( V_82 ) ) ;
}
return error ;
}
void
F_842 ( struct V_1228 * V_19 ,
struct V_9 * V_10 ,
struct V_1212 * error )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_155 ;
if ( ! error )
return;
F_843 ( V_19 , L_300 , F_45 ( V_10 ) -> V_340 ) ;
if ( F_210 ( V_10 ) || F_168 ( V_10 ) )
F_843 ( V_19 , L_301 ,
error -> V_1217 ) ;
F_85 (dev_priv, i) {
F_843 ( V_19 , L_302 , V_155 ) ;
F_843 ( V_19 , L_303 ,
error -> V_4 [ V_155 ] . V_1218 ? L_12 : L_13 ) ;
F_843 ( V_19 , L_304 , error -> V_4 [ V_155 ] . V_1222 ) ;
F_843 ( V_19 , L_305 , error -> V_4 [ V_155 ] . V_1223 ) ;
F_843 ( V_19 , L_306 , V_155 ) ;
F_843 ( V_19 , L_307 , error -> V_153 [ V_155 ] . V_466 ) ;
F_843 ( V_19 , L_308 , error -> V_153 [ V_155 ] . V_300 ) ;
if ( F_45 ( V_10 ) -> V_86 <= 3 ) {
F_843 ( V_19 , L_309 , error -> V_153 [ V_155 ] . V_299 ) ;
F_843 ( V_19 , L_310 , error -> V_153 [ V_155 ] . V_436 ) ;
}
if ( F_45 ( V_10 ) -> V_86 <= 7 && ! F_210 ( V_10 ) )
F_843 ( V_19 , L_311 , error -> V_153 [ V_155 ] . V_885 ) ;
if ( F_45 ( V_10 ) -> V_86 >= 4 ) {
F_843 ( V_19 , L_312 , error -> V_153 [ V_155 ] . V_1220 ) ;
F_843 ( V_19 , L_313 , error -> V_153 [ V_155 ] . V_1221 ) ;
}
F_843 ( V_19 , L_314 , V_155 ) ;
F_843 ( V_19 , L_307 , error -> V_1098 [ V_155 ] . V_466 ) ;
F_843 ( V_19 , L_310 , error -> V_1098 [ V_155 ] . V_1219 ) ;
F_843 ( V_19 , L_315 , error -> V_1098 [ V_155 ] . V_8 ) ;
}
for ( V_155 = 0 ; V_155 < error -> V_1224 ; V_155 ++ ) {
F_843 ( V_19 , L_316 ,
F_666 ( error -> V_80 [ V_155 ] . V_82 ) ) ;
F_843 ( V_19 , L_303 ,
error -> V_80 [ V_155 ] . V_1218 ? L_12 : L_13 ) ;
F_843 ( V_19 , L_317 , error -> V_80 [ V_155 ] . V_1225 ) ;
F_843 ( V_19 , L_318 , error -> V_80 [ V_155 ] . V_681 ) ;
F_843 ( V_19 , L_319 , error -> V_80 [ V_155 ] . V_1226 ) ;
F_843 ( V_19 , L_320 , error -> V_80 [ V_155 ] . V_942 ) ;
F_843 ( V_19 , L_321 , error -> V_80 [ V_155 ] . V_683 ) ;
F_843 ( V_19 , L_322 , error -> V_80 [ V_155 ] . V_1227 ) ;
F_843 ( V_19 , L_323 , error -> V_80 [ V_155 ] . V_944 ) ;
}
}
void F_844 ( struct V_9 * V_10 , struct V_1106 * V_1107 )
{
struct V_73 * V_29 ;
F_130 (dev, crtc) {
struct V_387 * V_388 ;
unsigned long V_804 ;
F_224 ( & V_10 -> V_336 , V_804 ) ;
V_388 = V_29 -> V_337 ;
if ( V_388 && V_388 -> V_389 &&
V_388 -> V_389 -> V_8 . V_1229 == V_1107 ) {
F_195 ( V_388 -> V_389 ) ;
V_388 -> V_389 = NULL ;
}
F_225 ( & V_10 -> V_336 , V_804 ) ;
}
}
