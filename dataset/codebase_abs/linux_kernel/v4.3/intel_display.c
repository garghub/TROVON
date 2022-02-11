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
static bool
F_7 ( struct V_10 * V_11 )
{
return F_8 ( V_11 ) ;
}
bool F_9 ( struct V_12 * V_13 , enum V_14 type )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_16 * V_17 ;
F_10 (dev, &crtc->base, encoder)
if ( V_17 -> type == type )
return true ;
return false ;
}
static bool F_11 ( const struct V_18 * V_19 ,
int type )
{
struct V_20 * V_11 = V_19 -> V_15 . V_11 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_16 * V_17 ;
int V_25 , V_26 = 0 ;
F_12 (state, connector, connector_state, i) {
if ( V_24 -> V_13 != V_19 -> V_15 . V_13 )
continue;
V_26 ++ ;
V_17 = F_13 ( V_24 -> V_27 ) ;
if ( V_17 -> type == type )
return true ;
}
F_2 ( V_26 == 0 ) ;
return false ;
}
static const T_2 *
F_14 ( struct V_18 * V_19 , int V_28 )
{
struct V_1 * V_2 = V_19 -> V_15 . V_13 -> V_2 ;
const T_2 * V_29 ;
if ( F_11 ( V_19 , V_30 ) ) {
if ( F_15 ( V_2 ) ) {
if ( V_28 == 100000 )
V_29 = & V_31 ;
else
V_29 = & V_32 ;
} else {
if ( V_28 == 100000 )
V_29 = & V_33 ;
else
V_29 = & V_34 ;
}
} else
V_29 = & V_35 ;
return V_29 ;
}
static const T_2 *
F_16 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_15 . V_13 -> V_2 ;
const T_2 * V_29 ;
if ( F_11 ( V_19 , V_30 ) ) {
if ( F_15 ( V_2 ) )
V_29 = & V_36 ;
else
V_29 = & V_37 ;
} else if ( F_11 ( V_19 , V_38 ) ||
F_11 ( V_19 , V_39 ) ) {
V_29 = & V_40 ;
} else if ( F_11 ( V_19 , V_41 ) ) {
V_29 = & V_42 ;
} else
V_29 = & V_43 ;
return V_29 ;
}
static const T_2 *
F_17 ( struct V_18 * V_19 , int V_28 )
{
struct V_1 * V_2 = V_19 -> V_15 . V_13 -> V_2 ;
const T_2 * V_29 ;
if ( F_18 ( V_2 ) )
V_29 = & V_44 ;
else if ( F_3 ( V_2 ) )
V_29 = F_14 ( V_19 , V_28 ) ;
else if ( F_19 ( V_2 ) ) {
V_29 = F_16 ( V_19 ) ;
} else if ( F_20 ( V_2 ) ) {
if ( F_11 ( V_19 , V_30 ) )
V_29 = & V_45 ;
else
V_29 = & V_46 ;
} else if ( F_21 ( V_2 ) ) {
V_29 = & V_47 ;
} else if ( F_22 ( V_2 ) ) {
V_29 = & V_48 ;
} else if ( ! F_23 ( V_2 ) ) {
if ( F_11 ( V_19 , V_30 ) )
V_29 = & V_49 ;
else
V_29 = & V_43 ;
} else {
if ( F_11 ( V_19 , V_30 ) )
V_29 = & V_50 ;
else if ( F_11 ( V_19 , V_51 ) )
V_29 = & V_52 ;
else
V_29 = & V_53 ;
}
return V_29 ;
}
static int F_24 ( int V_28 , T_3 * clock )
{
clock -> V_54 = clock -> V_55 + 2 ;
clock -> V_56 = clock -> V_57 * clock -> V_58 ;
if ( F_2 ( clock -> V_59 == 0 || clock -> V_56 == 0 ) )
return 0 ;
clock -> V_60 = F_25 ( V_28 * clock -> V_54 , clock -> V_59 ) ;
clock -> V_61 = F_25 ( clock -> V_60 , clock -> V_56 ) ;
return clock -> V_61 ;
}
static T_4 F_26 ( struct V_62 * V_62 )
{
return 5 * ( V_62 -> V_63 + 2 ) + ( V_62 -> V_55 + 2 ) ;
}
static int F_27 ( int V_28 , T_3 * clock )
{
clock -> V_54 = F_26 ( clock ) ;
clock -> V_56 = clock -> V_57 * clock -> V_58 ;
if ( F_2 ( clock -> V_59 + 2 == 0 || clock -> V_56 == 0 ) )
return 0 ;
clock -> V_60 = F_25 ( V_28 * clock -> V_54 , clock -> V_59 + 2 ) ;
clock -> V_61 = F_25 ( clock -> V_60 , clock -> V_56 ) ;
return clock -> V_61 ;
}
static int F_28 ( int V_28 , T_3 * clock )
{
clock -> V_54 = clock -> V_63 * clock -> V_55 ;
clock -> V_56 = clock -> V_57 * clock -> V_58 ;
if ( F_2 ( clock -> V_59 == 0 || clock -> V_56 == 0 ) )
return 0 ;
clock -> V_60 = F_25 ( V_28 * clock -> V_54 , clock -> V_59 ) ;
clock -> V_61 = F_25 ( clock -> V_60 , clock -> V_56 ) ;
return clock -> V_61 / 5 ;
}
int F_29 ( int V_28 , T_3 * clock )
{
clock -> V_54 = clock -> V_63 * clock -> V_55 ;
clock -> V_56 = clock -> V_57 * clock -> V_58 ;
if ( F_2 ( clock -> V_59 == 0 || clock -> V_56 == 0 ) )
return 0 ;
clock -> V_60 = F_30 ( ( V_64 ) V_28 * clock -> V_54 ,
clock -> V_59 << 22 ) ;
clock -> V_61 = F_25 ( clock -> V_60 , clock -> V_56 ) ;
return clock -> V_61 / 5 ;
}
static bool F_31 ( struct V_1 * V_2 ,
const T_2 * V_29 ,
const T_3 * clock )
{
if ( clock -> V_59 < V_29 -> V_59 . V_65 || V_29 -> V_59 . V_66 < clock -> V_59 )
F_32 ( L_1 ) ;
if ( clock -> V_57 < V_29 -> V_57 . V_65 || V_29 -> V_57 . V_66 < clock -> V_57 )
F_32 ( L_2 ) ;
if ( clock -> V_55 < V_29 -> V_55 . V_65 || V_29 -> V_55 . V_66 < clock -> V_55 )
F_32 ( L_3 ) ;
if ( clock -> V_63 < V_29 -> V_63 . V_65 || V_29 -> V_63 . V_66 < clock -> V_63 )
F_32 ( L_4 ) ;
if ( ! F_20 ( V_2 ) && ! F_22 ( V_2 ) && ! F_18 ( V_2 ) )
if ( clock -> V_63 <= clock -> V_55 )
F_32 ( L_5 ) ;
if ( ! F_22 ( V_2 ) && ! F_18 ( V_2 ) ) {
if ( clock -> V_56 < V_29 -> V_56 . V_65 || V_29 -> V_56 . V_66 < clock -> V_56 )
F_32 ( L_6 ) ;
if ( clock -> V_54 < V_29 -> V_54 . V_65 || V_29 -> V_54 . V_66 < clock -> V_54 )
F_32 ( L_7 ) ;
}
if ( clock -> V_60 < V_29 -> V_60 . V_65 || V_29 -> V_60 . V_66 < clock -> V_60 )
F_32 ( L_8 ) ;
if ( clock -> V_61 < V_29 -> V_61 . V_65 || V_29 -> V_61 . V_66 < clock -> V_61 )
F_32 ( L_9 ) ;
return true ;
}
static int
F_33 ( const T_2 * V_29 ,
const struct V_18 * V_19 ,
int V_67 )
{
struct V_1 * V_2 = V_19 -> V_15 . V_13 -> V_2 ;
if ( F_11 ( V_19 , V_30 ) ) {
if ( F_15 ( V_2 ) )
return V_29 -> V_58 . V_68 ;
else
return V_29 -> V_58 . V_69 ;
} else {
if ( V_67 < V_29 -> V_58 . V_70 )
return V_29 -> V_58 . V_69 ;
else
return V_29 -> V_58 . V_68 ;
}
}
static bool
F_34 ( const T_2 * V_29 ,
struct V_18 * V_19 ,
int V_67 , int V_28 , T_3 * V_71 ,
T_3 * V_72 )
{
struct V_1 * V_2 = V_19 -> V_15 . V_13 -> V_2 ;
T_3 clock ;
int V_73 = V_67 ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
clock . V_58 = F_33 ( V_29 , V_19 , V_67 ) ;
for ( clock . V_63 = V_29 -> V_63 . V_65 ; clock . V_63 <= V_29 -> V_63 . V_66 ;
clock . V_63 ++ ) {
for ( clock . V_55 = V_29 -> V_55 . V_65 ;
clock . V_55 <= V_29 -> V_55 . V_66 ; clock . V_55 ++ ) {
if ( clock . V_55 >= clock . V_63 )
break;
for ( clock . V_59 = V_29 -> V_59 . V_65 ;
clock . V_59 <= V_29 -> V_59 . V_66 ; clock . V_59 ++ ) {
for ( clock . V_57 = V_29 -> V_57 . V_65 ;
clock . V_57 <= V_29 -> V_57 . V_66 ; clock . V_57 ++ ) {
int V_74 ;
F_27 ( V_28 , & clock ) ;
if ( ! F_31 ( V_2 , V_29 ,
& clock ) )
continue;
if ( V_71 &&
clock . V_56 != V_71 -> V_56 )
continue;
V_74 = abs ( clock . V_61 - V_67 ) ;
if ( V_74 < V_73 ) {
* V_72 = clock ;
V_73 = V_74 ;
}
}
}
}
}
return ( V_73 != V_67 ) ;
}
static bool
F_35 ( const T_2 * V_29 ,
struct V_18 * V_19 ,
int V_67 , int V_28 , T_3 * V_71 ,
T_3 * V_72 )
{
struct V_1 * V_2 = V_19 -> V_15 . V_13 -> V_2 ;
T_3 clock ;
int V_73 = V_67 ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
clock . V_58 = F_33 ( V_29 , V_19 , V_67 ) ;
for ( clock . V_63 = V_29 -> V_63 . V_65 ; clock . V_63 <= V_29 -> V_63 . V_66 ;
clock . V_63 ++ ) {
for ( clock . V_55 = V_29 -> V_55 . V_65 ;
clock . V_55 <= V_29 -> V_55 . V_66 ; clock . V_55 ++ ) {
for ( clock . V_59 = V_29 -> V_59 . V_65 ;
clock . V_59 <= V_29 -> V_59 . V_66 ; clock . V_59 ++ ) {
for ( clock . V_57 = V_29 -> V_57 . V_65 ;
clock . V_57 <= V_29 -> V_57 . V_66 ; clock . V_57 ++ ) {
int V_74 ;
F_24 ( V_28 , & clock ) ;
if ( ! F_31 ( V_2 , V_29 ,
& clock ) )
continue;
if ( V_71 &&
clock . V_56 != V_71 -> V_56 )
continue;
V_74 = abs ( clock . V_61 - V_67 ) ;
if ( V_74 < V_73 ) {
* V_72 = clock ;
V_73 = V_74 ;
}
}
}
}
}
return ( V_73 != V_67 ) ;
}
static bool
F_36 ( const T_2 * V_29 ,
struct V_18 * V_19 ,
int V_67 , int V_28 , T_3 * V_71 ,
T_3 * V_72 )
{
struct V_1 * V_2 = V_19 -> V_15 . V_13 -> V_2 ;
T_3 clock ;
int V_75 ;
bool V_76 = false ;
int V_77 = ( V_67 >> 8 ) + ( V_67 >> 9 ) ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
clock . V_58 = F_33 ( V_29 , V_19 , V_67 ) ;
V_75 = V_29 -> V_59 . V_66 ;
for ( clock . V_59 = V_29 -> V_59 . V_65 ; clock . V_59 <= V_75 ; clock . V_59 ++ ) {
for ( clock . V_63 = V_29 -> V_63 . V_66 ;
clock . V_63 >= V_29 -> V_63 . V_65 ; clock . V_63 -- ) {
for ( clock . V_55 = V_29 -> V_55 . V_66 ;
clock . V_55 >= V_29 -> V_55 . V_65 ; clock . V_55 -- ) {
for ( clock . V_57 = V_29 -> V_57 . V_66 ;
clock . V_57 >= V_29 -> V_57 . V_65 ; clock . V_57 -- ) {
int V_74 ;
F_27 ( V_28 , & clock ) ;
if ( ! F_31 ( V_2 , V_29 ,
& clock ) )
continue;
V_74 = abs ( clock . V_61 - V_67 ) ;
if ( V_74 < V_77 ) {
* V_72 = clock ;
V_77 = V_74 ;
V_75 = clock . V_59 ;
V_76 = true ;
}
}
}
}
}
return V_76 ;
}
static bool F_37 ( struct V_1 * V_2 , int V_78 ,
const T_3 * V_79 ,
const T_3 * V_72 ,
unsigned int V_80 ,
unsigned int * V_81 )
{
if ( F_21 ( V_2 ) ) {
* V_81 = 0 ;
return V_79 -> V_56 > V_72 -> V_56 ;
}
if ( F_38 ( ! V_78 ) )
return false ;
* V_81 = F_39 ( 1000000ULL *
abs ( V_78 - V_79 -> V_61 ) ,
V_78 ) ;
if ( * V_81 < 100 && V_79 -> V_56 > V_72 -> V_56 ) {
* V_81 = 0 ;
return true ;
}
return * V_81 + 10 < V_80 ;
}
static bool
F_40 ( const T_2 * V_29 ,
struct V_18 * V_19 ,
int V_67 , int V_28 , T_3 * V_71 ,
T_3 * V_72 )
{
struct V_12 * V_13 = F_41 ( V_19 -> V_15 . V_13 ) ;
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
T_3 clock ;
unsigned int V_82 = 1000000 ;
int V_75 = V_65 ( V_29 -> V_59 . V_66 , V_28 / 19200 ) ;
bool V_76 = false ;
V_67 *= 5 ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
for ( clock . V_59 = V_29 -> V_59 . V_65 ; clock . V_59 <= V_75 ; clock . V_59 ++ ) {
for ( clock . V_57 = V_29 -> V_57 . V_66 ; clock . V_57 >= V_29 -> V_57 . V_65 ; clock . V_57 -- ) {
for ( clock . V_58 = V_29 -> V_58 . V_68 ; clock . V_58 >= V_29 -> V_58 . V_69 ;
clock . V_58 -= clock . V_58 > 10 ? 2 : 1 ) {
clock . V_56 = clock . V_57 * clock . V_58 ;
for ( clock . V_63 = V_29 -> V_63 . V_65 ; clock . V_63 <= V_29 -> V_63 . V_66 ; clock . V_63 ++ ) {
unsigned int V_83 ;
clock . V_55 = F_25 ( V_67 * clock . V_56 * clock . V_59 ,
V_28 * clock . V_63 ) ;
F_28 ( V_28 , & clock ) ;
if ( ! F_31 ( V_2 , V_29 ,
& clock ) )
continue;
if ( ! F_37 ( V_2 , V_67 ,
& clock ,
V_72 ,
V_82 , & V_83 ) )
continue;
* V_72 = clock ;
V_82 = V_83 ;
V_76 = true ;
}
}
}
}
return V_76 ;
}
static bool
F_42 ( const T_2 * V_29 ,
struct V_18 * V_19 ,
int V_67 , int V_28 , T_3 * V_71 ,
T_3 * V_72 )
{
struct V_12 * V_13 = F_41 ( V_19 -> V_15 . V_13 ) ;
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
unsigned int V_80 ;
T_3 clock ;
V_64 V_55 ;
int V_76 = false ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_80 = 1000000 ;
clock . V_59 = 1 , clock . V_63 = 2 ;
V_67 *= 5 ;
for ( clock . V_57 = V_29 -> V_57 . V_66 ; clock . V_57 >= V_29 -> V_57 . V_65 ; clock . V_57 -- ) {
for ( clock . V_58 = V_29 -> V_58 . V_68 ;
clock . V_58 >= V_29 -> V_58 . V_69 ;
clock . V_58 -= clock . V_58 > 10 ? 2 : 1 ) {
unsigned int V_81 ;
clock . V_56 = clock . V_57 * clock . V_58 ;
V_55 = F_30 ( ( ( V_64 ) V_67 * clock . V_56 *
clock . V_59 ) << 22 , V_28 * clock . V_63 ) ;
if ( V_55 > V_84 / clock . V_63 )
continue;
clock . V_55 = V_55 ;
F_29 ( V_28 , & clock ) ;
if ( ! F_31 ( V_2 , V_29 , & clock ) )
continue;
if ( ! F_37 ( V_2 , V_67 , & clock , V_72 ,
V_80 , & V_81 ) )
continue;
* V_72 = clock ;
V_80 = V_81 ;
V_76 = true ;
}
}
return V_76 ;
}
bool F_43 ( struct V_18 * V_19 , int V_85 ,
T_3 * V_72 )
{
int V_28 = F_44 ( V_19 , 0 ) ;
return F_42 ( F_17 ( V_19 , V_28 ) , V_19 ,
V_85 , V_28 , NULL , V_72 ) ;
}
bool F_45 ( struct V_86 * V_13 )
{
struct V_12 * V_12 = F_41 ( V_13 ) ;
return V_12 -> V_87 && V_13 -> V_88 -> V_11 -> V_89 &&
V_12 -> V_90 -> V_15 . V_91 . V_92 ;
}
enum V_93 F_46 ( struct V_3 * V_4 ,
enum V_94 V_94 )
{
struct V_86 * V_13 = V_4 -> V_95 [ V_94 ] ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
return V_12 -> V_90 -> V_96 ;
}
static bool F_47 ( struct V_1 * V_2 , enum V_94 V_94 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_97 = F_48 ( V_94 ) ;
T_1 V_98 , V_99 ;
T_1 V_100 ;
if ( F_23 ( V_2 ) )
V_100 = V_101 ;
else
V_100 = V_102 ;
V_98 = F_4 ( V_97 ) & V_100 ;
F_49 ( 5 ) ;
V_99 = F_4 ( V_97 ) & V_100 ;
return V_98 == V_99 ;
}
static void F_50 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_93 V_96 = V_13 -> V_90 -> V_96 ;
enum V_94 V_94 = V_13 -> V_94 ;
if ( F_51 ( V_2 ) -> V_103 >= 4 ) {
int V_97 = F_52 ( V_96 ) ;
if ( F_53 ( ( F_4 ( V_97 ) & V_104 ) == 0 ,
100 ) )
F_54 ( 1 , L_10 ) ;
} else {
if ( F_53 ( F_47 ( V_2 , V_94 ) , 100 ) )
F_54 ( 1 , L_10 ) ;
}
}
bool F_55 ( struct V_3 * V_4 ,
struct V_105 * V_106 )
{
T_1 V_107 ;
if ( F_56 ( V_4 -> V_2 ) ) {
switch ( V_106 -> V_106 ) {
case V_108 :
V_107 = V_109 ;
break;
case V_110 :
V_107 = V_111 ;
break;
case V_112 :
V_107 = V_113 ;
break;
default:
return true ;
}
} else {
switch ( V_106 -> V_106 ) {
case V_108 :
V_107 = V_114 ;
break;
case V_110 :
V_107 = V_115 ;
break;
case V_112 :
V_107 = V_116 ;
break;
case V_117 :
V_107 = V_118 ;
break;
default:
return true ;
}
}
return F_4 ( V_119 ) & V_107 ;
}
static const char * F_57 ( bool V_120 )
{
return V_120 ? L_11 : L_12 ;
}
void F_58 ( struct V_3 * V_4 ,
enum V_94 V_94 , bool V_11 )
{
int V_97 ;
T_1 V_121 ;
bool V_122 ;
V_97 = F_59 ( V_94 ) ;
V_121 = F_4 ( V_97 ) ;
V_122 = ! ! ( V_121 & V_123 ) ;
F_60 ( V_122 != V_11 ,
L_13 ,
F_57 ( V_11 ) , F_57 ( V_122 ) ) ;
}
static void F_61 ( struct V_3 * V_4 , bool V_11 )
{
T_1 V_121 ;
bool V_122 ;
F_62 ( & V_4 -> V_124 ) ;
V_121 = F_63 ( V_4 , V_125 ) ;
F_64 ( & V_4 -> V_124 ) ;
V_122 = V_121 & V_126 ;
F_60 ( V_122 != V_11 ,
L_14 ,
F_57 ( V_11 ) , F_57 ( V_122 ) ) ;
}
struct V_127 *
F_65 ( struct V_12 * V_13 )
{
struct V_3 * V_4 = V_13 -> V_15 . V_2 -> V_5 ;
if ( V_13 -> V_90 -> V_128 < 0 )
return NULL ;
return & V_4 -> V_129 [ V_13 -> V_90 -> V_128 ] ;
}
void F_66 ( struct V_3 * V_4 ,
struct V_127 * V_130 ,
bool V_11 )
{
bool V_122 ;
struct V_131 V_132 ;
if ( F_54 ( ! V_130 ,
L_15 , F_57 ( V_11 ) ) )
return;
V_122 = V_130 -> V_133 ( V_4 , V_130 , & V_132 ) ;
F_60 ( V_122 != V_11 ,
L_16 ,
V_130 -> V_134 , F_57 ( V_11 ) , F_57 ( V_122 ) ) ;
}
static void F_67 ( struct V_3 * V_4 ,
enum V_94 V_94 , bool V_11 )
{
int V_97 ;
T_1 V_121 ;
bool V_122 ;
enum V_93 V_96 = F_46 ( V_4 ,
V_94 ) ;
if ( F_68 ( V_4 -> V_2 ) ) {
V_97 = F_69 ( V_96 ) ;
V_121 = F_4 ( V_97 ) ;
V_122 = ! ! ( V_121 & V_135 ) ;
} else {
V_97 = F_70 ( V_94 ) ;
V_121 = F_4 ( V_97 ) ;
V_122 = ! ! ( V_121 & V_136 ) ;
}
F_60 ( V_122 != V_11 ,
L_17 ,
F_57 ( V_11 ) , F_57 ( V_122 ) ) ;
}
static void F_71 ( struct V_3 * V_4 ,
enum V_94 V_94 , bool V_11 )
{
int V_97 ;
T_1 V_121 ;
bool V_122 ;
V_97 = F_72 ( V_94 ) ;
V_121 = F_4 ( V_97 ) ;
V_122 = ! ! ( V_121 & V_137 ) ;
F_60 ( V_122 != V_11 ,
L_18 ,
F_57 ( V_11 ) , F_57 ( V_122 ) ) ;
}
static void F_73 ( struct V_3 * V_4 ,
enum V_94 V_94 )
{
int V_97 ;
T_1 V_121 ;
if ( F_51 ( V_4 -> V_2 ) -> V_103 == 5 )
return;
if ( F_68 ( V_4 -> V_2 ) )
return;
V_97 = F_70 ( V_94 ) ;
V_121 = F_4 ( V_97 ) ;
F_60 ( ! ( V_121 & V_138 ) , L_19 ) ;
}
void F_74 ( struct V_3 * V_4 ,
enum V_94 V_94 , bool V_11 )
{
int V_97 ;
T_1 V_121 ;
bool V_122 ;
V_97 = F_72 ( V_94 ) ;
V_121 = F_4 ( V_97 ) ;
V_122 = ! ! ( V_121 & V_139 ) ;
F_60 ( V_122 != V_11 ,
L_20 ,
F_57 ( V_11 ) , F_57 ( V_122 ) ) ;
}
void F_75 ( struct V_3 * V_4 ,
enum V_94 V_94 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_140 ;
T_1 V_121 ;
enum V_94 V_141 = V_142 ;
bool V_143 = true ;
if ( F_2 ( F_68 ( V_2 ) ) )
return;
if ( F_3 ( V_2 ) ) {
T_1 V_144 ;
V_140 = V_145 ;
V_144 = F_4 ( V_146 ) & V_147 ;
if ( V_144 == V_148 &&
F_4 ( V_149 ) & V_150 )
V_141 = V_151 ;
} else if ( F_22 ( V_2 ) ) {
V_140 = F_76 ( V_94 ) ;
V_141 = V_94 ;
} else {
V_140 = V_152 ;
if ( F_4 ( V_153 ) & V_150 )
V_141 = V_151 ;
}
V_121 = F_4 ( V_140 ) ;
if ( ! ( V_121 & V_154 ) ||
( ( V_121 & V_155 ) == V_156 ) )
V_143 = false ;
F_60 ( V_141 == V_94 && V_143 ,
L_21 ,
F_77 ( V_94 ) ) ;
}
static void F_78 ( struct V_3 * V_4 ,
enum V_94 V_94 , bool V_11 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
bool V_122 ;
if ( F_79 ( V_2 ) || F_80 ( V_2 ) )
V_122 = F_4 ( V_157 ) & V_158 ;
else
V_122 = F_4 ( F_81 ( V_94 ) ) & V_159 ;
F_60 ( V_122 != V_11 ,
L_22 ,
F_77 ( V_94 ) , F_57 ( V_11 ) , F_57 ( V_122 ) ) ;
}
void F_82 ( struct V_3 * V_4 ,
enum V_94 V_94 , bool V_11 )
{
int V_97 ;
T_1 V_121 ;
bool V_122 ;
enum V_93 V_96 = F_46 ( V_4 ,
V_94 ) ;
if ( ( V_94 == V_142 && V_4 -> V_160 & V_161 ) ||
( V_94 == V_151 && V_4 -> V_160 & V_162 ) )
V_11 = true ;
if ( ! F_83 ( V_4 ,
F_84 ( V_96 ) ) ) {
V_122 = false ;
} else {
V_97 = F_52 ( V_96 ) ;
V_121 = F_4 ( V_97 ) ;
V_122 = ! ! ( V_121 & V_163 ) ;
}
F_60 ( V_122 != V_11 ,
L_23 ,
F_77 ( V_94 ) , F_57 ( V_11 ) , F_57 ( V_122 ) ) ;
}
static void F_85 ( struct V_3 * V_4 ,
enum V_164 V_164 , bool V_11 )
{
int V_97 ;
T_1 V_121 ;
bool V_122 ;
V_97 = F_86 ( V_164 ) ;
V_121 = F_4 ( V_97 ) ;
V_122 = ! ! ( V_121 & V_165 ) ;
F_60 ( V_122 != V_11 ,
L_24 ,
F_87 ( V_164 ) , F_57 ( V_11 ) , F_57 ( V_122 ) ) ;
}
static void F_88 ( struct V_3 * V_4 ,
enum V_94 V_94 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_97 , V_25 ;
T_1 V_121 ;
int V_166 ;
if ( F_51 ( V_2 ) -> V_103 >= 4 ) {
V_97 = F_86 ( V_94 ) ;
V_121 = F_4 ( V_97 ) ;
F_60 ( V_121 & V_165 ,
L_25 ,
F_87 ( V_94 ) ) ;
return;
}
F_89 (dev_priv, i) {
V_97 = F_86 ( V_25 ) ;
V_121 = F_4 ( V_97 ) ;
V_166 = ( V_121 & V_167 ) >>
V_168 ;
F_60 ( ( V_121 & V_165 ) && V_94 == V_166 ,
L_26 ,
F_87 ( V_25 ) , F_77 ( V_94 ) ) ;
}
}
static void F_90 ( struct V_3 * V_4 ,
enum V_94 V_94 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_97 , V_169 ;
T_1 V_121 ;
if ( F_51 ( V_2 ) -> V_103 >= 9 ) {
F_91 (dev_priv, pipe, sprite) {
V_121 = F_4 ( F_92 ( V_94 , V_169 ) ) ;
F_60 ( V_121 & V_170 ,
L_27 ,
V_169 , F_77 ( V_94 ) ) ;
}
} else if ( F_22 ( V_2 ) ) {
F_91 (dev_priv, pipe, sprite) {
V_97 = F_93 ( V_94 , V_169 ) ;
V_121 = F_4 ( V_97 ) ;
F_60 ( V_121 & V_171 ,
L_28 ,
F_94 ( V_94 , V_169 ) , F_77 ( V_94 ) ) ;
}
} else if ( F_51 ( V_2 ) -> V_103 >= 7 ) {
V_97 = F_95 ( V_94 ) ;
V_121 = F_4 ( V_97 ) ;
F_60 ( V_121 & V_172 ,
L_28 ,
F_87 ( V_94 ) , F_77 ( V_94 ) ) ;
} else if ( F_51 ( V_2 ) -> V_103 >= 5 ) {
V_97 = F_96 ( V_94 ) ;
V_121 = F_4 ( V_97 ) ;
F_60 ( V_121 & V_173 ,
L_28 ,
F_87 ( V_94 ) , F_77 ( V_94 ) ) ;
}
}
static void F_97 ( struct V_86 * V_13 )
{
if ( F_98 ( F_99 ( V_13 ) == 0 ) )
F_100 ( V_13 ) ;
}
static void F_101 ( struct V_3 * V_4 )
{
T_1 V_121 ;
bool V_120 ;
F_98 ( ! ( F_56 ( V_4 -> V_2 ) || F_102 ( V_4 -> V_2 ) ) ) ;
V_121 = F_4 ( V_174 ) ;
V_120 = ! ! ( V_121 & ( V_175 | V_176 |
V_177 ) ) ;
F_60 ( ! V_120 , L_29 ) ;
}
static void F_103 ( struct V_3 * V_4 ,
enum V_94 V_94 )
{
int V_97 ;
T_1 V_121 ;
bool V_120 ;
V_97 = F_104 ( V_94 ) ;
V_121 = F_4 ( V_97 ) ;
V_120 = ! ! ( V_121 & V_178 ) ;
F_60 ( V_120 ,
L_30 ,
F_77 ( V_94 ) ) ;
}
static bool F_105 ( struct V_3 * V_4 ,
enum V_94 V_94 , T_1 V_144 , T_1 V_121 )
{
if ( ( V_121 & V_179 ) == 0 )
return false ;
if ( F_102 ( V_4 -> V_2 ) ) {
T_1 V_180 = F_106 ( V_94 ) ;
T_1 V_181 = F_4 ( V_180 ) ;
if ( ( V_181 & V_182 ) != V_144 )
return false ;
} else if ( F_21 ( V_4 -> V_2 ) ) {
if ( ( V_121 & V_183 ) != F_107 ( V_94 ) )
return false ;
} else {
if ( ( V_121 & V_184 ) != ( V_94 << 30 ) )
return false ;
}
return true ;
}
static bool F_108 ( struct V_3 * V_4 ,
enum V_94 V_94 , T_1 V_121 )
{
if ( ( V_121 & V_185 ) == 0 )
return false ;
if ( F_102 ( V_4 -> V_2 ) ) {
if ( ( V_121 & V_186 ) != F_109 ( V_94 ) )
return false ;
} else if ( F_21 ( V_4 -> V_2 ) ) {
if ( ( V_121 & V_187 ) != F_110 ( V_94 ) )
return false ;
} else {
if ( ( V_121 & V_188 ) != F_111 ( V_94 ) )
return false ;
}
return true ;
}
static bool F_112 ( struct V_3 * V_4 ,
enum V_94 V_94 , T_1 V_121 )
{
if ( ( V_121 & V_189 ) == 0 )
return false ;
if ( F_102 ( V_4 -> V_2 ) ) {
if ( ( V_121 & V_190 ) != F_113 ( V_94 ) )
return false ;
} else {
if ( ( V_121 & V_191 ) != F_114 ( V_94 ) )
return false ;
}
return true ;
}
static bool F_115 ( struct V_3 * V_4 ,
enum V_94 V_94 , T_1 V_121 )
{
if ( ( V_121 & V_192 ) == 0 )
return false ;
if ( F_102 ( V_4 -> V_2 ) ) {
if ( ( V_121 & V_190 ) != F_113 ( V_94 ) )
return false ;
} else {
if ( ( V_121 & V_193 ) != F_116 ( V_94 ) )
return false ;
}
return true ;
}
static void F_117 ( struct V_3 * V_4 ,
enum V_94 V_94 , int V_97 , T_1 V_144 )
{
T_1 V_121 = F_4 ( V_97 ) ;
F_60 ( F_105 ( V_4 , V_94 , V_144 , V_121 ) ,
L_31 ,
V_97 , F_77 ( V_94 ) ) ;
F_60 ( F_56 ( V_4 -> V_2 ) && ( V_121 & V_179 ) == 0
&& ( V_121 & V_194 ) ,
L_32 ) ;
}
static void F_118 ( struct V_3 * V_4 ,
enum V_94 V_94 , int V_97 )
{
T_1 V_121 = F_4 ( V_97 ) ;
F_60 ( F_108 ( V_4 , V_94 , V_121 ) ,
L_33 ,
V_97 , F_77 ( V_94 ) ) ;
F_60 ( F_56 ( V_4 -> V_2 ) && ( V_121 & V_185 ) == 0
&& ( V_121 & V_195 ) ,
L_34 ) ;
}
static void F_119 ( struct V_3 * V_4 ,
enum V_94 V_94 )
{
int V_97 ;
T_1 V_121 ;
F_117 ( V_4 , V_94 , V_196 , V_197 ) ;
F_117 ( V_4 , V_94 , V_198 , V_199 ) ;
F_117 ( V_4 , V_94 , V_200 , V_201 ) ;
V_97 = V_202 ;
V_121 = F_4 ( V_97 ) ;
F_60 ( F_115 ( V_4 , V_94 , V_121 ) ,
L_35 ,
F_77 ( V_94 ) ) ;
V_97 = V_149 ;
V_121 = F_4 ( V_97 ) ;
F_60 ( F_112 ( V_4 , V_94 , V_121 ) ,
L_36 ,
F_77 ( V_94 ) ) ;
F_118 ( V_4 , V_94 , V_203 ) ;
F_118 ( V_4 , V_94 , V_204 ) ;
F_118 ( V_4 , V_94 , V_205 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_22 ( V_2 ) )
return;
if ( F_21 ( V_2 ) ) {
F_121 ( V_206 ) = V_207 ;
F_121 ( V_208 ) = V_209 ;
} else {
F_121 ( V_206 ) = V_209 ;
}
}
static void F_122 ( struct V_12 * V_13 ,
const struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_97 = F_59 ( V_13 -> V_94 ) ;
T_1 V_62 = V_210 -> V_211 . V_62 ;
F_123 ( V_4 , V_13 -> V_94 ) ;
F_124 ( ! F_22 ( V_4 -> V_2 ) ) ;
if ( F_125 ( V_4 -> V_2 ) )
F_75 ( V_4 , V_13 -> V_94 ) ;
F_126 ( V_97 , V_62 ) ;
F_127 ( V_97 ) ;
F_128 ( 150 ) ;
if ( F_53 ( ( ( F_4 ( V_97 ) & V_212 ) == V_212 ) , 1 ) )
F_129 ( L_37 , V_13 -> V_94 ) ;
F_126 ( F_130 ( V_13 -> V_94 ) , V_210 -> V_211 . V_213 ) ;
F_127 ( F_130 ( V_13 -> V_94 ) ) ;
F_126 ( V_97 , V_62 ) ;
F_127 ( V_97 ) ;
F_128 ( 150 ) ;
F_126 ( V_97 , V_62 ) ;
F_127 ( V_97 ) ;
F_128 ( 150 ) ;
F_126 ( V_97 , V_62 ) ;
F_127 ( V_97 ) ;
F_128 ( 150 ) ;
}
static void F_131 ( struct V_12 * V_13 ,
const struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_94 = V_13 -> V_94 ;
enum V_214 V_106 = F_132 ( V_94 ) ;
T_1 V_215 ;
F_123 ( V_4 , V_13 -> V_94 ) ;
F_124 ( ! F_21 ( V_4 -> V_2 ) ) ;
F_62 ( & V_4 -> V_124 ) ;
V_215 = F_133 ( V_4 , V_94 , F_134 ( V_106 ) ) ;
V_215 |= V_216 ;
F_135 ( V_4 , V_94 , F_134 ( V_106 ) , V_215 ) ;
F_64 ( & V_4 -> V_124 ) ;
F_128 ( 1 ) ;
F_126 ( F_59 ( V_94 ) , V_210 -> V_211 . V_62 ) ;
if ( F_53 ( ( ( F_4 ( F_59 ( V_94 ) ) & V_212 ) == V_212 ) , 1 ) )
F_129 ( L_38 , V_94 ) ;
F_126 ( F_130 ( V_94 ) , V_210 -> V_211 . V_213 ) ;
F_127 ( F_130 ( V_94 ) ) ;
}
static int F_136 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_217 = 0 ;
F_137 (dev, crtc)
V_217 += V_13 -> V_15 . V_11 -> V_87 &&
F_9 ( V_13 , V_51 ) ;
return V_217 ;
}
static void F_138 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_97 = F_59 ( V_13 -> V_94 ) ;
T_1 V_62 = V_13 -> V_90 -> V_211 . V_62 ;
F_123 ( V_4 , V_13 -> V_94 ) ;
F_124 ( F_51 ( V_2 ) -> V_103 >= 5 ) ;
if ( F_125 ( V_2 ) && ! F_139 ( V_2 ) )
F_75 ( V_4 , V_13 -> V_94 ) ;
if ( F_139 ( V_2 ) && F_136 ( V_2 ) > 0 ) {
V_62 |= V_218 ;
F_126 ( F_59 ( ! V_13 -> V_94 ) ,
F_4 ( F_59 ( ! V_13 -> V_94 ) ) | V_218 ) ;
}
F_126 ( V_97 , 0 ) ;
F_126 ( V_97 , V_62 ) ;
F_127 ( V_97 ) ;
F_128 ( 150 ) ;
if ( F_51 ( V_2 ) -> V_103 >= 4 ) {
F_126 ( F_130 ( V_13 -> V_94 ) ,
V_13 -> V_90 -> V_211 . V_213 ) ;
} else {
F_126 ( V_97 , V_62 ) ;
}
F_126 ( V_97 , V_62 ) ;
F_127 ( V_97 ) ;
F_128 ( 150 ) ;
F_126 ( V_97 , V_62 ) ;
F_127 ( V_97 ) ;
F_128 ( 150 ) ;
F_126 ( V_97 , V_62 ) ;
F_127 ( V_97 ) ;
F_128 ( 150 ) ;
}
static void F_140 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_94 V_94 = V_13 -> V_94 ;
if ( F_139 ( V_2 ) &&
F_9 ( V_13 , V_51 ) &&
! F_136 ( V_2 ) ) {
F_126 ( F_59 ( V_151 ) ,
F_4 ( F_59 ( V_151 ) ) & ~ V_218 ) ;
F_126 ( F_59 ( V_142 ) ,
F_4 ( F_59 ( V_142 ) ) & ~ V_218 ) ;
}
if ( ( V_94 == V_142 && V_4 -> V_160 & V_161 ) ||
( V_94 == V_151 && V_4 -> V_160 & V_162 ) )
return;
F_123 ( V_4 , V_94 ) ;
F_126 ( F_59 ( V_94 ) , V_219 ) ;
F_127 ( F_59 ( V_94 ) ) ;
}
static void F_141 ( struct V_3 * V_4 , enum V_94 V_94 )
{
T_1 V_121 ;
F_123 ( V_4 , V_94 ) ;
V_121 = V_219 ;
if ( V_94 == V_151 )
V_121 = V_220 | V_221 ;
F_126 ( F_59 ( V_94 ) , V_121 ) ;
F_127 ( F_59 ( V_94 ) ) ;
}
static void F_142 ( struct V_3 * V_4 , enum V_94 V_94 )
{
enum V_214 V_106 = F_132 ( V_94 ) ;
T_1 V_121 ;
F_123 ( V_4 , V_94 ) ;
V_121 = V_222 |
V_221 | V_219 ;
if ( V_94 != V_142 )
V_121 |= V_220 ;
F_126 ( F_59 ( V_94 ) , V_121 ) ;
F_127 ( F_59 ( V_94 ) ) ;
F_62 ( & V_4 -> V_124 ) ;
V_121 = F_133 ( V_4 , V_94 , F_134 ( V_106 ) ) ;
V_121 &= ~ V_216 ;
F_135 ( V_4 , V_94 , F_134 ( V_106 ) , V_121 ) ;
if ( V_94 != V_151 ) {
V_121 = F_133 ( V_4 , V_94 , V_223 ) ;
V_121 &= ~ ( V_224 | V_225 ) ;
F_135 ( V_4 , V_94 , V_223 , V_121 ) ;
} else {
V_121 = F_133 ( V_4 , V_94 , V_226 ) ;
V_121 &= ~ ( V_227 | V_228 ) ;
F_135 ( V_4 , V_94 , V_226 , V_121 ) ;
}
F_64 ( & V_4 -> V_124 ) ;
}
void F_143 ( struct V_3 * V_4 ,
struct V_105 * V_229 ,
unsigned int V_230 )
{
T_1 V_231 ;
int V_232 ;
switch ( V_229 -> V_106 ) {
case V_108 :
V_231 = V_233 ;
V_232 = F_59 ( 0 ) ;
break;
case V_110 :
V_231 = V_234 ;
V_232 = F_59 ( 0 ) ;
V_230 <<= 4 ;
break;
case V_112 :
V_231 = V_235 ;
V_232 = V_236 ;
break;
default:
F_144 () ;
}
if ( F_53 ( ( F_4 ( V_232 ) & V_231 ) == V_230 , 1000 ) )
F_54 ( 1 , L_39 ,
F_145 ( V_229 -> V_106 ) , F_4 ( V_232 ) & V_231 , V_230 ) ;
}
static void F_146 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_127 * V_130 = F_65 ( V_13 ) ;
if ( F_2 ( V_130 == NULL ) )
return;
F_2 ( ! V_130 -> V_90 . V_237 ) ;
if ( V_130 -> V_87 == 0 ) {
F_147 ( L_40 , V_130 -> V_134 ) ;
F_2 ( V_130 -> V_238 ) ;
F_148 ( V_4 , V_130 ) ;
V_130 -> V_239 ( V_4 , V_130 ) ;
}
}
static void F_149 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_127 * V_130 = F_65 ( V_13 ) ;
if ( F_2 ( V_130 == NULL ) )
return;
if ( F_2 ( V_130 -> V_90 . V_237 == 0 ) )
return;
F_150 ( L_41 ,
V_130 -> V_134 , V_130 -> V_87 , V_130 -> V_238 ,
V_13 -> V_15 . V_15 . V_240 ) ;
if ( V_130 -> V_87 ++ ) {
F_2 ( ! V_130 -> V_238 ) ;
F_151 ( V_4 , V_130 ) ;
return;
}
F_2 ( V_130 -> V_238 ) ;
F_152 ( V_4 , V_241 ) ;
F_150 ( L_42 , V_130 -> V_134 ) ;
V_130 -> V_242 ( V_4 , V_130 ) ;
V_130 -> V_238 = true ;
}
static void F_153 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_127 * V_130 = F_65 ( V_13 ) ;
if ( F_51 ( V_2 ) -> V_103 < 5 )
return;
if ( V_130 == NULL )
return;
if ( F_2 ( ! ( V_130 -> V_90 . V_237 & ( 1 << F_154 ( & V_13 -> V_15 ) ) ) ) )
return;
F_150 ( L_43 ,
V_130 -> V_134 , V_130 -> V_87 , V_130 -> V_238 ,
V_13 -> V_15 . V_15 . V_240 ) ;
if ( F_2 ( V_130 -> V_87 == 0 ) ) {
F_148 ( V_4 , V_130 ) ;
return;
}
F_151 ( V_4 , V_130 ) ;
F_2 ( ! V_130 -> V_238 ) ;
if ( -- V_130 -> V_87 )
return;
F_150 ( L_44 , V_130 -> V_134 ) ;
V_130 -> V_243 ( V_4 , V_130 ) ;
V_130 -> V_238 = false ;
F_155 ( V_4 , V_241 ) ;
}
static void F_156 ( struct V_3 * V_4 ,
enum V_94 V_94 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_86 * V_13 = V_4 -> V_95 [ V_94 ] ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
T_4 V_97 , V_121 , V_244 ;
F_124 ( ! F_3 ( V_2 ) ) ;
F_151 ( V_4 ,
F_65 ( V_12 ) ) ;
F_157 ( V_4 , V_94 ) ;
F_158 ( V_4 , V_94 ) ;
if ( F_102 ( V_2 ) ) {
V_97 = F_159 ( V_94 ) ;
V_121 = F_4 ( V_97 ) ;
V_121 |= V_245 ;
F_126 ( V_97 , V_121 ) ;
}
V_97 = F_104 ( V_94 ) ;
V_121 = F_4 ( V_97 ) ;
V_244 = F_4 ( F_52 ( V_94 ) ) ;
if ( F_56 ( V_4 -> V_2 ) ) {
V_121 &= ~ V_246 ;
if ( F_9 ( V_12 , V_38 ) )
V_121 |= V_247 ;
else
V_121 |= V_244 & V_246 ;
}
V_121 &= ~ V_248 ;
if ( ( V_244 & V_249 ) == V_250 )
if ( F_56 ( V_4 -> V_2 ) &&
F_9 ( V_12 , V_41 ) )
V_121 |= V_251 ;
else
V_121 |= V_252 ;
else
V_121 |= V_253 ;
F_126 ( V_97 , V_121 | V_178 ) ;
if ( F_53 ( F_4 ( V_97 ) & V_254 , 100 ) )
F_129 ( L_45 , F_77 ( V_94 ) ) ;
}
static void F_160 ( struct V_3 * V_4 ,
enum V_93 V_96 )
{
T_1 V_121 , V_244 ;
F_124 ( ! F_3 ( V_4 -> V_2 ) ) ;
F_157 ( V_4 , (enum V_94 ) V_96 ) ;
F_158 ( V_4 , V_255 ) ;
V_121 = F_4 ( V_256 ) ;
V_121 |= V_245 ;
F_126 ( V_256 , V_121 ) ;
V_121 = V_178 ;
V_244 = F_4 ( F_52 ( V_96 ) ) ;
if ( ( V_244 & V_257 ) ==
V_250 )
V_121 |= V_252 ;
else
V_121 |= V_253 ;
F_126 ( V_258 , V_121 ) ;
if ( F_53 ( F_4 ( V_258 ) & V_254 , 100 ) )
F_129 ( L_46 ) ;
}
static void F_161 ( struct V_3 * V_4 ,
enum V_94 V_94 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_97 , V_121 ;
F_162 ( V_4 , V_94 ) ;
F_163 ( V_4 , V_94 ) ;
F_119 ( V_4 , V_94 ) ;
V_97 = F_104 ( V_94 ) ;
V_121 = F_4 ( V_97 ) ;
V_121 &= ~ V_178 ;
F_126 ( V_97 , V_121 ) ;
if ( F_53 ( ( F_4 ( V_97 ) & V_254 ) == 0 , 50 ) )
F_129 ( L_47 , F_77 ( V_94 ) ) ;
if ( ! F_56 ( V_2 ) ) {
V_97 = F_159 ( V_94 ) ;
V_121 = F_4 ( V_97 ) ;
V_121 &= ~ V_245 ;
F_126 ( V_97 , V_121 ) ;
}
}
static void F_164 ( struct V_3 * V_4 )
{
T_1 V_121 ;
V_121 = F_4 ( V_258 ) ;
V_121 &= ~ V_178 ;
F_126 ( V_258 , V_121 ) ;
if ( F_53 ( ( F_4 ( V_258 ) & V_254 ) == 0 , 50 ) )
F_129 ( L_48 ) ;
V_121 = F_4 ( V_256 ) ;
V_121 &= ~ V_245 ;
F_126 ( V_256 , V_121 ) ;
}
static void F_165 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_94 V_94 = V_13 -> V_94 ;
enum V_93 V_96 = F_46 ( V_4 ,
V_94 ) ;
enum V_94 V_259 ;
int V_97 ;
T_1 V_121 ;
F_150 ( L_49 , F_77 ( V_94 ) ) ;
F_88 ( V_4 , V_94 ) ;
F_166 ( V_4 , V_94 ) ;
F_90 ( V_4 , V_94 ) ;
if ( F_167 ( V_4 -> V_2 ) )
V_259 = V_255 ;
else
V_259 = V_94 ;
if ( F_168 ( V_4 -> V_2 ) )
if ( F_9 ( V_13 , V_260 ) )
F_169 ( V_4 ) ;
else
F_170 ( V_4 , V_94 ) ;
else {
if ( V_13 -> V_90 -> V_261 ) {
F_171 ( V_4 , V_259 ) ;
F_73 ( V_4 ,
(enum V_94 ) V_96 ) ;
}
}
V_97 = F_52 ( V_96 ) ;
V_121 = F_4 ( V_97 ) ;
if ( V_121 & V_163 ) {
F_2 ( ! ( ( V_94 == V_142 && V_4 -> V_160 & V_161 ) ||
( V_94 == V_151 && V_4 -> V_160 & V_162 ) ) ) ;
return;
}
F_126 ( V_97 , V_121 | V_163 ) ;
F_127 ( V_97 ) ;
}
static void F_172 ( struct V_12 * V_13 )
{
struct V_3 * V_4 = V_13 -> V_15 . V_2 -> V_5 ;
enum V_93 V_96 = V_13 -> V_90 -> V_96 ;
enum V_94 V_94 = V_13 -> V_94 ;
int V_97 ;
T_1 V_121 ;
F_150 ( L_50 , F_77 ( V_94 ) ) ;
F_88 ( V_4 , V_94 ) ;
F_166 ( V_4 , V_94 ) ;
F_90 ( V_4 , V_94 ) ;
V_97 = F_52 ( V_96 ) ;
V_121 = F_4 ( V_97 ) ;
if ( ( V_121 & V_163 ) == 0 )
return;
if ( V_13 -> V_90 -> V_262 )
V_121 &= ~ V_263 ;
if ( ! ( V_94 == V_142 && V_4 -> V_160 & V_161 ) &&
! ( V_94 == V_151 && V_4 -> V_160 & V_162 ) )
V_121 &= ~ V_163 ;
F_126 ( V_97 , V_121 ) ;
if ( ( V_121 & V_163 ) == 0 )
F_50 ( V_13 ) ;
}
static bool F_173 ( struct V_1 * V_2 )
{
#ifdef F_174
if ( F_51 ( V_2 ) -> V_103 >= 6 && V_264 )
return true ;
#endif
return false ;
}
unsigned int
F_175 ( struct V_1 * V_2 , T_4 V_265 ,
V_64 V_266 )
{
unsigned int V_267 ;
T_4 V_268 ;
switch ( V_266 ) {
case V_269 :
V_267 = 1 ;
break;
case V_270 :
V_267 = F_23 ( V_2 ) ? 16 : 8 ;
break;
case V_271 :
V_267 = 32 ;
break;
case V_272 :
V_268 = F_176 ( V_265 , 0 ) ;
switch ( V_268 ) {
default:
case 1 :
V_267 = 64 ;
break;
case 2 :
case 4 :
V_267 = 32 ;
break;
case 8 :
V_267 = 16 ;
break;
case 16 :
F_177 ( 1 ,
L_51 ) ;
V_267 = 16 ;
break;
}
break;
default:
F_178 ( V_266 ) ;
V_267 = 1 ;
break;
}
return V_267 ;
}
unsigned int
F_179 ( struct V_1 * V_2 , unsigned int V_273 ,
T_4 V_265 , V_64 V_266 )
{
return F_180 ( V_273 , F_175 ( V_2 , V_265 ,
V_266 ) ) ;
}
static int
F_181 ( struct V_274 * V_275 , struct V_276 * V_89 ,
const struct V_277 * V_278 )
{
struct V_279 * V_280 = & V_275 -> V_281 ;
unsigned int V_267 , V_282 ;
* V_275 = V_283 ;
if ( ! V_278 )
return 0 ;
if ( ! F_182 ( V_278 -> V_284 ) )
return 0 ;
* V_275 = V_285 ;
V_280 -> V_273 = V_89 -> V_273 ;
V_280 -> V_265 = V_89 -> V_265 ;
V_280 -> V_286 = V_89 -> V_287 [ 0 ] ;
V_280 -> V_288 = V_89 -> V_289 [ 0 ] ;
V_267 = F_175 ( V_89 -> V_2 , V_89 -> V_265 ,
V_89 -> V_289 [ 0 ] ) ;
V_282 = V_290 / V_267 ;
V_280 -> V_291 = F_183 ( V_89 -> V_287 [ 0 ] , V_282 ) ;
V_280 -> V_292 = F_183 ( V_89 -> V_273 , V_267 ) ;
V_280 -> V_293 = V_280 -> V_291 * V_280 -> V_292 * V_290 ;
return 0 ;
}
static unsigned int F_184 ( struct V_3 * V_4 )
{
if ( F_51 ( V_4 ) -> V_103 >= 9 )
return 256 * 1024 ;
else if ( F_185 ( V_4 ) || F_186 ( V_4 ) ||
F_22 ( V_4 ) )
return 128 * 1024 ;
else if ( F_51 ( V_4 ) -> V_103 >= 4 )
return 4 * 1024 ;
else
return 0 ;
}
int
F_187 ( struct V_294 * V_164 ,
struct V_276 * V_89 ,
const struct V_277 * V_278 ,
struct V_295 * V_296 ,
struct V_297 * * V_298 )
{
struct V_1 * V_2 = V_89 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_299 * V_300 = F_188 ( V_89 ) ;
struct V_274 V_275 ;
T_1 V_301 ;
int V_302 ;
F_2 ( ! F_189 ( & V_2 -> V_303 ) ) ;
switch ( V_89 -> V_289 [ 0 ] ) {
case V_269 :
V_301 = F_184 ( V_4 ) ;
break;
case V_270 :
if ( F_51 ( V_2 ) -> V_103 >= 9 )
V_301 = 256 * 1024 ;
else {
V_301 = 0 ;
}
break;
case V_271 :
case V_272 :
if ( F_177 ( F_51 ( V_2 ) -> V_103 < 9 ,
L_52 ) )
return - V_304 ;
V_301 = 1 * 1024 * 1024 ;
break;
default:
F_178 ( V_89 -> V_289 [ 0 ] ) ;
return - V_304 ;
}
V_302 = F_181 ( & V_275 , V_89 , V_278 ) ;
if ( V_302 )
return V_302 ;
if ( F_173 ( V_2 ) && V_301 < 256 * 1024 )
V_301 = 256 * 1024 ;
F_190 ( V_4 ) ;
V_4 -> V_305 . V_306 = false ;
V_302 = F_191 ( V_300 , V_301 , V_296 ,
V_298 , & V_275 ) ;
if ( V_302 )
goto V_307;
V_302 = F_192 ( V_300 ) ;
if ( V_302 == - V_308 ) {
V_302 = - V_309 ;
goto V_310;
} else if ( V_302 )
goto V_310;
F_193 ( V_300 ) ;
V_4 -> V_305 . V_306 = true ;
F_194 ( V_4 ) ;
return 0 ;
V_310:
F_195 ( V_300 , & V_275 ) ;
V_307:
V_4 -> V_305 . V_306 = true ;
F_194 ( V_4 ) ;
return V_302 ;
}
static void F_196 ( struct V_276 * V_89 ,
const struct V_277 * V_278 )
{
struct V_299 * V_300 = F_188 ( V_89 ) ;
struct V_274 V_275 ;
int V_302 ;
F_2 ( ! F_189 ( & V_300 -> V_15 . V_2 -> V_303 ) ) ;
V_302 = F_181 ( & V_275 , V_89 , V_278 ) ;
F_177 ( V_302 , L_53 ) ;
F_197 ( V_300 ) ;
F_195 ( V_300 , & V_275 ) ;
}
unsigned long F_198 ( struct V_3 * V_4 ,
int * V_311 , int * V_312 ,
unsigned int V_313 ,
unsigned int V_314 ,
unsigned int V_286 )
{
if ( V_313 != V_315 ) {
unsigned int V_316 , V_317 ;
V_316 = * V_312 / 8 ;
* V_312 %= 8 ;
V_317 = * V_311 / ( 512 / V_314 ) ;
* V_311 %= 512 / V_314 ;
return V_316 * V_286 * 8 + V_317 * 4096 ;
} else {
unsigned int V_301 = F_184 ( V_4 ) - 1 ;
unsigned int V_318 ;
V_318 = * V_312 * V_286 + * V_311 * V_314 ;
* V_312 = ( V_318 & V_301 ) / V_286 ;
* V_311 = ( ( V_318 & V_301 ) - * V_312 * V_286 ) / V_314 ;
return V_318 & ~ V_301 ;
}
}
static int F_199 ( int V_319 )
{
switch ( V_319 ) {
case V_320 :
return V_321 ;
case V_322 :
return V_323 ;
case V_324 :
return V_325 ;
default:
case V_326 :
return V_327 ;
case V_328 :
return V_329 ;
case V_330 :
return V_331 ;
case V_332 :
return V_333 ;
}
}
static int F_200 ( int V_319 , bool V_334 , bool V_335 )
{
switch ( V_319 ) {
case V_336 :
return V_325 ;
default:
case V_337 :
if ( V_334 ) {
if ( V_335 )
return V_338 ;
else
return V_329 ;
} else {
if ( V_335 )
return V_339 ;
else
return V_327 ;
}
case V_340 :
if ( V_334 )
return V_333 ;
else
return V_331 ;
}
}
static bool
F_201 ( struct V_12 * V_13 ,
struct V_341 * V_342 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_299 * V_300 = NULL ;
struct V_343 V_344 = { 0 } ;
struct V_276 * V_89 = & V_342 -> V_89 -> V_15 ;
T_1 V_345 = F_202 ( V_342 -> V_15 , V_290 ) ;
T_1 V_346 = F_203 ( V_342 -> V_15 + V_342 -> V_293 ,
V_290 ) ;
V_346 -= V_345 ;
if ( V_342 -> V_293 == 0 )
return false ;
V_300 = F_204 ( V_2 ,
V_345 ,
V_345 ,
V_346 ) ;
if ( ! V_300 )
return false ;
V_300 -> V_313 = V_342 -> V_347 ;
if ( V_300 -> V_313 == V_348 )
V_300 -> V_349 = V_89 -> V_287 [ 0 ] ;
V_344 . V_265 = V_89 -> V_265 ;
V_344 . V_350 = V_89 -> V_350 ;
V_344 . V_273 = V_89 -> V_273 ;
V_344 . V_287 [ 0 ] = V_89 -> V_287 [ 0 ] ;
V_344 . V_289 [ 0 ] = V_89 -> V_289 [ 0 ] ;
V_344 . V_351 = V_352 ;
F_62 ( & V_2 -> V_303 ) ;
if ( F_205 ( V_2 , F_206 ( V_89 ) ,
& V_344 , V_300 ) ) {
F_150 ( L_54 ) ;
goto V_353;
}
F_64 ( & V_2 -> V_303 ) ;
F_150 ( L_55 , V_300 ) ;
return true ;
V_353:
F_207 ( & V_300 -> V_15 ) ;
F_64 ( & V_2 -> V_303 ) ;
return false ;
}
static void
F_208 ( struct V_294 * V_164 )
{
if ( V_164 -> V_89 == V_164 -> V_11 -> V_89 )
return;
if ( V_164 -> V_11 -> V_89 )
F_209 ( V_164 -> V_11 -> V_89 ) ;
V_164 -> V_11 -> V_89 = V_164 -> V_89 ;
if ( V_164 -> V_11 -> V_89 )
F_210 ( V_164 -> V_11 -> V_89 ) ;
}
static void
F_211 ( struct V_12 * V_12 ,
struct V_341 * V_342 )
{
struct V_1 * V_2 = V_12 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_86 * V_354 ;
struct V_12 * V_25 ;
struct V_299 * V_300 ;
struct V_294 * V_88 = V_12 -> V_15 . V_88 ;
struct V_277 * V_278 = V_88 -> V_11 ;
struct V_276 * V_89 ;
if ( ! V_342 -> V_89 )
return;
if ( F_201 ( V_12 , V_342 ) ) {
V_89 = & V_342 -> V_89 -> V_15 ;
goto V_355;
}
F_212 ( V_342 -> V_89 ) ;
F_213 (dev, c) {
V_25 = F_41 ( V_354 ) ;
if ( V_354 == & V_12 -> V_15 )
continue;
if ( ! V_25 -> V_87 )
continue;
V_89 = V_354 -> V_88 -> V_89 ;
if ( ! V_89 )
continue;
V_300 = F_188 ( V_89 ) ;
if ( F_214 ( V_300 ) == V_342 -> V_15 ) {
F_210 ( V_89 ) ;
goto V_355;
}
}
return;
V_355:
V_278 -> V_356 = V_278 -> V_357 = 0 ;
V_278 -> V_358 = V_89 -> V_350 << 16 ;
V_278 -> V_359 = V_89 -> V_273 << 16 ;
V_278 -> V_360 = V_278 -> V_357 = 0 ;
V_278 -> V_361 = V_89 -> V_350 ;
V_278 -> V_362 = V_89 -> V_273 ;
V_300 = F_188 ( V_89 ) ;
if ( V_300 -> V_313 != V_315 )
V_4 -> V_363 = true ;
F_210 ( V_89 ) ;
V_88 -> V_89 = V_88 -> V_11 -> V_89 = V_89 ;
V_88 -> V_13 = V_88 -> V_11 -> V_13 = & V_12 -> V_15 ;
V_12 -> V_15 . V_11 -> V_364 |= ( 1 << F_215 ( V_88 ) ) ;
V_300 -> V_365 |= F_216 ( V_88 ) -> V_366 ;
}
static void F_217 ( struct V_86 * V_13 ,
struct V_276 * V_89 ,
int V_311 , int V_312 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_294 * V_88 = V_13 -> V_88 ;
bool V_367 = F_218 ( V_88 -> V_11 ) -> V_367 ;
struct V_299 * V_300 ;
int V_164 = V_12 -> V_164 ;
unsigned long V_368 ;
T_1 V_369 ;
T_1 V_97 = F_86 ( V_164 ) ;
int V_370 ;
if ( ! V_367 || ! V_89 ) {
F_126 ( V_97 , 0 ) ;
if ( F_51 ( V_2 ) -> V_103 >= 4 )
F_126 ( F_219 ( V_164 ) , 0 ) ;
else
F_126 ( F_220 ( V_164 ) , 0 ) ;
F_127 ( V_97 ) ;
return;
}
V_300 = F_188 ( V_89 ) ;
if ( F_2 ( V_300 == NULL ) )
return;
V_370 = F_176 ( V_89 -> V_265 , 0 ) ;
V_369 = V_371 ;
V_369 |= V_165 ;
if ( F_51 ( V_2 ) -> V_103 < 4 ) {
if ( V_12 -> V_94 == V_151 )
V_369 |= V_372 ;
F_126 ( F_221 ( V_164 ) ,
( ( V_12 -> V_90 -> V_373 - 1 ) << 16 ) |
( V_12 -> V_90 -> V_374 - 1 ) ) ;
F_126 ( F_222 ( V_164 ) , 0 ) ;
} else if ( F_21 ( V_2 ) && V_164 == V_375 ) {
F_126 ( F_223 ( V_164 ) ,
( ( V_12 -> V_90 -> V_373 - 1 ) << 16 ) |
( V_12 -> V_90 -> V_374 - 1 ) ) ;
F_126 ( F_224 ( V_164 ) , 0 ) ;
F_126 ( F_225 ( V_164 ) , 0 ) ;
}
switch ( V_89 -> V_265 ) {
case V_321 :
V_369 |= V_320 ;
break;
case V_323 :
V_369 |= V_322 ;
break;
case V_325 :
V_369 |= V_324 ;
break;
case V_327 :
V_369 |= V_326 ;
break;
case V_329 :
V_369 |= V_328 ;
break;
case V_331 :
V_369 |= V_330 ;
break;
case V_333 :
V_369 |= V_332 ;
break;
default:
F_144 () ;
}
if ( F_51 ( V_2 ) -> V_103 >= 4 &&
V_300 -> V_313 != V_315 )
V_369 |= V_376 ;
if ( F_19 ( V_2 ) )
V_369 |= V_377 ;
V_368 = V_312 * V_89 -> V_287 [ 0 ] + V_311 * V_370 ;
if ( F_51 ( V_2 ) -> V_103 >= 4 ) {
V_12 -> V_378 =
F_198 ( V_4 ,
& V_311 , & V_312 , V_300 -> V_313 ,
V_370 ,
V_89 -> V_287 [ 0 ] ) ;
V_368 -= V_12 -> V_378 ;
} else {
V_12 -> V_378 = V_368 ;
}
if ( V_13 -> V_88 -> V_11 -> V_284 == F_226 ( V_379 ) ) {
V_369 |= V_380 ;
V_311 += ( V_12 -> V_90 -> V_374 - 1 ) ;
V_312 += ( V_12 -> V_90 -> V_373 - 1 ) ;
V_368 +=
( V_12 -> V_90 -> V_373 - 1 ) * V_89 -> V_287 [ 0 ] +
( V_12 -> V_90 -> V_374 - 1 ) * V_370 ;
}
F_126 ( V_97 , V_369 ) ;
F_126 ( F_227 ( V_164 ) , V_89 -> V_287 [ 0 ] ) ;
if ( F_51 ( V_2 ) -> V_103 >= 4 ) {
F_126 ( F_219 ( V_164 ) ,
F_214 ( V_300 ) + V_12 -> V_378 ) ;
F_126 ( F_228 ( V_164 ) , ( V_312 << 16 ) | V_311 ) ;
F_126 ( F_229 ( V_164 ) , V_368 ) ;
} else
F_126 ( F_220 ( V_164 ) , F_214 ( V_300 ) + V_368 ) ;
F_127 ( V_97 ) ;
}
static void F_230 ( struct V_86 * V_13 ,
struct V_276 * V_89 ,
int V_311 , int V_312 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_294 * V_88 = V_13 -> V_88 ;
bool V_367 = F_218 ( V_88 -> V_11 ) -> V_367 ;
struct V_299 * V_300 ;
int V_164 = V_12 -> V_164 ;
unsigned long V_368 ;
T_1 V_369 ;
T_1 V_97 = F_86 ( V_164 ) ;
int V_370 ;
if ( ! V_367 || ! V_89 ) {
F_126 ( V_97 , 0 ) ;
F_126 ( F_219 ( V_164 ) , 0 ) ;
F_127 ( V_97 ) ;
return;
}
V_300 = F_188 ( V_89 ) ;
if ( F_2 ( V_300 == NULL ) )
return;
V_370 = F_176 ( V_89 -> V_265 , 0 ) ;
V_369 = V_371 ;
V_369 |= V_165 ;
if ( F_231 ( V_2 ) || F_232 ( V_2 ) )
V_369 |= V_381 ;
switch ( V_89 -> V_265 ) {
case V_321 :
V_369 |= V_320 ;
break;
case V_325 :
V_369 |= V_324 ;
break;
case V_327 :
V_369 |= V_326 ;
break;
case V_329 :
V_369 |= V_328 ;
break;
case V_331 :
V_369 |= V_330 ;
break;
case V_333 :
V_369 |= V_332 ;
break;
default:
F_144 () ;
}
if ( V_300 -> V_313 != V_315 )
V_369 |= V_376 ;
if ( ! F_231 ( V_2 ) && ! F_232 ( V_2 ) )
V_369 |= V_377 ;
V_368 = V_312 * V_89 -> V_287 [ 0 ] + V_311 * V_370 ;
V_12 -> V_378 =
F_198 ( V_4 ,
& V_311 , & V_312 , V_300 -> V_313 ,
V_370 ,
V_89 -> V_287 [ 0 ] ) ;
V_368 -= V_12 -> V_378 ;
if ( V_13 -> V_88 -> V_11 -> V_284 == F_226 ( V_379 ) ) {
V_369 |= V_380 ;
if ( ! F_231 ( V_2 ) && ! F_232 ( V_2 ) ) {
V_311 += ( V_12 -> V_90 -> V_374 - 1 ) ;
V_312 += ( V_12 -> V_90 -> V_373 - 1 ) ;
V_368 +=
( V_12 -> V_90 -> V_373 - 1 ) * V_89 -> V_287 [ 0 ] +
( V_12 -> V_90 -> V_374 - 1 ) * V_370 ;
}
}
F_126 ( V_97 , V_369 ) ;
F_126 ( F_227 ( V_164 ) , V_89 -> V_287 [ 0 ] ) ;
F_126 ( F_219 ( V_164 ) ,
F_214 ( V_300 ) + V_12 -> V_378 ) ;
if ( F_231 ( V_2 ) || F_232 ( V_2 ) ) {
F_126 ( F_233 ( V_164 ) , ( V_312 << 16 ) | V_311 ) ;
} else {
F_126 ( F_228 ( V_164 ) , ( V_312 << 16 ) | V_311 ) ;
F_126 ( F_229 ( V_164 ) , V_368 ) ;
}
F_127 ( V_97 ) ;
}
T_1 F_234 ( struct V_1 * V_2 , V_64 V_288 ,
T_4 V_265 )
{
T_1 V_382 = F_176 ( V_265 , 0 ) * 8 ;
switch ( V_288 ) {
case V_269 :
return 64 ;
case V_270 :
if ( F_51 ( V_2 ) -> V_103 == 2 )
return 128 ;
return 512 ;
case V_271 :
return 128 ;
case V_272 :
if ( V_382 == 8 )
return 64 ;
else
return 128 ;
default:
F_178 ( V_288 ) ;
return 64 ;
}
}
unsigned long F_235 ( struct V_383 * V_383 ,
struct V_299 * V_300 )
{
const struct V_274 * V_275 = & V_283 ;
if ( F_182 ( V_383 -> V_15 . V_11 -> V_284 ) )
V_275 = & V_285 ;
return F_236 ( V_300 , V_275 ) ;
}
static void F_237 ( struct V_12 * V_12 , int V_240 )
{
struct V_1 * V_2 = V_12 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_126 ( F_238 ( V_12 -> V_94 , V_240 ) , 0 ) ;
F_126 ( F_239 ( V_12 -> V_94 , V_240 ) , 0 ) ;
F_126 ( F_240 ( V_12 -> V_94 , V_240 ) , 0 ) ;
F_150 ( L_56 ,
V_12 -> V_15 . V_15 . V_240 , V_12 -> V_94 , V_240 ) ;
}
static void F_241 ( struct V_12 * V_12 )
{
struct V_384 * V_385 ;
int V_25 ;
V_385 = & V_12 -> V_90 -> V_385 ;
for ( V_25 = 0 ; V_25 < V_12 -> V_386 ; V_25 ++ ) {
if ( ! V_385 -> V_387 [ V_25 ] . V_388 )
F_237 ( V_12 , V_25 ) ;
}
}
T_1 F_242 ( T_4 V_265 )
{
switch ( V_265 ) {
case V_321 :
return V_389 ;
case V_325 :
return V_336 ;
case V_329 :
return V_337 | V_390 ;
case V_327 :
return V_337 ;
case V_338 :
return V_337 | V_390 |
V_391 ;
case V_339 :
return V_337 |
V_391 ;
case V_331 :
return V_340 ;
case V_333 :
return V_390 | V_340 ;
case V_392 :
return V_393 | V_394 ;
case V_395 :
return V_393 | V_396 ;
case V_397 :
return V_393 | V_398 ;
case V_399 :
return V_393 | V_400 ;
default:
F_178 ( V_265 ) ;
}
return 0 ;
}
T_1 F_243 ( V_64 V_288 )
{
switch ( V_288 ) {
case V_269 :
break;
case V_270 :
return V_401 ;
case V_271 :
return V_402 ;
case V_272 :
return V_403 ;
default:
F_178 ( V_288 ) ;
}
return 0 ;
}
T_1 F_244 ( unsigned int V_284 )
{
switch ( V_284 ) {
case F_226 ( V_404 ) :
break;
case F_226 ( V_405 ) :
return V_406 ;
case F_226 ( V_379 ) :
return V_407 ;
case F_226 ( V_408 ) :
return V_409 ;
default:
F_178 ( V_284 ) ;
}
return 0 ;
}
static void F_245 ( struct V_86 * V_13 ,
struct V_276 * V_89 ,
int V_311 , int V_312 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_294 * V_164 = V_13 -> V_88 ;
bool V_367 = F_218 ( V_164 -> V_11 ) -> V_367 ;
struct V_299 * V_300 ;
int V_94 = V_12 -> V_94 ;
T_1 V_410 , V_411 , V_349 ;
T_1 V_267 , V_412 , V_413 ;
unsigned int V_284 ;
int V_414 , V_415 ;
unsigned long V_416 ;
struct V_18 * V_19 = V_12 -> V_90 ;
struct V_417 * V_278 ;
int V_356 = 0 , V_357 = 0 , V_358 = 0 , V_359 = 0 ;
int V_418 = 0 , V_419 = 0 , V_420 = 0 , V_421 = 0 ;
int V_422 = - 1 ;
V_278 = F_218 ( V_164 -> V_11 ) ;
if ( ! V_367 || ! V_89 ) {
F_126 ( F_92 ( V_94 , 0 ) , 0 ) ;
F_126 ( F_246 ( V_94 , 0 ) , 0 ) ;
F_127 ( F_92 ( V_94 , 0 ) ) ;
return;
}
V_410 = V_170 |
V_423 |
V_424 ;
V_410 |= F_242 ( V_89 -> V_265 ) ;
V_410 |= F_243 ( V_89 -> V_289 [ 0 ] ) ;
V_410 |= V_425 ;
V_284 = V_164 -> V_11 -> V_284 ;
V_410 |= F_244 ( V_284 ) ;
V_300 = F_188 ( V_89 ) ;
V_411 = F_234 ( V_2 , V_89 -> V_289 [ 0 ] ,
V_89 -> V_265 ) ;
V_416 = F_235 ( F_216 ( V_164 ) , V_300 ) ;
if ( F_247 ( & V_278 -> V_426 ) ) {
V_422 = V_278 -> V_422 ;
V_356 = V_278 -> V_426 . V_427 >> 16 ;
V_357 = V_278 -> V_426 . y1 >> 16 ;
V_358 = F_247 ( & V_278 -> V_426 ) >> 16 ;
V_359 = F_248 ( & V_278 -> V_426 ) >> 16 ;
V_418 = V_278 -> V_428 . V_427 ;
V_419 = V_278 -> V_428 . y1 ;
V_420 = F_247 ( & V_278 -> V_428 ) ;
V_421 = F_248 ( & V_278 -> V_428 ) ;
F_2 ( V_311 != V_356 || V_312 != V_357 ) ;
} else {
V_358 = V_12 -> V_90 -> V_374 ;
V_359 = V_12 -> V_90 -> V_373 ;
}
if ( F_182 ( V_284 ) ) {
V_267 = F_175 ( V_2 , V_89 -> V_265 ,
V_89 -> V_289 [ 0 ] ) ;
V_349 = F_183 ( V_89 -> V_273 , V_267 ) ;
V_414 = V_349 * V_267 - V_312 - V_359 ;
V_415 = V_311 ;
V_413 = ( V_358 - 1 ) << 16 | ( V_359 - 1 ) ;
} else {
V_349 = V_89 -> V_287 [ 0 ] / V_411 ;
V_414 = V_311 ;
V_415 = V_312 ;
V_413 = ( V_359 - 1 ) << 16 | ( V_358 - 1 ) ;
}
V_412 = V_415 << 16 | V_414 ;
F_126 ( F_92 ( V_94 , 0 ) , V_410 ) ;
F_126 ( F_249 ( V_94 , 0 ) , V_412 ) ;
F_126 ( F_250 ( V_94 , 0 ) , V_413 ) ;
F_126 ( F_251 ( V_94 , 0 ) , V_349 ) ;
if ( V_422 >= 0 ) {
T_4 V_429 = 0 ;
F_2 ( ! V_420 || ! V_421 ) ;
V_429 = V_430 | F_252 ( 0 ) |
V_19 -> V_385 . V_387 [ V_422 ] . V_431 ;
F_126 ( F_238 ( V_94 , V_422 ) , V_429 ) ;
F_126 ( F_253 ( V_94 , V_422 ) , 0 ) ;
F_126 ( F_239 ( V_94 , V_422 ) , ( V_418 << 16 ) | V_419 ) ;
F_126 ( F_240 ( V_94 , V_422 ) , ( V_420 << 16 ) | V_421 ) ;
F_126 ( F_254 ( V_94 , 0 ) , 0 ) ;
} else {
F_126 ( F_254 ( V_94 , 0 ) , ( V_419 << 16 ) | V_418 ) ;
}
F_126 ( F_246 ( V_94 , 0 ) , V_416 ) ;
F_127 ( F_246 ( V_94 , 0 ) ) ;
}
static int
F_255 ( struct V_86 * V_13 , struct V_276 * V_89 ,
int V_311 , int V_312 , enum V_432 V_11 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_433 . V_434 )
V_4 -> V_433 . V_434 ( V_4 ) ;
V_4 -> V_435 . V_436 ( V_13 , V_89 , V_311 , V_312 ) ;
return 0 ;
}
static void F_256 ( struct V_1 * V_2 )
{
struct V_86 * V_13 ;
F_213 (dev, crtc) {
struct V_12 * V_12 = F_41 ( V_13 ) ;
enum V_164 V_164 = V_12 -> V_164 ;
F_257 ( V_2 , V_164 ) ;
F_258 ( V_2 , V_164 ) ;
}
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_86 * V_13 ;
F_213 (dev, crtc) {
struct V_12 * V_12 = F_41 ( V_13 ) ;
F_260 ( & V_13 -> V_437 , NULL ) ;
if ( V_12 -> V_87 && V_13 -> V_88 -> V_89 )
V_4 -> V_435 . V_436 ( V_13 ,
V_13 -> V_88 -> V_89 ,
V_13 -> V_311 ,
V_13 -> V_312 ) ;
F_261 ( & V_13 -> V_437 ) ;
}
}
void F_262 ( struct V_1 * V_2 )
{
if ( F_23 ( V_2 ) )
return;
if ( F_51 ( V_2 ) -> V_103 >= 5 || F_19 ( V_2 ) )
return;
F_263 ( V_2 ) ;
F_264 ( V_2 ) ;
}
void F_265 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_266 ( V_2 ) ;
F_256 ( V_2 ) ;
if ( F_23 ( V_2 ) )
return;
if ( F_51 ( V_2 ) -> V_103 >= 5 || F_19 ( V_2 ) ) {
F_259 ( V_2 ) ;
return;
}
F_267 ( V_4 ) ;
F_268 ( V_4 ) ;
F_269 ( V_2 ) ;
F_270 ( & V_4 -> V_438 ) ;
if ( V_4 -> V_435 . V_439 )
V_4 -> V_435 . V_439 ( V_2 ) ;
F_271 ( & V_4 -> V_438 ) ;
F_272 ( V_2 ) ;
F_273 ( V_4 ) ;
F_274 ( V_2 ) ;
}
static void
F_275 ( struct V_276 * V_440 )
{
struct V_299 * V_300 = F_188 ( V_440 ) ;
struct V_3 * V_4 = F_266 ( V_300 -> V_15 . V_2 ) ;
bool V_441 = V_4 -> V_305 . V_306 ;
int V_302 ;
V_4 -> V_305 . V_306 = false ;
V_302 = F_276 ( V_300 , true ) ;
V_4 -> V_305 . V_306 = V_441 ;
F_2 ( V_302 ) ;
}
static bool F_277 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
bool V_442 ;
if ( F_278 ( & V_4 -> V_443 ) ||
V_12 -> V_444 != F_279 ( & V_4 -> V_443 . V_444 ) )
return false ;
F_270 ( & V_2 -> V_445 ) ;
V_442 = F_41 ( V_13 ) -> V_446 != NULL ;
F_271 ( & V_2 -> V_445 ) ;
return V_442 ;
}
static void F_280 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_447 * V_91 ;
if ( ! V_448 . V_449 )
return;
V_91 = & V_13 -> V_90 -> V_15 . V_91 ;
F_126 ( F_281 ( V_13 -> V_94 ) ,
( ( V_91 -> V_450 - 1 ) << 16 ) |
( V_91 -> V_451 - 1 ) ) ;
if ( ! V_13 -> V_90 -> V_452 . V_120 &&
( F_9 ( V_13 , V_30 ) ||
F_9 ( V_13 , V_453 ) ) ) {
F_126 ( F_282 ( V_13 -> V_94 ) , 0 ) ;
F_126 ( F_283 ( V_13 -> V_94 ) , 0 ) ;
F_126 ( F_284 ( V_13 -> V_94 ) , 0 ) ;
}
V_13 -> V_90 -> V_374 = V_91 -> V_450 ;
V_13 -> V_90 -> V_373 = V_91 -> V_451 ;
}
static void F_285 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
int V_94 = V_12 -> V_94 ;
T_1 V_97 , V_454 ;
V_97 = F_70 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
if ( F_286 ( V_2 ) ) {
V_454 &= ~ V_455 ;
V_454 |= V_455 | V_456 ;
} else {
V_454 &= ~ V_457 ;
V_454 |= V_457 | V_456 ;
}
F_126 ( V_97 , V_454 ) ;
V_97 = F_72 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
if ( F_102 ( V_2 ) ) {
V_454 &= ~ V_458 ;
V_454 |= V_459 ;
} else {
V_454 &= ~ V_457 ;
V_454 |= V_457 ;
}
F_126 ( V_97 , V_454 | V_460 ) ;
F_127 ( V_97 ) ;
F_128 ( 1000 ) ;
if ( F_286 ( V_2 ) )
F_126 ( V_97 , F_4 ( V_97 ) | V_461 |
V_462 ) ;
}
static void F_287 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
int V_94 = V_12 -> V_94 ;
T_1 V_97 , V_454 , V_463 ;
F_288 ( V_4 , V_94 ) ;
V_97 = F_289 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_464 ;
V_454 &= ~ V_465 ;
F_126 ( V_97 , V_454 ) ;
F_4 ( V_97 ) ;
F_128 ( 150 ) ;
V_97 = F_70 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_466 ;
V_454 |= F_290 ( V_12 -> V_90 -> V_467 ) ;
V_454 &= ~ V_457 ;
V_454 |= V_468 ;
F_126 ( V_97 , V_454 | V_136 ) ;
V_97 = F_72 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_457 ;
V_454 |= V_468 ;
F_126 ( V_97 , V_454 | V_137 ) ;
F_127 ( V_97 ) ;
F_128 ( 150 ) ;
F_126 ( F_291 ( V_94 ) , V_469 ) ;
F_126 ( F_291 ( V_94 ) , V_469 |
V_470 ) ;
V_97 = F_292 ( V_94 ) ;
for ( V_463 = 0 ; V_463 < 5 ; V_463 ++ ) {
V_454 = F_4 ( V_97 ) ;
F_150 ( L_57 , V_454 ) ;
if ( ( V_454 & V_465 ) ) {
F_150 ( L_58 ) ;
F_126 ( V_97 , V_454 | V_465 ) ;
break;
}
}
if ( V_463 == 5 )
F_129 ( L_59 ) ;
V_97 = F_70 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_457 ;
V_454 |= V_471 ;
F_126 ( V_97 , V_454 ) ;
V_97 = F_72 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_457 ;
V_454 |= V_471 ;
F_126 ( V_97 , V_454 ) ;
F_127 ( V_97 ) ;
F_128 ( 150 ) ;
V_97 = F_292 ( V_94 ) ;
for ( V_463 = 0 ; V_463 < 5 ; V_463 ++ ) {
V_454 = F_4 ( V_97 ) ;
F_150 ( L_57 , V_454 ) ;
if ( V_454 & V_464 ) {
F_126 ( V_97 , V_454 | V_464 ) ;
F_150 ( L_60 ) ;
break;
}
}
if ( V_463 == 5 )
F_129 ( L_61 ) ;
F_150 ( L_62 ) ;
}
static void F_293 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
int V_94 = V_12 -> V_94 ;
T_1 V_97 , V_454 , V_25 , V_472 ;
V_97 = F_289 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_464 ;
V_454 &= ~ V_465 ;
F_126 ( V_97 , V_454 ) ;
F_127 ( V_97 ) ;
F_128 ( 150 ) ;
V_97 = F_70 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_466 ;
V_454 |= F_290 ( V_12 -> V_90 -> V_467 ) ;
V_454 &= ~ V_457 ;
V_454 |= V_468 ;
V_454 &= ~ V_473 ;
V_454 |= V_474 ;
F_126 ( V_97 , V_454 | V_136 ) ;
F_126 ( F_294 ( V_94 ) ,
V_475 | V_476 ) ;
V_97 = F_72 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
if ( F_102 ( V_2 ) ) {
V_454 &= ~ V_458 ;
V_454 |= V_477 ;
} else {
V_454 &= ~ V_457 ;
V_454 |= V_468 ;
}
F_126 ( V_97 , V_454 | V_137 ) ;
F_127 ( V_97 ) ;
F_128 ( 150 ) ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_97 = F_70 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_473 ;
V_454 |= V_478 [ V_25 ] ;
F_126 ( V_97 , V_454 ) ;
F_127 ( V_97 ) ;
F_128 ( 500 ) ;
for ( V_472 = 0 ; V_472 < 5 ; V_472 ++ ) {
V_97 = F_292 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
F_150 ( L_57 , V_454 ) ;
if ( V_454 & V_465 ) {
F_126 ( V_97 , V_454 | V_465 ) ;
F_150 ( L_58 ) ;
break;
}
F_128 ( 50 ) ;
}
if ( V_472 < 5 )
break;
}
if ( V_25 == 4 )
F_129 ( L_59 ) ;
V_97 = F_70 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_457 ;
V_454 |= V_471 ;
if ( F_295 ( V_2 ) ) {
V_454 &= ~ V_473 ;
V_454 |= V_474 ;
}
F_126 ( V_97 , V_454 ) ;
V_97 = F_72 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
if ( F_102 ( V_2 ) ) {
V_454 &= ~ V_458 ;
V_454 |= V_479 ;
} else {
V_454 &= ~ V_457 ;
V_454 |= V_471 ;
}
F_126 ( V_97 , V_454 ) ;
F_127 ( V_97 ) ;
F_128 ( 150 ) ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_97 = F_70 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_473 ;
V_454 |= V_478 [ V_25 ] ;
F_126 ( V_97 , V_454 ) ;
F_127 ( V_97 ) ;
F_128 ( 500 ) ;
for ( V_472 = 0 ; V_472 < 5 ; V_472 ++ ) {
V_97 = F_292 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
F_150 ( L_57 , V_454 ) ;
if ( V_454 & V_464 ) {
F_126 ( V_97 , V_454 | V_464 ) ;
F_150 ( L_60 ) ;
break;
}
F_128 ( 50 ) ;
}
if ( V_472 < 5 )
break;
}
if ( V_25 == 4 )
F_129 ( L_61 ) ;
F_150 ( L_63 ) ;
}
static void F_296 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
int V_94 = V_12 -> V_94 ;
T_1 V_97 , V_454 , V_25 , V_480 ;
V_97 = F_289 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_464 ;
V_454 &= ~ V_465 ;
F_126 ( V_97 , V_454 ) ;
F_127 ( V_97 ) ;
F_128 ( 150 ) ;
F_150 ( L_64 ,
F_4 ( F_292 ( V_94 ) ) ) ;
for ( V_480 = 0 ; V_480 < F_297 ( V_478 ) * 2 ; V_480 ++ ) {
V_97 = F_70 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ ( V_481 | V_455 ) ;
V_454 &= ~ V_136 ;
F_126 ( V_97 , V_454 ) ;
V_97 = F_72 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_481 ;
V_454 &= ~ V_458 ;
V_454 &= ~ V_137 ;
F_126 ( V_97 , V_454 ) ;
V_97 = F_70 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_466 ;
V_454 |= F_290 ( V_12 -> V_90 -> V_467 ) ;
V_454 |= V_482 ;
V_454 &= ~ V_473 ;
V_454 |= V_478 [ V_480 / 2 ] ;
V_454 |= V_483 ;
F_126 ( V_97 , V_454 | V_136 ) ;
F_126 ( F_294 ( V_94 ) ,
V_475 | V_476 ) ;
V_97 = F_72 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 |= V_477 ;
V_454 |= V_483 ;
F_126 ( V_97 , V_454 | V_137 ) ;
F_127 ( V_97 ) ;
F_128 ( 1 ) ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_97 = F_292 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
F_150 ( L_57 , V_454 ) ;
if ( V_454 & V_465 ||
( F_4 ( V_97 ) & V_465 ) ) {
F_126 ( V_97 , V_454 | V_465 ) ;
F_150 ( L_65 ,
V_25 ) ;
break;
}
F_128 ( 1 ) ;
}
if ( V_25 == 4 ) {
F_150 ( L_66 , V_480 / 2 ) ;
continue;
}
V_97 = F_70 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_455 ;
V_454 |= V_484 ;
F_126 ( V_97 , V_454 ) ;
V_97 = F_72 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_458 ;
V_454 |= V_479 ;
F_126 ( V_97 , V_454 ) ;
F_127 ( V_97 ) ;
F_128 ( 2 ) ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_97 = F_292 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
F_150 ( L_57 , V_454 ) ;
if ( V_454 & V_464 ||
( F_4 ( V_97 ) & V_464 ) ) {
F_126 ( V_97 , V_454 | V_464 ) ;
F_150 ( L_67 ,
V_25 ) ;
goto V_485;
}
F_128 ( 2 ) ;
}
if ( V_25 == 4 )
F_150 ( L_68 , V_480 / 2 ) ;
}
V_485:
F_150 ( L_63 ) ;
}
static void F_298 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_94 = V_12 -> V_94 ;
T_1 V_97 , V_454 ;
V_97 = F_72 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ ( V_466 | ( 0x7 << 16 ) ) ;
V_454 |= F_290 ( V_12 -> V_90 -> V_467 ) ;
V_454 |= ( F_4 ( F_52 ( V_94 ) ) & V_246 ) << 11 ;
F_126 ( V_97 , V_454 | V_139 ) ;
F_127 ( V_97 ) ;
F_128 ( 200 ) ;
V_454 = F_4 ( V_97 ) ;
F_126 ( V_97 , V_454 | V_486 ) ;
F_127 ( V_97 ) ;
F_128 ( 200 ) ;
V_97 = F_70 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
if ( ( V_454 & V_138 ) == 0 ) {
F_126 ( V_97 , V_454 | V_138 ) ;
F_127 ( V_97 ) ;
F_128 ( 100 ) ;
}
}
static void F_299 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_94 = V_12 -> V_94 ;
T_1 V_97 , V_454 ;
V_97 = F_72 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
F_126 ( V_97 , V_454 & ~ V_486 ) ;
V_97 = F_70 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
F_126 ( V_97 , V_454 & ~ V_138 ) ;
F_127 ( V_97 ) ;
F_128 ( 100 ) ;
V_97 = F_72 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
F_126 ( V_97 , V_454 & ~ V_139 ) ;
F_127 ( V_97 ) ;
F_128 ( 100 ) ;
}
static void F_300 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
int V_94 = V_12 -> V_94 ;
T_1 V_97 , V_454 ;
V_97 = F_70 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
F_126 ( V_97 , V_454 & ~ V_136 ) ;
F_127 ( V_97 ) ;
V_97 = F_72 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ ( 0x7 << 16 ) ;
V_454 |= ( F_4 ( F_52 ( V_94 ) ) & V_246 ) << 11 ;
F_126 ( V_97 , V_454 & ~ V_137 ) ;
F_127 ( V_97 ) ;
F_128 ( 100 ) ;
if ( F_56 ( V_2 ) )
F_126 ( F_291 ( V_94 ) , V_469 ) ;
V_97 = F_70 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ V_457 ;
V_454 |= V_468 ;
F_126 ( V_97 , V_454 ) ;
V_97 = F_72 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
if ( F_102 ( V_2 ) ) {
V_454 &= ~ V_458 ;
V_454 |= V_477 ;
} else {
V_454 &= ~ V_457 ;
V_454 |= V_468 ;
}
V_454 &= ~ ( 0x07 << 16 ) ;
V_454 |= ( F_4 ( F_52 ( V_94 ) ) & V_246 ) << 11 ;
F_126 ( V_97 , V_454 ) ;
F_127 ( V_97 ) ;
F_128 ( 100 ) ;
}
bool F_301 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
F_137 (dev, crtc) {
if ( F_279 ( & V_13 -> V_487 ) == 0 )
continue;
if ( V_13 -> V_446 )
F_302 ( V_2 , V_13 -> V_94 ) ;
return true ;
}
return false ;
}
static void F_303 ( struct V_12 * V_12 )
{
struct V_3 * V_4 = F_266 ( V_12 -> V_15 . V_2 ) ;
struct V_488 * V_489 = V_12 -> V_446 ;
F_304 () ;
V_12 -> V_446 = NULL ;
if ( V_489 -> V_490 )
F_305 ( V_12 -> V_15 . V_2 ,
V_12 -> V_94 ,
V_489 -> V_490 ) ;
F_100 ( & V_12 -> V_15 ) ;
F_306 ( & V_4 -> V_491 ) ;
F_307 ( V_4 -> V_492 , & V_489 -> V_489 ) ;
F_308 ( V_12 -> V_164 ,
V_489 -> V_493 ) ;
}
void F_309 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( F_310 ( & V_4 -> V_491 ) ) ;
if ( F_2 ( F_311 ( V_4 -> V_491 ,
! F_277 ( V_13 ) ,
60 * V_494 ) == 0 ) ) {
struct V_12 * V_12 = F_41 ( V_13 ) ;
F_270 ( & V_2 -> V_445 ) ;
if ( V_12 -> V_446 ) {
F_177 ( 1 , L_69 ) ;
F_303 ( V_12 ) ;
}
F_271 ( & V_2 -> V_445 ) ;
}
if ( V_13 -> V_88 -> V_89 ) {
F_62 ( & V_2 -> V_303 ) ;
F_275 ( V_13 -> V_88 -> V_89 ) ;
F_64 ( & V_2 -> V_303 ) ;
}
}
static void F_312 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int clock = F_41 ( V_13 ) -> V_90 -> V_15 . V_91 . V_92 ;
T_1 V_495 , V_496 , V_497 , V_498 = 0 ;
T_1 V_454 ;
F_62 ( & V_4 -> V_124 ) ;
F_126 ( V_499 , V_500 ) ;
F_313 ( V_4 , V_501 ,
F_314 ( V_4 , V_501 , V_502 ) |
V_503 ,
V_502 ) ;
if ( clock == 20000 ) {
V_497 = 1 ;
V_495 = 0x41 ;
V_496 = 0x20 ;
} else {
T_1 V_504 = 172800 * 1000 ;
T_1 V_505 = 64 ;
T_1 V_506 , V_507 , V_508 ;
V_506 = ( V_504 / clock ) ;
V_507 = V_506 / V_505 ;
V_508 = V_506 % V_505 ;
V_497 = 0 ;
V_495 = V_507 - 2 ;
V_496 = V_508 ;
}
F_2 ( F_315 ( V_495 ) &
~ V_509 ) ;
F_2 ( F_316 ( V_498 ) &
~ V_510 ) ;
F_150 ( L_70 ,
clock ,
V_497 ,
V_495 ,
V_498 ,
V_496 ) ;
V_454 = F_314 ( V_4 , V_511 , V_502 ) ;
V_454 &= ~ V_509 ;
V_454 |= F_315 ( V_495 ) ;
V_454 &= ~ V_510 ;
V_454 |= F_317 ( V_496 ) ;
V_454 |= F_316 ( V_498 ) ;
V_454 |= V_512 ;
F_313 ( V_4 , V_511 , V_454 , V_502 ) ;
V_454 = F_314 ( V_4 , V_513 , V_502 ) ;
V_454 &= ~ F_318 ( 1 ) ;
V_454 |= F_318 ( V_497 ) ;
F_313 ( V_4 , V_513 , V_454 , V_502 ) ;
V_454 = F_314 ( V_4 , V_501 , V_502 ) ;
V_454 &= ~ V_503 ;
F_313 ( V_4 , V_501 , V_454 , V_502 ) ;
F_128 ( 24 ) ;
F_126 ( V_499 , V_514 ) ;
F_64 ( & V_4 -> V_124 ) ;
}
static void F_319 ( struct V_12 * V_13 ,
enum V_94 V_259 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_93 V_96 = V_13 -> V_90 -> V_96 ;
F_126 ( F_320 ( V_259 ) ,
F_4 ( F_321 ( V_96 ) ) ) ;
F_126 ( F_322 ( V_259 ) ,
F_4 ( F_323 ( V_96 ) ) ) ;
F_126 ( F_324 ( V_259 ) ,
F_4 ( F_325 ( V_96 ) ) ) ;
F_126 ( F_326 ( V_259 ) ,
F_4 ( F_327 ( V_96 ) ) ) ;
F_126 ( F_328 ( V_259 ) ,
F_4 ( F_329 ( V_96 ) ) ) ;
F_126 ( F_330 ( V_259 ) ,
F_4 ( F_331 ( V_96 ) ) ) ;
F_126 ( F_332 ( V_259 ) ,
F_4 ( F_333 ( V_96 ) ) ) ;
}
static void F_334 ( struct V_1 * V_2 , bool V_242 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_454 ;
V_454 = F_4 ( V_515 ) ;
if ( ! ! ( V_454 & V_516 ) == V_242 )
return;
F_2 ( F_4 ( F_72 ( V_151 ) ) & V_137 ) ;
F_2 ( F_4 ( F_72 ( V_517 ) ) & V_137 ) ;
V_454 &= ~ V_516 ;
if ( V_242 )
V_454 |= V_516 ;
F_150 ( L_71 , V_242 ? L_72 : L_73 ) ;
F_126 ( V_515 , V_454 ) ;
F_127 ( V_515 ) ;
}
static void F_335 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_15 . V_2 ;
switch ( V_12 -> V_94 ) {
case V_142 :
break;
case V_151 :
if ( V_12 -> V_90 -> V_467 > 2 )
F_334 ( V_2 , false ) ;
else
F_334 ( V_2 , true ) ;
break;
case V_517 :
F_334 ( V_2 , true ) ;
break;
default:
F_144 () ;
}
}
static void F_336 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
int V_94 = V_12 -> V_94 ;
T_1 V_97 , V_454 ;
F_103 ( V_4 , V_94 ) ;
if ( F_286 ( V_2 ) )
F_335 ( V_12 ) ;
F_126 ( F_337 ( V_94 ) ,
F_4 ( F_338 ( V_94 ) ) & V_518 ) ;
V_4 -> V_435 . V_519 ( V_13 ) ;
if ( F_102 ( V_2 ) ) {
T_1 V_520 ;
V_454 = F_4 ( V_521 ) ;
V_454 |= F_339 ( V_94 ) ;
V_520 = F_340 ( V_94 ) ;
if ( V_12 -> V_90 -> V_128 == V_522 )
V_454 |= V_520 ;
else
V_454 &= ~ V_520 ;
F_126 ( V_521 , V_454 ) ;
}
F_149 ( V_12 ) ;
F_75 ( V_4 , V_94 ) ;
F_319 ( V_12 , V_94 ) ;
F_285 ( V_13 ) ;
if ( F_102 ( V_2 ) && V_12 -> V_90 -> V_523 ) {
T_1 V_524 = ( F_4 ( F_52 ( V_94 ) ) & V_246 ) >> 5 ;
V_97 = F_106 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ ( V_182 |
V_525 |
V_526 ) ;
V_454 |= V_527 ;
V_454 |= V_524 << 9 ;
if ( V_13 -> V_431 . V_351 & V_528 )
V_454 |= V_529 ;
if ( V_13 -> V_431 . V_351 & V_530 )
V_454 |= V_531 ;
switch ( F_341 ( V_13 ) ) {
case V_196 :
V_454 |= V_197 ;
break;
case V_198 :
V_454 |= V_199 ;
break;
case V_200 :
V_454 |= V_201 ;
break;
default:
F_144 () ;
}
F_126 ( V_97 , V_454 ) ;
}
F_156 ( V_4 , V_94 ) ;
}
static void F_342 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
enum V_93 V_96 = V_12 -> V_90 -> V_96 ;
F_103 ( V_4 , V_255 ) ;
F_312 ( V_13 ) ;
F_319 ( V_12 , V_142 ) ;
F_160 ( V_4 , V_96 ) ;
}
struct V_127 * F_343 ( struct V_12 * V_13 ,
struct V_18 * V_19 )
{
struct V_3 * V_4 = V_13 -> V_15 . V_2 -> V_5 ;
struct V_127 * V_130 ;
struct V_532 * V_128 ;
enum V_533 V_25 ;
V_128 = F_344 ( V_19 -> V_15 . V_11 ) ;
if ( F_56 ( V_4 -> V_2 ) ) {
V_25 = (enum V_533 ) V_13 -> V_94 ;
V_130 = & V_4 -> V_129 [ V_25 ] ;
F_150 ( L_74 ,
V_13 -> V_15 . V_15 . V_240 , V_130 -> V_134 ) ;
F_2 ( V_128 [ V_25 ] . V_237 ) ;
goto V_76;
}
if ( F_18 ( V_4 -> V_2 ) ) {
struct V_16 * V_17 ;
struct V_105 * V_534 ;
V_17 = F_345 ( V_19 ) ;
if ( F_2 ( ! V_17 ) )
return NULL ;
V_534 = F_346 ( & V_17 -> V_15 ) ;
V_25 = (enum V_533 ) V_534 -> V_106 ;
V_130 = & V_4 -> V_129 [ V_25 ] ;
F_150 ( L_74 ,
V_13 -> V_15 . V_15 . V_240 , V_130 -> V_134 ) ;
F_2 ( V_128 [ V_25 ] . V_237 ) ;
goto V_76;
}
for ( V_25 = 0 ; V_25 < V_4 -> V_535 ; V_25 ++ ) {
V_130 = & V_4 -> V_129 [ V_25 ] ;
if ( V_128 [ V_25 ] . V_237 == 0 )
continue;
if ( memcmp ( & V_19 -> V_211 ,
& V_128 [ V_25 ] . V_132 ,
sizeof( V_19 -> V_211 ) ) == 0 ) {
F_150 ( L_75 ,
V_13 -> V_15 . V_15 . V_240 , V_130 -> V_134 ,
V_128 [ V_25 ] . V_237 ,
V_130 -> V_87 ) ;
goto V_76;
}
}
for ( V_25 = 0 ; V_25 < V_4 -> V_535 ; V_25 ++ ) {
V_130 = & V_4 -> V_129 [ V_25 ] ;
if ( V_128 [ V_25 ] . V_237 == 0 ) {
F_150 ( L_76 ,
V_13 -> V_15 . V_15 . V_240 , V_130 -> V_134 ) ;
goto V_76;
}
}
return NULL ;
V_76:
if ( V_128 [ V_25 ] . V_237 == 0 )
V_128 [ V_25 ] . V_132 =
V_19 -> V_211 ;
V_19 -> V_128 = V_25 ;
F_147 ( L_77 , V_130 -> V_134 ,
F_77 ( V_13 -> V_94 ) ) ;
V_128 [ V_25 ] . V_237 |= 1 << V_13 -> V_94 ;
return V_130 ;
}
static void F_347 ( struct V_20 * V_11 )
{
struct V_3 * V_4 = F_266 ( V_11 -> V_2 ) ;
struct V_532 * V_128 ;
struct V_127 * V_130 ;
enum V_533 V_25 ;
if ( ! F_348 ( V_11 ) -> V_536 )
return;
V_128 = F_348 ( V_11 ) -> V_128 ;
for ( V_25 = 0 ; V_25 < V_4 -> V_535 ; V_25 ++ ) {
V_130 = & V_4 -> V_129 [ V_25 ] ;
V_130 -> V_90 = V_128 [ V_25 ] ;
}
}
static void F_349 ( struct V_1 * V_2 , int V_94 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_537 = F_48 ( V_94 ) ;
T_1 V_454 ;
V_454 = F_4 ( V_537 ) ;
F_128 ( 500 ) ;
if ( F_53 ( F_4 ( V_537 ) != V_454 , 5 ) ) {
if ( F_53 ( F_4 ( V_537 ) != V_454 , 5 ) )
F_129 ( L_78 , F_77 ( V_94 ) ) ;
}
}
static int
F_350 ( struct V_18 * V_19 , bool V_538 ,
unsigned V_539 , int * V_422 , unsigned int V_284 ,
int V_358 , int V_359 , int V_420 , int V_421 )
{
struct V_384 * V_385 =
& V_19 -> V_385 ;
struct V_12 * V_12 =
F_41 ( V_19 -> V_15 . V_13 ) ;
int V_540 ;
V_540 = F_182 ( V_284 ) ?
( V_359 != V_420 || V_358 != V_421 ) :
( V_358 != V_420 || V_359 != V_421 ) ;
if ( V_538 || ! V_540 ) {
if ( * V_422 >= 0 ) {
V_385 -> V_541 &= ~ ( 1 << V_539 ) ;
V_385 -> V_387 [ * V_422 ] . V_388 = 0 ;
F_150 ( L_79
L_80 ,
V_12 -> V_94 , V_539 , * V_422 ,
V_385 -> V_541 ) ;
* V_422 = - 1 ;
}
return 0 ;
}
if ( V_358 < V_542 || V_359 < V_543 ||
V_420 < V_544 || V_421 < V_545 ||
V_358 > V_546 || V_359 > V_547 ||
V_420 > V_548 || V_421 > V_549 ) {
F_150 ( L_81
L_82 ,
V_12 -> V_94 , V_539 , V_358 , V_359 , V_420 , V_421 ) ;
return - V_304 ;
}
V_385 -> V_541 |= ( 1 << V_539 ) ;
F_150 ( L_79
L_83 ,
V_12 -> V_94 , V_539 , V_358 , V_359 , V_420 , V_421 ,
V_385 -> V_541 ) ;
return 0 ;
}
int F_351 ( struct V_18 * V_11 )
{
struct V_12 * V_12 = F_41 ( V_11 -> V_15 . V_13 ) ;
struct V_447 * V_91 =
& V_11 -> V_15 . V_91 ;
F_150 ( L_84 ,
V_12 -> V_15 . V_15 . V_240 , V_12 -> V_94 , V_550 ) ;
return F_350 ( V_11 , ! V_11 -> V_15 . V_87 , V_550 ,
& V_11 -> V_385 . V_422 , V_404 ,
V_11 -> V_374 , V_11 -> V_373 ,
V_91 -> V_551 , V_91 -> V_552 ) ;
}
static int F_352 ( struct V_18 * V_19 ,
struct V_417 * V_278 )
{
struct V_12 * V_12 = F_41 ( V_19 -> V_15 . V_13 ) ;
struct V_383 * V_383 =
F_216 ( V_278 -> V_15 . V_164 ) ;
struct V_276 * V_89 = V_278 -> V_15 . V_89 ;
int V_302 ;
bool V_538 = ! V_89 || ! V_278 -> V_367 ;
F_150 ( L_85 ,
V_383 -> V_15 . V_15 . V_240 , V_12 -> V_94 ,
F_215 ( & V_383 -> V_15 ) ) ;
V_302 = F_350 ( V_19 , V_538 ,
F_215 ( & V_383 -> V_15 ) ,
& V_278 -> V_422 ,
V_278 -> V_15 . V_284 ,
F_247 ( & V_278 -> V_426 ) >> 16 ,
F_248 ( & V_278 -> V_426 ) >> 16 ,
F_247 ( & V_278 -> V_428 ) ,
F_248 ( & V_278 -> V_428 ) ) ;
if ( V_302 || V_278 -> V_422 < 0 )
return V_302 ;
if ( V_278 -> V_553 . V_351 != V_554 ) {
F_150 ( L_86 ,
V_383 -> V_15 . V_15 . V_240 ) ;
return - V_304 ;
}
switch ( V_89 -> V_265 ) {
case V_325 :
case V_329 :
case V_327 :
case V_338 :
case V_339 :
case V_331 :
case V_333 :
case V_392 :
case V_395 :
case V_397 :
case V_399 :
break;
default:
F_150 ( L_87 ,
V_383 -> V_15 . V_15 . V_240 , V_89 -> V_15 . V_240 , V_89 -> V_265 ) ;
return - V_304 ;
}
return 0 ;
}
static void F_353 ( struct V_12 * V_13 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_13 -> V_386 ; V_25 ++ )
F_237 ( V_13 , V_25 ) ;
}
static void F_354 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_94 = V_13 -> V_94 ;
struct V_384 * V_385 =
& V_13 -> V_90 -> V_385 ;
F_150 ( L_88 , V_13 -> V_90 ) ;
if ( V_13 -> V_90 -> V_452 . V_120 ) {
int V_240 ;
if ( F_2 ( V_13 -> V_90 -> V_385 . V_422 < 0 ) ) {
F_129 ( L_89 ) ;
return;
}
V_240 = V_385 -> V_422 ;
F_126 ( F_238 ( V_94 , V_240 ) , V_430 |
V_555 | V_385 -> V_387 [ V_240 ] . V_431 ) ;
F_126 ( F_239 ( V_94 , V_240 ) , V_13 -> V_90 -> V_452 . V_556 ) ;
F_126 ( F_240 ( V_94 , V_240 ) , V_13 -> V_90 -> V_452 . V_293 ) ;
F_150 ( L_90 , V_13 -> V_90 , V_240 ) ;
}
}
static void F_355 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_94 = V_13 -> V_94 ;
if ( V_13 -> V_90 -> V_452 . V_120 ) {
if ( F_286 ( V_2 ) || F_231 ( V_2 ) )
F_126 ( F_282 ( V_94 ) , V_557 | V_558 |
F_356 ( V_94 ) ) ;
else
F_126 ( F_282 ( V_94 ) , V_557 | V_558 ) ;
F_126 ( F_283 ( V_94 ) , V_13 -> V_90 -> V_452 . V_556 ) ;
F_126 ( F_284 ( V_94 ) , V_13 -> V_90 -> V_452 . V_293 ) ;
}
}
void F_357 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_13 -> V_90 -> V_559 )
return;
F_302 ( V_2 , V_13 -> V_94 ) ;
F_358 ( V_4 , V_13 -> V_164 ) ;
if ( F_232 ( V_2 ) ) {
F_62 ( & V_4 -> V_560 . V_561 ) ;
F_2 ( F_359 ( V_4 , V_562 , 0xc0000000 ) ) ;
F_64 ( & V_4 -> V_560 . V_561 ) ;
} else {
F_126 ( V_563 , V_564 ) ;
if ( F_53 ( F_360 ( V_563 ) & V_564 , 50 ) )
F_129 ( L_91 ) ;
}
}
void F_361 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_13 -> V_90 -> V_559 )
return;
F_358 ( V_4 , V_13 -> V_164 ) ;
if ( F_232 ( V_2 ) ) {
F_62 ( & V_4 -> V_560 . V_561 ) ;
F_2 ( F_359 ( V_4 , V_562 , 0 ) ) ;
F_64 ( & V_4 -> V_560 . V_561 ) ;
if ( F_53 ( ( F_4 ( V_563 ) & V_564 ) == 0 , 42 ) )
F_129 ( L_92 ) ;
} else {
F_126 ( V_563 , 0 ) ;
F_127 ( V_563 ) ;
}
F_302 ( V_2 , V_13 -> V_94 ) ;
}
static void F_362 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
enum V_94 V_94 = V_12 -> V_94 ;
int V_565 = F_363 ( V_94 ) ;
int V_25 ;
bool V_566 = false ;
if ( ! V_13 -> V_11 -> V_87 )
return;
if ( F_168 ( V_4 -> V_2 ) ) {
if ( F_9 ( V_12 , V_260 ) )
F_169 ( V_4 ) ;
else
F_170 ( V_4 , V_94 ) ;
}
if ( ! F_168 ( V_2 ) )
V_565 = F_364 ( V_94 ) ;
if ( F_231 ( V_2 ) && V_12 -> V_90 -> V_559 &&
( ( F_4 ( F_365 ( V_94 ) ) & V_567 ) ==
V_568 ) ) {
F_361 ( V_12 ) ;
V_566 = true ;
}
for ( V_25 = 0 ; V_25 < 256 ; V_25 ++ ) {
F_126 ( V_565 + 4 * V_25 ,
( V_12 -> V_569 [ V_25 ] << 16 ) |
( V_12 -> V_570 [ V_25 ] << 8 ) |
V_12 -> V_571 [ V_25 ] ) ;
}
if ( V_566 )
F_357 ( V_12 ) ;
}
static void F_366 ( struct V_12 * V_12 )
{
if ( V_12 -> V_572 ) {
struct V_1 * V_2 = V_12 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_62 ( & V_2 -> V_303 ) ;
V_4 -> V_305 . V_306 = false ;
( void ) F_367 ( V_12 -> V_572 ) ;
V_4 -> V_305 . V_306 = true ;
F_64 ( & V_2 -> V_303 ) ;
}
}
static void
F_368 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
int V_94 = V_12 -> V_94 ;
if ( F_232 ( V_2 ) )
F_302 ( V_2 , V_94 ) ;
F_357 ( V_12 ) ;
if ( F_23 ( V_2 ) )
F_369 ( V_4 , V_94 , true ) ;
if ( F_168 ( V_2 ) )
F_370 ( V_4 ) ;
}
static void
F_371 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
int V_94 = V_12 -> V_94 ;
if ( F_23 ( V_2 ) )
F_369 ( V_4 , V_94 , false ) ;
if ( F_168 ( V_2 ) ) {
F_372 ( V_4 , false ) ;
V_4 -> V_573 . V_574 . V_575 = false ;
F_302 ( V_2 , V_94 ) ;
}
F_361 ( V_12 ) ;
}
static void F_373 ( struct V_12 * V_13 )
{
struct V_576 * V_577 = & V_13 -> V_577 ;
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_294 * V_164 ;
if ( V_577 -> V_578 )
F_302 ( V_2 , V_13 -> V_94 ) ;
F_374 ( V_2 , V_577 -> V_579 ) ;
if ( V_577 -> V_580 )
V_13 -> V_573 . V_581 = true ;
if ( V_13 -> V_577 . V_582 )
F_375 ( & V_13 -> V_15 ) ;
if ( V_577 -> V_583 )
F_376 ( V_4 ) ;
if ( V_577 -> V_584 )
F_368 ( & V_13 -> V_15 ) ;
F_377 (plane, dev, atomic->update_sprite_watermarks)
F_378 ( V_164 , & V_13 -> V_15 ,
0 , 0 , 0 , false , false ) ;
memset ( V_577 , 0 , sizeof( * V_577 ) ) ;
}
static void F_379 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_576 * V_577 = & V_13 -> V_577 ;
struct V_294 * V_56 ;
F_377 (p, dev, atomic->disabled_planes) {
struct V_383 * V_164 = F_216 ( V_56 ) ;
F_62 ( & V_2 -> V_303 ) ;
F_380 ( F_188 ( V_164 -> V_15 . V_89 ) , NULL ,
V_164 -> V_366 ) ;
F_64 ( & V_2 -> V_303 ) ;
}
if ( V_577 -> V_585 )
F_309 ( & V_13 -> V_15 ) ;
if ( V_577 -> V_434 )
F_381 ( V_13 ) ;
if ( V_13 -> V_577 . V_586 )
F_361 ( V_13 ) ;
if ( V_577 -> V_587 )
F_371 ( & V_13 -> V_15 ) ;
if ( V_577 -> V_580 ) {
V_13 -> V_573 . V_581 = false ;
F_372 ( V_4 , false ) ;
}
}
static void F_382 ( struct V_86 * V_13 , unsigned V_364 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_294 * V_56 ;
int V_94 = V_12 -> V_94 ;
F_366 ( V_12 ) ;
F_377 (p, dev, plane_mask)
F_216 ( V_56 ) -> F_383 ( V_56 , V_13 ) ;
F_374 ( V_2 , F_384 ( V_94 ) ) ;
}
static void F_385 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_16 * V_17 ;
int V_94 = V_12 -> V_94 ;
if ( F_2 ( V_12 -> V_87 ) )
return;
if ( V_12 -> V_90 -> V_261 )
F_146 ( V_12 ) ;
if ( V_12 -> V_90 -> V_523 )
F_386 ( V_12 , V_588 ) ;
F_387 ( V_12 ) ;
if ( V_12 -> V_90 -> V_261 ) {
F_388 ( V_12 ,
& V_12 -> V_90 -> V_589 , NULL ) ;
}
F_389 ( V_13 ) ;
V_12 -> V_87 = true ;
F_369 ( V_4 , V_94 , true ) ;
F_390 ( V_4 , V_94 , true ) ;
F_10 (dev, crtc, encoder)
if ( V_17 -> V_590 )
V_17 -> V_590 ( V_17 ) ;
if ( V_12 -> V_90 -> V_261 ) {
F_298 ( V_12 ) ;
} else {
F_162 ( V_4 , V_94 ) ;
F_163 ( V_4 , V_94 ) ;
}
F_355 ( V_12 ) ;
F_362 ( V_13 ) ;
F_375 ( V_13 ) ;
F_165 ( V_12 ) ;
if ( V_12 -> V_90 -> V_261 )
F_336 ( V_13 ) ;
F_97 ( V_13 ) ;
F_391 ( V_13 ) ;
F_10 (dev, crtc, encoder)
V_17 -> V_242 ( V_17 ) ;
if ( F_102 ( V_2 ) )
F_349 ( V_2 , V_12 -> V_94 ) ;
}
static bool F_392 ( struct V_12 * V_13 )
{
return F_393 ( V_13 -> V_15 . V_2 ) && V_13 -> V_94 == V_142 ;
}
static void F_394 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_16 * V_17 ;
int V_94 = V_12 -> V_94 , V_591 ;
struct V_18 * V_210 =
F_395 ( V_13 -> V_11 ) ;
if ( F_2 ( V_12 -> V_87 ) )
return;
if ( F_65 ( V_12 ) )
F_149 ( V_12 ) ;
if ( V_12 -> V_90 -> V_523 )
F_386 ( V_12 , V_588 ) ;
F_387 ( V_12 ) ;
if ( V_12 -> V_90 -> V_96 != V_592 ) {
F_126 ( F_396 ( V_12 -> V_90 -> V_96 ) ,
V_12 -> V_90 -> V_593 - 1 ) ;
}
if ( V_12 -> V_90 -> V_261 ) {
F_388 ( V_12 ,
& V_12 -> V_90 -> V_589 , NULL ) ;
}
F_397 ( V_13 ) ;
F_398 ( V_13 ) ;
V_12 -> V_87 = true ;
F_369 ( V_4 , V_94 , true ) ;
F_10 (dev, crtc, encoder)
if ( V_17 -> V_590 )
V_17 -> V_590 ( V_17 ) ;
if ( V_12 -> V_90 -> V_261 ) {
F_390 ( V_4 , V_255 ,
true ) ;
V_4 -> V_435 . V_519 ( V_13 ) ;
}
F_399 ( V_12 ) ;
if ( F_51 ( V_2 ) -> V_103 == 9 )
F_354 ( V_12 ) ;
else if ( F_51 ( V_2 ) -> V_103 < 9 )
F_355 ( V_12 ) ;
else
F_178 ( F_51 ( V_2 ) -> V_103 ) ;
F_362 ( V_13 ) ;
F_400 ( V_13 ) ;
F_401 ( V_13 ) ;
F_375 ( V_13 ) ;
F_165 ( V_12 ) ;
if ( V_12 -> V_90 -> V_261 )
F_342 ( V_13 ) ;
if ( V_12 -> V_90 -> V_594 )
F_402 ( V_13 , true ) ;
F_97 ( V_13 ) ;
F_391 ( V_13 ) ;
F_10 (dev, crtc, encoder) {
V_17 -> V_242 ( V_17 ) ;
F_403 ( V_17 , true ) ;
}
V_591 = V_210 -> V_591 ;
if ( F_231 ( V_2 ) && V_591 != V_595 ) {
F_302 ( V_2 , V_591 ) ;
F_302 ( V_2 , V_591 ) ;
}
}
static void F_404 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_94 = V_13 -> V_94 ;
if ( V_13 -> V_90 -> V_452 . V_120 ) {
F_126 ( F_282 ( V_94 ) , 0 ) ;
F_126 ( F_283 ( V_94 ) , 0 ) ;
F_126 ( F_284 ( V_94 ) , 0 ) ;
}
}
static void F_405 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_16 * V_17 ;
int V_94 = V_12 -> V_94 ;
T_1 V_97 , V_454 ;
F_10 (dev, crtc, encoder)
V_17 -> V_243 ( V_17 ) ;
F_406 ( V_13 ) ;
F_97 ( V_13 ) ;
if ( V_12 -> V_90 -> V_261 )
F_390 ( V_4 , V_94 , false ) ;
F_172 ( V_12 ) ;
F_404 ( V_12 ) ;
if ( V_12 -> V_90 -> V_261 )
F_300 ( V_13 ) ;
F_10 (dev, crtc, encoder)
if ( V_17 -> V_596 )
V_17 -> V_596 ( V_17 ) ;
if ( V_12 -> V_90 -> V_261 ) {
F_161 ( V_4 , V_94 ) ;
if ( F_102 ( V_2 ) ) {
V_97 = F_106 ( V_94 ) ;
V_454 = F_4 ( V_97 ) ;
V_454 &= ~ ( V_527 |
V_182 ) ;
V_454 |= V_597 ;
F_126 ( V_97 , V_454 ) ;
V_454 = F_4 ( V_521 ) ;
V_454 &= ~ ( F_339 ( V_94 ) | F_340 ( V_94 ) ) ;
F_126 ( V_521 , V_454 ) ;
}
F_299 ( V_12 ) ;
}
V_12 -> V_87 = false ;
F_375 ( V_13 ) ;
}
static void F_407 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_16 * V_17 ;
enum V_93 V_96 = V_12 -> V_90 -> V_96 ;
F_10 (dev, crtc, encoder) {
F_403 ( V_17 , false ) ;
V_17 -> V_243 ( V_17 ) ;
}
F_406 ( V_13 ) ;
F_97 ( V_13 ) ;
if ( V_12 -> V_90 -> V_261 )
F_390 ( V_4 , V_255 ,
false ) ;
F_172 ( V_12 ) ;
if ( V_12 -> V_90 -> V_594 )
F_402 ( V_13 , false ) ;
F_408 ( V_4 , V_96 ) ;
if ( F_51 ( V_2 ) -> V_103 == 9 )
F_353 ( V_12 ) ;
else if ( F_51 ( V_2 ) -> V_103 < 9 )
F_404 ( V_12 ) ;
else
F_178 ( F_51 ( V_2 ) -> V_103 ) ;
F_409 ( V_12 ) ;
if ( V_12 -> V_90 -> V_261 ) {
F_164 ( V_4 ) ;
F_410 ( V_13 ) ;
}
F_10 (dev, crtc, encoder)
if ( V_17 -> V_596 )
V_17 -> V_596 ( V_17 ) ;
V_12 -> V_87 = false ;
F_375 ( V_13 ) ;
}
static void F_411 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_18 * V_210 = V_13 -> V_90 ;
if ( ! V_210 -> V_598 . V_599 )
return;
F_2 ( F_4 ( V_600 ) & V_601 ) ;
F_123 ( V_4 , V_13 -> V_94 ) ;
F_126 ( V_602 , V_210 -> V_598 . V_603 ) ;
F_126 ( V_600 , V_210 -> V_598 . V_599 ) ;
F_126 ( F_412 ( V_13 -> V_94 ) , 0 ) ;
}
static enum V_604 F_413 ( enum V_106 V_106 )
{
switch ( V_106 ) {
case V_605 :
return V_606 ;
case V_108 :
return V_607 ;
case V_110 :
return V_608 ;
case V_112 :
return V_609 ;
case V_117 :
return V_610 ;
default:
F_38 ( 1 ) ;
return V_611 ;
}
}
enum V_604
F_414 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_15 . V_2 ;
struct V_105 * V_534 ;
switch ( V_16 -> type ) {
case V_612 :
F_38 ( ! F_68 ( V_2 ) ) ;
case V_613 :
case V_38 :
case V_453 :
V_534 = F_346 ( & V_16 -> V_15 ) ;
return F_413 ( V_534 -> V_106 ) ;
case V_614 :
V_534 = F_415 ( & V_16 -> V_15 ) -> V_88 ;
return F_413 ( V_534 -> V_106 ) ;
case V_39 :
return V_615 ;
case V_260 :
return V_616 ;
default:
return V_611 ;
}
}
static unsigned long F_416 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_16 * V_16 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
enum V_94 V_94 = V_12 -> V_94 ;
unsigned long V_617 ;
enum V_93 V_93 ;
if ( ! V_13 -> V_11 -> V_87 )
return 0 ;
V_93 = F_46 ( V_2 -> V_5 , V_94 ) ;
V_617 = F_226 ( F_417 ( V_94 ) ) ;
V_617 |= F_226 ( F_84 ( V_93 ) ) ;
if ( V_12 -> V_90 -> V_452 . V_120 ||
V_12 -> V_90 -> V_452 . V_618 )
V_617 |= F_226 ( F_418 ( V_94 ) ) ;
F_10 (dev, crtc, intel_encoder)
V_617 |= F_226 ( F_414 ( V_16 ) ) ;
return V_617 ;
}
static unsigned long F_419 ( struct V_86 * V_13 )
{
struct V_3 * V_4 = V_13 -> V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
enum V_604 V_619 ;
unsigned long V_620 , V_621 , V_622 ;
V_622 = V_12 -> V_623 ;
V_12 -> V_623 = V_621 = F_416 ( V_13 ) ;
V_620 = V_621 & ~ V_622 ;
F_420 (domain, domains)
F_152 ( V_4 , V_619 ) ;
return V_622 & ~ V_621 ;
}
static void F_421 ( struct V_3 * V_4 ,
unsigned long V_620 )
{
enum V_604 V_619 ;
F_420 (domain, domains)
F_155 ( V_4 , V_619 ) ;
}
static void F_422 ( struct V_20 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_624 [ V_625 ] = {} ;
struct V_10 * V_19 ;
struct V_86 * V_13 ;
int V_25 ;
F_423 (state, crtc, crtc_state, i) {
if ( F_7 ( V_13 -> V_11 ) )
V_624 [ F_41 ( V_13 ) -> V_94 ] =
F_419 ( V_13 ) ;
}
if ( V_4 -> V_435 . V_626 ) {
unsigned int V_627 = F_348 ( V_11 ) -> V_627 ;
if ( V_627 != V_4 -> V_628 &&
! F_2 ( ! V_11 -> V_629 ) )
V_4 -> V_435 . V_626 ( V_11 ) ;
}
for ( V_25 = 0 ; V_25 < V_625 ; V_25 ++ )
if ( V_624 [ V_25 ] )
F_421 ( V_4 , V_624 [ V_25 ] ) ;
}
static void F_424 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_425 ( V_2 ) ) {
T_1 V_29 = F_4 ( V_630 ) & V_631 ;
if ( V_29 == V_632 )
V_4 -> V_633 = 675000 ;
else if ( V_29 == V_634 )
V_4 -> V_633 = 540000 ;
else if ( V_29 == V_635 )
V_4 -> V_633 = 450000 ;
else
V_4 -> V_633 = 337500 ;
} else if ( F_232 ( V_2 ) ) {
if ( F_4 ( V_636 ) & V_637 )
V_4 -> V_633 = 450000 ;
else if ( F_426 ( V_2 ) )
V_4 -> V_633 = 450000 ;
else if ( F_427 ( V_2 ) )
V_4 -> V_633 = 540000 ;
else
V_4 -> V_633 = 675000 ;
} else if ( F_21 ( V_2 ) ) {
V_4 -> V_633 = 320000 ;
} else if ( F_22 ( V_2 ) ) {
V_4 -> V_633 = 400000 ;
} else {
V_4 -> V_633 = V_4 -> V_628 ;
}
F_147 ( L_93 ,
V_4 -> V_633 ) ;
}
static void F_428 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_628 = V_4 -> V_435 . V_638 ( V_2 ) ;
F_147 ( L_94 ,
V_4 -> V_628 ) ;
if ( F_22 ( V_2 ) ) {
F_126 ( V_639 , F_183 ( V_4 -> V_628 , 1000 ) ) ;
}
if ( V_4 -> V_633 == 0 )
F_424 ( V_2 ) ;
}
static void F_429 ( struct V_1 * V_2 , int V_640 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_641 ;
T_4 V_642 ;
T_4 V_643 ;
int V_302 ;
switch ( V_640 ) {
case 144000 :
V_641 = V_644 ;
V_642 = F_430 ( 60 ) ;
break;
case 288000 :
V_641 = V_645 ;
V_642 = F_430 ( 60 ) ;
break;
case 384000 :
V_641 = V_646 ;
V_642 = F_430 ( 60 ) ;
break;
case 576000 :
V_641 = V_647 ;
V_642 = F_430 ( 60 ) ;
break;
case 624000 :
V_641 = V_647 ;
V_642 = F_430 ( 65 ) ;
break;
case 19200 :
V_642 = 0 ;
V_641 = 0 ;
break;
default:
F_129 ( L_95 , V_640 ) ;
return;
}
F_62 ( & V_4 -> V_560 . V_561 ) ;
V_302 = F_359 ( V_4 , V_648 ,
0x80000000 ) ;
F_64 ( & V_4 -> V_560 . V_561 ) ;
if ( V_302 ) {
F_129 ( L_96 ,
V_302 , V_640 ) ;
return;
}
V_643 = F_4 ( V_649 ) & V_650 ;
V_643 = V_643 * 500 + 1000 ;
if ( V_640 == 19200 || V_640 == 624000 ||
V_643 == 624000 ) {
F_126 ( V_651 , ~ V_652 ) ;
if ( F_53 ( ! ( F_4 ( V_651 ) & V_653 ) ,
1 ) )
F_129 ( L_97 ) ;
}
if ( V_640 != 19200 ) {
T_4 V_121 ;
V_121 = F_4 ( V_654 ) ;
V_121 &= ~ V_655 ;
V_121 |= V_642 ;
F_126 ( V_654 , V_121 ) ;
F_126 ( V_651 , V_652 ) ;
if ( F_53 ( F_4 ( V_651 ) & V_653 , 1 ) )
F_129 ( L_98 ) ;
V_121 = F_4 ( V_649 ) ;
V_121 &= ~ V_656 ;
V_121 |= V_641 ;
V_121 &= ~ V_657 ;
if ( V_640 >= 500000 )
V_121 |= V_657 ;
V_121 &= ~ V_650 ;
V_121 |= ( V_640 - 1000 ) / 500 ;
F_126 ( V_649 , V_121 ) ;
}
F_62 ( & V_4 -> V_560 . V_561 ) ;
V_302 = F_359 ( V_4 , V_648 ,
F_183 ( V_640 , 25000 ) ) ;
F_64 ( & V_4 -> V_560 . V_561 ) ;
if ( V_302 ) {
F_129 ( L_99 ,
V_302 , V_640 ) ;
return;
}
F_428 ( V_2 ) ;
}
void F_431 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_121 ;
V_121 = F_4 ( V_658 ) ;
V_121 &= ~ V_659 ;
F_126 ( V_658 , V_121 ) ;
F_152 ( V_4 , V_241 ) ;
if ( F_4 ( V_651 ) & V_652 ) {
F_150 ( L_100 ) ;
return;
}
F_429 ( V_2 , 624000 ) ;
F_126 ( V_660 , F_4 ( V_660 ) | V_661 ) ;
F_127 ( V_660 ) ;
F_128 ( 10 ) ;
if ( ! ( F_4 ( V_660 ) & V_662 ) )
F_129 ( L_101 ) ;
}
void F_432 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_126 ( V_660 , F_4 ( V_660 ) & ~ V_661 ) ;
F_127 ( V_660 ) ;
F_128 ( 10 ) ;
if ( F_4 ( V_660 ) & V_662 )
F_129 ( L_102 ) ;
F_429 ( V_2 , 19200 ) ;
F_155 ( V_4 , V_241 ) ;
}
static unsigned int F_433 ( unsigned int V_663 )
{
return ( V_663 - 1000 ) / 500 ;
}
static unsigned int F_434 ( unsigned int V_663 )
{
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < F_297 ( V_664 ) ; V_25 ++ ) {
const struct V_665 * V_666 = & V_664 [ V_25 ] ;
if ( V_666 -> V_663 == V_663 )
return V_666 -> V_60 ;
}
return 8100 ;
}
static void
F_435 ( struct V_3 * V_4 , unsigned int V_667 )
{
unsigned int V_668 ;
T_1 V_121 ;
V_121 = F_4 ( V_649 ) ;
V_121 &= ~ V_669 | ~ V_650 ;
V_121 |= V_670 ;
if ( V_667 == 8640 )
V_668 = 308570 ;
else
V_668 = 337500 ;
V_121 = V_670 | F_433 ( V_668 ) ;
F_126 ( V_649 , V_121 ) ;
F_127 ( V_649 ) ;
V_121 = F_4 ( V_671 ) ;
V_121 &= ~ ( F_436 ( V_672 ) | F_437 ( V_672 ) |
F_438 ( V_672 ) ) ;
V_121 |= F_439 ( V_672 ) ;
if ( V_667 == 8640 )
V_121 |= F_440 ( V_673 ,
V_672 ) ;
else
V_121 |= F_440 ( V_674 ,
V_672 ) ;
F_126 ( V_671 , V_121 ) ;
F_127 ( V_671 ) ;
F_126 ( V_675 , F_4 ( V_675 ) | V_676 ) ;
if ( F_53 ( F_4 ( V_675 ) & V_677 , 5 ) )
F_129 ( L_103 ) ;
}
static bool F_441 ( struct V_3 * V_4 )
{
int V_302 ;
T_1 V_121 ;
V_121 = V_678 ;
F_62 ( & V_4 -> V_560 . V_561 ) ;
V_302 = F_442 ( V_4 , V_679 , & V_121 ) ;
F_64 ( & V_4 -> V_560 . V_561 ) ;
return V_302 == 0 && ( V_121 & V_680 ) ;
}
static bool F_443 ( struct V_3 * V_4 )
{
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < 15 ; V_25 ++ ) {
if ( F_441 ( V_4 ) )
return true ;
F_128 ( 10 ) ;
}
return false ;
}
static void F_444 ( struct V_3 * V_4 , unsigned int V_663 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_1 V_681 , V_682 ;
F_147 ( L_104 , V_663 ) ;
if ( ! F_443 ( V_4 ) ) {
F_129 ( L_105 ) ;
return;
}
switch( V_663 ) {
case 450000 :
case 432000 :
V_681 = V_683 ;
V_682 = 1 ;
break;
case 540000 :
V_681 = V_684 ;
V_682 = 2 ;
break;
case 308570 :
case 337500 :
default:
V_681 = V_670 ;
V_682 = 0 ;
break;
case 617140 :
case 675000 :
V_681 = V_685 ;
V_682 = 3 ;
break;
}
F_126 ( V_649 , V_681 | F_433 ( V_663 ) ) ;
F_127 ( V_649 ) ;
F_62 ( & V_4 -> V_560 . V_561 ) ;
F_359 ( V_4 , V_679 , V_682 ) ;
F_64 ( & V_4 -> V_560 . V_561 ) ;
F_428 ( V_2 ) ;
}
void F_445 ( struct V_3 * V_4 )
{
F_126 ( V_660 , F_4 ( V_660 ) & ~ V_661 ) ;
F_127 ( V_660 ) ;
F_128 ( 10 ) ;
if ( F_4 ( V_660 ) & V_662 )
F_129 ( L_106 ) ;
F_126 ( V_675 , F_4 ( V_675 ) & ~ V_676 ) ;
if ( F_53 ( ! ( F_4 ( V_675 ) & V_677 ) , 1 ) )
F_129 ( L_107 ) ;
F_155 ( V_4 , V_241 ) ;
}
void F_446 ( struct V_3 * V_4 )
{
T_1 V_121 ;
unsigned int V_667 ;
V_121 = F_4 ( V_658 ) ;
F_126 ( V_658 , V_121 | V_659 ) ;
F_152 ( V_4 , V_241 ) ;
if ( ! ( F_4 ( V_675 ) & V_676 ) ) {
V_667 = F_434 ( V_4 -> V_686 ) ;
F_435 ( V_4 , V_667 ) ;
}
F_444 ( V_4 , V_4 -> V_686 ) ;
F_126 ( V_660 , F_4 ( V_660 ) | V_661 ) ;
F_127 ( V_660 ) ;
F_128 ( 10 ) ;
if ( ! ( F_4 ( V_660 ) & V_662 ) )
F_129 ( L_108 ) ;
}
static int F_447 ( struct V_3 * V_4 )
{
int V_687 , V_688 [] = { 800 , 1600 , 2000 , 2400 } ;
F_62 ( & V_4 -> V_124 ) ;
V_687 = F_63 ( V_4 , V_689 ) &
V_690 ;
F_64 ( & V_4 -> V_124 ) ;
return V_688 [ V_687 ] * 1000 ;
}
static void F_448 ( struct V_1 * V_2 , int V_627 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_121 , V_691 ;
F_2 ( V_4 -> V_435 . V_638 ( V_2 )
!= V_4 -> V_628 ) ;
if ( V_627 >= 320000 )
V_691 = 2 ;
else if ( V_627 == 266667 )
V_691 = 1 ;
else
V_691 = 0 ;
F_62 ( & V_4 -> V_560 . V_561 ) ;
V_121 = F_449 ( V_4 , V_692 ) ;
V_121 &= ~ V_693 ;
V_121 |= ( V_691 << V_694 ) ;
F_450 ( V_4 , V_692 , V_121 ) ;
if ( F_53 ( ( F_449 ( V_4 , V_692 ) &
V_695 ) == ( V_691 << V_696 ) ,
50 ) ) {
F_129 ( L_109 ) ;
}
F_64 ( & V_4 -> V_560 . V_561 ) ;
F_62 ( & V_4 -> V_124 ) ;
if ( V_627 == 400000 ) {
T_1 V_641 ;
V_641 = F_25 ( V_4 -> V_687 << 1 , V_627 ) - 1 ;
V_121 = F_63 ( V_4 , V_697 ) ;
V_121 &= ~ V_698 ;
V_121 |= V_641 ;
F_451 ( V_4 , V_697 , V_121 ) ;
if ( F_53 ( ( F_63 ( V_4 , V_697 ) &
V_699 ) == ( V_641 << V_700 ) ,
50 ) )
F_129 ( L_109 ) ;
}
V_121 = F_452 ( V_4 , V_701 ) ;
V_121 &= ~ 0x7f ;
if ( V_627 == 400000 )
V_121 |= 4500 / 250 ;
else
V_121 |= 3000 / 250 ;
F_453 ( V_4 , V_701 , V_121 ) ;
F_64 ( & V_4 -> V_124 ) ;
F_428 ( V_2 ) ;
}
static void F_454 ( struct V_1 * V_2 , int V_627 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_121 , V_691 ;
F_2 ( V_4 -> V_435 . V_638 ( V_2 )
!= V_4 -> V_628 ) ;
switch ( V_627 ) {
case 333333 :
case 320000 :
case 266667 :
case 200000 :
break;
default:
F_178 ( V_627 ) ;
return;
}
V_691 = F_25 ( V_4 -> V_687 << 1 , V_627 ) - 1 ;
F_62 ( & V_4 -> V_560 . V_561 ) ;
V_121 = F_449 ( V_4 , V_692 ) ;
V_121 &= ~ V_702 ;
V_121 |= ( V_691 << V_703 ) ;
F_450 ( V_4 , V_692 , V_121 ) ;
if ( F_53 ( ( F_449 ( V_4 , V_692 ) &
V_704 ) == ( V_691 << V_705 ) ,
50 ) ) {
F_129 ( L_109 ) ;
}
F_64 ( & V_4 -> V_560 . V_561 ) ;
F_428 ( V_2 ) ;
}
static int F_455 ( struct V_3 * V_4 ,
int V_706 )
{
int V_707 = ( V_4 -> V_687 << 1 ) % 320000 != 0 ? 333333 : 320000 ;
int V_29 = F_21 ( V_4 ) ? 95 : 90 ;
if ( ! F_21 ( V_4 ) &&
V_706 > V_707 * V_29 / 100 )
return 400000 ;
else if ( V_706 > 266667 * V_29 / 100 )
return V_707 ;
else if ( V_706 > 0 )
return 266667 ;
else
return 200000 ;
}
static int F_456 ( struct V_3 * V_4 ,
int V_706 )
{
if ( V_706 > 576000 * 9 / 10 )
return 624000 ;
else if ( V_706 > 384000 * 9 / 10 )
return 576000 ;
else if ( V_706 > 288000 * 9 / 10 )
return 384000 ;
else if ( V_706 > 144000 * 9 / 10 )
return 288000 ;
else
return 144000 ;
}
static int F_457 ( struct V_1 * V_2 ,
struct V_20 * V_11 )
{
struct V_12 * V_12 ;
struct V_18 * V_19 ;
int V_706 = 0 ;
F_137 (dev, intel_crtc) {
V_19 = F_458 ( V_11 , V_12 ) ;
if ( F_459 ( V_19 ) )
return F_460 ( V_19 ) ;
if ( ! V_19 -> V_15 . V_242 )
continue;
V_706 = V_66 ( V_706 ,
V_19 -> V_15 . V_91 . V_92 ) ;
}
return V_706 ;
}
static int F_461 ( struct V_20 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_706 = F_457 ( V_2 , V_11 ) ;
if ( V_706 < 0 )
return V_706 ;
F_348 ( V_11 ) -> V_627 =
F_455 ( V_4 , V_706 ) ;
return 0 ;
}
static int F_462 ( struct V_20 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_706 = F_457 ( V_2 , V_11 ) ;
if ( V_706 < 0 )
return V_706 ;
F_348 ( V_11 ) -> V_627 =
F_456 ( V_4 , V_706 ) ;
return 0 ;
}
static void F_463 ( struct V_3 * V_4 )
{
unsigned int V_708 , V_709 ;
if ( F_21 ( V_4 ) )
V_709 = F_464 ( 12 ) ;
else
V_709 = F_464 ( 8 ) ;
if ( F_25 ( V_4 -> V_628 , 1000 ) >= V_4 -> V_560 . V_710 ) {
if ( F_21 ( V_4 ) )
V_708 = V_711 ;
else
V_708 = F_464 ( 15 ) ;
} else {
V_708 = V_709 ;
}
F_126 ( V_712 , V_713 |
V_709 ) ;
F_126 ( V_712 , V_713 |
V_708 | V_714 ) ;
F_2 ( F_4 ( V_712 ) & V_714 ) ;
}
static void F_465 ( struct V_20 * V_715 )
{
struct V_1 * V_2 = V_715 -> V_2 ;
unsigned int V_716 = F_348 ( V_715 ) -> V_627 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_152 ( V_4 , V_717 ) ;
if ( F_21 ( V_2 ) )
F_454 ( V_2 , V_716 ) ;
else
F_448 ( V_2 , V_716 ) ;
F_463 ( V_4 ) ;
F_155 ( V_4 , V_717 ) ;
}
static void F_466 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = F_266 ( V_2 ) ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_16 * V_17 ;
int V_94 = V_12 -> V_94 ;
bool V_718 ;
if ( F_2 ( V_12 -> V_87 ) )
return;
V_718 = F_9 ( V_12 , V_260 ) ;
if ( ! V_718 ) {
if ( F_21 ( V_2 ) )
F_467 ( V_12 , V_12 -> V_90 ) ;
else
F_468 ( V_12 , V_12 -> V_90 ) ;
}
if ( V_12 -> V_90 -> V_523 )
F_386 ( V_12 , V_588 ) ;
F_387 ( V_12 ) ;
if ( F_21 ( V_2 ) && V_94 == V_151 ) {
struct V_3 * V_4 = V_2 -> V_5 ;
F_126 ( F_469 ( V_94 ) , V_719 ) ;
F_126 ( F_470 ( V_94 ) , 0 ) ;
}
F_471 ( V_12 ) ;
V_12 -> V_87 = true ;
F_369 ( V_4 , V_94 , true ) ;
F_10 (dev, crtc, encoder)
if ( V_17 -> V_720 )
V_17 -> V_720 ( V_17 ) ;
if ( ! V_718 ) {
if ( F_21 ( V_2 ) )
F_131 ( V_12 , V_12 -> V_90 ) ;
else
F_122 ( V_12 , V_12 -> V_90 ) ;
}
F_10 (dev, crtc, encoder)
if ( V_17 -> V_590 )
V_17 -> V_590 ( V_17 ) ;
F_411 ( V_12 ) ;
F_362 ( V_13 ) ;
F_165 ( V_12 ) ;
F_97 ( V_13 ) ;
F_391 ( V_13 ) ;
F_10 (dev, crtc, encoder)
V_17 -> V_242 ( V_17 ) ;
}
static void F_472 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_126 ( F_473 ( V_13 -> V_94 ) , V_13 -> V_90 -> V_211 . V_721 ) ;
F_126 ( F_474 ( V_13 -> V_94 ) , V_13 -> V_90 -> V_211 . V_722 ) ;
}
static void F_475 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = F_266 ( V_2 ) ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_16 * V_17 ;
int V_94 = V_12 -> V_94 ;
if ( F_2 ( V_12 -> V_87 ) )
return;
F_472 ( V_12 ) ;
if ( V_12 -> V_90 -> V_523 )
F_386 ( V_12 , V_588 ) ;
F_387 ( V_12 ) ;
F_471 ( V_12 ) ;
V_12 -> V_87 = true ;
if ( ! F_23 ( V_2 ) )
F_369 ( V_4 , V_94 , true ) ;
F_10 (dev, crtc, encoder)
if ( V_17 -> V_590 )
V_17 -> V_590 ( V_17 ) ;
F_138 ( V_12 ) ;
F_411 ( V_12 ) ;
F_362 ( V_13 ) ;
F_375 ( V_13 ) ;
F_165 ( V_12 ) ;
F_97 ( V_13 ) ;
F_391 ( V_13 ) ;
F_10 (dev, crtc, encoder)
V_17 -> V_242 ( V_17 ) ;
}
static void F_476 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_13 -> V_90 -> V_598 . V_599 )
return;
F_123 ( V_4 , V_13 -> V_94 ) ;
F_147 ( L_110 ,
F_4 ( V_600 ) ) ;
F_126 ( V_600 , 0 ) ;
}
static void F_477 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_16 * V_17 ;
int V_94 = V_12 -> V_94 ;
F_302 ( V_2 , V_94 ) ;
F_10 (dev, crtc, encoder)
V_17 -> V_243 ( V_17 ) ;
F_406 ( V_13 ) ;
F_97 ( V_13 ) ;
F_172 ( V_12 ) ;
F_476 ( V_12 ) ;
F_10 (dev, crtc, encoder)
if ( V_17 -> V_596 )
V_17 -> V_596 ( V_17 ) ;
if ( ! F_9 ( V_12 , V_260 ) ) {
if ( F_21 ( V_2 ) )
F_142 ( V_4 , V_94 ) ;
else if ( F_22 ( V_2 ) )
F_141 ( V_4 , V_94 ) ;
else
F_140 ( V_12 ) ;
}
if ( ! F_23 ( V_2 ) )
F_369 ( V_4 , V_94 , false ) ;
V_12 -> V_87 = false ;
F_375 ( V_13 ) ;
}
static void F_478 ( struct V_86 * V_13 )
{
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_3 * V_4 = F_266 ( V_13 -> V_2 ) ;
enum V_604 V_619 ;
unsigned long V_620 ;
if ( ! V_12 -> V_87 )
return;
if ( F_218 ( V_13 -> V_88 -> V_11 ) -> V_367 ) {
F_309 ( V_13 ) ;
F_371 ( V_13 ) ;
}
F_382 ( V_13 , V_13 -> V_11 -> V_364 ) ;
V_4 -> V_435 . V_723 ( V_13 ) ;
F_153 ( V_12 ) ;
V_620 = V_12 -> V_623 ;
F_420 (domain, domains)
F_155 ( V_4 , V_619 ) ;
V_12 -> V_623 = 0 ;
}
int F_264 ( struct V_1 * V_2 )
{
struct V_724 * V_90 = & V_2 -> V_725 ;
struct V_726 * V_727 = V_90 -> V_728 ;
struct V_20 * V_11 ;
struct V_86 * V_13 ;
unsigned V_237 = 0 ;
int V_302 = 0 ;
if ( F_2 ( ! V_727 ) )
return 0 ;
F_479 ( & V_727 -> V_729 ) ;
V_11 = F_480 ( V_2 ) ;
if ( F_2 ( ! V_11 ) )
return - V_730 ;
V_11 -> V_728 = V_727 ;
V_11 -> V_629 = true ;
F_213 (dev, crtc) {
struct V_10 * V_19 =
F_481 ( V_11 , V_13 ) ;
V_302 = F_482 ( V_19 ) ;
if ( V_302 )
goto free;
if ( ! V_19 -> V_87 )
continue;
V_19 -> V_87 = false ;
V_237 |= 1 << F_154 ( V_13 ) ;
}
if ( V_237 ) {
V_302 = F_483 ( V_11 ) ;
if ( ! V_302 ) {
F_213 (dev, crtc)
if ( V_237 & ( 1 << F_154 ( V_13 ) ) )
V_13 -> V_11 -> V_87 = true ;
return V_302 ;
}
}
free:
if ( V_302 )
F_129 ( L_111 , V_302 ) ;
F_484 ( V_11 ) ;
return V_302 ;
}
void F_485 ( struct V_731 * V_17 )
{
struct V_16 * V_16 = F_13 ( V_17 ) ;
F_486 ( V_17 ) ;
F_212 ( V_16 ) ;
}
static void F_487 ( struct V_732 * V_22 )
{
struct V_86 * V_13 = V_22 -> V_15 . V_11 -> V_13 ;
F_150 ( L_112 ,
V_22 -> V_15 . V_15 . V_240 ,
V_22 -> V_15 . V_134 ) ;
if ( V_22 -> V_133 ( V_22 ) ) {
struct V_16 * V_17 = V_22 -> V_17 ;
struct V_23 * V_733 = V_22 -> V_15 . V_11 ;
F_60 ( ! V_13 ,
L_113 ) ;
if ( ! V_13 )
return;
F_60 ( ! V_13 -> V_11 -> V_87 ,
L_114 ) ;
if ( ! V_17 || V_17 -> type == V_614 )
return;
F_60 ( V_733 -> V_27 != & V_17 -> V_15 ,
L_115 ) ;
F_60 ( V_733 -> V_13 != V_17 -> V_15 . V_13 ,
L_116 ) ;
} else {
F_60 ( V_13 && V_13 -> V_11 -> V_87 ,
L_117 ) ;
F_60 ( ! V_13 && V_22 -> V_15 . V_11 -> V_27 ,
L_118 ) ;
}
}
int F_488 ( struct V_732 * V_22 )
{
struct V_23 * V_24 ;
V_24 = F_489 ( sizeof *V_24 , V_734 ) ;
if ( ! V_24 )
return - V_730 ;
V_22 -> V_15 . V_11 = V_24 ;
return 0 ;
}
struct V_732 * F_490 ( void )
{
struct V_732 * V_22 ;
V_22 = F_489 ( sizeof *V_22 , V_734 ) ;
if ( ! V_22 )
return NULL ;
if ( F_488 ( V_22 ) < 0 ) {
F_212 ( V_22 ) ;
return NULL ;
}
return V_22 ;
}
bool F_491 ( struct V_732 * V_22 )
{
enum V_94 V_94 = 0 ;
struct V_16 * V_17 = V_22 -> V_17 ;
return V_17 -> V_133 ( V_17 , & V_94 ) ;
}
static int F_492 ( struct V_18 * V_19 )
{
if ( V_19 -> V_15 . V_242 && V_19 -> V_261 )
return V_19 -> V_467 ;
return 0 ;
}
static int F_493 ( struct V_1 * V_2 , enum V_94 V_94 ,
struct V_18 * V_210 )
{
struct V_20 * V_11 = V_210 -> V_15 . V_11 ;
struct V_12 * V_735 ;
struct V_18 * V_736 ;
F_150 ( L_119 ,
F_77 ( V_94 ) , V_210 -> V_467 ) ;
if ( V_210 -> V_467 > 4 ) {
F_150 ( L_120 ,
F_77 ( V_94 ) , V_210 -> V_467 ) ;
return - V_304 ;
}
if ( F_231 ( V_2 ) || F_232 ( V_2 ) ) {
if ( V_210 -> V_467 > 2 ) {
F_150 ( L_121 ,
V_210 -> V_467 ) ;
return - V_304 ;
} else {
return 0 ;
}
}
if ( F_51 ( V_2 ) -> V_737 == 2 )
return 0 ;
switch ( V_94 ) {
case V_142 :
return 0 ;
case V_151 :
if ( V_210 -> V_467 <= 2 )
return 0 ;
V_735 = F_41 ( F_494 ( V_2 , V_517 ) ) ;
V_736 =
F_458 ( V_11 , V_735 ) ;
if ( F_459 ( V_736 ) )
return F_460 ( V_736 ) ;
if ( F_492 ( V_736 ) > 0 ) {
F_150 ( L_122 ,
F_77 ( V_94 ) , V_210 -> V_467 ) ;
return - V_304 ;
}
return 0 ;
case V_517 :
if ( V_210 -> V_467 > 2 ) {
F_150 ( L_123 ,
F_77 ( V_94 ) , V_210 -> V_467 ) ;
return - V_304 ;
}
V_735 = F_41 ( F_494 ( V_2 , V_151 ) ) ;
V_736 =
F_458 ( V_11 , V_735 ) ;
if ( F_459 ( V_736 ) )
return F_460 ( V_736 ) ;
if ( F_492 ( V_736 ) > 2 ) {
F_150 ( L_124 ) ;
return - V_304 ;
}
return 0 ;
default:
F_144 () ;
}
}
static int F_495 ( struct V_12 * V_12 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_12 -> V_15 . V_2 ;
struct V_447 * V_91 = & V_210 -> V_15 . V_91 ;
int V_738 , V_739 , V_740 , V_302 ;
bool V_741 = false ;
V_472:
V_739 = F_5 ( V_2 ) * F_496 ( 100 ) / F_497 ( 1 ) / 10 ;
V_740 = V_91 -> V_92 ;
V_738 = F_498 ( V_740 , V_739 ,
V_210 -> V_742 ) ;
V_210 -> V_467 = V_738 ;
F_499 ( V_210 -> V_742 , V_738 , V_740 ,
V_739 , & V_210 -> V_589 ) ;
V_302 = F_493 ( V_12 -> V_15 . V_2 ,
V_12 -> V_94 , V_210 ) ;
if ( V_302 == - V_304 && V_210 -> V_742 > 6 * 3 ) {
V_210 -> V_742 -= 2 * 3 ;
F_150 ( L_125 ,
V_210 -> V_742 ) ;
V_741 = true ;
V_210 -> V_743 = true ;
goto V_472;
}
if ( V_741 )
return V_744 ;
return V_302 ;
}
static bool F_500 ( struct V_3 * V_4 ,
struct V_18 * V_210 )
{
if ( V_210 -> V_742 > 24 )
return false ;
if ( F_231 ( V_4 -> V_2 ) )
return true ;
return F_501 ( V_210 ) <=
V_4 -> V_633 * 95 / 100 ;
}
static void F_502 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_210 -> V_559 = V_448 . V_745 &&
F_392 ( V_13 ) &&
F_500 ( V_4 , V_210 ) ;
}
static int F_503 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_447 * V_91 = & V_210 -> V_15 . V_91 ;
if ( F_51 ( V_2 ) -> V_103 < 4 ) {
int V_746 = V_4 -> V_633 ;
if ( ( V_13 -> V_94 == V_142 || F_504 ( V_2 ) ) &&
V_91 -> V_92 > V_746 * 9 / 10 ) {
V_746 *= 2 ;
V_210 -> V_262 = true ;
}
if ( V_91 -> V_92 > V_746 * 9 / 10 )
return - V_304 ;
}
if ( ( F_11 ( V_210 , V_30 ) &&
F_15 ( V_2 ) ) || V_210 -> V_262 )
V_210 -> V_374 &= ~ 1 ;
if ( ( F_51 ( V_2 ) -> V_103 > 4 || F_19 ( V_2 ) ) &&
V_91 -> V_747 == V_91 -> V_551 )
return - V_304 ;
if ( F_393 ( V_2 ) )
F_502 ( V_13 , V_210 ) ;
if ( V_210 -> V_261 )
return F_495 ( V_13 , V_210 ) ;
return 0 ;
}
static int F_505 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_266 ( V_2 ) ;
T_4 V_748 = F_4 ( V_675 ) ;
T_4 V_749 = F_4 ( V_649 ) ;
T_4 V_750 ;
if ( ! ( V_748 & V_676 ) )
return 24000 ;
if ( ( V_749 & V_669 ) == V_684 )
return 540000 ;
V_750 = ( F_4 ( V_671 ) &
F_438 ( V_672 ) ) >> 1 ;
if ( V_750 == V_751 ||
V_750 == V_673 ) {
switch ( V_749 & V_669 ) {
case V_683 :
return 432000 ;
case V_670 :
return 308570 ;
case V_685 :
return 617140 ;
default:
F_54 ( 1 , L_126 ) ;
}
} else {
switch ( V_749 & V_669 ) {
case V_683 :
return 450000 ;
case V_670 :
return 337500 ;
case V_685 :
return 675000 ;
default:
F_54 ( 1 , L_126 ) ;
}
}
return 24000 ;
}
static int F_506 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_266 ( V_2 ) ;
T_4 V_749 = F_4 ( V_649 ) ;
T_4 V_752 = F_4 ( V_654 ) & V_655 ;
T_4 V_753 = F_4 ( V_651 ) ;
int V_627 ;
if ( ! ( V_753 & V_652 ) )
return 19200 ;
V_627 = 19200 * V_752 / 2 ;
switch ( V_749 & V_656 ) {
case V_647 :
return V_627 ;
case V_646 :
return V_627 * 2 / 3 ;
case V_645 :
return V_627 / 2 ;
case V_644 :
return V_627 / 4 ;
}
return 19200 ;
}
static int F_507 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_754 = F_4 ( V_755 ) ;
T_4 V_663 = V_754 & V_756 ;
if ( V_754 & V_757 )
return 800000 ;
else if ( F_4 ( V_636 ) & V_637 )
return 450000 ;
else if ( V_663 == V_758 )
return 450000 ;
else if ( V_663 == V_759 )
return 540000 ;
else if ( V_663 == V_760 )
return 337500 ;
else
return 675000 ;
}
static int F_508 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_754 = F_4 ( V_755 ) ;
T_4 V_663 = V_754 & V_756 ;
if ( V_754 & V_757 )
return 800000 ;
else if ( F_4 ( V_636 ) & V_637 )
return 450000 ;
else if ( V_663 == V_758 )
return 450000 ;
else if ( F_509 ( V_2 ) )
return 337500 ;
else
return 540000 ;
}
static int F_510 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_121 ;
int V_641 ;
if ( V_4 -> V_687 == 0 )
V_4 -> V_687 = F_447 ( V_4 ) ;
F_62 ( & V_4 -> V_124 ) ;
V_121 = F_63 ( V_4 , V_697 ) ;
F_64 ( & V_4 -> V_124 ) ;
V_641 = V_121 & V_698 ;
F_54 ( ( V_121 & V_699 ) !=
( V_641 << V_700 ) ,
L_127 ) ;
return F_25 ( V_4 -> V_687 << 1 , V_641 + 1 ) ;
}
static int F_511 ( struct V_1 * V_2 )
{
return 450000 ;
}
static int F_512 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_513 ( struct V_1 * V_2 )
{
return 333333 ;
}
static int F_514 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_515 ( struct V_1 * V_2 )
{
T_5 V_761 = 0 ;
F_516 ( V_2 -> V_762 , V_763 , & V_761 ) ;
switch ( V_761 & V_764 ) {
case V_765 :
return 266667 ;
case V_766 :
return 333333 ;
case V_767 :
return 444444 ;
case V_768 :
return 200000 ;
default:
F_129 ( L_128 , V_761 ) ;
case V_769 :
return 133333 ;
case V_770 :
return 166667 ;
}
}
static int F_517 ( struct V_1 * V_2 )
{
T_5 V_761 = 0 ;
F_516 ( V_2 -> V_762 , V_763 , & V_761 ) ;
if ( V_761 & V_771 )
return 133333 ;
else {
switch ( V_761 & V_764 ) {
case V_772 :
return 333333 ;
default:
case V_773 :
return 190000 ;
}
}
}
static int F_518 ( struct V_1 * V_2 )
{
return 266667 ;
}
static int F_519 ( struct V_1 * V_2 )
{
T_5 V_774 = 0 ;
if ( V_2 -> V_762 -> V_775 == 0x1 )
return 133333 ;
F_520 ( V_2 -> V_762 -> V_776 ,
F_521 ( 0 , 3 ) , V_777 , & V_774 ) ;
switch ( V_774 & V_778 ) {
case V_779 :
case V_780 :
case V_781 :
return 200000 ;
case V_782 :
return 250000 ;
case V_783 :
return 133333 ;
case V_784 :
case V_785 :
case V_786 :
return 266667 ;
}
return 0 ;
}
static int F_522 ( struct V_1 * V_2 )
{
return 133333 ;
}
static unsigned int F_523 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
static const unsigned int V_787 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 6400000 ,
} ;
static const unsigned int V_788 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 2666667 ,
} ;
static const unsigned int V_789 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 3333333 ,
[ 5 ] = 3566667 ,
[ 6 ] = 4266667 ,
} ;
static const unsigned int V_790 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
} ;
static const unsigned int V_791 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 2666667 ,
[ 5 ] = 4266667 ,
} ;
const unsigned int * V_792 ;
unsigned int V_60 ;
T_6 V_215 = 0 ;
if ( F_524 ( V_2 ) )
V_792 = V_791 ;
else if ( F_19 ( V_2 ) )
V_792 = V_790 ;
else if ( F_186 ( V_2 ) )
V_792 = V_789 ;
else if ( F_20 ( V_2 ) )
V_792 = V_788 ;
else if ( F_525 ( V_2 ) )
V_792 = V_787 ;
else
return 0 ;
V_215 = F_4 ( F_125 ( V_2 ) ? V_793 : V_794 ) ;
V_60 = V_792 [ V_215 & 0x7 ] ;
if ( V_60 == 0 )
F_129 ( L_129 , V_215 ) ;
else
F_150 ( L_130 , V_60 ) ;
return V_60 ;
}
static int F_526 ( struct V_1 * V_2 )
{
unsigned int V_795 , V_60 = F_523 ( V_2 ) ;
T_7 V_215 = 0 ;
F_516 ( V_2 -> V_762 , V_763 , & V_215 ) ;
V_795 = ( V_215 >> 12 ) & 0x1 ;
switch ( V_60 ) {
case 2666667 :
case 4000000 :
case 5333333 :
return V_795 ? 333333 : 222222 ;
case 3200000 :
return V_795 ? 320000 : 228571 ;
default:
F_129 ( L_131 , V_60 , V_215 ) ;
return 222222 ;
}
}
static int F_527 ( struct V_1 * V_2 )
{
static const T_6 V_796 [] = { 16 , 10 , 8 } ;
static const T_6 V_797 [] = { 20 , 12 , 10 } ;
static const T_6 V_798 [] = { 24 , 16 , 14 } ;
const T_6 * V_799 ;
unsigned int V_795 , V_60 = F_523 ( V_2 ) ;
T_7 V_215 = 0 ;
F_516 ( V_2 -> V_762 , V_763 , & V_215 ) ;
V_795 = ( ( V_215 >> 8 ) & 0x1f ) - 1 ;
if ( V_795 >= F_297 ( V_796 ) )
goto V_800;
switch ( V_60 ) {
case 3200000 :
V_799 = V_796 ;
break;
case 4000000 :
V_799 = V_797 ;
break;
case 5333333 :
V_799 = V_798 ;
break;
default:
goto V_800;
}
return F_25 ( V_60 , V_799 [ V_795 ] ) ;
V_800:
F_129 ( L_132 , V_60 , V_215 ) ;
return 200000 ;
}
static int F_528 ( struct V_1 * V_2 )
{
static const T_6 V_796 [] = { 12 , 10 , 8 , 7 , 5 , 16 } ;
static const T_6 V_797 [] = { 14 , 12 , 10 , 8 , 6 , 20 } ;
static const T_6 V_801 [] = { 20 , 14 , 12 , 10 , 8 , 24 } ;
static const T_6 V_798 [] = { 20 , 16 , 12 , 12 , 8 , 28 } ;
const T_6 * V_799 ;
unsigned int V_795 , V_60 = F_523 ( V_2 ) ;
T_7 V_215 = 0 ;
F_516 ( V_2 -> V_762 , V_763 , & V_215 ) ;
V_795 = ( V_215 >> 4 ) & 0x7 ;
if ( V_795 >= F_297 ( V_796 ) )
goto V_800;
switch ( V_60 ) {
case 3200000 :
V_799 = V_796 ;
break;
case 4000000 :
V_799 = V_797 ;
break;
case 4800000 :
V_799 = V_801 ;
break;
case 5333333 :
V_799 = V_798 ;
break;
default:
goto V_800;
}
return F_25 ( V_60 , V_799 [ V_795 ] ) ;
V_800:
F_129 ( L_133 , V_60 , V_215 ) ;
return 190476 ;
}
static void
F_529 ( T_4 * V_802 , T_4 * V_803 )
{
while ( * V_802 > V_804 ||
* V_803 > V_804 ) {
* V_802 >>= 1 ;
* V_803 >>= 1 ;
}
}
static void F_530 ( unsigned int V_54 , unsigned int V_59 ,
T_4 * V_805 , T_4 * V_806 )
{
* V_806 = F_531 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_805 = F_39 ( ( V_64 ) V_54 * * V_806 , V_59 ) ;
F_529 ( V_805 , V_806 ) ;
}
void
F_499 ( int V_382 , int V_807 ,
int V_808 , int V_809 ,
struct V_810 * V_811 )
{
V_811 -> V_812 = 64 ;
F_530 ( V_382 * V_808 ,
V_809 * V_807 * 8 ,
& V_811 -> V_813 , & V_811 -> V_814 ) ;
F_530 ( V_808 , V_809 ,
& V_811 -> V_815 , & V_811 -> V_816 ) ;
}
static inline bool F_532 ( struct V_3 * V_4 )
{
if ( V_448 . V_817 >= 0 )
return V_448 . V_817 != 0 ;
return V_4 -> V_818 . V_819
&& ! ( V_4 -> V_160 & V_820 ) ;
}
static int F_44 ( const struct V_18 * V_19 ,
int V_26 )
{
struct V_1 * V_2 = V_19 -> V_15 . V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_28 ;
F_2 ( ! V_19 -> V_15 . V_11 ) ;
if ( F_22 ( V_2 ) || F_18 ( V_2 ) ) {
V_28 = 100000 ;
} else if ( F_11 ( V_19 , V_30 ) &&
F_532 ( V_4 ) && V_26 < 2 ) {
V_28 = V_4 -> V_818 . V_821 ;
F_150 ( L_134 , V_28 ) ;
} else if ( ! F_23 ( V_2 ) ) {
V_28 = 96000 ;
} else {
V_28 = 48000 ;
}
return V_28 ;
}
static T_4 F_533 ( struct V_62 * V_62 )
{
return ( 1 << V_62 -> V_59 ) << 16 | V_62 -> V_55 ;
}
static T_4 F_534 ( struct V_62 * V_62 )
{
return V_62 -> V_59 << 16 | V_62 -> V_63 << 8 | V_62 -> V_55 ;
}
static void F_535 ( struct V_12 * V_13 ,
struct V_18 * V_19 ,
T_3 * V_822 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
T_1 V_823 , V_824 = 0 ;
if ( F_20 ( V_2 ) ) {
V_823 = F_533 ( & V_19 -> V_62 ) ;
if ( V_822 )
V_824 = F_533 ( V_822 ) ;
} else {
V_823 = F_534 ( & V_19 -> V_62 ) ;
if ( V_822 )
V_824 = F_534 ( V_822 ) ;
}
V_19 -> V_211 . V_721 = V_823 ;
V_13 -> V_825 = false ;
if ( F_11 ( V_19 , V_30 ) &&
V_822 ) {
V_19 -> V_211 . V_722 = V_824 ;
V_13 -> V_825 = true ;
} else {
V_19 -> V_211 . V_722 = V_823 ;
}
}
static void F_536 ( struct V_3 * V_4 , enum V_94
V_94 )
{
T_1 V_826 ;
V_826 = F_133 ( V_4 , V_94 , F_537 ( 1 ) ) ;
V_826 &= 0xffffff00 ;
V_826 |= 0x00000030 ;
F_135 ( V_4 , V_94 , F_537 ( 1 ) , V_826 ) ;
V_826 = F_133 ( V_4 , V_94 , V_827 ) ;
V_826 &= 0x8cffffff ;
V_826 = 0x8c000000 ;
F_135 ( V_4 , V_94 , V_827 , V_826 ) ;
V_826 = F_133 ( V_4 , V_94 , F_537 ( 1 ) ) ;
V_826 &= 0xffffff00 ;
F_135 ( V_4 , V_94 , F_537 ( 1 ) , V_826 ) ;
V_826 = F_133 ( V_4 , V_94 , V_827 ) ;
V_826 &= 0x00ffffff ;
V_826 |= 0xb0000000 ;
F_135 ( V_4 , V_94 , V_827 , V_826 ) ;
}
static void F_538 ( struct V_12 * V_13 ,
struct V_810 * V_811 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_94 = V_13 -> V_94 ;
F_126 ( F_539 ( V_94 ) , F_540 ( V_811 -> V_812 ) | V_811 -> V_813 ) ;
F_126 ( F_541 ( V_94 ) , V_811 -> V_814 ) ;
F_126 ( F_542 ( V_94 ) , V_811 -> V_815 ) ;
F_126 ( F_543 ( V_94 ) , V_811 -> V_816 ) ;
}
static void F_388 ( struct V_12 * V_13 ,
struct V_810 * V_811 ,
struct V_810 * V_828 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_94 = V_13 -> V_94 ;
enum V_93 V_93 = V_13 -> V_90 -> V_96 ;
if ( F_51 ( V_2 ) -> V_103 >= 5 ) {
F_126 ( F_338 ( V_93 ) , F_540 ( V_811 -> V_812 ) | V_811 -> V_813 ) ;
F_126 ( F_544 ( V_93 ) , V_811 -> V_814 ) ;
F_126 ( F_545 ( V_93 ) , V_811 -> V_815 ) ;
F_126 ( F_546 ( V_93 ) , V_811 -> V_816 ) ;
if ( V_828 && ( F_21 ( V_2 ) || F_51 ( V_2 ) -> V_103 < 8 ) &&
V_13 -> V_90 -> V_829 ) {
F_126 ( F_547 ( V_93 ) ,
F_540 ( V_828 -> V_812 ) | V_828 -> V_813 ) ;
F_126 ( F_548 ( V_93 ) , V_828 -> V_814 ) ;
F_126 ( F_549 ( V_93 ) , V_828 -> V_815 ) ;
F_126 ( F_550 ( V_93 ) , V_828 -> V_816 ) ;
}
} else {
F_126 ( F_551 ( V_94 ) , F_540 ( V_811 -> V_812 ) | V_811 -> V_813 ) ;
F_126 ( F_552 ( V_94 ) , V_811 -> V_814 ) ;
F_126 ( F_553 ( V_94 ) , V_811 -> V_815 ) ;
F_126 ( F_554 ( V_94 ) , V_811 -> V_816 ) ;
}
}
void F_386 ( struct V_12 * V_13 , enum V_830 V_811 )
{
struct V_810 * V_831 , * V_832 = NULL ;
if ( V_811 == V_588 ) {
V_831 = & V_13 -> V_90 -> V_831 ;
V_832 = & V_13 -> V_90 -> V_832 ;
} else if ( V_811 == V_833 ) {
V_831 = & V_13 -> V_90 -> V_832 ;
} else {
F_129 ( L_135 ) ;
return;
}
if ( V_13 -> V_90 -> V_261 )
F_538 ( V_13 , & V_13 -> V_90 -> V_831 ) ;
else
F_388 ( V_13 , V_831 , V_832 ) ;
}
static void F_555 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
T_1 V_62 , V_213 ;
V_62 = V_834 | V_221 |
V_219 | V_835 ;
if ( V_13 -> V_94 == V_151 )
V_62 |= V_220 ;
V_62 |= V_123 ;
V_210 -> V_211 . V_62 = V_62 ;
V_213 = ( V_210 -> V_593 - 1 )
<< V_836 ;
V_210 -> V_211 . V_213 = V_213 ;
}
static void F_468 ( struct V_12 * V_13 ,
const struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_94 = V_13 -> V_94 ;
T_1 V_837 ;
T_1 V_838 , V_839 , V_840 , V_841 , V_842 ;
T_1 V_843 , V_826 ;
F_62 ( & V_4 -> V_124 ) ;
V_838 = V_210 -> V_62 . V_59 ;
V_839 = V_210 -> V_62 . V_63 ;
V_840 = V_210 -> V_62 . V_55 ;
V_841 = V_210 -> V_62 . V_57 ;
V_842 = V_210 -> V_62 . V_58 ;
if ( V_94 == V_151 )
F_536 ( V_4 , V_94 ) ;
F_135 ( V_4 , V_94 , V_844 , 0x0100000f ) ;
V_826 = F_133 ( V_4 , V_94 , F_556 ( V_94 ) ) ;
V_826 &= 0x00ffffff ;
F_135 ( V_4 , V_94 , F_556 ( V_94 ) , V_826 ) ;
F_135 ( V_4 , V_94 , V_845 , 0x610 ) ;
V_837 = ( ( V_839 << V_846 ) | ( V_840 & V_847 ) ) ;
V_837 |= ( ( V_841 << V_848 ) | ( V_842 << V_849 ) ) ;
V_837 |= ( ( V_838 << V_850 ) ) ;
V_837 |= ( 1 << V_851 ) ;
V_837 |= ( V_852 << V_853 ) ;
F_135 ( V_4 , V_94 , F_557 ( V_94 ) , V_837 ) ;
V_837 |= V_854 ;
F_135 ( V_4 , V_94 , F_557 ( V_94 ) , V_837 ) ;
if ( V_210 -> V_855 == 162000 ||
F_9 ( V_13 , V_39 ) ||
F_9 ( V_13 , V_38 ) )
F_135 ( V_4 , V_94 , F_558 ( V_94 ) ,
0x009f0003 ) ;
else
F_135 ( V_4 , V_94 , F_558 ( V_94 ) ,
0x00d0000f ) ;
if ( V_210 -> V_523 ) {
if ( V_94 == V_142 )
F_135 ( V_4 , V_94 , F_559 ( V_94 ) ,
0x0df40000 ) ;
else
F_135 ( V_4 , V_94 , F_559 ( V_94 ) ,
0x0df70000 ) ;
} else {
if ( V_94 == V_142 )
F_135 ( V_4 , V_94 , F_559 ( V_94 ) ,
0x0df70000 ) ;
else
F_135 ( V_4 , V_94 , F_559 ( V_94 ) ,
0x0df40000 ) ;
}
V_843 = F_133 ( V_4 , V_94 , F_560 ( V_94 ) ) ;
V_843 = ( V_843 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_9 ( V_13 , V_613 ) ||
F_9 ( V_13 , V_453 ) )
V_843 |= 0x01000000 ;
F_135 ( V_4 , V_94 , F_560 ( V_94 ) , V_843 ) ;
F_135 ( V_4 , V_94 , F_561 ( V_94 ) , 0x87871000 ) ;
F_64 ( & V_4 -> V_124 ) ;
}
static void F_562 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
V_210 -> V_211 . V_62 = V_222 |
V_221 | V_219 |
V_123 ;
if ( V_13 -> V_94 != V_142 )
V_210 -> V_211 . V_62 |= V_220 ;
V_210 -> V_211 . V_213 =
( V_210 -> V_593 - 1 ) << V_836 ;
}
static void F_467 ( struct V_12 * V_13 ,
const struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_94 = V_13 -> V_94 ;
int V_232 = F_59 ( V_13 -> V_94 ) ;
enum V_214 V_106 = F_132 ( V_94 ) ;
T_1 V_856 , V_857 ;
T_1 V_838 , V_839 , V_840 , V_841 , V_842 , V_858 ;
T_1 V_859 ;
int V_60 ;
V_838 = V_210 -> V_62 . V_59 ;
V_858 = V_210 -> V_62 . V_55 & 0x3fffff ;
V_839 = V_210 -> V_62 . V_63 ;
V_840 = V_210 -> V_62 . V_55 >> 22 ;
V_841 = V_210 -> V_62 . V_57 ;
V_842 = V_210 -> V_62 . V_58 ;
V_60 = V_210 -> V_62 . V_60 ;
V_859 = 0 ;
V_856 = 0 ;
F_126 ( V_232 ,
V_210 -> V_211 . V_62 & ~ V_123 ) ;
F_62 ( & V_4 -> V_124 ) ;
F_135 ( V_4 , V_94 , F_563 ( V_106 ) ,
5 << V_860 |
V_841 << V_861 |
V_842 << V_862 |
1 << V_863 ) ;
F_135 ( V_4 , V_94 , F_564 ( V_106 ) , V_840 ) ;
F_135 ( V_4 , V_94 , F_565 ( V_106 ) ,
V_864 |
1 << V_865 ) ;
if ( V_858 )
F_135 ( V_4 , V_94 , F_566 ( V_106 ) , V_858 ) ;
V_859 = F_133 ( V_4 , V_94 , F_567 ( V_106 ) ) ;
V_859 &= ~ ( V_866 | V_867 ) ;
V_859 |= ( 2 << V_868 ) ;
if ( V_858 )
V_859 |= V_867 ;
F_135 ( V_4 , V_94 , F_567 ( V_106 ) , V_859 ) ;
V_859 = F_133 ( V_4 , V_94 , F_568 ( V_106 ) ) ;
V_859 &= ~ ( V_869 |
V_870 ) ;
V_859 |= ( 0x5 << V_871 ) ;
if ( ! V_858 )
V_859 |= V_870 ;
F_135 ( V_4 , V_94 , F_568 ( V_106 ) , V_859 ) ;
if ( V_60 == 5400000 ) {
V_856 |= ( 0x3 << V_872 ) ;
V_856 |= ( 0x8 << V_873 ) ;
V_856 |= ( 0x1 << V_874 ) ;
V_857 = 0x9 ;
} else if ( V_60 <= 6200000 ) {
V_856 |= ( 0x5 << V_872 ) ;
V_856 |= ( 0xB << V_873 ) ;
V_856 |= ( 0x3 << V_874 ) ;
V_857 = 0x9 ;
} else if ( V_60 <= 6480000 ) {
V_856 |= ( 0x4 << V_872 ) ;
V_856 |= ( 0x9 << V_873 ) ;
V_856 |= ( 0x3 << V_874 ) ;
V_857 = 0x8 ;
} else {
V_856 |= ( 0x4 << V_872 ) ;
V_856 |= ( 0x9 << V_873 ) ;
V_856 |= ( 0x3 << V_874 ) ;
V_857 = 0 ;
}
F_135 ( V_4 , V_94 , F_569 ( V_106 ) , V_856 ) ;
V_859 = F_133 ( V_4 , V_94 , F_570 ( V_106 ) ) ;
V_859 &= ~ V_875 ;
V_859 |= ( V_857 << V_876 ) ;
F_135 ( V_4 , V_94 , F_570 ( V_106 ) , V_859 ) ;
F_135 ( V_4 , V_94 , F_134 ( V_106 ) ,
F_133 ( V_4 , V_94 , F_134 ( V_106 ) ) |
V_877 ) ;
F_64 ( & V_4 -> V_124 ) ;
}
void F_571 ( struct V_1 * V_2 , enum V_94 V_94 ,
const struct V_62 * V_62 )
{
struct V_12 * V_13 =
F_41 ( F_494 ( V_2 , V_94 ) ) ;
struct V_18 V_210 = {
. V_15 . V_13 = & V_13 -> V_15 ,
. V_593 = 1 ,
. V_62 = * V_62 ,
} ;
if ( F_21 ( V_2 ) ) {
F_562 ( V_13 , & V_210 ) ;
F_467 ( V_13 , & V_210 ) ;
F_131 ( V_13 , & V_210 ) ;
} else {
F_555 ( V_13 , & V_210 ) ;
F_468 ( V_13 , & V_210 ) ;
F_122 ( V_13 , & V_210 ) ;
}
}
void F_572 ( struct V_1 * V_2 , enum V_94 V_94 )
{
if ( F_21 ( V_2 ) )
F_142 ( F_266 ( V_2 ) , V_94 ) ;
else
F_141 ( F_266 ( V_2 ) , V_94 ) ;
}
static void F_573 ( struct V_12 * V_13 ,
struct V_18 * V_19 ,
T_3 * V_822 ,
int V_26 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_62 ;
bool V_878 ;
struct V_62 * clock = & V_19 -> V_62 ;
F_535 ( V_13 , V_19 , V_822 ) ;
V_878 = F_11 ( V_19 , V_41 ) ||
F_11 ( V_19 , V_38 ) ;
V_62 = V_219 ;
if ( F_11 ( V_19 , V_30 ) )
V_62 |= V_879 ;
else
V_62 |= V_880 ;
if ( F_574 ( V_2 ) || F_575 ( V_2 ) || F_525 ( V_2 ) ) {
V_62 |= ( V_19 -> V_593 - 1 )
<< V_881 ;
}
if ( V_878 )
V_62 |= V_882 ;
if ( V_19 -> V_523 )
V_62 |= V_882 ;
if ( F_20 ( V_2 ) )
V_62 |= ( 1 << ( clock -> V_57 - 1 ) ) << V_883 ;
else {
V_62 |= ( 1 << ( clock -> V_57 - 1 ) ) << V_884 ;
if ( F_19 ( V_2 ) && V_822 )
V_62 |= ( 1 << ( V_822 -> V_57 - 1 ) ) << V_885 ;
}
switch ( clock -> V_58 ) {
case 5 :
V_62 |= V_886 ;
break;
case 7 :
V_62 |= V_887 ;
break;
case 10 :
V_62 |= V_888 ;
break;
case 14 :
V_62 |= V_889 ;
break;
}
if ( F_51 ( V_2 ) -> V_103 >= 4 )
V_62 |= ( 6 << V_890 ) ;
if ( V_19 -> V_891 )
V_62 |= V_892 ;
else if ( F_11 ( V_19 , V_30 ) &&
F_532 ( V_4 ) && V_26 < 2 )
V_62 |= V_893 ;
else
V_62 |= V_894 ;
V_62 |= V_123 ;
V_19 -> V_211 . V_62 = V_62 ;
if ( F_51 ( V_2 ) -> V_103 >= 4 ) {
T_1 V_213 = ( V_19 -> V_593 - 1 )
<< V_836 ;
V_19 -> V_211 . V_213 = V_213 ;
}
}
static void F_576 ( struct V_12 * V_13 ,
struct V_18 * V_19 ,
T_3 * V_822 ,
int V_26 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_62 ;
struct V_62 * clock = & V_19 -> V_62 ;
F_535 ( V_13 , V_19 , V_822 ) ;
V_62 = V_219 ;
if ( F_11 ( V_19 , V_30 ) ) {
V_62 |= ( 1 << ( clock -> V_57 - 1 ) ) << V_884 ;
} else {
if ( clock -> V_57 == 2 )
V_62 |= V_895 ;
else
V_62 |= ( clock -> V_57 - 2 ) << V_884 ;
if ( clock -> V_58 == 4 )
V_62 |= V_896 ;
}
if ( ! F_139 ( V_2 ) && F_11 ( V_19 , V_51 ) )
V_62 |= V_218 ;
if ( F_11 ( V_19 , V_30 ) &&
F_532 ( V_4 ) && V_26 < 2 )
V_62 |= V_893 ;
else
V_62 |= V_894 ;
V_62 |= V_123 ;
V_19 -> V_211 . V_62 = V_62 ;
}
static void F_387 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_94 V_94 = V_12 -> V_94 ;
enum V_93 V_96 = V_12 -> V_90 -> V_96 ;
struct V_447 * V_91 =
& V_12 -> V_90 -> V_15 . V_91 ;
T_4 V_897 , V_898 ;
int V_899 = 0 ;
V_897 = V_91 -> V_897 ;
V_898 = V_91 -> V_898 ;
if ( V_91 -> V_351 & V_900 ) {
V_897 -= 1 ;
V_898 -= 1 ;
if ( F_9 ( V_12 , V_41 ) )
V_899 = ( V_91 -> V_901 - 1 ) / 2 ;
else
V_899 = V_91 -> V_902 -
V_91 -> V_901 / 2 ;
if ( V_899 < 0 )
V_899 += V_91 -> V_901 ;
}
if ( F_51 ( V_2 ) -> V_103 > 3 )
F_126 ( F_333 ( V_96 ) , V_899 ) ;
F_126 ( F_321 ( V_96 ) ,
( V_91 -> V_450 - 1 ) |
( ( V_91 -> V_901 - 1 ) << 16 ) ) ;
F_126 ( F_323 ( V_96 ) ,
( V_91 -> V_903 - 1 ) |
( ( V_91 -> V_904 - 1 ) << 16 ) ) ;
F_126 ( F_325 ( V_96 ) ,
( V_91 -> V_902 - 1 ) |
( ( V_91 -> V_905 - 1 ) << 16 ) ) ;
F_126 ( F_327 ( V_96 ) ,
( V_91 -> V_451 - 1 ) |
( ( V_897 - 1 ) << 16 ) ) ;
F_126 ( F_329 ( V_96 ) ,
( V_91 -> V_906 - 1 ) |
( ( V_898 - 1 ) << 16 ) ) ;
F_126 ( F_331 ( V_96 ) ,
( V_91 -> V_907 - 1 ) |
( ( V_91 -> V_908 - 1 ) << 16 ) ) ;
if ( F_231 ( V_2 ) && V_96 == V_592 &&
( V_94 == V_151 || V_94 == V_517 ) )
F_126 ( F_327 ( V_94 ) , F_4 ( F_327 ( V_96 ) ) ) ;
F_126 ( F_281 ( V_94 ) ,
( ( V_12 -> V_90 -> V_374 - 1 ) << 16 ) |
( V_12 -> V_90 -> V_373 - 1 ) ) ;
}
static void F_577 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_93 V_96 = V_210 -> V_96 ;
T_4 V_215 ;
V_215 = F_4 ( F_321 ( V_96 ) ) ;
V_210 -> V_15 . V_91 . V_450 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_15 . V_91 . V_901 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_215 = F_4 ( F_323 ( V_96 ) ) ;
V_210 -> V_15 . V_91 . V_903 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_15 . V_91 . V_904 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_215 = F_4 ( F_325 ( V_96 ) ) ;
V_210 -> V_15 . V_91 . V_902 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_15 . V_91 . V_905 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_215 = F_4 ( F_327 ( V_96 ) ) ;
V_210 -> V_15 . V_91 . V_451 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_15 . V_91 . V_897 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_215 = F_4 ( F_329 ( V_96 ) ) ;
V_210 -> V_15 . V_91 . V_906 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_15 . V_91 . V_898 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_215 = F_4 ( F_331 ( V_96 ) ) ;
V_210 -> V_15 . V_91 . V_907 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_15 . V_91 . V_908 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
if ( F_4 ( F_52 ( V_96 ) ) & V_249 ) {
V_210 -> V_15 . V_91 . V_351 |= V_900 ;
V_210 -> V_15 . V_91 . V_897 += 1 ;
V_210 -> V_15 . V_91 . V_898 += 1 ;
}
V_215 = F_4 ( F_281 ( V_13 -> V_94 ) ) ;
V_210 -> V_373 = ( V_215 & 0xffff ) + 1 ;
V_210 -> V_374 = ( ( V_215 >> 16 ) & 0xffff ) + 1 ;
V_210 -> V_15 . V_431 . V_552 = V_210 -> V_373 ;
V_210 -> V_15 . V_431 . V_551 = V_210 -> V_374 ;
}
void F_578 ( struct V_447 * V_431 ,
struct V_18 * V_210 )
{
V_431 -> V_551 = V_210 -> V_15 . V_91 . V_450 ;
V_431 -> V_909 = V_210 -> V_15 . V_91 . V_901 ;
V_431 -> V_747 = V_210 -> V_15 . V_91 . V_902 ;
V_431 -> V_910 = V_210 -> V_15 . V_91 . V_905 ;
V_431 -> V_552 = V_210 -> V_15 . V_91 . V_451 ;
V_431 -> V_911 = V_210 -> V_15 . V_91 . V_897 ;
V_431 -> V_912 = V_210 -> V_15 . V_91 . V_907 ;
V_431 -> V_913 = V_210 -> V_15 . V_91 . V_908 ;
V_431 -> V_351 = V_210 -> V_15 . V_91 . V_351 ;
V_431 -> type = V_914 ;
V_431 -> clock = V_210 -> V_15 . V_91 . V_92 ;
V_431 -> V_351 |= V_210 -> V_15 . V_91 . V_351 ;
V_431 -> V_915 = F_579 ( V_431 ) ;
V_431 -> V_916 = F_580 ( V_431 ) ;
F_581 ( V_431 ) ;
}
static void F_471 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_917 ;
V_917 = 0 ;
if ( ( V_12 -> V_94 == V_142 && V_4 -> V_160 & V_161 ) ||
( V_12 -> V_94 == V_151 && V_4 -> V_160 & V_162 ) )
V_917 |= F_4 ( F_52 ( V_12 -> V_94 ) ) & V_163 ;
if ( V_12 -> V_90 -> V_262 )
V_917 |= V_263 ;
if ( F_19 ( V_2 ) || F_22 ( V_2 ) ) {
if ( V_12 -> V_90 -> V_918 && V_12 -> V_90 -> V_742 != 30 )
V_917 |= V_919 |
V_920 ;
switch ( V_12 -> V_90 -> V_742 ) {
case 18 :
V_917 |= V_921 ;
break;
case 24 :
V_917 |= V_247 ;
break;
case 30 :
V_917 |= V_922 ;
break;
default:
F_144 () ;
}
}
if ( F_582 ( V_2 ) ) {
if ( V_12 -> V_825 ) {
F_150 ( L_136 ) ;
V_917 |= V_923 ;
} else {
F_150 ( L_137 ) ;
}
}
if ( V_12 -> V_90 -> V_15 . V_91 . V_351 & V_900 ) {
if ( F_51 ( V_2 ) -> V_103 < 4 ||
F_9 ( V_12 , V_41 ) )
V_917 |= V_924 ;
else
V_917 |= V_925 ;
} else
V_917 |= V_926 ;
if ( F_22 ( V_2 ) && V_12 -> V_90 -> V_927 )
V_917 |= V_928 ;
F_126 ( F_52 ( V_12 -> V_94 ) , V_917 ) ;
F_127 ( F_52 ( V_12 -> V_94 ) ) ;
}
static int F_583 ( struct V_12 * V_13 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_28 , V_26 = 0 ;
T_3 clock ;
bool V_929 ;
bool V_718 = false ;
struct V_16 * V_17 ;
const T_2 * V_29 ;
struct V_20 * V_11 = V_19 -> V_15 . V_11 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_25 ;
memset ( & V_19 -> V_211 , 0 ,
sizeof( V_19 -> V_211 ) ) ;
F_12 (state, connector, connector_state, i) {
if ( V_24 -> V_13 != & V_13 -> V_15 )
continue;
V_17 = F_13 ( V_24 -> V_27 ) ;
switch ( V_17 -> type ) {
case V_260 :
V_718 = true ;
break;
default:
break;
}
V_26 ++ ;
}
if ( V_718 )
return 0 ;
if ( ! V_19 -> V_930 ) {
V_28 = F_44 ( V_19 , V_26 ) ;
V_29 = F_17 ( V_19 , V_28 ) ;
V_929 = V_4 -> V_435 . V_931 ( V_29 , V_19 ,
V_19 -> V_855 ,
V_28 , NULL , & clock ) ;
if ( ! V_929 ) {
F_129 ( L_138 ) ;
return - V_304 ;
}
V_19 -> V_62 . V_59 = clock . V_59 ;
V_19 -> V_62 . V_63 = clock . V_63 ;
V_19 -> V_62 . V_55 = clock . V_55 ;
V_19 -> V_62 . V_57 = clock . V_57 ;
V_19 -> V_62 . V_58 = clock . V_58 ;
}
if ( F_23 ( V_2 ) ) {
F_576 ( V_13 , V_19 , NULL ,
V_26 ) ;
} else if ( F_21 ( V_2 ) ) {
F_562 ( V_13 , V_19 ) ;
} else if ( F_22 ( V_2 ) ) {
F_555 ( V_13 , V_19 ) ;
} else {
F_573 ( V_13 , V_19 , NULL ,
V_26 ) ;
}
return 0 ;
}
static void F_584 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_215 ;
if ( F_51 ( V_2 ) -> V_103 <= 3 && ( F_139 ( V_2 ) || ! F_125 ( V_2 ) ) )
return;
V_215 = F_4 ( V_600 ) ;
if ( ! ( V_215 & V_601 ) )
return;
if ( F_51 ( V_2 ) -> V_103 < 4 ) {
if ( V_13 -> V_94 != V_151 )
return;
} else {
if ( ( V_215 & V_932 ) != ( V_13 -> V_94 << V_933 ) )
return;
}
V_210 -> V_598 . V_599 = V_215 ;
V_210 -> V_598 . V_603 = F_4 ( V_602 ) ;
if ( F_51 ( V_2 ) -> V_103 < 5 )
V_210 -> V_598 . V_934 =
F_4 ( V_153 ) & V_935 ;
}
static void F_585 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_94 = V_210 -> V_96 ;
T_3 clock ;
T_1 V_837 ;
int V_28 = 100000 ;
if ( ! ( V_210 -> V_211 . V_62 & V_123 ) )
return;
F_62 ( & V_4 -> V_124 ) ;
V_837 = F_133 ( V_4 , V_94 , F_557 ( V_94 ) ) ;
F_64 ( & V_4 -> V_124 ) ;
clock . V_63 = ( V_837 >> V_846 ) & 7 ;
clock . V_55 = V_837 & V_847 ;
clock . V_59 = ( V_837 >> V_850 ) & 0xf ;
clock . V_57 = ( V_837 >> V_848 ) & 7 ;
clock . V_58 = ( V_837 >> V_849 ) & 0x1f ;
V_210 -> V_855 = F_28 ( V_28 , & clock ) ;
}
static void
F_586 ( struct V_12 * V_13 ,
struct V_341 * V_342 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_121 , V_15 , V_318 ;
int V_94 = V_13 -> V_94 , V_164 = V_13 -> V_164 ;
int V_936 , V_265 ;
unsigned int V_937 ;
struct V_276 * V_89 ;
struct V_938 * V_939 ;
V_121 = F_4 ( F_86 ( V_164 ) ) ;
if ( ! ( V_121 & V_165 ) )
return;
V_939 = F_489 ( sizeof( * V_939 ) , V_734 ) ;
if ( ! V_939 ) {
F_150 ( L_139 ) ;
return;
}
V_89 = & V_939 -> V_15 ;
if ( F_51 ( V_2 ) -> V_103 >= 4 ) {
if ( V_121 & V_376 ) {
V_342 -> V_347 = V_348 ;
V_89 -> V_289 [ 0 ] = V_270 ;
}
}
V_265 = V_121 & V_940 ;
V_936 = F_199 ( V_265 ) ;
V_89 -> V_265 = V_936 ;
V_89 -> V_382 = F_176 ( V_936 , 0 ) * 8 ;
if ( F_51 ( V_2 ) -> V_103 >= 4 ) {
if ( V_342 -> V_347 )
V_318 = F_4 ( F_228 ( V_164 ) ) ;
else
V_318 = F_4 ( F_229 ( V_164 ) ) ;
V_15 = F_4 ( F_219 ( V_164 ) ) & 0xfffff000 ;
} else {
V_15 = F_4 ( F_220 ( V_164 ) ) ;
}
V_342 -> V_15 = V_15 ;
V_121 = F_4 ( F_281 ( V_94 ) ) ;
V_89 -> V_350 = ( ( V_121 >> 16 ) & 0xfff ) + 1 ;
V_89 -> V_273 = ( ( V_121 >> 0 ) & 0xfff ) + 1 ;
V_121 = F_4 ( F_227 ( V_94 ) ) ;
V_89 -> V_287 [ 0 ] = V_121 & 0xffffffc0 ;
V_937 = F_179 ( V_2 , V_89 -> V_273 ,
V_89 -> V_265 ,
V_89 -> V_289 [ 0 ] ) ;
V_342 -> V_293 = V_89 -> V_287 [ 0 ] * V_937 ;
F_150 ( L_140 ,
F_77 ( V_94 ) , V_164 , V_89 -> V_350 , V_89 -> V_273 ,
V_89 -> V_382 , V_15 , V_89 -> V_287 [ 0 ] ,
V_342 -> V_293 ) ;
V_342 -> V_89 = V_939 ;
}
static void F_587 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_94 = V_210 -> V_96 ;
enum V_214 V_106 = F_132 ( V_94 ) ;
T_3 clock ;
T_1 V_941 , V_942 , V_943 , V_944 , V_945 ;
int V_28 = 100000 ;
F_62 ( & V_4 -> V_124 ) ;
V_941 = F_133 ( V_4 , V_94 , F_563 ( V_106 ) ) ;
V_942 = F_133 ( V_4 , V_94 , F_564 ( V_106 ) ) ;
V_943 = F_133 ( V_4 , V_94 , F_565 ( V_106 ) ) ;
V_944 = F_133 ( V_4 , V_94 , F_566 ( V_106 ) ) ;
V_945 = F_133 ( V_4 , V_94 , F_567 ( V_106 ) ) ;
F_64 ( & V_4 -> V_124 ) ;
clock . V_63 = ( V_943 & 0x7 ) == V_864 ? 2 : 0 ;
clock . V_55 = ( V_942 & 0xff ) << 22 ;
if ( V_945 & V_867 )
clock . V_55 |= V_944 & 0x3fffff ;
clock . V_59 = ( V_943 >> V_865 ) & 0xf ;
clock . V_57 = ( V_941 >> V_861 ) & 0x7 ;
clock . V_58 = ( V_941 >> V_862 ) & 0x1f ;
V_210 -> V_855 = F_29 ( V_28 , & clock ) ;
}
static bool F_588 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_215 ;
if ( ! F_83 ( V_4 ,
F_417 ( V_13 -> V_94 ) ) )
return false ;
V_210 -> V_96 = (enum V_93 ) V_13 -> V_94 ;
V_210 -> V_128 = V_946 ;
V_215 = F_4 ( F_52 ( V_13 -> V_94 ) ) ;
if ( ! ( V_215 & V_163 ) )
return false ;
if ( F_19 ( V_2 ) || F_22 ( V_2 ) ) {
switch ( V_215 & V_246 ) {
case V_921 :
V_210 -> V_742 = 18 ;
break;
case V_247 :
V_210 -> V_742 = 24 ;
break;
case V_922 :
V_210 -> V_742 = 30 ;
break;
default:
break;
}
}
if ( F_22 ( V_2 ) && ( V_215 & V_928 ) )
V_210 -> V_927 = true ;
if ( F_51 ( V_2 ) -> V_103 < 4 )
V_210 -> V_262 = V_215 & V_263 ;
F_577 ( V_13 , V_210 ) ;
F_584 ( V_13 , V_210 ) ;
if ( F_51 ( V_2 ) -> V_103 >= 4 ) {
V_215 = F_4 ( F_130 ( V_13 -> V_94 ) ) ;
V_210 -> V_593 =
( ( V_215 & V_947 )
>> V_836 ) + 1 ;
V_210 -> V_211 . V_213 = V_215 ;
} else if ( F_574 ( V_2 ) || F_575 ( V_2 ) || F_525 ( V_2 ) ) {
V_215 = F_4 ( F_59 ( V_13 -> V_94 ) ) ;
V_210 -> V_593 =
( ( V_215 & V_948 )
>> V_881 ) + 1 ;
} else {
V_210 -> V_593 = 1 ;
}
V_210 -> V_211 . V_62 = F_4 ( F_59 ( V_13 -> V_94 ) ) ;
if ( ! F_22 ( V_2 ) ) {
if ( F_139 ( V_2 ) )
V_210 -> V_211 . V_62 &= ~ V_218 ;
V_210 -> V_211 . V_721 = F_4 ( F_473 ( V_13 -> V_94 ) ) ;
V_210 -> V_211 . V_722 = F_4 ( F_474 ( V_13 -> V_94 ) ) ;
} else {
V_210 -> V_211 . V_62 &= ~ ( V_212 |
V_234 |
V_233 ) ;
}
if ( F_21 ( V_2 ) )
F_587 ( V_13 , V_210 ) ;
else if ( F_22 ( V_2 ) )
F_585 ( V_13 , V_210 ) ;
else
F_589 ( V_13 , V_210 ) ;
return true ;
}
static void F_590 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_16 * V_17 ;
T_1 V_121 , V_949 ;
bool V_950 = false ;
bool V_951 = false ;
bool V_952 = false ;
bool V_953 = false ;
bool V_954 = false ;
F_591 (dev, encoder) {
switch ( V_17 -> type ) {
case V_30 :
V_952 = true ;
V_950 = true ;
break;
case V_453 :
V_952 = true ;
if ( F_346 ( & V_17 -> V_15 ) -> V_106 == V_605 )
V_951 = true ;
break;
default:
break;
}
}
if ( F_56 ( V_2 ) ) {
V_953 = V_4 -> V_818 . V_955 ;
V_954 = V_953 ;
} else {
V_953 = false ;
V_954 = true ;
}
F_150 ( L_141 ,
V_952 , V_950 , V_953 ) ;
V_121 = F_4 ( V_174 ) ;
V_949 = V_121 ;
V_949 &= ~ V_176 ;
if ( V_953 )
V_949 |= V_956 ;
else
V_949 |= V_957 ;
V_949 &= ~ V_175 ;
V_949 &= ~ V_958 ;
V_949 &= ~ V_959 ;
if ( V_952 ) {
V_949 |= V_960 ;
if ( F_532 ( V_4 ) && V_954 )
V_949 |= V_959 ;
if ( V_951 ) {
if ( F_532 ( V_4 ) && V_954 )
V_949 |= V_961 ;
else
V_949 |= V_962 ;
} else
V_949 |= V_963 ;
} else {
V_949 |= V_964 ;
V_949 |= V_963 ;
}
if ( V_949 == V_121 )
return;
V_121 &= ~ V_176 ;
if ( V_953 )
V_121 |= V_956 ;
else
V_121 |= V_957 ;
if ( V_952 ) {
V_121 &= ~ V_175 ;
V_121 |= V_960 ;
if ( F_532 ( V_4 ) && V_954 ) {
F_150 ( L_142 ) ;
V_121 |= V_959 ;
} else
V_121 &= ~ V_959 ;
F_126 ( V_174 , V_121 ) ;
F_127 ( V_174 ) ;
F_128 ( 200 ) ;
V_121 &= ~ V_958 ;
if ( V_951 ) {
if ( F_532 ( V_4 ) && V_954 ) {
F_150 ( L_143 ) ;
V_121 |= V_961 ;
} else
V_121 |= V_962 ;
} else
V_121 |= V_963 ;
F_126 ( V_174 , V_121 ) ;
F_127 ( V_174 ) ;
F_128 ( 200 ) ;
} else {
F_150 ( L_144 ) ;
V_121 &= ~ V_958 ;
V_121 |= V_963 ;
F_126 ( V_174 , V_121 ) ;
F_127 ( V_174 ) ;
F_128 ( 200 ) ;
V_121 &= ~ V_175 ;
V_121 |= V_964 ;
V_121 &= ~ V_959 ;
F_126 ( V_174 , V_121 ) ;
F_127 ( V_174 ) ;
F_128 ( 200 ) ;
}
F_124 ( V_121 != V_949 ) ;
}
static void F_592 ( struct V_3 * V_4 )
{
T_4 V_215 ;
V_215 = F_4 ( V_965 ) ;
V_215 |= V_966 ;
F_126 ( V_965 , V_215 ) ;
if ( F_593 ( F_4 ( V_965 ) &
V_967 , 100 ) )
F_129 ( L_145 ) ;
V_215 = F_4 ( V_965 ) ;
V_215 &= ~ V_966 ;
F_126 ( V_965 , V_215 ) ;
if ( F_593 ( ( F_4 ( V_965 ) &
V_967 ) == 0 , 100 ) )
F_129 ( L_146 ) ;
}
static void F_594 ( struct V_3 * V_4 )
{
T_4 V_215 ;
V_215 = F_314 ( V_4 , 0x8008 , V_968 ) ;
V_215 &= ~ ( 0xFF << 24 ) ;
V_215 |= ( 0x12 << 24 ) ;
F_313 ( V_4 , 0x8008 , V_215 , V_968 ) ;
V_215 = F_314 ( V_4 , 0x2008 , V_968 ) ;
V_215 |= ( 1 << 11 ) ;
F_313 ( V_4 , 0x2008 , V_215 , V_968 ) ;
V_215 = F_314 ( V_4 , 0x2108 , V_968 ) ;
V_215 |= ( 1 << 11 ) ;
F_313 ( V_4 , 0x2108 , V_215 , V_968 ) ;
V_215 = F_314 ( V_4 , 0x206C , V_968 ) ;
V_215 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_313 ( V_4 , 0x206C , V_215 , V_968 ) ;
V_215 = F_314 ( V_4 , 0x216C , V_968 ) ;
V_215 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_313 ( V_4 , 0x216C , V_215 , V_968 ) ;
V_215 = F_314 ( V_4 , 0x2080 , V_968 ) ;
V_215 &= ~ ( 7 << 13 ) ;
V_215 |= ( 5 << 13 ) ;
F_313 ( V_4 , 0x2080 , V_215 , V_968 ) ;
V_215 = F_314 ( V_4 , 0x2180 , V_968 ) ;
V_215 &= ~ ( 7 << 13 ) ;
V_215 |= ( 5 << 13 ) ;
F_313 ( V_4 , 0x2180 , V_215 , V_968 ) ;
V_215 = F_314 ( V_4 , 0x208C , V_968 ) ;
V_215 &= ~ 0xFF ;
V_215 |= 0x1C ;
F_313 ( V_4 , 0x208C , V_215 , V_968 ) ;
V_215 = F_314 ( V_4 , 0x218C , V_968 ) ;
V_215 &= ~ 0xFF ;
V_215 |= 0x1C ;
F_313 ( V_4 , 0x218C , V_215 , V_968 ) ;
V_215 = F_314 ( V_4 , 0x2098 , V_968 ) ;
V_215 &= ~ ( 0xFF << 16 ) ;
V_215 |= ( 0x1C << 16 ) ;
F_313 ( V_4 , 0x2098 , V_215 , V_968 ) ;
V_215 = F_314 ( V_4 , 0x2198 , V_968 ) ;
V_215 &= ~ ( 0xFF << 16 ) ;
V_215 |= ( 0x1C << 16 ) ;
F_313 ( V_4 , 0x2198 , V_215 , V_968 ) ;
V_215 = F_314 ( V_4 , 0x20C4 , V_968 ) ;
V_215 |= ( 1 << 27 ) ;
F_313 ( V_4 , 0x20C4 , V_215 , V_968 ) ;
V_215 = F_314 ( V_4 , 0x21C4 , V_968 ) ;
V_215 |= ( 1 << 27 ) ;
F_313 ( V_4 , 0x21C4 , V_215 , V_968 ) ;
V_215 = F_314 ( V_4 , 0x20EC , V_968 ) ;
V_215 &= ~ ( 0xF << 28 ) ;
V_215 |= ( 4 << 28 ) ;
F_313 ( V_4 , 0x20EC , V_215 , V_968 ) ;
V_215 = F_314 ( V_4 , 0x21EC , V_968 ) ;
V_215 &= ~ ( 0xF << 28 ) ;
V_215 |= ( 4 << 28 ) ;
F_313 ( V_4 , 0x21EC , V_215 , V_968 ) ;
}
static void F_595 ( struct V_1 * V_2 , bool V_969 ,
bool V_970 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_97 , V_215 ;
if ( F_54 ( V_970 && ! V_969 , L_147 ) )
V_969 = true ;
if ( F_54 ( V_4 -> V_971 == V_972 &&
V_970 , L_148 ) )
V_970 = false ;
F_62 ( & V_4 -> V_124 ) ;
V_215 = F_314 ( V_4 , V_973 , V_502 ) ;
V_215 &= ~ V_503 ;
V_215 |= V_974 ;
F_313 ( V_4 , V_973 , V_215 , V_502 ) ;
F_128 ( 24 ) ;
if ( V_969 ) {
V_215 = F_314 ( V_4 , V_973 , V_502 ) ;
V_215 &= ~ V_974 ;
F_313 ( V_4 , V_973 , V_215 , V_502 ) ;
if ( V_970 ) {
F_592 ( V_4 ) ;
F_594 ( V_4 ) ;
}
}
V_97 = ( V_4 -> V_971 == V_972 ) ?
V_975 : V_976 ;
V_215 = F_314 ( V_4 , V_97 , V_502 ) ;
V_215 |= V_977 ;
F_313 ( V_4 , V_97 , V_215 , V_502 ) ;
F_64 ( & V_4 -> V_124 ) ;
}
static void F_596 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_97 , V_215 ;
F_62 ( & V_4 -> V_124 ) ;
V_97 = ( V_4 -> V_971 == V_972 ) ?
V_975 : V_976 ;
V_215 = F_314 ( V_4 , V_97 , V_502 ) ;
V_215 &= ~ V_977 ;
F_313 ( V_4 , V_97 , V_215 , V_502 ) ;
V_215 = F_314 ( V_4 , V_973 , V_502 ) ;
if ( ! ( V_215 & V_503 ) ) {
if ( ! ( V_215 & V_974 ) ) {
V_215 |= V_974 ;
F_313 ( V_4 , V_973 , V_215 , V_502 ) ;
F_128 ( 32 ) ;
}
V_215 |= V_503 ;
F_313 ( V_4 , V_973 , V_215 , V_502 ) ;
}
F_64 ( & V_4 -> V_124 ) ;
}
static void F_597 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
bool V_978 = false ;
F_591 (dev, encoder) {
switch ( V_17 -> type ) {
case V_39 :
V_978 = true ;
break;
default:
break;
}
}
if ( V_978 )
F_595 ( V_2 , true , true ) ;
else
F_596 ( V_2 ) ;
}
void F_598 ( struct V_1 * V_2 )
{
if ( F_56 ( V_2 ) || F_102 ( V_2 ) )
F_590 ( V_2 ) ;
else if ( F_167 ( V_2 ) )
F_597 ( V_2 ) ;
}
static int F_599 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_15 . V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_11 = V_19 -> V_15 . V_11 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_16 * V_17 ;
int V_26 = 0 , V_25 ;
bool V_979 = false ;
F_12 (state, connector, connector_state, i) {
if ( V_24 -> V_13 != V_19 -> V_15 . V_13 )
continue;
V_17 = F_13 ( V_24 -> V_27 ) ;
switch ( V_17 -> type ) {
case V_30 :
V_979 = true ;
break;
default:
break;
}
V_26 ++ ;
}
if ( V_979 && F_532 ( V_4 ) && V_26 < 2 ) {
F_150 ( L_134 ,
V_4 -> V_818 . V_821 ) ;
return V_4 -> V_818 . V_821 ;
}
return 120000 ;
}
static void F_389 ( struct V_86 * V_13 )
{
struct V_3 * V_4 = V_13 -> V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
int V_94 = V_12 -> V_94 ;
T_4 V_121 ;
V_121 = 0 ;
switch ( V_12 -> V_90 -> V_742 ) {
case 18 :
V_121 |= V_921 ;
break;
case 24 :
V_121 |= V_247 ;
break;
case 30 :
V_121 |= V_922 ;
break;
case 36 :
V_121 |= V_980 ;
break;
default:
F_144 () ;
}
if ( V_12 -> V_90 -> V_918 )
V_121 |= ( V_919 | V_920 ) ;
if ( V_12 -> V_90 -> V_15 . V_91 . V_351 & V_900 )
V_121 |= V_250 ;
else
V_121 |= V_926 ;
if ( V_12 -> V_90 -> V_927 )
V_121 |= V_928 ;
F_126 ( F_52 ( V_94 ) , V_121 ) ;
F_127 ( F_52 ( V_94 ) ) ;
}
static void F_398 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
int V_94 = V_12 -> V_94 ;
T_7 V_981 = 0x7800 ;
if ( V_12 -> V_90 -> V_927 )
V_981 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_126 ( F_600 ( V_94 ) , V_981 << 16 ) ;
F_126 ( F_601 ( V_94 ) , 0 ) ;
F_126 ( F_602 ( V_94 ) , V_981 ) ;
F_126 ( F_603 ( V_94 ) , 0 ) ;
F_126 ( F_604 ( V_94 ) , 0 ) ;
F_126 ( F_605 ( V_94 ) , V_981 << 16 ) ;
F_126 ( F_606 ( V_94 ) , 0 ) ;
F_126 ( F_607 ( V_94 ) , 0 ) ;
F_126 ( F_608 ( V_94 ) , 0 ) ;
if ( F_51 ( V_2 ) -> V_103 > 6 ) {
T_7 V_982 = 0 ;
if ( V_12 -> V_90 -> V_927 )
V_982 = ( 16 * ( 1 << 12 ) / 255 ) & 0x1fff ;
F_126 ( F_609 ( V_94 ) , V_982 ) ;
F_126 ( F_610 ( V_94 ) , V_982 ) ;
F_126 ( F_611 ( V_94 ) , V_982 ) ;
F_126 ( F_612 ( V_94 ) , 0 ) ;
} else {
T_4 V_431 = V_983 ;
if ( V_12 -> V_90 -> V_927 )
V_431 |= V_984 ;
F_126 ( F_612 ( V_94 ) , V_431 ) ;
}
}
static void F_397 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
enum V_94 V_94 = V_12 -> V_94 ;
enum V_93 V_96 = V_12 -> V_90 -> V_96 ;
T_4 V_121 ;
V_121 = 0 ;
if ( F_231 ( V_2 ) && V_12 -> V_90 -> V_918 )
V_121 |= ( V_919 | V_920 ) ;
if ( V_12 -> V_90 -> V_15 . V_91 . V_351 & V_900 )
V_121 |= V_250 ;
else
V_121 |= V_926 ;
F_126 ( F_52 ( V_96 ) , V_121 ) ;
F_127 ( F_52 ( V_96 ) ) ;
F_126 ( F_365 ( V_12 -> V_94 ) , V_985 ) ;
F_127 ( F_365 ( V_12 -> V_94 ) ) ;
if ( F_232 ( V_2 ) || F_51 ( V_2 ) -> V_103 >= 9 ) {
V_121 = 0 ;
switch ( V_12 -> V_90 -> V_742 ) {
case 18 :
V_121 |= V_986 ;
break;
case 24 :
V_121 |= V_987 ;
break;
case 30 :
V_121 |= V_988 ;
break;
case 36 :
V_121 |= V_989 ;
break;
default:
F_144 () ;
}
if ( V_12 -> V_90 -> V_918 )
V_121 |= V_990 | V_991 ;
F_126 ( F_613 ( V_94 ) , V_121 ) ;
}
}
static bool F_614 ( struct V_86 * V_13 ,
struct V_18 * V_19 ,
T_3 * clock ,
bool * V_992 ,
T_3 * V_822 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_28 ;
const T_2 * V_29 ;
bool V_302 ;
V_28 = F_599 ( V_19 ) ;
V_29 = F_17 ( V_19 , V_28 ) ;
V_302 = V_4 -> V_435 . V_931 ( V_29 , V_19 ,
V_19 -> V_855 ,
V_28 , NULL , clock ) ;
if ( ! V_302 )
return false ;
return true ;
}
int F_498 ( int V_85 , int V_739 , int V_993 )
{
T_1 V_994 = V_85 * V_993 * 21 / 20 ;
return F_183 ( V_994 , V_739 * 8 ) ;
}
static bool F_615 ( struct V_62 * V_62 , int V_995 )
{
return F_26 ( V_62 ) < V_995 * V_62 -> V_59 ;
}
static T_4 F_616 ( struct V_12 * V_12 ,
struct V_18 * V_19 ,
T_1 * V_823 ,
T_3 * V_822 , T_1 * V_824 )
{
struct V_86 * V_13 = & V_12 -> V_15 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_11 = V_19 -> V_15 . V_11 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_16 * V_17 ;
T_4 V_62 ;
int V_995 , V_26 = 0 , V_25 ;
bool V_979 = false , V_878 = false ;
F_12 (state, connector, connector_state, i) {
if ( V_24 -> V_13 != V_19 -> V_15 . V_13 )
continue;
V_17 = F_13 ( V_24 -> V_27 ) ;
switch ( V_17 -> type ) {
case V_30 :
V_979 = true ;
break;
case V_41 :
case V_38 :
V_878 = true ;
break;
default:
break;
}
V_26 ++ ;
}
V_995 = 21 ;
if ( V_979 ) {
if ( ( F_532 ( V_4 ) &&
V_4 -> V_818 . V_821 == 100000 ) ||
( F_56 ( V_2 ) && F_15 ( V_2 ) ) )
V_995 = 25 ;
} else if ( V_19 -> V_891 )
V_995 = 20 ;
if ( F_615 ( & V_19 -> V_62 , V_995 ) )
* V_823 |= V_996 ;
if ( V_824 && ( V_822 -> V_54 < V_995 * V_822 -> V_59 ) )
* V_824 |= V_996 ;
V_62 = 0 ;
if ( V_979 )
V_62 |= V_879 ;
else
V_62 |= V_880 ;
V_62 |= ( V_19 -> V_593 - 1 )
<< V_997 ;
if ( V_878 )
V_62 |= V_882 ;
if ( V_19 -> V_523 )
V_62 |= V_882 ;
V_62 |= ( 1 << ( V_19 -> V_62 . V_57 - 1 ) ) << V_884 ;
V_62 |= ( 1 << ( V_19 -> V_62 . V_57 - 1 ) ) << V_885 ;
switch ( V_19 -> V_62 . V_58 ) {
case 5 :
V_62 |= V_886 ;
break;
case 7 :
V_62 |= V_887 ;
break;
case 10 :
V_62 |= V_888 ;
break;
case 14 :
V_62 |= V_889 ;
break;
}
if ( V_979 && F_532 ( V_4 ) && V_26 < 2 )
V_62 |= V_893 ;
else
V_62 |= V_894 ;
return V_62 | V_123 ;
}
static int F_617 ( struct V_12 * V_13 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
T_3 clock , V_822 ;
T_1 V_62 = 0 , V_823 = 0 , V_824 = 0 ;
bool V_929 , V_992 = false ;
bool V_979 = false ;
struct V_127 * V_130 ;
memset ( & V_19 -> V_211 , 0 ,
sizeof( V_19 -> V_211 ) ) ;
V_979 = F_9 ( V_13 , V_30 ) ;
F_54 ( ! ( F_56 ( V_2 ) || F_102 ( V_2 ) ) ,
L_149 , F_618 ( V_2 ) ) ;
V_929 = F_614 ( & V_13 -> V_15 , V_19 , & clock ,
& V_992 , & V_822 ) ;
if ( ! V_929 && ! V_19 -> V_930 ) {
F_129 ( L_138 ) ;
return - V_304 ;
}
if ( ! V_19 -> V_930 ) {
V_19 -> V_62 . V_59 = clock . V_59 ;
V_19 -> V_62 . V_63 = clock . V_63 ;
V_19 -> V_62 . V_55 = clock . V_55 ;
V_19 -> V_62 . V_57 = clock . V_57 ;
V_19 -> V_62 . V_58 = clock . V_58 ;
}
if ( V_19 -> V_261 ) {
V_823 = F_534 ( & V_19 -> V_62 ) ;
if ( V_992 )
V_824 = F_534 ( & V_822 ) ;
V_62 = F_616 ( V_13 , V_19 ,
& V_823 , & V_822 ,
V_992 ? & V_824 : NULL ) ;
V_19 -> V_211 . V_62 = V_62 ;
V_19 -> V_211 . V_721 = V_823 ;
if ( V_992 )
V_19 -> V_211 . V_722 = V_824 ;
else
V_19 -> V_211 . V_722 = V_823 ;
V_130 = F_343 ( V_13 , V_19 ) ;
if ( V_130 == NULL ) {
F_147 ( L_150 ,
F_77 ( V_13 -> V_94 ) ) ;
return - V_304 ;
}
}
if ( V_979 && V_992 )
V_13 -> V_825 = true ;
else
V_13 -> V_825 = false ;
return 0 ;
}
static void F_619 ( struct V_12 * V_13 ,
struct V_810 * V_811 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_94 V_94 = V_13 -> V_94 ;
V_811 -> V_815 = F_4 ( F_542 ( V_94 ) ) ;
V_811 -> V_816 = F_4 ( F_543 ( V_94 ) ) ;
V_811 -> V_813 = F_4 ( F_539 ( V_94 ) )
& ~ V_518 ;
V_811 -> V_814 = F_4 ( F_541 ( V_94 ) ) ;
V_811 -> V_812 = ( ( F_4 ( F_539 ( V_94 ) )
& V_518 ) >> V_998 ) + 1 ;
}
static void F_620 ( struct V_12 * V_13 ,
enum V_93 V_93 ,
struct V_810 * V_811 ,
struct V_810 * V_828 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_94 V_94 = V_13 -> V_94 ;
if ( F_51 ( V_2 ) -> V_103 >= 5 ) {
V_811 -> V_815 = F_4 ( F_545 ( V_93 ) ) ;
V_811 -> V_816 = F_4 ( F_546 ( V_93 ) ) ;
V_811 -> V_813 = F_4 ( F_338 ( V_93 ) )
& ~ V_518 ;
V_811 -> V_814 = F_4 ( F_544 ( V_93 ) ) ;
V_811 -> V_812 = ( ( F_4 ( F_338 ( V_93 ) )
& V_518 ) >> V_998 ) + 1 ;
if ( V_828 && F_51 ( V_2 ) -> V_103 < 8 &&
V_13 -> V_90 -> V_829 ) {
V_828 -> V_815 = F_4 ( F_549 ( V_93 ) ) ;
V_828 -> V_816 = F_4 ( F_550 ( V_93 ) ) ;
V_828 -> V_813 = F_4 ( F_547 ( V_93 ) )
& ~ V_518 ;
V_828 -> V_814 = F_4 ( F_548 ( V_93 ) ) ;
V_828 -> V_812 = ( ( F_4 ( F_547 ( V_93 ) )
& V_518 ) >> V_998 ) + 1 ;
}
} else {
V_811 -> V_815 = F_4 ( F_553 ( V_94 ) ) ;
V_811 -> V_816 = F_4 ( F_554 ( V_94 ) ) ;
V_811 -> V_813 = F_4 ( F_551 ( V_94 ) )
& ~ V_518 ;
V_811 -> V_814 = F_4 ( F_552 ( V_94 ) ) ;
V_811 -> V_812 = ( ( F_4 ( F_551 ( V_94 ) )
& V_518 ) >> V_998 ) + 1 ;
}
}
void F_621 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
if ( V_210 -> V_261 )
F_619 ( V_13 , & V_210 -> V_831 ) ;
else
F_620 ( V_13 , V_210 -> V_96 ,
& V_210 -> V_831 ,
& V_210 -> V_832 ) ;
}
static void F_622 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
F_620 ( V_13 , V_210 -> V_96 ,
& V_210 -> V_589 , NULL ) ;
}
static void F_623 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_384 * V_385 = & V_210 -> V_385 ;
T_4 V_429 = 0 ;
int V_240 = - 1 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_13 -> V_386 ; V_25 ++ ) {
V_429 = F_4 ( F_238 ( V_13 -> V_94 , V_25 ) ) ;
if ( V_429 & V_430 && ! ( V_429 & V_999 ) ) {
V_240 = V_25 ;
V_210 -> V_452 . V_120 = true ;
V_210 -> V_452 . V_556 = F_4 ( F_239 ( V_13 -> V_94 , V_25 ) ) ;
V_210 -> V_452 . V_293 = F_4 ( F_240 ( V_13 -> V_94 , V_25 ) ) ;
break;
}
}
V_385 -> V_422 = V_240 ;
if ( V_240 >= 0 ) {
V_385 -> V_541 |= ( 1 << V_550 ) ;
} else {
V_385 -> V_541 &= ~ ( 1 << V_550 ) ;
}
}
static void
F_624 ( struct V_12 * V_13 ,
struct V_341 * V_342 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_121 , V_15 , V_318 , V_1000 , V_347 ;
int V_94 = V_13 -> V_94 ;
int V_936 , V_265 ;
unsigned int V_937 ;
struct V_276 * V_89 ;
struct V_938 * V_939 ;
V_939 = F_489 ( sizeof( * V_939 ) , V_734 ) ;
if ( ! V_939 ) {
F_150 ( L_139 ) ;
return;
}
V_89 = & V_939 -> V_15 ;
V_121 = F_4 ( F_92 ( V_94 , 0 ) ) ;
if ( ! ( V_121 & V_170 ) )
goto error;
V_265 = V_121 & V_1001 ;
V_936 = F_200 ( V_265 ,
V_121 & V_390 ,
V_121 & V_1002 ) ;
V_89 -> V_265 = V_936 ;
V_89 -> V_382 = F_176 ( V_936 , 0 ) * 8 ;
V_347 = V_121 & V_1003 ;
switch ( V_347 ) {
case V_1004 :
V_89 -> V_289 [ 0 ] = V_269 ;
break;
case V_401 :
V_342 -> V_347 = V_348 ;
V_89 -> V_289 [ 0 ] = V_270 ;
break;
case V_402 :
V_89 -> V_289 [ 0 ] = V_271 ;
break;
case V_403 :
V_89 -> V_289 [ 0 ] = V_272 ;
break;
default:
F_178 ( V_347 ) ;
goto error;
}
V_15 = F_4 ( F_246 ( V_94 , 0 ) ) & 0xfffff000 ;
V_342 -> V_15 = V_15 ;
V_318 = F_4 ( F_249 ( V_94 , 0 ) ) ;
V_121 = F_4 ( F_250 ( V_94 , 0 ) ) ;
V_89 -> V_273 = ( ( V_121 >> 16 ) & 0xfff ) + 1 ;
V_89 -> V_350 = ( ( V_121 >> 0 ) & 0x1fff ) + 1 ;
V_121 = F_4 ( F_251 ( V_94 , 0 ) ) ;
V_1000 = F_234 ( V_2 , V_89 -> V_289 [ 0 ] ,
V_89 -> V_265 ) ;
V_89 -> V_287 [ 0 ] = ( V_121 & 0x3ff ) * V_1000 ;
V_937 = F_179 ( V_2 , V_89 -> V_273 ,
V_89 -> V_265 ,
V_89 -> V_289 [ 0 ] ) ;
V_342 -> V_293 = V_89 -> V_287 [ 0 ] * V_937 ;
F_150 ( L_151 ,
F_77 ( V_94 ) , V_89 -> V_350 , V_89 -> V_273 ,
V_89 -> V_382 , V_15 , V_89 -> V_287 [ 0 ] ,
V_342 -> V_293 ) ;
V_342 -> V_89 = V_939 ;
return;
error:
F_212 ( V_89 ) ;
}
static void F_625 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_215 ;
V_215 = F_4 ( F_282 ( V_13 -> V_94 ) ) ;
if ( V_215 & V_557 ) {
V_210 -> V_452 . V_120 = true ;
V_210 -> V_452 . V_556 = F_4 ( F_283 ( V_13 -> V_94 ) ) ;
V_210 -> V_452 . V_293 = F_4 ( F_284 ( V_13 -> V_94 ) ) ;
if ( F_626 ( V_2 ) ) {
F_2 ( ( V_215 & V_1005 ) !=
F_356 ( V_13 -> V_94 ) ) ;
}
}
}
static void
F_627 ( struct V_12 * V_13 ,
struct V_341 * V_342 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_121 , V_15 , V_318 ;
int V_94 = V_13 -> V_94 ;
int V_936 , V_265 ;
unsigned int V_937 ;
struct V_276 * V_89 ;
struct V_938 * V_939 ;
V_121 = F_4 ( F_86 ( V_94 ) ) ;
if ( ! ( V_121 & V_165 ) )
return;
V_939 = F_489 ( sizeof( * V_939 ) , V_734 ) ;
if ( ! V_939 ) {
F_150 ( L_139 ) ;
return;
}
V_89 = & V_939 -> V_15 ;
if ( F_51 ( V_2 ) -> V_103 >= 4 ) {
if ( V_121 & V_376 ) {
V_342 -> V_347 = V_348 ;
V_89 -> V_289 [ 0 ] = V_270 ;
}
}
V_265 = V_121 & V_940 ;
V_936 = F_199 ( V_265 ) ;
V_89 -> V_265 = V_936 ;
V_89 -> V_382 = F_176 ( V_936 , 0 ) * 8 ;
V_15 = F_4 ( F_219 ( V_94 ) ) & 0xfffff000 ;
if ( F_231 ( V_2 ) || F_232 ( V_2 ) ) {
V_318 = F_4 ( F_233 ( V_94 ) ) ;
} else {
if ( V_342 -> V_347 )
V_318 = F_4 ( F_228 ( V_94 ) ) ;
else
V_318 = F_4 ( F_229 ( V_94 ) ) ;
}
V_342 -> V_15 = V_15 ;
V_121 = F_4 ( F_281 ( V_94 ) ) ;
V_89 -> V_350 = ( ( V_121 >> 16 ) & 0xfff ) + 1 ;
V_89 -> V_273 = ( ( V_121 >> 0 ) & 0xfff ) + 1 ;
V_121 = F_4 ( F_227 ( V_94 ) ) ;
V_89 -> V_287 [ 0 ] = V_121 & 0xffffffc0 ;
V_937 = F_179 ( V_2 , V_89 -> V_273 ,
V_89 -> V_265 ,
V_89 -> V_289 [ 0 ] ) ;
V_342 -> V_293 = V_89 -> V_287 [ 0 ] * V_937 ;
F_150 ( L_151 ,
F_77 ( V_94 ) , V_89 -> V_350 , V_89 -> V_273 ,
V_89 -> V_382 , V_15 , V_89 -> V_287 [ 0 ] ,
V_342 -> V_293 ) ;
V_342 -> V_89 = V_939 ;
}
static bool F_628 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_215 ;
if ( ! F_83 ( V_4 ,
F_417 ( V_13 -> V_94 ) ) )
return false ;
V_210 -> V_96 = (enum V_93 ) V_13 -> V_94 ;
V_210 -> V_128 = V_946 ;
V_215 = F_4 ( F_52 ( V_13 -> V_94 ) ) ;
if ( ! ( V_215 & V_163 ) )
return false ;
switch ( V_215 & V_246 ) {
case V_921 :
V_210 -> V_742 = 18 ;
break;
case V_247 :
V_210 -> V_742 = 24 ;
break;
case V_922 :
V_210 -> V_742 = 30 ;
break;
case V_980 :
V_210 -> V_742 = 36 ;
break;
default:
break;
}
if ( V_215 & V_928 )
V_210 -> V_927 = true ;
if ( F_4 ( F_104 ( V_13 -> V_94 ) ) & V_178 ) {
struct V_127 * V_130 ;
V_210 -> V_261 = true ;
V_215 = F_4 ( F_72 ( V_13 -> V_94 ) ) ;
V_210 -> V_467 = ( ( V_466 & V_215 ) >>
V_1006 ) + 1 ;
F_622 ( V_13 , V_210 ) ;
if ( F_56 ( V_4 -> V_2 ) ) {
V_210 -> V_128 =
(enum V_533 ) V_13 -> V_94 ;
} else {
V_215 = F_4 ( V_521 ) ;
if ( V_215 & F_340 ( V_13 -> V_94 ) )
V_210 -> V_128 = V_522 ;
else
V_210 -> V_128 = V_1007 ;
}
V_130 = & V_4 -> V_129 [ V_210 -> V_128 ] ;
F_2 ( ! V_130 -> V_133 ( V_4 , V_130 ,
& V_210 -> V_211 ) ) ;
V_215 = V_210 -> V_211 . V_62 ;
V_210 -> V_593 =
( ( V_215 & V_1008 )
>> V_997 ) + 1 ;
F_629 ( V_13 , V_210 ) ;
} else {
V_210 -> V_593 = 1 ;
}
F_577 ( V_13 , V_210 ) ;
F_625 ( V_13 , V_210 ) ;
return true ;
}
static void F_630 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 ;
F_137 (dev, crtc)
F_60 ( V_13 -> V_87 , L_152 ,
F_77 ( V_13 -> V_94 ) ) ;
F_60 ( F_4 ( V_1009 ) , L_153 ) ;
F_60 ( F_4 ( V_1010 ) & V_1011 , L_154 ) ;
F_60 ( F_4 ( V_1012 ) & V_1013 , L_155 ) ;
F_60 ( F_4 ( V_1014 ) & V_1013 , L_156 ) ;
F_60 ( F_4 ( V_1015 ) & V_1016 , L_157 ) ;
F_60 ( F_4 ( V_1017 ) & V_1018 ,
L_158 ) ;
if ( F_231 ( V_2 ) )
F_60 ( F_4 ( V_1019 ) & V_1018 ,
L_159 ) ;
F_60 ( F_4 ( V_1020 ) & V_1021 ,
L_160 ) ;
F_60 ( F_4 ( V_1022 ) & V_1023 ,
L_161 ) ;
F_60 ( F_4 ( V_1024 ) & V_1025 , L_162 ) ;
F_60 ( F_631 ( V_4 ) , L_163 ) ;
}
static T_4 F_632 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( F_231 ( V_2 ) )
return F_4 ( V_1026 ) ;
else
return F_4 ( V_1027 ) ;
}
static void F_633 ( struct V_3 * V_4 , T_4 V_121 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( F_231 ( V_2 ) ) {
F_62 ( & V_4 -> V_560 . V_561 ) ;
if ( F_359 ( V_4 , V_1028 ,
V_121 ) )
F_129 ( L_164 ) ;
F_64 ( & V_4 -> V_560 . V_561 ) ;
} else {
F_126 ( V_1027 , V_121 ) ;
F_127 ( V_1027 ) ;
}
}
static void F_634 ( struct V_3 * V_4 ,
bool V_1029 , bool V_1030 )
{
T_4 V_121 ;
F_630 ( V_4 ) ;
V_121 = F_4 ( V_755 ) ;
if ( V_1029 ) {
V_121 |= V_757 ;
F_126 ( V_755 , V_121 ) ;
if ( F_593 ( F_4 ( V_755 ) &
V_1031 , 1 ) )
F_129 ( L_165 ) ;
V_121 = F_4 ( V_755 ) ;
}
V_121 |= V_1032 ;
F_126 ( V_755 , V_121 ) ;
F_127 ( V_755 ) ;
if ( F_53 ( ( F_4 ( V_755 ) & V_677 ) == 0 , 1 ) )
F_129 ( L_166 ) ;
V_121 = F_632 ( V_4 ) ;
V_121 |= V_1033 ;
F_633 ( V_4 , V_121 ) ;
F_635 ( 100 ) ;
if ( F_53 ( ( F_632 ( V_4 ) & V_1034 ) == 0 ,
1 ) )
F_129 ( L_167 ) ;
if ( V_1030 ) {
V_121 = F_4 ( V_755 ) ;
V_121 |= V_1035 ;
F_126 ( V_755 , V_121 ) ;
F_127 ( V_755 ) ;
}
}
static void F_636 ( struct V_3 * V_4 )
{
T_4 V_121 ;
V_121 = F_4 ( V_755 ) ;
if ( ( V_121 & ( V_677 | V_1032 | V_757 |
V_1035 ) ) == V_677 )
return;
F_637 ( V_4 , V_1036 ) ;
if ( V_121 & V_1035 ) {
V_121 &= ~ V_1035 ;
F_126 ( V_755 , V_121 ) ;
F_127 ( V_755 ) ;
}
V_121 = F_632 ( V_4 ) ;
V_121 |= V_1037 ;
V_121 &= ~ V_1033 ;
F_633 ( V_4 , V_121 ) ;
V_121 = F_4 ( V_755 ) ;
V_121 &= ~ V_1032 ;
F_126 ( V_755 , V_121 ) ;
if ( F_53 ( F_4 ( V_755 ) & V_677 , 5 ) )
F_129 ( L_168 ) ;
if ( V_121 & V_757 ) {
V_121 = F_4 ( V_755 ) ;
V_121 &= ~ V_757 ;
F_126 ( V_755 , V_121 ) ;
if ( F_593 ( ( F_4 ( V_755 ) &
V_1031 ) == 0 , 1 ) )
F_129 ( L_169 ) ;
}
F_638 ( V_4 , V_1036 ) ;
F_428 ( V_4 -> V_2 ) ;
}
void F_639 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_121 ;
F_150 ( L_170 ) ;
if ( V_4 -> V_971 == V_972 ) {
V_121 = F_4 ( V_1038 ) ;
V_121 &= ~ V_1039 ;
F_126 ( V_1038 , V_121 ) ;
}
F_596 ( V_2 ) ;
F_634 ( V_4 , true , true ) ;
}
void F_640 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_121 ;
F_150 ( L_171 ) ;
F_636 ( V_4 ) ;
F_597 ( V_2 ) ;
if ( V_4 -> V_971 == V_972 ) {
V_121 = F_4 ( V_1038 ) ;
V_121 |= V_1039 ;
F_126 ( V_1038 , V_121 ) ;
}
F_641 ( V_2 ) ;
}
static void F_642 ( struct V_20 * V_715 )
{
struct V_1 * V_2 = V_715 -> V_2 ;
unsigned int V_716 = F_348 ( V_715 ) -> V_627 ;
F_429 ( V_2 , V_716 ) ;
}
static int F_643 ( struct V_20 * V_11 )
{
struct V_12 * V_12 ;
struct V_18 * V_19 ;
int V_1040 = 0 ;
F_137 (state->dev, intel_crtc) {
int V_1041 ;
V_19 = F_458 ( V_11 , V_12 ) ;
if ( F_459 ( V_19 ) )
return F_460 ( V_19 ) ;
if ( ! V_19 -> V_15 . V_242 )
continue;
V_1041 = F_501 ( V_19 ) ;
if ( F_232 ( V_11 -> V_2 ) && V_19 -> V_559 )
V_1041 = F_183 ( V_1041 * 100 , 95 ) ;
V_1040 = V_66 ( V_1040 , V_1041 ) ;
}
return V_1040 ;
}
static void F_644 ( struct V_1 * V_2 , int V_627 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_121 , V_1042 ;
int V_302 ;
if ( F_54 ( ( F_4 ( V_755 ) &
( V_1032 | V_677 |
V_1043 | V_1044 |
V_1045 | V_1035 |
V_757 ) ) != V_677 ,
L_172 ) )
return;
F_62 ( & V_4 -> V_560 . V_561 ) ;
V_302 = F_359 ( V_4 ,
V_1046 , 0x0 ) ;
F_64 ( & V_4 -> V_560 . V_561 ) ;
if ( V_302 ) {
F_129 ( L_173 ) ;
return;
}
V_121 = F_4 ( V_755 ) ;
V_121 |= V_757 ;
F_126 ( V_755 , V_121 ) ;
if ( F_593 ( F_4 ( V_755 ) &
V_1031 , 1 ) )
F_129 ( L_165 ) ;
V_121 = F_4 ( V_755 ) ;
V_121 &= ~ V_756 ;
switch ( V_627 ) {
case 450000 :
V_121 |= V_758 ;
V_1042 = 0 ;
break;
case 540000 :
V_121 |= V_759 ;
V_1042 = 1 ;
break;
case 337500 :
V_121 |= V_760 ;
V_1042 = 2 ;
break;
case 675000 :
V_121 |= V_1047 ;
V_1042 = 3 ;
break;
default:
F_54 ( 1 , L_174 ) ;
return;
}
F_126 ( V_755 , V_121 ) ;
V_121 = F_4 ( V_755 ) ;
V_121 &= ~ V_757 ;
F_126 ( V_755 , V_121 ) ;
if ( F_593 ( ( F_4 ( V_755 ) &
V_1031 ) == 0 , 1 ) )
F_129 ( L_169 ) ;
F_62 ( & V_4 -> V_560 . V_561 ) ;
F_359 ( V_4 , V_648 , V_1042 ) ;
F_64 ( & V_4 -> V_560 . V_561 ) ;
F_428 ( V_2 ) ;
F_54 ( V_627 != V_4 -> V_628 ,
L_175 ,
V_627 , V_4 -> V_628 ) ;
}
static int F_645 ( struct V_20 * V_11 )
{
struct V_3 * V_4 = F_266 ( V_11 -> V_2 ) ;
int V_706 = F_643 ( V_11 ) ;
int V_627 ;
if ( V_706 > 540000 )
V_627 = 675000 ;
else if ( V_706 > 450000 )
V_627 = 540000 ;
else if ( V_706 > 337500 )
V_627 = 450000 ;
else
V_627 = 337500 ;
if ( V_627 > V_4 -> V_633 ) {
F_129 ( L_176 ,
V_627 , V_4 -> V_633 ) ;
V_627 = V_4 -> V_633 ;
}
F_348 ( V_11 ) -> V_627 = V_627 ;
return 0 ;
}
static void F_646 ( struct V_20 * V_715 )
{
struct V_1 * V_2 = V_715 -> V_2 ;
unsigned int V_716 = F_348 ( V_715 ) -> V_627 ;
F_644 ( V_2 , V_716 ) ;
}
static int F_647 ( struct V_12 * V_13 ,
struct V_18 * V_19 )
{
if ( ! F_648 ( V_13 , V_19 ) )
return - V_304 ;
V_13 -> V_825 = false ;
return 0 ;
}
static void F_649 ( struct V_3 * V_4 ,
enum V_106 V_106 ,
struct V_18 * V_210 )
{
switch ( V_106 ) {
case V_605 :
V_210 -> V_1048 = V_672 ;
V_210 -> V_128 = V_1049 ;
break;
case V_108 :
V_210 -> V_1048 = V_1050 ;
V_210 -> V_128 = V_1051 ;
break;
case V_110 :
V_210 -> V_1048 = V_1052 ;
V_210 -> V_128 = V_1053 ;
break;
default:
F_129 ( L_177 ) ;
}
}
static void F_650 ( struct V_3 * V_4 ,
enum V_106 V_106 ,
struct V_18 * V_210 )
{
T_1 V_454 , V_1054 ;
V_454 = F_4 ( V_1055 ) & F_651 ( V_106 ) ;
V_210 -> V_1048 = V_454 >> ( V_106 * 3 + 1 ) ;
switch ( V_210 -> V_1048 ) {
case V_672 :
V_1054 = F_4 ( V_671 ) ;
V_210 -> V_211 . V_1056 = V_1054 & 0x3f ;
break;
case V_1050 :
V_210 -> V_128 = V_1049 ;
break;
case V_1052 :
V_210 -> V_128 = V_1051 ;
break;
case V_1057 :
V_210 -> V_128 = V_1053 ;
break;
}
}
static void F_652 ( struct V_3 * V_4 ,
enum V_106 V_106 ,
struct V_18 * V_210 )
{
V_210 -> V_1048 = F_4 ( F_653 ( V_106 ) ) ;
switch ( V_210 -> V_1048 ) {
case V_1058 :
V_210 -> V_128 = V_1059 ;
break;
case V_1060 :
V_210 -> V_128 = V_1061 ;
break;
}
}
static void F_654 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_127 * V_130 ;
enum V_106 V_106 ;
T_4 V_215 ;
V_215 = F_4 ( F_69 ( V_210 -> V_96 ) ) ;
V_106 = ( V_215 & V_1062 ) >> V_1063 ;
if ( F_425 ( V_2 ) )
F_650 ( V_4 , V_106 , V_210 ) ;
else if ( F_18 ( V_2 ) )
F_649 ( V_4 , V_106 , V_210 ) ;
else
F_652 ( V_4 , V_106 , V_210 ) ;
if ( V_210 -> V_128 >= 0 ) {
V_130 = & V_4 -> V_129 [ V_210 -> V_128 ] ;
F_2 ( ! V_130 -> V_133 ( V_4 , V_130 ,
& V_210 -> V_211 ) ) ;
}
if ( F_51 ( V_2 ) -> V_103 < 9 &&
( V_106 == V_117 ) && F_4 ( V_258 ) & V_178 ) {
V_210 -> V_261 = true ;
V_215 = F_4 ( F_72 ( V_142 ) ) ;
V_210 -> V_467 = ( ( V_466 & V_215 ) >>
V_1006 ) + 1 ;
F_622 ( V_13 , V_210 ) ;
}
}
static bool F_655 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_604 V_1064 ;
T_4 V_215 ;
if ( ! F_83 ( V_4 ,
F_417 ( V_13 -> V_94 ) ) )
return false ;
V_210 -> V_96 = (enum V_93 ) V_13 -> V_94 ;
V_210 -> V_128 = V_946 ;
V_215 = F_4 ( F_69 ( V_592 ) ) ;
if ( V_215 & V_135 ) {
enum V_94 V_1065 ;
switch ( V_215 & V_1066 ) {
default:
F_54 ( 1 , L_178 ) ;
case V_1067 :
case V_1068 :
V_1065 = V_142 ;
break;
case V_1069 :
V_1065 = V_151 ;
break;
case V_1070 :
V_1065 = V_517 ;
break;
}
if ( V_1065 == V_13 -> V_94 )
V_210 -> V_96 = V_592 ;
}
if ( ! F_83 ( V_4 ,
F_84 ( V_210 -> V_96 ) ) )
return false ;
V_215 = F_4 ( F_52 ( V_210 -> V_96 ) ) ;
if ( ! ( V_215 & V_163 ) )
return false ;
F_654 ( V_13 , V_210 ) ;
F_577 ( V_13 , V_210 ) ;
if ( F_51 ( V_2 ) -> V_103 >= 9 ) {
F_656 ( V_2 , V_13 , V_210 ) ;
}
V_1064 = F_418 ( V_13 -> V_94 ) ;
if ( F_51 ( V_2 ) -> V_103 >= 9 ) {
V_210 -> V_385 . V_422 = - 1 ;
V_210 -> V_385 . V_541 &= ~ ( 1 << V_550 ) ;
}
if ( F_83 ( V_4 , V_1064 ) ) {
if ( F_51 ( V_2 ) -> V_103 == 9 )
F_623 ( V_13 , V_210 ) ;
else if ( F_51 ( V_2 ) -> V_103 < 9 )
F_625 ( V_13 , V_210 ) ;
else
F_178 ( F_51 ( V_2 ) -> V_103 ) ;
}
if ( F_231 ( V_2 ) )
V_210 -> V_559 = F_392 ( V_13 ) &&
( F_4 ( V_563 ) & V_564 ) ;
if ( V_210 -> V_96 != V_592 ) {
V_210 -> V_593 =
F_4 ( F_396 ( V_210 -> V_96 ) ) + 1 ;
} else {
V_210 -> V_593 = 1 ;
}
return true ;
}
static void F_657 ( struct V_86 * V_13 , T_1 V_15 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
T_4 V_1071 = 0 , V_293 = 0 ;
if ( V_15 ) {
unsigned int V_350 = V_12 -> V_15 . V_1072 -> V_11 -> V_361 ;
unsigned int V_273 = V_12 -> V_15 . V_1072 -> V_11 -> V_362 ;
unsigned int V_349 = F_658 ( V_350 ) * 4 ;
switch ( V_349 ) {
default:
F_177 ( 1 , L_179 ,
V_350 , V_349 ) ;
V_349 = 256 ;
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
}
V_1071 |= V_158 |
V_1073 |
V_1074 |
F_659 ( V_349 ) ;
V_293 = ( V_273 << 12 ) | V_350 ;
}
if ( V_12 -> V_1075 != 0 &&
( V_12 -> V_1076 != V_15 ||
V_12 -> V_1077 != V_293 ||
V_12 -> V_1075 != V_1071 ) ) {
F_126 ( V_157 , 0 ) ;
F_127 ( V_157 ) ;
V_12 -> V_1075 = 0 ;
}
if ( V_12 -> V_1076 != V_15 ) {
F_126 ( V_1078 , V_15 ) ;
V_12 -> V_1076 = V_15 ;
}
if ( V_12 -> V_1077 != V_293 ) {
F_126 ( V_1079 , V_293 ) ;
V_12 -> V_1077 = V_293 ;
}
if ( V_12 -> V_1075 != V_1071 ) {
F_126 ( V_157 , V_1071 ) ;
F_127 ( V_157 ) ;
V_12 -> V_1075 = V_1071 ;
}
}
static void F_660 ( struct V_86 * V_13 , T_1 V_15 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
int V_94 = V_12 -> V_94 ;
T_4 V_1071 ;
V_1071 = 0 ;
if ( V_15 ) {
V_1071 = V_1080 ;
switch ( V_12 -> V_15 . V_1072 -> V_11 -> V_361 ) {
case 64 :
V_1071 |= V_1081 ;
break;
case 128 :
V_1071 |= V_1082 ;
break;
case 256 :
V_1071 |= V_1083 ;
break;
default:
F_178 ( V_12 -> V_15 . V_1072 -> V_11 -> V_361 ) ;
return;
}
V_1071 |= V_94 << 28 ;
if ( F_231 ( V_2 ) || F_232 ( V_2 ) )
V_1071 |= V_1084 ;
}
if ( V_13 -> V_1072 -> V_11 -> V_284 == F_226 ( V_379 ) )
V_1071 |= V_1085 ;
if ( V_12 -> V_1075 != V_1071 ) {
F_126 ( F_81 ( V_94 ) , V_1071 ) ;
F_127 ( F_81 ( V_94 ) ) ;
V_12 -> V_1075 = V_1071 ;
}
F_126 ( F_661 ( V_94 ) , V_15 ) ;
F_127 ( F_661 ( V_94 ) ) ;
V_12 -> V_1076 = V_15 ;
}
static void F_662 ( struct V_86 * V_13 ,
bool V_238 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
int V_94 = V_12 -> V_94 ;
int V_311 = V_13 -> V_1086 ;
int V_312 = V_13 -> V_1087 ;
T_1 V_15 = 0 , V_556 = 0 ;
if ( V_238 )
V_15 = V_12 -> V_1088 ;
if ( V_311 >= V_12 -> V_90 -> V_374 )
V_15 = 0 ;
if ( V_312 >= V_12 -> V_90 -> V_373 )
V_15 = 0 ;
if ( V_311 < 0 ) {
if ( V_311 + V_12 -> V_15 . V_1072 -> V_11 -> V_361 <= 0 )
V_15 = 0 ;
V_556 |= V_1089 << V_1090 ;
V_311 = - V_311 ;
}
V_556 |= V_311 << V_1090 ;
if ( V_312 < 0 ) {
if ( V_312 + V_12 -> V_15 . V_1072 -> V_11 -> V_362 <= 0 )
V_15 = 0 ;
V_556 |= V_1089 << V_1091 ;
V_312 = - V_312 ;
}
V_556 |= V_312 << V_1091 ;
if ( V_15 == 0 && V_12 -> V_1076 == 0 )
return;
F_126 ( F_663 ( V_94 ) , V_556 ) ;
if ( F_168 ( V_2 ) &&
V_13 -> V_1072 -> V_11 -> V_284 == F_226 ( V_379 ) ) {
V_15 += ( V_12 -> V_15 . V_1072 -> V_11 -> V_362 *
V_12 -> V_15 . V_1072 -> V_11 -> V_361 - 1 ) * 4 ;
}
if ( F_79 ( V_2 ) || F_80 ( V_2 ) )
F_657 ( V_13 , V_15 ) ;
else
F_660 ( V_13 , V_15 ) ;
}
static bool F_664 ( struct V_1 * V_2 ,
T_4 V_350 , T_4 V_273 )
{
if ( V_350 == 0 || V_273 == 0 )
return false ;
if ( F_79 ( V_2 ) || F_80 ( V_2 ) ) {
if ( ( V_350 & 63 ) != 0 )
return false ;
if ( V_350 > ( F_79 ( V_2 ) ? 64 : 512 ) )
return false ;
if ( V_273 > 1023 )
return false ;
} else {
switch ( V_350 | V_273 ) {
case 256 :
case 128 :
if ( F_23 ( V_2 ) )
return false ;
case 64 :
break;
default:
return false ;
}
}
return true ;
}
static void F_665 ( struct V_86 * V_13 , T_5 * V_1092 , T_5 * V_1093 ,
T_5 * V_1094 , T_4 V_1095 , T_4 V_293 )
{
int V_1096 = ( V_1095 + V_293 > 256 ) ? 256 : V_1095 + V_293 , V_25 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
for ( V_25 = V_1095 ; V_25 < V_1096 ; V_25 ++ ) {
V_12 -> V_569 [ V_25 ] = V_1092 [ V_25 ] >> 8 ;
V_12 -> V_570 [ V_25 ] = V_1093 [ V_25 ] >> 8 ;
V_12 -> V_571 [ V_25 ] = V_1094 [ V_25 ] >> 8 ;
}
F_362 ( V_13 ) ;
}
struct V_276 *
F_666 ( struct V_1 * V_2 ,
struct V_343 * V_344 ,
struct V_299 * V_300 )
{
struct V_938 * V_939 ;
int V_302 ;
V_939 = F_489 ( sizeof( * V_939 ) , V_734 ) ;
if ( ! V_939 ) {
F_207 ( & V_300 -> V_15 ) ;
return F_667 ( - V_730 ) ;
}
V_302 = F_205 ( V_2 , V_939 , V_344 , V_300 ) ;
if ( V_302 )
goto V_73;
return & V_939 -> V_15 ;
V_73:
F_207 ( & V_300 -> V_15 ) ;
F_212 ( V_939 ) ;
return F_667 ( V_302 ) ;
}
static struct V_276 *
F_668 ( struct V_1 * V_2 ,
struct V_343 * V_344 ,
struct V_299 * V_300 )
{
struct V_276 * V_89 ;
int V_302 ;
V_302 = F_669 ( V_2 ) ;
if ( V_302 )
return F_667 ( V_302 ) ;
V_89 = F_666 ( V_2 , V_344 , V_300 ) ;
F_64 ( & V_2 -> V_303 ) ;
return V_89 ;
}
static T_1
F_670 ( int V_350 , int V_993 )
{
T_1 V_286 = F_183 ( V_350 * V_993 , 8 ) ;
return F_180 ( V_286 , 64 ) ;
}
static T_1
F_671 ( struct V_447 * V_431 , int V_993 )
{
T_1 V_286 = F_670 ( V_431 -> V_551 , V_993 ) ;
return F_672 ( V_286 * V_431 -> V_552 ) ;
}
static struct V_276 *
F_673 ( struct V_1 * V_2 ,
struct V_447 * V_431 ,
int V_1097 , int V_993 )
{
struct V_299 * V_300 ;
struct V_343 V_344 = { 0 } ;
V_300 = F_674 ( V_2 ,
F_671 ( V_431 , V_993 ) ) ;
if ( V_300 == NULL )
return F_667 ( - V_730 ) ;
V_344 . V_350 = V_431 -> V_551 ;
V_344 . V_273 = V_431 -> V_552 ;
V_344 . V_287 [ 0 ] = F_670 ( V_344 . V_350 ,
V_993 ) ;
V_344 . V_265 = F_675 ( V_993 , V_1097 ) ;
return F_668 ( V_2 , & V_344 , V_300 ) ;
}
static struct V_276 *
F_676 ( struct V_1 * V_2 ,
struct V_447 * V_431 )
{
#ifdef F_677
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_299 * V_300 ;
struct V_276 * V_89 ;
if ( ! V_4 -> V_1098 )
return NULL ;
if ( ! V_4 -> V_1098 -> V_89 )
return NULL ;
V_300 = V_4 -> V_1098 -> V_89 -> V_300 ;
F_124 ( ! V_300 ) ;
V_89 = & V_4 -> V_1098 -> V_89 -> V_15 ;
if ( V_89 -> V_287 [ 0 ] < F_670 ( V_431 -> V_551 ,
V_89 -> V_382 ) )
return NULL ;
if ( V_300 -> V_15 . V_293 < V_431 -> V_552 * V_89 -> V_287 [ 0 ] )
return NULL ;
return V_89 ;
#else
return NULL ;
#endif
}
static int F_678 ( struct V_20 * V_11 ,
struct V_86 * V_13 ,
struct V_447 * V_431 ,
struct V_276 * V_89 ,
int V_311 , int V_312 )
{
struct V_277 * V_278 ;
int V_551 , V_552 ;
int V_302 ;
V_278 = F_679 ( V_11 , V_13 -> V_88 ) ;
if ( F_459 ( V_278 ) )
return F_460 ( V_278 ) ;
if ( V_431 )
F_680 ( V_431 , & V_551 , & V_552 ) ;
else
V_551 = V_552 = 0 ;
V_302 = F_681 ( V_278 , V_89 ? V_13 : NULL ) ;
if ( V_302 )
return V_302 ;
F_682 ( V_278 , V_89 ) ;
V_278 -> V_360 = 0 ;
V_278 -> V_1099 = 0 ;
V_278 -> V_361 = V_551 ;
V_278 -> V_362 = V_552 ;
V_278 -> V_356 = V_311 << 16 ;
V_278 -> V_357 = V_312 << 16 ;
V_278 -> V_358 = V_551 << 16 ;
V_278 -> V_359 = V_552 << 16 ;
return 0 ;
}
bool F_683 ( struct V_21 * V_22 ,
struct V_447 * V_431 ,
struct V_1100 * V_1101 ,
struct V_726 * V_727 )
{
struct V_12 * V_12 ;
struct V_16 * V_16 =
F_684 ( V_22 ) ;
struct V_86 * V_1102 ;
struct V_731 * V_17 = & V_16 -> V_15 ;
struct V_86 * V_13 = NULL ;
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_276 * V_89 ;
struct V_724 * V_90 = & V_2 -> V_725 ;
struct V_20 * V_11 = NULL ;
struct V_23 * V_24 ;
struct V_18 * V_19 ;
int V_302 , V_25 = - 1 ;
F_150 ( L_180 ,
V_22 -> V_15 . V_240 , V_22 -> V_134 ,
V_17 -> V_15 . V_240 , V_17 -> V_134 ) ;
V_472:
V_302 = F_260 ( & V_90 -> V_1103 , V_727 ) ;
if ( V_302 )
goto V_800;
if ( V_17 -> V_13 ) {
V_13 = V_17 -> V_13 ;
V_302 = F_260 ( & V_13 -> V_437 , V_727 ) ;
if ( V_302 )
goto V_800;
V_302 = F_260 ( & V_13 -> V_88 -> V_437 , V_727 ) ;
if ( V_302 )
goto V_800;
V_1101 -> V_1104 = V_22 -> V_1105 ;
V_1101 -> V_1106 = false ;
if ( V_22 -> V_1105 != V_1107 )
V_22 -> V_1108 -> V_1105 ( V_22 , V_1107 ) ;
return true ;
}
F_213 (dev, possible_crtc) {
V_25 ++ ;
if ( ! ( V_17 -> V_1109 & ( 1 << V_25 ) ) )
continue;
if ( V_1102 -> V_11 -> V_242 )
continue;
V_13 = V_1102 ;
break;
}
if ( ! V_13 ) {
F_150 ( L_181 ) ;
goto V_800;
}
V_302 = F_260 ( & V_13 -> V_437 , V_727 ) ;
if ( V_302 )
goto V_800;
V_302 = F_260 ( & V_13 -> V_88 -> V_437 , V_727 ) ;
if ( V_302 )
goto V_800;
V_12 = F_41 ( V_13 ) ;
V_1101 -> V_1104 = V_22 -> V_1105 ;
V_1101 -> V_1106 = true ;
V_1101 -> V_1110 = NULL ;
V_11 = F_480 ( V_2 ) ;
if ( ! V_11 )
return false ;
V_11 -> V_728 = V_727 ;
V_24 = F_685 ( V_11 , V_22 ) ;
if ( F_459 ( V_24 ) ) {
V_302 = F_460 ( V_24 ) ;
goto V_800;
}
V_24 -> V_13 = V_13 ;
V_24 -> V_27 = & V_16 -> V_15 ;
V_19 = F_458 ( V_11 , V_12 ) ;
if ( F_459 ( V_19 ) ) {
V_302 = F_460 ( V_19 ) ;
goto V_800;
}
V_19 -> V_15 . V_87 = V_19 -> V_15 . V_242 = true ;
if ( ! V_431 )
V_431 = & V_1111 ;
V_89 = F_676 ( V_2 , V_431 ) ;
if ( V_89 == NULL ) {
F_150 ( L_182 ) ;
V_89 = F_673 ( V_2 , V_431 , 24 , 32 ) ;
V_1101 -> V_1110 = V_89 ;
} else
F_150 ( L_183 ) ;
if ( F_459 ( V_89 ) ) {
F_150 ( L_184 ) ;
goto V_800;
}
V_302 = F_678 ( V_11 , V_13 , V_431 , V_89 , 0 , 0 ) ;
if ( V_302 )
goto V_800;
F_686 ( & V_19 -> V_15 . V_431 , V_431 ) ;
if ( F_483 ( V_11 ) ) {
F_150 ( L_185 ) ;
if ( V_1101 -> V_1110 )
V_1101 -> V_1110 -> V_1108 -> V_1112 ( V_1101 -> V_1110 ) ;
goto V_800;
}
V_13 -> V_88 -> V_13 = V_13 ;
F_302 ( V_2 , V_12 -> V_94 ) ;
return true ;
V_800:
F_484 ( V_11 ) ;
V_11 = NULL ;
if ( V_302 == - V_308 ) {
F_687 ( V_727 ) ;
goto V_472;
}
return false ;
}
void F_688 ( struct V_21 * V_22 ,
struct V_1100 * V_1101 ,
struct V_726 * V_727 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_16 * V_16 =
F_684 ( V_22 ) ;
struct V_731 * V_17 = & V_16 -> V_15 ;
struct V_86 * V_13 = V_17 -> V_13 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_20 * V_11 ;
struct V_23 * V_24 ;
struct V_18 * V_19 ;
int V_302 ;
F_150 ( L_180 ,
V_22 -> V_15 . V_240 , V_22 -> V_134 ,
V_17 -> V_15 . V_240 , V_17 -> V_134 ) ;
if ( V_1101 -> V_1106 ) {
V_11 = F_480 ( V_2 ) ;
if ( ! V_11 )
goto V_800;
V_11 -> V_728 = V_727 ;
V_24 = F_685 ( V_11 , V_22 ) ;
if ( F_459 ( V_24 ) )
goto V_800;
V_19 = F_458 ( V_11 , V_12 ) ;
if ( F_459 ( V_19 ) )
goto V_800;
V_24 -> V_27 = NULL ;
V_24 -> V_13 = NULL ;
V_19 -> V_15 . V_242 = V_19 -> V_15 . V_87 = false ;
V_302 = F_678 ( V_11 , V_13 , NULL , NULL ,
0 , 0 ) ;
if ( V_302 )
goto V_800;
V_302 = F_483 ( V_11 ) ;
if ( V_302 )
goto V_800;
if ( V_1101 -> V_1110 ) {
F_689 ( V_1101 -> V_1110 ) ;
F_209 ( V_1101 -> V_1110 ) ;
}
return;
}
if ( V_1101 -> V_1104 != V_1107 )
V_22 -> V_1108 -> V_1105 ( V_22 , V_1101 -> V_1104 ) ;
return;
V_800:
F_150 ( L_186 ) ;
F_484 ( V_11 ) ;
}
static int F_690 ( struct V_1 * V_2 ,
const struct V_18 * V_210 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_62 = V_210 -> V_211 . V_62 ;
if ( ( V_62 & V_1113 ) == V_893 )
return V_4 -> V_818 . V_821 ;
else if ( F_3 ( V_2 ) )
return 120000 ;
else if ( ! F_23 ( V_2 ) )
return 96000 ;
else
return 48000 ;
}
static void F_589 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_94 = V_210 -> V_96 ;
T_1 V_62 = V_210 -> V_211 . V_62 ;
T_1 V_823 ;
T_3 clock ;
int V_855 ;
int V_28 = F_690 ( V_2 , V_210 ) ;
if ( ( V_62 & V_1114 ) == 0 )
V_823 = V_210 -> V_211 . V_721 ;
else
V_823 = V_210 -> V_211 . V_722 ;
clock . V_63 = ( V_823 & V_1115 ) >> V_1116 ;
if ( F_20 ( V_2 ) ) {
clock . V_59 = F_691 ( ( V_823 & V_1117 ) >> V_1118 ) - 1 ;
clock . V_55 = ( V_823 & V_1119 ) >> V_1120 ;
} else {
clock . V_59 = ( V_823 & V_1121 ) >> V_1118 ;
clock . V_55 = ( V_823 & V_1122 ) >> V_1120 ;
}
if ( ! F_23 ( V_2 ) ) {
if ( F_20 ( V_2 ) )
clock . V_57 = F_691 ( ( V_62 & V_1123 ) >>
V_883 ) ;
else
clock . V_57 = F_691 ( ( V_62 & V_1124 ) >>
V_884 ) ;
switch ( V_62 & V_1125 ) {
case V_880 :
clock . V_58 = V_62 & V_886 ?
5 : 10 ;
break;
case V_879 :
clock . V_58 = V_62 & V_887 ?
7 : 14 ;
break;
default:
F_150 ( L_187
L_188 , ( int ) ( V_62 & V_1125 ) ) ;
return;
}
if ( F_20 ( V_2 ) )
V_855 = F_24 ( V_28 , & clock ) ;
else
V_855 = F_27 ( V_28 , & clock ) ;
} else {
T_1 V_1126 = F_139 ( V_2 ) ? 0 : F_4 ( V_153 ) ;
bool V_979 = ( V_94 == 1 ) && ( V_1126 & V_189 ) ;
if ( V_979 ) {
clock . V_57 = F_691 ( ( V_62 & V_1127 ) >>
V_884 ) ;
if ( V_1126 & V_1128 )
clock . V_58 = 7 ;
else
clock . V_58 = 14 ;
} else {
if ( V_62 & V_895 )
clock . V_57 = 2 ;
else {
clock . V_57 = ( ( V_62 & V_1129 ) >>
V_884 ) + 2 ;
}
if ( V_62 & V_896 )
clock . V_58 = 4 ;
else
clock . V_58 = 2 ;
}
V_855 = F_27 ( V_28 , & clock ) ;
}
V_210 -> V_855 = V_855 ;
}
int F_692 ( int V_1130 ,
const struct V_810 * V_811 )
{
if ( ! V_811 -> V_816 )
return 0 ;
return F_39 ( ( V_1131 ) V_811 -> V_815 * V_1130 , V_811 -> V_816 ) ;
}
static void F_629 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
F_589 ( V_13 , V_210 ) ;
V_210 -> V_15 . V_91 . V_92 =
F_692 ( F_5 ( V_2 ) * 10000 ,
& V_210 -> V_589 ) ;
}
struct V_447 * F_693 ( struct V_1 * V_2 ,
struct V_86 * V_13 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
enum V_93 V_96 = V_12 -> V_90 -> V_96 ;
struct V_447 * V_431 ;
struct V_18 V_210 ;
int V_1132 = F_4 ( F_321 ( V_96 ) ) ;
int V_915 = F_4 ( F_325 ( V_96 ) ) ;
int V_1133 = F_4 ( F_327 ( V_96 ) ) ;
int V_1134 = F_4 ( F_331 ( V_96 ) ) ;
enum V_94 V_94 = V_12 -> V_94 ;
V_431 = F_489 ( sizeof( * V_431 ) , V_734 ) ;
if ( ! V_431 )
return NULL ;
V_210 . V_96 = (enum V_93 ) V_94 ;
V_210 . V_593 = 1 ;
V_210 . V_211 . V_62 = F_4 ( F_59 ( V_94 ) ) ;
V_210 . V_211 . V_721 = F_4 ( F_473 ( V_94 ) ) ;
V_210 . V_211 . V_722 = F_4 ( F_474 ( V_94 ) ) ;
F_589 ( V_12 , & V_210 ) ;
V_431 -> clock = V_210 . V_855 / V_210 . V_593 ;
V_431 -> V_551 = ( V_1132 & 0xffff ) + 1 ;
V_431 -> V_909 = ( ( V_1132 & 0xffff0000 ) >> 16 ) + 1 ;
V_431 -> V_747 = ( V_915 & 0xffff ) + 1 ;
V_431 -> V_910 = ( ( V_915 & 0xffff0000 ) >> 16 ) + 1 ;
V_431 -> V_552 = ( V_1133 & 0xffff ) + 1 ;
V_431 -> V_911 = ( ( V_1133 & 0xffff0000 ) >> 16 ) + 1 ;
V_431 -> V_912 = ( V_1134 & 0xffff ) + 1 ;
V_431 -> V_913 = ( ( V_1134 & 0xffff0000 ) >> 16 ) + 1 ;
F_581 ( V_431 ) ;
return V_431 ;
}
void F_694 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_305 . V_1135 )
return;
F_190 ( V_4 ) ;
F_695 ( V_4 ) ;
if ( F_51 ( V_2 ) -> V_103 >= 6 )
F_696 ( V_4 ) ;
V_4 -> V_305 . V_1135 = true ;
}
void F_697 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_305 . V_1135 )
return;
V_4 -> V_305 . V_1135 = false ;
if ( F_51 ( V_2 ) -> V_103 >= 6 )
F_698 ( V_2 -> V_5 ) ;
F_194 ( V_4 ) ;
}
static void F_699 ( struct V_86 * V_13 )
{
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_488 * V_489 ;
F_270 ( & V_2 -> V_445 ) ;
V_489 = V_12 -> V_446 ;
V_12 -> V_446 = NULL ;
F_271 ( & V_2 -> V_445 ) ;
if ( V_489 ) {
F_700 ( & V_489 -> V_489 ) ;
F_212 ( V_489 ) ;
}
F_701 ( V_13 ) ;
F_212 ( V_12 ) ;
}
static void F_702 ( struct V_1136 * V_1137 )
{
struct V_488 * V_489 =
F_703 ( V_1137 , struct V_488 , V_489 ) ;
struct V_12 * V_13 = F_41 ( V_489 -> V_13 ) ;
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_294 * V_88 = V_13 -> V_15 . V_88 ;
F_62 ( & V_2 -> V_303 ) ;
F_196 ( V_489 -> V_440 , V_88 -> V_11 ) ;
F_207 ( & V_489 -> V_493 -> V_15 ) ;
if ( V_489 -> V_1138 )
F_704 ( & V_489 -> V_1138 , NULL ) ;
F_64 ( & V_2 -> V_303 ) ;
F_705 ( V_2 , F_216 ( V_88 ) -> V_366 ) ;
F_209 ( V_489 -> V_440 ) ;
F_124 ( F_279 ( & V_13 -> V_487 ) == 0 ) ;
F_706 ( & V_13 -> V_487 ) ;
F_212 ( V_489 ) ;
}
static void F_707 ( struct V_1 * V_2 ,
struct V_86 * V_13 )
{
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_488 * V_489 ;
unsigned long V_351 ;
if ( V_12 == NULL )
return;
F_708 ( & V_2 -> V_445 , V_351 ) ;
V_489 = V_12 -> V_446 ;
F_304 () ;
if ( V_489 == NULL || F_279 ( & V_489 -> V_442 ) < V_1139 ) {
F_709 ( & V_2 -> V_445 , V_351 ) ;
return;
}
F_303 ( V_12 ) ;
F_709 ( & V_2 -> V_445 , V_351 ) ;
}
void F_710 ( struct V_1 * V_2 , int V_94 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_86 * V_13 = V_4 -> V_95 [ V_94 ] ;
F_707 ( V_2 , V_13 ) ;
}
void F_258 ( struct V_1 * V_2 , int V_164 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_86 * V_13 = V_4 -> V_1140 [ V_164 ] ;
F_707 ( V_2 , V_13 ) ;
}
static bool F_711 ( T_1 V_1141 , T_1 V_1142 )
{
return ! ( ( V_1141 - V_1142 ) & 0x80000000 ) ;
}
static bool F_712 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_278 ( & V_4 -> V_443 ) ||
V_13 -> V_444 != F_279 ( & V_4 -> V_443 . V_444 ) )
return true ;
if ( F_51 ( V_2 ) -> V_103 < 5 && ! F_19 ( V_2 ) )
return true ;
return ( F_4 ( F_713 ( V_13 -> V_164 ) ) & ~ 0xfff ) ==
V_13 -> V_446 -> V_1143 &&
F_711 ( F_4 ( F_714 ( V_13 -> V_94 ) ) ,
V_13 -> V_446 -> V_1144 ) ;
}
void F_257 ( struct V_1 * V_2 , int V_164 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 =
F_41 ( V_4 -> V_1140 [ V_164 ] ) ;
unsigned long V_351 ;
F_708 ( & V_2 -> V_445 , V_351 ) ;
if ( V_12 -> V_446 && F_712 ( V_12 ) )
F_715 ( & V_12 -> V_446 -> V_442 ) ;
F_709 ( & V_2 -> V_445 , V_351 ) ;
}
static inline void F_716 ( struct V_12 * V_12 )
{
F_717 () ;
F_718 ( & V_12 -> V_446 -> V_442 , V_1145 ) ;
F_717 () ;
}
static int F_719 ( struct V_1 * V_2 ,
struct V_86 * V_13 ,
struct V_276 * V_89 ,
struct V_299 * V_300 ,
struct V_297 * V_1146 ,
T_4 V_351 )
{
struct V_295 * V_1147 = V_1146 -> V_1147 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
T_1 V_1148 ;
int V_302 ;
V_302 = F_720 ( V_1146 , 6 ) ;
if ( V_302 )
return V_302 ;
if ( V_12 -> V_164 )
V_1148 = V_1149 ;
else
V_1148 = V_1150 ;
F_721 ( V_1147 , V_1151 | V_1148 ) ;
F_721 ( V_1147 , V_1152 ) ;
F_721 ( V_1147 , V_1153 |
F_722 ( V_12 -> V_164 ) ) ;
F_721 ( V_1147 , V_89 -> V_287 [ 0 ] ) ;
F_721 ( V_1147 , V_12 -> V_446 -> V_1143 ) ;
F_721 ( V_1147 , 0 ) ;
F_716 ( V_12 ) ;
return 0 ;
}
static int F_723 ( struct V_1 * V_2 ,
struct V_86 * V_13 ,
struct V_276 * V_89 ,
struct V_299 * V_300 ,
struct V_297 * V_1146 ,
T_4 V_351 )
{
struct V_295 * V_1147 = V_1146 -> V_1147 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
T_1 V_1148 ;
int V_302 ;
V_302 = F_720 ( V_1146 , 6 ) ;
if ( V_302 )
return V_302 ;
if ( V_12 -> V_164 )
V_1148 = V_1149 ;
else
V_1148 = V_1150 ;
F_721 ( V_1147 , V_1151 | V_1148 ) ;
F_721 ( V_1147 , V_1152 ) ;
F_721 ( V_1147 , V_1154 |
F_722 ( V_12 -> V_164 ) ) ;
F_721 ( V_1147 , V_89 -> V_287 [ 0 ] ) ;
F_721 ( V_1147 , V_12 -> V_446 -> V_1143 ) ;
F_721 ( V_1147 , V_1152 ) ;
F_716 ( V_12 ) ;
return 0 ;
}
static int F_724 ( struct V_1 * V_2 ,
struct V_86 * V_13 ,
struct V_276 * V_89 ,
struct V_299 * V_300 ,
struct V_297 * V_1146 ,
T_4 V_351 )
{
struct V_295 * V_1147 = V_1146 -> V_1147 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
T_4 V_1155 , V_1156 ;
int V_302 ;
V_302 = F_720 ( V_1146 , 4 ) ;
if ( V_302 )
return V_302 ;
F_721 ( V_1147 , V_1153 |
F_722 ( V_12 -> V_164 ) ) ;
F_721 ( V_1147 , V_89 -> V_287 [ 0 ] ) ;
F_721 ( V_1147 , V_12 -> V_446 -> V_1143 |
V_300 -> V_313 ) ;
V_1155 = 0 ;
V_1156 = F_4 ( F_281 ( V_12 -> V_94 ) ) & 0x0fff0fff ;
F_721 ( V_1147 , V_1155 | V_1156 ) ;
F_716 ( V_12 ) ;
return 0 ;
}
static int F_725 ( struct V_1 * V_2 ,
struct V_86 * V_13 ,
struct V_276 * V_89 ,
struct V_299 * V_300 ,
struct V_297 * V_1146 ,
T_4 V_351 )
{
struct V_295 * V_1147 = V_1146 -> V_1147 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
T_4 V_1155 , V_1156 ;
int V_302 ;
V_302 = F_720 ( V_1146 , 4 ) ;
if ( V_302 )
return V_302 ;
F_721 ( V_1147 , V_1153 |
F_722 ( V_12 -> V_164 ) ) ;
F_721 ( V_1147 , V_89 -> V_287 [ 0 ] | V_300 -> V_313 ) ;
F_721 ( V_1147 , V_12 -> V_446 -> V_1143 ) ;
V_1155 = 0 ;
V_1156 = F_4 ( F_281 ( V_12 -> V_94 ) ) & 0x0fff0fff ;
F_721 ( V_1147 , V_1155 | V_1156 ) ;
F_716 ( V_12 ) ;
return 0 ;
}
static int F_726 ( struct V_1 * V_2 ,
struct V_86 * V_13 ,
struct V_276 * V_89 ,
struct V_299 * V_300 ,
struct V_297 * V_1146 ,
T_4 V_351 )
{
struct V_295 * V_1147 = V_1146 -> V_1147 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
T_4 V_1157 = 0 ;
int V_1158 , V_302 ;
switch ( V_12 -> V_164 ) {
case V_1159 :
V_1157 = V_1160 ;
break;
case V_375 :
V_1157 = V_1161 ;
break;
case V_1162 :
V_1157 = V_1163 ;
break;
default:
F_177 ( 1 , L_189 ) ;
return - V_1164 ;
}
V_1158 = 4 ;
if ( V_1147 -> V_240 == V_1165 ) {
V_1158 += 6 ;
if ( F_727 ( V_2 ) )
V_1158 += 2 ;
}
V_302 = F_728 ( V_1146 ) ;
if ( V_302 )
return V_302 ;
V_302 = F_720 ( V_1146 , V_1158 ) ;
if ( V_302 )
return V_302 ;
if ( V_1147 -> V_240 == V_1165 ) {
F_721 ( V_1147 , F_729 ( 1 ) ) ;
F_721 ( V_1147 , V_1166 ) ;
F_721 ( V_1147 , ~ ( V_1167 |
V_1168 |
V_1169 ) ) ;
if ( F_727 ( V_2 ) )
F_721 ( V_1147 , F_730 ( 1 ) |
V_1170 ) ;
else
F_721 ( V_1147 , F_731 ( 1 ) |
V_1170 ) ;
F_721 ( V_1147 , V_1166 ) ;
F_721 ( V_1147 , V_1147 -> V_1171 . V_1143 + 256 ) ;
if ( F_727 ( V_2 ) ) {
F_721 ( V_1147 , 0 ) ;
F_721 ( V_1147 , V_1152 ) ;
}
}
F_721 ( V_1147 , V_1154 | V_1157 ) ;
F_721 ( V_1147 , ( V_89 -> V_287 [ 0 ] | V_300 -> V_313 ) ) ;
F_721 ( V_1147 , V_12 -> V_446 -> V_1143 ) ;
F_721 ( V_1147 , ( V_1152 ) ) ;
F_716 ( V_12 ) ;
return 0 ;
}
static bool F_732 ( struct V_295 * V_1147 ,
struct V_299 * V_300 )
{
if ( V_1147 == NULL )
return true ;
if ( F_51 ( V_1147 -> V_2 ) -> V_103 < 5 )
return false ;
if ( V_448 . F_732 < 0 )
return false ;
else if ( V_448 . F_732 > 0 )
return true ;
else if ( V_448 . V_1172 )
return true ;
else
return V_1147 != F_733 ( V_300 -> V_1173 ) ;
}
static void F_734 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_276 * V_89 = V_12 -> V_15 . V_88 -> V_89 ;
const enum V_94 V_94 = V_12 -> V_94 ;
T_1 V_1174 , V_349 ;
V_1174 = F_4 ( F_92 ( V_94 , 0 ) ) ;
V_1174 &= ~ V_1003 ;
switch ( V_89 -> V_289 [ 0 ] ) {
case V_269 :
break;
case V_270 :
V_1174 |= V_401 ;
break;
case V_271 :
V_1174 |= V_402 ;
break;
case V_272 :
V_1174 |= V_403 ;
break;
default:
F_178 ( V_89 -> V_289 [ 0 ] ) ;
}
V_349 = V_89 -> V_287 [ 0 ] /
F_234 ( V_2 , V_89 -> V_289 [ 0 ] ,
V_89 -> V_265 ) ;
F_126 ( F_92 ( V_94 , 0 ) , V_1174 ) ;
F_126 ( F_251 ( V_94 , 0 ) , V_349 ) ;
F_126 ( F_246 ( V_94 , 0 ) , V_12 -> V_446 -> V_1143 ) ;
F_127 ( F_246 ( V_94 , 0 ) ) ;
}
static void F_735 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_938 * V_939 =
F_206 ( V_12 -> V_15 . V_88 -> V_89 ) ;
struct V_299 * V_300 = V_939 -> V_300 ;
T_1 V_369 ;
T_1 V_97 ;
V_97 = F_86 ( V_12 -> V_164 ) ;
V_369 = F_4 ( V_97 ) ;
if ( V_300 -> V_313 != V_315 )
V_369 |= V_376 ;
else
V_369 &= ~ V_376 ;
F_126 ( V_97 , V_369 ) ;
F_126 ( F_219 ( V_12 -> V_164 ) ,
V_12 -> V_446 -> V_1143 ) ;
F_127 ( F_219 ( V_12 -> V_164 ) ) ;
}
static void F_736 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_15 . V_2 ;
T_1 V_1175 ;
F_716 ( V_12 ) ;
F_737 ( V_12 , & V_1175 ) ;
if ( F_51 ( V_2 ) -> V_103 >= 9 )
F_734 ( V_12 ) ;
else
F_735 ( V_12 ) ;
F_738 ( V_12 , V_1175 ) ;
}
static void F_739 ( struct V_1136 * V_489 )
{
struct V_1176 * V_1177 =
F_703 ( V_489 , struct V_1176 , V_489 ) ;
if ( V_1177 -> V_1146 )
F_2 ( F_740 ( V_1177 -> V_1146 ,
V_1177 -> V_13 -> V_444 ,
false , NULL ,
& V_1177 -> V_448 -> V_560 . V_1178 ) ) ;
F_736 ( V_1177 -> V_13 ) ;
F_741 ( V_1177 -> V_1146 ) ;
F_212 ( V_1177 ) ;
}
static int F_742 ( struct V_1 * V_2 ,
struct V_86 * V_13 ,
struct V_276 * V_89 ,
struct V_299 * V_300 ,
struct V_295 * V_1147 ,
T_4 V_351 )
{
struct V_1176 * V_1177 ;
V_1177 = F_743 ( sizeof( * V_1177 ) , V_734 ) ;
if ( V_1177 == NULL )
return - V_730 ;
V_1177 -> V_448 = F_266 ( V_2 ) ;
V_1177 -> V_1146 = F_744 ( V_300 -> V_1173 ) ;
V_1177 -> V_13 = F_41 ( V_13 ) ;
F_745 ( & V_1177 -> V_489 , F_739 ) ;
F_746 ( & V_1177 -> V_489 ) ;
return 0 ;
}
static int F_747 ( struct V_1 * V_2 ,
struct V_86 * V_13 ,
struct V_276 * V_89 ,
struct V_299 * V_300 ,
struct V_297 * V_1146 ,
T_4 V_351 )
{
return - V_1164 ;
}
static bool F_748 ( struct V_1 * V_2 ,
struct V_86 * V_13 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_488 * V_489 = V_12 -> V_446 ;
T_1 V_1179 ;
if ( F_279 ( & V_489 -> V_442 ) >= V_1139 )
return true ;
if ( ! V_489 -> V_1180 )
return false ;
if ( V_489 -> V_1181 == 0 ) {
if ( V_489 -> V_1138 &&
! F_749 ( V_489 -> V_1138 , true ) )
return false ;
V_489 -> V_1181 = F_750 ( V_13 ) ;
}
if ( F_750 ( V_13 ) - V_489 -> V_1181 < 3 )
return false ;
if ( F_51 ( V_2 ) -> V_103 >= 4 )
V_1179 = F_751 ( F_4 ( F_219 ( V_12 -> V_164 ) ) ) ;
else
V_1179 = F_4 ( F_220 ( V_12 -> V_164 ) ) ;
return V_1179 == V_489 -> V_1143 ;
}
void F_752 ( struct V_1 * V_2 , int V_94 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_86 * V_13 = V_4 -> V_95 [ V_94 ] ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_488 * V_489 ;
F_2 ( ! F_753 () ) ;
if ( V_13 == NULL )
return;
F_754 ( & V_2 -> V_445 ) ;
V_489 = V_12 -> V_446 ;
if ( V_489 != NULL && F_748 ( V_2 , V_13 ) ) {
F_177 ( 1 , L_190 ,
V_489 -> V_1182 , F_755 ( V_2 , V_94 ) ) ;
F_303 ( V_12 ) ;
V_489 = NULL ;
}
if ( V_489 != NULL &&
F_755 ( V_2 , V_94 ) - V_489 -> V_1182 > 1 )
F_756 ( V_2 , V_489 -> V_1138 ) ;
F_757 ( & V_2 -> V_445 ) ;
}
static int F_758 ( struct V_86 * V_13 ,
struct V_276 * V_89 ,
struct V_1183 * V_490 ,
T_4 V_1184 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_276 * V_440 = V_13 -> V_88 -> V_89 ;
struct V_299 * V_300 = F_188 ( V_89 ) ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_294 * V_88 = V_13 -> V_88 ;
enum V_94 V_94 = V_12 -> V_94 ;
struct V_488 * V_489 ;
struct V_295 * V_1147 ;
bool V_1177 ;
struct V_297 * V_1185 = NULL ;
int V_302 ;
if ( F_2 ( F_188 ( V_440 ) == NULL ) )
return - V_309 ;
if ( V_89 -> V_265 != V_13 -> V_88 -> V_89 -> V_265 )
return - V_304 ;
if ( F_51 ( V_2 ) -> V_103 > 3 &&
( V_89 -> V_1186 [ 0 ] != V_13 -> V_88 -> V_89 -> V_1186 [ 0 ] ||
V_89 -> V_287 [ 0 ] != V_13 -> V_88 -> V_89 -> V_287 [ 0 ] ) )
return - V_304 ;
if ( F_759 ( & V_4 -> V_443 ) )
goto V_1187;
V_489 = F_489 ( sizeof( * V_489 ) , V_734 ) ;
if ( V_489 == NULL )
return - V_730 ;
V_489 -> V_490 = V_490 ;
V_489 -> V_13 = V_13 ;
V_489 -> V_440 = V_440 ;
F_745 ( & V_489 -> V_489 , F_702 ) ;
V_302 = F_99 ( V_13 ) ;
if ( V_302 )
goto V_1188;
F_270 ( & V_2 -> V_445 ) ;
if ( V_12 -> V_446 ) {
if ( F_748 ( V_2 , V_13 ) ) {
F_147 ( L_191 ) ;
F_303 ( V_12 ) ;
} else {
F_147 ( L_192 ) ;
F_271 ( & V_2 -> V_445 ) ;
F_100 ( V_13 ) ;
F_212 ( V_489 ) ;
return - V_309 ;
}
}
V_12 -> V_446 = V_489 ;
F_271 ( & V_2 -> V_445 ) ;
if ( F_279 ( & V_12 -> V_487 ) >= 2 )
F_760 ( V_4 -> V_492 ) ;
F_210 ( V_489 -> V_440 ) ;
F_761 ( & V_300 -> V_15 ) ;
V_13 -> V_88 -> V_89 = V_89 ;
F_208 ( V_13 -> V_88 ) ;
V_489 -> V_493 = V_300 ;
V_302 = F_669 ( V_2 ) ;
if ( V_302 )
goto V_1189;
F_762 ( & V_12 -> V_487 ) ;
V_12 -> V_444 = F_279 ( & V_4 -> V_443 . V_444 ) ;
if ( F_51 ( V_2 ) -> V_103 >= 5 || F_19 ( V_2 ) )
V_489 -> V_1144 = F_4 ( F_714 ( V_94 ) ) + 1 ;
if ( F_22 ( V_2 ) ) {
V_1147 = & V_4 -> V_1147 [ V_1190 ] ;
if ( V_300 -> V_313 != F_188 ( V_489 -> V_440 ) -> V_313 )
V_1147 = NULL ;
} else if ( F_286 ( V_2 ) || F_231 ( V_2 ) ) {
V_1147 = & V_4 -> V_1147 [ V_1190 ] ;
} else if ( F_51 ( V_2 ) -> V_103 >= 7 ) {
V_1147 = F_733 ( V_300 -> V_1173 ) ;
if ( V_1147 == NULL || V_1147 -> V_240 != V_1165 )
V_1147 = & V_4 -> V_1147 [ V_1190 ] ;
} else {
V_1147 = & V_4 -> V_1147 [ V_1165 ] ;
}
V_1177 = F_732 ( V_1147 , V_300 ) ;
V_302 = F_187 ( V_13 -> V_88 , V_89 ,
V_13 -> V_88 -> V_11 ,
V_1177 ? F_733 ( V_300 -> V_1173 ) : V_1147 , & V_1185 ) ;
if ( V_302 )
goto V_1191;
V_489 -> V_1143 = F_235 ( F_216 ( V_88 ) , V_300 )
+ V_12 -> V_378 ;
if ( V_1177 ) {
V_302 = F_742 ( V_2 , V_13 , V_89 , V_300 , V_1147 ,
V_1184 ) ;
if ( V_302 )
goto V_1192;
F_704 ( & V_489 -> V_1138 ,
V_300 -> V_1173 ) ;
} else {
if ( ! V_1185 ) {
V_302 = F_763 ( V_1147 , V_1147 -> V_1193 , & V_1185 ) ;
if ( V_302 )
goto V_1192;
}
V_302 = V_4 -> V_435 . V_1194 ( V_2 , V_13 , V_89 , V_300 , V_1185 ,
V_1184 ) ;
if ( V_302 )
goto V_1192;
F_704 ( & V_489 -> V_1138 , V_1185 ) ;
}
if ( V_1185 )
F_764 ( V_1185 ) ;
V_489 -> V_1182 = F_750 ( V_13 ) ;
V_489 -> V_1180 = true ;
F_380 ( F_188 ( V_489 -> V_440 ) , V_300 ,
F_216 ( V_88 ) -> V_366 ) ;
F_64 ( & V_2 -> V_303 ) ;
F_381 ( V_12 ) ;
F_765 ( V_2 ,
F_216 ( V_88 ) -> V_366 ) ;
F_766 ( V_12 -> V_164 , V_300 ) ;
return 0 ;
V_1192:
F_196 ( V_89 , V_13 -> V_88 -> V_11 ) ;
V_1191:
if ( V_1185 )
F_767 ( V_1185 ) ;
F_706 ( & V_12 -> V_487 ) ;
F_64 ( & V_2 -> V_303 ) ;
V_1189:
V_13 -> V_88 -> V_89 = V_440 ;
F_208 ( V_13 -> V_88 ) ;
F_768 ( & V_300 -> V_15 ) ;
F_209 ( V_489 -> V_440 ) ;
F_270 ( & V_2 -> V_445 ) ;
V_12 -> V_446 = NULL ;
F_271 ( & V_2 -> V_445 ) ;
F_100 ( V_13 ) ;
V_1188:
F_212 ( V_489 ) ;
if ( V_302 == - V_1195 ) {
struct V_20 * V_11 ;
struct V_277 * V_278 ;
V_1187:
V_11 = F_480 ( V_2 ) ;
if ( ! V_11 )
return - V_730 ;
V_11 -> V_728 = F_769 ( V_13 ) ;
V_472:
V_278 = F_679 ( V_11 , V_88 ) ;
V_302 = F_482 ( V_278 ) ;
if ( ! V_302 ) {
F_682 ( V_278 , V_89 ) ;
V_302 = F_681 ( V_278 , V_13 ) ;
if ( ! V_302 )
V_302 = F_483 ( V_11 ) ;
}
if ( V_302 == - V_308 ) {
F_687 ( V_11 -> V_728 ) ;
F_770 ( V_11 ) ;
goto V_472;
}
if ( V_302 )
F_484 ( V_11 ) ;
if ( V_302 == 0 && V_490 ) {
F_270 ( & V_2 -> V_445 ) ;
F_305 ( V_2 , V_94 , V_490 ) ;
F_271 ( & V_2 -> V_445 ) ;
}
}
return V_302 ;
}
static bool F_771 ( struct V_294 * V_164 ,
struct V_277 * V_11 )
{
if ( ! V_164 -> V_11 -> V_89 || ! V_11 -> V_89 ||
V_164 -> V_11 -> V_89 -> V_289 [ 0 ] != V_11 -> V_89 -> V_289 [ 0 ] ||
V_164 -> V_11 -> V_284 != V_11 -> V_284 )
return true ;
if ( V_164 -> V_11 -> V_361 != V_11 -> V_361 )
return true ;
return false ;
}
int F_772 ( struct V_10 * V_19 ,
struct V_277 * V_278 )
{
struct V_86 * V_13 = V_19 -> V_13 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_294 * V_164 = V_278 -> V_164 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_417 * V_1196 =
F_218 ( V_164 -> V_11 ) ;
int V_1197 = V_12 -> V_15 . V_15 . V_240 , V_302 ;
int V_25 = F_215 ( V_164 ) ;
bool V_1198 = F_7 ( V_19 ) ;
bool V_1199 = V_13 -> V_11 -> V_87 ;
bool V_1200 = V_19 -> V_87 ;
bool V_1201 , V_1202 , V_367 , V_1203 ;
struct V_276 * V_89 = V_278 -> V_89 ;
if ( V_19 && F_51 ( V_2 ) -> V_103 >= 9 &&
V_164 -> type != V_1204 ) {
V_302 = F_352 (
F_395 ( V_19 ) ,
F_218 ( V_278 ) ) ;
if ( V_302 )
return V_302 ;
}
if ( V_1196 -> V_15 . V_89 && ! V_89 )
V_12 -> V_577 . V_1205 |= 1 << V_25 ;
V_1203 = V_1196 -> V_367 ;
V_367 = F_218 ( V_278 ) -> V_367 ;
if ( ! V_1199 && F_2 ( V_1203 ) )
V_1203 = false ;
if ( ! V_1200 && F_2 ( V_367 ) )
V_367 = false ;
if ( ! V_1203 && ! V_367 )
return 0 ;
V_1201 = V_1203 && ( ! V_367 || V_1198 ) ;
V_1202 = V_367 && ( ! V_1203 || V_1198 ) ;
F_773 ( L_193 , V_1197 ,
V_164 -> V_15 . V_240 , V_89 ? V_89 -> V_15 . V_240 : - 1 ) ;
F_773 ( L_194 ,
V_164 -> V_15 . V_240 , V_1203 , V_367 ,
V_1201 , V_1202 , V_1198 ) ;
if ( V_1202 ) {
V_12 -> V_577 . V_1206 = true ;
if ( V_164 -> type != V_1204 ) {
V_12 -> V_577 . V_580 = true ;
V_12 -> V_577 . V_578 = true ;
V_12 -> V_577 . V_582 = true ;
}
} else if ( V_1201 ) {
V_12 -> V_577 . V_582 = true ;
if ( V_164 -> type != V_1204 ) {
if ( V_1200 )
V_12 -> V_577 . V_578 = true ;
V_12 -> V_577 . V_580 = true ;
}
} else if ( F_771 ( V_164 , V_278 ) ) {
V_12 -> V_577 . V_1206 = true ;
}
if ( V_367 )
V_12 -> V_577 . V_579 |=
F_216 ( V_164 ) -> V_366 ;
switch ( V_164 -> type ) {
case V_1207 :
V_12 -> V_577 . V_585 = true ;
V_12 -> V_577 . V_587 = V_1201 ;
V_12 -> V_577 . V_584 = V_1202 ;
if ( V_1201 ) {
V_12 -> V_577 . V_586 = true ;
V_12 -> V_577 . V_434 = true ;
}
if ( V_367 &&
F_51 ( V_2 ) -> V_103 <= 4 && ! F_19 ( V_2 ) &&
V_4 -> V_433 . V_13 == V_12 &&
V_278 -> V_284 != F_226 ( V_404 ) )
V_12 -> V_577 . V_434 = true ;
if ( V_1202 && F_232 ( V_2 ) )
V_12 -> V_577 . V_578 = true ;
V_12 -> V_577 . V_583 |= V_367 || V_1198 ;
break;
case V_1204 :
break;
case V_1208 :
if ( V_1201 && ! V_1198 ) {
V_12 -> V_577 . V_578 = true ;
V_12 -> V_577 . V_1209 |=
1 << V_25 ;
}
}
return 0 ;
}
static bool F_774 ( const struct V_16 * V_1141 ,
const struct V_16 * V_1142 )
{
return V_1141 == V_1142 || ( V_1141 -> V_1210 & ( 1 << V_1142 -> type ) &&
V_1142 -> V_1210 & ( 1 << V_1141 -> type ) ) ;
}
static bool F_775 ( struct V_20 * V_11 ,
struct V_12 * V_13 ,
struct V_16 * V_17 )
{
struct V_16 * V_1211 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_25 ;
F_12 (state, connector, connector_state, i) {
if ( V_24 -> V_13 != & V_13 -> V_15 )
continue;
V_1211 =
F_13 ( V_24 -> V_27 ) ;
if ( ! F_774 ( V_17 , V_1211 ) )
return false ;
}
return true ;
}
static bool F_776 ( struct V_20 * V_11 ,
struct V_12 * V_13 )
{
struct V_16 * V_17 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_25 ;
F_12 (state, connector, connector_state, i) {
if ( V_24 -> V_13 != & V_13 -> V_15 )
continue;
V_17 = F_13 ( V_24 -> V_27 ) ;
if ( ! F_775 ( V_11 , V_13 , V_17 ) )
return false ;
}
return true ;
}
static int F_777 ( struct V_86 * V_13 ,
struct V_10 * V_19 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_18 * V_210 =
F_395 ( V_19 ) ;
struct V_20 * V_11 = V_19 -> V_11 ;
int V_302 ;
bool V_1198 = F_7 ( V_19 ) ;
if ( V_1198 && ! F_776 ( V_11 , V_12 ) ) {
F_150 ( L_195 ) ;
return - V_304 ;
}
if ( V_1198 && ! V_19 -> V_87 )
V_12 -> V_577 . V_582 = true ;
if ( V_1198 && V_19 -> V_242 &&
V_4 -> V_435 . V_1212 &&
! F_2 ( V_210 -> V_128 != V_946 ) ) {
V_302 = V_4 -> V_435 . V_1212 ( V_12 ,
V_210 ) ;
if ( V_302 )
return V_302 ;
}
V_302 = 0 ;
if ( F_51 ( V_2 ) -> V_103 >= 9 ) {
if ( V_1198 )
V_302 = F_351 ( V_210 ) ;
if ( ! V_302 )
V_302 = F_778 ( V_2 , V_12 ,
V_210 ) ;
}
return V_302 ;
}
static void F_779 ( struct V_1 * V_2 )
{
struct V_732 * V_22 ;
F_780 (dev, connector) {
if ( V_22 -> V_15 . V_17 ) {
V_22 -> V_15 . V_11 -> V_27 =
V_22 -> V_15 . V_17 ;
V_22 -> V_15 . V_11 -> V_13 =
V_22 -> V_15 . V_17 -> V_13 ;
} else {
V_22 -> V_15 . V_11 -> V_27 = NULL ;
V_22 -> V_15 . V_11 -> V_13 = NULL ;
}
}
}
static void
F_781 ( struct V_732 * V_22 ,
struct V_18 * V_210 )
{
int V_993 = V_210 -> V_742 ;
F_150 ( L_196 ,
V_22 -> V_15 . V_15 . V_240 ,
V_22 -> V_15 . V_134 ) ;
if ( V_22 -> V_15 . V_1213 . V_524 &&
V_22 -> V_15 . V_1213 . V_524 * 3 < V_993 ) {
F_150 ( L_197 ,
V_993 , V_22 -> V_15 . V_1213 . V_524 * 3 ) ;
V_210 -> V_742 = V_22 -> V_15 . V_1213 . V_524 * 3 ;
}
if ( V_22 -> V_15 . V_1213 . V_524 == 0 && V_993 > 24 ) {
F_150 ( L_198 ,
V_993 ) ;
V_210 -> V_742 = 24 ;
}
}
static int
F_782 ( struct V_12 * V_13 ,
struct V_18 * V_210 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_20 * V_11 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_993 , V_25 ;
if ( ( F_19 ( V_2 ) || F_22 ( V_2 ) ) )
V_993 = 10 * 3 ;
else if ( F_51 ( V_2 ) -> V_103 >= 5 )
V_993 = 12 * 3 ;
else
V_993 = 8 * 3 ;
V_210 -> V_742 = V_993 ;
V_11 = V_210 -> V_15 . V_11 ;
F_12 (state, connector, connector_state, i) {
if ( V_24 -> V_13 != & V_13 -> V_15 )
continue;
F_781 ( F_783 ( V_22 ) ,
V_210 ) ;
}
return V_993 ;
}
static void F_784 ( const struct V_447 * V_431 )
{
F_150 ( L_199
L_200 ,
V_431 -> V_92 ,
V_431 -> V_450 , V_431 -> V_902 ,
V_431 -> V_905 , V_431 -> V_901 ,
V_431 -> V_451 , V_431 -> V_907 ,
V_431 -> V_908 , V_431 -> V_897 , V_431 -> type , V_431 -> V_351 ) ;
}
static void F_785 ( struct V_12 * V_13 ,
struct V_18 * V_210 ,
const char * V_1214 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_294 * V_164 ;
struct V_383 * V_383 ;
struct V_417 * V_11 ;
struct V_276 * V_89 ;
F_150 ( L_201 , V_13 -> V_15 . V_15 . V_240 ,
V_1214 , V_210 , F_77 ( V_13 -> V_94 ) ) ;
F_150 ( L_202 , F_786 ( V_210 -> V_96 ) ) ;
F_150 ( L_203 ,
V_210 -> V_742 , V_210 -> V_918 ) ;
F_150 ( L_204 ,
V_210 -> V_261 ,
V_210 -> V_467 ,
V_210 -> V_589 . V_813 , V_210 -> V_589 . V_814 ,
V_210 -> V_589 . V_815 , V_210 -> V_589 . V_816 ,
V_210 -> V_589 . V_812 ) ;
F_150 ( L_205 ,
V_210 -> V_523 ,
V_210 -> V_831 . V_813 , V_210 -> V_831 . V_814 ,
V_210 -> V_831 . V_815 , V_210 -> V_831 . V_816 ,
V_210 -> V_831 . V_812 ) ;
F_150 ( L_206 ,
V_210 -> V_523 ,
V_210 -> V_832 . V_813 ,
V_210 -> V_832 . V_814 ,
V_210 -> V_832 . V_815 ,
V_210 -> V_832 . V_816 ,
V_210 -> V_832 . V_812 ) ;
F_150 ( L_207 ,
V_210 -> V_1215 ,
V_210 -> V_1216 ) ;
F_150 ( L_208 ) ;
F_787 ( & V_210 -> V_15 . V_431 ) ;
F_150 ( L_209 ) ;
F_787 ( & V_210 -> V_15 . V_91 ) ;
F_784 ( & V_210 -> V_15 . V_91 ) ;
F_150 ( L_210 , V_210 -> V_855 ) ;
F_150 ( L_211 ,
V_210 -> V_374 , V_210 -> V_373 ) ;
F_150 ( L_212 ,
V_13 -> V_386 ,
V_210 -> V_385 . V_541 ,
V_210 -> V_385 . V_422 ) ;
F_150 ( L_213 ,
V_210 -> V_598 . V_599 ,
V_210 -> V_598 . V_603 ,
V_210 -> V_598 . V_934 ) ;
F_150 ( L_214 ,
V_210 -> V_452 . V_556 ,
V_210 -> V_452 . V_293 ,
V_210 -> V_452 . V_120 ? L_215 : L_216 ) ;
F_150 ( L_217 , V_210 -> V_559 ) ;
F_150 ( L_218 , V_210 -> V_262 ) ;
if ( F_18 ( V_2 ) ) {
F_150 ( L_219
L_220
L_221 ,
V_210 -> V_1048 ,
V_210 -> V_211 . V_1217 ,
V_210 -> V_211 . V_1218 ,
V_210 -> V_211 . V_1219 ,
V_210 -> V_211 . V_1220 ,
V_210 -> V_211 . V_1221 ,
V_210 -> V_211 . V_1222 ,
V_210 -> V_211 . V_1223 ,
V_210 -> V_211 . V_1224 ,
V_210 -> V_211 . V_1225 ,
V_210 -> V_211 . V_1226 ,
V_210 -> V_211 . V_1227 ) ;
} else if ( F_425 ( V_2 ) ) {
F_150 ( L_222
L_223 ,
V_210 -> V_1048 ,
V_210 -> V_211 . V_1056 ,
V_210 -> V_211 . V_1228 ,
V_210 -> V_211 . V_1229 ) ;
} else if ( F_68 ( V_2 ) ) {
F_150 ( L_224 ,
V_210 -> V_1048 ,
V_210 -> V_211 . V_1230 ) ;
} else {
F_150 ( L_225
L_226 ,
V_210 -> V_211 . V_62 ,
V_210 -> V_211 . V_213 ,
V_210 -> V_211 . V_721 ,
V_210 -> V_211 . V_722 ) ;
}
F_150 ( L_227 ) ;
F_788 (plane, &dev->mode_config.plane_list, head) {
V_383 = F_216 ( V_164 ) ;
if ( V_383 -> V_94 != V_13 -> V_94 )
continue;
V_11 = F_218 ( V_164 -> V_11 ) ;
V_89 = V_11 -> V_15 . V_89 ;
if ( ! V_89 ) {
F_150 ( L_228
L_229 ,
V_164 -> type == V_1204 ? L_230 : L_231 ,
V_164 -> V_15 . V_240 , V_383 -> V_94 ,
( V_13 -> V_15 . V_88 == V_164 ) ? 0 : V_383 -> V_164 + 1 ,
F_215 ( V_164 ) , V_11 -> V_422 ) ;
continue;
}
F_150 ( L_232 ,
V_164 -> type == V_1204 ? L_230 : L_231 ,
V_164 -> V_15 . V_240 , V_383 -> V_94 ,
V_13 -> V_15 . V_88 == V_164 ? 0 : V_383 -> V_164 + 1 ,
F_215 ( V_164 ) ) ;
F_150 ( L_233 ,
V_89 -> V_15 . V_240 , V_89 -> V_350 , V_89 -> V_273 , V_89 -> V_265 ) ;
F_150 ( L_234 ,
V_11 -> V_422 ,
V_11 -> V_426 . V_427 >> 16 , V_11 -> V_426 . y1 >> 16 ,
F_247 ( & V_11 -> V_426 ) >> 16 ,
F_248 ( & V_11 -> V_426 ) >> 16 ,
V_11 -> V_428 . V_427 , V_11 -> V_428 . y1 ,
F_247 ( & V_11 -> V_428 ) , F_248 ( & V_11 -> V_428 ) ) ;
}
}
static bool F_789 ( struct V_20 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_16 * V_17 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
unsigned int V_1231 = 0 ;
int V_25 ;
F_12 (state, connector, connector_state, i) {
if ( ! V_24 -> V_27 )
continue;
V_17 = F_13 ( V_24 -> V_27 ) ;
F_2 ( ! V_24 -> V_13 ) ;
switch ( V_17 -> type ) {
unsigned int V_231 ;
case V_612 :
if ( F_2 ( ! F_68 ( V_2 ) ) )
break;
case V_613 :
case V_38 :
case V_453 :
V_231 = 1 << F_346 ( & V_17 -> V_15 ) -> V_106 ;
if ( V_1231 & V_231 )
return false ;
V_1231 |= V_231 ;
default:
break;
}
}
return true ;
}
static void
F_790 ( struct V_18 * V_19 )
{
struct V_10 V_1232 ;
struct V_384 V_385 ;
struct V_131 V_211 ;
enum V_533 V_128 ;
T_4 V_1048 ;
bool V_618 ;
V_1232 = V_19 -> V_15 ;
V_385 = V_19 -> V_385 ;
V_128 = V_19 -> V_128 ;
V_211 = V_19 -> V_211 ;
V_1048 = V_19 -> V_1048 ;
V_618 = V_19 -> V_452 . V_618 ;
memset ( V_19 , 0 , sizeof *V_19 ) ;
V_19 -> V_15 = V_1232 ;
V_19 -> V_385 = V_385 ;
V_19 -> V_128 = V_128 ;
V_19 -> V_211 = V_211 ;
V_19 -> V_1048 = V_1048 ;
V_19 -> V_452 . V_618 = V_618 ;
}
static int
F_791 ( struct V_86 * V_13 ,
struct V_18 * V_210 )
{
struct V_20 * V_11 = V_210 -> V_15 . V_11 ;
struct V_16 * V_17 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_1233 , V_302 = - V_304 ;
int V_25 ;
bool V_472 = true ;
F_790 ( V_210 ) ;
V_210 -> V_96 =
(enum V_93 ) F_41 ( V_13 ) -> V_94 ;
if ( ! ( V_210 -> V_15 . V_91 . V_351 &
( V_528 | V_1234 ) ) )
V_210 -> V_15 . V_91 . V_351 |= V_1234 ;
if ( ! ( V_210 -> V_15 . V_91 . V_351 &
( V_530 | V_1235 ) ) )
V_210 -> V_15 . V_91 . V_351 |= V_1235 ;
V_1233 = F_782 ( F_41 ( V_13 ) ,
V_210 ) ;
if ( V_1233 < 0 )
goto V_800;
F_680 ( & V_210 -> V_15 . V_431 ,
& V_210 -> V_374 ,
& V_210 -> V_373 ) ;
V_1236:
V_210 -> V_855 = 0 ;
V_210 -> V_593 = 1 ;
F_792 ( & V_210 -> V_15 . V_91 ,
V_1237 ) ;
F_12 (state, connector, connector_state, i) {
if ( V_24 -> V_13 != V_13 )
continue;
V_17 = F_13 ( V_24 -> V_27 ) ;
if ( ! ( V_17 -> V_1238 ( V_17 , V_210 ) ) ) {
F_150 ( L_235 ) ;
goto V_800;
}
}
if ( ! V_210 -> V_855 )
V_210 -> V_855 = V_210 -> V_15 . V_91 . V_92
* V_210 -> V_593 ;
V_302 = F_503 ( F_41 ( V_13 ) , V_210 ) ;
if ( V_302 < 0 ) {
F_150 ( L_236 ) ;
goto V_800;
}
if ( V_302 == V_744 ) {
if ( F_54 ( ! V_472 , L_237 ) ) {
V_302 = - V_304 ;
goto V_800;
}
F_150 ( L_238 ) ;
V_472 = false ;
goto V_1236;
}
V_210 -> V_918 = V_210 -> V_742 == 6 * 3 ;
F_150 ( L_239 ,
V_1233 , V_210 -> V_742 , V_210 -> V_918 ) ;
V_800:
return V_302 ;
}
static void
F_793 ( struct V_20 * V_11 )
{
struct V_86 * V_13 ;
struct V_10 * V_19 ;
int V_25 ;
F_423 (state, crtc, crtc_state, i) {
F_41 ( V_13 ) -> V_90 = F_395 ( V_13 -> V_11 ) ;
if ( V_13 -> V_11 -> V_87 )
V_13 -> V_1239 = V_13 -> V_11 -> V_91 ;
else
V_13 -> V_1239 . V_92 = 0 ;
}
}
static bool F_794 ( int V_1240 , int V_1241 )
{
int V_1242 ;
if ( V_1240 == V_1241 )
return true ;
if ( ! V_1240 || ! V_1241 )
return false ;
V_1242 = abs ( V_1240 - V_1241 ) ;
if ( ( ( ( ( V_1242 + V_1240 + V_1241 ) * 100 ) ) / ( V_1240 + V_1241 ) ) < 105 )
return true ;
return false ;
}
static bool
F_795 ( unsigned int V_54 , unsigned int V_59 ,
unsigned int V_55 , unsigned int V_1243 ,
bool V_1244 )
{
if ( V_54 == V_55 && V_59 == V_1243 )
return true ;
if ( V_1244 || ! V_54 || ! V_59 || ! V_55 || ! V_1243 )
return false ;
F_796 ( V_804 > V_84 ) ;
if ( V_54 > V_55 ) {
while ( V_54 > V_55 ) {
V_55 <<= 1 ;
V_1243 <<= 1 ;
}
} else if ( V_54 < V_55 ) {
while ( V_54 < V_55 ) {
V_54 <<= 1 ;
V_59 <<= 1 ;
}
}
return V_54 == V_55 && V_59 == V_1243 ;
}
static bool
F_797 ( const struct V_810 * V_811 ,
struct V_810 * V_828 ,
bool V_1245 )
{
if ( V_811 -> V_812 == V_828 -> V_812 &&
F_795 ( V_811 -> V_813 , V_811 -> V_814 ,
V_828 -> V_813 , V_828 -> V_814 , ! V_1245 ) &&
F_795 ( V_811 -> V_815 , V_811 -> V_816 ,
V_828 -> V_815 , V_828 -> V_816 , ! V_1245 ) ) {
if ( V_1245 )
* V_828 = * V_811 ;
return true ;
}
return false ;
}
static bool
F_798 ( struct V_1 * V_2 ,
struct V_18 * V_1246 ,
struct V_18 * V_210 ,
bool V_1245 )
{
bool V_302 = true ;
#define F_799 ( T_8 , ... ) \
do { \
if (!adjust) \
DRM_ERROR(fmt, ##__VA_ARGS__); \
else \
DRM_DEBUG_KMS(fmt, ##__VA_ARGS__); \
} while (0)
#define F_800 ( V_134 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_801 ( V_134 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_802 ( V_134 ) \
if (!intel_compare_link_m_n(&current_config->name, \
&pipe_config->name,\
adjust)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected tu %i gmch %i/%i link %i/%i, " \
"found tu %i, gmch %i/%i link %i/%i)\n", \
current_config->name.tu, \
current_config->name.gmch_m, \
current_config->name.gmch_n, \
current_config->name.link_m, \
current_config->name.link_n, \
pipe_config->name.tu, \
pipe_config->name.gmch_m, \
pipe_config->name.gmch_n, \
pipe_config->name.link_m, \
pipe_config->name.link_n); \
ret = false; \
}
#define F_803 ( V_134 , T_9 ) \
if (!intel_compare_link_m_n(&current_config->name, \
&pipe_config->name, adjust) && \
!intel_compare_link_m_n(&current_config->alt_name, \
&pipe_config->name, adjust)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected tu %i gmch %i/%i link %i/%i, " \
"or tu %i gmch %i/%i link %i/%i, " \
"found tu %i, gmch %i/%i link %i/%i)\n", \
current_config->name.tu, \
current_config->name.gmch_m, \
current_config->name.gmch_n, \
current_config->name.link_m, \
current_config->name.link_n, \
current_config->alt_name.tu, \
current_config->alt_name.gmch_m, \
current_config->alt_name.gmch_n, \
current_config->alt_name.link_m, \
current_config->alt_name.link_n, \
pipe_config->name.tu, \
pipe_config->name.gmch_m, \
pipe_config->name.gmch_n, \
pipe_config->name.link_m, \
pipe_config->name.link_n); \
ret = false; \
}
#define F_804 ( V_134 , T_9 ) \
if ((current_config->name != pipe_config->name) && \
(current_config->alt_name != pipe_config->name)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i or %i, found %i)\n", \
current_config->name, \
current_config->alt_name, \
pipe_config->name); \
ret = false; \
}
#define F_805 ( V_134 , V_617 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
ret = false; \
}
#define F_806 ( V_134 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_807 ( T_10 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_801 ( V_96 ) ;
F_801 ( V_261 ) ;
F_801 ( V_467 ) ;
F_802 ( V_589 ) ;
F_801 ( V_523 ) ;
if ( F_51 ( V_2 ) -> V_103 < 8 ) {
F_802 ( V_831 ) ;
F_801 ( V_829 ) ;
if ( V_1246 -> V_829 )
F_802 ( V_832 ) ;
} else
F_803 ( V_831 , V_832 ) ;
F_801 ( V_15 . V_91 . V_450 ) ;
F_801 ( V_15 . V_91 . V_901 ) ;
F_801 ( V_15 . V_91 . V_903 ) ;
F_801 ( V_15 . V_91 . V_904 ) ;
F_801 ( V_15 . V_91 . V_902 ) ;
F_801 ( V_15 . V_91 . V_905 ) ;
F_801 ( V_15 . V_91 . V_451 ) ;
F_801 ( V_15 . V_91 . V_897 ) ;
F_801 ( V_15 . V_91 . V_906 ) ;
F_801 ( V_15 . V_91 . V_898 ) ;
F_801 ( V_15 . V_91 . V_907 ) ;
F_801 ( V_15 . V_91 . V_908 ) ;
F_801 ( V_593 ) ;
F_801 ( V_1247 ) ;
if ( ( F_51 ( V_2 ) -> V_103 < 8 && ! F_231 ( V_2 ) ) ||
F_22 ( V_2 ) )
F_801 ( V_927 ) ;
F_801 ( V_1216 ) ;
F_801 ( V_1215 ) ;
F_805 ( V_15 . V_91 . V_351 ,
V_900 ) ;
if ( ! F_807 ( V_1248 ) ) {
F_805 ( V_15 . V_91 . V_351 ,
V_528 ) ;
F_805 ( V_15 . V_91 . V_351 ,
V_1234 ) ;
F_805 ( V_15 . V_91 . V_351 ,
V_530 ) ;
F_805 ( V_15 . V_91 . V_351 ,
V_1235 ) ;
}
F_801 ( V_374 ) ;
F_801 ( V_373 ) ;
F_801 ( V_598 . V_599 ) ;
if ( F_51 ( V_2 ) -> V_103 < 4 )
F_801 ( V_598 . V_603 ) ;
F_801 ( V_598 . V_934 ) ;
F_801 ( V_452 . V_120 ) ;
if ( V_1246 -> V_452 . V_120 ) {
F_801 ( V_452 . V_556 ) ;
F_801 ( V_452 . V_293 ) ;
}
F_801 ( V_385 . V_422 ) ;
if ( F_231 ( V_2 ) )
F_801 ( V_559 ) ;
F_801 ( V_262 ) ;
F_800 ( V_1048 ) ;
F_801 ( V_128 ) ;
F_800 ( V_211 . V_62 ) ;
F_800 ( V_211 . V_213 ) ;
F_800 ( V_211 . V_721 ) ;
F_800 ( V_211 . V_722 ) ;
F_800 ( V_211 . V_1230 ) ;
F_800 ( V_211 . V_1056 ) ;
F_800 ( V_211 . V_1228 ) ;
F_800 ( V_211 . V_1229 ) ;
if ( F_19 ( V_2 ) || F_51 ( V_2 ) -> V_103 >= 5 )
F_801 ( V_742 ) ;
F_806 ( V_15 . V_91 . V_92 ) ;
F_806 ( V_855 ) ;
#undef F_800
#undef F_801
#undef F_804
#undef F_805
#undef F_806
#undef F_807
#undef F_799
return V_302 ;
}
static void F_808 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_1249 V_1250 , * V_1251 ;
struct V_12 * V_12 ;
int V_164 ;
if ( F_51 ( V_2 ) -> V_103 < 9 )
return;
F_809 ( V_4 , & V_1250 ) ;
V_1251 = & V_4 -> V_573 . V_1252 . V_1253 ;
F_137 (dev, intel_crtc) {
struct V_1254 * V_1255 , * V_1256 ;
const enum V_94 V_94 = V_12 -> V_94 ;
if ( ! V_12 -> V_87 )
continue;
F_810 (dev_priv, pipe, plane) {
V_1255 = & V_1250 . V_164 [ V_94 ] [ V_164 ] ;
V_1256 = & V_1251 -> V_164 [ V_94 ] [ V_164 ] ;
if ( F_811 ( V_1255 , V_1256 ) )
continue;
F_129 ( L_240
L_241 ,
F_77 ( V_94 ) , V_164 + 1 ,
V_1256 -> V_1095 , V_1256 -> V_1096 ,
V_1255 -> V_1095 , V_1255 -> V_1096 ) ;
}
V_1255 = & V_1250 . V_1072 [ V_94 ] ;
V_1256 = & V_1251 -> V_1072 [ V_94 ] ;
if ( F_811 ( V_1255 , V_1256 ) )
continue;
F_129 ( L_242
L_241 ,
F_77 ( V_94 ) ,
V_1256 -> V_1095 , V_1256 -> V_1096 ,
V_1255 -> V_1095 , V_1255 -> V_1096 ) ;
}
}
static void
F_812 ( struct V_1 * V_2 ,
struct V_20 * V_715 )
{
struct V_23 * V_1257 ;
struct V_21 * V_22 ;
int V_25 ;
F_12 (old_state, connector, old_conn_state, i) {
struct V_731 * V_17 = V_22 -> V_17 ;
struct V_23 * V_11 = V_22 -> V_11 ;
F_487 ( F_783 ( V_22 ) ) ;
F_60 ( V_11 -> V_27 != V_17 ,
L_243 ) ;
}
}
static void
F_813 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_732 * V_22 ;
F_591 (dev, encoder) {
bool V_120 = false ;
enum V_94 V_94 ;
F_150 ( L_244 ,
V_17 -> V_15 . V_15 . V_240 ,
V_17 -> V_15 . V_134 ) ;
F_780 (dev, connector) {
if ( V_22 -> V_15 . V_11 -> V_27 != & V_17 -> V_15 )
continue;
V_120 = true ;
F_60 ( V_22 -> V_15 . V_11 -> V_13 !=
V_17 -> V_15 . V_13 ,
L_245 ) ;
}
F_60 ( ! ! V_17 -> V_15 . V_13 != V_120 ,
L_246
L_247 ,
! ! V_17 -> V_15 . V_13 , V_120 ) ;
if ( ! V_17 -> V_15 . V_13 ) {
bool V_87 ;
V_87 = V_17 -> V_133 ( V_17 , & V_94 ) ;
F_60 ( V_87 ,
L_248 ,
F_77 ( V_94 ) ) ;
}
}
}
static void
F_814 ( struct V_1 * V_2 , struct V_20 * V_715 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_16 * V_17 ;
struct V_10 * V_1258 ;
struct V_86 * V_13 ;
int V_25 ;
F_423 (old_state, crtc, old_crtc_state, i) {
struct V_12 * V_12 = F_41 ( V_13 ) ;
struct V_18 * V_210 , * V_1259 ;
bool V_87 ;
if ( ! F_7 ( V_13 -> V_11 ) )
continue;
F_815 ( V_13 , V_1258 ) ;
V_210 = F_395 ( V_1258 ) ;
memset ( V_210 , 0 , sizeof( * V_210 ) ) ;
V_210 -> V_15 . V_13 = V_13 ;
V_210 -> V_15 . V_11 = V_715 ;
F_150 ( L_249 ,
V_13 -> V_15 . V_240 ) ;
V_87 = V_4 -> V_435 . V_1260 ( V_12 ,
V_210 ) ;
if ( ( V_12 -> V_94 == V_142 && V_4 -> V_160 & V_161 ) ||
( V_12 -> V_94 == V_151 && V_4 -> V_160 & V_162 ) )
V_87 = V_13 -> V_11 -> V_87 ;
F_60 ( V_13 -> V_11 -> V_87 != V_87 ,
L_250
L_247 , V_13 -> V_11 -> V_87 , V_87 ) ;
F_60 ( V_12 -> V_87 != V_13 -> V_11 -> V_87 ,
L_251
L_247 , V_13 -> V_11 -> V_87 , V_12 -> V_87 ) ;
F_10 (dev, crtc, encoder) {
enum V_94 V_94 ;
V_87 = V_17 -> V_133 ( V_17 , & V_94 ) ;
F_60 ( V_87 != V_13 -> V_11 -> V_87 ,
L_252 ,
V_17 -> V_15 . V_15 . V_240 , V_87 , V_13 -> V_11 -> V_87 ) ;
F_60 ( V_87 && V_12 -> V_94 != V_94 ,
L_253 ,
F_77 ( V_94 ) ) ;
if ( V_87 )
V_17 -> V_1261 ( V_17 , V_210 ) ;
}
if ( ! V_13 -> V_11 -> V_87 )
continue;
V_1259 = F_395 ( V_13 -> V_11 ) ;
if ( ! F_798 ( V_2 , V_1259 ,
V_210 , false ) ) {
F_60 ( 1 , L_254 ) ;
F_785 ( V_12 , V_210 ,
L_255 ) ;
F_785 ( V_12 , V_1259 ,
L_256 ) ;
}
}
}
static void
F_816 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_13 ;
struct V_131 V_211 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_4 -> V_535 ; V_25 ++ ) {
struct V_127 * V_130 = & V_4 -> V_129 [ V_25 ] ;
int V_1262 = 0 , V_1263 = 0 ;
bool V_87 ;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
F_150 ( L_257 , V_130 -> V_134 ) ;
V_87 = V_130 -> V_133 ( V_4 , V_130 , & V_211 ) ;
F_60 ( V_130 -> V_87 > F_817 ( V_130 -> V_90 . V_237 ) ,
L_258 ,
V_130 -> V_87 , F_817 ( V_130 -> V_90 . V_237 ) ) ;
F_60 ( V_130 -> V_87 && ! V_130 -> V_238 ,
L_259 ) ;
F_60 ( V_130 -> V_238 && ! V_130 -> V_87 ,
L_260 ) ;
F_60 ( V_130 -> V_238 != V_87 ,
L_261 ,
V_130 -> V_238 , V_87 ) ;
F_137 (dev, crtc) {
if ( V_13 -> V_15 . V_11 -> V_242 && F_65 ( V_13 ) == V_130 )
V_1262 ++ ;
if ( V_13 -> V_87 && F_65 ( V_13 ) == V_130 )
V_1263 ++ ;
}
F_60 ( V_130 -> V_87 != V_1263 ,
L_262 ,
V_130 -> V_87 , V_1263 ) ;
F_60 ( F_817 ( V_130 -> V_90 . V_237 ) != V_1262 ,
L_263 ,
F_817 ( V_130 -> V_90 . V_237 ) , V_1262 ) ;
F_60 ( V_130 -> V_238 && memcmp ( & V_130 -> V_90 . V_132 , & V_211 ,
sizeof( V_211 ) ) ,
L_264 ) ;
}
}
static void
F_818 ( struct V_1 * V_2 ,
struct V_20 * V_715 )
{
F_808 ( V_2 ) ;
F_812 ( V_2 , V_715 ) ;
F_813 ( V_2 ) ;
F_814 ( V_2 , V_715 ) ;
F_816 ( V_2 ) ;
}
void F_819 ( const struct V_18 * V_210 ,
int V_1264 )
{
F_54 ( ! F_794 ( V_210 -> V_15 . V_91 . V_92 , V_1264 ) ,
L_265 ,
V_210 -> V_15 . V_91 . V_92 , V_1264 ) ;
}
static void F_820 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
if ( F_23 ( V_2 ) ) {
const struct V_447 * V_431 = & V_13 -> V_90 -> V_15 . V_91 ;
int V_911 ;
V_911 = V_431 -> V_897 ;
if ( V_431 -> V_351 & V_900 )
V_911 /= 2 ;
V_13 -> V_1265 = V_911 - 1 ;
} else if ( F_68 ( V_2 ) &&
F_9 ( V_13 , V_38 ) ) {
V_13 -> V_1265 = 2 ;
} else
V_13 -> V_1265 = 1 ;
}
static void F_821 ( struct V_20 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = F_266 ( V_2 ) ;
struct V_532 * V_128 = NULL ;
struct V_12 * V_12 ;
struct V_18 * V_18 ;
struct V_86 * V_13 ;
struct V_10 * V_19 ;
int V_25 ;
if ( ! V_4 -> V_435 . V_1212 )
return;
F_423 (state, crtc, crtc_state, i) {
int V_62 ;
V_12 = F_41 ( V_13 ) ;
V_18 = F_395 ( V_19 ) ;
V_62 = V_18 -> V_128 ;
if ( ! F_7 ( V_19 ) || V_62 == V_946 )
continue;
V_18 -> V_128 = V_946 ;
if ( ! V_128 )
V_128 = F_344 ( V_11 ) ;
V_128 [ V_62 ] . V_237 &= ~ ( 1 << V_12 -> V_94 ) ;
}
}
static int F_822 ( struct V_20 * V_11 )
{
struct V_10 * V_19 ;
struct V_12 * V_12 ;
struct V_86 * V_13 ;
struct V_18 * V_1266 = NULL ;
struct V_18 * V_736 = NULL ;
enum V_94 V_1267 = V_595 , V_1268 = V_595 ;
int V_25 ;
F_423 (state, crtc, crtc_state, i) {
V_12 = F_41 ( V_13 ) ;
if ( ! V_19 -> V_87 || ! F_7 ( V_19 ) )
continue;
if ( V_1266 ) {
V_736 = F_395 ( V_19 ) ;
break;
} else {
V_1266 = F_395 ( V_19 ) ;
V_1267 = V_12 -> V_94 ;
}
}
if ( ! V_1266 )
return 0 ;
F_137 (state->dev, intel_crtc) {
struct V_18 * V_210 ;
V_210 = F_458 ( V_11 , V_12 ) ;
if ( F_459 ( V_210 ) )
return F_460 ( V_210 ) ;
V_210 -> V_591 = V_595 ;
if ( ! V_210 -> V_15 . V_87 ||
F_7 ( & V_210 -> V_15 ) )
continue;
if ( V_1268 != V_595 )
return 0 ;
V_1268 = V_12 -> V_94 ;
}
if ( V_1268 != V_595 )
V_1266 -> V_591 = V_1268 ;
else if ( V_736 )
V_736 -> V_591 = V_1267 ;
return 0 ;
}
static int F_823 ( struct V_20 * V_11 )
{
struct V_86 * V_13 ;
struct V_10 * V_19 ;
int V_302 = 0 ;
F_213 (state->dev, crtc) {
V_19 = F_481 ( V_11 , V_13 ) ;
if ( F_459 ( V_19 ) )
return F_460 ( V_19 ) ;
if ( ! V_19 -> V_87 || F_7 ( V_19 ) )
continue;
V_19 -> V_1198 = true ;
V_302 = F_824 ( V_11 , V_13 ) ;
if ( V_302 )
break;
V_302 = F_825 ( V_11 , V_13 ) ;
if ( V_302 )
break;
}
return V_302 ;
}
static int F_826 ( struct V_20 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_302 ;
if ( ! F_789 ( V_11 ) ) {
F_150 ( L_266 ) ;
return - V_304 ;
}
if ( V_4 -> V_435 . V_1269 ) {
unsigned int V_627 ;
V_302 = V_4 -> V_435 . V_1269 ( V_11 ) ;
V_627 = F_348 ( V_11 ) -> V_627 ;
if ( ! V_302 && V_627 != V_4 -> V_628 )
V_302 = F_823 ( V_11 ) ;
if ( V_302 < 0 )
return V_302 ;
} else
F_348 ( V_11 ) -> V_627 = V_4 -> V_628 ;
F_821 ( V_11 ) ;
if ( F_231 ( V_2 ) )
return F_822 ( V_11 ) ;
return 0 ;
}
static int F_827 ( struct V_1 * V_2 ,
struct V_20 * V_11 )
{
struct V_86 * V_13 ;
struct V_10 * V_19 ;
int V_302 , V_25 ;
bool V_1270 = false ;
V_302 = F_828 ( V_2 , V_11 ) ;
if ( V_302 )
return V_302 ;
F_423 (state, crtc, crtc_state, i) {
struct V_18 * V_210 =
F_395 ( V_19 ) ;
if ( V_19 -> V_431 . V_1271 != V_13 -> V_11 -> V_431 . V_1271 )
V_19 -> V_1198 = true ;
if ( ! V_19 -> V_242 ) {
if ( F_7 ( V_19 ) )
V_1270 = true ;
continue;
}
if ( ! F_7 ( V_19 ) )
continue;
V_302 = F_824 ( V_11 , V_13 ) ;
if ( V_302 )
return V_302 ;
V_302 = F_791 ( V_13 , V_210 ) ;
if ( V_302 )
return V_302 ;
if ( V_448 . V_449 &&
F_798 ( V_11 -> V_2 ,
F_395 ( V_13 -> V_11 ) ,
V_210 , true ) ) {
V_19 -> V_1198 = false ;
}
if ( F_7 ( V_19 ) ) {
V_1270 = true ;
V_302 = F_825 ( V_11 , V_13 ) ;
if ( V_302 )
return V_302 ;
}
F_785 ( F_41 ( V_13 ) , V_210 ,
F_7 ( V_19 ) ?
L_267 : L_268 ) ;
}
if ( V_1270 ) {
V_302 = F_826 ( V_11 ) ;
if ( V_302 )
return V_302 ;
} else
F_348 ( V_11 ) -> V_627 =
F_266 ( V_11 -> V_2 ) -> V_628 ;
return F_829 ( V_11 -> V_2 , V_11 ) ;
}
static int F_830 ( struct V_1 * V_2 ,
struct V_20 * V_11 ,
bool V_1272 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_86 * V_13 ;
struct V_10 * V_19 ;
int V_302 = 0 ;
int V_25 ;
bool V_1270 = false ;
if ( V_1272 ) {
F_150 ( L_269 ) ;
return - V_304 ;
}
V_302 = F_831 ( V_2 , V_11 ) ;
if ( V_302 )
return V_302 ;
F_832 ( V_2 , V_11 ) ;
F_423 (state, crtc, crtc_state, i) {
struct V_12 * V_12 = F_41 ( V_13 ) ;
if ( ! F_7 ( V_13 -> V_11 ) )
continue;
V_1270 = true ;
F_379 ( V_12 ) ;
if ( V_19 -> V_87 ) {
F_382 ( V_13 , V_19 -> V_364 ) ;
V_4 -> V_435 . V_723 ( V_13 ) ;
V_12 -> V_87 = false ;
F_153 ( V_12 ) ;
}
}
F_793 ( V_11 ) ;
if ( V_1270 ) {
F_347 ( V_11 ) ;
F_833 ( V_11 -> V_2 , V_11 ) ;
F_422 ( V_11 ) ;
}
F_423 (state, crtc, crtc_state, i) {
struct V_12 * V_12 = F_41 ( V_13 ) ;
bool V_1273 = F_7 ( V_13 -> V_11 ) ;
if ( V_1273 && V_13 -> V_11 -> V_87 ) {
F_820 ( F_41 ( V_13 ) ) ;
V_4 -> V_435 . V_1274 ( V_13 ) ;
}
if ( ! V_1273 )
F_379 ( V_12 ) ;
F_834 ( V_19 ) ;
F_373 ( V_12 ) ;
}
F_835 ( V_2 , V_11 ) ;
F_836 ( V_2 , V_11 ) ;
if ( V_1270 )
F_818 ( V_2 , V_11 ) ;
F_484 ( V_11 ) ;
return 0 ;
}
void F_837 ( struct V_86 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_20 * V_11 ;
struct V_10 * V_19 ;
int V_302 ;
V_11 = F_480 ( V_2 ) ;
if ( ! V_11 ) {
F_150 ( L_270 ,
V_13 -> V_15 . V_240 ) ;
return;
}
V_11 -> V_728 = F_769 ( V_13 ) ;
V_472:
V_19 = F_481 ( V_11 , V_13 ) ;
V_302 = F_482 ( V_19 ) ;
if ( ! V_302 ) {
if ( ! V_19 -> V_87 )
goto V_1275;
V_19 -> V_1198 = true ;
V_302 = F_483 ( V_11 ) ;
}
if ( V_302 == - V_308 ) {
F_770 ( V_11 ) ;
F_687 ( V_11 -> V_728 ) ;
goto V_472;
}
if ( V_302 )
V_1275:
F_484 ( V_11 ) ;
}
static bool F_838 ( struct V_3 * V_4 ,
struct V_127 * V_130 ,
struct V_131 * V_132 )
{
T_4 V_121 ;
if ( ! F_83 ( V_4 , V_241 ) )
return false ;
V_121 = F_4 ( F_839 ( V_130 -> V_240 ) ) ;
V_132 -> V_62 = V_121 ;
V_132 -> V_721 = F_4 ( F_840 ( V_130 -> V_240 ) ) ;
V_132 -> V_722 = F_4 ( F_841 ( V_130 -> V_240 ) ) ;
return V_121 & V_123 ;
}
static void F_842 ( struct V_3 * V_4 ,
struct V_127 * V_130 )
{
F_126 ( F_840 ( V_130 -> V_240 ) , V_130 -> V_90 . V_132 . V_721 ) ;
F_126 ( F_841 ( V_130 -> V_240 ) , V_130 -> V_90 . V_132 . V_722 ) ;
}
static void F_843 ( struct V_3 * V_4 ,
struct V_127 * V_130 )
{
F_101 ( V_4 ) ;
F_126 ( F_839 ( V_130 -> V_240 ) , V_130 -> V_90 . V_132 . V_62 ) ;
F_127 ( F_839 ( V_130 -> V_240 ) ) ;
F_128 ( 150 ) ;
F_126 ( F_839 ( V_130 -> V_240 ) , V_130 -> V_90 . V_132 . V_62 ) ;
F_127 ( F_839 ( V_130 -> V_240 ) ) ;
F_128 ( 200 ) ;
}
static void F_844 ( struct V_3 * V_4 ,
struct V_127 * V_130 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 ;
F_137 (dev, crtc) {
if ( F_65 ( V_13 ) == V_130 )
F_103 ( V_4 , V_13 -> V_94 ) ;
}
F_126 ( F_839 ( V_130 -> V_240 ) , 0 ) ;
F_127 ( F_839 ( V_130 -> V_240 ) ) ;
F_128 ( 200 ) ;
}
static void F_845 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_25 ;
V_4 -> V_535 = 2 ;
for ( V_25 = 0 ; V_25 < V_4 -> V_535 ; V_25 ++ ) {
V_4 -> V_129 [ V_25 ] . V_240 = V_25 ;
V_4 -> V_129 [ V_25 ] . V_134 = V_1276 [ V_25 ] ;
V_4 -> V_129 [ V_25 ] . V_239 = F_842 ;
V_4 -> V_129 [ V_25 ] . V_242 = F_843 ;
V_4 -> V_129 [ V_25 ] . V_243 = F_844 ;
V_4 -> V_129 [ V_25 ] . V_133 =
F_838 ;
}
}
static void F_846 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_428 ( V_2 ) ;
if ( F_68 ( V_2 ) )
F_847 ( V_2 ) ;
else if ( F_56 ( V_2 ) || F_102 ( V_2 ) )
F_845 ( V_2 ) ;
else
V_4 -> V_535 = 0 ;
F_124 ( V_4 -> V_535 > V_1277 ) ;
}
int
F_848 ( struct V_294 * V_164 ,
struct V_276 * V_89 ,
const struct V_277 * V_1278 )
{
struct V_1 * V_2 = V_164 -> V_2 ;
struct V_383 * V_383 = F_216 ( V_164 ) ;
struct V_299 * V_300 = F_188 ( V_89 ) ;
struct V_299 * V_1279 = F_188 ( V_164 -> V_89 ) ;
int V_302 = 0 ;
if ( ! V_300 )
return 0 ;
F_62 ( & V_2 -> V_303 ) ;
if ( V_164 -> type == V_1204 &&
F_51 ( V_2 ) -> V_1280 ) {
int V_1281 = F_139 ( V_2 ) ? 16 * 1024 : 256 ;
V_302 = F_849 ( V_300 , V_1281 ) ;
if ( V_302 )
F_150 ( L_271 ) ;
} else {
V_302 = F_187 ( V_164 , V_89 , V_1278 , NULL , NULL ) ;
}
if ( V_302 == 0 )
F_380 ( V_1279 , V_300 , V_383 -> V_366 ) ;
F_64 ( & V_2 -> V_303 ) ;
return V_302 ;
}
void
F_850 ( struct V_294 * V_164 ,
struct V_276 * V_89 ,
const struct V_277 * V_715 )
{
struct V_1 * V_2 = V_164 -> V_2 ;
struct V_299 * V_300 = F_188 ( V_89 ) ;
if ( F_2 ( ! V_300 ) )
return;
if ( V_164 -> type != V_1204 ||
! F_51 ( V_2 ) -> V_1280 ) {
F_62 ( & V_2 -> V_303 ) ;
F_196 ( V_89 , V_715 ) ;
F_64 ( & V_2 -> V_303 ) ;
}
}
int
F_851 ( struct V_12 * V_12 , struct V_18 * V_19 )
{
int V_1282 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_92 , V_627 ;
if ( ! V_12 || ! V_19 )
return V_1283 ;
V_2 = V_12 -> V_15 . V_2 ;
V_4 = V_2 -> V_5 ;
V_92 = V_19 -> V_15 . V_91 . V_92 ;
V_627 = F_348 ( V_19 -> V_15 . V_11 ) -> V_627 ;
if ( ! V_92 || ! V_627 )
return V_1283 ;
V_1282 = V_65 ( ( 1 << 16 ) * 3 - 1 , ( 1 << 8 ) * ( ( V_627 << 8 ) / V_92 ) ) ;
return V_1282 ;
}
static int
F_852 ( struct V_294 * V_164 ,
struct V_18 * V_19 ,
struct V_417 * V_11 )
{
struct V_86 * V_13 = V_11 -> V_15 . V_13 ;
struct V_276 * V_89 = V_11 -> V_15 . V_89 ;
int V_1284 = V_1283 ;
int V_1282 = V_1283 ;
bool V_1285 = false ;
if ( F_51 ( V_164 -> V_2 ) -> V_103 >= 9 &&
V_11 -> V_553 . V_351 == V_554 ) {
V_1284 = 1 ;
V_1282 = F_851 ( F_41 ( V_13 ) , V_19 ) ;
V_1285 = true ;
}
return F_853 ( V_164 , V_13 , V_89 , & V_11 -> V_426 ,
& V_11 -> V_428 , & V_11 -> V_1286 ,
V_1284 , V_1282 ,
V_1285 , true ,
& V_11 -> V_367 ) ;
}
static void
F_854 ( struct V_294 * V_164 ,
struct V_417 * V_11 )
{
struct V_86 * V_13 = V_11 -> V_15 . V_13 ;
struct V_276 * V_89 = V_11 -> V_15 . V_89 ;
struct V_1 * V_2 = V_164 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 ;
struct V_1287 * V_426 = & V_11 -> V_426 ;
V_13 = V_13 ? V_13 : V_164 -> V_13 ;
V_12 = F_41 ( V_13 ) ;
V_164 -> V_89 = V_89 ;
V_13 -> V_311 = V_426 -> V_427 >> 16 ;
V_13 -> V_312 = V_426 -> y1 >> 16 ;
if ( ! V_13 -> V_11 -> V_87 )
return;
if ( V_11 -> V_367 )
F_280 ( V_12 ) ;
V_4 -> V_435 . V_436 ( V_13 , V_89 , V_13 -> V_311 , V_13 -> V_312 ) ;
}
static void
F_855 ( struct V_294 * V_164 ,
struct V_86 * V_13 )
{
struct V_1 * V_2 = V_164 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_435 . V_436 ( V_13 , NULL , 0 , 0 ) ;
}
static void F_856 ( struct V_86 * V_13 ,
struct V_10 * V_1258 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_12 * V_12 = F_41 ( V_13 ) ;
if ( V_12 -> V_577 . V_1206 )
F_375 ( V_13 ) ;
if ( V_13 -> V_11 -> V_87 )
F_737 ( V_12 , & V_12 -> V_1175 ) ;
if ( ! F_7 ( V_13 -> V_11 ) && F_51 ( V_2 ) -> V_103 >= 9 )
F_241 ( V_12 ) ;
}
static void F_857 ( struct V_86 * V_13 ,
struct V_10 * V_1258 )
{
struct V_12 * V_12 = F_41 ( V_13 ) ;
if ( V_13 -> V_11 -> V_87 )
F_738 ( V_12 , V_12 -> V_1175 ) ;
}
void F_858 ( struct V_294 * V_164 )
{
struct V_383 * V_383 = F_216 ( V_164 ) ;
F_859 ( V_164 ) ;
F_212 ( V_383 ) ;
}
static struct V_294 * F_860 ( struct V_1 * V_2 ,
int V_94 )
{
struct V_383 * V_88 ;
struct V_417 * V_11 ;
const T_4 * V_1288 ;
unsigned int V_1289 ;
V_88 = F_489 ( sizeof( * V_88 ) , V_734 ) ;
if ( V_88 == NULL )
return NULL ;
V_11 = F_861 ( & V_88 -> V_15 ) ;
if ( ! V_11 ) {
F_212 ( V_88 ) ;
return NULL ;
}
V_88 -> V_15 . V_11 = & V_11 -> V_15 ;
V_88 -> V_1290 = false ;
V_88 -> V_1291 = 1 ;
if ( F_51 ( V_2 ) -> V_103 >= 9 ) {
V_88 -> V_1290 = true ;
V_11 -> V_422 = - 1 ;
}
V_88 -> V_94 = V_94 ;
V_88 -> V_164 = V_94 ;
V_88 -> V_366 = F_862 ( V_94 ) ;
V_88 -> V_1292 = F_852 ;
V_88 -> V_1293 = F_854 ;
V_88 -> F_383 = F_855 ;
if ( F_863 ( V_2 ) && F_51 ( V_2 ) -> V_103 < 4 )
V_88 -> V_164 = ! V_94 ;
if ( F_51 ( V_2 ) -> V_103 >= 9 ) {
V_1288 = V_1294 ;
V_1289 = F_297 ( V_1294 ) ;
} else if ( F_51 ( V_2 ) -> V_103 >= 4 ) {
V_1288 = V_1295 ;
V_1289 = F_297 ( V_1295 ) ;
} else {
V_1288 = V_1296 ;
V_1289 = F_297 ( V_1296 ) ;
}
F_864 ( V_2 , & V_88 -> V_15 , 0 ,
& V_1297 ,
V_1288 , V_1289 ,
V_1207 ) ;
if ( F_51 ( V_2 ) -> V_103 >= 4 )
F_865 ( V_2 , V_88 ) ;
F_866 ( & V_88 -> V_15 , & V_1298 ) ;
return & V_88 -> V_15 ;
}
void F_865 ( struct V_1 * V_2 , struct V_383 * V_164 )
{
if ( ! V_2 -> V_725 . V_1299 ) {
unsigned long V_351 = F_226 ( V_404 ) |
F_226 ( V_379 ) ;
if ( F_51 ( V_2 ) -> V_103 >= 9 )
V_351 |= F_226 ( V_405 ) | F_226 ( V_408 ) ;
V_2 -> V_725 . V_1299 =
F_867 ( V_2 , V_351 ) ;
}
if ( V_2 -> V_725 . V_1299 )
F_868 ( & V_164 -> V_15 . V_15 ,
V_2 -> V_725 . V_1299 ,
V_164 -> V_15 . V_11 -> V_284 ) ;
}
static int
F_869 ( struct V_294 * V_164 ,
struct V_18 * V_19 ,
struct V_417 * V_11 )
{
struct V_86 * V_13 = V_19 -> V_15 . V_13 ;
struct V_276 * V_89 = V_11 -> V_15 . V_89 ;
struct V_299 * V_300 = F_188 ( V_89 ) ;
unsigned V_349 ;
int V_302 ;
V_302 = F_853 ( V_164 , V_13 , V_89 , & V_11 -> V_426 ,
& V_11 -> V_428 , & V_11 -> V_1286 ,
V_1283 ,
V_1283 ,
true , true , & V_11 -> V_367 ) ;
if ( V_302 )
return V_302 ;
if ( ! V_300 )
return 0 ;
if ( ! F_664 ( V_164 -> V_2 , V_11 -> V_15 . V_361 , V_11 -> V_15 . V_362 ) ) {
F_870 ( L_272 ,
V_11 -> V_15 . V_361 , V_11 -> V_15 . V_362 ) ;
return - V_304 ;
}
V_349 = F_658 ( V_11 -> V_15 . V_361 ) * 4 ;
if ( V_300 -> V_15 . V_293 < V_349 * V_11 -> V_15 . V_362 ) {
F_150 ( L_273 ) ;
return - V_730 ;
}
if ( V_89 -> V_289 [ 0 ] != V_269 ) {
F_150 ( L_274 ) ;
return - V_304 ;
}
return 0 ;
}
static void
F_871 ( struct V_294 * V_164 ,
struct V_86 * V_13 )
{
F_662 ( V_13 , false ) ;
}
static void
F_872 ( struct V_294 * V_164 ,
struct V_417 * V_11 )
{
struct V_86 * V_13 = V_11 -> V_15 . V_13 ;
struct V_1 * V_2 = V_164 -> V_2 ;
struct V_12 * V_12 ;
struct V_299 * V_300 = F_188 ( V_11 -> V_15 . V_89 ) ;
T_4 V_1179 ;
V_13 = V_13 ? V_13 : V_164 -> V_13 ;
V_12 = F_41 ( V_13 ) ;
V_164 -> V_89 = V_11 -> V_15 . V_89 ;
V_13 -> V_1086 = V_11 -> V_15 . V_360 ;
V_13 -> V_1087 = V_11 -> V_15 . V_1099 ;
if ( V_12 -> V_1300 == V_300 )
goto V_1301;
if ( ! V_300 )
V_1179 = 0 ;
else if ( ! F_51 ( V_2 ) -> V_1280 )
V_1179 = F_214 ( V_300 ) ;
else
V_1179 = V_300 -> V_1302 -> V_1303 ;
V_12 -> V_1088 = V_1179 ;
V_12 -> V_1300 = V_300 ;
V_1301:
if ( V_13 -> V_11 -> V_87 )
F_662 ( V_13 , V_11 -> V_367 ) ;
}
static struct V_294 * F_873 ( struct V_1 * V_2 ,
int V_94 )
{
struct V_383 * V_1072 ;
struct V_417 * V_11 ;
V_1072 = F_489 ( sizeof( * V_1072 ) , V_734 ) ;
if ( V_1072 == NULL )
return NULL ;
V_11 = F_861 ( & V_1072 -> V_15 ) ;
if ( ! V_11 ) {
F_212 ( V_1072 ) ;
return NULL ;
}
V_1072 -> V_15 . V_11 = & V_11 -> V_15 ;
V_1072 -> V_1290 = false ;
V_1072 -> V_1291 = 1 ;
V_1072 -> V_94 = V_94 ;
V_1072 -> V_164 = V_94 ;
V_1072 -> V_366 = F_874 ( V_94 ) ;
V_1072 -> V_1292 = F_869 ;
V_1072 -> V_1293 = F_872 ;
V_1072 -> F_383 = F_871 ;
F_864 ( V_2 , & V_1072 -> V_15 , 0 ,
& V_1297 ,
V_1304 ,
F_297 ( V_1304 ) ,
V_1204 ) ;
if ( F_51 ( V_2 ) -> V_103 >= 4 ) {
if ( ! V_2 -> V_725 . V_1299 )
V_2 -> V_725 . V_1299 =
F_867 ( V_2 ,
F_226 ( V_404 ) |
F_226 ( V_379 ) ) ;
if ( V_2 -> V_725 . V_1299 )
F_868 ( & V_1072 -> V_15 . V_15 ,
V_2 -> V_725 . V_1299 ,
V_11 -> V_15 . V_284 ) ;
}
if ( F_51 ( V_2 ) -> V_103 >= 9 )
V_11 -> V_422 = - 1 ;
F_866 ( & V_1072 -> V_15 , & V_1298 ) ;
return & V_1072 -> V_15 ;
}
static void F_656 ( struct V_1 * V_2 , struct V_12 * V_12 ,
struct V_18 * V_19 )
{
int V_25 ;
struct V_1305 * V_1305 ;
struct V_384 * V_385 = & V_19 -> V_385 ;
for ( V_25 = 0 ; V_25 < V_12 -> V_386 ; V_25 ++ ) {
V_1305 = & V_385 -> V_387 [ V_25 ] ;
V_1305 -> V_388 = 0 ;
V_1305 -> V_431 = V_1306 ;
}
V_385 -> V_422 = - 1 ;
}
static void F_875 ( struct V_1 * V_2 , int V_94 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_12 ;
struct V_18 * V_19 = NULL ;
struct V_294 * V_88 = NULL ;
struct V_294 * V_1072 = NULL ;
int V_25 , V_302 ;
V_12 = F_489 ( sizeof( * V_12 ) , V_734 ) ;
if ( V_12 == NULL )
return;
V_19 = F_489 ( sizeof( * V_19 ) , V_734 ) ;
if ( ! V_19 )
goto V_800;
V_12 -> V_90 = V_19 ;
V_12 -> V_15 . V_11 = & V_19 -> V_15 ;
V_19 -> V_15 . V_13 = & V_12 -> V_15 ;
if ( F_51 ( V_2 ) -> V_103 >= 9 ) {
if ( V_94 == V_517 )
V_12 -> V_386 = 1 ;
else
V_12 -> V_386 = V_1307 ;
F_656 ( V_2 , V_12 , V_19 ) ;
}
V_88 = F_860 ( V_2 , V_94 ) ;
if ( ! V_88 )
goto V_800;
V_1072 = F_873 ( V_2 , V_94 ) ;
if ( ! V_1072 )
goto V_800;
V_302 = F_876 ( V_2 , & V_12 -> V_15 , V_88 ,
V_1072 , & V_1308 ) ;
if ( V_302 )
goto V_800;
F_877 ( & V_12 -> V_15 , 256 ) ;
for ( V_25 = 0 ; V_25 < 256 ; V_25 ++ ) {
V_12 -> V_569 [ V_25 ] = V_25 ;
V_12 -> V_570 [ V_25 ] = V_25 ;
V_12 -> V_571 [ V_25 ] = V_25 ;
}
V_12 -> V_94 = V_94 ;
V_12 -> V_164 = V_94 ;
if ( F_863 ( V_2 ) && F_51 ( V_2 ) -> V_103 < 4 ) {
F_150 ( L_275 ) ;
V_12 -> V_164 = ! V_94 ;
}
V_12 -> V_1076 = ~ 0 ;
V_12 -> V_1075 = ~ 0 ;
V_12 -> V_1077 = ~ 0 ;
V_12 -> V_573 . V_581 = true ;
F_124 ( V_94 >= F_297 ( V_4 -> V_1140 ) ||
V_4 -> V_1140 [ V_12 -> V_164 ] != NULL ) ;
V_4 -> V_1140 [ V_12 -> V_164 ] = & V_12 -> V_15 ;
V_4 -> V_95 [ V_12 -> V_94 ] = & V_12 -> V_15 ;
F_878 ( & V_12 -> V_15 , & V_1309 ) ;
F_2 ( F_154 ( & V_12 -> V_15 ) != V_12 -> V_94 ) ;
return;
V_800:
if ( V_88 )
F_859 ( V_88 ) ;
if ( V_1072 )
F_859 ( V_1072 ) ;
F_212 ( V_19 ) ;
F_212 ( V_12 ) ;
}
enum V_94 F_879 ( struct V_732 * V_22 )
{
struct V_731 * V_17 = V_22 -> V_15 . V_17 ;
struct V_1 * V_2 = V_22 -> V_15 . V_2 ;
F_2 ( ! F_880 ( & V_2 -> V_725 . V_1103 ) ) ;
if ( ! V_17 || F_2 ( ! V_17 -> V_13 ) )
return V_595 ;
return F_41 ( V_17 -> V_13 ) -> V_94 ;
}
int F_881 ( struct V_1 * V_2 , void * V_1042 ,
struct V_1310 * V_1311 )
{
struct V_1312 * V_1313 = V_1042 ;
struct V_86 * V_1314 ;
struct V_12 * V_13 ;
V_1314 = F_882 ( V_2 , V_1313 -> V_1315 ) ;
if ( ! V_1314 ) {
F_129 ( L_276 ) ;
return - V_1316 ;
}
V_13 = F_41 ( V_1314 ) ;
V_1313 -> V_94 = V_13 -> V_94 ;
return 0 ;
}
static int F_883 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_15 . V_2 ;
struct V_16 * V_1211 ;
int V_1317 = 0 ;
int V_1318 = 0 ;
F_591 (dev, source_encoder) {
if ( F_774 ( V_17 , V_1211 ) )
V_1317 |= ( 1 << V_1318 ) ;
V_1318 ++ ;
}
return V_1317 ;
}
static bool F_884 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_125 ( V_2 ) )
return false ;
if ( ( F_4 ( V_1319 ) & V_1320 ) == 0 )
return false ;
if ( F_6 ( V_2 ) && ( F_4 ( V_636 ) & V_1321 ) )
return false ;
return true ;
}
static bool F_885 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_51 ( V_2 ) -> V_103 >= 9 )
return false ;
if ( F_509 ( V_2 ) || F_427 ( V_2 ) )
return false ;
if ( F_21 ( V_2 ) )
return false ;
if ( F_22 ( V_2 ) && ! V_4 -> V_818 . V_1322 )
return false ;
return true ;
}
static void F_886 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_16 * V_17 ;
bool V_1323 = false ;
F_887 ( V_2 ) ;
if ( F_885 ( V_2 ) )
F_888 ( V_2 ) ;
if ( F_18 ( V_2 ) ) {
F_889 ( V_2 , V_605 ) ;
F_889 ( V_2 , V_108 ) ;
F_889 ( V_2 , V_110 ) ;
} else if ( F_68 ( V_2 ) ) {
int V_76 ;
V_76 = F_4 ( V_1324 ) & V_1325 ;
if ( V_76 || F_425 ( V_2 ) )
F_889 ( V_2 , V_605 ) ;
V_76 = F_4 ( V_1326 ) ;
if ( V_76 & V_1327 )
F_889 ( V_2 , V_108 ) ;
if ( V_76 & V_1328 )
F_889 ( V_2 , V_110 ) ;
if ( V_76 & V_1329 )
F_889 ( V_2 , V_112 ) ;
if ( F_425 ( V_2 ) &&
( V_4 -> V_818 . V_1330 [ V_117 ] . V_1331 ||
V_4 -> V_818 . V_1330 [ V_117 ] . V_1332 ||
V_4 -> V_818 . V_1330 [ V_117 ] . V_1333 ) )
F_889 ( V_2 , V_117 ) ;
} else if ( F_3 ( V_2 ) ) {
int V_76 ;
V_1323 = F_890 ( V_2 , V_112 ) ;
if ( F_884 ( V_2 ) )
F_891 ( V_2 , V_1319 , V_605 ) ;
if ( F_4 ( V_203 ) & V_1334 ) {
V_76 = F_892 ( V_2 , V_1335 , true ) ;
if ( ! V_76 )
F_893 ( V_2 , V_203 , V_108 ) ;
if ( ! V_76 && ( F_4 ( V_196 ) & V_1320 ) )
F_891 ( V_2 , V_196 , V_108 ) ;
}
if ( F_4 ( V_204 ) & V_1334 )
F_893 ( V_2 , V_204 , V_110 ) ;
if ( ! V_1323 && F_4 ( V_205 ) & V_1334 )
F_893 ( V_2 , V_205 , V_112 ) ;
if ( F_4 ( V_198 ) & V_1320 )
F_891 ( V_2 , V_198 , V_110 ) ;
if ( F_4 ( V_200 ) & V_1320 )
F_891 ( V_2 , V_200 , V_112 ) ;
} else if ( F_22 ( V_2 ) ) {
if ( F_4 ( V_1336 + V_1337 ) & V_1334 &&
! F_890 ( V_2 , V_108 ) )
F_893 ( V_2 , V_1336 + V_1337 ,
V_108 ) ;
if ( F_4 ( V_1336 + V_1338 ) & V_1320 ||
F_890 ( V_2 , V_108 ) )
F_891 ( V_2 , V_1336 + V_1338 , V_108 ) ;
if ( F_4 ( V_1336 + V_1339 ) & V_1334 &&
! F_890 ( V_2 , V_110 ) )
F_893 ( V_2 , V_1336 + V_1339 ,
V_110 ) ;
if ( F_4 ( V_1336 + V_1340 ) & V_1320 ||
F_890 ( V_2 , V_110 ) )
F_891 ( V_2 , V_1336 + V_1340 , V_110 ) ;
if ( F_21 ( V_2 ) ) {
if ( F_4 ( V_1336 + V_1341 ) & V_1334 )
F_893 ( V_2 , V_1336 + V_1341 ,
V_112 ) ;
if ( F_4 ( V_1336 + V_1342 ) & V_1320 )
F_891 ( V_2 , V_1336 + V_1342 , V_112 ) ;
}
F_894 ( V_2 ) ;
} else if ( ! F_23 ( V_2 ) && ! F_20 ( V_2 ) ) {
bool V_76 = false ;
if ( F_4 ( V_1343 ) & V_1334 ) {
F_150 ( L_277 ) ;
V_76 = F_892 ( V_2 , V_1343 , true ) ;
if ( ! V_76 && F_19 ( V_2 ) ) {
F_150 ( L_278 ) ;
F_893 ( V_2 , V_1337 , V_108 ) ;
}
if ( ! V_76 && F_19 ( V_2 ) )
F_891 ( V_2 , V_1338 , V_108 ) ;
}
if ( F_4 ( V_1343 ) & V_1334 ) {
F_150 ( L_279 ) ;
V_76 = F_892 ( V_2 , V_1344 , false ) ;
}
if ( ! V_76 && ( F_4 ( V_1344 ) & V_1334 ) ) {
if ( F_19 ( V_2 ) ) {
F_150 ( L_280 ) ;
F_893 ( V_2 , V_1339 , V_110 ) ;
}
if ( F_19 ( V_2 ) )
F_891 ( V_2 , V_1340 , V_110 ) ;
}
if ( F_19 ( V_2 ) &&
( F_4 ( V_1342 ) & V_1320 ) )
F_891 ( V_2 , V_1342 , V_112 ) ;
} else if ( F_23 ( V_2 ) )
F_895 ( V_2 ) ;
if ( F_896 ( V_2 ) )
F_897 ( V_2 ) ;
F_898 ( V_2 ) ;
F_591 (dev, encoder) {
V_17 -> V_15 . V_1109 = V_17 -> V_237 ;
V_17 -> V_15 . V_1345 =
F_883 ( V_17 ) ;
}
F_598 ( V_2 ) ;
F_899 ( V_2 ) ;
}
static void F_900 ( struct V_276 * V_89 )
{
struct V_1 * V_2 = V_89 -> V_2 ;
struct V_938 * V_939 = F_206 ( V_89 ) ;
F_901 ( V_89 ) ;
F_62 ( & V_2 -> V_303 ) ;
F_2 ( ! V_939 -> V_300 -> V_1346 -- ) ;
F_207 ( & V_939 -> V_300 -> V_15 ) ;
F_64 ( & V_2 -> V_303 ) ;
F_212 ( V_939 ) ;
}
static int F_902 ( struct V_276 * V_89 ,
struct V_1310 * V_1311 ,
unsigned int * V_1347 )
{
struct V_938 * V_939 = F_206 ( V_89 ) ;
struct V_299 * V_300 = V_939 -> V_300 ;
if ( V_300 -> V_1348 . V_305 ) {
F_870 ( L_281 ) ;
return - V_304 ;
}
return F_903 ( V_1311 , & V_300 -> V_15 , V_1347 ) ;
}
static int F_904 ( struct V_276 * V_89 ,
struct V_1310 * V_1311 ,
unsigned V_351 , unsigned V_1349 ,
struct V_1350 * V_1351 ,
unsigned V_1352 )
{
struct V_1 * V_2 = V_89 -> V_2 ;
struct V_938 * V_939 = F_206 ( V_89 ) ;
struct V_299 * V_300 = V_939 -> V_300 ;
F_62 ( & V_2 -> V_303 ) ;
F_905 ( V_300 , false , V_1353 ) ;
F_64 ( & V_2 -> V_303 ) ;
return 0 ;
}
static
T_1 F_906 ( struct V_1 * V_2 , V_64 V_288 ,
T_4 V_265 )
{
T_1 V_103 = F_51 ( V_2 ) -> V_103 ;
if ( V_103 >= 9 ) {
return V_65 ( 8192 * F_176 ( V_265 , 0 ) , 32768 ) ;
} else if ( V_103 >= 5 && ! F_22 ( V_2 ) ) {
return 32 * 1024 ;
} else if ( V_103 >= 4 ) {
if ( V_288 == V_270 )
return 16 * 1024 ;
else
return 32 * 1024 ;
} else if ( V_103 >= 3 ) {
if ( V_288 == V_270 )
return 8 * 1024 ;
else
return 16 * 1024 ;
} else {
return 8 * 1024 ;
}
}
static int F_205 ( struct V_1 * V_2 ,
struct V_938 * V_939 ,
struct V_343 * V_344 ,
struct V_299 * V_300 )
{
unsigned int V_937 ;
int V_302 ;
T_1 V_1354 , V_1355 ;
F_2 ( ! F_189 ( & V_2 -> V_303 ) ) ;
if ( V_344 -> V_351 & V_352 ) {
if ( ! ! ( V_300 -> V_313 == V_348 ) !=
! ! ( V_344 -> V_289 [ 0 ] == V_270 ) ) {
F_870 ( L_282 ) ;
return - V_304 ;
}
} else {
if ( V_300 -> V_313 == V_348 )
V_344 -> V_289 [ 0 ] = V_270 ;
else if ( V_300 -> V_313 == V_1356 ) {
F_870 ( L_283 ) ;
return - V_304 ;
}
}
switch ( V_344 -> V_289 [ 0 ] ) {
case V_271 :
case V_272 :
if ( F_51 ( V_2 ) -> V_103 < 9 ) {
F_870 ( L_284 ,
V_344 -> V_289 [ 0 ] ) ;
return - V_304 ;
}
case V_269 :
case V_270 :
break;
default:
F_870 ( L_285 ,
V_344 -> V_289 [ 0 ] ) ;
return - V_304 ;
}
V_1355 = F_234 ( V_2 , V_344 -> V_289 [ 0 ] ,
V_344 -> V_265 ) ;
if ( V_344 -> V_287 [ 0 ] & ( V_1355 - 1 ) ) {
F_870 ( L_286 ,
V_344 -> V_287 [ 0 ] , V_1355 ) ;
return - V_304 ;
}
V_1354 = F_906 ( V_2 , V_344 -> V_289 [ 0 ] ,
V_344 -> V_265 ) ;
if ( V_344 -> V_287 [ 0 ] > V_1354 ) {
F_870 ( L_287 ,
V_344 -> V_289 [ 0 ] != V_269 ?
L_288 : L_289 ,
V_344 -> V_287 [ 0 ] , V_1354 ) ;
return - V_304 ;
}
if ( V_344 -> V_289 [ 0 ] == V_270 &&
V_344 -> V_287 [ 0 ] != V_300 -> V_349 ) {
F_870 ( L_290 ,
V_344 -> V_287 [ 0 ] , V_300 -> V_349 ) ;
return - V_304 ;
}
switch ( V_344 -> V_265 ) {
case V_321 :
case V_325 :
case V_327 :
case V_339 :
break;
case V_323 :
if ( F_51 ( V_2 ) -> V_103 > 3 ) {
F_870 ( L_291 ,
F_907 ( V_344 -> V_265 ) ) ;
return - V_304 ;
}
break;
case V_338 :
if ( ! F_22 ( V_2 ) && F_51 ( V_2 ) -> V_103 < 9 ) {
F_870 ( L_291 ,
F_907 ( V_344 -> V_265 ) ) ;
return - V_304 ;
}
break;
case V_329 :
case V_331 :
case V_333 :
if ( F_51 ( V_2 ) -> V_103 < 4 ) {
F_870 ( L_291 ,
F_907 ( V_344 -> V_265 ) ) ;
return - V_304 ;
}
break;
case V_1357 :
if ( ! F_22 ( V_2 ) ) {
F_870 ( L_291 ,
F_907 ( V_344 -> V_265 ) ) ;
return - V_304 ;
}
break;
case V_392 :
case V_397 :
case V_395 :
case V_399 :
if ( F_51 ( V_2 ) -> V_103 < 5 ) {
F_870 ( L_291 ,
F_907 ( V_344 -> V_265 ) ) ;
return - V_304 ;
}
break;
default:
F_870 ( L_291 ,
F_907 ( V_344 -> V_265 ) ) ;
return - V_304 ;
}
if ( V_344 -> V_1186 [ 0 ] != 0 )
return - V_304 ;
V_937 = F_179 ( V_2 , V_344 -> V_273 ,
V_344 -> V_265 ,
V_344 -> V_289 [ 0 ] ) ;
if ( V_300 -> V_15 . V_293 < V_937 * V_344 -> V_287 [ 0 ] )
return - V_304 ;
F_908 ( & V_939 -> V_15 , V_344 ) ;
V_939 -> V_300 = V_300 ;
V_939 -> V_300 -> V_1346 ++ ;
V_302 = F_909 ( V_2 , & V_939 -> V_15 , & V_1358 ) ;
if ( V_302 ) {
F_129 ( L_292 , V_302 ) ;
return V_302 ;
}
return 0 ;
}
static struct V_276 *
F_910 ( struct V_1 * V_2 ,
struct V_1310 * V_1359 ,
struct V_343 * V_344 )
{
struct V_299 * V_300 ;
V_300 = F_911 ( F_912 ( V_2 , V_1359 ,
V_344 -> V_1360 [ 0 ] ) ) ;
if ( & V_300 -> V_15 == NULL )
return F_667 ( - V_1316 ) ;
return F_668 ( V_2 , V_344 , V_300 ) ;
}
static inline void F_913 ( struct V_1 * V_2 )
{
}
static void F_914 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_3 ( V_2 ) || F_19 ( V_2 ) )
V_4 -> V_435 . V_931 = F_36 ;
else if ( F_21 ( V_2 ) )
V_4 -> V_435 . V_931 = F_42 ;
else if ( F_22 ( V_2 ) )
V_4 -> V_435 . V_931 = F_40 ;
else if ( F_20 ( V_2 ) )
V_4 -> V_435 . V_931 = F_35 ;
else
V_4 -> V_435 . V_931 = F_34 ;
if ( F_51 ( V_2 ) -> V_103 >= 9 ) {
V_4 -> V_435 . V_1260 = F_655 ;
V_4 -> V_435 . V_1361 =
F_624 ;
V_4 -> V_435 . V_1212 =
F_647 ;
V_4 -> V_435 . V_1274 = F_394 ;
V_4 -> V_435 . V_723 = F_407 ;
V_4 -> V_435 . V_436 =
F_245 ;
} else if ( F_68 ( V_2 ) ) {
V_4 -> V_435 . V_1260 = F_655 ;
V_4 -> V_435 . V_1361 =
F_627 ;
V_4 -> V_435 . V_1212 =
F_647 ;
V_4 -> V_435 . V_1274 = F_394 ;
V_4 -> V_435 . V_723 = F_407 ;
V_4 -> V_435 . V_436 =
F_230 ;
} else if ( F_3 ( V_2 ) ) {
V_4 -> V_435 . V_1260 = F_628 ;
V_4 -> V_435 . V_1361 =
F_627 ;
V_4 -> V_435 . V_1212 =
F_617 ;
V_4 -> V_435 . V_1274 = F_385 ;
V_4 -> V_435 . V_723 = F_405 ;
V_4 -> V_435 . V_436 =
F_230 ;
} else if ( F_22 ( V_2 ) ) {
V_4 -> V_435 . V_1260 = F_588 ;
V_4 -> V_435 . V_1361 =
F_586 ;
V_4 -> V_435 . V_1212 = F_583 ;
V_4 -> V_435 . V_1274 = F_466 ;
V_4 -> V_435 . V_723 = F_477 ;
V_4 -> V_435 . V_436 =
F_217 ;
} else {
V_4 -> V_435 . V_1260 = F_588 ;
V_4 -> V_435 . V_1361 =
F_586 ;
V_4 -> V_435 . V_1212 = F_583 ;
V_4 -> V_435 . V_1274 = F_475 ;
V_4 -> V_435 . V_723 = F_477 ;
V_4 -> V_435 . V_436 =
F_217 ;
}
if ( F_425 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_505 ;
else if ( F_18 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_506 ;
else if ( F_232 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_507 ;
else if ( F_231 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_508 ;
else if ( F_22 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_510 ;
else if ( F_6 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_511 ;
else if ( F_574 ( V_2 ) || F_185 ( V_2 ) ||
F_295 ( V_2 ) || F_286 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_512 ;
else if ( F_524 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_526 ;
else if ( F_186 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_527 ;
else if ( F_20 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_515 ;
else if ( F_525 ( V_2 ) || F_19 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_528 ;
else if ( F_504 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_513 ;
else if ( F_575 ( V_2 ) || F_79 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_514 ;
else if ( F_20 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_515 ;
else if ( F_915 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_517 ;
else if ( F_80 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_518 ;
else if ( F_916 ( V_2 ) )
V_4 -> V_435 . V_638 =
F_519 ;
else {
F_54 ( ! F_139 ( V_2 ) , L_293 ) ;
V_4 -> V_435 . V_638 =
F_522 ;
}
if ( F_6 ( V_2 ) ) {
V_4 -> V_435 . V_519 = F_287 ;
} else if ( F_295 ( V_2 ) ) {
V_4 -> V_435 . V_519 = F_293 ;
} else if ( F_286 ( V_2 ) ) {
V_4 -> V_435 . V_519 = F_296 ;
} else if ( F_231 ( V_2 ) || F_232 ( V_2 ) ) {
V_4 -> V_435 . V_519 = V_1362 ;
if ( F_232 ( V_2 ) ) {
V_4 -> V_435 . V_626 =
F_646 ;
V_4 -> V_435 . V_1269 =
F_645 ;
}
} else if ( F_22 ( V_2 ) ) {
V_4 -> V_435 . V_626 =
F_465 ;
V_4 -> V_435 . V_1269 =
F_461 ;
} else if ( F_18 ( V_2 ) ) {
V_4 -> V_435 . V_626 =
F_642 ;
V_4 -> V_435 . V_1269 =
F_462 ;
}
switch ( F_51 ( V_2 ) -> V_103 ) {
case 2 :
V_4 -> V_435 . V_1194 = F_719 ;
break;
case 3 :
V_4 -> V_435 . V_1194 = F_723 ;
break;
case 4 :
case 5 :
V_4 -> V_435 . V_1194 = F_724 ;
break;
case 6 :
V_4 -> V_435 . V_1194 = F_725 ;
break;
case 7 :
case 8 :
V_4 -> V_435 . V_1194 = F_726 ;
break;
case 9 :
default:
V_4 -> V_435 . V_1194 = F_747 ;
}
F_917 ( V_2 ) ;
F_918 ( & V_4 -> V_1363 ) ;
}
static void F_919 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_160 |= V_161 ;
F_920 ( L_294 ) ;
}
static void F_921 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_160 |= V_162 ;
F_920 ( L_295 ) ;
}
static void F_922 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_160 |= V_820 ;
F_920 ( L_296 ) ;
}
static void F_923 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_160 |= V_1364 ;
F_920 ( L_297 ) ;
}
static void F_924 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_160 |= V_1365 ;
F_920 ( L_298 ) ;
}
static int F_925 ( const struct V_1366 * V_240 )
{
F_920 ( L_299 , V_240 -> V_1367 ) ;
return 1 ;
}
static void F_926 ( struct V_1 * V_2 )
{
struct V_1368 * V_1369 = V_2 -> V_762 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < F_297 ( V_1370 ) ; V_25 ++ ) {
struct V_1371 * V_1372 = & V_1370 [ V_25 ] ;
if ( V_1369 -> V_1373 == V_1372 -> V_1373 &&
( V_1369 -> V_1374 == V_1372 -> V_1374 ||
V_1372 -> V_1374 == V_1375 ) &&
( V_1369 -> V_1376 == V_1372 -> V_1376 ||
V_1372 -> V_1376 == V_1375 ) )
V_1372 -> V_1377 ( V_2 ) ;
}
for ( V_25 = 0 ; V_25 < F_297 ( V_1378 ) ; V_25 ++ ) {
if ( F_927 ( * V_1378 [ V_25 ] . V_1379 ) != 0 )
V_1378 [ V_25 ] . V_1377 ( V_2 ) ;
}
}
static void F_928 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_11 V_1380 ;
T_1 V_1381 = F_929 ( V_2 ) ;
F_930 ( V_2 -> V_762 , V_1382 ) ;
F_931 ( V_1383 , V_1384 ) ;
V_1380 = F_932 ( V_1385 ) ;
F_931 ( V_1380 | 1 << 5 , V_1385 ) ;
F_933 ( V_2 -> V_762 , V_1382 ) ;
F_128 ( 300 ) ;
F_126 ( V_1381 , V_1386 ) ;
F_127 ( V_1381 ) ;
}
void F_269 ( struct V_1 * V_2 )
{
F_428 ( V_2 ) ;
F_641 ( V_2 ) ;
F_934 ( V_2 ) ;
F_935 ( V_2 ) ;
}
void F_936 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_169 , V_302 ;
enum V_94 V_94 ;
struct V_12 * V_13 ;
F_937 ( V_2 ) ;
V_2 -> V_725 . V_1387 = 0 ;
V_2 -> V_725 . V_1388 = 0 ;
V_2 -> V_725 . V_1389 = 24 ;
V_2 -> V_725 . V_1390 = 1 ;
V_2 -> V_725 . V_1391 = true ;
V_2 -> V_725 . V_1108 = & V_1392 ;
F_926 ( V_2 ) ;
F_938 ( V_2 ) ;
if ( F_51 ( V_2 ) -> V_737 == 0 )
return;
if ( F_56 ( V_2 ) || F_102 ( V_2 ) ) {
bool V_1393 = ! ! ( F_4 ( V_174 ) &
V_959 ) ;
if ( V_4 -> V_818 . V_819 != V_1393 ) {
F_150 ( L_300 ,
V_1393 ? L_72 : L_73 ,
V_4 -> V_818 . V_819 ? L_72 : L_73 ) ;
V_4 -> V_818 . V_819 = V_1393 ;
}
}
F_914 ( V_2 ) ;
F_939 ( V_2 ) ;
if ( F_23 ( V_2 ) ) {
V_2 -> V_725 . V_1394 = 2048 ;
V_2 -> V_725 . V_1395 = 2048 ;
} else if ( F_940 ( V_2 ) ) {
V_2 -> V_725 . V_1394 = 4096 ;
V_2 -> V_725 . V_1395 = 4096 ;
} else {
V_2 -> V_725 . V_1394 = 8192 ;
V_2 -> V_725 . V_1395 = 8192 ;
}
if ( F_79 ( V_2 ) || F_80 ( V_2 ) ) {
V_2 -> V_725 . V_1396 = F_79 ( V_2 ) ? 64 : 512 ;
V_2 -> V_725 . V_1397 = 1023 ;
} else if ( F_23 ( V_2 ) ) {
V_2 -> V_725 . V_1396 = V_1398 ;
V_2 -> V_725 . V_1397 = V_1399 ;
} else {
V_2 -> V_725 . V_1396 = V_1400 ;
V_2 -> V_725 . V_1397 = V_1401 ;
}
V_2 -> V_725 . V_1402 = V_4 -> V_1403 . V_1404 ;
F_150 ( L_301 ,
F_51 ( V_2 ) -> V_737 ,
F_51 ( V_2 ) -> V_737 > 1 ? L_302 : L_303 ) ;
F_89 (dev_priv, pipe) {
F_875 ( V_2 , V_94 ) ;
F_91 (dev_priv, pipe, sprite) {
V_302 = F_941 ( V_2 , V_94 , V_169 ) ;
if ( V_302 )
F_150 ( L_304 ,
F_77 ( V_94 ) , F_94 ( V_94 , V_169 ) , V_302 ) ;
}
}
F_120 ( V_2 ) ;
F_846 ( V_2 ) ;
F_928 ( V_2 ) ;
F_886 ( V_2 ) ;
F_942 ( V_4 ) ;
F_263 ( V_2 ) ;
F_943 ( V_2 ) ;
F_274 ( V_2 ) ;
F_137 (dev, crtc) {
struct V_341 V_342 = {} ;
if ( ! V_13 -> V_87 )
continue;
V_4 -> V_435 . V_1361 ( V_13 ,
& V_342 ) ;
F_211 ( V_13 , & V_342 ) ;
}
}
static void F_944 ( struct V_1 * V_2 )
{
struct V_732 * V_22 ;
struct V_21 * V_1405 = NULL ;
struct V_1100 V_1106 ;
struct V_726 * V_727 = V_2 -> V_725 . V_728 ;
F_780 (dev, connector) {
if ( V_22 -> V_17 -> type == V_39 ) {
V_1405 = & V_22 -> V_15 ;
break;
}
}
if ( ! V_1405 )
return;
if ( F_683 ( V_1405 , NULL , & V_1106 , V_727 ) )
F_688 ( V_1405 , & V_1106 , V_727 ) ;
}
static bool
F_945 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_97 , V_121 ;
if ( F_51 ( V_2 ) -> V_737 == 1 )
return true ;
V_97 = F_86 ( ! V_13 -> V_164 ) ;
V_121 = F_4 ( V_97 ) ;
if ( ( V_121 & V_165 ) &&
( ! ! ( V_121 & V_167 ) == V_13 -> V_94 ) )
return false ;
return true ;
}
static void F_946 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_16 * V_17 ;
T_1 V_97 ;
bool V_242 ;
V_97 = F_52 ( V_13 -> V_90 -> V_96 ) ;
F_126 ( V_97 , F_4 ( V_97 ) & ~ V_1406 ) ;
F_947 ( & V_13 -> V_15 ) ;
if ( V_13 -> V_87 ) {
struct V_383 * V_164 ;
F_948 ( & V_13 -> V_15 , & V_13 -> V_15 . V_1239 ) ;
F_820 ( V_13 ) ;
F_391 ( & V_13 -> V_15 ) ;
F_949 (dev, crtc, plane) {
if ( V_164 -> V_15 . type == V_1207 )
continue;
V_164 -> F_383 ( & V_164 -> V_15 , & V_13 -> V_15 ) ;
}
}
if ( F_51 ( V_2 ) -> V_103 < 4 && ! F_945 ( V_13 ) ) {
bool V_164 ;
F_150 ( L_305 ,
V_13 -> V_15 . V_15 . V_240 ) ;
V_164 = V_13 -> V_164 ;
F_218 ( V_13 -> V_15 . V_88 -> V_11 ) -> V_367 = true ;
V_13 -> V_164 = ! V_164 ;
F_478 ( & V_13 -> V_15 ) ;
V_13 -> V_164 = V_164 ;
}
if ( V_4 -> V_160 & V_161 &&
V_13 -> V_94 == V_142 && ! V_13 -> V_87 ) {
F_944 ( V_2 ) ;
}
V_242 = false ;
F_10 (dev, &crtc->base, encoder) {
V_242 = true ;
break;
}
if ( ! V_242 )
F_478 ( & V_13 -> V_15 ) ;
if ( V_13 -> V_87 != V_13 -> V_15 . V_11 -> V_87 ) {
F_150 ( L_306 ,
V_13 -> V_15 . V_15 . V_240 ,
V_13 -> V_15 . V_11 -> V_242 ? L_215 : L_216 ,
V_13 -> V_87 ? L_215 : L_216 ) ;
F_2 ( F_950 ( V_13 -> V_15 . V_11 , NULL ) < 0 ) ;
V_13 -> V_15 . V_11 -> V_87 = V_13 -> V_87 ;
V_13 -> V_15 . V_120 = V_13 -> V_87 ;
F_2 ( V_13 -> V_87 ) ;
F_10 (dev, &crtc->base, encoder)
V_17 -> V_15 . V_13 = NULL ;
}
if ( V_13 -> V_87 || F_168 ( V_2 ) ) {
V_13 -> V_1407 = true ;
V_13 -> V_1408 = true ;
}
}
static void F_951 ( struct V_16 * V_17 )
{
struct V_732 * V_22 ;
struct V_1 * V_2 = V_17 -> V_15 . V_2 ;
bool V_87 = false ;
bool V_1409 = V_17 -> V_15 . V_13 &&
F_41 ( V_17 -> V_15 . V_13 ) -> V_87 ;
F_780 (dev, connector) {
if ( V_22 -> V_15 . V_17 != & V_17 -> V_15 )
continue;
V_87 = true ;
break;
}
if ( V_87 && ! V_1409 ) {
F_150 ( L_307 ,
V_17 -> V_15 . V_15 . V_240 ,
V_17 -> V_15 . V_134 ) ;
if ( V_17 -> V_15 . V_13 ) {
F_150 ( L_308 ,
V_17 -> V_15 . V_15 . V_240 ,
V_17 -> V_15 . V_134 ) ;
V_17 -> V_243 ( V_17 ) ;
if ( V_17 -> V_596 )
V_17 -> V_596 ( V_17 ) ;
}
V_17 -> V_15 . V_13 = NULL ;
F_780 (dev, connector) {
if ( V_22 -> V_17 != V_17 )
continue;
V_22 -> V_15 . V_1105 = V_1410 ;
V_22 -> V_15 . V_17 = NULL ;
}
}
}
void F_952 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_1381 = F_929 ( V_2 ) ;
if ( ! ( F_4 ( V_1381 ) & V_1386 ) ) {
F_150 ( L_309 ) ;
F_928 ( V_2 ) ;
}
}
void F_953 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_83 ( V_4 , V_1411 ) )
return;
F_952 ( V_2 ) ;
}
static bool F_954 ( struct V_383 * V_164 )
{
struct V_3 * V_4 = F_266 ( V_164 -> V_15 . V_2 ) ;
return F_4 ( F_86 ( V_164 -> V_164 ) ) & V_165 ;
}
static void F_955 ( struct V_12 * V_13 )
{
struct V_294 * V_88 = V_13 -> V_15 . V_88 ;
struct V_417 * V_278 =
F_218 ( V_88 -> V_11 ) ;
V_278 -> V_367 =
F_954 ( F_216 ( V_88 ) ) ;
if ( V_278 -> V_367 )
V_13 -> V_15 . V_11 -> V_364 |= 1 << F_215 ( V_88 ) ;
}
static void F_956 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_94 V_94 ;
struct V_12 * V_13 ;
struct V_16 * V_17 ;
struct V_732 * V_22 ;
int V_25 ;
F_137 (dev, crtc) {
F_815 ( & V_13 -> V_15 , V_13 -> V_15 . V_11 ) ;
memset ( V_13 -> V_90 , 0 , sizeof( * V_13 -> V_90 ) ) ;
V_13 -> V_90 -> V_15 . V_13 = & V_13 -> V_15 ;
V_13 -> V_87 = V_4 -> V_435 . V_1260 ( V_13 ,
V_13 -> V_90 ) ;
V_13 -> V_15 . V_11 -> V_87 = V_13 -> V_87 ;
V_13 -> V_15 . V_120 = V_13 -> V_87 ;
F_955 ( V_13 ) ;
F_150 ( L_310 ,
V_13 -> V_15 . V_15 . V_240 ,
V_13 -> V_87 ? L_215 : L_216 ) ;
}
for ( V_25 = 0 ; V_25 < V_4 -> V_535 ; V_25 ++ ) {
struct V_127 * V_130 = & V_4 -> V_129 [ V_25 ] ;
V_130 -> V_238 = V_130 -> V_133 ( V_4 , V_130 ,
& V_130 -> V_90 . V_132 ) ;
V_130 -> V_87 = 0 ;
V_130 -> V_90 . V_237 = 0 ;
F_137 (dev, crtc) {
if ( V_13 -> V_87 && F_65 ( V_13 ) == V_130 ) {
V_130 -> V_87 ++ ;
V_130 -> V_90 . V_237 |= 1 << V_13 -> V_94 ;
}
}
F_150 ( L_311 ,
V_130 -> V_134 , V_130 -> V_90 . V_237 , V_130 -> V_238 ) ;
if ( V_130 -> V_90 . V_237 )
F_152 ( V_4 , V_241 ) ;
}
F_591 (dev, encoder) {
V_94 = 0 ;
if ( V_17 -> V_133 ( V_17 , & V_94 ) ) {
V_13 = F_41 ( V_4 -> V_95 [ V_94 ] ) ;
V_17 -> V_15 . V_13 = & V_13 -> V_15 ;
V_17 -> V_1261 ( V_17 , V_13 -> V_90 ) ;
} else {
V_17 -> V_15 . V_13 = NULL ;
}
F_150 ( L_312 ,
V_17 -> V_15 . V_15 . V_240 ,
V_17 -> V_15 . V_134 ,
V_17 -> V_15 . V_13 ? L_215 : L_216 ,
F_77 ( V_94 ) ) ;
}
F_780 (dev, connector) {
if ( V_22 -> V_133 ( V_22 ) ) {
V_22 -> V_15 . V_1105 = V_1107 ;
V_22 -> V_15 . V_17 = & V_22 -> V_17 -> V_15 ;
} else {
V_22 -> V_15 . V_1105 = V_1410 ;
V_22 -> V_15 . V_17 = NULL ;
}
F_150 ( L_313 ,
V_22 -> V_15 . V_15 . V_240 ,
V_22 -> V_15 . V_134 ,
V_22 -> V_15 . V_17 ? L_215 : L_216 ) ;
}
F_137 (dev, crtc) {
V_13 -> V_15 . V_1239 = V_13 -> V_90 -> V_15 . V_91 ;
memset ( & V_13 -> V_15 . V_431 , 0 , sizeof( V_13 -> V_15 . V_431 ) ) ;
if ( V_13 -> V_15 . V_11 -> V_87 ) {
F_578 ( & V_13 -> V_15 . V_431 , V_13 -> V_90 ) ;
F_578 ( & V_13 -> V_15 . V_11 -> V_91 , V_13 -> V_90 ) ;
F_2 ( F_950 ( V_13 -> V_15 . V_11 , & V_13 -> V_15 . V_431 ) ) ;
V_13 -> V_15 . V_11 -> V_431 . V_1271 = V_1412 ;
}
}
}
static void
F_943 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_94 V_94 ;
struct V_12 * V_13 ;
struct V_16 * V_17 ;
int V_25 ;
F_956 ( V_2 ) ;
F_591 (dev, encoder) {
F_951 ( V_17 ) ;
}
F_89 (dev_priv, pipe) {
V_13 = F_41 ( V_4 -> V_95 [ V_94 ] ) ;
F_946 ( V_13 ) ;
F_785 ( V_13 , V_13 -> V_90 ,
L_314 ) ;
}
F_779 ( V_2 ) ;
for ( V_25 = 0 ; V_25 < V_4 -> V_535 ; V_25 ++ ) {
struct V_127 * V_130 = & V_4 -> V_129 [ V_25 ] ;
if ( ! V_130 -> V_238 || V_130 -> V_87 )
continue;
F_150 ( L_315 , V_130 -> V_134 ) ;
V_130 -> V_243 ( V_4 , V_130 ) ;
V_130 -> V_238 = false ;
}
if ( F_22 ( V_2 ) )
F_957 ( V_2 ) ;
else if ( F_958 ( V_2 ) )
F_959 ( V_2 ) ;
else if ( F_3 ( V_2 ) )
F_960 ( V_2 ) ;
F_137 (dev, crtc) {
unsigned long V_624 ;
V_624 = F_419 ( & V_13 -> V_15 ) ;
if ( F_2 ( V_624 ) )
F_421 ( V_4 , V_624 ) ;
}
F_961 ( V_4 , false ) ;
}
void F_272 ( struct V_1 * V_2 )
{
struct V_20 * V_11 = F_480 ( V_2 ) ;
struct V_732 * V_1413 ;
struct V_383 * V_164 ;
struct V_86 * V_13 ;
int V_302 ;
if ( ! V_11 )
return;
V_11 -> V_728 = V_2 -> V_725 . V_728 ;
F_344 ( V_11 ) ;
F_213 (dev, crtc) {
struct V_10 * V_19 =
F_481 ( V_11 , V_13 ) ;
V_302 = F_482 ( V_19 ) ;
if ( V_302 )
goto V_73;
V_19 -> V_1198 = true ;
}
F_962 (dev, plane) {
V_302 = F_482 ( F_679 ( V_11 , & V_164 -> V_15 ) ) ;
if ( V_302 )
goto V_73;
}
F_780 (dev, conn) {
V_302 = F_482 ( F_685 ( V_11 , & V_1413 -> V_15 ) ) ;
if ( V_302 )
goto V_73;
}
F_943 ( V_2 ) ;
F_953 ( V_2 ) ;
V_302 = F_483 ( V_11 ) ;
if ( ! V_302 )
return;
V_73:
F_129 ( L_316 , V_302 ) ;
F_484 ( V_11 ) ;
}
void F_963 ( struct V_1 * V_2 )
{
struct V_86 * V_354 ;
struct V_299 * V_300 ;
int V_302 ;
F_62 ( & V_2 -> V_303 ) ;
F_964 ( V_2 ) ;
F_64 ( & V_2 -> V_303 ) ;
F_269 ( V_2 ) ;
F_965 ( V_2 ) ;
F_213 (dev, c) {
V_300 = F_188 ( V_354 -> V_88 -> V_89 ) ;
if ( V_300 == NULL )
continue;
F_62 ( & V_2 -> V_303 ) ;
V_302 = F_187 ( V_354 -> V_88 ,
V_354 -> V_88 -> V_89 ,
V_354 -> V_88 -> V_11 ,
NULL , NULL ) ;
F_64 ( & V_2 -> V_303 ) ;
if ( V_302 ) {
F_129 ( L_317 ,
F_41 ( V_354 ) -> V_94 ) ;
F_209 ( V_354 -> V_88 -> V_89 ) ;
V_354 -> V_88 -> V_89 = NULL ;
V_354 -> V_88 -> V_13 = V_354 -> V_88 -> V_11 -> V_13 = NULL ;
F_208 ( V_354 -> V_88 ) ;
V_354 -> V_11 -> V_364 &= ~ ( 1 << F_215 ( V_354 -> V_88 ) ) ;
}
}
F_966 ( V_2 ) ;
}
void F_967 ( struct V_732 * V_732 )
{
struct V_21 * V_22 = & V_732 -> V_15 ;
F_968 ( V_22 ) ;
F_969 ( V_22 ) ;
}
void F_970 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_21 * V_22 ;
F_971 ( V_2 ) ;
F_972 ( V_2 ) ;
F_973 ( V_4 ) ;
F_974 ( V_2 ) ;
F_975 () ;
F_942 ( V_4 ) ;
F_976 () ;
F_788 (connector, &dev->mode_config.connector_list, head) {
struct V_732 * V_732 ;
V_732 = F_783 ( V_22 ) ;
V_732 -> V_1414 ( V_732 ) ;
}
F_977 ( V_2 ) ;
F_978 ( V_2 ) ;
F_62 ( & V_2 -> V_303 ) ;
F_979 ( V_2 ) ;
F_64 ( & V_2 -> V_303 ) ;
}
struct V_731 * F_980 ( struct V_21 * V_22 )
{
return & F_684 ( V_22 ) -> V_15 ;
}
void F_981 ( struct V_732 * V_22 ,
struct V_16 * V_17 )
{
V_22 -> V_17 = V_17 ;
F_982 ( & V_22 -> V_15 ,
& V_17 -> V_15 ) ;
}
int F_983 ( struct V_1 * V_2 , bool V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned V_97 = F_51 ( V_2 ) -> V_103 >= 6 ? V_1415 : V_1416 ;
T_5 V_1417 ;
if ( F_516 ( V_4 -> V_1418 , V_97 , & V_1417 ) ) {
F_129 ( L_318 ) ;
return - V_1195 ;
}
if ( ! ! ( V_1417 & V_1419 ) == ! V_11 )
return 0 ;
if ( V_11 )
V_1417 &= ~ V_1419 ;
else
V_1417 |= V_1419 ;
if ( F_984 ( V_4 -> V_1418 , V_97 , V_1417 ) ) {
F_129 ( L_319 ) ;
return - V_1195 ;
}
return 0 ;
}
struct V_1420 *
F_985 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_1420 * error ;
int V_1421 [] = {
V_255 ,
V_1422 ,
V_1423 ,
V_592 ,
} ;
int V_25 ;
if ( F_51 ( V_2 ) -> V_737 == 0 )
return NULL ;
error = F_489 ( sizeof( * error ) , V_1424 ) ;
if ( error == NULL )
return NULL ;
if ( F_231 ( V_2 ) || F_232 ( V_2 ) )
error -> V_1425 = F_4 ( V_1009 ) ;
F_89 (dev_priv, i) {
error -> V_94 [ V_25 ] . V_1426 =
F_986 ( V_4 ,
F_417 ( V_25 ) ) ;
if ( ! error -> V_94 [ V_25 ] . V_1426 )
continue;
error -> V_1072 [ V_25 ] . V_599 = F_4 ( F_81 ( V_25 ) ) ;
error -> V_1072 [ V_25 ] . V_1427 = F_4 ( F_663 ( V_25 ) ) ;
error -> V_1072 [ V_25 ] . V_15 = F_4 ( F_661 ( V_25 ) ) ;
error -> V_164 [ V_25 ] . V_599 = F_4 ( F_86 ( V_25 ) ) ;
error -> V_164 [ V_25 ] . V_349 = F_4 ( F_227 ( V_25 ) ) ;
if ( F_51 ( V_2 ) -> V_103 <= 3 ) {
error -> V_164 [ V_25 ] . V_293 = F_4 ( F_221 ( V_25 ) ) ;
error -> V_164 [ V_25 ] . V_556 = F_4 ( F_222 ( V_25 ) ) ;
}
if ( F_51 ( V_2 ) -> V_103 <= 7 && ! F_231 ( V_2 ) )
error -> V_164 [ V_25 ] . V_1179 = F_4 ( F_220 ( V_25 ) ) ;
if ( F_51 ( V_2 ) -> V_103 >= 4 ) {
error -> V_164 [ V_25 ] . V_1428 = F_4 ( F_219 ( V_25 ) ) ;
error -> V_164 [ V_25 ] . V_1429 = F_4 ( F_228 ( V_25 ) ) ;
}
error -> V_94 [ V_25 ] . V_1430 = F_4 ( F_281 ( V_25 ) ) ;
if ( F_168 ( V_2 ) )
error -> V_94 [ V_25 ] . V_1431 = F_4 ( F_987 ( V_25 ) ) ;
}
error -> V_1432 = F_51 ( V_2 ) -> V_737 ;
if ( F_68 ( V_4 -> V_2 ) )
error -> V_1432 ++ ;
for ( V_25 = 0 ; V_25 < error -> V_1432 ; V_25 ++ ) {
enum V_93 V_96 = V_1421 [ V_25 ] ;
error -> V_93 [ V_25 ] . V_1426 =
F_986 ( V_4 ,
F_84 ( V_96 ) ) ;
if ( ! error -> V_93 [ V_25 ] . V_1426 )
continue;
error -> V_93 [ V_25 ] . V_96 = V_96 ;
error -> V_93 [ V_25 ] . V_1433 = F_4 ( F_52 ( V_96 ) ) ;
error -> V_93 [ V_25 ] . V_909 = F_4 ( F_321 ( V_96 ) ) ;
error -> V_93 [ V_25 ] . V_1434 = F_4 ( F_323 ( V_96 ) ) ;
error -> V_93 [ V_25 ] . V_915 = F_4 ( F_325 ( V_96 ) ) ;
error -> V_93 [ V_25 ] . V_911 = F_4 ( F_327 ( V_96 ) ) ;
error -> V_93 [ V_25 ] . V_1435 = F_4 ( F_329 ( V_96 ) ) ;
error -> V_93 [ V_25 ] . V_1134 = F_4 ( F_331 ( V_96 ) ) ;
}
return error ;
}
void
F_988 ( struct V_1436 * V_54 ,
struct V_1 * V_2 ,
struct V_1420 * error )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_25 ;
if ( ! error )
return;
F_989 ( V_54 , L_320 , F_51 ( V_2 ) -> V_737 ) ;
if ( F_231 ( V_2 ) || F_232 ( V_2 ) )
F_989 ( V_54 , L_321 ,
error -> V_1425 ) ;
F_89 (dev_priv, i) {
F_989 ( V_54 , L_322 , V_25 ) ;
F_989 ( V_54 , L_323 ,
error -> V_94 [ V_25 ] . V_1426 ? L_11 : L_12 ) ;
F_989 ( V_54 , L_324 , error -> V_94 [ V_25 ] . V_1430 ) ;
F_989 ( V_54 , L_325 , error -> V_94 [ V_25 ] . V_1431 ) ;
F_989 ( V_54 , L_326 , V_25 ) ;
F_989 ( V_54 , L_327 , error -> V_164 [ V_25 ] . V_599 ) ;
F_989 ( V_54 , L_328 , error -> V_164 [ V_25 ] . V_349 ) ;
if ( F_51 ( V_2 ) -> V_103 <= 3 ) {
F_989 ( V_54 , L_329 , error -> V_164 [ V_25 ] . V_293 ) ;
F_989 ( V_54 , L_330 , error -> V_164 [ V_25 ] . V_556 ) ;
}
if ( F_51 ( V_2 ) -> V_103 <= 7 && ! F_231 ( V_2 ) )
F_989 ( V_54 , L_331 , error -> V_164 [ V_25 ] . V_1179 ) ;
if ( F_51 ( V_2 ) -> V_103 >= 4 ) {
F_989 ( V_54 , L_332 , error -> V_164 [ V_25 ] . V_1428 ) ;
F_989 ( V_54 , L_333 , error -> V_164 [ V_25 ] . V_1429 ) ;
}
F_989 ( V_54 , L_334 , V_25 ) ;
F_989 ( V_54 , L_327 , error -> V_1072 [ V_25 ] . V_599 ) ;
F_989 ( V_54 , L_330 , error -> V_1072 [ V_25 ] . V_1427 ) ;
F_989 ( V_54 , L_335 , error -> V_1072 [ V_25 ] . V_15 ) ;
}
for ( V_25 = 0 ; V_25 < error -> V_1432 ; V_25 ++ ) {
F_989 ( V_54 , L_336 ,
F_786 ( error -> V_93 [ V_25 ] . V_96 ) ) ;
F_989 ( V_54 , L_323 ,
error -> V_93 [ V_25 ] . V_1426 ? L_11 : L_12 ) ;
F_989 ( V_54 , L_337 , error -> V_93 [ V_25 ] . V_1433 ) ;
F_989 ( V_54 , L_338 , error -> V_93 [ V_25 ] . V_909 ) ;
F_989 ( V_54 , L_339 , error -> V_93 [ V_25 ] . V_1434 ) ;
F_989 ( V_54 , L_340 , error -> V_93 [ V_25 ] . V_915 ) ;
F_989 ( V_54 , L_341 , error -> V_93 [ V_25 ] . V_911 ) ;
F_989 ( V_54 , L_342 , error -> V_93 [ V_25 ] . V_1435 ) ;
F_989 ( V_54 , L_343 , error -> V_93 [ V_25 ] . V_1134 ) ;
}
}
void F_990 ( struct V_1 * V_2 , struct V_1310 * V_1311 )
{
struct V_12 * V_13 ;
F_137 (dev, crtc) {
struct V_488 * V_489 ;
F_270 ( & V_2 -> V_445 ) ;
V_489 = V_13 -> V_446 ;
if ( V_489 && V_489 -> V_490 &&
V_489 -> V_490 -> V_15 . V_1437 == V_1311 ) {
F_212 ( V_489 -> V_490 ) ;
V_489 -> V_490 = NULL ;
}
F_271 ( & V_2 -> V_445 ) ;
}
}
