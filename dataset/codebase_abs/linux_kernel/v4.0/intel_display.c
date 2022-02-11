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
static bool F_12 ( struct V_28 * V_29 , int type )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_6 ;
F_13 (dev, encoder)
if ( V_6 -> V_31 == V_29 && V_6 -> type == type )
return true ;
return false ;
}
static const T_3 * F_14 ( struct V_28 * V_29 ,
int V_18 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
const T_3 * V_32 ;
if ( F_12 ( V_29 , V_33 ) ) {
if ( F_15 ( V_10 ) ) {
if ( V_18 == 100000 )
V_32 = & V_34 ;
else
V_32 = & V_35 ;
} else {
if ( V_18 == 100000 )
V_32 = & V_36 ;
else
V_32 = & V_37 ;
}
} else
V_32 = & V_38 ;
return V_32 ;
}
static const T_3 * F_16 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
const T_3 * V_32 ;
if ( F_12 ( V_29 , V_33 ) ) {
if ( F_15 ( V_10 ) )
V_32 = & V_39 ;
else
V_32 = & V_40 ;
} else if ( F_12 ( V_29 , V_41 ) ||
F_12 ( V_29 , V_42 ) ) {
V_32 = & V_43 ;
} else if ( F_12 ( V_29 , V_44 ) ) {
V_32 = & V_45 ;
} else
V_32 = & V_46 ;
return V_32 ;
}
static const T_3 * F_17 ( struct V_28 * V_29 , int V_18 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
const T_3 * V_32 ;
if ( F_4 ( V_10 ) )
V_32 = F_14 ( V_29 , V_18 ) ;
else if ( F_18 ( V_10 ) ) {
V_32 = F_16 ( V_29 ) ;
} else if ( F_19 ( V_10 ) ) {
if ( F_12 ( V_29 , V_33 ) )
V_32 = & V_47 ;
else
V_32 = & V_48 ;
} else if ( F_20 ( V_10 ) ) {
V_32 = & V_49 ;
} else if ( F_21 ( V_10 ) ) {
V_32 = & V_50 ;
} else if ( ! F_22 ( V_10 ) ) {
if ( F_12 ( V_29 , V_33 ) )
V_32 = & V_51 ;
else
V_32 = & V_46 ;
} else {
if ( F_12 ( V_29 , V_33 ) )
V_32 = & V_52 ;
else if ( F_12 ( V_29 , V_53 ) )
V_32 = & V_54 ;
else
V_32 = & V_55 ;
}
return V_32 ;
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
static T_4 F_24 ( struct V_56 * V_56 )
{
return 5 * ( V_56 -> V_20 + 2 ) + ( V_56 -> V_21 + 2 ) ;
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
clock -> V_26 = F_27 ( ( V_57 ) V_18 * clock -> V_19 ,
clock -> V_25 << 22 ) ;
clock -> V_27 = F_9 ( clock -> V_26 , clock -> V_22 ) ;
}
static bool F_28 ( struct V_9 * V_10 ,
const T_3 * V_32 ,
const T_2 * clock )
{
if ( clock -> V_25 < V_32 -> V_25 . V_58 || V_32 -> V_25 . V_59 < clock -> V_25 )
F_29 ( L_1 ) ;
if ( clock -> V_23 < V_32 -> V_23 . V_58 || V_32 -> V_23 . V_59 < clock -> V_23 )
F_29 ( L_2 ) ;
if ( clock -> V_21 < V_32 -> V_21 . V_58 || V_32 -> V_21 . V_59 < clock -> V_21 )
F_29 ( L_3 ) ;
if ( clock -> V_20 < V_32 -> V_20 . V_58 || V_32 -> V_20 . V_59 < clock -> V_20 )
F_29 ( L_4 ) ;
if ( ! F_19 ( V_10 ) && ! F_21 ( V_10 ) )
if ( clock -> V_20 <= clock -> V_21 )
F_29 ( L_5 ) ;
if ( ! F_21 ( V_10 ) ) {
if ( clock -> V_22 < V_32 -> V_22 . V_58 || V_32 -> V_22 . V_59 < clock -> V_22 )
F_29 ( L_6 ) ;
if ( clock -> V_19 < V_32 -> V_19 . V_58 || V_32 -> V_19 . V_59 < clock -> V_19 )
F_29 ( L_7 ) ;
}
if ( clock -> V_26 < V_32 -> V_26 . V_58 || V_32 -> V_26 . V_59 < clock -> V_26 )
F_29 ( L_8 ) ;
if ( clock -> V_27 < V_32 -> V_27 . V_58 || V_32 -> V_27 . V_59 < clock -> V_27 )
F_29 ( L_9 ) ;
return true ;
}
static bool
F_30 ( const T_3 * V_32 , struct V_28 * V_29 ,
int V_60 , int V_18 , T_2 * V_61 ,
T_2 * V_62 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock ;
int V_63 = V_60 ;
if ( F_12 ( V_29 , V_33 ) ) {
if ( F_15 ( V_10 ) )
clock . V_24 = V_32 -> V_24 . V_64 ;
else
clock . V_24 = V_32 -> V_24 . V_65 ;
} else {
if ( V_60 < V_32 -> V_24 . V_66 )
clock . V_24 = V_32 -> V_24 . V_65 ;
else
clock . V_24 = V_32 -> V_24 . V_64 ;
}
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
for ( clock . V_20 = V_32 -> V_20 . V_58 ; clock . V_20 <= V_32 -> V_20 . V_59 ;
clock . V_20 ++ ) {
for ( clock . V_21 = V_32 -> V_21 . V_58 ;
clock . V_21 <= V_32 -> V_21 . V_59 ; clock . V_21 ++ ) {
if ( clock . V_21 >= clock . V_20 )
break;
for ( clock . V_25 = V_32 -> V_25 . V_58 ;
clock . V_25 <= V_32 -> V_25 . V_59 ; clock . V_25 ++ ) {
for ( clock . V_23 = V_32 -> V_23 . V_58 ;
clock . V_23 <= V_32 -> V_23 . V_59 ; clock . V_23 ++ ) {
int V_67 ;
F_25 ( V_18 , & clock ) ;
if ( ! F_28 ( V_10 , V_32 ,
& clock ) )
continue;
if ( V_61 &&
clock . V_22 != V_61 -> V_22 )
continue;
V_67 = abs ( clock . V_27 - V_60 ) ;
if ( V_67 < V_63 ) {
* V_62 = clock ;
V_63 = V_67 ;
}
}
}
}
}
return ( V_63 != V_60 ) ;
}
static bool
F_31 ( const T_3 * V_32 , struct V_28 * V_29 ,
int V_60 , int V_18 , T_2 * V_61 ,
T_2 * V_62 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock ;
int V_63 = V_60 ;
if ( F_12 ( V_29 , V_33 ) ) {
if ( F_15 ( V_10 ) )
clock . V_24 = V_32 -> V_24 . V_64 ;
else
clock . V_24 = V_32 -> V_24 . V_65 ;
} else {
if ( V_60 < V_32 -> V_24 . V_66 )
clock . V_24 = V_32 -> V_24 . V_65 ;
else
clock . V_24 = V_32 -> V_24 . V_64 ;
}
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
for ( clock . V_20 = V_32 -> V_20 . V_58 ; clock . V_20 <= V_32 -> V_20 . V_59 ;
clock . V_20 ++ ) {
for ( clock . V_21 = V_32 -> V_21 . V_58 ;
clock . V_21 <= V_32 -> V_21 . V_59 ; clock . V_21 ++ ) {
for ( clock . V_25 = V_32 -> V_25 . V_58 ;
clock . V_25 <= V_32 -> V_25 . V_59 ; clock . V_25 ++ ) {
for ( clock . V_23 = V_32 -> V_23 . V_58 ;
clock . V_23 <= V_32 -> V_23 . V_59 ; clock . V_23 ++ ) {
int V_67 ;
F_23 ( V_18 , & clock ) ;
if ( ! F_28 ( V_10 , V_32 ,
& clock ) )
continue;
if ( V_61 &&
clock . V_22 != V_61 -> V_22 )
continue;
V_67 = abs ( clock . V_27 - V_60 ) ;
if ( V_67 < V_63 ) {
* V_62 = clock ;
V_63 = V_67 ;
}
}
}
}
}
return ( V_63 != V_60 ) ;
}
static bool
F_32 ( const T_3 * V_32 , struct V_28 * V_29 ,
int V_60 , int V_18 , T_2 * V_61 ,
T_2 * V_62 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock ;
int V_68 ;
bool V_69 ;
int V_70 = ( V_60 >> 8 ) + ( V_60 >> 9 ) ;
V_69 = false ;
if ( F_12 ( V_29 , V_33 ) ) {
if ( F_15 ( V_10 ) )
clock . V_24 = V_32 -> V_24 . V_64 ;
else
clock . V_24 = V_32 -> V_24 . V_65 ;
} else {
if ( V_60 < V_32 -> V_24 . V_66 )
clock . V_24 = V_32 -> V_24 . V_65 ;
else
clock . V_24 = V_32 -> V_24 . V_64 ;
}
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
V_68 = V_32 -> V_25 . V_59 ;
for ( clock . V_25 = V_32 -> V_25 . V_58 ; clock . V_25 <= V_68 ; clock . V_25 ++ ) {
for ( clock . V_20 = V_32 -> V_20 . V_59 ;
clock . V_20 >= V_32 -> V_20 . V_58 ; clock . V_20 -- ) {
for ( clock . V_21 = V_32 -> V_21 . V_59 ;
clock . V_21 >= V_32 -> V_21 . V_58 ; clock . V_21 -- ) {
for ( clock . V_23 = V_32 -> V_23 . V_59 ;
clock . V_23 >= V_32 -> V_23 . V_58 ; clock . V_23 -- ) {
int V_67 ;
F_25 ( V_18 , & clock ) ;
if ( ! F_28 ( V_10 , V_32 ,
& clock ) )
continue;
V_67 = abs ( clock . V_27 - V_60 ) ;
if ( V_67 < V_70 ) {
* V_62 = clock ;
V_70 = V_67 ;
V_68 = clock . V_25 ;
V_69 = true ;
}
}
}
}
}
return V_69 ;
}
static bool
F_33 ( const T_3 * V_32 , struct V_28 * V_29 ,
int V_60 , int V_18 , T_2 * V_61 ,
T_2 * V_62 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock ;
unsigned int V_71 = 1000000 ;
int V_68 = V_58 ( V_32 -> V_25 . V_59 , V_18 / 19200 ) ;
bool V_69 = false ;
V_60 *= 5 ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
for ( clock . V_25 = V_32 -> V_25 . V_58 ; clock . V_25 <= V_68 ; clock . V_25 ++ ) {
for ( clock . V_23 = V_32 -> V_23 . V_59 ; clock . V_23 >= V_32 -> V_23 . V_58 ; clock . V_23 -- ) {
for ( clock . V_24 = V_32 -> V_24 . V_64 ; clock . V_24 >= V_32 -> V_24 . V_65 ;
clock . V_24 -= clock . V_24 > 10 ? 2 : 1 ) {
clock . V_22 = clock . V_23 * clock . V_24 ;
for ( clock . V_20 = V_32 -> V_20 . V_58 ; clock . V_20 <= V_32 -> V_20 . V_59 ; clock . V_20 ++ ) {
unsigned int V_72 , V_73 ;
clock . V_21 = F_9 ( V_60 * clock . V_22 * clock . V_25 ,
V_18 * clock . V_20 ) ;
F_8 ( V_18 , & clock ) ;
if ( ! F_28 ( V_10 , V_32 ,
& clock ) )
continue;
V_73 = abs ( clock . V_27 - V_60 ) ;
V_72 = F_34 ( 1000000ULL * V_73 , V_60 ) ;
if ( V_72 < 100 && clock . V_22 > V_62 -> V_22 ) {
V_71 = 0 ;
* V_62 = clock ;
V_69 = true ;
}
if ( V_71 >= 10 && V_72 < V_71 - 10 ) {
V_71 = V_72 ;
* V_62 = clock ;
V_69 = true ;
}
}
}
}
}
return V_69 ;
}
static bool
F_35 ( const T_3 * V_32 , struct V_28 * V_29 ,
int V_60 , int V_18 , T_2 * V_61 ,
T_2 * V_62 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock ;
V_57 V_21 ;
int V_69 = false ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
clock . V_25 = 1 , clock . V_20 = 2 ;
V_60 *= 5 ;
for ( clock . V_23 = V_32 -> V_23 . V_59 ; clock . V_23 >= V_32 -> V_23 . V_58 ; clock . V_23 -- ) {
for ( clock . V_24 = V_32 -> V_24 . V_64 ;
clock . V_24 >= V_32 -> V_24 . V_65 ;
clock . V_24 -= clock . V_24 > 10 ? 2 : 1 ) {
clock . V_22 = clock . V_23 * clock . V_24 ;
V_21 = F_27 ( ( ( V_57 ) V_60 * clock . V_22 *
clock . V_25 ) << 22 , V_18 * clock . V_20 ) ;
if ( V_21 > V_74 / clock . V_20 )
continue;
clock . V_21 = V_21 ;
F_26 ( V_18 , & clock ) ;
if ( ! F_28 ( V_10 , V_32 , & clock ) )
continue;
if ( clock . V_22 > V_62 -> V_22 ) {
* V_62 = clock ;
V_69 = true ;
}
}
}
return V_69 ;
}
bool F_36 ( struct V_75 * V_29 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
return V_28 -> V_76 && V_29 -> V_77 -> V_78 &&
V_28 -> V_79 -> V_8 . V_80 . V_81 ;
}
enum V_82 F_38 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_75 * V_29 = V_12 -> V_83 [ V_4 ] ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
return V_28 -> V_79 -> V_84 ;
}
static bool F_39 ( struct V_9 * V_10 , enum V_4 V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_85 = F_40 ( V_4 ) ;
T_1 V_86 , V_87 ;
T_1 V_88 ;
if ( F_22 ( V_10 ) )
V_88 = V_89 ;
else
V_88 = V_90 ;
V_86 = F_5 ( V_85 ) & V_88 ;
F_41 ( 5 ) ;
V_87 = F_5 ( V_85 ) & V_88 ;
return V_86 == V_87 ;
}
static void F_42 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_82 V_84 = V_29 -> V_79 -> V_84 ;
enum V_4 V_4 = V_29 -> V_4 ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
int V_85 = F_44 ( V_84 ) ;
if ( F_45 ( ( F_5 ( V_85 ) & V_92 ) == 0 ,
100 ) )
F_46 ( 1 , L_10 ) ;
} else {
if ( F_45 ( F_39 ( V_10 , V_4 ) , 100 ) )
F_46 ( 1 , L_10 ) ;
}
}
bool F_47 ( struct V_11 * V_12 ,
struct V_93 * V_94 )
{
T_1 V_95 ;
if ( F_48 ( V_12 -> V_10 ) ) {
switch ( V_94 -> V_94 ) {
case V_96 :
V_95 = V_97 ;
break;
case V_98 :
V_95 = V_99 ;
break;
case V_100 :
V_95 = V_101 ;
break;
default:
return true ;
}
} else {
switch ( V_94 -> V_94 ) {
case V_96 :
V_95 = V_102 ;
break;
case V_98 :
V_95 = V_103 ;
break;
case V_100 :
V_95 = V_104 ;
break;
default:
return true ;
}
}
return F_5 ( V_105 ) & V_95 ;
}
static const char * F_49 ( bool V_106 )
{
return V_106 ? L_11 : L_12 ;
}
void F_50 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_107 )
{
int V_85 ;
T_1 V_108 ;
bool V_109 ;
V_85 = F_51 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_109 = ! ! ( V_108 & V_110 ) ;
F_52 ( V_109 != V_107 ,
L_13 ,
F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
static void F_53 ( struct V_11 * V_12 , bool V_107 )
{
T_1 V_108 ;
bool V_109 ;
F_54 ( & V_12 -> V_111 ) ;
V_108 = F_55 ( V_12 , V_112 ) ;
F_56 ( & V_12 -> V_111 ) ;
V_109 = V_108 & V_113 ;
F_52 ( V_109 != V_107 ,
L_14 ,
F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
struct V_114 *
F_57 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
if ( V_29 -> V_79 -> V_115 < 0 )
return NULL ;
return & V_12 -> V_116 [ V_29 -> V_79 -> V_115 ] ;
}
void F_58 ( struct V_11 * V_12 ,
struct V_114 * V_117 ,
bool V_107 )
{
bool V_109 ;
struct V_118 V_119 ;
if ( F_46 ( ! V_117 ,
L_15 , F_49 ( V_107 ) ) )
return;
V_109 = V_117 -> V_120 ( V_12 , V_117 , & V_119 ) ;
F_52 ( V_109 != V_107 ,
L_16 ,
V_117 -> V_121 , F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
static void F_59 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_107 )
{
int V_85 ;
T_1 V_108 ;
bool V_109 ;
enum V_82 V_84 = F_38 ( V_12 ,
V_4 ) ;
if ( F_60 ( V_12 -> V_10 ) ) {
V_85 = F_61 ( V_84 ) ;
V_108 = F_5 ( V_85 ) ;
V_109 = ! ! ( V_108 & V_122 ) ;
} else {
V_85 = F_62 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_109 = ! ! ( V_108 & V_123 ) ;
}
F_52 ( V_109 != V_107 ,
L_17 ,
F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
static void F_63 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_107 )
{
int V_85 ;
T_1 V_108 ;
bool V_109 ;
V_85 = F_64 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_109 = ! ! ( V_108 & V_124 ) ;
F_52 ( V_109 != V_107 ,
L_18 ,
F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
static void F_65 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_85 ;
T_1 V_108 ;
if ( F_43 ( V_12 -> V_10 ) -> V_91 == 5 )
return;
if ( F_60 ( V_12 -> V_10 ) )
return;
V_85 = F_62 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
F_52 ( ! ( V_108 & V_125 ) , L_19 ) ;
}
void F_66 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_107 )
{
int V_85 ;
T_1 V_108 ;
bool V_109 ;
V_85 = F_64 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_109 = ! ! ( V_108 & V_126 ) ;
F_52 ( V_109 != V_107 ,
L_20 ,
F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
void F_67 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_127 ;
T_1 V_108 ;
enum V_4 V_128 = V_129 ;
bool V_130 = true ;
if ( F_3 ( F_60 ( V_10 ) ) )
return;
if ( F_4 ( V_10 ) ) {
T_1 V_131 ;
V_127 = V_132 ;
V_131 = F_5 ( V_133 ) & V_134 ;
if ( V_131 == V_135 &&
F_5 ( V_136 ) & V_137 )
V_128 = V_138 ;
} else if ( F_21 ( V_10 ) ) {
V_127 = F_68 ( V_4 ) ;
V_128 = V_4 ;
} else {
V_127 = V_139 ;
if ( F_5 ( V_140 ) & V_137 )
V_128 = V_138 ;
}
V_108 = F_5 ( V_127 ) ;
if ( ! ( V_108 & V_141 ) ||
( ( V_108 & V_142 ) == V_143 ) )
V_130 = false ;
F_52 ( V_128 == V_4 && V_130 ,
L_21 ,
F_69 ( V_4 ) ) ;
}
static void F_70 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_107 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
bool V_109 ;
if ( F_71 ( V_10 ) || F_72 ( V_10 ) )
V_109 = F_5 ( V_144 ) & V_145 ;
else
V_109 = F_5 ( F_73 ( V_4 ) ) & V_146 ;
F_52 ( V_109 != V_107 ,
L_22 ,
F_69 ( V_4 ) , F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
void F_74 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_107 )
{
int V_85 ;
T_1 V_108 ;
bool V_109 ;
enum V_82 V_84 = F_38 ( V_12 ,
V_4 ) ;
if ( ( V_4 == V_129 && V_12 -> V_147 & V_148 ) ||
( V_4 == V_138 && V_12 -> V_147 & V_149 ) )
V_107 = true ;
if ( ! F_75 ( V_12 ,
F_76 ( V_84 ) ) ) {
V_109 = false ;
} else {
V_85 = F_44 ( V_84 ) ;
V_108 = F_5 ( V_85 ) ;
V_109 = ! ! ( V_108 & V_150 ) ;
}
F_52 ( V_109 != V_107 ,
L_23 ,
F_69 ( V_4 ) , F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
static void F_77 ( struct V_11 * V_12 ,
enum V_151 V_151 , bool V_107 )
{
int V_85 ;
T_1 V_108 ;
bool V_109 ;
V_85 = F_78 ( V_151 ) ;
V_108 = F_5 ( V_85 ) ;
V_109 = ! ! ( V_108 & V_152 ) ;
F_52 ( V_109 != V_107 ,
L_24 ,
F_79 ( V_151 ) , F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
static void F_80 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_85 , V_153 ;
T_1 V_108 ;
int V_154 ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
V_85 = F_78 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
F_52 ( V_108 & V_152 ,
L_25 ,
F_79 ( V_4 ) ) ;
return;
}
F_81 (dev_priv, i) {
V_85 = F_78 ( V_153 ) ;
V_108 = F_5 ( V_85 ) ;
V_154 = ( V_108 & V_155 ) >>
V_156 ;
F_52 ( ( V_108 & V_152 ) && V_4 == V_154 ,
L_26 ,
F_79 ( V_153 ) , F_69 ( V_4 ) ) ;
}
}
static void F_82 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_85 , V_157 ;
T_1 V_108 ;
if ( F_43 ( V_10 ) -> V_91 >= 9 ) {
F_83 (pipe, sprite) {
V_108 = F_5 ( F_84 ( V_4 , V_157 ) ) ;
F_52 ( V_108 & V_158 ,
L_27 ,
V_157 , F_69 ( V_4 ) ) ;
}
} else if ( F_21 ( V_10 ) ) {
F_83 (pipe, sprite) {
V_85 = F_85 ( V_4 , V_157 ) ;
V_108 = F_5 ( V_85 ) ;
F_52 ( V_108 & V_159 ,
L_28 ,
F_86 ( V_4 , V_157 ) , F_69 ( V_4 ) ) ;
}
} else if ( F_43 ( V_10 ) -> V_91 >= 7 ) {
V_85 = F_87 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
F_52 ( V_108 & V_160 ,
L_28 ,
F_79 ( V_4 ) , F_69 ( V_4 ) ) ;
} else if ( F_43 ( V_10 ) -> V_91 >= 5 ) {
V_85 = F_88 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
F_52 ( V_108 & V_161 ,
L_28 ,
F_79 ( V_4 ) , F_69 ( V_4 ) ) ;
}
}
static void F_89 ( struct V_75 * V_29 )
{
if ( F_90 ( F_91 ( V_29 ) == 0 ) )
F_92 ( V_29 ) ;
}
static void F_93 ( struct V_11 * V_12 )
{
T_1 V_108 ;
bool V_106 ;
F_90 ( ! ( F_48 ( V_12 -> V_10 ) || F_94 ( V_12 -> V_10 ) ) ) ;
V_108 = F_5 ( V_162 ) ;
V_106 = ! ! ( V_108 & ( V_163 | V_164 |
V_165 ) ) ;
F_52 ( ! V_106 , L_29 ) ;
}
static void F_95 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_85 ;
T_1 V_108 ;
bool V_106 ;
V_85 = F_96 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_106 = ! ! ( V_108 & V_166 ) ;
F_52 ( V_106 ,
L_30 ,
F_69 ( V_4 ) ) ;
}
static bool F_97 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_131 , T_1 V_108 )
{
if ( ( V_108 & V_167 ) == 0 )
return false ;
if ( F_94 ( V_12 -> V_10 ) ) {
T_1 V_168 = F_98 ( V_4 ) ;
T_1 V_169 = F_5 ( V_168 ) ;
if ( ( V_169 & V_170 ) != V_131 )
return false ;
} else if ( F_20 ( V_12 -> V_10 ) ) {
if ( ( V_108 & V_171 ) != F_99 ( V_4 ) )
return false ;
} else {
if ( ( V_108 & V_172 ) != ( V_4 << 30 ) )
return false ;
}
return true ;
}
static bool F_100 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_108 )
{
if ( ( V_108 & V_173 ) == 0 )
return false ;
if ( F_94 ( V_12 -> V_10 ) ) {
if ( ( V_108 & V_174 ) != F_101 ( V_4 ) )
return false ;
} else if ( F_20 ( V_12 -> V_10 ) ) {
if ( ( V_108 & V_175 ) != F_102 ( V_4 ) )
return false ;
} else {
if ( ( V_108 & V_176 ) != F_103 ( V_4 ) )
return false ;
}
return true ;
}
static bool F_104 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_108 )
{
if ( ( V_108 & V_177 ) == 0 )
return false ;
if ( F_94 ( V_12 -> V_10 ) ) {
if ( ( V_108 & V_178 ) != F_105 ( V_4 ) )
return false ;
} else {
if ( ( V_108 & V_179 ) != F_106 ( V_4 ) )
return false ;
}
return true ;
}
static bool F_107 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_108 )
{
if ( ( V_108 & V_180 ) == 0 )
return false ;
if ( F_94 ( V_12 -> V_10 ) ) {
if ( ( V_108 & V_178 ) != F_105 ( V_4 ) )
return false ;
} else {
if ( ( V_108 & V_181 ) != F_108 ( V_4 ) )
return false ;
}
return true ;
}
static void F_109 ( struct V_11 * V_12 ,
enum V_4 V_4 , int V_85 , T_1 V_131 )
{
T_1 V_108 = F_5 ( V_85 ) ;
F_52 ( F_97 ( V_12 , V_4 , V_131 , V_108 ) ,
L_31 ,
V_85 , F_69 ( V_4 ) ) ;
F_52 ( F_48 ( V_12 -> V_10 ) && ( V_108 & V_167 ) == 0
&& ( V_108 & V_182 ) ,
L_32 ) ;
}
static void F_110 ( struct V_11 * V_12 ,
enum V_4 V_4 , int V_85 )
{
T_1 V_108 = F_5 ( V_85 ) ;
F_52 ( F_100 ( V_12 , V_4 , V_108 ) ,
L_33 ,
V_85 , F_69 ( V_4 ) ) ;
F_52 ( F_48 ( V_12 -> V_10 ) && ( V_108 & V_173 ) == 0
&& ( V_108 & V_183 ) ,
L_34 ) ;
}
static void F_111 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_85 ;
T_1 V_108 ;
F_109 ( V_12 , V_4 , V_184 , V_185 ) ;
F_109 ( V_12 , V_4 , V_186 , V_187 ) ;
F_109 ( V_12 , V_4 , V_188 , V_189 ) ;
V_85 = V_190 ;
V_108 = F_5 ( V_85 ) ;
F_52 ( F_107 ( V_12 , V_4 , V_108 ) ,
L_35 ,
F_69 ( V_4 ) ) ;
V_85 = V_136 ;
V_108 = F_5 ( V_85 ) ;
F_52 ( F_104 ( V_12 , V_4 , V_108 ) ,
L_36 ,
F_69 ( V_4 ) ) ;
F_110 ( V_12 , V_4 , V_191 ) ;
F_110 ( V_12 , V_4 , V_192 ) ;
F_110 ( V_12 , V_4 , V_193 ) ;
}
static void F_112 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_21 ( V_10 ) )
return;
if ( F_20 ( V_10 ) ) {
F_113 ( V_194 ) = V_195 ;
F_113 ( V_196 ) = V_197 ;
} else {
F_113 ( V_194 ) = V_197 ;
}
}
static void F_114 ( struct V_28 * V_29 ,
const struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_85 = F_51 ( V_29 -> V_4 ) ;
T_1 V_56 = V_199 -> V_200 . V_56 ;
F_115 ( V_12 , V_29 -> V_4 ) ;
F_116 ( ! F_21 ( V_12 -> V_10 ) ) ;
if ( F_117 ( V_12 -> V_10 ) )
F_67 ( V_12 , V_29 -> V_4 ) ;
F_118 ( V_85 , V_56 ) ;
F_119 ( V_85 ) ;
F_120 ( 150 ) ;
if ( F_45 ( ( ( F_5 ( V_85 ) & V_201 ) == V_201 ) , 1 ) )
F_121 ( L_37 , V_29 -> V_4 ) ;
F_118 ( F_122 ( V_29 -> V_4 ) , V_199 -> V_200 . V_202 ) ;
F_119 ( F_122 ( V_29 -> V_4 ) ) ;
F_118 ( V_85 , V_56 ) ;
F_119 ( V_85 ) ;
F_120 ( 150 ) ;
F_118 ( V_85 , V_56 ) ;
F_119 ( V_85 ) ;
F_120 ( 150 ) ;
F_118 ( V_85 , V_56 ) ;
F_119 ( V_85 ) ;
F_120 ( 150 ) ;
}
static void F_123 ( struct V_28 * V_29 ,
const struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
enum V_203 V_94 = F_124 ( V_4 ) ;
T_1 V_204 ;
F_115 ( V_12 , V_29 -> V_4 ) ;
F_116 ( ! F_20 ( V_12 -> V_10 ) ) ;
F_54 ( & V_12 -> V_111 ) ;
V_204 = F_125 ( V_12 , V_4 , F_126 ( V_94 ) ) ;
V_204 |= V_205 ;
F_127 ( V_12 , V_4 , F_126 ( V_94 ) , V_204 ) ;
F_120 ( 1 ) ;
F_118 ( F_51 ( V_4 ) , V_199 -> V_200 . V_56 ) ;
if ( F_45 ( ( ( F_5 ( F_51 ( V_4 ) ) & V_201 ) == V_201 ) , 1 ) )
F_121 ( L_38 , V_4 ) ;
F_118 ( F_122 ( V_4 ) , V_199 -> V_200 . V_202 ) ;
F_119 ( F_122 ( V_4 ) ) ;
F_56 ( & V_12 -> V_111 ) ;
}
static int F_128 ( struct V_9 * V_10 )
{
struct V_28 * V_29 ;
int V_206 = 0 ;
F_129 (dev, crtc)
V_206 += V_29 -> V_76 &&
F_10 ( V_29 , V_53 ) ;
return V_206 ;
}
static void F_130 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_85 = F_51 ( V_29 -> V_4 ) ;
T_1 V_56 = V_29 -> V_79 -> V_200 . V_56 ;
F_115 ( V_12 , V_29 -> V_4 ) ;
F_116 ( F_43 ( V_10 ) -> V_91 >= 5 ) ;
if ( F_117 ( V_10 ) && ! F_131 ( V_10 ) )
F_67 ( V_12 , V_29 -> V_4 ) ;
if ( F_131 ( V_10 ) && F_128 ( V_10 ) > 0 ) {
V_56 |= V_207 ;
F_118 ( F_51 ( ! V_29 -> V_4 ) ,
F_5 ( F_51 ( ! V_29 -> V_4 ) ) | V_207 ) ;
}
F_119 ( V_85 ) ;
F_120 ( 150 ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
F_118 ( F_122 ( V_29 -> V_4 ) ,
V_29 -> V_79 -> V_200 . V_202 ) ;
} else {
F_118 ( V_85 , V_56 ) ;
}
F_118 ( V_85 , V_56 ) ;
F_119 ( V_85 ) ;
F_120 ( 150 ) ;
F_118 ( V_85 , V_56 ) ;
F_119 ( V_85 ) ;
F_120 ( 150 ) ;
F_118 ( V_85 , V_56 ) ;
F_119 ( V_85 ) ;
F_120 ( 150 ) ;
}
static void F_132 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
if ( F_131 ( V_10 ) &&
F_10 ( V_29 , V_53 ) &&
F_128 ( V_10 ) == 1 ) {
F_118 ( F_51 ( V_138 ) ,
F_5 ( F_51 ( V_138 ) ) & ~ V_207 ) ;
F_118 ( F_51 ( V_129 ) ,
F_5 ( F_51 ( V_129 ) ) & ~ V_207 ) ;
}
if ( ( V_4 == V_129 && V_12 -> V_147 & V_148 ) ||
( V_4 == V_138 && V_12 -> V_147 & V_149 ) )
return;
F_115 ( V_12 , V_4 ) ;
F_118 ( F_51 ( V_4 ) , 0 ) ;
F_119 ( F_51 ( V_4 ) ) ;
}
static void F_133 ( struct V_11 * V_12 , enum V_4 V_4 )
{
T_1 V_108 = 0 ;
F_115 ( V_12 , V_4 ) ;
if ( V_4 == V_138 )
V_108 = V_208 | V_209 ;
F_118 ( F_51 ( V_4 ) , V_108 ) ;
F_119 ( F_51 ( V_4 ) ) ;
}
static void F_134 ( struct V_11 * V_12 , enum V_4 V_4 )
{
enum V_203 V_94 = F_124 ( V_4 ) ;
T_1 V_108 ;
F_115 ( V_12 , V_4 ) ;
V_108 = V_210 | V_209 ;
if ( V_4 != V_129 )
V_108 |= V_208 ;
F_118 ( F_51 ( V_4 ) , V_108 ) ;
F_119 ( F_51 ( V_4 ) ) ;
F_54 ( & V_12 -> V_111 ) ;
V_108 = F_125 ( V_12 , V_4 , F_126 ( V_94 ) ) ;
V_108 &= ~ V_205 ;
F_127 ( V_12 , V_4 , F_126 ( V_94 ) , V_108 ) ;
if ( V_4 != V_138 ) {
V_108 = F_125 ( V_12 , V_4 , V_211 ) ;
V_108 &= ~ ( V_212 | V_213 ) ;
F_127 ( V_12 , V_4 , V_211 , V_108 ) ;
} else {
V_108 = F_125 ( V_12 , V_4 , V_214 ) ;
V_108 &= ~ ( V_215 | V_216 ) ;
F_127 ( V_12 , V_4 , V_214 , V_108 ) ;
}
F_56 ( & V_12 -> V_111 ) ;
}
void F_135 ( struct V_11 * V_12 ,
struct V_93 * V_217 )
{
T_1 V_218 ;
int V_219 ;
switch ( V_217 -> V_94 ) {
case V_96 :
V_218 = V_220 ;
V_219 = F_51 ( 0 ) ;
break;
case V_98 :
V_218 = V_221 ;
V_219 = F_51 ( 0 ) ;
break;
case V_100 :
V_218 = V_222 ;
V_219 = V_223 ;
break;
default:
F_136 () ;
}
if ( F_45 ( ( F_5 ( V_219 ) & V_218 ) == 0 , 1000 ) )
F_46 ( 1 , L_39 ,
F_137 ( V_217 -> V_94 ) , F_5 ( V_219 ) ) ;
}
static void F_138 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_114 * V_117 = F_57 ( V_29 ) ;
if ( F_3 ( V_117 == NULL ) )
return;
F_3 ( ! V_117 -> V_79 . V_224 ) ;
if ( V_117 -> V_76 == 0 ) {
F_139 ( L_40 , V_117 -> V_121 ) ;
F_3 ( V_117 -> V_225 ) ;
F_140 ( V_12 , V_117 ) ;
V_117 -> V_226 ( V_12 , V_117 ) ;
}
}
static void F_141 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_114 * V_117 = F_57 ( V_29 ) ;
if ( F_3 ( V_117 == NULL ) )
return;
if ( F_3 ( V_117 -> V_79 . V_224 == 0 ) )
return;
F_142 ( L_41 ,
V_117 -> V_121 , V_117 -> V_76 , V_117 -> V_225 ,
V_29 -> V_8 . V_8 . V_227 ) ;
if ( V_117 -> V_76 ++ ) {
F_3 ( ! V_117 -> V_225 ) ;
F_143 ( V_12 , V_117 ) ;
return;
}
F_3 ( V_117 -> V_225 ) ;
F_144 ( V_12 , V_228 ) ;
F_142 ( L_42 , V_117 -> V_121 ) ;
V_117 -> V_229 ( V_12 , V_117 ) ;
V_117 -> V_225 = true ;
}
static void F_145 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_114 * V_117 = F_57 ( V_29 ) ;
F_116 ( F_43 ( V_10 ) -> V_91 < 5 ) ;
if ( F_3 ( V_117 == NULL ) )
return;
if ( F_3 ( V_117 -> V_79 . V_224 == 0 ) )
return;
F_142 ( L_43 ,
V_117 -> V_121 , V_117 -> V_76 , V_117 -> V_225 ,
V_29 -> V_8 . V_8 . V_227 ) ;
if ( F_3 ( V_117 -> V_76 == 0 ) ) {
F_140 ( V_12 , V_117 ) ;
return;
}
F_143 ( V_12 , V_117 ) ;
F_3 ( ! V_117 -> V_225 ) ;
if ( -- V_117 -> V_76 )
return;
F_142 ( L_44 , V_117 -> V_121 ) ;
V_117 -> V_230 ( V_12 , V_117 ) ;
V_117 -> V_225 = false ;
F_146 ( V_12 , V_228 ) ;
}
static void F_147 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_75 * V_29 = V_12 -> V_83 [ V_4 ] ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_4 V_85 , V_108 , V_231 ;
F_116 ( ! F_4 ( V_10 ) ) ;
F_143 ( V_12 ,
F_57 ( V_28 ) ) ;
F_148 ( V_12 , V_4 ) ;
F_149 ( V_12 , V_4 ) ;
if ( F_94 ( V_10 ) ) {
V_85 = F_150 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_108 |= V_232 ;
F_118 ( V_85 , V_108 ) ;
}
V_85 = F_96 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_231 = F_5 ( F_44 ( V_4 ) ) ;
if ( F_48 ( V_12 -> V_10 ) ) {
V_108 &= ~ V_233 ;
V_108 |= V_231 & V_233 ;
}
V_108 &= ~ V_234 ;
if ( ( V_231 & V_235 ) == V_236 )
if ( F_48 ( V_12 -> V_10 ) &&
F_10 ( V_28 , V_44 ) )
V_108 |= V_237 ;
else
V_108 |= V_238 ;
else
V_108 |= V_239 ;
F_118 ( V_85 , V_108 | V_166 ) ;
if ( F_45 ( F_5 ( V_85 ) & V_240 , 100 ) )
F_121 ( L_45 , F_69 ( V_4 ) ) ;
}
static void F_151 ( struct V_11 * V_12 ,
enum V_82 V_84 )
{
T_1 V_108 , V_231 ;
F_116 ( ! F_4 ( V_12 -> V_10 ) ) ;
F_148 ( V_12 , (enum V_4 ) V_84 ) ;
F_149 ( V_12 , V_241 ) ;
V_108 = F_5 ( V_242 ) ;
V_108 |= V_232 ;
F_118 ( V_242 , V_108 ) ;
V_108 = V_166 ;
V_231 = F_5 ( F_44 ( V_84 ) ) ;
if ( ( V_231 & V_243 ) ==
V_236 )
V_108 |= V_238 ;
else
V_108 |= V_239 ;
F_118 ( V_244 , V_108 ) ;
if ( F_45 ( F_5 ( V_244 ) & V_240 , 100 ) )
F_121 ( L_46 ) ;
}
static void F_152 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_85 , V_108 ;
F_153 ( V_12 , V_4 ) ;
F_154 ( V_12 , V_4 ) ;
F_111 ( V_12 , V_4 ) ;
V_85 = F_96 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_108 &= ~ V_166 ;
F_118 ( V_85 , V_108 ) ;
if ( F_45 ( ( F_5 ( V_85 ) & V_240 ) == 0 , 50 ) )
F_121 ( L_47 , F_69 ( V_4 ) ) ;
if ( ! F_48 ( V_10 ) ) {
V_85 = F_150 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_108 &= ~ V_232 ;
F_118 ( V_85 , V_108 ) ;
}
}
static void F_155 ( struct V_11 * V_12 )
{
T_1 V_108 ;
V_108 = F_5 ( V_244 ) ;
V_108 &= ~ V_166 ;
F_118 ( V_244 , V_108 ) ;
if ( F_45 ( ( F_5 ( V_244 ) & V_240 ) == 0 , 50 ) )
F_121 ( L_48 ) ;
V_108 = F_5 ( V_242 ) ;
V_108 &= ~ V_232 ;
F_118 ( V_242 , V_108 ) ;
}
static void F_156 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
enum V_82 V_84 = F_38 ( V_12 ,
V_4 ) ;
enum V_4 V_245 ;
int V_85 ;
T_1 V_108 ;
F_80 ( V_12 , V_4 ) ;
F_157 ( V_12 , V_4 ) ;
F_82 ( V_12 , V_4 ) ;
if ( F_158 ( V_12 -> V_10 ) )
V_245 = V_241 ;
else
V_245 = V_4 ;
if ( ! F_4 ( V_12 -> V_10 ) )
if ( F_10 ( V_29 , V_246 ) )
F_159 ( V_12 ) ;
else
F_160 ( V_12 , V_4 ) ;
else {
if ( V_29 -> V_79 -> V_247 ) {
F_161 ( V_12 , V_245 ) ;
F_65 ( V_12 ,
(enum V_4 ) V_84 ) ;
}
}
V_85 = F_44 ( V_84 ) ;
V_108 = F_5 ( V_85 ) ;
if ( V_108 & V_150 ) {
F_3 ( ! ( ( V_4 == V_129 && V_12 -> V_147 & V_148 ) ||
( V_4 == V_138 && V_12 -> V_147 & V_149 ) ) ) ;
return;
}
F_118 ( V_85 , V_108 | V_150 ) ;
F_119 ( V_85 ) ;
}
static void F_162 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
enum V_82 V_84 = V_29 -> V_79 -> V_84 ;
enum V_4 V_4 = V_29 -> V_4 ;
int V_85 ;
T_1 V_108 ;
F_80 ( V_12 , V_4 ) ;
F_157 ( V_12 , V_4 ) ;
F_82 ( V_12 , V_4 ) ;
V_85 = F_44 ( V_84 ) ;
V_108 = F_5 ( V_85 ) ;
if ( ( V_108 & V_150 ) == 0 )
return;
if ( V_29 -> V_79 -> V_248 )
V_108 &= ~ V_249 ;
if ( ! ( V_4 == V_129 && V_12 -> V_147 & V_148 ) &&
! ( V_4 == V_138 && V_12 -> V_147 & V_149 ) )
V_108 &= ~ V_150 ;
F_118 ( V_85 , V_108 ) ;
if ( ( V_108 & V_150 ) == 0 )
F_42 ( V_29 ) ;
}
void F_163 ( struct V_11 * V_12 ,
enum V_151 V_151 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_1 V_85 = F_43 ( V_10 ) -> V_91 >= 4 ? F_164 ( V_151 ) : F_165 ( V_151 ) ;
F_118 ( V_85 , F_5 ( V_85 ) ) ;
F_119 ( V_85 ) ;
}
static void F_166 ( struct V_250 * V_151 ,
struct V_75 * V_29 )
{
struct V_9 * V_10 = V_151 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
F_167 ( V_12 , V_28 -> V_4 ) ;
if ( V_28 -> V_251 )
return;
V_28 -> V_251 = true ;
V_12 -> V_252 . V_253 ( V_29 , V_151 -> V_78 ,
V_29 -> V_254 , V_29 -> V_255 ) ;
if ( F_168 ( V_10 ) )
F_169 ( V_10 , V_28 -> V_4 ) ;
}
static void F_170 ( struct V_250 * V_151 ,
struct V_75 * V_29 )
{
struct V_9 * V_10 = V_151 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
if ( F_3 ( ! V_28 -> V_76 ) )
return;
if ( ! V_28 -> V_251 )
return;
V_28 -> V_251 = false ;
V_12 -> V_252 . V_253 ( V_29 , V_151 -> V_78 ,
V_29 -> V_254 , V_29 -> V_255 ) ;
}
static bool F_171 ( struct V_9 * V_10 )
{
#ifdef F_172
if ( F_43 ( V_10 ) -> V_91 >= 6 && V_256 )
return true ;
#endif
return false ;
}
int
F_173 ( struct V_9 * V_10 , int V_257 , unsigned int V_258 )
{
int V_259 ;
V_259 = V_258 ? ( F_22 ( V_10 ) ? 16 : 8 ) : 1 ;
return F_174 ( V_257 , V_259 ) ;
}
int
F_175 ( struct V_250 * V_151 ,
struct V_260 * V_78 ,
struct V_261 * V_262 )
{
struct V_9 * V_10 = V_78 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_263 * V_264 = F_176 ( V_78 ) ;
T_1 V_265 ;
int V_266 ;
F_3 ( ! F_177 ( & V_10 -> V_267 ) ) ;
switch ( V_264 -> V_268 ) {
case V_269 :
if ( F_43 ( V_10 ) -> V_91 >= 9 )
V_265 = 256 * 1024 ;
else if ( F_178 ( V_10 ) || F_179 ( V_10 ) )
V_265 = 128 * 1024 ;
else if ( F_43 ( V_10 ) -> V_91 >= 4 )
V_265 = 4 * 1024 ;
else
V_265 = 64 * 1024 ;
break;
case V_270 :
if ( F_43 ( V_10 ) -> V_91 >= 9 )
V_265 = 256 * 1024 ;
else {
V_265 = 0 ;
}
break;
case V_271 :
F_46 ( 1 , L_49 ) ;
return - V_272 ;
default:
F_136 () ;
}
if ( F_171 ( V_10 ) && V_265 < 256 * 1024 )
V_265 = 256 * 1024 ;
F_180 ( V_12 ) ;
V_12 -> V_273 . V_274 = false ;
V_266 = F_181 ( V_264 , V_265 , V_262 ) ;
if ( V_266 )
goto V_275;
V_266 = F_182 ( V_264 ) ;
if ( V_266 )
goto V_276;
F_183 ( V_264 ) ;
V_12 -> V_273 . V_274 = true ;
F_184 ( V_12 ) ;
return 0 ;
V_276:
F_185 ( V_264 ) ;
V_275:
V_12 -> V_273 . V_274 = true ;
F_184 ( V_12 ) ;
return V_266 ;
}
void F_186 ( struct V_263 * V_264 )
{
F_3 ( ! F_177 ( & V_264 -> V_8 . V_10 -> V_267 ) ) ;
F_187 ( V_264 ) ;
F_185 ( V_264 ) ;
}
unsigned long F_188 ( int * V_254 , int * V_255 ,
unsigned int V_268 ,
unsigned int V_277 ,
unsigned int V_278 )
{
if ( V_268 != V_269 ) {
unsigned int V_279 , V_280 ;
V_279 = * V_255 / 8 ;
* V_255 %= 8 ;
V_280 = * V_254 / ( 512 / V_277 ) ;
* V_254 %= 512 / V_277 ;
return V_279 * V_278 * 8 + V_280 * 4096 ;
} else {
unsigned int V_281 ;
V_281 = * V_255 * V_278 + * V_254 * V_277 ;
* V_255 = 0 ;
* V_254 = ( V_281 & 4095 ) / V_277 ;
return V_281 & - 4096 ;
}
}
static int F_189 ( int V_282 )
{
switch ( V_282 ) {
case V_283 :
return V_284 ;
case V_285 :
return V_286 ;
case V_287 :
return V_288 ;
default:
case V_289 :
return V_290 ;
case V_291 :
return V_292 ;
case V_293 :
return V_294 ;
case V_295 :
return V_296 ;
}
}
static int F_190 ( int V_282 , bool V_297 , bool V_298 )
{
switch ( V_282 ) {
case V_299 :
return V_288 ;
default:
case V_300 :
if ( V_297 ) {
if ( V_298 )
return V_301 ;
else
return V_292 ;
} else {
if ( V_298 )
return V_302 ;
else
return V_290 ;
}
case V_303 :
if ( V_297 )
return V_296 ;
else
return V_294 ;
}
}
static bool
F_191 ( struct V_28 * V_29 ,
struct V_304 * V_305 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_263 * V_264 = NULL ;
struct V_306 V_307 = { 0 } ;
T_1 V_308 = F_192 ( V_305 -> V_8 , V_309 ) ;
T_1 V_310 = F_193 ( V_305 -> V_8 + V_305 -> V_311 ,
V_309 ) ;
V_310 -= V_308 ;
if ( V_305 -> V_311 == 0 )
return false ;
V_264 = F_194 ( V_10 ,
V_308 ,
V_308 ,
V_310 ) ;
if ( ! V_264 )
return false ;
V_264 -> V_268 = V_305 -> V_258 ;
if ( V_264 -> V_268 == V_270 )
V_264 -> V_312 = V_29 -> V_8 . V_77 -> V_78 -> V_313 [ 0 ] ;
V_307 . V_314 = V_29 -> V_8 . V_77 -> V_78 -> V_314 ;
V_307 . V_315 = V_29 -> V_8 . V_77 -> V_78 -> V_315 ;
V_307 . V_257 = V_29 -> V_8 . V_77 -> V_78 -> V_257 ;
V_307 . V_313 [ 0 ] = V_29 -> V_8 . V_77 -> V_78 -> V_313 [ 0 ] ;
F_54 ( & V_10 -> V_267 ) ;
if ( F_195 ( V_10 , F_196 ( V_29 -> V_8 . V_77 -> V_78 ) ,
& V_307 , V_264 ) ) {
F_142 ( L_50 ) ;
goto V_316;
}
V_264 -> V_317 = F_197 ( V_29 -> V_4 ) ;
F_56 ( & V_10 -> V_267 ) ;
F_142 ( L_51 , V_264 ) ;
return true ;
V_316:
F_198 ( & V_264 -> V_8 ) ;
F_56 ( & V_10 -> V_267 ) ;
return false ;
}
static void
F_199 ( struct V_250 * V_151 )
{
if ( V_151 -> V_78 != V_151 -> V_107 -> V_78 )
F_200 ( V_151 -> V_107 , V_151 -> V_78 ) ;
}
static void
F_201 ( struct V_28 * V_28 ,
struct V_304 * V_305 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_318 ;
struct V_28 * V_153 ;
struct V_263 * V_264 ;
if ( ! V_28 -> V_8 . V_77 -> V_78 )
return;
if ( F_191 ( V_28 , V_305 ) ) {
struct V_250 * V_77 = V_28 -> V_8 . V_77 ;
V_77 -> V_107 -> V_29 = & V_28 -> V_8 ;
V_77 -> V_29 = & V_28 -> V_8 ;
F_199 ( V_77 ) ;
return;
}
F_202 ( V_28 -> V_8 . V_77 -> V_78 ) ;
V_28 -> V_8 . V_77 -> V_78 = NULL ;
F_203 (dev, c) {
V_153 = F_37 ( V_318 ) ;
if ( V_318 == & V_28 -> V_8 )
continue;
if ( ! V_153 -> V_76 )
continue;
V_264 = F_176 ( V_318 -> V_77 -> V_78 ) ;
if ( V_264 == NULL )
continue;
if ( F_204 ( V_264 ) == V_305 -> V_8 ) {
struct V_250 * V_77 = V_28 -> V_8 . V_77 ;
if ( V_264 -> V_268 != V_269 )
V_12 -> V_319 = true ;
F_205 ( V_318 -> V_77 -> V_78 ) ;
V_77 -> V_78 = V_318 -> V_77 -> V_78 ;
V_77 -> V_107 -> V_29 = & V_28 -> V_8 ;
V_77 -> V_29 = & V_28 -> V_8 ;
V_264 -> V_317 |= F_197 ( V_28 -> V_4 ) ;
break;
}
}
F_199 ( V_28 -> V_8 . V_77 ) ;
}
static void F_206 ( struct V_75 * V_29 ,
struct V_260 * V_78 ,
int V_254 , int V_255 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_263 * V_264 ;
int V_151 = V_28 -> V_151 ;
unsigned long V_320 ;
T_1 V_321 ;
T_1 V_85 = F_78 ( V_151 ) ;
int V_322 ;
if ( ! V_28 -> V_251 ) {
F_118 ( V_85 , 0 ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 )
F_118 ( F_164 ( V_151 ) , 0 ) ;
else
F_118 ( F_165 ( V_151 ) , 0 ) ;
F_119 ( V_85 ) ;
return;
}
V_264 = F_176 ( V_78 ) ;
if ( F_3 ( V_264 == NULL ) )
return;
V_322 = F_207 ( V_78 -> V_314 , 0 ) ;
V_321 = V_323 ;
V_321 |= V_152 ;
if ( F_43 ( V_10 ) -> V_91 < 4 ) {
if ( V_28 -> V_4 == V_138 )
V_321 |= V_324 ;
F_118 ( F_208 ( V_151 ) ,
( ( V_28 -> V_79 -> V_325 - 1 ) << 16 ) |
( V_28 -> V_79 -> V_326 - 1 ) ) ;
F_118 ( F_209 ( V_151 ) , 0 ) ;
} else if ( F_20 ( V_10 ) && V_151 == V_327 ) {
F_118 ( F_210 ( V_151 ) ,
( ( V_28 -> V_79 -> V_325 - 1 ) << 16 ) |
( V_28 -> V_79 -> V_326 - 1 ) ) ;
F_118 ( F_211 ( V_151 ) , 0 ) ;
F_118 ( F_212 ( V_151 ) , 0 ) ;
}
switch ( V_78 -> V_314 ) {
case V_284 :
V_321 |= V_283 ;
break;
case V_286 :
case V_328 :
V_321 |= V_285 ;
break;
case V_288 :
V_321 |= V_287 ;
break;
case V_290 :
case V_302 :
V_321 |= V_289 ;
break;
case V_292 :
case V_301 :
V_321 |= V_291 ;
break;
case V_294 :
case V_329 :
V_321 |= V_293 ;
break;
case V_296 :
case V_330 :
V_321 |= V_295 ;
break;
default:
F_136 () ;
}
if ( F_43 ( V_10 ) -> V_91 >= 4 &&
V_264 -> V_268 != V_269 )
V_321 |= V_331 ;
if ( F_18 ( V_10 ) )
V_321 |= V_332 ;
V_320 = V_255 * V_78 -> V_313 [ 0 ] + V_254 * V_322 ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
V_28 -> V_333 =
F_188 ( & V_254 , & V_255 , V_264 -> V_268 ,
V_322 ,
V_78 -> V_313 [ 0 ] ) ;
V_320 -= V_28 -> V_333 ;
} else {
V_28 -> V_333 = V_320 ;
}
if ( V_29 -> V_77 -> V_107 -> V_334 == F_213 ( V_335 ) ) {
V_321 |= V_336 ;
V_254 += ( V_28 -> V_79 -> V_326 - 1 ) ;
V_255 += ( V_28 -> V_79 -> V_325 - 1 ) ;
V_320 +=
( V_28 -> V_79 -> V_325 - 1 ) * V_78 -> V_313 [ 0 ] +
( V_28 -> V_79 -> V_326 - 1 ) * V_322 ;
}
F_118 ( V_85 , V_321 ) ;
F_142 ( L_52 ,
F_204 ( V_264 ) , V_320 , V_254 , V_255 ,
V_78 -> V_313 [ 0 ] ) ;
F_118 ( F_214 ( V_151 ) , V_78 -> V_313 [ 0 ] ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
F_118 ( F_164 ( V_151 ) ,
F_204 ( V_264 ) + V_28 -> V_333 ) ;
F_118 ( F_215 ( V_151 ) , ( V_255 << 16 ) | V_254 ) ;
F_118 ( F_216 ( V_151 ) , V_320 ) ;
} else
F_118 ( F_165 ( V_151 ) , F_204 ( V_264 ) + V_320 ) ;
F_119 ( V_85 ) ;
}
static void F_217 ( struct V_75 * V_29 ,
struct V_260 * V_78 ,
int V_254 , int V_255 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_263 * V_264 ;
int V_151 = V_28 -> V_151 ;
unsigned long V_320 ;
T_1 V_321 ;
T_1 V_85 = F_78 ( V_151 ) ;
int V_322 ;
if ( ! V_28 -> V_251 ) {
F_118 ( V_85 , 0 ) ;
F_118 ( F_164 ( V_151 ) , 0 ) ;
F_119 ( V_85 ) ;
return;
}
V_264 = F_176 ( V_78 ) ;
if ( F_3 ( V_264 == NULL ) )
return;
V_322 = F_207 ( V_78 -> V_314 , 0 ) ;
V_321 = V_323 ;
V_321 |= V_152 ;
if ( F_218 ( V_10 ) || F_168 ( V_10 ) )
V_321 |= V_337 ;
switch ( V_78 -> V_314 ) {
case V_284 :
V_321 |= V_283 ;
break;
case V_288 :
V_321 |= V_287 ;
break;
case V_290 :
case V_302 :
V_321 |= V_289 ;
break;
case V_292 :
case V_301 :
V_321 |= V_291 ;
break;
case V_294 :
case V_329 :
V_321 |= V_293 ;
break;
case V_296 :
case V_330 :
V_321 |= V_295 ;
break;
default:
F_136 () ;
}
if ( V_264 -> V_268 != V_269 )
V_321 |= V_331 ;
if ( ! F_218 ( V_10 ) && ! F_168 ( V_10 ) )
V_321 |= V_332 ;
V_320 = V_255 * V_78 -> V_313 [ 0 ] + V_254 * V_322 ;
V_28 -> V_333 =
F_188 ( & V_254 , & V_255 , V_264 -> V_268 ,
V_322 ,
V_78 -> V_313 [ 0 ] ) ;
V_320 -= V_28 -> V_333 ;
if ( V_29 -> V_77 -> V_107 -> V_334 == F_213 ( V_335 ) ) {
V_321 |= V_336 ;
if ( ! F_218 ( V_10 ) && ! F_168 ( V_10 ) ) {
V_254 += ( V_28 -> V_79 -> V_326 - 1 ) ;
V_255 += ( V_28 -> V_79 -> V_325 - 1 ) ;
V_320 +=
( V_28 -> V_79 -> V_325 - 1 ) * V_78 -> V_313 [ 0 ] +
( V_28 -> V_79 -> V_326 - 1 ) * V_322 ;
}
}
F_118 ( V_85 , V_321 ) ;
F_142 ( L_52 ,
F_204 ( V_264 ) , V_320 , V_254 , V_255 ,
V_78 -> V_313 [ 0 ] ) ;
F_118 ( F_214 ( V_151 ) , V_78 -> V_313 [ 0 ] ) ;
F_118 ( F_164 ( V_151 ) ,
F_204 ( V_264 ) + V_28 -> V_333 ) ;
if ( F_218 ( V_10 ) || F_168 ( V_10 ) ) {
F_118 ( F_219 ( V_151 ) , ( V_255 << 16 ) | V_254 ) ;
} else {
F_118 ( F_215 ( V_151 ) , ( V_255 << 16 ) | V_254 ) ;
F_118 ( F_216 ( V_151 ) , V_320 ) ;
}
F_119 ( V_85 ) ;
}
static void F_220 ( struct V_75 * V_29 ,
struct V_260 * V_78 ,
int V_254 , int V_255 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_338 * V_339 ;
struct V_263 * V_264 ;
int V_4 = V_28 -> V_4 ;
T_1 V_340 , V_312 ;
if ( ! V_28 -> V_251 ) {
F_118 ( F_84 ( V_4 , 0 ) , 0 ) ;
F_118 ( F_221 ( V_4 , 0 ) , 0 ) ;
F_119 ( F_84 ( V_4 , 0 ) ) ;
return;
}
V_340 = V_158 |
V_341 |
V_342 ;
switch ( V_78 -> V_314 ) {
case V_288 :
V_340 |= V_299 ;
break;
case V_290 :
V_340 |= V_300 ;
break;
case V_302 :
V_340 |= V_300 ;
V_340 |= V_343 ;
break;
case V_292 :
V_340 |= V_344 ;
V_340 |= V_300 ;
break;
case V_301 :
V_340 |= V_344 ;
V_340 |= V_300 ;
V_340 |= V_343 ;
break;
case V_294 :
V_340 |= V_303 ;
break;
case V_296 :
V_340 |= V_344 ;
V_340 |= V_303 ;
break;
default:
F_136 () ;
}
V_339 = F_196 ( V_78 ) ;
V_264 = V_339 -> V_264 ;
switch ( V_264 -> V_268 ) {
case V_269 :
V_312 = V_78 -> V_313 [ 0 ] >> 6 ;
break;
case V_270 :
V_340 |= V_345 ;
V_312 = V_78 -> V_313 [ 0 ] >> 9 ;
break;
default:
F_136 () ;
}
V_340 |= V_346 ;
if ( V_29 -> V_77 -> V_107 -> V_334 == F_213 ( V_335 ) )
V_340 |= V_347 ;
F_118 ( F_84 ( V_4 , 0 ) , V_340 ) ;
F_142 ( L_53 ,
F_204 ( V_264 ) ,
V_254 , V_255 , V_78 -> V_315 , V_78 -> V_257 ,
V_78 -> V_313 [ 0 ] ) ;
F_118 ( F_222 ( V_4 , 0 ) , 0 ) ;
F_118 ( F_223 ( V_4 , 0 ) , ( V_255 << 16 ) | V_254 ) ;
F_118 ( F_224 ( V_4 , 0 ) ,
( V_28 -> V_79 -> V_325 - 1 ) << 16 |
( V_28 -> V_79 -> V_326 - 1 ) ) ;
F_118 ( F_225 ( V_4 , 0 ) , V_312 ) ;
F_118 ( F_221 ( V_4 , 0 ) , F_204 ( V_264 ) ) ;
F_119 ( F_221 ( V_4 , 0 ) ) ;
}
static int
F_226 ( struct V_75 * V_29 , struct V_260 * V_78 ,
int V_254 , int V_255 , enum V_348 V_107 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_12 -> V_252 . V_349 )
V_12 -> V_252 . V_349 ( V_10 ) ;
V_12 -> V_252 . V_253 ( V_29 , V_78 , V_254 , V_255 ) ;
return 0 ;
}
static void F_227 ( struct V_9 * V_10 )
{
struct V_75 * V_29 ;
F_203 (dev, crtc) {
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_151 V_151 = V_28 -> V_151 ;
F_228 ( V_10 , V_151 ) ;
F_229 ( V_10 , V_151 ) ;
}
}
static void F_230 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_29 ;
F_203 (dev, crtc) {
struct V_28 * V_28 = F_37 ( V_29 ) ;
F_231 ( & V_29 -> V_350 , NULL ) ;
if ( V_28 -> V_76 && V_29 -> V_77 -> V_78 )
V_12 -> V_252 . V_253 ( V_29 ,
V_29 -> V_77 -> V_78 ,
V_29 -> V_254 ,
V_29 -> V_255 ) ;
F_232 ( & V_29 -> V_350 ) ;
}
}
void F_233 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_234 ( V_10 ) ;
struct V_28 * V_29 ;
if ( F_22 ( V_10 ) )
return;
if ( F_43 ( V_10 ) -> V_91 >= 5 || F_18 ( V_10 ) )
return;
F_235 ( V_10 ) ;
F_129 (dev, crtc) {
if ( V_29 -> V_76 )
V_12 -> V_252 . V_351 ( & V_29 -> V_8 ) ;
}
}
void F_236 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_234 ( V_10 ) ;
F_227 ( V_10 ) ;
if ( F_22 ( V_10 ) )
return;
if ( F_43 ( V_10 ) -> V_91 >= 5 || F_18 ( V_10 ) ) {
F_230 ( V_10 ) ;
return;
}
F_237 ( V_12 ) ;
F_238 ( V_12 ) ;
F_239 ( V_10 ) ;
F_240 ( & V_12 -> V_352 ) ;
if ( V_12 -> V_252 . V_353 )
V_12 -> V_252 . V_353 ( V_10 ) ;
F_241 ( & V_12 -> V_352 ) ;
F_242 ( V_10 , true ) ;
F_243 ( V_12 ) ;
F_244 ( V_10 ) ;
}
static int
F_245 ( struct V_260 * V_354 )
{
struct V_263 * V_264 = F_176 ( V_354 ) ;
struct V_11 * V_12 = V_264 -> V_8 . V_10 -> V_13 ;
bool V_355 = V_12 -> V_273 . V_274 ;
int V_266 ;
V_12 -> V_273 . V_274 = false ;
V_266 = F_246 ( V_264 ) ;
V_12 -> V_273 . V_274 = V_355 ;
return V_266 ;
}
static bool F_247 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
bool V_356 ;
if ( F_248 ( & V_12 -> V_357 ) ||
V_28 -> V_358 != F_249 ( & V_12 -> V_357 . V_358 ) )
return false ;
F_240 ( & V_10 -> V_359 ) ;
V_356 = F_37 ( V_29 ) -> V_360 != NULL ;
F_241 ( & V_10 -> V_359 ) ;
return V_356 ;
}
static void F_250 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
const struct V_361 * V_80 ;
if ( ! V_362 . V_363 )
return;
V_80 = & V_29 -> V_79 -> V_8 . V_80 ;
F_118 ( F_251 ( V_29 -> V_4 ) ,
( ( V_80 -> V_364 - 1 ) << 16 ) |
( V_80 -> V_365 - 1 ) ) ;
if ( ! V_29 -> V_79 -> V_366 . V_106 &&
( F_10 ( V_29 , V_33 ) ||
F_10 ( V_29 , V_367 ) ) ) {
F_118 ( F_252 ( V_29 -> V_4 ) , 0 ) ;
F_118 ( F_253 ( V_29 -> V_4 ) , 0 ) ;
F_118 ( F_254 ( V_29 -> V_4 ) , 0 ) ;
}
V_29 -> V_79 -> V_326 = V_80 -> V_364 ;
V_29 -> V_79 -> V_325 = V_80 -> V_365 ;
}
static void F_255 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_368 ;
V_85 = F_62 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
if ( F_256 ( V_10 ) ) {
V_368 &= ~ V_369 ;
V_368 |= V_369 | V_370 ;
} else {
V_368 &= ~ V_371 ;
V_368 |= V_371 | V_370 ;
}
F_118 ( V_85 , V_368 ) ;
V_85 = F_64 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
if ( F_94 ( V_10 ) ) {
V_368 &= ~ V_372 ;
V_368 |= V_373 ;
} else {
V_368 &= ~ V_371 ;
V_368 |= V_371 ;
}
F_118 ( V_85 , V_368 | V_374 ) ;
F_119 ( V_85 ) ;
F_120 ( 1000 ) ;
if ( F_256 ( V_10 ) )
F_118 ( V_85 , F_5 ( V_85 ) | V_375 |
V_376 ) ;
}
static bool F_257 ( struct V_28 * V_29 )
{
return V_29 -> V_8 . V_106 && V_29 -> V_76 &&
V_29 -> V_79 -> V_247 ;
}
static void F_258 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_377 =
F_37 ( V_12 -> V_83 [ V_138 ] ) ;
struct V_28 * V_378 =
F_37 ( V_12 -> V_83 [ V_379 ] ) ;
T_4 V_368 ;
if ( ! F_257 ( V_377 ) &&
! F_257 ( V_378 ) ) {
F_3 ( F_5 ( F_64 ( V_138 ) ) & V_124 ) ;
F_3 ( F_5 ( F_64 ( V_379 ) ) & V_124 ) ;
V_368 = F_5 ( V_380 ) ;
V_368 &= ~ V_381 ;
F_142 ( L_54 ) ;
F_118 ( V_380 , V_368 ) ;
}
}
static void F_259 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_368 , V_382 ;
F_167 ( V_12 , V_4 ) ;
V_85 = F_260 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_383 ;
V_368 &= ~ V_384 ;
F_118 ( V_85 , V_368 ) ;
F_5 ( V_85 ) ;
F_120 ( 150 ) ;
V_85 = F_62 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_385 ;
V_368 |= F_261 ( V_28 -> V_79 -> V_386 ) ;
V_368 &= ~ V_371 ;
V_368 |= V_387 ;
F_118 ( V_85 , V_368 | V_123 ) ;
V_85 = F_64 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_371 ;
V_368 |= V_387 ;
F_118 ( V_85 , V_368 | V_124 ) ;
F_119 ( V_85 ) ;
F_120 ( 150 ) ;
F_118 ( F_262 ( V_4 ) , V_388 ) ;
F_118 ( F_262 ( V_4 ) , V_388 |
V_389 ) ;
V_85 = F_263 ( V_4 ) ;
for ( V_382 = 0 ; V_382 < 5 ; V_382 ++ ) {
V_368 = F_5 ( V_85 ) ;
F_142 ( L_55 , V_368 ) ;
if ( ( V_368 & V_384 ) ) {
F_142 ( L_56 ) ;
F_118 ( V_85 , V_368 | V_384 ) ;
break;
}
}
if ( V_382 == 5 )
F_121 ( L_57 ) ;
V_85 = F_62 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_371 ;
V_368 |= V_390 ;
F_118 ( V_85 , V_368 ) ;
V_85 = F_64 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_371 ;
V_368 |= V_390 ;
F_118 ( V_85 , V_368 ) ;
F_119 ( V_85 ) ;
F_120 ( 150 ) ;
V_85 = F_263 ( V_4 ) ;
for ( V_382 = 0 ; V_382 < 5 ; V_382 ++ ) {
V_368 = F_5 ( V_85 ) ;
F_142 ( L_55 , V_368 ) ;
if ( V_368 & V_383 ) {
F_118 ( V_85 , V_368 | V_383 ) ;
F_142 ( L_58 ) ;
break;
}
}
if ( V_382 == 5 )
F_121 ( L_59 ) ;
F_142 ( L_60 ) ;
}
static void F_264 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_368 , V_153 , V_391 ;
V_85 = F_260 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_383 ;
V_368 &= ~ V_384 ;
F_118 ( V_85 , V_368 ) ;
F_119 ( V_85 ) ;
F_120 ( 150 ) ;
V_85 = F_62 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_385 ;
V_368 |= F_261 ( V_28 -> V_79 -> V_386 ) ;
V_368 &= ~ V_371 ;
V_368 |= V_387 ;
V_368 &= ~ V_392 ;
V_368 |= V_393 ;
F_118 ( V_85 , V_368 | V_123 ) ;
F_118 ( F_265 ( V_4 ) ,
V_394 | V_395 ) ;
V_85 = F_64 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
if ( F_94 ( V_10 ) ) {
V_368 &= ~ V_372 ;
V_368 |= V_396 ;
} else {
V_368 &= ~ V_371 ;
V_368 |= V_387 ;
}
F_118 ( V_85 , V_368 | V_124 ) ;
F_119 ( V_85 ) ;
F_120 ( 150 ) ;
for ( V_153 = 0 ; V_153 < 4 ; V_153 ++ ) {
V_85 = F_62 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_392 ;
V_368 |= V_397 [ V_153 ] ;
F_118 ( V_85 , V_368 ) ;
F_119 ( V_85 ) ;
F_120 ( 500 ) ;
for ( V_391 = 0 ; V_391 < 5 ; V_391 ++ ) {
V_85 = F_263 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
F_142 ( L_55 , V_368 ) ;
if ( V_368 & V_384 ) {
F_118 ( V_85 , V_368 | V_384 ) ;
F_142 ( L_56 ) ;
break;
}
F_120 ( 50 ) ;
}
if ( V_391 < 5 )
break;
}
if ( V_153 == 4 )
F_121 ( L_57 ) ;
V_85 = F_62 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_371 ;
V_368 |= V_390 ;
if ( F_266 ( V_10 ) ) {
V_368 &= ~ V_392 ;
V_368 |= V_393 ;
}
F_118 ( V_85 , V_368 ) ;
V_85 = F_64 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
if ( F_94 ( V_10 ) ) {
V_368 &= ~ V_372 ;
V_368 |= V_398 ;
} else {
V_368 &= ~ V_371 ;
V_368 |= V_390 ;
}
F_118 ( V_85 , V_368 ) ;
F_119 ( V_85 ) ;
F_120 ( 150 ) ;
for ( V_153 = 0 ; V_153 < 4 ; V_153 ++ ) {
V_85 = F_62 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_392 ;
V_368 |= V_397 [ V_153 ] ;
F_118 ( V_85 , V_368 ) ;
F_119 ( V_85 ) ;
F_120 ( 500 ) ;
for ( V_391 = 0 ; V_391 < 5 ; V_391 ++ ) {
V_85 = F_263 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
F_142 ( L_55 , V_368 ) ;
if ( V_368 & V_383 ) {
F_118 ( V_85 , V_368 | V_383 ) ;
F_142 ( L_58 ) ;
break;
}
F_120 ( 50 ) ;
}
if ( V_391 < 5 )
break;
}
if ( V_153 == 4 )
F_121 ( L_59 ) ;
F_142 ( L_61 ) ;
}
static void F_267 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_368 , V_153 , V_399 ;
V_85 = F_260 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_383 ;
V_368 &= ~ V_384 ;
F_118 ( V_85 , V_368 ) ;
F_119 ( V_85 ) ;
F_120 ( 150 ) ;
F_142 ( L_62 ,
F_5 ( F_263 ( V_4 ) ) ) ;
for ( V_399 = 0 ; V_399 < F_268 ( V_397 ) * 2 ; V_399 ++ ) {
V_85 = F_62 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ ( V_400 | V_369 ) ;
V_368 &= ~ V_123 ;
F_118 ( V_85 , V_368 ) ;
V_85 = F_64 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_400 ;
V_368 &= ~ V_372 ;
V_368 &= ~ V_124 ;
F_118 ( V_85 , V_368 ) ;
V_85 = F_62 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_385 ;
V_368 |= F_261 ( V_28 -> V_79 -> V_386 ) ;
V_368 |= V_401 ;
V_368 &= ~ V_392 ;
V_368 |= V_397 [ V_399 / 2 ] ;
V_368 |= V_402 ;
F_118 ( V_85 , V_368 | V_123 ) ;
F_118 ( F_265 ( V_4 ) ,
V_394 | V_395 ) ;
V_85 = F_64 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 |= V_396 ;
V_368 |= V_402 ;
F_118 ( V_85 , V_368 | V_124 ) ;
F_119 ( V_85 ) ;
F_120 ( 1 ) ;
for ( V_153 = 0 ; V_153 < 4 ; V_153 ++ ) {
V_85 = F_263 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
F_142 ( L_55 , V_368 ) ;
if ( V_368 & V_384 ||
( F_5 ( V_85 ) & V_384 ) ) {
F_118 ( V_85 , V_368 | V_384 ) ;
F_142 ( L_63 ,
V_153 ) ;
break;
}
F_120 ( 1 ) ;
}
if ( V_153 == 4 ) {
F_142 ( L_64 , V_399 / 2 ) ;
continue;
}
V_85 = F_62 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_369 ;
V_368 |= V_403 ;
F_118 ( V_85 , V_368 ) ;
V_85 = F_64 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_372 ;
V_368 |= V_398 ;
F_118 ( V_85 , V_368 ) ;
F_119 ( V_85 ) ;
F_120 ( 2 ) ;
for ( V_153 = 0 ; V_153 < 4 ; V_153 ++ ) {
V_85 = F_263 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
F_142 ( L_55 , V_368 ) ;
if ( V_368 & V_383 ||
( F_5 ( V_85 ) & V_383 ) ) {
F_118 ( V_85 , V_368 | V_383 ) ;
F_142 ( L_65 ,
V_153 ) ;
goto V_404;
}
F_120 ( 2 ) ;
}
if ( V_153 == 4 )
F_142 ( L_66 , V_399 / 2 ) ;
}
V_404:
F_142 ( L_61 ) ;
}
static void F_269 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_368 ;
V_85 = F_64 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ ( V_385 | ( 0x7 << 16 ) ) ;
V_368 |= F_261 ( V_28 -> V_79 -> V_386 ) ;
V_368 |= ( F_5 ( F_44 ( V_4 ) ) & V_233 ) << 11 ;
F_118 ( V_85 , V_368 | V_126 ) ;
F_119 ( V_85 ) ;
F_120 ( 200 ) ;
V_368 = F_5 ( V_85 ) ;
F_118 ( V_85 , V_368 | V_405 ) ;
F_119 ( V_85 ) ;
F_120 ( 200 ) ;
V_85 = F_62 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
if ( ( V_368 & V_125 ) == 0 ) {
F_118 ( V_85 , V_368 | V_125 ) ;
F_119 ( V_85 ) ;
F_120 ( 100 ) ;
}
}
static void F_270 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_368 ;
V_85 = F_64 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
F_118 ( V_85 , V_368 & ~ V_405 ) ;
V_85 = F_62 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
F_118 ( V_85 , V_368 & ~ V_125 ) ;
F_119 ( V_85 ) ;
F_120 ( 100 ) ;
V_85 = F_64 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
F_118 ( V_85 , V_368 & ~ V_126 ) ;
F_119 ( V_85 ) ;
F_120 ( 100 ) ;
}
static void F_271 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_368 ;
V_85 = F_62 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
F_118 ( V_85 , V_368 & ~ V_123 ) ;
F_119 ( V_85 ) ;
V_85 = F_64 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ ( 0x7 << 16 ) ;
V_368 |= ( F_5 ( F_44 ( V_4 ) ) & V_233 ) << 11 ;
F_118 ( V_85 , V_368 & ~ V_124 ) ;
F_119 ( V_85 ) ;
F_120 ( 100 ) ;
if ( F_48 ( V_10 ) )
F_118 ( F_262 ( V_4 ) , V_388 ) ;
V_85 = F_62 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ V_371 ;
V_368 |= V_387 ;
F_118 ( V_85 , V_368 ) ;
V_85 = F_64 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
if ( F_94 ( V_10 ) ) {
V_368 &= ~ V_372 ;
V_368 |= V_396 ;
} else {
V_368 &= ~ V_371 ;
V_368 |= V_387 ;
}
V_368 &= ~ ( 0x07 << 16 ) ;
V_368 |= ( F_5 ( F_44 ( V_4 ) ) & V_233 ) << 11 ;
F_118 ( V_85 , V_368 ) ;
F_119 ( V_85 ) ;
F_120 ( 100 ) ;
}
bool F_272 ( struct V_9 * V_10 )
{
struct V_28 * V_29 ;
F_129 (dev, crtc) {
if ( F_249 ( & V_29 -> V_406 ) == 0 )
continue;
if ( V_29 -> V_360 )
F_169 ( V_10 , V_29 -> V_4 ) ;
return true ;
}
return false ;
}
static void F_273 ( struct V_28 * V_28 )
{
struct V_11 * V_12 = F_234 ( V_28 -> V_8 . V_10 ) ;
struct V_407 * V_408 = V_28 -> V_360 ;
F_274 () ;
V_28 -> V_360 = NULL ;
if ( V_408 -> V_409 )
F_275 ( V_28 -> V_8 . V_10 ,
V_28 -> V_4 ,
V_408 -> V_409 ) ;
F_92 ( & V_28 -> V_8 ) ;
F_276 ( & V_12 -> V_410 ) ;
F_277 ( V_12 -> V_411 , & V_408 -> V_408 ) ;
F_278 ( V_28 -> V_151 ,
V_408 -> V_412 ) ;
}
void F_279 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_3 ( F_280 ( & V_12 -> V_410 ) ) ;
if ( F_3 ( F_281 ( V_12 -> V_410 ,
! F_247 ( V_29 ) ,
60 * V_413 ) == 0 ) ) {
struct V_28 * V_28 = F_37 ( V_29 ) ;
F_240 ( & V_10 -> V_359 ) ;
if ( V_28 -> V_360 ) {
F_282 ( 1 , L_67 ) ;
F_273 ( V_28 ) ;
}
F_241 ( & V_10 -> V_359 ) ;
}
if ( V_29 -> V_77 -> V_78 ) {
F_54 ( & V_10 -> V_267 ) ;
F_245 ( V_29 -> V_77 -> V_78 ) ;
F_56 ( & V_10 -> V_267 ) ;
}
}
static void F_283 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int clock = F_37 ( V_29 ) -> V_79 -> V_8 . V_80 . V_81 ;
T_1 V_414 , V_415 , V_416 , V_417 = 0 ;
T_1 V_368 ;
F_54 ( & V_12 -> V_111 ) ;
F_118 ( V_418 , V_419 ) ;
F_284 ( V_12 , V_420 ,
F_285 ( V_12 , V_420 , V_421 ) |
V_422 ,
V_421 ) ;
if ( clock == 20000 ) {
V_416 = 1 ;
V_414 = 0x41 ;
V_415 = 0x20 ;
} else {
T_1 V_423 = 172800 * 1000 ;
T_1 V_424 = 64 ;
T_1 V_425 , V_426 , V_427 ;
V_425 = ( V_423 / clock ) ;
V_426 = V_425 / V_424 ;
V_427 = V_425 % V_424 ;
V_416 = 0 ;
V_414 = V_426 - 2 ;
V_415 = V_427 ;
}
F_3 ( F_286 ( V_414 ) &
~ V_428 ) ;
F_3 ( F_287 ( V_417 ) &
~ V_429 ) ;
F_142 ( L_68 ,
clock ,
V_416 ,
V_414 ,
V_417 ,
V_415 ) ;
V_368 = F_285 ( V_12 , V_430 , V_421 ) ;
V_368 &= ~ V_428 ;
V_368 |= F_286 ( V_414 ) ;
V_368 &= ~ V_429 ;
V_368 |= F_288 ( V_415 ) ;
V_368 |= F_287 ( V_417 ) ;
V_368 |= V_431 ;
F_284 ( V_12 , V_430 , V_368 , V_421 ) ;
V_368 = F_285 ( V_12 , V_432 , V_421 ) ;
V_368 &= ~ F_289 ( 1 ) ;
V_368 |= F_289 ( V_416 ) ;
F_284 ( V_12 , V_432 , V_368 , V_421 ) ;
V_368 = F_285 ( V_12 , V_420 , V_421 ) ;
V_368 &= ~ V_422 ;
F_284 ( V_12 , V_420 , V_368 , V_421 ) ;
F_120 ( 24 ) ;
F_118 ( V_418 , V_433 ) ;
F_56 ( & V_12 -> V_111 ) ;
}
static void F_290 ( struct V_28 * V_29 ,
enum V_4 V_245 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_82 V_84 = V_29 -> V_79 -> V_84 ;
F_118 ( F_291 ( V_245 ) ,
F_5 ( F_292 ( V_84 ) ) ) ;
F_118 ( F_293 ( V_245 ) ,
F_5 ( F_294 ( V_84 ) ) ) ;
F_118 ( F_295 ( V_245 ) ,
F_5 ( F_296 ( V_84 ) ) ) ;
F_118 ( F_297 ( V_245 ) ,
F_5 ( F_298 ( V_84 ) ) ) ;
F_118 ( F_299 ( V_245 ) ,
F_5 ( F_300 ( V_84 ) ) ) ;
F_118 ( F_301 ( V_245 ) ,
F_5 ( F_302 ( V_84 ) ) ) ;
F_118 ( F_303 ( V_245 ) ,
F_5 ( F_304 ( V_84 ) ) ) ;
}
static void F_305 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_368 ;
V_368 = F_5 ( V_380 ) ;
if ( V_368 & V_381 )
return;
F_3 ( F_5 ( F_64 ( V_138 ) ) & V_124 ) ;
F_3 ( F_5 ( F_64 ( V_379 ) ) & V_124 ) ;
V_368 |= V_381 ;
F_142 ( L_69 ) ;
F_118 ( V_380 , V_368 ) ;
F_119 ( V_380 ) ;
}
static void F_306 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
switch ( V_28 -> V_4 ) {
case V_129 :
break;
case V_138 :
if ( V_28 -> V_79 -> V_386 > 2 )
F_3 ( F_5 ( V_380 ) & V_381 ) ;
else
F_305 ( V_10 ) ;
break;
case V_379 :
F_305 ( V_10 ) ;
break;
default:
F_136 () ;
}
}
static void F_307 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_368 ;
F_95 ( V_12 , V_4 ) ;
if ( F_256 ( V_10 ) )
F_306 ( V_28 ) ;
F_118 ( F_308 ( V_4 ) ,
F_5 ( F_309 ( V_4 ) ) & V_434 ) ;
V_12 -> V_252 . V_435 ( V_29 ) ;
if ( F_94 ( V_10 ) ) {
T_1 V_436 ;
V_368 = F_5 ( V_437 ) ;
V_368 |= F_310 ( V_4 ) ;
V_436 = F_311 ( V_4 ) ;
if ( V_28 -> V_79 -> V_115 == V_438 )
V_368 |= V_436 ;
else
V_368 &= ~ V_436 ;
F_118 ( V_437 , V_368 ) ;
}
F_141 ( V_28 ) ;
F_67 ( V_12 , V_4 ) ;
F_290 ( V_28 , V_4 ) ;
F_255 ( V_29 ) ;
if ( F_94 ( V_10 ) && V_28 -> V_79 -> V_439 ) {
T_1 V_440 = ( F_5 ( F_44 ( V_4 ) ) & V_233 ) >> 5 ;
V_85 = F_98 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ ( V_170 |
V_441 |
V_442 ) ;
V_368 |= ( V_443 |
V_444 ) ;
V_368 |= V_440 << 9 ;
if ( V_29 -> V_445 . V_446 & V_447 )
V_368 |= V_448 ;
if ( V_29 -> V_445 . V_446 & V_449 )
V_368 |= V_450 ;
switch ( F_312 ( V_29 ) ) {
case V_184 :
V_368 |= V_185 ;
break;
case V_186 :
V_368 |= V_187 ;
break;
case V_188 :
V_368 |= V_189 ;
break;
default:
F_136 () ;
}
F_118 ( V_85 , V_368 ) ;
}
F_147 ( V_12 , V_4 ) ;
}
static void F_313 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_82 V_84 = V_28 -> V_79 -> V_84 ;
F_95 ( V_12 , V_241 ) ;
F_283 ( V_29 ) ;
F_290 ( V_28 , V_129 ) ;
F_151 ( V_12 , V_84 ) ;
}
void F_314 ( struct V_28 * V_29 )
{
struct V_114 * V_117 = F_57 ( V_29 ) ;
if ( V_117 == NULL )
return;
if ( ! ( V_117 -> V_79 . V_224 & ( 1 << V_29 -> V_4 ) ) ) {
F_46 ( 1 , L_70 , V_117 -> V_121 ) ;
return;
}
V_117 -> V_79 . V_224 &= ~ ( 1 << V_29 -> V_4 ) ;
if ( V_117 -> V_79 . V_224 == 0 ) {
F_3 ( V_117 -> V_225 ) ;
F_3 ( V_117 -> V_76 ) ;
}
V_29 -> V_79 -> V_115 = V_451 ;
}
struct V_114 * F_315 ( struct V_28 * V_29 ,
struct V_198 * V_452 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
struct V_114 * V_117 ;
enum V_453 V_153 ;
if ( F_48 ( V_12 -> V_10 ) ) {
V_153 = (enum V_453 ) V_29 -> V_4 ;
V_117 = & V_12 -> V_116 [ V_153 ] ;
F_142 ( L_71 ,
V_29 -> V_8 . V_8 . V_227 , V_117 -> V_121 ) ;
F_3 ( V_117 -> V_454 -> V_224 ) ;
goto V_69;
}
for ( V_153 = 0 ; V_153 < V_12 -> V_455 ; V_153 ++ ) {
V_117 = & V_12 -> V_116 [ V_153 ] ;
if ( V_117 -> V_454 -> V_224 == 0 )
continue;
if ( memcmp ( & V_452 -> V_200 ,
& V_117 -> V_454 -> V_119 ,
sizeof( V_117 -> V_454 -> V_119 ) ) == 0 ) {
F_142 ( L_72 ,
V_29 -> V_8 . V_8 . V_227 , V_117 -> V_121 ,
V_117 -> V_454 -> V_224 ,
V_117 -> V_76 ) ;
goto V_69;
}
}
for ( V_153 = 0 ; V_153 < V_12 -> V_455 ; V_153 ++ ) {
V_117 = & V_12 -> V_116 [ V_153 ] ;
if ( V_117 -> V_454 -> V_224 == 0 ) {
F_142 ( L_73 ,
V_29 -> V_8 . V_8 . V_227 , V_117 -> V_121 ) ;
goto V_69;
}
}
return NULL ;
V_69:
if ( V_117 -> V_454 -> V_224 == 0 )
V_117 -> V_454 -> V_119 = V_452 -> V_200 ;
V_452 -> V_115 = V_153 ;
F_139 ( L_74 , V_117 -> V_121 ,
F_69 ( V_29 -> V_4 ) ) ;
V_117 -> V_454 -> V_224 |= 1 << V_29 -> V_4 ;
return V_117 ;
}
static int F_316 ( struct V_11 * V_12 ,
unsigned V_456 )
{
struct V_114 * V_117 ;
enum V_453 V_153 ;
for ( V_153 = 0 ; V_153 < V_12 -> V_455 ; V_153 ++ ) {
V_117 = & V_12 -> V_116 [ V_153 ] ;
V_117 -> V_454 = F_317 ( & V_117 -> V_79 , sizeof V_117 -> V_79 ,
V_457 ) ;
if ( ! V_117 -> V_454 )
goto V_458;
V_117 -> V_454 -> V_224 &= ~ V_456 ;
}
return 0 ;
V_458:
while ( -- V_153 >= 0 ) {
V_117 = & V_12 -> V_116 [ V_153 ] ;
F_202 ( V_117 -> V_454 ) ;
V_117 -> V_454 = NULL ;
}
return - V_459 ;
}
static void F_318 ( struct V_11 * V_12 )
{
struct V_114 * V_117 ;
enum V_453 V_153 ;
for ( V_153 = 0 ; V_153 < V_12 -> V_455 ; V_153 ++ ) {
V_117 = & V_12 -> V_116 [ V_153 ] ;
F_3 ( V_117 -> V_454 == & V_117 -> V_79 ) ;
V_117 -> V_79 = * V_117 -> V_454 ;
F_202 ( V_117 -> V_454 ) ;
V_117 -> V_454 = NULL ;
}
}
static void F_319 ( struct V_11 * V_12 )
{
struct V_114 * V_117 ;
enum V_453 V_153 ;
for ( V_153 = 0 ; V_153 < V_12 -> V_455 ; V_153 ++ ) {
V_117 = & V_12 -> V_116 [ V_153 ] ;
F_3 ( V_117 -> V_454 == & V_117 -> V_79 ) ;
F_202 ( V_117 -> V_454 ) ;
V_117 -> V_454 = NULL ;
}
}
static void F_320 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_460 = F_40 ( V_4 ) ;
T_1 V_368 ;
V_368 = F_5 ( V_460 ) ;
F_120 ( 500 ) ;
if ( F_45 ( F_5 ( V_460 ) != V_368 , 5 ) ) {
if ( F_45 ( F_5 ( V_460 ) != V_368 , 5 ) )
F_121 ( L_75 , F_69 ( V_4 ) ) ;
}
}
static void F_321 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_79 -> V_366 . V_106 ) {
F_118 ( F_322 ( V_4 ) , V_461 ) ;
F_118 ( F_323 ( V_4 ) , V_29 -> V_79 -> V_366 . V_462 ) ;
F_118 ( F_324 ( V_4 ) , V_29 -> V_79 -> V_366 . V_311 ) ;
}
}
static void F_325 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_79 -> V_366 . V_106 ) {
if ( F_256 ( V_10 ) || F_218 ( V_10 ) )
F_118 ( F_252 ( V_4 ) , V_463 | V_464 |
F_326 ( V_4 ) ) ;
else
F_118 ( F_252 ( V_4 ) , V_463 | V_464 ) ;
F_118 ( F_253 ( V_4 ) , V_29 -> V_79 -> V_366 . V_462 ) ;
F_118 ( F_254 ( V_4 ) , V_29 -> V_79 -> V_366 . V_311 ) ;
}
}
static void F_327 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_4 V_4 = F_37 ( V_29 ) -> V_4 ;
struct V_250 * V_151 ;
struct V_465 * V_465 ;
F_328 (plane, &dev->mode_config.plane_list) {
V_465 = F_329 ( V_151 ) ;
if ( V_465 -> V_4 == V_4 )
F_330 ( & V_465 -> V_8 ) ;
}
}
static void F_331 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_4 V_4 = F_37 ( V_29 ) -> V_4 ;
struct V_250 * V_151 ;
struct V_465 * V_465 ;
F_328 (plane, &dev->mode_config.plane_list) {
V_465 = F_329 ( V_151 ) ;
if ( V_465 -> V_4 == V_4 )
V_151 -> V_466 -> V_467 ( V_151 ) ;
}
}
void F_332 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_79 -> V_468 )
return;
F_169 ( V_10 , V_29 -> V_4 ) ;
F_333 ( V_12 , V_29 -> V_151 ) ;
if ( F_168 ( V_10 ) ) {
F_54 ( & V_12 -> V_469 . V_470 ) ;
F_3 ( F_334 ( V_12 , V_471 , 0xc0000000 ) ) ;
F_56 ( & V_12 -> V_469 . V_470 ) ;
} else {
F_118 ( V_472 , V_473 ) ;
if ( F_45 ( F_335 ( V_472 ) & V_473 , 50 ) )
F_121 ( L_76 ) ;
}
}
void F_336 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_79 -> V_468 )
return;
F_333 ( V_12 , V_29 -> V_151 ) ;
if ( F_168 ( V_10 ) ) {
F_54 ( & V_12 -> V_469 . V_470 ) ;
F_3 ( F_334 ( V_12 , V_471 , 0 ) ) ;
F_56 ( & V_12 -> V_469 . V_470 ) ;
if ( F_45 ( ( F_5 ( V_472 ) & V_473 ) == 0 , 42 ) )
F_121 ( L_77 ) ;
} else {
F_118 ( V_472 , 0 ) ;
F_119 ( V_472 ) ;
}
F_169 ( V_10 , V_29 -> V_4 ) ;
}
static void F_337 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
int V_474 = F_338 ( V_4 ) ;
int V_153 ;
bool V_475 = false ;
if ( ! V_29 -> V_106 || ! V_28 -> V_76 )
return;
if ( ! F_4 ( V_12 -> V_10 ) ) {
if ( F_10 ( V_28 , V_246 ) )
F_159 ( V_12 ) ;
else
F_160 ( V_12 , V_4 ) ;
}
if ( ! F_339 ( V_10 ) )
V_474 = F_340 ( V_4 ) ;
if ( F_218 ( V_10 ) && V_28 -> V_79 -> V_468 &&
( ( F_5 ( F_341 ( V_4 ) ) & V_476 ) ==
V_477 ) ) {
F_336 ( V_28 ) ;
V_475 = true ;
}
for ( V_153 = 0 ; V_153 < 256 ; V_153 ++ ) {
F_118 ( V_474 + 4 * V_153 ,
( V_28 -> V_478 [ V_153 ] << 16 ) |
( V_28 -> V_479 [ V_153 ] << 8 ) |
V_28 -> V_480 [ V_153 ] ) ;
}
if ( V_475 )
F_332 ( V_28 ) ;
}
static void F_342 ( struct V_28 * V_28 , bool V_229 )
{
if ( ! V_229 && V_28 -> V_481 ) {
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_54 ( & V_10 -> V_267 ) ;
V_12 -> V_273 . V_274 = false ;
( void ) F_343 ( V_28 -> V_481 ) ;
V_12 -> V_273 . V_274 = true ;
F_56 ( & V_10 -> V_267 ) ;
}
}
static void F_344 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
F_166 ( V_29 -> V_77 , V_29 ) ;
F_327 ( V_29 ) ;
F_345 ( V_29 , true ) ;
F_342 ( V_28 , true ) ;
F_332 ( V_28 ) ;
F_54 ( & V_10 -> V_267 ) ;
F_346 ( V_10 ) ;
F_56 ( & V_10 -> V_267 ) ;
F_347 ( V_10 , F_348 ( V_4 ) ) ;
}
static void F_349 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
int V_151 = V_28 -> V_151 ;
F_279 ( V_29 ) ;
if ( V_12 -> V_482 . V_151 == V_151 )
F_350 ( V_10 ) ;
F_336 ( V_28 ) ;
F_342 ( V_28 , false ) ;
F_345 ( V_29 , false ) ;
F_331 ( V_29 ) ;
F_170 ( V_29 -> V_77 , V_29 ) ;
F_347 ( V_10 , F_348 ( V_4 ) ) ;
}
static void F_351 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
F_3 ( ! V_29 -> V_106 ) ;
if ( V_28 -> V_76 )
return;
if ( V_28 -> V_79 -> V_247 )
F_138 ( V_28 ) ;
if ( V_28 -> V_79 -> V_439 )
F_352 ( V_28 ) ;
F_353 ( V_28 ) ;
if ( V_28 -> V_79 -> V_247 ) {
F_354 ( V_28 ,
& V_28 -> V_79 -> V_483 , NULL ) ;
}
F_355 ( V_29 ) ;
V_28 -> V_76 = true ;
F_356 ( V_12 , V_4 , true ) ;
F_357 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_484 )
V_6 -> V_484 ( V_6 ) ;
if ( V_28 -> V_79 -> V_247 ) {
F_269 ( V_28 ) ;
} else {
F_153 ( V_12 , V_4 ) ;
F_154 ( V_12 , V_4 ) ;
}
F_325 ( V_28 ) ;
F_337 ( V_29 ) ;
F_358 ( V_29 ) ;
F_156 ( V_28 ) ;
if ( V_28 -> V_79 -> V_247 )
F_307 ( V_29 ) ;
F_89 ( V_29 ) ;
F_359 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_229 ( V_6 ) ;
if ( F_94 ( V_10 ) )
F_320 ( V_10 , V_28 -> V_4 ) ;
F_344 ( V_29 ) ;
}
static bool F_360 ( struct V_28 * V_29 )
{
return F_361 ( V_29 -> V_8 . V_10 ) && V_29 -> V_4 == V_129 ;
}
static void F_362 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_28 * V_485 , * V_486 = NULL ;
F_129 (dev, crtc_it) {
if ( ! V_485 -> V_76 || V_485 == V_29 )
continue;
if ( V_486 )
return;
V_486 = V_485 ;
}
if ( ! V_486 )
return;
F_169 ( V_10 , V_486 -> V_4 ) ;
F_169 ( V_10 , V_486 -> V_4 ) ;
}
static void F_363 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
F_3 ( ! V_29 -> V_106 ) ;
if ( V_28 -> V_76 )
return;
if ( F_57 ( V_28 ) )
F_141 ( V_28 ) ;
if ( V_28 -> V_79 -> V_439 )
F_352 ( V_28 ) ;
F_353 ( V_28 ) ;
if ( V_28 -> V_79 -> V_84 != V_487 ) {
F_118 ( F_364 ( V_28 -> V_79 -> V_84 ) ,
V_28 -> V_79 -> V_488 - 1 ) ;
}
if ( V_28 -> V_79 -> V_247 ) {
F_354 ( V_28 ,
& V_28 -> V_79 -> V_483 , NULL ) ;
}
F_365 ( V_29 ) ;
F_366 ( V_29 ) ;
V_28 -> V_76 = true ;
F_356 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_484 )
V_6 -> V_484 ( V_6 ) ;
if ( V_28 -> V_79 -> V_247 ) {
F_357 ( V_12 , V_241 ,
true ) ;
V_12 -> V_252 . V_435 ( V_29 ) ;
}
F_367 ( V_28 ) ;
if ( F_368 ( V_10 ) )
F_321 ( V_28 ) ;
else
F_325 ( V_28 ) ;
F_337 ( V_29 ) ;
F_369 ( V_29 ) ;
F_370 ( V_29 ) ;
F_358 ( V_29 ) ;
F_156 ( V_28 ) ;
if ( V_28 -> V_79 -> V_247 )
F_313 ( V_29 ) ;
if ( V_28 -> V_79 -> V_489 )
F_371 ( V_29 , true ) ;
F_89 ( V_29 ) ;
F_359 ( V_29 ) ;
F_11 (dev, crtc, encoder) {
V_6 -> V_229 ( V_6 ) ;
F_372 ( V_6 , true ) ;
}
F_362 ( V_28 ) ;
F_344 ( V_29 ) ;
}
static void F_373 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_79 -> V_366 . V_106 ) {
F_118 ( F_322 ( V_4 ) , 0 ) ;
F_118 ( F_323 ( V_4 ) , 0 ) ;
F_118 ( F_324 ( V_4 ) , 0 ) ;
}
}
static void F_374 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_79 -> V_366 . V_106 ) {
F_118 ( F_252 ( V_4 ) , 0 ) ;
F_118 ( F_253 ( V_4 ) , 0 ) ;
F_118 ( F_254 ( V_4 ) , 0 ) ;
}
}
static void F_375 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_368 ;
if ( ! V_28 -> V_76 )
return;
F_349 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_230 ( V_6 ) ;
F_376 ( V_29 ) ;
F_89 ( V_29 ) ;
if ( V_28 -> V_79 -> V_247 )
F_357 ( V_12 , V_4 , false ) ;
F_162 ( V_28 ) ;
F_374 ( V_28 ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_490 )
V_6 -> V_490 ( V_6 ) ;
if ( V_28 -> V_79 -> V_247 ) {
F_271 ( V_29 ) ;
F_152 ( V_12 , V_4 ) ;
if ( F_94 ( V_10 ) ) {
V_85 = F_98 ( V_4 ) ;
V_368 = F_5 ( V_85 ) ;
V_368 &= ~ ( V_443 |
V_170 ) ;
V_368 |= V_491 ;
F_118 ( V_85 , V_368 ) ;
V_368 = F_5 ( V_437 ) ;
V_368 &= ~ ( F_310 ( V_4 ) | F_311 ( V_4 ) ) ;
F_118 ( V_437 , V_368 ) ;
}
F_145 ( V_28 ) ;
F_270 ( V_28 ) ;
}
V_28 -> V_76 = false ;
F_358 ( V_29 ) ;
F_54 ( & V_10 -> V_267 ) ;
F_346 ( V_10 ) ;
F_56 ( & V_10 -> V_267 ) ;
}
static void F_377 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_1 * V_6 ;
enum V_82 V_84 = V_28 -> V_79 -> V_84 ;
if ( ! V_28 -> V_76 )
return;
F_349 ( V_29 ) ;
F_11 (dev, crtc, encoder) {
F_372 ( V_6 , false ) ;
V_6 -> V_230 ( V_6 ) ;
}
F_376 ( V_29 ) ;
F_89 ( V_29 ) ;
if ( V_28 -> V_79 -> V_247 )
F_357 ( V_12 , V_241 ,
false ) ;
F_162 ( V_28 ) ;
if ( V_28 -> V_79 -> V_489 )
F_371 ( V_29 , false ) ;
F_378 ( V_12 , V_84 ) ;
if ( F_368 ( V_10 ) )
F_373 ( V_28 ) ;
else
F_374 ( V_28 ) ;
F_379 ( V_28 ) ;
if ( V_28 -> V_79 -> V_247 ) {
F_155 ( V_12 ) ;
F_380 ( V_29 ) ;
}
F_11 (dev, crtc, encoder)
if ( V_6 -> V_490 )
V_6 -> V_490 ( V_6 ) ;
V_28 -> V_76 = false ;
F_358 ( V_29 ) ;
F_54 ( & V_10 -> V_267 ) ;
F_346 ( V_10 ) ;
F_56 ( & V_10 -> V_267 ) ;
if ( F_57 ( V_28 ) )
F_145 ( V_28 ) ;
}
static void F_381 ( struct V_75 * V_29 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
F_314 ( V_28 ) ;
}
static void F_382 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_198 * V_199 = V_29 -> V_79 ;
if ( ! V_199 -> V_492 . V_493 )
return;
F_3 ( F_5 ( V_494 ) & V_495 ) ;
F_115 ( V_12 , V_29 -> V_4 ) ;
F_118 ( V_496 , V_199 -> V_492 . V_497 ) ;
F_118 ( V_494 , V_199 -> V_492 . V_493 ) ;
F_118 ( F_383 ( V_29 -> V_4 ) , 0 ) ;
}
static enum V_498 F_384 ( enum V_94 V_94 )
{
switch ( V_94 ) {
case V_499 :
return V_500 ;
case V_96 :
return V_501 ;
case V_98 :
return V_502 ;
case V_100 :
return V_503 ;
default:
F_385 ( 1 ) ;
return V_504 ;
}
}
enum V_498
F_386 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_8 . V_10 ;
struct V_93 * V_505 ;
switch ( V_1 -> type ) {
case V_506 :
F_385 ( ! F_60 ( V_10 ) ) ;
case V_507 :
case V_41 :
case V_367 :
V_505 = F_387 ( & V_1 -> V_8 ) ;
return F_384 ( V_505 -> V_94 ) ;
case V_508 :
V_505 = F_388 ( & V_1 -> V_8 ) -> V_77 ;
return F_384 ( V_505 -> V_94 ) ;
case V_42 :
return V_509 ;
case V_246 :
return V_510 ;
default:
return V_504 ;
}
}
static unsigned long F_389 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_1 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
unsigned long V_511 ;
enum V_82 V_82 ;
V_82 = F_38 ( V_10 -> V_13 , V_4 ) ;
V_511 = F_213 ( F_390 ( V_4 ) ) ;
V_511 |= F_213 ( F_76 ( V_82 ) ) ;
if ( V_28 -> V_79 -> V_366 . V_106 ||
V_28 -> V_79 -> V_366 . V_512 )
V_511 |= F_213 ( F_391 ( V_4 ) ) ;
F_11 (dev, crtc, intel_encoder)
V_511 |= F_213 ( F_386 ( V_1 ) ) ;
return V_511 ;
}
static void F_392 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned long V_513 [ V_514 ] = { 0 , } ;
struct V_28 * V_29 ;
F_129 (dev, crtc) {
enum V_498 V_515 ;
if ( ! V_29 -> V_8 . V_106 )
continue;
V_513 [ V_29 -> V_4 ] = F_389 ( & V_29 -> V_8 ) ;
F_393 (domain, pipe_domains[crtc->pipe])
F_144 ( V_12 , V_515 ) ;
}
if ( V_12 -> V_252 . V_516 )
V_12 -> V_252 . V_516 ( V_10 ) ;
F_129 (dev, crtc) {
enum V_498 V_515 ;
F_393 (domain, crtc->enabled_power_domains)
F_146 ( V_12 , V_515 ) ;
V_29 -> V_517 = V_513 [ V_29 -> V_4 ] ;
}
F_394 ( V_12 , false ) ;
}
static int F_395 ( struct V_11 * V_12 )
{
int V_518 , V_519 [] = { 800 , 1600 , 2000 , 2400 } ;
F_54 ( & V_12 -> V_111 ) ;
V_518 = F_55 ( V_12 , V_520 ) &
V_521 ;
F_56 ( & V_12 -> V_111 ) ;
return V_519 [ V_518 ] * 1000 ;
}
static void F_396 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_522 = V_12 -> V_252 . V_523 ( V_10 ) ;
F_139 ( L_78 ,
V_12 -> V_522 ) ;
F_118 ( V_524 , F_397 ( V_12 -> V_522 , 1000 ) ) ;
}
static void F_398 ( struct V_9 * V_10 , int V_525 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_108 , V_526 ;
F_3 ( V_12 -> V_252 . V_523 ( V_10 ) != V_12 -> V_522 ) ;
if ( V_525 >= 320000 )
V_526 = 2 ;
else if ( V_525 == 266667 )
V_526 = 1 ;
else
V_526 = 0 ;
F_54 ( & V_12 -> V_469 . V_470 ) ;
V_108 = F_399 ( V_12 , V_527 ) ;
V_108 &= ~ V_528 ;
V_108 |= ( V_526 << V_529 ) ;
F_400 ( V_12 , V_527 , V_108 ) ;
if ( F_45 ( ( F_399 ( V_12 , V_527 ) &
V_530 ) == ( V_526 << V_531 ) ,
50 ) ) {
F_121 ( L_79 ) ;
}
F_56 ( & V_12 -> V_469 . V_470 ) ;
if ( V_525 == 400000 ) {
T_1 V_532 ;
V_532 = F_9 ( V_12 -> V_518 << 1 , V_525 ) - 1 ;
F_54 ( & V_12 -> V_111 ) ;
V_108 = F_55 ( V_12 , V_533 ) ;
V_108 &= ~ V_534 ;
V_108 |= V_532 ;
F_401 ( V_12 , V_533 , V_108 ) ;
if ( F_45 ( ( F_55 ( V_12 , V_533 ) &
V_535 ) == ( V_532 << V_536 ) ,
50 ) )
F_121 ( L_79 ) ;
F_56 ( & V_12 -> V_111 ) ;
}
F_54 ( & V_12 -> V_111 ) ;
V_108 = F_402 ( V_12 , V_537 ) ;
V_108 &= ~ 0x7f ;
if ( V_525 == 400000 )
V_108 |= 4500 / 250 ;
else
V_108 |= 3000 / 250 ;
F_403 ( V_12 , V_537 , V_108 ) ;
F_56 ( & V_12 -> V_111 ) ;
F_396 ( V_10 ) ;
}
static void F_404 ( struct V_9 * V_10 , int V_525 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_108 , V_526 ;
F_3 ( V_12 -> V_252 . V_523 ( V_10 ) != V_12 -> V_522 ) ;
switch ( V_525 ) {
case 400000 :
V_526 = 3 ;
break;
case 333333 :
case 320000 :
V_526 = 2 ;
break;
case 266667 :
V_526 = 1 ;
break;
case 200000 :
V_526 = 0 ;
break;
default:
F_405 ( V_525 ) ;
return;
}
F_54 ( & V_12 -> V_469 . V_470 ) ;
V_108 = F_399 ( V_12 , V_527 ) ;
V_108 &= ~ V_538 ;
V_108 |= ( V_526 << V_539 ) ;
F_400 ( V_12 , V_527 , V_108 ) ;
if ( F_45 ( ( F_399 ( V_12 , V_527 ) &
V_540 ) == ( V_526 << V_541 ) ,
50 ) ) {
F_121 ( L_79 ) ;
}
F_56 ( & V_12 -> V_469 . V_470 ) ;
F_396 ( V_10 ) ;
}
static int F_406 ( struct V_11 * V_12 ,
int V_542 )
{
int V_543 = ( V_12 -> V_518 << 1 ) % 320000 != 0 ? 333333 : 320000 ;
if ( F_20 ( V_12 -> V_10 ) )
return 400000 ;
if ( V_542 > V_543 * 9 / 10 )
return 400000 ;
else if ( V_542 > 266667 * 9 / 10 )
return V_543 ;
else if ( V_542 > 0 )
return 266667 ;
else
return 200000 ;
}
static int F_407 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_28 * V_28 ;
int V_542 = 0 ;
F_129 (dev, intel_crtc) {
if ( V_28 -> V_544 )
V_542 = V_59 ( V_542 ,
V_28 -> V_454 -> V_8 . V_80 . V_81 ) ;
}
return V_542 ;
}
static void F_408 ( struct V_9 * V_10 ,
unsigned * V_545 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 ;
int V_542 = F_407 ( V_12 ) ;
if ( F_406 ( V_12 , V_542 ) ==
V_12 -> V_522 )
return;
F_129 (dev, intel_crtc)
if ( V_28 -> V_8 . V_106 )
* V_545 |= ( 1 << V_28 -> V_4 ) ;
}
static void F_409 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_542 = F_407 ( V_12 ) ;
int V_546 = F_406 ( V_12 , V_542 ) ;
if ( V_546 != V_12 -> V_522 ) {
F_144 ( V_12 , V_547 ) ;
if ( F_20 ( V_10 ) )
F_404 ( V_10 , V_546 ) ;
else
F_398 ( V_10 , V_546 ) ;
F_146 ( V_12 , V_547 ) ;
}
}
static void F_410 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = F_234 ( V_10 ) ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
bool V_548 ;
F_3 ( ! V_29 -> V_106 ) ;
if ( V_28 -> V_76 )
return;
V_548 = F_10 ( V_28 , V_246 ) ;
if ( ! V_548 ) {
if ( F_20 ( V_10 ) )
F_411 ( V_28 , V_28 -> V_79 ) ;
else
F_412 ( V_28 , V_28 -> V_79 ) ;
}
if ( V_28 -> V_79 -> V_439 )
F_352 ( V_28 ) ;
F_353 ( V_28 ) ;
if ( F_20 ( V_10 ) && V_4 == V_138 ) {
struct V_11 * V_12 = V_10 -> V_13 ;
F_118 ( F_413 ( V_4 ) , V_549 ) ;
F_118 ( F_414 ( V_4 ) , 0 ) ;
}
F_415 ( V_28 ) ;
V_28 -> V_76 = true ;
F_356 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_550 )
V_6 -> V_550 ( V_6 ) ;
if ( ! V_548 ) {
if ( F_20 ( V_10 ) )
F_123 ( V_28 , V_28 -> V_79 ) ;
else
F_114 ( V_28 , V_28 -> V_79 ) ;
}
F_11 (dev, crtc, encoder)
if ( V_6 -> V_484 )
V_6 -> V_484 ( V_6 ) ;
F_382 ( V_28 ) ;
F_337 ( V_29 ) ;
F_358 ( V_29 ) ;
F_156 ( V_28 ) ;
F_89 ( V_29 ) ;
F_359 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_229 ( V_6 ) ;
F_344 ( V_29 ) ;
F_416 ( V_12 ) ;
}
static void F_417 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_118 ( F_418 ( V_29 -> V_4 ) , V_29 -> V_79 -> V_200 . V_551 ) ;
F_118 ( F_419 ( V_29 -> V_4 ) , V_29 -> V_79 -> V_200 . V_552 ) ;
}
static void F_420 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = F_234 ( V_10 ) ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
F_3 ( ! V_29 -> V_106 ) ;
if ( V_28 -> V_76 )
return;
F_417 ( V_28 ) ;
if ( V_28 -> V_79 -> V_439 )
F_352 ( V_28 ) ;
F_353 ( V_28 ) ;
F_415 ( V_28 ) ;
V_28 -> V_76 = true ;
if ( ! F_22 ( V_10 ) )
F_356 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_484 )
V_6 -> V_484 ( V_6 ) ;
F_130 ( V_28 ) ;
F_382 ( V_28 ) ;
F_337 ( V_29 ) ;
F_358 ( V_29 ) ;
F_156 ( V_28 ) ;
F_89 ( V_29 ) ;
F_359 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_229 ( V_6 ) ;
F_344 ( V_29 ) ;
if ( F_22 ( V_10 ) )
F_356 ( V_12 , V_4 , true ) ;
F_416 ( V_12 ) ;
}
static void F_421 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_79 -> V_492 . V_493 )
return;
F_115 ( V_12 , V_29 -> V_4 ) ;
F_139 ( L_80 ,
F_5 ( V_494 ) ) ;
F_118 ( V_494 , 0 ) ;
}
static void F_422 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
if ( ! V_28 -> V_76 )
return;
if ( F_22 ( V_10 ) )
F_356 ( V_12 , V_4 , false ) ;
F_423 ( V_12 , false ) ;
F_349 ( V_29 ) ;
F_169 ( V_10 , V_4 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_230 ( V_6 ) ;
F_376 ( V_29 ) ;
F_89 ( V_29 ) ;
F_162 ( V_28 ) ;
F_421 ( V_28 ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_490 )
V_6 -> V_490 ( V_6 ) ;
if ( ! F_10 ( V_28 , V_246 ) ) {
if ( F_20 ( V_10 ) )
F_134 ( V_12 , V_4 ) ;
else if ( F_21 ( V_10 ) )
F_133 ( V_12 , V_4 ) ;
else
F_132 ( V_28 ) ;
}
if ( ! F_22 ( V_10 ) )
F_356 ( V_12 , V_4 , false ) ;
V_28 -> V_76 = false ;
F_358 ( V_29 ) ;
F_54 ( & V_10 -> V_267 ) ;
F_346 ( V_10 ) ;
F_56 ( & V_10 -> V_267 ) ;
}
static void F_424 ( struct V_75 * V_29 )
{
}
void F_425 ( struct V_75 * V_29 , bool V_229 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_498 V_515 ;
unsigned long V_553 ;
if ( V_229 ) {
if ( ! V_28 -> V_76 ) {
V_553 = F_389 ( V_29 ) ;
F_393 (domain, domains)
F_144 ( V_12 , V_515 ) ;
V_28 -> V_517 = V_553 ;
V_12 -> V_252 . V_554 ( V_29 ) ;
}
} else {
if ( V_28 -> V_76 ) {
V_12 -> V_252 . V_351 ( V_29 ) ;
V_553 = V_28 -> V_517 ;
F_393 (domain, domains)
F_146 ( V_12 , V_515 ) ;
V_28 -> V_517 = 0 ;
}
}
}
void F_426 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_1 ;
bool V_229 = false ;
F_11 (dev, crtc, intel_encoder)
V_229 |= V_1 -> V_555 ;
F_425 ( V_29 , V_229 ) ;
}
static void F_427 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_556 * V_3 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_3 ( ! V_29 -> V_106 ) ;
V_12 -> V_252 . V_351 ( V_29 ) ;
V_12 -> V_252 . V_557 ( V_29 ) ;
V_29 -> V_77 -> V_466 -> V_467 ( V_29 -> V_77 ) ;
F_428 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_3 -> V_6 || ! V_3 -> V_6 -> V_29 )
continue;
if ( V_3 -> V_6 -> V_29 != V_29 )
continue;
V_3 -> V_558 = V_559 ;
F_429 ( V_3 -> V_6 ) -> V_555 = false ;
}
}
void F_430 ( struct V_560 * V_6 )
{
struct V_1 * V_1 = F_429 ( V_6 ) ;
F_431 ( V_6 ) ;
F_202 ( V_1 ) ;
}
static void F_432 ( struct V_1 * V_6 , int V_445 )
{
if ( V_445 == V_561 ) {
V_6 -> V_555 = true ;
F_426 ( V_6 -> V_8 . V_29 ) ;
} else {
V_6 -> V_555 = false ;
F_426 ( V_6 -> V_8 . V_29 ) ;
}
}
static void F_433 ( struct V_2 * V_3 )
{
if ( V_3 -> V_120 ( V_3 ) ) {
struct V_1 * V_6 = V_3 -> V_6 ;
struct V_75 * V_29 ;
bool V_562 ;
enum V_4 V_4 ;
F_142 ( L_81 ,
V_3 -> V_8 . V_8 . V_227 ,
V_3 -> V_8 . V_121 ) ;
if ( V_3 -> V_5 )
return;
F_52 ( V_3 -> V_8 . V_558 == V_559 ,
L_82 ) ;
F_52 ( V_3 -> V_8 . V_6 != & V_6 -> V_8 ,
L_83 ) ;
if ( V_6 ) {
F_52 ( ! V_6 -> V_555 ,
L_84 ) ;
V_562 = V_6 -> V_120 ( V_6 , & V_4 ) ;
F_52 ( ! V_562 , L_85 ) ;
if ( F_90 ( ! V_6 -> V_8 . V_29 ) )
return;
V_29 = V_6 -> V_8 . V_29 ;
F_52 ( ! V_29 -> V_106 , L_86 ) ;
F_52 ( ! F_37 ( V_29 ) -> V_76 , L_87 ) ;
F_52 ( V_4 != F_37 ( V_29 ) -> V_4 ,
L_88 ) ;
}
}
}
void F_434 ( struct V_556 * V_3 , int V_445 )
{
if ( V_445 != V_561 )
V_445 = V_559 ;
if ( V_445 == V_3 -> V_558 )
return;
V_3 -> V_558 = V_445 ;
if ( V_3 -> V_6 )
F_432 ( F_429 ( V_3 -> V_6 ) , V_445 ) ;
F_435 ( V_3 -> V_10 ) ;
}
bool F_436 ( struct V_2 * V_3 )
{
enum V_4 V_4 = 0 ;
struct V_1 * V_6 = V_3 -> V_6 ;
return V_6 -> V_120 ( V_6 , & V_4 ) ;
}
static bool F_437 ( struct V_9 * V_10 , enum V_4 V_4 ,
struct V_198 * V_199 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_377 =
F_37 ( V_12 -> V_83 [ V_138 ] ) ;
F_142 ( L_89 ,
F_69 ( V_4 ) , V_199 -> V_386 ) ;
if ( V_199 -> V_386 > 4 ) {
F_142 ( L_90 ,
F_69 ( V_4 ) , V_199 -> V_386 ) ;
return false ;
}
if ( F_218 ( V_10 ) || F_168 ( V_10 ) ) {
if ( V_199 -> V_386 > 2 ) {
F_142 ( L_91 ,
V_199 -> V_386 ) ;
return false ;
} else {
return true ;
}
}
if ( F_43 ( V_10 ) -> V_563 == 2 )
return true ;
switch ( V_4 ) {
case V_129 :
return true ;
case V_138 :
if ( V_12 -> V_83 [ V_379 ] -> V_106 &&
V_199 -> V_386 > 2 ) {
F_142 ( L_92 ,
F_69 ( V_4 ) , V_199 -> V_386 ) ;
return false ;
}
return true ;
case V_379 :
if ( ! F_257 ( V_377 ) ||
V_377 -> V_79 -> V_386 <= 2 ) {
if ( V_199 -> V_386 > 2 ) {
F_142 ( L_92 ,
F_69 ( V_4 ) , V_199 -> V_386 ) ;
return false ;
}
} else {
F_142 ( L_93 ) ;
return false ;
}
return true ;
default:
F_136 () ;
}
}
static int F_438 ( struct V_28 * V_28 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_361 * V_80 = & V_199 -> V_8 . V_80 ;
int V_564 , V_565 , V_566 ;
bool V_567 , V_568 = false ;
V_391:
V_565 = F_6 ( V_10 ) * F_439 ( 100 ) / F_440 ( 1 ) / 10 ;
V_566 = V_80 -> V_81 ;
V_564 = F_441 ( V_566 , V_565 ,
V_199 -> V_569 ) ;
V_199 -> V_386 = V_564 ;
F_442 ( V_199 -> V_569 , V_564 , V_566 ,
V_565 , & V_199 -> V_483 ) ;
V_567 = F_437 ( V_28 -> V_8 . V_10 ,
V_28 -> V_4 , V_199 ) ;
if ( ! V_567 && V_199 -> V_569 > 6 * 3 ) {
V_199 -> V_569 -= 2 * 3 ;
F_142 ( L_94 ,
V_199 -> V_569 ) ;
V_568 = true ;
V_199 -> V_570 = true ;
goto V_391;
}
if ( V_568 )
return V_571 ;
return V_567 ? 0 : - V_272 ;
}
static void F_443 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
V_199 -> V_468 = V_362 . V_572 &&
F_360 ( V_29 ) &&
V_199 -> V_569 <= 24 ;
}
static int F_444 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_361 * V_80 = & V_199 -> V_8 . V_80 ;
if ( F_43 ( V_10 ) -> V_91 < 4 ) {
int V_573 =
V_12 -> V_252 . V_523 ( V_10 ) ;
if ( ( V_29 -> V_4 == V_129 || F_445 ( V_10 ) ) &&
V_80 -> V_81 > V_573 * 9 / 10 ) {
V_573 *= 2 ;
V_199 -> V_248 = true ;
}
if ( V_80 -> V_81 > V_573 * 9 / 10 )
return - V_272 ;
}
if ( ( F_10 ( V_29 , V_33 ) &&
F_15 ( V_10 ) ) || V_199 -> V_248 )
V_199 -> V_326 &= ~ 1 ;
if ( ( F_43 ( V_10 ) -> V_91 > 4 || F_18 ( V_10 ) ) &&
V_80 -> V_574 == V_80 -> V_575 )
return - V_272 ;
if ( ( F_18 ( V_10 ) || F_21 ( V_10 ) ) && V_199 -> V_569 > 10 * 3 ) {
V_199 -> V_569 = 10 * 3 ;
} else if ( F_43 ( V_10 ) -> V_91 <= 4 && V_199 -> V_569 > 8 * 3 ) {
V_199 -> V_569 = 8 * 3 ;
}
if ( F_361 ( V_10 ) )
F_443 ( V_29 , V_199 ) ;
if ( V_199 -> V_247 )
return F_438 ( V_29 , V_199 ) ;
return 0 ;
}
static int F_446 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_108 ;
int V_532 ;
if ( F_20 ( V_10 ) )
return 400000 ;
if ( V_12 -> V_518 == 0 )
V_12 -> V_518 = F_395 ( V_12 ) ;
F_54 ( & V_12 -> V_111 ) ;
V_108 = F_55 ( V_12 , V_533 ) ;
F_56 ( & V_12 -> V_111 ) ;
V_532 = V_108 & V_534 ;
F_46 ( ( V_108 & V_535 ) !=
( V_532 << V_536 ) ,
L_95 ) ;
return F_9 ( V_12 -> V_518 << 1 , V_532 + 1 ) ;
}
static int F_447 ( struct V_9 * V_10 )
{
return 400000 ;
}
static int F_448 ( struct V_9 * V_10 )
{
return 333000 ;
}
static int F_449 ( struct V_9 * V_10 )
{
return 200000 ;
}
static int F_450 ( struct V_9 * V_10 )
{
T_5 V_576 = 0 ;
F_451 ( V_10 -> V_577 , V_578 , & V_576 ) ;
switch ( V_576 & V_579 ) {
case V_580 :
return 267000 ;
case V_581 :
return 333000 ;
case V_582 :
return 444000 ;
case V_583 :
return 200000 ;
default:
F_121 ( L_96 , V_576 ) ;
case V_584 :
return 133000 ;
case V_585 :
return 167000 ;
}
}
static int F_452 ( struct V_9 * V_10 )
{
T_5 V_576 = 0 ;
F_451 ( V_10 -> V_577 , V_578 , & V_576 ) ;
if ( V_576 & V_586 )
return 133000 ;
else {
switch ( V_576 & V_579 ) {
case V_587 :
return 333000 ;
default:
case V_588 :
return 190000 ;
}
}
}
static int F_453 ( struct V_9 * V_10 )
{
return 266000 ;
}
static int F_454 ( struct V_9 * V_10 )
{
T_5 V_589 = 0 ;
switch ( V_589 & V_590 ) {
case V_591 :
case V_592 :
return 200000 ;
case V_593 :
return 250000 ;
case V_594 :
return 133000 ;
}
return 0 ;
}
static int F_455 ( struct V_9 * V_10 )
{
return 133000 ;
}
static void
F_456 ( T_4 * V_595 , T_4 * V_596 )
{
while ( * V_595 > V_597 ||
* V_596 > V_597 ) {
* V_595 >>= 1 ;
* V_596 >>= 1 ;
}
}
static void F_457 ( unsigned int V_19 , unsigned int V_25 ,
T_4 * V_598 , T_4 * V_599 )
{
* V_599 = F_458 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_598 = F_34 ( ( V_57 ) V_19 * * V_599 , V_25 ) ;
F_456 ( V_598 , V_599 ) ;
}
void
F_442 ( int V_600 , int V_601 ,
int V_602 , int V_603 ,
struct V_604 * V_605 )
{
V_605 -> V_606 = 64 ;
F_457 ( V_600 * V_602 ,
V_603 * V_601 * 8 ,
& V_605 -> V_607 , & V_605 -> V_608 ) ;
F_457 ( V_602 , V_603 ,
& V_605 -> V_609 , & V_605 -> V_610 ) ;
}
static inline bool F_459 ( struct V_11 * V_12 )
{
if ( V_362 . V_611 >= 0 )
return V_362 . V_611 != 0 ;
return V_12 -> V_612 . V_613
&& ! ( V_12 -> V_147 & V_614 ) ;
}
static int F_460 ( struct V_28 * V_29 , int V_615 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_18 ;
if ( F_21 ( V_10 ) ) {
V_18 = 100000 ;
} else if ( F_12 ( V_29 , V_33 ) &&
F_459 ( V_12 ) && V_615 < 2 ) {
V_18 = V_12 -> V_612 . V_616 ;
F_142 ( L_97 , V_18 ) ;
} else if ( ! F_22 ( V_10 ) ) {
V_18 = 96000 ;
} else {
V_18 = 48000 ;
}
return V_18 ;
}
static T_4 F_461 ( struct V_56 * V_56 )
{
return ( 1 << V_56 -> V_25 ) << 16 | V_56 -> V_21 ;
}
static T_4 F_462 ( struct V_56 * V_56 )
{
return V_56 -> V_25 << 16 | V_56 -> V_20 << 8 | V_56 -> V_21 ;
}
static void F_463 ( struct V_28 * V_29 ,
struct V_198 * V_452 ,
T_2 * V_617 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_1 V_618 , V_619 = 0 ;
if ( F_19 ( V_10 ) ) {
V_618 = F_461 ( & V_452 -> V_56 ) ;
if ( V_617 )
V_619 = F_461 ( V_617 ) ;
} else {
V_618 = F_462 ( & V_452 -> V_56 ) ;
if ( V_617 )
V_619 = F_462 ( V_617 ) ;
}
V_452 -> V_200 . V_551 = V_618 ;
V_29 -> V_620 = false ;
if ( F_12 ( V_29 , V_33 ) &&
V_617 && V_362 . V_621 ) {
V_452 -> V_200 . V_552 = V_619 ;
V_29 -> V_620 = true ;
} else {
V_452 -> V_200 . V_552 = V_618 ;
}
}
static void F_464 ( struct V_11 * V_12 , enum V_4
V_4 )
{
T_1 V_622 ;
V_622 = F_125 ( V_12 , V_4 , F_465 ( 1 ) ) ;
V_622 &= 0xffffff00 ;
V_622 |= 0x00000030 ;
F_127 ( V_12 , V_4 , F_465 ( 1 ) , V_622 ) ;
V_622 = F_125 ( V_12 , V_4 , V_623 ) ;
V_622 &= 0x8cffffff ;
V_622 = 0x8c000000 ;
F_127 ( V_12 , V_4 , V_623 , V_622 ) ;
V_622 = F_125 ( V_12 , V_4 , F_465 ( 1 ) ) ;
V_622 &= 0xffffff00 ;
F_127 ( V_12 , V_4 , F_465 ( 1 ) , V_622 ) ;
V_622 = F_125 ( V_12 , V_4 , V_623 ) ;
V_622 &= 0x00ffffff ;
V_622 |= 0xb0000000 ;
F_127 ( V_12 , V_4 , V_623 , V_622 ) ;
}
static void F_466 ( struct V_28 * V_29 ,
struct V_604 * V_605 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
F_118 ( F_467 ( V_4 ) , F_468 ( V_605 -> V_606 ) | V_605 -> V_607 ) ;
F_118 ( F_469 ( V_4 ) , V_605 -> V_608 ) ;
F_118 ( F_470 ( V_4 ) , V_605 -> V_609 ) ;
F_118 ( F_471 ( V_4 ) , V_605 -> V_610 ) ;
}
static void F_354 ( struct V_28 * V_29 ,
struct V_604 * V_605 ,
struct V_604 * V_624 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
enum V_82 V_82 = V_29 -> V_79 -> V_84 ;
if ( F_43 ( V_10 ) -> V_91 >= 5 ) {
F_118 ( F_309 ( V_82 ) , F_468 ( V_605 -> V_606 ) | V_605 -> V_607 ) ;
F_118 ( F_472 ( V_82 ) , V_605 -> V_608 ) ;
F_118 ( F_473 ( V_82 ) , V_605 -> V_609 ) ;
F_118 ( F_474 ( V_82 ) , V_605 -> V_610 ) ;
if ( V_624 && F_43 ( V_10 ) -> V_91 < 8 &&
V_29 -> V_79 -> V_625 ) {
F_118 ( F_475 ( V_82 ) ,
F_468 ( V_624 -> V_606 ) | V_624 -> V_607 ) ;
F_118 ( F_476 ( V_82 ) , V_624 -> V_608 ) ;
F_118 ( F_477 ( V_82 ) , V_624 -> V_609 ) ;
F_118 ( F_478 ( V_82 ) , V_624 -> V_610 ) ;
}
} else {
F_118 ( F_479 ( V_4 ) , F_468 ( V_605 -> V_606 ) | V_605 -> V_607 ) ;
F_118 ( F_480 ( V_4 ) , V_605 -> V_608 ) ;
F_118 ( F_481 ( V_4 ) , V_605 -> V_609 ) ;
F_118 ( F_482 ( V_4 ) , V_605 -> V_610 ) ;
}
}
void F_352 ( struct V_28 * V_29 )
{
if ( V_29 -> V_79 -> V_247 )
F_466 ( V_29 , & V_29 -> V_79 -> V_626 ) ;
else
F_354 ( V_29 , & V_29 -> V_79 -> V_626 ,
& V_29 -> V_79 -> V_627 ) ;
}
static void F_483 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
T_1 V_56 , V_202 ;
V_56 = V_628 | V_209 |
V_629 | V_630 ;
if ( V_29 -> V_4 == V_138 )
V_56 |= V_208 ;
V_56 |= V_110 ;
V_199 -> V_200 . V_56 = V_56 ;
V_202 = ( V_199 -> V_488 - 1 )
<< V_631 ;
V_199 -> V_200 . V_202 = V_202 ;
}
static void F_412 ( struct V_28 * V_29 ,
const struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
T_1 V_632 ;
T_1 V_633 , V_634 , V_635 , V_636 , V_637 ;
T_1 V_638 , V_622 ;
F_54 ( & V_12 -> V_111 ) ;
V_633 = V_199 -> V_56 . V_25 ;
V_634 = V_199 -> V_56 . V_20 ;
V_635 = V_199 -> V_56 . V_21 ;
V_636 = V_199 -> V_56 . V_23 ;
V_637 = V_199 -> V_56 . V_24 ;
if ( V_4 == V_138 )
F_464 ( V_12 , V_4 ) ;
F_127 ( V_12 , V_4 , V_639 , 0x0100000f ) ;
V_622 = F_125 ( V_12 , V_4 , F_484 ( V_4 ) ) ;
V_622 &= 0x00ffffff ;
F_127 ( V_12 , V_4 , F_484 ( V_4 ) , V_622 ) ;
F_127 ( V_12 , V_4 , V_640 , 0x610 ) ;
V_632 = ( ( V_634 << V_641 ) | ( V_635 & V_642 ) ) ;
V_632 |= ( ( V_636 << V_643 ) | ( V_637 << V_644 ) ) ;
V_632 |= ( ( V_633 << V_645 ) ) ;
V_632 |= ( 1 << V_646 ) ;
V_632 |= ( V_647 << V_648 ) ;
F_127 ( V_12 , V_4 , F_485 ( V_4 ) , V_632 ) ;
V_632 |= V_649 ;
F_127 ( V_12 , V_4 , F_485 ( V_4 ) , V_632 ) ;
if ( V_199 -> V_650 == 162000 ||
F_10 ( V_29 , V_42 ) ||
F_10 ( V_29 , V_41 ) )
F_127 ( V_12 , V_4 , F_486 ( V_4 ) ,
0x009f0003 ) ;
else
F_127 ( V_12 , V_4 , F_486 ( V_4 ) ,
0x00d0000f ) ;
if ( V_199 -> V_439 ) {
if ( V_4 == V_129 )
F_127 ( V_12 , V_4 , F_487 ( V_4 ) ,
0x0df40000 ) ;
else
F_127 ( V_12 , V_4 , F_487 ( V_4 ) ,
0x0df70000 ) ;
} else {
if ( V_4 == V_129 )
F_127 ( V_12 , V_4 , F_487 ( V_4 ) ,
0x0df70000 ) ;
else
F_127 ( V_12 , V_4 , F_487 ( V_4 ) ,
0x0df40000 ) ;
}
V_638 = F_125 ( V_12 , V_4 , F_488 ( V_4 ) ) ;
V_638 = ( V_638 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_10 ( V_29 , V_507 ) ||
F_10 ( V_29 , V_367 ) )
V_638 |= 0x01000000 ;
F_127 ( V_12 , V_4 , F_488 ( V_4 ) , V_638 ) ;
F_127 ( V_12 , V_4 , F_489 ( V_4 ) , 0x87871000 ) ;
F_56 ( & V_12 -> V_111 ) ;
}
static void F_490 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
V_199 -> V_200 . V_56 = V_210 |
V_209 | V_629 |
V_110 ;
if ( V_29 -> V_4 != V_129 )
V_199 -> V_200 . V_56 |= V_208 ;
V_199 -> V_200 . V_202 =
( V_199 -> V_488 - 1 ) << V_631 ;
}
static void F_411 ( struct V_28 * V_29 ,
const struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
int V_219 = F_51 ( V_29 -> V_4 ) ;
enum V_203 V_94 = F_124 ( V_4 ) ;
T_1 V_651 , V_652 ;
T_1 V_633 , V_634 , V_635 , V_636 , V_637 , V_653 ;
int V_18 ;
V_633 = V_199 -> V_56 . V_25 ;
V_653 = V_199 -> V_56 . V_21 & 0x3fffff ;
V_634 = V_199 -> V_56 . V_20 ;
V_635 = V_199 -> V_56 . V_21 >> 22 ;
V_636 = V_199 -> V_56 . V_23 ;
V_637 = V_199 -> V_56 . V_24 ;
F_118 ( V_219 ,
V_199 -> V_200 . V_56 & ~ V_110 ) ;
F_54 ( & V_12 -> V_111 ) ;
F_127 ( V_12 , V_4 , F_491 ( V_94 ) ,
5 << V_654 |
V_636 << V_655 |
V_637 << V_656 |
1 << V_657 ) ;
F_127 ( V_12 , V_4 , F_492 ( V_94 ) , V_635 ) ;
F_127 ( V_12 , V_4 , F_493 ( V_94 ) ,
V_658 |
1 << V_659 ) ;
F_127 ( V_12 , V_4 , F_494 ( V_94 ) , V_653 ) ;
F_127 ( V_12 , V_4 , F_495 ( V_94 ) ,
V_660 |
( 2 << V_661 ) ) ;
V_18 = F_460 ( V_29 , 0 ) ;
V_651 = 5 << V_662 |
2 << V_663 ;
if ( V_18 == 100000 )
V_652 = 11 ;
else if ( V_18 == 38400 )
V_652 = 10 ;
else
V_652 = 9 ;
V_651 |= V_652 << V_664 ;
F_127 ( V_12 , V_4 , F_496 ( V_94 ) , V_651 ) ;
F_127 ( V_12 , V_4 , F_126 ( V_94 ) ,
F_125 ( V_12 , V_4 , F_126 ( V_94 ) ) |
V_665 ) ;
F_56 ( & V_12 -> V_111 ) ;
}
void F_497 ( struct V_9 * V_10 , enum V_4 V_4 ,
const struct V_56 * V_56 )
{
struct V_28 * V_29 =
F_37 ( F_498 ( V_10 , V_4 ) ) ;
struct V_198 V_199 = {
. V_488 = 1 ,
. V_56 = * V_56 ,
} ;
if ( F_20 ( V_10 ) ) {
F_490 ( V_29 , & V_199 ) ;
F_411 ( V_29 , & V_199 ) ;
F_123 ( V_29 , & V_199 ) ;
} else {
F_483 ( V_29 , & V_199 ) ;
F_412 ( V_29 , & V_199 ) ;
F_114 ( V_29 , & V_199 ) ;
}
}
void F_499 ( struct V_9 * V_10 , enum V_4 V_4 )
{
if ( F_20 ( V_10 ) )
F_134 ( F_234 ( V_10 ) , V_4 ) ;
else
F_133 ( F_234 ( V_10 ) , V_4 ) ;
}
static void F_500 ( struct V_28 * V_29 ,
struct V_198 * V_452 ,
T_2 * V_617 ,
int V_615 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_56 ;
bool V_666 ;
struct V_56 * clock = & V_452 -> V_56 ;
F_463 ( V_29 , V_452 , V_617 ) ;
V_666 = F_12 ( V_29 , V_44 ) ||
F_12 ( V_29 , V_41 ) ;
V_56 = V_629 ;
if ( F_12 ( V_29 , V_33 ) )
V_56 |= V_667 ;
else
V_56 |= V_668 ;
if ( F_501 ( V_10 ) || F_502 ( V_10 ) || F_503 ( V_10 ) ) {
V_56 |= ( V_452 -> V_488 - 1 )
<< V_669 ;
}
if ( V_666 )
V_56 |= V_670 ;
if ( V_452 -> V_439 )
V_56 |= V_670 ;
if ( F_19 ( V_10 ) )
V_56 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_671 ;
else {
V_56 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_672 ;
if ( F_18 ( V_10 ) && V_617 )
V_56 |= ( 1 << ( V_617 -> V_23 - 1 ) ) << V_673 ;
}
switch ( clock -> V_24 ) {
case 5 :
V_56 |= V_674 ;
break;
case 7 :
V_56 |= V_675 ;
break;
case 10 :
V_56 |= V_676 ;
break;
case 14 :
V_56 |= V_677 ;
break;
}
if ( F_43 ( V_10 ) -> V_91 >= 4 )
V_56 |= ( 6 << V_678 ) ;
if ( V_452 -> V_679 )
V_56 |= V_680 ;
else if ( F_12 ( V_29 , V_33 ) &&
F_459 ( V_12 ) && V_615 < 2 )
V_56 |= V_681 ;
else
V_56 |= V_682 ;
V_56 |= V_110 ;
V_452 -> V_200 . V_56 = V_56 ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
T_1 V_202 = ( V_452 -> V_488 - 1 )
<< V_631 ;
V_452 -> V_200 . V_202 = V_202 ;
}
}
static void F_504 ( struct V_28 * V_29 ,
struct V_198 * V_452 ,
T_2 * V_617 ,
int V_615 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_56 ;
struct V_56 * clock = & V_452 -> V_56 ;
F_463 ( V_29 , V_452 , V_617 ) ;
V_56 = V_629 ;
if ( F_12 ( V_29 , V_33 ) ) {
V_56 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_672 ;
} else {
if ( clock -> V_23 == 2 )
V_56 |= V_683 ;
else
V_56 |= ( clock -> V_23 - 2 ) << V_672 ;
if ( clock -> V_24 == 4 )
V_56 |= V_684 ;
}
if ( ! F_131 ( V_10 ) && F_12 ( V_29 , V_53 ) )
V_56 |= V_207 ;
if ( F_12 ( V_29 , V_33 ) &&
F_459 ( V_12 ) && V_615 < 2 )
V_56 |= V_681 ;
else
V_56 |= V_682 ;
V_56 |= V_110 ;
V_452 -> V_200 . V_56 = V_56 ;
}
static void F_353 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_28 -> V_4 ;
enum V_82 V_84 = V_28 -> V_79 -> V_84 ;
struct V_361 * V_80 =
& V_28 -> V_79 -> V_8 . V_80 ;
T_4 V_685 , V_686 ;
int V_687 = 0 ;
V_685 = V_80 -> V_685 ;
V_686 = V_80 -> V_686 ;
if ( V_80 -> V_446 & V_688 ) {
V_685 -= 1 ;
V_686 -= 1 ;
if ( F_10 ( V_28 , V_44 ) )
V_687 = ( V_80 -> V_689 - 1 ) / 2 ;
else
V_687 = V_80 -> V_690 -
V_80 -> V_689 / 2 ;
if ( V_687 < 0 )
V_687 += V_80 -> V_689 ;
}
if ( F_43 ( V_10 ) -> V_91 > 3 )
F_118 ( F_304 ( V_84 ) , V_687 ) ;
F_118 ( F_292 ( V_84 ) ,
( V_80 -> V_364 - 1 ) |
( ( V_80 -> V_689 - 1 ) << 16 ) ) ;
F_118 ( F_294 ( V_84 ) ,
( V_80 -> V_691 - 1 ) |
( ( V_80 -> V_692 - 1 ) << 16 ) ) ;
F_118 ( F_296 ( V_84 ) ,
( V_80 -> V_690 - 1 ) |
( ( V_80 -> V_693 - 1 ) << 16 ) ) ;
F_118 ( F_298 ( V_84 ) ,
( V_80 -> V_365 - 1 ) |
( ( V_685 - 1 ) << 16 ) ) ;
F_118 ( F_300 ( V_84 ) ,
( V_80 -> V_694 - 1 ) |
( ( V_686 - 1 ) << 16 ) ) ;
F_118 ( F_302 ( V_84 ) ,
( V_80 -> V_695 - 1 ) |
( ( V_80 -> V_696 - 1 ) << 16 ) ) ;
if ( F_218 ( V_10 ) && V_84 == V_487 &&
( V_4 == V_138 || V_4 == V_379 ) )
F_118 ( F_298 ( V_4 ) , F_5 ( F_298 ( V_84 ) ) ) ;
F_118 ( F_251 ( V_4 ) ,
( ( V_28 -> V_79 -> V_326 - 1 ) << 16 ) |
( V_28 -> V_79 -> V_325 - 1 ) ) ;
}
static void F_505 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_82 V_84 = V_199 -> V_84 ;
T_4 V_204 ;
V_204 = F_5 ( F_292 ( V_84 ) ) ;
V_199 -> V_8 . V_80 . V_364 = ( V_204 & 0xffff ) + 1 ;
V_199 -> V_8 . V_80 . V_689 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_204 = F_5 ( F_294 ( V_84 ) ) ;
V_199 -> V_8 . V_80 . V_691 = ( V_204 & 0xffff ) + 1 ;
V_199 -> V_8 . V_80 . V_692 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_204 = F_5 ( F_296 ( V_84 ) ) ;
V_199 -> V_8 . V_80 . V_690 = ( V_204 & 0xffff ) + 1 ;
V_199 -> V_8 . V_80 . V_693 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_204 = F_5 ( F_298 ( V_84 ) ) ;
V_199 -> V_8 . V_80 . V_365 = ( V_204 & 0xffff ) + 1 ;
V_199 -> V_8 . V_80 . V_685 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_204 = F_5 ( F_300 ( V_84 ) ) ;
V_199 -> V_8 . V_80 . V_694 = ( V_204 & 0xffff ) + 1 ;
V_199 -> V_8 . V_80 . V_686 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_204 = F_5 ( F_302 ( V_84 ) ) ;
V_199 -> V_8 . V_80 . V_695 = ( V_204 & 0xffff ) + 1 ;
V_199 -> V_8 . V_80 . V_696 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
if ( F_5 ( F_44 ( V_84 ) ) & V_235 ) {
V_199 -> V_8 . V_80 . V_446 |= V_688 ;
V_199 -> V_8 . V_80 . V_685 += 1 ;
V_199 -> V_8 . V_80 . V_686 += 1 ;
}
V_204 = F_5 ( F_251 ( V_29 -> V_4 ) ) ;
V_199 -> V_325 = ( V_204 & 0xffff ) + 1 ;
V_199 -> V_326 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_199 -> V_8 . V_445 . V_697 = V_199 -> V_325 ;
V_199 -> V_8 . V_445 . V_575 = V_199 -> V_326 ;
}
void F_506 ( struct V_361 * V_445 ,
struct V_198 * V_199 )
{
V_445 -> V_575 = V_199 -> V_8 . V_80 . V_364 ;
V_445 -> V_698 = V_199 -> V_8 . V_80 . V_689 ;
V_445 -> V_574 = V_199 -> V_8 . V_80 . V_690 ;
V_445 -> V_699 = V_199 -> V_8 . V_80 . V_693 ;
V_445 -> V_697 = V_199 -> V_8 . V_80 . V_365 ;
V_445 -> V_700 = V_199 -> V_8 . V_80 . V_685 ;
V_445 -> V_701 = V_199 -> V_8 . V_80 . V_695 ;
V_445 -> V_702 = V_199 -> V_8 . V_80 . V_696 ;
V_445 -> V_446 = V_199 -> V_8 . V_80 . V_446 ;
V_445 -> clock = V_199 -> V_8 . V_80 . V_81 ;
V_445 -> V_446 |= V_199 -> V_8 . V_80 . V_446 ;
}
static void F_415 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_703 ;
V_703 = 0 ;
if ( ( V_28 -> V_4 == V_129 && V_12 -> V_147 & V_148 ) ||
( V_28 -> V_4 == V_138 && V_12 -> V_147 & V_149 ) )
V_703 |= F_5 ( F_44 ( V_28 -> V_4 ) ) & V_150 ;
if ( V_28 -> V_79 -> V_248 )
V_703 |= V_249 ;
if ( F_18 ( V_10 ) || F_21 ( V_10 ) ) {
if ( V_28 -> V_79 -> V_704 && V_28 -> V_79 -> V_569 != 30 )
V_703 |= V_705 |
V_706 ;
switch ( V_28 -> V_79 -> V_569 ) {
case 18 :
V_703 |= V_707 ;
break;
case 24 :
V_703 |= V_708 ;
break;
case 30 :
V_703 |= V_709 ;
break;
default:
F_136 () ;
}
}
if ( F_507 ( V_10 ) ) {
if ( V_28 -> V_620 ) {
F_142 ( L_98 ) ;
V_703 |= V_710 ;
} else {
F_142 ( L_99 ) ;
}
}
if ( V_28 -> V_79 -> V_8 . V_80 . V_446 & V_688 ) {
if ( F_43 ( V_10 ) -> V_91 < 4 ||
F_10 ( V_28 , V_44 ) )
V_703 |= V_711 ;
else
V_703 |= V_712 ;
} else
V_703 |= V_713 ;
if ( F_21 ( V_10 ) && V_28 -> V_79 -> V_714 )
V_703 |= V_715 ;
F_118 ( F_44 ( V_28 -> V_4 ) , V_703 ) ;
F_119 ( F_44 ( V_28 -> V_4 ) ) ;
}
static int F_508 ( struct V_28 * V_29 ,
struct V_198 * V_452 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_18 , V_615 = 0 ;
T_2 clock , V_617 ;
bool V_716 , V_717 = false ;
bool V_718 = false , V_548 = false ;
struct V_1 * V_6 ;
const T_3 * V_32 ;
F_13 (dev, encoder) {
if ( V_6 -> V_31 != V_29 )
continue;
switch ( V_6 -> type ) {
case V_33 :
V_718 = true ;
break;
case V_246 :
V_548 = true ;
break;
default:
break;
}
V_615 ++ ;
}
if ( V_548 )
return 0 ;
if ( ! V_452 -> V_719 ) {
V_18 = F_460 ( V_29 , V_615 ) ;
V_32 = F_17 ( V_29 , V_18 ) ;
V_716 = V_12 -> V_252 . V_720 ( V_32 , V_29 ,
V_452 -> V_650 ,
V_18 , NULL , & clock ) ;
if ( ! V_716 ) {
F_121 ( L_100 ) ;
return - V_272 ;
}
if ( V_718 && V_12 -> V_721 ) {
V_717 =
V_12 -> V_252 . V_720 ( V_32 , V_29 ,
V_12 -> V_722 ,
V_18 , & clock ,
& V_617 ) ;
}
V_452 -> V_56 . V_25 = clock . V_25 ;
V_452 -> V_56 . V_20 = clock . V_20 ;
V_452 -> V_56 . V_21 = clock . V_21 ;
V_452 -> V_56 . V_23 = clock . V_23 ;
V_452 -> V_56 . V_24 = clock . V_24 ;
}
if ( F_22 ( V_10 ) ) {
F_504 ( V_29 , V_452 ,
V_717 ? & V_617 : NULL ,
V_615 ) ;
} else if ( F_20 ( V_10 ) ) {
F_490 ( V_29 , V_452 ) ;
} else if ( F_21 ( V_10 ) ) {
F_483 ( V_29 , V_452 ) ;
} else {
F_500 ( V_29 , V_452 ,
V_717 ? & V_617 : NULL ,
V_615 ) ;
}
return 0 ;
}
static void F_509 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_204 ;
if ( F_43 ( V_10 ) -> V_91 <= 3 && ( F_131 ( V_10 ) || ! F_117 ( V_10 ) ) )
return;
V_204 = F_5 ( V_494 ) ;
if ( ! ( V_204 & V_495 ) )
return;
if ( F_43 ( V_10 ) -> V_91 < 4 ) {
if ( V_29 -> V_4 != V_138 )
return;
} else {
if ( ( V_204 & V_723 ) != ( V_29 -> V_4 << V_724 ) )
return;
}
V_199 -> V_492 . V_493 = V_204 ;
V_199 -> V_492 . V_497 = F_5 ( V_496 ) ;
if ( F_43 ( V_10 ) -> V_91 < 5 )
V_199 -> V_492 . V_725 =
F_5 ( V_140 ) & V_726 ;
}
static void F_510 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_199 -> V_84 ;
T_2 clock ;
T_1 V_632 ;
int V_18 = 100000 ;
if ( ! ( V_199 -> V_200 . V_56 & V_110 ) )
return;
F_54 ( & V_12 -> V_111 ) ;
V_632 = F_125 ( V_12 , V_4 , F_485 ( V_4 ) ) ;
F_56 ( & V_12 -> V_111 ) ;
clock . V_20 = ( V_632 >> V_641 ) & 7 ;
clock . V_21 = V_632 & V_642 ;
clock . V_25 = ( V_632 >> V_645 ) & 0xf ;
clock . V_23 = ( V_632 >> V_643 ) & 7 ;
clock . V_24 = ( V_632 >> V_644 ) & 0x1f ;
F_8 ( V_18 , & clock ) ;
V_199 -> V_650 = clock . V_27 / 5 ;
}
static void
F_511 ( struct V_28 * V_29 ,
struct V_304 * V_305 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_108 , V_8 , V_281 ;
int V_4 = V_29 -> V_4 , V_151 = V_29 -> V_151 ;
int V_727 , V_314 ;
int V_728 ;
struct V_260 * V_78 ;
struct V_338 * V_339 ;
V_108 = F_5 ( F_78 ( V_151 ) ) ;
if ( ! ( V_108 & V_152 ) )
return;
V_339 = F_512 ( sizeof( * V_339 ) , V_457 ) ;
if ( ! V_339 ) {
F_142 ( L_101 ) ;
return;
}
V_78 = & V_339 -> V_8 ;
if ( F_43 ( V_10 ) -> V_91 >= 4 )
if ( V_108 & V_331 )
V_305 -> V_258 = V_270 ;
V_314 = V_108 & V_729 ;
V_727 = F_189 ( V_314 ) ;
V_78 -> V_314 = V_727 ;
V_78 -> V_600 = F_207 ( V_727 , 0 ) * 8 ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
if ( V_305 -> V_258 )
V_281 = F_5 ( F_215 ( V_151 ) ) ;
else
V_281 = F_5 ( F_216 ( V_151 ) ) ;
V_8 = F_5 ( F_164 ( V_151 ) ) & 0xfffff000 ;
} else {
V_8 = F_5 ( F_165 ( V_151 ) ) ;
}
V_305 -> V_8 = V_8 ;
V_108 = F_5 ( F_251 ( V_4 ) ) ;
V_78 -> V_315 = ( ( V_108 >> 16 ) & 0xfff ) + 1 ;
V_78 -> V_257 = ( ( V_108 >> 0 ) & 0xfff ) + 1 ;
V_108 = F_5 ( F_214 ( V_4 ) ) ;
V_78 -> V_313 [ 0 ] = V_108 & 0xffffffc0 ;
V_728 = F_173 ( V_10 , V_78 -> V_257 ,
V_305 -> V_258 ) ;
V_305 -> V_311 = V_78 -> V_313 [ 0 ] * V_728 ;
F_142 ( L_102 ,
F_69 ( V_4 ) , V_151 , V_78 -> V_315 , V_78 -> V_257 ,
V_78 -> V_600 , V_8 , V_78 -> V_313 [ 0 ] ,
V_305 -> V_311 ) ;
V_29 -> V_8 . V_77 -> V_78 = V_78 ;
}
static void F_513 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_199 -> V_84 ;
enum V_203 V_94 = F_124 ( V_4 ) ;
T_2 clock ;
T_1 V_730 , V_731 , V_732 , V_733 ;
int V_18 = 100000 ;
F_54 ( & V_12 -> V_111 ) ;
V_730 = F_125 ( V_12 , V_4 , F_491 ( V_94 ) ) ;
V_731 = F_125 ( V_12 , V_4 , F_492 ( V_94 ) ) ;
V_732 = F_125 ( V_12 , V_4 , F_493 ( V_94 ) ) ;
V_733 = F_125 ( V_12 , V_4 , F_494 ( V_94 ) ) ;
F_56 ( & V_12 -> V_111 ) ;
clock . V_20 = ( V_732 & 0x7 ) == V_658 ? 2 : 0 ;
clock . V_21 = ( ( V_731 & 0xff ) << 22 ) | ( V_733 & 0x3fffff ) ;
clock . V_25 = ( V_732 >> V_659 ) & 0xf ;
clock . V_23 = ( V_730 >> V_655 ) & 0x7 ;
clock . V_24 = ( V_730 >> V_656 ) & 0x1f ;
F_26 ( V_18 , & clock ) ;
V_199 -> V_650 = clock . V_27 / 5 ;
}
static bool F_514 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_204 ;
if ( ! F_75 ( V_12 ,
F_390 ( V_29 -> V_4 ) ) )
return false ;
V_199 -> V_84 = (enum V_82 ) V_29 -> V_4 ;
V_199 -> V_115 = V_451 ;
V_204 = F_5 ( F_44 ( V_29 -> V_4 ) ) ;
if ( ! ( V_204 & V_150 ) )
return false ;
if ( F_18 ( V_10 ) || F_21 ( V_10 ) ) {
switch ( V_204 & V_233 ) {
case V_707 :
V_199 -> V_569 = 18 ;
break;
case V_708 :
V_199 -> V_569 = 24 ;
break;
case V_709 :
V_199 -> V_569 = 30 ;
break;
default:
break;
}
}
if ( F_21 ( V_10 ) && ( V_204 & V_715 ) )
V_199 -> V_714 = true ;
if ( F_43 ( V_10 ) -> V_91 < 4 )
V_199 -> V_248 = V_204 & V_249 ;
F_505 ( V_29 , V_199 ) ;
F_509 ( V_29 , V_199 ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
V_204 = F_5 ( F_122 ( V_29 -> V_4 ) ) ;
V_199 -> V_488 =
( ( V_204 & V_734 )
>> V_631 ) + 1 ;
V_199 -> V_200 . V_202 = V_204 ;
} else if ( F_501 ( V_10 ) || F_502 ( V_10 ) || F_503 ( V_10 ) ) {
V_204 = F_5 ( F_51 ( V_29 -> V_4 ) ) ;
V_199 -> V_488 =
( ( V_204 & V_735 )
>> V_669 ) + 1 ;
} else {
V_199 -> V_488 = 1 ;
}
V_199 -> V_200 . V_56 = F_5 ( F_51 ( V_29 -> V_4 ) ) ;
if ( ! F_21 ( V_10 ) ) {
if ( F_131 ( V_10 ) )
V_199 -> V_200 . V_56 &= ~ V_207 ;
V_199 -> V_200 . V_551 = F_5 ( F_418 ( V_29 -> V_4 ) ) ;
V_199 -> V_200 . V_552 = F_5 ( F_419 ( V_29 -> V_4 ) ) ;
} else {
V_199 -> V_200 . V_56 &= ~ ( V_201 |
V_221 |
V_220 ) ;
}
if ( F_20 ( V_10 ) )
F_513 ( V_29 , V_199 ) ;
else if ( F_21 ( V_10 ) )
F_510 ( V_29 , V_199 ) ;
else
F_515 ( V_29 , V_199 ) ;
return true ;
}
static void F_516 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
T_1 V_108 , V_736 ;
bool V_737 = false ;
bool V_738 = false ;
bool V_739 = false ;
bool V_740 = false ;
bool V_741 = false ;
F_13 (dev, encoder) {
switch ( V_6 -> type ) {
case V_33 :
V_739 = true ;
V_737 = true ;
break;
case V_367 :
V_739 = true ;
if ( F_387 ( & V_6 -> V_8 ) -> V_94 == V_499 )
V_738 = true ;
break;
default:
break;
}
}
if ( F_48 ( V_10 ) ) {
V_740 = V_12 -> V_612 . V_742 ;
V_741 = V_740 ;
} else {
V_740 = false ;
V_741 = true ;
}
F_142 ( L_103 ,
V_739 , V_737 , V_740 ) ;
V_108 = F_5 ( V_162 ) ;
V_736 = V_108 ;
V_736 &= ~ V_164 ;
if ( V_740 )
V_736 |= V_743 ;
else
V_736 |= V_744 ;
V_736 &= ~ V_163 ;
V_736 &= ~ V_745 ;
V_736 &= ~ V_746 ;
if ( V_739 ) {
V_736 |= V_747 ;
if ( F_459 ( V_12 ) && V_741 )
V_736 |= V_746 ;
if ( V_738 ) {
if ( F_459 ( V_12 ) && V_741 )
V_736 |= V_748 ;
else
V_736 |= V_749 ;
} else
V_736 |= V_750 ;
} else {
V_736 |= V_751 ;
V_736 |= V_750 ;
}
if ( V_736 == V_108 )
return;
V_108 &= ~ V_164 ;
if ( V_740 )
V_108 |= V_743 ;
else
V_108 |= V_744 ;
if ( V_739 ) {
V_108 &= ~ V_163 ;
V_108 |= V_747 ;
if ( F_459 ( V_12 ) && V_741 ) {
F_142 ( L_104 ) ;
V_108 |= V_746 ;
} else
V_108 &= ~ V_746 ;
F_118 ( V_162 , V_108 ) ;
F_119 ( V_162 ) ;
F_120 ( 200 ) ;
V_108 &= ~ V_745 ;
if ( V_738 ) {
if ( F_459 ( V_12 ) && V_741 ) {
F_142 ( L_105 ) ;
V_108 |= V_748 ;
} else
V_108 |= V_749 ;
} else
V_108 |= V_750 ;
F_118 ( V_162 , V_108 ) ;
F_119 ( V_162 ) ;
F_120 ( 200 ) ;
} else {
F_142 ( L_106 ) ;
V_108 &= ~ V_745 ;
V_108 |= V_750 ;
F_118 ( V_162 , V_108 ) ;
F_119 ( V_162 ) ;
F_120 ( 200 ) ;
V_108 &= ~ V_163 ;
V_108 |= V_751 ;
V_108 &= ~ V_746 ;
F_118 ( V_162 , V_108 ) ;
F_119 ( V_162 ) ;
F_120 ( 200 ) ;
}
F_116 ( V_108 != V_736 ) ;
}
static void F_517 ( struct V_11 * V_12 )
{
T_4 V_204 ;
V_204 = F_5 ( V_752 ) ;
V_204 |= V_753 ;
F_118 ( V_752 , V_204 ) ;
if ( F_518 ( F_5 ( V_752 ) &
V_754 , 100 ) )
F_121 ( L_107 ) ;
V_204 = F_5 ( V_752 ) ;
V_204 &= ~ V_753 ;
F_118 ( V_752 , V_204 ) ;
if ( F_518 ( ( F_5 ( V_752 ) &
V_754 ) == 0 , 100 ) )
F_121 ( L_108 ) ;
}
static void F_519 ( struct V_11 * V_12 )
{
T_4 V_204 ;
V_204 = F_285 ( V_12 , 0x8008 , V_755 ) ;
V_204 &= ~ ( 0xFF << 24 ) ;
V_204 |= ( 0x12 << 24 ) ;
F_284 ( V_12 , 0x8008 , V_204 , V_755 ) ;
V_204 = F_285 ( V_12 , 0x2008 , V_755 ) ;
V_204 |= ( 1 << 11 ) ;
F_284 ( V_12 , 0x2008 , V_204 , V_755 ) ;
V_204 = F_285 ( V_12 , 0x2108 , V_755 ) ;
V_204 |= ( 1 << 11 ) ;
F_284 ( V_12 , 0x2108 , V_204 , V_755 ) ;
V_204 = F_285 ( V_12 , 0x206C , V_755 ) ;
V_204 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_284 ( V_12 , 0x206C , V_204 , V_755 ) ;
V_204 = F_285 ( V_12 , 0x216C , V_755 ) ;
V_204 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_284 ( V_12 , 0x216C , V_204 , V_755 ) ;
V_204 = F_285 ( V_12 , 0x2080 , V_755 ) ;
V_204 &= ~ ( 7 << 13 ) ;
V_204 |= ( 5 << 13 ) ;
F_284 ( V_12 , 0x2080 , V_204 , V_755 ) ;
V_204 = F_285 ( V_12 , 0x2180 , V_755 ) ;
V_204 &= ~ ( 7 << 13 ) ;
V_204 |= ( 5 << 13 ) ;
F_284 ( V_12 , 0x2180 , V_204 , V_755 ) ;
V_204 = F_285 ( V_12 , 0x208C , V_755 ) ;
V_204 &= ~ 0xFF ;
V_204 |= 0x1C ;
F_284 ( V_12 , 0x208C , V_204 , V_755 ) ;
V_204 = F_285 ( V_12 , 0x218C , V_755 ) ;
V_204 &= ~ 0xFF ;
V_204 |= 0x1C ;
F_284 ( V_12 , 0x218C , V_204 , V_755 ) ;
V_204 = F_285 ( V_12 , 0x2098 , V_755 ) ;
V_204 &= ~ ( 0xFF << 16 ) ;
V_204 |= ( 0x1C << 16 ) ;
F_284 ( V_12 , 0x2098 , V_204 , V_755 ) ;
V_204 = F_285 ( V_12 , 0x2198 , V_755 ) ;
V_204 &= ~ ( 0xFF << 16 ) ;
V_204 |= ( 0x1C << 16 ) ;
F_284 ( V_12 , 0x2198 , V_204 , V_755 ) ;
V_204 = F_285 ( V_12 , 0x20C4 , V_755 ) ;
V_204 |= ( 1 << 27 ) ;
F_284 ( V_12 , 0x20C4 , V_204 , V_755 ) ;
V_204 = F_285 ( V_12 , 0x21C4 , V_755 ) ;
V_204 |= ( 1 << 27 ) ;
F_284 ( V_12 , 0x21C4 , V_204 , V_755 ) ;
V_204 = F_285 ( V_12 , 0x20EC , V_755 ) ;
V_204 &= ~ ( 0xF << 28 ) ;
V_204 |= ( 4 << 28 ) ;
F_284 ( V_12 , 0x20EC , V_204 , V_755 ) ;
V_204 = F_285 ( V_12 , 0x21EC , V_755 ) ;
V_204 &= ~ ( 0xF << 28 ) ;
V_204 |= ( 4 << 28 ) ;
F_284 ( V_12 , 0x21EC , V_204 , V_755 ) ;
}
static void F_520 ( struct V_9 * V_10 , bool V_756 ,
bool V_757 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_85 , V_204 ;
if ( F_46 ( V_757 && ! V_756 , L_109 ) )
V_756 = true ;
if ( F_46 ( V_12 -> V_758 == V_759 &&
V_757 , L_110 ) )
V_757 = false ;
F_54 ( & V_12 -> V_111 ) ;
V_204 = F_285 ( V_12 , V_760 , V_421 ) ;
V_204 &= ~ V_422 ;
V_204 |= V_761 ;
F_284 ( V_12 , V_760 , V_204 , V_421 ) ;
F_120 ( 24 ) ;
if ( V_756 ) {
V_204 = F_285 ( V_12 , V_760 , V_421 ) ;
V_204 &= ~ V_761 ;
F_284 ( V_12 , V_760 , V_204 , V_421 ) ;
if ( V_757 ) {
F_517 ( V_12 ) ;
F_519 ( V_12 ) ;
}
}
V_85 = ( V_12 -> V_758 == V_759 ) ?
V_762 : V_763 ;
V_204 = F_285 ( V_12 , V_85 , V_421 ) ;
V_204 |= V_764 ;
F_284 ( V_12 , V_85 , V_204 , V_421 ) ;
F_56 ( & V_12 -> V_111 ) ;
}
static void F_521 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_85 , V_204 ;
F_54 ( & V_12 -> V_111 ) ;
V_85 = ( V_12 -> V_758 == V_759 ) ?
V_762 : V_763 ;
V_204 = F_285 ( V_12 , V_85 , V_421 ) ;
V_204 &= ~ V_764 ;
F_284 ( V_12 , V_85 , V_204 , V_421 ) ;
V_204 = F_285 ( V_12 , V_760 , V_421 ) ;
if ( ! ( V_204 & V_422 ) ) {
if ( ! ( V_204 & V_761 ) ) {
V_204 |= V_761 ;
F_284 ( V_12 , V_760 , V_204 , V_421 ) ;
F_120 ( 32 ) ;
}
V_204 |= V_422 ;
F_284 ( V_12 , V_760 , V_204 , V_421 ) ;
}
F_56 ( & V_12 -> V_111 ) ;
}
static void F_522 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
bool V_765 = false ;
F_13 (dev, encoder) {
switch ( V_6 -> type ) {
case V_42 :
V_765 = true ;
break;
default:
break;
}
}
if ( V_765 )
F_520 ( V_10 , true , true ) ;
else
F_521 ( V_10 ) ;
}
void F_523 ( struct V_9 * V_10 )
{
if ( F_48 ( V_10 ) || F_94 ( V_10 ) )
F_516 ( V_10 ) ;
else if ( F_158 ( V_10 ) )
F_522 ( V_10 ) ;
}
static int F_524 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
int V_615 = 0 ;
bool V_718 = false ;
F_13 (dev, encoder) {
if ( V_6 -> V_31 != F_37 ( V_29 ) )
continue;
switch ( V_6 -> type ) {
case V_33 :
V_718 = true ;
break;
default:
break;
}
V_615 ++ ;
}
if ( V_718 && F_459 ( V_12 ) && V_615 < 2 ) {
F_142 ( L_97 ,
V_12 -> V_612 . V_616 ) ;
return V_12 -> V_612 . V_616 ;
}
return 120000 ;
}
static void F_355 ( struct V_75 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_4 V_108 ;
V_108 = 0 ;
switch ( V_28 -> V_79 -> V_569 ) {
case 18 :
V_108 |= V_707 ;
break;
case 24 :
V_108 |= V_708 ;
break;
case 30 :
V_108 |= V_709 ;
break;
case 36 :
V_108 |= V_766 ;
break;
default:
F_136 () ;
}
if ( V_28 -> V_79 -> V_704 )
V_108 |= ( V_705 | V_706 ) ;
if ( V_28 -> V_79 -> V_8 . V_80 . V_446 & V_688 )
V_108 |= V_236 ;
else
V_108 |= V_713 ;
if ( V_28 -> V_79 -> V_714 )
V_108 |= V_715 ;
F_118 ( F_44 ( V_4 ) , V_108 ) ;
F_119 ( F_44 ( V_4 ) ) ;
}
static void F_366 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_6 V_767 = 0x7800 ;
if ( V_28 -> V_79 -> V_714 )
V_767 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_118 ( F_525 ( V_4 ) , V_767 << 16 ) ;
F_118 ( F_526 ( V_4 ) , 0 ) ;
F_118 ( F_527 ( V_4 ) , V_767 ) ;
F_118 ( F_528 ( V_4 ) , 0 ) ;
F_118 ( F_529 ( V_4 ) , 0 ) ;
F_118 ( F_530 ( V_4 ) , V_767 << 16 ) ;
F_118 ( F_531 ( V_4 ) , 0 ) ;
F_118 ( F_532 ( V_4 ) , 0 ) ;
F_118 ( F_533 ( V_4 ) , 0 ) ;
if ( F_43 ( V_10 ) -> V_91 > 6 ) {
T_6 V_768 = 0 ;
if ( V_28 -> V_79 -> V_714 )
V_768 = ( 16 * ( 1 << 12 ) / 255 ) & 0x1fff ;
F_118 ( F_534 ( V_4 ) , V_768 ) ;
F_118 ( F_535 ( V_4 ) , V_768 ) ;
F_118 ( F_536 ( V_4 ) , V_768 ) ;
F_118 ( F_537 ( V_4 ) , 0 ) ;
} else {
T_4 V_445 = V_769 ;
if ( V_28 -> V_79 -> V_714 )
V_445 |= V_770 ;
F_118 ( F_537 ( V_4 ) , V_445 ) ;
}
}
static void F_365 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
enum V_82 V_84 = V_28 -> V_79 -> V_84 ;
T_4 V_108 ;
V_108 = 0 ;
if ( F_218 ( V_10 ) && V_28 -> V_79 -> V_704 )
V_108 |= ( V_705 | V_706 ) ;
if ( V_28 -> V_79 -> V_8 . V_80 . V_446 & V_688 )
V_108 |= V_236 ;
else
V_108 |= V_713 ;
F_118 ( F_44 ( V_84 ) , V_108 ) ;
F_119 ( F_44 ( V_84 ) ) ;
F_118 ( F_341 ( V_28 -> V_4 ) , V_771 ) ;
F_119 ( F_341 ( V_28 -> V_4 ) ) ;
if ( F_168 ( V_10 ) || F_43 ( V_10 ) -> V_91 >= 9 ) {
V_108 = 0 ;
switch ( V_28 -> V_79 -> V_569 ) {
case 18 :
V_108 |= V_772 ;
break;
case 24 :
V_108 |= V_773 ;
break;
case 30 :
V_108 |= V_774 ;
break;
case 36 :
V_108 |= V_775 ;
break;
default:
F_136 () ;
}
if ( V_28 -> V_79 -> V_704 )
V_108 |= V_776 | V_777 ;
F_118 ( F_538 ( V_4 ) , V_108 ) ;
}
}
static bool F_539 ( struct V_75 * V_29 ,
struct V_198 * V_452 ,
T_2 * clock ,
bool * V_717 ,
T_2 * V_617 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_18 ;
const T_3 * V_32 ;
bool V_266 , V_718 = false ;
V_718 = F_12 ( V_28 , V_33 ) ;
V_18 = F_524 ( V_29 ) ;
V_32 = F_17 ( V_28 , V_18 ) ;
V_266 = V_12 -> V_252 . V_720 ( V_32 , V_28 ,
V_452 -> V_650 ,
V_18 , NULL , clock ) ;
if ( ! V_266 )
return false ;
if ( V_718 && V_12 -> V_721 ) {
* V_717 =
V_12 -> V_252 . V_720 ( V_32 , V_28 ,
V_12 -> V_722 ,
V_18 , clock ,
V_617 ) ;
}
return true ;
}
int F_441 ( int V_778 , int V_565 , int V_779 )
{
T_1 V_780 = V_778 * V_779 * 21 / 20 ;
return F_397 ( V_780 , V_565 * 8 ) ;
}
static bool F_540 ( struct V_56 * V_56 , int V_781 )
{
return F_24 ( V_56 ) < V_781 * V_56 -> V_25 ;
}
static T_4 F_541 ( struct V_28 * V_28 ,
struct V_198 * V_452 ,
T_1 * V_618 ,
T_2 * V_617 , T_1 * V_619 )
{
struct V_75 * V_29 = & V_28 -> V_8 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 ;
T_4 V_56 ;
int V_781 , V_615 = 0 ;
bool V_718 = false , V_666 = false ;
F_13 (dev, intel_encoder) {
if ( V_1 -> V_31 != F_37 ( V_29 ) )
continue;
switch ( V_1 -> type ) {
case V_33 :
V_718 = true ;
break;
case V_44 :
case V_41 :
V_666 = true ;
break;
default:
break;
}
V_615 ++ ;
}
V_781 = 21 ;
if ( V_718 ) {
if ( ( F_459 ( V_12 ) &&
V_12 -> V_612 . V_616 == 100000 ) ||
( F_48 ( V_10 ) && F_15 ( V_10 ) ) )
V_781 = 25 ;
} else if ( V_452 -> V_679 )
V_781 = 20 ;
if ( F_540 ( & V_452 -> V_56 , V_781 ) )
* V_618 |= V_782 ;
if ( V_619 && ( V_617 -> V_19 < V_781 * V_617 -> V_25 ) )
* V_619 |= V_782 ;
V_56 = 0 ;
if ( V_718 )
V_56 |= V_667 ;
else
V_56 |= V_668 ;
V_56 |= ( V_452 -> V_488 - 1 )
<< V_783 ;
if ( V_666 )
V_56 |= V_670 ;
if ( V_452 -> V_439 )
V_56 |= V_670 ;
V_56 |= ( 1 << ( V_452 -> V_56 . V_23 - 1 ) ) << V_672 ;
V_56 |= ( 1 << ( V_452 -> V_56 . V_23 - 1 ) ) << V_673 ;
switch ( V_452 -> V_56 . V_24 ) {
case 5 :
V_56 |= V_674 ;
break;
case 7 :
V_56 |= V_675 ;
break;
case 10 :
V_56 |= V_676 ;
break;
case 14 :
V_56 |= V_677 ;
break;
}
if ( V_718 && F_459 ( V_12 ) && V_615 < 2 )
V_56 |= V_681 ;
else
V_56 |= V_682 ;
return V_56 | V_110 ;
}
static int F_542 ( struct V_28 * V_29 ,
struct V_198 * V_452 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock , V_617 ;
T_1 V_56 = 0 , V_618 = 0 , V_619 = 0 ;
bool V_716 , V_717 = false ;
bool V_718 = false ;
struct V_114 * V_117 ;
V_718 = F_10 ( V_29 , V_33 ) ;
F_46 ( ! ( F_48 ( V_10 ) || F_94 ( V_10 ) ) ,
L_111 , F_543 ( V_10 ) ) ;
V_716 = F_539 ( & V_29 -> V_8 , V_452 , & clock ,
& V_717 , & V_617 ) ;
if ( ! V_716 && ! V_452 -> V_719 ) {
F_121 ( L_100 ) ;
return - V_272 ;
}
if ( ! V_452 -> V_719 ) {
V_452 -> V_56 . V_25 = clock . V_25 ;
V_452 -> V_56 . V_20 = clock . V_20 ;
V_452 -> V_56 . V_21 = clock . V_21 ;
V_452 -> V_56 . V_23 = clock . V_23 ;
V_452 -> V_56 . V_24 = clock . V_24 ;
}
if ( V_452 -> V_247 ) {
V_618 = F_462 ( & V_452 -> V_56 ) ;
if ( V_717 )
V_619 = F_462 ( & V_617 ) ;
V_56 = F_541 ( V_29 , V_452 ,
& V_618 , & V_617 ,
V_717 ? & V_619 : NULL ) ;
V_452 -> V_200 . V_56 = V_56 ;
V_452 -> V_200 . V_551 = V_618 ;
if ( V_717 )
V_452 -> V_200 . V_552 = V_619 ;
else
V_452 -> V_200 . V_552 = V_618 ;
V_117 = F_315 ( V_29 , V_452 ) ;
if ( V_117 == NULL ) {
F_139 ( L_112 ,
F_69 ( V_29 -> V_4 ) ) ;
return - V_272 ;
}
}
if ( V_718 && V_717 && V_362 . V_621 )
V_29 -> V_620 = true ;
else
V_29 -> V_620 = false ;
return 0 ;
}
static void F_544 ( struct V_28 * V_29 ,
struct V_604 * V_605 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
V_605 -> V_609 = F_5 ( F_470 ( V_4 ) ) ;
V_605 -> V_610 = F_5 ( F_471 ( V_4 ) ) ;
V_605 -> V_607 = F_5 ( F_467 ( V_4 ) )
& ~ V_434 ;
V_605 -> V_608 = F_5 ( F_469 ( V_4 ) ) ;
V_605 -> V_606 = ( ( F_5 ( F_467 ( V_4 ) )
& V_434 ) >> V_784 ) + 1 ;
}
static void F_545 ( struct V_28 * V_29 ,
enum V_82 V_82 ,
struct V_604 * V_605 ,
struct V_604 * V_624 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
if ( F_43 ( V_10 ) -> V_91 >= 5 ) {
V_605 -> V_609 = F_5 ( F_473 ( V_82 ) ) ;
V_605 -> V_610 = F_5 ( F_474 ( V_82 ) ) ;
V_605 -> V_607 = F_5 ( F_309 ( V_82 ) )
& ~ V_434 ;
V_605 -> V_608 = F_5 ( F_472 ( V_82 ) ) ;
V_605 -> V_606 = ( ( F_5 ( F_309 ( V_82 ) )
& V_434 ) >> V_784 ) + 1 ;
if ( V_624 && F_43 ( V_10 ) -> V_91 < 8 &&
V_29 -> V_79 -> V_625 ) {
V_624 -> V_609 = F_5 ( F_477 ( V_82 ) ) ;
V_624 -> V_610 = F_5 ( F_478 ( V_82 ) ) ;
V_624 -> V_607 = F_5 ( F_475 ( V_82 ) )
& ~ V_434 ;
V_624 -> V_608 = F_5 ( F_476 ( V_82 ) ) ;
V_624 -> V_606 = ( ( F_5 ( F_475 ( V_82 ) )
& V_434 ) >> V_784 ) + 1 ;
}
} else {
V_605 -> V_609 = F_5 ( F_481 ( V_4 ) ) ;
V_605 -> V_610 = F_5 ( F_482 ( V_4 ) ) ;
V_605 -> V_607 = F_5 ( F_479 ( V_4 ) )
& ~ V_434 ;
V_605 -> V_608 = F_5 ( F_480 ( V_4 ) ) ;
V_605 -> V_606 = ( ( F_5 ( F_479 ( V_4 ) )
& V_434 ) >> V_784 ) + 1 ;
}
}
void F_546 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
if ( V_199 -> V_247 )
F_544 ( V_29 , & V_199 -> V_626 ) ;
else
F_545 ( V_29 , V_199 -> V_84 ,
& V_199 -> V_626 ,
& V_199 -> V_627 ) ;
}
static void F_547 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
F_545 ( V_29 , V_199 -> V_84 ,
& V_199 -> V_483 , NULL ) ;
}
static void F_548 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_204 ;
V_204 = F_5 ( F_322 ( V_29 -> V_4 ) ) ;
if ( V_204 & V_461 ) {
V_199 -> V_366 . V_106 = true ;
V_199 -> V_366 . V_462 = F_5 ( F_323 ( V_29 -> V_4 ) ) ;
V_199 -> V_366 . V_311 = F_5 ( F_324 ( V_29 -> V_4 ) ) ;
}
}
static void
F_549 ( struct V_28 * V_29 ,
struct V_304 * V_305 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_108 , V_8 , V_281 , V_785 ;
int V_4 = V_29 -> V_4 ;
int V_727 , V_314 ;
int V_728 ;
struct V_260 * V_78 ;
struct V_338 * V_339 ;
V_339 = F_512 ( sizeof( * V_339 ) , V_457 ) ;
if ( ! V_339 ) {
F_142 ( L_101 ) ;
return;
}
V_78 = & V_339 -> V_8 ;
V_108 = F_5 ( F_84 ( V_4 , 0 ) ) ;
if ( ! ( V_108 & V_158 ) )
goto error;
if ( V_108 & V_786 )
V_305 -> V_258 = V_270 ;
V_314 = V_108 & V_787 ;
V_727 = F_190 ( V_314 ,
V_108 & V_344 ,
V_108 & V_788 ) ;
V_78 -> V_314 = V_727 ;
V_78 -> V_600 = F_207 ( V_727 , 0 ) * 8 ;
V_8 = F_5 ( F_221 ( V_4 , 0 ) ) & 0xfffff000 ;
V_305 -> V_8 = V_8 ;
V_281 = F_5 ( F_223 ( V_4 , 0 ) ) ;
V_108 = F_5 ( F_224 ( V_4 , 0 ) ) ;
V_78 -> V_257 = ( ( V_108 >> 16 ) & 0xfff ) + 1 ;
V_78 -> V_315 = ( ( V_108 >> 0 ) & 0x1fff ) + 1 ;
V_108 = F_5 ( F_225 ( V_4 , 0 ) ) ;
switch ( V_305 -> V_258 ) {
case V_269 :
V_785 = 64 ;
break;
case V_270 :
V_785 = 512 ;
break;
default:
F_405 ( V_305 -> V_258 ) ;
goto error;
}
V_78 -> V_313 [ 0 ] = ( V_108 & 0x3ff ) * V_785 ;
V_728 = F_173 ( V_10 , V_78 -> V_257 ,
V_305 -> V_258 ) ;
V_305 -> V_311 = V_78 -> V_313 [ 0 ] * V_728 ;
F_142 ( L_113 ,
F_69 ( V_4 ) , V_78 -> V_315 , V_78 -> V_257 ,
V_78 -> V_600 , V_8 , V_78 -> V_313 [ 0 ] ,
V_305 -> V_311 ) ;
V_29 -> V_8 . V_77 -> V_78 = V_78 ;
return;
error:
F_202 ( V_78 ) ;
}
static void F_550 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_204 ;
V_204 = F_5 ( F_252 ( V_29 -> V_4 ) ) ;
if ( V_204 & V_463 ) {
V_199 -> V_366 . V_106 = true ;
V_199 -> V_366 . V_462 = F_5 ( F_253 ( V_29 -> V_4 ) ) ;
V_199 -> V_366 . V_311 = F_5 ( F_254 ( V_29 -> V_4 ) ) ;
if ( F_551 ( V_10 ) ) {
F_3 ( ( V_204 & V_789 ) !=
F_326 ( V_29 -> V_4 ) ) ;
}
}
}
static void
F_552 ( struct V_28 * V_29 ,
struct V_304 * V_305 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_108 , V_8 , V_281 ;
int V_4 = V_29 -> V_4 ;
int V_727 , V_314 ;
int V_728 ;
struct V_260 * V_78 ;
struct V_338 * V_339 ;
V_108 = F_5 ( F_78 ( V_4 ) ) ;
if ( ! ( V_108 & V_152 ) )
return;
V_339 = F_512 ( sizeof( * V_339 ) , V_457 ) ;
if ( ! V_339 ) {
F_142 ( L_101 ) ;
return;
}
V_78 = & V_339 -> V_8 ;
if ( F_43 ( V_10 ) -> V_91 >= 4 )
if ( V_108 & V_331 )
V_305 -> V_258 = V_270 ;
V_314 = V_108 & V_729 ;
V_727 = F_189 ( V_314 ) ;
V_78 -> V_314 = V_727 ;
V_78 -> V_600 = F_207 ( V_727 , 0 ) * 8 ;
V_8 = F_5 ( F_164 ( V_4 ) ) & 0xfffff000 ;
if ( F_218 ( V_10 ) || F_168 ( V_10 ) ) {
V_281 = F_5 ( F_219 ( V_4 ) ) ;
} else {
if ( V_305 -> V_258 )
V_281 = F_5 ( F_215 ( V_4 ) ) ;
else
V_281 = F_5 ( F_216 ( V_4 ) ) ;
}
V_305 -> V_8 = V_8 ;
V_108 = F_5 ( F_251 ( V_4 ) ) ;
V_78 -> V_315 = ( ( V_108 >> 16 ) & 0xfff ) + 1 ;
V_78 -> V_257 = ( ( V_108 >> 0 ) & 0xfff ) + 1 ;
V_108 = F_5 ( F_214 ( V_4 ) ) ;
V_78 -> V_313 [ 0 ] = V_108 & 0xffffffc0 ;
V_728 = F_173 ( V_10 , V_78 -> V_257 ,
V_305 -> V_258 ) ;
V_305 -> V_311 = V_78 -> V_313 [ 0 ] * V_728 ;
F_142 ( L_113 ,
F_69 ( V_4 ) , V_78 -> V_315 , V_78 -> V_257 ,
V_78 -> V_600 , V_8 , V_78 -> V_313 [ 0 ] ,
V_305 -> V_311 ) ;
V_29 -> V_8 . V_77 -> V_78 = V_78 ;
}
static bool F_553 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_204 ;
if ( ! F_75 ( V_12 ,
F_390 ( V_29 -> V_4 ) ) )
return false ;
V_199 -> V_84 = (enum V_82 ) V_29 -> V_4 ;
V_199 -> V_115 = V_451 ;
V_204 = F_5 ( F_44 ( V_29 -> V_4 ) ) ;
if ( ! ( V_204 & V_150 ) )
return false ;
switch ( V_204 & V_233 ) {
case V_707 :
V_199 -> V_569 = 18 ;
break;
case V_708 :
V_199 -> V_569 = 24 ;
break;
case V_709 :
V_199 -> V_569 = 30 ;
break;
case V_766 :
V_199 -> V_569 = 36 ;
break;
default:
break;
}
if ( V_204 & V_715 )
V_199 -> V_714 = true ;
if ( F_5 ( F_96 ( V_29 -> V_4 ) ) & V_166 ) {
struct V_114 * V_117 ;
V_199 -> V_247 = true ;
V_204 = F_5 ( F_64 ( V_29 -> V_4 ) ) ;
V_199 -> V_386 = ( ( V_385 & V_204 ) >>
V_790 ) + 1 ;
F_547 ( V_29 , V_199 ) ;
if ( F_48 ( V_12 -> V_10 ) ) {
V_199 -> V_115 =
(enum V_453 ) V_29 -> V_4 ;
} else {
V_204 = F_5 ( V_437 ) ;
if ( V_204 & F_311 ( V_29 -> V_4 ) )
V_199 -> V_115 = V_438 ;
else
V_199 -> V_115 = V_791 ;
}
V_117 = & V_12 -> V_116 [ V_199 -> V_115 ] ;
F_3 ( ! V_117 -> V_120 ( V_12 , V_117 ,
& V_199 -> V_200 ) ) ;
V_204 = V_199 -> V_200 . V_56 ;
V_199 -> V_488 =
( ( V_204 & V_792 )
>> V_783 ) + 1 ;
F_554 ( V_29 , V_199 ) ;
} else {
V_199 -> V_488 = 1 ;
}
F_505 ( V_29 , V_199 ) ;
F_550 ( V_29 , V_199 ) ;
return true ;
}
static void F_555 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_28 * V_29 ;
F_129 (dev, crtc)
F_52 ( V_29 -> V_76 , L_114 ,
F_69 ( V_29 -> V_4 ) ) ;
F_52 ( F_5 ( V_793 ) , L_115 ) ;
F_52 ( F_5 ( V_794 ) & V_795 , L_116 ) ;
F_52 ( F_5 ( V_796 ) & V_797 , L_117 ) ;
F_52 ( F_5 ( V_798 ) & V_797 , L_118 ) ;
F_52 ( F_5 ( V_799 ) & V_800 , L_119 ) ;
F_52 ( F_5 ( V_801 ) & V_802 ,
L_120 ) ;
if ( F_218 ( V_10 ) )
F_52 ( F_5 ( V_803 ) & V_802 ,
L_121 ) ;
F_52 ( F_5 ( V_804 ) & V_805 ,
L_122 ) ;
F_52 ( F_5 ( V_806 ) & V_807 ,
L_123 ) ;
F_52 ( F_5 ( V_808 ) & V_809 , L_124 ) ;
F_52 ( F_556 ( V_12 ) , L_125 ) ;
}
static T_4 F_557 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
if ( F_218 ( V_10 ) )
return F_5 ( V_810 ) ;
else
return F_5 ( V_811 ) ;
}
static void F_558 ( struct V_11 * V_12 , T_4 V_108 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
if ( F_218 ( V_10 ) ) {
F_54 ( & V_12 -> V_469 . V_470 ) ;
if ( F_334 ( V_12 , V_812 ,
V_108 ) )
F_121 ( L_126 ) ;
F_56 ( & V_12 -> V_469 . V_470 ) ;
} else {
F_118 ( V_811 , V_108 ) ;
F_119 ( V_811 ) ;
}
}
static void F_559 ( struct V_11 * V_12 ,
bool V_813 , bool V_814 )
{
T_4 V_108 ;
F_555 ( V_12 ) ;
V_108 = F_5 ( V_815 ) ;
if ( V_813 ) {
V_108 |= V_816 ;
F_118 ( V_815 , V_108 ) ;
if ( F_518 ( F_5 ( V_815 ) &
V_817 , 1 ) )
F_121 ( L_127 ) ;
V_108 = F_5 ( V_815 ) ;
}
V_108 |= V_818 ;
F_118 ( V_815 , V_108 ) ;
F_119 ( V_815 ) ;
if ( F_45 ( ( F_5 ( V_815 ) & V_819 ) == 0 , 1 ) )
F_121 ( L_128 ) ;
V_108 = F_557 ( V_12 ) ;
V_108 |= V_820 ;
F_558 ( V_12 , V_108 ) ;
F_560 ( 100 ) ;
if ( F_45 ( ( F_557 ( V_12 ) & V_821 ) == 0 ,
1 ) )
F_121 ( L_129 ) ;
if ( V_814 ) {
V_108 = F_5 ( V_815 ) ;
V_108 |= V_822 ;
F_118 ( V_815 , V_108 ) ;
F_119 ( V_815 ) ;
}
}
static void F_561 ( struct V_11 * V_12 )
{
T_4 V_108 ;
V_108 = F_5 ( V_815 ) ;
if ( ( V_108 & ( V_819 | V_818 | V_816 |
V_822 ) ) == V_819 )
return;
F_562 ( V_12 , V_823 ) ;
if ( V_108 & V_822 ) {
V_108 &= ~ V_822 ;
F_118 ( V_815 , V_108 ) ;
F_119 ( V_815 ) ;
}
V_108 = F_557 ( V_12 ) ;
V_108 |= V_824 ;
V_108 &= ~ V_820 ;
F_558 ( V_12 , V_108 ) ;
V_108 = F_5 ( V_815 ) ;
V_108 &= ~ V_818 ;
F_118 ( V_815 , V_108 ) ;
if ( F_45 ( F_5 ( V_815 ) & V_819 , 5 ) )
F_121 ( L_130 ) ;
if ( V_108 & V_816 ) {
V_108 = F_5 ( V_815 ) ;
V_108 &= ~ V_816 ;
F_118 ( V_815 , V_108 ) ;
if ( F_518 ( ( F_5 ( V_815 ) &
V_817 ) == 0 , 1 ) )
F_121 ( L_131 ) ;
}
F_563 ( V_12 , V_823 ) ;
}
void F_564 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_108 ;
F_142 ( L_132 ) ;
if ( V_12 -> V_758 == V_759 ) {
V_108 = F_5 ( V_825 ) ;
V_108 &= ~ V_826 ;
F_118 ( V_825 , V_108 ) ;
}
F_521 ( V_10 ) ;
F_559 ( V_12 , true , true ) ;
}
void F_565 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_108 ;
F_142 ( L_133 ) ;
F_561 ( V_12 ) ;
F_522 ( V_10 ) ;
if ( V_12 -> V_758 == V_759 ) {
V_108 = F_5 ( V_825 ) ;
V_108 |= V_826 ;
F_118 ( V_825 , V_108 ) ;
}
F_566 ( V_10 ) ;
}
static int F_567 ( struct V_28 * V_29 ,
struct V_198 * V_452 )
{
if ( ! F_568 ( V_29 , V_452 ) )
return - V_272 ;
V_29 -> V_620 = false ;
return 0 ;
}
static void F_569 ( struct V_11 * V_12 ,
enum V_94 V_94 ,
struct V_198 * V_199 )
{
T_1 V_368 , V_827 ;
V_368 = F_5 ( V_828 ) & F_570 ( V_94 ) ;
V_199 -> V_829 = V_368 >> ( V_94 * 3 + 1 ) ;
switch ( V_199 -> V_829 ) {
case V_830 :
V_827 = F_5 ( V_831 ) ;
V_199 -> V_200 . V_832 = V_827 & 0x3f ;
break;
case V_833 :
V_199 -> V_115 = V_834 ;
break;
case V_835 :
V_199 -> V_115 = V_836 ;
break;
case V_837 :
V_199 -> V_115 = V_838 ;
break;
}
}
static void F_571 ( struct V_11 * V_12 ,
enum V_94 V_94 ,
struct V_198 * V_199 )
{
V_199 -> V_829 = F_5 ( F_572 ( V_94 ) ) ;
switch ( V_199 -> V_829 ) {
case V_839 :
V_199 -> V_115 = V_840 ;
break;
case V_841 :
V_199 -> V_115 = V_842 ;
break;
}
}
static void F_573 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_114 * V_117 ;
enum V_94 V_94 ;
T_4 V_204 ;
V_204 = F_5 ( F_61 ( V_199 -> V_84 ) ) ;
V_94 = ( V_204 & V_843 ) >> V_844 ;
if ( F_368 ( V_10 ) )
F_569 ( V_12 , V_94 , V_199 ) ;
else
F_571 ( V_12 , V_94 , V_199 ) ;
if ( V_199 -> V_115 >= 0 ) {
V_117 = & V_12 -> V_116 [ V_199 -> V_115 ] ;
F_3 ( ! V_117 -> V_120 ( V_12 , V_117 ,
& V_199 -> V_200 ) ) ;
}
if ( F_43 ( V_10 ) -> V_91 < 9 &&
( V_94 == V_845 ) && F_5 ( V_244 ) & V_166 ) {
V_199 -> V_247 = true ;
V_204 = F_5 ( F_64 ( V_129 ) ) ;
V_199 -> V_386 = ( ( V_385 & V_204 ) >>
V_790 ) + 1 ;
F_547 ( V_29 , V_199 ) ;
}
}
static bool F_574 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_498 V_846 ;
T_4 V_204 ;
if ( ! F_75 ( V_12 ,
F_390 ( V_29 -> V_4 ) ) )
return false ;
V_199 -> V_84 = (enum V_82 ) V_29 -> V_4 ;
V_199 -> V_115 = V_451 ;
V_204 = F_5 ( F_61 ( V_487 ) ) ;
if ( V_204 & V_122 ) {
enum V_4 V_847 ;
switch ( V_204 & V_848 ) {
default:
F_46 ( 1 , L_134 ) ;
case V_849 :
case V_850 :
V_847 = V_129 ;
break;
case V_851 :
V_847 = V_138 ;
break;
case V_852 :
V_847 = V_379 ;
break;
}
if ( V_847 == V_29 -> V_4 )
V_199 -> V_84 = V_487 ;
}
if ( ! F_75 ( V_12 ,
F_76 ( V_199 -> V_84 ) ) )
return false ;
V_204 = F_5 ( F_44 ( V_199 -> V_84 ) ) ;
if ( ! ( V_204 & V_150 ) )
return false ;
F_573 ( V_29 , V_199 ) ;
F_505 ( V_29 , V_199 ) ;
V_846 = F_391 ( V_29 -> V_4 ) ;
if ( F_75 ( V_12 , V_846 ) ) {
if ( F_368 ( V_10 ) )
F_548 ( V_29 , V_199 ) ;
else
F_550 ( V_29 , V_199 ) ;
}
if ( F_218 ( V_10 ) )
V_199 -> V_468 = F_360 ( V_29 ) &&
( F_5 ( V_472 ) & V_473 ) ;
if ( V_199 -> V_84 != V_487 ) {
V_199 -> V_488 =
F_5 ( F_364 ( V_199 -> V_84 ) ) + 1 ;
} else {
V_199 -> V_488 = 1 ;
}
return true ;
}
static void F_575 ( struct V_75 * V_29 , T_1 V_8 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_4 V_853 = 0 , V_311 = 0 ;
if ( V_8 ) {
unsigned int V_315 = V_28 -> V_854 ;
unsigned int V_257 = V_28 -> V_855 ;
unsigned int V_312 = F_576 ( V_315 ) * 4 ;
switch ( V_312 ) {
default:
F_282 ( 1 , L_135 ,
V_315 , V_312 ) ;
V_312 = 256 ;
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
}
V_853 |= V_145 |
V_856 |
V_857 |
F_577 ( V_312 ) ;
V_311 = ( V_257 << 12 ) | V_315 ;
}
if ( V_28 -> V_858 != 0 &&
( V_28 -> V_859 != V_8 ||
V_28 -> V_860 != V_311 ||
V_28 -> V_858 != V_853 ) ) {
F_118 ( V_144 , 0 ) ;
F_119 ( V_144 ) ;
V_28 -> V_858 = 0 ;
}
if ( V_28 -> V_859 != V_8 ) {
F_118 ( V_861 , V_8 ) ;
V_28 -> V_859 = V_8 ;
}
if ( V_28 -> V_860 != V_311 ) {
F_118 ( V_862 , V_311 ) ;
V_28 -> V_860 = V_311 ;
}
if ( V_28 -> V_858 != V_853 ) {
F_118 ( V_144 , V_853 ) ;
F_119 ( V_144 ) ;
V_28 -> V_858 = V_853 ;
}
}
static void F_578 ( struct V_75 * V_29 , T_1 V_8 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_4 V_853 ;
V_853 = 0 ;
if ( V_8 ) {
V_853 = V_863 ;
switch ( V_28 -> V_854 ) {
case 64 :
V_853 |= V_864 ;
break;
case 128 :
V_853 |= V_865 ;
break;
case 256 :
V_853 |= V_866 ;
break;
default:
F_405 ( V_28 -> V_854 ) ;
return;
}
V_853 |= V_4 << 28 ;
if ( F_218 ( V_10 ) || F_168 ( V_10 ) )
V_853 |= V_867 ;
}
if ( V_29 -> V_868 -> V_107 -> V_334 == F_213 ( V_335 ) )
V_853 |= V_869 ;
if ( V_28 -> V_858 != V_853 ) {
F_118 ( F_73 ( V_4 ) , V_853 ) ;
F_119 ( F_73 ( V_4 ) ) ;
V_28 -> V_858 = V_853 ;
}
F_118 ( F_579 ( V_4 ) , V_8 ) ;
F_119 ( F_579 ( V_4 ) ) ;
V_28 -> V_859 = V_8 ;
}
static void F_345 ( struct V_75 * V_29 ,
bool V_225 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
int V_254 = V_29 -> V_870 ;
int V_255 = V_29 -> V_871 ;
T_1 V_8 = 0 , V_462 = 0 ;
if ( V_225 )
V_8 = V_28 -> V_872 ;
if ( V_254 >= V_28 -> V_79 -> V_326 )
V_8 = 0 ;
if ( V_255 >= V_28 -> V_79 -> V_325 )
V_8 = 0 ;
if ( V_254 < 0 ) {
if ( V_254 + V_28 -> V_854 <= 0 )
V_8 = 0 ;
V_462 |= V_873 << V_874 ;
V_254 = - V_254 ;
}
V_462 |= V_254 << V_874 ;
if ( V_255 < 0 ) {
if ( V_255 + V_28 -> V_855 <= 0 )
V_8 = 0 ;
V_462 |= V_873 << V_875 ;
V_255 = - V_255 ;
}
V_462 |= V_255 << V_875 ;
if ( V_8 == 0 && V_28 -> V_859 == 0 )
return;
F_118 ( F_580 ( V_4 ) , V_462 ) ;
if ( F_339 ( V_10 ) &&
V_29 -> V_868 -> V_107 -> V_334 == F_213 ( V_335 ) ) {
V_8 += ( V_28 -> V_855 *
V_28 -> V_854 - 1 ) * 4 ;
}
if ( F_71 ( V_10 ) || F_72 ( V_10 ) )
F_575 ( V_29 , V_8 ) ;
else
F_578 ( V_29 , V_8 ) ;
}
static bool F_581 ( struct V_9 * V_10 ,
T_4 V_315 , T_4 V_257 )
{
if ( V_315 == 0 || V_257 == 0 )
return false ;
if ( F_71 ( V_10 ) || F_72 ( V_10 ) ) {
if ( ( V_315 & 63 ) != 0 )
return false ;
if ( V_315 > ( F_71 ( V_10 ) ? 64 : 512 ) )
return false ;
if ( V_257 > 1023 )
return false ;
} else {
switch ( V_315 | V_257 ) {
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
static void F_582 ( struct V_75 * V_29 , T_5 * V_876 , T_5 * V_877 ,
T_5 * V_878 , T_4 V_879 , T_4 V_311 )
{
int V_880 = ( V_879 + V_311 > 256 ) ? 256 : V_879 + V_311 , V_153 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
for ( V_153 = V_879 ; V_153 < V_880 ; V_153 ++ ) {
V_28 -> V_478 [ V_153 ] = V_876 [ V_153 ] >> 8 ;
V_28 -> V_479 [ V_153 ] = V_877 [ V_153 ] >> 8 ;
V_28 -> V_480 [ V_153 ] = V_878 [ V_153 ] >> 8 ;
}
F_337 ( V_29 ) ;
}
struct V_260 *
F_583 ( struct V_9 * V_10 ,
struct V_306 * V_307 ,
struct V_263 * V_264 )
{
struct V_338 * V_339 ;
int V_266 ;
V_339 = F_512 ( sizeof( * V_339 ) , V_457 ) ;
if ( ! V_339 ) {
F_198 ( & V_264 -> V_8 ) ;
return F_584 ( - V_459 ) ;
}
V_266 = F_195 ( V_10 , V_339 , V_307 , V_264 ) ;
if ( V_266 )
goto V_63;
return & V_339 -> V_8 ;
V_63:
F_198 ( & V_264 -> V_8 ) ;
F_202 ( V_339 ) ;
return F_584 ( V_266 ) ;
}
static struct V_260 *
F_585 ( struct V_9 * V_10 ,
struct V_306 * V_307 ,
struct V_263 * V_264 )
{
struct V_260 * V_78 ;
int V_266 ;
V_266 = F_586 ( V_10 ) ;
if ( V_266 )
return F_584 ( V_266 ) ;
V_78 = F_583 ( V_10 , V_307 , V_264 ) ;
F_56 ( & V_10 -> V_267 ) ;
return V_78 ;
}
static T_1
F_587 ( int V_315 , int V_779 )
{
T_1 V_278 = F_397 ( V_315 * V_779 , 8 ) ;
return F_174 ( V_278 , 64 ) ;
}
static T_1
F_588 ( struct V_361 * V_445 , int V_779 )
{
T_1 V_278 = F_587 ( V_445 -> V_575 , V_779 ) ;
return F_589 ( V_278 * V_445 -> V_697 ) ;
}
static struct V_260 *
F_590 ( struct V_9 * V_10 ,
struct V_361 * V_445 ,
int V_881 , int V_779 )
{
struct V_263 * V_264 ;
struct V_306 V_307 = { 0 } ;
V_264 = F_591 ( V_10 ,
F_588 ( V_445 , V_779 ) ) ;
if ( V_264 == NULL )
return F_584 ( - V_459 ) ;
V_307 . V_315 = V_445 -> V_575 ;
V_307 . V_257 = V_445 -> V_697 ;
V_307 . V_313 [ 0 ] = F_587 ( V_307 . V_315 ,
V_779 ) ;
V_307 . V_314 = F_592 ( V_779 , V_881 ) ;
return F_585 ( V_10 , & V_307 , V_264 ) ;
}
static struct V_260 *
F_593 ( struct V_9 * V_10 ,
struct V_361 * V_445 )
{
#ifdef F_594
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_263 * V_264 ;
struct V_260 * V_78 ;
if ( ! V_12 -> V_882 )
return NULL ;
if ( ! V_12 -> V_882 -> V_78 )
return NULL ;
V_264 = V_12 -> V_882 -> V_78 -> V_264 ;
F_116 ( ! V_264 ) ;
V_78 = & V_12 -> V_882 -> V_78 -> V_8 ;
if ( V_78 -> V_313 [ 0 ] < F_587 ( V_445 -> V_575 ,
V_78 -> V_600 ) )
return NULL ;
if ( V_264 -> V_8 . V_311 < V_445 -> V_697 * V_78 -> V_313 [ 0 ] )
return NULL ;
return V_78 ;
#else
return NULL ;
#endif
}
bool F_595 ( struct V_556 * V_3 ,
struct V_361 * V_445 ,
struct V_883 * V_884 ,
struct V_885 * V_886 )
{
struct V_28 * V_28 ;
struct V_1 * V_1 =
F_596 ( V_3 ) ;
struct V_75 * V_887 ;
struct V_560 * V_6 = & V_1 -> V_8 ;
struct V_75 * V_29 = NULL ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_260 * V_78 ;
struct V_888 * V_79 = & V_10 -> V_889 ;
int V_266 , V_153 = - 1 ;
F_142 ( L_136 ,
V_3 -> V_8 . V_227 , V_3 -> V_121 ,
V_6 -> V_8 . V_227 , V_6 -> V_121 ) ;
V_391:
V_266 = F_231 ( & V_79 -> V_890 , V_886 ) ;
if ( V_266 )
goto V_891;
if ( V_6 -> V_29 ) {
V_29 = V_6 -> V_29 ;
V_266 = F_231 ( & V_29 -> V_350 , V_886 ) ;
if ( V_266 )
goto V_891;
V_266 = F_231 ( & V_29 -> V_77 -> V_350 , V_886 ) ;
if ( V_266 )
goto V_891;
V_884 -> V_892 = V_3 -> V_558 ;
V_884 -> V_893 = false ;
if ( V_3 -> V_558 != V_561 )
V_3 -> V_466 -> V_558 ( V_3 , V_561 ) ;
return true ;
}
F_203 (dev, possible_crtc) {
V_153 ++ ;
if ( ! ( V_6 -> V_894 & ( 1 << V_153 ) ) )
continue;
if ( V_887 -> V_106 )
continue;
if ( F_37 ( V_887 ) -> V_544 )
continue;
V_29 = V_887 ;
break;
}
if ( ! V_29 ) {
F_142 ( L_137 ) ;
goto V_891;
}
V_266 = F_231 ( & V_29 -> V_350 , V_886 ) ;
if ( V_266 )
goto V_891;
V_266 = F_231 ( & V_29 -> V_77 -> V_350 , V_886 ) ;
if ( V_266 )
goto V_891;
V_1 -> V_31 = F_37 ( V_29 ) ;
F_597 ( V_3 ) -> V_895 = V_1 ;
V_28 = F_37 ( V_29 ) ;
V_28 -> V_544 = true ;
V_28 -> V_454 = V_28 -> V_79 ;
V_884 -> V_892 = V_3 -> V_558 ;
V_884 -> V_893 = true ;
V_884 -> V_896 = NULL ;
if ( ! V_445 )
V_445 = & V_897 ;
V_78 = F_593 ( V_10 , V_445 ) ;
if ( V_78 == NULL ) {
F_142 ( L_138 ) ;
V_78 = F_590 ( V_10 , V_445 , 24 , 32 ) ;
V_884 -> V_896 = V_78 ;
} else
F_142 ( L_139 ) ;
if ( F_598 ( V_78 ) ) {
F_142 ( L_140 ) ;
goto V_898;
}
if ( F_599 ( V_29 , V_445 , 0 , 0 , V_78 ) ) {
F_142 ( L_141 ) ;
if ( V_884 -> V_896 )
V_884 -> V_896 -> V_466 -> V_899 ( V_884 -> V_896 ) ;
goto V_898;
}
V_29 -> V_77 -> V_29 = V_29 ;
F_169 ( V_10 , V_28 -> V_4 ) ;
return true ;
V_898:
V_28 -> V_544 = V_29 -> V_106 ;
if ( V_28 -> V_544 )
V_28 -> V_454 = V_28 -> V_79 ;
else
V_28 -> V_454 = NULL ;
V_891:
if ( V_266 == - V_900 ) {
F_600 ( V_886 ) ;
goto V_391;
}
return false ;
}
void F_601 ( struct V_556 * V_3 ,
struct V_883 * V_884 )
{
struct V_1 * V_1 =
F_596 ( V_3 ) ;
struct V_560 * V_6 = & V_1 -> V_8 ;
struct V_75 * V_29 = V_6 -> V_29 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
F_142 ( L_136 ,
V_3 -> V_8 . V_227 , V_3 -> V_121 ,
V_6 -> V_8 . V_227 , V_6 -> V_121 ) ;
if ( V_884 -> V_893 ) {
F_597 ( V_3 ) -> V_895 = NULL ;
V_1 -> V_31 = NULL ;
V_28 -> V_544 = false ;
V_28 -> V_454 = NULL ;
F_599 ( V_29 , NULL , 0 , 0 , NULL ) ;
if ( V_884 -> V_896 ) {
F_602 ( V_884 -> V_896 ) ;
F_603 ( V_884 -> V_896 ) ;
}
return;
}
if ( V_884 -> V_892 != V_561 )
V_3 -> V_466 -> V_558 ( V_3 , V_884 -> V_892 ) ;
}
static int F_604 ( struct V_9 * V_10 ,
const struct V_198 * V_199 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_56 = V_199 -> V_200 . V_56 ;
if ( ( V_56 & V_901 ) == V_681 )
return V_12 -> V_612 . V_616 ;
else if ( F_4 ( V_10 ) )
return 120000 ;
else if ( ! F_22 ( V_10 ) )
return 96000 ;
else
return 48000 ;
}
static void F_515 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_199 -> V_84 ;
T_1 V_56 = V_199 -> V_200 . V_56 ;
T_1 V_618 ;
T_2 clock ;
int V_18 = F_604 ( V_10 , V_199 ) ;
if ( ( V_56 & V_902 ) == 0 )
V_618 = V_199 -> V_200 . V_551 ;
else
V_618 = V_199 -> V_200 . V_552 ;
clock . V_20 = ( V_618 & V_903 ) >> V_904 ;
if ( F_19 ( V_10 ) ) {
clock . V_25 = F_605 ( ( V_618 & V_905 ) >> V_906 ) - 1 ;
clock . V_21 = ( V_618 & V_907 ) >> V_908 ;
} else {
clock . V_25 = ( V_618 & V_909 ) >> V_906 ;
clock . V_21 = ( V_618 & V_910 ) >> V_908 ;
}
if ( ! F_22 ( V_10 ) ) {
if ( F_19 ( V_10 ) )
clock . V_23 = F_605 ( ( V_56 & V_911 ) >>
V_671 ) ;
else
clock . V_23 = F_605 ( ( V_56 & V_912 ) >>
V_672 ) ;
switch ( V_56 & V_913 ) {
case V_668 :
clock . V_24 = V_56 & V_674 ?
5 : 10 ;
break;
case V_667 :
clock . V_24 = V_56 & V_675 ?
7 : 14 ;
break;
default:
F_142 ( L_142
L_143 , ( int ) ( V_56 & V_913 ) ) ;
return;
}
if ( F_19 ( V_10 ) )
F_23 ( V_18 , & clock ) ;
else
F_25 ( V_18 , & clock ) ;
} else {
T_1 V_914 = F_131 ( V_10 ) ? 0 : F_5 ( V_140 ) ;
bool V_718 = ( V_4 == 1 ) && ( V_914 & V_177 ) ;
if ( V_718 ) {
clock . V_23 = F_605 ( ( V_56 & V_915 ) >>
V_672 ) ;
if ( V_914 & V_916 )
clock . V_24 = 7 ;
else
clock . V_24 = 14 ;
} else {
if ( V_56 & V_683 )
clock . V_23 = 2 ;
else {
clock . V_23 = ( ( V_56 & V_917 ) >>
V_672 ) + 2 ;
}
if ( V_56 & V_684 )
clock . V_24 = 4 ;
else
clock . V_24 = 2 ;
}
F_25 ( V_18 , & clock ) ;
}
V_199 -> V_650 = clock . V_27 ;
}
int F_606 ( int V_918 ,
const struct V_604 * V_605 )
{
if ( ! V_605 -> V_610 )
return 0 ;
return F_34 ( ( V_919 ) V_605 -> V_609 * V_918 , V_605 -> V_610 ) ;
}
static void F_554 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
F_515 ( V_29 , V_199 ) ;
V_199 -> V_8 . V_80 . V_81 =
F_606 ( F_6 ( V_10 ) * 10000 ,
& V_199 -> V_483 ) ;
}
struct V_361 * F_607 ( struct V_9 * V_10 ,
struct V_75 * V_29 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_82 V_84 = V_28 -> V_79 -> V_84 ;
struct V_361 * V_445 ;
struct V_198 V_199 ;
int V_920 = F_5 ( F_292 ( V_84 ) ) ;
int V_921 = F_5 ( F_296 ( V_84 ) ) ;
int V_922 = F_5 ( F_298 ( V_84 ) ) ;
int V_923 = F_5 ( F_302 ( V_84 ) ) ;
enum V_4 V_4 = V_28 -> V_4 ;
V_445 = F_512 ( sizeof( * V_445 ) , V_457 ) ;
if ( ! V_445 )
return NULL ;
V_199 . V_84 = (enum V_82 ) V_4 ;
V_199 . V_488 = 1 ;
V_199 . V_200 . V_56 = F_5 ( F_51 ( V_4 ) ) ;
V_199 . V_200 . V_551 = F_5 ( F_418 ( V_4 ) ) ;
V_199 . V_200 . V_552 = F_5 ( F_419 ( V_4 ) ) ;
F_515 ( V_28 , & V_199 ) ;
V_445 -> clock = V_199 . V_650 / V_199 . V_488 ;
V_445 -> V_575 = ( V_920 & 0xffff ) + 1 ;
V_445 -> V_698 = ( ( V_920 & 0xffff0000 ) >> 16 ) + 1 ;
V_445 -> V_574 = ( V_921 & 0xffff ) + 1 ;
V_445 -> V_699 = ( ( V_921 & 0xffff0000 ) >> 16 ) + 1 ;
V_445 -> V_697 = ( V_922 & 0xffff ) + 1 ;
V_445 -> V_700 = ( ( V_922 & 0xffff0000 ) >> 16 ) + 1 ;
V_445 -> V_701 = ( V_923 & 0xffff ) + 1 ;
V_445 -> V_702 = ( ( V_923 & 0xffff0000 ) >> 16 ) + 1 ;
F_608 ( V_445 ) ;
return V_445 ;
}
static void F_609 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
if ( ! F_339 ( V_10 ) )
return;
if ( ! V_12 -> V_721 )
return;
if ( ! F_507 ( V_10 ) && V_28 -> V_620 ) {
int V_4 = V_28 -> V_4 ;
int V_219 = F_51 ( V_4 ) ;
int V_56 ;
F_139 ( L_144 ) ;
F_67 ( V_12 , V_4 ) ;
V_56 = F_5 ( V_219 ) ;
V_56 |= V_902 ;
F_118 ( V_219 , V_56 ) ;
F_169 ( V_10 , V_4 ) ;
V_56 = F_5 ( V_219 ) ;
if ( ! ( V_56 & V_902 ) )
F_139 ( L_145 ) ;
}
}
void F_610 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_12 -> V_273 . V_924 )
return;
F_180 ( V_12 ) ;
F_611 ( V_12 ) ;
V_12 -> V_273 . V_924 = true ;
}
void F_612 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_29 ;
if ( ! V_12 -> V_273 . V_924 )
return;
V_12 -> V_273 . V_924 = false ;
if ( ! V_362 . V_621 )
goto V_925;
F_203 (dev, crtc) {
if ( ! V_29 -> V_77 -> V_78 )
continue;
F_609 ( V_29 ) ;
}
if ( F_43 ( V_10 ) -> V_91 >= 6 )
F_613 ( V_10 -> V_13 ) ;
V_925:
F_184 ( V_12 ) ;
}
static void F_614 ( struct V_28 * V_29 ,
struct V_198 * V_452 )
{
F_202 ( V_29 -> V_79 ) ;
V_29 -> V_79 = V_452 ;
V_29 -> V_8 . V_107 = & V_452 -> V_8 ;
}
static void F_615 ( struct V_75 * V_29 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_407 * V_408 ;
F_240 ( & V_10 -> V_359 ) ;
V_408 = V_28 -> V_360 ;
V_28 -> V_360 = NULL ;
F_241 ( & V_10 -> V_359 ) ;
if ( V_408 ) {
F_616 ( & V_408 -> V_408 ) ;
F_202 ( V_408 ) ;
}
F_614 ( V_28 , NULL ) ;
F_617 ( V_29 ) ;
F_202 ( V_28 ) ;
}
static void F_618 ( struct V_926 * V_927 )
{
struct V_407 * V_408 =
F_619 ( V_927 , struct V_407 , V_408 ) ;
struct V_9 * V_10 = V_408 -> V_29 -> V_10 ;
enum V_4 V_4 = F_37 ( V_408 -> V_29 ) -> V_4 ;
F_54 ( & V_10 -> V_267 ) ;
F_186 ( V_408 -> V_928 ) ;
F_198 ( & V_408 -> V_412 -> V_8 ) ;
F_198 ( & V_408 -> V_928 -> V_8 ) ;
F_346 ( V_10 ) ;
if ( V_408 -> V_929 )
F_620 ( & V_408 -> V_929 , NULL ) ;
F_56 ( & V_10 -> V_267 ) ;
F_621 ( V_10 , F_197 ( V_4 ) ) ;
F_116 ( F_249 ( & F_37 ( V_408 -> V_29 ) -> V_406 ) == 0 ) ;
F_622 ( & F_37 ( V_408 -> V_29 ) -> V_406 ) ;
F_202 ( V_408 ) ;
}
static void F_623 ( struct V_9 * V_10 ,
struct V_75 * V_29 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_407 * V_408 ;
unsigned long V_446 ;
if ( V_28 == NULL )
return;
F_624 ( & V_10 -> V_359 , V_446 ) ;
V_408 = V_28 -> V_360 ;
F_274 () ;
if ( V_408 == NULL || F_249 ( & V_408 -> V_356 ) < V_930 ) {
F_625 ( & V_10 -> V_359 , V_446 ) ;
return;
}
F_273 ( V_28 ) ;
F_625 ( & V_10 -> V_359 , V_446 ) ;
}
void F_626 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_29 = V_12 -> V_83 [ V_4 ] ;
F_623 ( V_10 , V_29 ) ;
}
void F_229 ( struct V_9 * V_10 , int V_151 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_29 = V_12 -> V_931 [ V_151 ] ;
F_623 ( V_10 , V_29 ) ;
}
static bool F_627 ( T_1 V_932 , T_1 V_933 )
{
return ! ( ( V_932 - V_933 ) & 0x80000000 ) ;
}
static bool F_628 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_248 ( & V_12 -> V_357 ) ||
V_29 -> V_358 != F_249 ( & V_12 -> V_357 . V_358 ) )
return true ;
if ( F_43 ( V_10 ) -> V_91 < 5 && ! F_18 ( V_10 ) )
return true ;
return ( F_5 ( F_629 ( V_29 -> V_151 ) ) & ~ 0xfff ) ==
V_29 -> V_360 -> V_934 &&
F_627 ( F_5 ( F_630 ( V_29 -> V_4 ) ) ,
V_29 -> V_360 -> V_935 ) ;
}
void F_228 ( struct V_9 * V_10 , int V_151 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 =
F_37 ( V_12 -> V_931 [ V_151 ] ) ;
unsigned long V_446 ;
F_624 ( & V_10 -> V_359 , V_446 ) ;
if ( V_28 -> V_360 && F_628 ( V_28 ) )
F_631 ( & V_28 -> V_360 -> V_356 ) ;
F_625 ( & V_10 -> V_359 , V_446 ) ;
}
static inline void F_632 ( struct V_28 * V_28 )
{
F_633 () ;
F_634 ( & V_28 -> V_360 -> V_356 , V_936 ) ;
F_633 () ;
}
static int F_635 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_937 ,
T_4 V_446 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_1 V_938 ;
int V_266 ;
V_266 = F_636 ( V_937 , 6 ) ;
if ( V_266 )
return V_266 ;
if ( V_28 -> V_151 )
V_938 = V_939 ;
else
V_938 = V_940 ;
F_637 ( V_937 , V_941 | V_938 ) ;
F_637 ( V_937 , V_942 ) ;
F_637 ( V_937 , V_943 |
F_638 ( V_28 -> V_151 ) ) ;
F_637 ( V_937 , V_78 -> V_313 [ 0 ] ) ;
F_637 ( V_937 , V_28 -> V_360 -> V_934 ) ;
F_637 ( V_937 , 0 ) ;
F_632 ( V_28 ) ;
F_639 ( V_937 ) ;
return 0 ;
}
static int F_640 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_937 ,
T_4 V_446 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_1 V_938 ;
int V_266 ;
V_266 = F_636 ( V_937 , 6 ) ;
if ( V_266 )
return V_266 ;
if ( V_28 -> V_151 )
V_938 = V_939 ;
else
V_938 = V_940 ;
F_637 ( V_937 , V_941 | V_938 ) ;
F_637 ( V_937 , V_942 ) ;
F_637 ( V_937 , V_944 |
F_638 ( V_28 -> V_151 ) ) ;
F_637 ( V_937 , V_78 -> V_313 [ 0 ] ) ;
F_637 ( V_937 , V_28 -> V_360 -> V_934 ) ;
F_637 ( V_937 , V_942 ) ;
F_632 ( V_28 ) ;
F_639 ( V_937 ) ;
return 0 ;
}
static int F_641 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_937 ,
T_4 V_446 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_4 V_945 , V_946 ;
int V_266 ;
V_266 = F_636 ( V_937 , 4 ) ;
if ( V_266 )
return V_266 ;
F_637 ( V_937 , V_943 |
F_638 ( V_28 -> V_151 ) ) ;
F_637 ( V_937 , V_78 -> V_313 [ 0 ] ) ;
F_637 ( V_937 , V_28 -> V_360 -> V_934 |
V_264 -> V_268 ) ;
V_945 = 0 ;
V_946 = F_5 ( F_251 ( V_28 -> V_4 ) ) & 0x0fff0fff ;
F_637 ( V_937 , V_945 | V_946 ) ;
F_632 ( V_28 ) ;
F_639 ( V_937 ) ;
return 0 ;
}
static int F_642 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_937 ,
T_4 V_446 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_4 V_945 , V_946 ;
int V_266 ;
V_266 = F_636 ( V_937 , 4 ) ;
if ( V_266 )
return V_266 ;
F_637 ( V_937 , V_943 |
F_638 ( V_28 -> V_151 ) ) ;
F_637 ( V_937 , V_78 -> V_313 [ 0 ] | V_264 -> V_268 ) ;
F_637 ( V_937 , V_28 -> V_360 -> V_934 ) ;
V_945 = 0 ;
V_946 = F_5 ( F_251 ( V_28 -> V_4 ) ) & 0x0fff0fff ;
F_637 ( V_937 , V_945 | V_946 ) ;
F_632 ( V_28 ) ;
F_639 ( V_937 ) ;
return 0 ;
}
static int F_643 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_937 ,
T_4 V_446 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_4 V_947 = 0 ;
int V_948 , V_266 ;
switch ( V_28 -> V_151 ) {
case V_949 :
V_947 = V_950 ;
break;
case V_327 :
V_947 = V_951 ;
break;
case V_952 :
V_947 = V_953 ;
break;
default:
F_282 ( 1 , L_146 ) ;
return - V_954 ;
}
V_948 = 4 ;
if ( V_937 -> V_227 == V_955 ) {
V_948 += 6 ;
if ( F_644 ( V_10 ) )
V_948 += 2 ;
}
V_266 = F_645 ( V_937 ) ;
if ( V_266 )
return V_266 ;
V_266 = F_636 ( V_937 , V_948 ) ;
if ( V_266 )
return V_266 ;
if ( V_937 -> V_227 == V_955 ) {
F_637 ( V_937 , F_646 ( 1 ) ) ;
F_637 ( V_937 , V_956 ) ;
F_637 ( V_937 , ~ ( V_957 |
V_958 |
V_959 ) ) ;
if ( F_644 ( V_10 ) )
F_637 ( V_937 , F_647 ( 1 ) |
V_960 ) ;
else
F_637 ( V_937 , F_648 ( 1 ) |
V_960 ) ;
F_637 ( V_937 , V_956 ) ;
F_637 ( V_937 , V_937 -> V_961 . V_934 + 256 ) ;
if ( F_644 ( V_10 ) ) {
F_637 ( V_937 , 0 ) ;
F_637 ( V_937 , V_942 ) ;
}
}
F_637 ( V_937 , V_944 | V_947 ) ;
F_637 ( V_937 , ( V_78 -> V_313 [ 0 ] | V_264 -> V_268 ) ) ;
F_637 ( V_937 , V_28 -> V_360 -> V_934 ) ;
F_637 ( V_937 , ( V_942 ) ) ;
F_632 ( V_28 ) ;
F_639 ( V_937 ) ;
return 0 ;
}
static bool F_649 ( struct V_261 * V_937 ,
struct V_263 * V_264 )
{
if ( V_937 == NULL )
return true ;
if ( F_43 ( V_937 -> V_10 ) -> V_91 < 5 )
return false ;
if ( V_362 . F_649 < 0 )
return false ;
else if ( V_362 . F_649 > 0 )
return true ;
else if ( V_362 . V_962 )
return true ;
else
return V_937 != F_650 ( V_264 -> V_963 ) ;
}
static void F_651 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_260 * V_78 = V_28 -> V_8 . V_77 -> V_78 ;
struct V_338 * V_339 = F_196 ( V_78 ) ;
struct V_263 * V_264 = V_339 -> V_264 ;
const enum V_4 V_4 = V_28 -> V_4 ;
T_1 V_964 , V_312 ;
V_964 = F_5 ( F_84 ( V_4 , 0 ) ) ;
V_964 &= ~ V_786 ;
if ( V_264 -> V_268 == V_270 )
V_964 |= V_345 ;
V_312 = V_78 -> V_313 [ 0 ] >> 6 ;
if ( V_264 -> V_268 == V_270 )
V_312 = V_78 -> V_313 [ 0 ] >> 9 ;
F_118 ( F_84 ( V_4 , 0 ) , V_964 ) ;
F_118 ( F_225 ( V_4 , 0 ) , V_312 ) ;
F_118 ( F_221 ( V_4 , 0 ) , V_28 -> V_360 -> V_934 ) ;
F_119 ( F_221 ( V_4 , 0 ) ) ;
}
static void F_652 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_338 * V_339 =
F_196 ( V_28 -> V_8 . V_77 -> V_78 ) ;
struct V_263 * V_264 = V_339 -> V_264 ;
T_1 V_321 ;
T_1 V_85 ;
V_85 = F_78 ( V_28 -> V_151 ) ;
V_321 = F_5 ( V_85 ) ;
if ( V_264 -> V_268 != V_269 )
V_321 |= V_331 ;
else
V_321 &= ~ V_331 ;
F_118 ( V_85 , V_321 ) ;
F_118 ( F_164 ( V_28 -> V_151 ) ,
V_28 -> V_360 -> V_934 ) ;
F_119 ( F_164 ( V_28 -> V_151 ) ) ;
}
static void F_653 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
bool V_965 ;
T_1 V_966 ;
F_632 ( V_28 ) ;
V_965 = F_654 ( V_28 , & V_966 ) ;
if ( F_43 ( V_10 ) -> V_91 >= 9 )
F_651 ( V_28 ) ;
else
F_652 ( V_28 ) ;
if ( V_965 )
F_655 ( V_28 , V_966 ) ;
}
static void F_656 ( struct V_926 * V_408 )
{
struct V_28 * V_29 =
F_619 ( V_408 , struct V_28 , V_967 . V_408 ) ;
struct V_968 * V_967 ;
V_967 = & V_29 -> V_967 ;
if ( V_967 -> V_969 )
F_3 ( F_657 ( V_967 -> V_969 ,
V_29 -> V_358 ,
false , NULL , NULL ) != 0 ) ;
F_653 ( V_29 ) ;
if ( V_967 -> V_969 ) {
F_54 ( & V_29 -> V_8 . V_10 -> V_267 ) ;
F_620 ( & V_967 -> V_969 , NULL ) ;
F_56 ( & V_29 -> V_8 . V_10 -> V_267 ) ;
}
}
static int F_658 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_937 ,
T_4 V_446 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
F_620 ( & V_28 -> V_967 . V_969 ,
V_264 -> V_970 ) ;
F_659 ( & V_28 -> V_967 . V_408 ) ;
return 0 ;
}
static int F_660 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_937 ,
T_4 V_446 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_4 V_151 = 0 , V_312 ;
int V_266 ;
switch( V_28 -> V_4 ) {
case V_129 :
V_151 = V_971 ;
break;
case V_138 :
V_151 = V_972 ;
break;
case V_379 :
V_151 = V_973 ;
break;
default:
F_282 ( 1 , L_146 ) ;
return - V_954 ;
}
switch ( V_264 -> V_268 ) {
case V_269 :
V_312 = V_78 -> V_313 [ 0 ] >> 6 ;
break;
case V_270 :
V_312 = V_78 -> V_313 [ 0 ] >> 9 ;
break;
default:
F_282 ( 1 , L_147 ) ;
return - V_954 ;
}
V_266 = F_636 ( V_937 , 10 ) ;
if ( V_266 )
return V_266 ;
F_637 ( V_937 , F_646 ( 1 ) ) ;
F_637 ( V_937 , V_956 ) ;
F_637 ( V_937 , ~ ( V_957 |
V_958 |
V_959 ) ) ;
F_637 ( V_937 , F_647 ( 1 ) |
V_960 ) ;
F_637 ( V_937 , V_956 ) ;
F_637 ( V_937 , V_937 -> V_961 . V_934 + 256 ) ;
F_637 ( V_937 , 0 ) ;
F_637 ( V_937 , V_944 | V_151 ) ;
F_637 ( V_937 , V_312 << 6 | V_264 -> V_268 ) ;
F_637 ( V_937 , V_28 -> V_360 -> V_934 ) ;
F_632 ( V_28 ) ;
F_639 ( V_937 ) ;
return 0 ;
}
static int F_661 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_937 ,
T_4 V_446 )
{
return - V_954 ;
}
static bool F_662 ( struct V_9 * V_10 ,
struct V_75 * V_29 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_407 * V_408 = V_28 -> V_360 ;
T_1 V_974 ;
if ( F_249 ( & V_408 -> V_356 ) >= V_930 )
return true ;
if ( ! V_408 -> V_975 )
return false ;
if ( V_408 -> V_976 == 0 ) {
if ( V_408 -> V_929 &&
! F_663 ( V_408 -> V_929 , true ) )
return false ;
V_408 -> V_976 = F_664 ( V_10 , V_28 -> V_4 ) ;
}
if ( F_664 ( V_10 , V_28 -> V_4 ) - V_408 -> V_976 < 3 )
return false ;
if ( F_43 ( V_10 ) -> V_91 >= 4 )
V_974 = F_665 ( F_5 ( F_164 ( V_28 -> V_151 ) ) ) ;
else
V_974 = F_5 ( F_165 ( V_28 -> V_151 ) ) ;
return V_974 == V_408 -> V_934 ;
}
void F_666 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_29 = V_12 -> V_83 [ V_4 ] ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
F_3 ( ! F_667 () ) ;
if ( V_29 == NULL )
return;
F_668 ( & V_10 -> V_359 ) ;
if ( V_28 -> V_360 && F_662 ( V_10 , V_29 ) ) {
F_282 ( 1 , L_148 ,
V_28 -> V_360 -> V_977 , F_664 ( V_10 , V_4 ) ) ;
F_273 ( V_28 ) ;
}
F_669 ( & V_10 -> V_359 ) ;
}
static int F_670 ( struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_978 * V_409 ,
T_4 V_979 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_260 * V_354 = V_29 -> V_77 -> V_78 ;
struct V_263 * V_264 = F_176 ( V_78 ) ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_250 * V_77 = V_29 -> V_77 ;
enum V_4 V_4 = V_28 -> V_4 ;
struct V_407 * V_408 ;
struct V_261 * V_937 ;
int V_266 ;
if ( F_3 ( F_176 ( V_354 ) == NULL ) )
return - V_980 ;
if ( V_78 -> V_314 != V_29 -> V_77 -> V_78 -> V_314 )
return - V_272 ;
if ( F_43 ( V_10 ) -> V_91 > 3 &&
( V_78 -> V_981 [ 0 ] != V_29 -> V_77 -> V_78 -> V_981 [ 0 ] ||
V_78 -> V_313 [ 0 ] != V_29 -> V_77 -> V_78 -> V_313 [ 0 ] ) )
return - V_272 ;
if ( F_671 ( & V_12 -> V_357 ) )
goto V_982;
V_408 = F_512 ( sizeof( * V_408 ) , V_457 ) ;
if ( V_408 == NULL )
return - V_459 ;
V_408 -> V_409 = V_409 ;
V_408 -> V_29 = V_29 ;
V_408 -> V_928 = F_176 ( V_354 ) ;
F_672 ( & V_408 -> V_408 , F_618 ) ;
V_266 = F_91 ( V_29 ) ;
if ( V_266 )
goto V_983;
F_240 ( & V_10 -> V_359 ) ;
if ( V_28 -> V_360 ) {
if ( F_662 ( V_10 , V_29 ) ) {
F_139 ( L_149 ) ;
F_273 ( V_28 ) ;
} else {
F_139 ( L_150 ) ;
F_241 ( & V_10 -> V_359 ) ;
F_92 ( V_29 ) ;
F_202 ( V_408 ) ;
return - V_980 ;
}
}
V_28 -> V_360 = V_408 ;
F_241 ( & V_10 -> V_359 ) ;
if ( F_249 ( & V_28 -> V_406 ) >= 2 )
F_673 ( V_12 -> V_411 ) ;
V_266 = F_586 ( V_10 ) ;
if ( V_266 )
goto V_458;
F_674 ( & V_408 -> V_928 -> V_8 ) ;
F_674 ( & V_264 -> V_8 ) ;
V_29 -> V_77 -> V_78 = V_78 ;
F_199 ( V_29 -> V_77 ) ;
V_408 -> V_412 = V_264 ;
F_675 ( & V_28 -> V_406 ) ;
V_28 -> V_358 = F_249 ( & V_12 -> V_357 . V_358 ) ;
if ( F_43 ( V_10 ) -> V_91 >= 5 || F_18 ( V_10 ) )
V_408 -> V_935 = F_5 ( F_630 ( V_4 ) ) + 1 ;
if ( F_21 ( V_10 ) ) {
V_937 = & V_12 -> V_937 [ V_984 ] ;
if ( V_264 -> V_268 != V_408 -> V_928 -> V_268 )
V_937 = NULL ;
} else if ( F_256 ( V_10 ) || F_218 ( V_10 ) ) {
V_937 = & V_12 -> V_937 [ V_984 ] ;
} else if ( F_43 ( V_10 ) -> V_91 >= 7 ) {
V_937 = F_650 ( V_264 -> V_963 ) ;
if ( V_937 == NULL || V_937 -> V_227 != V_955 )
V_937 = & V_12 -> V_937 [ V_984 ] ;
} else {
V_937 = & V_12 -> V_937 [ V_955 ] ;
}
V_266 = F_175 ( V_29 -> V_77 , V_78 , V_937 ) ;
if ( V_266 )
goto V_985;
V_408 -> V_934 =
F_204 ( V_264 ) + V_28 -> V_333 ;
if ( F_649 ( V_937 , V_264 ) ) {
V_266 = F_658 ( V_10 , V_29 , V_78 , V_264 , V_937 ,
V_979 ) ;
if ( V_266 )
goto V_986;
F_620 ( & V_408 -> V_929 ,
V_264 -> V_970 ) ;
} else {
V_266 = V_12 -> V_252 . V_987 ( V_10 , V_29 , V_78 , V_264 , V_937 ,
V_979 ) ;
if ( V_266 )
goto V_986;
F_620 ( & V_408 -> V_929 ,
F_676 ( V_937 ) ) ;
}
V_408 -> V_977 = F_664 ( V_10 , V_28 -> V_4 ) ;
V_408 -> V_975 = true ;
F_677 ( V_408 -> V_928 , V_264 ,
F_197 ( V_4 ) ) ;
F_350 ( V_10 ) ;
F_678 ( V_10 , F_197 ( V_4 ) ) ;
F_56 ( & V_10 -> V_267 ) ;
F_679 ( V_28 -> V_151 , V_264 ) ;
return 0 ;
V_986:
F_186 ( V_264 ) ;
V_985:
F_622 ( & V_28 -> V_406 ) ;
V_29 -> V_77 -> V_78 = V_354 ;
F_199 ( V_29 -> V_77 ) ;
F_198 ( & V_408 -> V_928 -> V_8 ) ;
F_198 ( & V_264 -> V_8 ) ;
F_56 ( & V_10 -> V_267 ) ;
V_458:
F_240 ( & V_10 -> V_359 ) ;
V_28 -> V_360 = NULL ;
F_241 ( & V_10 -> V_359 ) ;
F_92 ( V_29 ) ;
V_983:
F_202 ( V_408 ) ;
if ( V_266 == - V_988 ) {
V_982:
V_266 = F_330 ( V_77 ) ;
if ( V_266 == 0 && V_409 ) {
F_240 ( & V_10 -> V_359 ) ;
F_275 ( V_10 , V_4 , V_409 ) ;
F_241 ( & V_10 -> V_359 ) ;
}
}
return V_266 ;
}
static void F_680 ( struct V_9 * V_10 )
{
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_428 (connector, &dev->mode_config.connector_list,
base.head) {
V_3 -> V_895 =
F_429 ( V_3 -> V_8 . V_6 ) ;
}
F_13 (dev, encoder) {
V_6 -> V_31 =
F_37 ( V_6 -> V_8 . V_29 ) ;
}
F_129 (dev, crtc) {
V_29 -> V_544 = V_29 -> V_8 . V_106 ;
if ( V_29 -> V_544 )
V_29 -> V_454 = V_29 -> V_79 ;
else
V_29 -> V_454 = NULL ;
}
}
static void F_681 ( struct V_9 * V_10 )
{
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_428 (connector, &dev->mode_config.connector_list,
base.head) {
V_3 -> V_8 . V_6 = & V_3 -> V_895 -> V_8 ;
}
F_13 (dev, encoder) {
V_6 -> V_8 . V_29 = & V_6 -> V_31 -> V_8 ;
}
F_129 (dev, crtc) {
V_29 -> V_8 . V_106 = V_29 -> V_544 ;
}
}
static void
F_682 ( struct V_2 * V_3 ,
struct V_198 * V_199 )
{
int V_779 = V_199 -> V_569 ;
F_142 ( L_151 ,
V_3 -> V_8 . V_8 . V_227 ,
V_3 -> V_8 . V_121 ) ;
if ( V_3 -> V_8 . V_989 . V_440 &&
V_3 -> V_8 . V_989 . V_440 * 3 < V_779 ) {
F_142 ( L_152 ,
V_779 , V_3 -> V_8 . V_989 . V_440 * 3 ) ;
V_199 -> V_569 = V_3 -> V_8 . V_989 . V_440 * 3 ;
}
if ( V_3 -> V_8 . V_989 . V_440 == 0 && V_779 > 24 ) {
F_142 ( L_153 ,
V_779 ) ;
V_199 -> V_569 = 24 ;
}
}
static int
F_683 ( struct V_28 * V_29 ,
struct V_260 * V_78 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_2 * V_3 ;
int V_779 ;
switch ( V_78 -> V_314 ) {
case V_284 :
V_779 = 8 * 3 ;
break;
case V_286 :
case V_328 :
if ( F_3 ( F_43 ( V_10 ) -> V_91 > 3 ) )
return - V_272 ;
case V_288 :
V_779 = 6 * 3 ;
break;
case V_292 :
case V_301 :
if ( F_3 ( F_43 ( V_10 ) -> V_91 < 4 ) )
return - V_272 ;
case V_290 :
case V_302 :
V_779 = 8 * 3 ;
break;
case V_294 :
case V_329 :
case V_296 :
case V_330 :
if ( F_3 ( F_43 ( V_10 ) -> V_91 < 4 ) )
return - V_272 ;
V_779 = 10 * 3 ;
break;
default:
F_142 ( L_154 ) ;
return - V_272 ;
}
V_199 -> V_569 = V_779 ;
F_428 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_3 -> V_895 ||
V_3 -> V_895 -> V_31 != V_29 )
continue;
F_682 ( V_3 , V_199 ) ;
}
return V_779 ;
}
static void F_684 ( const struct V_361 * V_445 )
{
F_142 ( L_155
L_156 ,
V_445 -> V_81 ,
V_445 -> V_364 , V_445 -> V_690 ,
V_445 -> V_693 , V_445 -> V_689 ,
V_445 -> V_365 , V_445 -> V_695 ,
V_445 -> V_696 , V_445 -> V_685 , V_445 -> type , V_445 -> V_446 ) ;
}
static void F_685 ( struct V_28 * V_29 ,
struct V_198 * V_199 ,
const char * V_990 )
{
F_142 ( L_157 , V_29 -> V_8 . V_8 . V_227 ,
V_990 , F_69 ( V_29 -> V_4 ) ) ;
F_142 ( L_158 , F_686 ( V_199 -> V_84 ) ) ;
F_142 ( L_159 ,
V_199 -> V_569 , V_199 -> V_704 ) ;
F_142 ( L_160 ,
V_199 -> V_247 ,
V_199 -> V_386 ,
V_199 -> V_483 . V_607 , V_199 -> V_483 . V_608 ,
V_199 -> V_483 . V_609 , V_199 -> V_483 . V_610 ,
V_199 -> V_483 . V_606 ) ;
F_142 ( L_161 ,
V_199 -> V_439 ,
V_199 -> V_626 . V_607 , V_199 -> V_626 . V_608 ,
V_199 -> V_626 . V_609 , V_199 -> V_626 . V_610 ,
V_199 -> V_626 . V_606 ) ;
F_142 ( L_162 ,
V_199 -> V_439 ,
V_199 -> V_627 . V_607 ,
V_199 -> V_627 . V_608 ,
V_199 -> V_627 . V_609 ,
V_199 -> V_627 . V_610 ,
V_199 -> V_627 . V_606 ) ;
F_142 ( L_163 ,
V_199 -> V_991 ,
V_199 -> V_992 ) ;
F_142 ( L_164 ) ;
F_687 ( & V_199 -> V_8 . V_445 ) ;
F_142 ( L_165 ) ;
F_687 ( & V_199 -> V_8 . V_80 ) ;
F_684 ( & V_199 -> V_8 . V_80 ) ;
F_142 ( L_166 , V_199 -> V_650 ) ;
F_142 ( L_167 ,
V_199 -> V_326 , V_199 -> V_325 ) ;
F_142 ( L_168 ,
V_199 -> V_492 . V_493 ,
V_199 -> V_492 . V_497 ,
V_199 -> V_492 . V_725 ) ;
F_142 ( L_169 ,
V_199 -> V_366 . V_462 ,
V_199 -> V_366 . V_311 ,
V_199 -> V_366 . V_106 ? L_170 : L_171 ) ;
F_142 ( L_172 , V_199 -> V_468 ) ;
F_142 ( L_173 , V_199 -> V_248 ) ;
}
static bool F_688 ( const struct V_1 * V_932 ,
const struct V_1 * V_933 )
{
return V_932 == V_933 || ( V_932 -> V_993 & ( 1 << V_933 -> type ) &&
V_933 -> V_993 & ( 1 << V_932 -> type ) ) ;
}
static bool F_689 ( struct V_28 * V_29 ,
struct V_1 * V_6 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_994 ;
F_13 (dev, source_encoder) {
if ( V_994 -> V_31 != V_29 )
continue;
if ( ! F_688 ( V_6 , V_994 ) )
return false ;
}
return true ;
}
static bool F_690 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_6 ;
F_13 (dev, encoder) {
if ( V_6 -> V_31 != V_29 )
continue;
if ( ! F_689 ( V_29 , V_6 ) )
return false ;
}
return true ;
}
static bool F_691 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
unsigned int V_995 = 0 ;
F_428 (connector,
&dev->mode_config.connector_list, base.head) {
struct V_1 * V_6 = V_3 -> V_895 ;
if ( ! V_6 )
continue;
F_3 ( ! V_6 -> V_31 ) ;
switch ( V_6 -> type ) {
unsigned int V_218 ;
case V_506 :
if ( F_3 ( ! F_60 ( V_10 ) ) )
break;
case V_507 :
case V_41 :
case V_367 :
V_218 = 1 << F_387 ( & V_6 -> V_8 ) -> V_94 ;
if ( V_995 & V_218 )
return false ;
V_995 |= V_218 ;
default:
break;
}
}
return true ;
}
static struct V_198 *
F_692 ( struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_361 * V_445 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_6 ;
struct V_198 * V_199 ;
int V_996 , V_266 = - V_272 ;
bool V_391 = true ;
if ( ! F_690 ( F_37 ( V_29 ) ) ) {
F_142 ( L_174 ) ;
return F_584 ( - V_272 ) ;
}
if ( ! F_691 ( V_10 ) ) {
F_142 ( L_175 ) ;
return F_584 ( - V_272 ) ;
}
V_199 = F_512 ( sizeof( * V_199 ) , V_457 ) ;
if ( ! V_199 )
return F_584 ( - V_459 ) ;
F_693 ( & V_199 -> V_8 . V_80 , V_445 ) ;
F_693 ( & V_199 -> V_8 . V_445 , V_445 ) ;
V_199 -> V_84 =
(enum V_82 ) F_37 ( V_29 ) -> V_4 ;
V_199 -> V_115 = V_451 ;
if ( ! ( V_199 -> V_8 . V_80 . V_446 &
( V_447 | V_997 ) ) )
V_199 -> V_8 . V_80 . V_446 |= V_997 ;
if ( ! ( V_199 -> V_8 . V_80 . V_446 &
( V_449 | V_998 ) ) )
V_199 -> V_8 . V_80 . V_446 |= V_998 ;
V_996 = F_683 ( F_37 ( V_29 ) ,
V_78 , V_199 ) ;
if ( V_996 < 0 )
goto V_898;
F_694 ( & V_199 -> V_8 . V_445 ,
& V_199 -> V_326 ,
& V_199 -> V_325 ) ;
V_999:
V_199 -> V_650 = 0 ;
V_199 -> V_488 = 1 ;
F_695 ( & V_199 -> V_8 . V_80 ,
V_1000 ) ;
F_13 (dev, encoder) {
if ( & V_6 -> V_31 -> V_8 != V_29 )
continue;
if ( ! ( V_6 -> V_1001 ( V_6 , V_199 ) ) ) {
F_142 ( L_176 ) ;
goto V_898;
}
}
if ( ! V_199 -> V_650 )
V_199 -> V_650 = V_199 -> V_8 . V_80 . V_81
* V_199 -> V_488 ;
V_266 = F_444 ( F_37 ( V_29 ) , V_199 ) ;
if ( V_266 < 0 ) {
F_142 ( L_177 ) ;
goto V_898;
}
if ( V_266 == V_571 ) {
if ( F_46 ( ! V_391 , L_178 ) ) {
V_266 = - V_272 ;
goto V_898;
}
F_142 ( L_179 ) ;
V_391 = false ;
goto V_999;
}
V_199 -> V_704 = V_199 -> V_569 != V_996 ;
F_142 ( L_180 ,
V_996 , V_199 -> V_569 , V_199 -> V_704 ) ;
return V_199 ;
V_898:
F_202 ( V_199 ) ;
return F_584 ( V_266 ) ;
}
static void
F_696 ( struct V_75 * V_29 , unsigned * V_1002 ,
unsigned * V_545 , unsigned * V_1003 )
{
struct V_28 * V_28 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
struct V_75 * V_1004 ;
* V_1003 = * V_1002 = * V_545 = 0 ;
F_428 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_8 . V_6 == & V_3 -> V_895 -> V_8 )
continue;
if ( V_3 -> V_8 . V_6 ) {
V_1004 = V_3 -> V_8 . V_6 -> V_29 ;
* V_545 |= 1 << F_37 ( V_1004 ) -> V_4 ;
}
if ( V_3 -> V_895 )
* V_545 |=
1 << V_3 -> V_895 -> V_31 -> V_4 ;
}
F_13 (dev, encoder) {
if ( V_6 -> V_8 . V_29 == & V_6 -> V_31 -> V_8 )
continue;
if ( V_6 -> V_8 . V_29 ) {
V_1004 = V_6 -> V_8 . V_29 ;
* V_545 |= 1 << F_37 ( V_1004 ) -> V_4 ;
}
if ( V_6 -> V_31 )
* V_545 |= 1 << V_6 -> V_31 -> V_4 ;
}
F_129 (dev, intel_crtc) {
if ( V_28 -> V_8 . V_106 == V_28 -> V_544 )
continue;
if ( ! V_28 -> V_544 )
* V_1003 |= 1 << V_28 -> V_4 ;
else
* V_545 |= 1 << V_28 -> V_4 ;
}
V_28 = F_37 ( V_29 ) ;
if ( V_28 -> V_544 )
* V_545 |= 1 << V_28 -> V_4 ;
if ( * V_545 )
* V_1002 = * V_545 ;
* V_1002 &= ~ ( * V_1003 ) ;
* V_545 &= ~ ( * V_1003 ) ;
* V_1002 &= 1 << V_28 -> V_4 ;
* V_545 &= 1 << V_28 -> V_4 ;
F_142 ( L_181 ,
* V_1002 , * V_545 , * V_1003 ) ;
}
static bool F_697 ( struct V_75 * V_29 )
{
struct V_560 * V_6 ;
struct V_9 * V_10 = V_29 -> V_10 ;
F_428 (encoder, &dev->mode_config.encoder_list, head)
if ( V_6 -> V_29 == V_29 )
return true ;
return false ;
}
static void
F_698 ( struct V_9 * V_10 , unsigned V_545 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 ;
struct V_28 * V_28 ;
struct V_556 * V_3 ;
F_318 ( V_12 ) ;
F_13 (dev, intel_encoder) {
if ( ! V_1 -> V_8 . V_29 )
continue;
V_28 = F_37 ( V_1 -> V_8 . V_29 ) ;
if ( V_545 & ( 1 << V_28 -> V_4 ) )
V_1 -> V_555 = false ;
}
F_681 ( V_10 ) ;
F_129 (dev, intel_crtc) {
F_3 ( V_28 -> V_8 . V_106 != F_697 ( & V_28 -> V_8 ) ) ;
F_3 ( V_28 -> V_454 &&
V_28 -> V_454 != V_28 -> V_79 ) ;
F_3 ( V_28 -> V_8 . V_106 != ! ! V_28 -> V_454 ) ;
}
F_428 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_3 -> V_6 || ! V_3 -> V_6 -> V_29 )
continue;
V_28 = F_37 ( V_3 -> V_6 -> V_29 ) ;
if ( V_545 & ( 1 << V_28 -> V_4 ) ) {
struct V_1005 * V_1006 =
V_10 -> V_889 . V_1006 ;
V_3 -> V_558 = V_561 ;
F_699 ( & V_3 -> V_8 ,
V_1006 ,
V_561 ) ;
V_1 = F_429 ( V_3 -> V_6 ) ;
V_1 -> V_555 = true ;
}
}
}
static bool F_700 ( int V_1007 , int V_1008 )
{
int V_73 ;
if ( V_1007 == V_1008 )
return true ;
if ( ! V_1007 || ! V_1008 )
return false ;
V_73 = abs ( V_1007 - V_1008 ) ;
if ( ( ( ( ( V_73 + V_1007 + V_1008 ) * 100 ) ) / ( V_1007 + V_1008 ) ) < 105 )
return true ;
return false ;
}
static bool
F_701 ( struct V_9 * V_10 ,
struct V_198 * V_1009 ,
struct V_198 * V_199 )
{
#define F_702 ( V_121 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_703 ( V_121 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_704 ( V_121 , T_7 ) \
if ((current_config->name != pipe_config->name) && \
(current_config->alt_name != pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i or %i, found %i)\n", \
current_config->name, \
current_config->alt_name, \
pipe_config->name); \
return false; \
}
#define F_705 ( V_121 , V_511 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
DRM_ERROR("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
return false; \
}
#define F_706 ( V_121 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_707 ( T_8 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_703 ( V_84 ) ;
F_703 ( V_247 ) ;
F_703 ( V_386 ) ;
F_703 ( V_483 . V_607 ) ;
F_703 ( V_483 . V_608 ) ;
F_703 ( V_483 . V_609 ) ;
F_703 ( V_483 . V_610 ) ;
F_703 ( V_483 . V_606 ) ;
F_703 ( V_439 ) ;
if ( F_43 ( V_10 ) -> V_91 < 8 ) {
F_703 ( V_626 . V_607 ) ;
F_703 ( V_626 . V_608 ) ;
F_703 ( V_626 . V_609 ) ;
F_703 ( V_626 . V_610 ) ;
F_703 ( V_626 . V_606 ) ;
if ( V_1009 -> V_625 ) {
F_703 ( V_627 . V_607 ) ;
F_703 ( V_627 . V_608 ) ;
F_703 ( V_627 . V_609 ) ;
F_703 ( V_627 . V_610 ) ;
F_703 ( V_627 . V_606 ) ;
}
} else {
F_704 ( V_626 . V_607 , V_627 . V_607 ) ;
F_704 ( V_626 . V_608 , V_627 . V_608 ) ;
F_704 ( V_626 . V_609 , V_627 . V_609 ) ;
F_704 ( V_626 . V_610 , V_627 . V_610 ) ;
F_704 ( V_626 . V_606 , V_627 . V_606 ) ;
}
F_703 ( V_8 . V_80 . V_364 ) ;
F_703 ( V_8 . V_80 . V_689 ) ;
F_703 ( V_8 . V_80 . V_691 ) ;
F_703 ( V_8 . V_80 . V_692 ) ;
F_703 ( V_8 . V_80 . V_690 ) ;
F_703 ( V_8 . V_80 . V_693 ) ;
F_703 ( V_8 . V_80 . V_365 ) ;
F_703 ( V_8 . V_80 . V_685 ) ;
F_703 ( V_8 . V_80 . V_694 ) ;
F_703 ( V_8 . V_80 . V_686 ) ;
F_703 ( V_8 . V_80 . V_695 ) ;
F_703 ( V_8 . V_80 . V_696 ) ;
F_703 ( V_488 ) ;
F_703 ( V_1010 ) ;
if ( ( F_43 ( V_10 ) -> V_91 < 8 && ! F_218 ( V_10 ) ) ||
F_21 ( V_10 ) )
F_703 ( V_714 ) ;
F_703 ( V_992 ) ;
F_703 ( V_991 ) ;
F_705 ( V_8 . V_80 . V_446 ,
V_688 ) ;
if ( ! F_707 ( V_1011 ) ) {
F_705 ( V_8 . V_80 . V_446 ,
V_447 ) ;
F_705 ( V_8 . V_80 . V_446 ,
V_997 ) ;
F_705 ( V_8 . V_80 . V_446 ,
V_449 ) ;
F_705 ( V_8 . V_80 . V_446 ,
V_998 ) ;
}
F_703 ( V_326 ) ;
F_703 ( V_325 ) ;
if ( ! F_707 ( V_1012 ) ) {
F_703 ( V_492 . V_493 ) ;
if ( F_43 ( V_10 ) -> V_91 < 4 )
F_703 ( V_492 . V_497 ) ;
F_703 ( V_492 . V_725 ) ;
}
F_703 ( V_366 . V_106 ) ;
if ( V_1009 -> V_366 . V_106 ) {
F_703 ( V_366 . V_462 ) ;
F_703 ( V_366 . V_311 ) ;
}
if ( F_218 ( V_10 ) )
F_703 ( V_468 ) ;
F_703 ( V_248 ) ;
F_702 ( V_829 ) ;
F_703 ( V_115 ) ;
F_702 ( V_200 . V_56 ) ;
F_702 ( V_200 . V_202 ) ;
F_702 ( V_200 . V_551 ) ;
F_702 ( V_200 . V_552 ) ;
F_702 ( V_200 . V_1013 ) ;
F_702 ( V_200 . V_832 ) ;
F_702 ( V_200 . V_1014 ) ;
F_702 ( V_200 . V_1015 ) ;
if ( F_18 ( V_10 ) || F_43 ( V_10 ) -> V_91 >= 5 )
F_703 ( V_569 ) ;
F_706 ( V_8 . V_80 . V_81 ) ;
F_706 ( V_650 ) ;
#undef F_702
#undef F_703
#undef F_704
#undef F_705
#undef F_706
#undef F_707
return true ;
}
static void F_708 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1016 V_1017 , * V_1018 ;
struct V_28 * V_28 ;
int V_151 ;
if ( F_43 ( V_10 ) -> V_91 < 9 )
return;
F_709 ( V_12 , & V_1017 ) ;
V_1018 = & V_12 -> V_1019 . V_1020 . V_1021 ;
F_129 (dev, intel_crtc) {
struct V_1022 * V_1023 , * V_1024 ;
const enum V_4 V_4 = V_28 -> V_4 ;
if ( ! V_28 -> V_76 )
continue;
F_710 (pipe, plane) {
V_1023 = & V_1017 . V_151 [ V_4 ] [ V_151 ] ;
V_1024 = & V_1018 -> V_151 [ V_4 ] [ V_151 ] ;
if ( F_711 ( V_1023 , V_1024 ) )
continue;
F_121 ( L_182
L_183 ,
F_69 ( V_4 ) , V_151 + 1 ,
V_1024 -> V_879 , V_1024 -> V_880 ,
V_1023 -> V_879 , V_1023 -> V_880 ) ;
}
V_1023 = & V_1017 . V_868 [ V_4 ] ;
V_1024 = & V_1018 -> V_868 [ V_4 ] ;
if ( F_711 ( V_1023 , V_1024 ) )
continue;
F_121 ( L_184
L_183 ,
F_69 ( V_4 ) ,
V_1024 -> V_879 , V_1024 -> V_880 ,
V_1023 -> V_879 , V_1023 -> V_880 ) ;
}
}
static void
F_712 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
F_428 (connector, &dev->mode_config.connector_list,
base.head) {
F_433 ( V_3 ) ;
F_52 ( & V_3 -> V_895 -> V_8 != V_3 -> V_8 . V_6 ,
L_185 ) ;
}
}
static void
F_713 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_13 (dev, encoder) {
bool V_106 = false ;
bool V_76 = false ;
enum V_4 V_4 , V_1025 ;
F_142 ( L_186 ,
V_6 -> V_8 . V_8 . V_227 ,
V_6 -> V_8 . V_121 ) ;
F_52 ( & V_6 -> V_31 -> V_8 != V_6 -> V_8 . V_29 ,
L_187 ) ;
F_52 ( V_6 -> V_555 && ! V_6 -> V_8 . V_29 ,
L_188 ) ;
F_428 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_8 . V_6 != & V_6 -> V_8 )
continue;
V_106 = true ;
if ( V_3 -> V_8 . V_558 != V_559 )
V_76 = true ;
}
if ( ! V_106 && V_6 -> V_8 . V_1026 == V_1027 )
continue;
F_52 ( ! ! V_6 -> V_8 . V_29 != V_106 ,
L_189
L_190 ,
! ! V_6 -> V_8 . V_29 , V_106 ) ;
F_52 ( V_76 && ! V_6 -> V_8 . V_29 ,
L_191 ) ;
F_52 ( V_6 -> V_555 != V_76 ,
L_192
L_190 , V_76 , V_6 -> V_555 ) ;
V_76 = V_6 -> V_120 ( V_6 , & V_4 ) ;
F_52 ( V_76 != V_6 -> V_555 ,
L_193
L_190 ,
V_6 -> V_555 , V_76 ) ;
if ( ! V_6 -> V_8 . V_29 )
continue;
V_1025 = F_37 ( V_6 -> V_8 . V_29 ) -> V_4 ;
F_52 ( V_76 && V_4 != V_1025 ,
L_194
L_190 ,
V_1025 , V_4 ) ;
}
}
static void
F_714 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_198 V_199 ;
F_129 (dev, crtc) {
bool V_106 = false ;
bool V_76 = false ;
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
F_142 ( L_195 ,
V_29 -> V_8 . V_8 . V_227 ) ;
F_52 ( V_29 -> V_76 && ! V_29 -> V_8 . V_106 ,
L_196 ) ;
F_13 (dev, encoder) {
if ( V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
V_106 = true ;
if ( V_6 -> V_555 )
V_76 = true ;
}
F_52 ( V_76 != V_29 -> V_76 ,
L_197
L_190 , V_76 , V_29 -> V_76 ) ;
F_52 ( V_106 != V_29 -> V_8 . V_106 ,
L_198
L_190 , V_106 , V_29 -> V_8 . V_106 ) ;
V_76 = V_12 -> V_252 . V_1028 ( V_29 ,
& V_199 ) ;
if ( ( V_29 -> V_4 == V_129 && V_12 -> V_147 & V_148 ) ||
( V_29 -> V_4 == V_138 && V_12 -> V_147 & V_149 ) )
V_76 = V_29 -> V_76 ;
F_13 (dev, encoder) {
enum V_4 V_4 ;
if ( V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
if ( V_6 -> V_120 ( V_6 , & V_4 ) )
V_6 -> V_1029 ( V_6 , & V_199 ) ;
}
F_52 ( V_29 -> V_76 != V_76 ,
L_199
L_190 , V_29 -> V_76 , V_76 ) ;
if ( V_76 &&
! F_701 ( V_10 , V_29 -> V_79 , & V_199 ) ) {
F_52 ( 1 , L_200 ) ;
F_685 ( V_29 , & V_199 ,
L_201 ) ;
F_685 ( V_29 , V_29 -> V_79 ,
L_202 ) ;
}
}
}
static void
F_715 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 ;
struct V_118 V_200 ;
int V_153 ;
for ( V_153 = 0 ; V_153 < V_12 -> V_455 ; V_153 ++ ) {
struct V_114 * V_117 = & V_12 -> V_116 [ V_153 ] ;
int V_1030 = 0 , V_1031 = 0 ;
bool V_76 ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
F_142 ( L_203 , V_117 -> V_121 ) ;
V_76 = V_117 -> V_120 ( V_12 , V_117 , & V_200 ) ;
F_52 ( V_117 -> V_76 > F_716 ( V_117 -> V_79 . V_224 ) ,
L_204 ,
V_117 -> V_76 , F_716 ( V_117 -> V_79 . V_224 ) ) ;
F_52 ( V_117 -> V_76 && ! V_117 -> V_225 ,
L_205 ) ;
F_52 ( V_117 -> V_225 && ! V_117 -> V_76 ,
L_206 ) ;
F_52 ( V_117 -> V_225 != V_76 ,
L_207 ,
V_117 -> V_225 , V_76 ) ;
F_129 (dev, crtc) {
if ( V_29 -> V_8 . V_106 && F_57 ( V_29 ) == V_117 )
V_1030 ++ ;
if ( V_29 -> V_76 && F_57 ( V_29 ) == V_117 )
V_1031 ++ ;
}
F_52 ( V_117 -> V_76 != V_1031 ,
L_208 ,
V_117 -> V_76 , V_1031 ) ;
F_52 ( F_716 ( V_117 -> V_79 . V_224 ) != V_1030 ,
L_209 ,
F_716 ( V_117 -> V_79 . V_224 ) , V_1030 ) ;
F_52 ( V_117 -> V_225 && memcmp ( & V_117 -> V_79 . V_119 , & V_200 ,
sizeof( V_200 ) ) ,
L_210 ) ;
}
}
void
F_435 ( struct V_9 * V_10 )
{
F_708 ( V_10 ) ;
F_712 ( V_10 ) ;
F_713 ( V_10 ) ;
F_714 ( V_10 ) ;
F_715 ( V_10 ) ;
}
void F_717 ( const struct V_198 * V_199 ,
int V_1032 )
{
F_46 ( ! F_700 ( V_199 -> V_8 . V_80 . V_81 , V_1032 ) ,
L_211 ,
V_199 -> V_8 . V_80 . V_81 , V_1032 ) ;
}
static void F_718 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
if ( F_22 ( V_10 ) ) {
const struct V_361 * V_445 = & V_29 -> V_79 -> V_8 . V_80 ;
int V_700 ;
V_700 = V_445 -> V_685 ;
if ( V_445 -> V_446 & V_688 )
V_700 /= 2 ;
V_29 -> V_1033 = V_700 - 1 ;
} else if ( F_60 ( V_10 ) &&
F_10 ( V_29 , V_41 ) ) {
V_29 -> V_1033 = 2 ;
} else
V_29 -> V_1033 = 1 ;
}
static struct V_198 *
F_719 ( struct V_75 * V_29 ,
struct V_361 * V_445 ,
struct V_260 * V_78 ,
unsigned * V_1002 ,
unsigned * V_545 ,
unsigned * V_1003 )
{
struct V_198 * V_199 = NULL ;
F_696 ( V_29 , V_1002 ,
V_545 , V_1003 ) ;
if ( ( * V_1002 ) == 0 )
goto V_925;
V_199 = F_692 ( V_29 , V_78 , V_445 ) ;
if ( F_598 ( V_199 ) ) {
goto V_925;
}
F_685 ( F_37 ( V_29 ) , V_199 ,
L_212 ) ;
V_925:
return V_199 ;
}
static int F_720 ( struct V_9 * V_10 ,
unsigned V_1002 ,
unsigned V_1003 )
{
struct V_11 * V_12 = F_234 ( V_10 ) ;
unsigned V_456 = V_1002 | V_1003 ;
struct V_28 * V_28 ;
int V_266 = 0 ;
if ( ! V_12 -> V_252 . V_1034 )
return 0 ;
V_266 = F_316 ( V_12 , V_456 ) ;
if ( V_266 )
goto V_1035;
F_721 (dev, modeset_pipes, intel_crtc) {
struct V_198 * V_107 = V_28 -> V_454 ;
V_266 = V_12 -> V_252 . V_1034 ( V_28 ,
V_107 ) ;
if ( V_266 ) {
F_319 ( V_12 ) ;
goto V_1035;
}
}
V_1035:
return V_266 ;
}
static int F_722 ( struct V_75 * V_29 ,
struct V_361 * V_445 ,
int V_254 , int V_255 , struct V_260 * V_78 ,
struct V_198 * V_199 ,
unsigned V_1002 ,
unsigned V_545 ,
unsigned V_1003 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_361 * V_1036 ;
struct V_28 * V_28 ;
int V_266 = 0 ;
V_1036 = F_723 ( sizeof( * V_1036 ) , V_457 ) ;
if ( ! V_1036 )
return - V_459 ;
* V_1036 = V_29 -> V_445 ;
if ( V_1002 )
F_37 ( V_29 ) -> V_454 = V_199 ;
if ( F_21 ( V_10 ) ) {
F_408 ( V_10 , & V_545 ) ;
V_545 &= ~ V_1003 ;
}
V_266 = F_720 ( V_10 , V_1002 , V_1003 ) ;
if ( V_266 )
goto V_1035;
F_721 (dev, disable_pipes, intel_crtc)
F_427 ( & V_28 -> V_8 ) ;
F_721 (dev, prepare_pipes, intel_crtc) {
if ( V_28 -> V_8 . V_106 )
V_12 -> V_252 . V_351 ( & V_28 -> V_8 ) ;
}
if ( V_1002 ) {
V_29 -> V_445 = * V_445 ;
F_614 ( F_37 ( V_29 ) , V_199 ) ;
F_724 ( V_29 ,
& V_199 -> V_8 . V_80 ) ;
}
F_698 ( V_10 , V_545 ) ;
F_392 ( V_10 ) ;
F_721 (dev, modeset_pipes, intel_crtc) {
struct V_250 * V_77 = V_28 -> V_8 . V_77 ;
int V_697 , V_575 ;
F_694 ( V_445 , & V_575 , & V_697 ) ;
V_266 = V_77 -> V_466 -> V_1037 ( V_77 , & V_28 -> V_8 ,
V_78 , 0 , 0 ,
V_575 , V_697 ,
V_254 << 16 , V_255 << 16 ,
V_575 << 16 , V_697 << 16 ) ;
}
F_721 (dev, prepare_pipes, intel_crtc) {
F_718 ( V_28 ) ;
V_12 -> V_252 . V_554 ( & V_28 -> V_8 ) ;
}
V_1035:
if ( V_266 && V_29 -> V_106 )
V_29 -> V_445 = * V_1036 ;
F_202 ( V_1036 ) ;
return V_266 ;
}
static int F_725 ( struct V_75 * V_29 ,
struct V_361 * V_445 ,
int V_254 , int V_255 , struct V_260 * V_78 ,
struct V_198 * V_199 ,
unsigned V_1002 ,
unsigned V_545 ,
unsigned V_1003 )
{
int V_266 ;
V_266 = F_722 ( V_29 , V_445 , V_254 , V_255 , V_78 , V_199 , V_1002 ,
V_545 , V_1003 ) ;
if ( V_266 == 0 )
F_435 ( V_29 -> V_10 ) ;
return V_266 ;
}
static int F_599 ( struct V_75 * V_29 ,
struct V_361 * V_445 ,
int V_254 , int V_255 , struct V_260 * V_78 )
{
struct V_198 * V_199 ;
unsigned V_1002 , V_545 , V_1003 ;
V_199 = F_719 ( V_29 , V_445 , V_78 ,
& V_1002 ,
& V_545 ,
& V_1003 ) ;
if ( F_598 ( V_199 ) )
return F_726 ( V_199 ) ;
return F_725 ( V_29 , V_445 , V_254 , V_255 , V_78 , V_199 ,
V_1002 , V_545 ,
V_1003 ) ;
}
void F_727 ( struct V_75 * V_29 )
{
F_599 ( V_29 , & V_29 -> V_445 , V_29 -> V_254 , V_29 -> V_255 , V_29 -> V_77 -> V_78 ) ;
}
static void F_728 ( struct V_1038 * V_79 )
{
if ( ! V_79 )
return;
F_202 ( V_79 -> V_1039 ) ;
F_202 ( V_79 -> V_1040 ) ;
F_202 ( V_79 -> V_1041 ) ;
F_202 ( V_79 ) ;
}
static int F_729 ( struct V_9 * V_10 ,
struct V_1038 * V_79 )
{
struct V_75 * V_29 ;
struct V_560 * V_6 ;
struct V_556 * V_3 ;
int V_206 ;
V_79 -> V_1041 =
F_730 ( V_10 -> V_889 . V_1042 ,
sizeof( bool ) , V_457 ) ;
if ( ! V_79 -> V_1041 )
return - V_459 ;
V_79 -> V_1040 =
F_730 ( V_10 -> V_889 . V_1043 ,
sizeof( struct V_75 * ) , V_457 ) ;
if ( ! V_79 -> V_1040 )
return - V_459 ;
V_79 -> V_1039 =
F_730 ( V_10 -> V_889 . V_1044 ,
sizeof( struct V_560 * ) , V_457 ) ;
if ( ! V_79 -> V_1039 )
return - V_459 ;
V_206 = 0 ;
F_203 (dev, crtc) {
V_79 -> V_1041 [ V_206 ++ ] = V_29 -> V_106 ;
}
V_206 = 0 ;
F_428 (encoder, &dev->mode_config.encoder_list, head) {
V_79 -> V_1040 [ V_206 ++ ] = V_6 -> V_29 ;
}
V_206 = 0 ;
F_428 (connector, &dev->mode_config.connector_list, head) {
V_79 -> V_1039 [ V_206 ++ ] = V_3 -> V_6 ;
}
return 0 ;
}
static void F_731 ( struct V_9 * V_10 ,
struct V_1038 * V_79 )
{
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
int V_206 ;
V_206 = 0 ;
F_129 (dev, crtc) {
V_29 -> V_544 = V_79 -> V_1041 [ V_206 ++ ] ;
if ( V_29 -> V_544 )
V_29 -> V_454 = V_29 -> V_79 ;
else
V_29 -> V_454 = NULL ;
}
V_206 = 0 ;
F_13 (dev, encoder) {
V_6 -> V_31 =
F_37 ( V_79 -> V_1040 [ V_206 ++ ] ) ;
}
V_206 = 0 ;
F_428 (connector, &dev->mode_config.connector_list, base.head) {
V_3 -> V_895 =
F_429 ( V_79 -> V_1039 [ V_206 ++ ] ) ;
}
}
static bool
F_732 ( struct V_1045 * V_1046 )
{
int V_153 ;
if ( V_1046 -> V_615 == 0 )
return false ;
if ( F_3 ( V_1046 -> V_1047 == NULL ) )
return false ;
for ( V_153 = 0 ; V_153 < V_1046 -> V_615 ; V_153 ++ )
if ( V_1046 -> V_1047 [ V_153 ] -> V_6 &&
V_1046 -> V_1047 [ V_153 ] -> V_6 -> V_29 == V_1046 -> V_29 &&
V_1046 -> V_1047 [ V_153 ] -> V_558 != V_561 )
return true ;
return false ;
}
static void
F_733 ( struct V_1045 * V_1046 ,
struct V_1038 * V_79 )
{
if ( F_732 ( V_1046 ) ) {
V_79 -> V_1048 = true ;
} else if ( V_1046 -> V_29 -> V_77 -> V_78 != V_1046 -> V_78 ) {
if ( V_1046 -> V_29 -> V_77 -> V_78 == NULL ) {
struct V_28 * V_28 =
F_37 ( V_1046 -> V_29 ) ;
if ( V_28 -> V_76 ) {
F_142 ( L_213 ) ;
V_79 -> V_1049 = true ;
} else {
F_142 ( L_214 ) ;
V_79 -> V_1048 = true ;
}
} else if ( V_1046 -> V_78 == NULL ) {
V_79 -> V_1048 = true ;
} else if ( V_1046 -> V_78 -> V_314 !=
V_1046 -> V_29 -> V_77 -> V_78 -> V_314 ) {
V_79 -> V_1048 = true ;
} else {
V_79 -> V_1049 = true ;
}
}
if ( V_1046 -> V_78 && ( V_1046 -> V_254 != V_1046 -> V_29 -> V_254 || V_1046 -> V_255 != V_1046 -> V_29 -> V_255 ) )
V_79 -> V_1049 = true ;
if ( V_1046 -> V_445 && ! F_734 ( V_1046 -> V_445 , & V_1046 -> V_29 -> V_445 ) ) {
F_142 ( L_215 ) ;
F_687 ( & V_1046 -> V_29 -> V_445 ) ;
F_687 ( V_1046 -> V_445 ) ;
V_79 -> V_1048 = true ;
}
F_142 ( L_216 ,
V_1046 -> V_29 -> V_8 . V_227 , V_79 -> V_1048 , V_79 -> V_1049 ) ;
}
static int
F_735 ( struct V_9 * V_10 ,
struct V_1045 * V_1046 ,
struct V_1038 * V_79 )
{
struct V_2 * V_3 ;
struct V_1 * V_6 ;
struct V_28 * V_29 ;
int V_1050 ;
F_3 ( ! V_1046 -> V_78 && ( V_1046 -> V_615 != 0 ) ) ;
F_3 ( V_1046 -> V_78 && ( V_1046 -> V_615 == 0 ) ) ;
F_428 (connector, &dev->mode_config.connector_list,
base.head) {
for ( V_1050 = 0 ; V_1050 < V_1046 -> V_615 ; V_1050 ++ ) {
if ( V_1046 -> V_1047 [ V_1050 ] == & V_3 -> V_8 ) {
V_3 -> V_895 = F_1 ( V_3 , F_37 ( V_1046 -> V_29 ) -> V_4 ) ;
break;
}
}
if ( ( ! V_1046 -> V_78 || V_1050 == V_1046 -> V_615 ) &&
V_3 -> V_8 . V_6 &&
V_3 -> V_8 . V_6 -> V_29 == V_1046 -> V_29 ) {
V_3 -> V_895 = NULL ;
F_142 ( L_217 ,
V_3 -> V_8 . V_8 . V_227 ,
V_3 -> V_8 . V_121 ) ;
}
if ( & V_3 -> V_895 -> V_8 != V_3 -> V_8 . V_6 ) {
F_142 ( L_218 ) ;
V_79 -> V_1048 = true ;
}
}
F_428 (connector, &dev->mode_config.connector_list,
base.head) {
struct V_75 * V_31 ;
if ( ! V_3 -> V_895 )
continue;
V_31 = V_3 -> V_895 -> V_8 . V_29 ;
for ( V_1050 = 0 ; V_1050 < V_1046 -> V_615 ; V_1050 ++ ) {
if ( V_1046 -> V_1047 [ V_1050 ] == & V_3 -> V_8 )
V_31 = V_1046 -> V_29 ;
}
if ( ! F_736 ( & V_3 -> V_895 -> V_8 ,
V_31 ) ) {
return - V_272 ;
}
V_3 -> V_895 -> V_31 = F_37 ( V_31 ) ;
F_142 ( L_219 ,
V_3 -> V_8 . V_8 . V_227 ,
V_3 -> V_8 . V_121 ,
V_31 -> V_8 . V_227 ) ;
}
F_13 (dev, encoder) {
int V_615 = 0 ;
F_428 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_895 == V_6 ) {
F_3 ( ! V_3 -> V_895 -> V_31 ) ;
V_615 ++ ;
}
}
if ( V_615 == 0 )
V_6 -> V_31 = NULL ;
else if ( V_615 > 1 )
return - V_272 ;
if ( & V_6 -> V_31 -> V_8 != V_6 -> V_8 . V_29 ) {
F_142 ( L_220 ) ;
V_79 -> V_1048 = true ;
}
}
F_428 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_895 )
if ( V_3 -> V_895 != V_3 -> V_6 )
V_3 -> V_6 = V_3 -> V_895 ;
}
F_129 (dev, crtc) {
V_29 -> V_544 = false ;
F_13 (dev, encoder) {
if ( V_6 -> V_31 == V_29 ) {
V_29 -> V_544 = true ;
break;
}
}
if ( V_29 -> V_544 != V_29 -> V_8 . V_106 ) {
F_142 ( L_221 ,
V_29 -> V_544 ? L_222 : L_223 ) ;
V_79 -> V_1048 = true ;
}
if ( V_29 -> V_544 )
V_29 -> V_454 = V_29 -> V_79 ;
else
V_29 -> V_454 = NULL ;
}
return 0 ;
}
static void F_737 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_142 ( L_224 ,
F_69 ( V_29 -> V_4 ) ) ;
F_428 (connector, &dev->mode_config.connector_list, base.head) {
if ( V_3 -> V_895 &&
V_3 -> V_895 -> V_31 == V_29 )
V_3 -> V_895 = NULL ;
}
F_13 (dev, encoder) {
if ( V_6 -> V_31 == V_29 )
V_6 -> V_31 = NULL ;
}
V_29 -> V_544 = false ;
V_29 -> V_454 = NULL ;
}
static int F_738 ( struct V_1045 * V_1046 )
{
struct V_9 * V_10 ;
struct V_1045 V_1051 ;
struct V_1038 * V_79 ;
struct V_198 * V_199 ;
unsigned V_1002 , V_545 , V_1003 ;
int V_266 ;
F_116 ( ! V_1046 ) ;
F_116 ( ! V_1046 -> V_29 ) ;
F_116 ( ! V_1046 -> V_29 -> V_1052 ) ;
F_116 ( ! V_1046 -> V_445 && V_1046 -> V_78 ) ;
F_116 ( V_1046 -> V_78 && V_1046 -> V_615 == 0 ) ;
if ( V_1046 -> V_78 ) {
F_142 ( L_225 ,
V_1046 -> V_29 -> V_8 . V_227 , V_1046 -> V_78 -> V_8 . V_227 ,
( int ) V_1046 -> V_615 , V_1046 -> V_254 , V_1046 -> V_255 ) ;
} else {
F_142 ( L_226 , V_1046 -> V_29 -> V_8 . V_227 ) ;
}
V_10 = V_1046 -> V_29 -> V_10 ;
V_266 = - V_459 ;
V_79 = F_512 ( sizeof( * V_79 ) , V_457 ) ;
if ( ! V_79 )
goto V_1053;
V_266 = F_729 ( V_10 , V_79 ) ;
if ( V_266 )
goto V_1053;
V_1051 . V_29 = V_1046 -> V_29 ;
V_1051 . V_445 = & V_1046 -> V_29 -> V_445 ;
V_1051 . V_254 = V_1046 -> V_29 -> V_254 ;
V_1051 . V_255 = V_1046 -> V_29 -> V_255 ;
V_1051 . V_78 = V_1046 -> V_29 -> V_77 -> V_78 ;
F_733 ( V_1046 , V_79 ) ;
V_266 = F_735 ( V_10 , V_1046 , V_79 ) ;
if ( V_266 )
goto V_898;
V_199 = F_719 ( V_1046 -> V_29 , V_1046 -> V_445 ,
V_1046 -> V_78 ,
& V_1002 ,
& V_545 ,
& V_1003 ) ;
if ( F_598 ( V_199 ) ) {
V_266 = F_726 ( V_199 ) ;
goto V_898;
} else if ( V_199 ) {
if ( V_199 -> V_991 !=
F_37 ( V_1046 -> V_29 ) -> V_79 -> V_991 )
V_79 -> V_1048 = true ;
}
if ( ! V_79 -> V_1048 )
F_202 ( V_199 ) ;
F_250 ( F_37 ( V_1046 -> V_29 ) ) ;
if ( V_79 -> V_1048 ) {
V_266 = F_725 ( V_1046 -> V_29 , V_1046 -> V_445 ,
V_1046 -> V_254 , V_1046 -> V_255 , V_1046 -> V_78 , V_199 ,
V_1002 , V_545 ,
V_1003 ) ;
} else if ( V_79 -> V_1049 ) {
struct V_28 * V_28 = F_37 ( V_1046 -> V_29 ) ;
struct V_250 * V_77 = V_1046 -> V_29 -> V_77 ;
int V_697 , V_575 ;
F_694 ( V_1046 -> V_445 , & V_575 , & V_697 ) ;
V_266 = V_77 -> V_466 -> V_1037 ( V_77 , V_1046 -> V_29 , V_1046 -> V_78 ,
0 , 0 , V_575 , V_697 ,
V_1046 -> V_254 << 16 , V_1046 -> V_255 << 16 ,
V_575 << 16 , V_697 << 16 ) ;
if ( ! V_28 -> V_251 && V_266 == 0 ) {
F_3 ( ! V_28 -> V_76 ) ;
F_166 ( V_1046 -> V_29 -> V_77 , V_1046 -> V_29 ) ;
}
if ( V_362 . V_363 && V_266 == 0 )
F_435 ( V_1046 -> V_29 -> V_10 ) ;
}
if ( V_266 ) {
F_142 ( L_227 ,
V_1046 -> V_29 -> V_8 . V_227 , V_266 ) ;
V_898:
F_731 ( V_10 , V_79 ) ;
if ( F_37 ( V_1051 . V_29 ) -> V_544 && ! V_1051 . V_78 )
F_737 ( F_37 ( V_1051 . V_29 ) ) ;
if ( V_79 -> V_1048 &&
F_599 ( V_1051 . V_29 , V_1051 . V_445 ,
V_1051 . V_254 , V_1051 . V_255 , V_1051 . V_78 ) )
F_121 ( L_228 ) ;
}
V_1053:
F_728 ( V_79 ) ;
return V_266 ;
}
static bool F_739 ( struct V_11 * V_12 ,
struct V_114 * V_117 ,
struct V_118 * V_119 )
{
T_4 V_108 ;
if ( ! F_75 ( V_12 , V_228 ) )
return false ;
V_108 = F_5 ( F_740 ( V_117 -> V_227 ) ) ;
V_119 -> V_56 = V_108 ;
V_119 -> V_551 = F_5 ( F_741 ( V_117 -> V_227 ) ) ;
V_119 -> V_552 = F_5 ( F_742 ( V_117 -> V_227 ) ) ;
return V_108 & V_110 ;
}
static void F_743 ( struct V_11 * V_12 ,
struct V_114 * V_117 )
{
F_118 ( F_741 ( V_117 -> V_227 ) , V_117 -> V_79 . V_119 . V_551 ) ;
F_118 ( F_742 ( V_117 -> V_227 ) , V_117 -> V_79 . V_119 . V_552 ) ;
}
static void F_744 ( struct V_11 * V_12 ,
struct V_114 * V_117 )
{
F_93 ( V_12 ) ;
F_118 ( F_740 ( V_117 -> V_227 ) , V_117 -> V_79 . V_119 . V_56 ) ;
F_119 ( F_740 ( V_117 -> V_227 ) ) ;
F_120 ( 150 ) ;
F_118 ( F_740 ( V_117 -> V_227 ) , V_117 -> V_79 . V_119 . V_56 ) ;
F_119 ( F_740 ( V_117 -> V_227 ) ) ;
F_120 ( 200 ) ;
}
static void F_745 ( struct V_11 * V_12 ,
struct V_114 * V_117 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_28 * V_29 ;
F_129 (dev, crtc) {
if ( F_57 ( V_29 ) == V_117 )
F_95 ( V_12 , V_29 -> V_4 ) ;
}
F_118 ( F_740 ( V_117 -> V_227 ) , 0 ) ;
F_119 ( F_740 ( V_117 -> V_227 ) ) ;
F_120 ( 200 ) ;
}
static void F_746 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_153 ;
V_12 -> V_455 = 2 ;
for ( V_153 = 0 ; V_153 < V_12 -> V_455 ; V_153 ++ ) {
V_12 -> V_116 [ V_153 ] . V_227 = V_153 ;
V_12 -> V_116 [ V_153 ] . V_121 = V_1054 [ V_153 ] ;
V_12 -> V_116 [ V_153 ] . V_226 = F_743 ;
V_12 -> V_116 [ V_153 ] . V_229 = F_744 ;
V_12 -> V_116 [ V_153 ] . V_230 = F_745 ;
V_12 -> V_116 [ V_153 ] . V_120 =
F_739 ;
}
}
static void F_747 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_60 ( V_10 ) )
F_748 ( V_10 ) ;
else if ( F_48 ( V_10 ) || F_94 ( V_10 ) )
F_746 ( V_10 ) ;
else
V_12 -> V_455 = 0 ;
F_116 ( V_12 -> V_455 > V_1055 ) ;
}
int
F_749 ( struct V_250 * V_151 ,
struct V_260 * V_78 )
{
struct V_9 * V_10 = V_151 -> V_10 ;
struct V_465 * V_465 = F_329 ( V_151 ) ;
enum V_4 V_4 = V_465 -> V_4 ;
struct V_263 * V_264 = F_176 ( V_78 ) ;
struct V_263 * V_1056 = F_176 ( V_151 -> V_78 ) ;
unsigned V_317 = 0 ;
int V_266 = 0 ;
if ( ! V_264 )
return 0 ;
switch ( V_151 -> type ) {
case V_1057 :
V_317 = F_197 ( V_4 ) ;
break;
case V_1058 :
V_317 = F_750 ( V_4 ) ;
break;
case V_1059 :
V_317 = F_751 ( V_4 ) ;
break;
}
F_54 ( & V_10 -> V_267 ) ;
if ( V_151 -> type == V_1058 &&
F_43 ( V_10 ) -> V_1060 ) {
int V_1061 = F_131 ( V_10 ) ? 16 * 1024 : 256 ;
V_266 = F_752 ( V_264 , V_1061 ) ;
if ( V_266 )
F_142 ( L_229 ) ;
} else {
V_266 = F_175 ( V_151 , V_78 , NULL ) ;
}
if ( V_266 == 0 )
F_677 ( V_1056 , V_264 , V_317 ) ;
F_56 ( & V_10 -> V_267 ) ;
return V_266 ;
}
void
F_753 ( struct V_250 * V_151 ,
struct V_260 * V_78 )
{
struct V_9 * V_10 = V_151 -> V_10 ;
struct V_263 * V_264 = F_176 ( V_78 ) ;
if ( F_3 ( ! V_264 ) )
return;
if ( V_151 -> type != V_1058 ||
! F_43 ( V_10 ) -> V_1060 ) {
F_54 ( & V_10 -> V_267 ) ;
F_186 ( V_264 ) ;
F_56 ( & V_10 -> V_267 ) ;
}
}
static int
F_754 ( struct V_250 * V_151 ,
struct V_1062 * V_107 )
{
struct V_9 * V_10 = V_151 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_29 = V_107 -> V_8 . V_29 ;
struct V_28 * V_28 ;
struct V_260 * V_78 = V_107 -> V_8 . V_78 ;
struct V_1063 * V_1064 = & V_107 -> V_1065 ;
struct V_1063 * V_1066 = & V_107 -> V_1066 ;
const struct V_1063 * V_1067 = & V_107 -> V_1067 ;
int V_266 ;
V_29 = V_29 ? V_29 : V_151 -> V_29 ;
V_28 = F_37 ( V_29 ) ;
V_266 = F_755 ( V_151 , V_29 , V_78 ,
V_1066 , V_1064 , V_1067 ,
V_1068 ,
V_1068 ,
false , true , & V_107 -> V_1069 ) ;
if ( V_266 )
return V_266 ;
if ( V_28 -> V_76 ) {
V_28 -> V_1070 . V_1071 = true ;
if ( V_28 -> V_251 &&
F_43 ( V_10 ) -> V_91 <= 4 && ! F_18 ( V_10 ) &&
V_12 -> V_482 . V_151 == V_28 -> V_151 &&
V_107 -> V_8 . V_334 != F_213 ( V_1072 ) ) {
V_28 -> V_1070 . V_349 = true ;
}
if ( V_107 -> V_1069 ) {
if ( F_168 ( V_10 ) && ! V_28 -> V_251 )
V_28 -> V_1070 . V_1073 = true ;
}
V_28 -> V_1070 . V_1074 |=
F_197 ( V_28 -> V_4 ) ;
V_28 -> V_1070 . V_1075 = true ;
}
return 0 ;
}
static void
F_756 ( struct V_250 * V_151 ,
struct V_1062 * V_107 )
{
struct V_75 * V_29 = V_107 -> V_8 . V_29 ;
struct V_260 * V_78 = V_107 -> V_8 . V_78 ;
struct V_9 * V_10 = V_151 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 ;
struct V_263 * V_264 = F_176 ( V_78 ) ;
struct V_465 * V_465 = F_329 ( V_151 ) ;
struct V_1063 * V_1066 = & V_107 -> V_1066 ;
V_29 = V_29 ? V_29 : V_151 -> V_29 ;
V_28 = F_37 ( V_29 ) ;
V_151 -> V_78 = V_78 ;
V_29 -> V_254 = V_1066 -> V_1076 >> 16 ;
V_29 -> V_255 = V_1066 -> y1 >> 16 ;
V_465 -> V_264 = V_264 ;
if ( V_28 -> V_76 ) {
if ( V_107 -> V_1069 ) {
F_250 ( V_28 ) ;
V_28 -> V_251 = true ;
V_12 -> V_252 . V_253 ( V_29 , V_151 -> V_78 ,
V_29 -> V_254 , V_29 -> V_255 ) ;
} else {
F_170 ( V_151 , V_29 ) ;
}
}
}
static void F_757 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_465 * V_465 ;
struct V_250 * V_22 ;
unsigned V_1074 = 0 ;
F_428 (p, &dev->mode_config.plane_list, head) {
V_465 = F_329 ( V_22 ) ;
if ( V_28 -> V_1070 . V_1077 &
( 1 << F_758 ( V_22 ) ) ) {
switch ( V_22 -> type ) {
case V_1057 :
V_1074 = F_197 ( V_465 -> V_4 ) ;
break;
case V_1058 :
V_1074 = F_750 ( V_465 -> V_4 ) ;
break;
case V_1059 :
V_1074 = F_751 ( V_465 -> V_4 ) ;
break;
}
F_54 ( & V_10 -> V_267 ) ;
F_677 ( F_176 ( V_22 -> V_78 ) , NULL , V_1074 ) ;
F_56 ( & V_10 -> V_267 ) ;
}
}
if ( V_28 -> V_1070 . V_1071 )
F_279 ( V_29 ) ;
if ( V_28 -> V_1070 . V_349 )
F_350 ( V_10 ) ;
if ( V_28 -> V_1070 . V_1078 )
F_759 ( V_29 ) ;
if ( V_28 -> V_1070 . V_1079 )
F_358 ( V_29 ) ;
F_180 ( V_12 ) ;
if ( V_28 -> V_76 )
V_28 -> V_1070 . V_1080 =
F_654 ( V_28 ,
& V_28 -> V_1070 . V_966 ) ;
}
static void F_760 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_250 * V_22 ;
if ( V_28 -> V_1070 . V_1080 )
F_655 ( V_28 ,
V_28 -> V_1070 . V_966 ) ;
F_184 ( V_12 ) ;
if ( V_28 -> V_1070 . V_1073 )
F_169 ( V_10 , V_28 -> V_4 ) ;
F_347 ( V_10 , V_28 -> V_1070 . V_1074 ) ;
if ( V_28 -> V_1070 . V_1075 ) {
F_54 ( & V_10 -> V_267 ) ;
F_346 ( V_10 ) ;
F_56 ( & V_10 -> V_267 ) ;
}
if ( V_28 -> V_1070 . V_1081 )
F_761 ( V_29 ) ;
F_328 (p, &dev->mode_config.plane_list)
if ( V_28 -> V_1070 . V_1082 & F_758 ( V_22 ) )
F_762 ( V_22 , V_29 , 0 , 0 , 0 ,
false , false ) ;
memset ( & V_28 -> V_1070 , 0 , sizeof( V_28 -> V_1070 ) ) ;
}
void F_763 ( struct V_250 * V_151 )
{
struct V_465 * V_465 = F_329 ( V_151 ) ;
F_764 ( V_151 ) ;
F_202 ( V_465 ) ;
}
static struct V_250 * F_765 ( struct V_9 * V_10 ,
int V_4 )
{
struct V_465 * V_77 ;
struct V_1062 * V_107 ;
const T_4 * V_1083 ;
int V_1084 ;
V_77 = F_512 ( sizeof( * V_77 ) , V_457 ) ;
if ( V_77 == NULL )
return NULL ;
V_107 = F_766 ( & V_77 -> V_8 ) ;
if ( ! V_107 ) {
F_202 ( V_77 ) ;
return NULL ;
}
V_77 -> V_8 . V_107 = & V_107 -> V_8 ;
V_77 -> V_1085 = false ;
V_77 -> V_1086 = 1 ;
V_77 -> V_4 = V_4 ;
V_77 -> V_151 = V_4 ;
V_77 -> V_1087 = F_754 ;
V_77 -> V_1088 = F_756 ;
if ( F_767 ( V_10 ) && F_43 ( V_10 ) -> V_91 < 4 )
V_77 -> V_151 = ! V_4 ;
if ( F_43 ( V_10 ) -> V_91 <= 3 ) {
V_1083 = V_1089 ;
V_1084 = F_268 ( V_1089 ) ;
} else {
V_1083 = V_1090 ;
V_1084 = F_268 ( V_1090 ) ;
}
F_768 ( V_10 , & V_77 -> V_8 , 0 ,
& V_1091 ,
V_1083 , V_1084 ,
V_1057 ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
if ( ! V_10 -> V_889 . V_1092 )
V_10 -> V_889 . V_1092 =
F_769 ( V_10 ,
F_213 ( V_1072 ) |
F_213 ( V_335 ) ) ;
if ( V_10 -> V_889 . V_1092 )
F_770 ( & V_77 -> V_8 . V_8 ,
V_10 -> V_889 . V_1092 ,
V_107 -> V_8 . V_334 ) ;
}
F_771 ( & V_77 -> V_8 , & V_1093 ) ;
return & V_77 -> V_8 ;
}
static int
F_772 ( struct V_250 * V_151 ,
struct V_1062 * V_107 )
{
struct V_75 * V_29 = V_107 -> V_8 . V_29 ;
struct V_9 * V_10 = V_151 -> V_10 ;
struct V_260 * V_78 = V_107 -> V_8 . V_78 ;
struct V_1063 * V_1064 = & V_107 -> V_1065 ;
struct V_1063 * V_1066 = & V_107 -> V_1066 ;
const struct V_1063 * V_1067 = & V_107 -> V_1067 ;
struct V_263 * V_264 = F_176 ( V_78 ) ;
struct V_28 * V_28 ;
unsigned V_312 ;
int V_266 ;
V_29 = V_29 ? V_29 : V_151 -> V_29 ;
V_28 = F_37 ( V_29 ) ;
V_266 = F_755 ( V_151 , V_29 , V_78 ,
V_1066 , V_1064 , V_1067 ,
V_1068 ,
V_1068 ,
true , true , & V_107 -> V_1069 ) ;
if ( V_266 )
return V_266 ;
if ( ! V_264 )
goto V_1094;
if ( ! F_581 ( V_10 , V_107 -> V_8 . V_1095 , V_107 -> V_8 . V_1096 ) ) {
F_773 ( L_230 ,
V_107 -> V_8 . V_1095 , V_107 -> V_8 . V_1096 ) ;
return - V_272 ;
}
V_312 = F_576 ( V_107 -> V_8 . V_1095 ) * 4 ;
if ( V_264 -> V_8 . V_311 < V_312 * V_107 -> V_8 . V_1096 ) {
F_142 ( L_231 ) ;
return - V_459 ;
}
F_54 ( & V_10 -> V_267 ) ;
if ( ! F_43 ( V_10 ) -> V_1060 && V_264 -> V_268 ) {
F_142 ( L_232 ) ;
V_266 = - V_272 ;
}
F_56 ( & V_10 -> V_267 ) ;
V_1094:
if ( V_28 -> V_76 ) {
if ( V_28 -> V_854 != V_107 -> V_8 . V_1095 )
V_28 -> V_1070 . V_1079 = true ;
V_28 -> V_1070 . V_1074 |=
F_750 ( V_28 -> V_4 ) ;
}
return V_266 ;
}
static void
F_774 ( struct V_250 * V_151 ,
struct V_1062 * V_107 )
{
struct V_75 * V_29 = V_107 -> V_8 . V_29 ;
struct V_9 * V_10 = V_151 -> V_10 ;
struct V_28 * V_28 ;
struct V_465 * V_465 = F_329 ( V_151 ) ;
struct V_263 * V_264 = F_176 ( V_107 -> V_8 . V_78 ) ;
T_4 V_974 ;
V_29 = V_29 ? V_29 : V_151 -> V_29 ;
V_28 = F_37 ( V_29 ) ;
V_151 -> V_78 = V_107 -> V_8 . V_78 ;
V_29 -> V_870 = V_107 -> V_8 . V_1097 ;
V_29 -> V_871 = V_107 -> V_8 . V_1098 ;
V_465 -> V_264 = V_264 ;
if ( V_28 -> V_1099 == V_264 )
goto V_1100;
if ( ! V_264 )
V_974 = 0 ;
else if ( ! F_43 ( V_10 ) -> V_1060 )
V_974 = F_204 ( V_264 ) ;
else
V_974 = V_264 -> V_1101 -> V_1102 ;
V_28 -> V_872 = V_974 ;
V_28 -> V_1099 = V_264 ;
V_1100:
V_28 -> V_854 = V_107 -> V_8 . V_1095 ;
V_28 -> V_855 = V_107 -> V_8 . V_1096 ;
if ( V_28 -> V_76 )
F_345 ( V_29 , V_107 -> V_1069 ) ;
}
static struct V_250 * F_775 ( struct V_9 * V_10 ,
int V_4 )
{
struct V_465 * V_868 ;
struct V_1062 * V_107 ;
V_868 = F_512 ( sizeof( * V_868 ) , V_457 ) ;
if ( V_868 == NULL )
return NULL ;
V_107 = F_766 ( & V_868 -> V_8 ) ;
if ( ! V_107 ) {
F_202 ( V_868 ) ;
return NULL ;
}
V_868 -> V_8 . V_107 = & V_107 -> V_8 ;
V_868 -> V_1085 = false ;
V_868 -> V_1086 = 1 ;
V_868 -> V_4 = V_4 ;
V_868 -> V_151 = V_4 ;
V_868 -> V_1087 = F_772 ;
V_868 -> V_1088 = F_774 ;
F_768 ( V_10 , & V_868 -> V_8 , 0 ,
& V_1091 ,
V_1103 ,
F_268 ( V_1103 ) ,
V_1058 ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
if ( ! V_10 -> V_889 . V_1092 )
V_10 -> V_889 . V_1092 =
F_769 ( V_10 ,
F_213 ( V_1072 ) |
F_213 ( V_335 ) ) ;
if ( V_10 -> V_889 . V_1092 )
F_770 ( & V_868 -> V_8 . V_8 ,
V_10 -> V_889 . V_1092 ,
V_107 -> V_8 . V_334 ) ;
}
F_771 ( & V_868 -> V_8 , & V_1093 ) ;
return & V_868 -> V_8 ;
}
static void F_776 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 ;
struct V_198 * V_452 = NULL ;
struct V_250 * V_77 = NULL ;
struct V_250 * V_868 = NULL ;
int V_153 , V_266 ;
V_28 = F_512 ( sizeof( * V_28 ) , V_457 ) ;
if ( V_28 == NULL )
return;
V_452 = F_512 ( sizeof( * V_452 ) , V_457 ) ;
if ( ! V_452 )
goto V_898;
F_614 ( V_28 , V_452 ) ;
V_77 = F_765 ( V_10 , V_4 ) ;
if ( ! V_77 )
goto V_898;
V_868 = F_775 ( V_10 , V_4 ) ;
if ( ! V_868 )
goto V_898;
V_266 = F_777 ( V_10 , & V_28 -> V_8 , V_77 ,
V_868 , & V_1104 ) ;
if ( V_266 )
goto V_898;
F_778 ( & V_28 -> V_8 , 256 ) ;
for ( V_153 = 0 ; V_153 < 256 ; V_153 ++ ) {
V_28 -> V_478 [ V_153 ] = V_153 ;
V_28 -> V_479 [ V_153 ] = V_153 ;
V_28 -> V_480 [ V_153 ] = V_153 ;
}
V_28 -> V_4 = V_4 ;
V_28 -> V_151 = V_4 ;
if ( F_767 ( V_10 ) && F_43 ( V_10 ) -> V_91 < 4 ) {
F_142 ( L_233 ) ;
V_28 -> V_151 = ! V_4 ;
}
V_28 -> V_859 = ~ 0 ;
V_28 -> V_858 = ~ 0 ;
V_28 -> V_860 = ~ 0 ;
F_116 ( V_4 >= F_268 ( V_12 -> V_931 ) ||
V_12 -> V_931 [ V_28 -> V_151 ] != NULL ) ;
V_12 -> V_931 [ V_28 -> V_151 ] = & V_28 -> V_8 ;
V_12 -> V_83 [ V_28 -> V_4 ] = & V_28 -> V_8 ;
F_672 ( & V_28 -> V_967 . V_408 , F_656 ) ;
F_779 ( & V_28 -> V_8 , & V_1105 ) ;
F_3 ( F_780 ( & V_28 -> V_8 ) != V_28 -> V_4 ) ;
return;
V_898:
if ( V_77 )
F_764 ( V_77 ) ;
if ( V_868 )
F_764 ( V_868 ) ;
F_202 ( V_452 ) ;
F_202 ( V_28 ) ;
}
enum V_4 F_781 ( struct V_2 * V_3 )
{
struct V_560 * V_6 = V_3 -> V_8 . V_6 ;
struct V_9 * V_10 = V_3 -> V_8 . V_10 ;
F_3 ( ! F_782 ( & V_10 -> V_889 . V_890 ) ) ;
if ( ! V_6 || F_3 ( ! V_6 -> V_29 ) )
return V_1106 ;
return F_37 ( V_6 -> V_29 ) -> V_4 ;
}
int F_783 ( struct V_9 * V_10 , void * V_1107 ,
struct V_1108 * V_1109 )
{
struct V_1110 * V_1111 = V_1107 ;
struct V_75 * V_1112 ;
struct V_28 * V_29 ;
if ( ! F_784 ( V_10 , V_1113 ) )
return - V_954 ;
V_1112 = F_785 ( V_10 , V_1111 -> V_1114 ) ;
if ( ! V_1112 ) {
F_121 ( L_234 ) ;
return - V_1115 ;
}
V_29 = F_37 ( V_1112 ) ;
V_1111 -> V_4 = V_29 -> V_4 ;
return 0 ;
}
static int F_786 ( struct V_1 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_8 . V_10 ;
struct V_1 * V_994 ;
int V_1116 = 0 ;
int V_1117 = 0 ;
F_13 (dev, source_encoder) {
if ( F_688 ( V_6 , V_994 ) )
V_1116 |= ( 1 << V_1117 ) ;
V_1117 ++ ;
}
return V_1116 ;
}
static bool F_787 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_117 ( V_10 ) )
return false ;
if ( ( F_5 ( V_1118 ) & V_1119 ) == 0 )
return false ;
if ( F_7 ( V_10 ) && ( F_5 ( V_1120 ) & V_1121 ) )
return false ;
return true ;
}
static bool F_788 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_43 ( V_10 ) -> V_91 >= 9 )
return false ;
if ( F_789 ( V_10 ) || F_790 ( V_10 ) )
return false ;
if ( F_20 ( V_10 ) )
return false ;
if ( F_21 ( V_10 ) && ! V_12 -> V_612 . V_1122 )
return false ;
return true ;
}
static void F_791 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
struct V_556 * V_3 ;
bool V_1123 = false ;
F_792 ( V_10 ) ;
if ( F_788 ( V_10 ) )
F_793 ( V_10 ) ;
if ( F_60 ( V_10 ) ) {
int V_69 ;
V_69 = F_5 ( V_1124 ) & V_1125 ;
if ( V_69 )
F_794 ( V_10 , V_499 ) ;
V_69 = F_5 ( V_1126 ) ;
if ( V_69 & V_1127 )
F_794 ( V_10 , V_96 ) ;
if ( V_69 & V_1128 )
F_794 ( V_10 , V_98 ) ;
if ( V_69 & V_1129 )
F_794 ( V_10 , V_100 ) ;
} else if ( F_4 ( V_10 ) ) {
int V_69 ;
V_1123 = F_795 ( V_10 , V_100 ) ;
if ( F_787 ( V_10 ) )
F_796 ( V_10 , V_1118 , V_499 ) ;
if ( F_5 ( V_191 ) & V_1130 ) {
V_69 = F_797 ( V_10 , V_1131 , true ) ;
if ( ! V_69 )
F_798 ( V_10 , V_191 , V_96 ) ;
if ( ! V_69 && ( F_5 ( V_184 ) & V_1119 ) )
F_796 ( V_10 , V_184 , V_96 ) ;
}
if ( F_5 ( V_192 ) & V_1130 )
F_798 ( V_10 , V_192 , V_98 ) ;
if ( ! V_1123 && F_5 ( V_193 ) & V_1130 )
F_798 ( V_10 , V_193 , V_100 ) ;
if ( F_5 ( V_186 ) & V_1119 )
F_796 ( V_10 , V_186 , V_98 ) ;
if ( F_5 ( V_188 ) & V_1119 )
F_796 ( V_10 , V_188 , V_100 ) ;
} else if ( F_21 ( V_10 ) ) {
if ( F_5 ( V_1132 + V_1133 ) & V_1130 &&
! F_795 ( V_10 , V_96 ) )
F_798 ( V_10 , V_1132 + V_1133 ,
V_96 ) ;
if ( F_5 ( V_1132 + V_1134 ) & V_1119 ||
F_795 ( V_10 , V_96 ) )
F_796 ( V_10 , V_1132 + V_1134 , V_96 ) ;
if ( F_5 ( V_1132 + V_1135 ) & V_1130 &&
! F_795 ( V_10 , V_98 ) )
F_798 ( V_10 , V_1132 + V_1135 ,
V_98 ) ;
if ( F_5 ( V_1132 + V_1136 ) & V_1119 ||
F_795 ( V_10 , V_98 ) )
F_796 ( V_10 , V_1132 + V_1136 , V_98 ) ;
if ( F_20 ( V_10 ) ) {
if ( F_5 ( V_1132 + V_1137 ) & V_1130 )
F_798 ( V_10 , V_1132 + V_1137 ,
V_100 ) ;
if ( F_5 ( V_1132 + V_1138 ) & V_1119 )
F_796 ( V_10 , V_1132 + V_1138 , V_100 ) ;
}
F_799 ( V_10 ) ;
} else if ( F_800 ( V_10 ) ) {
bool V_69 = false ;
if ( F_5 ( V_1139 ) & V_1130 ) {
F_142 ( L_235 ) ;
V_69 = F_797 ( V_10 , V_1139 , true ) ;
if ( ! V_69 && F_801 ( V_10 ) ) {
F_142 ( L_236 ) ;
F_798 ( V_10 , V_1133 , V_96 ) ;
}
if ( ! V_69 && F_802 ( V_10 ) )
F_796 ( V_10 , V_1134 , V_96 ) ;
}
if ( F_5 ( V_1139 ) & V_1130 ) {
F_142 ( L_237 ) ;
V_69 = F_797 ( V_10 , V_1140 , false ) ;
}
if ( ! V_69 && ( F_5 ( V_1140 ) & V_1130 ) ) {
if ( F_801 ( V_10 ) ) {
F_142 ( L_238 ) ;
F_798 ( V_10 , V_1135 , V_98 ) ;
}
if ( F_802 ( V_10 ) )
F_796 ( V_10 , V_1136 , V_98 ) ;
}
if ( F_802 ( V_10 ) &&
( F_5 ( V_1138 ) & V_1119 ) )
F_796 ( V_10 , V_1138 , V_100 ) ;
} else if ( F_22 ( V_10 ) )
F_803 ( V_10 ) ;
if ( F_804 ( V_10 ) )
F_805 ( V_10 ) ;
if ( F_784 ( V_10 , V_1141 ) ) {
F_428 (connector,
&dev->mode_config.connector_list,
head) {
if ( ! F_3 ( V_3 -> V_107 ) ) {
V_3 -> V_107 =
F_512 ( sizeof( * V_3 -> V_107 ) ,
V_457 ) ;
}
}
}
F_806 ( V_10 ) ;
F_13 (dev, encoder) {
V_6 -> V_8 . V_894 = V_6 -> V_224 ;
V_6 -> V_8 . V_1142 =
F_786 ( V_6 ) ;
}
F_523 ( V_10 ) ;
F_807 ( V_10 ) ;
}
static void F_808 ( struct V_260 * V_78 )
{
struct V_9 * V_10 = V_78 -> V_10 ;
struct V_338 * V_339 = F_196 ( V_78 ) ;
F_809 ( V_78 ) ;
F_54 ( & V_10 -> V_267 ) ;
F_3 ( ! V_339 -> V_264 -> V_1143 -- ) ;
F_198 ( & V_339 -> V_264 -> V_8 ) ;
F_56 ( & V_10 -> V_267 ) ;
F_202 ( V_339 ) ;
}
static int F_810 ( struct V_260 * V_78 ,
struct V_1108 * V_1109 ,
unsigned int * V_1144 )
{
struct V_338 * V_339 = F_196 ( V_78 ) ;
struct V_263 * V_264 = V_339 -> V_264 ;
return F_811 ( V_1109 , & V_264 -> V_8 , V_1144 ) ;
}
static int F_195 ( struct V_9 * V_10 ,
struct V_338 * V_339 ,
struct V_306 * V_307 ,
struct V_263 * V_264 )
{
int V_728 ;
int V_1145 ;
int V_266 ;
F_3 ( ! F_177 ( & V_10 -> V_267 ) ) ;
if ( V_264 -> V_268 == V_271 ) {
F_773 ( L_239 ) ;
return - V_272 ;
}
if ( V_307 -> V_313 [ 0 ] & 63 ) {
F_773 ( L_240 ,
V_307 -> V_313 [ 0 ] ) ;
return - V_272 ;
}
if ( F_43 ( V_10 ) -> V_91 >= 5 && ! F_21 ( V_10 ) ) {
V_1145 = 32 * 1024 ;
} else if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
if ( V_264 -> V_268 )
V_1145 = 16 * 1024 ;
else
V_1145 = 32 * 1024 ;
} else if ( F_43 ( V_10 ) -> V_91 >= 3 ) {
if ( V_264 -> V_268 )
V_1145 = 8 * 1024 ;
else
V_1145 = 16 * 1024 ;
} else
V_1145 = 8 * 1024 ;
if ( V_307 -> V_313 [ 0 ] > V_1145 ) {
F_773 ( L_241 ,
V_264 -> V_268 ? L_242 : L_243 ,
V_307 -> V_313 [ 0 ] , V_1145 ) ;
return - V_272 ;
}
if ( V_264 -> V_268 != V_269 &&
V_307 -> V_313 [ 0 ] != V_264 -> V_312 ) {
F_773 ( L_244 ,
V_307 -> V_313 [ 0 ] , V_264 -> V_312 ) ;
return - V_272 ;
}
switch ( V_307 -> V_314 ) {
case V_284 :
case V_288 :
case V_290 :
case V_302 :
break;
case V_286 :
case V_328 :
if ( F_43 ( V_10 ) -> V_91 > 3 ) {
F_773 ( L_245 ,
F_812 ( V_307 -> V_314 ) ) ;
return - V_272 ;
}
break;
case V_292 :
case V_301 :
case V_294 :
case V_329 :
case V_296 :
case V_330 :
if ( F_43 ( V_10 ) -> V_91 < 4 ) {
F_773 ( L_245 ,
F_812 ( V_307 -> V_314 ) ) ;
return - V_272 ;
}
break;
case V_1146 :
case V_1147 :
case V_1148 :
case V_1149 :
if ( F_43 ( V_10 ) -> V_91 < 5 ) {
F_773 ( L_245 ,
F_812 ( V_307 -> V_314 ) ) ;
return - V_272 ;
}
break;
default:
F_773 ( L_245 ,
F_812 ( V_307 -> V_314 ) ) ;
return - V_272 ;
}
if ( V_307 -> V_981 [ 0 ] != 0 )
return - V_272 ;
V_728 = F_173 ( V_10 , V_307 -> V_257 ,
V_264 -> V_268 ) ;
if ( V_264 -> V_8 . V_311 < V_728 * V_307 -> V_313 [ 0 ] )
return - V_272 ;
F_813 ( & V_339 -> V_8 , V_307 ) ;
V_339 -> V_264 = V_264 ;
V_339 -> V_264 -> V_1143 ++ ;
V_266 = F_814 ( V_10 , & V_339 -> V_8 , & V_1150 ) ;
if ( V_266 ) {
F_121 ( L_246 , V_266 ) ;
return V_266 ;
}
return 0 ;
}
static struct V_260 *
F_815 ( struct V_9 * V_10 ,
struct V_1108 * V_1151 ,
struct V_306 * V_307 )
{
struct V_263 * V_264 ;
V_264 = F_816 ( F_817 ( V_10 , V_1151 ,
V_307 -> V_1152 [ 0 ] ) ) ;
if ( & V_264 -> V_8 == NULL )
return F_584 ( - V_1115 ) ;
return F_585 ( V_10 , V_307 , V_264 ) ;
}
static inline void F_818 ( struct V_9 * V_10 )
{
}
static void F_819 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_4 ( V_10 ) || F_18 ( V_10 ) )
V_12 -> V_252 . V_720 = F_32 ;
else if ( F_20 ( V_10 ) )
V_12 -> V_252 . V_720 = F_35 ;
else if ( F_21 ( V_10 ) )
V_12 -> V_252 . V_720 = F_33 ;
else if ( F_19 ( V_10 ) )
V_12 -> V_252 . V_720 = F_31 ;
else
V_12 -> V_252 . V_720 = F_30 ;
if ( F_43 ( V_10 ) -> V_91 >= 9 ) {
V_12 -> V_252 . V_1028 = F_574 ;
V_12 -> V_252 . V_1153 =
F_549 ;
V_12 -> V_252 . V_1034 =
F_567 ;
V_12 -> V_252 . V_554 = F_363 ;
V_12 -> V_252 . V_351 = F_377 ;
V_12 -> V_252 . V_557 = F_381 ;
V_12 -> V_252 . V_253 =
F_220 ;
} else if ( F_60 ( V_10 ) ) {
V_12 -> V_252 . V_1028 = F_574 ;
V_12 -> V_252 . V_1153 =
F_552 ;
V_12 -> V_252 . V_1034 =
F_567 ;
V_12 -> V_252 . V_554 = F_363 ;
V_12 -> V_252 . V_351 = F_377 ;
V_12 -> V_252 . V_557 = F_381 ;
V_12 -> V_252 . V_253 =
F_217 ;
} else if ( F_4 ( V_10 ) ) {
V_12 -> V_252 . V_1028 = F_553 ;
V_12 -> V_252 . V_1153 =
F_552 ;
V_12 -> V_252 . V_1034 =
F_542 ;
V_12 -> V_252 . V_554 = F_351 ;
V_12 -> V_252 . V_351 = F_375 ;
V_12 -> V_252 . V_557 = F_381 ;
V_12 -> V_252 . V_253 =
F_217 ;
} else if ( F_21 ( V_10 ) ) {
V_12 -> V_252 . V_1028 = F_514 ;
V_12 -> V_252 . V_1153 =
F_511 ;
V_12 -> V_252 . V_1034 = F_508 ;
V_12 -> V_252 . V_554 = F_410 ;
V_12 -> V_252 . V_351 = F_422 ;
V_12 -> V_252 . V_557 = F_424 ;
V_12 -> V_252 . V_253 =
F_206 ;
} else {
V_12 -> V_252 . V_1028 = F_514 ;
V_12 -> V_252 . V_1153 =
F_511 ;
V_12 -> V_252 . V_1034 = F_508 ;
V_12 -> V_252 . V_554 = F_420 ;
V_12 -> V_252 . V_351 = F_422 ;
V_12 -> V_252 . V_557 = F_424 ;
V_12 -> V_252 . V_253 =
F_206 ;
}
if ( F_21 ( V_10 ) )
V_12 -> V_252 . V_523 =
F_446 ;
else if ( F_501 ( V_10 ) || ( F_503 ( V_10 ) && ! F_820 ( V_10 ) ) )
V_12 -> V_252 . V_523 =
F_447 ;
else if ( F_445 ( V_10 ) )
V_12 -> V_252 . V_523 =
F_448 ;
else if ( F_502 ( V_10 ) || F_71 ( V_10 ) )
V_12 -> V_252 . V_523 =
F_449 ;
else if ( F_19 ( V_10 ) )
V_12 -> V_252 . V_523 =
F_450 ;
else if ( F_821 ( V_10 ) )
V_12 -> V_252 . V_523 =
F_452 ;
else if ( F_72 ( V_10 ) )
V_12 -> V_252 . V_523 =
F_453 ;
else if ( F_822 ( V_10 ) )
V_12 -> V_252 . V_523 =
F_454 ;
else
V_12 -> V_252 . V_523 =
F_455 ;
if ( F_7 ( V_10 ) ) {
V_12 -> V_252 . V_435 = F_259 ;
} else if ( F_266 ( V_10 ) ) {
V_12 -> V_252 . V_435 = F_264 ;
} else if ( F_256 ( V_10 ) ) {
V_12 -> V_252 . V_435 = F_267 ;
V_12 -> V_252 . V_516 =
F_258 ;
} else if ( F_218 ( V_10 ) || F_168 ( V_10 ) ) {
V_12 -> V_252 . V_435 = V_1154 ;
} else if ( F_21 ( V_10 ) ) {
V_12 -> V_252 . V_516 =
F_409 ;
}
V_12 -> V_252 . V_987 = F_661 ;
switch ( F_43 ( V_10 ) -> V_91 ) {
case 2 :
V_12 -> V_252 . V_987 = F_635 ;
break;
case 3 :
V_12 -> V_252 . V_987 = F_640 ;
break;
case 4 :
case 5 :
V_12 -> V_252 . V_987 = F_641 ;
break;
case 6 :
V_12 -> V_252 . V_987 = F_642 ;
break;
case 7 :
case 8 :
V_12 -> V_252 . V_987 = F_643 ;
break;
case 9 :
V_12 -> V_252 . V_987 = F_660 ;
break;
}
F_823 ( V_10 ) ;
F_824 ( & V_12 -> V_1155 ) ;
}
static void F_825 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_147 |= V_148 ;
F_826 ( L_247 ) ;
}
static void F_827 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_147 |= V_149 ;
F_826 ( L_248 ) ;
}
static void F_828 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_147 |= V_614 ;
F_826 ( L_249 ) ;
}
static void F_829 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_147 |= V_1156 ;
F_826 ( L_250 ) ;
}
static void F_830 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_147 |= V_1157 ;
F_826 ( L_251 ) ;
}
static int F_831 ( const struct V_1158 * V_227 )
{
F_826 ( L_252 , V_227 -> V_1159 ) ;
return 1 ;
}
static void F_832 ( struct V_9 * V_10 )
{
struct V_1160 * V_1161 = V_10 -> V_577 ;
int V_153 ;
for ( V_153 = 0 ; V_153 < F_268 ( V_1162 ) ; V_153 ++ ) {
struct V_1163 * V_1164 = & V_1162 [ V_153 ] ;
if ( V_1161 -> V_1165 == V_1164 -> V_1165 &&
( V_1161 -> V_1166 == V_1164 -> V_1166 ||
V_1164 -> V_1166 == V_1167 ) &&
( V_1161 -> V_1168 == V_1164 -> V_1168 ||
V_1164 -> V_1168 == V_1167 ) )
V_1164 -> V_1169 ( V_10 ) ;
}
for ( V_153 = 0 ; V_153 < F_268 ( V_1170 ) ; V_153 ++ ) {
if ( F_833 ( * V_1170 [ V_153 ] . V_1171 ) != 0 )
V_1170 [ V_153 ] . V_1169 ( V_10 ) ;
}
}
static void F_834 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_9 V_1172 ;
T_1 V_1173 = F_835 ( V_10 ) ;
F_836 ( V_10 -> V_577 , V_1174 ) ;
F_837 ( V_1175 , V_1176 ) ;
V_1172 = F_838 ( V_1177 ) ;
F_837 ( V_1172 | 1 << 5 , V_1177 ) ;
F_839 ( V_10 -> V_577 , V_1174 ) ;
F_120 ( 300 ) ;
F_118 ( V_1173 , V_1178 ) ;
F_119 ( V_1173 ) ;
}
void F_239 ( struct V_9 * V_10 )
{
F_566 ( V_10 ) ;
if ( F_21 ( V_10 ) )
F_396 ( V_10 ) ;
F_840 ( V_10 ) ;
F_841 ( V_10 ) ;
}
void F_842 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_157 , V_266 ;
enum V_4 V_4 ;
struct V_28 * V_29 ;
F_843 ( V_10 ) ;
V_10 -> V_889 . V_1179 = 0 ;
V_10 -> V_889 . V_1180 = 0 ;
V_10 -> V_889 . V_1181 = 24 ;
V_10 -> V_889 . V_1182 = 1 ;
V_10 -> V_889 . V_466 = & V_1183 ;
F_832 ( V_10 ) ;
F_844 ( V_10 ) ;
if ( F_43 ( V_10 ) -> V_563 == 0 )
return;
F_819 ( V_10 ) ;
F_845 ( V_10 ) ;
if ( F_22 ( V_10 ) ) {
V_10 -> V_889 . V_1184 = 2048 ;
V_10 -> V_889 . V_1185 = 2048 ;
} else if ( F_846 ( V_10 ) ) {
V_10 -> V_889 . V_1184 = 4096 ;
V_10 -> V_889 . V_1185 = 4096 ;
} else {
V_10 -> V_889 . V_1184 = 8192 ;
V_10 -> V_889 . V_1185 = 8192 ;
}
if ( F_71 ( V_10 ) || F_72 ( V_10 ) ) {
V_10 -> V_889 . V_854 = F_71 ( V_10 ) ? 64 : 512 ;
V_10 -> V_889 . V_855 = 1023 ;
} else if ( F_22 ( V_10 ) ) {
V_10 -> V_889 . V_854 = V_1186 ;
V_10 -> V_889 . V_855 = V_1187 ;
} else {
V_10 -> V_889 . V_854 = V_1188 ;
V_10 -> V_889 . V_855 = V_1189 ;
}
V_10 -> V_889 . V_1190 = V_12 -> V_1191 . V_1192 ;
F_142 ( L_253 ,
F_43 ( V_10 ) -> V_563 ,
F_43 ( V_10 ) -> V_563 > 1 ? L_254 : L_255 ) ;
F_81 (dev_priv, pipe) {
F_776 ( V_10 , V_4 ) ;
F_83 (pipe, sprite) {
V_266 = F_847 ( V_10 , V_4 , V_157 ) ;
if ( V_266 )
F_142 ( L_256 ,
F_69 ( V_4 ) , F_86 ( V_4 , V_157 ) , V_266 ) ;
}
}
F_112 ( V_10 ) ;
F_747 ( V_10 ) ;
F_834 ( V_10 ) ;
F_791 ( V_10 ) ;
F_350 ( V_10 ) ;
F_235 ( V_10 ) ;
F_242 ( V_10 , false ) ;
F_244 ( V_10 ) ;
F_129 (dev, crtc) {
if ( ! V_29 -> V_76 )
continue;
if ( V_12 -> V_252 . V_1153 ) {
V_12 -> V_252 . V_1153 ( V_29 ,
& V_29 -> V_305 ) ;
F_201 ( V_29 , & V_29 -> V_305 ) ;
}
}
}
static void F_848 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
struct V_556 * V_1193 = NULL ;
struct V_883 V_893 ;
struct V_885 * V_886 = V_10 -> V_889 . V_1194 ;
F_428 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_6 -> type == V_42 ) {
V_1193 = & V_3 -> V_8 ;
break;
}
}
if ( ! V_1193 )
return;
if ( F_595 ( V_1193 , NULL , & V_893 , V_886 ) )
F_601 ( V_1193 , & V_893 ) ;
}
static bool
F_849 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_85 , V_108 ;
if ( F_43 ( V_10 ) -> V_563 == 1 )
return true ;
V_85 = F_78 ( ! V_29 -> V_151 ) ;
V_108 = F_5 ( V_85 ) ;
if ( ( V_108 & V_152 ) &&
( ! ! ( V_108 & V_155 ) == V_29 -> V_4 ) )
return false ;
return true ;
}
static void F_850 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_85 ;
V_85 = F_44 ( V_29 -> V_79 -> V_84 ) ;
F_118 ( V_85 , F_5 ( V_85 ) & ~ V_1195 ) ;
if ( V_29 -> V_76 ) {
F_718 ( V_29 ) ;
F_851 ( V_10 , V_29 -> V_4 ) ;
} else
F_852 ( V_10 , V_29 -> V_4 ) ;
if ( F_43 ( V_10 ) -> V_91 < 4 && ! F_849 ( V_29 ) ) {
struct V_2 * V_3 ;
bool V_151 ;
F_142 ( L_257 ,
V_29 -> V_8 . V_8 . V_227 ) ;
V_151 = V_29 -> V_151 ;
V_29 -> V_151 = ! V_151 ;
V_29 -> V_251 = true ;
V_12 -> V_252 . V_351 ( & V_29 -> V_8 ) ;
V_29 -> V_151 = V_151 ;
F_428 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
V_3 -> V_8 . V_558 = V_559 ;
V_3 -> V_8 . V_6 = NULL ;
}
F_428 (connector, &dev->mode_config.connector_list,
base.head)
if ( V_3 -> V_6 -> V_8 . V_29 == & V_29 -> V_8 ) {
V_3 -> V_6 -> V_8 . V_29 = NULL ;
V_3 -> V_6 -> V_555 = false ;
}
F_3 ( V_29 -> V_76 ) ;
V_29 -> V_8 . V_106 = false ;
}
if ( V_12 -> V_147 & V_148 &&
V_29 -> V_4 == V_129 && ! V_29 -> V_76 ) {
F_848 ( V_10 ) ;
}
F_426 ( & V_29 -> V_8 ) ;
if ( V_29 -> V_76 != V_29 -> V_8 . V_106 ) {
struct V_1 * V_6 ;
F_142 ( L_258 ,
V_29 -> V_8 . V_8 . V_227 ,
V_29 -> V_8 . V_106 ? L_170 : L_171 ,
V_29 -> V_76 ? L_170 : L_171 ) ;
V_29 -> V_8 . V_106 = V_29 -> V_76 ;
F_3 ( V_29 -> V_76 ) ;
F_11 (dev, &crtc->base, encoder) {
F_3 ( V_6 -> V_555 ) ;
V_6 -> V_8 . V_29 = NULL ;
}
}
if ( V_29 -> V_76 || F_339 ( V_10 ) ) {
V_29 -> V_1196 = true ;
V_29 -> V_1197 = true ;
}
}
static void F_853 ( struct V_1 * V_6 )
{
struct V_2 * V_3 ;
struct V_9 * V_10 = V_6 -> V_8 . V_10 ;
bool V_1198 = V_6 -> V_8 . V_29 &&
F_37 ( V_6 -> V_8 . V_29 ) -> V_76 ;
if ( V_6 -> V_555 && ! V_1198 ) {
F_142 ( L_259 ,
V_6 -> V_8 . V_8 . V_227 ,
V_6 -> V_8 . V_121 ) ;
if ( V_6 -> V_8 . V_29 ) {
F_142 ( L_260 ,
V_6 -> V_8 . V_8 . V_227 ,
V_6 -> V_8 . V_121 ) ;
V_6 -> V_230 ( V_6 ) ;
if ( V_6 -> V_490 )
V_6 -> V_490 ( V_6 ) ;
}
V_6 -> V_8 . V_29 = NULL ;
V_6 -> V_555 = false ;
F_428 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_6 != V_6 )
continue;
V_3 -> V_8 . V_558 = V_559 ;
V_3 -> V_8 . V_6 = NULL ;
}
}
}
void F_854 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_1173 = F_835 ( V_10 ) ;
if ( ! ( F_5 ( V_1173 ) & V_1178 ) ) {
F_142 ( L_261 ) ;
F_834 ( V_10 ) ;
}
}
void F_855 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_75 ( V_12 , V_1199 ) )
return;
F_854 ( V_10 ) ;
}
static bool F_856 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
if ( ! V_29 -> V_76 )
return false ;
return F_5 ( F_78 ( V_29 -> V_151 ) ) & V_152 ;
}
static void F_857 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
int V_153 ;
F_129 (dev, crtc) {
memset ( V_29 -> V_79 , 0 , sizeof( * V_29 -> V_79 ) ) ;
V_29 -> V_79 -> V_147 |= V_1012 ;
V_29 -> V_76 = V_12 -> V_252 . V_1028 ( V_29 ,
V_29 -> V_79 ) ;
V_29 -> V_8 . V_106 = V_29 -> V_76 ;
V_29 -> V_251 = F_856 ( V_29 ) ;
F_142 ( L_262 ,
V_29 -> V_8 . V_8 . V_227 ,
V_29 -> V_76 ? L_170 : L_171 ) ;
}
for ( V_153 = 0 ; V_153 < V_12 -> V_455 ; V_153 ++ ) {
struct V_114 * V_117 = & V_12 -> V_116 [ V_153 ] ;
V_117 -> V_225 = V_117 -> V_120 ( V_12 , V_117 ,
& V_117 -> V_79 . V_119 ) ;
V_117 -> V_76 = 0 ;
V_117 -> V_79 . V_224 = 0 ;
F_129 (dev, crtc) {
if ( V_29 -> V_76 && F_57 ( V_29 ) == V_117 ) {
V_117 -> V_76 ++ ;
V_117 -> V_79 . V_224 |= 1 << V_29 -> V_4 ;
}
}
F_142 ( L_263 ,
V_117 -> V_121 , V_117 -> V_79 . V_224 , V_117 -> V_225 ) ;
if ( V_117 -> V_79 . V_224 )
F_144 ( V_12 , V_228 ) ;
}
F_13 (dev, encoder) {
V_4 = 0 ;
if ( V_6 -> V_120 ( V_6 , & V_4 ) ) {
V_29 = F_37 ( V_12 -> V_83 [ V_4 ] ) ;
V_6 -> V_8 . V_29 = & V_29 -> V_8 ;
V_6 -> V_1029 ( V_6 , V_29 -> V_79 ) ;
} else {
V_6 -> V_8 . V_29 = NULL ;
}
V_6 -> V_555 = false ;
F_142 ( L_264 ,
V_6 -> V_8 . V_8 . V_227 ,
V_6 -> V_8 . V_121 ,
V_6 -> V_8 . V_29 ? L_170 : L_171 ,
F_69 ( V_4 ) ) ;
}
F_428 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_120 ( V_3 ) ) {
V_3 -> V_8 . V_558 = V_561 ;
V_3 -> V_6 -> V_555 = true ;
V_3 -> V_8 . V_6 = & V_3 -> V_6 -> V_8 ;
} else {
V_3 -> V_8 . V_558 = V_559 ;
V_3 -> V_8 . V_6 = NULL ;
}
F_142 ( L_265 ,
V_3 -> V_8 . V_8 . V_227 ,
V_3 -> V_8 . V_121 ,
V_3 -> V_8 . V_6 ? L_170 : L_171 ) ;
}
}
void F_242 ( struct V_9 * V_10 ,
bool V_1200 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_6 ;
int V_153 ;
F_857 ( V_10 ) ;
F_129 (dev, crtc) {
if ( V_29 -> V_76 && V_362 . V_363 ) {
F_506 ( & V_29 -> V_8 . V_445 ,
V_29 -> V_79 ) ;
F_142 ( L_266 ,
V_29 -> V_8 . V_8 . V_227 ) ;
F_687 ( & V_29 -> V_8 . V_445 ) ;
}
}
F_13 (dev, encoder) {
F_853 ( V_6 ) ;
}
F_81 (dev_priv, pipe) {
V_29 = F_37 ( V_12 -> V_83 [ V_4 ] ) ;
F_850 ( V_29 ) ;
F_685 ( V_29 , V_29 -> V_79 ,
L_267 ) ;
}
for ( V_153 = 0 ; V_153 < V_12 -> V_455 ; V_153 ++ ) {
struct V_114 * V_117 = & V_12 -> V_116 [ V_153 ] ;
if ( ! V_117 -> V_225 || V_117 -> V_76 )
continue;
F_142 ( L_268 , V_117 -> V_121 ) ;
V_117 -> V_230 ( V_12 , V_117 ) ;
V_117 -> V_225 = false ;
}
if ( F_858 ( V_10 ) )
F_859 ( V_10 ) ;
else if ( F_4 ( V_10 ) )
F_860 ( V_10 ) ;
if ( V_1200 ) {
F_855 ( V_10 ) ;
F_81 (dev_priv, pipe) {
struct V_75 * V_29 =
V_12 -> V_83 [ V_4 ] ;
F_599 ( V_29 , & V_29 -> V_445 , V_29 -> V_254 , V_29 -> V_255 ,
V_29 -> V_77 -> V_78 ) ;
}
} else {
F_680 ( V_10 ) ;
}
F_435 ( V_10 ) ;
}
void F_861 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_318 ;
struct V_263 * V_264 ;
F_54 ( & V_10 -> V_267 ) ;
F_862 ( V_10 ) ;
F_56 ( & V_10 -> V_267 ) ;
if ( F_48 ( V_10 ) || F_94 ( V_10 ) )
V_12 -> V_612 . V_613 = ! ! ( F_5 ( V_162 ) &
V_746 ) ;
F_239 ( V_10 ) ;
F_863 ( V_10 ) ;
F_54 ( & V_10 -> V_267 ) ;
F_203 (dev, c) {
V_264 = F_176 ( V_318 -> V_77 -> V_78 ) ;
if ( V_264 == NULL )
continue;
if ( F_175 ( V_318 -> V_77 ,
V_318 -> V_77 -> V_78 ,
NULL ) ) {
F_121 ( L_269 ,
F_37 ( V_318 ) -> V_4 ) ;
F_603 ( V_318 -> V_77 -> V_78 ) ;
V_318 -> V_77 -> V_78 = NULL ;
F_199 ( V_318 -> V_77 ) ;
}
}
F_56 ( & V_10 -> V_267 ) ;
F_864 ( V_10 ) ;
}
void F_865 ( struct V_2 * V_2 )
{
struct V_556 * V_3 = & V_2 -> V_8 ;
F_866 ( V_3 ) ;
F_867 ( V_3 ) ;
}
void F_868 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_556 * V_3 ;
F_869 ( V_10 ) ;
F_870 ( V_10 ) ;
F_871 ( V_12 ) ;
F_872 ( V_10 ) ;
F_54 ( & V_10 -> V_267 ) ;
F_873 () ;
F_350 ( V_10 ) ;
F_874 ( V_10 ) ;
F_56 ( & V_10 -> V_267 ) ;
F_875 () ;
F_428 (connector, &dev->mode_config.connector_list, head) {
struct V_2 * V_2 ;
V_2 = F_597 ( V_3 ) ;
V_2 -> V_1201 ( V_2 ) ;
}
F_876 ( V_10 ) ;
F_877 ( V_10 ) ;
F_54 ( & V_10 -> V_267 ) ;
F_878 ( V_10 ) ;
F_56 ( & V_10 -> V_267 ) ;
}
struct V_560 * F_879 ( struct V_556 * V_3 )
{
return & F_596 ( V_3 ) -> V_8 ;
}
void F_880 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
V_3 -> V_6 = V_6 ;
F_881 ( & V_3 -> V_8 ,
& V_6 -> V_8 ) ;
}
int F_882 ( struct V_9 * V_10 , bool V_107 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned V_85 = F_43 ( V_10 ) -> V_91 >= 6 ? V_1202 : V_1203 ;
T_5 V_1204 ;
if ( F_451 ( V_12 -> V_1205 , V_85 , & V_1204 ) ) {
F_121 ( L_270 ) ;
return - V_988 ;
}
if ( ! ! ( V_1204 & V_1206 ) == ! V_107 )
return 0 ;
if ( V_107 )
V_1204 &= ~ V_1206 ;
else
V_1204 |= V_1206 ;
if ( F_883 ( V_12 -> V_1205 , V_85 , V_1204 ) ) {
F_121 ( L_271 ) ;
return - V_988 ;
}
return 0 ;
}
struct V_1207 *
F_884 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1207 * error ;
int V_1208 [] = {
V_241 ,
V_1209 ,
V_1210 ,
V_487 ,
} ;
int V_153 ;
if ( F_43 ( V_10 ) -> V_563 == 0 )
return NULL ;
error = F_512 ( sizeof( * error ) , V_1211 ) ;
if ( error == NULL )
return NULL ;
if ( F_218 ( V_10 ) || F_168 ( V_10 ) )
error -> V_1212 = F_5 ( V_793 ) ;
F_81 (dev_priv, i) {
error -> V_4 [ V_153 ] . V_1213 =
F_885 ( V_12 ,
F_390 ( V_153 ) ) ;
if ( ! error -> V_4 [ V_153 ] . V_1213 )
continue;
error -> V_868 [ V_153 ] . V_493 = F_5 ( F_73 ( V_153 ) ) ;
error -> V_868 [ V_153 ] . V_1214 = F_5 ( F_580 ( V_153 ) ) ;
error -> V_868 [ V_153 ] . V_8 = F_5 ( F_579 ( V_153 ) ) ;
error -> V_151 [ V_153 ] . V_493 = F_5 ( F_78 ( V_153 ) ) ;
error -> V_151 [ V_153 ] . V_312 = F_5 ( F_214 ( V_153 ) ) ;
if ( F_43 ( V_10 ) -> V_91 <= 3 ) {
error -> V_151 [ V_153 ] . V_311 = F_5 ( F_208 ( V_153 ) ) ;
error -> V_151 [ V_153 ] . V_462 = F_5 ( F_209 ( V_153 ) ) ;
}
if ( F_43 ( V_10 ) -> V_91 <= 7 && ! F_218 ( V_10 ) )
error -> V_151 [ V_153 ] . V_974 = F_5 ( F_165 ( V_153 ) ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
error -> V_151 [ V_153 ] . V_1215 = F_5 ( F_164 ( V_153 ) ) ;
error -> V_151 [ V_153 ] . V_1216 = F_5 ( F_215 ( V_153 ) ) ;
}
error -> V_4 [ V_153 ] . V_1217 = F_5 ( F_251 ( V_153 ) ) ;
if ( F_339 ( V_10 ) )
error -> V_4 [ V_153 ] . V_1218 = F_5 ( F_886 ( V_153 ) ) ;
}
error -> V_1219 = F_43 ( V_10 ) -> V_563 ;
if ( F_60 ( V_12 -> V_10 ) )
error -> V_1219 ++ ;
for ( V_153 = 0 ; V_153 < error -> V_1219 ; V_153 ++ ) {
enum V_82 V_84 = V_1208 [ V_153 ] ;
error -> V_82 [ V_153 ] . V_1213 =
F_885 ( V_12 ,
F_76 ( V_84 ) ) ;
if ( ! error -> V_82 [ V_153 ] . V_1213 )
continue;
error -> V_82 [ V_153 ] . V_84 = V_84 ;
error -> V_82 [ V_153 ] . V_1220 = F_5 ( F_44 ( V_84 ) ) ;
error -> V_82 [ V_153 ] . V_698 = F_5 ( F_292 ( V_84 ) ) ;
error -> V_82 [ V_153 ] . V_1221 = F_5 ( F_294 ( V_84 ) ) ;
error -> V_82 [ V_153 ] . V_921 = F_5 ( F_296 ( V_84 ) ) ;
error -> V_82 [ V_153 ] . V_700 = F_5 ( F_298 ( V_84 ) ) ;
error -> V_82 [ V_153 ] . V_1222 = F_5 ( F_300 ( V_84 ) ) ;
error -> V_82 [ V_153 ] . V_923 = F_5 ( F_302 ( V_84 ) ) ;
}
return error ;
}
void
F_887 ( struct V_1223 * V_19 ,
struct V_9 * V_10 ,
struct V_1207 * error )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_153 ;
if ( ! error )
return;
F_888 ( V_19 , L_272 , F_43 ( V_10 ) -> V_563 ) ;
if ( F_218 ( V_10 ) || F_168 ( V_10 ) )
F_888 ( V_19 , L_273 ,
error -> V_1212 ) ;
F_81 (dev_priv, i) {
F_888 ( V_19 , L_274 , V_153 ) ;
F_888 ( V_19 , L_275 ,
error -> V_4 [ V_153 ] . V_1213 ? L_11 : L_12 ) ;
F_888 ( V_19 , L_276 , error -> V_4 [ V_153 ] . V_1217 ) ;
F_888 ( V_19 , L_277 , error -> V_4 [ V_153 ] . V_1218 ) ;
F_888 ( V_19 , L_278 , V_153 ) ;
F_888 ( V_19 , L_279 , error -> V_151 [ V_153 ] . V_493 ) ;
F_888 ( V_19 , L_280 , error -> V_151 [ V_153 ] . V_312 ) ;
if ( F_43 ( V_10 ) -> V_91 <= 3 ) {
F_888 ( V_19 , L_281 , error -> V_151 [ V_153 ] . V_311 ) ;
F_888 ( V_19 , L_282 , error -> V_151 [ V_153 ] . V_462 ) ;
}
if ( F_43 ( V_10 ) -> V_91 <= 7 && ! F_218 ( V_10 ) )
F_888 ( V_19 , L_283 , error -> V_151 [ V_153 ] . V_974 ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
F_888 ( V_19 , L_284 , error -> V_151 [ V_153 ] . V_1215 ) ;
F_888 ( V_19 , L_285 , error -> V_151 [ V_153 ] . V_1216 ) ;
}
F_888 ( V_19 , L_286 , V_153 ) ;
F_888 ( V_19 , L_279 , error -> V_868 [ V_153 ] . V_493 ) ;
F_888 ( V_19 , L_282 , error -> V_868 [ V_153 ] . V_1214 ) ;
F_888 ( V_19 , L_287 , error -> V_868 [ V_153 ] . V_8 ) ;
}
for ( V_153 = 0 ; V_153 < error -> V_1219 ; V_153 ++ ) {
F_888 ( V_19 , L_288 ,
F_686 ( error -> V_82 [ V_153 ] . V_84 ) ) ;
F_888 ( V_19 , L_275 ,
error -> V_82 [ V_153 ] . V_1213 ? L_11 : L_12 ) ;
F_888 ( V_19 , L_289 , error -> V_82 [ V_153 ] . V_1220 ) ;
F_888 ( V_19 , L_290 , error -> V_82 [ V_153 ] . V_698 ) ;
F_888 ( V_19 , L_291 , error -> V_82 [ V_153 ] . V_1221 ) ;
F_888 ( V_19 , L_292 , error -> V_82 [ V_153 ] . V_921 ) ;
F_888 ( V_19 , L_293 , error -> V_82 [ V_153 ] . V_700 ) ;
F_888 ( V_19 , L_294 , error -> V_82 [ V_153 ] . V_1222 ) ;
F_888 ( V_19 , L_295 , error -> V_82 [ V_153 ] . V_923 ) ;
}
}
void F_889 ( struct V_9 * V_10 , struct V_1108 * V_1109 )
{
struct V_28 * V_29 ;
F_129 (dev, crtc) {
struct V_407 * V_408 ;
F_240 ( & V_10 -> V_359 ) ;
V_408 = V_29 -> V_360 ;
if ( V_408 && V_408 -> V_409 &&
V_408 -> V_409 -> V_8 . V_1224 == V_1109 ) {
F_202 ( V_408 -> V_409 ) ;
V_408 -> V_409 = NULL ;
}
F_241 ( & V_10 -> V_359 ) ;
}
}
