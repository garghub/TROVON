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
V_28 -> V_79 . V_80 . V_81 ;
}
enum V_82 F_38 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_75 * V_29 = V_12 -> V_83 [ V_4 ] ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
return V_28 -> V_79 . V_84 ;
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
enum V_82 V_84 = V_29 -> V_79 . V_84 ;
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
F_46 ( V_109 != V_107 ,
L_13 ,
F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
static void F_52 ( struct V_11 * V_12 , bool V_107 )
{
T_1 V_108 ;
bool V_109 ;
F_53 ( & V_12 -> V_111 ) ;
V_108 = F_54 ( V_12 , V_112 ) ;
F_55 ( & V_12 -> V_111 ) ;
V_109 = V_108 & V_113 ;
F_46 ( V_109 != V_107 ,
L_14 ,
F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
struct V_114 *
F_56 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
if ( V_29 -> V_79 . V_115 < 0 )
return NULL ;
return & V_12 -> V_116 [ V_29 -> V_79 . V_115 ] ;
}
void F_57 ( struct V_11 * V_12 ,
struct V_114 * V_117 ,
bool V_107 )
{
bool V_109 ;
struct V_118 V_119 ;
if ( F_46 ( ! V_117 ,
L_15 , F_49 ( V_107 ) ) )
return;
V_109 = V_117 -> V_120 ( V_12 , V_117 , & V_119 ) ;
F_46 ( V_109 != V_107 ,
L_16 ,
V_117 -> V_121 , F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
static void F_58 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_107 )
{
int V_85 ;
T_1 V_108 ;
bool V_109 ;
enum V_82 V_84 = F_38 ( V_12 ,
V_4 ) ;
if ( F_59 ( V_12 -> V_10 ) ) {
V_85 = F_60 ( V_84 ) ;
V_108 = F_5 ( V_85 ) ;
V_109 = ! ! ( V_108 & V_122 ) ;
} else {
V_85 = F_61 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_109 = ! ! ( V_108 & V_123 ) ;
}
F_46 ( V_109 != V_107 ,
L_17 ,
F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
static void F_62 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_107 )
{
int V_85 ;
T_1 V_108 ;
bool V_109 ;
V_85 = F_63 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_109 = ! ! ( V_108 & V_124 ) ;
F_46 ( V_109 != V_107 ,
L_18 ,
F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
static void F_64 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_85 ;
T_1 V_108 ;
if ( F_43 ( V_12 -> V_10 ) -> V_91 == 5 )
return;
if ( F_59 ( V_12 -> V_10 ) )
return;
V_85 = F_61 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
F_46 ( ! ( V_108 & V_125 ) , L_19 ) ;
}
void F_65 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_107 )
{
int V_85 ;
T_1 V_108 ;
bool V_109 ;
V_85 = F_63 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_109 = ! ! ( V_108 & V_126 ) ;
F_46 ( V_109 != V_107 ,
L_20 ,
F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
void F_66 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_127 ;
T_1 V_108 ;
enum V_4 V_128 = V_129 ;
bool V_130 = true ;
if ( F_3 ( F_59 ( V_10 ) ) )
return;
if ( F_4 ( V_10 ) ) {
T_1 V_131 ;
V_127 = V_132 ;
V_131 = F_5 ( V_133 ) & V_134 ;
if ( V_131 == V_135 &&
F_5 ( V_136 ) & V_137 )
V_128 = V_138 ;
} else if ( F_21 ( V_10 ) ) {
V_127 = F_67 ( V_4 ) ;
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
F_46 ( V_128 == V_4 && V_130 ,
L_21 ,
F_68 ( V_4 ) ) ;
}
static void F_69 ( struct V_11 * V_12 ,
enum V_4 V_4 , bool V_107 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
bool V_109 ;
if ( F_70 ( V_10 ) || F_71 ( V_10 ) )
V_109 = F_5 ( V_144 ) & V_145 ;
else
V_109 = F_5 ( F_72 ( V_4 ) ) & V_146 ;
F_46 ( V_109 != V_107 ,
L_22 ,
F_68 ( V_4 ) , F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
void F_73 ( struct V_11 * V_12 ,
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
if ( ! F_74 ( V_12 ,
F_75 ( V_84 ) ) ) {
V_109 = false ;
} else {
V_85 = F_44 ( V_84 ) ;
V_108 = F_5 ( V_85 ) ;
V_109 = ! ! ( V_108 & V_150 ) ;
}
F_46 ( V_109 != V_107 ,
L_23 ,
F_68 ( V_4 ) , F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
static void F_76 ( struct V_11 * V_12 ,
enum V_151 V_151 , bool V_107 )
{
int V_85 ;
T_1 V_108 ;
bool V_109 ;
V_85 = F_77 ( V_151 ) ;
V_108 = F_5 ( V_85 ) ;
V_109 = ! ! ( V_108 & V_152 ) ;
F_46 ( V_109 != V_107 ,
L_24 ,
F_78 ( V_151 ) , F_49 ( V_107 ) , F_49 ( V_109 ) ) ;
}
static void F_79 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_85 , V_153 ;
T_1 V_108 ;
int V_154 ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
V_85 = F_77 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
F_46 ( V_108 & V_152 ,
L_25 ,
F_78 ( V_4 ) ) ;
return;
}
F_80 (dev_priv, i) {
V_85 = F_77 ( V_153 ) ;
V_108 = F_5 ( V_85 ) ;
V_154 = ( V_108 & V_155 ) >>
V_156 ;
F_46 ( ( V_108 & V_152 ) && V_4 == V_154 ,
L_26 ,
F_78 ( V_153 ) , F_68 ( V_4 ) ) ;
}
}
static void F_81 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_85 , V_157 ;
T_1 V_108 ;
if ( F_43 ( V_10 ) -> V_91 >= 9 ) {
F_82 (pipe, sprite) {
V_108 = F_5 ( F_83 ( V_4 , V_157 ) ) ;
F_46 ( V_108 & V_158 ,
L_27 ,
V_157 , F_68 ( V_4 ) ) ;
}
} else if ( F_21 ( V_10 ) ) {
F_82 (pipe, sprite) {
V_85 = F_84 ( V_4 , V_157 ) ;
V_108 = F_5 ( V_85 ) ;
F_46 ( V_108 & V_159 ,
L_28 ,
F_85 ( V_4 , V_157 ) , F_68 ( V_4 ) ) ;
}
} else if ( F_43 ( V_10 ) -> V_91 >= 7 ) {
V_85 = F_86 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
F_46 ( V_108 & V_160 ,
L_28 ,
F_78 ( V_4 ) , F_68 ( V_4 ) ) ;
} else if ( F_43 ( V_10 ) -> V_91 >= 5 ) {
V_85 = F_87 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
F_46 ( V_108 & V_161 ,
L_28 ,
F_78 ( V_4 ) , F_68 ( V_4 ) ) ;
}
}
static void F_88 ( struct V_75 * V_29 )
{
if ( F_3 ( F_89 ( V_29 ) == 0 ) )
F_90 ( V_29 ) ;
}
static void F_91 ( struct V_11 * V_12 )
{
T_1 V_108 ;
bool V_106 ;
F_3 ( ! ( F_48 ( V_12 -> V_10 ) || F_92 ( V_12 -> V_10 ) ) ) ;
V_108 = F_5 ( V_162 ) ;
V_106 = ! ! ( V_108 & ( V_163 | V_164 |
V_165 ) ) ;
F_46 ( ! V_106 , L_29 ) ;
}
static void F_93 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_85 ;
T_1 V_108 ;
bool V_106 ;
V_85 = F_94 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_106 = ! ! ( V_108 & V_166 ) ;
F_46 ( V_106 ,
L_30 ,
F_68 ( V_4 ) ) ;
}
static bool F_95 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_131 , T_1 V_108 )
{
if ( ( V_108 & V_167 ) == 0 )
return false ;
if ( F_92 ( V_12 -> V_10 ) ) {
T_1 V_168 = F_96 ( V_4 ) ;
T_1 V_169 = F_5 ( V_168 ) ;
if ( ( V_169 & V_170 ) != V_131 )
return false ;
} else if ( F_20 ( V_12 -> V_10 ) ) {
if ( ( V_108 & V_171 ) != F_97 ( V_4 ) )
return false ;
} else {
if ( ( V_108 & V_172 ) != ( V_4 << 30 ) )
return false ;
}
return true ;
}
static bool F_98 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_108 )
{
if ( ( V_108 & V_173 ) == 0 )
return false ;
if ( F_92 ( V_12 -> V_10 ) ) {
if ( ( V_108 & V_174 ) != F_99 ( V_4 ) )
return false ;
} else if ( F_20 ( V_12 -> V_10 ) ) {
if ( ( V_108 & V_175 ) != F_100 ( V_4 ) )
return false ;
} else {
if ( ( V_108 & V_176 ) != F_101 ( V_4 ) )
return false ;
}
return true ;
}
static bool F_102 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_108 )
{
if ( ( V_108 & V_177 ) == 0 )
return false ;
if ( F_92 ( V_12 -> V_10 ) ) {
if ( ( V_108 & V_178 ) != F_103 ( V_4 ) )
return false ;
} else {
if ( ( V_108 & V_179 ) != F_104 ( V_4 ) )
return false ;
}
return true ;
}
static bool F_105 ( struct V_11 * V_12 ,
enum V_4 V_4 , T_1 V_108 )
{
if ( ( V_108 & V_180 ) == 0 )
return false ;
if ( F_92 ( V_12 -> V_10 ) ) {
if ( ( V_108 & V_178 ) != F_103 ( V_4 ) )
return false ;
} else {
if ( ( V_108 & V_181 ) != F_106 ( V_4 ) )
return false ;
}
return true ;
}
static void F_107 ( struct V_11 * V_12 ,
enum V_4 V_4 , int V_85 , T_1 V_131 )
{
T_1 V_108 = F_5 ( V_85 ) ;
F_46 ( F_95 ( V_12 , V_4 , V_131 , V_108 ) ,
L_31 ,
V_85 , F_68 ( V_4 ) ) ;
F_46 ( F_48 ( V_12 -> V_10 ) && ( V_108 & V_167 ) == 0
&& ( V_108 & V_182 ) ,
L_32 ) ;
}
static void F_108 ( struct V_11 * V_12 ,
enum V_4 V_4 , int V_85 )
{
T_1 V_108 = F_5 ( V_85 ) ;
F_46 ( F_98 ( V_12 , V_4 , V_108 ) ,
L_33 ,
V_85 , F_68 ( V_4 ) ) ;
F_46 ( F_48 ( V_12 -> V_10 ) && ( V_108 & V_173 ) == 0
&& ( V_108 & V_183 ) ,
L_34 ) ;
}
static void F_109 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
int V_85 ;
T_1 V_108 ;
F_107 ( V_12 , V_4 , V_184 , V_185 ) ;
F_107 ( V_12 , V_4 , V_186 , V_187 ) ;
F_107 ( V_12 , V_4 , V_188 , V_189 ) ;
V_85 = V_190 ;
V_108 = F_5 ( V_85 ) ;
F_46 ( F_105 ( V_12 , V_4 , V_108 ) ,
L_35 ,
F_68 ( V_4 ) ) ;
V_85 = V_136 ;
V_108 = F_5 ( V_85 ) ;
F_46 ( F_102 ( V_12 , V_4 , V_108 ) ,
L_36 ,
F_68 ( V_4 ) ) ;
F_108 ( V_12 , V_4 , V_191 ) ;
F_108 ( V_12 , V_4 , V_192 ) ;
F_108 ( V_12 , V_4 , V_193 ) ;
}
static void F_110 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_21 ( V_10 ) )
return;
if ( F_20 ( V_10 ) ) {
F_111 ( V_194 ) = V_195 ;
F_111 ( V_196 ) = V_197 ;
} else {
F_111 ( V_194 ) = V_197 ;
}
}
static void F_112 ( struct V_28 * V_29 ,
const struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_85 = F_51 ( V_29 -> V_4 ) ;
T_1 V_56 = V_199 -> V_200 . V_56 ;
F_113 ( V_12 , V_29 -> V_4 ) ;
F_114 ( ! F_21 ( V_12 -> V_10 ) ) ;
if ( F_115 ( V_12 -> V_10 ) )
F_66 ( V_12 , V_29 -> V_4 ) ;
F_116 ( V_85 , V_56 ) ;
F_117 ( V_85 ) ;
F_118 ( 150 ) ;
if ( F_45 ( ( ( F_5 ( V_85 ) & V_201 ) == V_201 ) , 1 ) )
F_119 ( L_37 , V_29 -> V_4 ) ;
F_116 ( F_120 ( V_29 -> V_4 ) , V_199 -> V_200 . V_202 ) ;
F_117 ( F_120 ( V_29 -> V_4 ) ) ;
F_116 ( V_85 , V_56 ) ;
F_117 ( V_85 ) ;
F_118 ( 150 ) ;
F_116 ( V_85 , V_56 ) ;
F_117 ( V_85 ) ;
F_118 ( 150 ) ;
F_116 ( V_85 , V_56 ) ;
F_117 ( V_85 ) ;
F_118 ( 150 ) ;
}
static void F_121 ( struct V_28 * V_29 ,
const struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
enum V_203 V_94 = F_122 ( V_4 ) ;
T_1 V_204 ;
F_113 ( V_12 , V_29 -> V_4 ) ;
F_114 ( ! F_20 ( V_12 -> V_10 ) ) ;
F_53 ( & V_12 -> V_111 ) ;
V_204 = F_123 ( V_12 , V_4 , F_124 ( V_94 ) ) ;
V_204 |= V_205 ;
F_125 ( V_12 , V_4 , F_124 ( V_94 ) , V_204 ) ;
F_118 ( 1 ) ;
F_116 ( F_51 ( V_4 ) , V_199 -> V_200 . V_56 ) ;
if ( F_45 ( ( ( F_5 ( F_51 ( V_4 ) ) & V_201 ) == V_201 ) , 1 ) )
F_119 ( L_38 , V_4 ) ;
F_116 ( F_120 ( V_4 ) , V_199 -> V_200 . V_202 ) ;
F_117 ( F_120 ( V_4 ) ) ;
F_55 ( & V_12 -> V_111 ) ;
}
static int F_126 ( struct V_9 * V_10 )
{
struct V_28 * V_29 ;
int V_206 = 0 ;
F_127 (dev, crtc)
V_206 += V_29 -> V_76 &&
F_10 ( V_29 , V_53 ) ;
return V_206 ;
}
static void F_128 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_85 = F_51 ( V_29 -> V_4 ) ;
T_1 V_56 = V_29 -> V_79 . V_200 . V_56 ;
F_113 ( V_12 , V_29 -> V_4 ) ;
F_114 ( F_43 ( V_10 ) -> V_91 >= 5 ) ;
if ( F_115 ( V_10 ) && ! F_129 ( V_10 ) )
F_66 ( V_12 , V_29 -> V_4 ) ;
if ( F_129 ( V_10 ) && F_126 ( V_10 ) > 0 ) {
V_56 |= V_207 ;
F_116 ( F_51 ( ! V_29 -> V_4 ) ,
F_5 ( F_51 ( ! V_29 -> V_4 ) ) | V_207 ) ;
}
F_117 ( V_85 ) ;
F_118 ( 150 ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
F_116 ( F_120 ( V_29 -> V_4 ) ,
V_29 -> V_79 . V_200 . V_202 ) ;
} else {
F_116 ( V_85 , V_56 ) ;
}
F_116 ( V_85 , V_56 ) ;
F_117 ( V_85 ) ;
F_118 ( 150 ) ;
F_116 ( V_85 , V_56 ) ;
F_117 ( V_85 ) ;
F_118 ( 150 ) ;
F_116 ( V_85 , V_56 ) ;
F_117 ( V_85 ) ;
F_118 ( 150 ) ;
}
static void F_130 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
if ( F_129 ( V_10 ) &&
F_10 ( V_29 , V_53 ) &&
F_126 ( V_10 ) == 1 ) {
F_116 ( F_51 ( V_138 ) ,
F_5 ( F_51 ( V_138 ) ) & ~ V_207 ) ;
F_116 ( F_51 ( V_129 ) ,
F_5 ( F_51 ( V_129 ) ) & ~ V_207 ) ;
}
if ( ( V_4 == V_129 && V_12 -> V_147 & V_148 ) ||
( V_4 == V_138 && V_12 -> V_147 & V_149 ) )
return;
F_113 ( V_12 , V_4 ) ;
F_116 ( F_51 ( V_4 ) , 0 ) ;
F_117 ( F_51 ( V_4 ) ) ;
}
static void F_131 ( struct V_11 * V_12 , enum V_4 V_4 )
{
T_1 V_108 = 0 ;
F_113 ( V_12 , V_4 ) ;
if ( V_4 == V_138 )
V_108 = V_208 | V_209 ;
F_116 ( F_51 ( V_4 ) , V_108 ) ;
F_117 ( F_51 ( V_4 ) ) ;
}
static void F_132 ( struct V_11 * V_12 , enum V_4 V_4 )
{
enum V_203 V_94 = F_122 ( V_4 ) ;
T_1 V_108 ;
F_113 ( V_12 , V_4 ) ;
V_108 = V_210 | V_209 ;
if ( V_4 != V_129 )
V_108 |= V_208 ;
F_116 ( F_51 ( V_4 ) , V_108 ) ;
F_117 ( F_51 ( V_4 ) ) ;
F_53 ( & V_12 -> V_111 ) ;
V_108 = F_123 ( V_12 , V_4 , F_124 ( V_94 ) ) ;
V_108 &= ~ V_205 ;
F_125 ( V_12 , V_4 , F_124 ( V_94 ) , V_108 ) ;
if ( V_4 != V_138 ) {
V_108 = F_123 ( V_12 , V_4 , V_211 ) ;
V_108 &= ~ ( V_212 | V_213 ) ;
F_125 ( V_12 , V_4 , V_211 , V_108 ) ;
} else {
V_108 = F_123 ( V_12 , V_4 , V_214 ) ;
V_108 &= ~ ( V_215 | V_216 ) ;
F_125 ( V_12 , V_4 , V_214 , V_108 ) ;
}
F_55 ( & V_12 -> V_111 ) ;
}
void F_133 ( struct V_11 * V_12 ,
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
F_134 () ;
}
if ( F_45 ( ( F_5 ( V_219 ) & V_218 ) == 0 , 1000 ) )
F_46 ( 1 , L_39 ,
F_135 ( V_217 -> V_94 ) , F_5 ( V_219 ) ) ;
}
static void F_136 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_114 * V_117 = F_56 ( V_29 ) ;
if ( F_3 ( V_117 == NULL ) )
return;
F_3 ( ! V_117 -> V_79 . V_224 ) ;
if ( V_117 -> V_76 == 0 ) {
F_137 ( L_40 , V_117 -> V_121 ) ;
F_3 ( V_117 -> V_225 ) ;
F_138 ( V_12 , V_117 ) ;
V_117 -> V_226 ( V_12 , V_117 ) ;
}
}
static void F_139 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_114 * V_117 = F_56 ( V_29 ) ;
if ( F_3 ( V_117 == NULL ) )
return;
if ( F_3 ( V_117 -> V_79 . V_224 == 0 ) )
return;
F_140 ( L_41 ,
V_117 -> V_121 , V_117 -> V_76 , V_117 -> V_225 ,
V_29 -> V_8 . V_8 . V_227 ) ;
if ( V_117 -> V_76 ++ ) {
F_3 ( ! V_117 -> V_225 ) ;
F_141 ( V_12 , V_117 ) ;
return;
}
F_3 ( V_117 -> V_225 ) ;
F_142 ( V_12 , V_228 ) ;
F_140 ( L_42 , V_117 -> V_121 ) ;
V_117 -> V_229 ( V_12 , V_117 ) ;
V_117 -> V_225 = true ;
}
static void F_143 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_114 * V_117 = F_56 ( V_29 ) ;
F_114 ( F_43 ( V_10 ) -> V_91 < 5 ) ;
if ( F_3 ( V_117 == NULL ) )
return;
if ( F_3 ( V_117 -> V_79 . V_224 == 0 ) )
return;
F_140 ( L_43 ,
V_117 -> V_121 , V_117 -> V_76 , V_117 -> V_225 ,
V_29 -> V_8 . V_8 . V_227 ) ;
if ( F_3 ( V_117 -> V_76 == 0 ) ) {
F_138 ( V_12 , V_117 ) ;
return;
}
F_141 ( V_12 , V_117 ) ;
F_3 ( ! V_117 -> V_225 ) ;
if ( -- V_117 -> V_76 )
return;
F_140 ( L_44 , V_117 -> V_121 ) ;
V_117 -> V_230 ( V_12 , V_117 ) ;
V_117 -> V_225 = false ;
F_144 ( V_12 , V_228 ) ;
}
static void F_145 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_75 * V_29 = V_12 -> V_83 [ V_4 ] ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_4 V_85 , V_108 , V_231 ;
F_114 ( ! F_4 ( V_10 ) ) ;
F_141 ( V_12 ,
F_56 ( V_28 ) ) ;
F_146 ( V_12 , V_4 ) ;
F_147 ( V_12 , V_4 ) ;
if ( F_92 ( V_10 ) ) {
V_85 = F_148 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_108 |= V_232 ;
F_116 ( V_85 , V_108 ) ;
}
V_85 = F_94 ( V_4 ) ;
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
F_116 ( V_85 , V_108 | V_166 ) ;
if ( F_45 ( F_5 ( V_85 ) & V_240 , 100 ) )
F_119 ( L_45 , F_68 ( V_4 ) ) ;
}
static void F_149 ( struct V_11 * V_12 ,
enum V_82 V_84 )
{
T_1 V_108 , V_231 ;
F_114 ( ! F_4 ( V_12 -> V_10 ) ) ;
F_146 ( V_12 , (enum V_4 ) V_84 ) ;
F_147 ( V_12 , V_241 ) ;
V_108 = F_5 ( V_242 ) ;
V_108 |= V_232 ;
F_116 ( V_242 , V_108 ) ;
V_108 = V_166 ;
V_231 = F_5 ( F_44 ( V_84 ) ) ;
if ( ( V_231 & V_243 ) ==
V_236 )
V_108 |= V_238 ;
else
V_108 |= V_239 ;
F_116 ( V_244 , V_108 ) ;
if ( F_45 ( F_5 ( V_244 ) & V_240 , 100 ) )
F_119 ( L_46 ) ;
}
static void F_150 ( struct V_11 * V_12 ,
enum V_4 V_4 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_85 , V_108 ;
F_151 ( V_12 , V_4 ) ;
F_152 ( V_12 , V_4 ) ;
F_109 ( V_12 , V_4 ) ;
V_85 = F_94 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_108 &= ~ V_166 ;
F_116 ( V_85 , V_108 ) ;
if ( F_45 ( ( F_5 ( V_85 ) & V_240 ) == 0 , 50 ) )
F_119 ( L_47 , F_68 ( V_4 ) ) ;
if ( ! F_48 ( V_10 ) ) {
V_85 = F_148 ( V_4 ) ;
V_108 = F_5 ( V_85 ) ;
V_108 &= ~ V_232 ;
F_116 ( V_85 , V_108 ) ;
}
}
static void F_153 ( struct V_11 * V_12 )
{
T_1 V_108 ;
V_108 = F_5 ( V_244 ) ;
V_108 &= ~ V_166 ;
F_116 ( V_244 , V_108 ) ;
if ( F_45 ( ( F_5 ( V_244 ) & V_240 ) == 0 , 50 ) )
F_119 ( L_48 ) ;
V_108 = F_5 ( V_242 ) ;
V_108 &= ~ V_232 ;
F_116 ( V_242 , V_108 ) ;
}
static void F_154 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
enum V_82 V_84 = F_38 ( V_12 ,
V_4 ) ;
enum V_4 V_245 ;
int V_85 ;
T_1 V_108 ;
F_79 ( V_12 , V_4 ) ;
F_155 ( V_12 , V_4 ) ;
F_81 ( V_12 , V_4 ) ;
if ( F_156 ( V_12 -> V_10 ) )
V_245 = V_241 ;
else
V_245 = V_4 ;
if ( ! F_4 ( V_12 -> V_10 ) )
if ( F_10 ( V_29 , V_246 ) )
F_157 ( V_12 ) ;
else
F_158 ( V_12 , V_4 ) ;
else {
if ( V_29 -> V_79 . V_247 ) {
F_159 ( V_12 , V_245 ) ;
F_64 ( V_12 ,
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
F_116 ( V_85 , V_108 | V_150 ) ;
F_117 ( V_85 ) ;
}
static void F_160 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
enum V_82 V_84 = V_29 -> V_79 . V_84 ;
enum V_4 V_4 = V_29 -> V_4 ;
int V_85 ;
T_1 V_108 ;
F_79 ( V_12 , V_4 ) ;
F_155 ( V_12 , V_4 ) ;
F_81 ( V_12 , V_4 ) ;
V_85 = F_44 ( V_84 ) ;
V_108 = F_5 ( V_85 ) ;
if ( ( V_108 & V_150 ) == 0 )
return;
if ( V_29 -> V_79 . V_248 )
V_108 &= ~ V_249 ;
if ( ! ( V_4 == V_129 && V_12 -> V_147 & V_148 ) &&
! ( V_4 == V_138 && V_12 -> V_147 & V_149 ) )
V_108 &= ~ V_150 ;
F_116 ( V_85 , V_108 ) ;
if ( ( V_108 & V_150 ) == 0 )
F_42 ( V_29 ) ;
}
void F_161 ( struct V_11 * V_12 ,
enum V_151 V_151 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_1 V_85 = F_43 ( V_10 ) -> V_91 >= 4 ? F_162 ( V_151 ) : F_163 ( V_151 ) ;
F_116 ( V_85 , F_5 ( V_85 ) ) ;
F_117 ( V_85 ) ;
}
static void F_164 ( struct V_250 * V_151 ,
struct V_75 * V_29 )
{
struct V_9 * V_10 = V_151 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
F_165 ( V_12 , V_28 -> V_4 ) ;
if ( V_28 -> V_251 )
return;
V_28 -> V_251 = true ;
V_12 -> V_252 . V_253 ( V_29 , V_151 -> V_78 ,
V_29 -> V_254 , V_29 -> V_255 ) ;
if ( F_166 ( V_10 ) )
F_167 ( V_10 , V_28 -> V_4 ) ;
}
static void F_168 ( struct V_250 * V_151 ,
struct V_75 * V_29 )
{
struct V_9 * V_10 = V_151 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
F_165 ( V_12 , V_28 -> V_4 ) ;
if ( ! V_28 -> V_251 )
return;
V_28 -> V_251 = false ;
V_12 -> V_252 . V_253 ( V_29 , V_151 -> V_78 ,
V_29 -> V_254 , V_29 -> V_255 ) ;
}
static bool F_169 ( struct V_9 * V_10 )
{
#ifdef F_170
if ( F_43 ( V_10 ) -> V_91 >= 6 && V_256 )
return true ;
#endif
return false ;
}
static int F_171 ( struct V_9 * V_10 , int V_257 , bool V_258 )
{
int V_259 ;
V_259 = V_258 ? ( F_22 ( V_10 ) ? 16 : 8 ) : 1 ;
return F_172 ( V_257 , V_259 ) ;
}
int
F_173 ( struct V_250 * V_151 ,
struct V_260 * V_78 ,
struct V_261 * V_262 )
{
struct V_9 * V_10 = V_78 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_263 * V_264 = F_174 ( V_78 ) ;
T_1 V_265 ;
int V_266 ;
F_3 ( ! F_175 ( & V_10 -> V_267 ) ) ;
switch ( V_264 -> V_268 ) {
case V_269 :
if ( F_43 ( V_10 ) -> V_91 >= 9 )
V_265 = 256 * 1024 ;
else if ( F_176 ( V_10 ) || F_177 ( V_10 ) )
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
F_134 () ;
}
if ( F_169 ( V_10 ) && V_265 < 256 * 1024 )
V_265 = 256 * 1024 ;
F_178 ( V_12 ) ;
V_12 -> V_273 . V_274 = false ;
V_266 = F_179 ( V_264 , V_265 , V_262 ) ;
if ( V_266 )
goto V_275;
V_266 = F_180 ( V_264 ) ;
if ( V_266 )
goto V_276;
F_181 ( V_264 ) ;
V_12 -> V_273 . V_274 = true ;
F_182 ( V_12 ) ;
return 0 ;
V_276:
F_183 ( V_264 ) ;
V_275:
V_12 -> V_273 . V_274 = true ;
F_182 ( V_12 ) ;
return V_266 ;
}
void F_184 ( struct V_263 * V_264 )
{
F_3 ( ! F_175 ( & V_264 -> V_8 . V_10 -> V_267 ) ) ;
F_185 ( V_264 ) ;
F_183 ( V_264 ) ;
}
unsigned long F_186 ( int * V_254 , int * V_255 ,
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
int F_187 ( int V_282 )
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
static bool F_188 ( struct V_28 * V_29 ,
struct V_297 * V_298 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_263 * V_264 = NULL ;
struct V_299 V_300 = { 0 } ;
T_1 V_8 = V_298 -> V_8 ;
if ( V_298 -> V_301 == 0 )
return false ;
V_264 = F_189 ( V_10 , V_8 , V_8 ,
V_298 -> V_301 ) ;
if ( ! V_264 )
return false ;
if ( V_298 -> V_258 ) {
V_264 -> V_268 = V_270 ;
V_264 -> V_302 = V_29 -> V_8 . V_77 -> V_78 -> V_303 [ 0 ] ;
}
V_300 . V_304 = V_29 -> V_8 . V_77 -> V_78 -> V_304 ;
V_300 . V_305 = V_29 -> V_8 . V_77 -> V_78 -> V_305 ;
V_300 . V_257 = V_29 -> V_8 . V_77 -> V_78 -> V_257 ;
V_300 . V_303 [ 0 ] = V_29 -> V_8 . V_77 -> V_78 -> V_303 [ 0 ] ;
F_53 ( & V_10 -> V_267 ) ;
if ( F_190 ( V_10 , F_191 ( V_29 -> V_8 . V_77 -> V_78 ) ,
& V_300 , V_264 ) ) {
F_140 ( L_50 ) ;
goto V_306;
}
V_264 -> V_307 = F_192 ( V_29 -> V_4 ) ;
F_55 ( & V_10 -> V_267 ) ;
F_140 ( L_51 , V_264 ) ;
return true ;
V_306:
F_193 ( & V_264 -> V_8 ) ;
F_55 ( & V_10 -> V_267 ) ;
return false ;
}
static void F_194 ( struct V_28 * V_28 ,
struct V_297 * V_298 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_308 ;
struct V_28 * V_153 ;
struct V_263 * V_264 ;
if ( ! V_28 -> V_8 . V_77 -> V_78 )
return;
if ( F_188 ( V_28 , V_298 ) )
return;
F_195 ( V_28 -> V_8 . V_77 -> V_78 ) ;
V_28 -> V_8 . V_77 -> V_78 = NULL ;
F_196 (dev, c) {
V_153 = F_37 ( V_308 ) ;
if ( V_308 == & V_28 -> V_8 )
continue;
if ( ! V_153 -> V_76 )
continue;
V_264 = F_174 ( V_308 -> V_77 -> V_78 ) ;
if ( V_264 == NULL )
continue;
if ( F_197 ( V_264 ) == V_298 -> V_8 ) {
if ( V_264 -> V_268 != V_269 )
V_12 -> V_309 = true ;
F_198 ( V_308 -> V_77 -> V_78 ) ;
V_28 -> V_8 . V_77 -> V_78 = V_308 -> V_77 -> V_78 ;
V_264 -> V_307 |= F_192 ( V_28 -> V_4 ) ;
break;
}
}
}
static void F_199 ( struct V_75 * V_29 ,
struct V_260 * V_78 ,
int V_254 , int V_255 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_263 * V_264 ;
int V_151 = V_28 -> V_151 ;
unsigned long V_310 ;
T_1 V_311 ;
T_1 V_85 = F_77 ( V_151 ) ;
int V_312 ;
if ( ! V_28 -> V_251 ) {
F_116 ( V_85 , 0 ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 )
F_116 ( F_162 ( V_151 ) , 0 ) ;
else
F_116 ( F_163 ( V_151 ) , 0 ) ;
F_117 ( V_85 ) ;
return;
}
V_264 = F_174 ( V_78 ) ;
if ( F_3 ( V_264 == NULL ) )
return;
V_312 = F_200 ( V_78 -> V_304 , 0 ) ;
V_311 = V_313 ;
V_311 |= V_152 ;
if ( F_43 ( V_10 ) -> V_91 < 4 ) {
if ( V_28 -> V_4 == V_138 )
V_311 |= V_314 ;
F_116 ( F_201 ( V_151 ) ,
( ( V_28 -> V_79 . V_315 - 1 ) << 16 ) |
( V_28 -> V_79 . V_316 - 1 ) ) ;
F_116 ( F_202 ( V_151 ) , 0 ) ;
} else if ( F_20 ( V_10 ) && V_151 == V_317 ) {
F_116 ( F_203 ( V_151 ) ,
( ( V_28 -> V_79 . V_315 - 1 ) << 16 ) |
( V_28 -> V_79 . V_316 - 1 ) ) ;
F_116 ( F_204 ( V_151 ) , 0 ) ;
F_116 ( F_205 ( V_151 ) , 0 ) ;
}
switch ( V_78 -> V_304 ) {
case V_284 :
V_311 |= V_283 ;
break;
case V_286 :
case V_318 :
V_311 |= V_285 ;
break;
case V_288 :
V_311 |= V_287 ;
break;
case V_290 :
case V_319 :
V_311 |= V_289 ;
break;
case V_292 :
case V_320 :
V_311 |= V_291 ;
break;
case V_294 :
case V_321 :
V_311 |= V_293 ;
break;
case V_296 :
case V_322 :
V_311 |= V_295 ;
break;
default:
F_134 () ;
}
if ( F_43 ( V_10 ) -> V_91 >= 4 &&
V_264 -> V_268 != V_269 )
V_311 |= V_323 ;
if ( F_18 ( V_10 ) )
V_311 |= V_324 ;
V_310 = V_255 * V_78 -> V_303 [ 0 ] + V_254 * V_312 ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
V_28 -> V_325 =
F_186 ( & V_254 , & V_255 , V_264 -> V_268 ,
V_312 ,
V_78 -> V_303 [ 0 ] ) ;
V_310 -= V_28 -> V_325 ;
} else {
V_28 -> V_325 = V_310 ;
}
if ( F_206 ( V_29 -> V_77 ) -> V_326 == F_207 ( V_327 ) ) {
V_311 |= V_328 ;
V_254 += ( V_28 -> V_79 . V_316 - 1 ) ;
V_255 += ( V_28 -> V_79 . V_315 - 1 ) ;
V_310 +=
( V_28 -> V_79 . V_315 - 1 ) * V_78 -> V_303 [ 0 ] +
( V_28 -> V_79 . V_316 - 1 ) * V_312 ;
}
F_116 ( V_85 , V_311 ) ;
F_140 ( L_52 ,
F_197 ( V_264 ) , V_310 , V_254 , V_255 ,
V_78 -> V_303 [ 0 ] ) ;
F_116 ( F_208 ( V_151 ) , V_78 -> V_303 [ 0 ] ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
F_116 ( F_162 ( V_151 ) ,
F_197 ( V_264 ) + V_28 -> V_325 ) ;
F_116 ( F_209 ( V_151 ) , ( V_255 << 16 ) | V_254 ) ;
F_116 ( F_210 ( V_151 ) , V_310 ) ;
} else
F_116 ( F_163 ( V_151 ) , F_197 ( V_264 ) + V_310 ) ;
F_117 ( V_85 ) ;
}
static void F_211 ( struct V_75 * V_29 ,
struct V_260 * V_78 ,
int V_254 , int V_255 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_263 * V_264 ;
int V_151 = V_28 -> V_151 ;
unsigned long V_310 ;
T_1 V_311 ;
T_1 V_85 = F_77 ( V_151 ) ;
int V_312 ;
if ( ! V_28 -> V_251 ) {
F_116 ( V_85 , 0 ) ;
F_116 ( F_162 ( V_151 ) , 0 ) ;
F_117 ( V_85 ) ;
return;
}
V_264 = F_174 ( V_78 ) ;
if ( F_3 ( V_264 == NULL ) )
return;
V_312 = F_200 ( V_78 -> V_304 , 0 ) ;
V_311 = V_313 ;
V_311 |= V_152 ;
if ( F_212 ( V_10 ) || F_166 ( V_10 ) )
V_311 |= V_329 ;
switch ( V_78 -> V_304 ) {
case V_284 :
V_311 |= V_283 ;
break;
case V_288 :
V_311 |= V_287 ;
break;
case V_290 :
case V_319 :
V_311 |= V_289 ;
break;
case V_292 :
case V_320 :
V_311 |= V_291 ;
break;
case V_294 :
case V_321 :
V_311 |= V_293 ;
break;
case V_296 :
case V_322 :
V_311 |= V_295 ;
break;
default:
F_134 () ;
}
if ( V_264 -> V_268 != V_269 )
V_311 |= V_323 ;
if ( ! F_212 ( V_10 ) && ! F_166 ( V_10 ) )
V_311 |= V_324 ;
V_310 = V_255 * V_78 -> V_303 [ 0 ] + V_254 * V_312 ;
V_28 -> V_325 =
F_186 ( & V_254 , & V_255 , V_264 -> V_268 ,
V_312 ,
V_78 -> V_303 [ 0 ] ) ;
V_310 -= V_28 -> V_325 ;
if ( F_206 ( V_29 -> V_77 ) -> V_326 == F_207 ( V_327 ) ) {
V_311 |= V_328 ;
if ( ! F_212 ( V_10 ) && ! F_166 ( V_10 ) ) {
V_254 += ( V_28 -> V_79 . V_316 - 1 ) ;
V_255 += ( V_28 -> V_79 . V_315 - 1 ) ;
V_310 +=
( V_28 -> V_79 . V_315 - 1 ) * V_78 -> V_303 [ 0 ] +
( V_28 -> V_79 . V_316 - 1 ) * V_312 ;
}
}
F_116 ( V_85 , V_311 ) ;
F_140 ( L_52 ,
F_197 ( V_264 ) , V_310 , V_254 , V_255 ,
V_78 -> V_303 [ 0 ] ) ;
F_116 ( F_208 ( V_151 ) , V_78 -> V_303 [ 0 ] ) ;
F_116 ( F_162 ( V_151 ) ,
F_197 ( V_264 ) + V_28 -> V_325 ) ;
if ( F_212 ( V_10 ) || F_166 ( V_10 ) ) {
F_116 ( F_213 ( V_151 ) , ( V_255 << 16 ) | V_254 ) ;
} else {
F_116 ( F_209 ( V_151 ) , ( V_255 << 16 ) | V_254 ) ;
F_116 ( F_210 ( V_151 ) , V_310 ) ;
}
F_117 ( V_85 ) ;
}
static void F_214 ( struct V_75 * V_29 ,
struct V_260 * V_78 ,
int V_254 , int V_255 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_330 * V_331 ;
struct V_263 * V_264 ;
int V_4 = V_28 -> V_4 ;
T_1 V_332 , V_302 ;
if ( ! V_28 -> V_251 ) {
F_116 ( F_83 ( V_4 , 0 ) , 0 ) ;
F_116 ( F_215 ( V_4 , 0 ) , 0 ) ;
F_117 ( F_83 ( V_4 , 0 ) ) ;
return;
}
V_332 = V_158 |
V_333 |
V_334 ;
switch ( V_78 -> V_304 ) {
case V_288 :
V_332 |= V_335 ;
break;
case V_290 :
V_332 |= V_336 ;
break;
case V_292 :
V_332 |= V_337 ;
V_332 |= V_336 ;
break;
case V_294 :
V_332 |= V_338 ;
break;
case V_296 :
V_332 |= V_337 ;
V_332 |= V_338 ;
break;
default:
F_134 () ;
}
V_331 = F_191 ( V_78 ) ;
V_264 = V_331 -> V_264 ;
switch ( V_264 -> V_268 ) {
case V_269 :
V_302 = V_78 -> V_303 [ 0 ] >> 6 ;
break;
case V_270 :
V_332 |= V_339 ;
V_302 = V_78 -> V_303 [ 0 ] >> 9 ;
break;
default:
F_134 () ;
}
V_332 |= V_340 ;
if ( F_206 ( V_29 -> V_77 ) -> V_326 == F_207 ( V_327 ) )
V_332 |= V_341 ;
F_116 ( F_83 ( V_4 , 0 ) , V_332 ) ;
F_140 ( L_53 ,
F_197 ( V_264 ) ,
V_254 , V_255 , V_78 -> V_305 , V_78 -> V_257 ,
V_78 -> V_303 [ 0 ] ) ;
F_116 ( F_216 ( V_4 , 0 ) , 0 ) ;
F_116 ( F_217 ( V_4 , 0 ) , ( V_255 << 16 ) | V_254 ) ;
F_116 ( F_218 ( V_4 , 0 ) ,
( V_28 -> V_79 . V_315 - 1 ) << 16 |
( V_28 -> V_79 . V_316 - 1 ) ) ;
F_116 ( F_219 ( V_4 , 0 ) , V_302 ) ;
F_116 ( F_215 ( V_4 , 0 ) , F_197 ( V_264 ) ) ;
F_117 ( F_215 ( V_4 , 0 ) ) ;
}
static int
F_220 ( struct V_75 * V_29 , struct V_260 * V_78 ,
int V_254 , int V_255 , enum V_342 V_107 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_12 -> V_252 . V_343 )
V_12 -> V_252 . V_343 ( V_10 ) ;
V_12 -> V_252 . V_253 ( V_29 , V_78 , V_254 , V_255 ) ;
return 0 ;
}
static void F_221 ( struct V_9 * V_10 )
{
struct V_75 * V_29 ;
F_196 (dev, crtc) {
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_151 V_151 = V_28 -> V_151 ;
F_222 ( V_10 , V_151 ) ;
F_223 ( V_10 , V_151 ) ;
}
}
static void F_224 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_29 ;
F_196 (dev, crtc) {
struct V_28 * V_28 = F_37 ( V_29 ) ;
F_225 ( & V_29 -> V_344 , NULL ) ;
if ( V_28 -> V_76 && V_29 -> V_77 -> V_78 )
V_12 -> V_252 . V_253 ( V_29 ,
V_29 -> V_77 -> V_78 ,
V_29 -> V_254 ,
V_29 -> V_255 ) ;
F_226 ( & V_29 -> V_344 ) ;
}
}
void F_227 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_228 ( V_10 ) ;
struct V_28 * V_29 ;
if ( F_22 ( V_10 ) )
return;
if ( F_43 ( V_10 ) -> V_91 >= 5 || F_18 ( V_10 ) )
return;
F_229 ( V_10 ) ;
F_127 (dev, crtc) {
if ( V_29 -> V_76 )
V_12 -> V_252 . V_345 ( & V_29 -> V_8 ) ;
}
}
void F_230 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_228 ( V_10 ) ;
F_221 ( V_10 ) ;
if ( F_22 ( V_10 ) )
return;
if ( F_43 ( V_10 ) -> V_91 >= 5 || F_18 ( V_10 ) ) {
F_224 ( V_10 ) ;
return;
}
F_231 ( V_12 ) ;
F_232 ( V_12 ) ;
F_233 ( V_10 ) ;
F_234 ( & V_12 -> V_346 ) ;
if ( V_12 -> V_252 . V_347 )
V_12 -> V_252 . V_347 ( V_10 ) ;
F_235 ( & V_12 -> V_346 ) ;
F_236 ( V_10 , true ) ;
F_237 ( V_12 ) ;
F_238 ( V_10 ) ;
}
static int
F_239 ( struct V_260 * V_348 )
{
struct V_263 * V_264 = F_174 ( V_348 ) ;
struct V_11 * V_12 = V_264 -> V_8 . V_10 -> V_13 ;
bool V_349 = V_12 -> V_273 . V_274 ;
int V_266 ;
V_12 -> V_273 . V_274 = false ;
V_266 = F_240 ( V_264 ) ;
V_12 -> V_273 . V_274 = V_349 ;
return V_266 ;
}
static bool F_241 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
bool V_350 ;
if ( F_242 ( & V_12 -> V_351 ) ||
V_28 -> V_352 != F_243 ( & V_12 -> V_351 . V_352 ) )
return false ;
F_234 ( & V_10 -> V_353 ) ;
V_350 = F_37 ( V_29 ) -> V_354 != NULL ;
F_235 ( & V_10 -> V_353 ) ;
return V_350 ;
}
static void F_244 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
const struct V_355 * V_80 ;
if ( ! V_356 . V_357 )
return;
V_80 = & V_29 -> V_79 . V_80 ;
F_116 ( F_245 ( V_29 -> V_4 ) ,
( ( V_80 -> V_358 - 1 ) << 16 ) |
( V_80 -> V_359 - 1 ) ) ;
if ( ! V_29 -> V_79 . V_360 . V_106 &&
( F_10 ( V_29 , V_33 ) ||
F_10 ( V_29 , V_361 ) ) ) {
F_116 ( F_246 ( V_29 -> V_4 ) , 0 ) ;
F_116 ( F_247 ( V_29 -> V_4 ) , 0 ) ;
F_116 ( F_248 ( V_29 -> V_4 ) , 0 ) ;
}
V_29 -> V_79 . V_316 = V_80 -> V_358 ;
V_29 -> V_79 . V_315 = V_80 -> V_359 ;
}
static int
F_249 ( struct V_75 * V_29 , int V_254 , int V_255 ,
struct V_260 * V_78 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
struct V_260 * V_348 = V_29 -> V_77 -> V_78 ;
struct V_263 * V_362 = F_174 ( V_348 ) ;
int V_266 ;
if ( F_241 ( V_29 ) ) {
F_119 ( L_54 ) ;
return - V_363 ;
}
if ( ! V_78 ) {
F_119 ( L_55 ) ;
return 0 ;
}
if ( V_28 -> V_151 > F_43 ( V_10 ) -> V_364 ) {
F_119 ( L_56 ,
F_78 ( V_28 -> V_151 ) ,
F_43 ( V_10 ) -> V_364 ) ;
return - V_272 ;
}
F_53 ( & V_10 -> V_267 ) ;
V_266 = F_173 ( V_29 -> V_77 , V_78 , NULL ) ;
if ( V_266 == 0 )
F_250 ( V_362 , F_174 ( V_78 ) ,
F_192 ( V_4 ) ) ;
F_55 ( & V_10 -> V_267 ) ;
if ( V_266 != 0 ) {
F_119 ( L_57 ) ;
return V_266 ;
}
V_12 -> V_252 . V_253 ( V_29 , V_78 , V_254 , V_255 ) ;
if ( V_28 -> V_76 )
F_251 ( V_10 , F_192 ( V_4 ) ) ;
V_29 -> V_77 -> V_78 = V_78 ;
V_29 -> V_254 = V_254 ;
V_29 -> V_255 = V_255 ;
if ( V_348 ) {
if ( V_28 -> V_76 && V_348 != V_78 )
F_167 ( V_10 , V_28 -> V_4 ) ;
F_53 ( & V_10 -> V_267 ) ;
F_184 ( V_362 ) ;
F_55 ( & V_10 -> V_267 ) ;
}
F_53 ( & V_10 -> V_267 ) ;
F_252 ( V_10 ) ;
F_55 ( & V_10 -> V_267 ) ;
return 0 ;
}
static void F_253 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_365 ;
V_85 = F_61 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
if ( F_254 ( V_10 ) ) {
V_365 &= ~ V_366 ;
V_365 |= V_366 | V_367 ;
} else {
V_365 &= ~ V_368 ;
V_365 |= V_368 | V_367 ;
}
F_116 ( V_85 , V_365 ) ;
V_85 = F_63 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
if ( F_92 ( V_10 ) ) {
V_365 &= ~ V_369 ;
V_365 |= V_370 ;
} else {
V_365 &= ~ V_368 ;
V_365 |= V_368 ;
}
F_116 ( V_85 , V_365 | V_371 ) ;
F_117 ( V_85 ) ;
F_118 ( 1000 ) ;
if ( F_254 ( V_10 ) )
F_116 ( V_85 , F_5 ( V_85 ) | V_372 |
V_373 ) ;
}
static bool F_255 ( struct V_28 * V_29 )
{
return V_29 -> V_8 . V_106 && V_29 -> V_76 &&
V_29 -> V_79 . V_247 ;
}
static void F_256 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_374 =
F_37 ( V_12 -> V_83 [ V_138 ] ) ;
struct V_28 * V_375 =
F_37 ( V_12 -> V_83 [ V_376 ] ) ;
T_4 V_365 ;
if ( ! F_255 ( V_374 ) &&
! F_255 ( V_375 ) ) {
F_3 ( F_5 ( F_63 ( V_138 ) ) & V_124 ) ;
F_3 ( F_5 ( F_63 ( V_376 ) ) & V_124 ) ;
V_365 = F_5 ( V_377 ) ;
V_365 &= ~ V_378 ;
F_140 ( L_58 ) ;
F_116 ( V_377 , V_365 ) ;
}
}
static void F_257 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_365 , V_379 ;
F_165 ( V_12 , V_4 ) ;
V_85 = F_258 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_380 ;
V_365 &= ~ V_381 ;
F_116 ( V_85 , V_365 ) ;
F_5 ( V_85 ) ;
F_118 ( 150 ) ;
V_85 = F_61 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_382 ;
V_365 |= F_259 ( V_28 -> V_79 . V_383 ) ;
V_365 &= ~ V_368 ;
V_365 |= V_384 ;
F_116 ( V_85 , V_365 | V_123 ) ;
V_85 = F_63 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_368 ;
V_365 |= V_384 ;
F_116 ( V_85 , V_365 | V_124 ) ;
F_117 ( V_85 ) ;
F_118 ( 150 ) ;
F_116 ( F_260 ( V_4 ) , V_385 ) ;
F_116 ( F_260 ( V_4 ) , V_385 |
V_386 ) ;
V_85 = F_261 ( V_4 ) ;
for ( V_379 = 0 ; V_379 < 5 ; V_379 ++ ) {
V_365 = F_5 ( V_85 ) ;
F_140 ( L_59 , V_365 ) ;
if ( ( V_365 & V_381 ) ) {
F_140 ( L_60 ) ;
F_116 ( V_85 , V_365 | V_381 ) ;
break;
}
}
if ( V_379 == 5 )
F_119 ( L_61 ) ;
V_85 = F_61 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_368 ;
V_365 |= V_387 ;
F_116 ( V_85 , V_365 ) ;
V_85 = F_63 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_368 ;
V_365 |= V_387 ;
F_116 ( V_85 , V_365 ) ;
F_117 ( V_85 ) ;
F_118 ( 150 ) ;
V_85 = F_261 ( V_4 ) ;
for ( V_379 = 0 ; V_379 < 5 ; V_379 ++ ) {
V_365 = F_5 ( V_85 ) ;
F_140 ( L_59 , V_365 ) ;
if ( V_365 & V_380 ) {
F_116 ( V_85 , V_365 | V_380 ) ;
F_140 ( L_62 ) ;
break;
}
}
if ( V_379 == 5 )
F_119 ( L_63 ) ;
F_140 ( L_64 ) ;
}
static void F_262 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_365 , V_153 , V_388 ;
V_85 = F_258 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_380 ;
V_365 &= ~ V_381 ;
F_116 ( V_85 , V_365 ) ;
F_117 ( V_85 ) ;
F_118 ( 150 ) ;
V_85 = F_61 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_382 ;
V_365 |= F_259 ( V_28 -> V_79 . V_383 ) ;
V_365 &= ~ V_368 ;
V_365 |= V_384 ;
V_365 &= ~ V_389 ;
V_365 |= V_390 ;
F_116 ( V_85 , V_365 | V_123 ) ;
F_116 ( F_263 ( V_4 ) ,
V_391 | V_392 ) ;
V_85 = F_63 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
if ( F_92 ( V_10 ) ) {
V_365 &= ~ V_369 ;
V_365 |= V_393 ;
} else {
V_365 &= ~ V_368 ;
V_365 |= V_384 ;
}
F_116 ( V_85 , V_365 | V_124 ) ;
F_117 ( V_85 ) ;
F_118 ( 150 ) ;
for ( V_153 = 0 ; V_153 < 4 ; V_153 ++ ) {
V_85 = F_61 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_389 ;
V_365 |= V_394 [ V_153 ] ;
F_116 ( V_85 , V_365 ) ;
F_117 ( V_85 ) ;
F_118 ( 500 ) ;
for ( V_388 = 0 ; V_388 < 5 ; V_388 ++ ) {
V_85 = F_261 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
F_140 ( L_59 , V_365 ) ;
if ( V_365 & V_381 ) {
F_116 ( V_85 , V_365 | V_381 ) ;
F_140 ( L_60 ) ;
break;
}
F_118 ( 50 ) ;
}
if ( V_388 < 5 )
break;
}
if ( V_153 == 4 )
F_119 ( L_61 ) ;
V_85 = F_61 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_368 ;
V_365 |= V_387 ;
if ( F_264 ( V_10 ) ) {
V_365 &= ~ V_389 ;
V_365 |= V_390 ;
}
F_116 ( V_85 , V_365 ) ;
V_85 = F_63 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
if ( F_92 ( V_10 ) ) {
V_365 &= ~ V_369 ;
V_365 |= V_395 ;
} else {
V_365 &= ~ V_368 ;
V_365 |= V_387 ;
}
F_116 ( V_85 , V_365 ) ;
F_117 ( V_85 ) ;
F_118 ( 150 ) ;
for ( V_153 = 0 ; V_153 < 4 ; V_153 ++ ) {
V_85 = F_61 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_389 ;
V_365 |= V_394 [ V_153 ] ;
F_116 ( V_85 , V_365 ) ;
F_117 ( V_85 ) ;
F_118 ( 500 ) ;
for ( V_388 = 0 ; V_388 < 5 ; V_388 ++ ) {
V_85 = F_261 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
F_140 ( L_59 , V_365 ) ;
if ( V_365 & V_380 ) {
F_116 ( V_85 , V_365 | V_380 ) ;
F_140 ( L_62 ) ;
break;
}
F_118 ( 50 ) ;
}
if ( V_388 < 5 )
break;
}
if ( V_153 == 4 )
F_119 ( L_63 ) ;
F_140 ( L_65 ) ;
}
static void F_265 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_365 , V_153 , V_396 ;
V_85 = F_258 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_380 ;
V_365 &= ~ V_381 ;
F_116 ( V_85 , V_365 ) ;
F_117 ( V_85 ) ;
F_118 ( 150 ) ;
F_140 ( L_66 ,
F_5 ( F_261 ( V_4 ) ) ) ;
for ( V_396 = 0 ; V_396 < F_266 ( V_394 ) * 2 ; V_396 ++ ) {
V_85 = F_61 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ ( V_397 | V_366 ) ;
V_365 &= ~ V_123 ;
F_116 ( V_85 , V_365 ) ;
V_85 = F_63 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_397 ;
V_365 &= ~ V_369 ;
V_365 &= ~ V_124 ;
F_116 ( V_85 , V_365 ) ;
V_85 = F_61 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_382 ;
V_365 |= F_259 ( V_28 -> V_79 . V_383 ) ;
V_365 |= V_398 ;
V_365 &= ~ V_389 ;
V_365 |= V_394 [ V_396 / 2 ] ;
V_365 |= V_399 ;
F_116 ( V_85 , V_365 | V_123 ) ;
F_116 ( F_263 ( V_4 ) ,
V_391 | V_392 ) ;
V_85 = F_63 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 |= V_393 ;
V_365 |= V_399 ;
F_116 ( V_85 , V_365 | V_124 ) ;
F_117 ( V_85 ) ;
F_118 ( 1 ) ;
for ( V_153 = 0 ; V_153 < 4 ; V_153 ++ ) {
V_85 = F_261 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
F_140 ( L_59 , V_365 ) ;
if ( V_365 & V_381 ||
( F_5 ( V_85 ) & V_381 ) ) {
F_116 ( V_85 , V_365 | V_381 ) ;
F_140 ( L_67 ,
V_153 ) ;
break;
}
F_118 ( 1 ) ;
}
if ( V_153 == 4 ) {
F_140 ( L_68 , V_396 / 2 ) ;
continue;
}
V_85 = F_61 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_366 ;
V_365 |= V_400 ;
F_116 ( V_85 , V_365 ) ;
V_85 = F_63 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_369 ;
V_365 |= V_395 ;
F_116 ( V_85 , V_365 ) ;
F_117 ( V_85 ) ;
F_118 ( 2 ) ;
for ( V_153 = 0 ; V_153 < 4 ; V_153 ++ ) {
V_85 = F_261 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
F_140 ( L_59 , V_365 ) ;
if ( V_365 & V_380 ||
( F_5 ( V_85 ) & V_380 ) ) {
F_116 ( V_85 , V_365 | V_380 ) ;
F_140 ( L_69 ,
V_153 ) ;
goto V_401;
}
F_118 ( 2 ) ;
}
if ( V_153 == 4 )
F_140 ( L_70 , V_396 / 2 ) ;
}
V_401:
F_140 ( L_65 ) ;
}
static void F_267 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_365 ;
V_85 = F_63 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ ( V_382 | ( 0x7 << 16 ) ) ;
V_365 |= F_259 ( V_28 -> V_79 . V_383 ) ;
V_365 |= ( F_5 ( F_44 ( V_4 ) ) & V_233 ) << 11 ;
F_116 ( V_85 , V_365 | V_126 ) ;
F_117 ( V_85 ) ;
F_118 ( 200 ) ;
V_365 = F_5 ( V_85 ) ;
F_116 ( V_85 , V_365 | V_402 ) ;
F_117 ( V_85 ) ;
F_118 ( 200 ) ;
V_85 = F_61 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
if ( ( V_365 & V_125 ) == 0 ) {
F_116 ( V_85 , V_365 | V_125 ) ;
F_117 ( V_85 ) ;
F_118 ( 100 ) ;
}
}
static void F_268 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_365 ;
V_85 = F_63 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
F_116 ( V_85 , V_365 & ~ V_402 ) ;
V_85 = F_61 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
F_116 ( V_85 , V_365 & ~ V_125 ) ;
F_117 ( V_85 ) ;
F_118 ( 100 ) ;
V_85 = F_63 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
F_116 ( V_85 , V_365 & ~ V_126 ) ;
F_117 ( V_85 ) ;
F_118 ( 100 ) ;
}
static void F_269 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_365 ;
V_85 = F_61 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
F_116 ( V_85 , V_365 & ~ V_123 ) ;
F_117 ( V_85 ) ;
V_85 = F_63 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ ( 0x7 << 16 ) ;
V_365 |= ( F_5 ( F_44 ( V_4 ) ) & V_233 ) << 11 ;
F_116 ( V_85 , V_365 & ~ V_124 ) ;
F_117 ( V_85 ) ;
F_118 ( 100 ) ;
if ( F_48 ( V_10 ) )
F_116 ( F_260 ( V_4 ) , V_385 ) ;
V_85 = F_61 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ V_368 ;
V_365 |= V_384 ;
F_116 ( V_85 , V_365 ) ;
V_85 = F_63 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
if ( F_92 ( V_10 ) ) {
V_365 &= ~ V_369 ;
V_365 |= V_393 ;
} else {
V_365 &= ~ V_368 ;
V_365 |= V_384 ;
}
V_365 &= ~ ( 0x07 << 16 ) ;
V_365 |= ( F_5 ( F_44 ( V_4 ) ) & V_233 ) << 11 ;
F_116 ( V_85 , V_365 ) ;
F_117 ( V_85 ) ;
F_118 ( 100 ) ;
}
bool F_270 ( struct V_9 * V_10 )
{
struct V_28 * V_29 ;
F_127 (dev, crtc) {
if ( F_243 ( & V_29 -> V_403 ) == 0 )
continue;
if ( V_29 -> V_354 )
F_167 ( V_10 , V_29 -> V_4 ) ;
return true ;
}
return false ;
}
static void F_271 ( struct V_28 * V_28 )
{
struct V_11 * V_12 = F_228 ( V_28 -> V_8 . V_10 ) ;
struct V_404 * V_405 = V_28 -> V_354 ;
F_272 () ;
V_28 -> V_354 = NULL ;
if ( V_405 -> V_406 )
F_273 ( V_28 -> V_8 . V_10 ,
V_28 -> V_4 ,
V_405 -> V_406 ) ;
F_90 ( & V_28 -> V_8 ) ;
F_274 ( & V_12 -> V_407 ) ;
F_275 ( V_12 -> V_408 , & V_405 -> V_405 ) ;
F_276 ( V_28 -> V_151 ,
V_405 -> V_409 ) ;
}
void F_277 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_3 ( F_278 ( & V_12 -> V_407 ) ) ;
if ( F_3 ( F_279 ( V_12 -> V_407 ,
! F_241 ( V_29 ) ,
60 * V_410 ) == 0 ) ) {
struct V_28 * V_28 = F_37 ( V_29 ) ;
F_234 ( & V_10 -> V_353 ) ;
if ( V_28 -> V_354 ) {
F_280 ( 1 , L_71 ) ;
F_271 ( V_28 ) ;
}
F_235 ( & V_10 -> V_353 ) ;
}
if ( V_29 -> V_77 -> V_78 ) {
F_53 ( & V_10 -> V_267 ) ;
F_239 ( V_29 -> V_77 -> V_78 ) ;
F_55 ( & V_10 -> V_267 ) ;
}
}
static void F_281 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int clock = F_37 ( V_29 ) -> V_79 . V_80 . V_81 ;
T_1 V_411 , V_412 , V_413 , V_414 = 0 ;
T_1 V_365 ;
F_53 ( & V_12 -> V_111 ) ;
F_116 ( V_415 , V_416 ) ;
F_282 ( V_12 , V_417 ,
F_283 ( V_12 , V_417 , V_418 ) |
V_419 ,
V_418 ) ;
if ( clock == 20000 ) {
V_413 = 1 ;
V_411 = 0x41 ;
V_412 = 0x20 ;
} else {
T_1 V_420 = 172800 * 1000 ;
T_1 V_421 = 64 ;
T_1 V_422 , V_423 , V_424 ;
V_422 = ( V_420 / clock ) ;
V_423 = V_422 / V_421 ;
V_424 = V_422 % V_421 ;
V_413 = 0 ;
V_411 = V_423 - 2 ;
V_412 = V_424 ;
}
F_3 ( F_284 ( V_411 ) &
~ V_425 ) ;
F_3 ( F_285 ( V_414 ) &
~ V_426 ) ;
F_140 ( L_72 ,
clock ,
V_413 ,
V_411 ,
V_414 ,
V_412 ) ;
V_365 = F_283 ( V_12 , V_427 , V_418 ) ;
V_365 &= ~ V_425 ;
V_365 |= F_284 ( V_411 ) ;
V_365 &= ~ V_426 ;
V_365 |= F_286 ( V_412 ) ;
V_365 |= F_285 ( V_414 ) ;
V_365 |= V_428 ;
F_282 ( V_12 , V_427 , V_365 , V_418 ) ;
V_365 = F_283 ( V_12 , V_429 , V_418 ) ;
V_365 &= ~ F_287 ( 1 ) ;
V_365 |= F_287 ( V_413 ) ;
F_282 ( V_12 , V_429 , V_365 , V_418 ) ;
V_365 = F_283 ( V_12 , V_417 , V_418 ) ;
V_365 &= ~ V_419 ;
F_282 ( V_12 , V_417 , V_365 , V_418 ) ;
F_118 ( 24 ) ;
F_116 ( V_415 , V_430 ) ;
F_55 ( & V_12 -> V_111 ) ;
}
static void F_288 ( struct V_28 * V_29 ,
enum V_4 V_245 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_82 V_84 = V_29 -> V_79 . V_84 ;
F_116 ( F_289 ( V_245 ) ,
F_5 ( F_290 ( V_84 ) ) ) ;
F_116 ( F_291 ( V_245 ) ,
F_5 ( F_292 ( V_84 ) ) ) ;
F_116 ( F_293 ( V_245 ) ,
F_5 ( F_294 ( V_84 ) ) ) ;
F_116 ( F_295 ( V_245 ) ,
F_5 ( F_296 ( V_84 ) ) ) ;
F_116 ( F_297 ( V_245 ) ,
F_5 ( F_298 ( V_84 ) ) ) ;
F_116 ( F_299 ( V_245 ) ,
F_5 ( F_300 ( V_84 ) ) ) ;
F_116 ( F_301 ( V_245 ) ,
F_5 ( F_302 ( V_84 ) ) ) ;
}
static void F_303 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_365 ;
V_365 = F_5 ( V_377 ) ;
if ( V_365 & V_378 )
return;
F_3 ( F_5 ( F_63 ( V_138 ) ) & V_124 ) ;
F_3 ( F_5 ( F_63 ( V_376 ) ) & V_124 ) ;
V_365 |= V_378 ;
F_140 ( L_73 ) ;
F_116 ( V_377 , V_365 ) ;
F_117 ( V_377 ) ;
}
static void F_304 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
switch ( V_28 -> V_4 ) {
case V_129 :
break;
case V_138 :
if ( V_28 -> V_79 . V_383 > 2 )
F_3 ( F_5 ( V_377 ) & V_378 ) ;
else
F_303 ( V_10 ) ;
break;
case V_376 :
F_303 ( V_10 ) ;
break;
default:
F_134 () ;
}
}
static void F_305 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_365 ;
F_93 ( V_12 , V_4 ) ;
if ( F_254 ( V_10 ) )
F_304 ( V_28 ) ;
F_116 ( F_306 ( V_4 ) ,
F_5 ( F_307 ( V_4 ) ) & V_431 ) ;
V_12 -> V_252 . V_432 ( V_29 ) ;
if ( F_92 ( V_10 ) ) {
T_1 V_433 ;
V_365 = F_5 ( V_434 ) ;
V_365 |= F_308 ( V_4 ) ;
V_433 = F_309 ( V_4 ) ;
if ( V_28 -> V_79 . V_115 == V_435 )
V_365 |= V_433 ;
else
V_365 &= ~ V_433 ;
F_116 ( V_434 , V_365 ) ;
}
F_139 ( V_28 ) ;
F_66 ( V_12 , V_4 ) ;
F_288 ( V_28 , V_4 ) ;
F_253 ( V_29 ) ;
if ( F_92 ( V_10 ) && V_28 -> V_79 . V_436 ) {
T_1 V_437 = ( F_5 ( F_44 ( V_4 ) ) & V_233 ) >> 5 ;
V_85 = F_96 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ ( V_170 |
V_438 |
V_439 ) ;
V_365 |= ( V_440 |
V_441 ) ;
V_365 |= V_437 << 9 ;
if ( V_29 -> V_442 . V_443 & V_444 )
V_365 |= V_445 ;
if ( V_29 -> V_442 . V_443 & V_446 )
V_365 |= V_447 ;
switch ( F_310 ( V_29 ) ) {
case V_184 :
V_365 |= V_185 ;
break;
case V_186 :
V_365 |= V_187 ;
break;
case V_188 :
V_365 |= V_189 ;
break;
default:
F_134 () ;
}
F_116 ( V_85 , V_365 ) ;
}
F_145 ( V_12 , V_4 ) ;
}
static void F_311 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_82 V_84 = V_28 -> V_79 . V_84 ;
F_93 ( V_12 , V_241 ) ;
F_281 ( V_29 ) ;
F_288 ( V_28 , V_129 ) ;
F_149 ( V_12 , V_84 ) ;
}
void F_312 ( struct V_28 * V_29 )
{
struct V_114 * V_117 = F_56 ( V_29 ) ;
if ( V_117 == NULL )
return;
if ( ! ( V_117 -> V_79 . V_224 & ( 1 << V_29 -> V_4 ) ) ) {
F_46 ( 1 , L_74 , V_117 -> V_121 ) ;
return;
}
V_117 -> V_79 . V_224 &= ~ ( 1 << V_29 -> V_4 ) ;
if ( V_117 -> V_79 . V_224 == 0 ) {
F_3 ( V_117 -> V_225 ) ;
F_3 ( V_117 -> V_76 ) ;
}
V_29 -> V_79 . V_115 = V_448 ;
}
struct V_114 * F_313 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
struct V_114 * V_117 ;
enum V_449 V_153 ;
if ( F_48 ( V_12 -> V_10 ) ) {
V_153 = (enum V_449 ) V_29 -> V_4 ;
V_117 = & V_12 -> V_116 [ V_153 ] ;
F_140 ( L_75 ,
V_29 -> V_8 . V_8 . V_227 , V_117 -> V_121 ) ;
F_3 ( V_117 -> V_450 -> V_224 ) ;
goto V_69;
}
for ( V_153 = 0 ; V_153 < V_12 -> V_451 ; V_153 ++ ) {
V_117 = & V_12 -> V_116 [ V_153 ] ;
if ( V_117 -> V_450 -> V_224 == 0 )
continue;
if ( memcmp ( & V_29 -> V_450 -> V_200 ,
& V_117 -> V_450 -> V_119 ,
sizeof( V_117 -> V_450 -> V_119 ) ) == 0 ) {
F_140 ( L_76 ,
V_29 -> V_8 . V_8 . V_227 , V_117 -> V_121 ,
V_117 -> V_450 -> V_224 ,
V_117 -> V_76 ) ;
goto V_69;
}
}
for ( V_153 = 0 ; V_153 < V_12 -> V_451 ; V_153 ++ ) {
V_117 = & V_12 -> V_116 [ V_153 ] ;
if ( V_117 -> V_450 -> V_224 == 0 ) {
F_140 ( L_77 ,
V_29 -> V_8 . V_8 . V_227 , V_117 -> V_121 ) ;
goto V_69;
}
}
return NULL ;
V_69:
if ( V_117 -> V_450 -> V_224 == 0 )
V_117 -> V_450 -> V_119 = V_29 -> V_450 -> V_200 ;
V_29 -> V_450 -> V_115 = V_153 ;
F_137 ( L_78 , V_117 -> V_121 ,
F_68 ( V_29 -> V_4 ) ) ;
V_117 -> V_450 -> V_224 |= 1 << V_29 -> V_4 ;
return V_117 ;
}
static int F_314 ( struct V_11 * V_12 ,
unsigned V_452 )
{
struct V_114 * V_117 ;
enum V_449 V_153 ;
for ( V_153 = 0 ; V_153 < V_12 -> V_451 ; V_153 ++ ) {
V_117 = & V_12 -> V_116 [ V_153 ] ;
V_117 -> V_450 = F_315 ( & V_117 -> V_79 , sizeof V_117 -> V_79 ,
V_453 ) ;
if ( ! V_117 -> V_450 )
goto V_454;
V_117 -> V_450 -> V_224 &= ~ V_452 ;
}
return 0 ;
V_454:
while ( -- V_153 >= 0 ) {
V_117 = & V_12 -> V_116 [ V_153 ] ;
F_195 ( V_117 -> V_450 ) ;
V_117 -> V_450 = NULL ;
}
return - V_455 ;
}
static void F_316 ( struct V_11 * V_12 )
{
struct V_114 * V_117 ;
enum V_449 V_153 ;
for ( V_153 = 0 ; V_153 < V_12 -> V_451 ; V_153 ++ ) {
V_117 = & V_12 -> V_116 [ V_153 ] ;
F_3 ( V_117 -> V_450 == & V_117 -> V_79 ) ;
V_117 -> V_79 = * V_117 -> V_450 ;
F_195 ( V_117 -> V_450 ) ;
V_117 -> V_450 = NULL ;
}
}
static void F_317 ( struct V_11 * V_12 )
{
struct V_114 * V_117 ;
enum V_449 V_153 ;
for ( V_153 = 0 ; V_153 < V_12 -> V_451 ; V_153 ++ ) {
V_117 = & V_12 -> V_116 [ V_153 ] ;
F_3 ( V_117 -> V_450 == & V_117 -> V_79 ) ;
F_195 ( V_117 -> V_450 ) ;
V_117 -> V_450 = NULL ;
}
}
static void F_318 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_456 = F_40 ( V_4 ) ;
T_1 V_365 ;
V_365 = F_5 ( V_456 ) ;
F_118 ( 500 ) ;
if ( F_45 ( F_5 ( V_456 ) != V_365 , 5 ) ) {
if ( F_45 ( F_5 ( V_456 ) != V_365 , 5 ) )
F_119 ( L_79 , F_68 ( V_4 ) ) ;
}
}
static void F_319 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_79 . V_360 . V_106 ) {
F_116 ( F_320 ( V_4 ) , V_457 ) ;
F_116 ( F_321 ( V_4 ) , V_29 -> V_79 . V_360 . V_458 ) ;
F_116 ( F_322 ( V_4 ) , V_29 -> V_79 . V_360 . V_301 ) ;
}
}
static void F_323 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_79 . V_360 . V_106 ) {
if ( F_254 ( V_10 ) || F_212 ( V_10 ) )
F_116 ( F_246 ( V_4 ) , V_459 | V_460 |
F_324 ( V_4 ) ) ;
else
F_116 ( F_246 ( V_4 ) , V_459 | V_460 ) ;
F_116 ( F_247 ( V_4 ) , V_29 -> V_79 . V_360 . V_458 ) ;
F_116 ( F_248 ( V_4 ) , V_29 -> V_79 . V_360 . V_301 ) ;
}
}
static void F_325 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_4 V_4 = F_37 ( V_29 ) -> V_4 ;
struct V_250 * V_151 ;
struct V_461 * V_461 ;
F_326 (plane, &dev->mode_config.plane_list) {
V_461 = F_206 ( V_151 ) ;
if ( V_461 -> V_4 == V_4 )
F_327 ( & V_461 -> V_8 ) ;
}
}
static void F_328 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_4 V_4 = F_37 ( V_29 ) -> V_4 ;
struct V_250 * V_151 ;
struct V_461 * V_461 ;
F_326 (plane, &dev->mode_config.plane_list) {
V_461 = F_206 ( V_151 ) ;
if ( V_461 -> V_4 == V_4 )
F_329 ( & V_461 -> V_8 ) ;
}
}
void F_330 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_79 . V_462 )
return;
F_167 ( V_10 , V_29 -> V_4 ) ;
F_331 ( V_12 , V_29 -> V_151 ) ;
if ( F_166 ( V_10 ) ) {
F_53 ( & V_12 -> V_463 . V_464 ) ;
F_3 ( F_332 ( V_12 , V_465 , 0xc0000000 ) ) ;
F_55 ( & V_12 -> V_463 . V_464 ) ;
} else {
F_116 ( V_466 , V_467 ) ;
if ( F_45 ( F_333 ( V_466 ) & V_467 , 50 ) )
F_119 ( L_80 ) ;
}
}
void F_334 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_79 . V_462 )
return;
F_331 ( V_12 , V_29 -> V_151 ) ;
if ( F_166 ( V_10 ) ) {
F_53 ( & V_12 -> V_463 . V_464 ) ;
F_3 ( F_332 ( V_12 , V_465 , 0 ) ) ;
F_55 ( & V_12 -> V_463 . V_464 ) ;
if ( F_45 ( ( F_5 ( V_466 ) & V_467 ) == 0 , 42 ) )
F_119 ( L_81 ) ;
} else {
F_116 ( V_466 , 0 ) ;
F_117 ( V_466 ) ;
}
F_167 ( V_10 , V_29 -> V_4 ) ;
}
static void F_335 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
int V_468 = F_336 ( V_4 ) ;
int V_153 ;
bool V_469 = false ;
if ( ! V_29 -> V_106 || ! V_28 -> V_76 )
return;
if ( ! F_4 ( V_12 -> V_10 ) ) {
if ( F_10 ( V_28 , V_246 ) )
F_157 ( V_12 ) ;
else
F_158 ( V_12 , V_4 ) ;
}
if ( ! F_337 ( V_10 ) )
V_468 = F_338 ( V_4 ) ;
if ( F_212 ( V_10 ) && V_28 -> V_79 . V_462 &&
( ( F_5 ( F_339 ( V_4 ) ) & V_470 ) ==
V_471 ) ) {
F_334 ( V_28 ) ;
V_469 = true ;
}
for ( V_153 = 0 ; V_153 < 256 ; V_153 ++ ) {
F_116 ( V_468 + 4 * V_153 ,
( V_28 -> V_472 [ V_153 ] << 16 ) |
( V_28 -> V_473 [ V_153 ] << 8 ) |
V_28 -> V_474 [ V_153 ] ) ;
}
if ( V_469 )
F_330 ( V_28 ) ;
}
static void F_340 ( struct V_28 * V_28 , bool V_229 )
{
if ( ! V_229 && V_28 -> V_475 ) {
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_53 ( & V_10 -> V_267 ) ;
V_12 -> V_273 . V_274 = false ;
( void ) F_341 ( V_28 -> V_475 ) ;
V_12 -> V_273 . V_274 = true ;
F_55 ( & V_10 -> V_267 ) ;
}
}
static void F_342 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
F_164 ( V_29 -> V_77 , V_29 ) ;
F_325 ( V_29 ) ;
F_343 ( V_29 , true ) ;
F_340 ( V_28 , true ) ;
F_330 ( V_28 ) ;
F_53 ( & V_10 -> V_267 ) ;
F_252 ( V_10 ) ;
F_55 ( & V_10 -> V_267 ) ;
F_251 ( V_10 , F_344 ( V_4 ) ) ;
}
static void F_345 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
int V_151 = V_28 -> V_151 ;
F_277 ( V_29 ) ;
if ( V_12 -> V_476 . V_151 == V_151 )
F_346 ( V_10 ) ;
F_334 ( V_28 ) ;
F_340 ( V_28 , false ) ;
F_343 ( V_29 , false ) ;
F_328 ( V_29 ) ;
F_168 ( V_29 -> V_77 , V_29 ) ;
F_251 ( V_10 , F_344 ( V_4 ) ) ;
}
static void F_347 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
F_3 ( ! V_29 -> V_106 ) ;
if ( V_28 -> V_76 )
return;
if ( V_28 -> V_79 . V_247 )
F_136 ( V_28 ) ;
if ( V_28 -> V_79 . V_436 )
F_348 ( V_28 ) ;
F_349 ( V_28 ) ;
if ( V_28 -> V_79 . V_247 ) {
F_350 ( V_28 ,
& V_28 -> V_79 . V_477 , NULL ) ;
}
F_351 ( V_29 ) ;
V_28 -> V_76 = true ;
F_352 ( V_12 , V_4 , true ) ;
F_353 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_478 )
V_6 -> V_478 ( V_6 ) ;
if ( V_28 -> V_79 . V_247 ) {
F_267 ( V_28 ) ;
} else {
F_151 ( V_12 , V_4 ) ;
F_152 ( V_12 , V_4 ) ;
}
F_323 ( V_28 ) ;
F_335 ( V_29 ) ;
F_354 ( V_29 ) ;
F_154 ( V_28 ) ;
if ( V_28 -> V_79 . V_247 )
F_305 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_229 ( V_6 ) ;
if ( F_92 ( V_10 ) )
F_318 ( V_10 , V_28 -> V_4 ) ;
F_88 ( V_29 ) ;
F_355 ( V_29 ) ;
F_342 ( V_29 ) ;
}
static bool F_356 ( struct V_28 * V_29 )
{
return F_357 ( V_29 -> V_8 . V_10 ) && V_29 -> V_4 == V_129 ;
}
static void F_358 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_28 * V_479 , * V_480 = NULL ;
F_127 (dev, crtc_it) {
if ( ! V_479 -> V_76 || V_479 == V_29 )
continue;
if ( V_480 )
return;
V_480 = V_479 ;
}
if ( ! V_480 )
return;
F_167 ( V_10 , V_480 -> V_4 ) ;
F_167 ( V_10 , V_480 -> V_4 ) ;
}
static void F_359 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
F_3 ( ! V_29 -> V_106 ) ;
if ( V_28 -> V_76 )
return;
if ( F_56 ( V_28 ) )
F_139 ( V_28 ) ;
if ( V_28 -> V_79 . V_436 )
F_348 ( V_28 ) ;
F_349 ( V_28 ) ;
if ( V_28 -> V_79 . V_84 != V_481 ) {
F_116 ( F_360 ( V_28 -> V_79 . V_84 ) ,
V_28 -> V_79 . V_482 - 1 ) ;
}
if ( V_28 -> V_79 . V_247 ) {
F_350 ( V_28 ,
& V_28 -> V_79 . V_477 , NULL ) ;
}
F_361 ( V_29 ) ;
F_362 ( V_29 ) ;
V_28 -> V_76 = true ;
F_352 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_478 )
V_6 -> V_478 ( V_6 ) ;
if ( V_28 -> V_79 . V_247 ) {
F_353 ( V_12 , V_241 ,
true ) ;
V_12 -> V_252 . V_432 ( V_29 ) ;
}
F_363 ( V_28 ) ;
if ( F_364 ( V_10 ) )
F_319 ( V_28 ) ;
else
F_323 ( V_28 ) ;
F_335 ( V_29 ) ;
F_365 ( V_29 ) ;
F_366 ( V_29 ) ;
F_354 ( V_29 ) ;
F_154 ( V_28 ) ;
if ( V_28 -> V_79 . V_247 )
F_311 ( V_29 ) ;
if ( V_28 -> V_79 . V_483 )
F_367 ( V_29 , true ) ;
F_11 (dev, crtc, encoder) {
V_6 -> V_229 ( V_6 ) ;
F_368 ( V_6 , true ) ;
}
F_88 ( V_29 ) ;
F_355 ( V_29 ) ;
F_358 ( V_28 ) ;
F_342 ( V_29 ) ;
}
static void F_369 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_79 . V_360 . V_106 ) {
F_116 ( F_320 ( V_4 ) , 0 ) ;
F_116 ( F_321 ( V_4 ) , 0 ) ;
F_116 ( F_322 ( V_4 ) , 0 ) ;
}
}
static void F_370 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
if ( V_29 -> V_79 . V_360 . V_106 ) {
F_116 ( F_246 ( V_4 ) , 0 ) ;
F_116 ( F_247 ( V_4 ) , 0 ) ;
F_116 ( F_248 ( V_4 ) , 0 ) ;
}
}
static void F_371 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
T_1 V_85 , V_365 ;
if ( ! V_28 -> V_76 )
return;
F_345 ( V_29 ) ;
F_372 ( V_29 ) ;
F_88 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_230 ( V_6 ) ;
if ( V_28 -> V_79 . V_247 )
F_353 ( V_12 , V_4 , false ) ;
F_160 ( V_28 ) ;
F_370 ( V_28 ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_484 )
V_6 -> V_484 ( V_6 ) ;
if ( V_28 -> V_79 . V_247 ) {
F_269 ( V_29 ) ;
F_150 ( V_12 , V_4 ) ;
if ( F_92 ( V_10 ) ) {
V_85 = F_96 ( V_4 ) ;
V_365 = F_5 ( V_85 ) ;
V_365 &= ~ ( V_440 |
V_170 ) ;
V_365 |= V_485 ;
F_116 ( V_85 , V_365 ) ;
V_365 = F_5 ( V_434 ) ;
V_365 &= ~ ( F_308 ( V_4 ) | F_309 ( V_4 ) ) ;
F_116 ( V_434 , V_365 ) ;
}
F_143 ( V_28 ) ;
F_268 ( V_28 ) ;
}
V_28 -> V_76 = false ;
F_354 ( V_29 ) ;
F_53 ( & V_10 -> V_267 ) ;
F_252 ( V_10 ) ;
F_55 ( & V_10 -> V_267 ) ;
}
static void F_373 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_1 * V_6 ;
enum V_82 V_84 = V_28 -> V_79 . V_84 ;
if ( ! V_28 -> V_76 )
return;
F_345 ( V_29 ) ;
F_372 ( V_29 ) ;
F_88 ( V_29 ) ;
F_11 (dev, crtc, encoder) {
F_368 ( V_6 , false ) ;
V_6 -> V_230 ( V_6 ) ;
}
if ( V_28 -> V_79 . V_247 )
F_353 ( V_12 , V_241 ,
false ) ;
F_160 ( V_28 ) ;
if ( V_28 -> V_79 . V_483 )
F_367 ( V_29 , false ) ;
F_374 ( V_12 , V_84 ) ;
if ( F_364 ( V_10 ) )
F_369 ( V_28 ) ;
else
F_370 ( V_28 ) ;
F_375 ( V_28 ) ;
if ( V_28 -> V_79 . V_247 ) {
F_153 ( V_12 ) ;
F_376 ( V_29 ) ;
}
F_11 (dev, crtc, encoder)
if ( V_6 -> V_484 )
V_6 -> V_484 ( V_6 ) ;
V_28 -> V_76 = false ;
F_354 ( V_29 ) ;
F_53 ( & V_10 -> V_267 ) ;
F_252 ( V_10 ) ;
F_55 ( & V_10 -> V_267 ) ;
if ( F_56 ( V_28 ) )
F_143 ( V_28 ) ;
}
static void F_377 ( struct V_75 * V_29 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
F_312 ( V_28 ) ;
}
static void F_378 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_198 * V_199 = & V_29 -> V_79 ;
if ( ! V_29 -> V_79 . V_486 . V_487 )
return;
F_3 ( F_5 ( V_488 ) & V_489 ) ;
F_113 ( V_12 , V_29 -> V_4 ) ;
F_116 ( V_490 , V_199 -> V_486 . V_491 ) ;
F_116 ( V_488 , V_199 -> V_486 . V_487 ) ;
F_116 ( F_379 ( V_29 -> V_4 ) , 0 ) ;
}
static enum V_492 F_380 ( enum V_94 V_94 )
{
switch ( V_94 ) {
case V_493 :
return V_494 ;
case V_96 :
return V_495 ;
case V_98 :
return V_496 ;
case V_100 :
return V_497 ;
default:
F_381 ( 1 ) ;
return V_498 ;
}
}
enum V_492
F_382 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_8 . V_10 ;
struct V_93 * V_499 ;
switch ( V_1 -> type ) {
case V_500 :
F_381 ( ! F_59 ( V_10 ) ) ;
case V_501 :
case V_41 :
case V_361 :
V_499 = F_383 ( & V_1 -> V_8 ) ;
return F_380 ( V_499 -> V_94 ) ;
case V_502 :
V_499 = F_384 ( & V_1 -> V_8 ) -> V_77 ;
return F_380 ( V_499 -> V_94 ) ;
case V_42 :
return V_503 ;
case V_246 :
return V_504 ;
default:
return V_498 ;
}
}
static unsigned long F_385 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_1 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
unsigned long V_505 ;
enum V_82 V_82 ;
V_82 = F_38 ( V_10 -> V_13 , V_4 ) ;
V_505 = F_207 ( F_386 ( V_4 ) ) ;
V_505 |= F_207 ( F_75 ( V_82 ) ) ;
if ( V_28 -> V_79 . V_360 . V_106 ||
V_28 -> V_79 . V_360 . V_506 )
V_505 |= F_207 ( F_387 ( V_4 ) ) ;
F_11 (dev, crtc, intel_encoder)
V_505 |= F_207 ( F_382 ( V_1 ) ) ;
return V_505 ;
}
static void F_388 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned long V_507 [ V_508 ] = { 0 , } ;
struct V_28 * V_29 ;
F_127 (dev, crtc) {
enum V_492 V_509 ;
if ( ! V_29 -> V_8 . V_106 )
continue;
V_507 [ V_29 -> V_4 ] = F_385 ( & V_29 -> V_8 ) ;
F_389 (domain, pipe_domains[crtc->pipe])
F_142 ( V_12 , V_509 ) ;
}
if ( V_12 -> V_252 . V_510 )
V_12 -> V_252 . V_510 ( V_10 ) ;
F_127 (dev, crtc) {
enum V_492 V_509 ;
F_389 (domain, crtc->enabled_power_domains)
F_144 ( V_12 , V_509 ) ;
V_29 -> V_511 = V_507 [ V_29 -> V_4 ] ;
}
F_390 ( V_12 , false ) ;
}
static int F_391 ( struct V_11 * V_12 )
{
int V_512 , V_513 [] = { 800 , 1600 , 2000 , 2400 } ;
F_53 ( & V_12 -> V_111 ) ;
V_512 = F_54 ( V_12 , V_514 ) &
V_515 ;
F_55 ( & V_12 -> V_111 ) ;
return V_513 [ V_512 ] * 1000 ;
}
static void F_392 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_516 = V_12 -> V_252 . V_517 ( V_10 ) ;
F_137 ( L_82 ,
V_12 -> V_516 ) ;
F_116 ( V_518 , F_393 ( V_12 -> V_516 , 1000 ) ) ;
}
static void F_394 ( struct V_9 * V_10 , int V_519 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_108 , V_520 ;
F_3 ( V_12 -> V_252 . V_517 ( V_10 ) != V_12 -> V_516 ) ;
if ( V_519 >= 320000 )
V_520 = 2 ;
else if ( V_519 == 266667 )
V_520 = 1 ;
else
V_520 = 0 ;
F_53 ( & V_12 -> V_463 . V_464 ) ;
V_108 = F_395 ( V_12 , V_521 ) ;
V_108 &= ~ V_522 ;
V_108 |= ( V_520 << V_523 ) ;
F_396 ( V_12 , V_521 , V_108 ) ;
if ( F_45 ( ( F_395 ( V_12 , V_521 ) &
V_524 ) == ( V_520 << V_525 ) ,
50 ) ) {
F_119 ( L_83 ) ;
}
F_55 ( & V_12 -> V_463 . V_464 ) ;
if ( V_519 == 400000 ) {
T_1 V_526 ;
V_526 = F_9 ( V_12 -> V_512 << 1 , V_519 ) - 1 ;
F_53 ( & V_12 -> V_111 ) ;
V_108 = F_54 ( V_12 , V_527 ) ;
V_108 &= ~ V_528 ;
V_108 |= V_526 ;
F_397 ( V_12 , V_527 , V_108 ) ;
if ( F_45 ( ( F_54 ( V_12 , V_527 ) &
V_529 ) == ( V_526 << V_530 ) ,
50 ) )
F_119 ( L_83 ) ;
F_55 ( & V_12 -> V_111 ) ;
}
F_53 ( & V_12 -> V_111 ) ;
V_108 = F_398 ( V_12 , V_531 ) ;
V_108 &= ~ 0x7f ;
if ( V_519 == 400000 )
V_108 |= 4500 / 250 ;
else
V_108 |= 3000 / 250 ;
F_399 ( V_12 , V_531 , V_108 ) ;
F_55 ( & V_12 -> V_111 ) ;
F_392 ( V_10 ) ;
}
static void F_400 ( struct V_9 * V_10 , int V_519 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_108 , V_520 ;
F_3 ( V_12 -> V_252 . V_517 ( V_10 ) != V_12 -> V_516 ) ;
switch ( V_519 ) {
case 400000 :
V_520 = 3 ;
break;
case 333333 :
case 320000 :
V_520 = 2 ;
break;
case 266667 :
V_520 = 1 ;
break;
case 200000 :
V_520 = 0 ;
break;
default:
F_3 ( 1 ) ;
return;
}
F_53 ( & V_12 -> V_463 . V_464 ) ;
V_108 = F_395 ( V_12 , V_521 ) ;
V_108 &= ~ V_532 ;
V_108 |= ( V_520 << V_533 ) ;
F_396 ( V_12 , V_521 , V_108 ) ;
if ( F_45 ( ( F_395 ( V_12 , V_521 ) &
V_534 ) == ( V_520 << V_535 ) ,
50 ) ) {
F_119 ( L_83 ) ;
}
F_55 ( & V_12 -> V_463 . V_464 ) ;
F_392 ( V_10 ) ;
}
static int F_401 ( struct V_11 * V_12 ,
int V_536 )
{
int V_537 = ( V_12 -> V_512 << 1 ) % 320000 != 0 ? 333333 : 320000 ;
if ( F_20 ( V_12 -> V_10 ) )
return 400000 ;
if ( V_536 > V_537 * 9 / 10 )
return 400000 ;
else if ( V_536 > 266667 * 9 / 10 )
return V_537 ;
else if ( V_536 > 0 )
return 266667 ;
else
return 200000 ;
}
static int F_402 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_28 * V_28 ;
int V_536 = 0 ;
F_127 (dev, intel_crtc) {
if ( V_28 -> V_538 )
V_536 = V_59 ( V_536 ,
V_28 -> V_450 -> V_80 . V_81 ) ;
}
return V_536 ;
}
static void F_403 ( struct V_9 * V_10 ,
unsigned * V_539 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 ;
int V_536 = F_402 ( V_12 ) ;
if ( F_401 ( V_12 , V_536 ) ==
V_12 -> V_516 )
return;
F_127 (dev, intel_crtc)
if ( V_28 -> V_8 . V_106 )
* V_539 |= ( 1 << V_28 -> V_4 ) ;
}
static void F_404 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_536 = F_402 ( V_12 ) ;
int V_540 = F_401 ( V_12 , V_536 ) ;
if ( V_540 != V_12 -> V_516 ) {
F_142 ( V_12 , V_541 ) ;
if ( F_20 ( V_10 ) )
F_400 ( V_10 , V_540 ) ;
else
F_394 ( V_10 , V_540 ) ;
F_144 ( V_12 , V_541 ) ;
}
}
static void F_405 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = F_228 ( V_10 ) ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
bool V_542 ;
F_3 ( ! V_29 -> V_106 ) ;
if ( V_28 -> V_76 )
return;
V_542 = F_10 ( V_28 , V_246 ) ;
if ( ! V_542 ) {
if ( F_20 ( V_10 ) )
F_406 ( V_28 , & V_28 -> V_79 ) ;
else
F_407 ( V_28 , & V_28 -> V_79 ) ;
}
if ( V_28 -> V_79 . V_436 )
F_348 ( V_28 ) ;
F_349 ( V_28 ) ;
if ( F_20 ( V_10 ) && V_4 == V_138 ) {
struct V_11 * V_12 = V_10 -> V_13 ;
F_116 ( F_408 ( V_4 ) , V_543 ) ;
F_116 ( F_409 ( V_4 ) , 0 ) ;
}
F_410 ( V_28 ) ;
V_28 -> V_76 = true ;
F_352 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_544 )
V_6 -> V_544 ( V_6 ) ;
if ( ! V_542 ) {
if ( F_20 ( V_10 ) )
F_121 ( V_28 , & V_28 -> V_79 ) ;
else
F_112 ( V_28 , & V_28 -> V_79 ) ;
}
F_11 (dev, crtc, encoder)
if ( V_6 -> V_478 )
V_6 -> V_478 ( V_6 ) ;
F_378 ( V_28 ) ;
F_335 ( V_29 ) ;
F_354 ( V_29 ) ;
F_154 ( V_28 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_229 ( V_6 ) ;
F_88 ( V_29 ) ;
F_355 ( V_29 ) ;
F_342 ( V_29 ) ;
F_411 ( V_12 ) ;
}
static void F_412 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_116 ( F_413 ( V_29 -> V_4 ) , V_29 -> V_79 . V_200 . V_545 ) ;
F_116 ( F_414 ( V_29 -> V_4 ) , V_29 -> V_79 . V_200 . V_546 ) ;
}
static void F_415 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = F_228 ( V_10 ) ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
F_3 ( ! V_29 -> V_106 ) ;
if ( V_28 -> V_76 )
return;
F_412 ( V_28 ) ;
if ( V_28 -> V_79 . V_436 )
F_348 ( V_28 ) ;
F_349 ( V_28 ) ;
F_410 ( V_28 ) ;
V_28 -> V_76 = true ;
if ( ! F_22 ( V_10 ) )
F_352 ( V_12 , V_4 , true ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_478 )
V_6 -> V_478 ( V_6 ) ;
F_128 ( V_28 ) ;
F_378 ( V_28 ) ;
F_335 ( V_29 ) ;
F_354 ( V_29 ) ;
F_154 ( V_28 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_229 ( V_6 ) ;
F_88 ( V_29 ) ;
F_355 ( V_29 ) ;
F_342 ( V_29 ) ;
if ( F_22 ( V_10 ) )
F_352 ( V_12 , V_4 , true ) ;
F_411 ( V_12 ) ;
}
static void F_416 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! V_29 -> V_79 . V_486 . V_487 )
return;
F_113 ( V_12 , V_29 -> V_4 ) ;
F_137 ( L_84 ,
F_5 ( V_488 ) ) ;
F_116 ( V_488 , 0 ) ;
}
static void F_417 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_1 * V_6 ;
int V_4 = V_28 -> V_4 ;
if ( ! V_28 -> V_76 )
return;
if ( F_22 ( V_10 ) )
F_352 ( V_12 , V_4 , false ) ;
F_418 ( V_12 , false ) ;
F_345 ( V_29 ) ;
F_167 ( V_10 , V_4 ) ;
F_372 ( V_29 ) ;
F_88 ( V_29 ) ;
F_11 (dev, crtc, encoder)
V_6 -> V_230 ( V_6 ) ;
F_160 ( V_28 ) ;
F_416 ( V_28 ) ;
F_11 (dev, crtc, encoder)
if ( V_6 -> V_484 )
V_6 -> V_484 ( V_6 ) ;
if ( ! F_10 ( V_28 , V_246 ) ) {
if ( F_20 ( V_10 ) )
F_132 ( V_12 , V_4 ) ;
else if ( F_21 ( V_10 ) )
F_131 ( V_12 , V_4 ) ;
else
F_130 ( V_28 ) ;
}
if ( ! F_22 ( V_10 ) )
F_352 ( V_12 , V_4 , false ) ;
V_28 -> V_76 = false ;
F_354 ( V_29 ) ;
F_53 ( & V_10 -> V_267 ) ;
F_252 ( V_10 ) ;
F_55 ( & V_10 -> V_267 ) ;
}
static void F_419 ( struct V_75 * V_29 )
{
}
void F_420 ( struct V_75 * V_29 , bool V_229 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_492 V_509 ;
unsigned long V_547 ;
if ( V_229 ) {
if ( ! V_28 -> V_76 ) {
V_547 = F_385 ( V_29 ) ;
F_389 (domain, domains)
F_142 ( V_12 , V_509 ) ;
V_28 -> V_511 = V_547 ;
V_12 -> V_252 . V_548 ( V_29 ) ;
}
} else {
if ( V_28 -> V_76 ) {
V_12 -> V_252 . V_345 ( V_29 ) ;
V_547 = V_28 -> V_511 ;
F_389 (domain, domains)
F_144 ( V_12 , V_509 ) ;
V_28 -> V_511 = 0 ;
}
}
}
void F_421 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_1 ;
bool V_229 = false ;
F_11 (dev, crtc, intel_encoder)
V_229 |= V_1 -> V_549 ;
F_420 ( V_29 , V_229 ) ;
}
static void F_422 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_550 * V_3 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_263 * V_362 = F_174 ( V_29 -> V_77 -> V_78 ) ;
enum V_4 V_4 = F_37 ( V_29 ) -> V_4 ;
F_3 ( ! V_29 -> V_106 ) ;
V_12 -> V_252 . V_345 ( V_29 ) ;
V_12 -> V_252 . V_551 ( V_29 ) ;
if ( V_29 -> V_77 -> V_78 ) {
F_53 ( & V_10 -> V_267 ) ;
F_184 ( V_362 ) ;
F_250 ( V_362 , NULL ,
F_192 ( V_4 ) ) ;
F_55 ( & V_10 -> V_267 ) ;
V_29 -> V_77 -> V_78 = NULL ;
}
F_423 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_3 -> V_6 || ! V_3 -> V_6 -> V_29 )
continue;
if ( V_3 -> V_6 -> V_29 != V_29 )
continue;
V_3 -> V_552 = V_553 ;
F_424 ( V_3 -> V_6 ) -> V_549 = false ;
}
}
void F_425 ( struct V_554 * V_6 )
{
struct V_1 * V_1 = F_424 ( V_6 ) ;
F_426 ( V_6 ) ;
F_195 ( V_1 ) ;
}
static void F_427 ( struct V_1 * V_6 , int V_442 )
{
if ( V_442 == V_555 ) {
V_6 -> V_549 = true ;
F_421 ( V_6 -> V_8 . V_29 ) ;
} else {
V_6 -> V_549 = false ;
F_421 ( V_6 -> V_8 . V_29 ) ;
}
}
static void F_428 ( struct V_2 * V_3 )
{
if ( V_3 -> V_120 ( V_3 ) ) {
struct V_1 * V_6 = V_3 -> V_6 ;
struct V_75 * V_29 ;
bool V_556 ;
enum V_4 V_4 ;
F_140 ( L_85 ,
V_3 -> V_8 . V_8 . V_227 ,
V_3 -> V_8 . V_121 ) ;
if ( V_3 -> V_5 )
return;
F_46 ( V_3 -> V_8 . V_552 == V_553 ,
L_86 ) ;
F_46 ( V_3 -> V_8 . V_6 != & V_6 -> V_8 ,
L_87 ) ;
if ( V_6 ) {
F_46 ( ! V_6 -> V_549 ,
L_88 ) ;
V_556 = V_6 -> V_120 ( V_6 , & V_4 ) ;
F_46 ( ! V_556 , L_89 ) ;
if ( F_3 ( ! V_6 -> V_8 . V_29 ) )
return;
V_29 = V_6 -> V_8 . V_29 ;
F_46 ( ! V_29 -> V_106 , L_90 ) ;
F_46 ( ! F_37 ( V_29 ) -> V_76 , L_91 ) ;
F_46 ( V_4 != F_37 ( V_29 ) -> V_4 ,
L_92 ) ;
}
}
}
void F_429 ( struct V_550 * V_3 , int V_442 )
{
if ( V_442 != V_555 )
V_442 = V_553 ;
if ( V_442 == V_3 -> V_552 )
return;
V_3 -> V_552 = V_442 ;
if ( V_3 -> V_6 )
F_427 ( F_424 ( V_3 -> V_6 ) , V_442 ) ;
F_430 ( V_3 -> V_10 ) ;
}
bool F_431 ( struct V_2 * V_3 )
{
enum V_4 V_4 = 0 ;
struct V_1 * V_6 = V_3 -> V_6 ;
return V_6 -> V_120 ( V_6 , & V_4 ) ;
}
static bool F_432 ( struct V_9 * V_10 , enum V_4 V_4 ,
struct V_198 * V_199 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_374 =
F_37 ( V_12 -> V_83 [ V_138 ] ) ;
F_140 ( L_93 ,
F_68 ( V_4 ) , V_199 -> V_383 ) ;
if ( V_199 -> V_383 > 4 ) {
F_140 ( L_94 ,
F_68 ( V_4 ) , V_199 -> V_383 ) ;
return false ;
}
if ( F_212 ( V_10 ) || F_166 ( V_10 ) ) {
if ( V_199 -> V_383 > 2 ) {
F_140 ( L_95 ,
V_199 -> V_383 ) ;
return false ;
} else {
return true ;
}
}
if ( F_43 ( V_10 ) -> V_364 == 2 )
return true ;
switch ( V_4 ) {
case V_129 :
return true ;
case V_138 :
if ( V_12 -> V_83 [ V_376 ] -> V_106 &&
V_199 -> V_383 > 2 ) {
F_140 ( L_96 ,
F_68 ( V_4 ) , V_199 -> V_383 ) ;
return false ;
}
return true ;
case V_376 :
if ( ! F_255 ( V_374 ) ||
V_374 -> V_79 . V_383 <= 2 ) {
if ( V_199 -> V_383 > 2 ) {
F_140 ( L_96 ,
F_68 ( V_4 ) , V_199 -> V_383 ) ;
return false ;
}
} else {
F_140 ( L_97 ) ;
return false ;
}
return true ;
default:
F_134 () ;
}
}
static int F_433 ( struct V_28 * V_28 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_355 * V_80 = & V_199 -> V_80 ;
int V_557 , V_558 , V_559 ;
bool V_560 , V_561 = false ;
V_388:
V_558 = F_6 ( V_10 ) * F_434 ( 100 ) / F_435 ( 1 ) / 10 ;
V_559 = V_80 -> V_81 ;
V_557 = F_436 ( V_559 , V_558 ,
V_199 -> V_562 ) ;
V_199 -> V_383 = V_557 ;
F_437 ( V_199 -> V_562 , V_557 , V_559 ,
V_558 , & V_199 -> V_477 ) ;
V_560 = F_432 ( V_28 -> V_8 . V_10 ,
V_28 -> V_4 , V_199 ) ;
if ( ! V_560 && V_199 -> V_562 > 6 * 3 ) {
V_199 -> V_562 -= 2 * 3 ;
F_140 ( L_98 ,
V_199 -> V_562 ) ;
V_561 = true ;
V_199 -> V_563 = true ;
goto V_388;
}
if ( V_561 )
return V_564 ;
return V_560 ? 0 : - V_272 ;
}
static void F_438 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
V_199 -> V_462 = V_356 . V_565 &&
F_356 ( V_29 ) &&
V_199 -> V_562 <= 24 ;
}
static int F_439 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_355 * V_80 = & V_199 -> V_80 ;
if ( F_43 ( V_10 ) -> V_91 < 4 ) {
int V_566 =
V_12 -> V_252 . V_517 ( V_10 ) ;
if ( ( V_29 -> V_4 == V_129 || F_440 ( V_10 ) ) &&
V_80 -> V_81 > V_566 * 9 / 10 ) {
V_566 *= 2 ;
V_199 -> V_248 = true ;
}
if ( V_80 -> V_81 > V_566 * 9 / 10 )
return - V_272 ;
}
if ( ( F_10 ( V_29 , V_33 ) &&
F_15 ( V_10 ) ) || V_199 -> V_248 )
V_199 -> V_316 &= ~ 1 ;
if ( ( F_43 ( V_10 ) -> V_91 > 4 || F_18 ( V_10 ) ) &&
V_80 -> V_567 == V_80 -> V_568 )
return - V_272 ;
if ( ( F_18 ( V_10 ) || F_21 ( V_10 ) ) && V_199 -> V_562 > 10 * 3 ) {
V_199 -> V_562 = 10 * 3 ;
} else if ( F_43 ( V_10 ) -> V_91 <= 4 && V_199 -> V_562 > 8 * 3 ) {
V_199 -> V_562 = 8 * 3 ;
}
if ( F_357 ( V_10 ) )
F_438 ( V_29 , V_199 ) ;
if ( V_199 -> V_247 )
return F_433 ( V_29 , V_199 ) ;
return 0 ;
}
static int F_441 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_108 ;
int V_526 ;
if ( F_20 ( V_10 ) )
return 400000 ;
if ( V_12 -> V_512 == 0 )
V_12 -> V_512 = F_391 ( V_12 ) ;
F_53 ( & V_12 -> V_111 ) ;
V_108 = F_54 ( V_12 , V_527 ) ;
F_55 ( & V_12 -> V_111 ) ;
V_526 = V_108 & V_528 ;
F_46 ( ( V_108 & V_529 ) !=
( V_526 << V_530 ) ,
L_99 ) ;
return F_9 ( V_12 -> V_512 << 1 , V_526 + 1 ) ;
}
static int F_442 ( struct V_9 * V_10 )
{
return 400000 ;
}
static int F_443 ( struct V_9 * V_10 )
{
return 333000 ;
}
static int F_444 ( struct V_9 * V_10 )
{
return 200000 ;
}
static int F_445 ( struct V_9 * V_10 )
{
T_5 V_569 = 0 ;
F_446 ( V_10 -> V_570 , V_571 , & V_569 ) ;
switch ( V_569 & V_572 ) {
case V_573 :
return 267000 ;
case V_574 :
return 333000 ;
case V_575 :
return 444000 ;
case V_576 :
return 200000 ;
default:
F_119 ( L_100 , V_569 ) ;
case V_577 :
return 133000 ;
case V_578 :
return 167000 ;
}
}
static int F_447 ( struct V_9 * V_10 )
{
T_5 V_569 = 0 ;
F_446 ( V_10 -> V_570 , V_571 , & V_569 ) ;
if ( V_569 & V_579 )
return 133000 ;
else {
switch ( V_569 & V_572 ) {
case V_580 :
return 333000 ;
default:
case V_581 :
return 190000 ;
}
}
}
static int F_448 ( struct V_9 * V_10 )
{
return 266000 ;
}
static int F_449 ( struct V_9 * V_10 )
{
T_5 V_582 = 0 ;
switch ( V_582 & V_583 ) {
case V_584 :
case V_585 :
return 200000 ;
case V_586 :
return 250000 ;
case V_587 :
return 133000 ;
}
return 0 ;
}
static int F_450 ( struct V_9 * V_10 )
{
return 133000 ;
}
static void
F_451 ( T_4 * V_588 , T_4 * V_589 )
{
while ( * V_588 > V_590 ||
* V_589 > V_590 ) {
* V_588 >>= 1 ;
* V_589 >>= 1 ;
}
}
static void F_452 ( unsigned int V_19 , unsigned int V_25 ,
T_4 * V_591 , T_4 * V_592 )
{
* V_592 = F_453 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_591 = F_34 ( ( V_57 ) V_19 * * V_592 , V_25 ) ;
F_451 ( V_591 , V_592 ) ;
}
void
F_437 ( int V_593 , int V_594 ,
int V_595 , int V_596 ,
struct V_597 * V_598 )
{
V_598 -> V_599 = 64 ;
F_452 ( V_593 * V_595 ,
V_596 * V_594 * 8 ,
& V_598 -> V_600 , & V_598 -> V_601 ) ;
F_452 ( V_595 , V_596 ,
& V_598 -> V_602 , & V_598 -> V_603 ) ;
}
static inline bool F_454 ( struct V_11 * V_12 )
{
if ( V_356 . V_604 >= 0 )
return V_356 . V_604 != 0 ;
return V_12 -> V_605 . V_606
&& ! ( V_12 -> V_147 & V_607 ) ;
}
static int F_455 ( struct V_28 * V_29 , int V_608 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_18 ;
if ( F_21 ( V_10 ) ) {
V_18 = 100000 ;
} else if ( F_12 ( V_29 , V_33 ) &&
F_454 ( V_12 ) && V_608 < 2 ) {
V_18 = V_12 -> V_605 . V_609 ;
F_140 ( L_101 , V_18 ) ;
} else if ( ! F_22 ( V_10 ) ) {
V_18 = 96000 ;
} else {
V_18 = 48000 ;
}
return V_18 ;
}
static T_4 F_456 ( struct V_56 * V_56 )
{
return ( 1 << V_56 -> V_25 ) << 16 | V_56 -> V_21 ;
}
static T_4 F_457 ( struct V_56 * V_56 )
{
return V_56 -> V_25 << 16 | V_56 -> V_20 << 8 | V_56 -> V_21 ;
}
static void F_458 ( struct V_28 * V_29 ,
T_2 * V_610 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_1 V_611 , V_612 = 0 ;
if ( F_19 ( V_10 ) ) {
V_611 = F_456 ( & V_29 -> V_450 -> V_56 ) ;
if ( V_610 )
V_612 = F_456 ( V_610 ) ;
} else {
V_611 = F_457 ( & V_29 -> V_450 -> V_56 ) ;
if ( V_610 )
V_612 = F_457 ( V_610 ) ;
}
V_29 -> V_450 -> V_200 . V_545 = V_611 ;
V_29 -> V_613 = false ;
if ( F_12 ( V_29 , V_33 ) &&
V_610 && V_356 . V_614 ) {
V_29 -> V_450 -> V_200 . V_546 = V_612 ;
V_29 -> V_613 = true ;
} else {
V_29 -> V_450 -> V_200 . V_546 = V_611 ;
}
}
static void F_459 ( struct V_11 * V_12 , enum V_4
V_4 )
{
T_1 V_615 ;
V_615 = F_123 ( V_12 , V_4 , F_460 ( 1 ) ) ;
V_615 &= 0xffffff00 ;
V_615 |= 0x00000030 ;
F_125 ( V_12 , V_4 , F_460 ( 1 ) , V_615 ) ;
V_615 = F_123 ( V_12 , V_4 , V_616 ) ;
V_615 &= 0x8cffffff ;
V_615 = 0x8c000000 ;
F_125 ( V_12 , V_4 , V_616 , V_615 ) ;
V_615 = F_123 ( V_12 , V_4 , F_460 ( 1 ) ) ;
V_615 &= 0xffffff00 ;
F_125 ( V_12 , V_4 , F_460 ( 1 ) , V_615 ) ;
V_615 = F_123 ( V_12 , V_4 , V_616 ) ;
V_615 &= 0x00ffffff ;
V_615 |= 0xb0000000 ;
F_125 ( V_12 , V_4 , V_616 , V_615 ) ;
}
static void F_461 ( struct V_28 * V_29 ,
struct V_597 * V_598 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
F_116 ( F_462 ( V_4 ) , F_463 ( V_598 -> V_599 ) | V_598 -> V_600 ) ;
F_116 ( F_464 ( V_4 ) , V_598 -> V_601 ) ;
F_116 ( F_465 ( V_4 ) , V_598 -> V_602 ) ;
F_116 ( F_466 ( V_4 ) , V_598 -> V_603 ) ;
}
static void F_350 ( struct V_28 * V_29 ,
struct V_597 * V_598 ,
struct V_597 * V_617 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
enum V_82 V_82 = V_29 -> V_79 . V_84 ;
if ( F_43 ( V_10 ) -> V_91 >= 5 ) {
F_116 ( F_307 ( V_82 ) , F_463 ( V_598 -> V_599 ) | V_598 -> V_600 ) ;
F_116 ( F_467 ( V_82 ) , V_598 -> V_601 ) ;
F_116 ( F_468 ( V_82 ) , V_598 -> V_602 ) ;
F_116 ( F_469 ( V_82 ) , V_598 -> V_603 ) ;
if ( V_617 && F_43 ( V_10 ) -> V_91 < 8 &&
V_29 -> V_79 . V_618 ) {
F_116 ( F_470 ( V_82 ) ,
F_463 ( V_617 -> V_599 ) | V_617 -> V_600 ) ;
F_116 ( F_471 ( V_82 ) , V_617 -> V_601 ) ;
F_116 ( F_472 ( V_82 ) , V_617 -> V_602 ) ;
F_116 ( F_473 ( V_82 ) , V_617 -> V_603 ) ;
}
} else {
F_116 ( F_474 ( V_4 ) , F_463 ( V_598 -> V_599 ) | V_598 -> V_600 ) ;
F_116 ( F_475 ( V_4 ) , V_598 -> V_601 ) ;
F_116 ( F_476 ( V_4 ) , V_598 -> V_602 ) ;
F_116 ( F_477 ( V_4 ) , V_598 -> V_603 ) ;
}
}
void F_348 ( struct V_28 * V_29 )
{
if ( V_29 -> V_79 . V_247 )
F_461 ( V_29 , & V_29 -> V_79 . V_619 ) ;
else
F_350 ( V_29 , & V_29 -> V_79 . V_619 ,
& V_29 -> V_79 . V_620 ) ;
}
static void F_478 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
T_1 V_56 , V_202 ;
V_56 = V_621 | V_209 |
V_622 | V_623 ;
if ( V_29 -> V_4 == V_138 )
V_56 |= V_208 ;
V_56 |= V_110 ;
V_199 -> V_200 . V_56 = V_56 ;
V_202 = ( V_199 -> V_482 - 1 )
<< V_624 ;
V_199 -> V_200 . V_202 = V_202 ;
}
static void F_407 ( struct V_28 * V_29 ,
const struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
T_1 V_625 ;
T_1 V_626 , V_627 , V_628 , V_629 , V_630 ;
T_1 V_631 , V_615 ;
F_53 ( & V_12 -> V_111 ) ;
V_626 = V_199 -> V_56 . V_25 ;
V_627 = V_199 -> V_56 . V_20 ;
V_628 = V_199 -> V_56 . V_21 ;
V_629 = V_199 -> V_56 . V_23 ;
V_630 = V_199 -> V_56 . V_24 ;
if ( V_4 == V_138 )
F_459 ( V_12 , V_4 ) ;
F_125 ( V_12 , V_4 , V_632 , 0x0100000f ) ;
V_615 = F_123 ( V_12 , V_4 , F_479 ( V_4 ) ) ;
V_615 &= 0x00ffffff ;
F_125 ( V_12 , V_4 , F_479 ( V_4 ) , V_615 ) ;
F_125 ( V_12 , V_4 , V_633 , 0x610 ) ;
V_625 = ( ( V_627 << V_634 ) | ( V_628 & V_635 ) ) ;
V_625 |= ( ( V_629 << V_636 ) | ( V_630 << V_637 ) ) ;
V_625 |= ( ( V_626 << V_638 ) ) ;
V_625 |= ( 1 << V_639 ) ;
V_625 |= ( V_640 << V_641 ) ;
F_125 ( V_12 , V_4 , F_480 ( V_4 ) , V_625 ) ;
V_625 |= V_642 ;
F_125 ( V_12 , V_4 , F_480 ( V_4 ) , V_625 ) ;
if ( V_199 -> V_643 == 162000 ||
F_10 ( V_29 , V_42 ) ||
F_10 ( V_29 , V_41 ) )
F_125 ( V_12 , V_4 , F_481 ( V_4 ) ,
0x009f0003 ) ;
else
F_125 ( V_12 , V_4 , F_481 ( V_4 ) ,
0x00d0000f ) ;
if ( V_29 -> V_79 . V_436 ) {
if ( V_4 == V_129 )
F_125 ( V_12 , V_4 , F_482 ( V_4 ) ,
0x0df40000 ) ;
else
F_125 ( V_12 , V_4 , F_482 ( V_4 ) ,
0x0df70000 ) ;
} else {
if ( V_4 == V_129 )
F_125 ( V_12 , V_4 , F_482 ( V_4 ) ,
0x0df70000 ) ;
else
F_125 ( V_12 , V_4 , F_482 ( V_4 ) ,
0x0df40000 ) ;
}
V_631 = F_123 ( V_12 , V_4 , F_483 ( V_4 ) ) ;
V_631 = ( V_631 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_10 ( V_29 , V_501 ) ||
F_10 ( V_29 , V_361 ) )
V_631 |= 0x01000000 ;
F_125 ( V_12 , V_4 , F_483 ( V_4 ) , V_631 ) ;
F_125 ( V_12 , V_4 , F_484 ( V_4 ) , 0x87871000 ) ;
F_55 ( & V_12 -> V_111 ) ;
}
static void F_485 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
V_199 -> V_200 . V_56 = V_210 |
V_209 | V_622 |
V_110 ;
if ( V_29 -> V_4 != V_129 )
V_199 -> V_200 . V_56 |= V_208 ;
V_199 -> V_200 . V_202 =
( V_199 -> V_482 - 1 ) << V_624 ;
}
static void F_406 ( struct V_28 * V_29 ,
const struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_29 -> V_4 ;
int V_219 = F_51 ( V_29 -> V_4 ) ;
enum V_203 V_94 = F_122 ( V_4 ) ;
T_1 V_644 , V_645 ;
T_1 V_626 , V_627 , V_628 , V_629 , V_630 , V_646 ;
int V_18 ;
V_626 = V_199 -> V_56 . V_25 ;
V_646 = V_199 -> V_56 . V_21 & 0x3fffff ;
V_627 = V_199 -> V_56 . V_20 ;
V_628 = V_199 -> V_56 . V_21 >> 22 ;
V_629 = V_199 -> V_56 . V_23 ;
V_630 = V_199 -> V_56 . V_24 ;
F_116 ( V_219 ,
V_199 -> V_200 . V_56 & ~ V_110 ) ;
F_53 ( & V_12 -> V_111 ) ;
F_125 ( V_12 , V_4 , F_486 ( V_94 ) ,
5 << V_647 |
V_629 << V_648 |
V_630 << V_649 |
1 << V_650 ) ;
F_125 ( V_12 , V_4 , F_487 ( V_94 ) , V_628 ) ;
F_125 ( V_12 , V_4 , F_488 ( V_94 ) ,
V_651 |
1 << V_652 ) ;
F_125 ( V_12 , V_4 , F_489 ( V_94 ) , V_646 ) ;
F_125 ( V_12 , V_4 , F_490 ( V_94 ) ,
V_653 |
( 2 << V_654 ) ) ;
V_18 = F_455 ( V_29 , 0 ) ;
V_644 = 5 << V_655 |
2 << V_656 ;
if ( V_18 == 100000 )
V_645 = 11 ;
else if ( V_18 == 38400 )
V_645 = 10 ;
else
V_645 = 9 ;
V_644 |= V_645 << V_657 ;
F_125 ( V_12 , V_4 , F_491 ( V_94 ) , V_644 ) ;
F_125 ( V_12 , V_4 , F_124 ( V_94 ) ,
F_123 ( V_12 , V_4 , F_124 ( V_94 ) ) |
V_658 ) ;
F_55 ( & V_12 -> V_111 ) ;
}
void F_492 ( struct V_9 * V_10 , enum V_4 V_4 ,
const struct V_56 * V_56 )
{
struct V_28 * V_29 =
F_37 ( F_493 ( V_10 , V_4 ) ) ;
struct V_198 V_199 = {
. V_482 = 1 ,
. V_56 = * V_56 ,
} ;
if ( F_20 ( V_10 ) ) {
F_485 ( V_29 , & V_199 ) ;
F_406 ( V_29 , & V_199 ) ;
F_121 ( V_29 , & V_199 ) ;
} else {
F_478 ( V_29 , & V_199 ) ;
F_407 ( V_29 , & V_199 ) ;
F_112 ( V_29 , & V_199 ) ;
}
}
void F_494 ( struct V_9 * V_10 , enum V_4 V_4 )
{
if ( F_20 ( V_10 ) )
F_132 ( F_228 ( V_10 ) , V_4 ) ;
else
F_131 ( F_228 ( V_10 ) , V_4 ) ;
}
static void F_495 ( struct V_28 * V_29 ,
T_2 * V_610 ,
int V_608 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_56 ;
bool V_659 ;
struct V_56 * clock = & V_29 -> V_450 -> V_56 ;
F_458 ( V_29 , V_610 ) ;
V_659 = F_12 ( V_29 , V_44 ) ||
F_12 ( V_29 , V_41 ) ;
V_56 = V_622 ;
if ( F_12 ( V_29 , V_33 ) )
V_56 |= V_660 ;
else
V_56 |= V_661 ;
if ( F_496 ( V_10 ) || F_497 ( V_10 ) || F_498 ( V_10 ) ) {
V_56 |= ( V_29 -> V_450 -> V_482 - 1 )
<< V_662 ;
}
if ( V_659 )
V_56 |= V_663 ;
if ( V_29 -> V_450 -> V_436 )
V_56 |= V_663 ;
if ( F_19 ( V_10 ) )
V_56 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_664 ;
else {
V_56 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_665 ;
if ( F_18 ( V_10 ) && V_610 )
V_56 |= ( 1 << ( V_610 -> V_23 - 1 ) ) << V_666 ;
}
switch ( clock -> V_24 ) {
case 5 :
V_56 |= V_667 ;
break;
case 7 :
V_56 |= V_668 ;
break;
case 10 :
V_56 |= V_669 ;
break;
case 14 :
V_56 |= V_670 ;
break;
}
if ( F_43 ( V_10 ) -> V_91 >= 4 )
V_56 |= ( 6 << V_671 ) ;
if ( V_29 -> V_450 -> V_672 )
V_56 |= V_673 ;
else if ( F_12 ( V_29 , V_33 ) &&
F_454 ( V_12 ) && V_608 < 2 )
V_56 |= V_674 ;
else
V_56 |= V_675 ;
V_56 |= V_110 ;
V_29 -> V_450 -> V_200 . V_56 = V_56 ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
T_1 V_202 = ( V_29 -> V_450 -> V_482 - 1 )
<< V_624 ;
V_29 -> V_450 -> V_200 . V_202 = V_202 ;
}
}
static void F_499 ( struct V_28 * V_29 ,
T_2 * V_610 ,
int V_608 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_56 ;
struct V_56 * clock = & V_29 -> V_450 -> V_56 ;
F_458 ( V_29 , V_610 ) ;
V_56 = V_622 ;
if ( F_12 ( V_29 , V_33 ) ) {
V_56 |= ( 1 << ( clock -> V_23 - 1 ) ) << V_665 ;
} else {
if ( clock -> V_23 == 2 )
V_56 |= V_676 ;
else
V_56 |= ( clock -> V_23 - 2 ) << V_665 ;
if ( clock -> V_24 == 4 )
V_56 |= V_677 ;
}
if ( ! F_129 ( V_10 ) && F_12 ( V_29 , V_53 ) )
V_56 |= V_207 ;
if ( F_12 ( V_29 , V_33 ) &&
F_454 ( V_12 ) && V_608 < 2 )
V_56 |= V_674 ;
else
V_56 |= V_675 ;
V_56 |= V_110 ;
V_29 -> V_450 -> V_200 . V_56 = V_56 ;
}
static void F_349 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_28 -> V_4 ;
enum V_82 V_84 = V_28 -> V_79 . V_84 ;
struct V_355 * V_80 =
& V_28 -> V_79 . V_80 ;
T_4 V_678 , V_679 ;
int V_680 = 0 ;
V_678 = V_80 -> V_678 ;
V_679 = V_80 -> V_679 ;
if ( V_80 -> V_443 & V_681 ) {
V_678 -= 1 ;
V_679 -= 1 ;
if ( F_10 ( V_28 , V_44 ) )
V_680 = ( V_80 -> V_682 - 1 ) / 2 ;
else
V_680 = V_80 -> V_683 -
V_80 -> V_682 / 2 ;
if ( V_680 < 0 )
V_680 += V_80 -> V_682 ;
}
if ( F_43 ( V_10 ) -> V_91 > 3 )
F_116 ( F_302 ( V_84 ) , V_680 ) ;
F_116 ( F_290 ( V_84 ) ,
( V_80 -> V_358 - 1 ) |
( ( V_80 -> V_682 - 1 ) << 16 ) ) ;
F_116 ( F_292 ( V_84 ) ,
( V_80 -> V_684 - 1 ) |
( ( V_80 -> V_685 - 1 ) << 16 ) ) ;
F_116 ( F_294 ( V_84 ) ,
( V_80 -> V_683 - 1 ) |
( ( V_80 -> V_686 - 1 ) << 16 ) ) ;
F_116 ( F_296 ( V_84 ) ,
( V_80 -> V_359 - 1 ) |
( ( V_678 - 1 ) << 16 ) ) ;
F_116 ( F_298 ( V_84 ) ,
( V_80 -> V_687 - 1 ) |
( ( V_679 - 1 ) << 16 ) ) ;
F_116 ( F_300 ( V_84 ) ,
( V_80 -> V_688 - 1 ) |
( ( V_80 -> V_689 - 1 ) << 16 ) ) ;
if ( F_212 ( V_10 ) && V_84 == V_481 &&
( V_4 == V_138 || V_4 == V_376 ) )
F_116 ( F_296 ( V_4 ) , F_5 ( F_296 ( V_84 ) ) ) ;
F_116 ( F_245 ( V_4 ) ,
( ( V_28 -> V_79 . V_316 - 1 ) << 16 ) |
( V_28 -> V_79 . V_315 - 1 ) ) ;
}
static void F_500 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_82 V_84 = V_199 -> V_84 ;
T_4 V_204 ;
V_204 = F_5 ( F_290 ( V_84 ) ) ;
V_199 -> V_80 . V_358 = ( V_204 & 0xffff ) + 1 ;
V_199 -> V_80 . V_682 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_204 = F_5 ( F_292 ( V_84 ) ) ;
V_199 -> V_80 . V_684 = ( V_204 & 0xffff ) + 1 ;
V_199 -> V_80 . V_685 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_204 = F_5 ( F_294 ( V_84 ) ) ;
V_199 -> V_80 . V_683 = ( V_204 & 0xffff ) + 1 ;
V_199 -> V_80 . V_686 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_204 = F_5 ( F_296 ( V_84 ) ) ;
V_199 -> V_80 . V_359 = ( V_204 & 0xffff ) + 1 ;
V_199 -> V_80 . V_678 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_204 = F_5 ( F_298 ( V_84 ) ) ;
V_199 -> V_80 . V_687 = ( V_204 & 0xffff ) + 1 ;
V_199 -> V_80 . V_679 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_204 = F_5 ( F_300 ( V_84 ) ) ;
V_199 -> V_80 . V_688 = ( V_204 & 0xffff ) + 1 ;
V_199 -> V_80 . V_689 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
if ( F_5 ( F_44 ( V_84 ) ) & V_235 ) {
V_199 -> V_80 . V_443 |= V_681 ;
V_199 -> V_80 . V_678 += 1 ;
V_199 -> V_80 . V_679 += 1 ;
}
V_204 = F_5 ( F_245 ( V_29 -> V_4 ) ) ;
V_199 -> V_315 = ( V_204 & 0xffff ) + 1 ;
V_199 -> V_316 = ( ( V_204 >> 16 ) & 0xffff ) + 1 ;
V_199 -> V_690 . V_691 = V_199 -> V_315 ;
V_199 -> V_690 . V_568 = V_199 -> V_316 ;
}
void F_501 ( struct V_355 * V_442 ,
struct V_198 * V_199 )
{
V_442 -> V_568 = V_199 -> V_80 . V_358 ;
V_442 -> V_692 = V_199 -> V_80 . V_682 ;
V_442 -> V_567 = V_199 -> V_80 . V_683 ;
V_442 -> V_693 = V_199 -> V_80 . V_686 ;
V_442 -> V_691 = V_199 -> V_80 . V_359 ;
V_442 -> V_694 = V_199 -> V_80 . V_678 ;
V_442 -> V_695 = V_199 -> V_80 . V_688 ;
V_442 -> V_696 = V_199 -> V_80 . V_689 ;
V_442 -> V_443 = V_199 -> V_80 . V_443 ;
V_442 -> clock = V_199 -> V_80 . V_81 ;
V_442 -> V_443 |= V_199 -> V_80 . V_443 ;
}
static void F_410 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_697 ;
V_697 = 0 ;
if ( ( V_28 -> V_4 == V_129 && V_12 -> V_147 & V_148 ) ||
( V_28 -> V_4 == V_138 && V_12 -> V_147 & V_149 ) )
V_697 |= F_5 ( F_44 ( V_28 -> V_4 ) ) & V_150 ;
if ( V_28 -> V_79 . V_248 )
V_697 |= V_249 ;
if ( F_18 ( V_10 ) || F_21 ( V_10 ) ) {
if ( V_28 -> V_79 . V_698 && V_28 -> V_79 . V_562 != 30 )
V_697 |= V_699 |
V_700 ;
switch ( V_28 -> V_79 . V_562 ) {
case 18 :
V_697 |= V_701 ;
break;
case 24 :
V_697 |= V_702 ;
break;
case 30 :
V_697 |= V_703 ;
break;
default:
F_134 () ;
}
}
if ( F_502 ( V_10 ) ) {
if ( V_28 -> V_613 ) {
F_140 ( L_102 ) ;
V_697 |= V_704 ;
} else {
F_140 ( L_103 ) ;
}
}
if ( V_28 -> V_79 . V_80 . V_443 & V_681 ) {
if ( F_43 ( V_10 ) -> V_91 < 4 ||
F_10 ( V_28 , V_44 ) )
V_697 |= V_705 ;
else
V_697 |= V_706 ;
} else
V_697 |= V_707 ;
if ( F_21 ( V_10 ) && V_28 -> V_79 . V_708 )
V_697 |= V_709 ;
F_116 ( F_44 ( V_28 -> V_4 ) , V_697 ) ;
F_117 ( F_44 ( V_28 -> V_4 ) ) ;
}
static int F_503 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_18 , V_608 = 0 ;
T_2 clock , V_610 ;
bool V_710 , V_711 = false ;
bool V_712 = false , V_542 = false ;
struct V_1 * V_6 ;
const T_3 * V_32 ;
F_13 (dev, encoder) {
if ( V_6 -> V_31 != V_29 )
continue;
switch ( V_6 -> type ) {
case V_33 :
V_712 = true ;
break;
case V_246 :
V_542 = true ;
break;
default:
break;
}
V_608 ++ ;
}
if ( V_542 )
return 0 ;
if ( ! V_29 -> V_450 -> V_713 ) {
V_18 = F_455 ( V_29 , V_608 ) ;
V_32 = F_17 ( V_29 , V_18 ) ;
V_710 = V_12 -> V_252 . V_714 ( V_32 , V_29 ,
V_29 -> V_450 -> V_643 ,
V_18 , NULL , & clock ) ;
if ( ! V_710 ) {
F_119 ( L_104 ) ;
return - V_272 ;
}
if ( V_712 && V_12 -> V_715 ) {
V_711 =
V_12 -> V_252 . V_714 ( V_32 , V_29 ,
V_12 -> V_716 ,
V_18 , & clock ,
& V_610 ) ;
}
V_29 -> V_450 -> V_56 . V_25 = clock . V_25 ;
V_29 -> V_450 -> V_56 . V_20 = clock . V_20 ;
V_29 -> V_450 -> V_56 . V_21 = clock . V_21 ;
V_29 -> V_450 -> V_56 . V_23 = clock . V_23 ;
V_29 -> V_450 -> V_56 . V_24 = clock . V_24 ;
}
if ( F_22 ( V_10 ) ) {
F_499 ( V_29 ,
V_711 ? & V_610 : NULL ,
V_608 ) ;
} else if ( F_20 ( V_10 ) ) {
F_485 ( V_29 , V_29 -> V_450 ) ;
} else if ( F_21 ( V_10 ) ) {
F_478 ( V_29 , V_29 -> V_450 ) ;
} else {
F_495 ( V_29 ,
V_711 ? & V_610 : NULL ,
V_608 ) ;
}
return 0 ;
}
static void F_504 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_204 ;
if ( F_43 ( V_10 ) -> V_91 <= 3 && ( F_129 ( V_10 ) || ! F_115 ( V_10 ) ) )
return;
V_204 = F_5 ( V_488 ) ;
if ( ! ( V_204 & V_489 ) )
return;
if ( F_43 ( V_10 ) -> V_91 < 4 ) {
if ( V_29 -> V_4 != V_138 )
return;
} else {
if ( ( V_204 & V_717 ) != ( V_29 -> V_4 << V_718 ) )
return;
}
V_199 -> V_486 . V_487 = V_204 ;
V_199 -> V_486 . V_491 = F_5 ( V_490 ) ;
if ( F_43 ( V_10 ) -> V_91 < 5 )
V_199 -> V_486 . V_719 =
F_5 ( V_140 ) & V_720 ;
}
static void F_505 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_199 -> V_84 ;
T_2 clock ;
T_1 V_625 ;
int V_18 = 100000 ;
if ( ! ( V_199 -> V_200 . V_56 & V_110 ) )
return;
F_53 ( & V_12 -> V_111 ) ;
V_625 = F_123 ( V_12 , V_4 , F_480 ( V_4 ) ) ;
F_55 ( & V_12 -> V_111 ) ;
clock . V_20 = ( V_625 >> V_634 ) & 7 ;
clock . V_21 = V_625 & V_635 ;
clock . V_25 = ( V_625 >> V_638 ) & 0xf ;
clock . V_23 = ( V_625 >> V_636 ) & 7 ;
clock . V_24 = ( V_625 >> V_637 ) & 0x1f ;
F_8 ( V_18 , & clock ) ;
V_199 -> V_643 = clock . V_27 / 5 ;
}
static void F_506 ( struct V_28 * V_29 ,
struct V_297 * V_298 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_108 , V_8 , V_281 ;
int V_4 = V_29 -> V_4 , V_151 = V_29 -> V_151 ;
int V_721 , V_304 ;
int V_722 ;
V_29 -> V_8 . V_77 -> V_78 = F_507 ( sizeof( struct V_330 ) , V_453 ) ;
if ( ! V_29 -> V_8 . V_77 -> V_78 ) {
F_140 ( L_105 ) ;
return;
}
V_108 = F_5 ( F_77 ( V_151 ) ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 )
if ( V_108 & V_323 )
V_298 -> V_258 = true ;
V_304 = V_108 & V_723 ;
V_721 = F_187 ( V_304 ) ;
V_29 -> V_8 . V_77 -> V_78 -> V_304 = V_721 ;
V_29 -> V_8 . V_77 -> V_78 -> V_593 =
F_200 ( V_721 , 0 ) * 8 ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
if ( V_298 -> V_258 )
V_281 = F_5 ( F_209 ( V_151 ) ) ;
else
V_281 = F_5 ( F_210 ( V_151 ) ) ;
V_8 = F_5 ( F_162 ( V_151 ) ) & 0xfffff000 ;
} else {
V_8 = F_5 ( F_163 ( V_151 ) ) ;
}
V_298 -> V_8 = V_8 ;
V_108 = F_5 ( F_245 ( V_4 ) ) ;
V_29 -> V_8 . V_77 -> V_78 -> V_305 = ( ( V_108 >> 16 ) & 0xfff ) + 1 ;
V_29 -> V_8 . V_77 -> V_78 -> V_257 = ( ( V_108 >> 0 ) & 0xfff ) + 1 ;
V_108 = F_5 ( F_208 ( V_4 ) ) ;
V_29 -> V_8 . V_77 -> V_78 -> V_303 [ 0 ] = V_108 & 0xffffffc0 ;
V_722 = F_171 ( V_10 , V_29 -> V_8 . V_77 -> V_78 -> V_257 ,
V_298 -> V_258 ) ;
V_298 -> V_301 = F_508 ( V_29 -> V_8 . V_77 -> V_78 -> V_303 [ 0 ] *
V_722 ) ;
F_140 ( L_106 ,
V_4 , V_151 , V_29 -> V_8 . V_77 -> V_78 -> V_305 ,
V_29 -> V_8 . V_77 -> V_78 -> V_257 ,
V_29 -> V_8 . V_77 -> V_78 -> V_593 , V_8 ,
V_29 -> V_8 . V_77 -> V_78 -> V_303 [ 0 ] ,
V_298 -> V_301 ) ;
}
static void F_509 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_199 -> V_84 ;
enum V_203 V_94 = F_122 ( V_4 ) ;
T_2 clock ;
T_1 V_724 , V_725 , V_726 , V_727 ;
int V_18 = 100000 ;
F_53 ( & V_12 -> V_111 ) ;
V_724 = F_123 ( V_12 , V_4 , F_486 ( V_94 ) ) ;
V_725 = F_123 ( V_12 , V_4 , F_487 ( V_94 ) ) ;
V_726 = F_123 ( V_12 , V_4 , F_488 ( V_94 ) ) ;
V_727 = F_123 ( V_12 , V_4 , F_489 ( V_94 ) ) ;
F_55 ( & V_12 -> V_111 ) ;
clock . V_20 = ( V_726 & 0x7 ) == V_651 ? 2 : 0 ;
clock . V_21 = ( ( V_725 & 0xff ) << 22 ) | ( V_727 & 0x3fffff ) ;
clock . V_25 = ( V_726 >> V_652 ) & 0xf ;
clock . V_23 = ( V_724 >> V_648 ) & 0x7 ;
clock . V_24 = ( V_724 >> V_649 ) & 0x1f ;
F_26 ( V_18 , & clock ) ;
V_199 -> V_643 = clock . V_27 / 5 ;
}
static bool F_510 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_204 ;
if ( ! F_74 ( V_12 ,
F_386 ( V_29 -> V_4 ) ) )
return false ;
V_199 -> V_84 = (enum V_82 ) V_29 -> V_4 ;
V_199 -> V_115 = V_448 ;
V_204 = F_5 ( F_44 ( V_29 -> V_4 ) ) ;
if ( ! ( V_204 & V_150 ) )
return false ;
if ( F_18 ( V_10 ) || F_21 ( V_10 ) ) {
switch ( V_204 & V_233 ) {
case V_701 :
V_199 -> V_562 = 18 ;
break;
case V_702 :
V_199 -> V_562 = 24 ;
break;
case V_703 :
V_199 -> V_562 = 30 ;
break;
default:
break;
}
}
if ( F_21 ( V_10 ) && ( V_204 & V_709 ) )
V_199 -> V_708 = true ;
if ( F_43 ( V_10 ) -> V_91 < 4 )
V_199 -> V_248 = V_204 & V_249 ;
F_500 ( V_29 , V_199 ) ;
F_504 ( V_29 , V_199 ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
V_204 = F_5 ( F_120 ( V_29 -> V_4 ) ) ;
V_199 -> V_482 =
( ( V_204 & V_728 )
>> V_624 ) + 1 ;
V_199 -> V_200 . V_202 = V_204 ;
} else if ( F_496 ( V_10 ) || F_497 ( V_10 ) || F_498 ( V_10 ) ) {
V_204 = F_5 ( F_51 ( V_29 -> V_4 ) ) ;
V_199 -> V_482 =
( ( V_204 & V_729 )
>> V_662 ) + 1 ;
} else {
V_199 -> V_482 = 1 ;
}
V_199 -> V_200 . V_56 = F_5 ( F_51 ( V_29 -> V_4 ) ) ;
if ( ! F_21 ( V_10 ) ) {
if ( F_129 ( V_10 ) )
V_199 -> V_200 . V_56 &= ~ V_207 ;
V_199 -> V_200 . V_545 = F_5 ( F_413 ( V_29 -> V_4 ) ) ;
V_199 -> V_200 . V_546 = F_5 ( F_414 ( V_29 -> V_4 ) ) ;
} else {
V_199 -> V_200 . V_56 &= ~ ( V_201 |
V_221 |
V_220 ) ;
}
if ( F_20 ( V_10 ) )
F_509 ( V_29 , V_199 ) ;
else if ( F_21 ( V_10 ) )
F_505 ( V_29 , V_199 ) ;
else
F_511 ( V_29 , V_199 ) ;
return true ;
}
static void F_512 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
T_1 V_108 , V_730 ;
bool V_731 = false ;
bool V_732 = false ;
bool V_733 = false ;
bool V_734 = false ;
bool V_735 = false ;
F_13 (dev, encoder) {
switch ( V_6 -> type ) {
case V_33 :
V_733 = true ;
V_731 = true ;
break;
case V_361 :
V_733 = true ;
if ( F_383 ( & V_6 -> V_8 ) -> V_94 == V_493 )
V_732 = true ;
break;
default:
break;
}
}
if ( F_48 ( V_10 ) ) {
V_734 = V_12 -> V_605 . V_736 ;
V_735 = V_734 ;
} else {
V_734 = false ;
V_735 = true ;
}
F_140 ( L_107 ,
V_733 , V_731 , V_734 ) ;
V_108 = F_5 ( V_162 ) ;
V_730 = V_108 ;
V_730 &= ~ V_164 ;
if ( V_734 )
V_730 |= V_737 ;
else
V_730 |= V_738 ;
V_730 &= ~ V_163 ;
V_730 &= ~ V_739 ;
V_730 &= ~ V_740 ;
if ( V_733 ) {
V_730 |= V_741 ;
if ( F_454 ( V_12 ) && V_735 )
V_730 |= V_740 ;
if ( V_732 ) {
if ( F_454 ( V_12 ) && V_735 )
V_730 |= V_742 ;
else
V_730 |= V_743 ;
} else
V_730 |= V_744 ;
} else {
V_730 |= V_745 ;
V_730 |= V_744 ;
}
if ( V_730 == V_108 )
return;
V_108 &= ~ V_164 ;
if ( V_734 )
V_108 |= V_737 ;
else
V_108 |= V_738 ;
if ( V_733 ) {
V_108 &= ~ V_163 ;
V_108 |= V_741 ;
if ( F_454 ( V_12 ) && V_735 ) {
F_140 ( L_108 ) ;
V_108 |= V_740 ;
} else
V_108 &= ~ V_740 ;
F_116 ( V_162 , V_108 ) ;
F_117 ( V_162 ) ;
F_118 ( 200 ) ;
V_108 &= ~ V_739 ;
if ( V_732 ) {
if ( F_454 ( V_12 ) && V_735 ) {
F_140 ( L_109 ) ;
V_108 |= V_742 ;
} else
V_108 |= V_743 ;
} else
V_108 |= V_744 ;
F_116 ( V_162 , V_108 ) ;
F_117 ( V_162 ) ;
F_118 ( 200 ) ;
} else {
F_140 ( L_110 ) ;
V_108 &= ~ V_739 ;
V_108 |= V_744 ;
F_116 ( V_162 , V_108 ) ;
F_117 ( V_162 ) ;
F_118 ( 200 ) ;
V_108 &= ~ V_163 ;
V_108 |= V_745 ;
V_108 &= ~ V_740 ;
F_116 ( V_162 , V_108 ) ;
F_117 ( V_162 ) ;
F_118 ( 200 ) ;
}
F_114 ( V_108 != V_730 ) ;
}
static void F_513 ( struct V_11 * V_12 )
{
T_4 V_204 ;
V_204 = F_5 ( V_746 ) ;
V_204 |= V_747 ;
F_116 ( V_746 , V_204 ) ;
if ( F_514 ( F_5 ( V_746 ) &
V_748 , 100 ) )
F_119 ( L_111 ) ;
V_204 = F_5 ( V_746 ) ;
V_204 &= ~ V_747 ;
F_116 ( V_746 , V_204 ) ;
if ( F_514 ( ( F_5 ( V_746 ) &
V_748 ) == 0 , 100 ) )
F_119 ( L_112 ) ;
}
static void F_515 ( struct V_11 * V_12 )
{
T_4 V_204 ;
V_204 = F_283 ( V_12 , 0x8008 , V_749 ) ;
V_204 &= ~ ( 0xFF << 24 ) ;
V_204 |= ( 0x12 << 24 ) ;
F_282 ( V_12 , 0x8008 , V_204 , V_749 ) ;
V_204 = F_283 ( V_12 , 0x2008 , V_749 ) ;
V_204 |= ( 1 << 11 ) ;
F_282 ( V_12 , 0x2008 , V_204 , V_749 ) ;
V_204 = F_283 ( V_12 , 0x2108 , V_749 ) ;
V_204 |= ( 1 << 11 ) ;
F_282 ( V_12 , 0x2108 , V_204 , V_749 ) ;
V_204 = F_283 ( V_12 , 0x206C , V_749 ) ;
V_204 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_282 ( V_12 , 0x206C , V_204 , V_749 ) ;
V_204 = F_283 ( V_12 , 0x216C , V_749 ) ;
V_204 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_282 ( V_12 , 0x216C , V_204 , V_749 ) ;
V_204 = F_283 ( V_12 , 0x2080 , V_749 ) ;
V_204 &= ~ ( 7 << 13 ) ;
V_204 |= ( 5 << 13 ) ;
F_282 ( V_12 , 0x2080 , V_204 , V_749 ) ;
V_204 = F_283 ( V_12 , 0x2180 , V_749 ) ;
V_204 &= ~ ( 7 << 13 ) ;
V_204 |= ( 5 << 13 ) ;
F_282 ( V_12 , 0x2180 , V_204 , V_749 ) ;
V_204 = F_283 ( V_12 , 0x208C , V_749 ) ;
V_204 &= ~ 0xFF ;
V_204 |= 0x1C ;
F_282 ( V_12 , 0x208C , V_204 , V_749 ) ;
V_204 = F_283 ( V_12 , 0x218C , V_749 ) ;
V_204 &= ~ 0xFF ;
V_204 |= 0x1C ;
F_282 ( V_12 , 0x218C , V_204 , V_749 ) ;
V_204 = F_283 ( V_12 , 0x2098 , V_749 ) ;
V_204 &= ~ ( 0xFF << 16 ) ;
V_204 |= ( 0x1C << 16 ) ;
F_282 ( V_12 , 0x2098 , V_204 , V_749 ) ;
V_204 = F_283 ( V_12 , 0x2198 , V_749 ) ;
V_204 &= ~ ( 0xFF << 16 ) ;
V_204 |= ( 0x1C << 16 ) ;
F_282 ( V_12 , 0x2198 , V_204 , V_749 ) ;
V_204 = F_283 ( V_12 , 0x20C4 , V_749 ) ;
V_204 |= ( 1 << 27 ) ;
F_282 ( V_12 , 0x20C4 , V_204 , V_749 ) ;
V_204 = F_283 ( V_12 , 0x21C4 , V_749 ) ;
V_204 |= ( 1 << 27 ) ;
F_282 ( V_12 , 0x21C4 , V_204 , V_749 ) ;
V_204 = F_283 ( V_12 , 0x20EC , V_749 ) ;
V_204 &= ~ ( 0xF << 28 ) ;
V_204 |= ( 4 << 28 ) ;
F_282 ( V_12 , 0x20EC , V_204 , V_749 ) ;
V_204 = F_283 ( V_12 , 0x21EC , V_749 ) ;
V_204 &= ~ ( 0xF << 28 ) ;
V_204 |= ( 4 << 28 ) ;
F_282 ( V_12 , 0x21EC , V_204 , V_749 ) ;
}
static void F_516 ( struct V_9 * V_10 , bool V_750 ,
bool V_751 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_85 , V_204 ;
if ( F_46 ( V_751 && ! V_750 , L_113 ) )
V_750 = true ;
if ( F_46 ( V_12 -> V_752 == V_753 &&
V_751 , L_114 ) )
V_751 = false ;
F_53 ( & V_12 -> V_111 ) ;
V_204 = F_283 ( V_12 , V_754 , V_418 ) ;
V_204 &= ~ V_419 ;
V_204 |= V_755 ;
F_282 ( V_12 , V_754 , V_204 , V_418 ) ;
F_118 ( 24 ) ;
if ( V_750 ) {
V_204 = F_283 ( V_12 , V_754 , V_418 ) ;
V_204 &= ~ V_755 ;
F_282 ( V_12 , V_754 , V_204 , V_418 ) ;
if ( V_751 ) {
F_513 ( V_12 ) ;
F_515 ( V_12 ) ;
}
}
V_85 = ( V_12 -> V_752 == V_753 ) ?
V_756 : V_757 ;
V_204 = F_283 ( V_12 , V_85 , V_418 ) ;
V_204 |= V_758 ;
F_282 ( V_12 , V_85 , V_204 , V_418 ) ;
F_55 ( & V_12 -> V_111 ) ;
}
static void F_517 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_85 , V_204 ;
F_53 ( & V_12 -> V_111 ) ;
V_85 = ( V_12 -> V_752 == V_753 ) ?
V_756 : V_757 ;
V_204 = F_283 ( V_12 , V_85 , V_418 ) ;
V_204 &= ~ V_758 ;
F_282 ( V_12 , V_85 , V_204 , V_418 ) ;
V_204 = F_283 ( V_12 , V_754 , V_418 ) ;
if ( ! ( V_204 & V_419 ) ) {
if ( ! ( V_204 & V_755 ) ) {
V_204 |= V_755 ;
F_282 ( V_12 , V_754 , V_204 , V_418 ) ;
F_118 ( 32 ) ;
}
V_204 |= V_419 ;
F_282 ( V_12 , V_754 , V_204 , V_418 ) ;
}
F_55 ( & V_12 -> V_111 ) ;
}
static void F_518 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
bool V_759 = false ;
F_13 (dev, encoder) {
switch ( V_6 -> type ) {
case V_42 :
V_759 = true ;
break;
default:
break;
}
}
if ( V_759 )
F_516 ( V_10 , true , true ) ;
else
F_517 ( V_10 ) ;
}
void F_519 ( struct V_9 * V_10 )
{
if ( F_48 ( V_10 ) || F_92 ( V_10 ) )
F_512 ( V_10 ) ;
else if ( F_156 ( V_10 ) )
F_518 ( V_10 ) ;
}
static int F_520 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
int V_608 = 0 ;
bool V_712 = false ;
F_13 (dev, encoder) {
if ( V_6 -> V_31 != F_37 ( V_29 ) )
continue;
switch ( V_6 -> type ) {
case V_33 :
V_712 = true ;
break;
default:
break;
}
V_608 ++ ;
}
if ( V_712 && F_454 ( V_12 ) && V_608 < 2 ) {
F_140 ( L_101 ,
V_12 -> V_605 . V_609 ) ;
return V_12 -> V_605 . V_609 ;
}
return 120000 ;
}
static void F_351 ( struct V_75 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_4 V_108 ;
V_108 = 0 ;
switch ( V_28 -> V_79 . V_562 ) {
case 18 :
V_108 |= V_701 ;
break;
case 24 :
V_108 |= V_702 ;
break;
case 30 :
V_108 |= V_703 ;
break;
case 36 :
V_108 |= V_760 ;
break;
default:
F_134 () ;
}
if ( V_28 -> V_79 . V_698 )
V_108 |= ( V_699 | V_700 ) ;
if ( V_28 -> V_79 . V_80 . V_443 & V_681 )
V_108 |= V_236 ;
else
V_108 |= V_707 ;
if ( V_28 -> V_79 . V_708 )
V_108 |= V_709 ;
F_116 ( F_44 ( V_4 ) , V_108 ) ;
F_117 ( F_44 ( V_4 ) ) ;
}
static void F_362 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_6 V_761 = 0x7800 ;
if ( V_28 -> V_79 . V_708 )
V_761 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_116 ( F_521 ( V_4 ) , V_761 << 16 ) ;
F_116 ( F_522 ( V_4 ) , 0 ) ;
F_116 ( F_523 ( V_4 ) , V_761 ) ;
F_116 ( F_524 ( V_4 ) , 0 ) ;
F_116 ( F_525 ( V_4 ) , 0 ) ;
F_116 ( F_526 ( V_4 ) , V_761 << 16 ) ;
F_116 ( F_527 ( V_4 ) , 0 ) ;
F_116 ( F_528 ( V_4 ) , 0 ) ;
F_116 ( F_529 ( V_4 ) , 0 ) ;
if ( F_43 ( V_10 ) -> V_91 > 6 ) {
T_6 V_762 = 0 ;
if ( V_28 -> V_79 . V_708 )
V_762 = ( 16 * ( 1 << 12 ) / 255 ) & 0x1fff ;
F_116 ( F_530 ( V_4 ) , V_762 ) ;
F_116 ( F_531 ( V_4 ) , V_762 ) ;
F_116 ( F_532 ( V_4 ) , V_762 ) ;
F_116 ( F_533 ( V_4 ) , 0 ) ;
} else {
T_4 V_442 = V_763 ;
if ( V_28 -> V_79 . V_708 )
V_442 |= V_764 ;
F_116 ( F_533 ( V_4 ) , V_442 ) ;
}
}
static void F_361 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
enum V_82 V_84 = V_28 -> V_79 . V_84 ;
T_4 V_108 ;
V_108 = 0 ;
if ( F_212 ( V_10 ) && V_28 -> V_79 . V_698 )
V_108 |= ( V_699 | V_700 ) ;
if ( V_28 -> V_79 . V_80 . V_443 & V_681 )
V_108 |= V_236 ;
else
V_108 |= V_707 ;
F_116 ( F_44 ( V_84 ) , V_108 ) ;
F_117 ( F_44 ( V_84 ) ) ;
F_116 ( F_339 ( V_28 -> V_4 ) , V_765 ) ;
F_117 ( F_339 ( V_28 -> V_4 ) ) ;
if ( F_166 ( V_10 ) || F_43 ( V_10 ) -> V_91 >= 9 ) {
V_108 = 0 ;
switch ( V_28 -> V_79 . V_562 ) {
case 18 :
V_108 |= V_766 ;
break;
case 24 :
V_108 |= V_767 ;
break;
case 30 :
V_108 |= V_768 ;
break;
case 36 :
V_108 |= V_769 ;
break;
default:
F_134 () ;
}
if ( V_28 -> V_79 . V_698 )
V_108 |= V_770 | V_771 ;
F_116 ( F_534 ( V_4 ) , V_108 ) ;
}
}
static bool F_535 ( struct V_75 * V_29 ,
T_2 * clock ,
bool * V_711 ,
T_2 * V_610 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_18 ;
const T_3 * V_32 ;
bool V_266 , V_712 = false ;
V_712 = F_12 ( V_28 , V_33 ) ;
V_18 = F_520 ( V_29 ) ;
V_32 = F_17 ( V_28 , V_18 ) ;
V_266 = V_12 -> V_252 . V_714 ( V_32 , V_28 ,
V_28 -> V_450 -> V_643 ,
V_18 , NULL , clock ) ;
if ( ! V_266 )
return false ;
if ( V_712 && V_12 -> V_715 ) {
* V_711 =
V_12 -> V_252 . V_714 ( V_32 , V_28 ,
V_12 -> V_716 ,
V_18 , clock ,
V_610 ) ;
}
return true ;
}
int F_436 ( int V_772 , int V_558 , int V_773 )
{
T_1 V_774 = V_772 * V_773 * 21 / 20 ;
return F_393 ( V_774 , V_558 * 8 ) ;
}
static bool F_536 ( struct V_56 * V_56 , int V_775 )
{
return F_24 ( V_56 ) < V_775 * V_56 -> V_25 ;
}
static T_4 F_537 ( struct V_28 * V_28 ,
T_1 * V_611 ,
T_2 * V_610 , T_1 * V_612 )
{
struct V_75 * V_29 = & V_28 -> V_8 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 ;
T_4 V_56 ;
int V_775 , V_608 = 0 ;
bool V_712 = false , V_659 = false ;
F_13 (dev, intel_encoder) {
if ( V_1 -> V_31 != F_37 ( V_29 ) )
continue;
switch ( V_1 -> type ) {
case V_33 :
V_712 = true ;
break;
case V_44 :
case V_41 :
V_659 = true ;
break;
default:
break;
}
V_608 ++ ;
}
V_775 = 21 ;
if ( V_712 ) {
if ( ( F_454 ( V_12 ) &&
V_12 -> V_605 . V_609 == 100000 ) ||
( F_48 ( V_10 ) && F_15 ( V_10 ) ) )
V_775 = 25 ;
} else if ( V_28 -> V_450 -> V_672 )
V_775 = 20 ;
if ( F_536 ( & V_28 -> V_450 -> V_56 , V_775 ) )
* V_611 |= V_776 ;
if ( V_612 && ( V_610 -> V_19 < V_775 * V_610 -> V_25 ) )
* V_612 |= V_776 ;
V_56 = 0 ;
if ( V_712 )
V_56 |= V_660 ;
else
V_56 |= V_661 ;
V_56 |= ( V_28 -> V_450 -> V_482 - 1 )
<< V_777 ;
if ( V_659 )
V_56 |= V_663 ;
if ( V_28 -> V_450 -> V_436 )
V_56 |= V_663 ;
V_56 |= ( 1 << ( V_28 -> V_450 -> V_56 . V_23 - 1 ) ) << V_665 ;
V_56 |= ( 1 << ( V_28 -> V_450 -> V_56 . V_23 - 1 ) ) << V_666 ;
switch ( V_28 -> V_450 -> V_56 . V_24 ) {
case 5 :
V_56 |= V_667 ;
break;
case 7 :
V_56 |= V_668 ;
break;
case 10 :
V_56 |= V_669 ;
break;
case 14 :
V_56 |= V_670 ;
break;
}
if ( V_712 && F_454 ( V_12 ) && V_608 < 2 )
V_56 |= V_674 ;
else
V_56 |= V_675 ;
return V_56 | V_110 ;
}
static int F_538 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
T_2 clock , V_610 ;
T_1 V_56 = 0 , V_611 = 0 , V_612 = 0 ;
bool V_710 , V_711 = false ;
bool V_712 = false ;
struct V_114 * V_117 ;
V_712 = F_10 ( V_29 , V_33 ) ;
F_46 ( ! ( F_48 ( V_10 ) || F_92 ( V_10 ) ) ,
L_115 , F_539 ( V_10 ) ) ;
V_710 = F_535 ( & V_29 -> V_8 , & clock ,
& V_711 , & V_610 ) ;
if ( ! V_710 && ! V_29 -> V_450 -> V_713 ) {
F_119 ( L_104 ) ;
return - V_272 ;
}
if ( ! V_29 -> V_450 -> V_713 ) {
V_29 -> V_450 -> V_56 . V_25 = clock . V_25 ;
V_29 -> V_450 -> V_56 . V_20 = clock . V_20 ;
V_29 -> V_450 -> V_56 . V_21 = clock . V_21 ;
V_29 -> V_450 -> V_56 . V_23 = clock . V_23 ;
V_29 -> V_450 -> V_56 . V_24 = clock . V_24 ;
}
if ( V_29 -> V_450 -> V_247 ) {
V_611 = F_457 ( & V_29 -> V_450 -> V_56 ) ;
if ( V_711 )
V_612 = F_457 ( & V_610 ) ;
V_56 = F_537 ( V_29 ,
& V_611 , & V_610 ,
V_711 ? & V_612 : NULL ) ;
V_29 -> V_450 -> V_200 . V_56 = V_56 ;
V_29 -> V_450 -> V_200 . V_545 = V_611 ;
if ( V_711 )
V_29 -> V_450 -> V_200 . V_546 = V_612 ;
else
V_29 -> V_450 -> V_200 . V_546 = V_611 ;
V_117 = F_313 ( V_29 ) ;
if ( V_117 == NULL ) {
F_137 ( L_116 ,
F_68 ( V_29 -> V_4 ) ) ;
return - V_272 ;
}
}
if ( V_712 && V_711 && V_356 . V_614 )
V_29 -> V_613 = true ;
else
V_29 -> V_613 = false ;
return 0 ;
}
static void F_540 ( struct V_28 * V_29 ,
struct V_597 * V_598 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
V_598 -> V_602 = F_5 ( F_465 ( V_4 ) ) ;
V_598 -> V_603 = F_5 ( F_466 ( V_4 ) ) ;
V_598 -> V_600 = F_5 ( F_462 ( V_4 ) )
& ~ V_431 ;
V_598 -> V_601 = F_5 ( F_464 ( V_4 ) ) ;
V_598 -> V_599 = ( ( F_5 ( F_462 ( V_4 ) )
& V_431 ) >> V_778 ) + 1 ;
}
static void F_541 ( struct V_28 * V_29 ,
enum V_82 V_82 ,
struct V_597 * V_598 ,
struct V_597 * V_617 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 = V_29 -> V_4 ;
if ( F_43 ( V_10 ) -> V_91 >= 5 ) {
V_598 -> V_602 = F_5 ( F_468 ( V_82 ) ) ;
V_598 -> V_603 = F_5 ( F_469 ( V_82 ) ) ;
V_598 -> V_600 = F_5 ( F_307 ( V_82 ) )
& ~ V_431 ;
V_598 -> V_601 = F_5 ( F_467 ( V_82 ) ) ;
V_598 -> V_599 = ( ( F_5 ( F_307 ( V_82 ) )
& V_431 ) >> V_778 ) + 1 ;
if ( V_617 && F_43 ( V_10 ) -> V_91 < 8 &&
V_29 -> V_79 . V_618 ) {
V_617 -> V_602 = F_5 ( F_472 ( V_82 ) ) ;
V_617 -> V_603 = F_5 ( F_473 ( V_82 ) ) ;
V_617 -> V_600 = F_5 ( F_470 ( V_82 ) )
& ~ V_431 ;
V_617 -> V_601 = F_5 ( F_471 ( V_82 ) ) ;
V_617 -> V_599 = ( ( F_5 ( F_470 ( V_82 ) )
& V_431 ) >> V_778 ) + 1 ;
}
} else {
V_598 -> V_602 = F_5 ( F_476 ( V_4 ) ) ;
V_598 -> V_603 = F_5 ( F_477 ( V_4 ) ) ;
V_598 -> V_600 = F_5 ( F_474 ( V_4 ) )
& ~ V_431 ;
V_598 -> V_601 = F_5 ( F_475 ( V_4 ) ) ;
V_598 -> V_599 = ( ( F_5 ( F_474 ( V_4 ) )
& V_431 ) >> V_778 ) + 1 ;
}
}
void F_542 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
if ( V_29 -> V_79 . V_247 )
F_540 ( V_29 , & V_199 -> V_619 ) ;
else
F_541 ( V_29 , V_199 -> V_84 ,
& V_199 -> V_619 ,
& V_199 -> V_620 ) ;
}
static void F_543 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
F_541 ( V_29 , V_199 -> V_84 ,
& V_199 -> V_477 , NULL ) ;
}
static void F_544 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_204 ;
V_204 = F_5 ( F_320 ( V_29 -> V_4 ) ) ;
if ( V_204 & V_457 ) {
V_199 -> V_360 . V_106 = true ;
V_199 -> V_360 . V_458 = F_5 ( F_321 ( V_29 -> V_4 ) ) ;
V_199 -> V_360 . V_301 = F_5 ( F_322 ( V_29 -> V_4 ) ) ;
}
}
static void F_545 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_204 ;
V_204 = F_5 ( F_246 ( V_29 -> V_4 ) ) ;
if ( V_204 & V_459 ) {
V_199 -> V_360 . V_106 = true ;
V_199 -> V_360 . V_458 = F_5 ( F_247 ( V_29 -> V_4 ) ) ;
V_199 -> V_360 . V_301 = F_5 ( F_248 ( V_29 -> V_4 ) ) ;
if ( F_546 ( V_10 ) ) {
F_3 ( ( V_204 & V_779 ) !=
F_324 ( V_29 -> V_4 ) ) ;
}
}
}
static void F_547 ( struct V_28 * V_29 ,
struct V_297 * V_298 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_108 , V_8 , V_281 ;
int V_4 = V_29 -> V_4 , V_151 = V_29 -> V_151 ;
int V_721 , V_304 ;
int V_722 ;
V_29 -> V_8 . V_77 -> V_78 = F_507 ( sizeof( struct V_330 ) , V_453 ) ;
if ( ! V_29 -> V_8 . V_77 -> V_78 ) {
F_140 ( L_105 ) ;
return;
}
V_108 = F_5 ( F_77 ( V_151 ) ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 )
if ( V_108 & V_323 )
V_298 -> V_258 = true ;
V_304 = V_108 & V_723 ;
V_721 = F_187 ( V_304 ) ;
V_29 -> V_8 . V_77 -> V_78 -> V_304 = V_721 ;
V_29 -> V_8 . V_77 -> V_78 -> V_593 =
F_200 ( V_721 , 0 ) * 8 ;
V_8 = F_5 ( F_162 ( V_151 ) ) & 0xfffff000 ;
if ( F_212 ( V_10 ) || F_166 ( V_10 ) ) {
V_281 = F_5 ( F_213 ( V_151 ) ) ;
} else {
if ( V_298 -> V_258 )
V_281 = F_5 ( F_209 ( V_151 ) ) ;
else
V_281 = F_5 ( F_210 ( V_151 ) ) ;
}
V_298 -> V_8 = V_8 ;
V_108 = F_5 ( F_245 ( V_4 ) ) ;
V_29 -> V_8 . V_77 -> V_78 -> V_305 = ( ( V_108 >> 16 ) & 0xfff ) + 1 ;
V_29 -> V_8 . V_77 -> V_78 -> V_257 = ( ( V_108 >> 0 ) & 0xfff ) + 1 ;
V_108 = F_5 ( F_208 ( V_4 ) ) ;
V_29 -> V_8 . V_77 -> V_78 -> V_303 [ 0 ] = V_108 & 0xffffffc0 ;
V_722 = F_171 ( V_10 , V_29 -> V_8 . V_77 -> V_78 -> V_257 ,
V_298 -> V_258 ) ;
V_298 -> V_301 = F_508 ( V_29 -> V_8 . V_77 -> V_78 -> V_303 [ 0 ] *
V_722 ) ;
F_140 ( L_106 ,
V_4 , V_151 , V_29 -> V_8 . V_77 -> V_78 -> V_305 ,
V_29 -> V_8 . V_77 -> V_78 -> V_257 ,
V_29 -> V_8 . V_77 -> V_78 -> V_593 , V_8 ,
V_29 -> V_8 . V_77 -> V_78 -> V_303 [ 0 ] ,
V_298 -> V_301 ) ;
}
static bool F_548 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_4 V_204 ;
if ( ! F_74 ( V_12 ,
F_386 ( V_29 -> V_4 ) ) )
return false ;
V_199 -> V_84 = (enum V_82 ) V_29 -> V_4 ;
V_199 -> V_115 = V_448 ;
V_204 = F_5 ( F_44 ( V_29 -> V_4 ) ) ;
if ( ! ( V_204 & V_150 ) )
return false ;
switch ( V_204 & V_233 ) {
case V_701 :
V_199 -> V_562 = 18 ;
break;
case V_702 :
V_199 -> V_562 = 24 ;
break;
case V_703 :
V_199 -> V_562 = 30 ;
break;
case V_760 :
V_199 -> V_562 = 36 ;
break;
default:
break;
}
if ( V_204 & V_709 )
V_199 -> V_708 = true ;
if ( F_5 ( F_94 ( V_29 -> V_4 ) ) & V_166 ) {
struct V_114 * V_117 ;
V_199 -> V_247 = true ;
V_204 = F_5 ( F_63 ( V_29 -> V_4 ) ) ;
V_199 -> V_383 = ( ( V_382 & V_204 ) >>
V_780 ) + 1 ;
F_543 ( V_29 , V_199 ) ;
if ( F_48 ( V_12 -> V_10 ) ) {
V_199 -> V_115 =
(enum V_449 ) V_29 -> V_4 ;
} else {
V_204 = F_5 ( V_434 ) ;
if ( V_204 & F_309 ( V_29 -> V_4 ) )
V_199 -> V_115 = V_435 ;
else
V_199 -> V_115 = V_781 ;
}
V_117 = & V_12 -> V_116 [ V_199 -> V_115 ] ;
F_3 ( ! V_117 -> V_120 ( V_12 , V_117 ,
& V_199 -> V_200 ) ) ;
V_204 = V_199 -> V_200 . V_56 ;
V_199 -> V_482 =
( ( V_204 & V_782 )
>> V_777 ) + 1 ;
F_549 ( V_29 , V_199 ) ;
} else {
V_199 -> V_482 = 1 ;
}
F_500 ( V_29 , V_199 ) ;
F_545 ( V_29 , V_199 ) ;
return true ;
}
static void F_550 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_28 * V_29 ;
F_127 (dev, crtc)
F_46 ( V_29 -> V_76 , L_117 ,
F_68 ( V_29 -> V_4 ) ) ;
F_46 ( F_5 ( V_783 ) , L_118 ) ;
F_46 ( F_5 ( V_784 ) & V_785 , L_119 ) ;
F_46 ( F_5 ( V_786 ) & V_787 , L_120 ) ;
F_46 ( F_5 ( V_788 ) & V_787 , L_121 ) ;
F_46 ( F_5 ( V_789 ) & V_790 , L_122 ) ;
F_46 ( F_5 ( V_791 ) & V_792 ,
L_123 ) ;
if ( F_212 ( V_10 ) )
F_46 ( F_5 ( V_793 ) & V_792 ,
L_124 ) ;
F_46 ( F_5 ( V_794 ) & V_795 ,
L_125 ) ;
F_46 ( F_5 ( V_796 ) & V_797 ,
L_126 ) ;
F_46 ( F_5 ( V_798 ) & V_799 , L_127 ) ;
F_46 ( F_551 ( V_12 ) , L_128 ) ;
}
static T_4 F_552 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
if ( F_212 ( V_10 ) )
return F_5 ( V_800 ) ;
else
return F_5 ( V_801 ) ;
}
static void F_553 ( struct V_11 * V_12 , T_4 V_108 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
if ( F_212 ( V_10 ) ) {
F_53 ( & V_12 -> V_463 . V_464 ) ;
if ( F_332 ( V_12 , V_802 ,
V_108 ) )
F_119 ( L_129 ) ;
F_55 ( & V_12 -> V_463 . V_464 ) ;
} else {
F_116 ( V_801 , V_108 ) ;
F_117 ( V_801 ) ;
}
}
static void F_554 ( struct V_11 * V_12 ,
bool V_803 , bool V_804 )
{
T_4 V_108 ;
F_550 ( V_12 ) ;
V_108 = F_5 ( V_805 ) ;
if ( V_803 ) {
V_108 |= V_806 ;
F_116 ( V_805 , V_108 ) ;
if ( F_514 ( F_5 ( V_805 ) &
V_807 , 1 ) )
F_119 ( L_130 ) ;
V_108 = F_5 ( V_805 ) ;
}
V_108 |= V_808 ;
F_116 ( V_805 , V_108 ) ;
F_117 ( V_805 ) ;
if ( F_45 ( ( F_5 ( V_805 ) & V_809 ) == 0 , 1 ) )
F_119 ( L_131 ) ;
V_108 = F_552 ( V_12 ) ;
V_108 |= V_810 ;
F_553 ( V_12 , V_108 ) ;
F_555 ( 100 ) ;
if ( F_45 ( ( F_552 ( V_12 ) & V_811 ) == 0 ,
1 ) )
F_119 ( L_132 ) ;
if ( V_804 ) {
V_108 = F_5 ( V_805 ) ;
V_108 |= V_812 ;
F_116 ( V_805 , V_108 ) ;
F_117 ( V_805 ) ;
}
}
static void F_556 ( struct V_11 * V_12 )
{
T_4 V_108 ;
V_108 = F_5 ( V_805 ) ;
if ( ( V_108 & ( V_809 | V_808 | V_806 |
V_812 ) ) == V_809 )
return;
F_234 ( & V_12 -> V_813 . V_814 ) ;
if ( V_12 -> V_813 . V_815 ++ == 0 )
V_12 -> V_813 . V_816 . V_817 ( V_12 , V_818 ) ;
F_235 ( & V_12 -> V_813 . V_814 ) ;
if ( V_108 & V_812 ) {
V_108 &= ~ V_812 ;
F_116 ( V_805 , V_108 ) ;
F_117 ( V_805 ) ;
}
V_108 = F_552 ( V_12 ) ;
V_108 |= V_819 ;
V_108 &= ~ V_810 ;
F_553 ( V_12 , V_108 ) ;
V_108 = F_5 ( V_805 ) ;
V_108 &= ~ V_808 ;
F_116 ( V_805 , V_108 ) ;
if ( F_45 ( F_5 ( V_805 ) & V_809 , 5 ) )
F_119 ( L_133 ) ;
if ( V_108 & V_806 ) {
V_108 = F_5 ( V_805 ) ;
V_108 &= ~ V_806 ;
F_116 ( V_805 , V_108 ) ;
if ( F_514 ( ( F_5 ( V_805 ) &
V_807 ) == 0 , 1 ) )
F_119 ( L_134 ) ;
}
F_234 ( & V_12 -> V_813 . V_814 ) ;
if ( -- V_12 -> V_813 . V_815 == 0 )
V_12 -> V_813 . V_816 . V_820 ( V_12 , V_818 ) ;
F_235 ( & V_12 -> V_813 . V_814 ) ;
}
void F_557 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_108 ;
F_140 ( L_135 ) ;
if ( V_12 -> V_752 == V_753 ) {
V_108 = F_5 ( V_821 ) ;
V_108 &= ~ V_822 ;
F_116 ( V_821 , V_108 ) ;
}
F_517 ( V_10 ) ;
F_554 ( V_12 , true , true ) ;
}
void F_558 ( struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_4 V_108 ;
F_140 ( L_136 ) ;
F_556 ( V_12 ) ;
F_518 ( V_10 ) ;
if ( V_12 -> V_752 == V_753 ) {
V_108 = F_5 ( V_821 ) ;
V_108 |= V_822 ;
F_116 ( V_821 , V_108 ) ;
}
F_559 ( V_10 ) ;
}
static int F_560 ( struct V_28 * V_29 )
{
if ( ! F_561 ( V_29 ) )
return - V_272 ;
V_29 -> V_613 = false ;
return 0 ;
}
static void F_562 ( struct V_11 * V_12 ,
enum V_94 V_94 ,
struct V_198 * V_199 )
{
T_1 V_365 ;
V_365 = F_5 ( V_823 ) & F_563 ( V_94 ) ;
V_199 -> V_824 = V_365 >> ( V_94 * 3 + 1 ) ;
switch ( V_199 -> V_824 ) {
case V_825 :
V_199 -> V_115 = V_826 ;
break;
case V_827 :
V_199 -> V_115 = V_828 ;
break;
case V_829 :
V_199 -> V_115 = V_830 ;
break;
}
}
static void F_564 ( struct V_11 * V_12 ,
enum V_94 V_94 ,
struct V_198 * V_199 )
{
V_199 -> V_824 = F_5 ( F_565 ( V_94 ) ) ;
switch ( V_199 -> V_824 ) {
case V_831 :
V_199 -> V_115 = V_832 ;
break;
case V_833 :
V_199 -> V_115 = V_834 ;
break;
}
}
static void F_566 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_114 * V_117 ;
enum V_94 V_94 ;
T_4 V_204 ;
V_204 = F_5 ( F_60 ( V_199 -> V_84 ) ) ;
V_94 = ( V_204 & V_835 ) >> V_836 ;
if ( F_364 ( V_10 ) )
F_562 ( V_12 , V_94 , V_199 ) ;
else
F_564 ( V_12 , V_94 , V_199 ) ;
if ( V_199 -> V_115 >= 0 ) {
V_117 = & V_12 -> V_116 [ V_199 -> V_115 ] ;
F_3 ( ! V_117 -> V_120 ( V_12 , V_117 ,
& V_199 -> V_200 ) ) ;
}
if ( F_43 ( V_10 ) -> V_91 < 9 &&
( V_94 == V_837 ) && F_5 ( V_244 ) & V_166 ) {
V_199 -> V_247 = true ;
V_204 = F_5 ( F_63 ( V_129 ) ) ;
V_199 -> V_383 = ( ( V_382 & V_204 ) >>
V_780 ) + 1 ;
F_543 ( V_29 , V_199 ) ;
}
}
static bool F_567 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_492 V_838 ;
T_4 V_204 ;
if ( ! F_74 ( V_12 ,
F_386 ( V_29 -> V_4 ) ) )
return false ;
V_199 -> V_84 = (enum V_82 ) V_29 -> V_4 ;
V_199 -> V_115 = V_448 ;
V_204 = F_5 ( F_60 ( V_481 ) ) ;
if ( V_204 & V_122 ) {
enum V_4 V_839 ;
switch ( V_204 & V_840 ) {
default:
F_46 ( 1 , L_137 ) ;
case V_841 :
case V_842 :
V_839 = V_129 ;
break;
case V_843 :
V_839 = V_138 ;
break;
case V_844 :
V_839 = V_376 ;
break;
}
if ( V_839 == V_29 -> V_4 )
V_199 -> V_84 = V_481 ;
}
if ( ! F_74 ( V_12 ,
F_75 ( V_199 -> V_84 ) ) )
return false ;
V_204 = F_5 ( F_44 ( V_199 -> V_84 ) ) ;
if ( ! ( V_204 & V_150 ) )
return false ;
F_566 ( V_29 , V_199 ) ;
F_500 ( V_29 , V_199 ) ;
V_838 = F_387 ( V_29 -> V_4 ) ;
if ( F_74 ( V_12 , V_838 ) ) {
if ( F_364 ( V_10 ) )
F_544 ( V_29 , V_199 ) ;
else
F_545 ( V_29 , V_199 ) ;
}
if ( F_212 ( V_10 ) )
V_199 -> V_462 = F_356 ( V_29 ) &&
( F_5 ( V_466 ) & V_467 ) ;
if ( V_199 -> V_84 != V_481 ) {
V_199 -> V_482 =
F_5 ( F_360 ( V_199 -> V_84 ) ) + 1 ;
} else {
V_199 -> V_482 = 1 ;
}
return true ;
}
static void F_568 ( struct V_75 * V_29 , T_1 V_8 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_4 V_845 = 0 , V_301 = 0 ;
if ( V_8 ) {
unsigned int V_305 = V_28 -> V_846 ;
unsigned int V_257 = V_28 -> V_847 ;
unsigned int V_302 = F_569 ( V_305 ) * 4 ;
switch ( V_302 ) {
default:
F_280 ( 1 , L_138 ,
V_305 , V_302 ) ;
V_302 = 256 ;
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
}
V_845 |= V_145 |
V_848 |
V_849 |
F_570 ( V_302 ) ;
V_301 = ( V_257 << 12 ) | V_305 ;
}
if ( V_28 -> V_850 != 0 &&
( V_28 -> V_851 != V_8 ||
V_28 -> V_852 != V_301 ||
V_28 -> V_850 != V_845 ) ) {
F_116 ( V_144 , 0 ) ;
F_117 ( V_144 ) ;
V_28 -> V_850 = 0 ;
}
if ( V_28 -> V_851 != V_8 ) {
F_116 ( V_853 , V_8 ) ;
V_28 -> V_851 = V_8 ;
}
if ( V_28 -> V_852 != V_301 ) {
F_116 ( V_854 , V_301 ) ;
V_28 -> V_852 = V_301 ;
}
if ( V_28 -> V_850 != V_845 ) {
F_116 ( V_144 , V_845 ) ;
F_117 ( V_144 ) ;
V_28 -> V_850 = V_845 ;
}
}
static void F_571 ( struct V_75 * V_29 , T_1 V_8 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
T_4 V_845 ;
V_845 = 0 ;
if ( V_8 ) {
V_845 = V_855 ;
switch ( V_28 -> V_846 ) {
case 64 :
V_845 |= V_856 ;
break;
case 128 :
V_845 |= V_857 ;
break;
case 256 :
V_845 |= V_858 ;
break;
default:
F_3 ( 1 ) ;
return;
}
V_845 |= V_4 << 28 ;
if ( F_212 ( V_10 ) || F_166 ( V_10 ) )
V_845 |= V_859 ;
}
if ( F_206 ( V_29 -> V_860 ) -> V_326 == F_207 ( V_327 ) )
V_845 |= V_861 ;
if ( V_28 -> V_850 != V_845 ) {
F_116 ( F_72 ( V_4 ) , V_845 ) ;
F_117 ( F_72 ( V_4 ) ) ;
V_28 -> V_850 = V_845 ;
}
F_116 ( F_572 ( V_4 ) , V_8 ) ;
F_117 ( F_572 ( V_4 ) ) ;
V_28 -> V_851 = V_8 ;
}
static void F_343 ( struct V_75 * V_29 ,
bool V_225 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_4 = V_28 -> V_4 ;
int V_254 = V_29 -> V_862 ;
int V_255 = V_29 -> V_863 ;
T_1 V_8 = 0 , V_458 = 0 ;
if ( V_225 )
V_8 = V_28 -> V_864 ;
if ( V_254 >= V_28 -> V_79 . V_316 )
V_8 = 0 ;
if ( V_255 >= V_28 -> V_79 . V_315 )
V_8 = 0 ;
if ( V_254 < 0 ) {
if ( V_254 + V_28 -> V_846 <= 0 )
V_8 = 0 ;
V_458 |= V_865 << V_866 ;
V_254 = - V_254 ;
}
V_458 |= V_254 << V_866 ;
if ( V_255 < 0 ) {
if ( V_255 + V_28 -> V_847 <= 0 )
V_8 = 0 ;
V_458 |= V_865 << V_867 ;
V_255 = - V_255 ;
}
V_458 |= V_255 << V_867 ;
if ( V_8 == 0 && V_28 -> V_851 == 0 )
return;
F_116 ( F_573 ( V_4 ) , V_458 ) ;
if ( F_337 ( V_10 ) &&
F_206 ( V_29 -> V_860 ) -> V_326 == F_207 ( V_327 ) ) {
V_8 += ( V_28 -> V_847 *
V_28 -> V_846 - 1 ) * 4 ;
}
if ( F_70 ( V_10 ) || F_71 ( V_10 ) )
F_568 ( V_29 , V_8 ) ;
else
F_571 ( V_29 , V_8 ) ;
}
static bool F_574 ( struct V_9 * V_10 ,
T_4 V_305 , T_4 V_257 )
{
if ( V_305 == 0 || V_257 == 0 )
return false ;
if ( F_70 ( V_10 ) || F_71 ( V_10 ) ) {
if ( ( V_305 & 63 ) != 0 )
return false ;
if ( V_305 > ( F_70 ( V_10 ) ? 64 : 512 ) )
return false ;
if ( V_257 > 1023 )
return false ;
} else {
switch ( V_305 | V_257 ) {
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
static int F_575 ( struct V_75 * V_29 ,
struct V_263 * V_264 ,
T_4 V_305 , T_4 V_257 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = F_228 ( V_10 ) ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
unsigned V_868 ;
T_4 V_869 ;
int V_266 ;
if ( ! V_264 ) {
F_140 ( L_139 ) ;
V_869 = 0 ;
F_53 ( & V_10 -> V_267 ) ;
goto V_870;
}
F_53 ( & V_10 -> V_267 ) ;
if ( ! F_43 ( V_10 ) -> V_871 ) {
unsigned V_265 ;
F_178 ( V_12 ) ;
V_265 = 0 ;
if ( F_169 ( V_10 ) )
V_265 = 64 * 1024 ;
V_266 = F_179 ( V_264 , V_265 , NULL ) ;
if ( V_266 ) {
F_140 ( L_140 ) ;
F_182 ( V_12 ) ;
goto V_872;
}
V_266 = F_576 ( V_264 ) ;
if ( V_266 ) {
F_140 ( L_141 ) ;
F_182 ( V_12 ) ;
goto V_873;
}
V_869 = F_197 ( V_264 ) ;
F_182 ( V_12 ) ;
} else {
int V_874 = F_129 ( V_10 ) ? 16 * 1024 : 256 ;
V_266 = F_577 ( V_264 , V_874 ) ;
if ( V_266 ) {
F_140 ( L_142 ) ;
goto V_872;
}
V_869 = V_264 -> V_875 -> V_876 ;
}
V_870:
if ( V_28 -> V_877 ) {
if ( ! F_43 ( V_10 ) -> V_871 )
F_183 ( V_28 -> V_877 ) ;
}
F_250 ( V_28 -> V_877 , V_264 ,
F_578 ( V_4 ) ) ;
F_55 ( & V_10 -> V_267 ) ;
V_868 = V_28 -> V_846 ;
V_28 -> V_864 = V_869 ;
V_28 -> V_877 = V_264 ;
V_28 -> V_846 = V_305 ;
V_28 -> V_847 = V_257 ;
if ( V_28 -> V_76 ) {
if ( V_868 != V_305 )
F_354 ( V_29 ) ;
F_343 ( V_29 , V_28 -> V_877 != NULL ) ;
F_251 ( V_10 , F_578 ( V_4 ) ) ;
}
return 0 ;
V_873:
F_183 ( V_264 ) ;
V_872:
F_55 ( & V_10 -> V_267 ) ;
return V_266 ;
}
static void F_579 ( struct V_75 * V_29 , T_5 * V_878 , T_5 * V_879 ,
T_5 * V_880 , T_4 V_881 , T_4 V_301 )
{
int V_882 = ( V_881 + V_301 > 256 ) ? 256 : V_881 + V_301 , V_153 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
for ( V_153 = V_881 ; V_153 < V_882 ; V_153 ++ ) {
V_28 -> V_472 [ V_153 ] = V_878 [ V_153 ] >> 8 ;
V_28 -> V_473 [ V_153 ] = V_879 [ V_153 ] >> 8 ;
V_28 -> V_474 [ V_153 ] = V_880 [ V_153 ] >> 8 ;
}
F_335 ( V_29 ) ;
}
struct V_260 *
F_580 ( struct V_9 * V_10 ,
struct V_299 * V_300 ,
struct V_263 * V_264 )
{
struct V_330 * V_331 ;
int V_266 ;
V_331 = F_507 ( sizeof( * V_331 ) , V_453 ) ;
if ( ! V_331 ) {
F_193 ( & V_264 -> V_8 ) ;
return F_581 ( - V_455 ) ;
}
V_266 = F_190 ( V_10 , V_331 , V_300 , V_264 ) ;
if ( V_266 )
goto V_63;
return & V_331 -> V_8 ;
V_63:
F_193 ( & V_264 -> V_8 ) ;
F_195 ( V_331 ) ;
return F_581 ( V_266 ) ;
}
static struct V_260 *
F_582 ( struct V_9 * V_10 ,
struct V_299 * V_300 ,
struct V_263 * V_264 )
{
struct V_260 * V_78 ;
int V_266 ;
V_266 = F_583 ( V_10 ) ;
if ( V_266 )
return F_581 ( V_266 ) ;
V_78 = F_580 ( V_10 , V_300 , V_264 ) ;
F_55 ( & V_10 -> V_267 ) ;
return V_78 ;
}
static T_1
F_584 ( int V_305 , int V_773 )
{
T_1 V_278 = F_393 ( V_305 * V_773 , 8 ) ;
return F_172 ( V_278 , 64 ) ;
}
static T_1
F_585 ( struct V_355 * V_442 , int V_773 )
{
T_1 V_278 = F_584 ( V_442 -> V_568 , V_773 ) ;
return F_508 ( V_278 * V_442 -> V_691 ) ;
}
static struct V_260 *
F_586 ( struct V_9 * V_10 ,
struct V_355 * V_442 ,
int V_883 , int V_773 )
{
struct V_263 * V_264 ;
struct V_299 V_300 = { 0 } ;
V_264 = F_587 ( V_10 ,
F_585 ( V_442 , V_773 ) ) ;
if ( V_264 == NULL )
return F_581 ( - V_455 ) ;
V_300 . V_305 = V_442 -> V_568 ;
V_300 . V_257 = V_442 -> V_691 ;
V_300 . V_303 [ 0 ] = F_584 ( V_300 . V_305 ,
V_773 ) ;
V_300 . V_304 = F_588 ( V_773 , V_883 ) ;
return F_582 ( V_10 , & V_300 , V_264 ) ;
}
static struct V_260 *
F_589 ( struct V_9 * V_10 ,
struct V_355 * V_442 )
{
#ifdef F_590
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_263 * V_264 ;
struct V_260 * V_78 ;
if ( ! V_12 -> V_884 )
return NULL ;
if ( ! V_12 -> V_884 -> V_78 )
return NULL ;
V_264 = V_12 -> V_884 -> V_78 -> V_264 ;
F_114 ( ! V_264 ) ;
V_78 = & V_12 -> V_884 -> V_78 -> V_8 ;
if ( V_78 -> V_303 [ 0 ] < F_584 ( V_442 -> V_568 ,
V_78 -> V_593 ) )
return NULL ;
if ( V_264 -> V_8 . V_301 < V_442 -> V_691 * V_78 -> V_303 [ 0 ] )
return NULL ;
return V_78 ;
#else
return NULL ;
#endif
}
bool F_591 ( struct V_550 * V_3 ,
struct V_355 * V_442 ,
struct V_885 * V_886 ,
struct V_887 * V_888 )
{
struct V_28 * V_28 ;
struct V_1 * V_1 =
F_592 ( V_3 ) ;
struct V_75 * V_889 ;
struct V_554 * V_6 = & V_1 -> V_8 ;
struct V_75 * V_29 = NULL ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_260 * V_78 ;
struct V_890 * V_79 = & V_10 -> V_891 ;
int V_266 , V_153 = - 1 ;
F_140 ( L_143 ,
V_3 -> V_8 . V_227 , V_3 -> V_121 ,
V_6 -> V_8 . V_227 , V_6 -> V_121 ) ;
V_388:
V_266 = F_225 ( & V_79 -> V_892 , V_888 ) ;
if ( V_266 )
goto V_893;
if ( V_6 -> V_29 ) {
V_29 = V_6 -> V_29 ;
V_266 = F_225 ( & V_29 -> V_344 , V_888 ) ;
if ( V_266 )
goto V_893;
V_266 = F_225 ( & V_29 -> V_77 -> V_344 , V_888 ) ;
if ( V_266 )
goto V_893;
V_886 -> V_894 = V_3 -> V_552 ;
V_886 -> V_895 = false ;
if ( V_3 -> V_552 != V_555 )
V_3 -> V_816 -> V_552 ( V_3 , V_555 ) ;
return true ;
}
F_196 (dev, possible_crtc) {
V_153 ++ ;
if ( ! ( V_6 -> V_896 & ( 1 << V_153 ) ) )
continue;
if ( V_889 -> V_106 )
continue;
if ( F_37 ( V_889 ) -> V_538 )
continue;
V_29 = V_889 ;
break;
}
if ( ! V_29 ) {
F_140 ( L_144 ) ;
goto V_893;
}
V_266 = F_225 ( & V_29 -> V_344 , V_888 ) ;
if ( V_266 )
goto V_893;
V_266 = F_225 ( & V_29 -> V_77 -> V_344 , V_888 ) ;
if ( V_266 )
goto V_893;
V_1 -> V_31 = F_37 ( V_29 ) ;
F_593 ( V_3 ) -> V_897 = V_1 ;
V_28 = F_37 ( V_29 ) ;
V_28 -> V_538 = true ;
V_28 -> V_450 = & V_28 -> V_79 ;
V_886 -> V_894 = V_3 -> V_552 ;
V_886 -> V_895 = true ;
V_886 -> V_898 = NULL ;
if ( ! V_442 )
V_442 = & V_899 ;
V_78 = F_589 ( V_10 , V_442 ) ;
if ( V_78 == NULL ) {
F_140 ( L_145 ) ;
V_78 = F_586 ( V_10 , V_442 , 24 , 32 ) ;
V_886 -> V_898 = V_78 ;
} else
F_140 ( L_146 ) ;
if ( F_594 ( V_78 ) ) {
F_140 ( L_147 ) ;
goto V_900;
}
if ( F_595 ( V_29 , V_442 , 0 , 0 , V_78 ) ) {
F_140 ( L_148 ) ;
if ( V_886 -> V_898 )
V_886 -> V_898 -> V_816 -> V_901 ( V_886 -> V_898 ) ;
goto V_900;
}
F_167 ( V_10 , V_28 -> V_4 ) ;
return true ;
V_900:
V_28 -> V_538 = V_29 -> V_106 ;
if ( V_28 -> V_538 )
V_28 -> V_450 = & V_28 -> V_79 ;
else
V_28 -> V_450 = NULL ;
V_893:
if ( V_266 == - V_902 ) {
F_596 ( V_888 ) ;
goto V_388;
}
return false ;
}
void F_597 ( struct V_550 * V_3 ,
struct V_885 * V_886 )
{
struct V_1 * V_1 =
F_592 ( V_3 ) ;
struct V_554 * V_6 = & V_1 -> V_8 ;
struct V_75 * V_29 = V_6 -> V_29 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
F_140 ( L_143 ,
V_3 -> V_8 . V_227 , V_3 -> V_121 ,
V_6 -> V_8 . V_227 , V_6 -> V_121 ) ;
if ( V_886 -> V_895 ) {
F_593 ( V_3 ) -> V_897 = NULL ;
V_1 -> V_31 = NULL ;
V_28 -> V_538 = false ;
V_28 -> V_450 = NULL ;
F_595 ( V_29 , NULL , 0 , 0 , NULL ) ;
if ( V_886 -> V_898 ) {
F_598 ( V_886 -> V_898 ) ;
F_599 ( V_886 -> V_898 ) ;
}
return;
}
if ( V_886 -> V_894 != V_555 )
V_3 -> V_816 -> V_552 ( V_3 , V_886 -> V_894 ) ;
}
static int F_600 ( struct V_9 * V_10 ,
const struct V_198 * V_199 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_56 = V_199 -> V_200 . V_56 ;
if ( ( V_56 & V_903 ) == V_674 )
return V_12 -> V_605 . V_609 ;
else if ( F_4 ( V_10 ) )
return 120000 ;
else if ( ! F_22 ( V_10 ) )
return 96000 ;
else
return 48000 ;
}
static void F_511 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_4 = V_199 -> V_84 ;
T_1 V_56 = V_199 -> V_200 . V_56 ;
T_1 V_611 ;
T_2 clock ;
int V_18 = F_600 ( V_10 , V_199 ) ;
if ( ( V_56 & V_904 ) == 0 )
V_611 = V_199 -> V_200 . V_545 ;
else
V_611 = V_199 -> V_200 . V_546 ;
clock . V_20 = ( V_611 & V_905 ) >> V_906 ;
if ( F_19 ( V_10 ) ) {
clock . V_25 = F_601 ( ( V_611 & V_907 ) >> V_908 ) - 1 ;
clock . V_21 = ( V_611 & V_909 ) >> V_910 ;
} else {
clock . V_25 = ( V_611 & V_911 ) >> V_908 ;
clock . V_21 = ( V_611 & V_912 ) >> V_910 ;
}
if ( ! F_22 ( V_10 ) ) {
if ( F_19 ( V_10 ) )
clock . V_23 = F_601 ( ( V_56 & V_913 ) >>
V_664 ) ;
else
clock . V_23 = F_601 ( ( V_56 & V_914 ) >>
V_665 ) ;
switch ( V_56 & V_915 ) {
case V_661 :
clock . V_24 = V_56 & V_667 ?
5 : 10 ;
break;
case V_660 :
clock . V_24 = V_56 & V_668 ?
7 : 14 ;
break;
default:
F_140 ( L_149
L_150 , ( int ) ( V_56 & V_915 ) ) ;
return;
}
if ( F_19 ( V_10 ) )
F_23 ( V_18 , & clock ) ;
else
F_25 ( V_18 , & clock ) ;
} else {
T_1 V_916 = F_129 ( V_10 ) ? 0 : F_5 ( V_140 ) ;
bool V_712 = ( V_4 == 1 ) && ( V_916 & V_177 ) ;
if ( V_712 ) {
clock . V_23 = F_601 ( ( V_56 & V_917 ) >>
V_665 ) ;
if ( V_916 & V_918 )
clock . V_24 = 7 ;
else
clock . V_24 = 14 ;
} else {
if ( V_56 & V_676 )
clock . V_23 = 2 ;
else {
clock . V_23 = ( ( V_56 & V_919 ) >>
V_665 ) + 2 ;
}
if ( V_56 & V_677 )
clock . V_24 = 4 ;
else
clock . V_24 = 2 ;
}
F_25 ( V_18 , & clock ) ;
}
V_199 -> V_643 = clock . V_27 ;
}
int F_602 ( int V_920 ,
const struct V_597 * V_598 )
{
if ( ! V_598 -> V_603 )
return 0 ;
return F_34 ( ( V_921 ) V_598 -> V_602 * V_920 , V_598 -> V_603 ) ;
}
static void F_549 ( struct V_28 * V_29 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
F_511 ( V_29 , V_199 ) ;
V_199 -> V_80 . V_81 =
F_602 ( F_6 ( V_10 ) * 10000 ,
& V_199 -> V_477 ) ;
}
struct V_355 * F_603 ( struct V_9 * V_10 ,
struct V_75 * V_29 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_82 V_84 = V_28 -> V_79 . V_84 ;
struct V_355 * V_442 ;
struct V_198 V_199 ;
int V_922 = F_5 ( F_290 ( V_84 ) ) ;
int V_923 = F_5 ( F_294 ( V_84 ) ) ;
int V_924 = F_5 ( F_296 ( V_84 ) ) ;
int V_925 = F_5 ( F_300 ( V_84 ) ) ;
enum V_4 V_4 = V_28 -> V_4 ;
V_442 = F_507 ( sizeof( * V_442 ) , V_453 ) ;
if ( ! V_442 )
return NULL ;
V_199 . V_84 = (enum V_82 ) V_4 ;
V_199 . V_482 = 1 ;
V_199 . V_200 . V_56 = F_5 ( F_51 ( V_4 ) ) ;
V_199 . V_200 . V_545 = F_5 ( F_413 ( V_4 ) ) ;
V_199 . V_200 . V_546 = F_5 ( F_414 ( V_4 ) ) ;
F_511 ( V_28 , & V_199 ) ;
V_442 -> clock = V_199 . V_643 / V_199 . V_482 ;
V_442 -> V_568 = ( V_922 & 0xffff ) + 1 ;
V_442 -> V_692 = ( ( V_922 & 0xffff0000 ) >> 16 ) + 1 ;
V_442 -> V_567 = ( V_923 & 0xffff ) + 1 ;
V_442 -> V_693 = ( ( V_923 & 0xffff0000 ) >> 16 ) + 1 ;
V_442 -> V_691 = ( V_924 & 0xffff ) + 1 ;
V_442 -> V_694 = ( ( V_924 & 0xffff0000 ) >> 16 ) + 1 ;
V_442 -> V_695 = ( V_925 & 0xffff ) + 1 ;
V_442 -> V_696 = ( ( V_925 & 0xffff0000 ) >> 16 ) + 1 ;
F_604 ( V_442 ) ;
return V_442 ;
}
static void F_605 ( struct V_75 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
if ( ! F_337 ( V_10 ) )
return;
if ( ! V_12 -> V_715 )
return;
if ( ! F_502 ( V_10 ) && V_28 -> V_613 ) {
int V_4 = V_28 -> V_4 ;
int V_219 = F_51 ( V_4 ) ;
int V_56 ;
F_137 ( L_151 ) ;
F_66 ( V_12 , V_4 ) ;
V_56 = F_5 ( V_219 ) ;
V_56 |= V_904 ;
F_116 ( V_219 , V_56 ) ;
F_167 ( V_10 , V_4 ) ;
V_56 = F_5 ( V_219 ) ;
if ( ! ( V_56 & V_904 ) )
F_137 ( L_152 ) ;
}
}
void F_606 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_12 -> V_273 . V_926 )
return;
F_178 ( V_12 ) ;
F_607 ( V_12 ) ;
V_12 -> V_273 . V_926 = true ;
}
void F_608 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_29 ;
if ( ! V_12 -> V_273 . V_926 )
return;
V_12 -> V_273 . V_926 = false ;
if ( ! V_356 . V_614 )
goto V_927;
F_196 (dev, crtc) {
if ( ! V_29 -> V_77 -> V_78 )
continue;
F_605 ( V_29 ) ;
}
if ( F_43 ( V_10 ) -> V_91 >= 6 )
F_609 ( V_10 -> V_13 ) ;
V_927:
F_182 ( V_12 ) ;
}
static void F_610 ( struct V_75 * V_29 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_404 * V_405 ;
F_234 ( & V_10 -> V_353 ) ;
V_405 = V_28 -> V_354 ;
V_28 -> V_354 = NULL ;
F_235 ( & V_10 -> V_353 ) ;
if ( V_405 ) {
F_611 ( & V_405 -> V_405 ) ;
F_195 ( V_405 ) ;
}
F_612 ( V_29 ) ;
F_195 ( V_28 ) ;
}
static void F_613 ( struct V_928 * V_929 )
{
struct V_404 * V_405 =
F_614 ( V_929 , struct V_404 , V_405 ) ;
struct V_9 * V_10 = V_405 -> V_29 -> V_10 ;
enum V_4 V_4 = F_37 ( V_405 -> V_29 ) -> V_4 ;
F_53 ( & V_10 -> V_267 ) ;
F_184 ( V_405 -> V_930 ) ;
F_193 ( & V_405 -> V_409 -> V_8 ) ;
F_193 ( & V_405 -> V_930 -> V_8 ) ;
F_252 ( V_10 ) ;
F_55 ( & V_10 -> V_267 ) ;
F_615 ( V_10 , F_192 ( V_4 ) ) ;
F_114 ( F_243 ( & F_37 ( V_405 -> V_29 ) -> V_403 ) == 0 ) ;
F_616 ( & F_37 ( V_405 -> V_29 ) -> V_403 ) ;
F_195 ( V_405 ) ;
}
static void F_617 ( struct V_9 * V_10 ,
struct V_75 * V_29 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_404 * V_405 ;
unsigned long V_443 ;
if ( V_28 == NULL )
return;
F_618 ( & V_10 -> V_353 , V_443 ) ;
V_405 = V_28 -> V_354 ;
F_272 () ;
if ( V_405 == NULL || F_243 ( & V_405 -> V_350 ) < V_931 ) {
F_619 ( & V_10 -> V_353 , V_443 ) ;
return;
}
F_271 ( V_28 ) ;
F_619 ( & V_10 -> V_353 , V_443 ) ;
}
void F_620 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_29 = V_12 -> V_83 [ V_4 ] ;
F_617 ( V_10 , V_29 ) ;
}
void F_223 ( struct V_9 * V_10 , int V_151 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_29 = V_12 -> V_932 [ V_151 ] ;
F_617 ( V_10 , V_29 ) ;
}
static bool F_621 ( T_1 V_933 , T_1 V_934 )
{
return ! ( ( V_933 - V_934 ) & 0x80000000 ) ;
}
static bool F_622 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_242 ( & V_12 -> V_351 ) ||
V_29 -> V_352 != F_243 ( & V_12 -> V_351 . V_352 ) )
return true ;
if ( F_43 ( V_10 ) -> V_91 < 5 && ! F_18 ( V_10 ) )
return true ;
return ( F_5 ( F_623 ( V_29 -> V_151 ) ) & ~ 0xfff ) ==
V_29 -> V_354 -> V_935 &&
F_621 ( F_5 ( F_624 ( V_29 -> V_4 ) ) ,
V_29 -> V_354 -> V_936 ) ;
}
void F_222 ( struct V_9 * V_10 , int V_151 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 =
F_37 ( V_12 -> V_932 [ V_151 ] ) ;
unsigned long V_443 ;
F_618 ( & V_10 -> V_353 , V_443 ) ;
if ( V_28 -> V_354 && F_622 ( V_28 ) )
F_625 ( & V_28 -> V_354 -> V_350 ) ;
F_619 ( & V_10 -> V_353 , V_443 ) ;
}
static inline void F_626 ( struct V_28 * V_28 )
{
F_627 () ;
F_628 ( & V_28 -> V_354 -> V_350 , V_937 ) ;
F_627 () ;
}
static int F_629 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_938 ,
T_4 V_443 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_1 V_939 ;
int V_266 ;
V_266 = F_630 ( V_938 , 6 ) ;
if ( V_266 )
return V_266 ;
if ( V_28 -> V_151 )
V_939 = V_940 ;
else
V_939 = V_941 ;
F_631 ( V_938 , V_942 | V_939 ) ;
F_631 ( V_938 , V_943 ) ;
F_631 ( V_938 , V_944 |
F_632 ( V_28 -> V_151 ) ) ;
F_631 ( V_938 , V_78 -> V_303 [ 0 ] ) ;
F_631 ( V_938 , V_28 -> V_354 -> V_935 ) ;
F_631 ( V_938 , 0 ) ;
F_626 ( V_28 ) ;
F_633 ( V_938 ) ;
return 0 ;
}
static int F_634 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_938 ,
T_4 V_443 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_1 V_939 ;
int V_266 ;
V_266 = F_630 ( V_938 , 6 ) ;
if ( V_266 )
return V_266 ;
if ( V_28 -> V_151 )
V_939 = V_940 ;
else
V_939 = V_941 ;
F_631 ( V_938 , V_942 | V_939 ) ;
F_631 ( V_938 , V_943 ) ;
F_631 ( V_938 , V_945 |
F_632 ( V_28 -> V_151 ) ) ;
F_631 ( V_938 , V_78 -> V_303 [ 0 ] ) ;
F_631 ( V_938 , V_28 -> V_354 -> V_935 ) ;
F_631 ( V_938 , V_943 ) ;
F_626 ( V_28 ) ;
F_633 ( V_938 ) ;
return 0 ;
}
static int F_635 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_938 ,
T_4 V_443 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_4 V_946 , V_947 ;
int V_266 ;
V_266 = F_630 ( V_938 , 4 ) ;
if ( V_266 )
return V_266 ;
F_631 ( V_938 , V_944 |
F_632 ( V_28 -> V_151 ) ) ;
F_631 ( V_938 , V_78 -> V_303 [ 0 ] ) ;
F_631 ( V_938 , V_28 -> V_354 -> V_935 |
V_264 -> V_268 ) ;
V_946 = 0 ;
V_947 = F_5 ( F_245 ( V_28 -> V_4 ) ) & 0x0fff0fff ;
F_631 ( V_938 , V_946 | V_947 ) ;
F_626 ( V_28 ) ;
F_633 ( V_938 ) ;
return 0 ;
}
static int F_636 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_938 ,
T_4 V_443 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_4 V_946 , V_947 ;
int V_266 ;
V_266 = F_630 ( V_938 , 4 ) ;
if ( V_266 )
return V_266 ;
F_631 ( V_938 , V_944 |
F_632 ( V_28 -> V_151 ) ) ;
F_631 ( V_938 , V_78 -> V_303 [ 0 ] | V_264 -> V_268 ) ;
F_631 ( V_938 , V_28 -> V_354 -> V_935 ) ;
V_946 = 0 ;
V_947 = F_5 ( F_245 ( V_28 -> V_4 ) ) & 0x0fff0fff ;
F_631 ( V_938 , V_946 | V_947 ) ;
F_626 ( V_28 ) ;
F_633 ( V_938 ) ;
return 0 ;
}
static int F_637 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_938 ,
T_4 V_443 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_4 V_948 = 0 ;
int V_949 , V_266 ;
switch ( V_28 -> V_151 ) {
case V_950 :
V_948 = V_951 ;
break;
case V_317 :
V_948 = V_952 ;
break;
case V_953 :
V_948 = V_954 ;
break;
default:
F_280 ( 1 , L_153 ) ;
return - V_955 ;
}
V_949 = 4 ;
if ( V_938 -> V_227 == V_956 ) {
V_949 += 6 ;
if ( F_638 ( V_10 ) )
V_949 += 2 ;
}
V_266 = F_639 ( V_938 ) ;
if ( V_266 )
return V_266 ;
V_266 = F_630 ( V_938 , V_949 ) ;
if ( V_266 )
return V_266 ;
if ( V_938 -> V_227 == V_956 ) {
F_631 ( V_938 , F_640 ( 1 ) ) ;
F_631 ( V_938 , V_957 ) ;
F_631 ( V_938 , ~ ( V_958 |
V_959 |
V_960 ) ) ;
if ( F_638 ( V_10 ) )
F_631 ( V_938 , F_641 ( 1 ) |
V_961 ) ;
else
F_631 ( V_938 , F_642 ( 1 ) |
V_961 ) ;
F_631 ( V_938 , V_957 ) ;
F_631 ( V_938 , V_938 -> V_962 . V_935 + 256 ) ;
if ( F_638 ( V_10 ) ) {
F_631 ( V_938 , 0 ) ;
F_631 ( V_938 , V_943 ) ;
}
}
F_631 ( V_938 , V_945 | V_948 ) ;
F_631 ( V_938 , ( V_78 -> V_303 [ 0 ] | V_264 -> V_268 ) ) ;
F_631 ( V_938 , V_28 -> V_354 -> V_935 ) ;
F_631 ( V_938 , ( V_943 ) ) ;
F_626 ( V_28 ) ;
F_633 ( V_938 ) ;
return 0 ;
}
static bool F_643 ( struct V_261 * V_938 ,
struct V_263 * V_264 )
{
if ( V_938 == NULL )
return true ;
if ( F_43 ( V_938 -> V_10 ) -> V_91 < 5 )
return false ;
if ( V_356 . F_643 < 0 )
return false ;
else if ( V_356 . F_643 > 0 )
return true ;
else if ( V_356 . V_963 )
return true ;
else
return V_938 != V_264 -> V_938 ;
}
static void F_644 ( struct V_28 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_330 * V_331 =
F_191 ( V_28 -> V_8 . V_77 -> V_78 ) ;
struct V_263 * V_264 = V_331 -> V_264 ;
bool V_964 ;
T_1 V_965 ;
T_1 V_311 ;
T_1 V_85 ;
F_626 ( V_28 ) ;
V_964 = F_645 ( V_28 , & V_965 ) ;
V_85 = F_77 ( V_28 -> V_151 ) ;
V_311 = F_5 ( V_85 ) ;
if ( V_264 -> V_268 != V_269 )
V_311 |= V_323 ;
else
V_311 &= ~ V_323 ;
F_116 ( V_85 , V_311 ) ;
F_116 ( F_162 ( V_28 -> V_151 ) ,
V_28 -> V_354 -> V_935 ) ;
F_117 ( F_162 ( V_28 -> V_151 ) ) ;
if ( V_964 )
F_646 ( V_28 , V_965 ) ;
}
static void F_647 ( struct V_928 * V_405 )
{
struct V_28 * V_28 =
F_614 ( V_405 , struct V_28 , V_966 . V_405 ) ;
struct V_261 * V_938 ;
T_4 V_967 ;
V_967 = V_28 -> V_966 . V_967 ;
V_938 = V_28 -> V_966 . V_938 ;
if ( V_967 )
F_3 ( F_648 ( V_938 , V_967 ,
V_28 -> V_352 ,
false , NULL , NULL ) != 0 ) ;
F_644 ( V_28 ) ;
}
static int F_649 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_938 ,
T_4 V_443 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
V_28 -> V_966 . V_967 = V_264 -> V_968 ;
V_28 -> V_966 . V_938 = V_264 -> V_938 ;
F_650 ( & V_28 -> V_966 . V_405 ) ;
return 0 ;
}
static int F_651 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_938 ,
T_4 V_443 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
T_4 V_151 = 0 , V_302 ;
int V_266 ;
switch( V_28 -> V_4 ) {
case V_129 :
V_151 = V_969 ;
break;
case V_138 :
V_151 = V_970 ;
break;
case V_376 :
V_151 = V_971 ;
break;
default:
F_280 ( 1 , L_153 ) ;
return - V_955 ;
}
switch ( V_264 -> V_268 ) {
case V_269 :
V_302 = V_78 -> V_303 [ 0 ] >> 6 ;
break;
case V_270 :
V_302 = V_78 -> V_303 [ 0 ] >> 9 ;
break;
default:
F_280 ( 1 , L_154 ) ;
return - V_955 ;
}
V_266 = F_630 ( V_938 , 10 ) ;
if ( V_266 )
return V_266 ;
F_631 ( V_938 , F_640 ( 1 ) ) ;
F_631 ( V_938 , V_957 ) ;
F_631 ( V_938 , ~ ( V_958 |
V_959 |
V_960 ) ) ;
F_631 ( V_938 , F_641 ( 1 ) |
V_961 ) ;
F_631 ( V_938 , V_957 ) ;
F_631 ( V_938 , V_938 -> V_962 . V_935 + 256 ) ;
F_631 ( V_938 , 0 ) ;
F_631 ( V_938 , V_945 | V_151 ) ;
F_631 ( V_938 , V_302 << 6 | V_264 -> V_268 ) ;
F_631 ( V_938 , V_28 -> V_354 -> V_935 ) ;
F_626 ( V_28 ) ;
F_633 ( V_938 ) ;
return 0 ;
}
static int F_652 ( struct V_9 * V_10 ,
struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_263 * V_264 ,
struct V_261 * V_938 ,
T_4 V_443 )
{
return - V_955 ;
}
static bool F_653 ( struct V_9 * V_10 ,
struct V_75 * V_29 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_404 * V_405 = V_28 -> V_354 ;
T_1 V_869 ;
if ( F_243 ( & V_405 -> V_350 ) >= V_931 )
return true ;
if ( ! V_405 -> V_972 )
return false ;
if ( V_405 -> V_973 == 0 ) {
if ( V_405 -> V_974 &&
! F_654 ( V_405 -> V_974 -> V_975 ( V_405 -> V_974 , true ) ,
V_405 -> V_976 ) )
return false ;
V_405 -> V_973 = F_655 ( V_10 , V_28 -> V_4 ) ;
}
if ( F_655 ( V_10 , V_28 -> V_4 ) - V_405 -> V_973 < 3 )
return false ;
if ( F_43 ( V_10 ) -> V_91 >= 4 )
V_869 = F_656 ( F_5 ( F_162 ( V_28 -> V_151 ) ) ) ;
else
V_869 = F_5 ( F_163 ( V_28 -> V_151 ) ) ;
return V_869 == V_405 -> V_935 ;
}
void F_657 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_29 = V_12 -> V_83 [ V_4 ] ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
F_3 ( ! F_658 () ) ;
if ( V_29 == NULL )
return;
F_659 ( & V_10 -> V_353 ) ;
if ( V_28 -> V_354 && F_653 ( V_10 , V_29 ) ) {
F_280 ( 1 , L_155 ,
V_28 -> V_354 -> V_977 , F_655 ( V_10 , V_4 ) ) ;
F_271 ( V_28 ) ;
}
F_660 ( & V_10 -> V_353 ) ;
}
static int F_661 ( struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_978 * V_406 ,
T_4 V_979 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_260 * V_348 = V_29 -> V_77 -> V_78 ;
struct V_263 * V_264 = F_174 ( V_78 ) ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
struct V_404 * V_405 ;
struct V_261 * V_938 ;
int V_266 ;
if ( F_3 ( F_174 ( V_348 ) == NULL ) )
return - V_363 ;
if ( V_78 -> V_304 != V_29 -> V_77 -> V_78 -> V_304 )
return - V_272 ;
if ( F_43 ( V_10 ) -> V_91 > 3 &&
( V_78 -> V_980 [ 0 ] != V_29 -> V_77 -> V_78 -> V_980 [ 0 ] ||
V_78 -> V_303 [ 0 ] != V_29 -> V_77 -> V_78 -> V_303 [ 0 ] ) )
return - V_272 ;
if ( F_662 ( & V_12 -> V_351 ) )
goto V_981;
V_405 = F_507 ( sizeof( * V_405 ) , V_453 ) ;
if ( V_405 == NULL )
return - V_455 ;
V_405 -> V_406 = V_406 ;
V_405 -> V_29 = V_29 ;
V_405 -> V_930 = F_174 ( V_348 ) ;
F_663 ( & V_405 -> V_405 , F_613 ) ;
V_266 = F_89 ( V_29 ) ;
if ( V_266 )
goto V_982;
F_234 ( & V_10 -> V_353 ) ;
if ( V_28 -> V_354 ) {
if ( F_653 ( V_10 , V_29 ) ) {
F_137 ( L_156 ) ;
F_271 ( V_28 ) ;
} else {
F_137 ( L_157 ) ;
F_235 ( & V_10 -> V_353 ) ;
F_90 ( V_29 ) ;
F_195 ( V_405 ) ;
return - V_363 ;
}
}
V_28 -> V_354 = V_405 ;
F_235 ( & V_10 -> V_353 ) ;
if ( F_243 ( & V_28 -> V_403 ) >= 2 )
F_664 ( V_12 -> V_408 ) ;
V_266 = F_583 ( V_10 ) ;
if ( V_266 )
goto V_454;
F_665 ( & V_405 -> V_930 -> V_8 ) ;
F_665 ( & V_264 -> V_8 ) ;
V_29 -> V_77 -> V_78 = V_78 ;
V_405 -> V_409 = V_264 ;
F_666 ( & V_28 -> V_403 ) ;
V_28 -> V_352 = F_243 ( & V_12 -> V_351 . V_352 ) ;
if ( F_43 ( V_10 ) -> V_91 >= 5 || F_18 ( V_10 ) )
V_405 -> V_936 = F_5 ( F_624 ( V_4 ) ) + 1 ;
if ( F_21 ( V_10 ) ) {
V_938 = & V_12 -> V_938 [ V_983 ] ;
if ( V_264 -> V_268 != V_405 -> V_930 -> V_268 )
V_938 = NULL ;
} else if ( F_254 ( V_10 ) || F_212 ( V_10 ) ) {
V_938 = & V_12 -> V_938 [ V_983 ] ;
} else if ( F_43 ( V_10 ) -> V_91 >= 7 ) {
V_938 = V_264 -> V_938 ;
if ( V_938 == NULL || V_938 -> V_227 != V_956 )
V_938 = & V_12 -> V_938 [ V_983 ] ;
} else {
V_938 = & V_12 -> V_938 [ V_956 ] ;
}
V_266 = F_173 ( V_29 -> V_77 , V_78 , V_938 ) ;
if ( V_266 )
goto V_984;
V_405 -> V_935 =
F_197 ( V_264 ) + V_28 -> V_325 ;
if ( F_643 ( V_938 , V_264 ) ) {
V_266 = F_649 ( V_10 , V_29 , V_78 , V_264 , V_938 ,
V_979 ) ;
if ( V_266 )
goto V_985;
V_405 -> V_976 = V_264 -> V_968 ;
V_405 -> V_974 = V_264 -> V_938 ;
} else {
V_266 = V_12 -> V_252 . V_986 ( V_10 , V_29 , V_78 , V_264 , V_938 ,
V_979 ) ;
if ( V_266 )
goto V_985;
V_405 -> V_976 = F_667 ( V_938 ) ;
V_405 -> V_974 = V_938 ;
}
V_405 -> V_977 = F_655 ( V_10 , V_28 -> V_4 ) ;
V_405 -> V_972 = true ;
F_250 ( V_405 -> V_930 , V_264 ,
F_192 ( V_4 ) ) ;
F_346 ( V_10 ) ;
F_668 ( V_10 , F_192 ( V_4 ) ) ;
F_55 ( & V_10 -> V_267 ) ;
F_669 ( V_28 -> V_151 , V_264 ) ;
return 0 ;
V_985:
F_184 ( V_264 ) ;
V_984:
F_616 ( & V_28 -> V_403 ) ;
V_29 -> V_77 -> V_78 = V_348 ;
F_193 ( & V_405 -> V_930 -> V_8 ) ;
F_193 ( & V_264 -> V_8 ) ;
F_55 ( & V_10 -> V_267 ) ;
V_454:
F_234 ( & V_10 -> V_353 ) ;
V_28 -> V_354 = NULL ;
F_235 ( & V_10 -> V_353 ) ;
F_90 ( V_29 ) ;
V_982:
F_195 ( V_405 ) ;
if ( V_266 == - V_987 ) {
V_981:
F_277 ( V_29 ) ;
V_266 = F_249 ( V_29 , V_29 -> V_254 , V_29 -> V_255 , V_78 ) ;
if ( V_266 == 0 && V_406 ) {
F_234 ( & V_10 -> V_353 ) ;
F_273 ( V_10 , V_4 , V_406 ) ;
F_235 ( & V_10 -> V_353 ) ;
}
}
return V_266 ;
}
static void F_670 ( struct V_9 * V_10 )
{
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_423 (connector, &dev->mode_config.connector_list,
base.head) {
V_3 -> V_897 =
F_424 ( V_3 -> V_8 . V_6 ) ;
}
F_13 (dev, encoder) {
V_6 -> V_31 =
F_37 ( V_6 -> V_8 . V_29 ) ;
}
F_127 (dev, crtc) {
V_29 -> V_538 = V_29 -> V_8 . V_106 ;
if ( V_29 -> V_538 )
V_29 -> V_450 = & V_29 -> V_79 ;
else
V_29 -> V_450 = NULL ;
}
}
static void F_671 ( struct V_9 * V_10 )
{
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_423 (connector, &dev->mode_config.connector_list,
base.head) {
V_3 -> V_8 . V_6 = & V_3 -> V_897 -> V_8 ;
}
F_13 (dev, encoder) {
V_6 -> V_8 . V_29 = & V_6 -> V_31 -> V_8 ;
}
F_127 (dev, crtc) {
V_29 -> V_8 . V_106 = V_29 -> V_538 ;
}
}
static void
F_672 ( struct V_2 * V_3 ,
struct V_198 * V_199 )
{
int V_773 = V_199 -> V_562 ;
F_140 ( L_158 ,
V_3 -> V_8 . V_8 . V_227 ,
V_3 -> V_8 . V_121 ) ;
if ( V_3 -> V_8 . V_988 . V_437 &&
V_3 -> V_8 . V_988 . V_437 * 3 < V_773 ) {
F_140 ( L_159 ,
V_773 , V_3 -> V_8 . V_988 . V_437 * 3 ) ;
V_199 -> V_562 = V_3 -> V_8 . V_988 . V_437 * 3 ;
}
if ( V_3 -> V_8 . V_988 . V_437 == 0 && V_773 > 24 ) {
F_140 ( L_160 ,
V_773 ) ;
V_199 -> V_562 = 24 ;
}
}
static int
F_673 ( struct V_28 * V_29 ,
struct V_260 * V_78 ,
struct V_198 * V_199 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_2 * V_3 ;
int V_773 ;
switch ( V_78 -> V_304 ) {
case V_284 :
V_773 = 8 * 3 ;
break;
case V_286 :
case V_318 :
if ( F_3 ( F_43 ( V_10 ) -> V_91 > 3 ) )
return - V_272 ;
case V_288 :
V_773 = 6 * 3 ;
break;
case V_292 :
case V_320 :
if ( F_3 ( F_43 ( V_10 ) -> V_91 < 4 ) )
return - V_272 ;
case V_290 :
case V_319 :
V_773 = 8 * 3 ;
break;
case V_294 :
case V_321 :
case V_296 :
case V_322 :
if ( F_3 ( F_43 ( V_10 ) -> V_91 < 4 ) )
return - V_272 ;
V_773 = 10 * 3 ;
break;
default:
F_140 ( L_161 ) ;
return - V_272 ;
}
V_199 -> V_562 = V_773 ;
F_423 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_3 -> V_897 ||
V_3 -> V_897 -> V_31 != V_29 )
continue;
F_672 ( V_3 , V_199 ) ;
}
return V_773 ;
}
static void F_674 ( const struct V_355 * V_442 )
{
F_140 ( L_162
L_163 ,
V_442 -> V_81 ,
V_442 -> V_358 , V_442 -> V_683 ,
V_442 -> V_686 , V_442 -> V_682 ,
V_442 -> V_359 , V_442 -> V_688 ,
V_442 -> V_689 , V_442 -> V_678 , V_442 -> type , V_442 -> V_443 ) ;
}
static void F_675 ( struct V_28 * V_29 ,
struct V_198 * V_199 ,
const char * V_989 )
{
F_140 ( L_164 , V_29 -> V_8 . V_8 . V_227 ,
V_989 , F_68 ( V_29 -> V_4 ) ) ;
F_140 ( L_165 , F_676 ( V_199 -> V_84 ) ) ;
F_140 ( L_166 ,
V_199 -> V_562 , V_199 -> V_698 ) ;
F_140 ( L_167 ,
V_199 -> V_247 ,
V_199 -> V_383 ,
V_199 -> V_477 . V_600 , V_199 -> V_477 . V_601 ,
V_199 -> V_477 . V_602 , V_199 -> V_477 . V_603 ,
V_199 -> V_477 . V_599 ) ;
F_140 ( L_168 ,
V_199 -> V_436 ,
V_199 -> V_619 . V_600 , V_199 -> V_619 . V_601 ,
V_199 -> V_619 . V_602 , V_199 -> V_619 . V_603 ,
V_199 -> V_619 . V_599 ) ;
F_140 ( L_169 ,
V_199 -> V_436 ,
V_199 -> V_620 . V_600 ,
V_199 -> V_620 . V_601 ,
V_199 -> V_620 . V_602 ,
V_199 -> V_620 . V_603 ,
V_199 -> V_620 . V_599 ) ;
F_140 ( L_170 ,
V_199 -> V_990 ,
V_199 -> V_991 ) ;
F_140 ( L_171 ) ;
F_677 ( & V_199 -> V_690 ) ;
F_140 ( L_172 ) ;
F_677 ( & V_199 -> V_80 ) ;
F_674 ( & V_199 -> V_80 ) ;
F_140 ( L_173 , V_199 -> V_643 ) ;
F_140 ( L_174 ,
V_199 -> V_316 , V_199 -> V_315 ) ;
F_140 ( L_175 ,
V_199 -> V_486 . V_487 ,
V_199 -> V_486 . V_491 ,
V_199 -> V_486 . V_719 ) ;
F_140 ( L_176 ,
V_199 -> V_360 . V_458 ,
V_199 -> V_360 . V_301 ,
V_199 -> V_360 . V_106 ? L_177 : L_178 ) ;
F_140 ( L_179 , V_199 -> V_462 ) ;
F_140 ( L_180 , V_199 -> V_248 ) ;
}
static bool F_678 ( const struct V_1 * V_933 ,
const struct V_1 * V_934 )
{
return V_933 == V_934 || ( V_933 -> V_992 & ( 1 << V_934 -> type ) &&
V_934 -> V_992 & ( 1 << V_933 -> type ) ) ;
}
static bool F_679 ( struct V_28 * V_29 ,
struct V_1 * V_6 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_993 ;
F_13 (dev, source_encoder) {
if ( V_993 -> V_31 != V_29 )
continue;
if ( ! F_678 ( V_6 , V_993 ) )
return false ;
}
return true ;
}
static bool F_680 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_6 ;
F_13 (dev, encoder) {
if ( V_6 -> V_31 != V_29 )
continue;
if ( ! F_679 ( V_29 , V_6 ) )
return false ;
}
return true ;
}
static bool F_681 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
unsigned int V_994 = 0 ;
F_423 (connector,
&dev->mode_config.connector_list, base.head) {
struct V_1 * V_6 = V_3 -> V_897 ;
if ( ! V_6 )
continue;
F_3 ( ! V_6 -> V_31 ) ;
switch ( V_6 -> type ) {
unsigned int V_218 ;
case V_500 :
if ( F_3 ( ! F_59 ( V_10 ) ) )
break;
case V_501 :
case V_41 :
case V_361 :
V_218 = 1 << F_383 ( & V_6 -> V_8 ) -> V_94 ;
if ( V_994 & V_218 )
return false ;
V_994 |= V_218 ;
default:
break;
}
}
return true ;
}
static struct V_198 *
F_682 ( struct V_75 * V_29 ,
struct V_260 * V_78 ,
struct V_355 * V_442 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_6 ;
struct V_198 * V_199 ;
int V_995 , V_266 = - V_272 ;
bool V_388 = true ;
if ( ! F_680 ( F_37 ( V_29 ) ) ) {
F_140 ( L_181 ) ;
return F_581 ( - V_272 ) ;
}
if ( ! F_681 ( V_10 ) ) {
F_140 ( L_182 ) ;
return F_581 ( - V_272 ) ;
}
V_199 = F_507 ( sizeof( * V_199 ) , V_453 ) ;
if ( ! V_199 )
return F_581 ( - V_455 ) ;
F_683 ( & V_199 -> V_80 , V_442 ) ;
F_683 ( & V_199 -> V_690 , V_442 ) ;
V_199 -> V_84 =
(enum V_82 ) F_37 ( V_29 ) -> V_4 ;
V_199 -> V_115 = V_448 ;
if ( ! ( V_199 -> V_80 . V_443 &
( V_444 | V_996 ) ) )
V_199 -> V_80 . V_443 |= V_996 ;
if ( ! ( V_199 -> V_80 . V_443 &
( V_446 | V_997 ) ) )
V_199 -> V_80 . V_443 |= V_997 ;
V_995 = F_673 ( F_37 ( V_29 ) ,
V_78 , V_199 ) ;
if ( V_995 < 0 )
goto V_900;
F_684 ( & V_199 -> V_690 , V_998 ) ;
V_199 -> V_316 = V_199 -> V_690 . V_358 ;
V_199 -> V_315 = V_199 -> V_690 . V_359 ;
V_999:
V_199 -> V_643 = 0 ;
V_199 -> V_482 = 1 ;
F_684 ( & V_199 -> V_80 , V_998 ) ;
F_13 (dev, encoder) {
if ( & V_6 -> V_31 -> V_8 != V_29 )
continue;
if ( ! ( V_6 -> V_1000 ( V_6 , V_199 ) ) ) {
F_140 ( L_183 ) ;
goto V_900;
}
}
if ( ! V_199 -> V_643 )
V_199 -> V_643 = V_199 -> V_80 . V_81
* V_199 -> V_482 ;
V_266 = F_439 ( F_37 ( V_29 ) , V_199 ) ;
if ( V_266 < 0 ) {
F_140 ( L_184 ) ;
goto V_900;
}
if ( V_266 == V_564 ) {
if ( F_46 ( ! V_388 , L_185 ) ) {
V_266 = - V_272 ;
goto V_900;
}
F_140 ( L_186 ) ;
V_388 = false ;
goto V_999;
}
V_199 -> V_698 = V_199 -> V_562 != V_995 ;
F_140 ( L_187 ,
V_995 , V_199 -> V_562 , V_199 -> V_698 ) ;
return V_199 ;
V_900:
F_195 ( V_199 ) ;
return F_581 ( V_266 ) ;
}
static void
F_685 ( struct V_75 * V_29 , unsigned * V_1001 ,
unsigned * V_539 , unsigned * V_1002 )
{
struct V_28 * V_28 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
struct V_75 * V_1003 ;
* V_1002 = * V_1001 = * V_539 = 0 ;
F_423 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_8 . V_6 == & V_3 -> V_897 -> V_8 )
continue;
if ( V_3 -> V_8 . V_6 ) {
V_1003 = V_3 -> V_8 . V_6 -> V_29 ;
* V_539 |= 1 << F_37 ( V_1003 ) -> V_4 ;
}
if ( V_3 -> V_897 )
* V_539 |=
1 << V_3 -> V_897 -> V_31 -> V_4 ;
}
F_13 (dev, encoder) {
if ( V_6 -> V_8 . V_29 == & V_6 -> V_31 -> V_8 )
continue;
if ( V_6 -> V_8 . V_29 ) {
V_1003 = V_6 -> V_8 . V_29 ;
* V_539 |= 1 << F_37 ( V_1003 ) -> V_4 ;
}
if ( V_6 -> V_31 )
* V_539 |= 1 << V_6 -> V_31 -> V_4 ;
}
F_127 (dev, intel_crtc) {
if ( V_28 -> V_8 . V_106 == V_28 -> V_538 )
continue;
if ( ! V_28 -> V_538 )
* V_1002 |= 1 << V_28 -> V_4 ;
else
* V_539 |= 1 << V_28 -> V_4 ;
}
V_28 = F_37 ( V_29 ) ;
if ( V_28 -> V_538 )
* V_539 |= 1 << V_28 -> V_4 ;
if ( * V_539 )
* V_1001 = * V_539 ;
* V_1001 &= ~ ( * V_1002 ) ;
* V_539 &= ~ ( * V_1002 ) ;
* V_1001 &= 1 << V_28 -> V_4 ;
* V_539 &= 1 << V_28 -> V_4 ;
F_140 ( L_188 ,
* V_1001 , * V_539 , * V_1002 ) ;
}
static bool F_686 ( struct V_75 * V_29 )
{
struct V_554 * V_6 ;
struct V_9 * V_10 = V_29 -> V_10 ;
F_423 (encoder, &dev->mode_config.encoder_list, head)
if ( V_6 -> V_29 == V_29 )
return true ;
return false ;
}
static void
F_687 ( struct V_9 * V_10 , unsigned V_539 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 ;
struct V_28 * V_28 ;
struct V_550 * V_3 ;
F_316 ( V_12 ) ;
F_13 (dev, intel_encoder) {
if ( ! V_1 -> V_8 . V_29 )
continue;
V_28 = F_37 ( V_1 -> V_8 . V_29 ) ;
if ( V_539 & ( 1 << V_28 -> V_4 ) )
V_1 -> V_549 = false ;
}
F_671 ( V_10 ) ;
F_127 (dev, intel_crtc) {
F_3 ( V_28 -> V_8 . V_106 != F_686 ( & V_28 -> V_8 ) ) ;
F_3 ( V_28 -> V_450 &&
V_28 -> V_450 != & V_28 -> V_79 ) ;
F_3 ( V_28 -> V_8 . V_106 != ! ! V_28 -> V_450 ) ;
}
F_423 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_3 -> V_6 || ! V_3 -> V_6 -> V_29 )
continue;
V_28 = F_37 ( V_3 -> V_6 -> V_29 ) ;
if ( V_539 & ( 1 << V_28 -> V_4 ) ) {
struct V_1004 * V_1005 =
V_10 -> V_891 . V_1005 ;
V_3 -> V_552 = V_555 ;
F_688 ( & V_3 -> V_8 ,
V_1005 ,
V_555 ) ;
V_1 = F_424 ( V_3 -> V_6 ) ;
V_1 -> V_549 = true ;
}
}
}
static bool F_689 ( int V_1006 , int V_1007 )
{
int V_73 ;
if ( V_1006 == V_1007 )
return true ;
if ( ! V_1006 || ! V_1007 )
return false ;
V_73 = abs ( V_1006 - V_1007 ) ;
if ( ( ( ( ( V_73 + V_1006 + V_1007 ) * 100 ) ) / ( V_1006 + V_1007 ) ) < 105 )
return true ;
return false ;
}
static bool
F_690 ( struct V_9 * V_10 ,
struct V_198 * V_1008 ,
struct V_198 * V_199 )
{
#define F_691 ( V_121 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_692 ( V_121 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_693 ( V_121 , T_7 ) \
if ((current_config->name != pipe_config->name) && \
(current_config->alt_name != pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i or %i, found %i)\n", \
current_config->name, \
current_config->alt_name, \
pipe_config->name); \
return false; \
}
#define F_694 ( V_121 , V_505 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
DRM_ERROR("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
return false; \
}
#define F_695 ( V_121 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_696 ( T_8 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_692 ( V_84 ) ;
F_692 ( V_247 ) ;
F_692 ( V_383 ) ;
F_692 ( V_477 . V_600 ) ;
F_692 ( V_477 . V_601 ) ;
F_692 ( V_477 . V_602 ) ;
F_692 ( V_477 . V_603 ) ;
F_692 ( V_477 . V_599 ) ;
F_692 ( V_436 ) ;
if ( F_43 ( V_10 ) -> V_91 < 8 ) {
F_692 ( V_619 . V_600 ) ;
F_692 ( V_619 . V_601 ) ;
F_692 ( V_619 . V_602 ) ;
F_692 ( V_619 . V_603 ) ;
F_692 ( V_619 . V_599 ) ;
if ( V_1008 -> V_618 ) {
F_692 ( V_620 . V_600 ) ;
F_692 ( V_620 . V_601 ) ;
F_692 ( V_620 . V_602 ) ;
F_692 ( V_620 . V_603 ) ;
F_692 ( V_620 . V_599 ) ;
}
} else {
F_693 ( V_619 . V_600 , V_620 . V_600 ) ;
F_693 ( V_619 . V_601 , V_620 . V_601 ) ;
F_693 ( V_619 . V_602 , V_620 . V_602 ) ;
F_693 ( V_619 . V_603 , V_620 . V_603 ) ;
F_693 ( V_619 . V_599 , V_620 . V_599 ) ;
}
F_692 ( V_80 . V_358 ) ;
F_692 ( V_80 . V_682 ) ;
F_692 ( V_80 . V_684 ) ;
F_692 ( V_80 . V_685 ) ;
F_692 ( V_80 . V_683 ) ;
F_692 ( V_80 . V_686 ) ;
F_692 ( V_80 . V_359 ) ;
F_692 ( V_80 . V_678 ) ;
F_692 ( V_80 . V_687 ) ;
F_692 ( V_80 . V_679 ) ;
F_692 ( V_80 . V_688 ) ;
F_692 ( V_80 . V_689 ) ;
F_692 ( V_482 ) ;
F_692 ( V_1009 ) ;
if ( ( F_43 ( V_10 ) -> V_91 < 8 && ! F_212 ( V_10 ) ) ||
F_21 ( V_10 ) )
F_692 ( V_708 ) ;
F_692 ( V_991 ) ;
F_692 ( V_990 ) ;
F_694 ( V_80 . V_443 ,
V_681 ) ;
if ( ! F_696 ( V_1010 ) ) {
F_694 ( V_80 . V_443 ,
V_444 ) ;
F_694 ( V_80 . V_443 ,
V_996 ) ;
F_694 ( V_80 . V_443 ,
V_446 ) ;
F_694 ( V_80 . V_443 ,
V_997 ) ;
}
F_692 ( V_316 ) ;
F_692 ( V_315 ) ;
if ( ! F_696 ( V_1011 ) ) {
F_692 ( V_486 . V_487 ) ;
if ( F_43 ( V_10 ) -> V_91 < 4 )
F_692 ( V_486 . V_491 ) ;
F_692 ( V_486 . V_719 ) ;
}
F_692 ( V_360 . V_106 ) ;
if ( V_1008 -> V_360 . V_106 ) {
F_692 ( V_360 . V_458 ) ;
F_692 ( V_360 . V_301 ) ;
}
if ( F_212 ( V_10 ) )
F_692 ( V_462 ) ;
F_692 ( V_248 ) ;
F_691 ( V_824 ) ;
F_692 ( V_115 ) ;
F_691 ( V_200 . V_56 ) ;
F_691 ( V_200 . V_202 ) ;
F_691 ( V_200 . V_545 ) ;
F_691 ( V_200 . V_546 ) ;
F_691 ( V_200 . V_1012 ) ;
F_691 ( V_200 . V_1013 ) ;
F_691 ( V_200 . V_1014 ) ;
F_691 ( V_200 . V_1015 ) ;
if ( F_18 ( V_10 ) || F_43 ( V_10 ) -> V_91 >= 5 )
F_692 ( V_562 ) ;
F_695 ( V_80 . V_81 ) ;
F_695 ( V_643 ) ;
#undef F_691
#undef F_692
#undef F_693
#undef F_694
#undef F_695
#undef F_696
return true ;
}
static void F_697 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1016 V_1017 , * V_1018 ;
struct V_28 * V_28 ;
int V_151 ;
if ( F_43 ( V_10 ) -> V_91 < 9 )
return;
F_698 ( V_12 , & V_1017 ) ;
V_1018 = & V_12 -> V_1019 . V_1020 . V_1021 ;
F_127 (dev, intel_crtc) {
struct V_1022 * V_1023 , * V_1024 ;
const enum V_4 V_4 = V_28 -> V_4 ;
if ( ! V_28 -> V_76 )
continue;
F_699 (pipe, plane) {
V_1023 = & V_1017 . V_151 [ V_4 ] [ V_151 ] ;
V_1024 = & V_1018 -> V_151 [ V_4 ] [ V_151 ] ;
if ( F_700 ( V_1023 , V_1024 ) )
continue;
F_119 ( L_189
L_190 ,
F_68 ( V_4 ) , V_151 + 1 ,
V_1024 -> V_881 , V_1024 -> V_882 ,
V_1023 -> V_881 , V_1023 -> V_882 ) ;
}
V_1023 = & V_1017 . V_860 [ V_4 ] ;
V_1024 = & V_1018 -> V_860 [ V_4 ] ;
if ( F_700 ( V_1023 , V_1024 ) )
continue;
F_119 ( L_191
L_190 ,
F_68 ( V_4 ) ,
V_1024 -> V_881 , V_1024 -> V_882 ,
V_1023 -> V_881 , V_1023 -> V_882 ) ;
}
}
static void
F_701 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
F_423 (connector, &dev->mode_config.connector_list,
base.head) {
F_428 ( V_3 ) ;
F_46 ( & V_3 -> V_897 -> V_8 != V_3 -> V_8 . V_6 ,
L_192 ) ;
}
}
static void
F_702 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_13 (dev, encoder) {
bool V_106 = false ;
bool V_76 = false ;
enum V_4 V_4 , V_1025 ;
F_140 ( L_193 ,
V_6 -> V_8 . V_8 . V_227 ,
V_6 -> V_8 . V_121 ) ;
F_46 ( & V_6 -> V_31 -> V_8 != V_6 -> V_8 . V_29 ,
L_194 ) ;
F_46 ( V_6 -> V_549 && ! V_6 -> V_8 . V_29 ,
L_195 ) ;
F_423 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_8 . V_6 != & V_6 -> V_8 )
continue;
V_106 = true ;
if ( V_3 -> V_8 . V_552 != V_553 )
V_76 = true ;
}
if ( ! V_106 && V_6 -> V_8 . V_1026 == V_1027 )
continue;
F_46 ( ! ! V_6 -> V_8 . V_29 != V_106 ,
L_196
L_197 ,
! ! V_6 -> V_8 . V_29 , V_106 ) ;
F_46 ( V_76 && ! V_6 -> V_8 . V_29 ,
L_198 ) ;
F_46 ( V_6 -> V_549 != V_76 ,
L_199
L_197 , V_76 , V_6 -> V_549 ) ;
V_76 = V_6 -> V_120 ( V_6 , & V_4 ) ;
F_46 ( V_76 != V_6 -> V_549 ,
L_200
L_197 ,
V_6 -> V_549 , V_76 ) ;
if ( ! V_6 -> V_8 . V_29 )
continue;
V_1025 = F_37 ( V_6 -> V_8 . V_29 ) -> V_4 ;
F_46 ( V_76 && V_4 != V_1025 ,
L_201
L_197 ,
V_1025 , V_4 ) ;
}
}
static void
F_703 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_198 V_199 ;
F_127 (dev, crtc) {
bool V_106 = false ;
bool V_76 = false ;
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
F_140 ( L_202 ,
V_29 -> V_8 . V_8 . V_227 ) ;
F_46 ( V_29 -> V_76 && ! V_29 -> V_8 . V_106 ,
L_203 ) ;
F_13 (dev, encoder) {
if ( V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
V_106 = true ;
if ( V_6 -> V_549 )
V_76 = true ;
}
F_46 ( V_76 != V_29 -> V_76 ,
L_204
L_197 , V_76 , V_29 -> V_76 ) ;
F_46 ( V_106 != V_29 -> V_8 . V_106 ,
L_205
L_197 , V_106 , V_29 -> V_8 . V_106 ) ;
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
F_46 ( V_29 -> V_76 != V_76 ,
L_206
L_197 , V_29 -> V_76 , V_76 ) ;
if ( V_76 &&
! F_690 ( V_10 , & V_29 -> V_79 , & V_199 ) ) {
F_46 ( 1 , L_207 ) ;
F_675 ( V_29 , & V_199 ,
L_208 ) ;
F_675 ( V_29 , & V_29 -> V_79 ,
L_209 ) ;
}
}
}
static void
F_704 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_29 ;
struct V_118 V_200 ;
int V_153 ;
for ( V_153 = 0 ; V_153 < V_12 -> V_451 ; V_153 ++ ) {
struct V_114 * V_117 = & V_12 -> V_116 [ V_153 ] ;
int V_1030 = 0 , V_1031 = 0 ;
bool V_76 ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
F_140 ( L_210 , V_117 -> V_121 ) ;
V_76 = V_117 -> V_120 ( V_12 , V_117 , & V_200 ) ;
F_46 ( V_117 -> V_76 > F_705 ( V_117 -> V_79 . V_224 ) ,
L_211 ,
V_117 -> V_76 , F_705 ( V_117 -> V_79 . V_224 ) ) ;
F_46 ( V_117 -> V_76 && ! V_117 -> V_225 ,
L_212 ) ;
F_46 ( V_117 -> V_225 && ! V_117 -> V_76 ,
L_213 ) ;
F_46 ( V_117 -> V_225 != V_76 ,
L_214 ,
V_117 -> V_225 , V_76 ) ;
F_127 (dev, crtc) {
if ( V_29 -> V_8 . V_106 && F_56 ( V_29 ) == V_117 )
V_1030 ++ ;
if ( V_29 -> V_76 && F_56 ( V_29 ) == V_117 )
V_1031 ++ ;
}
F_46 ( V_117 -> V_76 != V_1031 ,
L_215 ,
V_117 -> V_76 , V_1031 ) ;
F_46 ( F_705 ( V_117 -> V_79 . V_224 ) != V_1030 ,
L_216 ,
F_705 ( V_117 -> V_79 . V_224 ) , V_1030 ) ;
F_46 ( V_117 -> V_225 && memcmp ( & V_117 -> V_79 . V_119 , & V_200 ,
sizeof( V_200 ) ) ,
L_217 ) ;
}
}
void
F_430 ( struct V_9 * V_10 )
{
F_697 ( V_10 ) ;
F_701 ( V_10 ) ;
F_702 ( V_10 ) ;
F_703 ( V_10 ) ;
F_704 ( V_10 ) ;
}
void F_706 ( const struct V_198 * V_199 ,
int V_1032 )
{
F_46 ( ! F_689 ( V_199 -> V_80 . V_81 , V_1032 ) ,
L_218 ,
V_199 -> V_80 . V_81 , V_1032 ) ;
}
static void F_707 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
if ( F_22 ( V_10 ) ) {
const struct V_355 * V_442 = & V_29 -> V_79 . V_80 ;
int V_694 ;
V_694 = V_442 -> V_678 ;
if ( V_442 -> V_443 & V_681 )
V_694 /= 2 ;
V_29 -> V_1033 = V_694 - 1 ;
} else if ( F_59 ( V_10 ) &&
F_10 ( V_29 , V_41 ) ) {
V_29 -> V_1033 = 2 ;
} else
V_29 -> V_1033 = 1 ;
}
static struct V_198 *
F_708 ( struct V_75 * V_29 ,
struct V_355 * V_442 ,
struct V_260 * V_78 ,
unsigned * V_1001 ,
unsigned * V_539 ,
unsigned * V_1002 )
{
struct V_198 * V_199 = NULL ;
F_685 ( V_29 , V_1001 ,
V_539 , V_1002 ) ;
if ( ( * V_1001 ) == 0 )
goto V_927;
V_199 = F_682 ( V_29 , V_78 , V_442 ) ;
if ( F_594 ( V_199 ) ) {
goto V_927;
}
F_675 ( F_37 ( V_29 ) , V_199 ,
L_219 ) ;
V_927:
return V_199 ;
}
static int F_709 ( struct V_75 * V_29 ,
struct V_355 * V_442 ,
int V_254 , int V_255 , struct V_260 * V_78 ,
struct V_198 * V_199 ,
unsigned V_1001 ,
unsigned V_539 ,
unsigned V_1002 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_355 * V_1034 ;
struct V_28 * V_28 ;
int V_266 = 0 ;
V_1034 = F_710 ( sizeof( * V_1034 ) , V_453 ) ;
if ( ! V_1034 )
return - V_455 ;
* V_1034 = V_29 -> V_442 ;
if ( V_1001 )
F_37 ( V_29 ) -> V_450 = V_199 ;
if ( F_21 ( V_10 ) ) {
F_403 ( V_10 , & V_539 ) ;
V_539 &= ~ V_1002 ;
}
if ( V_12 -> V_252 . V_1035 ) {
unsigned V_452 = V_1001 | V_1002 ;
V_266 = F_314 ( V_12 , V_452 ) ;
if ( V_266 )
goto V_1036;
F_711 (dev, modeset_pipes, intel_crtc) {
V_266 = V_12 -> V_252 . V_1035 ( V_28 ) ;
if ( V_266 ) {
F_317 ( V_12 ) ;
goto V_1036;
}
}
}
F_711 (dev, disable_pipes, intel_crtc)
F_422 ( & V_28 -> V_8 ) ;
F_711 (dev, prepare_pipes, intel_crtc) {
if ( V_28 -> V_8 . V_106 )
V_12 -> V_252 . V_345 ( & V_28 -> V_8 ) ;
}
if ( V_1001 ) {
V_29 -> V_442 = * V_442 ;
F_37 ( V_29 ) -> V_79 = * V_199 ;
F_37 ( V_29 ) -> V_450 = & F_37 ( V_29 ) -> V_79 ;
F_712 ( V_29 ,
& V_199 -> V_80 ) ;
}
F_687 ( V_10 , V_539 ) ;
F_388 ( V_10 ) ;
F_711 (dev, modeset_pipes, intel_crtc) {
struct V_260 * V_348 = V_29 -> V_77 -> V_78 ;
struct V_263 * V_362 = F_174 ( V_348 ) ;
struct V_263 * V_264 = F_174 ( V_78 ) ;
F_53 ( & V_10 -> V_267 ) ;
V_266 = F_173 ( V_29 -> V_77 , V_78 , NULL ) ;
if ( V_266 != 0 ) {
F_119 ( L_57 ) ;
F_55 ( & V_10 -> V_267 ) ;
goto V_1036;
}
if ( V_348 )
F_184 ( V_362 ) ;
F_250 ( V_362 , V_264 ,
F_192 ( V_28 -> V_4 ) ) ;
F_55 ( & V_10 -> V_267 ) ;
V_29 -> V_77 -> V_78 = V_78 ;
V_29 -> V_254 = V_254 ;
V_29 -> V_255 = V_255 ;
}
F_711 (dev, prepare_pipes, intel_crtc) {
F_707 ( V_28 ) ;
V_12 -> V_252 . V_548 ( & V_28 -> V_8 ) ;
}
V_1036:
if ( V_266 && V_29 -> V_106 )
V_29 -> V_442 = * V_1034 ;
F_195 ( V_199 ) ;
F_195 ( V_1034 ) ;
return V_266 ;
}
static int F_713 ( struct V_75 * V_29 ,
struct V_355 * V_442 ,
int V_254 , int V_255 , struct V_260 * V_78 ,
struct V_198 * V_199 ,
unsigned V_1001 ,
unsigned V_539 ,
unsigned V_1002 )
{
int V_266 ;
V_266 = F_709 ( V_29 , V_442 , V_254 , V_255 , V_78 , V_199 , V_1001 ,
V_539 , V_1002 ) ;
if ( V_266 == 0 )
F_430 ( V_29 -> V_10 ) ;
return V_266 ;
}
static int F_595 ( struct V_75 * V_29 ,
struct V_355 * V_442 ,
int V_254 , int V_255 , struct V_260 * V_78 )
{
struct V_198 * V_199 ;
unsigned V_1001 , V_539 , V_1002 ;
V_199 = F_708 ( V_29 , V_442 , V_78 ,
& V_1001 ,
& V_539 ,
& V_1002 ) ;
if ( F_594 ( V_199 ) )
return F_714 ( V_199 ) ;
return F_713 ( V_29 , V_442 , V_254 , V_255 , V_78 , V_199 ,
V_1001 , V_539 ,
V_1002 ) ;
}
void F_715 ( struct V_75 * V_29 )
{
F_595 ( V_29 , & V_29 -> V_442 , V_29 -> V_254 , V_29 -> V_255 , V_29 -> V_77 -> V_78 ) ;
}
static void F_716 ( struct V_1037 * V_79 )
{
if ( ! V_79 )
return;
F_195 ( V_79 -> V_1038 ) ;
F_195 ( V_79 -> V_1039 ) ;
F_195 ( V_79 -> V_1040 ) ;
F_195 ( V_79 ) ;
}
static int F_717 ( struct V_9 * V_10 ,
struct V_1037 * V_79 )
{
struct V_75 * V_29 ;
struct V_554 * V_6 ;
struct V_550 * V_3 ;
int V_206 ;
V_79 -> V_1040 =
F_718 ( V_10 -> V_891 . V_1041 ,
sizeof( bool ) , V_453 ) ;
if ( ! V_79 -> V_1040 )
return - V_455 ;
V_79 -> V_1039 =
F_718 ( V_10 -> V_891 . V_1042 ,
sizeof( struct V_75 * ) , V_453 ) ;
if ( ! V_79 -> V_1039 )
return - V_455 ;
V_79 -> V_1038 =
F_718 ( V_10 -> V_891 . V_1043 ,
sizeof( struct V_554 * ) , V_453 ) ;
if ( ! V_79 -> V_1038 )
return - V_455 ;
V_206 = 0 ;
F_196 (dev, crtc) {
V_79 -> V_1040 [ V_206 ++ ] = V_29 -> V_106 ;
}
V_206 = 0 ;
F_423 (encoder, &dev->mode_config.encoder_list, head) {
V_79 -> V_1039 [ V_206 ++ ] = V_6 -> V_29 ;
}
V_206 = 0 ;
F_423 (connector, &dev->mode_config.connector_list, head) {
V_79 -> V_1038 [ V_206 ++ ] = V_3 -> V_6 ;
}
return 0 ;
}
static void F_719 ( struct V_9 * V_10 ,
struct V_1037 * V_79 )
{
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
int V_206 ;
V_206 = 0 ;
F_127 (dev, crtc) {
V_29 -> V_538 = V_79 -> V_1040 [ V_206 ++ ] ;
if ( V_29 -> V_538 )
V_29 -> V_450 = & V_29 -> V_79 ;
else
V_29 -> V_450 = NULL ;
}
V_206 = 0 ;
F_13 (dev, encoder) {
V_6 -> V_31 =
F_37 ( V_79 -> V_1039 [ V_206 ++ ] ) ;
}
V_206 = 0 ;
F_423 (connector, &dev->mode_config.connector_list, base.head) {
V_3 -> V_897 =
F_424 ( V_79 -> V_1038 [ V_206 ++ ] ) ;
}
}
static bool
F_720 ( struct V_1044 * V_1045 )
{
int V_153 ;
if ( V_1045 -> V_608 == 0 )
return false ;
if ( F_3 ( V_1045 -> V_1046 == NULL ) )
return false ;
for ( V_153 = 0 ; V_153 < V_1045 -> V_608 ; V_153 ++ )
if ( V_1045 -> V_1046 [ V_153 ] -> V_6 &&
V_1045 -> V_1046 [ V_153 ] -> V_6 -> V_29 == V_1045 -> V_29 &&
V_1045 -> V_1046 [ V_153 ] -> V_552 != V_555 )
return true ;
return false ;
}
static void
F_721 ( struct V_1044 * V_1045 ,
struct V_1037 * V_79 )
{
if ( F_720 ( V_1045 ) ) {
V_79 -> V_1047 = true ;
} else if ( V_1045 -> V_29 -> V_77 -> V_78 != V_1045 -> V_78 ) {
if ( V_1045 -> V_29 -> V_77 -> V_78 == NULL ) {
struct V_28 * V_28 =
F_37 ( V_1045 -> V_29 ) ;
if ( V_28 -> V_76 ) {
F_140 ( L_220 ) ;
V_79 -> V_1048 = true ;
} else {
F_140 ( L_221 ) ;
V_79 -> V_1047 = true ;
}
} else if ( V_1045 -> V_78 == NULL ) {
V_79 -> V_1047 = true ;
} else if ( V_1045 -> V_78 -> V_304 !=
V_1045 -> V_29 -> V_77 -> V_78 -> V_304 ) {
V_79 -> V_1047 = true ;
} else {
V_79 -> V_1048 = true ;
}
}
if ( V_1045 -> V_78 && ( V_1045 -> V_254 != V_1045 -> V_29 -> V_254 || V_1045 -> V_255 != V_1045 -> V_29 -> V_255 ) )
V_79 -> V_1048 = true ;
if ( V_1045 -> V_442 && ! F_722 ( V_1045 -> V_442 , & V_1045 -> V_29 -> V_442 ) ) {
F_140 ( L_222 ) ;
F_677 ( & V_1045 -> V_29 -> V_442 ) ;
F_677 ( V_1045 -> V_442 ) ;
V_79 -> V_1047 = true ;
}
F_140 ( L_223 ,
V_1045 -> V_29 -> V_8 . V_227 , V_79 -> V_1047 , V_79 -> V_1048 ) ;
}
static int
F_723 ( struct V_9 * V_10 ,
struct V_1044 * V_1045 ,
struct V_1037 * V_79 )
{
struct V_2 * V_3 ;
struct V_1 * V_6 ;
struct V_28 * V_29 ;
int V_1049 ;
F_3 ( ! V_1045 -> V_78 && ( V_1045 -> V_608 != 0 ) ) ;
F_3 ( V_1045 -> V_78 && ( V_1045 -> V_608 == 0 ) ) ;
F_423 (connector, &dev->mode_config.connector_list,
base.head) {
for ( V_1049 = 0 ; V_1049 < V_1045 -> V_608 ; V_1049 ++ ) {
if ( V_1045 -> V_1046 [ V_1049 ] == & V_3 -> V_8 ) {
V_3 -> V_897 = F_1 ( V_3 , F_37 ( V_1045 -> V_29 ) -> V_4 ) ;
break;
}
}
if ( ( ! V_1045 -> V_78 || V_1049 == V_1045 -> V_608 ) &&
V_3 -> V_8 . V_6 &&
V_3 -> V_8 . V_6 -> V_29 == V_1045 -> V_29 ) {
V_3 -> V_897 = NULL ;
F_140 ( L_224 ,
V_3 -> V_8 . V_8 . V_227 ,
V_3 -> V_8 . V_121 ) ;
}
if ( & V_3 -> V_897 -> V_8 != V_3 -> V_8 . V_6 ) {
F_140 ( L_225 ) ;
V_79 -> V_1047 = true ;
}
}
F_423 (connector, &dev->mode_config.connector_list,
base.head) {
struct V_75 * V_31 ;
if ( ! V_3 -> V_897 )
continue;
V_31 = V_3 -> V_897 -> V_8 . V_29 ;
for ( V_1049 = 0 ; V_1049 < V_1045 -> V_608 ; V_1049 ++ ) {
if ( V_1045 -> V_1046 [ V_1049 ] == & V_3 -> V_8 )
V_31 = V_1045 -> V_29 ;
}
if ( ! F_724 ( & V_3 -> V_897 -> V_8 ,
V_31 ) ) {
return - V_272 ;
}
V_3 -> V_897 -> V_31 = F_37 ( V_31 ) ;
F_140 ( L_226 ,
V_3 -> V_8 . V_8 . V_227 ,
V_3 -> V_8 . V_121 ,
V_31 -> V_8 . V_227 ) ;
}
F_13 (dev, encoder) {
int V_608 = 0 ;
F_423 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_897 == V_6 ) {
F_3 ( ! V_3 -> V_897 -> V_31 ) ;
V_608 ++ ;
}
}
if ( V_608 == 0 )
V_6 -> V_31 = NULL ;
else if ( V_608 > 1 )
return - V_272 ;
if ( & V_6 -> V_31 -> V_8 != V_6 -> V_8 . V_29 ) {
F_140 ( L_227 ) ;
V_79 -> V_1047 = true ;
}
}
F_423 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_897 )
if ( V_3 -> V_897 != V_3 -> V_6 )
V_3 -> V_6 = V_3 -> V_897 ;
}
F_127 (dev, crtc) {
V_29 -> V_538 = false ;
F_13 (dev, encoder) {
if ( V_6 -> V_31 == V_29 ) {
V_29 -> V_538 = true ;
break;
}
}
if ( V_29 -> V_538 != V_29 -> V_8 . V_106 ) {
F_140 ( L_228 ,
V_29 -> V_538 ? L_229 : L_230 ) ;
V_79 -> V_1047 = true ;
}
if ( V_29 -> V_538 )
V_29 -> V_450 = & V_29 -> V_79 ;
else
V_29 -> V_450 = NULL ;
}
return 0 ;
}
static void F_725 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
F_140 ( L_231 ,
F_68 ( V_29 -> V_4 ) ) ;
F_423 (connector, &dev->mode_config.connector_list, base.head) {
if ( V_3 -> V_897 &&
V_3 -> V_897 -> V_31 == V_29 )
V_3 -> V_897 = NULL ;
}
F_13 (dev, encoder) {
if ( V_6 -> V_31 == V_29 )
V_6 -> V_31 = NULL ;
}
V_29 -> V_538 = false ;
V_29 -> V_450 = NULL ;
}
static int F_726 ( struct V_1044 * V_1045 )
{
struct V_9 * V_10 ;
struct V_1044 V_1050 ;
struct V_1037 * V_79 ;
struct V_198 * V_199 ;
unsigned V_1001 , V_539 , V_1002 ;
int V_266 ;
F_114 ( ! V_1045 ) ;
F_114 ( ! V_1045 -> V_29 ) ;
F_114 ( ! V_1045 -> V_29 -> V_1051 ) ;
F_114 ( ! V_1045 -> V_442 && V_1045 -> V_78 ) ;
F_114 ( V_1045 -> V_78 && V_1045 -> V_608 == 0 ) ;
if ( V_1045 -> V_78 ) {
F_140 ( L_232 ,
V_1045 -> V_29 -> V_8 . V_227 , V_1045 -> V_78 -> V_8 . V_227 ,
( int ) V_1045 -> V_608 , V_1045 -> V_254 , V_1045 -> V_255 ) ;
} else {
F_140 ( L_233 , V_1045 -> V_29 -> V_8 . V_227 ) ;
}
V_10 = V_1045 -> V_29 -> V_10 ;
V_266 = - V_455 ;
V_79 = F_507 ( sizeof( * V_79 ) , V_453 ) ;
if ( ! V_79 )
goto V_1052;
V_266 = F_717 ( V_10 , V_79 ) ;
if ( V_266 )
goto V_1052;
V_1050 . V_29 = V_1045 -> V_29 ;
V_1050 . V_442 = & V_1045 -> V_29 -> V_442 ;
V_1050 . V_254 = V_1045 -> V_29 -> V_254 ;
V_1050 . V_255 = V_1045 -> V_29 -> V_255 ;
V_1050 . V_78 = V_1045 -> V_29 -> V_77 -> V_78 ;
F_721 ( V_1045 , V_79 ) ;
V_266 = F_723 ( V_10 , V_1045 , V_79 ) ;
if ( V_266 )
goto V_900;
V_199 = F_708 ( V_1045 -> V_29 , V_1045 -> V_442 ,
V_1045 -> V_78 ,
& V_1001 ,
& V_539 ,
& V_1002 ) ;
if ( F_594 ( V_199 ) ) {
V_266 = F_714 ( V_199 ) ;
goto V_900;
} else if ( V_199 ) {
if ( V_199 -> V_990 !=
F_37 ( V_1045 -> V_29 ) -> V_79 . V_990 )
V_79 -> V_1047 = true ;
}
if ( ! V_79 -> V_1047 )
F_195 ( V_199 ) ;
F_244 ( F_37 ( V_1045 -> V_29 ) ) ;
if ( V_79 -> V_1047 ) {
V_266 = F_713 ( V_1045 -> V_29 , V_1045 -> V_442 ,
V_1045 -> V_254 , V_1045 -> V_255 , V_1045 -> V_78 , V_199 ,
V_1001 , V_539 ,
V_1002 ) ;
} else if ( V_79 -> V_1048 ) {
struct V_28 * V_28 = F_37 ( V_1045 -> V_29 ) ;
F_277 ( V_1045 -> V_29 ) ;
V_266 = F_249 ( V_1045 -> V_29 ,
V_1045 -> V_254 , V_1045 -> V_255 , V_1045 -> V_78 ) ;
if ( ! V_28 -> V_251 && V_266 == 0 ) {
F_3 ( ! V_28 -> V_76 ) ;
F_164 ( V_1045 -> V_29 -> V_77 , V_1045 -> V_29 ) ;
}
if ( V_356 . V_357 && V_266 == 0 )
F_430 ( V_1045 -> V_29 -> V_10 ) ;
}
if ( V_266 ) {
F_140 ( L_234 ,
V_1045 -> V_29 -> V_8 . V_227 , V_266 ) ;
V_900:
F_719 ( V_10 , V_79 ) ;
if ( F_37 ( V_1050 . V_29 ) -> V_538 && ! V_1050 . V_78 )
F_725 ( F_37 ( V_1050 . V_29 ) ) ;
if ( V_79 -> V_1047 &&
F_595 ( V_1050 . V_29 , V_1050 . V_442 ,
V_1050 . V_254 , V_1050 . V_255 , V_1050 . V_78 ) )
F_119 ( L_235 ) ;
}
V_1052:
F_716 ( V_79 ) ;
return V_266 ;
}
static bool F_727 ( struct V_11 * V_12 ,
struct V_114 * V_117 ,
struct V_118 * V_119 )
{
T_4 V_108 ;
if ( ! F_74 ( V_12 , V_228 ) )
return false ;
V_108 = F_5 ( F_728 ( V_117 -> V_227 ) ) ;
V_119 -> V_56 = V_108 ;
V_119 -> V_545 = F_5 ( F_729 ( V_117 -> V_227 ) ) ;
V_119 -> V_546 = F_5 ( F_730 ( V_117 -> V_227 ) ) ;
return V_108 & V_110 ;
}
static void F_731 ( struct V_11 * V_12 ,
struct V_114 * V_117 )
{
F_116 ( F_729 ( V_117 -> V_227 ) , V_117 -> V_79 . V_119 . V_545 ) ;
F_116 ( F_730 ( V_117 -> V_227 ) , V_117 -> V_79 . V_119 . V_546 ) ;
}
static void F_732 ( struct V_11 * V_12 ,
struct V_114 * V_117 )
{
F_91 ( V_12 ) ;
F_116 ( F_728 ( V_117 -> V_227 ) , V_117 -> V_79 . V_119 . V_56 ) ;
F_117 ( F_728 ( V_117 -> V_227 ) ) ;
F_118 ( 150 ) ;
F_116 ( F_728 ( V_117 -> V_227 ) , V_117 -> V_79 . V_119 . V_56 ) ;
F_117 ( F_728 ( V_117 -> V_227 ) ) ;
F_118 ( 200 ) ;
}
static void F_733 ( struct V_11 * V_12 ,
struct V_114 * V_117 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_28 * V_29 ;
F_127 (dev, crtc) {
if ( F_56 ( V_29 ) == V_117 )
F_93 ( V_12 , V_29 -> V_4 ) ;
}
F_116 ( F_728 ( V_117 -> V_227 ) , 0 ) ;
F_117 ( F_728 ( V_117 -> V_227 ) ) ;
F_118 ( 200 ) ;
}
static void F_734 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_153 ;
V_12 -> V_451 = 2 ;
for ( V_153 = 0 ; V_153 < V_12 -> V_451 ; V_153 ++ ) {
V_12 -> V_116 [ V_153 ] . V_227 = V_153 ;
V_12 -> V_116 [ V_153 ] . V_121 = V_1053 [ V_153 ] ;
V_12 -> V_116 [ V_153 ] . V_226 = F_731 ;
V_12 -> V_116 [ V_153 ] . V_229 = F_732 ;
V_12 -> V_116 [ V_153 ] . V_230 = F_733 ;
V_12 -> V_116 [ V_153 ] . V_120 =
F_727 ;
}
}
static void F_735 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_59 ( V_10 ) )
F_736 ( V_10 ) ;
else if ( F_48 ( V_10 ) || F_92 ( V_10 ) )
F_734 ( V_10 ) ;
else
V_12 -> V_451 = 0 ;
F_114 ( V_12 -> V_451 > V_1054 ) ;
}
static int
F_737 ( struct V_250 * V_151 )
{
struct V_9 * V_10 = V_151 -> V_10 ;
struct V_28 * V_28 ;
if ( ! V_151 -> V_78 )
return 0 ;
F_114 ( ! V_151 -> V_29 ) ;
V_28 = F_37 ( V_151 -> V_29 ) ;
if ( ! V_28 -> V_251 )
goto V_1055;
F_277 ( V_151 -> V_29 ) ;
F_168 ( V_151 , V_151 -> V_29 ) ;
V_1055:
F_53 ( & V_10 -> V_267 ) ;
F_250 ( F_174 ( V_151 -> V_78 ) , NULL ,
F_192 ( V_28 -> V_4 ) ) ;
F_184 ( F_174 ( V_151 -> V_78 ) ) ;
F_55 ( & V_10 -> V_267 ) ;
V_151 -> V_78 = NULL ;
return 0 ;
}
static int
F_738 ( struct V_250 * V_151 ,
struct V_1056 * V_107 )
{
struct V_75 * V_29 = V_107 -> V_29 ;
struct V_260 * V_78 = V_107 -> V_78 ;
struct V_1057 * V_1058 = & V_107 -> V_1059 ;
struct V_1057 * V_1060 = & V_107 -> V_1060 ;
const struct V_1057 * V_1061 = & V_107 -> V_1061 ;
return F_739 ( V_151 , V_29 , V_78 ,
V_1060 , V_1058 , V_1061 ,
V_1062 ,
V_1062 ,
false , true , & V_107 -> V_1063 ) ;
}
static int
F_740 ( struct V_250 * V_151 ,
struct V_1056 * V_107 )
{
struct V_75 * V_29 = V_107 -> V_29 ;
struct V_260 * V_78 = V_107 -> V_78 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
struct V_263 * V_264 = F_174 ( V_78 ) ;
struct V_263 * V_362 = F_174 ( V_151 -> V_78 ) ;
int V_266 ;
F_277 ( V_29 ) ;
if ( F_241 ( V_29 ) ) {
F_119 ( L_54 ) ;
return - V_363 ;
}
if ( V_362 != V_264 ) {
F_53 ( & V_10 -> V_267 ) ;
V_266 = F_173 ( V_151 , V_78 , NULL ) ;
if ( V_266 == 0 )
F_250 ( V_362 , V_264 ,
F_192 ( V_4 ) ) ;
F_55 ( & V_10 -> V_267 ) ;
if ( V_266 != 0 ) {
F_140 ( L_57 ) ;
return V_266 ;
}
}
return 0 ;
}
static void
F_741 ( struct V_250 * V_151 ,
struct V_1056 * V_107 )
{
struct V_75 * V_29 = V_107 -> V_29 ;
struct V_260 * V_78 = V_107 -> V_78 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
enum V_4 V_4 = V_28 -> V_4 ;
struct V_260 * V_348 = V_151 -> V_78 ;
struct V_263 * V_264 = F_174 ( V_78 ) ;
struct V_263 * V_362 = F_174 ( V_151 -> V_78 ) ;
struct V_461 * V_461 = F_206 ( V_151 ) ;
struct V_1057 * V_1060 = & V_107 -> V_1060 ;
V_29 -> V_77 -> V_78 = V_78 ;
V_29 -> V_254 = V_1060 -> V_1064 >> 16 ;
V_29 -> V_255 = V_1060 -> y1 >> 16 ;
V_461 -> V_1065 = V_107 -> V_1066 . V_1064 ;
V_461 -> V_1067 = V_107 -> V_1066 . y1 ;
V_461 -> V_1068 = F_742 ( & V_107 -> V_1066 ) ;
V_461 -> V_1069 = F_743 ( & V_107 -> V_1066 ) ;
V_461 -> V_1070 = V_107 -> V_1071 . V_1064 ;
V_461 -> V_1072 = V_107 -> V_1071 . y1 ;
V_461 -> V_1073 = F_742 ( & V_107 -> V_1071 ) ;
V_461 -> V_1074 = F_743 ( & V_107 -> V_1071 ) ;
V_461 -> V_264 = V_264 ;
if ( V_28 -> V_76 ) {
if ( V_28 -> V_251 &&
F_43 ( V_10 ) -> V_91 <= 4 && ! F_18 ( V_10 ) &&
V_12 -> V_476 . V_151 == V_28 -> V_151 &&
V_461 -> V_326 != F_207 ( V_1075 ) ) {
F_346 ( V_10 ) ;
}
if ( V_107 -> V_1063 ) {
bool V_1076 = V_28 -> V_251 ;
F_244 ( V_28 ) ;
V_28 -> V_251 = true ;
V_12 -> V_252 . V_253 ( V_29 , V_151 -> V_78 ,
V_29 -> V_254 , V_29 -> V_255 ) ;
if ( F_166 ( V_10 ) && ! V_1076 )
F_167 ( V_10 , V_28 -> V_4 ) ;
} else {
F_168 ( V_151 , V_29 ) ;
}
F_251 ( V_10 , F_192 ( V_4 ) ) ;
F_53 ( & V_10 -> V_267 ) ;
F_252 ( V_10 ) ;
F_55 ( & V_10 -> V_267 ) ;
}
if ( V_348 && V_348 != V_78 ) {
if ( V_28 -> V_76 )
F_167 ( V_10 , V_28 -> V_4 ) ;
F_53 ( & V_10 -> V_267 ) ;
F_184 ( V_362 ) ;
F_55 ( & V_10 -> V_267 ) ;
}
}
static int
F_744 ( struct V_250 * V_151 , struct V_75 * V_29 ,
struct V_260 * V_78 , int V_1065 , int V_1067 ,
unsigned int V_1068 , unsigned int V_1069 ,
T_4 V_1070 , T_4 V_1072 ,
T_4 V_1073 , T_4 V_1074 )
{
struct V_1056 V_107 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
int V_266 ;
V_107 . V_29 = V_29 ;
V_107 . V_78 = V_78 ;
V_107 . V_1060 . V_1064 = V_1070 ;
V_107 . V_1060 . V_1077 = V_1070 + V_1073 ;
V_107 . V_1060 . y1 = V_1072 ;
V_107 . V_1060 . V_1078 = V_1072 + V_1074 ;
V_107 . V_1059 . V_1064 = V_1065 ;
V_107 . V_1059 . V_1077 = V_1065 + V_1068 ;
V_107 . V_1059 . y1 = V_1067 ;
V_107 . V_1059 . V_1078 = V_1067 + V_1069 ;
V_107 . V_1061 . V_1064 = 0 ;
V_107 . V_1061 . y1 = 0 ;
V_107 . V_1061 . V_1077 = V_28 -> V_76 ? V_28 -> V_79 . V_316 : 0 ;
V_107 . V_1061 . V_1078 = V_28 -> V_76 ? V_28 -> V_79 . V_315 : 0 ;
V_107 . V_1071 = V_107 . V_1060 ;
V_107 . V_1066 = V_107 . V_1059 ;
V_266 = F_738 ( V_151 , & V_107 ) ;
if ( V_266 )
return V_266 ;
V_266 = F_740 ( V_151 , & V_107 ) ;
if ( V_266 )
return V_266 ;
F_741 ( V_151 , & V_107 ) ;
return 0 ;
}
static void F_745 ( struct V_250 * V_151 )
{
struct V_461 * V_461 = F_206 ( V_151 ) ;
F_746 ( V_151 ) ;
F_195 ( V_461 ) ;
}
static struct V_250 * F_747 ( struct V_9 * V_10 ,
int V_4 )
{
struct V_461 * V_77 ;
const T_4 * V_1079 ;
int V_1080 ;
V_77 = F_507 ( sizeof( * V_77 ) , V_453 ) ;
if ( V_77 == NULL )
return NULL ;
V_77 -> V_1081 = false ;
V_77 -> V_1082 = 1 ;
V_77 -> V_4 = V_4 ;
V_77 -> V_151 = V_4 ;
V_77 -> V_326 = F_207 ( V_1075 ) ;
if ( F_748 ( V_10 ) && F_43 ( V_10 ) -> V_91 < 4 )
V_77 -> V_151 = ! V_4 ;
if ( F_43 ( V_10 ) -> V_91 <= 3 ) {
V_1079 = V_1083 ;
V_1080 = F_266 ( V_1083 ) ;
} else {
V_1079 = V_1084 ;
V_1080 = F_266 ( V_1084 ) ;
}
F_749 ( V_10 , & V_77 -> V_8 , 0 ,
& V_1085 ,
V_1079 , V_1080 ,
V_1086 ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
if ( ! V_10 -> V_891 . V_1087 )
V_10 -> V_891 . V_1087 =
F_750 ( V_10 ,
F_207 ( V_1075 ) |
F_207 ( V_327 ) ) ;
if ( V_10 -> V_891 . V_1087 )
F_751 ( & V_77 -> V_8 . V_8 ,
V_10 -> V_891 . V_1087 ,
V_77 -> V_326 ) ;
}
return & V_77 -> V_8 ;
}
static int
F_752 ( struct V_250 * V_151 )
{
if ( ! V_151 -> V_78 )
return 0 ;
F_114 ( ! V_151 -> V_29 ) ;
return F_575 ( V_151 -> V_29 , NULL , 0 , 0 ) ;
}
static int
F_753 ( struct V_250 * V_151 ,
struct V_1056 * V_107 )
{
struct V_75 * V_29 = V_107 -> V_29 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_260 * V_78 = V_107 -> V_78 ;
struct V_1057 * V_1058 = & V_107 -> V_1059 ;
struct V_1057 * V_1060 = & V_107 -> V_1060 ;
const struct V_1057 * V_1061 = & V_107 -> V_1061 ;
struct V_263 * V_264 = F_174 ( V_78 ) ;
int V_1068 , V_1069 ;
unsigned V_302 ;
int V_266 ;
V_266 = F_739 ( V_151 , V_29 , V_78 ,
V_1060 , V_1058 , V_1061 ,
V_1062 ,
V_1062 ,
true , true , & V_107 -> V_1063 ) ;
if ( V_266 )
return V_266 ;
if ( ! V_264 )
return 0 ;
V_1068 = F_742 ( & V_107 -> V_1066 ) ;
V_1069 = F_743 ( & V_107 -> V_1066 ) ;
if ( ! F_574 ( V_10 , V_1068 , V_1069 ) ) {
F_754 ( L_236 ) ;
return - V_272 ;
}
V_302 = F_569 ( V_1068 ) * 4 ;
if ( V_264 -> V_8 . V_301 < V_302 * V_1069 ) {
F_140 ( L_237 ) ;
return - V_455 ;
}
if ( V_78 == V_29 -> V_860 -> V_78 )
return 0 ;
F_53 ( & V_10 -> V_267 ) ;
if ( ! F_43 ( V_10 ) -> V_871 && V_264 -> V_268 ) {
F_140 ( L_238 ) ;
V_266 = - V_272 ;
}
F_55 ( & V_10 -> V_267 ) ;
return V_266 ;
}
static int
F_755 ( struct V_250 * V_151 ,
struct V_1056 * V_107 )
{
struct V_75 * V_29 = V_107 -> V_29 ;
struct V_260 * V_78 = V_107 -> V_78 ;
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_461 * V_461 = F_206 ( V_151 ) ;
struct V_330 * V_331 = F_191 ( V_78 ) ;
struct V_263 * V_264 = V_331 -> V_264 ;
int V_1068 , V_1069 ;
V_29 -> V_862 = V_107 -> V_1066 . V_1064 ;
V_29 -> V_863 = V_107 -> V_1066 . y1 ;
V_461 -> V_1065 = V_107 -> V_1066 . V_1064 ;
V_461 -> V_1067 = V_107 -> V_1066 . y1 ;
V_461 -> V_1068 = F_742 ( & V_107 -> V_1066 ) ;
V_461 -> V_1069 = F_743 ( & V_107 -> V_1066 ) ;
V_461 -> V_1070 = V_107 -> V_1071 . V_1064 ;
V_461 -> V_1072 = V_107 -> V_1071 . y1 ;
V_461 -> V_1073 = F_742 ( & V_107 -> V_1071 ) ;
V_461 -> V_1074 = F_743 ( & V_107 -> V_1071 ) ;
V_461 -> V_264 = V_264 ;
if ( V_78 != V_29 -> V_860 -> V_78 ) {
V_1068 = F_742 ( & V_107 -> V_1066 ) ;
V_1069 = F_743 ( & V_107 -> V_1066 ) ;
return F_575 ( V_29 , V_264 , V_1068 , V_1069 ) ;
} else {
F_343 ( V_29 , V_107 -> V_1063 ) ;
F_251 ( V_29 -> V_10 ,
F_578 ( V_28 -> V_4 ) ) ;
return 0 ;
}
}
static int
F_756 ( struct V_250 * V_151 , struct V_75 * V_29 ,
struct V_260 * V_78 , int V_1065 , int V_1067 ,
unsigned int V_1068 , unsigned int V_1069 ,
T_4 V_1070 , T_4 V_1072 ,
T_4 V_1073 , T_4 V_1074 )
{
struct V_28 * V_28 = F_37 ( V_29 ) ;
struct V_1056 V_107 ;
int V_266 ;
V_107 . V_29 = V_29 ;
V_107 . V_78 = V_78 ;
V_107 . V_1060 . V_1064 = V_1070 ;
V_107 . V_1060 . V_1077 = V_1070 + V_1073 ;
V_107 . V_1060 . y1 = V_1072 ;
V_107 . V_1060 . V_1078 = V_1072 + V_1074 ;
V_107 . V_1059 . V_1064 = V_1065 ;
V_107 . V_1059 . V_1077 = V_1065 + V_1068 ;
V_107 . V_1059 . y1 = V_1067 ;
V_107 . V_1059 . V_1078 = V_1067 + V_1069 ;
V_107 . V_1061 . V_1064 = 0 ;
V_107 . V_1061 . y1 = 0 ;
V_107 . V_1061 . V_1077 = V_28 -> V_76 ? V_28 -> V_79 . V_316 : 0 ;
V_107 . V_1061 . V_1078 = V_28 -> V_76 ? V_28 -> V_79 . V_315 : 0 ;
V_107 . V_1071 = V_107 . V_1060 ;
V_107 . V_1066 = V_107 . V_1059 ;
V_266 = F_753 ( V_151 , & V_107 ) ;
if ( V_266 )
return V_266 ;
return F_755 ( V_151 , & V_107 ) ;
}
static struct V_250 * F_757 ( struct V_9 * V_10 ,
int V_4 )
{
struct V_461 * V_860 ;
V_860 = F_507 ( sizeof( * V_860 ) , V_453 ) ;
if ( V_860 == NULL )
return NULL ;
V_860 -> V_1081 = false ;
V_860 -> V_1082 = 1 ;
V_860 -> V_4 = V_4 ;
V_860 -> V_151 = V_4 ;
V_860 -> V_326 = F_207 ( V_1075 ) ;
F_749 ( V_10 , & V_860 -> V_8 , 0 ,
& V_1088 ,
V_1089 ,
F_266 ( V_1089 ) ,
V_1090 ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
if ( ! V_10 -> V_891 . V_1087 )
V_10 -> V_891 . V_1087 =
F_750 ( V_10 ,
F_207 ( V_1075 ) |
F_207 ( V_327 ) ) ;
if ( V_10 -> V_891 . V_1087 )
F_751 ( & V_860 -> V_8 . V_8 ,
V_10 -> V_891 . V_1087 ,
V_860 -> V_326 ) ;
}
return & V_860 -> V_8 ;
}
static void F_758 ( struct V_9 * V_10 , int V_4 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_28 * V_28 ;
struct V_250 * V_77 = NULL ;
struct V_250 * V_860 = NULL ;
int V_153 , V_266 ;
V_28 = F_507 ( sizeof( * V_28 ) , V_453 ) ;
if ( V_28 == NULL )
return;
V_77 = F_747 ( V_10 , V_4 ) ;
if ( ! V_77 )
goto V_900;
V_860 = F_757 ( V_10 , V_4 ) ;
if ( ! V_860 )
goto V_900;
V_266 = F_759 ( V_10 , & V_28 -> V_8 , V_77 ,
V_860 , & V_1091 ) ;
if ( V_266 )
goto V_900;
F_760 ( & V_28 -> V_8 , 256 ) ;
for ( V_153 = 0 ; V_153 < 256 ; V_153 ++ ) {
V_28 -> V_472 [ V_153 ] = V_153 ;
V_28 -> V_473 [ V_153 ] = V_153 ;
V_28 -> V_474 [ V_153 ] = V_153 ;
}
V_28 -> V_4 = V_4 ;
V_28 -> V_151 = V_4 ;
if ( F_748 ( V_10 ) && F_43 ( V_10 ) -> V_91 < 4 ) {
F_140 ( L_239 ) ;
V_28 -> V_151 = ! V_4 ;
}
V_28 -> V_851 = ~ 0 ;
V_28 -> V_850 = ~ 0 ;
V_28 -> V_852 = ~ 0 ;
F_114 ( V_4 >= F_266 ( V_12 -> V_932 ) ||
V_12 -> V_932 [ V_28 -> V_151 ] != NULL ) ;
V_12 -> V_932 [ V_28 -> V_151 ] = & V_28 -> V_8 ;
V_12 -> V_83 [ V_28 -> V_4 ] = & V_28 -> V_8 ;
F_663 ( & V_28 -> V_966 . V_405 , F_647 ) ;
F_761 ( & V_28 -> V_8 , & V_1092 ) ;
F_3 ( F_762 ( & V_28 -> V_8 ) != V_28 -> V_4 ) ;
return;
V_900:
if ( V_77 )
F_746 ( V_77 ) ;
if ( V_860 )
F_746 ( V_860 ) ;
F_195 ( V_28 ) ;
}
enum V_4 F_763 ( struct V_2 * V_3 )
{
struct V_554 * V_6 = V_3 -> V_8 . V_6 ;
struct V_9 * V_10 = V_3 -> V_8 . V_10 ;
F_3 ( ! F_764 ( & V_10 -> V_891 . V_892 ) ) ;
if ( ! V_6 || F_3 ( ! V_6 -> V_29 ) )
return V_1093 ;
return F_37 ( V_6 -> V_29 ) -> V_4 ;
}
int F_765 ( struct V_9 * V_10 , void * V_1094 ,
struct V_1095 * V_1096 )
{
struct V_1097 * V_1098 = V_1094 ;
struct V_75 * V_1099 ;
struct V_28 * V_29 ;
if ( ! F_766 ( V_10 , V_1100 ) )
return - V_955 ;
V_1099 = F_767 ( V_10 , V_1098 -> V_1101 ) ;
if ( ! V_1099 ) {
F_119 ( L_240 ) ;
return - V_1102 ;
}
V_29 = F_37 ( V_1099 ) ;
V_1098 -> V_4 = V_29 -> V_4 ;
return 0 ;
}
static int F_768 ( struct V_1 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_8 . V_10 ;
struct V_1 * V_993 ;
int V_1103 = 0 ;
int V_1104 = 0 ;
F_13 (dev, source_encoder) {
if ( F_678 ( V_6 , V_993 ) )
V_1103 |= ( 1 << V_1104 ) ;
V_1104 ++ ;
}
return V_1103 ;
}
static bool F_769 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_115 ( V_10 ) )
return false ;
if ( ( F_5 ( V_1105 ) & V_1106 ) == 0 )
return false ;
if ( F_7 ( V_10 ) && ( F_5 ( V_1107 ) & V_1108 ) )
return false ;
return true ;
}
const char * F_770 ( int V_1109 )
{
static const char * V_1110 [] = {
[ V_1111 ] = L_241 ,
[ V_42 ] = L_242 ,
[ V_53 ] = L_243 ,
[ V_44 ] = L_244 ,
[ V_33 ] = L_245 ,
[ V_1112 ] = L_246 ,
[ V_41 ] = L_247 ,
[ V_501 ] = L_248 ,
[ V_361 ] = L_249 ,
[ V_246 ] = L_250 ,
[ V_500 ] = L_251 ,
} ;
if ( V_1109 < 0 || V_1109 >= F_266 ( V_1110 ) || ! V_1110 [ V_1109 ] )
return L_252 ;
return V_1110 [ V_1109 ] ;
}
static bool F_771 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_43 ( V_10 ) -> V_91 >= 9 )
return false ;
if ( F_772 ( V_10 ) || F_773 ( V_10 ) )
return false ;
if ( F_20 ( V_10 ) )
return false ;
if ( F_21 ( V_10 ) && ! V_12 -> V_605 . V_1113 )
return false ;
return true ;
}
static void F_774 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
bool V_1114 = false ;
F_775 ( V_10 ) ;
if ( F_771 ( V_10 ) )
F_776 ( V_10 ) ;
if ( F_59 ( V_10 ) ) {
int V_69 ;
V_69 = F_5 ( V_1115 ) & V_1116 ;
if ( V_69 )
F_777 ( V_10 , V_493 ) ;
V_69 = F_5 ( V_1117 ) ;
if ( V_69 & V_1118 )
F_777 ( V_10 , V_96 ) ;
if ( V_69 & V_1119 )
F_777 ( V_10 , V_98 ) ;
if ( V_69 & V_1120 )
F_777 ( V_10 , V_100 ) ;
} else if ( F_4 ( V_10 ) ) {
int V_69 ;
V_1114 = F_778 ( V_10 , V_100 ) ;
if ( F_769 ( V_10 ) )
F_779 ( V_10 , V_1105 , V_493 ) ;
if ( F_5 ( V_191 ) & V_1121 ) {
V_69 = F_780 ( V_10 , V_1122 , true ) ;
if ( ! V_69 )
F_781 ( V_10 , V_191 , V_96 ) ;
if ( ! V_69 && ( F_5 ( V_184 ) & V_1106 ) )
F_779 ( V_10 , V_184 , V_96 ) ;
}
if ( F_5 ( V_192 ) & V_1121 )
F_781 ( V_10 , V_192 , V_98 ) ;
if ( ! V_1114 && F_5 ( V_193 ) & V_1121 )
F_781 ( V_10 , V_193 , V_100 ) ;
if ( F_5 ( V_186 ) & V_1106 )
F_779 ( V_10 , V_186 , V_98 ) ;
if ( F_5 ( V_188 ) & V_1106 )
F_779 ( V_10 , V_188 , V_100 ) ;
} else if ( F_21 ( V_10 ) ) {
if ( F_5 ( V_1123 + V_1124 ) & V_1121 )
F_781 ( V_10 , V_1123 + V_1124 ,
V_96 ) ;
if ( F_5 ( V_1123 + V_1125 ) & V_1106 ||
F_778 ( V_10 , V_96 ) )
F_779 ( V_10 , V_1123 + V_1125 , V_96 ) ;
if ( F_5 ( V_1123 + V_1126 ) & V_1121 )
F_781 ( V_10 , V_1123 + V_1126 ,
V_98 ) ;
if ( F_5 ( V_1123 + V_1127 ) & V_1106 ||
F_778 ( V_10 , V_98 ) )
F_779 ( V_10 , V_1123 + V_1127 , V_98 ) ;
if ( F_20 ( V_10 ) ) {
if ( F_5 ( V_1123 + V_1128 ) & V_1121 )
F_781 ( V_10 , V_1123 + V_1128 ,
V_100 ) ;
if ( F_5 ( V_1123 + V_1129 ) & V_1106 )
F_779 ( V_10 , V_1123 + V_1129 , V_100 ) ;
}
F_782 ( V_10 ) ;
} else if ( F_783 ( V_10 ) ) {
bool V_69 = false ;
if ( F_5 ( V_1130 ) & V_1121 ) {
F_140 ( L_253 ) ;
V_69 = F_780 ( V_10 , V_1130 , true ) ;
if ( ! V_69 && F_784 ( V_10 ) ) {
F_140 ( L_254 ) ;
F_781 ( V_10 , V_1124 , V_96 ) ;
}
if ( ! V_69 && F_785 ( V_10 ) )
F_779 ( V_10 , V_1125 , V_96 ) ;
}
if ( F_5 ( V_1130 ) & V_1121 ) {
F_140 ( L_255 ) ;
V_69 = F_780 ( V_10 , V_1131 , false ) ;
}
if ( ! V_69 && ( F_5 ( V_1131 ) & V_1121 ) ) {
if ( F_784 ( V_10 ) ) {
F_140 ( L_256 ) ;
F_781 ( V_10 , V_1126 , V_98 ) ;
}
if ( F_785 ( V_10 ) )
F_779 ( V_10 , V_1127 , V_98 ) ;
}
if ( F_785 ( V_10 ) &&
( F_5 ( V_1129 ) & V_1106 ) )
F_779 ( V_10 , V_1129 , V_100 ) ;
} else if ( F_22 ( V_10 ) )
F_786 ( V_10 ) ;
if ( F_787 ( V_10 ) )
F_788 ( V_10 ) ;
F_789 ( V_10 ) ;
F_13 (dev, encoder) {
V_6 -> V_8 . V_896 = V_6 -> V_224 ;
V_6 -> V_8 . V_1132 =
F_768 ( V_6 ) ;
}
F_519 ( V_10 ) ;
F_790 ( V_10 ) ;
}
static void F_791 ( struct V_260 * V_78 )
{
struct V_9 * V_10 = V_78 -> V_10 ;
struct V_330 * V_331 = F_191 ( V_78 ) ;
F_792 ( V_78 ) ;
F_53 ( & V_10 -> V_267 ) ;
F_3 ( ! V_331 -> V_264 -> V_1133 -- ) ;
F_193 ( & V_331 -> V_264 -> V_8 ) ;
F_55 ( & V_10 -> V_267 ) ;
F_195 ( V_331 ) ;
}
static int F_793 ( struct V_260 * V_78 ,
struct V_1095 * V_1096 ,
unsigned int * V_1134 )
{
struct V_330 * V_331 = F_191 ( V_78 ) ;
struct V_263 * V_264 = V_331 -> V_264 ;
return F_794 ( V_1096 , & V_264 -> V_8 , V_1134 ) ;
}
static int F_190 ( struct V_9 * V_10 ,
struct V_330 * V_331 ,
struct V_299 * V_300 ,
struct V_263 * V_264 )
{
int V_722 ;
int V_1135 ;
int V_266 ;
F_3 ( ! F_175 ( & V_10 -> V_267 ) ) ;
if ( V_264 -> V_268 == V_271 ) {
F_754 ( L_257 ) ;
return - V_272 ;
}
if ( V_300 -> V_303 [ 0 ] & 63 ) {
F_754 ( L_258 ,
V_300 -> V_303 [ 0 ] ) ;
return - V_272 ;
}
if ( F_43 ( V_10 ) -> V_91 >= 5 && ! F_21 ( V_10 ) ) {
V_1135 = 32 * 1024 ;
} else if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
if ( V_264 -> V_268 )
V_1135 = 16 * 1024 ;
else
V_1135 = 32 * 1024 ;
} else if ( F_43 ( V_10 ) -> V_91 >= 3 ) {
if ( V_264 -> V_268 )
V_1135 = 8 * 1024 ;
else
V_1135 = 16 * 1024 ;
} else
V_1135 = 8 * 1024 ;
if ( V_300 -> V_303 [ 0 ] > V_1135 ) {
F_754 ( L_259 ,
V_264 -> V_268 ? L_260 : L_261 ,
V_300 -> V_303 [ 0 ] , V_1135 ) ;
return - V_272 ;
}
if ( V_264 -> V_268 != V_269 &&
V_300 -> V_303 [ 0 ] != V_264 -> V_302 ) {
F_754 ( L_262 ,
V_300 -> V_303 [ 0 ] , V_264 -> V_302 ) ;
return - V_272 ;
}
switch ( V_300 -> V_304 ) {
case V_284 :
case V_288 :
case V_290 :
case V_319 :
break;
case V_286 :
case V_318 :
if ( F_43 ( V_10 ) -> V_91 > 3 ) {
F_754 ( L_263 ,
F_795 ( V_300 -> V_304 ) ) ;
return - V_272 ;
}
break;
case V_292 :
case V_320 :
case V_294 :
case V_321 :
case V_296 :
case V_322 :
if ( F_43 ( V_10 ) -> V_91 < 4 ) {
F_754 ( L_263 ,
F_795 ( V_300 -> V_304 ) ) ;
return - V_272 ;
}
break;
case V_1136 :
case V_1137 :
case V_1138 :
case V_1139 :
if ( F_43 ( V_10 ) -> V_91 < 5 ) {
F_754 ( L_263 ,
F_795 ( V_300 -> V_304 ) ) ;
return - V_272 ;
}
break;
default:
F_754 ( L_263 ,
F_795 ( V_300 -> V_304 ) ) ;
return - V_272 ;
}
if ( V_300 -> V_980 [ 0 ] != 0 )
return - V_272 ;
V_722 = F_171 ( V_10 , V_300 -> V_257 ,
V_264 -> V_268 ) ;
if ( V_264 -> V_8 . V_301 < V_722 * V_300 -> V_303 [ 0 ] )
return - V_272 ;
F_796 ( & V_331 -> V_8 , V_300 ) ;
V_331 -> V_264 = V_264 ;
V_331 -> V_264 -> V_1133 ++ ;
V_266 = F_797 ( V_10 , & V_331 -> V_8 , & V_1140 ) ;
if ( V_266 ) {
F_119 ( L_264 , V_266 ) ;
return V_266 ;
}
return 0 ;
}
static struct V_260 *
F_798 ( struct V_9 * V_10 ,
struct V_1095 * V_1141 ,
struct V_299 * V_300 )
{
struct V_263 * V_264 ;
V_264 = F_799 ( F_800 ( V_10 , V_1141 ,
V_300 -> V_1142 [ 0 ] ) ) ;
if ( & V_264 -> V_8 == NULL )
return F_581 ( - V_1102 ) ;
return F_582 ( V_10 , V_300 , V_264 ) ;
}
static inline void F_801 ( struct V_9 * V_10 )
{
}
static void F_802 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_4 ( V_10 ) || F_18 ( V_10 ) )
V_12 -> V_252 . V_714 = F_32 ;
else if ( F_20 ( V_10 ) )
V_12 -> V_252 . V_714 = F_35 ;
else if ( F_21 ( V_10 ) )
V_12 -> V_252 . V_714 = F_33 ;
else if ( F_19 ( V_10 ) )
V_12 -> V_252 . V_714 = F_31 ;
else
V_12 -> V_252 . V_714 = F_30 ;
if ( F_59 ( V_10 ) ) {
V_12 -> V_252 . V_1028 = F_567 ;
V_12 -> V_252 . V_1143 = F_547 ;
V_12 -> V_252 . V_1035 =
F_560 ;
V_12 -> V_252 . V_548 = F_359 ;
V_12 -> V_252 . V_345 = F_373 ;
V_12 -> V_252 . V_551 = F_377 ;
if ( F_43 ( V_10 ) -> V_91 >= 9 )
V_12 -> V_252 . V_253 =
F_214 ;
else
V_12 -> V_252 . V_253 =
F_211 ;
} else if ( F_4 ( V_10 ) ) {
V_12 -> V_252 . V_1028 = F_548 ;
V_12 -> V_252 . V_1143 = F_547 ;
V_12 -> V_252 . V_1035 =
F_538 ;
V_12 -> V_252 . V_548 = F_347 ;
V_12 -> V_252 . V_345 = F_371 ;
V_12 -> V_252 . V_551 = F_377 ;
V_12 -> V_252 . V_253 =
F_211 ;
} else if ( F_21 ( V_10 ) ) {
V_12 -> V_252 . V_1028 = F_510 ;
V_12 -> V_252 . V_1143 = F_506 ;
V_12 -> V_252 . V_1035 = F_503 ;
V_12 -> V_252 . V_548 = F_405 ;
V_12 -> V_252 . V_345 = F_417 ;
V_12 -> V_252 . V_551 = F_419 ;
V_12 -> V_252 . V_253 =
F_199 ;
} else {
V_12 -> V_252 . V_1028 = F_510 ;
V_12 -> V_252 . V_1143 = F_506 ;
V_12 -> V_252 . V_1035 = F_503 ;
V_12 -> V_252 . V_548 = F_415 ;
V_12 -> V_252 . V_345 = F_417 ;
V_12 -> V_252 . V_551 = F_419 ;
V_12 -> V_252 . V_253 =
F_199 ;
}
if ( F_21 ( V_10 ) )
V_12 -> V_252 . V_517 =
F_441 ;
else if ( F_496 ( V_10 ) || ( F_498 ( V_10 ) && ! F_803 ( V_10 ) ) )
V_12 -> V_252 . V_517 =
F_442 ;
else if ( F_440 ( V_10 ) )
V_12 -> V_252 . V_517 =
F_443 ;
else if ( F_497 ( V_10 ) || F_70 ( V_10 ) )
V_12 -> V_252 . V_517 =
F_444 ;
else if ( F_19 ( V_10 ) )
V_12 -> V_252 . V_517 =
F_445 ;
else if ( F_804 ( V_10 ) )
V_12 -> V_252 . V_517 =
F_447 ;
else if ( F_71 ( V_10 ) )
V_12 -> V_252 . V_517 =
F_448 ;
else if ( F_805 ( V_10 ) )
V_12 -> V_252 . V_517 =
F_449 ;
else
V_12 -> V_252 . V_517 =
F_450 ;
if ( F_7 ( V_10 ) ) {
V_12 -> V_252 . V_432 = F_257 ;
} else if ( F_264 ( V_10 ) ) {
V_12 -> V_252 . V_432 = F_262 ;
} else if ( F_254 ( V_10 ) ) {
V_12 -> V_252 . V_432 = F_265 ;
V_12 -> V_252 . V_510 =
F_256 ;
} else if ( F_212 ( V_10 ) || F_166 ( V_10 ) ) {
V_12 -> V_252 . V_432 = V_1144 ;
} else if ( F_21 ( V_10 ) ) {
V_12 -> V_252 . V_510 =
F_404 ;
}
V_12 -> V_252 . V_986 = F_652 ;
switch ( F_43 ( V_10 ) -> V_91 ) {
case 2 :
V_12 -> V_252 . V_986 = F_629 ;
break;
case 3 :
V_12 -> V_252 . V_986 = F_634 ;
break;
case 4 :
case 5 :
V_12 -> V_252 . V_986 = F_635 ;
break;
case 6 :
V_12 -> V_252 . V_986 = F_636 ;
break;
case 7 :
case 8 :
V_12 -> V_252 . V_986 = F_637 ;
break;
case 9 :
V_12 -> V_252 . V_986 = F_651 ;
break;
}
F_806 ( V_10 ) ;
F_807 ( & V_12 -> V_1145 ) ;
}
static void F_808 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_147 |= V_148 ;
F_809 ( L_265 ) ;
}
static void F_810 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_147 |= V_149 ;
F_809 ( L_266 ) ;
}
static void F_811 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_147 |= V_607 ;
F_809 ( L_267 ) ;
}
static void F_812 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_147 |= V_1146 ;
F_809 ( L_268 ) ;
}
static void F_813 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_147 |= V_1147 ;
F_809 ( L_269 ) ;
}
static int F_814 ( const struct V_1148 * V_227 )
{
F_809 ( L_270 , V_227 -> V_1149 ) ;
return 1 ;
}
static void F_815 ( struct V_9 * V_10 )
{
struct V_1150 * V_1151 = V_10 -> V_570 ;
int V_153 ;
for ( V_153 = 0 ; V_153 < F_266 ( V_1152 ) ; V_153 ++ ) {
struct V_1153 * V_1154 = & V_1152 [ V_153 ] ;
if ( V_1151 -> V_1155 == V_1154 -> V_1155 &&
( V_1151 -> V_1156 == V_1154 -> V_1156 ||
V_1154 -> V_1156 == V_1157 ) &&
( V_1151 -> V_1158 == V_1154 -> V_1158 ||
V_1154 -> V_1158 == V_1157 ) )
V_1154 -> V_1159 ( V_10 ) ;
}
for ( V_153 = 0 ; V_153 < F_266 ( V_1160 ) ; V_153 ++ ) {
if ( F_816 ( * V_1160 [ V_153 ] . V_1161 ) != 0 )
V_1160 [ V_153 ] . V_1159 ( V_10 ) ;
}
}
static void F_817 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_9 V_1162 ;
T_1 V_1163 = F_818 ( V_10 ) ;
F_819 ( V_10 -> V_570 , V_1164 ) ;
F_820 ( V_1165 , V_1166 ) ;
V_1162 = F_821 ( V_1167 ) ;
F_820 ( V_1162 | 1 << 5 , V_1167 ) ;
F_822 ( V_10 -> V_570 , V_1164 ) ;
F_118 ( 300 ) ;
F_116 ( V_1163 , V_1168 ) ;
F_117 ( V_1163 ) ;
}
void F_233 ( struct V_9 * V_10 )
{
F_559 ( V_10 ) ;
if ( F_21 ( V_10 ) )
F_392 ( V_10 ) ;
F_823 ( V_10 ) ;
F_824 ( V_10 ) ;
}
void F_825 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_157 , V_266 ;
enum V_4 V_4 ;
struct V_28 * V_29 ;
F_826 ( V_10 ) ;
V_10 -> V_891 . V_1169 = 0 ;
V_10 -> V_891 . V_1170 = 0 ;
V_10 -> V_891 . V_1171 = 24 ;
V_10 -> V_891 . V_1172 = 1 ;
V_10 -> V_891 . V_816 = & V_1173 ;
F_815 ( V_10 ) ;
F_827 ( V_10 ) ;
if ( F_43 ( V_10 ) -> V_364 == 0 )
return;
F_802 ( V_10 ) ;
F_828 ( V_10 ) ;
if ( F_22 ( V_10 ) ) {
V_10 -> V_891 . V_1174 = 2048 ;
V_10 -> V_891 . V_1175 = 2048 ;
} else if ( F_829 ( V_10 ) ) {
V_10 -> V_891 . V_1174 = 4096 ;
V_10 -> V_891 . V_1175 = 4096 ;
} else {
V_10 -> V_891 . V_1174 = 8192 ;
V_10 -> V_891 . V_1175 = 8192 ;
}
if ( F_70 ( V_10 ) || F_71 ( V_10 ) ) {
V_10 -> V_891 . V_846 = F_70 ( V_10 ) ? 64 : 512 ;
V_10 -> V_891 . V_847 = 1023 ;
} else if ( F_22 ( V_10 ) ) {
V_10 -> V_891 . V_846 = V_1176 ;
V_10 -> V_891 . V_847 = V_1177 ;
} else {
V_10 -> V_891 . V_846 = V_1178 ;
V_10 -> V_891 . V_847 = V_1179 ;
}
V_10 -> V_891 . V_1180 = V_12 -> V_1181 . V_1182 ;
F_140 ( L_271 ,
F_43 ( V_10 ) -> V_364 ,
F_43 ( V_10 ) -> V_364 > 1 ? L_272 : L_273 ) ;
F_80 (dev_priv, pipe) {
F_758 ( V_10 , V_4 ) ;
F_82 (pipe, sprite) {
V_266 = F_830 ( V_10 , V_4 , V_157 ) ;
if ( V_266 )
F_140 ( L_274 ,
F_68 ( V_4 ) , F_85 ( V_4 , V_157 ) , V_266 ) ;
}
}
F_110 ( V_10 ) ;
F_735 ( V_10 ) ;
F_817 ( V_10 ) ;
F_774 ( V_10 ) ;
F_346 ( V_10 ) ;
F_229 ( V_10 ) ;
F_236 ( V_10 , false ) ;
F_238 ( V_10 ) ;
F_127 (dev, crtc) {
if ( ! V_29 -> V_76 )
continue;
if ( V_12 -> V_252 . V_1143 ) {
V_12 -> V_252 . V_1143 ( V_29 ,
& V_29 -> V_298 ) ;
F_194 ( V_29 , & V_29 -> V_298 ) ;
}
}
}
static void F_831 ( struct V_9 * V_10 )
{
struct V_2 * V_3 ;
struct V_550 * V_1183 = NULL ;
struct V_885 V_895 ;
struct V_887 * V_888 = V_10 -> V_891 . V_1184 ;
F_423 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_6 -> type == V_42 ) {
V_1183 = & V_3 -> V_8 ;
break;
}
}
if ( ! V_1183 )
return;
if ( F_591 ( V_1183 , NULL , & V_895 , V_888 ) )
F_597 ( V_1183 , & V_895 ) ;
}
static bool
F_832 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_85 , V_108 ;
if ( F_43 ( V_10 ) -> V_364 == 1 )
return true ;
V_85 = F_77 ( ! V_29 -> V_151 ) ;
V_108 = F_5 ( V_85 ) ;
if ( ( V_108 & V_152 ) &&
( ! ! ( V_108 & V_155 ) == V_29 -> V_4 ) )
return false ;
return true ;
}
static void F_833 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_8 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_85 ;
V_85 = F_44 ( V_29 -> V_79 . V_84 ) ;
F_116 ( V_85 , F_5 ( V_85 ) & ~ V_1185 ) ;
if ( V_29 -> V_76 ) {
F_707 ( V_29 ) ;
F_834 ( V_10 , V_29 -> V_4 ) ;
} else
F_835 ( V_10 , V_29 -> V_4 ) ;
if ( F_43 ( V_10 ) -> V_91 < 4 && ! F_832 ( V_29 ) ) {
struct V_2 * V_3 ;
bool V_151 ;
F_140 ( L_275 ,
V_29 -> V_8 . V_8 . V_227 ) ;
V_151 = V_29 -> V_151 ;
V_29 -> V_151 = ! V_151 ;
V_29 -> V_251 = true ;
V_12 -> V_252 . V_345 ( & V_29 -> V_8 ) ;
V_29 -> V_151 = V_151 ;
F_423 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_6 -> V_8 . V_29 != & V_29 -> V_8 )
continue;
V_3 -> V_8 . V_552 = V_553 ;
V_3 -> V_8 . V_6 = NULL ;
}
F_423 (connector, &dev->mode_config.connector_list,
base.head)
if ( V_3 -> V_6 -> V_8 . V_29 == & V_29 -> V_8 ) {
V_3 -> V_6 -> V_8 . V_29 = NULL ;
V_3 -> V_6 -> V_549 = false ;
}
F_3 ( V_29 -> V_76 ) ;
V_29 -> V_8 . V_106 = false ;
}
if ( V_12 -> V_147 & V_148 &&
V_29 -> V_4 == V_129 && ! V_29 -> V_76 ) {
F_831 ( V_10 ) ;
}
F_421 ( & V_29 -> V_8 ) ;
if ( V_29 -> V_76 != V_29 -> V_8 . V_106 ) {
struct V_1 * V_6 ;
F_140 ( L_276 ,
V_29 -> V_8 . V_8 . V_227 ,
V_29 -> V_8 . V_106 ? L_177 : L_178 ,
V_29 -> V_76 ? L_177 : L_178 ) ;
V_29 -> V_8 . V_106 = V_29 -> V_76 ;
F_3 ( V_29 -> V_76 ) ;
F_11 (dev, &crtc->base, encoder) {
F_3 ( V_6 -> V_549 ) ;
V_6 -> V_8 . V_29 = NULL ;
}
}
if ( V_29 -> V_76 || F_337 ( V_10 ) ) {
V_29 -> V_1186 = true ;
V_29 -> V_1187 = true ;
}
}
static void F_836 ( struct V_1 * V_6 )
{
struct V_2 * V_3 ;
struct V_9 * V_10 = V_6 -> V_8 . V_10 ;
bool V_1188 = V_6 -> V_8 . V_29 &&
F_37 ( V_6 -> V_8 . V_29 ) -> V_76 ;
if ( V_6 -> V_549 && ! V_1188 ) {
F_140 ( L_277 ,
V_6 -> V_8 . V_8 . V_227 ,
V_6 -> V_8 . V_121 ) ;
if ( V_6 -> V_8 . V_29 ) {
F_140 ( L_278 ,
V_6 -> V_8 . V_8 . V_227 ,
V_6 -> V_8 . V_121 ) ;
V_6 -> V_230 ( V_6 ) ;
if ( V_6 -> V_484 )
V_6 -> V_484 ( V_6 ) ;
}
V_6 -> V_8 . V_29 = NULL ;
V_6 -> V_549 = false ;
F_423 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_6 != V_6 )
continue;
V_3 -> V_8 . V_552 = V_553 ;
V_3 -> V_8 . V_6 = NULL ;
}
}
}
void F_837 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_1163 = F_818 ( V_10 ) ;
if ( ! ( F_5 ( V_1163 ) & V_1168 ) ) {
F_140 ( L_279 ) ;
F_817 ( V_10 ) ;
}
}
void F_838 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( ! F_74 ( V_12 , V_1189 ) )
return;
F_837 ( V_10 ) ;
}
static bool F_839 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = V_29 -> V_8 . V_10 -> V_13 ;
if ( ! V_29 -> V_76 )
return false ;
return F_5 ( F_77 ( V_29 -> V_151 ) ) & V_152 ;
}
static void F_840 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
int V_153 ;
F_127 (dev, crtc) {
memset ( & V_29 -> V_79 , 0 , sizeof( V_29 -> V_79 ) ) ;
V_29 -> V_79 . V_147 |= V_1011 ;
V_29 -> V_76 = V_12 -> V_252 . V_1028 ( V_29 ,
& V_29 -> V_79 ) ;
V_29 -> V_8 . V_106 = V_29 -> V_76 ;
V_29 -> V_251 = F_839 ( V_29 ) ;
F_140 ( L_280 ,
V_29 -> V_8 . V_8 . V_227 ,
V_29 -> V_76 ? L_177 : L_178 ) ;
}
for ( V_153 = 0 ; V_153 < V_12 -> V_451 ; V_153 ++ ) {
struct V_114 * V_117 = & V_12 -> V_116 [ V_153 ] ;
V_117 -> V_225 = V_117 -> V_120 ( V_12 , V_117 ,
& V_117 -> V_79 . V_119 ) ;
V_117 -> V_76 = 0 ;
V_117 -> V_79 . V_224 = 0 ;
F_127 (dev, crtc) {
if ( V_29 -> V_76 && F_56 ( V_29 ) == V_117 ) {
V_117 -> V_76 ++ ;
V_117 -> V_79 . V_224 |= 1 << V_29 -> V_4 ;
}
}
F_140 ( L_281 ,
V_117 -> V_121 , V_117 -> V_79 . V_224 , V_117 -> V_225 ) ;
if ( V_117 -> V_79 . V_224 )
F_142 ( V_12 , V_228 ) ;
}
F_13 (dev, encoder) {
V_4 = 0 ;
if ( V_6 -> V_120 ( V_6 , & V_4 ) ) {
V_29 = F_37 ( V_12 -> V_83 [ V_4 ] ) ;
V_6 -> V_8 . V_29 = & V_29 -> V_8 ;
V_6 -> V_1029 ( V_6 , & V_29 -> V_79 ) ;
} else {
V_6 -> V_8 . V_29 = NULL ;
}
V_6 -> V_549 = false ;
F_140 ( L_282 ,
V_6 -> V_8 . V_8 . V_227 ,
V_6 -> V_8 . V_121 ,
V_6 -> V_8 . V_29 ? L_177 : L_178 ,
F_68 ( V_4 ) ) ;
}
F_423 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_3 -> V_120 ( V_3 ) ) {
V_3 -> V_8 . V_552 = V_555 ;
V_3 -> V_6 -> V_549 = true ;
V_3 -> V_8 . V_6 = & V_3 -> V_6 -> V_8 ;
} else {
V_3 -> V_8 . V_552 = V_553 ;
V_3 -> V_8 . V_6 = NULL ;
}
F_140 ( L_283 ,
V_3 -> V_8 . V_8 . V_227 ,
V_3 -> V_8 . V_121 ,
V_3 -> V_8 . V_6 ? L_177 : L_178 ) ;
}
}
void F_236 ( struct V_9 * V_10 ,
bool V_1190 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
enum V_4 V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_6 ;
int V_153 ;
F_840 ( V_10 ) ;
F_127 (dev, crtc) {
if ( V_29 -> V_76 && V_356 . V_357 ) {
F_501 ( & V_29 -> V_8 . V_442 , & V_29 -> V_79 ) ;
F_140 ( L_284 ,
V_29 -> V_8 . V_8 . V_227 ) ;
F_677 ( & V_29 -> V_8 . V_442 ) ;
}
}
F_13 (dev, encoder) {
F_836 ( V_6 ) ;
}
F_80 (dev_priv, pipe) {
V_29 = F_37 ( V_12 -> V_83 [ V_4 ] ) ;
F_833 ( V_29 ) ;
F_675 ( V_29 , & V_29 -> V_79 , L_285 ) ;
}
for ( V_153 = 0 ; V_153 < V_12 -> V_451 ; V_153 ++ ) {
struct V_114 * V_117 = & V_12 -> V_116 [ V_153 ] ;
if ( ! V_117 -> V_225 || V_117 -> V_76 )
continue;
F_140 ( L_286 , V_117 -> V_121 ) ;
V_117 -> V_230 ( V_12 , V_117 ) ;
V_117 -> V_225 = false ;
}
if ( F_841 ( V_10 ) )
F_842 ( V_10 ) ;
else if ( F_4 ( V_10 ) )
F_843 ( V_10 ) ;
if ( V_1190 ) {
F_838 ( V_10 ) ;
F_80 (dev_priv, pipe) {
struct V_75 * V_29 =
V_12 -> V_83 [ V_4 ] ;
F_595 ( V_29 , & V_29 -> V_442 , V_29 -> V_254 , V_29 -> V_255 ,
V_29 -> V_77 -> V_78 ) ;
}
} else {
F_670 ( V_10 ) ;
}
F_430 ( V_10 ) ;
}
void F_844 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_308 ;
struct V_263 * V_264 ;
F_53 ( & V_10 -> V_267 ) ;
F_845 ( V_10 ) ;
F_55 ( & V_10 -> V_267 ) ;
if ( F_48 ( V_10 ) || F_92 ( V_10 ) )
V_12 -> V_605 . V_606 = ! ! ( F_5 ( V_162 ) &
V_740 ) ;
F_233 ( V_10 ) ;
F_846 ( V_10 ) ;
F_53 ( & V_10 -> V_267 ) ;
F_196 (dev, c) {
V_264 = F_174 ( V_308 -> V_77 -> V_78 ) ;
if ( V_264 == NULL )
continue;
if ( F_173 ( V_308 -> V_77 ,
V_308 -> V_77 -> V_78 ,
NULL ) ) {
F_119 ( L_287 ,
F_37 ( V_308 ) -> V_4 ) ;
F_599 ( V_308 -> V_77 -> V_78 ) ;
V_308 -> V_77 -> V_78 = NULL ;
}
}
F_55 ( & V_10 -> V_267 ) ;
F_847 ( V_10 ) ;
}
void F_848 ( struct V_2 * V_2 )
{
struct V_550 * V_3 = & V_2 -> V_8 ;
F_849 ( V_3 ) ;
F_850 ( V_3 ) ;
}
void F_851 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_550 * V_3 ;
F_852 ( V_10 ) ;
F_853 ( V_10 ) ;
F_854 ( V_12 ) ;
F_855 ( V_10 ) ;
F_53 ( & V_10 -> V_267 ) ;
F_856 () ;
F_346 ( V_10 ) ;
F_857 ( V_10 ) ;
F_55 ( & V_10 -> V_267 ) ;
F_858 () ;
F_423 (connector, &dev->mode_config.connector_list, head) {
struct V_2 * V_2 ;
V_2 = F_593 ( V_3 ) ;
V_2 -> V_1191 ( V_2 ) ;
}
F_859 ( V_10 ) ;
F_860 ( V_10 ) ;
F_53 ( & V_10 -> V_267 ) ;
F_861 ( V_10 ) ;
F_55 ( & V_10 -> V_267 ) ;
}
struct V_554 * F_862 ( struct V_550 * V_3 )
{
return & F_592 ( V_3 ) -> V_8 ;
}
void F_863 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
V_3 -> V_6 = V_6 ;
F_864 ( & V_3 -> V_8 ,
& V_6 -> V_8 ) ;
}
int F_865 ( struct V_9 * V_10 , bool V_107 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned V_85 = F_43 ( V_10 ) -> V_91 >= 6 ? V_1192 : V_1193 ;
T_5 V_1194 ;
if ( F_446 ( V_12 -> V_1195 , V_85 , & V_1194 ) ) {
F_119 ( L_288 ) ;
return - V_987 ;
}
if ( ! ! ( V_1194 & V_1196 ) == ! V_107 )
return 0 ;
if ( V_107 )
V_1194 &= ~ V_1196 ;
else
V_1194 |= V_1196 ;
if ( F_866 ( V_12 -> V_1195 , V_85 , V_1194 ) ) {
F_119 ( L_289 ) ;
return - V_987 ;
}
return 0 ;
}
struct V_1197 *
F_867 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1197 * error ;
int V_1198 [] = {
V_241 ,
V_1199 ,
V_1200 ,
V_481 ,
} ;
int V_153 ;
if ( F_43 ( V_10 ) -> V_364 == 0 )
return NULL ;
error = F_507 ( sizeof( * error ) , V_1201 ) ;
if ( error == NULL )
return NULL ;
if ( F_212 ( V_10 ) || F_166 ( V_10 ) )
error -> V_1202 = F_5 ( V_783 ) ;
F_80 (dev_priv, i) {
error -> V_4 [ V_153 ] . V_1203 =
F_868 ( V_12 ,
F_386 ( V_153 ) ) ;
if ( ! error -> V_4 [ V_153 ] . V_1203 )
continue;
error -> V_860 [ V_153 ] . V_487 = F_5 ( F_72 ( V_153 ) ) ;
error -> V_860 [ V_153 ] . V_1204 = F_5 ( F_573 ( V_153 ) ) ;
error -> V_860 [ V_153 ] . V_8 = F_5 ( F_572 ( V_153 ) ) ;
error -> V_151 [ V_153 ] . V_487 = F_5 ( F_77 ( V_153 ) ) ;
error -> V_151 [ V_153 ] . V_302 = F_5 ( F_208 ( V_153 ) ) ;
if ( F_43 ( V_10 ) -> V_91 <= 3 ) {
error -> V_151 [ V_153 ] . V_301 = F_5 ( F_201 ( V_153 ) ) ;
error -> V_151 [ V_153 ] . V_458 = F_5 ( F_202 ( V_153 ) ) ;
}
if ( F_43 ( V_10 ) -> V_91 <= 7 && ! F_212 ( V_10 ) )
error -> V_151 [ V_153 ] . V_869 = F_5 ( F_163 ( V_153 ) ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
error -> V_151 [ V_153 ] . V_1205 = F_5 ( F_162 ( V_153 ) ) ;
error -> V_151 [ V_153 ] . V_1206 = F_5 ( F_209 ( V_153 ) ) ;
}
error -> V_4 [ V_153 ] . V_1207 = F_5 ( F_245 ( V_153 ) ) ;
if ( F_337 ( V_10 ) )
error -> V_4 [ V_153 ] . V_1208 = F_5 ( F_869 ( V_153 ) ) ;
}
error -> V_1209 = F_43 ( V_10 ) -> V_364 ;
if ( F_59 ( V_12 -> V_10 ) )
error -> V_1209 ++ ;
for ( V_153 = 0 ; V_153 < error -> V_1209 ; V_153 ++ ) {
enum V_82 V_84 = V_1198 [ V_153 ] ;
error -> V_82 [ V_153 ] . V_1203 =
F_868 ( V_12 ,
F_75 ( V_84 ) ) ;
if ( ! error -> V_82 [ V_153 ] . V_1203 )
continue;
error -> V_82 [ V_153 ] . V_84 = V_84 ;
error -> V_82 [ V_153 ] . V_1210 = F_5 ( F_44 ( V_84 ) ) ;
error -> V_82 [ V_153 ] . V_692 = F_5 ( F_290 ( V_84 ) ) ;
error -> V_82 [ V_153 ] . V_1211 = F_5 ( F_292 ( V_84 ) ) ;
error -> V_82 [ V_153 ] . V_923 = F_5 ( F_294 ( V_84 ) ) ;
error -> V_82 [ V_153 ] . V_694 = F_5 ( F_296 ( V_84 ) ) ;
error -> V_82 [ V_153 ] . V_1212 = F_5 ( F_298 ( V_84 ) ) ;
error -> V_82 [ V_153 ] . V_925 = F_5 ( F_300 ( V_84 ) ) ;
}
return error ;
}
void
F_870 ( struct V_1213 * V_19 ,
struct V_9 * V_10 ,
struct V_1197 * error )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_153 ;
if ( ! error )
return;
F_871 ( V_19 , L_290 , F_43 ( V_10 ) -> V_364 ) ;
if ( F_212 ( V_10 ) || F_166 ( V_10 ) )
F_871 ( V_19 , L_291 ,
error -> V_1202 ) ;
F_80 (dev_priv, i) {
F_871 ( V_19 , L_292 , V_153 ) ;
F_871 ( V_19 , L_293 ,
error -> V_4 [ V_153 ] . V_1203 ? L_11 : L_12 ) ;
F_871 ( V_19 , L_294 , error -> V_4 [ V_153 ] . V_1207 ) ;
F_871 ( V_19 , L_295 , error -> V_4 [ V_153 ] . V_1208 ) ;
F_871 ( V_19 , L_296 , V_153 ) ;
F_871 ( V_19 , L_297 , error -> V_151 [ V_153 ] . V_487 ) ;
F_871 ( V_19 , L_298 , error -> V_151 [ V_153 ] . V_302 ) ;
if ( F_43 ( V_10 ) -> V_91 <= 3 ) {
F_871 ( V_19 , L_299 , error -> V_151 [ V_153 ] . V_301 ) ;
F_871 ( V_19 , L_300 , error -> V_151 [ V_153 ] . V_458 ) ;
}
if ( F_43 ( V_10 ) -> V_91 <= 7 && ! F_212 ( V_10 ) )
F_871 ( V_19 , L_301 , error -> V_151 [ V_153 ] . V_869 ) ;
if ( F_43 ( V_10 ) -> V_91 >= 4 ) {
F_871 ( V_19 , L_302 , error -> V_151 [ V_153 ] . V_1205 ) ;
F_871 ( V_19 , L_303 , error -> V_151 [ V_153 ] . V_1206 ) ;
}
F_871 ( V_19 , L_304 , V_153 ) ;
F_871 ( V_19 , L_297 , error -> V_860 [ V_153 ] . V_487 ) ;
F_871 ( V_19 , L_300 , error -> V_860 [ V_153 ] . V_1204 ) ;
F_871 ( V_19 , L_305 , error -> V_860 [ V_153 ] . V_8 ) ;
}
for ( V_153 = 0 ; V_153 < error -> V_1209 ; V_153 ++ ) {
F_871 ( V_19 , L_306 ,
F_676 ( error -> V_82 [ V_153 ] . V_84 ) ) ;
F_871 ( V_19 , L_293 ,
error -> V_82 [ V_153 ] . V_1203 ? L_11 : L_12 ) ;
F_871 ( V_19 , L_307 , error -> V_82 [ V_153 ] . V_1210 ) ;
F_871 ( V_19 , L_308 , error -> V_82 [ V_153 ] . V_692 ) ;
F_871 ( V_19 , L_309 , error -> V_82 [ V_153 ] . V_1211 ) ;
F_871 ( V_19 , L_310 , error -> V_82 [ V_153 ] . V_923 ) ;
F_871 ( V_19 , L_311 , error -> V_82 [ V_153 ] . V_694 ) ;
F_871 ( V_19 , L_312 , error -> V_82 [ V_153 ] . V_1212 ) ;
F_871 ( V_19 , L_313 , error -> V_82 [ V_153 ] . V_925 ) ;
}
}
void F_872 ( struct V_9 * V_10 , struct V_1095 * V_1096 )
{
struct V_28 * V_29 ;
F_127 (dev, crtc) {
struct V_404 * V_405 ;
F_234 ( & V_10 -> V_353 ) ;
V_405 = V_29 -> V_354 ;
if ( V_405 && V_405 -> V_406 &&
V_405 -> V_406 -> V_8 . V_1214 == V_1096 ) {
F_195 ( V_405 -> V_406 ) ;
V_405 -> V_406 = NULL ;
}
F_235 ( & V_10 -> V_353 ) ;
}
}
