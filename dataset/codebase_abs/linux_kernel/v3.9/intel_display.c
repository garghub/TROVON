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
T_1 F_7 ( struct V_3 * V_4 , int V_10 )
{
F_2 ( ! F_8 ( & V_4 -> V_11 ) ) ;
if ( F_9 ( ( F_4 ( V_12 ) & V_13 ) == 0 , 100 ) ) {
F_10 ( L_1 ) ;
return 0 ;
}
F_11 ( V_14 , V_10 ) ;
F_11 ( V_12 , V_15 | V_16 | V_17 |
V_18 ) ;
if ( F_9 ( ( F_4 ( V_12 ) & V_13 ) == 0 , 100 ) ) {
F_10 ( L_2 ) ;
return 0 ;
}
return F_4 ( V_19 ) ;
}
static void F_12 ( struct V_3 * V_4 , int V_10 ,
T_1 V_20 )
{
F_2 ( ! F_8 ( & V_4 -> V_11 ) ) ;
if ( F_9 ( ( F_4 ( V_12 ) & V_13 ) == 0 , 100 ) ) {
F_10 ( L_1 ) ;
return;
}
F_11 ( V_19 , V_20 ) ;
F_11 ( V_14 , V_10 ) ;
F_11 ( V_12 , V_15 | V_21 | V_17 |
V_18 ) ;
if ( F_9 ( ( F_4 ( V_12 ) & V_13 ) == 0 , 100 ) )
F_10 ( L_3 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_11 ( V_22 , 0 ) ;
F_14 ( V_22 ) ;
F_11 ( V_22 , 1 ) ;
F_14 ( V_22 ) ;
}
static const T_2 * F_15 ( struct V_23 * V_24 ,
int V_25 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
const T_2 * V_26 ;
if ( F_16 ( V_24 , V_27 ) ) {
if ( F_17 ( V_2 ) ) {
if ( V_25 == 100000 )
V_26 = & V_28 ;
else
V_26 = & V_29 ;
} else {
if ( V_25 == 100000 )
V_26 = & V_30 ;
else
V_26 = & V_31 ;
}
} else if ( F_16 ( V_24 , V_32 ) ||
F_16 ( V_24 , V_33 ) )
V_26 = & V_34 ;
else
V_26 = & V_35 ;
return V_26 ;
}
static const T_2 * F_18 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
const T_2 * V_26 ;
if ( F_16 ( V_24 , V_27 ) ) {
if ( F_17 ( V_2 ) )
V_26 = & V_36 ;
else
V_26 = & V_37 ;
} else if ( F_16 ( V_24 , V_38 ) ||
F_16 ( V_24 , V_39 ) ) {
V_26 = & V_40 ;
} else if ( F_16 ( V_24 , V_41 ) ) {
V_26 = & V_42 ;
} else if ( F_16 ( V_24 , V_32 ) ) {
V_26 = & V_43 ;
} else
V_26 = & V_44 ;
return V_26 ;
}
static const T_2 * F_19 ( struct V_23 * V_24 , int V_25 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
const T_2 * V_26 ;
if ( F_3 ( V_2 ) )
V_26 = F_15 ( V_24 , V_25 ) ;
else if ( F_20 ( V_2 ) ) {
V_26 = F_18 ( V_24 ) ;
} else if ( F_21 ( V_2 ) ) {
if ( F_16 ( V_24 , V_27 ) )
V_26 = & V_45 ;
else
V_26 = & V_46 ;
} else if ( F_22 ( V_2 ) ) {
if ( F_16 ( V_24 , V_39 ) )
V_26 = & V_47 ;
else if ( F_16 ( V_24 , V_38 ) )
V_26 = & V_48 ;
else
V_26 = & V_49 ;
} else if ( ! F_23 ( V_2 ) ) {
if ( F_16 ( V_24 , V_27 ) )
V_26 = & V_50 ;
else
V_26 = & V_44 ;
} else {
if ( F_16 ( V_24 , V_27 ) )
V_26 = & V_51 ;
else
V_26 = & V_52 ;
}
return V_26 ;
}
static void F_24 ( int V_25 , T_3 * clock )
{
clock -> V_53 = clock -> V_54 + 2 ;
clock -> V_55 = clock -> V_56 * clock -> V_57 ;
clock -> V_58 = V_25 * clock -> V_53 / clock -> V_59 ;
clock -> V_60 = clock -> V_58 / clock -> V_55 ;
}
static void F_25 ( struct V_1 * V_2 , int V_25 , T_3 * clock )
{
if ( F_21 ( V_2 ) ) {
F_24 ( V_25 , clock ) ;
return;
}
clock -> V_53 = 5 * ( clock -> V_61 + 2 ) + ( clock -> V_54 + 2 ) ;
clock -> V_55 = clock -> V_56 * clock -> V_57 ;
clock -> V_58 = V_25 * clock -> V_53 / ( clock -> V_59 + 2 ) ;
clock -> V_60 = clock -> V_58 / clock -> V_55 ;
}
bool F_16 ( struct V_23 * V_24 , int type )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_62 * V_63 ;
F_26 (dev, crtc, encoder)
if ( V_63 -> type == type )
return true ;
return false ;
}
static bool F_27 ( struct V_1 * V_2 ,
const T_2 * V_26 ,
const T_3 * clock )
{
if ( clock -> V_56 < V_26 -> V_56 . V_64 || V_26 -> V_56 . V_65 < clock -> V_56 )
F_28 ( L_4 ) ;
if ( clock -> V_55 < V_26 -> V_55 . V_64 || V_26 -> V_55 . V_65 < clock -> V_55 )
F_28 ( L_5 ) ;
if ( clock -> V_54 < V_26 -> V_54 . V_64 || V_26 -> V_54 . V_65 < clock -> V_54 )
F_28 ( L_6 ) ;
if ( clock -> V_61 < V_26 -> V_61 . V_64 || V_26 -> V_61 . V_65 < clock -> V_61 )
F_28 ( L_7 ) ;
if ( clock -> V_61 <= clock -> V_54 && ! F_21 ( V_2 ) )
F_28 ( L_8 ) ;
if ( clock -> V_53 < V_26 -> V_53 . V_64 || V_26 -> V_53 . V_65 < clock -> V_53 )
F_28 ( L_9 ) ;
if ( clock -> V_59 < V_26 -> V_59 . V_64 || V_26 -> V_59 . V_65 < clock -> V_59 )
F_28 ( L_10 ) ;
if ( clock -> V_58 < V_26 -> V_58 . V_64 || V_26 -> V_58 . V_65 < clock -> V_58 )
F_28 ( L_11 ) ;
if ( clock -> V_60 < V_26 -> V_60 . V_64 || V_26 -> V_60 . V_65 < clock -> V_60 )
F_28 ( L_12 ) ;
return true ;
}
static bool
F_29 ( const T_2 * V_26 , struct V_23 * V_24 ,
int V_66 , int V_25 , T_3 * V_67 ,
T_3 * V_68 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
T_3 clock ;
int V_69 = V_66 ;
if ( F_16 ( V_24 , V_27 ) ) {
if ( F_17 ( V_2 ) )
clock . V_57 = V_26 -> V_57 . V_70 ;
else
clock . V_57 = V_26 -> V_57 . V_71 ;
} else {
if ( V_66 < V_26 -> V_57 . V_72 )
clock . V_57 = V_26 -> V_57 . V_71 ;
else
clock . V_57 = V_26 -> V_57 . V_70 ;
}
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
for ( clock . V_61 = V_26 -> V_61 . V_64 ; clock . V_61 <= V_26 -> V_61 . V_65 ;
clock . V_61 ++ ) {
for ( clock . V_54 = V_26 -> V_54 . V_64 ;
clock . V_54 <= V_26 -> V_54 . V_65 ; clock . V_54 ++ ) {
if ( clock . V_54 >= clock . V_61 && ! F_21 ( V_2 ) )
break;
for ( clock . V_59 = V_26 -> V_59 . V_64 ;
clock . V_59 <= V_26 -> V_59 . V_65 ; clock . V_59 ++ ) {
for ( clock . V_56 = V_26 -> V_56 . V_64 ;
clock . V_56 <= V_26 -> V_56 . V_65 ; clock . V_56 ++ ) {
int V_73 ;
F_25 ( V_2 , V_25 , & clock ) ;
if ( ! F_27 ( V_2 , V_26 ,
& clock ) )
continue;
if ( V_67 &&
clock . V_55 != V_67 -> V_55 )
continue;
V_73 = abs ( clock . V_60 - V_66 ) ;
if ( V_73 < V_69 ) {
* V_68 = clock ;
V_69 = V_73 ;
}
}
}
}
}
return ( V_69 != V_66 ) ;
}
static bool
F_30 ( const T_2 * V_26 , struct V_23 * V_24 ,
int V_66 , int V_25 , T_3 * V_67 ,
T_3 * V_68 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
T_3 clock ;
int V_74 ;
bool V_75 ;
int V_76 = ( V_66 >> 8 ) + ( V_66 >> 9 ) ;
V_75 = false ;
if ( F_16 ( V_24 , V_27 ) ) {
int V_77 ;
if ( F_3 ( V_2 ) )
V_77 = V_78 ;
else
V_77 = V_79 ;
if ( F_17 ( V_2 ) )
clock . V_57 = V_26 -> V_57 . V_70 ;
else
clock . V_57 = V_26 -> V_57 . V_71 ;
} else {
if ( V_66 < V_26 -> V_57 . V_72 )
clock . V_57 = V_26 -> V_57 . V_71 ;
else
clock . V_57 = V_26 -> V_57 . V_70 ;
}
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
V_74 = V_26 -> V_59 . V_65 ;
for ( clock . V_59 = V_26 -> V_59 . V_64 ; clock . V_59 <= V_74 ; clock . V_59 ++ ) {
for ( clock . V_61 = V_26 -> V_61 . V_65 ;
clock . V_61 >= V_26 -> V_61 . V_64 ; clock . V_61 -- ) {
for ( clock . V_54 = V_26 -> V_54 . V_65 ;
clock . V_54 >= V_26 -> V_54 . V_64 ; clock . V_54 -- ) {
for ( clock . V_56 = V_26 -> V_56 . V_65 ;
clock . V_56 >= V_26 -> V_56 . V_64 ; clock . V_56 -- ) {
int V_73 ;
F_25 ( V_2 , V_25 , & clock ) ;
if ( ! F_27 ( V_2 , V_26 ,
& clock ) )
continue;
if ( V_67 &&
clock . V_55 != V_67 -> V_55 )
continue;
V_73 = abs ( clock . V_60 - V_66 ) ;
if ( V_73 < V_76 ) {
* V_68 = clock ;
V_76 = V_73 ;
V_74 = clock . V_59 ;
V_75 = true ;
}
}
}
}
}
return V_75 ;
}
static bool
F_31 ( const T_2 * V_26 , struct V_23 * V_24 ,
int V_66 , int V_25 , T_3 * V_67 ,
T_3 * V_68 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
T_3 clock ;
if ( V_66 < 200000 ) {
clock . V_59 = 1 ;
clock . V_56 = 2 ;
clock . V_57 = 10 ;
clock . V_61 = 12 ;
clock . V_54 = 9 ;
} else {
clock . V_59 = 2 ;
clock . V_56 = 1 ;
clock . V_57 = 10 ;
clock . V_61 = 14 ;
clock . V_54 = 8 ;
}
F_25 ( V_2 , V_25 , & clock ) ;
memcpy ( V_68 , & clock , sizeof( T_3 ) ) ;
return true ;
}
static bool
F_32 ( const T_2 * V_26 , struct V_23 * V_24 ,
int V_66 , int V_25 , T_3 * V_67 ,
T_3 * V_68 )
{
T_3 clock ;
if ( V_66 < 200000 ) {
clock . V_56 = 2 ;
clock . V_57 = 10 ;
clock . V_59 = 2 ;
clock . V_61 = 23 ;
clock . V_54 = 8 ;
} else {
clock . V_56 = 1 ;
clock . V_57 = 10 ;
clock . V_59 = 1 ;
clock . V_61 = 14 ;
clock . V_54 = 2 ;
}
clock . V_53 = 5 * ( clock . V_61 + 2 ) + ( clock . V_54 + 2 ) ;
clock . V_55 = ( clock . V_56 * clock . V_57 ) ;
clock . V_60 = 96000 * clock . V_53 / ( clock . V_59 + 2 ) / clock . V_55 ;
clock . V_58 = 0 ;
memcpy ( V_68 , & clock , sizeof( T_3 ) ) ;
return true ;
}
static bool
F_33 ( const T_2 * V_26 , struct V_23 * V_24 ,
int V_66 , int V_25 , T_3 * V_67 ,
T_3 * V_68 )
{
T_1 V_56 , V_57 , V_61 , V_54 , V_58 , V_80 , V_81 , V_82 , V_83 , V_84 ;
T_1 V_53 , V_59 , V_85 ;
T_1 V_86 , V_87 , V_88 , V_55 ;
unsigned long V_89 , V_90 , V_91 ;
int V_92 , V_93 ;
V_93 = 0 ;
V_92 = V_66 * 1000 ;
V_89 = 1000000 ;
V_90 = V_91 = 0 ;
V_85 = V_92 / ( 2 * 100 ) ;
V_86 = 0 ;
V_87 = 19200 ;
V_88 = 1 ;
V_59 = V_55 = V_56 = V_57 = V_53 = V_61 = V_54 = V_58 = V_80 = 0 ;
V_81 = V_82 = V_83 = V_84 = 0 ;
for ( V_59 = V_26 -> V_59 . V_64 ; V_59 <= ( ( V_25 ) / V_87 ) ; V_59 ++ ) {
V_86 = V_25 / V_59 ;
for ( V_56 = V_26 -> V_56 . V_65 ; V_56 > V_26 -> V_56 . V_64 ; V_56 -- ) {
for ( V_57 = V_26 -> V_57 . V_70 + 1 ; V_57 > 0 ; V_57 -- ) {
if ( V_57 > 10 )
V_57 = V_57 - 1 ;
V_55 = V_56 * V_57 ;
for ( V_61 = V_26 -> V_61 . V_64 ; V_61 <= V_26 -> V_61 . V_65 ; V_61 ++ ) {
V_54 = ( ( ( 2 * ( V_85 * V_55 * V_59 / V_61 ) ) +
V_25 ) / ( 2 * V_25 ) ) ;
V_53 = V_61 * V_54 ;
V_58 = V_86 * V_53 ;
if ( V_58 >= V_26 -> V_58 . V_64 && V_58 < V_26 -> V_58 . V_65 ) {
V_90 = 1000000 * ( ( V_58 / V_55 ) - V_85 ) / V_85 ;
V_91 = ( V_90 > 0 ) ? V_90 : ( - V_90 ) ;
if ( V_91 < 100 && ( ( V_56 * V_57 ) > ( V_83 * V_84 ) ) ) {
V_89 = 0 ;
V_93 = 1 ;
}
if ( V_91 < V_89 - 10 ) {
V_89 = V_91 ;
V_93 = 1 ;
}
if ( V_93 ) {
V_80 = V_59 ;
V_81 = V_61 ;
V_82 = V_54 ;
V_83 = V_56 ;
V_84 = V_57 ;
V_93 = 0 ;
}
}
}
}
}
}
V_68 -> V_59 = V_80 ;
V_68 -> V_61 = V_81 ;
V_68 -> V_54 = V_82 ;
V_68 -> V_56 = V_83 ;
V_68 -> V_57 = V_84 ;
return true ;
}
enum V_94 F_34 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
struct V_23 * V_24 = V_4 -> V_96 [ V_95 ] ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
return V_97 -> V_98 ;
}
static void F_36 ( struct V_1 * V_2 , int V_95 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_99 , V_100 = F_37 ( V_95 ) ;
V_99 = F_4 ( V_100 ) ;
if ( F_38 ( F_39 ( V_100 ) != V_99 , 50 ) )
F_40 ( L_13 ) ;
}
void F_41 ( struct V_1 * V_2 , int V_95 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_101 = F_42 ( V_95 ) ;
if ( F_43 ( V_2 ) -> V_102 >= 5 ) {
F_36 ( V_2 , V_95 ) ;
return;
}
F_11 ( V_101 ,
F_4 ( V_101 ) | V_103 ) ;
if ( F_38 ( F_4 ( V_101 ) &
V_103 ,
50 ) )
F_40 ( L_13 ) ;
}
void F_44 ( struct V_1 * V_2 , int V_95 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_94 V_98 = F_34 ( V_4 ,
V_95 ) ;
if ( F_43 ( V_2 ) -> V_102 >= 4 ) {
int V_10 = F_45 ( V_98 ) ;
if ( F_38 ( ( F_4 ( V_10 ) & V_104 ) == 0 ,
100 ) )
F_46 ( 1 , L_14 ) ;
} else {
T_1 V_105 , V_106 ;
int V_10 = F_47 ( V_95 ) ;
unsigned long V_107 = V_108 + F_48 ( 100 ) ;
if ( F_23 ( V_2 ) )
V_106 = V_109 ;
else
V_106 = V_110 ;
do {
V_105 = F_4 ( V_10 ) & V_106 ;
F_49 ( 5 ) ;
} while ( ( ( F_4 ( V_10 ) & V_106 ) != V_105 ) &&
F_50 ( V_107 , V_108 ) );
if ( F_50 ( V_108 , V_107 ) )
F_46 ( 1 , L_14 ) ;
}
}
bool F_51 ( struct V_3 * V_4 ,
struct V_111 * V_112 )
{
T_1 V_113 ;
if ( F_52 ( V_4 -> V_2 ) ) {
switch( V_112 -> V_112 ) {
case V_114 :
V_113 = V_115 ;
break;
case V_116 :
V_113 = V_117 ;
break;
case V_118 :
V_113 = V_119 ;
break;
default:
return true ;
}
} else {
switch( V_112 -> V_112 ) {
case V_114 :
V_113 = V_120 ;
break;
case V_116 :
V_113 = V_121 ;
break;
case V_118 :
V_113 = V_122 ;
break;
default:
return true ;
}
}
return F_4 ( V_123 ) & V_113 ;
}
static const char * F_53 ( bool V_124 )
{
return V_124 ? L_15 : L_16 ;
}
static void F_54 ( struct V_3 * V_4 ,
enum V_95 V_95 , bool V_125 )
{
int V_10 ;
T_1 V_20 ;
bool V_126 ;
V_10 = F_55 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_126 = ! ! ( V_20 & V_127 ) ;
F_46 ( V_126 != V_125 ,
L_17 ,
F_53 ( V_125 ) , F_53 ( V_126 ) ) ;
}
static void F_56 ( struct V_3 * V_4 ,
struct V_128 * V_129 ,
struct V_97 * V_24 ,
bool V_125 )
{
T_1 V_20 ;
bool V_126 ;
if ( F_57 ( V_4 -> V_2 ) ) {
F_58 ( L_18 ) ;
return;
}
if ( F_46 ( ! V_129 ,
L_19 , F_53 ( V_125 ) ) )
return;
V_20 = F_4 ( V_129 -> V_130 ) ;
V_126 = ! ! ( V_20 & V_127 ) ;
F_46 ( V_126 != V_125 ,
L_20 ,
V_129 -> V_130 , F_53 ( V_125 ) , F_53 ( V_126 ) , V_20 ) ;
if ( V_24 && F_59 ( V_4 -> V_2 ) ) {
T_1 V_131 ;
V_131 = F_4 ( V_132 ) ;
V_126 = V_129 -> V_130 == V_133 ;
if ( ! F_46 ( ( ( V_131 >> ( 4 * V_24 -> V_95 ) ) & 1 ) != V_126 ,
L_21 ,
V_126 , V_24 -> V_95 , V_131 ) ) {
V_126 = ! ! ( V_20 >> ( 4 * V_24 -> V_95 + 3 ) ) ;
F_46 ( V_126 != V_125 ,
L_22 ,
V_129 -> V_130 == V_133 ,
F_53 ( V_125 ) ,
V_24 -> V_95 ,
V_20 ) ;
}
}
}
static void F_60 ( struct V_3 * V_4 ,
enum V_95 V_95 , bool V_125 )
{
int V_10 ;
T_1 V_20 ;
bool V_126 ;
enum V_94 V_98 = F_34 ( V_4 ,
V_95 ) ;
if ( F_61 ( V_4 -> V_2 ) ) {
V_10 = F_62 ( V_98 ) ;
V_20 = F_4 ( V_10 ) ;
V_126 = ! ! ( V_20 & V_134 ) ;
} else {
V_10 = F_63 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_126 = ! ! ( V_20 & V_135 ) ;
}
F_46 ( V_126 != V_125 ,
L_23 ,
F_53 ( V_125 ) , F_53 ( V_126 ) ) ;
}
static void F_64 ( struct V_3 * V_4 ,
enum V_95 V_95 , bool V_125 )
{
int V_10 ;
T_1 V_20 ;
bool V_126 ;
V_10 = F_65 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_126 = ! ! ( V_20 & V_136 ) ;
F_46 ( V_126 != V_125 ,
L_24 ,
F_53 ( V_125 ) , F_53 ( V_126 ) ) ;
}
static void F_66 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
if ( V_4 -> V_137 -> V_102 == 5 )
return;
if ( F_61 ( V_4 -> V_2 ) )
return;
V_10 = F_63 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
F_46 ( ! ( V_20 & V_138 ) , L_25 ) ;
}
static void F_67 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
V_10 = F_65 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
F_46 ( ! ( V_20 & V_139 ) , L_26 ) ;
}
static void F_68 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
int V_140 , V_77 ;
T_1 V_20 ;
enum V_95 V_141 = V_142 ;
bool V_143 = true ;
if ( F_3 ( V_4 -> V_2 ) ) {
V_140 = V_144 ;
V_77 = V_78 ;
} else {
V_140 = V_145 ;
V_77 = V_79 ;
}
V_20 = F_4 ( V_140 ) ;
if ( ! ( V_20 & V_146 ) ||
( ( V_20 & V_147 ) == V_147 ) )
V_143 = false ;
if ( F_4 ( V_77 ) & V_148 )
V_141 = V_149 ;
F_46 ( V_141 == V_95 && V_143 ,
L_27 ,
F_69 ( V_95 ) ) ;
}
void F_70 ( struct V_3 * V_4 ,
enum V_95 V_95 , bool V_125 )
{
int V_10 ;
T_1 V_20 ;
bool V_126 ;
enum V_94 V_98 = F_34 ( V_4 ,
V_95 ) ;
if ( V_95 == V_142 && V_4 -> V_150 & V_151 )
V_125 = true ;
if ( F_71 ( V_4 -> V_2 ) && V_98 != V_152 &&
! ( F_4 ( V_153 ) & V_154 ) ) {
V_126 = false ;
} else {
V_10 = F_45 ( V_98 ) ;
V_20 = F_4 ( V_10 ) ;
V_126 = ! ! ( V_20 & V_155 ) ;
}
F_46 ( V_126 != V_125 ,
L_28 ,
F_69 ( V_95 ) , F_53 ( V_125 ) , F_53 ( V_126 ) ) ;
}
static void F_72 ( struct V_3 * V_4 ,
enum V_156 V_156 , bool V_125 )
{
int V_10 ;
T_1 V_20 ;
bool V_126 ;
V_10 = F_73 ( V_156 ) ;
V_20 = F_4 ( V_10 ) ;
V_126 = ! ! ( V_20 & V_157 ) ;
F_46 ( V_126 != V_125 ,
L_29 ,
F_74 ( V_156 ) , F_53 ( V_125 ) , F_53 ( V_126 ) ) ;
}
static void F_75 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
int V_10 , V_158 ;
T_1 V_20 ;
int V_159 ;
if ( F_3 ( V_4 -> V_2 ) ) {
V_10 = F_73 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
F_46 ( ( V_20 & V_157 ) ,
L_30 ,
F_74 ( V_95 ) ) ;
return;
}
for ( V_158 = 0 ; V_158 < 2 ; V_158 ++ ) {
V_10 = F_73 ( V_158 ) ;
V_20 = F_4 ( V_10 ) ;
V_159 = ( V_20 & V_160 ) >>
V_161 ;
F_46 ( ( V_20 & V_157 ) && V_95 == V_159 ,
L_31 ,
F_74 ( V_158 ) , F_69 ( V_95 ) ) ;
}
}
static void F_76 ( struct V_3 * V_4 )
{
T_1 V_20 ;
bool V_124 ;
if ( F_57 ( V_4 -> V_2 ) ) {
F_58 ( L_32 ) ;
return;
}
V_20 = F_4 ( V_162 ) ;
V_124 = ! ! ( V_20 & ( V_163 | V_164 |
V_165 ) ) ;
F_46 ( ! V_124 , L_33 ) ;
}
static void F_77 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
bool V_124 ;
V_10 = F_78 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_124 = ! ! ( V_20 & V_166 ) ;
F_46 ( V_124 ,
L_34 ,
F_69 ( V_95 ) ) ;
}
static bool F_79 ( struct V_3 * V_4 ,
enum V_95 V_95 , T_1 V_167 , T_1 V_20 )
{
if ( ( V_20 & V_168 ) == 0 )
return false ;
if ( F_59 ( V_4 -> V_2 ) ) {
T_1 V_169 = F_80 ( V_95 ) ;
T_1 V_170 = F_4 ( V_169 ) ;
if ( ( V_170 & V_171 ) != V_167 )
return false ;
} else {
if ( ( V_20 & V_172 ) != ( V_95 << 30 ) )
return false ;
}
return true ;
}
static bool F_81 ( struct V_3 * V_4 ,
enum V_95 V_95 , T_1 V_20 )
{
if ( ( V_20 & V_173 ) == 0 )
return false ;
if ( F_59 ( V_4 -> V_2 ) ) {
if ( ( V_20 & V_174 ) != F_82 ( V_95 ) )
return false ;
} else {
if ( ( V_20 & V_175 ) != F_83 ( V_95 ) )
return false ;
}
return true ;
}
static bool F_84 ( struct V_3 * V_4 ,
enum V_95 V_95 , T_1 V_20 )
{
if ( ( V_20 & V_176 ) == 0 )
return false ;
if ( F_59 ( V_4 -> V_2 ) ) {
if ( ( V_20 & V_174 ) != F_82 ( V_95 ) )
return false ;
} else {
if ( ( V_20 & V_177 ) != F_85 ( V_95 ) )
return false ;
}
return true ;
}
static bool F_86 ( struct V_3 * V_4 ,
enum V_95 V_95 , T_1 V_20 )
{
if ( ( V_20 & V_178 ) == 0 )
return false ;
if ( F_59 ( V_4 -> V_2 ) ) {
if ( ( V_20 & V_174 ) != F_82 ( V_95 ) )
return false ;
} else {
if ( ( V_20 & V_179 ) != F_87 ( V_95 ) )
return false ;
}
return true ;
}
static void F_88 ( struct V_3 * V_4 ,
enum V_95 V_95 , int V_10 , T_1 V_167 )
{
T_1 V_20 = F_4 ( V_10 ) ;
F_46 ( F_79 ( V_4 , V_95 , V_167 , V_20 ) ,
L_35 ,
V_10 , F_69 ( V_95 ) ) ;
F_46 ( F_52 ( V_4 -> V_2 ) && ( V_20 & V_168 ) == 0
&& ( V_20 & V_180 ) ,
L_36 ) ;
}
static void F_89 ( struct V_3 * V_4 ,
enum V_95 V_95 , int V_10 )
{
T_1 V_20 = F_4 ( V_10 ) ;
F_46 ( F_81 ( V_4 , V_95 , V_20 ) ,
L_37 ,
V_10 , F_69 ( V_95 ) ) ;
F_46 ( F_52 ( V_4 -> V_2 ) && ( V_20 & V_173 ) == 0
&& ( V_20 & V_181 ) ,
L_38 ) ;
}
static void F_90 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
F_88 ( V_4 , V_95 , V_182 , V_183 ) ;
F_88 ( V_4 , V_95 , V_184 , V_185 ) ;
F_88 ( V_4 , V_95 , V_186 , V_187 ) ;
V_10 = V_188 ;
V_20 = F_4 ( V_10 ) ;
F_46 ( F_86 ( V_4 , V_95 , V_20 ) ,
L_39 ,
F_69 ( V_95 ) ) ;
V_10 = V_78 ;
V_20 = F_4 ( V_10 ) ;
F_46 ( F_84 ( V_4 , V_95 , V_20 ) ,
L_40 ,
F_69 ( V_95 ) ) ;
F_89 ( V_4 , V_95 , V_189 ) ;
F_89 ( V_4 , V_95 , V_190 ) ;
F_89 ( V_4 , V_95 , V_191 ) ;
}
static void F_91 ( struct V_3 * V_4 , enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
F_92 ( ! F_22 ( V_4 -> V_2 ) && V_4 -> V_137 -> V_102 >= 5 ) ;
if ( F_93 ( V_4 -> V_2 ) && ! F_94 ( V_4 -> V_2 ) )
F_68 ( V_4 , V_95 ) ;
V_10 = F_55 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_20 |= V_127 ;
F_11 ( V_10 , V_20 ) ;
F_14 ( V_10 ) ;
F_95 ( 150 ) ;
F_11 ( V_10 , V_20 ) ;
F_14 ( V_10 ) ;
F_95 ( 150 ) ;
F_11 ( V_10 , V_20 ) ;
F_14 ( V_10 ) ;
F_95 ( 150 ) ;
}
static void F_96 ( struct V_3 * V_4 , enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
if ( V_95 == V_142 && ( V_4 -> V_150 & V_151 ) )
return;
F_97 ( V_4 , V_95 ) ;
V_10 = F_55 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_20 &= ~ V_127 ;
F_11 ( V_10 , V_20 ) ;
F_14 ( V_10 ) ;
}
static void
F_98 ( struct V_3 * V_4 , T_4 V_10 , T_1 V_192 ,
enum V_193 V_194 )
{
T_1 V_195 ;
F_2 ( ! F_8 ( & V_4 -> V_11 ) ) ;
if ( F_38 ( ( F_4 ( V_196 ) & V_197 ) == 0 ,
100 ) ) {
F_10 ( L_41 ) ;
return;
}
F_11 ( V_198 , ( V_10 << 16 ) ) ;
F_11 ( V_199 , V_192 ) ;
if ( V_194 == V_200 )
V_195 = V_201 | V_202 ;
else
V_195 = V_203 | V_204 ;
F_11 ( V_196 , V_197 | V_195 ) ;
if ( F_38 ( ( F_4 ( V_196 ) & ( V_197 | V_205 ) ) == 0 ,
100 ) ) {
F_10 ( L_42 ) ;
return;
}
}
static T_1
F_99 ( struct V_3 * V_4 , T_4 V_10 ,
enum V_193 V_194 )
{
T_1 V_192 = 0 ;
F_2 ( ! F_8 ( & V_4 -> V_11 ) ) ;
if ( F_38 ( ( F_4 ( V_196 ) & V_197 ) == 0 ,
100 ) ) {
F_10 ( L_41 ) ;
return 0 ;
}
F_11 ( V_198 , ( V_10 << 16 ) ) ;
if ( V_194 == V_200 )
V_192 = V_201 | V_206 ;
else
V_192 = V_203 | V_207 ;
F_11 ( V_196 , V_192 | V_197 ) ;
if ( F_38 ( ( F_4 ( V_196 ) & ( V_197 | V_205 ) ) == 0 ,
100 ) ) {
F_10 ( L_43 ) ;
return 0 ;
}
return F_4 ( V_199 ) ;
}
static void F_100 ( struct V_97 * V_97 )
{
struct V_3 * V_4 = V_97 -> V_208 . V_2 -> V_5 ;
struct V_128 * V_129 ;
int V_10 ;
T_1 V_20 ;
F_92 ( V_4 -> V_137 -> V_102 < 5 ) ;
V_129 = V_97 -> V_209 ;
if ( V_129 == NULL )
return;
if ( F_2 ( V_129 -> V_210 == 0 ) )
return;
F_40 ( L_44 ,
V_129 -> V_130 , V_129 -> V_211 , V_129 -> V_212 ,
V_97 -> V_208 . V_208 . V_213 ) ;
F_76 ( V_4 ) ;
if ( V_129 -> V_211 ++ && V_129 -> V_212 ) {
F_101 ( V_4 , V_129 , NULL ) ;
return;
}
F_40 ( L_45 , V_129 -> V_130 ) ;
V_10 = V_129 -> V_130 ;
V_20 = F_4 ( V_10 ) ;
V_20 |= V_127 ;
F_11 ( V_10 , V_20 ) ;
F_14 ( V_10 ) ;
F_95 ( 200 ) ;
V_129 -> V_212 = true ;
}
static void F_102 ( struct V_97 * V_97 )
{
struct V_3 * V_4 = V_97 -> V_208 . V_2 -> V_5 ;
struct V_128 * V_129 = V_97 -> V_209 ;
int V_10 ;
T_1 V_20 ;
F_92 ( V_4 -> V_137 -> V_102 < 5 ) ;
if ( V_129 == NULL )
return;
if ( F_2 ( V_129 -> V_210 == 0 ) )
return;
F_40 ( L_46 ,
V_129 -> V_130 , V_129 -> V_211 , V_129 -> V_212 ,
V_97 -> V_208 . V_208 . V_213 ) ;
if ( F_2 ( V_129 -> V_211 == 0 ) ) {
F_103 ( V_4 , V_129 , NULL ) ;
return;
}
if ( -- V_129 -> V_211 ) {
F_101 ( V_4 , V_129 , NULL ) ;
return;
}
F_40 ( L_47 , V_129 -> V_130 ) ;
F_77 ( V_4 , V_97 -> V_95 ) ;
V_10 = V_129 -> V_130 ;
V_20 = F_4 ( V_10 ) ;
V_20 &= ~ V_127 ;
F_11 ( V_10 , V_20 ) ;
F_14 ( V_10 ) ;
F_95 ( 200 ) ;
V_129 -> V_212 = false ;
}
static void F_104 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_23 * V_24 = V_4 -> V_96 [ V_95 ] ;
T_5 V_10 , V_20 , V_214 ;
F_92 ( V_4 -> V_137 -> V_102 < 5 ) ;
F_101 ( V_4 ,
F_35 ( V_24 ) -> V_209 ,
F_35 ( V_24 ) ) ;
F_105 ( V_4 , V_95 ) ;
F_106 ( V_4 , V_95 ) ;
if ( F_59 ( V_2 ) ) {
V_10 = F_107 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_20 |= V_215 ;
F_11 ( V_10 , V_20 ) ;
}
V_10 = F_78 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_214 = F_4 ( F_45 ( V_95 ) ) ;
if ( F_52 ( V_4 -> V_2 ) ) {
V_20 &= ~ V_216 ;
V_20 |= V_214 & V_216 ;
}
V_20 &= ~ V_217 ;
if ( ( V_214 & V_218 ) == V_219 )
if ( F_52 ( V_4 -> V_2 ) &&
F_16 ( V_24 , V_41 ) )
V_20 |= V_220 ;
else
V_20 |= V_221 ;
else
V_20 |= V_222 ;
F_11 ( V_10 , V_20 | V_166 ) ;
if ( F_38 ( F_4 ( V_10 ) & V_223 , 100 ) )
F_10 ( L_48 , V_95 ) ;
}
static void F_108 ( struct V_3 * V_4 ,
enum V_94 V_98 )
{
T_1 V_20 , V_214 ;
F_92 ( V_4 -> V_137 -> V_102 < 5 ) ;
F_105 ( V_4 , (enum V_95 ) V_98 ) ;
F_106 ( V_4 , V_224 ) ;
V_20 = F_4 ( V_225 ) ;
V_20 |= V_215 ;
F_11 ( V_225 , V_20 ) ;
V_20 = V_166 ;
V_214 = F_4 ( F_45 ( V_98 ) ) ;
if ( ( V_214 & V_226 ) ==
V_219 )
V_20 |= V_221 ;
else
V_20 |= V_222 ;
F_11 ( F_78 ( V_224 ) , V_20 ) ;
if ( F_38 ( F_4 ( V_227 ) & V_223 , 100 ) )
F_10 ( L_49 ) ;
}
static void F_109 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_5 V_10 , V_20 ;
F_110 ( V_4 , V_95 ) ;
F_111 ( V_4 , V_95 ) ;
F_90 ( V_4 , V_95 ) ;
V_10 = F_78 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_20 &= ~ V_166 ;
F_11 ( V_10 , V_20 ) ;
if ( F_38 ( ( F_4 ( V_10 ) & V_223 ) == 0 , 50 ) )
F_10 ( L_50 , V_95 ) ;
if ( ! F_52 ( V_2 ) ) {
V_10 = F_107 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_20 &= ~ V_215 ;
F_11 ( V_10 , V_20 ) ;
}
}
static void F_112 ( struct V_3 * V_4 )
{
T_1 V_20 ;
V_20 = F_4 ( V_227 ) ;
V_20 &= ~ V_166 ;
F_11 ( V_227 , V_20 ) ;
if ( F_38 ( ( F_4 ( V_227 ) & V_223 ) == 0 , 50 ) )
F_10 ( L_51 ) ;
V_20 = F_4 ( V_225 ) ;
V_20 &= ~ V_215 ;
F_11 ( V_225 , V_20 ) ;
}
static void F_113 ( struct V_3 * V_4 , enum V_95 V_95 ,
bool V_228 )
{
enum V_94 V_98 = F_34 ( V_4 ,
V_95 ) ;
enum V_95 V_229 ;
int V_10 ;
T_1 V_20 ;
if ( F_57 ( V_4 -> V_2 ) )
V_229 = V_224 ;
else
V_229 = V_95 ;
if ( ! F_3 ( V_4 -> V_2 ) )
F_114 ( V_4 , V_95 ) ;
else {
if ( V_228 ) {
F_67 ( V_4 , V_229 ) ;
F_66 ( V_4 ,
(enum V_95 ) V_98 ) ;
}
}
V_10 = F_45 ( V_98 ) ;
V_20 = F_4 ( V_10 ) ;
if ( V_20 & V_155 )
return;
F_11 ( V_10 , V_20 | V_155 ) ;
F_41 ( V_4 -> V_2 , V_95 ) ;
}
static void F_115 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
enum V_94 V_98 = F_34 ( V_4 ,
V_95 ) ;
int V_10 ;
T_1 V_20 ;
F_75 ( V_4 , V_95 ) ;
if ( V_95 == V_142 && ( V_4 -> V_150 & V_151 ) )
return;
V_10 = F_45 ( V_98 ) ;
V_20 = F_4 ( V_10 ) ;
if ( ( V_20 & V_155 ) == 0 )
return;
F_11 ( V_10 , V_20 & ~ V_155 ) ;
F_44 ( V_4 -> V_2 , V_95 ) ;
}
void F_116 ( struct V_3 * V_4 ,
enum V_156 V_156 )
{
if ( V_4 -> V_137 -> V_102 >= 4 )
F_11 ( F_117 ( V_156 ) , F_4 ( F_117 ( V_156 ) ) ) ;
else
F_11 ( F_118 ( V_156 ) , F_4 ( F_118 ( V_156 ) ) ) ;
}
static void F_119 ( struct V_3 * V_4 ,
enum V_156 V_156 , enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
F_120 ( V_4 , V_95 ) ;
V_10 = F_73 ( V_156 ) ;
V_20 = F_4 ( V_10 ) ;
if ( V_20 & V_157 )
return;
F_11 ( V_10 , V_20 | V_157 ) ;
F_116 ( V_4 , V_156 ) ;
F_41 ( V_4 -> V_2 , V_95 ) ;
}
static void F_121 ( struct V_3 * V_4 ,
enum V_156 V_156 , enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
V_10 = F_73 ( V_156 ) ;
V_20 = F_4 ( V_10 ) ;
if ( ( V_20 & V_157 ) == 0 )
return;
F_11 ( V_10 , V_20 & ~ V_157 ) ;
F_116 ( V_4 , V_156 ) ;
F_41 ( V_4 -> V_2 , V_95 ) ;
}
int
F_122 ( struct V_1 * V_2 ,
struct V_230 * V_231 ,
struct V_232 * V_233 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_234 ;
int V_235 ;
switch ( V_231 -> V_236 ) {
case V_237 :
if ( F_123 ( V_2 ) || F_124 ( V_2 ) )
V_234 = 128 * 1024 ;
else if ( F_43 ( V_2 ) -> V_102 >= 4 )
V_234 = 4 * 1024 ;
else
V_234 = 64 * 1024 ;
break;
case V_238 :
V_234 = 0 ;
break;
case V_239 :
F_10 ( L_52 ) ;
return - V_240 ;
default:
F_125 () ;
}
V_4 -> V_241 . V_242 = false ;
V_235 = F_126 ( V_231 , V_234 , V_233 ) ;
if ( V_235 )
goto V_243;
V_235 = F_127 ( V_231 ) ;
if ( V_235 )
goto V_244;
F_128 ( V_231 ) ;
V_4 -> V_241 . V_242 = true ;
return 0 ;
V_244:
F_129 ( V_231 ) ;
V_243:
V_4 -> V_241 . V_242 = true ;
return V_235 ;
}
void F_130 ( struct V_230 * V_231 )
{
F_131 ( V_231 ) ;
F_129 ( V_231 ) ;
}
unsigned long F_132 ( int * V_245 , int * V_246 ,
unsigned int V_236 ,
unsigned int V_247 ,
unsigned int V_248 )
{
if ( V_236 != V_237 ) {
unsigned int V_249 , V_250 ;
V_249 = * V_246 / 8 ;
* V_246 %= 8 ;
V_250 = * V_245 / ( 512 / V_247 ) ;
* V_245 %= 512 / V_247 ;
return V_249 * V_248 * 8 + V_250 * 4096 ;
} else {
unsigned int V_251 ;
V_251 = * V_246 * V_248 + * V_245 * V_247 ;
* V_246 = 0 ;
* V_245 = ( V_251 & 4095 ) / V_247 ;
return V_251 & - 4096 ;
}
}
static int F_133 ( struct V_23 * V_24 , struct V_252 * V_253 ,
int V_245 , int V_246 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_254 * V_255 ;
struct V_230 * V_231 ;
int V_156 = V_97 -> V_156 ;
unsigned long V_256 ;
T_1 V_257 ;
T_1 V_10 ;
switch ( V_156 ) {
case 0 :
case 1 :
break;
default:
F_10 ( L_53 , V_156 ) ;
return - V_240 ;
}
V_255 = F_134 ( V_253 ) ;
V_231 = V_255 -> V_231 ;
V_10 = F_73 ( V_156 ) ;
V_257 = F_4 ( V_10 ) ;
V_257 &= ~ V_258 ;
switch ( V_253 -> V_259 ) {
case V_260 :
V_257 |= V_261 ;
break;
case V_262 :
case V_263 :
V_257 |= V_264 ;
break;
case V_265 :
V_257 |= V_266 ;
break;
case V_267 :
case V_268 :
V_257 |= V_269 ;
break;
case V_270 :
case V_271 :
V_257 |= V_272 ;
break;
case V_273 :
case V_274 :
V_257 |= V_275 ;
break;
case V_276 :
case V_277 :
V_257 |= V_278 ;
break;
default:
F_10 ( L_54 , V_253 -> V_259 ) ;
return - V_240 ;
}
if ( F_43 ( V_2 ) -> V_102 >= 4 ) {
if ( V_231 -> V_236 != V_237 )
V_257 |= V_279 ;
else
V_257 &= ~ V_279 ;
}
F_11 ( V_10 , V_257 ) ;
V_256 = V_246 * V_253 -> V_280 [ 0 ] + V_245 * ( V_253 -> V_281 / 8 ) ;
if ( F_43 ( V_2 ) -> V_102 >= 4 ) {
V_97 -> V_282 =
F_132 ( & V_245 , & V_246 , V_231 -> V_236 ,
V_253 -> V_281 / 8 ,
V_253 -> V_280 [ 0 ] ) ;
V_256 -= V_97 -> V_282 ;
} else {
V_97 -> V_282 = V_256 ;
}
F_40 ( L_55 ,
V_231 -> V_283 , V_256 , V_245 , V_246 , V_253 -> V_280 [ 0 ] ) ;
F_11 ( F_135 ( V_156 ) , V_253 -> V_280 [ 0 ] ) ;
if ( F_43 ( V_2 ) -> V_102 >= 4 ) {
F_136 ( F_117 ( V_156 ) ,
V_231 -> V_283 + V_97 -> V_282 ) ;
F_11 ( F_137 ( V_156 ) , ( V_246 << 16 ) | V_245 ) ;
F_11 ( F_138 ( V_156 ) , V_256 ) ;
} else
F_11 ( F_118 ( V_156 ) , V_231 -> V_283 + V_256 ) ;
F_14 ( V_10 ) ;
return 0 ;
}
static int F_139 ( struct V_23 * V_24 ,
struct V_252 * V_253 , int V_245 , int V_246 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_254 * V_255 ;
struct V_230 * V_231 ;
int V_156 = V_97 -> V_156 ;
unsigned long V_256 ;
T_1 V_257 ;
T_1 V_10 ;
switch ( V_156 ) {
case 0 :
case 1 :
case 2 :
break;
default:
F_10 ( L_53 , V_156 ) ;
return - V_240 ;
}
V_255 = F_134 ( V_253 ) ;
V_231 = V_255 -> V_231 ;
V_10 = F_73 ( V_156 ) ;
V_257 = F_4 ( V_10 ) ;
V_257 &= ~ V_258 ;
switch ( V_253 -> V_259 ) {
case V_260 :
V_257 |= V_261 ;
break;
case V_265 :
V_257 |= V_266 ;
break;
case V_267 :
case V_268 :
V_257 |= V_269 ;
break;
case V_270 :
case V_271 :
V_257 |= V_272 ;
break;
case V_273 :
case V_274 :
V_257 |= V_275 ;
break;
case V_276 :
case V_277 :
V_257 |= V_278 ;
break;
default:
F_10 ( L_54 , V_253 -> V_259 ) ;
return - V_240 ;
}
if ( V_231 -> V_236 != V_237 )
V_257 |= V_279 ;
else
V_257 &= ~ V_279 ;
V_257 |= V_284 ;
F_11 ( V_10 , V_257 ) ;
V_256 = V_246 * V_253 -> V_280 [ 0 ] + V_245 * ( V_253 -> V_281 / 8 ) ;
V_97 -> V_282 =
F_132 ( & V_245 , & V_246 , V_231 -> V_236 ,
V_253 -> V_281 / 8 ,
V_253 -> V_280 [ 0 ] ) ;
V_256 -= V_97 -> V_282 ;
F_40 ( L_55 ,
V_231 -> V_283 , V_256 , V_245 , V_246 , V_253 -> V_280 [ 0 ] ) ;
F_11 ( F_135 ( V_156 ) , V_253 -> V_280 [ 0 ] ) ;
F_136 ( F_117 ( V_156 ) ,
V_231 -> V_283 + V_97 -> V_282 ) ;
if ( F_71 ( V_2 ) ) {
F_11 ( F_140 ( V_156 ) , ( V_246 << 16 ) | V_245 ) ;
} else {
F_11 ( F_137 ( V_156 ) , ( V_246 << 16 ) | V_245 ) ;
F_11 ( F_138 ( V_156 ) , V_256 ) ;
}
F_14 ( V_10 ) ;
return 0 ;
}
static int
F_141 ( struct V_23 * V_24 , struct V_252 * V_253 ,
int V_245 , int V_246 , enum V_285 V_125 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_286 . V_287 )
V_4 -> V_286 . V_287 ( V_2 ) ;
F_142 ( V_24 ) ;
return V_4 -> V_286 . V_288 ( V_24 , V_253 , V_245 , V_246 ) ;
}
static int
F_143 ( struct V_252 * V_289 )
{
struct V_230 * V_231 = F_134 ( V_289 ) -> V_231 ;
struct V_3 * V_4 = V_231 -> V_208 . V_2 -> V_5 ;
bool V_290 = V_4 -> V_241 . V_242 ;
int V_235 ;
V_4 -> V_241 . V_242 = false ;
V_235 = F_144 ( V_231 ) ;
V_4 -> V_241 . V_242 = V_290 ;
return V_235 ;
}
static void F_145 ( struct V_23 * V_24 , int V_245 , int V_246 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_291 * V_292 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
if ( ! V_2 -> V_293 -> V_294 )
return;
V_292 = V_2 -> V_293 -> V_294 -> V_295 ;
if ( ! V_292 -> V_296 )
return;
switch ( V_97 -> V_95 ) {
case 0 :
V_292 -> V_296 -> V_297 = V_245 ;
V_292 -> V_296 -> V_298 = V_246 ;
break;
case 1 :
V_292 -> V_296 -> V_299 = V_245 ;
V_292 -> V_296 -> V_300 = V_246 ;
break;
default:
break;
}
}
static int
F_146 ( struct V_23 * V_24 , int V_245 , int V_246 ,
struct V_252 * V_253 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_252 * V_289 ;
int V_235 ;
if ( ! V_253 ) {
F_10 ( L_56 ) ;
return 0 ;
}
if( V_97 -> V_156 > V_4 -> V_301 ) {
F_10 ( L_57 ,
V_97 -> V_156 ,
V_4 -> V_301 ) ;
return - V_240 ;
}
F_147 ( & V_2 -> V_302 ) ;
V_235 = F_122 ( V_2 ,
F_134 ( V_253 ) -> V_231 ,
NULL ) ;
if ( V_235 != 0 ) {
F_148 ( & V_2 -> V_302 ) ;
F_10 ( L_58 ) ;
return V_235 ;
}
if ( V_24 -> V_253 )
F_143 ( V_24 -> V_253 ) ;
V_235 = V_4 -> V_286 . V_288 ( V_24 , V_253 , V_245 , V_246 ) ;
if ( V_235 ) {
F_130 ( F_134 ( V_253 ) -> V_231 ) ;
F_148 ( & V_2 -> V_302 ) ;
F_10 ( L_59 ) ;
return V_235 ;
}
V_289 = V_24 -> V_253 ;
V_24 -> V_253 = V_253 ;
V_24 -> V_245 = V_245 ;
V_24 -> V_246 = V_246 ;
if ( V_289 ) {
F_41 ( V_2 , V_97 -> V_95 ) ;
F_130 ( F_134 ( V_289 ) -> V_231 ) ;
}
F_149 ( V_2 ) ;
F_148 ( & V_2 -> V_302 ) ;
F_145 ( V_24 , V_245 , V_246 ) ;
return 0 ;
}
static void F_150 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_1 V_10 , V_303 ;
V_10 = F_63 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
if ( F_151 ( V_2 ) ) {
V_303 &= ~ V_304 ;
V_303 |= V_304 | V_305 ;
} else {
V_303 &= ~ V_306 ;
V_303 |= V_306 | V_305 ;
}
F_11 ( V_10 , V_303 ) ;
V_10 = F_65 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
if ( F_59 ( V_2 ) ) {
V_303 &= ~ V_307 ;
V_303 |= V_308 ;
} else {
V_303 &= ~ V_306 ;
V_303 |= V_306 ;
}
F_11 ( V_10 , V_303 | V_309 ) ;
F_14 ( V_10 ) ;
F_95 ( 1000 ) ;
if ( F_151 ( V_2 ) )
F_11 ( V_10 , F_4 ( V_10 ) | V_310 |
V_311 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_312 =
F_35 ( V_4 -> V_96 [ V_149 ] ) ;
struct V_97 * V_313 =
F_35 ( V_4 -> V_96 [ V_314 ] ) ;
T_5 V_303 ;
if ( ! V_312 -> V_208 . V_124 && ! V_313 -> V_208 . V_124 ) {
F_2 ( F_4 ( F_65 ( V_149 ) ) & V_136 ) ;
F_2 ( F_4 ( F_65 ( V_314 ) ) & V_136 ) ;
V_303 = F_4 ( V_315 ) ;
V_303 &= ~ V_316 ;
F_40 ( L_60 ) ;
F_11 ( V_315 , V_303 ) ;
}
}
static void F_153 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
int V_156 = V_97 -> V_156 ;
T_1 V_10 , V_303 , V_317 ;
F_120 ( V_4 , V_95 ) ;
F_154 ( V_4 , V_156 ) ;
V_10 = F_155 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_318 ;
V_303 &= ~ V_319 ;
F_11 ( V_10 , V_303 ) ;
F_4 ( V_10 ) ;
F_95 ( 150 ) ;
V_10 = F_63 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ ( 7 << 19 ) ;
V_303 |= ( V_97 -> V_320 - 1 ) << 19 ;
V_303 &= ~ V_306 ;
V_303 |= V_321 ;
F_11 ( V_10 , V_303 | V_135 ) ;
V_10 = F_65 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_306 ;
V_303 |= V_321 ;
F_11 ( V_10 , V_303 | V_136 ) ;
F_14 ( V_10 ) ;
F_95 ( 150 ) ;
F_11 ( F_156 ( V_95 ) , V_322 ) ;
F_11 ( F_156 ( V_95 ) , V_322 |
V_323 ) ;
V_10 = F_157 ( V_95 ) ;
for ( V_317 = 0 ; V_317 < 5 ; V_317 ++ ) {
V_303 = F_4 ( V_10 ) ;
F_40 ( L_61 , V_303 ) ;
if ( ( V_303 & V_319 ) ) {
F_40 ( L_62 ) ;
F_11 ( V_10 , V_303 | V_319 ) ;
break;
}
}
if ( V_317 == 5 )
F_10 ( L_63 ) ;
V_10 = F_63 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_306 ;
V_303 |= V_324 ;
F_11 ( V_10 , V_303 ) ;
V_10 = F_65 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_306 ;
V_303 |= V_324 ;
F_11 ( V_10 , V_303 ) ;
F_14 ( V_10 ) ;
F_95 ( 150 ) ;
V_10 = F_157 ( V_95 ) ;
for ( V_317 = 0 ; V_317 < 5 ; V_317 ++ ) {
V_303 = F_4 ( V_10 ) ;
F_40 ( L_61 , V_303 ) ;
if ( V_303 & V_318 ) {
F_11 ( V_10 , V_303 | V_318 ) ;
F_40 ( L_64 ) ;
break;
}
}
if ( V_317 == 5 )
F_10 ( L_65 ) ;
F_40 ( L_66 ) ;
}
static void F_158 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_1 V_10 , V_303 , V_158 , V_325 ;
V_10 = F_155 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_318 ;
V_303 &= ~ V_319 ;
F_11 ( V_10 , V_303 ) ;
F_14 ( V_10 ) ;
F_95 ( 150 ) ;
V_10 = F_63 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ ( 7 << 19 ) ;
V_303 |= ( V_97 -> V_320 - 1 ) << 19 ;
V_303 &= ~ V_306 ;
V_303 |= V_321 ;
V_303 &= ~ V_326 ;
V_303 |= V_327 ;
F_11 ( V_10 , V_303 | V_135 ) ;
F_11 ( F_159 ( V_95 ) ,
V_328 | V_329 ) ;
V_10 = F_65 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
if ( F_59 ( V_2 ) ) {
V_303 &= ~ V_307 ;
V_303 |= V_330 ;
} else {
V_303 &= ~ V_306 ;
V_303 |= V_321 ;
}
F_11 ( V_10 , V_303 | V_136 ) ;
F_14 ( V_10 ) ;
F_95 ( 150 ) ;
for ( V_158 = 0 ; V_158 < 4 ; V_158 ++ ) {
V_10 = F_63 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_326 ;
V_303 |= V_331 [ V_158 ] ;
F_11 ( V_10 , V_303 ) ;
F_14 ( V_10 ) ;
F_95 ( 500 ) ;
for ( V_325 = 0 ; V_325 < 5 ; V_325 ++ ) {
V_10 = F_157 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
F_40 ( L_61 , V_303 ) ;
if ( V_303 & V_319 ) {
F_11 ( V_10 , V_303 | V_319 ) ;
F_40 ( L_62 ) ;
break;
}
F_95 ( 50 ) ;
}
if ( V_325 < 5 )
break;
}
if ( V_158 == 4 )
F_10 ( L_63 ) ;
V_10 = F_63 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_306 ;
V_303 |= V_324 ;
if ( F_160 ( V_2 ) ) {
V_303 &= ~ V_326 ;
V_303 |= V_327 ;
}
F_11 ( V_10 , V_303 ) ;
V_10 = F_65 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
if ( F_59 ( V_2 ) ) {
V_303 &= ~ V_307 ;
V_303 |= V_332 ;
} else {
V_303 &= ~ V_306 ;
V_303 |= V_324 ;
}
F_11 ( V_10 , V_303 ) ;
F_14 ( V_10 ) ;
F_95 ( 150 ) ;
for ( V_158 = 0 ; V_158 < 4 ; V_158 ++ ) {
V_10 = F_63 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_326 ;
V_303 |= V_331 [ V_158 ] ;
F_11 ( V_10 , V_303 ) ;
F_14 ( V_10 ) ;
F_95 ( 500 ) ;
for ( V_325 = 0 ; V_325 < 5 ; V_325 ++ ) {
V_10 = F_157 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
F_40 ( L_61 , V_303 ) ;
if ( V_303 & V_318 ) {
F_11 ( V_10 , V_303 | V_318 ) ;
F_40 ( L_64 ) ;
break;
}
F_95 ( 50 ) ;
}
if ( V_325 < 5 )
break;
}
if ( V_158 == 4 )
F_10 ( L_65 ) ;
F_40 ( L_67 ) ;
}
static void F_161 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_1 V_10 , V_303 , V_158 ;
V_10 = F_155 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_318 ;
V_303 &= ~ V_319 ;
F_11 ( V_10 , V_303 ) ;
F_14 ( V_10 ) ;
F_95 ( 150 ) ;
F_40 ( L_68 ,
F_4 ( F_157 ( V_95 ) ) ) ;
V_10 = F_63 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ ( 7 << 19 ) ;
V_303 |= ( V_97 -> V_320 - 1 ) << 19 ;
V_303 &= ~ ( V_333 | V_304 ) ;
V_303 |= V_334 ;
V_303 &= ~ V_326 ;
V_303 |= V_327 ;
V_303 |= V_335 ;
F_11 ( V_10 , V_303 | V_135 ) ;
F_11 ( F_159 ( V_95 ) ,
V_328 | V_329 ) ;
V_10 = F_65 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_333 ;
V_303 &= ~ V_307 ;
V_303 |= V_330 ;
V_303 |= V_335 ;
F_11 ( V_10 , V_303 | V_136 ) ;
F_14 ( V_10 ) ;
F_95 ( 150 ) ;
for ( V_158 = 0 ; V_158 < 4 ; V_158 ++ ) {
V_10 = F_63 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_326 ;
V_303 |= V_331 [ V_158 ] ;
F_11 ( V_10 , V_303 ) ;
F_14 ( V_10 ) ;
F_95 ( 500 ) ;
V_10 = F_157 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
F_40 ( L_61 , V_303 ) ;
if ( V_303 & V_319 ||
( F_4 ( V_10 ) & V_319 ) ) {
F_11 ( V_10 , V_303 | V_319 ) ;
F_40 ( L_69 , V_158 ) ;
break;
}
}
if ( V_158 == 4 )
F_10 ( L_63 ) ;
V_10 = F_63 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_304 ;
V_303 |= V_336 ;
V_303 &= ~ V_326 ;
V_303 |= V_327 ;
F_11 ( V_10 , V_303 ) ;
V_10 = F_65 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_307 ;
V_303 |= V_332 ;
F_11 ( V_10 , V_303 ) ;
F_14 ( V_10 ) ;
F_95 ( 150 ) ;
for ( V_158 = 0 ; V_158 < 4 ; V_158 ++ ) {
V_10 = F_63 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_326 ;
V_303 |= V_331 [ V_158 ] ;
F_11 ( V_10 , V_303 ) ;
F_14 ( V_10 ) ;
F_95 ( 500 ) ;
V_10 = F_157 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
F_40 ( L_61 , V_303 ) ;
if ( V_303 & V_318 ) {
F_11 ( V_10 , V_303 | V_318 ) ;
F_40 ( L_70 , V_158 ) ;
break;
}
}
if ( V_158 == 4 )
F_10 ( L_65 ) ;
F_40 ( L_67 ) ;
}
static void F_162 ( struct V_97 * V_97 )
{
struct V_1 * V_2 = V_97 -> V_208 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_95 = V_97 -> V_95 ;
T_1 V_10 , V_303 ;
V_10 = F_65 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ ( ( 0x7 << 19 ) | ( 0x7 << 16 ) ) ;
V_303 |= ( V_97 -> V_320 - 1 ) << 19 ;
V_303 |= ( F_4 ( F_45 ( V_95 ) ) & V_216 ) << 11 ;
F_11 ( V_10 , V_303 | V_139 ) ;
F_14 ( V_10 ) ;
F_95 ( 200 ) ;
V_303 = F_4 ( V_10 ) ;
F_11 ( V_10 , V_303 | V_337 ) ;
F_14 ( V_10 ) ;
F_95 ( 200 ) ;
V_10 = F_63 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
if ( ( V_303 & V_138 ) == 0 ) {
F_11 ( V_10 , V_303 | V_138 ) ;
F_14 ( V_10 ) ;
F_95 ( 100 ) ;
}
}
static void F_163 ( struct V_97 * V_97 )
{
struct V_1 * V_2 = V_97 -> V_208 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_95 = V_97 -> V_95 ;
T_1 V_10 , V_303 ;
V_10 = F_65 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
F_11 ( V_10 , V_303 & ~ V_337 ) ;
V_10 = F_63 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
F_11 ( V_10 , V_303 & ~ V_138 ) ;
F_14 ( V_10 ) ;
F_95 ( 100 ) ;
V_10 = F_65 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
F_11 ( V_10 , V_303 & ~ V_139 ) ;
F_14 ( V_10 ) ;
F_95 ( 100 ) ;
}
static void F_164 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_1 V_10 , V_303 ;
V_10 = F_63 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
F_11 ( V_10 , V_303 & ~ V_135 ) ;
F_14 ( V_10 ) ;
V_10 = F_65 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ ( 0x7 << 16 ) ;
V_303 |= ( F_4 ( F_45 ( V_95 ) ) & V_216 ) << 11 ;
F_11 ( V_10 , V_303 & ~ V_136 ) ;
F_14 ( V_10 ) ;
F_95 ( 100 ) ;
if ( F_52 ( V_2 ) ) {
F_11 ( F_156 ( V_95 ) , V_322 ) ;
}
V_10 = F_63 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_306 ;
V_303 |= V_321 ;
F_11 ( V_10 , V_303 ) ;
V_10 = F_65 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
if ( F_59 ( V_2 ) ) {
V_303 &= ~ V_307 ;
V_303 |= V_330 ;
} else {
V_303 &= ~ V_306 ;
V_303 |= V_321 ;
}
V_303 &= ~ ( 0x07 << 16 ) ;
V_303 |= ( F_4 ( F_45 ( V_95 ) ) & V_216 ) << 11 ;
F_11 ( V_10 , V_303 ) ;
F_14 ( V_10 ) ;
F_95 ( 100 ) ;
}
static bool F_165 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
unsigned long V_338 ;
bool V_339 ;
if ( F_166 ( & V_4 -> V_340 ) ||
V_97 -> V_341 != F_167 ( & V_4 -> V_340 . V_341 ) )
return false ;
F_168 ( & V_2 -> V_342 , V_338 ) ;
V_339 = F_35 ( V_24 ) -> V_343 != NULL ;
F_169 ( & V_2 -> V_342 , V_338 ) ;
return V_339 ;
}
static void F_170 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_24 -> V_253 == NULL )
return;
F_2 ( F_171 ( & V_4 -> V_344 ) ) ;
F_172 ( V_4 -> V_344 ,
! F_165 ( V_24 ) ) ;
F_147 ( & V_2 -> V_302 ) ;
F_143 ( V_24 -> V_253 ) ;
F_148 ( & V_2 -> V_302 ) ;
}
static bool F_173 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_62 * V_62 ;
F_26 (dev, crtc, intel_encoder) {
switch ( V_62 -> type ) {
case V_33 :
if ( ! F_174 ( & V_62 -> V_208 ) )
return false ;
continue;
}
}
return true ;
}
static bool F_175 ( struct V_23 * V_24 )
{
return F_16 ( V_24 , V_39 ) ;
}
static void F_176 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_345 , V_346 , V_347 , V_348 = 0 ;
T_1 V_303 ;
F_147 ( & V_4 -> V_11 ) ;
F_11 ( V_349 , V_350 ) ;
F_98 ( V_4 , V_351 ,
F_99 ( V_4 , V_351 , V_200 ) |
V_352 ,
V_200 ) ;
if ( V_24 -> V_353 . clock == 20000 ) {
V_347 = 1 ;
V_345 = 0x41 ;
V_346 = 0x20 ;
} else {
T_1 V_354 = 172800 * 1000 ;
T_1 V_355 = 64 ;
T_1 V_356 , V_357 , V_358 ;
V_356 = ( V_354 / V_24 -> V_353 . clock ) ;
V_357 = V_356 / V_355 ;
V_358 = V_356 % V_355 ;
V_347 = 0 ;
V_345 = V_357 - 2 ;
V_346 = V_358 ;
}
F_2 ( F_177 ( V_345 ) &
~ V_359 ) ;
F_2 ( F_178 ( V_348 ) &
~ V_360 ) ;
F_40 ( L_71 ,
V_24 -> V_353 . clock ,
V_347 ,
V_345 ,
V_348 ,
V_346 ) ;
V_303 = F_99 ( V_4 , V_361 , V_200 ) ;
V_303 &= ~ V_359 ;
V_303 |= F_177 ( V_345 ) ;
V_303 &= ~ V_360 ;
V_303 |= F_179 ( V_346 ) ;
V_303 |= F_178 ( V_348 ) ;
V_303 |= V_362 ;
F_98 ( V_4 , V_361 , V_303 , V_200 ) ;
V_303 = F_99 ( V_4 , V_363 , V_200 ) ;
V_303 &= ~ F_180 ( 1 ) ;
V_303 |= F_180 ( V_347 ) ;
F_98 ( V_4 , V_363 , V_303 , V_200 ) ;
V_303 = F_99 ( V_4 , V_351 , V_200 ) ;
V_303 &= ~ V_352 ;
F_98 ( V_4 , V_351 , V_303 , V_200 ) ;
F_95 ( 24 ) ;
F_11 ( V_349 , V_364 ) ;
F_148 ( & V_4 -> V_11 ) ;
}
static void F_181 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_1 V_10 , V_303 ;
F_77 ( V_4 , V_95 ) ;
F_11 ( F_182 ( V_95 ) ,
F_4 ( F_183 ( V_95 ) ) & V_365 ) ;
V_4 -> V_286 . V_366 ( V_24 ) ;
F_100 ( V_97 ) ;
if ( F_59 ( V_2 ) ) {
T_1 V_367 ;
V_303 = F_4 ( V_132 ) ;
switch ( V_95 ) {
default:
case 0 :
V_303 |= V_368 ;
V_367 = V_369 ;
break;
case 1 :
V_303 |= V_370 ;
V_367 = V_371 ;
break;
case 2 :
V_303 |= V_372 ;
V_367 = V_373 ;
break;
}
if ( V_97 -> V_209 -> V_130 == V_133 )
V_303 |= V_367 ;
else
V_303 &= ~ V_367 ;
F_11 ( V_132 , V_303 ) ;
}
F_68 ( V_4 , V_95 ) ;
F_11 ( F_184 ( V_95 ) , F_4 ( F_185 ( V_95 ) ) ) ;
F_11 ( F_186 ( V_95 ) , F_4 ( F_187 ( V_95 ) ) ) ;
F_11 ( F_188 ( V_95 ) , F_4 ( F_189 ( V_95 ) ) ) ;
F_11 ( F_190 ( V_95 ) , F_4 ( F_191 ( V_95 ) ) ) ;
F_11 ( F_192 ( V_95 ) , F_4 ( F_193 ( V_95 ) ) ) ;
F_11 ( F_194 ( V_95 ) , F_4 ( F_195 ( V_95 ) ) ) ;
F_11 ( F_196 ( V_95 ) , F_4 ( F_197 ( V_95 ) ) ) ;
F_150 ( V_24 ) ;
if ( F_59 ( V_2 ) &&
( F_16 ( V_24 , V_32 ) ||
F_16 ( V_24 , V_33 ) ) ) {
T_1 V_374 = ( F_4 ( F_45 ( V_95 ) ) & V_216 ) >> 5 ;
V_10 = F_80 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ ( V_171 |
V_375 |
V_376 ) ;
V_303 |= ( V_377 |
V_378 ) ;
V_303 |= V_374 << 9 ;
if ( V_24 -> V_353 . V_338 & V_379 )
V_303 |= V_380 ;
if ( V_24 -> V_353 . V_338 & V_381 )
V_303 |= V_382 ;
switch ( F_198 ( V_24 ) ) {
case V_182 :
V_303 |= V_183 ;
break;
case V_184 :
V_303 |= V_185 ;
break;
case V_186 :
V_303 |= V_187 ;
break;
default:
F_125 () ;
}
F_11 ( V_10 , V_303 ) ;
}
F_104 ( V_4 , V_95 ) ;
}
static void F_199 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
enum V_94 V_98 = V_97 -> V_98 ;
F_77 ( V_4 , V_224 ) ;
F_176 ( V_24 ) ;
F_11 ( V_383 , F_4 ( F_185 ( V_98 ) ) ) ;
F_11 ( V_384 , F_4 ( F_187 ( V_98 ) ) ) ;
F_11 ( V_385 , F_4 ( F_189 ( V_98 ) ) ) ;
F_11 ( V_386 , F_4 ( F_191 ( V_98 ) ) ) ;
F_11 ( V_387 , F_4 ( F_193 ( V_98 ) ) ) ;
F_11 ( V_388 , F_4 ( F_195 ( V_98 ) ) ) ;
F_11 ( V_389 , F_4 ( F_197 ( V_98 ) ) ) ;
F_108 ( V_4 , V_98 ) ;
}
static void F_200 ( struct V_97 * V_97 )
{
struct V_128 * V_129 = V_97 -> V_209 ;
if ( V_129 == NULL )
return;
if ( V_129 -> V_210 == 0 ) {
F_46 ( 1 , L_72 ) ;
return;
}
-- V_129 -> V_210 ;
V_97 -> V_209 = NULL ;
}
static struct V_128 * F_201 ( struct V_97 * V_97 , T_1 V_390 , T_1 V_391 )
{
struct V_3 * V_4 = V_97 -> V_208 . V_2 -> V_5 ;
struct V_128 * V_129 ;
int V_158 ;
V_129 = V_97 -> V_209 ;
if ( V_129 ) {
F_40 ( L_73 ,
V_97 -> V_208 . V_208 . V_213 , V_129 -> V_130 ) ;
goto V_392;
}
if ( F_52 ( V_4 -> V_2 ) ) {
V_158 = V_97 -> V_95 ;
V_129 = & V_4 -> V_393 [ V_158 ] ;
F_40 ( L_74 ,
V_97 -> V_208 . V_208 . V_213 , V_129 -> V_130 ) ;
goto V_75;
}
for ( V_158 = 0 ; V_158 < V_4 -> V_394 ; V_158 ++ ) {
V_129 = & V_4 -> V_393 [ V_158 ] ;
if ( V_129 -> V_210 == 0 )
continue;
if ( V_390 == ( F_4 ( V_129 -> V_130 ) & 0x7fffffff ) &&
V_391 == F_4 ( V_129 -> V_395 ) ) {
F_40 ( L_75 ,
V_97 -> V_208 . V_208 . V_213 ,
V_129 -> V_130 , V_129 -> V_210 , V_129 -> V_211 ) ;
goto V_75;
}
}
for ( V_158 = 0 ; V_158 < V_4 -> V_394 ; V_158 ++ ) {
V_129 = & V_4 -> V_393 [ V_158 ] ;
if ( V_129 -> V_210 == 0 ) {
F_40 ( L_76 ,
V_97 -> V_208 . V_208 . V_213 , V_129 -> V_130 ) ;
goto V_75;
}
}
return NULL ;
V_75:
V_97 -> V_209 = V_129 ;
V_129 -> V_210 ++ ;
F_58 ( L_77 , V_158 , V_97 -> V_95 ) ;
V_392:
F_58 ( L_78 , V_129 -> V_130 ) ;
F_11 ( V_129 -> V_130 , V_390 & ~ V_127 ) ;
F_14 ( V_129 -> V_130 ) ;
F_95 ( 150 ) ;
F_11 ( V_129 -> V_395 , V_391 ) ;
F_11 ( V_129 -> V_130 , V_390 & ~ V_127 ) ;
V_129 -> V_212 = false ;
return V_129 ;
}
void F_202 ( struct V_1 * V_2 , int V_95 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_396 = F_47 ( V_95 ) ;
T_1 V_303 ;
V_303 = F_4 ( V_396 ) ;
F_95 ( 500 ) ;
if ( F_38 ( F_4 ( V_396 ) != V_303 , 5 ) ) {
if ( F_38 ( F_4 ( V_396 ) != V_303 , 5 ) )
F_10 ( L_79 , V_95 ) ;
}
}
static void F_203 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_62 * V_63 ;
int V_95 = V_97 -> V_95 ;
int V_156 = V_97 -> V_156 ;
T_1 V_303 ;
bool V_397 ;
F_2 ( ! V_24 -> V_124 ) ;
if ( V_97 -> V_211 )
return;
V_97 -> V_211 = true ;
F_204 ( V_2 ) ;
if ( F_16 ( V_24 , V_27 ) ) {
V_303 = F_4 ( V_78 ) ;
if ( ( V_303 & V_176 ) == 0 )
F_11 ( V_78 , V_303 | V_176 ) ;
}
V_397 = F_173 ( V_24 ) ;
if ( V_397 ) {
F_162 ( V_97 ) ;
} else {
F_110 ( V_4 , V_95 ) ;
F_111 ( V_4 , V_95 ) ;
}
F_26 (dev, crtc, encoder)
if ( V_63 -> V_398 )
V_63 -> V_398 ( V_63 ) ;
if ( V_4 -> V_399 &&
( F_16 ( V_24 , V_27 ) ||
F_16 ( V_24 , V_33 ) ) ) {
if ( F_151 ( V_2 ) )
F_11 ( F_205 ( V_95 ) , V_400 | V_401 |
F_206 ( V_95 ) ) ;
else
F_11 ( F_205 ( V_95 ) , V_400 | V_401 ) ;
F_11 ( F_207 ( V_95 ) , V_4 -> V_402 ) ;
F_11 ( F_208 ( V_95 ) , V_4 -> V_399 ) ;
}
F_209 ( V_24 ) ;
F_113 ( V_4 , V_95 , V_397 ) ;
F_119 ( V_4 , V_156 , V_95 ) ;
if ( V_397 )
F_181 ( V_24 ) ;
F_147 ( & V_2 -> V_302 ) ;
F_149 ( V_2 ) ;
F_148 ( & V_2 -> V_302 ) ;
F_210 ( V_24 , true ) ;
F_26 (dev, crtc, encoder)
V_63 -> V_403 ( V_63 ) ;
if ( F_59 ( V_2 ) )
F_202 ( V_2 , V_97 -> V_95 ) ;
F_41 ( V_2 , V_97 -> V_95 ) ;
}
static void F_211 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_62 * V_63 ;
int V_95 = V_97 -> V_95 ;
int V_156 = V_97 -> V_156 ;
bool V_397 ;
F_2 ( ! V_24 -> V_124 ) ;
if ( V_97 -> V_211 )
return;
V_97 -> V_211 = true ;
F_204 ( V_2 ) ;
V_397 = F_175 ( V_24 ) ;
if ( V_397 )
V_4 -> V_286 . V_366 ( V_24 ) ;
F_26 (dev, crtc, encoder)
if ( V_63 -> V_398 )
V_63 -> V_398 ( V_63 ) ;
F_212 ( V_97 ) ;
if ( V_4 -> V_399 &&
F_16 ( V_24 , V_33 ) ) {
F_11 ( F_205 ( V_95 ) , V_400 | V_401 |
F_206 ( V_95 ) ) ;
F_11 ( F_207 ( V_95 ) , V_4 -> V_402 ) ;
F_11 ( F_208 ( V_95 ) , V_4 -> V_399 ) ;
}
F_209 ( V_24 ) ;
F_213 ( V_24 ) ;
F_214 ( V_24 ) ;
F_113 ( V_4 , V_95 , V_397 ) ;
F_119 ( V_4 , V_156 , V_95 ) ;
if ( V_397 )
F_199 ( V_24 ) ;
F_147 ( & V_2 -> V_302 ) ;
F_149 ( V_2 ) ;
F_148 ( & V_2 -> V_302 ) ;
F_210 ( V_24 , true ) ;
F_26 (dev, crtc, encoder)
V_63 -> V_403 ( V_63 ) ;
F_41 ( V_2 , V_97 -> V_95 ) ;
}
static void F_215 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_62 * V_63 ;
int V_95 = V_97 -> V_95 ;
int V_156 = V_97 -> V_156 ;
T_1 V_10 , V_303 ;
if ( ! V_97 -> V_211 )
return;
F_26 (dev, crtc, encoder)
V_63 -> V_404 ( V_63 ) ;
F_170 ( V_24 ) ;
F_216 ( V_2 , V_95 ) ;
F_210 ( V_24 , false ) ;
F_121 ( V_4 , V_156 , V_95 ) ;
if ( V_4 -> V_405 == V_156 )
F_217 ( V_2 ) ;
F_115 ( V_4 , V_95 ) ;
F_11 ( F_205 ( V_95 ) , 0 ) ;
F_11 ( F_208 ( V_95 ) , 0 ) ;
F_26 (dev, crtc, encoder)
if ( V_63 -> V_406 )
V_63 -> V_406 ( V_63 ) ;
F_164 ( V_24 ) ;
F_109 ( V_4 , V_95 ) ;
if ( F_59 ( V_2 ) ) {
V_10 = F_80 ( V_95 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ ( V_377 | V_171 ) ;
V_303 |= V_407 ;
F_11 ( V_10 , V_303 ) ;
V_303 = F_4 ( V_132 ) ;
switch ( V_95 ) {
case 0 :
V_303 &= ~ ( V_368 | V_369 ) ;
break;
case 1 :
V_303 &= ~ ( V_370 | V_371 ) ;
break;
case 2 :
V_303 &= ~ ( V_372 | V_373 ) ;
break;
default:
F_125 () ;
}
F_11 ( V_132 , V_303 ) ;
}
F_102 ( V_97 ) ;
F_163 ( V_97 ) ;
V_97 -> V_211 = false ;
F_204 ( V_2 ) ;
F_147 ( & V_2 -> V_302 ) ;
F_149 ( V_2 ) ;
F_148 ( & V_2 -> V_302 ) ;
}
static void F_218 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_62 * V_63 ;
int V_95 = V_97 -> V_95 ;
int V_156 = V_97 -> V_156 ;
enum V_94 V_98 = V_97 -> V_98 ;
bool V_397 ;
if ( ! V_97 -> V_211 )
return;
V_397 = F_175 ( V_24 ) ;
F_26 (dev, crtc, encoder)
V_63 -> V_404 ( V_63 ) ;
F_170 ( V_24 ) ;
F_216 ( V_2 , V_95 ) ;
F_210 ( V_24 , false ) ;
F_121 ( V_4 , V_156 , V_95 ) ;
if ( V_4 -> V_405 == V_156 )
F_217 ( V_2 ) ;
F_115 ( V_4 , V_95 ) ;
F_219 ( V_4 , V_98 ) ;
F_11 ( F_205 ( V_95 ) , 0 ) ;
F_11 ( F_208 ( V_95 ) , 0 ) ;
F_220 ( V_97 ) ;
F_26 (dev, crtc, encoder)
if ( V_63 -> V_406 )
V_63 -> V_406 ( V_63 ) ;
if ( V_397 ) {
F_112 ( V_4 ) ;
F_221 ( V_24 ) ;
}
V_97 -> V_211 = false ;
F_204 ( V_2 ) ;
F_147 ( & V_2 -> V_302 ) ;
F_149 ( V_2 ) ;
F_148 ( & V_2 -> V_302 ) ;
}
static void F_222 ( struct V_23 * V_24 )
{
struct V_97 * V_97 = F_35 ( V_24 ) ;
F_200 ( V_97 ) ;
}
static void F_223 ( struct V_23 * V_24 )
{
struct V_97 * V_97 = F_35 ( V_24 ) ;
V_97 -> V_98 = (enum V_94 ) V_97 -> V_95 ;
F_224 ( V_24 ) ;
}
static void F_225 ( struct V_97 * V_97 , bool V_403 )
{
if ( ! V_403 && V_97 -> V_408 ) {
struct V_1 * V_2 = V_97 -> V_208 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_147 ( & V_2 -> V_302 ) ;
V_4 -> V_241 . V_242 = false ;
( void ) F_226 ( V_97 -> V_408 ) ;
V_4 -> V_241 . V_242 = true ;
F_148 ( & V_2 -> V_302 ) ;
}
}
static void
F_227 ( struct V_3 * V_4 , enum V_95 V_95 )
{
T_1 V_409 = F_4 ( F_228 ( V_95 ) ) ;
if ( ( V_409 & V_410 ) == 0 ) {
T_1 V_411 = F_4 ( V_412 ) ;
F_11 ( V_412 , V_411 & ~ V_413 ) ;
F_11 ( F_228 ( V_95 ) , V_414 ) ;
F_41 ( V_4 -> V_2 , V_95 ) ;
F_11 ( F_228 ( V_95 ) , V_409 ) ;
F_11 ( F_229 ( V_95 ) , F_4 ( F_229 ( V_95 ) ) ) ;
F_11 ( V_412 , V_411 ) ;
}
}
static void F_230 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_62 * V_63 ;
int V_95 = V_97 -> V_95 ;
int V_156 = V_97 -> V_156 ;
F_2 ( ! V_24 -> V_124 ) ;
if ( V_97 -> V_211 )
return;
V_97 -> V_211 = true ;
F_204 ( V_2 ) ;
F_91 ( V_4 , V_95 ) ;
F_26 (dev, crtc, encoder)
if ( V_63 -> V_398 )
V_63 -> V_398 ( V_63 ) ;
F_113 ( V_4 , V_95 , false ) ;
F_119 ( V_4 , V_156 , V_95 ) ;
if ( F_20 ( V_2 ) )
F_227 ( V_4 , V_95 ) ;
F_209 ( V_24 ) ;
F_149 ( V_2 ) ;
F_225 ( V_97 , true ) ;
F_210 ( V_24 , true ) ;
F_26 (dev, crtc, encoder)
V_63 -> V_403 ( V_63 ) ;
}
static void F_231 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_62 * V_63 ;
int V_95 = V_97 -> V_95 ;
int V_156 = V_97 -> V_156 ;
T_1 V_415 ;
if ( ! V_97 -> V_211 )
return;
F_26 (dev, crtc, encoder)
V_63 -> V_404 ( V_63 ) ;
F_170 ( V_24 ) ;
F_216 ( V_2 , V_95 ) ;
F_225 ( V_97 , false ) ;
F_210 ( V_24 , false ) ;
if ( V_4 -> V_405 == V_156 )
F_217 ( V_2 ) ;
F_121 ( V_4 , V_156 , V_95 ) ;
F_115 ( V_4 , V_95 ) ;
V_415 = F_4 ( V_416 ) ;
if ( ( V_415 & V_417 ) &&
( ( V_415 & V_418 ) >> V_419 ) == V_95 )
F_11 ( V_416 , 0 ) ;
F_96 ( V_4 , V_95 ) ;
V_97 -> V_211 = false ;
F_149 ( V_2 ) ;
F_204 ( V_2 ) ;
}
static void F_232 ( struct V_23 * V_24 )
{
}
static void F_233 ( struct V_23 * V_24 ,
bool V_124 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_291 * V_292 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
if ( ! V_2 -> V_293 -> V_294 )
return;
V_292 = V_2 -> V_293 -> V_294 -> V_295 ;
if ( ! V_292 -> V_296 )
return;
switch ( V_95 ) {
case 0 :
V_292 -> V_296 -> V_420 = V_124 ? V_24 -> V_353 . V_421 : 0 ;
V_292 -> V_296 -> V_422 = V_124 ? V_24 -> V_353 . V_423 : 0 ;
break;
case 1 :
V_292 -> V_296 -> V_424 = V_124 ? V_24 -> V_353 . V_421 : 0 ;
V_292 -> V_296 -> V_425 = V_124 ? V_24 -> V_353 . V_423 : 0 ;
break;
default:
F_10 ( L_80 , F_69 ( V_95 ) ) ;
break;
}
}
void F_234 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_62 * V_62 ;
bool V_403 = false ;
F_26 (dev, crtc, intel_encoder)
V_403 |= V_62 -> V_426 ;
if ( V_403 )
V_4 -> V_286 . V_427 ( V_24 ) ;
else
V_4 -> V_286 . V_428 ( V_24 ) ;
F_233 ( V_24 , V_403 ) ;
}
static void F_235 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_429 * V_430 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
F_2 ( ! V_24 -> V_124 ) ;
V_97 -> V_431 = false ;
V_4 -> V_286 . V_428 ( V_24 ) ;
F_233 ( V_24 , false ) ;
V_4 -> V_286 . V_432 ( V_24 ) ;
F_236 ( V_2 -> V_5 , F_35 ( V_24 ) -> V_156 ) ;
F_97 ( V_2 -> V_5 , F_35 ( V_24 ) -> V_95 ) ;
if ( V_24 -> V_253 ) {
F_147 ( & V_2 -> V_302 ) ;
F_130 ( F_134 ( V_24 -> V_253 ) -> V_231 ) ;
F_148 ( & V_2 -> V_302 ) ;
V_24 -> V_253 = NULL ;
}
F_237 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_430 -> V_63 || ! V_430 -> V_63 -> V_24 )
continue;
if ( V_430 -> V_63 -> V_24 != V_24 )
continue;
V_430 -> V_433 = V_434 ;
F_238 ( V_430 -> V_63 ) -> V_426 = false ;
}
}
void F_239 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
F_237 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_24 -> V_124 )
F_235 ( V_24 ) ;
}
}
void F_240 ( struct V_435 * V_63 )
{
struct V_62 * V_62 = F_238 ( V_63 ) ;
F_241 ( V_63 ) ;
F_242 ( V_62 ) ;
}
void F_243 ( struct V_62 * V_63 , int V_353 )
{
if ( V_353 == V_436 ) {
V_63 -> V_426 = true ;
F_234 ( V_63 -> V_208 . V_24 ) ;
} else {
V_63 -> V_426 = false ;
F_234 ( V_63 -> V_208 . V_24 ) ;
}
}
static void F_244 ( struct V_437 * V_430 )
{
if ( V_430 -> V_438 ( V_430 ) ) {
struct V_62 * V_63 = V_430 -> V_63 ;
struct V_23 * V_24 ;
bool V_439 ;
enum V_95 V_95 ;
F_40 ( L_81 ,
V_430 -> V_208 . V_208 . V_213 ,
F_245 ( & V_430 -> V_208 ) ) ;
F_46 ( V_430 -> V_208 . V_433 == V_434 ,
L_82 ) ;
F_46 ( V_430 -> V_208 . V_63 != & V_63 -> V_208 ,
L_83 ) ;
F_46 ( ! V_63 -> V_426 ,
L_84 ) ;
V_439 = V_63 -> V_438 ( V_63 , & V_95 ) ;
F_46 ( ! V_439 , L_85 ) ;
if ( F_2 ( ! V_63 -> V_208 . V_24 ) )
return;
V_24 = V_63 -> V_208 . V_24 ;
F_46 ( ! V_24 -> V_124 , L_86 ) ;
F_46 ( ! F_35 ( V_24 ) -> V_211 , L_87 ) ;
F_46 ( V_95 != F_35 ( V_24 ) -> V_95 ,
L_88 ) ;
}
}
void F_246 ( struct V_429 * V_430 , int V_353 )
{
struct V_62 * V_63 = F_247 ( V_430 ) ;
if ( V_353 != V_436 )
V_353 = V_434 ;
if ( V_353 == V_430 -> V_433 )
return;
V_430 -> V_433 = V_353 ;
if ( V_63 -> V_208 . V_24 )
F_243 ( V_63 , V_353 ) ;
else
F_2 ( V_63 -> V_426 != false ) ;
F_248 ( V_430 -> V_2 ) ;
}
bool F_249 ( struct V_437 * V_430 )
{
enum V_95 V_95 = 0 ;
struct V_62 * V_63 = V_430 -> V_63 ;
return V_63 -> V_438 ( V_63 , & V_95 ) ;
}
static bool F_250 ( struct V_23 * V_24 ,
const struct V_440 * V_353 ,
struct V_440 * V_441 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
if ( F_3 ( V_2 ) ) {
if ( V_353 -> clock * 3 > V_442 * 4 )
return false ;
}
if ( ! ( V_441 -> V_443 & V_444 ) )
F_251 ( V_441 , 0 ) ;
if ( ( F_43 ( V_2 ) -> V_102 > 4 || F_20 ( V_2 ) ) &&
V_441 -> V_445 == V_441 -> V_421 )
return false ;
return true ;
}
static int F_252 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_253 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_254 ( struct V_1 * V_2 )
{
return 333000 ;
}
static int F_255 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_256 ( struct V_1 * V_2 )
{
T_4 V_446 = 0 ;
F_257 ( V_2 -> V_447 , V_448 , & V_446 ) ;
if ( V_446 & V_449 )
return 133000 ;
else {
switch ( V_446 & V_450 ) {
case V_451 :
return 333000 ;
default:
case V_452 :
return 190000 ;
}
}
}
static int F_258 ( struct V_1 * V_2 )
{
return 266000 ;
}
static int F_259 ( struct V_1 * V_2 )
{
T_4 V_453 = 0 ;
switch ( V_453 & V_454 ) {
case V_455 :
case V_456 :
return 200000 ;
case V_457 :
return 250000 ;
case V_458 :
return 133000 ;
}
return 0 ;
}
static int F_260 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_261 ( T_5 * V_459 , T_5 * V_460 )
{
while ( * V_459 > 0xffffff || * V_460 > 0xffffff ) {
* V_459 >>= 1 ;
* V_460 >>= 1 ;
}
}
void
F_262 ( int V_281 , int V_461 ,
int V_462 , int V_463 ,
struct V_464 * V_465 )
{
V_465 -> V_466 = 64 ;
V_465 -> V_467 = V_281 * V_462 ;
V_465 -> V_468 = V_463 * V_461 * 8 ;
F_261 ( & V_465 -> V_467 , & V_465 -> V_468 ) ;
V_465 -> V_469 = V_462 ;
V_465 -> V_470 = V_463 ;
F_261 ( & V_465 -> V_469 , & V_465 -> V_470 ) ;
}
static inline bool F_263 ( struct V_3 * V_4 )
{
if ( V_471 >= 0 )
return V_471 != 0 ;
return V_4 -> V_472
&& ! ( V_4 -> V_150 & V_473 ) ;
}
static bool F_264 ( struct V_23 * V_24 ,
struct V_252 * V_253 ,
unsigned int * V_474 ,
struct V_440 * V_353 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_429 * V_430 ;
struct V_62 * V_62 ;
unsigned int V_475 = V_476 , V_374 ;
F_26 (dev, crtc, intel_encoder) {
if ( V_62 -> type == V_27 ) {
unsigned int V_477 ;
if ( ( F_4 ( V_78 ) & V_478 ) ==
V_479 )
V_477 = 8 ;
else
V_477 = 6 ;
if ( V_477 < V_475 ) {
F_40 ( L_89 , V_475 , V_477 ) ;
V_475 = V_477 ;
}
continue;
}
F_237 (connector, &dev->mode_config.connector_list,
head) {
if ( V_430 -> V_63 != & V_62 -> V_208 )
continue;
if ( V_430 -> V_480 . V_374 &&
V_430 -> V_480 . V_374 < V_475 ) {
F_40 ( L_90 , V_475 , V_430 -> V_480 . V_374 ) ;
V_475 = V_430 -> V_480 . V_374 ;
}
}
if ( V_62 -> type == V_33 ) {
unsigned int V_481 = V_4 -> V_482 . V_483 / 3 ;
if ( V_481 && V_481 < V_475 ) {
F_40 ( L_91 , V_475 , V_481 ) ;
V_475 = V_481 ;
}
continue;
}
if ( V_62 -> type == V_38 ) {
if ( V_475 > 8 && V_475 < 12 ) {
F_40 ( L_92 ) ;
V_475 = 12 ;
} else {
F_40 ( L_93 ) ;
V_475 = 8 ;
}
}
}
if ( V_353 -> V_443 & V_484 ) {
F_40 ( L_94 ) ;
V_475 = 6 ;
}
switch ( V_253 -> V_485 ) {
case 8 :
V_374 = 8 ;
break;
case 15 :
case 16 :
V_374 = 6 ;
break;
case 24 :
V_374 = 8 ;
break;
case 30 :
V_374 = 10 ;
break;
case 48 :
V_374 = 12 ;
break;
default:
F_265 ( L_95 ) ;
V_374 = V_64 ( ( unsigned int ) 8 , V_475 ) ;
break;
}
V_475 = V_64 ( V_475 , V_374 ) ;
F_40 ( L_96 ,
V_374 , V_475 ) ;
* V_474 = V_475 * 3 ;
return V_475 != V_374 ;
}
static int F_266 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_25 = 27000 ;
return 100000 ;
if ( F_16 ( V_24 , V_39 ) ) {
V_25 = 96000 ;
} else if ( F_16 ( V_24 , V_27 ) ) {
if ( F_263 ( V_4 ) )
V_25 = 100000 ;
else
V_25 = 96000 ;
} else if ( F_16 ( V_24 , V_33 ) ) {
V_25 = 100000 ;
}
return V_25 ;
}
static int F_267 ( struct V_23 * V_24 , int V_486 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_25 ;
if ( F_22 ( V_2 ) ) {
V_25 = F_266 ( V_24 ) ;
} else if ( F_16 ( V_24 , V_27 ) &&
F_263 ( V_4 ) && V_486 < 2 ) {
V_25 = V_4 -> V_487 * 1000 ;
F_40 ( L_97 ,
V_25 / 1000 ) ;
} else if ( ! F_23 ( V_2 ) ) {
V_25 = 96000 ;
} else {
V_25 = 48000 ;
}
return V_25 ;
}
static void F_268 ( struct V_440 * V_441 ,
T_3 * clock )
{
if ( V_441 -> clock >= 100000
&& V_441 -> clock < 140500 ) {
clock -> V_56 = 2 ;
clock -> V_57 = 10 ;
clock -> V_59 = 3 ;
clock -> V_61 = 16 ;
clock -> V_54 = 8 ;
} else if ( V_441 -> clock >= 140500
&& V_441 -> clock <= 200000 ) {
clock -> V_56 = 1 ;
clock -> V_57 = 10 ;
clock -> V_59 = 6 ;
clock -> V_61 = 12 ;
clock -> V_54 = 8 ;
}
}
static void F_269 ( struct V_23 * V_24 ,
T_3 * clock ,
T_3 * V_488 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_1 V_391 , V_489 = 0 ;
if ( F_21 ( V_2 ) ) {
V_391 = ( 1 << clock -> V_59 ) << 16 | clock -> V_61 << 8 | clock -> V_54 ;
if ( V_488 )
V_489 = ( 1 << V_488 -> V_59 ) << 16 |
V_488 -> V_61 << 8 | V_488 -> V_54 ;
} else {
V_391 = clock -> V_59 << 16 | clock -> V_61 << 8 | clock -> V_54 ;
if ( V_488 )
V_489 = V_488 -> V_59 << 16 | V_488 -> V_61 << 8 |
V_488 -> V_54 ;
}
F_11 ( F_270 ( V_95 ) , V_391 ) ;
V_97 -> V_490 = false ;
if ( F_16 ( V_24 , V_27 ) &&
V_488 && V_491 ) {
F_11 ( F_271 ( V_95 ) , V_489 ) ;
V_97 -> V_490 = true ;
} else {
F_11 ( F_271 ( V_95 ) , V_391 ) ;
}
}
static void F_272 ( struct V_23 * V_24 ,
struct V_440 * V_353 ,
struct V_440 * V_441 ,
T_3 * clock , T_3 * V_488 ,
int V_486 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_1 V_390 , V_492 , V_493 ;
T_1 V_80 , V_81 , V_82 , V_83 , V_84 ;
bool V_494 ;
T_1 V_303 ;
F_147 ( & V_4 -> V_11 ) ;
V_494 = F_16 ( V_24 , V_41 ) ||
F_16 ( V_24 , V_38 ) ;
V_390 = V_495 ;
V_390 |= V_496 ;
V_390 |= V_497 ;
V_390 |= V_498 ;
F_11 ( F_55 ( V_95 ) , V_390 ) ;
F_14 ( F_55 ( V_95 ) ) ;
V_80 = clock -> V_59 ;
V_81 = clock -> V_61 ;
V_82 = clock -> V_54 ;
V_83 = clock -> V_56 ;
V_84 = clock -> V_57 ;
V_492 = ( ( V_81 << V_499 ) | ( V_82 & V_500 ) ) ;
V_492 |= ( ( V_83 << V_501 ) | ( V_84 << V_502 ) ) ;
V_492 |= ( ( V_80 << V_503 ) ) ;
V_492 |= ( 1 << V_504 ) ;
V_492 |= ( 1 << V_505 ) ;
V_492 |= V_506 ;
F_12 ( V_4 , F_273 ( V_95 ) , V_492 ) ;
F_12 ( V_4 , F_274 ( V_95 ) , 0x01000000 ) ;
V_493 = ( 1 << V_507 ) | ( 5 << V_508 ) |
( 3 << V_509 ) | ( 1 << 20 ) |
( 7 << V_510 ) | ( 8 << V_511 ) |
( 5 << V_512 ) ;
F_12 ( V_4 , F_275 ( V_95 ) , V_493 ) ;
F_12 ( V_4 , F_276 ( V_95 ) , 0x005f003b ) ;
V_390 |= V_127 ;
F_11 ( F_55 ( V_95 ) , V_390 ) ;
F_14 ( F_55 ( V_95 ) ) ;
if ( F_38 ( ( ( F_4 ( F_55 ( V_95 ) ) & V_513 ) == V_513 ) , 1 ) )
F_10 ( L_98 , V_95 ) ;
F_12 ( V_4 , V_514 , 0x620 ) ;
if ( F_16 ( V_24 , V_32 ) )
F_277 ( V_24 , V_353 , V_441 ) ;
F_11 ( F_55 ( V_95 ) , V_390 ) ;
F_14 ( F_55 ( V_95 ) ) ;
F_95 ( 150 ) ;
V_303 = 0 ;
if ( V_494 ) {
V_303 = F_278 ( V_441 ) ;
if ( V_303 > 1 )
V_303 = ( V_303 - 1 ) << V_515 ;
else
V_303 = 0 ;
}
F_11 ( F_279 ( V_95 ) , V_303 ) ;
F_14 ( F_279 ( V_95 ) ) ;
if( F_16 ( V_24 , V_32 )
|| F_16 ( V_24 , V_38 ) )
{
V_303 = 0x1000C4 ;
if( V_95 == 1 )
V_303 |= ( 1 << 21 ) ;
F_12 ( V_4 , V_516 , V_303 ) ;
}
if( F_16 ( V_24 , V_33 ) )
{
V_303 = 0x1000C4 ;
if( V_95 == 1 )
V_303 |= ( 1 << 21 ) ;
F_12 ( V_4 , V_517 , V_303 ) ;
}
F_148 ( & V_4 -> V_11 ) ;
}
static void F_280 ( struct V_23 * V_24 ,
struct V_440 * V_353 ,
struct V_440 * V_441 ,
T_3 * clock , T_3 * V_488 ,
int V_486 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_62 * V_63 ;
int V_95 = V_97 -> V_95 ;
T_1 V_390 ;
bool V_494 ;
F_269 ( V_24 , clock , V_488 ) ;
V_494 = F_16 ( V_24 , V_41 ) ||
F_16 ( V_24 , V_38 ) ;
V_390 = V_495 ;
if ( F_16 ( V_24 , V_27 ) )
V_390 |= V_518 ;
else
V_390 |= V_519 ;
if ( V_494 ) {
int V_520 = F_278 ( V_441 ) ;
if ( V_520 > 1 ) {
if ( F_281 ( V_2 ) || F_282 ( V_2 ) || F_283 ( V_2 ) )
V_390 |= ( V_520 - 1 ) << V_521 ;
}
V_390 |= V_522 ;
}
if ( F_16 ( V_24 , V_32 ) )
V_390 |= V_522 ;
if ( F_21 ( V_2 ) )
V_390 |= ( 1 << ( clock -> V_56 - 1 ) ) << V_523 ;
else {
V_390 |= ( 1 << ( clock -> V_56 - 1 ) ) << V_524 ;
if ( F_20 ( V_2 ) && V_488 )
V_390 |= ( 1 << ( V_488 -> V_56 - 1 ) ) << V_525 ;
}
switch ( clock -> V_57 ) {
case 5 :
V_390 |= V_526 ;
break;
case 7 :
V_390 |= V_527 ;
break;
case 10 :
V_390 |= V_528 ;
break;
case 14 :
V_390 |= V_529 ;
break;
}
if ( F_43 ( V_2 ) -> V_102 >= 4 )
V_390 |= ( 6 << V_530 ) ;
if ( V_494 && F_16 ( V_24 , V_531 ) )
V_390 |= V_532 ;
else if ( F_16 ( V_24 , V_531 ) )
V_390 |= 3 ;
else if ( F_16 ( V_24 , V_27 ) &&
F_263 ( V_4 ) && V_486 < 2 )
V_390 |= V_533 ;
else
V_390 |= V_534 ;
V_390 |= V_127 ;
F_11 ( F_55 ( V_95 ) , V_390 & ~ V_127 ) ;
F_14 ( F_55 ( V_95 ) ) ;
F_95 ( 150 ) ;
F_26 (dev, crtc, encoder)
if ( V_63 -> V_535 )
V_63 -> V_535 ( V_63 ) ;
if ( F_16 ( V_24 , V_32 ) )
F_277 ( V_24 , V_353 , V_441 ) ;
F_11 ( F_55 ( V_95 ) , V_390 ) ;
F_14 ( F_55 ( V_95 ) ) ;
F_95 ( 150 ) ;
if ( F_43 ( V_2 ) -> V_102 >= 4 ) {
T_1 V_303 = 0 ;
if ( V_494 ) {
V_303 = F_278 ( V_441 ) ;
if ( V_303 > 1 )
V_303 = ( V_303 - 1 ) << V_515 ;
else
V_303 = 0 ;
}
F_11 ( F_279 ( V_95 ) , V_303 ) ;
} else {
F_11 ( F_55 ( V_95 ) , V_390 ) ;
}
}
static void F_284 ( struct V_23 * V_24 ,
struct V_440 * V_441 ,
T_3 * clock , T_3 * V_488 ,
int V_486 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_62 * V_63 ;
int V_95 = V_97 -> V_95 ;
T_1 V_390 ;
F_269 ( V_24 , clock , V_488 ) ;
V_390 = V_495 ;
if ( F_16 ( V_24 , V_27 ) ) {
V_390 |= ( 1 << ( clock -> V_56 - 1 ) ) << V_524 ;
} else {
if ( clock -> V_56 == 2 )
V_390 |= V_536 ;
else
V_390 |= ( clock -> V_56 - 2 ) << V_524 ;
if ( clock -> V_57 == 4 )
V_390 |= V_537 ;
}
if ( F_16 ( V_24 , V_531 ) )
V_390 |= 3 ;
else if ( F_16 ( V_24 , V_27 ) &&
F_263 ( V_4 ) && V_486 < 2 )
V_390 |= V_533 ;
else
V_390 |= V_534 ;
V_390 |= V_127 ;
F_11 ( F_55 ( V_95 ) , V_390 & ~ V_127 ) ;
F_14 ( F_55 ( V_95 ) ) ;
F_95 ( 150 ) ;
F_26 (dev, crtc, encoder)
if ( V_63 -> V_535 )
V_63 -> V_535 ( V_63 ) ;
F_11 ( F_55 ( V_95 ) , V_390 ) ;
F_14 ( F_55 ( V_95 ) ) ;
F_95 ( 150 ) ;
F_11 ( F_55 ( V_95 ) , V_390 ) ;
}
static void F_285 ( struct V_97 * V_97 ,
struct V_440 * V_353 ,
struct V_440 * V_441 )
{
struct V_1 * V_2 = V_97 -> V_208 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_95 V_95 = V_97 -> V_95 ;
enum V_94 V_98 = V_97 -> V_98 ;
T_5 V_538 ;
if ( ! F_23 ( V_2 ) && V_441 -> V_338 & V_539 ) {
V_441 -> V_540 -= 1 ;
V_441 -> V_541 -= 1 ;
V_538 = V_441 -> V_542
- V_441 -> V_543 / 2 ;
} else {
V_538 = 0 ;
}
if ( F_43 ( V_2 ) -> V_102 > 3 )
F_11 ( F_197 ( V_98 ) , V_538 ) ;
F_11 ( F_185 ( V_98 ) ,
( V_441 -> V_544 - 1 ) |
( ( V_441 -> V_543 - 1 ) << 16 ) ) ;
F_11 ( F_187 ( V_98 ) ,
( V_441 -> V_545 - 1 ) |
( ( V_441 -> V_546 - 1 ) << 16 ) ) ;
F_11 ( F_189 ( V_98 ) ,
( V_441 -> V_542 - 1 ) |
( ( V_441 -> V_547 - 1 ) << 16 ) ) ;
F_11 ( F_191 ( V_98 ) ,
( V_441 -> V_548 - 1 ) |
( ( V_441 -> V_540 - 1 ) << 16 ) ) ;
F_11 ( F_193 ( V_98 ) ,
( V_441 -> V_549 - 1 ) |
( ( V_441 -> V_541 - 1 ) << 16 ) ) ;
F_11 ( F_195 ( V_98 ) ,
( V_441 -> V_550 - 1 ) |
( ( V_441 -> V_551 - 1 ) << 16 ) ) ;
if ( F_71 ( V_2 ) && V_98 == V_152 &&
( V_95 == V_149 || V_95 == V_314 ) )
F_11 ( F_191 ( V_95 ) , F_4 ( F_191 ( V_98 ) ) ) ;
F_11 ( F_286 ( V_95 ) ,
( ( V_353 -> V_421 - 1 ) << 16 ) | ( V_353 -> V_423 - 1 ) ) ;
}
static int F_287 ( struct V_23 * V_24 ,
struct V_440 * V_353 ,
struct V_440 * V_441 ,
int V_245 , int V_246 ,
struct V_252 * V_253 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
int V_156 = V_97 -> V_156 ;
int V_25 , V_486 = 0 ;
T_3 clock , V_488 ;
T_1 V_257 , V_552 ;
bool V_553 , V_554 = false , V_494 = false ;
bool V_555 = false , V_556 = false , V_557 = false ;
struct V_62 * V_63 ;
const T_2 * V_26 ;
int V_235 ;
F_26 (dev, crtc, encoder) {
switch ( V_63 -> type ) {
case V_27 :
V_555 = true ;
break;
case V_41 :
case V_38 :
V_494 = true ;
if ( V_63 -> V_558 )
V_556 = true ;
break;
case V_531 :
V_556 = true ;
break;
case V_32 :
V_557 = true ;
break;
}
V_486 ++ ;
}
V_25 = F_267 ( V_24 , V_486 ) ;
V_26 = F_19 ( V_24 , V_25 ) ;
V_553 = V_26 -> V_559 ( V_26 , V_24 , V_441 -> clock , V_25 , NULL ,
& clock ) ;
if ( ! V_553 ) {
F_10 ( L_99 ) ;
return - V_240 ;
}
F_210 ( V_24 , true ) ;
if ( V_555 && V_4 -> V_560 ) {
V_554 = V_26 -> V_559 ( V_26 , V_24 ,
V_4 -> V_561 ,
V_25 ,
& clock ,
& V_488 ) ;
}
if ( V_494 && V_556 )
F_268 ( V_441 , & clock ) ;
if ( F_23 ( V_2 ) )
F_284 ( V_24 , V_441 , & clock ,
V_554 ? & V_488 : NULL ,
V_486 ) ;
else if ( F_22 ( V_2 ) )
F_272 ( V_24 , V_353 , V_441 , & clock ,
V_554 ? & V_488 : NULL ,
V_486 ) ;
else
F_280 ( V_24 , V_353 , V_441 , & clock ,
V_554 ? & V_488 : NULL ,
V_486 ) ;
V_552 = F_4 ( F_45 ( V_95 ) ) ;
V_257 = V_562 ;
if ( V_95 == 0 )
V_257 &= ~ V_160 ;
else
V_257 |= V_563 ;
if ( V_95 == 0 && F_43 ( V_2 ) -> V_102 < 4 ) {
if ( V_353 -> clock >
V_4 -> V_286 . V_564 ( V_2 ) * 9 / 10 )
V_552 |= V_565 ;
else
V_552 &= ~ V_565 ;
}
V_552 &= ~ ( V_216 | V_566 ) ;
if ( V_557 ) {
if ( V_441 -> V_443 & V_484 ) {
V_552 |= V_567 |
V_566 |
V_568 ;
}
}
if ( F_22 ( V_2 ) && F_16 ( V_24 , V_33 ) ) {
if ( V_441 -> V_443 & V_484 ) {
V_552 |= V_567 |
V_155 |
V_104 ;
}
}
F_40 ( L_100 , V_95 == 0 ? 'A' : 'B' ) ;
F_288 ( V_353 ) ;
if ( F_289 ( V_2 ) ) {
if ( V_97 -> V_490 ) {
F_40 ( L_101 ) ;
V_552 |= V_569 ;
} else {
F_40 ( L_102 ) ;
V_552 &= ~ V_569 ;
}
}
V_552 &= ~ V_218 ;
if ( ! F_23 ( V_2 ) &&
V_441 -> V_338 & V_539 )
V_552 |= V_570 ;
else
V_552 |= V_571 ;
F_285 ( V_97 , V_353 , V_441 ) ;
F_11 ( F_290 ( V_156 ) ,
( ( V_353 -> V_423 - 1 ) << 16 ) |
( V_353 -> V_421 - 1 ) ) ;
F_11 ( F_291 ( V_156 ) , 0 ) ;
F_11 ( F_45 ( V_95 ) , V_552 ) ;
F_14 ( F_45 ( V_95 ) ) ;
F_113 ( V_4 , V_95 , false ) ;
F_41 ( V_2 , V_95 ) ;
F_11 ( F_73 ( V_156 ) , V_257 ) ;
F_14 ( F_73 ( V_156 ) ) ;
V_235 = F_146 ( V_24 , V_245 , V_246 , V_253 ) ;
F_204 ( V_2 ) ;
return V_235 ;
}
static void F_292 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_572 * V_573 = & V_2 -> V_573 ;
struct V_62 * V_63 ;
T_1 V_303 ;
bool V_574 = false ;
bool V_575 = false ;
bool V_576 = false ;
bool V_577 = false ;
bool V_578 = false ;
bool V_579 = false ;
F_237 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_63 -> type ) {
case V_27 :
V_577 = true ;
V_574 = true ;
break;
case V_33 :
V_577 = true ;
if ( F_174 ( & V_63 -> V_208 ) )
V_576 = true ;
else
V_575 = true ;
break;
}
}
if ( F_52 ( V_2 ) ) {
V_578 = V_4 -> V_580 ;
V_579 = V_578 ;
} else {
V_578 = false ;
V_579 = true ;
}
F_40 ( L_103 ,
V_577 , V_574 , V_576 , V_575 ,
V_578 ) ;
V_303 = F_4 ( V_162 ) ;
V_303 &= ~ V_164 ;
if ( V_578 )
V_303 |= V_581 ;
else
V_303 |= V_582 ;
if ( V_577 ) {
V_303 &= ~ V_163 ;
V_303 |= V_583 ;
if ( F_263 ( V_4 ) && V_579 ) {
F_40 ( L_104 ) ;
V_303 |= V_584 ;
} else
V_303 &= ~ V_584 ;
F_11 ( V_162 , V_303 ) ;
F_14 ( V_162 ) ;
F_95 ( 200 ) ;
V_303 &= ~ V_585 ;
if ( V_575 ) {
if ( F_263 ( V_4 ) && V_579 ) {
F_40 ( L_105 ) ;
V_303 |= V_586 ;
}
else
V_303 |= V_587 ;
} else
V_303 |= V_588 ;
F_11 ( V_162 , V_303 ) ;
F_14 ( V_162 ) ;
F_95 ( 200 ) ;
} else {
F_40 ( L_106 ) ;
V_303 &= ~ V_585 ;
V_303 |= V_588 ;
F_11 ( V_162 , V_303 ) ;
F_14 ( V_162 ) ;
F_95 ( 200 ) ;
V_303 &= ~ V_163 ;
V_303 |= V_589 ;
V_303 &= ~ V_584 ;
F_11 ( V_162 , V_303 ) ;
F_14 ( V_162 ) ;
F_95 ( 200 ) ;
}
}
static void F_293 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_572 * V_573 = & V_2 -> V_573 ;
struct V_62 * V_63 ;
bool V_590 = false ;
bool V_591 = false ;
T_1 V_195 ;
F_237 (encoder, &mode_config->encoder_list, base.head) {
switch ( V_63 -> type ) {
case V_39 :
V_590 = true ;
break;
}
}
if ( ! V_590 )
return;
F_147 ( & V_4 -> V_11 ) ;
if ( F_71 ( V_2 ) && ( V_2 -> V_592 & 0xFF00 ) == 0x0C00 )
V_591 = true ;
V_195 = F_99 ( V_4 , V_593 , V_200 ) ;
V_195 &= ~ V_352 ;
V_195 |= V_594 ;
F_98 ( V_4 , V_593 , V_195 , V_200 ) ;
F_95 ( 24 ) ;
V_195 = F_99 ( V_4 , V_593 , V_200 ) ;
V_195 &= ~ V_594 ;
F_98 ( V_4 , V_593 , V_195 , V_200 ) ;
if ( ! V_591 ) {
V_195 = F_4 ( V_595 ) ;
V_195 |= V_596 ;
F_11 ( V_595 , V_195 ) ;
if ( F_9 ( F_4 ( V_595 ) &
V_597 , 100 ) )
F_10 ( L_107 ) ;
V_195 = F_4 ( V_595 ) ;
V_195 &= ~ V_596 ;
F_11 ( V_595 , V_195 ) ;
if ( F_9 ( ( F_4 ( V_595 ) &
V_597 ) == 0 ,
100 ) )
F_10 ( L_108 ) ;
}
V_195 = F_99 ( V_4 , 0x8008 , V_598 ) ;
V_195 &= ~ ( 0xFF << 24 ) ;
V_195 |= ( 0x12 << 24 ) ;
F_98 ( V_4 , 0x8008 , V_195 , V_598 ) ;
if ( ! V_591 ) {
V_195 = F_99 ( V_4 , 0x808C , V_598 ) ;
V_195 &= ~ ( 0x3 << 6 ) ;
V_195 |= ( 1 << 6 ) | ( 1 << 0 ) ;
F_98 ( V_4 , 0x808C , V_195 , V_598 ) ;
}
if ( V_591 ) {
V_195 = F_99 ( V_4 , 0x800C , V_598 ) ;
V_195 |= 0x7FFF ;
F_98 ( V_4 , 0x800C , V_195 , V_598 ) ;
}
V_195 = F_99 ( V_4 , 0x2008 , V_598 ) ;
V_195 |= ( 1 << 11 ) ;
F_98 ( V_4 , 0x2008 , V_195 , V_598 ) ;
V_195 = F_99 ( V_4 , 0x2108 , V_598 ) ;
V_195 |= ( 1 << 11 ) ;
F_98 ( V_4 , 0x2108 , V_195 , V_598 ) ;
if ( V_591 ) {
V_195 = F_99 ( V_4 , 0x2038 , V_598 ) ;
V_195 |= ( 0x3F << 24 ) | ( 0xF << 20 ) | ( 0xF << 16 ) ;
F_98 ( V_4 , 0x2038 , V_195 , V_598 ) ;
V_195 = F_99 ( V_4 , 0x2138 , V_598 ) ;
V_195 |= ( 0x3F << 24 ) | ( 0xF << 20 ) | ( 0xF << 16 ) ;
F_98 ( V_4 , 0x2138 , V_195 , V_598 ) ;
V_195 = F_99 ( V_4 , 0x203C , V_598 ) ;
V_195 |= ( 0x3F << 8 ) ;
F_98 ( V_4 , 0x203C , V_195 , V_598 ) ;
V_195 = F_99 ( V_4 , 0x213C , V_598 ) ;
V_195 |= ( 0x3F << 8 ) ;
F_98 ( V_4 , 0x213C , V_195 , V_598 ) ;
}
V_195 = F_99 ( V_4 , 0x206C , V_598 ) ;
V_195 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_98 ( V_4 , 0x206C , V_195 , V_598 ) ;
V_195 = F_99 ( V_4 , 0x216C , V_598 ) ;
V_195 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_98 ( V_4 , 0x216C , V_195 , V_598 ) ;
if ( ! V_591 ) {
V_195 = F_99 ( V_4 , 0x2080 , V_598 ) ;
V_195 &= ~ ( 7 << 13 ) ;
V_195 |= ( 5 << 13 ) ;
F_98 ( V_4 , 0x2080 , V_195 , V_598 ) ;
V_195 = F_99 ( V_4 , 0x2180 , V_598 ) ;
V_195 &= ~ ( 7 << 13 ) ;
V_195 |= ( 5 << 13 ) ;
F_98 ( V_4 , 0x2180 , V_195 , V_598 ) ;
}
V_195 = F_99 ( V_4 , 0x208C , V_598 ) ;
V_195 &= ~ 0xFF ;
V_195 |= 0x1C ;
F_98 ( V_4 , 0x208C , V_195 , V_598 ) ;
V_195 = F_99 ( V_4 , 0x218C , V_598 ) ;
V_195 &= ~ 0xFF ;
V_195 |= 0x1C ;
F_98 ( V_4 , 0x218C , V_195 , V_598 ) ;
V_195 = F_99 ( V_4 , 0x2098 , V_598 ) ;
V_195 &= ~ ( 0xFF << 16 ) ;
V_195 |= ( 0x1C << 16 ) ;
F_98 ( V_4 , 0x2098 , V_195 , V_598 ) ;
V_195 = F_99 ( V_4 , 0x2198 , V_598 ) ;
V_195 &= ~ ( 0xFF << 16 ) ;
V_195 |= ( 0x1C << 16 ) ;
F_98 ( V_4 , 0x2198 , V_195 , V_598 ) ;
if ( ! V_591 ) {
V_195 = F_99 ( V_4 , 0x20C4 , V_598 ) ;
V_195 |= ( 1 << 27 ) ;
F_98 ( V_4 , 0x20C4 , V_195 , V_598 ) ;
V_195 = F_99 ( V_4 , 0x21C4 , V_598 ) ;
V_195 |= ( 1 << 27 ) ;
F_98 ( V_4 , 0x21C4 , V_195 , V_598 ) ;
V_195 = F_99 ( V_4 , 0x20EC , V_598 ) ;
V_195 &= ~ ( 0xF << 28 ) ;
V_195 |= ( 4 << 28 ) ;
F_98 ( V_4 , 0x20EC , V_195 , V_598 ) ;
V_195 = F_99 ( V_4 , 0x21EC , V_598 ) ;
V_195 &= ~ ( 0xF << 28 ) ;
V_195 |= ( 4 << 28 ) ;
F_98 ( V_4 , 0x21EC , V_195 , V_598 ) ;
}
V_195 = F_99 ( V_4 , V_599 , V_200 ) ;
V_195 |= V_600 ;
F_98 ( V_4 , V_599 , V_195 , V_200 ) ;
F_148 ( & V_4 -> V_11 ) ;
}
void F_294 ( struct V_1 * V_2 )
{
if ( F_52 ( V_2 ) || F_59 ( V_2 ) )
F_292 ( V_2 ) ;
else if ( F_57 ( V_2 ) )
F_293 ( V_2 ) ;
}
static int F_295 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_62 * V_63 ;
struct V_62 * V_601 = NULL ;
int V_486 = 0 ;
bool V_555 = false ;
F_26 (dev, crtc, encoder) {
switch ( V_63 -> type ) {
case V_27 :
V_555 = true ;
break;
case V_33 :
V_601 = V_63 ;
break;
}
V_486 ++ ;
}
if ( V_555 && F_263 ( V_4 ) && V_486 < 2 ) {
F_40 ( L_97 ,
V_4 -> V_487 ) ;
return V_4 -> V_487 * 1000 ;
}
return 120000 ;
}
static void F_296 ( struct V_23 * V_24 ,
struct V_440 * V_441 ,
bool V_602 )
{
struct V_3 * V_4 = V_24 -> V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_5 V_20 ;
V_20 = F_4 ( F_45 ( V_95 ) ) ;
V_20 &= ~ V_216 ;
switch ( V_97 -> V_483 ) {
case 18 :
V_20 |= V_567 ;
break;
case 24 :
V_20 |= V_603 ;
break;
case 30 :
V_20 |= V_604 ;
break;
case 36 :
V_20 |= V_605 ;
break;
default:
F_125 () ;
}
V_20 &= ~ ( V_566 | V_606 ) ;
if ( V_602 )
V_20 |= ( V_566 | V_568 ) ;
V_20 &= ~ V_218 ;
if ( V_441 -> V_338 & V_539 )
V_20 |= V_219 ;
else
V_20 |= V_571 ;
if ( V_441 -> V_443 & V_607 )
V_20 |= V_608 ;
else
V_20 &= ~ V_608 ;
F_11 ( F_45 ( V_95 ) , V_20 ) ;
F_14 ( F_45 ( V_95 ) ) ;
}
static void F_297 ( struct V_23 * V_24 ,
const struct V_440 * V_441 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_6 V_609 = 0x7800 ;
if ( V_441 -> V_443 & V_607 )
V_609 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_11 ( F_298 ( V_95 ) , V_609 << 16 ) ;
F_11 ( F_299 ( V_95 ) , 0 ) ;
F_11 ( F_300 ( V_95 ) , V_609 ) ;
F_11 ( F_301 ( V_95 ) , 0 ) ;
F_11 ( F_302 ( V_95 ) , 0 ) ;
F_11 ( F_303 ( V_95 ) , V_609 << 16 ) ;
F_11 ( F_304 ( V_95 ) , 0 ) ;
F_11 ( F_305 ( V_95 ) , 0 ) ;
F_11 ( F_306 ( V_95 ) , 0 ) ;
if ( F_43 ( V_2 ) -> V_102 > 6 ) {
T_6 V_610 = 0 ;
if ( V_441 -> V_443 & V_607 )
V_610 = ( 16 * ( 1 << 13 ) / 255 ) & 0x1fff ;
F_11 ( F_307 ( V_95 ) , V_610 ) ;
F_11 ( F_308 ( V_95 ) , V_610 ) ;
F_11 ( F_309 ( V_95 ) , V_610 ) ;
F_11 ( F_310 ( V_95 ) , 0 ) ;
} else {
T_5 V_353 = V_611 ;
if ( V_441 -> V_443 & V_607 )
V_353 |= V_612 ;
F_11 ( F_310 ( V_95 ) , V_353 ) ;
}
}
static void F_311 ( struct V_23 * V_24 ,
struct V_440 * V_441 ,
bool V_602 )
{
struct V_3 * V_4 = V_24 -> V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
enum V_94 V_98 = V_97 -> V_98 ;
T_5 V_20 ;
V_20 = F_4 ( F_45 ( V_98 ) ) ;
V_20 &= ~ ( V_566 | V_606 ) ;
if ( V_602 )
V_20 |= ( V_566 | V_568 ) ;
V_20 &= ~ V_226 ;
if ( V_441 -> V_338 & V_539 )
V_20 |= V_219 ;
else
V_20 |= V_571 ;
F_11 ( F_45 ( V_98 ) , V_20 ) ;
F_14 ( F_45 ( V_98 ) ) ;
}
static bool F_312 ( struct V_23 * V_24 ,
struct V_440 * V_441 ,
T_3 * clock ,
bool * V_554 ,
T_3 * V_488 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_62 * V_62 ;
int V_25 ;
const T_2 * V_26 ;
bool V_235 , V_494 = false , V_556 = false , V_555 = false ;
F_26 (dev, crtc, intel_encoder) {
switch ( V_62 -> type ) {
case V_27 :
V_555 = true ;
break;
case V_41 :
case V_38 :
V_494 = true ;
if ( V_62 -> V_558 )
V_556 = true ;
break;
case V_531 :
V_556 = true ;
break;
}
}
V_25 = F_295 ( V_24 ) ;
V_26 = F_19 ( V_24 , V_25 ) ;
V_235 = V_26 -> V_559 ( V_26 , V_24 , V_441 -> clock , V_25 , NULL ,
clock ) ;
if ( ! V_235 )
return false ;
if ( V_555 && V_4 -> V_560 ) {
* V_554 = V_26 -> V_559 ( V_26 , V_24 ,
V_4 -> V_561 ,
V_25 ,
clock ,
V_488 ) ;
}
if ( V_494 && V_556 )
F_268 ( V_441 , clock ) ;
return true ;
}
static void F_313 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_303 ;
V_303 = F_4 ( V_315 ) ;
if ( V_303 & V_316 )
return;
F_2 ( F_4 ( F_65 ( V_149 ) ) & V_136 ) ;
F_2 ( F_4 ( F_65 ( V_314 ) ) & V_136 ) ;
V_303 |= V_316 ;
F_40 ( L_109 ) ;
F_11 ( V_315 , V_303 ) ;
F_14 ( V_315 ) ;
}
static bool F_314 ( struct V_97 * V_97 )
{
struct V_1 * V_2 = V_97 -> V_208 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_312 =
F_35 ( V_4 -> V_96 [ V_149 ] ) ;
F_40 ( L_110 ,
V_97 -> V_95 , V_97 -> V_320 ) ;
if ( V_97 -> V_320 > 4 ) {
F_40 ( L_111 ,
V_97 -> V_95 , V_97 -> V_320 ) ;
V_97 -> V_320 = 4 ;
return false ;
}
if ( V_4 -> V_301 == 2 )
return true ;
switch ( V_97 -> V_95 ) {
case V_142 :
return true ;
case V_149 :
if ( V_4 -> V_96 [ V_314 ] -> V_124 &&
V_97 -> V_320 > 2 ) {
F_40 ( L_112 ,
V_97 -> V_95 , V_97 -> V_320 ) ;
V_97 -> V_320 = 2 ;
return false ;
}
if ( V_97 -> V_320 > 2 )
F_2 ( F_4 ( V_315 ) & V_316 ) ;
else
F_313 ( V_2 ) ;
return true ;
case V_314 :
if ( ! V_312 -> V_208 . V_124 || V_312 -> V_320 <= 2 ) {
if ( V_97 -> V_320 > 2 ) {
F_40 ( L_112 ,
V_97 -> V_95 , V_97 -> V_320 ) ;
V_97 -> V_320 = 2 ;
return false ;
}
} else {
F_40 ( L_113 ) ;
return false ;
}
F_313 ( V_2 ) ;
return true ;
default:
F_125 () ;
}
}
int F_315 ( int V_613 , int V_614 , int V_483 )
{
T_1 V_615 = V_613 * V_483 * 21 / 20 ;
return V_615 / ( V_614 * 8 ) + 1 ;
}
static void F_316 ( struct V_23 * V_24 ,
struct V_440 * V_353 ,
struct V_440 * V_441 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
enum V_94 V_98 = V_97 -> V_98 ;
struct V_62 * V_62 , * V_601 = NULL ;
struct V_464 V_465 = { 0 } ;
int V_613 , V_520 , V_616 , V_614 ;
bool V_557 = false , V_617 = false ;
F_26 (dev, crtc, intel_encoder) {
switch ( V_62 -> type ) {
case V_32 :
V_557 = true ;
break;
case V_33 :
V_557 = true ;
if ( ! F_174 ( & V_62 -> V_208 ) )
V_617 = true ;
V_601 = V_62 ;
break;
}
}
V_520 = F_278 ( V_441 ) ;
V_616 = 0 ;
if ( V_617 ) {
F_317 ( V_601 , & V_616 , & V_614 ) ;
} else {
V_614 = F_5 ( V_2 ) * F_318 ( 100 ) / F_319 ( 1 ) / 10 ;
}
if ( V_601 )
V_613 = F_320 ( V_601 , V_353 ) ;
else if ( V_557 )
V_613 = V_353 -> clock ;
else
V_613 = V_441 -> clock ;
if ( ! V_616 )
V_616 = F_315 ( V_613 , V_614 ,
V_97 -> V_483 ) ;
V_97 -> V_320 = V_616 ;
if ( V_520 > 1 )
V_614 *= V_520 ;
F_262 ( V_97 -> V_483 , V_616 , V_613 , V_614 , & V_465 ) ;
F_11 ( F_183 ( V_98 ) , F_321 ( V_465 . V_466 ) | V_465 . V_467 ) ;
F_11 ( F_322 ( V_98 ) , V_465 . V_468 ) ;
F_11 ( F_323 ( V_98 ) , V_465 . V_469 ) ;
F_11 ( F_324 ( V_98 ) , V_465 . V_470 ) ;
}
static T_5 F_325 ( struct V_97 * V_97 ,
struct V_440 * V_441 ,
T_3 * clock , T_1 V_391 )
{
struct V_23 * V_24 = & V_97 -> V_208 ;
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_62 * V_62 ;
T_5 V_390 ;
int V_618 , V_520 , V_486 = 0 ;
bool V_555 = false , V_494 = false , V_556 = false ;
bool V_557 = false , V_617 = false ;
F_26 (dev, crtc, intel_encoder) {
switch ( V_62 -> type ) {
case V_27 :
V_555 = true ;
break;
case V_41 :
case V_38 :
V_494 = true ;
if ( V_62 -> V_558 )
V_556 = true ;
break;
case V_531 :
V_556 = true ;
break;
case V_32 :
V_557 = true ;
break;
case V_33 :
V_557 = true ;
if ( ! F_174 ( & V_62 -> V_208 ) )
V_617 = true ;
break;
}
V_486 ++ ;
}
V_618 = 21 ;
if ( V_555 ) {
if ( ( F_263 ( V_4 ) &&
V_4 -> V_487 == 100 ) ||
F_17 ( V_2 ) )
V_618 = 25 ;
} else if ( V_494 && V_556 )
V_618 = 20 ;
if ( clock -> V_53 < V_618 * clock -> V_59 )
V_391 |= V_619 ;
V_390 = 0 ;
if ( V_555 )
V_390 |= V_518 ;
else
V_390 |= V_519 ;
if ( V_494 ) {
V_520 = F_278 ( V_441 ) ;
if ( V_520 > 1 ) {
V_390 |= ( V_520 - 1 ) << V_620 ;
}
V_390 |= V_522 ;
}
if ( V_557 && ! V_617 )
V_390 |= V_522 ;
V_390 |= ( 1 << ( clock -> V_56 - 1 ) ) << V_524 ;
V_390 |= ( 1 << ( clock -> V_56 - 1 ) ) << V_525 ;
switch ( clock -> V_57 ) {
case 5 :
V_390 |= V_526 ;
break;
case 7 :
V_390 |= V_527 ;
break;
case 10 :
V_390 |= V_528 ;
break;
case 14 :
V_390 |= V_529 ;
break;
}
if ( V_494 && V_556 )
V_390 |= V_532 ;
else if ( V_556 )
V_390 |= 3 ;
else if ( V_555 && F_263 ( V_4 ) && V_486 < 2 )
V_390 |= V_533 ;
else
V_390 |= V_534 ;
return V_390 ;
}
static int F_326 ( struct V_23 * V_24 ,
struct V_440 * V_353 ,
struct V_440 * V_441 ,
int V_245 , int V_246 ,
struct V_252 * V_253 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
int V_156 = V_97 -> V_156 ;
int V_486 = 0 ;
T_3 clock , V_488 ;
T_1 V_390 , V_391 = 0 , V_489 = 0 ;
bool V_553 , V_554 = false ;
bool V_555 = false , V_557 = false , V_617 = false ;
struct V_62 * V_63 ;
int V_235 ;
bool V_602 , V_621 ;
F_26 (dev, crtc, encoder) {
switch ( V_63 -> type ) {
case V_27 :
V_555 = true ;
break;
case V_32 :
V_557 = true ;
break;
case V_33 :
V_557 = true ;
if ( ! F_174 ( & V_63 -> V_208 ) )
V_617 = true ;
break;
}
V_486 ++ ;
}
F_46 ( ! ( F_52 ( V_2 ) || F_59 ( V_2 ) ) ,
L_114 , F_327 ( V_2 ) ) ;
V_553 = F_312 ( V_24 , V_441 , & clock ,
& V_554 , & V_488 ) ;
if ( ! V_553 ) {
F_10 ( L_99 ) ;
return - V_240 ;
}
F_210 ( V_24 , true ) ;
V_602 = F_264 ( V_24 , V_253 , & V_97 -> V_483 ,
V_441 ) ;
if ( V_555 && V_4 -> V_622 )
V_602 = true ;
V_391 = clock . V_59 << 16 | clock . V_61 << 8 | clock . V_54 ;
if ( V_554 )
V_489 = V_488 . V_59 << 16 | V_488 . V_61 << 8 |
V_488 . V_54 ;
V_390 = F_325 ( V_97 , V_441 , & clock , V_391 ) ;
F_40 ( L_115 , V_95 ) ;
F_288 ( V_353 ) ;
if ( ! V_617 ) {
struct V_128 * V_129 ;
V_129 = F_201 ( V_97 , V_390 , V_391 ) ;
if ( V_129 == NULL ) {
F_58 ( L_116 ,
V_95 ) ;
return - V_240 ;
}
} else
F_200 ( V_97 ) ;
if ( V_557 && ! V_617 )
F_277 ( V_24 , V_353 , V_441 ) ;
F_26 (dev, crtc, encoder)
if ( V_63 -> V_535 )
V_63 -> V_535 ( V_63 ) ;
if ( V_97 -> V_209 ) {
F_11 ( V_97 -> V_209 -> V_130 , V_390 ) ;
F_14 ( V_97 -> V_209 -> V_130 ) ;
F_95 ( 150 ) ;
F_11 ( V_97 -> V_209 -> V_130 , V_390 ) ;
}
V_97 -> V_490 = false ;
if ( V_97 -> V_209 ) {
if ( V_555 && V_554 && V_491 ) {
F_11 ( V_97 -> V_209 -> V_623 , V_489 ) ;
V_97 -> V_490 = true ;
} else {
F_11 ( V_97 -> V_209 -> V_623 , V_391 ) ;
}
}
F_285 ( V_97 , V_353 , V_441 ) ;
F_316 ( V_24 , V_353 , V_441 ) ;
V_621 = F_314 ( V_97 ) ;
F_296 ( V_24 , V_441 , V_602 ) ;
F_41 ( V_2 , V_95 ) ;
F_11 ( F_73 ( V_156 ) , V_562 ) ;
F_14 ( F_73 ( V_156 ) ) ;
V_235 = F_146 ( V_24 , V_245 , V_246 , V_253 ) ;
F_204 ( V_2 ) ;
F_328 ( V_2 , V_95 , V_441 ) ;
return V_621 ? V_235 : - V_240 ;
}
static void F_329 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_403 = false ;
struct V_97 * V_24 ;
struct V_62 * V_63 ;
F_237 (crtc, &dev->mode_config.crtc_list, base.head) {
if ( V_24 -> V_95 != V_142 && V_24 -> V_208 . V_124 )
V_403 = true ;
}
F_237 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_63 -> type != V_33 &&
V_63 -> V_426 )
V_403 = true ;
}
if ( V_4 -> V_399 )
V_403 = true ;
F_330 ( V_2 , V_403 ) ;
}
static int F_331 ( struct V_23 * V_24 ,
struct V_440 * V_353 ,
struct V_440 * V_441 ,
int V_245 , int V_246 ,
struct V_252 * V_253 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
int V_156 = V_97 -> V_156 ;
int V_486 = 0 ;
bool V_557 = false , V_617 = false ;
struct V_62 * V_63 ;
int V_235 ;
bool V_602 ;
F_26 (dev, crtc, encoder) {
switch ( V_63 -> type ) {
case V_32 :
V_557 = true ;
break;
case V_33 :
V_557 = true ;
if ( ! F_174 ( & V_63 -> V_208 ) )
V_617 = true ;
break;
}
V_486 ++ ;
}
if ( V_617 )
V_97 -> V_98 = V_152 ;
else
V_97 -> V_98 = V_95 ;
F_46 ( ! F_57 ( V_2 ) , L_114 ,
F_327 ( V_2 ) ) ;
F_46 ( V_486 != 1 , L_117 ,
V_486 , F_69 ( V_95 ) ) ;
F_2 ( F_4 ( F_45 ( V_97 -> V_98 ) ) &
( V_155 | V_104 ) ) ;
F_2 ( F_4 ( F_73 ( V_156 ) ) & V_157 ) ;
if ( ! F_332 ( V_24 , V_441 -> clock ) )
return - V_240 ;
F_210 ( V_24 , true ) ;
V_602 = F_264 ( V_24 , V_253 , & V_97 -> V_483 ,
V_441 ) ;
F_40 ( L_115 , V_95 ) ;
F_288 ( V_353 ) ;
if ( V_557 && ! V_617 )
F_277 ( V_24 , V_353 , V_441 ) ;
V_97 -> V_490 = false ;
F_285 ( V_97 , V_353 , V_441 ) ;
if ( ! V_557 || V_617 )
F_316 ( V_24 , V_353 , V_441 ) ;
F_311 ( V_24 , V_441 , V_602 ) ;
F_297 ( V_24 , V_441 ) ;
F_11 ( F_73 ( V_156 ) , V_562 | V_624 ) ;
F_14 ( F_73 ( V_156 ) ) ;
V_235 = F_146 ( V_24 , V_245 , V_246 , V_253 ) ;
F_204 ( V_2 ) ;
F_328 ( V_2 , V_95 , V_441 ) ;
return V_235 ;
}
static int F_333 ( struct V_23 * V_24 ,
struct V_440 * V_353 ,
struct V_440 * V_441 ,
int V_245 , int V_246 ,
struct V_252 * V_253 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_625 * V_626 ;
struct V_62 * V_63 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
int V_235 ;
F_334 ( V_2 , V_95 ) ;
V_235 = V_4 -> V_286 . V_627 ( V_24 , V_353 , V_441 ,
V_245 , V_246 , V_253 ) ;
F_335 ( V_2 , V_95 ) ;
if ( V_235 != 0 )
return V_235 ;
F_26 (dev, crtc, encoder) {
F_40 ( L_118 ,
V_63 -> V_208 . V_208 . V_213 ,
F_336 ( & V_63 -> V_208 ) ,
V_353 -> V_208 . V_213 , V_353 -> V_628 ) ;
V_626 = V_63 -> V_208 . V_629 ;
V_626 -> V_630 ( & V_63 -> V_208 , V_353 , V_441 ) ;
}
return 0 ;
}
static bool F_337 ( struct V_429 * V_430 ,
int V_631 , T_5 V_632 ,
int V_633 , T_5 V_634 ,
int V_635 )
{
struct V_3 * V_4 = V_430 -> V_2 -> V_5 ;
T_7 * V_636 = V_430 -> V_636 ;
T_5 V_158 ;
V_158 = F_4 ( V_631 ) ;
V_158 &= V_632 ;
if ( ! V_636 [ 0 ] )
return ! V_158 ;
if ( ! V_158 )
return false ;
V_158 = F_4 ( V_633 ) ;
V_158 &= ~ V_634 ;
F_11 ( V_633 , V_158 ) ;
for ( V_158 = 0 ; V_158 < V_636 [ 2 ] ; V_158 ++ )
if ( F_4 ( V_635 ) != * ( ( T_5 * ) V_636 + V_158 ) )
return false ;
return true ;
}
static void F_338 ( struct V_429 * V_430 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = V_430 -> V_2 -> V_5 ;
T_7 * V_636 = V_430 -> V_636 ;
T_5 V_637 ;
T_5 V_638 ;
T_5 V_158 ;
V_158 = F_4 ( V_639 ) ;
if ( V_158 == V_640 || V_158 == V_641 )
V_637 = V_642 ;
else
V_637 = V_643 ;
if ( F_337 ( V_430 ,
V_644 , V_637 ,
V_644 , V_645 ,
V_646 ) )
return;
V_158 = F_4 ( V_644 ) ;
V_158 &= ~ ( V_637 | V_645 ) ;
V_638 = ( V_158 >> 9 ) & 0x1f ;
F_11 ( V_644 , V_158 ) ;
if ( ! V_636 [ 0 ] )
return;
V_638 = F_339 ( T_7 , V_636 [ 2 ] , V_638 ) ;
F_58 ( L_119 , V_638 ) ;
for ( V_158 = 0 ; V_158 < V_638 ; V_158 ++ )
F_11 ( V_646 , * ( ( T_5 * ) V_636 + V_158 ) ) ;
V_158 = F_4 ( V_644 ) ;
V_158 |= V_637 ;
F_11 ( V_644 , V_158 ) ;
}
static void F_340 ( struct V_429 * V_430 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = V_430 -> V_2 -> V_5 ;
T_7 * V_636 = V_430 -> V_636 ;
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
T_5 V_637 ;
T_5 V_158 ;
int V_638 ;
int V_95 = F_35 ( V_24 ) -> V_95 ;
int V_195 ;
int V_647 = F_341 ( V_95 ) ;
int V_648 = F_342 ( V_95 ) ;
int V_649 = F_343 ( V_95 ) ;
int V_650 = V_651 ;
F_58 ( L_120 ) ;
F_58 ( L_121 ) ;
V_195 = F_4 ( V_650 ) ;
V_195 |= ( V_652 << ( V_95 * 4 ) ) ;
F_11 ( V_650 , V_195 ) ;
F_41 ( V_2 , V_95 ) ;
V_195 = F_4 ( V_650 ) ;
F_58 ( L_122 , V_195 ) ;
V_195 |= ( V_653 << ( V_95 * 4 ) ) ;
F_11 ( V_650 , V_195 ) ;
V_195 = F_4 ( V_650 ) ;
F_58 ( L_123 , V_195 ) ;
V_195 = F_4 ( V_649 ) ;
F_58 ( L_124 , V_195 ) ;
V_195 &= ~ ( V_654 | V_655 ) ;
F_11 ( V_649 , V_195 ) ;
F_58 ( L_125 , F_69 ( V_95 ) ) ;
V_637 = V_653 << ( V_95 * 4 ) ;
V_97 -> V_431 = true ;
if ( F_16 ( V_24 , V_32 ) ) {
F_58 ( L_126 ) ;
V_636 [ 5 ] |= ( 1 << 2 ) ;
F_11 ( V_649 , V_654 ) ;
} else
F_11 ( V_649 , 0 ) ;
if ( F_337 ( V_430 ,
V_650 , V_637 ,
V_648 , V_656 ,
V_647 ) )
return;
V_158 = F_4 ( V_650 ) ;
V_158 &= ~ V_637 ;
F_11 ( V_650 , V_158 ) ;
if ( ! V_636 [ 0 ] )
return;
V_158 = F_4 ( V_648 ) ;
V_158 &= ~ V_656 ;
F_11 ( V_648 , V_158 ) ;
V_158 = ( V_158 >> 29 ) & V_657 ;
F_58 ( L_127 , V_158 ) ;
V_638 = F_339 ( T_7 , V_636 [ 2 ] , 21 ) ;
F_58 ( L_119 , V_638 ) ;
for ( V_158 = 0 ; V_158 < V_638 ; V_158 ++ )
F_11 ( V_647 , * ( ( T_5 * ) V_636 + V_158 ) ) ;
V_158 = F_4 ( V_650 ) ;
V_158 |= V_637 ;
F_11 ( V_650 , V_158 ) ;
}
static void F_344 ( struct V_429 * V_430 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = V_430 -> V_2 -> V_5 ;
T_7 * V_636 = V_430 -> V_636 ;
T_5 V_637 ;
T_5 V_158 ;
int V_638 ;
int V_647 ;
int V_649 ;
int V_648 ;
int V_650 ;
int V_95 = F_35 ( V_24 ) -> V_95 ;
if ( F_52 ( V_430 -> V_2 ) ) {
V_647 = F_345 ( V_95 ) ;
V_649 = F_346 ( V_95 ) ;
V_648 = F_347 ( V_95 ) ;
V_650 = V_658 ;
} else {
V_647 = F_348 ( V_95 ) ;
V_649 = F_349 ( V_95 ) ;
V_648 = F_350 ( V_95 ) ;
V_650 = V_659 ;
}
F_58 ( L_125 , F_69 ( V_95 ) ) ;
V_158 = F_4 ( V_648 ) ;
V_158 = ( V_158 >> 29 ) & V_657 ;
if ( ! V_158 ) {
F_58 ( L_128 ) ;
V_637 = V_660 ;
V_637 |= V_660 << 4 ;
V_637 |= V_660 << 8 ;
} else {
F_58 ( L_129 , 'A' + V_158 ) ;
V_637 = V_660 << ( ( V_158 - 1 ) * 4 ) ;
}
if ( F_16 ( V_24 , V_32 ) ) {
F_58 ( L_126 ) ;
V_636 [ 5 ] |= ( 1 << 2 ) ;
F_11 ( V_649 , V_654 ) ;
} else
F_11 ( V_649 , 0 ) ;
if ( F_337 ( V_430 ,
V_650 , V_637 ,
V_648 , V_656 ,
V_647 ) )
return;
V_158 = F_4 ( V_650 ) ;
V_158 &= ~ V_637 ;
F_11 ( V_650 , V_158 ) ;
if ( ! V_636 [ 0 ] )
return;
V_158 = F_4 ( V_648 ) ;
V_158 &= ~ V_656 ;
F_11 ( V_648 , V_158 ) ;
V_638 = F_339 ( T_7 , V_636 [ 2 ] , 21 ) ;
F_58 ( L_119 , V_638 ) ;
for ( V_158 = 0 ; V_158 < V_638 ; V_158 ++ )
F_11 ( V_647 , * ( ( T_5 * ) V_636 + V_158 ) ) ;
V_158 = F_4 ( V_650 ) ;
V_158 |= V_637 ;
F_11 ( V_650 , V_158 ) ;
}
void F_351 ( struct V_435 * V_63 ,
struct V_440 * V_353 )
{
struct V_23 * V_24 = V_63 -> V_24 ;
struct V_429 * V_430 ;
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_430 = F_352 ( V_63 , V_353 ) ;
if ( ! V_430 )
return;
F_58 ( L_130 ,
V_430 -> V_208 . V_213 ,
F_245 ( V_430 ) ,
V_430 -> V_63 -> V_208 . V_213 ,
F_336 ( V_430 -> V_63 ) ) ;
V_430 -> V_636 [ 6 ] = F_353 ( V_430 , V_353 ) / 2 ;
if ( V_4 -> V_286 . V_661 )
V_4 -> V_286 . V_661 ( V_430 , V_24 ) ;
}
void F_209 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_662 = F_354 ( V_97 -> V_95 ) ;
int V_158 ;
if ( ! V_24 -> V_124 || ! V_97 -> V_211 )
return;
if ( F_3 ( V_2 ) )
V_662 = F_355 ( V_97 -> V_95 ) ;
for ( V_158 = 0 ; V_158 < 256 ; V_158 ++ ) {
F_11 ( V_662 + 4 * V_158 ,
( V_97 -> V_663 [ V_158 ] << 16 ) |
( V_97 -> V_664 [ V_158 ] << 8 ) |
V_97 -> V_665 [ V_158 ] ) ;
}
}
static void F_356 ( struct V_23 * V_24 , T_1 V_208 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
bool V_666 = V_208 != 0 ;
T_1 V_409 ;
if ( V_97 -> V_667 == V_666 )
return;
V_409 = F_4 ( V_668 ) ;
if ( V_666 ) {
F_11 ( V_669 , V_208 ) ;
V_409 &= ~ ( V_670 ) ;
V_409 |= V_671 |
V_672 |
V_673 ;
} else
V_409 &= ~ ( V_671 | V_672 ) ;
F_11 ( V_668 , V_409 ) ;
V_97 -> V_667 = V_666 ;
}
static void F_357 ( struct V_23 * V_24 , T_1 V_208 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
bool V_666 = V_208 != 0 ;
if ( V_97 -> V_667 != V_666 ) {
T_5 V_409 = F_4 ( F_228 ( V_95 ) ) ;
if ( V_208 ) {
V_409 &= ~ ( V_410 | V_674 ) ;
V_409 |= V_414 | V_675 ;
V_409 |= V_95 << 28 ;
} else {
V_409 &= ~ ( V_410 | V_675 ) ;
V_409 |= V_676 ;
}
F_11 ( F_228 ( V_95 ) , V_409 ) ;
V_97 -> V_667 = V_666 ;
}
F_11 ( F_229 ( V_95 ) , V_208 ) ;
}
static void F_358 ( struct V_23 * V_24 , T_1 V_208 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
bool V_666 = V_208 != 0 ;
if ( V_97 -> V_667 != V_666 ) {
T_5 V_409 = F_4 ( F_359 ( V_95 ) ) ;
if ( V_208 ) {
V_409 &= ~ V_410 ;
V_409 |= V_414 | V_675 ;
} else {
V_409 &= ~ ( V_410 | V_675 ) ;
V_409 |= V_676 ;
}
if ( F_71 ( V_2 ) )
V_409 |= V_677 ;
F_11 ( F_359 ( V_95 ) , V_409 ) ;
V_97 -> V_667 = V_666 ;
}
F_11 ( F_360 ( V_95 ) , V_208 ) ;
}
static void F_210 ( struct V_23 * V_24 ,
bool V_212 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
int V_245 = V_97 -> V_678 ;
int V_246 = V_97 -> V_679 ;
T_1 V_208 , V_680 ;
bool V_666 ;
V_680 = 0 ;
if ( V_212 && V_24 -> V_124 && V_24 -> V_253 ) {
V_208 = V_97 -> V_681 ;
if ( V_245 > ( int ) V_24 -> V_253 -> V_682 )
V_208 = 0 ;
if ( V_246 > ( int ) V_24 -> V_253 -> V_683 )
V_208 = 0 ;
} else
V_208 = 0 ;
if ( V_245 < 0 ) {
if ( V_245 + V_97 -> V_684 < 0 )
V_208 = 0 ;
V_680 |= V_685 << V_686 ;
V_245 = - V_245 ;
}
V_680 |= V_245 << V_686 ;
if ( V_246 < 0 ) {
if ( V_246 + V_97 -> V_687 < 0 )
V_208 = 0 ;
V_680 |= V_685 << V_688 ;
V_246 = - V_246 ;
}
V_680 |= V_246 << V_688 ;
V_666 = V_208 != 0 ;
if ( ! V_666 && ! V_97 -> V_667 )
return;
if ( F_151 ( V_2 ) || F_71 ( V_2 ) ) {
F_11 ( F_361 ( V_95 ) , V_680 ) ;
F_358 ( V_24 , V_208 ) ;
} else {
F_11 ( F_362 ( V_95 ) , V_680 ) ;
if ( F_363 ( V_2 ) || F_364 ( V_2 ) )
F_356 ( V_24 , V_208 ) ;
else
F_357 ( V_24 , V_208 ) ;
}
}
static int F_365 ( struct V_23 * V_24 ,
struct V_689 * V_690 ,
T_5 V_691 ,
T_5 V_682 , T_5 V_683 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_230 * V_231 ;
T_5 V_692 ;
int V_235 ;
if ( ! V_691 ) {
F_40 ( L_131 ) ;
V_692 = 0 ;
V_231 = NULL ;
F_147 ( & V_2 -> V_302 ) ;
goto V_693;
}
if ( V_682 != 64 || V_683 != 64 ) {
F_10 ( L_132 ) ;
return - V_240 ;
}
V_231 = F_366 ( F_367 ( V_2 , V_690 , V_691 ) ) ;
if ( & V_231 -> V_208 == NULL )
return - V_694 ;
if ( V_231 -> V_208 . V_695 < V_682 * V_683 * 4 ) {
F_10 ( L_133 ) ;
V_235 = - V_696 ;
goto V_697;
}
F_147 ( & V_2 -> V_302 ) ;
if ( ! V_4 -> V_137 -> V_698 ) {
if ( V_231 -> V_236 ) {
F_10 ( L_134 ) ;
V_235 = - V_240 ;
goto V_699;
}
V_235 = F_126 ( V_231 , 0 , NULL ) ;
if ( V_235 ) {
F_10 ( L_135 ) ;
goto V_699;
}
V_235 = F_368 ( V_231 ) ;
if ( V_235 ) {
F_10 ( L_136 ) ;
goto V_700;
}
V_692 = V_231 -> V_283 ;
} else {
int V_701 = F_94 ( V_2 ) ? 16 * 1024 : 256 ;
V_235 = F_369 ( V_2 , V_231 ,
( V_97 -> V_95 == 0 ) ? V_702 : V_703 ,
V_701 ) ;
if ( V_235 ) {
F_10 ( L_137 ) ;
goto V_699;
}
V_692 = V_231 -> V_704 -> V_691 -> V_705 ;
}
if ( F_23 ( V_2 ) )
F_11 ( V_706 , ( V_683 << 12 ) | V_682 ) ;
V_693:
if ( V_97 -> V_707 ) {
if ( V_4 -> V_137 -> V_698 ) {
if ( V_97 -> V_707 != V_231 )
F_370 ( V_2 , V_97 -> V_707 ) ;
} else
F_129 ( V_97 -> V_707 ) ;
F_371 ( & V_97 -> V_707 -> V_208 ) ;
}
F_148 ( & V_2 -> V_302 ) ;
V_97 -> V_681 = V_692 ;
V_97 -> V_707 = V_231 ;
V_97 -> V_684 = V_682 ;
V_97 -> V_687 = V_683 ;
F_210 ( V_24 , true ) ;
return 0 ;
V_700:
F_129 ( V_231 ) ;
V_699:
F_148 ( & V_2 -> V_302 ) ;
V_697:
F_372 ( & V_231 -> V_208 ) ;
return V_235 ;
}
static int F_373 ( struct V_23 * V_24 , int V_245 , int V_246 )
{
struct V_97 * V_97 = F_35 ( V_24 ) ;
V_97 -> V_678 = V_245 ;
V_97 -> V_679 = V_246 ;
F_210 ( V_24 , true ) ;
return 0 ;
}
void F_374 ( struct V_23 * V_24 , T_4 V_708 , T_4 V_709 ,
T_4 V_710 , int V_711 )
{
struct V_97 * V_97 = F_35 ( V_24 ) ;
V_97 -> V_663 [ V_711 ] = V_708 >> 8 ;
V_97 -> V_664 [ V_711 ] = V_709 >> 8 ;
V_97 -> V_665 [ V_711 ] = V_710 >> 8 ;
}
void F_375 ( struct V_23 * V_24 , T_4 * V_708 , T_4 * V_709 ,
T_4 * V_710 , int V_711 )
{
struct V_97 * V_97 = F_35 ( V_24 ) ;
* V_708 = V_97 -> V_663 [ V_711 ] << 8 ;
* V_709 = V_97 -> V_664 [ V_711 ] << 8 ;
* V_710 = V_97 -> V_665 [ V_711 ] << 8 ;
}
static void F_376 ( struct V_23 * V_24 , T_4 * V_708 , T_4 * V_709 ,
T_4 * V_710 , T_5 V_712 , T_5 V_695 )
{
int V_713 = ( V_712 + V_695 > 256 ) ? 256 : V_712 + V_695 , V_158 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
for ( V_158 = V_712 ; V_158 < V_713 ; V_158 ++ ) {
V_97 -> V_663 [ V_158 ] = V_708 [ V_158 ] >> 8 ;
V_97 -> V_664 [ V_158 ] = V_709 [ V_158 ] >> 8 ;
V_97 -> V_665 [ V_158 ] = V_710 [ V_158 ] >> 8 ;
}
F_209 ( V_24 ) ;
}
static struct V_252 *
F_377 ( struct V_1 * V_2 ,
struct V_714 * V_715 ,
struct V_230 * V_231 )
{
struct V_254 * V_255 ;
int V_235 ;
V_255 = F_378 ( sizeof( * V_255 ) , V_716 ) ;
if ( ! V_255 ) {
F_372 ( & V_231 -> V_208 ) ;
return F_379 ( - V_696 ) ;
}
V_235 = F_380 ( V_2 , V_255 , V_715 , V_231 ) ;
if ( V_235 ) {
F_372 ( & V_231 -> V_208 ) ;
F_242 ( V_255 ) ;
return F_379 ( V_235 ) ;
}
return & V_255 -> V_208 ;
}
static T_1
F_381 ( int V_682 , int V_483 )
{
T_1 V_248 = F_382 ( V_682 * V_483 , 8 ) ;
return F_383 ( V_248 , 64 ) ;
}
static T_1
F_384 ( struct V_440 * V_353 , int V_483 )
{
T_1 V_248 = F_381 ( V_353 -> V_421 , V_483 ) ;
return F_383 ( V_248 * V_353 -> V_423 , V_717 ) ;
}
static struct V_252 *
F_385 ( struct V_1 * V_2 ,
struct V_440 * V_353 ,
int V_485 , int V_483 )
{
struct V_230 * V_231 ;
struct V_714 V_715 = { 0 } ;
V_231 = F_386 ( V_2 ,
F_384 ( V_353 , V_483 ) ) ;
if ( V_231 == NULL )
return F_379 ( - V_696 ) ;
V_715 . V_682 = V_353 -> V_421 ;
V_715 . V_683 = V_353 -> V_423 ;
V_715 . V_280 [ 0 ] = F_381 ( V_715 . V_682 ,
V_483 ) ;
V_715 . V_259 = F_387 ( V_483 , V_485 ) ;
return F_377 ( V_2 , & V_715 , V_231 ) ;
}
static struct V_252 *
F_388 ( struct V_1 * V_2 ,
struct V_440 * V_353 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_230 * V_231 ;
struct V_252 * V_253 ;
if ( V_4 -> V_718 == NULL )
return NULL ;
V_231 = V_4 -> V_718 -> V_719 . V_231 ;
if ( V_231 == NULL )
return NULL ;
V_253 = & V_4 -> V_718 -> V_719 . V_208 ;
if ( V_253 -> V_280 [ 0 ] < F_381 ( V_353 -> V_421 ,
V_253 -> V_281 ) )
return NULL ;
if ( V_231 -> V_208 . V_695 < V_353 -> V_423 * V_253 -> V_280 [ 0 ] )
return NULL ;
return V_253 ;
}
bool F_389 ( struct V_429 * V_430 ,
struct V_440 * V_353 ,
struct V_720 * V_721 )
{
struct V_97 * V_97 ;
struct V_62 * V_62 =
F_247 ( V_430 ) ;
struct V_23 * V_722 ;
struct V_435 * V_63 = & V_62 -> V_208 ;
struct V_23 * V_24 = NULL ;
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_252 * V_253 ;
int V_158 = - 1 ;
F_40 ( L_138 ,
V_430 -> V_208 . V_213 , F_245 ( V_430 ) ,
V_63 -> V_208 . V_213 , F_336 ( V_63 ) ) ;
if ( V_63 -> V_24 ) {
V_24 = V_63 -> V_24 ;
F_147 ( & V_24 -> V_723 ) ;
V_721 -> V_724 = V_430 -> V_433 ;
V_721 -> V_725 = false ;
if ( V_430 -> V_433 != V_436 )
V_430 -> V_726 -> V_433 ( V_430 , V_436 ) ;
return true ;
}
F_237 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_158 ++ ;
if ( ! ( V_63 -> V_727 & ( 1 << V_158 ) ) )
continue;
if ( ! V_722 -> V_124 ) {
V_24 = V_722 ;
break;
}
}
if ( ! V_24 ) {
F_40 ( L_139 ) ;
return false ;
}
F_147 ( & V_24 -> V_723 ) ;
V_62 -> V_728 = F_35 ( V_24 ) ;
F_390 ( V_430 ) -> V_729 = V_62 ;
V_97 = F_35 ( V_24 ) ;
V_721 -> V_724 = V_430 -> V_433 ;
V_721 -> V_725 = true ;
V_721 -> V_730 = NULL ;
if ( ! V_353 )
V_353 = & V_731 ;
V_253 = F_388 ( V_2 , V_353 ) ;
if ( V_253 == NULL ) {
F_40 ( L_140 ) ;
V_253 = F_385 ( V_2 , V_353 , 24 , 32 ) ;
V_721 -> V_730 = V_253 ;
} else
F_40 ( L_141 ) ;
if ( F_391 ( V_253 ) ) {
F_40 ( L_142 ) ;
F_148 ( & V_24 -> V_723 ) ;
return false ;
}
if ( F_392 ( V_24 , V_353 , 0 , 0 , V_253 ) ) {
F_40 ( L_143 ) ;
if ( V_721 -> V_730 )
V_721 -> V_730 -> V_726 -> V_732 ( V_721 -> V_730 ) ;
F_148 ( & V_24 -> V_723 ) ;
return false ;
}
F_41 ( V_2 , V_97 -> V_95 ) ;
return true ;
}
void F_393 ( struct V_429 * V_430 ,
struct V_720 * V_721 )
{
struct V_62 * V_62 =
F_247 ( V_430 ) ;
struct V_435 * V_63 = & V_62 -> V_208 ;
struct V_23 * V_24 = V_63 -> V_24 ;
F_40 ( L_138 ,
V_430 -> V_208 . V_213 , F_245 ( V_430 ) ,
V_63 -> V_208 . V_213 , F_336 ( V_63 ) ) ;
if ( V_721 -> V_725 ) {
F_390 ( V_430 ) -> V_729 = NULL ;
V_62 -> V_728 = NULL ;
F_392 ( V_24 , NULL , 0 , 0 , NULL ) ;
if ( V_721 -> V_730 ) {
F_394 ( V_721 -> V_730 ) ;
F_395 ( V_721 -> V_730 ) ;
}
F_148 ( & V_24 -> V_723 ) ;
return;
}
if ( V_721 -> V_724 != V_436 )
V_430 -> V_726 -> V_433 ( V_430 , V_721 -> V_724 ) ;
F_148 ( & V_24 -> V_723 ) ;
}
static int F_396 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_1 V_390 = F_4 ( F_55 ( V_95 ) ) ;
T_1 V_391 ;
T_3 clock ;
if ( ( V_390 & V_733 ) == 0 )
V_391 = F_4 ( F_270 ( V_95 ) ) ;
else
V_391 = F_4 ( F_271 ( V_95 ) ) ;
clock . V_61 = ( V_391 & V_734 ) >> V_735 ;
if ( F_21 ( V_2 ) ) {
clock . V_59 = F_397 ( ( V_391 & V_736 ) >> V_737 ) - 1 ;
clock . V_54 = ( V_391 & V_738 ) >> V_739 ;
} else {
clock . V_59 = ( V_391 & V_740 ) >> V_737 ;
clock . V_54 = ( V_391 & V_741 ) >> V_739 ;
}
if ( ! F_23 ( V_2 ) ) {
if ( F_21 ( V_2 ) )
clock . V_56 = F_397 ( ( V_390 & V_742 ) >>
V_523 ) ;
else
clock . V_56 = F_397 ( ( V_390 & V_743 ) >>
V_524 ) ;
switch ( V_390 & V_744 ) {
case V_519 :
clock . V_57 = V_390 & V_526 ?
5 : 10 ;
break;
case V_518 :
clock . V_57 = V_390 & V_527 ?
7 : 14 ;
break;
default:
F_40 ( L_144
L_145 , ( int ) ( V_390 & V_744 ) ) ;
return 0 ;
}
F_25 ( V_2 , 96000 , & clock ) ;
} else {
bool V_555 = ( V_95 == 1 ) && ( F_4 ( V_79 ) & V_176 ) ;
if ( V_555 ) {
clock . V_56 = F_397 ( ( V_390 & V_745 ) >>
V_524 ) ;
clock . V_57 = 14 ;
if ( ( V_390 & V_746 ) ==
V_533 ) {
F_25 ( V_2 , 66000 , & clock ) ;
} else
F_25 ( V_2 , 48000 , & clock ) ;
} else {
if ( V_390 & V_536 )
clock . V_56 = 2 ;
else {
clock . V_56 = ( ( V_390 & V_747 ) >>
V_524 ) + 2 ;
}
if ( V_390 & V_537 )
clock . V_57 = 4 ;
else
clock . V_57 = 2 ;
F_25 ( V_2 , 48000 , & clock ) ;
}
}
return clock . V_60 ;
}
struct V_440 * F_398 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
enum V_94 V_98 = V_97 -> V_98 ;
struct V_440 * V_353 ;
int V_748 = F_4 ( F_185 ( V_98 ) ) ;
int V_749 = F_4 ( F_189 ( V_98 ) ) ;
int V_750 = F_4 ( F_191 ( V_98 ) ) ;
int V_751 = F_4 ( F_195 ( V_98 ) ) ;
V_353 = F_378 ( sizeof( * V_353 ) , V_716 ) ;
if ( ! V_353 )
return NULL ;
V_353 -> clock = F_396 ( V_2 , V_24 ) ;
V_353 -> V_421 = ( V_748 & 0xffff ) + 1 ;
V_353 -> V_752 = ( ( V_748 & 0xffff0000 ) >> 16 ) + 1 ;
V_353 -> V_445 = ( V_749 & 0xffff ) + 1 ;
V_353 -> V_753 = ( ( V_749 & 0xffff0000 ) >> 16 ) + 1 ;
V_353 -> V_423 = ( V_750 & 0xffff ) + 1 ;
V_353 -> V_754 = ( ( V_750 & 0xffff0000 ) >> 16 ) + 1 ;
V_353 -> V_755 = ( V_751 & 0xffff ) + 1 ;
V_353 -> V_756 = ( ( V_751 & 0xffff0000 ) >> 16 ) + 1 ;
F_399 ( V_353 ) ;
return V_353 ;
}
static void F_142 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
T_8 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
int V_757 = F_55 ( V_95 ) ;
int V_390 ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_560 )
return;
V_390 = F_4 ( V_757 ) ;
if ( ! F_289 ( V_2 ) && ( V_390 & V_733 ) ) {
F_58 ( L_146 ) ;
F_68 ( V_4 , V_95 ) ;
V_390 &= ~ V_733 ;
F_11 ( V_757 , V_390 ) ;
F_41 ( V_2 , V_95 ) ;
V_390 = F_4 ( V_757 ) ;
if ( V_390 & V_733 )
F_58 ( L_147 ) ;
}
}
static void F_400 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
T_8 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_560 )
return;
if ( ! F_289 ( V_2 ) && V_97 -> V_490 ) {
int V_95 = V_97 -> V_95 ;
int V_757 = F_55 ( V_95 ) ;
int V_390 ;
F_58 ( L_148 ) ;
F_68 ( V_4 , V_95 ) ;
V_390 = F_4 ( V_757 ) ;
V_390 |= V_733 ;
F_11 ( V_757 , V_390 ) ;
F_41 ( V_2 , V_95 ) ;
V_390 = F_4 ( V_757 ) ;
if ( ! ( V_390 & V_733 ) )
F_58 ( L_149 ) ;
}
}
void F_401 ( struct V_1 * V_2 )
{
F_402 ( V_2 -> V_5 ) ;
}
void F_403 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
if ( ! V_491 )
return;
F_237 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_24 -> V_253 )
continue;
F_400 ( V_24 ) ;
}
}
void F_404 ( struct V_230 * V_231 )
{
struct V_1 * V_2 = V_231 -> V_208 . V_2 ;
struct V_23 * V_24 ;
if ( ! V_491 )
return;
F_237 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_24 -> V_253 )
continue;
if ( F_134 ( V_24 -> V_253 ) -> V_231 == V_231 )
F_142 ( V_24 ) ;
}
}
static void F_405 ( struct V_23 * V_24 )
{
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_758 * V_759 ;
unsigned long V_338 ;
F_168 ( & V_2 -> V_342 , V_338 ) ;
V_759 = V_97 -> V_343 ;
V_97 -> V_343 = NULL ;
F_169 ( & V_2 -> V_342 , V_338 ) ;
if ( V_759 ) {
F_406 ( & V_759 -> V_759 ) ;
F_242 ( V_759 ) ;
}
F_407 ( V_24 ) ;
F_242 ( V_97 ) ;
}
static void F_408 ( struct V_760 * V_761 )
{
struct V_758 * V_759 =
F_409 ( V_761 , struct V_758 , V_759 ) ;
struct V_1 * V_2 = V_759 -> V_24 -> V_2 ;
F_147 ( & V_2 -> V_302 ) ;
F_130 ( V_759 -> V_762 ) ;
F_371 ( & V_759 -> V_763 -> V_208 ) ;
F_371 ( & V_759 -> V_762 -> V_208 ) ;
F_149 ( V_2 ) ;
F_148 ( & V_2 -> V_302 ) ;
F_92 ( F_167 ( & F_35 ( V_759 -> V_24 ) -> V_764 ) == 0 ) ;
F_410 ( & F_35 ( V_759 -> V_24 ) -> V_764 ) ;
F_242 ( V_759 ) ;
}
static void F_411 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_758 * V_759 ;
struct V_230 * V_231 ;
unsigned long V_338 ;
if ( V_97 == NULL )
return;
F_168 ( & V_2 -> V_342 , V_338 ) ;
V_759 = V_97 -> V_343 ;
F_412 () ;
if ( V_759 == NULL || F_167 ( & V_759 -> V_339 ) < V_765 ) {
F_169 ( & V_2 -> V_342 , V_338 ) ;
return;
}
F_412 () ;
V_97 -> V_343 = NULL ;
if ( V_759 -> V_766 )
F_413 ( V_2 , V_97 -> V_95 , V_759 -> V_766 ) ;
F_414 ( V_2 , V_97 -> V_95 ) ;
F_169 ( & V_2 -> V_342 , V_338 ) ;
V_231 = V_759 -> V_762 ;
F_415 ( & V_4 -> V_344 ) ;
F_416 ( V_4 -> V_767 , & V_759 -> V_759 ) ;
F_417 ( V_97 -> V_156 , V_759 -> V_763 ) ;
}
void F_418 ( struct V_1 * V_2 , int V_95 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_23 * V_24 = V_4 -> V_96 [ V_95 ] ;
F_411 ( V_2 , V_24 ) ;
}
void F_419 ( struct V_1 * V_2 , int V_156 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_23 * V_24 = V_4 -> V_768 [ V_156 ] ;
F_411 ( V_2 , V_24 ) ;
}
void F_420 ( struct V_1 * V_2 , int V_156 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 =
F_35 ( V_4 -> V_768 [ V_156 ] ) ;
unsigned long V_338 ;
F_168 ( & V_2 -> V_342 , V_338 ) ;
if ( V_97 -> V_343 )
F_421 ( & V_97 -> V_343 -> V_339 ) ;
F_169 ( & V_2 -> V_342 , V_338 ) ;
}
inline static void F_422 ( struct V_97 * V_97 )
{
F_423 () ;
F_424 ( & V_97 -> V_343 -> V_339 , V_769 ) ;
F_423 () ;
}
static int F_425 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_252 * V_253 ,
struct V_230 * V_231 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
T_1 V_770 ;
struct V_232 * V_771 = & V_4 -> V_771 [ V_772 ] ;
int V_235 ;
V_235 = F_122 ( V_2 , V_231 , V_771 ) ;
if ( V_235 )
goto V_69;
V_235 = F_426 ( V_771 , 6 ) ;
if ( V_235 )
goto V_244;
if ( V_97 -> V_156 )
V_770 = V_773 ;
else
V_770 = V_774 ;
F_427 ( V_771 , V_775 | V_770 ) ;
F_427 ( V_771 , V_776 ) ;
F_427 ( V_771 , V_777 |
F_428 ( V_97 -> V_156 ) ) ;
F_427 ( V_771 , V_253 -> V_280 [ 0 ] ) ;
F_427 ( V_771 , V_231 -> V_283 + V_97 -> V_282 ) ;
F_427 ( V_771 , 0 ) ;
F_422 ( V_97 ) ;
F_429 ( V_771 ) ;
return 0 ;
V_244:
F_130 ( V_231 ) ;
V_69:
return V_235 ;
}
static int F_430 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_252 * V_253 ,
struct V_230 * V_231 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
T_1 V_770 ;
struct V_232 * V_771 = & V_4 -> V_771 [ V_772 ] ;
int V_235 ;
V_235 = F_122 ( V_2 , V_231 , V_771 ) ;
if ( V_235 )
goto V_69;
V_235 = F_426 ( V_771 , 6 ) ;
if ( V_235 )
goto V_244;
if ( V_97 -> V_156 )
V_770 = V_773 ;
else
V_770 = V_774 ;
F_427 ( V_771 , V_775 | V_770 ) ;
F_427 ( V_771 , V_776 ) ;
F_427 ( V_771 , V_778 |
F_428 ( V_97 -> V_156 ) ) ;
F_427 ( V_771 , V_253 -> V_280 [ 0 ] ) ;
F_427 ( V_771 , V_231 -> V_283 + V_97 -> V_282 ) ;
F_427 ( V_771 , V_776 ) ;
F_422 ( V_97 ) ;
F_429 ( V_771 ) ;
return 0 ;
V_244:
F_130 ( V_231 ) ;
V_69:
return V_235 ;
}
static int F_431 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_252 * V_253 ,
struct V_230 * V_231 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
T_5 V_779 , V_780 ;
struct V_232 * V_771 = & V_4 -> V_771 [ V_772 ] ;
int V_235 ;
V_235 = F_122 ( V_2 , V_231 , V_771 ) ;
if ( V_235 )
goto V_69;
V_235 = F_426 ( V_771 , 4 ) ;
if ( V_235 )
goto V_244;
F_427 ( V_771 , V_777 |
F_428 ( V_97 -> V_156 ) ) ;
F_427 ( V_771 , V_253 -> V_280 [ 0 ] ) ;
F_427 ( V_771 ,
( V_231 -> V_283 + V_97 -> V_282 ) |
V_231 -> V_236 ) ;
V_779 = 0 ;
V_780 = F_4 ( F_286 ( V_97 -> V_95 ) ) & 0x0fff0fff ;
F_427 ( V_771 , V_779 | V_780 ) ;
F_422 ( V_97 ) ;
F_429 ( V_771 ) ;
return 0 ;
V_244:
F_130 ( V_231 ) ;
V_69:
return V_235 ;
}
static int F_432 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_252 * V_253 ,
struct V_230 * V_231 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_232 * V_771 = & V_4 -> V_771 [ V_772 ] ;
T_5 V_779 , V_780 ;
int V_235 ;
V_235 = F_122 ( V_2 , V_231 , V_771 ) ;
if ( V_235 )
goto V_69;
V_235 = F_426 ( V_771 , 4 ) ;
if ( V_235 )
goto V_244;
F_427 ( V_771 , V_777 |
F_428 ( V_97 -> V_156 ) ) ;
F_427 ( V_771 , V_253 -> V_280 [ 0 ] | V_231 -> V_236 ) ;
F_427 ( V_771 , V_231 -> V_283 + V_97 -> V_282 ) ;
V_779 = 0 ;
V_780 = F_4 ( F_286 ( V_97 -> V_95 ) ) & 0x0fff0fff ;
F_427 ( V_771 , V_779 | V_780 ) ;
F_422 ( V_97 ) ;
F_429 ( V_771 ) ;
return 0 ;
V_244:
F_130 ( V_231 ) ;
V_69:
return V_235 ;
}
static int F_433 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_252 * V_253 ,
struct V_230 * V_231 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_232 * V_771 = & V_4 -> V_771 [ V_781 ] ;
T_5 V_782 = 0 ;
int V_235 ;
V_235 = F_122 ( V_2 , V_231 , V_771 ) ;
if ( V_235 )
goto V_69;
switch( V_97 -> V_156 ) {
case V_783 :
V_782 = V_784 ;
break;
case V_785 :
V_782 = V_786 ;
break;
case V_787 :
V_782 = V_788 ;
break;
default:
F_434 ( 1 , L_150 ) ;
V_235 = - V_789 ;
goto V_244;
}
V_235 = F_426 ( V_771 , 4 ) ;
if ( V_235 )
goto V_244;
F_427 ( V_771 , V_778 | V_782 ) ;
F_427 ( V_771 , ( V_253 -> V_280 [ 0 ] | V_231 -> V_236 ) ) ;
F_427 ( V_771 , V_231 -> V_283 + V_97 -> V_282 ) ;
F_427 ( V_771 , ( V_776 ) ) ;
F_422 ( V_97 ) ;
F_429 ( V_771 ) ;
return 0 ;
V_244:
F_130 ( V_231 ) ;
V_69:
return V_235 ;
}
static int F_435 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_252 * V_253 ,
struct V_230 * V_231 )
{
return - V_789 ;
}
static int F_436 ( struct V_23 * V_24 ,
struct V_252 * V_253 ,
struct V_790 * V_766 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_252 * V_289 = V_24 -> V_253 ;
struct V_230 * V_231 = F_134 ( V_253 ) -> V_231 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_758 * V_759 ;
unsigned long V_338 ;
int V_235 ;
if ( V_253 -> V_259 != V_24 -> V_253 -> V_259 )
return - V_240 ;
if ( F_43 ( V_2 ) -> V_102 > 3 &&
( V_253 -> V_791 [ 0 ] != V_24 -> V_253 -> V_791 [ 0 ] ||
V_253 -> V_280 [ 0 ] != V_24 -> V_253 -> V_280 [ 0 ] ) )
return - V_240 ;
V_759 = F_378 ( sizeof *V_759 , V_716 ) ;
if ( V_759 == NULL )
return - V_696 ;
V_759 -> V_766 = V_766 ;
V_759 -> V_24 = V_24 ;
V_759 -> V_762 = F_134 ( V_289 ) -> V_231 ;
F_437 ( & V_759 -> V_759 , F_408 ) ;
V_235 = F_438 ( V_2 , V_97 -> V_95 ) ;
if ( V_235 )
goto V_792;
F_168 ( & V_2 -> V_342 , V_338 ) ;
if ( V_97 -> V_343 ) {
F_169 ( & V_2 -> V_342 , V_338 ) ;
F_242 ( V_759 ) ;
F_414 ( V_2 , V_97 -> V_95 ) ;
F_58 ( L_151 ) ;
return - V_793 ;
}
V_97 -> V_343 = V_759 ;
F_169 ( & V_2 -> V_342 , V_338 ) ;
if ( F_167 ( & V_97 -> V_764 ) >= 2 )
F_439 ( V_4 -> V_767 ) ;
V_235 = F_440 ( V_2 ) ;
if ( V_235 )
goto V_794;
F_441 ( & V_759 -> V_762 -> V_208 ) ;
F_441 ( & V_231 -> V_208 ) ;
V_24 -> V_253 = V_253 ;
V_759 -> V_763 = V_231 ;
V_759 -> V_795 = true ;
F_442 ( & V_97 -> V_764 ) ;
V_97 -> V_341 = F_167 ( & V_4 -> V_340 . V_341 ) ;
V_235 = V_4 -> V_286 . V_796 ( V_2 , V_24 , V_253 , V_231 ) ;
if ( V_235 )
goto V_797;
F_217 ( V_2 ) ;
F_404 ( V_231 ) ;
F_148 ( & V_2 -> V_302 ) ;
F_443 ( V_97 -> V_156 , V_231 ) ;
return 0 ;
V_797:
F_410 ( & V_97 -> V_764 ) ;
V_24 -> V_253 = V_289 ;
F_371 ( & V_759 -> V_762 -> V_208 ) ;
F_371 ( & V_231 -> V_208 ) ;
F_148 ( & V_2 -> V_302 ) ;
V_794:
F_168 ( & V_2 -> V_342 , V_338 ) ;
V_97 -> V_343 = NULL ;
F_169 ( & V_2 -> V_342 , V_338 ) ;
F_414 ( V_2 , V_97 -> V_95 ) ;
V_792:
F_242 ( V_759 ) ;
return V_235 ;
}
bool F_444 ( struct V_62 * V_63 )
{
struct V_62 * V_798 ;
struct V_23 * V_24 = & V_63 -> V_728 -> V_208 ;
if ( F_2 ( ! V_24 ) )
return false ;
F_237 (other_encoder,
&crtc->dev->mode_config.encoder_list,
base.head) {
if ( & V_798 -> V_728 -> V_208 != V_24 ||
V_63 == V_798 )
continue;
else
return true ;
}
return false ;
}
static bool F_445 ( struct V_435 * V_63 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 ;
struct V_23 * V_195 ;
int V_799 = 1 ;
F_46 ( ! V_24 , L_152 ) ;
V_2 = V_24 -> V_2 ;
F_237 (tmp, &dev->mode_config.crtc_list, head) {
if ( V_195 == V_24 )
break;
V_799 <<= 1 ;
}
if ( V_63 -> V_727 & V_799 )
return true ;
return false ;
}
static void F_446 ( struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_437 * V_430 ;
F_237 (connector, &dev->mode_config.connector_list,
base.head) {
V_430 -> V_729 =
F_238 ( V_430 -> V_208 . V_63 ) ;
}
F_237 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_63 -> V_728 =
F_35 ( V_63 -> V_208 . V_24 ) ;
}
}
static void F_447 ( struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_437 * V_430 ;
F_237 (connector, &dev->mode_config.connector_list,
base.head) {
V_430 -> V_208 . V_63 = & V_430 -> V_729 -> V_208 ;
}
F_237 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_63 -> V_208 . V_24 = & V_63 -> V_728 -> V_208 ;
}
}
static struct V_440 *
F_448 ( struct V_23 * V_24 ,
struct V_440 * V_353 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_440 * V_441 ;
struct V_625 * V_626 ;
struct V_62 * V_63 ;
V_441 = F_449 ( V_2 , V_353 ) ;
if ( ! V_441 )
return F_379 ( - V_696 ) ;
F_237 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( & V_63 -> V_728 -> V_208 != V_24 )
continue;
V_626 = V_63 -> V_208 . V_629 ;
if ( ! ( V_626 -> V_800 ( & V_63 -> V_208 , V_353 ,
V_441 ) ) ) {
F_40 ( L_153 ) ;
goto V_697;
}
}
if ( ! ( F_250 ( V_24 , V_353 , V_441 ) ) ) {
F_40 ( L_154 ) ;
goto V_697;
}
F_40 ( L_155 , V_24 -> V_208 . V_213 ) ;
return V_441 ;
V_697:
F_450 ( V_2 , V_441 ) ;
return F_379 ( - V_240 ) ;
}
static void
F_451 ( struct V_23 * V_24 , unsigned * V_801 ,
unsigned * V_802 , unsigned * V_803 )
{
struct V_97 * V_97 ;
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_62 * V_63 ;
struct V_437 * V_430 ;
struct V_23 * V_804 ;
* V_803 = * V_801 = * V_802 = 0 ;
F_237 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_430 -> V_208 . V_63 == & V_430 -> V_729 -> V_208 )
continue;
if ( V_430 -> V_208 . V_63 ) {
V_804 = V_430 -> V_208 . V_63 -> V_24 ;
* V_802 |= 1 << F_35 ( V_804 ) -> V_95 ;
}
if ( V_430 -> V_729 )
* V_802 |=
1 << V_430 -> V_729 -> V_728 -> V_95 ;
}
F_237 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_63 -> V_208 . V_24 == & V_63 -> V_728 -> V_208 )
continue;
if ( V_63 -> V_208 . V_24 ) {
V_804 = V_63 -> V_208 . V_24 ;
* V_802 |= 1 << F_35 ( V_804 ) -> V_95 ;
}
if ( V_63 -> V_728 )
* V_802 |= 1 << V_63 -> V_728 -> V_95 ;
}
F_237 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
bool V_805 = false ;
if ( ! V_97 -> V_208 . V_124 )
continue;
F_237 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_63 -> V_728 == V_97 )
V_805 = true ;
}
if ( ! V_805 )
* V_803 |= 1 << V_97 -> V_95 ;
}
V_97 = F_35 ( V_24 ) ;
if ( V_24 -> V_124 )
* V_802 |= 1 << V_97 -> V_95 ;
if ( * V_802 )
* V_801 = * V_802 ;
* V_801 &= ~ ( * V_803 ) ;
* V_802 &= ~ ( * V_803 ) ;
}
static bool F_452 ( struct V_23 * V_24 )
{
struct V_435 * V_63 ;
struct V_1 * V_2 = V_24 -> V_2 ;
F_237 (encoder, &dev->mode_config.encoder_list, head)
if ( V_63 -> V_24 == V_24 )
return true ;
return false ;
}
static void
F_453 ( struct V_1 * V_2 , unsigned V_802 )
{
struct V_62 * V_62 ;
struct V_97 * V_97 ;
struct V_429 * V_430 ;
F_237 (intel_encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_62 -> V_208 . V_24 )
continue;
V_97 = F_35 ( V_62 -> V_208 . V_24 ) ;
if ( V_802 & ( 1 << V_97 -> V_95 ) )
V_62 -> V_426 = false ;
}
F_447 ( V_2 ) ;
F_237 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
V_97 -> V_208 . V_124 = F_452 ( & V_97 -> V_208 ) ;
}
F_237 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_430 -> V_63 || ! V_430 -> V_63 -> V_24 )
continue;
V_97 = F_35 ( V_430 -> V_63 -> V_24 ) ;
if ( V_802 & ( 1 << V_97 -> V_95 ) ) {
struct V_806 * V_807 =
V_2 -> V_573 . V_807 ;
V_430 -> V_433 = V_436 ;
F_454 ( & V_430 -> V_208 ,
V_807 ,
V_436 ) ;
V_62 = F_238 ( V_430 -> V_63 ) ;
V_62 -> V_426 = true ;
}
}
}
int F_392 ( struct V_23 * V_24 ,
struct V_440 * V_353 ,
int V_245 , int V_246 , struct V_252 * V_253 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
T_8 * V_4 = V_2 -> V_5 ;
struct V_440 * V_441 , * V_808 , * V_809 ;
struct V_97 * V_97 ;
unsigned V_803 , V_802 , V_801 ;
int V_235 = 0 ;
V_808 = F_455 ( 2 * sizeof( * V_808 ) , V_716 ) ;
if ( ! V_808 )
return - V_696 ;
V_809 = V_808 + 1 ;
F_451 ( V_24 , & V_801 ,
& V_802 , & V_803 ) ;
F_40 ( L_156 ,
V_801 , V_802 , V_803 ) ;
F_456 (dev, disable_pipes, intel_crtc)
F_235 ( & V_97 -> V_208 ) ;
* V_809 = V_24 -> V_810 ;
* V_808 = V_24 -> V_353 ;
V_441 = NULL ;
if ( V_801 ) {
V_441 = F_448 ( V_24 , V_353 ) ;
if ( F_391 ( V_441 ) ) {
V_235 = F_457 ( V_441 ) ;
goto V_811;
}
}
F_456 (dev, prepare_pipes, intel_crtc) {
if ( V_97 -> V_208 . V_124 )
V_4 -> V_286 . V_428 ( & V_97 -> V_208 ) ;
}
if ( V_801 )
V_24 -> V_353 = * V_353 ;
F_453 ( V_2 , V_802 ) ;
if ( V_4 -> V_286 . V_812 )
V_4 -> V_286 . V_812 ( V_2 ) ;
F_456 (dev, modeset_pipes, intel_crtc) {
V_235 = F_333 ( & V_97 -> V_208 ,
V_353 , V_441 ,
V_245 , V_246 , V_253 ) ;
if ( V_235 )
goto V_813;
}
F_456 (dev, prepare_pipes, intel_crtc)
V_4 -> V_286 . V_427 ( & V_97 -> V_208 ) ;
if ( V_801 ) {
V_24 -> V_810 = * V_441 ;
F_458 ( V_24 ) ;
}
V_813:
F_450 ( V_2 , V_441 ) ;
if ( V_235 && V_24 -> V_124 ) {
V_24 -> V_810 = * V_809 ;
V_24 -> V_353 = * V_808 ;
} else {
F_248 ( V_2 ) ;
}
V_811:
F_242 ( V_808 ) ;
return V_235 ;
}
void F_459 ( struct V_23 * V_24 )
{
F_392 ( V_24 , & V_24 -> V_353 , V_24 -> V_245 , V_24 -> V_246 , V_24 -> V_253 ) ;
}
static void F_460 ( struct V_814 * V_815 )
{
if ( ! V_815 )
return;
F_242 ( V_815 -> V_816 ) ;
F_242 ( V_815 -> V_817 ) ;
F_242 ( V_815 ) ;
}
static int F_461 ( struct V_1 * V_2 ,
struct V_814 * V_815 )
{
struct V_435 * V_63 ;
struct V_429 * V_430 ;
int V_818 ;
V_815 -> V_817 =
F_462 ( V_2 -> V_573 . V_819 ,
sizeof( struct V_23 * ) , V_716 ) ;
if ( ! V_815 -> V_817 )
return - V_696 ;
V_815 -> V_816 =
F_462 ( V_2 -> V_573 . V_820 ,
sizeof( struct V_435 * ) , V_716 ) ;
if ( ! V_815 -> V_816 )
return - V_696 ;
V_818 = 0 ;
F_237 (encoder, &dev->mode_config.encoder_list, head) {
V_815 -> V_817 [ V_818 ++ ] = V_63 -> V_24 ;
}
V_818 = 0 ;
F_237 (connector, &dev->mode_config.connector_list, head) {
V_815 -> V_816 [ V_818 ++ ] = V_430 -> V_63 ;
}
return 0 ;
}
static void F_463 ( struct V_1 * V_2 ,
struct V_814 * V_815 )
{
struct V_62 * V_63 ;
struct V_437 * V_430 ;
int V_818 ;
V_818 = 0 ;
F_237 (encoder, &dev->mode_config.encoder_list, base.head) {
V_63 -> V_728 =
F_35 ( V_815 -> V_817 [ V_818 ++ ] ) ;
}
V_818 = 0 ;
F_237 (connector, &dev->mode_config.connector_list, base.head) {
V_430 -> V_729 =
F_238 ( V_815 -> V_816 [ V_818 ++ ] ) ;
}
}
static void
F_464 ( struct V_821 * V_822 ,
struct V_814 * V_815 )
{
if ( V_822 -> V_24 -> V_253 != V_822 -> V_253 ) {
if ( V_822 -> V_24 -> V_253 == NULL ) {
F_40 ( L_157 ) ;
V_815 -> V_823 = true ;
} else if ( V_822 -> V_253 == NULL ) {
V_815 -> V_823 = true ;
} else if ( V_822 -> V_253 -> V_485 != V_822 -> V_24 -> V_253 -> V_485 ) {
V_815 -> V_823 = true ;
} else if ( V_822 -> V_253 -> V_281 !=
V_822 -> V_24 -> V_253 -> V_281 ) {
V_815 -> V_823 = true ;
} else
V_815 -> V_824 = true ;
}
if ( V_822 -> V_253 && ( V_822 -> V_245 != V_822 -> V_24 -> V_245 || V_822 -> V_246 != V_822 -> V_24 -> V_246 ) )
V_815 -> V_824 = true ;
if ( V_822 -> V_353 && ! F_465 ( V_822 -> V_353 , & V_822 -> V_24 -> V_353 ) ) {
F_40 ( L_158 ) ;
F_288 ( & V_822 -> V_24 -> V_353 ) ;
F_288 ( V_822 -> V_353 ) ;
V_815 -> V_823 = true ;
}
}
static int
F_466 ( struct V_1 * V_2 ,
struct V_821 * V_822 ,
struct V_814 * V_815 )
{
struct V_23 * V_728 ;
struct V_437 * V_430 ;
struct V_62 * V_63 ;
int V_818 , V_825 ;
F_2 ( ! V_822 -> V_253 && ( V_822 -> V_486 != 0 ) ) ;
F_2 ( V_822 -> V_253 && ( V_822 -> V_486 == 0 ) ) ;
V_818 = 0 ;
F_237 (connector, &dev->mode_config.connector_list,
base.head) {
for ( V_825 = 0 ; V_825 < V_822 -> V_486 ; V_825 ++ ) {
if ( V_822 -> V_826 [ V_825 ] == & V_430 -> V_208 ) {
V_430 -> V_729 = V_430 -> V_63 ;
break;
}
}
if ( ( ! V_822 -> V_253 || V_825 == V_822 -> V_486 ) &&
V_430 -> V_208 . V_63 &&
V_430 -> V_208 . V_63 -> V_24 == V_822 -> V_24 ) {
V_430 -> V_729 = NULL ;
F_40 ( L_159 ,
V_430 -> V_208 . V_208 . V_213 ,
F_245 ( & V_430 -> V_208 ) ) ;
}
if ( & V_430 -> V_729 -> V_208 != V_430 -> V_208 . V_63 ) {
F_40 ( L_160 ) ;
V_815 -> V_823 = true ;
}
}
V_818 = 0 ;
F_237 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_430 -> V_729 )
continue;
V_728 = V_430 -> V_729 -> V_208 . V_24 ;
for ( V_825 = 0 ; V_825 < V_822 -> V_486 ; V_825 ++ ) {
if ( V_822 -> V_826 [ V_825 ] == & V_430 -> V_208 )
V_728 = V_822 -> V_24 ;
}
if ( ! F_445 ( & V_430 -> V_729 -> V_208 ,
V_728 ) ) {
return - V_240 ;
}
V_430 -> V_63 -> V_728 = F_35 ( V_728 ) ;
F_40 ( L_161 ,
V_430 -> V_208 . V_208 . V_213 ,
F_245 ( & V_430 -> V_208 ) ,
V_728 -> V_208 . V_213 ) ;
}
F_237 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_237 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_430 -> V_729 == V_63 ) {
F_2 ( ! V_430 -> V_729 -> V_728 ) ;
goto V_827;
}
}
V_63 -> V_728 = NULL ;
V_827:
if ( & V_63 -> V_728 -> V_208 != V_63 -> V_208 . V_24 ) {
F_40 ( L_162 ) ;
V_815 -> V_823 = true ;
}
}
return 0 ;
}
static int F_467 ( struct V_821 * V_822 )
{
struct V_1 * V_2 ;
struct V_821 V_828 ;
struct V_814 * V_815 ;
int V_235 ;
F_92 ( ! V_822 ) ;
F_92 ( ! V_822 -> V_24 ) ;
F_92 ( ! V_822 -> V_24 -> V_629 ) ;
F_92 ( ! V_822 -> V_353 && V_822 -> V_253 ) ;
F_92 ( V_822 -> V_253 && V_822 -> V_486 == 0 ) ;
if ( V_822 -> V_253 ) {
F_40 ( L_163 ,
V_822 -> V_24 -> V_208 . V_213 , V_822 -> V_253 -> V_208 . V_213 ,
( int ) V_822 -> V_486 , V_822 -> V_245 , V_822 -> V_246 ) ;
} else {
F_40 ( L_164 , V_822 -> V_24 -> V_208 . V_213 ) ;
}
V_2 = V_822 -> V_24 -> V_2 ;
V_235 = - V_696 ;
V_815 = F_378 ( sizeof( * V_815 ) , V_716 ) ;
if ( ! V_815 )
goto V_829;
V_235 = F_461 ( V_2 , V_815 ) ;
if ( V_235 )
goto V_829;
V_828 . V_24 = V_822 -> V_24 ;
V_828 . V_353 = & V_822 -> V_24 -> V_353 ;
V_828 . V_245 = V_822 -> V_24 -> V_245 ;
V_828 . V_246 = V_822 -> V_24 -> V_246 ;
V_828 . V_253 = V_822 -> V_24 -> V_253 ;
F_464 ( V_822 , V_815 ) ;
V_235 = F_466 ( V_2 , V_822 , V_815 ) ;
if ( V_235 )
goto V_697;
if ( V_815 -> V_823 ) {
if ( V_822 -> V_353 ) {
F_40 ( L_165
L_166 ) ;
F_288 ( V_822 -> V_353 ) ;
}
V_235 = F_392 ( V_822 -> V_24 , V_822 -> V_353 ,
V_822 -> V_245 , V_822 -> V_246 , V_822 -> V_253 ) ;
if ( V_235 ) {
F_10 ( L_167 ,
V_822 -> V_24 -> V_208 . V_213 , V_235 ) ;
goto V_697;
}
} else if ( V_815 -> V_824 ) {
V_235 = F_146 ( V_822 -> V_24 ,
V_822 -> V_245 , V_822 -> V_246 , V_822 -> V_253 ) ;
}
F_460 ( V_815 ) ;
return 0 ;
V_697:
F_463 ( V_2 , V_815 ) ;
if ( V_815 -> V_823 &&
F_392 ( V_828 . V_24 , V_828 . V_353 ,
V_828 . V_245 , V_828 . V_246 , V_828 . V_253 ) )
F_10 ( L_168 ) ;
V_829:
F_460 ( V_815 ) ;
return V_235 ;
}
static void F_468 ( struct V_1 * V_2 )
{
if ( F_61 ( V_2 ) )
F_469 ( V_2 ) ;
}
static void F_470 ( struct V_1 * V_2 )
{
T_8 * V_4 = V_2 -> V_5 ;
int V_158 ;
if ( V_4 -> V_394 == 0 ) {
F_40 ( L_169 ) ;
return;
}
for ( V_158 = 0 ; V_158 < V_4 -> V_394 ; V_158 ++ ) {
V_4 -> V_393 [ V_158 ] . V_130 = F_471 ( V_158 ) ;
V_4 -> V_393 [ V_158 ] . V_395 = F_472 ( V_158 ) ;
V_4 -> V_393 [ V_158 ] . V_623 = F_473 ( V_158 ) ;
}
}
static void F_474 ( struct V_1 * V_2 , int V_95 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 ;
int V_158 ;
V_97 = F_378 ( sizeof( struct V_97 ) + ( V_830 * sizeof( struct V_429 * ) ) , V_716 ) ;
if ( V_97 == NULL )
return;
F_475 ( V_2 , & V_97 -> V_208 , & V_831 ) ;
F_476 ( & V_97 -> V_208 , 256 ) ;
for ( V_158 = 0 ; V_158 < 256 ; V_158 ++ ) {
V_97 -> V_663 [ V_158 ] = V_158 ;
V_97 -> V_664 [ V_158 ] = V_158 ;
V_97 -> V_665 [ V_158 ] = V_158 ;
}
V_97 -> V_95 = V_95 ;
V_97 -> V_156 = V_95 ;
V_97 -> V_98 = V_95 ;
if ( F_93 ( V_2 ) && F_477 ( V_2 ) ) {
F_40 ( L_170 ) ;
V_97 -> V_156 = ! V_95 ;
}
F_92 ( V_95 >= F_478 ( V_4 -> V_768 ) ||
V_4 -> V_768 [ V_97 -> V_156 ] != NULL ) ;
V_4 -> V_768 [ V_97 -> V_156 ] = & V_97 -> V_208 ;
V_4 -> V_96 [ V_97 -> V_95 ] = & V_97 -> V_208 ;
V_97 -> V_483 = 24 ;
F_479 ( & V_97 -> V_208 , & V_832 ) ;
}
int F_480 ( struct V_1 * V_2 , void * V_833 ,
struct V_689 * V_690 )
{
struct V_834 * V_835 = V_833 ;
struct V_836 * V_837 ;
struct V_97 * V_24 ;
if ( ! F_481 ( V_2 , V_838 ) )
return - V_789 ;
V_837 = F_482 ( V_2 , V_835 -> V_839 ,
V_840 ) ;
if ( ! V_837 ) {
F_10 ( L_171 ) ;
return - V_240 ;
}
V_24 = F_35 ( F_483 ( V_837 ) ) ;
V_835 -> V_95 = V_24 -> V_95 ;
return 0 ;
}
static int F_484 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_208 . V_2 ;
struct V_62 * V_841 ;
int V_842 = 0 ;
int V_843 = 0 ;
F_237 (source_encoder,
&dev->mode_config.encoder_list, base.head) {
if ( V_63 == V_841 )
V_842 |= ( 1 << V_843 ) ;
if ( V_63 -> V_844 && V_841 -> V_844 )
V_842 |= ( 1 << V_843 ) ;
V_843 ++ ;
}
return V_842 ;
}
static bool F_485 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_93 ( V_2 ) )
return false ;
if ( ( F_4 ( V_845 ) & V_846 ) == 0 )
return false ;
if ( F_6 ( V_2 ) &&
( F_4 ( V_847 ) & V_848 ) )
return false ;
return true ;
}
static void F_486 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_62 * V_63 ;
bool V_849 = false ;
bool V_574 ;
V_574 = F_487 ( V_2 ) ;
if ( ! V_574 && ! F_3 ( V_2 ) ) {
F_11 ( V_416 , 0 ) ;
}
if ( ! ( F_61 ( V_2 ) && ( F_4 ( F_488 ( V_850 ) ) & V_851 ) ) )
F_489 ( V_2 ) ;
if ( F_61 ( V_2 ) ) {
int V_75 ;
V_75 = F_4 ( V_852 ) & V_853 ;
if ( V_75 )
F_490 ( V_2 , V_850 ) ;
V_75 = F_4 ( V_854 ) ;
if ( V_75 & V_855 )
F_490 ( V_2 , V_114 ) ;
if ( V_75 & V_856 )
F_490 ( V_2 , V_116 ) ;
if ( V_75 & V_857 )
F_490 ( V_2 , V_118 ) ;
} else if ( F_3 ( V_2 ) ) {
int V_75 ;
V_849 = F_491 ( V_2 ) ;
if ( F_485 ( V_2 ) )
F_492 ( V_2 , V_845 , V_850 ) ;
if ( F_4 ( V_189 ) & V_858 ) {
V_75 = F_493 ( V_2 , V_859 , true ) ;
if ( ! V_75 )
F_494 ( V_2 , V_189 , V_114 ) ;
if ( ! V_75 && ( F_4 ( V_182 ) & V_846 ) )
F_492 ( V_2 , V_182 , V_114 ) ;
}
if ( F_4 ( V_190 ) & V_858 )
F_494 ( V_2 , V_190 , V_116 ) ;
if ( ! V_849 && F_4 ( V_191 ) & V_858 )
F_494 ( V_2 , V_191 , V_118 ) ;
if ( F_4 ( V_184 ) & V_846 )
F_492 ( V_2 , V_184 , V_116 ) ;
if ( F_4 ( V_186 ) & V_846 )
F_492 ( V_2 , V_186 , V_118 ) ;
} else if ( F_22 ( V_2 ) ) {
if ( F_4 ( V_860 + V_861 ) & V_846 )
F_492 ( V_2 , V_860 + V_861 , V_116 ) ;
if ( F_4 ( V_860 + V_862 ) & V_858 ) {
F_494 ( V_2 , V_860 + V_862 , V_114 ) ;
if ( F_4 ( V_860 + V_863 ) & V_846 )
F_492 ( V_2 , V_860 + V_863 , V_114 ) ;
}
if ( F_4 ( V_860 + V_864 ) & V_858 )
F_494 ( V_2 , V_860 + V_864 , V_116 ) ;
} else if ( F_495 ( V_2 ) ) {
bool V_75 = false ;
if ( F_4 ( V_862 ) & V_865 ) {
F_40 ( L_172 ) ;
V_75 = F_493 ( V_2 , V_862 , true ) ;
if ( ! V_75 && F_496 ( V_2 ) ) {
F_40 ( L_173 ) ;
F_494 ( V_2 , V_862 , V_114 ) ;
}
if ( ! V_75 && F_497 ( V_2 ) ) {
F_40 ( L_174 ) ;
F_492 ( V_2 , V_863 , V_114 ) ;
}
}
if ( F_4 ( V_862 ) & V_865 ) {
F_40 ( L_175 ) ;
V_75 = F_493 ( V_2 , V_864 , false ) ;
}
if ( ! V_75 && ( F_4 ( V_864 ) & V_865 ) ) {
if ( F_496 ( V_2 ) ) {
F_40 ( L_176 ) ;
F_494 ( V_2 , V_864 , V_116 ) ;
}
if ( F_497 ( V_2 ) ) {
F_40 ( L_177 ) ;
F_492 ( V_2 , V_861 , V_116 ) ;
}
}
if ( F_497 ( V_2 ) &&
( F_4 ( V_866 ) & V_846 ) ) {
F_40 ( L_178 ) ;
F_492 ( V_2 , V_866 , V_118 ) ;
}
} else if ( F_23 ( V_2 ) )
F_498 ( V_2 ) ;
if ( F_499 ( V_2 ) )
F_500 ( V_2 ) ;
F_237 (encoder, &dev->mode_config.encoder_list, base.head) {
V_63 -> V_208 . V_727 = V_63 -> V_799 ;
V_63 -> V_208 . V_867 =
F_484 ( V_63 ) ;
}
F_294 ( V_2 ) ;
F_501 ( V_2 ) ;
}
static void F_502 ( struct V_252 * V_253 )
{
struct V_254 * V_255 = F_134 ( V_253 ) ;
F_503 ( V_253 ) ;
F_372 ( & V_255 -> V_231 -> V_208 ) ;
F_242 ( V_255 ) ;
}
static int F_504 ( struct V_252 * V_253 ,
struct V_689 * V_690 ,
unsigned int * V_691 )
{
struct V_254 * V_255 = F_134 ( V_253 ) ;
struct V_230 * V_231 = V_255 -> V_231 ;
return F_505 ( V_690 , & V_231 -> V_208 , V_691 ) ;
}
int F_380 ( struct V_1 * V_2 ,
struct V_254 * V_255 ,
struct V_714 * V_715 ,
struct V_230 * V_231 )
{
int V_235 ;
if ( V_231 -> V_236 == V_239 ) {
F_265 ( L_179 ) ;
return - V_240 ;
}
if ( V_715 -> V_280 [ 0 ] & 63 ) {
F_265 ( L_180 ,
V_715 -> V_280 [ 0 ] ) ;
return - V_240 ;
}
if ( V_715 -> V_280 [ 0 ] > 32768 ) {
F_265 ( L_181 ,
V_715 -> V_280 [ 0 ] ) ;
return - V_240 ;
}
if ( V_231 -> V_236 != V_237 &&
V_715 -> V_280 [ 0 ] != V_231 -> V_868 ) {
F_265 ( L_182 ,
V_715 -> V_280 [ 0 ] , V_231 -> V_868 ) ;
return - V_240 ;
}
switch ( V_715 -> V_259 ) {
case V_260 :
case V_265 :
case V_267 :
case V_268 :
break;
case V_262 :
case V_263 :
if ( F_43 ( V_2 ) -> V_102 > 3 ) {
F_265 ( L_183 , V_715 -> V_259 ) ;
return - V_240 ;
}
break;
case V_270 :
case V_271 :
case V_273 :
case V_274 :
case V_276 :
case V_277 :
if ( F_43 ( V_2 ) -> V_102 < 4 ) {
F_265 ( L_183 , V_715 -> V_259 ) ;
return - V_240 ;
}
break;
case V_869 :
case V_870 :
case V_871 :
case V_872 :
if ( F_43 ( V_2 ) -> V_102 < 5 ) {
F_265 ( L_183 , V_715 -> V_259 ) ;
return - V_240 ;
}
break;
default:
F_265 ( L_184 , V_715 -> V_259 ) ;
return - V_240 ;
}
if ( V_715 -> V_791 [ 0 ] != 0 )
return - V_240 ;
F_506 ( & V_255 -> V_208 , V_715 ) ;
V_255 -> V_231 = V_231 ;
V_235 = F_507 ( V_2 , & V_255 -> V_208 , & V_873 ) ;
if ( V_235 ) {
F_10 ( L_185 , V_235 ) ;
return V_235 ;
}
return 0 ;
}
static struct V_252 *
F_508 ( struct V_1 * V_2 ,
struct V_689 * V_874 ,
struct V_714 * V_715 )
{
struct V_230 * V_231 ;
V_231 = F_366 ( F_367 ( V_2 , V_874 ,
V_715 -> V_875 [ 0 ] ) ) ;
if ( & V_231 -> V_208 == NULL )
return F_379 ( - V_694 ) ;
return F_377 ( V_2 , V_715 , V_231 ) ;
}
static void F_509 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_61 ( V_2 ) ) {
V_4 -> V_286 . V_627 = F_331 ;
V_4 -> V_286 . V_427 = F_211 ;
V_4 -> V_286 . V_428 = F_218 ;
V_4 -> V_286 . V_432 = F_223 ;
V_4 -> V_286 . V_288 = F_139 ;
} else if ( F_3 ( V_2 ) ) {
V_4 -> V_286 . V_627 = F_326 ;
V_4 -> V_286 . V_427 = F_203 ;
V_4 -> V_286 . V_428 = F_215 ;
V_4 -> V_286 . V_432 = F_222 ;
V_4 -> V_286 . V_288 = F_139 ;
} else {
V_4 -> V_286 . V_627 = F_287 ;
V_4 -> V_286 . V_427 = F_230 ;
V_4 -> V_286 . V_428 = F_231 ;
V_4 -> V_286 . V_432 = F_232 ;
V_4 -> V_286 . V_288 = F_133 ;
}
if ( F_22 ( V_2 ) )
V_4 -> V_286 . V_564 =
F_252 ;
else if ( F_281 ( V_2 ) || ( F_283 ( V_2 ) && ! F_510 ( V_2 ) ) )
V_4 -> V_286 . V_564 =
F_253 ;
else if ( F_511 ( V_2 ) )
V_4 -> V_286 . V_564 =
F_254 ;
else if ( F_282 ( V_2 ) || F_363 ( V_2 ) || F_510 ( V_2 ) )
V_4 -> V_286 . V_564 =
F_255 ;
else if ( F_512 ( V_2 ) )
V_4 -> V_286 . V_564 =
F_256 ;
else if ( F_364 ( V_2 ) )
V_4 -> V_286 . V_564 =
F_258 ;
else if ( F_513 ( V_2 ) )
V_4 -> V_286 . V_564 =
F_259 ;
else
V_4 -> V_286 . V_564 =
F_260 ;
if ( F_3 ( V_2 ) ) {
if ( F_6 ( V_2 ) ) {
V_4 -> V_286 . V_366 = F_153 ;
V_4 -> V_286 . V_661 = F_344 ;
} else if ( F_160 ( V_2 ) ) {
V_4 -> V_286 . V_366 = F_158 ;
V_4 -> V_286 . V_661 = F_344 ;
} else if ( F_151 ( V_2 ) ) {
V_4 -> V_286 . V_366 = F_161 ;
V_4 -> V_286 . V_661 = F_344 ;
V_4 -> V_286 . V_812 =
F_152 ;
} else if ( F_71 ( V_2 ) ) {
V_4 -> V_286 . V_366 = V_876 ;
V_4 -> V_286 . V_661 = F_340 ;
V_4 -> V_286 . V_812 =
F_329 ;
}
} else if ( F_20 ( V_2 ) ) {
V_4 -> V_286 . V_661 = F_338 ;
}
V_4 -> V_286 . V_796 = F_435 ;
switch ( F_43 ( V_2 ) -> V_102 ) {
case 2 :
V_4 -> V_286 . V_796 = F_425 ;
break;
case 3 :
V_4 -> V_286 . V_796 = F_430 ;
break;
case 4 :
case 5 :
V_4 -> V_286 . V_796 = F_431 ;
break;
case 6 :
V_4 -> V_286 . V_796 = F_432 ;
break;
case 7 :
V_4 -> V_286 . V_796 = F_433 ;
break;
}
}
static void F_514 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_150 |= V_151 ;
F_515 ( L_186 ) ;
}
static void F_516 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_150 |= V_473 ;
F_515 ( L_187 ) ;
}
static void F_517 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_150 |= V_877 ;
F_515 ( L_188 ) ;
}
static int F_518 ( const struct V_878 * V_213 )
{
F_515 ( L_189 , V_213 -> V_879 ) ;
return 1 ;
}
static void F_519 ( struct V_1 * V_2 )
{
struct V_880 * V_881 = V_2 -> V_447 ;
int V_158 ;
for ( V_158 = 0 ; V_158 < F_478 ( V_882 ) ; V_158 ++ ) {
struct V_883 * V_884 = & V_882 [ V_158 ] ;
if ( V_881 -> V_885 == V_884 -> V_885 &&
( V_881 -> V_886 == V_884 -> V_886 ||
V_884 -> V_886 == V_887 ) &&
( V_881 -> V_888 == V_884 -> V_888 ||
V_884 -> V_888 == V_887 ) )
V_884 -> V_889 ( V_2 ) ;
}
for ( V_158 = 0 ; V_158 < F_478 ( V_890 ) ; V_158 ++ ) {
if ( F_520 ( * V_890 [ V_158 ] . V_891 ) != 0 )
V_890 [ V_158 ] . V_889 ( V_2 ) ;
}
}
static void F_521 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_9 V_892 ;
T_1 V_893 = F_522 ( V_2 ) ;
F_523 ( V_2 -> V_447 , V_894 ) ;
F_524 ( V_895 , V_896 ) ;
V_892 = F_525 ( V_897 ) ;
F_524 ( V_892 | 1 << 5 , V_897 ) ;
F_526 ( V_2 -> V_447 , V_894 ) ;
F_95 ( 300 ) ;
F_11 ( V_893 , V_898 ) ;
F_14 ( V_893 ) ;
}
void F_527 ( struct V_1 * V_2 )
{
F_528 ( V_2 ) ;
F_529 ( V_2 ) ;
F_530 ( V_2 ) ;
F_147 ( & V_2 -> V_302 ) ;
F_531 ( V_2 ) ;
F_148 ( & V_2 -> V_302 ) ;
}
void F_532 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_158 , V_235 ;
F_533 ( V_2 ) ;
V_2 -> V_573 . V_899 = 0 ;
V_2 -> V_573 . V_900 = 0 ;
V_2 -> V_573 . V_901 = 24 ;
V_2 -> V_573 . V_902 = 1 ;
V_2 -> V_573 . V_726 = & V_903 ;
F_519 ( V_2 ) ;
F_534 ( V_2 ) ;
F_509 ( V_2 ) ;
if ( F_23 ( V_2 ) ) {
V_2 -> V_573 . V_904 = 2048 ;
V_2 -> V_573 . V_905 = 2048 ;
} else if ( F_477 ( V_2 ) ) {
V_2 -> V_573 . V_904 = 4096 ;
V_2 -> V_573 . V_905 = 4096 ;
} else {
V_2 -> V_573 . V_904 = 8192 ;
V_2 -> V_573 . V_905 = 8192 ;
}
V_2 -> V_573 . V_906 = V_4 -> V_907 . V_908 ;
F_40 ( L_190 ,
V_4 -> V_301 , V_4 -> V_301 > 1 ? L_191 : L_192 ) ;
for ( V_158 = 0 ; V_158 < V_4 -> V_301 ; V_158 ++ ) {
F_474 ( V_2 , V_158 ) ;
V_235 = F_535 ( V_2 , V_158 ) ;
if ( V_235 )
F_40 ( L_193 , V_158 , V_235 ) ;
}
F_468 ( V_2 ) ;
F_470 ( V_2 ) ;
F_521 ( V_2 ) ;
F_486 ( V_2 ) ;
F_217 ( V_2 ) ;
}
static void
F_536 ( struct V_437 * V_430 )
{
V_430 -> V_208 . V_433 = V_434 ;
V_430 -> V_208 . V_63 = NULL ;
V_430 -> V_63 -> V_426 = false ;
V_430 -> V_63 -> V_208 . V_24 = NULL ;
}
static void F_537 ( struct V_1 * V_2 )
{
struct V_437 * V_430 ;
struct V_429 * V_909 = NULL ;
struct V_720 V_725 ;
F_237 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_430 -> V_63 -> type == V_39 ) {
V_909 = & V_430 -> V_208 ;
break;
}
}
if ( ! V_909 )
return;
if ( F_389 ( V_909 , NULL , & V_725 ) )
F_393 ( V_909 , & V_725 ) ;
}
static bool
F_538 ( struct V_97 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_208 . V_2 -> V_5 ;
T_1 V_10 , V_20 ;
if ( V_4 -> V_301 == 1 )
return true ;
V_10 = F_73 ( ! V_24 -> V_156 ) ;
V_20 = F_4 ( V_10 ) ;
if ( ( V_20 & V_157 ) &&
( ! ! ( V_20 & V_160 ) == V_24 -> V_95 ) )
return false ;
return true ;
}
static void F_539 ( struct V_97 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_208 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_10 ;
V_10 = F_45 ( V_24 -> V_98 ) ;
F_11 ( V_10 , F_4 ( V_10 ) & ~ V_910 ) ;
if ( F_43 ( V_2 ) -> V_102 < 4 && ! F_538 ( V_24 ) ) {
struct V_437 * V_430 ;
bool V_156 ;
F_40 ( L_194 ,
V_24 -> V_208 . V_208 . V_213 ) ;
V_156 = V_24 -> V_156 ;
V_24 -> V_156 = ! V_156 ;
V_4 -> V_286 . V_428 ( & V_24 -> V_208 ) ;
V_24 -> V_156 = V_156 ;
F_237 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_430 -> V_63 -> V_208 . V_24 != & V_24 -> V_208 )
continue;
F_536 ( V_430 ) ;
}
F_2 ( V_24 -> V_211 ) ;
V_24 -> V_208 . V_124 = false ;
}
if ( V_4 -> V_150 & V_151 &&
V_24 -> V_95 == V_142 && ! V_24 -> V_211 ) {
F_537 ( V_2 ) ;
}
F_234 ( & V_24 -> V_208 ) ;
if ( V_24 -> V_211 != V_24 -> V_208 . V_124 ) {
struct V_62 * V_63 ;
F_40 ( L_195 ,
V_24 -> V_208 . V_208 . V_213 ,
V_24 -> V_208 . V_124 ? L_196 : L_197 ,
V_24 -> V_211 ? L_196 : L_197 ) ;
V_24 -> V_208 . V_124 = V_24 -> V_211 ;
F_2 ( V_24 -> V_211 ) ;
F_26 (dev, &crtc->base, encoder) {
F_2 ( V_63 -> V_426 ) ;
V_63 -> V_208 . V_24 = NULL ;
}
}
}
static void F_540 ( struct V_62 * V_63 )
{
struct V_437 * V_430 ;
struct V_1 * V_2 = V_63 -> V_208 . V_2 ;
bool V_911 = V_63 -> V_208 . V_24 &&
F_35 ( V_63 -> V_208 . V_24 ) -> V_211 ;
if ( V_63 -> V_426 && ! V_911 ) {
F_40 ( L_198 ,
V_63 -> V_208 . V_208 . V_213 ,
F_336 ( & V_63 -> V_208 ) ) ;
if ( V_63 -> V_208 . V_24 ) {
F_40 ( L_199 ,
V_63 -> V_208 . V_208 . V_213 ,
F_336 ( & V_63 -> V_208 ) ) ;
V_63 -> V_404 ( V_63 ) ;
}
F_237 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_430 -> V_63 != V_63 )
continue;
F_536 ( V_430 ) ;
}
}
}
void F_541 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_893 = F_522 ( V_2 ) ;
if ( F_4 ( V_893 ) != V_898 ) {
F_40 ( L_200 ) ;
F_521 ( V_2 ) ;
}
}
void F_542 ( struct V_1 * V_2 ,
bool V_912 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_95 V_95 ;
T_1 V_195 ;
struct V_97 * V_24 ;
struct V_62 * V_63 ;
struct V_437 * V_430 ;
if ( F_61 ( V_2 ) ) {
V_195 = F_4 ( F_62 ( V_152 ) ) ;
if ( V_195 & V_134 ) {
switch ( V_195 & V_913 ) {
case V_914 :
case V_915 :
V_95 = V_142 ;
break;
case V_916 :
V_95 = V_149 ;
break;
case V_917 :
V_95 = V_314 ;
break;
}
V_24 = F_35 ( V_4 -> V_96 [ V_95 ] ) ;
V_24 -> V_98 = V_152 ;
F_40 ( L_201 ,
F_69 ( V_95 ) ) ;
}
}
F_543 (pipe) {
V_24 = F_35 ( V_4 -> V_96 [ V_95 ] ) ;
V_195 = F_4 ( F_45 ( V_24 -> V_98 ) ) ;
if ( V_195 & V_155 )
V_24 -> V_211 = true ;
else
V_24 -> V_211 = false ;
V_24 -> V_208 . V_124 = V_24 -> V_211 ;
F_40 ( L_202 ,
V_24 -> V_208 . V_208 . V_213 ,
V_24 -> V_211 ? L_196 : L_197 ) ;
}
if ( F_61 ( V_2 ) )
F_544 ( V_2 ) ;
F_237 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_95 = 0 ;
if ( V_63 -> V_438 ( V_63 , & V_95 ) ) {
V_63 -> V_208 . V_24 =
V_4 -> V_96 [ V_95 ] ;
} else {
V_63 -> V_208 . V_24 = NULL ;
}
V_63 -> V_426 = false ;
F_40 ( L_203 ,
V_63 -> V_208 . V_208 . V_213 ,
F_336 ( & V_63 -> V_208 ) ,
V_63 -> V_208 . V_24 ? L_196 : L_197 ,
V_95 ) ;
}
F_237 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_430 -> V_438 ( V_430 ) ) {
V_430 -> V_208 . V_433 = V_436 ;
V_430 -> V_63 -> V_426 = true ;
V_430 -> V_208 . V_63 = & V_430 -> V_63 -> V_208 ;
} else {
V_430 -> V_208 . V_433 = V_434 ;
V_430 -> V_208 . V_63 = NULL ;
}
F_40 ( L_204 ,
V_430 -> V_208 . V_208 . V_213 ,
F_245 ( & V_430 -> V_208 ) ,
V_430 -> V_208 . V_63 ? L_196 : L_197 ) ;
}
F_237 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_540 ( V_63 ) ;
}
F_543 (pipe) {
V_24 = F_35 ( V_4 -> V_96 [ V_95 ] ) ;
F_539 ( V_24 ) ;
}
if ( V_912 ) {
F_543 (pipe) {
F_459 ( V_4 -> V_96 [ V_95 ] ) ;
}
F_541 ( V_2 ) ;
} else {
F_446 ( V_2 ) ;
}
F_248 ( V_2 ) ;
F_545 ( V_2 ) ;
}
void F_546 ( struct V_1 * V_2 )
{
F_527 ( V_2 ) ;
F_547 ( V_2 ) ;
F_542 ( V_2 , false ) ;
}
void F_548 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_23 * V_24 ;
struct V_97 * V_97 ;
F_549 ( V_2 ) ;
F_147 ( & V_2 -> V_302 ) ;
F_550 () ;
F_237 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_24 -> V_253 )
continue;
V_97 = F_35 ( V_24 ) ;
F_142 ( V_24 ) ;
}
F_217 ( V_2 ) ;
F_551 ( V_2 ) ;
F_552 ( V_2 ) ;
if ( F_22 ( V_2 ) )
F_13 ( V_2 ) ;
F_148 ( & V_2 -> V_302 ) ;
F_553 ( V_2 ) ;
F_406 ( & V_4 -> V_918 ) ;
F_406 ( & V_4 -> V_919 . V_759 ) ;
F_554 () ;
F_555 ( V_2 ) ;
F_556 ( V_2 ) ;
}
struct V_435 * F_557 ( struct V_429 * V_430 )
{
return & F_247 ( V_430 ) -> V_208 ;
}
void F_558 ( struct V_437 * V_430 ,
struct V_62 * V_63 )
{
V_430 -> V_63 = V_63 ;
F_559 ( & V_430 -> V_208 ,
& V_63 -> V_208 ) ;
}
int F_560 ( struct V_1 * V_2 , bool V_125 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_920 ;
F_257 ( V_4 -> V_921 , V_922 , & V_920 ) ;
if ( V_125 )
V_920 &= ~ V_923 ;
else
V_920 |= V_923 ;
F_561 ( V_4 -> V_921 , V_922 , V_920 ) ;
return 0 ;
}
struct V_924 *
F_562 ( struct V_1 * V_2 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_924 * error ;
enum V_94 V_98 ;
int V_158 ;
error = F_455 ( sizeof( * error ) , V_925 ) ;
if ( error == NULL )
return NULL ;
F_543 (i) {
V_98 = F_34 ( V_4 , V_158 ) ;
error -> V_926 [ V_158 ] . V_927 = F_4 ( F_228 ( V_158 ) ) ;
error -> V_926 [ V_158 ] . V_928 = F_4 ( F_362 ( V_158 ) ) ;
error -> V_926 [ V_158 ] . V_208 = F_4 ( F_229 ( V_158 ) ) ;
error -> V_156 [ V_158 ] . V_927 = F_4 ( F_73 ( V_158 ) ) ;
error -> V_156 [ V_158 ] . V_868 = F_4 ( F_135 ( V_158 ) ) ;
error -> V_156 [ V_158 ] . V_695 = F_4 ( F_290 ( V_158 ) ) ;
error -> V_156 [ V_158 ] . V_680 = F_4 ( F_291 ( V_158 ) ) ;
error -> V_156 [ V_158 ] . V_692 = F_4 ( F_118 ( V_158 ) ) ;
if ( F_43 ( V_2 ) -> V_102 >= 4 ) {
error -> V_156 [ V_158 ] . V_929 = F_4 ( F_117 ( V_158 ) ) ;
error -> V_156 [ V_158 ] . V_930 = F_4 ( F_137 ( V_158 ) ) ;
}
error -> V_95 [ V_158 ] . V_931 = F_4 ( F_45 ( V_98 ) ) ;
error -> V_95 [ V_158 ] . V_932 = F_4 ( F_286 ( V_158 ) ) ;
error -> V_95 [ V_158 ] . V_752 = F_4 ( F_185 ( V_98 ) ) ;
error -> V_95 [ V_158 ] . V_933 = F_4 ( F_187 ( V_98 ) ) ;
error -> V_95 [ V_158 ] . V_749 = F_4 ( F_189 ( V_98 ) ) ;
error -> V_95 [ V_158 ] . V_754 = F_4 ( F_191 ( V_98 ) ) ;
error -> V_95 [ V_158 ] . V_934 = F_4 ( F_193 ( V_98 ) ) ;
error -> V_95 [ V_158 ] . V_751 = F_4 ( F_195 ( V_98 ) ) ;
}
return error ;
}
void
F_563 ( struct V_935 * V_53 ,
struct V_1 * V_2 ,
struct V_924 * error )
{
T_8 * V_4 = V_2 -> V_5 ;
int V_158 ;
F_564 ( V_53 , L_205 , V_4 -> V_301 ) ;
F_543 (i) {
F_564 ( V_53 , L_206 , V_158 ) ;
F_564 ( V_53 , L_207 , error -> V_95 [ V_158 ] . V_931 ) ;
F_564 ( V_53 , L_208 , error -> V_95 [ V_158 ] . V_932 ) ;
F_564 ( V_53 , L_209 , error -> V_95 [ V_158 ] . V_752 ) ;
F_564 ( V_53 , L_210 , error -> V_95 [ V_158 ] . V_933 ) ;
F_564 ( V_53 , L_211 , error -> V_95 [ V_158 ] . V_749 ) ;
F_564 ( V_53 , L_212 , error -> V_95 [ V_158 ] . V_754 ) ;
F_564 ( V_53 , L_213 , error -> V_95 [ V_158 ] . V_934 ) ;
F_564 ( V_53 , L_214 , error -> V_95 [ V_158 ] . V_751 ) ;
F_564 ( V_53 , L_215 , V_158 ) ;
F_564 ( V_53 , L_216 , error -> V_156 [ V_158 ] . V_927 ) ;
F_564 ( V_53 , L_217 , error -> V_156 [ V_158 ] . V_868 ) ;
F_564 ( V_53 , L_218 , error -> V_156 [ V_158 ] . V_695 ) ;
F_564 ( V_53 , L_219 , error -> V_156 [ V_158 ] . V_680 ) ;
F_564 ( V_53 , L_220 , error -> V_156 [ V_158 ] . V_692 ) ;
if ( F_43 ( V_2 ) -> V_102 >= 4 ) {
F_564 ( V_53 , L_221 , error -> V_156 [ V_158 ] . V_929 ) ;
F_564 ( V_53 , L_222 , error -> V_156 [ V_158 ] . V_930 ) ;
}
F_564 ( V_53 , L_223 , V_158 ) ;
F_564 ( V_53 , L_216 , error -> V_926 [ V_158 ] . V_927 ) ;
F_564 ( V_53 , L_219 , error -> V_926 [ V_158 ] . V_928 ) ;
F_564 ( V_53 , L_224 , error -> V_926 [ V_158 ] . V_208 ) ;
}
}
