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
return V_97 -> V_98 . V_99 ;
}
static void F_36 ( struct V_1 * V_2 , int V_95 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_100 , V_101 = F_37 ( V_95 ) ;
V_100 = F_4 ( V_101 ) ;
if ( F_38 ( F_39 ( V_101 ) != V_100 , 50 ) )
F_40 ( L_13 ) ;
}
void F_41 ( struct V_1 * V_2 , int V_95 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_102 = F_42 ( V_95 ) ;
if ( F_43 ( V_2 ) -> V_103 >= 5 ) {
F_36 ( V_2 , V_95 ) ;
return;
}
F_11 ( V_102 ,
F_4 ( V_102 ) | V_104 ) ;
if ( F_38 ( F_4 ( V_102 ) &
V_104 ,
50 ) )
F_40 ( L_13 ) ;
}
void F_44 ( struct V_1 * V_2 , int V_95 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_94 V_99 = F_34 ( V_4 ,
V_95 ) ;
if ( F_43 ( V_2 ) -> V_103 >= 4 ) {
int V_10 = F_45 ( V_99 ) ;
if ( F_38 ( ( F_4 ( V_10 ) & V_105 ) == 0 ,
100 ) )
F_46 ( 1 , L_14 ) ;
} else {
T_1 V_106 , V_107 ;
int V_10 = F_47 ( V_95 ) ;
unsigned long V_108 = V_109 + F_48 ( 100 ) ;
if ( F_23 ( V_2 ) )
V_107 = V_110 ;
else
V_107 = V_111 ;
do {
V_106 = F_4 ( V_10 ) & V_107 ;
F_49 ( 5 ) ;
} while ( ( ( F_4 ( V_10 ) & V_107 ) != V_106 ) &&
F_50 ( V_108 , V_109 ) );
if ( F_50 ( V_109 , V_108 ) )
F_46 ( 1 , L_14 ) ;
}
}
bool F_51 ( struct V_3 * V_4 ,
struct V_112 * V_113 )
{
T_1 V_114 ;
if ( F_52 ( V_4 -> V_2 ) ) {
switch( V_113 -> V_113 ) {
case V_115 :
V_114 = V_116 ;
break;
case V_117 :
V_114 = V_118 ;
break;
case V_119 :
V_114 = V_120 ;
break;
default:
return true ;
}
} else {
switch( V_113 -> V_113 ) {
case V_115 :
V_114 = V_121 ;
break;
case V_117 :
V_114 = V_122 ;
break;
case V_119 :
V_114 = V_123 ;
break;
default:
return true ;
}
}
return F_4 ( V_124 ) & V_114 ;
}
static const char * F_53 ( bool V_125 )
{
return V_125 ? L_15 : L_16 ;
}
static void F_54 ( struct V_3 * V_4 ,
enum V_95 V_95 , bool V_126 )
{
int V_10 ;
T_1 V_20 ;
bool V_127 ;
V_10 = F_55 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_127 = ! ! ( V_20 & V_128 ) ;
F_46 ( V_127 != V_126 ,
L_17 ,
F_53 ( V_126 ) , F_53 ( V_127 ) ) ;
}
static void F_56 ( struct V_3 * V_4 ,
struct V_129 * V_130 ,
struct V_97 * V_24 ,
bool V_126 )
{
T_1 V_20 ;
bool V_127 ;
if ( F_57 ( V_4 -> V_2 ) ) {
F_58 ( L_18 ) ;
return;
}
if ( F_46 ( ! V_130 ,
L_19 , F_53 ( V_126 ) ) )
return;
V_20 = F_4 ( V_130 -> V_131 ) ;
V_127 = ! ! ( V_20 & V_128 ) ;
F_46 ( V_127 != V_126 ,
L_20 ,
V_130 -> V_131 , F_53 ( V_126 ) , F_53 ( V_127 ) , V_20 ) ;
if ( V_24 && F_59 ( V_4 -> V_2 ) ) {
T_1 V_132 ;
V_132 = F_4 ( V_133 ) ;
V_127 = V_130 -> V_131 == V_134 ;
if ( ! F_46 ( ( ( V_132 >> ( 4 * V_24 -> V_95 ) ) & 1 ) != V_127 ,
L_21 ,
V_127 , V_24 -> V_95 , V_132 ) ) {
V_127 = ! ! ( V_20 >> ( 4 * V_24 -> V_95 + 3 ) ) ;
F_46 ( V_127 != V_126 ,
L_22 ,
V_130 -> V_131 == V_134 ,
F_53 ( V_126 ) ,
V_24 -> V_95 ,
V_20 ) ;
}
}
}
static void F_60 ( struct V_3 * V_4 ,
enum V_95 V_95 , bool V_126 )
{
int V_10 ;
T_1 V_20 ;
bool V_127 ;
enum V_94 V_99 = F_34 ( V_4 ,
V_95 ) ;
if ( F_61 ( V_4 -> V_2 ) ) {
V_10 = F_62 ( V_99 ) ;
V_20 = F_4 ( V_10 ) ;
V_127 = ! ! ( V_20 & V_135 ) ;
} else {
V_10 = F_63 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_127 = ! ! ( V_20 & V_136 ) ;
}
F_46 ( V_127 != V_126 ,
L_23 ,
F_53 ( V_126 ) , F_53 ( V_127 ) ) ;
}
static void F_64 ( struct V_3 * V_4 ,
enum V_95 V_95 , bool V_126 )
{
int V_10 ;
T_1 V_20 ;
bool V_127 ;
V_10 = F_65 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_127 = ! ! ( V_20 & V_137 ) ;
F_46 ( V_127 != V_126 ,
L_24 ,
F_53 ( V_126 ) , F_53 ( V_127 ) ) ;
}
static void F_66 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
if ( V_4 -> V_138 -> V_103 == 5 )
return;
if ( F_61 ( V_4 -> V_2 ) )
return;
V_10 = F_63 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
F_46 ( ! ( V_20 & V_139 ) , L_25 ) ;
}
static void F_67 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
V_10 = F_65 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
F_46 ( ! ( V_20 & V_140 ) , L_26 ) ;
}
static void F_68 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
int V_141 , V_77 ;
T_1 V_20 ;
enum V_95 V_142 = V_143 ;
bool V_144 = true ;
if ( F_3 ( V_4 -> V_2 ) ) {
V_141 = V_145 ;
V_77 = V_78 ;
} else {
V_141 = V_146 ;
V_77 = V_79 ;
}
V_20 = F_4 ( V_141 ) ;
if ( ! ( V_20 & V_147 ) ||
( ( V_20 & V_148 ) == V_148 ) )
V_144 = false ;
if ( F_4 ( V_77 ) & V_149 )
V_142 = V_150 ;
F_46 ( V_142 == V_95 && V_144 ,
L_27 ,
F_69 ( V_95 ) ) ;
}
void F_70 ( struct V_3 * V_4 ,
enum V_95 V_95 , bool V_126 )
{
int V_10 ;
T_1 V_20 ;
bool V_127 ;
enum V_94 V_99 = F_34 ( V_4 ,
V_95 ) ;
if ( V_95 == V_143 && V_4 -> V_151 & V_152 )
V_126 = true ;
if ( ! F_71 ( V_4 -> V_2 ) &&
V_99 != V_153 ) {
V_127 = false ;
} else {
V_10 = F_45 ( V_99 ) ;
V_20 = F_4 ( V_10 ) ;
V_127 = ! ! ( V_20 & V_154 ) ;
}
F_46 ( V_127 != V_126 ,
L_28 ,
F_69 ( V_95 ) , F_53 ( V_126 ) , F_53 ( V_127 ) ) ;
}
static void F_72 ( struct V_3 * V_4 ,
enum V_155 V_155 , bool V_126 )
{
int V_10 ;
T_1 V_20 ;
bool V_127 ;
V_10 = F_73 ( V_155 ) ;
V_20 = F_4 ( V_10 ) ;
V_127 = ! ! ( V_20 & V_156 ) ;
F_46 ( V_127 != V_126 ,
L_29 ,
F_74 ( V_155 ) , F_53 ( V_126 ) , F_53 ( V_127 ) ) ;
}
static void F_75 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
int V_10 , V_157 ;
T_1 V_20 ;
int V_158 ;
if ( F_3 ( V_4 -> V_2 ) || F_22 ( V_4 -> V_2 ) ) {
V_10 = F_73 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
F_46 ( ( V_20 & V_156 ) ,
L_30 ,
F_74 ( V_95 ) ) ;
return;
}
for ( V_157 = 0 ; V_157 < 2 ; V_157 ++ ) {
V_10 = F_73 ( V_157 ) ;
V_20 = F_4 ( V_10 ) ;
V_158 = ( V_20 & V_159 ) >>
V_160 ;
F_46 ( ( V_20 & V_156 ) && V_95 == V_158 ,
L_31 ,
F_74 ( V_157 ) , F_69 ( V_95 ) ) ;
}
}
static void F_76 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
int V_10 , V_157 ;
T_1 V_20 ;
if ( ! F_22 ( V_4 -> V_2 ) )
return;
for ( V_157 = 0 ; V_157 < V_4 -> V_161 ; V_157 ++ ) {
V_10 = F_77 ( V_95 , V_157 ) ;
V_20 = F_4 ( V_10 ) ;
F_46 ( ( V_20 & V_162 ) ,
L_32 ,
V_95 * 2 + V_157 , F_69 ( V_95 ) ) ;
}
}
static void F_78 ( struct V_3 * V_4 )
{
T_1 V_20 ;
bool V_125 ;
if ( F_57 ( V_4 -> V_2 ) ) {
F_58 ( L_33 ) ;
return;
}
V_20 = F_4 ( V_163 ) ;
V_125 = ! ! ( V_20 & ( V_164 | V_165 |
V_166 ) ) ;
F_46 ( ! V_125 , L_34 ) ;
}
static void F_79 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
bool V_125 ;
V_10 = F_80 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_125 = ! ! ( V_20 & V_167 ) ;
F_46 ( V_125 ,
L_35 ,
F_69 ( V_95 ) ) ;
}
static bool F_81 ( struct V_3 * V_4 ,
enum V_95 V_95 , T_1 V_168 , T_1 V_20 )
{
if ( ( V_20 & V_169 ) == 0 )
return false ;
if ( F_59 ( V_4 -> V_2 ) ) {
T_1 V_170 = F_82 ( V_95 ) ;
T_1 V_171 = F_4 ( V_170 ) ;
if ( ( V_171 & V_172 ) != V_168 )
return false ;
} else {
if ( ( V_20 & V_173 ) != ( V_95 << 30 ) )
return false ;
}
return true ;
}
static bool F_83 ( struct V_3 * V_4 ,
enum V_95 V_95 , T_1 V_20 )
{
if ( ( V_20 & V_174 ) == 0 )
return false ;
if ( F_59 ( V_4 -> V_2 ) ) {
if ( ( V_20 & V_175 ) != F_84 ( V_95 ) )
return false ;
} else {
if ( ( V_20 & V_176 ) != F_85 ( V_95 ) )
return false ;
}
return true ;
}
static bool F_86 ( struct V_3 * V_4 ,
enum V_95 V_95 , T_1 V_20 )
{
if ( ( V_20 & V_177 ) == 0 )
return false ;
if ( F_59 ( V_4 -> V_2 ) ) {
if ( ( V_20 & V_178 ) != F_87 ( V_95 ) )
return false ;
} else {
if ( ( V_20 & V_179 ) != F_88 ( V_95 ) )
return false ;
}
return true ;
}
static bool F_89 ( struct V_3 * V_4 ,
enum V_95 V_95 , T_1 V_20 )
{
if ( ( V_20 & V_180 ) == 0 )
return false ;
if ( F_59 ( V_4 -> V_2 ) ) {
if ( ( V_20 & V_178 ) != F_87 ( V_95 ) )
return false ;
} else {
if ( ( V_20 & V_181 ) != F_90 ( V_95 ) )
return false ;
}
return true ;
}
static void F_91 ( struct V_3 * V_4 ,
enum V_95 V_95 , int V_10 , T_1 V_168 )
{
T_1 V_20 = F_4 ( V_10 ) ;
F_46 ( F_81 ( V_4 , V_95 , V_168 , V_20 ) ,
L_36 ,
V_10 , F_69 ( V_95 ) ) ;
F_46 ( F_52 ( V_4 -> V_2 ) && ( V_20 & V_169 ) == 0
&& ( V_20 & V_182 ) ,
L_37 ) ;
}
static void F_92 ( struct V_3 * V_4 ,
enum V_95 V_95 , int V_10 )
{
T_1 V_20 = F_4 ( V_10 ) ;
F_46 ( F_83 ( V_4 , V_95 , V_20 ) ,
L_38 ,
V_10 , F_69 ( V_95 ) ) ;
F_46 ( F_52 ( V_4 -> V_2 ) && ( V_20 & V_174 ) == 0
&& ( V_20 & V_183 ) ,
L_39 ) ;
}
static void F_93 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
F_91 ( V_4 , V_95 , V_184 , V_185 ) ;
F_91 ( V_4 , V_95 , V_186 , V_187 ) ;
F_91 ( V_4 , V_95 , V_188 , V_189 ) ;
V_10 = V_190 ;
V_20 = F_4 ( V_10 ) ;
F_46 ( F_89 ( V_4 , V_95 , V_20 ) ,
L_40 ,
F_69 ( V_95 ) ) ;
V_10 = V_78 ;
V_20 = F_4 ( V_10 ) ;
F_46 ( F_86 ( V_4 , V_95 , V_20 ) ,
L_41 ,
F_69 ( V_95 ) ) ;
F_92 ( V_4 , V_95 , V_191 ) ;
F_92 ( V_4 , V_95 , V_192 ) ;
F_92 ( V_4 , V_95 , V_193 ) ;
}
static void F_94 ( struct V_3 * V_4 , enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
F_95 ( ! F_22 ( V_4 -> V_2 ) && V_4 -> V_138 -> V_103 >= 5 ) ;
if ( F_96 ( V_4 -> V_2 ) && ! F_97 ( V_4 -> V_2 ) )
F_68 ( V_4 , V_95 ) ;
V_10 = F_55 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_20 |= V_128 ;
F_11 ( V_10 , V_20 ) ;
F_14 ( V_10 ) ;
F_98 ( 150 ) ;
F_11 ( V_10 , V_20 ) ;
F_14 ( V_10 ) ;
F_98 ( 150 ) ;
F_11 ( V_10 , V_20 ) ;
F_14 ( V_10 ) ;
F_98 ( 150 ) ;
}
static void F_99 ( struct V_3 * V_4 , enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
if ( V_95 == V_143 && ( V_4 -> V_151 & V_152 ) )
return;
F_100 ( V_4 , V_95 ) ;
V_10 = F_55 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_20 &= ~ V_128 ;
F_11 ( V_10 , V_20 ) ;
F_14 ( V_10 ) ;
}
static void
F_101 ( struct V_3 * V_4 , T_4 V_10 , T_1 V_194 ,
enum V_195 V_196 )
{
T_1 V_197 ;
F_2 ( ! F_8 ( & V_4 -> V_11 ) ) ;
if ( F_38 ( ( F_4 ( V_198 ) & V_199 ) == 0 ,
100 ) ) {
F_10 ( L_42 ) ;
return;
}
F_11 ( V_200 , ( V_10 << 16 ) ) ;
F_11 ( V_201 , V_194 ) ;
if ( V_196 == V_202 )
V_197 = V_203 | V_204 ;
else
V_197 = V_205 | V_206 ;
F_11 ( V_198 , V_199 | V_197 ) ;
if ( F_38 ( ( F_4 ( V_198 ) & ( V_199 | V_207 ) ) == 0 ,
100 ) ) {
F_10 ( L_43 ) ;
return;
}
}
static T_1
F_102 ( struct V_3 * V_4 , T_4 V_10 ,
enum V_195 V_196 )
{
T_1 V_194 = 0 ;
F_2 ( ! F_8 ( & V_4 -> V_11 ) ) ;
if ( F_38 ( ( F_4 ( V_198 ) & V_199 ) == 0 ,
100 ) ) {
F_10 ( L_42 ) ;
return 0 ;
}
F_11 ( V_200 , ( V_10 << 16 ) ) ;
if ( V_196 == V_202 )
V_194 = V_203 | V_208 ;
else
V_194 = V_205 | V_209 ;
F_11 ( V_198 , V_194 | V_199 ) ;
if ( F_38 ( ( F_4 ( V_198 ) & ( V_199 | V_207 ) ) == 0 ,
100 ) ) {
F_10 ( L_44 ) ;
return 0 ;
}
return F_4 ( V_201 ) ;
}
static void F_103 ( struct V_97 * V_97 )
{
struct V_3 * V_4 = V_97 -> V_210 . V_2 -> V_5 ;
struct V_129 * V_130 ;
int V_10 ;
T_1 V_20 ;
F_95 ( V_4 -> V_138 -> V_103 < 5 ) ;
V_130 = V_97 -> V_211 ;
if ( V_130 == NULL )
return;
if ( F_2 ( V_130 -> V_212 == 0 ) )
return;
F_40 ( L_45 ,
V_130 -> V_131 , V_130 -> V_213 , V_130 -> V_214 ,
V_97 -> V_210 . V_210 . V_215 ) ;
F_78 ( V_4 ) ;
if ( V_130 -> V_213 ++ && V_130 -> V_214 ) {
F_104 ( V_4 , V_130 , NULL ) ;
return;
}
F_40 ( L_46 , V_130 -> V_131 ) ;
V_10 = V_130 -> V_131 ;
V_20 = F_4 ( V_10 ) ;
V_20 |= V_128 ;
F_11 ( V_10 , V_20 ) ;
F_14 ( V_10 ) ;
F_98 ( 200 ) ;
V_130 -> V_214 = true ;
}
static void F_105 ( struct V_97 * V_97 )
{
struct V_3 * V_4 = V_97 -> V_210 . V_2 -> V_5 ;
struct V_129 * V_130 = V_97 -> V_211 ;
int V_10 ;
T_1 V_20 ;
F_95 ( V_4 -> V_138 -> V_103 < 5 ) ;
if ( V_130 == NULL )
return;
if ( F_2 ( V_130 -> V_212 == 0 ) )
return;
F_40 ( L_47 ,
V_130 -> V_131 , V_130 -> V_213 , V_130 -> V_214 ,
V_97 -> V_210 . V_210 . V_215 ) ;
if ( F_2 ( V_130 -> V_213 == 0 ) ) {
F_106 ( V_4 , V_130 , NULL ) ;
return;
}
if ( -- V_130 -> V_213 ) {
F_104 ( V_4 , V_130 , NULL ) ;
return;
}
F_40 ( L_48 , V_130 -> V_131 ) ;
F_79 ( V_4 , V_97 -> V_95 ) ;
V_10 = V_130 -> V_131 ;
V_20 = F_4 ( V_10 ) ;
V_20 &= ~ V_128 ;
F_11 ( V_10 , V_20 ) ;
F_14 ( V_10 ) ;
F_98 ( 200 ) ;
V_130 -> V_214 = false ;
}
static void F_107 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_23 * V_24 = V_4 -> V_96 [ V_95 ] ;
T_5 V_10 , V_20 , V_216 ;
F_95 ( V_4 -> V_138 -> V_103 < 5 ) ;
F_104 ( V_4 ,
F_35 ( V_24 ) -> V_211 ,
F_35 ( V_24 ) ) ;
F_108 ( V_4 , V_95 ) ;
F_109 ( V_4 , V_95 ) ;
if ( F_59 ( V_2 ) ) {
V_10 = F_110 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_20 |= V_217 ;
F_11 ( V_10 , V_20 ) ;
}
V_10 = F_80 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_216 = F_4 ( F_45 ( V_95 ) ) ;
if ( F_52 ( V_4 -> V_2 ) ) {
V_20 &= ~ V_218 ;
V_20 |= V_216 & V_218 ;
}
V_20 &= ~ V_219 ;
if ( ( V_216 & V_220 ) == V_221 )
if ( F_52 ( V_4 -> V_2 ) &&
F_16 ( V_24 , V_41 ) )
V_20 |= V_222 ;
else
V_20 |= V_223 ;
else
V_20 |= V_224 ;
F_11 ( V_10 , V_20 | V_167 ) ;
if ( F_38 ( F_4 ( V_10 ) & V_225 , 100 ) )
F_10 ( L_49 , V_95 ) ;
}
static void F_111 ( struct V_3 * V_4 ,
enum V_94 V_99 )
{
T_1 V_20 , V_216 ;
F_95 ( V_4 -> V_138 -> V_103 < 5 ) ;
F_108 ( V_4 , (enum V_95 ) V_99 ) ;
F_109 ( V_4 , V_226 ) ;
V_20 = F_4 ( V_227 ) ;
V_20 |= V_217 ;
F_11 ( V_227 , V_20 ) ;
V_20 = V_167 ;
V_216 = F_4 ( F_45 ( V_99 ) ) ;
if ( ( V_216 & V_228 ) ==
V_221 )
V_20 |= V_223 ;
else
V_20 |= V_224 ;
F_11 ( F_80 ( V_226 ) , V_20 ) ;
if ( F_38 ( F_4 ( V_229 ) & V_225 , 100 ) )
F_10 ( L_50 ) ;
}
static void F_112 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_5 V_10 , V_20 ;
F_113 ( V_4 , V_95 ) ;
F_114 ( V_4 , V_95 ) ;
F_93 ( V_4 , V_95 ) ;
V_10 = F_80 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_20 &= ~ V_167 ;
F_11 ( V_10 , V_20 ) ;
if ( F_38 ( ( F_4 ( V_10 ) & V_225 ) == 0 , 50 ) )
F_10 ( L_51 , V_95 ) ;
if ( ! F_52 ( V_2 ) ) {
V_10 = F_110 ( V_95 ) ;
V_20 = F_4 ( V_10 ) ;
V_20 &= ~ V_217 ;
F_11 ( V_10 , V_20 ) ;
}
}
static void F_115 ( struct V_3 * V_4 )
{
T_1 V_20 ;
V_20 = F_4 ( V_229 ) ;
V_20 &= ~ V_167 ;
F_11 ( V_229 , V_20 ) ;
if ( F_38 ( ( F_4 ( V_229 ) & V_225 ) == 0 , 50 ) )
F_10 ( L_52 ) ;
V_20 = F_4 ( V_227 ) ;
V_20 &= ~ V_217 ;
F_11 ( V_227 , V_20 ) ;
}
static void F_116 ( struct V_3 * V_4 , enum V_95 V_95 ,
bool V_230 )
{
enum V_94 V_99 = F_34 ( V_4 ,
V_95 ) ;
enum V_95 V_231 ;
int V_10 ;
T_1 V_20 ;
if ( F_57 ( V_4 -> V_2 ) )
V_231 = V_226 ;
else
V_231 = V_95 ;
if ( ! F_3 ( V_4 -> V_2 ) )
F_117 ( V_4 , V_95 ) ;
else {
if ( V_230 ) {
F_67 ( V_4 , V_231 ) ;
F_66 ( V_4 ,
(enum V_95 ) V_99 ) ;
}
}
V_10 = F_45 ( V_99 ) ;
V_20 = F_4 ( V_10 ) ;
if ( V_20 & V_154 )
return;
F_11 ( V_10 , V_20 | V_154 ) ;
F_41 ( V_4 -> V_2 , V_95 ) ;
}
static void F_118 ( struct V_3 * V_4 ,
enum V_95 V_95 )
{
enum V_94 V_99 = F_34 ( V_4 ,
V_95 ) ;
int V_10 ;
T_1 V_20 ;
F_75 ( V_4 , V_95 ) ;
F_76 ( V_4 , V_95 ) ;
if ( V_95 == V_143 && ( V_4 -> V_151 & V_152 ) )
return;
V_10 = F_45 ( V_99 ) ;
V_20 = F_4 ( V_10 ) ;
if ( ( V_20 & V_154 ) == 0 )
return;
F_11 ( V_10 , V_20 & ~ V_154 ) ;
F_44 ( V_4 -> V_2 , V_95 ) ;
}
void F_119 ( struct V_3 * V_4 ,
enum V_155 V_155 )
{
if ( V_4 -> V_138 -> V_103 >= 4 )
F_11 ( F_120 ( V_155 ) , F_4 ( F_120 ( V_155 ) ) ) ;
else
F_11 ( F_121 ( V_155 ) , F_4 ( F_121 ( V_155 ) ) ) ;
}
static void F_122 ( struct V_3 * V_4 ,
enum V_155 V_155 , enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
F_123 ( V_4 , V_95 ) ;
V_10 = F_73 ( V_155 ) ;
V_20 = F_4 ( V_10 ) ;
if ( V_20 & V_156 )
return;
F_11 ( V_10 , V_20 | V_156 ) ;
F_119 ( V_4 , V_155 ) ;
F_41 ( V_4 -> V_2 , V_95 ) ;
}
static void F_124 ( struct V_3 * V_4 ,
enum V_155 V_155 , enum V_95 V_95 )
{
int V_10 ;
T_1 V_20 ;
V_10 = F_73 ( V_155 ) ;
V_20 = F_4 ( V_10 ) ;
if ( ( V_20 & V_156 ) == 0 )
return;
F_11 ( V_10 , V_20 & ~ V_156 ) ;
F_119 ( V_4 , V_155 ) ;
F_41 ( V_4 -> V_2 , V_95 ) ;
}
static bool F_125 ( struct V_1 * V_2 )
{
#ifdef F_126
if ( F_43 ( V_2 ) -> V_103 >= 6 && V_232 )
return true ;
#endif
return false ;
}
int
F_127 ( struct V_1 * V_2 ,
struct V_233 * V_234 ,
struct V_235 * V_236 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_237 ;
int V_238 ;
switch ( V_234 -> V_239 ) {
case V_240 :
if ( F_128 ( V_2 ) || F_129 ( V_2 ) )
V_237 = 128 * 1024 ;
else if ( F_43 ( V_2 ) -> V_103 >= 4 )
V_237 = 4 * 1024 ;
else
V_237 = 64 * 1024 ;
break;
case V_241 :
V_237 = 0 ;
break;
case V_242 :
F_58 ( L_53 ) ;
return - V_243 ;
default:
F_130 () ;
}
if ( F_125 ( V_2 ) && V_237 < 256 * 1024 )
V_237 = 256 * 1024 ;
V_4 -> V_244 . V_245 = false ;
V_238 = F_131 ( V_234 , V_237 , V_236 ) ;
if ( V_238 )
goto V_246;
V_238 = F_132 ( V_234 ) ;
if ( V_238 )
goto V_247;
F_133 ( V_234 ) ;
V_4 -> V_244 . V_245 = true ;
return 0 ;
V_247:
F_134 ( V_234 ) ;
V_246:
V_4 -> V_244 . V_245 = true ;
return V_238 ;
}
void F_135 ( struct V_233 * V_234 )
{
F_136 ( V_234 ) ;
F_134 ( V_234 ) ;
}
unsigned long F_137 ( int * V_248 , int * V_249 ,
unsigned int V_239 ,
unsigned int V_250 ,
unsigned int V_251 )
{
if ( V_239 != V_240 ) {
unsigned int V_252 , V_253 ;
V_252 = * V_249 / 8 ;
* V_249 %= 8 ;
V_253 = * V_248 / ( 512 / V_250 ) ;
* V_248 %= 512 / V_250 ;
return V_252 * V_251 * 8 + V_253 * 4096 ;
} else {
unsigned int V_254 ;
V_254 = * V_249 * V_251 + * V_248 * V_250 ;
* V_249 = 0 ;
* V_248 = ( V_254 & 4095 ) / V_250 ;
return V_254 & - 4096 ;
}
}
static int F_138 ( struct V_23 * V_24 , struct V_255 * V_256 ,
int V_248 , int V_249 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_257 * V_258 ;
struct V_233 * V_234 ;
int V_155 = V_97 -> V_155 ;
unsigned long V_259 ;
T_1 V_260 ;
T_1 V_10 ;
switch ( V_155 ) {
case 0 :
case 1 :
break;
default:
F_10 ( L_54 , V_155 ) ;
return - V_243 ;
}
V_258 = F_139 ( V_256 ) ;
V_234 = V_258 -> V_234 ;
V_10 = F_73 ( V_155 ) ;
V_260 = F_4 ( V_10 ) ;
V_260 &= ~ V_261 ;
switch ( V_256 -> V_262 ) {
case V_263 :
V_260 |= V_264 ;
break;
case V_265 :
case V_266 :
V_260 |= V_267 ;
break;
case V_268 :
V_260 |= V_269 ;
break;
case V_270 :
case V_271 :
V_260 |= V_272 ;
break;
case V_273 :
case V_274 :
V_260 |= V_275 ;
break;
case V_276 :
case V_277 :
V_260 |= V_278 ;
break;
case V_279 :
case V_280 :
V_260 |= V_281 ;
break;
default:
F_130 () ;
}
if ( F_43 ( V_2 ) -> V_103 >= 4 ) {
if ( V_234 -> V_239 != V_240 )
V_260 |= V_282 ;
else
V_260 &= ~ V_282 ;
}
F_11 ( V_10 , V_260 ) ;
V_259 = V_249 * V_256 -> V_283 [ 0 ] + V_248 * ( V_256 -> V_284 / 8 ) ;
if ( F_43 ( V_2 ) -> V_103 >= 4 ) {
V_97 -> V_285 =
F_137 ( & V_248 , & V_249 , V_234 -> V_239 ,
V_256 -> V_284 / 8 ,
V_256 -> V_283 [ 0 ] ) ;
V_259 -= V_97 -> V_285 ;
} else {
V_97 -> V_285 = V_259 ;
}
F_40 ( L_55 ,
V_234 -> V_286 , V_259 , V_248 , V_249 , V_256 -> V_283 [ 0 ] ) ;
F_11 ( F_140 ( V_155 ) , V_256 -> V_283 [ 0 ] ) ;
if ( F_43 ( V_2 ) -> V_103 >= 4 ) {
F_141 ( F_120 ( V_155 ) ,
V_234 -> V_286 + V_97 -> V_285 ) ;
F_11 ( F_142 ( V_155 ) , ( V_249 << 16 ) | V_248 ) ;
F_11 ( F_143 ( V_155 ) , V_259 ) ;
} else
F_11 ( F_121 ( V_155 ) , V_234 -> V_286 + V_259 ) ;
F_14 ( V_10 ) ;
return 0 ;
}
static int F_144 ( struct V_23 * V_24 ,
struct V_255 * V_256 , int V_248 , int V_249 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_257 * V_258 ;
struct V_233 * V_234 ;
int V_155 = V_97 -> V_155 ;
unsigned long V_259 ;
T_1 V_260 ;
T_1 V_10 ;
switch ( V_155 ) {
case 0 :
case 1 :
case 2 :
break;
default:
F_10 ( L_54 , V_155 ) ;
return - V_243 ;
}
V_258 = F_139 ( V_256 ) ;
V_234 = V_258 -> V_234 ;
V_10 = F_73 ( V_155 ) ;
V_260 = F_4 ( V_10 ) ;
V_260 &= ~ V_261 ;
switch ( V_256 -> V_262 ) {
case V_263 :
V_260 |= V_264 ;
break;
case V_268 :
V_260 |= V_269 ;
break;
case V_270 :
case V_271 :
V_260 |= V_272 ;
break;
case V_273 :
case V_274 :
V_260 |= V_275 ;
break;
case V_276 :
case V_277 :
V_260 |= V_278 ;
break;
case V_279 :
case V_280 :
V_260 |= V_281 ;
break;
default:
F_130 () ;
}
if ( V_234 -> V_239 != V_240 )
V_260 |= V_282 ;
else
V_260 &= ~ V_282 ;
V_260 |= V_287 ;
F_11 ( V_10 , V_260 ) ;
V_259 = V_249 * V_256 -> V_283 [ 0 ] + V_248 * ( V_256 -> V_284 / 8 ) ;
V_97 -> V_285 =
F_137 ( & V_248 , & V_249 , V_234 -> V_239 ,
V_256 -> V_284 / 8 ,
V_256 -> V_283 [ 0 ] ) ;
V_259 -= V_97 -> V_285 ;
F_40 ( L_55 ,
V_234 -> V_286 , V_259 , V_248 , V_249 , V_256 -> V_283 [ 0 ] ) ;
F_11 ( F_140 ( V_155 ) , V_256 -> V_283 [ 0 ] ) ;
F_141 ( F_120 ( V_155 ) ,
V_234 -> V_286 + V_97 -> V_285 ) ;
if ( F_145 ( V_2 ) ) {
F_11 ( F_146 ( V_155 ) , ( V_249 << 16 ) | V_248 ) ;
} else {
F_11 ( F_142 ( V_155 ) , ( V_249 << 16 ) | V_248 ) ;
F_11 ( F_143 ( V_155 ) , V_259 ) ;
}
F_14 ( V_10 ) ;
return 0 ;
}
static int
F_147 ( struct V_23 * V_24 , struct V_255 * V_256 ,
int V_248 , int V_249 , enum V_288 V_126 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_289 . V_290 )
V_4 -> V_289 . V_290 ( V_2 ) ;
F_148 ( V_24 ) ;
return V_4 -> V_289 . V_291 ( V_24 , V_256 , V_248 , V_249 ) ;
}
void F_149 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_23 * V_24 ;
F_150 (crtc, &dev->mode_config.crtc_list, head) {
struct V_97 * V_97 = F_35 ( V_24 ) ;
enum V_155 V_155 = V_97 -> V_155 ;
F_151 ( V_2 , V_155 ) ;
F_152 ( V_2 , V_155 ) ;
}
F_150 (crtc, &dev->mode_config.crtc_list, head) {
struct V_97 * V_97 = F_35 ( V_24 ) ;
F_153 ( & V_24 -> V_292 ) ;
if ( V_97 -> V_213 )
V_4 -> V_289 . V_291 ( V_24 , V_24 -> V_256 ,
V_24 -> V_248 , V_24 -> V_249 ) ;
F_154 ( & V_24 -> V_292 ) ;
}
}
static int
F_155 ( struct V_255 * V_293 )
{
struct V_233 * V_234 = F_139 ( V_293 ) -> V_234 ;
struct V_3 * V_4 = V_234 -> V_210 . V_2 -> V_5 ;
bool V_294 = V_4 -> V_244 . V_245 ;
int V_238 ;
V_4 -> V_244 . V_245 = false ;
V_238 = F_156 ( V_234 ) ;
V_4 -> V_244 . V_245 = V_294 ;
return V_238 ;
}
static void F_157 ( struct V_23 * V_24 , int V_248 , int V_249 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_295 * V_296 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
if ( ! V_2 -> V_297 -> V_298 )
return;
V_296 = V_2 -> V_297 -> V_298 -> V_299 ;
if ( ! V_296 -> V_300 )
return;
switch ( V_97 -> V_95 ) {
case 0 :
V_296 -> V_300 -> V_301 = V_248 ;
V_296 -> V_300 -> V_302 = V_249 ;
break;
case 1 :
V_296 -> V_300 -> V_303 = V_248 ;
V_296 -> V_300 -> V_304 = V_249 ;
break;
default:
break;
}
}
static int
F_158 ( struct V_23 * V_24 , int V_248 , int V_249 ,
struct V_255 * V_256 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_255 * V_293 ;
int V_238 ;
if ( ! V_256 ) {
F_10 ( L_56 ) ;
return 0 ;
}
if ( V_97 -> V_155 > F_43 ( V_2 ) -> V_305 ) {
F_10 ( L_57 ,
V_97 -> V_155 ,
F_43 ( V_2 ) -> V_305 ) ;
return - V_243 ;
}
F_153 ( & V_2 -> V_306 ) ;
V_238 = F_127 ( V_2 ,
F_139 ( V_256 ) -> V_234 ,
NULL ) ;
if ( V_238 != 0 ) {
F_154 ( & V_2 -> V_306 ) ;
F_10 ( L_58 ) ;
return V_238 ;
}
V_238 = V_4 -> V_289 . V_291 ( V_24 , V_256 , V_248 , V_249 ) ;
if ( V_238 ) {
F_135 ( F_139 ( V_256 ) -> V_234 ) ;
F_154 ( & V_2 -> V_306 ) ;
F_10 ( L_59 ) ;
return V_238 ;
}
V_293 = V_24 -> V_256 ;
V_24 -> V_256 = V_256 ;
V_24 -> V_248 = V_248 ;
V_24 -> V_249 = V_249 ;
if ( V_293 ) {
F_41 ( V_2 , V_97 -> V_95 ) ;
F_135 ( F_139 ( V_293 ) -> V_234 ) ;
}
F_159 ( V_2 ) ;
F_154 ( & V_2 -> V_306 ) ;
F_157 ( V_24 , V_248 , V_249 ) ;
return 0 ;
}
static void F_160 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_1 V_10 , V_307 ;
V_10 = F_63 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
if ( F_161 ( V_2 ) ) {
V_307 &= ~ V_308 ;
V_307 |= V_308 | V_309 ;
} else {
V_307 &= ~ V_310 ;
V_307 |= V_310 | V_309 ;
}
F_11 ( V_10 , V_307 ) ;
V_10 = F_65 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
if ( F_59 ( V_2 ) ) {
V_307 &= ~ V_311 ;
V_307 |= V_312 ;
} else {
V_307 &= ~ V_310 ;
V_307 |= V_310 ;
}
F_11 ( V_10 , V_307 | V_313 ) ;
F_14 ( V_10 ) ;
F_98 ( 1000 ) ;
if ( F_161 ( V_2 ) )
F_11 ( V_10 , F_4 ( V_10 ) | V_314 |
V_315 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_316 =
F_35 ( V_4 -> V_96 [ V_150 ] ) ;
struct V_97 * V_317 =
F_35 ( V_4 -> V_96 [ V_318 ] ) ;
T_5 V_307 ;
if ( ! V_316 -> V_210 . V_125 && ! V_317 -> V_210 . V_125 ) {
F_2 ( F_4 ( F_65 ( V_150 ) ) & V_137 ) ;
F_2 ( F_4 ( F_65 ( V_318 ) ) & V_137 ) ;
V_307 = F_4 ( V_319 ) ;
V_307 &= ~ V_320 ;
F_40 ( L_60 ) ;
F_11 ( V_319 , V_307 ) ;
}
}
static void F_163 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
int V_155 = V_97 -> V_155 ;
T_1 V_10 , V_307 , V_321 ;
F_123 ( V_4 , V_95 ) ;
F_164 ( V_4 , V_155 ) ;
V_10 = F_165 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ V_322 ;
V_307 &= ~ V_323 ;
F_11 ( V_10 , V_307 ) ;
F_4 ( V_10 ) ;
F_98 ( 150 ) ;
V_10 = F_63 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ ( 7 << 19 ) ;
V_307 |= ( V_97 -> V_324 - 1 ) << 19 ;
V_307 &= ~ V_310 ;
V_307 |= V_325 ;
F_11 ( V_10 , V_307 | V_136 ) ;
V_10 = F_65 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ V_310 ;
V_307 |= V_325 ;
F_11 ( V_10 , V_307 | V_137 ) ;
F_14 ( V_10 ) ;
F_98 ( 150 ) ;
F_11 ( F_166 ( V_95 ) , V_326 ) ;
F_11 ( F_166 ( V_95 ) , V_326 |
V_327 ) ;
V_10 = F_167 ( V_95 ) ;
for ( V_321 = 0 ; V_321 < 5 ; V_321 ++ ) {
V_307 = F_4 ( V_10 ) ;
F_40 ( L_61 , V_307 ) ;
if ( ( V_307 & V_323 ) ) {
F_40 ( L_62 ) ;
F_11 ( V_10 , V_307 | V_323 ) ;
break;
}
}
if ( V_321 == 5 )
F_10 ( L_63 ) ;
V_10 = F_63 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ V_310 ;
V_307 |= V_328 ;
F_11 ( V_10 , V_307 ) ;
V_10 = F_65 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ V_310 ;
V_307 |= V_328 ;
F_11 ( V_10 , V_307 ) ;
F_14 ( V_10 ) ;
F_98 ( 150 ) ;
V_10 = F_167 ( V_95 ) ;
for ( V_321 = 0 ; V_321 < 5 ; V_321 ++ ) {
V_307 = F_4 ( V_10 ) ;
F_40 ( L_61 , V_307 ) ;
if ( V_307 & V_322 ) {
F_11 ( V_10 , V_307 | V_322 ) ;
F_40 ( L_64 ) ;
break;
}
}
if ( V_321 == 5 )
F_10 ( L_65 ) ;
F_40 ( L_66 ) ;
}
static void F_168 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_1 V_10 , V_307 , V_157 , V_329 ;
V_10 = F_165 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ V_322 ;
V_307 &= ~ V_323 ;
F_11 ( V_10 , V_307 ) ;
F_14 ( V_10 ) ;
F_98 ( 150 ) ;
V_10 = F_63 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ ( 7 << 19 ) ;
V_307 |= ( V_97 -> V_324 - 1 ) << 19 ;
V_307 &= ~ V_310 ;
V_307 |= V_325 ;
V_307 &= ~ V_330 ;
V_307 |= V_331 ;
F_11 ( V_10 , V_307 | V_136 ) ;
F_11 ( F_169 ( V_95 ) ,
V_332 | V_333 ) ;
V_10 = F_65 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
if ( F_59 ( V_2 ) ) {
V_307 &= ~ V_311 ;
V_307 |= V_334 ;
} else {
V_307 &= ~ V_310 ;
V_307 |= V_325 ;
}
F_11 ( V_10 , V_307 | V_137 ) ;
F_14 ( V_10 ) ;
F_98 ( 150 ) ;
for ( V_157 = 0 ; V_157 < 4 ; V_157 ++ ) {
V_10 = F_63 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ V_330 ;
V_307 |= V_335 [ V_157 ] ;
F_11 ( V_10 , V_307 ) ;
F_14 ( V_10 ) ;
F_98 ( 500 ) ;
for ( V_329 = 0 ; V_329 < 5 ; V_329 ++ ) {
V_10 = F_167 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
F_40 ( L_61 , V_307 ) ;
if ( V_307 & V_323 ) {
F_11 ( V_10 , V_307 | V_323 ) ;
F_40 ( L_62 ) ;
break;
}
F_98 ( 50 ) ;
}
if ( V_329 < 5 )
break;
}
if ( V_157 == 4 )
F_10 ( L_63 ) ;
V_10 = F_63 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ V_310 ;
V_307 |= V_328 ;
if ( F_170 ( V_2 ) ) {
V_307 &= ~ V_330 ;
V_307 |= V_331 ;
}
F_11 ( V_10 , V_307 ) ;
V_10 = F_65 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
if ( F_59 ( V_2 ) ) {
V_307 &= ~ V_311 ;
V_307 |= V_336 ;
} else {
V_307 &= ~ V_310 ;
V_307 |= V_328 ;
}
F_11 ( V_10 , V_307 ) ;
F_14 ( V_10 ) ;
F_98 ( 150 ) ;
for ( V_157 = 0 ; V_157 < 4 ; V_157 ++ ) {
V_10 = F_63 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ V_330 ;
V_307 |= V_335 [ V_157 ] ;
F_11 ( V_10 , V_307 ) ;
F_14 ( V_10 ) ;
F_98 ( 500 ) ;
for ( V_329 = 0 ; V_329 < 5 ; V_329 ++ ) {
V_10 = F_167 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
F_40 ( L_61 , V_307 ) ;
if ( V_307 & V_322 ) {
F_11 ( V_10 , V_307 | V_322 ) ;
F_40 ( L_64 ) ;
break;
}
F_98 ( 50 ) ;
}
if ( V_329 < 5 )
break;
}
if ( V_157 == 4 )
F_10 ( L_65 ) ;
F_40 ( L_67 ) ;
}
static void F_171 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_1 V_10 , V_307 , V_157 ;
V_10 = F_165 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ V_322 ;
V_307 &= ~ V_323 ;
F_11 ( V_10 , V_307 ) ;
F_14 ( V_10 ) ;
F_98 ( 150 ) ;
F_40 ( L_68 ,
F_4 ( F_167 ( V_95 ) ) ) ;
V_10 = F_63 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ ( 7 << 19 ) ;
V_307 |= ( V_97 -> V_324 - 1 ) << 19 ;
V_307 &= ~ ( V_337 | V_308 ) ;
V_307 |= V_338 ;
V_307 &= ~ V_330 ;
V_307 |= V_331 ;
V_307 |= V_339 ;
F_11 ( V_10 , V_307 | V_136 ) ;
F_11 ( F_169 ( V_95 ) ,
V_332 | V_333 ) ;
V_10 = F_65 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ V_337 ;
V_307 &= ~ V_311 ;
V_307 |= V_334 ;
V_307 |= V_339 ;
F_11 ( V_10 , V_307 | V_137 ) ;
F_14 ( V_10 ) ;
F_98 ( 150 ) ;
for ( V_157 = 0 ; V_157 < 4 ; V_157 ++ ) {
V_10 = F_63 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ V_330 ;
V_307 |= V_335 [ V_157 ] ;
F_11 ( V_10 , V_307 ) ;
F_14 ( V_10 ) ;
F_98 ( 500 ) ;
V_10 = F_167 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
F_40 ( L_61 , V_307 ) ;
if ( V_307 & V_323 ||
( F_4 ( V_10 ) & V_323 ) ) {
F_11 ( V_10 , V_307 | V_323 ) ;
F_40 ( L_69 , V_157 ) ;
break;
}
}
if ( V_157 == 4 )
F_10 ( L_63 ) ;
V_10 = F_63 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ V_308 ;
V_307 |= V_340 ;
V_307 &= ~ V_330 ;
V_307 |= V_331 ;
F_11 ( V_10 , V_307 ) ;
V_10 = F_65 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ V_311 ;
V_307 |= V_336 ;
F_11 ( V_10 , V_307 ) ;
F_14 ( V_10 ) ;
F_98 ( 150 ) ;
for ( V_157 = 0 ; V_157 < 4 ; V_157 ++ ) {
V_10 = F_63 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ V_330 ;
V_307 |= V_335 [ V_157 ] ;
F_11 ( V_10 , V_307 ) ;
F_14 ( V_10 ) ;
F_98 ( 500 ) ;
V_10 = F_167 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
F_40 ( L_61 , V_307 ) ;
if ( V_307 & V_322 ) {
F_11 ( V_10 , V_307 | V_322 ) ;
F_40 ( L_70 , V_157 ) ;
break;
}
}
if ( V_157 == 4 )
F_10 ( L_65 ) ;
F_40 ( L_67 ) ;
}
static void F_172 ( struct V_97 * V_97 )
{
struct V_1 * V_2 = V_97 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_95 = V_97 -> V_95 ;
T_1 V_10 , V_307 ;
V_10 = F_65 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ ( ( 0x7 << 19 ) | ( 0x7 << 16 ) ) ;
V_307 |= ( V_97 -> V_324 - 1 ) << 19 ;
V_307 |= ( F_4 ( F_45 ( V_95 ) ) & V_218 ) << 11 ;
F_11 ( V_10 , V_307 | V_140 ) ;
F_14 ( V_10 ) ;
F_98 ( 200 ) ;
V_307 = F_4 ( V_10 ) ;
F_11 ( V_10 , V_307 | V_341 ) ;
F_14 ( V_10 ) ;
F_98 ( 200 ) ;
V_10 = F_63 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
if ( ( V_307 & V_139 ) == 0 ) {
F_11 ( V_10 , V_307 | V_139 ) ;
F_14 ( V_10 ) ;
F_98 ( 100 ) ;
}
}
static void F_173 ( struct V_97 * V_97 )
{
struct V_1 * V_2 = V_97 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_95 = V_97 -> V_95 ;
T_1 V_10 , V_307 ;
V_10 = F_65 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
F_11 ( V_10 , V_307 & ~ V_341 ) ;
V_10 = F_63 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
F_11 ( V_10 , V_307 & ~ V_139 ) ;
F_14 ( V_10 ) ;
F_98 ( 100 ) ;
V_10 = F_65 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
F_11 ( V_10 , V_307 & ~ V_140 ) ;
F_14 ( V_10 ) ;
F_98 ( 100 ) ;
}
static void F_174 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_1 V_10 , V_307 ;
V_10 = F_63 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
F_11 ( V_10 , V_307 & ~ V_136 ) ;
F_14 ( V_10 ) ;
V_10 = F_65 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ ( 0x7 << 16 ) ;
V_307 |= ( F_4 ( F_45 ( V_95 ) ) & V_218 ) << 11 ;
F_11 ( V_10 , V_307 & ~ V_137 ) ;
F_14 ( V_10 ) ;
F_98 ( 100 ) ;
if ( F_52 ( V_2 ) ) {
F_11 ( F_166 ( V_95 ) , V_326 ) ;
}
V_10 = F_63 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ V_310 ;
V_307 |= V_325 ;
F_11 ( V_10 , V_307 ) ;
V_10 = F_65 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
if ( F_59 ( V_2 ) ) {
V_307 &= ~ V_311 ;
V_307 |= V_334 ;
} else {
V_307 &= ~ V_310 ;
V_307 |= V_325 ;
}
V_307 &= ~ ( 0x07 << 16 ) ;
V_307 |= ( F_4 ( F_45 ( V_95 ) ) & V_218 ) << 11 ;
F_11 ( V_10 , V_307 ) ;
F_14 ( V_10 ) ;
F_98 ( 100 ) ;
}
static bool F_175 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
unsigned long V_342 ;
bool V_343 ;
if ( F_176 ( & V_4 -> V_344 ) ||
V_97 -> V_345 != F_177 ( & V_4 -> V_344 . V_345 ) )
return false ;
F_178 ( & V_2 -> V_346 , V_342 ) ;
V_343 = F_35 ( V_24 ) -> V_347 != NULL ;
F_179 ( & V_2 -> V_346 , V_342 ) ;
return V_343 ;
}
static void F_180 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_24 -> V_256 == NULL )
return;
F_2 ( F_181 ( & V_4 -> V_348 ) ) ;
F_182 ( V_4 -> V_348 ,
! F_175 ( V_24 ) ) ;
F_153 ( & V_2 -> V_306 ) ;
F_155 ( V_24 -> V_256 ) ;
F_154 ( & V_2 -> V_306 ) ;
}
static void F_183 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_349 , V_350 , V_351 , V_352 = 0 ;
T_1 V_307 ;
F_153 ( & V_4 -> V_11 ) ;
F_11 ( V_353 , V_354 ) ;
F_101 ( V_4 , V_355 ,
F_102 ( V_4 , V_355 , V_202 ) |
V_356 ,
V_202 ) ;
if ( V_24 -> V_357 . clock == 20000 ) {
V_351 = 1 ;
V_349 = 0x41 ;
V_350 = 0x20 ;
} else {
T_1 V_358 = 172800 * 1000 ;
T_1 V_359 = 64 ;
T_1 V_360 , V_361 , V_362 ;
V_360 = ( V_358 / V_24 -> V_357 . clock ) ;
V_361 = V_360 / V_359 ;
V_362 = V_360 % V_359 ;
V_351 = 0 ;
V_349 = V_361 - 2 ;
V_350 = V_362 ;
}
F_2 ( F_184 ( V_349 ) &
~ V_363 ) ;
F_2 ( F_185 ( V_352 ) &
~ V_364 ) ;
F_40 ( L_71 ,
V_24 -> V_357 . clock ,
V_351 ,
V_349 ,
V_352 ,
V_350 ) ;
V_307 = F_102 ( V_4 , V_365 , V_202 ) ;
V_307 &= ~ V_363 ;
V_307 |= F_184 ( V_349 ) ;
V_307 &= ~ V_364 ;
V_307 |= F_186 ( V_350 ) ;
V_307 |= F_185 ( V_352 ) ;
V_307 |= V_366 ;
F_101 ( V_4 , V_365 , V_307 , V_202 ) ;
V_307 = F_102 ( V_4 , V_367 , V_202 ) ;
V_307 &= ~ F_187 ( 1 ) ;
V_307 |= F_187 ( V_351 ) ;
F_101 ( V_4 , V_367 , V_307 , V_202 ) ;
V_307 = F_102 ( V_4 , V_355 , V_202 ) ;
V_307 &= ~ V_356 ;
F_101 ( V_4 , V_355 , V_307 , V_202 ) ;
F_98 ( 24 ) ;
F_11 ( V_353 , V_368 ) ;
F_154 ( & V_4 -> V_11 ) ;
}
static void F_188 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_1 V_10 , V_307 ;
F_79 ( V_4 , V_95 ) ;
F_11 ( F_189 ( V_95 ) ,
F_4 ( F_190 ( V_95 ) ) & V_369 ) ;
V_4 -> V_289 . V_370 ( V_24 ) ;
F_103 ( V_97 ) ;
if ( F_59 ( V_2 ) ) {
T_1 V_371 ;
V_307 = F_4 ( V_133 ) ;
switch ( V_95 ) {
default:
case 0 :
V_307 |= V_372 ;
V_371 = V_373 ;
break;
case 1 :
V_307 |= V_374 ;
V_371 = V_375 ;
break;
case 2 :
V_307 |= V_376 ;
V_371 = V_377 ;
break;
}
if ( V_97 -> V_211 -> V_131 == V_134 )
V_307 |= V_371 ;
else
V_307 &= ~ V_371 ;
F_11 ( V_133 , V_307 ) ;
}
F_68 ( V_4 , V_95 ) ;
F_11 ( F_191 ( V_95 ) , F_4 ( F_192 ( V_95 ) ) ) ;
F_11 ( F_193 ( V_95 ) , F_4 ( F_194 ( V_95 ) ) ) ;
F_11 ( F_195 ( V_95 ) , F_4 ( F_196 ( V_95 ) ) ) ;
F_11 ( F_197 ( V_95 ) , F_4 ( F_198 ( V_95 ) ) ) ;
F_11 ( F_199 ( V_95 ) , F_4 ( F_200 ( V_95 ) ) ) ;
F_11 ( F_201 ( V_95 ) , F_4 ( F_202 ( V_95 ) ) ) ;
F_11 ( F_203 ( V_95 ) , F_4 ( F_204 ( V_95 ) ) ) ;
F_160 ( V_24 ) ;
if ( F_59 ( V_2 ) &&
( F_16 ( V_24 , V_32 ) ||
F_16 ( V_24 , V_33 ) ) ) {
T_1 V_378 = ( F_4 ( F_45 ( V_95 ) ) & V_218 ) >> 5 ;
V_10 = F_82 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ ( V_172 |
V_379 |
V_380 ) ;
V_307 |= ( V_381 |
V_382 ) ;
V_307 |= V_378 << 9 ;
if ( V_24 -> V_357 . V_342 & V_383 )
V_307 |= V_384 ;
if ( V_24 -> V_357 . V_342 & V_385 )
V_307 |= V_386 ;
switch ( F_205 ( V_24 ) ) {
case V_184 :
V_307 |= V_185 ;
break;
case V_186 :
V_307 |= V_187 ;
break;
case V_188 :
V_307 |= V_189 ;
break;
default:
F_130 () ;
}
F_11 ( V_10 , V_307 ) ;
}
F_107 ( V_4 , V_95 ) ;
}
static void F_206 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
enum V_94 V_99 = V_97 -> V_98 . V_99 ;
F_79 ( V_4 , V_226 ) ;
F_183 ( V_24 ) ;
F_11 ( V_387 , F_4 ( F_192 ( V_99 ) ) ) ;
F_11 ( V_388 , F_4 ( F_194 ( V_99 ) ) ) ;
F_11 ( V_389 , F_4 ( F_196 ( V_99 ) ) ) ;
F_11 ( V_390 , F_4 ( F_198 ( V_99 ) ) ) ;
F_11 ( V_391 , F_4 ( F_200 ( V_99 ) ) ) ;
F_11 ( V_392 , F_4 ( F_202 ( V_99 ) ) ) ;
F_11 ( V_393 , F_4 ( F_204 ( V_99 ) ) ) ;
F_111 ( V_4 , V_99 ) ;
}
static void F_207 ( struct V_97 * V_97 )
{
struct V_129 * V_130 = V_97 -> V_211 ;
if ( V_130 == NULL )
return;
if ( V_130 -> V_212 == 0 ) {
F_46 ( 1 , L_72 ) ;
return;
}
-- V_130 -> V_212 ;
V_97 -> V_211 = NULL ;
}
static struct V_129 * F_208 ( struct V_97 * V_97 , T_1 V_394 , T_1 V_395 )
{
struct V_3 * V_4 = V_97 -> V_210 . V_2 -> V_5 ;
struct V_129 * V_130 ;
int V_157 ;
V_130 = V_97 -> V_211 ;
if ( V_130 ) {
F_40 ( L_73 ,
V_97 -> V_210 . V_210 . V_215 , V_130 -> V_131 ) ;
goto V_396;
}
if ( F_52 ( V_4 -> V_2 ) ) {
V_157 = V_97 -> V_95 ;
V_130 = & V_4 -> V_397 [ V_157 ] ;
F_40 ( L_74 ,
V_97 -> V_210 . V_210 . V_215 , V_130 -> V_131 ) ;
goto V_75;
}
for ( V_157 = 0 ; V_157 < V_4 -> V_398 ; V_157 ++ ) {
V_130 = & V_4 -> V_397 [ V_157 ] ;
if ( V_130 -> V_212 == 0 )
continue;
if ( V_394 == ( F_4 ( V_130 -> V_131 ) & 0x7fffffff ) &&
V_395 == F_4 ( V_130 -> V_399 ) ) {
F_40 ( L_75 ,
V_97 -> V_210 . V_210 . V_215 ,
V_130 -> V_131 , V_130 -> V_212 , V_130 -> V_213 ) ;
goto V_75;
}
}
for ( V_157 = 0 ; V_157 < V_4 -> V_398 ; V_157 ++ ) {
V_130 = & V_4 -> V_397 [ V_157 ] ;
if ( V_130 -> V_212 == 0 ) {
F_40 ( L_76 ,
V_97 -> V_210 . V_210 . V_215 , V_130 -> V_131 ) ;
goto V_75;
}
}
return NULL ;
V_75:
V_97 -> V_211 = V_130 ;
V_130 -> V_212 ++ ;
F_58 ( L_77 , V_157 , V_97 -> V_95 ) ;
V_396:
F_58 ( L_78 , V_130 -> V_131 ) ;
F_11 ( V_130 -> V_131 , V_394 & ~ V_128 ) ;
F_14 ( V_130 -> V_131 ) ;
F_98 ( 150 ) ;
F_11 ( V_130 -> V_399 , V_395 ) ;
F_11 ( V_130 -> V_131 , V_394 & ~ V_128 ) ;
V_130 -> V_214 = false ;
return V_130 ;
}
void F_209 ( struct V_1 * V_2 , int V_95 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_400 = F_47 ( V_95 ) ;
T_1 V_307 ;
V_307 = F_4 ( V_400 ) ;
F_98 ( 500 ) ;
if ( F_38 ( F_4 ( V_400 ) != V_307 , 5 ) ) {
if ( F_38 ( F_4 ( V_400 ) != V_307 , 5 ) )
F_10 ( L_79 , V_95 ) ;
}
}
static void F_210 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_62 * V_63 ;
int V_95 = V_97 -> V_95 ;
int V_155 = V_97 -> V_155 ;
T_1 V_307 ;
F_2 ( ! V_24 -> V_125 ) ;
if ( V_97 -> V_213 )
return;
V_97 -> V_213 = true ;
F_211 ( V_2 ) ;
if ( F_16 ( V_24 , V_27 ) ) {
V_307 = F_4 ( V_78 ) ;
if ( ( V_307 & V_177 ) == 0 )
F_11 ( V_78 , V_307 | V_177 ) ;
}
if ( V_97 -> V_98 . V_401 ) {
F_172 ( V_97 ) ;
} else {
F_113 ( V_4 , V_95 ) ;
F_114 ( V_4 , V_95 ) ;
}
F_26 (dev, crtc, encoder)
if ( V_63 -> V_402 )
V_63 -> V_402 ( V_63 ) ;
if ( V_4 -> V_403 &&
( F_16 ( V_24 , V_27 ) ||
F_16 ( V_24 , V_33 ) ) ) {
if ( F_161 ( V_2 ) )
F_11 ( F_212 ( V_95 ) , V_404 | V_405 |
F_213 ( V_95 ) ) ;
else
F_11 ( F_212 ( V_95 ) , V_404 | V_405 ) ;
F_11 ( F_214 ( V_95 ) , V_4 -> V_406 ) ;
F_11 ( F_215 ( V_95 ) , V_4 -> V_403 ) ;
}
F_216 ( V_24 ) ;
F_116 ( V_4 , V_95 ,
V_97 -> V_98 . V_401 ) ;
F_122 ( V_4 , V_155 , V_95 ) ;
if ( V_97 -> V_98 . V_401 )
F_188 ( V_24 ) ;
F_153 ( & V_2 -> V_306 ) ;
F_159 ( V_2 ) ;
F_154 ( & V_2 -> V_306 ) ;
F_217 ( V_24 , true ) ;
F_26 (dev, crtc, encoder)
V_63 -> V_407 ( V_63 ) ;
if ( F_59 ( V_2 ) )
F_209 ( V_2 , V_97 -> V_95 ) ;
F_41 ( V_2 , V_97 -> V_95 ) ;
}
static void F_218 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_62 * V_63 ;
int V_95 = V_97 -> V_95 ;
int V_155 = V_97 -> V_155 ;
F_2 ( ! V_24 -> V_125 ) ;
if ( V_97 -> V_213 )
return;
V_97 -> V_213 = true ;
F_211 ( V_2 ) ;
if ( V_97 -> V_98 . V_401 )
V_4 -> V_289 . V_370 ( V_24 ) ;
F_26 (dev, crtc, encoder)
if ( V_63 -> V_402 )
V_63 -> V_402 ( V_63 ) ;
F_219 ( V_97 ) ;
if ( V_4 -> V_403 &&
F_16 ( V_24 , V_33 ) ) {
F_11 ( F_212 ( V_95 ) , V_404 | V_405 |
F_213 ( V_95 ) ) ;
F_11 ( F_214 ( V_95 ) , V_4 -> V_406 ) ;
F_11 ( F_215 ( V_95 ) , V_4 -> V_403 ) ;
}
F_216 ( V_24 ) ;
F_220 ( V_24 ) ;
F_221 ( V_24 ) ;
F_116 ( V_4 , V_95 ,
V_97 -> V_98 . V_401 ) ;
F_122 ( V_4 , V_155 , V_95 ) ;
if ( V_97 -> V_98 . V_401 )
F_206 ( V_24 ) ;
F_153 ( & V_2 -> V_306 ) ;
F_159 ( V_2 ) ;
F_154 ( & V_2 -> V_306 ) ;
F_217 ( V_24 , true ) ;
F_26 (dev, crtc, encoder)
V_63 -> V_407 ( V_63 ) ;
F_41 ( V_2 , V_97 -> V_95 ) ;
}
static void F_222 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_62 * V_63 ;
int V_95 = V_97 -> V_95 ;
int V_155 = V_97 -> V_155 ;
T_1 V_10 , V_307 ;
if ( ! V_97 -> V_213 )
return;
F_26 (dev, crtc, encoder)
V_63 -> V_408 ( V_63 ) ;
F_180 ( V_24 ) ;
F_223 ( V_2 , V_95 ) ;
F_217 ( V_24 , false ) ;
F_124 ( V_4 , V_155 , V_95 ) ;
if ( V_4 -> V_409 == V_155 )
F_224 ( V_2 ) ;
F_118 ( V_4 , V_95 ) ;
F_11 ( F_212 ( V_95 ) , 0 ) ;
F_11 ( F_215 ( V_95 ) , 0 ) ;
F_26 (dev, crtc, encoder)
if ( V_63 -> V_410 )
V_63 -> V_410 ( V_63 ) ;
F_174 ( V_24 ) ;
F_112 ( V_4 , V_95 ) ;
if ( F_59 ( V_2 ) ) {
V_10 = F_82 ( V_95 ) ;
V_307 = F_4 ( V_10 ) ;
V_307 &= ~ ( V_381 | V_172 ) ;
V_307 |= V_411 ;
F_11 ( V_10 , V_307 ) ;
V_307 = F_4 ( V_133 ) ;
switch ( V_95 ) {
case 0 :
V_307 &= ~ ( V_372 | V_373 ) ;
break;
case 1 :
V_307 &= ~ ( V_374 | V_375 ) ;
break;
case 2 :
V_307 &= ~ ( V_376 | V_377 ) ;
break;
default:
F_130 () ;
}
F_11 ( V_133 , V_307 ) ;
}
F_105 ( V_97 ) ;
F_173 ( V_97 ) ;
V_97 -> V_213 = false ;
F_211 ( V_2 ) ;
F_153 ( & V_2 -> V_306 ) ;
F_159 ( V_2 ) ;
F_154 ( & V_2 -> V_306 ) ;
}
static void F_225 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_62 * V_63 ;
int V_95 = V_97 -> V_95 ;
int V_155 = V_97 -> V_155 ;
enum V_94 V_99 = V_97 -> V_98 . V_99 ;
if ( ! V_97 -> V_213 )
return;
F_26 (dev, crtc, encoder)
V_63 -> V_408 ( V_63 ) ;
F_180 ( V_24 ) ;
F_223 ( V_2 , V_95 ) ;
F_217 ( V_24 , false ) ;
F_124 ( V_4 , V_155 , V_95 ) ;
if ( V_4 -> V_409 == V_155 )
F_224 ( V_2 ) ;
F_118 ( V_4 , V_95 ) ;
F_226 ( V_4 , V_99 ) ;
if ( F_71 ( V_2 ) ) {
F_11 ( F_212 ( V_95 ) , 0 ) ;
F_11 ( F_215 ( V_95 ) , 0 ) ;
}
F_227 ( V_97 ) ;
F_26 (dev, crtc, encoder)
if ( V_63 -> V_410 )
V_63 -> V_410 ( V_63 ) ;
if ( V_97 -> V_98 . V_401 ) {
F_115 ( V_4 ) ;
F_228 ( V_24 ) ;
}
V_97 -> V_213 = false ;
F_211 ( V_2 ) ;
F_153 ( & V_2 -> V_306 ) ;
F_159 ( V_2 ) ;
F_154 ( & V_2 -> V_306 ) ;
}
static void F_229 ( struct V_23 * V_24 )
{
struct V_97 * V_97 = F_35 ( V_24 ) ;
F_207 ( V_97 ) ;
}
static void F_230 ( struct V_23 * V_24 )
{
struct V_97 * V_97 = F_35 ( V_24 ) ;
V_97 -> V_98 . V_99 = (enum V_94 ) V_97 -> V_95 ;
F_231 ( V_24 ) ;
}
static void F_232 ( struct V_97 * V_97 , bool V_407 )
{
if ( ! V_407 && V_97 -> V_412 ) {
struct V_1 * V_2 = V_97 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_153 ( & V_2 -> V_306 ) ;
V_4 -> V_244 . V_245 = false ;
( void ) F_233 ( V_97 -> V_412 ) ;
V_4 -> V_244 . V_245 = true ;
F_154 ( & V_2 -> V_306 ) ;
}
}
static void
F_234 ( struct V_3 * V_4 , enum V_95 V_95 )
{
T_1 V_413 = F_4 ( F_235 ( V_95 ) ) ;
if ( ( V_413 & V_414 ) == 0 ) {
T_1 V_415 = F_4 ( V_416 ) ;
F_11 ( V_416 , V_415 & ~ V_417 ) ;
F_11 ( F_235 ( V_95 ) , V_418 ) ;
F_41 ( V_4 -> V_2 , V_95 ) ;
F_11 ( F_235 ( V_95 ) , V_413 ) ;
F_11 ( F_236 ( V_95 ) , F_4 ( F_236 ( V_95 ) ) ) ;
F_11 ( V_416 , V_415 ) ;
}
}
static void F_237 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_62 * V_63 ;
int V_95 = V_97 -> V_95 ;
int V_155 = V_97 -> V_155 ;
F_2 ( ! V_24 -> V_125 ) ;
if ( V_97 -> V_213 )
return;
V_97 -> V_213 = true ;
F_211 ( V_2 ) ;
F_94 ( V_4 , V_95 ) ;
F_26 (dev, crtc, encoder)
if ( V_63 -> V_402 )
V_63 -> V_402 ( V_63 ) ;
F_116 ( V_4 , V_95 , false ) ;
F_122 ( V_4 , V_155 , V_95 ) ;
if ( F_20 ( V_2 ) )
F_234 ( V_4 , V_95 ) ;
F_216 ( V_24 ) ;
F_159 ( V_2 ) ;
F_232 ( V_97 , true ) ;
F_217 ( V_24 , true ) ;
F_26 (dev, crtc, encoder)
V_63 -> V_407 ( V_63 ) ;
}
static void F_238 ( struct V_97 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_95 V_95 ;
T_5 V_419 = F_4 ( V_420 ) ;
F_100 ( V_4 , V_24 -> V_95 ) ;
if ( F_43 ( V_2 ) -> V_103 >= 4 )
V_95 = ( V_419 & V_421 ) >> V_422 ;
else
V_95 = V_150 ;
if ( V_95 == V_24 -> V_95 ) {
F_58 ( L_80 , V_419 ) ;
F_11 ( V_420 , 0 ) ;
}
}
static void F_239 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_62 * V_63 ;
int V_95 = V_97 -> V_95 ;
int V_155 = V_97 -> V_155 ;
if ( ! V_97 -> V_213 )
return;
F_26 (dev, crtc, encoder)
V_63 -> V_408 ( V_63 ) ;
F_180 ( V_24 ) ;
F_223 ( V_2 , V_95 ) ;
F_232 ( V_97 , false ) ;
F_217 ( V_24 , false ) ;
if ( V_4 -> V_409 == V_155 )
F_224 ( V_2 ) ;
F_124 ( V_4 , V_155 , V_95 ) ;
F_118 ( V_4 , V_95 ) ;
F_238 ( V_97 ) ;
F_99 ( V_4 , V_95 ) ;
V_97 -> V_213 = false ;
F_159 ( V_2 ) ;
F_211 ( V_2 ) ;
}
static void F_240 ( struct V_23 * V_24 )
{
}
static void F_241 ( struct V_23 * V_24 ,
bool V_125 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_295 * V_296 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
if ( ! V_2 -> V_297 -> V_298 )
return;
V_296 = V_2 -> V_297 -> V_298 -> V_299 ;
if ( ! V_296 -> V_300 )
return;
switch ( V_95 ) {
case 0 :
V_296 -> V_300 -> V_423 = V_125 ? V_24 -> V_357 . V_424 : 0 ;
V_296 -> V_300 -> V_425 = V_125 ? V_24 -> V_357 . V_426 : 0 ;
break;
case 1 :
V_296 -> V_300 -> V_427 = V_125 ? V_24 -> V_357 . V_424 : 0 ;
V_296 -> V_300 -> V_428 = V_125 ? V_24 -> V_357 . V_426 : 0 ;
break;
default:
F_10 ( L_81 , F_69 ( V_95 ) ) ;
break;
}
}
void F_242 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_62 * V_62 ;
bool V_407 = false ;
F_26 (dev, crtc, intel_encoder)
V_407 |= V_62 -> V_429 ;
if ( V_407 )
V_4 -> V_289 . V_430 ( V_24 ) ;
else
V_4 -> V_289 . V_431 ( V_24 ) ;
F_241 ( V_24 , V_407 ) ;
}
static void F_243 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_432 * V_433 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
F_2 ( ! V_24 -> V_125 ) ;
V_97 -> V_434 = false ;
V_4 -> V_289 . V_431 ( V_24 ) ;
F_241 ( V_24 , false ) ;
V_4 -> V_289 . V_435 ( V_24 ) ;
F_244 ( V_2 -> V_5 , F_35 ( V_24 ) -> V_155 ) ;
F_100 ( V_2 -> V_5 , F_35 ( V_24 ) -> V_95 ) ;
if ( V_24 -> V_256 ) {
F_153 ( & V_2 -> V_306 ) ;
F_135 ( F_139 ( V_24 -> V_256 ) -> V_234 ) ;
F_154 ( & V_2 -> V_306 ) ;
V_24 -> V_256 = NULL ;
}
F_150 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_433 -> V_63 || ! V_433 -> V_63 -> V_24 )
continue;
if ( V_433 -> V_63 -> V_24 != V_24 )
continue;
V_433 -> V_436 = V_437 ;
F_245 ( V_433 -> V_63 ) -> V_429 = false ;
}
}
void F_246 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
F_150 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_24 -> V_125 )
F_243 ( V_24 ) ;
}
}
void F_247 ( struct V_438 * V_63 )
{
struct V_62 * V_62 = F_245 ( V_63 ) ;
F_248 ( V_63 ) ;
F_249 ( V_62 ) ;
}
void F_250 ( struct V_62 * V_63 , int V_357 )
{
if ( V_357 == V_439 ) {
V_63 -> V_429 = true ;
F_242 ( V_63 -> V_210 . V_24 ) ;
} else {
V_63 -> V_429 = false ;
F_242 ( V_63 -> V_210 . V_24 ) ;
}
}
static void F_251 ( struct V_440 * V_433 )
{
if ( V_433 -> V_441 ( V_433 ) ) {
struct V_62 * V_63 = V_433 -> V_63 ;
struct V_23 * V_24 ;
bool V_442 ;
enum V_95 V_95 ;
F_40 ( L_82 ,
V_433 -> V_210 . V_210 . V_215 ,
F_252 ( & V_433 -> V_210 ) ) ;
F_46 ( V_433 -> V_210 . V_436 == V_437 ,
L_83 ) ;
F_46 ( V_433 -> V_210 . V_63 != & V_63 -> V_210 ,
L_84 ) ;
F_46 ( ! V_63 -> V_429 ,
L_85 ) ;
V_442 = V_63 -> V_441 ( V_63 , & V_95 ) ;
F_46 ( ! V_442 , L_86 ) ;
if ( F_2 ( ! V_63 -> V_210 . V_24 ) )
return;
V_24 = V_63 -> V_210 . V_24 ;
F_46 ( ! V_24 -> V_125 , L_87 ) ;
F_46 ( ! F_35 ( V_24 ) -> V_213 , L_88 ) ;
F_46 ( V_95 != F_35 ( V_24 ) -> V_95 ,
L_89 ) ;
}
}
void F_253 ( struct V_432 * V_433 , int V_357 )
{
struct V_62 * V_63 = F_254 ( V_433 ) ;
if ( V_357 != V_439 )
V_357 = V_437 ;
if ( V_357 == V_433 -> V_436 )
return;
V_433 -> V_436 = V_357 ;
if ( V_63 -> V_210 . V_24 )
F_250 ( V_63 , V_357 ) ;
else
F_2 ( V_63 -> V_429 != false ) ;
F_255 ( V_433 -> V_2 ) ;
}
bool F_256 ( struct V_440 * V_433 )
{
enum V_95 V_95 = 0 ;
struct V_62 * V_63 = V_433 -> V_63 ;
return V_63 -> V_441 ( V_63 , & V_95 ) ;
}
static bool F_257 ( struct V_23 * V_24 ,
struct V_443 * V_444 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_445 * V_446 = & V_444 -> V_446 ;
if ( F_3 ( V_2 ) ) {
if ( V_444 -> V_447 . clock * 3
> V_448 * 4 )
return false ;
}
if ( ! V_444 -> V_449 )
F_258 ( V_446 , 0 ) ;
if ( ( F_43 ( V_2 ) -> V_103 > 4 || F_20 ( V_2 ) ) &&
V_446 -> V_450 == V_446 -> V_424 )
return false ;
if ( ( F_20 ( V_2 ) || F_22 ( V_2 ) ) && V_444 -> V_451 > 10 * 3 ) {
V_444 -> V_451 = 10 * 3 ;
} else if ( F_43 ( V_2 ) -> V_103 <= 4 && V_444 -> V_451 > 8 * 3 ) {
V_444 -> V_451 = 8 * 3 ;
}
return true ;
}
static int F_259 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_260 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_261 ( struct V_1 * V_2 )
{
return 333000 ;
}
static int F_262 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_263 ( struct V_1 * V_2 )
{
T_4 V_452 = 0 ;
F_264 ( V_2 -> V_453 , V_454 , & V_452 ) ;
if ( V_452 & V_455 )
return 133000 ;
else {
switch ( V_452 & V_456 ) {
case V_457 :
return 333000 ;
default:
case V_458 :
return 190000 ;
}
}
}
static int F_265 ( struct V_1 * V_2 )
{
return 266000 ;
}
static int F_266 ( struct V_1 * V_2 )
{
T_4 V_459 = 0 ;
switch ( V_459 & V_460 ) {
case V_461 :
case V_462 :
return 200000 ;
case V_463 :
return 250000 ;
case V_464 :
return 133000 ;
}
return 0 ;
}
static int F_267 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_268 ( T_5 * V_465 , T_5 * V_466 )
{
while ( * V_465 > V_467 ||
* V_466 > V_467 ) {
* V_465 >>= 1 ;
* V_466 >>= 1 ;
}
}
static void F_269 ( unsigned int V_53 , unsigned int V_59 ,
T_5 * V_468 , T_5 * V_469 )
{
* V_469 = F_270 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_468 = F_271 ( ( V_470 ) V_53 * * V_469 , V_59 ) ;
F_268 ( V_468 , V_469 ) ;
}
void
F_272 ( int V_284 , int V_471 ,
int V_472 , int V_473 ,
struct V_474 * V_475 )
{
V_475 -> V_476 = 64 ;
F_269 ( V_284 * V_472 ,
V_473 * V_471 * 8 ,
& V_475 -> V_477 , & V_475 -> V_478 ) ;
F_269 ( V_472 , V_473 ,
& V_475 -> V_479 , & V_475 -> V_480 ) ;
}
static inline bool F_273 ( struct V_3 * V_4 )
{
if ( V_481 >= 0 )
return V_481 != 0 ;
return V_4 -> V_482
&& ! ( V_4 -> V_151 & V_483 ) ;
}
static int F_274 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_25 = 27000 ;
return 100000 ;
if ( F_16 ( V_24 , V_39 ) ) {
V_25 = 96000 ;
} else if ( F_16 ( V_24 , V_27 ) ) {
if ( F_273 ( V_4 ) )
V_25 = 100000 ;
else
V_25 = 96000 ;
} else if ( F_16 ( V_24 , V_33 ) ) {
V_25 = 100000 ;
}
return V_25 ;
}
static int F_275 ( struct V_23 * V_24 , int V_484 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_25 ;
if ( F_22 ( V_2 ) ) {
V_25 = F_274 ( V_24 ) ;
} else if ( F_16 ( V_24 , V_27 ) &&
F_273 ( V_4 ) && V_484 < 2 ) {
V_25 = V_4 -> V_485 * 1000 ;
F_40 ( L_90 ,
V_25 / 1000 ) ;
} else if ( ! F_23 ( V_2 ) ) {
V_25 = 96000 ;
} else {
V_25 = 48000 ;
}
return V_25 ;
}
static void F_276 ( struct V_97 * V_24 )
{
unsigned V_486 = V_24 -> V_98 . V_446 . clock ;
struct V_394 * clock = & V_24 -> V_98 . V_394 ;
if ( V_486 >= 100000 && V_486 < 140500 ) {
clock -> V_56 = 2 ;
clock -> V_57 = 10 ;
clock -> V_59 = 3 ;
clock -> V_61 = 16 ;
clock -> V_54 = 8 ;
} else if ( V_486 >= 140500 && V_486 <= 200000 ) {
clock -> V_56 = 1 ;
clock -> V_57 = 10 ;
clock -> V_59 = 6 ;
clock -> V_61 = 12 ;
clock -> V_54 = 8 ;
}
V_24 -> V_98 . V_487 = true ;
}
static void F_277 ( struct V_97 * V_24 ,
T_3 * V_488 )
{
struct V_1 * V_2 = V_24 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_95 = V_24 -> V_95 ;
T_1 V_395 , V_489 = 0 ;
struct V_394 * clock = & V_24 -> V_98 . V_394 ;
if ( F_21 ( V_2 ) ) {
V_395 = ( 1 << clock -> V_59 ) << 16 | clock -> V_61 << 8 | clock -> V_54 ;
if ( V_488 )
V_489 = ( 1 << V_488 -> V_59 ) << 16 |
V_488 -> V_61 << 8 | V_488 -> V_54 ;
} else {
V_395 = clock -> V_59 << 16 | clock -> V_61 << 8 | clock -> V_54 ;
if ( V_488 )
V_489 = V_488 -> V_59 << 16 | V_488 -> V_61 << 8 |
V_488 -> V_54 ;
}
F_11 ( F_278 ( V_95 ) , V_395 ) ;
V_24 -> V_490 = false ;
if ( F_16 ( & V_24 -> V_210 , V_27 ) &&
V_488 && V_491 ) {
F_11 ( F_279 ( V_95 ) , V_489 ) ;
V_24 -> V_490 = true ;
} else {
F_11 ( F_279 ( V_95 ) , V_395 ) ;
}
}
static void F_280 ( struct V_97 * V_24 )
{
if ( V_24 -> V_98 . V_401 )
F_281 ( V_24 , & V_24 -> V_98 . V_492 ) ;
else
F_282 ( V_24 , & V_24 -> V_98 . V_492 ) ;
}
static void F_283 ( struct V_97 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_95 = V_24 -> V_95 ;
T_1 V_394 , V_493 , V_494 ;
T_1 V_80 , V_81 , V_82 , V_83 , V_84 ;
bool V_495 ;
T_1 V_307 ;
F_153 ( & V_4 -> V_11 ) ;
V_495 = F_16 ( & V_24 -> V_210 , V_41 ) ||
F_16 ( & V_24 -> V_210 , V_38 ) ;
V_394 = V_496 ;
V_394 |= V_497 ;
V_394 |= V_498 ;
V_394 |= V_499 ;
F_11 ( F_55 ( V_95 ) , V_394 ) ;
F_14 ( F_55 ( V_95 ) ) ;
V_80 = V_24 -> V_98 . V_394 . V_59 ;
V_81 = V_24 -> V_98 . V_394 . V_61 ;
V_82 = V_24 -> V_98 . V_394 . V_54 ;
V_83 = V_24 -> V_98 . V_394 . V_56 ;
V_84 = V_24 -> V_98 . V_394 . V_57 ;
V_493 = ( ( V_81 << V_500 ) | ( V_82 & V_501 ) ) ;
V_493 |= ( ( V_83 << V_502 ) | ( V_84 << V_503 ) ) ;
V_493 |= ( ( V_80 << V_504 ) ) ;
V_493 |= ( 1 << V_505 ) ;
V_493 |= ( 1 << V_506 ) ;
V_493 |= V_507 ;
F_12 ( V_4 , F_284 ( V_95 ) , V_493 ) ;
F_12 ( V_4 , F_285 ( V_95 ) , 0x01000000 ) ;
V_494 = ( 1 << V_508 ) | ( 5 << V_509 ) |
( 3 << V_510 ) | ( 1 << 20 ) |
( 7 << V_511 ) | ( 8 << V_512 ) |
( 5 << V_513 ) ;
F_12 ( V_4 , F_286 ( V_95 ) , V_494 ) ;
F_12 ( V_4 , F_287 ( V_95 ) , 0x005f003b ) ;
V_394 |= V_128 ;
F_11 ( F_55 ( V_95 ) , V_394 ) ;
F_14 ( F_55 ( V_95 ) ) ;
if ( F_38 ( ( ( F_4 ( F_55 ( V_95 ) ) & V_514 ) == V_514 ) , 1 ) )
F_10 ( L_91 , V_95 ) ;
F_12 ( V_4 , V_515 , 0x620 ) ;
if ( V_24 -> V_98 . V_516 )
F_280 ( V_24 ) ;
F_11 ( F_55 ( V_95 ) , V_394 ) ;
F_14 ( F_55 ( V_95 ) ) ;
F_98 ( 150 ) ;
V_307 = 0 ;
if ( V_495 ) {
V_307 = 0 ;
if ( V_24 -> V_98 . V_517 > 1 ) {
V_307 = ( V_24 -> V_98 . V_517 - 1 )
<< V_518 ;
}
}
F_11 ( F_288 ( V_95 ) , V_307 ) ;
F_14 ( F_288 ( V_95 ) ) ;
if( F_16 ( & V_24 -> V_210 , V_32 )
|| F_16 ( & V_24 -> V_210 , V_38 ) ) {
V_307 = 0x1000C4 ;
if( V_95 == 1 )
V_307 |= ( 1 << 21 ) ;
F_12 ( V_4 , V_519 , V_307 ) ;
}
if( F_16 ( & V_24 -> V_210 , V_33 ) ) {
V_307 = 0x1000C4 ;
if( V_95 == 1 )
V_307 |= ( 1 << 21 ) ;
F_12 ( V_4 , V_520 , V_307 ) ;
}
F_154 ( & V_4 -> V_11 ) ;
}
static void F_289 ( struct V_97 * V_24 ,
T_3 * V_488 ,
int V_484 )
{
struct V_1 * V_2 = V_24 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_62 * V_63 ;
int V_95 = V_24 -> V_95 ;
T_1 V_394 ;
bool V_495 ;
struct V_394 * clock = & V_24 -> V_98 . V_394 ;
F_277 ( V_24 , V_488 ) ;
V_495 = F_16 ( & V_24 -> V_210 , V_41 ) ||
F_16 ( & V_24 -> V_210 , V_38 ) ;
V_394 = V_496 ;
if ( F_16 ( & V_24 -> V_210 , V_27 ) )
V_394 |= V_521 ;
else
V_394 |= V_522 ;
if ( V_495 ) {
if ( ( V_24 -> V_98 . V_517 > 1 ) &&
( F_290 ( V_2 ) || F_291 ( V_2 ) || F_292 ( V_2 ) ) ) {
V_394 |= ( V_24 -> V_98 . V_517 - 1 )
<< V_523 ;
}
V_394 |= V_524 ;
}
if ( F_16 ( & V_24 -> V_210 , V_32 ) )
V_394 |= V_524 ;
if ( F_21 ( V_2 ) )
V_394 |= ( 1 << ( clock -> V_56 - 1 ) ) << V_525 ;
else {
V_394 |= ( 1 << ( clock -> V_56 - 1 ) ) << V_526 ;
if ( F_20 ( V_2 ) && V_488 )
V_394 |= ( 1 << ( V_488 -> V_56 - 1 ) ) << V_527 ;
}
switch ( clock -> V_57 ) {
case 5 :
V_394 |= V_528 ;
break;
case 7 :
V_394 |= V_529 ;
break;
case 10 :
V_394 |= V_530 ;
break;
case 14 :
V_394 |= V_531 ;
break;
}
if ( F_43 ( V_2 ) -> V_103 >= 4 )
V_394 |= ( 6 << V_532 ) ;
if ( V_495 && F_16 ( & V_24 -> V_210 , V_533 ) )
V_394 |= V_534 ;
else if ( F_16 ( & V_24 -> V_210 , V_533 ) )
V_394 |= 3 ;
else if ( F_16 ( & V_24 -> V_210 , V_27 ) &&
F_273 ( V_4 ) && V_484 < 2 )
V_394 |= V_535 ;
else
V_394 |= V_536 ;
V_394 |= V_128 ;
F_11 ( F_55 ( V_95 ) , V_394 & ~ V_128 ) ;
F_14 ( F_55 ( V_95 ) ) ;
F_98 ( 150 ) ;
F_26 (dev, &crtc->base, encoder)
if ( V_63 -> V_537 )
V_63 -> V_537 ( V_63 ) ;
if ( V_24 -> V_98 . V_516 )
F_280 ( V_24 ) ;
F_11 ( F_55 ( V_95 ) , V_394 ) ;
F_14 ( F_55 ( V_95 ) ) ;
F_98 ( 150 ) ;
if ( F_43 ( V_2 ) -> V_103 >= 4 ) {
T_1 V_307 = 0 ;
if ( V_495 ) {
V_307 = 0 ;
if ( V_24 -> V_98 . V_517 > 1 ) {
V_307 = ( V_24 -> V_98 . V_517 - 1 )
<< V_518 ;
}
}
F_11 ( F_288 ( V_95 ) , V_307 ) ;
} else {
F_11 ( F_55 ( V_95 ) , V_394 ) ;
}
}
static void F_293 ( struct V_97 * V_24 ,
struct V_445 * V_446 ,
T_3 * V_488 ,
int V_484 )
{
struct V_1 * V_2 = V_24 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_62 * V_63 ;
int V_95 = V_24 -> V_95 ;
T_1 V_394 ;
struct V_394 * clock = & V_24 -> V_98 . V_394 ;
F_277 ( V_24 , V_488 ) ;
V_394 = V_496 ;
if ( F_16 ( & V_24 -> V_210 , V_27 ) ) {
V_394 |= ( 1 << ( clock -> V_56 - 1 ) ) << V_526 ;
} else {
if ( clock -> V_56 == 2 )
V_394 |= V_538 ;
else
V_394 |= ( clock -> V_56 - 2 ) << V_526 ;
if ( clock -> V_57 == 4 )
V_394 |= V_539 ;
}
if ( F_16 ( & V_24 -> V_210 , V_27 ) &&
F_273 ( V_4 ) && V_484 < 2 )
V_394 |= V_535 ;
else
V_394 |= V_536 ;
V_394 |= V_128 ;
F_11 ( F_55 ( V_95 ) , V_394 & ~ V_128 ) ;
F_14 ( F_55 ( V_95 ) ) ;
F_98 ( 150 ) ;
F_26 (dev, &crtc->base, encoder)
if ( V_63 -> V_537 )
V_63 -> V_537 ( V_63 ) ;
F_11 ( F_55 ( V_95 ) , V_394 ) ;
F_14 ( F_55 ( V_95 ) ) ;
F_98 ( 150 ) ;
F_11 ( F_55 ( V_95 ) , V_394 ) ;
}
static void F_294 ( struct V_97 * V_97 ,
struct V_445 * V_357 ,
struct V_445 * V_446 )
{
struct V_1 * V_2 = V_97 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_95 V_95 = V_97 -> V_95 ;
enum V_94 V_99 = V_97 -> V_98 . V_99 ;
T_5 V_540 ;
if ( ! F_23 ( V_2 ) && V_446 -> V_342 & V_541 ) {
V_446 -> V_542 -= 1 ;
V_446 -> V_543 -= 1 ;
V_540 = V_446 -> V_544
- V_446 -> V_545 / 2 ;
} else {
V_540 = 0 ;
}
if ( F_43 ( V_2 ) -> V_103 > 3 )
F_11 ( F_204 ( V_99 ) , V_540 ) ;
F_11 ( F_192 ( V_99 ) ,
( V_446 -> V_546 - 1 ) |
( ( V_446 -> V_545 - 1 ) << 16 ) ) ;
F_11 ( F_194 ( V_99 ) ,
( V_446 -> V_547 - 1 ) |
( ( V_446 -> V_548 - 1 ) << 16 ) ) ;
F_11 ( F_196 ( V_99 ) ,
( V_446 -> V_544 - 1 ) |
( ( V_446 -> V_549 - 1 ) << 16 ) ) ;
F_11 ( F_198 ( V_99 ) ,
( V_446 -> V_550 - 1 ) |
( ( V_446 -> V_542 - 1 ) << 16 ) ) ;
F_11 ( F_200 ( V_99 ) ,
( V_446 -> V_551 - 1 ) |
( ( V_446 -> V_543 - 1 ) << 16 ) ) ;
F_11 ( F_202 ( V_99 ) ,
( V_446 -> V_552 - 1 ) |
( ( V_446 -> V_553 - 1 ) << 16 ) ) ;
if ( F_145 ( V_2 ) && V_99 == V_153 &&
( V_95 == V_150 || V_95 == V_318 ) )
F_11 ( F_198 ( V_95 ) , F_4 ( F_198 ( V_99 ) ) ) ;
F_11 ( F_295 ( V_95 ) ,
( ( V_357 -> V_424 - 1 ) << 16 ) | ( V_357 -> V_426 - 1 ) ) ;
}
static void F_296 ( struct V_97 * V_97 )
{
struct V_1 * V_2 = V_97 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_554 ;
V_554 = F_4 ( F_45 ( V_97 -> V_95 ) ) ;
if ( V_97 -> V_95 == 0 && F_43 ( V_2 ) -> V_103 < 4 ) {
if ( V_97 -> V_98 . V_447 . clock >
V_4 -> V_289 . V_555 ( V_2 ) * 9 / 10 )
V_554 |= V_556 ;
else
V_554 &= ~ V_556 ;
}
V_554 &= ~ ( V_218 | V_557 ) ;
if ( V_97 -> V_98 . V_516 ) {
if ( V_97 -> V_98 . V_558 ) {
V_554 |= V_559 |
V_557 |
V_560 ;
}
}
if ( F_22 ( V_2 ) && F_16 ( & V_97 -> V_210 ,
V_33 ) ) {
if ( V_97 -> V_98 . V_558 ) {
V_554 |= V_559 |
V_154 |
V_105 ;
}
}
if ( F_297 ( V_2 ) ) {
if ( V_97 -> V_490 ) {
F_40 ( L_92 ) ;
V_554 |= V_561 ;
} else {
F_40 ( L_93 ) ;
V_554 &= ~ V_561 ;
}
}
V_554 &= ~ V_220 ;
if ( ! F_23 ( V_2 ) &&
V_97 -> V_98 . V_446 . V_342 & V_541 )
V_554 |= V_562 ;
else
V_554 |= V_563 ;
if ( F_22 ( V_2 ) ) {
if ( V_97 -> V_98 . V_564 )
V_554 |= V_565 ;
else
V_554 &= ~ V_565 ;
}
F_11 ( F_45 ( V_97 -> V_95 ) , V_554 ) ;
F_14 ( F_45 ( V_97 -> V_95 ) ) ;
}
static int F_298 ( struct V_23 * V_24 ,
int V_248 , int V_249 ,
struct V_255 * V_256 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_445 * V_446 =
& V_97 -> V_98 . V_446 ;
struct V_445 * V_357 = & V_97 -> V_98 . V_447 ;
int V_95 = V_97 -> V_95 ;
int V_155 = V_97 -> V_155 ;
int V_25 , V_484 = 0 ;
T_3 clock , V_488 ;
T_1 V_260 ;
bool V_566 , V_567 = false , V_495 = false ;
bool V_568 = false , V_569 = false ;
struct V_62 * V_63 ;
const T_2 * V_26 ;
int V_238 ;
F_26 (dev, crtc, encoder) {
switch ( V_63 -> type ) {
case V_27 :
V_568 = true ;
break;
case V_41 :
case V_38 :
V_495 = true ;
if ( V_63 -> V_570 )
V_569 = true ;
break;
case V_533 :
V_569 = true ;
break;
}
V_484 ++ ;
}
V_25 = F_275 ( V_24 , V_484 ) ;
V_26 = F_19 ( V_24 , V_25 ) ;
V_566 = V_26 -> V_571 ( V_26 , V_24 , V_446 -> clock , V_25 , NULL ,
& clock ) ;
if ( ! V_566 ) {
F_10 ( L_94 ) ;
return - V_243 ;
}
F_217 ( V_24 , true ) ;
if ( V_568 && V_4 -> V_572 ) {
V_567 = V_26 -> V_571 ( V_26 , V_24 ,
V_4 -> V_573 ,
V_25 ,
& clock ,
& V_488 ) ;
}
if ( ! V_97 -> V_98 . V_487 ) {
V_97 -> V_98 . V_394 . V_59 = clock . V_59 ;
V_97 -> V_98 . V_394 . V_61 = clock . V_61 ;
V_97 -> V_98 . V_394 . V_54 = clock . V_54 ;
V_97 -> V_98 . V_394 . V_56 = clock . V_56 ;
V_97 -> V_98 . V_394 . V_57 = clock . V_57 ;
}
if ( V_495 && V_569 )
F_276 ( V_97 ) ;
if ( F_23 ( V_2 ) )
F_293 ( V_97 , V_446 ,
V_567 ? & V_488 : NULL ,
V_484 ) ;
else if ( F_22 ( V_2 ) )
F_283 ( V_97 ) ;
else
F_289 ( V_97 ,
V_567 ? & V_488 : NULL ,
V_484 ) ;
V_260 = V_574 ;
if ( ! F_22 ( V_2 ) ) {
if ( V_95 == 0 )
V_260 &= ~ V_159 ;
else
V_260 |= V_575 ;
}
F_40 ( L_95 , V_95 == 0 ? 'A' : 'B' ) ;
F_299 ( V_357 ) ;
F_294 ( V_97 , V_357 , V_446 ) ;
F_11 ( F_300 ( V_155 ) ,
( ( V_357 -> V_426 - 1 ) << 16 ) |
( V_357 -> V_424 - 1 ) ) ;
F_11 ( F_301 ( V_155 ) , 0 ) ;
F_296 ( V_97 ) ;
F_116 ( V_4 , V_95 , false ) ;
F_41 ( V_2 , V_95 ) ;
F_11 ( F_73 ( V_155 ) , V_260 ) ;
F_14 ( F_73 ( V_155 ) ) ;
V_238 = F_158 ( V_24 , V_248 , V_249 , V_256 ) ;
F_211 ( V_2 ) ;
return V_238 ;
}
static bool F_302 ( struct V_97 * V_24 ,
struct V_443 * V_444 )
{
struct V_1 * V_2 = V_24 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_197 ;
V_197 = F_4 ( F_45 ( V_24 -> V_95 ) ) ;
if ( ! ( V_197 & V_154 ) )
return false ;
return true ;
}
static void F_303 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_576 * V_577 = & V_2 -> V_577 ;
struct V_62 * V_63 ;
T_1 V_20 , V_578 ;
bool V_579 = false ;
bool V_580 = false ;
bool V_581 = false ;
bool V_582 = false ;
bool V_583 = false ;
bool V_584 = false ;
F_150 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_63 -> type ) {
case V_27 :
V_582 = true ;
V_579 = true ;
break;
case V_33 :
V_582 = true ;
if ( F_304 ( & V_63 -> V_210 ) )
V_581 = true ;
else
V_580 = true ;
break;
}
}
if ( F_52 ( V_2 ) ) {
V_583 = V_4 -> V_585 ;
V_584 = V_583 ;
} else {
V_583 = false ;
V_584 = true ;
}
F_40 ( L_96 ,
V_582 , V_579 , V_581 , V_580 ,
V_583 ) ;
V_20 = F_4 ( V_163 ) ;
V_578 = V_20 ;
V_578 &= ~ V_165 ;
if ( V_583 )
V_578 |= V_586 ;
else
V_578 |= V_587 ;
V_578 &= ~ V_164 ;
V_578 &= ~ V_588 ;
V_578 &= ~ V_589 ;
if ( V_582 ) {
V_578 |= V_590 ;
if ( F_273 ( V_4 ) && V_584 )
V_578 |= V_589 ;
if ( V_580 ) {
if ( F_273 ( V_4 ) && V_584 )
V_578 |= V_591 ;
else
V_578 |= V_592 ;
} else
V_578 |= V_593 ;
} else {
V_578 |= V_594 ;
V_578 |= V_593 ;
}
if ( V_578 == V_20 )
return;
V_20 &= ~ V_165 ;
if ( V_583 )
V_20 |= V_586 ;
else
V_20 |= V_587 ;
if ( V_582 ) {
V_20 &= ~ V_164 ;
V_20 |= V_590 ;
if ( F_273 ( V_4 ) && V_584 ) {
F_40 ( L_97 ) ;
V_20 |= V_589 ;
} else
V_20 &= ~ V_589 ;
F_11 ( V_163 , V_20 ) ;
F_14 ( V_163 ) ;
F_98 ( 200 ) ;
V_20 &= ~ V_588 ;
if ( V_580 ) {
if ( F_273 ( V_4 ) && V_584 ) {
F_40 ( L_98 ) ;
V_20 |= V_591 ;
}
else
V_20 |= V_592 ;
} else
V_20 |= V_593 ;
F_11 ( V_163 , V_20 ) ;
F_14 ( V_163 ) ;
F_98 ( 200 ) ;
} else {
F_40 ( L_99 ) ;
V_20 &= ~ V_588 ;
V_20 |= V_593 ;
F_11 ( V_163 , V_20 ) ;
F_14 ( V_163 ) ;
F_98 ( 200 ) ;
V_20 &= ~ V_164 ;
V_20 |= V_594 ;
V_20 &= ~ V_589 ;
F_11 ( V_163 , V_20 ) ;
F_14 ( V_163 ) ;
F_98 ( 200 ) ;
}
F_95 ( V_20 != V_578 ) ;
}
static void F_305 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_576 * V_577 = & V_2 -> V_577 ;
struct V_62 * V_63 ;
bool V_595 = false ;
bool V_596 = false ;
T_1 V_197 ;
F_150 (encoder, &mode_config->encoder_list, base.head) {
switch ( V_63 -> type ) {
case V_39 :
V_595 = true ;
break;
}
}
if ( ! V_595 )
return;
F_153 ( & V_4 -> V_11 ) ;
if ( F_145 ( V_2 ) && ( V_2 -> V_597 & 0xFF00 ) == 0x0C00 )
V_596 = true ;
V_197 = F_102 ( V_4 , V_598 , V_202 ) ;
V_197 &= ~ V_356 ;
V_197 |= V_599 ;
F_101 ( V_4 , V_598 , V_197 , V_202 ) ;
F_98 ( 24 ) ;
V_197 = F_102 ( V_4 , V_598 , V_202 ) ;
V_197 &= ~ V_599 ;
F_101 ( V_4 , V_598 , V_197 , V_202 ) ;
if ( ! V_596 ) {
V_197 = F_4 ( V_600 ) ;
V_197 |= V_601 ;
F_11 ( V_600 , V_197 ) ;
if ( F_9 ( F_4 ( V_600 ) &
V_602 , 100 ) )
F_10 ( L_100 ) ;
V_197 = F_4 ( V_600 ) ;
V_197 &= ~ V_601 ;
F_11 ( V_600 , V_197 ) ;
if ( F_9 ( ( F_4 ( V_600 ) &
V_602 ) == 0 ,
100 ) )
F_10 ( L_101 ) ;
}
V_197 = F_102 ( V_4 , 0x8008 , V_603 ) ;
V_197 &= ~ ( 0xFF << 24 ) ;
V_197 |= ( 0x12 << 24 ) ;
F_101 ( V_4 , 0x8008 , V_197 , V_603 ) ;
if ( V_596 ) {
V_197 = F_102 ( V_4 , 0x800C , V_603 ) ;
V_197 |= 0x7FFF ;
F_101 ( V_4 , 0x800C , V_197 , V_603 ) ;
}
V_197 = F_102 ( V_4 , 0x2008 , V_603 ) ;
V_197 |= ( 1 << 11 ) ;
F_101 ( V_4 , 0x2008 , V_197 , V_603 ) ;
V_197 = F_102 ( V_4 , 0x2108 , V_603 ) ;
V_197 |= ( 1 << 11 ) ;
F_101 ( V_4 , 0x2108 , V_197 , V_603 ) ;
if ( V_596 ) {
V_197 = F_102 ( V_4 , 0x2038 , V_603 ) ;
V_197 |= ( 0x3F << 24 ) | ( 0xF << 20 ) | ( 0xF << 16 ) ;
F_101 ( V_4 , 0x2038 , V_197 , V_603 ) ;
V_197 = F_102 ( V_4 , 0x2138 , V_603 ) ;
V_197 |= ( 0x3F << 24 ) | ( 0xF << 20 ) | ( 0xF << 16 ) ;
F_101 ( V_4 , 0x2138 , V_197 , V_603 ) ;
V_197 = F_102 ( V_4 , 0x203C , V_603 ) ;
V_197 |= ( 0x3F << 8 ) ;
F_101 ( V_4 , 0x203C , V_197 , V_603 ) ;
V_197 = F_102 ( V_4 , 0x213C , V_603 ) ;
V_197 |= ( 0x3F << 8 ) ;
F_101 ( V_4 , 0x213C , V_197 , V_603 ) ;
}
V_197 = F_102 ( V_4 , 0x206C , V_603 ) ;
V_197 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_101 ( V_4 , 0x206C , V_197 , V_603 ) ;
V_197 = F_102 ( V_4 , 0x216C , V_603 ) ;
V_197 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_101 ( V_4 , 0x216C , V_197 , V_603 ) ;
if ( ! V_596 ) {
V_197 = F_102 ( V_4 , 0x2080 , V_603 ) ;
V_197 &= ~ ( 7 << 13 ) ;
V_197 |= ( 5 << 13 ) ;
F_101 ( V_4 , 0x2080 , V_197 , V_603 ) ;
V_197 = F_102 ( V_4 , 0x2180 , V_603 ) ;
V_197 &= ~ ( 7 << 13 ) ;
V_197 |= ( 5 << 13 ) ;
F_101 ( V_4 , 0x2180 , V_197 , V_603 ) ;
}
V_197 = F_102 ( V_4 , 0x208C , V_603 ) ;
V_197 &= ~ 0xFF ;
V_197 |= 0x1C ;
F_101 ( V_4 , 0x208C , V_197 , V_603 ) ;
V_197 = F_102 ( V_4 , 0x218C , V_603 ) ;
V_197 &= ~ 0xFF ;
V_197 |= 0x1C ;
F_101 ( V_4 , 0x218C , V_197 , V_603 ) ;
V_197 = F_102 ( V_4 , 0x2098 , V_603 ) ;
V_197 &= ~ ( 0xFF << 16 ) ;
V_197 |= ( 0x1C << 16 ) ;
F_101 ( V_4 , 0x2098 , V_197 , V_603 ) ;
V_197 = F_102 ( V_4 , 0x2198 , V_603 ) ;
V_197 &= ~ ( 0xFF << 16 ) ;
V_197 |= ( 0x1C << 16 ) ;
F_101 ( V_4 , 0x2198 , V_197 , V_603 ) ;
if ( ! V_596 ) {
V_197 = F_102 ( V_4 , 0x20C4 , V_603 ) ;
V_197 |= ( 1 << 27 ) ;
F_101 ( V_4 , 0x20C4 , V_197 , V_603 ) ;
V_197 = F_102 ( V_4 , 0x21C4 , V_603 ) ;
V_197 |= ( 1 << 27 ) ;
F_101 ( V_4 , 0x21C4 , V_197 , V_603 ) ;
V_197 = F_102 ( V_4 , 0x20EC , V_603 ) ;
V_197 &= ~ ( 0xF << 28 ) ;
V_197 |= ( 4 << 28 ) ;
F_101 ( V_4 , 0x20EC , V_197 , V_603 ) ;
V_197 = F_102 ( V_4 , 0x21EC , V_603 ) ;
V_197 &= ~ ( 0xF << 28 ) ;
V_197 |= ( 4 << 28 ) ;
F_101 ( V_4 , 0x21EC , V_197 , V_603 ) ;
}
V_197 = F_102 ( V_4 , V_604 , V_202 ) ;
V_197 |= V_605 ;
F_101 ( V_4 , V_604 , V_197 , V_202 ) ;
F_154 ( & V_4 -> V_11 ) ;
}
void F_306 ( struct V_1 * V_2 )
{
if ( F_52 ( V_2 ) || F_59 ( V_2 ) )
F_303 ( V_2 ) ;
else if ( F_57 ( V_2 ) )
F_305 ( V_2 ) ;
}
static int F_307 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_62 * V_63 ;
struct V_62 * V_606 = NULL ;
int V_484 = 0 ;
bool V_568 = false ;
F_26 (dev, crtc, encoder) {
switch ( V_63 -> type ) {
case V_27 :
V_568 = true ;
break;
case V_33 :
V_606 = V_63 ;
break;
}
V_484 ++ ;
}
if ( V_568 && F_273 ( V_4 ) && V_484 < 2 ) {
F_40 ( L_90 ,
V_4 -> V_485 ) ;
return V_4 -> V_485 * 1000 ;
}
return 120000 ;
}
static void F_308 ( struct V_23 * V_24 ,
struct V_445 * V_446 ,
bool V_558 )
{
struct V_3 * V_4 = V_24 -> V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_5 V_20 ;
V_20 = F_4 ( F_45 ( V_95 ) ) ;
V_20 &= ~ V_218 ;
switch ( V_97 -> V_98 . V_451 ) {
case 18 :
V_20 |= V_559 ;
break;
case 24 :
V_20 |= V_607 ;
break;
case 30 :
V_20 |= V_608 ;
break;
case 36 :
V_20 |= V_609 ;
break;
default:
F_130 () ;
}
V_20 &= ~ ( V_557 | V_610 ) ;
if ( V_558 )
V_20 |= ( V_557 | V_560 ) ;
V_20 &= ~ V_220 ;
if ( V_446 -> V_342 & V_541 )
V_20 |= V_221 ;
else
V_20 |= V_563 ;
if ( V_97 -> V_98 . V_564 )
V_20 |= V_565 ;
else
V_20 &= ~ V_565 ;
F_11 ( F_45 ( V_95 ) , V_20 ) ;
F_14 ( F_45 ( V_95 ) ) ;
}
static void F_309 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_6 V_611 = 0x7800 ;
if ( V_97 -> V_98 . V_564 )
V_611 = ( ( 235 - 16 ) * ( 1 << 12 ) / 255 ) & 0xff8 ;
F_11 ( F_310 ( V_95 ) , V_611 << 16 ) ;
F_11 ( F_311 ( V_95 ) , 0 ) ;
F_11 ( F_312 ( V_95 ) , V_611 ) ;
F_11 ( F_313 ( V_95 ) , 0 ) ;
F_11 ( F_314 ( V_95 ) , 0 ) ;
F_11 ( F_315 ( V_95 ) , V_611 << 16 ) ;
F_11 ( F_316 ( V_95 ) , 0 ) ;
F_11 ( F_317 ( V_95 ) , 0 ) ;
F_11 ( F_318 ( V_95 ) , 0 ) ;
if ( F_43 ( V_2 ) -> V_103 > 6 ) {
T_6 V_612 = 0 ;
if ( V_97 -> V_98 . V_564 )
V_612 = ( 16 * ( 1 << 13 ) / 255 ) & 0x1fff ;
F_11 ( F_319 ( V_95 ) , V_612 ) ;
F_11 ( F_320 ( V_95 ) , V_612 ) ;
F_11 ( F_321 ( V_95 ) , V_612 ) ;
F_11 ( F_322 ( V_95 ) , 0 ) ;
} else {
T_5 V_357 = V_613 ;
if ( V_97 -> V_98 . V_564 )
V_357 |= V_614 ;
F_11 ( F_322 ( V_95 ) , V_357 ) ;
}
}
static void F_323 ( struct V_23 * V_24 ,
struct V_445 * V_446 ,
bool V_558 )
{
struct V_3 * V_4 = V_24 -> V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
enum V_94 V_99 = V_97 -> V_98 . V_99 ;
T_5 V_20 ;
V_20 = F_4 ( F_45 ( V_99 ) ) ;
V_20 &= ~ ( V_557 | V_610 ) ;
if ( V_558 )
V_20 |= ( V_557 | V_560 ) ;
V_20 &= ~ V_228 ;
if ( V_446 -> V_342 & V_541 )
V_20 |= V_221 ;
else
V_20 |= V_563 ;
F_11 ( F_45 ( V_99 ) , V_20 ) ;
F_14 ( F_45 ( V_99 ) ) ;
}
static bool F_324 ( struct V_23 * V_24 ,
struct V_445 * V_446 ,
T_3 * clock ,
bool * V_567 ,
T_3 * V_488 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_62 * V_62 ;
int V_25 ;
const T_2 * V_26 ;
bool V_238 , V_495 = false , V_569 = false , V_568 = false ;
F_26 (dev, crtc, intel_encoder) {
switch ( V_62 -> type ) {
case V_27 :
V_568 = true ;
break;
case V_41 :
case V_38 :
V_495 = true ;
if ( V_62 -> V_570 )
V_569 = true ;
break;
case V_533 :
V_569 = true ;
break;
}
}
V_25 = F_307 ( V_24 ) ;
V_26 = F_19 ( V_24 , V_25 ) ;
V_238 = V_26 -> V_571 ( V_26 , V_24 , V_446 -> clock , V_25 , NULL ,
clock ) ;
if ( ! V_238 )
return false ;
if ( V_568 && V_4 -> V_572 ) {
* V_567 = V_26 -> V_571 ( V_26 , V_24 ,
V_4 -> V_573 ,
V_25 ,
clock ,
V_488 ) ;
}
if ( V_495 && V_569 )
F_276 ( F_35 ( V_24 ) ) ;
return true ;
}
static void F_325 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_307 ;
V_307 = F_4 ( V_319 ) ;
if ( V_307 & V_320 )
return;
F_2 ( F_4 ( F_65 ( V_150 ) ) & V_137 ) ;
F_2 ( F_4 ( F_65 ( V_318 ) ) & V_137 ) ;
V_307 |= V_320 ;
F_40 ( L_102 ) ;
F_11 ( V_319 , V_307 ) ;
F_14 ( V_319 ) ;
}
static bool F_326 ( struct V_97 * V_97 )
{
struct V_1 * V_2 = V_97 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_316 =
F_35 ( V_4 -> V_96 [ V_150 ] ) ;
F_40 ( L_103 ,
V_97 -> V_95 , V_97 -> V_324 ) ;
if ( V_97 -> V_324 > 4 ) {
F_40 ( L_104 ,
V_97 -> V_95 , V_97 -> V_324 ) ;
V_97 -> V_324 = 4 ;
return false ;
}
if ( F_43 ( V_2 ) -> V_305 == 2 )
return true ;
switch ( V_97 -> V_95 ) {
case V_143 :
return true ;
case V_150 :
if ( V_4 -> V_96 [ V_318 ] -> V_125 &&
V_97 -> V_324 > 2 ) {
F_40 ( L_105 ,
V_97 -> V_95 , V_97 -> V_324 ) ;
V_97 -> V_324 = 2 ;
return false ;
}
if ( V_97 -> V_324 > 2 )
F_2 ( F_4 ( V_319 ) & V_320 ) ;
else
F_325 ( V_2 ) ;
return true ;
case V_318 :
if ( ! V_316 -> V_210 . V_125 || V_316 -> V_324 <= 2 ) {
if ( V_97 -> V_324 > 2 ) {
F_40 ( L_105 ,
V_97 -> V_95 , V_97 -> V_324 ) ;
V_97 -> V_324 = 2 ;
return false ;
}
} else {
F_40 ( L_106 ) ;
return false ;
}
F_325 ( V_2 ) ;
return true ;
default:
F_130 () ;
}
}
int F_327 ( int V_615 , int V_616 , int V_617 )
{
T_1 V_618 = V_615 * V_617 * 21 / 20 ;
return V_618 / ( V_616 * 8 ) + 1 ;
}
void F_281 ( struct V_97 * V_24 ,
struct V_474 * V_475 )
{
struct V_1 * V_2 = V_24 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_95 = V_24 -> V_95 ;
F_11 ( F_328 ( V_95 ) , F_329 ( V_475 -> V_476 ) | V_475 -> V_477 ) ;
F_11 ( F_330 ( V_95 ) , V_475 -> V_478 ) ;
F_11 ( F_331 ( V_95 ) , V_475 -> V_479 ) ;
F_11 ( F_332 ( V_95 ) , V_475 -> V_480 ) ;
}
void F_282 ( struct V_97 * V_24 ,
struct V_474 * V_475 )
{
struct V_1 * V_2 = V_24 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_95 = V_24 -> V_95 ;
enum V_94 V_94 = V_24 -> V_98 . V_99 ;
if ( F_43 ( V_2 ) -> V_103 >= 5 ) {
F_11 ( F_190 ( V_94 ) , F_329 ( V_475 -> V_476 ) | V_475 -> V_477 ) ;
F_11 ( F_333 ( V_94 ) , V_475 -> V_478 ) ;
F_11 ( F_334 ( V_94 ) , V_475 -> V_479 ) ;
F_11 ( F_335 ( V_94 ) , V_475 -> V_480 ) ;
} else {
F_11 ( F_336 ( V_95 ) , F_329 ( V_475 -> V_476 ) | V_475 -> V_477 ) ;
F_11 ( F_337 ( V_95 ) , V_475 -> V_478 ) ;
F_11 ( F_338 ( V_95 ) , V_475 -> V_479 ) ;
F_11 ( F_339 ( V_95 ) , V_475 -> V_480 ) ;
}
}
static void F_340 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_445 * V_446 =
& V_97 -> V_98 . V_446 ;
struct V_474 V_475 = { 0 } ;
int V_615 , V_619 , V_616 ;
V_616 = F_5 ( V_2 ) * F_341 ( 100 ) / F_342 ( 1 ) / 10 ;
if ( V_97 -> V_98 . V_620 )
V_615 = V_97 -> V_98 . V_620 ;
else
V_615 = V_446 -> clock ;
V_619 = F_327 ( V_615 , V_616 ,
V_97 -> V_98 . V_451 ) ;
V_97 -> V_324 = V_619 ;
if ( V_97 -> V_98 . V_517 > 1 )
V_616 *= V_97 -> V_98 . V_517 ;
F_272 ( V_97 -> V_98 . V_451 , V_619 , V_615 ,
V_616 , & V_475 ) ;
F_282 ( V_97 , & V_475 ) ;
}
static T_5 F_343 ( struct V_97 * V_97 ,
T_3 * clock , T_1 * V_395 ,
T_3 * V_488 , T_1 * V_489 )
{
struct V_23 * V_24 = & V_97 -> V_210 ;
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_62 * V_62 ;
T_5 V_394 ;
int V_621 , V_484 = 0 ;
bool V_568 = false , V_495 = false , V_569 = false ;
F_26 (dev, crtc, intel_encoder) {
switch ( V_62 -> type ) {
case V_27 :
V_568 = true ;
break;
case V_41 :
case V_38 :
V_495 = true ;
if ( V_62 -> V_570 )
V_569 = true ;
break;
case V_533 :
V_569 = true ;
break;
}
V_484 ++ ;
}
V_621 = 21 ;
if ( V_568 ) {
if ( ( F_273 ( V_4 ) &&
V_4 -> V_485 == 100 ) ||
( F_52 ( V_2 ) && F_17 ( V_2 ) ) )
V_621 = 25 ;
} else if ( V_495 && V_569 )
V_621 = 20 ;
if ( clock -> V_53 < V_621 * clock -> V_59 )
* V_395 |= V_622 ;
if ( V_489 && ( V_488 -> V_53 < V_621 * V_488 -> V_59 ) )
* V_489 |= V_622 ;
V_394 = 0 ;
if ( V_568 )
V_394 |= V_521 ;
else
V_394 |= V_522 ;
if ( V_495 ) {
if ( V_97 -> V_98 . V_517 > 1 ) {
V_394 |= ( V_97 -> V_98 . V_517 - 1 )
<< V_623 ;
}
V_394 |= V_524 ;
}
if ( V_97 -> V_98 . V_516 &&
V_97 -> V_98 . V_401 )
V_394 |= V_524 ;
V_394 |= ( 1 << ( clock -> V_56 - 1 ) ) << V_526 ;
V_394 |= ( 1 << ( clock -> V_56 - 1 ) ) << V_527 ;
switch ( clock -> V_57 ) {
case 5 :
V_394 |= V_528 ;
break;
case 7 :
V_394 |= V_529 ;
break;
case 10 :
V_394 |= V_530 ;
break;
case 14 :
V_394 |= V_531 ;
break;
}
if ( V_495 && V_569 )
V_394 |= V_534 ;
else if ( V_569 )
V_394 |= 3 ;
else if ( V_568 && F_273 ( V_4 ) && V_484 < 2 )
V_394 |= V_535 ;
else
V_394 |= V_536 ;
return V_394 ;
}
static int F_344 ( struct V_23 * V_24 ,
int V_248 , int V_249 ,
struct V_255 * V_256 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_445 * V_446 =
& V_97 -> V_98 . V_446 ;
struct V_445 * V_357 = & V_97 -> V_98 . V_447 ;
int V_95 = V_97 -> V_95 ;
int V_155 = V_97 -> V_155 ;
int V_484 = 0 ;
T_3 clock , V_488 ;
T_1 V_394 , V_395 = 0 , V_489 = 0 ;
bool V_566 , V_567 = false ;
bool V_568 = false ;
struct V_62 * V_63 ;
int V_238 ;
bool V_558 , V_624 ;
F_26 (dev, crtc, encoder) {
switch ( V_63 -> type ) {
case V_27 :
V_568 = true ;
break;
}
V_484 ++ ;
}
F_46 ( ! ( F_52 ( V_2 ) || F_59 ( V_2 ) ) ,
L_107 , F_345 ( V_2 ) ) ;
V_97 -> V_98 . V_99 = V_95 ;
V_566 = F_324 ( V_24 , V_446 , & clock ,
& V_567 , & V_488 ) ;
if ( ! V_566 ) {
F_10 ( L_94 ) ;
return - V_243 ;
}
if ( ! V_97 -> V_98 . V_487 ) {
V_97 -> V_98 . V_394 . V_59 = clock . V_59 ;
V_97 -> V_98 . V_394 . V_61 = clock . V_61 ;
V_97 -> V_98 . V_394 . V_54 = clock . V_54 ;
V_97 -> V_98 . V_394 . V_56 = clock . V_56 ;
V_97 -> V_98 . V_394 . V_57 = clock . V_57 ;
}
F_217 ( V_24 , true ) ;
V_558 = V_97 -> V_98 . V_558 ;
if ( V_568 && V_4 -> V_625 )
V_558 = true ;
V_395 = clock . V_59 << 16 | clock . V_61 << 8 | clock . V_54 ;
if ( V_567 )
V_489 = V_488 . V_59 << 16 | V_488 . V_61 << 8 |
V_488 . V_54 ;
V_394 = F_343 ( V_97 , & clock , & V_395 , & V_488 ,
V_567 ? & V_489 : NULL ) ;
F_40 ( L_108 , V_95 ) ;
F_299 ( V_357 ) ;
if ( V_97 -> V_98 . V_401 ) {
struct V_129 * V_130 ;
V_130 = F_208 ( V_97 , V_394 , V_395 ) ;
if ( V_130 == NULL ) {
F_58 ( L_109 ,
V_95 ) ;
return - V_243 ;
}
} else
F_207 ( V_97 ) ;
if ( V_97 -> V_98 . V_516 )
F_280 ( V_97 ) ;
F_26 (dev, crtc, encoder)
if ( V_63 -> V_537 )
V_63 -> V_537 ( V_63 ) ;
if ( V_97 -> V_211 ) {
F_11 ( V_97 -> V_211 -> V_131 , V_394 ) ;
F_14 ( V_97 -> V_211 -> V_131 ) ;
F_98 ( 150 ) ;
F_11 ( V_97 -> V_211 -> V_131 , V_394 ) ;
}
V_97 -> V_490 = false ;
if ( V_97 -> V_211 ) {
if ( V_568 && V_567 && V_491 ) {
F_11 ( V_97 -> V_211 -> V_626 , V_489 ) ;
V_97 -> V_490 = true ;
} else {
F_11 ( V_97 -> V_211 -> V_626 , V_395 ) ;
}
}
F_294 ( V_97 , V_357 , V_446 ) ;
V_97 -> V_324 = 0 ;
if ( V_97 -> V_98 . V_401 )
F_340 ( V_24 ) ;
V_624 = F_326 ( V_97 ) ;
F_308 ( V_24 , V_446 , V_558 ) ;
F_41 ( V_2 , V_95 ) ;
F_11 ( F_73 ( V_155 ) , V_574 ) ;
F_14 ( F_73 ( V_155 ) ) ;
V_238 = F_158 ( V_24 , V_248 , V_249 , V_256 ) ;
F_211 ( V_2 ) ;
F_346 ( V_2 , V_95 , V_446 ) ;
return V_624 ? V_238 : - V_243 ;
}
static bool F_347 ( struct V_97 * V_24 ,
struct V_443 * V_444 )
{
struct V_1 * V_2 = V_24 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_197 ;
V_197 = F_4 ( F_45 ( V_24 -> V_95 ) ) ;
if ( ! ( V_197 & V_154 ) )
return false ;
if ( F_4 ( F_80 ( V_24 -> V_95 ) ) & V_167 )
V_444 -> V_401 = true ;
return true ;
}
static void F_348 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_407 = false ;
struct V_97 * V_24 ;
struct V_62 * V_63 ;
F_150 (crtc, &dev->mode_config.crtc_list, base.head) {
if ( V_24 -> V_95 != V_143 && V_24 -> V_210 . V_125 )
V_407 = true ;
}
F_150 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_63 -> type != V_33 &&
V_63 -> V_429 )
V_407 = true ;
}
if ( V_4 -> V_403 )
V_407 = true ;
F_349 ( V_2 , V_407 ) ;
}
static int F_350 ( struct V_23 * V_24 ,
int V_248 , int V_249 ,
struct V_255 * V_256 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_445 * V_446 =
& V_97 -> V_98 . V_446 ;
struct V_445 * V_357 = & V_97 -> V_98 . V_447 ;
int V_95 = V_97 -> V_95 ;
int V_155 = V_97 -> V_155 ;
int V_484 = 0 ;
bool V_627 = false ;
struct V_62 * V_63 ;
int V_238 ;
bool V_558 ;
F_26 (dev, crtc, encoder) {
switch ( V_63 -> type ) {
case V_33 :
if ( ! F_304 ( & V_63 -> V_210 ) )
V_627 = true ;
break;
}
V_484 ++ ;
}
if ( V_627 )
V_97 -> V_98 . V_99 = V_153 ;
else
V_97 -> V_98 . V_99 = V_95 ;
F_46 ( ! F_57 ( V_2 ) , L_107 ,
F_345 ( V_2 ) ) ;
F_46 ( V_484 != 1 , L_110 ,
V_484 , F_69 ( V_95 ) ) ;
F_2 ( F_4 ( F_45 ( V_97 -> V_98 . V_99 ) ) &
( V_154 | V_105 ) ) ;
F_2 ( F_4 ( F_73 ( V_155 ) ) & V_156 ) ;
if ( ! F_351 ( V_24 , V_446 -> clock ) )
return - V_243 ;
F_217 ( V_24 , true ) ;
V_558 = V_97 -> V_98 . V_558 ;
F_40 ( L_108 , V_95 ) ;
F_299 ( V_357 ) ;
if ( V_97 -> V_98 . V_516 )
F_280 ( V_97 ) ;
V_97 -> V_490 = false ;
F_294 ( V_97 , V_357 , V_446 ) ;
if ( V_97 -> V_98 . V_401 )
F_340 ( V_24 ) ;
F_323 ( V_24 , V_446 , V_558 ) ;
F_309 ( V_24 ) ;
F_11 ( F_73 ( V_155 ) , V_574 | V_628 ) ;
F_14 ( F_73 ( V_155 ) ) ;
V_238 = F_158 ( V_24 , V_248 , V_249 , V_256 ) ;
F_211 ( V_2 ) ;
F_346 ( V_2 , V_95 , V_446 ) ;
return V_238 ;
}
static bool F_352 ( struct V_97 * V_24 ,
struct V_443 * V_444 )
{
struct V_1 * V_2 = V_24 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_197 ;
V_197 = F_4 ( F_45 ( V_24 -> V_98 . V_99 ) ) ;
if ( ! ( V_197 & V_154 ) )
return false ;
V_197 = F_4 ( F_62 ( V_24 -> V_95 ) ) ;
if ( ( V_197 & V_629 ) == F_353 ( V_630 ) &&
F_4 ( F_80 ( V_143 ) ) & V_167 )
V_444 -> V_401 = true ;
return true ;
}
static int F_354 ( struct V_23 * V_24 ,
int V_248 , int V_249 ,
struct V_255 * V_256 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_631 * V_632 ;
struct V_62 * V_63 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_445 * V_446 =
& V_97 -> V_98 . V_446 ;
struct V_445 * V_357 = & V_97 -> V_98 . V_447 ;
int V_95 = V_97 -> V_95 ;
int V_238 ;
F_355 ( V_2 , V_95 ) ;
V_238 = V_4 -> V_289 . V_633 ( V_24 , V_248 , V_249 , V_256 ) ;
F_356 ( V_2 , V_95 ) ;
if ( V_238 != 0 )
return V_238 ;
F_26 (dev, crtc, encoder) {
F_40 ( L_111 ,
V_63 -> V_210 . V_210 . V_215 ,
F_357 ( & V_63 -> V_210 ) ,
V_357 -> V_210 . V_215 , V_357 -> V_634 ) ;
if ( V_63 -> V_635 ) {
V_63 -> V_635 ( V_63 ) ;
} else {
V_632 = V_63 -> V_210 . V_636 ;
V_632 -> V_635 ( & V_63 -> V_210 , V_357 , V_446 ) ;
}
}
return 0 ;
}
static bool F_358 ( struct V_432 * V_433 ,
int V_637 , T_5 V_638 ,
int V_639 , T_5 V_640 ,
int V_641 )
{
struct V_3 * V_4 = V_433 -> V_2 -> V_5 ;
T_7 * V_642 = V_433 -> V_642 ;
T_5 V_157 ;
V_157 = F_4 ( V_637 ) ;
V_157 &= V_638 ;
if ( ! V_642 [ 0 ] )
return ! V_157 ;
if ( ! V_157 )
return false ;
V_157 = F_4 ( V_639 ) ;
V_157 &= ~ V_640 ;
F_11 ( V_639 , V_157 ) ;
for ( V_157 = 0 ; V_157 < V_642 [ 2 ] ; V_157 ++ )
if ( F_4 ( V_641 ) != * ( ( T_5 * ) V_642 + V_157 ) )
return false ;
return true ;
}
static void F_359 ( struct V_432 * V_433 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = V_433 -> V_2 -> V_5 ;
T_7 * V_642 = V_433 -> V_642 ;
T_5 V_643 ;
T_5 V_644 ;
T_5 V_157 ;
V_157 = F_4 ( V_645 ) ;
if ( V_157 == V_646 || V_157 == V_647 )
V_643 = V_648 ;
else
V_643 = V_649 ;
if ( F_358 ( V_433 ,
V_650 , V_643 ,
V_650 , V_651 ,
V_652 ) )
return;
V_157 = F_4 ( V_650 ) ;
V_157 &= ~ ( V_643 | V_651 ) ;
V_644 = ( V_157 >> 9 ) & 0x1f ;
F_11 ( V_650 , V_157 ) ;
if ( ! V_642 [ 0 ] )
return;
V_644 = F_270 ( T_7 , V_642 [ 2 ] , V_644 ) ;
F_58 ( L_112 , V_644 ) ;
for ( V_157 = 0 ; V_157 < V_644 ; V_157 ++ )
F_11 ( V_652 , * ( ( T_5 * ) V_642 + V_157 ) ) ;
V_157 = F_4 ( V_650 ) ;
V_157 |= V_643 ;
F_11 ( V_650 , V_157 ) ;
}
static void F_360 ( struct V_432 * V_433 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = V_433 -> V_2 -> V_5 ;
T_7 * V_642 = V_433 -> V_642 ;
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
T_5 V_643 ;
T_5 V_157 ;
int V_644 ;
int V_95 = F_35 ( V_24 ) -> V_95 ;
int V_197 ;
int V_653 = F_361 ( V_95 ) ;
int V_654 = F_362 ( V_95 ) ;
int V_655 = F_363 ( V_95 ) ;
int V_656 = V_657 ;
F_58 ( L_113 ) ;
F_58 ( L_114 ) ;
V_197 = F_4 ( V_656 ) ;
V_197 |= ( V_658 << ( V_95 * 4 ) ) ;
F_11 ( V_656 , V_197 ) ;
F_41 ( V_2 , V_95 ) ;
V_197 = F_4 ( V_656 ) ;
F_58 ( L_115 , V_197 ) ;
V_197 |= ( V_659 << ( V_95 * 4 ) ) ;
F_11 ( V_656 , V_197 ) ;
V_197 = F_4 ( V_656 ) ;
F_58 ( L_116 , V_197 ) ;
V_197 = F_4 ( V_655 ) ;
F_58 ( L_117 , V_197 ) ;
V_197 &= ~ ( V_660 | V_661 ) ;
F_11 ( V_655 , V_197 ) ;
F_58 ( L_118 , F_69 ( V_95 ) ) ;
V_643 = V_659 << ( V_95 * 4 ) ;
V_97 -> V_434 = true ;
if ( F_16 ( V_24 , V_32 ) ) {
F_58 ( L_119 ) ;
V_642 [ 5 ] |= ( 1 << 2 ) ;
F_11 ( V_655 , V_660 ) ;
} else
F_11 ( V_655 , 0 ) ;
if ( F_358 ( V_433 ,
V_656 , V_643 ,
V_654 , V_662 ,
V_653 ) )
return;
V_157 = F_4 ( V_656 ) ;
V_157 &= ~ V_643 ;
F_11 ( V_656 , V_157 ) ;
if ( ! V_642 [ 0 ] )
return;
V_157 = F_4 ( V_654 ) ;
V_157 &= ~ V_662 ;
F_11 ( V_654 , V_157 ) ;
V_157 = ( V_157 >> 29 ) & V_663 ;
F_58 ( L_120 , V_157 ) ;
V_644 = F_270 ( T_7 , V_642 [ 2 ] , 21 ) ;
F_58 ( L_112 , V_644 ) ;
for ( V_157 = 0 ; V_157 < V_644 ; V_157 ++ )
F_11 ( V_653 , * ( ( T_5 * ) V_642 + V_157 ) ) ;
V_157 = F_4 ( V_656 ) ;
V_157 |= V_643 ;
F_11 ( V_656 , V_157 ) ;
}
static void F_364 ( struct V_432 * V_433 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = V_433 -> V_2 -> V_5 ;
T_7 * V_642 = V_433 -> V_642 ;
T_5 V_643 ;
T_5 V_157 ;
int V_644 ;
int V_653 ;
int V_655 ;
int V_654 ;
int V_656 ;
int V_95 = F_35 ( V_24 ) -> V_95 ;
if ( F_52 ( V_433 -> V_2 ) ) {
V_653 = F_365 ( V_95 ) ;
V_655 = F_366 ( V_95 ) ;
V_654 = F_367 ( V_95 ) ;
V_656 = V_664 ;
} else {
V_653 = F_368 ( V_95 ) ;
V_655 = F_369 ( V_95 ) ;
V_654 = F_370 ( V_95 ) ;
V_656 = V_665 ;
}
F_58 ( L_118 , F_69 ( V_95 ) ) ;
V_157 = F_4 ( V_654 ) ;
V_157 = ( V_157 >> 29 ) & V_663 ;
if ( ! V_157 ) {
F_58 ( L_121 ) ;
V_643 = V_666 ;
V_643 |= V_666 << 4 ;
V_643 |= V_666 << 8 ;
} else {
F_58 ( L_122 , 'A' + V_157 ) ;
V_643 = V_666 << ( ( V_157 - 1 ) * 4 ) ;
}
if ( F_16 ( V_24 , V_32 ) ) {
F_58 ( L_119 ) ;
V_642 [ 5 ] |= ( 1 << 2 ) ;
F_11 ( V_655 , V_660 ) ;
} else
F_11 ( V_655 , 0 ) ;
if ( F_358 ( V_433 ,
V_656 , V_643 ,
V_654 , V_662 ,
V_653 ) )
return;
V_157 = F_4 ( V_656 ) ;
V_157 &= ~ V_643 ;
F_11 ( V_656 , V_157 ) ;
if ( ! V_642 [ 0 ] )
return;
V_157 = F_4 ( V_654 ) ;
V_157 &= ~ V_662 ;
F_11 ( V_654 , V_157 ) ;
V_644 = F_270 ( T_7 , V_642 [ 2 ] , 21 ) ;
F_58 ( L_112 , V_644 ) ;
for ( V_157 = 0 ; V_157 < V_644 ; V_157 ++ )
F_11 ( V_653 , * ( ( T_5 * ) V_642 + V_157 ) ) ;
V_157 = F_4 ( V_656 ) ;
V_157 |= V_643 ;
F_11 ( V_656 , V_157 ) ;
}
void F_371 ( struct V_438 * V_63 ,
struct V_445 * V_357 )
{
struct V_23 * V_24 = V_63 -> V_24 ;
struct V_432 * V_433 ;
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_433 = F_372 ( V_63 , V_357 ) ;
if ( ! V_433 )
return;
F_58 ( L_123 ,
V_433 -> V_210 . V_215 ,
F_252 ( V_433 ) ,
V_433 -> V_63 -> V_210 . V_215 ,
F_357 ( V_433 -> V_63 ) ) ;
V_433 -> V_642 [ 6 ] = F_373 ( V_433 , V_357 ) / 2 ;
if ( V_4 -> V_289 . V_667 )
V_4 -> V_289 . V_667 ( V_433 , V_24 ) ;
}
void F_216 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_668 = F_374 ( V_97 -> V_95 ) ;
int V_157 ;
if ( ! V_24 -> V_125 || ! V_97 -> V_213 )
return;
if ( F_3 ( V_2 ) )
V_668 = F_375 ( V_97 -> V_95 ) ;
for ( V_157 = 0 ; V_157 < 256 ; V_157 ++ ) {
F_11 ( V_668 + 4 * V_157 ,
( V_97 -> V_669 [ V_157 ] << 16 ) |
( V_97 -> V_670 [ V_157 ] << 8 ) |
V_97 -> V_671 [ V_157 ] ) ;
}
}
static void F_376 ( struct V_23 * V_24 , T_1 V_210 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
bool V_672 = V_210 != 0 ;
T_1 V_413 ;
if ( V_97 -> V_673 == V_672 )
return;
V_413 = F_4 ( V_674 ) ;
if ( V_672 ) {
F_11 ( V_675 , V_210 ) ;
V_413 &= ~ ( V_676 ) ;
V_413 |= V_677 |
V_678 |
V_679 ;
} else
V_413 &= ~ ( V_677 | V_678 ) ;
F_11 ( V_674 , V_413 ) ;
V_97 -> V_673 = V_672 ;
}
static void F_377 ( struct V_23 * V_24 , T_1 V_210 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
bool V_672 = V_210 != 0 ;
if ( V_97 -> V_673 != V_672 ) {
T_5 V_413 = F_4 ( F_235 ( V_95 ) ) ;
if ( V_210 ) {
V_413 &= ~ ( V_414 | V_680 ) ;
V_413 |= V_418 | V_681 ;
V_413 |= V_95 << 28 ;
} else {
V_413 &= ~ ( V_414 | V_681 ) ;
V_413 |= V_682 ;
}
F_11 ( F_235 ( V_95 ) , V_413 ) ;
V_97 -> V_673 = V_672 ;
}
F_11 ( F_236 ( V_95 ) , V_210 ) ;
}
static void F_378 ( struct V_23 * V_24 , T_1 V_210 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
bool V_672 = V_210 != 0 ;
if ( V_97 -> V_673 != V_672 ) {
T_5 V_413 = F_4 ( F_379 ( V_95 ) ) ;
if ( V_210 ) {
V_413 &= ~ V_414 ;
V_413 |= V_418 | V_681 ;
} else {
V_413 &= ~ ( V_414 | V_681 ) ;
V_413 |= V_682 ;
}
if ( F_145 ( V_2 ) )
V_413 |= V_683 ;
F_11 ( F_379 ( V_95 ) , V_413 ) ;
V_97 -> V_673 = V_672 ;
}
F_11 ( F_380 ( V_95 ) , V_210 ) ;
}
static void F_217 ( struct V_23 * V_24 ,
bool V_214 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
int V_248 = V_97 -> V_684 ;
int V_249 = V_97 -> V_685 ;
T_1 V_210 , V_686 ;
bool V_672 ;
V_686 = 0 ;
if ( V_214 && V_24 -> V_125 && V_24 -> V_256 ) {
V_210 = V_97 -> V_687 ;
if ( V_248 > ( int ) V_24 -> V_256 -> V_688 )
V_210 = 0 ;
if ( V_249 > ( int ) V_24 -> V_256 -> V_689 )
V_210 = 0 ;
} else
V_210 = 0 ;
if ( V_248 < 0 ) {
if ( V_248 + V_97 -> V_690 < 0 )
V_210 = 0 ;
V_686 |= V_691 << V_692 ;
V_248 = - V_248 ;
}
V_686 |= V_248 << V_692 ;
if ( V_249 < 0 ) {
if ( V_249 + V_97 -> V_693 < 0 )
V_210 = 0 ;
V_686 |= V_691 << V_694 ;
V_249 = - V_249 ;
}
V_686 |= V_249 << V_694 ;
V_672 = V_210 != 0 ;
if ( ! V_672 && ! V_97 -> V_673 )
return;
if ( F_161 ( V_2 ) || F_145 ( V_2 ) ) {
F_11 ( F_381 ( V_95 ) , V_686 ) ;
F_378 ( V_24 , V_210 ) ;
} else {
F_11 ( F_382 ( V_95 ) , V_686 ) ;
if ( F_383 ( V_2 ) || F_384 ( V_2 ) )
F_376 ( V_24 , V_210 ) ;
else
F_377 ( V_24 , V_210 ) ;
}
}
static int F_385 ( struct V_23 * V_24 ,
struct V_695 * V_696 ,
T_5 V_697 ,
T_5 V_688 , T_5 V_689 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_233 * V_234 ;
T_5 V_698 ;
int V_238 ;
if ( ! V_697 ) {
F_40 ( L_124 ) ;
V_698 = 0 ;
V_234 = NULL ;
F_153 ( & V_2 -> V_306 ) ;
goto V_699;
}
if ( V_688 != 64 || V_689 != 64 ) {
F_10 ( L_125 ) ;
return - V_243 ;
}
V_234 = F_386 ( F_387 ( V_2 , V_696 , V_697 ) ) ;
if ( & V_234 -> V_210 == NULL )
return - V_700 ;
if ( V_234 -> V_210 . V_701 < V_688 * V_689 * 4 ) {
F_10 ( L_126 ) ;
V_238 = - V_702 ;
goto V_703;
}
F_153 ( & V_2 -> V_306 ) ;
if ( ! V_4 -> V_138 -> V_704 ) {
unsigned V_237 ;
if ( V_234 -> V_239 ) {
F_10 ( L_127 ) ;
V_238 = - V_243 ;
goto V_705;
}
V_237 = 0 ;
if ( F_125 ( V_2 ) )
V_237 = 64 * 1024 ;
V_238 = F_131 ( V_234 , V_237 , NULL ) ;
if ( V_238 ) {
F_10 ( L_128 ) ;
goto V_705;
}
V_238 = F_388 ( V_234 ) ;
if ( V_238 ) {
F_10 ( L_129 ) ;
goto V_706;
}
V_698 = V_234 -> V_286 ;
} else {
int V_707 = F_97 ( V_2 ) ? 16 * 1024 : 256 ;
V_238 = F_389 ( V_2 , V_234 ,
( V_97 -> V_95 == 0 ) ? V_708 : V_709 ,
V_707 ) ;
if ( V_238 ) {
F_10 ( L_130 ) ;
goto V_705;
}
V_698 = V_234 -> V_710 -> V_697 -> V_711 ;
}
if ( F_23 ( V_2 ) )
F_11 ( V_712 , ( V_689 << 12 ) | V_688 ) ;
V_699:
if ( V_97 -> V_713 ) {
if ( V_4 -> V_138 -> V_704 ) {
if ( V_97 -> V_713 != V_234 )
F_390 ( V_2 , V_97 -> V_713 ) ;
} else
F_134 ( V_97 -> V_713 ) ;
F_391 ( & V_97 -> V_713 -> V_210 ) ;
}
F_154 ( & V_2 -> V_306 ) ;
V_97 -> V_687 = V_698 ;
V_97 -> V_713 = V_234 ;
V_97 -> V_690 = V_688 ;
V_97 -> V_693 = V_689 ;
F_217 ( V_24 , true ) ;
return 0 ;
V_706:
F_134 ( V_234 ) ;
V_705:
F_154 ( & V_2 -> V_306 ) ;
V_703:
F_392 ( & V_234 -> V_210 ) ;
return V_238 ;
}
static int F_393 ( struct V_23 * V_24 , int V_248 , int V_249 )
{
struct V_97 * V_97 = F_35 ( V_24 ) ;
V_97 -> V_684 = V_248 ;
V_97 -> V_685 = V_249 ;
F_217 ( V_24 , true ) ;
return 0 ;
}
void F_394 ( struct V_23 * V_24 , T_4 V_714 , T_4 V_715 ,
T_4 V_716 , int V_717 )
{
struct V_97 * V_97 = F_35 ( V_24 ) ;
V_97 -> V_669 [ V_717 ] = V_714 >> 8 ;
V_97 -> V_670 [ V_717 ] = V_715 >> 8 ;
V_97 -> V_671 [ V_717 ] = V_716 >> 8 ;
}
void F_395 ( struct V_23 * V_24 , T_4 * V_714 , T_4 * V_715 ,
T_4 * V_716 , int V_717 )
{
struct V_97 * V_97 = F_35 ( V_24 ) ;
* V_714 = V_97 -> V_669 [ V_717 ] << 8 ;
* V_715 = V_97 -> V_670 [ V_717 ] << 8 ;
* V_716 = V_97 -> V_671 [ V_717 ] << 8 ;
}
static void F_396 ( struct V_23 * V_24 , T_4 * V_714 , T_4 * V_715 ,
T_4 * V_716 , T_5 V_718 , T_5 V_701 )
{
int V_719 = ( V_718 + V_701 > 256 ) ? 256 : V_718 + V_701 , V_157 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
for ( V_157 = V_718 ; V_157 < V_719 ; V_157 ++ ) {
V_97 -> V_669 [ V_157 ] = V_714 [ V_157 ] >> 8 ;
V_97 -> V_670 [ V_157 ] = V_715 [ V_157 ] >> 8 ;
V_97 -> V_671 [ V_157 ] = V_716 [ V_157 ] >> 8 ;
}
F_216 ( V_24 ) ;
}
static struct V_255 *
F_397 ( struct V_1 * V_2 ,
struct V_720 * V_721 ,
struct V_233 * V_234 )
{
struct V_257 * V_258 ;
int V_238 ;
V_258 = F_398 ( sizeof( * V_258 ) , V_722 ) ;
if ( ! V_258 ) {
F_392 ( & V_234 -> V_210 ) ;
return F_399 ( - V_702 ) ;
}
V_238 = F_400 ( V_2 , V_258 , V_721 , V_234 ) ;
if ( V_238 ) {
F_392 ( & V_234 -> V_210 ) ;
F_249 ( V_258 ) ;
return F_399 ( V_238 ) ;
}
return & V_258 -> V_210 ;
}
static T_1
F_401 ( int V_688 , int V_617 )
{
T_1 V_251 = F_402 ( V_688 * V_617 , 8 ) ;
return F_403 ( V_251 , 64 ) ;
}
static T_1
F_404 ( struct V_445 * V_357 , int V_617 )
{
T_1 V_251 = F_401 ( V_357 -> V_424 , V_617 ) ;
return F_403 ( V_251 * V_357 -> V_426 , V_723 ) ;
}
static struct V_255 *
F_405 ( struct V_1 * V_2 ,
struct V_445 * V_357 ,
int V_724 , int V_617 )
{
struct V_233 * V_234 ;
struct V_720 V_721 = { 0 } ;
V_234 = F_406 ( V_2 ,
F_404 ( V_357 , V_617 ) ) ;
if ( V_234 == NULL )
return F_399 ( - V_702 ) ;
V_721 . V_688 = V_357 -> V_424 ;
V_721 . V_689 = V_357 -> V_426 ;
V_721 . V_283 [ 0 ] = F_401 ( V_721 . V_688 ,
V_617 ) ;
V_721 . V_262 = F_407 ( V_617 , V_724 ) ;
return F_397 ( V_2 , & V_721 , V_234 ) ;
}
static struct V_255 *
F_408 ( struct V_1 * V_2 ,
struct V_445 * V_357 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_233 * V_234 ;
struct V_255 * V_256 ;
if ( V_4 -> V_725 == NULL )
return NULL ;
V_234 = V_4 -> V_725 -> V_726 . V_234 ;
if ( V_234 == NULL )
return NULL ;
V_256 = & V_4 -> V_725 -> V_726 . V_210 ;
if ( V_256 -> V_283 [ 0 ] < F_401 ( V_357 -> V_424 ,
V_256 -> V_284 ) )
return NULL ;
if ( V_234 -> V_210 . V_701 < V_357 -> V_426 * V_256 -> V_283 [ 0 ] )
return NULL ;
return V_256 ;
}
bool F_409 ( struct V_432 * V_433 ,
struct V_445 * V_357 ,
struct V_727 * V_728 )
{
struct V_97 * V_97 ;
struct V_62 * V_62 =
F_254 ( V_433 ) ;
struct V_23 * V_729 ;
struct V_438 * V_63 = & V_62 -> V_210 ;
struct V_23 * V_24 = NULL ;
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_255 * V_256 ;
int V_157 = - 1 ;
F_40 ( L_131 ,
V_433 -> V_210 . V_215 , F_252 ( V_433 ) ,
V_63 -> V_210 . V_215 , F_357 ( V_63 ) ) ;
if ( V_63 -> V_24 ) {
V_24 = V_63 -> V_24 ;
F_153 ( & V_24 -> V_292 ) ;
V_728 -> V_730 = V_433 -> V_436 ;
V_728 -> V_731 = false ;
if ( V_433 -> V_436 != V_439 )
V_433 -> V_732 -> V_436 ( V_433 , V_439 ) ;
return true ;
}
F_150 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_157 ++ ;
if ( ! ( V_63 -> V_733 & ( 1 << V_157 ) ) )
continue;
if ( ! V_729 -> V_125 ) {
V_24 = V_729 ;
break;
}
}
if ( ! V_24 ) {
F_40 ( L_132 ) ;
return false ;
}
F_153 ( & V_24 -> V_292 ) ;
V_62 -> V_734 = F_35 ( V_24 ) ;
F_410 ( V_433 ) -> V_735 = V_62 ;
V_97 = F_35 ( V_24 ) ;
V_728 -> V_730 = V_433 -> V_436 ;
V_728 -> V_731 = true ;
V_728 -> V_736 = NULL ;
if ( ! V_357 )
V_357 = & V_737 ;
V_256 = F_408 ( V_2 , V_357 ) ;
if ( V_256 == NULL ) {
F_40 ( L_133 ) ;
V_256 = F_405 ( V_2 , V_357 , 24 , 32 ) ;
V_728 -> V_736 = V_256 ;
} else
F_40 ( L_134 ) ;
if ( F_411 ( V_256 ) ) {
F_40 ( L_135 ) ;
F_154 ( & V_24 -> V_292 ) ;
return false ;
}
if ( F_412 ( V_24 , V_357 , 0 , 0 , V_256 ) ) {
F_40 ( L_136 ) ;
if ( V_728 -> V_736 )
V_728 -> V_736 -> V_732 -> V_738 ( V_728 -> V_736 ) ;
F_154 ( & V_24 -> V_292 ) ;
return false ;
}
F_41 ( V_2 , V_97 -> V_95 ) ;
return true ;
}
void F_413 ( struct V_432 * V_433 ,
struct V_727 * V_728 )
{
struct V_62 * V_62 =
F_254 ( V_433 ) ;
struct V_438 * V_63 = & V_62 -> V_210 ;
struct V_23 * V_24 = V_63 -> V_24 ;
F_40 ( L_131 ,
V_433 -> V_210 . V_215 , F_252 ( V_433 ) ,
V_63 -> V_210 . V_215 , F_357 ( V_63 ) ) ;
if ( V_728 -> V_731 ) {
F_410 ( V_433 ) -> V_735 = NULL ;
V_62 -> V_734 = NULL ;
F_412 ( V_24 , NULL , 0 , 0 , NULL ) ;
if ( V_728 -> V_736 ) {
F_414 ( V_728 -> V_736 ) ;
F_415 ( V_728 -> V_736 ) ;
}
F_154 ( & V_24 -> V_292 ) ;
return;
}
if ( V_728 -> V_730 != V_439 )
V_433 -> V_732 -> V_436 ( V_433 , V_728 -> V_730 ) ;
F_154 ( & V_24 -> V_292 ) ;
}
static int F_416 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
T_1 V_394 = F_4 ( F_55 ( V_95 ) ) ;
T_1 V_395 ;
T_3 clock ;
if ( ( V_394 & V_739 ) == 0 )
V_395 = F_4 ( F_278 ( V_95 ) ) ;
else
V_395 = F_4 ( F_279 ( V_95 ) ) ;
clock . V_61 = ( V_395 & V_740 ) >> V_741 ;
if ( F_21 ( V_2 ) ) {
clock . V_59 = F_417 ( ( V_395 & V_742 ) >> V_743 ) - 1 ;
clock . V_54 = ( V_395 & V_744 ) >> V_745 ;
} else {
clock . V_59 = ( V_395 & V_746 ) >> V_743 ;
clock . V_54 = ( V_395 & V_747 ) >> V_745 ;
}
if ( ! F_23 ( V_2 ) ) {
if ( F_21 ( V_2 ) )
clock . V_56 = F_417 ( ( V_394 & V_748 ) >>
V_525 ) ;
else
clock . V_56 = F_417 ( ( V_394 & V_749 ) >>
V_526 ) ;
switch ( V_394 & V_750 ) {
case V_522 :
clock . V_57 = V_394 & V_528 ?
5 : 10 ;
break;
case V_521 :
clock . V_57 = V_394 & V_529 ?
7 : 14 ;
break;
default:
F_40 ( L_137
L_138 , ( int ) ( V_394 & V_750 ) ) ;
return 0 ;
}
F_25 ( V_2 , 96000 , & clock ) ;
} else {
bool V_568 = ( V_95 == 1 ) && ( F_4 ( V_79 ) & V_177 ) ;
if ( V_568 ) {
clock . V_56 = F_417 ( ( V_394 & V_751 ) >>
V_526 ) ;
clock . V_57 = 14 ;
if ( ( V_394 & V_752 ) ==
V_535 ) {
F_25 ( V_2 , 66000 , & clock ) ;
} else
F_25 ( V_2 , 48000 , & clock ) ;
} else {
if ( V_394 & V_538 )
clock . V_56 = 2 ;
else {
clock . V_56 = ( ( V_394 & V_753 ) >>
V_526 ) + 2 ;
}
if ( V_394 & V_539 )
clock . V_57 = 4 ;
else
clock . V_57 = 2 ;
F_25 ( V_2 , 48000 , & clock ) ;
}
}
return clock . V_60 ;
}
struct V_445 * F_418 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
enum V_94 V_99 = V_97 -> V_98 . V_99 ;
struct V_445 * V_357 ;
int V_754 = F_4 ( F_192 ( V_99 ) ) ;
int V_755 = F_4 ( F_196 ( V_99 ) ) ;
int V_756 = F_4 ( F_198 ( V_99 ) ) ;
int V_757 = F_4 ( F_202 ( V_99 ) ) ;
V_357 = F_398 ( sizeof( * V_357 ) , V_722 ) ;
if ( ! V_357 )
return NULL ;
V_357 -> clock = F_416 ( V_2 , V_24 ) ;
V_357 -> V_424 = ( V_754 & 0xffff ) + 1 ;
V_357 -> V_758 = ( ( V_754 & 0xffff0000 ) >> 16 ) + 1 ;
V_357 -> V_450 = ( V_755 & 0xffff ) + 1 ;
V_357 -> V_759 = ( ( V_755 & 0xffff0000 ) >> 16 ) + 1 ;
V_357 -> V_426 = ( V_756 & 0xffff ) + 1 ;
V_357 -> V_760 = ( ( V_756 & 0xffff0000 ) >> 16 ) + 1 ;
V_357 -> V_761 = ( V_757 & 0xffff ) + 1 ;
V_357 -> V_762 = ( ( V_757 & 0xffff0000 ) >> 16 ) + 1 ;
F_419 ( V_357 ) ;
return V_357 ;
}
static void F_148 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
T_8 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
int V_95 = V_97 -> V_95 ;
int V_763 = F_55 ( V_95 ) ;
int V_394 ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_572 )
return;
V_394 = F_4 ( V_763 ) ;
if ( ! F_297 ( V_2 ) && ( V_394 & V_739 ) ) {
F_58 ( L_139 ) ;
F_68 ( V_4 , V_95 ) ;
V_394 &= ~ V_739 ;
F_11 ( V_763 , V_394 ) ;
F_41 ( V_2 , V_95 ) ;
V_394 = F_4 ( V_763 ) ;
if ( V_394 & V_739 )
F_58 ( L_140 ) ;
}
}
static void F_420 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
T_8 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_572 )
return;
if ( ! F_297 ( V_2 ) && V_97 -> V_490 ) {
int V_95 = V_97 -> V_95 ;
int V_763 = F_55 ( V_95 ) ;
int V_394 ;
F_58 ( L_141 ) ;
F_68 ( V_4 , V_95 ) ;
V_394 = F_4 ( V_763 ) ;
V_394 |= V_739 ;
F_11 ( V_763 , V_394 ) ;
F_41 ( V_2 , V_95 ) ;
V_394 = F_4 ( V_763 ) ;
if ( ! ( V_394 & V_739 ) )
F_58 ( L_142 ) ;
}
}
void F_421 ( struct V_1 * V_2 )
{
F_422 ( V_2 -> V_5 ) ;
}
void F_423 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
if ( ! V_491 )
return;
F_150 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_24 -> V_256 )
continue;
F_420 ( V_24 ) ;
}
}
void F_424 ( struct V_233 * V_234 )
{
struct V_1 * V_2 = V_234 -> V_210 . V_2 ;
struct V_23 * V_24 ;
if ( ! V_491 )
return;
F_150 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_24 -> V_256 )
continue;
if ( F_139 ( V_24 -> V_256 ) -> V_234 == V_234 )
F_148 ( V_24 ) ;
}
}
static void F_425 ( struct V_23 * V_24 )
{
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_764 * V_765 ;
unsigned long V_342 ;
F_178 ( & V_2 -> V_346 , V_342 ) ;
V_765 = V_97 -> V_347 ;
V_97 -> V_347 = NULL ;
F_179 ( & V_2 -> V_346 , V_342 ) ;
if ( V_765 ) {
F_426 ( & V_765 -> V_765 ) ;
F_249 ( V_765 ) ;
}
F_427 ( V_24 ) ;
F_249 ( V_97 ) ;
}
static void F_428 ( struct V_766 * V_767 )
{
struct V_764 * V_765 =
F_429 ( V_767 , struct V_764 , V_765 ) ;
struct V_1 * V_2 = V_765 -> V_24 -> V_2 ;
F_153 ( & V_2 -> V_306 ) ;
F_135 ( V_765 -> V_768 ) ;
F_391 ( & V_765 -> V_769 -> V_210 ) ;
F_391 ( & V_765 -> V_768 -> V_210 ) ;
F_159 ( V_2 ) ;
F_154 ( & V_2 -> V_306 ) ;
F_95 ( F_177 ( & F_35 ( V_765 -> V_24 ) -> V_770 ) == 0 ) ;
F_430 ( & F_35 ( V_765 -> V_24 ) -> V_770 ) ;
F_249 ( V_765 ) ;
}
static void F_431 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_764 * V_765 ;
unsigned long V_342 ;
if ( V_97 == NULL )
return;
F_178 ( & V_2 -> V_346 , V_342 ) ;
V_765 = V_97 -> V_347 ;
F_432 () ;
if ( V_765 == NULL || F_177 ( & V_765 -> V_343 ) < V_771 ) {
F_179 ( & V_2 -> V_346 , V_342 ) ;
return;
}
F_432 () ;
V_97 -> V_347 = NULL ;
if ( V_765 -> V_772 )
F_433 ( V_2 , V_97 -> V_95 , V_765 -> V_772 ) ;
F_434 ( V_2 , V_97 -> V_95 ) ;
F_179 ( & V_2 -> V_346 , V_342 ) ;
F_435 ( & V_4 -> V_348 ) ;
F_436 ( V_4 -> V_773 , & V_765 -> V_765 ) ;
F_437 ( V_97 -> V_155 , V_765 -> V_769 ) ;
}
void F_438 ( struct V_1 * V_2 , int V_95 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_23 * V_24 = V_4 -> V_96 [ V_95 ] ;
F_431 ( V_2 , V_24 ) ;
}
void F_152 ( struct V_1 * V_2 , int V_155 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_23 * V_24 = V_4 -> V_774 [ V_155 ] ;
F_431 ( V_2 , V_24 ) ;
}
void F_151 ( struct V_1 * V_2 , int V_155 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 =
F_35 ( V_4 -> V_774 [ V_155 ] ) ;
unsigned long V_342 ;
F_178 ( & V_2 -> V_346 , V_342 ) ;
if ( V_97 -> V_347 )
F_439 ( & V_97 -> V_347 -> V_343 ) ;
F_179 ( & V_2 -> V_346 , V_342 ) ;
}
inline static void F_440 ( struct V_97 * V_97 )
{
F_441 () ;
F_442 ( & V_97 -> V_347 -> V_343 , V_775 ) ;
F_441 () ;
}
static int F_443 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_255 * V_256 ,
struct V_233 * V_234 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
T_1 V_776 ;
struct V_235 * V_777 = & V_4 -> V_777 [ V_778 ] ;
int V_238 ;
V_238 = F_127 ( V_2 , V_234 , V_777 ) ;
if ( V_238 )
goto V_69;
V_238 = F_444 ( V_777 , 6 ) ;
if ( V_238 )
goto V_247;
if ( V_97 -> V_155 )
V_776 = V_779 ;
else
V_776 = V_780 ;
F_445 ( V_777 , V_781 | V_776 ) ;
F_445 ( V_777 , V_782 ) ;
F_445 ( V_777 , V_783 |
F_446 ( V_97 -> V_155 ) ) ;
F_445 ( V_777 , V_256 -> V_283 [ 0 ] ) ;
F_445 ( V_777 , V_234 -> V_286 + V_97 -> V_285 ) ;
F_445 ( V_777 , 0 ) ;
F_440 ( V_97 ) ;
F_447 ( V_777 ) ;
return 0 ;
V_247:
F_135 ( V_234 ) ;
V_69:
return V_238 ;
}
static int F_448 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_255 * V_256 ,
struct V_233 * V_234 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
T_1 V_776 ;
struct V_235 * V_777 = & V_4 -> V_777 [ V_778 ] ;
int V_238 ;
V_238 = F_127 ( V_2 , V_234 , V_777 ) ;
if ( V_238 )
goto V_69;
V_238 = F_444 ( V_777 , 6 ) ;
if ( V_238 )
goto V_247;
if ( V_97 -> V_155 )
V_776 = V_779 ;
else
V_776 = V_780 ;
F_445 ( V_777 , V_781 | V_776 ) ;
F_445 ( V_777 , V_782 ) ;
F_445 ( V_777 , V_784 |
F_446 ( V_97 -> V_155 ) ) ;
F_445 ( V_777 , V_256 -> V_283 [ 0 ] ) ;
F_445 ( V_777 , V_234 -> V_286 + V_97 -> V_285 ) ;
F_445 ( V_777 , V_782 ) ;
F_440 ( V_97 ) ;
F_447 ( V_777 ) ;
return 0 ;
V_247:
F_135 ( V_234 ) ;
V_69:
return V_238 ;
}
static int F_449 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_255 * V_256 ,
struct V_233 * V_234 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
T_5 V_785 , V_786 ;
struct V_235 * V_777 = & V_4 -> V_777 [ V_778 ] ;
int V_238 ;
V_238 = F_127 ( V_2 , V_234 , V_777 ) ;
if ( V_238 )
goto V_69;
V_238 = F_444 ( V_777 , 4 ) ;
if ( V_238 )
goto V_247;
F_445 ( V_777 , V_783 |
F_446 ( V_97 -> V_155 ) ) ;
F_445 ( V_777 , V_256 -> V_283 [ 0 ] ) ;
F_445 ( V_777 ,
( V_234 -> V_286 + V_97 -> V_285 ) |
V_234 -> V_239 ) ;
V_785 = 0 ;
V_786 = F_4 ( F_295 ( V_97 -> V_95 ) ) & 0x0fff0fff ;
F_445 ( V_777 , V_785 | V_786 ) ;
F_440 ( V_97 ) ;
F_447 ( V_777 ) ;
return 0 ;
V_247:
F_135 ( V_234 ) ;
V_69:
return V_238 ;
}
static int F_450 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_255 * V_256 ,
struct V_233 * V_234 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_235 * V_777 = & V_4 -> V_777 [ V_778 ] ;
T_5 V_785 , V_786 ;
int V_238 ;
V_238 = F_127 ( V_2 , V_234 , V_777 ) ;
if ( V_238 )
goto V_69;
V_238 = F_444 ( V_777 , 4 ) ;
if ( V_238 )
goto V_247;
F_445 ( V_777 , V_783 |
F_446 ( V_97 -> V_155 ) ) ;
F_445 ( V_777 , V_256 -> V_283 [ 0 ] | V_234 -> V_239 ) ;
F_445 ( V_777 , V_234 -> V_286 + V_97 -> V_285 ) ;
V_785 = 0 ;
V_786 = F_4 ( F_295 ( V_97 -> V_95 ) ) & 0x0fff0fff ;
F_445 ( V_777 , V_785 | V_786 ) ;
F_440 ( V_97 ) ;
F_447 ( V_777 ) ;
return 0 ;
V_247:
F_135 ( V_234 ) ;
V_69:
return V_238 ;
}
static int F_451 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_255 * V_256 ,
struct V_233 * V_234 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_235 * V_777 = & V_4 -> V_777 [ V_787 ] ;
T_5 V_788 = 0 ;
int V_238 ;
V_238 = F_127 ( V_2 , V_234 , V_777 ) ;
if ( V_238 )
goto V_69;
switch( V_97 -> V_155 ) {
case V_789 :
V_788 = V_790 ;
break;
case V_791 :
V_788 = V_792 ;
break;
case V_793 :
V_788 = V_794 ;
break;
default:
F_452 ( 1 , L_143 ) ;
V_238 = - V_795 ;
goto V_247;
}
V_238 = F_444 ( V_777 , 4 ) ;
if ( V_238 )
goto V_247;
F_445 ( V_777 , V_784 | V_788 ) ;
F_445 ( V_777 , ( V_256 -> V_283 [ 0 ] | V_234 -> V_239 ) ) ;
F_445 ( V_777 , V_234 -> V_286 + V_97 -> V_285 ) ;
F_445 ( V_777 , ( V_782 ) ) ;
F_440 ( V_97 ) ;
F_447 ( V_777 ) ;
return 0 ;
V_247:
F_135 ( V_234 ) ;
V_69:
return V_238 ;
}
static int F_453 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_255 * V_256 ,
struct V_233 * V_234 )
{
return - V_795 ;
}
static int F_454 ( struct V_23 * V_24 ,
struct V_255 * V_256 ,
struct V_796 * V_772 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_255 * V_293 = V_24 -> V_256 ;
struct V_233 * V_234 = F_139 ( V_256 ) -> V_234 ;
struct V_97 * V_97 = F_35 ( V_24 ) ;
struct V_764 * V_765 ;
unsigned long V_342 ;
int V_238 ;
if ( V_256 -> V_262 != V_24 -> V_256 -> V_262 )
return - V_243 ;
if ( F_43 ( V_2 ) -> V_103 > 3 &&
( V_256 -> V_797 [ 0 ] != V_24 -> V_256 -> V_797 [ 0 ] ||
V_256 -> V_283 [ 0 ] != V_24 -> V_256 -> V_283 [ 0 ] ) )
return - V_243 ;
V_765 = F_398 ( sizeof *V_765 , V_722 ) ;
if ( V_765 == NULL )
return - V_702 ;
V_765 -> V_772 = V_772 ;
V_765 -> V_24 = V_24 ;
V_765 -> V_768 = F_139 ( V_293 ) -> V_234 ;
F_455 ( & V_765 -> V_765 , F_428 ) ;
V_238 = F_456 ( V_2 , V_97 -> V_95 ) ;
if ( V_238 )
goto V_798;
F_178 ( & V_2 -> V_346 , V_342 ) ;
if ( V_97 -> V_347 ) {
F_179 ( & V_2 -> V_346 , V_342 ) ;
F_249 ( V_765 ) ;
F_434 ( V_2 , V_97 -> V_95 ) ;
F_58 ( L_144 ) ;
return - V_799 ;
}
V_97 -> V_347 = V_765 ;
F_179 ( & V_2 -> V_346 , V_342 ) ;
if ( F_177 ( & V_97 -> V_770 ) >= 2 )
F_457 ( V_4 -> V_773 ) ;
V_238 = F_458 ( V_2 ) ;
if ( V_238 )
goto V_800;
F_459 ( & V_765 -> V_768 -> V_210 ) ;
F_459 ( & V_234 -> V_210 ) ;
V_24 -> V_256 = V_256 ;
V_765 -> V_769 = V_234 ;
V_765 -> V_801 = true ;
F_460 ( & V_97 -> V_770 ) ;
V_97 -> V_345 = F_177 ( & V_4 -> V_344 . V_345 ) ;
V_238 = V_4 -> V_289 . V_802 ( V_2 , V_24 , V_256 , V_234 ) ;
if ( V_238 )
goto V_803;
F_224 ( V_2 ) ;
F_424 ( V_234 ) ;
F_154 ( & V_2 -> V_306 ) ;
F_461 ( V_97 -> V_155 , V_234 ) ;
return 0 ;
V_803:
F_430 ( & V_97 -> V_770 ) ;
V_24 -> V_256 = V_293 ;
F_391 ( & V_765 -> V_768 -> V_210 ) ;
F_391 ( & V_234 -> V_210 ) ;
F_154 ( & V_2 -> V_306 ) ;
V_800:
F_178 ( & V_2 -> V_346 , V_342 ) ;
V_97 -> V_347 = NULL ;
F_179 ( & V_2 -> V_346 , V_342 ) ;
F_434 ( V_2 , V_97 -> V_95 ) ;
V_798:
F_249 ( V_765 ) ;
return V_238 ;
}
bool F_462 ( struct V_62 * V_63 )
{
struct V_62 * V_804 ;
struct V_23 * V_24 = & V_63 -> V_734 -> V_210 ;
if ( F_2 ( ! V_24 ) )
return false ;
F_150 (other_encoder,
&crtc->dev->mode_config.encoder_list,
base.head) {
if ( & V_804 -> V_734 -> V_210 != V_24 ||
V_63 == V_804 )
continue;
else
return true ;
}
return false ;
}
static bool F_463 ( struct V_438 * V_63 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 ;
struct V_23 * V_197 ;
int V_805 = 1 ;
F_46 ( ! V_24 , L_145 ) ;
V_2 = V_24 -> V_2 ;
F_150 (tmp, &dev->mode_config.crtc_list, head) {
if ( V_197 == V_24 )
break;
V_805 <<= 1 ;
}
if ( V_63 -> V_733 & V_805 )
return true ;
return false ;
}
static void F_464 ( struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_440 * V_433 ;
F_150 (connector, &dev->mode_config.connector_list,
base.head) {
V_433 -> V_735 =
F_245 ( V_433 -> V_210 . V_63 ) ;
}
F_150 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_63 -> V_734 =
F_35 ( V_63 -> V_210 . V_24 ) ;
}
}
static void F_465 ( struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_440 * V_433 ;
F_150 (connector, &dev->mode_config.connector_list,
base.head) {
V_433 -> V_210 . V_63 = & V_433 -> V_735 -> V_210 ;
}
F_150 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_63 -> V_210 . V_24 = & V_63 -> V_734 -> V_210 ;
}
}
static int
F_466 ( struct V_23 * V_24 ,
struct V_255 * V_256 ,
struct V_443 * V_444 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_432 * V_433 ;
int V_617 ;
switch ( V_256 -> V_262 ) {
case V_263 :
V_617 = 8 * 3 ;
break;
case V_265 :
case V_266 :
if ( F_2 ( F_43 ( V_2 ) -> V_103 > 3 ) )
return - V_243 ;
case V_268 :
V_617 = 6 * 3 ;
break;
case V_273 :
case V_274 :
if ( F_2 ( F_43 ( V_2 ) -> V_103 < 4 ) )
return - V_243 ;
case V_270 :
case V_271 :
V_617 = 8 * 3 ;
break;
case V_276 :
case V_277 :
case V_279 :
case V_280 :
if ( F_2 ( F_43 ( V_2 ) -> V_103 < 4 ) )
return - V_243 ;
V_617 = 10 * 3 ;
break;
default:
F_40 ( L_146 ) ;
return - V_243 ;
}
V_444 -> V_451 = V_617 ;
F_150 (connector, &dev->mode_config.connector_list,
head) {
if ( V_433 -> V_63 && V_433 -> V_63 -> V_24 != V_24 )
continue;
if ( V_433 -> V_806 . V_378 &&
V_433 -> V_806 . V_378 * 3 < V_617 ) {
F_40 ( L_147 ,
V_617 , V_433 -> V_806 . V_378 * 3 ) ;
V_444 -> V_451 = V_433 -> V_806 . V_378 * 3 ;
}
}
return V_617 ;
}
static struct V_443 *
F_467 ( struct V_23 * V_24 ,
struct V_255 * V_256 ,
struct V_445 * V_357 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_631 * V_632 ;
struct V_62 * V_63 ;
struct V_443 * V_444 ;
int V_807 ;
V_444 = F_398 ( sizeof( * V_444 ) , V_722 ) ;
if ( ! V_444 )
return F_399 ( - V_702 ) ;
F_468 ( & V_444 -> V_446 , V_357 ) ;
F_468 ( & V_444 -> V_447 , V_357 ) ;
V_807 = F_466 ( V_24 , V_256 , V_444 ) ;
if ( V_807 < 0 )
goto V_703;
F_150 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( & V_63 -> V_734 -> V_210 != V_24 )
continue;
if ( V_63 -> V_808 ) {
if ( ! ( V_63 -> V_808 ( V_63 , V_444 ) ) ) {
F_40 ( L_148 ) ;
goto V_703;
}
continue;
}
V_632 = V_63 -> V_210 . V_636 ;
if ( ! ( V_632 -> V_809 ( & V_63 -> V_210 ,
& V_444 -> V_447 ,
& V_444 -> V_446 ) ) ) {
F_40 ( L_149 ) ;
goto V_703;
}
}
if ( ! ( F_257 ( V_24 , V_444 ) ) ) {
F_40 ( L_150 ) ;
goto V_703;
}
F_40 ( L_151 , V_24 -> V_210 . V_215 ) ;
V_444 -> V_558 = V_444 -> V_451 != V_807 ;
F_40 ( L_152 ,
V_807 , V_444 -> V_451 , V_444 -> V_558 ) ;
return V_444 ;
V_703:
F_249 ( V_444 ) ;
return F_399 ( - V_243 ) ;
}
static void
F_469 ( struct V_23 * V_24 , unsigned * V_810 ,
unsigned * V_811 , unsigned * V_812 )
{
struct V_97 * V_97 ;
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_62 * V_63 ;
struct V_440 * V_433 ;
struct V_23 * V_813 ;
* V_812 = * V_810 = * V_811 = 0 ;
F_150 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_433 -> V_210 . V_63 == & V_433 -> V_735 -> V_210 )
continue;
if ( V_433 -> V_210 . V_63 ) {
V_813 = V_433 -> V_210 . V_63 -> V_24 ;
* V_811 |= 1 << F_35 ( V_813 ) -> V_95 ;
}
if ( V_433 -> V_735 )
* V_811 |=
1 << V_433 -> V_735 -> V_734 -> V_95 ;
}
F_150 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_63 -> V_210 . V_24 == & V_63 -> V_734 -> V_210 )
continue;
if ( V_63 -> V_210 . V_24 ) {
V_813 = V_63 -> V_210 . V_24 ;
* V_811 |= 1 << F_35 ( V_813 ) -> V_95 ;
}
if ( V_63 -> V_734 )
* V_811 |= 1 << V_63 -> V_734 -> V_95 ;
}
F_150 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
bool V_814 = false ;
if ( ! V_97 -> V_210 . V_125 )
continue;
F_150 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_63 -> V_734 == V_97 )
V_814 = true ;
}
if ( ! V_814 )
* V_812 |= 1 << V_97 -> V_95 ;
}
V_97 = F_35 ( V_24 ) ;
if ( V_24 -> V_125 )
* V_811 |= 1 << V_97 -> V_95 ;
if ( * V_811 )
* V_810 = * V_811 ;
* V_810 &= ~ ( * V_812 ) ;
* V_811 &= ~ ( * V_812 ) ;
* V_810 &= 1 << V_97 -> V_95 ;
* V_811 &= 1 << V_97 -> V_95 ;
}
static bool F_470 ( struct V_23 * V_24 )
{
struct V_438 * V_63 ;
struct V_1 * V_2 = V_24 -> V_2 ;
F_150 (encoder, &dev->mode_config.encoder_list, head)
if ( V_63 -> V_24 == V_24 )
return true ;
return false ;
}
static void
F_471 ( struct V_1 * V_2 , unsigned V_811 )
{
struct V_62 * V_62 ;
struct V_97 * V_97 ;
struct V_432 * V_433 ;
F_150 (intel_encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_62 -> V_210 . V_24 )
continue;
V_97 = F_35 ( V_62 -> V_210 . V_24 ) ;
if ( V_811 & ( 1 << V_97 -> V_95 ) )
V_62 -> V_429 = false ;
}
F_465 ( V_2 ) ;
F_150 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
V_97 -> V_210 . V_125 = F_470 ( & V_97 -> V_210 ) ;
}
F_150 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_433 -> V_63 || ! V_433 -> V_63 -> V_24 )
continue;
V_97 = F_35 ( V_433 -> V_63 -> V_24 ) ;
if ( V_811 & ( 1 << V_97 -> V_95 ) ) {
struct V_815 * V_816 =
V_2 -> V_577 . V_816 ;
V_433 -> V_436 = V_439 ;
F_472 ( & V_433 -> V_210 ,
V_816 ,
V_439 ) ;
V_62 = F_245 ( V_433 -> V_63 ) ;
V_62 -> V_429 = true ;
}
}
}
void
F_255 ( struct V_1 * V_2 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_97 * V_24 ;
struct V_62 * V_63 ;
struct V_440 * V_433 ;
struct V_443 V_444 ;
F_150 (connector, &dev->mode_config.connector_list,
base.head) {
F_251 ( V_433 ) ;
F_46 ( & V_433 -> V_735 -> V_210 != V_433 -> V_210 . V_63 ,
L_153 ) ;
}
F_150 (encoder, &dev->mode_config.encoder_list,
base.head) {
bool V_125 = false ;
bool V_213 = false ;
enum V_95 V_95 , V_817 ;
F_40 ( L_154 ,
V_63 -> V_210 . V_210 . V_215 ,
F_357 ( & V_63 -> V_210 ) ) ;
F_46 ( & V_63 -> V_734 -> V_210 != V_63 -> V_210 . V_24 ,
L_155 ) ;
F_46 ( V_63 -> V_429 && ! V_63 -> V_210 . V_24 ,
L_156 ) ;
F_150 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_433 -> V_210 . V_63 != & V_63 -> V_210 )
continue;
V_125 = true ;
if ( V_433 -> V_210 . V_436 != V_437 )
V_213 = true ;
}
F_46 ( ! ! V_63 -> V_210 . V_24 != V_125 ,
L_157
L_158 ,
! ! V_63 -> V_210 . V_24 , V_125 ) ;
F_46 ( V_213 && ! V_63 -> V_210 . V_24 ,
L_159 ) ;
F_46 ( V_63 -> V_429 != V_213 ,
L_160
L_158 , V_213 , V_63 -> V_429 ) ;
V_213 = V_63 -> V_441 ( V_63 , & V_95 ) ;
F_46 ( V_213 != V_63 -> V_429 ,
L_161
L_158 ,
V_63 -> V_429 , V_213 ) ;
if ( ! V_63 -> V_210 . V_24 )
continue;
V_817 = F_35 ( V_63 -> V_210 . V_24 ) -> V_95 ;
F_46 ( V_213 && V_95 != V_817 ,
L_162
L_158 ,
V_817 , V_95 ) ;
}
F_150 (crtc, &dev->mode_config.crtc_list,
base.head) {
bool V_125 = false ;
bool V_213 = false ;
F_40 ( L_151 ,
V_24 -> V_210 . V_210 . V_215 ) ;
F_46 ( V_24 -> V_213 && ! V_24 -> V_210 . V_125 ,
L_163 ) ;
F_150 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_63 -> V_210 . V_24 != & V_24 -> V_210 )
continue;
V_125 = true ;
if ( V_63 -> V_429 )
V_213 = true ;
}
F_46 ( V_213 != V_24 -> V_213 ,
L_164
L_158 , V_213 , V_24 -> V_213 ) ;
F_46 ( V_125 != V_24 -> V_210 . V_125 ,
L_165
L_158 , V_125 , V_24 -> V_210 . V_125 ) ;
memset ( & V_444 , 0 , sizeof( V_444 ) ) ;
V_213 = V_4 -> V_289 . V_818 ( V_24 ,
& V_444 ) ;
if ( V_24 -> V_95 == V_143 && V_4 -> V_151 & V_152 )
V_213 = V_24 -> V_213 ;
F_46 ( V_24 -> V_213 != V_213 ,
L_166
L_158 , V_24 -> V_213 , V_213 ) ;
F_46 ( V_213 &&
! F_473 ( & V_24 -> V_98 , & V_444 ) ,
L_167 ) ;
}
}
static int F_474 ( struct V_23 * V_24 ,
struct V_445 * V_357 ,
int V_248 , int V_249 , struct V_255 * V_256 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
T_8 * V_4 = V_2 -> V_5 ;
struct V_445 * V_819 , * V_820 ;
struct V_443 * V_444 = NULL ;
struct V_97 * V_97 ;
unsigned V_812 , V_811 , V_810 ;
int V_238 = 0 ;
V_819 = F_475 ( 2 * sizeof( * V_819 ) , V_722 ) ;
if ( ! V_819 )
return - V_702 ;
V_820 = V_819 + 1 ;
F_469 ( V_24 , & V_810 ,
& V_811 , & V_812 ) ;
* V_820 = V_24 -> V_821 ;
* V_819 = V_24 -> V_357 ;
if ( V_810 ) {
V_444 = F_467 ( V_24 , V_256 , V_357 ) ;
if ( F_411 ( V_444 ) ) {
V_238 = F_476 ( V_444 ) ;
V_444 = NULL ;
goto V_822;
}
}
F_40 ( L_168 ,
V_810 , V_811 , V_812 ) ;
F_477 (dev, disable_pipes, intel_crtc)
F_243 ( & V_97 -> V_210 ) ;
F_477 (dev, prepare_pipes, intel_crtc) {
if ( V_97 -> V_210 . V_125 )
V_4 -> V_289 . V_431 ( & V_97 -> V_210 ) ;
}
if ( V_810 ) {
enum V_94 V_197 = F_35 ( V_24 ) -> V_98 . V_99 ;
V_24 -> V_357 = * V_357 ;
F_35 ( V_24 ) -> V_98 = * V_444 ;
F_35 ( V_24 ) -> V_98 . V_99 = V_197 ;
}
F_471 ( V_2 , V_811 ) ;
if ( V_4 -> V_289 . V_823 )
V_4 -> V_289 . V_823 ( V_2 ) ;
F_477 (dev, modeset_pipes, intel_crtc) {
V_238 = F_354 ( & V_97 -> V_210 ,
V_248 , V_249 , V_256 ) ;
if ( V_238 )
goto V_824;
}
F_477 (dev, prepare_pipes, intel_crtc)
V_4 -> V_289 . V_430 ( & V_97 -> V_210 ) ;
if ( V_810 ) {
V_24 -> V_821 = V_444 -> V_446 ;
F_478 ( V_24 ) ;
}
V_824:
if ( V_238 && V_24 -> V_125 ) {
V_24 -> V_821 = * V_820 ;
V_24 -> V_357 = * V_819 ;
}
V_822:
F_249 ( V_444 ) ;
F_249 ( V_819 ) ;
return V_238 ;
}
int F_412 ( struct V_23 * V_24 ,
struct V_445 * V_357 ,
int V_248 , int V_249 , struct V_255 * V_256 )
{
int V_238 ;
V_238 = F_474 ( V_24 , V_357 , V_248 , V_249 , V_256 ) ;
if ( V_238 == 0 )
F_255 ( V_24 -> V_2 ) ;
return V_238 ;
}
void F_479 ( struct V_23 * V_24 )
{
F_412 ( V_24 , & V_24 -> V_357 , V_24 -> V_248 , V_24 -> V_249 , V_24 -> V_256 ) ;
}
static void F_480 ( struct V_825 * V_98 )
{
if ( ! V_98 )
return;
F_249 ( V_98 -> V_826 ) ;
F_249 ( V_98 -> V_827 ) ;
F_249 ( V_98 ) ;
}
static int F_481 ( struct V_1 * V_2 ,
struct V_825 * V_98 )
{
struct V_438 * V_63 ;
struct V_432 * V_433 ;
int V_828 ;
V_98 -> V_827 =
F_482 ( V_2 -> V_577 . V_829 ,
sizeof( struct V_23 * ) , V_722 ) ;
if ( ! V_98 -> V_827 )
return - V_702 ;
V_98 -> V_826 =
F_482 ( V_2 -> V_577 . V_830 ,
sizeof( struct V_438 * ) , V_722 ) ;
if ( ! V_98 -> V_826 )
return - V_702 ;
V_828 = 0 ;
F_150 (encoder, &dev->mode_config.encoder_list, head) {
V_98 -> V_827 [ V_828 ++ ] = V_63 -> V_24 ;
}
V_828 = 0 ;
F_150 (connector, &dev->mode_config.connector_list, head) {
V_98 -> V_826 [ V_828 ++ ] = V_433 -> V_63 ;
}
return 0 ;
}
static void F_483 ( struct V_1 * V_2 ,
struct V_825 * V_98 )
{
struct V_62 * V_63 ;
struct V_440 * V_433 ;
int V_828 ;
V_828 = 0 ;
F_150 (encoder, &dev->mode_config.encoder_list, base.head) {
V_63 -> V_734 =
F_35 ( V_98 -> V_827 [ V_828 ++ ] ) ;
}
V_828 = 0 ;
F_150 (connector, &dev->mode_config.connector_list, base.head) {
V_433 -> V_735 =
F_245 ( V_98 -> V_826 [ V_828 ++ ] ) ;
}
}
static bool
F_484 ( struct V_23 * V_24 , struct V_432 * V_831 ,
int V_484 )
{
int V_157 ;
for ( V_157 = 0 ; V_157 < V_484 ; V_157 ++ )
if ( V_831 [ V_157 ] . V_63 &&
V_831 [ V_157 ] . V_63 -> V_24 == V_24 &&
V_831 [ V_157 ] . V_436 != V_439 )
return true ;
return false ;
}
static void
F_485 ( struct V_832 * V_833 ,
struct V_825 * V_98 )
{
if ( V_833 -> V_831 != NULL &&
F_484 ( V_833 -> V_24 , * V_833 -> V_831 ,
V_833 -> V_484 ) ) {
V_98 -> V_834 = true ;
} else if ( V_833 -> V_24 -> V_256 != V_833 -> V_256 ) {
if ( V_833 -> V_24 -> V_256 == NULL ) {
F_40 ( L_169 ) ;
V_98 -> V_834 = true ;
} else if ( V_833 -> V_256 == NULL ) {
V_98 -> V_834 = true ;
} else if ( V_833 -> V_256 -> V_262 !=
V_833 -> V_24 -> V_256 -> V_262 ) {
V_98 -> V_834 = true ;
} else {
V_98 -> V_835 = true ;
}
}
if ( V_833 -> V_256 && ( V_833 -> V_248 != V_833 -> V_24 -> V_248 || V_833 -> V_249 != V_833 -> V_24 -> V_249 ) )
V_98 -> V_835 = true ;
if ( V_833 -> V_357 && ! F_486 ( V_833 -> V_357 , & V_833 -> V_24 -> V_357 ) ) {
F_40 ( L_170 ) ;
F_299 ( & V_833 -> V_24 -> V_357 ) ;
F_299 ( V_833 -> V_357 ) ;
V_98 -> V_834 = true ;
}
}
static int
F_487 ( struct V_1 * V_2 ,
struct V_832 * V_833 ,
struct V_825 * V_98 )
{
struct V_23 * V_734 ;
struct V_440 * V_433 ;
struct V_62 * V_63 ;
int V_828 , V_836 ;
F_2 ( ! V_833 -> V_256 && ( V_833 -> V_484 != 0 ) ) ;
F_2 ( V_833 -> V_256 && ( V_833 -> V_484 == 0 ) ) ;
V_828 = 0 ;
F_150 (connector, &dev->mode_config.connector_list,
base.head) {
for ( V_836 = 0 ; V_836 < V_833 -> V_484 ; V_836 ++ ) {
if ( V_833 -> V_831 [ V_836 ] == & V_433 -> V_210 ) {
V_433 -> V_735 = V_433 -> V_63 ;
break;
}
}
if ( ( ! V_833 -> V_256 || V_836 == V_833 -> V_484 ) &&
V_433 -> V_210 . V_63 &&
V_433 -> V_210 . V_63 -> V_24 == V_833 -> V_24 ) {
V_433 -> V_735 = NULL ;
F_40 ( L_171 ,
V_433 -> V_210 . V_210 . V_215 ,
F_252 ( & V_433 -> V_210 ) ) ;
}
if ( & V_433 -> V_735 -> V_210 != V_433 -> V_210 . V_63 ) {
F_40 ( L_172 ) ;
V_98 -> V_834 = true ;
}
}
V_828 = 0 ;
F_150 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_433 -> V_735 )
continue;
V_734 = V_433 -> V_735 -> V_210 . V_24 ;
for ( V_836 = 0 ; V_836 < V_833 -> V_484 ; V_836 ++ ) {
if ( V_833 -> V_831 [ V_836 ] == & V_433 -> V_210 )
V_734 = V_833 -> V_24 ;
}
if ( ! F_463 ( & V_433 -> V_735 -> V_210 ,
V_734 ) ) {
return - V_243 ;
}
V_433 -> V_63 -> V_734 = F_35 ( V_734 ) ;
F_40 ( L_173 ,
V_433 -> V_210 . V_210 . V_215 ,
F_252 ( & V_433 -> V_210 ) ,
V_734 -> V_210 . V_215 ) ;
}
F_150 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_150 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_433 -> V_735 == V_63 ) {
F_2 ( ! V_433 -> V_735 -> V_734 ) ;
goto V_837;
}
}
V_63 -> V_734 = NULL ;
V_837:
if ( & V_63 -> V_734 -> V_210 != V_63 -> V_210 . V_24 ) {
F_40 ( L_174 ) ;
V_98 -> V_834 = true ;
}
}
return 0 ;
}
static int F_488 ( struct V_832 * V_833 )
{
struct V_1 * V_2 ;
struct V_832 V_838 ;
struct V_825 * V_98 ;
int V_238 ;
F_95 ( ! V_833 ) ;
F_95 ( ! V_833 -> V_24 ) ;
F_95 ( ! V_833 -> V_24 -> V_636 ) ;
F_95 ( ! V_833 -> V_357 && V_833 -> V_256 ) ;
F_95 ( V_833 -> V_256 && V_833 -> V_484 == 0 ) ;
if ( V_833 -> V_256 ) {
F_40 ( L_175 ,
V_833 -> V_24 -> V_210 . V_215 , V_833 -> V_256 -> V_210 . V_215 ,
( int ) V_833 -> V_484 , V_833 -> V_248 , V_833 -> V_249 ) ;
} else {
F_40 ( L_176 , V_833 -> V_24 -> V_210 . V_215 ) ;
}
V_2 = V_833 -> V_24 -> V_2 ;
V_238 = - V_702 ;
V_98 = F_398 ( sizeof( * V_98 ) , V_722 ) ;
if ( ! V_98 )
goto V_839;
V_238 = F_481 ( V_2 , V_98 ) ;
if ( V_238 )
goto V_839;
V_838 . V_24 = V_833 -> V_24 ;
V_838 . V_357 = & V_833 -> V_24 -> V_357 ;
V_838 . V_248 = V_833 -> V_24 -> V_248 ;
V_838 . V_249 = V_833 -> V_24 -> V_249 ;
V_838 . V_256 = V_833 -> V_24 -> V_256 ;
F_485 ( V_833 , V_98 ) ;
V_238 = F_487 ( V_2 , V_833 , V_98 ) ;
if ( V_238 )
goto V_703;
if ( V_98 -> V_834 ) {
if ( V_833 -> V_357 ) {
F_40 ( L_177
L_178 ) ;
F_299 ( V_833 -> V_357 ) ;
}
V_238 = F_412 ( V_833 -> V_24 , V_833 -> V_357 ,
V_833 -> V_248 , V_833 -> V_249 , V_833 -> V_256 ) ;
} else if ( V_98 -> V_835 ) {
F_180 ( V_833 -> V_24 ) ;
V_238 = F_158 ( V_833 -> V_24 ,
V_833 -> V_248 , V_833 -> V_249 , V_833 -> V_256 ) ;
}
if ( V_238 ) {
F_10 ( L_179 ,
V_833 -> V_24 -> V_210 . V_215 , V_238 ) ;
V_703:
F_483 ( V_2 , V_98 ) ;
if ( V_98 -> V_834 &&
F_412 ( V_838 . V_24 , V_838 . V_357 ,
V_838 . V_248 , V_838 . V_249 , V_838 . V_256 ) )
F_10 ( L_180 ) ;
}
V_839:
F_480 ( V_98 ) ;
return V_238 ;
}
static void F_489 ( struct V_1 * V_2 )
{
if ( F_61 ( V_2 ) )
F_490 ( V_2 ) ;
}
static void F_491 ( struct V_1 * V_2 )
{
T_8 * V_4 = V_2 -> V_5 ;
int V_157 ;
if ( V_4 -> V_398 == 0 ) {
F_40 ( L_181 ) ;
return;
}
for ( V_157 = 0 ; V_157 < V_4 -> V_398 ; V_157 ++ ) {
V_4 -> V_397 [ V_157 ] . V_131 = F_492 ( V_157 ) ;
V_4 -> V_397 [ V_157 ] . V_399 = F_493 ( V_157 ) ;
V_4 -> V_397 [ V_157 ] . V_626 = F_494 ( V_157 ) ;
}
}
static void F_495 ( struct V_1 * V_2 , int V_95 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_97 * V_97 ;
int V_157 ;
V_97 = F_398 ( sizeof( struct V_97 ) + ( V_840 * sizeof( struct V_432 * ) ) , V_722 ) ;
if ( V_97 == NULL )
return;
F_496 ( V_2 , & V_97 -> V_210 , & V_841 ) ;
F_497 ( & V_97 -> V_210 , 256 ) ;
for ( V_157 = 0 ; V_157 < 256 ; V_157 ++ ) {
V_97 -> V_669 [ V_157 ] = V_157 ;
V_97 -> V_670 [ V_157 ] = V_157 ;
V_97 -> V_671 [ V_157 ] = V_157 ;
}
V_97 -> V_95 = V_95 ;
V_97 -> V_155 = V_95 ;
V_97 -> V_98 . V_99 = V_95 ;
if ( F_96 ( V_2 ) && F_498 ( V_2 ) ) {
F_40 ( L_182 ) ;
V_97 -> V_155 = ! V_95 ;
}
F_95 ( V_95 >= F_499 ( V_4 -> V_774 ) ||
V_4 -> V_774 [ V_97 -> V_155 ] != NULL ) ;
V_4 -> V_774 [ V_97 -> V_155 ] = & V_97 -> V_210 ;
V_4 -> V_96 [ V_97 -> V_95 ] = & V_97 -> V_210 ;
F_500 ( & V_97 -> V_210 , & V_842 ) ;
}
int F_501 ( struct V_1 * V_2 , void * V_843 ,
struct V_695 * V_696 )
{
struct V_844 * V_845 = V_843 ;
struct V_846 * V_847 ;
struct V_97 * V_24 ;
if ( ! F_502 ( V_2 , V_848 ) )
return - V_795 ;
V_847 = F_503 ( V_2 , V_845 -> V_849 ,
V_850 ) ;
if ( ! V_847 ) {
F_10 ( L_183 ) ;
return - V_243 ;
}
V_24 = F_35 ( F_504 ( V_847 ) ) ;
V_845 -> V_95 = V_24 -> V_95 ;
return 0 ;
}
static int F_505 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_210 . V_2 ;
struct V_62 * V_851 ;
int V_852 = 0 ;
int V_853 = 0 ;
F_150 (source_encoder,
&dev->mode_config.encoder_list, base.head) {
if ( V_63 == V_851 )
V_852 |= ( 1 << V_853 ) ;
if ( V_63 -> V_854 && V_851 -> V_854 )
V_852 |= ( 1 << V_853 ) ;
V_853 ++ ;
}
return V_852 ;
}
static bool F_506 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_96 ( V_2 ) )
return false ;
if ( ( F_4 ( V_855 ) & V_856 ) == 0 )
return false ;
if ( F_6 ( V_2 ) &&
( F_4 ( V_857 ) & V_858 ) )
return false ;
return true ;
}
static void F_507 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_62 * V_63 ;
bool V_859 = false ;
bool V_579 ;
V_579 = F_508 ( V_2 ) ;
if ( ! V_579 && ! F_3 ( V_2 ) ) {
F_11 ( V_420 , 0 ) ;
}
if ( ! F_509 ( V_2 ) )
F_510 ( V_2 ) ;
if ( F_61 ( V_2 ) ) {
int V_75 ;
V_75 = F_4 ( V_860 ) & V_861 ;
if ( V_75 )
F_511 ( V_2 , V_862 ) ;
V_75 = F_4 ( V_863 ) ;
if ( V_75 & V_864 )
F_511 ( V_2 , V_115 ) ;
if ( V_75 & V_865 )
F_511 ( V_2 , V_117 ) ;
if ( V_75 & V_866 )
F_511 ( V_2 , V_119 ) ;
} else if ( F_3 ( V_2 ) ) {
int V_75 ;
V_859 = F_512 ( V_2 ) ;
if ( F_506 ( V_2 ) )
F_513 ( V_2 , V_855 , V_862 ) ;
if ( F_4 ( V_191 ) & V_867 ) {
V_75 = F_514 ( V_2 , V_868 , true ) ;
if ( ! V_75 )
F_515 ( V_2 , V_191 , V_115 ) ;
if ( ! V_75 && ( F_4 ( V_184 ) & V_856 ) )
F_513 ( V_2 , V_184 , V_115 ) ;
}
if ( F_4 ( V_192 ) & V_867 )
F_515 ( V_2 , V_192 , V_117 ) ;
if ( ! V_859 && F_4 ( V_193 ) & V_867 )
F_515 ( V_2 , V_193 , V_119 ) ;
if ( F_4 ( V_186 ) & V_856 )
F_513 ( V_2 , V_186 , V_117 ) ;
if ( F_4 ( V_188 ) & V_856 )
F_513 ( V_2 , V_188 , V_119 ) ;
} else if ( F_22 ( V_2 ) ) {
if ( F_4 ( V_869 + V_870 ) & V_856 )
F_513 ( V_2 , V_869 + V_870 , V_117 ) ;
if ( F_4 ( V_869 + V_871 ) & V_867 ) {
F_515 ( V_2 , V_869 + V_871 ,
V_115 ) ;
if ( F_4 ( V_869 + V_872 ) & V_856 )
F_513 ( V_2 , V_869 + V_872 , V_115 ) ;
}
} else if ( F_516 ( V_2 ) ) {
bool V_75 = false ;
if ( F_4 ( V_873 ) & V_867 ) {
F_40 ( L_184 ) ;
V_75 = F_514 ( V_2 , V_873 , true ) ;
if ( ! V_75 && F_517 ( V_2 ) ) {
F_40 ( L_185 ) ;
F_515 ( V_2 , V_871 , V_115 ) ;
}
if ( ! V_75 && F_518 ( V_2 ) ) {
F_40 ( L_186 ) ;
F_513 ( V_2 , V_872 , V_115 ) ;
}
}
if ( F_4 ( V_873 ) & V_867 ) {
F_40 ( L_187 ) ;
V_75 = F_514 ( V_2 , V_874 , false ) ;
}
if ( ! V_75 && ( F_4 ( V_874 ) & V_867 ) ) {
if ( F_517 ( V_2 ) ) {
F_40 ( L_188 ) ;
F_515 ( V_2 , V_875 , V_117 ) ;
}
if ( F_518 ( V_2 ) ) {
F_40 ( L_189 ) ;
F_513 ( V_2 , V_870 , V_117 ) ;
}
}
if ( F_518 ( V_2 ) &&
( F_4 ( V_876 ) & V_856 ) ) {
F_40 ( L_190 ) ;
F_513 ( V_2 , V_876 , V_119 ) ;
}
} else if ( F_23 ( V_2 ) )
F_519 ( V_2 ) ;
if ( F_520 ( V_2 ) )
F_521 ( V_2 ) ;
F_150 (encoder, &dev->mode_config.encoder_list, base.head) {
V_63 -> V_210 . V_733 = V_63 -> V_805 ;
V_63 -> V_210 . V_877 =
F_505 ( V_63 ) ;
}
F_306 ( V_2 ) ;
F_522 ( V_2 ) ;
}
static void F_523 ( struct V_255 * V_256 )
{
struct V_257 * V_258 = F_139 ( V_256 ) ;
F_524 ( V_256 ) ;
F_392 ( & V_258 -> V_234 -> V_210 ) ;
F_249 ( V_258 ) ;
}
static int F_525 ( struct V_255 * V_256 ,
struct V_695 * V_696 ,
unsigned int * V_697 )
{
struct V_257 * V_258 = F_139 ( V_256 ) ;
struct V_233 * V_234 = V_258 -> V_234 ;
return F_526 ( V_696 , & V_234 -> V_210 , V_697 ) ;
}
int F_400 ( struct V_1 * V_2 ,
struct V_257 * V_258 ,
struct V_720 * V_721 ,
struct V_233 * V_234 )
{
int V_238 ;
if ( V_234 -> V_239 == V_242 ) {
F_527 ( L_191 ) ;
return - V_243 ;
}
if ( V_721 -> V_283 [ 0 ] & 63 ) {
F_527 ( L_192 ,
V_721 -> V_283 [ 0 ] ) ;
return - V_243 ;
}
if ( V_721 -> V_283 [ 0 ] > 32768 ) {
F_527 ( L_193 ,
V_721 -> V_283 [ 0 ] ) ;
return - V_243 ;
}
if ( V_234 -> V_239 != V_240 &&
V_721 -> V_283 [ 0 ] != V_234 -> V_878 ) {
F_527 ( L_194 ,
V_721 -> V_283 [ 0 ] , V_234 -> V_878 ) ;
return - V_243 ;
}
switch ( V_721 -> V_262 ) {
case V_263 :
case V_268 :
case V_270 :
case V_271 :
break;
case V_265 :
case V_266 :
if ( F_43 ( V_2 ) -> V_103 > 3 ) {
F_527 ( L_195 , V_721 -> V_262 ) ;
return - V_243 ;
}
break;
case V_273 :
case V_274 :
case V_276 :
case V_277 :
case V_279 :
case V_280 :
if ( F_43 ( V_2 ) -> V_103 < 4 ) {
F_527 ( L_195 , V_721 -> V_262 ) ;
return - V_243 ;
}
break;
case V_879 :
case V_880 :
case V_881 :
case V_882 :
if ( F_43 ( V_2 ) -> V_103 < 5 ) {
F_527 ( L_195 , V_721 -> V_262 ) ;
return - V_243 ;
}
break;
default:
F_527 ( L_196 , V_721 -> V_262 ) ;
return - V_243 ;
}
if ( V_721 -> V_797 [ 0 ] != 0 )
return - V_243 ;
F_528 ( & V_258 -> V_210 , V_721 ) ;
V_258 -> V_234 = V_234 ;
V_238 = F_529 ( V_2 , & V_258 -> V_210 , & V_883 ) ;
if ( V_238 ) {
F_10 ( L_197 , V_238 ) ;
return V_238 ;
}
return 0 ;
}
static struct V_255 *
F_530 ( struct V_1 * V_2 ,
struct V_695 * V_884 ,
struct V_720 * V_721 )
{
struct V_233 * V_234 ;
V_234 = F_386 ( F_387 ( V_2 , V_884 ,
V_721 -> V_885 [ 0 ] ) ) ;
if ( & V_234 -> V_210 == NULL )
return F_399 ( - V_700 ) ;
return F_397 ( V_2 , V_721 , V_234 ) ;
}
static void F_531 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_61 ( V_2 ) ) {
V_4 -> V_289 . V_818 = F_352 ;
V_4 -> V_289 . V_633 = F_350 ;
V_4 -> V_289 . V_430 = F_218 ;
V_4 -> V_289 . V_431 = F_225 ;
V_4 -> V_289 . V_435 = F_230 ;
V_4 -> V_289 . V_291 = F_144 ;
} else if ( F_3 ( V_2 ) ) {
V_4 -> V_289 . V_818 = F_347 ;
V_4 -> V_289 . V_633 = F_344 ;
V_4 -> V_289 . V_430 = F_210 ;
V_4 -> V_289 . V_431 = F_222 ;
V_4 -> V_289 . V_435 = F_229 ;
V_4 -> V_289 . V_291 = F_144 ;
} else {
V_4 -> V_289 . V_818 = F_302 ;
V_4 -> V_289 . V_633 = F_298 ;
V_4 -> V_289 . V_430 = F_237 ;
V_4 -> V_289 . V_431 = F_239 ;
V_4 -> V_289 . V_435 = F_240 ;
V_4 -> V_289 . V_291 = F_138 ;
}
if ( F_22 ( V_2 ) )
V_4 -> V_289 . V_555 =
F_259 ;
else if ( F_290 ( V_2 ) || ( F_292 ( V_2 ) && ! F_532 ( V_2 ) ) )
V_4 -> V_289 . V_555 =
F_260 ;
else if ( F_533 ( V_2 ) )
V_4 -> V_289 . V_555 =
F_261 ;
else if ( F_291 ( V_2 ) || F_383 ( V_2 ) || F_532 ( V_2 ) )
V_4 -> V_289 . V_555 =
F_262 ;
else if ( F_534 ( V_2 ) )
V_4 -> V_289 . V_555 =
F_263 ;
else if ( F_384 ( V_2 ) )
V_4 -> V_289 . V_555 =
F_265 ;
else if ( F_535 ( V_2 ) )
V_4 -> V_289 . V_555 =
F_266 ;
else
V_4 -> V_289 . V_555 =
F_267 ;
if ( F_3 ( V_2 ) ) {
if ( F_6 ( V_2 ) ) {
V_4 -> V_289 . V_370 = F_163 ;
V_4 -> V_289 . V_667 = F_364 ;
} else if ( F_170 ( V_2 ) ) {
V_4 -> V_289 . V_370 = F_168 ;
V_4 -> V_289 . V_667 = F_364 ;
} else if ( F_161 ( V_2 ) ) {
V_4 -> V_289 . V_370 = F_171 ;
V_4 -> V_289 . V_667 = F_364 ;
V_4 -> V_289 . V_823 =
F_162 ;
} else if ( F_145 ( V_2 ) ) {
V_4 -> V_289 . V_370 = V_886 ;
V_4 -> V_289 . V_667 = F_360 ;
V_4 -> V_289 . V_823 =
F_348 ;
}
} else if ( F_20 ( V_2 ) ) {
V_4 -> V_289 . V_667 = F_359 ;
}
V_4 -> V_289 . V_802 = F_453 ;
switch ( F_43 ( V_2 ) -> V_103 ) {
case 2 :
V_4 -> V_289 . V_802 = F_443 ;
break;
case 3 :
V_4 -> V_289 . V_802 = F_448 ;
break;
case 4 :
case 5 :
V_4 -> V_289 . V_802 = F_449 ;
break;
case 6 :
V_4 -> V_289 . V_802 = F_450 ;
break;
case 7 :
V_4 -> V_289 . V_802 = F_451 ;
break;
}
}
static void F_536 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_151 |= V_152 ;
F_537 ( L_198 ) ;
}
static void F_538 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_151 |= V_483 ;
F_537 ( L_199 ) ;
}
static void F_539 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_151 |= V_887 ;
F_537 ( L_200 ) ;
}
static int F_540 ( const struct V_888 * V_215 )
{
F_537 ( L_201 , V_215 -> V_889 ) ;
return 1 ;
}
static void F_541 ( struct V_1 * V_2 )
{
struct V_890 * V_891 = V_2 -> V_453 ;
int V_157 ;
for ( V_157 = 0 ; V_157 < F_499 ( V_892 ) ; V_157 ++ ) {
struct V_893 * V_894 = & V_892 [ V_157 ] ;
if ( V_891 -> V_895 == V_894 -> V_895 &&
( V_891 -> V_896 == V_894 -> V_896 ||
V_894 -> V_896 == V_897 ) &&
( V_891 -> V_898 == V_894 -> V_898 ||
V_894 -> V_898 == V_897 ) )
V_894 -> V_899 ( V_2 ) ;
}
for ( V_157 = 0 ; V_157 < F_499 ( V_900 ) ; V_157 ++ ) {
if ( F_542 ( * V_900 [ V_157 ] . V_901 ) != 0 )
V_900 [ V_157 ] . V_899 ( V_2 ) ;
}
}
static void F_543 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_9 V_902 ;
T_1 V_903 = F_544 ( V_2 ) ;
F_545 ( V_2 -> V_453 , V_904 ) ;
F_546 ( V_905 , V_906 ) ;
V_902 = F_547 ( V_907 ) ;
F_546 ( V_902 | 1 << 5 , V_907 ) ;
F_548 ( V_2 -> V_453 , V_904 ) ;
F_98 ( 300 ) ;
F_11 ( V_903 , V_908 ) ;
F_14 ( V_903 ) ;
}
void F_549 ( struct V_1 * V_2 )
{
F_550 ( V_2 ) ;
F_551 ( V_2 ) ;
F_552 ( V_2 ) ;
F_153 ( & V_2 -> V_306 ) ;
F_553 ( V_2 ) ;
F_154 ( & V_2 -> V_306 ) ;
}
void F_554 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_157 , V_909 , V_238 ;
F_555 ( V_2 ) ;
V_2 -> V_577 . V_910 = 0 ;
V_2 -> V_577 . V_911 = 0 ;
V_2 -> V_577 . V_912 = 24 ;
V_2 -> V_577 . V_913 = 1 ;
V_2 -> V_577 . V_732 = & V_914 ;
F_541 ( V_2 ) ;
F_556 ( V_2 ) ;
if ( F_43 ( V_2 ) -> V_305 == 0 )
return;
F_531 ( V_2 ) ;
if ( F_23 ( V_2 ) ) {
V_2 -> V_577 . V_915 = 2048 ;
V_2 -> V_577 . V_916 = 2048 ;
} else if ( F_498 ( V_2 ) ) {
V_2 -> V_577 . V_915 = 4096 ;
V_2 -> V_577 . V_916 = 4096 ;
} else {
V_2 -> V_577 . V_915 = 8192 ;
V_2 -> V_577 . V_916 = 8192 ;
}
V_2 -> V_577 . V_917 = V_4 -> V_918 . V_919 ;
F_40 ( L_202 ,
F_43 ( V_2 ) -> V_305 ,
F_43 ( V_2 ) -> V_305 > 1 ? L_203 : L_204 ) ;
for ( V_157 = 0 ; V_157 < F_43 ( V_2 ) -> V_305 ; V_157 ++ ) {
F_495 ( V_2 , V_157 ) ;
for ( V_909 = 0 ; V_909 < V_4 -> V_161 ; V_909 ++ ) {
V_238 = F_557 ( V_2 , V_157 , V_909 ) ;
if ( V_238 )
F_40 ( L_205 ,
V_157 , V_909 , V_238 ) ;
}
}
F_489 ( V_2 ) ;
F_491 ( V_2 ) ;
F_543 ( V_2 ) ;
F_507 ( V_2 ) ;
F_224 ( V_2 ) ;
}
static void
F_558 ( struct V_440 * V_433 )
{
V_433 -> V_210 . V_436 = V_437 ;
V_433 -> V_210 . V_63 = NULL ;
V_433 -> V_63 -> V_429 = false ;
V_433 -> V_63 -> V_210 . V_24 = NULL ;
}
static void F_559 ( struct V_1 * V_2 )
{
struct V_440 * V_433 ;
struct V_432 * V_920 = NULL ;
struct V_727 V_731 ;
F_150 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_433 -> V_63 -> type == V_39 ) {
V_920 = & V_433 -> V_210 ;
break;
}
}
if ( ! V_920 )
return;
if ( F_409 ( V_920 , NULL , & V_731 ) )
F_413 ( V_920 , & V_731 ) ;
}
static bool
F_560 ( struct V_97 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_10 , V_20 ;
if ( F_43 ( V_2 ) -> V_305 == 1 )
return true ;
V_10 = F_73 ( ! V_24 -> V_155 ) ;
V_20 = F_4 ( V_10 ) ;
if ( ( V_20 & V_156 ) &&
( ! ! ( V_20 & V_159 ) == V_24 -> V_95 ) )
return false ;
return true ;
}
static void F_561 ( struct V_97 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_210 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_10 ;
V_10 = F_45 ( V_24 -> V_98 . V_99 ) ;
F_11 ( V_10 , F_4 ( V_10 ) & ~ V_921 ) ;
if ( F_43 ( V_2 ) -> V_103 < 4 && ! F_560 ( V_24 ) ) {
struct V_440 * V_433 ;
bool V_155 ;
F_40 ( L_206 ,
V_24 -> V_210 . V_210 . V_215 ) ;
V_155 = V_24 -> V_155 ;
V_24 -> V_155 = ! V_155 ;
V_4 -> V_289 . V_431 ( & V_24 -> V_210 ) ;
V_24 -> V_155 = V_155 ;
F_150 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_433 -> V_63 -> V_210 . V_24 != & V_24 -> V_210 )
continue;
F_558 ( V_433 ) ;
}
F_2 ( V_24 -> V_213 ) ;
V_24 -> V_210 . V_125 = false ;
}
if ( V_4 -> V_151 & V_152 &&
V_24 -> V_95 == V_143 && ! V_24 -> V_213 ) {
F_559 ( V_2 ) ;
}
F_242 ( & V_24 -> V_210 ) ;
if ( V_24 -> V_213 != V_24 -> V_210 . V_125 ) {
struct V_62 * V_63 ;
F_40 ( L_207 ,
V_24 -> V_210 . V_210 . V_215 ,
V_24 -> V_210 . V_125 ? L_208 : L_209 ,
V_24 -> V_213 ? L_208 : L_209 ) ;
V_24 -> V_210 . V_125 = V_24 -> V_213 ;
F_2 ( V_24 -> V_213 ) ;
F_26 (dev, &crtc->base, encoder) {
F_2 ( V_63 -> V_429 ) ;
V_63 -> V_210 . V_24 = NULL ;
}
}
}
static void F_562 ( struct V_62 * V_63 )
{
struct V_440 * V_433 ;
struct V_1 * V_2 = V_63 -> V_210 . V_2 ;
bool V_922 = V_63 -> V_210 . V_24 &&
F_35 ( V_63 -> V_210 . V_24 ) -> V_213 ;
if ( V_63 -> V_429 && ! V_922 ) {
F_40 ( L_210 ,
V_63 -> V_210 . V_210 . V_215 ,
F_357 ( & V_63 -> V_210 ) ) ;
if ( V_63 -> V_210 . V_24 ) {
F_40 ( L_211 ,
V_63 -> V_210 . V_210 . V_215 ,
F_357 ( & V_63 -> V_210 ) ) ;
V_63 -> V_408 ( V_63 ) ;
}
F_150 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_433 -> V_63 != V_63 )
continue;
F_558 ( V_433 ) ;
}
}
}
void F_563 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_903 = F_544 ( V_2 ) ;
if ( F_4 ( V_903 ) != V_908 ) {
F_40 ( L_212 ) ;
F_543 ( V_2 ) ;
}
}
void F_564 ( struct V_1 * V_2 ,
bool V_923 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_95 V_95 ;
T_1 V_197 ;
struct V_924 * V_155 ;
struct V_97 * V_24 ;
struct V_62 * V_63 ;
struct V_440 * V_433 ;
if ( F_61 ( V_2 ) ) {
V_197 = F_4 ( F_62 ( V_153 ) ) ;
if ( V_197 & V_135 ) {
switch ( V_197 & V_925 ) {
case V_926 :
case V_927 :
V_95 = V_143 ;
break;
case V_928 :
V_95 = V_150 ;
break;
case V_929 :
V_95 = V_318 ;
break;
default:
F_46 ( 1 , L_213 , V_197 ) ;
F_226 ( V_4 ,
V_153 ) ;
goto V_930;
}
V_24 = F_35 ( V_4 -> V_96 [ V_95 ] ) ;
V_24 -> V_98 . V_99 = V_153 ;
F_40 ( L_214 ,
F_69 ( V_95 ) ) ;
}
}
V_930:
F_150 (crtc, &dev->mode_config.crtc_list,
base.head) {
enum V_94 V_197 = V_24 -> V_98 . V_99 ;
memset ( & V_24 -> V_98 , 0 , sizeof( V_24 -> V_98 ) ) ;
V_24 -> V_98 . V_99 = V_197 ;
V_24 -> V_213 = V_4 -> V_289 . V_818 ( V_24 ,
& V_24 -> V_98 ) ;
V_24 -> V_210 . V_125 = V_24 -> V_213 ;
F_40 ( L_215 ,
V_24 -> V_210 . V_210 . V_215 ,
V_24 -> V_213 ? L_208 : L_209 ) ;
}
if ( F_61 ( V_2 ) )
F_565 ( V_2 ) ;
F_150 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_95 = 0 ;
if ( V_63 -> V_441 ( V_63 , & V_95 ) ) {
V_63 -> V_210 . V_24 =
V_4 -> V_96 [ V_95 ] ;
} else {
V_63 -> V_210 . V_24 = NULL ;
}
V_63 -> V_429 = false ;
F_40 ( L_216 ,
V_63 -> V_210 . V_210 . V_215 ,
F_357 ( & V_63 -> V_210 ) ,
V_63 -> V_210 . V_24 ? L_208 : L_209 ,
V_95 ) ;
}
F_150 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_433 -> V_441 ( V_433 ) ) {
V_433 -> V_210 . V_436 = V_439 ;
V_433 -> V_63 -> V_429 = true ;
V_433 -> V_210 . V_63 = & V_433 -> V_63 -> V_210 ;
} else {
V_433 -> V_210 . V_436 = V_437 ;
V_433 -> V_210 . V_63 = NULL ;
}
F_40 ( L_217 ,
V_433 -> V_210 . V_210 . V_215 ,
F_252 ( & V_433 -> V_210 ) ,
V_433 -> V_210 . V_63 ? L_208 : L_209 ) ;
}
F_150 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_562 ( V_63 ) ;
}
F_566 (pipe) {
V_24 = F_35 ( V_4 -> V_96 [ V_95 ] ) ;
F_561 ( V_24 ) ;
}
if ( V_923 ) {
F_566 (pipe) {
struct V_23 * V_24 =
V_4 -> V_96 [ V_95 ] ;
F_474 ( V_24 , & V_24 -> V_357 , V_24 -> V_248 , V_24 -> V_249 ,
V_24 -> V_256 ) ;
}
F_150 (plane, &dev->mode_config.plane_list, head)
F_567 ( V_155 ) ;
F_563 ( V_2 ) ;
} else {
F_464 ( V_2 ) ;
}
F_255 ( V_2 ) ;
F_568 ( V_2 ) ;
}
void F_569 ( struct V_1 * V_2 )
{
F_549 ( V_2 ) ;
F_570 ( V_2 ) ;
F_564 ( V_2 , false ) ;
}
void F_571 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_23 * V_24 ;
struct V_97 * V_97 ;
F_572 ( V_2 ) ;
F_153 ( & V_2 -> V_306 ) ;
F_573 () ;
F_150 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_24 -> V_256 )
continue;
V_97 = F_35 ( V_24 ) ;
F_148 ( V_24 ) ;
}
F_224 ( V_2 ) ;
F_574 ( V_2 ) ;
F_575 ( V_2 ) ;
if ( F_22 ( V_2 ) )
F_13 ( V_2 ) ;
F_154 ( & V_2 -> V_306 ) ;
F_576 ( V_2 ) ;
F_426 ( & V_4 -> V_931 ) ;
F_426 ( & V_4 -> V_932 . V_765 ) ;
F_577 () ;
F_578 ( V_2 ) ;
F_579 ( V_2 ) ;
F_580 ( V_2 ) ;
}
struct V_438 * F_581 ( struct V_432 * V_433 )
{
return & F_254 ( V_433 ) -> V_210 ;
}
void F_582 ( struct V_440 * V_433 ,
struct V_62 * V_63 )
{
V_433 -> V_63 = V_63 ;
F_583 ( & V_433 -> V_210 ,
& V_63 -> V_210 ) ;
}
int F_584 ( struct V_1 * V_2 , bool V_126 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_933 ;
F_264 ( V_4 -> V_934 , V_935 , & V_933 ) ;
if ( V_126 )
V_933 &= ~ V_936 ;
else
V_933 |= V_936 ;
F_585 ( V_4 -> V_934 , V_935 , V_933 ) ;
return 0 ;
}
struct V_937 *
F_586 ( struct V_1 * V_2 )
{
T_8 * V_4 = V_2 -> V_5 ;
struct V_937 * error ;
enum V_94 V_99 ;
int V_157 ;
error = F_475 ( sizeof( * error ) , V_938 ) ;
if ( error == NULL )
return NULL ;
F_566 (i) {
V_99 = F_34 ( V_4 , V_157 ) ;
if ( F_43 ( V_2 ) -> V_103 <= 6 || F_22 ( V_2 ) ) {
error -> V_939 [ V_157 ] . V_940 = F_4 ( F_235 ( V_157 ) ) ;
error -> V_939 [ V_157 ] . V_941 = F_4 ( F_382 ( V_157 ) ) ;
error -> V_939 [ V_157 ] . V_210 = F_4 ( F_236 ( V_157 ) ) ;
} else {
error -> V_939 [ V_157 ] . V_940 = F_4 ( F_379 ( V_157 ) ) ;
error -> V_939 [ V_157 ] . V_941 = F_4 ( F_381 ( V_157 ) ) ;
error -> V_939 [ V_157 ] . V_210 = F_4 ( F_380 ( V_157 ) ) ;
}
error -> V_155 [ V_157 ] . V_940 = F_4 ( F_73 ( V_157 ) ) ;
error -> V_155 [ V_157 ] . V_878 = F_4 ( F_140 ( V_157 ) ) ;
if ( F_43 ( V_2 ) -> V_103 <= 3 ) {
error -> V_155 [ V_157 ] . V_701 = F_4 ( F_300 ( V_157 ) ) ;
error -> V_155 [ V_157 ] . V_686 = F_4 ( F_301 ( V_157 ) ) ;
}
if ( F_43 ( V_2 ) -> V_103 <= 7 && ! F_145 ( V_2 ) )
error -> V_155 [ V_157 ] . V_698 = F_4 ( F_121 ( V_157 ) ) ;
if ( F_43 ( V_2 ) -> V_103 >= 4 ) {
error -> V_155 [ V_157 ] . V_942 = F_4 ( F_120 ( V_157 ) ) ;
error -> V_155 [ V_157 ] . V_943 = F_4 ( F_142 ( V_157 ) ) ;
}
error -> V_95 [ V_157 ] . V_944 = F_4 ( F_45 ( V_99 ) ) ;
error -> V_95 [ V_157 ] . V_945 = F_4 ( F_295 ( V_157 ) ) ;
error -> V_95 [ V_157 ] . V_758 = F_4 ( F_192 ( V_99 ) ) ;
error -> V_95 [ V_157 ] . V_946 = F_4 ( F_194 ( V_99 ) ) ;
error -> V_95 [ V_157 ] . V_755 = F_4 ( F_196 ( V_99 ) ) ;
error -> V_95 [ V_157 ] . V_760 = F_4 ( F_198 ( V_99 ) ) ;
error -> V_95 [ V_157 ] . V_947 = F_4 ( F_200 ( V_99 ) ) ;
error -> V_95 [ V_157 ] . V_757 = F_4 ( F_202 ( V_99 ) ) ;
}
return error ;
}
void
F_587 ( struct V_948 * V_53 ,
struct V_1 * V_2 ,
struct V_937 * error )
{
int V_157 ;
F_588 ( V_53 , L_218 , F_43 ( V_2 ) -> V_305 ) ;
F_566 (i) {
F_588 ( V_53 , L_219 , V_157 ) ;
F_588 ( V_53 , L_220 , error -> V_95 [ V_157 ] . V_944 ) ;
F_588 ( V_53 , L_221 , error -> V_95 [ V_157 ] . V_945 ) ;
F_588 ( V_53 , L_222 , error -> V_95 [ V_157 ] . V_758 ) ;
F_588 ( V_53 , L_223 , error -> V_95 [ V_157 ] . V_946 ) ;
F_588 ( V_53 , L_224 , error -> V_95 [ V_157 ] . V_755 ) ;
F_588 ( V_53 , L_225 , error -> V_95 [ V_157 ] . V_760 ) ;
F_588 ( V_53 , L_226 , error -> V_95 [ V_157 ] . V_947 ) ;
F_588 ( V_53 , L_227 , error -> V_95 [ V_157 ] . V_757 ) ;
F_588 ( V_53 , L_228 , V_157 ) ;
F_588 ( V_53 , L_229 , error -> V_155 [ V_157 ] . V_940 ) ;
F_588 ( V_53 , L_230 , error -> V_155 [ V_157 ] . V_878 ) ;
if ( F_43 ( V_2 ) -> V_103 <= 3 ) {
F_588 ( V_53 , L_231 , error -> V_155 [ V_157 ] . V_701 ) ;
F_588 ( V_53 , L_232 , error -> V_155 [ V_157 ] . V_686 ) ;
}
if ( F_43 ( V_2 ) -> V_103 <= 7 && ! F_145 ( V_2 ) )
F_588 ( V_53 , L_233 , error -> V_155 [ V_157 ] . V_698 ) ;
if ( F_43 ( V_2 ) -> V_103 >= 4 ) {
F_588 ( V_53 , L_234 , error -> V_155 [ V_157 ] . V_942 ) ;
F_588 ( V_53 , L_235 , error -> V_155 [ V_157 ] . V_943 ) ;
}
F_588 ( V_53 , L_236 , V_157 ) ;
F_588 ( V_53 , L_229 , error -> V_939 [ V_157 ] . V_940 ) ;
F_588 ( V_53 , L_232 , error -> V_939 [ V_157 ] . V_941 ) ;
F_588 ( V_53 , L_237 , error -> V_939 [ V_157 ] . V_210 ) ;
}
}
