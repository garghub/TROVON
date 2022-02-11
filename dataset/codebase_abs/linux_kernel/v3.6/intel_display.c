static inline T_1
F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
struct V_3 * V_4 = V_2 -> V_5 ;
return ( F_3 ( V_6 ) & V_7 ) + 2 ;
} else
return 27 ;
}
T_1 F_4 ( struct V_3 * V_4 , int V_8 )
{
unsigned long V_9 ;
T_1 V_10 = 0 ;
F_5 ( & V_4 -> V_11 , V_9 ) ;
if ( F_6 ( ( F_3 ( V_12 ) & V_13 ) == 0 , 100 ) ) {
F_7 ( L_1 ) ;
goto V_14;
}
F_8 ( V_15 , V_8 ) ;
F_8 ( V_12 , V_16 | V_17 | V_18 |
V_19 ) ;
if ( F_6 ( ( F_3 ( V_12 ) & V_13 ) == 0 , 100 ) ) {
F_7 ( L_2 ) ;
goto V_14;
}
V_10 = F_3 ( V_20 ) ;
V_14:
F_9 ( & V_4 -> V_11 , V_9 ) ;
return V_10 ;
}
static void F_10 ( struct V_3 * V_4 , int V_8 ,
T_1 V_10 )
{
unsigned long V_9 ;
F_5 ( & V_4 -> V_11 , V_9 ) ;
if ( F_6 ( ( F_3 ( V_12 ) & V_13 ) == 0 , 100 ) ) {
F_7 ( L_1 ) ;
goto V_14;
}
F_8 ( V_20 , V_10 ) ;
F_8 ( V_15 , V_8 ) ;
F_8 ( V_12 , V_16 | V_21 | V_18 |
V_19 ) ;
if ( F_6 ( ( F_3 ( V_12 ) & V_13 ) == 0 , 100 ) )
F_7 ( L_3 ) ;
V_14:
F_9 ( & V_4 -> V_11 , V_9 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_8 ( V_22 , 0 ) ;
F_12 ( V_22 ) ;
F_8 ( V_22 , 1 ) ;
F_12 ( V_22 ) ;
}
static int F_13 ( const struct V_23 * V_24 )
{
F_14 ( L_4 , V_24 -> V_25 ) ;
return 1 ;
}
static bool F_15 ( struct V_3 * V_4 ,
unsigned int V_8 )
{
unsigned int V_10 ;
if ( V_26 > 0 )
return V_26 == 2 ;
if ( F_16 ( V_27 ) )
return true ;
if ( V_4 -> V_28 )
V_10 = V_4 -> V_28 ;
else {
V_10 = F_3 ( V_8 ) ;
if ( ! ( V_10 & ~ ( V_29 | V_30 ) ) )
V_10 = V_4 -> V_31 ;
V_4 -> V_28 = V_10 ;
}
return ( V_10 & V_32 ) == V_33 ;
}
static const T_2 * F_17 ( struct V_34 * V_35 ,
int V_36 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const T_2 * V_37 ;
if ( F_18 ( V_35 , V_38 ) ) {
if ( F_15 ( V_4 , V_39 ) ) {
if ( V_36 == 100000 )
V_37 = & V_40 ;
else
V_37 = & V_41 ;
} else {
if ( V_36 == 100000 )
V_37 = & V_42 ;
else
V_37 = & V_43 ;
}
} else if ( F_18 ( V_35 , V_44 ) ||
V_45 )
V_37 = & V_46 ;
else
V_37 = & V_47 ;
return V_37 ;
}
static const T_2 * F_19 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const T_2 * V_37 ;
if ( F_18 ( V_35 , V_38 ) ) {
if ( F_15 ( V_4 , V_48 ) )
V_37 = & V_49 ;
else
V_37 = & V_50 ;
} else if ( F_18 ( V_35 , V_51 ) ||
F_18 ( V_35 , V_52 ) ) {
V_37 = & V_53 ;
} else if ( F_18 ( V_35 , V_54 ) ) {
V_37 = & V_55 ;
} else if ( F_18 ( V_35 , V_44 ) ) {
V_37 = & V_56 ;
} else
V_37 = & V_57 ;
return V_37 ;
}
static const T_2 * F_20 ( struct V_34 * V_35 , int V_36 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
const T_2 * V_37 ;
if ( F_21 ( V_2 ) )
V_37 = F_17 ( V_35 , V_36 ) ;
else if ( F_22 ( V_2 ) ) {
V_37 = F_19 ( V_35 ) ;
} else if ( F_23 ( V_2 ) ) {
if ( F_18 ( V_35 , V_38 ) )
V_37 = & V_58 ;
else
V_37 = & V_59 ;
} else if ( F_24 ( V_2 ) ) {
if ( F_18 ( V_35 , V_52 ) )
V_37 = & V_60 ;
else if ( F_18 ( V_35 , V_51 ) )
V_37 = & V_61 ;
else
V_37 = & V_62 ;
} else if ( ! F_25 ( V_2 ) ) {
if ( F_18 ( V_35 , V_38 ) )
V_37 = & V_63 ;
else
V_37 = & V_57 ;
} else {
if ( F_18 ( V_35 , V_38 ) )
V_37 = & V_64 ;
else
V_37 = & V_65 ;
}
return V_37 ;
}
static void F_26 ( int V_36 , T_3 * clock )
{
clock -> V_66 = clock -> V_67 + 2 ;
clock -> V_68 = clock -> V_69 * clock -> V_70 ;
clock -> V_71 = V_36 * clock -> V_66 / clock -> V_72 ;
clock -> V_73 = clock -> V_71 / clock -> V_68 ;
}
static void F_27 ( struct V_1 * V_2 , int V_36 , T_3 * clock )
{
if ( F_23 ( V_2 ) ) {
F_26 ( V_36 , clock ) ;
return;
}
clock -> V_66 = 5 * ( clock -> V_74 + 2 ) + ( clock -> V_67 + 2 ) ;
clock -> V_68 = clock -> V_69 * clock -> V_70 ;
clock -> V_71 = V_36 * clock -> V_66 / ( clock -> V_72 + 2 ) ;
clock -> V_73 = clock -> V_71 / clock -> V_68 ;
}
bool F_18 ( struct V_34 * V_35 , int type )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_75 * V_76 ;
F_28 (dev, crtc, encoder)
if ( V_76 -> type == type )
return true ;
return false ;
}
static bool F_29 ( struct V_1 * V_2 ,
const T_2 * V_37 ,
const T_3 * clock )
{
if ( clock -> V_69 < V_37 -> V_69 . V_77 || V_37 -> V_69 . V_78 < clock -> V_69 )
F_30 ( L_5 ) ;
if ( clock -> V_68 < V_37 -> V_68 . V_77 || V_37 -> V_68 . V_78 < clock -> V_68 )
F_30 ( L_6 ) ;
if ( clock -> V_67 < V_37 -> V_67 . V_77 || V_37 -> V_67 . V_78 < clock -> V_67 )
F_30 ( L_7 ) ;
if ( clock -> V_74 < V_37 -> V_74 . V_77 || V_37 -> V_74 . V_78 < clock -> V_74 )
F_30 ( L_8 ) ;
if ( clock -> V_74 <= clock -> V_67 && ! F_23 ( V_2 ) )
F_30 ( L_9 ) ;
if ( clock -> V_66 < V_37 -> V_66 . V_77 || V_37 -> V_66 . V_78 < clock -> V_66 )
F_30 ( L_10 ) ;
if ( clock -> V_72 < V_37 -> V_72 . V_77 || V_37 -> V_72 . V_78 < clock -> V_72 )
F_30 ( L_11 ) ;
if ( clock -> V_71 < V_37 -> V_71 . V_77 || V_37 -> V_71 . V_78 < clock -> V_71 )
F_30 ( L_12 ) ;
if ( clock -> V_73 < V_37 -> V_73 . V_77 || V_37 -> V_73 . V_78 < clock -> V_73 )
F_30 ( L_13 ) ;
return true ;
}
static bool
F_31 ( const T_2 * V_37 , struct V_34 * V_35 ,
int V_79 , int V_36 , T_3 * V_80 ,
T_3 * V_81 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 clock ;
int V_82 = V_79 ;
if ( F_18 ( V_35 , V_38 ) &&
( F_3 ( V_48 ) ) != 0 ) {
if ( F_15 ( V_4 , V_48 ) )
clock . V_70 = V_37 -> V_70 . V_83 ;
else
clock . V_70 = V_37 -> V_70 . V_84 ;
} else {
if ( V_79 < V_37 -> V_70 . V_85 )
clock . V_70 = V_37 -> V_70 . V_84 ;
else
clock . V_70 = V_37 -> V_70 . V_83 ;
}
memset ( V_81 , 0 , sizeof( * V_81 ) ) ;
for ( clock . V_74 = V_37 -> V_74 . V_77 ; clock . V_74 <= V_37 -> V_74 . V_78 ;
clock . V_74 ++ ) {
for ( clock . V_67 = V_37 -> V_67 . V_77 ;
clock . V_67 <= V_37 -> V_67 . V_78 ; clock . V_67 ++ ) {
if ( clock . V_67 >= clock . V_74 && ! F_23 ( V_2 ) )
break;
for ( clock . V_72 = V_37 -> V_72 . V_77 ;
clock . V_72 <= V_37 -> V_72 . V_78 ; clock . V_72 ++ ) {
for ( clock . V_69 = V_37 -> V_69 . V_77 ;
clock . V_69 <= V_37 -> V_69 . V_78 ; clock . V_69 ++ ) {
int V_86 ;
F_27 ( V_2 , V_36 , & clock ) ;
if ( ! F_29 ( V_2 , V_37 ,
& clock ) )
continue;
if ( V_80 &&
clock . V_68 != V_80 -> V_68 )
continue;
V_86 = abs ( clock . V_73 - V_79 ) ;
if ( V_86 < V_82 ) {
* V_81 = clock ;
V_82 = V_86 ;
}
}
}
}
}
return ( V_82 != V_79 ) ;
}
static bool
F_32 ( const T_2 * V_37 , struct V_34 * V_35 ,
int V_79 , int V_36 , T_3 * V_80 ,
T_3 * V_81 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 clock ;
int V_87 ;
bool V_88 ;
int V_89 = ( V_79 >> 8 ) + ( V_79 >> 9 ) ;
V_88 = false ;
if ( F_18 ( V_35 , V_38 ) ) {
int V_90 ;
if ( F_21 ( V_2 ) )
V_90 = V_39 ;
else
V_90 = V_48 ;
if ( ( F_3 ( V_90 ) & V_32 ) ==
V_33 )
clock . V_70 = V_37 -> V_70 . V_83 ;
else
clock . V_70 = V_37 -> V_70 . V_84 ;
} else {
if ( V_79 < V_37 -> V_70 . V_85 )
clock . V_70 = V_37 -> V_70 . V_84 ;
else
clock . V_70 = V_37 -> V_70 . V_83 ;
}
memset ( V_81 , 0 , sizeof( * V_81 ) ) ;
V_87 = V_37 -> V_72 . V_78 ;
for ( clock . V_72 = V_37 -> V_72 . V_77 ; clock . V_72 <= V_87 ; clock . V_72 ++ ) {
for ( clock . V_74 = V_37 -> V_74 . V_78 ;
clock . V_74 >= V_37 -> V_74 . V_77 ; clock . V_74 -- ) {
for ( clock . V_67 = V_37 -> V_67 . V_78 ;
clock . V_67 >= V_37 -> V_67 . V_77 ; clock . V_67 -- ) {
for ( clock . V_69 = V_37 -> V_69 . V_78 ;
clock . V_69 >= V_37 -> V_69 . V_77 ; clock . V_69 -- ) {
int V_86 ;
F_27 ( V_2 , V_36 , & clock ) ;
if ( ! F_29 ( V_2 , V_37 ,
& clock ) )
continue;
if ( V_80 &&
clock . V_68 != V_80 -> V_68 )
continue;
V_86 = abs ( clock . V_73 - V_79 ) ;
if ( V_86 < V_89 ) {
* V_81 = clock ;
V_89 = V_86 ;
V_87 = clock . V_72 ;
V_88 = true ;
}
}
}
}
}
return V_88 ;
}
static bool
F_33 ( const T_2 * V_37 , struct V_34 * V_35 ,
int V_79 , int V_36 , T_3 * V_80 ,
T_3 * V_81 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
T_3 clock ;
if ( V_79 < 200000 ) {
clock . V_72 = 1 ;
clock . V_69 = 2 ;
clock . V_70 = 10 ;
clock . V_74 = 12 ;
clock . V_67 = 9 ;
} else {
clock . V_72 = 2 ;
clock . V_69 = 1 ;
clock . V_70 = 10 ;
clock . V_74 = 14 ;
clock . V_67 = 8 ;
}
F_27 ( V_2 , V_36 , & clock ) ;
memcpy ( V_81 , & clock , sizeof( T_3 ) ) ;
return true ;
}
static bool
F_34 ( const T_2 * V_37 , struct V_34 * V_35 ,
int V_79 , int V_36 , T_3 * V_80 ,
T_3 * V_81 )
{
T_3 clock ;
if ( V_79 < 200000 ) {
clock . V_69 = 2 ;
clock . V_70 = 10 ;
clock . V_72 = 2 ;
clock . V_74 = 23 ;
clock . V_67 = 8 ;
} else {
clock . V_69 = 1 ;
clock . V_70 = 10 ;
clock . V_72 = 1 ;
clock . V_74 = 14 ;
clock . V_67 = 2 ;
}
clock . V_66 = 5 * ( clock . V_74 + 2 ) + ( clock . V_67 + 2 ) ;
clock . V_68 = ( clock . V_69 * clock . V_70 ) ;
clock . V_73 = 96000 * clock . V_66 / ( clock . V_72 + 2 ) / clock . V_68 ;
clock . V_71 = 0 ;
memcpy ( V_81 , & clock , sizeof( T_3 ) ) ;
return true ;
}
static bool
F_35 ( const T_2 * V_37 , struct V_34 * V_35 ,
int V_79 , int V_36 , T_3 * V_80 ,
T_3 * V_81 )
{
T_1 V_69 , V_70 , V_74 , V_67 , V_71 , V_91 , V_92 , V_93 , V_94 , V_95 ;
T_1 V_66 , V_72 , V_96 ;
T_1 V_97 , V_98 , V_99 , V_68 ;
unsigned long V_100 , V_101 , V_102 ;
int V_103 , V_104 ;
V_104 = 0 ;
V_103 = V_79 * 1000 ;
V_100 = 1000000 ;
V_101 = V_102 = 0 ;
V_96 = V_103 / ( 2 * 100 ) ;
V_97 = 0 ;
V_98 = 19200 ;
V_99 = 1 ;
V_72 = V_68 = V_69 = V_70 = V_66 = V_74 = V_67 = V_71 = V_91 = 0 ;
V_92 = V_93 = V_94 = V_95 = 0 ;
for ( V_72 = V_37 -> V_72 . V_77 ; V_72 <= ( ( V_36 ) / V_98 ) ; V_72 ++ ) {
V_97 = V_36 / V_72 ;
for ( V_69 = V_37 -> V_69 . V_78 ; V_69 > V_37 -> V_69 . V_77 ; V_69 -- ) {
for ( V_70 = V_37 -> V_70 . V_83 + 1 ; V_70 > 0 ; V_70 -- ) {
if ( V_70 > 10 )
V_70 = V_70 - 1 ;
V_68 = V_69 * V_70 ;
for ( V_74 = V_37 -> V_74 . V_77 ; V_74 <= V_37 -> V_74 . V_78 ; V_74 ++ ) {
V_67 = ( ( ( 2 * ( V_96 * V_68 * V_72 / V_74 ) ) +
V_36 ) / ( 2 * V_36 ) ) ;
V_66 = V_74 * V_67 ;
V_71 = V_97 * V_66 ;
if ( V_71 >= V_37 -> V_71 . V_77 && V_71 < V_37 -> V_71 . V_78 ) {
V_101 = 1000000 * ( ( V_71 / V_68 ) - V_96 ) / V_96 ;
V_102 = ( V_101 > 0 ) ? V_101 : ( - V_101 ) ;
if ( V_102 < 100 && ( ( V_69 * V_70 ) > ( V_94 * V_95 ) ) ) {
V_100 = 0 ;
V_104 = 1 ;
}
if ( V_102 < V_100 - 10 ) {
V_100 = V_102 ;
V_104 = 1 ;
}
if ( V_104 ) {
V_91 = V_72 ;
V_92 = V_74 ;
V_93 = V_67 ;
V_94 = V_69 ;
V_95 = V_70 ;
V_104 = 0 ;
}
}
}
}
}
}
V_81 -> V_72 = V_91 ;
V_81 -> V_74 = V_92 ;
V_81 -> V_67 = V_93 ;
V_81 -> V_69 = V_94 ;
V_81 -> V_70 = V_95 ;
return true ;
}
static void F_36 ( struct V_1 * V_2 , int V_105 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_106 , V_107 = F_37 ( V_105 ) ;
V_106 = F_3 ( V_107 ) ;
if ( F_38 ( F_39 ( V_107 ) != V_106 , 50 ) )
F_40 ( L_14 ) ;
}
void F_41 ( struct V_1 * V_2 , int V_105 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_108 = F_42 ( V_105 ) ;
if ( F_43 ( V_2 ) -> V_109 >= 5 ) {
F_36 ( V_2 , V_105 ) ;
return;
}
F_8 ( V_108 ,
F_3 ( V_108 ) | V_110 ) ;
if ( F_38 ( F_3 ( V_108 ) &
V_110 ,
50 ) )
F_40 ( L_14 ) ;
}
void F_44 ( struct V_1 * V_2 , int V_105 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_43 ( V_2 ) -> V_109 >= 4 ) {
int V_8 = F_45 ( V_105 ) ;
if ( F_38 ( ( F_3 ( V_8 ) & V_111 ) == 0 ,
100 ) )
F_40 ( L_15 ) ;
} else {
T_1 V_112 , V_113 ;
int V_8 = F_46 ( V_105 ) ;
unsigned long V_114 = V_115 + F_47 ( 100 ) ;
if ( F_25 ( V_2 ) )
V_113 = V_116 ;
else
V_113 = V_117 ;
do {
V_112 = F_3 ( V_8 ) & V_113 ;
F_48 ( 5 ) ;
} while ( ( ( F_3 ( V_8 ) & V_113 ) != V_112 ) &&
F_49 ( V_114 , V_115 ) );
if ( F_49 ( V_115 , V_114 ) )
F_40 ( L_15 ) ;
}
}
static const char * F_50 ( bool V_118 )
{
return V_118 ? L_16 : L_17 ;
}
static void F_51 ( struct V_3 * V_4 ,
enum V_105 V_105 , bool V_119 )
{
int V_8 ;
T_1 V_10 ;
bool V_120 ;
V_8 = F_52 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
V_120 = ! ! ( V_10 & V_121 ) ;
F_53 ( V_120 != V_119 ,
L_18 ,
F_50 ( V_119 ) , F_50 ( V_120 ) ) ;
}
static void F_54 ( struct V_3 * V_4 ,
struct V_122 * V_123 ,
struct V_124 * V_35 ,
bool V_119 )
{
T_1 V_10 ;
bool V_120 ;
if ( F_55 ( V_4 -> V_2 ) ) {
F_56 ( L_19 ) ;
return;
}
if ( F_53 ( ! V_123 ,
L_20 , F_50 ( V_119 ) ) )
return;
V_10 = F_3 ( V_123 -> V_125 ) ;
V_120 = ! ! ( V_10 & V_121 ) ;
F_53 ( V_120 != V_119 ,
L_21 ,
V_123 -> V_125 , F_50 ( V_119 ) , F_50 ( V_120 ) , V_10 ) ;
if ( V_35 && F_57 ( V_4 -> V_2 ) ) {
T_1 V_126 ;
V_126 = F_3 ( V_127 ) ;
V_120 = V_123 -> V_125 == V_128 ;
if ( ! F_53 ( ( ( V_126 >> ( 4 * V_35 -> V_105 ) ) & 1 ) != V_120 ,
L_22 ,
V_120 , V_35 -> V_105 , V_126 ) ) {
V_120 = ! ! ( V_10 >> ( 4 * V_35 -> V_105 + 3 ) ) ;
F_53 ( V_120 != V_119 ,
L_23 ,
V_123 -> V_125 == V_128 ,
F_50 ( V_119 ) ,
V_35 -> V_105 ,
V_10 ) ;
}
}
}
static void F_58 ( struct V_3 * V_4 ,
enum V_105 V_105 , bool V_119 )
{
int V_8 ;
T_1 V_10 ;
bool V_120 ;
if ( F_59 ( V_4 -> V_2 ) ) {
V_8 = F_60 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
V_120 = ! ! ( V_10 & V_129 ) ;
} else {
V_8 = F_61 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
V_120 = ! ! ( V_10 & V_130 ) ;
}
F_53 ( V_120 != V_119 ,
L_24 ,
F_50 ( V_119 ) , F_50 ( V_120 ) ) ;
}
static void F_62 ( struct V_3 * V_4 ,
enum V_105 V_105 , bool V_119 )
{
int V_8 ;
T_1 V_10 ;
bool V_120 ;
if ( F_59 ( V_4 -> V_2 ) && V_105 > 0 ) {
F_7 ( L_25 ) ;
return;
} else {
V_8 = F_63 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
V_120 = ! ! ( V_10 & V_131 ) ;
}
F_53 ( V_120 != V_119 ,
L_26 ,
F_50 ( V_119 ) , F_50 ( V_120 ) ) ;
}
static void F_64 ( struct V_3 * V_4 ,
enum V_105 V_105 )
{
int V_8 ;
T_1 V_10 ;
if ( V_4 -> V_132 -> V_109 == 5 )
return;
if ( F_59 ( V_4 -> V_2 ) )
return;
V_8 = F_61 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
F_53 ( ! ( V_10 & V_133 ) , L_27 ) ;
}
static void F_65 ( struct V_3 * V_4 ,
enum V_105 V_105 )
{
int V_8 ;
T_1 V_10 ;
if ( F_59 ( V_4 -> V_2 ) && V_105 > 0 ) {
F_7 ( L_28 ) ;
return;
}
V_8 = F_63 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
F_53 ( ! ( V_10 & V_134 ) , L_29 ) ;
}
static void F_66 ( struct V_3 * V_4 ,
enum V_105 V_105 )
{
int V_135 , V_90 ;
T_1 V_10 ;
enum V_105 V_136 = V_137 ;
bool V_138 = true ;
if ( F_21 ( V_4 -> V_2 ) ) {
V_135 = V_139 ;
V_90 = V_39 ;
} else {
V_135 = V_140 ;
V_90 = V_48 ;
}
V_10 = F_3 ( V_135 ) ;
if ( ! ( V_10 & V_141 ) ||
( ( V_10 & V_142 ) == V_142 ) )
V_138 = false ;
if ( F_3 ( V_90 ) & V_143 )
V_136 = V_144 ;
F_53 ( V_136 == V_105 && V_138 ,
L_30 ,
F_67 ( V_105 ) ) ;
}
void F_68 ( struct V_3 * V_4 ,
enum V_105 V_105 , bool V_119 )
{
int V_8 ;
T_1 V_10 ;
bool V_120 ;
if ( V_105 == V_137 && V_4 -> V_145 & V_146 )
V_119 = true ;
V_8 = F_45 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
V_120 = ! ! ( V_10 & V_147 ) ;
F_53 ( V_120 != V_119 ,
L_31 ,
F_67 ( V_105 ) , F_50 ( V_119 ) , F_50 ( V_120 ) ) ;
}
static void F_69 ( struct V_3 * V_4 ,
enum V_148 V_148 , bool V_119 )
{
int V_8 ;
T_1 V_10 ;
bool V_120 ;
V_8 = F_70 ( V_148 ) ;
V_10 = F_3 ( V_8 ) ;
V_120 = ! ! ( V_10 & V_149 ) ;
F_53 ( V_120 != V_119 ,
L_32 ,
F_71 ( V_148 ) , F_50 ( V_119 ) , F_50 ( V_120 ) ) ;
}
static void F_72 ( struct V_3 * V_4 ,
enum V_105 V_105 )
{
int V_8 , V_150 ;
T_1 V_10 ;
int V_151 ;
if ( F_21 ( V_4 -> V_2 ) ) {
V_8 = F_70 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
F_53 ( ( V_10 & V_149 ) ,
L_33 ,
F_71 ( V_105 ) ) ;
return;
}
for ( V_150 = 0 ; V_150 < 2 ; V_150 ++ ) {
V_8 = F_70 ( V_150 ) ;
V_10 = F_3 ( V_8 ) ;
V_151 = ( V_10 & V_152 ) >>
V_153 ;
F_53 ( ( V_10 & V_149 ) && V_105 == V_151 ,
L_34 ,
F_71 ( V_150 ) , F_67 ( V_105 ) ) ;
}
}
static void F_73 ( struct V_3 * V_4 )
{
T_1 V_10 ;
bool V_118 ;
if ( F_55 ( V_4 -> V_2 ) ) {
F_56 ( L_35 ) ;
return;
}
V_10 = F_3 ( V_154 ) ;
V_118 = ! ! ( V_10 & ( V_155 | V_156 |
V_157 ) ) ;
F_53 ( ! V_118 , L_36 ) ;
}
static void F_74 ( struct V_3 * V_4 ,
enum V_105 V_105 )
{
int V_8 ;
T_1 V_10 ;
bool V_118 ;
V_8 = F_75 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
V_118 = ! ! ( V_10 & V_158 ) ;
F_53 ( V_118 ,
L_37 ,
F_67 ( V_105 ) ) ;
}
static bool F_76 ( struct V_3 * V_4 ,
enum V_105 V_105 , T_1 V_159 , T_1 V_10 )
{
if ( ( V_10 & V_160 ) == 0 )
return false ;
if ( F_57 ( V_4 -> V_2 ) ) {
T_1 V_161 = F_77 ( V_105 ) ;
T_1 V_162 = F_3 ( V_161 ) ;
if ( ( V_162 & V_163 ) != V_159 )
return false ;
} else {
if ( ( V_10 & V_164 ) != ( V_105 << 30 ) )
return false ;
}
return true ;
}
static bool F_78 ( struct V_3 * V_4 ,
enum V_105 V_105 , T_1 V_10 )
{
if ( ( V_10 & V_165 ) == 0 )
return false ;
if ( F_57 ( V_4 -> V_2 ) ) {
if ( ( V_10 & V_166 ) != F_79 ( V_105 ) )
return false ;
} else {
if ( ( V_10 & V_167 ) != F_80 ( V_105 ) )
return false ;
}
return true ;
}
static bool F_81 ( struct V_3 * V_4 ,
enum V_105 V_105 , T_1 V_10 )
{
if ( ( V_10 & V_168 ) == 0 )
return false ;
if ( F_57 ( V_4 -> V_2 ) ) {
if ( ( V_10 & V_166 ) != F_79 ( V_105 ) )
return false ;
} else {
if ( ( V_10 & V_29 ) != F_82 ( V_105 ) )
return false ;
}
return true ;
}
static bool F_83 ( struct V_3 * V_4 ,
enum V_105 V_105 , T_1 V_10 )
{
if ( ( V_10 & V_169 ) == 0 )
return false ;
if ( F_57 ( V_4 -> V_2 ) ) {
if ( ( V_10 & V_166 ) != F_79 ( V_105 ) )
return false ;
} else {
if ( ( V_10 & V_170 ) != F_84 ( V_105 ) )
return false ;
}
return true ;
}
static void F_85 ( struct V_3 * V_4 ,
enum V_105 V_105 , int V_8 , T_1 V_159 )
{
T_1 V_10 = F_3 ( V_8 ) ;
F_53 ( F_76 ( V_4 , V_105 , V_159 , V_10 ) ,
L_38 ,
V_8 , F_67 ( V_105 ) ) ;
F_53 ( F_86 ( V_4 -> V_2 ) && ( V_10 & V_160 ) == 0
&& ( V_10 & V_171 ) ,
L_39 ) ;
}
static void F_87 ( struct V_3 * V_4 ,
enum V_105 V_105 , int V_8 )
{
T_1 V_10 = F_3 ( V_8 ) ;
F_53 ( F_78 ( V_4 , V_105 , V_10 ) ,
L_40 ,
V_8 , F_67 ( V_105 ) ) ;
F_53 ( F_86 ( V_4 -> V_2 ) && ( V_10 & V_165 ) == 0
&& ( V_10 & V_172 ) ,
L_41 ) ;
}
static void F_88 ( struct V_3 * V_4 ,
enum V_105 V_105 )
{
int V_8 ;
T_1 V_10 ;
F_85 ( V_4 , V_105 , V_173 , V_174 ) ;
F_85 ( V_4 , V_105 , V_175 , V_176 ) ;
F_85 ( V_4 , V_105 , V_177 , V_178 ) ;
V_8 = V_179 ;
V_10 = F_3 ( V_8 ) ;
F_53 ( F_83 ( V_4 , V_105 , V_10 ) ,
L_42 ,
F_67 ( V_105 ) ) ;
V_8 = V_39 ;
V_10 = F_3 ( V_8 ) ;
F_53 ( F_81 ( V_4 , V_105 , V_10 ) ,
L_43 ,
F_67 ( V_105 ) ) ;
F_87 ( V_4 , V_105 , V_180 ) ;
F_87 ( V_4 , V_105 , V_181 ) ;
F_87 ( V_4 , V_105 , V_182 ) ;
}
static void F_89 ( struct V_3 * V_4 , enum V_105 V_105 )
{
int V_8 ;
T_1 V_10 ;
F_90 ( ! F_24 ( V_4 -> V_2 ) && V_4 -> V_132 -> V_109 >= 5 ) ;
if ( F_91 ( V_4 -> V_2 ) && ! F_92 ( V_4 -> V_2 ) )
F_66 ( V_4 , V_105 ) ;
V_8 = F_52 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
V_10 |= V_121 ;
F_8 ( V_8 , V_10 ) ;
F_12 ( V_8 ) ;
F_93 ( 150 ) ;
F_8 ( V_8 , V_10 ) ;
F_12 ( V_8 ) ;
F_93 ( 150 ) ;
F_8 ( V_8 , V_10 ) ;
F_12 ( V_8 ) ;
F_93 ( 150 ) ;
}
static void F_94 ( struct V_3 * V_4 , enum V_105 V_105 )
{
int V_8 ;
T_1 V_10 ;
if ( V_105 == V_137 && ( V_4 -> V_145 & V_146 ) )
return;
F_95 ( V_4 , V_105 ) ;
V_8 = F_52 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
V_10 &= ~ V_121 ;
F_8 ( V_8 , V_10 ) ;
F_12 ( V_8 ) ;
}
static void
F_96 ( struct V_3 * V_4 , T_4 V_8 , T_1 V_183 )
{
unsigned long V_9 ;
F_5 ( & V_4 -> V_11 , V_9 ) ;
if ( F_38 ( ( F_3 ( V_184 ) & V_185 ) == 0 ,
100 ) ) {
F_7 ( L_44 ) ;
goto V_14;
}
F_8 ( V_186 ,
( V_8 << 16 ) ) ;
F_8 ( V_187 ,
V_183 ) ;
F_8 ( V_184 ,
V_185 |
V_188 ) ;
if ( F_38 ( ( F_3 ( V_184 ) & ( V_185 | V_189 ) ) == 0 ,
100 ) ) {
F_7 ( L_45 ) ;
goto V_14;
}
V_14:
F_9 ( & V_4 -> V_11 , V_9 ) ;
}
static T_1
F_97 ( struct V_3 * V_4 , T_4 V_8 )
{
unsigned long V_9 ;
T_1 V_183 = 0 ;
F_5 ( & V_4 -> V_11 , V_9 ) ;
if ( F_38 ( ( F_3 ( V_184 ) & V_185 ) == 0 ,
100 ) ) {
F_7 ( L_44 ) ;
goto V_14;
}
F_8 ( V_186 ,
( V_8 << 16 ) ) ;
F_8 ( V_184 ,
V_185 |
V_190 ) ;
if ( F_38 ( ( F_3 ( V_184 ) & ( V_185 | V_189 ) ) == 0 ,
100 ) ) {
F_7 ( L_46 ) ;
goto V_14;
}
V_183 = F_3 ( V_187 ) ;
V_14:
F_9 ( & V_4 -> V_11 , V_9 ) ;
return V_183 ;
}
static void F_98 ( struct V_124 * V_124 )
{
struct V_3 * V_4 = V_124 -> V_191 . V_2 -> V_5 ;
struct V_122 * V_123 ;
int V_8 ;
T_1 V_10 ;
F_90 ( V_4 -> V_132 -> V_109 < 5 ) ;
V_123 = V_124 -> V_192 ;
if ( V_123 == NULL )
return;
if ( F_99 ( V_123 -> V_193 == 0 ) )
return;
F_40 ( L_47 ,
V_123 -> V_125 , V_123 -> V_194 , V_123 -> V_195 ,
V_124 -> V_191 . V_191 . V_24 ) ;
F_73 ( V_4 ) ;
if ( V_123 -> V_194 ++ && V_123 -> V_195 ) {
F_100 ( V_4 , V_123 , NULL ) ;
return;
}
F_40 ( L_48 , V_123 -> V_125 ) ;
V_8 = V_123 -> V_125 ;
V_10 = F_3 ( V_8 ) ;
V_10 |= V_121 ;
F_8 ( V_8 , V_10 ) ;
F_12 ( V_8 ) ;
F_93 ( 200 ) ;
V_123 -> V_195 = true ;
}
static void F_101 ( struct V_124 * V_124 )
{
struct V_3 * V_4 = V_124 -> V_191 . V_2 -> V_5 ;
struct V_122 * V_123 = V_124 -> V_192 ;
int V_8 ;
T_1 V_10 ;
F_90 ( V_4 -> V_132 -> V_109 < 5 ) ;
if ( V_123 == NULL )
return;
if ( F_99 ( V_123 -> V_193 == 0 ) )
return;
F_40 ( L_49 ,
V_123 -> V_125 , V_123 -> V_194 , V_123 -> V_195 ,
V_124 -> V_191 . V_191 . V_24 ) ;
if ( F_99 ( V_123 -> V_194 == 0 ) ) {
F_102 ( V_4 , V_123 , NULL ) ;
return;
}
if ( -- V_123 -> V_194 ) {
F_100 ( V_4 , V_123 , NULL ) ;
return;
}
F_40 ( L_50 , V_123 -> V_125 ) ;
F_74 ( V_4 , V_124 -> V_105 ) ;
V_8 = V_123 -> V_125 ;
V_10 = F_3 ( V_8 ) ;
V_10 &= ~ V_121 ;
F_8 ( V_8 , V_10 ) ;
F_12 ( V_8 ) ;
F_93 ( 200 ) ;
V_123 -> V_195 = false ;
}
static void F_103 ( struct V_3 * V_4 ,
enum V_105 V_105 )
{
int V_8 ;
T_1 V_10 , V_196 ;
struct V_34 * V_35 = V_4 -> V_197 [ V_105 ] ;
F_90 ( V_4 -> V_132 -> V_109 < 5 ) ;
F_100 ( V_4 ,
F_104 ( V_35 ) -> V_192 ,
F_104 ( V_35 ) ) ;
F_105 ( V_4 , V_105 ) ;
F_106 ( V_4 , V_105 ) ;
if ( F_59 ( V_4 -> V_2 ) && V_105 > 0 ) {
F_7 ( L_51 ) ;
return;
}
V_8 = F_75 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
V_196 = F_3 ( F_45 ( V_105 ) ) ;
if ( F_86 ( V_4 -> V_2 ) ) {
V_10 &= ~ V_198 ;
V_10 |= V_196 & V_198 ;
}
V_10 &= ~ V_199 ;
if ( ( V_196 & V_200 ) == V_201 )
if ( F_86 ( V_4 -> V_2 ) &&
F_18 ( V_35 , V_54 ) )
V_10 |= V_202 ;
else
V_10 |= V_203 ;
else
V_10 |= V_204 ;
F_8 ( V_8 , V_10 | V_158 ) ;
if ( F_38 ( F_3 ( V_8 ) & V_205 , 100 ) )
F_7 ( L_52 , V_105 ) ;
}
static void F_107 ( struct V_3 * V_4 ,
enum V_105 V_105 )
{
int V_8 ;
T_1 V_10 ;
F_108 ( V_4 , V_105 ) ;
F_109 ( V_4 , V_105 ) ;
F_88 ( V_4 , V_105 ) ;
V_8 = F_75 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
V_10 &= ~ V_158 ;
F_8 ( V_8 , V_10 ) ;
if ( F_38 ( ( F_3 ( V_8 ) & V_205 ) == 0 , 50 ) )
F_7 ( L_53 , V_105 ) ;
}
static void F_110 ( struct V_3 * V_4 , enum V_105 V_105 ,
bool V_206 )
{
int V_8 ;
T_1 V_10 ;
if ( ! F_21 ( V_4 -> V_2 ) )
F_111 ( V_4 , V_105 ) ;
else {
if ( V_206 ) {
F_65 ( V_4 , V_105 ) ;
F_64 ( V_4 , V_105 ) ;
}
}
V_8 = F_45 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
if ( V_10 & V_147 )
return;
F_8 ( V_8 , V_10 | V_147 ) ;
F_41 ( V_4 -> V_2 , V_105 ) ;
}
static void F_112 ( struct V_3 * V_4 ,
enum V_105 V_105 )
{
int V_8 ;
T_1 V_10 ;
F_72 ( V_4 , V_105 ) ;
if ( V_105 == V_137 && ( V_4 -> V_145 & V_146 ) )
return;
V_8 = F_45 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
if ( ( V_10 & V_147 ) == 0 )
return;
F_8 ( V_8 , V_10 & ~ V_147 ) ;
F_44 ( V_4 -> V_2 , V_105 ) ;
}
void F_113 ( struct V_3 * V_4 ,
enum V_148 V_148 )
{
F_8 ( F_114 ( V_148 ) , F_3 ( F_114 ( V_148 ) ) ) ;
F_8 ( F_115 ( V_148 ) , F_3 ( F_115 ( V_148 ) ) ) ;
}
static void F_116 ( struct V_3 * V_4 ,
enum V_148 V_148 , enum V_105 V_105 )
{
int V_8 ;
T_1 V_10 ;
F_117 ( V_4 , V_105 ) ;
V_8 = F_70 ( V_148 ) ;
V_10 = F_3 ( V_8 ) ;
if ( V_10 & V_149 )
return;
F_8 ( V_8 , V_10 | V_149 ) ;
F_113 ( V_4 , V_148 ) ;
F_41 ( V_4 -> V_2 , V_105 ) ;
}
static void F_118 ( struct V_3 * V_4 ,
enum V_148 V_148 , enum V_105 V_105 )
{
int V_8 ;
T_1 V_10 ;
V_8 = F_70 ( V_148 ) ;
V_10 = F_3 ( V_8 ) ;
if ( ( V_10 & V_149 ) == 0 )
return;
F_8 ( V_8 , V_10 & ~ V_149 ) ;
F_113 ( V_4 , V_148 ) ;
F_41 ( V_4 -> V_2 , V_105 ) ;
}
static void F_119 ( struct V_3 * V_4 ,
enum V_105 V_105 , int V_8 , T_1 V_159 )
{
T_1 V_10 = F_3 ( V_8 ) ;
if ( F_76 ( V_4 , V_105 , V_159 , V_10 ) ) {
F_40 ( L_54 , V_8 , V_105 ) ;
F_8 ( V_8 , V_10 & ~ V_160 ) ;
}
}
static void F_120 ( struct V_3 * V_4 ,
enum V_105 V_105 , int V_8 )
{
T_1 V_10 = F_3 ( V_8 ) ;
if ( F_78 ( V_4 , V_105 , V_10 ) ) {
F_40 ( L_55 ,
V_8 , V_105 ) ;
F_8 ( V_8 , V_10 & ~ V_165 ) ;
}
}
static void F_121 ( struct V_3 * V_4 ,
enum V_105 V_105 )
{
T_1 V_8 , V_10 ;
V_10 = F_3 ( V_139 ) ;
F_8 ( V_139 , V_10 | V_142 ) ;
F_119 ( V_4 , V_105 , V_173 , V_174 ) ;
F_119 ( V_4 , V_105 , V_175 , V_176 ) ;
F_119 ( V_4 , V_105 , V_177 , V_178 ) ;
V_8 = V_179 ;
V_10 = F_3 ( V_8 ) ;
if ( F_83 ( V_4 , V_105 , V_10 ) )
F_8 ( V_8 , V_10 & ~ V_169 ) ;
V_8 = V_39 ;
V_10 = F_3 ( V_8 ) ;
if ( F_81 ( V_4 , V_105 , V_10 ) ) {
F_40 ( L_56 , V_105 , V_10 ) ;
F_8 ( V_8 , V_10 & ~ V_168 ) ;
F_12 ( V_8 ) ;
F_93 ( 100 ) ;
}
F_120 ( V_4 , V_105 , V_180 ) ;
F_120 ( V_4 , V_105 , V_181 ) ;
F_120 ( V_4 , V_105 , V_182 ) ;
}
int
F_122 ( struct V_1 * V_2 ,
struct V_207 * V_208 ,
struct V_209 * V_210 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_211 ;
int V_212 ;
switch ( V_208 -> V_213 ) {
case V_214 :
if ( F_123 ( V_2 ) || F_124 ( V_2 ) )
V_211 = 128 * 1024 ;
else if ( F_43 ( V_2 ) -> V_109 >= 4 )
V_211 = 4 * 1024 ;
else
V_211 = 64 * 1024 ;
break;
case V_215 :
V_211 = 0 ;
break;
case V_216 :
F_7 ( L_57 ) ;
return - V_217 ;
default:
F_125 () ;
}
V_4 -> V_218 . V_219 = false ;
V_212 = F_126 ( V_208 , V_211 , V_210 ) ;
if ( V_212 )
goto V_220;
V_212 = F_127 ( V_208 ) ;
if ( V_212 )
goto V_221;
F_128 ( V_208 ) ;
V_4 -> V_218 . V_219 = true ;
return 0 ;
V_221:
F_129 ( V_208 ) ;
V_220:
V_4 -> V_218 . V_219 = true ;
return V_212 ;
}
void F_130 ( struct V_207 * V_208 )
{
F_131 ( V_208 ) ;
F_129 ( V_208 ) ;
}
static unsigned long F_132 ( int * V_222 , int * V_223 ,
unsigned int V_224 ,
unsigned int V_225 )
{
int V_226 , V_227 ;
V_226 = * V_223 / 8 ;
* V_223 %= 8 ;
V_227 = * V_222 / ( 512 / V_224 ) ;
* V_222 %= 512 / V_224 ;
return V_226 * V_225 * 8 + V_227 * 4096 ;
}
static int F_133 ( struct V_34 * V_35 , struct V_228 * V_229 ,
int V_222 , int V_223 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_230 * V_231 ;
struct V_207 * V_208 ;
int V_148 = V_124 -> V_148 ;
unsigned long V_232 ;
T_1 V_233 ;
T_1 V_8 ;
switch ( V_148 ) {
case 0 :
case 1 :
break;
default:
F_7 ( L_58 , V_148 ) ;
return - V_217 ;
}
V_231 = F_134 ( V_229 ) ;
V_208 = V_231 -> V_208 ;
V_8 = F_70 ( V_148 ) ;
V_233 = F_3 ( V_8 ) ;
V_233 &= ~ V_234 ;
switch ( V_229 -> V_235 ) {
case 8 :
V_233 |= V_236 ;
break;
case 16 :
if ( V_229 -> V_237 == 15 )
V_233 |= V_238 ;
else
V_233 |= V_239 ;
break;
case 24 :
case 32 :
V_233 |= V_240 ;
break;
default:
F_7 ( L_59 , V_229 -> V_235 ) ;
return - V_217 ;
}
if ( F_43 ( V_2 ) -> V_109 >= 4 ) {
if ( V_208 -> V_213 != V_214 )
V_233 |= V_241 ;
else
V_233 &= ~ V_241 ;
}
F_8 ( V_8 , V_233 ) ;
V_232 = V_223 * V_229 -> V_242 [ 0 ] + V_222 * ( V_229 -> V_235 / 8 ) ;
if ( F_43 ( V_2 ) -> V_109 >= 4 ) {
V_124 -> V_243 =
F_132 ( & V_222 , & V_223 ,
V_229 -> V_235 / 8 ,
V_229 -> V_242 [ 0 ] ) ;
V_232 -= V_124 -> V_243 ;
} else {
V_124 -> V_243 = V_232 ;
}
F_40 ( L_60 ,
V_208 -> V_244 , V_232 , V_222 , V_223 , V_229 -> V_242 [ 0 ] ) ;
F_8 ( F_135 ( V_148 ) , V_229 -> V_242 [ 0 ] ) ;
if ( F_43 ( V_2 ) -> V_109 >= 4 ) {
F_136 ( F_115 ( V_148 ) ,
V_208 -> V_244 + V_124 -> V_243 ) ;
F_8 ( F_137 ( V_148 ) , ( V_223 << 16 ) | V_222 ) ;
F_8 ( F_138 ( V_148 ) , V_232 ) ;
} else
F_8 ( F_114 ( V_148 ) , V_208 -> V_244 + V_232 ) ;
F_12 ( V_8 ) ;
return 0 ;
}
static int F_139 ( struct V_34 * V_35 ,
struct V_228 * V_229 , int V_222 , int V_223 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_230 * V_231 ;
struct V_207 * V_208 ;
int V_148 = V_124 -> V_148 ;
unsigned long V_232 ;
T_1 V_233 ;
T_1 V_8 ;
switch ( V_148 ) {
case 0 :
case 1 :
case 2 :
break;
default:
F_7 ( L_58 , V_148 ) ;
return - V_217 ;
}
V_231 = F_134 ( V_229 ) ;
V_208 = V_231 -> V_208 ;
V_8 = F_70 ( V_148 ) ;
V_233 = F_3 ( V_8 ) ;
V_233 &= ~ V_234 ;
switch ( V_229 -> V_235 ) {
case 8 :
V_233 |= V_236 ;
break;
case 16 :
if ( V_229 -> V_237 != 16 )
return - V_217 ;
V_233 |= V_239 ;
break;
case 24 :
case 32 :
if ( V_229 -> V_237 == 24 )
V_233 |= V_240 ;
else if ( V_229 -> V_237 == 30 )
V_233 |= V_245 ;
else
return - V_217 ;
break;
default:
F_7 ( L_59 , V_229 -> V_235 ) ;
return - V_217 ;
}
if ( V_208 -> V_213 != V_214 )
V_233 |= V_241 ;
else
V_233 &= ~ V_241 ;
V_233 |= V_246 ;
F_8 ( V_8 , V_233 ) ;
V_232 = V_223 * V_229 -> V_242 [ 0 ] + V_222 * ( V_229 -> V_235 / 8 ) ;
V_124 -> V_243 =
F_132 ( & V_222 , & V_223 ,
V_229 -> V_235 / 8 ,
V_229 -> V_242 [ 0 ] ) ;
V_232 -= V_124 -> V_243 ;
F_40 ( L_60 ,
V_208 -> V_244 , V_232 , V_222 , V_223 , V_229 -> V_242 [ 0 ] ) ;
F_8 ( F_135 ( V_148 ) , V_229 -> V_242 [ 0 ] ) ;
F_136 ( F_115 ( V_148 ) ,
V_208 -> V_244 + V_124 -> V_243 ) ;
F_8 ( F_137 ( V_148 ) , ( V_223 << 16 ) | V_222 ) ;
F_8 ( F_138 ( V_148 ) , V_232 ) ;
F_12 ( V_8 ) ;
return 0 ;
}
static int
F_140 ( struct V_34 * V_35 , struct V_228 * V_229 ,
int V_222 , int V_223 , enum V_247 V_119 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_248 . V_249 )
V_4 -> V_248 . V_249 ( V_2 ) ;
F_141 ( V_35 ) ;
return V_4 -> V_248 . V_250 ( V_35 , V_229 , V_222 , V_223 ) ;
}
static int
F_142 ( struct V_228 * V_251 )
{
struct V_207 * V_208 = F_134 ( V_251 ) -> V_208 ;
struct V_3 * V_4 = V_208 -> V_191 . V_2 -> V_5 ;
bool V_252 = V_4 -> V_218 . V_219 ;
int V_212 ;
F_143 ( V_4 -> V_253 ,
F_144 ( & V_4 -> V_218 . V_254 ) ||
F_144 ( & V_208 -> V_255 ) == 0 ) ;
V_4 -> V_218 . V_219 = false ;
V_212 = F_145 ( V_208 ) ;
V_4 -> V_218 . V_219 = V_252 ;
return V_212 ;
}
static int
F_146 ( struct V_34 * V_35 , int V_222 , int V_223 ,
struct V_228 * V_251 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_256 * V_257 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_212 ;
if ( ! V_35 -> V_229 ) {
F_7 ( L_61 ) ;
return 0 ;
}
if( V_124 -> V_148 > V_4 -> V_258 ) {
F_7 ( L_62 ,
V_124 -> V_148 ,
V_4 -> V_258 ) ;
return - V_217 ;
}
F_147 ( & V_2 -> V_259 ) ;
V_212 = F_122 ( V_2 ,
F_134 ( V_35 -> V_229 ) -> V_208 ,
NULL ) ;
if ( V_212 != 0 ) {
F_148 ( & V_2 -> V_259 ) ;
F_7 ( L_63 ) ;
return V_212 ;
}
if ( V_251 )
F_142 ( V_251 ) ;
V_212 = V_4 -> V_248 . V_250 ( V_35 , V_35 -> V_229 , V_222 , V_223 ) ;
if ( V_212 ) {
F_130 ( F_134 ( V_35 -> V_229 ) -> V_208 ) ;
F_148 ( & V_2 -> V_259 ) ;
F_7 ( L_64 ) ;
return V_212 ;
}
if ( V_251 ) {
F_41 ( V_2 , V_124 -> V_105 ) ;
F_130 ( F_134 ( V_251 ) -> V_208 ) ;
}
F_149 ( V_2 ) ;
F_148 ( & V_2 -> V_259 ) ;
if ( ! V_2 -> V_260 -> V_261 )
return 0 ;
V_257 = V_2 -> V_260 -> V_261 -> V_262 ;
if ( ! V_257 -> V_263 )
return 0 ;
if ( V_124 -> V_105 ) {
V_257 -> V_263 -> V_264 = V_222 ;
V_257 -> V_263 -> V_265 = V_223 ;
} else {
V_257 -> V_263 -> V_266 = V_222 ;
V_257 -> V_263 -> V_267 = V_223 ;
}
return 0 ;
}
static void F_150 ( struct V_34 * V_35 , int clock )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_268 ;
F_40 ( L_65 , clock ) ;
V_268 = F_3 ( V_269 ) ;
V_268 &= ~ V_270 ;
if ( clock < 200000 ) {
T_1 V_271 ;
V_268 |= V_272 ;
V_271 = F_3 ( 0x4600c ) ;
V_271 &= 0xffff0000 ;
F_8 ( 0x4600c , V_271 | 0x8124 ) ;
V_271 = F_3 ( 0x46010 ) ;
F_8 ( 0x46010 , V_271 | 1 ) ;
V_271 = F_3 ( 0x46034 ) ;
F_8 ( 0x46034 , V_271 | ( 1 << 24 ) ) ;
} else {
V_268 |= V_273 ;
}
F_8 ( V_269 , V_268 ) ;
F_12 ( V_269 ) ;
F_93 ( 500 ) ;
}
static void F_151 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_8 , V_271 ;
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
if ( F_152 ( V_2 ) ) {
V_271 &= ~ V_274 ;
V_271 |= V_274 | V_275 ;
} else {
V_271 &= ~ V_276 ;
V_271 |= V_276 | V_275 ;
}
F_8 ( V_8 , V_271 ) ;
V_8 = F_63 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
if ( F_57 ( V_2 ) ) {
V_271 &= ~ V_277 ;
V_271 |= V_278 ;
} else {
V_271 &= ~ V_276 ;
V_271 |= V_276 ;
}
F_8 ( V_8 , V_271 | V_279 ) ;
F_12 ( V_8 ) ;
F_93 ( 1000 ) ;
if ( F_152 ( V_2 ) )
F_8 ( V_8 , F_3 ( V_8 ) | V_280 |
V_281 ) ;
}
static void F_153 ( struct V_1 * V_2 , int V_105 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_9 = F_3 ( V_282 ) ;
V_9 |= F_154 ( V_105 ) ;
F_8 ( V_282 , V_9 ) ;
V_9 |= F_155 ( V_105 ) ;
F_8 ( V_282 , V_9 ) ;
F_12 ( V_282 ) ;
}
static void F_156 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_148 = V_124 -> V_148 ;
T_1 V_8 , V_271 , V_283 ;
F_117 ( V_4 , V_105 ) ;
F_157 ( V_4 , V_148 ) ;
V_8 = F_158 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_284 ;
V_271 &= ~ V_285 ;
F_8 ( V_8 , V_271 ) ;
F_3 ( V_8 ) ;
F_93 ( 150 ) ;
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ ( 7 << 19 ) ;
V_271 |= ( V_124 -> V_286 - 1 ) << 19 ;
V_271 &= ~ V_276 ;
V_271 |= V_287 ;
F_8 ( V_8 , V_271 | V_130 ) ;
V_8 = F_63 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_276 ;
V_271 |= V_287 ;
F_8 ( V_8 , V_271 | V_131 ) ;
F_12 ( V_8 ) ;
F_93 ( 150 ) ;
if ( F_86 ( V_2 ) ) {
F_8 ( F_159 ( V_105 ) , V_288 ) ;
F_8 ( F_159 ( V_105 ) , V_288 |
V_289 ) ;
}
V_8 = F_160 ( V_105 ) ;
for ( V_283 = 0 ; V_283 < 5 ; V_283 ++ ) {
V_271 = F_3 ( V_8 ) ;
F_40 ( L_66 , V_271 ) ;
if ( ( V_271 & V_285 ) ) {
F_40 ( L_67 ) ;
F_8 ( V_8 , V_271 | V_285 ) ;
break;
}
}
if ( V_283 == 5 )
F_7 ( L_68 ) ;
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_276 ;
V_271 |= V_290 ;
F_8 ( V_8 , V_271 ) ;
V_8 = F_63 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_276 ;
V_271 |= V_290 ;
F_8 ( V_8 , V_271 ) ;
F_12 ( V_8 ) ;
F_93 ( 150 ) ;
V_8 = F_160 ( V_105 ) ;
for ( V_283 = 0 ; V_283 < 5 ; V_283 ++ ) {
V_271 = F_3 ( V_8 ) ;
F_40 ( L_66 , V_271 ) ;
if ( V_271 & V_284 ) {
F_8 ( V_8 , V_271 | V_284 ) ;
F_40 ( L_69 ) ;
break;
}
}
if ( V_283 == 5 )
F_7 ( L_70 ) ;
F_40 ( L_71 ) ;
}
static void F_161 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_8 , V_271 , V_150 , V_291 ;
V_8 = F_158 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_284 ;
V_271 &= ~ V_285 ;
F_8 ( V_8 , V_271 ) ;
F_12 ( V_8 ) ;
F_93 ( 150 ) ;
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ ( 7 << 19 ) ;
V_271 |= ( V_124 -> V_286 - 1 ) << 19 ;
V_271 &= ~ V_276 ;
V_271 |= V_287 ;
V_271 &= ~ V_292 ;
V_271 |= V_293 ;
F_8 ( V_8 , V_271 | V_130 ) ;
V_8 = F_63 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
if ( F_57 ( V_2 ) ) {
V_271 &= ~ V_277 ;
V_271 |= V_294 ;
} else {
V_271 &= ~ V_276 ;
V_271 |= V_287 ;
}
F_8 ( V_8 , V_271 | V_131 ) ;
F_12 ( V_8 ) ;
F_93 ( 150 ) ;
if ( F_57 ( V_2 ) )
F_153 ( V_2 , V_105 ) ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_292 ;
V_271 |= V_295 [ V_150 ] ;
F_8 ( V_8 , V_271 ) ;
F_12 ( V_8 ) ;
F_93 ( 500 ) ;
for ( V_291 = 0 ; V_291 < 5 ; V_291 ++ ) {
V_8 = F_160 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
F_40 ( L_66 , V_271 ) ;
if ( V_271 & V_285 ) {
F_8 ( V_8 , V_271 | V_285 ) ;
F_40 ( L_67 ) ;
break;
}
F_93 ( 50 ) ;
}
if ( V_291 < 5 )
break;
}
if ( V_150 == 4 )
F_7 ( L_68 ) ;
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_276 ;
V_271 |= V_290 ;
if ( F_162 ( V_2 ) ) {
V_271 &= ~ V_292 ;
V_271 |= V_293 ;
}
F_8 ( V_8 , V_271 ) ;
V_8 = F_63 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
if ( F_57 ( V_2 ) ) {
V_271 &= ~ V_277 ;
V_271 |= V_296 ;
} else {
V_271 &= ~ V_276 ;
V_271 |= V_290 ;
}
F_8 ( V_8 , V_271 ) ;
F_12 ( V_8 ) ;
F_93 ( 150 ) ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_292 ;
V_271 |= V_295 [ V_150 ] ;
F_8 ( V_8 , V_271 ) ;
F_12 ( V_8 ) ;
F_93 ( 500 ) ;
for ( V_291 = 0 ; V_291 < 5 ; V_291 ++ ) {
V_8 = F_160 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
F_40 ( L_66 , V_271 ) ;
if ( V_271 & V_284 ) {
F_8 ( V_8 , V_271 | V_284 ) ;
F_40 ( L_69 ) ;
break;
}
F_93 ( 50 ) ;
}
if ( V_291 < 5 )
break;
}
if ( V_150 == 4 )
F_7 ( L_70 ) ;
F_40 ( L_72 ) ;
}
static void F_163 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_8 , V_271 , V_150 ;
V_8 = F_158 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_284 ;
V_271 &= ~ V_285 ;
F_8 ( V_8 , V_271 ) ;
F_12 ( V_8 ) ;
F_93 ( 150 ) ;
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ ( 7 << 19 ) ;
V_271 |= ( V_124 -> V_286 - 1 ) << 19 ;
V_271 &= ~ ( V_297 | V_274 ) ;
V_271 |= V_298 ;
V_271 &= ~ V_292 ;
V_271 |= V_293 ;
V_271 |= V_299 ;
F_8 ( V_8 , V_271 | V_130 ) ;
V_8 = F_63 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_297 ;
V_271 &= ~ V_277 ;
V_271 |= V_294 ;
V_271 |= V_299 ;
F_8 ( V_8 , V_271 | V_131 ) ;
F_12 ( V_8 ) ;
F_93 ( 150 ) ;
if ( F_57 ( V_2 ) )
F_153 ( V_2 , V_105 ) ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_292 ;
V_271 |= V_295 [ V_150 ] ;
F_8 ( V_8 , V_271 ) ;
F_12 ( V_8 ) ;
F_93 ( 500 ) ;
V_8 = F_160 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
F_40 ( L_66 , V_271 ) ;
if ( V_271 & V_285 ||
( F_3 ( V_8 ) & V_285 ) ) {
F_8 ( V_8 , V_271 | V_285 ) ;
F_40 ( L_67 ) ;
break;
}
}
if ( V_150 == 4 )
F_7 ( L_68 ) ;
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_274 ;
V_271 |= V_300 ;
V_271 &= ~ V_292 ;
V_271 |= V_293 ;
F_8 ( V_8 , V_271 ) ;
V_8 = F_63 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_277 ;
V_271 |= V_296 ;
F_8 ( V_8 , V_271 ) ;
F_12 ( V_8 ) ;
F_93 ( 150 ) ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_292 ;
V_271 |= V_295 [ V_150 ] ;
F_8 ( V_8 , V_271 ) ;
F_12 ( V_8 ) ;
F_93 ( 500 ) ;
V_8 = F_160 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
F_40 ( L_66 , V_271 ) ;
if ( V_271 & V_284 ) {
F_8 ( V_8 , V_271 | V_284 ) ;
F_40 ( L_69 ) ;
break;
}
}
if ( V_150 == 4 )
F_7 ( L_70 ) ;
F_40 ( L_72 ) ;
}
static void F_164 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_8 , V_271 ;
F_8 ( F_165 ( V_105 ) ,
F_3 ( F_166 ( V_105 ) ) & V_301 ) ;
V_8 = F_63 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ ( ( 0x7 << 19 ) | ( 0x7 << 16 ) ) ;
V_271 |= ( V_124 -> V_286 - 1 ) << 19 ;
V_271 |= ( F_3 ( F_45 ( V_105 ) ) & V_198 ) << 11 ;
F_8 ( V_8 , V_271 | V_134 ) ;
F_12 ( V_8 ) ;
F_93 ( 200 ) ;
V_271 = F_3 ( V_8 ) ;
F_8 ( V_8 , V_271 | V_302 ) ;
F_12 ( V_8 ) ;
F_93 ( 200 ) ;
if ( ! F_59 ( V_2 ) ) {
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
if ( ( V_271 & V_133 ) == 0 ) {
F_8 ( V_8 , V_271 | V_133 ) ;
F_12 ( V_8 ) ;
F_93 ( 100 ) ;
}
}
}
static void F_167 ( struct V_1 * V_2 , int V_105 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_9 = F_3 ( V_282 ) ;
V_9 &= ~ ( F_155 ( V_105 ) ) ;
F_8 ( V_282 , V_9 ) ;
V_9 &= ~ ( F_154 ( V_105 ) ) ;
F_8 ( V_282 , V_9 ) ;
F_12 ( V_282 ) ;
}
static void F_168 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_8 , V_271 ;
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
F_8 ( V_8 , V_271 & ~ V_130 ) ;
F_12 ( V_8 ) ;
V_8 = F_63 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ ( 0x7 << 16 ) ;
V_271 |= ( F_3 ( F_45 ( V_105 ) ) & V_198 ) << 11 ;
F_8 ( V_8 , V_271 & ~ V_131 ) ;
F_12 ( V_8 ) ;
F_93 ( 100 ) ;
if ( F_86 ( V_2 ) ) {
F_8 ( F_159 ( V_105 ) , V_288 ) ;
F_8 ( F_159 ( V_105 ) ,
F_3 ( F_159 ( V_105 ) &
~ V_289 ) ) ;
} else if ( F_57 ( V_2 ) ) {
F_167 ( V_2 , V_105 ) ;
}
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_276 ;
V_271 |= V_287 ;
F_8 ( V_8 , V_271 ) ;
V_8 = F_63 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
if ( F_57 ( V_2 ) ) {
V_271 &= ~ V_277 ;
V_271 |= V_294 ;
} else {
V_271 &= ~ V_276 ;
V_271 |= V_287 ;
}
V_271 &= ~ ( 0x07 << 16 ) ;
V_271 |= ( F_3 ( F_45 ( V_105 ) ) & V_198 ) << 11 ;
F_8 ( V_8 , V_271 ) ;
F_12 ( V_8 ) ;
F_93 ( 100 ) ;
}
static void F_169 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
if ( V_35 -> V_229 == NULL )
return;
F_147 ( & V_2 -> V_259 ) ;
F_142 ( V_35 -> V_229 ) ;
F_148 ( & V_2 -> V_259 ) ;
}
static bool F_170 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_75 * V_76 ;
F_28 (dev, crtc, encoder) {
if ( F_59 ( V_2 ) ) {
F_99 ( ! F_55 ( V_2 ) ) ;
if ( V_76 -> type == V_303 ) {
F_40 ( L_73 ) ;
return true ;
} else {
F_40 ( L_74 ,
V_76 -> type ) ;
return false ;
}
}
switch ( V_76 -> type ) {
case V_304 :
if ( ! F_171 ( & V_76 -> V_191 ) )
return false ;
continue;
}
}
return true ;
}
static void F_172 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_305 , V_306 , V_307 , V_308 = 0 ;
T_1 V_271 ;
F_8 ( V_309 , V_310 ) ;
F_96 ( V_4 , V_311 ,
F_97 ( V_4 , V_311 ) |
V_312 ) ;
if ( V_35 -> V_313 . clock == 20000 ) {
V_307 = 1 ;
V_305 = 0x41 ;
V_306 = 0x20 ;
} else {
T_1 V_314 = 172800 * 1000 ;
T_1 V_315 = 64 ;
T_1 V_316 , V_317 , V_318 ;
V_316 = ( V_314 / V_35 -> V_313 . clock ) ;
V_317 = V_316 / V_315 ;
V_318 = V_316 % V_315 ;
V_307 = 0 ;
V_305 = V_317 - 2 ;
V_306 = V_318 ;
}
F_99 ( F_173 ( V_305 ) &
~ V_319 ) ;
F_99 ( F_174 ( V_308 ) &
~ V_320 ) ;
F_40 ( L_75 ,
V_35 -> V_313 . clock ,
V_307 ,
V_305 ,
V_308 ,
V_306 ) ;
V_271 = F_97 ( V_4 , V_321 ) ;
V_271 &= ~ V_319 ;
V_271 |= F_173 ( V_305 ) ;
V_271 &= ~ V_320 ;
V_271 |= F_175 ( V_306 ) ;
V_271 |= F_174 ( V_308 ) ;
V_271 |= V_322 ;
F_96 ( V_4 ,
V_321 ,
V_271 ) ;
V_271 = F_97 ( V_4 , V_323 ) ;
V_271 &= ~ F_176 ( 1 ) ;
V_271 |= F_176 ( V_307 ) ;
F_96 ( V_4 ,
V_323 ,
V_271 ) ;
V_271 = F_97 ( V_4 , V_311 ) ;
V_271 &= ~ V_312 ;
F_96 ( V_4 ,
V_311 ,
V_271 ) ;
F_93 ( 24 ) ;
F_8 ( V_309 , V_324 ) ;
}
static void F_177 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_8 , V_271 ;
F_74 ( V_4 , V_105 ) ;
V_4 -> V_248 . V_325 ( V_35 ) ;
F_98 ( V_124 ) ;
if ( F_55 ( V_2 ) ) {
F_40 ( L_76 ) ;
F_172 ( V_35 ) ;
} else if ( F_57 ( V_2 ) ) {
T_1 V_326 ;
V_271 = F_3 ( V_127 ) ;
switch ( V_105 ) {
default:
case 0 :
V_271 |= V_327 ;
V_326 = V_328 ;
break;
case 1 :
V_271 |= V_329 ;
V_326 = V_330 ;
break;
case 2 :
V_271 |= V_331 ;
V_326 = V_332 ;
break;
}
if ( V_124 -> V_192 -> V_125 == V_128 )
V_271 |= V_326 ;
else
V_271 &= ~ V_326 ;
F_8 ( V_127 , V_271 ) ;
}
F_66 ( V_4 , V_105 ) ;
F_8 ( F_178 ( V_105 ) , F_3 ( F_179 ( V_105 ) ) ) ;
F_8 ( F_180 ( V_105 ) , F_3 ( F_181 ( V_105 ) ) ) ;
F_8 ( F_182 ( V_105 ) , F_3 ( F_183 ( V_105 ) ) ) ;
F_8 ( F_184 ( V_105 ) , F_3 ( F_185 ( V_105 ) ) ) ;
F_8 ( F_186 ( V_105 ) , F_3 ( F_187 ( V_105 ) ) ) ;
F_8 ( F_188 ( V_105 ) , F_3 ( F_189 ( V_105 ) ) ) ;
F_8 ( F_190 ( V_105 ) , F_3 ( F_191 ( V_105 ) ) ) ;
if ( ! F_59 ( V_2 ) )
F_151 ( V_35 ) ;
if ( F_57 ( V_2 ) &&
( F_18 ( V_35 , V_44 ) ||
F_18 ( V_35 , V_304 ) ) ) {
T_1 V_333 = ( F_3 ( F_45 ( V_105 ) ) & V_198 ) >> 5 ;
V_8 = F_77 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ ( V_163 |
V_334 |
V_335 ) ;
V_271 |= ( V_336 |
V_337 ) ;
V_271 |= V_333 << 9 ;
if ( V_35 -> V_313 . V_9 & V_338 )
V_271 |= V_339 ;
if ( V_35 -> V_313 . V_9 & V_340 )
V_271 |= V_341 ;
switch ( F_192 ( V_35 ) ) {
case V_173 :
V_271 |= V_174 ;
break;
case V_175 :
V_271 |= V_176 ;
break;
case V_177 :
V_271 |= V_178 ;
break;
default:
F_40 ( L_77 ) ;
V_271 |= V_174 ;
break;
}
F_8 ( V_8 , V_271 ) ;
}
F_103 ( V_4 , V_105 ) ;
}
static void F_193 ( struct V_124 * V_124 )
{
struct V_122 * V_123 = V_124 -> V_192 ;
if ( V_123 == NULL )
return;
if ( V_123 -> V_193 == 0 ) {
F_53 ( 1 , L_78 ) ;
return;
}
-- V_123 -> V_193 ;
V_124 -> V_192 = NULL ;
}
static struct V_122 * F_194 ( struct V_124 * V_124 , T_1 V_342 , T_1 V_343 )
{
struct V_3 * V_4 = V_124 -> V_191 . V_2 -> V_5 ;
struct V_122 * V_123 ;
int V_150 ;
V_123 = V_124 -> V_192 ;
if ( V_123 ) {
F_40 ( L_79 ,
V_124 -> V_191 . V_191 . V_24 , V_123 -> V_125 ) ;
goto V_344;
}
if ( F_86 ( V_4 -> V_2 ) ) {
V_150 = V_124 -> V_105 ;
V_123 = & V_4 -> V_345 [ V_150 ] ;
F_40 ( L_80 ,
V_124 -> V_191 . V_191 . V_24 , V_123 -> V_125 ) ;
goto V_88;
}
for ( V_150 = 0 ; V_150 < V_4 -> V_346 ; V_150 ++ ) {
V_123 = & V_4 -> V_345 [ V_150 ] ;
if ( V_123 -> V_193 == 0 )
continue;
if ( V_342 == ( F_3 ( V_123 -> V_125 ) & 0x7fffffff ) &&
V_343 == F_3 ( V_123 -> V_347 ) ) {
F_40 ( L_81 ,
V_124 -> V_191 . V_191 . V_24 ,
V_123 -> V_125 , V_123 -> V_193 , V_123 -> V_194 ) ;
goto V_88;
}
}
for ( V_150 = 0 ; V_150 < V_4 -> V_346 ; V_150 ++ ) {
V_123 = & V_4 -> V_345 [ V_150 ] ;
if ( V_123 -> V_193 == 0 ) {
F_40 ( L_82 ,
V_124 -> V_191 . V_191 . V_24 , V_123 -> V_125 ) ;
goto V_88;
}
}
return NULL ;
V_88:
V_124 -> V_192 = V_123 ;
V_123 -> V_193 ++ ;
F_56 ( L_83 , V_150 , V_124 -> V_105 ) ;
V_344:
F_56 ( L_84 , V_123 -> V_125 ) ;
F_8 ( V_123 -> V_125 , V_342 & ~ V_121 ) ;
F_12 ( V_123 -> V_125 ) ;
F_93 ( 150 ) ;
F_8 ( V_123 -> V_347 , V_343 ) ;
F_8 ( V_123 -> V_125 , V_342 & ~ V_121 ) ;
V_123 -> V_195 = false ;
return V_123 ;
}
void F_195 ( struct V_1 * V_2 , int V_105 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_348 = F_46 ( V_105 ) , V_349 = F_196 ( V_105 ) ;
T_1 V_271 ;
V_271 = F_3 ( V_348 ) ;
F_93 ( 500 ) ;
if ( F_38 ( F_3 ( V_348 ) != V_271 , 5 ) ) {
F_8 ( V_349 , V_350 ) ;
F_93 ( 250 ) ;
F_8 ( V_349 , 0 ) ;
if ( F_38 ( F_3 ( V_348 ) != V_271 , 5 ) )
F_7 ( L_85 , V_105 ) ;
}
}
static void F_197 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_148 = V_124 -> V_148 ;
T_1 V_271 ;
bool V_351 ;
if ( V_124 -> V_194 )
return;
V_124 -> V_194 = true ;
F_198 ( V_2 ) ;
if ( F_18 ( V_35 , V_38 ) ) {
V_271 = F_3 ( V_39 ) ;
if ( ( V_271 & V_168 ) == 0 )
F_8 ( V_39 , V_271 | V_168 ) ;
}
V_351 = F_170 ( V_35 ) ;
if ( V_351 )
F_164 ( V_35 ) ;
else
F_168 ( V_35 ) ;
if ( V_4 -> V_352 &&
( F_18 ( V_35 , V_38 ) || V_45 ) ) {
F_8 ( F_199 ( V_105 ) , V_353 | V_354 ) ;
F_8 ( F_200 ( V_105 ) , V_4 -> V_355 ) ;
F_8 ( F_201 ( V_105 ) , V_4 -> V_352 ) ;
}
F_202 ( V_35 ) ;
F_110 ( V_4 , V_105 , V_351 ) ;
F_116 ( V_4 , V_148 , V_105 ) ;
if ( V_351 )
F_177 ( V_35 ) ;
F_147 ( & V_2 -> V_259 ) ;
F_149 ( V_2 ) ;
F_148 ( & V_2 -> V_259 ) ;
F_203 ( V_35 , true ) ;
}
static void F_204 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_148 = V_124 -> V_148 ;
T_1 V_8 , V_271 ;
if ( ! V_124 -> V_194 )
return;
F_169 ( V_35 ) ;
F_205 ( V_2 , V_105 ) ;
F_203 ( V_35 , false ) ;
F_118 ( V_4 , V_148 , V_105 ) ;
if ( V_4 -> V_356 == V_148 )
F_206 ( V_2 ) ;
F_112 ( V_4 , V_105 ) ;
F_8 ( F_199 ( V_105 ) , 0 ) ;
F_8 ( F_201 ( V_105 ) , 0 ) ;
F_168 ( V_35 ) ;
F_121 ( V_4 , V_105 ) ;
F_107 ( V_4 , V_105 ) ;
if ( F_57 ( V_2 ) ) {
V_8 = F_77 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ ( V_336 | V_163 ) ;
V_271 |= V_357 ;
F_8 ( V_8 , V_271 ) ;
V_271 = F_3 ( V_127 ) ;
switch ( V_105 ) {
case 0 :
V_271 &= ~ ( V_327 | V_328 ) ;
break;
case 1 :
V_271 &= ~ ( V_329 | V_330 ) ;
break;
case 2 :
V_271 &= ~ ( V_331 | V_332 ) ;
break;
default:
F_125 () ;
}
F_8 ( V_127 , V_271 ) ;
}
F_101 ( V_124 ) ;
V_8 = F_63 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
F_8 ( V_8 , V_271 & ~ V_302 ) ;
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
F_8 ( V_8 , V_271 & ~ V_133 ) ;
F_12 ( V_8 ) ;
F_93 ( 100 ) ;
V_8 = F_63 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
F_8 ( V_8 , V_271 & ~ V_134 ) ;
F_12 ( V_8 ) ;
F_93 ( 100 ) ;
V_124 -> V_194 = false ;
F_198 ( V_2 ) ;
F_147 ( & V_2 -> V_259 ) ;
F_149 ( V_2 ) ;
F_148 ( & V_2 -> V_259 ) ;
}
static void F_207 ( struct V_34 * V_35 , int V_313 )
{
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_148 = V_124 -> V_148 ;
switch ( V_313 ) {
case V_358 :
case V_359 :
case V_360 :
F_40 ( L_86 , V_105 , V_148 ) ;
F_197 ( V_35 ) ;
break;
case V_361 :
F_40 ( L_87 , V_105 , V_148 ) ;
F_204 ( V_35 ) ;
break;
}
}
static void F_208 ( struct V_34 * V_35 )
{
struct V_124 * V_124 = F_104 ( V_35 ) ;
F_193 ( V_124 ) ;
}
static void F_209 ( struct V_124 * V_124 , bool V_362 )
{
if ( ! V_362 && V_124 -> V_363 ) {
struct V_1 * V_2 = V_124 -> V_191 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_147 ( & V_2 -> V_259 ) ;
V_4 -> V_218 . V_219 = false ;
( void ) F_210 ( V_124 -> V_363 ) ;
V_4 -> V_218 . V_219 = true ;
F_148 ( & V_2 -> V_259 ) ;
}
}
static void F_211 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_148 = V_124 -> V_148 ;
if ( V_124 -> V_194 )
return;
V_124 -> V_194 = true ;
F_198 ( V_2 ) ;
F_89 ( V_4 , V_105 ) ;
F_110 ( V_4 , V_105 , false ) ;
F_116 ( V_4 , V_148 , V_105 ) ;
F_202 ( V_35 ) ;
F_149 ( V_2 ) ;
F_209 ( V_124 , true ) ;
F_203 ( V_35 , true ) ;
}
static void F_212 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_148 = V_124 -> V_148 ;
if ( ! V_124 -> V_194 )
return;
F_169 ( V_35 ) ;
F_205 ( V_2 , V_105 ) ;
F_209 ( V_124 , false ) ;
F_203 ( V_35 , false ) ;
if ( V_4 -> V_356 == V_148 )
F_206 ( V_2 ) ;
F_118 ( V_4 , V_148 , V_105 ) ;
F_112 ( V_4 , V_105 ) ;
F_94 ( V_4 , V_105 ) ;
V_124 -> V_194 = false ;
F_149 ( V_2 ) ;
F_198 ( V_2 ) ;
}
static void F_213 ( struct V_34 * V_35 , int V_313 )
{
switch ( V_313 ) {
case V_358 :
case V_359 :
case V_360 :
F_211 ( V_35 ) ;
break;
case V_361 :
F_212 ( V_35 ) ;
break;
}
}
static void F_214 ( struct V_34 * V_35 )
{
}
static void F_215 ( struct V_34 * V_35 , int V_313 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_256 * V_257 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
bool V_118 ;
if ( V_124 -> V_364 == V_313 )
return;
V_124 -> V_364 = V_313 ;
V_4 -> V_248 . V_365 ( V_35 , V_313 ) ;
if ( ! V_2 -> V_260 -> V_261 )
return;
V_257 = V_2 -> V_260 -> V_261 -> V_262 ;
if ( ! V_257 -> V_263 )
return;
V_118 = V_35 -> V_118 && V_313 != V_361 ;
switch ( V_105 ) {
case 0 :
V_257 -> V_263 -> V_366 = V_118 ? V_35 -> V_313 . V_367 : 0 ;
V_257 -> V_263 -> V_368 = V_118 ? V_35 -> V_313 . V_369 : 0 ;
break;
case 1 :
V_257 -> V_263 -> V_370 = V_118 ? V_35 -> V_313 . V_367 : 0 ;
V_257 -> V_263 -> V_371 = V_118 ? V_35 -> V_313 . V_369 : 0 ;
break;
default:
F_7 ( L_88 , F_67 ( V_105 ) ) ;
break;
}
}
static void F_216 ( struct V_34 * V_35 )
{
struct V_372 * V_373 = V_35 -> V_374 ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_373 -> V_365 ( V_35 , V_361 ) ;
V_4 -> V_248 . V_375 ( V_35 ) ;
F_217 ( V_2 -> V_5 , F_104 ( V_35 ) -> V_148 ) ;
F_95 ( V_2 -> V_5 , F_104 ( V_35 ) -> V_105 ) ;
if ( V_35 -> V_229 ) {
F_147 ( & V_2 -> V_259 ) ;
F_130 ( F_134 ( V_35 -> V_229 ) -> V_208 ) ;
F_148 ( & V_2 -> V_259 ) ;
}
}
static void F_218 ( struct V_34 * V_35 )
{
F_212 ( V_35 ) ;
}
static void F_219 ( struct V_34 * V_35 )
{
F_211 ( V_35 ) ;
}
static void F_220 ( struct V_34 * V_35 )
{
F_204 ( V_35 ) ;
}
static void F_221 ( struct V_34 * V_35 )
{
F_197 ( V_35 ) ;
}
void F_222 ( struct V_376 * V_76 )
{
struct V_377 * V_378 = V_76 -> V_374 ;
V_378 -> V_365 ( V_76 , V_361 ) ;
}
void F_223 ( struct V_376 * V_76 )
{
struct V_377 * V_378 = V_76 -> V_374 ;
struct V_1 * V_2 = V_76 -> V_2 ;
struct V_124 * V_124 = F_104 ( V_76 -> V_35 ) ;
V_378 -> V_365 ( V_76 , V_358 ) ;
if ( F_57 ( V_2 ) )
F_195 ( V_2 , V_124 -> V_105 ) ;
}
void F_224 ( struct V_376 * V_76 )
{
struct V_75 * V_75 = F_225 ( V_76 ) ;
F_226 ( V_76 ) ;
F_227 ( V_75 ) ;
}
static bool F_228 ( struct V_34 * V_35 ,
const struct V_379 * V_313 ,
struct V_379 * V_380 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
if ( F_21 ( V_2 ) ) {
if ( V_313 -> clock * 3 > V_381 * 4 )
return false ;
}
if ( ! ( V_380 -> V_382 & V_383 ) )
F_229 ( V_380 , 0 ) ;
return true ;
}
static int F_230 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_231 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_232 ( struct V_1 * V_2 )
{
return 333000 ;
}
static int F_233 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_234 ( struct V_1 * V_2 )
{
T_4 V_384 = 0 ;
F_235 ( V_2 -> V_385 , V_386 , & V_384 ) ;
if ( V_384 & V_387 )
return 133000 ;
else {
switch ( V_384 & V_388 ) {
case V_389 :
return 333000 ;
default:
case V_390 :
return 190000 ;
}
}
}
static int F_236 ( struct V_1 * V_2 )
{
return 266000 ;
}
static int F_237 ( struct V_1 * V_2 )
{
T_4 V_391 = 0 ;
switch ( V_391 & V_392 ) {
case V_393 :
case V_394 :
return 200000 ;
case V_395 :
return 250000 ;
case V_396 :
return 133000 ;
}
return 0 ;
}
static int F_238 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_239 ( T_1 * V_397 , T_1 * V_398 )
{
while ( * V_397 > 0xffffff || * V_398 > 0xffffff ) {
* V_397 >>= 1 ;
* V_398 >>= 1 ;
}
}
static void
F_240 ( int V_235 , int V_399 , int V_400 ,
int V_401 , struct V_402 * V_403 )
{
V_403 -> V_404 = 64 ;
V_403 -> V_405 = V_235 * V_400 ;
V_403 -> V_406 = V_401 * V_399 * 8 ;
F_239 ( & V_403 -> V_405 , & V_403 -> V_406 ) ;
V_403 -> V_407 = V_400 ;
V_403 -> V_408 = V_401 ;
F_239 ( & V_403 -> V_407 , & V_403 -> V_408 ) ;
}
static inline bool F_241 ( struct V_3 * V_4 )
{
if ( V_409 >= 0 )
return V_409 != 0 ;
return V_4 -> V_410
&& ! ( V_4 -> V_145 & V_411 ) ;
}
static bool F_242 ( struct V_34 * V_35 ,
unsigned int * V_412 ,
struct V_379 * V_313 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_413 * V_414 ;
struct V_75 * V_75 ;
unsigned int V_415 = V_416 , V_333 ;
F_28 (dev, crtc, intel_encoder) {
if ( V_75 -> type == V_38 ) {
unsigned int V_417 ;
if ( ( F_3 ( V_39 ) & V_418 ) ==
V_419 )
V_417 = 8 ;
else
V_417 = 6 ;
if ( V_417 < V_415 ) {
F_40 ( L_89 , V_415 , V_417 ) ;
V_415 = V_417 ;
}
continue;
}
F_243 (connector, &dev->mode_config.connector_list,
head) {
if ( V_414 -> V_76 != & V_75 -> V_191 )
continue;
if ( V_414 -> V_420 . V_333 &&
V_414 -> V_420 . V_333 < V_415 ) {
F_40 ( L_90 , V_415 , V_414 -> V_420 . V_333 ) ;
V_415 = V_414 -> V_420 . V_333 ;
}
}
if ( V_75 -> type == V_51 ) {
if ( V_415 > 8 && V_415 < 12 ) {
F_40 ( L_91 ) ;
V_415 = 12 ;
} else {
F_40 ( L_92 ) ;
V_415 = 8 ;
}
}
}
if ( V_313 -> V_382 & V_421 ) {
F_40 ( L_93 ) ;
V_415 = 6 ;
}
switch ( V_35 -> V_229 -> V_237 ) {
case 8 :
V_333 = 8 ;
break;
case 15 :
case 16 :
V_333 = 6 ;
break;
case 24 :
V_333 = 8 ;
break;
case 30 :
V_333 = 10 ;
break;
case 48 :
V_333 = 12 ;
break;
default:
F_244 ( L_94 ) ;
V_333 = V_77 ( ( unsigned int ) 8 , V_415 ) ;
break;
}
V_415 = V_77 ( V_415 , V_333 ) ;
F_40 ( L_95 ,
V_333 , V_415 ) ;
* V_412 = V_415 * 3 ;
return V_415 != V_333 ;
}
static int F_245 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_36 = 27000 ;
return 100000 ;
if ( F_18 ( V_35 , V_52 ) ) {
V_36 = 96000 ;
} else if ( F_18 ( V_35 , V_38 ) ) {
if ( F_241 ( V_4 ) )
V_36 = 100000 ;
else
V_36 = 96000 ;
} else if ( F_18 ( V_35 , V_304 ) ) {
V_36 = 100000 ;
}
return V_36 ;
}
static int F_246 ( struct V_34 * V_35 , int V_422 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_36 ;
if ( F_24 ( V_2 ) ) {
V_36 = F_245 ( V_35 ) ;
} else if ( F_18 ( V_35 , V_38 ) &&
F_241 ( V_4 ) && V_422 < 2 ) {
V_36 = V_4 -> V_423 * 1000 ;
F_40 ( L_96 ,
V_36 / 1000 ) ;
} else if ( ! F_25 ( V_2 ) ) {
V_36 = 96000 ;
} else {
V_36 = 48000 ;
}
return V_36 ;
}
static void F_247 ( struct V_379 * V_380 ,
T_3 * clock )
{
if ( V_380 -> clock >= 100000
&& V_380 -> clock < 140500 ) {
clock -> V_69 = 2 ;
clock -> V_70 = 10 ;
clock -> V_72 = 3 ;
clock -> V_74 = 16 ;
clock -> V_67 = 8 ;
} else if ( V_380 -> clock >= 140500
&& V_380 -> clock <= 200000 ) {
clock -> V_69 = 1 ;
clock -> V_70 = 10 ;
clock -> V_72 = 6 ;
clock -> V_74 = 12 ;
clock -> V_67 = 8 ;
}
}
static void F_248 ( struct V_34 * V_35 ,
T_3 * clock ,
T_3 * V_424 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_343 , V_425 = 0 ;
if ( F_23 ( V_2 ) ) {
V_343 = ( 1 << clock -> V_72 ) << 16 | clock -> V_74 << 8 | clock -> V_67 ;
if ( V_424 )
V_425 = ( 1 << V_424 -> V_72 ) << 16 |
V_424 -> V_74 << 8 | V_424 -> V_67 ;
} else {
V_343 = clock -> V_72 << 16 | clock -> V_74 << 8 | clock -> V_67 ;
if ( V_424 )
V_425 = V_424 -> V_72 << 16 | V_424 -> V_74 << 8 |
V_424 -> V_67 ;
}
F_8 ( F_249 ( V_105 ) , V_343 ) ;
V_124 -> V_426 = false ;
if ( F_18 ( V_35 , V_38 ) &&
V_424 && V_427 ) {
F_8 ( F_250 ( V_105 ) , V_425 ) ;
V_124 -> V_426 = true ;
} else {
F_8 ( F_250 ( V_105 ) , V_343 ) ;
}
}
static void F_251 ( struct V_34 * V_35 , T_3 * clock ,
struct V_379 * V_380 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_271 ;
V_271 = F_3 ( V_48 ) ;
V_271 |= V_168 | V_428 ;
if ( V_105 == 1 ) {
V_271 |= V_143 ;
} else {
V_271 &= ~ V_143 ;
}
V_271 |= V_4 -> V_429 ;
if ( clock -> V_70 == 7 )
V_271 |= V_430 | V_33 ;
else
V_271 &= ~ ( V_430 | V_33 ) ;
if ( F_43 ( V_2 ) -> V_109 >= 4 ) {
if ( V_4 -> V_431 )
V_271 |= V_432 ;
else
V_271 &= ~ V_432 ;
}
V_271 &= ~ ( V_433 | V_434 ) ;
if ( V_380 -> V_9 & V_435 )
V_271 |= V_433 ;
if ( V_380 -> V_9 & V_436 )
V_271 |= V_434 ;
F_8 ( V_48 , V_271 ) ;
}
static void F_252 ( struct V_34 * V_35 ,
struct V_379 * V_313 ,
struct V_379 * V_380 ,
T_3 * clock , T_3 * V_424 ,
int V_36 , int V_422 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_342 , V_437 , V_438 ;
T_1 V_91 , V_92 , V_93 , V_94 , V_95 ;
bool V_439 ;
V_439 = F_18 ( V_35 , V_51 ) ;
V_91 = clock -> V_72 ;
V_92 = clock -> V_74 ;
V_93 = clock -> V_67 ;
V_94 = clock -> V_69 ;
V_95 = clock -> V_70 ;
V_342 = V_440 | V_441 |
V_442 | V_443 ;
F_8 ( F_52 ( V_105 ) , V_342 ) ;
F_12 ( F_52 ( V_105 ) ) ;
V_437 = ( ( V_92 << V_444 ) | ( V_93 & V_445 ) ) ;
V_437 |= ( ( V_94 << V_446 ) | ( V_95 << V_447 ) ) ;
V_437 |= ( ( V_91 << V_448 ) ) ;
V_437 |= ( 1 << V_449 ) ;
V_437 |= ( 1 << V_450 ) ;
V_437 |= V_451 ;
F_10 ( V_4 , F_253 ( V_105 ) , V_437 ) ;
F_10 ( V_4 , F_254 ( V_105 ) , 0x01000000 ) ;
V_438 = V_452 | ( 5 << V_453 ) |
( 3 << V_454 ) | ( 1 << 20 ) |
( 8 << V_455 ) | ( 5 << V_456 ) ;
F_10 ( V_4 , F_255 ( V_105 ) , V_438 ) ;
F_10 ( V_4 , F_256 ( V_105 ) , 0x009f0051 ) ;
V_342 |= V_121 ;
F_8 ( F_52 ( V_105 ) , V_342 ) ;
F_12 ( F_52 ( V_105 ) ) ;
if ( F_38 ( ( ( F_3 ( F_52 ( V_105 ) ) & V_457 ) == V_457 ) , 1 ) )
F_7 ( L_97 , V_105 ) ;
if ( V_439 ) {
T_1 V_271 = F_257 ( V_380 ) ;
if ( V_271 > 1 )
V_271 = ( V_271 - 1 ) << V_458 ;
else
V_271 = 0 ;
F_8 ( F_258 ( V_105 ) , V_271 ) ;
F_12 ( F_258 ( V_105 ) ) ;
}
F_10 ( V_4 , V_459 , 0x641 ) ;
}
static void F_259 ( struct V_34 * V_35 ,
struct V_379 * V_313 ,
struct V_379 * V_380 ,
T_3 * clock , T_3 * V_424 ,
int V_422 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_342 ;
bool V_460 ;
V_460 = F_18 ( V_35 , V_54 ) ||
F_18 ( V_35 , V_51 ) ;
V_342 = V_442 ;
if ( F_18 ( V_35 , V_38 ) )
V_342 |= V_461 ;
else
V_342 |= V_462 ;
if ( V_460 ) {
int V_463 = F_257 ( V_380 ) ;
if ( V_463 > 1 ) {
if ( F_260 ( V_2 ) || F_261 ( V_2 ) || F_262 ( V_2 ) )
V_342 |= ( V_463 - 1 ) << V_464 ;
}
V_342 |= V_465 ;
}
if ( F_18 ( V_35 , V_44 ) )
V_342 |= V_465 ;
if ( F_23 ( V_2 ) )
V_342 |= ( 1 << ( clock -> V_69 - 1 ) ) << V_466 ;
else {
V_342 |= ( 1 << ( clock -> V_69 - 1 ) ) << V_467 ;
if ( F_22 ( V_2 ) && V_424 )
V_342 |= ( 1 << ( V_424 -> V_69 - 1 ) ) << V_468 ;
}
switch ( clock -> V_70 ) {
case 5 :
V_342 |= V_469 ;
break;
case 7 :
V_342 |= V_470 ;
break;
case 10 :
V_342 |= V_471 ;
break;
case 14 :
V_342 |= V_472 ;
break;
}
if ( F_43 ( V_2 ) -> V_109 >= 4 )
V_342 |= ( 6 << V_473 ) ;
if ( V_460 && F_18 ( V_35 , V_474 ) )
V_342 |= V_475 ;
else if ( F_18 ( V_35 , V_474 ) )
V_342 |= 3 ;
else if ( F_18 ( V_35 , V_38 ) &&
F_241 ( V_4 ) && V_422 < 2 )
V_342 |= V_476 ;
else
V_342 |= V_477 ;
V_342 |= V_121 ;
F_8 ( F_52 ( V_105 ) , V_342 & ~ V_121 ) ;
F_12 ( F_52 ( V_105 ) ) ;
F_93 ( 150 ) ;
if ( F_18 ( V_35 , V_38 ) )
F_251 ( V_35 , clock , V_380 ) ;
if ( F_18 ( V_35 , V_44 ) )
F_263 ( V_35 , V_313 , V_380 ) ;
F_8 ( F_52 ( V_105 ) , V_342 ) ;
F_12 ( F_52 ( V_105 ) ) ;
F_93 ( 150 ) ;
if ( F_43 ( V_2 ) -> V_109 >= 4 ) {
T_1 V_271 = 0 ;
if ( V_460 ) {
V_271 = F_257 ( V_380 ) ;
if ( V_271 > 1 )
V_271 = ( V_271 - 1 ) << V_458 ;
else
V_271 = 0 ;
}
F_8 ( F_258 ( V_105 ) , V_271 ) ;
} else {
F_8 ( F_52 ( V_105 ) , V_342 ) ;
}
}
static void F_264 ( struct V_34 * V_35 ,
struct V_379 * V_380 ,
T_3 * clock ,
int V_422 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_342 ;
V_342 = V_442 ;
if ( F_18 ( V_35 , V_38 ) ) {
V_342 |= ( 1 << ( clock -> V_69 - 1 ) ) << V_467 ;
} else {
if ( clock -> V_69 == 2 )
V_342 |= V_478 ;
else
V_342 |= ( clock -> V_69 - 2 ) << V_467 ;
if ( clock -> V_70 == 4 )
V_342 |= V_479 ;
}
if ( F_18 ( V_35 , V_474 ) )
V_342 |= 3 ;
else if ( F_18 ( V_35 , V_38 ) &&
F_241 ( V_4 ) && V_422 < 2 )
V_342 |= V_476 ;
else
V_342 |= V_477 ;
V_342 |= V_121 ;
F_8 ( F_52 ( V_105 ) , V_342 & ~ V_121 ) ;
F_12 ( F_52 ( V_105 ) ) ;
F_93 ( 150 ) ;
if ( F_18 ( V_35 , V_38 ) )
F_251 ( V_35 , clock , V_380 ) ;
F_8 ( F_52 ( V_105 ) , V_342 ) ;
F_12 ( F_52 ( V_105 ) ) ;
F_93 ( 150 ) ;
F_8 ( F_52 ( V_105 ) , V_342 ) ;
}
static int F_265 ( struct V_34 * V_35 ,
struct V_379 * V_313 ,
struct V_379 * V_380 ,
int V_222 , int V_223 ,
struct V_228 * V_251 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_148 = V_124 -> V_148 ;
int V_36 , V_422 = 0 ;
T_3 clock , V_424 ;
T_1 V_233 , V_480 , V_481 ;
bool V_482 , V_483 = false , V_460 = false ;
bool V_484 = false , V_485 = false , V_486 = false ;
struct V_75 * V_76 ;
const T_2 * V_37 ;
int V_212 ;
F_28 (dev, crtc, encoder) {
switch ( V_76 -> type ) {
case V_38 :
V_484 = true ;
break;
case V_54 :
case V_51 :
V_460 = true ;
if ( V_76 -> V_487 )
V_485 = true ;
break;
case V_474 :
V_485 = true ;
break;
case V_44 :
V_486 = true ;
break;
}
V_422 ++ ;
}
V_36 = F_246 ( V_35 , V_422 ) ;
V_37 = F_20 ( V_35 , V_36 ) ;
V_482 = V_37 -> V_488 ( V_37 , V_35 , V_380 -> clock , V_36 , NULL ,
& clock ) ;
if ( ! V_482 ) {
F_7 ( L_98 ) ;
return - V_217 ;
}
F_203 ( V_35 , true ) ;
if ( V_484 && V_4 -> V_489 ) {
V_483 = V_37 -> V_488 ( V_37 , V_35 ,
V_4 -> V_490 ,
V_36 ,
& clock ,
& V_424 ) ;
}
if ( V_460 && V_485 )
F_247 ( V_380 , & clock ) ;
F_248 ( V_35 , & clock , V_483 ?
& V_424 : NULL ) ;
if ( F_25 ( V_2 ) )
F_264 ( V_35 , V_380 , & clock , V_422 ) ;
else if ( F_24 ( V_2 ) )
F_252 ( V_35 , V_313 , V_380 , & clock , NULL ,
V_36 , V_422 ) ;
else
F_259 ( V_35 , V_313 , V_380 , & clock ,
V_483 ? & V_424 : NULL ,
V_422 ) ;
V_480 = F_3 ( F_45 ( V_105 ) ) ;
V_233 = V_491 ;
if ( V_105 == 0 )
V_233 &= ~ V_152 ;
else
V_233 |= V_492 ;
if ( V_105 == 0 && F_43 ( V_2 ) -> V_109 < 4 ) {
if ( V_313 -> clock >
V_4 -> V_248 . V_493 ( V_2 ) * 9 / 10 )
V_480 |= V_494 ;
else
V_480 &= ~ V_494 ;
}
V_480 &= ~ ( V_495 | V_496 ) ;
if ( V_486 ) {
if ( V_313 -> V_382 & V_421 ) {
V_480 |= V_497 |
V_496 |
V_498 ;
}
}
F_40 ( L_99 , V_105 == 0 ? 'A' : 'B' ) ;
F_266 ( V_313 ) ;
if ( F_267 ( V_2 ) ) {
if ( V_124 -> V_426 ) {
F_40 ( L_100 ) ;
V_480 |= V_499 ;
} else {
F_40 ( L_101 ) ;
V_480 &= ~ V_499 ;
}
}
V_480 &= ~ V_200 ;
if ( ! F_25 ( V_2 ) &&
V_380 -> V_9 & V_500 ) {
V_480 |= V_501 ;
V_380 -> V_502 -= 1 ;
V_380 -> V_503 -= 1 ;
V_481 = V_380 -> V_504
- V_380 -> V_505 / 2 ;
} else {
V_480 |= V_506 ;
V_481 = 0 ;
}
if ( ! F_268 ( V_2 ) )
F_8 ( F_191 ( V_105 ) , V_481 ) ;
F_8 ( F_179 ( V_105 ) ,
( V_380 -> V_507 - 1 ) |
( ( V_380 -> V_505 - 1 ) << 16 ) ) ;
F_8 ( F_181 ( V_105 ) ,
( V_380 -> V_508 - 1 ) |
( ( V_380 -> V_509 - 1 ) << 16 ) ) ;
F_8 ( F_183 ( V_105 ) ,
( V_380 -> V_504 - 1 ) |
( ( V_380 -> V_510 - 1 ) << 16 ) ) ;
F_8 ( F_185 ( V_105 ) ,
( V_380 -> V_511 - 1 ) |
( ( V_380 -> V_502 - 1 ) << 16 ) ) ;
F_8 ( F_187 ( V_105 ) ,
( V_380 -> V_512 - 1 ) |
( ( V_380 -> V_503 - 1 ) << 16 ) ) ;
F_8 ( F_189 ( V_105 ) ,
( V_380 -> V_513 - 1 ) |
( ( V_380 -> V_514 - 1 ) << 16 ) ) ;
F_8 ( F_269 ( V_148 ) ,
( ( V_313 -> V_369 - 1 ) << 16 ) |
( V_313 -> V_367 - 1 ) ) ;
F_8 ( F_270 ( V_148 ) , 0 ) ;
F_8 ( F_271 ( V_105 ) ,
( ( V_313 -> V_367 - 1 ) << 16 ) | ( V_313 -> V_369 - 1 ) ) ;
F_8 ( F_45 ( V_105 ) , V_480 ) ;
F_12 ( F_45 ( V_105 ) ) ;
F_110 ( V_4 , V_105 , false ) ;
F_41 ( V_2 , V_105 ) ;
F_8 ( F_70 ( V_148 ) , V_233 ) ;
F_12 ( F_70 ( V_148 ) ) ;
V_212 = F_146 ( V_35 , V_222 , V_223 , V_251 ) ;
F_198 ( V_2 ) ;
return V_212 ;
}
void F_272 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_515 * V_516 = & V_2 -> V_516 ;
struct V_75 * V_76 ;
T_1 V_271 ;
bool V_517 = false ;
bool V_518 = false ;
bool V_519 = false ;
bool V_520 = false ;
bool V_521 = false ;
bool V_522 = false ;
F_243 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_76 -> type ) {
case V_38 :
V_520 = true ;
V_517 = true ;
break;
case V_304 :
V_520 = true ;
if ( F_171 ( & V_76 -> V_191 ) )
V_519 = true ;
else
V_518 = true ;
break;
}
}
if ( F_86 ( V_2 ) ) {
V_521 = V_4 -> V_523 ;
V_522 = V_521 ;
} else {
V_521 = false ;
V_522 = true ;
}
F_40 ( L_102 ,
V_520 , V_517 , V_519 , V_518 ,
V_521 ) ;
V_271 = F_3 ( V_154 ) ;
V_271 &= ~ V_156 ;
if ( V_521 )
V_271 |= V_524 ;
else
V_271 |= V_525 ;
if ( V_520 ) {
V_271 &= ~ V_155 ;
V_271 |= V_526 ;
if ( F_241 ( V_4 ) && V_522 ) {
F_40 ( L_103 ) ;
V_271 |= V_527 ;
} else
V_271 &= ~ V_527 ;
F_8 ( V_154 , V_271 ) ;
F_12 ( V_154 ) ;
F_93 ( 200 ) ;
V_271 &= ~ V_528 ;
if ( V_518 ) {
if ( F_241 ( V_4 ) && V_522 ) {
F_40 ( L_104 ) ;
V_271 |= V_529 ;
}
else
V_271 |= V_530 ;
} else
V_271 |= V_531 ;
F_8 ( V_154 , V_271 ) ;
F_12 ( V_154 ) ;
F_93 ( 200 ) ;
} else {
F_40 ( L_105 ) ;
V_271 &= ~ V_528 ;
V_271 |= V_531 ;
F_8 ( V_154 , V_271 ) ;
F_12 ( V_154 ) ;
F_93 ( 200 ) ;
V_271 &= ~ V_155 ;
V_271 |= V_532 ;
V_271 &= ~ V_527 ;
F_8 ( V_154 , V_271 ) ;
F_12 ( V_154 ) ;
F_93 ( 200 ) ;
}
}
static int F_273 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_75 * V_76 ;
struct V_75 * V_533 = NULL ;
int V_422 = 0 ;
bool V_484 = false ;
F_28 (dev, crtc, encoder) {
switch ( V_76 -> type ) {
case V_38 :
V_484 = true ;
break;
case V_304 :
V_533 = V_76 ;
break;
}
V_422 ++ ;
}
if ( V_484 && F_241 ( V_4 ) && V_422 < 2 ) {
F_40 ( L_96 ,
V_4 -> V_423 ) ;
return V_4 -> V_423 * 1000 ;
}
return 120000 ;
}
static int F_274 ( struct V_34 * V_35 ,
struct V_379 * V_313 ,
struct V_379 * V_380 ,
int V_222 , int V_223 ,
struct V_228 * V_251 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_148 = V_124 -> V_148 ;
int V_36 , V_422 = 0 ;
T_3 clock , V_424 ;
T_1 V_342 , V_343 = 0 , V_425 = 0 , V_233 , V_480 ;
bool V_482 , V_483 = false , V_460 = false ;
bool V_534 = false , V_484 = false , V_485 = false , V_486 = false ;
struct V_75 * V_76 , * V_533 = NULL ;
const T_2 * V_37 ;
int V_212 ;
struct V_402 V_403 = { 0 } ;
T_1 V_271 ;
int V_535 , V_463 , V_536 , V_537 , V_538 ;
unsigned int V_412 ;
bool V_539 ;
bool V_540 = false , V_541 = false ;
F_28 (dev, crtc, encoder) {
switch ( V_76 -> type ) {
case V_38 :
V_484 = true ;
break;
case V_54 :
case V_51 :
V_460 = true ;
if ( V_76 -> V_487 )
V_485 = true ;
break;
case V_474 :
V_485 = true ;
break;
case V_52 :
V_534 = true ;
break;
case V_44 :
V_486 = true ;
break;
case V_304 :
V_486 = true ;
if ( F_171 ( & V_76 -> V_191 ) )
V_541 = true ;
else
V_540 = true ;
V_533 = V_76 ;
break;
}
V_422 ++ ;
}
V_36 = F_273 ( V_35 ) ;
V_37 = F_20 ( V_35 , V_36 ) ;
V_482 = V_37 -> V_488 ( V_37 , V_35 , V_380 -> clock , V_36 , NULL ,
& clock ) ;
if ( ! V_482 ) {
F_7 ( L_98 ) ;
return - V_217 ;
}
F_203 ( V_35 , true ) ;
if ( V_484 && V_4 -> V_489 ) {
V_483 = V_37 -> V_488 ( V_37 , V_35 ,
V_4 -> V_490 ,
V_36 ,
& clock ,
& V_424 ) ;
}
if ( V_460 && V_485 )
F_247 ( V_380 , & clock ) ;
V_463 = F_257 ( V_380 ) ;
V_536 = 0 ;
if ( V_540 ) {
F_275 ( V_533 , & V_536 , & V_537 ) ;
} else {
V_537 = F_1 ( V_2 ) * F_276 ( 100 ) / F_277 ( 1 ) / 10 ;
}
if ( V_533 )
V_535 = F_278 ( V_533 , V_313 ) ;
else if ( V_486 )
V_535 = V_313 -> clock ;
else
V_535 = V_380 -> clock ;
V_271 = F_3 ( F_45 ( V_105 ) ) ;
V_271 &= ~ V_198 ;
V_539 = F_242 ( V_35 , & V_412 , V_313 ) ;
switch ( V_412 ) {
case 18 :
V_271 |= V_542 ;
break;
case 24 :
V_271 |= V_543 ;
break;
case 30 :
V_271 |= V_544 ;
break;
case 36 :
V_271 |= V_545 ;
break;
default:
F_53 ( 1 , L_106 ,
V_412 ) ;
V_271 |= V_543 ;
V_412 = 24 ;
break;
}
V_124 -> V_224 = V_412 ;
F_8 ( F_45 ( V_105 ) , V_271 ) ;
if ( ! V_536 ) {
T_1 V_546 = V_535 * V_124 -> V_224 * 21 / 20 ;
V_536 = V_546 / ( V_537 * 8 ) + 1 ;
}
V_124 -> V_286 = V_536 ;
if ( V_463 > 1 )
V_537 *= V_463 ;
F_240 ( V_124 -> V_224 , V_536 , V_535 , V_537 ,
& V_403 ) ;
V_343 = clock . V_72 << 16 | clock . V_74 << 8 | clock . V_67 ;
if ( V_483 )
V_425 = V_424 . V_72 << 16 | V_424 . V_74 << 8 |
V_424 . V_67 ;
V_538 = 21 ;
if ( V_484 ) {
if ( ( F_241 ( V_4 ) &&
V_4 -> V_423 == 100 ) ||
( F_3 ( V_39 ) & V_32 ) == V_33 )
V_538 = 25 ;
} else if ( V_460 && V_485 )
V_538 = 20 ;
if ( clock . V_66 < V_538 * clock . V_72 )
V_343 |= V_547 ;
V_342 = 0 ;
if ( V_484 )
V_342 |= V_461 ;
else
V_342 |= V_462 ;
if ( V_460 ) {
int V_463 = F_257 ( V_380 ) ;
if ( V_463 > 1 ) {
V_342 |= ( V_463 - 1 ) << V_548 ;
}
V_342 |= V_465 ;
}
if ( V_486 && ! V_540 )
V_342 |= V_465 ;
V_342 |= ( 1 << ( clock . V_69 - 1 ) ) << V_467 ;
V_342 |= ( 1 << ( clock . V_69 - 1 ) ) << V_468 ;
switch ( clock . V_70 ) {
case 5 :
V_342 |= V_469 ;
break;
case 7 :
V_342 |= V_470 ;
break;
case 10 :
V_342 |= V_471 ;
break;
case 14 :
V_342 |= V_472 ;
break;
}
if ( V_460 && V_485 )
V_342 |= V_475 ;
else if ( V_485 )
V_342 |= 3 ;
else if ( V_484 && F_241 ( V_4 ) && V_422 < 2 )
V_342 |= V_476 ;
else
V_342 |= V_477 ;
V_480 = F_3 ( F_45 ( V_105 ) ) ;
V_233 = V_491 ;
F_40 ( L_107 , V_105 ) ;
F_266 ( V_313 ) ;
if ( F_55 ( V_2 ) ) {
F_40 ( L_108 ,
V_105 ) ;
} else if ( ! V_540 ) {
struct V_122 * V_123 ;
V_123 = F_194 ( V_124 , V_342 , V_343 ) ;
if ( V_123 == NULL ) {
F_56 ( L_109 ,
V_105 ) ;
return - V_217 ;
}
} else
F_193 ( V_124 ) ;
if ( V_484 ) {
V_271 = F_3 ( V_39 ) ;
V_271 |= V_168 | V_428 ;
if ( F_57 ( V_2 ) ) {
V_271 &= ~ V_166 ;
V_271 |= F_79 ( V_105 ) ;
} else {
if ( V_105 == 1 )
V_271 |= V_143 ;
else
V_271 &= ~ V_143 ;
}
V_271 |= V_4 -> V_429 ;
if ( clock . V_70 == 7 )
V_271 |= V_430 | V_33 ;
else
V_271 &= ~ ( V_430 | V_33 ) ;
V_271 &= ~ ( V_433 | V_434 ) ;
if ( V_380 -> V_9 & V_435 )
V_271 |= V_433 ;
if ( V_380 -> V_9 & V_436 )
V_271 |= V_434 ;
F_8 ( V_39 , V_271 ) ;
}
V_480 &= ~ V_496 ;
V_480 &= ~ V_549 ;
if ( ( V_484 && V_4 -> V_431 ) || V_539 ) {
V_480 |= V_496 ;
V_480 |= V_498 ;
}
if ( V_486 && ! V_540 ) {
F_263 ( V_35 , V_313 , V_380 ) ;
} else {
F_8 ( F_279 ( V_105 ) , 0 ) ;
F_8 ( F_280 ( V_105 ) , 0 ) ;
F_8 ( F_281 ( V_105 ) , 0 ) ;
F_8 ( F_282 ( V_105 ) , 0 ) ;
}
if ( V_124 -> V_192 ) {
F_8 ( V_124 -> V_192 -> V_125 , V_342 ) ;
F_12 ( V_124 -> V_192 -> V_125 ) ;
F_93 ( 150 ) ;
F_8 ( V_124 -> V_192 -> V_125 , V_342 ) ;
}
V_124 -> V_426 = false ;
if ( V_124 -> V_192 ) {
if ( V_484 && V_483 && V_427 ) {
F_8 ( V_124 -> V_192 -> V_550 , V_425 ) ;
V_124 -> V_426 = true ;
} else {
F_8 ( V_124 -> V_192 -> V_550 , V_343 ) ;
}
}
V_480 &= ~ V_200 ;
if ( V_380 -> V_9 & V_500 ) {
V_480 |= V_201 ;
V_380 -> V_502 -= 1 ;
V_380 -> V_503 -= 1 ;
F_8 ( F_191 ( V_105 ) ,
V_380 -> V_504
- V_380 -> V_505 / 2 ) ;
} else {
V_480 |= V_506 ;
F_8 ( F_191 ( V_105 ) , 0 ) ;
}
F_8 ( F_179 ( V_105 ) ,
( V_380 -> V_507 - 1 ) |
( ( V_380 -> V_505 - 1 ) << 16 ) ) ;
F_8 ( F_181 ( V_105 ) ,
( V_380 -> V_508 - 1 ) |
( ( V_380 -> V_509 - 1 ) << 16 ) ) ;
F_8 ( F_183 ( V_105 ) ,
( V_380 -> V_504 - 1 ) |
( ( V_380 -> V_510 - 1 ) << 16 ) ) ;
F_8 ( F_185 ( V_105 ) ,
( V_380 -> V_511 - 1 ) |
( ( V_380 -> V_502 - 1 ) << 16 ) ) ;
F_8 ( F_187 ( V_105 ) ,
( V_380 -> V_512 - 1 ) |
( ( V_380 -> V_503 - 1 ) << 16 ) ) ;
F_8 ( F_189 ( V_105 ) ,
( V_380 -> V_513 - 1 ) |
( ( V_380 -> V_514 - 1 ) << 16 ) ) ;
F_8 ( F_271 ( V_105 ) ,
( ( V_313 -> V_367 - 1 ) << 16 ) | ( V_313 -> V_369 - 1 ) ) ;
F_8 ( F_166 ( V_105 ) , F_283 ( V_403 . V_404 ) | V_403 . V_405 ) ;
F_8 ( F_284 ( V_105 ) , V_403 . V_406 ) ;
F_8 ( F_285 ( V_105 ) , V_403 . V_407 ) ;
F_8 ( F_286 ( V_105 ) , V_403 . V_408 ) ;
if ( V_540 )
F_150 ( V_35 , V_380 -> clock ) ;
F_8 ( F_45 ( V_105 ) , V_480 ) ;
F_12 ( F_45 ( V_105 ) ) ;
F_41 ( V_2 , V_105 ) ;
F_8 ( F_70 ( V_148 ) , V_233 ) ;
F_12 ( F_70 ( V_148 ) ) ;
V_212 = F_146 ( V_35 , V_222 , V_223 , V_251 ) ;
F_198 ( V_2 ) ;
F_287 ( V_2 , V_105 , V_380 ) ;
return V_212 ;
}
static int F_288 ( struct V_34 * V_35 ,
struct V_379 * V_313 ,
struct V_379 * V_380 ,
int V_222 , int V_223 ,
struct V_228 * V_251 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_212 ;
F_289 ( V_2 , V_105 ) ;
V_212 = V_4 -> V_248 . V_551 ( V_35 , V_313 , V_380 ,
V_222 , V_223 , V_251 ) ;
F_290 ( V_2 , V_105 ) ;
if ( V_212 )
V_124 -> V_364 = V_361 ;
else
V_124 -> V_364 = V_358 ;
return V_212 ;
}
static bool F_291 ( struct V_413 * V_414 ,
int V_552 , T_5 V_553 ,
int V_554 , T_5 V_555 ,
int V_556 )
{
struct V_3 * V_4 = V_414 -> V_2 -> V_5 ;
T_6 * V_557 = V_414 -> V_557 ;
T_5 V_150 ;
V_150 = F_3 ( V_552 ) ;
V_150 &= V_553 ;
if ( ! V_557 [ 0 ] )
return ! V_150 ;
if ( ! V_150 )
return false ;
V_150 = F_3 ( V_554 ) ;
V_150 &= ~ V_555 ;
F_8 ( V_554 , V_150 ) ;
for ( V_150 = 0 ; V_150 < V_557 [ 2 ] ; V_150 ++ )
if ( F_3 ( V_556 ) != * ( ( T_5 * ) V_557 + V_150 ) )
return false ;
return true ;
}
static void F_292 ( struct V_413 * V_414 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = V_414 -> V_2 -> V_5 ;
T_6 * V_557 = V_414 -> V_557 ;
T_5 V_558 ;
T_5 V_559 ;
T_5 V_150 ;
V_150 = F_3 ( V_560 ) ;
if ( V_150 == V_561 || V_150 == V_562 )
V_558 = V_563 ;
else
V_558 = V_564 ;
if ( F_291 ( V_414 ,
V_565 , V_558 ,
V_565 , V_566 ,
V_567 ) )
return;
V_150 = F_3 ( V_565 ) ;
V_150 &= ~ ( V_558 | V_566 ) ;
V_559 = ( V_150 >> 9 ) & 0x1f ;
F_8 ( V_565 , V_150 ) ;
if ( ! V_557 [ 0 ] )
return;
V_559 = F_293 ( T_6 , V_557 [ 2 ] , V_559 ) ;
F_56 ( L_110 , V_559 ) ;
for ( V_150 = 0 ; V_150 < V_559 ; V_150 ++ )
F_8 ( V_567 , * ( ( T_5 * ) V_557 + V_150 ) ) ;
V_150 = F_3 ( V_565 ) ;
V_150 |= V_558 ;
F_8 ( V_565 , V_150 ) ;
}
static void F_294 ( struct V_413 * V_414 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = V_414 -> V_2 -> V_5 ;
T_6 * V_557 = V_414 -> V_557 ;
T_5 V_558 ;
T_5 V_150 ;
int V_559 ;
int V_568 ;
int V_569 ;
int V_570 ;
int V_571 ;
if ( F_86 ( V_414 -> V_2 ) ) {
V_568 = V_572 ;
V_569 = V_573 ;
V_570 = V_574 ;
V_571 = V_575 ;
} else {
V_568 = V_576 ;
V_569 = V_577 ;
V_570 = V_578 ;
V_571 = V_579 ;
}
V_150 = F_104 ( V_35 ) -> V_105 ;
V_568 += V_150 * 0x100 ;
V_570 += V_150 * 0x100 ;
V_569 += V_150 * 0x100 ;
F_56 ( L_111 , F_67 ( V_150 ) ) ;
V_150 = F_3 ( V_570 ) ;
V_150 = ( V_150 >> 29 ) & 0x3 ;
if ( ! V_150 ) {
F_56 ( L_112 ) ;
V_558 = V_580 ;
V_558 |= V_580 << 4 ;
V_558 |= V_580 << 8 ;
} else {
F_56 ( L_113 , 'A' + V_150 ) ;
V_558 = V_580 << ( ( V_150 - 1 ) * 4 ) ;
}
if ( F_18 ( V_35 , V_44 ) ) {
F_56 ( L_114 ) ;
V_557 [ 5 ] |= ( 1 << 2 ) ;
F_8 ( V_569 , V_581 ) ;
} else
F_8 ( V_569 , 0 ) ;
if ( F_291 ( V_414 ,
V_571 , V_558 ,
V_570 , V_582 ,
V_568 ) )
return;
V_150 = F_3 ( V_571 ) ;
V_150 &= ~ V_558 ;
F_8 ( V_571 , V_150 ) ;
if ( ! V_557 [ 0 ] )
return;
V_150 = F_3 ( V_570 ) ;
V_150 &= ~ V_582 ;
F_8 ( V_570 , V_150 ) ;
V_559 = F_293 ( T_6 , V_557 [ 2 ] , 21 ) ;
F_56 ( L_110 , V_559 ) ;
for ( V_150 = 0 ; V_150 < V_559 ; V_150 ++ )
F_8 ( V_568 , * ( ( T_5 * ) V_557 + V_150 ) ) ;
V_150 = F_3 ( V_571 ) ;
V_150 |= V_558 ;
F_8 ( V_571 , V_150 ) ;
}
void F_295 ( struct V_376 * V_76 ,
struct V_379 * V_313 )
{
struct V_34 * V_35 = V_76 -> V_35 ;
struct V_413 * V_414 ;
struct V_1 * V_2 = V_76 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_414 = F_296 ( V_76 , V_313 ) ;
if ( ! V_414 )
return;
F_56 ( L_115 ,
V_414 -> V_191 . V_24 ,
F_297 ( V_414 ) ,
V_414 -> V_76 -> V_191 . V_24 ,
F_298 ( V_414 -> V_76 ) ) ;
V_414 -> V_557 [ 6 ] = F_299 ( V_414 , V_313 ) / 2 ;
if ( V_4 -> V_248 . V_583 )
V_4 -> V_248 . V_583 ( V_414 , V_35 ) ;
}
void F_202 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_584 = F_300 ( V_124 -> V_105 ) ;
int V_150 ;
if ( ! V_35 -> V_118 || ! V_124 -> V_194 )
return;
if ( F_21 ( V_2 ) )
V_584 = F_301 ( V_124 -> V_105 ) ;
for ( V_150 = 0 ; V_150 < 256 ; V_150 ++ ) {
F_8 ( V_584 + 4 * V_150 ,
( V_124 -> V_585 [ V_150 ] << 16 ) |
( V_124 -> V_586 [ V_150 ] << 8 ) |
V_124 -> V_587 [ V_150 ] ) ;
}
}
static void F_302 ( struct V_34 * V_35 , T_1 V_191 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
bool V_588 = V_191 != 0 ;
T_1 V_589 ;
if ( V_124 -> V_590 == V_588 )
return;
V_589 = F_3 ( V_591 ) ;
if ( V_588 ) {
F_8 ( V_592 , V_191 ) ;
V_589 &= ~ ( V_593 ) ;
V_589 |= V_594 |
V_595 |
V_596 ;
} else
V_589 &= ~ ( V_594 | V_595 ) ;
F_8 ( V_591 , V_589 ) ;
V_124 -> V_590 = V_588 ;
}
static void F_303 ( struct V_34 * V_35 , T_1 V_191 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
bool V_588 = V_191 != 0 ;
if ( V_124 -> V_590 != V_588 ) {
T_5 V_589 = F_3 ( F_304 ( V_105 ) ) ;
if ( V_191 ) {
V_589 &= ~ ( V_597 | V_598 ) ;
V_589 |= V_599 | V_600 ;
V_589 |= V_105 << 28 ;
} else {
V_589 &= ~ ( V_597 | V_600 ) ;
V_589 |= V_601 ;
}
F_8 ( F_304 ( V_105 ) , V_589 ) ;
V_124 -> V_590 = V_588 ;
}
F_8 ( F_305 ( V_105 ) , V_191 ) ;
}
static void F_306 ( struct V_34 * V_35 , T_1 V_191 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
bool V_588 = V_191 != 0 ;
if ( V_124 -> V_590 != V_588 ) {
T_5 V_589 = F_3 ( F_307 ( V_105 ) ) ;
if ( V_191 ) {
V_589 &= ~ V_597 ;
V_589 |= V_599 | V_600 ;
} else {
V_589 &= ~ ( V_597 | V_600 ) ;
V_589 |= V_601 ;
}
F_8 ( F_307 ( V_105 ) , V_589 ) ;
V_124 -> V_590 = V_588 ;
}
F_8 ( F_308 ( V_105 ) , V_191 ) ;
}
static void F_203 ( struct V_34 * V_35 ,
bool V_195 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_222 = V_124 -> V_602 ;
int V_223 = V_124 -> V_603 ;
T_1 V_191 , V_604 ;
bool V_588 ;
V_604 = 0 ;
if ( V_195 && V_35 -> V_118 && V_35 -> V_229 ) {
V_191 = V_124 -> V_605 ;
if ( V_222 > ( int ) V_35 -> V_229 -> V_606 )
V_191 = 0 ;
if ( V_223 > ( int ) V_35 -> V_229 -> V_607 )
V_191 = 0 ;
} else
V_191 = 0 ;
if ( V_222 < 0 ) {
if ( V_222 + V_124 -> V_608 < 0 )
V_191 = 0 ;
V_604 |= V_609 << V_610 ;
V_222 = - V_222 ;
}
V_604 |= V_222 << V_610 ;
if ( V_223 < 0 ) {
if ( V_223 + V_124 -> V_611 < 0 )
V_191 = 0 ;
V_604 |= V_609 << V_612 ;
V_223 = - V_223 ;
}
V_604 |= V_223 << V_612 ;
V_588 = V_191 != 0 ;
if ( ! V_588 && ! V_124 -> V_590 )
return;
if ( F_152 ( V_2 ) || F_59 ( V_2 ) ) {
F_8 ( F_309 ( V_105 ) , V_604 ) ;
F_306 ( V_35 , V_191 ) ;
} else {
F_8 ( F_310 ( V_105 ) , V_604 ) ;
if ( F_311 ( V_2 ) || F_312 ( V_2 ) )
F_302 ( V_35 , V_191 ) ;
else
F_303 ( V_35 , V_191 ) ;
}
}
static int F_313 ( struct V_34 * V_35 ,
struct V_613 * V_614 ,
T_5 V_615 ,
T_5 V_606 , T_5 V_607 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_207 * V_208 ;
T_5 V_616 ;
int V_212 ;
F_40 ( L_116 ) ;
if ( ! V_615 ) {
F_40 ( L_117 ) ;
V_616 = 0 ;
V_208 = NULL ;
F_147 ( & V_2 -> V_259 ) ;
goto V_617;
}
if ( V_606 != 64 || V_607 != 64 ) {
F_7 ( L_118 ) ;
return - V_217 ;
}
V_208 = F_314 ( F_315 ( V_2 , V_614 , V_615 ) ) ;
if ( & V_208 -> V_191 == NULL )
return - V_618 ;
if ( V_208 -> V_191 . V_619 < V_606 * V_607 * 4 ) {
F_7 ( L_119 ) ;
V_212 = - V_620 ;
goto V_621;
}
F_147 ( & V_2 -> V_259 ) ;
if ( ! V_4 -> V_132 -> V_622 ) {
if ( V_208 -> V_213 ) {
F_7 ( L_120 ) ;
V_212 = - V_217 ;
goto V_623;
}
V_212 = F_126 ( V_208 , 0 , NULL ) ;
if ( V_212 ) {
F_7 ( L_121 ) ;
goto V_623;
}
V_212 = F_316 ( V_208 ) ;
if ( V_212 ) {
F_7 ( L_122 ) ;
goto V_624;
}
V_616 = V_208 -> V_244 ;
} else {
int V_625 = F_92 ( V_2 ) ? 16 * 1024 : 256 ;
V_212 = F_317 ( V_2 , V_208 ,
( V_124 -> V_105 == 0 ) ? V_626 : V_627 ,
V_625 ) ;
if ( V_212 ) {
F_7 ( L_123 ) ;
goto V_623;
}
V_616 = V_208 -> V_628 -> V_615 -> V_629 ;
}
if ( F_25 ( V_2 ) )
F_8 ( V_630 , ( V_607 << 12 ) | V_606 ) ;
V_617:
if ( V_124 -> V_631 ) {
if ( V_4 -> V_132 -> V_622 ) {
if ( V_124 -> V_631 != V_208 )
F_318 ( V_2 , V_124 -> V_631 ) ;
} else
F_129 ( V_124 -> V_631 ) ;
F_319 ( & V_124 -> V_631 -> V_191 ) ;
}
F_148 ( & V_2 -> V_259 ) ;
V_124 -> V_605 = V_616 ;
V_124 -> V_631 = V_208 ;
V_124 -> V_608 = V_606 ;
V_124 -> V_611 = V_607 ;
F_203 ( V_35 , true ) ;
return 0 ;
V_624:
F_129 ( V_208 ) ;
V_623:
F_148 ( & V_2 -> V_259 ) ;
V_621:
F_320 ( & V_208 -> V_191 ) ;
return V_212 ;
}
static int F_321 ( struct V_34 * V_35 , int V_222 , int V_223 )
{
struct V_124 * V_124 = F_104 ( V_35 ) ;
V_124 -> V_602 = V_222 ;
V_124 -> V_603 = V_223 ;
F_203 ( V_35 , true ) ;
return 0 ;
}
void F_322 ( struct V_34 * V_35 , T_4 V_632 , T_4 V_633 ,
T_4 V_634 , int V_635 )
{
struct V_124 * V_124 = F_104 ( V_35 ) ;
V_124 -> V_585 [ V_635 ] = V_632 >> 8 ;
V_124 -> V_586 [ V_635 ] = V_633 >> 8 ;
V_124 -> V_587 [ V_635 ] = V_634 >> 8 ;
}
void F_323 ( struct V_34 * V_35 , T_4 * V_632 , T_4 * V_633 ,
T_4 * V_634 , int V_635 )
{
struct V_124 * V_124 = F_104 ( V_35 ) ;
* V_632 = V_124 -> V_585 [ V_635 ] << 8 ;
* V_633 = V_124 -> V_586 [ V_635 ] << 8 ;
* V_634 = V_124 -> V_587 [ V_635 ] << 8 ;
}
static void F_324 ( struct V_34 * V_35 , T_4 * V_632 , T_4 * V_633 ,
T_4 * V_634 , T_5 V_636 , T_5 V_619 )
{
int V_637 = ( V_636 + V_619 > 256 ) ? 256 : V_636 + V_619 , V_150 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
for ( V_150 = V_636 ; V_150 < V_637 ; V_150 ++ ) {
V_124 -> V_585 [ V_150 ] = V_632 [ V_150 ] >> 8 ;
V_124 -> V_586 [ V_150 ] = V_633 [ V_150 ] >> 8 ;
V_124 -> V_587 [ V_150 ] = V_634 [ V_150 ] >> 8 ;
}
F_202 ( V_35 ) ;
}
static struct V_228 *
F_325 ( struct V_1 * V_2 ,
struct V_638 * V_639 ,
struct V_207 * V_208 )
{
struct V_230 * V_231 ;
int V_212 ;
V_231 = F_326 ( sizeof( * V_231 ) , V_640 ) ;
if ( ! V_231 ) {
F_320 ( & V_208 -> V_191 ) ;
return F_327 ( - V_620 ) ;
}
V_212 = F_328 ( V_2 , V_231 , V_639 , V_208 ) ;
if ( V_212 ) {
F_320 ( & V_208 -> V_191 ) ;
F_227 ( V_231 ) ;
return F_327 ( V_212 ) ;
}
return & V_231 -> V_191 ;
}
static T_1
F_329 ( int V_606 , int V_224 )
{
T_1 V_225 = F_330 ( V_606 * V_224 , 8 ) ;
return F_331 ( V_225 , 64 ) ;
}
static T_1
F_332 ( struct V_379 * V_313 , int V_224 )
{
T_1 V_225 = F_329 ( V_313 -> V_367 , V_224 ) ;
return F_331 ( V_225 * V_313 -> V_369 , V_641 ) ;
}
static struct V_228 *
F_333 ( struct V_1 * V_2 ,
struct V_379 * V_313 ,
int V_237 , int V_224 )
{
struct V_207 * V_208 ;
struct V_638 V_639 ;
V_208 = F_334 ( V_2 ,
F_332 ( V_313 , V_224 ) ) ;
if ( V_208 == NULL )
return F_327 ( - V_620 ) ;
V_639 . V_606 = V_313 -> V_367 ;
V_639 . V_607 = V_313 -> V_369 ;
V_639 . V_242 [ 0 ] = F_329 ( V_639 . V_606 ,
V_224 ) ;
V_639 . V_642 = F_335 ( V_224 , V_237 ) ;
return F_325 ( V_2 , & V_639 , V_208 ) ;
}
static struct V_228 *
F_336 ( struct V_1 * V_2 ,
struct V_379 * V_313 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_207 * V_208 ;
struct V_228 * V_229 ;
if ( V_4 -> V_643 == NULL )
return NULL ;
V_208 = V_4 -> V_643 -> V_644 . V_208 ;
if ( V_208 == NULL )
return NULL ;
V_229 = & V_4 -> V_643 -> V_644 . V_191 ;
if ( V_229 -> V_242 [ 0 ] < F_329 ( V_313 -> V_367 ,
V_229 -> V_235 ) )
return NULL ;
if ( V_208 -> V_191 . V_619 < V_313 -> V_369 * V_229 -> V_242 [ 0 ] )
return NULL ;
return V_229 ;
}
bool F_337 ( struct V_75 * V_75 ,
struct V_413 * V_414 ,
struct V_379 * V_313 ,
struct V_645 * V_646 )
{
struct V_124 * V_124 ;
struct V_34 * V_647 ;
struct V_376 * V_76 = & V_75 -> V_191 ;
struct V_34 * V_35 = NULL ;
struct V_1 * V_2 = V_76 -> V_2 ;
struct V_228 * V_251 ;
int V_150 = - 1 ;
F_40 ( L_124 ,
V_414 -> V_191 . V_24 , F_297 ( V_414 ) ,
V_76 -> V_191 . V_24 , F_298 ( V_76 ) ) ;
if ( V_76 -> V_35 ) {
V_35 = V_76 -> V_35 ;
V_124 = F_104 ( V_35 ) ;
V_646 -> V_364 = V_124 -> V_364 ;
V_646 -> V_648 = false ;
if ( V_124 -> V_364 != V_358 ) {
struct V_377 * V_378 ;
struct V_372 * V_373 ;
V_373 = V_35 -> V_374 ;
V_373 -> V_365 ( V_35 , V_358 ) ;
V_378 = V_76 -> V_374 ;
V_378 -> V_365 ( V_76 , V_358 ) ;
}
return true ;
}
F_243 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_150 ++ ;
if ( ! ( V_76 -> V_649 & ( 1 << V_150 ) ) )
continue;
if ( ! V_647 -> V_118 ) {
V_35 = V_647 ;
break;
}
}
if ( ! V_35 ) {
F_40 ( L_125 ) ;
return false ;
}
V_76 -> V_35 = V_35 ;
V_414 -> V_76 = V_76 ;
V_124 = F_104 ( V_35 ) ;
V_646 -> V_364 = V_124 -> V_364 ;
V_646 -> V_648 = true ;
V_646 -> V_650 = NULL ;
if ( ! V_313 )
V_313 = & V_651 ;
V_251 = V_35 -> V_229 ;
V_35 -> V_229 = F_336 ( V_2 , V_313 ) ;
if ( V_35 -> V_229 == NULL ) {
F_40 ( L_126 ) ;
V_35 -> V_229 = F_333 ( V_2 , V_313 , 24 , 32 ) ;
V_646 -> V_650 = V_35 -> V_229 ;
} else
F_40 ( L_127 ) ;
if ( F_338 ( V_35 -> V_229 ) ) {
F_40 ( L_128 ) ;
V_35 -> V_229 = V_251 ;
return false ;
}
if ( ! F_339 ( V_35 , V_313 , 0 , 0 , V_251 ) ) {
F_40 ( L_129 ) ;
if ( V_646 -> V_650 )
V_646 -> V_650 -> V_652 -> V_653 ( V_646 -> V_650 ) ;
V_35 -> V_229 = V_251 ;
return false ;
}
F_41 ( V_2 , V_124 -> V_105 ) ;
return true ;
}
void F_340 ( struct V_75 * V_75 ,
struct V_413 * V_414 ,
struct V_645 * V_646 )
{
struct V_376 * V_76 = & V_75 -> V_191 ;
struct V_1 * V_2 = V_76 -> V_2 ;
struct V_34 * V_35 = V_76 -> V_35 ;
struct V_377 * V_378 = V_76 -> V_374 ;
struct V_372 * V_373 = V_35 -> V_374 ;
F_40 ( L_124 ,
V_414 -> V_191 . V_24 , F_297 ( V_414 ) ,
V_76 -> V_191 . V_24 , F_298 ( V_76 ) ) ;
if ( V_646 -> V_648 ) {
V_414 -> V_76 = NULL ;
F_341 ( V_2 ) ;
if ( V_646 -> V_650 )
V_646 -> V_650 -> V_652 -> V_653 ( V_646 -> V_650 ) ;
return;
}
if ( V_646 -> V_364 != V_358 ) {
V_378 -> V_365 ( V_76 , V_646 -> V_364 ) ;
V_373 -> V_365 ( V_35 , V_646 -> V_364 ) ;
}
}
static int F_342 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_342 = F_3 ( F_52 ( V_105 ) ) ;
T_1 V_343 ;
T_3 clock ;
if ( ( V_342 & V_654 ) == 0 )
V_343 = F_3 ( F_249 ( V_105 ) ) ;
else
V_343 = F_3 ( F_250 ( V_105 ) ) ;
clock . V_74 = ( V_343 & V_655 ) >> V_656 ;
if ( F_23 ( V_2 ) ) {
clock . V_72 = F_343 ( ( V_343 & V_657 ) >> V_658 ) - 1 ;
clock . V_67 = ( V_343 & V_659 ) >> V_660 ;
} else {
clock . V_72 = ( V_343 & V_661 ) >> V_658 ;
clock . V_67 = ( V_343 & V_662 ) >> V_660 ;
}
if ( ! F_25 ( V_2 ) ) {
if ( F_23 ( V_2 ) )
clock . V_69 = F_343 ( ( V_342 & V_663 ) >>
V_466 ) ;
else
clock . V_69 = F_343 ( ( V_342 & V_664 ) >>
V_467 ) ;
switch ( V_342 & V_665 ) {
case V_462 :
clock . V_70 = V_342 & V_469 ?
5 : 10 ;
break;
case V_461 :
clock . V_70 = V_342 & V_470 ?
7 : 14 ;
break;
default:
F_40 ( L_130
L_131 , ( int ) ( V_342 & V_665 ) ) ;
return 0 ;
}
F_27 ( V_2 , 96000 , & clock ) ;
} else {
bool V_484 = ( V_105 == 1 ) && ( F_3 ( V_48 ) & V_168 ) ;
if ( V_484 ) {
clock . V_69 = F_343 ( ( V_342 & V_666 ) >>
V_467 ) ;
clock . V_70 = 14 ;
if ( ( V_342 & V_667 ) ==
V_476 ) {
F_27 ( V_2 , 66000 , & clock ) ;
} else
F_27 ( V_2 , 48000 , & clock ) ;
} else {
if ( V_342 & V_478 )
clock . V_69 = 2 ;
else {
clock . V_69 = ( ( V_342 & V_668 ) >>
V_467 ) + 2 ;
}
if ( V_342 & V_479 )
clock . V_70 = 4 ;
else
clock . V_70 = 2 ;
F_27 ( V_2 , 48000 , & clock ) ;
}
}
return clock . V_73 ;
}
struct V_379 * F_344 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
struct V_379 * V_313 ;
int V_669 = F_3 ( F_179 ( V_105 ) ) ;
int V_670 = F_3 ( F_183 ( V_105 ) ) ;
int V_671 = F_3 ( F_185 ( V_105 ) ) ;
int V_672 = F_3 ( F_189 ( V_105 ) ) ;
V_313 = F_326 ( sizeof( * V_313 ) , V_640 ) ;
if ( ! V_313 )
return NULL ;
V_313 -> clock = F_342 ( V_2 , V_35 ) ;
V_313 -> V_367 = ( V_669 & 0xffff ) + 1 ;
V_313 -> V_673 = ( ( V_669 & 0xffff0000 ) >> 16 ) + 1 ;
V_313 -> V_674 = ( V_670 & 0xffff ) + 1 ;
V_313 -> V_675 = ( ( V_670 & 0xffff0000 ) >> 16 ) + 1 ;
V_313 -> V_369 = ( V_671 & 0xffff ) + 1 ;
V_313 -> V_676 = ( ( V_671 & 0xffff0000 ) >> 16 ) + 1 ;
V_313 -> V_677 = ( V_672 & 0xffff ) + 1 ;
V_313 -> V_678 = ( ( V_672 & 0xffff0000 ) >> 16 ) + 1 ;
F_345 ( V_313 ) ;
return V_313 ;
}
static void F_346 ( unsigned long V_679 )
{
struct V_1 * V_2 = (struct V_1 * ) V_679 ;
T_7 * V_4 = V_2 -> V_5 ;
if ( ! F_347 ( & V_4 -> V_218 . V_680 ) ) {
F_348 ( & V_4 -> V_681 , V_115 +
F_47 ( V_682 ) ) ;
return;
}
V_4 -> V_683 = false ;
F_349 ( V_4 -> V_684 , & V_4 -> V_685 ) ;
}
static void F_350 ( unsigned long V_679 )
{
struct V_124 * V_124 = (struct V_124 * ) V_679 ;
struct V_34 * V_35 = & V_124 -> V_191 ;
T_7 * V_4 = V_35 -> V_2 -> V_5 ;
struct V_230 * V_231 ;
V_231 = F_134 ( V_35 -> V_229 ) ;
if ( V_231 && V_231 -> V_208 -> V_194 ) {
F_348 ( & V_124 -> V_681 , V_115 +
F_47 ( V_686 ) ) ;
return;
}
V_124 -> V_683 = false ;
F_349 ( V_4 -> V_684 , & V_4 -> V_685 ) ;
}
static void F_141 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_687 = F_52 ( V_105 ) ;
int V_342 ;
if ( F_21 ( V_2 ) )
return;
if ( ! V_4 -> V_489 )
return;
V_342 = F_3 ( V_687 ) ;
if ( ! F_267 ( V_2 ) && ( V_342 & V_654 ) ) {
F_56 ( L_132 ) ;
F_66 ( V_4 , V_105 ) ;
V_342 &= ~ V_654 ;
F_8 ( V_687 , V_342 ) ;
F_41 ( V_2 , V_105 ) ;
V_342 = F_3 ( V_687 ) ;
if ( V_342 & V_654 )
F_56 ( L_133 ) ;
}
F_348 ( & V_124 -> V_681 , V_115 +
F_47 ( V_686 ) ) ;
}
static void F_351 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
if ( F_21 ( V_2 ) )
return;
if ( ! V_4 -> V_489 )
return;
if ( ! F_267 ( V_2 ) && V_124 -> V_426 ) {
int V_105 = V_124 -> V_105 ;
int V_687 = F_52 ( V_105 ) ;
int V_342 ;
F_56 ( L_134 ) ;
F_66 ( V_4 , V_105 ) ;
V_342 = F_3 ( V_687 ) ;
V_342 |= V_654 ;
F_8 ( V_687 , V_342 ) ;
F_41 ( V_2 , V_105 ) ;
V_342 = F_3 ( V_687 ) ;
if ( ! ( V_342 & V_654 ) )
F_56 ( L_135 ) ;
}
}
static void F_352 ( struct V_688 * V_689 )
{
T_7 * V_4 = F_353 ( V_689 , T_7 ,
V_685 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_34 * V_35 ;
struct V_124 * V_124 ;
if ( ! V_427 )
return;
F_147 ( & V_2 -> V_259 ) ;
F_354 ( V_4 ) ;
F_243 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_35 -> V_229 )
continue;
V_124 = F_104 ( V_35 ) ;
if ( ! V_124 -> V_683 )
F_351 ( V_35 ) ;
}
F_148 ( & V_2 -> V_259 ) ;
}
void F_355 ( struct V_1 * V_2 , struct V_207 * V_208 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_34 * V_35 = NULL ;
struct V_230 * V_231 ;
struct V_124 * V_124 ;
if ( ! F_356 ( V_2 , V_690 ) )
return;
if ( ! V_4 -> V_683 ) {
F_357 ( V_2 ) ;
V_4 -> V_683 = true ;
} else
F_348 ( & V_4 -> V_681 , V_115 +
F_47 ( V_682 ) ) ;
if ( V_208 == NULL )
return;
F_243 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_35 -> V_229 )
continue;
V_124 = F_104 ( V_35 ) ;
V_231 = F_134 ( V_35 -> V_229 ) ;
if ( V_231 -> V_208 == V_208 ) {
if ( ! V_124 -> V_683 ) {
F_141 ( V_35 ) ;
V_124 -> V_683 = true ;
} else {
F_348 ( & V_124 -> V_681 , V_115 +
F_47 ( V_686 ) ) ;
}
}
}
}
static void F_358 ( struct V_34 * V_35 )
{
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_691 * V_689 ;
unsigned long V_9 ;
F_5 ( & V_2 -> V_692 , V_9 ) ;
V_689 = V_124 -> V_693 ;
V_124 -> V_693 = NULL ;
F_9 ( & V_2 -> V_692 , V_9 ) ;
if ( V_689 ) {
F_359 ( & V_689 -> V_689 ) ;
F_227 ( V_689 ) ;
}
F_360 ( V_35 ) ;
F_227 ( V_124 ) ;
}
static void F_361 ( struct V_688 * V_694 )
{
struct V_691 * V_689 =
F_353 ( V_694 , struct V_691 , V_689 ) ;
F_147 ( & V_689 -> V_2 -> V_259 ) ;
F_130 ( V_689 -> V_695 ) ;
F_319 ( & V_689 -> V_696 -> V_191 ) ;
F_319 ( & V_689 -> V_695 -> V_191 ) ;
F_149 ( V_689 -> V_2 ) ;
F_148 ( & V_689 -> V_2 -> V_259 ) ;
F_227 ( V_689 ) ;
}
static void F_362 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_691 * V_689 ;
struct V_207 * V_208 ;
struct V_697 * V_698 ;
struct V_699 V_700 , V_701 ;
unsigned long V_9 ;
if ( V_124 == NULL )
return;
F_363 ( & V_700 ) ;
F_5 ( & V_2 -> V_692 , V_9 ) ;
V_689 = V_124 -> V_693 ;
if ( V_689 == NULL || ! V_689 -> V_702 ) {
F_9 ( & V_2 -> V_692 , V_9 ) ;
return;
}
V_124 -> V_693 = NULL ;
if ( V_689 -> V_703 ) {
V_698 = V_689 -> V_703 ;
V_698 -> V_703 . V_704 = F_364 ( V_2 , V_124 -> V_105 , & V_701 ) ;
if ( 10 * ( F_365 ( & V_700 ) - F_365 ( & V_701 ) ) >
9 * V_35 -> V_705 ) {
V_698 -> V_703 . V_704 ++ ;
V_701 = F_366 ( F_365 ( & V_701 ) +
V_35 -> V_705 ) ;
}
V_698 -> V_703 . V_706 = V_701 . V_706 ;
V_698 -> V_703 . V_707 = V_701 . V_707 ;
F_367 ( & V_698 -> V_191 . V_708 ,
& V_698 -> V_191 . V_709 -> V_710 ) ;
F_368 ( & V_698 -> V_191 . V_709 -> V_711 ) ;
}
F_369 ( V_2 , V_124 -> V_105 ) ;
F_9 ( & V_2 -> V_692 , V_9 ) ;
V_208 = V_689 -> V_695 ;
F_370 ( 1 << V_124 -> V_148 ,
& V_208 -> V_255 . V_712 ) ;
if ( F_144 ( & V_208 -> V_255 ) == 0 )
F_371 ( & V_4 -> V_253 ) ;
F_372 ( & V_689 -> V_689 ) ;
F_373 ( V_124 -> V_148 , V_689 -> V_696 ) ;
}
void F_374 ( struct V_1 * V_2 , int V_105 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_34 * V_35 = V_4 -> V_197 [ V_105 ] ;
F_362 ( V_2 , V_35 ) ;
}
void F_375 ( struct V_1 * V_2 , int V_148 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_34 * V_35 = V_4 -> V_713 [ V_148 ] ;
F_362 ( V_2 , V_35 ) ;
}
void F_376 ( struct V_1 * V_2 , int V_148 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 =
F_104 ( V_4 -> V_713 [ V_148 ] ) ;
unsigned long V_9 ;
F_5 ( & V_2 -> V_692 , V_9 ) ;
if ( V_124 -> V_693 ) {
if ( ( ++ V_124 -> V_693 -> V_702 ) > 1 )
F_7 ( L_136 ) ;
} else {
F_56 ( L_137 ) ;
}
F_9 ( & V_2 -> V_692 , V_9 ) ;
}
static int F_377 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_228 * V_229 ,
struct V_207 * V_208 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
T_1 V_714 ;
struct V_209 * V_715 = & V_4 -> V_715 [ V_716 ] ;
int V_212 ;
V_212 = F_122 ( V_2 , V_208 , V_715 ) ;
if ( V_212 )
goto V_82;
V_212 = F_378 ( V_715 , 6 ) ;
if ( V_212 )
goto V_221;
if ( V_124 -> V_148 )
V_714 = V_717 ;
else
V_714 = V_718 ;
F_379 ( V_715 , V_719 | V_714 ) ;
F_379 ( V_715 , V_720 ) ;
F_379 ( V_715 , V_721 |
F_380 ( V_124 -> V_148 ) ) ;
F_379 ( V_715 , V_229 -> V_242 [ 0 ] ) ;
F_379 ( V_715 , V_208 -> V_244 + V_124 -> V_243 ) ;
F_379 ( V_715 , 0 ) ;
F_381 ( V_715 ) ;
return 0 ;
V_221:
F_130 ( V_208 ) ;
V_82:
return V_212 ;
}
static int F_382 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_228 * V_229 ,
struct V_207 * V_208 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
T_1 V_714 ;
struct V_209 * V_715 = & V_4 -> V_715 [ V_716 ] ;
int V_212 ;
V_212 = F_122 ( V_2 , V_208 , V_715 ) ;
if ( V_212 )
goto V_82;
V_212 = F_378 ( V_715 , 6 ) ;
if ( V_212 )
goto V_221;
if ( V_124 -> V_148 )
V_714 = V_717 ;
else
V_714 = V_718 ;
F_379 ( V_715 , V_719 | V_714 ) ;
F_379 ( V_715 , V_720 ) ;
F_379 ( V_715 , V_722 |
F_380 ( V_124 -> V_148 ) ) ;
F_379 ( V_715 , V_229 -> V_242 [ 0 ] ) ;
F_379 ( V_715 , V_208 -> V_244 + V_124 -> V_243 ) ;
F_379 ( V_715 , V_720 ) ;
F_381 ( V_715 ) ;
return 0 ;
V_221:
F_130 ( V_208 ) ;
V_82:
return V_212 ;
}
static int F_383 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_228 * V_229 ,
struct V_207 * V_208 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
T_5 V_723 , V_724 ;
struct V_209 * V_715 = & V_4 -> V_715 [ V_716 ] ;
int V_212 ;
V_212 = F_122 ( V_2 , V_208 , V_715 ) ;
if ( V_212 )
goto V_82;
V_212 = F_378 ( V_715 , 4 ) ;
if ( V_212 )
goto V_221;
F_379 ( V_715 , V_721 |
F_380 ( V_124 -> V_148 ) ) ;
F_379 ( V_715 , V_229 -> V_242 [ 0 ] ) ;
F_379 ( V_715 ,
( V_208 -> V_244 + V_124 -> V_243 ) |
V_208 -> V_213 ) ;
V_723 = 0 ;
V_724 = F_3 ( F_271 ( V_124 -> V_105 ) ) & 0x0fff0fff ;
F_379 ( V_715 , V_723 | V_724 ) ;
F_381 ( V_715 ) ;
return 0 ;
V_221:
F_130 ( V_208 ) ;
V_82:
return V_212 ;
}
static int F_384 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_228 * V_229 ,
struct V_207 * V_208 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_209 * V_715 = & V_4 -> V_715 [ V_716 ] ;
T_5 V_723 , V_724 ;
int V_212 ;
V_212 = F_122 ( V_2 , V_208 , V_715 ) ;
if ( V_212 )
goto V_82;
V_212 = F_378 ( V_715 , 4 ) ;
if ( V_212 )
goto V_221;
F_379 ( V_715 , V_721 |
F_380 ( V_124 -> V_148 ) ) ;
F_379 ( V_715 , V_229 -> V_242 [ 0 ] | V_208 -> V_213 ) ;
F_379 ( V_715 , V_208 -> V_244 + V_124 -> V_243 ) ;
V_723 = 0 ;
V_724 = F_3 ( F_271 ( V_124 -> V_105 ) ) & 0x0fff0fff ;
F_379 ( V_715 , V_723 | V_724 ) ;
F_381 ( V_715 ) ;
return 0 ;
V_221:
F_130 ( V_208 ) ;
V_82:
return V_212 ;
}
static int F_385 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_228 * V_229 ,
struct V_207 * V_208 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_209 * V_715 = & V_4 -> V_715 [ V_725 ] ;
T_5 V_726 = 0 ;
int V_212 ;
V_212 = F_122 ( V_2 , V_208 , V_715 ) ;
if ( V_212 )
goto V_82;
switch( V_124 -> V_148 ) {
case V_727 :
V_726 = V_728 ;
break;
case V_729 :
V_726 = V_730 ;
break;
case V_731 :
V_726 = V_732 ;
break;
default:
F_386 ( 1 , L_138 ) ;
V_212 = - V_733 ;
goto V_82;
}
V_212 = F_378 ( V_715 , 4 ) ;
if ( V_212 )
goto V_221;
F_379 ( V_715 , V_722 | V_726 ) ;
F_379 ( V_715 , ( V_229 -> V_242 [ 0 ] | V_208 -> V_213 ) ) ;
F_379 ( V_715 , V_208 -> V_244 + V_124 -> V_243 ) ;
F_379 ( V_715 , ( V_720 ) ) ;
F_381 ( V_715 ) ;
return 0 ;
V_221:
F_130 ( V_208 ) ;
V_82:
return V_212 ;
}
static int F_387 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_228 * V_229 ,
struct V_207 * V_208 )
{
return - V_733 ;
}
static int F_388 ( struct V_34 * V_35 ,
struct V_228 * V_229 ,
struct V_697 * V_703 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_230 * V_231 ;
struct V_207 * V_208 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_691 * V_689 ;
unsigned long V_9 ;
int V_212 ;
if ( V_229 -> V_642 != V_35 -> V_229 -> V_642 )
return - V_217 ;
if ( F_43 ( V_2 ) -> V_109 > 3 &&
( V_229 -> V_734 [ 0 ] != V_35 -> V_229 -> V_734 [ 0 ] ||
V_229 -> V_242 [ 0 ] != V_35 -> V_229 -> V_242 [ 0 ] ) )
return - V_217 ;
V_689 = F_326 ( sizeof *V_689 , V_640 ) ;
if ( V_689 == NULL )
return - V_620 ;
V_689 -> V_703 = V_703 ;
V_689 -> V_2 = V_35 -> V_2 ;
V_231 = F_134 ( V_35 -> V_229 ) ;
V_689 -> V_695 = V_231 -> V_208 ;
F_389 ( & V_689 -> V_689 , F_361 ) ;
V_212 = F_390 ( V_2 , V_124 -> V_105 ) ;
if ( V_212 )
goto V_735;
F_5 ( & V_2 -> V_692 , V_9 ) ;
if ( V_124 -> V_693 ) {
F_9 ( & V_2 -> V_692 , V_9 ) ;
F_227 ( V_689 ) ;
F_369 ( V_2 , V_124 -> V_105 ) ;
F_56 ( L_139 ) ;
return - V_736 ;
}
V_124 -> V_693 = V_689 ;
F_9 ( & V_2 -> V_692 , V_9 ) ;
V_231 = F_134 ( V_229 ) ;
V_208 = V_231 -> V_208 ;
V_212 = F_391 ( V_2 ) ;
if ( V_212 )
goto V_737;
F_392 ( & V_689 -> V_695 -> V_191 ) ;
F_392 ( & V_208 -> V_191 ) ;
V_35 -> V_229 = V_229 ;
V_689 -> V_696 = V_208 ;
V_689 -> V_738 = true ;
F_393 ( 1 << V_124 -> V_148 , & V_689 -> V_695 -> V_255 ) ;
V_212 = V_4 -> V_248 . V_739 ( V_2 , V_35 , V_229 , V_208 ) ;
if ( V_212 )
goto V_740;
F_206 ( V_2 ) ;
F_355 ( V_2 , V_208 ) ;
F_148 ( & V_2 -> V_259 ) ;
F_394 ( V_124 -> V_148 , V_208 ) ;
return 0 ;
V_740:
F_395 ( 1 << V_124 -> V_148 , & V_689 -> V_695 -> V_255 ) ;
F_319 ( & V_689 -> V_695 -> V_191 ) ;
F_319 ( & V_208 -> V_191 ) ;
F_148 ( & V_2 -> V_259 ) ;
V_737:
F_5 ( & V_2 -> V_692 , V_9 ) ;
V_124 -> V_693 = NULL ;
F_9 ( & V_2 -> V_692 , V_9 ) ;
F_369 ( V_2 , V_124 -> V_105 ) ;
V_735:
F_227 ( V_689 ) ;
return V_212 ;
}
static void F_396 ( struct V_1 * V_2 ,
int V_105 , int V_148 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_8 , V_10 ;
int V_150 ;
F_397 (i) {
V_8 = F_45 ( V_150 ) ;
F_8 ( V_8 , F_3 ( V_8 ) & ~ V_741 ) ;
}
if ( F_21 ( V_2 ) )
return;
V_8 = F_70 ( V_148 ) ;
V_10 = F_3 ( V_8 ) ;
if ( ( V_10 & V_149 ) == 0 )
return;
if ( ! ! ( V_10 & V_152 ) == V_105 )
return;
V_105 = ! V_105 ;
F_118 ( V_4 , V_148 , V_105 ) ;
F_112 ( V_4 , V_105 ) ;
}
static void F_398 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
V_124 -> V_364 = - 1 ;
F_396 ( V_2 , V_124 -> V_105 , V_124 -> V_148 ) ;
}
static void F_399 ( struct V_1 * V_2 )
{
T_7 * V_4 = V_2 -> V_5 ;
int V_150 ;
if ( V_4 -> V_346 == 0 ) {
F_40 ( L_140 ) ;
return;
}
for ( V_150 = 0 ; V_150 < V_4 -> V_346 ; V_150 ++ ) {
V_4 -> V_345 [ V_150 ] . V_125 = F_400 ( V_150 ) ;
V_4 -> V_345 [ V_150 ] . V_347 = F_401 ( V_150 ) ;
V_4 -> V_345 [ V_150 ] . V_550 = F_402 ( V_150 ) ;
}
}
static void F_403 ( struct V_1 * V_2 , int V_105 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 ;
int V_150 ;
V_124 = F_326 ( sizeof( struct V_124 ) + ( V_742 * sizeof( struct V_413 * ) ) , V_640 ) ;
if ( V_124 == NULL )
return;
F_404 ( V_2 , & V_124 -> V_191 , & V_743 ) ;
F_405 ( & V_124 -> V_191 , 256 ) ;
for ( V_150 = 0 ; V_150 < 256 ; V_150 ++ ) {
V_124 -> V_585 [ V_150 ] = V_150 ;
V_124 -> V_586 [ V_150 ] = V_150 ;
V_124 -> V_587 [ V_150 ] = V_150 ;
}
V_124 -> V_105 = V_105 ;
V_124 -> V_148 = V_105 ;
if ( F_91 ( V_2 ) && F_268 ( V_2 ) ) {
F_40 ( L_141 ) ;
V_124 -> V_148 = ! V_105 ;
}
F_90 ( V_105 >= F_406 ( V_4 -> V_713 ) ||
V_4 -> V_713 [ V_124 -> V_148 ] != NULL ) ;
V_4 -> V_713 [ V_124 -> V_148 ] = & V_124 -> V_191 ;
V_4 -> V_197 [ V_124 -> V_105 ] = & V_124 -> V_191 ;
F_398 ( & V_124 -> V_191 ) ;
V_124 -> V_194 = true ;
V_124 -> V_224 = 24 ;
if ( F_21 ( V_2 ) ) {
V_744 . V_344 = F_220 ;
V_744 . V_745 = F_221 ;
} else {
V_744 . V_344 = F_218 ;
V_744 . V_745 = F_219 ;
}
F_407 ( & V_124 -> V_191 , & V_744 ) ;
V_124 -> V_683 = false ;
F_408 ( & V_124 -> V_681 , F_350 ,
( unsigned long ) V_124 ) ;
}
int F_409 ( struct V_1 * V_2 , void * V_746 ,
struct V_613 * V_614 )
{
struct V_747 * V_748 = V_746 ;
struct V_749 * V_750 ;
struct V_124 * V_35 ;
if ( ! F_356 ( V_2 , V_690 ) )
return - V_733 ;
V_750 = F_410 ( V_2 , V_748 -> V_751 ,
V_752 ) ;
if ( ! V_750 ) {
F_7 ( L_142 ) ;
return - V_217 ;
}
V_35 = F_104 ( F_411 ( V_750 ) ) ;
V_748 -> V_105 = V_35 -> V_105 ;
return 0 ;
}
static int F_412 ( struct V_1 * V_2 , int V_753 )
{
struct V_75 * V_76 ;
int V_754 = 0 ;
int V_755 = 0 ;
F_243 (encoder, &dev->mode_config.encoder_list, base.head) {
if ( V_753 & V_76 -> V_756 )
V_754 |= ( 1 << V_755 ) ;
V_755 ++ ;
}
return V_754 ;
}
static bool F_413 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_91 ( V_2 ) )
return false ;
if ( ( F_3 ( V_269 ) & V_757 ) == 0 )
return false ;
if ( F_2 ( V_2 ) &&
( F_3 ( V_758 ) & V_759 ) )
return false ;
return true ;
}
static void F_414 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_75 * V_76 ;
bool V_760 = false ;
bool V_517 ;
V_517 = F_415 ( V_2 ) ;
if ( ! V_517 && ! F_21 ( V_2 ) ) {
F_8 ( V_761 , 0 ) ;
}
if ( F_21 ( V_2 ) ) {
V_760 = F_416 ( V_2 ) ;
if ( F_413 ( V_2 ) )
F_417 ( V_2 , V_269 ) ;
if ( V_760 && ( F_3 ( V_177 ) & V_757 ) )
F_417 ( V_2 , V_177 ) ;
}
F_418 ( V_2 ) ;
if ( F_59 ( V_2 ) ) {
int V_88 ;
V_88 = F_3 ( V_762 ) & V_763 ;
if ( V_88 )
F_419 ( V_2 , V_764 ) ;
V_88 = F_3 ( V_765 ) ;
if ( V_88 & V_766 )
F_419 ( V_2 , V_767 ) ;
if ( V_88 & V_768 )
F_419 ( V_2 , V_769 ) ;
if ( V_88 & V_770 )
F_419 ( V_2 , V_771 ) ;
} else if ( F_21 ( V_2 ) ) {
int V_88 ;
if ( F_3 ( V_180 ) & V_772 ) {
V_88 = F_420 ( V_2 , V_773 , true ) ;
if ( ! V_88 )
F_421 ( V_2 , V_180 ) ;
if ( ! V_88 && ( F_3 ( V_173 ) & V_757 ) )
F_417 ( V_2 , V_173 ) ;
}
if ( F_3 ( V_181 ) & V_772 )
F_421 ( V_2 , V_181 ) ;
if ( ! V_760 && F_3 ( V_182 ) & V_772 )
F_421 ( V_2 , V_182 ) ;
if ( F_3 ( V_175 ) & V_757 )
F_417 ( V_2 , V_175 ) ;
if ( ! V_760 && ( F_3 ( V_177 ) & V_757 ) )
F_417 ( V_2 , V_177 ) ;
} else if ( F_24 ( V_2 ) ) {
int V_88 ;
if ( F_3 ( V_774 ) & V_772 ) {
V_88 = F_420 ( V_2 , V_774 , true ) ;
if ( ! V_88 )
F_421 ( V_2 , V_774 ) ;
if ( ! V_88 && ( F_3 ( V_775 ) & V_757 ) )
F_417 ( V_2 , V_775 ) ;
}
if ( F_3 ( V_776 ) & V_772 )
F_421 ( V_2 , V_776 ) ;
if ( F_3 ( V_777 ) & V_757 )
F_417 ( V_2 , V_777 ) ;
} else if ( F_422 ( V_2 ) ) {
bool V_88 = false ;
if ( F_3 ( V_774 ) & V_778 ) {
F_40 ( L_143 ) ;
V_88 = F_420 ( V_2 , V_774 , true ) ;
if ( ! V_88 && F_423 ( V_2 ) ) {
F_40 ( L_144 ) ;
F_421 ( V_2 , V_774 ) ;
}
if ( ! V_88 && F_424 ( V_2 ) ) {
F_40 ( L_145 ) ;
F_417 ( V_2 , V_775 ) ;
}
}
if ( F_3 ( V_774 ) & V_778 ) {
F_40 ( L_146 ) ;
V_88 = F_420 ( V_2 , V_776 , false ) ;
}
if ( ! V_88 && ( F_3 ( V_776 ) & V_778 ) ) {
if ( F_423 ( V_2 ) ) {
F_40 ( L_147 ) ;
F_421 ( V_2 , V_776 ) ;
}
if ( F_424 ( V_2 ) ) {
F_40 ( L_148 ) ;
F_417 ( V_2 , V_777 ) ;
}
}
if ( F_424 ( V_2 ) &&
( F_3 ( V_779 ) & V_757 ) ) {
F_40 ( L_149 ) ;
F_417 ( V_2 , V_779 ) ;
}
} else if ( F_25 ( V_2 ) )
F_425 ( V_2 ) ;
if ( F_426 ( V_2 ) )
F_427 ( V_2 ) ;
F_243 (encoder, &dev->mode_config.encoder_list, base.head) {
V_76 -> V_191 . V_649 = V_76 -> V_780 ;
V_76 -> V_191 . V_781 =
F_412 ( V_2 , V_76 -> V_756 ) ;
}
F_341 ( V_2 ) ;
if ( F_86 ( V_2 ) || F_57 ( V_2 ) )
F_272 ( V_2 ) ;
}
static void F_428 ( struct V_228 * V_229 )
{
struct V_230 * V_231 = F_134 ( V_229 ) ;
F_429 ( V_229 ) ;
F_320 ( & V_231 -> V_208 -> V_191 ) ;
F_227 ( V_231 ) ;
}
static int F_430 ( struct V_228 * V_229 ,
struct V_613 * V_614 ,
unsigned int * V_615 )
{
struct V_230 * V_231 = F_134 ( V_229 ) ;
struct V_207 * V_208 = V_231 -> V_208 ;
return F_431 ( V_614 , & V_208 -> V_191 , V_615 ) ;
}
int F_328 ( struct V_1 * V_2 ,
struct V_230 * V_231 ,
struct V_638 * V_639 ,
struct V_207 * V_208 )
{
int V_212 ;
if ( V_208 -> V_213 == V_216 )
return - V_217 ;
if ( V_639 -> V_242 [ 0 ] & 63 )
return - V_217 ;
switch ( V_639 -> V_642 ) {
case V_782 :
case V_783 :
case V_784 :
case V_785 :
case V_786 :
case V_787 :
case V_788 :
break;
case V_789 :
case V_790 :
case V_791 :
case V_792 :
break;
default:
F_40 ( L_150 ,
V_639 -> V_642 ) ;
return - V_217 ;
}
V_212 = F_432 ( V_2 , & V_231 -> V_191 , & V_793 ) ;
if ( V_212 ) {
F_7 ( L_151 , V_212 ) ;
return V_212 ;
}
F_433 ( & V_231 -> V_191 , V_639 ) ;
V_231 -> V_208 = V_208 ;
return 0 ;
}
static struct V_228 *
F_434 ( struct V_1 * V_2 ,
struct V_613 * V_794 ,
struct V_638 * V_639 )
{
struct V_207 * V_208 ;
V_208 = F_314 ( F_315 ( V_2 , V_794 ,
V_639 -> V_795 [ 0 ] ) ) ;
if ( & V_208 -> V_191 == NULL )
return F_327 ( - V_618 ) ;
return F_325 ( V_2 , V_639 , V_208 ) ;
}
static void F_435 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_21 ( V_2 ) ) {
V_4 -> V_248 . V_365 = F_207 ;
V_4 -> V_248 . V_551 = F_274 ;
V_4 -> V_248 . V_375 = F_208 ;
V_4 -> V_248 . V_250 = F_139 ;
} else {
V_4 -> V_248 . V_365 = F_213 ;
V_4 -> V_248 . V_551 = F_265 ;
V_4 -> V_248 . V_375 = F_214 ;
V_4 -> V_248 . V_250 = F_133 ;
}
if ( F_24 ( V_2 ) )
V_4 -> V_248 . V_493 =
F_230 ;
else if ( F_260 ( V_2 ) || ( F_262 ( V_2 ) && ! F_436 ( V_2 ) ) )
V_4 -> V_248 . V_493 =
F_231 ;
else if ( F_437 ( V_2 ) )
V_4 -> V_248 . V_493 =
F_232 ;
else if ( F_261 ( V_2 ) || F_311 ( V_2 ) || F_436 ( V_2 ) )
V_4 -> V_248 . V_493 =
F_233 ;
else if ( F_438 ( V_2 ) )
V_4 -> V_248 . V_493 =
F_234 ;
else if ( F_312 ( V_2 ) )
V_4 -> V_248 . V_493 =
F_236 ;
else if ( F_439 ( V_2 ) )
V_4 -> V_248 . V_493 =
F_237 ;
else
V_4 -> V_248 . V_493 =
F_238 ;
if ( F_21 ( V_2 ) ) {
if ( F_2 ( V_2 ) ) {
V_4 -> V_248 . V_325 = F_156 ;
V_4 -> V_248 . V_583 = F_294 ;
} else if ( F_162 ( V_2 ) ) {
V_4 -> V_248 . V_325 = F_161 ;
V_4 -> V_248 . V_583 = F_294 ;
} else if ( F_152 ( V_2 ) ) {
V_4 -> V_248 . V_325 = F_163 ;
V_4 -> V_248 . V_583 = F_294 ;
} else if ( F_59 ( V_2 ) ) {
V_4 -> V_248 . V_325 = V_796 ;
V_4 -> V_248 . V_583 = F_294 ;
} else
V_4 -> V_248 . V_797 = NULL ;
} else if ( F_22 ( V_2 ) ) {
V_4 -> V_248 . V_583 = F_292 ;
}
V_4 -> V_248 . V_739 = F_387 ;
switch ( F_43 ( V_2 ) -> V_109 ) {
case 2 :
V_4 -> V_248 . V_739 = F_377 ;
break;
case 3 :
V_4 -> V_248 . V_739 = F_382 ;
break;
case 4 :
case 5 :
V_4 -> V_248 . V_739 = F_383 ;
break;
case 6 :
V_4 -> V_248 . V_739 = F_384 ;
break;
case 7 :
V_4 -> V_248 . V_739 = F_385 ;
break;
}
}
static void F_440 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_145 |= V_146 ;
F_14 ( L_152 ) ;
}
static void F_441 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_145 |= V_411 ;
F_14 ( L_153 ) ;
}
static void F_442 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_145 |= V_798 ;
F_14 ( L_154 ) ;
}
static void F_443 ( struct V_1 * V_2 )
{
struct V_799 * V_800 = V_2 -> V_385 ;
int V_150 ;
for ( V_150 = 0 ; V_150 < F_406 ( V_801 ) ; V_150 ++ ) {
struct V_802 * V_803 = & V_801 [ V_150 ] ;
if ( V_800 -> V_804 == V_803 -> V_804 &&
( V_800 -> V_805 == V_803 -> V_805 ||
V_803 -> V_805 == V_806 ) &&
( V_800 -> V_807 == V_803 -> V_807 ||
V_803 -> V_807 == V_806 ) )
V_803 -> V_808 ( V_2 ) ;
}
}
static void F_444 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_8 V_809 ;
T_1 V_810 ;
if ( F_21 ( V_2 ) )
V_810 = V_811 ;
else
V_810 = V_812 ;
F_445 ( V_2 -> V_385 , V_813 ) ;
F_446 ( V_814 , V_815 ) ;
V_809 = F_447 ( V_816 ) ;
F_446 ( V_809 | 1 << 5 , V_816 ) ;
F_448 ( V_2 -> V_385 , V_813 ) ;
F_93 ( 300 ) ;
F_8 ( V_810 , V_817 ) ;
F_12 ( V_810 ) ;
}
void F_449 ( struct V_1 * V_2 )
{
F_450 ( V_2 ) ;
F_451 ( V_2 ) ;
F_452 ( V_2 ) ;
F_147 ( & V_2 -> V_259 ) ;
F_453 ( V_2 ) ;
F_148 ( & V_2 -> V_259 ) ;
}
void F_454 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_150 , V_212 ;
F_455 ( V_2 ) ;
V_2 -> V_516 . V_818 = 0 ;
V_2 -> V_516 . V_819 = 0 ;
V_2 -> V_516 . V_820 = 24 ;
V_2 -> V_516 . V_821 = 1 ;
V_2 -> V_516 . V_652 = & V_822 ;
F_443 ( V_2 ) ;
F_456 ( V_2 ) ;
F_435 ( V_2 ) ;
if ( F_25 ( V_2 ) ) {
V_2 -> V_516 . V_823 = 2048 ;
V_2 -> V_516 . V_824 = 2048 ;
} else if ( F_268 ( V_2 ) ) {
V_2 -> V_516 . V_823 = 4096 ;
V_2 -> V_516 . V_824 = 4096 ;
} else {
V_2 -> V_516 . V_823 = 8192 ;
V_2 -> V_516 . V_824 = 8192 ;
}
V_2 -> V_516 . V_825 = V_4 -> V_218 . V_826 ;
F_40 ( L_155 ,
V_4 -> V_258 , V_4 -> V_258 > 1 ? L_156 : L_157 ) ;
for ( V_150 = 0 ; V_150 < V_4 -> V_258 ; V_150 ++ ) {
F_403 ( V_2 , V_150 ) ;
V_212 = F_457 ( V_2 , V_150 ) ;
if ( V_212 )
F_40 ( L_158 , V_150 , V_212 ) ;
}
F_399 ( V_2 ) ;
F_444 ( V_2 ) ;
F_414 ( V_2 ) ;
F_389 ( & V_4 -> V_685 , F_352 ) ;
F_408 ( & V_4 -> V_681 , F_346 ,
( unsigned long ) V_2 ) ;
}
void F_458 ( struct V_1 * V_2 )
{
F_449 ( V_2 ) ;
F_459 ( V_2 ) ;
}
void F_460 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_34 * V_35 ;
struct V_124 * V_124 ;
F_461 ( V_2 ) ;
F_147 ( & V_2 -> V_259 ) ;
F_462 () ;
F_243 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_35 -> V_229 )
continue;
V_124 = F_104 ( V_35 ) ;
F_141 ( V_35 ) ;
}
F_206 ( V_2 ) ;
F_463 ( V_2 ) ;
F_464 ( V_2 ) ;
if ( F_24 ( V_2 ) )
F_11 ( V_2 ) ;
F_148 ( & V_2 -> V_259 ) ;
F_465 ( V_2 ) ;
F_359 ( & V_4 -> V_827 ) ;
F_359 ( & V_4 -> V_828 ) ;
F_466 () ;
F_243 (crtc, &dev->mode_config.crtc_list, head) {
V_124 = F_104 ( V_35 ) ;
F_467 ( & V_124 -> V_681 ) ;
}
F_467 ( & V_4 -> V_681 ) ;
F_359 ( & V_4 -> V_685 ) ;
F_468 ( V_2 ) ;
}
struct V_376 * F_469 ( struct V_413 * V_414 )
{
return & F_470 ( V_414 ) -> V_191 ;
}
void F_471 ( struct V_829 * V_414 ,
struct V_75 * V_76 )
{
V_414 -> V_76 = V_76 ;
F_472 ( & V_414 -> V_191 ,
& V_76 -> V_191 ) ;
}
int F_473 ( struct V_1 * V_2 , bool V_119 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_830 ;
F_235 ( V_4 -> V_831 , V_832 , & V_830 ) ;
if ( V_119 )
V_830 &= ~ V_833 ;
else
V_830 |= V_833 ;
F_474 ( V_4 -> V_831 , V_832 , V_830 ) ;
return 0 ;
}
struct V_834 *
F_475 ( struct V_1 * V_2 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_834 * error ;
int V_150 ;
error = F_476 ( sizeof( * error ) , V_835 ) ;
if ( error == NULL )
return NULL ;
for ( V_150 = 0 ; V_150 < 2 ; V_150 ++ ) {
error -> V_836 [ V_150 ] . V_837 = F_3 ( F_304 ( V_150 ) ) ;
error -> V_836 [ V_150 ] . V_838 = F_3 ( F_310 ( V_150 ) ) ;
error -> V_836 [ V_150 ] . V_191 = F_3 ( F_305 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_837 = F_3 ( F_70 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_839 = F_3 ( F_135 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_619 = F_3 ( F_269 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_604 = F_3 ( F_270 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_616 = F_3 ( F_114 ( V_150 ) ) ;
if ( F_43 ( V_2 ) -> V_109 >= 4 ) {
error -> V_148 [ V_150 ] . V_840 = F_3 ( F_115 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_841 = F_3 ( F_137 ( V_150 ) ) ;
}
error -> V_105 [ V_150 ] . V_842 = F_3 ( F_45 ( V_150 ) ) ;
error -> V_105 [ V_150 ] . V_843 = F_3 ( F_271 ( V_150 ) ) ;
error -> V_105 [ V_150 ] . V_673 = F_3 ( F_179 ( V_150 ) ) ;
error -> V_105 [ V_150 ] . V_844 = F_3 ( F_181 ( V_150 ) ) ;
error -> V_105 [ V_150 ] . V_670 = F_3 ( F_183 ( V_150 ) ) ;
error -> V_105 [ V_150 ] . V_676 = F_3 ( F_185 ( V_150 ) ) ;
error -> V_105 [ V_150 ] . V_845 = F_3 ( F_187 ( V_150 ) ) ;
error -> V_105 [ V_150 ] . V_672 = F_3 ( F_189 ( V_150 ) ) ;
}
return error ;
}
void
F_477 ( struct V_846 * V_66 ,
struct V_1 * V_2 ,
struct V_834 * error )
{
int V_150 ;
for ( V_150 = 0 ; V_150 < 2 ; V_150 ++ ) {
F_478 ( V_66 , L_159 , V_150 ) ;
F_478 ( V_66 , L_160 , error -> V_105 [ V_150 ] . V_842 ) ;
F_478 ( V_66 , L_161 , error -> V_105 [ V_150 ] . V_843 ) ;
F_478 ( V_66 , L_162 , error -> V_105 [ V_150 ] . V_673 ) ;
F_478 ( V_66 , L_163 , error -> V_105 [ V_150 ] . V_844 ) ;
F_478 ( V_66 , L_164 , error -> V_105 [ V_150 ] . V_670 ) ;
F_478 ( V_66 , L_165 , error -> V_105 [ V_150 ] . V_676 ) ;
F_478 ( V_66 , L_166 , error -> V_105 [ V_150 ] . V_845 ) ;
F_478 ( V_66 , L_167 , error -> V_105 [ V_150 ] . V_672 ) ;
F_478 ( V_66 , L_168 , V_150 ) ;
F_478 ( V_66 , L_169 , error -> V_148 [ V_150 ] . V_837 ) ;
F_478 ( V_66 , L_170 , error -> V_148 [ V_150 ] . V_839 ) ;
F_478 ( V_66 , L_171 , error -> V_148 [ V_150 ] . V_619 ) ;
F_478 ( V_66 , L_172 , error -> V_148 [ V_150 ] . V_604 ) ;
F_478 ( V_66 , L_173 , error -> V_148 [ V_150 ] . V_616 ) ;
if ( F_43 ( V_2 ) -> V_109 >= 4 ) {
F_478 ( V_66 , L_174 , error -> V_148 [ V_150 ] . V_840 ) ;
F_478 ( V_66 , L_175 , error -> V_148 [ V_150 ] . V_841 ) ;
}
F_478 ( V_66 , L_176 , V_150 ) ;
F_478 ( V_66 , L_169 , error -> V_836 [ V_150 ] . V_837 ) ;
F_478 ( V_66 , L_172 , error -> V_836 [ V_150 ] . V_838 ) ;
F_478 ( V_66 , L_177 , error -> V_836 [ V_150 ] . V_191 ) ;
}
}
