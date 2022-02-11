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
unsigned long V_11 ;
T_1 V_12 = 0 ;
F_8 ( & V_4 -> V_13 , V_11 ) ;
if ( F_9 ( ( F_4 ( V_14 ) & V_15 ) == 0 , 100 ) ) {
F_10 ( L_1 ) ;
goto V_16;
}
F_11 ( V_17 , V_10 ) ;
F_11 ( V_14 , V_18 | V_19 | V_20 |
V_21 ) ;
if ( F_9 ( ( F_4 ( V_14 ) & V_15 ) == 0 , 100 ) ) {
F_10 ( L_2 ) ;
goto V_16;
}
V_12 = F_4 ( V_22 ) ;
V_16:
F_12 ( & V_4 -> V_13 , V_11 ) ;
return V_12 ;
}
static void F_13 ( struct V_3 * V_4 , int V_10 ,
T_1 V_12 )
{
unsigned long V_11 ;
F_8 ( & V_4 -> V_13 , V_11 ) ;
if ( F_9 ( ( F_4 ( V_14 ) & V_15 ) == 0 , 100 ) ) {
F_10 ( L_1 ) ;
goto V_16;
}
F_11 ( V_22 , V_12 ) ;
F_11 ( V_17 , V_10 ) ;
F_11 ( V_14 , V_18 | V_23 | V_20 |
V_21 ) ;
if ( F_9 ( ( F_4 ( V_14 ) & V_15 ) == 0 , 100 ) )
F_10 ( L_3 ) ;
V_16:
F_12 ( & V_4 -> V_13 , V_11 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_11 ( V_24 , 0 ) ;
F_15 ( V_24 ) ;
F_11 ( V_24 , 1 ) ;
F_15 ( V_24 ) ;
}
static int F_16 ( const struct V_25 * V_26 )
{
F_17 ( L_4 , V_26 -> V_27 ) ;
return 1 ;
}
static bool F_18 ( struct V_3 * V_4 ,
unsigned int V_10 )
{
unsigned int V_12 ;
if ( V_28 > 0 )
return V_28 == 2 ;
if ( F_19 ( V_29 ) )
return true ;
if ( V_4 -> V_30 )
V_12 = V_4 -> V_30 ;
else {
V_12 = F_4 ( V_10 ) ;
if ( ! ( V_12 & ~ ( V_31 | V_32 ) ) )
V_12 = V_4 -> V_33 ;
V_4 -> V_30 = V_12 ;
}
return ( V_12 & V_34 ) == V_35 ;
}
static const T_2 * F_20 ( struct V_36 * V_37 ,
int V_38 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const T_2 * V_39 ;
if ( F_21 ( V_37 , V_40 ) ) {
if ( F_18 ( V_4 , V_41 ) ) {
if ( V_38 == 100000 )
V_39 = & V_42 ;
else
V_39 = & V_43 ;
} else {
if ( V_38 == 100000 )
V_39 = & V_44 ;
else
V_39 = & V_45 ;
}
} else if ( F_21 ( V_37 , V_46 ) ||
F_21 ( V_37 , V_47 ) )
V_39 = & V_48 ;
else
V_39 = & V_49 ;
return V_39 ;
}
static const T_2 * F_22 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const T_2 * V_39 ;
if ( F_21 ( V_37 , V_40 ) ) {
if ( F_18 ( V_4 , V_50 ) )
V_39 = & V_51 ;
else
V_39 = & V_52 ;
} else if ( F_21 ( V_37 , V_53 ) ||
F_21 ( V_37 , V_54 ) ) {
V_39 = & V_55 ;
} else if ( F_21 ( V_37 , V_56 ) ) {
V_39 = & V_57 ;
} else if ( F_21 ( V_37 , V_46 ) ) {
V_39 = & V_58 ;
} else
V_39 = & V_59 ;
return V_39 ;
}
static const T_2 * F_23 ( struct V_36 * V_37 , int V_38 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
const T_2 * V_39 ;
if ( F_3 ( V_2 ) )
V_39 = F_20 ( V_37 , V_38 ) ;
else if ( F_24 ( V_2 ) ) {
V_39 = F_22 ( V_37 ) ;
} else if ( F_25 ( V_2 ) ) {
if ( F_21 ( V_37 , V_40 ) )
V_39 = & V_60 ;
else
V_39 = & V_61 ;
} else if ( F_26 ( V_2 ) ) {
if ( F_21 ( V_37 , V_54 ) )
V_39 = & V_62 ;
else if ( F_21 ( V_37 , V_53 ) )
V_39 = & V_63 ;
else
V_39 = & V_64 ;
} else if ( ! F_27 ( V_2 ) ) {
if ( F_21 ( V_37 , V_40 ) )
V_39 = & V_65 ;
else
V_39 = & V_59 ;
} else {
if ( F_21 ( V_37 , V_40 ) )
V_39 = & V_66 ;
else
V_39 = & V_67 ;
}
return V_39 ;
}
static void F_28 ( int V_38 , T_3 * clock )
{
clock -> V_68 = clock -> V_69 + 2 ;
clock -> V_70 = clock -> V_71 * clock -> V_72 ;
clock -> V_73 = V_38 * clock -> V_68 / clock -> V_74 ;
clock -> V_75 = clock -> V_73 / clock -> V_70 ;
}
static void F_29 ( struct V_1 * V_2 , int V_38 , T_3 * clock )
{
if ( F_25 ( V_2 ) ) {
F_28 ( V_38 , clock ) ;
return;
}
clock -> V_68 = 5 * ( clock -> V_76 + 2 ) + ( clock -> V_69 + 2 ) ;
clock -> V_70 = clock -> V_71 * clock -> V_72 ;
clock -> V_73 = V_38 * clock -> V_68 / ( clock -> V_74 + 2 ) ;
clock -> V_75 = clock -> V_73 / clock -> V_70 ;
}
bool F_21 ( struct V_36 * V_37 , int type )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_77 * V_78 ;
F_30 (dev, crtc, encoder)
if ( V_78 -> type == type )
return true ;
return false ;
}
static bool F_31 ( struct V_1 * V_2 ,
const T_2 * V_39 ,
const T_3 * clock )
{
if ( clock -> V_71 < V_39 -> V_71 . V_79 || V_39 -> V_71 . V_80 < clock -> V_71 )
F_32 ( L_5 ) ;
if ( clock -> V_70 < V_39 -> V_70 . V_79 || V_39 -> V_70 . V_80 < clock -> V_70 )
F_32 ( L_6 ) ;
if ( clock -> V_69 < V_39 -> V_69 . V_79 || V_39 -> V_69 . V_80 < clock -> V_69 )
F_32 ( L_7 ) ;
if ( clock -> V_76 < V_39 -> V_76 . V_79 || V_39 -> V_76 . V_80 < clock -> V_76 )
F_32 ( L_8 ) ;
if ( clock -> V_76 <= clock -> V_69 && ! F_25 ( V_2 ) )
F_32 ( L_9 ) ;
if ( clock -> V_68 < V_39 -> V_68 . V_79 || V_39 -> V_68 . V_80 < clock -> V_68 )
F_32 ( L_10 ) ;
if ( clock -> V_74 < V_39 -> V_74 . V_79 || V_39 -> V_74 . V_80 < clock -> V_74 )
F_32 ( L_11 ) ;
if ( clock -> V_73 < V_39 -> V_73 . V_79 || V_39 -> V_73 . V_80 < clock -> V_73 )
F_32 ( L_12 ) ;
if ( clock -> V_75 < V_39 -> V_75 . V_79 || V_39 -> V_75 . V_80 < clock -> V_75 )
F_32 ( L_13 ) ;
return true ;
}
static bool
F_33 ( const T_2 * V_39 , struct V_36 * V_37 ,
int V_81 , int V_38 , T_3 * V_82 ,
T_3 * V_83 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 clock ;
int V_84 = V_81 ;
if ( F_21 ( V_37 , V_40 ) &&
( F_4 ( V_50 ) ) != 0 ) {
if ( F_18 ( V_4 , V_50 ) )
clock . V_72 = V_39 -> V_72 . V_85 ;
else
clock . V_72 = V_39 -> V_72 . V_86 ;
} else {
if ( V_81 < V_39 -> V_72 . V_87 )
clock . V_72 = V_39 -> V_72 . V_86 ;
else
clock . V_72 = V_39 -> V_72 . V_85 ;
}
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
for ( clock . V_76 = V_39 -> V_76 . V_79 ; clock . V_76 <= V_39 -> V_76 . V_80 ;
clock . V_76 ++ ) {
for ( clock . V_69 = V_39 -> V_69 . V_79 ;
clock . V_69 <= V_39 -> V_69 . V_80 ; clock . V_69 ++ ) {
if ( clock . V_69 >= clock . V_76 && ! F_25 ( V_2 ) )
break;
for ( clock . V_74 = V_39 -> V_74 . V_79 ;
clock . V_74 <= V_39 -> V_74 . V_80 ; clock . V_74 ++ ) {
for ( clock . V_71 = V_39 -> V_71 . V_79 ;
clock . V_71 <= V_39 -> V_71 . V_80 ; clock . V_71 ++ ) {
int V_88 ;
F_29 ( V_2 , V_38 , & clock ) ;
if ( ! F_31 ( V_2 , V_39 ,
& clock ) )
continue;
if ( V_82 &&
clock . V_70 != V_82 -> V_70 )
continue;
V_88 = abs ( clock . V_75 - V_81 ) ;
if ( V_88 < V_84 ) {
* V_83 = clock ;
V_84 = V_88 ;
}
}
}
}
}
return ( V_84 != V_81 ) ;
}
static bool
F_34 ( const T_2 * V_39 , struct V_36 * V_37 ,
int V_81 , int V_38 , T_3 * V_82 ,
T_3 * V_83 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 clock ;
int V_89 ;
bool V_90 ;
int V_91 = ( V_81 >> 8 ) + ( V_81 >> 9 ) ;
V_90 = false ;
if ( F_21 ( V_37 , V_40 ) ) {
int V_92 ;
if ( F_3 ( V_2 ) )
V_92 = V_41 ;
else
V_92 = V_50 ;
if ( ( F_4 ( V_92 ) & V_34 ) ==
V_35 )
clock . V_72 = V_39 -> V_72 . V_85 ;
else
clock . V_72 = V_39 -> V_72 . V_86 ;
} else {
if ( V_81 < V_39 -> V_72 . V_87 )
clock . V_72 = V_39 -> V_72 . V_86 ;
else
clock . V_72 = V_39 -> V_72 . V_85 ;
}
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_89 = V_39 -> V_74 . V_80 ;
for ( clock . V_74 = V_39 -> V_74 . V_79 ; clock . V_74 <= V_89 ; clock . V_74 ++ ) {
for ( clock . V_76 = V_39 -> V_76 . V_80 ;
clock . V_76 >= V_39 -> V_76 . V_79 ; clock . V_76 -- ) {
for ( clock . V_69 = V_39 -> V_69 . V_80 ;
clock . V_69 >= V_39 -> V_69 . V_79 ; clock . V_69 -- ) {
for ( clock . V_71 = V_39 -> V_71 . V_80 ;
clock . V_71 >= V_39 -> V_71 . V_79 ; clock . V_71 -- ) {
int V_88 ;
F_29 ( V_2 , V_38 , & clock ) ;
if ( ! F_31 ( V_2 , V_39 ,
& clock ) )
continue;
if ( V_82 &&
clock . V_70 != V_82 -> V_70 )
continue;
V_88 = abs ( clock . V_75 - V_81 ) ;
if ( V_88 < V_91 ) {
* V_83 = clock ;
V_91 = V_88 ;
V_89 = clock . V_74 ;
V_90 = true ;
}
}
}
}
}
return V_90 ;
}
static bool
F_35 ( const T_2 * V_39 , struct V_36 * V_37 ,
int V_81 , int V_38 , T_3 * V_82 ,
T_3 * V_83 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
T_3 clock ;
if ( V_81 < 200000 ) {
clock . V_74 = 1 ;
clock . V_71 = 2 ;
clock . V_72 = 10 ;
clock . V_76 = 12 ;
clock . V_69 = 9 ;
} else {
clock . V_74 = 2 ;
clock . V_71 = 1 ;
clock . V_72 = 10 ;
clock . V_76 = 14 ;
clock . V_69 = 8 ;
}
F_29 ( V_2 , V_38 , & clock ) ;
memcpy ( V_83 , & clock , sizeof( T_3 ) ) ;
return true ;
}
static bool
F_36 ( const T_2 * V_39 , struct V_36 * V_37 ,
int V_81 , int V_38 , T_3 * V_82 ,
T_3 * V_83 )
{
T_3 clock ;
if ( V_81 < 200000 ) {
clock . V_71 = 2 ;
clock . V_72 = 10 ;
clock . V_74 = 2 ;
clock . V_76 = 23 ;
clock . V_69 = 8 ;
} else {
clock . V_71 = 1 ;
clock . V_72 = 10 ;
clock . V_74 = 1 ;
clock . V_76 = 14 ;
clock . V_69 = 2 ;
}
clock . V_68 = 5 * ( clock . V_76 + 2 ) + ( clock . V_69 + 2 ) ;
clock . V_70 = ( clock . V_71 * clock . V_72 ) ;
clock . V_75 = 96000 * clock . V_68 / ( clock . V_74 + 2 ) / clock . V_70 ;
clock . V_73 = 0 ;
memcpy ( V_83 , & clock , sizeof( T_3 ) ) ;
return true ;
}
static bool
F_37 ( const T_2 * V_39 , struct V_36 * V_37 ,
int V_81 , int V_38 , T_3 * V_82 ,
T_3 * V_83 )
{
T_1 V_71 , V_72 , V_76 , V_69 , V_73 , V_93 , V_94 , V_95 , V_96 , V_97 ;
T_1 V_68 , V_74 , V_98 ;
T_1 V_99 , V_100 , V_101 , V_70 ;
unsigned long V_102 , V_103 , V_104 ;
int V_105 , V_106 ;
V_106 = 0 ;
V_105 = V_81 * 1000 ;
V_102 = 1000000 ;
V_103 = V_104 = 0 ;
V_98 = V_105 / ( 2 * 100 ) ;
V_99 = 0 ;
V_100 = 19200 ;
V_101 = 1 ;
V_74 = V_70 = V_71 = V_72 = V_68 = V_76 = V_69 = V_73 = V_93 = 0 ;
V_94 = V_95 = V_96 = V_97 = 0 ;
for ( V_74 = V_39 -> V_74 . V_79 ; V_74 <= ( ( V_38 ) / V_100 ) ; V_74 ++ ) {
V_99 = V_38 / V_74 ;
for ( V_71 = V_39 -> V_71 . V_80 ; V_71 > V_39 -> V_71 . V_79 ; V_71 -- ) {
for ( V_72 = V_39 -> V_72 . V_85 + 1 ; V_72 > 0 ; V_72 -- ) {
if ( V_72 > 10 )
V_72 = V_72 - 1 ;
V_70 = V_71 * V_72 ;
for ( V_76 = V_39 -> V_76 . V_79 ; V_76 <= V_39 -> V_76 . V_80 ; V_76 ++ ) {
V_69 = ( ( ( 2 * ( V_98 * V_70 * V_74 / V_76 ) ) +
V_38 ) / ( 2 * V_38 ) ) ;
V_68 = V_76 * V_69 ;
V_73 = V_99 * V_68 ;
if ( V_73 >= V_39 -> V_73 . V_79 && V_73 < V_39 -> V_73 . V_80 ) {
V_103 = 1000000 * ( ( V_73 / V_70 ) - V_98 ) / V_98 ;
V_104 = ( V_103 > 0 ) ? V_103 : ( - V_103 ) ;
if ( V_104 < 100 && ( ( V_71 * V_72 ) > ( V_96 * V_97 ) ) ) {
V_102 = 0 ;
V_106 = 1 ;
}
if ( V_104 < V_102 - 10 ) {
V_102 = V_104 ;
V_106 = 1 ;
}
if ( V_106 ) {
V_93 = V_74 ;
V_94 = V_76 ;
V_95 = V_69 ;
V_96 = V_71 ;
V_97 = V_72 ;
V_106 = 0 ;
}
}
}
}
}
}
V_83 -> V_74 = V_93 ;
V_83 -> V_76 = V_94 ;
V_83 -> V_69 = V_95 ;
V_83 -> V_71 = V_96 ;
V_83 -> V_72 = V_97 ;
return true ;
}
enum V_107 F_38 ( struct V_3 * V_4 ,
enum V_108 V_108 )
{
struct V_36 * V_37 = V_4 -> V_109 [ V_108 ] ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
return V_110 -> V_111 ;
}
static void F_40 ( struct V_1 * V_2 , int V_108 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_112 , V_113 = F_41 ( V_108 ) ;
V_112 = F_4 ( V_113 ) ;
if ( F_42 ( F_43 ( V_113 ) != V_112 , 50 ) )
F_44 ( L_14 ) ;
}
void F_45 ( struct V_1 * V_2 , int V_108 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_114 = F_46 ( V_108 ) ;
if ( F_47 ( V_2 ) -> V_115 >= 5 ) {
F_40 ( V_2 , V_108 ) ;
return;
}
F_11 ( V_114 ,
F_4 ( V_114 ) | V_116 ) ;
if ( F_42 ( F_4 ( V_114 ) &
V_116 ,
50 ) )
F_44 ( L_14 ) ;
}
void F_48 ( struct V_1 * V_2 , int V_108 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_107 V_111 = F_38 ( V_4 ,
V_108 ) ;
if ( F_47 ( V_2 ) -> V_115 >= 4 ) {
int V_10 = F_49 ( V_111 ) ;
if ( F_42 ( ( F_4 ( V_10 ) & V_117 ) == 0 ,
100 ) )
F_50 ( 1 , L_15 ) ;
} else {
T_1 V_118 , V_119 ;
int V_10 = F_51 ( V_108 ) ;
unsigned long V_120 = V_121 + F_52 ( 100 ) ;
if ( F_27 ( V_2 ) )
V_119 = V_122 ;
else
V_119 = V_123 ;
do {
V_118 = F_4 ( V_10 ) & V_119 ;
F_53 ( 5 ) ;
} while ( ( ( F_4 ( V_10 ) & V_119 ) != V_118 ) &&
F_54 ( V_120 , V_121 ) );
if ( F_54 ( V_121 , V_120 ) )
F_50 ( 1 , L_15 ) ;
}
}
static const char * F_55 ( bool V_124 )
{
return V_124 ? L_16 : L_17 ;
}
static void F_56 ( struct V_3 * V_4 ,
enum V_108 V_108 , bool V_125 )
{
int V_10 ;
T_1 V_12 ;
bool V_126 ;
V_10 = F_57 ( V_108 ) ;
V_12 = F_4 ( V_10 ) ;
V_126 = ! ! ( V_12 & V_127 ) ;
F_50 ( V_126 != V_125 ,
L_18 ,
F_55 ( V_125 ) , F_55 ( V_126 ) ) ;
}
static void F_58 ( struct V_3 * V_4 ,
struct V_128 * V_129 ,
struct V_110 * V_37 ,
bool V_125 )
{
T_1 V_12 ;
bool V_126 ;
if ( F_59 ( V_4 -> V_2 ) ) {
F_60 ( L_19 ) ;
return;
}
if ( F_50 ( ! V_129 ,
L_20 , F_55 ( V_125 ) ) )
return;
V_12 = F_4 ( V_129 -> V_130 ) ;
V_126 = ! ! ( V_12 & V_127 ) ;
F_50 ( V_126 != V_125 ,
L_21 ,
V_129 -> V_130 , F_55 ( V_125 ) , F_55 ( V_126 ) , V_12 ) ;
if ( V_37 && F_61 ( V_4 -> V_2 ) ) {
T_1 V_131 ;
V_131 = F_4 ( V_132 ) ;
V_126 = V_129 -> V_130 == V_133 ;
if ( ! F_50 ( ( ( V_131 >> ( 4 * V_37 -> V_108 ) ) & 1 ) != V_126 ,
L_22 ,
V_126 , V_37 -> V_108 , V_131 ) ) {
V_126 = ! ! ( V_12 >> ( 4 * V_37 -> V_108 + 3 ) ) ;
F_50 ( V_126 != V_125 ,
L_23 ,
V_129 -> V_130 == V_133 ,
F_55 ( V_125 ) ,
V_37 -> V_108 ,
V_12 ) ;
}
}
}
static void F_62 ( struct V_3 * V_4 ,
enum V_108 V_108 , bool V_125 )
{
int V_10 ;
T_1 V_12 ;
bool V_126 ;
enum V_107 V_111 = F_38 ( V_4 ,
V_108 ) ;
if ( F_63 ( V_4 -> V_2 ) ) {
V_10 = F_64 ( V_111 ) ;
V_12 = F_4 ( V_10 ) ;
V_126 = ! ! ( V_12 & V_134 ) ;
} else {
V_10 = F_65 ( V_108 ) ;
V_12 = F_4 ( V_10 ) ;
V_126 = ! ! ( V_12 & V_135 ) ;
}
F_50 ( V_126 != V_125 ,
L_24 ,
F_55 ( V_125 ) , F_55 ( V_126 ) ) ;
}
static void F_66 ( struct V_3 * V_4 ,
enum V_108 V_108 , bool V_125 )
{
int V_10 ;
T_1 V_12 ;
bool V_126 ;
V_10 = F_67 ( V_108 ) ;
V_12 = F_4 ( V_10 ) ;
V_126 = ! ! ( V_12 & V_136 ) ;
F_50 ( V_126 != V_125 ,
L_25 ,
F_55 ( V_125 ) , F_55 ( V_126 ) ) ;
}
static void F_68 ( struct V_3 * V_4 ,
enum V_108 V_108 )
{
int V_10 ;
T_1 V_12 ;
if ( V_4 -> V_137 -> V_115 == 5 )
return;
if ( F_63 ( V_4 -> V_2 ) )
return;
V_10 = F_65 ( V_108 ) ;
V_12 = F_4 ( V_10 ) ;
F_50 ( ! ( V_12 & V_138 ) , L_26 ) ;
}
static void F_69 ( struct V_3 * V_4 ,
enum V_108 V_108 )
{
int V_10 ;
T_1 V_12 ;
V_10 = F_67 ( V_108 ) ;
V_12 = F_4 ( V_10 ) ;
F_50 ( ! ( V_12 & V_139 ) , L_27 ) ;
}
static void F_70 ( struct V_3 * V_4 ,
enum V_108 V_108 )
{
int V_140 , V_92 ;
T_1 V_12 ;
enum V_108 V_141 = V_142 ;
bool V_143 = true ;
if ( F_3 ( V_4 -> V_2 ) ) {
V_140 = V_144 ;
V_92 = V_41 ;
} else {
V_140 = V_145 ;
V_92 = V_50 ;
}
V_12 = F_4 ( V_140 ) ;
if ( ! ( V_12 & V_146 ) ||
( ( V_12 & V_147 ) == V_147 ) )
V_143 = false ;
if ( F_4 ( V_92 ) & V_148 )
V_141 = V_149 ;
F_50 ( V_141 == V_108 && V_143 ,
L_28 ,
F_71 ( V_108 ) ) ;
}
void F_72 ( struct V_3 * V_4 ,
enum V_108 V_108 , bool V_125 )
{
int V_10 ;
T_1 V_12 ;
bool V_126 ;
enum V_107 V_111 = F_38 ( V_4 ,
V_108 ) ;
if ( V_108 == V_142 && V_4 -> V_150 & V_151 )
V_125 = true ;
V_10 = F_49 ( V_111 ) ;
V_12 = F_4 ( V_10 ) ;
V_126 = ! ! ( V_12 & V_152 ) ;
F_50 ( V_126 != V_125 ,
L_29 ,
F_71 ( V_108 ) , F_55 ( V_125 ) , F_55 ( V_126 ) ) ;
}
static void F_73 ( struct V_3 * V_4 ,
enum V_153 V_153 , bool V_125 )
{
int V_10 ;
T_1 V_12 ;
bool V_126 ;
V_10 = F_74 ( V_153 ) ;
V_12 = F_4 ( V_10 ) ;
V_126 = ! ! ( V_12 & V_154 ) ;
F_50 ( V_126 != V_125 ,
L_30 ,
F_75 ( V_153 ) , F_55 ( V_125 ) , F_55 ( V_126 ) ) ;
}
static void F_76 ( struct V_3 * V_4 ,
enum V_108 V_108 )
{
int V_10 , V_155 ;
T_1 V_12 ;
int V_156 ;
if ( F_3 ( V_4 -> V_2 ) ) {
V_10 = F_74 ( V_108 ) ;
V_12 = F_4 ( V_10 ) ;
F_50 ( ( V_12 & V_154 ) ,
L_31 ,
F_75 ( V_108 ) ) ;
return;
}
for ( V_155 = 0 ; V_155 < 2 ; V_155 ++ ) {
V_10 = F_74 ( V_155 ) ;
V_12 = F_4 ( V_10 ) ;
V_156 = ( V_12 & V_157 ) >>
V_158 ;
F_50 ( ( V_12 & V_154 ) && V_108 == V_156 ,
L_32 ,
F_75 ( V_155 ) , F_71 ( V_108 ) ) ;
}
}
static void F_77 ( struct V_3 * V_4 )
{
T_1 V_12 ;
bool V_124 ;
if ( F_59 ( V_4 -> V_2 ) ) {
F_60 ( L_33 ) ;
return;
}
V_12 = F_4 ( V_159 ) ;
V_124 = ! ! ( V_12 & ( V_160 | V_161 |
V_162 ) ) ;
F_50 ( ! V_124 , L_34 ) ;
}
static void F_78 ( struct V_3 * V_4 ,
enum V_108 V_108 )
{
int V_10 ;
T_1 V_12 ;
bool V_124 ;
V_10 = F_79 ( V_108 ) ;
V_12 = F_4 ( V_10 ) ;
V_124 = ! ! ( V_12 & V_163 ) ;
F_50 ( V_124 ,
L_35 ,
F_71 ( V_108 ) ) ;
}
static bool F_80 ( struct V_3 * V_4 ,
enum V_108 V_108 , T_1 V_164 , T_1 V_12 )
{
if ( ( V_12 & V_165 ) == 0 )
return false ;
if ( F_61 ( V_4 -> V_2 ) ) {
T_1 V_166 = F_81 ( V_108 ) ;
T_1 V_167 = F_4 ( V_166 ) ;
if ( ( V_167 & V_168 ) != V_164 )
return false ;
} else {
if ( ( V_12 & V_169 ) != ( V_108 << 30 ) )
return false ;
}
return true ;
}
static bool F_82 ( struct V_3 * V_4 ,
enum V_108 V_108 , T_1 V_12 )
{
if ( ( V_12 & V_170 ) == 0 )
return false ;
if ( F_61 ( V_4 -> V_2 ) ) {
if ( ( V_12 & V_171 ) != F_83 ( V_108 ) )
return false ;
} else {
if ( ( V_12 & V_172 ) != F_84 ( V_108 ) )
return false ;
}
return true ;
}
static bool F_85 ( struct V_3 * V_4 ,
enum V_108 V_108 , T_1 V_12 )
{
if ( ( V_12 & V_173 ) == 0 )
return false ;
if ( F_61 ( V_4 -> V_2 ) ) {
if ( ( V_12 & V_171 ) != F_83 ( V_108 ) )
return false ;
} else {
if ( ( V_12 & V_31 ) != F_86 ( V_108 ) )
return false ;
}
return true ;
}
static bool F_87 ( struct V_3 * V_4 ,
enum V_108 V_108 , T_1 V_12 )
{
if ( ( V_12 & V_174 ) == 0 )
return false ;
if ( F_61 ( V_4 -> V_2 ) ) {
if ( ( V_12 & V_171 ) != F_83 ( V_108 ) )
return false ;
} else {
if ( ( V_12 & V_175 ) != F_88 ( V_108 ) )
return false ;
}
return true ;
}
static void F_89 ( struct V_3 * V_4 ,
enum V_108 V_108 , int V_10 , T_1 V_164 )
{
T_1 V_12 = F_4 ( V_10 ) ;
F_50 ( F_80 ( V_4 , V_108 , V_164 , V_12 ) ,
L_36 ,
V_10 , F_71 ( V_108 ) ) ;
F_50 ( F_90 ( V_4 -> V_2 ) && ( V_12 & V_165 ) == 0
&& ( V_12 & V_176 ) ,
L_37 ) ;
}
static void F_91 ( struct V_3 * V_4 ,
enum V_108 V_108 , int V_10 )
{
T_1 V_12 = F_4 ( V_10 ) ;
F_50 ( F_82 ( V_4 , V_108 , V_12 ) ,
L_38 ,
V_10 , F_71 ( V_108 ) ) ;
F_50 ( F_90 ( V_4 -> V_2 ) && ( V_12 & V_170 ) == 0
&& ( V_12 & V_177 ) ,
L_39 ) ;
}
static void F_92 ( struct V_3 * V_4 ,
enum V_108 V_108 )
{
int V_10 ;
T_1 V_12 ;
F_89 ( V_4 , V_108 , V_178 , V_179 ) ;
F_89 ( V_4 , V_108 , V_180 , V_181 ) ;
F_89 ( V_4 , V_108 , V_182 , V_183 ) ;
V_10 = V_184 ;
V_12 = F_4 ( V_10 ) ;
F_50 ( F_87 ( V_4 , V_108 , V_12 ) ,
L_40 ,
F_71 ( V_108 ) ) ;
V_10 = V_41 ;
V_12 = F_4 ( V_10 ) ;
F_50 ( F_85 ( V_4 , V_108 , V_12 ) ,
L_41 ,
F_71 ( V_108 ) ) ;
F_91 ( V_4 , V_108 , V_185 ) ;
F_91 ( V_4 , V_108 , V_186 ) ;
F_91 ( V_4 , V_108 , V_187 ) ;
}
static void F_93 ( struct V_3 * V_4 , enum V_108 V_108 )
{
int V_10 ;
T_1 V_12 ;
F_94 ( ! F_26 ( V_4 -> V_2 ) && V_4 -> V_137 -> V_115 >= 5 ) ;
if ( F_95 ( V_4 -> V_2 ) && ! F_96 ( V_4 -> V_2 ) )
F_70 ( V_4 , V_108 ) ;
V_10 = F_57 ( V_108 ) ;
V_12 = F_4 ( V_10 ) ;
V_12 |= V_127 ;
F_11 ( V_10 , V_12 ) ;
F_15 ( V_10 ) ;
F_97 ( 150 ) ;
F_11 ( V_10 , V_12 ) ;
F_15 ( V_10 ) ;
F_97 ( 150 ) ;
F_11 ( V_10 , V_12 ) ;
F_15 ( V_10 ) ;
F_97 ( 150 ) ;
}
static void F_98 ( struct V_3 * V_4 , enum V_108 V_108 )
{
int V_10 ;
T_1 V_12 ;
if ( V_108 == V_142 && ( V_4 -> V_150 & V_151 ) )
return;
F_99 ( V_4 , V_108 ) ;
V_10 = F_57 ( V_108 ) ;
V_12 = F_4 ( V_10 ) ;
V_12 &= ~ V_127 ;
F_11 ( V_10 , V_12 ) ;
F_15 ( V_10 ) ;
}
static void
F_100 ( struct V_3 * V_4 , T_4 V_10 , T_1 V_188 ,
enum V_189 V_190 )
{
unsigned long V_11 ;
T_1 V_191 ;
F_8 ( & V_4 -> V_13 , V_11 ) ;
if ( F_42 ( ( F_4 ( V_192 ) & V_193 ) == 0 , 100 ) ) {
F_10 ( L_42 ) ;
goto V_16;
}
F_11 ( V_194 , ( V_10 << 16 ) ) ;
F_11 ( V_195 , V_188 ) ;
if ( V_190 == V_196 )
V_191 = V_197 | V_198 ;
else
V_191 = V_199 | V_200 ;
F_11 ( V_192 , V_193 | V_191 ) ;
if ( F_42 ( ( F_4 ( V_192 ) & ( V_193 | V_201 ) ) == 0 ,
100 ) ) {
F_10 ( L_43 ) ;
goto V_16;
}
V_16:
F_12 ( & V_4 -> V_13 , V_11 ) ;
}
static T_1
F_101 ( struct V_3 * V_4 , T_4 V_10 ,
enum V_189 V_190 )
{
unsigned long V_11 ;
T_1 V_188 = 0 ;
F_8 ( & V_4 -> V_13 , V_11 ) ;
if ( F_42 ( ( F_4 ( V_192 ) & V_193 ) == 0 , 100 ) ) {
F_10 ( L_42 ) ;
goto V_16;
}
F_11 ( V_194 , ( V_10 << 16 ) ) ;
if ( V_190 == V_196 )
V_188 = V_197 | V_202 ;
else
V_188 = V_199 | V_203 ;
F_11 ( V_192 , V_188 | V_193 ) ;
if ( F_42 ( ( F_4 ( V_192 ) & ( V_193 | V_201 ) ) == 0 ,
100 ) ) {
F_10 ( L_44 ) ;
goto V_16;
}
V_188 = F_4 ( V_195 ) ;
V_16:
F_12 ( & V_4 -> V_13 , V_11 ) ;
return V_188 ;
}
static void F_102 ( struct V_110 * V_110 )
{
struct V_3 * V_4 = V_110 -> V_204 . V_2 -> V_5 ;
struct V_128 * V_129 ;
int V_10 ;
T_1 V_12 ;
F_94 ( V_4 -> V_137 -> V_115 < 5 ) ;
V_129 = V_110 -> V_205 ;
if ( V_129 == NULL )
return;
if ( F_2 ( V_129 -> V_206 == 0 ) )
return;
F_44 ( L_45 ,
V_129 -> V_130 , V_129 -> V_207 , V_129 -> V_208 ,
V_110 -> V_204 . V_204 . V_26 ) ;
F_77 ( V_4 ) ;
if ( V_129 -> V_207 ++ && V_129 -> V_208 ) {
F_103 ( V_4 , V_129 , NULL ) ;
return;
}
F_44 ( L_46 , V_129 -> V_130 ) ;
V_10 = V_129 -> V_130 ;
V_12 = F_4 ( V_10 ) ;
V_12 |= V_127 ;
F_11 ( V_10 , V_12 ) ;
F_15 ( V_10 ) ;
F_97 ( 200 ) ;
V_129 -> V_208 = true ;
}
static void F_104 ( struct V_110 * V_110 )
{
struct V_3 * V_4 = V_110 -> V_204 . V_2 -> V_5 ;
struct V_128 * V_129 = V_110 -> V_205 ;
int V_10 ;
T_1 V_12 ;
F_94 ( V_4 -> V_137 -> V_115 < 5 ) ;
if ( V_129 == NULL )
return;
if ( F_2 ( V_129 -> V_206 == 0 ) )
return;
F_44 ( L_47 ,
V_129 -> V_130 , V_129 -> V_207 , V_129 -> V_208 ,
V_110 -> V_204 . V_204 . V_26 ) ;
if ( F_2 ( V_129 -> V_207 == 0 ) ) {
F_105 ( V_4 , V_129 , NULL ) ;
return;
}
if ( -- V_129 -> V_207 ) {
F_103 ( V_4 , V_129 , NULL ) ;
return;
}
F_44 ( L_48 , V_129 -> V_130 ) ;
F_78 ( V_4 , V_110 -> V_108 ) ;
V_10 = V_129 -> V_130 ;
V_12 = F_4 ( V_10 ) ;
V_12 &= ~ V_127 ;
F_11 ( V_10 , V_12 ) ;
F_15 ( V_10 ) ;
F_97 ( 200 ) ;
V_129 -> V_208 = false ;
}
static void F_106 ( struct V_3 * V_4 ,
enum V_108 V_108 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_36 * V_37 = V_4 -> V_109 [ V_108 ] ;
T_5 V_10 , V_12 , V_209 ;
F_94 ( V_4 -> V_137 -> V_115 < 5 ) ;
F_103 ( V_4 ,
F_39 ( V_37 ) -> V_205 ,
F_39 ( V_37 ) ) ;
F_107 ( V_4 , V_108 ) ;
F_108 ( V_4 , V_108 ) ;
if ( F_61 ( V_2 ) ) {
V_10 = F_109 ( V_108 ) ;
V_12 = F_4 ( V_10 ) ;
V_12 |= V_210 ;
F_11 ( V_10 , V_12 ) ;
}
V_10 = F_79 ( V_108 ) ;
V_12 = F_4 ( V_10 ) ;
V_209 = F_4 ( F_49 ( V_108 ) ) ;
if ( F_90 ( V_4 -> V_2 ) ) {
V_12 &= ~ V_211 ;
V_12 |= V_209 & V_211 ;
}
V_12 &= ~ V_212 ;
if ( ( V_209 & V_213 ) == V_214 )
if ( F_90 ( V_4 -> V_2 ) &&
F_21 ( V_37 , V_56 ) )
V_12 |= V_215 ;
else
V_12 |= V_216 ;
else
V_12 |= V_217 ;
F_11 ( V_10 , V_12 | V_163 ) ;
if ( F_42 ( F_4 ( V_10 ) & V_218 , 100 ) )
F_10 ( L_49 , V_108 ) ;
}
static void F_110 ( struct V_3 * V_4 ,
enum V_107 V_111 )
{
T_1 V_12 , V_209 ;
F_94 ( V_4 -> V_137 -> V_115 < 5 ) ;
F_107 ( V_4 , V_111 ) ;
F_108 ( V_4 , V_219 ) ;
V_12 = F_4 ( V_220 ) ;
V_12 |= V_210 ;
F_11 ( V_220 , V_12 ) ;
V_12 = V_163 ;
V_209 = F_4 ( F_49 ( V_111 ) ) ;
if ( ( V_209 & V_221 ) ==
V_214 )
V_12 |= V_216 ;
else
V_12 |= V_217 ;
F_11 ( F_79 ( V_219 ) , V_12 ) ;
if ( F_42 ( F_4 ( V_222 ) & V_218 , 100 ) )
F_10 ( L_50 ) ;
}
static void F_111 ( struct V_3 * V_4 ,
enum V_108 V_108 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_5 V_10 , V_12 ;
F_112 ( V_4 , V_108 ) ;
F_113 ( V_4 , V_108 ) ;
F_92 ( V_4 , V_108 ) ;
V_10 = F_79 ( V_108 ) ;
V_12 = F_4 ( V_10 ) ;
V_12 &= ~ V_163 ;
F_11 ( V_10 , V_12 ) ;
if ( F_42 ( ( F_4 ( V_10 ) & V_218 ) == 0 , 50 ) )
F_10 ( L_51 , V_108 ) ;
if ( ! F_90 ( V_2 ) ) {
V_10 = F_109 ( V_108 ) ;
V_12 = F_4 ( V_10 ) ;
V_12 &= ~ V_210 ;
F_11 ( V_10 , V_12 ) ;
}
}
static void F_114 ( struct V_3 * V_4 )
{
T_1 V_12 ;
V_12 = F_4 ( V_222 ) ;
V_12 &= ~ V_163 ;
F_11 ( V_222 , V_12 ) ;
if ( F_42 ( ( F_4 ( V_222 ) & V_218 ) == 0 , 50 ) )
F_10 ( L_52 ) ;
V_12 = F_4 ( V_220 ) ;
V_12 &= ~ V_210 ;
F_11 ( V_220 , V_12 ) ;
}
static void F_115 ( struct V_3 * V_4 , enum V_108 V_108 ,
bool V_223 )
{
enum V_107 V_111 = F_38 ( V_4 ,
V_108 ) ;
enum V_107 V_224 ;
int V_10 ;
T_1 V_12 ;
if ( F_63 ( V_4 -> V_2 ) )
V_224 = V_219 ;
else
V_224 = V_108 ;
if ( ! F_3 ( V_4 -> V_2 ) )
F_116 ( V_4 , V_108 ) ;
else {
if ( V_223 ) {
F_69 ( V_4 , V_224 ) ;
F_68 ( V_4 , V_111 ) ;
}
}
V_10 = F_49 ( V_111 ) ;
V_12 = F_4 ( V_10 ) ;
if ( V_12 & V_152 )
return;
F_11 ( V_10 , V_12 | V_152 ) ;
F_45 ( V_4 -> V_2 , V_108 ) ;
}
static void F_117 ( struct V_3 * V_4 ,
enum V_108 V_108 )
{
enum V_107 V_111 = F_38 ( V_4 ,
V_108 ) ;
int V_10 ;
T_1 V_12 ;
F_76 ( V_4 , V_108 ) ;
if ( V_108 == V_142 && ( V_4 -> V_150 & V_151 ) )
return;
V_10 = F_49 ( V_111 ) ;
V_12 = F_4 ( V_10 ) ;
if ( ( V_12 & V_152 ) == 0 )
return;
F_11 ( V_10 , V_12 & ~ V_152 ) ;
F_48 ( V_4 -> V_2 , V_108 ) ;
}
void F_118 ( struct V_3 * V_4 ,
enum V_153 V_153 )
{
if ( V_4 -> V_137 -> V_115 >= 4 )
F_11 ( F_119 ( V_153 ) , F_4 ( F_119 ( V_153 ) ) ) ;
else
F_11 ( F_120 ( V_153 ) , F_4 ( F_120 ( V_153 ) ) ) ;
}
static void F_121 ( struct V_3 * V_4 ,
enum V_153 V_153 , enum V_108 V_108 )
{
int V_10 ;
T_1 V_12 ;
F_122 ( V_4 , V_108 ) ;
V_10 = F_74 ( V_153 ) ;
V_12 = F_4 ( V_10 ) ;
if ( V_12 & V_154 )
return;
F_11 ( V_10 , V_12 | V_154 ) ;
F_118 ( V_4 , V_153 ) ;
F_45 ( V_4 -> V_2 , V_108 ) ;
}
static void F_123 ( struct V_3 * V_4 ,
enum V_153 V_153 , enum V_108 V_108 )
{
int V_10 ;
T_1 V_12 ;
V_10 = F_74 ( V_153 ) ;
V_12 = F_4 ( V_10 ) ;
if ( ( V_12 & V_154 ) == 0 )
return;
F_11 ( V_10 , V_12 & ~ V_154 ) ;
F_118 ( V_4 , V_153 ) ;
F_45 ( V_4 -> V_2 , V_108 ) ;
}
int
F_124 ( struct V_1 * V_2 ,
struct V_225 * V_226 ,
struct V_227 * V_228 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_229 ;
int V_230 ;
switch ( V_226 -> V_231 ) {
case V_232 :
if ( F_125 ( V_2 ) || F_126 ( V_2 ) )
V_229 = 128 * 1024 ;
else if ( F_47 ( V_2 ) -> V_115 >= 4 )
V_229 = 4 * 1024 ;
else
V_229 = 64 * 1024 ;
break;
case V_233 :
V_229 = 0 ;
break;
case V_234 :
F_10 ( L_53 ) ;
return - V_235 ;
default:
F_127 () ;
}
V_4 -> V_236 . V_237 = false ;
V_230 = F_128 ( V_226 , V_229 , V_228 ) ;
if ( V_230 )
goto V_238;
V_230 = F_129 ( V_226 ) ;
if ( V_230 )
goto V_239;
F_130 ( V_226 ) ;
V_4 -> V_236 . V_237 = true ;
return 0 ;
V_239:
F_131 ( V_226 ) ;
V_238:
V_4 -> V_236 . V_237 = true ;
return V_230 ;
}
void F_132 ( struct V_225 * V_226 )
{
F_133 ( V_226 ) ;
F_131 ( V_226 ) ;
}
unsigned long F_134 ( int * V_240 , int * V_241 ,
unsigned int V_242 ,
unsigned int V_243 )
{
int V_244 , V_245 ;
V_244 = * V_241 / 8 ;
* V_241 %= 8 ;
V_245 = * V_240 / ( 512 / V_242 ) ;
* V_240 %= 512 / V_242 ;
return V_244 * V_243 * 8 + V_245 * 4096 ;
}
static int F_135 ( struct V_36 * V_37 , struct V_246 * V_247 ,
int V_240 , int V_241 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
struct V_248 * V_249 ;
struct V_225 * V_226 ;
int V_153 = V_110 -> V_153 ;
unsigned long V_250 ;
T_1 V_251 ;
T_1 V_10 ;
switch ( V_153 ) {
case 0 :
case 1 :
break;
default:
F_10 ( L_54 , V_153 ) ;
return - V_235 ;
}
V_249 = F_136 ( V_247 ) ;
V_226 = V_249 -> V_226 ;
V_10 = F_74 ( V_153 ) ;
V_251 = F_4 ( V_10 ) ;
V_251 &= ~ V_252 ;
switch ( V_247 -> V_253 ) {
case V_254 :
V_251 |= V_255 ;
break;
case V_256 :
case V_257 :
V_251 |= V_258 ;
break;
case V_259 :
V_251 |= V_260 ;
break;
case V_261 :
case V_262 :
V_251 |= V_263 ;
break;
case V_264 :
case V_265 :
V_251 |= V_266 ;
break;
case V_267 :
case V_268 :
V_251 |= V_269 ;
break;
case V_270 :
case V_271 :
V_251 |= V_272 ;
break;
default:
F_10 ( L_55 , V_247 -> V_253 ) ;
return - V_235 ;
}
if ( F_47 ( V_2 ) -> V_115 >= 4 ) {
if ( V_226 -> V_231 != V_232 )
V_251 |= V_273 ;
else
V_251 &= ~ V_273 ;
}
F_11 ( V_10 , V_251 ) ;
V_250 = V_241 * V_247 -> V_274 [ 0 ] + V_240 * ( V_247 -> V_275 / 8 ) ;
if ( F_47 ( V_2 ) -> V_115 >= 4 ) {
V_110 -> V_276 =
F_134 ( & V_240 , & V_241 ,
V_247 -> V_275 / 8 ,
V_247 -> V_274 [ 0 ] ) ;
V_250 -= V_110 -> V_276 ;
} else {
V_110 -> V_276 = V_250 ;
}
F_44 ( L_56 ,
V_226 -> V_277 , V_250 , V_240 , V_241 , V_247 -> V_274 [ 0 ] ) ;
F_11 ( F_137 ( V_153 ) , V_247 -> V_274 [ 0 ] ) ;
if ( F_47 ( V_2 ) -> V_115 >= 4 ) {
F_138 ( F_119 ( V_153 ) ,
V_226 -> V_277 + V_110 -> V_276 ) ;
F_11 ( F_139 ( V_153 ) , ( V_241 << 16 ) | V_240 ) ;
F_11 ( F_140 ( V_153 ) , V_250 ) ;
} else
F_11 ( F_120 ( V_153 ) , V_226 -> V_277 + V_250 ) ;
F_15 ( V_10 ) ;
return 0 ;
}
static int F_141 ( struct V_36 * V_37 ,
struct V_246 * V_247 , int V_240 , int V_241 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
struct V_248 * V_249 ;
struct V_225 * V_226 ;
int V_153 = V_110 -> V_153 ;
unsigned long V_250 ;
T_1 V_251 ;
T_1 V_10 ;
switch ( V_153 ) {
case 0 :
case 1 :
case 2 :
break;
default:
F_10 ( L_54 , V_153 ) ;
return - V_235 ;
}
V_249 = F_136 ( V_247 ) ;
V_226 = V_249 -> V_226 ;
V_10 = F_74 ( V_153 ) ;
V_251 = F_4 ( V_10 ) ;
V_251 &= ~ V_252 ;
switch ( V_247 -> V_253 ) {
case V_254 :
V_251 |= V_255 ;
break;
case V_259 :
V_251 |= V_260 ;
break;
case V_261 :
case V_262 :
V_251 |= V_263 ;
break;
case V_264 :
case V_265 :
V_251 |= V_266 ;
break;
case V_267 :
case V_268 :
V_251 |= V_269 ;
break;
case V_270 :
case V_271 :
V_251 |= V_272 ;
break;
default:
F_10 ( L_55 , V_247 -> V_253 ) ;
return - V_235 ;
}
if ( V_226 -> V_231 != V_232 )
V_251 |= V_273 ;
else
V_251 &= ~ V_273 ;
V_251 |= V_278 ;
F_11 ( V_10 , V_251 ) ;
V_250 = V_241 * V_247 -> V_274 [ 0 ] + V_240 * ( V_247 -> V_275 / 8 ) ;
V_110 -> V_276 =
F_134 ( & V_240 , & V_241 ,
V_247 -> V_275 / 8 ,
V_247 -> V_274 [ 0 ] ) ;
V_250 -= V_110 -> V_276 ;
F_44 ( L_56 ,
V_226 -> V_277 , V_250 , V_240 , V_241 , V_247 -> V_274 [ 0 ] ) ;
F_11 ( F_137 ( V_153 ) , V_247 -> V_274 [ 0 ] ) ;
F_138 ( F_119 ( V_153 ) ,
V_226 -> V_277 + V_110 -> V_276 ) ;
if ( F_63 ( V_2 ) ) {
F_11 ( F_142 ( V_153 ) , ( V_241 << 16 ) | V_240 ) ;
} else {
F_11 ( F_139 ( V_153 ) , ( V_241 << 16 ) | V_240 ) ;
F_11 ( F_140 ( V_153 ) , V_250 ) ;
}
F_15 ( V_10 ) ;
return 0 ;
}
static int
F_143 ( struct V_36 * V_37 , struct V_246 * V_247 ,
int V_240 , int V_241 , enum V_279 V_125 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_280 . V_281 )
V_4 -> V_280 . V_281 ( V_2 ) ;
F_144 ( V_37 ) ;
return V_4 -> V_280 . V_282 ( V_37 , V_247 , V_240 , V_241 ) ;
}
static int
F_145 ( struct V_246 * V_283 )
{
struct V_225 * V_226 = F_136 ( V_283 ) -> V_226 ;
struct V_3 * V_4 = V_226 -> V_204 . V_2 -> V_5 ;
bool V_284 = V_4 -> V_236 . V_237 ;
int V_230 ;
F_146 ( V_4 -> V_285 ,
F_147 ( & V_4 -> V_236 . V_286 ) ||
F_147 ( & V_226 -> V_287 ) == 0 ) ;
V_4 -> V_236 . V_237 = false ;
V_230 = F_148 ( V_226 ) ;
V_4 -> V_236 . V_237 = V_284 ;
return V_230 ;
}
static void F_149 ( struct V_36 * V_37 , int V_240 , int V_241 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_288 * V_289 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
if ( ! V_2 -> V_290 -> V_291 )
return;
V_289 = V_2 -> V_290 -> V_291 -> V_292 ;
if ( ! V_289 -> V_293 )
return;
switch ( V_110 -> V_108 ) {
case 0 :
V_289 -> V_293 -> V_294 = V_240 ;
V_289 -> V_293 -> V_295 = V_241 ;
break;
case 1 :
V_289 -> V_293 -> V_296 = V_240 ;
V_289 -> V_293 -> V_297 = V_241 ;
break;
default:
break;
}
}
static int
F_150 ( struct V_36 * V_37 , int V_240 , int V_241 ,
struct V_246 * V_247 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
struct V_246 * V_283 ;
int V_230 ;
if ( ! V_247 ) {
F_10 ( L_57 ) ;
return 0 ;
}
if( V_110 -> V_153 > V_4 -> V_298 ) {
F_10 ( L_58 ,
V_110 -> V_153 ,
V_4 -> V_298 ) ;
return - V_235 ;
}
F_151 ( & V_2 -> V_299 ) ;
V_230 = F_124 ( V_2 ,
F_136 ( V_247 ) -> V_226 ,
NULL ) ;
if ( V_230 != 0 ) {
F_152 ( & V_2 -> V_299 ) ;
F_10 ( L_59 ) ;
return V_230 ;
}
if ( V_37 -> V_247 )
F_145 ( V_37 -> V_247 ) ;
V_230 = V_4 -> V_280 . V_282 ( V_37 , V_247 , V_240 , V_241 ) ;
if ( V_230 ) {
F_132 ( F_136 ( V_247 ) -> V_226 ) ;
F_152 ( & V_2 -> V_299 ) ;
F_10 ( L_60 ) ;
return V_230 ;
}
V_283 = V_37 -> V_247 ;
V_37 -> V_247 = V_247 ;
V_37 -> V_240 = V_240 ;
V_37 -> V_241 = V_241 ;
if ( V_283 ) {
F_45 ( V_2 , V_110 -> V_108 ) ;
F_132 ( F_136 ( V_283 ) -> V_226 ) ;
}
F_153 ( V_2 ) ;
F_152 ( & V_2 -> V_299 ) ;
F_149 ( V_37 , V_240 , V_241 ) ;
return 0 ;
}
static void F_154 ( struct V_36 * V_37 , int clock )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_300 ;
F_44 ( L_61 , clock ) ;
V_300 = F_4 ( V_301 ) ;
V_300 &= ~ V_302 ;
if ( clock < 200000 ) {
T_1 V_303 ;
V_300 |= V_304 ;
V_303 = F_4 ( 0x4600c ) ;
V_303 &= 0xffff0000 ;
F_11 ( 0x4600c , V_303 | 0x8124 ) ;
V_303 = F_4 ( 0x46010 ) ;
F_11 ( 0x46010 , V_303 | 1 ) ;
V_303 = F_4 ( 0x46034 ) ;
F_11 ( 0x46034 , V_303 | ( 1 << 24 ) ) ;
} else {
V_300 |= V_305 ;
}
F_11 ( V_301 , V_300 ) ;
F_15 ( V_301 ) ;
F_97 ( 500 ) ;
}
static void F_155 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
T_1 V_10 , V_303 ;
V_10 = F_65 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
if ( F_156 ( V_2 ) ) {
V_303 &= ~ V_306 ;
V_303 |= V_306 | V_307 ;
} else {
V_303 &= ~ V_308 ;
V_303 |= V_308 | V_307 ;
}
F_11 ( V_10 , V_303 ) ;
V_10 = F_67 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
if ( F_61 ( V_2 ) ) {
V_303 &= ~ V_309 ;
V_303 |= V_310 ;
} else {
V_303 &= ~ V_308 ;
V_303 |= V_308 ;
}
F_11 ( V_10 , V_303 | V_311 ) ;
F_15 ( V_10 ) ;
F_97 ( 1000 ) ;
if ( F_156 ( V_2 ) )
F_11 ( V_10 , F_4 ( V_10 ) | V_312 |
V_313 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_314 =
F_39 ( V_4 -> V_109 [ V_149 ] ) ;
struct V_110 * V_315 =
F_39 ( V_4 -> V_109 [ V_316 ] ) ;
T_5 V_303 ;
if ( ! V_314 -> V_204 . V_124 && ! V_315 -> V_204 . V_124 ) {
F_2 ( F_4 ( F_67 ( V_149 ) ) & V_136 ) ;
F_2 ( F_4 ( F_67 ( V_316 ) ) & V_136 ) ;
V_303 = F_4 ( V_317 ) ;
V_303 &= ~ V_318 ;
F_44 ( L_62 ) ;
F_11 ( V_317 , V_303 ) ;
}
}
static void F_158 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
int V_153 = V_110 -> V_153 ;
T_1 V_10 , V_303 , V_319 ;
F_122 ( V_4 , V_108 ) ;
F_159 ( V_4 , V_153 ) ;
V_10 = F_160 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_320 ;
V_303 &= ~ V_321 ;
F_11 ( V_10 , V_303 ) ;
F_4 ( V_10 ) ;
F_97 ( 150 ) ;
V_10 = F_65 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ ( 7 << 19 ) ;
V_303 |= ( V_110 -> V_322 - 1 ) << 19 ;
V_303 &= ~ V_308 ;
V_303 |= V_323 ;
F_11 ( V_10 , V_303 | V_135 ) ;
V_10 = F_67 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_308 ;
V_303 |= V_323 ;
F_11 ( V_10 , V_303 | V_136 ) ;
F_15 ( V_10 ) ;
F_97 ( 150 ) ;
F_11 ( F_161 ( V_108 ) , V_324 ) ;
F_11 ( F_161 ( V_108 ) , V_324 |
V_325 ) ;
V_10 = F_162 ( V_108 ) ;
for ( V_319 = 0 ; V_319 < 5 ; V_319 ++ ) {
V_303 = F_4 ( V_10 ) ;
F_44 ( L_63 , V_303 ) ;
if ( ( V_303 & V_321 ) ) {
F_44 ( L_64 ) ;
F_11 ( V_10 , V_303 | V_321 ) ;
break;
}
}
if ( V_319 == 5 )
F_10 ( L_65 ) ;
V_10 = F_65 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_308 ;
V_303 |= V_326 ;
F_11 ( V_10 , V_303 ) ;
V_10 = F_67 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_308 ;
V_303 |= V_326 ;
F_11 ( V_10 , V_303 ) ;
F_15 ( V_10 ) ;
F_97 ( 150 ) ;
V_10 = F_162 ( V_108 ) ;
for ( V_319 = 0 ; V_319 < 5 ; V_319 ++ ) {
V_303 = F_4 ( V_10 ) ;
F_44 ( L_63 , V_303 ) ;
if ( V_303 & V_320 ) {
F_11 ( V_10 , V_303 | V_320 ) ;
F_44 ( L_66 ) ;
break;
}
}
if ( V_319 == 5 )
F_10 ( L_67 ) ;
F_44 ( L_68 ) ;
}
static void F_163 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
T_1 V_10 , V_303 , V_155 , V_327 ;
V_10 = F_160 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_320 ;
V_303 &= ~ V_321 ;
F_11 ( V_10 , V_303 ) ;
F_15 ( V_10 ) ;
F_97 ( 150 ) ;
V_10 = F_65 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ ( 7 << 19 ) ;
V_303 |= ( V_110 -> V_322 - 1 ) << 19 ;
V_303 &= ~ V_308 ;
V_303 |= V_323 ;
V_303 &= ~ V_328 ;
V_303 |= V_329 ;
F_11 ( V_10 , V_303 | V_135 ) ;
F_11 ( F_164 ( V_108 ) ,
V_330 | V_331 ) ;
V_10 = F_67 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
if ( F_61 ( V_2 ) ) {
V_303 &= ~ V_309 ;
V_303 |= V_332 ;
} else {
V_303 &= ~ V_308 ;
V_303 |= V_323 ;
}
F_11 ( V_10 , V_303 | V_136 ) ;
F_15 ( V_10 ) ;
F_97 ( 150 ) ;
for ( V_155 = 0 ; V_155 < 4 ; V_155 ++ ) {
V_10 = F_65 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_328 ;
V_303 |= V_333 [ V_155 ] ;
F_11 ( V_10 , V_303 ) ;
F_15 ( V_10 ) ;
F_97 ( 500 ) ;
for ( V_327 = 0 ; V_327 < 5 ; V_327 ++ ) {
V_10 = F_162 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
F_44 ( L_63 , V_303 ) ;
if ( V_303 & V_321 ) {
F_11 ( V_10 , V_303 | V_321 ) ;
F_44 ( L_64 ) ;
break;
}
F_97 ( 50 ) ;
}
if ( V_327 < 5 )
break;
}
if ( V_155 == 4 )
F_10 ( L_65 ) ;
V_10 = F_65 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_308 ;
V_303 |= V_326 ;
if ( F_165 ( V_2 ) ) {
V_303 &= ~ V_328 ;
V_303 |= V_329 ;
}
F_11 ( V_10 , V_303 ) ;
V_10 = F_67 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
if ( F_61 ( V_2 ) ) {
V_303 &= ~ V_309 ;
V_303 |= V_334 ;
} else {
V_303 &= ~ V_308 ;
V_303 |= V_326 ;
}
F_11 ( V_10 , V_303 ) ;
F_15 ( V_10 ) ;
F_97 ( 150 ) ;
for ( V_155 = 0 ; V_155 < 4 ; V_155 ++ ) {
V_10 = F_65 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_328 ;
V_303 |= V_333 [ V_155 ] ;
F_11 ( V_10 , V_303 ) ;
F_15 ( V_10 ) ;
F_97 ( 500 ) ;
for ( V_327 = 0 ; V_327 < 5 ; V_327 ++ ) {
V_10 = F_162 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
F_44 ( L_63 , V_303 ) ;
if ( V_303 & V_320 ) {
F_11 ( V_10 , V_303 | V_320 ) ;
F_44 ( L_66 ) ;
break;
}
F_97 ( 50 ) ;
}
if ( V_327 < 5 )
break;
}
if ( V_155 == 4 )
F_10 ( L_67 ) ;
F_44 ( L_69 ) ;
}
static void F_166 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
T_1 V_10 , V_303 , V_155 ;
V_10 = F_160 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_320 ;
V_303 &= ~ V_321 ;
F_11 ( V_10 , V_303 ) ;
F_15 ( V_10 ) ;
F_97 ( 150 ) ;
F_44 ( L_70 ,
F_4 ( F_162 ( V_108 ) ) ) ;
V_10 = F_65 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ ( 7 << 19 ) ;
V_303 |= ( V_110 -> V_322 - 1 ) << 19 ;
V_303 &= ~ ( V_335 | V_306 ) ;
V_303 |= V_336 ;
V_303 &= ~ V_328 ;
V_303 |= V_329 ;
V_303 |= V_337 ;
F_11 ( V_10 , V_303 | V_135 ) ;
F_11 ( F_164 ( V_108 ) ,
V_330 | V_331 ) ;
V_10 = F_67 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_335 ;
V_303 &= ~ V_309 ;
V_303 |= V_332 ;
V_303 |= V_337 ;
F_11 ( V_10 , V_303 | V_136 ) ;
F_15 ( V_10 ) ;
F_97 ( 150 ) ;
for ( V_155 = 0 ; V_155 < 4 ; V_155 ++ ) {
V_10 = F_65 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_328 ;
V_303 |= V_333 [ V_155 ] ;
F_11 ( V_10 , V_303 ) ;
F_15 ( V_10 ) ;
F_97 ( 500 ) ;
V_10 = F_162 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
F_44 ( L_63 , V_303 ) ;
if ( V_303 & V_321 ||
( F_4 ( V_10 ) & V_321 ) ) {
F_11 ( V_10 , V_303 | V_321 ) ;
F_44 ( L_71 , V_155 ) ;
break;
}
}
if ( V_155 == 4 )
F_10 ( L_65 ) ;
V_10 = F_65 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_306 ;
V_303 |= V_338 ;
V_303 &= ~ V_328 ;
V_303 |= V_329 ;
F_11 ( V_10 , V_303 ) ;
V_10 = F_67 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_309 ;
V_303 |= V_334 ;
F_11 ( V_10 , V_303 ) ;
F_15 ( V_10 ) ;
F_97 ( 150 ) ;
for ( V_155 = 0 ; V_155 < 4 ; V_155 ++ ) {
V_10 = F_65 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_328 ;
V_303 |= V_333 [ V_155 ] ;
F_11 ( V_10 , V_303 ) ;
F_15 ( V_10 ) ;
F_97 ( 500 ) ;
V_10 = F_162 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
F_44 ( L_63 , V_303 ) ;
if ( V_303 & V_320 ) {
F_11 ( V_10 , V_303 | V_320 ) ;
F_44 ( L_72 , V_155 ) ;
break;
}
}
if ( V_155 == 4 )
F_10 ( L_67 ) ;
F_44 ( L_69 ) ;
}
static void F_167 ( struct V_110 * V_110 )
{
struct V_1 * V_2 = V_110 -> V_204 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_108 = V_110 -> V_108 ;
T_1 V_10 , V_303 ;
V_10 = F_67 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ ( ( 0x7 << 19 ) | ( 0x7 << 16 ) ) ;
V_303 |= ( V_110 -> V_322 - 1 ) << 19 ;
V_303 |= ( F_4 ( F_49 ( V_108 ) ) & V_211 ) << 11 ;
F_11 ( V_10 , V_303 | V_139 ) ;
F_15 ( V_10 ) ;
F_97 ( 200 ) ;
V_303 = F_4 ( V_10 ) ;
F_11 ( V_10 , V_303 | V_339 ) ;
F_15 ( V_10 ) ;
F_97 ( 200 ) ;
if ( ! F_63 ( V_2 ) ) {
V_10 = F_65 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
if ( ( V_303 & V_138 ) == 0 ) {
F_11 ( V_10 , V_303 | V_138 ) ;
F_15 ( V_10 ) ;
F_97 ( 100 ) ;
}
}
}
static void F_168 ( struct V_110 * V_110 )
{
struct V_1 * V_2 = V_110 -> V_204 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_108 = V_110 -> V_108 ;
T_1 V_10 , V_303 ;
V_10 = F_67 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
F_11 ( V_10 , V_303 & ~ V_339 ) ;
V_10 = F_65 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
F_11 ( V_10 , V_303 & ~ V_138 ) ;
F_15 ( V_10 ) ;
F_97 ( 100 ) ;
V_10 = F_67 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
F_11 ( V_10 , V_303 & ~ V_139 ) ;
F_15 ( V_10 ) ;
F_97 ( 100 ) ;
}
static void F_169 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
T_1 V_10 , V_303 ;
V_10 = F_65 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
F_11 ( V_10 , V_303 & ~ V_135 ) ;
F_15 ( V_10 ) ;
V_10 = F_67 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ ( 0x7 << 16 ) ;
V_303 |= ( F_4 ( F_49 ( V_108 ) ) & V_211 ) << 11 ;
F_11 ( V_10 , V_303 & ~ V_136 ) ;
F_15 ( V_10 ) ;
F_97 ( 100 ) ;
if ( F_90 ( V_2 ) ) {
F_11 ( F_161 ( V_108 ) , V_324 ) ;
}
V_10 = F_65 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ V_308 ;
V_303 |= V_323 ;
F_11 ( V_10 , V_303 ) ;
V_10 = F_67 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
if ( F_61 ( V_2 ) ) {
V_303 &= ~ V_309 ;
V_303 |= V_332 ;
} else {
V_303 &= ~ V_308 ;
V_303 |= V_323 ;
}
V_303 &= ~ ( 0x07 << 16 ) ;
V_303 |= ( F_4 ( F_49 ( V_108 ) ) & V_211 ) << 11 ;
F_11 ( V_10 , V_303 ) ;
F_15 ( V_10 ) ;
F_97 ( 100 ) ;
}
static bool F_170 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_11 ;
bool V_340 ;
if ( F_147 ( & V_4 -> V_236 . V_286 ) )
return false ;
F_8 ( & V_2 -> V_341 , V_11 ) ;
V_340 = F_39 ( V_37 ) -> V_342 != NULL ;
F_12 ( & V_2 -> V_341 , V_11 ) ;
return V_340 ;
}
static void F_171 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_37 -> V_247 == NULL )
return;
F_146 ( V_4 -> V_285 ,
! F_170 ( V_37 ) ) ;
F_151 ( & V_2 -> V_299 ) ;
F_145 ( V_37 -> V_247 ) ;
F_152 ( & V_2 -> V_299 ) ;
}
static bool F_172 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_77 * V_77 ;
F_30 (dev, crtc, intel_encoder) {
switch ( V_77 -> type ) {
case V_47 :
if ( ! F_173 ( & V_77 -> V_204 ) )
return false ;
continue;
}
}
return true ;
}
static bool F_174 ( struct V_36 * V_37 )
{
return F_21 ( V_37 , V_54 ) ;
}
static void F_175 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_343 , V_344 , V_345 , V_346 = 0 ;
T_1 V_303 ;
F_11 ( V_347 , V_348 ) ;
F_100 ( V_4 , V_349 ,
F_101 ( V_4 , V_349 , V_196 ) |
V_350 ,
V_196 ) ;
if ( V_37 -> V_351 . clock == 20000 ) {
V_345 = 1 ;
V_343 = 0x41 ;
V_344 = 0x20 ;
} else {
T_1 V_352 = 172800 * 1000 ;
T_1 V_353 = 64 ;
T_1 V_354 , V_355 , V_356 ;
V_354 = ( V_352 / V_37 -> V_351 . clock ) ;
V_355 = V_354 / V_353 ;
V_356 = V_354 % V_353 ;
V_345 = 0 ;
V_343 = V_355 - 2 ;
V_344 = V_356 ;
}
F_2 ( F_176 ( V_343 ) &
~ V_357 ) ;
F_2 ( F_177 ( V_346 ) &
~ V_358 ) ;
F_44 ( L_73 ,
V_37 -> V_351 . clock ,
V_345 ,
V_343 ,
V_346 ,
V_344 ) ;
V_303 = F_101 ( V_4 , V_359 , V_196 ) ;
V_303 &= ~ V_357 ;
V_303 |= F_176 ( V_343 ) ;
V_303 &= ~ V_358 ;
V_303 |= F_178 ( V_344 ) ;
V_303 |= F_177 ( V_346 ) ;
V_303 |= V_360 ;
F_100 ( V_4 , V_359 , V_303 , V_196 ) ;
V_303 = F_101 ( V_4 , V_361 , V_196 ) ;
V_303 &= ~ F_179 ( 1 ) ;
V_303 |= F_179 ( V_345 ) ;
F_100 ( V_4 , V_361 , V_303 , V_196 ) ;
V_303 = F_101 ( V_4 , V_349 , V_196 ) ;
V_303 &= ~ V_350 ;
F_100 ( V_4 , V_349 , V_303 , V_196 ) ;
F_97 ( 24 ) ;
F_11 ( V_347 , V_362 ) ;
}
static void F_180 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
T_1 V_10 , V_303 ;
F_78 ( V_4 , V_108 ) ;
F_11 ( F_181 ( V_108 ) ,
F_4 ( F_182 ( V_108 ) ) & V_363 ) ;
V_4 -> V_280 . V_364 ( V_37 ) ;
F_102 ( V_110 ) ;
if ( F_61 ( V_2 ) ) {
T_1 V_365 ;
V_303 = F_4 ( V_132 ) ;
switch ( V_108 ) {
default:
case 0 :
V_303 |= V_366 ;
V_365 = V_367 ;
break;
case 1 :
V_303 |= V_368 ;
V_365 = V_369 ;
break;
case 2 :
V_303 |= V_370 ;
V_365 = V_371 ;
break;
}
if ( V_110 -> V_205 -> V_130 == V_133 )
V_303 |= V_365 ;
else
V_303 &= ~ V_365 ;
F_11 ( V_132 , V_303 ) ;
}
F_70 ( V_4 , V_108 ) ;
F_11 ( F_183 ( V_108 ) , F_4 ( F_184 ( V_108 ) ) ) ;
F_11 ( F_185 ( V_108 ) , F_4 ( F_186 ( V_108 ) ) ) ;
F_11 ( F_187 ( V_108 ) , F_4 ( F_188 ( V_108 ) ) ) ;
F_11 ( F_189 ( V_108 ) , F_4 ( F_190 ( V_108 ) ) ) ;
F_11 ( F_191 ( V_108 ) , F_4 ( F_192 ( V_108 ) ) ) ;
F_11 ( F_193 ( V_108 ) , F_4 ( F_194 ( V_108 ) ) ) ;
F_11 ( F_195 ( V_108 ) , F_4 ( F_196 ( V_108 ) ) ) ;
F_155 ( V_37 ) ;
if ( F_61 ( V_2 ) &&
( F_21 ( V_37 , V_46 ) ||
F_21 ( V_37 , V_47 ) ) ) {
T_1 V_372 = ( F_4 ( F_49 ( V_108 ) ) & V_211 ) >> 5 ;
V_10 = F_81 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ ( V_168 |
V_373 |
V_374 ) ;
V_303 |= ( V_375 |
V_376 ) ;
V_303 |= V_372 << 9 ;
if ( V_37 -> V_351 . V_11 & V_377 )
V_303 |= V_378 ;
if ( V_37 -> V_351 . V_11 & V_379 )
V_303 |= V_380 ;
switch ( F_197 ( V_37 ) ) {
case V_178 :
V_303 |= V_179 ;
break;
case V_180 :
V_303 |= V_181 ;
break;
case V_182 :
V_303 |= V_183 ;
break;
default:
F_127 () ;
}
F_11 ( V_10 , V_303 ) ;
}
F_106 ( V_4 , V_108 ) ;
}
static void F_198 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
enum V_107 V_111 = V_110 -> V_111 ;
F_78 ( V_4 , V_219 ) ;
F_175 ( V_37 ) ;
F_11 ( V_381 , F_4 ( F_184 ( V_111 ) ) ) ;
F_11 ( V_382 , F_4 ( F_186 ( V_111 ) ) ) ;
F_11 ( V_383 , F_4 ( F_188 ( V_111 ) ) ) ;
F_11 ( V_384 , F_4 ( F_190 ( V_111 ) ) ) ;
F_11 ( V_385 , F_4 ( F_192 ( V_111 ) ) ) ;
F_11 ( V_386 , F_4 ( F_194 ( V_111 ) ) ) ;
F_11 ( V_387 , F_4 ( F_196 ( V_111 ) ) ) ;
F_110 ( V_4 , V_111 ) ;
}
static void F_199 ( struct V_110 * V_110 )
{
struct V_128 * V_129 = V_110 -> V_205 ;
if ( V_129 == NULL )
return;
if ( V_129 -> V_206 == 0 ) {
F_50 ( 1 , L_74 ) ;
return;
}
-- V_129 -> V_206 ;
V_110 -> V_205 = NULL ;
}
static struct V_128 * F_200 ( struct V_110 * V_110 , T_1 V_388 , T_1 V_389 )
{
struct V_3 * V_4 = V_110 -> V_204 . V_2 -> V_5 ;
struct V_128 * V_129 ;
int V_155 ;
V_129 = V_110 -> V_205 ;
if ( V_129 ) {
F_44 ( L_75 ,
V_110 -> V_204 . V_204 . V_26 , V_129 -> V_130 ) ;
goto V_390;
}
if ( F_90 ( V_4 -> V_2 ) ) {
V_155 = V_110 -> V_108 ;
V_129 = & V_4 -> V_391 [ V_155 ] ;
F_44 ( L_76 ,
V_110 -> V_204 . V_204 . V_26 , V_129 -> V_130 ) ;
goto V_90;
}
for ( V_155 = 0 ; V_155 < V_4 -> V_392 ; V_155 ++ ) {
V_129 = & V_4 -> V_391 [ V_155 ] ;
if ( V_129 -> V_206 == 0 )
continue;
if ( V_388 == ( F_4 ( V_129 -> V_130 ) & 0x7fffffff ) &&
V_389 == F_4 ( V_129 -> V_393 ) ) {
F_44 ( L_77 ,
V_110 -> V_204 . V_204 . V_26 ,
V_129 -> V_130 , V_129 -> V_206 , V_129 -> V_207 ) ;
goto V_90;
}
}
for ( V_155 = 0 ; V_155 < V_4 -> V_392 ; V_155 ++ ) {
V_129 = & V_4 -> V_391 [ V_155 ] ;
if ( V_129 -> V_206 == 0 ) {
F_44 ( L_78 ,
V_110 -> V_204 . V_204 . V_26 , V_129 -> V_130 ) ;
goto V_90;
}
}
return NULL ;
V_90:
V_110 -> V_205 = V_129 ;
V_129 -> V_206 ++ ;
F_60 ( L_79 , V_155 , V_110 -> V_108 ) ;
V_390:
F_60 ( L_80 , V_129 -> V_130 ) ;
F_11 ( V_129 -> V_130 , V_388 & ~ V_127 ) ;
F_15 ( V_129 -> V_130 ) ;
F_97 ( 150 ) ;
F_11 ( V_129 -> V_393 , V_389 ) ;
F_11 ( V_129 -> V_130 , V_388 & ~ V_127 ) ;
V_129 -> V_208 = false ;
return V_129 ;
}
void F_201 ( struct V_1 * V_2 , int V_108 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_394 = F_51 ( V_108 ) ;
T_1 V_303 ;
V_303 = F_4 ( V_394 ) ;
F_97 ( 500 ) ;
if ( F_42 ( F_4 ( V_394 ) != V_303 , 5 ) ) {
if ( F_42 ( F_4 ( V_394 ) != V_303 , 5 ) )
F_10 ( L_81 , V_108 ) ;
}
}
static void F_202 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
struct V_77 * V_78 ;
int V_108 = V_110 -> V_108 ;
int V_153 = V_110 -> V_153 ;
T_1 V_303 ;
bool V_395 ;
F_2 ( ! V_37 -> V_124 ) ;
if ( V_110 -> V_207 )
return;
V_110 -> V_207 = true ;
F_203 ( V_2 ) ;
if ( F_21 ( V_37 , V_40 ) ) {
V_303 = F_4 ( V_41 ) ;
if ( ( V_303 & V_173 ) == 0 )
F_11 ( V_41 , V_303 | V_173 ) ;
}
V_395 = F_172 ( V_37 ) ;
if ( V_395 ) {
F_167 ( V_110 ) ;
} else {
F_112 ( V_4 , V_108 ) ;
F_113 ( V_4 , V_108 ) ;
}
F_30 (dev, crtc, encoder)
if ( V_78 -> V_396 )
V_78 -> V_396 ( V_78 ) ;
if ( V_4 -> V_397 &&
( F_21 ( V_37 , V_40 ) ||
F_21 ( V_37 , V_47 ) ) ) {
if ( F_156 ( V_2 ) )
F_11 ( F_204 ( V_108 ) , V_398 | V_399 |
F_205 ( V_108 ) ) ;
else
F_11 ( F_204 ( V_108 ) , V_398 | V_399 ) ;
F_11 ( F_206 ( V_108 ) , V_4 -> V_400 ) ;
F_11 ( F_207 ( V_108 ) , V_4 -> V_397 ) ;
}
F_208 ( V_37 ) ;
F_115 ( V_4 , V_108 , V_395 ) ;
F_121 ( V_4 , V_153 , V_108 ) ;
if ( V_395 )
F_180 ( V_37 ) ;
F_151 ( & V_2 -> V_299 ) ;
F_153 ( V_2 ) ;
F_152 ( & V_2 -> V_299 ) ;
F_209 ( V_37 , true ) ;
F_30 (dev, crtc, encoder)
V_78 -> V_401 ( V_78 ) ;
if ( F_61 ( V_2 ) )
F_201 ( V_2 , V_110 -> V_108 ) ;
F_45 ( V_2 , V_110 -> V_108 ) ;
}
static void F_210 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
struct V_77 * V_78 ;
int V_108 = V_110 -> V_108 ;
int V_153 = V_110 -> V_153 ;
bool V_395 ;
F_2 ( ! V_37 -> V_124 ) ;
if ( V_110 -> V_207 )
return;
V_110 -> V_207 = true ;
F_203 ( V_2 ) ;
V_395 = F_174 ( V_37 ) ;
if ( V_395 )
V_4 -> V_280 . V_364 ( V_37 ) ;
F_30 (dev, crtc, encoder)
if ( V_78 -> V_396 )
V_78 -> V_396 ( V_78 ) ;
F_211 ( V_110 ) ;
if ( V_4 -> V_397 &&
F_21 ( V_37 , V_47 ) ) {
F_11 ( F_204 ( V_108 ) , V_398 | V_399 |
F_205 ( V_108 ) ) ;
F_11 ( F_206 ( V_108 ) , V_4 -> V_400 ) ;
F_11 ( F_207 ( V_108 ) , V_4 -> V_397 ) ;
}
F_208 ( V_37 ) ;
F_212 ( V_37 ) ;
F_213 ( V_37 ) ;
F_115 ( V_4 , V_108 , V_395 ) ;
F_121 ( V_4 , V_153 , V_108 ) ;
if ( V_395 )
F_198 ( V_37 ) ;
F_151 ( & V_2 -> V_299 ) ;
F_153 ( V_2 ) ;
F_152 ( & V_2 -> V_299 ) ;
F_209 ( V_37 , true ) ;
F_30 (dev, crtc, encoder)
V_78 -> V_401 ( V_78 ) ;
F_45 ( V_2 , V_110 -> V_108 ) ;
}
static void F_214 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
struct V_77 * V_78 ;
int V_108 = V_110 -> V_108 ;
int V_153 = V_110 -> V_153 ;
T_1 V_10 , V_303 ;
if ( ! V_110 -> V_207 )
return;
F_30 (dev, crtc, encoder)
V_78 -> V_402 ( V_78 ) ;
F_171 ( V_37 ) ;
F_215 ( V_2 , V_108 ) ;
F_209 ( V_37 , false ) ;
F_123 ( V_4 , V_153 , V_108 ) ;
if ( V_4 -> V_403 == V_153 )
F_216 ( V_2 ) ;
F_117 ( V_4 , V_108 ) ;
F_11 ( F_204 ( V_108 ) , 0 ) ;
F_11 ( F_207 ( V_108 ) , 0 ) ;
F_30 (dev, crtc, encoder)
if ( V_78 -> V_404 )
V_78 -> V_404 ( V_78 ) ;
F_169 ( V_37 ) ;
F_111 ( V_4 , V_108 ) ;
if ( F_61 ( V_2 ) ) {
V_10 = F_81 ( V_108 ) ;
V_303 = F_4 ( V_10 ) ;
V_303 &= ~ ( V_375 | V_168 ) ;
V_303 |= V_405 ;
F_11 ( V_10 , V_303 ) ;
V_303 = F_4 ( V_132 ) ;
switch ( V_108 ) {
case 0 :
V_303 &= ~ ( V_366 | V_367 ) ;
break;
case 1 :
V_303 &= ~ ( V_368 | V_369 ) ;
break;
case 2 :
V_303 &= ~ ( V_370 | V_371 ) ;
break;
default:
F_127 () ;
}
F_11 ( V_132 , V_303 ) ;
}
F_104 ( V_110 ) ;
F_168 ( V_110 ) ;
V_110 -> V_207 = false ;
F_203 ( V_2 ) ;
F_151 ( & V_2 -> V_299 ) ;
F_153 ( V_2 ) ;
F_152 ( & V_2 -> V_299 ) ;
}
static void F_217 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
struct V_77 * V_78 ;
int V_108 = V_110 -> V_108 ;
int V_153 = V_110 -> V_153 ;
enum V_107 V_111 = V_110 -> V_111 ;
bool V_395 ;
if ( ! V_110 -> V_207 )
return;
V_395 = F_174 ( V_37 ) ;
F_30 (dev, crtc, encoder)
V_78 -> V_402 ( V_78 ) ;
F_171 ( V_37 ) ;
F_215 ( V_2 , V_108 ) ;
F_209 ( V_37 , false ) ;
F_123 ( V_4 , V_153 , V_108 ) ;
if ( V_4 -> V_403 == V_153 )
F_216 ( V_2 ) ;
F_117 ( V_4 , V_108 ) ;
F_218 ( V_4 , V_111 ) ;
F_11 ( F_204 ( V_108 ) , 0 ) ;
F_11 ( F_207 ( V_108 ) , 0 ) ;
F_219 ( V_110 ) ;
F_30 (dev, crtc, encoder)
if ( V_78 -> V_404 )
V_78 -> V_404 ( V_78 ) ;
if ( V_395 ) {
F_114 ( V_4 ) ;
F_220 ( V_37 ) ;
}
V_110 -> V_207 = false ;
F_203 ( V_2 ) ;
F_151 ( & V_2 -> V_299 ) ;
F_153 ( V_2 ) ;
F_152 ( & V_2 -> V_299 ) ;
}
static void F_221 ( struct V_36 * V_37 )
{
struct V_110 * V_110 = F_39 ( V_37 ) ;
F_199 ( V_110 ) ;
}
static void F_222 ( struct V_36 * V_37 )
{
struct V_110 * V_110 = F_39 ( V_37 ) ;
V_110 -> V_111 = V_110 -> V_108 ;
F_223 ( V_37 ) ;
}
static void F_224 ( struct V_110 * V_110 , bool V_401 )
{
if ( ! V_401 && V_110 -> V_406 ) {
struct V_1 * V_2 = V_110 -> V_204 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_151 ( & V_2 -> V_299 ) ;
V_4 -> V_236 . V_237 = false ;
( void ) F_225 ( V_110 -> V_406 ) ;
V_4 -> V_236 . V_237 = true ;
F_152 ( & V_2 -> V_299 ) ;
}
}
static void F_226 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
struct V_77 * V_78 ;
int V_108 = V_110 -> V_108 ;
int V_153 = V_110 -> V_153 ;
F_2 ( ! V_37 -> V_124 ) ;
if ( V_110 -> V_207 )
return;
V_110 -> V_207 = true ;
F_203 ( V_2 ) ;
F_93 ( V_4 , V_108 ) ;
F_115 ( V_4 , V_108 , false ) ;
F_121 ( V_4 , V_153 , V_108 ) ;
F_208 ( V_37 ) ;
F_153 ( V_2 ) ;
F_224 ( V_110 , true ) ;
F_209 ( V_37 , true ) ;
F_30 (dev, crtc, encoder)
V_78 -> V_401 ( V_78 ) ;
}
static void F_227 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
struct V_77 * V_78 ;
int V_108 = V_110 -> V_108 ;
int V_153 = V_110 -> V_153 ;
if ( ! V_110 -> V_207 )
return;
F_30 (dev, crtc, encoder)
V_78 -> V_402 ( V_78 ) ;
F_171 ( V_37 ) ;
F_215 ( V_2 , V_108 ) ;
F_224 ( V_110 , false ) ;
F_209 ( V_37 , false ) ;
if ( V_4 -> V_403 == V_153 )
F_216 ( V_2 ) ;
F_123 ( V_4 , V_153 , V_108 ) ;
F_117 ( V_4 , V_108 ) ;
F_98 ( V_4 , V_108 ) ;
V_110 -> V_207 = false ;
F_153 ( V_2 ) ;
F_203 ( V_2 ) ;
}
static void F_228 ( struct V_36 * V_37 )
{
}
static void F_229 ( struct V_36 * V_37 ,
bool V_124 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_288 * V_289 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
if ( ! V_2 -> V_290 -> V_291 )
return;
V_289 = V_2 -> V_290 -> V_291 -> V_292 ;
if ( ! V_289 -> V_293 )
return;
switch ( V_108 ) {
case 0 :
V_289 -> V_293 -> V_407 = V_124 ? V_37 -> V_351 . V_408 : 0 ;
V_289 -> V_293 -> V_409 = V_124 ? V_37 -> V_351 . V_410 : 0 ;
break;
case 1 :
V_289 -> V_293 -> V_411 = V_124 ? V_37 -> V_351 . V_408 : 0 ;
V_289 -> V_293 -> V_412 = V_124 ? V_37 -> V_351 . V_410 : 0 ;
break;
default:
F_10 ( L_82 , F_71 ( V_108 ) ) ;
break;
}
}
void F_230 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_77 * V_77 ;
bool V_401 = false ;
F_30 (dev, crtc, intel_encoder)
V_401 |= V_77 -> V_413 ;
if ( V_401 )
V_4 -> V_280 . V_414 ( V_37 ) ;
else
V_4 -> V_280 . V_415 ( V_37 ) ;
F_229 ( V_37 , V_401 ) ;
}
static void F_231 ( struct V_36 * V_37 )
{
}
static void F_232 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_416 * V_417 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( ! V_37 -> V_124 ) ;
V_4 -> V_280 . V_415 ( V_37 ) ;
F_229 ( V_37 , false ) ;
V_4 -> V_280 . V_418 ( V_37 ) ;
F_233 ( V_2 -> V_5 , F_39 ( V_37 ) -> V_153 ) ;
F_99 ( V_2 -> V_5 , F_39 ( V_37 ) -> V_108 ) ;
if ( V_37 -> V_247 ) {
F_151 ( & V_2 -> V_299 ) ;
F_132 ( F_136 ( V_37 -> V_247 ) -> V_226 ) ;
F_152 ( & V_2 -> V_299 ) ;
V_37 -> V_247 = NULL ;
}
F_234 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_417 -> V_78 || ! V_417 -> V_78 -> V_37 )
continue;
if ( V_417 -> V_78 -> V_37 != V_37 )
continue;
V_417 -> V_419 = V_420 ;
F_235 ( V_417 -> V_78 ) -> V_413 = false ;
}
}
void F_236 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
F_234 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_37 -> V_124 )
F_232 ( V_37 ) ;
}
}
void F_237 ( struct V_421 * V_78 )
{
}
void F_238 ( struct V_421 * V_78 )
{
struct V_77 * V_77 = F_235 ( V_78 ) ;
F_239 ( V_78 ) ;
F_240 ( V_77 ) ;
}
void F_241 ( struct V_77 * V_78 , int V_351 )
{
if ( V_351 == V_422 ) {
V_78 -> V_413 = true ;
F_230 ( V_78 -> V_204 . V_37 ) ;
} else {
V_78 -> V_413 = false ;
F_230 ( V_78 -> V_204 . V_37 ) ;
}
}
static void F_242 ( struct V_423 * V_417 )
{
if ( V_417 -> V_424 ( V_417 ) ) {
struct V_77 * V_78 = V_417 -> V_78 ;
struct V_36 * V_37 ;
bool V_425 ;
enum V_108 V_108 ;
F_44 ( L_83 ,
V_417 -> V_204 . V_204 . V_26 ,
F_243 ( & V_417 -> V_204 ) ) ;
F_50 ( V_417 -> V_204 . V_419 == V_420 ,
L_84 ) ;
F_50 ( V_417 -> V_204 . V_78 != & V_78 -> V_204 ,
L_85 ) ;
F_50 ( ! V_78 -> V_413 ,
L_86 ) ;
V_425 = V_78 -> V_424 ( V_78 , & V_108 ) ;
F_50 ( ! V_425 , L_87 ) ;
if ( F_2 ( ! V_78 -> V_204 . V_37 ) )
return;
V_37 = V_78 -> V_204 . V_37 ;
F_50 ( ! V_37 -> V_124 , L_88 ) ;
F_50 ( ! F_39 ( V_37 ) -> V_207 , L_89 ) ;
F_50 ( V_108 != F_39 ( V_37 ) -> V_108 ,
L_90 ) ;
}
}
void F_244 ( struct V_416 * V_417 , int V_351 )
{
struct V_77 * V_78 = F_245 ( V_417 ) ;
if ( V_351 != V_422 )
V_351 = V_420 ;
if ( V_351 == V_417 -> V_419 )
return;
V_417 -> V_419 = V_351 ;
if ( V_78 -> V_204 . V_37 )
F_241 ( V_78 , V_351 ) ;
else
F_2 ( V_78 -> V_413 != false ) ;
F_246 ( V_417 -> V_2 ) ;
}
bool F_247 ( struct V_423 * V_417 )
{
enum V_108 V_108 = 0 ;
struct V_77 * V_78 = V_417 -> V_78 ;
return V_78 -> V_424 ( V_78 , & V_108 ) ;
}
static bool F_248 ( struct V_36 * V_37 ,
const struct V_426 * V_351 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
if ( F_3 ( V_2 ) ) {
if ( V_351 -> clock * 3 > V_428 * 4 )
return false ;
}
if ( ! ( V_427 -> V_429 & V_430 ) )
F_249 ( V_427 , 0 ) ;
if ( ( F_47 ( V_2 ) -> V_115 > 4 || F_24 ( V_2 ) ) &&
V_427 -> V_431 == V_427 -> V_408 )
return false ;
return true ;
}
static int F_250 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_251 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_252 ( struct V_1 * V_2 )
{
return 333000 ;
}
static int F_253 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_254 ( struct V_1 * V_2 )
{
T_4 V_432 = 0 ;
F_255 ( V_2 -> V_433 , V_434 , & V_432 ) ;
if ( V_432 & V_435 )
return 133000 ;
else {
switch ( V_432 & V_436 ) {
case V_437 :
return 333000 ;
default:
case V_438 :
return 190000 ;
}
}
}
static int F_256 ( struct V_1 * V_2 )
{
return 266000 ;
}
static int F_257 ( struct V_1 * V_2 )
{
T_4 V_439 = 0 ;
switch ( V_439 & V_440 ) {
case V_441 :
case V_442 :
return 200000 ;
case V_443 :
return 250000 ;
case V_444 :
return 133000 ;
}
return 0 ;
}
static int F_258 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_259 ( T_1 * V_445 , T_1 * V_446 )
{
while ( * V_445 > 0xffffff || * V_446 > 0xffffff ) {
* V_445 >>= 1 ;
* V_446 >>= 1 ;
}
}
static void
F_260 ( int V_275 , int V_447 , int V_448 ,
int V_449 , struct V_450 * V_451 )
{
V_451 -> V_452 = 64 ;
V_451 -> V_453 = V_275 * V_448 ;
V_451 -> V_454 = V_449 * V_447 * 8 ;
F_259 ( & V_451 -> V_453 , & V_451 -> V_454 ) ;
V_451 -> V_455 = V_448 ;
V_451 -> V_456 = V_449 ;
F_259 ( & V_451 -> V_455 , & V_451 -> V_456 ) ;
}
static inline bool F_261 ( struct V_3 * V_4 )
{
if ( V_457 >= 0 )
return V_457 != 0 ;
return V_4 -> V_458
&& ! ( V_4 -> V_150 & V_459 ) ;
}
static bool F_262 ( struct V_36 * V_37 ,
struct V_246 * V_247 ,
unsigned int * V_460 ,
struct V_426 * V_351 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_416 * V_417 ;
struct V_77 * V_77 ;
unsigned int V_461 = V_462 , V_372 ;
F_30 (dev, crtc, intel_encoder) {
if ( V_77 -> type == V_40 ) {
unsigned int V_463 ;
if ( ( F_4 ( V_41 ) & V_464 ) ==
V_465 )
V_463 = 8 ;
else
V_463 = 6 ;
if ( V_463 < V_461 ) {
F_44 ( L_91 , V_461 , V_463 ) ;
V_461 = V_463 ;
}
continue;
}
F_234 (connector, &dev->mode_config.connector_list,
head) {
if ( V_417 -> V_78 != & V_77 -> V_204 )
continue;
if ( V_417 -> V_466 . V_372 &&
V_417 -> V_466 . V_372 < V_461 ) {
F_44 ( L_92 , V_461 , V_417 -> V_466 . V_372 ) ;
V_461 = V_417 -> V_466 . V_372 ;
}
}
if ( V_77 -> type == V_47 ) {
unsigned int V_467 = V_4 -> V_468 . V_242 / 3 ;
if ( V_467 && V_467 < V_461 ) {
F_44 ( L_93 , V_461 , V_467 ) ;
V_461 = V_467 ;
}
continue;
}
if ( V_77 -> type == V_53 ) {
if ( V_461 > 8 && V_461 < 12 ) {
F_44 ( L_94 ) ;
V_461 = 12 ;
} else {
F_44 ( L_95 ) ;
V_461 = 8 ;
}
}
}
if ( V_351 -> V_429 & V_469 ) {
F_44 ( L_96 ) ;
V_461 = 6 ;
}
switch ( V_247 -> V_470 ) {
case 8 :
V_372 = 8 ;
break;
case 15 :
case 16 :
V_372 = 6 ;
break;
case 24 :
V_372 = 8 ;
break;
case 30 :
V_372 = 10 ;
break;
case 48 :
V_372 = 12 ;
break;
default:
F_263 ( L_97 ) ;
V_372 = V_79 ( ( unsigned int ) 8 , V_461 ) ;
break;
}
V_461 = V_79 ( V_461 , V_372 ) ;
F_44 ( L_98 ,
V_372 , V_461 ) ;
* V_460 = V_461 * 3 ;
return V_461 != V_372 ;
}
static int F_264 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_38 = 27000 ;
return 100000 ;
if ( F_21 ( V_37 , V_54 ) ) {
V_38 = 96000 ;
} else if ( F_21 ( V_37 , V_40 ) ) {
if ( F_261 ( V_4 ) )
V_38 = 100000 ;
else
V_38 = 96000 ;
} else if ( F_21 ( V_37 , V_47 ) ) {
V_38 = 100000 ;
}
return V_38 ;
}
static int F_265 ( struct V_36 * V_37 , int V_471 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_38 ;
if ( F_26 ( V_2 ) ) {
V_38 = F_264 ( V_37 ) ;
} else if ( F_21 ( V_37 , V_40 ) &&
F_261 ( V_4 ) && V_471 < 2 ) {
V_38 = V_4 -> V_472 * 1000 ;
F_44 ( L_99 ,
V_38 / 1000 ) ;
} else if ( ! F_27 ( V_2 ) ) {
V_38 = 96000 ;
} else {
V_38 = 48000 ;
}
return V_38 ;
}
static void F_266 ( struct V_426 * V_427 ,
T_3 * clock )
{
if ( V_427 -> clock >= 100000
&& V_427 -> clock < 140500 ) {
clock -> V_71 = 2 ;
clock -> V_72 = 10 ;
clock -> V_74 = 3 ;
clock -> V_76 = 16 ;
clock -> V_69 = 8 ;
} else if ( V_427 -> clock >= 140500
&& V_427 -> clock <= 200000 ) {
clock -> V_71 = 1 ;
clock -> V_72 = 10 ;
clock -> V_74 = 6 ;
clock -> V_76 = 12 ;
clock -> V_69 = 8 ;
}
}
static void F_267 ( struct V_36 * V_37 ,
T_3 * clock ,
T_3 * V_473 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
T_1 V_389 , V_474 = 0 ;
if ( F_25 ( V_2 ) ) {
V_389 = ( 1 << clock -> V_74 ) << 16 | clock -> V_76 << 8 | clock -> V_69 ;
if ( V_473 )
V_474 = ( 1 << V_473 -> V_74 ) << 16 |
V_473 -> V_76 << 8 | V_473 -> V_69 ;
} else {
V_389 = clock -> V_74 << 16 | clock -> V_76 << 8 | clock -> V_69 ;
if ( V_473 )
V_474 = V_473 -> V_74 << 16 | V_473 -> V_76 << 8 |
V_473 -> V_69 ;
}
F_11 ( F_268 ( V_108 ) , V_389 ) ;
V_110 -> V_475 = false ;
if ( F_21 ( V_37 , V_40 ) &&
V_473 && V_476 ) {
F_11 ( F_269 ( V_108 ) , V_474 ) ;
V_110 -> V_475 = true ;
} else {
F_11 ( F_269 ( V_108 ) , V_389 ) ;
}
}
static void F_270 ( struct V_36 * V_37 , T_3 * clock ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
T_1 V_303 ;
V_303 = F_4 ( V_50 ) ;
V_303 |= V_173 | V_477 ;
if ( V_108 == 1 ) {
V_303 |= V_148 ;
} else {
V_303 &= ~ V_148 ;
}
V_303 |= V_4 -> V_478 ;
if ( clock -> V_72 == 7 )
V_303 |= V_479 | V_35 ;
else
V_303 &= ~ ( V_479 | V_35 ) ;
if ( F_47 ( V_2 ) -> V_115 >= 4 ) {
if ( V_4 -> V_480 )
V_303 |= V_481 ;
else
V_303 &= ~ V_481 ;
}
V_303 &= ~ ( V_482 | V_483 ) ;
if ( V_427 -> V_11 & V_484 )
V_303 |= V_482 ;
if ( V_427 -> V_11 & V_485 )
V_303 |= V_483 ;
F_11 ( V_50 , V_303 ) ;
}
static void F_271 ( struct V_36 * V_37 ,
struct V_426 * V_351 ,
struct V_426 * V_427 ,
T_3 * clock , T_3 * V_473 ,
int V_471 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
T_1 V_388 , V_486 , V_487 ;
T_1 V_93 , V_94 , V_95 , V_96 , V_97 ;
bool V_488 ;
T_1 V_303 ;
V_488 = F_21 ( V_37 , V_56 ) ||
F_21 ( V_37 , V_53 ) ;
V_388 = V_489 ;
V_388 |= V_490 ;
V_388 |= V_491 ;
V_388 |= V_492 ;
F_11 ( F_57 ( V_108 ) , V_388 ) ;
F_15 ( F_57 ( V_108 ) ) ;
V_93 = clock -> V_74 ;
V_94 = clock -> V_76 ;
V_95 = clock -> V_69 ;
V_96 = clock -> V_71 ;
V_97 = clock -> V_72 ;
V_486 = ( ( V_94 << V_493 ) | ( V_95 & V_494 ) ) ;
V_486 |= ( ( V_96 << V_495 ) | ( V_97 << V_496 ) ) ;
V_486 |= ( ( V_93 << V_497 ) ) ;
V_486 |= ( 1 << V_498 ) ;
V_486 |= ( 1 << V_499 ) ;
V_486 |= V_500 ;
F_13 ( V_4 , F_272 ( V_108 ) , V_486 ) ;
F_13 ( V_4 , F_273 ( V_108 ) , 0x01000000 ) ;
V_487 = ( 1 << V_501 ) | ( 5 << V_502 ) |
( 3 << V_503 ) | ( 1 << 20 ) |
( 7 << V_504 ) | ( 8 << V_505 ) |
( 5 << V_506 ) ;
F_13 ( V_4 , F_274 ( V_108 ) , V_487 ) ;
F_13 ( V_4 , F_275 ( V_108 ) , 0x005f003b ) ;
V_388 |= V_127 ;
F_11 ( F_57 ( V_108 ) , V_388 ) ;
F_15 ( F_57 ( V_108 ) ) ;
if ( F_42 ( ( ( F_4 ( F_57 ( V_108 ) ) & V_507 ) == V_507 ) , 1 ) )
F_10 ( L_100 , V_108 ) ;
F_13 ( V_4 , V_508 , 0x620 ) ;
if ( F_21 ( V_37 , V_46 ) )
F_276 ( V_37 , V_351 , V_427 ) ;
F_11 ( F_57 ( V_108 ) , V_388 ) ;
F_15 ( F_57 ( V_108 ) ) ;
F_97 ( 150 ) ;
V_303 = 0 ;
if ( V_488 ) {
V_303 = F_277 ( V_427 ) ;
if ( V_303 > 1 )
V_303 = ( V_303 - 1 ) << V_509 ;
else
V_303 = 0 ;
}
F_11 ( F_278 ( V_108 ) , V_303 ) ;
F_15 ( F_278 ( V_108 ) ) ;
if( F_21 ( V_37 , V_46 )
|| F_21 ( V_37 , V_53 ) )
{
V_303 = 0x1000C4 ;
if( V_108 == 1 )
V_303 |= ( 1 << 21 ) ;
F_13 ( V_4 , V_510 , V_303 ) ;
}
if( F_21 ( V_37 , V_47 ) )
{
V_303 = 0x1000C4 ;
if( V_108 == 1 )
V_303 |= ( 1 << 21 ) ;
F_13 ( V_4 , V_511 , V_303 ) ;
}
}
static void F_279 ( struct V_36 * V_37 ,
struct V_426 * V_351 ,
struct V_426 * V_427 ,
T_3 * clock , T_3 * V_473 ,
int V_471 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
T_1 V_388 ;
bool V_488 ;
F_267 ( V_37 , clock , V_473 ) ;
V_488 = F_21 ( V_37 , V_56 ) ||
F_21 ( V_37 , V_53 ) ;
V_388 = V_489 ;
if ( F_21 ( V_37 , V_40 ) )
V_388 |= V_512 ;
else
V_388 |= V_513 ;
if ( V_488 ) {
int V_514 = F_277 ( V_427 ) ;
if ( V_514 > 1 ) {
if ( F_280 ( V_2 ) || F_281 ( V_2 ) || F_282 ( V_2 ) )
V_388 |= ( V_514 - 1 ) << V_515 ;
}
V_388 |= V_516 ;
}
if ( F_21 ( V_37 , V_46 ) )
V_388 |= V_516 ;
if ( F_25 ( V_2 ) )
V_388 |= ( 1 << ( clock -> V_71 - 1 ) ) << V_517 ;
else {
V_388 |= ( 1 << ( clock -> V_71 - 1 ) ) << V_518 ;
if ( F_24 ( V_2 ) && V_473 )
V_388 |= ( 1 << ( V_473 -> V_71 - 1 ) ) << V_519 ;
}
switch ( clock -> V_72 ) {
case 5 :
V_388 |= V_520 ;
break;
case 7 :
V_388 |= V_521 ;
break;
case 10 :
V_388 |= V_522 ;
break;
case 14 :
V_388 |= V_523 ;
break;
}
if ( F_47 ( V_2 ) -> V_115 >= 4 )
V_388 |= ( 6 << V_524 ) ;
if ( V_488 && F_21 ( V_37 , V_525 ) )
V_388 |= V_526 ;
else if ( F_21 ( V_37 , V_525 ) )
V_388 |= 3 ;
else if ( F_21 ( V_37 , V_40 ) &&
F_261 ( V_4 ) && V_471 < 2 )
V_388 |= V_527 ;
else
V_388 |= V_528 ;
V_388 |= V_127 ;
F_11 ( F_57 ( V_108 ) , V_388 & ~ V_127 ) ;
F_15 ( F_57 ( V_108 ) ) ;
F_97 ( 150 ) ;
if ( F_21 ( V_37 , V_40 ) )
F_270 ( V_37 , clock , V_427 ) ;
if ( F_21 ( V_37 , V_46 ) )
F_276 ( V_37 , V_351 , V_427 ) ;
F_11 ( F_57 ( V_108 ) , V_388 ) ;
F_15 ( F_57 ( V_108 ) ) ;
F_97 ( 150 ) ;
if ( F_47 ( V_2 ) -> V_115 >= 4 ) {
T_1 V_303 = 0 ;
if ( V_488 ) {
V_303 = F_277 ( V_427 ) ;
if ( V_303 > 1 )
V_303 = ( V_303 - 1 ) << V_509 ;
else
V_303 = 0 ;
}
F_11 ( F_278 ( V_108 ) , V_303 ) ;
} else {
F_11 ( F_57 ( V_108 ) , V_388 ) ;
}
}
static void F_283 ( struct V_36 * V_37 ,
struct V_426 * V_427 ,
T_3 * clock , T_3 * V_473 ,
int V_471 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
T_1 V_388 ;
F_267 ( V_37 , clock , V_473 ) ;
V_388 = V_489 ;
if ( F_21 ( V_37 , V_40 ) ) {
V_388 |= ( 1 << ( clock -> V_71 - 1 ) ) << V_518 ;
} else {
if ( clock -> V_71 == 2 )
V_388 |= V_529 ;
else
V_388 |= ( clock -> V_71 - 2 ) << V_518 ;
if ( clock -> V_72 == 4 )
V_388 |= V_530 ;
}
if ( F_21 ( V_37 , V_525 ) )
V_388 |= 3 ;
else if ( F_21 ( V_37 , V_40 ) &&
F_261 ( V_4 ) && V_471 < 2 )
V_388 |= V_527 ;
else
V_388 |= V_528 ;
V_388 |= V_127 ;
F_11 ( F_57 ( V_108 ) , V_388 & ~ V_127 ) ;
F_15 ( F_57 ( V_108 ) ) ;
F_97 ( 150 ) ;
if ( F_21 ( V_37 , V_40 ) )
F_270 ( V_37 , clock , V_427 ) ;
F_11 ( F_57 ( V_108 ) , V_388 ) ;
F_15 ( F_57 ( V_108 ) ) ;
F_97 ( 150 ) ;
F_11 ( F_57 ( V_108 ) , V_388 ) ;
}
static void F_284 ( struct V_110 * V_110 ,
struct V_426 * V_351 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_110 -> V_204 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_108 V_108 = V_110 -> V_108 ;
enum V_107 V_111 = V_110 -> V_111 ;
T_5 V_531 ;
if ( ! F_27 ( V_2 ) && V_427 -> V_11 & V_532 ) {
V_427 -> V_533 -= 1 ;
V_427 -> V_534 -= 1 ;
V_531 = V_427 -> V_535
- V_427 -> V_536 / 2 ;
} else {
V_531 = 0 ;
}
if ( F_47 ( V_2 ) -> V_115 > 3 )
F_11 ( F_196 ( V_111 ) , V_531 ) ;
F_11 ( F_184 ( V_111 ) ,
( V_427 -> V_537 - 1 ) |
( ( V_427 -> V_536 - 1 ) << 16 ) ) ;
F_11 ( F_186 ( V_111 ) ,
( V_427 -> V_538 - 1 ) |
( ( V_427 -> V_539 - 1 ) << 16 ) ) ;
F_11 ( F_188 ( V_111 ) ,
( V_427 -> V_535 - 1 ) |
( ( V_427 -> V_540 - 1 ) << 16 ) ) ;
F_11 ( F_190 ( V_111 ) ,
( V_427 -> V_541 - 1 ) |
( ( V_427 -> V_533 - 1 ) << 16 ) ) ;
F_11 ( F_192 ( V_111 ) ,
( V_427 -> V_542 - 1 ) |
( ( V_427 -> V_534 - 1 ) << 16 ) ) ;
F_11 ( F_194 ( V_111 ) ,
( V_427 -> V_543 - 1 ) |
( ( V_427 -> V_544 - 1 ) << 16 ) ) ;
if ( F_63 ( V_2 ) && V_111 == V_545 &&
( V_108 == V_149 || V_108 == V_316 ) )
F_11 ( F_190 ( V_108 ) , F_4 ( F_190 ( V_111 ) ) ) ;
F_11 ( F_285 ( V_108 ) ,
( ( V_351 -> V_408 - 1 ) << 16 ) | ( V_351 -> V_410 - 1 ) ) ;
}
static int F_286 ( struct V_36 * V_37 ,
struct V_426 * V_351 ,
struct V_426 * V_427 ,
int V_240 , int V_241 ,
struct V_246 * V_247 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
int V_153 = V_110 -> V_153 ;
int V_38 , V_471 = 0 ;
T_3 clock , V_473 ;
T_1 V_251 , V_546 ;
bool V_547 , V_548 = false , V_488 = false ;
bool V_549 = false , V_550 = false , V_551 = false ;
struct V_77 * V_78 ;
const T_2 * V_39 ;
int V_230 ;
F_30 (dev, crtc, encoder) {
switch ( V_78 -> type ) {
case V_40 :
V_549 = true ;
break;
case V_56 :
case V_53 :
V_488 = true ;
if ( V_78 -> V_552 )
V_550 = true ;
break;
case V_525 :
V_550 = true ;
break;
case V_46 :
V_551 = true ;
break;
}
V_471 ++ ;
}
V_38 = F_265 ( V_37 , V_471 ) ;
V_39 = F_23 ( V_37 , V_38 ) ;
V_547 = V_39 -> V_553 ( V_39 , V_37 , V_427 -> clock , V_38 , NULL ,
& clock ) ;
if ( ! V_547 ) {
F_10 ( L_101 ) ;
return - V_235 ;
}
F_209 ( V_37 , true ) ;
if ( V_549 && V_4 -> V_554 ) {
V_548 = V_39 -> V_553 ( V_39 , V_37 ,
V_4 -> V_555 ,
V_38 ,
& clock ,
& V_473 ) ;
}
if ( V_488 && V_550 )
F_266 ( V_427 , & clock ) ;
if ( F_27 ( V_2 ) )
F_283 ( V_37 , V_427 , & clock ,
V_548 ? & V_473 : NULL ,
V_471 ) ;
else if ( F_26 ( V_2 ) )
F_271 ( V_37 , V_351 , V_427 , & clock ,
V_548 ? & V_473 : NULL ,
V_471 ) ;
else
F_279 ( V_37 , V_351 , V_427 , & clock ,
V_548 ? & V_473 : NULL ,
V_471 ) ;
V_546 = F_4 ( F_49 ( V_108 ) ) ;
V_251 = V_556 ;
if ( V_108 == 0 )
V_251 &= ~ V_157 ;
else
V_251 |= V_557 ;
if ( V_108 == 0 && F_47 ( V_2 ) -> V_115 < 4 ) {
if ( V_351 -> clock >
V_4 -> V_280 . V_558 ( V_2 ) * 9 / 10 )
V_546 |= V_559 ;
else
V_546 &= ~ V_559 ;
}
V_546 &= ~ ( V_560 | V_561 ) ;
if ( V_551 ) {
if ( V_427 -> V_429 & V_469 ) {
V_546 |= V_562 |
V_561 |
V_563 ;
}
}
if ( F_26 ( V_2 ) && F_21 ( V_37 , V_47 ) ) {
if ( V_427 -> V_429 & V_469 ) {
V_546 |= V_562 |
V_152 |
V_117 ;
}
}
F_44 ( L_102 , V_108 == 0 ? 'A' : 'B' ) ;
F_287 ( V_351 ) ;
if ( F_288 ( V_2 ) ) {
if ( V_110 -> V_475 ) {
F_44 ( L_103 ) ;
V_546 |= V_564 ;
} else {
F_44 ( L_104 ) ;
V_546 &= ~ V_564 ;
}
}
V_546 &= ~ V_213 ;
if ( ! F_27 ( V_2 ) &&
V_427 -> V_11 & V_532 )
V_546 |= V_565 ;
else
V_546 |= V_566 ;
F_284 ( V_110 , V_351 , V_427 ) ;
F_11 ( F_289 ( V_153 ) ,
( ( V_351 -> V_410 - 1 ) << 16 ) |
( V_351 -> V_408 - 1 ) ) ;
F_11 ( F_290 ( V_153 ) , 0 ) ;
F_11 ( F_49 ( V_108 ) , V_546 ) ;
F_15 ( F_49 ( V_108 ) ) ;
F_115 ( V_4 , V_108 , false ) ;
F_45 ( V_2 , V_108 ) ;
F_11 ( F_74 ( V_153 ) , V_251 ) ;
F_15 ( F_74 ( V_153 ) ) ;
V_230 = F_150 ( V_37 , V_240 , V_241 , V_247 ) ;
F_203 ( V_2 ) ;
return V_230 ;
}
static void F_291 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_567 * V_568 = & V_2 -> V_568 ;
struct V_77 * V_78 ;
T_1 V_303 ;
bool V_569 = false ;
bool V_570 = false ;
bool V_571 = false ;
bool V_572 = false ;
bool V_573 = false ;
bool V_574 = false ;
F_234 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_78 -> type ) {
case V_40 :
V_572 = true ;
V_569 = true ;
break;
case V_47 :
V_572 = true ;
if ( F_173 ( & V_78 -> V_204 ) )
V_571 = true ;
else
V_570 = true ;
break;
}
}
if ( F_90 ( V_2 ) ) {
V_573 = V_4 -> V_575 ;
V_574 = V_573 ;
} else {
V_573 = false ;
V_574 = true ;
}
F_44 ( L_105 ,
V_572 , V_569 , V_571 , V_570 ,
V_573 ) ;
V_303 = F_4 ( V_159 ) ;
V_303 &= ~ V_161 ;
if ( V_573 )
V_303 |= V_576 ;
else
V_303 |= V_577 ;
if ( V_572 ) {
V_303 &= ~ V_160 ;
V_303 |= V_578 ;
if ( F_261 ( V_4 ) && V_574 ) {
F_44 ( L_106 ) ;
V_303 |= V_579 ;
} else
V_303 &= ~ V_579 ;
F_11 ( V_159 , V_303 ) ;
F_15 ( V_159 ) ;
F_97 ( 200 ) ;
V_303 &= ~ V_580 ;
if ( V_570 ) {
if ( F_261 ( V_4 ) && V_574 ) {
F_44 ( L_107 ) ;
V_303 |= V_581 ;
}
else
V_303 |= V_582 ;
} else
V_303 |= V_583 ;
F_11 ( V_159 , V_303 ) ;
F_15 ( V_159 ) ;
F_97 ( 200 ) ;
} else {
F_44 ( L_108 ) ;
V_303 &= ~ V_580 ;
V_303 |= V_583 ;
F_11 ( V_159 , V_303 ) ;
F_15 ( V_159 ) ;
F_97 ( 200 ) ;
V_303 &= ~ V_160 ;
V_303 |= V_584 ;
V_303 &= ~ V_579 ;
F_11 ( V_159 , V_303 ) ;
F_15 ( V_159 ) ;
F_97 ( 200 ) ;
}
}
static void F_292 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_567 * V_568 = & V_2 -> V_568 ;
struct V_77 * V_78 ;
bool V_585 = false ;
bool V_586 = false ;
T_1 V_191 ;
F_234 (encoder, &mode_config->encoder_list, base.head) {
switch ( V_78 -> type ) {
case V_54 :
V_585 = true ;
break;
}
}
if ( ! V_585 )
return;
if ( F_63 ( V_2 ) && ( V_2 -> V_587 & 0xFF00 ) == 0x0C00 )
V_586 = true ;
V_191 = F_101 ( V_4 , V_588 , V_196 ) ;
V_191 &= ~ V_350 ;
V_191 |= V_589 ;
F_100 ( V_4 , V_588 , V_191 , V_196 ) ;
F_97 ( 24 ) ;
V_191 = F_101 ( V_4 , V_588 , V_196 ) ;
V_191 &= ~ V_589 ;
F_100 ( V_4 , V_588 , V_191 , V_196 ) ;
if ( ! V_586 ) {
V_191 = F_4 ( V_590 ) ;
V_191 |= V_591 ;
F_11 ( V_590 , V_191 ) ;
if ( F_9 ( F_4 ( V_590 ) &
V_592 , 100 ) )
F_10 ( L_109 ) ;
V_191 = F_4 ( V_590 ) ;
V_191 &= ~ V_591 ;
F_11 ( V_590 , V_191 ) ;
if ( F_9 ( ( F_4 ( V_590 ) &
V_592 ) == 0 ,
100 ) )
F_10 ( L_110 ) ;
}
V_191 = F_101 ( V_4 , 0x8008 , V_593 ) ;
V_191 &= ~ ( 0xFF << 24 ) ;
V_191 |= ( 0x12 << 24 ) ;
F_100 ( V_4 , 0x8008 , V_191 , V_593 ) ;
if ( ! V_586 ) {
V_191 = F_101 ( V_4 , 0x808C , V_593 ) ;
V_191 &= ~ ( 0x3 << 6 ) ;
V_191 |= ( 1 << 6 ) | ( 1 << 0 ) ;
F_100 ( V_4 , 0x808C , V_191 , V_593 ) ;
}
if ( V_586 ) {
V_191 = F_101 ( V_4 , 0x800C , V_593 ) ;
V_191 |= 0x7FFF ;
F_100 ( V_4 , 0x800C , V_191 , V_593 ) ;
}
V_191 = F_101 ( V_4 , 0x2008 , V_593 ) ;
V_191 |= ( 1 << 11 ) ;
F_100 ( V_4 , 0x2008 , V_191 , V_593 ) ;
V_191 = F_101 ( V_4 , 0x2108 , V_593 ) ;
V_191 |= ( 1 << 11 ) ;
F_100 ( V_4 , 0x2108 , V_191 , V_593 ) ;
if ( V_586 ) {
V_191 = F_101 ( V_4 , 0x2038 , V_593 ) ;
V_191 |= ( 0x3F << 24 ) | ( 0xF << 20 ) | ( 0xF << 16 ) ;
F_100 ( V_4 , 0x2038 , V_191 , V_593 ) ;
V_191 = F_101 ( V_4 , 0x2138 , V_593 ) ;
V_191 |= ( 0x3F << 24 ) | ( 0xF << 20 ) | ( 0xF << 16 ) ;
F_100 ( V_4 , 0x2138 , V_191 , V_593 ) ;
V_191 = F_101 ( V_4 , 0x203C , V_593 ) ;
V_191 |= ( 0x3F << 8 ) ;
F_100 ( V_4 , 0x203C , V_191 , V_593 ) ;
V_191 = F_101 ( V_4 , 0x213C , V_593 ) ;
V_191 |= ( 0x3F << 8 ) ;
F_100 ( V_4 , 0x213C , V_191 , V_593 ) ;
}
V_191 = F_101 ( V_4 , 0x206C , V_593 ) ;
V_191 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_100 ( V_4 , 0x206C , V_191 , V_593 ) ;
V_191 = F_101 ( V_4 , 0x216C , V_593 ) ;
V_191 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_100 ( V_4 , 0x216C , V_191 , V_593 ) ;
if ( ! V_586 ) {
V_191 = F_101 ( V_4 , 0x2080 , V_593 ) ;
V_191 &= ~ ( 7 << 13 ) ;
V_191 |= ( 5 << 13 ) ;
F_100 ( V_4 , 0x2080 , V_191 , V_593 ) ;
V_191 = F_101 ( V_4 , 0x2180 , V_593 ) ;
V_191 &= ~ ( 7 << 13 ) ;
V_191 |= ( 5 << 13 ) ;
F_100 ( V_4 , 0x2180 , V_191 , V_593 ) ;
}
V_191 = F_101 ( V_4 , 0x208C , V_593 ) ;
V_191 &= ~ 0xFF ;
V_191 |= 0x1C ;
F_100 ( V_4 , 0x208C , V_191 , V_593 ) ;
V_191 = F_101 ( V_4 , 0x218C , V_593 ) ;
V_191 &= ~ 0xFF ;
V_191 |= 0x1C ;
F_100 ( V_4 , 0x218C , V_191 , V_593 ) ;
V_191 = F_101 ( V_4 , 0x2098 , V_593 ) ;
V_191 &= ~ ( 0xFF << 16 ) ;
V_191 |= ( 0x1C << 16 ) ;
F_100 ( V_4 , 0x2098 , V_191 , V_593 ) ;
V_191 = F_101 ( V_4 , 0x2198 , V_593 ) ;
V_191 &= ~ ( 0xFF << 16 ) ;
V_191 |= ( 0x1C << 16 ) ;
F_100 ( V_4 , 0x2198 , V_191 , V_593 ) ;
if ( ! V_586 ) {
V_191 = F_101 ( V_4 , 0x20C4 , V_593 ) ;
V_191 |= ( 1 << 27 ) ;
F_100 ( V_4 , 0x20C4 , V_191 , V_593 ) ;
V_191 = F_101 ( V_4 , 0x21C4 , V_593 ) ;
V_191 |= ( 1 << 27 ) ;
F_100 ( V_4 , 0x21C4 , V_191 , V_593 ) ;
V_191 = F_101 ( V_4 , 0x20EC , V_593 ) ;
V_191 &= ~ ( 0xF << 28 ) ;
V_191 |= ( 4 << 28 ) ;
F_100 ( V_4 , 0x20EC , V_191 , V_593 ) ;
V_191 = F_101 ( V_4 , 0x21EC , V_593 ) ;
V_191 &= ~ ( 0xF << 28 ) ;
V_191 |= ( 4 << 28 ) ;
F_100 ( V_4 , 0x21EC , V_191 , V_593 ) ;
}
V_191 = F_101 ( V_4 , V_594 , V_196 ) ;
V_191 |= V_595 ;
F_100 ( V_4 , V_594 , V_191 , V_196 ) ;
}
void F_293 ( struct V_1 * V_2 )
{
if ( F_90 ( V_2 ) || F_61 ( V_2 ) )
F_291 ( V_2 ) ;
else if ( F_59 ( V_2 ) )
F_292 ( V_2 ) ;
}
static int F_294 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_77 * V_78 ;
struct V_77 * V_596 = NULL ;
int V_471 = 0 ;
bool V_549 = false ;
F_30 (dev, crtc, encoder) {
switch ( V_78 -> type ) {
case V_40 :
V_549 = true ;
break;
case V_47 :
V_596 = V_78 ;
break;
}
V_471 ++ ;
}
if ( V_549 && F_261 ( V_4 ) && V_471 < 2 ) {
F_44 ( L_99 ,
V_4 -> V_472 ) ;
return V_4 -> V_472 * 1000 ;
}
return 120000 ;
}
static void F_295 ( struct V_36 * V_37 ,
struct V_426 * V_427 ,
bool V_597 )
{
struct V_3 * V_4 = V_37 -> V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
T_5 V_12 ;
V_12 = F_4 ( F_49 ( V_108 ) ) ;
V_12 &= ~ V_211 ;
switch ( V_110 -> V_242 ) {
case 18 :
V_12 |= V_598 ;
break;
case 24 :
V_12 |= V_599 ;
break;
case 30 :
V_12 |= V_600 ;
break;
case 36 :
V_12 |= V_601 ;
break;
default:
F_127 () ;
}
V_12 &= ~ ( V_561 | V_602 ) ;
if ( V_597 )
V_12 |= ( V_561 | V_563 ) ;
V_12 &= ~ V_213 ;
if ( V_427 -> V_11 & V_532 )
V_12 |= V_214 ;
else
V_12 |= V_566 ;
F_11 ( F_49 ( V_108 ) , V_12 ) ;
F_15 ( F_49 ( V_108 ) ) ;
}
static void F_296 ( struct V_36 * V_37 ,
struct V_426 * V_427 ,
bool V_597 )
{
struct V_3 * V_4 = V_37 -> V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
enum V_107 V_111 = V_110 -> V_111 ;
T_5 V_12 ;
V_12 = F_4 ( F_49 ( V_111 ) ) ;
V_12 &= ~ ( V_561 | V_602 ) ;
if ( V_597 )
V_12 |= ( V_561 | V_563 ) ;
V_12 &= ~ V_221 ;
if ( V_427 -> V_11 & V_532 )
V_12 |= V_214 ;
else
V_12 |= V_566 ;
F_11 ( F_49 ( V_111 ) , V_12 ) ;
F_15 ( F_49 ( V_111 ) ) ;
}
static bool F_297 ( struct V_36 * V_37 ,
struct V_426 * V_427 ,
T_3 * clock ,
bool * V_548 ,
T_3 * V_473 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_77 * V_77 ;
int V_38 ;
const T_2 * V_39 ;
bool V_230 , V_488 = false , V_550 = false , V_549 = false ;
F_30 (dev, crtc, intel_encoder) {
switch ( V_77 -> type ) {
case V_40 :
V_549 = true ;
break;
case V_56 :
case V_53 :
V_488 = true ;
if ( V_77 -> V_552 )
V_550 = true ;
break;
case V_525 :
V_550 = true ;
break;
}
}
V_38 = F_294 ( V_37 ) ;
V_39 = F_23 ( V_37 , V_38 ) ;
V_230 = V_39 -> V_553 ( V_39 , V_37 , V_427 -> clock , V_38 , NULL ,
clock ) ;
if ( ! V_230 )
return false ;
if ( V_549 && V_4 -> V_554 ) {
* V_548 = V_39 -> V_553 ( V_39 , V_37 ,
V_4 -> V_555 ,
V_38 ,
clock ,
V_473 ) ;
}
if ( V_488 && V_550 )
F_266 ( V_427 , clock ) ;
return true ;
}
static void F_298 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_303 ;
V_303 = F_4 ( V_317 ) ;
if ( V_303 & V_318 )
return;
F_2 ( F_4 ( F_67 ( V_149 ) ) & V_136 ) ;
F_2 ( F_4 ( F_67 ( V_316 ) ) & V_136 ) ;
V_303 |= V_318 ;
F_44 ( L_111 ) ;
F_11 ( V_317 , V_303 ) ;
F_15 ( V_317 ) ;
}
static bool F_299 ( struct V_110 * V_110 )
{
struct V_1 * V_2 = V_110 -> V_204 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_314 =
F_39 ( V_4 -> V_109 [ V_149 ] ) ;
F_44 ( L_112 ,
V_110 -> V_108 , V_110 -> V_322 ) ;
if ( V_110 -> V_322 > 4 ) {
F_44 ( L_113 ,
V_110 -> V_108 , V_110 -> V_322 ) ;
V_110 -> V_322 = 4 ;
return false ;
}
if ( V_4 -> V_298 == 2 )
return true ;
switch ( V_110 -> V_108 ) {
case V_142 :
return true ;
case V_149 :
if ( V_4 -> V_109 [ V_316 ] -> V_124 &&
V_110 -> V_322 > 2 ) {
F_44 ( L_114 ,
V_110 -> V_108 , V_110 -> V_322 ) ;
V_110 -> V_322 = 2 ;
return false ;
}
if ( V_110 -> V_322 > 2 )
F_2 ( F_4 ( V_317 ) & V_318 ) ;
else
F_298 ( V_2 ) ;
return true ;
case V_316 :
if ( ! V_314 -> V_204 . V_124 || V_314 -> V_322 <= 2 ) {
if ( V_110 -> V_322 > 2 ) {
F_44 ( L_114 ,
V_110 -> V_108 , V_110 -> V_322 ) ;
V_110 -> V_322 = 2 ;
return false ;
}
} else {
F_44 ( L_115 ) ;
return false ;
}
F_298 ( V_2 ) ;
return true ;
default:
F_127 () ;
}
}
int F_300 ( int V_603 , int V_604 , int V_242 )
{
T_1 V_605 = V_603 * V_242 * 21 / 20 ;
return V_605 / ( V_604 * 8 ) + 1 ;
}
static void F_301 ( struct V_36 * V_37 ,
struct V_426 * V_351 ,
struct V_426 * V_427 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
enum V_107 V_111 = V_110 -> V_111 ;
struct V_77 * V_77 , * V_596 = NULL ;
struct V_450 V_451 = { 0 } ;
int V_603 , V_514 , V_606 , V_604 ;
bool V_551 = false , V_607 = false ;
F_30 (dev, crtc, intel_encoder) {
switch ( V_77 -> type ) {
case V_46 :
V_551 = true ;
break;
case V_47 :
V_551 = true ;
if ( ! F_173 ( & V_77 -> V_204 ) )
V_607 = true ;
V_596 = V_77 ;
break;
}
}
V_514 = F_277 ( V_427 ) ;
V_606 = 0 ;
if ( V_607 ) {
F_302 ( V_596 , & V_606 , & V_604 ) ;
} else {
V_604 = F_5 ( V_2 ) * F_303 ( 100 ) / F_304 ( 1 ) / 10 ;
}
if ( V_596 )
V_603 = F_305 ( V_596 , V_351 ) ;
else if ( V_551 )
V_603 = V_351 -> clock ;
else
V_603 = V_427 -> clock ;
if ( ! V_606 )
V_606 = F_300 ( V_603 , V_604 ,
V_110 -> V_242 ) ;
V_110 -> V_322 = V_606 ;
if ( V_514 > 1 )
V_604 *= V_514 ;
F_260 ( V_110 -> V_242 , V_606 , V_603 , V_604 ,
& V_451 ) ;
F_11 ( F_182 ( V_111 ) , F_306 ( V_451 . V_452 ) | V_451 . V_453 ) ;
F_11 ( F_307 ( V_111 ) , V_451 . V_454 ) ;
F_11 ( F_308 ( V_111 ) , V_451 . V_455 ) ;
F_11 ( F_309 ( V_111 ) , V_451 . V_456 ) ;
}
static T_5 F_310 ( struct V_110 * V_110 ,
struct V_426 * V_427 ,
T_3 * clock , T_1 V_389 )
{
struct V_36 * V_37 = & V_110 -> V_204 ;
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_77 * V_77 ;
T_5 V_388 ;
int V_608 , V_514 , V_471 = 0 ;
bool V_549 = false , V_488 = false , V_550 = false ;
bool V_551 = false , V_607 = false ;
F_30 (dev, crtc, intel_encoder) {
switch ( V_77 -> type ) {
case V_40 :
V_549 = true ;
break;
case V_56 :
case V_53 :
V_488 = true ;
if ( V_77 -> V_552 )
V_550 = true ;
break;
case V_525 :
V_550 = true ;
break;
case V_46 :
V_551 = true ;
break;
case V_47 :
V_551 = true ;
if ( ! F_173 ( & V_77 -> V_204 ) )
V_607 = true ;
break;
}
V_471 ++ ;
}
V_608 = 21 ;
if ( V_549 ) {
if ( ( F_261 ( V_4 ) &&
V_4 -> V_472 == 100 ) ||
( F_4 ( V_41 ) & V_34 ) == V_35 )
V_608 = 25 ;
} else if ( V_488 && V_550 )
V_608 = 20 ;
if ( clock -> V_68 < V_608 * clock -> V_74 )
V_389 |= V_609 ;
V_388 = 0 ;
if ( V_549 )
V_388 |= V_512 ;
else
V_388 |= V_513 ;
if ( V_488 ) {
V_514 = F_277 ( V_427 ) ;
if ( V_514 > 1 ) {
V_388 |= ( V_514 - 1 ) << V_610 ;
}
V_388 |= V_516 ;
}
if ( V_551 && ! V_607 )
V_388 |= V_516 ;
V_388 |= ( 1 << ( clock -> V_71 - 1 ) ) << V_518 ;
V_388 |= ( 1 << ( clock -> V_71 - 1 ) ) << V_519 ;
switch ( clock -> V_72 ) {
case 5 :
V_388 |= V_520 ;
break;
case 7 :
V_388 |= V_521 ;
break;
case 10 :
V_388 |= V_522 ;
break;
case 14 :
V_388 |= V_523 ;
break;
}
if ( V_488 && V_550 )
V_388 |= V_526 ;
else if ( V_550 )
V_388 |= 3 ;
else if ( V_549 && F_261 ( V_4 ) && V_471 < 2 )
V_388 |= V_527 ;
else
V_388 |= V_528 ;
return V_388 ;
}
static int F_311 ( struct V_36 * V_37 ,
struct V_426 * V_351 ,
struct V_426 * V_427 ,
int V_240 , int V_241 ,
struct V_246 * V_247 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
int V_153 = V_110 -> V_153 ;
int V_471 = 0 ;
T_3 clock , V_473 ;
T_1 V_388 , V_389 = 0 , V_474 = 0 ;
bool V_547 , V_548 = false ;
bool V_549 = false , V_551 = false , V_607 = false ;
struct V_77 * V_78 ;
T_1 V_303 ;
int V_230 ;
bool V_597 , V_611 ;
F_30 (dev, crtc, encoder) {
switch ( V_78 -> type ) {
case V_40 :
V_549 = true ;
break;
case V_46 :
V_551 = true ;
break;
case V_47 :
V_551 = true ;
if ( ! F_173 ( & V_78 -> V_204 ) )
V_607 = true ;
break;
}
V_471 ++ ;
}
F_50 ( ! ( F_90 ( V_2 ) || F_61 ( V_2 ) ) ,
L_116 , F_312 ( V_2 ) ) ;
V_547 = F_297 ( V_37 , V_427 , & clock ,
& V_548 , & V_473 ) ;
if ( ! V_547 ) {
F_10 ( L_101 ) ;
return - V_235 ;
}
F_209 ( V_37 , true ) ;
V_597 = F_262 ( V_37 , V_247 , & V_110 -> V_242 ,
V_427 ) ;
if ( V_549 && V_4 -> V_480 )
V_597 = true ;
V_389 = clock . V_74 << 16 | clock . V_76 << 8 | clock . V_69 ;
if ( V_548 )
V_474 = V_473 . V_74 << 16 | V_473 . V_76 << 8 |
V_473 . V_69 ;
V_388 = F_310 ( V_110 , V_427 , & clock , V_389 ) ;
F_44 ( L_117 , V_108 ) ;
F_287 ( V_351 ) ;
if ( ! V_607 ) {
struct V_128 * V_129 ;
V_129 = F_200 ( V_110 , V_388 , V_389 ) ;
if ( V_129 == NULL ) {
F_60 ( L_118 ,
V_108 ) ;
return - V_235 ;
}
} else
F_199 ( V_110 ) ;
if ( V_549 ) {
V_303 = F_4 ( V_41 ) ;
V_303 |= V_173 | V_477 ;
if ( F_61 ( V_2 ) ) {
V_303 &= ~ V_171 ;
V_303 |= F_83 ( V_108 ) ;
} else {
if ( V_108 == 1 )
V_303 |= V_148 ;
else
V_303 &= ~ V_148 ;
}
V_303 |= V_4 -> V_478 ;
if ( clock . V_72 == 7 )
V_303 |= V_479 | V_35 ;
else
V_303 &= ~ ( V_479 | V_35 ) ;
V_303 &= ~ ( V_482 | V_483 ) ;
if ( V_427 -> V_11 & V_484 )
V_303 |= V_482 ;
if ( V_427 -> V_11 & V_485 )
V_303 |= V_483 ;
F_11 ( V_41 , V_303 ) ;
}
if ( V_551 && ! V_607 ) {
F_276 ( V_37 , V_351 , V_427 ) ;
} else {
F_11 ( F_313 ( V_108 ) , 0 ) ;
F_11 ( F_314 ( V_108 ) , 0 ) ;
F_11 ( F_315 ( V_108 ) , 0 ) ;
F_11 ( F_316 ( V_108 ) , 0 ) ;
}
if ( V_110 -> V_205 ) {
F_11 ( V_110 -> V_205 -> V_130 , V_388 ) ;
F_15 ( V_110 -> V_205 -> V_130 ) ;
F_97 ( 150 ) ;
F_11 ( V_110 -> V_205 -> V_130 , V_388 ) ;
}
V_110 -> V_475 = false ;
if ( V_110 -> V_205 ) {
if ( V_549 && V_548 && V_476 ) {
F_11 ( V_110 -> V_205 -> V_612 , V_474 ) ;
V_110 -> V_475 = true ;
} else {
F_11 ( V_110 -> V_205 -> V_612 , V_389 ) ;
}
}
F_284 ( V_110 , V_351 , V_427 ) ;
F_301 ( V_37 , V_351 , V_427 ) ;
V_611 = F_299 ( V_110 ) ;
if ( V_607 )
F_154 ( V_37 , V_427 -> clock ) ;
F_295 ( V_37 , V_427 , V_597 ) ;
F_45 ( V_2 , V_108 ) ;
F_11 ( F_74 ( V_153 ) , V_556 ) ;
F_15 ( F_74 ( V_153 ) ) ;
V_230 = F_150 ( V_37 , V_240 , V_241 , V_247 ) ;
F_203 ( V_2 ) ;
F_317 ( V_2 , V_108 , V_427 ) ;
return V_611 ? V_230 : - V_235 ;
}
static int F_318 ( struct V_36 * V_37 ,
struct V_426 * V_351 ,
struct V_426 * V_427 ,
int V_240 , int V_241 ,
struct V_246 * V_247 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
int V_153 = V_110 -> V_153 ;
int V_471 = 0 ;
T_3 clock , V_473 ;
T_1 V_388 = 0 , V_389 = 0 , V_474 = 0 ;
bool V_547 , V_548 = false ;
bool V_549 = false , V_551 = false , V_607 = false ;
struct V_77 * V_78 ;
T_1 V_303 ;
int V_230 ;
bool V_597 ;
F_30 (dev, crtc, encoder) {
switch ( V_78 -> type ) {
case V_40 :
V_549 = true ;
break;
case V_46 :
V_551 = true ;
break;
case V_47 :
V_551 = true ;
if ( ! F_173 ( & V_78 -> V_204 ) )
V_607 = true ;
break;
}
V_471 ++ ;
}
if ( V_607 )
V_110 -> V_111 = V_545 ;
else
V_110 -> V_111 = V_108 ;
F_50 ( ! F_59 ( V_2 ) , L_116 ,
F_312 ( V_2 ) ) ;
F_50 ( V_471 != 1 , L_119 ,
V_471 , F_71 ( V_108 ) ) ;
F_2 ( F_4 ( F_49 ( V_110 -> V_111 ) ) &
( V_152 | V_117 ) ) ;
F_2 ( F_4 ( F_74 ( V_153 ) ) & V_154 ) ;
if ( ! F_319 ( V_37 , V_427 -> clock ) )
return - V_235 ;
if ( F_90 ( V_2 ) || F_61 ( V_2 ) ) {
V_547 = F_297 ( V_37 , V_427 , & clock ,
& V_548 ,
& V_473 ) ;
if ( ! V_547 ) {
F_10 ( L_101 ) ;
return - V_235 ;
}
}
F_209 ( V_37 , true ) ;
V_597 = F_262 ( V_37 , V_247 , & V_110 -> V_242 ,
V_427 ) ;
if ( V_549 && V_4 -> V_480 )
V_597 = true ;
F_44 ( L_117 , V_108 ) ;
F_287 ( V_351 ) ;
if ( F_90 ( V_2 ) || F_61 ( V_2 ) ) {
V_389 = clock . V_74 << 16 | clock . V_76 << 8 | clock . V_69 ;
if ( V_548 )
V_474 = V_473 . V_74 << 16 | V_473 . V_76 << 8 |
V_473 . V_69 ;
V_388 = F_310 ( V_110 , V_427 , & clock ,
V_389 ) ;
if ( ! V_607 ) {
struct V_128 * V_129 ;
V_129 = F_200 ( V_110 , V_388 , V_389 ) ;
if ( V_129 == NULL ) {
F_60 ( L_118 ,
V_108 ) ;
return - V_235 ;
}
} else
F_199 ( V_110 ) ;
if ( V_549 ) {
V_303 = F_4 ( V_41 ) ;
V_303 |= V_173 | V_477 ;
if ( F_61 ( V_2 ) ) {
V_303 &= ~ V_171 ;
V_303 |= F_83 ( V_108 ) ;
} else {
if ( V_108 == 1 )
V_303 |= V_148 ;
else
V_303 &= ~ V_148 ;
}
V_303 |= V_4 -> V_478 ;
if ( clock . V_72 == 7 )
V_303 |= V_479 | V_35 ;
else
V_303 &= ~ ( V_479 |
V_35 ) ;
V_303 &= ~ ( V_482 | V_483 ) ;
if ( V_427 -> V_11 & V_484 )
V_303 |= V_482 ;
if ( V_427 -> V_11 & V_485 )
V_303 |= V_483 ;
F_11 ( V_41 , V_303 ) ;
}
}
if ( V_551 && ! V_607 ) {
F_276 ( V_37 , V_351 , V_427 ) ;
} else {
if ( F_90 ( V_2 ) || F_61 ( V_2 ) ) {
F_11 ( F_313 ( V_108 ) , 0 ) ;
F_11 ( F_314 ( V_108 ) , 0 ) ;
F_11 ( F_315 ( V_108 ) , 0 ) ;
F_11 ( F_316 ( V_108 ) , 0 ) ;
}
}
V_110 -> V_475 = false ;
if ( F_90 ( V_2 ) || F_61 ( V_2 ) ) {
if ( V_110 -> V_205 ) {
F_11 ( V_110 -> V_205 -> V_130 , V_388 ) ;
F_15 ( V_110 -> V_205 -> V_130 ) ;
F_97 ( 150 ) ;
F_11 ( V_110 -> V_205 -> V_130 , V_388 ) ;
}
if ( V_110 -> V_205 ) {
if ( V_549 && V_548 && V_476 ) {
F_11 ( V_110 -> V_205 -> V_612 , V_474 ) ;
V_110 -> V_475 = true ;
} else {
F_11 ( V_110 -> V_205 -> V_612 , V_389 ) ;
}
}
}
F_284 ( V_110 , V_351 , V_427 ) ;
if ( ! V_551 || V_607 )
F_301 ( V_37 , V_351 , V_427 ) ;
if ( F_90 ( V_2 ) || F_61 ( V_2 ) )
if ( V_607 )
F_154 ( V_37 , V_427 -> clock ) ;
F_296 ( V_37 , V_427 , V_597 ) ;
F_11 ( F_74 ( V_153 ) , V_556 ) ;
F_15 ( F_74 ( V_153 ) ) ;
V_230 = F_150 ( V_37 , V_240 , V_241 , V_247 ) ;
F_203 ( V_2 ) ;
F_317 ( V_2 , V_108 , V_427 ) ;
return V_230 ;
}
static int F_320 ( struct V_36 * V_37 ,
struct V_426 * V_351 ,
struct V_426 * V_427 ,
int V_240 , int V_241 ,
struct V_246 * V_247 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_613 * V_614 ;
struct V_77 * V_78 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
int V_230 ;
F_321 ( V_2 , V_108 ) ;
V_230 = V_4 -> V_280 . V_615 ( V_37 , V_351 , V_427 ,
V_240 , V_241 , V_247 ) ;
F_322 ( V_2 , V_108 ) ;
if ( V_230 != 0 )
return V_230 ;
F_30 (dev, crtc, encoder) {
F_44 ( L_120 ,
V_78 -> V_204 . V_204 . V_26 ,
F_323 ( & V_78 -> V_204 ) ,
V_351 -> V_204 . V_26 , V_351 -> V_616 ) ;
V_614 = V_78 -> V_204 . V_617 ;
V_614 -> V_618 ( & V_78 -> V_204 , V_351 , V_427 ) ;
}
return 0 ;
}
static bool F_324 ( struct V_416 * V_417 ,
int V_619 , T_5 V_620 ,
int V_621 , T_5 V_622 ,
int V_623 )
{
struct V_3 * V_4 = V_417 -> V_2 -> V_5 ;
T_6 * V_624 = V_417 -> V_624 ;
T_5 V_155 ;
V_155 = F_4 ( V_619 ) ;
V_155 &= V_620 ;
if ( ! V_624 [ 0 ] )
return ! V_155 ;
if ( ! V_155 )
return false ;
V_155 = F_4 ( V_621 ) ;
V_155 &= ~ V_622 ;
F_11 ( V_621 , V_155 ) ;
for ( V_155 = 0 ; V_155 < V_624 [ 2 ] ; V_155 ++ )
if ( F_4 ( V_623 ) != * ( ( T_5 * ) V_624 + V_155 ) )
return false ;
return true ;
}
static void F_325 ( struct V_416 * V_417 ,
struct V_36 * V_37 )
{
struct V_3 * V_4 = V_417 -> V_2 -> V_5 ;
T_6 * V_624 = V_417 -> V_624 ;
T_5 V_625 ;
T_5 V_626 ;
T_5 V_155 ;
V_155 = F_4 ( V_627 ) ;
if ( V_155 == V_628 || V_155 == V_629 )
V_625 = V_630 ;
else
V_625 = V_631 ;
if ( F_324 ( V_417 ,
V_632 , V_625 ,
V_632 , V_633 ,
V_634 ) )
return;
V_155 = F_4 ( V_632 ) ;
V_155 &= ~ ( V_625 | V_633 ) ;
V_626 = ( V_155 >> 9 ) & 0x1f ;
F_11 ( V_632 , V_155 ) ;
if ( ! V_624 [ 0 ] )
return;
V_626 = F_326 ( T_6 , V_624 [ 2 ] , V_626 ) ;
F_60 ( L_121 , V_626 ) ;
for ( V_155 = 0 ; V_155 < V_626 ; V_155 ++ )
F_11 ( V_634 , * ( ( T_5 * ) V_624 + V_155 ) ) ;
V_155 = F_4 ( V_632 ) ;
V_155 |= V_625 ;
F_11 ( V_632 , V_155 ) ;
}
static void F_327 ( struct V_416 * V_417 ,
struct V_36 * V_37 )
{
struct V_3 * V_4 = V_417 -> V_2 -> V_5 ;
T_6 * V_624 = V_417 -> V_624 ;
struct V_1 * V_2 = V_37 -> V_2 ;
T_5 V_625 ;
T_5 V_155 ;
int V_626 ;
int V_108 = F_39 ( V_37 ) -> V_108 ;
int V_191 ;
int V_635 = F_328 ( V_108 ) ;
int V_636 = F_329 ( V_108 ) ;
int V_637 = F_330 ( V_108 ) ;
int V_638 = V_639 ;
F_60 ( L_122 ) ;
F_60 ( L_123 ) ;
V_191 = F_4 ( V_638 ) ;
V_191 |= ( V_640 << ( V_108 * 4 ) ) ;
F_11 ( V_638 , V_191 ) ;
F_45 ( V_2 , V_108 ) ;
V_191 = F_4 ( V_638 ) ;
F_60 ( L_124 , V_191 ) ;
V_191 |= ( V_641 << ( V_108 * 4 ) ) ;
F_11 ( V_638 , V_191 ) ;
V_191 = F_4 ( V_638 ) ;
F_60 ( L_125 , V_191 ) ;
V_191 = F_4 ( V_637 ) ;
F_60 ( L_126 , V_191 ) ;
V_191 &= ~ ( V_642 | V_643 ) ;
F_11 ( V_637 , V_191 ) ;
F_60 ( L_127 , F_71 ( V_108 ) ) ;
V_625 = V_641 << ( V_108 * 4 ) ;
if ( F_21 ( V_37 , V_46 ) ) {
F_60 ( L_128 ) ;
V_624 [ 5 ] |= ( 1 << 2 ) ;
F_11 ( V_637 , V_642 ) ;
} else
F_11 ( V_637 , 0 ) ;
if ( F_324 ( V_417 ,
V_638 , V_625 ,
V_636 , V_644 ,
V_635 ) )
return;
V_155 = F_4 ( V_638 ) ;
V_155 &= ~ V_625 ;
F_11 ( V_638 , V_155 ) ;
if ( ! V_624 [ 0 ] )
return;
V_155 = F_4 ( V_636 ) ;
V_155 &= ~ V_644 ;
F_11 ( V_636 , V_155 ) ;
V_155 = ( V_155 >> 29 ) & V_645 ;
F_60 ( L_129 , V_155 ) ;
V_626 = F_326 ( T_6 , V_624 [ 2 ] , 21 ) ;
F_60 ( L_121 , V_626 ) ;
for ( V_155 = 0 ; V_155 < V_626 ; V_155 ++ )
F_11 ( V_635 , * ( ( T_5 * ) V_624 + V_155 ) ) ;
V_155 = F_4 ( V_638 ) ;
V_155 |= V_625 ;
F_11 ( V_638 , V_155 ) ;
}
static void F_331 ( struct V_416 * V_417 ,
struct V_36 * V_37 )
{
struct V_3 * V_4 = V_417 -> V_2 -> V_5 ;
T_6 * V_624 = V_417 -> V_624 ;
T_5 V_625 ;
T_5 V_155 ;
int V_626 ;
int V_635 ;
int V_637 ;
int V_636 ;
int V_638 ;
int V_108 = F_39 ( V_37 ) -> V_108 ;
if ( F_90 ( V_417 -> V_2 ) ) {
V_635 = F_332 ( V_108 ) ;
V_637 = F_333 ( V_108 ) ;
V_636 = F_334 ( V_108 ) ;
V_638 = V_646 ;
} else {
V_635 = F_335 ( V_108 ) ;
V_637 = F_336 ( V_108 ) ;
V_636 = F_337 ( V_108 ) ;
V_638 = V_647 ;
}
F_60 ( L_127 , F_71 ( V_108 ) ) ;
V_155 = F_4 ( V_636 ) ;
V_155 = ( V_155 >> 29 ) & V_645 ;
if ( ! V_155 ) {
F_60 ( L_130 ) ;
V_625 = V_648 ;
V_625 |= V_648 << 4 ;
V_625 |= V_648 << 8 ;
} else {
F_60 ( L_131 , 'A' + V_155 ) ;
V_625 = V_648 << ( ( V_155 - 1 ) * 4 ) ;
}
if ( F_21 ( V_37 , V_46 ) ) {
F_60 ( L_128 ) ;
V_624 [ 5 ] |= ( 1 << 2 ) ;
F_11 ( V_637 , V_642 ) ;
} else
F_11 ( V_637 , 0 ) ;
if ( F_324 ( V_417 ,
V_638 , V_625 ,
V_636 , V_644 ,
V_635 ) )
return;
V_155 = F_4 ( V_638 ) ;
V_155 &= ~ V_625 ;
F_11 ( V_638 , V_155 ) ;
if ( ! V_624 [ 0 ] )
return;
V_155 = F_4 ( V_636 ) ;
V_155 &= ~ V_644 ;
F_11 ( V_636 , V_155 ) ;
V_626 = F_326 ( T_6 , V_624 [ 2 ] , 21 ) ;
F_60 ( L_121 , V_626 ) ;
for ( V_155 = 0 ; V_155 < V_626 ; V_155 ++ )
F_11 ( V_635 , * ( ( T_5 * ) V_624 + V_155 ) ) ;
V_155 = F_4 ( V_638 ) ;
V_155 |= V_625 ;
F_11 ( V_638 , V_155 ) ;
}
void F_338 ( struct V_421 * V_78 ,
struct V_426 * V_351 )
{
struct V_36 * V_37 = V_78 -> V_37 ;
struct V_416 * V_417 ;
struct V_1 * V_2 = V_78 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_417 = F_339 ( V_78 , V_351 ) ;
if ( ! V_417 )
return;
F_60 ( L_132 ,
V_417 -> V_204 . V_26 ,
F_243 ( V_417 ) ,
V_417 -> V_78 -> V_204 . V_26 ,
F_323 ( V_417 -> V_78 ) ) ;
V_417 -> V_624 [ 6 ] = F_340 ( V_417 , V_351 ) / 2 ;
if ( V_4 -> V_280 . V_649 )
V_4 -> V_280 . V_649 ( V_417 , V_37 ) ;
}
void F_208 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_650 = F_341 ( V_110 -> V_108 ) ;
int V_155 ;
if ( ! V_37 -> V_124 || ! V_110 -> V_207 )
return;
if ( F_3 ( V_2 ) )
V_650 = F_342 ( V_110 -> V_108 ) ;
for ( V_155 = 0 ; V_155 < 256 ; V_155 ++ ) {
F_11 ( V_650 + 4 * V_155 ,
( V_110 -> V_651 [ V_155 ] << 16 ) |
( V_110 -> V_652 [ V_155 ] << 8 ) |
V_110 -> V_653 [ V_155 ] ) ;
}
}
static void F_343 ( struct V_36 * V_37 , T_1 V_204 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
bool V_654 = V_204 != 0 ;
T_1 V_655 ;
if ( V_110 -> V_656 == V_654 )
return;
V_655 = F_4 ( V_657 ) ;
if ( V_654 ) {
F_11 ( V_658 , V_204 ) ;
V_655 &= ~ ( V_659 ) ;
V_655 |= V_660 |
V_661 |
V_662 ;
} else
V_655 &= ~ ( V_660 | V_661 ) ;
F_11 ( V_657 , V_655 ) ;
V_110 -> V_656 = V_654 ;
}
static void F_344 ( struct V_36 * V_37 , T_1 V_204 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
bool V_654 = V_204 != 0 ;
if ( V_110 -> V_656 != V_654 ) {
T_5 V_655 = F_4 ( F_345 ( V_108 ) ) ;
if ( V_204 ) {
V_655 &= ~ ( V_663 | V_664 ) ;
V_655 |= V_665 | V_666 ;
V_655 |= V_108 << 28 ;
} else {
V_655 &= ~ ( V_663 | V_666 ) ;
V_655 |= V_667 ;
}
F_11 ( F_345 ( V_108 ) , V_655 ) ;
V_110 -> V_656 = V_654 ;
}
F_11 ( F_346 ( V_108 ) , V_204 ) ;
}
static void F_347 ( struct V_36 * V_37 , T_1 V_204 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
bool V_654 = V_204 != 0 ;
if ( V_110 -> V_656 != V_654 ) {
T_5 V_655 = F_4 ( F_348 ( V_108 ) ) ;
if ( V_204 ) {
V_655 &= ~ V_663 ;
V_655 |= V_665 | V_666 ;
} else {
V_655 &= ~ ( V_663 | V_666 ) ;
V_655 |= V_667 ;
}
F_11 ( F_348 ( V_108 ) , V_655 ) ;
V_110 -> V_656 = V_654 ;
}
F_11 ( F_349 ( V_108 ) , V_204 ) ;
}
static void F_209 ( struct V_36 * V_37 ,
bool V_208 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
int V_240 = V_110 -> V_668 ;
int V_241 = V_110 -> V_669 ;
T_1 V_204 , V_670 ;
bool V_654 ;
V_670 = 0 ;
if ( V_208 && V_37 -> V_124 && V_37 -> V_247 ) {
V_204 = V_110 -> V_671 ;
if ( V_240 > ( int ) V_37 -> V_247 -> V_672 )
V_204 = 0 ;
if ( V_241 > ( int ) V_37 -> V_247 -> V_673 )
V_204 = 0 ;
} else
V_204 = 0 ;
if ( V_240 < 0 ) {
if ( V_240 + V_110 -> V_674 < 0 )
V_204 = 0 ;
V_670 |= V_675 << V_676 ;
V_240 = - V_240 ;
}
V_670 |= V_240 << V_676 ;
if ( V_241 < 0 ) {
if ( V_241 + V_110 -> V_677 < 0 )
V_204 = 0 ;
V_670 |= V_675 << V_678 ;
V_241 = - V_241 ;
}
V_670 |= V_241 << V_678 ;
V_654 = V_204 != 0 ;
if ( ! V_654 && ! V_110 -> V_656 )
return;
if ( F_156 ( V_2 ) || F_63 ( V_2 ) ) {
F_11 ( F_350 ( V_108 ) , V_670 ) ;
F_347 ( V_37 , V_204 ) ;
} else {
F_11 ( F_351 ( V_108 ) , V_670 ) ;
if ( F_352 ( V_2 ) || F_353 ( V_2 ) )
F_343 ( V_37 , V_204 ) ;
else
F_344 ( V_37 , V_204 ) ;
}
}
static int F_354 ( struct V_36 * V_37 ,
struct V_679 * V_680 ,
T_5 V_681 ,
T_5 V_672 , T_5 V_673 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
struct V_225 * V_226 ;
T_5 V_682 ;
int V_230 ;
if ( ! V_681 ) {
F_44 ( L_133 ) ;
V_682 = 0 ;
V_226 = NULL ;
F_151 ( & V_2 -> V_299 ) ;
goto V_683;
}
if ( V_672 != 64 || V_673 != 64 ) {
F_10 ( L_134 ) ;
return - V_235 ;
}
V_226 = F_355 ( F_356 ( V_2 , V_680 , V_681 ) ) ;
if ( & V_226 -> V_204 == NULL )
return - V_684 ;
if ( V_226 -> V_204 . V_685 < V_672 * V_673 * 4 ) {
F_10 ( L_135 ) ;
V_230 = - V_686 ;
goto V_687;
}
F_151 ( & V_2 -> V_299 ) ;
if ( ! V_4 -> V_137 -> V_688 ) {
if ( V_226 -> V_231 ) {
F_10 ( L_136 ) ;
V_230 = - V_235 ;
goto V_689;
}
V_230 = F_128 ( V_226 , 0 , NULL ) ;
if ( V_230 ) {
F_10 ( L_137 ) ;
goto V_689;
}
V_230 = F_357 ( V_226 ) ;
if ( V_230 ) {
F_10 ( L_138 ) ;
goto V_690;
}
V_682 = V_226 -> V_277 ;
} else {
int V_691 = F_96 ( V_2 ) ? 16 * 1024 : 256 ;
V_230 = F_358 ( V_2 , V_226 ,
( V_110 -> V_108 == 0 ) ? V_692 : V_693 ,
V_691 ) ;
if ( V_230 ) {
F_10 ( L_139 ) ;
goto V_689;
}
V_682 = V_226 -> V_694 -> V_681 -> V_695 ;
}
if ( F_27 ( V_2 ) )
F_11 ( V_696 , ( V_673 << 12 ) | V_672 ) ;
V_683:
if ( V_110 -> V_697 ) {
if ( V_4 -> V_137 -> V_688 ) {
if ( V_110 -> V_697 != V_226 )
F_359 ( V_2 , V_110 -> V_697 ) ;
} else
F_131 ( V_110 -> V_697 ) ;
F_360 ( & V_110 -> V_697 -> V_204 ) ;
}
F_152 ( & V_2 -> V_299 ) ;
V_110 -> V_671 = V_682 ;
V_110 -> V_697 = V_226 ;
V_110 -> V_674 = V_672 ;
V_110 -> V_677 = V_673 ;
F_209 ( V_37 , true ) ;
return 0 ;
V_690:
F_131 ( V_226 ) ;
V_689:
F_152 ( & V_2 -> V_299 ) ;
V_687:
F_361 ( & V_226 -> V_204 ) ;
return V_230 ;
}
static int F_362 ( struct V_36 * V_37 , int V_240 , int V_241 )
{
struct V_110 * V_110 = F_39 ( V_37 ) ;
V_110 -> V_668 = V_240 ;
V_110 -> V_669 = V_241 ;
F_209 ( V_37 , true ) ;
return 0 ;
}
void F_363 ( struct V_36 * V_37 , T_4 V_698 , T_4 V_699 ,
T_4 V_700 , int V_701 )
{
struct V_110 * V_110 = F_39 ( V_37 ) ;
V_110 -> V_651 [ V_701 ] = V_698 >> 8 ;
V_110 -> V_652 [ V_701 ] = V_699 >> 8 ;
V_110 -> V_653 [ V_701 ] = V_700 >> 8 ;
}
void F_364 ( struct V_36 * V_37 , T_4 * V_698 , T_4 * V_699 ,
T_4 * V_700 , int V_701 )
{
struct V_110 * V_110 = F_39 ( V_37 ) ;
* V_698 = V_110 -> V_651 [ V_701 ] << 8 ;
* V_699 = V_110 -> V_652 [ V_701 ] << 8 ;
* V_700 = V_110 -> V_653 [ V_701 ] << 8 ;
}
static void F_365 ( struct V_36 * V_37 , T_4 * V_698 , T_4 * V_699 ,
T_4 * V_700 , T_5 V_702 , T_5 V_685 )
{
int V_703 = ( V_702 + V_685 > 256 ) ? 256 : V_702 + V_685 , V_155 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
for ( V_155 = V_702 ; V_155 < V_703 ; V_155 ++ ) {
V_110 -> V_651 [ V_155 ] = V_698 [ V_155 ] >> 8 ;
V_110 -> V_652 [ V_155 ] = V_699 [ V_155 ] >> 8 ;
V_110 -> V_653 [ V_155 ] = V_700 [ V_155 ] >> 8 ;
}
F_208 ( V_37 ) ;
}
static struct V_246 *
F_366 ( struct V_1 * V_2 ,
struct V_704 * V_705 ,
struct V_225 * V_226 )
{
struct V_248 * V_249 ;
int V_230 ;
V_249 = F_367 ( sizeof( * V_249 ) , V_706 ) ;
if ( ! V_249 ) {
F_361 ( & V_226 -> V_204 ) ;
return F_368 ( - V_686 ) ;
}
V_230 = F_369 ( V_2 , V_249 , V_705 , V_226 ) ;
if ( V_230 ) {
F_361 ( & V_226 -> V_204 ) ;
F_240 ( V_249 ) ;
return F_368 ( V_230 ) ;
}
return & V_249 -> V_204 ;
}
static T_1
F_370 ( int V_672 , int V_242 )
{
T_1 V_243 = F_371 ( V_672 * V_242 , 8 ) ;
return F_372 ( V_243 , 64 ) ;
}
static T_1
F_373 ( struct V_426 * V_351 , int V_242 )
{
T_1 V_243 = F_370 ( V_351 -> V_408 , V_242 ) ;
return F_372 ( V_243 * V_351 -> V_410 , V_707 ) ;
}
static struct V_246 *
F_374 ( struct V_1 * V_2 ,
struct V_426 * V_351 ,
int V_470 , int V_242 )
{
struct V_225 * V_226 ;
struct V_704 V_705 = { 0 } ;
V_226 = F_375 ( V_2 ,
F_373 ( V_351 , V_242 ) ) ;
if ( V_226 == NULL )
return F_368 ( - V_686 ) ;
V_705 . V_672 = V_351 -> V_408 ;
V_705 . V_673 = V_351 -> V_410 ;
V_705 . V_274 [ 0 ] = F_370 ( V_705 . V_672 ,
V_242 ) ;
V_705 . V_253 = F_376 ( V_242 , V_470 ) ;
return F_366 ( V_2 , & V_705 , V_226 ) ;
}
static struct V_246 *
F_377 ( struct V_1 * V_2 ,
struct V_426 * V_351 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_225 * V_226 ;
struct V_246 * V_247 ;
if ( V_4 -> V_708 == NULL )
return NULL ;
V_226 = V_4 -> V_708 -> V_709 . V_226 ;
if ( V_226 == NULL )
return NULL ;
V_247 = & V_4 -> V_708 -> V_709 . V_204 ;
if ( V_247 -> V_274 [ 0 ] < F_370 ( V_351 -> V_408 ,
V_247 -> V_275 ) )
return NULL ;
if ( V_226 -> V_204 . V_685 < V_351 -> V_410 * V_247 -> V_274 [ 0 ] )
return NULL ;
return V_247 ;
}
bool F_378 ( struct V_416 * V_417 ,
struct V_426 * V_351 ,
struct V_710 * V_711 )
{
struct V_110 * V_110 ;
struct V_77 * V_77 =
F_245 ( V_417 ) ;
struct V_36 * V_712 ;
struct V_421 * V_78 = & V_77 -> V_204 ;
struct V_36 * V_37 = NULL ;
struct V_1 * V_2 = V_78 -> V_2 ;
struct V_246 * V_247 ;
int V_155 = - 1 ;
F_44 ( L_140 ,
V_417 -> V_204 . V_26 , F_243 ( V_417 ) ,
V_78 -> V_204 . V_26 , F_323 ( V_78 ) ) ;
if ( V_78 -> V_37 ) {
V_37 = V_78 -> V_37 ;
V_711 -> V_713 = V_417 -> V_419 ;
V_711 -> V_714 = false ;
if ( V_417 -> V_419 != V_422 )
V_417 -> V_715 -> V_419 ( V_417 , V_422 ) ;
return true ;
}
F_234 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_155 ++ ;
if ( ! ( V_78 -> V_716 & ( 1 << V_155 ) ) )
continue;
if ( ! V_712 -> V_124 ) {
V_37 = V_712 ;
break;
}
}
if ( ! V_37 ) {
F_44 ( L_141 ) ;
return false ;
}
V_77 -> V_717 = F_39 ( V_37 ) ;
F_379 ( V_417 ) -> V_718 = V_77 ;
V_110 = F_39 ( V_37 ) ;
V_711 -> V_713 = V_417 -> V_419 ;
V_711 -> V_714 = true ;
V_711 -> V_719 = NULL ;
if ( ! V_351 )
V_351 = & V_720 ;
V_247 = F_377 ( V_2 , V_351 ) ;
if ( V_247 == NULL ) {
F_44 ( L_142 ) ;
V_247 = F_374 ( V_2 , V_351 , 24 , 32 ) ;
V_711 -> V_719 = V_247 ;
} else
F_44 ( L_143 ) ;
if ( F_380 ( V_247 ) ) {
F_44 ( L_144 ) ;
return false ;
}
if ( ! F_381 ( V_37 , V_351 , 0 , 0 , V_247 ) ) {
F_44 ( L_145 ) ;
if ( V_711 -> V_719 )
V_711 -> V_719 -> V_715 -> V_721 ( V_711 -> V_719 ) ;
return false ;
}
F_45 ( V_2 , V_110 -> V_108 ) ;
return true ;
}
void F_382 ( struct V_416 * V_417 ,
struct V_710 * V_711 )
{
struct V_77 * V_77 =
F_245 ( V_417 ) ;
struct V_421 * V_78 = & V_77 -> V_204 ;
F_44 ( L_140 ,
V_417 -> V_204 . V_26 , F_243 ( V_417 ) ,
V_78 -> V_204 . V_26 , F_323 ( V_78 ) ) ;
if ( V_711 -> V_714 ) {
struct V_36 * V_37 = V_78 -> V_37 ;
F_379 ( V_417 ) -> V_718 = NULL ;
V_77 -> V_717 = NULL ;
F_381 ( V_37 , NULL , 0 , 0 , NULL ) ;
if ( V_711 -> V_719 )
V_711 -> V_719 -> V_715 -> V_721 ( V_711 -> V_719 ) ;
return;
}
if ( V_711 -> V_713 != V_422 )
V_417 -> V_715 -> V_419 ( V_417 , V_711 -> V_713 ) ;
}
static int F_383 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
T_1 V_388 = F_4 ( F_57 ( V_108 ) ) ;
T_1 V_389 ;
T_3 clock ;
if ( ( V_388 & V_722 ) == 0 )
V_389 = F_4 ( F_268 ( V_108 ) ) ;
else
V_389 = F_4 ( F_269 ( V_108 ) ) ;
clock . V_76 = ( V_389 & V_723 ) >> V_724 ;
if ( F_25 ( V_2 ) ) {
clock . V_74 = F_384 ( ( V_389 & V_725 ) >> V_726 ) - 1 ;
clock . V_69 = ( V_389 & V_727 ) >> V_728 ;
} else {
clock . V_74 = ( V_389 & V_729 ) >> V_726 ;
clock . V_69 = ( V_389 & V_730 ) >> V_728 ;
}
if ( ! F_27 ( V_2 ) ) {
if ( F_25 ( V_2 ) )
clock . V_71 = F_384 ( ( V_388 & V_731 ) >>
V_517 ) ;
else
clock . V_71 = F_384 ( ( V_388 & V_732 ) >>
V_518 ) ;
switch ( V_388 & V_733 ) {
case V_513 :
clock . V_72 = V_388 & V_520 ?
5 : 10 ;
break;
case V_512 :
clock . V_72 = V_388 & V_521 ?
7 : 14 ;
break;
default:
F_44 ( L_146
L_147 , ( int ) ( V_388 & V_733 ) ) ;
return 0 ;
}
F_29 ( V_2 , 96000 , & clock ) ;
} else {
bool V_549 = ( V_108 == 1 ) && ( F_4 ( V_50 ) & V_173 ) ;
if ( V_549 ) {
clock . V_71 = F_384 ( ( V_388 & V_734 ) >>
V_518 ) ;
clock . V_72 = 14 ;
if ( ( V_388 & V_735 ) ==
V_527 ) {
F_29 ( V_2 , 66000 , & clock ) ;
} else
F_29 ( V_2 , 48000 , & clock ) ;
} else {
if ( V_388 & V_529 )
clock . V_71 = 2 ;
else {
clock . V_71 = ( ( V_388 & V_736 ) >>
V_518 ) + 2 ;
}
if ( V_388 & V_530 )
clock . V_72 = 4 ;
else
clock . V_72 = 2 ;
F_29 ( V_2 , 48000 , & clock ) ;
}
}
return clock . V_75 ;
}
struct V_426 * F_385 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
enum V_107 V_111 = V_110 -> V_111 ;
struct V_426 * V_351 ;
int V_737 = F_4 ( F_184 ( V_111 ) ) ;
int V_738 = F_4 ( F_188 ( V_111 ) ) ;
int V_739 = F_4 ( F_190 ( V_111 ) ) ;
int V_740 = F_4 ( F_194 ( V_111 ) ) ;
V_351 = F_367 ( sizeof( * V_351 ) , V_706 ) ;
if ( ! V_351 )
return NULL ;
V_351 -> clock = F_383 ( V_2 , V_37 ) ;
V_351 -> V_408 = ( V_737 & 0xffff ) + 1 ;
V_351 -> V_741 = ( ( V_737 & 0xffff0000 ) >> 16 ) + 1 ;
V_351 -> V_431 = ( V_738 & 0xffff ) + 1 ;
V_351 -> V_742 = ( ( V_738 & 0xffff0000 ) >> 16 ) + 1 ;
V_351 -> V_410 = ( V_739 & 0xffff ) + 1 ;
V_351 -> V_743 = ( ( V_739 & 0xffff0000 ) >> 16 ) + 1 ;
V_351 -> V_744 = ( V_740 & 0xffff ) + 1 ;
V_351 -> V_745 = ( ( V_740 & 0xffff0000 ) >> 16 ) + 1 ;
F_386 ( V_351 ) ;
return V_351 ;
}
static void F_144 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
int V_108 = V_110 -> V_108 ;
int V_746 = F_57 ( V_108 ) ;
int V_388 ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_554 )
return;
V_388 = F_4 ( V_746 ) ;
if ( ! F_288 ( V_2 ) && ( V_388 & V_722 ) ) {
F_60 ( L_148 ) ;
F_70 ( V_4 , V_108 ) ;
V_388 &= ~ V_722 ;
F_11 ( V_746 , V_388 ) ;
F_45 ( V_2 , V_108 ) ;
V_388 = F_4 ( V_746 ) ;
if ( V_388 & V_722 )
F_60 ( L_149 ) ;
}
}
static void F_387 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
if ( F_3 ( V_2 ) )
return;
if ( ! V_4 -> V_554 )
return;
if ( ! F_288 ( V_2 ) && V_110 -> V_475 ) {
int V_108 = V_110 -> V_108 ;
int V_746 = F_57 ( V_108 ) ;
int V_388 ;
F_60 ( L_150 ) ;
F_70 ( V_4 , V_108 ) ;
V_388 = F_4 ( V_746 ) ;
V_388 |= V_722 ;
F_11 ( V_746 , V_388 ) ;
F_45 ( V_2 , V_108 ) ;
V_388 = F_4 ( V_746 ) ;
if ( ! ( V_388 & V_722 ) )
F_60 ( L_151 ) ;
}
}
void F_388 ( struct V_1 * V_2 )
{
F_389 ( V_2 -> V_5 ) ;
}
void F_390 ( struct V_1 * V_2 )
{
}
void F_391 ( struct V_225 * V_226 )
{
struct V_1 * V_2 = V_226 -> V_204 . V_2 ;
struct V_36 * V_37 ;
if ( ! V_476 )
return;
F_234 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_37 -> V_247 )
continue;
if ( F_136 ( V_37 -> V_247 ) -> V_226 == V_226 )
F_144 ( V_37 ) ;
}
}
void F_392 ( struct V_225 * V_226 )
{
struct V_1 * V_2 = V_226 -> V_204 . V_2 ;
struct V_36 * V_37 ;
if ( ! V_476 )
return;
F_234 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_37 -> V_247 )
continue;
if ( F_136 ( V_37 -> V_247 ) -> V_226 == V_226 )
F_387 ( V_37 ) ;
}
}
static void F_393 ( struct V_36 * V_37 )
{
struct V_110 * V_110 = F_39 ( V_37 ) ;
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_747 * V_748 ;
unsigned long V_11 ;
F_8 ( & V_2 -> V_341 , V_11 ) ;
V_748 = V_110 -> V_342 ;
V_110 -> V_342 = NULL ;
F_12 ( & V_2 -> V_341 , V_11 ) ;
if ( V_748 ) {
F_394 ( & V_748 -> V_748 ) ;
F_240 ( V_748 ) ;
}
F_395 ( V_37 ) ;
F_240 ( V_110 ) ;
}
static void F_396 ( struct V_749 * V_750 )
{
struct V_747 * V_748 =
F_397 ( V_750 , struct V_747 , V_748 ) ;
struct V_1 * V_2 = V_748 -> V_37 -> V_2 ;
F_151 ( & V_2 -> V_299 ) ;
F_132 ( V_748 -> V_751 ) ;
F_360 ( & V_748 -> V_752 -> V_204 ) ;
F_360 ( & V_748 -> V_751 -> V_204 ) ;
F_153 ( V_2 ) ;
F_152 ( & V_2 -> V_299 ) ;
F_94 ( F_147 ( & F_39 ( V_748 -> V_37 ) -> V_753 ) == 0 ) ;
F_398 ( & F_39 ( V_748 -> V_37 ) -> V_753 ) ;
F_240 ( V_748 ) ;
}
static void F_399 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
struct V_747 * V_748 ;
struct V_225 * V_226 ;
unsigned long V_11 ;
if ( V_110 == NULL )
return;
F_8 ( & V_2 -> V_341 , V_11 ) ;
V_748 = V_110 -> V_342 ;
F_400 () ;
if ( V_748 == NULL || F_147 ( & V_748 -> V_340 ) < V_754 ) {
F_12 ( & V_2 -> V_341 , V_11 ) ;
return;
}
F_400 () ;
V_110 -> V_342 = NULL ;
if ( V_748 -> V_755 )
F_401 ( V_2 , V_110 -> V_108 , V_748 -> V_755 ) ;
F_402 ( V_2 , V_110 -> V_108 ) ;
F_12 ( & V_2 -> V_341 , V_11 ) ;
V_226 = V_748 -> V_751 ;
F_403 ( 1 << V_110 -> V_153 ,
& V_226 -> V_287 . V_756 ) ;
F_404 ( & V_4 -> V_285 ) ;
F_405 ( V_4 -> V_757 , & V_748 -> V_748 ) ;
F_406 ( V_110 -> V_153 , V_748 -> V_752 ) ;
}
void F_407 ( struct V_1 * V_2 , int V_108 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_36 * V_37 = V_4 -> V_109 [ V_108 ] ;
F_399 ( V_2 , V_37 ) ;
}
void F_408 ( struct V_1 * V_2 , int V_153 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_36 * V_37 = V_4 -> V_758 [ V_153 ] ;
F_399 ( V_2 , V_37 ) ;
}
void F_409 ( struct V_1 * V_2 , int V_153 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 =
F_39 ( V_4 -> V_758 [ V_153 ] ) ;
unsigned long V_11 ;
F_8 ( & V_2 -> V_341 , V_11 ) ;
if ( V_110 -> V_342 )
F_410 ( & V_110 -> V_342 -> V_340 ) ;
F_12 ( & V_2 -> V_341 , V_11 ) ;
}
inline static void F_411 ( struct V_110 * V_110 )
{
F_412 () ;
F_413 ( & V_110 -> V_342 -> V_340 , V_759 ) ;
F_412 () ;
}
static int F_414 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_246 * V_247 ,
struct V_225 * V_226 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
T_1 V_760 ;
struct V_227 * V_761 = & V_4 -> V_761 [ V_762 ] ;
int V_230 ;
V_230 = F_124 ( V_2 , V_226 , V_761 ) ;
if ( V_230 )
goto V_84;
V_230 = F_415 ( V_761 , 6 ) ;
if ( V_230 )
goto V_239;
if ( V_110 -> V_153 )
V_760 = V_763 ;
else
V_760 = V_764 ;
F_416 ( V_761 , V_765 | V_760 ) ;
F_416 ( V_761 , V_766 ) ;
F_416 ( V_761 , V_767 |
F_417 ( V_110 -> V_153 ) ) ;
F_416 ( V_761 , V_247 -> V_274 [ 0 ] ) ;
F_416 ( V_761 , V_226 -> V_277 + V_110 -> V_276 ) ;
F_416 ( V_761 , 0 ) ;
F_411 ( V_110 ) ;
F_418 ( V_761 ) ;
return 0 ;
V_239:
F_132 ( V_226 ) ;
V_84:
return V_230 ;
}
static int F_419 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_246 * V_247 ,
struct V_225 * V_226 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
T_1 V_760 ;
struct V_227 * V_761 = & V_4 -> V_761 [ V_762 ] ;
int V_230 ;
V_230 = F_124 ( V_2 , V_226 , V_761 ) ;
if ( V_230 )
goto V_84;
V_230 = F_415 ( V_761 , 6 ) ;
if ( V_230 )
goto V_239;
if ( V_110 -> V_153 )
V_760 = V_763 ;
else
V_760 = V_764 ;
F_416 ( V_761 , V_765 | V_760 ) ;
F_416 ( V_761 , V_766 ) ;
F_416 ( V_761 , V_768 |
F_417 ( V_110 -> V_153 ) ) ;
F_416 ( V_761 , V_247 -> V_274 [ 0 ] ) ;
F_416 ( V_761 , V_226 -> V_277 + V_110 -> V_276 ) ;
F_416 ( V_761 , V_766 ) ;
F_411 ( V_110 ) ;
F_418 ( V_761 ) ;
return 0 ;
V_239:
F_132 ( V_226 ) ;
V_84:
return V_230 ;
}
static int F_420 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_246 * V_247 ,
struct V_225 * V_226 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
T_5 V_769 , V_770 ;
struct V_227 * V_761 = & V_4 -> V_761 [ V_762 ] ;
int V_230 ;
V_230 = F_124 ( V_2 , V_226 , V_761 ) ;
if ( V_230 )
goto V_84;
V_230 = F_415 ( V_761 , 4 ) ;
if ( V_230 )
goto V_239;
F_416 ( V_761 , V_767 |
F_417 ( V_110 -> V_153 ) ) ;
F_416 ( V_761 , V_247 -> V_274 [ 0 ] ) ;
F_416 ( V_761 ,
( V_226 -> V_277 + V_110 -> V_276 ) |
V_226 -> V_231 ) ;
V_769 = 0 ;
V_770 = F_4 ( F_285 ( V_110 -> V_108 ) ) & 0x0fff0fff ;
F_416 ( V_761 , V_769 | V_770 ) ;
F_411 ( V_110 ) ;
F_418 ( V_761 ) ;
return 0 ;
V_239:
F_132 ( V_226 ) ;
V_84:
return V_230 ;
}
static int F_421 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_246 * V_247 ,
struct V_225 * V_226 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
struct V_227 * V_761 = & V_4 -> V_761 [ V_762 ] ;
T_5 V_769 , V_770 ;
int V_230 ;
V_230 = F_124 ( V_2 , V_226 , V_761 ) ;
if ( V_230 )
goto V_84;
V_230 = F_415 ( V_761 , 4 ) ;
if ( V_230 )
goto V_239;
F_416 ( V_761 , V_767 |
F_417 ( V_110 -> V_153 ) ) ;
F_416 ( V_761 , V_247 -> V_274 [ 0 ] | V_226 -> V_231 ) ;
F_416 ( V_761 , V_226 -> V_277 + V_110 -> V_276 ) ;
V_769 = 0 ;
V_770 = F_4 ( F_285 ( V_110 -> V_108 ) ) & 0x0fff0fff ;
F_416 ( V_761 , V_769 | V_770 ) ;
F_411 ( V_110 ) ;
F_418 ( V_761 ) ;
return 0 ;
V_239:
F_132 ( V_226 ) ;
V_84:
return V_230 ;
}
static int F_422 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_246 * V_247 ,
struct V_225 * V_226 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
struct V_227 * V_761 = & V_4 -> V_761 [ V_771 ] ;
T_5 V_772 = 0 ;
int V_230 ;
V_230 = F_124 ( V_2 , V_226 , V_761 ) ;
if ( V_230 )
goto V_84;
switch( V_110 -> V_153 ) {
case V_773 :
V_772 = V_774 ;
break;
case V_775 :
V_772 = V_776 ;
break;
case V_777 :
V_772 = V_778 ;
break;
default:
F_423 ( 1 , L_152 ) ;
V_230 = - V_779 ;
goto V_239;
}
V_230 = F_415 ( V_761 , 4 ) ;
if ( V_230 )
goto V_239;
F_416 ( V_761 , V_768 | V_772 ) ;
F_416 ( V_761 , ( V_247 -> V_274 [ 0 ] | V_226 -> V_231 ) ) ;
F_416 ( V_761 , V_226 -> V_277 + V_110 -> V_276 ) ;
F_416 ( V_761 , ( V_766 ) ) ;
F_411 ( V_110 ) ;
F_418 ( V_761 ) ;
return 0 ;
V_239:
F_132 ( V_226 ) ;
V_84:
return V_230 ;
}
static int F_424 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_246 * V_247 ,
struct V_225 * V_226 )
{
return - V_779 ;
}
static int F_425 ( struct V_36 * V_37 ,
struct V_246 * V_247 ,
struct V_780 * V_755 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_248 * V_249 ;
struct V_225 * V_226 ;
struct V_110 * V_110 = F_39 ( V_37 ) ;
struct V_747 * V_748 ;
unsigned long V_11 ;
int V_230 ;
if ( V_247 -> V_253 != V_37 -> V_247 -> V_253 )
return - V_235 ;
if ( F_47 ( V_2 ) -> V_115 > 3 &&
( V_247 -> V_781 [ 0 ] != V_37 -> V_247 -> V_781 [ 0 ] ||
V_247 -> V_274 [ 0 ] != V_37 -> V_247 -> V_274 [ 0 ] ) )
return - V_235 ;
V_748 = F_367 ( sizeof *V_748 , V_706 ) ;
if ( V_748 == NULL )
return - V_686 ;
V_748 -> V_755 = V_755 ;
V_748 -> V_37 = V_37 ;
V_249 = F_136 ( V_37 -> V_247 ) ;
V_748 -> V_751 = V_249 -> V_226 ;
F_426 ( & V_748 -> V_748 , F_396 ) ;
V_230 = F_427 ( V_2 , V_110 -> V_108 ) ;
if ( V_230 )
goto V_782;
F_8 ( & V_2 -> V_341 , V_11 ) ;
if ( V_110 -> V_342 ) {
F_12 ( & V_2 -> V_341 , V_11 ) ;
F_240 ( V_748 ) ;
F_402 ( V_2 , V_110 -> V_108 ) ;
F_60 ( L_153 ) ;
return - V_783 ;
}
V_110 -> V_342 = V_748 ;
F_12 ( & V_2 -> V_341 , V_11 ) ;
V_249 = F_136 ( V_247 ) ;
V_226 = V_249 -> V_226 ;
if ( F_147 ( & V_110 -> V_753 ) >= 2 )
F_428 ( V_4 -> V_757 ) ;
V_230 = F_429 ( V_2 ) ;
if ( V_230 )
goto V_784;
F_430 ( & V_748 -> V_751 -> V_204 ) ;
F_430 ( & V_226 -> V_204 ) ;
V_37 -> V_247 = V_247 ;
V_748 -> V_752 = V_226 ;
V_748 -> V_785 = true ;
F_431 ( 1 << V_110 -> V_153 , & V_748 -> V_751 -> V_287 ) ;
F_432 ( & V_110 -> V_753 ) ;
V_230 = V_4 -> V_280 . V_786 ( V_2 , V_37 , V_247 , V_226 ) ;
if ( V_230 )
goto V_787;
F_216 ( V_2 ) ;
F_391 ( V_226 ) ;
F_152 ( & V_2 -> V_299 ) ;
F_433 ( V_110 -> V_153 , V_226 ) ;
return 0 ;
V_787:
F_398 ( & V_110 -> V_753 ) ;
F_434 ( 1 << V_110 -> V_153 , & V_748 -> V_751 -> V_287 ) ;
F_360 ( & V_748 -> V_751 -> V_204 ) ;
F_360 ( & V_226 -> V_204 ) ;
F_152 ( & V_2 -> V_299 ) ;
V_784:
F_8 ( & V_2 -> V_341 , V_11 ) ;
V_110 -> V_342 = NULL ;
F_12 ( & V_2 -> V_341 , V_11 ) ;
F_402 ( V_2 , V_110 -> V_108 ) ;
V_782:
F_240 ( V_748 ) ;
return V_230 ;
}
bool F_435 ( struct V_77 * V_78 )
{
struct V_77 * V_788 ;
struct V_36 * V_37 = & V_78 -> V_717 -> V_204 ;
if ( F_2 ( ! V_37 ) )
return false ;
F_234 (other_encoder,
&crtc->dev->mode_config.encoder_list,
base.head) {
if ( & V_788 -> V_717 -> V_204 != V_37 ||
V_78 == V_788 )
continue;
else
return true ;
}
return false ;
}
static bool F_436 ( struct V_421 * V_78 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_36 * V_191 ;
int V_789 = 1 ;
F_50 ( ! V_37 , L_154 ) ;
V_2 = V_37 -> V_2 ;
F_234 (tmp, &dev->mode_config.crtc_list, head) {
if ( V_191 == V_37 )
break;
V_789 <<= 1 ;
}
if ( V_78 -> V_716 & V_789 )
return true ;
return false ;
}
static void F_437 ( struct V_1 * V_2 )
{
struct V_77 * V_78 ;
struct V_423 * V_417 ;
F_234 (connector, &dev->mode_config.connector_list,
base.head) {
V_417 -> V_718 =
F_235 ( V_417 -> V_204 . V_78 ) ;
}
F_234 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_78 -> V_717 =
F_39 ( V_78 -> V_204 . V_37 ) ;
}
}
static void F_438 ( struct V_1 * V_2 )
{
struct V_77 * V_78 ;
struct V_423 * V_417 ;
F_234 (connector, &dev->mode_config.connector_list,
base.head) {
V_417 -> V_204 . V_78 = & V_417 -> V_718 -> V_204 ;
}
F_234 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_78 -> V_204 . V_37 = & V_78 -> V_717 -> V_204 ;
}
}
static struct V_426 *
F_439 ( struct V_36 * V_37 ,
struct V_426 * V_351 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_426 * V_427 ;
struct V_613 * V_614 ;
struct V_77 * V_78 ;
V_427 = F_440 ( V_2 , V_351 ) ;
if ( ! V_427 )
return F_368 ( - V_686 ) ;
F_234 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( & V_78 -> V_717 -> V_204 != V_37 )
continue;
V_614 = V_78 -> V_204 . V_617 ;
if ( ! ( V_614 -> V_790 ( & V_78 -> V_204 , V_351 ,
V_427 ) ) ) {
F_44 ( L_155 ) ;
goto V_687;
}
}
if ( ! ( F_248 ( V_37 , V_351 , V_427 ) ) ) {
F_44 ( L_156 ) ;
goto V_687;
}
F_44 ( L_157 , V_37 -> V_204 . V_26 ) ;
return V_427 ;
V_687:
F_441 ( V_2 , V_427 ) ;
return F_368 ( - V_235 ) ;
}
static void
F_442 ( struct V_36 * V_37 , unsigned * V_791 ,
unsigned * V_792 , unsigned * V_793 )
{
struct V_110 * V_110 ;
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_77 * V_78 ;
struct V_423 * V_417 ;
struct V_36 * V_794 ;
* V_793 = * V_791 = * V_792 = 0 ;
F_234 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_417 -> V_204 . V_78 == & V_417 -> V_718 -> V_204 )
continue;
if ( V_417 -> V_204 . V_78 ) {
V_794 = V_417 -> V_204 . V_78 -> V_37 ;
* V_792 |= 1 << F_39 ( V_794 ) -> V_108 ;
}
if ( V_417 -> V_718 )
* V_792 |=
1 << V_417 -> V_718 -> V_717 -> V_108 ;
}
F_234 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_78 -> V_204 . V_37 == & V_78 -> V_717 -> V_204 )
continue;
if ( V_78 -> V_204 . V_37 ) {
V_794 = V_78 -> V_204 . V_37 ;
* V_792 |= 1 << F_39 ( V_794 ) -> V_108 ;
}
if ( V_78 -> V_717 )
* V_792 |= 1 << V_78 -> V_717 -> V_108 ;
}
F_234 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
bool V_795 = false ;
if ( ! V_110 -> V_204 . V_124 )
continue;
F_234 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_78 -> V_717 == V_110 )
V_795 = true ;
}
if ( ! V_795 )
* V_793 |= 1 << V_110 -> V_108 ;
}
V_110 = F_39 ( V_37 ) ;
if ( V_37 -> V_124 )
* V_792 |= 1 << V_110 -> V_108 ;
if ( * V_792 )
* V_791 = * V_792 ;
* V_791 &= ~ ( * V_793 ) ;
* V_792 &= ~ ( * V_793 ) ;
}
static bool F_443 ( struct V_36 * V_37 )
{
struct V_421 * V_78 ;
struct V_1 * V_2 = V_37 -> V_2 ;
F_234 (encoder, &dev->mode_config.encoder_list, head)
if ( V_78 -> V_37 == V_37 )
return true ;
return false ;
}
static void
F_444 ( struct V_1 * V_2 , unsigned V_792 )
{
struct V_77 * V_77 ;
struct V_110 * V_110 ;
struct V_416 * V_417 ;
F_234 (intel_encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_77 -> V_204 . V_37 )
continue;
V_110 = F_39 ( V_77 -> V_204 . V_37 ) ;
if ( V_792 & ( 1 << V_110 -> V_108 ) )
V_77 -> V_413 = false ;
}
F_438 ( V_2 ) ;
F_234 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
V_110 -> V_204 . V_124 = F_443 ( & V_110 -> V_204 ) ;
}
F_234 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_417 -> V_78 || ! V_417 -> V_78 -> V_37 )
continue;
V_110 = F_39 ( V_417 -> V_78 -> V_37 ) ;
if ( V_792 & ( 1 << V_110 -> V_108 ) ) {
struct V_796 * V_797 =
V_2 -> V_568 . V_797 ;
V_417 -> V_419 = V_422 ;
F_445 ( & V_417 -> V_204 ,
V_797 ,
V_422 ) ;
V_77 = F_235 ( V_417 -> V_78 ) ;
V_77 -> V_413 = true ;
}
}
}
bool F_381 ( struct V_36 * V_37 ,
struct V_426 * V_351 ,
int V_240 , int V_241 , struct V_246 * V_247 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_426 * V_427 , V_798 , V_799 ;
struct V_110 * V_110 ;
unsigned V_793 , V_792 , V_791 ;
bool V_230 = true ;
F_442 ( V_37 , & V_791 ,
& V_792 , & V_793 ) ;
F_44 ( L_158 ,
V_791 , V_792 , V_793 ) ;
F_446 (dev, disable_pipes, intel_crtc)
F_232 ( & V_110 -> V_204 ) ;
V_799 = V_37 -> V_800 ;
V_798 = V_37 -> V_351 ;
V_427 = NULL ;
if ( V_791 ) {
V_427 = F_439 ( V_37 , V_351 ) ;
if ( F_380 ( V_427 ) ) {
return false ;
}
}
F_446 (dev, prepare_pipes, intel_crtc) {
if ( V_110 -> V_204 . V_124 )
V_4 -> V_280 . V_415 ( & V_110 -> V_204 ) ;
}
if ( V_791 )
V_37 -> V_351 = * V_351 ;
F_444 ( V_2 , V_792 ) ;
if ( V_4 -> V_280 . V_801 )
V_4 -> V_280 . V_801 ( V_2 ) ;
F_446 (dev, modeset_pipes, intel_crtc) {
V_230 = ! F_320 ( & V_110 -> V_204 ,
V_351 , V_427 ,
V_240 , V_241 , V_247 ) ;
if ( ! V_230 )
goto V_802;
}
F_446 (dev, prepare_pipes, intel_crtc)
V_4 -> V_280 . V_414 ( & V_110 -> V_204 ) ;
if ( V_791 ) {
V_37 -> V_800 = * V_427 ;
F_447 ( V_37 ) ;
}
V_802:
F_441 ( V_2 , V_427 ) ;
if ( ! V_230 && V_37 -> V_124 ) {
V_37 -> V_800 = V_799 ;
V_37 -> V_351 = V_798 ;
} else {
F_246 ( V_2 ) ;
}
return V_230 ;
}
static void F_448 ( struct V_803 * V_804 )
{
if ( ! V_804 )
return;
F_240 ( V_804 -> V_805 ) ;
F_240 ( V_804 -> V_806 ) ;
F_240 ( V_804 ) ;
}
static int F_449 ( struct V_1 * V_2 ,
struct V_803 * V_804 )
{
struct V_421 * V_78 ;
struct V_416 * V_417 ;
int V_807 ;
V_804 -> V_806 =
F_450 ( V_2 -> V_568 . V_808 ,
sizeof( struct V_36 * ) , V_706 ) ;
if ( ! V_804 -> V_806 )
return - V_686 ;
V_804 -> V_805 =
F_450 ( V_2 -> V_568 . V_809 ,
sizeof( struct V_421 * ) , V_706 ) ;
if ( ! V_804 -> V_805 )
return - V_686 ;
V_807 = 0 ;
F_234 (encoder, &dev->mode_config.encoder_list, head) {
V_804 -> V_806 [ V_807 ++ ] = V_78 -> V_37 ;
}
V_807 = 0 ;
F_234 (connector, &dev->mode_config.connector_list, head) {
V_804 -> V_805 [ V_807 ++ ] = V_417 -> V_78 ;
}
return 0 ;
}
static void F_451 ( struct V_1 * V_2 ,
struct V_803 * V_804 )
{
struct V_77 * V_78 ;
struct V_423 * V_417 ;
int V_807 ;
V_807 = 0 ;
F_234 (encoder, &dev->mode_config.encoder_list, base.head) {
V_78 -> V_717 =
F_39 ( V_804 -> V_806 [ V_807 ++ ] ) ;
}
V_807 = 0 ;
F_234 (connector, &dev->mode_config.connector_list, base.head) {
V_417 -> V_718 =
F_235 ( V_804 -> V_805 [ V_807 ++ ] ) ;
}
}
static void
F_452 ( struct V_810 * V_811 ,
struct V_803 * V_804 )
{
if ( V_811 -> V_37 -> V_247 != V_811 -> V_247 ) {
if ( V_811 -> V_37 -> V_247 == NULL ) {
F_44 ( L_159 ) ;
V_804 -> V_812 = true ;
} else if ( V_811 -> V_247 == NULL ) {
V_804 -> V_812 = true ;
} else if ( V_811 -> V_247 -> V_470 != V_811 -> V_37 -> V_247 -> V_470 ) {
V_804 -> V_812 = true ;
} else if ( V_811 -> V_247 -> V_275 !=
V_811 -> V_37 -> V_247 -> V_275 ) {
V_804 -> V_812 = true ;
} else
V_804 -> V_813 = true ;
}
if ( V_811 -> V_247 && ( V_811 -> V_240 != V_811 -> V_37 -> V_240 || V_811 -> V_241 != V_811 -> V_37 -> V_241 ) )
V_804 -> V_813 = true ;
if ( V_811 -> V_351 && ! F_453 ( V_811 -> V_351 , & V_811 -> V_37 -> V_351 ) ) {
F_44 ( L_160 ) ;
F_287 ( & V_811 -> V_37 -> V_351 ) ;
F_287 ( V_811 -> V_351 ) ;
V_804 -> V_812 = true ;
}
}
static int
F_454 ( struct V_1 * V_2 ,
struct V_810 * V_811 ,
struct V_803 * V_804 )
{
struct V_36 * V_717 ;
struct V_423 * V_417 ;
struct V_77 * V_78 ;
int V_807 , V_814 ;
F_2 ( ! V_811 -> V_247 && ( V_811 -> V_471 != 0 ) ) ;
F_2 ( V_811 -> V_247 && ( V_811 -> V_471 == 0 ) ) ;
V_807 = 0 ;
F_234 (connector, &dev->mode_config.connector_list,
base.head) {
for ( V_814 = 0 ; V_814 < V_811 -> V_471 ; V_814 ++ ) {
if ( V_811 -> V_815 [ V_814 ] == & V_417 -> V_204 ) {
V_417 -> V_718 = V_417 -> V_78 ;
break;
}
}
if ( ( ! V_811 -> V_247 || V_814 == V_811 -> V_471 ) &&
V_417 -> V_204 . V_78 &&
V_417 -> V_204 . V_78 -> V_37 == V_811 -> V_37 ) {
V_417 -> V_718 = NULL ;
F_44 ( L_161 ,
V_417 -> V_204 . V_204 . V_26 ,
F_243 ( & V_417 -> V_204 ) ) ;
}
if ( & V_417 -> V_718 -> V_204 != V_417 -> V_204 . V_78 ) {
F_44 ( L_162 ) ;
V_804 -> V_812 = true ;
}
}
V_807 = 0 ;
F_234 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_417 -> V_718 )
continue;
V_717 = V_417 -> V_718 -> V_204 . V_37 ;
for ( V_814 = 0 ; V_814 < V_811 -> V_471 ; V_814 ++ ) {
if ( V_811 -> V_815 [ V_814 ] == & V_417 -> V_204 )
V_717 = V_811 -> V_37 ;
}
if ( ! F_436 ( & V_417 -> V_718 -> V_204 ,
V_717 ) ) {
return - V_235 ;
}
V_417 -> V_78 -> V_717 = F_39 ( V_717 ) ;
F_44 ( L_163 ,
V_417 -> V_204 . V_204 . V_26 ,
F_243 ( & V_417 -> V_204 ) ,
V_717 -> V_204 . V_26 ) ;
}
F_234 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_234 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_417 -> V_718 == V_78 ) {
F_2 ( ! V_417 -> V_718 -> V_717 ) ;
goto V_816;
}
}
V_78 -> V_717 = NULL ;
V_816:
if ( & V_78 -> V_717 -> V_204 != V_78 -> V_204 . V_37 ) {
F_44 ( L_164 ) ;
V_804 -> V_812 = true ;
}
}
return 0 ;
}
static int F_455 ( struct V_810 * V_811 )
{
struct V_1 * V_2 ;
struct V_810 V_817 ;
struct V_803 * V_804 ;
int V_230 ;
F_94 ( ! V_811 ) ;
F_94 ( ! V_811 -> V_37 ) ;
F_94 ( ! V_811 -> V_37 -> V_617 ) ;
if ( ! V_811 -> V_351 )
V_811 -> V_247 = NULL ;
if ( V_811 -> V_247 && V_811 -> V_471 == 0 )
return 0 ;
if ( V_811 -> V_247 ) {
F_44 ( L_165 ,
V_811 -> V_37 -> V_204 . V_26 , V_811 -> V_247 -> V_204 . V_26 ,
( int ) V_811 -> V_471 , V_811 -> V_240 , V_811 -> V_241 ) ;
} else {
F_44 ( L_166 , V_811 -> V_37 -> V_204 . V_26 ) ;
}
V_2 = V_811 -> V_37 -> V_2 ;
V_230 = - V_686 ;
V_804 = F_367 ( sizeof( * V_804 ) , V_706 ) ;
if ( ! V_804 )
goto V_818;
V_230 = F_449 ( V_2 , V_804 ) ;
if ( V_230 )
goto V_818;
V_817 . V_37 = V_811 -> V_37 ;
V_817 . V_351 = & V_811 -> V_37 -> V_351 ;
V_817 . V_240 = V_811 -> V_37 -> V_240 ;
V_817 . V_241 = V_811 -> V_37 -> V_241 ;
V_817 . V_247 = V_811 -> V_37 -> V_247 ;
F_452 ( V_811 , V_804 ) ;
V_230 = F_454 ( V_2 , V_811 , V_804 ) ;
if ( V_230 )
goto V_687;
if ( V_804 -> V_812 ) {
if ( V_811 -> V_351 ) {
F_44 ( L_167
L_168 ) ;
F_287 ( V_811 -> V_351 ) ;
}
if ( ! F_381 ( V_811 -> V_37 , V_811 -> V_351 ,
V_811 -> V_240 , V_811 -> V_241 , V_811 -> V_247 ) ) {
F_10 ( L_169 ,
V_811 -> V_37 -> V_204 . V_26 ) ;
V_230 = - V_235 ;
goto V_687;
}
} else if ( V_804 -> V_813 ) {
V_230 = F_150 ( V_811 -> V_37 ,
V_811 -> V_240 , V_811 -> V_241 , V_811 -> V_247 ) ;
}
F_448 ( V_804 ) ;
return 0 ;
V_687:
F_451 ( V_2 , V_804 ) ;
if ( V_804 -> V_812 &&
! F_381 ( V_817 . V_37 , V_817 . V_351 ,
V_817 . V_240 , V_817 . V_241 , V_817 . V_247 ) )
F_10 ( L_170 ) ;
V_818:
F_448 ( V_804 ) ;
return V_230 ;
}
static void F_456 ( struct V_1 * V_2 )
{
if ( F_63 ( V_2 ) )
F_457 ( V_2 ) ;
}
static void F_458 ( struct V_1 * V_2 )
{
T_7 * V_4 = V_2 -> V_5 ;
int V_155 ;
if ( V_4 -> V_392 == 0 ) {
F_44 ( L_171 ) ;
return;
}
for ( V_155 = 0 ; V_155 < V_4 -> V_392 ; V_155 ++ ) {
V_4 -> V_391 [ V_155 ] . V_130 = F_459 ( V_155 ) ;
V_4 -> V_391 [ V_155 ] . V_393 = F_460 ( V_155 ) ;
V_4 -> V_391 [ V_155 ] . V_612 = F_461 ( V_155 ) ;
}
}
static void F_462 ( struct V_1 * V_2 , int V_108 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_110 * V_110 ;
int V_155 ;
V_110 = F_367 ( sizeof( struct V_110 ) + ( V_819 * sizeof( struct V_416 * ) ) , V_706 ) ;
if ( V_110 == NULL )
return;
F_463 ( V_2 , & V_110 -> V_204 , & V_820 ) ;
F_464 ( & V_110 -> V_204 , 256 ) ;
for ( V_155 = 0 ; V_155 < 256 ; V_155 ++ ) {
V_110 -> V_651 [ V_155 ] = V_155 ;
V_110 -> V_652 [ V_155 ] = V_155 ;
V_110 -> V_653 [ V_155 ] = V_155 ;
}
V_110 -> V_108 = V_108 ;
V_110 -> V_153 = V_108 ;
V_110 -> V_111 = V_108 ;
if ( F_95 ( V_2 ) && F_465 ( V_2 ) ) {
F_44 ( L_172 ) ;
V_110 -> V_153 = ! V_108 ;
}
F_94 ( V_108 >= F_466 ( V_4 -> V_758 ) ||
V_4 -> V_758 [ V_110 -> V_153 ] != NULL ) ;
V_4 -> V_758 [ V_110 -> V_153 ] = & V_110 -> V_204 ;
V_4 -> V_109 [ V_110 -> V_108 ] = & V_110 -> V_204 ;
V_110 -> V_242 = 24 ;
F_467 ( & V_110 -> V_204 , & V_821 ) ;
}
int F_468 ( struct V_1 * V_2 , void * V_822 ,
struct V_679 * V_680 )
{
struct V_823 * V_824 = V_822 ;
struct V_825 * V_826 ;
struct V_110 * V_37 ;
if ( ! F_469 ( V_2 , V_827 ) )
return - V_779 ;
V_826 = F_470 ( V_2 , V_824 -> V_828 ,
V_829 ) ;
if ( ! V_826 ) {
F_10 ( L_173 ) ;
return - V_235 ;
}
V_37 = F_39 ( F_471 ( V_826 ) ) ;
V_824 -> V_108 = V_37 -> V_108 ;
return 0 ;
}
static int F_472 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_204 . V_2 ;
struct V_77 * V_830 ;
int V_831 = 0 ;
int V_832 = 0 ;
F_234 (source_encoder,
&dev->mode_config.encoder_list, base.head) {
if ( V_78 == V_830 )
V_831 |= ( 1 << V_832 ) ;
if ( V_78 -> V_833 && V_830 -> V_833 )
V_831 |= ( 1 << V_832 ) ;
V_832 ++ ;
}
return V_831 ;
}
static bool F_473 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_95 ( V_2 ) )
return false ;
if ( ( F_4 ( V_301 ) & V_834 ) == 0 )
return false ;
if ( F_6 ( V_2 ) &&
( F_4 ( V_835 ) & V_836 ) )
return false ;
return true ;
}
static void F_474 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_77 * V_78 ;
bool V_837 = false ;
bool V_569 ;
V_569 = F_475 ( V_2 ) ;
if ( ! V_569 && ! F_3 ( V_2 ) ) {
F_11 ( V_838 , 0 ) ;
}
if ( ! ( F_63 ( V_2 ) &&
( F_4 ( F_476 ( V_839 ) ) & V_840 ) ) )
F_477 ( V_2 ) ;
if ( F_63 ( V_2 ) ) {
int V_90 ;
V_90 = F_4 ( V_841 ) & V_842 ;
if ( V_90 )
F_478 ( V_2 , V_839 ) ;
V_90 = F_4 ( V_843 ) ;
if ( V_90 & V_844 )
F_478 ( V_2 , V_845 ) ;
if ( V_90 & V_846 )
F_478 ( V_2 , V_847 ) ;
if ( V_90 & V_848 )
F_478 ( V_2 , V_849 ) ;
} else if ( F_3 ( V_2 ) ) {
int V_90 ;
V_837 = F_479 ( V_2 ) ;
if ( F_473 ( V_2 ) )
F_480 ( V_2 , V_301 , V_839 ) ;
if ( F_4 ( V_185 ) & V_850 ) {
V_90 = F_481 ( V_2 , V_851 , true ) ;
if ( ! V_90 )
F_482 ( V_2 , V_185 , V_845 ) ;
if ( ! V_90 && ( F_4 ( V_178 ) & V_834 ) )
F_480 ( V_2 , V_178 , V_845 ) ;
}
if ( F_4 ( V_186 ) & V_850 )
F_482 ( V_2 , V_186 , V_847 ) ;
if ( ! V_837 && F_4 ( V_187 ) & V_850 )
F_482 ( V_2 , V_187 , V_849 ) ;
if ( F_4 ( V_180 ) & V_834 )
F_480 ( V_2 , V_180 , V_847 ) ;
if ( F_4 ( V_182 ) & V_834 )
F_480 ( V_2 , V_182 , V_849 ) ;
} else if ( F_26 ( V_2 ) ) {
int V_90 ;
if ( F_4 ( V_852 ) & V_834 )
F_480 ( V_2 , V_852 , V_847 ) ;
if ( F_4 ( V_853 ) & V_850 ) {
V_90 = F_481 ( V_2 , V_853 , true ) ;
if ( ! V_90 )
F_482 ( V_2 , V_853 , V_845 ) ;
if ( ! V_90 && ( F_4 ( V_854 ) & V_834 ) )
F_480 ( V_2 , V_854 , V_845 ) ;
}
if ( F_4 ( V_855 ) & V_850 )
F_482 ( V_2 , V_855 , V_847 ) ;
} else if ( F_483 ( V_2 ) ) {
bool V_90 = false ;
if ( F_4 ( V_853 ) & V_856 ) {
F_44 ( L_174 ) ;
V_90 = F_481 ( V_2 , V_853 , true ) ;
if ( ! V_90 && F_484 ( V_2 ) ) {
F_44 ( L_175 ) ;
F_482 ( V_2 , V_853 , V_845 ) ;
}
if ( ! V_90 && F_485 ( V_2 ) ) {
F_44 ( L_176 ) ;
F_480 ( V_2 , V_854 , V_845 ) ;
}
}
if ( F_4 ( V_853 ) & V_856 ) {
F_44 ( L_177 ) ;
V_90 = F_481 ( V_2 , V_855 , false ) ;
}
if ( ! V_90 && ( F_4 ( V_855 ) & V_856 ) ) {
if ( F_484 ( V_2 ) ) {
F_44 ( L_178 ) ;
F_482 ( V_2 , V_855 , V_847 ) ;
}
if ( F_485 ( V_2 ) ) {
F_44 ( L_179 ) ;
F_480 ( V_2 , V_852 , V_847 ) ;
}
}
if ( F_485 ( V_2 ) &&
( F_4 ( V_857 ) & V_834 ) ) {
F_44 ( L_180 ) ;
F_480 ( V_2 , V_857 , V_849 ) ;
}
} else if ( F_27 ( V_2 ) )
F_486 ( V_2 ) ;
if ( F_487 ( V_2 ) )
F_488 ( V_2 ) ;
F_234 (encoder, &dev->mode_config.encoder_list, base.head) {
V_78 -> V_204 . V_716 = V_78 -> V_789 ;
V_78 -> V_204 . V_858 =
F_472 ( V_78 ) ;
}
F_293 ( V_2 ) ;
F_489 ( V_2 ) ;
}
static void F_490 ( struct V_246 * V_247 )
{
struct V_248 * V_249 = F_136 ( V_247 ) ;
F_491 ( V_247 ) ;
F_361 ( & V_249 -> V_226 -> V_204 ) ;
F_240 ( V_249 ) ;
}
static int F_492 ( struct V_246 * V_247 ,
struct V_679 * V_680 ,
unsigned int * V_681 )
{
struct V_248 * V_249 = F_136 ( V_247 ) ;
struct V_225 * V_226 = V_249 -> V_226 ;
return F_493 ( V_680 , & V_226 -> V_204 , V_681 ) ;
}
int F_369 ( struct V_1 * V_2 ,
struct V_248 * V_249 ,
struct V_704 * V_705 ,
struct V_225 * V_226 )
{
int V_230 ;
if ( V_226 -> V_231 == V_234 ) {
F_263 ( L_181 ) ;
return - V_235 ;
}
if ( V_705 -> V_274 [ 0 ] & 63 ) {
F_263 ( L_182 ,
V_705 -> V_274 [ 0 ] ) ;
return - V_235 ;
}
if ( V_705 -> V_274 [ 0 ] > 32768 ) {
F_263 ( L_183 ,
V_705 -> V_274 [ 0 ] ) ;
return - V_235 ;
}
if ( V_226 -> V_231 != V_232 &&
V_705 -> V_274 [ 0 ] != V_226 -> V_859 ) {
F_263 ( L_184 ,
V_705 -> V_274 [ 0 ] , V_226 -> V_859 ) ;
return - V_235 ;
}
switch ( V_705 -> V_253 ) {
case V_254 :
case V_259 :
case V_261 :
case V_262 :
break;
case V_256 :
case V_257 :
if ( F_47 ( V_2 ) -> V_115 > 3 ) {
F_263 ( L_185 , V_705 -> V_253 ) ;
return - V_235 ;
}
break;
case V_264 :
case V_265 :
case V_267 :
case V_268 :
case V_270 :
case V_271 :
if ( F_47 ( V_2 ) -> V_115 < 4 ) {
F_263 ( L_185 , V_705 -> V_253 ) ;
return - V_235 ;
}
break;
case V_860 :
case V_861 :
case V_862 :
case V_863 :
if ( F_47 ( V_2 ) -> V_115 < 5 ) {
F_263 ( L_185 , V_705 -> V_253 ) ;
return - V_235 ;
}
break;
default:
F_263 ( L_186 , V_705 -> V_253 ) ;
return - V_235 ;
}
if ( V_705 -> V_781 [ 0 ] != 0 )
return - V_235 ;
V_230 = F_494 ( V_2 , & V_249 -> V_204 , & V_864 ) ;
if ( V_230 ) {
F_10 ( L_187 , V_230 ) ;
return V_230 ;
}
F_495 ( & V_249 -> V_204 , V_705 ) ;
V_249 -> V_226 = V_226 ;
return 0 ;
}
static struct V_246 *
F_496 ( struct V_1 * V_2 ,
struct V_679 * V_865 ,
struct V_704 * V_705 )
{
struct V_225 * V_226 ;
V_226 = F_355 ( F_356 ( V_2 , V_865 ,
V_705 -> V_866 [ 0 ] ) ) ;
if ( & V_226 -> V_204 == NULL )
return F_368 ( - V_684 ) ;
return F_366 ( V_2 , V_705 , V_226 ) ;
}
static void F_497 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_63 ( V_2 ) ) {
V_4 -> V_280 . V_615 = F_318 ;
V_4 -> V_280 . V_414 = F_210 ;
V_4 -> V_280 . V_415 = F_217 ;
V_4 -> V_280 . V_418 = F_222 ;
V_4 -> V_280 . V_282 = F_141 ;
} else if ( F_3 ( V_2 ) ) {
V_4 -> V_280 . V_615 = F_311 ;
V_4 -> V_280 . V_414 = F_202 ;
V_4 -> V_280 . V_415 = F_214 ;
V_4 -> V_280 . V_418 = F_221 ;
V_4 -> V_280 . V_282 = F_141 ;
} else {
V_4 -> V_280 . V_615 = F_286 ;
V_4 -> V_280 . V_414 = F_226 ;
V_4 -> V_280 . V_415 = F_227 ;
V_4 -> V_280 . V_418 = F_228 ;
V_4 -> V_280 . V_282 = F_135 ;
}
if ( F_26 ( V_2 ) )
V_4 -> V_280 . V_558 =
F_250 ;
else if ( F_280 ( V_2 ) || ( F_282 ( V_2 ) && ! F_498 ( V_2 ) ) )
V_4 -> V_280 . V_558 =
F_251 ;
else if ( F_499 ( V_2 ) )
V_4 -> V_280 . V_558 =
F_252 ;
else if ( F_281 ( V_2 ) || F_352 ( V_2 ) || F_498 ( V_2 ) )
V_4 -> V_280 . V_558 =
F_253 ;
else if ( F_500 ( V_2 ) )
V_4 -> V_280 . V_558 =
F_254 ;
else if ( F_353 ( V_2 ) )
V_4 -> V_280 . V_558 =
F_256 ;
else if ( F_501 ( V_2 ) )
V_4 -> V_280 . V_558 =
F_257 ;
else
V_4 -> V_280 . V_558 =
F_258 ;
if ( F_3 ( V_2 ) ) {
if ( F_6 ( V_2 ) ) {
V_4 -> V_280 . V_364 = F_158 ;
V_4 -> V_280 . V_649 = F_331 ;
} else if ( F_165 ( V_2 ) ) {
V_4 -> V_280 . V_364 = F_163 ;
V_4 -> V_280 . V_649 = F_331 ;
} else if ( F_156 ( V_2 ) ) {
V_4 -> V_280 . V_364 = F_166 ;
V_4 -> V_280 . V_649 = F_331 ;
V_4 -> V_280 . V_801 =
F_157 ;
} else if ( F_63 ( V_2 ) ) {
V_4 -> V_280 . V_364 = V_867 ;
V_4 -> V_280 . V_649 = F_327 ;
} else
V_4 -> V_280 . V_868 = NULL ;
} else if ( F_24 ( V_2 ) ) {
V_4 -> V_280 . V_649 = F_325 ;
}
V_4 -> V_280 . V_786 = F_424 ;
switch ( F_47 ( V_2 ) -> V_115 ) {
case 2 :
V_4 -> V_280 . V_786 = F_414 ;
break;
case 3 :
V_4 -> V_280 . V_786 = F_419 ;
break;
case 4 :
case 5 :
V_4 -> V_280 . V_786 = F_420 ;
break;
case 6 :
V_4 -> V_280 . V_786 = F_421 ;
break;
case 7 :
V_4 -> V_280 . V_786 = F_422 ;
break;
}
}
static void F_502 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_150 |= V_151 ;
F_17 ( L_188 ) ;
}
static void F_503 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_150 |= V_459 ;
F_17 ( L_189 ) ;
}
static void F_504 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_150 |= V_869 ;
F_17 ( L_190 ) ;
}
static int F_505 ( const struct V_25 * V_26 )
{
F_17 ( L_191 , V_26 -> V_27 ) ;
return 1 ;
}
static void F_506 ( struct V_1 * V_2 )
{
struct V_870 * V_871 = V_2 -> V_433 ;
int V_155 ;
for ( V_155 = 0 ; V_155 < F_466 ( V_872 ) ; V_155 ++ ) {
struct V_873 * V_874 = & V_872 [ V_155 ] ;
if ( V_871 -> V_875 == V_874 -> V_875 &&
( V_871 -> V_876 == V_874 -> V_876 ||
V_874 -> V_876 == V_877 ) &&
( V_871 -> V_878 == V_874 -> V_878 ||
V_874 -> V_878 == V_877 ) )
V_874 -> V_879 ( V_2 ) ;
}
for ( V_155 = 0 ; V_155 < F_466 ( V_880 ) ; V_155 ++ ) {
if ( F_19 ( * V_880 [ V_155 ] . V_881 ) != 0 )
V_880 [ V_155 ] . V_879 ( V_2 ) ;
}
}
static void F_507 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_8 V_882 ;
T_1 V_883 ;
if ( F_3 ( V_2 ) )
V_883 = V_884 ;
else
V_883 = V_885 ;
F_508 ( V_2 -> V_433 , V_886 ) ;
F_509 ( V_887 , V_888 ) ;
V_882 = F_510 ( V_889 ) ;
F_509 ( V_882 | 1 << 5 , V_889 ) ;
F_511 ( V_2 -> V_433 , V_886 ) ;
F_97 ( 300 ) ;
F_11 ( V_883 , V_890 ) ;
F_15 ( V_883 ) ;
}
void F_512 ( struct V_1 * V_2 )
{
F_513 ( V_2 ) ;
F_514 ( V_2 ) ;
F_515 ( V_2 ) ;
F_151 ( & V_2 -> V_299 ) ;
F_516 ( V_2 ) ;
F_152 ( & V_2 -> V_299 ) ;
}
void F_517 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_155 , V_230 ;
F_518 ( V_2 ) ;
V_2 -> V_568 . V_891 = 0 ;
V_2 -> V_568 . V_892 = 0 ;
V_2 -> V_568 . V_893 = 24 ;
V_2 -> V_568 . V_894 = 1 ;
V_2 -> V_568 . V_715 = & V_895 ;
F_506 ( V_2 ) ;
F_519 ( V_2 ) ;
F_497 ( V_2 ) ;
if ( F_27 ( V_2 ) ) {
V_2 -> V_568 . V_896 = 2048 ;
V_2 -> V_568 . V_897 = 2048 ;
} else if ( F_465 ( V_2 ) ) {
V_2 -> V_568 . V_896 = 4096 ;
V_2 -> V_568 . V_897 = 4096 ;
} else {
V_2 -> V_568 . V_896 = 8192 ;
V_2 -> V_568 . V_897 = 8192 ;
}
V_2 -> V_568 . V_898 = V_4 -> V_236 . V_899 ;
F_44 ( L_192 ,
V_4 -> V_298 , V_4 -> V_298 > 1 ? L_193 : L_194 ) ;
for ( V_155 = 0 ; V_155 < V_4 -> V_298 ; V_155 ++ ) {
F_462 ( V_2 , V_155 ) ;
V_230 = F_520 ( V_2 , V_155 ) ;
if ( V_230 )
F_44 ( L_195 , V_155 , V_230 ) ;
}
F_456 ( V_2 ) ;
F_458 ( V_2 ) ;
F_507 ( V_2 ) ;
F_474 ( V_2 ) ;
}
static void
F_521 ( struct V_423 * V_417 )
{
V_417 -> V_204 . V_419 = V_420 ;
V_417 -> V_204 . V_78 = NULL ;
V_417 -> V_78 -> V_413 = false ;
V_417 -> V_78 -> V_204 . V_37 = NULL ;
}
static void F_522 ( struct V_1 * V_2 )
{
struct V_423 * V_417 ;
struct V_416 * V_900 = NULL ;
struct V_710 V_714 ;
F_234 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_417 -> V_78 -> type == V_54 ) {
V_900 = & V_417 -> V_204 ;
break;
}
}
if ( ! V_900 )
return;
if ( F_378 ( V_900 , NULL , & V_714 ) )
F_382 ( V_900 , & V_714 ) ;
}
static bool
F_523 ( struct V_110 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_204 . V_2 -> V_5 ;
T_1 V_10 , V_12 ;
if ( V_4 -> V_298 == 1 )
return true ;
V_10 = F_74 ( ! V_37 -> V_153 ) ;
V_12 = F_4 ( V_10 ) ;
if ( ( V_12 & V_154 ) &&
( ! ! ( V_12 & V_157 ) == V_37 -> V_108 ) )
return false ;
return true ;
}
static void F_524 ( struct V_110 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_204 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_10 ;
V_10 = F_49 ( V_37 -> V_111 ) ;
F_11 ( V_10 , F_4 ( V_10 ) & ~ V_901 ) ;
if ( F_47 ( V_2 ) -> V_115 < 4 && ! F_523 ( V_37 ) ) {
struct V_423 * V_417 ;
bool V_153 ;
F_44 ( L_196 ,
V_37 -> V_204 . V_204 . V_26 ) ;
V_153 = V_37 -> V_153 ;
V_37 -> V_153 = ! V_153 ;
V_4 -> V_280 . V_415 ( & V_37 -> V_204 ) ;
V_37 -> V_153 = V_153 ;
F_234 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_417 -> V_78 -> V_204 . V_37 != & V_37 -> V_204 )
continue;
F_521 ( V_417 ) ;
}
F_2 ( V_37 -> V_207 ) ;
V_37 -> V_204 . V_124 = false ;
}
if ( V_4 -> V_150 & V_151 &&
V_37 -> V_108 == V_142 && ! V_37 -> V_207 ) {
F_522 ( V_2 ) ;
}
F_230 ( & V_37 -> V_204 ) ;
if ( V_37 -> V_207 != V_37 -> V_204 . V_124 ) {
struct V_77 * V_78 ;
F_44 ( L_197 ,
V_37 -> V_204 . V_204 . V_26 ,
V_37 -> V_204 . V_124 ? L_198 : L_199 ,
V_37 -> V_207 ? L_198 : L_199 ) ;
V_37 -> V_204 . V_124 = V_37 -> V_207 ;
F_2 ( V_37 -> V_207 ) ;
F_30 (dev, &crtc->base, encoder) {
F_2 ( V_78 -> V_413 ) ;
V_78 -> V_204 . V_37 = NULL ;
}
}
}
static void F_525 ( struct V_77 * V_78 )
{
struct V_423 * V_417 ;
struct V_1 * V_2 = V_78 -> V_204 . V_2 ;
bool V_902 = V_78 -> V_204 . V_37 &&
F_39 ( V_78 -> V_204 . V_37 ) -> V_207 ;
if ( V_78 -> V_413 && ! V_902 ) {
F_44 ( L_200 ,
V_78 -> V_204 . V_204 . V_26 ,
F_323 ( & V_78 -> V_204 ) ) ;
if ( V_78 -> V_204 . V_37 ) {
F_44 ( L_201 ,
V_78 -> V_204 . V_204 . V_26 ,
F_323 ( & V_78 -> V_204 ) ) ;
V_78 -> V_402 ( V_78 ) ;
}
F_234 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_417 -> V_78 != V_78 )
continue;
F_521 ( V_417 ) ;
}
}
}
static void F_526 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_883 ;
if ( F_3 ( V_2 ) )
V_883 = V_884 ;
else
V_883 = V_885 ;
if ( F_4 ( V_883 ) != V_890 ) {
F_44 ( L_202 ) ;
F_11 ( V_883 , V_890 ) ;
F_15 ( V_883 ) ;
}
}
void F_527 ( struct V_1 * V_2 ,
bool V_903 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_108 V_108 ;
T_1 V_191 ;
struct V_110 * V_37 ;
struct V_77 * V_78 ;
struct V_423 * V_417 ;
if ( F_63 ( V_2 ) ) {
V_191 = F_4 ( F_64 ( V_545 ) ) ;
if ( V_191 & V_134 ) {
switch ( V_191 & V_904 ) {
case V_905 :
case V_906 :
V_108 = V_142 ;
break;
case V_907 :
V_108 = V_149 ;
break;
case V_908 :
V_108 = V_316 ;
break;
}
V_37 = F_39 ( V_4 -> V_109 [ V_108 ] ) ;
V_37 -> V_111 = V_545 ;
F_44 ( L_203 ,
F_71 ( V_108 ) ) ;
}
}
F_528 (pipe) {
V_37 = F_39 ( V_4 -> V_109 [ V_108 ] ) ;
V_191 = F_4 ( F_49 ( V_37 -> V_111 ) ) ;
if ( V_191 & V_152 )
V_37 -> V_207 = true ;
else
V_37 -> V_207 = false ;
V_37 -> V_204 . V_124 = V_37 -> V_207 ;
F_44 ( L_204 ,
V_37 -> V_204 . V_204 . V_26 ,
V_37 -> V_207 ? L_198 : L_199 ) ;
}
if ( F_63 ( V_2 ) )
F_529 ( V_2 ) ;
F_234 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_108 = 0 ;
if ( V_78 -> V_424 ( V_78 , & V_108 ) ) {
V_78 -> V_204 . V_37 =
V_4 -> V_109 [ V_108 ] ;
} else {
V_78 -> V_204 . V_37 = NULL ;
}
V_78 -> V_413 = false ;
F_44 ( L_205 ,
V_78 -> V_204 . V_204 . V_26 ,
F_323 ( & V_78 -> V_204 ) ,
V_78 -> V_204 . V_37 ? L_198 : L_199 ,
V_108 ) ;
}
F_234 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_417 -> V_424 ( V_417 ) ) {
V_417 -> V_204 . V_419 = V_422 ;
V_417 -> V_78 -> V_413 = true ;
V_417 -> V_204 . V_78 = & V_417 -> V_78 -> V_204 ;
} else {
V_417 -> V_204 . V_419 = V_420 ;
V_417 -> V_204 . V_78 = NULL ;
}
F_44 ( L_206 ,
V_417 -> V_204 . V_204 . V_26 ,
F_243 ( & V_417 -> V_204 ) ,
V_417 -> V_204 . V_78 ? L_198 : L_199 ) ;
}
F_234 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_525 ( V_78 ) ;
}
F_528 (pipe) {
V_37 = F_39 ( V_4 -> V_109 [ V_108 ] ) ;
F_524 ( V_37 ) ;
}
if ( V_903 ) {
F_528 (pipe) {
V_37 = F_39 ( V_4 -> V_109 [ V_108 ] ) ;
F_381 ( & V_37 -> V_204 , & V_37 -> V_204 . V_351 ,
V_37 -> V_204 . V_240 , V_37 -> V_204 . V_241 , V_37 -> V_204 . V_247 ) ;
}
F_526 ( V_2 ) ;
} else {
F_437 ( V_2 ) ;
}
F_246 ( V_2 ) ;
F_530 ( V_2 ) ;
}
void F_531 ( struct V_1 * V_2 )
{
F_512 ( V_2 ) ;
F_532 ( V_2 ) ;
F_527 ( V_2 , false ) ;
}
void F_533 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_36 * V_37 ;
struct V_110 * V_110 ;
F_534 ( V_2 ) ;
F_151 ( & V_2 -> V_299 ) ;
F_535 () ;
F_234 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_37 -> V_247 )
continue;
V_110 = F_39 ( V_37 ) ;
F_144 ( V_37 ) ;
}
F_216 ( V_2 ) ;
F_536 ( V_2 ) ;
F_537 ( V_2 ) ;
if ( F_26 ( V_2 ) )
F_14 ( V_2 ) ;
F_152 ( & V_2 -> V_299 ) ;
F_538 ( V_2 ) ;
F_394 ( & V_4 -> V_909 ) ;
F_394 ( & V_4 -> V_910 . V_748 ) ;
F_539 () ;
F_540 ( V_2 ) ;
}
struct V_421 * F_541 ( struct V_416 * V_417 )
{
return & F_245 ( V_417 ) -> V_204 ;
}
void F_542 ( struct V_423 * V_417 ,
struct V_77 * V_78 )
{
V_417 -> V_78 = V_78 ;
F_543 ( & V_417 -> V_204 ,
& V_78 -> V_204 ) ;
}
int F_544 ( struct V_1 * V_2 , bool V_125 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_911 ;
F_255 ( V_4 -> V_912 , V_913 , & V_911 ) ;
if ( V_125 )
V_911 &= ~ V_914 ;
else
V_911 |= V_914 ;
F_545 ( V_4 -> V_912 , V_913 , V_911 ) ;
return 0 ;
}
struct V_915 *
F_546 ( struct V_1 * V_2 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_915 * error ;
enum V_107 V_111 ;
int V_155 ;
error = F_547 ( sizeof( * error ) , V_916 ) ;
if ( error == NULL )
return NULL ;
F_528 (i) {
V_111 = F_38 ( V_4 , V_155 ) ;
error -> V_917 [ V_155 ] . V_918 = F_4 ( F_345 ( V_155 ) ) ;
error -> V_917 [ V_155 ] . V_919 = F_4 ( F_351 ( V_155 ) ) ;
error -> V_917 [ V_155 ] . V_204 = F_4 ( F_346 ( V_155 ) ) ;
error -> V_153 [ V_155 ] . V_918 = F_4 ( F_74 ( V_155 ) ) ;
error -> V_153 [ V_155 ] . V_859 = F_4 ( F_137 ( V_155 ) ) ;
error -> V_153 [ V_155 ] . V_685 = F_4 ( F_289 ( V_155 ) ) ;
error -> V_153 [ V_155 ] . V_670 = F_4 ( F_290 ( V_155 ) ) ;
error -> V_153 [ V_155 ] . V_682 = F_4 ( F_120 ( V_155 ) ) ;
if ( F_47 ( V_2 ) -> V_115 >= 4 ) {
error -> V_153 [ V_155 ] . V_920 = F_4 ( F_119 ( V_155 ) ) ;
error -> V_153 [ V_155 ] . V_921 = F_4 ( F_139 ( V_155 ) ) ;
}
error -> V_108 [ V_155 ] . V_922 = F_4 ( F_49 ( V_111 ) ) ;
error -> V_108 [ V_155 ] . V_923 = F_4 ( F_285 ( V_155 ) ) ;
error -> V_108 [ V_155 ] . V_741 = F_4 ( F_184 ( V_111 ) ) ;
error -> V_108 [ V_155 ] . V_924 = F_4 ( F_186 ( V_111 ) ) ;
error -> V_108 [ V_155 ] . V_738 = F_4 ( F_188 ( V_111 ) ) ;
error -> V_108 [ V_155 ] . V_743 = F_4 ( F_190 ( V_111 ) ) ;
error -> V_108 [ V_155 ] . V_925 = F_4 ( F_192 ( V_111 ) ) ;
error -> V_108 [ V_155 ] . V_740 = F_4 ( F_194 ( V_111 ) ) ;
}
return error ;
}
void
F_548 ( struct V_926 * V_68 ,
struct V_1 * V_2 ,
struct V_915 * error )
{
T_7 * V_4 = V_2 -> V_5 ;
int V_155 ;
F_549 ( V_68 , L_207 , V_4 -> V_298 ) ;
F_528 (i) {
F_549 ( V_68 , L_208 , V_155 ) ;
F_549 ( V_68 , L_209 , error -> V_108 [ V_155 ] . V_922 ) ;
F_549 ( V_68 , L_210 , error -> V_108 [ V_155 ] . V_923 ) ;
F_549 ( V_68 , L_211 , error -> V_108 [ V_155 ] . V_741 ) ;
F_549 ( V_68 , L_212 , error -> V_108 [ V_155 ] . V_924 ) ;
F_549 ( V_68 , L_213 , error -> V_108 [ V_155 ] . V_738 ) ;
F_549 ( V_68 , L_214 , error -> V_108 [ V_155 ] . V_743 ) ;
F_549 ( V_68 , L_215 , error -> V_108 [ V_155 ] . V_925 ) ;
F_549 ( V_68 , L_216 , error -> V_108 [ V_155 ] . V_740 ) ;
F_549 ( V_68 , L_217 , V_155 ) ;
F_549 ( V_68 , L_218 , error -> V_153 [ V_155 ] . V_918 ) ;
F_549 ( V_68 , L_219 , error -> V_153 [ V_155 ] . V_859 ) ;
F_549 ( V_68 , L_220 , error -> V_153 [ V_155 ] . V_685 ) ;
F_549 ( V_68 , L_221 , error -> V_153 [ V_155 ] . V_670 ) ;
F_549 ( V_68 , L_222 , error -> V_153 [ V_155 ] . V_682 ) ;
if ( F_47 ( V_2 ) -> V_115 >= 4 ) {
F_549 ( V_68 , L_223 , error -> V_153 [ V_155 ] . V_920 ) ;
F_549 ( V_68 , L_224 , error -> V_153 [ V_155 ] . V_921 ) ;
}
F_549 ( V_68 , L_225 , V_155 ) ;
F_549 ( V_68 , L_218 , error -> V_917 [ V_155 ] . V_918 ) ;
F_549 ( V_68 , L_221 , error -> V_917 [ V_155 ] . V_919 ) ;
F_549 ( V_68 , L_226 , error -> V_917 [ V_155 ] . V_204 ) ;
}
}
