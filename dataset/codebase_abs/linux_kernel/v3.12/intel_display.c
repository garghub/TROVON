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
else if ( F_8 ( V_11 , V_35 ) )
V_13 = & V_36 ;
else
V_13 = & V_37 ;
}
return V_13 ;
}
static void F_16 ( int V_12 , T_3 * clock )
{
clock -> V_38 = clock -> V_39 + 2 ;
clock -> V_40 = clock -> V_41 * clock -> V_42 ;
clock -> V_43 = V_12 * clock -> V_38 / clock -> V_44 ;
clock -> V_45 = clock -> V_43 / clock -> V_40 ;
}
static T_4 F_17 ( struct V_46 * V_46 )
{
return 5 * ( V_46 -> V_47 + 2 ) + ( V_46 -> V_39 + 2 ) ;
}
static void F_18 ( int V_12 , T_3 * clock )
{
clock -> V_38 = F_17 ( clock ) ;
clock -> V_40 = clock -> V_41 * clock -> V_42 ;
clock -> V_43 = V_12 * clock -> V_38 / ( clock -> V_44 + 2 ) ;
clock -> V_45 = clock -> V_43 / clock -> V_40 ;
}
bool F_8 ( struct V_10 * V_11 , int type )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_48 * V_49 ;
F_19 (dev, crtc, encoder)
if ( V_49 -> type == type )
return true ;
return false ;
}
static bool F_20 ( struct V_1 * V_2 ,
const T_2 * V_13 ,
const T_3 * clock )
{
if ( clock -> V_41 < V_13 -> V_41 . V_50 || V_13 -> V_41 . V_51 < clock -> V_41 )
F_21 ( L_1 ) ;
if ( clock -> V_40 < V_13 -> V_40 . V_50 || V_13 -> V_40 . V_51 < clock -> V_40 )
F_21 ( L_2 ) ;
if ( clock -> V_39 < V_13 -> V_39 . V_50 || V_13 -> V_39 . V_51 < clock -> V_39 )
F_21 ( L_3 ) ;
if ( clock -> V_47 < V_13 -> V_47 . V_50 || V_13 -> V_47 . V_51 < clock -> V_47 )
F_21 ( L_4 ) ;
if ( clock -> V_47 <= clock -> V_39 && ! F_13 ( V_2 ) )
F_21 ( L_5 ) ;
if ( clock -> V_38 < V_13 -> V_38 . V_50 || V_13 -> V_38 . V_51 < clock -> V_38 )
F_21 ( L_6 ) ;
if ( clock -> V_44 < V_13 -> V_44 . V_50 || V_13 -> V_44 . V_51 < clock -> V_44 )
F_21 ( L_7 ) ;
if ( clock -> V_43 < V_13 -> V_43 . V_50 || V_13 -> V_43 . V_51 < clock -> V_43 )
F_21 ( L_8 ) ;
if ( clock -> V_45 < V_13 -> V_45 . V_50 || V_13 -> V_45 . V_51 < clock -> V_45 )
F_21 ( L_9 ) ;
return true ;
}
static bool
F_22 ( const T_2 * V_13 , struct V_10 * V_11 ,
int V_52 , int V_12 , T_3 * V_53 ,
T_3 * V_54 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 clock ;
int V_55 = V_52 ;
if ( F_8 ( V_11 , V_14 ) ) {
if ( F_9 ( V_2 ) )
clock . V_42 = V_13 -> V_42 . V_56 ;
else
clock . V_42 = V_13 -> V_42 . V_57 ;
} else {
if ( V_52 < V_13 -> V_42 . V_58 )
clock . V_42 = V_13 -> V_42 . V_57 ;
else
clock . V_42 = V_13 -> V_42 . V_56 ;
}
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
for ( clock . V_47 = V_13 -> V_47 . V_50 ; clock . V_47 <= V_13 -> V_47 . V_51 ;
clock . V_47 ++ ) {
for ( clock . V_39 = V_13 -> V_39 . V_50 ;
clock . V_39 <= V_13 -> V_39 . V_51 ; clock . V_39 ++ ) {
if ( clock . V_39 >= clock . V_47 )
break;
for ( clock . V_44 = V_13 -> V_44 . V_50 ;
clock . V_44 <= V_13 -> V_44 . V_51 ; clock . V_44 ++ ) {
for ( clock . V_41 = V_13 -> V_41 . V_50 ;
clock . V_41 <= V_13 -> V_41 . V_51 ; clock . V_41 ++ ) {
int V_59 ;
F_18 ( V_12 , & clock ) ;
if ( ! F_20 ( V_2 , V_13 ,
& clock ) )
continue;
if ( V_53 &&
clock . V_40 != V_53 -> V_40 )
continue;
V_59 = abs ( clock . V_45 - V_52 ) ;
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
F_23 ( const T_2 * V_13 , struct V_10 * V_11 ,
int V_52 , int V_12 , T_3 * V_53 ,
T_3 * V_54 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 clock ;
int V_55 = V_52 ;
if ( F_8 ( V_11 , V_14 ) ) {
if ( F_9 ( V_2 ) )
clock . V_42 = V_13 -> V_42 . V_56 ;
else
clock . V_42 = V_13 -> V_42 . V_57 ;
} else {
if ( V_52 < V_13 -> V_42 . V_58 )
clock . V_42 = V_13 -> V_42 . V_57 ;
else
clock . V_42 = V_13 -> V_42 . V_56 ;
}
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
for ( clock . V_47 = V_13 -> V_47 . V_50 ; clock . V_47 <= V_13 -> V_47 . V_51 ;
clock . V_47 ++ ) {
for ( clock . V_39 = V_13 -> V_39 . V_50 ;
clock . V_39 <= V_13 -> V_39 . V_51 ; clock . V_39 ++ ) {
for ( clock . V_44 = V_13 -> V_44 . V_50 ;
clock . V_44 <= V_13 -> V_44 . V_51 ; clock . V_44 ++ ) {
for ( clock . V_41 = V_13 -> V_41 . V_50 ;
clock . V_41 <= V_13 -> V_41 . V_51 ; clock . V_41 ++ ) {
int V_59 ;
F_16 ( V_12 , & clock ) ;
if ( ! F_20 ( V_2 , V_13 ,
& clock ) )
continue;
if ( V_53 &&
clock . V_40 != V_53 -> V_40 )
continue;
V_59 = abs ( clock . V_45 - V_52 ) ;
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
F_24 ( const T_2 * V_13 , struct V_10 * V_11 ,
int V_52 , int V_12 , T_3 * V_53 ,
T_3 * V_54 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 clock ;
int V_60 ;
bool V_61 ;
int V_62 = ( V_52 >> 8 ) + ( V_52 >> 9 ) ;
V_61 = false ;
if ( F_8 ( V_11 , V_14 ) ) {
if ( F_9 ( V_2 ) )
clock . V_42 = V_13 -> V_42 . V_56 ;
else
clock . V_42 = V_13 -> V_42 . V_57 ;
} else {
if ( V_52 < V_13 -> V_42 . V_58 )
clock . V_42 = V_13 -> V_42 . V_57 ;
else
clock . V_42 = V_13 -> V_42 . V_56 ;
}
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_60 = V_13 -> V_44 . V_51 ;
for ( clock . V_44 = V_13 -> V_44 . V_50 ; clock . V_44 <= V_60 ; clock . V_44 ++ ) {
for ( clock . V_47 = V_13 -> V_47 . V_51 ;
clock . V_47 >= V_13 -> V_47 . V_50 ; clock . V_47 -- ) {
for ( clock . V_39 = V_13 -> V_39 . V_51 ;
clock . V_39 >= V_13 -> V_39 . V_50 ; clock . V_39 -- ) {
for ( clock . V_41 = V_13 -> V_41 . V_51 ;
clock . V_41 >= V_13 -> V_41 . V_50 ; clock . V_41 -- ) {
int V_59 ;
F_18 ( V_12 , & clock ) ;
if ( ! F_20 ( V_2 , V_13 ,
& clock ) )
continue;
V_59 = abs ( clock . V_45 - V_52 ) ;
if ( V_59 < V_62 ) {
* V_54 = clock ;
V_62 = V_59 ;
V_60 = clock . V_44 ;
V_61 = true ;
}
}
}
}
}
return V_61 ;
}
static bool
F_25 ( const T_2 * V_13 , struct V_10 * V_11 ,
int V_52 , int V_12 , T_3 * V_53 ,
T_3 * V_54 )
{
T_1 V_41 , V_42 , V_47 , V_39 , V_43 , V_63 , V_64 , V_65 , V_66 , V_67 ;
T_1 V_38 , V_44 , V_68 ;
T_1 V_69 , V_70 , V_40 ;
unsigned long V_71 , V_72 , V_73 ;
int V_74 , V_75 ;
V_75 = 0 ;
V_74 = V_52 * 1000 ;
V_71 = 1000000 ;
V_72 = V_73 = 0 ;
V_68 = V_74 / ( 2 * 100 ) ;
V_69 = 0 ;
V_70 = 19200 ;
V_44 = V_40 = V_41 = V_42 = V_38 = V_47 = V_39 = V_43 = V_63 = 0 ;
V_64 = V_65 = V_66 = V_67 = 0 ;
for ( V_44 = V_13 -> V_44 . V_50 ; V_44 <= ( ( V_12 ) / V_70 ) ; V_44 ++ ) {
V_69 = V_12 / V_44 ;
for ( V_41 = V_13 -> V_41 . V_51 ; V_41 > V_13 -> V_41 . V_50 ; V_41 -- ) {
for ( V_42 = V_13 -> V_42 . V_56 + 1 ; V_42 > 0 ; V_42 -- ) {
if ( V_42 > 10 )
V_42 = V_42 - 1 ;
V_40 = V_41 * V_42 ;
for ( V_47 = V_13 -> V_47 . V_50 ; V_47 <= V_13 -> V_47 . V_51 ; V_47 ++ ) {
V_39 = ( ( ( 2 * ( V_68 * V_40 * V_44 / V_47 ) ) +
V_12 ) / ( 2 * V_12 ) ) ;
V_38 = V_47 * V_39 ;
V_43 = V_69 * V_38 ;
if ( V_43 >= V_13 -> V_43 . V_50 && V_43 < V_13 -> V_43 . V_51 ) {
V_72 = 1000000 * ( ( V_43 / V_40 ) - V_68 ) / V_68 ;
V_73 = ( V_72 > 0 ) ? V_72 : ( - V_72 ) ;
if ( V_73 < 100 && ( ( V_41 * V_42 ) > ( V_66 * V_67 ) ) ) {
V_71 = 0 ;
V_75 = 1 ;
}
if ( V_73 < V_71 - 10 ) {
V_71 = V_73 ;
V_75 = 1 ;
}
if ( V_75 ) {
V_63 = V_44 ;
V_64 = V_47 ;
V_65 = V_39 ;
V_66 = V_41 ;
V_67 = V_42 ;
V_75 = 0 ;
}
}
}
}
}
}
V_54 -> V_44 = V_63 ;
V_54 -> V_47 = V_64 ;
V_54 -> V_39 = V_65 ;
V_54 -> V_41 = V_66 ;
V_54 -> V_42 = V_67 ;
return true ;
}
enum V_76 F_26 ( struct V_3 * V_4 ,
enum V_77 V_77 )
{
struct V_10 * V_11 = V_4 -> V_78 [ V_77 ] ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
return V_79 -> V_80 . V_81 ;
}
static void F_28 ( struct V_1 * V_2 , int V_77 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_82 , V_83 = F_29 ( V_77 ) ;
V_82 = F_4 ( V_83 ) ;
if ( F_30 ( F_31 ( V_83 ) != V_82 , 50 ) )
F_32 ( L_10 ) ;
}
void F_33 ( struct V_1 * V_2 , int V_77 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_84 = F_34 ( V_77 ) ;
if ( F_35 ( V_2 ) -> V_85 >= 5 ) {
F_28 ( V_2 , V_77 ) ;
return;
}
F_36 ( V_84 ,
F_4 ( V_84 ) | V_86 ) ;
if ( F_30 ( F_4 ( V_84 ) &
V_86 ,
50 ) )
F_32 ( L_10 ) ;
}
void F_37 ( struct V_1 * V_2 , int V_77 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_76 V_81 = F_26 ( V_4 ,
V_77 ) ;
if ( F_35 ( V_2 ) -> V_85 >= 4 ) {
int V_87 = F_38 ( V_81 ) ;
if ( F_30 ( ( F_4 ( V_87 ) & V_88 ) == 0 ,
100 ) )
F_39 ( 1 , L_11 ) ;
} else {
T_1 V_89 , V_90 ;
int V_87 = F_40 ( V_77 ) ;
unsigned long V_91 = V_92 + F_41 ( 100 ) ;
if ( F_15 ( V_2 ) )
V_90 = V_93 ;
else
V_90 = V_94 ;
do {
V_89 = F_4 ( V_87 ) & V_90 ;
F_42 ( 5 ) ;
} while ( ( ( F_4 ( V_87 ) & V_90 ) != V_89 ) &&
F_43 ( V_91 , V_92 ) );
if ( F_43 ( V_92 , V_91 ) )
F_39 ( 1 , L_11 ) ;
}
}
bool F_44 ( struct V_3 * V_4 ,
struct V_95 * V_96 )
{
T_1 V_97 ;
if ( F_45 ( V_4 -> V_2 ) ) {
switch( V_96 -> V_96 ) {
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
switch( V_96 -> V_96 ) {
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
return F_4 ( V_107 ) & V_97 ;
}
static const char * F_46 ( bool V_108 )
{
return V_108 ? L_12 : L_13 ;
}
void F_47 ( struct V_3 * V_4 ,
enum V_77 V_77 , bool V_109 )
{
int V_87 ;
T_1 V_110 ;
bool V_111 ;
V_87 = F_48 ( V_77 ) ;
V_110 = F_4 ( V_87 ) ;
V_111 = ! ! ( V_110 & V_112 ) ;
F_39 ( V_111 != V_109 ,
L_14 ,
F_46 ( V_109 ) , F_46 ( V_111 ) ) ;
}
struct V_113 *
F_49 ( struct V_79 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_114 . V_2 -> V_5 ;
if ( V_11 -> V_80 . V_115 < 0 )
return NULL ;
return & V_4 -> V_116 [ V_11 -> V_80 . V_115 ] ;
}
void F_50 ( struct V_3 * V_4 ,
struct V_113 * V_117 ,
bool V_109 )
{
bool V_111 ;
struct V_118 V_119 ;
if ( F_51 ( V_4 -> V_2 ) ) {
F_52 ( L_15 ) ;
return;
}
if ( F_39 ( ! V_117 ,
L_16 , F_46 ( V_109 ) ) )
return;
V_111 = V_117 -> V_120 ( V_4 , V_117 , & V_119 ) ;
F_39 ( V_111 != V_109 ,
L_17 ,
V_117 -> V_121 , F_46 ( V_109 ) , F_46 ( V_111 ) ) ;
}
static void F_53 ( struct V_3 * V_4 ,
enum V_77 V_77 , bool V_109 )
{
int V_87 ;
T_1 V_110 ;
bool V_111 ;
enum V_76 V_81 = F_26 ( V_4 ,
V_77 ) ;
if ( F_54 ( V_4 -> V_2 ) ) {
V_87 = F_55 ( V_81 ) ;
V_110 = F_4 ( V_87 ) ;
V_111 = ! ! ( V_110 & V_122 ) ;
} else {
V_87 = F_56 ( V_77 ) ;
V_110 = F_4 ( V_87 ) ;
V_111 = ! ! ( V_110 & V_123 ) ;
}
F_39 ( V_111 != V_109 ,
L_18 ,
F_46 ( V_109 ) , F_46 ( V_111 ) ) ;
}
static void F_57 ( struct V_3 * V_4 ,
enum V_77 V_77 , bool V_109 )
{
int V_87 ;
T_1 V_110 ;
bool V_111 ;
V_87 = F_58 ( V_77 ) ;
V_110 = F_4 ( V_87 ) ;
V_111 = ! ! ( V_110 & V_124 ) ;
F_39 ( V_111 != V_109 ,
L_19 ,
F_46 ( V_109 ) , F_46 ( V_111 ) ) ;
}
static void F_59 ( struct V_3 * V_4 ,
enum V_77 V_77 )
{
int V_87 ;
T_1 V_110 ;
if ( V_4 -> V_125 -> V_85 == 5 )
return;
if ( F_54 ( V_4 -> V_2 ) )
return;
V_87 = F_56 ( V_77 ) ;
V_110 = F_4 ( V_87 ) ;
F_39 ( ! ( V_110 & V_126 ) , L_20 ) ;
}
void F_60 ( struct V_3 * V_4 ,
enum V_77 V_77 , bool V_109 )
{
int V_87 ;
T_1 V_110 ;
bool V_111 ;
V_87 = F_58 ( V_77 ) ;
V_110 = F_4 ( V_87 ) ;
V_111 = ! ! ( V_110 & V_127 ) ;
F_39 ( V_111 != V_109 ,
L_21 ,
F_46 ( V_109 ) , F_46 ( V_111 ) ) ;
}
static void F_61 ( struct V_3 * V_4 ,
enum V_77 V_77 )
{
int V_128 , V_129 ;
T_1 V_110 ;
enum V_77 V_130 = V_131 ;
bool V_132 = true ;
if ( F_3 ( V_4 -> V_2 ) ) {
V_128 = V_133 ;
V_129 = V_134 ;
} else {
V_128 = V_135 ;
V_129 = V_136 ;
}
V_110 = F_4 ( V_128 ) ;
if ( ! ( V_110 & V_137 ) ||
( ( V_110 & V_138 ) == V_138 ) )
V_132 = false ;
if ( F_4 ( V_129 ) & V_139 )
V_130 = V_140 ;
F_39 ( V_130 == V_77 && V_132 ,
L_22 ,
F_62 ( V_77 ) ) ;
}
void F_63 ( struct V_3 * V_4 ,
enum V_77 V_77 , bool V_109 )
{
int V_87 ;
T_1 V_110 ;
bool V_111 ;
enum V_76 V_81 = F_26 ( V_4 ,
V_77 ) ;
if ( V_77 == V_131 && V_4 -> V_141 & V_142 )
V_109 = true ;
if ( ! F_64 ( V_4 -> V_2 ,
F_65 ( V_81 ) ) ) {
V_111 = false ;
} else {
V_87 = F_38 ( V_81 ) ;
V_110 = F_4 ( V_87 ) ;
V_111 = ! ! ( V_110 & V_143 ) ;
}
F_39 ( V_111 != V_109 ,
L_23 ,
F_62 ( V_77 ) , F_46 ( V_109 ) , F_46 ( V_111 ) ) ;
}
static void F_66 ( struct V_3 * V_4 ,
enum V_144 V_144 , bool V_109 )
{
int V_87 ;
T_1 V_110 ;
bool V_111 ;
V_87 = F_67 ( V_144 ) ;
V_110 = F_4 ( V_87 ) ;
V_111 = ! ! ( V_110 & V_145 ) ;
F_39 ( V_111 != V_109 ,
L_24 ,
F_68 ( V_144 ) , F_46 ( V_109 ) , F_46 ( V_111 ) ) ;
}
static void F_69 ( struct V_3 * V_4 ,
enum V_77 V_77 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_87 , V_146 ;
T_1 V_110 ;
int V_147 ;
if ( F_35 ( V_2 ) -> V_85 >= 4 ) {
V_87 = F_67 ( V_77 ) ;
V_110 = F_4 ( V_87 ) ;
F_39 ( ( V_110 & V_145 ) ,
L_25 ,
F_68 ( V_77 ) ) ;
return;
}
F_70 (i) {
V_87 = F_67 ( V_146 ) ;
V_110 = F_4 ( V_87 ) ;
V_147 = ( V_110 & V_148 ) >>
V_149 ;
F_39 ( ( V_110 & V_145 ) && V_77 == V_147 ,
L_26 ,
F_68 ( V_146 ) , F_62 ( V_77 ) ) ;
}
}
static void F_71 ( struct V_3 * V_4 ,
enum V_77 V_77 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_87 , V_146 ;
T_1 V_110 ;
if ( F_14 ( V_2 ) ) {
for ( V_146 = 0 ; V_146 < V_4 -> V_150 ; V_146 ++ ) {
V_87 = F_72 ( V_77 , V_146 ) ;
V_110 = F_4 ( V_87 ) ;
F_39 ( ( V_110 & V_151 ) ,
L_27 ,
F_73 ( V_77 , V_146 ) , F_62 ( V_77 ) ) ;
}
} else if ( F_35 ( V_2 ) -> V_85 >= 7 ) {
V_87 = F_74 ( V_77 ) ;
V_110 = F_4 ( V_87 ) ;
F_39 ( ( V_110 & V_152 ) ,
L_27 ,
F_68 ( V_77 ) , F_62 ( V_77 ) ) ;
} else if ( F_35 ( V_2 ) -> V_85 >= 5 ) {
V_87 = F_75 ( V_77 ) ;
V_110 = F_4 ( V_87 ) ;
F_39 ( ( V_110 & V_153 ) ,
L_27 ,
F_68 ( V_77 ) , F_62 ( V_77 ) ) ;
}
}
static void F_76 ( struct V_3 * V_4 )
{
T_1 V_110 ;
bool V_108 ;
if ( F_51 ( V_4 -> V_2 ) ) {
F_52 ( L_28 ) ;
return;
}
V_110 = F_4 ( V_154 ) ;
V_108 = ! ! ( V_110 & ( V_155 | V_156 |
V_157 ) ) ;
F_39 ( ! V_108 , L_29 ) ;
}
static void F_77 ( struct V_3 * V_4 ,
enum V_77 V_77 )
{
int V_87 ;
T_1 V_110 ;
bool V_108 ;
V_87 = F_78 ( V_77 ) ;
V_110 = F_4 ( V_87 ) ;
V_108 = ! ! ( V_110 & V_158 ) ;
F_39 ( V_108 ,
L_30 ,
F_62 ( V_77 ) ) ;
}
static bool F_79 ( struct V_3 * V_4 ,
enum V_77 V_77 , T_1 V_159 , T_1 V_110 )
{
if ( ( V_110 & V_160 ) == 0 )
return false ;
if ( F_80 ( V_4 -> V_2 ) ) {
T_1 V_161 = F_81 ( V_77 ) ;
T_1 V_162 = F_4 ( V_161 ) ;
if ( ( V_162 & V_163 ) != V_159 )
return false ;
} else {
if ( ( V_110 & V_164 ) != ( V_77 << 30 ) )
return false ;
}
return true ;
}
static bool F_82 ( struct V_3 * V_4 ,
enum V_77 V_77 , T_1 V_110 )
{
if ( ( V_110 & V_165 ) == 0 )
return false ;
if ( F_80 ( V_4 -> V_2 ) ) {
if ( ( V_110 & V_166 ) != F_83 ( V_77 ) )
return false ;
} else {
if ( ( V_110 & V_167 ) != F_84 ( V_77 ) )
return false ;
}
return true ;
}
static bool F_85 ( struct V_3 * V_4 ,
enum V_77 V_77 , T_1 V_110 )
{
if ( ( V_110 & V_168 ) == 0 )
return false ;
if ( F_80 ( V_4 -> V_2 ) ) {
if ( ( V_110 & V_169 ) != F_86 ( V_77 ) )
return false ;
} else {
if ( ( V_110 & V_170 ) != F_87 ( V_77 ) )
return false ;
}
return true ;
}
static bool F_88 ( struct V_3 * V_4 ,
enum V_77 V_77 , T_1 V_110 )
{
if ( ( V_110 & V_171 ) == 0 )
return false ;
if ( F_80 ( V_4 -> V_2 ) ) {
if ( ( V_110 & V_169 ) != F_86 ( V_77 ) )
return false ;
} else {
if ( ( V_110 & V_172 ) != F_89 ( V_77 ) )
return false ;
}
return true ;
}
static void F_90 ( struct V_3 * V_4 ,
enum V_77 V_77 , int V_87 , T_1 V_159 )
{
T_1 V_110 = F_4 ( V_87 ) ;
F_39 ( F_79 ( V_4 , V_77 , V_159 , V_110 ) ,
L_31 ,
V_87 , F_62 ( V_77 ) ) ;
F_39 ( F_45 ( V_4 -> V_2 ) && ( V_110 & V_160 ) == 0
&& ( V_110 & V_173 ) ,
L_32 ) ;
}
static void F_91 ( struct V_3 * V_4 ,
enum V_77 V_77 , int V_87 )
{
T_1 V_110 = F_4 ( V_87 ) ;
F_39 ( F_82 ( V_4 , V_77 , V_110 ) ,
L_33 ,
V_87 , F_62 ( V_77 ) ) ;
F_39 ( F_45 ( V_4 -> V_2 ) && ( V_110 & V_165 ) == 0
&& ( V_110 & V_174 ) ,
L_34 ) ;
}
static void F_92 ( struct V_3 * V_4 ,
enum V_77 V_77 )
{
int V_87 ;
T_1 V_110 ;
F_90 ( V_4 , V_77 , V_175 , V_176 ) ;
F_90 ( V_4 , V_77 , V_177 , V_178 ) ;
F_90 ( V_4 , V_77 , V_179 , V_180 ) ;
V_87 = V_181 ;
V_110 = F_4 ( V_87 ) ;
F_39 ( F_88 ( V_4 , V_77 , V_110 ) ,
L_35 ,
F_62 ( V_77 ) ) ;
V_87 = V_134 ;
V_110 = F_4 ( V_87 ) ;
F_39 ( F_85 ( V_4 , V_77 , V_110 ) ,
L_36 ,
F_62 ( V_77 ) ) ;
F_91 ( V_4 , V_77 , V_182 ) ;
F_91 ( V_4 , V_77 , V_183 ) ;
F_91 ( V_4 , V_77 , V_184 ) ;
}
static void F_93 ( struct V_79 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_87 = F_48 ( V_11 -> V_77 ) ;
T_1 V_46 = V_11 -> V_80 . V_185 . V_46 ;
F_94 ( V_4 , V_11 -> V_77 ) ;
F_95 ( ! F_14 ( V_4 -> V_2 ) ) ;
if ( F_96 ( V_4 -> V_2 ) && ! F_97 ( V_4 -> V_2 ) )
F_61 ( V_4 , V_11 -> V_77 ) ;
F_36 ( V_87 , V_46 ) ;
F_98 ( V_87 ) ;
F_99 ( 150 ) ;
if ( F_30 ( ( ( F_4 ( V_87 ) & V_186 ) == V_186 ) , 1 ) )
F_100 ( L_37 , V_11 -> V_77 ) ;
F_36 ( F_101 ( V_11 -> V_77 ) , V_11 -> V_80 . V_185 . V_187 ) ;
F_98 ( F_101 ( V_11 -> V_77 ) ) ;
F_36 ( V_87 , V_46 ) ;
F_98 ( V_87 ) ;
F_99 ( 150 ) ;
F_36 ( V_87 , V_46 ) ;
F_98 ( V_87 ) ;
F_99 ( 150 ) ;
F_36 ( V_87 , V_46 ) ;
F_98 ( V_87 ) ;
F_99 ( 150 ) ;
}
static void F_102 ( struct V_79 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_87 = F_48 ( V_11 -> V_77 ) ;
T_1 V_46 = V_11 -> V_80 . V_185 . V_46 ;
F_94 ( V_4 , V_11 -> V_77 ) ;
F_95 ( V_4 -> V_125 -> V_85 >= 5 ) ;
if ( F_96 ( V_2 ) && ! F_97 ( V_2 ) )
F_61 ( V_4 , V_11 -> V_77 ) ;
F_36 ( V_87 , V_46 ) ;
F_98 ( V_87 ) ;
F_99 ( 150 ) ;
if ( F_35 ( V_2 ) -> V_85 >= 4 ) {
F_36 ( F_101 ( V_11 -> V_77 ) ,
V_11 -> V_80 . V_185 . V_187 ) ;
} else {
F_36 ( V_87 , V_46 ) ;
}
F_36 ( V_87 , V_46 ) ;
F_98 ( V_87 ) ;
F_99 ( 150 ) ;
F_36 ( V_87 , V_46 ) ;
F_98 ( V_87 ) ;
F_99 ( 150 ) ;
F_36 ( V_87 , V_46 ) ;
F_98 ( V_87 ) ;
F_99 ( 150 ) ;
}
static void F_103 ( struct V_3 * V_4 , enum V_77 V_77 )
{
if ( V_77 == V_131 && ( V_4 -> V_141 & V_142 ) )
return;
F_94 ( V_4 , V_77 ) ;
F_36 ( F_48 ( V_77 ) , 0 ) ;
F_98 ( F_48 ( V_77 ) ) ;
}
void F_104 ( struct V_3 * V_4 , int V_96 )
{
T_1 V_188 ;
if ( ! V_96 )
V_188 = V_189 ;
else
V_188 = V_190 ;
if ( F_30 ( ( F_4 ( F_48 ( 0 ) ) & V_188 ) == 0 , 1000 ) )
F_39 ( 1 , L_38 ,
'B' + V_96 , F_4 ( F_48 ( 0 ) ) ) ;
}
static void F_105 ( struct V_79 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_114 . V_2 -> V_5 ;
struct V_113 * V_117 = F_49 ( V_11 ) ;
F_95 ( V_4 -> V_125 -> V_85 < 5 ) ;
if ( F_2 ( V_117 == NULL ) )
return;
if ( F_2 ( V_117 -> V_191 == 0 ) )
return;
F_32 ( L_39 ,
V_117 -> V_121 , V_117 -> V_192 , V_117 -> V_193 ,
V_11 -> V_114 . V_114 . V_194 ) ;
if ( V_117 -> V_192 ++ ) {
F_2 ( ! V_117 -> V_193 ) ;
F_106 ( V_4 , V_117 ) ;
return;
}
F_2 ( V_117 -> V_193 ) ;
F_32 ( L_40 , V_117 -> V_121 ) ;
V_117 -> V_195 ( V_4 , V_117 ) ;
V_117 -> V_193 = true ;
}
static void F_107 ( struct V_79 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_114 . V_2 -> V_5 ;
struct V_113 * V_117 = F_49 ( V_11 ) ;
F_95 ( V_4 -> V_125 -> V_85 < 5 ) ;
if ( F_2 ( V_117 == NULL ) )
return;
if ( F_2 ( V_117 -> V_191 == 0 ) )
return;
F_32 ( L_41 ,
V_117 -> V_121 , V_117 -> V_192 , V_117 -> V_193 ,
V_11 -> V_114 . V_114 . V_194 ) ;
if ( F_2 ( V_117 -> V_192 == 0 ) ) {
F_108 ( V_4 , V_117 ) ;
return;
}
F_106 ( V_4 , V_117 ) ;
F_2 ( ! V_117 -> V_193 ) ;
if ( -- V_117 -> V_192 )
return;
F_32 ( L_42 , V_117 -> V_121 ) ;
V_117 -> V_196 ( V_4 , V_117 ) ;
V_117 -> V_193 = false ;
}
static void F_109 ( struct V_3 * V_4 ,
enum V_77 V_77 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_10 * V_11 = V_4 -> V_78 [ V_77 ] ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
T_4 V_87 , V_110 , V_197 ;
F_95 ( V_4 -> V_125 -> V_85 < 5 ) ;
F_106 ( V_4 ,
F_49 ( V_79 ) ) ;
F_110 ( V_4 , V_77 ) ;
F_111 ( V_4 , V_77 ) ;
if ( F_80 ( V_2 ) ) {
V_87 = F_112 ( V_77 ) ;
V_110 = F_4 ( V_87 ) ;
V_110 |= V_198 ;
F_36 ( V_87 , V_110 ) ;
}
V_87 = F_78 ( V_77 ) ;
V_110 = F_4 ( V_87 ) ;
V_197 = F_4 ( F_38 ( V_77 ) ) ;
if ( F_45 ( V_4 -> V_2 ) ) {
V_110 &= ~ V_199 ;
V_110 |= V_197 & V_199 ;
}
V_110 &= ~ V_200 ;
if ( ( V_197 & V_201 ) == V_202 )
if ( F_45 ( V_4 -> V_2 ) &&
F_8 ( V_11 , V_25 ) )
V_110 |= V_203 ;
else
V_110 |= V_204 ;
else
V_110 |= V_205 ;
F_36 ( V_87 , V_110 | V_158 ) ;
if ( F_30 ( F_4 ( V_87 ) & V_206 , 100 ) )
F_100 ( L_43 , F_62 ( V_77 ) ) ;
}
static void F_113 ( struct V_3 * V_4 ,
enum V_76 V_81 )
{
T_1 V_110 , V_197 ;
F_95 ( V_4 -> V_125 -> V_85 < 5 ) ;
F_110 ( V_4 , (enum V_77 ) V_81 ) ;
F_111 ( V_4 , V_207 ) ;
V_110 = F_4 ( V_208 ) ;
V_110 |= V_198 ;
F_36 ( V_208 , V_110 ) ;
V_110 = V_158 ;
V_197 = F_4 ( F_38 ( V_81 ) ) ;
if ( ( V_197 & V_209 ) ==
V_202 )
V_110 |= V_204 ;
else
V_110 |= V_205 ;
F_36 ( V_210 , V_110 ) ;
if ( F_30 ( F_4 ( V_210 ) & V_206 , 100 ) )
F_100 ( L_44 ) ;
}
static void F_114 ( struct V_3 * V_4 ,
enum V_77 V_77 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_87 , V_110 ;
F_115 ( V_4 , V_77 ) ;
F_116 ( V_4 , V_77 ) ;
F_92 ( V_4 , V_77 ) ;
V_87 = F_78 ( V_77 ) ;
V_110 = F_4 ( V_87 ) ;
V_110 &= ~ V_158 ;
F_36 ( V_87 , V_110 ) ;
if ( F_30 ( ( F_4 ( V_87 ) & V_206 ) == 0 , 50 ) )
F_100 ( L_45 , F_62 ( V_77 ) ) ;
if ( ! F_45 ( V_2 ) ) {
V_87 = F_112 ( V_77 ) ;
V_110 = F_4 ( V_87 ) ;
V_110 &= ~ V_198 ;
F_36 ( V_87 , V_110 ) ;
}
}
static void F_117 ( struct V_3 * V_4 )
{
T_1 V_110 ;
V_110 = F_4 ( V_210 ) ;
V_110 &= ~ V_158 ;
F_36 ( V_210 , V_110 ) ;
if ( F_30 ( ( F_4 ( V_210 ) & V_206 ) == 0 , 50 ) )
F_100 ( L_46 ) ;
V_110 = F_4 ( V_208 ) ;
V_110 &= ~ V_198 ;
F_36 ( V_208 , V_110 ) ;
}
static void F_118 ( struct V_3 * V_4 , enum V_77 V_77 ,
bool V_211 )
{
enum V_76 V_81 = F_26 ( V_4 ,
V_77 ) ;
enum V_77 V_212 ;
int V_87 ;
T_1 V_110 ;
F_69 ( V_4 , V_77 ) ;
F_71 ( V_4 , V_77 ) ;
if ( F_51 ( V_4 -> V_2 ) )
V_212 = V_207 ;
else
V_212 = V_77 ;
if ( ! F_3 ( V_4 -> V_2 ) )
F_119 ( V_4 , V_77 ) ;
else {
if ( V_211 ) {
F_120 ( V_4 , V_212 ) ;
F_59 ( V_4 ,
(enum V_77 ) V_81 ) ;
}
}
V_87 = F_38 ( V_81 ) ;
V_110 = F_4 ( V_87 ) ;
if ( V_110 & V_143 )
return;
F_36 ( V_87 , V_110 | V_143 ) ;
F_33 ( V_4 -> V_2 , V_77 ) ;
}
static void F_121 ( struct V_3 * V_4 ,
enum V_77 V_77 )
{
enum V_76 V_81 = F_26 ( V_4 ,
V_77 ) ;
int V_87 ;
T_1 V_110 ;
F_69 ( V_4 , V_77 ) ;
F_71 ( V_4 , V_77 ) ;
if ( V_77 == V_131 && ( V_4 -> V_141 & V_142 ) )
return;
V_87 = F_38 ( V_81 ) ;
V_110 = F_4 ( V_87 ) ;
if ( ( V_110 & V_143 ) == 0 )
return;
F_36 ( V_87 , V_110 & ~ V_143 ) ;
F_37 ( V_4 -> V_2 , V_77 ) ;
}
void F_122 ( struct V_3 * V_4 ,
enum V_144 V_144 )
{
if ( V_4 -> V_125 -> V_85 >= 4 )
F_36 ( F_123 ( V_144 ) , F_4 ( F_123 ( V_144 ) ) ) ;
else
F_36 ( F_124 ( V_144 ) , F_4 ( F_124 ( V_144 ) ) ) ;
}
static void F_125 ( struct V_3 * V_4 ,
enum V_144 V_144 , enum V_77 V_77 )
{
int V_87 ;
T_1 V_110 ;
F_126 ( V_4 , V_77 ) ;
V_87 = F_67 ( V_144 ) ;
V_110 = F_4 ( V_87 ) ;
if ( V_110 & V_145 )
return;
F_36 ( V_87 , V_110 | V_145 ) ;
F_122 ( V_4 , V_144 ) ;
F_33 ( V_4 -> V_2 , V_77 ) ;
}
static void F_127 ( struct V_3 * V_4 ,
enum V_144 V_144 , enum V_77 V_77 )
{
int V_87 ;
T_1 V_110 ;
V_87 = F_67 ( V_144 ) ;
V_110 = F_4 ( V_87 ) ;
if ( ( V_110 & V_145 ) == 0 )
return;
F_36 ( V_87 , V_110 & ~ V_145 ) ;
F_122 ( V_4 , V_144 ) ;
F_33 ( V_4 -> V_2 , V_77 ) ;
}
static bool F_128 ( struct V_1 * V_2 )
{
#ifdef F_129
if ( F_35 ( V_2 ) -> V_85 >= 6 && V_213 )
return true ;
#endif
return false ;
}
int
F_130 ( struct V_1 * V_2 ,
struct V_214 * V_215 ,
struct V_216 * V_217 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_218 ;
int V_219 ;
switch ( V_215 -> V_220 ) {
case V_221 :
if ( F_131 ( V_2 ) || F_132 ( V_2 ) )
V_218 = 128 * 1024 ;
else if ( F_35 ( V_2 ) -> V_85 >= 4 )
V_218 = 4 * 1024 ;
else
V_218 = 64 * 1024 ;
break;
case V_222 :
V_218 = 0 ;
break;
case V_223 :
F_52 ( L_47 ) ;
return - V_224 ;
default:
F_133 () ;
}
if ( F_128 ( V_2 ) && V_218 < 256 * 1024 )
V_218 = 256 * 1024 ;
V_4 -> V_225 . V_226 = false ;
V_219 = F_134 ( V_215 , V_218 , V_217 ) ;
if ( V_219 )
goto V_227;
V_219 = F_135 ( V_215 ) ;
if ( V_219 )
goto V_228;
F_136 ( V_215 ) ;
V_4 -> V_225 . V_226 = true ;
return 0 ;
V_228:
F_137 ( V_215 ) ;
V_227:
V_4 -> V_225 . V_226 = true ;
return V_219 ;
}
void F_138 ( struct V_214 * V_215 )
{
F_139 ( V_215 ) ;
F_137 ( V_215 ) ;
}
unsigned long F_140 ( int * V_229 , int * V_230 ,
unsigned int V_220 ,
unsigned int V_231 ,
unsigned int V_232 )
{
if ( V_220 != V_221 ) {
unsigned int V_233 , V_234 ;
V_233 = * V_230 / 8 ;
* V_230 %= 8 ;
V_234 = * V_229 / ( 512 / V_231 ) ;
* V_229 %= 512 / V_231 ;
return V_233 * V_232 * 8 + V_234 * 4096 ;
} else {
unsigned int V_235 ;
V_235 = * V_230 * V_232 + * V_229 * V_231 ;
* V_230 = 0 ;
* V_229 = ( V_235 & 4095 ) / V_231 ;
return V_235 & - 4096 ;
}
}
static int F_141 ( struct V_10 * V_11 , struct V_236 * V_237 ,
int V_229 , int V_230 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_238 * V_239 ;
struct V_214 * V_215 ;
int V_144 = V_79 -> V_144 ;
unsigned long V_240 ;
T_1 V_241 ;
T_1 V_87 ;
switch ( V_144 ) {
case 0 :
case 1 :
break;
default:
F_100 ( L_48 , F_68 ( V_144 ) ) ;
return - V_224 ;
}
V_239 = F_142 ( V_237 ) ;
V_215 = V_239 -> V_215 ;
V_87 = F_67 ( V_144 ) ;
V_241 = F_4 ( V_87 ) ;
V_241 &= ~ V_242 ;
switch ( V_237 -> V_243 ) {
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
F_133 () ;
}
if ( F_35 ( V_2 ) -> V_85 >= 4 ) {
if ( V_215 -> V_220 != V_221 )
V_241 |= V_263 ;
else
V_241 &= ~ V_263 ;
}
if ( F_12 ( V_2 ) )
V_241 |= V_264 ;
F_36 ( V_87 , V_241 ) ;
V_240 = V_230 * V_237 -> V_265 [ 0 ] + V_229 * ( V_237 -> V_266 / 8 ) ;
if ( F_35 ( V_2 ) -> V_85 >= 4 ) {
V_79 -> V_267 =
F_140 ( & V_229 , & V_230 , V_215 -> V_220 ,
V_237 -> V_266 / 8 ,
V_237 -> V_265 [ 0 ] ) ;
V_240 -= V_79 -> V_267 ;
} else {
V_79 -> V_267 = V_240 ;
}
F_32 ( L_49 ,
F_143 ( V_215 ) , V_240 , V_229 , V_230 ,
V_237 -> V_265 [ 0 ] ) ;
F_36 ( F_144 ( V_144 ) , V_237 -> V_265 [ 0 ] ) ;
if ( F_35 ( V_2 ) -> V_85 >= 4 ) {
F_145 ( F_123 ( V_144 ) ,
F_143 ( V_215 ) + V_79 -> V_267 ) ;
F_36 ( F_146 ( V_144 ) , ( V_230 << 16 ) | V_229 ) ;
F_36 ( F_147 ( V_144 ) , V_240 ) ;
} else
F_36 ( F_124 ( V_144 ) , F_143 ( V_215 ) + V_240 ) ;
F_98 ( V_87 ) ;
return 0 ;
}
static int F_148 ( struct V_10 * V_11 ,
struct V_236 * V_237 , int V_229 , int V_230 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_238 * V_239 ;
struct V_214 * V_215 ;
int V_144 = V_79 -> V_144 ;
unsigned long V_240 ;
T_1 V_241 ;
T_1 V_87 ;
switch ( V_144 ) {
case 0 :
case 1 :
case 2 :
break;
default:
F_100 ( L_48 , F_68 ( V_144 ) ) ;
return - V_224 ;
}
V_239 = F_142 ( V_237 ) ;
V_215 = V_239 -> V_215 ;
V_87 = F_67 ( V_144 ) ;
V_241 = F_4 ( V_87 ) ;
V_241 &= ~ V_242 ;
switch ( V_237 -> V_243 ) {
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
F_133 () ;
}
if ( V_215 -> V_220 != V_221 )
V_241 |= V_263 ;
else
V_241 &= ~ V_263 ;
if ( F_149 ( V_2 ) )
V_241 &= ~ V_264 ;
else
V_241 |= V_264 ;
F_36 ( V_87 , V_241 ) ;
V_240 = V_230 * V_237 -> V_265 [ 0 ] + V_229 * ( V_237 -> V_266 / 8 ) ;
V_79 -> V_267 =
F_140 ( & V_229 , & V_230 , V_215 -> V_220 ,
V_237 -> V_266 / 8 ,
V_237 -> V_265 [ 0 ] ) ;
V_240 -= V_79 -> V_267 ;
F_32 ( L_49 ,
F_143 ( V_215 ) , V_240 , V_229 , V_230 ,
V_237 -> V_265 [ 0 ] ) ;
F_36 ( F_144 ( V_144 ) , V_237 -> V_265 [ 0 ] ) ;
F_145 ( F_123 ( V_144 ) ,
F_143 ( V_215 ) + V_79 -> V_267 ) ;
if ( F_149 ( V_2 ) ) {
F_36 ( F_150 ( V_144 ) , ( V_230 << 16 ) | V_229 ) ;
} else {
F_36 ( F_146 ( V_144 ) , ( V_230 << 16 ) | V_229 ) ;
F_36 ( F_147 ( V_144 ) , V_240 ) ;
}
F_98 ( V_87 ) ;
return 0 ;
}
static int
F_151 ( struct V_10 * V_11 , struct V_236 * V_237 ,
int V_229 , int V_230 , enum V_268 V_109 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_269 . V_270 )
V_4 -> V_269 . V_270 ( V_2 ) ;
F_152 ( V_11 ) ;
return V_4 -> V_269 . V_271 ( V_11 , V_237 , V_229 , V_230 ) ;
}
void F_153 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_11 ;
F_154 (crtc, &dev->mode_config.crtc_list, head) {
struct V_79 * V_79 = F_27 ( V_11 ) ;
enum V_144 V_144 = V_79 -> V_144 ;
F_155 ( V_2 , V_144 ) ;
F_156 ( V_2 , V_144 ) ;
}
F_154 (crtc, &dev->mode_config.crtc_list, head) {
struct V_79 * V_79 = F_27 ( V_11 ) ;
F_157 ( & V_11 -> V_272 ) ;
if ( V_79 -> V_192 )
V_4 -> V_269 . V_271 ( V_11 , V_11 -> V_237 ,
V_11 -> V_229 , V_11 -> V_230 ) ;
F_158 ( & V_11 -> V_272 ) ;
}
}
static int
F_159 ( struct V_236 * V_273 )
{
struct V_214 * V_215 = F_142 ( V_273 ) -> V_215 ;
struct V_3 * V_4 = V_215 -> V_114 . V_2 -> V_5 ;
bool V_274 = V_4 -> V_225 . V_226 ;
int V_219 ;
V_4 -> V_225 . V_226 = false ;
V_219 = F_160 ( V_215 ) ;
V_4 -> V_225 . V_226 = V_274 ;
return V_219 ;
}
static void F_161 ( struct V_10 * V_11 , int V_229 , int V_230 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_275 * V_276 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
if ( ! V_2 -> V_277 -> V_278 )
return;
V_276 = V_2 -> V_277 -> V_278 -> V_279 ;
if ( ! V_276 -> V_280 )
return;
switch ( V_79 -> V_77 ) {
case 0 :
V_276 -> V_280 -> V_281 = V_229 ;
V_276 -> V_280 -> V_282 = V_230 ;
break;
case 1 :
V_276 -> V_280 -> V_283 = V_229 ;
V_276 -> V_280 -> V_284 = V_230 ;
break;
default:
break;
}
}
static int
F_162 ( struct V_10 * V_11 , int V_229 , int V_230 ,
struct V_236 * V_237 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_236 * V_273 ;
int V_219 ;
if ( ! V_237 ) {
F_100 ( L_50 ) ;
return 0 ;
}
if ( V_79 -> V_144 > F_35 ( V_2 ) -> V_285 ) {
F_100 ( L_51 ,
F_68 ( V_79 -> V_144 ) ,
F_35 ( V_2 ) -> V_285 ) ;
return - V_224 ;
}
F_157 ( & V_2 -> V_286 ) ;
V_219 = F_130 ( V_2 ,
F_142 ( V_237 ) -> V_215 ,
NULL ) ;
if ( V_219 != 0 ) {
F_158 ( & V_2 -> V_286 ) ;
F_100 ( L_52 ) ;
return V_219 ;
}
if ( V_287 ) {
F_36 ( F_163 ( V_79 -> V_77 ) ,
( ( V_11 -> V_288 . V_289 - 1 ) << 16 ) |
( V_11 -> V_288 . V_290 - 1 ) ) ;
if ( ! V_79 -> V_80 . V_291 . V_108 &&
( F_8 ( V_11 , V_14 ) ||
F_8 ( V_11 , V_292 ) ) ) {
F_36 ( F_164 ( V_79 -> V_77 ) , 0 ) ;
F_36 ( F_165 ( V_79 -> V_77 ) , 0 ) ;
F_36 ( F_166 ( V_79 -> V_77 ) , 0 ) ;
}
}
V_219 = V_4 -> V_269 . V_271 ( V_11 , V_237 , V_229 , V_230 ) ;
if ( V_219 ) {
F_138 ( F_142 ( V_237 ) -> V_215 ) ;
F_158 ( & V_2 -> V_286 ) ;
F_100 ( L_53 ) ;
return V_219 ;
}
V_273 = V_11 -> V_237 ;
V_11 -> V_237 = V_237 ;
V_11 -> V_229 = V_229 ;
V_11 -> V_230 = V_230 ;
if ( V_273 ) {
if ( V_79 -> V_192 && V_273 != V_237 )
F_33 ( V_2 , V_79 -> V_77 ) ;
F_138 ( F_142 ( V_273 ) -> V_215 ) ;
}
F_167 ( V_2 ) ;
F_168 ( V_2 ) ;
F_158 ( & V_2 -> V_286 ) ;
F_161 ( V_11 , V_229 , V_230 ) ;
return 0 ;
}
static void F_169 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
int V_77 = V_79 -> V_77 ;
T_1 V_87 , V_293 ;
V_87 = F_56 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
if ( F_170 ( V_2 ) ) {
V_293 &= ~ V_294 ;
V_293 |= V_294 | V_295 ;
} else {
V_293 &= ~ V_296 ;
V_293 |= V_296 | V_295 ;
}
F_36 ( V_87 , V_293 ) ;
V_87 = F_58 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
if ( F_80 ( V_2 ) ) {
V_293 &= ~ V_297 ;
V_293 |= V_298 ;
} else {
V_293 &= ~ V_296 ;
V_293 |= V_296 ;
}
F_36 ( V_87 , V_293 | V_299 ) ;
F_98 ( V_87 ) ;
F_99 ( 1000 ) ;
if ( F_170 ( V_2 ) )
F_36 ( V_87 , F_4 ( V_87 ) | V_300 |
V_301 ) ;
}
static bool F_171 ( struct V_79 * V_11 )
{
return V_11 -> V_114 . V_108 && V_11 -> V_192 &&
V_11 -> V_80 . V_302 ;
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_303 =
F_27 ( V_4 -> V_78 [ V_140 ] ) ;
struct V_79 * V_304 =
F_27 ( V_4 -> V_78 [ V_305 ] ) ;
T_4 V_293 ;
if ( ! F_171 ( V_303 ) &&
! F_171 ( V_304 ) ) {
F_2 ( F_4 ( F_58 ( V_140 ) ) & V_124 ) ;
F_2 ( F_4 ( F_58 ( V_305 ) ) & V_124 ) ;
V_293 = F_4 ( V_306 ) ;
V_293 &= ~ V_307 ;
F_32 ( L_54 ) ;
F_36 ( V_306 , V_293 ) ;
}
}
static void F_173 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
int V_77 = V_79 -> V_77 ;
int V_144 = V_79 -> V_144 ;
T_1 V_87 , V_293 , V_308 ;
F_126 ( V_4 , V_77 ) ;
F_174 ( V_4 , V_144 ) ;
V_87 = F_175 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_309 ;
V_293 &= ~ V_310 ;
F_36 ( V_87 , V_293 ) ;
F_4 ( V_87 ) ;
F_99 ( 150 ) ;
V_87 = F_56 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_311 ;
V_293 |= F_176 ( V_79 -> V_80 . V_312 ) ;
V_293 &= ~ V_296 ;
V_293 |= V_313 ;
F_36 ( V_87 , V_293 | V_123 ) ;
V_87 = F_58 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_296 ;
V_293 |= V_313 ;
F_36 ( V_87 , V_293 | V_124 ) ;
F_98 ( V_87 ) ;
F_99 ( 150 ) ;
F_36 ( F_177 ( V_77 ) , V_314 ) ;
F_36 ( F_177 ( V_77 ) , V_314 |
V_315 ) ;
V_87 = F_178 ( V_77 ) ;
for ( V_308 = 0 ; V_308 < 5 ; V_308 ++ ) {
V_293 = F_4 ( V_87 ) ;
F_32 ( L_55 , V_293 ) ;
if ( ( V_293 & V_310 ) ) {
F_32 ( L_56 ) ;
F_36 ( V_87 , V_293 | V_310 ) ;
break;
}
}
if ( V_308 == 5 )
F_100 ( L_57 ) ;
V_87 = F_56 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_296 ;
V_293 |= V_316 ;
F_36 ( V_87 , V_293 ) ;
V_87 = F_58 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_296 ;
V_293 |= V_316 ;
F_36 ( V_87 , V_293 ) ;
F_98 ( V_87 ) ;
F_99 ( 150 ) ;
V_87 = F_178 ( V_77 ) ;
for ( V_308 = 0 ; V_308 < 5 ; V_308 ++ ) {
V_293 = F_4 ( V_87 ) ;
F_32 ( L_55 , V_293 ) ;
if ( V_293 & V_309 ) {
F_36 ( V_87 , V_293 | V_309 ) ;
F_32 ( L_58 ) ;
break;
}
}
if ( V_308 == 5 )
F_100 ( L_59 ) ;
F_32 ( L_60 ) ;
}
static void F_179 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
int V_77 = V_79 -> V_77 ;
T_1 V_87 , V_293 , V_146 , V_317 ;
V_87 = F_175 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_309 ;
V_293 &= ~ V_310 ;
F_36 ( V_87 , V_293 ) ;
F_98 ( V_87 ) ;
F_99 ( 150 ) ;
V_87 = F_56 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_311 ;
V_293 |= F_176 ( V_79 -> V_80 . V_312 ) ;
V_293 &= ~ V_296 ;
V_293 |= V_313 ;
V_293 &= ~ V_318 ;
V_293 |= V_319 ;
F_36 ( V_87 , V_293 | V_123 ) ;
F_36 ( F_180 ( V_77 ) ,
V_320 | V_321 ) ;
V_87 = F_58 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
if ( F_80 ( V_2 ) ) {
V_293 &= ~ V_297 ;
V_293 |= V_322 ;
} else {
V_293 &= ~ V_296 ;
V_293 |= V_313 ;
}
F_36 ( V_87 , V_293 | V_124 ) ;
F_98 ( V_87 ) ;
F_99 ( 150 ) ;
for ( V_146 = 0 ; V_146 < 4 ; V_146 ++ ) {
V_87 = F_56 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_318 ;
V_293 |= V_323 [ V_146 ] ;
F_36 ( V_87 , V_293 ) ;
F_98 ( V_87 ) ;
F_99 ( 500 ) ;
for ( V_317 = 0 ; V_317 < 5 ; V_317 ++ ) {
V_87 = F_178 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
F_32 ( L_55 , V_293 ) ;
if ( V_293 & V_310 ) {
F_36 ( V_87 , V_293 | V_310 ) ;
F_32 ( L_56 ) ;
break;
}
F_99 ( 50 ) ;
}
if ( V_317 < 5 )
break;
}
if ( V_146 == 4 )
F_100 ( L_57 ) ;
V_87 = F_56 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_296 ;
V_293 |= V_316 ;
if ( F_181 ( V_2 ) ) {
V_293 &= ~ V_318 ;
V_293 |= V_319 ;
}
F_36 ( V_87 , V_293 ) ;
V_87 = F_58 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
if ( F_80 ( V_2 ) ) {
V_293 &= ~ V_297 ;
V_293 |= V_324 ;
} else {
V_293 &= ~ V_296 ;
V_293 |= V_316 ;
}
F_36 ( V_87 , V_293 ) ;
F_98 ( V_87 ) ;
F_99 ( 150 ) ;
for ( V_146 = 0 ; V_146 < 4 ; V_146 ++ ) {
V_87 = F_56 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_318 ;
V_293 |= V_323 [ V_146 ] ;
F_36 ( V_87 , V_293 ) ;
F_98 ( V_87 ) ;
F_99 ( 500 ) ;
for ( V_317 = 0 ; V_317 < 5 ; V_317 ++ ) {
V_87 = F_178 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
F_32 ( L_55 , V_293 ) ;
if ( V_293 & V_309 ) {
F_36 ( V_87 , V_293 | V_309 ) ;
F_32 ( L_58 ) ;
break;
}
F_99 ( 50 ) ;
}
if ( V_317 < 5 )
break;
}
if ( V_146 == 4 )
F_100 ( L_59 ) ;
F_32 ( L_61 ) ;
}
static void F_182 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
int V_77 = V_79 -> V_77 ;
T_1 V_87 , V_293 , V_146 , V_325 ;
V_87 = F_175 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_309 ;
V_293 &= ~ V_310 ;
F_36 ( V_87 , V_293 ) ;
F_98 ( V_87 ) ;
F_99 ( 150 ) ;
F_32 ( L_62 ,
F_4 ( F_178 ( V_77 ) ) ) ;
for ( V_325 = 0 ; V_325 < F_183 ( V_323 ) * 2 ; V_325 ++ ) {
V_87 = F_56 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ ( V_326 | V_294 ) ;
V_293 &= ~ V_123 ;
F_36 ( V_87 , V_293 ) ;
V_87 = F_58 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_326 ;
V_293 &= ~ V_297 ;
V_293 &= ~ V_124 ;
F_36 ( V_87 , V_293 ) ;
V_87 = F_56 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_311 ;
V_293 |= F_176 ( V_79 -> V_80 . V_312 ) ;
V_293 |= V_327 ;
V_293 &= ~ V_318 ;
V_293 |= V_323 [ V_325 / 2 ] ;
V_293 |= V_328 ;
F_36 ( V_87 , V_293 | V_123 ) ;
F_36 ( F_180 ( V_77 ) ,
V_320 | V_321 ) ;
V_87 = F_58 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 |= V_322 ;
V_293 |= V_328 ;
F_36 ( V_87 , V_293 | V_124 ) ;
F_98 ( V_87 ) ;
F_99 ( 1 ) ;
for ( V_146 = 0 ; V_146 < 4 ; V_146 ++ ) {
V_87 = F_178 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
F_32 ( L_55 , V_293 ) ;
if ( V_293 & V_310 ||
( F_4 ( V_87 ) & V_310 ) ) {
F_36 ( V_87 , V_293 | V_310 ) ;
F_32 ( L_63 ,
V_146 ) ;
break;
}
F_99 ( 1 ) ;
}
if ( V_146 == 4 ) {
F_32 ( L_64 , V_325 / 2 ) ;
continue;
}
V_87 = F_56 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_294 ;
V_293 |= V_329 ;
F_36 ( V_87 , V_293 ) ;
V_87 = F_58 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_297 ;
V_293 |= V_324 ;
F_36 ( V_87 , V_293 ) ;
F_98 ( V_87 ) ;
F_99 ( 2 ) ;
for ( V_146 = 0 ; V_146 < 4 ; V_146 ++ ) {
V_87 = F_178 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
F_32 ( L_55 , V_293 ) ;
if ( V_293 & V_309 ||
( F_4 ( V_87 ) & V_309 ) ) {
F_36 ( V_87 , V_293 | V_309 ) ;
F_32 ( L_65 ,
V_146 ) ;
goto V_330;
}
F_99 ( 2 ) ;
}
if ( V_146 == 4 )
F_32 ( L_66 , V_325 / 2 ) ;
}
V_330:
F_32 ( L_61 ) ;
}
static void F_184 ( struct V_79 * V_79 )
{
struct V_1 * V_2 = V_79 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_77 = V_79 -> V_77 ;
T_1 V_87 , V_293 ;
V_87 = F_58 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ ( V_311 | ( 0x7 << 16 ) ) ;
V_293 |= F_176 ( V_79 -> V_80 . V_312 ) ;
V_293 |= ( F_4 ( F_38 ( V_77 ) ) & V_199 ) << 11 ;
F_36 ( V_87 , V_293 | V_127 ) ;
F_98 ( V_87 ) ;
F_99 ( 200 ) ;
V_293 = F_4 ( V_87 ) ;
F_36 ( V_87 , V_293 | V_331 ) ;
F_98 ( V_87 ) ;
F_99 ( 200 ) ;
V_87 = F_56 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
if ( ( V_293 & V_126 ) == 0 ) {
F_36 ( V_87 , V_293 | V_126 ) ;
F_98 ( V_87 ) ;
F_99 ( 100 ) ;
}
}
static void F_185 ( struct V_79 * V_79 )
{
struct V_1 * V_2 = V_79 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_77 = V_79 -> V_77 ;
T_1 V_87 , V_293 ;
V_87 = F_58 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
F_36 ( V_87 , V_293 & ~ V_331 ) ;
V_87 = F_56 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
F_36 ( V_87 , V_293 & ~ V_126 ) ;
F_98 ( V_87 ) ;
F_99 ( 100 ) ;
V_87 = F_58 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
F_36 ( V_87 , V_293 & ~ V_127 ) ;
F_98 ( V_87 ) ;
F_99 ( 100 ) ;
}
static void F_186 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
int V_77 = V_79 -> V_77 ;
T_1 V_87 , V_293 ;
V_87 = F_56 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
F_36 ( V_87 , V_293 & ~ V_123 ) ;
F_98 ( V_87 ) ;
V_87 = F_58 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ ( 0x7 << 16 ) ;
V_293 |= ( F_4 ( F_38 ( V_77 ) ) & V_199 ) << 11 ;
F_36 ( V_87 , V_293 & ~ V_124 ) ;
F_98 ( V_87 ) ;
F_99 ( 100 ) ;
if ( F_45 ( V_2 ) ) {
F_36 ( F_177 ( V_77 ) , V_314 ) ;
}
V_87 = F_56 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ V_296 ;
V_293 |= V_313 ;
F_36 ( V_87 , V_293 ) ;
V_87 = F_58 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
if ( F_80 ( V_2 ) ) {
V_293 &= ~ V_297 ;
V_293 |= V_322 ;
} else {
V_293 &= ~ V_296 ;
V_293 |= V_313 ;
}
V_293 &= ~ ( 0x07 << 16 ) ;
V_293 |= ( F_4 ( F_38 ( V_77 ) ) & V_199 ) << 11 ;
F_36 ( V_87 , V_293 ) ;
F_98 ( V_87 ) ;
F_99 ( 100 ) ;
}
static bool F_187 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
unsigned long V_332 ;
bool V_333 ;
if ( F_188 ( & V_4 -> V_334 ) ||
V_79 -> V_335 != F_189 ( & V_4 -> V_334 . V_335 ) )
return false ;
F_190 ( & V_2 -> V_336 , V_332 ) ;
V_333 = F_27 ( V_11 ) -> V_337 != NULL ;
F_191 ( & V_2 -> V_336 , V_332 ) ;
return V_333 ;
}
static void F_192 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_11 -> V_237 == NULL )
return;
F_2 ( F_193 ( & V_4 -> V_338 ) ) ;
F_194 ( V_4 -> V_338 ,
! F_187 ( V_11 ) ) ;
F_157 ( & V_2 -> V_286 ) ;
F_159 ( V_11 -> V_237 ) ;
F_158 ( & V_2 -> V_286 ) ;
}
static void F_195 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_339 , V_340 , V_341 , V_342 = 0 ;
T_1 V_293 ;
F_157 ( & V_4 -> V_343 ) ;
F_36 ( V_344 , V_345 ) ;
F_196 ( V_4 , V_346 ,
F_197 ( V_4 , V_346 , V_347 ) |
V_348 ,
V_347 ) ;
if ( V_11 -> V_288 . clock == 20000 ) {
V_341 = 1 ;
V_339 = 0x41 ;
V_340 = 0x20 ;
} else {
T_1 V_349 = 172800 * 1000 ;
T_1 V_350 = 64 ;
T_1 V_351 , V_352 , V_353 ;
V_351 = ( V_349 / V_11 -> V_288 . clock ) ;
V_352 = V_351 / V_350 ;
V_353 = V_351 % V_350 ;
V_341 = 0 ;
V_339 = V_352 - 2 ;
V_340 = V_353 ;
}
F_2 ( F_198 ( V_339 ) &
~ V_354 ) ;
F_2 ( F_199 ( V_342 ) &
~ V_355 ) ;
F_32 ( L_67 ,
V_11 -> V_288 . clock ,
V_341 ,
V_339 ,
V_342 ,
V_340 ) ;
V_293 = F_197 ( V_4 , V_356 , V_347 ) ;
V_293 &= ~ V_354 ;
V_293 |= F_198 ( V_339 ) ;
V_293 &= ~ V_355 ;
V_293 |= F_200 ( V_340 ) ;
V_293 |= F_199 ( V_342 ) ;
V_293 |= V_357 ;
F_196 ( V_4 , V_356 , V_293 , V_347 ) ;
V_293 = F_197 ( V_4 , V_358 , V_347 ) ;
V_293 &= ~ F_201 ( 1 ) ;
V_293 |= F_201 ( V_341 ) ;
F_196 ( V_4 , V_358 , V_293 , V_347 ) ;
V_293 = F_197 ( V_4 , V_346 , V_347 ) ;
V_293 &= ~ V_348 ;
F_196 ( V_4 , V_346 , V_293 , V_347 ) ;
F_99 ( 24 ) ;
F_36 ( V_344 , V_359 ) ;
F_158 ( & V_4 -> V_343 ) ;
}
static void F_202 ( struct V_79 * V_11 ,
enum V_77 V_212 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_76 V_81 = V_11 -> V_80 . V_81 ;
F_36 ( F_203 ( V_212 ) ,
F_4 ( F_204 ( V_81 ) ) ) ;
F_36 ( F_205 ( V_212 ) ,
F_4 ( F_206 ( V_81 ) ) ) ;
F_36 ( F_207 ( V_212 ) ,
F_4 ( F_208 ( V_81 ) ) ) ;
F_36 ( F_209 ( V_212 ) ,
F_4 ( F_210 ( V_81 ) ) ) ;
F_36 ( F_211 ( V_212 ) ,
F_4 ( F_212 ( V_81 ) ) ) ;
F_36 ( F_213 ( V_212 ) ,
F_4 ( F_214 ( V_81 ) ) ) ;
F_36 ( F_215 ( V_212 ) ,
F_4 ( F_216 ( V_81 ) ) ) ;
}
static void F_217 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_293 ;
V_293 = F_4 ( V_306 ) ;
if ( V_293 & V_307 )
return;
F_2 ( F_4 ( F_58 ( V_140 ) ) & V_124 ) ;
F_2 ( F_4 ( F_58 ( V_305 ) ) & V_124 ) ;
V_293 |= V_307 ;
F_32 ( L_68 ) ;
F_36 ( V_306 , V_293 ) ;
F_98 ( V_306 ) ;
}
static void F_218 ( struct V_79 * V_79 )
{
struct V_1 * V_2 = V_79 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_79 -> V_77 ) {
case V_131 :
break;
case V_140 :
if ( V_79 -> V_80 . V_312 > 2 )
F_2 ( F_4 ( V_306 ) & V_307 ) ;
else
F_217 ( V_2 ) ;
break;
case V_305 :
F_217 ( V_2 ) ;
break;
default:
F_133 () ;
}
}
static void F_219 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
int V_77 = V_79 -> V_77 ;
T_1 V_87 , V_293 ;
F_77 ( V_4 , V_77 ) ;
if ( F_170 ( V_2 ) )
F_218 ( V_79 ) ;
F_36 ( F_220 ( V_77 ) ,
F_4 ( F_221 ( V_77 ) ) & V_360 ) ;
V_4 -> V_269 . V_361 ( V_11 ) ;
if ( F_80 ( V_2 ) ) {
T_1 V_362 ;
V_293 = F_4 ( V_363 ) ;
V_293 |= F_222 ( V_77 ) ;
V_362 = F_223 ( V_77 ) ;
if ( V_79 -> V_80 . V_115 == V_364 )
V_293 |= V_362 ;
else
V_293 &= ~ V_362 ;
F_36 ( V_363 , V_293 ) ;
}
F_105 ( V_79 ) ;
F_61 ( V_4 , V_77 ) ;
F_202 ( V_79 , V_77 ) ;
F_169 ( V_11 ) ;
if ( F_80 ( V_2 ) &&
( F_8 ( V_11 , V_365 ) ||
F_8 ( V_11 , V_292 ) ) ) {
T_1 V_366 = ( F_4 ( F_38 ( V_77 ) ) & V_199 ) >> 5 ;
V_87 = F_81 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ ( V_163 |
V_367 |
V_368 ) ;
V_293 |= ( V_369 |
V_370 ) ;
V_293 |= V_366 << 9 ;
if ( V_11 -> V_288 . V_332 & V_371 )
V_293 |= V_372 ;
if ( V_11 -> V_288 . V_332 & V_373 )
V_293 |= V_374 ;
switch ( F_224 ( V_11 ) ) {
case V_175 :
V_293 |= V_176 ;
break;
case V_177 :
V_293 |= V_178 ;
break;
case V_179 :
V_293 |= V_180 ;
break;
default:
F_133 () ;
}
F_36 ( V_87 , V_293 ) ;
}
F_109 ( V_4 , V_77 ) ;
}
static void F_225 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
enum V_76 V_81 = V_79 -> V_80 . V_81 ;
F_77 ( V_4 , V_207 ) ;
F_195 ( V_11 ) ;
F_202 ( V_79 , V_131 ) ;
F_113 ( V_4 , V_81 ) ;
}
static void F_226 ( struct V_79 * V_11 )
{
struct V_113 * V_117 = F_49 ( V_11 ) ;
if ( V_117 == NULL )
return;
if ( V_117 -> V_191 == 0 ) {
F_39 ( 1 , L_69 , V_117 -> V_121 ) ;
return;
}
if ( -- V_117 -> V_191 == 0 ) {
F_2 ( V_117 -> V_193 ) ;
F_2 ( V_117 -> V_192 ) ;
}
V_11 -> V_80 . V_115 = V_375 ;
}
static struct V_113 * F_227 ( struct V_79 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_114 . V_2 -> V_5 ;
struct V_113 * V_117 = F_49 ( V_11 ) ;
enum V_376 V_146 ;
if ( V_117 ) {
F_32 ( L_70 ,
V_11 -> V_114 . V_114 . V_194 , V_117 -> V_121 ) ;
F_226 ( V_11 ) ;
}
if ( F_45 ( V_4 -> V_2 ) ) {
V_146 = (enum V_376 ) V_11 -> V_77 ;
V_117 = & V_4 -> V_116 [ V_146 ] ;
F_32 ( L_71 ,
V_11 -> V_114 . V_114 . V_194 , V_117 -> V_121 ) ;
goto V_61;
}
for ( V_146 = 0 ; V_146 < V_4 -> V_377 ; V_146 ++ ) {
V_117 = & V_4 -> V_116 [ V_146 ] ;
if ( V_117 -> V_191 == 0 )
continue;
if ( memcmp ( & V_11 -> V_80 . V_185 , & V_117 -> V_119 ,
sizeof( V_117 -> V_119 ) ) == 0 ) {
F_32 ( L_72 ,
V_11 -> V_114 . V_114 . V_194 ,
V_117 -> V_121 , V_117 -> V_191 , V_117 -> V_192 ) ;
goto V_61;
}
}
for ( V_146 = 0 ; V_146 < V_4 -> V_377 ; V_146 ++ ) {
V_117 = & V_4 -> V_116 [ V_146 ] ;
if ( V_117 -> V_191 == 0 ) {
F_32 ( L_73 ,
V_11 -> V_114 . V_114 . V_194 , V_117 -> V_121 ) ;
goto V_61;
}
}
return NULL ;
V_61:
V_11 -> V_80 . V_115 = V_146 ;
F_52 ( L_74 , V_117 -> V_121 ,
F_62 ( V_11 -> V_77 ) ) ;
if ( V_117 -> V_192 == 0 ) {
memcpy ( & V_117 -> V_119 , & V_11 -> V_80 . V_185 ,
sizeof( V_117 -> V_119 ) ) ;
F_52 ( L_75 , V_117 -> V_121 ) ;
F_2 ( V_117 -> V_193 ) ;
F_108 ( V_4 , V_117 ) ;
V_117 -> V_378 ( V_4 , V_117 ) ;
}
V_117 -> V_191 ++ ;
return V_117 ;
}
static void F_228 ( struct V_1 * V_2 , int V_77 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_379 = F_40 ( V_77 ) ;
T_1 V_293 ;
V_293 = F_4 ( V_379 ) ;
F_99 ( 500 ) ;
if ( F_30 ( F_4 ( V_379 ) != V_293 , 5 ) ) {
if ( F_30 ( F_4 ( V_379 ) != V_293 , 5 ) )
F_100 ( L_76 , F_62 ( V_77 ) ) ;
}
}
static void F_229 ( struct V_79 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_77 = V_11 -> V_77 ;
if ( V_11 -> V_80 . V_291 . V_108 ) {
if ( F_170 ( V_2 ) || F_149 ( V_2 ) )
F_36 ( F_164 ( V_77 ) , V_380 | V_381 |
F_230 ( V_77 ) ) ;
else
F_36 ( F_164 ( V_77 ) , V_380 | V_381 ) ;
F_36 ( F_165 ( V_77 ) , V_11 -> V_80 . V_291 . V_382 ) ;
F_36 ( F_166 ( V_77 ) , V_11 -> V_80 . V_291 . V_383 ) ;
}
}
static void F_231 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
enum V_77 V_77 = F_27 ( V_11 ) -> V_77 ;
struct V_384 * V_384 ;
F_154 (intel_plane, &dev->mode_config.plane_list, base.head)
if ( V_384 -> V_77 == V_77 )
F_232 ( & V_384 -> V_114 ) ;
}
static void F_233 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
enum V_77 V_77 = F_27 ( V_11 ) -> V_77 ;
struct V_384 * V_384 ;
F_154 (intel_plane, &dev->mode_config.plane_list, base.head)
if ( V_384 -> V_77 == V_77 )
F_234 ( & V_384 -> V_114 ) ;
}
static void F_235 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_48 * V_49 ;
int V_77 = V_79 -> V_77 ;
int V_144 = V_79 -> V_144 ;
F_2 ( ! V_11 -> V_108 ) ;
if ( V_79 -> V_192 )
return;
V_79 -> V_192 = true ;
F_236 ( V_2 , V_77 , true ) ;
F_237 ( V_2 , V_77 , true ) ;
F_238 ( V_2 ) ;
F_19 (dev, crtc, encoder)
if ( V_49 -> V_385 )
V_49 -> V_385 ( V_49 ) ;
if ( V_79 -> V_80 . V_302 ) {
F_184 ( V_79 ) ;
} else {
F_115 ( V_4 , V_77 ) ;
F_116 ( V_4 , V_77 ) ;
}
F_229 ( V_79 ) ;
F_239 ( V_11 ) ;
F_118 ( V_4 , V_77 ,
V_79 -> V_80 . V_302 ) ;
F_125 ( V_4 , V_144 , V_77 ) ;
F_231 ( V_11 ) ;
F_240 ( V_11 , true ) ;
if ( V_79 -> V_80 . V_302 )
F_219 ( V_11 ) ;
F_157 ( & V_2 -> V_286 ) ;
F_167 ( V_2 ) ;
F_158 ( & V_2 -> V_286 ) ;
F_19 (dev, crtc, encoder)
V_49 -> V_195 ( V_49 ) ;
if ( F_80 ( V_2 ) )
F_228 ( V_2 , V_79 -> V_77 ) ;
F_33 ( V_2 , V_79 -> V_77 ) ;
}
static bool F_241 ( struct V_79 * V_11 )
{
return F_242 ( V_11 -> V_114 . V_2 ) && V_11 -> V_77 == V_131 ;
}
static void F_243 ( struct V_79 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_114 . V_2 -> V_5 ;
if ( ! V_11 -> V_80 . V_386 )
return;
F_174 ( V_4 , V_11 -> V_144 ) ;
F_36 ( V_387 , V_388 ) ;
}
static void F_244 ( struct V_79 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_11 -> V_80 . V_386 )
return;
F_174 ( V_4 , V_11 -> V_144 ) ;
F_36 ( V_387 , 0 ) ;
F_33 ( V_2 , V_11 -> V_77 ) ;
}
static void F_245 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_48 * V_49 ;
int V_77 = V_79 -> V_77 ;
int V_144 = V_79 -> V_144 ;
F_2 ( ! V_11 -> V_108 ) ;
if ( V_79 -> V_192 )
return;
V_79 -> V_192 = true ;
F_236 ( V_2 , V_77 , true ) ;
if ( V_79 -> V_80 . V_302 )
F_237 ( V_2 , V_207 , true ) ;
F_238 ( V_2 ) ;
if ( V_79 -> V_80 . V_302 )
V_4 -> V_269 . V_361 ( V_11 ) ;
F_19 (dev, crtc, encoder)
if ( V_49 -> V_385 )
V_49 -> V_385 ( V_49 ) ;
F_246 ( V_79 ) ;
F_229 ( V_79 ) ;
F_239 ( V_11 ) ;
F_247 ( V_11 ) ;
F_248 ( V_11 ) ;
F_118 ( V_4 , V_77 ,
V_79 -> V_80 . V_302 ) ;
F_125 ( V_4 , V_144 , V_77 ) ;
F_231 ( V_11 ) ;
F_240 ( V_11 , true ) ;
F_243 ( V_79 ) ;
if ( V_79 -> V_80 . V_302 )
F_225 ( V_11 ) ;
F_157 ( & V_2 -> V_286 ) ;
F_167 ( V_2 ) ;
F_158 ( & V_2 -> V_286 ) ;
F_19 (dev, crtc, encoder)
V_49 -> V_195 ( V_49 ) ;
F_33 ( V_2 , V_79 -> V_77 ) ;
}
static void F_249 ( struct V_79 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_77 = V_11 -> V_77 ;
if ( V_11 -> V_80 . V_291 . V_108 ) {
F_36 ( F_164 ( V_77 ) , 0 ) ;
F_36 ( F_165 ( V_77 ) , 0 ) ;
F_36 ( F_166 ( V_77 ) , 0 ) ;
}
}
static void F_250 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_48 * V_49 ;
int V_77 = V_79 -> V_77 ;
int V_144 = V_79 -> V_144 ;
T_1 V_87 , V_293 ;
if ( ! V_79 -> V_192 )
return;
F_19 (dev, crtc, encoder)
V_49 -> V_196 ( V_49 ) ;
F_192 ( V_11 ) ;
F_251 ( V_2 , V_77 ) ;
if ( V_4 -> V_389 . V_144 == V_144 )
F_252 ( V_2 ) ;
F_240 ( V_11 , false ) ;
F_233 ( V_11 ) ;
F_127 ( V_4 , V_144 , V_77 ) ;
if ( V_79 -> V_80 . V_302 )
F_237 ( V_2 , V_77 , false ) ;
F_121 ( V_4 , V_77 ) ;
F_249 ( V_79 ) ;
F_19 (dev, crtc, encoder)
if ( V_49 -> V_390 )
V_49 -> V_390 ( V_49 ) ;
if ( V_79 -> V_80 . V_302 ) {
F_186 ( V_11 ) ;
F_114 ( V_4 , V_77 ) ;
F_237 ( V_2 , V_77 , true ) ;
if ( F_80 ( V_2 ) ) {
V_87 = F_81 ( V_77 ) ;
V_293 = F_4 ( V_87 ) ;
V_293 &= ~ ( V_369 |
V_163 ) ;
V_293 |= V_391 ;
F_36 ( V_87 , V_293 ) ;
V_293 = F_4 ( V_363 ) ;
V_293 &= ~ ( F_222 ( V_77 ) | F_223 ( V_77 ) ) ;
F_36 ( V_363 , V_293 ) ;
}
F_107 ( V_79 ) ;
F_185 ( V_79 ) ;
}
V_79 -> V_192 = false ;
F_238 ( V_2 ) ;
F_157 ( & V_2 -> V_286 ) ;
F_167 ( V_2 ) ;
F_158 ( & V_2 -> V_286 ) ;
}
static void F_253 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_48 * V_49 ;
int V_77 = V_79 -> V_77 ;
int V_144 = V_79 -> V_144 ;
enum V_76 V_81 = V_79 -> V_80 . V_81 ;
if ( ! V_79 -> V_192 )
return;
F_19 (dev, crtc, encoder)
V_49 -> V_196 ( V_49 ) ;
F_192 ( V_11 ) ;
F_251 ( V_2 , V_77 ) ;
if ( V_4 -> V_389 . V_144 == V_144 )
F_252 ( V_2 ) ;
F_244 ( V_79 ) ;
F_240 ( V_11 , false ) ;
F_233 ( V_11 ) ;
F_127 ( V_4 , V_144 , V_77 ) ;
if ( V_79 -> V_80 . V_302 )
F_237 ( V_2 , V_207 , false ) ;
F_121 ( V_4 , V_77 ) ;
F_254 ( V_4 , V_81 ) ;
F_249 ( V_79 ) ;
F_255 ( V_79 ) ;
F_19 (dev, crtc, encoder)
if ( V_49 -> V_390 )
V_49 -> V_390 ( V_49 ) ;
if ( V_79 -> V_80 . V_302 ) {
F_117 ( V_4 ) ;
F_237 ( V_2 , V_207 , true ) ;
F_256 ( V_11 ) ;
}
V_79 -> V_192 = false ;
F_238 ( V_2 ) ;
F_157 ( & V_2 -> V_286 ) ;
F_167 ( V_2 ) ;
F_158 ( & V_2 -> V_286 ) ;
}
static void F_257 ( struct V_10 * V_11 )
{
struct V_79 * V_79 = F_27 ( V_11 ) ;
F_226 ( V_79 ) ;
}
static void F_258 ( struct V_10 * V_11 )
{
F_259 ( V_11 ) ;
}
static void F_260 ( struct V_79 * V_79 , bool V_195 )
{
if ( ! V_195 && V_79 -> V_392 ) {
struct V_1 * V_2 = V_79 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_157 ( & V_2 -> V_286 ) ;
V_4 -> V_225 . V_226 = false ;
( void ) F_261 ( V_79 -> V_392 ) ;
V_4 -> V_225 . V_226 = true ;
F_158 ( & V_2 -> V_286 ) ;
}
}
static void
F_262 ( struct V_3 * V_4 , enum V_77 V_77 )
{
T_1 V_393 = F_4 ( F_263 ( V_77 ) ) ;
if ( ( V_393 & V_394 ) == 0 ) {
T_1 V_395 = F_4 ( V_396 ) ;
F_36 ( V_396 , V_395 & ~ V_397 ) ;
F_36 ( F_263 ( V_77 ) , V_398 ) ;
F_33 ( V_4 -> V_2 , V_77 ) ;
F_36 ( F_263 ( V_77 ) , V_393 ) ;
F_36 ( F_264 ( V_77 ) , F_4 ( F_264 ( V_77 ) ) ) ;
F_36 ( V_396 , V_395 ) ;
}
}
static void F_265 ( struct V_79 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_399 * V_400 = & V_11 -> V_80 ;
if ( ! V_11 -> V_80 . V_401 . V_402 )
return;
F_2 ( F_4 ( V_403 ) & V_404 ) ;
F_94 ( V_4 , V_11 -> V_77 ) ;
F_36 ( V_405 , V_400 -> V_401 . V_406 ) ;
F_36 ( V_403 , V_400 -> V_401 . V_402 ) ;
F_36 ( F_266 ( V_11 -> V_77 ) , 0 ) ;
}
static void F_267 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_48 * V_49 ;
int V_77 = V_79 -> V_77 ;
int V_144 = V_79 -> V_144 ;
F_2 ( ! V_11 -> V_108 ) ;
if ( V_79 -> V_192 )
return;
V_79 -> V_192 = true ;
F_238 ( V_2 ) ;
F_19 (dev, crtc, encoder)
if ( V_49 -> V_407 )
V_49 -> V_407 ( V_49 ) ;
F_93 ( V_79 ) ;
F_19 (dev, crtc, encoder)
if ( V_49 -> V_385 )
V_49 -> V_385 ( V_49 ) ;
F_265 ( V_79 ) ;
F_239 ( V_11 ) ;
F_118 ( V_4 , V_77 , false ) ;
F_125 ( V_4 , V_144 , V_77 ) ;
F_231 ( V_11 ) ;
F_240 ( V_11 , true ) ;
F_167 ( V_2 ) ;
F_19 (dev, crtc, encoder)
V_49 -> V_195 ( V_49 ) ;
}
static void F_268 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_48 * V_49 ;
int V_77 = V_79 -> V_77 ;
int V_144 = V_79 -> V_144 ;
F_2 ( ! V_11 -> V_108 ) ;
if ( V_79 -> V_192 )
return;
V_79 -> V_192 = true ;
F_238 ( V_2 ) ;
F_19 (dev, crtc, encoder)
if ( V_49 -> V_385 )
V_49 -> V_385 ( V_49 ) ;
F_102 ( V_79 ) ;
F_265 ( V_79 ) ;
F_239 ( V_11 ) ;
F_118 ( V_4 , V_77 , false ) ;
F_125 ( V_4 , V_144 , V_77 ) ;
F_231 ( V_11 ) ;
if ( F_12 ( V_2 ) )
F_262 ( V_4 , V_77 ) ;
F_240 ( V_11 , true ) ;
F_260 ( V_79 , true ) ;
F_167 ( V_2 ) ;
F_19 (dev, crtc, encoder)
V_49 -> V_195 ( V_49 ) ;
}
static void F_269 ( struct V_79 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_11 -> V_80 . V_401 . V_402 )
return;
F_94 ( V_4 , V_11 -> V_77 ) ;
F_52 ( L_77 ,
F_4 ( V_403 ) ) ;
F_36 ( V_403 , 0 ) ;
}
static void F_270 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_48 * V_49 ;
int V_77 = V_79 -> V_77 ;
int V_144 = V_79 -> V_144 ;
if ( ! V_79 -> V_192 )
return;
F_19 (dev, crtc, encoder)
V_49 -> V_196 ( V_49 ) ;
F_192 ( V_11 ) ;
F_251 ( V_2 , V_77 ) ;
if ( V_4 -> V_389 . V_144 == V_144 )
F_252 ( V_2 ) ;
F_260 ( V_79 , false ) ;
F_240 ( V_11 , false ) ;
F_233 ( V_11 ) ;
F_127 ( V_4 , V_144 , V_77 ) ;
F_121 ( V_4 , V_77 ) ;
F_269 ( V_79 ) ;
F_19 (dev, crtc, encoder)
if ( V_49 -> V_390 )
V_49 -> V_390 ( V_49 ) ;
F_103 ( V_4 , V_77 ) ;
V_79 -> V_192 = false ;
F_167 ( V_2 ) ;
F_238 ( V_2 ) ;
}
static void F_271 ( struct V_10 * V_11 )
{
}
static void F_272 ( struct V_10 * V_11 ,
bool V_108 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_275 * V_276 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
int V_77 = V_79 -> V_77 ;
if ( ! V_2 -> V_277 -> V_278 )
return;
V_276 = V_2 -> V_277 -> V_278 -> V_279 ;
if ( ! V_276 -> V_280 )
return;
switch ( V_77 ) {
case 0 :
V_276 -> V_280 -> V_408 = V_108 ? V_11 -> V_288 . V_289 : 0 ;
V_276 -> V_280 -> V_409 = V_108 ? V_11 -> V_288 . V_290 : 0 ;
break;
case 1 :
V_276 -> V_280 -> V_410 = V_108 ? V_11 -> V_288 . V_289 : 0 ;
V_276 -> V_280 -> V_411 = V_108 ? V_11 -> V_288 . V_290 : 0 ;
break;
default:
F_100 ( L_78 , F_62 ( V_77 ) ) ;
break;
}
}
void F_273 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_48 * V_48 ;
bool V_195 = false ;
F_19 (dev, crtc, intel_encoder)
V_195 |= V_48 -> V_412 ;
if ( V_195 )
V_4 -> V_269 . V_413 ( V_11 ) ;
else
V_4 -> V_269 . V_414 ( V_11 ) ;
F_272 ( V_11 , V_195 ) ;
}
static void F_274 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_415 * V_416 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
F_2 ( ! V_11 -> V_108 ) ;
V_4 -> V_269 . V_414 ( V_11 ) ;
V_79 -> V_417 = false ;
F_272 ( V_11 , false ) ;
V_4 -> V_269 . V_418 ( V_11 ) ;
F_275 ( V_2 -> V_5 , F_27 ( V_11 ) -> V_144 ) ;
F_94 ( V_2 -> V_5 , F_27 ( V_11 ) -> V_77 ) ;
if ( V_11 -> V_237 ) {
F_157 ( & V_2 -> V_286 ) ;
F_138 ( F_142 ( V_11 -> V_237 ) -> V_215 ) ;
F_158 ( & V_2 -> V_286 ) ;
V_11 -> V_237 = NULL ;
}
F_154 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_416 -> V_49 || ! V_416 -> V_49 -> V_11 )
continue;
if ( V_416 -> V_49 -> V_11 != V_11 )
continue;
V_416 -> V_419 = V_420 ;
F_276 ( V_416 -> V_49 ) -> V_412 = false ;
}
}
void F_277 ( struct V_421 * V_49 )
{
struct V_48 * V_48 = F_276 ( V_49 ) ;
F_278 ( V_49 ) ;
F_279 ( V_48 ) ;
}
static void F_280 ( struct V_48 * V_49 , int V_288 )
{
if ( V_288 == V_422 ) {
V_49 -> V_412 = true ;
F_273 ( V_49 -> V_114 . V_11 ) ;
} else {
V_49 -> V_412 = false ;
F_273 ( V_49 -> V_114 . V_11 ) ;
}
}
static void F_281 ( struct V_423 * V_416 )
{
if ( V_416 -> V_120 ( V_416 ) ) {
struct V_48 * V_49 = V_416 -> V_49 ;
struct V_10 * V_11 ;
bool V_424 ;
enum V_77 V_77 ;
F_32 ( L_79 ,
V_416 -> V_114 . V_114 . V_194 ,
F_282 ( & V_416 -> V_114 ) ) ;
F_39 ( V_416 -> V_114 . V_419 == V_420 ,
L_80 ) ;
F_39 ( V_416 -> V_114 . V_49 != & V_49 -> V_114 ,
L_81 ) ;
F_39 ( ! V_49 -> V_412 ,
L_82 ) ;
V_424 = V_49 -> V_120 ( V_49 , & V_77 ) ;
F_39 ( ! V_424 , L_83 ) ;
if ( F_2 ( ! V_49 -> V_114 . V_11 ) )
return;
V_11 = V_49 -> V_114 . V_11 ;
F_39 ( ! V_11 -> V_108 , L_84 ) ;
F_39 ( ! F_27 ( V_11 ) -> V_192 , L_85 ) ;
F_39 ( V_77 != F_27 ( V_11 ) -> V_77 ,
L_86 ) ;
}
}
void F_283 ( struct V_415 * V_416 , int V_288 )
{
if ( V_288 != V_422 )
V_288 = V_420 ;
if ( V_288 == V_416 -> V_419 )
return;
V_416 -> V_419 = V_288 ;
if ( V_416 -> V_49 )
F_280 ( F_276 ( V_416 -> V_49 ) , V_288 ) ;
F_284 ( V_416 -> V_2 ) ;
}
bool F_285 ( struct V_423 * V_416 )
{
enum V_77 V_77 = 0 ;
struct V_48 * V_49 = V_416 -> V_49 ;
return V_49 -> V_120 ( V_49 , & V_77 ) ;
}
static bool F_286 ( struct V_1 * V_2 , enum V_77 V_77 ,
struct V_399 * V_400 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_303 =
F_27 ( V_4 -> V_78 [ V_140 ] ) ;
F_32 ( L_87 ,
F_62 ( V_77 ) , V_400 -> V_312 ) ;
if ( V_400 -> V_312 > 4 ) {
F_32 ( L_88 ,
F_62 ( V_77 ) , V_400 -> V_312 ) ;
return false ;
}
if ( F_149 ( V_2 ) ) {
if ( V_400 -> V_312 > 2 ) {
F_32 ( L_89 ,
V_400 -> V_312 ) ;
return false ;
} else {
return true ;
}
}
if ( F_35 ( V_2 ) -> V_285 == 2 )
return true ;
switch ( V_77 ) {
case V_131 :
return true ;
case V_140 :
if ( V_4 -> V_78 [ V_305 ] -> V_108 &&
V_400 -> V_312 > 2 ) {
F_32 ( L_90 ,
F_62 ( V_77 ) , V_400 -> V_312 ) ;
return false ;
}
return true ;
case V_305 :
if ( ! F_171 ( V_303 ) ||
V_303 -> V_80 . V_312 <= 2 ) {
if ( V_400 -> V_312 > 2 ) {
F_32 ( L_90 ,
F_62 ( V_77 ) , V_400 -> V_312 ) ;
return false ;
}
} else {
F_32 ( L_91 ) ;
return false ;
}
return true ;
default:
F_133 () ;
}
}
static int F_287 ( struct V_79 * V_79 ,
struct V_399 * V_400 )
{
struct V_1 * V_2 = V_79 -> V_114 . V_2 ;
struct V_425 * V_426 = & V_400 -> V_426 ;
int V_427 , V_428 , V_429 ;
bool V_430 , V_431 = false ;
V_317:
V_428 = F_5 ( V_2 ) * F_288 ( 100 ) / F_289 ( 1 ) / 10 ;
V_429 = V_426 -> clock ;
V_429 /= V_400 -> V_432 ;
V_427 = F_290 ( V_429 , V_428 ,
V_400 -> V_433 ) ;
V_400 -> V_312 = V_427 ;
F_291 ( V_400 -> V_433 , V_427 , V_429 ,
V_428 , & V_400 -> V_434 ) ;
V_430 = F_286 ( V_79 -> V_114 . V_2 ,
V_79 -> V_77 , V_400 ) ;
if ( ! V_430 && V_400 -> V_433 > 6 * 3 ) {
V_400 -> V_433 -= 2 * 3 ;
F_32 ( L_92 ,
V_400 -> V_433 ) ;
V_431 = true ;
V_400 -> V_435 = true ;
goto V_317;
}
if ( V_431 )
return V_436 ;
return V_430 ? 0 : - V_224 ;
}
static void F_292 ( struct V_79 * V_11 ,
struct V_399 * V_400 )
{
V_400 -> V_386 = V_437 &&
F_241 ( V_11 ) &&
V_400 -> V_433 <= 24 ;
}
static int F_293 ( struct V_79 * V_11 ,
struct V_399 * V_400 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_425 * V_426 = & V_400 -> V_426 ;
if ( F_3 ( V_2 ) ) {
if ( V_400 -> V_438 . clock * 3
> V_439 * 4 )
return - V_224 ;
}
if ( ( F_35 ( V_2 ) -> V_85 > 4 || F_12 ( V_2 ) ) &&
V_426 -> V_440 == V_426 -> V_289 )
return - V_224 ;
if ( ( F_12 ( V_2 ) || F_14 ( V_2 ) ) && V_400 -> V_433 > 10 * 3 ) {
V_400 -> V_433 = 10 * 3 ;
} else if ( F_35 ( V_2 ) -> V_85 <= 4 && V_400 -> V_433 > 8 * 3 ) {
V_400 -> V_433 = 8 * 3 ;
}
if ( F_242 ( V_2 ) )
F_292 ( V_11 , V_400 ) ;
if ( F_45 ( V_2 ) || F_80 ( V_2 ) )
V_400 -> V_115 = V_11 -> V_80 . V_115 ;
if ( V_400 -> V_302 )
return F_287 ( V_11 , V_400 ) ;
return 0 ;
}
static int F_294 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_295 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_296 ( struct V_1 * V_2 )
{
return 333000 ;
}
static int F_297 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_298 ( struct V_1 * V_2 )
{
T_5 V_441 = 0 ;
F_299 ( V_2 -> V_442 , V_443 , & V_441 ) ;
switch ( V_441 & V_444 ) {
case V_445 :
return 267000 ;
case V_446 :
return 333000 ;
case V_447 :
return 444000 ;
case V_448 :
return 200000 ;
default:
F_100 ( L_93 , V_441 ) ;
case V_449 :
return 133000 ;
case V_450 :
return 167000 ;
}
}
static int F_300 ( struct V_1 * V_2 )
{
T_5 V_441 = 0 ;
F_299 ( V_2 -> V_442 , V_443 , & V_441 ) ;
if ( V_441 & V_451 )
return 133000 ;
else {
switch ( V_441 & V_444 ) {
case V_452 :
return 333000 ;
default:
case V_453 :
return 190000 ;
}
}
}
static int F_301 ( struct V_1 * V_2 )
{
return 266000 ;
}
static int F_302 ( struct V_1 * V_2 )
{
T_5 V_454 = 0 ;
switch ( V_454 & V_455 ) {
case V_456 :
case V_457 :
return 200000 ;
case V_458 :
return 250000 ;
case V_459 :
return 133000 ;
}
return 0 ;
}
static int F_303 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_304 ( T_4 * V_460 , T_4 * V_461 )
{
while ( * V_460 > V_462 ||
* V_461 > V_462 ) {
* V_460 >>= 1 ;
* V_461 >>= 1 ;
}
}
static void F_305 ( unsigned int V_38 , unsigned int V_44 ,
T_4 * V_463 , T_4 * V_464 )
{
* V_464 = F_306 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_463 = F_307 ( ( V_465 ) V_38 * * V_464 , V_44 ) ;
F_304 ( V_463 , V_464 ) ;
}
void
F_291 ( int V_266 , int V_466 ,
int V_467 , int V_468 ,
struct V_469 * V_470 )
{
V_470 -> V_471 = 64 ;
F_305 ( V_266 * V_467 ,
V_468 * V_466 * 8 ,
& V_470 -> V_472 , & V_470 -> V_473 ) ;
F_305 ( V_467 , V_468 ,
& V_470 -> V_474 , & V_470 -> V_475 ) ;
}
static inline bool F_308 ( struct V_3 * V_4 )
{
if ( V_476 >= 0 )
return V_476 != 0 ;
return V_4 -> V_477 . V_478
&& ! ( V_4 -> V_141 & V_479 ) ;
}
static int F_309 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_12 = 27000 ;
return 100000 ;
if ( F_8 ( V_11 , V_23 ) ) {
V_12 = 96000 ;
} else if ( F_8 ( V_11 , V_14 ) ) {
if ( F_308 ( V_4 ) )
V_12 = 100000 ;
else
V_12 = 96000 ;
} else if ( F_8 ( V_11 , V_292 ) ) {
V_12 = 100000 ;
}
return V_12 ;
}
static int F_310 ( struct V_10 * V_11 , int V_480 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_12 ;
if ( F_14 ( V_2 ) ) {
V_12 = F_309 ( V_11 ) ;
} else if ( F_8 ( V_11 , V_14 ) &&
F_308 ( V_4 ) && V_480 < 2 ) {
V_12 = V_4 -> V_477 . V_481 * 1000 ;
F_32 ( L_94 ,
V_12 / 1000 ) ;
} else if ( ! F_15 ( V_2 ) ) {
V_12 = 96000 ;
} else {
V_12 = 48000 ;
}
return V_12 ;
}
static T_4 F_311 ( struct V_46 * V_46 )
{
return ( 1 << V_46 -> V_44 ) << 16 | V_46 -> V_39 ;
}
static T_4 F_312 ( struct V_46 * V_46 )
{
return V_46 -> V_44 << 16 | V_46 -> V_47 << 8 | V_46 -> V_39 ;
}
static void F_313 ( struct V_79 * V_11 ,
T_3 * V_482 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_77 = V_11 -> V_77 ;
T_1 V_483 , V_484 = 0 ;
if ( F_13 ( V_2 ) ) {
V_483 = F_311 ( & V_11 -> V_80 . V_46 ) ;
if ( V_482 )
V_484 = F_311 ( V_482 ) ;
} else {
V_483 = F_312 ( & V_11 -> V_80 . V_46 ) ;
if ( V_482 )
V_484 = F_312 ( V_482 ) ;
}
F_36 ( F_314 ( V_77 ) , V_483 ) ;
V_11 -> V_80 . V_185 . V_485 = V_483 ;
V_11 -> V_486 = false ;
if ( F_8 ( & V_11 -> V_114 , V_14 ) &&
V_482 && V_487 ) {
F_36 ( F_315 ( V_77 ) , V_484 ) ;
V_11 -> V_80 . V_185 . V_488 = V_484 ;
V_11 -> V_486 = true ;
} else {
F_36 ( F_315 ( V_77 ) , V_483 ) ;
V_11 -> V_80 . V_185 . V_488 = V_483 ;
}
}
static void F_316 ( struct V_3 * V_4 )
{
T_1 V_489 ;
V_489 = F_317 ( V_4 , F_318 ( 1 ) ) ;
V_489 &= 0xffffff00 ;
V_489 |= 0x00000030 ;
F_319 ( V_4 , F_318 ( 1 ) , V_489 ) ;
V_489 = F_317 ( V_4 , V_490 ) ;
V_489 &= 0x8cffffff ;
V_489 = 0x8c000000 ;
F_319 ( V_4 , V_490 , V_489 ) ;
V_489 = F_317 ( V_4 , F_318 ( 1 ) ) ;
V_489 &= 0xffffff00 ;
F_319 ( V_4 , F_318 ( 1 ) , V_489 ) ;
V_489 = F_317 ( V_4 , V_490 ) ;
V_489 &= 0x00ffffff ;
V_489 |= 0xb0000000 ;
F_319 ( V_4 , V_490 , V_489 ) ;
}
static void F_320 ( struct V_79 * V_11 ,
struct V_469 * V_470 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_77 = V_11 -> V_77 ;
F_36 ( F_321 ( V_77 ) , F_322 ( V_470 -> V_471 ) | V_470 -> V_472 ) ;
F_36 ( F_323 ( V_77 ) , V_470 -> V_473 ) ;
F_36 ( F_324 ( V_77 ) , V_470 -> V_474 ) ;
F_36 ( F_325 ( V_77 ) , V_470 -> V_475 ) ;
}
static void F_326 ( struct V_79 * V_11 ,
struct V_469 * V_470 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_77 = V_11 -> V_77 ;
enum V_76 V_76 = V_11 -> V_80 . V_81 ;
if ( F_35 ( V_2 ) -> V_85 >= 5 ) {
F_36 ( F_221 ( V_76 ) , F_322 ( V_470 -> V_471 ) | V_470 -> V_472 ) ;
F_36 ( F_327 ( V_76 ) , V_470 -> V_473 ) ;
F_36 ( F_328 ( V_76 ) , V_470 -> V_474 ) ;
F_36 ( F_329 ( V_76 ) , V_470 -> V_475 ) ;
} else {
F_36 ( F_330 ( V_77 ) , F_322 ( V_470 -> V_471 ) | V_470 -> V_472 ) ;
F_36 ( F_331 ( V_77 ) , V_470 -> V_473 ) ;
F_36 ( F_332 ( V_77 ) , V_470 -> V_474 ) ;
F_36 ( F_333 ( V_77 ) , V_470 -> V_475 ) ;
}
}
static void F_334 ( struct V_79 * V_11 )
{
if ( V_11 -> V_80 . V_302 )
F_320 ( V_11 , & V_11 -> V_80 . V_491 ) ;
else
F_326 ( V_11 , & V_11 -> V_80 . V_491 ) ;
}
static void F_335 ( struct V_79 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_77 = V_11 -> V_77 ;
T_1 V_46 , V_492 ;
T_1 V_63 , V_64 , V_65 , V_66 , V_67 ;
T_1 V_493 , V_489 , V_187 ;
F_157 ( & V_4 -> V_343 ) ;
V_63 = V_11 -> V_80 . V_46 . V_44 ;
V_64 = V_11 -> V_80 . V_46 . V_47 ;
V_65 = V_11 -> V_80 . V_46 . V_39 ;
V_66 = V_11 -> V_80 . V_46 . V_41 ;
V_67 = V_11 -> V_80 . V_46 . V_42 ;
if ( V_77 )
F_316 ( V_4 ) ;
F_319 ( V_4 , V_494 , 0x0100000f ) ;
V_489 = F_317 ( V_4 , F_336 ( V_77 ) ) ;
V_489 &= 0x00ffffff ;
F_319 ( V_4 , F_336 ( V_77 ) , V_489 ) ;
F_319 ( V_4 , V_495 , 0x610 ) ;
V_492 = ( ( V_64 << V_496 ) | ( V_65 & V_497 ) ) ;
V_492 |= ( ( V_66 << V_498 ) | ( V_67 << V_499 ) ) ;
V_492 |= ( ( V_63 << V_500 ) ) ;
V_492 |= ( 1 << V_501 ) ;
V_492 |= ( V_502 << V_503 ) ;
F_319 ( V_4 , F_337 ( V_77 ) , V_492 ) ;
V_492 |= V_504 ;
F_319 ( V_4 , F_337 ( V_77 ) , V_492 ) ;
if ( V_11 -> V_80 . V_505 == 162000 ||
F_8 ( & V_11 -> V_114 , V_23 ) ||
F_8 ( & V_11 -> V_114 , V_22 ) )
F_319 ( V_4 , F_338 ( V_77 ) ,
0x009f0003 ) ;
else
F_319 ( V_4 , F_338 ( V_77 ) ,
0x00d0000f ) ;
if ( F_8 ( & V_11 -> V_114 , V_292 ) ||
F_8 ( & V_11 -> V_114 , V_365 ) ) {
if ( ! V_77 )
F_319 ( V_4 , F_339 ( V_77 ) ,
0x0df40000 ) ;
else
F_319 ( V_4 , F_339 ( V_77 ) ,
0x0df70000 ) ;
} else {
if ( ! V_77 )
F_319 ( V_4 , F_339 ( V_77 ) ,
0x0df70000 ) ;
else
F_319 ( V_4 , F_339 ( V_77 ) ,
0x0df40000 ) ;
}
V_493 = F_317 ( V_4 , F_340 ( V_77 ) ) ;
V_493 = ( V_493 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_8 ( & V_11 -> V_114 , V_365 ) ||
F_8 ( & V_11 -> V_114 , V_292 ) )
V_493 |= 0x01000000 ;
F_319 ( V_4 , F_340 ( V_77 ) , V_493 ) ;
F_319 ( V_4 , F_341 ( V_77 ) , 0x87871000 ) ;
V_46 = V_506 | V_507 |
V_508 | V_509 ;
if ( V_77 )
V_46 |= V_510 ;
V_46 |= V_112 ;
V_11 -> V_80 . V_185 . V_46 = V_46 ;
V_187 = ( V_11 -> V_80 . V_432 - 1 )
<< V_511 ;
V_11 -> V_80 . V_185 . V_187 = V_187 ;
if ( V_11 -> V_80 . V_512 )
F_334 ( V_11 ) ;
F_158 ( & V_4 -> V_343 ) ;
}
static void F_342 ( struct V_79 * V_11 ,
T_3 * V_482 ,
int V_480 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_46 ;
bool V_513 ;
struct V_46 * clock = & V_11 -> V_80 . V_46 ;
F_313 ( V_11 , V_482 ) ;
V_513 = F_8 ( & V_11 -> V_114 , V_25 ) ||
F_8 ( & V_11 -> V_114 , V_22 ) ;
V_46 = V_508 ;
if ( F_8 ( & V_11 -> V_114 , V_14 ) )
V_46 |= V_514 ;
else
V_46 |= V_515 ;
if ( F_343 ( V_2 ) || F_344 ( V_2 ) || F_345 ( V_2 ) ) {
V_46 |= ( V_11 -> V_80 . V_432 - 1 )
<< V_516 ;
}
if ( V_513 )
V_46 |= V_517 ;
if ( F_8 ( & V_11 -> V_114 , V_365 ) )
V_46 |= V_517 ;
if ( F_13 ( V_2 ) )
V_46 |= ( 1 << ( clock -> V_41 - 1 ) ) << V_518 ;
else {
V_46 |= ( 1 << ( clock -> V_41 - 1 ) ) << V_519 ;
if ( F_12 ( V_2 ) && V_482 )
V_46 |= ( 1 << ( V_482 -> V_41 - 1 ) ) << V_520 ;
}
switch ( clock -> V_42 ) {
case 5 :
V_46 |= V_521 ;
break;
case 7 :
V_46 |= V_522 ;
break;
case 10 :
V_46 |= V_523 ;
break;
case 14 :
V_46 |= V_524 ;
break;
}
if ( F_35 ( V_2 ) -> V_85 >= 4 )
V_46 |= ( 6 << V_525 ) ;
if ( V_11 -> V_80 . V_526 )
V_46 |= V_527 ;
else if ( F_8 ( & V_11 -> V_114 , V_14 ) &&
F_308 ( V_4 ) && V_480 < 2 )
V_46 |= V_528 ;
else
V_46 |= V_529 ;
V_46 |= V_112 ;
V_11 -> V_80 . V_185 . V_46 = V_46 ;
if ( F_35 ( V_2 ) -> V_85 >= 4 ) {
T_1 V_187 = ( V_11 -> V_80 . V_432 - 1 )
<< V_511 ;
V_11 -> V_80 . V_185 . V_187 = V_187 ;
}
if ( V_11 -> V_80 . V_512 )
F_334 ( V_11 ) ;
}
static void F_346 ( struct V_79 * V_11 ,
T_3 * V_482 ,
int V_480 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_46 ;
struct V_46 * clock = & V_11 -> V_80 . V_46 ;
F_313 ( V_11 , V_482 ) ;
V_46 = V_508 ;
if ( F_8 ( & V_11 -> V_114 , V_14 ) ) {
V_46 |= ( 1 << ( clock -> V_41 - 1 ) ) << V_519 ;
} else {
if ( clock -> V_41 == 2 )
V_46 |= V_530 ;
else
V_46 |= ( clock -> V_41 - 2 ) << V_519 ;
if ( clock -> V_42 == 4 )
V_46 |= V_531 ;
}
if ( F_8 ( & V_11 -> V_114 , V_35 ) )
V_46 |= V_532 ;
if ( F_8 ( & V_11 -> V_114 , V_14 ) &&
F_308 ( V_4 ) && V_480 < 2 )
V_46 |= V_528 ;
else
V_46 |= V_529 ;
V_46 |= V_112 ;
V_11 -> V_80 . V_185 . V_46 = V_46 ;
}
static void F_347 ( struct V_79 * V_79 )
{
struct V_1 * V_2 = V_79 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_77 V_77 = V_79 -> V_77 ;
enum V_76 V_81 = V_79 -> V_80 . V_81 ;
struct V_425 * V_426 =
& V_79 -> V_80 . V_426 ;
struct V_425 * V_288 = & V_79 -> V_80 . V_438 ;
T_4 V_533 , V_534 , V_535 ;
V_534 = V_426 -> V_534 ;
V_535 = V_426 -> V_535 ;
if ( ! F_15 ( V_2 ) && V_426 -> V_332 & V_536 ) {
V_534 -= 1 ;
V_535 -= 1 ;
V_533 = V_426 -> V_537
- V_426 -> V_538 / 2 ;
} else {
V_533 = 0 ;
}
if ( F_35 ( V_2 ) -> V_85 > 3 )
F_36 ( F_216 ( V_81 ) , V_533 ) ;
F_36 ( F_204 ( V_81 ) ,
( V_426 -> V_539 - 1 ) |
( ( V_426 -> V_538 - 1 ) << 16 ) ) ;
F_36 ( F_206 ( V_81 ) ,
( V_426 -> V_540 - 1 ) |
( ( V_426 -> V_541 - 1 ) << 16 ) ) ;
F_36 ( F_208 ( V_81 ) ,
( V_426 -> V_537 - 1 ) |
( ( V_426 -> V_542 - 1 ) << 16 ) ) ;
F_36 ( F_210 ( V_81 ) ,
( V_426 -> V_543 - 1 ) |
( ( V_534 - 1 ) << 16 ) ) ;
F_36 ( F_212 ( V_81 ) ,
( V_426 -> V_544 - 1 ) |
( ( V_535 - 1 ) << 16 ) ) ;
F_36 ( F_214 ( V_81 ) ,
( V_426 -> V_545 - 1 ) |
( ( V_426 -> V_546 - 1 ) << 16 ) ) ;
if ( F_149 ( V_2 ) && V_81 == V_547 &&
( V_77 == V_140 || V_77 == V_305 ) )
F_36 ( F_210 ( V_77 ) , F_4 ( F_210 ( V_81 ) ) ) ;
F_36 ( F_163 ( V_77 ) ,
( ( V_288 -> V_289 - 1 ) << 16 ) | ( V_288 -> V_290 - 1 ) ) ;
}
static void F_348 ( struct V_79 * V_11 ,
struct V_399 * V_400 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_76 V_81 = V_400 -> V_81 ;
T_4 V_548 ;
V_548 = F_4 ( F_204 ( V_81 ) ) ;
V_400 -> V_426 . V_539 = ( V_548 & 0xffff ) + 1 ;
V_400 -> V_426 . V_538 = ( ( V_548 >> 16 ) & 0xffff ) + 1 ;
V_548 = F_4 ( F_206 ( V_81 ) ) ;
V_400 -> V_426 . V_540 = ( V_548 & 0xffff ) + 1 ;
V_400 -> V_426 . V_541 = ( ( V_548 >> 16 ) & 0xffff ) + 1 ;
V_548 = F_4 ( F_208 ( V_81 ) ) ;
V_400 -> V_426 . V_537 = ( V_548 & 0xffff ) + 1 ;
V_400 -> V_426 . V_542 = ( ( V_548 >> 16 ) & 0xffff ) + 1 ;
V_548 = F_4 ( F_210 ( V_81 ) ) ;
V_400 -> V_426 . V_543 = ( V_548 & 0xffff ) + 1 ;
V_400 -> V_426 . V_534 = ( ( V_548 >> 16 ) & 0xffff ) + 1 ;
V_548 = F_4 ( F_212 ( V_81 ) ) ;
V_400 -> V_426 . V_544 = ( V_548 & 0xffff ) + 1 ;
V_400 -> V_426 . V_535 = ( ( V_548 >> 16 ) & 0xffff ) + 1 ;
V_548 = F_4 ( F_214 ( V_81 ) ) ;
V_400 -> V_426 . V_545 = ( V_548 & 0xffff ) + 1 ;
V_400 -> V_426 . V_546 = ( ( V_548 >> 16 ) & 0xffff ) + 1 ;
if ( F_4 ( F_38 ( V_81 ) ) & V_201 ) {
V_400 -> V_426 . V_332 |= V_536 ;
V_400 -> V_426 . V_534 += 1 ;
V_400 -> V_426 . V_535 += 1 ;
}
V_548 = F_4 ( F_163 ( V_11 -> V_77 ) ) ;
V_400 -> V_438 . V_290 = ( V_548 & 0xffff ) + 1 ;
V_400 -> V_438 . V_289 = ( ( V_548 >> 16 ) & 0xffff ) + 1 ;
}
static void F_349 ( struct V_79 * V_79 ,
struct V_399 * V_400 )
{
struct V_10 * V_11 = & V_79 -> V_114 ;
V_11 -> V_288 . V_289 = V_400 -> V_426 . V_539 ;
V_11 -> V_288 . V_549 = V_400 -> V_426 . V_538 ;
V_11 -> V_288 . V_440 = V_400 -> V_426 . V_537 ;
V_11 -> V_288 . V_550 = V_400 -> V_426 . V_542 ;
V_11 -> V_288 . V_290 = V_400 -> V_426 . V_543 ;
V_11 -> V_288 . V_551 = V_400 -> V_426 . V_534 ;
V_11 -> V_288 . V_552 = V_400 -> V_426 . V_545 ;
V_11 -> V_288 . V_553 = V_400 -> V_426 . V_546 ;
V_11 -> V_288 . V_332 = V_400 -> V_426 . V_332 ;
V_11 -> V_288 . clock = V_400 -> V_426 . clock ;
V_11 -> V_288 . V_332 |= V_400 -> V_426 . V_332 ;
}
static void F_350 ( struct V_79 * V_79 )
{
struct V_1 * V_2 = V_79 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_554 ;
V_554 = 0 ;
if ( V_4 -> V_141 & V_142 &&
F_4 ( F_38 ( V_79 -> V_77 ) ) & V_143 )
V_554 |= V_143 ;
if ( V_79 -> V_77 == 0 && F_35 ( V_2 ) -> V_85 < 4 ) {
if ( V_79 -> V_80 . V_438 . clock >
V_4 -> V_269 . V_555 ( V_2 ) * 9 / 10 )
V_554 |= V_556 ;
}
if ( F_12 ( V_2 ) || F_14 ( V_2 ) ) {
if ( V_79 -> V_80 . V_557 && V_79 -> V_80 . V_433 != 30 )
V_554 |= V_558 |
V_559 ;
switch ( V_79 -> V_80 . V_433 ) {
case 18 :
V_554 |= V_560 ;
break;
case 24 :
V_554 |= V_561 ;
break;
case 30 :
V_554 |= V_562 ;
break;
default:
F_133 () ;
}
}
if ( F_351 ( V_2 ) ) {
if ( V_79 -> V_486 ) {
F_32 ( L_95 ) ;
V_554 |= V_563 ;
} else {
F_32 ( L_96 ) ;
}
}
if ( ! F_15 ( V_2 ) &&
V_79 -> V_80 . V_426 . V_332 & V_536 )
V_554 |= V_564 ;
else
V_554 |= V_565 ;
if ( F_14 ( V_2 ) && V_79 -> V_80 . V_566 )
V_554 |= V_567 ;
F_36 ( F_38 ( V_79 -> V_77 ) , V_554 ) ;
F_98 ( F_38 ( V_79 -> V_77 ) ) ;
}
static int F_352 ( struct V_10 * V_11 ,
int V_229 , int V_230 ,
struct V_236 * V_237 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_425 * V_288 = & V_79 -> V_80 . V_438 ;
int V_77 = V_79 -> V_77 ;
int V_144 = V_79 -> V_144 ;
int V_12 , V_480 = 0 ;
T_3 clock , V_482 ;
T_1 V_241 ;
bool V_568 , V_569 = false ;
bool V_570 = false ;
struct V_48 * V_49 ;
const T_2 * V_13 ;
int V_219 ;
F_19 (dev, crtc, encoder) {
switch ( V_49 -> type ) {
case V_14 :
V_570 = true ;
break;
}
V_480 ++ ;
}
V_12 = F_310 ( V_11 , V_480 ) ;
V_13 = F_11 ( V_11 , V_12 ) ;
V_568 = V_4 -> V_269 . V_571 ( V_13 , V_11 ,
V_79 -> V_80 . V_505 ,
V_12 , NULL , & clock ) ;
if ( ! V_568 && ! V_79 -> V_80 . V_572 ) {
F_100 ( L_97 ) ;
return - V_224 ;
}
if ( V_570 && V_4 -> V_573 ) {
V_569 =
V_4 -> V_269 . V_571 ( V_13 , V_11 ,
V_4 -> V_574 ,
V_12 , & clock ,
& V_482 ) ;
}
if ( ! V_79 -> V_80 . V_572 ) {
V_79 -> V_80 . V_46 . V_44 = clock . V_44 ;
V_79 -> V_80 . V_46 . V_47 = clock . V_47 ;
V_79 -> V_80 . V_46 . V_39 = clock . V_39 ;
V_79 -> V_80 . V_46 . V_41 = clock . V_41 ;
V_79 -> V_80 . V_46 . V_42 = clock . V_42 ;
}
if ( F_15 ( V_2 ) )
F_346 ( V_79 ,
V_569 ? & V_482 : NULL ,
V_480 ) ;
else if ( F_14 ( V_2 ) )
F_335 ( V_79 ) ;
else
F_342 ( V_79 ,
V_569 ? & V_482 : NULL ,
V_480 ) ;
V_241 = V_575 ;
if ( ! F_14 ( V_2 ) ) {
if ( V_77 == 0 )
V_241 &= ~ V_148 ;
else
V_241 |= V_576 ;
}
F_347 ( V_79 ) ;
F_36 ( F_353 ( V_144 ) ,
( ( V_288 -> V_290 - 1 ) << 16 ) |
( V_288 -> V_289 - 1 ) ) ;
F_36 ( F_354 ( V_144 ) , 0 ) ;
F_350 ( V_79 ) ;
F_36 ( F_67 ( V_144 ) , V_241 ) ;
F_98 ( F_67 ( V_144 ) ) ;
V_219 = F_162 ( V_11 , V_229 , V_230 , V_237 ) ;
F_238 ( V_2 ) ;
return V_219 ;
}
static void F_355 ( struct V_79 * V_11 ,
struct V_399 * V_400 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_548 ;
V_548 = F_4 ( V_403 ) ;
if ( ! ( V_548 & V_404 ) )
return;
if ( F_35 ( V_2 ) -> V_85 < 4 ) {
if ( V_11 -> V_77 != V_140 )
return;
} else {
if ( ( V_548 & V_577 ) != ( V_11 -> V_77 << V_578 ) )
return;
}
V_400 -> V_401 . V_402 = V_548 ;
V_400 -> V_401 . V_406 = F_4 ( V_405 ) ;
if ( F_35 ( V_2 ) -> V_85 < 5 )
V_400 -> V_401 . V_579 =
F_4 ( V_136 ) & V_580 ;
}
static bool F_356 ( struct V_79 * V_11 ,
struct V_399 * V_400 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_548 ;
V_400 -> V_81 = (enum V_76 ) V_11 -> V_77 ;
V_400 -> V_115 = V_375 ;
V_548 = F_4 ( F_38 ( V_11 -> V_77 ) ) ;
if ( ! ( V_548 & V_143 ) )
return false ;
if ( F_12 ( V_2 ) || F_14 ( V_2 ) ) {
switch ( V_548 & V_199 ) {
case V_560 :
V_400 -> V_433 = 18 ;
break;
case V_561 :
V_400 -> V_433 = 24 ;
break;
case V_562 :
V_400 -> V_433 = 30 ;
break;
default:
break;
}
}
F_348 ( V_11 , V_400 ) ;
F_355 ( V_11 , V_400 ) ;
if ( F_35 ( V_2 ) -> V_85 >= 4 ) {
V_548 = F_4 ( F_101 ( V_11 -> V_77 ) ) ;
V_400 -> V_432 =
( ( V_548 & V_581 )
>> V_511 ) + 1 ;
V_400 -> V_185 . V_187 = V_548 ;
} else if ( F_343 ( V_2 ) || F_344 ( V_2 ) || F_345 ( V_2 ) ) {
V_548 = F_4 ( F_48 ( V_11 -> V_77 ) ) ;
V_400 -> V_432 =
( ( V_548 & V_582 )
>> V_516 ) + 1 ;
} else {
V_400 -> V_432 = 1 ;
}
V_400 -> V_185 . V_46 = F_4 ( F_48 ( V_11 -> V_77 ) ) ;
if ( ! F_14 ( V_2 ) ) {
V_400 -> V_185 . V_485 = F_4 ( F_314 ( V_11 -> V_77 ) ) ;
V_400 -> V_185 . V_488 = F_4 ( F_315 ( V_11 -> V_77 ) ) ;
} else {
V_400 -> V_185 . V_46 &= ~ ( V_186 |
V_190 |
V_189 ) ;
}
return true ;
}
static void F_357 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_583 * V_584 = & V_2 -> V_584 ;
struct V_48 * V_49 ;
T_1 V_110 , V_585 ;
bool V_586 = false ;
bool V_587 = false ;
bool V_588 = false ;
bool V_589 = false ;
bool V_590 = false ;
F_154 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_49 -> type ) {
case V_14 :
V_588 = true ;
V_586 = true ;
break;
case V_292 :
V_588 = true ;
if ( F_358 ( & V_49 -> V_114 ) -> V_96 == V_591 )
V_587 = true ;
break;
}
}
if ( F_45 ( V_2 ) ) {
V_589 = V_4 -> V_477 . V_592 ;
V_590 = V_589 ;
} else {
V_589 = false ;
V_590 = true ;
}
F_32 ( L_98 ,
V_588 , V_586 , V_589 ) ;
V_110 = F_4 ( V_154 ) ;
V_585 = V_110 ;
V_585 &= ~ V_156 ;
if ( V_589 )
V_585 |= V_593 ;
else
V_585 |= V_594 ;
V_585 &= ~ V_155 ;
V_585 &= ~ V_595 ;
V_585 &= ~ V_596 ;
if ( V_588 ) {
V_585 |= V_597 ;
if ( F_308 ( V_4 ) && V_590 )
V_585 |= V_596 ;
if ( V_587 ) {
if ( F_308 ( V_4 ) && V_590 )
V_585 |= V_598 ;
else
V_585 |= V_599 ;
} else
V_585 |= V_600 ;
} else {
V_585 |= V_601 ;
V_585 |= V_600 ;
}
if ( V_585 == V_110 )
return;
V_110 &= ~ V_156 ;
if ( V_589 )
V_110 |= V_593 ;
else
V_110 |= V_594 ;
if ( V_588 ) {
V_110 &= ~ V_155 ;
V_110 |= V_597 ;
if ( F_308 ( V_4 ) && V_590 ) {
F_32 ( L_99 ) ;
V_110 |= V_596 ;
} else
V_110 &= ~ V_596 ;
F_36 ( V_154 , V_110 ) ;
F_98 ( V_154 ) ;
F_99 ( 200 ) ;
V_110 &= ~ V_595 ;
if ( V_587 ) {
if ( F_308 ( V_4 ) && V_590 ) {
F_32 ( L_100 ) ;
V_110 |= V_598 ;
}
else
V_110 |= V_599 ;
} else
V_110 |= V_600 ;
F_36 ( V_154 , V_110 ) ;
F_98 ( V_154 ) ;
F_99 ( 200 ) ;
} else {
F_32 ( L_101 ) ;
V_110 &= ~ V_595 ;
V_110 |= V_600 ;
F_36 ( V_154 , V_110 ) ;
F_98 ( V_154 ) ;
F_99 ( 200 ) ;
V_110 &= ~ V_155 ;
V_110 |= V_601 ;
V_110 &= ~ V_596 ;
F_36 ( V_154 , V_110 ) ;
F_98 ( V_154 ) ;
F_99 ( 200 ) ;
}
F_95 ( V_110 != V_585 ) ;
}
static void F_359 ( struct V_3 * V_4 )
{
T_4 V_548 ;
V_548 = F_4 ( V_602 ) ;
V_548 |= V_603 ;
F_36 ( V_602 , V_548 ) ;
if ( F_360 ( F_4 ( V_602 ) &
V_604 , 100 ) )
F_100 ( L_102 ) ;
V_548 = F_4 ( V_602 ) ;
V_548 &= ~ V_603 ;
F_36 ( V_602 , V_548 ) ;
if ( F_360 ( ( F_4 ( V_602 ) &
V_604 ) == 0 , 100 ) )
F_100 ( L_103 ) ;
}
static void F_361 ( struct V_3 * V_4 )
{
T_4 V_548 ;
V_548 = F_197 ( V_4 , 0x8008 , V_605 ) ;
V_548 &= ~ ( 0xFF << 24 ) ;
V_548 |= ( 0x12 << 24 ) ;
F_196 ( V_4 , 0x8008 , V_548 , V_605 ) ;
V_548 = F_197 ( V_4 , 0x2008 , V_605 ) ;
V_548 |= ( 1 << 11 ) ;
F_196 ( V_4 , 0x2008 , V_548 , V_605 ) ;
V_548 = F_197 ( V_4 , 0x2108 , V_605 ) ;
V_548 |= ( 1 << 11 ) ;
F_196 ( V_4 , 0x2108 , V_548 , V_605 ) ;
V_548 = F_197 ( V_4 , 0x206C , V_605 ) ;
V_548 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_196 ( V_4 , 0x206C , V_548 , V_605 ) ;
V_548 = F_197 ( V_4 , 0x216C , V_605 ) ;
V_548 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_196 ( V_4 , 0x216C , V_548 , V_605 ) ;
V_548 = F_197 ( V_4 , 0x2080 , V_605 ) ;
V_548 &= ~ ( 7 << 13 ) ;
V_548 |= ( 5 << 13 ) ;
F_196 ( V_4 , 0x2080 , V_548 , V_605 ) ;
V_548 = F_197 ( V_4 , 0x2180 , V_605 ) ;
V_548 &= ~ ( 7 << 13 ) ;
V_548 |= ( 5 << 13 ) ;
F_196 ( V_4 , 0x2180 , V_548 , V_605 ) ;
V_548 = F_197 ( V_4 , 0x208C , V_605 ) ;
V_548 &= ~ 0xFF ;
V_548 |= 0x1C ;
F_196 ( V_4 , 0x208C , V_548 , V_605 ) ;
V_548 = F_197 ( V_4 , 0x218C , V_605 ) ;
V_548 &= ~ 0xFF ;
V_548 |= 0x1C ;
F_196 ( V_4 , 0x218C , V_548 , V_605 ) ;
V_548 = F_197 ( V_4 , 0x2098 , V_605 ) ;
V_548 &= ~ ( 0xFF << 16 ) ;
V_548 |= ( 0x1C << 16 ) ;
F_196 ( V_4 , 0x2098 , V_548 , V_605 ) ;
V_548 = F_197 ( V_4 , 0x2198 , V_605 ) ;
V_548 &= ~ ( 0xFF << 16 ) ;
V_548 |= ( 0x1C << 16 ) ;
F_196 ( V_4 , 0x2198 , V_548 , V_605 ) ;
V_548 = F_197 ( V_4 , 0x20C4 , V_605 ) ;
V_548 |= ( 1 << 27 ) ;
F_196 ( V_4 , 0x20C4 , V_548 , V_605 ) ;
V_548 = F_197 ( V_4 , 0x21C4 , V_605 ) ;
V_548 |= ( 1 << 27 ) ;
F_196 ( V_4 , 0x21C4 , V_548 , V_605 ) ;
V_548 = F_197 ( V_4 , 0x20EC , V_605 ) ;
V_548 &= ~ ( 0xF << 28 ) ;
V_548 |= ( 4 << 28 ) ;
F_196 ( V_4 , 0x20EC , V_548 , V_605 ) ;
V_548 = F_197 ( V_4 , 0x21EC , V_605 ) ;
V_548 &= ~ ( 0xF << 28 ) ;
V_548 |= ( 4 << 28 ) ;
F_196 ( V_4 , 0x21EC , V_548 , V_605 ) ;
}
static void F_362 ( struct V_1 * V_2 , bool V_606 ,
bool V_607 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_87 , V_548 ;
if ( F_39 ( V_607 && ! V_606 , L_104 ) )
V_606 = true ;
if ( F_39 ( V_4 -> V_608 == V_609 &&
V_607 , L_105 ) )
V_607 = false ;
F_157 ( & V_4 -> V_343 ) ;
V_548 = F_197 ( V_4 , V_610 , V_347 ) ;
V_548 &= ~ V_348 ;
V_548 |= V_611 ;
F_196 ( V_4 , V_610 , V_548 , V_347 ) ;
F_99 ( 24 ) ;
if ( V_606 ) {
V_548 = F_197 ( V_4 , V_610 , V_347 ) ;
V_548 &= ~ V_611 ;
F_196 ( V_4 , V_610 , V_548 , V_347 ) ;
if ( V_607 ) {
F_359 ( V_4 ) ;
F_361 ( V_4 ) ;
}
}
V_87 = ( V_4 -> V_608 == V_609 ) ?
V_612 : V_613 ;
V_548 = F_197 ( V_4 , V_87 , V_347 ) ;
V_548 |= V_614 ;
F_196 ( V_4 , V_87 , V_548 , V_347 ) ;
F_158 ( & V_4 -> V_343 ) ;
}
static void F_363 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_87 , V_548 ;
F_157 ( & V_4 -> V_343 ) ;
V_87 = ( V_4 -> V_608 == V_609 ) ?
V_612 : V_613 ;
V_548 = F_197 ( V_4 , V_87 , V_347 ) ;
V_548 &= ~ V_614 ;
F_196 ( V_4 , V_87 , V_548 , V_347 ) ;
V_548 = F_197 ( V_4 , V_610 , V_347 ) ;
if ( ! ( V_548 & V_348 ) ) {
if ( ! ( V_548 & V_611 ) ) {
V_548 |= V_611 ;
F_196 ( V_4 , V_610 , V_548 , V_347 ) ;
F_99 ( 32 ) ;
}
V_548 |= V_348 ;
F_196 ( V_4 , V_610 , V_548 , V_347 ) ;
}
F_158 ( & V_4 -> V_343 ) ;
}
static void F_364 ( struct V_1 * V_2 )
{
struct V_583 * V_584 = & V_2 -> V_584 ;
struct V_48 * V_49 ;
bool V_615 = false ;
F_154 (encoder, &mode_config->encoder_list, base.head) {
switch ( V_49 -> type ) {
case V_23 :
V_615 = true ;
break;
}
}
if ( V_615 )
F_362 ( V_2 , true , true ) ;
else
F_363 ( V_2 ) ;
}
void F_365 ( struct V_1 * V_2 )
{
if ( F_45 ( V_2 ) || F_80 ( V_2 ) )
F_357 ( V_2 ) ;
else if ( F_51 ( V_2 ) )
F_364 ( V_2 ) ;
}
static int F_366 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_48 * V_49 ;
int V_480 = 0 ;
bool V_570 = false ;
F_19 (dev, crtc, encoder) {
switch ( V_49 -> type ) {
case V_14 :
V_570 = true ;
break;
}
V_480 ++ ;
}
if ( V_570 && F_308 ( V_4 ) && V_480 < 2 ) {
F_32 ( L_94 ,
V_4 -> V_477 . V_481 ) ;
return V_4 -> V_477 . V_481 * 1000 ;
}
return 120000 ;
}
static void F_367 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
int V_77 = V_79 -> V_77 ;
T_4 V_110 ;
V_110 = 0 ;
switch ( V_79 -> V_80 . V_433 ) {
case 18 :
V_110 |= V_560 ;
break;
case 24 :
V_110 |= V_561 ;
break;
case 30 :
V_110 |= V_562 ;
break;
case 36 :
V_110 |= V_616 ;
break;
default:
F_133 () ;
}
if ( V_79 -> V_80 . V_557 )
V_110 |= ( V_558 | V_559 ) ;
if ( V_79 -> V_80 . V_426 . V_332 & V_536 )
V_110 |= V_202 ;
else
V_110 |= V_565 ;
if ( V_79 -> V_80 . V_566 )
V_110 |= V_567 ;
F_36 ( F_38 ( V_77 ) , V_110 ) ;
F_98 ( F_38 ( V_77 ) ) ;
}
static void F_368 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
int V_77 = V_79 -> V_77 ;
T_6 V_617 = 0x7800 ;
if ( V_79 -> V_80 . V_566 )
V_617 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_36 ( F_369 ( V_77 ) , V_617 << 16 ) ;
F_36 ( F_370 ( V_77 ) , 0 ) ;
F_36 ( F_371 ( V_77 ) , V_617 ) ;
F_36 ( F_372 ( V_77 ) , 0 ) ;
F_36 ( F_373 ( V_77 ) , 0 ) ;
F_36 ( F_374 ( V_77 ) , V_617 << 16 ) ;
F_36 ( F_375 ( V_77 ) , 0 ) ;
F_36 ( F_376 ( V_77 ) , 0 ) ;
F_36 ( F_377 ( V_77 ) , 0 ) ;
if ( F_35 ( V_2 ) -> V_85 > 6 ) {
T_6 V_618 = 0 ;
if ( V_79 -> V_80 . V_566 )
V_618 = ( 16 * ( 1 << 13 ) / 255 ) & 0x1fff ;
F_36 ( F_378 ( V_77 ) , V_618 ) ;
F_36 ( F_379 ( V_77 ) , V_618 ) ;
F_36 ( F_380 ( V_77 ) , V_618 ) ;
F_36 ( F_381 ( V_77 ) , 0 ) ;
} else {
T_4 V_288 = V_619 ;
if ( V_79 -> V_80 . V_566 )
V_288 |= V_620 ;
F_36 ( F_381 ( V_77 ) , V_288 ) ;
}
}
static void F_382 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
enum V_76 V_81 = V_79 -> V_80 . V_81 ;
T_4 V_110 ;
V_110 = 0 ;
if ( V_79 -> V_80 . V_557 )
V_110 |= ( V_558 | V_559 ) ;
if ( V_79 -> V_80 . V_426 . V_332 & V_536 )
V_110 |= V_202 ;
else
V_110 |= V_565 ;
F_36 ( F_38 ( V_81 ) , V_110 ) ;
F_98 ( F_38 ( V_81 ) ) ;
F_36 ( F_383 ( V_79 -> V_77 ) , V_621 ) ;
F_98 ( F_383 ( V_79 -> V_77 ) ) ;
}
static bool F_384 ( struct V_10 * V_11 ,
T_3 * clock ,
bool * V_569 ,
T_3 * V_482 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_48 * V_48 ;
int V_12 ;
const T_2 * V_13 ;
bool V_219 , V_570 = false ;
F_19 (dev, crtc, intel_encoder) {
switch ( V_48 -> type ) {
case V_14 :
V_570 = true ;
break;
}
}
V_12 = F_366 ( V_11 ) ;
V_13 = F_11 ( V_11 , V_12 ) ;
V_219 = V_4 -> V_269 . V_571 ( V_13 , V_11 ,
F_27 ( V_11 ) -> V_80 . V_505 ,
V_12 , NULL , clock ) ;
if ( ! V_219 )
return false ;
if ( V_570 && V_4 -> V_573 ) {
* V_569 =
V_4 -> V_269 . V_571 ( V_13 , V_11 ,
V_4 -> V_574 ,
V_12 , clock ,
V_482 ) ;
}
return true ;
}
int F_290 ( int V_622 , int V_428 , int V_623 )
{
T_1 V_624 = V_622 * V_623 * 21 / 20 ;
return V_624 / ( V_428 * 8 ) + 1 ;
}
static bool F_385 ( struct V_46 * V_46 , int V_625 )
{
return F_17 ( V_46 ) < V_625 * V_46 -> V_44 ;
}
static T_4 F_386 ( struct V_79 * V_79 ,
T_1 * V_483 ,
T_3 * V_482 , T_1 * V_484 )
{
struct V_10 * V_11 = & V_79 -> V_114 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_48 * V_48 ;
T_4 V_46 ;
int V_625 , V_480 = 0 ;
bool V_570 = false , V_513 = false ;
F_19 (dev, crtc, intel_encoder) {
switch ( V_48 -> type ) {
case V_14 :
V_570 = true ;
break;
case V_25 :
case V_22 :
V_513 = true ;
break;
}
V_480 ++ ;
}
V_625 = 21 ;
if ( V_570 ) {
if ( ( F_308 ( V_4 ) &&
V_4 -> V_477 . V_481 == 100 ) ||
( F_45 ( V_2 ) && F_9 ( V_2 ) ) )
V_625 = 25 ;
} else if ( V_79 -> V_80 . V_526 )
V_625 = 20 ;
if ( F_385 ( & V_79 -> V_80 . V_46 , V_625 ) )
* V_483 |= V_626 ;
if ( V_484 && ( V_482 -> V_38 < V_625 * V_482 -> V_44 ) )
* V_484 |= V_626 ;
V_46 = 0 ;
if ( V_570 )
V_46 |= V_514 ;
else
V_46 |= V_515 ;
V_46 |= ( V_79 -> V_80 . V_432 - 1 )
<< V_627 ;
if ( V_513 )
V_46 |= V_517 ;
if ( V_79 -> V_80 . V_512 )
V_46 |= V_517 ;
V_46 |= ( 1 << ( V_79 -> V_80 . V_46 . V_41 - 1 ) ) << V_519 ;
V_46 |= ( 1 << ( V_79 -> V_80 . V_46 . V_41 - 1 ) ) << V_520 ;
switch ( V_79 -> V_80 . V_46 . V_42 ) {
case 5 :
V_46 |= V_521 ;
break;
case 7 :
V_46 |= V_522 ;
break;
case 10 :
V_46 |= V_523 ;
break;
case 14 :
V_46 |= V_524 ;
break;
}
if ( V_570 && F_308 ( V_4 ) && V_480 < 2 )
V_46 |= V_528 ;
else
V_46 |= V_529 ;
return V_46 | V_112 ;
}
static int F_387 ( struct V_10 * V_11 ,
int V_229 , int V_230 ,
struct V_236 * V_237 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
int V_77 = V_79 -> V_77 ;
int V_144 = V_79 -> V_144 ;
int V_480 = 0 ;
T_3 clock , V_482 ;
T_1 V_46 = 0 , V_483 = 0 , V_484 = 0 ;
bool V_568 , V_569 = false ;
bool V_570 = false ;
struct V_48 * V_49 ;
struct V_113 * V_117 ;
int V_219 ;
F_19 (dev, crtc, encoder) {
switch ( V_49 -> type ) {
case V_14 :
V_570 = true ;
break;
}
V_480 ++ ;
}
F_39 ( ! ( F_45 ( V_2 ) || F_80 ( V_2 ) ) ,
L_106 , F_388 ( V_2 ) ) ;
V_568 = F_384 ( V_11 , & clock ,
& V_569 , & V_482 ) ;
if ( ! V_568 && ! V_79 -> V_80 . V_572 ) {
F_100 ( L_97 ) ;
return - V_224 ;
}
if ( ! V_79 -> V_80 . V_572 ) {
V_79 -> V_80 . V_46 . V_44 = clock . V_44 ;
V_79 -> V_80 . V_46 . V_47 = clock . V_47 ;
V_79 -> V_80 . V_46 . V_39 = clock . V_39 ;
V_79 -> V_80 . V_46 . V_41 = clock . V_41 ;
V_79 -> V_80 . V_46 . V_42 = clock . V_42 ;
}
if ( V_79 -> V_80 . V_302 ) {
V_483 = F_312 ( & V_79 -> V_80 . V_46 ) ;
if ( V_569 )
V_484 = F_312 ( & V_482 ) ;
V_46 = F_386 ( V_79 ,
& V_483 , & V_482 ,
V_569 ? & V_484 : NULL ) ;
V_79 -> V_80 . V_185 . V_46 = V_46 ;
V_79 -> V_80 . V_185 . V_485 = V_483 ;
if ( V_569 )
V_79 -> V_80 . V_185 . V_488 = V_484 ;
else
V_79 -> V_80 . V_185 . V_488 = V_483 ;
V_117 = F_227 ( V_79 ) ;
if ( V_117 == NULL ) {
F_52 ( L_107 ,
F_62 ( V_77 ) ) ;
return - V_224 ;
}
} else
F_226 ( V_79 ) ;
if ( V_79 -> V_80 . V_512 )
F_334 ( V_79 ) ;
if ( V_570 && V_569 && V_487 )
V_79 -> V_486 = true ;
else
V_79 -> V_486 = false ;
if ( V_79 -> V_80 . V_302 ) {
V_117 = F_49 ( V_79 ) ;
}
F_347 ( V_79 ) ;
if ( V_79 -> V_80 . V_302 ) {
F_326 ( V_79 ,
& V_79 -> V_80 . V_434 ) ;
}
F_367 ( V_11 ) ;
F_36 ( F_67 ( V_144 ) , V_575 ) ;
F_98 ( F_67 ( V_144 ) ) ;
V_219 = F_162 ( V_11 , V_229 , V_230 , V_237 ) ;
F_238 ( V_2 ) ;
return V_219 ;
}
static void F_389 ( struct V_79 * V_11 ,
struct V_399 * V_400 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_76 V_76 = V_400 -> V_81 ;
V_400 -> V_434 . V_474 = F_4 ( F_328 ( V_76 ) ) ;
V_400 -> V_434 . V_475 = F_4 ( F_329 ( V_76 ) ) ;
V_400 -> V_434 . V_472 = F_4 ( F_221 ( V_76 ) )
& ~ V_360 ;
V_400 -> V_434 . V_473 = F_4 ( F_327 ( V_76 ) ) ;
V_400 -> V_434 . V_471 = ( ( F_4 ( F_221 ( V_76 ) )
& V_360 ) >> V_628 ) + 1 ;
}
static void F_390 ( struct V_79 * V_11 ,
struct V_399 * V_400 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_548 ;
V_548 = F_4 ( F_164 ( V_11 -> V_77 ) ) ;
if ( V_548 & V_380 ) {
V_400 -> V_291 . V_108 = true ;
V_400 -> V_291 . V_382 = F_4 ( F_165 ( V_11 -> V_77 ) ) ;
V_400 -> V_291 . V_383 = F_4 ( F_166 ( V_11 -> V_77 ) ) ;
if ( F_391 ( V_2 ) ) {
F_2 ( ( V_548 & V_629 ) !=
F_230 ( V_11 -> V_77 ) ) ;
}
}
}
static bool F_392 ( struct V_79 * V_11 ,
struct V_399 * V_400 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_548 ;
V_400 -> V_81 = (enum V_76 ) V_11 -> V_77 ;
V_400 -> V_115 = V_375 ;
V_548 = F_4 ( F_38 ( V_11 -> V_77 ) ) ;
if ( ! ( V_548 & V_143 ) )
return false ;
switch ( V_548 & V_199 ) {
case V_560 :
V_400 -> V_433 = 18 ;
break;
case V_561 :
V_400 -> V_433 = 24 ;
break;
case V_562 :
V_400 -> V_433 = 30 ;
break;
case V_616 :
V_400 -> V_433 = 36 ;
break;
default:
break;
}
if ( F_4 ( F_78 ( V_11 -> V_77 ) ) & V_158 ) {
struct V_113 * V_117 ;
V_400 -> V_302 = true ;
V_548 = F_4 ( F_58 ( V_11 -> V_77 ) ) ;
V_400 -> V_312 = ( ( V_311 & V_548 ) >>
V_630 ) + 1 ;
F_389 ( V_11 , V_400 ) ;
if ( F_45 ( V_4 -> V_2 ) ) {
V_400 -> V_115 =
(enum V_376 ) V_11 -> V_77 ;
} else {
V_548 = F_4 ( V_363 ) ;
if ( V_548 & F_223 ( V_11 -> V_77 ) )
V_400 -> V_115 = V_364 ;
else
V_400 -> V_115 = V_631 ;
}
V_117 = & V_4 -> V_116 [ V_400 -> V_115 ] ;
F_2 ( ! V_117 -> V_120 ( V_4 , V_117 ,
& V_400 -> V_185 ) ) ;
V_548 = V_400 -> V_185 . V_46 ;
V_400 -> V_432 =
( ( V_548 & V_632 )
>> V_627 ) + 1 ;
} else {
V_400 -> V_432 = 1 ;
}
F_348 ( V_11 , V_400 ) ;
F_390 ( V_11 , V_400 ) ;
return true ;
}
static void F_393 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_633 * V_634 = & V_4 -> V_635 ;
struct V_79 * V_11 ;
unsigned long V_636 ;
T_4 V_110 ;
F_154 (crtc, &dev->mode_config.crtc_list, base.head)
F_39 ( V_11 -> V_114 . V_108 , L_108 ,
F_62 ( V_11 -> V_77 ) ) ;
F_39 ( F_4 ( V_637 ) , L_109 ) ;
F_39 ( V_634 -> V_638 , L_110 ) ;
F_39 ( V_634 -> V_639 , L_111 ) ;
F_39 ( V_634 -> V_640 , L_112 ) ;
F_39 ( F_4 ( V_641 ) & V_642 , L_113 ) ;
F_39 ( F_4 ( V_643 ) & V_644 ,
L_114 ) ;
F_39 ( F_4 ( V_645 ) & V_644 ,
L_115 ) ;
F_39 ( F_4 ( V_646 ) & V_647 ,
L_116 ) ;
F_39 ( F_4 ( V_648 ) & V_649 ,
L_117 ) ;
F_39 ( F_4 ( V_650 ) & V_651 , L_118 ) ;
F_190 ( & V_4 -> V_652 , V_636 ) ;
V_110 = F_4 ( V_653 ) ;
F_39 ( ( V_110 & ~ V_654 ) != V_110 ,
L_119 , V_110 ) ;
V_110 = F_4 ( V_655 ) ;
F_39 ( ( V_110 | V_656 ) != 0xffffffff ,
L_120 , V_110 ) ;
F_191 ( & V_4 -> V_652 , V_636 ) ;
}
void F_394 ( struct V_3 * V_4 ,
bool V_657 , bool V_658 )
{
T_4 V_110 ;
F_393 ( V_4 ) ;
V_110 = F_4 ( V_659 ) ;
if ( V_657 ) {
V_110 |= V_660 ;
F_36 ( V_659 , V_110 ) ;
if ( F_360 ( F_4 ( V_659 ) &
V_661 , 1 ) )
F_100 ( L_121 ) ;
V_110 = F_4 ( V_659 ) ;
}
V_110 |= V_662 ;
F_36 ( V_659 , V_110 ) ;
F_98 ( V_659 ) ;
if ( F_30 ( ( F_4 ( V_659 ) & V_663 ) == 0 , 1 ) )
F_100 ( L_122 ) ;
V_110 = F_4 ( V_664 ) ;
V_110 |= V_665 ;
F_36 ( V_664 , V_110 ) ;
F_98 ( V_664 ) ;
F_395 ( 100 ) ;
if ( F_30 ( ( F_4 ( V_664 ) & V_666 ) == 0 , 1 ) )
F_100 ( L_123 ) ;
if ( V_658 ) {
V_110 = F_4 ( V_659 ) ;
V_110 |= V_667 ;
F_36 ( V_659 , V_110 ) ;
F_98 ( V_659 ) ;
}
}
void F_396 ( struct V_3 * V_4 )
{
T_4 V_110 ;
V_110 = F_4 ( V_659 ) ;
if ( ( V_110 & ( V_663 | V_662 | V_660 |
V_667 ) ) == V_663 )
return;
V_4 -> V_668 . V_669 . V_670 ( V_4 ) ;
if ( V_110 & V_667 ) {
V_110 &= ~ V_667 ;
F_36 ( V_659 , V_110 ) ;
F_98 ( V_659 ) ;
}
V_110 = F_4 ( V_664 ) ;
V_110 |= V_671 ;
V_110 &= ~ V_665 ;
F_36 ( V_664 , V_110 ) ;
F_98 ( V_664 ) ;
V_110 = F_4 ( V_659 ) ;
V_110 &= ~ V_662 ;
F_36 ( V_659 , V_110 ) ;
if ( F_30 ( F_4 ( V_659 ) & V_663 , 5 ) )
F_100 ( L_124 ) ;
if ( V_110 & V_660 ) {
V_110 = F_4 ( V_659 ) ;
V_110 &= ~ V_660 ;
F_36 ( V_659 , V_110 ) ;
if ( F_360 ( ( F_4 ( V_659 ) &
V_661 ) == 0 , 1 ) )
F_100 ( L_125 ) ;
}
V_4 -> V_668 . V_669 . V_672 ( V_4 ) ;
}
void F_397 ( struct V_673 * V_674 )
{
struct V_3 * V_4 =
F_398 ( F_399 ( V_674 ) , struct V_3 ,
V_675 . V_676 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_110 ;
if ( V_4 -> V_675 . V_108 )
return;
F_32 ( L_126 ) ;
V_4 -> V_675 . V_108 = true ;
if ( V_4 -> V_608 == V_609 ) {
V_110 = F_4 ( V_677 ) ;
V_110 &= ~ V_678 ;
F_36 ( V_677 , V_110 ) ;
}
F_363 ( V_2 ) ;
F_400 ( V_2 ) ;
F_394 ( V_4 , true , true ) ;
}
static void F_401 ( struct V_3 * V_4 )
{
F_2 ( ! F_402 ( & V_4 -> V_675 . V_679 ) ) ;
F_39 ( V_4 -> V_675 . V_680 < 1 ,
L_127 , V_4 -> V_675 . V_680 ) ;
V_4 -> V_675 . V_680 -- ;
if ( V_4 -> V_675 . V_680 != 0 )
return;
F_403 ( & V_4 -> V_675 . V_676 ,
F_41 ( V_681 ) ) ;
}
static void F_404 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_110 ;
F_2 ( ! F_402 ( & V_4 -> V_675 . V_679 ) ) ;
F_39 ( V_4 -> V_675 . V_680 < 0 ,
L_127 , V_4 -> V_675 . V_680 ) ;
V_4 -> V_675 . V_680 ++ ;
if ( V_4 -> V_675 . V_680 != 1 )
return;
F_405 ( & V_4 -> V_675 . V_676 ) ;
if ( ! V_4 -> V_675 . V_108 )
return;
F_32 ( L_128 ) ;
F_396 ( V_4 ) ;
F_406 ( V_2 ) ;
F_364 ( V_2 ) ;
if ( V_4 -> V_608 == V_609 ) {
V_110 = F_4 ( V_677 ) ;
V_110 |= V_678 ;
F_36 ( V_677 , V_110 ) ;
}
F_407 ( V_2 ) ;
F_408 ( V_2 ) ;
F_157 ( & V_4 -> V_682 . V_683 ) ;
F_409 ( V_2 ) ;
F_158 ( & V_4 -> V_682 . V_683 ) ;
V_4 -> V_675 . V_108 = false ;
}
void F_410 ( struct V_3 * V_4 )
{
F_157 ( & V_4 -> V_675 . V_679 ) ;
F_401 ( V_4 ) ;
F_158 ( & V_4 -> V_675 . V_679 ) ;
}
void F_411 ( struct V_3 * V_4 )
{
F_157 ( & V_4 -> V_675 . V_679 ) ;
F_404 ( V_4 ) ;
F_158 ( & V_4 -> V_675 . V_679 ) ;
}
static bool F_412 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_79 * V_11 ;
T_4 V_110 ;
F_154 (crtc, &dev->mode_config.crtc_list, base.head)
if ( V_11 -> V_114 . V_108 )
return false ;
V_110 = F_4 ( V_637 ) ;
if ( V_110 != 0 ) {
F_32 ( L_129 ) ;
return false ;
}
return true ;
}
static void F_413 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_684 ;
if ( ! V_685 )
return;
F_157 ( & V_4 -> V_675 . V_679 ) ;
V_684 = F_412 ( V_4 ) ;
if ( V_684 == V_4 -> V_675 . V_686 )
goto V_687;
V_4 -> V_675 . V_686 = V_684 ;
if ( V_684 )
F_401 ( V_4 ) ;
else
F_404 ( V_4 ) ;
V_687:
F_158 ( & V_4 -> V_675 . V_679 ) ;
}
static void F_414 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_675 . V_688 ) {
V_4 -> V_675 . V_688 = true ;
F_410 ( V_4 ) ;
}
}
static void F_415 ( struct V_3 * V_4 )
{
if ( V_4 -> V_675 . V_688 ) {
V_4 -> V_675 . V_688 = false ;
F_411 ( V_4 ) ;
}
}
static void F_416 ( struct V_1 * V_2 )
{
bool V_195 = false ;
struct V_79 * V_11 ;
F_154 (crtc, &dev->mode_config.crtc_list, base.head) {
if ( ! V_11 -> V_114 . V_108 )
continue;
if ( V_11 -> V_77 != V_131 || V_11 -> V_80 . V_291 . V_108 ||
V_11 -> V_80 . V_81 != V_547 )
V_195 = true ;
}
F_417 ( V_2 , V_195 ) ;
F_413 ( V_2 ) ;
}
static int F_418 ( struct V_10 * V_11 ,
int V_229 , int V_230 ,
struct V_236 * V_237 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
int V_144 = V_79 -> V_144 ;
int V_219 ;
if ( ! F_419 ( V_11 ) )
return - V_224 ;
if ( V_79 -> V_80 . V_512 )
F_334 ( V_79 ) ;
V_79 -> V_486 = false ;
F_347 ( V_79 ) ;
if ( V_79 -> V_80 . V_302 ) {
F_326 ( V_79 ,
& V_79 -> V_80 . V_434 ) ;
}
F_382 ( V_11 ) ;
F_368 ( V_11 ) ;
F_36 ( F_67 ( V_144 ) , V_575 | V_689 ) ;
F_98 ( F_67 ( V_144 ) ) ;
V_219 = F_162 ( V_11 , V_229 , V_230 , V_237 ) ;
F_238 ( V_2 ) ;
return V_219 ;
}
static bool F_420 ( struct V_79 * V_11 ,
struct V_399 * V_400 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_690 V_691 ;
T_4 V_548 ;
V_400 -> V_81 = (enum V_76 ) V_11 -> V_77 ;
V_400 -> V_115 = V_375 ;
V_548 = F_4 ( F_55 ( V_547 ) ) ;
if ( V_548 & V_122 ) {
enum V_77 V_692 ;
switch ( V_548 & V_693 ) {
default:
F_39 ( 1 , L_130 ) ;
case V_694 :
case V_695 :
V_692 = V_131 ;
break;
case V_696 :
V_692 = V_140 ;
break;
case V_697 :
V_692 = V_305 ;
break;
}
if ( V_692 == V_11 -> V_77 )
V_400 -> V_81 = V_547 ;
}
if ( ! F_64 ( V_2 ,
F_65 ( V_400 -> V_81 ) ) )
return false ;
V_548 = F_4 ( F_38 ( V_400 -> V_81 ) ) ;
if ( ! ( V_548 & V_143 ) )
return false ;
V_548 = F_4 ( F_55 ( V_400 -> V_81 ) ) ;
if ( ( V_548 & V_698 ) == F_421 ( V_699 ) &&
F_4 ( V_210 ) & V_158 ) {
V_400 -> V_302 = true ;
V_548 = F_4 ( F_58 ( V_131 ) ) ;
V_400 -> V_312 = ( ( V_311 & V_548 ) >>
V_630 ) + 1 ;
F_389 ( V_11 , V_400 ) ;
}
F_348 ( V_11 , V_400 ) ;
V_691 = F_422 ( V_11 -> V_77 ) ;
if ( F_64 ( V_2 , V_691 ) )
F_390 ( V_11 , V_400 ) ;
V_400 -> V_386 = F_241 ( V_11 ) &&
( F_4 ( V_387 ) & V_388 ) ;
V_400 -> V_432 = 1 ;
return true ;
}
static int F_423 ( struct V_10 * V_11 ,
int V_229 , int V_230 ,
struct V_236 * V_237 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_48 * V_49 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_425 * V_288 = & V_79 -> V_80 . V_438 ;
int V_77 = V_79 -> V_77 ;
int V_219 ;
F_424 ( V_2 , V_77 ) ;
V_219 = V_4 -> V_269 . V_700 ( V_11 , V_229 , V_230 , V_237 ) ;
F_425 ( V_2 , V_77 ) ;
if ( V_219 != 0 )
return V_219 ;
F_19 (dev, crtc, encoder) {
F_32 ( L_131 ,
V_49 -> V_114 . V_114 . V_194 ,
F_426 ( & V_49 -> V_114 ) ,
V_288 -> V_114 . V_194 , V_288 -> V_121 ) ;
V_49 -> V_378 ( V_49 ) ;
}
return 0 ;
}
static bool F_427 ( struct V_415 * V_416 ,
int V_701 , T_4 V_702 ,
int V_703 , T_4 V_704 ,
int V_705 )
{
struct V_3 * V_4 = V_416 -> V_2 -> V_5 ;
T_7 * V_706 = V_416 -> V_706 ;
T_4 V_146 ;
V_146 = F_4 ( V_701 ) ;
V_146 &= V_702 ;
if ( ! V_706 [ 0 ] )
return ! V_146 ;
if ( ! V_146 )
return false ;
V_146 = F_4 ( V_703 ) ;
V_146 &= ~ V_704 ;
F_36 ( V_703 , V_146 ) ;
for ( V_146 = 0 ; V_146 < V_706 [ 2 ] ; V_146 ++ )
if ( F_4 ( V_705 ) != * ( ( T_4 * ) V_706 + V_146 ) )
return false ;
return true ;
}
static void F_428 ( struct V_415 * V_416 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = V_416 -> V_2 -> V_5 ;
T_7 * V_706 = V_416 -> V_706 ;
T_4 V_707 ;
T_4 V_708 ;
T_4 V_146 ;
V_146 = F_4 ( V_709 ) ;
if ( V_146 == V_710 || V_146 == V_711 )
V_707 = V_712 ;
else
V_707 = V_713 ;
if ( F_427 ( V_416 ,
V_714 , V_707 ,
V_714 , V_715 ,
V_716 ) )
return;
V_146 = F_4 ( V_714 ) ;
V_146 &= ~ ( V_707 | V_715 ) ;
V_708 = ( V_146 >> 9 ) & 0x1f ;
F_36 ( V_714 , V_146 ) ;
if ( ! V_706 [ 0 ] )
return;
V_708 = F_306 ( T_7 , V_706 [ 2 ] , V_708 ) ;
F_52 ( L_132 , V_708 ) ;
for ( V_146 = 0 ; V_146 < V_708 ; V_146 ++ )
F_36 ( V_716 , * ( ( T_4 * ) V_706 + V_146 ) ) ;
V_146 = F_4 ( V_714 ) ;
V_146 |= V_707 ;
F_36 ( V_714 , V_146 ) ;
}
static void F_429 ( struct V_415 * V_416 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = V_416 -> V_2 -> V_5 ;
T_7 * V_706 = V_416 -> V_706 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
T_4 V_707 ;
T_4 V_146 ;
int V_708 ;
int V_77 = F_27 ( V_11 ) -> V_77 ;
int V_548 ;
int V_717 = F_430 ( V_77 ) ;
int V_718 = F_431 ( V_77 ) ;
int V_719 = F_432 ( V_77 ) ;
int V_720 = V_721 ;
F_52 ( L_133 ) ;
F_52 ( L_134 ) ;
V_548 = F_4 ( V_720 ) ;
V_548 |= ( V_722 << ( V_77 * 4 ) ) ;
F_36 ( V_720 , V_548 ) ;
F_33 ( V_2 , V_77 ) ;
V_548 = F_4 ( V_720 ) ;
F_52 ( L_135 , V_548 ) ;
V_548 |= ( V_723 << ( V_77 * 4 ) ) ;
F_36 ( V_720 , V_548 ) ;
V_548 = F_4 ( V_720 ) ;
F_52 ( L_136 , V_548 ) ;
V_548 = F_4 ( V_719 ) ;
F_52 ( L_137 , V_548 ) ;
V_548 &= ~ ( V_724 | V_725 ) ;
F_36 ( V_719 , V_548 ) ;
F_52 ( L_138 , F_62 ( V_77 ) ) ;
V_707 = V_723 << ( V_77 * 4 ) ;
V_79 -> V_417 = true ;
if ( F_8 ( V_11 , V_365 ) ) {
F_52 ( L_139 ) ;
V_706 [ 5 ] |= ( 1 << 2 ) ;
F_36 ( V_719 , V_724 ) ;
} else
F_36 ( V_719 , 0 ) ;
if ( F_427 ( V_416 ,
V_720 , V_707 ,
V_718 , V_726 ,
V_717 ) )
return;
V_146 = F_4 ( V_720 ) ;
V_146 &= ~ V_707 ;
F_36 ( V_720 , V_146 ) ;
if ( ! V_706 [ 0 ] )
return;
V_146 = F_4 ( V_718 ) ;
V_146 &= ~ V_726 ;
F_36 ( V_718 , V_146 ) ;
V_146 = ( V_146 >> 29 ) & V_727 ;
F_52 ( L_140 , V_146 ) ;
V_708 = F_306 ( T_7 , V_706 [ 2 ] , 21 ) ;
F_52 ( L_132 , V_708 ) ;
for ( V_146 = 0 ; V_146 < V_708 ; V_146 ++ )
F_36 ( V_717 , * ( ( T_4 * ) V_706 + V_146 ) ) ;
V_146 = F_4 ( V_720 ) ;
V_146 |= V_707 ;
F_36 ( V_720 , V_146 ) ;
}
static void F_433 ( struct V_415 * V_416 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = V_416 -> V_2 -> V_5 ;
T_7 * V_706 = V_416 -> V_706 ;
T_4 V_707 ;
T_4 V_146 ;
int V_708 ;
int V_717 ;
int V_719 ;
int V_718 ;
int V_720 ;
int V_77 = F_27 ( V_11 ) -> V_77 ;
if ( F_45 ( V_416 -> V_2 ) ) {
V_717 = F_434 ( V_77 ) ;
V_719 = F_435 ( V_77 ) ;
V_718 = F_436 ( V_77 ) ;
V_720 = V_728 ;
} else {
V_717 = F_437 ( V_77 ) ;
V_719 = F_438 ( V_77 ) ;
V_718 = F_439 ( V_77 ) ;
V_720 = V_729 ;
}
F_52 ( L_138 , F_62 ( V_77 ) ) ;
V_146 = F_4 ( V_718 ) ;
V_146 = ( V_146 >> 29 ) & V_727 ;
if ( ! V_146 ) {
F_52 ( L_141 ) ;
V_707 = V_730 ;
V_707 |= V_730 << 4 ;
V_707 |= V_730 << 8 ;
} else {
F_52 ( L_142 , F_440 ( V_146 ) ) ;
V_707 = V_730 << ( ( V_146 - 1 ) * 4 ) ;
}
if ( F_8 ( V_11 , V_365 ) ) {
F_52 ( L_139 ) ;
V_706 [ 5 ] |= ( 1 << 2 ) ;
F_36 ( V_719 , V_724 ) ;
} else
F_36 ( V_719 , 0 ) ;
if ( F_427 ( V_416 ,
V_720 , V_707 ,
V_718 , V_726 ,
V_717 ) )
return;
V_146 = F_4 ( V_720 ) ;
V_146 &= ~ V_707 ;
F_36 ( V_720 , V_146 ) ;
if ( ! V_706 [ 0 ] )
return;
V_146 = F_4 ( V_718 ) ;
V_146 &= ~ V_726 ;
F_36 ( V_718 , V_146 ) ;
V_708 = F_306 ( T_7 , V_706 [ 2 ] , 21 ) ;
F_52 ( L_132 , V_708 ) ;
for ( V_146 = 0 ; V_146 < V_708 ; V_146 ++ )
F_36 ( V_717 , * ( ( T_4 * ) V_706 + V_146 ) ) ;
V_146 = F_4 ( V_720 ) ;
V_146 |= V_707 ;
F_36 ( V_720 , V_146 ) ;
}
void F_441 ( struct V_421 * V_49 ,
struct V_425 * V_288 )
{
struct V_10 * V_11 = V_49 -> V_11 ;
struct V_415 * V_416 ;
struct V_1 * V_2 = V_49 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_416 = F_442 ( V_49 , V_288 ) ;
if ( ! V_416 )
return;
F_52 ( L_143 ,
V_416 -> V_114 . V_194 ,
F_282 ( V_416 ) ,
V_416 -> V_49 -> V_114 . V_194 ,
F_426 ( V_416 -> V_49 ) ) ;
V_416 -> V_706 [ 6 ] = F_443 ( V_416 , V_288 ) / 2 ;
if ( V_4 -> V_269 . V_731 )
V_4 -> V_269 . V_731 ( V_416 , V_11 ) ;
}
void F_239 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
enum V_77 V_77 = V_79 -> V_77 ;
int V_732 = F_444 ( V_77 ) ;
int V_146 ;
bool V_733 = false ;
if ( ! V_11 -> V_108 || ! V_79 -> V_192 )
return;
if ( ! F_3 ( V_4 -> V_2 ) )
F_119 ( V_4 , V_77 ) ;
if ( F_3 ( V_2 ) )
V_732 = F_445 ( V_77 ) ;
if ( V_79 -> V_80 . V_386 &&
( ( F_4 ( F_383 ( V_77 ) ) & V_734 ) ==
V_735 ) ) {
F_244 ( V_79 ) ;
V_733 = true ;
}
for ( V_146 = 0 ; V_146 < 256 ; V_146 ++ ) {
F_36 ( V_732 + 4 * V_146 ,
( V_79 -> V_736 [ V_146 ] << 16 ) |
( V_79 -> V_737 [ V_146 ] << 8 ) |
V_79 -> V_738 [ V_146 ] ) ;
}
if ( V_733 )
F_243 ( V_79 ) ;
}
static void F_446 ( struct V_10 * V_11 , T_1 V_114 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
bool V_739 = V_114 != 0 ;
T_1 V_393 ;
if ( V_79 -> V_740 == V_739 )
return;
V_393 = F_4 ( V_741 ) ;
if ( V_739 ) {
F_36 ( V_742 , V_114 ) ;
V_393 &= ~ ( V_743 ) ;
V_393 |= V_744 |
V_745 |
V_746 ;
} else
V_393 &= ~ ( V_744 | V_745 ) ;
F_36 ( V_741 , V_393 ) ;
V_79 -> V_740 = V_739 ;
}
static void F_447 ( struct V_10 * V_11 , T_1 V_114 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
int V_77 = V_79 -> V_77 ;
bool V_739 = V_114 != 0 ;
if ( V_79 -> V_740 != V_739 ) {
T_4 V_393 = F_4 ( F_263 ( V_77 ) ) ;
if ( V_114 ) {
V_393 &= ~ ( V_394 | V_747 ) ;
V_393 |= V_398 | V_748 ;
V_393 |= V_77 << 28 ;
} else {
V_393 &= ~ ( V_394 | V_748 ) ;
V_393 |= V_749 ;
}
F_36 ( F_263 ( V_77 ) , V_393 ) ;
V_79 -> V_740 = V_739 ;
}
F_36 ( F_264 ( V_77 ) , V_114 ) ;
}
static void F_448 ( struct V_10 * V_11 , T_1 V_114 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
int V_77 = V_79 -> V_77 ;
bool V_739 = V_114 != 0 ;
if ( V_79 -> V_740 != V_739 ) {
T_4 V_393 = F_4 ( F_449 ( V_77 ) ) ;
if ( V_114 ) {
V_393 &= ~ V_394 ;
V_393 |= V_398 | V_748 ;
} else {
V_393 &= ~ ( V_394 | V_748 ) ;
V_393 |= V_749 ;
}
if ( F_149 ( V_2 ) ) {
V_393 |= V_750 ;
V_393 &= ~ V_751 ;
}
F_36 ( F_449 ( V_77 ) , V_393 ) ;
V_79 -> V_740 = V_739 ;
}
F_36 ( F_450 ( V_77 ) , V_114 ) ;
}
static void F_240 ( struct V_10 * V_11 ,
bool V_193 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
int V_77 = V_79 -> V_77 ;
int V_229 = V_79 -> V_752 ;
int V_230 = V_79 -> V_753 ;
T_1 V_114 , V_382 ;
bool V_739 ;
V_382 = 0 ;
if ( V_193 && V_11 -> V_108 && V_11 -> V_237 ) {
V_114 = V_79 -> V_754 ;
if ( V_229 > ( int ) V_11 -> V_237 -> V_755 )
V_114 = 0 ;
if ( V_230 > ( int ) V_11 -> V_237 -> V_756 )
V_114 = 0 ;
} else
V_114 = 0 ;
if ( V_229 < 0 ) {
if ( V_229 + V_79 -> V_757 < 0 )
V_114 = 0 ;
V_382 |= V_758 << V_759 ;
V_229 = - V_229 ;
}
V_382 |= V_229 << V_759 ;
if ( V_230 < 0 ) {
if ( V_230 + V_79 -> V_760 < 0 )
V_114 = 0 ;
V_382 |= V_758 << V_761 ;
V_230 = - V_230 ;
}
V_382 |= V_230 << V_761 ;
V_739 = V_114 != 0 ;
if ( ! V_739 && ! V_79 -> V_740 )
return;
if ( F_170 ( V_2 ) || F_149 ( V_2 ) ) {
F_36 ( F_451 ( V_77 ) , V_382 ) ;
F_448 ( V_11 , V_114 ) ;
} else {
F_36 ( F_452 ( V_77 ) , V_382 ) ;
if ( F_453 ( V_2 ) || F_454 ( V_2 ) )
F_446 ( V_11 , V_114 ) ;
else
F_447 ( V_11 , V_114 ) ;
}
}
static int F_455 ( struct V_10 * V_11 ,
struct V_762 * V_763 ,
T_4 V_764 ,
T_4 V_755 , T_4 V_756 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_214 * V_215 ;
T_4 V_765 ;
int V_219 ;
if ( ! V_764 ) {
F_32 ( L_144 ) ;
V_765 = 0 ;
V_215 = NULL ;
F_157 ( & V_2 -> V_286 ) ;
goto V_766;
}
if ( V_755 != 64 || V_756 != 64 ) {
F_100 ( L_145 ) ;
return - V_224 ;
}
V_215 = F_456 ( F_457 ( V_2 , V_763 , V_764 ) ) ;
if ( & V_215 -> V_114 == NULL )
return - V_767 ;
if ( V_215 -> V_114 . V_383 < V_755 * V_756 * 4 ) {
F_100 ( L_146 ) ;
V_219 = - V_768 ;
goto V_769;
}
F_157 ( & V_2 -> V_286 ) ;
if ( ! V_4 -> V_125 -> V_770 ) {
unsigned V_218 ;
if ( V_215 -> V_220 ) {
F_100 ( L_147 ) ;
V_219 = - V_224 ;
goto V_771;
}
V_218 = 0 ;
if ( F_128 ( V_2 ) )
V_218 = 64 * 1024 ;
V_219 = F_134 ( V_215 , V_218 , NULL ) ;
if ( V_219 ) {
F_100 ( L_148 ) ;
goto V_771;
}
V_219 = F_458 ( V_215 ) ;
if ( V_219 ) {
F_100 ( L_149 ) ;
goto V_772;
}
V_765 = F_143 ( V_215 ) ;
} else {
int V_773 = F_97 ( V_2 ) ? 16 * 1024 : 256 ;
V_219 = F_459 ( V_2 , V_215 ,
( V_79 -> V_77 == 0 ) ? V_774 : V_775 ,
V_773 ) ;
if ( V_219 ) {
F_100 ( L_150 ) ;
goto V_771;
}
V_765 = V_215 -> V_776 -> V_764 -> V_777 ;
}
if ( F_15 ( V_2 ) )
F_36 ( V_778 , ( V_756 << 12 ) | V_755 ) ;
V_766:
if ( V_79 -> V_779 ) {
if ( V_4 -> V_125 -> V_770 ) {
if ( V_79 -> V_779 != V_215 )
F_460 ( V_2 , V_79 -> V_779 ) ;
} else
F_137 ( V_79 -> V_779 ) ;
F_461 ( & V_79 -> V_779 -> V_114 ) ;
}
F_158 ( & V_2 -> V_286 ) ;
V_79 -> V_754 = V_765 ;
V_79 -> V_779 = V_215 ;
V_79 -> V_757 = V_755 ;
V_79 -> V_760 = V_756 ;
if ( V_79 -> V_192 )
F_240 ( V_11 , V_79 -> V_779 != NULL ) ;
return 0 ;
V_772:
F_137 ( V_215 ) ;
V_771:
F_158 ( & V_2 -> V_286 ) ;
V_769:
F_462 ( & V_215 -> V_114 ) ;
return V_219 ;
}
static int F_463 ( struct V_10 * V_11 , int V_229 , int V_230 )
{
struct V_79 * V_79 = F_27 ( V_11 ) ;
V_79 -> V_752 = V_229 ;
V_79 -> V_753 = V_230 ;
if ( V_79 -> V_192 )
F_240 ( V_11 , V_79 -> V_779 != NULL ) ;
return 0 ;
}
void F_464 ( struct V_10 * V_11 , T_5 V_780 , T_5 V_781 ,
T_5 V_782 , int V_783 )
{
struct V_79 * V_79 = F_27 ( V_11 ) ;
V_79 -> V_736 [ V_783 ] = V_780 >> 8 ;
V_79 -> V_737 [ V_783 ] = V_781 >> 8 ;
V_79 -> V_738 [ V_783 ] = V_782 >> 8 ;
}
void F_465 ( struct V_10 * V_11 , T_5 * V_780 , T_5 * V_781 ,
T_5 * V_782 , int V_783 )
{
struct V_79 * V_79 = F_27 ( V_11 ) ;
* V_780 = V_79 -> V_736 [ V_783 ] << 8 ;
* V_781 = V_79 -> V_737 [ V_783 ] << 8 ;
* V_782 = V_79 -> V_738 [ V_783 ] << 8 ;
}
static void F_466 ( struct V_10 * V_11 , T_5 * V_780 , T_5 * V_781 ,
T_5 * V_782 , T_4 V_784 , T_4 V_383 )
{
int V_785 = ( V_784 + V_383 > 256 ) ? 256 : V_784 + V_383 , V_146 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
for ( V_146 = V_784 ; V_146 < V_785 ; V_146 ++ ) {
V_79 -> V_736 [ V_146 ] = V_780 [ V_146 ] >> 8 ;
V_79 -> V_737 [ V_146 ] = V_781 [ V_146 ] >> 8 ;
V_79 -> V_738 [ V_146 ] = V_782 [ V_146 ] >> 8 ;
}
F_239 ( V_11 ) ;
}
static struct V_236 *
F_467 ( struct V_1 * V_2 ,
struct V_786 * V_787 ,
struct V_214 * V_215 )
{
struct V_238 * V_239 ;
int V_219 ;
V_239 = F_468 ( sizeof( * V_239 ) , V_788 ) ;
if ( ! V_239 ) {
F_462 ( & V_215 -> V_114 ) ;
return F_469 ( - V_768 ) ;
}
V_219 = F_470 ( V_2 , V_239 , V_787 , V_215 ) ;
if ( V_219 ) {
F_462 ( & V_215 -> V_114 ) ;
F_279 ( V_239 ) ;
return F_469 ( V_219 ) ;
}
return & V_239 -> V_114 ;
}
static T_1
F_471 ( int V_755 , int V_623 )
{
T_1 V_232 = F_472 ( V_755 * V_623 , 8 ) ;
return F_473 ( V_232 , 64 ) ;
}
static T_1
F_474 ( struct V_425 * V_288 , int V_623 )
{
T_1 V_232 = F_471 ( V_288 -> V_289 , V_623 ) ;
return F_473 ( V_232 * V_288 -> V_290 , V_789 ) ;
}
static struct V_236 *
F_475 ( struct V_1 * V_2 ,
struct V_425 * V_288 ,
int V_790 , int V_623 )
{
struct V_214 * V_215 ;
struct V_786 V_787 = { 0 } ;
V_215 = F_476 ( V_2 ,
F_474 ( V_288 , V_623 ) ) ;
if ( V_215 == NULL )
return F_469 ( - V_768 ) ;
V_787 . V_755 = V_288 -> V_289 ;
V_787 . V_756 = V_288 -> V_290 ;
V_787 . V_265 [ 0 ] = F_471 ( V_787 . V_755 ,
V_623 ) ;
V_787 . V_243 = F_477 ( V_623 , V_790 ) ;
return F_467 ( V_2 , & V_787 , V_215 ) ;
}
static struct V_236 *
F_478 ( struct V_1 * V_2 ,
struct V_425 * V_288 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_214 * V_215 ;
struct V_236 * V_237 ;
if ( V_4 -> V_791 == NULL )
return NULL ;
V_215 = V_4 -> V_791 -> V_792 . V_215 ;
if ( V_215 == NULL )
return NULL ;
V_237 = & V_4 -> V_791 -> V_792 . V_114 ;
if ( V_237 -> V_265 [ 0 ] < F_471 ( V_288 -> V_289 ,
V_237 -> V_266 ) )
return NULL ;
if ( V_215 -> V_114 . V_383 < V_288 -> V_290 * V_237 -> V_265 [ 0 ] )
return NULL ;
return V_237 ;
}
bool F_479 ( struct V_415 * V_416 ,
struct V_425 * V_288 ,
struct V_793 * V_794 )
{
struct V_79 * V_79 ;
struct V_48 * V_48 =
F_480 ( V_416 ) ;
struct V_10 * V_795 ;
struct V_421 * V_49 = & V_48 -> V_114 ;
struct V_10 * V_11 = NULL ;
struct V_1 * V_2 = V_49 -> V_2 ;
struct V_236 * V_237 ;
int V_146 = - 1 ;
F_32 ( L_151 ,
V_416 -> V_114 . V_194 , F_282 ( V_416 ) ,
V_49 -> V_114 . V_194 , F_426 ( V_49 ) ) ;
if ( V_49 -> V_11 ) {
V_11 = V_49 -> V_11 ;
F_157 ( & V_11 -> V_272 ) ;
V_794 -> V_796 = V_416 -> V_419 ;
V_794 -> V_797 = false ;
if ( V_416 -> V_419 != V_422 )
V_416 -> V_669 -> V_419 ( V_416 , V_422 ) ;
return true ;
}
F_154 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_146 ++ ;
if ( ! ( V_49 -> V_798 & ( 1 << V_146 ) ) )
continue;
if ( ! V_795 -> V_108 ) {
V_11 = V_795 ;
break;
}
}
if ( ! V_11 ) {
F_32 ( L_152 ) ;
return false ;
}
F_157 ( & V_11 -> V_272 ) ;
V_48 -> V_799 = F_27 ( V_11 ) ;
F_481 ( V_416 ) -> V_800 = V_48 ;
V_79 = F_27 ( V_11 ) ;
V_794 -> V_796 = V_416 -> V_419 ;
V_794 -> V_797 = true ;
V_794 -> V_801 = NULL ;
if ( ! V_288 )
V_288 = & V_802 ;
V_237 = F_478 ( V_2 , V_288 ) ;
if ( V_237 == NULL ) {
F_32 ( L_153 ) ;
V_237 = F_475 ( V_2 , V_288 , 24 , 32 ) ;
V_794 -> V_801 = V_237 ;
} else
F_32 ( L_154 ) ;
if ( F_482 ( V_237 ) ) {
F_32 ( L_155 ) ;
F_158 ( & V_11 -> V_272 ) ;
return false ;
}
if ( F_483 ( V_11 , V_288 , 0 , 0 , V_237 ) ) {
F_32 ( L_156 ) ;
if ( V_794 -> V_801 )
V_794 -> V_801 -> V_669 -> V_803 ( V_794 -> V_801 ) ;
F_158 ( & V_11 -> V_272 ) ;
return false ;
}
F_33 ( V_2 , V_79 -> V_77 ) ;
return true ;
}
void F_484 ( struct V_415 * V_416 ,
struct V_793 * V_794 )
{
struct V_48 * V_48 =
F_480 ( V_416 ) ;
struct V_421 * V_49 = & V_48 -> V_114 ;
struct V_10 * V_11 = V_49 -> V_11 ;
F_32 ( L_151 ,
V_416 -> V_114 . V_194 , F_282 ( V_416 ) ,
V_49 -> V_114 . V_194 , F_426 ( V_49 ) ) ;
if ( V_794 -> V_797 ) {
F_481 ( V_416 ) -> V_800 = NULL ;
V_48 -> V_799 = NULL ;
F_483 ( V_11 , NULL , 0 , 0 , NULL ) ;
if ( V_794 -> V_801 ) {
F_485 ( V_794 -> V_801 ) ;
F_486 ( V_794 -> V_801 ) ;
}
F_158 ( & V_11 -> V_272 ) ;
return;
}
if ( V_794 -> V_796 != V_422 )
V_416 -> V_669 -> V_419 ( V_416 , V_794 -> V_796 ) ;
F_158 ( & V_11 -> V_272 ) ;
}
static void F_487 ( struct V_79 * V_11 ,
struct V_399 * V_400 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_77 = V_400 -> V_81 ;
T_1 V_46 = F_4 ( F_48 ( V_77 ) ) ;
T_1 V_483 ;
T_3 clock ;
if ( ( V_46 & V_804 ) == 0 )
V_483 = F_4 ( F_314 ( V_77 ) ) ;
else
V_483 = F_4 ( F_315 ( V_77 ) ) ;
clock . V_47 = ( V_483 & V_805 ) >> V_806 ;
if ( F_13 ( V_2 ) ) {
clock . V_44 = F_488 ( ( V_483 & V_807 ) >> V_808 ) - 1 ;
clock . V_39 = ( V_483 & V_809 ) >> V_810 ;
} else {
clock . V_44 = ( V_483 & V_811 ) >> V_808 ;
clock . V_39 = ( V_483 & V_812 ) >> V_810 ;
}
if ( ! F_15 ( V_2 ) ) {
if ( F_13 ( V_2 ) )
clock . V_41 = F_488 ( ( V_46 & V_813 ) >>
V_518 ) ;
else
clock . V_41 = F_488 ( ( V_46 & V_814 ) >>
V_519 ) ;
switch ( V_46 & V_815 ) {
case V_515 :
clock . V_42 = V_46 & V_521 ?
5 : 10 ;
break;
case V_514 :
clock . V_42 = V_46 & V_522 ?
7 : 14 ;
break;
default:
F_32 ( L_157
L_158 , ( int ) ( V_46 & V_815 ) ) ;
V_400 -> V_426 . clock = 0 ;
return;
}
if ( F_13 ( V_2 ) )
F_16 ( 96000 , & clock ) ;
else
F_18 ( 96000 , & clock ) ;
} else {
bool V_570 = ( V_77 == 1 ) && ( F_4 ( V_136 ) & V_168 ) ;
if ( V_570 ) {
clock . V_41 = F_488 ( ( V_46 & V_816 ) >>
V_519 ) ;
clock . V_42 = 14 ;
if ( ( V_46 & V_817 ) ==
V_528 ) {
F_18 ( 66000 , & clock ) ;
} else
F_18 ( 48000 , & clock ) ;
} else {
if ( V_46 & V_530 )
clock . V_41 = 2 ;
else {
clock . V_41 = ( ( V_46 & V_818 ) >>
V_519 ) + 2 ;
}
if ( V_46 & V_531 )
clock . V_42 = 4 ;
else
clock . V_42 = 2 ;
F_18 ( 48000 , & clock ) ;
}
}
V_400 -> V_426 . clock = clock . V_45 ;
}
static void F_489 ( struct V_79 * V_11 ,
struct V_399 * V_400 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_76 V_81 = V_400 -> V_81 ;
int V_819 , V_820 ;
T_8 clock ;
T_1 V_474 , V_475 ;
V_820 = V_400 -> V_432 ;
if ( V_400 -> V_302 )
V_819 = F_5 ( V_2 ) * 10000 ;
else
V_819 = V_400 -> V_505 ;
V_474 = F_4 ( F_328 ( V_81 ) ) ;
V_475 = F_4 ( F_329 ( V_81 ) ) ;
if ( ! V_474 || ! V_475 )
return;
clock = ( ( T_8 ) V_474 * ( T_8 ) V_819 * ( T_8 ) V_820 ) ;
F_490 ( clock , V_475 ) ;
V_400 -> V_426 . clock = clock ;
}
struct V_425 * F_491 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
enum V_76 V_81 = V_79 -> V_80 . V_81 ;
struct V_425 * V_288 ;
struct V_399 V_400 ;
int V_821 = F_4 ( F_204 ( V_81 ) ) ;
int V_822 = F_4 ( F_208 ( V_81 ) ) ;
int V_823 = F_4 ( F_210 ( V_81 ) ) ;
int V_824 = F_4 ( F_214 ( V_81 ) ) ;
V_288 = F_468 ( sizeof( * V_288 ) , V_788 ) ;
if ( ! V_288 )
return NULL ;
V_400 . V_81 = (enum V_76 ) V_79 -> V_77 ;
V_400 . V_432 = 1 ;
F_487 ( V_79 , & V_400 ) ;
V_288 -> clock = V_400 . V_426 . clock ;
V_288 -> V_289 = ( V_821 & 0xffff ) + 1 ;
V_288 -> V_549 = ( ( V_821 & 0xffff0000 ) >> 16 ) + 1 ;
V_288 -> V_440 = ( V_822 & 0xffff ) + 1 ;
V_288 -> V_550 = ( ( V_822 & 0xffff0000 ) >> 16 ) + 1 ;
V_288 -> V_290 = ( V_823 & 0xffff ) + 1 ;
V_288 -> V_551 = ( ( V_823 & 0xffff0000 ) >> 16 ) + 1 ;
V_288 -> V_552 = ( V_824 & 0xffff ) + 1 ;
V_288 -> V_553 = ( ( V_824 & 0xffff0000 ) >> 16 ) + 1 ;
F_492 ( V_288 ) ;
return V_288 ;
}
static void F_152 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_9 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
int V_77 = V_79 -> V_77 ;
int V_825 = F_48 ( V_77 ) ;
int V_46 ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_573 )
return;
V_46 = F_4 ( V_825 ) ;
if ( ! F_351 ( V_2 ) && ( V_46 & V_804 ) ) {
F_52 ( L_159 ) ;
F_61 ( V_4 , V_77 ) ;
V_46 &= ~ V_804 ;
F_36 ( V_825 , V_46 ) ;
F_33 ( V_2 , V_77 ) ;
V_46 = F_4 ( V_825 ) ;
if ( V_46 & V_804 )
F_52 ( L_160 ) ;
}
}
static void F_493 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_9 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_573 )
return;
if ( ! F_351 ( V_2 ) && V_79 -> V_486 ) {
int V_77 = V_79 -> V_77 ;
int V_825 = F_48 ( V_77 ) ;
int V_46 ;
F_52 ( L_161 ) ;
F_61 ( V_4 , V_77 ) ;
V_46 = F_4 ( V_825 ) ;
V_46 |= V_804 ;
F_36 ( V_825 , V_46 ) ;
F_33 ( V_2 , V_77 ) ;
V_46 = F_4 ( V_825 ) ;
if ( ! ( V_46 & V_804 ) )
F_52 ( L_162 ) ;
}
}
void F_494 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_415 ( V_4 ) ;
F_495 ( V_4 ) ;
}
void F_496 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_11 ;
F_414 ( V_4 ) ;
if ( ! V_487 )
return;
F_154 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_11 -> V_237 )
continue;
F_493 ( V_11 ) ;
}
}
void F_497 ( struct V_214 * V_215 ,
struct V_216 * V_826 )
{
struct V_1 * V_2 = V_215 -> V_114 . V_2 ;
struct V_10 * V_11 ;
if ( ! V_487 )
return;
F_154 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_11 -> V_237 )
continue;
if ( F_142 ( V_11 -> V_237 ) -> V_215 != V_215 )
continue;
F_152 ( V_11 ) ;
if ( V_826 && F_498 ( V_2 ) )
V_826 -> V_827 = true ;
}
}
static void F_499 ( struct V_10 * V_11 )
{
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_828 * V_829 ;
unsigned long V_332 ;
F_190 ( & V_2 -> V_336 , V_332 ) ;
V_829 = V_79 -> V_337 ;
V_79 -> V_337 = NULL ;
F_191 ( & V_2 -> V_336 , V_332 ) ;
if ( V_829 ) {
F_500 ( & V_829 -> V_829 ) ;
F_279 ( V_829 ) ;
}
F_455 ( V_11 , NULL , 0 , 0 , 0 ) ;
F_501 ( V_11 ) ;
F_279 ( V_79 ) ;
}
static void F_502 ( struct V_673 * V_674 )
{
struct V_828 * V_829 =
F_398 ( V_674 , struct V_828 , V_829 ) ;
struct V_1 * V_2 = V_829 -> V_11 -> V_2 ;
F_157 ( & V_2 -> V_286 ) ;
F_138 ( V_829 -> V_830 ) ;
F_461 ( & V_829 -> V_831 -> V_114 ) ;
F_461 ( & V_829 -> V_830 -> V_114 ) ;
F_167 ( V_2 ) ;
F_158 ( & V_2 -> V_286 ) ;
F_95 ( F_189 ( & F_27 ( V_829 -> V_11 ) -> V_832 ) == 0 ) ;
F_503 ( & F_27 ( V_829 -> V_11 ) -> V_832 ) ;
F_279 ( V_829 ) ;
}
static void F_504 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
T_9 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_828 * V_829 ;
unsigned long V_332 ;
if ( V_79 == NULL )
return;
F_190 ( & V_2 -> V_336 , V_332 ) ;
V_829 = V_79 -> V_337 ;
F_505 () ;
if ( V_829 == NULL || F_189 ( & V_829 -> V_333 ) < V_833 ) {
F_191 ( & V_2 -> V_336 , V_332 ) ;
return;
}
F_505 () ;
V_79 -> V_337 = NULL ;
if ( V_829 -> V_834 )
F_506 ( V_2 , V_79 -> V_77 , V_829 -> V_834 ) ;
F_507 ( V_2 , V_79 -> V_77 ) ;
F_191 ( & V_2 -> V_336 , V_332 ) ;
F_508 ( & V_4 -> V_338 ) ;
F_509 ( V_4 -> V_835 , & V_829 -> V_829 ) ;
F_510 ( V_79 -> V_144 , V_829 -> V_831 ) ;
}
void F_511 ( struct V_1 * V_2 , int V_77 )
{
T_9 * V_4 = V_2 -> V_5 ;
struct V_10 * V_11 = V_4 -> V_78 [ V_77 ] ;
F_504 ( V_2 , V_11 ) ;
}
void F_156 ( struct V_1 * V_2 , int V_144 )
{
T_9 * V_4 = V_2 -> V_5 ;
struct V_10 * V_11 = V_4 -> V_836 [ V_144 ] ;
F_504 ( V_2 , V_11 ) ;
}
void F_155 ( struct V_1 * V_2 , int V_144 )
{
T_9 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 =
F_27 ( V_4 -> V_836 [ V_144 ] ) ;
unsigned long V_332 ;
F_190 ( & V_2 -> V_336 , V_332 ) ;
if ( V_79 -> V_337 )
F_512 ( & V_79 -> V_337 -> V_333 ) ;
F_191 ( & V_2 -> V_336 , V_332 ) ;
}
inline static void F_513 ( struct V_79 * V_79 )
{
F_514 () ;
F_515 ( & V_79 -> V_337 -> V_333 , V_837 ) ;
F_514 () ;
}
static int F_516 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_236 * V_237 ,
struct V_214 * V_215 ,
T_4 V_332 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
T_1 V_838 ;
struct V_216 * V_826 = & V_4 -> V_826 [ V_839 ] ;
int V_219 ;
V_219 = F_130 ( V_2 , V_215 , V_826 ) ;
if ( V_219 )
goto V_55;
V_219 = F_517 ( V_826 , 6 ) ;
if ( V_219 )
goto V_228;
if ( V_79 -> V_144 )
V_838 = V_840 ;
else
V_838 = V_841 ;
F_518 ( V_826 , V_842 | V_838 ) ;
F_518 ( V_826 , V_843 ) ;
F_518 ( V_826 , V_844 |
F_519 ( V_79 -> V_144 ) ) ;
F_518 ( V_826 , V_237 -> V_265 [ 0 ] ) ;
F_518 ( V_826 , F_143 ( V_215 ) + V_79 -> V_267 ) ;
F_518 ( V_826 , 0 ) ;
F_513 ( V_79 ) ;
F_520 ( V_826 ) ;
return 0 ;
V_228:
F_138 ( V_215 ) ;
V_55:
return V_219 ;
}
static int F_521 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_236 * V_237 ,
struct V_214 * V_215 ,
T_4 V_332 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
T_1 V_838 ;
struct V_216 * V_826 = & V_4 -> V_826 [ V_839 ] ;
int V_219 ;
V_219 = F_130 ( V_2 , V_215 , V_826 ) ;
if ( V_219 )
goto V_55;
V_219 = F_517 ( V_826 , 6 ) ;
if ( V_219 )
goto V_228;
if ( V_79 -> V_144 )
V_838 = V_840 ;
else
V_838 = V_841 ;
F_518 ( V_826 , V_842 | V_838 ) ;
F_518 ( V_826 , V_843 ) ;
F_518 ( V_826 , V_845 |
F_519 ( V_79 -> V_144 ) ) ;
F_518 ( V_826 , V_237 -> V_265 [ 0 ] ) ;
F_518 ( V_826 , F_143 ( V_215 ) + V_79 -> V_267 ) ;
F_518 ( V_826 , V_843 ) ;
F_513 ( V_79 ) ;
F_520 ( V_826 ) ;
return 0 ;
V_228:
F_138 ( V_215 ) ;
V_55:
return V_219 ;
}
static int F_522 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_236 * V_237 ,
struct V_214 * V_215 ,
T_4 V_332 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
T_4 V_846 , V_847 ;
struct V_216 * V_826 = & V_4 -> V_826 [ V_839 ] ;
int V_219 ;
V_219 = F_130 ( V_2 , V_215 , V_826 ) ;
if ( V_219 )
goto V_55;
V_219 = F_517 ( V_826 , 4 ) ;
if ( V_219 )
goto V_228;
F_518 ( V_826 , V_844 |
F_519 ( V_79 -> V_144 ) ) ;
F_518 ( V_826 , V_237 -> V_265 [ 0 ] ) ;
F_518 ( V_826 ,
( F_143 ( V_215 ) + V_79 -> V_267 ) |
V_215 -> V_220 ) ;
V_846 = 0 ;
V_847 = F_4 ( F_163 ( V_79 -> V_77 ) ) & 0x0fff0fff ;
F_518 ( V_826 , V_846 | V_847 ) ;
F_513 ( V_79 ) ;
F_520 ( V_826 ) ;
return 0 ;
V_228:
F_138 ( V_215 ) ;
V_55:
return V_219 ;
}
static int F_523 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_236 * V_237 ,
struct V_214 * V_215 ,
T_4 V_332 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_216 * V_826 = & V_4 -> V_826 [ V_839 ] ;
T_4 V_846 , V_847 ;
int V_219 ;
V_219 = F_130 ( V_2 , V_215 , V_826 ) ;
if ( V_219 )
goto V_55;
V_219 = F_517 ( V_826 , 4 ) ;
if ( V_219 )
goto V_228;
F_518 ( V_826 , V_844 |
F_519 ( V_79 -> V_144 ) ) ;
F_518 ( V_826 , V_237 -> V_265 [ 0 ] | V_215 -> V_220 ) ;
F_518 ( V_826 , F_143 ( V_215 ) + V_79 -> V_267 ) ;
V_846 = 0 ;
V_847 = F_4 ( F_163 ( V_79 -> V_77 ) ) & 0x0fff0fff ;
F_518 ( V_826 , V_846 | V_847 ) ;
F_513 ( V_79 ) ;
F_520 ( V_826 ) ;
return 0 ;
V_228:
F_138 ( V_215 ) ;
V_55:
return V_219 ;
}
static int F_524 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_236 * V_237 ,
struct V_214 * V_215 ,
T_4 V_332 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_216 * V_826 ;
T_4 V_848 = 0 ;
int V_708 , V_219 ;
V_826 = V_215 -> V_826 ;
if ( F_14 ( V_2 ) || V_826 == NULL || V_826 -> V_194 != V_839 )
V_826 = & V_4 -> V_826 [ V_849 ] ;
V_219 = F_130 ( V_2 , V_215 , V_826 ) ;
if ( V_219 )
goto V_55;
switch( V_79 -> V_144 ) {
case V_850 :
V_848 = V_851 ;
break;
case V_852 :
V_848 = V_853 ;
break;
case V_854 :
V_848 = V_855 ;
break;
default:
F_525 ( 1 , L_163 ) ;
V_219 = - V_856 ;
goto V_228;
}
V_708 = 4 ;
if ( V_826 -> V_194 == V_839 )
V_708 += 6 ;
V_219 = F_517 ( V_826 , V_708 ) ;
if ( V_219 )
goto V_228;
if ( V_826 -> V_194 == V_839 ) {
F_518 ( V_826 , F_526 ( 1 ) ) ;
F_518 ( V_826 , V_857 ) ;
F_518 ( V_826 , ~ ( V_858 |
V_859 |
V_860 ) ) ;
F_518 ( V_826 , F_527 ( 1 ) ) ;
F_518 ( V_826 , V_857 ) ;
F_518 ( V_826 , V_826 -> V_861 . V_862 + 256 ) ;
}
F_518 ( V_826 , V_845 | V_848 ) ;
F_518 ( V_826 , ( V_237 -> V_265 [ 0 ] | V_215 -> V_220 ) ) ;
F_518 ( V_826 , F_143 ( V_215 ) + V_79 -> V_267 ) ;
F_518 ( V_826 , ( V_843 ) ) ;
F_513 ( V_79 ) ;
F_520 ( V_826 ) ;
return 0 ;
V_228:
F_138 ( V_215 ) ;
V_55:
return V_219 ;
}
static int F_528 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_236 * V_237 ,
struct V_214 * V_215 ,
T_4 V_332 )
{
return - V_856 ;
}
static int F_529 ( struct V_10 * V_11 ,
struct V_236 * V_237 ,
struct V_863 * V_834 ,
T_4 V_864 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_236 * V_273 = V_11 -> V_237 ;
struct V_214 * V_215 = F_142 ( V_237 ) -> V_215 ;
struct V_79 * V_79 = F_27 ( V_11 ) ;
struct V_828 * V_829 ;
unsigned long V_332 ;
int V_219 ;
if ( V_237 -> V_243 != V_11 -> V_237 -> V_243 )
return - V_224 ;
if ( F_35 ( V_2 ) -> V_85 > 3 &&
( V_237 -> V_865 [ 0 ] != V_11 -> V_237 -> V_865 [ 0 ] ||
V_237 -> V_265 [ 0 ] != V_11 -> V_237 -> V_265 [ 0 ] ) )
return - V_224 ;
V_829 = F_468 ( sizeof *V_829 , V_788 ) ;
if ( V_829 == NULL )
return - V_768 ;
V_829 -> V_834 = V_834 ;
V_829 -> V_11 = V_11 ;
V_829 -> V_830 = F_142 ( V_273 ) -> V_215 ;
F_530 ( & V_829 -> V_829 , F_502 ) ;
V_219 = F_531 ( V_2 , V_79 -> V_77 ) ;
if ( V_219 )
goto V_866;
F_190 ( & V_2 -> V_336 , V_332 ) ;
if ( V_79 -> V_337 ) {
F_191 ( & V_2 -> V_336 , V_332 ) ;
F_279 ( V_829 ) ;
F_507 ( V_2 , V_79 -> V_77 ) ;
F_52 ( L_164 ) ;
return - V_867 ;
}
V_79 -> V_337 = V_829 ;
F_191 ( & V_2 -> V_336 , V_332 ) ;
if ( F_189 ( & V_79 -> V_832 ) >= 2 )
F_532 ( V_4 -> V_835 ) ;
V_219 = F_533 ( V_2 ) ;
if ( V_219 )
goto V_868;
F_534 ( & V_829 -> V_830 -> V_114 ) ;
F_534 ( & V_215 -> V_114 ) ;
V_11 -> V_237 = V_237 ;
V_829 -> V_831 = V_215 ;
V_829 -> V_869 = true ;
F_535 ( & V_79 -> V_832 ) ;
V_79 -> V_335 = F_189 ( & V_4 -> V_334 . V_335 ) ;
V_219 = V_4 -> V_269 . V_870 ( V_2 , V_11 , V_237 , V_215 , V_864 ) ;
if ( V_219 )
goto V_871;
F_252 ( V_2 ) ;
F_497 ( V_215 , NULL ) ;
F_158 ( & V_2 -> V_286 ) ;
F_536 ( V_79 -> V_144 , V_215 ) ;
return 0 ;
V_871:
F_503 ( & V_79 -> V_832 ) ;
V_11 -> V_237 = V_273 ;
F_461 ( & V_829 -> V_830 -> V_114 ) ;
F_461 ( & V_215 -> V_114 ) ;
F_158 ( & V_2 -> V_286 ) ;
V_868:
F_190 ( & V_2 -> V_336 , V_332 ) ;
V_79 -> V_337 = NULL ;
F_191 ( & V_2 -> V_336 , V_332 ) ;
F_507 ( V_2 , V_79 -> V_77 ) ;
V_866:
F_279 ( V_829 ) ;
return V_219 ;
}
static bool F_537 ( struct V_421 * V_49 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_10 * V_548 ;
int V_872 = 1 ;
F_39 ( ! V_11 , L_165 ) ;
V_2 = V_11 -> V_2 ;
F_154 (tmp, &dev->mode_config.crtc_list, head) {
if ( V_548 == V_11 )
break;
V_872 <<= 1 ;
}
if ( V_49 -> V_798 & V_872 )
return true ;
return false ;
}
static void F_538 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
struct V_423 * V_416 ;
F_154 (connector, &dev->mode_config.connector_list,
base.head) {
V_416 -> V_800 =
F_276 ( V_416 -> V_114 . V_49 ) ;
}
F_154 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_49 -> V_799 =
F_27 ( V_49 -> V_114 . V_11 ) ;
}
}
static void F_539 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
struct V_423 * V_416 ;
F_154 (connector, &dev->mode_config.connector_list,
base.head) {
V_416 -> V_114 . V_49 = & V_416 -> V_800 -> V_114 ;
}
F_154 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_49 -> V_114 . V_11 = & V_49 -> V_799 -> V_114 ;
}
}
static void
F_540 ( struct V_423 * V_416 ,
struct V_399 * V_400 )
{
int V_623 = V_400 -> V_433 ;
F_32 ( L_166 ,
V_416 -> V_114 . V_114 . V_194 ,
F_282 ( & V_416 -> V_114 ) ) ;
if ( V_416 -> V_114 . V_873 . V_366 &&
V_416 -> V_114 . V_873 . V_366 * 3 < V_623 ) {
F_32 ( L_167 ,
V_623 , V_416 -> V_114 . V_873 . V_366 * 3 ) ;
V_400 -> V_433 = V_416 -> V_114 . V_873 . V_366 * 3 ;
}
if ( V_416 -> V_114 . V_873 . V_366 == 0 && V_623 > 24 ) {
F_32 ( L_168 ,
V_623 ) ;
V_400 -> V_433 = 24 ;
}
}
static int
F_541 ( struct V_79 * V_11 ,
struct V_236 * V_237 ,
struct V_399 * V_400 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_423 * V_416 ;
int V_623 ;
switch ( V_237 -> V_243 ) {
case V_244 :
V_623 = 8 * 3 ;
break;
case V_246 :
case V_247 :
if ( F_2 ( F_35 ( V_2 ) -> V_85 > 3 ) )
return - V_224 ;
case V_249 :
V_623 = 6 * 3 ;
break;
case V_254 :
case V_255 :
if ( F_2 ( F_35 ( V_2 ) -> V_85 < 4 ) )
return - V_224 ;
case V_251 :
case V_252 :
V_623 = 8 * 3 ;
break;
case V_257 :
case V_258 :
case V_260 :
case V_261 :
if ( F_2 ( F_35 ( V_2 ) -> V_85 < 4 ) )
return - V_224 ;
V_623 = 10 * 3 ;
break;
default:
F_32 ( L_169 ) ;
return - V_224 ;
}
V_400 -> V_433 = V_623 ;
F_154 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_416 -> V_800 ||
V_416 -> V_800 -> V_799 != V_11 )
continue;
F_540 ( V_416 , V_400 ) ;
}
return V_623 ;
}
static void F_542 ( struct V_79 * V_11 ,
struct V_399 * V_400 ,
const char * V_874 )
{
F_32 ( L_170 , V_11 -> V_114 . V_114 . V_194 ,
V_874 , F_62 ( V_11 -> V_77 ) ) ;
F_32 ( L_171 , F_543 ( V_400 -> V_81 ) ) ;
F_32 ( L_172 ,
V_400 -> V_433 , V_400 -> V_557 ) ;
F_32 ( L_173 ,
V_400 -> V_302 ,
V_400 -> V_312 ,
V_400 -> V_434 . V_472 , V_400 -> V_434 . V_473 ,
V_400 -> V_434 . V_474 , V_400 -> V_434 . V_475 ,
V_400 -> V_434 . V_471 ) ;
F_32 ( L_174 ) ;
F_544 ( & V_400 -> V_438 ) ;
F_32 ( L_175 ) ;
F_544 ( & V_400 -> V_426 ) ;
F_32 ( L_176 ,
V_400 -> V_401 . V_402 ,
V_400 -> V_401 . V_406 ,
V_400 -> V_401 . V_579 ) ;
F_32 ( L_177 ,
V_400 -> V_291 . V_382 ,
V_400 -> V_291 . V_383 ,
V_400 -> V_291 . V_108 ? L_178 : L_179 ) ;
F_32 ( L_180 , V_400 -> V_386 ) ;
}
static bool F_545 ( struct V_10 * V_11 )
{
int V_875 = 0 ;
bool V_876 = false ;
struct V_48 * V_49 ;
F_154 (encoder, &crtc->dev->mode_config.encoder_list,
base.head) {
if ( & V_49 -> V_799 -> V_114 != V_11 )
continue;
V_875 ++ ;
if ( ! V_49 -> V_877 )
V_876 = true ;
}
return ! ( V_875 > 1 && V_876 ) ;
}
static struct V_399 *
F_546 ( struct V_10 * V_11 ,
struct V_236 * V_237 ,
struct V_425 * V_288 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_48 * V_49 ;
struct V_399 * V_400 ;
int V_878 , V_219 = - V_224 ;
bool V_317 = true ;
if ( ! F_545 ( V_11 ) ) {
F_32 ( L_181 ) ;
return F_469 ( - V_224 ) ;
}
V_400 = F_468 ( sizeof( * V_400 ) , V_788 ) ;
if ( ! V_400 )
return F_469 ( - V_768 ) ;
F_547 ( & V_400 -> V_426 , V_288 ) ;
F_547 ( & V_400 -> V_438 , V_288 ) ;
V_400 -> V_81 =
(enum V_76 ) F_27 ( V_11 ) -> V_77 ;
V_400 -> V_115 = V_375 ;
if ( ! ( V_400 -> V_426 . V_332 &
( V_371 | V_879 ) ) )
V_400 -> V_426 . V_332 |= V_879 ;
if ( ! ( V_400 -> V_426 . V_332 &
( V_373 | V_880 ) ) )
V_400 -> V_426 . V_332 |= V_880 ;
V_878 = F_541 ( F_27 ( V_11 ) ,
V_237 , V_400 ) ;
if ( V_878 < 0 )
goto V_769;
V_881:
V_400 -> V_505 = 0 ;
V_400 -> V_432 = 1 ;
F_548 ( & V_400 -> V_426 , 0 ) ;
F_154 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( & V_49 -> V_799 -> V_114 != V_11 )
continue;
if ( ! ( V_49 -> V_882 ( V_49 , V_400 ) ) ) {
F_32 ( L_182 ) ;
goto V_769;
}
}
if ( ! V_400 -> V_505 )
V_400 -> V_505 = V_400 -> V_426 . clock ;
V_219 = F_293 ( F_27 ( V_11 ) , V_400 ) ;
if ( V_219 < 0 ) {
F_32 ( L_183 ) ;
goto V_769;
}
if ( V_219 == V_436 ) {
if ( F_39 ( ! V_317 , L_184 ) ) {
V_219 = - V_224 ;
goto V_769;
}
F_32 ( L_185 ) ;
V_317 = false ;
goto V_881;
}
V_400 -> V_557 = V_400 -> V_433 != V_878 ;
F_32 ( L_186 ,
V_878 , V_400 -> V_433 , V_400 -> V_557 ) ;
return V_400 ;
V_769:
F_279 ( V_400 ) ;
return F_469 ( V_219 ) ;
}
static void
F_549 ( struct V_10 * V_11 , unsigned * V_883 ,
unsigned * V_884 , unsigned * V_885 )
{
struct V_79 * V_79 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_48 * V_49 ;
struct V_423 * V_416 ;
struct V_10 * V_886 ;
* V_885 = * V_883 = * V_884 = 0 ;
F_154 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_416 -> V_114 . V_49 == & V_416 -> V_800 -> V_114 )
continue;
if ( V_416 -> V_114 . V_49 ) {
V_886 = V_416 -> V_114 . V_49 -> V_11 ;
* V_884 |= 1 << F_27 ( V_886 ) -> V_77 ;
}
if ( V_416 -> V_800 )
* V_884 |=
1 << V_416 -> V_800 -> V_799 -> V_77 ;
}
F_154 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_49 -> V_114 . V_11 == & V_49 -> V_799 -> V_114 )
continue;
if ( V_49 -> V_114 . V_11 ) {
V_886 = V_49 -> V_114 . V_11 ;
* V_884 |= 1 << F_27 ( V_886 ) -> V_77 ;
}
if ( V_49 -> V_799 )
* V_884 |= 1 << V_49 -> V_799 -> V_77 ;
}
F_154 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
bool V_887 = false ;
if ( ! V_79 -> V_114 . V_108 )
continue;
F_154 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_49 -> V_799 == V_79 )
V_887 = true ;
}
if ( ! V_887 )
* V_885 |= 1 << V_79 -> V_77 ;
}
V_79 = F_27 ( V_11 ) ;
if ( V_11 -> V_108 )
* V_884 |= 1 << V_79 -> V_77 ;
if ( * V_884 )
* V_883 = * V_884 ;
* V_883 &= ~ ( * V_885 ) ;
* V_884 &= ~ ( * V_885 ) ;
* V_883 &= 1 << V_79 -> V_77 ;
* V_884 &= 1 << V_79 -> V_77 ;
F_32 ( L_187 ,
* V_883 , * V_884 , * V_885 ) ;
}
static bool F_550 ( struct V_10 * V_11 )
{
struct V_421 * V_49 ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_154 (encoder, &dev->mode_config.encoder_list, head)
if ( V_49 -> V_11 == V_11 )
return true ;
return false ;
}
static void
F_551 ( struct V_1 * V_2 , unsigned V_884 )
{
struct V_48 * V_48 ;
struct V_79 * V_79 ;
struct V_415 * V_416 ;
F_154 (intel_encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_48 -> V_114 . V_11 )
continue;
V_79 = F_27 ( V_48 -> V_114 . V_11 ) ;
if ( V_884 & ( 1 << V_79 -> V_77 ) )
V_48 -> V_412 = false ;
}
F_539 ( V_2 ) ;
F_154 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
V_79 -> V_114 . V_108 = F_550 ( & V_79 -> V_114 ) ;
}
F_154 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_416 -> V_49 || ! V_416 -> V_49 -> V_11 )
continue;
V_79 = F_27 ( V_416 -> V_49 -> V_11 ) ;
if ( V_884 & ( 1 << V_79 -> V_77 ) ) {
struct V_888 * V_889 =
V_2 -> V_584 . V_889 ;
V_416 -> V_419 = V_422 ;
F_552 ( & V_416 -> V_114 ,
V_889 ,
V_422 ) ;
V_48 = F_276 ( V_416 -> V_49 ) ;
V_48 -> V_412 = true ;
}
}
}
static bool F_553 ( struct V_399 * V_890 ,
struct V_399 * V_891 )
{
int V_892 , V_893 , V_894 ;
V_892 = V_890 -> V_426 . clock ;
V_893 = V_891 -> V_426 . clock ;
if ( V_892 == V_893 )
return true ;
if ( ! V_892 || ! V_893 )
return false ;
V_894 = abs ( V_892 - V_893 ) ;
if ( ( ( ( ( V_894 + V_892 + V_893 ) * 100 ) ) / ( V_892 + V_893 ) ) < 105 )
return true ;
return false ;
}
static bool
F_554 ( struct V_1 * V_2 ,
struct V_399 * V_895 ,
struct V_399 * V_400 )
{
#define F_555 ( V_121 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_556 ( V_121 ) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define F_557 ( V_121 , T_10 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
DRM_ERROR("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
return false; \
}
#define F_558 ( T_11 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_556 ( V_81 ) ;
F_556 ( V_302 ) ;
F_556 ( V_312 ) ;
F_556 ( V_434 . V_472 ) ;
F_556 ( V_434 . V_473 ) ;
F_556 ( V_434 . V_474 ) ;
F_556 ( V_434 . V_475 ) ;
F_556 ( V_434 . V_471 ) ;
F_556 ( V_426 . V_539 ) ;
F_556 ( V_426 . V_538 ) ;
F_556 ( V_426 . V_540 ) ;
F_556 ( V_426 . V_541 ) ;
F_556 ( V_426 . V_537 ) ;
F_556 ( V_426 . V_542 ) ;
F_556 ( V_426 . V_543 ) ;
F_556 ( V_426 . V_534 ) ;
F_556 ( V_426 . V_544 ) ;
F_556 ( V_426 . V_535 ) ;
F_556 ( V_426 . V_545 ) ;
F_556 ( V_426 . V_546 ) ;
F_556 ( V_432 ) ;
F_557 ( V_426 . V_332 ,
V_536 ) ;
if ( ! F_558 ( V_896 ) ) {
F_557 ( V_426 . V_332 ,
V_371 ) ;
F_557 ( V_426 . V_332 ,
V_879 ) ;
F_557 ( V_426 . V_332 ,
V_373 ) ;
F_557 ( V_426 . V_332 ,
V_880 ) ;
}
F_556 ( V_438 . V_289 ) ;
F_556 ( V_438 . V_290 ) ;
F_556 ( V_401 . V_402 ) ;
if ( F_35 ( V_2 ) -> V_85 < 4 )
F_556 ( V_401 . V_406 ) ;
F_556 ( V_401 . V_579 ) ;
F_556 ( V_291 . V_108 ) ;
if ( V_895 -> V_291 . V_108 ) {
F_556 ( V_291 . V_382 ) ;
F_556 ( V_291 . V_383 ) ;
}
F_556 ( V_386 ) ;
F_556 ( V_115 ) ;
F_555 ( V_185 . V_46 ) ;
F_555 ( V_185 . V_187 ) ;
F_555 ( V_185 . V_485 ) ;
F_555 ( V_185 . V_488 ) ;
if ( F_12 ( V_2 ) || F_35 ( V_2 ) -> V_85 >= 5 )
F_556 ( V_433 ) ;
#undef F_555
#undef F_556
#undef F_557
#undef F_558
if ( ! F_149 ( V_2 ) ) {
if ( ! F_553 ( V_895 , V_400 ) ) {
F_100 ( L_188 ,
V_895 -> V_426 . clock ,
V_400 -> V_426 . clock ) ;
return false ;
}
}
return true ;
}
static void
F_559 ( struct V_1 * V_2 )
{
struct V_423 * V_416 ;
F_154 (connector, &dev->mode_config.connector_list,
base.head) {
F_281 ( V_416 ) ;
F_39 ( & V_416 -> V_800 -> V_114 != V_416 -> V_114 . V_49 ,
L_189 ) ;
}
}
static void
F_560 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
struct V_423 * V_416 ;
F_154 (encoder, &dev->mode_config.encoder_list,
base.head) {
bool V_108 = false ;
bool V_192 = false ;
enum V_77 V_77 , V_897 ;
F_32 ( L_190 ,
V_49 -> V_114 . V_114 . V_194 ,
F_426 ( & V_49 -> V_114 ) ) ;
F_39 ( & V_49 -> V_799 -> V_114 != V_49 -> V_114 . V_11 ,
L_191 ) ;
F_39 ( V_49 -> V_412 && ! V_49 -> V_114 . V_11 ,
L_192 ) ;
F_154 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_416 -> V_114 . V_49 != & V_49 -> V_114 )
continue;
V_108 = true ;
if ( V_416 -> V_114 . V_419 != V_420 )
V_192 = true ;
}
F_39 ( ! ! V_49 -> V_114 . V_11 != V_108 ,
L_193
L_194 ,
! ! V_49 -> V_114 . V_11 , V_108 ) ;
F_39 ( V_192 && ! V_49 -> V_114 . V_11 ,
L_195 ) ;
F_39 ( V_49 -> V_412 != V_192 ,
L_196
L_194 , V_192 , V_49 -> V_412 ) ;
V_192 = V_49 -> V_120 ( V_49 , & V_77 ) ;
F_39 ( V_192 != V_49 -> V_412 ,
L_197
L_194 ,
V_49 -> V_412 , V_192 ) ;
if ( ! V_49 -> V_114 . V_11 )
continue;
V_897 = F_27 ( V_49 -> V_114 . V_11 ) -> V_77 ;
F_39 ( V_192 && V_77 != V_897 ,
L_198
L_194 ,
V_897 , V_77 ) ;
}
}
static void
F_561 ( struct V_1 * V_2 )
{
T_9 * V_4 = V_2 -> V_5 ;
struct V_79 * V_11 ;
struct V_48 * V_49 ;
struct V_399 V_400 ;
F_154 (crtc, &dev->mode_config.crtc_list,
base.head) {
bool V_108 = false ;
bool V_192 = false ;
memset ( & V_400 , 0 , sizeof( V_400 ) ) ;
F_32 ( L_199 ,
V_11 -> V_114 . V_114 . V_194 ) ;
F_39 ( V_11 -> V_192 && ! V_11 -> V_114 . V_108 ,
L_200 ) ;
F_154 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_49 -> V_114 . V_11 != & V_11 -> V_114 )
continue;
V_108 = true ;
if ( V_49 -> V_412 )
V_192 = true ;
}
F_39 ( V_192 != V_11 -> V_192 ,
L_201
L_194 , V_192 , V_11 -> V_192 ) ;
F_39 ( V_108 != V_11 -> V_114 . V_108 ,
L_202
L_194 , V_108 , V_11 -> V_114 . V_108 ) ;
V_192 = V_4 -> V_269 . V_898 ( V_11 ,
& V_400 ) ;
if ( V_11 -> V_77 == V_131 && V_4 -> V_141 & V_142 )
V_192 = V_11 -> V_192 ;
F_154 (encoder, &dev->mode_config.encoder_list,
base.head) {
enum V_77 V_77 ;
if ( V_49 -> V_114 . V_11 != & V_11 -> V_114 )
continue;
if ( V_49 -> V_899 &&
V_49 -> V_120 ( V_49 , & V_77 ) )
V_49 -> V_899 ( V_49 , & V_400 ) ;
}
if ( V_4 -> V_269 . V_900 )
V_4 -> V_269 . V_900 ( V_11 , & V_400 ) ;
F_39 ( V_11 -> V_192 != V_192 ,
L_203
L_194 , V_11 -> V_192 , V_192 ) ;
if ( V_192 &&
! F_554 ( V_2 , & V_11 -> V_80 , & V_400 ) ) {
F_39 ( 1 , L_204 ) ;
F_542 ( V_11 , & V_400 ,
L_205 ) ;
F_542 ( V_11 , & V_11 -> V_80 ,
L_206 ) ;
}
}
}
static void
F_562 ( struct V_1 * V_2 )
{
T_9 * V_4 = V_2 -> V_5 ;
struct V_79 * V_11 ;
struct V_118 V_185 ;
int V_146 ;
for ( V_146 = 0 ; V_146 < V_4 -> V_377 ; V_146 ++ ) {
struct V_113 * V_117 = & V_4 -> V_116 [ V_146 ] ;
int V_901 = 0 , V_902 = 0 ;
bool V_192 ;
memset ( & V_185 , 0 , sizeof( V_185 ) ) ;
F_32 ( L_207 , V_117 -> V_121 ) ;
V_192 = V_117 -> V_120 ( V_4 , V_117 , & V_185 ) ;
F_39 ( V_117 -> V_192 > V_117 -> V_191 ,
L_208 ,
V_117 -> V_192 , V_117 -> V_191 ) ;
F_39 ( V_117 -> V_192 && ! V_117 -> V_193 ,
L_209 ) ;
F_39 ( V_117 -> V_193 && ! V_117 -> V_192 ,
L_210 ) ;
F_39 ( V_117 -> V_193 != V_192 ,
L_211 ,
V_117 -> V_193 , V_192 ) ;
F_154 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_11 -> V_114 . V_108 && F_49 ( V_11 ) == V_117 )
V_901 ++ ;
if ( V_11 -> V_192 && F_49 ( V_11 ) == V_117 )
V_902 ++ ;
}
F_39 ( V_117 -> V_192 != V_902 ,
L_212 ,
V_117 -> V_192 , V_902 ) ;
F_39 ( V_117 -> V_191 != V_901 ,
L_213 ,
V_117 -> V_191 , V_901 ) ;
F_39 ( V_117 -> V_193 && memcmp ( & V_117 -> V_119 , & V_185 ,
sizeof( V_185 ) ) ,
L_214 ) ;
}
}
void
F_284 ( struct V_1 * V_2 )
{
F_559 ( V_2 ) ;
F_560 ( V_2 ) ;
F_561 ( V_2 ) ;
F_562 ( V_2 ) ;
}
static int F_563 ( struct V_10 * V_11 ,
struct V_425 * V_288 ,
int V_229 , int V_230 , struct V_236 * V_237 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_9 * V_4 = V_2 -> V_5 ;
struct V_425 * V_903 , * V_904 ;
struct V_399 * V_400 = NULL ;
struct V_79 * V_79 ;
unsigned V_885 , V_884 , V_883 ;
int V_219 = 0 ;
V_903 = F_564 ( 2 * sizeof( * V_903 ) , V_788 ) ;
if ( ! V_903 )
return - V_768 ;
V_904 = V_903 + 1 ;
F_549 ( V_11 , & V_883 ,
& V_884 , & V_885 ) ;
* V_904 = V_11 -> V_905 ;
* V_903 = V_11 -> V_288 ;
if ( V_883 ) {
V_400 = F_546 ( V_11 , V_237 , V_288 ) ;
if ( F_482 ( V_400 ) ) {
V_219 = F_565 ( V_400 ) ;
V_400 = NULL ;
goto V_906;
}
F_542 ( F_27 ( V_11 ) , V_400 ,
L_215 ) ;
}
F_566 (dev, disable_pipes, intel_crtc)
F_274 ( & V_79 -> V_114 ) ;
F_566 (dev, prepare_pipes, intel_crtc) {
if ( V_79 -> V_114 . V_108 )
V_4 -> V_269 . V_414 ( & V_79 -> V_114 ) ;
}
if ( V_883 ) {
V_11 -> V_288 = * V_288 ;
F_27 ( V_11 ) -> V_80 = * V_400 ;
}
F_551 ( V_2 , V_884 ) ;
if ( V_4 -> V_269 . V_907 )
V_4 -> V_269 . V_907 ( V_2 ) ;
F_566 (dev, modeset_pipes, intel_crtc) {
V_219 = F_423 ( & V_79 -> V_114 ,
V_229 , V_230 , V_237 ) ;
if ( V_219 )
goto V_687;
}
F_566 (dev, prepare_pipes, intel_crtc)
V_4 -> V_269 . V_413 ( & V_79 -> V_114 ) ;
if ( V_883 ) {
V_11 -> V_905 = V_400 -> V_426 ;
F_567 ( V_11 ) ;
}
V_687:
if ( V_219 && V_11 -> V_108 ) {
V_11 -> V_905 = * V_904 ;
V_11 -> V_288 = * V_903 ;
}
V_906:
F_279 ( V_400 ) ;
F_279 ( V_903 ) ;
return V_219 ;
}
static int F_483 ( struct V_10 * V_11 ,
struct V_425 * V_288 ,
int V_229 , int V_230 , struct V_236 * V_237 )
{
int V_219 ;
V_219 = F_563 ( V_11 , V_288 , V_229 , V_230 , V_237 ) ;
if ( V_219 == 0 )
F_284 ( V_11 -> V_2 ) ;
return V_219 ;
}
void F_568 ( struct V_10 * V_11 )
{
F_483 ( V_11 , & V_11 -> V_288 , V_11 -> V_229 , V_11 -> V_230 , V_11 -> V_237 ) ;
}
static void F_569 ( struct V_908 * V_80 )
{
if ( ! V_80 )
return;
F_279 ( V_80 -> V_909 ) ;
F_279 ( V_80 -> V_910 ) ;
F_279 ( V_80 ) ;
}
static int F_570 ( struct V_1 * V_2 ,
struct V_908 * V_80 )
{
struct V_421 * V_49 ;
struct V_415 * V_416 ;
int V_911 ;
V_80 -> V_910 =
F_571 ( V_2 -> V_584 . V_912 ,
sizeof( struct V_10 * ) , V_788 ) ;
if ( ! V_80 -> V_910 )
return - V_768 ;
V_80 -> V_909 =
F_571 ( V_2 -> V_584 . V_913 ,
sizeof( struct V_421 * ) , V_788 ) ;
if ( ! V_80 -> V_909 )
return - V_768 ;
V_911 = 0 ;
F_154 (encoder, &dev->mode_config.encoder_list, head) {
V_80 -> V_910 [ V_911 ++ ] = V_49 -> V_11 ;
}
V_911 = 0 ;
F_154 (connector, &dev->mode_config.connector_list, head) {
V_80 -> V_909 [ V_911 ++ ] = V_416 -> V_49 ;
}
return 0 ;
}
static void F_572 ( struct V_1 * V_2 ,
struct V_908 * V_80 )
{
struct V_48 * V_49 ;
struct V_423 * V_416 ;
int V_911 ;
V_911 = 0 ;
F_154 (encoder, &dev->mode_config.encoder_list, base.head) {
V_49 -> V_799 =
F_27 ( V_80 -> V_910 [ V_911 ++ ] ) ;
}
V_911 = 0 ;
F_154 (connector, &dev->mode_config.connector_list, base.head) {
V_416 -> V_800 =
F_276 ( V_80 -> V_909 [ V_911 ++ ] ) ;
}
}
static bool
F_573 ( struct V_914 * V_915 )
{
int V_146 ;
if ( V_915 -> V_480 == 0 )
return false ;
if ( F_2 ( V_915 -> V_916 == NULL ) )
return false ;
for ( V_146 = 0 ; V_146 < V_915 -> V_480 ; V_146 ++ )
if ( V_915 -> V_916 [ V_146 ] -> V_49 &&
V_915 -> V_916 [ V_146 ] -> V_49 -> V_11 == V_915 -> V_11 &&
V_915 -> V_916 [ V_146 ] -> V_419 != V_422 )
return true ;
return false ;
}
static void
F_574 ( struct V_914 * V_915 ,
struct V_908 * V_80 )
{
if ( F_573 ( V_915 ) ) {
V_80 -> V_917 = true ;
} else if ( V_915 -> V_11 -> V_237 != V_915 -> V_237 ) {
if ( V_915 -> V_11 -> V_237 == NULL ) {
struct V_79 * V_79 =
F_27 ( V_915 -> V_11 ) ;
if ( V_79 -> V_192 && V_287 ) {
F_32 ( L_216 ) ;
V_80 -> V_918 = true ;
} else {
F_32 ( L_217 ) ;
V_80 -> V_917 = true ;
}
} else if ( V_915 -> V_237 == NULL ) {
V_80 -> V_917 = true ;
} else if ( V_915 -> V_237 -> V_243 !=
V_915 -> V_11 -> V_237 -> V_243 ) {
V_80 -> V_917 = true ;
} else {
V_80 -> V_918 = true ;
}
}
if ( V_915 -> V_237 && ( V_915 -> V_229 != V_915 -> V_11 -> V_229 || V_915 -> V_230 != V_915 -> V_11 -> V_230 ) )
V_80 -> V_918 = true ;
if ( V_915 -> V_288 && ! F_575 ( V_915 -> V_288 , & V_915 -> V_11 -> V_288 ) ) {
F_32 ( L_218 ) ;
F_544 ( & V_915 -> V_11 -> V_288 ) ;
F_544 ( V_915 -> V_288 ) ;
V_80 -> V_917 = true ;
}
F_32 ( L_219 ,
V_915 -> V_11 -> V_114 . V_194 , V_80 -> V_917 , V_80 -> V_918 ) ;
}
static int
F_576 ( struct V_1 * V_2 ,
struct V_914 * V_915 ,
struct V_908 * V_80 )
{
struct V_10 * V_799 ;
struct V_423 * V_416 ;
struct V_48 * V_49 ;
int V_919 ;
F_2 ( ! V_915 -> V_237 && ( V_915 -> V_480 != 0 ) ) ;
F_2 ( V_915 -> V_237 && ( V_915 -> V_480 == 0 ) ) ;
F_154 (connector, &dev->mode_config.connector_list,
base.head) {
for ( V_919 = 0 ; V_919 < V_915 -> V_480 ; V_919 ++ ) {
if ( V_915 -> V_916 [ V_919 ] == & V_416 -> V_114 ) {
V_416 -> V_800 = V_416 -> V_49 ;
break;
}
}
if ( ( ! V_915 -> V_237 || V_919 == V_915 -> V_480 ) &&
V_416 -> V_114 . V_49 &&
V_416 -> V_114 . V_49 -> V_11 == V_915 -> V_11 ) {
V_416 -> V_800 = NULL ;
F_32 ( L_220 ,
V_416 -> V_114 . V_114 . V_194 ,
F_282 ( & V_416 -> V_114 ) ) ;
}
if ( & V_416 -> V_800 -> V_114 != V_416 -> V_114 . V_49 ) {
F_32 ( L_221 ) ;
V_80 -> V_917 = true ;
}
}
F_154 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_416 -> V_800 )
continue;
V_799 = V_416 -> V_800 -> V_114 . V_11 ;
for ( V_919 = 0 ; V_919 < V_915 -> V_480 ; V_919 ++ ) {
if ( V_915 -> V_916 [ V_919 ] == & V_416 -> V_114 )
V_799 = V_915 -> V_11 ;
}
if ( ! F_537 ( & V_416 -> V_800 -> V_114 ,
V_799 ) ) {
return - V_224 ;
}
V_416 -> V_49 -> V_799 = F_27 ( V_799 ) ;
F_32 ( L_222 ,
V_416 -> V_114 . V_114 . V_194 ,
F_282 ( & V_416 -> V_114 ) ,
V_799 -> V_114 . V_194 ) ;
}
F_154 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_154 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_416 -> V_800 == V_49 ) {
F_2 ( ! V_416 -> V_800 -> V_799 ) ;
goto V_920;
}
}
V_49 -> V_799 = NULL ;
V_920:
if ( & V_49 -> V_799 -> V_114 != V_49 -> V_114 . V_11 ) {
F_32 ( L_223 ) ;
V_80 -> V_917 = true ;
}
}
return 0 ;
}
static int F_577 ( struct V_914 * V_915 )
{
struct V_1 * V_2 ;
struct V_914 V_921 ;
struct V_908 * V_80 ;
int V_219 ;
F_95 ( ! V_915 ) ;
F_95 ( ! V_915 -> V_11 ) ;
F_95 ( ! V_915 -> V_11 -> V_922 ) ;
F_95 ( ! V_915 -> V_288 && V_915 -> V_237 ) ;
F_95 ( V_915 -> V_237 && V_915 -> V_480 == 0 ) ;
if ( V_915 -> V_237 ) {
F_32 ( L_224 ,
V_915 -> V_11 -> V_114 . V_194 , V_915 -> V_237 -> V_114 . V_194 ,
( int ) V_915 -> V_480 , V_915 -> V_229 , V_915 -> V_230 ) ;
} else {
F_32 ( L_225 , V_915 -> V_11 -> V_114 . V_194 ) ;
}
V_2 = V_915 -> V_11 -> V_2 ;
V_219 = - V_768 ;
V_80 = F_468 ( sizeof( * V_80 ) , V_788 ) ;
if ( ! V_80 )
goto V_923;
V_219 = F_570 ( V_2 , V_80 ) ;
if ( V_219 )
goto V_923;
V_921 . V_11 = V_915 -> V_11 ;
V_921 . V_288 = & V_915 -> V_11 -> V_288 ;
V_921 . V_229 = V_915 -> V_11 -> V_229 ;
V_921 . V_230 = V_915 -> V_11 -> V_230 ;
V_921 . V_237 = V_915 -> V_11 -> V_237 ;
F_574 ( V_915 , V_80 ) ;
V_219 = F_576 ( V_2 , V_915 , V_80 ) ;
if ( V_219 )
goto V_769;
if ( V_80 -> V_917 ) {
V_219 = F_483 ( V_915 -> V_11 , V_915 -> V_288 ,
V_915 -> V_229 , V_915 -> V_230 , V_915 -> V_237 ) ;
} else if ( V_80 -> V_918 ) {
F_192 ( V_915 -> V_11 ) ;
V_219 = F_162 ( V_915 -> V_11 ,
V_915 -> V_229 , V_915 -> V_230 , V_915 -> V_237 ) ;
}
if ( V_219 ) {
F_32 ( L_226 ,
V_915 -> V_11 -> V_114 . V_194 , V_219 ) ;
V_769:
F_572 ( V_2 , V_80 ) ;
if ( V_80 -> V_917 &&
F_483 ( V_921 . V_11 , V_921 . V_288 ,
V_921 . V_229 , V_921 . V_230 , V_921 . V_237 ) )
F_100 ( L_227 ) ;
}
V_923:
F_569 ( V_80 ) ;
return V_219 ;
}
static void F_578 ( struct V_1 * V_2 )
{
if ( F_54 ( V_2 ) )
F_579 ( V_2 ) ;
}
static bool F_580 ( struct V_3 * V_4 ,
struct V_113 * V_117 ,
struct V_118 * V_119 )
{
T_4 V_110 ;
V_110 = F_4 ( F_581 ( V_117 -> V_194 ) ) ;
V_119 -> V_46 = V_110 ;
V_119 -> V_485 = F_4 ( F_582 ( V_117 -> V_194 ) ) ;
V_119 -> V_488 = F_4 ( F_583 ( V_117 -> V_194 ) ) ;
return V_110 & V_112 ;
}
static void F_584 ( struct V_3 * V_4 ,
struct V_113 * V_117 )
{
F_36 ( F_582 ( V_117 -> V_194 ) , V_117 -> V_119 . V_485 ) ;
F_36 ( F_583 ( V_117 -> V_194 ) , V_117 -> V_119 . V_488 ) ;
}
static void F_585 ( struct V_3 * V_4 ,
struct V_113 * V_117 )
{
F_76 ( V_4 ) ;
F_36 ( F_581 ( V_117 -> V_194 ) , V_117 -> V_119 . V_46 ) ;
F_98 ( F_581 ( V_117 -> V_194 ) ) ;
F_99 ( 150 ) ;
F_36 ( F_581 ( V_117 -> V_194 ) , V_117 -> V_119 . V_46 ) ;
F_98 ( F_581 ( V_117 -> V_194 ) ) ;
F_99 ( 200 ) ;
}
static void F_586 ( struct V_3 * V_4 ,
struct V_113 * V_117 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_79 * V_11 ;
F_154 (crtc, &dev->mode_config.crtc_list, base.head) {
if ( F_49 ( V_11 ) == V_117 )
F_77 ( V_4 , V_11 -> V_77 ) ;
}
F_36 ( F_581 ( V_117 -> V_194 ) , 0 ) ;
F_98 ( F_581 ( V_117 -> V_194 ) ) ;
F_99 ( 200 ) ;
}
static void F_587 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_146 ;
V_4 -> V_377 = 2 ;
for ( V_146 = 0 ; V_146 < V_4 -> V_377 ; V_146 ++ ) {
V_4 -> V_116 [ V_146 ] . V_194 = V_146 ;
V_4 -> V_116 [ V_146 ] . V_121 = V_924 [ V_146 ] ;
V_4 -> V_116 [ V_146 ] . V_378 = F_584 ;
V_4 -> V_116 [ V_146 ] . V_195 = F_585 ;
V_4 -> V_116 [ V_146 ] . V_196 = F_586 ;
V_4 -> V_116 [ V_146 ] . V_120 =
F_580 ;
}
}
static void F_588 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_45 ( V_2 ) || F_80 ( V_2 ) )
F_587 ( V_2 ) ;
else
V_4 -> V_377 = 0 ;
F_95 ( V_4 -> V_377 > V_925 ) ;
F_32 ( L_228 ,
V_4 -> V_377 ) ;
}
static void F_589 ( struct V_1 * V_2 , int V_77 )
{
T_9 * V_4 = V_2 -> V_5 ;
struct V_79 * V_79 ;
int V_146 ;
V_79 = F_468 ( sizeof( struct V_79 ) + ( V_926 * sizeof( struct V_415 * ) ) , V_788 ) ;
if ( V_79 == NULL )
return;
F_590 ( V_2 , & V_79 -> V_114 , & V_927 ) ;
F_591 ( & V_79 -> V_114 , 256 ) ;
for ( V_146 = 0 ; V_146 < 256 ; V_146 ++ ) {
V_79 -> V_736 [ V_146 ] = V_146 ;
V_79 -> V_737 [ V_146 ] = V_146 ;
V_79 -> V_738 [ V_146 ] = V_146 ;
}
V_79 -> V_77 = V_77 ;
V_79 -> V_144 = V_77 ;
if ( F_96 ( V_2 ) && F_592 ( V_2 ) ) {
F_32 ( L_229 ) ;
V_79 -> V_144 = ! V_77 ;
}
F_95 ( V_77 >= F_183 ( V_4 -> V_836 ) ||
V_4 -> V_836 [ V_79 -> V_144 ] != NULL ) ;
V_4 -> V_836 [ V_79 -> V_144 ] = & V_79 -> V_114 ;
V_4 -> V_78 [ V_79 -> V_77 ] = & V_79 -> V_114 ;
F_593 ( & V_79 -> V_114 , & V_928 ) ;
}
int F_594 ( struct V_1 * V_2 , void * V_929 ,
struct V_762 * V_763 )
{
struct V_930 * V_931 = V_929 ;
struct V_932 * V_933 ;
struct V_79 * V_11 ;
if ( ! F_595 ( V_2 , V_934 ) )
return - V_856 ;
V_933 = F_596 ( V_2 , V_931 -> V_935 ,
V_936 ) ;
if ( ! V_933 ) {
F_100 ( L_230 ) ;
return - V_224 ;
}
V_11 = F_27 ( F_597 ( V_933 ) ) ;
V_931 -> V_77 = V_11 -> V_77 ;
return 0 ;
}
static int F_598 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_114 . V_2 ;
struct V_48 * V_937 ;
int V_938 = 0 ;
int V_939 = 0 ;
F_154 (source_encoder,
&dev->mode_config.encoder_list, base.head) {
if ( V_49 == V_937 )
V_938 |= ( 1 << V_939 ) ;
if ( V_49 -> V_877 && V_937 -> V_877 )
V_938 |= ( 1 << V_939 ) ;
V_939 ++ ;
}
return V_938 ;
}
static bool F_599 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_96 ( V_2 ) )
return false ;
if ( ( F_4 ( V_940 ) & V_941 ) == 0 )
return false ;
if ( F_6 ( V_2 ) &&
( F_4 ( V_942 ) & V_943 ) )
return false ;
return true ;
}
static void F_600 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_48 * V_49 ;
bool V_944 = false ;
F_601 ( V_2 ) ;
if ( ! F_602 ( V_2 ) )
F_603 ( V_2 ) ;
if ( F_54 ( V_2 ) ) {
int V_61 ;
V_61 = F_4 ( V_945 ) & V_946 ;
if ( V_61 )
F_604 ( V_2 , V_591 ) ;
V_61 = F_4 ( V_947 ) ;
if ( V_61 & V_948 )
F_604 ( V_2 , V_98 ) ;
if ( V_61 & V_949 )
F_604 ( V_2 , V_100 ) ;
if ( V_61 & V_950 )
F_604 ( V_2 , V_102 ) ;
} else if ( F_3 ( V_2 ) ) {
int V_61 ;
V_944 = F_605 ( V_2 ) ;
if ( F_599 ( V_2 ) )
F_606 ( V_2 , V_940 , V_591 ) ;
if ( F_4 ( V_182 ) & V_951 ) {
V_61 = F_607 ( V_2 , V_952 , true ) ;
if ( ! V_61 )
F_608 ( V_2 , V_182 , V_98 ) ;
if ( ! V_61 && ( F_4 ( V_175 ) & V_941 ) )
F_606 ( V_2 , V_175 , V_98 ) ;
}
if ( F_4 ( V_183 ) & V_951 )
F_608 ( V_2 , V_183 , V_100 ) ;
if ( ! V_944 && F_4 ( V_184 ) & V_951 )
F_608 ( V_2 , V_184 , V_102 ) ;
if ( F_4 ( V_177 ) & V_941 )
F_606 ( V_2 , V_177 , V_100 ) ;
if ( F_4 ( V_179 ) & V_941 )
F_606 ( V_2 , V_179 , V_102 ) ;
} else if ( F_14 ( V_2 ) ) {
if ( F_4 ( V_953 + V_954 ) & V_951 ) {
F_608 ( V_2 , V_953 + V_954 ,
V_100 ) ;
if ( F_4 ( V_953 + V_955 ) & V_941 )
F_606 ( V_2 , V_953 + V_955 ,
V_100 ) ;
}
if ( F_4 ( V_953 + V_956 ) & V_951 ) {
F_608 ( V_2 , V_953 + V_956 ,
V_98 ) ;
if ( F_4 ( V_953 + V_957 ) & V_941 )
F_606 ( V_2 , V_953 + V_957 , V_98 ) ;
}
} else if ( F_609 ( V_2 ) ) {
bool V_61 = false ;
if ( F_4 ( V_958 ) & V_951 ) {
F_32 ( L_231 ) ;
V_61 = F_607 ( V_2 , V_958 , true ) ;
if ( ! V_61 && F_610 ( V_2 ) ) {
F_32 ( L_232 ) ;
F_608 ( V_2 , V_956 , V_98 ) ;
}
if ( ! V_61 && F_611 ( V_2 ) )
F_606 ( V_2 , V_957 , V_98 ) ;
}
if ( F_4 ( V_958 ) & V_951 ) {
F_32 ( L_233 ) ;
V_61 = F_607 ( V_2 , V_959 , false ) ;
}
if ( ! V_61 && ( F_4 ( V_959 ) & V_951 ) ) {
if ( F_610 ( V_2 ) ) {
F_32 ( L_234 ) ;
F_608 ( V_2 , V_954 , V_100 ) ;
}
if ( F_611 ( V_2 ) )
F_606 ( V_2 , V_955 , V_100 ) ;
}
if ( F_611 ( V_2 ) &&
( F_4 ( V_960 ) & V_941 ) )
F_606 ( V_2 , V_960 , V_102 ) ;
} else if ( F_15 ( V_2 ) )
F_612 ( V_2 ) ;
if ( F_613 ( V_2 ) )
F_614 ( V_2 ) ;
F_154 (encoder, &dev->mode_config.encoder_list, base.head) {
V_49 -> V_114 . V_798 = V_49 -> V_872 ;
V_49 -> V_114 . V_961 =
F_598 ( V_49 ) ;
}
F_365 ( V_2 ) ;
F_615 ( V_2 ) ;
}
void F_616 ( struct V_238 * V_237 )
{
F_617 ( & V_237 -> V_114 ) ;
F_462 ( & V_237 -> V_215 -> V_114 ) ;
}
static void F_618 ( struct V_236 * V_237 )
{
struct V_238 * V_239 = F_142 ( V_237 ) ;
F_616 ( V_239 ) ;
F_279 ( V_239 ) ;
}
static int F_619 ( struct V_236 * V_237 ,
struct V_762 * V_763 ,
unsigned int * V_764 )
{
struct V_238 * V_239 = F_142 ( V_237 ) ;
struct V_214 * V_215 = V_239 -> V_215 ;
return F_620 ( V_763 , & V_215 -> V_114 , V_764 ) ;
}
int F_470 ( struct V_1 * V_2 ,
struct V_238 * V_239 ,
struct V_786 * V_787 ,
struct V_214 * V_215 )
{
int V_962 ;
int V_219 ;
if ( V_215 -> V_220 == V_223 ) {
F_621 ( L_235 ) ;
return - V_224 ;
}
if ( V_787 -> V_265 [ 0 ] & 63 ) {
F_621 ( L_236 ,
V_787 -> V_265 [ 0 ] ) ;
return - V_224 ;
}
if ( F_35 ( V_2 ) -> V_85 >= 5 && ! F_14 ( V_2 ) ) {
V_962 = 32 * 1024 ;
} else if ( F_35 ( V_2 ) -> V_85 >= 4 ) {
if ( V_215 -> V_220 )
V_962 = 16 * 1024 ;
else
V_962 = 32 * 1024 ;
} else if ( F_35 ( V_2 ) -> V_85 >= 3 ) {
if ( V_215 -> V_220 )
V_962 = 8 * 1024 ;
else
V_962 = 16 * 1024 ;
} else
V_962 = 8 * 1024 ;
if ( V_787 -> V_265 [ 0 ] > V_962 ) {
F_621 ( L_237 ,
V_215 -> V_220 ? L_238 : L_239 ,
V_787 -> V_265 [ 0 ] , V_962 ) ;
return - V_224 ;
}
if ( V_215 -> V_220 != V_221 &&
V_787 -> V_265 [ 0 ] != V_215 -> V_963 ) {
F_621 ( L_240 ,
V_787 -> V_265 [ 0 ] , V_215 -> V_963 ) ;
return - V_224 ;
}
switch ( V_787 -> V_243 ) {
case V_244 :
case V_249 :
case V_251 :
case V_252 :
break;
case V_246 :
case V_247 :
if ( F_35 ( V_2 ) -> V_85 > 3 ) {
F_621 ( L_241 ,
F_622 ( V_787 -> V_243 ) ) ;
return - V_224 ;
}
break;
case V_254 :
case V_255 :
case V_257 :
case V_258 :
case V_260 :
case V_261 :
if ( F_35 ( V_2 ) -> V_85 < 4 ) {
F_621 ( L_241 ,
F_622 ( V_787 -> V_243 ) ) ;
return - V_224 ;
}
break;
case V_964 :
case V_965 :
case V_966 :
case V_967 :
if ( F_35 ( V_2 ) -> V_85 < 5 ) {
F_621 ( L_241 ,
F_622 ( V_787 -> V_243 ) ) ;
return - V_224 ;
}
break;
default:
F_621 ( L_241 ,
F_622 ( V_787 -> V_243 ) ) ;
return - V_224 ;
}
if ( V_787 -> V_865 [ 0 ] != 0 )
return - V_224 ;
F_623 ( & V_239 -> V_114 , V_787 ) ;
V_239 -> V_215 = V_215 ;
V_219 = F_624 ( V_2 , & V_239 -> V_114 , & V_968 ) ;
if ( V_219 ) {
F_100 ( L_242 , V_219 ) ;
return V_219 ;
}
return 0 ;
}
static struct V_236 *
F_625 ( struct V_1 * V_2 ,
struct V_762 * V_969 ,
struct V_786 * V_787 )
{
struct V_214 * V_215 ;
V_215 = F_456 ( F_457 ( V_2 , V_969 ,
V_787 -> V_970 [ 0 ] ) ) ;
if ( & V_215 -> V_114 == NULL )
return F_469 ( - V_767 ) ;
return F_467 ( V_2 , V_787 , V_215 ) ;
}
static void F_626 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_3 ( V_2 ) || F_12 ( V_2 ) )
V_4 -> V_269 . V_571 = F_24 ;
else if ( F_14 ( V_2 ) )
V_4 -> V_269 . V_571 = F_25 ;
else if ( F_13 ( V_2 ) )
V_4 -> V_269 . V_571 = F_23 ;
else
V_4 -> V_269 . V_571 = F_22 ;
if ( F_54 ( V_2 ) ) {
V_4 -> V_269 . V_898 = F_420 ;
V_4 -> V_269 . V_700 = F_418 ;
V_4 -> V_269 . V_413 = F_245 ;
V_4 -> V_269 . V_414 = F_253 ;
V_4 -> V_269 . V_418 = F_258 ;
V_4 -> V_269 . V_271 = F_148 ;
} else if ( F_3 ( V_2 ) ) {
V_4 -> V_269 . V_898 = F_392 ;
V_4 -> V_269 . V_900 = F_489 ;
V_4 -> V_269 . V_700 = F_387 ;
V_4 -> V_269 . V_413 = F_235 ;
V_4 -> V_269 . V_414 = F_250 ;
V_4 -> V_269 . V_418 = F_257 ;
V_4 -> V_269 . V_271 = F_148 ;
} else if ( F_14 ( V_2 ) ) {
V_4 -> V_269 . V_898 = F_356 ;
V_4 -> V_269 . V_900 = F_487 ;
V_4 -> V_269 . V_700 = F_352 ;
V_4 -> V_269 . V_413 = F_267 ;
V_4 -> V_269 . V_414 = F_270 ;
V_4 -> V_269 . V_418 = F_271 ;
V_4 -> V_269 . V_271 = F_141 ;
} else {
V_4 -> V_269 . V_898 = F_356 ;
V_4 -> V_269 . V_900 = F_487 ;
V_4 -> V_269 . V_700 = F_352 ;
V_4 -> V_269 . V_413 = F_268 ;
V_4 -> V_269 . V_414 = F_270 ;
V_4 -> V_269 . V_418 = F_271 ;
V_4 -> V_269 . V_271 = F_141 ;
}
if ( F_14 ( V_2 ) )
V_4 -> V_269 . V_555 =
F_294 ;
else if ( F_343 ( V_2 ) || ( F_345 ( V_2 ) && ! F_627 ( V_2 ) ) )
V_4 -> V_269 . V_555 =
F_295 ;
else if ( F_628 ( V_2 ) )
V_4 -> V_269 . V_555 =
F_296 ;
else if ( F_344 ( V_2 ) || F_453 ( V_2 ) )
V_4 -> V_269 . V_555 =
F_297 ;
else if ( F_13 ( V_2 ) )
V_4 -> V_269 . V_555 =
F_298 ;
else if ( F_629 ( V_2 ) )
V_4 -> V_269 . V_555 =
F_300 ;
else if ( F_454 ( V_2 ) )
V_4 -> V_269 . V_555 =
F_301 ;
else if ( F_630 ( V_2 ) )
V_4 -> V_269 . V_555 =
F_302 ;
else
V_4 -> V_269 . V_555 =
F_303 ;
if ( F_3 ( V_2 ) ) {
if ( F_6 ( V_2 ) ) {
V_4 -> V_269 . V_361 = F_173 ;
V_4 -> V_269 . V_731 = F_433 ;
} else if ( F_181 ( V_2 ) ) {
V_4 -> V_269 . V_361 = F_179 ;
V_4 -> V_269 . V_731 = F_433 ;
} else if ( F_170 ( V_2 ) ) {
V_4 -> V_269 . V_361 = F_182 ;
V_4 -> V_269 . V_731 = F_433 ;
V_4 -> V_269 . V_907 =
F_172 ;
} else if ( F_149 ( V_2 ) ) {
V_4 -> V_269 . V_361 = V_971 ;
V_4 -> V_269 . V_731 = F_429 ;
V_4 -> V_269 . V_907 =
F_416 ;
}
} else if ( F_12 ( V_2 ) ) {
V_4 -> V_269 . V_731 = F_428 ;
}
V_4 -> V_269 . V_870 = F_528 ;
switch ( F_35 ( V_2 ) -> V_85 ) {
case 2 :
V_4 -> V_269 . V_870 = F_516 ;
break;
case 3 :
V_4 -> V_269 . V_870 = F_521 ;
break;
case 4 :
case 5 :
V_4 -> V_269 . V_870 = F_522 ;
break;
case 6 :
V_4 -> V_269 . V_870 = F_523 ;
break;
case 7 :
V_4 -> V_269 . V_870 = F_524 ;
break;
}
}
static void F_631 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_141 |= V_142 ;
F_632 ( L_243 ) ;
}
static void F_633 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_141 |= V_479 ;
F_632 ( L_244 ) ;
}
static void F_634 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_141 |= V_972 ;
F_632 ( L_245 ) ;
}
static void F_635 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_141 |= V_973 ;
F_632 ( L_246 ) ;
}
static int F_636 ( const struct V_974 * V_194 )
{
F_632 ( L_247 , V_194 -> V_975 ) ;
return 1 ;
}
static void F_637 ( struct V_1 * V_2 )
{
struct V_976 * V_977 = V_2 -> V_442 ;
int V_146 ;
for ( V_146 = 0 ; V_146 < F_183 ( V_978 ) ; V_146 ++ ) {
struct V_979 * V_980 = & V_978 [ V_146 ] ;
if ( V_977 -> V_981 == V_980 -> V_981 &&
( V_977 -> V_982 == V_980 -> V_982 ||
V_980 -> V_982 == V_983 ) &&
( V_977 -> V_984 == V_980 -> V_984 ||
V_980 -> V_984 == V_983 ) )
V_980 -> V_985 ( V_2 ) ;
}
for ( V_146 = 0 ; V_146 < F_183 ( V_986 ) ; V_146 ++ ) {
if ( F_638 ( * V_986 [ V_146 ] . V_987 ) != 0 )
V_986 [ V_146 ] . V_985 ( V_2 ) ;
}
}
static void F_639 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_12 V_988 ;
T_1 V_989 = F_640 ( V_2 ) ;
F_641 ( V_2 -> V_442 , V_990 ) ;
F_642 ( V_991 , V_992 ) ;
V_988 = F_643 ( V_993 ) ;
F_642 ( V_988 | 1 << 5 , V_993 ) ;
F_644 ( V_2 -> V_442 , V_990 ) ;
F_99 ( 300 ) ;
F_36 ( V_989 , V_994 ) ;
F_98 ( V_989 ) ;
}
void F_645 ( struct V_1 * V_2 )
{
F_646 ( V_2 ) ;
F_407 ( V_2 ) ;
F_647 ( V_2 ) ;
F_157 ( & V_2 -> V_286 ) ;
F_648 ( V_2 ) ;
F_158 ( & V_2 -> V_286 ) ;
}
void F_649 ( struct V_1 * V_2 )
{
F_650 ( V_2 ) ;
}
void F_651 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_146 , V_325 , V_219 ;
F_652 ( V_2 ) ;
V_2 -> V_584 . V_995 = 0 ;
V_2 -> V_584 . V_996 = 0 ;
V_2 -> V_584 . V_997 = 24 ;
V_2 -> V_584 . V_998 = 1 ;
V_2 -> V_584 . V_669 = & V_999 ;
F_637 ( V_2 ) ;
F_653 ( V_2 ) ;
if ( F_35 ( V_2 ) -> V_285 == 0 )
return;
F_626 ( V_2 ) ;
if ( F_15 ( V_2 ) ) {
V_2 -> V_584 . V_1000 = 2048 ;
V_2 -> V_584 . V_1001 = 2048 ;
} else if ( F_592 ( V_2 ) ) {
V_2 -> V_584 . V_1000 = 4096 ;
V_2 -> V_584 . V_1001 = 4096 ;
} else {
V_2 -> V_584 . V_1000 = 8192 ;
V_2 -> V_584 . V_1001 = 8192 ;
}
V_2 -> V_584 . V_1002 = V_4 -> V_1003 . V_1004 ;
F_32 ( L_248 ,
F_35 ( V_2 ) -> V_285 ,
F_35 ( V_2 ) -> V_285 > 1 ? L_249 : L_250 ) ;
F_70 (i) {
F_589 ( V_2 , V_146 ) ;
for ( V_325 = 0 ; V_325 < V_4 -> V_150 ; V_325 ++ ) {
V_219 = F_654 ( V_2 , V_146 , V_325 ) ;
if ( V_219 )
F_32 ( L_251 ,
F_62 ( V_146 ) , F_73 ( V_146 , V_325 ) , V_219 ) ;
}
}
F_578 ( V_2 ) ;
F_588 ( V_2 ) ;
F_639 ( V_2 ) ;
F_600 ( V_2 ) ;
F_252 ( V_2 ) ;
}
static void
F_655 ( struct V_423 * V_416 )
{
V_416 -> V_114 . V_419 = V_420 ;
V_416 -> V_114 . V_49 = NULL ;
V_416 -> V_49 -> V_412 = false ;
V_416 -> V_49 -> V_114 . V_11 = NULL ;
}
static void F_656 ( struct V_1 * V_2 )
{
struct V_423 * V_416 ;
struct V_415 * V_1005 = NULL ;
struct V_793 V_797 ;
F_154 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_416 -> V_49 -> type == V_23 ) {
V_1005 = & V_416 -> V_114 ;
break;
}
}
if ( ! V_1005 )
return;
if ( F_479 ( V_1005 , NULL , & V_797 ) )
F_484 ( V_1005 , & V_797 ) ;
}
static bool
F_657 ( struct V_79 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_87 , V_110 ;
if ( F_35 ( V_2 ) -> V_285 == 1 )
return true ;
V_87 = F_67 ( ! V_11 -> V_144 ) ;
V_110 = F_4 ( V_87 ) ;
if ( ( V_110 & V_145 ) &&
( ! ! ( V_110 & V_148 ) == V_11 -> V_77 ) )
return false ;
return true ;
}
static void F_658 ( struct V_79 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_114 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_87 ;
V_87 = F_38 ( V_11 -> V_80 . V_81 ) ;
F_36 ( V_87 , F_4 ( V_87 ) & ~ V_1006 ) ;
if ( F_35 ( V_2 ) -> V_85 < 4 && ! F_657 ( V_11 ) ) {
struct V_423 * V_416 ;
bool V_144 ;
F_32 ( L_252 ,
V_11 -> V_114 . V_114 . V_194 ) ;
V_144 = V_11 -> V_144 ;
V_11 -> V_144 = ! V_144 ;
V_4 -> V_269 . V_414 ( & V_11 -> V_114 ) ;
V_11 -> V_144 = V_144 ;
F_154 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_416 -> V_49 -> V_114 . V_11 != & V_11 -> V_114 )
continue;
F_655 ( V_416 ) ;
}
F_2 ( V_11 -> V_192 ) ;
V_11 -> V_114 . V_108 = false ;
}
if ( V_4 -> V_141 & V_142 &&
V_11 -> V_77 == V_131 && ! V_11 -> V_192 ) {
F_656 ( V_2 ) ;
}
F_273 ( & V_11 -> V_114 ) ;
if ( V_11 -> V_192 != V_11 -> V_114 . V_108 ) {
struct V_48 * V_49 ;
F_32 ( L_253 ,
V_11 -> V_114 . V_114 . V_194 ,
V_11 -> V_114 . V_108 ? L_178 : L_179 ,
V_11 -> V_192 ? L_178 : L_179 ) ;
V_11 -> V_114 . V_108 = V_11 -> V_192 ;
F_2 ( V_11 -> V_192 ) ;
F_19 (dev, &crtc->base, encoder) {
F_2 ( V_49 -> V_412 ) ;
V_49 -> V_114 . V_11 = NULL ;
}
}
}
static void F_659 ( struct V_48 * V_49 )
{
struct V_423 * V_416 ;
struct V_1 * V_2 = V_49 -> V_114 . V_2 ;
bool V_1007 = V_49 -> V_114 . V_11 &&
F_27 ( V_49 -> V_114 . V_11 ) -> V_192 ;
if ( V_49 -> V_412 && ! V_1007 ) {
F_32 ( L_254 ,
V_49 -> V_114 . V_114 . V_194 ,
F_426 ( & V_49 -> V_114 ) ) ;
if ( V_49 -> V_114 . V_11 ) {
F_32 ( L_255 ,
V_49 -> V_114 . V_114 . V_194 ,
F_426 ( & V_49 -> V_114 ) ) ;
V_49 -> V_196 ( V_49 ) ;
}
F_154 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_416 -> V_49 != V_49 )
continue;
F_655 ( V_416 ) ;
}
}
}
void F_660 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_989 = F_640 ( V_2 ) ;
if ( F_661 ( V_2 ) &&
( F_4 ( V_637 ) & V_1008 ) == 0 )
return;
if ( F_4 ( V_989 ) != V_994 ) {
F_32 ( L_256 ) ;
F_639 ( V_2 ) ;
}
}
static void F_662 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_77 V_77 ;
struct V_79 * V_11 ;
struct V_48 * V_49 ;
struct V_423 * V_416 ;
int V_146 ;
F_154 (crtc, &dev->mode_config.crtc_list,
base.head) {
memset ( & V_11 -> V_80 , 0 , sizeof( V_11 -> V_80 ) ) ;
V_11 -> V_192 = V_4 -> V_269 . V_898 ( V_11 ,
& V_11 -> V_80 ) ;
V_11 -> V_114 . V_108 = V_11 -> V_192 ;
F_32 ( L_257 ,
V_11 -> V_114 . V_114 . V_194 ,
V_11 -> V_192 ? L_178 : L_179 ) ;
}
if ( F_54 ( V_2 ) )
F_663 ( V_2 ) ;
for ( V_146 = 0 ; V_146 < V_4 -> V_377 ; V_146 ++ ) {
struct V_113 * V_117 = & V_4 -> V_116 [ V_146 ] ;
V_117 -> V_193 = V_117 -> V_120 ( V_4 , V_117 , & V_117 -> V_119 ) ;
V_117 -> V_192 = 0 ;
F_154 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_11 -> V_192 && F_49 ( V_11 ) == V_117 )
V_117 -> V_192 ++ ;
}
V_117 -> V_191 = V_117 -> V_192 ;
F_32 ( L_258 ,
V_117 -> V_121 , V_117 -> V_191 , V_117 -> V_193 ) ;
}
F_154 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_77 = 0 ;
if ( V_49 -> V_120 ( V_49 , & V_77 ) ) {
V_11 = F_27 ( V_4 -> V_78 [ V_77 ] ) ;
V_49 -> V_114 . V_11 = & V_11 -> V_114 ;
if ( V_49 -> V_899 )
V_49 -> V_899 ( V_49 , & V_11 -> V_80 ) ;
} else {
V_49 -> V_114 . V_11 = NULL ;
}
V_49 -> V_412 = false ;
F_32 ( L_259 ,
V_49 -> V_114 . V_114 . V_194 ,
F_426 ( & V_49 -> V_114 ) ,
V_49 -> V_114 . V_11 ? L_178 : L_179 ,
V_77 ) ;
}
F_154 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( ! V_11 -> V_192 )
continue;
if ( V_4 -> V_269 . V_900 )
V_4 -> V_269 . V_900 ( V_11 ,
& V_11 -> V_80 ) ;
}
F_154 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_416 -> V_120 ( V_416 ) ) {
V_416 -> V_114 . V_419 = V_422 ;
V_416 -> V_49 -> V_412 = true ;
V_416 -> V_114 . V_49 = & V_416 -> V_49 -> V_114 ;
} else {
V_416 -> V_114 . V_419 = V_420 ;
V_416 -> V_114 . V_49 = NULL ;
}
F_32 ( L_260 ,
V_416 -> V_114 . V_114 . V_194 ,
F_282 ( & V_416 -> V_114 ) ,
V_416 -> V_114 . V_49 ? L_178 : L_179 ) ;
}
}
void F_664 ( struct V_1 * V_2 ,
bool V_1009 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_77 V_77 ;
struct V_1010 * V_144 ;
struct V_79 * V_11 ;
struct V_48 * V_49 ;
int V_146 ;
F_662 ( V_2 ) ;
F_154 (crtc, &dev->mode_config.crtc_list,
base.head) {
if ( V_11 -> V_192 && V_287 ) {
F_349 ( V_11 , & V_11 -> V_80 ) ;
F_32 ( L_261 ,
V_11 -> V_114 . V_114 . V_194 ) ;
F_544 ( & V_11 -> V_114 . V_288 ) ;
}
}
F_154 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_659 ( V_49 ) ;
}
F_70 (pipe) {
V_11 = F_27 ( V_4 -> V_78 [ V_77 ] ) ;
F_658 ( V_11 ) ;
F_542 ( V_11 , & V_11 -> V_80 , L_262 ) ;
}
for ( V_146 = 0 ; V_146 < V_4 -> V_377 ; V_146 ++ ) {
struct V_113 * V_117 = & V_4 -> V_116 [ V_146 ] ;
if ( ! V_117 -> V_193 || V_117 -> V_192 )
continue;
F_32 ( L_263 , V_117 -> V_121 ) ;
V_117 -> V_196 ( V_4 , V_117 ) ;
V_117 -> V_193 = false ;
}
if ( V_1009 ) {
F_70 (pipe) {
struct V_10 * V_11 =
V_4 -> V_78 [ V_77 ] ;
F_563 ( V_11 , & V_11 -> V_288 , V_11 -> V_229 , V_11 -> V_230 ,
V_11 -> V_237 ) ;
}
F_154 (plane, &dev->mode_config.plane_list, head)
F_232 ( V_144 ) ;
F_660 ( V_2 ) ;
} else {
F_538 ( V_2 ) ;
}
F_284 ( V_2 ) ;
F_665 ( V_2 ) ;
}
void F_666 ( struct V_1 * V_2 )
{
F_645 ( V_2 ) ;
F_667 ( V_2 ) ;
F_664 ( V_2 , false ) ;
}
void F_668 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_11 ;
F_669 ( V_2 ) ;
F_500 ( & V_4 -> V_1011 ) ;
F_670 ( V_2 ) ;
F_157 ( & V_2 -> V_286 ) ;
F_671 () ;
F_154 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_11 -> V_237 )
continue;
F_152 ( V_11 ) ;
}
F_252 ( V_2 ) ;
F_672 ( V_2 ) ;
F_673 ( V_2 ) ;
F_158 ( & V_2 -> V_286 ) ;
F_674 () ;
F_675 ( V_2 ) ;
F_676 ( V_2 ) ;
F_677 ( V_2 ) ;
}
struct V_421 * F_678 ( struct V_415 * V_416 )
{
return & F_480 ( V_416 ) -> V_114 ;
}
void F_679 ( struct V_423 * V_416 ,
struct V_48 * V_49 )
{
V_416 -> V_49 = V_49 ;
F_680 ( & V_416 -> V_114 ,
& V_49 -> V_114 ) ;
}
int F_681 ( struct V_1 * V_2 , bool V_109 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_1012 ;
F_299 ( V_4 -> V_1013 , V_1014 , & V_1012 ) ;
if ( V_109 )
V_1012 &= ~ V_1015 ;
else
V_1012 |= V_1015 ;
F_682 ( V_4 -> V_1013 , V_1014 , V_1012 ) ;
return 0 ;
}
struct V_1016 *
F_683 ( struct V_1 * V_2 )
{
T_9 * V_4 = V_2 -> V_5 ;
struct V_1016 * error ;
int V_1017 [] = {
V_207 ,
V_1018 ,
V_1019 ,
V_547 ,
} ;
int V_146 ;
if ( F_35 ( V_2 ) -> V_285 == 0 )
return NULL ;
error = F_564 ( sizeof( * error ) , V_1020 ) ;
if ( error == NULL )
return NULL ;
if ( F_661 ( V_2 ) )
error -> V_1021 = F_4 ( V_637 ) ;
F_70 (i) {
if ( F_35 ( V_2 ) -> V_85 <= 6 || F_14 ( V_2 ) ) {
error -> V_1022 [ V_146 ] . V_402 = F_4 ( F_263 ( V_146 ) ) ;
error -> V_1022 [ V_146 ] . V_1023 = F_4 ( F_452 ( V_146 ) ) ;
error -> V_1022 [ V_146 ] . V_114 = F_4 ( F_264 ( V_146 ) ) ;
} else {
error -> V_1022 [ V_146 ] . V_402 = F_4 ( F_449 ( V_146 ) ) ;
error -> V_1022 [ V_146 ] . V_1023 = F_4 ( F_451 ( V_146 ) ) ;
error -> V_1022 [ V_146 ] . V_114 = F_4 ( F_450 ( V_146 ) ) ;
}
error -> V_144 [ V_146 ] . V_402 = F_4 ( F_67 ( V_146 ) ) ;
error -> V_144 [ V_146 ] . V_963 = F_4 ( F_144 ( V_146 ) ) ;
if ( F_35 ( V_2 ) -> V_85 <= 3 ) {
error -> V_144 [ V_146 ] . V_383 = F_4 ( F_353 ( V_146 ) ) ;
error -> V_144 [ V_146 ] . V_382 = F_4 ( F_354 ( V_146 ) ) ;
}
if ( F_35 ( V_2 ) -> V_85 <= 7 && ! F_149 ( V_2 ) )
error -> V_144 [ V_146 ] . V_765 = F_4 ( F_124 ( V_146 ) ) ;
if ( F_35 ( V_2 ) -> V_85 >= 4 ) {
error -> V_144 [ V_146 ] . V_1024 = F_4 ( F_123 ( V_146 ) ) ;
error -> V_144 [ V_146 ] . V_1025 = F_4 ( F_146 ( V_146 ) ) ;
}
error -> V_77 [ V_146 ] . V_1026 = F_4 ( F_163 ( V_146 ) ) ;
}
error -> V_1027 = F_35 ( V_2 ) -> V_285 ;
if ( F_54 ( V_4 -> V_2 ) )
error -> V_1027 ++ ;
for ( V_146 = 0 ; V_146 < error -> V_1027 ; V_146 ++ ) {
enum V_76 V_81 = V_1017 [ V_146 ] ;
error -> V_76 [ V_146 ] . V_81 = V_81 ;
error -> V_76 [ V_146 ] . V_1028 = F_4 ( F_38 ( V_81 ) ) ;
error -> V_76 [ V_146 ] . V_549 = F_4 ( F_204 ( V_81 ) ) ;
error -> V_76 [ V_146 ] . V_1029 = F_4 ( F_206 ( V_81 ) ) ;
error -> V_76 [ V_146 ] . V_822 = F_4 ( F_208 ( V_81 ) ) ;
error -> V_76 [ V_146 ] . V_551 = F_4 ( F_210 ( V_81 ) ) ;
error -> V_76 [ V_146 ] . V_1030 = F_4 ( F_212 ( V_81 ) ) ;
error -> V_76 [ V_146 ] . V_824 = F_4 ( F_214 ( V_81 ) ) ;
}
F_684 ( V_2 ) ;
return error ;
}
void
F_685 ( struct V_1031 * V_38 ,
struct V_1 * V_2 ,
struct V_1016 * error )
{
int V_146 ;
if ( ! error )
return;
F_686 ( V_38 , L_264 , F_35 ( V_2 ) -> V_285 ) ;
if ( F_661 ( V_2 ) )
F_686 ( V_38 , L_265 ,
error -> V_1021 ) ;
F_70 (i) {
F_686 ( V_38 , L_266 , V_146 ) ;
F_686 ( V_38 , L_267 , error -> V_77 [ V_146 ] . V_1026 ) ;
F_686 ( V_38 , L_268 , V_146 ) ;
F_686 ( V_38 , L_269 , error -> V_144 [ V_146 ] . V_402 ) ;
F_686 ( V_38 , L_270 , error -> V_144 [ V_146 ] . V_963 ) ;
if ( F_35 ( V_2 ) -> V_85 <= 3 ) {
F_686 ( V_38 , L_271 , error -> V_144 [ V_146 ] . V_383 ) ;
F_686 ( V_38 , L_272 , error -> V_144 [ V_146 ] . V_382 ) ;
}
if ( F_35 ( V_2 ) -> V_85 <= 7 && ! F_149 ( V_2 ) )
F_686 ( V_38 , L_273 , error -> V_144 [ V_146 ] . V_765 ) ;
if ( F_35 ( V_2 ) -> V_85 >= 4 ) {
F_686 ( V_38 , L_274 , error -> V_144 [ V_146 ] . V_1024 ) ;
F_686 ( V_38 , L_275 , error -> V_144 [ V_146 ] . V_1025 ) ;
}
F_686 ( V_38 , L_276 , V_146 ) ;
F_686 ( V_38 , L_269 , error -> V_1022 [ V_146 ] . V_402 ) ;
F_686 ( V_38 , L_272 , error -> V_1022 [ V_146 ] . V_1023 ) ;
F_686 ( V_38 , L_277 , error -> V_1022 [ V_146 ] . V_114 ) ;
}
for ( V_146 = 0 ; V_146 < error -> V_1027 ; V_146 ++ ) {
F_686 ( V_38 , L_278 ,
F_543 ( error -> V_76 [ V_146 ] . V_81 ) ) ;
F_686 ( V_38 , L_279 , error -> V_76 [ V_146 ] . V_1028 ) ;
F_686 ( V_38 , L_280 , error -> V_76 [ V_146 ] . V_549 ) ;
F_686 ( V_38 , L_281 , error -> V_76 [ V_146 ] . V_1029 ) ;
F_686 ( V_38 , L_282 , error -> V_76 [ V_146 ] . V_822 ) ;
F_686 ( V_38 , L_283 , error -> V_76 [ V_146 ] . V_551 ) ;
F_686 ( V_38 , L_284 , error -> V_76 [ V_146 ] . V_1030 ) ;
F_686 ( V_38 , L_285 , error -> V_76 [ V_146 ] . V_824 ) ;
}
}
