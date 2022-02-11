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
static const T_2 * F_7 ( struct V_10 * V_11 ,
int V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
const T_2 * V_13 ;
if ( F_8 ( V_11 , V_14 ) ) {
if ( F_9 ( V_2 ) ) {
if ( V_12 == 100000 )
V_13 = & V_15 ;
else
V_13 = & V_16 ;
} else {
if ( V_12 == 100000 )
V_13 = & V_17 ;
else
V_13 = & V_18 ;
}
} else
V_13 = & V_19 ;
return V_13 ;
}
static const T_2 * F_10 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
const T_2 * V_13 ;
if ( F_8 ( V_11 , V_14 ) ) {
if ( F_9 ( V_2 ) )
V_13 = & V_20 ;
else
V_13 = & V_21 ;
} else if ( F_8 ( V_11 , V_22 ) ||
F_8 ( V_11 , V_23 ) ) {
V_13 = & V_24 ;
} else if ( F_8 ( V_11 , V_25 ) ) {
V_13 = & V_26 ;
} else
V_13 = & V_27 ;
return V_13 ;
}
static const T_2 * F_11 ( struct V_10 * V_11 , int V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
const T_2 * V_13 ;
if ( F_3 ( V_2 ) )
V_13 = F_7 ( V_11 , V_12 ) ;
else if ( F_12 ( V_2 ) ) {
V_13 = F_10 ( V_11 ) ;
} else if ( F_13 ( V_2 ) ) {
if ( F_8 ( V_11 , V_14 ) )
V_13 = & V_28 ;
else
V_13 = & V_29 ;
} else if ( F_14 ( V_2 ) ) {
if ( F_8 ( V_11 , V_23 ) )
V_13 = & V_30 ;
else if ( F_8 ( V_11 , V_22 ) )
V_13 = & V_31 ;
else
V_13 = & V_32 ;
} else if ( ! F_15 ( V_2 ) ) {
if ( F_8 ( V_11 , V_14 ) )
V_13 = & V_33 ;
else
V_13 = & V_27 ;
} else {
if ( F_8 ( V_11 , V_14 ) )
V_13 = & V_34 ;
else
V_13 = & V_35 ;
}
return V_13 ;
}
static void F_16 ( int V_12 , T_3 * clock )
{
clock -> V_36 = clock -> V_37 + 2 ;
clock -> V_38 = clock -> V_39 * clock -> V_40 ;
clock -> V_41 = V_12 * clock -> V_36 / clock -> V_42 ;
clock -> V_43 = clock -> V_41 / clock -> V_38 ;
}
static T_4 F_17 ( struct V_44 * V_44 )
{
return 5 * ( V_44 -> V_45 + 2 ) + ( V_44 -> V_37 + 2 ) ;
}
static void F_18 ( int V_12 , T_3 * clock )
{
clock -> V_36 = F_17 ( clock ) ;
clock -> V_38 = clock -> V_39 * clock -> V_40 ;
clock -> V_41 = V_12 * clock -> V_36 / ( clock -> V_42 + 2 ) ;
clock -> V_43 = clock -> V_41 / clock -> V_38 ;
}
bool F_8 ( struct V_10 * V_11 , int type )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_46 * V_47 ;
F_19 (dev, crtc, encoder)
if ( V_47 -> type == type )
return true ;
return false ;
}
static bool F_20 ( struct V_1 * V_2 ,
const T_2 * V_13 ,
const T_3 * clock )
{
if ( clock -> V_39 < V_13 -> V_39 . V_48 || V_13 -> V_39 . V_49 < clock -> V_39 )
F_21 ( L_1 ) ;
if ( clock -> V_38 < V_13 -> V_38 . V_48 || V_13 -> V_38 . V_49 < clock -> V_38 )
F_21 ( L_2 ) ;
if ( clock -> V_37 < V_13 -> V_37 . V_48 || V_13 -> V_37 . V_49 < clock -> V_37 )
F_21 ( L_3 ) ;
if ( clock -> V_45 < V_13 -> V_45 . V_48 || V_13 -> V_45 . V_49 < clock -> V_45 )
F_21 ( L_4 ) ;
if ( clock -> V_45 <= clock -> V_37 && ! F_13 ( V_2 ) )
F_21 ( L_5 ) ;
if ( clock -> V_36 < V_13 -> V_36 . V_48 || V_13 -> V_36 . V_49 < clock -> V_36 )
F_21 ( L_6 ) ;
if ( clock -> V_42 < V_13 -> V_42 . V_48 || V_13 -> V_42 . V_49 < clock -> V_42 )
F_21 ( L_7 ) ;
if ( clock -> V_41 < V_13 -> V_41 . V_48 || V_13 -> V_41 . V_49 < clock -> V_41 )
F_21 ( L_8 ) ;
if ( clock -> V_43 < V_13 -> V_43 . V_48 || V_13 -> V_43 . V_49 < clock -> V_43 )
F_21 ( L_9 ) ;
return true ;
}
static bool
F_22 ( const T_2 * V_13 , struct V_10 * V_11 ,
int V_50 , int V_12 , T_3 * V_51 ,
T_3 * V_52 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 clock ;
int V_53 = V_50 ;
if ( F_8 ( V_11 , V_14 ) ) {
if ( F_9 ( V_2 ) )
clock . V_40 = V_13 -> V_40 . V_54 ;
else
clock . V_40 = V_13 -> V_40 . V_55 ;
} else {
if ( V_50 < V_13 -> V_40 . V_56 )
clock . V_40 = V_13 -> V_40 . V_55 ;
else
clock . V_40 = V_13 -> V_40 . V_54 ;
}
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
for ( clock . V_45 = V_13 -> V_45 . V_48 ; clock . V_45 <= V_13 -> V_45 . V_49 ;
clock . V_45 ++ ) {
for ( clock . V_37 = V_13 -> V_37 . V_48 ;
clock . V_37 <= V_13 -> V_37 . V_49 ; clock . V_37 ++ ) {
if ( clock . V_37 >= clock . V_45 )
break;
for ( clock . V_42 = V_13 -> V_42 . V_48 ;
clock . V_42 <= V_13 -> V_42 . V_49 ; clock . V_42 ++ ) {
for ( clock . V_39 = V_13 -> V_39 . V_48 ;
clock . V_39 <= V_13 -> V_39 . V_49 ; clock . V_39 ++ ) {
int V_57 ;
F_18 ( V_12 , & clock ) ;
if ( ! F_20 ( V_2 , V_13 ,
& clock ) )
continue;
if ( V_51 &&
clock . V_38 != V_51 -> V_38 )
continue;
V_57 = abs ( clock . V_43 - V_50 ) ;
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
F_23 ( const T_2 * V_13 , struct V_10 * V_11 ,
int V_50 , int V_12 , T_3 * V_51 ,
T_3 * V_52 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 clock ;
int V_53 = V_50 ;
if ( F_8 ( V_11 , V_14 ) ) {
if ( F_9 ( V_2 ) )
clock . V_40 = V_13 -> V_40 . V_54 ;
else
clock . V_40 = V_13 -> V_40 . V_55 ;
} else {
if ( V_50 < V_13 -> V_40 . V_56 )
clock . V_40 = V_13 -> V_40 . V_55 ;
else
clock . V_40 = V_13 -> V_40 . V_54 ;
}
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
for ( clock . V_45 = V_13 -> V_45 . V_48 ; clock . V_45 <= V_13 -> V_45 . V_49 ;
clock . V_45 ++ ) {
for ( clock . V_37 = V_13 -> V_37 . V_48 ;
clock . V_37 <= V_13 -> V_37 . V_49 ; clock . V_37 ++ ) {
for ( clock . V_42 = V_13 -> V_42 . V_48 ;
clock . V_42 <= V_13 -> V_42 . V_49 ; clock . V_42 ++ ) {
for ( clock . V_39 = V_13 -> V_39 . V_48 ;
clock . V_39 <= V_13 -> V_39 . V_49 ; clock . V_39 ++ ) {
int V_57 ;
F_16 ( V_12 , & clock ) ;
if ( ! F_20 ( V_2 , V_13 ,
& clock ) )
continue;
if ( V_51 &&
clock . V_38 != V_51 -> V_38 )
continue;
V_57 = abs ( clock . V_43 - V_50 ) ;
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
F_24 ( const T_2 * V_13 , struct V_10 * V_11 ,
int V_50 , int V_12 , T_3 * V_51 ,
T_3 * V_52 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 clock ;
int V_58 ;
bool V_59 ;
int V_60 = ( V_50 >> 8 ) + ( V_50 >> 9 ) ;
V_59 = false ;
if ( F_8 ( V_11 , V_14 ) ) {
if ( F_9 ( V_2 ) )
clock . V_40 = V_13 -> V_40 . V_54 ;
else
clock . V_40 = V_13 -> V_40 . V_55 ;
} else {
if ( V_50 < V_13 -> V_40 . V_56 )
clock . V_40 = V_13 -> V_40 . V_55 ;
else
clock . V_40 = V_13 -> V_40 . V_54 ;
}
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_58 = V_13 -> V_42 . V_49 ;
for ( clock . V_42 = V_13 -> V_42 . V_48 ; clock . V_42 <= V_58 ; clock . V_42 ++ ) {
for ( clock . V_45 = V_13 -> V_45 . V_49 ;
clock . V_45 >= V_13 -> V_45 . V_48 ; clock . V_45 -- ) {
for ( clock . V_37 = V_13 -> V_37 . V_49 ;
clock . V_37 >= V_13 -> V_37 . V_48 ; clock . V_37 -- ) {
for ( clock . V_39 = V_13 -> V_39 . V_49 ;
clock . V_39 >= V_13 -> V_39 . V_48 ; clock . V_39 -- ) {
int V_57 ;
F_18 ( V_12 , & clock ) ;
if ( ! F_20 ( V_2 , V_13 ,
& clock ) )
continue;
V_57 = abs ( clock . V_43 - V_50 ) ;
if ( V_57 < V_60 ) {
* V_52 = clock ;
V_60 = V_57 ;
V_58 = clock . V_42 ;
V_59 = true ;
}
}
}
}
}
return V_59 ;
}
static bool
F_25 ( const T_2 * V_13 , struct V_10 * V_11 ,
int V_50 , int V_12 , T_3 * V_51 ,
T_3 * V_52 )
{
T_1 V_39 , V_40 , V_45 , V_37 , V_41 , V_61 , V_62 , V_63 , V_64 , V_65 ;
T_1 V_36 , V_42 , V_66 ;
T_1 V_67 , V_68 , V_69 , V_38 ;
unsigned long V_70 , V_71 , V_72 ;
int V_73 , V_74 ;
V_74 = 0 ;
V_73 = V_50 * 1000 ;
V_70 = 1000000 ;
V_71 = V_72 = 0 ;
V_66 = V_73 / ( 2 * 100 ) ;
V_67 = 0 ;
V_68 = 19200 ;
V_69 = 1 ;
V_42 = V_38 = V_39 = V_40 = V_36 = V_45 = V_37 = V_41 = V_61 = 0 ;
V_62 = V_63 = V_64 = V_65 = 0 ;
for ( V_42 = V_13 -> V_42 . V_48 ; V_42 <= ( ( V_12 ) / V_68 ) ; V_42 ++ ) {
V_67 = V_12 / V_42 ;
for ( V_39 = V_13 -> V_39 . V_49 ; V_39 > V_13 -> V_39 . V_48 ; V_39 -- ) {
for ( V_40 = V_13 -> V_40 . V_54 + 1 ; V_40 > 0 ; V_40 -- ) {
if ( V_40 > 10 )
V_40 = V_40 - 1 ;
V_38 = V_39 * V_40 ;
for ( V_45 = V_13 -> V_45 . V_48 ; V_45 <= V_13 -> V_45 . V_49 ; V_45 ++ ) {
V_37 = ( ( ( 2 * ( V_66 * V_38 * V_42 / V_45 ) ) +
V_12 ) / ( 2 * V_12 ) ) ;
V_36 = V_45 * V_37 ;
V_41 = V_67 * V_36 ;
if ( V_41 >= V_13 -> V_41 . V_48 && V_41 < V_13 -> V_41 . V_49 ) {
V_71 = 1000000 * ( ( V_41 / V_38 ) - V_66 ) / V_66 ;
V_72 = ( V_71 > 0 ) ? V_71 : ( - V_71 ) ;
if ( V_72 < 100 && ( ( V_39 * V_40 ) > ( V_64 * V_65 ) ) ) {
V_70 = 0 ;
V_74 = 1 ;
}
if ( V_72 < V_70 - 10 ) {
V_70 = V_72 ;
V_74 = 1 ;
}
if ( V_74 ) {
V_61 = V_42 ;
V_62 = V_45 ;
V_63 = V_37 ;
V_64 = V_39 ;
V_65 = V_40 ;
V_74 = 0 ;
}
}
}
}
}
}
V_52 -> V_42 = V_61 ;
V_52 -> V_45 = V_62 ;
V_52 -> V_37 = V_63 ;
V_52 -> V_39 = V_64 ;
V_52 -> V_40 = V_65 ;
return true ;
}
enum V_75 F_26 ( struct V_3 * V_4 ,
enum V_76 V_76 )
{
struct V_10 * V_11 = V_4 -> V_77 [ V_76 ] ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
return V_78 -> V_79 . V_80 ;
}
static void F_28 ( struct V_1 * V_2 , int V_76 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_81 , V_82 = F_29 ( V_76 ) ;
V_81 = F_4 ( V_82 ) ;
if ( F_30 ( F_31 ( V_82 ) != V_81 , 50 ) )
F_32 ( L_10 ) ;
}
void F_33 ( struct V_1 * V_2 , int V_76 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_83 = F_34 ( V_76 ) ;
if ( F_35 ( V_2 ) -> V_84 >= 5 ) {
F_28 ( V_2 , V_76 ) ;
return;
}
F_36 ( V_83 ,
F_4 ( V_83 ) | V_85 ) ;
if ( F_30 ( F_4 ( V_83 ) &
V_85 ,
50 ) )
F_32 ( L_10 ) ;
}
void F_37 ( struct V_1 * V_2 , int V_76 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_75 V_80 = F_26 ( V_4 ,
V_76 ) ;
if ( F_35 ( V_2 ) -> V_84 >= 4 ) {
int V_86 = F_38 ( V_80 ) ;
if ( F_30 ( ( F_4 ( V_86 ) & V_87 ) == 0 ,
100 ) )
F_39 ( 1 , L_11 ) ;
} else {
T_1 V_88 , V_89 ;
int V_86 = F_40 ( V_76 ) ;
unsigned long V_90 = V_91 + F_41 ( 100 ) ;
if ( F_15 ( V_2 ) )
V_89 = V_92 ;
else
V_89 = V_93 ;
do {
V_88 = F_4 ( V_86 ) & V_89 ;
F_42 ( 5 ) ;
} while ( ( ( F_4 ( V_86 ) & V_89 ) != V_88 ) &&
F_43 ( V_90 , V_91 ) );
if ( F_43 ( V_91 , V_90 ) )
F_39 ( 1 , L_11 ) ;
}
}
bool F_44 ( struct V_3 * V_4 ,
struct V_94 * V_95 )
{
T_1 V_96 ;
if ( F_45 ( V_4 -> V_2 ) ) {
switch( V_95 -> V_95 ) {
case V_97 :
V_96 = V_98 ;
break;
case V_99 :
V_96 = V_100 ;
break;
case V_101 :
V_96 = V_102 ;
break;
default:
return true ;
}
} else {
switch( V_95 -> V_95 ) {
case V_97 :
V_96 = V_103 ;
break;
case V_99 :
V_96 = V_104 ;
break;
case V_101 :
V_96 = V_105 ;
break;
default:
return true ;
}
}
return F_4 ( V_106 ) & V_96 ;
}
static const char * F_46 ( bool V_107 )
{
return V_107 ? L_12 : L_13 ;
}
static void F_47 ( struct V_3 * V_4 ,
enum V_76 V_76 , bool V_108 )
{
int V_86 ;
T_1 V_109 ;
bool V_110 ;
V_86 = F_48 ( V_76 ) ;
V_109 = F_4 ( V_86 ) ;
V_110 = ! ! ( V_109 & V_111 ) ;
F_39 ( V_110 != V_108 ,
L_14 ,
F_46 ( V_108 ) , F_46 ( V_110 ) ) ;
}
static struct V_112 *
F_49 ( struct V_78 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_113 . V_2 -> V_5 ;
if ( V_11 -> V_79 . V_114 < 0 )
return NULL ;
return & V_4 -> V_115 [ V_11 -> V_79 . V_114 ] ;
}
static void F_50 ( struct V_3 * V_4 ,
struct V_112 * V_116 ,
bool V_108 )
{
bool V_110 ;
struct V_117 V_118 ;
if ( F_51 ( V_4 -> V_2 ) ) {
F_52 ( L_15 ) ;
return;
}
if ( F_39 ( ! V_116 ,
L_16 , F_46 ( V_108 ) ) )
return;
V_110 = V_116 -> V_119 ( V_4 , V_116 , & V_118 ) ;
F_39 ( V_110 != V_108 ,
L_17 ,
V_116 -> V_120 , F_46 ( V_108 ) , F_46 ( V_110 ) ) ;
}
static void F_53 ( struct V_3 * V_4 ,
enum V_76 V_76 , bool V_108 )
{
int V_86 ;
T_1 V_109 ;
bool V_110 ;
enum V_75 V_80 = F_26 ( V_4 ,
V_76 ) ;
if ( F_54 ( V_4 -> V_2 ) ) {
V_86 = F_55 ( V_80 ) ;
V_109 = F_4 ( V_86 ) ;
V_110 = ! ! ( V_109 & V_121 ) ;
} else {
V_86 = F_56 ( V_76 ) ;
V_109 = F_4 ( V_86 ) ;
V_110 = ! ! ( V_109 & V_122 ) ;
}
F_39 ( V_110 != V_108 ,
L_18 ,
F_46 ( V_108 ) , F_46 ( V_110 ) ) ;
}
static void F_57 ( struct V_3 * V_4 ,
enum V_76 V_76 , bool V_108 )
{
int V_86 ;
T_1 V_109 ;
bool V_110 ;
V_86 = F_58 ( V_76 ) ;
V_109 = F_4 ( V_86 ) ;
V_110 = ! ! ( V_109 & V_123 ) ;
F_39 ( V_110 != V_108 ,
L_19 ,
F_46 ( V_108 ) , F_46 ( V_110 ) ) ;
}
static void F_59 ( struct V_3 * V_4 ,
enum V_76 V_76 )
{
int V_86 ;
T_1 V_109 ;
if ( V_4 -> V_124 -> V_84 == 5 )
return;
if ( F_54 ( V_4 -> V_2 ) )
return;
V_86 = F_56 ( V_76 ) ;
V_109 = F_4 ( V_86 ) ;
F_39 ( ! ( V_109 & V_125 ) , L_20 ) ;
}
static void F_60 ( struct V_3 * V_4 ,
enum V_76 V_76 )
{
int V_86 ;
T_1 V_109 ;
V_86 = F_58 ( V_76 ) ;
V_109 = F_4 ( V_86 ) ;
F_39 ( ! ( V_109 & V_126 ) , L_21 ) ;
}
static void F_61 ( struct V_3 * V_4 ,
enum V_76 V_76 )
{
int V_127 , V_128 ;
T_1 V_109 ;
enum V_76 V_129 = V_130 ;
bool V_131 = true ;
if ( F_3 ( V_4 -> V_2 ) ) {
V_127 = V_132 ;
V_128 = V_133 ;
} else {
V_127 = V_134 ;
V_128 = V_135 ;
}
V_109 = F_4 ( V_127 ) ;
if ( ! ( V_109 & V_136 ) ||
( ( V_109 & V_137 ) == V_137 ) )
V_131 = false ;
if ( F_4 ( V_128 ) & V_138 )
V_129 = V_139 ;
F_39 ( V_129 == V_76 && V_131 ,
L_22 ,
F_62 ( V_76 ) ) ;
}
void F_63 ( struct V_3 * V_4 ,
enum V_76 V_76 , bool V_108 )
{
int V_86 ;
T_1 V_109 ;
bool V_110 ;
enum V_75 V_80 = F_26 ( V_4 ,
V_76 ) ;
if ( V_76 == V_130 && V_4 -> V_140 & V_141 )
V_108 = true ;
if ( ! F_64 ( V_4 -> V_2 ,
F_65 ( V_80 ) ) ) {
V_110 = false ;
} else {
V_86 = F_38 ( V_80 ) ;
V_109 = F_4 ( V_86 ) ;
V_110 = ! ! ( V_109 & V_142 ) ;
}
F_39 ( V_110 != V_108 ,
L_23 ,
F_62 ( V_76 ) , F_46 ( V_108 ) , F_46 ( V_110 ) ) ;
}
static void F_66 ( struct V_3 * V_4 ,
enum V_143 V_143 , bool V_108 )
{
int V_86 ;
T_1 V_109 ;
bool V_110 ;
V_86 = F_67 ( V_143 ) ;
V_109 = F_4 ( V_86 ) ;
V_110 = ! ! ( V_109 & V_144 ) ;
F_39 ( V_110 != V_108 ,
L_24 ,
F_68 ( V_143 ) , F_46 ( V_108 ) , F_46 ( V_110 ) ) ;
}
static void F_69 ( struct V_3 * V_4 ,
enum V_76 V_76 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_86 , V_145 ;
T_1 V_109 ;
int V_146 ;
if ( F_35 ( V_2 ) -> V_84 >= 4 ) {
V_86 = F_67 ( V_76 ) ;
V_109 = F_4 ( V_86 ) ;
F_39 ( ( V_109 & V_144 ) ,
L_25 ,
F_68 ( V_76 ) ) ;
return;
}
for ( V_145 = 0 ; V_145 < F_35 ( V_2 ) -> V_147 ; V_145 ++ ) {
V_86 = F_67 ( V_145 ) ;
V_109 = F_4 ( V_86 ) ;
V_146 = ( V_109 & V_148 ) >>
V_149 ;
F_39 ( ( V_109 & V_144 ) && V_76 == V_146 ,
L_26 ,
F_68 ( V_145 ) , F_62 ( V_76 ) ) ;
}
}
static void F_70 ( struct V_3 * V_4 ,
enum V_76 V_76 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_86 , V_145 ;
T_1 V_109 ;
if ( F_14 ( V_2 ) ) {
for ( V_145 = 0 ; V_145 < V_4 -> V_150 ; V_145 ++ ) {
V_86 = F_71 ( V_76 , V_145 ) ;
V_109 = F_4 ( V_86 ) ;
F_39 ( ( V_109 & V_151 ) ,
L_27 ,
F_72 ( V_76 , V_145 ) , F_62 ( V_76 ) ) ;
}
} else if ( F_35 ( V_2 ) -> V_84 >= 7 ) {
V_86 = F_73 ( V_76 ) ;
V_109 = F_4 ( V_86 ) ;
F_39 ( ( V_109 & V_152 ) ,
L_27 ,
F_68 ( V_76 ) , F_62 ( V_76 ) ) ;
} else if ( F_35 ( V_2 ) -> V_84 >= 5 ) {
V_86 = F_74 ( V_76 ) ;
V_109 = F_4 ( V_86 ) ;
F_39 ( ( V_109 & V_153 ) ,
L_27 ,
F_68 ( V_76 ) , F_62 ( V_76 ) ) ;
}
}
static void F_75 ( struct V_3 * V_4 )
{
T_1 V_109 ;
bool V_107 ;
if ( F_51 ( V_4 -> V_2 ) ) {
F_52 ( L_28 ) ;
return;
}
V_109 = F_4 ( V_154 ) ;
V_107 = ! ! ( V_109 & ( V_155 | V_156 |
V_157 ) ) ;
F_39 ( ! V_107 , L_29 ) ;
}
static void F_76 ( struct V_3 * V_4 ,
enum V_76 V_76 )
{
int V_86 ;
T_1 V_109 ;
bool V_107 ;
V_86 = F_77 ( V_76 ) ;
V_109 = F_4 ( V_86 ) ;
V_107 = ! ! ( V_109 & V_158 ) ;
F_39 ( V_107 ,
L_30 ,
F_62 ( V_76 ) ) ;
}
static bool F_78 ( struct V_3 * V_4 ,
enum V_76 V_76 , T_1 V_159 , T_1 V_109 )
{
if ( ( V_109 & V_160 ) == 0 )
return false ;
if ( F_79 ( V_4 -> V_2 ) ) {
T_1 V_161 = F_80 ( V_76 ) ;
T_1 V_162 = F_4 ( V_161 ) ;
if ( ( V_162 & V_163 ) != V_159 )
return false ;
} else {
if ( ( V_109 & V_164 ) != ( V_76 << 30 ) )
return false ;
}
return true ;
}
static bool F_81 ( struct V_3 * V_4 ,
enum V_76 V_76 , T_1 V_109 )
{
if ( ( V_109 & V_165 ) == 0 )
return false ;
if ( F_79 ( V_4 -> V_2 ) ) {
if ( ( V_109 & V_166 ) != F_82 ( V_76 ) )
return false ;
} else {
if ( ( V_109 & V_167 ) != F_83 ( V_76 ) )
return false ;
}
return true ;
}
static bool F_84 ( struct V_3 * V_4 ,
enum V_76 V_76 , T_1 V_109 )
{
if ( ( V_109 & V_168 ) == 0 )
return false ;
if ( F_79 ( V_4 -> V_2 ) ) {
if ( ( V_109 & V_169 ) != F_85 ( V_76 ) )
return false ;
} else {
if ( ( V_109 & V_170 ) != F_86 ( V_76 ) )
return false ;
}
return true ;
}
static bool F_87 ( struct V_3 * V_4 ,
enum V_76 V_76 , T_1 V_109 )
{
if ( ( V_109 & V_171 ) == 0 )
return false ;
if ( F_79 ( V_4 -> V_2 ) ) {
if ( ( V_109 & V_169 ) != F_85 ( V_76 ) )
return false ;
} else {
if ( ( V_109 & V_172 ) != F_88 ( V_76 ) )
return false ;
}
return true ;
}
static void F_89 ( struct V_3 * V_4 ,
enum V_76 V_76 , int V_86 , T_1 V_159 )
{
T_1 V_109 = F_4 ( V_86 ) ;
F_39 ( F_78 ( V_4 , V_76 , V_159 , V_109 ) ,
L_31 ,
V_86 , F_62 ( V_76 ) ) ;
F_39 ( F_45 ( V_4 -> V_2 ) && ( V_109 & V_160 ) == 0
&& ( V_109 & V_173 ) ,
L_32 ) ;
}
static void F_90 ( struct V_3 * V_4 ,
enum V_76 V_76 , int V_86 )
{
T_1 V_109 = F_4 ( V_86 ) ;
F_39 ( F_81 ( V_4 , V_76 , V_109 ) ,
L_33 ,
V_86 , F_62 ( V_76 ) ) ;
F_39 ( F_45 ( V_4 -> V_2 ) && ( V_109 & V_165 ) == 0
&& ( V_109 & V_174 ) ,
L_34 ) ;
}
static void F_91 ( struct V_3 * V_4 ,
enum V_76 V_76 )
{
int V_86 ;
T_1 V_109 ;
F_89 ( V_4 , V_76 , V_175 , V_176 ) ;
F_89 ( V_4 , V_76 , V_177 , V_178 ) ;
F_89 ( V_4 , V_76 , V_179 , V_180 ) ;
V_86 = V_181 ;
V_109 = F_4 ( V_86 ) ;
F_39 ( F_87 ( V_4 , V_76 , V_109 ) ,
L_35 ,
F_62 ( V_76 ) ) ;
V_86 = V_133 ;
V_109 = F_4 ( V_86 ) ;
F_39 ( F_84 ( V_4 , V_76 , V_109 ) ,
L_36 ,
F_62 ( V_76 ) ) ;
F_90 ( V_4 , V_76 , V_182 ) ;
F_90 ( V_4 , V_76 , V_183 ) ;
F_90 ( V_4 , V_76 , V_184 ) ;
}
static void F_92 ( struct V_3 * V_4 , enum V_76 V_76 )
{
int V_86 ;
T_1 V_109 ;
F_93 ( V_4 , V_76 ) ;
F_94 ( ! F_14 ( V_4 -> V_2 ) && V_4 -> V_124 -> V_84 >= 5 ) ;
if ( F_95 ( V_4 -> V_2 ) && ! F_96 ( V_4 -> V_2 ) )
F_61 ( V_4 , V_76 ) ;
V_86 = F_48 ( V_76 ) ;
V_109 = F_4 ( V_86 ) ;
V_109 |= V_111 ;
F_36 ( V_86 , V_109 ) ;
F_97 ( V_86 ) ;
F_98 ( 150 ) ;
F_36 ( V_86 , V_109 ) ;
F_97 ( V_86 ) ;
F_98 ( 150 ) ;
F_36 ( V_86 , V_109 ) ;
F_97 ( V_86 ) ;
F_98 ( 150 ) ;
}
static void F_99 ( struct V_3 * V_4 , enum V_76 V_76 )
{
int V_86 ;
T_1 V_109 ;
if ( V_76 == V_130 && ( V_4 -> V_140 & V_141 ) )
return;
F_93 ( V_4 , V_76 ) ;
V_86 = F_48 ( V_76 ) ;
V_109 = F_4 ( V_86 ) ;
V_109 &= ~ V_111 ;
F_36 ( V_86 , V_109 ) ;
F_97 ( V_86 ) ;
}
void F_100 ( struct V_3 * V_4 , int V_95 )
{
T_1 V_185 ;
if ( ! V_95 )
V_185 = V_186 ;
else
V_185 = V_187 ;
if ( F_30 ( ( F_4 ( F_48 ( 0 ) ) & V_185 ) == 0 , 1000 ) )
F_39 ( 1 , L_37 ,
'B' + V_95 , F_4 ( F_48 ( 0 ) ) ) ;
}
static void F_101 ( struct V_78 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_113 . V_2 -> V_5 ;
struct V_112 * V_116 = F_49 ( V_11 ) ;
F_94 ( V_4 -> V_124 -> V_84 < 5 ) ;
if ( F_2 ( V_116 == NULL ) )
return;
if ( F_2 ( V_116 -> V_188 == 0 ) )
return;
F_32 ( L_38 ,
V_116 -> V_120 , V_116 -> V_189 , V_116 -> V_190 ,
V_11 -> V_113 . V_113 . V_191 ) ;
if ( V_116 -> V_189 ++ ) {
F_2 ( ! V_116 -> V_190 ) ;
F_102 ( V_4 , V_116 ) ;
return;
}
F_2 ( V_116 -> V_190 ) ;
F_32 ( L_39 , V_116 -> V_120 ) ;
V_116 -> V_192 ( V_4 , V_116 ) ;
V_116 -> V_190 = true ;
}
static void F_103 ( struct V_78 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_113 . V_2 -> V_5 ;
struct V_112 * V_116 = F_49 ( V_11 ) ;
F_94 ( V_4 -> V_124 -> V_84 < 5 ) ;
if ( F_2 ( V_116 == NULL ) )
return;
if ( F_2 ( V_116 -> V_188 == 0 ) )
return;
F_32 ( L_40 ,
V_116 -> V_120 , V_116 -> V_189 , V_116 -> V_190 ,
V_11 -> V_113 . V_113 . V_191 ) ;
if ( F_2 ( V_116 -> V_189 == 0 ) ) {
F_104 ( V_4 , V_116 ) ;
return;
}
F_102 ( V_4 , V_116 ) ;
F_2 ( ! V_116 -> V_190 ) ;
if ( -- V_116 -> V_189 )
return;
F_32 ( L_41 , V_116 -> V_120 ) ;
V_116 -> V_193 ( V_4 , V_116 ) ;
V_116 -> V_190 = false ;
}
static void F_105 ( struct V_3 * V_4 ,
enum V_76 V_76 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_10 * V_11 = V_4 -> V_77 [ V_76 ] ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
T_4 V_86 , V_109 , V_194 ;
F_94 ( V_4 -> V_124 -> V_84 < 5 ) ;
F_102 ( V_4 ,
F_49 ( V_78 ) ) ;
F_106 ( V_4 , V_76 ) ;
F_107 ( V_4 , V_76 ) ;
if ( F_79 ( V_2 ) ) {
V_86 = F_108 ( V_76 ) ;
V_109 = F_4 ( V_86 ) ;
V_109 |= V_195 ;
F_36 ( V_86 , V_109 ) ;
}
V_86 = F_77 ( V_76 ) ;
V_109 = F_4 ( V_86 ) ;
V_194 = F_4 ( F_38 ( V_76 ) ) ;
if ( F_45 ( V_4 -> V_2 ) ) {
V_109 &= ~ V_196 ;
V_109 |= V_194 & V_196 ;
}
V_109 &= ~ V_197 ;
if ( ( V_194 & V_198 ) == V_199 )
if ( F_45 ( V_4 -> V_2 ) &&
F_8 ( V_11 , V_25 ) )
V_109 |= V_200 ;
else
V_109 |= V_201 ;
else
V_109 |= V_202 ;
F_36 ( V_86 , V_109 | V_158 ) ;
if ( F_30 ( F_4 ( V_86 ) & V_203 , 100 ) )
F_109 ( L_42 , F_62 ( V_76 ) ) ;
}
static void F_110 ( struct V_3 * V_4 ,
enum V_75 V_80 )
{
T_1 V_109 , V_194 ;
F_94 ( V_4 -> V_124 -> V_84 < 5 ) ;
F_106 ( V_4 , (enum V_76 ) V_80 ) ;
F_107 ( V_4 , V_204 ) ;
V_109 = F_4 ( V_205 ) ;
V_109 |= V_195 ;
F_36 ( V_205 , V_109 ) ;
V_109 = V_158 ;
V_194 = F_4 ( F_38 ( V_80 ) ) ;
if ( ( V_194 & V_206 ) ==
V_199 )
V_109 |= V_201 ;
else
V_109 |= V_202 ;
F_36 ( V_207 , V_109 ) ;
if ( F_30 ( F_4 ( V_207 ) & V_203 , 100 ) )
F_109 ( L_43 ) ;
}
static void F_111 ( struct V_3 * V_4 ,
enum V_76 V_76 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_86 , V_109 ;
F_112 ( V_4 , V_76 ) ;
F_113 ( V_4 , V_76 ) ;
F_91 ( V_4 , V_76 ) ;
V_86 = F_77 ( V_76 ) ;
V_109 = F_4 ( V_86 ) ;
V_109 &= ~ V_158 ;
F_36 ( V_86 , V_109 ) ;
if ( F_30 ( ( F_4 ( V_86 ) & V_203 ) == 0 , 50 ) )
F_109 ( L_44 , F_62 ( V_76 ) ) ;
if ( ! F_45 ( V_2 ) ) {
V_86 = F_108 ( V_76 ) ;
V_109 = F_4 ( V_86 ) ;
V_109 &= ~ V_195 ;
F_36 ( V_86 , V_109 ) ;
}
}
static void F_114 ( struct V_3 * V_4 )
{
T_1 V_109 ;
V_109 = F_4 ( V_207 ) ;
V_109 &= ~ V_158 ;
F_36 ( V_207 , V_109 ) ;
if ( F_30 ( ( F_4 ( V_207 ) & V_203 ) == 0 , 50 ) )
F_109 ( L_45 ) ;
V_109 = F_4 ( V_205 ) ;
V_109 &= ~ V_195 ;
F_36 ( V_205 , V_109 ) ;
}
static void F_115 ( struct V_3 * V_4 , enum V_76 V_76 ,
bool V_208 )
{
enum V_75 V_80 = F_26 ( V_4 ,
V_76 ) ;
enum V_76 V_209 ;
int V_86 ;
T_1 V_109 ;
F_69 ( V_4 , V_76 ) ;
F_70 ( V_4 , V_76 ) ;
if ( F_51 ( V_4 -> V_2 ) )
V_209 = V_204 ;
else
V_209 = V_76 ;
if ( ! F_3 ( V_4 -> V_2 ) )
F_116 ( V_4 , V_76 ) ;
else {
if ( V_208 ) {
F_60 ( V_4 , V_209 ) ;
F_59 ( V_4 ,
(enum V_76 ) V_80 ) ;
}
}
V_86 = F_38 ( V_80 ) ;
V_109 = F_4 ( V_86 ) ;
if ( V_109 & V_142 )
return;
F_36 ( V_86 , V_109 | V_142 ) ;
F_33 ( V_4 -> V_2 , V_76 ) ;
}
static void F_117 ( struct V_3 * V_4 ,
enum V_76 V_76 )
{
enum V_75 V_80 = F_26 ( V_4 ,
V_76 ) ;
int V_86 ;
T_1 V_109 ;
F_69 ( V_4 , V_76 ) ;
F_70 ( V_4 , V_76 ) ;
if ( V_76 == V_130 && ( V_4 -> V_140 & V_141 ) )
return;
V_86 = F_38 ( V_80 ) ;
V_109 = F_4 ( V_86 ) ;
if ( ( V_109 & V_142 ) == 0 )
return;
F_36 ( V_86 , V_109 & ~ V_142 ) ;
F_37 ( V_4 -> V_2 , V_76 ) ;
}
void F_118 ( struct V_3 * V_4 ,
enum V_143 V_143 )
{
if ( V_4 -> V_124 -> V_84 >= 4 )
F_36 ( F_119 ( V_143 ) , F_4 ( F_119 ( V_143 ) ) ) ;
else
F_36 ( F_120 ( V_143 ) , F_4 ( F_120 ( V_143 ) ) ) ;
}
static void F_121 ( struct V_3 * V_4 ,
enum V_143 V_143 , enum V_76 V_76 )
{
int V_86 ;
T_1 V_109 ;
F_122 ( V_4 , V_76 ) ;
V_86 = F_67 ( V_143 ) ;
V_109 = F_4 ( V_86 ) ;
if ( V_109 & V_144 )
return;
F_36 ( V_86 , V_109 | V_144 ) ;
F_118 ( V_4 , V_143 ) ;
F_33 ( V_4 -> V_2 , V_76 ) ;
}
static void F_123 ( struct V_3 * V_4 ,
enum V_143 V_143 , enum V_76 V_76 )
{
int V_86 ;
T_1 V_109 ;
V_86 = F_67 ( V_143 ) ;
V_109 = F_4 ( V_86 ) ;
if ( ( V_109 & V_144 ) == 0 )
return;
F_36 ( V_86 , V_109 & ~ V_144 ) ;
F_118 ( V_4 , V_143 ) ;
F_33 ( V_4 -> V_2 , V_76 ) ;
}
static bool F_124 ( struct V_1 * V_2 )
{
#ifdef F_125
if ( F_35 ( V_2 ) -> V_84 >= 6 && V_210 )
return true ;
#endif
return false ;
}
int
F_126 ( struct V_1 * V_2 ,
struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_215 ;
int V_216 ;
switch ( V_212 -> V_217 ) {
case V_218 :
if ( F_127 ( V_2 ) || F_128 ( V_2 ) )
V_215 = 128 * 1024 ;
else if ( F_35 ( V_2 ) -> V_84 >= 4 )
V_215 = 4 * 1024 ;
else
V_215 = 64 * 1024 ;
break;
case V_219 :
V_215 = 0 ;
break;
case V_220 :
F_52 ( L_46 ) ;
return - V_221 ;
default:
F_129 () ;
}
if ( F_124 ( V_2 ) && V_215 < 256 * 1024 )
V_215 = 256 * 1024 ;
V_4 -> V_222 . V_223 = false ;
V_216 = F_130 ( V_212 , V_215 , V_214 ) ;
if ( V_216 )
goto V_224;
V_216 = F_131 ( V_212 ) ;
if ( V_216 )
goto V_225;
F_132 ( V_212 ) ;
V_4 -> V_222 . V_223 = true ;
return 0 ;
V_225:
F_133 ( V_212 ) ;
V_224:
V_4 -> V_222 . V_223 = true ;
return V_216 ;
}
void F_134 ( struct V_211 * V_212 )
{
F_135 ( V_212 ) ;
F_133 ( V_212 ) ;
}
unsigned long F_136 ( int * V_226 , int * V_227 ,
unsigned int V_217 ,
unsigned int V_228 ,
unsigned int V_229 )
{
if ( V_217 != V_218 ) {
unsigned int V_230 , V_231 ;
V_230 = * V_227 / 8 ;
* V_227 %= 8 ;
V_231 = * V_226 / ( 512 / V_228 ) ;
* V_226 %= 512 / V_228 ;
return V_230 * V_229 * 8 + V_231 * 4096 ;
} else {
unsigned int V_232 ;
V_232 = * V_227 * V_229 + * V_226 * V_228 ;
* V_227 = 0 ;
* V_226 = ( V_232 & 4095 ) / V_228 ;
return V_232 & - 4096 ;
}
}
static int F_137 ( struct V_10 * V_11 , struct V_233 * V_234 ,
int V_226 , int V_227 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_235 * V_236 ;
struct V_211 * V_212 ;
int V_143 = V_78 -> V_143 ;
unsigned long V_237 ;
T_1 V_238 ;
T_1 V_86 ;
switch ( V_143 ) {
case 0 :
case 1 :
break;
default:
F_109 ( L_47 , F_68 ( V_143 ) ) ;
return - V_221 ;
}
V_236 = F_138 ( V_234 ) ;
V_212 = V_236 -> V_212 ;
V_86 = F_67 ( V_143 ) ;
V_238 = F_4 ( V_86 ) ;
V_238 &= ~ V_239 ;
switch ( V_234 -> V_240 ) {
case V_241 :
V_238 |= V_242 ;
break;
case V_243 :
case V_244 :
V_238 |= V_245 ;
break;
case V_246 :
V_238 |= V_247 ;
break;
case V_248 :
case V_249 :
V_238 |= V_250 ;
break;
case V_251 :
case V_252 :
V_238 |= V_253 ;
break;
case V_254 :
case V_255 :
V_238 |= V_256 ;
break;
case V_257 :
case V_258 :
V_238 |= V_259 ;
break;
default:
F_129 () ;
}
if ( F_35 ( V_2 ) -> V_84 >= 4 ) {
if ( V_212 -> V_217 != V_218 )
V_238 |= V_260 ;
else
V_238 &= ~ V_260 ;
}
if ( F_12 ( V_2 ) )
V_238 |= V_261 ;
F_36 ( V_86 , V_238 ) ;
V_237 = V_227 * V_234 -> V_262 [ 0 ] + V_226 * ( V_234 -> V_263 / 8 ) ;
if ( F_35 ( V_2 ) -> V_84 >= 4 ) {
V_78 -> V_264 =
F_136 ( & V_226 , & V_227 , V_212 -> V_217 ,
V_234 -> V_263 / 8 ,
V_234 -> V_262 [ 0 ] ) ;
V_237 -= V_78 -> V_264 ;
} else {
V_78 -> V_264 = V_237 ;
}
F_32 ( L_48 ,
V_212 -> V_265 , V_237 , V_226 , V_227 , V_234 -> V_262 [ 0 ] ) ;
F_36 ( F_139 ( V_143 ) , V_234 -> V_262 [ 0 ] ) ;
if ( F_35 ( V_2 ) -> V_84 >= 4 ) {
F_140 ( F_119 ( V_143 ) ,
V_212 -> V_265 + V_78 -> V_264 ) ;
F_36 ( F_141 ( V_143 ) , ( V_227 << 16 ) | V_226 ) ;
F_36 ( F_142 ( V_143 ) , V_237 ) ;
} else
F_36 ( F_120 ( V_143 ) , V_212 -> V_265 + V_237 ) ;
F_97 ( V_86 ) ;
return 0 ;
}
static int F_143 ( struct V_10 * V_11 ,
struct V_233 * V_234 , int V_226 , int V_227 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_235 * V_236 ;
struct V_211 * V_212 ;
int V_143 = V_78 -> V_143 ;
unsigned long V_237 ;
T_1 V_238 ;
T_1 V_86 ;
switch ( V_143 ) {
case 0 :
case 1 :
case 2 :
break;
default:
F_109 ( L_47 , F_68 ( V_143 ) ) ;
return - V_221 ;
}
V_236 = F_138 ( V_234 ) ;
V_212 = V_236 -> V_212 ;
V_86 = F_67 ( V_143 ) ;
V_238 = F_4 ( V_86 ) ;
V_238 &= ~ V_239 ;
switch ( V_234 -> V_240 ) {
case V_241 :
V_238 |= V_242 ;
break;
case V_246 :
V_238 |= V_247 ;
break;
case V_248 :
case V_249 :
V_238 |= V_250 ;
break;
case V_251 :
case V_252 :
V_238 |= V_253 ;
break;
case V_254 :
case V_255 :
V_238 |= V_256 ;
break;
case V_257 :
case V_258 :
V_238 |= V_259 ;
break;
default:
F_129 () ;
}
if ( V_212 -> V_217 != V_218 )
V_238 |= V_260 ;
else
V_238 &= ~ V_260 ;
V_238 |= V_261 ;
F_36 ( V_86 , V_238 ) ;
V_237 = V_227 * V_234 -> V_262 [ 0 ] + V_226 * ( V_234 -> V_263 / 8 ) ;
V_78 -> V_264 =
F_136 ( & V_226 , & V_227 , V_212 -> V_217 ,
V_234 -> V_263 / 8 ,
V_234 -> V_262 [ 0 ] ) ;
V_237 -= V_78 -> V_264 ;
F_32 ( L_48 ,
V_212 -> V_265 , V_237 , V_226 , V_227 , V_234 -> V_262 [ 0 ] ) ;
F_36 ( F_139 ( V_143 ) , V_234 -> V_262 [ 0 ] ) ;
F_140 ( F_119 ( V_143 ) ,
V_212 -> V_265 + V_78 -> V_264 ) ;
if ( F_144 ( V_2 ) ) {
F_36 ( F_145 ( V_143 ) , ( V_227 << 16 ) | V_226 ) ;
} else {
F_36 ( F_141 ( V_143 ) , ( V_227 << 16 ) | V_226 ) ;
F_36 ( F_142 ( V_143 ) , V_237 ) ;
}
F_97 ( V_86 ) ;
return 0 ;
}
static int
F_146 ( struct V_10 * V_11 , struct V_233 * V_234 ,
int V_226 , int V_227 , enum V_266 V_108 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_267 . V_268 )
V_4 -> V_267 . V_268 ( V_2 ) ;
F_147 ( V_11 ) ;
return V_4 -> V_267 . V_269 ( V_11 , V_234 , V_226 , V_227 ) ;
}
void F_148 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_11 ;
F_149 (crtc, &dev->mode_config.crtc_list, head) {
struct V_78 * V_78 = F_27 ( V_11 ) ;
enum V_143 V_143 = V_78 -> V_143 ;
F_150 ( V_2 , V_143 ) ;
F_151 ( V_2 , V_143 ) ;
}
F_149 (crtc, &dev->mode_config.crtc_list, head) {
struct V_78 * V_78 = F_27 ( V_11 ) ;
F_152 ( & V_11 -> V_270 ) ;
if ( V_78 -> V_189 )
V_4 -> V_267 . V_269 ( V_11 , V_11 -> V_234 ,
V_11 -> V_226 , V_11 -> V_227 ) ;
F_153 ( & V_11 -> V_270 ) ;
}
}
static int
F_154 ( struct V_233 * V_271 )
{
struct V_211 * V_212 = F_138 ( V_271 ) -> V_212 ;
struct V_3 * V_4 = V_212 -> V_113 . V_2 -> V_5 ;
bool V_272 = V_4 -> V_222 . V_223 ;
int V_216 ;
V_4 -> V_222 . V_223 = false ;
V_216 = F_155 ( V_212 ) ;
V_4 -> V_222 . V_223 = V_272 ;
return V_216 ;
}
static void F_156 ( struct V_10 * V_11 , int V_226 , int V_227 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_273 * V_274 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
if ( ! V_2 -> V_275 -> V_276 )
return;
V_274 = V_2 -> V_275 -> V_276 -> V_277 ;
if ( ! V_274 -> V_278 )
return;
switch ( V_78 -> V_76 ) {
case 0 :
V_274 -> V_278 -> V_279 = V_226 ;
V_274 -> V_278 -> V_280 = V_227 ;
break;
case 1 :
V_274 -> V_278 -> V_281 = V_226 ;
V_274 -> V_278 -> V_282 = V_227 ;
break;
default:
break;
}
}
static int
F_157 ( struct V_10 * V_11 , int V_226 , int V_227 ,
struct V_233 * V_234 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_233 * V_271 ;
int V_216 ;
if ( ! V_234 ) {
F_109 ( L_49 ) ;
return 0 ;
}
if ( V_78 -> V_143 > F_35 ( V_2 ) -> V_147 ) {
F_109 ( L_50 ,
F_68 ( V_78 -> V_143 ) ,
F_35 ( V_2 ) -> V_147 ) ;
return - V_221 ;
}
F_152 ( & V_2 -> V_283 ) ;
V_216 = F_126 ( V_2 ,
F_138 ( V_234 ) -> V_212 ,
NULL ) ;
if ( V_216 != 0 ) {
F_153 ( & V_2 -> V_283 ) ;
F_109 ( L_51 ) ;
return V_216 ;
}
V_216 = V_4 -> V_267 . V_269 ( V_11 , V_234 , V_226 , V_227 ) ;
if ( V_216 ) {
F_134 ( F_138 ( V_234 ) -> V_212 ) ;
F_153 ( & V_2 -> V_283 ) ;
F_109 ( L_52 ) ;
return V_216 ;
}
V_271 = V_11 -> V_234 ;
V_11 -> V_234 = V_234 ;
V_11 -> V_226 = V_226 ;
V_11 -> V_227 = V_227 ;
if ( V_271 ) {
if ( V_78 -> V_189 && V_271 != V_234 )
F_33 ( V_2 , V_78 -> V_76 ) ;
F_134 ( F_138 ( V_271 ) -> V_212 ) ;
}
F_158 ( V_2 ) ;
F_153 ( & V_2 -> V_283 ) ;
F_156 ( V_11 , V_226 , V_227 ) ;
return 0 ;
}
static void F_159 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_76 = V_78 -> V_76 ;
T_1 V_86 , V_284 ;
V_86 = F_56 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
if ( F_160 ( V_2 ) ) {
V_284 &= ~ V_285 ;
V_284 |= V_285 | V_286 ;
} else {
V_284 &= ~ V_287 ;
V_284 |= V_287 | V_286 ;
}
F_36 ( V_86 , V_284 ) ;
V_86 = F_58 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
if ( F_79 ( V_2 ) ) {
V_284 &= ~ V_288 ;
V_284 |= V_289 ;
} else {
V_284 &= ~ V_287 ;
V_284 |= V_287 ;
}
F_36 ( V_86 , V_284 | V_290 ) ;
F_97 ( V_86 ) ;
F_98 ( 1000 ) ;
if ( F_160 ( V_2 ) )
F_36 ( V_86 , F_4 ( V_86 ) | V_291 |
V_292 ) ;
}
static bool F_161 ( struct V_78 * V_78 )
{
return V_78 -> V_113 . V_107 && V_78 -> V_79 . V_293 ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_294 =
F_27 ( V_4 -> V_77 [ V_139 ] ) ;
struct V_78 * V_295 =
F_27 ( V_4 -> V_77 [ V_296 ] ) ;
T_4 V_284 ;
if ( ! F_161 ( V_294 ) &&
! F_161 ( V_295 ) ) {
F_2 ( F_4 ( F_58 ( V_139 ) ) & V_123 ) ;
F_2 ( F_4 ( F_58 ( V_296 ) ) & V_123 ) ;
V_284 = F_4 ( V_297 ) ;
V_284 &= ~ V_298 ;
F_32 ( L_53 ) ;
F_36 ( V_297 , V_284 ) ;
}
}
static void F_163 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_76 = V_78 -> V_76 ;
int V_143 = V_78 -> V_143 ;
T_1 V_86 , V_284 , V_299 ;
F_122 ( V_4 , V_76 ) ;
F_164 ( V_4 , V_143 ) ;
V_86 = F_165 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_300 ;
V_284 &= ~ V_301 ;
F_36 ( V_86 , V_284 ) ;
F_4 ( V_86 ) ;
F_98 ( 150 ) ;
V_86 = F_56 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_302 ;
V_284 |= F_166 ( V_78 -> V_79 . V_303 ) ;
V_284 &= ~ V_287 ;
V_284 |= V_304 ;
F_36 ( V_86 , V_284 | V_122 ) ;
V_86 = F_58 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_287 ;
V_284 |= V_304 ;
F_36 ( V_86 , V_284 | V_123 ) ;
F_97 ( V_86 ) ;
F_98 ( 150 ) ;
F_36 ( F_167 ( V_76 ) , V_305 ) ;
F_36 ( F_167 ( V_76 ) , V_305 |
V_306 ) ;
V_86 = F_168 ( V_76 ) ;
for ( V_299 = 0 ; V_299 < 5 ; V_299 ++ ) {
V_284 = F_4 ( V_86 ) ;
F_32 ( L_54 , V_284 ) ;
if ( ( V_284 & V_301 ) ) {
F_32 ( L_55 ) ;
F_36 ( V_86 , V_284 | V_301 ) ;
break;
}
}
if ( V_299 == 5 )
F_109 ( L_56 ) ;
V_86 = F_56 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_287 ;
V_284 |= V_307 ;
F_36 ( V_86 , V_284 ) ;
V_86 = F_58 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_287 ;
V_284 |= V_307 ;
F_36 ( V_86 , V_284 ) ;
F_97 ( V_86 ) ;
F_98 ( 150 ) ;
V_86 = F_168 ( V_76 ) ;
for ( V_299 = 0 ; V_299 < 5 ; V_299 ++ ) {
V_284 = F_4 ( V_86 ) ;
F_32 ( L_54 , V_284 ) ;
if ( V_284 & V_300 ) {
F_36 ( V_86 , V_284 | V_300 ) ;
F_32 ( L_57 ) ;
break;
}
}
if ( V_299 == 5 )
F_109 ( L_58 ) ;
F_32 ( L_59 ) ;
}
static void F_169 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_76 = V_78 -> V_76 ;
T_1 V_86 , V_284 , V_145 , V_308 ;
V_86 = F_165 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_300 ;
V_284 &= ~ V_301 ;
F_36 ( V_86 , V_284 ) ;
F_97 ( V_86 ) ;
F_98 ( 150 ) ;
V_86 = F_56 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_302 ;
V_284 |= F_166 ( V_78 -> V_79 . V_303 ) ;
V_284 &= ~ V_287 ;
V_284 |= V_304 ;
V_284 &= ~ V_309 ;
V_284 |= V_310 ;
F_36 ( V_86 , V_284 | V_122 ) ;
F_36 ( F_170 ( V_76 ) ,
V_311 | V_312 ) ;
V_86 = F_58 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
if ( F_79 ( V_2 ) ) {
V_284 &= ~ V_288 ;
V_284 |= V_313 ;
} else {
V_284 &= ~ V_287 ;
V_284 |= V_304 ;
}
F_36 ( V_86 , V_284 | V_123 ) ;
F_97 ( V_86 ) ;
F_98 ( 150 ) ;
for ( V_145 = 0 ; V_145 < 4 ; V_145 ++ ) {
V_86 = F_56 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_309 ;
V_284 |= V_314 [ V_145 ] ;
F_36 ( V_86 , V_284 ) ;
F_97 ( V_86 ) ;
F_98 ( 500 ) ;
for ( V_308 = 0 ; V_308 < 5 ; V_308 ++ ) {
V_86 = F_168 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
F_32 ( L_54 , V_284 ) ;
if ( V_284 & V_301 ) {
F_36 ( V_86 , V_284 | V_301 ) ;
F_32 ( L_55 ) ;
break;
}
F_98 ( 50 ) ;
}
if ( V_308 < 5 )
break;
}
if ( V_145 == 4 )
F_109 ( L_56 ) ;
V_86 = F_56 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_287 ;
V_284 |= V_307 ;
if ( F_171 ( V_2 ) ) {
V_284 &= ~ V_309 ;
V_284 |= V_310 ;
}
F_36 ( V_86 , V_284 ) ;
V_86 = F_58 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
if ( F_79 ( V_2 ) ) {
V_284 &= ~ V_288 ;
V_284 |= V_315 ;
} else {
V_284 &= ~ V_287 ;
V_284 |= V_307 ;
}
F_36 ( V_86 , V_284 ) ;
F_97 ( V_86 ) ;
F_98 ( 150 ) ;
for ( V_145 = 0 ; V_145 < 4 ; V_145 ++ ) {
V_86 = F_56 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_309 ;
V_284 |= V_314 [ V_145 ] ;
F_36 ( V_86 , V_284 ) ;
F_97 ( V_86 ) ;
F_98 ( 500 ) ;
for ( V_308 = 0 ; V_308 < 5 ; V_308 ++ ) {
V_86 = F_168 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
F_32 ( L_54 , V_284 ) ;
if ( V_284 & V_300 ) {
F_36 ( V_86 , V_284 | V_300 ) ;
F_32 ( L_57 ) ;
break;
}
F_98 ( 50 ) ;
}
if ( V_308 < 5 )
break;
}
if ( V_145 == 4 )
F_109 ( L_58 ) ;
F_32 ( L_60 ) ;
}
static void F_172 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_76 = V_78 -> V_76 ;
T_1 V_86 , V_284 , V_145 ;
V_86 = F_165 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_300 ;
V_284 &= ~ V_301 ;
F_36 ( V_86 , V_284 ) ;
F_97 ( V_86 ) ;
F_98 ( 150 ) ;
F_32 ( L_61 ,
F_4 ( F_168 ( V_76 ) ) ) ;
V_86 = F_56 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_302 ;
V_284 |= F_166 ( V_78 -> V_79 . V_303 ) ;
V_284 &= ~ ( V_316 | V_285 ) ;
V_284 |= V_317 ;
V_284 &= ~ V_309 ;
V_284 |= V_310 ;
V_284 |= V_318 ;
F_36 ( V_86 , V_284 | V_122 ) ;
F_36 ( F_170 ( V_76 ) ,
V_311 | V_312 ) ;
V_86 = F_58 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_316 ;
V_284 &= ~ V_288 ;
V_284 |= V_313 ;
V_284 |= V_318 ;
F_36 ( V_86 , V_284 | V_123 ) ;
F_97 ( V_86 ) ;
F_98 ( 150 ) ;
for ( V_145 = 0 ; V_145 < 4 ; V_145 ++ ) {
V_86 = F_56 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_309 ;
V_284 |= V_314 [ V_145 ] ;
F_36 ( V_86 , V_284 ) ;
F_97 ( V_86 ) ;
F_98 ( 500 ) ;
V_86 = F_168 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
F_32 ( L_54 , V_284 ) ;
if ( V_284 & V_301 ||
( F_4 ( V_86 ) & V_301 ) ) {
F_36 ( V_86 , V_284 | V_301 ) ;
F_32 ( L_62 , V_145 ) ;
break;
}
}
if ( V_145 == 4 )
F_109 ( L_56 ) ;
V_86 = F_56 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_285 ;
V_284 |= V_319 ;
V_284 &= ~ V_309 ;
V_284 |= V_310 ;
F_36 ( V_86 , V_284 ) ;
V_86 = F_58 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_288 ;
V_284 |= V_315 ;
F_36 ( V_86 , V_284 ) ;
F_97 ( V_86 ) ;
F_98 ( 150 ) ;
for ( V_145 = 0 ; V_145 < 4 ; V_145 ++ ) {
V_86 = F_56 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_309 ;
V_284 |= V_314 [ V_145 ] ;
F_36 ( V_86 , V_284 ) ;
F_97 ( V_86 ) ;
F_98 ( 500 ) ;
V_86 = F_168 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
F_32 ( L_54 , V_284 ) ;
if ( V_284 & V_300 ) {
F_36 ( V_86 , V_284 | V_300 ) ;
F_32 ( L_63 , V_145 ) ;
break;
}
}
if ( V_145 == 4 )
F_109 ( L_58 ) ;
F_32 ( L_60 ) ;
}
static void F_173 ( struct V_78 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_76 = V_78 -> V_76 ;
T_1 V_86 , V_284 ;
V_86 = F_58 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ ( V_302 | ( 0x7 << 16 ) ) ;
V_284 |= F_166 ( V_78 -> V_79 . V_303 ) ;
V_284 |= ( F_4 ( F_38 ( V_76 ) ) & V_196 ) << 11 ;
F_36 ( V_86 , V_284 | V_126 ) ;
F_97 ( V_86 ) ;
F_98 ( 200 ) ;
V_284 = F_4 ( V_86 ) ;
F_36 ( V_86 , V_284 | V_320 ) ;
F_97 ( V_86 ) ;
F_98 ( 200 ) ;
V_86 = F_56 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
if ( ( V_284 & V_125 ) == 0 ) {
F_36 ( V_86 , V_284 | V_125 ) ;
F_97 ( V_86 ) ;
F_98 ( 100 ) ;
}
}
static void F_174 ( struct V_78 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_76 = V_78 -> V_76 ;
T_1 V_86 , V_284 ;
V_86 = F_58 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
F_36 ( V_86 , V_284 & ~ V_320 ) ;
V_86 = F_56 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
F_36 ( V_86 , V_284 & ~ V_125 ) ;
F_97 ( V_86 ) ;
F_98 ( 100 ) ;
V_86 = F_58 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
F_36 ( V_86 , V_284 & ~ V_126 ) ;
F_97 ( V_86 ) ;
F_98 ( 100 ) ;
}
static void F_175 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_76 = V_78 -> V_76 ;
T_1 V_86 , V_284 ;
V_86 = F_56 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
F_36 ( V_86 , V_284 & ~ V_122 ) ;
F_97 ( V_86 ) ;
V_86 = F_58 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ ( 0x7 << 16 ) ;
V_284 |= ( F_4 ( F_38 ( V_76 ) ) & V_196 ) << 11 ;
F_36 ( V_86 , V_284 & ~ V_123 ) ;
F_97 ( V_86 ) ;
F_98 ( 100 ) ;
if ( F_45 ( V_2 ) ) {
F_36 ( F_167 ( V_76 ) , V_305 ) ;
}
V_86 = F_56 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ V_287 ;
V_284 |= V_304 ;
F_36 ( V_86 , V_284 ) ;
V_86 = F_58 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
if ( F_79 ( V_2 ) ) {
V_284 &= ~ V_288 ;
V_284 |= V_313 ;
} else {
V_284 &= ~ V_287 ;
V_284 |= V_304 ;
}
V_284 &= ~ ( 0x07 << 16 ) ;
V_284 |= ( F_4 ( F_38 ( V_76 ) ) & V_196 ) << 11 ;
F_36 ( V_86 , V_284 ) ;
F_97 ( V_86 ) ;
F_98 ( 100 ) ;
}
static bool F_176 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
unsigned long V_321 ;
bool V_322 ;
if ( F_177 ( & V_4 -> V_323 ) ||
V_78 -> V_324 != F_178 ( & V_4 -> V_323 . V_324 ) )
return false ;
F_179 ( & V_2 -> V_325 , V_321 ) ;
V_322 = F_27 ( V_11 ) -> V_326 != NULL ;
F_180 ( & V_2 -> V_325 , V_321 ) ;
return V_322 ;
}
static void F_181 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_11 -> V_234 == NULL )
return;
F_2 ( F_182 ( & V_4 -> V_327 ) ) ;
F_183 ( V_4 -> V_327 ,
! F_176 ( V_11 ) ) ;
F_152 ( & V_2 -> V_283 ) ;
F_154 ( V_11 -> V_234 ) ;
F_153 ( & V_2 -> V_283 ) ;
}
static void F_184 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_328 , V_329 , V_330 , V_331 = 0 ;
T_1 V_284 ;
F_152 ( & V_4 -> V_332 ) ;
F_36 ( V_333 , V_334 ) ;
F_185 ( V_4 , V_335 ,
F_186 ( V_4 , V_335 , V_336 ) |
V_337 ,
V_336 ) ;
if ( V_11 -> V_338 . clock == 20000 ) {
V_330 = 1 ;
V_328 = 0x41 ;
V_329 = 0x20 ;
} else {
T_1 V_339 = 172800 * 1000 ;
T_1 V_340 = 64 ;
T_1 V_341 , V_342 , V_343 ;
V_341 = ( V_339 / V_11 -> V_338 . clock ) ;
V_342 = V_341 / V_340 ;
V_343 = V_341 % V_340 ;
V_330 = 0 ;
V_328 = V_342 - 2 ;
V_329 = V_343 ;
}
F_2 ( F_187 ( V_328 ) &
~ V_344 ) ;
F_2 ( F_188 ( V_331 ) &
~ V_345 ) ;
F_32 ( L_64 ,
V_11 -> V_338 . clock ,
V_330 ,
V_328 ,
V_331 ,
V_329 ) ;
V_284 = F_186 ( V_4 , V_346 , V_336 ) ;
V_284 &= ~ V_344 ;
V_284 |= F_187 ( V_328 ) ;
V_284 &= ~ V_345 ;
V_284 |= F_189 ( V_329 ) ;
V_284 |= F_188 ( V_331 ) ;
V_284 |= V_347 ;
F_185 ( V_4 , V_346 , V_284 , V_336 ) ;
V_284 = F_186 ( V_4 , V_348 , V_336 ) ;
V_284 &= ~ F_190 ( 1 ) ;
V_284 |= F_190 ( V_330 ) ;
F_185 ( V_4 , V_348 , V_284 , V_336 ) ;
V_284 = F_186 ( V_4 , V_335 , V_336 ) ;
V_284 &= ~ V_337 ;
F_185 ( V_4 , V_335 , V_284 , V_336 ) ;
F_98 ( 24 ) ;
F_36 ( V_333 , V_349 ) ;
F_153 ( & V_4 -> V_332 ) ;
}
static void F_191 ( struct V_78 * V_11 ,
enum V_76 V_209 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_75 V_80 = V_11 -> V_79 . V_80 ;
F_36 ( F_192 ( V_209 ) ,
F_4 ( F_193 ( V_80 ) ) ) ;
F_36 ( F_194 ( V_209 ) ,
F_4 ( F_195 ( V_80 ) ) ) ;
F_36 ( F_196 ( V_209 ) ,
F_4 ( F_197 ( V_80 ) ) ) ;
F_36 ( F_198 ( V_209 ) ,
F_4 ( F_199 ( V_80 ) ) ) ;
F_36 ( F_200 ( V_209 ) ,
F_4 ( F_201 ( V_80 ) ) ) ;
F_36 ( F_202 ( V_209 ) ,
F_4 ( F_203 ( V_80 ) ) ) ;
F_36 ( F_204 ( V_209 ) ,
F_4 ( F_205 ( V_80 ) ) ) ;
}
static void F_206 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_76 = V_78 -> V_76 ;
T_1 V_86 , V_284 ;
F_76 ( V_4 , V_76 ) ;
F_36 ( F_207 ( V_76 ) ,
F_4 ( F_208 ( V_76 ) ) & V_350 ) ;
V_4 -> V_267 . V_351 ( V_11 ) ;
F_101 ( V_78 ) ;
if ( F_79 ( V_2 ) ) {
T_1 V_352 ;
V_284 = F_4 ( V_353 ) ;
V_284 |= F_209 ( V_76 ) ;
V_352 = F_210 ( V_76 ) ;
if ( V_78 -> V_79 . V_114 == V_354 )
V_284 |= V_352 ;
else
V_284 &= ~ V_352 ;
F_36 ( V_353 , V_284 ) ;
}
F_61 ( V_4 , V_76 ) ;
F_191 ( V_78 , V_76 ) ;
F_159 ( V_11 ) ;
if ( F_79 ( V_2 ) &&
( F_8 ( V_11 , V_355 ) ||
F_8 ( V_11 , V_356 ) ) ) {
T_1 V_357 = ( F_4 ( F_38 ( V_76 ) ) & V_196 ) >> 5 ;
V_86 = F_80 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ ( V_163 |
V_358 |
V_359 ) ;
V_284 |= ( V_360 |
V_361 ) ;
V_284 |= V_357 << 9 ;
if ( V_11 -> V_338 . V_321 & V_362 )
V_284 |= V_363 ;
if ( V_11 -> V_338 . V_321 & V_364 )
V_284 |= V_365 ;
switch ( F_211 ( V_11 ) ) {
case V_175 :
V_284 |= V_176 ;
break;
case V_177 :
V_284 |= V_178 ;
break;
case V_179 :
V_284 |= V_180 ;
break;
default:
F_129 () ;
}
F_36 ( V_86 , V_284 ) ;
}
F_105 ( V_4 , V_76 ) ;
}
static void F_212 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
enum V_75 V_80 = V_78 -> V_79 . V_80 ;
F_76 ( V_4 , V_204 ) ;
F_184 ( V_11 ) ;
F_191 ( V_78 , V_130 ) ;
F_110 ( V_4 , V_80 ) ;
}
static void F_213 ( struct V_78 * V_11 )
{
struct V_112 * V_116 = F_49 ( V_11 ) ;
if ( V_116 == NULL )
return;
if ( V_116 -> V_188 == 0 ) {
F_39 ( 1 , L_65 , V_116 -> V_120 ) ;
return;
}
if ( -- V_116 -> V_188 == 0 ) {
F_2 ( V_116 -> V_190 ) ;
F_2 ( V_116 -> V_189 ) ;
}
V_11 -> V_79 . V_114 = V_366 ;
}
static struct V_112 * F_214 ( struct V_78 * V_11 , T_1 V_44 , T_1 V_367 )
{
struct V_3 * V_4 = V_11 -> V_113 . V_2 -> V_5 ;
struct V_112 * V_116 = F_49 ( V_11 ) ;
enum V_368 V_145 ;
if ( V_116 ) {
F_32 ( L_66 ,
V_11 -> V_113 . V_113 . V_191 , V_116 -> V_120 ) ;
F_213 ( V_11 ) ;
}
if ( F_45 ( V_4 -> V_2 ) ) {
V_145 = V_11 -> V_76 ;
V_116 = & V_4 -> V_115 [ V_145 ] ;
F_32 ( L_67 ,
V_11 -> V_113 . V_113 . V_191 , V_116 -> V_120 ) ;
goto V_59;
}
for ( V_145 = 0 ; V_145 < V_4 -> V_369 ; V_145 ++ ) {
V_116 = & V_4 -> V_115 [ V_145 ] ;
if ( V_116 -> V_188 == 0 )
continue;
if ( V_44 == ( F_4 ( F_215 ( V_116 -> V_191 ) ) & 0x7fffffff ) &&
V_367 == F_4 ( F_216 ( V_116 -> V_191 ) ) ) {
F_32 ( L_68 ,
V_11 -> V_113 . V_113 . V_191 ,
V_116 -> V_120 , V_116 -> V_188 , V_116 -> V_189 ) ;
goto V_59;
}
}
for ( V_145 = 0 ; V_145 < V_4 -> V_369 ; V_145 ++ ) {
V_116 = & V_4 -> V_115 [ V_145 ] ;
if ( V_116 -> V_188 == 0 ) {
F_32 ( L_69 ,
V_11 -> V_113 . V_113 . V_191 , V_116 -> V_120 ) ;
goto V_59;
}
}
return NULL ;
V_59:
V_11 -> V_79 . V_114 = V_145 ;
F_52 ( L_70 , V_116 -> V_120 ,
F_62 ( V_11 -> V_76 ) ) ;
if ( V_116 -> V_189 == 0 ) {
memcpy ( & V_116 -> V_118 , & V_11 -> V_79 . V_370 ,
sizeof( V_116 -> V_118 ) ) ;
F_52 ( L_71 , V_116 -> V_120 ) ;
F_2 ( V_116 -> V_190 ) ;
F_104 ( V_4 , V_116 ) ;
F_36 ( F_215 ( V_116 -> V_191 ) , V_44 & ~ V_111 ) ;
F_97 ( F_215 ( V_116 -> V_191 ) ) ;
F_98 ( 150 ) ;
F_36 ( F_216 ( V_116 -> V_191 ) , V_367 ) ;
F_36 ( F_215 ( V_116 -> V_191 ) , V_44 & ~ V_111 ) ;
}
V_116 -> V_188 ++ ;
return V_116 ;
}
static void F_217 ( struct V_1 * V_2 , int V_76 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_371 = F_40 ( V_76 ) ;
T_1 V_284 ;
V_284 = F_4 ( V_371 ) ;
F_98 ( 500 ) ;
if ( F_30 ( F_4 ( V_371 ) != V_284 , 5 ) ) {
if ( F_30 ( F_4 ( V_371 ) != V_284 , 5 ) )
F_109 ( L_72 , F_62 ( V_76 ) ) ;
}
}
static void F_218 ( struct V_78 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_76 = V_11 -> V_76 ;
if ( V_11 -> V_79 . V_372 . V_373 ) {
if ( F_160 ( V_2 ) || F_144 ( V_2 ) )
F_36 ( F_219 ( V_76 ) , V_374 | V_375 |
F_220 ( V_76 ) ) ;
else
F_36 ( F_219 ( V_76 ) , V_374 | V_375 ) ;
F_36 ( F_221 ( V_76 ) , V_11 -> V_79 . V_372 . V_376 ) ;
F_36 ( F_222 ( V_76 ) , V_11 -> V_79 . V_372 . V_373 ) ;
}
}
static void F_223 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
enum V_76 V_76 = F_27 ( V_11 ) -> V_76 ;
struct V_377 * V_377 ;
F_149 (intel_plane, &dev->mode_config.plane_list, base.head)
if ( V_377 -> V_76 == V_76 )
F_224 ( & V_377 -> V_113 ) ;
}
static void F_225 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
enum V_76 V_76 = F_27 ( V_11 ) -> V_76 ;
struct V_377 * V_377 ;
F_149 (intel_plane, &dev->mode_config.plane_list, base.head)
if ( V_377 -> V_76 == V_76 )
F_226 ( & V_377 -> V_113 ) ;
}
static void F_227 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_46 * V_47 ;
int V_76 = V_78 -> V_76 ;
int V_143 = V_78 -> V_143 ;
T_1 V_284 ;
F_2 ( ! V_11 -> V_107 ) ;
if ( V_78 -> V_189 )
return;
V_78 -> V_189 = true ;
F_228 ( V_2 , V_76 , true ) ;
F_229 ( V_2 , V_76 , true ) ;
F_230 ( V_2 ) ;
if ( F_8 ( V_11 , V_14 ) ) {
V_284 = F_4 ( V_133 ) ;
if ( ( V_284 & V_168 ) == 0 )
F_36 ( V_133 , V_284 | V_168 ) ;
}
if ( V_78 -> V_79 . V_293 ) {
F_173 ( V_78 ) ;
} else {
F_112 ( V_4 , V_76 ) ;
F_113 ( V_4 , V_76 ) ;
}
F_19 (dev, crtc, encoder)
if ( V_47 -> V_378 )
V_47 -> V_378 ( V_47 ) ;
F_218 ( V_78 ) ;
F_231 ( V_11 ) ;
F_115 ( V_4 , V_76 ,
V_78 -> V_79 . V_293 ) ;
F_121 ( V_4 , V_143 , V_76 ) ;
F_223 ( V_11 ) ;
F_232 ( V_11 , true ) ;
if ( V_78 -> V_79 . V_293 )
F_206 ( V_11 ) ;
F_152 ( & V_2 -> V_283 ) ;
F_158 ( V_2 ) ;
F_153 ( & V_2 -> V_283 ) ;
F_19 (dev, crtc, encoder)
V_47 -> V_192 ( V_47 ) ;
if ( F_79 ( V_2 ) )
F_217 ( V_2 , V_78 -> V_76 ) ;
F_33 ( V_2 , V_78 -> V_76 ) ;
}
static bool F_233 ( struct V_78 * V_11 )
{
return F_234 ( V_11 -> V_113 . V_2 ) && V_11 -> V_76 == V_130 ;
}
static void F_235 ( struct V_78 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_113 . V_2 -> V_5 ;
if ( ! V_11 -> V_79 . V_379 )
return;
F_164 ( V_4 , V_11 -> V_143 ) ;
F_36 ( V_380 , V_381 ) ;
}
static void F_236 ( struct V_78 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_11 -> V_79 . V_379 )
return;
F_164 ( V_4 , V_11 -> V_143 ) ;
F_36 ( V_380 , 0 ) ;
F_33 ( V_2 , V_11 -> V_76 ) ;
}
static void F_237 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_46 * V_47 ;
int V_76 = V_78 -> V_76 ;
int V_143 = V_78 -> V_143 ;
F_2 ( ! V_11 -> V_107 ) ;
if ( V_78 -> V_189 )
return;
V_78 -> V_189 = true ;
F_228 ( V_2 , V_76 , true ) ;
if ( V_78 -> V_79 . V_293 )
F_229 ( V_2 , V_204 , true ) ;
F_230 ( V_2 ) ;
if ( V_78 -> V_79 . V_293 )
V_4 -> V_267 . V_351 ( V_11 ) ;
F_19 (dev, crtc, encoder)
if ( V_47 -> V_378 )
V_47 -> V_378 ( V_47 ) ;
F_238 ( V_78 ) ;
F_218 ( V_78 ) ;
F_231 ( V_11 ) ;
F_239 ( V_11 ) ;
F_240 ( V_11 ) ;
F_115 ( V_4 , V_76 ,
V_78 -> V_79 . V_293 ) ;
F_121 ( V_4 , V_143 , V_76 ) ;
F_223 ( V_11 ) ;
F_232 ( V_11 , true ) ;
F_235 ( V_78 ) ;
if ( V_78 -> V_79 . V_293 )
F_212 ( V_11 ) ;
F_152 ( & V_2 -> V_283 ) ;
F_158 ( V_2 ) ;
F_153 ( & V_2 -> V_283 ) ;
F_19 (dev, crtc, encoder)
V_47 -> V_192 ( V_47 ) ;
F_33 ( V_2 , V_78 -> V_76 ) ;
}
static void F_241 ( struct V_78 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_76 = V_11 -> V_76 ;
if ( V_11 -> V_79 . V_372 . V_373 ) {
F_36 ( F_219 ( V_76 ) , 0 ) ;
F_36 ( F_221 ( V_76 ) , 0 ) ;
F_36 ( F_222 ( V_76 ) , 0 ) ;
}
}
static void F_242 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_46 * V_47 ;
int V_76 = V_78 -> V_76 ;
int V_143 = V_78 -> V_143 ;
T_1 V_86 , V_284 ;
if ( ! V_78 -> V_189 )
return;
F_19 (dev, crtc, encoder)
V_47 -> V_193 ( V_47 ) ;
F_181 ( V_11 ) ;
F_243 ( V_2 , V_76 ) ;
if ( V_4 -> V_382 == V_143 )
F_244 ( V_2 ) ;
F_232 ( V_11 , false ) ;
F_225 ( V_11 ) ;
F_123 ( V_4 , V_143 , V_76 ) ;
if ( V_78 -> V_79 . V_293 )
F_229 ( V_2 , V_76 , false ) ;
F_117 ( V_4 , V_76 ) ;
F_241 ( V_78 ) ;
F_19 (dev, crtc, encoder)
if ( V_47 -> V_383 )
V_47 -> V_383 ( V_47 ) ;
if ( V_78 -> V_79 . V_293 ) {
F_175 ( V_11 ) ;
F_111 ( V_4 , V_76 ) ;
F_229 ( V_2 , V_76 , true ) ;
if ( F_79 ( V_2 ) ) {
V_86 = F_80 ( V_76 ) ;
V_284 = F_4 ( V_86 ) ;
V_284 &= ~ ( V_360 |
V_163 ) ;
V_284 |= V_384 ;
F_36 ( V_86 , V_284 ) ;
V_284 = F_4 ( V_353 ) ;
V_284 &= ~ ( F_209 ( V_76 ) | F_210 ( V_76 ) ) ;
F_36 ( V_353 , V_284 ) ;
}
F_103 ( V_78 ) ;
F_174 ( V_78 ) ;
}
V_78 -> V_189 = false ;
F_230 ( V_2 ) ;
F_152 ( & V_2 -> V_283 ) ;
F_158 ( V_2 ) ;
F_153 ( & V_2 -> V_283 ) ;
}
static void F_245 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_46 * V_47 ;
int V_76 = V_78 -> V_76 ;
int V_143 = V_78 -> V_143 ;
enum V_75 V_80 = V_78 -> V_79 . V_80 ;
if ( ! V_78 -> V_189 )
return;
F_19 (dev, crtc, encoder)
V_47 -> V_193 ( V_47 ) ;
F_181 ( V_11 ) ;
F_243 ( V_2 , V_76 ) ;
if ( V_4 -> V_382 == V_143 )
F_244 ( V_2 ) ;
F_236 ( V_78 ) ;
F_232 ( V_11 , false ) ;
F_225 ( V_11 ) ;
F_123 ( V_4 , V_143 , V_76 ) ;
if ( V_78 -> V_79 . V_293 )
F_229 ( V_2 , V_204 , false ) ;
F_117 ( V_4 , V_76 ) ;
F_246 ( V_4 , V_80 ) ;
F_241 ( V_78 ) ;
F_247 ( V_78 ) ;
F_19 (dev, crtc, encoder)
if ( V_47 -> V_383 )
V_47 -> V_383 ( V_47 ) ;
if ( V_78 -> V_79 . V_293 ) {
F_114 ( V_4 ) ;
F_229 ( V_2 , V_204 , true ) ;
F_248 ( V_11 ) ;
}
V_78 -> V_189 = false ;
F_230 ( V_2 ) ;
F_152 ( & V_2 -> V_283 ) ;
F_158 ( V_2 ) ;
F_153 ( & V_2 -> V_283 ) ;
}
static void F_249 ( struct V_10 * V_11 )
{
struct V_78 * V_78 = F_27 ( V_11 ) ;
F_213 ( V_78 ) ;
}
static void F_250 ( struct V_10 * V_11 )
{
F_251 ( V_11 ) ;
}
static void F_252 ( struct V_78 * V_78 , bool V_192 )
{
if ( ! V_192 && V_78 -> V_385 ) {
struct V_1 * V_2 = V_78 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_152 ( & V_2 -> V_283 ) ;
V_4 -> V_222 . V_223 = false ;
( void ) F_253 ( V_78 -> V_385 ) ;
V_4 -> V_222 . V_223 = true ;
F_153 ( & V_2 -> V_283 ) ;
}
}
static void
F_254 ( struct V_3 * V_4 , enum V_76 V_76 )
{
T_1 V_386 = F_4 ( F_255 ( V_76 ) ) ;
if ( ( V_386 & V_387 ) == 0 ) {
T_1 V_388 = F_4 ( V_389 ) ;
F_36 ( V_389 , V_388 & ~ V_390 ) ;
F_36 ( F_255 ( V_76 ) , V_391 ) ;
F_33 ( V_4 -> V_2 , V_76 ) ;
F_36 ( F_255 ( V_76 ) , V_386 ) ;
F_36 ( F_256 ( V_76 ) , F_4 ( F_256 ( V_76 ) ) ) ;
F_36 ( V_389 , V_388 ) ;
}
}
static void F_257 ( struct V_78 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_392 * V_393 = & V_11 -> V_79 ;
if ( ! V_11 -> V_79 . V_394 . V_395 )
return;
F_2 ( F_4 ( V_396 ) & V_397 ) ;
F_93 ( V_4 , V_11 -> V_76 ) ;
F_36 ( V_398 , V_393 -> V_394 . V_399 ) ;
F_36 ( V_396 , V_393 -> V_394 . V_395 ) ;
F_36 ( F_258 ( V_11 -> V_76 ) , 0 ) ;
}
static void F_259 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_46 * V_47 ;
int V_76 = V_78 -> V_76 ;
int V_143 = V_78 -> V_143 ;
F_2 ( ! V_11 -> V_107 ) ;
if ( V_78 -> V_189 )
return;
V_78 -> V_189 = true ;
F_230 ( V_2 ) ;
F_152 ( & V_4 -> V_332 ) ;
F_19 (dev, crtc, encoder)
if ( V_47 -> V_400 )
V_47 -> V_400 ( V_47 ) ;
F_92 ( V_4 , V_76 ) ;
F_19 (dev, crtc, encoder)
if ( V_47 -> V_378 )
V_47 -> V_378 ( V_47 ) ;
F_19 (dev, crtc, encoder)
V_47 -> V_192 ( V_47 ) ;
F_257 ( V_78 ) ;
F_231 ( V_11 ) ;
F_115 ( V_4 , V_76 , false ) ;
F_121 ( V_4 , V_143 , V_76 ) ;
F_223 ( V_11 ) ;
F_232 ( V_11 , true ) ;
F_158 ( V_2 ) ;
F_153 ( & V_4 -> V_332 ) ;
}
static void F_260 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_46 * V_47 ;
int V_76 = V_78 -> V_76 ;
int V_143 = V_78 -> V_143 ;
F_2 ( ! V_11 -> V_107 ) ;
if ( V_78 -> V_189 )
return;
V_78 -> V_189 = true ;
F_230 ( V_2 ) ;
F_92 ( V_4 , V_76 ) ;
F_19 (dev, crtc, encoder)
if ( V_47 -> V_378 )
V_47 -> V_378 ( V_47 ) ;
F_257 ( V_78 ) ;
F_231 ( V_11 ) ;
F_115 ( V_4 , V_76 , false ) ;
F_121 ( V_4 , V_143 , V_76 ) ;
F_223 ( V_11 ) ;
if ( F_12 ( V_2 ) )
F_254 ( V_4 , V_76 ) ;
F_232 ( V_11 , true ) ;
F_252 ( V_78 , true ) ;
F_158 ( V_2 ) ;
F_19 (dev, crtc, encoder)
V_47 -> V_192 ( V_47 ) ;
}
static void F_261 ( struct V_78 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_11 -> V_79 . V_394 . V_395 )
return;
F_93 ( V_4 , V_11 -> V_76 ) ;
F_52 ( L_73 ,
F_4 ( V_396 ) ) ;
F_36 ( V_396 , 0 ) ;
}
static void F_262 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_46 * V_47 ;
int V_76 = V_78 -> V_76 ;
int V_143 = V_78 -> V_143 ;
if ( ! V_78 -> V_189 )
return;
F_19 (dev, crtc, encoder)
V_47 -> V_193 ( V_47 ) ;
F_181 ( V_11 ) ;
F_243 ( V_2 , V_76 ) ;
if ( V_4 -> V_382 == V_143 )
F_244 ( V_2 ) ;
F_252 ( V_78 , false ) ;
F_232 ( V_11 , false ) ;
F_225 ( V_11 ) ;
F_123 ( V_4 , V_143 , V_76 ) ;
F_117 ( V_4 , V_76 ) ;
F_261 ( V_78 ) ;
F_19 (dev, crtc, encoder)
if ( V_47 -> V_383 )
V_47 -> V_383 ( V_47 ) ;
F_99 ( V_4 , V_76 ) ;
V_78 -> V_189 = false ;
F_158 ( V_2 ) ;
F_230 ( V_2 ) ;
}
static void F_263 ( struct V_10 * V_11 )
{
}
static void F_264 ( struct V_10 * V_11 ,
bool V_107 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_273 * V_274 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_76 = V_78 -> V_76 ;
if ( ! V_2 -> V_275 -> V_276 )
return;
V_274 = V_2 -> V_275 -> V_276 -> V_277 ;
if ( ! V_274 -> V_278 )
return;
switch ( V_76 ) {
case 0 :
V_274 -> V_278 -> V_401 = V_107 ? V_11 -> V_338 . V_402 : 0 ;
V_274 -> V_278 -> V_403 = V_107 ? V_11 -> V_338 . V_404 : 0 ;
break;
case 1 :
V_274 -> V_278 -> V_405 = V_107 ? V_11 -> V_338 . V_402 : 0 ;
V_274 -> V_278 -> V_406 = V_107 ? V_11 -> V_338 . V_404 : 0 ;
break;
default:
F_109 ( L_74 , F_62 ( V_76 ) ) ;
break;
}
}
void F_265 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_46 * V_46 ;
bool V_192 = false ;
F_19 (dev, crtc, intel_encoder)
V_192 |= V_46 -> V_407 ;
if ( V_192 )
V_4 -> V_267 . V_408 ( V_11 ) ;
else
V_4 -> V_267 . V_409 ( V_11 ) ;
F_264 ( V_11 , V_192 ) ;
}
static void F_266 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_410 * V_411 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
F_2 ( ! V_11 -> V_107 ) ;
V_4 -> V_267 . V_409 ( V_11 ) ;
V_78 -> V_412 = false ;
F_264 ( V_11 , false ) ;
V_4 -> V_267 . V_413 ( V_11 ) ;
F_267 ( V_2 -> V_5 , F_27 ( V_11 ) -> V_143 ) ;
F_93 ( V_2 -> V_5 , F_27 ( V_11 ) -> V_76 ) ;
if ( V_11 -> V_234 ) {
F_152 ( & V_2 -> V_283 ) ;
F_134 ( F_138 ( V_11 -> V_234 ) -> V_212 ) ;
F_153 ( & V_2 -> V_283 ) ;
V_11 -> V_234 = NULL ;
}
F_149 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_411 -> V_47 || ! V_411 -> V_47 -> V_11 )
continue;
if ( V_411 -> V_47 -> V_11 != V_11 )
continue;
V_411 -> V_414 = V_415 ;
F_268 ( V_411 -> V_47 ) -> V_407 = false ;
}
}
void F_269 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_149 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_11 -> V_107 )
F_266 ( V_11 ) ;
}
}
void F_270 ( struct V_416 * V_47 )
{
struct V_46 * V_46 = F_268 ( V_47 ) ;
F_271 ( V_47 ) ;
F_272 ( V_46 ) ;
}
void F_273 ( struct V_46 * V_47 , int V_338 )
{
if ( V_338 == V_417 ) {
V_47 -> V_407 = true ;
F_265 ( V_47 -> V_113 . V_11 ) ;
} else {
V_47 -> V_407 = false ;
F_265 ( V_47 -> V_113 . V_11 ) ;
}
}
static void F_274 ( struct V_418 * V_411 )
{
if ( V_411 -> V_119 ( V_411 ) ) {
struct V_46 * V_47 = V_411 -> V_47 ;
struct V_10 * V_11 ;
bool V_419 ;
enum V_76 V_76 ;
F_32 ( L_75 ,
V_411 -> V_113 . V_113 . V_191 ,
F_275 ( & V_411 -> V_113 ) ) ;
F_39 ( V_411 -> V_113 . V_414 == V_415 ,
L_76 ) ;
F_39 ( V_411 -> V_113 . V_47 != & V_47 -> V_113 ,
L_77 ) ;
F_39 ( ! V_47 -> V_407 ,
L_78 ) ;
V_419 = V_47 -> V_119 ( V_47 , & V_76 ) ;
F_39 ( ! V_419 , L_79 ) ;
if ( F_2 ( ! V_47 -> V_113 . V_11 ) )
return;
V_11 = V_47 -> V_113 . V_11 ;
F_39 ( ! V_11 -> V_107 , L_80 ) ;
F_39 ( ! F_27 ( V_11 ) -> V_189 , L_81 ) ;
F_39 ( V_76 != F_27 ( V_11 ) -> V_76 ,
L_82 ) ;
}
}
void F_276 ( struct V_410 * V_411 , int V_338 )
{
struct V_46 * V_47 = F_277 ( V_411 ) ;
if ( V_338 != V_417 )
V_338 = V_415 ;
if ( V_338 == V_411 -> V_414 )
return;
V_411 -> V_414 = V_338 ;
if ( V_47 -> V_113 . V_11 )
F_273 ( V_47 , V_338 ) ;
else
F_2 ( V_47 -> V_407 != false ) ;
F_278 ( V_411 -> V_2 ) ;
}
bool F_279 ( struct V_418 * V_411 )
{
enum V_76 V_76 = 0 ;
struct V_46 * V_47 = V_411 -> V_47 ;
return V_47 -> V_119 ( V_47 , & V_76 ) ;
}
static bool F_280 ( struct V_1 * V_2 , enum V_76 V_76 ,
struct V_392 * V_393 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_294 =
F_27 ( V_4 -> V_77 [ V_139 ] ) ;
F_32 ( L_83 ,
F_62 ( V_76 ) , V_393 -> V_303 ) ;
if ( V_393 -> V_303 > 4 ) {
F_32 ( L_84 ,
F_62 ( V_76 ) , V_393 -> V_303 ) ;
return false ;
}
if ( F_144 ( V_2 ) ) {
if ( V_393 -> V_303 > 2 ) {
F_32 ( L_85 ,
V_393 -> V_303 ) ;
return false ;
} else {
return true ;
}
}
if ( F_35 ( V_2 ) -> V_147 == 2 )
return true ;
switch ( V_76 ) {
case V_130 :
return true ;
case V_139 :
if ( V_4 -> V_77 [ V_296 ] -> V_107 &&
V_393 -> V_303 > 2 ) {
F_32 ( L_86 ,
F_62 ( V_76 ) , V_393 -> V_303 ) ;
return false ;
}
return true ;
case V_296 :
if ( ! F_161 ( V_294 ) ||
V_294 -> V_79 . V_303 <= 2 ) {
if ( V_393 -> V_303 > 2 ) {
F_32 ( L_86 ,
F_62 ( V_76 ) , V_393 -> V_303 ) ;
return false ;
}
} else {
F_32 ( L_87 ) ;
return false ;
}
return true ;
default:
F_129 () ;
}
}
static int F_281 ( struct V_78 * V_78 ,
struct V_392 * V_393 )
{
struct V_1 * V_2 = V_78 -> V_113 . V_2 ;
struct V_420 * V_421 = & V_393 -> V_421 ;
int V_422 , V_423 , V_424 ;
bool V_425 , V_426 = false ;
V_308:
V_423 = F_5 ( V_2 ) * F_282 ( 100 ) / F_283 ( 1 ) / 10 ;
V_424 = V_421 -> clock ;
V_424 /= V_393 -> V_427 ;
V_422 = F_284 ( V_424 , V_423 ,
V_393 -> V_428 ) ;
V_393 -> V_303 = V_422 ;
F_285 ( V_393 -> V_428 , V_422 , V_424 ,
V_423 , & V_393 -> V_429 ) ;
V_425 = F_280 ( V_78 -> V_113 . V_2 ,
V_78 -> V_76 , V_393 ) ;
if ( ! V_425 && V_393 -> V_428 > 6 * 3 ) {
V_393 -> V_428 -= 2 * 3 ;
F_32 ( L_88 ,
V_393 -> V_428 ) ;
V_426 = true ;
V_393 -> V_430 = true ;
goto V_308;
}
if ( V_426 )
return V_431 ;
return V_425 ? 0 : - V_221 ;
}
static void F_286 ( struct V_78 * V_11 ,
struct V_392 * V_393 )
{
V_393 -> V_379 = V_432 &&
F_233 ( V_11 ) &&
V_393 -> V_428 == 24 ;
}
static int F_287 ( struct V_78 * V_11 ,
struct V_392 * V_393 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_420 * V_421 = & V_393 -> V_421 ;
if ( F_3 ( V_2 ) ) {
if ( V_393 -> V_433 . clock * 3
> V_434 * 4 )
return - V_221 ;
}
if ( ! V_393 -> V_435 )
F_288 ( V_421 , 0 ) ;
if ( ( F_35 ( V_2 ) -> V_84 > 4 || F_12 ( V_2 ) ) &&
V_421 -> V_436 == V_421 -> V_402 )
return - V_221 ;
if ( ( F_12 ( V_2 ) || F_14 ( V_2 ) ) && V_393 -> V_428 > 10 * 3 ) {
V_393 -> V_428 = 10 * 3 ;
} else if ( F_35 ( V_2 ) -> V_84 <= 4 && V_393 -> V_428 > 8 * 3 ) {
V_393 -> V_428 = 8 * 3 ;
}
if ( F_234 ( V_2 ) )
F_286 ( V_11 , V_393 ) ;
if ( F_45 ( V_2 ) || F_79 ( V_2 ) )
V_393 -> V_114 = V_11 -> V_79 . V_114 ;
if ( V_393 -> V_293 )
return F_281 ( V_11 , V_393 ) ;
return 0 ;
}
static int F_289 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_290 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_291 ( struct V_1 * V_2 )
{
return 333000 ;
}
static int F_292 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_293 ( struct V_1 * V_2 )
{
T_5 V_437 = 0 ;
F_294 ( V_2 -> V_438 , V_439 , & V_437 ) ;
if ( V_437 & V_440 )
return 133000 ;
else {
switch ( V_437 & V_441 ) {
case V_442 :
return 333000 ;
default:
case V_443 :
return 190000 ;
}
}
}
static int F_295 ( struct V_1 * V_2 )
{
return 266000 ;
}
static int F_296 ( struct V_1 * V_2 )
{
T_5 V_444 = 0 ;
switch ( V_444 & V_445 ) {
case V_446 :
case V_447 :
return 200000 ;
case V_448 :
return 250000 ;
case V_449 :
return 133000 ;
}
return 0 ;
}
static int F_297 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_298 ( T_4 * V_450 , T_4 * V_451 )
{
while ( * V_450 > V_452 ||
* V_451 > V_452 ) {
* V_450 >>= 1 ;
* V_451 >>= 1 ;
}
}
static void F_299 ( unsigned int V_36 , unsigned int V_42 ,
T_4 * V_453 , T_4 * V_454 )
{
* V_454 = F_300 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_453 = F_301 ( ( V_455 ) V_36 * * V_454 , V_42 ) ;
F_298 ( V_453 , V_454 ) ;
}
void
F_285 ( int V_263 , int V_456 ,
int V_457 , int V_458 ,
struct V_459 * V_460 )
{
V_460 -> V_461 = 64 ;
F_299 ( V_263 * V_457 ,
V_458 * V_456 * 8 ,
& V_460 -> V_462 , & V_460 -> V_463 ) ;
F_299 ( V_457 , V_458 ,
& V_460 -> V_464 , & V_460 -> V_465 ) ;
}
static inline bool F_302 ( struct V_3 * V_4 )
{
if ( V_466 >= 0 )
return V_466 != 0 ;
return V_4 -> V_467 . V_468
&& ! ( V_4 -> V_140 & V_469 ) ;
}
static int F_303 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_12 = 27000 ;
return 100000 ;
if ( F_8 ( V_11 , V_23 ) ) {
V_12 = 96000 ;
} else if ( F_8 ( V_11 , V_14 ) ) {
if ( F_302 ( V_4 ) )
V_12 = 100000 ;
else
V_12 = 96000 ;
} else if ( F_8 ( V_11 , V_356 ) ) {
V_12 = 100000 ;
}
return V_12 ;
}
static int F_304 ( struct V_10 * V_11 , int V_470 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_12 ;
if ( F_14 ( V_2 ) ) {
V_12 = F_303 ( V_11 ) ;
} else if ( F_8 ( V_11 , V_14 ) &&
F_302 ( V_4 ) && V_470 < 2 ) {
V_12 = V_4 -> V_467 . V_471 * 1000 ;
F_32 ( L_89 ,
V_12 / 1000 ) ;
} else if ( ! F_15 ( V_2 ) ) {
V_12 = 96000 ;
} else {
V_12 = 48000 ;
}
return V_12 ;
}
static T_4 F_305 ( struct V_44 * V_44 )
{
return ( 1 << V_44 -> V_42 ) << 16 | V_44 -> V_37 ;
}
static T_4 F_306 ( struct V_44 * V_44 )
{
return V_44 -> V_42 << 16 | V_44 -> V_45 << 8 | V_44 -> V_37 ;
}
static void F_307 ( struct V_78 * V_11 ,
T_3 * V_472 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_76 = V_11 -> V_76 ;
T_1 V_367 , V_473 = 0 ;
if ( F_13 ( V_2 ) ) {
V_367 = F_305 ( & V_11 -> V_79 . V_44 ) ;
if ( V_472 )
V_473 = F_305 ( V_472 ) ;
} else {
V_367 = F_306 ( & V_11 -> V_79 . V_44 ) ;
if ( V_472 )
V_473 = F_306 ( V_472 ) ;
}
F_36 ( F_308 ( V_76 ) , V_367 ) ;
V_11 -> V_474 = false ;
if ( F_8 ( & V_11 -> V_113 , V_14 ) &&
V_472 && V_475 ) {
F_36 ( F_309 ( V_76 ) , V_473 ) ;
V_11 -> V_474 = true ;
} else {
F_36 ( F_309 ( V_76 ) , V_367 ) ;
}
}
static void F_310 ( struct V_3 * V_4 )
{
T_1 V_476 ;
V_476 = F_311 ( V_4 , F_312 ( 1 ) ) ;
V_476 &= 0xffffff00 ;
V_476 |= 0x00000030 ;
F_313 ( V_4 , F_312 ( 1 ) , V_476 ) ;
V_476 = F_311 ( V_4 , V_477 ) ;
V_476 &= 0x8cffffff ;
V_476 = 0x8c000000 ;
F_313 ( V_4 , V_477 , V_476 ) ;
V_476 = F_311 ( V_4 , F_312 ( 1 ) ) ;
V_476 &= 0xffffff00 ;
F_313 ( V_4 , F_312 ( 1 ) , V_476 ) ;
V_476 = F_311 ( V_4 , V_477 ) ;
V_476 &= 0x00ffffff ;
V_476 |= 0xb0000000 ;
F_313 ( V_4 , V_477 , V_476 ) ;
}
static void F_314 ( struct V_78 * V_11 ,
struct V_459 * V_460 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_76 = V_11 -> V_76 ;
F_36 ( F_315 ( V_76 ) , F_316 ( V_460 -> V_461 ) | V_460 -> V_462 ) ;
F_36 ( F_317 ( V_76 ) , V_460 -> V_463 ) ;
F_36 ( F_318 ( V_76 ) , V_460 -> V_464 ) ;
F_36 ( F_319 ( V_76 ) , V_460 -> V_465 ) ;
}
static void F_320 ( struct V_78 * V_11 ,
struct V_459 * V_460 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_76 = V_11 -> V_76 ;
enum V_75 V_75 = V_11 -> V_79 . V_80 ;
if ( F_35 ( V_2 ) -> V_84 >= 5 ) {
F_36 ( F_208 ( V_75 ) , F_316 ( V_460 -> V_461 ) | V_460 -> V_462 ) ;
F_36 ( F_321 ( V_75 ) , V_460 -> V_463 ) ;
F_36 ( F_322 ( V_75 ) , V_460 -> V_464 ) ;
F_36 ( F_323 ( V_75 ) , V_460 -> V_465 ) ;
} else {
F_36 ( F_324 ( V_76 ) , F_316 ( V_460 -> V_461 ) | V_460 -> V_462 ) ;
F_36 ( F_325 ( V_76 ) , V_460 -> V_463 ) ;
F_36 ( F_326 ( V_76 ) , V_460 -> V_464 ) ;
F_36 ( F_327 ( V_76 ) , V_460 -> V_465 ) ;
}
}
static void F_328 ( struct V_78 * V_11 )
{
if ( V_11 -> V_79 . V_293 )
F_314 ( V_11 , & V_11 -> V_79 . V_478 ) ;
else
F_320 ( V_11 , & V_11 -> V_79 . V_478 ) ;
}
static void F_329 ( struct V_78 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_46 * V_47 ;
int V_76 = V_11 -> V_76 ;
T_1 V_44 , V_479 ;
T_1 V_61 , V_62 , V_63 , V_64 , V_65 ;
bool V_480 ;
T_1 V_481 , V_476 , V_482 ;
F_152 ( & V_4 -> V_332 ) ;
V_480 = F_8 ( & V_11 -> V_113 , V_22 ) ;
V_61 = V_11 -> V_79 . V_44 . V_42 ;
V_62 = V_11 -> V_79 . V_44 . V_45 ;
V_63 = V_11 -> V_79 . V_44 . V_37 ;
V_64 = V_11 -> V_79 . V_44 . V_39 ;
V_65 = V_11 -> V_79 . V_44 . V_40 ;
if ( V_76 )
F_310 ( V_4 ) ;
F_313 ( V_4 , V_483 , 0x0100000f ) ;
V_476 = F_311 ( V_4 , F_330 ( V_76 ) ) ;
V_476 &= 0x00ffffff ;
F_313 ( V_4 , F_330 ( V_76 ) , V_476 ) ;
F_313 ( V_4 , V_484 , 0x610 ) ;
V_479 = ( ( V_62 << V_485 ) | ( V_63 & V_486 ) ) ;
V_479 |= ( ( V_64 << V_487 ) | ( V_65 << V_488 ) ) ;
V_479 |= ( ( V_61 << V_489 ) ) ;
V_479 |= ( 1 << V_490 ) ;
V_479 |= ( V_491 << V_492 ) ;
F_313 ( V_4 , F_331 ( V_76 ) , V_479 ) ;
V_479 |= V_493 ;
F_313 ( V_4 , F_331 ( V_76 ) , V_479 ) ;
if ( V_11 -> V_79 . V_494 == 162000 ||
F_8 ( & V_11 -> V_113 , V_23 ) ||
F_8 ( & V_11 -> V_113 , V_22 ) )
F_313 ( V_4 , F_332 ( V_76 ) ,
0x005f0021 ) ;
else
F_313 ( V_4 , F_332 ( V_76 ) ,
0x00d0000f ) ;
if ( F_8 ( & V_11 -> V_113 , V_356 ) ||
F_8 ( & V_11 -> V_113 , V_355 ) ) {
if ( ! V_76 )
F_313 ( V_4 , F_333 ( V_76 ) ,
0x0df40000 ) ;
else
F_313 ( V_4 , F_333 ( V_76 ) ,
0x0df70000 ) ;
} else {
if ( ! V_76 )
F_313 ( V_4 , F_333 ( V_76 ) ,
0x0df70000 ) ;
else
F_313 ( V_4 , F_333 ( V_76 ) ,
0x0df40000 ) ;
}
V_481 = F_311 ( V_4 , F_334 ( V_76 ) ) ;
V_481 = ( V_481 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_8 ( & V_11 -> V_113 , V_355 ) ||
F_8 ( & V_11 -> V_113 , V_356 ) )
V_481 |= 0x01000000 ;
F_313 ( V_4 , F_334 ( V_76 ) , V_481 ) ;
F_313 ( V_4 , F_335 ( V_76 ) , 0x87871000 ) ;
F_19 (dev, &crtc->base, encoder)
if ( V_47 -> V_400 )
V_47 -> V_400 ( V_47 ) ;
V_44 = V_495 | V_496 |
V_497 | V_498 ;
if ( V_76 )
V_44 |= V_499 ;
V_44 |= V_111 ;
F_36 ( F_48 ( V_76 ) , V_44 ) ;
F_97 ( F_48 ( V_76 ) ) ;
F_98 ( 150 ) ;
if ( F_30 ( ( ( F_4 ( F_48 ( V_76 ) ) & V_500 ) == V_500 ) , 1 ) )
F_109 ( L_90 , V_76 ) ;
V_482 = ( V_11 -> V_79 . V_427 - 1 )
<< V_501 ;
F_36 ( F_336 ( V_76 ) , V_482 ) ;
F_97 ( F_336 ( V_76 ) ) ;
if ( V_11 -> V_79 . V_502 )
F_328 ( V_11 ) ;
F_153 ( & V_4 -> V_332 ) ;
}
static void F_337 ( struct V_78 * V_11 ,
T_3 * V_472 ,
int V_470 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_46 * V_47 ;
int V_76 = V_11 -> V_76 ;
T_1 V_44 ;
bool V_503 ;
struct V_44 * clock = & V_11 -> V_79 . V_44 ;
F_307 ( V_11 , V_472 ) ;
V_503 = F_8 ( & V_11 -> V_113 , V_25 ) ||
F_8 ( & V_11 -> V_113 , V_22 ) ;
V_44 = V_497 ;
if ( F_8 ( & V_11 -> V_113 , V_14 ) )
V_44 |= V_504 ;
else
V_44 |= V_505 ;
if ( F_338 ( V_2 ) || F_339 ( V_2 ) || F_340 ( V_2 ) ) {
V_44 |= ( V_11 -> V_79 . V_427 - 1 )
<< V_506 ;
}
if ( V_503 )
V_44 |= V_507 ;
if ( F_8 ( & V_11 -> V_113 , V_355 ) )
V_44 |= V_507 ;
if ( F_13 ( V_2 ) )
V_44 |= ( 1 << ( clock -> V_39 - 1 ) ) << V_508 ;
else {
V_44 |= ( 1 << ( clock -> V_39 - 1 ) ) << V_509 ;
if ( F_12 ( V_2 ) && V_472 )
V_44 |= ( 1 << ( V_472 -> V_39 - 1 ) ) << V_510 ;
}
switch ( clock -> V_40 ) {
case 5 :
V_44 |= V_511 ;
break;
case 7 :
V_44 |= V_512 ;
break;
case 10 :
V_44 |= V_513 ;
break;
case 14 :
V_44 |= V_514 ;
break;
}
if ( F_35 ( V_2 ) -> V_84 >= 4 )
V_44 |= ( 6 << V_515 ) ;
if ( V_11 -> V_79 . V_516 )
V_44 |= V_517 ;
else if ( F_8 ( & V_11 -> V_113 , V_14 ) &&
F_302 ( V_4 ) && V_470 < 2 )
V_44 |= V_518 ;
else
V_44 |= V_519 ;
V_44 |= V_111 ;
F_36 ( F_48 ( V_76 ) , V_44 & ~ V_111 ) ;
F_97 ( F_48 ( V_76 ) ) ;
F_98 ( 150 ) ;
F_19 (dev, &crtc->base, encoder)
if ( V_47 -> V_400 )
V_47 -> V_400 ( V_47 ) ;
if ( V_11 -> V_79 . V_502 )
F_328 ( V_11 ) ;
F_36 ( F_48 ( V_76 ) , V_44 ) ;
F_97 ( F_48 ( V_76 ) ) ;
F_98 ( 150 ) ;
if ( F_35 ( V_2 ) -> V_84 >= 4 ) {
T_1 V_482 = ( V_11 -> V_79 . V_427 - 1 )
<< V_501 ;
F_36 ( F_336 ( V_76 ) , V_482 ) ;
} else {
F_36 ( F_48 ( V_76 ) , V_44 ) ;
}
}
static void F_341 ( struct V_78 * V_11 ,
T_3 * V_472 ,
int V_470 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_46 * V_47 ;
int V_76 = V_11 -> V_76 ;
T_1 V_44 ;
struct V_44 * clock = & V_11 -> V_79 . V_44 ;
F_307 ( V_11 , V_472 ) ;
V_44 = V_497 ;
if ( F_8 ( & V_11 -> V_113 , V_14 ) ) {
V_44 |= ( 1 << ( clock -> V_39 - 1 ) ) << V_509 ;
} else {
if ( clock -> V_39 == 2 )
V_44 |= V_520 ;
else
V_44 |= ( clock -> V_39 - 2 ) << V_509 ;
if ( clock -> V_40 == 4 )
V_44 |= V_521 ;
}
if ( F_8 ( & V_11 -> V_113 , V_14 ) &&
F_302 ( V_4 ) && V_470 < 2 )
V_44 |= V_518 ;
else
V_44 |= V_519 ;
V_44 |= V_111 ;
F_36 ( F_48 ( V_76 ) , V_44 & ~ V_111 ) ;
F_97 ( F_48 ( V_76 ) ) ;
F_98 ( 150 ) ;
F_19 (dev, &crtc->base, encoder)
if ( V_47 -> V_400 )
V_47 -> V_400 ( V_47 ) ;
F_36 ( F_48 ( V_76 ) , V_44 ) ;
F_97 ( F_48 ( V_76 ) ) ;
F_98 ( 150 ) ;
F_36 ( F_48 ( V_76 ) , V_44 ) ;
}
static void F_342 ( struct V_78 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_76 V_76 = V_78 -> V_76 ;
enum V_75 V_80 = V_78 -> V_79 . V_80 ;
struct V_420 * V_421 =
& V_78 -> V_79 . V_421 ;
struct V_420 * V_338 = & V_78 -> V_79 . V_433 ;
T_4 V_522 , V_523 , V_524 ;
V_523 = V_421 -> V_523 ;
V_524 = V_421 -> V_524 ;
if ( ! F_15 ( V_2 ) && V_421 -> V_321 & V_525 ) {
V_523 -= 1 ;
V_524 -= 1 ;
V_522 = V_421 -> V_526
- V_421 -> V_527 / 2 ;
} else {
V_522 = 0 ;
}
if ( F_35 ( V_2 ) -> V_84 > 3 )
F_36 ( F_205 ( V_80 ) , V_522 ) ;
F_36 ( F_193 ( V_80 ) ,
( V_421 -> V_528 - 1 ) |
( ( V_421 -> V_527 - 1 ) << 16 ) ) ;
F_36 ( F_195 ( V_80 ) ,
( V_421 -> V_529 - 1 ) |
( ( V_421 -> V_530 - 1 ) << 16 ) ) ;
F_36 ( F_197 ( V_80 ) ,
( V_421 -> V_526 - 1 ) |
( ( V_421 -> V_531 - 1 ) << 16 ) ) ;
F_36 ( F_199 ( V_80 ) ,
( V_421 -> V_532 - 1 ) |
( ( V_523 - 1 ) << 16 ) ) ;
F_36 ( F_201 ( V_80 ) ,
( V_421 -> V_533 - 1 ) |
( ( V_524 - 1 ) << 16 ) ) ;
F_36 ( F_203 ( V_80 ) ,
( V_421 -> V_534 - 1 ) |
( ( V_421 -> V_535 - 1 ) << 16 ) ) ;
if ( F_144 ( V_2 ) && V_80 == V_536 &&
( V_76 == V_139 || V_76 == V_296 ) )
F_36 ( F_199 ( V_76 ) , F_4 ( F_199 ( V_80 ) ) ) ;
F_36 ( F_343 ( V_76 ) ,
( ( V_338 -> V_402 - 1 ) << 16 ) | ( V_338 -> V_404 - 1 ) ) ;
}
static void F_344 ( struct V_78 * V_11 ,
struct V_392 * V_393 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_75 V_80 = V_393 -> V_80 ;
T_4 V_537 ;
V_537 = F_4 ( F_193 ( V_80 ) ) ;
V_393 -> V_421 . V_528 = ( V_537 & 0xffff ) + 1 ;
V_393 -> V_421 . V_527 = ( ( V_537 >> 16 ) & 0xffff ) + 1 ;
V_537 = F_4 ( F_195 ( V_80 ) ) ;
V_393 -> V_421 . V_529 = ( V_537 & 0xffff ) + 1 ;
V_393 -> V_421 . V_530 = ( ( V_537 >> 16 ) & 0xffff ) + 1 ;
V_537 = F_4 ( F_197 ( V_80 ) ) ;
V_393 -> V_421 . V_526 = ( V_537 & 0xffff ) + 1 ;
V_393 -> V_421 . V_531 = ( ( V_537 >> 16 ) & 0xffff ) + 1 ;
V_537 = F_4 ( F_199 ( V_80 ) ) ;
V_393 -> V_421 . V_532 = ( V_537 & 0xffff ) + 1 ;
V_393 -> V_421 . V_523 = ( ( V_537 >> 16 ) & 0xffff ) + 1 ;
V_537 = F_4 ( F_201 ( V_80 ) ) ;
V_393 -> V_421 . V_533 = ( V_537 & 0xffff ) + 1 ;
V_393 -> V_421 . V_524 = ( ( V_537 >> 16 ) & 0xffff ) + 1 ;
V_537 = F_4 ( F_203 ( V_80 ) ) ;
V_393 -> V_421 . V_534 = ( V_537 & 0xffff ) + 1 ;
V_393 -> V_421 . V_535 = ( ( V_537 >> 16 ) & 0xffff ) + 1 ;
if ( F_4 ( F_38 ( V_80 ) ) & V_198 ) {
V_393 -> V_421 . V_321 |= V_525 ;
V_393 -> V_421 . V_523 += 1 ;
V_393 -> V_421 . V_524 += 1 ;
}
V_537 = F_4 ( F_343 ( V_11 -> V_76 ) ) ;
V_393 -> V_433 . V_404 = ( V_537 & 0xffff ) + 1 ;
V_393 -> V_433 . V_402 = ( ( V_537 >> 16 ) & 0xffff ) + 1 ;
}
static void F_345 ( struct V_78 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_538 ;
V_538 = 0 ;
if ( V_78 -> V_76 == 0 && F_35 ( V_2 ) -> V_84 < 4 ) {
if ( V_78 -> V_79 . V_433 . clock >
V_4 -> V_267 . V_539 ( V_2 ) * 9 / 10 )
V_538 |= V_540 ;
}
if ( F_12 ( V_2 ) || F_14 ( V_2 ) ) {
if ( V_78 -> V_79 . V_541 && V_78 -> V_79 . V_428 != 30 )
V_538 |= V_542 |
V_543 ;
switch ( V_78 -> V_79 . V_428 ) {
case 18 :
V_538 |= V_544 ;
break;
case 24 :
V_538 |= V_545 ;
break;
case 30 :
V_538 |= V_546 ;
break;
default:
F_129 () ;
}
}
if ( F_346 ( V_2 ) ) {
if ( V_78 -> V_474 ) {
F_32 ( L_91 ) ;
V_538 |= V_547 ;
} else {
F_32 ( L_92 ) ;
}
}
if ( ! F_15 ( V_2 ) &&
V_78 -> V_79 . V_421 . V_321 & V_525 )
V_538 |= V_548 ;
else
V_538 |= V_549 ;
if ( F_14 ( V_2 ) && V_78 -> V_79 . V_550 )
V_538 |= V_551 ;
F_36 ( F_38 ( V_78 -> V_76 ) , V_538 ) ;
F_97 ( F_38 ( V_78 -> V_76 ) ) ;
}
static int F_347 ( struct V_10 * V_11 ,
int V_226 , int V_227 ,
struct V_233 * V_234 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_420 * V_338 = & V_78 -> V_79 . V_433 ;
int V_76 = V_78 -> V_76 ;
int V_143 = V_78 -> V_143 ;
int V_12 , V_470 = 0 ;
T_3 clock , V_472 ;
T_1 V_238 ;
bool V_552 , V_553 = false ;
bool V_554 = false ;
struct V_46 * V_47 ;
const T_2 * V_13 ;
int V_216 ;
F_19 (dev, crtc, encoder) {
switch ( V_47 -> type ) {
case V_14 :
V_554 = true ;
break;
}
V_470 ++ ;
}
V_12 = F_304 ( V_11 , V_470 ) ;
V_13 = F_11 ( V_11 , V_12 ) ;
V_552 = V_4 -> V_267 . V_555 ( V_13 , V_11 ,
V_78 -> V_79 . V_494 ,
V_12 , NULL , & clock ) ;
if ( ! V_552 && ! V_78 -> V_79 . V_556 ) {
F_109 ( L_93 ) ;
return - V_221 ;
}
F_232 ( V_11 , true ) ;
if ( V_554 && V_4 -> V_557 ) {
V_553 =
V_4 -> V_267 . V_555 ( V_13 , V_11 ,
V_4 -> V_558 ,
V_12 , & clock ,
& V_472 ) ;
}
if ( ! V_78 -> V_79 . V_556 ) {
V_78 -> V_79 . V_44 . V_42 = clock . V_42 ;
V_78 -> V_79 . V_44 . V_45 = clock . V_45 ;
V_78 -> V_79 . V_44 . V_37 = clock . V_37 ;
V_78 -> V_79 . V_44 . V_39 = clock . V_39 ;
V_78 -> V_79 . V_44 . V_40 = clock . V_40 ;
}
if ( F_15 ( V_2 ) )
F_341 ( V_78 ,
V_553 ? & V_472 : NULL ,
V_470 ) ;
else if ( F_14 ( V_2 ) )
F_329 ( V_78 ) ;
else
F_337 ( V_78 ,
V_553 ? & V_472 : NULL ,
V_470 ) ;
V_238 = V_559 ;
if ( ! F_14 ( V_2 ) ) {
if ( V_76 == 0 )
V_238 &= ~ V_148 ;
else
V_238 |= V_560 ;
}
F_342 ( V_78 ) ;
F_36 ( F_348 ( V_143 ) ,
( ( V_338 -> V_404 - 1 ) << 16 ) |
( V_338 -> V_402 - 1 ) ) ;
F_36 ( F_349 ( V_143 ) , 0 ) ;
F_345 ( V_78 ) ;
F_36 ( F_67 ( V_143 ) , V_238 ) ;
F_97 ( F_67 ( V_143 ) ) ;
V_216 = F_157 ( V_11 , V_226 , V_227 , V_234 ) ;
F_230 ( V_2 ) ;
return V_216 ;
}
static void F_350 ( struct V_78 * V_11 ,
struct V_392 * V_393 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_537 ;
V_537 = F_4 ( V_396 ) ;
if ( ! ( V_537 & V_397 ) )
return;
if ( F_35 ( V_2 ) -> V_84 < 4 ) {
if ( V_11 -> V_76 != V_139 )
return;
} else {
if ( ( V_537 & V_561 ) != ( V_11 -> V_76 << V_562 ) )
return;
}
V_393 -> V_394 . V_395 = V_537 ;
V_393 -> V_394 . V_399 = F_4 ( V_398 ) ;
if ( F_35 ( V_2 ) -> V_84 < 5 )
V_393 -> V_394 . V_563 =
F_4 ( V_135 ) & V_564 ;
}
static bool F_351 ( struct V_78 * V_11 ,
struct V_392 * V_393 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_537 ;
V_393 -> V_80 = V_11 -> V_76 ;
V_393 -> V_114 = V_366 ;
V_537 = F_4 ( F_38 ( V_11 -> V_76 ) ) ;
if ( ! ( V_537 & V_142 ) )
return false ;
F_344 ( V_11 , V_393 ) ;
F_350 ( V_11 , V_393 ) ;
if ( F_35 ( V_2 ) -> V_84 >= 4 ) {
V_537 = F_4 ( F_336 ( V_11 -> V_76 ) ) ;
V_393 -> V_427 =
( ( V_537 & V_565 )
>> V_501 ) + 1 ;
} else if ( F_338 ( V_2 ) || F_339 ( V_2 ) || F_340 ( V_2 ) ) {
V_537 = F_4 ( F_48 ( V_11 -> V_76 ) ) ;
V_393 -> V_427 =
( ( V_537 & V_566 )
>> V_506 ) + 1 ;
} else {
V_393 -> V_427 = 1 ;
}
return true ;
}
static void F_352 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_567 * V_568 = & V_2 -> V_568 ;
struct V_46 * V_47 ;
T_1 V_109 , V_569 ;
bool V_570 = false ;
bool V_571 = false ;
bool V_572 = false ;
bool V_573 = false ;
bool V_574 = false ;
F_149 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_47 -> type ) {
case V_14 :
V_572 = true ;
V_570 = true ;
break;
case V_356 :
V_572 = true ;
if ( F_353 ( & V_47 -> V_113 ) -> V_95 == V_575 )
V_571 = true ;
break;
}
}
if ( F_45 ( V_2 ) ) {
V_573 = V_4 -> V_467 . V_576 ;
V_574 = V_573 ;
} else {
V_573 = false ;
V_574 = true ;
}
F_32 ( L_94 ,
V_572 , V_570 , V_573 ) ;
V_109 = F_4 ( V_154 ) ;
V_569 = V_109 ;
V_569 &= ~ V_156 ;
if ( V_573 )
V_569 |= V_577 ;
else
V_569 |= V_578 ;
V_569 &= ~ V_155 ;
V_569 &= ~ V_579 ;
V_569 &= ~ V_580 ;
if ( V_572 ) {
V_569 |= V_581 ;
if ( F_302 ( V_4 ) && V_574 )
V_569 |= V_580 ;
if ( V_571 ) {
if ( F_302 ( V_4 ) && V_574 )
V_569 |= V_582 ;
else
V_569 |= V_583 ;
} else
V_569 |= V_584 ;
} else {
V_569 |= V_585 ;
V_569 |= V_584 ;
}
if ( V_569 == V_109 )
return;
V_109 &= ~ V_156 ;
if ( V_573 )
V_109 |= V_577 ;
else
V_109 |= V_578 ;
if ( V_572 ) {
V_109 &= ~ V_155 ;
V_109 |= V_581 ;
if ( F_302 ( V_4 ) && V_574 ) {
F_32 ( L_95 ) ;
V_109 |= V_580 ;
} else
V_109 &= ~ V_580 ;
F_36 ( V_154 , V_109 ) ;
F_97 ( V_154 ) ;
F_98 ( 200 ) ;
V_109 &= ~ V_579 ;
if ( V_571 ) {
if ( F_302 ( V_4 ) && V_574 ) {
F_32 ( L_96 ) ;
V_109 |= V_582 ;
}
else
V_109 |= V_583 ;
} else
V_109 |= V_584 ;
F_36 ( V_154 , V_109 ) ;
F_97 ( V_154 ) ;
F_98 ( 200 ) ;
} else {
F_32 ( L_97 ) ;
V_109 &= ~ V_579 ;
V_109 |= V_584 ;
F_36 ( V_154 , V_109 ) ;
F_97 ( V_154 ) ;
F_98 ( 200 ) ;
V_109 &= ~ V_155 ;
V_109 |= V_585 ;
V_109 &= ~ V_580 ;
F_36 ( V_154 , V_109 ) ;
F_97 ( V_154 ) ;
F_98 ( 200 ) ;
}
F_94 ( V_109 != V_569 ) ;
}
static void F_354 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_567 * V_568 = & V_2 -> V_568 ;
struct V_46 * V_47 ;
bool V_586 = false ;
bool V_587 = false ;
T_1 V_537 ;
F_149 (encoder, &mode_config->encoder_list, base.head) {
switch ( V_47 -> type ) {
case V_23 :
V_586 = true ;
break;
}
}
if ( ! V_586 )
return;
F_152 ( & V_4 -> V_332 ) ;
if ( F_144 ( V_2 ) && ( V_2 -> V_588 & 0xFF00 ) == 0x0C00 )
V_587 = true ;
V_537 = F_186 ( V_4 , V_589 , V_336 ) ;
V_537 &= ~ V_337 ;
V_537 |= V_590 ;
F_185 ( V_4 , V_589 , V_537 , V_336 ) ;
F_98 ( 24 ) ;
V_537 = F_186 ( V_4 , V_589 , V_336 ) ;
V_537 &= ~ V_590 ;
F_185 ( V_4 , V_589 , V_537 , V_336 ) ;
if ( ! V_587 ) {
V_537 = F_4 ( V_591 ) ;
V_537 |= V_592 ;
F_36 ( V_591 , V_537 ) ;
if ( F_355 ( F_4 ( V_591 ) &
V_593 , 100 ) )
F_109 ( L_98 ) ;
V_537 = F_4 ( V_591 ) ;
V_537 &= ~ V_592 ;
F_36 ( V_591 , V_537 ) ;
if ( F_355 ( ( F_4 ( V_591 ) &
V_593 ) == 0 ,
100 ) )
F_109 ( L_99 ) ;
}
V_537 = F_186 ( V_4 , 0x8008 , V_594 ) ;
V_537 &= ~ ( 0xFF << 24 ) ;
V_537 |= ( 0x12 << 24 ) ;
F_185 ( V_4 , 0x8008 , V_537 , V_594 ) ;
if ( V_587 ) {
V_537 = F_186 ( V_4 , 0x800C , V_594 ) ;
V_537 |= 0x7FFF ;
F_185 ( V_4 , 0x800C , V_537 , V_594 ) ;
}
V_537 = F_186 ( V_4 , 0x2008 , V_594 ) ;
V_537 |= ( 1 << 11 ) ;
F_185 ( V_4 , 0x2008 , V_537 , V_594 ) ;
V_537 = F_186 ( V_4 , 0x2108 , V_594 ) ;
V_537 |= ( 1 << 11 ) ;
F_185 ( V_4 , 0x2108 , V_537 , V_594 ) ;
if ( V_587 ) {
V_537 = F_186 ( V_4 , 0x2038 , V_594 ) ;
V_537 |= ( 0x3F << 24 ) | ( 0xF << 20 ) | ( 0xF << 16 ) ;
F_185 ( V_4 , 0x2038 , V_537 , V_594 ) ;
V_537 = F_186 ( V_4 , 0x2138 , V_594 ) ;
V_537 |= ( 0x3F << 24 ) | ( 0xF << 20 ) | ( 0xF << 16 ) ;
F_185 ( V_4 , 0x2138 , V_537 , V_594 ) ;
V_537 = F_186 ( V_4 , 0x203C , V_594 ) ;
V_537 |= ( 0x3F << 8 ) ;
F_185 ( V_4 , 0x203C , V_537 , V_594 ) ;
V_537 = F_186 ( V_4 , 0x213C , V_594 ) ;
V_537 |= ( 0x3F << 8 ) ;
F_185 ( V_4 , 0x213C , V_537 , V_594 ) ;
}
V_537 = F_186 ( V_4 , 0x206C , V_594 ) ;
V_537 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_185 ( V_4 , 0x206C , V_537 , V_594 ) ;
V_537 = F_186 ( V_4 , 0x216C , V_594 ) ;
V_537 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_185 ( V_4 , 0x216C , V_537 , V_594 ) ;
if ( ! V_587 ) {
V_537 = F_186 ( V_4 , 0x2080 , V_594 ) ;
V_537 &= ~ ( 7 << 13 ) ;
V_537 |= ( 5 << 13 ) ;
F_185 ( V_4 , 0x2080 , V_537 , V_594 ) ;
V_537 = F_186 ( V_4 , 0x2180 , V_594 ) ;
V_537 &= ~ ( 7 << 13 ) ;
V_537 |= ( 5 << 13 ) ;
F_185 ( V_4 , 0x2180 , V_537 , V_594 ) ;
}
V_537 = F_186 ( V_4 , 0x208C , V_594 ) ;
V_537 &= ~ 0xFF ;
V_537 |= 0x1C ;
F_185 ( V_4 , 0x208C , V_537 , V_594 ) ;
V_537 = F_186 ( V_4 , 0x218C , V_594 ) ;
V_537 &= ~ 0xFF ;
V_537 |= 0x1C ;
F_185 ( V_4 , 0x218C , V_537 , V_594 ) ;
V_537 = F_186 ( V_4 , 0x2098 , V_594 ) ;
V_537 &= ~ ( 0xFF << 16 ) ;
V_537 |= ( 0x1C << 16 ) ;
F_185 ( V_4 , 0x2098 , V_537 , V_594 ) ;
V_537 = F_186 ( V_4 , 0x2198 , V_594 ) ;
V_537 &= ~ ( 0xFF << 16 ) ;
V_537 |= ( 0x1C << 16 ) ;
F_185 ( V_4 , 0x2198 , V_537 , V_594 ) ;
if ( ! V_587 ) {
V_537 = F_186 ( V_4 , 0x20C4 , V_594 ) ;
V_537 |= ( 1 << 27 ) ;
F_185 ( V_4 , 0x20C4 , V_537 , V_594 ) ;
V_537 = F_186 ( V_4 , 0x21C4 , V_594 ) ;
V_537 |= ( 1 << 27 ) ;
F_185 ( V_4 , 0x21C4 , V_537 , V_594 ) ;
V_537 = F_186 ( V_4 , 0x20EC , V_594 ) ;
V_537 &= ~ ( 0xF << 28 ) ;
V_537 |= ( 4 << 28 ) ;
F_185 ( V_4 , 0x20EC , V_537 , V_594 ) ;
V_537 = F_186 ( V_4 , 0x21EC , V_594 ) ;
V_537 &= ~ ( 0xF << 28 ) ;
V_537 |= ( 4 << 28 ) ;
F_185 ( V_4 , 0x21EC , V_537 , V_594 ) ;
}
V_537 = F_186 ( V_4 , V_595 , V_336 ) ;
V_537 |= V_596 ;
F_185 ( V_4 , V_595 , V_537 , V_336 ) ;
F_153 ( & V_4 -> V_332 ) ;
}
void F_356 ( struct V_1 * V_2 )
{
if ( F_45 ( V_2 ) || F_79 ( V_2 ) )
F_352 ( V_2 ) ;
else if ( F_51 ( V_2 ) )
F_354 ( V_2 ) ;
}
static int F_357 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_46 * V_47 ;
int V_470 = 0 ;
bool V_554 = false ;
F_19 (dev, crtc, encoder) {
switch ( V_47 -> type ) {
case V_14 :
V_554 = true ;
break;
}
V_470 ++ ;
}
if ( V_554 && F_302 ( V_4 ) && V_470 < 2 ) {
F_32 ( L_89 ,
V_4 -> V_467 . V_471 ) ;
return V_4 -> V_467 . V_471 * 1000 ;
}
return 120000 ;
}
static void F_358 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_76 = V_78 -> V_76 ;
T_4 V_109 ;
V_109 = 0 ;
switch ( V_78 -> V_79 . V_428 ) {
case 18 :
V_109 |= V_544 ;
break;
case 24 :
V_109 |= V_545 ;
break;
case 30 :
V_109 |= V_546 ;
break;
case 36 :
V_109 |= V_597 ;
break;
default:
F_129 () ;
}
if ( V_78 -> V_79 . V_541 )
V_109 |= ( V_542 | V_543 ) ;
if ( V_78 -> V_79 . V_421 . V_321 & V_525 )
V_109 |= V_199 ;
else
V_109 |= V_549 ;
if ( V_78 -> V_79 . V_550 )
V_109 |= V_551 ;
F_36 ( F_38 ( V_76 ) , V_109 ) ;
F_97 ( F_38 ( V_76 ) ) ;
}
static void F_359 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_76 = V_78 -> V_76 ;
T_6 V_598 = 0x7800 ;
if ( V_78 -> V_79 . V_550 )
V_598 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_36 ( F_360 ( V_76 ) , V_598 << 16 ) ;
F_36 ( F_361 ( V_76 ) , 0 ) ;
F_36 ( F_362 ( V_76 ) , V_598 ) ;
F_36 ( F_363 ( V_76 ) , 0 ) ;
F_36 ( F_364 ( V_76 ) , 0 ) ;
F_36 ( F_365 ( V_76 ) , V_598 << 16 ) ;
F_36 ( F_366 ( V_76 ) , 0 ) ;
F_36 ( F_367 ( V_76 ) , 0 ) ;
F_36 ( F_368 ( V_76 ) , 0 ) ;
if ( F_35 ( V_2 ) -> V_84 > 6 ) {
T_6 V_599 = 0 ;
if ( V_78 -> V_79 . V_550 )
V_599 = ( 16 * ( 1 << 13 ) / 255 ) & 0x1fff ;
F_36 ( F_369 ( V_76 ) , V_599 ) ;
F_36 ( F_370 ( V_76 ) , V_599 ) ;
F_36 ( F_371 ( V_76 ) , V_599 ) ;
F_36 ( F_372 ( V_76 ) , 0 ) ;
} else {
T_4 V_338 = V_600 ;
if ( V_78 -> V_79 . V_550 )
V_338 |= V_601 ;
F_36 ( F_372 ( V_76 ) , V_338 ) ;
}
}
static void F_373 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
enum V_75 V_80 = V_78 -> V_79 . V_80 ;
T_4 V_109 ;
V_109 = 0 ;
if ( V_78 -> V_79 . V_541 )
V_109 |= ( V_542 | V_543 ) ;
if ( V_78 -> V_79 . V_421 . V_321 & V_525 )
V_109 |= V_199 ;
else
V_109 |= V_549 ;
F_36 ( F_38 ( V_80 ) , V_109 ) ;
F_97 ( F_38 ( V_80 ) ) ;
F_36 ( F_374 ( V_78 -> V_76 ) , V_602 ) ;
F_97 ( F_374 ( V_78 -> V_76 ) ) ;
}
static bool F_375 ( struct V_10 * V_11 ,
T_3 * clock ,
bool * V_553 ,
T_3 * V_472 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_46 * V_46 ;
int V_12 ;
const T_2 * V_13 ;
bool V_216 , V_554 = false ;
F_19 (dev, crtc, intel_encoder) {
switch ( V_46 -> type ) {
case V_14 :
V_554 = true ;
break;
}
}
V_12 = F_357 ( V_11 ) ;
V_13 = F_11 ( V_11 , V_12 ) ;
V_216 = V_4 -> V_267 . V_555 ( V_13 , V_11 ,
F_27 ( V_11 ) -> V_79 . V_494 ,
V_12 , NULL , clock ) ;
if ( ! V_216 )
return false ;
if ( V_554 && V_4 -> V_557 ) {
* V_553 =
V_4 -> V_267 . V_555 ( V_13 , V_11 ,
V_4 -> V_558 ,
V_12 , clock ,
V_472 ) ;
}
return true ;
}
static void F_376 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_284 ;
V_284 = F_4 ( V_297 ) ;
if ( V_284 & V_298 )
return;
F_2 ( F_4 ( F_58 ( V_139 ) ) & V_123 ) ;
F_2 ( F_4 ( F_58 ( V_296 ) ) & V_123 ) ;
V_284 |= V_298 ;
F_32 ( L_100 ) ;
F_36 ( V_297 , V_284 ) ;
F_97 ( V_297 ) ;
}
static void F_377 ( struct V_78 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_78 -> V_76 ) {
case V_130 :
break;
case V_139 :
if ( V_78 -> V_79 . V_303 > 2 )
F_2 ( F_4 ( V_297 ) & V_298 ) ;
else
F_376 ( V_2 ) ;
break;
case V_296 :
F_376 ( V_2 ) ;
break;
default:
F_129 () ;
}
}
int F_284 ( int V_603 , int V_423 , int V_604 )
{
T_1 V_605 = V_603 * V_604 * 21 / 20 ;
return V_605 / ( V_423 * 8 ) + 1 ;
}
static bool F_378 ( struct V_44 * V_44 , int V_606 )
{
return F_17 ( V_44 ) < V_606 * V_44 -> V_42 ;
}
static T_4 F_379 ( struct V_78 * V_78 ,
T_1 * V_367 ,
T_3 * V_472 , T_1 * V_473 )
{
struct V_10 * V_11 = & V_78 -> V_113 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_46 * V_46 ;
T_4 V_44 ;
int V_606 , V_470 = 0 ;
bool V_554 = false , V_503 = false ;
F_19 (dev, crtc, intel_encoder) {
switch ( V_46 -> type ) {
case V_14 :
V_554 = true ;
break;
case V_25 :
case V_22 :
V_503 = true ;
break;
}
V_470 ++ ;
}
V_606 = 21 ;
if ( V_554 ) {
if ( ( F_302 ( V_4 ) &&
V_4 -> V_467 . V_471 == 100 ) ||
( F_45 ( V_2 ) && F_9 ( V_2 ) ) )
V_606 = 25 ;
} else if ( V_78 -> V_79 . V_516 )
V_606 = 20 ;
if ( F_378 ( & V_78 -> V_79 . V_44 , V_606 ) )
* V_367 |= V_607 ;
if ( V_473 && ( V_472 -> V_36 < V_606 * V_472 -> V_42 ) )
* V_473 |= V_607 ;
V_44 = 0 ;
if ( V_554 )
V_44 |= V_504 ;
else
V_44 |= V_505 ;
V_44 |= ( V_78 -> V_79 . V_427 - 1 )
<< V_608 ;
if ( V_503 )
V_44 |= V_507 ;
if ( V_78 -> V_79 . V_502 )
V_44 |= V_507 ;
V_44 |= ( 1 << ( V_78 -> V_79 . V_44 . V_39 - 1 ) ) << V_509 ;
V_44 |= ( 1 << ( V_78 -> V_79 . V_44 . V_39 - 1 ) ) << V_510 ;
switch ( V_78 -> V_79 . V_44 . V_40 ) {
case 5 :
V_44 |= V_511 ;
break;
case 7 :
V_44 |= V_512 ;
break;
case 10 :
V_44 |= V_513 ;
break;
case 14 :
V_44 |= V_514 ;
break;
}
if ( V_554 && F_302 ( V_4 ) && V_470 < 2 )
V_44 |= V_518 ;
else
V_44 |= V_519 ;
return V_44 | V_111 ;
}
static int F_380 ( struct V_10 * V_11 ,
int V_226 , int V_227 ,
struct V_233 * V_234 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_76 = V_78 -> V_76 ;
int V_143 = V_78 -> V_143 ;
int V_470 = 0 ;
T_3 clock , V_472 ;
T_1 V_44 = 0 , V_367 = 0 , V_473 = 0 ;
bool V_552 , V_553 = false ;
bool V_554 = false ;
struct V_46 * V_47 ;
struct V_112 * V_116 ;
int V_216 ;
F_19 (dev, crtc, encoder) {
switch ( V_47 -> type ) {
case V_14 :
V_554 = true ;
break;
}
V_470 ++ ;
}
F_39 ( ! ( F_45 ( V_2 ) || F_79 ( V_2 ) ) ,
L_101 , F_381 ( V_2 ) ) ;
V_552 = F_375 ( V_11 , & clock ,
& V_553 , & V_472 ) ;
if ( ! V_552 && ! V_78 -> V_79 . V_556 ) {
F_109 ( L_93 ) ;
return - V_221 ;
}
if ( ! V_78 -> V_79 . V_556 ) {
V_78 -> V_79 . V_44 . V_42 = clock . V_42 ;
V_78 -> V_79 . V_44 . V_45 = clock . V_45 ;
V_78 -> V_79 . V_44 . V_37 = clock . V_37 ;
V_78 -> V_79 . V_44 . V_39 = clock . V_39 ;
V_78 -> V_79 . V_44 . V_40 = clock . V_40 ;
}
F_232 ( V_11 , true ) ;
if ( V_78 -> V_79 . V_293 ) {
V_367 = F_306 ( & V_78 -> V_79 . V_44 ) ;
if ( V_553 )
V_473 = F_306 ( & V_472 ) ;
V_44 = F_379 ( V_78 ,
& V_367 , & V_472 ,
V_553 ? & V_473 : NULL ) ;
V_78 -> V_79 . V_370 . V_44 = V_44 ;
V_78 -> V_79 . V_370 . V_609 = V_367 ;
if ( V_553 )
V_78 -> V_79 . V_370 . V_610 = V_473 ;
else
V_78 -> V_79 . V_370 . V_610 = V_367 ;
V_116 = F_214 ( V_78 , V_44 , V_367 ) ;
if ( V_116 == NULL ) {
F_52 ( L_102 ,
F_62 ( V_76 ) ) ;
return - V_221 ;
}
} else
F_213 ( V_78 ) ;
if ( V_78 -> V_79 . V_502 )
F_328 ( V_78 ) ;
F_19 (dev, crtc, encoder)
if ( V_47 -> V_400 )
V_47 -> V_400 ( V_47 ) ;
if ( V_554 && V_553 && V_475 )
V_78 -> V_474 = true ;
else
V_78 -> V_474 = false ;
if ( V_78 -> V_79 . V_293 ) {
V_116 = F_49 ( V_78 ) ;
F_36 ( F_215 ( V_116 -> V_191 ) , V_44 ) ;
F_97 ( F_215 ( V_116 -> V_191 ) ) ;
F_98 ( 150 ) ;
F_36 ( F_215 ( V_116 -> V_191 ) , V_44 ) ;
if ( V_553 )
F_36 ( F_382 ( V_116 -> V_191 ) , V_473 ) ;
else
F_36 ( F_382 ( V_116 -> V_191 ) , V_367 ) ;
}
F_342 ( V_78 ) ;
if ( V_78 -> V_79 . V_293 ) {
F_320 ( V_78 ,
& V_78 -> V_79 . V_429 ) ;
}
if ( F_160 ( V_2 ) )
F_377 ( V_78 ) ;
F_358 ( V_11 ) ;
F_36 ( F_67 ( V_143 ) , V_559 ) ;
F_97 ( F_67 ( V_143 ) ) ;
V_216 = F_157 ( V_11 , V_226 , V_227 , V_234 ) ;
F_230 ( V_2 ) ;
return V_216 ;
}
static void F_383 ( struct V_78 * V_11 ,
struct V_392 * V_393 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_75 V_75 = V_393 -> V_80 ;
V_393 -> V_429 . V_464 = F_4 ( F_322 ( V_75 ) ) ;
V_393 -> V_429 . V_465 = F_4 ( F_323 ( V_75 ) ) ;
V_393 -> V_429 . V_462 = F_4 ( F_208 ( V_75 ) )
& ~ V_350 ;
V_393 -> V_429 . V_463 = F_4 ( F_321 ( V_75 ) ) ;
V_393 -> V_429 . V_461 = ( ( F_4 ( F_208 ( V_75 ) )
& V_350 ) >> V_611 ) + 1 ;
}
static void F_384 ( struct V_78 * V_11 ,
struct V_392 * V_393 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_537 ;
V_537 = F_4 ( F_219 ( V_11 -> V_76 ) ) ;
if ( V_537 & V_374 ) {
V_393 -> V_372 . V_376 = F_4 ( F_221 ( V_11 -> V_76 ) ) ;
V_393 -> V_372 . V_373 = F_4 ( F_222 ( V_11 -> V_76 ) ) ;
if ( F_385 ( V_2 ) ) {
F_2 ( ( V_537 & V_612 ) !=
F_220 ( V_11 -> V_76 ) ) ;
}
}
}
static bool F_386 ( struct V_78 * V_11 ,
struct V_392 * V_393 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_537 ;
V_393 -> V_80 = V_11 -> V_76 ;
V_393 -> V_114 = V_366 ;
V_537 = F_4 ( F_38 ( V_11 -> V_76 ) ) ;
if ( ! ( V_537 & V_142 ) )
return false ;
if ( F_4 ( F_77 ( V_11 -> V_76 ) ) & V_158 ) {
struct V_112 * V_116 ;
V_393 -> V_293 = true ;
V_537 = F_4 ( F_58 ( V_11 -> V_76 ) ) ;
V_393 -> V_303 = ( ( V_302 & V_537 ) >>
V_613 ) + 1 ;
F_383 ( V_11 , V_393 ) ;
V_393 -> V_427 = 1 ;
if ( F_45 ( V_4 -> V_2 ) ) {
V_393 -> V_114 = V_11 -> V_76 ;
} else {
V_537 = F_4 ( V_353 ) ;
if ( V_537 & F_210 ( V_11 -> V_76 ) )
V_393 -> V_114 = V_354 ;
else
V_393 -> V_114 = V_614 ;
}
V_116 = & V_4 -> V_115 [ V_393 -> V_114 ] ;
F_2 ( ! V_116 -> V_119 ( V_4 , V_116 ,
& V_393 -> V_370 ) ) ;
} else {
V_393 -> V_427 = 1 ;
}
F_344 ( V_11 , V_393 ) ;
F_384 ( V_11 , V_393 ) ;
return true ;
}
static void F_387 ( struct V_1 * V_2 )
{
bool V_192 = false ;
struct V_78 * V_11 ;
F_149 (crtc, &dev->mode_config.crtc_list, base.head) {
if ( ! V_11 -> V_113 . V_107 )
continue;
if ( V_11 -> V_76 != V_130 || V_11 -> V_79 . V_372 . V_373 ||
V_11 -> V_79 . V_80 != V_536 )
V_192 = true ;
}
F_388 ( V_2 , V_192 ) ;
}
static int F_389 ( struct V_10 * V_11 ,
int V_226 , int V_227 ,
struct V_233 * V_234 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_143 = V_78 -> V_143 ;
int V_216 ;
if ( ! F_390 ( V_11 ) )
return - V_221 ;
F_232 ( V_11 , true ) ;
if ( V_78 -> V_79 . V_502 )
F_328 ( V_78 ) ;
V_78 -> V_474 = false ;
F_342 ( V_78 ) ;
if ( V_78 -> V_79 . V_293 ) {
F_320 ( V_78 ,
& V_78 -> V_79 . V_429 ) ;
}
F_373 ( V_11 ) ;
F_359 ( V_11 ) ;
F_36 ( F_67 ( V_143 ) , V_559 | V_615 ) ;
F_97 ( F_67 ( V_143 ) ) ;
V_216 = F_157 ( V_11 , V_226 , V_227 , V_234 ) ;
F_230 ( V_2 ) ;
return V_216 ;
}
static bool F_391 ( struct V_78 * V_11 ,
struct V_392 * V_393 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_616 V_617 ;
T_4 V_537 ;
V_393 -> V_80 = V_11 -> V_76 ;
V_393 -> V_114 = V_366 ;
V_537 = F_4 ( F_55 ( V_536 ) ) ;
if ( V_537 & V_121 ) {
enum V_76 V_618 ;
switch ( V_537 & V_619 ) {
default:
F_39 ( 1 , L_103 ) ;
case V_620 :
case V_621 :
V_618 = V_130 ;
break;
case V_622 :
V_618 = V_139 ;
break;
case V_623 :
V_618 = V_296 ;
break;
}
if ( V_618 == V_11 -> V_76 )
V_393 -> V_80 = V_536 ;
}
if ( ! F_64 ( V_2 ,
F_65 ( V_393 -> V_80 ) ) )
return false ;
V_537 = F_4 ( F_38 ( V_393 -> V_80 ) ) ;
if ( ! ( V_537 & V_142 ) )
return false ;
V_537 = F_4 ( F_55 ( V_393 -> V_80 ) ) ;
if ( ( V_537 & V_624 ) == F_392 ( V_625 ) &&
F_4 ( V_207 ) & V_158 ) {
V_393 -> V_293 = true ;
V_537 = F_4 ( F_58 ( V_130 ) ) ;
V_393 -> V_303 = ( ( V_302 & V_537 ) >>
V_613 ) + 1 ;
F_383 ( V_11 , V_393 ) ;
}
F_344 ( V_11 , V_393 ) ;
V_617 = F_393 ( V_11 -> V_76 ) ;
if ( F_64 ( V_2 , V_617 ) )
F_384 ( V_11 , V_393 ) ;
V_393 -> V_379 = F_233 ( V_11 ) &&
( F_4 ( V_380 ) & V_381 ) ;
V_393 -> V_427 = 1 ;
return true ;
}
static int F_394 ( struct V_10 * V_11 ,
int V_226 , int V_227 ,
struct V_233 * V_234 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_626 * V_627 ;
struct V_46 * V_47 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_420 * V_421 =
& V_78 -> V_79 . V_421 ;
struct V_420 * V_338 = & V_78 -> V_79 . V_433 ;
int V_76 = V_78 -> V_76 ;
int V_216 ;
F_395 ( V_2 , V_76 ) ;
V_216 = V_4 -> V_267 . V_628 ( V_11 , V_226 , V_227 , V_234 ) ;
F_396 ( V_2 , V_76 ) ;
if ( V_216 != 0 )
return V_216 ;
F_19 (dev, crtc, encoder) {
F_32 ( L_104 ,
V_47 -> V_113 . V_113 . V_191 ,
F_397 ( & V_47 -> V_113 ) ,
V_338 -> V_113 . V_191 , V_338 -> V_120 ) ;
if ( V_47 -> V_629 ) {
V_47 -> V_629 ( V_47 ) ;
} else {
V_627 = V_47 -> V_113 . V_630 ;
V_627 -> V_629 ( & V_47 -> V_113 , V_338 , V_421 ) ;
}
}
return 0 ;
}
static bool F_398 ( struct V_410 * V_411 ,
int V_631 , T_4 V_632 ,
int V_633 , T_4 V_634 ,
int V_635 )
{
struct V_3 * V_4 = V_411 -> V_2 -> V_5 ;
T_7 * V_636 = V_411 -> V_636 ;
T_4 V_145 ;
V_145 = F_4 ( V_631 ) ;
V_145 &= V_632 ;
if ( ! V_636 [ 0 ] )
return ! V_145 ;
if ( ! V_145 )
return false ;
V_145 = F_4 ( V_633 ) ;
V_145 &= ~ V_634 ;
F_36 ( V_633 , V_145 ) ;
for ( V_145 = 0 ; V_145 < V_636 [ 2 ] ; V_145 ++ )
if ( F_4 ( V_635 ) != * ( ( T_4 * ) V_636 + V_145 ) )
return false ;
return true ;
}
static void F_399 ( struct V_410 * V_411 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = V_411 -> V_2 -> V_5 ;
T_7 * V_636 = V_411 -> V_636 ;
T_4 V_637 ;
T_4 V_638 ;
T_4 V_145 ;
V_145 = F_4 ( V_639 ) ;
if ( V_145 == V_640 || V_145 == V_641 )
V_637 = V_642 ;
else
V_637 = V_643 ;
if ( F_398 ( V_411 ,
V_644 , V_637 ,
V_644 , V_645 ,
V_646 ) )
return;
V_145 = F_4 ( V_644 ) ;
V_145 &= ~ ( V_637 | V_645 ) ;
V_638 = ( V_145 >> 9 ) & 0x1f ;
F_36 ( V_644 , V_145 ) ;
if ( ! V_636 [ 0 ] )
return;
V_638 = F_300 ( T_7 , V_636 [ 2 ] , V_638 ) ;
F_52 ( L_105 , V_638 ) ;
for ( V_145 = 0 ; V_145 < V_638 ; V_145 ++ )
F_36 ( V_646 , * ( ( T_4 * ) V_636 + V_145 ) ) ;
V_145 = F_4 ( V_644 ) ;
V_145 |= V_637 ;
F_36 ( V_644 , V_145 ) ;
}
static void F_400 ( struct V_410 * V_411 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = V_411 -> V_2 -> V_5 ;
T_7 * V_636 = V_411 -> V_636 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
T_4 V_637 ;
T_4 V_145 ;
int V_638 ;
int V_76 = F_27 ( V_11 ) -> V_76 ;
int V_537 ;
int V_647 = F_401 ( V_76 ) ;
int V_648 = F_402 ( V_76 ) ;
int V_649 = F_403 ( V_76 ) ;
int V_650 = V_651 ;
F_52 ( L_106 ) ;
F_52 ( L_107 ) ;
V_537 = F_4 ( V_650 ) ;
V_537 |= ( V_652 << ( V_76 * 4 ) ) ;
F_36 ( V_650 , V_537 ) ;
F_33 ( V_2 , V_76 ) ;
V_537 = F_4 ( V_650 ) ;
F_52 ( L_108 , V_537 ) ;
V_537 |= ( V_653 << ( V_76 * 4 ) ) ;
F_36 ( V_650 , V_537 ) ;
V_537 = F_4 ( V_650 ) ;
F_52 ( L_109 , V_537 ) ;
V_537 = F_4 ( V_649 ) ;
F_52 ( L_110 , V_537 ) ;
V_537 &= ~ ( V_654 | V_655 ) ;
F_36 ( V_649 , V_537 ) ;
F_52 ( L_111 , F_62 ( V_76 ) ) ;
V_637 = V_653 << ( V_76 * 4 ) ;
V_78 -> V_412 = true ;
if ( F_8 ( V_11 , V_355 ) ) {
F_52 ( L_112 ) ;
V_636 [ 5 ] |= ( 1 << 2 ) ;
F_36 ( V_649 , V_654 ) ;
} else
F_36 ( V_649 , 0 ) ;
if ( F_398 ( V_411 ,
V_650 , V_637 ,
V_648 , V_656 ,
V_647 ) )
return;
V_145 = F_4 ( V_650 ) ;
V_145 &= ~ V_637 ;
F_36 ( V_650 , V_145 ) ;
if ( ! V_636 [ 0 ] )
return;
V_145 = F_4 ( V_648 ) ;
V_145 &= ~ V_656 ;
F_36 ( V_648 , V_145 ) ;
V_145 = ( V_145 >> 29 ) & V_657 ;
F_52 ( L_113 , V_145 ) ;
V_638 = F_300 ( T_7 , V_636 [ 2 ] , 21 ) ;
F_52 ( L_105 , V_638 ) ;
for ( V_145 = 0 ; V_145 < V_638 ; V_145 ++ )
F_36 ( V_647 , * ( ( T_4 * ) V_636 + V_145 ) ) ;
V_145 = F_4 ( V_650 ) ;
V_145 |= V_637 ;
F_36 ( V_650 , V_145 ) ;
}
static void F_404 ( struct V_410 * V_411 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = V_411 -> V_2 -> V_5 ;
T_7 * V_636 = V_411 -> V_636 ;
T_4 V_637 ;
T_4 V_145 ;
int V_638 ;
int V_647 ;
int V_649 ;
int V_648 ;
int V_650 ;
int V_76 = F_27 ( V_11 ) -> V_76 ;
if ( F_45 ( V_411 -> V_2 ) ) {
V_647 = F_405 ( V_76 ) ;
V_649 = F_406 ( V_76 ) ;
V_648 = F_407 ( V_76 ) ;
V_650 = V_658 ;
} else {
V_647 = F_408 ( V_76 ) ;
V_649 = F_409 ( V_76 ) ;
V_648 = F_410 ( V_76 ) ;
V_650 = V_659 ;
}
F_52 ( L_111 , F_62 ( V_76 ) ) ;
V_145 = F_4 ( V_648 ) ;
V_145 = ( V_145 >> 29 ) & V_657 ;
if ( ! V_145 ) {
F_52 ( L_114 ) ;
V_637 = V_660 ;
V_637 |= V_660 << 4 ;
V_637 |= V_660 << 8 ;
} else {
F_52 ( L_115 , F_411 ( V_145 ) ) ;
V_637 = V_660 << ( ( V_145 - 1 ) * 4 ) ;
}
if ( F_8 ( V_11 , V_355 ) ) {
F_52 ( L_112 ) ;
V_636 [ 5 ] |= ( 1 << 2 ) ;
F_36 ( V_649 , V_654 ) ;
} else
F_36 ( V_649 , 0 ) ;
if ( F_398 ( V_411 ,
V_650 , V_637 ,
V_648 , V_656 ,
V_647 ) )
return;
V_145 = F_4 ( V_650 ) ;
V_145 &= ~ V_637 ;
F_36 ( V_650 , V_145 ) ;
if ( ! V_636 [ 0 ] )
return;
V_145 = F_4 ( V_648 ) ;
V_145 &= ~ V_656 ;
F_36 ( V_648 , V_145 ) ;
V_638 = F_300 ( T_7 , V_636 [ 2 ] , 21 ) ;
F_52 ( L_105 , V_638 ) ;
for ( V_145 = 0 ; V_145 < V_638 ; V_145 ++ )
F_36 ( V_647 , * ( ( T_4 * ) V_636 + V_145 ) ) ;
V_145 = F_4 ( V_650 ) ;
V_145 |= V_637 ;
F_36 ( V_650 , V_145 ) ;
}
void F_412 ( struct V_416 * V_47 ,
struct V_420 * V_338 )
{
struct V_10 * V_11 = V_47 -> V_11 ;
struct V_410 * V_411 ;
struct V_1 * V_2 = V_47 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_411 = F_413 ( V_47 , V_338 ) ;
if ( ! V_411 )
return;
F_52 ( L_116 ,
V_411 -> V_113 . V_191 ,
F_275 ( V_411 ) ,
V_411 -> V_47 -> V_113 . V_191 ,
F_397 ( V_411 -> V_47 ) ) ;
V_411 -> V_636 [ 6 ] = F_414 ( V_411 , V_338 ) / 2 ;
if ( V_4 -> V_267 . V_661 )
V_4 -> V_267 . V_661 ( V_411 , V_11 ) ;
}
void F_231 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
enum V_76 V_76 = V_78 -> V_76 ;
int V_662 = F_415 ( V_76 ) ;
int V_145 ;
bool V_663 = false ;
if ( ! V_11 -> V_107 || ! V_78 -> V_189 )
return;
if ( ! F_3 ( V_4 -> V_2 ) )
F_116 ( V_4 , V_76 ) ;
if ( F_3 ( V_2 ) )
V_662 = F_416 ( V_76 ) ;
if ( V_78 -> V_79 . V_379 &&
( ( F_4 ( F_374 ( V_76 ) ) & V_664 ) ==
V_665 ) ) {
F_236 ( V_78 ) ;
V_663 = true ;
}
for ( V_145 = 0 ; V_145 < 256 ; V_145 ++ ) {
F_36 ( V_662 + 4 * V_145 ,
( V_78 -> V_666 [ V_145 ] << 16 ) |
( V_78 -> V_667 [ V_145 ] << 8 ) |
V_78 -> V_668 [ V_145 ] ) ;
}
if ( V_663 )
F_235 ( V_78 ) ;
}
static void F_417 ( struct V_10 * V_11 , T_1 V_113 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
bool V_669 = V_113 != 0 ;
T_1 V_386 ;
if ( V_78 -> V_670 == V_669 )
return;
V_386 = F_4 ( V_671 ) ;
if ( V_669 ) {
F_36 ( V_672 , V_113 ) ;
V_386 &= ~ ( V_673 ) ;
V_386 |= V_674 |
V_675 |
V_676 ;
} else
V_386 &= ~ ( V_674 | V_675 ) ;
F_36 ( V_671 , V_386 ) ;
V_78 -> V_670 = V_669 ;
}
static void F_418 ( struct V_10 * V_11 , T_1 V_113 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_76 = V_78 -> V_76 ;
bool V_669 = V_113 != 0 ;
if ( V_78 -> V_670 != V_669 ) {
T_4 V_386 = F_4 ( F_255 ( V_76 ) ) ;
if ( V_113 ) {
V_386 &= ~ ( V_387 | V_677 ) ;
V_386 |= V_391 | V_678 ;
V_386 |= V_76 << 28 ;
} else {
V_386 &= ~ ( V_387 | V_678 ) ;
V_386 |= V_679 ;
}
F_36 ( F_255 ( V_76 ) , V_386 ) ;
V_78 -> V_670 = V_669 ;
}
F_36 ( F_256 ( V_76 ) , V_113 ) ;
}
static void F_419 ( struct V_10 * V_11 , T_1 V_113 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_76 = V_78 -> V_76 ;
bool V_669 = V_113 != 0 ;
if ( V_78 -> V_670 != V_669 ) {
T_4 V_386 = F_4 ( F_420 ( V_76 ) ) ;
if ( V_113 ) {
V_386 &= ~ V_387 ;
V_386 |= V_391 | V_678 ;
} else {
V_386 &= ~ ( V_387 | V_678 ) ;
V_386 |= V_679 ;
}
if ( F_144 ( V_2 ) )
V_386 |= V_680 ;
F_36 ( F_420 ( V_76 ) , V_386 ) ;
V_78 -> V_670 = V_669 ;
}
F_36 ( F_421 ( V_76 ) , V_113 ) ;
}
static void F_232 ( struct V_10 * V_11 ,
bool V_190 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_76 = V_78 -> V_76 ;
int V_226 = V_78 -> V_681 ;
int V_227 = V_78 -> V_682 ;
T_1 V_113 , V_376 ;
bool V_669 ;
V_376 = 0 ;
if ( V_190 && V_11 -> V_107 && V_11 -> V_234 ) {
V_113 = V_78 -> V_683 ;
if ( V_226 > ( int ) V_11 -> V_234 -> V_684 )
V_113 = 0 ;
if ( V_227 > ( int ) V_11 -> V_234 -> V_685 )
V_113 = 0 ;
} else
V_113 = 0 ;
if ( V_226 < 0 ) {
if ( V_226 + V_78 -> V_686 < 0 )
V_113 = 0 ;
V_376 |= V_687 << V_688 ;
V_226 = - V_226 ;
}
V_376 |= V_226 << V_688 ;
if ( V_227 < 0 ) {
if ( V_227 + V_78 -> V_689 < 0 )
V_113 = 0 ;
V_376 |= V_687 << V_690 ;
V_227 = - V_227 ;
}
V_376 |= V_227 << V_690 ;
V_669 = V_113 != 0 ;
if ( ! V_669 && ! V_78 -> V_670 )
return;
if ( F_160 ( V_2 ) || F_144 ( V_2 ) ) {
F_36 ( F_422 ( V_76 ) , V_376 ) ;
F_419 ( V_11 , V_113 ) ;
} else {
F_36 ( F_423 ( V_76 ) , V_376 ) ;
if ( F_424 ( V_2 ) || F_425 ( V_2 ) )
F_417 ( V_11 , V_113 ) ;
else
F_418 ( V_11 , V_113 ) ;
}
}
static int F_426 ( struct V_10 * V_11 ,
struct V_691 * V_692 ,
T_4 V_693 ,
T_4 V_684 , T_4 V_685 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_211 * V_212 ;
T_4 V_694 ;
int V_216 ;
if ( ! V_693 ) {
F_32 ( L_117 ) ;
V_694 = 0 ;
V_212 = NULL ;
F_152 ( & V_2 -> V_283 ) ;
goto V_695;
}
if ( V_684 != 64 || V_685 != 64 ) {
F_109 ( L_118 ) ;
return - V_221 ;
}
V_212 = F_427 ( F_428 ( V_2 , V_692 , V_693 ) ) ;
if ( & V_212 -> V_113 == NULL )
return - V_696 ;
if ( V_212 -> V_113 . V_373 < V_684 * V_685 * 4 ) {
F_109 ( L_119 ) ;
V_216 = - V_697 ;
goto V_698;
}
F_152 ( & V_2 -> V_283 ) ;
if ( ! V_4 -> V_124 -> V_699 ) {
unsigned V_215 ;
if ( V_212 -> V_217 ) {
F_109 ( L_120 ) ;
V_216 = - V_221 ;
goto V_700;
}
V_215 = 0 ;
if ( F_124 ( V_2 ) )
V_215 = 64 * 1024 ;
V_216 = F_130 ( V_212 , V_215 , NULL ) ;
if ( V_216 ) {
F_109 ( L_121 ) ;
goto V_700;
}
V_216 = F_429 ( V_212 ) ;
if ( V_216 ) {
F_109 ( L_122 ) ;
goto V_701;
}
V_694 = V_212 -> V_265 ;
} else {
int V_702 = F_96 ( V_2 ) ? 16 * 1024 : 256 ;
V_216 = F_430 ( V_2 , V_212 ,
( V_78 -> V_76 == 0 ) ? V_703 : V_704 ,
V_702 ) ;
if ( V_216 ) {
F_109 ( L_123 ) ;
goto V_700;
}
V_694 = V_212 -> V_705 -> V_693 -> V_706 ;
}
if ( F_15 ( V_2 ) )
F_36 ( V_707 , ( V_685 << 12 ) | V_684 ) ;
V_695:
if ( V_78 -> V_708 ) {
if ( V_4 -> V_124 -> V_699 ) {
if ( V_78 -> V_708 != V_212 )
F_431 ( V_2 , V_78 -> V_708 ) ;
} else
F_133 ( V_78 -> V_708 ) ;
F_432 ( & V_78 -> V_708 -> V_113 ) ;
}
F_153 ( & V_2 -> V_283 ) ;
V_78 -> V_683 = V_694 ;
V_78 -> V_708 = V_212 ;
V_78 -> V_686 = V_684 ;
V_78 -> V_689 = V_685 ;
F_232 ( V_11 , V_78 -> V_708 != NULL ) ;
return 0 ;
V_701:
F_133 ( V_212 ) ;
V_700:
F_153 ( & V_2 -> V_283 ) ;
V_698:
F_433 ( & V_212 -> V_113 ) ;
return V_216 ;
}
static int F_434 ( struct V_10 * V_11 , int V_226 , int V_227 )
{
struct V_78 * V_78 = F_27 ( V_11 ) ;
V_78 -> V_681 = V_226 ;
V_78 -> V_682 = V_227 ;
F_232 ( V_11 , V_78 -> V_708 != NULL ) ;
return 0 ;
}
void F_435 ( struct V_10 * V_11 , T_5 V_709 , T_5 V_710 ,
T_5 V_711 , int V_712 )
{
struct V_78 * V_78 = F_27 ( V_11 ) ;
V_78 -> V_666 [ V_712 ] = V_709 >> 8 ;
V_78 -> V_667 [ V_712 ] = V_710 >> 8 ;
V_78 -> V_668 [ V_712 ] = V_711 >> 8 ;
}
void F_436 ( struct V_10 * V_11 , T_5 * V_709 , T_5 * V_710 ,
T_5 * V_711 , int V_712 )
{
struct V_78 * V_78 = F_27 ( V_11 ) ;
* V_709 = V_78 -> V_666 [ V_712 ] << 8 ;
* V_710 = V_78 -> V_667 [ V_712 ] << 8 ;
* V_711 = V_78 -> V_668 [ V_712 ] << 8 ;
}
static void F_437 ( struct V_10 * V_11 , T_5 * V_709 , T_5 * V_710 ,
T_5 * V_711 , T_4 V_713 , T_4 V_373 )
{
int V_714 = ( V_713 + V_373 > 256 ) ? 256 : V_713 + V_373 , V_145 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
for ( V_145 = V_713 ; V_145 < V_714 ; V_145 ++ ) {
V_78 -> V_666 [ V_145 ] = V_709 [ V_145 ] >> 8 ;
V_78 -> V_667 [ V_145 ] = V_710 [ V_145 ] >> 8 ;
V_78 -> V_668 [ V_145 ] = V_711 [ V_145 ] >> 8 ;
}
F_231 ( V_11 ) ;
}
static struct V_233 *
F_438 ( struct V_1 * V_2 ,
struct V_715 * V_716 ,
struct V_211 * V_212 )
{
struct V_235 * V_236 ;
int V_216 ;
V_236 = F_439 ( sizeof( * V_236 ) , V_717 ) ;
if ( ! V_236 ) {
F_433 ( & V_212 -> V_113 ) ;
return F_440 ( - V_697 ) ;
}
V_216 = F_441 ( V_2 , V_236 , V_716 , V_212 ) ;
if ( V_216 ) {
F_433 ( & V_212 -> V_113 ) ;
F_272 ( V_236 ) ;
return F_440 ( V_216 ) ;
}
return & V_236 -> V_113 ;
}
static T_1
F_442 ( int V_684 , int V_604 )
{
T_1 V_229 = F_443 ( V_684 * V_604 , 8 ) ;
return F_444 ( V_229 , 64 ) ;
}
static T_1
F_445 ( struct V_420 * V_338 , int V_604 )
{
T_1 V_229 = F_442 ( V_338 -> V_402 , V_604 ) ;
return F_444 ( V_229 * V_338 -> V_404 , V_718 ) ;
}
static struct V_233 *
F_446 ( struct V_1 * V_2 ,
struct V_420 * V_338 ,
int V_719 , int V_604 )
{
struct V_211 * V_212 ;
struct V_715 V_716 = { 0 } ;
V_212 = F_447 ( V_2 ,
F_445 ( V_338 , V_604 ) ) ;
if ( V_212 == NULL )
return F_440 ( - V_697 ) ;
V_716 . V_684 = V_338 -> V_402 ;
V_716 . V_685 = V_338 -> V_404 ;
V_716 . V_262 [ 0 ] = F_442 ( V_716 . V_684 ,
V_604 ) ;
V_716 . V_240 = F_448 ( V_604 , V_719 ) ;
return F_438 ( V_2 , & V_716 , V_212 ) ;
}
static struct V_233 *
F_449 ( struct V_1 * V_2 ,
struct V_420 * V_338 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_211 * V_212 ;
struct V_233 * V_234 ;
if ( V_4 -> V_720 == NULL )
return NULL ;
V_212 = V_4 -> V_720 -> V_721 . V_212 ;
if ( V_212 == NULL )
return NULL ;
V_234 = & V_4 -> V_720 -> V_721 . V_113 ;
if ( V_234 -> V_262 [ 0 ] < F_442 ( V_338 -> V_402 ,
V_234 -> V_263 ) )
return NULL ;
if ( V_212 -> V_113 . V_373 < V_338 -> V_404 * V_234 -> V_262 [ 0 ] )
return NULL ;
return V_234 ;
}
bool F_450 ( struct V_410 * V_411 ,
struct V_420 * V_338 ,
struct V_722 * V_723 )
{
struct V_78 * V_78 ;
struct V_46 * V_46 =
F_277 ( V_411 ) ;
struct V_10 * V_724 ;
struct V_416 * V_47 = & V_46 -> V_113 ;
struct V_10 * V_11 = NULL ;
struct V_1 * V_2 = V_47 -> V_2 ;
struct V_233 * V_234 ;
int V_145 = - 1 ;
F_32 ( L_124 ,
V_411 -> V_113 . V_191 , F_275 ( V_411 ) ,
V_47 -> V_113 . V_191 , F_397 ( V_47 ) ) ;
if ( V_47 -> V_11 ) {
V_11 = V_47 -> V_11 ;
F_152 ( & V_11 -> V_270 ) ;
V_723 -> V_725 = V_411 -> V_414 ;
V_723 -> V_726 = false ;
if ( V_411 -> V_414 != V_417 )
V_411 -> V_727 -> V_414 ( V_411 , V_417 ) ;
return true ;
}
F_149 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_145 ++ ;
if ( ! ( V_47 -> V_728 & ( 1 << V_145 ) ) )
continue;
if ( ! V_724 -> V_107 ) {
V_11 = V_724 ;
break;
}
}
if ( ! V_11 ) {
F_32 ( L_125 ) ;
return false ;
}
F_152 ( & V_11 -> V_270 ) ;
V_46 -> V_729 = F_27 ( V_11 ) ;
F_451 ( V_411 ) -> V_730 = V_46 ;
V_78 = F_27 ( V_11 ) ;
V_723 -> V_725 = V_411 -> V_414 ;
V_723 -> V_726 = true ;
V_723 -> V_731 = NULL ;
if ( ! V_338 )
V_338 = & V_732 ;
V_234 = F_449 ( V_2 , V_338 ) ;
if ( V_234 == NULL ) {
F_32 ( L_126 ) ;
V_234 = F_446 ( V_2 , V_338 , 24 , 32 ) ;
V_723 -> V_731 = V_234 ;
} else
F_32 ( L_127 ) ;
if ( F_452 ( V_234 ) ) {
F_32 ( L_128 ) ;
F_153 ( & V_11 -> V_270 ) ;
return false ;
}
if ( F_453 ( V_11 , V_338 , 0 , 0 , V_234 ) ) {
F_32 ( L_129 ) ;
if ( V_723 -> V_731 )
V_723 -> V_731 -> V_727 -> V_733 ( V_723 -> V_731 ) ;
F_153 ( & V_11 -> V_270 ) ;
return false ;
}
F_33 ( V_2 , V_78 -> V_76 ) ;
return true ;
}
void F_454 ( struct V_410 * V_411 ,
struct V_722 * V_723 )
{
struct V_46 * V_46 =
F_277 ( V_411 ) ;
struct V_416 * V_47 = & V_46 -> V_113 ;
struct V_10 * V_11 = V_47 -> V_11 ;
F_32 ( L_124 ,
V_411 -> V_113 . V_191 , F_275 ( V_411 ) ,
V_47 -> V_113 . V_191 , F_397 ( V_47 ) ) ;
if ( V_723 -> V_726 ) {
F_451 ( V_411 ) -> V_730 = NULL ;
V_46 -> V_729 = NULL ;
F_453 ( V_11 , NULL , 0 , 0 , NULL ) ;
if ( V_723 -> V_731 ) {
F_455 ( V_723 -> V_731 ) ;
F_456 ( V_723 -> V_731 ) ;
}
F_153 ( & V_11 -> V_270 ) ;
return;
}
if ( V_723 -> V_725 != V_417 )
V_411 -> V_727 -> V_414 ( V_411 , V_723 -> V_725 ) ;
F_153 ( & V_11 -> V_270 ) ;
}
static int F_457 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_76 = V_78 -> V_76 ;
T_1 V_44 = F_4 ( F_48 ( V_76 ) ) ;
T_1 V_367 ;
T_3 clock ;
if ( ( V_44 & V_734 ) == 0 )
V_367 = F_4 ( F_308 ( V_76 ) ) ;
else
V_367 = F_4 ( F_309 ( V_76 ) ) ;
clock . V_45 = ( V_367 & V_735 ) >> V_736 ;
if ( F_13 ( V_2 ) ) {
clock . V_42 = F_458 ( ( V_367 & V_737 ) >> V_738 ) - 1 ;
clock . V_37 = ( V_367 & V_739 ) >> V_740 ;
} else {
clock . V_42 = ( V_367 & V_741 ) >> V_738 ;
clock . V_37 = ( V_367 & V_742 ) >> V_740 ;
}
if ( ! F_15 ( V_2 ) ) {
if ( F_13 ( V_2 ) )
clock . V_39 = F_458 ( ( V_44 & V_743 ) >>
V_508 ) ;
else
clock . V_39 = F_458 ( ( V_44 & V_744 ) >>
V_509 ) ;
switch ( V_44 & V_745 ) {
case V_505 :
clock . V_40 = V_44 & V_511 ?
5 : 10 ;
break;
case V_504 :
clock . V_40 = V_44 & V_512 ?
7 : 14 ;
break;
default:
F_32 ( L_130
L_131 , ( int ) ( V_44 & V_745 ) ) ;
return 0 ;
}
if ( F_13 ( V_2 ) )
F_16 ( 96000 , & clock ) ;
else
F_18 ( 96000 , & clock ) ;
} else {
bool V_554 = ( V_76 == 1 ) && ( F_4 ( V_135 ) & V_168 ) ;
if ( V_554 ) {
clock . V_39 = F_458 ( ( V_44 & V_746 ) >>
V_509 ) ;
clock . V_40 = 14 ;
if ( ( V_44 & V_747 ) ==
V_518 ) {
F_18 ( 66000 , & clock ) ;
} else
F_18 ( 48000 , & clock ) ;
} else {
if ( V_44 & V_520 )
clock . V_39 = 2 ;
else {
clock . V_39 = ( ( V_44 & V_748 ) >>
V_509 ) + 2 ;
}
if ( V_44 & V_521 )
clock . V_40 = 4 ;
else
clock . V_40 = 2 ;
F_18 ( 48000 , & clock ) ;
}
}
return clock . V_43 ;
}
struct V_420 * F_459 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
enum V_75 V_80 = V_78 -> V_79 . V_80 ;
struct V_420 * V_338 ;
int V_749 = F_4 ( F_193 ( V_80 ) ) ;
int V_750 = F_4 ( F_197 ( V_80 ) ) ;
int V_751 = F_4 ( F_199 ( V_80 ) ) ;
int V_752 = F_4 ( F_203 ( V_80 ) ) ;
V_338 = F_439 ( sizeof( * V_338 ) , V_717 ) ;
if ( ! V_338 )
return NULL ;
V_338 -> clock = F_457 ( V_2 , V_11 ) ;
V_338 -> V_402 = ( V_749 & 0xffff ) + 1 ;
V_338 -> V_753 = ( ( V_749 & 0xffff0000 ) >> 16 ) + 1 ;
V_338 -> V_436 = ( V_750 & 0xffff ) + 1 ;
V_338 -> V_754 = ( ( V_750 & 0xffff0000 ) >> 16 ) + 1 ;
V_338 -> V_404 = ( V_751 & 0xffff ) + 1 ;
V_338 -> V_755 = ( ( V_751 & 0xffff0000 ) >> 16 ) + 1 ;
V_338 -> V_756 = ( V_752 & 0xffff ) + 1 ;
V_338 -> V_757 = ( ( V_752 & 0xffff0000 ) >> 16 ) + 1 ;
F_460 ( V_338 ) ;
return V_338 ;
}
static void F_147 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_8 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
int V_76 = V_78 -> V_76 ;
int V_758 = F_48 ( V_76 ) ;
int V_44 ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_557 )
return;
V_44 = F_4 ( V_758 ) ;
if ( ! F_346 ( V_2 ) && ( V_44 & V_734 ) ) {
F_52 ( L_132 ) ;
F_61 ( V_4 , V_76 ) ;
V_44 &= ~ V_734 ;
F_36 ( V_758 , V_44 ) ;
F_33 ( V_2 , V_76 ) ;
V_44 = F_4 ( V_758 ) ;
if ( V_44 & V_734 )
F_52 ( L_133 ) ;
}
}
static void F_461 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_8 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_557 )
return;
if ( ! F_346 ( V_2 ) && V_78 -> V_474 ) {
int V_76 = V_78 -> V_76 ;
int V_758 = F_48 ( V_76 ) ;
int V_44 ;
F_52 ( L_134 ) ;
F_61 ( V_4 , V_76 ) ;
V_44 = F_4 ( V_758 ) ;
V_44 |= V_734 ;
F_36 ( V_758 , V_44 ) ;
F_33 ( V_2 , V_76 ) ;
V_44 = F_4 ( V_758 ) ;
if ( ! ( V_44 & V_734 ) )
F_52 ( L_135 ) ;
}
}
void F_462 ( struct V_1 * V_2 )
{
F_463 ( V_2 -> V_5 ) ;
}
void F_464 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
if ( ! V_475 )
return;
F_149 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_11 -> V_234 )
continue;
F_461 ( V_11 ) ;
}
}
void F_465 ( struct V_211 * V_212 ,
struct V_213 * V_759 )
{
struct V_1 * V_2 = V_212 -> V_113 . V_2 ;
struct V_10 * V_11 ;
if ( ! V_475 )
return;
F_149 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_11 -> V_234 )
continue;
if ( F_138 ( V_11 -> V_234 ) -> V_212 != V_212 )
continue;
F_147 ( V_11 ) ;
if ( V_759 && F_466 ( V_2 ) )
V_759 -> V_760 = true ;
}
}
static void F_467 ( struct V_10 * V_11 )
{
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_761 * V_762 ;
unsigned long V_321 ;
F_179 ( & V_2 -> V_325 , V_321 ) ;
V_762 = V_78 -> V_326 ;
V_78 -> V_326 = NULL ;
F_180 ( & V_2 -> V_325 , V_321 ) ;
if ( V_762 ) {
F_468 ( & V_762 -> V_762 ) ;
F_272 ( V_762 ) ;
}
F_426 ( V_11 , NULL , 0 , 0 , 0 ) ;
F_469 ( V_11 ) ;
F_272 ( V_78 ) ;
}
static void F_470 ( struct V_763 * V_764 )
{
struct V_761 * V_762 =
F_471 ( V_764 , struct V_761 , V_762 ) ;
struct V_1 * V_2 = V_762 -> V_11 -> V_2 ;
F_152 ( & V_2 -> V_283 ) ;
F_134 ( V_762 -> V_765 ) ;
F_432 ( & V_762 -> V_766 -> V_113 ) ;
F_432 ( & V_762 -> V_765 -> V_113 ) ;
F_158 ( V_2 ) ;
F_153 ( & V_2 -> V_283 ) ;
F_94 ( F_178 ( & F_27 ( V_762 -> V_11 ) -> V_767 ) == 0 ) ;
F_472 ( & F_27 ( V_762 -> V_11 ) -> V_767 ) ;
F_272 ( V_762 ) ;
}
static void F_473 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_761 * V_762 ;
unsigned long V_321 ;
if ( V_78 == NULL )
return;
F_179 ( & V_2 -> V_325 , V_321 ) ;
V_762 = V_78 -> V_326 ;
F_474 () ;
if ( V_762 == NULL || F_178 ( & V_762 -> V_322 ) < V_768 ) {
F_180 ( & V_2 -> V_325 , V_321 ) ;
return;
}
F_474 () ;
V_78 -> V_326 = NULL ;
if ( V_762 -> V_769 )
F_475 ( V_2 , V_78 -> V_76 , V_762 -> V_769 ) ;
F_476 ( V_2 , V_78 -> V_76 ) ;
F_180 ( & V_2 -> V_325 , V_321 ) ;
F_477 ( & V_4 -> V_327 ) ;
F_478 ( V_4 -> V_770 , & V_762 -> V_762 ) ;
F_479 ( V_78 -> V_143 , V_762 -> V_766 ) ;
}
void F_480 ( struct V_1 * V_2 , int V_76 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_10 * V_11 = V_4 -> V_77 [ V_76 ] ;
F_473 ( V_2 , V_11 ) ;
}
void F_151 ( struct V_1 * V_2 , int V_143 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_10 * V_11 = V_4 -> V_771 [ V_143 ] ;
F_473 ( V_2 , V_11 ) ;
}
void F_150 ( struct V_1 * V_2 , int V_143 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 =
F_27 ( V_4 -> V_771 [ V_143 ] ) ;
unsigned long V_321 ;
F_179 ( & V_2 -> V_325 , V_321 ) ;
if ( V_78 -> V_326 )
F_481 ( & V_78 -> V_326 -> V_322 ) ;
F_180 ( & V_2 -> V_325 , V_321 ) ;
}
inline static void F_482 ( struct V_78 * V_78 )
{
F_483 () ;
F_484 ( & V_78 -> V_326 -> V_322 , V_772 ) ;
F_483 () ;
}
static int F_485 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_233 * V_234 ,
struct V_211 * V_212 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
T_1 V_773 ;
struct V_213 * V_759 = & V_4 -> V_759 [ V_774 ] ;
int V_216 ;
V_216 = F_126 ( V_2 , V_212 , V_759 ) ;
if ( V_216 )
goto V_53;
V_216 = F_486 ( V_759 , 6 ) ;
if ( V_216 )
goto V_225;
if ( V_78 -> V_143 )
V_773 = V_775 ;
else
V_773 = V_776 ;
F_487 ( V_759 , V_777 | V_773 ) ;
F_487 ( V_759 , V_778 ) ;
F_487 ( V_759 , V_779 |
F_488 ( V_78 -> V_143 ) ) ;
F_487 ( V_759 , V_234 -> V_262 [ 0 ] ) ;
F_487 ( V_759 , V_212 -> V_265 + V_78 -> V_264 ) ;
F_487 ( V_759 , 0 ) ;
F_482 ( V_78 ) ;
F_489 ( V_759 ) ;
return 0 ;
V_225:
F_134 ( V_212 ) ;
V_53:
return V_216 ;
}
static int F_490 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_233 * V_234 ,
struct V_211 * V_212 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
T_1 V_773 ;
struct V_213 * V_759 = & V_4 -> V_759 [ V_774 ] ;
int V_216 ;
V_216 = F_126 ( V_2 , V_212 , V_759 ) ;
if ( V_216 )
goto V_53;
V_216 = F_486 ( V_759 , 6 ) ;
if ( V_216 )
goto V_225;
if ( V_78 -> V_143 )
V_773 = V_775 ;
else
V_773 = V_776 ;
F_487 ( V_759 , V_777 | V_773 ) ;
F_487 ( V_759 , V_778 ) ;
F_487 ( V_759 , V_780 |
F_488 ( V_78 -> V_143 ) ) ;
F_487 ( V_759 , V_234 -> V_262 [ 0 ] ) ;
F_487 ( V_759 , V_212 -> V_265 + V_78 -> V_264 ) ;
F_487 ( V_759 , V_778 ) ;
F_482 ( V_78 ) ;
F_489 ( V_759 ) ;
return 0 ;
V_225:
F_134 ( V_212 ) ;
V_53:
return V_216 ;
}
static int F_491 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_233 * V_234 ,
struct V_211 * V_212 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
T_4 V_781 , V_782 ;
struct V_213 * V_759 = & V_4 -> V_759 [ V_774 ] ;
int V_216 ;
V_216 = F_126 ( V_2 , V_212 , V_759 ) ;
if ( V_216 )
goto V_53;
V_216 = F_486 ( V_759 , 4 ) ;
if ( V_216 )
goto V_225;
F_487 ( V_759 , V_779 |
F_488 ( V_78 -> V_143 ) ) ;
F_487 ( V_759 , V_234 -> V_262 [ 0 ] ) ;
F_487 ( V_759 ,
( V_212 -> V_265 + V_78 -> V_264 ) |
V_212 -> V_217 ) ;
V_781 = 0 ;
V_782 = F_4 ( F_343 ( V_78 -> V_76 ) ) & 0x0fff0fff ;
F_487 ( V_759 , V_781 | V_782 ) ;
F_482 ( V_78 ) ;
F_489 ( V_759 ) ;
return 0 ;
V_225:
F_134 ( V_212 ) ;
V_53:
return V_216 ;
}
static int F_492 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_233 * V_234 ,
struct V_211 * V_212 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_213 * V_759 = & V_4 -> V_759 [ V_774 ] ;
T_4 V_781 , V_782 ;
int V_216 ;
V_216 = F_126 ( V_2 , V_212 , V_759 ) ;
if ( V_216 )
goto V_53;
V_216 = F_486 ( V_759 , 4 ) ;
if ( V_216 )
goto V_225;
F_487 ( V_759 , V_779 |
F_488 ( V_78 -> V_143 ) ) ;
F_487 ( V_759 , V_234 -> V_262 [ 0 ] | V_212 -> V_217 ) ;
F_487 ( V_759 , V_212 -> V_265 + V_78 -> V_264 ) ;
V_781 = 0 ;
V_782 = F_4 ( F_343 ( V_78 -> V_76 ) ) & 0x0fff0fff ;
F_487 ( V_759 , V_781 | V_782 ) ;
F_482 ( V_78 ) ;
F_489 ( V_759 ) ;
return 0 ;
V_225:
F_134 ( V_212 ) ;
V_53:
return V_216 ;
}
static int F_493 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_233 * V_234 ,
struct V_211 * V_212 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_213 * V_759 = & V_4 -> V_759 [ V_783 ] ;
T_4 V_784 = 0 ;
int V_216 ;
V_216 = F_126 ( V_2 , V_212 , V_759 ) ;
if ( V_216 )
goto V_53;
switch( V_78 -> V_143 ) {
case V_785 :
V_784 = V_786 ;
break;
case V_787 :
V_784 = V_788 ;
break;
case V_789 :
V_784 = V_790 ;
break;
default:
F_494 ( 1 , L_136 ) ;
V_216 = - V_791 ;
goto V_225;
}
V_216 = F_486 ( V_759 , 4 ) ;
if ( V_216 )
goto V_225;
F_487 ( V_759 , V_780 | V_784 ) ;
F_487 ( V_759 , ( V_234 -> V_262 [ 0 ] | V_212 -> V_217 ) ) ;
F_487 ( V_759 , V_212 -> V_265 + V_78 -> V_264 ) ;
F_487 ( V_759 , ( V_778 ) ) ;
F_482 ( V_78 ) ;
F_489 ( V_759 ) ;
return 0 ;
V_225:
F_134 ( V_212 ) ;
V_53:
return V_216 ;
}
static int F_495 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_233 * V_234 ,
struct V_211 * V_212 )
{
return - V_791 ;
}
static int F_496 ( struct V_10 * V_11 ,
struct V_233 * V_234 ,
struct V_792 * V_769 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_233 * V_271 = V_11 -> V_234 ;
struct V_211 * V_212 = F_138 ( V_234 ) -> V_212 ;
struct V_78 * V_78 = F_27 ( V_11 ) ;
struct V_761 * V_762 ;
unsigned long V_321 ;
int V_216 ;
if ( V_234 -> V_240 != V_11 -> V_234 -> V_240 )
return - V_221 ;
if ( F_35 ( V_2 ) -> V_84 > 3 &&
( V_234 -> V_793 [ 0 ] != V_11 -> V_234 -> V_793 [ 0 ] ||
V_234 -> V_262 [ 0 ] != V_11 -> V_234 -> V_262 [ 0 ] ) )
return - V_221 ;
V_762 = F_439 ( sizeof *V_762 , V_717 ) ;
if ( V_762 == NULL )
return - V_697 ;
V_762 -> V_769 = V_769 ;
V_762 -> V_11 = V_11 ;
V_762 -> V_765 = F_138 ( V_271 ) -> V_212 ;
F_497 ( & V_762 -> V_762 , F_470 ) ;
V_216 = F_498 ( V_2 , V_78 -> V_76 ) ;
if ( V_216 )
goto V_794;
F_179 ( & V_2 -> V_325 , V_321 ) ;
if ( V_78 -> V_326 ) {
F_180 ( & V_2 -> V_325 , V_321 ) ;
F_272 ( V_762 ) ;
F_476 ( V_2 , V_78 -> V_76 ) ;
F_52 ( L_137 ) ;
return - V_795 ;
}
V_78 -> V_326 = V_762 ;
F_180 ( & V_2 -> V_325 , V_321 ) ;
if ( F_178 ( & V_78 -> V_767 ) >= 2 )
F_499 ( V_4 -> V_770 ) ;
V_216 = F_500 ( V_2 ) ;
if ( V_216 )
goto V_796;
F_501 ( & V_762 -> V_765 -> V_113 ) ;
F_501 ( & V_212 -> V_113 ) ;
V_11 -> V_234 = V_234 ;
V_762 -> V_766 = V_212 ;
V_762 -> V_797 = true ;
F_502 ( & V_78 -> V_767 ) ;
V_78 -> V_324 = F_178 ( & V_4 -> V_323 . V_324 ) ;
V_216 = V_4 -> V_267 . V_798 ( V_2 , V_11 , V_234 , V_212 ) ;
if ( V_216 )
goto V_799;
F_244 ( V_2 ) ;
F_465 ( V_212 , NULL ) ;
F_153 ( & V_2 -> V_283 ) ;
F_503 ( V_78 -> V_143 , V_212 ) ;
return 0 ;
V_799:
F_472 ( & V_78 -> V_767 ) ;
V_11 -> V_234 = V_271 ;
F_432 ( & V_762 -> V_765 -> V_113 ) ;
F_432 ( & V_212 -> V_113 ) ;
F_153 ( & V_2 -> V_283 ) ;
V_796:
F_179 ( & V_2 -> V_325 , V_321 ) ;
V_78 -> V_326 = NULL ;
F_180 ( & V_2 -> V_325 , V_321 ) ;
F_476 ( V_2 , V_78 -> V_76 ) ;
V_794:
F_272 ( V_762 ) ;
return V_216 ;
}
static bool F_504 ( struct V_416 * V_47 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_10 * V_537 ;
int V_800 = 1 ;
F_39 ( ! V_11 , L_138 ) ;
V_2 = V_11 -> V_2 ;
F_149 (tmp, &dev->mode_config.crtc_list, head) {
if ( V_537 == V_11 )
break;
V_800 <<= 1 ;
}
if ( V_47 -> V_728 & V_800 )
return true ;
return false ;
}
static void F_505 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
struct V_418 * V_411 ;
F_149 (connector, &dev->mode_config.connector_list,
base.head) {
V_411 -> V_730 =
F_268 ( V_411 -> V_113 . V_47 ) ;
}
F_149 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_47 -> V_729 =
F_27 ( V_47 -> V_113 . V_11 ) ;
}
}
static void F_506 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
struct V_418 * V_411 ;
F_149 (connector, &dev->mode_config.connector_list,
base.head) {
V_411 -> V_113 . V_47 = & V_411 -> V_730 -> V_113 ;
}
F_149 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_47 -> V_113 . V_11 = & V_47 -> V_729 -> V_113 ;
}
}
static void
F_507 ( struct V_418 * V_411 ,
struct V_392 * V_393 )
{
int V_604 = V_393 -> V_428 ;
F_32 ( L_139 ,
V_411 -> V_113 . V_113 . V_191 ,
F_275 ( & V_411 -> V_113 ) ) ;
if ( V_411 -> V_113 . V_801 . V_357 &&
V_411 -> V_113 . V_801 . V_357 * 3 < V_604 ) {
F_32 ( L_140 ,
V_604 , V_411 -> V_113 . V_801 . V_357 * 3 ) ;
V_393 -> V_428 = V_411 -> V_113 . V_801 . V_357 * 3 ;
}
if ( V_411 -> V_113 . V_801 . V_357 == 0 && V_604 > 24 ) {
F_32 ( L_141 ,
V_604 ) ;
V_393 -> V_428 = 24 ;
}
}
static int
F_508 ( struct V_78 * V_11 ,
struct V_233 * V_234 ,
struct V_392 * V_393 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_418 * V_411 ;
int V_604 ;
switch ( V_234 -> V_240 ) {
case V_241 :
V_604 = 8 * 3 ;
break;
case V_243 :
case V_244 :
if ( F_2 ( F_35 ( V_2 ) -> V_84 > 3 ) )
return - V_221 ;
case V_246 :
V_604 = 6 * 3 ;
break;
case V_251 :
case V_252 :
if ( F_2 ( F_35 ( V_2 ) -> V_84 < 4 ) )
return - V_221 ;
case V_248 :
case V_249 :
V_604 = 8 * 3 ;
break;
case V_254 :
case V_255 :
case V_257 :
case V_258 :
if ( F_2 ( F_35 ( V_2 ) -> V_84 < 4 ) )
return - V_221 ;
V_604 = 10 * 3 ;
break;
default:
F_32 ( L_142 ) ;
return - V_221 ;
}
V_393 -> V_428 = V_604 ;
F_149 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_411 -> V_730 ||
V_411 -> V_730 -> V_729 != V_11 )
continue;
F_507 ( V_411 , V_393 ) ;
}
return V_604 ;
}
static void F_509 ( struct V_78 * V_11 ,
struct V_392 * V_393 ,
const char * V_802 )
{
F_32 ( L_143 , V_11 -> V_113 . V_113 . V_191 ,
V_802 , F_62 ( V_11 -> V_76 ) ) ;
F_32 ( L_144 , F_510 ( V_393 -> V_80 ) ) ;
F_32 ( L_145 ,
V_393 -> V_428 , V_393 -> V_541 ) ;
F_32 ( L_146 ,
V_393 -> V_293 ,
V_393 -> V_303 ,
V_393 -> V_429 . V_462 , V_393 -> V_429 . V_463 ,
V_393 -> V_429 . V_464 , V_393 -> V_429 . V_465 ,
V_393 -> V_429 . V_461 ) ;
F_32 ( L_147 ) ;
F_511 ( & V_393 -> V_433 ) ;
F_32 ( L_148 ) ;
F_511 ( & V_393 -> V_421 ) ;
F_32 ( L_149 ,
V_393 -> V_394 . V_395 ,
V_393 -> V_394 . V_399 ,
V_393 -> V_394 . V_563 ) ;
F_32 ( L_150 ,
V_393 -> V_372 . V_376 ,
V_393 -> V_372 . V_373 ) ;
F_32 ( L_151 , V_393 -> V_379 ) ;
}
static bool F_512 ( struct V_10 * V_11 )
{
int V_803 = 0 ;
bool V_804 = false ;
struct V_46 * V_47 ;
F_149 (encoder, &crtc->dev->mode_config.encoder_list,
base.head) {
if ( & V_47 -> V_729 -> V_113 != V_11 )
continue;
V_803 ++ ;
if ( ! V_47 -> V_805 )
V_804 = true ;
}
return ! ( V_803 > 1 && V_804 ) ;
}
static struct V_392 *
F_513 ( struct V_10 * V_11 ,
struct V_233 * V_234 ,
struct V_420 * V_338 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_626 * V_627 ;
struct V_46 * V_47 ;
struct V_392 * V_393 ;
int V_806 , V_216 = - V_221 ;
bool V_308 = true ;
if ( ! F_512 ( V_11 ) ) {
F_32 ( L_152 ) ;
return F_440 ( - V_221 ) ;
}
V_393 = F_439 ( sizeof( * V_393 ) , V_717 ) ;
if ( ! V_393 )
return F_440 ( - V_697 ) ;
F_514 ( & V_393 -> V_421 , V_338 ) ;
F_514 ( & V_393 -> V_433 , V_338 ) ;
V_393 -> V_80 = F_27 ( V_11 ) -> V_76 ;
V_393 -> V_114 = V_366 ;
V_806 = F_508 ( F_27 ( V_11 ) ,
V_234 , V_393 ) ;
if ( V_806 < 0 )
goto V_698;
V_807:
V_393 -> V_494 = 0 ;
V_393 -> V_427 = 1 ;
F_149 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( & V_47 -> V_729 -> V_113 != V_11 )
continue;
if ( V_47 -> V_808 ) {
if ( ! ( V_47 -> V_808 ( V_47 , V_393 ) ) ) {
F_32 ( L_153 ) ;
goto V_698;
}
continue;
}
V_627 = V_47 -> V_113 . V_630 ;
if ( ! ( V_627 -> V_809 ( & V_47 -> V_113 ,
& V_393 -> V_433 ,
& V_393 -> V_421 ) ) ) {
F_32 ( L_154 ) ;
goto V_698;
}
}
if ( ! V_393 -> V_494 )
V_393 -> V_494 = V_393 -> V_421 . clock ;
V_216 = F_287 ( F_27 ( V_11 ) , V_393 ) ;
if ( V_216 < 0 ) {
F_32 ( L_155 ) ;
goto V_698;
}
if ( V_216 == V_431 ) {
if ( F_39 ( ! V_308 , L_156 ) ) {
V_216 = - V_221 ;
goto V_698;
}
F_32 ( L_157 ) ;
V_308 = false ;
goto V_807;
}
V_393 -> V_541 = V_393 -> V_428 != V_806 ;
F_32 ( L_158 ,
V_806 , V_393 -> V_428 , V_393 -> V_541 ) ;
return V_393 ;
V_698:
F_272 ( V_393 ) ;
return F_440 ( V_216 ) ;
}
static void
F_515 ( struct V_10 * V_11 , unsigned * V_810 ,
unsigned * V_811 , unsigned * V_812 )
{
struct V_78 * V_78 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_46 * V_47 ;
struct V_418 * V_411 ;
struct V_10 * V_813 ;
* V_812 = * V_810 = * V_811 = 0 ;
F_149 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_411 -> V_113 . V_47 == & V_411 -> V_730 -> V_113 )
continue;
if ( V_411 -> V_113 . V_47 ) {
V_813 = V_411 -> V_113 . V_47 -> V_11 ;
* V_811 |= 1 << F_27 ( V_813 ) -> V_76 ;
}
if ( V_411 -> V_730 )
* V_811 |=
1 << V_411 -> V_730 -> V_729 -> V_76 ;
}
F_149 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_47 -> V_113 . V_11 == & V_47 -> V_729 -> V_113 )
continue;
if ( V_47 -> V_113 . V_11 ) {
V_813 = V_47 -> V_113 . V_11 ;
* V_811 |= 1 << F_27 ( V_813 ) -> V_76 ;
}
if ( V_47 -> V_729 )
* V_811 |= 1 << V_47 -> V_729 -> V_76 ;
}
F_149 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
bool V_814 = false ;
if ( ! V_78 -> V_113 . V_107 )
continue;
F_149 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_47 -> V_729 == V_78 )
V_814 = true ;
}
if ( ! V_814 )
* V_812 |= 1 << V_78 -> V_76 ;
}
V_78 = F_27 ( V_11 ) ;
if ( V_11 -> V_107 )
* V_811 |= 1 << V_78 -> V_76 ;
if ( * V_811 )
* V_810 = * V_811 ;
* V_810 &= ~ ( * V_812 ) ;
* V_811 &= ~ ( * V_812 ) ;
* V_810 &= 1 << V_78 -> V_76 ;
* V_811 &= 1 << V_78 -> V_76 ;
F_32 ( L_159 ,
* V_810 , * V_811 , * V_812 ) ;
}
static bool F_516 ( struct V_10 * V_11 )
{
struct V_416 * V_47 ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_149 (encoder, &dev->mode_config.encoder_list, head)
if ( V_47 -> V_11 == V_11 )
return true ;
return false ;
}
static void
F_517 ( struct V_1 * V_2 , unsigned V_811 )
{
struct V_46 * V_46 ;
struct V_78 * V_78 ;
struct V_410 * V_411 ;
F_149 (intel_encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_46 -> V_113 . V_11 )
continue;
V_78 = F_27 ( V_46 -> V_113 . V_11 ) ;
if ( V_811 & ( 1 << V_78 -> V_76 ) )
V_46 -> V_407 = false ;
}
F_506 ( V_2 ) ;
F_149 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
V_78 -> V_113 . V_107 = F_516 ( & V_78 -> V_113 ) ;
}
F_149 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_411 -> V_47 || ! V_411 -> V_47 -> V_11 )
continue;
V_78 = F_27 ( V_411 -> V_47 -> V_11 ) ;
if ( V_811 & ( 1 << V_78 -> V_76 ) ) {
struct V_815 * V_816 =
V_2 -> V_568 . V_816 ;
V_411 -> V_414 = V_417 ;
F_518 ( & V_411 -> V_113 ,
V_816 ,
V_417 ) ;
V_46 = F_268 ( V_411 -> V_47 ) ;
V_46 -> V_407 = true ;
}
}
}
static bool
F_519 ( struct V_1 * V_2 ,
struct V_392 * V_817 ,
struct V_392 * V_393 )
{
#define F_520 ( V_120 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_521 ( V_120 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_522 ( V_120 , T_9 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
return false; \
}
#define F_523 ( T_10 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_521 ( V_80 ) ;
F_521 ( V_293 ) ;
F_521 ( V_303 ) ;
F_521 ( V_429 . V_462 ) ;
F_521 ( V_429 . V_463 ) ;
F_521 ( V_429 . V_464 ) ;
F_521 ( V_429 . V_465 ) ;
F_521 ( V_429 . V_461 ) ;
F_521 ( V_421 . V_528 ) ;
F_521 ( V_421 . V_527 ) ;
F_521 ( V_421 . V_529 ) ;
F_521 ( V_421 . V_530 ) ;
F_521 ( V_421 . V_526 ) ;
F_521 ( V_421 . V_531 ) ;
F_521 ( V_421 . V_532 ) ;
F_521 ( V_421 . V_523 ) ;
F_521 ( V_421 . V_533 ) ;
F_521 ( V_421 . V_524 ) ;
F_521 ( V_421 . V_534 ) ;
F_521 ( V_421 . V_535 ) ;
if ( ! F_3 ( V_2 ) )
F_521 ( V_427 ) ;
F_522 ( V_421 . V_321 ,
V_525 ) ;
if ( ! F_523 ( V_818 ) ) {
F_522 ( V_421 . V_321 ,
V_362 ) ;
F_522 ( V_421 . V_321 ,
V_819 ) ;
F_522 ( V_421 . V_321 ,
V_364 ) ;
F_522 ( V_421 . V_321 ,
V_820 ) ;
}
F_521 ( V_433 . V_402 ) ;
F_521 ( V_433 . V_404 ) ;
F_521 ( V_394 . V_395 ) ;
if ( F_35 ( V_2 ) -> V_84 < 4 )
F_521 ( V_394 . V_399 ) ;
F_521 ( V_394 . V_563 ) ;
F_521 ( V_372 . V_376 ) ;
F_521 ( V_372 . V_373 ) ;
F_521 ( V_379 ) ;
F_521 ( V_114 ) ;
F_520 ( V_370 . V_44 ) ;
F_520 ( V_370 . V_609 ) ;
F_520 ( V_370 . V_610 ) ;
#undef F_520
#undef F_521
#undef F_522
#undef F_523
return true ;
}
static void
F_524 ( struct V_1 * V_2 )
{
struct V_418 * V_411 ;
F_149 (connector, &dev->mode_config.connector_list,
base.head) {
F_274 ( V_411 ) ;
F_39 ( & V_411 -> V_730 -> V_113 != V_411 -> V_113 . V_47 ,
L_160 ) ;
}
}
static void
F_525 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
struct V_418 * V_411 ;
F_149 (encoder, &dev->mode_config.encoder_list,
base.head) {
bool V_107 = false ;
bool V_189 = false ;
enum V_76 V_76 , V_821 ;
F_32 ( L_161 ,
V_47 -> V_113 . V_113 . V_191 ,
F_397 ( & V_47 -> V_113 ) ) ;
F_39 ( & V_47 -> V_729 -> V_113 != V_47 -> V_113 . V_11 ,
L_162 ) ;
F_39 ( V_47 -> V_407 && ! V_47 -> V_113 . V_11 ,
L_163 ) ;
F_149 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_411 -> V_113 . V_47 != & V_47 -> V_113 )
continue;
V_107 = true ;
if ( V_411 -> V_113 . V_414 != V_415 )
V_189 = true ;
}
F_39 ( ! ! V_47 -> V_113 . V_11 != V_107 ,
L_164
L_165 ,
! ! V_47 -> V_113 . V_11 , V_107 ) ;
F_39 ( V_189 && ! V_47 -> V_113 . V_11 ,
L_166 ) ;
F_39 ( V_47 -> V_407 != V_189 ,
L_167
L_165 , V_189 , V_47 -> V_407 ) ;
V_189 = V_47 -> V_119 ( V_47 , & V_76 ) ;
F_39 ( V_189 != V_47 -> V_407 ,
L_168
L_165 ,
V_47 -> V_407 , V_189 ) ;
if ( ! V_47 -> V_113 . V_11 )
continue;
V_821 = F_27 ( V_47 -> V_113 . V_11 ) -> V_76 ;
F_39 ( V_189 && V_76 != V_821 ,
L_169
L_165 ,
V_821 , V_76 ) ;
}
}
static void
F_526 ( struct V_1 * V_2 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_78 * V_11 ;
struct V_46 * V_47 ;
struct V_392 V_393 ;
F_149 (crtc, &dev->mode_config.crtc_list,
base.head) {
bool V_107 = false ;
bool V_189 = false ;
memset ( & V_393 , 0 , sizeof( V_393 ) ) ;
F_32 ( L_170 ,
V_11 -> V_113 . V_113 . V_191 ) ;
F_39 ( V_11 -> V_189 && ! V_11 -> V_113 . V_107 ,
L_171 ) ;
F_149 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_47 -> V_113 . V_11 != & V_11 -> V_113 )
continue;
V_107 = true ;
if ( V_47 -> V_407 )
V_189 = true ;
}
F_39 ( V_189 != V_11 -> V_189 ,
L_172
L_165 , V_189 , V_11 -> V_189 ) ;
F_39 ( V_107 != V_11 -> V_113 . V_107 ,
L_173
L_165 , V_107 , V_11 -> V_113 . V_107 ) ;
V_189 = V_4 -> V_267 . V_822 ( V_11 ,
& V_393 ) ;
if ( V_11 -> V_76 == V_130 && V_4 -> V_140 & V_141 )
V_189 = V_11 -> V_189 ;
F_149 (encoder, &dev->mode_config.encoder_list,
base.head) {
enum V_76 V_76 ;
if ( V_47 -> V_113 . V_11 != & V_11 -> V_113 )
continue;
if ( V_47 -> V_823 &&
V_47 -> V_119 ( V_47 , & V_76 ) )
V_47 -> V_823 ( V_47 , & V_393 ) ;
}
F_39 ( V_11 -> V_189 != V_189 ,
L_174
L_165 , V_11 -> V_189 , V_189 ) ;
if ( V_189 &&
! F_519 ( V_2 , & V_11 -> V_79 , & V_393 ) ) {
F_39 ( 1 , L_175 ) ;
F_509 ( V_11 , & V_393 ,
L_176 ) ;
F_509 ( V_11 , & V_11 -> V_79 ,
L_177 ) ;
}
}
}
static void
F_527 ( struct V_1 * V_2 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_78 * V_11 ;
struct V_117 V_370 ;
int V_145 ;
for ( V_145 = 0 ; V_145 < V_4 -> V_369 ; V_145 ++ ) {
struct V_112 * V_116 = & V_4 -> V_115 [ V_145 ] ;
int V_824 = 0 , V_825 = 0 ;
bool V_189 ;
memset ( & V_370 , 0 , sizeof( V_370 ) ) ;
F_32 ( L_178 , V_116 -> V_120 ) ;
V_189 = V_116 -> V_119 ( V_4 , V_116 , & V_370 ) ;
F_39 ( V_116 -> V_189 > V_116 -> V_188 ,
L_179 ,
V_116 -> V_189 , V_116 -> V_188 ) ;
F_39 ( V_116 -> V_189 && ! V_116 -> V_190 ,
L_180 ) ;
F_39 ( V_116 -> V_190 && ! V_116 -> V_189 ,
L_181 ) ;
F_39 ( V_116 -> V_190 != V_189 ,
L_182 ,
V_116 -> V_190 , V_189 ) ;
F_149 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_11 -> V_113 . V_107 && F_49 ( V_11 ) == V_116 )
V_824 ++ ;
if ( V_11 -> V_189 && F_49 ( V_11 ) == V_116 )
V_825 ++ ;
}
F_39 ( V_116 -> V_189 != V_825 ,
L_183 ,
V_116 -> V_189 , V_825 ) ;
F_39 ( V_116 -> V_188 != V_824 ,
L_184 ,
V_116 -> V_188 , V_824 ) ;
F_39 ( V_116 -> V_190 && memcmp ( & V_116 -> V_118 , & V_370 ,
sizeof( V_370 ) ) ,
L_185 ) ;
}
}
void
F_278 ( struct V_1 * V_2 )
{
F_524 ( V_2 ) ;
F_525 ( V_2 ) ;
F_526 ( V_2 ) ;
F_527 ( V_2 ) ;
}
static int F_528 ( struct V_10 * V_11 ,
struct V_420 * V_338 ,
int V_226 , int V_227 , struct V_233 * V_234 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_8 * V_4 = V_2 -> V_5 ;
struct V_420 * V_826 , * V_827 ;
struct V_392 * V_393 = NULL ;
struct V_78 * V_78 ;
unsigned V_812 , V_811 , V_810 ;
int V_216 = 0 ;
V_826 = F_529 ( 2 * sizeof( * V_826 ) , V_717 ) ;
if ( ! V_826 )
return - V_697 ;
V_827 = V_826 + 1 ;
F_515 ( V_11 , & V_810 ,
& V_811 , & V_812 ) ;
* V_827 = V_11 -> V_828 ;
* V_826 = V_11 -> V_338 ;
if ( V_810 ) {
V_393 = F_513 ( V_11 , V_234 , V_338 ) ;
if ( F_452 ( V_393 ) ) {
V_216 = F_530 ( V_393 ) ;
V_393 = NULL ;
goto V_829;
}
F_509 ( F_27 ( V_11 ) , V_393 ,
L_186 ) ;
}
F_531 (dev, disable_pipes, intel_crtc)
F_266 ( & V_78 -> V_113 ) ;
F_531 (dev, prepare_pipes, intel_crtc) {
if ( V_78 -> V_113 . V_107 )
V_4 -> V_267 . V_409 ( & V_78 -> V_113 ) ;
}
if ( V_810 ) {
V_11 -> V_338 = * V_338 ;
F_27 ( V_11 ) -> V_79 = * V_393 ;
}
F_517 ( V_2 , V_811 ) ;
if ( V_4 -> V_267 . V_830 )
V_4 -> V_267 . V_830 ( V_2 ) ;
F_531 (dev, modeset_pipes, intel_crtc) {
V_216 = F_394 ( & V_78 -> V_113 ,
V_226 , V_227 , V_234 ) ;
if ( V_216 )
goto V_831;
}
F_531 (dev, prepare_pipes, intel_crtc)
V_4 -> V_267 . V_408 ( & V_78 -> V_113 ) ;
if ( V_810 ) {
V_11 -> V_828 = V_393 -> V_421 ;
F_532 ( V_11 ) ;
}
V_831:
if ( V_216 && V_11 -> V_107 ) {
V_11 -> V_828 = * V_827 ;
V_11 -> V_338 = * V_826 ;
}
V_829:
F_272 ( V_393 ) ;
F_272 ( V_826 ) ;
return V_216 ;
}
int F_453 ( struct V_10 * V_11 ,
struct V_420 * V_338 ,
int V_226 , int V_227 , struct V_233 * V_234 )
{
int V_216 ;
V_216 = F_528 ( V_11 , V_338 , V_226 , V_227 , V_234 ) ;
if ( V_216 == 0 )
F_278 ( V_11 -> V_2 ) ;
return V_216 ;
}
void F_533 ( struct V_10 * V_11 )
{
F_453 ( V_11 , & V_11 -> V_338 , V_11 -> V_226 , V_11 -> V_227 , V_11 -> V_234 ) ;
}
static void F_534 ( struct V_832 * V_79 )
{
if ( ! V_79 )
return;
F_272 ( V_79 -> V_833 ) ;
F_272 ( V_79 -> V_834 ) ;
F_272 ( V_79 ) ;
}
static int F_535 ( struct V_1 * V_2 ,
struct V_832 * V_79 )
{
struct V_416 * V_47 ;
struct V_410 * V_411 ;
int V_835 ;
V_79 -> V_834 =
F_536 ( V_2 -> V_568 . V_836 ,
sizeof( struct V_10 * ) , V_717 ) ;
if ( ! V_79 -> V_834 )
return - V_697 ;
V_79 -> V_833 =
F_536 ( V_2 -> V_568 . V_837 ,
sizeof( struct V_416 * ) , V_717 ) ;
if ( ! V_79 -> V_833 )
return - V_697 ;
V_835 = 0 ;
F_149 (encoder, &dev->mode_config.encoder_list, head) {
V_79 -> V_834 [ V_835 ++ ] = V_47 -> V_11 ;
}
V_835 = 0 ;
F_149 (connector, &dev->mode_config.connector_list, head) {
V_79 -> V_833 [ V_835 ++ ] = V_411 -> V_47 ;
}
return 0 ;
}
static void F_537 ( struct V_1 * V_2 ,
struct V_832 * V_79 )
{
struct V_46 * V_47 ;
struct V_418 * V_411 ;
int V_835 ;
V_835 = 0 ;
F_149 (encoder, &dev->mode_config.encoder_list, base.head) {
V_47 -> V_729 =
F_27 ( V_79 -> V_834 [ V_835 ++ ] ) ;
}
V_835 = 0 ;
F_149 (connector, &dev->mode_config.connector_list, base.head) {
V_411 -> V_730 =
F_268 ( V_79 -> V_833 [ V_835 ++ ] ) ;
}
}
static bool
F_538 ( struct V_838 * V_839 )
{
int V_145 ;
if ( V_839 -> V_470 == 0 )
return false ;
if ( F_2 ( V_839 -> V_840 == NULL ) )
return false ;
for ( V_145 = 0 ; V_145 < V_839 -> V_470 ; V_145 ++ )
if ( V_839 -> V_840 [ V_145 ] -> V_47 &&
V_839 -> V_840 [ V_145 ] -> V_47 -> V_11 == V_839 -> V_11 &&
V_839 -> V_840 [ V_145 ] -> V_414 != V_417 )
return true ;
return false ;
}
static void
F_539 ( struct V_838 * V_839 ,
struct V_832 * V_79 )
{
if ( F_538 ( V_839 ) ) {
V_79 -> V_841 = true ;
} else if ( V_839 -> V_11 -> V_234 != V_839 -> V_234 ) {
if ( V_839 -> V_11 -> V_234 == NULL ) {
F_32 ( L_187 ) ;
V_79 -> V_841 = true ;
} else if ( V_839 -> V_234 == NULL ) {
V_79 -> V_841 = true ;
} else if ( V_839 -> V_234 -> V_240 !=
V_839 -> V_11 -> V_234 -> V_240 ) {
V_79 -> V_841 = true ;
} else {
V_79 -> V_842 = true ;
}
}
if ( V_839 -> V_234 && ( V_839 -> V_226 != V_839 -> V_11 -> V_226 || V_839 -> V_227 != V_839 -> V_11 -> V_227 ) )
V_79 -> V_842 = true ;
if ( V_839 -> V_338 && ! F_540 ( V_839 -> V_338 , & V_839 -> V_11 -> V_338 ) ) {
F_32 ( L_188 ) ;
F_511 ( & V_839 -> V_11 -> V_338 ) ;
F_511 ( V_839 -> V_338 ) ;
V_79 -> V_841 = true ;
}
}
static int
F_541 ( struct V_1 * V_2 ,
struct V_838 * V_839 ,
struct V_832 * V_79 )
{
struct V_10 * V_729 ;
struct V_418 * V_411 ;
struct V_46 * V_47 ;
int V_835 , V_843 ;
F_2 ( ! V_839 -> V_234 && ( V_839 -> V_470 != 0 ) ) ;
F_2 ( V_839 -> V_234 && ( V_839 -> V_470 == 0 ) ) ;
V_835 = 0 ;
F_149 (connector, &dev->mode_config.connector_list,
base.head) {
for ( V_843 = 0 ; V_843 < V_839 -> V_470 ; V_843 ++ ) {
if ( V_839 -> V_840 [ V_843 ] == & V_411 -> V_113 ) {
V_411 -> V_730 = V_411 -> V_47 ;
break;
}
}
if ( ( ! V_839 -> V_234 || V_843 == V_839 -> V_470 ) &&
V_411 -> V_113 . V_47 &&
V_411 -> V_113 . V_47 -> V_11 == V_839 -> V_11 ) {
V_411 -> V_730 = NULL ;
F_32 ( L_189 ,
V_411 -> V_113 . V_113 . V_191 ,
F_275 ( & V_411 -> V_113 ) ) ;
}
if ( & V_411 -> V_730 -> V_113 != V_411 -> V_113 . V_47 ) {
F_32 ( L_190 ) ;
V_79 -> V_841 = true ;
}
}
V_835 = 0 ;
F_149 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_411 -> V_730 )
continue;
V_729 = V_411 -> V_730 -> V_113 . V_11 ;
for ( V_843 = 0 ; V_843 < V_839 -> V_470 ; V_843 ++ ) {
if ( V_839 -> V_840 [ V_843 ] == & V_411 -> V_113 )
V_729 = V_839 -> V_11 ;
}
if ( ! F_504 ( & V_411 -> V_730 -> V_113 ,
V_729 ) ) {
return - V_221 ;
}
V_411 -> V_47 -> V_729 = F_27 ( V_729 ) ;
F_32 ( L_191 ,
V_411 -> V_113 . V_113 . V_191 ,
F_275 ( & V_411 -> V_113 ) ,
V_729 -> V_113 . V_191 ) ;
}
F_149 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_149 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_411 -> V_730 == V_47 ) {
F_2 ( ! V_411 -> V_730 -> V_729 ) ;
goto V_844;
}
}
V_47 -> V_729 = NULL ;
V_844:
if ( & V_47 -> V_729 -> V_113 != V_47 -> V_113 . V_11 ) {
F_32 ( L_192 ) ;
V_79 -> V_841 = true ;
}
}
return 0 ;
}
static int F_542 ( struct V_838 * V_839 )
{
struct V_1 * V_2 ;
struct V_838 V_845 ;
struct V_832 * V_79 ;
int V_216 ;
F_94 ( ! V_839 ) ;
F_94 ( ! V_839 -> V_11 ) ;
F_94 ( ! V_839 -> V_11 -> V_630 ) ;
F_94 ( ! V_839 -> V_338 && V_839 -> V_234 ) ;
F_94 ( V_839 -> V_234 && V_839 -> V_470 == 0 ) ;
if ( V_839 -> V_234 ) {
F_32 ( L_193 ,
V_839 -> V_11 -> V_113 . V_191 , V_839 -> V_234 -> V_113 . V_191 ,
( int ) V_839 -> V_470 , V_839 -> V_226 , V_839 -> V_227 ) ;
} else {
F_32 ( L_194 , V_839 -> V_11 -> V_113 . V_191 ) ;
}
V_2 = V_839 -> V_11 -> V_2 ;
V_216 = - V_697 ;
V_79 = F_439 ( sizeof( * V_79 ) , V_717 ) ;
if ( ! V_79 )
goto V_846;
V_216 = F_535 ( V_2 , V_79 ) ;
if ( V_216 )
goto V_846;
V_845 . V_11 = V_839 -> V_11 ;
V_845 . V_338 = & V_839 -> V_11 -> V_338 ;
V_845 . V_226 = V_839 -> V_11 -> V_226 ;
V_845 . V_227 = V_839 -> V_11 -> V_227 ;
V_845 . V_234 = V_839 -> V_11 -> V_234 ;
F_539 ( V_839 , V_79 ) ;
V_216 = F_541 ( V_2 , V_839 , V_79 ) ;
if ( V_216 )
goto V_698;
if ( V_79 -> V_841 ) {
V_216 = F_453 ( V_839 -> V_11 , V_839 -> V_338 ,
V_839 -> V_226 , V_839 -> V_227 , V_839 -> V_234 ) ;
} else if ( V_79 -> V_842 ) {
F_181 ( V_839 -> V_11 ) ;
V_216 = F_157 ( V_839 -> V_11 ,
V_839 -> V_226 , V_839 -> V_227 , V_839 -> V_234 ) ;
}
if ( V_216 ) {
F_32 ( L_195 ,
V_839 -> V_11 -> V_113 . V_191 , V_216 ) ;
V_698:
F_537 ( V_2 , V_79 ) ;
if ( V_79 -> V_841 &&
F_453 ( V_845 . V_11 , V_845 . V_338 ,
V_845 . V_226 , V_845 . V_227 , V_845 . V_234 ) )
F_109 ( L_196 ) ;
}
V_846:
F_534 ( V_79 ) ;
return V_216 ;
}
static void F_543 ( struct V_1 * V_2 )
{
if ( F_54 ( V_2 ) )
F_544 ( V_2 ) ;
}
static bool F_545 ( struct V_3 * V_4 ,
struct V_112 * V_116 ,
struct V_117 * V_118 )
{
T_4 V_109 ;
V_109 = F_4 ( F_215 ( V_116 -> V_191 ) ) ;
V_118 -> V_44 = V_109 ;
V_118 -> V_609 = F_4 ( F_216 ( V_116 -> V_191 ) ) ;
V_118 -> V_610 = F_4 ( F_382 ( V_116 -> V_191 ) ) ;
return V_109 & V_111 ;
}
static void F_546 ( struct V_3 * V_4 ,
struct V_112 * V_116 )
{
T_4 V_86 , V_109 ;
F_75 ( V_4 ) ;
V_86 = F_215 ( V_116 -> V_191 ) ;
V_109 = F_4 ( V_86 ) ;
V_109 |= V_111 ;
F_36 ( V_86 , V_109 ) ;
F_97 ( V_86 ) ;
F_98 ( 200 ) ;
}
static void F_547 ( struct V_3 * V_4 ,
struct V_112 * V_116 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_78 * V_11 ;
T_4 V_86 , V_109 ;
F_149 (crtc, &dev->mode_config.crtc_list, base.head) {
if ( F_49 ( V_11 ) == V_116 )
F_76 ( V_4 , V_11 -> V_76 ) ;
}
V_86 = F_215 ( V_116 -> V_191 ) ;
V_109 = F_4 ( V_86 ) ;
V_109 &= ~ V_111 ;
F_36 ( V_86 , V_109 ) ;
F_97 ( V_86 ) ;
F_98 ( 200 ) ;
}
static void F_548 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_145 ;
V_4 -> V_369 = 2 ;
for ( V_145 = 0 ; V_145 < V_4 -> V_369 ; V_145 ++ ) {
V_4 -> V_115 [ V_145 ] . V_191 = V_145 ;
V_4 -> V_115 [ V_145 ] . V_120 = V_847 [ V_145 ] ;
V_4 -> V_115 [ V_145 ] . V_192 = F_546 ;
V_4 -> V_115 [ V_145 ] . V_193 = F_547 ;
V_4 -> V_115 [ V_145 ] . V_119 =
F_545 ;
}
}
static void F_549 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_45 ( V_2 ) || F_79 ( V_2 ) )
F_548 ( V_2 ) ;
else
V_4 -> V_369 = 0 ;
F_94 ( V_4 -> V_369 > V_848 ) ;
F_32 ( L_197 ,
V_4 -> V_369 ) ;
}
static void F_550 ( struct V_1 * V_2 , int V_76 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_78 * V_78 ;
int V_145 ;
V_78 = F_439 ( sizeof( struct V_78 ) + ( V_849 * sizeof( struct V_410 * ) ) , V_717 ) ;
if ( V_78 == NULL )
return;
F_551 ( V_2 , & V_78 -> V_113 , & V_850 ) ;
F_552 ( & V_78 -> V_113 , 256 ) ;
for ( V_145 = 0 ; V_145 < 256 ; V_145 ++ ) {
V_78 -> V_666 [ V_145 ] = V_145 ;
V_78 -> V_667 [ V_145 ] = V_145 ;
V_78 -> V_668 [ V_145 ] = V_145 ;
}
V_78 -> V_76 = V_76 ;
V_78 -> V_143 = V_76 ;
if ( F_95 ( V_2 ) && F_553 ( V_2 ) ) {
F_32 ( L_198 ) ;
V_78 -> V_143 = ! V_76 ;
}
F_94 ( V_76 >= F_554 ( V_4 -> V_771 ) ||
V_4 -> V_771 [ V_78 -> V_143 ] != NULL ) ;
V_4 -> V_771 [ V_78 -> V_143 ] = & V_78 -> V_113 ;
V_4 -> V_77 [ V_78 -> V_76 ] = & V_78 -> V_113 ;
F_555 ( & V_78 -> V_113 , & V_851 ) ;
}
int F_556 ( struct V_1 * V_2 , void * V_852 ,
struct V_691 * V_692 )
{
struct V_853 * V_854 = V_852 ;
struct V_855 * V_856 ;
struct V_78 * V_11 ;
if ( ! F_557 ( V_2 , V_857 ) )
return - V_791 ;
V_856 = F_558 ( V_2 , V_854 -> V_858 ,
V_859 ) ;
if ( ! V_856 ) {
F_109 ( L_199 ) ;
return - V_221 ;
}
V_11 = F_27 ( F_559 ( V_856 ) ) ;
V_854 -> V_76 = V_11 -> V_76 ;
return 0 ;
}
static int F_560 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_113 . V_2 ;
struct V_46 * V_860 ;
int V_861 = 0 ;
int V_862 = 0 ;
F_149 (source_encoder,
&dev->mode_config.encoder_list, base.head) {
if ( V_47 == V_860 )
V_861 |= ( 1 << V_862 ) ;
if ( V_47 -> V_805 && V_860 -> V_805 )
V_861 |= ( 1 << V_862 ) ;
V_862 ++ ;
}
return V_861 ;
}
static bool F_561 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_95 ( V_2 ) )
return false ;
if ( ( F_4 ( V_863 ) & V_864 ) == 0 )
return false ;
if ( F_6 ( V_2 ) &&
( F_4 ( V_865 ) & V_866 ) )
return false ;
return true ;
}
static void F_562 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_46 * V_47 ;
bool V_867 = false ;
F_563 ( V_2 ) ;
if ( ! F_564 ( V_2 ) )
F_565 ( V_2 ) ;
if ( F_54 ( V_2 ) ) {
int V_59 ;
V_59 = F_4 ( V_868 ) & V_869 ;
if ( V_59 )
F_566 ( V_2 , V_575 ) ;
V_59 = F_4 ( V_870 ) ;
if ( V_59 & V_871 )
F_566 ( V_2 , V_97 ) ;
if ( V_59 & V_872 )
F_566 ( V_2 , V_99 ) ;
if ( V_59 & V_873 )
F_566 ( V_2 , V_101 ) ;
} else if ( F_3 ( V_2 ) ) {
int V_59 ;
V_867 = F_567 ( V_2 ) ;
if ( F_561 ( V_2 ) )
F_568 ( V_2 , V_863 , V_575 ) ;
if ( F_4 ( V_182 ) & V_874 ) {
V_59 = F_569 ( V_2 , V_875 , true ) ;
if ( ! V_59 )
F_570 ( V_2 , V_182 , V_97 ) ;
if ( ! V_59 && ( F_4 ( V_175 ) & V_864 ) )
F_568 ( V_2 , V_175 , V_97 ) ;
}
if ( F_4 ( V_183 ) & V_874 )
F_570 ( V_2 , V_183 , V_99 ) ;
if ( ! V_867 && F_4 ( V_184 ) & V_874 )
F_570 ( V_2 , V_184 , V_101 ) ;
if ( F_4 ( V_177 ) & V_864 )
F_568 ( V_2 , V_177 , V_99 ) ;
if ( F_4 ( V_179 ) & V_864 )
F_568 ( V_2 , V_179 , V_101 ) ;
} else if ( F_14 ( V_2 ) ) {
if ( F_4 ( V_876 + V_877 ) & V_864 )
F_568 ( V_2 , V_876 + V_877 , V_99 ) ;
if ( F_4 ( V_876 + V_878 ) & V_874 ) {
F_570 ( V_2 , V_876 + V_878 ,
V_97 ) ;
if ( F_4 ( V_876 + V_879 ) & V_864 )
F_568 ( V_2 , V_876 + V_879 , V_97 ) ;
}
} else if ( F_571 ( V_2 ) ) {
bool V_59 = false ;
if ( F_4 ( V_880 ) & V_874 ) {
F_32 ( L_200 ) ;
V_59 = F_569 ( V_2 , V_880 , true ) ;
if ( ! V_59 && F_572 ( V_2 ) ) {
F_32 ( L_201 ) ;
F_570 ( V_2 , V_878 , V_97 ) ;
}
if ( ! V_59 && F_573 ( V_2 ) )
F_568 ( V_2 , V_879 , V_97 ) ;
}
if ( F_4 ( V_880 ) & V_874 ) {
F_32 ( L_202 ) ;
V_59 = F_569 ( V_2 , V_881 , false ) ;
}
if ( ! V_59 && ( F_4 ( V_881 ) & V_874 ) ) {
if ( F_572 ( V_2 ) ) {
F_32 ( L_203 ) ;
F_570 ( V_2 , V_882 , V_99 ) ;
}
if ( F_573 ( V_2 ) )
F_568 ( V_2 , V_877 , V_99 ) ;
}
if ( F_573 ( V_2 ) &&
( F_4 ( V_883 ) & V_864 ) )
F_568 ( V_2 , V_883 , V_101 ) ;
} else if ( F_15 ( V_2 ) )
F_574 ( V_2 ) ;
if ( F_575 ( V_2 ) )
F_576 ( V_2 ) ;
F_149 (encoder, &dev->mode_config.encoder_list, base.head) {
V_47 -> V_113 . V_728 = V_47 -> V_800 ;
V_47 -> V_113 . V_884 =
F_560 ( V_47 ) ;
}
F_356 ( V_2 ) ;
F_577 ( V_2 ) ;
}
static void F_578 ( struct V_233 * V_234 )
{
struct V_235 * V_236 = F_138 ( V_234 ) ;
F_579 ( V_234 ) ;
F_433 ( & V_236 -> V_212 -> V_113 ) ;
F_272 ( V_236 ) ;
}
static int F_580 ( struct V_233 * V_234 ,
struct V_691 * V_692 ,
unsigned int * V_693 )
{
struct V_235 * V_236 = F_138 ( V_234 ) ;
struct V_211 * V_212 = V_236 -> V_212 ;
return F_581 ( V_692 , & V_212 -> V_113 , V_693 ) ;
}
int F_441 ( struct V_1 * V_2 ,
struct V_235 * V_236 ,
struct V_715 * V_716 ,
struct V_211 * V_212 )
{
int V_885 ;
int V_216 ;
if ( V_212 -> V_217 == V_220 ) {
F_582 ( L_204 ) ;
return - V_221 ;
}
if ( V_716 -> V_262 [ 0 ] & 63 ) {
F_582 ( L_205 ,
V_716 -> V_262 [ 0 ] ) ;
return - V_221 ;
}
if ( F_35 ( V_2 ) -> V_84 >= 5 && ! F_14 ( V_2 ) ) {
V_885 = 32 * 1024 ;
} else if ( F_35 ( V_2 ) -> V_84 >= 4 ) {
if ( V_212 -> V_217 )
V_885 = 16 * 1024 ;
else
V_885 = 32 * 1024 ;
} else if ( F_35 ( V_2 ) -> V_84 >= 3 ) {
if ( V_212 -> V_217 )
V_885 = 8 * 1024 ;
else
V_885 = 16 * 1024 ;
} else
V_885 = 8 * 1024 ;
if ( V_716 -> V_262 [ 0 ] > V_885 ) {
F_582 ( L_206 ,
V_212 -> V_217 ? L_207 : L_208 ,
V_716 -> V_262 [ 0 ] , V_885 ) ;
return - V_221 ;
}
if ( V_212 -> V_217 != V_218 &&
V_716 -> V_262 [ 0 ] != V_212 -> V_886 ) {
F_582 ( L_209 ,
V_716 -> V_262 [ 0 ] , V_212 -> V_886 ) ;
return - V_221 ;
}
switch ( V_716 -> V_240 ) {
case V_241 :
case V_246 :
case V_248 :
case V_249 :
break;
case V_243 :
case V_244 :
if ( F_35 ( V_2 ) -> V_84 > 3 ) {
F_582 ( L_210 ,
F_583 ( V_716 -> V_240 ) ) ;
return - V_221 ;
}
break;
case V_251 :
case V_252 :
case V_254 :
case V_255 :
case V_257 :
case V_258 :
if ( F_35 ( V_2 ) -> V_84 < 4 ) {
F_582 ( L_210 ,
F_583 ( V_716 -> V_240 ) ) ;
return - V_221 ;
}
break;
case V_887 :
case V_888 :
case V_889 :
case V_890 :
if ( F_35 ( V_2 ) -> V_84 < 5 ) {
F_582 ( L_210 ,
F_583 ( V_716 -> V_240 ) ) ;
return - V_221 ;
}
break;
default:
F_582 ( L_210 ,
F_583 ( V_716 -> V_240 ) ) ;
return - V_221 ;
}
if ( V_716 -> V_793 [ 0 ] != 0 )
return - V_221 ;
F_584 ( & V_236 -> V_113 , V_716 ) ;
V_236 -> V_212 = V_212 ;
V_216 = F_585 ( V_2 , & V_236 -> V_113 , & V_891 ) ;
if ( V_216 ) {
F_109 ( L_211 , V_216 ) ;
return V_216 ;
}
return 0 ;
}
static struct V_233 *
F_586 ( struct V_1 * V_2 ,
struct V_691 * V_892 ,
struct V_715 * V_716 )
{
struct V_211 * V_212 ;
V_212 = F_427 ( F_428 ( V_2 , V_892 ,
V_716 -> V_893 [ 0 ] ) ) ;
if ( & V_212 -> V_113 == NULL )
return F_440 ( - V_696 ) ;
return F_438 ( V_2 , V_716 , V_212 ) ;
}
static void F_587 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_3 ( V_2 ) || F_12 ( V_2 ) )
V_4 -> V_267 . V_555 = F_24 ;
else if ( F_14 ( V_2 ) )
V_4 -> V_267 . V_555 = F_25 ;
else if ( F_13 ( V_2 ) )
V_4 -> V_267 . V_555 = F_23 ;
else
V_4 -> V_267 . V_555 = F_22 ;
if ( F_54 ( V_2 ) ) {
V_4 -> V_267 . V_822 = F_391 ;
V_4 -> V_267 . V_628 = F_389 ;
V_4 -> V_267 . V_408 = F_237 ;
V_4 -> V_267 . V_409 = F_245 ;
V_4 -> V_267 . V_413 = F_250 ;
V_4 -> V_267 . V_269 = F_143 ;
} else if ( F_3 ( V_2 ) ) {
V_4 -> V_267 . V_822 = F_386 ;
V_4 -> V_267 . V_628 = F_380 ;
V_4 -> V_267 . V_408 = F_227 ;
V_4 -> V_267 . V_409 = F_242 ;
V_4 -> V_267 . V_413 = F_249 ;
V_4 -> V_267 . V_269 = F_143 ;
} else if ( F_14 ( V_2 ) ) {
V_4 -> V_267 . V_822 = F_351 ;
V_4 -> V_267 . V_628 = F_347 ;
V_4 -> V_267 . V_408 = F_259 ;
V_4 -> V_267 . V_409 = F_262 ;
V_4 -> V_267 . V_413 = F_263 ;
V_4 -> V_267 . V_269 = F_137 ;
} else {
V_4 -> V_267 . V_822 = F_351 ;
V_4 -> V_267 . V_628 = F_347 ;
V_4 -> V_267 . V_408 = F_260 ;
V_4 -> V_267 . V_409 = F_262 ;
V_4 -> V_267 . V_413 = F_263 ;
V_4 -> V_267 . V_269 = F_137 ;
}
if ( F_14 ( V_2 ) )
V_4 -> V_267 . V_539 =
F_289 ;
else if ( F_338 ( V_2 ) || ( F_340 ( V_2 ) && ! F_588 ( V_2 ) ) )
V_4 -> V_267 . V_539 =
F_290 ;
else if ( F_589 ( V_2 ) )
V_4 -> V_267 . V_539 =
F_291 ;
else if ( F_339 ( V_2 ) || F_424 ( V_2 ) || F_588 ( V_2 ) )
V_4 -> V_267 . V_539 =
F_292 ;
else if ( F_590 ( V_2 ) )
V_4 -> V_267 . V_539 =
F_293 ;
else if ( F_425 ( V_2 ) )
V_4 -> V_267 . V_539 =
F_295 ;
else if ( F_591 ( V_2 ) )
V_4 -> V_267 . V_539 =
F_296 ;
else
V_4 -> V_267 . V_539 =
F_297 ;
if ( F_3 ( V_2 ) ) {
if ( F_6 ( V_2 ) ) {
V_4 -> V_267 . V_351 = F_163 ;
V_4 -> V_267 . V_661 = F_404 ;
} else if ( F_171 ( V_2 ) ) {
V_4 -> V_267 . V_351 = F_169 ;
V_4 -> V_267 . V_661 = F_404 ;
} else if ( F_160 ( V_2 ) ) {
V_4 -> V_267 . V_351 = F_172 ;
V_4 -> V_267 . V_661 = F_404 ;
V_4 -> V_267 . V_830 =
F_162 ;
} else if ( F_144 ( V_2 ) ) {
V_4 -> V_267 . V_351 = V_894 ;
V_4 -> V_267 . V_661 = F_400 ;
V_4 -> V_267 . V_830 =
F_387 ;
}
} else if ( F_12 ( V_2 ) ) {
V_4 -> V_267 . V_661 = F_399 ;
}
V_4 -> V_267 . V_798 = F_495 ;
switch ( F_35 ( V_2 ) -> V_84 ) {
case 2 :
V_4 -> V_267 . V_798 = F_485 ;
break;
case 3 :
V_4 -> V_267 . V_798 = F_490 ;
break;
case 4 :
case 5 :
V_4 -> V_267 . V_798 = F_491 ;
break;
case 6 :
V_4 -> V_267 . V_798 = F_492 ;
break;
case 7 :
V_4 -> V_267 . V_798 = F_493 ;
break;
}
}
static void F_592 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_140 |= V_141 ;
F_593 ( L_212 ) ;
}
static void F_594 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_140 |= V_469 ;
F_593 ( L_213 ) ;
}
static void F_595 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_140 |= V_895 ;
F_593 ( L_214 ) ;
}
static void F_596 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_140 |= V_896 ;
F_593 ( L_215 ) ;
}
static int F_597 ( const struct V_897 * V_191 )
{
F_593 ( L_216 , V_191 -> V_898 ) ;
return 1 ;
}
static void F_598 ( struct V_1 * V_2 )
{
struct V_899 * V_900 = V_2 -> V_438 ;
int V_145 ;
for ( V_145 = 0 ; V_145 < F_554 ( V_901 ) ; V_145 ++ ) {
struct V_902 * V_903 = & V_901 [ V_145 ] ;
if ( V_900 -> V_904 == V_903 -> V_904 &&
( V_900 -> V_905 == V_903 -> V_905 ||
V_903 -> V_905 == V_906 ) &&
( V_900 -> V_907 == V_903 -> V_907 ||
V_903 -> V_907 == V_906 ) )
V_903 -> V_908 ( V_2 ) ;
}
for ( V_145 = 0 ; V_145 < F_554 ( V_909 ) ; V_145 ++ ) {
if ( F_599 ( * V_909 [ V_145 ] . V_910 ) != 0 )
V_909 [ V_145 ] . V_908 ( V_2 ) ;
}
}
static void F_600 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_11 V_911 ;
T_1 V_912 = F_601 ( V_2 ) ;
F_602 ( V_2 -> V_438 , V_913 ) ;
F_603 ( V_914 , V_915 ) ;
V_911 = F_604 ( V_916 ) ;
F_603 ( V_911 | 1 << 5 , V_916 ) ;
F_605 ( V_2 -> V_438 , V_913 ) ;
F_98 ( 300 ) ;
F_36 ( V_912 , V_917 ) ;
F_97 ( V_912 ) ;
}
void F_606 ( struct V_1 * V_2 )
{
F_607 ( V_2 ) ;
F_608 ( V_2 ) ;
F_609 ( V_2 ) ;
F_152 ( & V_2 -> V_283 ) ;
F_610 ( V_2 ) ;
F_153 ( & V_2 -> V_283 ) ;
}
void F_611 ( struct V_1 * V_2 )
{
F_612 ( V_2 ) ;
}
void F_613 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_145 , V_918 , V_216 ;
F_614 ( V_2 ) ;
V_2 -> V_568 . V_919 = 0 ;
V_2 -> V_568 . V_920 = 0 ;
V_2 -> V_568 . V_921 = 24 ;
V_2 -> V_568 . V_922 = 1 ;
V_2 -> V_568 . V_727 = & V_923 ;
F_598 ( V_2 ) ;
F_615 ( V_2 ) ;
if ( F_35 ( V_2 ) -> V_147 == 0 )
return;
F_587 ( V_2 ) ;
if ( F_15 ( V_2 ) ) {
V_2 -> V_568 . V_924 = 2048 ;
V_2 -> V_568 . V_925 = 2048 ;
} else if ( F_553 ( V_2 ) ) {
V_2 -> V_568 . V_924 = 4096 ;
V_2 -> V_568 . V_925 = 4096 ;
} else {
V_2 -> V_568 . V_924 = 8192 ;
V_2 -> V_568 . V_925 = 8192 ;
}
V_2 -> V_568 . V_926 = V_4 -> V_927 . V_928 ;
F_32 ( L_217 ,
F_35 ( V_2 ) -> V_147 ,
F_35 ( V_2 ) -> V_147 > 1 ? L_218 : L_219 ) ;
for ( V_145 = 0 ; V_145 < F_35 ( V_2 ) -> V_147 ; V_145 ++ ) {
F_550 ( V_2 , V_145 ) ;
for ( V_918 = 0 ; V_918 < V_4 -> V_150 ; V_918 ++ ) {
V_216 = F_616 ( V_2 , V_145 , V_918 ) ;
if ( V_216 )
F_32 ( L_220 ,
F_62 ( V_145 ) , F_72 ( V_145 , V_918 ) , V_216 ) ;
}
}
F_543 ( V_2 ) ;
F_549 ( V_2 ) ;
F_600 ( V_2 ) ;
F_562 ( V_2 ) ;
F_244 ( V_2 ) ;
}
static void
F_617 ( struct V_418 * V_411 )
{
V_411 -> V_113 . V_414 = V_415 ;
V_411 -> V_113 . V_47 = NULL ;
V_411 -> V_47 -> V_407 = false ;
V_411 -> V_47 -> V_113 . V_11 = NULL ;
}
static void F_618 ( struct V_1 * V_2 )
{
struct V_418 * V_411 ;
struct V_410 * V_929 = NULL ;
struct V_722 V_726 ;
F_149 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_411 -> V_47 -> type == V_23 ) {
V_929 = & V_411 -> V_113 ;
break;
}
}
if ( ! V_929 )
return;
if ( F_450 ( V_929 , NULL , & V_726 ) )
F_454 ( V_929 , & V_726 ) ;
}
static bool
F_619 ( struct V_78 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_86 , V_109 ;
if ( F_35 ( V_2 ) -> V_147 == 1 )
return true ;
V_86 = F_67 ( ! V_11 -> V_143 ) ;
V_109 = F_4 ( V_86 ) ;
if ( ( V_109 & V_144 ) &&
( ! ! ( V_109 & V_148 ) == V_11 -> V_76 ) )
return false ;
return true ;
}
static void F_620 ( struct V_78 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_113 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_86 ;
V_86 = F_38 ( V_11 -> V_79 . V_80 ) ;
F_36 ( V_86 , F_4 ( V_86 ) & ~ V_930 ) ;
if ( F_35 ( V_2 ) -> V_84 < 4 && ! F_619 ( V_11 ) ) {
struct V_418 * V_411 ;
bool V_143 ;
F_32 ( L_221 ,
V_11 -> V_113 . V_113 . V_191 ) ;
V_143 = V_11 -> V_143 ;
V_11 -> V_143 = ! V_143 ;
V_4 -> V_267 . V_409 ( & V_11 -> V_113 ) ;
V_11 -> V_143 = V_143 ;
F_149 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_411 -> V_47 -> V_113 . V_11 != & V_11 -> V_113 )
continue;
F_617 ( V_411 ) ;
}
F_2 ( V_11 -> V_189 ) ;
V_11 -> V_113 . V_107 = false ;
}
if ( V_4 -> V_140 & V_141 &&
V_11 -> V_76 == V_130 && ! V_11 -> V_189 ) {
F_618 ( V_2 ) ;
}
F_265 ( & V_11 -> V_113 ) ;
if ( V_11 -> V_189 != V_11 -> V_113 . V_107 ) {
struct V_46 * V_47 ;
F_32 ( L_222 ,
V_11 -> V_113 . V_113 . V_191 ,
V_11 -> V_113 . V_107 ? L_223 : L_224 ,
V_11 -> V_189 ? L_223 : L_224 ) ;
V_11 -> V_113 . V_107 = V_11 -> V_189 ;
F_2 ( V_11 -> V_189 ) ;
F_19 (dev, &crtc->base, encoder) {
F_2 ( V_47 -> V_407 ) ;
V_47 -> V_113 . V_11 = NULL ;
}
}
}
static void F_621 ( struct V_46 * V_47 )
{
struct V_418 * V_411 ;
struct V_1 * V_2 = V_47 -> V_113 . V_2 ;
bool V_931 = V_47 -> V_113 . V_11 &&
F_27 ( V_47 -> V_113 . V_11 ) -> V_189 ;
if ( V_47 -> V_407 && ! V_931 ) {
F_32 ( L_225 ,
V_47 -> V_113 . V_113 . V_191 ,
F_397 ( & V_47 -> V_113 ) ) ;
if ( V_47 -> V_113 . V_11 ) {
F_32 ( L_226 ,
V_47 -> V_113 . V_113 . V_191 ,
F_397 ( & V_47 -> V_113 ) ) ;
V_47 -> V_193 ( V_47 ) ;
}
F_149 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_411 -> V_47 != V_47 )
continue;
F_617 ( V_411 ) ;
}
}
}
void F_622 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_912 = F_601 ( V_2 ) ;
if ( F_4 ( V_912 ) != V_917 ) {
F_32 ( L_227 ) ;
F_600 ( V_2 ) ;
}
}
static void F_623 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_76 V_76 ;
struct V_78 * V_11 ;
struct V_46 * V_47 ;
struct V_418 * V_411 ;
int V_145 ;
F_149 (crtc, &dev->mode_config.crtc_list,
base.head) {
memset ( & V_11 -> V_79 , 0 , sizeof( V_11 -> V_79 ) ) ;
V_11 -> V_189 = V_4 -> V_267 . V_822 ( V_11 ,
& V_11 -> V_79 ) ;
V_11 -> V_113 . V_107 = V_11 -> V_189 ;
F_32 ( L_228 ,
V_11 -> V_113 . V_113 . V_191 ,
V_11 -> V_189 ? L_223 : L_224 ) ;
}
if ( F_54 ( V_2 ) )
F_624 ( V_2 ) ;
for ( V_145 = 0 ; V_145 < V_4 -> V_369 ; V_145 ++ ) {
struct V_112 * V_116 = & V_4 -> V_115 [ V_145 ] ;
V_116 -> V_190 = V_116 -> V_119 ( V_4 , V_116 , & V_116 -> V_118 ) ;
V_116 -> V_189 = 0 ;
F_149 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_11 -> V_189 && F_49 ( V_11 ) == V_116 )
V_116 -> V_189 ++ ;
}
V_116 -> V_188 = V_116 -> V_189 ;
F_32 ( L_229 ,
V_116 -> V_120 , V_116 -> V_188 , V_116 -> V_190 ) ;
}
F_149 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_76 = 0 ;
if ( V_47 -> V_119 ( V_47 , & V_76 ) ) {
V_11 = F_27 ( V_4 -> V_77 [ V_76 ] ) ;
V_47 -> V_113 . V_11 = & V_11 -> V_113 ;
if ( V_47 -> V_823 )
V_47 -> V_823 ( V_47 , & V_11 -> V_79 ) ;
} else {
V_47 -> V_113 . V_11 = NULL ;
}
V_47 -> V_407 = false ;
F_32 ( L_230 ,
V_47 -> V_113 . V_113 . V_191 ,
F_397 ( & V_47 -> V_113 ) ,
V_47 -> V_113 . V_11 ? L_223 : L_224 ,
V_76 ) ;
}
F_149 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_411 -> V_119 ( V_411 ) ) {
V_411 -> V_113 . V_414 = V_417 ;
V_411 -> V_47 -> V_407 = true ;
V_411 -> V_113 . V_47 = & V_411 -> V_47 -> V_113 ;
} else {
V_411 -> V_113 . V_414 = V_415 ;
V_411 -> V_113 . V_47 = NULL ;
}
F_32 ( L_231 ,
V_411 -> V_113 . V_113 . V_191 ,
F_275 ( & V_411 -> V_113 ) ,
V_411 -> V_113 . V_47 ? L_223 : L_224 ) ;
}
}
void F_625 ( struct V_1 * V_2 ,
bool V_932 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_76 V_76 ;
struct V_933 * V_143 ;
struct V_78 * V_11 ;
struct V_46 * V_47 ;
int V_145 ;
F_623 ( V_2 ) ;
F_149 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_621 ( V_47 ) ;
}
F_626 (pipe) {
V_11 = F_27 ( V_4 -> V_77 [ V_76 ] ) ;
F_620 ( V_11 ) ;
F_509 ( V_11 , & V_11 -> V_79 , L_232 ) ;
}
for ( V_145 = 0 ; V_145 < V_4 -> V_369 ; V_145 ++ ) {
struct V_112 * V_116 = & V_4 -> V_115 [ V_145 ] ;
if ( ! V_116 -> V_190 || V_116 -> V_189 )
continue;
F_32 ( L_233 , V_116 -> V_120 ) ;
V_116 -> V_193 ( V_4 , V_116 ) ;
V_116 -> V_190 = false ;
}
if ( V_932 ) {
F_626 (pipe) {
struct V_10 * V_11 =
V_4 -> V_77 [ V_76 ] ;
F_528 ( V_11 , & V_11 -> V_338 , V_11 -> V_226 , V_11 -> V_227 ,
V_11 -> V_234 ) ;
}
F_149 (plane, &dev->mode_config.plane_list, head)
F_224 ( V_143 ) ;
F_622 ( V_2 ) ;
} else {
F_505 ( V_2 ) ;
}
F_278 ( V_2 ) ;
F_627 ( V_2 ) ;
}
void F_628 ( struct V_1 * V_2 )
{
F_606 ( V_2 ) ;
F_629 ( V_2 ) ;
F_625 ( V_2 , false ) ;
}
void F_630 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_11 ;
struct V_78 * V_78 ;
F_631 ( V_2 ) ;
F_468 ( & V_4 -> V_934 ) ;
F_632 ( V_2 ) ;
F_152 ( & V_2 -> V_283 ) ;
F_633 () ;
F_149 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_11 -> V_234 )
continue;
V_78 = F_27 ( V_11 ) ;
F_147 ( V_11 ) ;
}
F_244 ( V_2 ) ;
F_634 ( V_2 ) ;
F_635 ( V_2 ) ;
F_153 ( & V_2 -> V_283 ) ;
F_636 () ;
F_637 ( V_2 ) ;
F_638 ( V_2 ) ;
F_639 ( V_2 ) ;
}
struct V_416 * F_640 ( struct V_410 * V_411 )
{
return & F_277 ( V_411 ) -> V_113 ;
}
void F_641 ( struct V_418 * V_411 ,
struct V_46 * V_47 )
{
V_411 -> V_47 = V_47 ;
F_642 ( & V_411 -> V_113 ,
& V_47 -> V_113 ) ;
}
int F_643 ( struct V_1 * V_2 , bool V_108 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_935 ;
F_294 ( V_4 -> V_936 , V_937 , & V_935 ) ;
if ( V_108 )
V_935 &= ~ V_938 ;
else
V_935 |= V_938 ;
F_644 ( V_4 -> V_936 , V_937 , V_935 ) ;
return 0 ;
}
struct V_939 *
F_645 ( struct V_1 * V_2 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_939 * error ;
int V_940 [] = {
V_204 ,
V_941 ,
V_942 ,
V_536 ,
} ;
int V_145 ;
if ( F_35 ( V_2 ) -> V_147 == 0 )
return NULL ;
error = F_529 ( sizeof( * error ) , V_943 ) ;
if ( error == NULL )
return NULL ;
if ( F_646 ( V_2 ) )
error -> V_944 = F_4 ( V_945 ) ;
F_626 (i) {
if ( F_35 ( V_2 ) -> V_84 <= 6 || F_14 ( V_2 ) ) {
error -> V_946 [ V_145 ] . V_395 = F_4 ( F_255 ( V_145 ) ) ;
error -> V_946 [ V_145 ] . V_947 = F_4 ( F_423 ( V_145 ) ) ;
error -> V_946 [ V_145 ] . V_113 = F_4 ( F_256 ( V_145 ) ) ;
} else {
error -> V_946 [ V_145 ] . V_395 = F_4 ( F_420 ( V_145 ) ) ;
error -> V_946 [ V_145 ] . V_947 = F_4 ( F_422 ( V_145 ) ) ;
error -> V_946 [ V_145 ] . V_113 = F_4 ( F_421 ( V_145 ) ) ;
}
error -> V_143 [ V_145 ] . V_395 = F_4 ( F_67 ( V_145 ) ) ;
error -> V_143 [ V_145 ] . V_886 = F_4 ( F_139 ( V_145 ) ) ;
if ( F_35 ( V_2 ) -> V_84 <= 3 ) {
error -> V_143 [ V_145 ] . V_373 = F_4 ( F_348 ( V_145 ) ) ;
error -> V_143 [ V_145 ] . V_376 = F_4 ( F_349 ( V_145 ) ) ;
}
if ( F_35 ( V_2 ) -> V_84 <= 7 && ! F_144 ( V_2 ) )
error -> V_143 [ V_145 ] . V_694 = F_4 ( F_120 ( V_145 ) ) ;
if ( F_35 ( V_2 ) -> V_84 >= 4 ) {
error -> V_143 [ V_145 ] . V_948 = F_4 ( F_119 ( V_145 ) ) ;
error -> V_143 [ V_145 ] . V_949 = F_4 ( F_141 ( V_145 ) ) ;
}
error -> V_76 [ V_145 ] . V_950 = F_4 ( F_343 ( V_145 ) ) ;
}
error -> V_951 = F_35 ( V_2 ) -> V_147 ;
if ( F_54 ( V_4 -> V_2 ) )
error -> V_951 ++ ;
for ( V_145 = 0 ; V_145 < error -> V_951 ; V_145 ++ ) {
enum V_75 V_80 = V_940 [ V_145 ] ;
error -> V_75 [ V_145 ] . V_80 = V_80 ;
error -> V_75 [ V_145 ] . V_952 = F_4 ( F_38 ( V_80 ) ) ;
error -> V_75 [ V_145 ] . V_753 = F_4 ( F_193 ( V_80 ) ) ;
error -> V_75 [ V_145 ] . V_953 = F_4 ( F_195 ( V_80 ) ) ;
error -> V_75 [ V_145 ] . V_750 = F_4 ( F_197 ( V_80 ) ) ;
error -> V_75 [ V_145 ] . V_755 = F_4 ( F_199 ( V_80 ) ) ;
error -> V_75 [ V_145 ] . V_954 = F_4 ( F_201 ( V_80 ) ) ;
error -> V_75 [ V_145 ] . V_752 = F_4 ( F_203 ( V_80 ) ) ;
}
if ( F_646 ( V_2 ) )
F_647 ( V_955 , V_956 ) ;
return error ;
}
void
F_648 ( struct V_957 * V_36 ,
struct V_1 * V_2 ,
struct V_939 * error )
{
int V_145 ;
if ( ! error )
return;
F_649 ( V_36 , L_234 , F_35 ( V_2 ) -> V_147 ) ;
if ( F_646 ( V_2 ) )
F_649 ( V_36 , L_235 ,
error -> V_944 ) ;
F_626 (i) {
F_649 ( V_36 , L_236 , V_145 ) ;
F_649 ( V_36 , L_237 , error -> V_76 [ V_145 ] . V_950 ) ;
F_649 ( V_36 , L_238 , V_145 ) ;
F_649 ( V_36 , L_239 , error -> V_143 [ V_145 ] . V_395 ) ;
F_649 ( V_36 , L_240 , error -> V_143 [ V_145 ] . V_886 ) ;
if ( F_35 ( V_2 ) -> V_84 <= 3 ) {
F_649 ( V_36 , L_241 , error -> V_143 [ V_145 ] . V_373 ) ;
F_649 ( V_36 , L_242 , error -> V_143 [ V_145 ] . V_376 ) ;
}
if ( F_35 ( V_2 ) -> V_84 <= 7 && ! F_144 ( V_2 ) )
F_649 ( V_36 , L_243 , error -> V_143 [ V_145 ] . V_694 ) ;
if ( F_35 ( V_2 ) -> V_84 >= 4 ) {
F_649 ( V_36 , L_244 , error -> V_143 [ V_145 ] . V_948 ) ;
F_649 ( V_36 , L_245 , error -> V_143 [ V_145 ] . V_949 ) ;
}
F_649 ( V_36 , L_246 , V_145 ) ;
F_649 ( V_36 , L_239 , error -> V_946 [ V_145 ] . V_395 ) ;
F_649 ( V_36 , L_242 , error -> V_946 [ V_145 ] . V_947 ) ;
F_649 ( V_36 , L_247 , error -> V_946 [ V_145 ] . V_113 ) ;
}
for ( V_145 = 0 ; V_145 < error -> V_951 ; V_145 ++ ) {
F_649 ( V_36 , L_248 ,
F_510 ( error -> V_75 [ V_145 ] . V_80 ) ) ;
F_649 ( V_36 , L_249 , error -> V_75 [ V_145 ] . V_952 ) ;
F_649 ( V_36 , L_250 , error -> V_75 [ V_145 ] . V_753 ) ;
F_649 ( V_36 , L_251 , error -> V_75 [ V_145 ] . V_953 ) ;
F_649 ( V_36 , L_252 , error -> V_75 [ V_145 ] . V_750 ) ;
F_649 ( V_36 , L_253 , error -> V_75 [ V_145 ] . V_755 ) ;
F_649 ( V_36 , L_254 , error -> V_75 [ V_145 ] . V_954 ) ;
F_649 ( V_36 , L_255 , error -> V_75 [ V_145 ] . V_752 ) ;
}
}
