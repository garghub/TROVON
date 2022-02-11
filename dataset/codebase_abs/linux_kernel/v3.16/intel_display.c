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
} else if ( F_18 ( V_2 ) ) {
V_24 = & V_42 ;
} else if ( ! F_19 ( V_2 ) ) {
if ( F_9 ( V_21 , V_25 ) )
V_24 = & V_43 ;
else
V_24 = & V_38 ;
} else {
if ( F_9 ( V_21 , V_25 ) )
V_24 = & V_44 ;
else if ( F_9 ( V_21 , V_45 ) )
V_24 = & V_46 ;
else
V_24 = & V_47 ;
}
return V_24 ;
}
static void F_20 ( int V_10 , T_2 * clock )
{
clock -> V_11 = clock -> V_13 + 2 ;
clock -> V_14 = clock -> V_15 * clock -> V_16 ;
if ( F_2 ( clock -> V_17 == 0 || clock -> V_14 == 0 ) )
return;
clock -> V_18 = F_8 ( V_10 * clock -> V_11 , clock -> V_17 ) ;
clock -> V_19 = F_8 ( clock -> V_18 , clock -> V_14 ) ;
}
static T_4 F_21 ( struct V_48 * V_48 )
{
return 5 * ( V_48 -> V_12 + 2 ) + ( V_48 -> V_13 + 2 ) ;
}
static void F_22 ( int V_10 , T_2 * clock )
{
clock -> V_11 = F_21 ( clock ) ;
clock -> V_14 = clock -> V_15 * clock -> V_16 ;
if ( F_2 ( clock -> V_17 + 2 == 0 || clock -> V_14 == 0 ) )
return;
clock -> V_18 = F_8 ( V_10 * clock -> V_11 , clock -> V_17 + 2 ) ;
clock -> V_19 = F_8 ( clock -> V_18 , clock -> V_14 ) ;
}
static void F_23 ( int V_10 , T_2 * clock )
{
clock -> V_11 = clock -> V_12 * clock -> V_13 ;
clock -> V_14 = clock -> V_15 * clock -> V_16 ;
if ( F_2 ( clock -> V_17 == 0 || clock -> V_14 == 0 ) )
return;
clock -> V_18 = F_24 ( ( V_49 ) V_10 * clock -> V_11 ,
clock -> V_17 << 22 ) ;
clock -> V_19 = F_8 ( clock -> V_18 , clock -> V_14 ) ;
}
static bool F_25 ( struct V_1 * V_2 ,
const T_3 * V_24 ,
const T_2 * clock )
{
if ( clock -> V_17 < V_24 -> V_17 . V_50 || V_24 -> V_17 . V_51 < clock -> V_17 )
F_26 ( L_1 ) ;
if ( clock -> V_15 < V_24 -> V_15 . V_50 || V_24 -> V_15 . V_51 < clock -> V_15 )
F_26 ( L_2 ) ;
if ( clock -> V_13 < V_24 -> V_13 . V_50 || V_24 -> V_13 . V_51 < clock -> V_13 )
F_26 ( L_3 ) ;
if ( clock -> V_12 < V_24 -> V_12 . V_50 || V_24 -> V_12 . V_51 < clock -> V_12 )
F_26 ( L_4 ) ;
if ( ! F_16 ( V_2 ) && ! F_18 ( V_2 ) )
if ( clock -> V_12 <= clock -> V_13 )
F_26 ( L_5 ) ;
if ( ! F_18 ( V_2 ) ) {
if ( clock -> V_14 < V_24 -> V_14 . V_50 || V_24 -> V_14 . V_51 < clock -> V_14 )
F_26 ( L_6 ) ;
if ( clock -> V_11 < V_24 -> V_11 . V_50 || V_24 -> V_11 . V_51 < clock -> V_11 )
F_26 ( L_7 ) ;
}
if ( clock -> V_18 < V_24 -> V_18 . V_50 || V_24 -> V_18 . V_51 < clock -> V_18 )
F_26 ( L_8 ) ;
if ( clock -> V_19 < V_24 -> V_19 . V_50 || V_24 -> V_19 . V_51 < clock -> V_19 )
F_26 ( L_9 ) ;
return true ;
}
static bool
F_27 ( const T_3 * V_24 , struct V_20 * V_21 ,
int V_52 , int V_10 , T_2 * V_53 ,
T_2 * V_54 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_2 clock ;
int V_55 = V_52 ;
if ( F_9 ( V_21 , V_25 ) ) {
if ( F_12 ( V_2 ) )
clock . V_16 = V_24 -> V_16 . V_56 ;
else
clock . V_16 = V_24 -> V_16 . V_57 ;
} else {
if ( V_52 < V_24 -> V_16 . V_58 )
clock . V_16 = V_24 -> V_16 . V_57 ;
else
clock . V_16 = V_24 -> V_16 . V_56 ;
}
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
for ( clock . V_12 = V_24 -> V_12 . V_50 ; clock . V_12 <= V_24 -> V_12 . V_51 ;
clock . V_12 ++ ) {
for ( clock . V_13 = V_24 -> V_13 . V_50 ;
clock . V_13 <= V_24 -> V_13 . V_51 ; clock . V_13 ++ ) {
if ( clock . V_13 >= clock . V_12 )
break;
for ( clock . V_17 = V_24 -> V_17 . V_50 ;
clock . V_17 <= V_24 -> V_17 . V_51 ; clock . V_17 ++ ) {
for ( clock . V_15 = V_24 -> V_15 . V_50 ;
clock . V_15 <= V_24 -> V_15 . V_51 ; clock . V_15 ++ ) {
int V_59 ;
F_22 ( V_10 , & clock ) ;
if ( ! F_25 ( V_2 , V_24 ,
& clock ) )
continue;
if ( V_53 &&
clock . V_14 != V_53 -> V_14 )
continue;
V_59 = abs ( clock . V_19 - V_52 ) ;
if ( V_59 < V_55 ) {
* V_54 = clock ;
V_55 = V_59 ;
}
}
}
}
}
return ( V_55 != V_52 ) ;
}
static bool
F_28 ( const T_3 * V_24 , struct V_20 * V_21 ,
int V_52 , int V_10 , T_2 * V_53 ,
T_2 * V_54 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_2 clock ;
int V_55 = V_52 ;
if ( F_9 ( V_21 , V_25 ) ) {
if ( F_12 ( V_2 ) )
clock . V_16 = V_24 -> V_16 . V_56 ;
else
clock . V_16 = V_24 -> V_16 . V_57 ;
} else {
if ( V_52 < V_24 -> V_16 . V_58 )
clock . V_16 = V_24 -> V_16 . V_57 ;
else
clock . V_16 = V_24 -> V_16 . V_56 ;
}
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
for ( clock . V_12 = V_24 -> V_12 . V_50 ; clock . V_12 <= V_24 -> V_12 . V_51 ;
clock . V_12 ++ ) {
for ( clock . V_13 = V_24 -> V_13 . V_50 ;
clock . V_13 <= V_24 -> V_13 . V_51 ; clock . V_13 ++ ) {
for ( clock . V_17 = V_24 -> V_17 . V_50 ;
clock . V_17 <= V_24 -> V_17 . V_51 ; clock . V_17 ++ ) {
for ( clock . V_15 = V_24 -> V_15 . V_50 ;
clock . V_15 <= V_24 -> V_15 . V_51 ; clock . V_15 ++ ) {
int V_59 ;
F_20 ( V_10 , & clock ) ;
if ( ! F_25 ( V_2 , V_24 ,
& clock ) )
continue;
if ( V_53 &&
clock . V_14 != V_53 -> V_14 )
continue;
V_59 = abs ( clock . V_19 - V_52 ) ;
if ( V_59 < V_55 ) {
* V_54 = clock ;
V_55 = V_59 ;
}
}
}
}
}
return ( V_55 != V_52 ) ;
}
static bool
F_29 ( const T_3 * V_24 , struct V_20 * V_21 ,
int V_52 , int V_10 , T_2 * V_53 ,
T_2 * V_54 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_2 clock ;
int V_60 ;
bool V_61 ;
int V_62 = ( V_52 >> 8 ) + ( V_52 >> 9 ) ;
V_61 = false ;
if ( F_9 ( V_21 , V_25 ) ) {
if ( F_12 ( V_2 ) )
clock . V_16 = V_24 -> V_16 . V_56 ;
else
clock . V_16 = V_24 -> V_16 . V_57 ;
} else {
if ( V_52 < V_24 -> V_16 . V_58 )
clock . V_16 = V_24 -> V_16 . V_57 ;
else
clock . V_16 = V_24 -> V_16 . V_56 ;
}
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_60 = V_24 -> V_17 . V_51 ;
for ( clock . V_17 = V_24 -> V_17 . V_50 ; clock . V_17 <= V_60 ; clock . V_17 ++ ) {
for ( clock . V_12 = V_24 -> V_12 . V_51 ;
clock . V_12 >= V_24 -> V_12 . V_50 ; clock . V_12 -- ) {
for ( clock . V_13 = V_24 -> V_13 . V_51 ;
clock . V_13 >= V_24 -> V_13 . V_50 ; clock . V_13 -- ) {
for ( clock . V_15 = V_24 -> V_15 . V_51 ;
clock . V_15 >= V_24 -> V_15 . V_50 ; clock . V_15 -- ) {
int V_59 ;
F_22 ( V_10 , & clock ) ;
if ( ! F_25 ( V_2 , V_24 ,
& clock ) )
continue;
V_59 = abs ( clock . V_19 - V_52 ) ;
if ( V_59 < V_62 ) {
* V_54 = clock ;
V_62 = V_59 ;
V_60 = clock . V_17 ;
V_61 = true ;
}
}
}
}
}
return V_61 ;
}
static bool
F_30 ( const T_3 * V_24 , struct V_20 * V_21 ,
int V_52 , int V_10 , T_2 * V_53 ,
T_2 * V_54 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_2 clock ;
unsigned int V_63 = 1000000 ;
int V_60 = V_50 ( V_24 -> V_17 . V_51 , V_10 / 19200 ) ;
bool V_61 = false ;
V_52 *= 5 ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
for ( clock . V_17 = V_24 -> V_17 . V_50 ; clock . V_17 <= V_60 ; clock . V_17 ++ ) {
for ( clock . V_15 = V_24 -> V_15 . V_51 ; clock . V_15 >= V_24 -> V_15 . V_50 ; clock . V_15 -- ) {
for ( clock . V_16 = V_24 -> V_16 . V_56 ; clock . V_16 >= V_24 -> V_16 . V_57 ;
clock . V_16 -= clock . V_16 > 10 ? 2 : 1 ) {
clock . V_14 = clock . V_15 * clock . V_16 ;
for ( clock . V_12 = V_24 -> V_12 . V_50 ; clock . V_12 <= V_24 -> V_12 . V_51 ; clock . V_12 ++ ) {
unsigned int V_64 , V_65 ;
clock . V_13 = F_8 ( V_52 * clock . V_14 * clock . V_17 ,
V_10 * clock . V_12 ) ;
F_7 ( V_10 , & clock ) ;
if ( ! F_25 ( V_2 , V_24 ,
& clock ) )
continue;
V_65 = abs ( clock . V_19 - V_52 ) ;
V_64 = F_31 ( 1000000ULL * V_65 , V_52 ) ;
if ( V_64 < 100 && clock . V_14 > V_54 -> V_14 ) {
V_63 = 0 ;
* V_54 = clock ;
V_61 = true ;
}
if ( V_63 >= 10 && V_64 < V_63 - 10 ) {
V_63 = V_64 ;
* V_54 = clock ;
V_61 = true ;
}
}
}
}
}
return V_61 ;
}
static bool
F_32 ( const T_3 * V_24 , struct V_20 * V_21 ,
int V_52 , int V_10 , T_2 * V_53 ,
T_2 * V_54 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_2 clock ;
V_49 V_13 ;
int V_61 = false ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
clock . V_17 = 1 , clock . V_12 = 2 ;
V_52 *= 5 ;
for ( clock . V_15 = V_24 -> V_15 . V_51 ; clock . V_15 >= V_24 -> V_15 . V_50 ; clock . V_15 -- ) {
for ( clock . V_16 = V_24 -> V_16 . V_56 ;
clock . V_16 >= V_24 -> V_16 . V_57 ;
clock . V_16 -= clock . V_16 > 10 ? 2 : 1 ) {
clock . V_14 = clock . V_15 * clock . V_16 ;
V_13 = F_24 ( ( ( V_49 ) V_52 * clock . V_14 *
clock . V_17 ) << 22 , V_10 * clock . V_12 ) ;
if ( V_13 > V_66 / clock . V_12 )
continue;
clock . V_13 = V_13 ;
F_23 ( V_10 , & clock ) ;
if ( ! F_25 ( V_2 , V_24 , & clock ) )
continue;
if ( clock . V_14 > V_54 -> V_14 ) {
* V_54 = clock ;
V_61 = true ;
}
}
}
return V_61 ;
}
bool F_33 ( struct V_20 * V_21 )
{
struct V_67 * V_67 = F_34 ( V_21 ) ;
return V_67 -> V_68 && V_21 -> V_69 -> V_70 &&
V_67 -> V_71 . V_72 . V_73 ;
}
enum V_74 F_35 ( struct V_3 * V_4 ,
enum V_75 V_75 )
{
struct V_20 * V_21 = V_4 -> V_76 [ V_75 ] ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
return V_67 -> V_71 . V_77 ;
}
static void F_36 ( struct V_1 * V_2 , int V_75 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_78 , V_79 = F_37 ( V_75 ) ;
V_78 = F_4 ( V_79 ) ;
if ( F_38 ( F_39 ( V_79 ) != V_78 , 50 ) )
F_40 ( 1 , L_10 ) ;
}
void F_41 ( struct V_1 * V_2 , int V_75 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_80 = F_42 ( V_75 ) ;
if ( F_15 ( V_2 ) || F_43 ( V_2 ) -> V_81 >= 5 ) {
F_36 ( V_2 , V_75 ) ;
return;
}
F_44 ( V_80 ,
F_4 ( V_80 ) | V_82 ) ;
if ( F_38 ( F_4 ( V_80 ) &
V_82 ,
50 ) )
F_45 ( L_10 ) ;
}
static bool F_46 ( struct V_1 * V_2 , enum V_75 V_75 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_83 = F_47 ( V_75 ) ;
T_1 V_84 , V_85 ;
T_1 V_86 ;
if ( F_19 ( V_2 ) )
V_86 = V_87 ;
else
V_86 = V_88 ;
V_84 = F_4 ( V_83 ) & V_86 ;
F_48 ( 5 ) ;
V_85 = F_4 ( V_83 ) & V_86 ;
return V_84 == V_85 ;
}
void F_49 ( struct V_1 * V_2 , int V_75 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_74 V_77 = F_35 ( V_4 ,
V_75 ) ;
if ( F_43 ( V_2 ) -> V_81 >= 4 ) {
int V_83 = F_50 ( V_77 ) ;
if ( F_38 ( ( F_4 ( V_83 ) & V_89 ) == 0 ,
100 ) )
F_40 ( 1 , L_11 ) ;
} else {
if ( F_38 ( F_46 ( V_2 , V_75 ) , 100 ) )
F_40 ( 1 , L_11 ) ;
}
}
bool F_51 ( struct V_3 * V_4 ,
struct V_90 * V_91 )
{
T_1 V_92 ;
if ( F_52 ( V_4 -> V_2 ) ) {
switch ( V_91 -> V_91 ) {
case V_93 :
V_92 = V_94 ;
break;
case V_95 :
V_92 = V_96 ;
break;
case V_97 :
V_92 = V_98 ;
break;
default:
return true ;
}
} else {
switch ( V_91 -> V_91 ) {
case V_93 :
V_92 = V_99 ;
break;
case V_95 :
V_92 = V_100 ;
break;
case V_97 :
V_92 = V_101 ;
break;
default:
return true ;
}
}
return F_4 ( V_102 ) & V_92 ;
}
static const char * F_53 ( bool V_103 )
{
return V_103 ? L_12 : L_13 ;
}
void F_54 ( struct V_3 * V_4 ,
enum V_75 V_75 , bool V_104 )
{
int V_83 ;
T_1 V_105 ;
bool V_106 ;
V_83 = F_55 ( V_75 ) ;
V_105 = F_4 ( V_83 ) ;
V_106 = ! ! ( V_105 & V_107 ) ;
F_40 ( V_106 != V_104 ,
L_14 ,
F_53 ( V_104 ) , F_53 ( V_106 ) ) ;
}
static void F_56 ( struct V_3 * V_4 , bool V_104 )
{
T_1 V_105 ;
bool V_106 ;
F_57 ( & V_4 -> V_108 ) ;
V_105 = F_58 ( V_4 , V_109 ) ;
F_59 ( & V_4 -> V_108 ) ;
V_106 = V_105 & V_110 ;
F_40 ( V_106 != V_104 ,
L_15 ,
F_53 ( V_104 ) , F_53 ( V_106 ) ) ;
}
struct V_111 *
F_60 ( struct V_67 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_112 . V_2 -> V_5 ;
if ( V_21 -> V_71 . V_113 < 0 )
return NULL ;
return & V_4 -> V_114 [ V_21 -> V_71 . V_113 ] ;
}
void F_61 ( struct V_3 * V_4 ,
struct V_111 * V_115 ,
bool V_104 )
{
bool V_106 ;
struct V_116 V_117 ;
if ( F_62 ( V_4 -> V_2 ) ) {
F_63 ( L_16 ) ;
return;
}
if ( F_40 ( ! V_115 ,
L_17 , F_53 ( V_104 ) ) )
return;
V_106 = V_115 -> V_118 ( V_4 , V_115 , & V_117 ) ;
F_40 ( V_106 != V_104 ,
L_18 ,
V_115 -> V_119 , F_53 ( V_104 ) , F_53 ( V_106 ) ) ;
}
static void F_64 ( struct V_3 * V_4 ,
enum V_75 V_75 , bool V_104 )
{
int V_83 ;
T_1 V_105 ;
bool V_106 ;
enum V_74 V_77 = F_35 ( V_4 ,
V_75 ) ;
if ( F_65 ( V_4 -> V_2 ) ) {
V_83 = F_66 ( V_77 ) ;
V_105 = F_4 ( V_83 ) ;
V_106 = ! ! ( V_105 & V_120 ) ;
} else {
V_83 = F_67 ( V_75 ) ;
V_105 = F_4 ( V_83 ) ;
V_106 = ! ! ( V_105 & V_121 ) ;
}
F_40 ( V_106 != V_104 ,
L_19 ,
F_53 ( V_104 ) , F_53 ( V_106 ) ) ;
}
static void F_68 ( struct V_3 * V_4 ,
enum V_75 V_75 , bool V_104 )
{
int V_83 ;
T_1 V_105 ;
bool V_106 ;
V_83 = F_69 ( V_75 ) ;
V_105 = F_4 ( V_83 ) ;
V_106 = ! ! ( V_105 & V_122 ) ;
F_40 ( V_106 != V_104 ,
L_20 ,
F_53 ( V_104 ) , F_53 ( V_106 ) ) ;
}
static void F_70 ( struct V_3 * V_4 ,
enum V_75 V_75 )
{
int V_83 ;
T_1 V_105 ;
if ( F_43 ( V_4 -> V_2 ) -> V_81 == 5 )
return;
if ( F_65 ( V_4 -> V_2 ) )
return;
V_83 = F_67 ( V_75 ) ;
V_105 = F_4 ( V_83 ) ;
F_40 ( ! ( V_105 & V_123 ) , L_21 ) ;
}
void F_71 ( struct V_3 * V_4 ,
enum V_75 V_75 , bool V_104 )
{
int V_83 ;
T_1 V_105 ;
bool V_106 ;
V_83 = F_69 ( V_75 ) ;
V_105 = F_4 ( V_83 ) ;
V_106 = ! ! ( V_105 & V_124 ) ;
F_40 ( V_106 != V_104 ,
L_22 ,
F_53 ( V_104 ) , F_53 ( V_106 ) ) ;
}
static void F_72 ( struct V_3 * V_4 ,
enum V_75 V_75 )
{
int V_125 , V_126 ;
T_1 V_105 ;
enum V_75 V_127 = V_128 ;
bool V_129 = true ;
if ( F_3 ( V_4 -> V_2 ) ) {
V_125 = V_130 ;
V_126 = V_131 ;
} else {
V_125 = V_132 ;
V_126 = V_133 ;
}
V_105 = F_4 ( V_125 ) ;
if ( ! ( V_105 & V_134 ) ||
( ( V_105 & V_135 ) == V_135 ) )
V_129 = false ;
if ( F_4 ( V_126 ) & V_136 )
V_127 = V_137 ;
F_40 ( V_127 == V_75 && V_129 ,
L_23 ,
F_73 ( V_75 ) ) ;
}
static void F_74 ( struct V_3 * V_4 ,
enum V_75 V_75 , bool V_104 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
bool V_106 ;
if ( F_75 ( V_2 ) || F_76 ( V_2 ) )
V_106 = F_4 ( V_138 ) & V_139 ;
else
V_106 = F_4 ( F_77 ( V_75 ) ) & V_140 ;
F_40 ( V_106 != V_104 ,
L_24 ,
F_73 ( V_75 ) , F_53 ( V_104 ) , F_53 ( V_106 ) ) ;
}
void F_78 ( struct V_3 * V_4 ,
enum V_75 V_75 , bool V_104 )
{
int V_83 ;
T_1 V_105 ;
bool V_106 ;
enum V_74 V_77 = F_35 ( V_4 ,
V_75 ) ;
if ( V_75 == V_128 && V_4 -> V_141 & V_142 )
V_104 = true ;
if ( ! F_79 ( V_4 ,
F_80 ( V_77 ) ) ) {
V_106 = false ;
} else {
V_83 = F_50 ( V_77 ) ;
V_105 = F_4 ( V_83 ) ;
V_106 = ! ! ( V_105 & V_143 ) ;
}
F_40 ( V_106 != V_104 ,
L_25 ,
F_73 ( V_75 ) , F_53 ( V_104 ) , F_53 ( V_106 ) ) ;
}
static void F_81 ( struct V_3 * V_4 ,
enum V_144 V_144 , bool V_104 )
{
int V_83 ;
T_1 V_105 ;
bool V_106 ;
V_83 = F_82 ( V_144 ) ;
V_105 = F_4 ( V_83 ) ;
V_106 = ! ! ( V_105 & V_145 ) ;
F_40 ( V_106 != V_104 ,
L_26 ,
F_83 ( V_144 ) , F_53 ( V_104 ) , F_53 ( V_106 ) ) ;
}
static void F_84 ( struct V_3 * V_4 ,
enum V_75 V_75 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_83 , V_146 ;
T_1 V_105 ;
int V_147 ;
if ( F_43 ( V_2 ) -> V_81 >= 4 ) {
V_83 = F_82 ( V_75 ) ;
V_105 = F_4 ( V_83 ) ;
F_40 ( V_105 & V_145 ,
L_27 ,
F_83 ( V_75 ) ) ;
return;
}
F_85 (i) {
V_83 = F_82 ( V_146 ) ;
V_105 = F_4 ( V_83 ) ;
V_147 = ( V_105 & V_148 ) >>
V_149 ;
F_40 ( ( V_105 & V_145 ) && V_75 == V_147 ,
L_28 ,
F_83 ( V_146 ) , F_73 ( V_75 ) ) ;
}
}
static void F_86 ( struct V_3 * V_4 ,
enum V_75 V_75 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_83 , V_150 ;
T_1 V_105 ;
if ( F_18 ( V_2 ) ) {
F_87 (pipe, sprite) {
V_83 = F_88 ( V_75 , V_150 ) ;
V_105 = F_4 ( V_83 ) ;
F_40 ( V_105 & V_151 ,
L_29 ,
F_89 ( V_75 , V_150 ) , F_73 ( V_75 ) ) ;
}
} else if ( F_43 ( V_2 ) -> V_81 >= 7 ) {
V_83 = F_90 ( V_75 ) ;
V_105 = F_4 ( V_83 ) ;
F_40 ( V_105 & V_152 ,
L_29 ,
F_83 ( V_75 ) , F_73 ( V_75 ) ) ;
} else if ( F_43 ( V_2 ) -> V_81 >= 5 ) {
V_83 = F_91 ( V_75 ) ;
V_105 = F_4 ( V_83 ) ;
F_40 ( V_105 & V_153 ,
L_29 ,
F_83 ( V_75 ) , F_73 ( V_75 ) ) ;
}
}
static void F_92 ( struct V_3 * V_4 )
{
T_1 V_105 ;
bool V_103 ;
F_2 ( ! ( F_52 ( V_4 -> V_2 ) || F_93 ( V_4 -> V_2 ) ) ) ;
V_105 = F_4 ( V_154 ) ;
V_103 = ! ! ( V_105 & ( V_155 | V_156 |
V_157 ) ) ;
F_40 ( ! V_103 , L_30 ) ;
}
static void F_94 ( struct V_3 * V_4 ,
enum V_75 V_75 )
{
int V_83 ;
T_1 V_105 ;
bool V_103 ;
V_83 = F_95 ( V_75 ) ;
V_105 = F_4 ( V_83 ) ;
V_103 = ! ! ( V_105 & V_158 ) ;
F_40 ( V_103 ,
L_31 ,
F_73 ( V_75 ) ) ;
}
static bool F_96 ( struct V_3 * V_4 ,
enum V_75 V_75 , T_1 V_159 , T_1 V_105 )
{
if ( ( V_105 & V_160 ) == 0 )
return false ;
if ( F_93 ( V_4 -> V_2 ) ) {
T_1 V_161 = F_97 ( V_75 ) ;
T_1 V_162 = F_4 ( V_161 ) ;
if ( ( V_162 & V_163 ) != V_159 )
return false ;
} else if ( F_17 ( V_4 -> V_2 ) ) {
if ( ( V_105 & V_164 ) != F_98 ( V_75 ) )
return false ;
} else {
if ( ( V_105 & V_165 ) != ( V_75 << 30 ) )
return false ;
}
return true ;
}
static bool F_99 ( struct V_3 * V_4 ,
enum V_75 V_75 , T_1 V_105 )
{
if ( ( V_105 & V_166 ) == 0 )
return false ;
if ( F_93 ( V_4 -> V_2 ) ) {
if ( ( V_105 & V_167 ) != F_100 ( V_75 ) )
return false ;
} else if ( F_17 ( V_4 -> V_2 ) ) {
if ( ( V_105 & V_168 ) != F_101 ( V_75 ) )
return false ;
} else {
if ( ( V_105 & V_169 ) != F_102 ( V_75 ) )
return false ;
}
return true ;
}
static bool F_103 ( struct V_3 * V_4 ,
enum V_75 V_75 , T_1 V_105 )
{
if ( ( V_105 & V_170 ) == 0 )
return false ;
if ( F_93 ( V_4 -> V_2 ) ) {
if ( ( V_105 & V_171 ) != F_104 ( V_75 ) )
return false ;
} else {
if ( ( V_105 & V_172 ) != F_105 ( V_75 ) )
return false ;
}
return true ;
}
static bool F_106 ( struct V_3 * V_4 ,
enum V_75 V_75 , T_1 V_105 )
{
if ( ( V_105 & V_173 ) == 0 )
return false ;
if ( F_93 ( V_4 -> V_2 ) ) {
if ( ( V_105 & V_171 ) != F_104 ( V_75 ) )
return false ;
} else {
if ( ( V_105 & V_174 ) != F_107 ( V_75 ) )
return false ;
}
return true ;
}
static void F_108 ( struct V_3 * V_4 ,
enum V_75 V_75 , int V_83 , T_1 V_159 )
{
T_1 V_105 = F_4 ( V_83 ) ;
F_40 ( F_96 ( V_4 , V_75 , V_159 , V_105 ) ,
L_32 ,
V_83 , F_73 ( V_75 ) ) ;
F_40 ( F_52 ( V_4 -> V_2 ) && ( V_105 & V_160 ) == 0
&& ( V_105 & V_175 ) ,
L_33 ) ;
}
static void F_109 ( struct V_3 * V_4 ,
enum V_75 V_75 , int V_83 )
{
T_1 V_105 = F_4 ( V_83 ) ;
F_40 ( F_99 ( V_4 , V_75 , V_105 ) ,
L_34 ,
V_83 , F_73 ( V_75 ) ) ;
F_40 ( F_52 ( V_4 -> V_2 ) && ( V_105 & V_166 ) == 0
&& ( V_105 & V_176 ) ,
L_35 ) ;
}
static void F_110 ( struct V_3 * V_4 ,
enum V_75 V_75 )
{
int V_83 ;
T_1 V_105 ;
F_108 ( V_4 , V_75 , V_177 , V_178 ) ;
F_108 ( V_4 , V_75 , V_179 , V_180 ) ;
F_108 ( V_4 , V_75 , V_181 , V_182 ) ;
V_83 = V_183 ;
V_105 = F_4 ( V_83 ) ;
F_40 ( F_106 ( V_4 , V_75 , V_105 ) ,
L_36 ,
F_73 ( V_75 ) ) ;
V_83 = V_131 ;
V_105 = F_4 ( V_83 ) ;
F_40 ( F_103 ( V_4 , V_75 , V_105 ) ,
L_37 ,
F_73 ( V_75 ) ) ;
F_109 ( V_4 , V_75 , V_184 ) ;
F_109 ( V_4 , V_75 , V_185 ) ;
F_109 ( V_4 , V_75 , V_186 ) ;
}
static void F_111 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_18 ( V_2 ) )
return;
if ( F_17 ( V_2 ) ) {
F_112 ( V_187 ) = V_188 ;
F_112 ( V_189 ) = V_190 ;
} else {
F_112 ( V_187 ) = V_190 ;
}
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_18 ( V_2 ) )
return;
if ( F_17 ( V_2 ) ) {
enum V_191 V_192 ;
T_1 V_105 ;
for ( V_192 = V_187 ; V_192 < V_193 ; V_192 ++ ) {
if ( F_38 ( F_4 ( V_194 ) &
F_114 ( V_192 ) , 1 ) )
F_115 ( L_38 , V_192 ) ;
V_105 = F_4 ( V_195 ) ;
F_44 ( V_195 ,
F_116 ( V_192 , V_105 ) ) ;
}
} else {
if ( F_4 ( V_196 ) & V_197 )
return;
F_117 ( V_4 , V_198 ,
false ) ;
F_117 ( V_4 , V_198 ,
true ) ;
}
}
static void F_118 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_83 = F_55 ( V_21 -> V_75 ) ;
T_1 V_48 = V_21 -> V_71 . V_199 . V_48 ;
F_119 ( V_4 , V_21 -> V_75 ) ;
F_120 ( ! F_18 ( V_4 -> V_2 ) ) ;
if ( F_121 ( V_4 -> V_2 ) && ! F_122 ( V_4 -> V_2 ) )
F_72 ( V_4 , V_21 -> V_75 ) ;
F_44 ( V_83 , V_48 ) ;
F_123 ( V_83 ) ;
F_124 ( 150 ) ;
if ( F_38 ( ( ( F_4 ( V_83 ) & V_200 ) == V_200 ) , 1 ) )
F_115 ( L_39 , V_21 -> V_75 ) ;
F_44 ( F_125 ( V_21 -> V_75 ) , V_21 -> V_71 . V_199 . V_201 ) ;
F_123 ( F_125 ( V_21 -> V_75 ) ) ;
F_44 ( V_83 , V_48 ) ;
F_123 ( V_83 ) ;
F_124 ( 150 ) ;
F_44 ( V_83 , V_48 ) ;
F_123 ( V_83 ) ;
F_124 ( 150 ) ;
F_44 ( V_83 , V_48 ) ;
F_123 ( V_83 ) ;
F_124 ( 150 ) ;
}
static void F_126 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_75 = V_21 -> V_75 ;
enum V_202 V_91 = F_127 ( V_75 ) ;
T_1 V_203 ;
F_119 ( V_4 , V_21 -> V_75 ) ;
F_120 ( ! F_17 ( V_4 -> V_2 ) ) ;
F_57 ( & V_4 -> V_108 ) ;
V_203 = F_128 ( V_4 , V_75 , F_129 ( V_91 ) ) ;
V_203 |= V_204 ;
F_130 ( V_4 , V_75 , F_129 ( V_91 ) , V_203 ) ;
F_124 ( 1 ) ;
F_44 ( F_55 ( V_75 ) , V_21 -> V_71 . V_199 . V_48 ) ;
if ( F_38 ( ( ( F_4 ( F_55 ( V_75 ) ) & V_200 ) == V_200 ) , 1 ) )
F_115 ( L_40 , V_75 ) ;
F_44 ( F_125 ( V_75 ) , V_21 -> V_71 . V_199 . V_201 ) ;
F_123 ( F_125 ( V_75 ) ) ;
F_59 ( & V_4 -> V_108 ) ;
}
static void F_131 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_83 = F_55 ( V_21 -> V_75 ) ;
T_1 V_48 = V_21 -> V_71 . V_199 . V_48 ;
F_119 ( V_4 , V_21 -> V_75 ) ;
F_120 ( F_43 ( V_2 ) -> V_81 >= 5 ) ;
if ( F_121 ( V_2 ) && ! F_122 ( V_2 ) )
F_72 ( V_4 , V_21 -> V_75 ) ;
F_44 ( V_83 , V_48 ) ;
F_123 ( V_83 ) ;
F_124 ( 150 ) ;
if ( F_43 ( V_2 ) -> V_81 >= 4 ) {
F_44 ( F_125 ( V_21 -> V_75 ) ,
V_21 -> V_71 . V_199 . V_201 ) ;
} else {
F_44 ( V_83 , V_48 ) ;
}
F_44 ( V_83 , V_48 ) ;
F_123 ( V_83 ) ;
F_124 ( 150 ) ;
F_44 ( V_83 , V_48 ) ;
F_123 ( V_83 ) ;
F_124 ( 150 ) ;
F_44 ( V_83 , V_48 ) ;
F_123 ( V_83 ) ;
F_124 ( 150 ) ;
}
static void F_132 ( struct V_3 * V_4 , enum V_75 V_75 )
{
if ( V_75 == V_128 && ( V_4 -> V_141 & V_142 ) )
return;
F_119 ( V_4 , V_75 ) ;
F_44 ( F_55 ( V_75 ) , 0 ) ;
F_123 ( F_55 ( V_75 ) ) ;
}
static void F_133 ( struct V_3 * V_4 , enum V_75 V_75 )
{
T_1 V_105 = 0 ;
F_119 ( V_4 , V_75 ) ;
if ( V_75 == V_137 )
V_105 = V_205 | V_206 ;
F_44 ( F_55 ( V_75 ) , V_105 ) ;
F_123 ( F_55 ( V_75 ) ) ;
}
static void F_134 ( struct V_3 * V_4 , enum V_75 V_75 )
{
enum V_202 V_91 = F_127 ( V_75 ) ;
T_1 V_105 ;
F_119 ( V_4 , V_75 ) ;
V_105 = V_207 ;
if ( V_75 != V_128 )
V_105 |= V_205 ;
F_44 ( F_55 ( V_75 ) , V_105 ) ;
F_123 ( F_55 ( V_75 ) ) ;
F_57 ( & V_4 -> V_108 ) ;
V_105 = F_128 ( V_4 , V_75 , F_129 ( V_91 ) ) ;
V_105 &= ~ V_204 ;
F_130 ( V_4 , V_75 , F_129 ( V_91 ) , V_105 ) ;
F_59 ( & V_4 -> V_108 ) ;
}
void F_135 ( struct V_3 * V_4 ,
struct V_90 * V_208 )
{
T_1 V_209 ;
int V_210 ;
switch ( V_208 -> V_91 ) {
case V_93 :
V_209 = V_211 ;
V_210 = F_55 ( 0 ) ;
break;
case V_95 :
V_209 = V_212 ;
V_210 = F_55 ( 0 ) ;
break;
case V_97 :
V_209 = V_213 ;
V_210 = V_214 ;
break;
default:
F_136 () ;
}
if ( F_38 ( ( F_4 ( V_210 ) & V_209 ) == 0 , 1000 ) )
F_40 ( 1 , L_41 ,
F_137 ( V_208 -> V_91 ) , F_4 ( V_210 ) ) ;
}
static void F_138 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_111 * V_115 = F_60 ( V_21 ) ;
F_2 ( ! V_115 -> V_215 ) ;
if ( V_115 -> V_68 == 0 ) {
F_63 ( L_42 , V_115 -> V_119 ) ;
F_2 ( V_115 -> V_216 ) ;
F_139 ( V_4 , V_115 ) ;
V_115 -> V_217 ( V_4 , V_115 ) ;
}
}
static void F_140 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_111 * V_115 = F_60 ( V_21 ) ;
if ( F_2 ( V_115 == NULL ) )
return;
if ( F_2 ( V_115 -> V_215 == 0 ) )
return;
F_45 ( L_43 ,
V_115 -> V_119 , V_115 -> V_68 , V_115 -> V_216 ,
V_21 -> V_112 . V_112 . V_218 ) ;
if ( V_115 -> V_68 ++ ) {
F_2 ( ! V_115 -> V_216 ) ;
F_141 ( V_4 , V_115 ) ;
return;
}
F_2 ( V_115 -> V_216 ) ;
F_45 ( L_44 , V_115 -> V_119 ) ;
V_115 -> V_219 ( V_4 , V_115 ) ;
V_115 -> V_216 = true ;
}
static void F_142 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_111 * V_115 = F_60 ( V_21 ) ;
F_120 ( F_43 ( V_2 ) -> V_81 < 5 ) ;
if ( F_2 ( V_115 == NULL ) )
return;
if ( F_2 ( V_115 -> V_215 == 0 ) )
return;
F_45 ( L_45 ,
V_115 -> V_119 , V_115 -> V_68 , V_115 -> V_216 ,
V_21 -> V_112 . V_112 . V_218 ) ;
if ( F_2 ( V_115 -> V_68 == 0 ) ) {
F_139 ( V_4 , V_115 ) ;
return;
}
F_141 ( V_4 , V_115 ) ;
F_2 ( ! V_115 -> V_216 ) ;
if ( -- V_115 -> V_68 )
return;
F_45 ( L_46 , V_115 -> V_119 ) ;
V_115 -> V_220 ( V_4 , V_115 ) ;
V_115 -> V_216 = false ;
}
static void F_143 ( struct V_3 * V_4 ,
enum V_75 V_75 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_20 * V_21 = V_4 -> V_76 [ V_75 ] ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
T_4 V_83 , V_105 , V_221 ;
F_120 ( F_43 ( V_2 ) -> V_81 < 5 ) ;
F_141 ( V_4 ,
F_60 ( V_67 ) ) ;
F_144 ( V_4 , V_75 ) ;
F_145 ( V_4 , V_75 ) ;
if ( F_93 ( V_2 ) ) {
V_83 = F_146 ( V_75 ) ;
V_105 = F_4 ( V_83 ) ;
V_105 |= V_222 ;
F_44 ( V_83 , V_105 ) ;
}
V_83 = F_95 ( V_75 ) ;
V_105 = F_4 ( V_83 ) ;
V_221 = F_4 ( F_50 ( V_75 ) ) ;
if ( F_52 ( V_4 -> V_2 ) ) {
V_105 &= ~ V_223 ;
V_105 |= V_221 & V_223 ;
}
V_105 &= ~ V_224 ;
if ( ( V_221 & V_225 ) == V_226 )
if ( F_52 ( V_4 -> V_2 ) &&
F_9 ( V_21 , V_36 ) )
V_105 |= V_227 ;
else
V_105 |= V_228 ;
else
V_105 |= V_229 ;
F_44 ( V_83 , V_105 | V_158 ) ;
if ( F_38 ( F_4 ( V_83 ) & V_230 , 100 ) )
F_115 ( L_47 , F_73 ( V_75 ) ) ;
}
static void F_147 ( struct V_3 * V_4 ,
enum V_74 V_77 )
{
T_1 V_105 , V_221 ;
F_120 ( F_43 ( V_4 -> V_2 ) -> V_81 < 5 ) ;
F_144 ( V_4 , (enum V_75 ) V_77 ) ;
F_145 ( V_4 , V_231 ) ;
V_105 = F_4 ( V_232 ) ;
V_105 |= V_222 ;
F_44 ( V_232 , V_105 ) ;
V_105 = V_158 ;
V_221 = F_4 ( F_50 ( V_77 ) ) ;
if ( ( V_221 & V_233 ) ==
V_226 )
V_105 |= V_228 ;
else
V_105 |= V_229 ;
F_44 ( V_234 , V_105 ) ;
if ( F_38 ( F_4 ( V_234 ) & V_230 , 100 ) )
F_115 ( L_48 ) ;
}
static void F_148 ( struct V_3 * V_4 ,
enum V_75 V_75 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_83 , V_105 ;
F_149 ( V_4 , V_75 ) ;
F_150 ( V_4 , V_75 ) ;
F_110 ( V_4 , V_75 ) ;
V_83 = F_95 ( V_75 ) ;
V_105 = F_4 ( V_83 ) ;
V_105 &= ~ V_158 ;
F_44 ( V_83 , V_105 ) ;
if ( F_38 ( ( F_4 ( V_83 ) & V_230 ) == 0 , 50 ) )
F_115 ( L_49 , F_73 ( V_75 ) ) ;
if ( ! F_52 ( V_2 ) ) {
V_83 = F_146 ( V_75 ) ;
V_105 = F_4 ( V_83 ) ;
V_105 &= ~ V_222 ;
F_44 ( V_83 , V_105 ) ;
}
}
static void F_151 ( struct V_3 * V_4 )
{
T_1 V_105 ;
V_105 = F_4 ( V_234 ) ;
V_105 &= ~ V_158 ;
F_44 ( V_234 , V_105 ) ;
if ( F_38 ( ( F_4 ( V_234 ) & V_230 ) == 0 , 50 ) )
F_115 ( L_50 ) ;
V_105 = F_4 ( V_232 ) ;
V_105 &= ~ V_222 ;
F_44 ( V_232 , V_105 ) ;
}
static void F_152 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_75 V_75 = V_21 -> V_75 ;
enum V_74 V_77 = F_35 ( V_4 ,
V_75 ) ;
enum V_75 V_235 ;
int V_83 ;
T_1 V_105 ;
F_84 ( V_4 , V_75 ) ;
F_153 ( V_4 , V_75 ) ;
F_86 ( V_4 , V_75 ) ;
if ( F_62 ( V_4 -> V_2 ) )
V_235 = V_231 ;
else
V_235 = V_75 ;
if ( ! F_3 ( V_4 -> V_2 ) )
if ( F_9 ( & V_21 -> V_112 , V_236 ) )
F_154 ( V_4 ) ;
else
F_155 ( V_4 , V_75 ) ;
else {
if ( V_21 -> V_71 . V_237 ) {
F_156 ( V_4 , V_235 ) ;
F_70 ( V_4 ,
(enum V_75 ) V_77 ) ;
}
}
V_83 = F_50 ( V_77 ) ;
V_105 = F_4 ( V_83 ) ;
if ( V_105 & V_143 ) {
F_2 ( ! ( V_75 == V_128 &&
V_4 -> V_141 & V_142 ) ) ;
return;
}
F_44 ( V_83 , V_105 | V_143 ) ;
F_123 ( V_83 ) ;
}
static void F_157 ( struct V_3 * V_4 ,
enum V_75 V_75 )
{
enum V_74 V_77 = F_35 ( V_4 ,
V_75 ) ;
int V_83 ;
T_1 V_105 ;
F_84 ( V_4 , V_75 ) ;
F_153 ( V_4 , V_75 ) ;
F_86 ( V_4 , V_75 ) ;
if ( V_75 == V_128 && ( V_4 -> V_141 & V_142 ) )
return;
V_83 = F_50 ( V_77 ) ;
V_105 = F_4 ( V_83 ) ;
if ( ( V_105 & V_143 ) == 0 )
return;
F_44 ( V_83 , V_105 & ~ V_143 ) ;
F_49 ( V_4 -> V_2 , V_75 ) ;
}
void F_158 ( struct V_3 * V_4 ,
enum V_144 V_144 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_83 = F_43 ( V_2 ) -> V_81 >= 4 ? F_159 ( V_144 ) : F_160 ( V_144 ) ;
F_44 ( V_83 , F_4 ( V_83 ) ) ;
F_123 ( V_83 ) ;
}
static void F_161 ( struct V_3 * V_4 ,
enum V_144 V_144 , enum V_75 V_75 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_67 * V_67 =
F_34 ( V_4 -> V_76 [ V_75 ] ) ;
int V_83 ;
T_1 V_105 ;
F_162 ( V_4 , V_75 ) ;
if ( V_67 -> V_238 )
return;
V_67 -> V_238 = true ;
V_83 = F_82 ( V_144 ) ;
V_105 = F_4 ( V_83 ) ;
F_2 ( V_105 & V_145 ) ;
F_44 ( V_83 , V_105 | V_145 ) ;
F_158 ( V_4 , V_144 ) ;
if ( F_163 ( V_2 ) )
F_41 ( V_2 , V_67 -> V_75 ) ;
}
static void F_164 ( struct V_3 * V_4 ,
enum V_144 V_144 , enum V_75 V_75 )
{
struct V_67 * V_67 =
F_34 ( V_4 -> V_76 [ V_75 ] ) ;
int V_83 ;
T_1 V_105 ;
if ( ! V_67 -> V_238 )
return;
V_67 -> V_238 = false ;
V_83 = F_82 ( V_144 ) ;
V_105 = F_4 ( V_83 ) ;
F_2 ( ( V_105 & V_145 ) == 0 ) ;
F_44 ( V_83 , V_105 & ~ V_145 ) ;
F_158 ( V_4 , V_144 ) ;
}
static bool F_165 ( struct V_1 * V_2 )
{
#ifdef F_166
if ( F_43 ( V_2 ) -> V_81 >= 6 && V_239 )
return true ;
#endif
return false ;
}
static int F_167 ( struct V_1 * V_2 , int V_240 , bool V_241 )
{
int V_242 ;
V_242 = V_241 ? ( F_19 ( V_2 ) ? 16 : 8 ) : 1 ;
return F_168 ( V_240 , V_242 ) ;
}
int
F_169 ( struct V_1 * V_2 ,
struct V_243 * V_244 ,
struct V_245 * V_246 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_247 ;
int V_248 ;
switch ( V_244 -> V_249 ) {
case V_250 :
if ( F_170 ( V_2 ) || F_171 ( V_2 ) )
V_247 = 128 * 1024 ;
else if ( F_43 ( V_2 ) -> V_81 >= 4 )
V_247 = 4 * 1024 ;
else
V_247 = 64 * 1024 ;
break;
case V_251 :
V_247 = 0 ;
break;
case V_252 :
F_40 ( 1 , L_51 ) ;
return - V_253 ;
default:
F_136 () ;
}
if ( F_165 ( V_2 ) && V_247 < 256 * 1024 )
V_247 = 256 * 1024 ;
V_4 -> V_254 . V_255 = false ;
V_248 = F_172 ( V_244 , V_247 , V_246 ) ;
if ( V_248 )
goto V_256;
V_248 = F_173 ( V_244 ) ;
if ( V_248 )
goto V_257;
F_174 ( V_244 ) ;
V_4 -> V_254 . V_255 = true ;
return 0 ;
V_257:
F_175 ( V_244 ) ;
V_256:
V_4 -> V_254 . V_255 = true ;
return V_248 ;
}
void F_176 ( struct V_243 * V_244 )
{
F_177 ( V_244 ) ;
F_175 ( V_244 ) ;
}
unsigned long F_178 ( int * V_258 , int * V_259 ,
unsigned int V_249 ,
unsigned int V_260 ,
unsigned int V_261 )
{
if ( V_249 != V_250 ) {
unsigned int V_262 , V_263 ;
V_262 = * V_259 / 8 ;
* V_259 %= 8 ;
V_263 = * V_258 / ( 512 / V_260 ) ;
* V_258 %= 512 / V_260 ;
return V_262 * V_261 * 8 + V_263 * 4096 ;
} else {
unsigned int V_264 ;
V_264 = * V_259 * V_261 + * V_258 * V_260 ;
* V_259 = 0 ;
* V_258 = ( V_264 & 4095 ) / V_260 ;
return V_264 & - 4096 ;
}
}
int F_179 ( int V_265 )
{
switch ( V_265 ) {
case V_266 :
return V_267 ;
case V_268 :
return V_269 ;
case V_270 :
return V_271 ;
default:
case V_272 :
return V_273 ;
case V_274 :
return V_275 ;
case V_276 :
return V_277 ;
case V_278 :
return V_279 ;
}
}
static bool F_180 ( struct V_67 * V_21 ,
struct V_280 * V_281 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_243 * V_244 = NULL ;
struct V_282 V_283 = { 0 } ;
T_1 V_112 = V_281 -> V_112 ;
if ( V_281 -> V_284 == 0 )
return false ;
V_244 = F_181 ( V_2 , V_112 , V_112 ,
V_281 -> V_284 ) ;
if ( ! V_244 )
return false ;
if ( V_281 -> V_241 ) {
V_244 -> V_249 = V_251 ;
V_244 -> V_285 = V_21 -> V_112 . V_69 -> V_70 -> V_286 [ 0 ] ;
}
V_283 . V_287 = V_21 -> V_112 . V_69 -> V_70 -> V_287 ;
V_283 . V_288 = V_21 -> V_112 . V_69 -> V_70 -> V_288 ;
V_283 . V_240 = V_21 -> V_112 . V_69 -> V_70 -> V_240 ;
V_283 . V_286 [ 0 ] = V_21 -> V_112 . V_69 -> V_70 -> V_286 [ 0 ] ;
F_57 ( & V_2 -> V_289 ) ;
if ( F_182 ( V_2 , F_183 ( V_21 -> V_112 . V_69 -> V_70 ) ,
& V_283 , V_244 ) ) {
F_45 ( L_52 ) ;
goto V_290;
}
F_59 ( & V_2 -> V_289 ) ;
F_45 ( L_53 , V_244 ) ;
return true ;
V_290:
F_184 ( & V_244 -> V_112 ) ;
F_59 ( & V_2 -> V_289 ) ;
return false ;
}
static void F_185 ( struct V_67 * V_67 ,
struct V_280 * V_281 )
{
struct V_1 * V_2 = V_67 -> V_112 . V_2 ;
struct V_20 * V_291 ;
struct V_67 * V_146 ;
struct V_292 * V_70 ;
if ( ! V_67 -> V_112 . V_69 -> V_70 )
return;
if ( F_180 ( V_67 , V_281 ) )
return;
F_186 ( V_67 -> V_112 . V_69 -> V_70 ) ;
V_67 -> V_112 . V_69 -> V_70 = NULL ;
F_187 (dev, c) {
V_146 = F_34 ( V_291 ) ;
if ( V_291 == & V_67 -> V_112 )
continue;
if ( ! V_146 -> V_68 || ! V_291 -> V_69 -> V_70 )
continue;
V_70 = F_183 ( V_291 -> V_69 -> V_70 ) ;
if ( F_188 ( V_70 -> V_244 ) == V_281 -> V_112 ) {
F_189 ( V_291 -> V_69 -> V_70 ) ;
V_67 -> V_112 . V_69 -> V_70 = V_291 -> V_69 -> V_70 ;
break;
}
}
}
static void F_190 ( struct V_20 * V_21 ,
struct V_293 * V_70 ,
int V_258 , int V_259 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
struct V_292 * V_294 ;
struct V_243 * V_244 ;
int V_144 = V_67 -> V_144 ;
unsigned long V_295 ;
T_1 V_296 ;
T_1 V_83 ;
V_294 = F_183 ( V_70 ) ;
V_244 = V_294 -> V_244 ;
V_83 = F_82 ( V_144 ) ;
V_296 = F_4 ( V_83 ) ;
V_296 &= ~ V_297 ;
switch ( V_70 -> V_287 ) {
case V_267 :
V_296 |= V_266 ;
break;
case V_269 :
case V_298 :
V_296 |= V_268 ;
break;
case V_271 :
V_296 |= V_270 ;
break;
case V_273 :
case V_299 :
V_296 |= V_272 ;
break;
case V_275 :
case V_300 :
V_296 |= V_274 ;
break;
case V_277 :
case V_301 :
V_296 |= V_276 ;
break;
case V_279 :
case V_302 :
V_296 |= V_278 ;
break;
default:
F_136 () ;
}
if ( F_43 ( V_2 ) -> V_81 >= 4 ) {
if ( V_244 -> V_249 != V_250 )
V_296 |= V_303 ;
else
V_296 &= ~ V_303 ;
}
if ( F_15 ( V_2 ) )
V_296 |= V_304 ;
F_44 ( V_83 , V_296 ) ;
V_295 = V_259 * V_70 -> V_286 [ 0 ] + V_258 * ( V_70 -> V_305 / 8 ) ;
if ( F_43 ( V_2 ) -> V_81 >= 4 ) {
V_67 -> V_306 =
F_178 ( & V_258 , & V_259 , V_244 -> V_249 ,
V_70 -> V_305 / 8 ,
V_70 -> V_286 [ 0 ] ) ;
V_295 -= V_67 -> V_306 ;
} else {
V_67 -> V_306 = V_295 ;
}
F_45 ( L_54 ,
F_188 ( V_244 ) , V_295 , V_258 , V_259 ,
V_70 -> V_286 [ 0 ] ) ;
F_44 ( F_191 ( V_144 ) , V_70 -> V_286 [ 0 ] ) ;
if ( F_43 ( V_2 ) -> V_81 >= 4 ) {
F_44 ( F_159 ( V_144 ) ,
F_188 ( V_244 ) + V_67 -> V_306 ) ;
F_44 ( F_192 ( V_144 ) , ( V_259 << 16 ) | V_258 ) ;
F_44 ( F_193 ( V_144 ) , V_295 ) ;
} else
F_44 ( F_160 ( V_144 ) , F_188 ( V_244 ) + V_295 ) ;
F_123 ( V_83 ) ;
}
static void F_194 ( struct V_20 * V_21 ,
struct V_293 * V_70 ,
int V_258 , int V_259 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
struct V_292 * V_294 ;
struct V_243 * V_244 ;
int V_144 = V_67 -> V_144 ;
unsigned long V_295 ;
T_1 V_296 ;
T_1 V_83 ;
V_294 = F_183 ( V_70 ) ;
V_244 = V_294 -> V_244 ;
V_83 = F_82 ( V_144 ) ;
V_296 = F_4 ( V_83 ) ;
V_296 &= ~ V_297 ;
switch ( V_70 -> V_287 ) {
case V_267 :
V_296 |= V_266 ;
break;
case V_271 :
V_296 |= V_270 ;
break;
case V_273 :
case V_299 :
V_296 |= V_272 ;
break;
case V_275 :
case V_300 :
V_296 |= V_274 ;
break;
case V_277 :
case V_301 :
V_296 |= V_276 ;
break;
case V_279 :
case V_302 :
V_296 |= V_278 ;
break;
default:
F_136 () ;
}
if ( V_244 -> V_249 != V_250 )
V_296 |= V_303 ;
else
V_296 &= ~ V_303 ;
if ( F_195 ( V_2 ) || F_163 ( V_2 ) )
V_296 &= ~ V_304 ;
else
V_296 |= V_304 ;
F_44 ( V_83 , V_296 ) ;
V_295 = V_259 * V_70 -> V_286 [ 0 ] + V_258 * ( V_70 -> V_305 / 8 ) ;
V_67 -> V_306 =
F_178 ( & V_258 , & V_259 , V_244 -> V_249 ,
V_70 -> V_305 / 8 ,
V_70 -> V_286 [ 0 ] ) ;
V_295 -= V_67 -> V_306 ;
F_45 ( L_54 ,
F_188 ( V_244 ) , V_295 , V_258 , V_259 ,
V_70 -> V_286 [ 0 ] ) ;
F_44 ( F_191 ( V_144 ) , V_70 -> V_286 [ 0 ] ) ;
F_44 ( F_159 ( V_144 ) ,
F_188 ( V_244 ) + V_67 -> V_306 ) ;
if ( F_195 ( V_2 ) || F_163 ( V_2 ) ) {
F_44 ( F_196 ( V_144 ) , ( V_259 << 16 ) | V_258 ) ;
} else {
F_44 ( F_192 ( V_144 ) , ( V_259 << 16 ) | V_258 ) ;
F_44 ( F_193 ( V_144 ) , V_295 ) ;
}
F_123 ( V_83 ) ;
}
static int
F_197 ( struct V_20 * V_21 , struct V_293 * V_70 ,
int V_258 , int V_259 , enum V_307 V_104 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_308 . V_309 )
V_4 -> V_308 . V_309 ( V_2 ) ;
F_198 ( V_21 ) ;
V_4 -> V_308 . V_310 ( V_21 , V_70 , V_258 , V_259 ) ;
return 0 ;
}
void F_199 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 ;
F_187 (dev, crtc) {
struct V_67 * V_67 = F_34 ( V_21 ) ;
enum V_144 V_144 = V_67 -> V_144 ;
F_200 ( V_2 , V_144 ) ;
F_201 ( V_2 , V_144 ) ;
}
F_187 (dev, crtc) {
struct V_67 * V_67 = F_34 ( V_21 ) ;
F_202 ( & V_21 -> V_311 , NULL ) ;
if ( V_67 -> V_68 && V_21 -> V_69 -> V_70 )
V_4 -> V_308 . V_310 ( V_21 ,
V_21 -> V_69 -> V_70 ,
V_21 -> V_258 ,
V_21 -> V_259 ) ;
F_203 ( & V_21 -> V_311 ) ;
}
}
static int
F_204 ( struct V_293 * V_312 )
{
struct V_243 * V_244 = F_183 ( V_312 ) -> V_244 ;
struct V_3 * V_4 = V_244 -> V_112 . V_2 -> V_5 ;
bool V_313 = V_4 -> V_254 . V_255 ;
int V_248 ;
V_4 -> V_254 . V_255 = false ;
V_248 = F_205 ( V_244 ) ;
V_4 -> V_254 . V_255 = V_313 ;
return V_248 ;
}
static bool F_206 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
unsigned long V_314 ;
bool V_315 ;
if ( F_207 ( & V_4 -> V_316 ) ||
V_67 -> V_317 != F_208 ( & V_4 -> V_316 . V_317 ) )
return false ;
F_209 ( & V_2 -> V_318 , V_314 ) ;
V_315 = F_34 ( V_21 ) -> V_319 != NULL ;
F_210 ( & V_2 -> V_318 , V_314 ) ;
return V_315 ;
}
static int
F_211 ( struct V_20 * V_21 , int V_258 , int V_259 ,
struct V_293 * V_70 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
struct V_293 * V_312 ;
int V_248 ;
if ( F_206 ( V_21 ) ) {
F_115 ( L_55 ) ;
return - V_320 ;
}
if ( ! V_70 ) {
F_115 ( L_56 ) ;
return 0 ;
}
if ( V_67 -> V_144 > F_43 ( V_2 ) -> V_321 ) {
F_115 ( L_57 ,
F_83 ( V_67 -> V_144 ) ,
F_43 ( V_2 ) -> V_321 ) ;
return - V_253 ;
}
F_57 ( & V_2 -> V_289 ) ;
V_248 = F_169 ( V_2 ,
F_183 ( V_70 ) -> V_244 ,
NULL ) ;
F_59 ( & V_2 -> V_289 ) ;
if ( V_248 != 0 ) {
F_115 ( L_58 ) ;
return V_248 ;
}
if ( V_322 . V_323 ) {
const struct V_324 * V_72 =
& V_67 -> V_71 . V_72 ;
F_44 ( F_212 ( V_67 -> V_75 ) ,
( ( V_72 -> V_325 - 1 ) << 16 ) |
( V_72 -> V_326 - 1 ) ) ;
if ( ! V_67 -> V_71 . V_327 . V_103 &&
( F_9 ( V_21 , V_25 ) ||
F_9 ( V_21 , V_328 ) ) ) {
F_44 ( F_213 ( V_67 -> V_75 ) , 0 ) ;
F_44 ( F_214 ( V_67 -> V_75 ) , 0 ) ;
F_44 ( F_215 ( V_67 -> V_75 ) , 0 ) ;
}
V_67 -> V_71 . V_329 = V_72 -> V_325 ;
V_67 -> V_71 . V_330 = V_72 -> V_326 ;
}
V_4 -> V_308 . V_310 ( V_21 , V_70 , V_258 , V_259 ) ;
V_312 = V_21 -> V_69 -> V_70 ;
V_21 -> V_69 -> V_70 = V_70 ;
V_21 -> V_258 = V_258 ;
V_21 -> V_259 = V_259 ;
if ( V_312 ) {
if ( V_67 -> V_68 && V_312 != V_70 )
F_41 ( V_2 , V_67 -> V_75 ) ;
F_57 ( & V_2 -> V_289 ) ;
F_176 ( F_183 ( V_312 ) -> V_244 ) ;
F_59 ( & V_2 -> V_289 ) ;
}
F_57 ( & V_2 -> V_289 ) ;
F_216 ( V_2 ) ;
F_217 ( V_2 ) ;
F_59 ( & V_2 -> V_289 ) ;
return 0 ;
}
static void F_218 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_75 = V_67 -> V_75 ;
T_1 V_83 , V_331 ;
V_83 = F_67 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
if ( F_219 ( V_2 ) ) {
V_331 &= ~ V_332 ;
V_331 |= V_332 | V_333 ;
} else {
V_331 &= ~ V_334 ;
V_331 |= V_334 | V_333 ;
}
F_44 ( V_83 , V_331 ) ;
V_83 = F_69 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
if ( F_93 ( V_2 ) ) {
V_331 &= ~ V_335 ;
V_331 |= V_336 ;
} else {
V_331 &= ~ V_334 ;
V_331 |= V_334 ;
}
F_44 ( V_83 , V_331 | V_337 ) ;
F_123 ( V_83 ) ;
F_124 ( 1000 ) ;
if ( F_219 ( V_2 ) )
F_44 ( V_83 , F_4 ( V_83 ) | V_338 |
V_339 ) ;
}
static bool F_220 ( struct V_67 * V_21 )
{
return V_21 -> V_112 . V_103 && V_21 -> V_68 &&
V_21 -> V_71 . V_237 ;
}
static void F_221 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_340 =
F_34 ( V_4 -> V_76 [ V_137 ] ) ;
struct V_67 * V_341 =
F_34 ( V_4 -> V_76 [ V_342 ] ) ;
T_4 V_331 ;
if ( ! F_220 ( V_340 ) &&
! F_220 ( V_341 ) ) {
F_2 ( F_4 ( F_69 ( V_137 ) ) & V_122 ) ;
F_2 ( F_4 ( F_69 ( V_342 ) ) & V_122 ) ;
V_331 = F_4 ( V_343 ) ;
V_331 &= ~ V_344 ;
F_45 ( L_59 ) ;
F_44 ( V_343 , V_331 ) ;
}
}
static void F_222 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_75 = V_67 -> V_75 ;
T_1 V_83 , V_331 , V_345 ;
F_162 ( V_4 , V_75 ) ;
V_83 = F_223 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_346 ;
V_331 &= ~ V_347 ;
F_44 ( V_83 , V_331 ) ;
F_4 ( V_83 ) ;
F_124 ( 150 ) ;
V_83 = F_67 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_348 ;
V_331 |= F_224 ( V_67 -> V_71 . V_349 ) ;
V_331 &= ~ V_334 ;
V_331 |= V_350 ;
F_44 ( V_83 , V_331 | V_121 ) ;
V_83 = F_69 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_334 ;
V_331 |= V_350 ;
F_44 ( V_83 , V_331 | V_122 ) ;
F_123 ( V_83 ) ;
F_124 ( 150 ) ;
F_44 ( F_225 ( V_75 ) , V_351 ) ;
F_44 ( F_225 ( V_75 ) , V_351 |
V_352 ) ;
V_83 = F_226 ( V_75 ) ;
for ( V_345 = 0 ; V_345 < 5 ; V_345 ++ ) {
V_331 = F_4 ( V_83 ) ;
F_45 ( L_60 , V_331 ) ;
if ( ( V_331 & V_347 ) ) {
F_45 ( L_61 ) ;
F_44 ( V_83 , V_331 | V_347 ) ;
break;
}
}
if ( V_345 == 5 )
F_115 ( L_62 ) ;
V_83 = F_67 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_334 ;
V_331 |= V_353 ;
F_44 ( V_83 , V_331 ) ;
V_83 = F_69 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_334 ;
V_331 |= V_353 ;
F_44 ( V_83 , V_331 ) ;
F_123 ( V_83 ) ;
F_124 ( 150 ) ;
V_83 = F_226 ( V_75 ) ;
for ( V_345 = 0 ; V_345 < 5 ; V_345 ++ ) {
V_331 = F_4 ( V_83 ) ;
F_45 ( L_60 , V_331 ) ;
if ( V_331 & V_346 ) {
F_44 ( V_83 , V_331 | V_346 ) ;
F_45 ( L_63 ) ;
break;
}
}
if ( V_345 == 5 )
F_115 ( L_64 ) ;
F_45 ( L_65 ) ;
}
static void F_227 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_75 = V_67 -> V_75 ;
T_1 V_83 , V_331 , V_146 , V_354 ;
V_83 = F_223 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_346 ;
V_331 &= ~ V_347 ;
F_44 ( V_83 , V_331 ) ;
F_123 ( V_83 ) ;
F_124 ( 150 ) ;
V_83 = F_67 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_348 ;
V_331 |= F_224 ( V_67 -> V_71 . V_349 ) ;
V_331 &= ~ V_334 ;
V_331 |= V_350 ;
V_331 &= ~ V_355 ;
V_331 |= V_356 ;
F_44 ( V_83 , V_331 | V_121 ) ;
F_44 ( F_228 ( V_75 ) ,
V_357 | V_358 ) ;
V_83 = F_69 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
if ( F_93 ( V_2 ) ) {
V_331 &= ~ V_335 ;
V_331 |= V_359 ;
} else {
V_331 &= ~ V_334 ;
V_331 |= V_350 ;
}
F_44 ( V_83 , V_331 | V_122 ) ;
F_123 ( V_83 ) ;
F_124 ( 150 ) ;
for ( V_146 = 0 ; V_146 < 4 ; V_146 ++ ) {
V_83 = F_67 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_355 ;
V_331 |= V_360 [ V_146 ] ;
F_44 ( V_83 , V_331 ) ;
F_123 ( V_83 ) ;
F_124 ( 500 ) ;
for ( V_354 = 0 ; V_354 < 5 ; V_354 ++ ) {
V_83 = F_226 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
F_45 ( L_60 , V_331 ) ;
if ( V_331 & V_347 ) {
F_44 ( V_83 , V_331 | V_347 ) ;
F_45 ( L_61 ) ;
break;
}
F_124 ( 50 ) ;
}
if ( V_354 < 5 )
break;
}
if ( V_146 == 4 )
F_115 ( L_62 ) ;
V_83 = F_67 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_334 ;
V_331 |= V_353 ;
if ( F_229 ( V_2 ) ) {
V_331 &= ~ V_355 ;
V_331 |= V_356 ;
}
F_44 ( V_83 , V_331 ) ;
V_83 = F_69 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
if ( F_93 ( V_2 ) ) {
V_331 &= ~ V_335 ;
V_331 |= V_361 ;
} else {
V_331 &= ~ V_334 ;
V_331 |= V_353 ;
}
F_44 ( V_83 , V_331 ) ;
F_123 ( V_83 ) ;
F_124 ( 150 ) ;
for ( V_146 = 0 ; V_146 < 4 ; V_146 ++ ) {
V_83 = F_67 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_355 ;
V_331 |= V_360 [ V_146 ] ;
F_44 ( V_83 , V_331 ) ;
F_123 ( V_83 ) ;
F_124 ( 500 ) ;
for ( V_354 = 0 ; V_354 < 5 ; V_354 ++ ) {
V_83 = F_226 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
F_45 ( L_60 , V_331 ) ;
if ( V_331 & V_346 ) {
F_44 ( V_83 , V_331 | V_346 ) ;
F_45 ( L_63 ) ;
break;
}
F_124 ( 50 ) ;
}
if ( V_354 < 5 )
break;
}
if ( V_146 == 4 )
F_115 ( L_64 ) ;
F_45 ( L_66 ) ;
}
static void F_230 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_75 = V_67 -> V_75 ;
T_1 V_83 , V_331 , V_146 , V_362 ;
V_83 = F_223 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_346 ;
V_331 &= ~ V_347 ;
F_44 ( V_83 , V_331 ) ;
F_123 ( V_83 ) ;
F_124 ( 150 ) ;
F_45 ( L_67 ,
F_4 ( F_226 ( V_75 ) ) ) ;
for ( V_362 = 0 ; V_362 < F_231 ( V_360 ) * 2 ; V_362 ++ ) {
V_83 = F_67 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ ( V_363 | V_332 ) ;
V_331 &= ~ V_121 ;
F_44 ( V_83 , V_331 ) ;
V_83 = F_69 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_363 ;
V_331 &= ~ V_335 ;
V_331 &= ~ V_122 ;
F_44 ( V_83 , V_331 ) ;
V_83 = F_67 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_348 ;
V_331 |= F_224 ( V_67 -> V_71 . V_349 ) ;
V_331 |= V_364 ;
V_331 &= ~ V_355 ;
V_331 |= V_360 [ V_362 / 2 ] ;
V_331 |= V_365 ;
F_44 ( V_83 , V_331 | V_121 ) ;
F_44 ( F_228 ( V_75 ) ,
V_357 | V_358 ) ;
V_83 = F_69 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 |= V_359 ;
V_331 |= V_365 ;
F_44 ( V_83 , V_331 | V_122 ) ;
F_123 ( V_83 ) ;
F_124 ( 1 ) ;
for ( V_146 = 0 ; V_146 < 4 ; V_146 ++ ) {
V_83 = F_226 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
F_45 ( L_60 , V_331 ) ;
if ( V_331 & V_347 ||
( F_4 ( V_83 ) & V_347 ) ) {
F_44 ( V_83 , V_331 | V_347 ) ;
F_45 ( L_68 ,
V_146 ) ;
break;
}
F_124 ( 1 ) ;
}
if ( V_146 == 4 ) {
F_45 ( L_69 , V_362 / 2 ) ;
continue;
}
V_83 = F_67 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_332 ;
V_331 |= V_366 ;
F_44 ( V_83 , V_331 ) ;
V_83 = F_69 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_335 ;
V_331 |= V_361 ;
F_44 ( V_83 , V_331 ) ;
F_123 ( V_83 ) ;
F_124 ( 2 ) ;
for ( V_146 = 0 ; V_146 < 4 ; V_146 ++ ) {
V_83 = F_226 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
F_45 ( L_60 , V_331 ) ;
if ( V_331 & V_346 ||
( F_4 ( V_83 ) & V_346 ) ) {
F_44 ( V_83 , V_331 | V_346 ) ;
F_45 ( L_70 ,
V_146 ) ;
goto V_367;
}
F_124 ( 2 ) ;
}
if ( V_146 == 4 )
F_45 ( L_71 , V_362 / 2 ) ;
}
V_367:
F_45 ( L_66 ) ;
}
static void F_232 ( struct V_67 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_75 = V_67 -> V_75 ;
T_1 V_83 , V_331 ;
V_83 = F_69 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ ( V_348 | ( 0x7 << 16 ) ) ;
V_331 |= F_224 ( V_67 -> V_71 . V_349 ) ;
V_331 |= ( F_4 ( F_50 ( V_75 ) ) & V_223 ) << 11 ;
F_44 ( V_83 , V_331 | V_124 ) ;
F_123 ( V_83 ) ;
F_124 ( 200 ) ;
V_331 = F_4 ( V_83 ) ;
F_44 ( V_83 , V_331 | V_368 ) ;
F_123 ( V_83 ) ;
F_124 ( 200 ) ;
V_83 = F_67 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
if ( ( V_331 & V_123 ) == 0 ) {
F_44 ( V_83 , V_331 | V_123 ) ;
F_123 ( V_83 ) ;
F_124 ( 100 ) ;
}
}
static void F_233 ( struct V_67 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_75 = V_67 -> V_75 ;
T_1 V_83 , V_331 ;
V_83 = F_69 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
F_44 ( V_83 , V_331 & ~ V_368 ) ;
V_83 = F_67 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
F_44 ( V_83 , V_331 & ~ V_123 ) ;
F_123 ( V_83 ) ;
F_124 ( 100 ) ;
V_83 = F_69 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
F_44 ( V_83 , V_331 & ~ V_124 ) ;
F_123 ( V_83 ) ;
F_124 ( 100 ) ;
}
static void F_234 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_75 = V_67 -> V_75 ;
T_1 V_83 , V_331 ;
V_83 = F_67 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
F_44 ( V_83 , V_331 & ~ V_121 ) ;
F_123 ( V_83 ) ;
V_83 = F_69 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ ( 0x7 << 16 ) ;
V_331 |= ( F_4 ( F_50 ( V_75 ) ) & V_223 ) << 11 ;
F_44 ( V_83 , V_331 & ~ V_122 ) ;
F_123 ( V_83 ) ;
F_124 ( 100 ) ;
if ( F_52 ( V_2 ) )
F_44 ( F_225 ( V_75 ) , V_351 ) ;
V_83 = F_67 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ V_334 ;
V_331 |= V_350 ;
F_44 ( V_83 , V_331 ) ;
V_83 = F_69 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
if ( F_93 ( V_2 ) ) {
V_331 &= ~ V_335 ;
V_331 |= V_359 ;
} else {
V_331 &= ~ V_334 ;
V_331 |= V_350 ;
}
V_331 &= ~ ( 0x07 << 16 ) ;
V_331 |= ( F_4 ( F_50 ( V_75 ) ) & V_223 ) << 11 ;
F_44 ( V_83 , V_331 ) ;
F_123 ( V_83 ) ;
F_124 ( 100 ) ;
}
bool F_235 ( struct V_1 * V_2 )
{
struct V_67 * V_21 ;
F_236 (dev, crtc) {
if ( F_208 ( & V_21 -> V_369 ) == 0 )
continue;
if ( V_21 -> V_319 )
F_41 ( V_2 , V_21 -> V_75 ) ;
return true ;
}
return false ;
}
void F_237 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_21 -> V_69 -> V_70 == NULL )
return;
F_2 ( F_238 ( & V_4 -> V_370 ) ) ;
F_2 ( F_239 ( V_4 -> V_370 ,
! F_206 ( V_21 ) ,
60 * V_371 ) == 0 ) ;
F_57 ( & V_2 -> V_289 ) ;
F_204 ( V_21 -> V_69 -> V_70 ) ;
F_59 ( & V_2 -> V_289 ) ;
}
static void F_240 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int clock = F_34 ( V_21 ) -> V_71 . V_72 . V_73 ;
T_1 V_372 , V_373 , V_374 , V_375 = 0 ;
T_1 V_331 ;
F_57 ( & V_4 -> V_108 ) ;
F_44 ( V_376 , V_377 ) ;
F_241 ( V_4 , V_378 ,
F_242 ( V_4 , V_378 , V_379 ) |
V_380 ,
V_379 ) ;
if ( clock == 20000 ) {
V_374 = 1 ;
V_372 = 0x41 ;
V_373 = 0x20 ;
} else {
T_1 V_381 = 172800 * 1000 ;
T_1 V_382 = 64 ;
T_1 V_383 , V_384 , V_385 ;
V_383 = ( V_381 / clock ) ;
V_384 = V_383 / V_382 ;
V_385 = V_383 % V_382 ;
V_374 = 0 ;
V_372 = V_384 - 2 ;
V_373 = V_385 ;
}
F_2 ( F_243 ( V_372 ) &
~ V_386 ) ;
F_2 ( F_244 ( V_375 ) &
~ V_387 ) ;
F_45 ( L_72 ,
clock ,
V_374 ,
V_372 ,
V_375 ,
V_373 ) ;
V_331 = F_242 ( V_4 , V_388 , V_379 ) ;
V_331 &= ~ V_386 ;
V_331 |= F_243 ( V_372 ) ;
V_331 &= ~ V_387 ;
V_331 |= F_245 ( V_373 ) ;
V_331 |= F_244 ( V_375 ) ;
V_331 |= V_389 ;
F_241 ( V_4 , V_388 , V_331 , V_379 ) ;
V_331 = F_242 ( V_4 , V_390 , V_379 ) ;
V_331 &= ~ F_246 ( 1 ) ;
V_331 |= F_246 ( V_374 ) ;
F_241 ( V_4 , V_390 , V_331 , V_379 ) ;
V_331 = F_242 ( V_4 , V_378 , V_379 ) ;
V_331 &= ~ V_380 ;
F_241 ( V_4 , V_378 , V_331 , V_379 ) ;
F_124 ( 24 ) ;
F_44 ( V_376 , V_391 ) ;
F_59 ( & V_4 -> V_108 ) ;
}
static void F_247 ( struct V_67 * V_21 ,
enum V_75 V_235 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_74 V_77 = V_21 -> V_71 . V_77 ;
F_44 ( F_248 ( V_235 ) ,
F_4 ( F_249 ( V_77 ) ) ) ;
F_44 ( F_250 ( V_235 ) ,
F_4 ( F_251 ( V_77 ) ) ) ;
F_44 ( F_252 ( V_235 ) ,
F_4 ( F_253 ( V_77 ) ) ) ;
F_44 ( F_254 ( V_235 ) ,
F_4 ( F_255 ( V_77 ) ) ) ;
F_44 ( F_256 ( V_235 ) ,
F_4 ( F_257 ( V_77 ) ) ) ;
F_44 ( F_258 ( V_235 ) ,
F_4 ( F_259 ( V_77 ) ) ) ;
F_44 ( F_260 ( V_235 ) ,
F_4 ( F_261 ( V_77 ) ) ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_331 ;
V_331 = F_4 ( V_343 ) ;
if ( V_331 & V_344 )
return;
F_2 ( F_4 ( F_69 ( V_137 ) ) & V_122 ) ;
F_2 ( F_4 ( F_69 ( V_342 ) ) & V_122 ) ;
V_331 |= V_344 ;
F_45 ( L_73 ) ;
F_44 ( V_343 , V_331 ) ;
F_123 ( V_343 ) ;
}
static void F_263 ( struct V_67 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_67 -> V_75 ) {
case V_128 :
break;
case V_137 :
if ( V_67 -> V_71 . V_349 > 2 )
F_2 ( F_4 ( V_343 ) & V_344 ) ;
else
F_262 ( V_2 ) ;
break;
case V_342 :
F_262 ( V_2 ) ;
break;
default:
F_136 () ;
}
}
static void F_264 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_75 = V_67 -> V_75 ;
T_1 V_83 , V_331 ;
F_94 ( V_4 , V_75 ) ;
if ( F_219 ( V_2 ) )
F_263 ( V_67 ) ;
F_44 ( F_265 ( V_75 ) ,
F_4 ( F_266 ( V_75 ) ) & V_392 ) ;
V_4 -> V_308 . V_393 ( V_21 ) ;
if ( F_93 ( V_2 ) ) {
T_1 V_394 ;
V_331 = F_4 ( V_395 ) ;
V_331 |= F_267 ( V_75 ) ;
V_394 = F_268 ( V_75 ) ;
if ( V_67 -> V_71 . V_113 == V_396 )
V_331 |= V_394 ;
else
V_331 &= ~ V_394 ;
F_44 ( V_395 , V_331 ) ;
}
F_140 ( V_67 ) ;
F_72 ( V_4 , V_75 ) ;
F_247 ( V_67 , V_75 ) ;
F_218 ( V_21 ) ;
if ( F_93 ( V_2 ) &&
( F_9 ( V_21 , V_397 ) ||
F_9 ( V_21 , V_328 ) ) ) {
T_1 V_398 = ( F_4 ( F_50 ( V_75 ) ) & V_223 ) >> 5 ;
V_83 = F_97 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ ( V_163 |
V_399 |
V_400 ) ;
V_331 |= ( V_401 |
V_402 ) ;
V_331 |= V_398 << 9 ;
if ( V_21 -> V_403 . V_314 & V_404 )
V_331 |= V_405 ;
if ( V_21 -> V_403 . V_314 & V_406 )
V_331 |= V_407 ;
switch ( F_269 ( V_21 ) ) {
case V_177 :
V_331 |= V_178 ;
break;
case V_179 :
V_331 |= V_180 ;
break;
case V_181 :
V_331 |= V_182 ;
break;
default:
F_136 () ;
}
F_44 ( V_83 , V_331 ) ;
}
F_143 ( V_4 , V_75 ) ;
}
static void F_270 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
enum V_74 V_77 = V_67 -> V_71 . V_77 ;
F_94 ( V_4 , V_231 ) ;
F_240 ( V_21 ) ;
F_247 ( V_67 , V_128 ) ;
F_147 ( V_4 , V_77 ) ;
}
static void F_271 ( struct V_67 * V_21 )
{
struct V_111 * V_115 = F_60 ( V_21 ) ;
if ( V_115 == NULL )
return;
if ( V_115 -> V_215 == 0 ) {
F_40 ( 1 , L_74 , V_115 -> V_119 ) ;
return;
}
if ( -- V_115 -> V_215 == 0 ) {
F_2 ( V_115 -> V_216 ) ;
F_2 ( V_115 -> V_68 ) ;
}
V_21 -> V_71 . V_113 = V_408 ;
}
static struct V_111 * F_272 ( struct V_67 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_112 . V_2 -> V_5 ;
struct V_111 * V_115 = F_60 ( V_21 ) ;
enum V_409 V_146 ;
if ( V_115 ) {
F_45 ( L_75 ,
V_21 -> V_112 . V_112 . V_218 , V_115 -> V_119 ) ;
F_271 ( V_21 ) ;
}
if ( F_52 ( V_4 -> V_2 ) ) {
V_146 = (enum V_409 ) V_21 -> V_75 ;
V_115 = & V_4 -> V_114 [ V_146 ] ;
F_45 ( L_76 ,
V_21 -> V_112 . V_112 . V_218 , V_115 -> V_119 ) ;
F_2 ( V_115 -> V_215 ) ;
goto V_61;
}
for ( V_146 = 0 ; V_146 < V_4 -> V_410 ; V_146 ++ ) {
V_115 = & V_4 -> V_114 [ V_146 ] ;
if ( V_115 -> V_215 == 0 )
continue;
if ( memcmp ( & V_21 -> V_71 . V_199 , & V_115 -> V_117 ,
sizeof( V_115 -> V_117 ) ) == 0 ) {
F_45 ( L_77 ,
V_21 -> V_112 . V_112 . V_218 ,
V_115 -> V_119 , V_115 -> V_215 , V_115 -> V_68 ) ;
goto V_61;
}
}
for ( V_146 = 0 ; V_146 < V_4 -> V_410 ; V_146 ++ ) {
V_115 = & V_4 -> V_114 [ V_146 ] ;
if ( V_115 -> V_215 == 0 ) {
F_45 ( L_78 ,
V_21 -> V_112 . V_112 . V_218 , V_115 -> V_119 ) ;
goto V_61;
}
}
return NULL ;
V_61:
if ( V_115 -> V_215 == 0 )
V_115 -> V_117 = V_21 -> V_71 . V_199 ;
V_21 -> V_71 . V_113 = V_146 ;
F_63 ( L_79 , V_115 -> V_119 ,
F_73 ( V_21 -> V_75 ) ) ;
V_115 -> V_215 ++ ;
return V_115 ;
}
static void F_273 ( struct V_1 * V_2 , int V_75 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_411 = F_47 ( V_75 ) ;
T_1 V_331 ;
V_331 = F_4 ( V_411 ) ;
F_124 ( 500 ) ;
if ( F_38 ( F_4 ( V_411 ) != V_331 , 5 ) ) {
if ( F_38 ( F_4 ( V_411 ) != V_331 , 5 ) )
F_115 ( L_80 , F_73 ( V_75 ) ) ;
}
}
static void F_274 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_75 = V_21 -> V_75 ;
if ( V_21 -> V_71 . V_327 . V_103 ) {
if ( F_219 ( V_2 ) || F_195 ( V_2 ) )
F_44 ( F_213 ( V_75 ) , V_412 | V_413 |
F_275 ( V_75 ) ) ;
else
F_44 ( F_213 ( V_75 ) , V_412 | V_413 ) ;
F_44 ( F_214 ( V_75 ) , V_21 -> V_71 . V_327 . V_414 ) ;
F_44 ( F_215 ( V_75 ) , V_21 -> V_71 . V_327 . V_284 ) ;
}
}
static void F_276 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
enum V_75 V_75 = F_34 ( V_21 ) -> V_75 ;
struct V_415 * V_144 ;
struct V_416 * V_416 ;
F_277 (plane, &dev->mode_config.plane_list) {
V_416 = F_278 ( V_144 ) ;
if ( V_416 -> V_75 == V_75 )
F_279 ( & V_416 -> V_112 ) ;
}
}
static void F_280 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
enum V_75 V_75 = F_34 ( V_21 ) -> V_75 ;
struct V_415 * V_144 ;
struct V_416 * V_416 ;
F_277 (plane, &dev->mode_config.plane_list) {
V_416 = F_278 ( V_144 ) ;
if ( V_416 -> V_75 == V_75 )
F_281 ( & V_416 -> V_112 ) ;
}
}
void F_282 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_21 -> V_71 . V_417 )
return;
F_41 ( V_2 , V_21 -> V_75 ) ;
F_283 ( V_4 , V_21 -> V_144 ) ;
if ( F_163 ( V_2 ) ) {
F_57 ( & V_4 -> V_418 . V_419 ) ;
F_2 ( F_284 ( V_4 , V_420 , 0xc0000000 ) ) ;
F_59 ( & V_4 -> V_418 . V_419 ) ;
} else {
F_44 ( V_421 , V_422 ) ;
if ( F_38 ( F_39 ( V_421 ) & V_422 , 50 ) )
F_115 ( L_81 ) ;
}
}
void F_285 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_21 -> V_71 . V_417 )
return;
F_283 ( V_4 , V_21 -> V_144 ) ;
if ( F_163 ( V_2 ) ) {
F_57 ( & V_4 -> V_418 . V_419 ) ;
F_2 ( F_284 ( V_4 , V_420 , 0 ) ) ;
F_59 ( & V_4 -> V_418 . V_419 ) ;
if ( F_38 ( ( F_4 ( V_421 ) & V_422 ) == 0 , 42 ) )
F_115 ( L_82 ) ;
} else {
F_44 ( V_421 , 0 ) ;
F_123 ( V_421 ) ;
}
F_41 ( V_2 , V_21 -> V_75 ) ;
}
static void F_286 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
enum V_75 V_75 = V_67 -> V_75 ;
int V_423 = F_287 ( V_75 ) ;
int V_146 ;
bool V_424 = false ;
if ( ! V_21 -> V_103 || ! V_67 -> V_68 )
return;
if ( ! F_3 ( V_4 -> V_2 ) ) {
if ( F_9 ( V_21 , V_236 ) )
F_154 ( V_4 ) ;
else
F_155 ( V_4 , V_75 ) ;
}
if ( F_3 ( V_2 ) )
V_423 = F_288 ( V_75 ) ;
if ( F_195 ( V_2 ) && V_67 -> V_71 . V_417 &&
( ( F_4 ( F_289 ( V_75 ) ) & V_425 ) ==
V_426 ) ) {
F_285 ( V_67 ) ;
V_424 = true ;
}
for ( V_146 = 0 ; V_146 < 256 ; V_146 ++ ) {
F_44 ( V_423 + 4 * V_146 ,
( V_67 -> V_427 [ V_146 ] << 16 ) |
( V_67 -> V_428 [ V_146 ] << 8 ) |
V_67 -> V_429 [ V_146 ] ) ;
}
if ( V_424 )
F_282 ( V_67 ) ;
}
static void F_290 ( struct V_67 * V_67 , bool V_219 )
{
if ( ! V_219 && V_67 -> V_430 ) {
struct V_1 * V_2 = V_67 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_57 ( & V_2 -> V_289 ) ;
V_4 -> V_254 . V_255 = false ;
( void ) F_291 ( V_67 -> V_430 ) ;
V_4 -> V_254 . V_255 = true ;
F_59 ( & V_2 -> V_289 ) ;
}
}
static void
F_292 ( struct V_3 * V_4 , enum V_75 V_75 )
{
T_1 V_431 = F_4 ( F_77 ( V_75 ) ) ;
if ( ( V_431 & V_140 ) == 0 ) {
T_1 V_432 = F_4 ( V_433 ) ;
F_44 ( V_433 , V_432 & ~ V_434 ) ;
F_44 ( F_77 ( V_75 ) , V_435 ) ;
F_41 ( V_4 -> V_2 , V_75 ) ;
F_44 ( F_77 ( V_75 ) , V_431 ) ;
F_44 ( F_293 ( V_75 ) , F_4 ( F_293 ( V_75 ) ) ) ;
F_44 ( V_433 , V_432 ) ;
}
}
static void F_294 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_75 = V_67 -> V_75 ;
int V_144 = V_67 -> V_144 ;
F_161 ( V_4 , V_144 , V_75 ) ;
F_276 ( V_21 ) ;
if ( F_15 ( V_2 ) )
F_292 ( V_4 , V_75 ) ;
F_295 ( V_21 , true ) ;
F_290 ( V_67 , true ) ;
F_282 ( V_67 ) ;
F_57 ( & V_2 -> V_289 ) ;
F_216 ( V_2 ) ;
F_217 ( V_2 ) ;
F_59 ( & V_2 -> V_289 ) ;
}
static void F_296 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_75 = V_67 -> V_75 ;
int V_144 = V_67 -> V_144 ;
F_237 ( V_21 ) ;
F_297 ( V_21 ) ;
if ( V_4 -> V_436 . V_144 == V_144 )
F_298 ( V_2 ) ;
F_285 ( V_67 ) ;
F_290 ( V_67 , false ) ;
F_295 ( V_21 , false ) ;
F_280 ( V_21 ) ;
F_164 ( V_4 , V_144 , V_75 ) ;
}
static void F_299 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
struct V_22 * V_23 ;
int V_75 = V_67 -> V_75 ;
enum V_144 V_144 = V_67 -> V_144 ;
F_2 ( ! V_21 -> V_103 ) ;
if ( V_67 -> V_68 )
return;
if ( V_67 -> V_71 . V_237 )
F_138 ( V_67 ) ;
if ( V_67 -> V_71 . V_437 )
F_300 ( V_67 ) ;
F_301 ( V_67 ) ;
if ( V_67 -> V_71 . V_237 ) {
F_302 ( V_67 ,
& V_67 -> V_71 . V_438 ) ;
}
F_303 ( V_21 ) ;
F_44 ( F_82 ( V_144 ) , V_439 ) ;
F_123 ( F_82 ( V_144 ) ) ;
V_4 -> V_308 . V_310 ( V_21 , V_21 -> V_69 -> V_70 ,
V_21 -> V_258 , V_21 -> V_259 ) ;
V_67 -> V_68 = true ;
F_304 ( V_2 , V_75 , true ) ;
F_305 ( V_2 , V_75 , true ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_440 )
V_23 -> V_440 ( V_23 ) ;
if ( V_67 -> V_71 . V_237 ) {
F_232 ( V_67 ) ;
} else {
F_149 ( V_4 , V_75 ) ;
F_150 ( V_4 , V_75 ) ;
}
F_274 ( V_67 ) ;
F_286 ( V_21 ) ;
F_306 ( V_21 ) ;
F_152 ( V_67 ) ;
if ( V_67 -> V_71 . V_237 )
F_264 ( V_21 ) ;
F_10 (dev, crtc, encoder)
V_23 -> V_219 ( V_23 ) ;
if ( F_93 ( V_2 ) )
F_273 ( V_2 , V_67 -> V_75 ) ;
F_294 ( V_21 ) ;
F_307 ( V_21 ) ;
}
static bool F_308 ( struct V_67 * V_21 )
{
return F_309 ( V_21 -> V_112 . V_2 ) && V_21 -> V_75 == V_128 ;
}
static void F_310 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_67 * V_441 , * V_442 = NULL ;
F_236 (dev, crtc_it) {
if ( ! V_441 -> V_68 || V_441 == V_21 )
continue;
if ( V_442 )
return;
V_442 = V_441 ;
}
if ( ! V_442 )
return;
F_41 ( V_2 , V_442 -> V_75 ) ;
F_41 ( V_2 , V_442 -> V_75 ) ;
}
static void F_311 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
struct V_22 * V_23 ;
int V_75 = V_67 -> V_75 ;
enum V_144 V_144 = V_67 -> V_144 ;
F_2 ( ! V_21 -> V_103 ) ;
if ( V_67 -> V_68 )
return;
if ( V_67 -> V_71 . V_437 )
F_300 ( V_67 ) ;
F_301 ( V_67 ) ;
if ( V_67 -> V_71 . V_237 ) {
F_302 ( V_67 ,
& V_67 -> V_71 . V_438 ) ;
}
F_312 ( V_21 ) ;
F_313 ( V_21 ) ;
F_44 ( F_82 ( V_144 ) , V_439 | V_443 ) ;
F_123 ( F_82 ( V_144 ) ) ;
V_4 -> V_308 . V_310 ( V_21 , V_21 -> V_69 -> V_70 ,
V_21 -> V_258 , V_21 -> V_259 ) ;
V_67 -> V_68 = true ;
F_304 ( V_2 , V_75 , true ) ;
if ( V_67 -> V_71 . V_237 )
F_305 ( V_2 , V_231 , true ) ;
if ( V_67 -> V_71 . V_237 )
V_4 -> V_308 . V_393 ( V_21 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_440 )
V_23 -> V_440 ( V_23 ) ;
F_314 ( V_67 ) ;
F_274 ( V_67 ) ;
F_286 ( V_21 ) ;
F_315 ( V_21 ) ;
F_316 ( V_21 ) ;
F_306 ( V_21 ) ;
F_152 ( V_67 ) ;
if ( V_67 -> V_71 . V_237 )
F_270 ( V_21 ) ;
F_10 (dev, crtc, encoder) {
V_23 -> V_219 ( V_23 ) ;
F_317 ( V_23 , true ) ;
}
F_310 ( V_67 ) ;
F_294 ( V_21 ) ;
F_307 ( V_21 ) ;
}
static void F_318 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_75 = V_21 -> V_75 ;
if ( V_21 -> V_71 . V_327 . V_103 ) {
F_44 ( F_213 ( V_75 ) , 0 ) ;
F_44 ( F_214 ( V_75 ) , 0 ) ;
F_44 ( F_215 ( V_75 ) , 0 ) ;
}
}
static void F_319 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
struct V_22 * V_23 ;
int V_75 = V_67 -> V_75 ;
T_1 V_83 , V_331 ;
if ( ! V_67 -> V_68 )
return;
F_296 ( V_21 ) ;
F_10 (dev, crtc, encoder)
V_23 -> V_220 ( V_23 ) ;
if ( V_67 -> V_71 . V_237 )
F_305 ( V_2 , V_75 , false ) ;
F_157 ( V_4 , V_75 ) ;
F_318 ( V_67 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_444 )
V_23 -> V_444 ( V_23 ) ;
if ( V_67 -> V_71 . V_237 ) {
F_234 ( V_21 ) ;
F_148 ( V_4 , V_75 ) ;
F_305 ( V_2 , V_75 , true ) ;
if ( F_93 ( V_2 ) ) {
V_83 = F_97 ( V_75 ) ;
V_331 = F_4 ( V_83 ) ;
V_331 &= ~ ( V_401 |
V_163 ) ;
V_331 |= V_445 ;
F_44 ( V_83 , V_331 ) ;
V_331 = F_4 ( V_395 ) ;
V_331 &= ~ ( F_267 ( V_75 ) | F_268 ( V_75 ) ) ;
F_44 ( V_395 , V_331 ) ;
}
F_142 ( V_67 ) ;
F_233 ( V_67 ) ;
}
V_67 -> V_68 = false ;
F_306 ( V_21 ) ;
F_57 ( & V_2 -> V_289 ) ;
F_216 ( V_2 ) ;
F_217 ( V_2 ) ;
F_59 ( & V_2 -> V_289 ) ;
}
static void F_320 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
struct V_22 * V_23 ;
int V_75 = V_67 -> V_75 ;
enum V_74 V_77 = V_67 -> V_71 . V_77 ;
if ( ! V_67 -> V_68 )
return;
F_296 ( V_21 ) ;
F_10 (dev, crtc, encoder) {
F_317 ( V_23 , false ) ;
V_23 -> V_220 ( V_23 ) ;
}
if ( V_67 -> V_71 . V_237 )
F_305 ( V_2 , V_231 , false ) ;
F_157 ( V_4 , V_75 ) ;
F_321 ( V_4 , V_77 ) ;
F_318 ( V_67 ) ;
F_322 ( V_67 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_444 )
V_23 -> V_444 ( V_23 ) ;
if ( V_67 -> V_71 . V_237 ) {
F_151 ( V_4 ) ;
F_305 ( V_2 , V_231 , true ) ;
F_323 ( V_21 ) ;
}
V_67 -> V_68 = false ;
F_306 ( V_21 ) ;
F_57 ( & V_2 -> V_289 ) ;
F_216 ( V_2 ) ;
F_217 ( V_2 ) ;
F_59 ( & V_2 -> V_289 ) ;
}
static void F_324 ( struct V_20 * V_21 )
{
struct V_67 * V_67 = F_34 ( V_21 ) ;
F_271 ( V_67 ) ;
}
static void F_325 ( struct V_20 * V_21 )
{
F_326 ( V_21 ) ;
}
static void F_327 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_446 * V_447 = & V_21 -> V_71 ;
if ( ! V_21 -> V_71 . V_448 . V_449 )
return;
F_2 ( F_4 ( V_450 ) & V_451 ) ;
F_119 ( V_4 , V_21 -> V_75 ) ;
F_44 ( V_452 , V_447 -> V_448 . V_453 ) ;
F_44 ( V_450 , V_447 -> V_448 . V_449 ) ;
F_44 ( F_328 ( V_21 -> V_75 ) , 0 ) ;
}
enum V_454
F_329 ( struct V_22 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_112 . V_2 ;
struct V_90 * V_455 ;
switch ( V_22 -> type ) {
case V_456 :
F_330 ( ! F_65 ( V_2 ) ) ;
case V_397 :
case V_33 :
case V_328 :
V_455 = F_331 ( & V_22 -> V_112 ) ;
switch ( V_455 -> V_91 ) {
case V_457 :
return V_458 ;
case V_93 :
return V_459 ;
case V_95 :
return V_460 ;
case V_97 :
return V_461 ;
default:
F_330 ( 1 ) ;
return V_462 ;
}
case V_34 :
return V_463 ;
case V_236 :
return V_464 ;
default:
return V_462 ;
}
}
static unsigned long F_332 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_22 * V_22 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
enum V_75 V_75 = V_67 -> V_75 ;
bool V_465 = V_67 -> V_71 . V_327 . V_103 ;
unsigned long V_466 ;
enum V_74 V_74 ;
V_74 = F_35 ( V_2 -> V_5 , V_75 ) ;
V_466 = F_333 ( F_334 ( V_75 ) ) ;
V_466 |= F_333 ( F_80 ( V_74 ) ) ;
if ( V_465 )
V_466 |= F_333 ( F_335 ( V_75 ) ) ;
F_10 (dev, crtc, intel_encoder)
V_466 |= F_333 ( F_329 ( V_22 ) ) ;
return V_466 ;
}
void F_336 ( struct V_3 * V_4 ,
bool V_219 )
{
if ( V_4 -> V_467 . V_468 == V_219 )
return;
if ( V_219 )
F_337 ( V_4 , V_469 ) ;
else
F_338 ( V_4 , V_469 ) ;
V_4 -> V_467 . V_468 = V_219 ;
}
static void F_339 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_470 [ V_471 ] = { 0 , } ;
struct V_67 * V_21 ;
F_236 (dev, crtc) {
enum V_454 V_472 ;
if ( ! V_21 -> V_112 . V_103 )
continue;
V_470 [ V_21 -> V_75 ] = F_332 ( & V_21 -> V_112 ) ;
F_340 (domain, pipe_domains[crtc->pipe])
F_337 ( V_4 , V_472 ) ;
}
F_236 (dev, crtc) {
enum V_454 V_472 ;
F_340 (domain, crtc->enabled_power_domains)
F_338 ( V_4 , V_472 ) ;
V_21 -> V_473 = V_470 [ V_21 -> V_75 ] ;
}
F_336 ( V_4 , false ) ;
}
int F_341 ( struct V_3 * V_4 )
{
int V_474 , V_475 [] = { 800 , 1600 , 2000 , 2400 } ;
F_57 ( & V_4 -> V_108 ) ;
V_474 = F_58 ( V_4 , V_476 ) &
V_477 ;
F_59 ( & V_4 -> V_108 ) ;
return V_475 [ V_474 ] ;
}
static void F_342 ( struct V_1 * V_2 , int V_478 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_105 , V_479 ;
F_2 ( F_343 ( V_4 ) != V_4 -> V_480 ) ;
V_4 -> V_480 = V_478 ;
if ( V_478 >= 320 )
V_479 = 2 ;
else if ( V_478 == 266 )
V_479 = 1 ;
else
V_479 = 0 ;
F_57 ( & V_4 -> V_418 . V_419 ) ;
V_105 = F_344 ( V_4 , V_481 ) ;
V_105 &= ~ V_482 ;
V_105 |= ( V_479 << V_483 ) ;
F_345 ( V_4 , V_481 , V_105 ) ;
if ( F_38 ( ( F_344 ( V_4 , V_481 ) &
V_484 ) == ( V_479 << V_485 ) ,
50 ) ) {
F_115 ( L_83 ) ;
}
F_59 ( & V_4 -> V_418 . V_419 ) ;
if ( V_478 == 400 ) {
T_1 V_486 , V_18 ;
V_18 = F_341 ( V_4 ) ;
V_486 = ( ( V_18 << 1 ) / V_478 ) - 1 ;
F_57 ( & V_4 -> V_108 ) ;
V_105 = F_58 ( V_4 , V_487 ) ;
V_105 &= ~ 0xf ;
V_105 |= V_486 ;
F_346 ( V_4 , V_487 , V_105 ) ;
F_59 ( & V_4 -> V_108 ) ;
}
F_57 ( & V_4 -> V_108 ) ;
V_105 = F_347 ( V_4 , V_488 ) ;
V_105 &= ~ 0x7f ;
if ( V_478 == 400 )
V_105 |= 4500 / 250 ;
else
V_105 |= 3000 / 250 ;
F_348 ( V_4 , V_488 , V_105 ) ;
F_59 ( & V_4 -> V_108 ) ;
F_349 ( V_2 ) ;
}
int F_343 ( struct V_3 * V_4 )
{
int V_489 , V_18 ;
int V_486 ;
V_18 = F_341 ( V_4 ) ;
F_57 ( & V_4 -> V_108 ) ;
V_486 = F_58 ( V_4 , V_487 ) ;
F_59 ( & V_4 -> V_108 ) ;
V_486 &= 0xf ;
V_489 = ( V_18 << 1 ) / ( V_486 + 1 ) ;
return V_489 ;
}
static int F_350 ( struct V_3 * V_4 ,
int V_490 )
{
if ( V_490 > 288000 ) {
return 400 ;
} else if ( V_490 > 240000 ) {
return 320 ;
} else
return 266 ;
}
static int F_351 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_67 * V_67 ;
int V_490 = 0 ;
F_236 (dev, intel_crtc) {
if ( V_67 -> V_491 )
V_490 = V_51 ( V_490 ,
V_67 -> V_492 -> V_72 . V_73 ) ;
}
return V_490 ;
}
static void F_352 ( struct V_1 * V_2 ,
unsigned * V_493 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 ;
int V_490 = F_351 ( V_4 ) ;
if ( F_350 ( V_4 , V_490 ) ==
V_4 -> V_480 )
return;
F_236 (dev, intel_crtc)
if ( V_67 -> V_112 . V_103 )
* V_493 |= ( 1 << V_67 -> V_75 ) ;
}
static void F_353 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_490 = F_351 ( V_4 ) ;
int V_494 = F_350 ( V_4 , V_490 ) ;
if ( V_494 != V_4 -> V_480 )
F_342 ( V_2 , V_494 ) ;
F_339 ( V_2 ) ;
}
static void F_354 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
struct V_22 * V_23 ;
int V_75 = V_67 -> V_75 ;
int V_144 = V_67 -> V_144 ;
bool V_495 ;
T_1 V_296 ;
F_2 ( ! V_21 -> V_103 ) ;
if ( V_67 -> V_68 )
return;
V_495 = F_9 ( V_21 , V_236 ) ;
if ( ! V_495 && ! F_17 ( V_2 ) )
F_355 ( V_67 ) ;
V_296 = V_439 ;
if ( V_67 -> V_71 . V_437 )
F_300 ( V_67 ) ;
F_301 ( V_67 ) ;
F_44 ( F_356 ( V_144 ) ,
( ( V_67 -> V_71 . V_330 - 1 ) << 16 ) |
( V_67 -> V_71 . V_329 - 1 ) ) ;
F_44 ( F_357 ( V_144 ) , 0 ) ;
F_358 ( V_67 ) ;
F_44 ( F_82 ( V_144 ) , V_296 ) ;
F_123 ( F_82 ( V_144 ) ) ;
V_4 -> V_308 . V_310 ( V_21 , V_21 -> V_69 -> V_70 ,
V_21 -> V_258 , V_21 -> V_259 ) ;
V_67 -> V_68 = true ;
F_304 ( V_2 , V_75 , true ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_496 )
V_23 -> V_496 ( V_23 ) ;
if ( ! V_495 ) {
if ( F_17 ( V_2 ) )
F_126 ( V_67 ) ;
else
F_118 ( V_67 ) ;
}
F_10 (dev, crtc, encoder)
if ( V_23 -> V_440 )
V_23 -> V_440 ( V_23 ) ;
F_327 ( V_67 ) ;
F_286 ( V_21 ) ;
F_306 ( V_21 ) ;
F_152 ( V_67 ) ;
F_10 (dev, crtc, encoder)
V_23 -> V_219 ( V_23 ) ;
F_294 ( V_21 ) ;
F_307 ( V_21 ) ;
F_359 ( V_2 ) ;
}
static void F_360 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_44 ( F_361 ( V_21 -> V_75 ) , V_21 -> V_71 . V_199 . V_497 ) ;
F_44 ( F_362 ( V_21 -> V_75 ) , V_21 -> V_71 . V_199 . V_498 ) ;
}
static void F_363 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
struct V_22 * V_23 ;
int V_75 = V_67 -> V_75 ;
int V_144 = V_67 -> V_144 ;
T_1 V_296 ;
F_2 ( ! V_21 -> V_103 ) ;
if ( V_67 -> V_68 )
return;
F_360 ( V_67 ) ;
V_296 = V_439 ;
if ( V_75 == 0 )
V_296 &= ~ V_148 ;
else
V_296 |= V_499 ;
if ( V_67 -> V_71 . V_437 )
F_300 ( V_67 ) ;
F_301 ( V_67 ) ;
F_44 ( F_356 ( V_144 ) ,
( ( V_67 -> V_71 . V_330 - 1 ) << 16 ) |
( V_67 -> V_71 . V_329 - 1 ) ) ;
F_44 ( F_357 ( V_144 ) , 0 ) ;
F_358 ( V_67 ) ;
F_44 ( F_82 ( V_144 ) , V_296 ) ;
F_123 ( F_82 ( V_144 ) ) ;
V_4 -> V_308 . V_310 ( V_21 , V_21 -> V_69 -> V_70 ,
V_21 -> V_258 , V_21 -> V_259 ) ;
V_67 -> V_68 = true ;
if ( ! F_19 ( V_2 ) )
F_304 ( V_2 , V_75 , true ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_440 )
V_23 -> V_440 ( V_23 ) ;
F_131 ( V_67 ) ;
F_327 ( V_67 ) ;
F_286 ( V_21 ) ;
F_306 ( V_21 ) ;
F_152 ( V_67 ) ;
F_10 (dev, crtc, encoder)
V_23 -> V_219 ( V_23 ) ;
F_294 ( V_21 ) ;
if ( F_19 ( V_2 ) )
F_304 ( V_2 , V_75 , true ) ;
F_307 ( V_21 ) ;
F_359 ( V_2 ) ;
}
static void F_364 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_21 -> V_71 . V_448 . V_449 )
return;
F_119 ( V_4 , V_21 -> V_75 ) ;
F_63 ( L_84 ,
F_4 ( V_450 ) ) ;
F_44 ( V_450 , 0 ) ;
}
static void F_365 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
struct V_22 * V_23 ;
int V_75 = V_67 -> V_75 ;
if ( ! V_67 -> V_68 )
return;
if ( F_19 ( V_2 ) )
F_304 ( V_2 , V_75 , false ) ;
F_296 ( V_21 ) ;
F_10 (dev, crtc, encoder)
V_23 -> V_220 ( V_23 ) ;
if ( F_19 ( V_2 ) )
F_41 ( V_2 , V_75 ) ;
F_157 ( V_4 , V_75 ) ;
F_364 ( V_67 ) ;
F_10 (dev, crtc, encoder)
if ( V_23 -> V_444 )
V_23 -> V_444 ( V_23 ) ;
if ( ! F_9 ( V_21 , V_236 ) ) {
if ( F_17 ( V_2 ) )
F_134 ( V_4 , V_75 ) ;
else if ( F_18 ( V_2 ) )
F_133 ( V_4 , V_75 ) ;
else
F_132 ( V_4 , V_75 ) ;
}
if ( ! F_19 ( V_2 ) )
F_304 ( V_2 , V_75 , false ) ;
V_67 -> V_68 = false ;
F_306 ( V_21 ) ;
F_57 ( & V_2 -> V_289 ) ;
F_216 ( V_2 ) ;
F_217 ( V_2 ) ;
F_59 ( & V_2 -> V_289 ) ;
}
static void F_366 ( struct V_20 * V_21 )
{
}
static void F_367 ( struct V_20 * V_21 ,
bool V_103 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_500 * V_501 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_75 = V_67 -> V_75 ;
if ( ! V_2 -> V_69 -> V_502 )
return;
V_501 = V_2 -> V_69 -> V_502 -> V_503 ;
if ( ! V_501 -> V_504 )
return;
switch ( V_75 ) {
case 0 :
V_501 -> V_504 -> V_505 = V_103 ? V_21 -> V_403 . V_506 : 0 ;
V_501 -> V_504 -> V_507 = V_103 ? V_21 -> V_403 . V_508 : 0 ;
break;
case 1 :
V_501 -> V_504 -> V_509 = V_103 ? V_21 -> V_403 . V_506 : 0 ;
V_501 -> V_504 -> V_510 = V_103 ? V_21 -> V_403 . V_508 : 0 ;
break;
default:
F_115 ( L_85 , F_73 ( V_75 ) ) ;
break;
}
}
void F_368 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_22 ;
bool V_219 = false ;
F_10 (dev, crtc, intel_encoder)
V_219 |= V_22 -> V_511 ;
if ( V_219 )
V_4 -> V_308 . V_512 ( V_21 ) ;
else
V_4 -> V_308 . V_513 ( V_21 ) ;
F_367 ( V_21 , V_219 ) ;
}
static void F_369 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_514 * V_515 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( ! V_21 -> V_103 ) ;
V_4 -> V_308 . V_513 ( V_21 ) ;
F_367 ( V_21 , false ) ;
V_4 -> V_308 . V_516 ( V_21 ) ;
F_370 ( V_2 -> V_5 , F_34 ( V_21 ) -> V_144 ) ;
F_153 ( V_4 , F_34 ( V_21 ) -> V_75 ) ;
F_119 ( V_2 -> V_5 , F_34 ( V_21 ) -> V_75 ) ;
if ( V_21 -> V_69 -> V_70 ) {
F_57 ( & V_2 -> V_289 ) ;
F_176 ( F_183 ( V_21 -> V_69 -> V_70 ) -> V_244 ) ;
F_59 ( & V_2 -> V_289 ) ;
V_21 -> V_69 -> V_70 = NULL ;
}
F_371 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_515 -> V_23 || ! V_515 -> V_23 -> V_21 )
continue;
if ( V_515 -> V_23 -> V_21 != V_21 )
continue;
V_515 -> V_517 = V_518 ;
F_372 ( V_515 -> V_23 ) -> V_511 = false ;
}
}
void F_373 ( struct V_519 * V_23 )
{
struct V_22 * V_22 = F_372 ( V_23 ) ;
F_374 ( V_23 ) ;
F_186 ( V_22 ) ;
}
static void F_375 ( struct V_22 * V_23 , int V_403 )
{
if ( V_403 == V_520 ) {
V_23 -> V_511 = true ;
F_368 ( V_23 -> V_112 . V_21 ) ;
} else {
V_23 -> V_511 = false ;
F_368 ( V_23 -> V_112 . V_21 ) ;
}
}
static void F_376 ( struct V_521 * V_515 )
{
if ( V_515 -> V_118 ( V_515 ) ) {
struct V_22 * V_23 = V_515 -> V_23 ;
struct V_20 * V_21 ;
bool V_522 ;
enum V_75 V_75 ;
F_45 ( L_86 ,
V_515 -> V_112 . V_112 . V_218 ,
V_515 -> V_112 . V_119 ) ;
F_40 ( V_515 -> V_112 . V_517 == V_518 ,
L_87 ) ;
F_40 ( V_515 -> V_112 . V_23 != & V_23 -> V_112 ,
L_88 ) ;
F_40 ( ! V_23 -> V_511 ,
L_89 ) ;
V_522 = V_23 -> V_118 ( V_23 , & V_75 ) ;
F_40 ( ! V_522 , L_90 ) ;
if ( F_2 ( ! V_23 -> V_112 . V_21 ) )
return;
V_21 = V_23 -> V_112 . V_21 ;
F_40 ( ! V_21 -> V_103 , L_91 ) ;
F_40 ( ! F_34 ( V_21 ) -> V_68 , L_92 ) ;
F_40 ( V_75 != F_34 ( V_21 ) -> V_75 ,
L_93 ) ;
}
}
void F_377 ( struct V_514 * V_515 , int V_403 )
{
if ( V_403 != V_520 )
V_403 = V_518 ;
if ( V_403 == V_515 -> V_517 )
return;
V_515 -> V_517 = V_403 ;
if ( V_515 -> V_23 )
F_375 ( F_372 ( V_515 -> V_23 ) , V_403 ) ;
F_378 ( V_515 -> V_2 ) ;
}
bool F_379 ( struct V_521 * V_515 )
{
enum V_75 V_75 = 0 ;
struct V_22 * V_23 = V_515 -> V_23 ;
return V_23 -> V_118 ( V_23 , & V_75 ) ;
}
static bool F_380 ( struct V_1 * V_2 , enum V_75 V_75 ,
struct V_446 * V_447 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_340 =
F_34 ( V_4 -> V_76 [ V_137 ] ) ;
F_45 ( L_94 ,
F_73 ( V_75 ) , V_447 -> V_349 ) ;
if ( V_447 -> V_349 > 4 ) {
F_45 ( L_95 ,
F_73 ( V_75 ) , V_447 -> V_349 ) ;
return false ;
}
if ( F_195 ( V_2 ) || F_163 ( V_2 ) ) {
if ( V_447 -> V_349 > 2 ) {
F_45 ( L_96 ,
V_447 -> V_349 ) ;
return false ;
} else {
return true ;
}
}
if ( F_43 ( V_2 ) -> V_321 == 2 )
return true ;
switch ( V_75 ) {
case V_128 :
return true ;
case V_137 :
if ( V_4 -> V_76 [ V_342 ] -> V_103 &&
V_447 -> V_349 > 2 ) {
F_45 ( L_97 ,
F_73 ( V_75 ) , V_447 -> V_349 ) ;
return false ;
}
return true ;
case V_342 :
if ( ! F_220 ( V_340 ) ||
V_340 -> V_71 . V_349 <= 2 ) {
if ( V_447 -> V_349 > 2 ) {
F_45 ( L_97 ,
F_73 ( V_75 ) , V_447 -> V_349 ) ;
return false ;
}
} else {
F_45 ( L_98 ) ;
return false ;
}
return true ;
default:
F_136 () ;
}
}
static int F_381 ( struct V_67 * V_67 ,
struct V_446 * V_447 )
{
struct V_1 * V_2 = V_67 -> V_112 . V_2 ;
struct V_324 * V_72 = & V_447 -> V_72 ;
int V_523 , V_524 , V_525 ;
bool V_526 , V_527 = false ;
V_354:
V_524 = F_5 ( V_2 ) * F_382 ( 100 ) / F_383 ( 1 ) / 10 ;
V_525 = V_72 -> V_73 ;
V_523 = F_384 ( V_525 , V_524 ,
V_447 -> V_528 ) ;
V_447 -> V_349 = V_523 ;
F_385 ( V_447 -> V_528 , V_523 , V_525 ,
V_524 , & V_447 -> V_438 ) ;
V_526 = F_380 ( V_67 -> V_112 . V_2 ,
V_67 -> V_75 , V_447 ) ;
if ( ! V_526 && V_447 -> V_528 > 6 * 3 ) {
V_447 -> V_528 -= 2 * 3 ;
F_45 ( L_99 ,
V_447 -> V_528 ) ;
V_527 = true ;
V_447 -> V_529 = true ;
goto V_354;
}
if ( V_527 )
return V_530 ;
return V_526 ? 0 : - V_253 ;
}
static void F_386 ( struct V_67 * V_21 ,
struct V_446 * V_447 )
{
V_447 -> V_417 = V_322 . V_531 &&
F_308 ( V_21 ) &&
V_447 -> V_528 <= 24 ;
}
static int F_387 ( struct V_67 * V_21 ,
struct V_446 * V_447 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_324 * V_72 = & V_447 -> V_72 ;
if ( F_43 ( V_2 ) -> V_81 < 4 ) {
struct V_3 * V_4 = V_2 -> V_5 ;
int V_532 =
V_4 -> V_308 . V_533 ( V_2 ) ;
if ( ( V_21 -> V_75 == V_128 || F_388 ( V_2 ) ) &&
V_72 -> V_73 > V_532 * 9 / 10 ) {
V_532 *= 2 ;
V_447 -> V_534 = true ;
}
if ( V_72 -> V_73 > V_532 * 9 / 10 )
return - V_253 ;
}
if ( ( F_9 ( & V_21 -> V_112 , V_25 ) &&
F_12 ( V_2 ) ) || V_447 -> V_534 )
V_447 -> V_329 &= ~ 1 ;
if ( ( F_43 ( V_2 ) -> V_81 > 4 || F_15 ( V_2 ) ) &&
V_72 -> V_535 == V_72 -> V_506 )
return - V_253 ;
if ( ( F_15 ( V_2 ) || F_18 ( V_2 ) ) && V_447 -> V_528 > 10 * 3 ) {
V_447 -> V_528 = 10 * 3 ;
} else if ( F_43 ( V_2 ) -> V_81 <= 4 && V_447 -> V_528 > 8 * 3 ) {
V_447 -> V_528 = 8 * 3 ;
}
if ( F_309 ( V_2 ) )
F_386 ( V_21 , V_447 ) ;
if ( F_52 ( V_2 ) || F_93 ( V_2 ) )
V_447 -> V_113 = V_21 -> V_71 . V_113 ;
if ( V_447 -> V_237 )
return F_381 ( V_21 , V_447 ) ;
return 0 ;
}
static int F_389 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_390 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_391 ( struct V_1 * V_2 )
{
return 333000 ;
}
static int F_392 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_393 ( struct V_1 * V_2 )
{
T_5 V_536 = 0 ;
F_394 ( V_2 -> V_537 , V_538 , & V_536 ) ;
switch ( V_536 & V_539 ) {
case V_540 :
return 267000 ;
case V_541 :
return 333000 ;
case V_542 :
return 444000 ;
case V_543 :
return 200000 ;
default:
F_115 ( L_100 , V_536 ) ;
case V_544 :
return 133000 ;
case V_545 :
return 167000 ;
}
}
static int F_395 ( struct V_1 * V_2 )
{
T_5 V_536 = 0 ;
F_394 ( V_2 -> V_537 , V_538 , & V_536 ) ;
if ( V_536 & V_546 )
return 133000 ;
else {
switch ( V_536 & V_539 ) {
case V_547 :
return 333000 ;
default:
case V_548 :
return 190000 ;
}
}
}
static int F_396 ( struct V_1 * V_2 )
{
return 266000 ;
}
static int F_397 ( struct V_1 * V_2 )
{
T_5 V_549 = 0 ;
switch ( V_549 & V_550 ) {
case V_551 :
case V_552 :
return 200000 ;
case V_553 :
return 250000 ;
case V_554 :
return 133000 ;
}
return 0 ;
}
static int F_398 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_399 ( T_4 * V_555 , T_4 * V_556 )
{
while ( * V_555 > V_557 ||
* V_556 > V_557 ) {
* V_555 >>= 1 ;
* V_556 >>= 1 ;
}
}
static void F_400 ( unsigned int V_11 , unsigned int V_17 ,
T_4 * V_558 , T_4 * V_559 )
{
* V_559 = F_401 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_558 = F_31 ( ( V_49 ) V_11 * * V_559 , V_17 ) ;
F_399 ( V_558 , V_559 ) ;
}
void
F_385 ( int V_305 , int V_560 ,
int V_561 , int V_562 ,
struct V_563 * V_564 )
{
V_564 -> V_565 = 64 ;
F_400 ( V_305 * V_561 ,
V_562 * V_560 * 8 ,
& V_564 -> V_566 , & V_564 -> V_567 ) ;
F_400 ( V_561 , V_562 ,
& V_564 -> V_568 , & V_564 -> V_569 ) ;
}
static inline bool F_402 ( struct V_3 * V_4 )
{
if ( V_322 . V_570 >= 0 )
return V_322 . V_570 != 0 ;
return V_4 -> V_571 . V_572
&& ! ( V_4 -> V_141 & V_573 ) ;
}
static int F_403 ( struct V_20 * V_21 , int V_574 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_10 ;
if ( F_18 ( V_2 ) ) {
V_10 = 100000 ;
} else if ( F_9 ( V_21 , V_25 ) &&
F_402 ( V_4 ) && V_574 < 2 ) {
V_10 = V_4 -> V_571 . V_575 ;
F_45 ( L_101 , V_10 ) ;
} else if ( ! F_19 ( V_2 ) ) {
V_10 = 96000 ;
} else {
V_10 = 48000 ;
}
return V_10 ;
}
static T_4 F_404 ( struct V_48 * V_48 )
{
return ( 1 << V_48 -> V_17 ) << 16 | V_48 -> V_13 ;
}
static T_4 F_405 ( struct V_48 * V_48 )
{
return V_48 -> V_17 << 16 | V_48 -> V_12 << 8 | V_48 -> V_13 ;
}
static void F_406 ( struct V_67 * V_21 ,
T_2 * V_576 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
T_1 V_577 , V_578 = 0 ;
if ( F_16 ( V_2 ) ) {
V_577 = F_404 ( & V_21 -> V_71 . V_48 ) ;
if ( V_576 )
V_578 = F_404 ( V_576 ) ;
} else {
V_577 = F_405 ( & V_21 -> V_71 . V_48 ) ;
if ( V_576 )
V_578 = F_405 ( V_576 ) ;
}
V_21 -> V_71 . V_199 . V_497 = V_577 ;
V_21 -> V_579 = false ;
if ( F_9 ( & V_21 -> V_112 , V_25 ) &&
V_576 && V_322 . V_580 ) {
V_21 -> V_71 . V_199 . V_498 = V_578 ;
V_21 -> V_579 = true ;
} else {
V_21 -> V_71 . V_199 . V_498 = V_577 ;
}
}
static void F_407 ( struct V_3 * V_4 , enum V_75
V_75 )
{
T_1 V_581 ;
V_581 = F_128 ( V_4 , V_75 , F_408 ( 1 ) ) ;
V_581 &= 0xffffff00 ;
V_581 |= 0x00000030 ;
F_130 ( V_4 , V_75 , F_408 ( 1 ) , V_581 ) ;
V_581 = F_128 ( V_4 , V_75 , V_582 ) ;
V_581 &= 0x8cffffff ;
V_581 = 0x8c000000 ;
F_130 ( V_4 , V_75 , V_582 , V_581 ) ;
V_581 = F_128 ( V_4 , V_75 , F_408 ( 1 ) ) ;
V_581 &= 0xffffff00 ;
F_130 ( V_4 , V_75 , F_408 ( 1 ) , V_581 ) ;
V_581 = F_128 ( V_4 , V_75 , V_582 ) ;
V_581 &= 0x00ffffff ;
V_581 |= 0xb0000000 ;
F_130 ( V_4 , V_75 , V_582 , V_581 ) ;
}
static void F_409 ( struct V_67 * V_21 ,
struct V_563 * V_564 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_75 = V_21 -> V_75 ;
F_44 ( F_410 ( V_75 ) , F_411 ( V_564 -> V_565 ) | V_564 -> V_566 ) ;
F_44 ( F_412 ( V_75 ) , V_564 -> V_567 ) ;
F_44 ( F_413 ( V_75 ) , V_564 -> V_568 ) ;
F_44 ( F_414 ( V_75 ) , V_564 -> V_569 ) ;
}
static void F_302 ( struct V_67 * V_21 ,
struct V_563 * V_564 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_75 = V_21 -> V_75 ;
enum V_74 V_74 = V_21 -> V_71 . V_77 ;
if ( F_43 ( V_2 ) -> V_81 >= 5 ) {
F_44 ( F_266 ( V_74 ) , F_411 ( V_564 -> V_565 ) | V_564 -> V_566 ) ;
F_44 ( F_415 ( V_74 ) , V_564 -> V_567 ) ;
F_44 ( F_416 ( V_74 ) , V_564 -> V_568 ) ;
F_44 ( F_417 ( V_74 ) , V_564 -> V_569 ) ;
} else {
F_44 ( F_418 ( V_75 ) , F_411 ( V_564 -> V_565 ) | V_564 -> V_566 ) ;
F_44 ( F_419 ( V_75 ) , V_564 -> V_567 ) ;
F_44 ( F_420 ( V_75 ) , V_564 -> V_568 ) ;
F_44 ( F_421 ( V_75 ) , V_564 -> V_569 ) ;
}
}
static void F_300 ( struct V_67 * V_21 )
{
if ( V_21 -> V_71 . V_237 )
F_409 ( V_21 , & V_21 -> V_71 . V_583 ) ;
else
F_302 ( V_21 , & V_21 -> V_71 . V_583 ) ;
}
static void F_422 ( struct V_67 * V_21 )
{
T_1 V_48 , V_201 ;
V_48 = V_584 | V_206 |
V_585 | V_586 ;
if ( V_21 -> V_75 == V_137 )
V_48 |= V_205 ;
V_48 |= V_107 ;
V_21 -> V_71 . V_199 . V_48 = V_48 ;
V_201 = ( V_21 -> V_71 . V_587 - 1 )
<< V_588 ;
V_21 -> V_71 . V_199 . V_201 = V_201 ;
}
static void F_355 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_75 = V_21 -> V_75 ;
T_1 V_589 ;
T_1 V_590 , V_591 , V_592 , V_593 , V_594 ;
T_1 V_595 , V_581 ;
F_57 ( & V_4 -> V_108 ) ;
V_590 = V_21 -> V_71 . V_48 . V_17 ;
V_591 = V_21 -> V_71 . V_48 . V_12 ;
V_592 = V_21 -> V_71 . V_48 . V_13 ;
V_593 = V_21 -> V_71 . V_48 . V_15 ;
V_594 = V_21 -> V_71 . V_48 . V_16 ;
if ( V_75 == V_137 )
F_407 ( V_4 , V_75 ) ;
F_130 ( V_4 , V_75 , V_596 , 0x0100000f ) ;
V_581 = F_128 ( V_4 , V_75 , F_423 ( V_75 ) ) ;
V_581 &= 0x00ffffff ;
F_130 ( V_4 , V_75 , F_423 ( V_75 ) , V_581 ) ;
F_130 ( V_4 , V_75 , V_597 , 0x610 ) ;
V_589 = ( ( V_591 << V_598 ) | ( V_592 & V_599 ) ) ;
V_589 |= ( ( V_593 << V_600 ) | ( V_594 << V_601 ) ) ;
V_589 |= ( ( V_590 << V_602 ) ) ;
V_589 |= ( 1 << V_603 ) ;
V_589 |= ( V_604 << V_605 ) ;
F_130 ( V_4 , V_75 , F_424 ( V_75 ) , V_589 ) ;
V_589 |= V_606 ;
F_130 ( V_4 , V_75 , F_424 ( V_75 ) , V_589 ) ;
if ( V_21 -> V_71 . V_607 == 162000 ||
F_9 ( & V_21 -> V_112 , V_34 ) ||
F_9 ( & V_21 -> V_112 , V_33 ) )
F_130 ( V_4 , V_75 , F_425 ( V_75 ) ,
0x009f0003 ) ;
else
F_130 ( V_4 , V_75 , F_425 ( V_75 ) ,
0x00d0000f ) ;
if ( F_9 ( & V_21 -> V_112 , V_328 ) ||
F_9 ( & V_21 -> V_112 , V_397 ) ) {
if ( V_75 == V_128 )
F_130 ( V_4 , V_75 , F_426 ( V_75 ) ,
0x0df40000 ) ;
else
F_130 ( V_4 , V_75 , F_426 ( V_75 ) ,
0x0df70000 ) ;
} else {
if ( V_75 == V_128 )
F_130 ( V_4 , V_75 , F_426 ( V_75 ) ,
0x0df70000 ) ;
else
F_130 ( V_4 , V_75 , F_426 ( V_75 ) ,
0x0df40000 ) ;
}
V_595 = F_128 ( V_4 , V_75 , F_427 ( V_75 ) ) ;
V_595 = ( V_595 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_9 ( & V_21 -> V_112 , V_397 ) ||
F_9 ( & V_21 -> V_112 , V_328 ) )
V_595 |= 0x01000000 ;
F_130 ( V_4 , V_75 , F_427 ( V_75 ) , V_595 ) ;
F_130 ( V_4 , V_75 , F_428 ( V_75 ) , 0x87871000 ) ;
F_59 ( & V_4 -> V_108 ) ;
}
static void F_429 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_75 = V_21 -> V_75 ;
int V_210 = F_55 ( V_21 -> V_75 ) ;
enum V_202 V_91 = F_127 ( V_75 ) ;
T_1 V_608 , V_609 ;
T_1 V_590 , V_591 , V_592 , V_593 , V_594 , V_610 ;
int V_10 ;
V_21 -> V_71 . V_199 . V_48 = V_207 |
V_206 | V_585 |
V_107 ;
if ( V_75 != V_128 )
V_21 -> V_71 . V_199 . V_48 |= V_205 ;
V_21 -> V_71 . V_199 . V_201 =
( V_21 -> V_71 . V_587 - 1 ) << V_588 ;
V_590 = V_21 -> V_71 . V_48 . V_17 ;
V_610 = V_21 -> V_71 . V_48 . V_13 & 0x3fffff ;
V_591 = V_21 -> V_71 . V_48 . V_12 ;
V_592 = V_21 -> V_71 . V_48 . V_13 >> 22 ;
V_593 = V_21 -> V_71 . V_48 . V_15 ;
V_594 = V_21 -> V_71 . V_48 . V_16 ;
F_44 ( V_210 ,
V_21 -> V_71 . V_199 . V_48 & ~ V_107 ) ;
F_57 ( & V_4 -> V_108 ) ;
F_130 ( V_4 , V_75 , F_430 ( V_91 ) ,
5 << V_611 |
V_593 << V_612 |
V_594 << V_613 |
1 << V_614 ) ;
F_130 ( V_4 , V_75 , F_431 ( V_91 ) , V_592 ) ;
F_130 ( V_4 , V_75 , F_432 ( V_91 ) ,
V_615 |
1 << V_616 ) ;
F_130 ( V_4 , V_75 , F_433 ( V_91 ) , V_610 ) ;
F_130 ( V_4 , V_75 , F_434 ( V_91 ) ,
V_617 |
( 2 << V_618 ) ) ;
V_10 = F_403 ( & V_21 -> V_112 , 0 ) ;
V_608 = 5 << V_619 |
2 << V_620 ;
if ( V_10 == 100000 )
V_609 = 11 ;
else if ( V_10 == 38400 )
V_609 = 10 ;
else
V_609 = 9 ;
V_608 |= V_609 << V_621 ;
F_130 ( V_4 , V_75 , F_435 ( V_91 ) , V_608 ) ;
F_130 ( V_4 , V_75 , F_129 ( V_91 ) ,
F_128 ( V_4 , V_75 , F_129 ( V_91 ) ) |
V_622 ) ;
F_59 ( & V_4 -> V_108 ) ;
}
static void F_436 ( struct V_67 * V_21 ,
T_2 * V_576 ,
int V_574 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_48 ;
bool V_623 ;
struct V_48 * clock = & V_21 -> V_71 . V_48 ;
F_406 ( V_21 , V_576 ) ;
V_623 = F_9 ( & V_21 -> V_112 , V_36 ) ||
F_9 ( & V_21 -> V_112 , V_33 ) ;
V_48 = V_585 ;
if ( F_9 ( & V_21 -> V_112 , V_25 ) )
V_48 |= V_624 ;
else
V_48 |= V_625 ;
if ( F_437 ( V_2 ) || F_438 ( V_2 ) || F_439 ( V_2 ) ) {
V_48 |= ( V_21 -> V_71 . V_587 - 1 )
<< V_626 ;
}
if ( V_623 )
V_48 |= V_627 ;
if ( F_9 ( & V_21 -> V_112 , V_397 ) )
V_48 |= V_627 ;
if ( F_16 ( V_2 ) )
V_48 |= ( 1 << ( clock -> V_15 - 1 ) ) << V_628 ;
else {
V_48 |= ( 1 << ( clock -> V_15 - 1 ) ) << V_629 ;
if ( F_15 ( V_2 ) && V_576 )
V_48 |= ( 1 << ( V_576 -> V_15 - 1 ) ) << V_630 ;
}
switch ( clock -> V_16 ) {
case 5 :
V_48 |= V_631 ;
break;
case 7 :
V_48 |= V_632 ;
break;
case 10 :
V_48 |= V_633 ;
break;
case 14 :
V_48 |= V_634 ;
break;
}
if ( F_43 ( V_2 ) -> V_81 >= 4 )
V_48 |= ( 6 << V_635 ) ;
if ( V_21 -> V_71 . V_636 )
V_48 |= V_637 ;
else if ( F_9 ( & V_21 -> V_112 , V_25 ) &&
F_402 ( V_4 ) && V_574 < 2 )
V_48 |= V_638 ;
else
V_48 |= V_639 ;
V_48 |= V_107 ;
V_21 -> V_71 . V_199 . V_48 = V_48 ;
if ( F_43 ( V_2 ) -> V_81 >= 4 ) {
T_1 V_201 = ( V_21 -> V_71 . V_587 - 1 )
<< V_588 ;
V_21 -> V_71 . V_199 . V_201 = V_201 ;
}
}
static void F_440 ( struct V_67 * V_21 ,
T_2 * V_576 ,
int V_574 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_48 ;
struct V_48 * clock = & V_21 -> V_71 . V_48 ;
F_406 ( V_21 , V_576 ) ;
V_48 = V_585 ;
if ( F_9 ( & V_21 -> V_112 , V_25 ) ) {
V_48 |= ( 1 << ( clock -> V_15 - 1 ) ) << V_629 ;
} else {
if ( clock -> V_15 == 2 )
V_48 |= V_640 ;
else
V_48 |= ( clock -> V_15 - 2 ) << V_629 ;
if ( clock -> V_16 == 4 )
V_48 |= V_641 ;
}
if ( F_9 ( & V_21 -> V_112 , V_45 ) )
V_48 |= V_642 ;
if ( F_9 ( & V_21 -> V_112 , V_25 ) &&
F_402 ( V_4 ) && V_574 < 2 )
V_48 |= V_638 ;
else
V_48 |= V_639 ;
V_48 |= V_107 ;
V_21 -> V_71 . V_199 . V_48 = V_48 ;
}
static void F_301 ( struct V_67 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_75 V_75 = V_67 -> V_75 ;
enum V_74 V_77 = V_67 -> V_71 . V_77 ;
struct V_324 * V_72 =
& V_67 -> V_71 . V_72 ;
T_4 V_643 , V_644 ;
int V_645 = 0 ;
V_643 = V_72 -> V_643 ;
V_644 = V_72 -> V_644 ;
if ( V_72 -> V_314 & V_646 ) {
V_643 -= 1 ;
V_644 -= 1 ;
if ( F_9 ( & V_67 -> V_112 , V_36 ) )
V_645 = ( V_72 -> V_647 - 1 ) / 2 ;
else
V_645 = V_72 -> V_648 -
V_72 -> V_647 / 2 ;
if ( V_645 < 0 )
V_645 += V_72 -> V_647 ;
}
if ( F_43 ( V_2 ) -> V_81 > 3 )
F_44 ( F_261 ( V_77 ) , V_645 ) ;
F_44 ( F_249 ( V_77 ) ,
( V_72 -> V_325 - 1 ) |
( ( V_72 -> V_647 - 1 ) << 16 ) ) ;
F_44 ( F_251 ( V_77 ) ,
( V_72 -> V_649 - 1 ) |
( ( V_72 -> V_650 - 1 ) << 16 ) ) ;
F_44 ( F_253 ( V_77 ) ,
( V_72 -> V_648 - 1 ) |
( ( V_72 -> V_651 - 1 ) << 16 ) ) ;
F_44 ( F_255 ( V_77 ) ,
( V_72 -> V_326 - 1 ) |
( ( V_643 - 1 ) << 16 ) ) ;
F_44 ( F_257 ( V_77 ) ,
( V_72 -> V_652 - 1 ) |
( ( V_644 - 1 ) << 16 ) ) ;
F_44 ( F_259 ( V_77 ) ,
( V_72 -> V_653 - 1 ) |
( ( V_72 -> V_654 - 1 ) << 16 ) ) ;
if ( F_195 ( V_2 ) && V_77 == V_655 &&
( V_75 == V_137 || V_75 == V_342 ) )
F_44 ( F_255 ( V_75 ) , F_4 ( F_255 ( V_77 ) ) ) ;
F_44 ( F_212 ( V_75 ) ,
( ( V_67 -> V_71 . V_329 - 1 ) << 16 ) |
( V_67 -> V_71 . V_330 - 1 ) ) ;
}
static void F_441 ( struct V_67 * V_21 ,
struct V_446 * V_447 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_74 V_77 = V_447 -> V_77 ;
T_4 V_203 ;
V_203 = F_4 ( F_249 ( V_77 ) ) ;
V_447 -> V_72 . V_325 = ( V_203 & 0xffff ) + 1 ;
V_447 -> V_72 . V_647 = ( ( V_203 >> 16 ) & 0xffff ) + 1 ;
V_203 = F_4 ( F_251 ( V_77 ) ) ;
V_447 -> V_72 . V_649 = ( V_203 & 0xffff ) + 1 ;
V_447 -> V_72 . V_650 = ( ( V_203 >> 16 ) & 0xffff ) + 1 ;
V_203 = F_4 ( F_253 ( V_77 ) ) ;
V_447 -> V_72 . V_648 = ( V_203 & 0xffff ) + 1 ;
V_447 -> V_72 . V_651 = ( ( V_203 >> 16 ) & 0xffff ) + 1 ;
V_203 = F_4 ( F_255 ( V_77 ) ) ;
V_447 -> V_72 . V_326 = ( V_203 & 0xffff ) + 1 ;
V_447 -> V_72 . V_643 = ( ( V_203 >> 16 ) & 0xffff ) + 1 ;
V_203 = F_4 ( F_257 ( V_77 ) ) ;
V_447 -> V_72 . V_652 = ( V_203 & 0xffff ) + 1 ;
V_447 -> V_72 . V_644 = ( ( V_203 >> 16 ) & 0xffff ) + 1 ;
V_203 = F_4 ( F_259 ( V_77 ) ) ;
V_447 -> V_72 . V_653 = ( V_203 & 0xffff ) + 1 ;
V_447 -> V_72 . V_654 = ( ( V_203 >> 16 ) & 0xffff ) + 1 ;
if ( F_4 ( F_50 ( V_77 ) ) & V_225 ) {
V_447 -> V_72 . V_314 |= V_646 ;
V_447 -> V_72 . V_643 += 1 ;
V_447 -> V_72 . V_644 += 1 ;
}
V_203 = F_4 ( F_212 ( V_21 -> V_75 ) ) ;
V_447 -> V_330 = ( V_203 & 0xffff ) + 1 ;
V_447 -> V_329 = ( ( V_203 >> 16 ) & 0xffff ) + 1 ;
V_447 -> V_656 . V_508 = V_447 -> V_330 ;
V_447 -> V_656 . V_506 = V_447 -> V_329 ;
}
void F_442 ( struct V_324 * V_403 ,
struct V_446 * V_447 )
{
V_403 -> V_506 = V_447 -> V_72 . V_325 ;
V_403 -> V_657 = V_447 -> V_72 . V_647 ;
V_403 -> V_535 = V_447 -> V_72 . V_648 ;
V_403 -> V_658 = V_447 -> V_72 . V_651 ;
V_403 -> V_508 = V_447 -> V_72 . V_326 ;
V_403 -> V_659 = V_447 -> V_72 . V_643 ;
V_403 -> V_660 = V_447 -> V_72 . V_653 ;
V_403 -> V_661 = V_447 -> V_72 . V_654 ;
V_403 -> V_314 = V_447 -> V_72 . V_314 ;
V_403 -> clock = V_447 -> V_72 . V_73 ;
V_403 -> V_314 |= V_447 -> V_72 . V_314 ;
}
static void F_358 ( struct V_67 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_662 ;
V_662 = 0 ;
if ( V_4 -> V_141 & V_142 &&
F_4 ( F_50 ( V_67 -> V_75 ) ) & V_143 )
V_662 |= V_143 ;
if ( V_67 -> V_71 . V_534 )
V_662 |= V_663 ;
if ( F_15 ( V_2 ) || F_18 ( V_2 ) ) {
if ( V_67 -> V_71 . V_664 && V_67 -> V_71 . V_528 != 30 )
V_662 |= V_665 |
V_666 ;
switch ( V_67 -> V_71 . V_528 ) {
case 18 :
V_662 |= V_667 ;
break;
case 24 :
V_662 |= V_668 ;
break;
case 30 :
V_662 |= V_669 ;
break;
default:
F_136 () ;
}
}
if ( F_443 ( V_2 ) ) {
if ( V_67 -> V_579 ) {
F_45 ( L_102 ) ;
V_662 |= V_670 ;
} else {
F_45 ( L_103 ) ;
}
}
if ( V_67 -> V_71 . V_72 . V_314 & V_646 ) {
if ( F_43 ( V_2 ) -> V_81 < 4 ||
F_9 ( & V_67 -> V_112 , V_36 ) )
V_662 |= V_671 ;
else
V_662 |= V_672 ;
} else
V_662 |= V_673 ;
if ( F_18 ( V_2 ) && V_67 -> V_71 . V_674 )
V_662 |= V_675 ;
F_44 ( F_50 ( V_67 -> V_75 ) , V_662 ) ;
F_123 ( F_50 ( V_67 -> V_75 ) ) ;
}
static int F_444 ( struct V_20 * V_21 ,
int V_258 , int V_259 ,
struct V_293 * V_70 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_10 , V_574 = 0 ;
T_2 clock , V_576 ;
bool V_676 , V_677 = false ;
bool V_678 = false , V_495 = false ;
struct V_22 * V_23 ;
const T_3 * V_24 ;
F_10 (dev, crtc, encoder) {
switch ( V_23 -> type ) {
case V_25 :
V_678 = true ;
break;
case V_236 :
V_495 = true ;
break;
}
V_574 ++ ;
}
if ( V_495 )
return 0 ;
if ( ! V_67 -> V_71 . V_679 ) {
V_10 = F_403 ( V_21 , V_574 ) ;
V_24 = F_14 ( V_21 , V_10 ) ;
V_676 = V_4 -> V_308 . V_680 ( V_24 , V_21 ,
V_67 -> V_71 . V_607 ,
V_10 , NULL , & clock ) ;
if ( ! V_676 ) {
F_115 ( L_104 ) ;
return - V_253 ;
}
if ( V_678 && V_4 -> V_681 ) {
V_677 =
V_4 -> V_308 . V_680 ( V_24 , V_21 ,
V_4 -> V_682 ,
V_10 , & clock ,
& V_576 ) ;
}
V_67 -> V_71 . V_48 . V_17 = clock . V_17 ;
V_67 -> V_71 . V_48 . V_12 = clock . V_12 ;
V_67 -> V_71 . V_48 . V_13 = clock . V_13 ;
V_67 -> V_71 . V_48 . V_15 = clock . V_15 ;
V_67 -> V_71 . V_48 . V_16 = clock . V_16 ;
}
if ( F_19 ( V_2 ) ) {
F_440 ( V_67 ,
V_677 ? & V_576 : NULL ,
V_574 ) ;
} else if ( F_17 ( V_2 ) ) {
F_429 ( V_67 ) ;
} else if ( F_18 ( V_2 ) ) {
F_422 ( V_67 ) ;
} else {
F_436 ( V_67 ,
V_677 ? & V_576 : NULL ,
V_574 ) ;
}
return 0 ;
}
static void F_445 ( struct V_67 * V_21 ,
struct V_446 * V_447 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_203 ;
if ( F_43 ( V_2 ) -> V_81 <= 3 && ( F_122 ( V_2 ) || ! F_121 ( V_2 ) ) )
return;
V_203 = F_4 ( V_450 ) ;
if ( ! ( V_203 & V_451 ) )
return;
if ( F_43 ( V_2 ) -> V_81 < 4 ) {
if ( V_21 -> V_75 != V_137 )
return;
} else {
if ( ( V_203 & V_683 ) != ( V_21 -> V_75 << V_684 ) )
return;
}
V_447 -> V_448 . V_449 = V_203 ;
V_447 -> V_448 . V_453 = F_4 ( V_452 ) ;
if ( F_43 ( V_2 ) -> V_81 < 5 )
V_447 -> V_448 . V_685 =
F_4 ( V_133 ) & V_686 ;
}
static void F_446 ( struct V_67 * V_21 ,
struct V_446 * V_447 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_75 = V_447 -> V_77 ;
T_2 clock ;
T_1 V_589 ;
int V_10 = 100000 ;
F_57 ( & V_4 -> V_108 ) ;
V_589 = F_128 ( V_4 , V_75 , F_424 ( V_75 ) ) ;
F_59 ( & V_4 -> V_108 ) ;
clock . V_12 = ( V_589 >> V_598 ) & 7 ;
clock . V_13 = V_589 & V_599 ;
clock . V_17 = ( V_589 >> V_602 ) & 0xf ;
clock . V_15 = ( V_589 >> V_600 ) & 7 ;
clock . V_16 = ( V_589 >> V_601 ) & 0x1f ;
F_7 ( V_10 , & clock ) ;
V_447 -> V_607 = clock . V_19 / 5 ;
}
static void F_447 ( struct V_67 * V_21 ,
struct V_280 * V_281 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_105 , V_112 , V_264 ;
int V_75 = V_21 -> V_75 , V_144 = V_21 -> V_144 ;
int V_687 , V_287 ;
int V_688 ;
V_21 -> V_112 . V_69 -> V_70 = F_448 ( sizeof( struct V_292 ) , V_689 ) ;
if ( ! V_21 -> V_112 . V_69 -> V_70 ) {
F_45 ( L_105 ) ;
return;
}
V_105 = F_4 ( F_82 ( V_144 ) ) ;
if ( F_43 ( V_2 ) -> V_81 >= 4 )
if ( V_105 & V_303 )
V_281 -> V_241 = true ;
V_287 = V_105 & V_297 ;
V_687 = F_179 ( V_287 ) ;
V_21 -> V_112 . V_69 -> V_70 -> V_287 = V_687 ;
V_21 -> V_112 . V_69 -> V_70 -> V_305 =
F_449 ( V_687 , 0 ) * 8 ;
if ( F_43 ( V_2 ) -> V_81 >= 4 ) {
if ( V_281 -> V_241 )
V_264 = F_4 ( F_192 ( V_144 ) ) ;
else
V_264 = F_4 ( F_193 ( V_144 ) ) ;
V_112 = F_4 ( F_159 ( V_144 ) ) & 0xfffff000 ;
} else {
V_112 = F_4 ( F_160 ( V_144 ) ) ;
}
V_281 -> V_112 = V_112 ;
V_105 = F_4 ( F_212 ( V_75 ) ) ;
V_21 -> V_112 . V_69 -> V_70 -> V_288 = ( ( V_105 >> 16 ) & 0xfff ) + 1 ;
V_21 -> V_112 . V_69 -> V_70 -> V_240 = ( ( V_105 >> 0 ) & 0xfff ) + 1 ;
V_105 = F_4 ( F_191 ( V_75 ) ) ;
V_21 -> V_112 . V_69 -> V_70 -> V_286 [ 0 ] = V_105 & 0xffffff80 ;
V_688 = F_167 ( V_2 , V_21 -> V_112 . V_69 -> V_70 -> V_240 ,
V_281 -> V_241 ) ;
V_281 -> V_284 = F_168 ( V_21 -> V_112 . V_69 -> V_70 -> V_286 [ 0 ] *
V_688 , V_690 ) ;
F_45 ( L_106 ,
V_75 , V_144 , V_21 -> V_112 . V_69 -> V_70 -> V_288 ,
V_21 -> V_112 . V_69 -> V_70 -> V_240 ,
V_21 -> V_112 . V_69 -> V_70 -> V_305 , V_112 ,
V_21 -> V_112 . V_69 -> V_70 -> V_286 [ 0 ] ,
V_281 -> V_284 ) ;
}
static void F_450 ( struct V_67 * V_21 ,
struct V_446 * V_447 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_75 = V_447 -> V_77 ;
enum V_202 V_91 = F_127 ( V_75 ) ;
T_2 clock ;
T_1 V_691 , V_692 , V_693 , V_694 ;
int V_10 = 100000 ;
F_57 ( & V_4 -> V_108 ) ;
V_691 = F_128 ( V_4 , V_75 , F_430 ( V_91 ) ) ;
V_692 = F_128 ( V_4 , V_75 , F_431 ( V_91 ) ) ;
V_693 = F_128 ( V_4 , V_75 , F_432 ( V_91 ) ) ;
V_694 = F_128 ( V_4 , V_75 , F_433 ( V_91 ) ) ;
F_59 ( & V_4 -> V_108 ) ;
clock . V_12 = ( V_693 & 0x7 ) == V_615 ? 2 : 0 ;
clock . V_13 = ( ( V_692 & 0xff ) << 22 ) | ( V_694 & 0x3fffff ) ;
clock . V_17 = ( V_693 >> V_616 ) & 0xf ;
clock . V_15 = ( V_691 >> V_612 ) & 0x7 ;
clock . V_16 = ( V_691 >> V_613 ) & 0x1f ;
F_23 ( V_10 , & clock ) ;
V_447 -> V_607 = clock . V_19 / 5 ;
}
static bool F_451 ( struct V_67 * V_21 ,
struct V_446 * V_447 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_203 ;
if ( ! F_79 ( V_4 ,
F_334 ( V_21 -> V_75 ) ) )
return false ;
V_447 -> V_77 = (enum V_74 ) V_21 -> V_75 ;
V_447 -> V_113 = V_408 ;
V_203 = F_4 ( F_50 ( V_21 -> V_75 ) ) ;
if ( ! ( V_203 & V_143 ) )
return false ;
if ( F_15 ( V_2 ) || F_18 ( V_2 ) ) {
switch ( V_203 & V_223 ) {
case V_667 :
V_447 -> V_528 = 18 ;
break;
case V_668 :
V_447 -> V_528 = 24 ;
break;
case V_669 :
V_447 -> V_528 = 30 ;
break;
default:
break;
}
}
if ( F_18 ( V_2 ) && ( V_203 & V_675 ) )
V_447 -> V_674 = true ;
if ( F_43 ( V_2 ) -> V_81 < 4 )
V_447 -> V_534 = V_203 & V_663 ;
F_441 ( V_21 , V_447 ) ;
F_445 ( V_21 , V_447 ) ;
if ( F_43 ( V_2 ) -> V_81 >= 4 ) {
V_203 = F_4 ( F_125 ( V_21 -> V_75 ) ) ;
V_447 -> V_587 =
( ( V_203 & V_695 )
>> V_588 ) + 1 ;
V_447 -> V_199 . V_201 = V_203 ;
} else if ( F_437 ( V_2 ) || F_438 ( V_2 ) || F_439 ( V_2 ) ) {
V_203 = F_4 ( F_55 ( V_21 -> V_75 ) ) ;
V_447 -> V_587 =
( ( V_203 & V_696 )
>> V_626 ) + 1 ;
} else {
V_447 -> V_587 = 1 ;
}
V_447 -> V_199 . V_48 = F_4 ( F_55 ( V_21 -> V_75 ) ) ;
if ( ! F_18 ( V_2 ) ) {
V_447 -> V_199 . V_497 = F_4 ( F_361 ( V_21 -> V_75 ) ) ;
V_447 -> V_199 . V_498 = F_4 ( F_362 ( V_21 -> V_75 ) ) ;
} else {
V_447 -> V_199 . V_48 &= ~ ( V_200 |
V_212 |
V_211 ) ;
}
if ( F_17 ( V_2 ) )
F_450 ( V_21 , V_447 ) ;
else if ( F_18 ( V_2 ) )
F_446 ( V_21 , V_447 ) ;
else
F_452 ( V_21 , V_447 ) ;
return true ;
}
static void F_453 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_697 * V_698 = & V_2 -> V_698 ;
struct V_22 * V_23 ;
T_1 V_105 , V_699 ;
bool V_700 = false ;
bool V_701 = false ;
bool V_702 = false ;
bool V_703 = false ;
bool V_704 = false ;
F_371 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_23 -> type ) {
case V_25 :
V_702 = true ;
V_700 = true ;
break;
case V_328 :
V_702 = true ;
if ( F_331 ( & V_23 -> V_112 ) -> V_91 == V_457 )
V_701 = true ;
break;
}
}
if ( F_52 ( V_2 ) ) {
V_703 = V_4 -> V_571 . V_705 ;
V_704 = V_703 ;
} else {
V_703 = false ;
V_704 = true ;
}
F_45 ( L_107 ,
V_702 , V_700 , V_703 ) ;
V_105 = F_4 ( V_154 ) ;
V_699 = V_105 ;
V_699 &= ~ V_156 ;
if ( V_703 )
V_699 |= V_706 ;
else
V_699 |= V_707 ;
V_699 &= ~ V_155 ;
V_699 &= ~ V_708 ;
V_699 &= ~ V_709 ;
if ( V_702 ) {
V_699 |= V_710 ;
if ( F_402 ( V_4 ) && V_704 )
V_699 |= V_709 ;
if ( V_701 ) {
if ( F_402 ( V_4 ) && V_704 )
V_699 |= V_711 ;
else
V_699 |= V_712 ;
} else
V_699 |= V_713 ;
} else {
V_699 |= V_714 ;
V_699 |= V_713 ;
}
if ( V_699 == V_105 )
return;
V_105 &= ~ V_156 ;
if ( V_703 )
V_105 |= V_706 ;
else
V_105 |= V_707 ;
if ( V_702 ) {
V_105 &= ~ V_155 ;
V_105 |= V_710 ;
if ( F_402 ( V_4 ) && V_704 ) {
F_45 ( L_108 ) ;
V_105 |= V_709 ;
} else
V_105 &= ~ V_709 ;
F_44 ( V_154 , V_105 ) ;
F_123 ( V_154 ) ;
F_124 ( 200 ) ;
V_105 &= ~ V_708 ;
if ( V_701 ) {
if ( F_402 ( V_4 ) && V_704 ) {
F_45 ( L_109 ) ;
V_105 |= V_711 ;
} else
V_105 |= V_712 ;
} else
V_105 |= V_713 ;
F_44 ( V_154 , V_105 ) ;
F_123 ( V_154 ) ;
F_124 ( 200 ) ;
} else {
F_45 ( L_110 ) ;
V_105 &= ~ V_708 ;
V_105 |= V_713 ;
F_44 ( V_154 , V_105 ) ;
F_123 ( V_154 ) ;
F_124 ( 200 ) ;
V_105 &= ~ V_155 ;
V_105 |= V_714 ;
V_105 &= ~ V_709 ;
F_44 ( V_154 , V_105 ) ;
F_123 ( V_154 ) ;
F_124 ( 200 ) ;
}
F_120 ( V_105 != V_699 ) ;
}
static void F_454 ( struct V_3 * V_4 )
{
T_4 V_203 ;
V_203 = F_4 ( V_715 ) ;
V_203 |= V_716 ;
F_44 ( V_715 , V_203 ) ;
if ( F_455 ( F_4 ( V_715 ) &
V_717 , 100 ) )
F_115 ( L_111 ) ;
V_203 = F_4 ( V_715 ) ;
V_203 &= ~ V_716 ;
F_44 ( V_715 , V_203 ) ;
if ( F_455 ( ( F_4 ( V_715 ) &
V_717 ) == 0 , 100 ) )
F_115 ( L_112 ) ;
}
static void F_456 ( struct V_3 * V_4 )
{
T_4 V_203 ;
V_203 = F_242 ( V_4 , 0x8008 , V_718 ) ;
V_203 &= ~ ( 0xFF << 24 ) ;
V_203 |= ( 0x12 << 24 ) ;
F_241 ( V_4 , 0x8008 , V_203 , V_718 ) ;
V_203 = F_242 ( V_4 , 0x2008 , V_718 ) ;
V_203 |= ( 1 << 11 ) ;
F_241 ( V_4 , 0x2008 , V_203 , V_718 ) ;
V_203 = F_242 ( V_4 , 0x2108 , V_718 ) ;
V_203 |= ( 1 << 11 ) ;
F_241 ( V_4 , 0x2108 , V_203 , V_718 ) ;
V_203 = F_242 ( V_4 , 0x206C , V_718 ) ;
V_203 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_241 ( V_4 , 0x206C , V_203 , V_718 ) ;
V_203 = F_242 ( V_4 , 0x216C , V_718 ) ;
V_203 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_241 ( V_4 , 0x216C , V_203 , V_718 ) ;
V_203 = F_242 ( V_4 , 0x2080 , V_718 ) ;
V_203 &= ~ ( 7 << 13 ) ;
V_203 |= ( 5 << 13 ) ;
F_241 ( V_4 , 0x2080 , V_203 , V_718 ) ;
V_203 = F_242 ( V_4 , 0x2180 , V_718 ) ;
V_203 &= ~ ( 7 << 13 ) ;
V_203 |= ( 5 << 13 ) ;
F_241 ( V_4 , 0x2180 , V_203 , V_718 ) ;
V_203 = F_242 ( V_4 , 0x208C , V_718 ) ;
V_203 &= ~ 0xFF ;
V_203 |= 0x1C ;
F_241 ( V_4 , 0x208C , V_203 , V_718 ) ;
V_203 = F_242 ( V_4 , 0x218C , V_718 ) ;
V_203 &= ~ 0xFF ;
V_203 |= 0x1C ;
F_241 ( V_4 , 0x218C , V_203 , V_718 ) ;
V_203 = F_242 ( V_4 , 0x2098 , V_718 ) ;
V_203 &= ~ ( 0xFF << 16 ) ;
V_203 |= ( 0x1C << 16 ) ;
F_241 ( V_4 , 0x2098 , V_203 , V_718 ) ;
V_203 = F_242 ( V_4 , 0x2198 , V_718 ) ;
V_203 &= ~ ( 0xFF << 16 ) ;
V_203 |= ( 0x1C << 16 ) ;
F_241 ( V_4 , 0x2198 , V_203 , V_718 ) ;
V_203 = F_242 ( V_4 , 0x20C4 , V_718 ) ;
V_203 |= ( 1 << 27 ) ;
F_241 ( V_4 , 0x20C4 , V_203 , V_718 ) ;
V_203 = F_242 ( V_4 , 0x21C4 , V_718 ) ;
V_203 |= ( 1 << 27 ) ;
F_241 ( V_4 , 0x21C4 , V_203 , V_718 ) ;
V_203 = F_242 ( V_4 , 0x20EC , V_718 ) ;
V_203 &= ~ ( 0xF << 28 ) ;
V_203 |= ( 4 << 28 ) ;
F_241 ( V_4 , 0x20EC , V_203 , V_718 ) ;
V_203 = F_242 ( V_4 , 0x21EC , V_718 ) ;
V_203 &= ~ ( 0xF << 28 ) ;
V_203 |= ( 4 << 28 ) ;
F_241 ( V_4 , 0x21EC , V_203 , V_718 ) ;
}
static void F_457 ( struct V_1 * V_2 , bool V_719 ,
bool V_720 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_83 , V_203 ;
if ( F_40 ( V_720 && ! V_719 , L_113 ) )
V_719 = true ;
if ( F_40 ( V_4 -> V_721 == V_722 &&
V_720 , L_114 ) )
V_720 = false ;
F_57 ( & V_4 -> V_108 ) ;
V_203 = F_242 ( V_4 , V_723 , V_379 ) ;
V_203 &= ~ V_380 ;
V_203 |= V_724 ;
F_241 ( V_4 , V_723 , V_203 , V_379 ) ;
F_124 ( 24 ) ;
if ( V_719 ) {
V_203 = F_242 ( V_4 , V_723 , V_379 ) ;
V_203 &= ~ V_724 ;
F_241 ( V_4 , V_723 , V_203 , V_379 ) ;
if ( V_720 ) {
F_454 ( V_4 ) ;
F_456 ( V_4 ) ;
}
}
V_83 = ( V_4 -> V_721 == V_722 ) ?
V_725 : V_726 ;
V_203 = F_242 ( V_4 , V_83 , V_379 ) ;
V_203 |= V_727 ;
F_241 ( V_4 , V_83 , V_203 , V_379 ) ;
F_59 ( & V_4 -> V_108 ) ;
}
static void F_458 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_83 , V_203 ;
F_57 ( & V_4 -> V_108 ) ;
V_83 = ( V_4 -> V_721 == V_722 ) ?
V_725 : V_726 ;
V_203 = F_242 ( V_4 , V_83 , V_379 ) ;
V_203 &= ~ V_727 ;
F_241 ( V_4 , V_83 , V_203 , V_379 ) ;
V_203 = F_242 ( V_4 , V_723 , V_379 ) ;
if ( ! ( V_203 & V_380 ) ) {
if ( ! ( V_203 & V_724 ) ) {
V_203 |= V_724 ;
F_241 ( V_4 , V_723 , V_203 , V_379 ) ;
F_124 ( 32 ) ;
}
V_203 |= V_380 ;
F_241 ( V_4 , V_723 , V_203 , V_379 ) ;
}
F_59 ( & V_4 -> V_108 ) ;
}
static void F_459 ( struct V_1 * V_2 )
{
struct V_697 * V_698 = & V_2 -> V_698 ;
struct V_22 * V_23 ;
bool V_728 = false ;
F_371 (encoder, &mode_config->encoder_list, base.head) {
switch ( V_23 -> type ) {
case V_34 :
V_728 = true ;
break;
}
}
if ( V_728 )
F_457 ( V_2 , true , true ) ;
else
F_458 ( V_2 ) ;
}
void F_460 ( struct V_1 * V_2 )
{
if ( F_52 ( V_2 ) || F_93 ( V_2 ) )
F_453 ( V_2 ) ;
else if ( F_62 ( V_2 ) )
F_459 ( V_2 ) ;
}
static int F_461 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_23 ;
int V_574 = 0 ;
bool V_678 = false ;
F_10 (dev, crtc, encoder) {
switch ( V_23 -> type ) {
case V_25 :
V_678 = true ;
break;
}
V_574 ++ ;
}
if ( V_678 && F_402 ( V_4 ) && V_574 < 2 ) {
F_45 ( L_101 ,
V_4 -> V_571 . V_575 ) ;
return V_4 -> V_571 . V_575 ;
}
return 120000 ;
}
static void F_303 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_75 = V_67 -> V_75 ;
T_4 V_105 ;
V_105 = 0 ;
switch ( V_67 -> V_71 . V_528 ) {
case 18 :
V_105 |= V_667 ;
break;
case 24 :
V_105 |= V_668 ;
break;
case 30 :
V_105 |= V_669 ;
break;
case 36 :
V_105 |= V_729 ;
break;
default:
F_136 () ;
}
if ( V_67 -> V_71 . V_664 )
V_105 |= ( V_665 | V_666 ) ;
if ( V_67 -> V_71 . V_72 . V_314 & V_646 )
V_105 |= V_226 ;
else
V_105 |= V_673 ;
if ( V_67 -> V_71 . V_674 )
V_105 |= V_675 ;
F_44 ( F_50 ( V_75 ) , V_105 ) ;
F_123 ( F_50 ( V_75 ) ) ;
}
static void F_313 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_75 = V_67 -> V_75 ;
T_6 V_730 = 0x7800 ;
if ( V_67 -> V_71 . V_674 )
V_730 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_44 ( F_462 ( V_75 ) , V_730 << 16 ) ;
F_44 ( F_463 ( V_75 ) , 0 ) ;
F_44 ( F_464 ( V_75 ) , V_730 ) ;
F_44 ( F_465 ( V_75 ) , 0 ) ;
F_44 ( F_466 ( V_75 ) , 0 ) ;
F_44 ( F_467 ( V_75 ) , V_730 << 16 ) ;
F_44 ( F_468 ( V_75 ) , 0 ) ;
F_44 ( F_469 ( V_75 ) , 0 ) ;
F_44 ( F_470 ( V_75 ) , 0 ) ;
if ( F_43 ( V_2 ) -> V_81 > 6 ) {
T_6 V_731 = 0 ;
if ( V_67 -> V_71 . V_674 )
V_731 = ( 16 * ( 1 << 12 ) / 255 ) & 0x1fff ;
F_44 ( F_471 ( V_75 ) , V_731 ) ;
F_44 ( F_472 ( V_75 ) , V_731 ) ;
F_44 ( F_473 ( V_75 ) , V_731 ) ;
F_44 ( F_474 ( V_75 ) , 0 ) ;
} else {
T_4 V_403 = V_732 ;
if ( V_67 -> V_71 . V_674 )
V_403 |= V_733 ;
F_44 ( F_474 ( V_75 ) , V_403 ) ;
}
}
static void F_312 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
enum V_75 V_75 = V_67 -> V_75 ;
enum V_74 V_77 = V_67 -> V_71 . V_77 ;
T_4 V_105 ;
V_105 = 0 ;
if ( F_195 ( V_2 ) && V_67 -> V_71 . V_664 )
V_105 |= ( V_665 | V_666 ) ;
if ( V_67 -> V_71 . V_72 . V_314 & V_646 )
V_105 |= V_226 ;
else
V_105 |= V_673 ;
F_44 ( F_50 ( V_77 ) , V_105 ) ;
F_123 ( F_50 ( V_77 ) ) ;
F_44 ( F_289 ( V_67 -> V_75 ) , V_734 ) ;
F_123 ( F_289 ( V_67 -> V_75 ) ) ;
if ( F_163 ( V_2 ) ) {
V_105 = 0 ;
switch ( V_67 -> V_71 . V_528 ) {
case 18 :
V_105 |= V_735 ;
break;
case 24 :
V_105 |= V_736 ;
break;
case 30 :
V_105 |= V_737 ;
break;
case 36 :
V_105 |= V_738 ;
break;
default:
F_136 () ;
}
if ( V_67 -> V_71 . V_664 )
V_105 |= V_739 | V_740 ;
F_44 ( F_475 ( V_75 ) , V_105 ) ;
}
}
static bool F_476 ( struct V_20 * V_21 ,
T_2 * clock ,
bool * V_677 ,
T_2 * V_576 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_22 ;
int V_10 ;
const T_3 * V_24 ;
bool V_248 , V_678 = false ;
F_10 (dev, crtc, intel_encoder) {
switch ( V_22 -> type ) {
case V_25 :
V_678 = true ;
break;
}
}
V_10 = F_461 ( V_21 ) ;
V_24 = F_14 ( V_21 , V_10 ) ;
V_248 = V_4 -> V_308 . V_680 ( V_24 , V_21 ,
F_34 ( V_21 ) -> V_71 . V_607 ,
V_10 , NULL , clock ) ;
if ( ! V_248 )
return false ;
if ( V_678 && V_4 -> V_681 ) {
* V_677 =
V_4 -> V_308 . V_680 ( V_24 , V_21 ,
V_4 -> V_682 ,
V_10 , clock ,
V_576 ) ;
}
return true ;
}
int F_384 ( int V_741 , int V_524 , int V_742 )
{
T_1 V_743 = V_741 * V_742 * 21 / 20 ;
return F_477 ( V_743 , V_524 * 8 ) ;
}
static bool F_478 ( struct V_48 * V_48 , int V_744 )
{
return F_21 ( V_48 ) < V_744 * V_48 -> V_17 ;
}
static T_4 F_479 ( struct V_67 * V_67 ,
T_1 * V_577 ,
T_2 * V_576 , T_1 * V_578 )
{
struct V_20 * V_21 = & V_67 -> V_112 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_22 ;
T_4 V_48 ;
int V_744 , V_574 = 0 ;
bool V_678 = false , V_623 = false ;
F_10 (dev, crtc, intel_encoder) {
switch ( V_22 -> type ) {
case V_25 :
V_678 = true ;
break;
case V_36 :
case V_33 :
V_623 = true ;
break;
}
V_574 ++ ;
}
V_744 = 21 ;
if ( V_678 ) {
if ( ( F_402 ( V_4 ) &&
V_4 -> V_571 . V_575 == 100000 ) ||
( F_52 ( V_2 ) && F_12 ( V_2 ) ) )
V_744 = 25 ;
} else if ( V_67 -> V_71 . V_636 )
V_744 = 20 ;
if ( F_478 ( & V_67 -> V_71 . V_48 , V_744 ) )
* V_577 |= V_745 ;
if ( V_578 && ( V_576 -> V_11 < V_744 * V_576 -> V_17 ) )
* V_578 |= V_745 ;
V_48 = 0 ;
if ( V_678 )
V_48 |= V_624 ;
else
V_48 |= V_625 ;
V_48 |= ( V_67 -> V_71 . V_587 - 1 )
<< V_746 ;
if ( V_623 )
V_48 |= V_627 ;
if ( V_67 -> V_71 . V_437 )
V_48 |= V_627 ;
V_48 |= ( 1 << ( V_67 -> V_71 . V_48 . V_15 - 1 ) ) << V_629 ;
V_48 |= ( 1 << ( V_67 -> V_71 . V_48 . V_15 - 1 ) ) << V_630 ;
switch ( V_67 -> V_71 . V_48 . V_16 ) {
case 5 :
V_48 |= V_631 ;
break;
case 7 :
V_48 |= V_632 ;
break;
case 10 :
V_48 |= V_633 ;
break;
case 14 :
V_48 |= V_634 ;
break;
}
if ( V_678 && F_402 ( V_4 ) && V_574 < 2 )
V_48 |= V_638 ;
else
V_48 |= V_639 ;
return V_48 | V_107 ;
}
static int F_480 ( struct V_20 * V_21 ,
int V_258 , int V_259 ,
struct V_293 * V_70 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_574 = 0 ;
T_2 clock , V_576 ;
T_1 V_48 = 0 , V_577 = 0 , V_578 = 0 ;
bool V_676 , V_677 = false ;
bool V_678 = false ;
struct V_22 * V_23 ;
struct V_111 * V_115 ;
F_10 (dev, crtc, encoder) {
switch ( V_23 -> type ) {
case V_25 :
V_678 = true ;
break;
}
V_574 ++ ;
}
F_40 ( ! ( F_52 ( V_2 ) || F_93 ( V_2 ) ) ,
L_115 , F_481 ( V_2 ) ) ;
V_676 = F_476 ( V_21 , & clock ,
& V_677 , & V_576 ) ;
if ( ! V_676 && ! V_67 -> V_71 . V_679 ) {
F_115 ( L_104 ) ;
return - V_253 ;
}
if ( ! V_67 -> V_71 . V_679 ) {
V_67 -> V_71 . V_48 . V_17 = clock . V_17 ;
V_67 -> V_71 . V_48 . V_12 = clock . V_12 ;
V_67 -> V_71 . V_48 . V_13 = clock . V_13 ;
V_67 -> V_71 . V_48 . V_15 = clock . V_15 ;
V_67 -> V_71 . V_48 . V_16 = clock . V_16 ;
}
if ( V_67 -> V_71 . V_237 ) {
V_577 = F_405 ( & V_67 -> V_71 . V_48 ) ;
if ( V_677 )
V_578 = F_405 ( & V_576 ) ;
V_48 = F_479 ( V_67 ,
& V_577 , & V_576 ,
V_677 ? & V_578 : NULL ) ;
V_67 -> V_71 . V_199 . V_48 = V_48 ;
V_67 -> V_71 . V_199 . V_497 = V_577 ;
if ( V_677 )
V_67 -> V_71 . V_199 . V_498 = V_578 ;
else
V_67 -> V_71 . V_199 . V_498 = V_577 ;
V_115 = F_272 ( V_67 ) ;
if ( V_115 == NULL ) {
F_63 ( L_116 ,
F_73 ( V_67 -> V_75 ) ) ;
return - V_253 ;
}
} else
F_271 ( V_67 ) ;
if ( V_678 && V_677 && V_322 . V_580 )
V_67 -> V_579 = true ;
else
V_67 -> V_579 = false ;
return 0 ;
}
static void F_482 ( struct V_67 * V_21 ,
struct V_563 * V_564 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_75 V_75 = V_21 -> V_75 ;
V_564 -> V_568 = F_4 ( F_413 ( V_75 ) ) ;
V_564 -> V_569 = F_4 ( F_414 ( V_75 ) ) ;
V_564 -> V_566 = F_4 ( F_410 ( V_75 ) )
& ~ V_392 ;
V_564 -> V_567 = F_4 ( F_412 ( V_75 ) ) ;
V_564 -> V_565 = ( ( F_4 ( F_410 ( V_75 ) )
& V_392 ) >> V_747 ) + 1 ;
}
static void F_483 ( struct V_67 * V_21 ,
enum V_74 V_74 ,
struct V_563 * V_564 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_75 V_75 = V_21 -> V_75 ;
if ( F_43 ( V_2 ) -> V_81 >= 5 ) {
V_564 -> V_568 = F_4 ( F_416 ( V_74 ) ) ;
V_564 -> V_569 = F_4 ( F_417 ( V_74 ) ) ;
V_564 -> V_566 = F_4 ( F_266 ( V_74 ) )
& ~ V_392 ;
V_564 -> V_567 = F_4 ( F_415 ( V_74 ) ) ;
V_564 -> V_565 = ( ( F_4 ( F_266 ( V_74 ) )
& V_392 ) >> V_747 ) + 1 ;
} else {
V_564 -> V_568 = F_4 ( F_420 ( V_75 ) ) ;
V_564 -> V_569 = F_4 ( F_421 ( V_75 ) ) ;
V_564 -> V_566 = F_4 ( F_418 ( V_75 ) )
& ~ V_392 ;
V_564 -> V_567 = F_4 ( F_419 ( V_75 ) ) ;
V_564 -> V_565 = ( ( F_4 ( F_418 ( V_75 ) )
& V_392 ) >> V_747 ) + 1 ;
}
}
void F_484 ( struct V_67 * V_21 ,
struct V_446 * V_447 )
{
if ( V_21 -> V_71 . V_237 )
F_482 ( V_21 , & V_447 -> V_583 ) ;
else
F_483 ( V_21 , V_447 -> V_77 ,
& V_447 -> V_583 ) ;
}
static void F_485 ( struct V_67 * V_21 ,
struct V_446 * V_447 )
{
F_483 ( V_21 , V_447 -> V_77 ,
& V_447 -> V_438 ) ;
}
static void F_486 ( struct V_67 * V_21 ,
struct V_446 * V_447 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_203 ;
V_203 = F_4 ( F_213 ( V_21 -> V_75 ) ) ;
if ( V_203 & V_412 ) {
V_447 -> V_327 . V_103 = true ;
V_447 -> V_327 . V_414 = F_4 ( F_214 ( V_21 -> V_75 ) ) ;
V_447 -> V_327 . V_284 = F_4 ( F_215 ( V_21 -> V_75 ) ) ;
if ( F_487 ( V_2 ) ) {
F_2 ( ( V_203 & V_748 ) !=
F_275 ( V_21 -> V_75 ) ) ;
}
}
}
static void F_488 ( struct V_67 * V_21 ,
struct V_280 * V_281 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_105 , V_112 , V_264 ;
int V_75 = V_21 -> V_75 , V_144 = V_21 -> V_144 ;
int V_687 , V_287 ;
int V_688 ;
V_21 -> V_112 . V_69 -> V_70 = F_448 ( sizeof( struct V_292 ) , V_689 ) ;
if ( ! V_21 -> V_112 . V_69 -> V_70 ) {
F_45 ( L_105 ) ;
return;
}
V_105 = F_4 ( F_82 ( V_144 ) ) ;
if ( F_43 ( V_2 ) -> V_81 >= 4 )
if ( V_105 & V_303 )
V_281 -> V_241 = true ;
V_287 = V_105 & V_297 ;
V_687 = F_179 ( V_287 ) ;
V_21 -> V_112 . V_69 -> V_70 -> V_287 = V_687 ;
V_21 -> V_112 . V_69 -> V_70 -> V_305 =
F_449 ( V_687 , 0 ) * 8 ;
V_112 = F_4 ( F_159 ( V_144 ) ) & 0xfffff000 ;
if ( F_195 ( V_2 ) || F_163 ( V_2 ) ) {
V_264 = F_4 ( F_196 ( V_144 ) ) ;
} else {
if ( V_281 -> V_241 )
V_264 = F_4 ( F_192 ( V_144 ) ) ;
else
V_264 = F_4 ( F_193 ( V_144 ) ) ;
}
V_281 -> V_112 = V_112 ;
V_105 = F_4 ( F_212 ( V_75 ) ) ;
V_21 -> V_112 . V_69 -> V_70 -> V_288 = ( ( V_105 >> 16 ) & 0xfff ) + 1 ;
V_21 -> V_112 . V_69 -> V_70 -> V_240 = ( ( V_105 >> 0 ) & 0xfff ) + 1 ;
V_105 = F_4 ( F_191 ( V_75 ) ) ;
V_21 -> V_112 . V_69 -> V_70 -> V_286 [ 0 ] = V_105 & 0xffffff80 ;
V_688 = F_167 ( V_2 , V_21 -> V_112 . V_69 -> V_70 -> V_240 ,
V_281 -> V_241 ) ;
V_281 -> V_284 = F_168 ( V_21 -> V_112 . V_69 -> V_70 -> V_286 [ 0 ] *
V_688 , V_690 ) ;
F_45 ( L_106 ,
V_75 , V_144 , V_21 -> V_112 . V_69 -> V_70 -> V_288 ,
V_21 -> V_112 . V_69 -> V_70 -> V_240 ,
V_21 -> V_112 . V_69 -> V_70 -> V_305 , V_112 ,
V_21 -> V_112 . V_69 -> V_70 -> V_286 [ 0 ] ,
V_281 -> V_284 ) ;
}
static bool F_489 ( struct V_67 * V_21 ,
struct V_446 * V_447 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_203 ;
V_447 -> V_77 = (enum V_74 ) V_21 -> V_75 ;
V_447 -> V_113 = V_408 ;
V_203 = F_4 ( F_50 ( V_21 -> V_75 ) ) ;
if ( ! ( V_203 & V_143 ) )
return false ;
switch ( V_203 & V_223 ) {
case V_667 :
V_447 -> V_528 = 18 ;
break;
case V_668 :
V_447 -> V_528 = 24 ;
break;
case V_669 :
V_447 -> V_528 = 30 ;
break;
case V_729 :
V_447 -> V_528 = 36 ;
break;
default:
break;
}
if ( V_203 & V_675 )
V_447 -> V_674 = true ;
if ( F_4 ( F_95 ( V_21 -> V_75 ) ) & V_158 ) {
struct V_111 * V_115 ;
V_447 -> V_237 = true ;
V_203 = F_4 ( F_69 ( V_21 -> V_75 ) ) ;
V_447 -> V_349 = ( ( V_348 & V_203 ) >>
V_749 ) + 1 ;
F_485 ( V_21 , V_447 ) ;
if ( F_52 ( V_4 -> V_2 ) ) {
V_447 -> V_113 =
(enum V_409 ) V_21 -> V_75 ;
} else {
V_203 = F_4 ( V_395 ) ;
if ( V_203 & F_268 ( V_21 -> V_75 ) )
V_447 -> V_113 = V_396 ;
else
V_447 -> V_113 = V_750 ;
}
V_115 = & V_4 -> V_114 [ V_447 -> V_113 ] ;
F_2 ( ! V_115 -> V_118 ( V_4 , V_115 ,
& V_447 -> V_199 ) ) ;
V_203 = V_447 -> V_199 . V_48 ;
V_447 -> V_587 =
( ( V_203 & V_751 )
>> V_746 ) + 1 ;
F_490 ( V_21 , V_447 ) ;
} else {
V_447 -> V_587 = 1 ;
}
F_441 ( V_21 , V_447 ) ;
F_486 ( V_21 , V_447 ) ;
return true ;
}
static void F_491 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_752 * V_753 = & V_4 -> V_754 ;
struct V_67 * V_21 ;
F_236 (dev, crtc)
F_40 ( V_21 -> V_68 , L_117 ,
F_73 ( V_21 -> V_75 ) ) ;
F_40 ( F_4 ( V_755 ) , L_118 ) ;
F_40 ( V_753 -> V_756 , L_119 ) ;
F_40 ( V_753 -> V_757 , L_120 ) ;
F_40 ( V_753 -> V_758 , L_121 ) ;
F_40 ( F_4 ( V_759 ) & V_760 , L_122 ) ;
F_40 ( F_4 ( V_761 ) & V_762 ,
L_123 ) ;
F_40 ( F_4 ( V_763 ) & V_762 ,
L_124 ) ;
F_40 ( F_4 ( V_764 ) & V_765 ,
L_125 ) ;
F_40 ( F_4 ( V_766 ) & V_767 ,
L_126 ) ;
F_40 ( F_4 ( V_768 ) & V_769 , L_127 ) ;
F_40 ( ! V_4 -> V_770 . V_771 , L_128 ) ;
}
static void F_492 ( struct V_3 * V_4 , T_4 V_105 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( F_195 ( V_2 ) ) {
F_57 ( & V_4 -> V_418 . V_419 ) ;
if ( F_284 ( V_4 , V_772 ,
V_105 ) )
F_115 ( L_129 ) ;
F_59 ( & V_4 -> V_418 . V_419 ) ;
} else {
F_44 ( V_773 , V_105 ) ;
}
F_123 ( V_773 ) ;
}
static void F_493 ( struct V_3 * V_4 ,
bool V_774 , bool V_775 )
{
T_4 V_105 ;
F_491 ( V_4 ) ;
V_105 = F_4 ( V_776 ) ;
if ( V_774 ) {
V_105 |= V_777 ;
F_44 ( V_776 , V_105 ) ;
if ( F_455 ( F_4 ( V_776 ) &
V_778 , 1 ) )
F_115 ( L_130 ) ;
V_105 = F_4 ( V_776 ) ;
}
V_105 |= V_779 ;
F_44 ( V_776 , V_105 ) ;
F_123 ( V_776 ) ;
if ( F_38 ( ( F_4 ( V_776 ) & V_780 ) == 0 , 1 ) )
F_115 ( L_131 ) ;
V_105 = F_4 ( V_773 ) ;
V_105 |= V_781 ;
F_492 ( V_4 , V_105 ) ;
F_494 ( 100 ) ;
if ( F_38 ( ( F_4 ( V_773 ) & V_782 ) == 0 , 1 ) )
F_115 ( L_132 ) ;
if ( V_775 ) {
V_105 = F_4 ( V_776 ) ;
V_105 |= V_783 ;
F_44 ( V_776 , V_105 ) ;
F_123 ( V_776 ) ;
}
}
static void F_495 ( struct V_3 * V_4 )
{
T_4 V_105 ;
unsigned long V_784 ;
V_105 = F_4 ( V_776 ) ;
if ( ( V_105 & ( V_780 | V_779 | V_777 |
V_783 ) ) == V_780 )
return;
F_209 ( & V_4 -> V_785 . V_786 , V_784 ) ;
if ( V_4 -> V_785 . V_787 ++ == 0 )
V_4 -> V_785 . V_788 . V_789 ( V_4 , V_790 ) ;
F_210 ( & V_4 -> V_785 . V_786 , V_784 ) ;
if ( V_105 & V_783 ) {
V_105 &= ~ V_783 ;
F_44 ( V_776 , V_105 ) ;
F_123 ( V_776 ) ;
}
V_105 = F_4 ( V_773 ) ;
V_105 |= V_791 ;
V_105 &= ~ V_781 ;
F_492 ( V_4 , V_105 ) ;
V_105 = F_4 ( V_776 ) ;
V_105 &= ~ V_779 ;
F_44 ( V_776 , V_105 ) ;
if ( F_38 ( F_4 ( V_776 ) & V_780 , 5 ) )
F_115 ( L_133 ) ;
if ( V_105 & V_777 ) {
V_105 = F_4 ( V_776 ) ;
V_105 &= ~ V_777 ;
F_44 ( V_776 , V_105 ) ;
if ( F_455 ( ( F_4 ( V_776 ) &
V_778 ) == 0 , 1 ) )
F_115 ( L_134 ) ;
}
F_209 ( & V_4 -> V_785 . V_786 , V_784 ) ;
if ( -- V_4 -> V_785 . V_787 == 0 )
V_4 -> V_785 . V_788 . V_792 ( V_4 , V_790 ) ;
F_210 ( & V_4 -> V_785 . V_786 , V_784 ) ;
}
void F_496 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_105 ;
F_45 ( L_135 ) ;
if ( V_4 -> V_721 == V_722 ) {
V_105 = F_4 ( V_793 ) ;
V_105 &= ~ V_794 ;
F_44 ( V_793 , V_105 ) ;
}
F_458 ( V_2 ) ;
F_493 ( V_4 , true , true ) ;
}
void F_497 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_105 ;
F_45 ( L_136 ) ;
F_495 ( V_4 ) ;
F_459 ( V_2 ) ;
if ( V_4 -> V_721 == V_722 ) {
V_105 = F_4 ( V_793 ) ;
V_105 |= V_794 ;
F_44 ( V_793 , V_105 ) ;
}
F_498 ( V_2 ) ;
}
static void F_499 ( struct V_1 * V_2 )
{
F_339 ( V_2 ) ;
}
static void F_500 ( struct V_1 * V_2 )
{
F_339 ( V_2 ) ;
}
static int F_501 ( struct V_20 * V_21 ,
int V_258 , int V_259 ,
struct V_293 * V_70 )
{
struct V_67 * V_67 = F_34 ( V_21 ) ;
if ( ! F_502 ( V_67 ) )
return - V_253 ;
F_503 ( V_67 ) ;
V_67 -> V_579 = false ;
return 0 ;
}
static bool F_504 ( struct V_67 * V_21 ,
struct V_446 * V_447 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_454 V_795 ;
T_4 V_203 ;
if ( ! F_79 ( V_4 ,
F_334 ( V_21 -> V_75 ) ) )
return false ;
V_447 -> V_77 = (enum V_74 ) V_21 -> V_75 ;
V_447 -> V_113 = V_408 ;
V_203 = F_4 ( F_66 ( V_655 ) ) ;
if ( V_203 & V_120 ) {
enum V_75 V_796 ;
switch ( V_203 & V_797 ) {
default:
F_40 ( 1 , L_137 ) ;
case V_798 :
case V_799 :
V_796 = V_128 ;
break;
case V_800 :
V_796 = V_137 ;
break;
case V_801 :
V_796 = V_342 ;
break;
}
if ( V_796 == V_21 -> V_75 )
V_447 -> V_77 = V_655 ;
}
if ( ! F_79 ( V_4 ,
F_80 ( V_447 -> V_77 ) ) )
return false ;
V_203 = F_4 ( F_50 ( V_447 -> V_77 ) ) ;
if ( ! ( V_203 & V_143 ) )
return false ;
V_203 = F_4 ( F_66 ( V_447 -> V_77 ) ) ;
if ( ( V_203 & V_802 ) == F_505 ( V_803 ) &&
F_4 ( V_234 ) & V_158 ) {
V_447 -> V_237 = true ;
V_203 = F_4 ( F_69 ( V_128 ) ) ;
V_447 -> V_349 = ( ( V_348 & V_203 ) >>
V_749 ) + 1 ;
F_485 ( V_21 , V_447 ) ;
}
F_441 ( V_21 , V_447 ) ;
V_795 = F_335 ( V_21 -> V_75 ) ;
if ( F_79 ( V_4 , V_795 ) )
F_486 ( V_21 , V_447 ) ;
if ( F_195 ( V_2 ) )
V_447 -> V_417 = F_308 ( V_21 ) &&
( F_4 ( V_421 ) & V_422 ) ;
V_447 -> V_587 = 1 ;
return true ;
}
static T_1 F_506 ( struct V_324 * V_403 )
{
int V_146 ;
for ( V_146 = 0 ; V_146 < F_231 ( V_804 ) ; V_146 ++ ) {
if ( V_403 -> clock == V_804 [ V_146 ] . clock )
break;
}
if ( V_146 == F_231 ( V_804 ) ) {
F_45 ( L_138 , V_403 -> clock ) ;
V_146 = 1 ;
}
F_45 ( L_139 ,
V_804 [ V_146 ] . clock ,
V_804 [ V_146 ] . V_71 ) ;
return V_804 [ V_146 ] . V_71 ;
}
static bool F_507 ( struct V_514 * V_515 ,
int V_805 , T_4 V_806 ,
int V_807 , T_4 V_808 ,
int V_809 )
{
struct V_3 * V_4 = V_515 -> V_2 -> V_5 ;
T_7 * V_810 = V_515 -> V_810 ;
T_4 V_146 ;
V_146 = F_4 ( V_805 ) ;
V_146 &= V_806 ;
if ( ! V_810 [ 0 ] )
return ! V_146 ;
if ( ! V_146 )
return false ;
V_146 = F_4 ( V_807 ) ;
V_146 &= ~ V_808 ;
F_44 ( V_807 , V_146 ) ;
for ( V_146 = 0 ; V_146 < V_810 [ 2 ] ; V_146 ++ )
if ( F_4 ( V_809 ) != * ( ( T_4 * ) V_810 + V_146 ) )
return false ;
return true ;
}
static void F_508 ( struct V_514 * V_515 ,
struct V_20 * V_21 ,
struct V_324 * V_403 )
{
struct V_3 * V_4 = V_515 -> V_2 -> V_5 ;
T_7 * V_810 = V_515 -> V_810 ;
T_4 V_811 ;
T_4 V_812 ;
T_4 V_146 ;
V_146 = F_4 ( V_813 ) ;
if ( V_146 == V_814 || V_146 == V_815 )
V_811 = V_816 ;
else
V_811 = V_817 ;
if ( F_507 ( V_515 ,
V_818 , V_811 ,
V_818 , V_819 ,
V_820 ) )
return;
V_146 = F_4 ( V_818 ) ;
V_146 &= ~ ( V_811 | V_819 ) ;
V_812 = ( V_146 >> 9 ) & 0x1f ;
F_44 ( V_818 , V_146 ) ;
if ( ! V_810 [ 0 ] )
return;
V_812 = F_401 ( T_7 , V_810 [ 2 ] , V_812 ) ;
F_63 ( L_140 , V_812 ) ;
for ( V_146 = 0 ; V_146 < V_812 ; V_146 ++ )
F_44 ( V_820 , * ( ( T_4 * ) V_810 + V_146 ) ) ;
V_146 = F_4 ( V_818 ) ;
V_146 |= V_811 ;
F_44 ( V_818 , V_146 ) ;
}
static void F_509 ( struct V_514 * V_515 ,
struct V_20 * V_21 ,
struct V_324 * V_403 )
{
struct V_3 * V_4 = V_515 -> V_2 -> V_5 ;
T_7 * V_810 = V_515 -> V_810 ;
T_4 V_811 ;
T_4 V_146 ;
int V_812 ;
int V_75 = F_34 ( V_21 ) -> V_75 ;
int V_203 ;
int V_821 = F_510 ( V_75 ) ;
int V_822 = F_511 ( V_75 ) ;
int V_823 = F_512 ( V_75 ) ;
int V_824 = V_825 ;
F_63 ( L_141 ) ;
V_203 = F_4 ( V_824 ) ;
V_203 |= ( V_826 << ( V_75 * 4 ) ) ;
F_44 ( V_824 , V_203 ) ;
F_123 ( V_824 ) ;
F_119 ( V_4 , F_34 ( V_21 ) -> V_75 ) ;
V_203 = F_4 ( V_824 ) ;
F_63 ( L_142 , V_203 ) ;
V_203 |= ( V_827 << ( V_75 * 4 ) ) ;
F_44 ( V_824 , V_203 ) ;
V_203 = F_4 ( V_824 ) ;
F_63 ( L_143 , V_203 ) ;
V_203 = F_4 ( V_823 ) ;
F_63 ( L_144 , V_203 ) ;
V_203 &= ~ ( V_828 | V_829 ) ;
F_44 ( V_823 , V_203 ) ;
F_63 ( L_145 , F_73 ( V_75 ) ) ;
V_811 = V_827 << ( V_75 * 4 ) ;
if ( F_9 ( V_21 , V_397 ) ) {
F_63 ( L_146 ) ;
V_810 [ 5 ] |= ( 1 << 2 ) ;
F_44 ( V_823 , V_828 ) ;
} else {
F_44 ( V_823 , F_506 ( V_403 ) ) ;
}
if ( F_507 ( V_515 ,
V_824 , V_811 ,
V_822 , V_830 ,
V_821 ) )
return;
V_146 = F_4 ( V_824 ) ;
V_146 &= ~ V_811 ;
F_44 ( V_824 , V_146 ) ;
if ( ! V_810 [ 0 ] )
return;
V_146 = F_4 ( V_822 ) ;
V_146 &= ~ V_830 ;
F_44 ( V_822 , V_146 ) ;
V_146 = ( V_146 >> 29 ) & V_831 ;
F_63 ( L_147 , V_146 ) ;
V_812 = F_401 ( T_7 , V_810 [ 2 ] , 21 ) ;
F_63 ( L_140 , V_812 ) ;
for ( V_146 = 0 ; V_146 < V_812 ; V_146 ++ )
F_44 ( V_821 , * ( ( T_4 * ) V_810 + V_146 ) ) ;
V_146 = F_4 ( V_824 ) ;
V_146 |= V_811 ;
F_44 ( V_824 , V_146 ) ;
}
static void F_513 ( struct V_514 * V_515 ,
struct V_20 * V_21 ,
struct V_324 * V_403 )
{
struct V_3 * V_4 = V_515 -> V_2 -> V_5 ;
T_7 * V_810 = V_515 -> V_810 ;
T_4 V_811 ;
T_4 V_146 ;
int V_812 ;
int V_821 ;
int V_823 ;
int V_822 ;
int V_824 ;
int V_75 = F_34 ( V_21 ) -> V_75 ;
if ( F_52 ( V_515 -> V_2 ) ) {
V_821 = F_514 ( V_75 ) ;
V_823 = F_515 ( V_75 ) ;
V_822 = F_516 ( V_75 ) ;
V_824 = V_832 ;
} else if ( F_18 ( V_515 -> V_2 ) ) {
V_821 = F_517 ( V_75 ) ;
V_823 = F_518 ( V_75 ) ;
V_822 = F_519 ( V_75 ) ;
V_824 = V_833 ;
} else {
V_821 = F_520 ( V_75 ) ;
V_823 = F_521 ( V_75 ) ;
V_822 = F_522 ( V_75 ) ;
V_824 = V_834 ;
}
F_63 ( L_145 , F_73 ( V_75 ) ) ;
if ( F_18 ( V_515 -> V_2 ) ) {
struct V_22 * V_22 ;
struct V_90 * V_455 ;
V_22 = F_523 ( V_515 ) ;
V_455 = F_331 ( & V_22 -> V_112 ) ;
V_146 = V_455 -> V_91 ;
} else {
V_146 = F_4 ( V_822 ) ;
V_146 = ( V_146 >> 29 ) & V_831 ;
}
if ( ! V_146 ) {
F_63 ( L_148 ) ;
V_811 = V_835 ;
V_811 |= V_835 << 4 ;
V_811 |= V_835 << 8 ;
} else {
F_63 ( L_149 , F_137 ( V_146 ) ) ;
V_811 = V_835 << ( ( V_146 - 1 ) * 4 ) ;
}
if ( F_9 ( V_21 , V_397 ) ) {
F_63 ( L_146 ) ;
V_810 [ 5 ] |= ( 1 << 2 ) ;
F_44 ( V_823 , V_828 ) ;
} else {
F_44 ( V_823 , F_506 ( V_403 ) ) ;
}
if ( F_507 ( V_515 ,
V_824 , V_811 ,
V_822 , V_830 ,
V_821 ) )
return;
V_146 = F_4 ( V_824 ) ;
V_146 &= ~ V_811 ;
F_44 ( V_824 , V_146 ) ;
if ( ! V_810 [ 0 ] )
return;
V_146 = F_4 ( V_822 ) ;
V_146 &= ~ V_830 ;
F_44 ( V_822 , V_146 ) ;
V_812 = F_401 ( T_7 , V_810 [ 2 ] , 21 ) ;
F_63 ( L_140 , V_812 ) ;
for ( V_146 = 0 ; V_146 < V_812 ; V_146 ++ )
F_44 ( V_821 , * ( ( T_4 * ) V_810 + V_146 ) ) ;
V_146 = F_4 ( V_824 ) ;
V_146 |= V_811 ;
F_44 ( V_824 , V_146 ) ;
}
void F_524 ( struct V_519 * V_23 ,
struct V_324 * V_403 )
{
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_514 * V_515 ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_515 = F_525 ( V_23 , V_403 ) ;
if ( ! V_515 )
return;
F_63 ( L_150 ,
V_515 -> V_112 . V_218 ,
V_515 -> V_119 ,
V_515 -> V_23 -> V_112 . V_218 ,
V_515 -> V_23 -> V_119 ) ;
V_515 -> V_810 [ 6 ] = F_526 ( V_515 , V_403 ) / 2 ;
if ( V_4 -> V_308 . V_836 )
V_4 -> V_308 . V_836 ( V_515 , V_21 , V_403 ) ;
}
static void F_527 ( struct V_20 * V_21 , T_1 V_112 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
T_4 V_431 ;
if ( V_112 != V_67 -> V_837 ) {
if ( V_67 -> V_838 ) {
F_44 ( V_138 , 0 ) ;
F_123 ( V_138 ) ;
V_67 -> V_838 = 0 ;
}
F_44 ( V_839 , V_112 ) ;
F_123 ( V_839 ) ;
}
V_431 = 0 ;
if ( V_112 )
V_431 = ( V_139 |
V_840 |
V_841 ) ;
if ( V_67 -> V_838 != V_431 ) {
F_44 ( V_138 , V_431 ) ;
F_123 ( V_138 ) ;
V_67 -> V_838 = V_431 ;
}
}
static void F_528 ( struct V_20 * V_21 , T_1 V_112 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_75 = V_67 -> V_75 ;
T_4 V_431 ;
V_431 = 0 ;
if ( V_112 ) {
V_431 = V_842 ;
switch ( V_67 -> V_843 ) {
case 64 :
V_431 |= V_435 ;
break;
case 128 :
V_431 |= V_844 ;
break;
case 256 :
V_431 |= V_845 ;
break;
default:
F_2 ( 1 ) ;
return;
}
V_431 |= V_75 << 28 ;
}
if ( V_67 -> V_838 != V_431 ) {
F_44 ( F_77 ( V_75 ) , V_431 ) ;
F_123 ( F_77 ( V_75 ) ) ;
V_67 -> V_838 = V_431 ;
}
F_44 ( F_293 ( V_75 ) , V_112 ) ;
F_123 ( F_293 ( V_75 ) ) ;
}
static void F_529 ( struct V_20 * V_21 , T_1 V_112 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_75 = V_67 -> V_75 ;
T_4 V_431 ;
V_431 = 0 ;
if ( V_112 ) {
V_431 = V_842 ;
switch ( V_67 -> V_843 ) {
case 64 :
V_431 |= V_435 ;
break;
case 128 :
V_431 |= V_844 ;
break;
case 256 :
V_431 |= V_845 ;
break;
default:
F_2 ( 1 ) ;
return;
}
}
if ( F_195 ( V_2 ) || F_163 ( V_2 ) )
V_431 |= V_846 ;
if ( V_67 -> V_838 != V_431 ) {
F_44 ( F_77 ( V_75 ) , V_431 ) ;
F_123 ( F_77 ( V_75 ) ) ;
V_67 -> V_838 = V_431 ;
}
F_44 ( F_293 ( V_75 ) , V_112 ) ;
F_123 ( F_293 ( V_75 ) ) ;
}
static void F_295 ( struct V_20 * V_21 ,
bool V_216 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_75 = V_67 -> V_75 ;
int V_258 = V_67 -> V_847 ;
int V_259 = V_67 -> V_848 ;
T_1 V_112 = 0 , V_414 = 0 ;
if ( V_216 )
V_112 = V_67 -> V_849 ;
if ( V_258 >= V_67 -> V_71 . V_329 )
V_112 = 0 ;
if ( V_259 >= V_67 -> V_71 . V_330 )
V_112 = 0 ;
if ( V_258 < 0 ) {
if ( V_258 + V_67 -> V_843 <= 0 )
V_112 = 0 ;
V_414 |= V_850 << V_851 ;
V_258 = - V_258 ;
}
V_414 |= V_258 << V_851 ;
if ( V_259 < 0 ) {
if ( V_259 + V_67 -> V_852 <= 0 )
V_112 = 0 ;
V_414 |= V_850 << V_853 ;
V_259 = - V_259 ;
}
V_414 |= V_259 << V_853 ;
if ( V_112 == 0 && V_67 -> V_837 == 0 )
return;
F_44 ( F_530 ( V_75 ) , V_414 ) ;
if ( F_219 ( V_2 ) || F_195 ( V_2 ) || F_163 ( V_2 ) )
F_529 ( V_21 , V_112 ) ;
else if ( F_75 ( V_2 ) || F_76 ( V_2 ) )
F_527 ( V_21 , V_112 ) ;
else
F_528 ( V_21 , V_112 ) ;
V_67 -> V_837 = V_112 ;
}
static int F_531 ( struct V_20 * V_21 ,
struct V_854 * V_855 ,
T_4 V_856 ,
T_4 V_288 , T_4 V_240 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
struct V_243 * V_244 ;
unsigned V_857 ;
T_4 V_858 ;
int V_248 ;
if ( ! V_856 ) {
F_45 ( L_151 ) ;
V_858 = 0 ;
V_244 = NULL ;
F_57 ( & V_2 -> V_289 ) ;
goto V_859;
}
if ( ! ( ( V_288 == 64 && V_240 == 64 ) ||
( V_288 == 128 && V_240 == 128 && ! F_19 ( V_2 ) ) ||
( V_288 == 256 && V_240 == 256 && ! F_19 ( V_2 ) ) ) ) {
F_532 ( L_152 ) ;
return - V_253 ;
}
V_244 = F_533 ( F_534 ( V_2 , V_855 , V_856 ) ) ;
if ( & V_244 -> V_112 == NULL )
return - V_860 ;
if ( V_244 -> V_112 . V_284 < V_288 * V_240 * 4 ) {
F_45 ( L_153 ) ;
V_248 = - V_861 ;
goto V_862;
}
F_57 ( & V_2 -> V_289 ) ;
if ( ! F_43 ( V_2 ) -> V_863 ) {
unsigned V_247 ;
if ( V_244 -> V_249 ) {
F_45 ( L_154 ) ;
V_248 = - V_253 ;
goto V_864;
}
V_247 = 0 ;
if ( F_165 ( V_2 ) )
V_247 = 64 * 1024 ;
V_248 = F_172 ( V_244 , V_247 , NULL ) ;
if ( V_248 ) {
F_45 ( L_155 ) ;
goto V_864;
}
V_248 = F_535 ( V_244 ) ;
if ( V_248 ) {
F_45 ( L_156 ) ;
goto V_865;
}
V_858 = F_188 ( V_244 ) ;
} else {
int V_866 = F_122 ( V_2 ) ? 16 * 1024 : 256 ;
V_248 = F_536 ( V_244 , V_866 ) ;
if ( V_248 ) {
F_45 ( L_157 ) ;
goto V_864;
}
V_858 = V_244 -> V_867 -> V_868 ;
}
if ( F_19 ( V_2 ) )
F_44 ( V_869 , ( V_240 << 12 ) | V_288 ) ;
V_859:
if ( V_67 -> V_870 ) {
if ( ! F_43 ( V_2 ) -> V_863 )
F_175 ( V_67 -> V_870 ) ;
F_184 ( & V_67 -> V_870 -> V_112 ) ;
}
F_59 ( & V_2 -> V_289 ) ;
V_857 = V_67 -> V_843 ;
V_67 -> V_849 = V_858 ;
V_67 -> V_870 = V_244 ;
V_67 -> V_843 = V_288 ;
V_67 -> V_852 = V_240 ;
if ( V_67 -> V_68 ) {
if ( V_857 != V_288 )
F_306 ( V_21 ) ;
F_295 ( V_21 , V_67 -> V_870 != NULL ) ;
}
return 0 ;
V_865:
F_175 ( V_244 ) ;
V_864:
F_59 ( & V_2 -> V_289 ) ;
V_862:
F_537 ( & V_244 -> V_112 ) ;
return V_248 ;
}
static int F_538 ( struct V_20 * V_21 , int V_258 , int V_259 )
{
struct V_67 * V_67 = F_34 ( V_21 ) ;
V_67 -> V_847 = F_539 ( int , V_258 , V_871 , V_872 ) ;
V_67 -> V_848 = F_539 ( int , V_259 , V_871 , V_872 ) ;
if ( V_67 -> V_68 )
F_295 ( V_21 , V_67 -> V_870 != NULL ) ;
return 0 ;
}
static void F_540 ( struct V_20 * V_21 , T_5 * V_873 , T_5 * V_874 ,
T_5 * V_875 , T_4 V_876 , T_4 V_284 )
{
int V_877 = ( V_876 + V_284 > 256 ) ? 256 : V_876 + V_284 , V_146 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
for ( V_146 = V_876 ; V_146 < V_877 ; V_146 ++ ) {
V_67 -> V_427 [ V_146 ] = V_873 [ V_146 ] >> 8 ;
V_67 -> V_428 [ V_146 ] = V_874 [ V_146 ] >> 8 ;
V_67 -> V_429 [ V_146 ] = V_875 [ V_146 ] >> 8 ;
}
F_286 ( V_21 ) ;
}
struct V_293 *
F_541 ( struct V_1 * V_2 ,
struct V_282 * V_283 ,
struct V_243 * V_244 )
{
struct V_292 * V_294 ;
int V_248 ;
V_294 = F_448 ( sizeof( * V_294 ) , V_689 ) ;
if ( ! V_294 ) {
F_537 ( & V_244 -> V_112 ) ;
return F_542 ( - V_861 ) ;
}
V_248 = F_182 ( V_2 , V_294 , V_283 , V_244 ) ;
if ( V_248 )
goto V_55;
return & V_294 -> V_112 ;
V_55:
F_537 ( & V_244 -> V_112 ) ;
F_186 ( V_294 ) ;
return F_542 ( V_248 ) ;
}
static struct V_293 *
F_543 ( struct V_1 * V_2 ,
struct V_282 * V_283 ,
struct V_243 * V_244 )
{
struct V_293 * V_70 ;
int V_248 ;
V_248 = F_544 ( V_2 ) ;
if ( V_248 )
return F_542 ( V_248 ) ;
V_70 = F_541 ( V_2 , V_283 , V_244 ) ;
F_59 ( & V_2 -> V_289 ) ;
return V_70 ;
}
static T_1
F_545 ( int V_288 , int V_742 )
{
T_1 V_261 = F_477 ( V_288 * V_742 , 8 ) ;
return F_168 ( V_261 , 64 ) ;
}
static T_1
F_546 ( struct V_324 * V_403 , int V_742 )
{
T_1 V_261 = F_545 ( V_403 -> V_506 , V_742 ) ;
return F_168 ( V_261 * V_403 -> V_508 , V_690 ) ;
}
static struct V_293 *
F_547 ( struct V_1 * V_2 ,
struct V_324 * V_403 ,
int V_878 , int V_742 )
{
struct V_243 * V_244 ;
struct V_282 V_283 = { 0 } ;
V_244 = F_548 ( V_2 ,
F_546 ( V_403 , V_742 ) ) ;
if ( V_244 == NULL )
return F_542 ( - V_861 ) ;
V_283 . V_288 = V_403 -> V_506 ;
V_283 . V_240 = V_403 -> V_508 ;
V_283 . V_286 [ 0 ] = F_545 ( V_283 . V_288 ,
V_742 ) ;
V_283 . V_287 = F_549 ( V_742 , V_878 ) ;
return F_543 ( V_2 , & V_283 , V_244 ) ;
}
static struct V_293 *
F_550 ( struct V_1 * V_2 ,
struct V_324 * V_403 )
{
#ifdef F_551
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_243 * V_244 ;
struct V_293 * V_70 ;
if ( ! V_4 -> V_879 )
return NULL ;
if ( ! V_4 -> V_879 -> V_70 )
return NULL ;
V_244 = V_4 -> V_879 -> V_70 -> V_244 ;
F_120 ( ! V_244 ) ;
V_70 = & V_4 -> V_879 -> V_70 -> V_112 ;
if ( V_70 -> V_286 [ 0 ] < F_545 ( V_403 -> V_506 ,
V_70 -> V_305 ) )
return NULL ;
if ( V_244 -> V_112 . V_284 < V_403 -> V_508 * V_70 -> V_286 [ 0 ] )
return NULL ;
return V_70 ;
#else
return NULL ;
#endif
}
bool F_552 ( struct V_514 * V_515 ,
struct V_324 * V_403 ,
struct V_880 * V_881 ,
struct V_882 * V_883 )
{
struct V_67 * V_67 ;
struct V_22 * V_22 =
F_523 ( V_515 ) ;
struct V_20 * V_884 ;
struct V_519 * V_23 = & V_22 -> V_112 ;
struct V_20 * V_21 = NULL ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_293 * V_70 ;
struct V_697 * V_71 = & V_2 -> V_698 ;
int V_248 , V_146 = - 1 ;
F_45 ( L_158 ,
V_515 -> V_112 . V_218 , V_515 -> V_119 ,
V_23 -> V_112 . V_218 , V_23 -> V_119 ) ;
F_553 ( V_883 , 0 ) ;
V_354:
V_248 = F_202 ( & V_71 -> V_885 , V_883 ) ;
if ( V_248 )
goto V_886;
if ( V_23 -> V_21 ) {
V_21 = V_23 -> V_21 ;
V_248 = F_202 ( & V_21 -> V_311 , V_883 ) ;
if ( V_248 )
goto V_886;
V_881 -> V_887 = V_515 -> V_517 ;
V_881 -> V_888 = false ;
if ( V_515 -> V_517 != V_520 )
V_515 -> V_788 -> V_517 ( V_515 , V_520 ) ;
return true ;
}
F_187 (dev, possible_crtc) {
V_146 ++ ;
if ( ! ( V_23 -> V_889 & ( 1 << V_146 ) ) )
continue;
if ( ! V_884 -> V_103 ) {
V_21 = V_884 ;
break;
}
}
if ( ! V_21 ) {
F_45 ( L_159 ) ;
goto V_886;
}
V_248 = F_202 ( & V_21 -> V_311 , V_883 ) ;
if ( V_248 )
goto V_886;
V_22 -> V_890 = F_34 ( V_21 ) ;
F_554 ( V_515 ) -> V_891 = V_22 ;
V_67 = F_34 ( V_21 ) ;
V_67 -> V_491 = true ;
V_67 -> V_492 = & V_67 -> V_71 ;
V_881 -> V_887 = V_515 -> V_517 ;
V_881 -> V_888 = true ;
V_881 -> V_892 = NULL ;
if ( ! V_403 )
V_403 = & V_893 ;
V_70 = F_550 ( V_2 , V_403 ) ;
if ( V_70 == NULL ) {
F_45 ( L_160 ) ;
V_70 = F_547 ( V_2 , V_403 , 24 , 32 ) ;
V_881 -> V_892 = V_70 ;
} else
F_45 ( L_161 ) ;
if ( F_555 ( V_70 ) ) {
F_45 ( L_162 ) ;
goto V_862;
}
if ( F_556 ( V_21 , V_403 , 0 , 0 , V_70 ) ) {
F_45 ( L_163 ) ;
if ( V_881 -> V_892 )
V_881 -> V_892 -> V_788 -> V_894 ( V_881 -> V_892 ) ;
goto V_862;
}
F_41 ( V_2 , V_67 -> V_75 ) ;
return true ;
V_862:
V_67 -> V_491 = V_21 -> V_103 ;
if ( V_67 -> V_491 )
V_67 -> V_492 = & V_67 -> V_71 ;
else
V_67 -> V_492 = NULL ;
V_886:
if ( V_248 == - V_895 ) {
F_557 ( V_883 ) ;
goto V_354;
}
F_558 ( V_883 ) ;
F_559 ( V_883 ) ;
return false ;
}
void F_560 ( struct V_514 * V_515 ,
struct V_880 * V_881 ,
struct V_882 * V_883 )
{
struct V_22 * V_22 =
F_523 ( V_515 ) ;
struct V_519 * V_23 = & V_22 -> V_112 ;
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
F_45 ( L_158 ,
V_515 -> V_112 . V_218 , V_515 -> V_119 ,
V_23 -> V_112 . V_218 , V_23 -> V_119 ) ;
if ( V_881 -> V_888 ) {
F_554 ( V_515 ) -> V_891 = NULL ;
V_22 -> V_890 = NULL ;
V_67 -> V_491 = false ;
V_67 -> V_492 = NULL ;
F_556 ( V_21 , NULL , 0 , 0 , NULL ) ;
if ( V_881 -> V_892 ) {
F_561 ( V_881 -> V_892 ) ;
F_562 ( V_881 -> V_892 ) ;
}
goto V_896;
return;
}
if ( V_881 -> V_887 != V_520 )
V_515 -> V_788 -> V_517 ( V_515 , V_881 -> V_887 ) ;
V_896:
F_558 ( V_883 ) ;
F_559 ( V_883 ) ;
}
static int F_563 ( struct V_1 * V_2 ,
const struct V_446 * V_447 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_48 = V_447 -> V_199 . V_48 ;
if ( ( V_48 & V_897 ) == V_638 )
return V_4 -> V_571 . V_575 ;
else if ( F_3 ( V_2 ) )
return 120000 ;
else if ( ! F_19 ( V_2 ) )
return 96000 ;
else
return 48000 ;
}
static void F_452 ( struct V_67 * V_21 ,
struct V_446 * V_447 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_75 = V_447 -> V_77 ;
T_1 V_48 = V_447 -> V_199 . V_48 ;
T_1 V_577 ;
T_2 clock ;
int V_10 = F_563 ( V_2 , V_447 ) ;
if ( ( V_48 & V_898 ) == 0 )
V_577 = V_447 -> V_199 . V_497 ;
else
V_577 = V_447 -> V_199 . V_498 ;
clock . V_12 = ( V_577 & V_899 ) >> V_900 ;
if ( F_16 ( V_2 ) ) {
clock . V_17 = F_564 ( ( V_577 & V_901 ) >> V_902 ) - 1 ;
clock . V_13 = ( V_577 & V_903 ) >> V_904 ;
} else {
clock . V_17 = ( V_577 & V_905 ) >> V_902 ;
clock . V_13 = ( V_577 & V_906 ) >> V_904 ;
}
if ( ! F_19 ( V_2 ) ) {
if ( F_16 ( V_2 ) )
clock . V_15 = F_564 ( ( V_48 & V_907 ) >>
V_628 ) ;
else
clock . V_15 = F_564 ( ( V_48 & V_908 ) >>
V_629 ) ;
switch ( V_48 & V_909 ) {
case V_625 :
clock . V_16 = V_48 & V_631 ?
5 : 10 ;
break;
case V_624 :
clock . V_16 = V_48 & V_632 ?
7 : 14 ;
break;
default:
F_45 ( L_164
L_165 , ( int ) ( V_48 & V_909 ) ) ;
return;
}
if ( F_16 ( V_2 ) )
F_20 ( V_10 , & clock ) ;
else
F_22 ( V_10 , & clock ) ;
} else {
T_1 V_910 = F_122 ( V_2 ) ? 0 : F_4 ( V_133 ) ;
bool V_678 = ( V_75 == 1 ) && ( V_910 & V_170 ) ;
if ( V_678 ) {
clock . V_15 = F_564 ( ( V_48 & V_911 ) >>
V_629 ) ;
if ( V_910 & V_912 )
clock . V_16 = 7 ;
else
clock . V_16 = 14 ;
} else {
if ( V_48 & V_640 )
clock . V_15 = 2 ;
else {
clock . V_15 = ( ( V_48 & V_913 ) >>
V_629 ) + 2 ;
}
if ( V_48 & V_641 )
clock . V_16 = 4 ;
else
clock . V_16 = 2 ;
}
F_22 ( V_10 , & clock ) ;
}
V_447 -> V_607 = clock . V_19 ;
}
int F_565 ( int V_914 ,
const struct V_563 * V_564 )
{
if ( ! V_564 -> V_569 )
return 0 ;
return F_31 ( ( V_915 ) V_564 -> V_568 * V_914 , V_564 -> V_569 ) ;
}
static void F_490 ( struct V_67 * V_21 ,
struct V_446 * V_447 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
F_452 ( V_21 , V_447 ) ;
V_447 -> V_72 . V_73 =
F_565 ( F_5 ( V_2 ) * 10000 ,
& V_447 -> V_438 ) ;
}
struct V_324 * F_566 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
enum V_74 V_77 = V_67 -> V_71 . V_77 ;
struct V_324 * V_403 ;
struct V_446 V_447 ;
int V_916 = F_4 ( F_249 ( V_77 ) ) ;
int V_917 = F_4 ( F_253 ( V_77 ) ) ;
int V_918 = F_4 ( F_255 ( V_77 ) ) ;
int V_919 = F_4 ( F_259 ( V_77 ) ) ;
enum V_75 V_75 = V_67 -> V_75 ;
V_403 = F_448 ( sizeof( * V_403 ) , V_689 ) ;
if ( ! V_403 )
return NULL ;
V_447 . V_77 = (enum V_74 ) V_75 ;
V_447 . V_587 = 1 ;
V_447 . V_199 . V_48 = F_4 ( F_55 ( V_75 ) ) ;
V_447 . V_199 . V_497 = F_4 ( F_361 ( V_75 ) ) ;
V_447 . V_199 . V_498 = F_4 ( F_362 ( V_75 ) ) ;
F_452 ( V_67 , & V_447 ) ;
V_403 -> clock = V_447 . V_607 / V_447 . V_587 ;
V_403 -> V_506 = ( V_916 & 0xffff ) + 1 ;
V_403 -> V_657 = ( ( V_916 & 0xffff0000 ) >> 16 ) + 1 ;
V_403 -> V_535 = ( V_917 & 0xffff ) + 1 ;
V_403 -> V_658 = ( ( V_917 & 0xffff0000 ) >> 16 ) + 1 ;
V_403 -> V_508 = ( V_918 & 0xffff ) + 1 ;
V_403 -> V_659 = ( ( V_918 & 0xffff0000 ) >> 16 ) + 1 ;
V_403 -> V_660 = ( V_919 & 0xffff ) + 1 ;
V_403 -> V_661 = ( ( V_919 & 0xffff0000 ) >> 16 ) + 1 ;
F_567 ( V_403 ) ;
return V_403 ;
}
static void F_198 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
int V_75 = V_67 -> V_75 ;
int V_210 = F_55 ( V_75 ) ;
int V_48 ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_681 )
return;
V_48 = F_4 ( V_210 ) ;
if ( ! F_443 ( V_2 ) && ( V_48 & V_898 ) ) {
F_63 ( L_166 ) ;
F_72 ( V_4 , V_75 ) ;
V_48 &= ~ V_898 ;
F_44 ( V_210 , V_48 ) ;
F_41 ( V_2 , V_75 ) ;
V_48 = F_4 ( V_210 ) ;
if ( V_48 & V_898 )
F_63 ( L_167 ) ;
}
}
static void F_568 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_681 )
return;
if ( ! F_443 ( V_2 ) && V_67 -> V_579 ) {
int V_75 = V_67 -> V_75 ;
int V_210 = F_55 ( V_75 ) ;
int V_48 ;
F_63 ( L_168 ) ;
F_72 ( V_4 , V_75 ) ;
V_48 = F_4 ( V_210 ) ;
V_48 |= V_898 ;
F_44 ( V_210 , V_48 ) ;
F_41 ( V_2 , V_75 ) ;
V_48 = F_4 ( V_210 ) ;
if ( ! ( V_48 & V_898 ) )
F_63 ( L_169 ) ;
}
}
void F_569 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_254 . V_920 )
return;
F_570 ( V_4 ) ;
F_571 ( V_4 ) ;
V_4 -> V_254 . V_920 = true ;
}
void F_572 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 ;
if ( ! V_4 -> V_254 . V_920 )
return;
V_4 -> V_254 . V_920 = false ;
if ( ! V_322 . V_580 )
goto V_921;
F_187 (dev, crtc) {
if ( ! V_21 -> V_69 -> V_70 )
continue;
F_568 ( V_21 ) ;
}
if ( F_43 ( V_2 ) -> V_81 >= 6 )
F_573 ( V_2 -> V_5 ) ;
V_921:
F_574 ( V_4 ) ;
}
void F_575 ( struct V_243 * V_244 ,
struct V_245 * V_922 )
{
struct V_1 * V_2 = V_244 -> V_112 . V_2 ;
struct V_20 * V_21 ;
if ( ! V_322 . V_580 )
return;
F_187 (dev, crtc) {
if ( ! V_21 -> V_69 -> V_70 )
continue;
if ( F_183 ( V_21 -> V_69 -> V_70 ) -> V_244 != V_244 )
continue;
F_198 ( V_21 ) ;
if ( V_922 && F_576 ( V_2 ) )
V_922 -> V_923 = true ;
}
}
static void F_577 ( struct V_20 * V_21 )
{
struct V_67 * V_67 = F_34 ( V_21 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_924 * V_925 ;
unsigned long V_314 ;
F_209 ( & V_2 -> V_318 , V_314 ) ;
V_925 = V_67 -> V_319 ;
V_67 -> V_319 = NULL ;
F_210 ( & V_2 -> V_318 , V_314 ) ;
if ( V_925 ) {
F_578 ( & V_925 -> V_925 ) ;
F_186 ( V_925 ) ;
}
F_531 ( V_21 , NULL , 0 , 0 , 0 ) ;
F_579 ( V_21 ) ;
F_186 ( V_67 ) ;
}
static void F_580 ( struct V_926 * V_927 )
{
struct V_924 * V_925 =
F_581 ( V_927 , struct V_924 , V_925 ) ;
struct V_1 * V_2 = V_925 -> V_21 -> V_2 ;
F_57 ( & V_2 -> V_289 ) ;
F_176 ( V_925 -> V_928 ) ;
F_184 ( & V_925 -> V_929 -> V_112 ) ;
F_184 ( & V_925 -> V_928 -> V_112 ) ;
F_216 ( V_2 ) ;
F_59 ( & V_2 -> V_289 ) ;
F_120 ( F_208 ( & F_34 ( V_925 -> V_21 ) -> V_369 ) == 0 ) ;
F_582 ( & F_34 ( V_925 -> V_21 ) -> V_369 ) ;
F_186 ( V_925 ) ;
}
static void F_583 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
struct V_924 * V_925 ;
unsigned long V_314 ;
if ( V_67 == NULL )
return;
F_209 ( & V_2 -> V_318 , V_314 ) ;
V_925 = V_67 -> V_319 ;
F_584 () ;
if ( V_925 == NULL || F_208 ( & V_925 -> V_315 ) < V_930 ) {
F_210 ( & V_2 -> V_318 , V_314 ) ;
return;
}
F_584 () ;
V_67 -> V_319 = NULL ;
if ( V_925 -> V_931 )
F_585 ( V_2 , V_67 -> V_75 , V_925 -> V_931 ) ;
F_586 ( V_21 ) ;
F_210 ( & V_2 -> V_318 , V_314 ) ;
F_587 ( & V_4 -> V_370 ) ;
F_588 ( V_4 -> V_932 , & V_925 -> V_925 ) ;
F_589 ( V_67 -> V_144 , V_925 -> V_929 ) ;
}
void F_590 ( struct V_1 * V_2 , int V_75 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 = V_4 -> V_76 [ V_75 ] ;
F_583 ( V_2 , V_21 ) ;
}
void F_201 ( struct V_1 * V_2 , int V_144 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 = V_4 -> V_933 [ V_144 ] ;
F_583 ( V_2 , V_21 ) ;
}
static bool F_591 ( T_1 V_934 , T_1 V_935 )
{
return ! ( ( V_934 - V_935 ) & 0x80000000 ) ;
}
static bool F_592 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_43 ( V_2 ) -> V_81 < 5 && ! F_15 ( V_2 ) )
return true ;
return ( F_4 ( F_593 ( V_21 -> V_144 ) ) & ~ 0xfff ) ==
V_21 -> V_319 -> V_936 &&
F_591 ( F_4 ( F_594 ( V_21 -> V_75 ) ) ,
V_21 -> V_319 -> V_937 ) ;
}
void F_200 ( struct V_1 * V_2 , int V_144 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 =
F_34 ( V_4 -> V_933 [ V_144 ] ) ;
unsigned long V_314 ;
F_209 ( & V_2 -> V_318 , V_314 ) ;
if ( V_67 -> V_319 && F_592 ( V_67 ) )
F_595 ( & V_67 -> V_319 -> V_315 ) ;
F_210 ( & V_2 -> V_318 , V_314 ) ;
}
static inline void F_596 ( struct V_67 * V_67 )
{
F_597 () ;
F_598 ( & V_67 -> V_319 -> V_315 , V_938 ) ;
F_597 () ;
}
static int F_599 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_293 * V_70 ,
struct V_243 * V_244 ,
struct V_245 * V_922 ,
T_4 V_314 )
{
struct V_67 * V_67 = F_34 ( V_21 ) ;
T_1 V_939 ;
int V_248 ;
V_248 = F_600 ( V_922 , 6 ) ;
if ( V_248 )
return V_248 ;
if ( V_67 -> V_144 )
V_939 = V_940 ;
else
V_939 = V_941 ;
F_601 ( V_922 , V_942 | V_939 ) ;
F_601 ( V_922 , V_943 ) ;
F_601 ( V_922 , V_944 |
F_602 ( V_67 -> V_144 ) ) ;
F_601 ( V_922 , V_70 -> V_286 [ 0 ] ) ;
F_601 ( V_922 , V_67 -> V_319 -> V_936 ) ;
F_601 ( V_922 , 0 ) ;
F_596 ( V_67 ) ;
F_603 ( V_922 ) ;
return 0 ;
}
static int F_604 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_293 * V_70 ,
struct V_243 * V_244 ,
struct V_245 * V_922 ,
T_4 V_314 )
{
struct V_67 * V_67 = F_34 ( V_21 ) ;
T_1 V_939 ;
int V_248 ;
V_248 = F_600 ( V_922 , 6 ) ;
if ( V_248 )
return V_248 ;
if ( V_67 -> V_144 )
V_939 = V_940 ;
else
V_939 = V_941 ;
F_601 ( V_922 , V_942 | V_939 ) ;
F_601 ( V_922 , V_943 ) ;
F_601 ( V_922 , V_945 |
F_602 ( V_67 -> V_144 ) ) ;
F_601 ( V_922 , V_70 -> V_286 [ 0 ] ) ;
F_601 ( V_922 , V_67 -> V_319 -> V_936 ) ;
F_601 ( V_922 , V_943 ) ;
F_596 ( V_67 ) ;
F_603 ( V_922 ) ;
return 0 ;
}
static int F_605 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_293 * V_70 ,
struct V_243 * V_244 ,
struct V_245 * V_922 ,
T_4 V_314 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
T_4 V_946 , V_947 ;
int V_248 ;
V_248 = F_600 ( V_922 , 4 ) ;
if ( V_248 )
return V_248 ;
F_601 ( V_922 , V_944 |
F_602 ( V_67 -> V_144 ) ) ;
F_601 ( V_922 , V_70 -> V_286 [ 0 ] ) ;
F_601 ( V_922 , V_67 -> V_319 -> V_936 |
V_244 -> V_249 ) ;
V_946 = 0 ;
V_947 = F_4 ( F_212 ( V_67 -> V_75 ) ) & 0x0fff0fff ;
F_601 ( V_922 , V_946 | V_947 ) ;
F_596 ( V_67 ) ;
F_603 ( V_922 ) ;
return 0 ;
}
static int F_606 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_293 * V_70 ,
struct V_243 * V_244 ,
struct V_245 * V_922 ,
T_4 V_314 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
T_4 V_946 , V_947 ;
int V_248 ;
V_248 = F_600 ( V_922 , 4 ) ;
if ( V_248 )
return V_248 ;
F_601 ( V_922 , V_944 |
F_602 ( V_67 -> V_144 ) ) ;
F_601 ( V_922 , V_70 -> V_286 [ 0 ] | V_244 -> V_249 ) ;
F_601 ( V_922 , V_67 -> V_319 -> V_936 ) ;
V_946 = 0 ;
V_947 = F_4 ( F_212 ( V_67 -> V_75 ) ) & 0x0fff0fff ;
F_601 ( V_922 , V_946 | V_947 ) ;
F_596 ( V_67 ) ;
F_603 ( V_922 ) ;
return 0 ;
}
static int F_607 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_293 * V_70 ,
struct V_243 * V_244 ,
struct V_245 * V_922 ,
T_4 V_314 )
{
struct V_67 * V_67 = F_34 ( V_21 ) ;
T_4 V_948 = 0 ;
int V_812 , V_248 ;
switch ( V_67 -> V_144 ) {
case V_949 :
V_948 = V_950 ;
break;
case V_951 :
V_948 = V_952 ;
break;
case V_953 :
V_948 = V_954 ;
break;
default:
F_608 ( 1 , L_170 ) ;
return - V_955 ;
}
V_812 = 4 ;
if ( V_922 -> V_218 == V_956 ) {
V_812 += 6 ;
if ( F_609 ( V_2 ) )
V_812 += 2 ;
}
V_248 = F_610 ( V_922 ) ;
if ( V_248 )
return V_248 ;
V_248 = F_600 ( V_922 , V_812 ) ;
if ( V_248 )
return V_248 ;
if ( V_922 -> V_218 == V_956 ) {
F_601 ( V_922 , F_611 ( 1 ) ) ;
F_601 ( V_922 , V_957 ) ;
F_601 ( V_922 , ~ ( V_958 |
V_959 |
V_960 ) ) ;
if ( F_609 ( V_2 ) )
F_601 ( V_922 , F_612 ( 1 ) |
V_961 ) ;
else
F_601 ( V_922 , F_613 ( 1 ) |
V_961 ) ;
F_601 ( V_922 , V_957 ) ;
F_601 ( V_922 , V_922 -> V_962 . V_936 + 256 ) ;
if ( F_609 ( V_2 ) ) {
F_601 ( V_922 , 0 ) ;
F_601 ( V_922 , V_943 ) ;
}
}
F_601 ( V_922 , V_945 | V_948 ) ;
F_601 ( V_922 , ( V_70 -> V_286 [ 0 ] | V_244 -> V_249 ) ) ;
F_601 ( V_922 , V_67 -> V_319 -> V_936 ) ;
F_601 ( V_922 , ( V_943 ) ) ;
F_596 ( V_67 ) ;
F_603 ( V_922 ) ;
return 0 ;
}
static int F_614 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_293 * V_70 ,
struct V_243 * V_244 ,
struct V_245 * V_922 ,
T_4 V_314 )
{
return - V_955 ;
}
static int F_615 ( struct V_20 * V_21 ,
struct V_293 * V_70 ,
struct V_963 * V_931 ,
T_4 V_964 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_293 * V_312 = V_21 -> V_69 -> V_70 ;
struct V_243 * V_244 = F_183 ( V_70 ) -> V_244 ;
struct V_67 * V_67 = F_34 ( V_21 ) ;
struct V_924 * V_925 ;
struct V_245 * V_922 ;
unsigned long V_314 ;
int V_248 ;
if ( V_70 -> V_287 != V_21 -> V_69 -> V_70 -> V_287 )
return - V_253 ;
if ( F_43 ( V_2 ) -> V_81 > 3 &&
( V_70 -> V_965 [ 0 ] != V_21 -> V_69 -> V_70 -> V_965 [ 0 ] ||
V_70 -> V_286 [ 0 ] != V_21 -> V_69 -> V_70 -> V_286 [ 0 ] ) )
return - V_253 ;
if ( F_616 ( & V_4 -> V_316 ) )
goto V_966;
V_925 = F_448 ( sizeof( * V_925 ) , V_689 ) ;
if ( V_925 == NULL )
return - V_861 ;
V_925 -> V_931 = V_931 ;
V_925 -> V_21 = V_21 ;
V_925 -> V_928 = F_183 ( V_312 ) -> V_244 ;
F_617 ( & V_925 -> V_925 , F_580 ) ;
V_248 = F_618 ( V_21 ) ;
if ( V_248 )
goto V_967;
F_209 ( & V_2 -> V_318 , V_314 ) ;
if ( V_67 -> V_319 ) {
F_210 ( & V_2 -> V_318 , V_314 ) ;
F_186 ( V_925 ) ;
F_586 ( V_21 ) ;
F_63 ( L_171 ) ;
return - V_320 ;
}
V_67 -> V_319 = V_925 ;
F_210 ( & V_2 -> V_318 , V_314 ) ;
if ( F_208 ( & V_67 -> V_369 ) >= 2 )
F_619 ( V_4 -> V_932 ) ;
V_248 = F_544 ( V_2 ) ;
if ( V_248 )
goto V_968;
F_620 ( & V_925 -> V_928 -> V_112 ) ;
F_620 ( & V_244 -> V_112 ) ;
V_21 -> V_69 -> V_70 = V_70 ;
V_925 -> V_929 = V_244 ;
V_925 -> V_969 = true ;
F_621 ( & V_67 -> V_369 ) ;
V_67 -> V_317 = F_208 ( & V_4 -> V_316 . V_317 ) ;
if ( F_43 ( V_2 ) -> V_81 >= 5 || F_15 ( V_2 ) )
V_925 -> V_937 = F_4 ( F_594 ( V_67 -> V_75 ) ) + 1 ;
if ( F_18 ( V_2 ) ) {
V_922 = & V_4 -> V_922 [ V_970 ] ;
} else if ( F_43 ( V_2 ) -> V_81 >= 7 ) {
V_922 = V_244 -> V_922 ;
if ( V_922 == NULL || V_922 -> V_218 != V_956 )
V_922 = & V_4 -> V_922 [ V_970 ] ;
} else {
V_922 = & V_4 -> V_922 [ V_956 ] ;
}
V_248 = F_169 ( V_2 , V_244 , V_922 ) ;
if ( V_248 )
goto V_971;
V_925 -> V_936 =
F_188 ( V_244 ) + V_67 -> V_306 ;
V_248 = V_4 -> V_308 . V_972 ( V_2 , V_21 , V_70 , V_244 , V_922 , V_964 ) ;
if ( V_248 )
goto V_973;
F_298 ( V_2 ) ;
F_575 ( V_244 , NULL ) ;
F_59 ( & V_2 -> V_289 ) ;
F_622 ( V_67 -> V_144 , V_244 ) ;
return 0 ;
V_973:
F_176 ( V_244 ) ;
V_971:
F_582 ( & V_67 -> V_369 ) ;
V_21 -> V_69 -> V_70 = V_312 ;
F_184 ( & V_925 -> V_928 -> V_112 ) ;
F_184 ( & V_244 -> V_112 ) ;
F_59 ( & V_2 -> V_289 ) ;
V_968:
F_209 ( & V_2 -> V_318 , V_314 ) ;
V_67 -> V_319 = NULL ;
F_210 ( & V_2 -> V_318 , V_314 ) ;
F_586 ( V_21 ) ;
V_967:
F_186 ( V_925 ) ;
if ( V_248 == - V_974 ) {
V_966:
F_237 ( V_21 ) ;
V_248 = F_211 ( V_21 , V_21 -> V_258 , V_21 -> V_259 , V_70 ) ;
if ( V_248 == 0 && V_931 )
F_585 ( V_2 , V_67 -> V_75 , V_931 ) ;
}
return V_248 ;
}
static void F_623 ( struct V_1 * V_2 )
{
struct V_67 * V_21 ;
struct V_22 * V_23 ;
struct V_521 * V_515 ;
F_371 (connector, &dev->mode_config.connector_list,
base.head) {
V_515 -> V_891 =
F_372 ( V_515 -> V_112 . V_23 ) ;
}
F_371 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_23 -> V_890 =
F_34 ( V_23 -> V_112 . V_21 ) ;
}
F_236 (dev, crtc) {
V_21 -> V_491 = V_21 -> V_112 . V_103 ;
if ( V_21 -> V_491 )
V_21 -> V_492 = & V_21 -> V_71 ;
else
V_21 -> V_492 = NULL ;
}
}
static void F_624 ( struct V_1 * V_2 )
{
struct V_67 * V_21 ;
struct V_22 * V_23 ;
struct V_521 * V_515 ;
F_371 (connector, &dev->mode_config.connector_list,
base.head) {
V_515 -> V_112 . V_23 = & V_515 -> V_891 -> V_112 ;
}
F_371 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_23 -> V_112 . V_21 = & V_23 -> V_890 -> V_112 ;
}
F_236 (dev, crtc) {
V_21 -> V_112 . V_103 = V_21 -> V_491 ;
}
}
static void
F_625 ( struct V_521 * V_515 ,
struct V_446 * V_447 )
{
int V_742 = V_447 -> V_528 ;
F_45 ( L_172 ,
V_515 -> V_112 . V_112 . V_218 ,
V_515 -> V_112 . V_119 ) ;
if ( V_515 -> V_112 . V_975 . V_398 &&
V_515 -> V_112 . V_975 . V_398 * 3 < V_742 ) {
F_45 ( L_173 ,
V_742 , V_515 -> V_112 . V_975 . V_398 * 3 ) ;
V_447 -> V_528 = V_515 -> V_112 . V_975 . V_398 * 3 ;
}
if ( V_515 -> V_112 . V_975 . V_398 == 0 && V_742 > 24 ) {
F_45 ( L_174 ,
V_742 ) ;
V_447 -> V_528 = 24 ;
}
}
static int
F_626 ( struct V_67 * V_21 ,
struct V_293 * V_70 ,
struct V_446 * V_447 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_521 * V_515 ;
int V_742 ;
switch ( V_70 -> V_287 ) {
case V_267 :
V_742 = 8 * 3 ;
break;
case V_269 :
case V_298 :
if ( F_2 ( F_43 ( V_2 ) -> V_81 > 3 ) )
return - V_253 ;
case V_271 :
V_742 = 6 * 3 ;
break;
case V_275 :
case V_300 :
if ( F_2 ( F_43 ( V_2 ) -> V_81 < 4 ) )
return - V_253 ;
case V_273 :
case V_299 :
V_742 = 8 * 3 ;
break;
case V_277 :
case V_301 :
case V_279 :
case V_302 :
if ( F_2 ( F_43 ( V_2 ) -> V_81 < 4 ) )
return - V_253 ;
V_742 = 10 * 3 ;
break;
default:
F_45 ( L_175 ) ;
return - V_253 ;
}
V_447 -> V_528 = V_742 ;
F_371 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_515 -> V_891 ||
V_515 -> V_891 -> V_890 != V_21 )
continue;
F_625 ( V_515 , V_447 ) ;
}
return V_742 ;
}
static void F_627 ( const struct V_324 * V_403 )
{
F_45 ( L_176
L_177 ,
V_403 -> V_73 ,
V_403 -> V_325 , V_403 -> V_648 ,
V_403 -> V_651 , V_403 -> V_647 ,
V_403 -> V_326 , V_403 -> V_653 ,
V_403 -> V_654 , V_403 -> V_643 , V_403 -> type , V_403 -> V_314 ) ;
}
static void F_628 ( struct V_67 * V_21 ,
struct V_446 * V_447 ,
const char * V_976 )
{
F_45 ( L_178 , V_21 -> V_112 . V_112 . V_218 ,
V_976 , F_73 ( V_21 -> V_75 ) ) ;
F_45 ( L_179 , F_629 ( V_447 -> V_77 ) ) ;
F_45 ( L_180 ,
V_447 -> V_528 , V_447 -> V_664 ) ;
F_45 ( L_181 ,
V_447 -> V_237 ,
V_447 -> V_349 ,
V_447 -> V_438 . V_566 , V_447 -> V_438 . V_567 ,
V_447 -> V_438 . V_568 , V_447 -> V_438 . V_569 ,
V_447 -> V_438 . V_565 ) ;
F_45 ( L_182 ,
V_447 -> V_437 ,
V_447 -> V_583 . V_566 , V_447 -> V_583 . V_567 ,
V_447 -> V_583 . V_568 , V_447 -> V_583 . V_569 ,
V_447 -> V_583 . V_565 ) ;
F_45 ( L_183 ) ;
F_630 ( & V_447 -> V_656 ) ;
F_45 ( L_184 ) ;
F_630 ( & V_447 -> V_72 ) ;
F_627 ( & V_447 -> V_72 ) ;
F_45 ( L_185 , V_447 -> V_607 ) ;
F_45 ( L_186 ,
V_447 -> V_329 , V_447 -> V_330 ) ;
F_45 ( L_187 ,
V_447 -> V_448 . V_449 ,
V_447 -> V_448 . V_453 ,
V_447 -> V_448 . V_685 ) ;
F_45 ( L_188 ,
V_447 -> V_327 . V_414 ,
V_447 -> V_327 . V_284 ,
V_447 -> V_327 . V_103 ? L_189 : L_190 ) ;
F_45 ( L_191 , V_447 -> V_417 ) ;
F_45 ( L_192 , V_447 -> V_534 ) ;
}
static bool F_631 ( const struct V_22 * V_934 ,
const struct V_22 * V_935 )
{
return V_934 == V_935 || ( V_934 -> V_977 & ( 1 << V_935 -> type ) &&
V_935 -> V_977 & ( 1 << V_934 -> type ) ) ;
}
static bool F_632 ( struct V_67 * V_21 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_22 * V_978 ;
F_371 (source_encoder,
&dev->mode_config.encoder_list, base.head) {
if ( V_978 -> V_890 != V_21 )
continue;
if ( ! F_631 ( V_23 , V_978 ) )
return false ;
}
return true ;
}
static bool F_633 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_22 * V_23 ;
F_371 (encoder,
&dev->mode_config.encoder_list, base.head) {
if ( V_23 -> V_890 != V_21 )
continue;
if ( ! F_632 ( V_21 , V_23 ) )
return false ;
}
return true ;
}
static struct V_446 *
F_634 ( struct V_20 * V_21 ,
struct V_293 * V_70 ,
struct V_324 * V_403 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_22 * V_23 ;
struct V_446 * V_447 ;
int V_979 , V_248 = - V_253 ;
bool V_354 = true ;
if ( ! F_633 ( F_34 ( V_21 ) ) ) {
F_45 ( L_193 ) ;
return F_542 ( - V_253 ) ;
}
V_447 = F_448 ( sizeof( * V_447 ) , V_689 ) ;
if ( ! V_447 )
return F_542 ( - V_861 ) ;
F_635 ( & V_447 -> V_72 , V_403 ) ;
F_635 ( & V_447 -> V_656 , V_403 ) ;
V_447 -> V_77 =
(enum V_74 ) F_34 ( V_21 ) -> V_75 ;
V_447 -> V_113 = V_408 ;
if ( ! ( V_447 -> V_72 . V_314 &
( V_404 | V_980 ) ) )
V_447 -> V_72 . V_314 |= V_980 ;
if ( ! ( V_447 -> V_72 . V_314 &
( V_406 | V_981 ) ) )
V_447 -> V_72 . V_314 |= V_981 ;
V_979 = F_626 ( F_34 ( V_21 ) ,
V_70 , V_447 ) ;
if ( V_979 < 0 )
goto V_862;
F_636 ( & V_447 -> V_656 , V_982 ) ;
V_447 -> V_329 = V_447 -> V_656 . V_325 ;
V_447 -> V_330 = V_447 -> V_656 . V_326 ;
V_983:
V_447 -> V_607 = 0 ;
V_447 -> V_587 = 1 ;
F_636 ( & V_447 -> V_72 , V_982 ) ;
F_371 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( & V_23 -> V_890 -> V_112 != V_21 )
continue;
if ( ! ( V_23 -> V_984 ( V_23 , V_447 ) ) ) {
F_45 ( L_194 ) ;
goto V_862;
}
}
if ( ! V_447 -> V_607 )
V_447 -> V_607 = V_447 -> V_72 . V_73
* V_447 -> V_587 ;
V_248 = F_387 ( F_34 ( V_21 ) , V_447 ) ;
if ( V_248 < 0 ) {
F_45 ( L_195 ) ;
goto V_862;
}
if ( V_248 == V_530 ) {
if ( F_40 ( ! V_354 , L_196 ) ) {
V_248 = - V_253 ;
goto V_862;
}
F_45 ( L_197 ) ;
V_354 = false ;
goto V_983;
}
V_447 -> V_664 = V_447 -> V_528 != V_979 ;
F_45 ( L_198 ,
V_979 , V_447 -> V_528 , V_447 -> V_664 ) ;
return V_447 ;
V_862:
F_186 ( V_447 ) ;
return F_542 ( V_248 ) ;
}
static void
F_637 ( struct V_20 * V_21 , unsigned * V_985 ,
unsigned * V_493 , unsigned * V_986 )
{
struct V_67 * V_67 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_22 * V_23 ;
struct V_521 * V_515 ;
struct V_20 * V_987 ;
* V_986 = * V_985 = * V_493 = 0 ;
F_371 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_515 -> V_112 . V_23 == & V_515 -> V_891 -> V_112 )
continue;
if ( V_515 -> V_112 . V_23 ) {
V_987 = V_515 -> V_112 . V_23 -> V_21 ;
* V_493 |= 1 << F_34 ( V_987 ) -> V_75 ;
}
if ( V_515 -> V_891 )
* V_493 |=
1 << V_515 -> V_891 -> V_890 -> V_75 ;
}
F_371 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_23 -> V_112 . V_21 == & V_23 -> V_890 -> V_112 )
continue;
if ( V_23 -> V_112 . V_21 ) {
V_987 = V_23 -> V_112 . V_21 ;
* V_493 |= 1 << F_34 ( V_987 ) -> V_75 ;
}
if ( V_23 -> V_890 )
* V_493 |= 1 << V_23 -> V_890 -> V_75 ;
}
F_236 (dev, intel_crtc) {
if ( V_67 -> V_112 . V_103 == V_67 -> V_491 )
continue;
if ( ! V_67 -> V_491 )
* V_986 |= 1 << V_67 -> V_75 ;
else
* V_493 |= 1 << V_67 -> V_75 ;
}
V_67 = F_34 ( V_21 ) ;
if ( V_67 -> V_491 )
* V_493 |= 1 << V_67 -> V_75 ;
if ( * V_493 )
* V_985 = * V_493 ;
* V_985 &= ~ ( * V_986 ) ;
* V_493 &= ~ ( * V_986 ) ;
* V_985 &= 1 << V_67 -> V_75 ;
* V_493 &= 1 << V_67 -> V_75 ;
F_45 ( L_199 ,
* V_985 , * V_493 , * V_986 ) ;
}
static bool F_638 ( struct V_20 * V_21 )
{
struct V_519 * V_23 ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_371 (encoder, &dev->mode_config.encoder_list, head)
if ( V_23 -> V_21 == V_21 )
return true ;
return false ;
}
static void
F_639 ( struct V_1 * V_2 , unsigned V_493 )
{
struct V_22 * V_22 ;
struct V_67 * V_67 ;
struct V_514 * V_515 ;
F_371 (intel_encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_22 -> V_112 . V_21 )
continue;
V_67 = F_34 ( V_22 -> V_112 . V_21 ) ;
if ( V_493 & ( 1 << V_67 -> V_75 ) )
V_22 -> V_511 = false ;
}
F_624 ( V_2 ) ;
F_236 (dev, intel_crtc) {
F_2 ( V_67 -> V_112 . V_103 != F_638 ( & V_67 -> V_112 ) ) ;
F_2 ( V_67 -> V_492 &&
V_67 -> V_492 != & V_67 -> V_71 ) ;
F_2 ( V_67 -> V_112 . V_103 != ! ! V_67 -> V_492 ) ;
}
F_371 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_515 -> V_23 || ! V_515 -> V_23 -> V_21 )
continue;
V_67 = F_34 ( V_515 -> V_23 -> V_21 ) ;
if ( V_493 & ( 1 << V_67 -> V_75 ) ) {
struct V_988 * V_989 =
V_2 -> V_698 . V_989 ;
V_515 -> V_517 = V_520 ;
F_640 ( & V_515 -> V_112 ,
V_989 ,
V_520 ) ;
V_22 = F_372 ( V_515 -> V_23 ) ;
V_22 -> V_511 = true ;
}
}
}
static bool F_641 ( int V_990 , int V_991 )
{
int V_65 ;
if ( V_990 == V_991 )
return true ;
if ( ! V_990 || ! V_991 )
return false ;
V_65 = abs ( V_990 - V_991 ) ;
if ( ( ( ( ( V_65 + V_990 + V_991 ) * 100 ) ) / ( V_990 + V_991 ) ) < 105 )
return true ;
return false ;
}
static bool
F_642 ( struct V_1 * V_2 ,
struct V_446 * V_992 ,
struct V_446 * V_447 )
{
#define F_643 ( V_119 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_644 ( V_119 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_645 ( V_119 , V_466 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
DRM_ERROR("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
return false; \
}
#define F_646 ( V_119 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_647 ( T_8 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_644 ( V_77 ) ;
F_644 ( V_237 ) ;
F_644 ( V_349 ) ;
F_644 ( V_438 . V_566 ) ;
F_644 ( V_438 . V_567 ) ;
F_644 ( V_438 . V_568 ) ;
F_644 ( V_438 . V_569 ) ;
F_644 ( V_438 . V_565 ) ;
F_644 ( V_437 ) ;
F_644 ( V_583 . V_566 ) ;
F_644 ( V_583 . V_567 ) ;
F_644 ( V_583 . V_568 ) ;
F_644 ( V_583 . V_569 ) ;
F_644 ( V_583 . V_565 ) ;
F_644 ( V_72 . V_325 ) ;
F_644 ( V_72 . V_647 ) ;
F_644 ( V_72 . V_649 ) ;
F_644 ( V_72 . V_650 ) ;
F_644 ( V_72 . V_648 ) ;
F_644 ( V_72 . V_651 ) ;
F_644 ( V_72 . V_326 ) ;
F_644 ( V_72 . V_643 ) ;
F_644 ( V_72 . V_652 ) ;
F_644 ( V_72 . V_644 ) ;
F_644 ( V_72 . V_653 ) ;
F_644 ( V_72 . V_654 ) ;
F_644 ( V_587 ) ;
F_644 ( V_993 ) ;
if ( ( F_43 ( V_2 ) -> V_81 < 8 && ! F_195 ( V_2 ) ) ||
F_18 ( V_2 ) )
F_644 ( V_674 ) ;
F_644 ( V_994 ) ;
F_645 ( V_72 . V_314 ,
V_646 ) ;
if ( ! F_647 ( V_995 ) ) {
F_645 ( V_72 . V_314 ,
V_404 ) ;
F_645 ( V_72 . V_314 ,
V_980 ) ;
F_645 ( V_72 . V_314 ,
V_406 ) ;
F_645 ( V_72 . V_314 ,
V_981 ) ;
}
F_644 ( V_329 ) ;
F_644 ( V_330 ) ;
if ( ! F_647 ( V_996 ) ) {
F_644 ( V_448 . V_449 ) ;
if ( F_43 ( V_2 ) -> V_81 < 4 )
F_644 ( V_448 . V_453 ) ;
F_644 ( V_448 . V_685 ) ;
}
F_644 ( V_327 . V_103 ) ;
if ( V_992 -> V_327 . V_103 ) {
F_644 ( V_327 . V_414 ) ;
F_644 ( V_327 . V_284 ) ;
}
if ( F_195 ( V_2 ) )
F_644 ( V_417 ) ;
F_644 ( V_534 ) ;
F_644 ( V_113 ) ;
F_643 ( V_199 . V_48 ) ;
F_643 ( V_199 . V_201 ) ;
F_643 ( V_199 . V_497 ) ;
F_643 ( V_199 . V_498 ) ;
if ( F_15 ( V_2 ) || F_43 ( V_2 ) -> V_81 >= 5 )
F_644 ( V_528 ) ;
F_646 ( V_72 . V_73 ) ;
F_646 ( V_607 ) ;
#undef F_643
#undef F_644
#undef F_645
#undef F_646
#undef F_647
return true ;
}
static void
F_648 ( struct V_1 * V_2 )
{
struct V_521 * V_515 ;
F_371 (connector, &dev->mode_config.connector_list,
base.head) {
F_376 ( V_515 ) ;
F_40 ( & V_515 -> V_891 -> V_112 != V_515 -> V_112 . V_23 ,
L_200 ) ;
}
}
static void
F_649 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_521 * V_515 ;
F_371 (encoder, &dev->mode_config.encoder_list,
base.head) {
bool V_103 = false ;
bool V_68 = false ;
enum V_75 V_75 , V_997 ;
F_45 ( L_201 ,
V_23 -> V_112 . V_112 . V_218 ,
V_23 -> V_112 . V_119 ) ;
F_40 ( & V_23 -> V_890 -> V_112 != V_23 -> V_112 . V_21 ,
L_202 ) ;
F_40 ( V_23 -> V_511 && ! V_23 -> V_112 . V_21 ,
L_203 ) ;
F_371 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_515 -> V_112 . V_23 != & V_23 -> V_112 )
continue;
V_103 = true ;
if ( V_515 -> V_112 . V_517 != V_518 )
V_68 = true ;
}
F_40 ( ! ! V_23 -> V_112 . V_21 != V_103 ,
L_204
L_205 ,
! ! V_23 -> V_112 . V_21 , V_103 ) ;
F_40 ( V_68 && ! V_23 -> V_112 . V_21 ,
L_206 ) ;
F_40 ( V_23 -> V_511 != V_68 ,
L_207
L_205 , V_68 , V_23 -> V_511 ) ;
V_68 = V_23 -> V_118 ( V_23 , & V_75 ) ;
F_40 ( V_68 != V_23 -> V_511 ,
L_208
L_205 ,
V_23 -> V_511 , V_68 ) ;
if ( ! V_23 -> V_112 . V_21 )
continue;
V_997 = F_34 ( V_23 -> V_112 . V_21 ) -> V_75 ;
F_40 ( V_68 && V_75 != V_997 ,
L_209
L_205 ,
V_997 , V_75 ) ;
}
}
static void
F_650 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_21 ;
struct V_22 * V_23 ;
struct V_446 V_447 ;
F_236 (dev, crtc) {
bool V_103 = false ;
bool V_68 = false ;
memset ( & V_447 , 0 , sizeof( V_447 ) ) ;
F_45 ( L_210 ,
V_21 -> V_112 . V_112 . V_218 ) ;
F_40 ( V_21 -> V_68 && ! V_21 -> V_112 . V_103 ,
L_211 ) ;
F_371 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_23 -> V_112 . V_21 != & V_21 -> V_112 )
continue;
V_103 = true ;
if ( V_23 -> V_511 )
V_68 = true ;
}
F_40 ( V_68 != V_21 -> V_68 ,
L_212
L_205 , V_68 , V_21 -> V_68 ) ;
F_40 ( V_103 != V_21 -> V_112 . V_103 ,
L_213
L_205 , V_103 , V_21 -> V_112 . V_103 ) ;
V_68 = V_4 -> V_308 . V_998 ( V_21 ,
& V_447 ) ;
if ( V_21 -> V_75 == V_128 && V_4 -> V_141 & V_142 )
V_68 = V_21 -> V_68 ;
F_371 (encoder, &dev->mode_config.encoder_list,
base.head) {
enum V_75 V_75 ;
if ( V_23 -> V_112 . V_21 != & V_21 -> V_112 )
continue;
if ( V_23 -> V_118 ( V_23 , & V_75 ) )
V_23 -> V_999 ( V_23 , & V_447 ) ;
}
F_40 ( V_21 -> V_68 != V_68 ,
L_214
L_205 , V_21 -> V_68 , V_68 ) ;
if ( V_68 &&
! F_642 ( V_2 , & V_21 -> V_71 , & V_447 ) ) {
F_40 ( 1 , L_215 ) ;
F_628 ( V_21 , & V_447 ,
L_216 ) ;
F_628 ( V_21 , & V_21 -> V_71 ,
L_217 ) ;
}
}
}
static void
F_651 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_21 ;
struct V_116 V_199 ;
int V_146 ;
for ( V_146 = 0 ; V_146 < V_4 -> V_410 ; V_146 ++ ) {
struct V_111 * V_115 = & V_4 -> V_114 [ V_146 ] ;
int V_1000 = 0 , V_1001 = 0 ;
bool V_68 ;
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
F_45 ( L_218 , V_115 -> V_119 ) ;
V_68 = V_115 -> V_118 ( V_4 , V_115 , & V_199 ) ;
F_40 ( V_115 -> V_68 > V_115 -> V_215 ,
L_219 ,
V_115 -> V_68 , V_115 -> V_215 ) ;
F_40 ( V_115 -> V_68 && ! V_115 -> V_216 ,
L_220 ) ;
F_40 ( V_115 -> V_216 && ! V_115 -> V_68 ,
L_221 ) ;
F_40 ( V_115 -> V_216 != V_68 ,
L_222 ,
V_115 -> V_216 , V_68 ) ;
F_236 (dev, crtc) {
if ( V_21 -> V_112 . V_103 && F_60 ( V_21 ) == V_115 )
V_1000 ++ ;
if ( V_21 -> V_68 && F_60 ( V_21 ) == V_115 )
V_1001 ++ ;
}
F_40 ( V_115 -> V_68 != V_1001 ,
L_223 ,
V_115 -> V_68 , V_1001 ) ;
F_40 ( V_115 -> V_215 != V_1000 ,
L_224 ,
V_115 -> V_215 , V_1000 ) ;
F_40 ( V_115 -> V_216 && memcmp ( & V_115 -> V_117 , & V_199 ,
sizeof( V_199 ) ) ,
L_225 ) ;
}
}
void
F_378 ( struct V_1 * V_2 )
{
F_648 ( V_2 ) ;
F_649 ( V_2 ) ;
F_650 ( V_2 ) ;
F_651 ( V_2 ) ;
}
void F_652 ( const struct V_446 * V_447 ,
int V_1002 )
{
F_40 ( ! F_641 ( V_447 -> V_72 . V_73 , V_1002 ) ,
L_226 ,
V_447 -> V_72 . V_73 , V_1002 ) ;
}
static void F_653 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
if ( F_19 ( V_2 ) ) {
const struct V_324 * V_403 = & V_21 -> V_71 . V_72 ;
int V_659 ;
V_659 = V_403 -> V_643 ;
if ( V_403 -> V_314 & V_646 )
V_659 /= 2 ;
V_21 -> V_1003 = V_659 - 1 ;
} else if ( F_65 ( V_2 ) &&
F_9 ( & V_21 -> V_112 , V_33 ) ) {
V_21 -> V_1003 = 2 ;
} else
V_21 -> V_1003 = 1 ;
}
static int F_654 ( struct V_20 * V_21 ,
struct V_324 * V_403 ,
int V_258 , int V_259 , struct V_293 * V_70 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_324 * V_1004 ;
struct V_446 * V_447 = NULL ;
struct V_67 * V_67 ;
unsigned V_986 , V_493 , V_985 ;
int V_248 = 0 ;
V_1004 = F_655 ( sizeof( * V_1004 ) , V_689 ) ;
if ( ! V_1004 )
return - V_861 ;
F_637 ( V_21 , & V_985 ,
& V_493 , & V_986 ) ;
* V_1004 = V_21 -> V_403 ;
if ( V_985 ) {
V_447 = F_634 ( V_21 , V_70 , V_403 ) ;
if ( F_555 ( V_447 ) ) {
V_248 = F_656 ( V_447 ) ;
V_447 = NULL ;
goto V_921;
}
F_628 ( F_34 ( V_21 ) , V_447 ,
L_227 ) ;
F_34 ( V_21 ) -> V_492 = V_447 ;
}
if ( F_18 ( V_2 ) ) {
F_352 ( V_2 , & V_493 ) ;
V_493 &= ~ V_986 ;
}
F_657 (dev, disable_pipes, intel_crtc)
F_369 ( & V_67 -> V_112 ) ;
F_657 (dev, prepare_pipes, intel_crtc) {
if ( V_67 -> V_112 . V_103 )
V_4 -> V_308 . V_513 ( & V_67 -> V_112 ) ;
}
if ( V_985 ) {
V_21 -> V_403 = * V_403 ;
F_34 ( V_21 ) -> V_71 = * V_447 ;
F_34 ( V_21 ) -> V_492 = & F_34 ( V_21 ) -> V_71 ;
F_658 ( V_21 ,
& V_447 -> V_72 ) ;
}
F_639 ( V_2 , V_493 ) ;
if ( V_4 -> V_308 . V_1005 )
V_4 -> V_308 . V_1005 ( V_2 ) ;
F_657 (dev, modeset_pipes, intel_crtc) {
struct V_293 * V_312 ;
F_57 ( & V_2 -> V_289 ) ;
V_248 = F_169 ( V_2 ,
F_183 ( V_70 ) -> V_244 ,
NULL ) ;
if ( V_248 != 0 ) {
F_115 ( L_58 ) ;
F_59 ( & V_2 -> V_289 ) ;
goto V_1006;
}
V_312 = V_21 -> V_69 -> V_70 ;
if ( V_312 )
F_176 ( F_183 ( V_312 ) -> V_244 ) ;
F_59 ( & V_2 -> V_289 ) ;
V_21 -> V_69 -> V_70 = V_70 ;
V_21 -> V_258 = V_258 ;
V_21 -> V_259 = V_259 ;
V_248 = V_4 -> V_308 . V_1007 ( & V_67 -> V_112 ,
V_258 , V_259 , V_70 ) ;
if ( V_248 )
goto V_1006;
}
F_657 (dev, prepare_pipes, intel_crtc) {
F_653 ( V_67 ) ;
V_4 -> V_308 . V_512 ( & V_67 -> V_112 ) ;
}
V_1006:
if ( V_248 && V_21 -> V_103 )
V_21 -> V_403 = * V_1004 ;
V_921:
F_186 ( V_447 ) ;
F_186 ( V_1004 ) ;
return V_248 ;
}
static int F_556 ( struct V_20 * V_21 ,
struct V_324 * V_403 ,
int V_258 , int V_259 , struct V_293 * V_70 )
{
int V_248 ;
V_248 = F_654 ( V_21 , V_403 , V_258 , V_259 , V_70 ) ;
if ( V_248 == 0 )
F_378 ( V_21 -> V_2 ) ;
return V_248 ;
}
void F_659 ( struct V_20 * V_21 )
{
F_556 ( V_21 , & V_21 -> V_403 , V_21 -> V_258 , V_21 -> V_259 , V_21 -> V_69 -> V_70 ) ;
}
static void F_660 ( struct V_1008 * V_71 )
{
if ( ! V_71 )
return;
F_186 ( V_71 -> V_1009 ) ;
F_186 ( V_71 -> V_1010 ) ;
F_186 ( V_71 -> V_1011 ) ;
F_186 ( V_71 ) ;
}
static int F_661 ( struct V_1 * V_2 ,
struct V_1008 * V_71 )
{
struct V_20 * V_21 ;
struct V_519 * V_23 ;
struct V_514 * V_515 ;
int V_1012 ;
V_71 -> V_1011 =
F_662 ( V_2 -> V_698 . V_1013 ,
sizeof( bool ) , V_689 ) ;
if ( ! V_71 -> V_1011 )
return - V_861 ;
V_71 -> V_1010 =
F_662 ( V_2 -> V_698 . V_1014 ,
sizeof( struct V_20 * ) , V_689 ) ;
if ( ! V_71 -> V_1010 )
return - V_861 ;
V_71 -> V_1009 =
F_662 ( V_2 -> V_698 . V_1015 ,
sizeof( struct V_519 * ) , V_689 ) ;
if ( ! V_71 -> V_1009 )
return - V_861 ;
V_1012 = 0 ;
F_187 (dev, crtc) {
V_71 -> V_1011 [ V_1012 ++ ] = V_21 -> V_103 ;
}
V_1012 = 0 ;
F_371 (encoder, &dev->mode_config.encoder_list, head) {
V_71 -> V_1010 [ V_1012 ++ ] = V_23 -> V_21 ;
}
V_1012 = 0 ;
F_371 (connector, &dev->mode_config.connector_list, head) {
V_71 -> V_1009 [ V_1012 ++ ] = V_515 -> V_23 ;
}
return 0 ;
}
static void F_663 ( struct V_1 * V_2 ,
struct V_1008 * V_71 )
{
struct V_67 * V_21 ;
struct V_22 * V_23 ;
struct V_521 * V_515 ;
int V_1012 ;
V_1012 = 0 ;
F_236 (dev, crtc) {
V_21 -> V_491 = V_71 -> V_1011 [ V_1012 ++ ] ;
if ( V_21 -> V_491 )
V_21 -> V_492 = & V_21 -> V_71 ;
else
V_21 -> V_492 = NULL ;
}
V_1012 = 0 ;
F_371 (encoder, &dev->mode_config.encoder_list, base.head) {
V_23 -> V_890 =
F_34 ( V_71 -> V_1010 [ V_1012 ++ ] ) ;
}
V_1012 = 0 ;
F_371 (connector, &dev->mode_config.connector_list, base.head) {
V_515 -> V_891 =
F_372 ( V_71 -> V_1009 [ V_1012 ++ ] ) ;
}
}
static bool
F_664 ( struct V_1016 * V_1017 )
{
int V_146 ;
if ( V_1017 -> V_574 == 0 )
return false ;
if ( F_2 ( V_1017 -> V_1018 == NULL ) )
return false ;
for ( V_146 = 0 ; V_146 < V_1017 -> V_574 ; V_146 ++ )
if ( V_1017 -> V_1018 [ V_146 ] -> V_23 &&
V_1017 -> V_1018 [ V_146 ] -> V_23 -> V_21 == V_1017 -> V_21 &&
V_1017 -> V_1018 [ V_146 ] -> V_517 != V_520 )
return true ;
return false ;
}
static void
F_665 ( struct V_1016 * V_1017 ,
struct V_1008 * V_71 )
{
if ( F_664 ( V_1017 ) ) {
V_71 -> V_1019 = true ;
} else if ( V_1017 -> V_21 -> V_69 -> V_70 != V_1017 -> V_70 ) {
if ( V_1017 -> V_21 -> V_69 -> V_70 == NULL ) {
struct V_67 * V_67 =
F_34 ( V_1017 -> V_21 ) ;
if ( V_67 -> V_68 && V_322 . V_323 ) {
F_45 ( L_228 ) ;
V_71 -> V_1020 = true ;
} else {
F_45 ( L_229 ) ;
V_71 -> V_1019 = true ;
}
} else if ( V_1017 -> V_70 == NULL ) {
V_71 -> V_1019 = true ;
} else if ( V_1017 -> V_70 -> V_287 !=
V_1017 -> V_21 -> V_69 -> V_70 -> V_287 ) {
V_71 -> V_1019 = true ;
} else {
V_71 -> V_1020 = true ;
}
}
if ( V_1017 -> V_70 && ( V_1017 -> V_258 != V_1017 -> V_21 -> V_258 || V_1017 -> V_259 != V_1017 -> V_21 -> V_259 ) )
V_71 -> V_1020 = true ;
if ( V_1017 -> V_403 && ! F_666 ( V_1017 -> V_403 , & V_1017 -> V_21 -> V_403 ) ) {
F_45 ( L_230 ) ;
F_630 ( & V_1017 -> V_21 -> V_403 ) ;
F_630 ( V_1017 -> V_403 ) ;
V_71 -> V_1019 = true ;
}
F_45 ( L_231 ,
V_1017 -> V_21 -> V_112 . V_218 , V_71 -> V_1019 , V_71 -> V_1020 ) ;
}
static int
F_667 ( struct V_1 * V_2 ,
struct V_1016 * V_1017 ,
struct V_1008 * V_71 )
{
struct V_521 * V_515 ;
struct V_22 * V_23 ;
struct V_67 * V_21 ;
int V_1021 ;
F_2 ( ! V_1017 -> V_70 && ( V_1017 -> V_574 != 0 ) ) ;
F_2 ( V_1017 -> V_70 && ( V_1017 -> V_574 == 0 ) ) ;
F_371 (connector, &dev->mode_config.connector_list,
base.head) {
for ( V_1021 = 0 ; V_1021 < V_1017 -> V_574 ; V_1021 ++ ) {
if ( V_1017 -> V_1018 [ V_1021 ] == & V_515 -> V_112 ) {
V_515 -> V_891 = V_515 -> V_23 ;
break;
}
}
if ( ( ! V_1017 -> V_70 || V_1021 == V_1017 -> V_574 ) &&
V_515 -> V_112 . V_23 &&
V_515 -> V_112 . V_23 -> V_21 == V_1017 -> V_21 ) {
V_515 -> V_891 = NULL ;
F_45 ( L_232 ,
V_515 -> V_112 . V_112 . V_218 ,
V_515 -> V_112 . V_119 ) ;
}
if ( & V_515 -> V_891 -> V_112 != V_515 -> V_112 . V_23 ) {
F_45 ( L_233 ) ;
V_71 -> V_1019 = true ;
}
}
F_371 (connector, &dev->mode_config.connector_list,
base.head) {
struct V_20 * V_890 ;
if ( ! V_515 -> V_891 )
continue;
V_890 = V_515 -> V_891 -> V_112 . V_21 ;
for ( V_1021 = 0 ; V_1021 < V_1017 -> V_574 ; V_1021 ++ ) {
if ( V_1017 -> V_1018 [ V_1021 ] == & V_515 -> V_112 )
V_890 = V_1017 -> V_21 ;
}
if ( ! F_668 ( & V_515 -> V_891 -> V_112 ,
V_890 ) ) {
return - V_253 ;
}
V_515 -> V_23 -> V_890 = F_34 ( V_890 ) ;
F_45 ( L_234 ,
V_515 -> V_112 . V_112 . V_218 ,
V_515 -> V_112 . V_119 ,
V_890 -> V_112 . V_218 ) ;
}
F_371 (encoder, &dev->mode_config.encoder_list,
base.head) {
int V_574 = 0 ;
F_371 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_515 -> V_891 == V_23 ) {
F_2 ( ! V_515 -> V_891 -> V_890 ) ;
V_574 ++ ;
}
}
if ( V_574 == 0 )
V_23 -> V_890 = NULL ;
else if ( V_574 > 1 )
return - V_253 ;
if ( & V_23 -> V_890 -> V_112 != V_23 -> V_112 . V_21 ) {
F_45 ( L_235 ) ;
V_71 -> V_1019 = true ;
}
}
F_236 (dev, crtc) {
V_21 -> V_491 = false ;
F_371 (encoder,
&dev->mode_config.encoder_list,
base.head) {
if ( V_23 -> V_890 == V_21 ) {
V_21 -> V_491 = true ;
break;
}
}
if ( V_21 -> V_491 != V_21 -> V_112 . V_103 ) {
F_45 ( L_236 ,
V_21 -> V_491 ? L_237 : L_238 ) ;
V_71 -> V_1019 = true ;
}
if ( V_21 -> V_491 )
V_21 -> V_492 = & V_21 -> V_71 ;
else
V_21 -> V_492 = NULL ;
}
return 0 ;
}
static void F_669 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_22 * V_23 ;
struct V_521 * V_515 ;
F_45 ( L_239 ,
F_73 ( V_21 -> V_75 ) ) ;
F_371 (connector, &dev->mode_config.connector_list, base.head) {
if ( V_515 -> V_891 &&
V_515 -> V_891 -> V_890 == V_21 )
V_515 -> V_891 = NULL ;
}
F_371 (encoder, &dev->mode_config.encoder_list, base.head) {
if ( V_23 -> V_890 == V_21 )
V_23 -> V_890 = NULL ;
}
V_21 -> V_491 = false ;
V_21 -> V_492 = NULL ;
}
static int F_670 ( struct V_1016 * V_1017 )
{
struct V_1 * V_2 ;
struct V_1016 V_1022 ;
struct V_1008 * V_71 ;
int V_248 ;
F_120 ( ! V_1017 ) ;
F_120 ( ! V_1017 -> V_21 ) ;
F_120 ( ! V_1017 -> V_21 -> V_1023 ) ;
F_120 ( ! V_1017 -> V_403 && V_1017 -> V_70 ) ;
F_120 ( V_1017 -> V_70 && V_1017 -> V_574 == 0 ) ;
if ( V_1017 -> V_70 ) {
F_45 ( L_240 ,
V_1017 -> V_21 -> V_112 . V_218 , V_1017 -> V_70 -> V_112 . V_218 ,
( int ) V_1017 -> V_574 , V_1017 -> V_258 , V_1017 -> V_259 ) ;
} else {
F_45 ( L_241 , V_1017 -> V_21 -> V_112 . V_218 ) ;
}
V_2 = V_1017 -> V_21 -> V_2 ;
V_248 = - V_861 ;
V_71 = F_448 ( sizeof( * V_71 ) , V_689 ) ;
if ( ! V_71 )
goto V_1024;
V_248 = F_661 ( V_2 , V_71 ) ;
if ( V_248 )
goto V_1024;
V_1022 . V_21 = V_1017 -> V_21 ;
V_1022 . V_403 = & V_1017 -> V_21 -> V_403 ;
V_1022 . V_258 = V_1017 -> V_21 -> V_258 ;
V_1022 . V_259 = V_1017 -> V_21 -> V_259 ;
V_1022 . V_70 = V_1017 -> V_21 -> V_69 -> V_70 ;
F_665 ( V_1017 , V_71 ) ;
V_248 = F_667 ( V_2 , V_1017 , V_71 ) ;
if ( V_248 )
goto V_862;
if ( V_71 -> V_1019 ) {
V_248 = F_556 ( V_1017 -> V_21 , V_1017 -> V_403 ,
V_1017 -> V_258 , V_1017 -> V_259 , V_1017 -> V_70 ) ;
} else if ( V_71 -> V_1020 ) {
F_237 ( V_1017 -> V_21 ) ;
V_248 = F_211 ( V_1017 -> V_21 ,
V_1017 -> V_258 , V_1017 -> V_259 , V_1017 -> V_70 ) ;
if ( V_322 . V_323 && V_248 == 0 )
F_378 ( V_1017 -> V_21 -> V_2 ) ;
}
if ( V_248 ) {
F_45 ( L_242 ,
V_1017 -> V_21 -> V_112 . V_218 , V_248 ) ;
V_862:
F_663 ( V_2 , V_71 ) ;
if ( F_34 ( V_1022 . V_21 ) -> V_491 && ! V_1022 . V_70 )
F_669 ( F_34 ( V_1022 . V_21 ) ) ;
if ( V_71 -> V_1019 &&
F_556 ( V_1022 . V_21 , V_1022 . V_403 ,
V_1022 . V_258 , V_1022 . V_259 , V_1022 . V_70 ) )
F_115 ( L_243 ) ;
}
V_1024:
F_660 ( V_71 ) ;
return V_248 ;
}
static void F_671 ( struct V_1 * V_2 )
{
if ( F_65 ( V_2 ) )
F_672 ( V_2 ) ;
}
static bool F_673 ( struct V_3 * V_4 ,
struct V_111 * V_115 ,
struct V_116 * V_117 )
{
T_4 V_105 ;
V_105 = F_4 ( F_674 ( V_115 -> V_218 ) ) ;
V_117 -> V_48 = V_105 ;
V_117 -> V_497 = F_4 ( F_675 ( V_115 -> V_218 ) ) ;
V_117 -> V_498 = F_4 ( F_676 ( V_115 -> V_218 ) ) ;
return V_105 & V_107 ;
}
static void F_677 ( struct V_3 * V_4 ,
struct V_111 * V_115 )
{
F_44 ( F_675 ( V_115 -> V_218 ) , V_115 -> V_117 . V_497 ) ;
F_44 ( F_676 ( V_115 -> V_218 ) , V_115 -> V_117 . V_498 ) ;
}
static void F_678 ( struct V_3 * V_4 ,
struct V_111 * V_115 )
{
F_92 ( V_4 ) ;
F_44 ( F_674 ( V_115 -> V_218 ) , V_115 -> V_117 . V_48 ) ;
F_123 ( F_674 ( V_115 -> V_218 ) ) ;
F_124 ( 150 ) ;
F_44 ( F_674 ( V_115 -> V_218 ) , V_115 -> V_117 . V_48 ) ;
F_123 ( F_674 ( V_115 -> V_218 ) ) ;
F_124 ( 200 ) ;
}
static void F_679 ( struct V_3 * V_4 ,
struct V_111 * V_115 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_67 * V_21 ;
F_236 (dev, crtc) {
if ( F_60 ( V_21 ) == V_115 )
F_94 ( V_4 , V_21 -> V_75 ) ;
}
F_44 ( F_674 ( V_115 -> V_218 ) , 0 ) ;
F_123 ( F_674 ( V_115 -> V_218 ) ) ;
F_124 ( 200 ) ;
}
static void F_680 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_146 ;
V_4 -> V_410 = 2 ;
for ( V_146 = 0 ; V_146 < V_4 -> V_410 ; V_146 ++ ) {
V_4 -> V_114 [ V_146 ] . V_218 = V_146 ;
V_4 -> V_114 [ V_146 ] . V_119 = V_1025 [ V_146 ] ;
V_4 -> V_114 [ V_146 ] . V_217 = F_677 ;
V_4 -> V_114 [ V_146 ] . V_219 = F_678 ;
V_4 -> V_114 [ V_146 ] . V_220 = F_679 ;
V_4 -> V_114 [ V_146 ] . V_118 =
F_673 ;
}
}
static void F_681 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_52 ( V_2 ) || F_93 ( V_2 ) )
F_680 ( V_2 ) ;
else
V_4 -> V_410 = 0 ;
F_120 ( V_4 -> V_410 > V_1026 ) ;
}
static void F_682 ( struct V_1 * V_2 , int V_75 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_67 ;
int V_146 ;
V_67 = F_448 ( sizeof( * V_67 ) , V_689 ) ;
if ( V_67 == NULL )
return;
F_683 ( V_2 , & V_67 -> V_112 , & V_1027 ) ;
F_684 ( & V_67 -> V_112 , 256 ) ;
for ( V_146 = 0 ; V_146 < 256 ; V_146 ++ ) {
V_67 -> V_427 [ V_146 ] = V_146 ;
V_67 -> V_428 [ V_146 ] = V_146 ;
V_67 -> V_429 [ V_146 ] = V_146 ;
}
V_67 -> V_75 = V_75 ;
V_67 -> V_144 = V_75 ;
if ( F_685 ( V_2 ) && F_43 ( V_2 ) -> V_81 < 4 ) {
F_45 ( L_244 ) ;
V_67 -> V_144 = ! V_75 ;
}
V_67 -> V_837 = ~ 0 ;
V_67 -> V_838 = ~ 0 ;
F_686 ( & V_67 -> V_1028 ) ;
F_120 ( V_75 >= F_231 ( V_4 -> V_933 ) ||
V_4 -> V_933 [ V_67 -> V_144 ] != NULL ) ;
V_4 -> V_933 [ V_67 -> V_144 ] = & V_67 -> V_112 ;
V_4 -> V_76 [ V_67 -> V_75 ] = & V_67 -> V_112 ;
F_687 ( & V_67 -> V_112 , & V_1029 ) ;
F_2 ( F_688 ( & V_67 -> V_112 ) != V_67 -> V_75 ) ;
}
enum V_75 F_689 ( struct V_521 * V_515 )
{
struct V_519 * V_23 = V_515 -> V_112 . V_23 ;
struct V_1 * V_2 = V_515 -> V_112 . V_2 ;
F_2 ( ! F_690 ( & V_2 -> V_698 . V_885 ) ) ;
if ( ! V_23 )
return V_1030 ;
return F_34 ( V_23 -> V_21 ) -> V_75 ;
}
int F_691 ( struct V_1 * V_2 , void * V_1031 ,
struct V_854 * V_855 )
{
struct V_1032 * V_1033 = V_1031 ;
struct V_1034 * V_1035 ;
struct V_67 * V_21 ;
if ( ! F_692 ( V_2 , V_1036 ) )
return - V_955 ;
V_1035 = F_693 ( V_2 , V_1033 -> V_1037 ,
V_1038 ) ;
if ( ! V_1035 ) {
F_115 ( L_245 ) ;
return - V_860 ;
}
V_21 = F_34 ( F_694 ( V_1035 ) ) ;
V_1033 -> V_75 = V_21 -> V_75 ;
return 0 ;
}
static int F_695 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_112 . V_2 ;
struct V_22 * V_978 ;
int V_1039 = 0 ;
int V_1040 = 0 ;
F_371 (source_encoder,
&dev->mode_config.encoder_list, base.head) {
if ( F_631 ( V_23 , V_978 ) )
V_1039 |= ( 1 << V_1040 ) ;
V_1040 ++ ;
}
return V_1039 ;
}
static bool F_696 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_121 ( V_2 ) )
return false ;
if ( ( F_4 ( V_1041 ) & V_1042 ) == 0 )
return false ;
if ( F_6 ( V_2 ) && ( F_4 ( V_1043 ) & V_1044 ) )
return false ;
return true ;
}
const char * F_697 ( int V_1045 )
{
static const char * V_1046 [] = {
[ V_1047 ] = L_246 ,
[ V_34 ] = L_247 ,
[ V_45 ] = L_248 ,
[ V_36 ] = L_249 ,
[ V_25 ] = L_250 ,
[ V_1048 ] = L_251 ,
[ V_33 ] = L_252 ,
[ V_397 ] = L_253 ,
[ V_328 ] = L_254 ,
[ V_236 ] = L_255 ,
[ V_456 ] = L_256 ,
} ;
if ( V_1045 < 0 || V_1045 >= F_231 ( V_1046 ) || ! V_1046 [ V_1045 ] )
return L_257 ;
return V_1046 [ V_1045 ] ;
}
static bool F_698 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_699 ( V_2 ) )
return false ;
if ( F_17 ( V_2 ) )
return false ;
if ( F_18 ( V_2 ) && ! V_4 -> V_571 . V_1049 )
return false ;
return true ;
}
static void F_700 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 * V_23 ;
bool V_1050 = false ;
F_701 ( V_2 ) ;
if ( F_698 ( V_2 ) )
F_702 ( V_2 ) ;
if ( F_65 ( V_2 ) ) {
int V_61 ;
V_61 = F_4 ( V_1051 ) & V_1052 ;
if ( V_61 )
F_703 ( V_2 , V_457 ) ;
V_61 = F_4 ( V_1053 ) ;
if ( V_61 & V_1054 )
F_703 ( V_2 , V_93 ) ;
if ( V_61 & V_1055 )
F_703 ( V_2 , V_95 ) ;
if ( V_61 & V_1056 )
F_703 ( V_2 , V_97 ) ;
} else if ( F_3 ( V_2 ) ) {
int V_61 ;
V_1050 = F_704 ( V_2 , V_97 ) ;
if ( F_696 ( V_2 ) )
F_705 ( V_2 , V_1041 , V_457 ) ;
if ( F_4 ( V_184 ) & V_1057 ) {
V_61 = F_706 ( V_2 , V_1058 , true ) ;
if ( ! V_61 )
F_707 ( V_2 , V_184 , V_93 ) ;
if ( ! V_61 && ( F_4 ( V_177 ) & V_1042 ) )
F_705 ( V_2 , V_177 , V_93 ) ;
}
if ( F_4 ( V_185 ) & V_1057 )
F_707 ( V_2 , V_185 , V_95 ) ;
if ( ! V_1050 && F_4 ( V_186 ) & V_1057 )
F_707 ( V_2 , V_186 , V_97 ) ;
if ( F_4 ( V_179 ) & V_1042 )
F_705 ( V_2 , V_179 , V_95 ) ;
if ( F_4 ( V_181 ) & V_1042 )
F_705 ( V_2 , V_181 , V_97 ) ;
} else if ( F_18 ( V_2 ) ) {
if ( F_4 ( V_1059 + V_1060 ) & V_1057 ) {
F_707 ( V_2 , V_1059 + V_1060 ,
V_93 ) ;
if ( F_4 ( V_1059 + V_1061 ) & V_1042 )
F_705 ( V_2 , V_1059 + V_1061 , V_93 ) ;
}
if ( F_4 ( V_1059 + V_1062 ) & V_1057 ) {
F_707 ( V_2 , V_1059 + V_1062 ,
V_95 ) ;
if ( F_4 ( V_1059 + V_1063 ) & V_1042 )
F_705 ( V_2 , V_1059 + V_1063 , V_95 ) ;
}
if ( F_17 ( V_2 ) ) {
if ( F_4 ( V_1059 + V_1064 ) & V_1057 ) {
F_707 ( V_2 , V_1059 + V_1064 ,
V_97 ) ;
if ( F_4 ( V_1059 + V_1065 ) & V_1042 )
F_705 ( V_2 , V_1059 + V_1065 , V_97 ) ;
}
}
F_708 ( V_2 ) ;
} else if ( F_709 ( V_2 ) ) {
bool V_61 = false ;
if ( F_4 ( V_1066 ) & V_1057 ) {
F_45 ( L_258 ) ;
V_61 = F_706 ( V_2 , V_1066 , true ) ;
if ( ! V_61 && F_710 ( V_2 ) ) {
F_45 ( L_259 ) ;
F_707 ( V_2 , V_1060 , V_93 ) ;
}
if ( ! V_61 && F_711 ( V_2 ) )
F_705 ( V_2 , V_1061 , V_93 ) ;
}
if ( F_4 ( V_1066 ) & V_1057 ) {
F_45 ( L_260 ) ;
V_61 = F_706 ( V_2 , V_1067 , false ) ;
}
if ( ! V_61 && ( F_4 ( V_1067 ) & V_1057 ) ) {
if ( F_710 ( V_2 ) ) {
F_45 ( L_261 ) ;
F_707 ( V_2 , V_1062 , V_95 ) ;
}
if ( F_711 ( V_2 ) )
F_705 ( V_2 , V_1063 , V_95 ) ;
}
if ( F_711 ( V_2 ) &&
( F_4 ( V_1065 ) & V_1042 ) )
F_705 ( V_2 , V_1065 , V_97 ) ;
} else if ( F_19 ( V_2 ) )
F_712 ( V_2 ) ;
if ( F_713 ( V_2 ) )
F_714 ( V_2 ) ;
F_371 (encoder, &dev->mode_config.encoder_list, base.head) {
V_23 -> V_112 . V_889 = V_23 -> V_1068 ;
V_23 -> V_112 . V_1069 =
F_695 ( V_23 ) ;
}
F_460 ( V_2 ) ;
F_715 ( V_2 ) ;
}
static void F_716 ( struct V_293 * V_70 )
{
struct V_292 * V_294 = F_183 ( V_70 ) ;
F_717 ( V_70 ) ;
F_2 ( ! V_294 -> V_244 -> V_1070 -- ) ;
F_537 ( & V_294 -> V_244 -> V_112 ) ;
F_186 ( V_294 ) ;
}
static int F_718 ( struct V_293 * V_70 ,
struct V_854 * V_855 ,
unsigned int * V_856 )
{
struct V_292 * V_294 = F_183 ( V_70 ) ;
struct V_243 * V_244 = V_294 -> V_244 ;
return F_719 ( V_855 , & V_244 -> V_112 , V_856 ) ;
}
static int F_182 ( struct V_1 * V_2 ,
struct V_292 * V_294 ,
struct V_282 * V_283 ,
struct V_243 * V_244 )
{
int V_688 ;
int V_1071 ;
int V_248 ;
F_2 ( ! F_720 ( & V_2 -> V_289 ) ) ;
if ( V_244 -> V_249 == V_252 ) {
F_532 ( L_262 ) ;
return - V_253 ;
}
if ( V_283 -> V_286 [ 0 ] & 63 ) {
F_532 ( L_263 ,
V_283 -> V_286 [ 0 ] ) ;
return - V_253 ;
}
if ( F_43 ( V_2 ) -> V_81 >= 5 && ! F_18 ( V_2 ) ) {
V_1071 = 32 * 1024 ;
} else if ( F_43 ( V_2 ) -> V_81 >= 4 ) {
if ( V_244 -> V_249 )
V_1071 = 16 * 1024 ;
else
V_1071 = 32 * 1024 ;
} else if ( F_43 ( V_2 ) -> V_81 >= 3 ) {
if ( V_244 -> V_249 )
V_1071 = 8 * 1024 ;
else
V_1071 = 16 * 1024 ;
} else
V_1071 = 8 * 1024 ;
if ( V_283 -> V_286 [ 0 ] > V_1071 ) {
F_532 ( L_264 ,
V_244 -> V_249 ? L_265 : L_266 ,
V_283 -> V_286 [ 0 ] , V_1071 ) ;
return - V_253 ;
}
if ( V_244 -> V_249 != V_250 &&
V_283 -> V_286 [ 0 ] != V_244 -> V_285 ) {
F_532 ( L_267 ,
V_283 -> V_286 [ 0 ] , V_244 -> V_285 ) ;
return - V_253 ;
}
switch ( V_283 -> V_287 ) {
case V_267 :
case V_271 :
case V_273 :
case V_299 :
break;
case V_269 :
case V_298 :
if ( F_43 ( V_2 ) -> V_81 > 3 ) {
F_532 ( L_268 ,
F_721 ( V_283 -> V_287 ) ) ;
return - V_253 ;
}
break;
case V_275 :
case V_300 :
case V_277 :
case V_301 :
case V_279 :
case V_302 :
if ( F_43 ( V_2 ) -> V_81 < 4 ) {
F_532 ( L_268 ,
F_721 ( V_283 -> V_287 ) ) ;
return - V_253 ;
}
break;
case V_1072 :
case V_1073 :
case V_1074 :
case V_1075 :
if ( F_43 ( V_2 ) -> V_81 < 5 ) {
F_532 ( L_268 ,
F_721 ( V_283 -> V_287 ) ) ;
return - V_253 ;
}
break;
default:
F_532 ( L_268 ,
F_721 ( V_283 -> V_287 ) ) ;
return - V_253 ;
}
if ( V_283 -> V_965 [ 0 ] != 0 )
return - V_253 ;
V_688 = F_167 ( V_2 , V_283 -> V_240 ,
V_244 -> V_249 ) ;
if ( V_244 -> V_112 . V_284 < V_688 * V_283 -> V_286 [ 0 ] )
return - V_253 ;
F_722 ( & V_294 -> V_112 , V_283 ) ;
V_294 -> V_244 = V_244 ;
V_294 -> V_244 -> V_1070 ++ ;
V_248 = F_723 ( V_2 , & V_294 -> V_112 , & V_1076 ) ;
if ( V_248 ) {
F_115 ( L_269 , V_248 ) ;
return V_248 ;
}
return 0 ;
}
static struct V_293 *
F_724 ( struct V_1 * V_2 ,
struct V_854 * V_1077 ,
struct V_282 * V_283 )
{
struct V_243 * V_244 ;
V_244 = F_533 ( F_534 ( V_2 , V_1077 ,
V_283 -> V_1078 [ 0 ] ) ) ;
if ( & V_244 -> V_112 == NULL )
return F_542 ( - V_860 ) ;
return F_543 ( V_2 , V_283 , V_244 ) ;
}
static inline void F_725 ( struct V_1 * V_2 )
{
}
static void F_726 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_3 ( V_2 ) || F_15 ( V_2 ) )
V_4 -> V_308 . V_680 = F_29 ;
else if ( F_17 ( V_2 ) )
V_4 -> V_308 . V_680 = F_32 ;
else if ( F_18 ( V_2 ) )
V_4 -> V_308 . V_680 = F_30 ;
else if ( F_16 ( V_2 ) )
V_4 -> V_308 . V_680 = F_28 ;
else
V_4 -> V_308 . V_680 = F_27 ;
if ( F_65 ( V_2 ) ) {
V_4 -> V_308 . V_998 = F_504 ;
V_4 -> V_308 . V_1079 = F_488 ;
V_4 -> V_308 . V_1007 = F_501 ;
V_4 -> V_308 . V_512 = F_311 ;
V_4 -> V_308 . V_513 = F_320 ;
V_4 -> V_308 . V_516 = F_325 ;
V_4 -> V_308 . V_310 =
F_194 ;
} else if ( F_3 ( V_2 ) ) {
V_4 -> V_308 . V_998 = F_489 ;
V_4 -> V_308 . V_1079 = F_488 ;
V_4 -> V_308 . V_1007 = F_480 ;
V_4 -> V_308 . V_512 = F_299 ;
V_4 -> V_308 . V_513 = F_319 ;
V_4 -> V_308 . V_516 = F_324 ;
V_4 -> V_308 . V_310 =
F_194 ;
} else if ( F_18 ( V_2 ) ) {
V_4 -> V_308 . V_998 = F_451 ;
V_4 -> V_308 . V_1079 = F_447 ;
V_4 -> V_308 . V_1007 = F_444 ;
V_4 -> V_308 . V_512 = F_354 ;
V_4 -> V_308 . V_513 = F_365 ;
V_4 -> V_308 . V_516 = F_366 ;
V_4 -> V_308 . V_310 =
F_190 ;
} else {
V_4 -> V_308 . V_998 = F_451 ;
V_4 -> V_308 . V_1079 = F_447 ;
V_4 -> V_308 . V_1007 = F_444 ;
V_4 -> V_308 . V_512 = F_363 ;
V_4 -> V_308 . V_513 = F_365 ;
V_4 -> V_308 . V_516 = F_366 ;
V_4 -> V_308 . V_310 =
F_190 ;
}
if ( F_18 ( V_2 ) )
V_4 -> V_308 . V_533 =
F_389 ;
else if ( F_437 ( V_2 ) || ( F_439 ( V_2 ) && ! F_727 ( V_2 ) ) )
V_4 -> V_308 . V_533 =
F_390 ;
else if ( F_388 ( V_2 ) )
V_4 -> V_308 . V_533 =
F_391 ;
else if ( F_438 ( V_2 ) || F_75 ( V_2 ) )
V_4 -> V_308 . V_533 =
F_392 ;
else if ( F_16 ( V_2 ) )
V_4 -> V_308 . V_533 =
F_393 ;
else if ( F_728 ( V_2 ) )
V_4 -> V_308 . V_533 =
F_395 ;
else if ( F_76 ( V_2 ) )
V_4 -> V_308 . V_533 =
F_396 ;
else if ( F_729 ( V_2 ) )
V_4 -> V_308 . V_533 =
F_397 ;
else
V_4 -> V_308 . V_533 =
F_398 ;
if ( F_3 ( V_2 ) ) {
if ( F_6 ( V_2 ) ) {
V_4 -> V_308 . V_393 = F_222 ;
V_4 -> V_308 . V_836 = F_513 ;
} else if ( F_229 ( V_2 ) ) {
V_4 -> V_308 . V_393 = F_227 ;
V_4 -> V_308 . V_836 = F_513 ;
V_4 -> V_308 . V_1005 =
F_499 ;
} else if ( F_219 ( V_2 ) ) {
V_4 -> V_308 . V_393 = F_230 ;
V_4 -> V_308 . V_836 = F_513 ;
V_4 -> V_308 . V_1005 =
F_221 ;
} else if ( F_195 ( V_2 ) || F_609 ( V_2 ) ) {
V_4 -> V_308 . V_393 = V_1080 ;
V_4 -> V_308 . V_836 = F_509 ;
V_4 -> V_308 . V_1005 =
F_500 ;
}
} else if ( F_15 ( V_2 ) ) {
V_4 -> V_308 . V_836 = F_508 ;
} else if ( F_18 ( V_2 ) ) {
V_4 -> V_308 . V_1005 =
F_353 ;
V_4 -> V_308 . V_836 = F_513 ;
}
V_4 -> V_308 . V_972 = F_614 ;
switch ( F_43 ( V_2 ) -> V_81 ) {
case 2 :
V_4 -> V_308 . V_972 = F_599 ;
break;
case 3 :
V_4 -> V_308 . V_972 = F_604 ;
break;
case 4 :
case 5 :
V_4 -> V_308 . V_972 = F_605 ;
break;
case 6 :
V_4 -> V_308 . V_972 = F_606 ;
break;
case 7 :
case 8 :
V_4 -> V_308 . V_972 = F_607 ;
break;
}
F_730 ( V_2 ) ;
}
static void F_731 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_141 |= V_142 ;
F_732 ( L_270 ) ;
}
static void F_733 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_141 |= V_573 ;
F_732 ( L_271 ) ;
}
static void F_734 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_141 |= V_1081 ;
F_732 ( L_272 ) ;
}
static void F_735 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_141 |= V_1082 ;
F_732 ( L_273 ) ;
}
static int F_736 ( const struct V_1083 * V_218 )
{
F_732 ( L_274 , V_218 -> V_1084 ) ;
return 1 ;
}
static void F_737 ( struct V_1 * V_2 )
{
struct V_1085 * V_1086 = V_2 -> V_537 ;
int V_146 ;
for ( V_146 = 0 ; V_146 < F_231 ( V_1087 ) ; V_146 ++ ) {
struct V_1088 * V_1089 = & V_1087 [ V_146 ] ;
if ( V_1086 -> V_1090 == V_1089 -> V_1090 &&
( V_1086 -> V_1091 == V_1089 -> V_1091 ||
V_1089 -> V_1091 == V_1092 ) &&
( V_1086 -> V_1093 == V_1089 -> V_1093 ||
V_1089 -> V_1093 == V_1092 ) )
V_1089 -> V_1094 ( V_2 ) ;
}
for ( V_146 = 0 ; V_146 < F_231 ( V_1095 ) ; V_146 ++ ) {
if ( F_738 ( * V_1095 [ V_146 ] . V_1096 ) != 0 )
V_1095 [ V_146 ] . V_1094 ( V_2 ) ;
}
}
static void F_739 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_9 V_1097 ;
T_1 V_1098 = F_740 ( V_2 ) ;
F_741 ( V_2 -> V_537 , V_1099 ) ;
F_742 ( V_1100 , V_1101 ) ;
V_1097 = F_743 ( V_1102 ) ;
F_742 ( V_1097 | 1 << 5 , V_1102 ) ;
F_744 ( V_2 -> V_537 , V_1099 ) ;
F_124 ( 300 ) ;
F_44 ( V_1098 , V_1103 ) ;
F_123 ( V_1098 ) ;
}
void F_745 ( struct V_1 * V_2 )
{
F_498 ( V_2 ) ;
F_746 ( V_2 ) ;
F_113 ( V_2 ) ;
F_747 ( V_2 ) ;
}
void F_748 ( struct V_1 * V_2 )
{
F_749 ( V_2 ) ;
}
void F_750 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_150 , V_248 ;
enum V_75 V_75 ;
struct V_67 * V_21 ;
F_751 ( V_2 ) ;
V_2 -> V_698 . V_1104 = 0 ;
V_2 -> V_698 . V_1105 = 0 ;
V_2 -> V_698 . V_1106 = 24 ;
V_2 -> V_698 . V_1107 = 1 ;
V_2 -> V_698 . V_788 = & V_1108 ;
F_737 ( V_2 ) ;
F_752 ( V_2 ) ;
if ( F_43 ( V_2 ) -> V_321 == 0 )
return;
F_726 ( V_2 ) ;
if ( F_19 ( V_2 ) ) {
V_2 -> V_698 . V_1109 = 2048 ;
V_2 -> V_698 . V_1110 = 2048 ;
} else if ( F_753 ( V_2 ) ) {
V_2 -> V_698 . V_1109 = 4096 ;
V_2 -> V_698 . V_1110 = 4096 ;
} else {
V_2 -> V_698 . V_1109 = 8192 ;
V_2 -> V_698 . V_1110 = 8192 ;
}
if ( F_19 ( V_2 ) ) {
V_2 -> V_698 . V_843 = V_1111 ;
V_2 -> V_698 . V_852 = V_1112 ;
} else {
V_2 -> V_698 . V_843 = V_1113 ;
V_2 -> V_698 . V_852 = V_1114 ;
}
V_2 -> V_698 . V_1115 = V_4 -> V_1116 . V_1117 ;
F_45 ( L_275 ,
F_43 ( V_2 ) -> V_321 ,
F_43 ( V_2 ) -> V_321 > 1 ? L_276 : L_277 ) ;
F_85 (pipe) {
F_682 ( V_2 , V_75 ) ;
F_87 (pipe, sprite) {
V_248 = F_754 ( V_2 , V_75 , V_150 ) ;
if ( V_248 )
F_45 ( L_278 ,
F_73 ( V_75 ) , F_89 ( V_75 , V_150 ) , V_248 ) ;
}
}
F_111 ( V_2 ) ;
F_113 ( V_2 ) ;
F_671 ( V_2 ) ;
F_681 ( V_2 ) ;
F_739 ( V_2 ) ;
F_700 ( V_2 ) ;
F_298 ( V_2 ) ;
F_755 ( V_2 ) ;
F_756 ( V_2 , false ) ;
F_757 ( V_2 ) ;
F_236 (dev, crtc) {
if ( ! V_21 -> V_68 )
continue;
if ( V_4 -> V_308 . V_1079 ) {
V_4 -> V_308 . V_1079 ( V_21 ,
& V_21 -> V_281 ) ;
F_185 ( V_21 , & V_21 -> V_281 ) ;
}
}
}
static void F_758 ( struct V_1 * V_2 )
{
struct V_521 * V_515 ;
struct V_514 * V_1118 = NULL ;
struct V_880 V_888 ;
struct V_882 V_883 ;
F_371 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_515 -> V_23 -> type == V_34 ) {
V_1118 = & V_515 -> V_112 ;
break;
}
}
if ( ! V_1118 )
return;
if ( F_552 ( V_1118 , NULL , & V_888 , & V_883 ) )
F_560 ( V_1118 , & V_888 , & V_883 ) ;
}
static bool
F_759 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_83 , V_105 ;
if ( F_43 ( V_2 ) -> V_321 == 1 )
return true ;
V_83 = F_82 ( ! V_21 -> V_144 ) ;
V_105 = F_4 ( V_83 ) ;
if ( ( V_105 & V_145 ) &&
( ! ! ( V_105 & V_148 ) == V_21 -> V_75 ) )
return false ;
return true ;
}
static void F_760 ( struct V_67 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_112 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_83 ;
V_83 = F_50 ( V_21 -> V_71 . V_77 ) ;
F_44 ( V_83 , F_4 ( V_83 ) & ~ V_1119 ) ;
if ( V_21 -> V_68 )
F_761 ( V_2 , V_21 -> V_75 ) ;
else
F_762 ( V_2 , V_21 -> V_75 ) ;
if ( F_43 ( V_2 ) -> V_81 < 4 && ! F_759 ( V_21 ) ) {
struct V_521 * V_515 ;
bool V_144 ;
F_45 ( L_279 ,
V_21 -> V_112 . V_112 . V_218 ) ;
V_144 = V_21 -> V_144 ;
V_21 -> V_144 = ! V_144 ;
V_21 -> V_238 = true ;
V_4 -> V_308 . V_513 ( & V_21 -> V_112 ) ;
V_21 -> V_144 = V_144 ;
F_371 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_515 -> V_23 -> V_112 . V_21 != & V_21 -> V_112 )
continue;
V_515 -> V_112 . V_517 = V_518 ;
V_515 -> V_112 . V_23 = NULL ;
}
F_371 (connector, &dev->mode_config.connector_list,
base.head)
if ( V_515 -> V_23 -> V_112 . V_21 == & V_21 -> V_112 ) {
V_515 -> V_23 -> V_112 . V_21 = NULL ;
V_515 -> V_23 -> V_511 = false ;
}
F_2 ( V_21 -> V_68 ) ;
V_21 -> V_112 . V_103 = false ;
}
if ( V_4 -> V_141 & V_142 &&
V_21 -> V_75 == V_128 && ! V_21 -> V_68 ) {
F_758 ( V_2 ) ;
}
F_368 ( & V_21 -> V_112 ) ;
if ( V_21 -> V_68 != V_21 -> V_112 . V_103 ) {
struct V_22 * V_23 ;
F_45 ( L_280 ,
V_21 -> V_112 . V_112 . V_218 ,
V_21 -> V_112 . V_103 ? L_189 : L_190 ,
V_21 -> V_68 ? L_189 : L_190 ) ;
V_21 -> V_112 . V_103 = V_21 -> V_68 ;
F_2 ( V_21 -> V_68 ) ;
F_10 (dev, &crtc->base, encoder) {
F_2 ( V_23 -> V_511 ) ;
V_23 -> V_112 . V_21 = NULL ;
}
}
if ( V_21 -> V_68 || F_18 ( V_2 ) || F_43 ( V_2 ) -> V_81 < 5 ) {
V_21 -> V_1120 = true ;
V_21 -> V_1121 = true ;
F_653 ( V_21 ) ;
}
}
static void F_763 ( struct V_22 * V_23 )
{
struct V_521 * V_515 ;
struct V_1 * V_2 = V_23 -> V_112 . V_2 ;
bool V_1122 = V_23 -> V_112 . V_21 &&
F_34 ( V_23 -> V_112 . V_21 ) -> V_68 ;
if ( V_23 -> V_511 && ! V_1122 ) {
F_45 ( L_281 ,
V_23 -> V_112 . V_112 . V_218 ,
V_23 -> V_112 . V_119 ) ;
if ( V_23 -> V_112 . V_21 ) {
F_45 ( L_282 ,
V_23 -> V_112 . V_112 . V_218 ,
V_23 -> V_112 . V_119 ) ;
V_23 -> V_220 ( V_23 ) ;
}
V_23 -> V_112 . V_21 = NULL ;
V_23 -> V_511 = false ;
F_371 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_515 -> V_23 != V_23 )
continue;
V_515 -> V_112 . V_517 = V_518 ;
V_515 -> V_112 . V_23 = NULL ;
}
}
}
void F_764 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_1098 = F_740 ( V_2 ) ;
if ( ! ( F_4 ( V_1098 ) & V_1103 ) ) {
F_45 ( L_283 ) ;
F_739 ( V_2 ) ;
}
}
void F_765 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_79 ( V_4 , V_1123 ) )
return;
F_764 ( V_2 ) ;
}
static bool F_766 ( struct V_67 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_112 . V_2 -> V_5 ;
if ( ! V_21 -> V_68 )
return false ;
return F_4 ( F_82 ( V_21 -> V_144 ) ) & V_145 ;
}
static void F_767 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_75 V_75 ;
struct V_67 * V_21 ;
struct V_22 * V_23 ;
struct V_521 * V_515 ;
int V_146 ;
F_236 (dev, crtc) {
memset ( & V_21 -> V_71 , 0 , sizeof( V_21 -> V_71 ) ) ;
V_21 -> V_71 . V_141 |= V_996 ;
V_21 -> V_68 = V_4 -> V_308 . V_998 ( V_21 ,
& V_21 -> V_71 ) ;
V_21 -> V_112 . V_103 = V_21 -> V_68 ;
V_21 -> V_238 = F_766 ( V_21 ) ;
F_45 ( L_284 ,
V_21 -> V_112 . V_112 . V_218 ,
V_21 -> V_68 ? L_189 : L_190 ) ;
}
if ( F_65 ( V_2 ) )
F_768 ( V_2 ) ;
for ( V_146 = 0 ; V_146 < V_4 -> V_410 ; V_146 ++ ) {
struct V_111 * V_115 = & V_4 -> V_114 [ V_146 ] ;
V_115 -> V_216 = V_115 -> V_118 ( V_4 , V_115 , & V_115 -> V_117 ) ;
V_115 -> V_68 = 0 ;
F_236 (dev, crtc) {
if ( V_21 -> V_68 && F_60 ( V_21 ) == V_115 )
V_115 -> V_68 ++ ;
}
V_115 -> V_215 = V_115 -> V_68 ;
F_45 ( L_285 ,
V_115 -> V_119 , V_115 -> V_215 , V_115 -> V_216 ) ;
}
F_371 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_75 = 0 ;
if ( V_23 -> V_118 ( V_23 , & V_75 ) ) {
V_21 = F_34 ( V_4 -> V_76 [ V_75 ] ) ;
V_23 -> V_112 . V_21 = & V_21 -> V_112 ;
V_23 -> V_999 ( V_23 , & V_21 -> V_71 ) ;
} else {
V_23 -> V_112 . V_21 = NULL ;
}
V_23 -> V_511 = false ;
F_45 ( L_286 ,
V_23 -> V_112 . V_112 . V_218 ,
V_23 -> V_112 . V_119 ,
V_23 -> V_112 . V_21 ? L_189 : L_190 ,
F_73 ( V_75 ) ) ;
}
F_371 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_515 -> V_118 ( V_515 ) ) {
V_515 -> V_112 . V_517 = V_520 ;
V_515 -> V_23 -> V_511 = true ;
V_515 -> V_112 . V_23 = & V_515 -> V_23 -> V_112 ;
} else {
V_515 -> V_112 . V_517 = V_518 ;
V_515 -> V_112 . V_23 = NULL ;
}
F_45 ( L_287 ,
V_515 -> V_112 . V_112 . V_218 ,
V_515 -> V_112 . V_119 ,
V_515 -> V_112 . V_23 ? L_189 : L_190 ) ;
}
}
void F_756 ( struct V_1 * V_2 ,
bool V_1124 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_75 V_75 ;
struct V_67 * V_21 ;
struct V_22 * V_23 ;
int V_146 ;
F_767 ( V_2 ) ;
F_236 (dev, crtc) {
if ( V_21 -> V_68 && V_322 . V_323 ) {
F_442 ( & V_21 -> V_112 . V_403 , & V_21 -> V_71 ) ;
F_45 ( L_288 ,
V_21 -> V_112 . V_112 . V_218 ) ;
F_630 ( & V_21 -> V_112 . V_403 ) ;
}
}
F_371 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_763 ( V_23 ) ;
}
F_85 (pipe) {
V_21 = F_34 ( V_4 -> V_76 [ V_75 ] ) ;
F_760 ( V_21 ) ;
F_628 ( V_21 , & V_21 -> V_71 , L_289 ) ;
}
for ( V_146 = 0 ; V_146 < V_4 -> V_410 ; V_146 ++ ) {
struct V_111 * V_115 = & V_4 -> V_114 [ V_146 ] ;
if ( ! V_115 -> V_216 || V_115 -> V_68 )
continue;
F_45 ( L_290 , V_115 -> V_119 ) ;
V_115 -> V_220 ( V_4 , V_115 ) ;
V_115 -> V_216 = false ;
}
if ( F_3 ( V_2 ) )
F_769 ( V_2 ) ;
if ( V_1124 ) {
F_765 ( V_2 ) ;
F_85 (pipe) {
struct V_20 * V_21 =
V_4 -> V_76 [ V_75 ] ;
F_654 ( V_21 , & V_21 -> V_403 , V_21 -> V_258 , V_21 -> V_259 ,
V_21 -> V_69 -> V_70 ) ;
}
} else {
F_623 ( V_2 ) ;
}
F_378 ( V_2 ) ;
}
void F_770 ( struct V_1 * V_2 )
{
struct V_20 * V_291 ;
struct V_292 * V_70 ;
F_57 ( & V_2 -> V_289 ) ;
F_771 ( V_2 ) ;
F_59 ( & V_2 -> V_289 ) ;
F_745 ( V_2 ) ;
F_772 ( V_2 ) ;
F_57 ( & V_2 -> V_289 ) ;
F_187 (dev, c) {
if ( ! V_291 -> V_69 -> V_70 )
continue;
V_70 = F_183 ( V_291 -> V_69 -> V_70 ) ;
if ( F_169 ( V_2 , V_70 -> V_244 , NULL ) ) {
F_115 ( L_291 ,
F_34 ( V_291 ) -> V_75 ) ;
F_562 ( V_291 -> V_69 -> V_70 ) ;
V_291 -> V_69 -> V_70 = NULL ;
}
}
F_59 ( & V_2 -> V_289 ) ;
}
void F_773 ( struct V_521 * V_521 )
{
struct V_514 * V_515 = & V_521 -> V_112 ;
F_774 ( V_515 ) ;
F_775 ( V_515 ) ;
}
void F_776 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_514 * V_515 ;
F_777 ( V_2 ) ;
F_578 ( & V_4 -> V_1125 ) ;
F_778 ( V_2 ) ;
F_57 ( & V_2 -> V_289 ) ;
F_779 () ;
F_187 (dev, crtc) {
if ( ! V_21 -> V_69 -> V_70 )
continue;
F_198 ( V_21 ) ;
}
F_298 ( V_2 ) ;
F_780 ( V_2 ) ;
F_781 ( V_2 ) ;
F_59 ( & V_2 -> V_289 ) ;
F_782 () ;
F_371 (connector, &dev->mode_config.connector_list, head) {
struct V_521 * V_521 ;
V_521 = F_554 ( V_515 ) ;
V_521 -> V_1126 ( V_521 ) ;
}
F_783 ( V_2 ) ;
F_784 ( V_2 ) ;
F_57 ( & V_2 -> V_289 ) ;
F_785 ( V_2 ) ;
F_59 ( & V_2 -> V_289 ) ;
}
struct V_519 * F_786 ( struct V_514 * V_515 )
{
return & F_523 ( V_515 ) -> V_112 ;
}
void F_787 ( struct V_521 * V_515 ,
struct V_22 * V_23 )
{
V_515 -> V_23 = V_23 ;
F_788 ( & V_515 -> V_112 ,
& V_23 -> V_112 ) ;
}
int F_789 ( struct V_1 * V_2 , bool V_104 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned V_83 = F_43 ( V_2 ) -> V_81 >= 6 ? V_1127 : V_1128 ;
T_5 V_1129 ;
if ( F_394 ( V_4 -> V_1130 , V_83 , & V_1129 ) ) {
F_115 ( L_292 ) ;
return - V_974 ;
}
if ( ! ! ( V_1129 & V_1131 ) == ! V_104 )
return 0 ;
if ( V_104 )
V_1129 &= ~ V_1131 ;
else
V_1129 |= V_1131 ;
if ( F_790 ( V_4 -> V_1130 , V_83 , V_1129 ) ) {
F_115 ( L_293 ) ;
return - V_974 ;
}
return 0 ;
}
struct V_1132 *
F_791 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_1132 * error ;
int V_1133 [] = {
V_231 ,
V_1134 ,
V_1135 ,
V_655 ,
} ;
int V_146 ;
if ( F_43 ( V_2 ) -> V_321 == 0 )
return NULL ;
error = F_448 ( sizeof( * error ) , V_1136 ) ;
if ( error == NULL )
return NULL ;
if ( F_195 ( V_2 ) || F_163 ( V_2 ) )
error -> V_1137 = F_4 ( V_755 ) ;
F_85 (i) {
error -> V_75 [ V_146 ] . V_1138 =
F_792 ( V_4 ,
F_334 ( V_146 ) ) ;
if ( ! error -> V_75 [ V_146 ] . V_1138 )
continue;
error -> V_1139 [ V_146 ] . V_449 = F_4 ( F_77 ( V_146 ) ) ;
error -> V_1139 [ V_146 ] . V_1140 = F_4 ( F_530 ( V_146 ) ) ;
error -> V_1139 [ V_146 ] . V_112 = F_4 ( F_293 ( V_146 ) ) ;
error -> V_144 [ V_146 ] . V_449 = F_4 ( F_82 ( V_146 ) ) ;
error -> V_144 [ V_146 ] . V_285 = F_4 ( F_191 ( V_146 ) ) ;
if ( F_43 ( V_2 ) -> V_81 <= 3 ) {
error -> V_144 [ V_146 ] . V_284 = F_4 ( F_356 ( V_146 ) ) ;
error -> V_144 [ V_146 ] . V_414 = F_4 ( F_357 ( V_146 ) ) ;
}
if ( F_43 ( V_2 ) -> V_81 <= 7 && ! F_195 ( V_2 ) )
error -> V_144 [ V_146 ] . V_858 = F_4 ( F_160 ( V_146 ) ) ;
if ( F_43 ( V_2 ) -> V_81 >= 4 ) {
error -> V_144 [ V_146 ] . V_1141 = F_4 ( F_159 ( V_146 ) ) ;
error -> V_144 [ V_146 ] . V_1142 = F_4 ( F_192 ( V_146 ) ) ;
}
error -> V_75 [ V_146 ] . V_1143 = F_4 ( F_212 ( V_146 ) ) ;
if ( ! F_3 ( V_2 ) )
error -> V_75 [ V_146 ] . V_1144 = F_4 ( F_42 ( V_146 ) ) ;
}
error -> V_1145 = F_43 ( V_2 ) -> V_321 ;
if ( F_65 ( V_4 -> V_2 ) )
error -> V_1145 ++ ;
for ( V_146 = 0 ; V_146 < error -> V_1145 ; V_146 ++ ) {
enum V_74 V_77 = V_1133 [ V_146 ] ;
error -> V_74 [ V_146 ] . V_1138 =
F_792 ( V_4 ,
F_80 ( V_77 ) ) ;
if ( ! error -> V_74 [ V_146 ] . V_1138 )
continue;
error -> V_74 [ V_146 ] . V_77 = V_77 ;
error -> V_74 [ V_146 ] . V_1146 = F_4 ( F_50 ( V_77 ) ) ;
error -> V_74 [ V_146 ] . V_657 = F_4 ( F_249 ( V_77 ) ) ;
error -> V_74 [ V_146 ] . V_1147 = F_4 ( F_251 ( V_77 ) ) ;
error -> V_74 [ V_146 ] . V_917 = F_4 ( F_253 ( V_77 ) ) ;
error -> V_74 [ V_146 ] . V_659 = F_4 ( F_255 ( V_77 ) ) ;
error -> V_74 [ V_146 ] . V_1148 = F_4 ( F_257 ( V_77 ) ) ;
error -> V_74 [ V_146 ] . V_919 = F_4 ( F_259 ( V_77 ) ) ;
}
return error ;
}
void
F_793 ( struct V_1149 * V_11 ,
struct V_1 * V_2 ,
struct V_1132 * error )
{
int V_146 ;
if ( ! error )
return;
F_794 ( V_11 , L_294 , F_43 ( V_2 ) -> V_321 ) ;
if ( F_195 ( V_2 ) || F_163 ( V_2 ) )
F_794 ( V_11 , L_295 ,
error -> V_1137 ) ;
F_85 (i) {
F_794 ( V_11 , L_296 , V_146 ) ;
F_794 ( V_11 , L_297 ,
error -> V_75 [ V_146 ] . V_1138 ? L_12 : L_13 ) ;
F_794 ( V_11 , L_298 , error -> V_75 [ V_146 ] . V_1143 ) ;
F_794 ( V_11 , L_299 , error -> V_75 [ V_146 ] . V_1144 ) ;
F_794 ( V_11 , L_300 , V_146 ) ;
F_794 ( V_11 , L_301 , error -> V_144 [ V_146 ] . V_449 ) ;
F_794 ( V_11 , L_302 , error -> V_144 [ V_146 ] . V_285 ) ;
if ( F_43 ( V_2 ) -> V_81 <= 3 ) {
F_794 ( V_11 , L_303 , error -> V_144 [ V_146 ] . V_284 ) ;
F_794 ( V_11 , L_304 , error -> V_144 [ V_146 ] . V_414 ) ;
}
if ( F_43 ( V_2 ) -> V_81 <= 7 && ! F_195 ( V_2 ) )
F_794 ( V_11 , L_305 , error -> V_144 [ V_146 ] . V_858 ) ;
if ( F_43 ( V_2 ) -> V_81 >= 4 ) {
F_794 ( V_11 , L_306 , error -> V_144 [ V_146 ] . V_1141 ) ;
F_794 ( V_11 , L_307 , error -> V_144 [ V_146 ] . V_1142 ) ;
}
F_794 ( V_11 , L_308 , V_146 ) ;
F_794 ( V_11 , L_301 , error -> V_1139 [ V_146 ] . V_449 ) ;
F_794 ( V_11 , L_304 , error -> V_1139 [ V_146 ] . V_1140 ) ;
F_794 ( V_11 , L_309 , error -> V_1139 [ V_146 ] . V_112 ) ;
}
for ( V_146 = 0 ; V_146 < error -> V_1145 ; V_146 ++ ) {
F_794 ( V_11 , L_310 ,
F_629 ( error -> V_74 [ V_146 ] . V_77 ) ) ;
F_794 ( V_11 , L_297 ,
error -> V_74 [ V_146 ] . V_1138 ? L_12 : L_13 ) ;
F_794 ( V_11 , L_311 , error -> V_74 [ V_146 ] . V_1146 ) ;
F_794 ( V_11 , L_312 , error -> V_74 [ V_146 ] . V_657 ) ;
F_794 ( V_11 , L_313 , error -> V_74 [ V_146 ] . V_1147 ) ;
F_794 ( V_11 , L_314 , error -> V_74 [ V_146 ] . V_917 ) ;
F_794 ( V_11 , L_315 , error -> V_74 [ V_146 ] . V_659 ) ;
F_794 ( V_11 , L_316 , error -> V_74 [ V_146 ] . V_1148 ) ;
F_794 ( V_11 , L_317 , error -> V_74 [ V_146 ] . V_919 ) ;
}
}
