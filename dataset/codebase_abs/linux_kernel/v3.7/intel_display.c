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
F_46 ( 1 , L_15 ) ;
} else {
T_1 V_112 , V_113 ;
int V_8 = F_47 ( V_105 ) ;
unsigned long V_114 = V_115 + F_48 ( 100 ) ;
if ( F_25 ( V_2 ) )
V_113 = V_116 ;
else
V_113 = V_117 ;
do {
V_112 = F_3 ( V_8 ) & V_113 ;
F_49 ( 5 ) ;
} while ( ( ( F_3 ( V_8 ) & V_113 ) != V_112 ) &&
F_50 ( V_114 , V_115 ) );
if ( F_50 ( V_115 , V_114 ) )
F_46 ( 1 , L_15 ) ;
}
}
static const char * F_51 ( bool V_118 )
{
return V_118 ? L_16 : L_17 ;
}
static void F_52 ( struct V_3 * V_4 ,
enum V_105 V_105 , bool V_119 )
{
int V_8 ;
T_1 V_10 ;
bool V_120 ;
V_8 = F_53 ( V_105 ) ;
V_10 = F_3 ( V_8 ) ;
V_120 = ! ! ( V_10 & V_121 ) ;
F_46 ( V_120 != V_119 ,
L_18 ,
F_51 ( V_119 ) , F_51 ( V_120 ) ) ;
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
if ( F_46 ( ! V_123 ,
L_20 , F_51 ( V_119 ) ) )
return;
V_10 = F_3 ( V_123 -> V_125 ) ;
V_120 = ! ! ( V_10 & V_121 ) ;
F_46 ( V_120 != V_119 ,
L_21 ,
V_123 -> V_125 , F_51 ( V_119 ) , F_51 ( V_120 ) , V_10 ) ;
if ( V_35 && F_57 ( V_4 -> V_2 ) ) {
T_1 V_126 ;
V_126 = F_3 ( V_127 ) ;
V_120 = V_123 -> V_125 == V_128 ;
if ( ! F_46 ( ( ( V_126 >> ( 4 * V_35 -> V_105 ) ) & 1 ) != V_120 ,
L_22 ,
V_120 , V_35 -> V_105 , V_126 ) ) {
V_120 = ! ! ( V_10 >> ( 4 * V_35 -> V_105 + 3 ) ) ;
F_46 ( V_120 != V_119 ,
L_23 ,
V_123 -> V_125 == V_128 ,
F_51 ( V_119 ) ,
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
F_46 ( V_120 != V_119 ,
L_24 ,
F_51 ( V_119 ) , F_51 ( V_120 ) ) ;
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
F_46 ( V_120 != V_119 ,
L_26 ,
F_51 ( V_119 ) , F_51 ( V_120 ) ) ;
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
F_46 ( ! ( V_10 & V_133 ) , L_27 ) ;
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
F_46 ( ! ( V_10 & V_134 ) , L_29 ) ;
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
F_46 ( V_136 == V_105 && V_138 ,
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
F_46 ( V_120 != V_119 ,
L_31 ,
F_67 ( V_105 ) , F_51 ( V_119 ) , F_51 ( V_120 ) ) ;
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
F_46 ( V_120 != V_119 ,
L_32 ,
F_71 ( V_148 ) , F_51 ( V_119 ) , F_51 ( V_120 ) ) ;
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
F_46 ( ( V_10 & V_149 ) ,
L_33 ,
F_71 ( V_105 ) ) ;
return;
}
for ( V_150 = 0 ; V_150 < 2 ; V_150 ++ ) {
V_8 = F_70 ( V_150 ) ;
V_10 = F_3 ( V_8 ) ;
V_151 = ( V_10 & V_152 ) >>
V_153 ;
F_46 ( ( V_10 & V_149 ) && V_105 == V_151 ,
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
F_46 ( ! V_118 , L_36 ) ;
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
F_46 ( V_118 ,
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
F_46 ( F_76 ( V_4 , V_105 , V_159 , V_10 ) ,
L_38 ,
V_8 , F_67 ( V_105 ) ) ;
F_46 ( F_86 ( V_4 -> V_2 ) && ( V_10 & V_160 ) == 0
&& ( V_10 & V_171 ) ,
L_39 ) ;
}
static void F_87 ( struct V_3 * V_4 ,
enum V_105 V_105 , int V_8 )
{
T_1 V_10 = F_3 ( V_8 ) ;
F_46 ( F_78 ( V_4 , V_105 , V_10 ) ,
L_40 ,
V_8 , F_67 ( V_105 ) ) ;
F_46 ( F_86 ( V_4 -> V_2 ) && ( V_10 & V_165 ) == 0
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
F_46 ( F_83 ( V_4 , V_105 , V_10 ) ,
L_42 ,
F_67 ( V_105 ) ) ;
V_8 = V_39 ;
V_10 = F_3 ( V_8 ) ;
F_46 ( F_81 ( V_4 , V_105 , V_10 ) ,
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
V_8 = F_53 ( V_105 ) ;
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
V_8 = F_53 ( V_105 ) ;
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
int
F_119 ( struct V_1 * V_2 ,
struct V_207 * V_208 ,
struct V_209 * V_210 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_211 ;
int V_212 ;
switch ( V_208 -> V_213 ) {
case V_214 :
if ( F_120 ( V_2 ) || F_121 ( V_2 ) )
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
F_7 ( L_54 ) ;
return - V_217 ;
default:
F_122 () ;
}
V_4 -> V_218 . V_219 = false ;
V_212 = F_123 ( V_208 , V_211 , V_210 ) ;
if ( V_212 )
goto V_220;
V_212 = F_124 ( V_208 ) ;
if ( V_212 )
goto V_221;
F_125 ( V_208 ) ;
V_4 -> V_218 . V_219 = true ;
return 0 ;
V_221:
F_126 ( V_208 ) ;
V_220:
V_4 -> V_218 . V_219 = true ;
return V_212 ;
}
void F_127 ( struct V_207 * V_208 )
{
F_128 ( V_208 ) ;
F_126 ( V_208 ) ;
}
static unsigned long F_129 ( int * V_222 , int * V_223 ,
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
static int F_130 ( struct V_34 * V_35 , struct V_228 * V_229 ,
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
F_7 ( L_55 , V_148 ) ;
return - V_217 ;
}
V_231 = F_131 ( V_229 ) ;
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
F_7 ( L_56 , V_229 -> V_235 ) ;
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
F_129 ( & V_222 , & V_223 ,
V_229 -> V_235 / 8 ,
V_229 -> V_242 [ 0 ] ) ;
V_232 -= V_124 -> V_243 ;
} else {
V_124 -> V_243 = V_232 ;
}
F_40 ( L_57 ,
V_208 -> V_244 , V_232 , V_222 , V_223 , V_229 -> V_242 [ 0 ] ) ;
F_8 ( F_132 ( V_148 ) , V_229 -> V_242 [ 0 ] ) ;
if ( F_43 ( V_2 ) -> V_109 >= 4 ) {
F_133 ( F_115 ( V_148 ) ,
V_208 -> V_244 + V_124 -> V_243 ) ;
F_8 ( F_134 ( V_148 ) , ( V_223 << 16 ) | V_222 ) ;
F_8 ( F_135 ( V_148 ) , V_232 ) ;
} else
F_8 ( F_114 ( V_148 ) , V_208 -> V_244 + V_232 ) ;
F_12 ( V_8 ) ;
return 0 ;
}
static int F_136 ( struct V_34 * V_35 ,
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
F_7 ( L_55 , V_148 ) ;
return - V_217 ;
}
V_231 = F_131 ( V_229 ) ;
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
F_7 ( L_56 , V_229 -> V_235 ) ;
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
F_129 ( & V_222 , & V_223 ,
V_229 -> V_235 / 8 ,
V_229 -> V_242 [ 0 ] ) ;
V_232 -= V_124 -> V_243 ;
F_40 ( L_57 ,
V_208 -> V_244 , V_232 , V_222 , V_223 , V_229 -> V_242 [ 0 ] ) ;
F_8 ( F_132 ( V_148 ) , V_229 -> V_242 [ 0 ] ) ;
F_133 ( F_115 ( V_148 ) ,
V_208 -> V_244 + V_124 -> V_243 ) ;
F_8 ( F_134 ( V_148 ) , ( V_223 << 16 ) | V_222 ) ;
F_8 ( F_135 ( V_148 ) , V_232 ) ;
F_12 ( V_8 ) ;
return 0 ;
}
static int
F_137 ( struct V_34 * V_35 , struct V_228 * V_229 ,
int V_222 , int V_223 , enum V_247 V_119 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_248 . V_249 )
V_4 -> V_248 . V_249 ( V_2 ) ;
F_138 ( V_35 ) ;
return V_4 -> V_248 . V_250 ( V_35 , V_229 , V_222 , V_223 ) ;
}
static int
F_139 ( struct V_228 * V_251 )
{
struct V_207 * V_208 = F_131 ( V_251 ) -> V_208 ;
struct V_3 * V_4 = V_208 -> V_191 . V_2 -> V_5 ;
bool V_252 = V_4 -> V_218 . V_219 ;
int V_212 ;
F_140 ( V_4 -> V_253 ,
F_141 ( & V_4 -> V_218 . V_254 ) ||
F_141 ( & V_208 -> V_255 ) == 0 ) ;
V_4 -> V_218 . V_219 = false ;
V_212 = F_142 ( V_208 ) ;
V_4 -> V_218 . V_219 = V_252 ;
return V_212 ;
}
static int
F_143 ( struct V_34 * V_35 , int V_222 , int V_223 ,
struct V_228 * V_229 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_256 * V_257 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_228 * V_251 ;
int V_212 ;
if ( ! V_229 ) {
F_7 ( L_58 ) ;
return 0 ;
}
if( V_124 -> V_148 > V_4 -> V_258 ) {
F_7 ( L_59 ,
V_124 -> V_148 ,
V_4 -> V_258 ) ;
return - V_217 ;
}
F_144 ( & V_2 -> V_259 ) ;
V_212 = F_119 ( V_2 ,
F_131 ( V_229 ) -> V_208 ,
NULL ) ;
if ( V_212 != 0 ) {
F_145 ( & V_2 -> V_259 ) ;
F_7 ( L_60 ) ;
return V_212 ;
}
if ( V_35 -> V_229 )
F_139 ( V_35 -> V_229 ) ;
V_212 = V_4 -> V_248 . V_250 ( V_35 , V_229 , V_222 , V_223 ) ;
if ( V_212 ) {
F_127 ( F_131 ( V_229 ) -> V_208 ) ;
F_145 ( & V_2 -> V_259 ) ;
F_7 ( L_61 ) ;
return V_212 ;
}
V_251 = V_35 -> V_229 ;
V_35 -> V_229 = V_229 ;
V_35 -> V_222 = V_222 ;
V_35 -> V_223 = V_223 ;
if ( V_251 ) {
F_41 ( V_2 , V_124 -> V_105 ) ;
F_127 ( F_131 ( V_251 ) -> V_208 ) ;
}
F_146 ( V_2 ) ;
F_145 ( & V_2 -> V_259 ) ;
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
static void F_147 ( struct V_34 * V_35 , int clock )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_268 ;
F_40 ( L_62 , clock ) ;
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
static void F_148 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_8 , V_271 ;
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
if ( F_149 ( V_2 ) ) {
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
if ( F_149 ( V_2 ) )
F_8 ( V_8 , F_3 ( V_8 ) | V_280 |
V_281 ) ;
}
static void F_150 ( struct V_1 * V_2 , int V_105 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_9 = F_3 ( V_282 ) ;
V_9 |= F_151 ( V_105 ) ;
F_8 ( V_282 , V_9 ) ;
V_9 |= F_152 ( V_105 ) ;
F_8 ( V_282 , V_9 ) ;
F_12 ( V_282 ) ;
}
static void F_153 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_148 = V_124 -> V_148 ;
T_1 V_8 , V_271 , V_283 ;
F_117 ( V_4 , V_105 ) ;
F_154 ( V_4 , V_148 ) ;
V_8 = F_155 ( V_105 ) ;
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
F_8 ( F_156 ( V_105 ) , V_288 ) ;
F_8 ( F_156 ( V_105 ) , V_288 |
V_289 ) ;
}
V_8 = F_157 ( V_105 ) ;
for ( V_283 = 0 ; V_283 < 5 ; V_283 ++ ) {
V_271 = F_3 ( V_8 ) ;
F_40 ( L_63 , V_271 ) ;
if ( ( V_271 & V_285 ) ) {
F_40 ( L_64 ) ;
F_8 ( V_8 , V_271 | V_285 ) ;
break;
}
}
if ( V_283 == 5 )
F_7 ( L_65 ) ;
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
V_8 = F_157 ( V_105 ) ;
for ( V_283 = 0 ; V_283 < 5 ; V_283 ++ ) {
V_271 = F_3 ( V_8 ) ;
F_40 ( L_63 , V_271 ) ;
if ( V_271 & V_284 ) {
F_8 ( V_8 , V_271 | V_284 ) ;
F_40 ( L_66 ) ;
break;
}
}
if ( V_283 == 5 )
F_7 ( L_67 ) ;
F_40 ( L_68 ) ;
}
static void F_158 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_8 , V_271 , V_150 , V_291 ;
V_8 = F_155 ( V_105 ) ;
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
F_150 ( V_2 , V_105 ) ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_292 ;
V_271 |= V_295 [ V_150 ] ;
F_8 ( V_8 , V_271 ) ;
F_12 ( V_8 ) ;
F_93 ( 500 ) ;
for ( V_291 = 0 ; V_291 < 5 ; V_291 ++ ) {
V_8 = F_157 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
F_40 ( L_63 , V_271 ) ;
if ( V_271 & V_285 ) {
F_8 ( V_8 , V_271 | V_285 ) ;
F_40 ( L_64 ) ;
break;
}
F_93 ( 50 ) ;
}
if ( V_291 < 5 )
break;
}
if ( V_150 == 4 )
F_7 ( L_65 ) ;
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_276 ;
V_271 |= V_290 ;
if ( F_159 ( V_2 ) ) {
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
V_8 = F_157 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
F_40 ( L_63 , V_271 ) ;
if ( V_271 & V_284 ) {
F_8 ( V_8 , V_271 | V_284 ) ;
F_40 ( L_66 ) ;
break;
}
F_93 ( 50 ) ;
}
if ( V_291 < 5 )
break;
}
if ( V_150 == 4 )
F_7 ( L_67 ) ;
F_40 ( L_69 ) ;
}
static void F_160 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_8 , V_271 , V_150 ;
V_8 = F_155 ( V_105 ) ;
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
F_150 ( V_2 , V_105 ) ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
V_8 = F_61 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ V_292 ;
V_271 |= V_295 [ V_150 ] ;
F_8 ( V_8 , V_271 ) ;
F_12 ( V_8 ) ;
F_93 ( 500 ) ;
V_8 = F_157 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
F_40 ( L_63 , V_271 ) ;
if ( V_271 & V_285 ||
( F_3 ( V_8 ) & V_285 ) ) {
F_8 ( V_8 , V_271 | V_285 ) ;
F_40 ( L_64 ) ;
break;
}
}
if ( V_150 == 4 )
F_7 ( L_65 ) ;
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
V_8 = F_157 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
F_40 ( L_63 , V_271 ) ;
if ( V_271 & V_284 ) {
F_8 ( V_8 , V_271 | V_284 ) ;
F_40 ( L_66 ) ;
break;
}
}
if ( V_150 == 4 )
F_7 ( L_67 ) ;
F_40 ( L_69 ) ;
}
static void F_161 ( struct V_124 * V_124 )
{
struct V_1 * V_2 = V_124 -> V_191 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_105 = V_124 -> V_105 ;
T_1 V_8 , V_271 ;
F_8 ( F_162 ( V_105 ) ,
F_3 ( F_163 ( V_105 ) ) & V_301 ) ;
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
static void F_164 ( struct V_124 * V_124 )
{
struct V_1 * V_2 = V_124 -> V_191 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_105 = V_124 -> V_105 ;
T_1 V_8 , V_271 ;
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
}
static void F_165 ( struct V_1 * V_2 , int V_105 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_9 = F_3 ( V_282 ) ;
V_9 &= ~ ( F_152 ( V_105 ) ) ;
F_8 ( V_282 , V_9 ) ;
V_9 &= ~ ( F_151 ( V_105 ) ) ;
F_8 ( V_282 , V_9 ) ;
F_12 ( V_282 ) ;
}
static void F_166 ( struct V_34 * V_35 )
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
F_8 ( F_156 ( V_105 ) , V_288 ) ;
F_8 ( F_156 ( V_105 ) ,
F_3 ( F_156 ( V_105 ) &
~ V_289 ) ) ;
} else if ( F_57 ( V_2 ) ) {
F_165 ( V_2 , V_105 ) ;
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
static bool F_167 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_9 ;
bool V_303 ;
if ( F_141 ( & V_4 -> V_218 . V_254 ) )
return false ;
F_5 ( & V_2 -> V_304 , V_9 ) ;
V_303 = F_104 ( V_35 ) -> V_305 != NULL ;
F_9 ( & V_2 -> V_304 , V_9 ) ;
return V_303 ;
}
static void F_168 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_35 -> V_229 == NULL )
return;
F_140 ( V_4 -> V_253 ,
! F_167 ( V_35 ) ) ;
F_144 ( & V_2 -> V_259 ) ;
F_139 ( V_35 -> V_229 ) ;
F_145 ( & V_2 -> V_259 ) ;
}
static bool F_169 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_75 * V_75 ;
F_28 (dev, crtc, intel_encoder) {
if ( F_59 ( V_2 ) ) {
F_99 ( ! F_55 ( V_2 ) ) ;
if ( V_75 -> type == V_52 ) {
F_40 ( L_70 ) ;
return true ;
} else {
F_40 ( L_71 ,
V_75 -> type ) ;
return false ;
}
}
switch ( V_75 -> type ) {
case V_306 :
if ( ! F_170 ( & V_75 -> V_191 ) )
return false ;
continue;
}
}
return true ;
}
static void F_171 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_307 , V_308 , V_309 , V_310 = 0 ;
T_1 V_271 ;
F_8 ( V_311 , V_312 ) ;
F_96 ( V_4 , V_313 ,
F_97 ( V_4 , V_313 ) |
V_314 ) ;
if ( V_35 -> V_315 . clock == 20000 ) {
V_309 = 1 ;
V_307 = 0x41 ;
V_308 = 0x20 ;
} else {
T_1 V_316 = 172800 * 1000 ;
T_1 V_317 = 64 ;
T_1 V_318 , V_319 , V_320 ;
V_318 = ( V_316 / V_35 -> V_315 . clock ) ;
V_319 = V_318 / V_317 ;
V_320 = V_318 % V_317 ;
V_309 = 0 ;
V_307 = V_319 - 2 ;
V_308 = V_320 ;
}
F_99 ( F_172 ( V_307 ) &
~ V_321 ) ;
F_99 ( F_173 ( V_310 ) &
~ V_322 ) ;
F_40 ( L_72 ,
V_35 -> V_315 . clock ,
V_309 ,
V_307 ,
V_310 ,
V_308 ) ;
V_271 = F_97 ( V_4 , V_323 ) ;
V_271 &= ~ V_321 ;
V_271 |= F_172 ( V_307 ) ;
V_271 &= ~ V_322 ;
V_271 |= F_174 ( V_308 ) ;
V_271 |= F_173 ( V_310 ) ;
V_271 |= V_324 ;
F_96 ( V_4 ,
V_323 ,
V_271 ) ;
V_271 = F_97 ( V_4 , V_325 ) ;
V_271 &= ~ F_175 ( 1 ) ;
V_271 |= F_175 ( V_309 ) ;
F_96 ( V_4 ,
V_325 ,
V_271 ) ;
V_271 = F_97 ( V_4 , V_313 ) ;
V_271 &= ~ V_314 ;
F_96 ( V_4 ,
V_313 ,
V_271 ) ;
F_93 ( 24 ) ;
F_8 ( V_311 , V_326 ) ;
}
static void F_176 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_8 , V_271 ;
F_74 ( V_4 , V_105 ) ;
V_4 -> V_248 . V_327 ( V_35 ) ;
F_98 ( V_124 ) ;
if ( F_55 ( V_2 ) ) {
F_40 ( L_73 ) ;
F_171 ( V_35 ) ;
} else if ( F_57 ( V_2 ) ) {
T_1 V_328 ;
V_271 = F_3 ( V_127 ) ;
switch ( V_105 ) {
default:
case 0 :
V_271 |= V_329 ;
V_328 = V_330 ;
break;
case 1 :
V_271 |= V_331 ;
V_328 = V_332 ;
break;
case 2 :
V_271 |= V_333 ;
V_328 = V_334 ;
break;
}
if ( V_124 -> V_192 -> V_125 == V_128 )
V_271 |= V_328 ;
else
V_271 &= ~ V_328 ;
F_8 ( V_127 , V_271 ) ;
}
F_66 ( V_4 , V_105 ) ;
F_8 ( F_177 ( V_105 ) , F_3 ( F_178 ( V_105 ) ) ) ;
F_8 ( F_179 ( V_105 ) , F_3 ( F_180 ( V_105 ) ) ) ;
F_8 ( F_181 ( V_105 ) , F_3 ( F_182 ( V_105 ) ) ) ;
F_8 ( F_183 ( V_105 ) , F_3 ( F_184 ( V_105 ) ) ) ;
F_8 ( F_185 ( V_105 ) , F_3 ( F_186 ( V_105 ) ) ) ;
F_8 ( F_187 ( V_105 ) , F_3 ( F_188 ( V_105 ) ) ) ;
F_8 ( F_189 ( V_105 ) , F_3 ( F_190 ( V_105 ) ) ) ;
if ( ! F_59 ( V_2 ) )
F_148 ( V_35 ) ;
if ( F_57 ( V_2 ) &&
( F_18 ( V_35 , V_44 ) ||
F_18 ( V_35 , V_306 ) ) ) {
T_1 V_335 = ( F_3 ( F_45 ( V_105 ) ) & V_198 ) >> 5 ;
V_8 = F_77 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ ( V_163 |
V_336 |
V_337 ) ;
V_271 |= ( V_338 |
V_339 ) ;
V_271 |= V_335 << 9 ;
if ( V_35 -> V_315 . V_9 & V_340 )
V_271 |= V_341 ;
if ( V_35 -> V_315 . V_9 & V_342 )
V_271 |= V_343 ;
switch ( F_191 ( V_35 ) ) {
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
F_40 ( L_74 ) ;
V_271 |= V_174 ;
break;
}
F_8 ( V_8 , V_271 ) ;
}
F_103 ( V_4 , V_105 ) ;
}
static void F_192 ( struct V_124 * V_124 )
{
struct V_122 * V_123 = V_124 -> V_192 ;
if ( V_123 == NULL )
return;
if ( V_123 -> V_193 == 0 ) {
F_46 ( 1 , L_75 ) ;
return;
}
-- V_123 -> V_193 ;
V_124 -> V_192 = NULL ;
}
static struct V_122 * F_193 ( struct V_124 * V_124 , T_1 V_344 , T_1 V_345 )
{
struct V_3 * V_4 = V_124 -> V_191 . V_2 -> V_5 ;
struct V_122 * V_123 ;
int V_150 ;
V_123 = V_124 -> V_192 ;
if ( V_123 ) {
F_40 ( L_76 ,
V_124 -> V_191 . V_191 . V_24 , V_123 -> V_125 ) ;
goto V_346;
}
if ( F_86 ( V_4 -> V_2 ) ) {
V_150 = V_124 -> V_105 ;
V_123 = & V_4 -> V_347 [ V_150 ] ;
F_40 ( L_77 ,
V_124 -> V_191 . V_191 . V_24 , V_123 -> V_125 ) ;
goto V_88;
}
for ( V_150 = 0 ; V_150 < V_4 -> V_348 ; V_150 ++ ) {
V_123 = & V_4 -> V_347 [ V_150 ] ;
if ( V_123 -> V_193 == 0 )
continue;
if ( V_344 == ( F_3 ( V_123 -> V_125 ) & 0x7fffffff ) &&
V_345 == F_3 ( V_123 -> V_349 ) ) {
F_40 ( L_78 ,
V_124 -> V_191 . V_191 . V_24 ,
V_123 -> V_125 , V_123 -> V_193 , V_123 -> V_194 ) ;
goto V_88;
}
}
for ( V_150 = 0 ; V_150 < V_4 -> V_348 ; V_150 ++ ) {
V_123 = & V_4 -> V_347 [ V_150 ] ;
if ( V_123 -> V_193 == 0 ) {
F_40 ( L_79 ,
V_124 -> V_191 . V_191 . V_24 , V_123 -> V_125 ) ;
goto V_88;
}
}
return NULL ;
V_88:
V_124 -> V_192 = V_123 ;
V_123 -> V_193 ++ ;
F_56 ( L_80 , V_150 , V_124 -> V_105 ) ;
V_346:
F_56 ( L_81 , V_123 -> V_125 ) ;
F_8 ( V_123 -> V_125 , V_344 & ~ V_121 ) ;
F_12 ( V_123 -> V_125 ) ;
F_93 ( 150 ) ;
F_8 ( V_123 -> V_349 , V_345 ) ;
F_8 ( V_123 -> V_125 , V_344 & ~ V_121 ) ;
V_123 -> V_195 = false ;
return V_123 ;
}
void F_194 ( struct V_1 * V_2 , int V_105 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_350 = F_47 ( V_105 ) , V_351 = F_195 ( V_105 ) ;
T_1 V_271 ;
V_271 = F_3 ( V_350 ) ;
F_93 ( 500 ) ;
if ( F_38 ( F_3 ( V_350 ) != V_271 , 5 ) ) {
F_8 ( V_351 , V_352 ) ;
F_93 ( 250 ) ;
F_8 ( V_351 , 0 ) ;
if ( F_38 ( F_3 ( V_350 ) != V_271 , 5 ) )
F_7 ( L_82 , V_105 ) ;
}
}
static void F_196 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_75 * V_76 ;
int V_105 = V_124 -> V_105 ;
int V_148 = V_124 -> V_148 ;
T_1 V_271 ;
bool V_353 ;
F_99 ( ! V_35 -> V_118 ) ;
if ( V_124 -> V_194 )
return;
V_124 -> V_194 = true ;
F_197 ( V_2 ) ;
if ( F_18 ( V_35 , V_38 ) ) {
V_271 = F_3 ( V_39 ) ;
if ( ( V_271 & V_168 ) == 0 )
F_8 ( V_39 , V_271 | V_168 ) ;
}
V_353 = F_169 ( V_35 ) ;
if ( V_353 ) {
F_161 ( V_124 ) ;
} else {
F_108 ( V_4 , V_105 ) ;
F_109 ( V_4 , V_105 ) ;
}
F_28 (dev, crtc, encoder)
if ( V_76 -> V_354 )
V_76 -> V_354 ( V_76 ) ;
if ( V_4 -> V_355 &&
( F_18 ( V_35 , V_38 ) || V_45 ) ) {
F_8 ( F_198 ( V_105 ) , V_356 | V_357 ) ;
F_8 ( F_199 ( V_105 ) , V_4 -> V_358 ) ;
F_8 ( F_200 ( V_105 ) , V_4 -> V_355 ) ;
}
F_201 ( V_35 ) ;
F_110 ( V_4 , V_105 , V_353 ) ;
F_116 ( V_4 , V_148 , V_105 ) ;
if ( V_353 )
F_176 ( V_35 ) ;
F_144 ( & V_2 -> V_259 ) ;
F_146 ( V_2 ) ;
F_145 ( & V_2 -> V_259 ) ;
F_202 ( V_35 , true ) ;
F_28 (dev, crtc, encoder)
V_76 -> V_359 ( V_76 ) ;
if ( F_57 ( V_2 ) )
F_194 ( V_2 , V_124 -> V_105 ) ;
F_41 ( V_2 , V_124 -> V_105 ) ;
}
static void F_203 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_75 * V_76 ;
int V_105 = V_124 -> V_105 ;
int V_148 = V_124 -> V_148 ;
T_1 V_8 , V_271 ;
if ( ! V_124 -> V_194 )
return;
F_28 (dev, crtc, encoder)
V_76 -> V_360 ( V_76 ) ;
F_168 ( V_35 ) ;
F_204 ( V_2 , V_105 ) ;
F_202 ( V_35 , false ) ;
F_118 ( V_4 , V_148 , V_105 ) ;
if ( V_4 -> V_361 == V_148 )
F_205 ( V_2 ) ;
F_112 ( V_4 , V_105 ) ;
F_8 ( F_198 ( V_105 ) , 0 ) ;
F_8 ( F_200 ( V_105 ) , 0 ) ;
F_28 (dev, crtc, encoder)
if ( V_76 -> V_362 )
V_76 -> V_362 ( V_76 ) ;
F_166 ( V_35 ) ;
F_107 ( V_4 , V_105 ) ;
if ( F_57 ( V_2 ) ) {
V_8 = F_77 ( V_105 ) ;
V_271 = F_3 ( V_8 ) ;
V_271 &= ~ ( V_338 | V_163 ) ;
V_271 |= V_363 ;
F_8 ( V_8 , V_271 ) ;
V_271 = F_3 ( V_127 ) ;
switch ( V_105 ) {
case 0 :
V_271 &= ~ ( V_329 | V_330 ) ;
break;
case 1 :
V_271 &= ~ ( V_331 | V_332 ) ;
break;
case 2 :
V_271 &= ~ ( V_333 | V_334 ) ;
break;
default:
F_122 () ;
}
F_8 ( V_127 , V_271 ) ;
}
F_101 ( V_124 ) ;
F_164 ( V_124 ) ;
V_124 -> V_194 = false ;
F_197 ( V_2 ) ;
F_144 ( & V_2 -> V_259 ) ;
F_146 ( V_2 ) ;
F_145 ( & V_2 -> V_259 ) ;
}
static void F_206 ( struct V_34 * V_35 )
{
struct V_124 * V_124 = F_104 ( V_35 ) ;
F_192 ( V_124 ) ;
}
static void F_207 ( struct V_124 * V_124 , bool V_359 )
{
if ( ! V_359 && V_124 -> V_364 ) {
struct V_1 * V_2 = V_124 -> V_191 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_144 ( & V_2 -> V_259 ) ;
V_4 -> V_218 . V_219 = false ;
( void ) F_208 ( V_124 -> V_364 ) ;
V_4 -> V_218 . V_219 = true ;
F_145 ( & V_2 -> V_259 ) ;
}
}
static void F_209 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_75 * V_76 ;
int V_105 = V_124 -> V_105 ;
int V_148 = V_124 -> V_148 ;
F_99 ( ! V_35 -> V_118 ) ;
if ( V_124 -> V_194 )
return;
V_124 -> V_194 = true ;
F_197 ( V_2 ) ;
F_89 ( V_4 , V_105 ) ;
F_110 ( V_4 , V_105 , false ) ;
F_116 ( V_4 , V_148 , V_105 ) ;
F_201 ( V_35 ) ;
F_146 ( V_2 ) ;
F_207 ( V_124 , true ) ;
F_202 ( V_35 , true ) ;
F_28 (dev, crtc, encoder)
V_76 -> V_359 ( V_76 ) ;
}
static void F_210 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_75 * V_76 ;
int V_105 = V_124 -> V_105 ;
int V_148 = V_124 -> V_148 ;
if ( ! V_124 -> V_194 )
return;
F_28 (dev, crtc, encoder)
V_76 -> V_360 ( V_76 ) ;
F_168 ( V_35 ) ;
F_204 ( V_2 , V_105 ) ;
F_207 ( V_124 , false ) ;
F_202 ( V_35 , false ) ;
if ( V_4 -> V_361 == V_148 )
F_205 ( V_2 ) ;
F_118 ( V_4 , V_148 , V_105 ) ;
F_112 ( V_4 , V_105 ) ;
F_94 ( V_4 , V_105 ) ;
V_124 -> V_194 = false ;
F_146 ( V_2 ) ;
F_197 ( V_2 ) ;
}
static void F_211 ( struct V_34 * V_35 )
{
}
static void F_212 ( struct V_34 * V_35 ,
bool V_118 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_256 * V_257 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
if ( ! V_2 -> V_260 -> V_261 )
return;
V_257 = V_2 -> V_260 -> V_261 -> V_262 ;
if ( ! V_257 -> V_263 )
return;
switch ( V_105 ) {
case 0 :
V_257 -> V_263 -> V_365 = V_118 ? V_35 -> V_315 . V_366 : 0 ;
V_257 -> V_263 -> V_367 = V_118 ? V_35 -> V_315 . V_368 : 0 ;
break;
case 1 :
V_257 -> V_263 -> V_369 = V_118 ? V_35 -> V_315 . V_366 : 0 ;
V_257 -> V_263 -> V_370 = V_118 ? V_35 -> V_315 . V_368 : 0 ;
break;
default:
F_7 ( L_83 , F_67 ( V_105 ) ) ;
break;
}
}
void F_213 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_75 * V_75 ;
bool V_359 = false ;
F_28 (dev, crtc, intel_encoder)
V_359 |= V_75 -> V_371 ;
if ( V_359 )
V_4 -> V_248 . V_372 ( V_35 ) ;
else
V_4 -> V_248 . V_373 ( V_35 ) ;
F_212 ( V_35 , V_359 ) ;
}
static void F_214 ( struct V_34 * V_35 )
{
}
static void F_215 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_374 * V_375 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_99 ( ! V_35 -> V_118 ) ;
V_4 -> V_248 . V_373 ( V_35 ) ;
F_212 ( V_35 , false ) ;
V_4 -> V_248 . V_376 ( V_35 ) ;
F_216 ( V_2 -> V_5 , F_104 ( V_35 ) -> V_148 ) ;
F_95 ( V_2 -> V_5 , F_104 ( V_35 ) -> V_105 ) ;
if ( V_35 -> V_229 ) {
F_144 ( & V_2 -> V_259 ) ;
F_127 ( F_131 ( V_35 -> V_229 ) -> V_208 ) ;
F_145 ( & V_2 -> V_259 ) ;
V_35 -> V_229 = NULL ;
}
F_217 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_375 -> V_76 || ! V_375 -> V_76 -> V_35 )
continue;
if ( V_375 -> V_76 -> V_35 != V_35 )
continue;
V_375 -> V_377 = V_378 ;
F_218 ( V_375 -> V_76 ) -> V_371 = false ;
}
}
void F_219 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
F_217 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_35 -> V_118 )
F_215 ( V_35 ) ;
}
}
void F_220 ( struct V_379 * V_76 )
{
}
void F_221 ( struct V_379 * V_76 )
{
struct V_75 * V_75 = F_218 ( V_76 ) ;
F_222 ( V_76 ) ;
F_223 ( V_75 ) ;
}
void F_224 ( struct V_75 * V_76 , int V_315 )
{
if ( V_315 == V_380 ) {
V_76 -> V_371 = true ;
F_213 ( V_76 -> V_191 . V_35 ) ;
} else {
V_76 -> V_371 = false ;
F_213 ( V_76 -> V_191 . V_35 ) ;
}
}
static void F_225 ( struct V_381 * V_375 )
{
if ( V_375 -> V_382 ( V_375 ) ) {
struct V_75 * V_76 = V_375 -> V_76 ;
struct V_34 * V_35 ;
bool V_383 ;
enum V_105 V_105 ;
F_40 ( L_84 ,
V_375 -> V_191 . V_191 . V_24 ,
F_226 ( & V_375 -> V_191 ) ) ;
F_46 ( V_375 -> V_191 . V_377 == V_378 ,
L_85 ) ;
F_46 ( V_375 -> V_191 . V_76 != & V_76 -> V_191 ,
L_86 ) ;
F_46 ( ! V_76 -> V_371 ,
L_87 ) ;
V_383 = V_76 -> V_382 ( V_76 , & V_105 ) ;
F_46 ( ! V_383 , L_88 ) ;
if ( F_99 ( ! V_76 -> V_191 . V_35 ) )
return;
V_35 = V_76 -> V_191 . V_35 ;
F_46 ( ! V_35 -> V_118 , L_89 ) ;
F_46 ( ! F_104 ( V_35 ) -> V_194 , L_90 ) ;
F_46 ( V_105 != F_104 ( V_35 ) -> V_105 ,
L_91 ) ;
}
}
void F_227 ( struct V_374 * V_375 , int V_315 )
{
struct V_75 * V_76 = F_228 ( V_375 ) ;
if ( V_315 != V_380 )
V_315 = V_378 ;
if ( V_315 == V_375 -> V_377 )
return;
V_375 -> V_377 = V_315 ;
if ( V_76 -> V_191 . V_35 )
F_224 ( V_76 , V_315 ) ;
else
F_99 ( V_76 -> V_371 != false ) ;
F_229 ( V_375 -> V_2 ) ;
}
bool F_230 ( struct V_381 * V_375 )
{
enum V_105 V_105 = 0 ;
struct V_75 * V_76 = V_375 -> V_76 ;
return V_76 -> V_382 ( V_76 , & V_105 ) ;
}
static bool F_231 ( struct V_34 * V_35 ,
const struct V_384 * V_315 ,
struct V_384 * V_385 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
if ( F_21 ( V_2 ) ) {
if ( V_315 -> clock * 3 > V_386 * 4 )
return false ;
}
if ( ! ( V_385 -> V_387 & V_388 ) )
F_232 ( V_385 , 0 ) ;
if ( ( F_43 ( V_2 ) -> V_109 > 4 || F_22 ( V_2 ) ) &&
V_385 -> V_389 == V_385 -> V_366 )
return false ;
return true ;
}
static int F_233 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_234 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_235 ( struct V_1 * V_2 )
{
return 333000 ;
}
static int F_236 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_237 ( struct V_1 * V_2 )
{
T_4 V_390 = 0 ;
F_238 ( V_2 -> V_391 , V_392 , & V_390 ) ;
if ( V_390 & V_393 )
return 133000 ;
else {
switch ( V_390 & V_394 ) {
case V_395 :
return 333000 ;
default:
case V_396 :
return 190000 ;
}
}
}
static int F_239 ( struct V_1 * V_2 )
{
return 266000 ;
}
static int F_240 ( struct V_1 * V_2 )
{
T_4 V_397 = 0 ;
switch ( V_397 & V_398 ) {
case V_399 :
case V_400 :
return 200000 ;
case V_401 :
return 250000 ;
case V_402 :
return 133000 ;
}
return 0 ;
}
static int F_241 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_242 ( T_1 * V_403 , T_1 * V_404 )
{
while ( * V_403 > 0xffffff || * V_404 > 0xffffff ) {
* V_403 >>= 1 ;
* V_404 >>= 1 ;
}
}
static void
F_243 ( int V_235 , int V_405 , int V_406 ,
int V_407 , struct V_408 * V_409 )
{
V_409 -> V_410 = 64 ;
V_409 -> V_411 = V_235 * V_406 ;
V_409 -> V_412 = V_407 * V_405 * 8 ;
F_242 ( & V_409 -> V_411 , & V_409 -> V_412 ) ;
V_409 -> V_413 = V_406 ;
V_409 -> V_414 = V_407 ;
F_242 ( & V_409 -> V_413 , & V_409 -> V_414 ) ;
}
static inline bool F_244 ( struct V_3 * V_4 )
{
if ( V_415 >= 0 )
return V_415 != 0 ;
return V_4 -> V_416
&& ! ( V_4 -> V_145 & V_417 ) ;
}
static bool F_245 ( struct V_34 * V_35 ,
struct V_228 * V_229 ,
unsigned int * V_418 ,
struct V_384 * V_315 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_374 * V_375 ;
struct V_75 * V_75 ;
unsigned int V_419 = V_420 , V_335 ;
F_28 (dev, crtc, intel_encoder) {
if ( V_75 -> type == V_38 ) {
unsigned int V_421 ;
if ( ( F_3 ( V_39 ) & V_422 ) ==
V_423 )
V_421 = 8 ;
else
V_421 = 6 ;
if ( V_421 < V_419 ) {
F_40 ( L_92 , V_419 , V_421 ) ;
V_419 = V_421 ;
}
continue;
}
F_217 (connector, &dev->mode_config.connector_list,
head) {
if ( V_375 -> V_76 != & V_75 -> V_191 )
continue;
if ( V_375 -> V_424 . V_335 &&
V_375 -> V_424 . V_335 < V_419 ) {
F_40 ( L_93 , V_419 , V_375 -> V_424 . V_335 ) ;
V_419 = V_375 -> V_424 . V_335 ;
}
}
if ( V_75 -> type == V_306 ) {
unsigned int V_425 = V_4 -> V_426 . V_224 / 3 ;
if ( V_425 && V_425 < V_419 ) {
F_40 ( L_94 , V_419 , V_425 ) ;
V_419 = V_425 ;
}
continue;
}
if ( V_75 -> type == V_51 ) {
if ( V_419 > 8 && V_419 < 12 ) {
F_40 ( L_95 ) ;
V_419 = 12 ;
} else {
F_40 ( L_96 ) ;
V_419 = 8 ;
}
}
}
if ( V_315 -> V_387 & V_427 ) {
F_40 ( L_97 ) ;
V_419 = 6 ;
}
switch ( V_229 -> V_237 ) {
case 8 :
V_335 = 8 ;
break;
case 15 :
case 16 :
V_335 = 6 ;
break;
case 24 :
V_335 = 8 ;
break;
case 30 :
V_335 = 10 ;
break;
case 48 :
V_335 = 12 ;
break;
default:
F_246 ( L_98 ) ;
V_335 = V_77 ( ( unsigned int ) 8 , V_419 ) ;
break;
}
V_419 = V_77 ( V_419 , V_335 ) ;
F_40 ( L_99 ,
V_335 , V_419 ) ;
* V_418 = V_419 * 3 ;
return V_419 != V_335 ;
}
static int F_247 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_36 = 27000 ;
return 100000 ;
if ( F_18 ( V_35 , V_52 ) ) {
V_36 = 96000 ;
} else if ( F_18 ( V_35 , V_38 ) ) {
if ( F_244 ( V_4 ) )
V_36 = 100000 ;
else
V_36 = 96000 ;
} else if ( F_18 ( V_35 , V_306 ) ) {
V_36 = 100000 ;
}
return V_36 ;
}
static int F_248 ( struct V_34 * V_35 , int V_428 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_36 ;
if ( F_24 ( V_2 ) ) {
V_36 = F_247 ( V_35 ) ;
} else if ( F_18 ( V_35 , V_38 ) &&
F_244 ( V_4 ) && V_428 < 2 ) {
V_36 = V_4 -> V_429 * 1000 ;
F_40 ( L_100 ,
V_36 / 1000 ) ;
} else if ( ! F_25 ( V_2 ) ) {
V_36 = 96000 ;
} else {
V_36 = 48000 ;
}
return V_36 ;
}
static void F_249 ( struct V_384 * V_385 ,
T_3 * clock )
{
if ( V_385 -> clock >= 100000
&& V_385 -> clock < 140500 ) {
clock -> V_69 = 2 ;
clock -> V_70 = 10 ;
clock -> V_72 = 3 ;
clock -> V_74 = 16 ;
clock -> V_67 = 8 ;
} else if ( V_385 -> clock >= 140500
&& V_385 -> clock <= 200000 ) {
clock -> V_69 = 1 ;
clock -> V_70 = 10 ;
clock -> V_72 = 6 ;
clock -> V_74 = 12 ;
clock -> V_67 = 8 ;
}
}
static void F_250 ( struct V_34 * V_35 ,
T_3 * clock ,
T_3 * V_430 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_345 , V_431 = 0 ;
if ( F_23 ( V_2 ) ) {
V_345 = ( 1 << clock -> V_72 ) << 16 | clock -> V_74 << 8 | clock -> V_67 ;
if ( V_430 )
V_431 = ( 1 << V_430 -> V_72 ) << 16 |
V_430 -> V_74 << 8 | V_430 -> V_67 ;
} else {
V_345 = clock -> V_72 << 16 | clock -> V_74 << 8 | clock -> V_67 ;
if ( V_430 )
V_431 = V_430 -> V_72 << 16 | V_430 -> V_74 << 8 |
V_430 -> V_67 ;
}
F_8 ( F_251 ( V_105 ) , V_345 ) ;
V_124 -> V_432 = false ;
if ( F_18 ( V_35 , V_38 ) &&
V_430 && V_433 ) {
F_8 ( F_252 ( V_105 ) , V_431 ) ;
V_124 -> V_432 = true ;
} else {
F_8 ( F_252 ( V_105 ) , V_345 ) ;
}
}
static void F_253 ( struct V_34 * V_35 , T_3 * clock ,
struct V_384 * V_385 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_271 ;
V_271 = F_3 ( V_48 ) ;
V_271 |= V_168 | V_434 ;
if ( V_105 == 1 ) {
V_271 |= V_143 ;
} else {
V_271 &= ~ V_143 ;
}
V_271 |= V_4 -> V_435 ;
if ( clock -> V_70 == 7 )
V_271 |= V_436 | V_33 ;
else
V_271 &= ~ ( V_436 | V_33 ) ;
if ( F_43 ( V_2 ) -> V_109 >= 4 ) {
if ( V_4 -> V_437 )
V_271 |= V_438 ;
else
V_271 &= ~ V_438 ;
}
V_271 &= ~ ( V_439 | V_440 ) ;
if ( V_385 -> V_9 & V_441 )
V_271 |= V_439 ;
if ( V_385 -> V_9 & V_442 )
V_271 |= V_440 ;
F_8 ( V_48 , V_271 ) ;
}
static void F_254 ( struct V_34 * V_35 ,
struct V_384 * V_315 ,
struct V_384 * V_385 ,
T_3 * clock , T_3 * V_430 ,
int V_36 , int V_428 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_344 , V_443 , V_444 ;
T_1 V_91 , V_92 , V_93 , V_94 , V_95 ;
bool V_445 ;
V_445 = F_18 ( V_35 , V_51 ) ;
V_91 = clock -> V_72 ;
V_92 = clock -> V_74 ;
V_93 = clock -> V_67 ;
V_94 = clock -> V_69 ;
V_95 = clock -> V_70 ;
V_344 = V_446 | V_447 |
V_448 | V_449 ;
F_8 ( F_53 ( V_105 ) , V_344 ) ;
F_12 ( F_53 ( V_105 ) ) ;
V_443 = ( ( V_92 << V_450 ) | ( V_93 & V_451 ) ) ;
V_443 |= ( ( V_94 << V_452 ) | ( V_95 << V_453 ) ) ;
V_443 |= ( ( V_91 << V_454 ) ) ;
V_443 |= ( 1 << V_455 ) ;
V_443 |= ( 1 << V_456 ) ;
V_443 |= V_457 ;
F_10 ( V_4 , F_255 ( V_105 ) , V_443 ) ;
F_10 ( V_4 , F_256 ( V_105 ) , 0x01000000 ) ;
V_444 = V_458 | ( 5 << V_459 ) |
( 3 << V_460 ) | ( 1 << 20 ) |
( 8 << V_461 ) | ( 5 << V_462 ) ;
F_10 ( V_4 , F_257 ( V_105 ) , V_444 ) ;
F_10 ( V_4 , F_258 ( V_105 ) , 0x009f0051 ) ;
V_344 |= V_121 ;
F_8 ( F_53 ( V_105 ) , V_344 ) ;
F_12 ( F_53 ( V_105 ) ) ;
if ( F_38 ( ( ( F_3 ( F_53 ( V_105 ) ) & V_463 ) == V_463 ) , 1 ) )
F_7 ( L_101 , V_105 ) ;
if ( V_445 ) {
T_1 V_271 = F_259 ( V_385 ) ;
if ( V_271 > 1 )
V_271 = ( V_271 - 1 ) << V_464 ;
else
V_271 = 0 ;
F_8 ( F_260 ( V_105 ) , V_271 ) ;
F_12 ( F_260 ( V_105 ) ) ;
}
F_10 ( V_4 , V_465 , 0x641 ) ;
}
static void F_261 ( struct V_34 * V_35 ,
struct V_384 * V_315 ,
struct V_384 * V_385 ,
T_3 * clock , T_3 * V_430 ,
int V_428 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_344 ;
bool V_466 ;
V_466 = F_18 ( V_35 , V_54 ) ||
F_18 ( V_35 , V_51 ) ;
V_344 = V_448 ;
if ( F_18 ( V_35 , V_38 ) )
V_344 |= V_467 ;
else
V_344 |= V_468 ;
if ( V_466 ) {
int V_469 = F_259 ( V_385 ) ;
if ( V_469 > 1 ) {
if ( F_262 ( V_2 ) || F_263 ( V_2 ) || F_264 ( V_2 ) )
V_344 |= ( V_469 - 1 ) << V_470 ;
}
V_344 |= V_471 ;
}
if ( F_18 ( V_35 , V_44 ) )
V_344 |= V_471 ;
if ( F_23 ( V_2 ) )
V_344 |= ( 1 << ( clock -> V_69 - 1 ) ) << V_472 ;
else {
V_344 |= ( 1 << ( clock -> V_69 - 1 ) ) << V_473 ;
if ( F_22 ( V_2 ) && V_430 )
V_344 |= ( 1 << ( V_430 -> V_69 - 1 ) ) << V_474 ;
}
switch ( clock -> V_70 ) {
case 5 :
V_344 |= V_475 ;
break;
case 7 :
V_344 |= V_476 ;
break;
case 10 :
V_344 |= V_477 ;
break;
case 14 :
V_344 |= V_478 ;
break;
}
if ( F_43 ( V_2 ) -> V_109 >= 4 )
V_344 |= ( 6 << V_479 ) ;
if ( V_466 && F_18 ( V_35 , V_480 ) )
V_344 |= V_481 ;
else if ( F_18 ( V_35 , V_480 ) )
V_344 |= 3 ;
else if ( F_18 ( V_35 , V_38 ) &&
F_244 ( V_4 ) && V_428 < 2 )
V_344 |= V_482 ;
else
V_344 |= V_483 ;
V_344 |= V_121 ;
F_8 ( F_53 ( V_105 ) , V_344 & ~ V_121 ) ;
F_12 ( F_53 ( V_105 ) ) ;
F_93 ( 150 ) ;
if ( F_18 ( V_35 , V_38 ) )
F_253 ( V_35 , clock , V_385 ) ;
if ( F_18 ( V_35 , V_44 ) )
F_265 ( V_35 , V_315 , V_385 ) ;
F_8 ( F_53 ( V_105 ) , V_344 ) ;
F_12 ( F_53 ( V_105 ) ) ;
F_93 ( 150 ) ;
if ( F_43 ( V_2 ) -> V_109 >= 4 ) {
T_1 V_271 = 0 ;
if ( V_466 ) {
V_271 = F_259 ( V_385 ) ;
if ( V_271 > 1 )
V_271 = ( V_271 - 1 ) << V_464 ;
else
V_271 = 0 ;
}
F_8 ( F_260 ( V_105 ) , V_271 ) ;
} else {
F_8 ( F_53 ( V_105 ) , V_344 ) ;
}
}
static void F_266 ( struct V_34 * V_35 ,
struct V_384 * V_385 ,
T_3 * clock ,
int V_428 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_344 ;
V_344 = V_448 ;
if ( F_18 ( V_35 , V_38 ) ) {
V_344 |= ( 1 << ( clock -> V_69 - 1 ) ) << V_473 ;
} else {
if ( clock -> V_69 == 2 )
V_344 |= V_484 ;
else
V_344 |= ( clock -> V_69 - 2 ) << V_473 ;
if ( clock -> V_70 == 4 )
V_344 |= V_485 ;
}
if ( F_18 ( V_35 , V_480 ) )
V_344 |= 3 ;
else if ( F_18 ( V_35 , V_38 ) &&
F_244 ( V_4 ) && V_428 < 2 )
V_344 |= V_482 ;
else
V_344 |= V_483 ;
V_344 |= V_121 ;
F_8 ( F_53 ( V_105 ) , V_344 & ~ V_121 ) ;
F_12 ( F_53 ( V_105 ) ) ;
F_93 ( 150 ) ;
if ( F_18 ( V_35 , V_38 ) )
F_253 ( V_35 , clock , V_385 ) ;
F_8 ( F_53 ( V_105 ) , V_344 ) ;
F_12 ( F_53 ( V_105 ) ) ;
F_93 ( 150 ) ;
F_8 ( F_53 ( V_105 ) , V_344 ) ;
}
static int F_267 ( struct V_34 * V_35 ,
struct V_384 * V_315 ,
struct V_384 * V_385 ,
int V_222 , int V_223 ,
struct V_228 * V_229 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_148 = V_124 -> V_148 ;
int V_36 , V_428 = 0 ;
T_3 clock , V_430 ;
T_1 V_233 , V_486 , V_487 ;
bool V_488 , V_489 = false , V_466 = false ;
bool V_490 = false , V_491 = false , V_492 = false ;
struct V_75 * V_76 ;
const T_2 * V_37 ;
int V_212 ;
F_28 (dev, crtc, encoder) {
switch ( V_76 -> type ) {
case V_38 :
V_490 = true ;
break;
case V_54 :
case V_51 :
V_466 = true ;
if ( V_76 -> V_493 )
V_491 = true ;
break;
case V_480 :
V_491 = true ;
break;
case V_44 :
V_492 = true ;
break;
}
V_428 ++ ;
}
V_36 = F_248 ( V_35 , V_428 ) ;
V_37 = F_20 ( V_35 , V_36 ) ;
V_488 = V_37 -> V_494 ( V_37 , V_35 , V_385 -> clock , V_36 , NULL ,
& clock ) ;
if ( ! V_488 ) {
F_7 ( L_102 ) ;
return - V_217 ;
}
F_202 ( V_35 , true ) ;
if ( V_490 && V_4 -> V_495 ) {
V_489 = V_37 -> V_494 ( V_37 , V_35 ,
V_4 -> V_496 ,
V_36 ,
& clock ,
& V_430 ) ;
}
if ( V_466 && V_491 )
F_249 ( V_385 , & clock ) ;
F_250 ( V_35 , & clock , V_489 ?
& V_430 : NULL ) ;
if ( F_25 ( V_2 ) )
F_266 ( V_35 , V_385 , & clock , V_428 ) ;
else if ( F_24 ( V_2 ) )
F_254 ( V_35 , V_315 , V_385 , & clock , NULL ,
V_36 , V_428 ) ;
else
F_261 ( V_35 , V_315 , V_385 , & clock ,
V_489 ? & V_430 : NULL ,
V_428 ) ;
V_486 = F_3 ( F_45 ( V_105 ) ) ;
V_233 = V_497 ;
if ( V_105 == 0 )
V_233 &= ~ V_152 ;
else
V_233 |= V_498 ;
if ( V_105 == 0 && F_43 ( V_2 ) -> V_109 < 4 ) {
if ( V_315 -> clock >
V_4 -> V_248 . V_499 ( V_2 ) * 9 / 10 )
V_486 |= V_500 ;
else
V_486 &= ~ V_500 ;
}
V_486 &= ~ ( V_501 | V_502 ) ;
if ( V_492 ) {
if ( V_385 -> V_387 & V_427 ) {
V_486 |= V_503 |
V_502 |
V_504 ;
}
}
F_40 ( L_103 , V_105 == 0 ? 'A' : 'B' ) ;
F_268 ( V_315 ) ;
if ( F_269 ( V_2 ) ) {
if ( V_124 -> V_432 ) {
F_40 ( L_104 ) ;
V_486 |= V_505 ;
} else {
F_40 ( L_105 ) ;
V_486 &= ~ V_505 ;
}
}
V_486 &= ~ V_200 ;
if ( ! F_25 ( V_2 ) &&
V_385 -> V_9 & V_506 ) {
V_486 |= V_507 ;
V_385 -> V_508 -= 1 ;
V_385 -> V_509 -= 1 ;
V_487 = V_385 -> V_510
- V_385 -> V_511 / 2 ;
} else {
V_486 |= V_512 ;
V_487 = 0 ;
}
if ( ! F_270 ( V_2 ) )
F_8 ( F_190 ( V_105 ) , V_487 ) ;
F_8 ( F_178 ( V_105 ) ,
( V_385 -> V_513 - 1 ) |
( ( V_385 -> V_511 - 1 ) << 16 ) ) ;
F_8 ( F_180 ( V_105 ) ,
( V_385 -> V_514 - 1 ) |
( ( V_385 -> V_515 - 1 ) << 16 ) ) ;
F_8 ( F_182 ( V_105 ) ,
( V_385 -> V_510 - 1 ) |
( ( V_385 -> V_516 - 1 ) << 16 ) ) ;
F_8 ( F_184 ( V_105 ) ,
( V_385 -> V_517 - 1 ) |
( ( V_385 -> V_508 - 1 ) << 16 ) ) ;
F_8 ( F_186 ( V_105 ) ,
( V_385 -> V_518 - 1 ) |
( ( V_385 -> V_509 - 1 ) << 16 ) ) ;
F_8 ( F_188 ( V_105 ) ,
( V_385 -> V_519 - 1 ) |
( ( V_385 -> V_520 - 1 ) << 16 ) ) ;
F_8 ( F_271 ( V_148 ) ,
( ( V_315 -> V_368 - 1 ) << 16 ) |
( V_315 -> V_366 - 1 ) ) ;
F_8 ( F_272 ( V_148 ) , 0 ) ;
F_8 ( F_273 ( V_105 ) ,
( ( V_315 -> V_366 - 1 ) << 16 ) | ( V_315 -> V_368 - 1 ) ) ;
F_8 ( F_45 ( V_105 ) , V_486 ) ;
F_12 ( F_45 ( V_105 ) ) ;
F_110 ( V_4 , V_105 , false ) ;
F_41 ( V_2 , V_105 ) ;
F_8 ( F_70 ( V_148 ) , V_233 ) ;
F_12 ( F_70 ( V_148 ) ) ;
V_212 = F_143 ( V_35 , V_222 , V_223 , V_229 ) ;
F_197 ( V_2 ) ;
return V_212 ;
}
void F_274 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_521 * V_522 = & V_2 -> V_522 ;
struct V_75 * V_76 ;
T_1 V_271 ;
bool V_523 = false ;
bool V_524 = false ;
bool V_525 = false ;
bool V_526 = false ;
bool V_527 = false ;
bool V_528 = false ;
F_217 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_76 -> type ) {
case V_38 :
V_526 = true ;
V_523 = true ;
break;
case V_306 :
V_526 = true ;
if ( F_170 ( & V_76 -> V_191 ) )
V_525 = true ;
else
V_524 = true ;
break;
}
}
if ( F_86 ( V_2 ) ) {
V_527 = V_4 -> V_529 ;
V_528 = V_527 ;
} else {
V_527 = false ;
V_528 = true ;
}
F_40 ( L_106 ,
V_526 , V_523 , V_525 , V_524 ,
V_527 ) ;
V_271 = F_3 ( V_154 ) ;
V_271 &= ~ V_156 ;
if ( V_527 )
V_271 |= V_530 ;
else
V_271 |= V_531 ;
if ( V_526 ) {
V_271 &= ~ V_155 ;
V_271 |= V_532 ;
if ( F_244 ( V_4 ) && V_528 ) {
F_40 ( L_107 ) ;
V_271 |= V_533 ;
} else
V_271 &= ~ V_533 ;
F_8 ( V_154 , V_271 ) ;
F_12 ( V_154 ) ;
F_93 ( 200 ) ;
V_271 &= ~ V_534 ;
if ( V_524 ) {
if ( F_244 ( V_4 ) && V_528 ) {
F_40 ( L_108 ) ;
V_271 |= V_535 ;
}
else
V_271 |= V_536 ;
} else
V_271 |= V_537 ;
F_8 ( V_154 , V_271 ) ;
F_12 ( V_154 ) ;
F_93 ( 200 ) ;
} else {
F_40 ( L_109 ) ;
V_271 &= ~ V_534 ;
V_271 |= V_537 ;
F_8 ( V_154 , V_271 ) ;
F_12 ( V_154 ) ;
F_93 ( 200 ) ;
V_271 &= ~ V_155 ;
V_271 |= V_538 ;
V_271 &= ~ V_533 ;
F_8 ( V_154 , V_271 ) ;
F_12 ( V_154 ) ;
F_93 ( 200 ) ;
}
}
static int F_275 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_75 * V_76 ;
struct V_75 * V_539 = NULL ;
int V_428 = 0 ;
bool V_490 = false ;
F_28 (dev, crtc, encoder) {
switch ( V_76 -> type ) {
case V_38 :
V_490 = true ;
break;
case V_306 :
V_539 = V_76 ;
break;
}
V_428 ++ ;
}
if ( V_490 && F_244 ( V_4 ) && V_428 < 2 ) {
F_40 ( L_100 ,
V_4 -> V_429 ) ;
return V_4 -> V_429 * 1000 ;
}
return 120000 ;
}
static void F_276 ( struct V_34 * V_35 ,
struct V_384 * V_385 ,
bool V_540 )
{
struct V_3 * V_4 = V_35 -> V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_5 V_10 ;
V_10 = F_3 ( F_45 ( V_105 ) ) ;
V_10 &= ~ V_198 ;
switch ( V_124 -> V_224 ) {
case 18 :
V_10 |= V_541 ;
break;
case 24 :
V_10 |= V_542 ;
break;
case 30 :
V_10 |= V_543 ;
break;
case 36 :
V_10 |= V_544 ;
break;
default:
V_10 |= V_542 ;
break;
}
V_10 &= ~ ( V_502 | V_545 ) ;
if ( V_540 )
V_10 |= ( V_502 | V_504 ) ;
V_10 &= ~ V_200 ;
if ( V_385 -> V_9 & V_506 )
V_10 |= V_201 ;
else
V_10 |= V_512 ;
F_8 ( F_45 ( V_105 ) , V_10 ) ;
F_12 ( F_45 ( V_105 ) ) ;
}
static bool F_277 ( struct V_34 * V_35 ,
struct V_384 * V_385 ,
T_3 * clock ,
bool * V_489 ,
T_3 * V_430 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_75 * V_75 ;
int V_36 ;
const T_2 * V_37 ;
bool V_212 , V_466 = false , V_491 = false , V_490 = false ;
F_28 (dev, crtc, intel_encoder) {
switch ( V_75 -> type ) {
case V_38 :
V_490 = true ;
break;
case V_54 :
case V_51 :
V_466 = true ;
if ( V_75 -> V_493 )
V_491 = true ;
break;
case V_480 :
V_491 = true ;
break;
}
}
V_36 = F_275 ( V_35 ) ;
V_37 = F_20 ( V_35 , V_36 ) ;
V_212 = V_37 -> V_494 ( V_37 , V_35 , V_385 -> clock , V_36 , NULL ,
clock ) ;
if ( ! V_212 )
return false ;
if ( V_490 && V_4 -> V_495 ) {
* V_489 = V_37 -> V_494 ( V_37 , V_35 ,
V_4 -> V_496 ,
V_36 ,
clock ,
V_430 ) ;
}
if ( V_466 && V_491 )
F_249 ( V_385 , clock ) ;
return true ;
}
static int F_278 ( struct V_34 * V_35 ,
struct V_384 * V_315 ,
struct V_384 * V_385 ,
int V_222 , int V_223 ,
struct V_228 * V_229 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_148 = V_124 -> V_148 ;
int V_428 = 0 ;
T_3 clock , V_430 ;
T_1 V_344 , V_345 = 0 , V_431 = 0 ;
bool V_488 , V_489 = false , V_466 = false ;
bool V_546 = false , V_490 = false , V_491 = false , V_492 = false ;
struct V_75 * V_76 , * V_539 = NULL ;
int V_212 ;
struct V_408 V_409 = { 0 } ;
T_1 V_271 ;
int V_547 , V_469 , V_548 , V_549 , V_550 ;
unsigned int V_418 ;
bool V_540 ;
bool V_551 = false , V_552 = false ;
F_28 (dev, crtc, encoder) {
switch ( V_76 -> type ) {
case V_38 :
V_490 = true ;
break;
case V_54 :
case V_51 :
V_466 = true ;
if ( V_76 -> V_493 )
V_491 = true ;
break;
case V_480 :
V_491 = true ;
break;
case V_52 :
V_546 = true ;
break;
case V_44 :
V_492 = true ;
break;
case V_306 :
V_492 = true ;
if ( F_170 ( & V_76 -> V_191 ) )
V_552 = true ;
else
V_551 = true ;
V_539 = V_76 ;
break;
}
V_428 ++ ;
}
V_488 = F_277 ( V_35 , V_385 , & clock ,
& V_489 , & V_430 ) ;
if ( ! V_488 ) {
F_7 ( L_102 ) ;
return - V_217 ;
}
F_202 ( V_35 , true ) ;
V_469 = F_259 ( V_385 ) ;
V_548 = 0 ;
if ( V_551 ) {
F_279 ( V_539 , & V_548 , & V_549 ) ;
} else {
V_549 = F_1 ( V_2 ) * F_280 ( 100 ) / F_281 ( 1 ) / 10 ;
}
if ( V_539 )
V_547 = F_282 ( V_539 , V_315 ) ;
else if ( V_492 )
V_547 = V_315 -> clock ;
else
V_547 = V_385 -> clock ;
V_540 = F_245 ( V_35 , V_229 , & V_418 ,
V_385 ) ;
if ( V_490 && V_4 -> V_437 )
V_540 = true ;
if ( V_418 != 18 && V_418 != 24 && V_418 != 30 &&
V_418 != 36 ) {
F_46 ( 1 , L_110 ,
V_418 ) ;
V_418 = 24 ;
}
V_124 -> V_224 = V_418 ;
if ( ! V_548 ) {
T_1 V_553 = V_547 * V_124 -> V_224 * 21 / 20 ;
V_548 = V_553 / ( V_549 * 8 ) + 1 ;
}
V_124 -> V_286 = V_548 ;
if ( V_469 > 1 )
V_549 *= V_469 ;
F_243 ( V_124 -> V_224 , V_548 , V_547 , V_549 ,
& V_409 ) ;
V_345 = clock . V_72 << 16 | clock . V_74 << 8 | clock . V_67 ;
if ( V_489 )
V_431 = V_430 . V_72 << 16 | V_430 . V_74 << 8 |
V_430 . V_67 ;
V_550 = 21 ;
if ( V_490 ) {
if ( ( F_244 ( V_4 ) &&
V_4 -> V_429 == 100 ) ||
( F_3 ( V_39 ) & V_32 ) == V_33 )
V_550 = 25 ;
} else if ( V_466 && V_491 )
V_550 = 20 ;
if ( clock . V_66 < V_550 * clock . V_72 )
V_345 |= V_554 ;
V_344 = 0 ;
if ( V_490 )
V_344 |= V_467 ;
else
V_344 |= V_468 ;
if ( V_466 ) {
int V_469 = F_259 ( V_385 ) ;
if ( V_469 > 1 ) {
V_344 |= ( V_469 - 1 ) << V_555 ;
}
V_344 |= V_471 ;
}
if ( V_492 && ! V_551 )
V_344 |= V_471 ;
V_344 |= ( 1 << ( clock . V_69 - 1 ) ) << V_473 ;
V_344 |= ( 1 << ( clock . V_69 - 1 ) ) << V_474 ;
switch ( clock . V_70 ) {
case 5 :
V_344 |= V_475 ;
break;
case 7 :
V_344 |= V_476 ;
break;
case 10 :
V_344 |= V_477 ;
break;
case 14 :
V_344 |= V_478 ;
break;
}
if ( V_466 && V_491 )
V_344 |= V_481 ;
else if ( V_491 )
V_344 |= 3 ;
else if ( V_490 && F_244 ( V_4 ) && V_428 < 2 )
V_344 |= V_482 ;
else
V_344 |= V_483 ;
F_40 ( L_111 , V_105 ) ;
F_268 ( V_315 ) ;
if ( F_55 ( V_2 ) ) {
F_40 ( L_112 ,
V_105 ) ;
} else if ( ! V_551 ) {
struct V_122 * V_123 ;
V_123 = F_193 ( V_124 , V_344 , V_345 ) ;
if ( V_123 == NULL ) {
F_56 ( L_113 ,
V_105 ) ;
return - V_217 ;
}
} else
F_192 ( V_124 ) ;
if ( V_490 ) {
V_271 = F_3 ( V_39 ) ;
V_271 |= V_168 | V_434 ;
if ( F_57 ( V_2 ) ) {
V_271 &= ~ V_166 ;
V_271 |= F_79 ( V_105 ) ;
} else {
if ( V_105 == 1 )
V_271 |= V_143 ;
else
V_271 &= ~ V_143 ;
}
V_271 |= V_4 -> V_435 ;
if ( clock . V_70 == 7 )
V_271 |= V_436 | V_33 ;
else
V_271 &= ~ ( V_436 | V_33 ) ;
V_271 &= ~ ( V_439 | V_440 ) ;
if ( V_385 -> V_9 & V_441 )
V_271 |= V_439 ;
if ( V_385 -> V_9 & V_442 )
V_271 |= V_440 ;
F_8 ( V_39 , V_271 ) ;
}
if ( V_492 && ! V_551 ) {
F_265 ( V_35 , V_315 , V_385 ) ;
} else {
F_8 ( F_283 ( V_105 ) , 0 ) ;
F_8 ( F_284 ( V_105 ) , 0 ) ;
F_8 ( F_285 ( V_105 ) , 0 ) ;
F_8 ( F_286 ( V_105 ) , 0 ) ;
}
if ( V_124 -> V_192 ) {
F_8 ( V_124 -> V_192 -> V_125 , V_344 ) ;
F_12 ( V_124 -> V_192 -> V_125 ) ;
F_93 ( 150 ) ;
F_8 ( V_124 -> V_192 -> V_125 , V_344 ) ;
}
V_124 -> V_432 = false ;
if ( V_124 -> V_192 ) {
if ( V_490 && V_489 && V_433 ) {
F_8 ( V_124 -> V_192 -> V_556 , V_431 ) ;
V_124 -> V_432 = true ;
} else {
F_8 ( V_124 -> V_192 -> V_556 , V_345 ) ;
}
}
if ( V_385 -> V_9 & V_506 ) {
V_385 -> V_508 -= 1 ;
V_385 -> V_509 -= 1 ;
F_8 ( F_190 ( V_105 ) ,
V_385 -> V_510
- V_385 -> V_511 / 2 ) ;
} else {
F_8 ( F_190 ( V_105 ) , 0 ) ;
}
F_8 ( F_178 ( V_105 ) ,
( V_385 -> V_513 - 1 ) |
( ( V_385 -> V_511 - 1 ) << 16 ) ) ;
F_8 ( F_180 ( V_105 ) ,
( V_385 -> V_514 - 1 ) |
( ( V_385 -> V_515 - 1 ) << 16 ) ) ;
F_8 ( F_182 ( V_105 ) ,
( V_385 -> V_510 - 1 ) |
( ( V_385 -> V_516 - 1 ) << 16 ) ) ;
F_8 ( F_184 ( V_105 ) ,
( V_385 -> V_517 - 1 ) |
( ( V_385 -> V_508 - 1 ) << 16 ) ) ;
F_8 ( F_186 ( V_105 ) ,
( V_385 -> V_518 - 1 ) |
( ( V_385 -> V_509 - 1 ) << 16 ) ) ;
F_8 ( F_188 ( V_105 ) ,
( V_385 -> V_519 - 1 ) |
( ( V_385 -> V_520 - 1 ) << 16 ) ) ;
F_8 ( F_273 ( V_105 ) ,
( ( V_315 -> V_366 - 1 ) << 16 ) | ( V_315 -> V_368 - 1 ) ) ;
F_8 ( F_163 ( V_105 ) , F_287 ( V_409 . V_410 ) | V_409 . V_411 ) ;
F_8 ( F_288 ( V_105 ) , V_409 . V_412 ) ;
F_8 ( F_289 ( V_105 ) , V_409 . V_413 ) ;
F_8 ( F_290 ( V_105 ) , V_409 . V_414 ) ;
if ( V_551 )
F_147 ( V_35 , V_385 -> clock ) ;
F_276 ( V_35 , V_385 , V_540 ) ;
F_41 ( V_2 , V_105 ) ;
F_8 ( F_70 ( V_148 ) , V_497 ) ;
F_12 ( F_70 ( V_148 ) ) ;
V_212 = F_143 ( V_35 , V_222 , V_223 , V_229 ) ;
F_197 ( V_2 ) ;
F_291 ( V_2 , V_105 , V_385 ) ;
return V_212 ;
}
static int F_292 ( struct V_34 * V_35 ,
struct V_384 * V_315 ,
struct V_384 * V_385 ,
int V_222 , int V_223 ,
struct V_228 * V_229 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_212 ;
F_293 ( V_2 , V_105 ) ;
V_212 = V_4 -> V_248 . V_557 ( V_35 , V_315 , V_385 ,
V_222 , V_223 , V_229 ) ;
F_294 ( V_2 , V_105 ) ;
return V_212 ;
}
static bool F_295 ( struct V_374 * V_375 ,
int V_558 , T_5 V_559 ,
int V_560 , T_5 V_561 ,
int V_562 )
{
struct V_3 * V_4 = V_375 -> V_2 -> V_5 ;
T_6 * V_563 = V_375 -> V_563 ;
T_5 V_150 ;
V_150 = F_3 ( V_558 ) ;
V_150 &= V_559 ;
if ( ! V_563 [ 0 ] )
return ! V_150 ;
if ( ! V_150 )
return false ;
V_150 = F_3 ( V_560 ) ;
V_150 &= ~ V_561 ;
F_8 ( V_560 , V_150 ) ;
for ( V_150 = 0 ; V_150 < V_563 [ 2 ] ; V_150 ++ )
if ( F_3 ( V_562 ) != * ( ( T_5 * ) V_563 + V_150 ) )
return false ;
return true ;
}
static void F_296 ( struct V_374 * V_375 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = V_375 -> V_2 -> V_5 ;
T_6 * V_563 = V_375 -> V_563 ;
T_5 V_564 ;
T_5 V_565 ;
T_5 V_150 ;
V_150 = F_3 ( V_566 ) ;
if ( V_150 == V_567 || V_150 == V_568 )
V_564 = V_569 ;
else
V_564 = V_570 ;
if ( F_295 ( V_375 ,
V_571 , V_564 ,
V_571 , V_572 ,
V_573 ) )
return;
V_150 = F_3 ( V_571 ) ;
V_150 &= ~ ( V_564 | V_572 ) ;
V_565 = ( V_150 >> 9 ) & 0x1f ;
F_8 ( V_571 , V_150 ) ;
if ( ! V_563 [ 0 ] )
return;
V_565 = F_297 ( T_6 , V_563 [ 2 ] , V_565 ) ;
F_56 ( L_114 , V_565 ) ;
for ( V_150 = 0 ; V_150 < V_565 ; V_150 ++ )
F_8 ( V_573 , * ( ( T_5 * ) V_563 + V_150 ) ) ;
V_150 = F_3 ( V_571 ) ;
V_150 |= V_564 ;
F_8 ( V_571 , V_150 ) ;
}
static void F_298 ( struct V_374 * V_375 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = V_375 -> V_2 -> V_5 ;
T_6 * V_563 = V_375 -> V_563 ;
struct V_1 * V_2 = V_35 -> V_2 ;
T_5 V_564 ;
T_5 V_150 ;
int V_565 ;
int V_105 = F_104 ( V_35 ) -> V_105 ;
int V_574 ;
int V_575 = F_299 ( V_105 ) ;
int V_576 = F_300 ( V_105 ) ;
int V_577 = F_301 ( V_105 ) ;
int V_578 = V_579 ;
F_56 ( L_115 ) ;
F_56 ( L_116 ) ;
V_574 = F_3 ( V_578 ) ;
V_574 |= ( V_580 << ( V_105 * 4 ) ) ;
F_8 ( V_578 , V_574 ) ;
F_41 ( V_2 , V_105 ) ;
V_574 = F_3 ( V_578 ) ;
F_56 ( L_117 , V_574 ) ;
V_574 |= ( V_581 << ( V_105 * 4 ) ) ;
F_8 ( V_578 , V_574 ) ;
V_574 = F_3 ( V_578 ) ;
F_56 ( L_118 , V_574 ) ;
V_574 = F_3 ( V_577 ) ;
F_56 ( L_119 , V_574 ) ;
V_574 &= ~ ( V_582 | V_583 ) ;
F_8 ( V_577 , V_574 ) ;
F_56 ( L_120 , F_67 ( V_105 ) ) ;
V_564 = V_581 << ( V_105 * 4 ) ;
if ( F_18 ( V_35 , V_44 ) ) {
F_56 ( L_121 ) ;
V_563 [ 5 ] |= ( 1 << 2 ) ;
F_8 ( V_577 , V_582 ) ;
} else
F_8 ( V_577 , 0 ) ;
if ( F_295 ( V_375 ,
V_578 , V_564 ,
V_576 , V_584 ,
V_575 ) )
return;
V_150 = F_3 ( V_578 ) ;
V_150 &= ~ V_564 ;
F_8 ( V_578 , V_150 ) ;
if ( ! V_563 [ 0 ] )
return;
V_150 = F_3 ( V_576 ) ;
V_150 &= ~ V_584 ;
F_8 ( V_576 , V_150 ) ;
V_150 = ( V_150 >> 29 ) & V_585 ;
F_56 ( L_122 , V_150 ) ;
V_565 = F_297 ( T_6 , V_563 [ 2 ] , 21 ) ;
F_56 ( L_114 , V_565 ) ;
for ( V_150 = 0 ; V_150 < V_565 ; V_150 ++ )
F_8 ( V_575 , * ( ( T_5 * ) V_563 + V_150 ) ) ;
V_150 = F_3 ( V_578 ) ;
V_150 |= V_564 ;
F_8 ( V_578 , V_150 ) ;
}
static void F_302 ( struct V_374 * V_375 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = V_375 -> V_2 -> V_5 ;
T_6 * V_563 = V_375 -> V_563 ;
T_5 V_564 ;
T_5 V_150 ;
int V_565 ;
int V_575 ;
int V_577 ;
int V_576 ;
int V_578 ;
int V_105 = F_104 ( V_35 ) -> V_105 ;
if ( F_86 ( V_375 -> V_2 ) ) {
V_575 = F_303 ( V_105 ) ;
V_577 = F_304 ( V_105 ) ;
V_576 = F_305 ( V_105 ) ;
V_578 = V_586 ;
} else {
V_575 = F_306 ( V_105 ) ;
V_577 = F_307 ( V_105 ) ;
V_576 = F_308 ( V_105 ) ;
V_578 = V_587 ;
}
F_56 ( L_120 , F_67 ( V_105 ) ) ;
V_150 = F_3 ( V_576 ) ;
V_150 = ( V_150 >> 29 ) & V_585 ;
if ( ! V_150 ) {
F_56 ( L_123 ) ;
V_564 = V_588 ;
V_564 |= V_588 << 4 ;
V_564 |= V_588 << 8 ;
} else {
F_56 ( L_124 , 'A' + V_150 ) ;
V_564 = V_588 << ( ( V_150 - 1 ) * 4 ) ;
}
if ( F_18 ( V_35 , V_44 ) ) {
F_56 ( L_121 ) ;
V_563 [ 5 ] |= ( 1 << 2 ) ;
F_8 ( V_577 , V_582 ) ;
} else
F_8 ( V_577 , 0 ) ;
if ( F_295 ( V_375 ,
V_578 , V_564 ,
V_576 , V_584 ,
V_575 ) )
return;
V_150 = F_3 ( V_578 ) ;
V_150 &= ~ V_564 ;
F_8 ( V_578 , V_150 ) ;
if ( ! V_563 [ 0 ] )
return;
V_150 = F_3 ( V_576 ) ;
V_150 &= ~ V_584 ;
F_8 ( V_576 , V_150 ) ;
V_565 = F_297 ( T_6 , V_563 [ 2 ] , 21 ) ;
F_56 ( L_114 , V_565 ) ;
for ( V_150 = 0 ; V_150 < V_565 ; V_150 ++ )
F_8 ( V_575 , * ( ( T_5 * ) V_563 + V_150 ) ) ;
V_150 = F_3 ( V_578 ) ;
V_150 |= V_564 ;
F_8 ( V_578 , V_150 ) ;
}
void F_309 ( struct V_379 * V_76 ,
struct V_384 * V_315 )
{
struct V_34 * V_35 = V_76 -> V_35 ;
struct V_374 * V_375 ;
struct V_1 * V_2 = V_76 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_375 = F_310 ( V_76 , V_315 ) ;
if ( ! V_375 )
return;
F_56 ( L_125 ,
V_375 -> V_191 . V_24 ,
F_226 ( V_375 ) ,
V_375 -> V_76 -> V_191 . V_24 ,
F_311 ( V_375 -> V_76 ) ) ;
V_375 -> V_563 [ 6 ] = F_312 ( V_375 , V_315 ) / 2 ;
if ( V_4 -> V_248 . V_589 )
V_4 -> V_248 . V_589 ( V_375 , V_35 ) ;
}
void F_201 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_590 = F_313 ( V_124 -> V_105 ) ;
int V_150 ;
if ( ! V_35 -> V_118 || ! V_124 -> V_194 )
return;
if ( F_21 ( V_2 ) )
V_590 = F_314 ( V_124 -> V_105 ) ;
for ( V_150 = 0 ; V_150 < 256 ; V_150 ++ ) {
F_8 ( V_590 + 4 * V_150 ,
( V_124 -> V_591 [ V_150 ] << 16 ) |
( V_124 -> V_592 [ V_150 ] << 8 ) |
V_124 -> V_593 [ V_150 ] ) ;
}
}
static void F_315 ( struct V_34 * V_35 , T_1 V_191 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
bool V_594 = V_191 != 0 ;
T_1 V_595 ;
if ( V_124 -> V_596 == V_594 )
return;
V_595 = F_3 ( V_597 ) ;
if ( V_594 ) {
F_8 ( V_598 , V_191 ) ;
V_595 &= ~ ( V_599 ) ;
V_595 |= V_600 |
V_601 |
V_602 ;
} else
V_595 &= ~ ( V_600 | V_601 ) ;
F_8 ( V_597 , V_595 ) ;
V_124 -> V_596 = V_594 ;
}
static void F_316 ( struct V_34 * V_35 , T_1 V_191 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
bool V_594 = V_191 != 0 ;
if ( V_124 -> V_596 != V_594 ) {
T_5 V_595 = F_3 ( F_317 ( V_105 ) ) ;
if ( V_191 ) {
V_595 &= ~ ( V_603 | V_604 ) ;
V_595 |= V_605 | V_606 ;
V_595 |= V_105 << 28 ;
} else {
V_595 &= ~ ( V_603 | V_606 ) ;
V_595 |= V_607 ;
}
F_8 ( F_317 ( V_105 ) , V_595 ) ;
V_124 -> V_596 = V_594 ;
}
F_8 ( F_318 ( V_105 ) , V_191 ) ;
}
static void F_319 ( struct V_34 * V_35 , T_1 V_191 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
bool V_594 = V_191 != 0 ;
if ( V_124 -> V_596 != V_594 ) {
T_5 V_595 = F_3 ( F_320 ( V_105 ) ) ;
if ( V_191 ) {
V_595 &= ~ V_603 ;
V_595 |= V_605 | V_606 ;
} else {
V_595 &= ~ ( V_603 | V_606 ) ;
V_595 |= V_607 ;
}
F_8 ( F_320 ( V_105 ) , V_595 ) ;
V_124 -> V_596 = V_594 ;
}
F_8 ( F_321 ( V_105 ) , V_191 ) ;
}
static void F_202 ( struct V_34 * V_35 ,
bool V_195 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_222 = V_124 -> V_608 ;
int V_223 = V_124 -> V_609 ;
T_1 V_191 , V_610 ;
bool V_594 ;
V_610 = 0 ;
if ( V_195 && V_35 -> V_118 && V_35 -> V_229 ) {
V_191 = V_124 -> V_611 ;
if ( V_222 > ( int ) V_35 -> V_229 -> V_612 )
V_191 = 0 ;
if ( V_223 > ( int ) V_35 -> V_229 -> V_613 )
V_191 = 0 ;
} else
V_191 = 0 ;
if ( V_222 < 0 ) {
if ( V_222 + V_124 -> V_614 < 0 )
V_191 = 0 ;
V_610 |= V_615 << V_616 ;
V_222 = - V_222 ;
}
V_610 |= V_222 << V_616 ;
if ( V_223 < 0 ) {
if ( V_223 + V_124 -> V_617 < 0 )
V_191 = 0 ;
V_610 |= V_615 << V_618 ;
V_223 = - V_223 ;
}
V_610 |= V_223 << V_618 ;
V_594 = V_191 != 0 ;
if ( ! V_594 && ! V_124 -> V_596 )
return;
if ( F_149 ( V_2 ) || F_59 ( V_2 ) ) {
F_8 ( F_322 ( V_105 ) , V_610 ) ;
F_319 ( V_35 , V_191 ) ;
} else {
F_8 ( F_323 ( V_105 ) , V_610 ) ;
if ( F_324 ( V_2 ) || F_325 ( V_2 ) )
F_315 ( V_35 , V_191 ) ;
else
F_316 ( V_35 , V_191 ) ;
}
}
static int F_326 ( struct V_34 * V_35 ,
struct V_619 * V_620 ,
T_5 V_621 ,
T_5 V_612 , T_5 V_613 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_207 * V_208 ;
T_5 V_622 ;
int V_212 ;
if ( ! V_621 ) {
F_40 ( L_126 ) ;
V_622 = 0 ;
V_208 = NULL ;
F_144 ( & V_2 -> V_259 ) ;
goto V_623;
}
if ( V_612 != 64 || V_613 != 64 ) {
F_7 ( L_127 ) ;
return - V_217 ;
}
V_208 = F_327 ( F_328 ( V_2 , V_620 , V_621 ) ) ;
if ( & V_208 -> V_191 == NULL )
return - V_624 ;
if ( V_208 -> V_191 . V_625 < V_612 * V_613 * 4 ) {
F_7 ( L_128 ) ;
V_212 = - V_626 ;
goto V_627;
}
F_144 ( & V_2 -> V_259 ) ;
if ( ! V_4 -> V_132 -> V_628 ) {
if ( V_208 -> V_213 ) {
F_7 ( L_129 ) ;
V_212 = - V_217 ;
goto V_629;
}
V_212 = F_123 ( V_208 , 0 , NULL ) ;
if ( V_212 ) {
F_7 ( L_130 ) ;
goto V_629;
}
V_212 = F_329 ( V_208 ) ;
if ( V_212 ) {
F_7 ( L_131 ) ;
goto V_630;
}
V_622 = V_208 -> V_244 ;
} else {
int V_631 = F_92 ( V_2 ) ? 16 * 1024 : 256 ;
V_212 = F_330 ( V_2 , V_208 ,
( V_124 -> V_105 == 0 ) ? V_632 : V_633 ,
V_631 ) ;
if ( V_212 ) {
F_7 ( L_132 ) ;
goto V_629;
}
V_622 = V_208 -> V_634 -> V_621 -> V_635 ;
}
if ( F_25 ( V_2 ) )
F_8 ( V_636 , ( V_613 << 12 ) | V_612 ) ;
V_623:
if ( V_124 -> V_637 ) {
if ( V_4 -> V_132 -> V_628 ) {
if ( V_124 -> V_637 != V_208 )
F_331 ( V_2 , V_124 -> V_637 ) ;
} else
F_126 ( V_124 -> V_637 ) ;
F_332 ( & V_124 -> V_637 -> V_191 ) ;
}
F_145 ( & V_2 -> V_259 ) ;
V_124 -> V_611 = V_622 ;
V_124 -> V_637 = V_208 ;
V_124 -> V_614 = V_612 ;
V_124 -> V_617 = V_613 ;
F_202 ( V_35 , true ) ;
return 0 ;
V_630:
F_126 ( V_208 ) ;
V_629:
F_145 ( & V_2 -> V_259 ) ;
V_627:
F_333 ( & V_208 -> V_191 ) ;
return V_212 ;
}
static int F_334 ( struct V_34 * V_35 , int V_222 , int V_223 )
{
struct V_124 * V_124 = F_104 ( V_35 ) ;
V_124 -> V_608 = V_222 ;
V_124 -> V_609 = V_223 ;
F_202 ( V_35 , true ) ;
return 0 ;
}
void F_335 ( struct V_34 * V_35 , T_4 V_638 , T_4 V_639 ,
T_4 V_640 , int V_641 )
{
struct V_124 * V_124 = F_104 ( V_35 ) ;
V_124 -> V_591 [ V_641 ] = V_638 >> 8 ;
V_124 -> V_592 [ V_641 ] = V_639 >> 8 ;
V_124 -> V_593 [ V_641 ] = V_640 >> 8 ;
}
void F_336 ( struct V_34 * V_35 , T_4 * V_638 , T_4 * V_639 ,
T_4 * V_640 , int V_641 )
{
struct V_124 * V_124 = F_104 ( V_35 ) ;
* V_638 = V_124 -> V_591 [ V_641 ] << 8 ;
* V_639 = V_124 -> V_592 [ V_641 ] << 8 ;
* V_640 = V_124 -> V_593 [ V_641 ] << 8 ;
}
static void F_337 ( struct V_34 * V_35 , T_4 * V_638 , T_4 * V_639 ,
T_4 * V_640 , T_5 V_642 , T_5 V_625 )
{
int V_643 = ( V_642 + V_625 > 256 ) ? 256 : V_642 + V_625 , V_150 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
for ( V_150 = V_642 ; V_150 < V_643 ; V_150 ++ ) {
V_124 -> V_591 [ V_150 ] = V_638 [ V_150 ] >> 8 ;
V_124 -> V_592 [ V_150 ] = V_639 [ V_150 ] >> 8 ;
V_124 -> V_593 [ V_150 ] = V_640 [ V_150 ] >> 8 ;
}
F_201 ( V_35 ) ;
}
static struct V_228 *
F_338 ( struct V_1 * V_2 ,
struct V_644 * V_645 ,
struct V_207 * V_208 )
{
struct V_230 * V_231 ;
int V_212 ;
V_231 = F_339 ( sizeof( * V_231 ) , V_646 ) ;
if ( ! V_231 ) {
F_333 ( & V_208 -> V_191 ) ;
return F_340 ( - V_626 ) ;
}
V_212 = F_341 ( V_2 , V_231 , V_645 , V_208 ) ;
if ( V_212 ) {
F_333 ( & V_208 -> V_191 ) ;
F_223 ( V_231 ) ;
return F_340 ( V_212 ) ;
}
return & V_231 -> V_191 ;
}
static T_1
F_342 ( int V_612 , int V_224 )
{
T_1 V_225 = F_343 ( V_612 * V_224 , 8 ) ;
return F_344 ( V_225 , 64 ) ;
}
static T_1
F_345 ( struct V_384 * V_315 , int V_224 )
{
T_1 V_225 = F_342 ( V_315 -> V_366 , V_224 ) ;
return F_344 ( V_225 * V_315 -> V_368 , V_647 ) ;
}
static struct V_228 *
F_346 ( struct V_1 * V_2 ,
struct V_384 * V_315 ,
int V_237 , int V_224 )
{
struct V_207 * V_208 ;
struct V_644 V_645 ;
V_208 = F_347 ( V_2 ,
F_345 ( V_315 , V_224 ) ) ;
if ( V_208 == NULL )
return F_340 ( - V_626 ) ;
V_645 . V_612 = V_315 -> V_366 ;
V_645 . V_613 = V_315 -> V_368 ;
V_645 . V_242 [ 0 ] = F_342 ( V_645 . V_612 ,
V_224 ) ;
V_645 . V_648 = F_348 ( V_224 , V_237 ) ;
return F_338 ( V_2 , & V_645 , V_208 ) ;
}
static struct V_228 *
F_349 ( struct V_1 * V_2 ,
struct V_384 * V_315 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_207 * V_208 ;
struct V_228 * V_229 ;
if ( V_4 -> V_649 == NULL )
return NULL ;
V_208 = V_4 -> V_649 -> V_650 . V_208 ;
if ( V_208 == NULL )
return NULL ;
V_229 = & V_4 -> V_649 -> V_650 . V_191 ;
if ( V_229 -> V_242 [ 0 ] < F_342 ( V_315 -> V_366 ,
V_229 -> V_235 ) )
return NULL ;
if ( V_208 -> V_191 . V_625 < V_315 -> V_368 * V_229 -> V_242 [ 0 ] )
return NULL ;
return V_229 ;
}
bool F_350 ( struct V_374 * V_375 ,
struct V_384 * V_315 ,
struct V_651 * V_652 )
{
struct V_124 * V_124 ;
struct V_75 * V_75 =
F_228 ( V_375 ) ;
struct V_34 * V_653 ;
struct V_379 * V_76 = & V_75 -> V_191 ;
struct V_34 * V_35 = NULL ;
struct V_1 * V_2 = V_76 -> V_2 ;
struct V_228 * V_229 ;
int V_150 = - 1 ;
F_40 ( L_133 ,
V_375 -> V_191 . V_24 , F_226 ( V_375 ) ,
V_76 -> V_191 . V_24 , F_311 ( V_76 ) ) ;
if ( V_76 -> V_35 ) {
V_35 = V_76 -> V_35 ;
V_652 -> V_654 = V_375 -> V_377 ;
V_652 -> V_655 = false ;
if ( V_375 -> V_377 != V_380 )
V_375 -> V_656 -> V_377 ( V_375 , V_380 ) ;
return true ;
}
F_217 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_150 ++ ;
if ( ! ( V_76 -> V_657 & ( 1 << V_150 ) ) )
continue;
if ( ! V_653 -> V_118 ) {
V_35 = V_653 ;
break;
}
}
if ( ! V_35 ) {
F_40 ( L_134 ) ;
return false ;
}
V_75 -> V_658 = F_104 ( V_35 ) ;
F_351 ( V_375 ) -> V_659 = V_75 ;
V_124 = F_104 ( V_35 ) ;
V_652 -> V_654 = V_375 -> V_377 ;
V_652 -> V_655 = true ;
V_652 -> V_660 = NULL ;
if ( ! V_315 )
V_315 = & V_661 ;
V_229 = F_349 ( V_2 , V_315 ) ;
if ( V_229 == NULL ) {
F_40 ( L_135 ) ;
V_229 = F_346 ( V_2 , V_315 , 24 , 32 ) ;
V_652 -> V_660 = V_229 ;
} else
F_40 ( L_136 ) ;
if ( F_352 ( V_229 ) ) {
F_40 ( L_137 ) ;
goto V_627;
}
if ( ! F_353 ( V_35 , V_315 , 0 , 0 , V_229 ) ) {
F_40 ( L_138 ) ;
if ( V_652 -> V_660 )
V_652 -> V_660 -> V_656 -> V_662 ( V_652 -> V_660 ) ;
goto V_627;
}
F_41 ( V_2 , V_124 -> V_105 ) ;
return true ;
V_627:
V_375 -> V_76 = NULL ;
V_76 -> V_35 = NULL ;
return false ;
}
void F_354 ( struct V_374 * V_375 ,
struct V_651 * V_652 )
{
struct V_75 * V_75 =
F_228 ( V_375 ) ;
struct V_379 * V_76 = & V_75 -> V_191 ;
F_40 ( L_133 ,
V_375 -> V_191 . V_24 , F_226 ( V_375 ) ,
V_76 -> V_191 . V_24 , F_311 ( V_76 ) ) ;
if ( V_652 -> V_655 ) {
struct V_34 * V_35 = V_76 -> V_35 ;
F_351 ( V_375 ) -> V_659 = NULL ;
V_75 -> V_658 = NULL ;
F_353 ( V_35 , NULL , 0 , 0 , NULL ) ;
if ( V_652 -> V_660 )
V_652 -> V_660 -> V_656 -> V_662 ( V_652 -> V_660 ) ;
return;
}
if ( V_652 -> V_654 != V_380 )
V_375 -> V_656 -> V_377 ( V_375 , V_652 -> V_654 ) ;
}
static int F_355 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
T_1 V_344 = F_3 ( F_53 ( V_105 ) ) ;
T_1 V_345 ;
T_3 clock ;
if ( ( V_344 & V_663 ) == 0 )
V_345 = F_3 ( F_251 ( V_105 ) ) ;
else
V_345 = F_3 ( F_252 ( V_105 ) ) ;
clock . V_74 = ( V_345 & V_664 ) >> V_665 ;
if ( F_23 ( V_2 ) ) {
clock . V_72 = F_356 ( ( V_345 & V_666 ) >> V_667 ) - 1 ;
clock . V_67 = ( V_345 & V_668 ) >> V_669 ;
} else {
clock . V_72 = ( V_345 & V_670 ) >> V_667 ;
clock . V_67 = ( V_345 & V_671 ) >> V_669 ;
}
if ( ! F_25 ( V_2 ) ) {
if ( F_23 ( V_2 ) )
clock . V_69 = F_356 ( ( V_344 & V_672 ) >>
V_472 ) ;
else
clock . V_69 = F_356 ( ( V_344 & V_673 ) >>
V_473 ) ;
switch ( V_344 & V_674 ) {
case V_468 :
clock . V_70 = V_344 & V_475 ?
5 : 10 ;
break;
case V_467 :
clock . V_70 = V_344 & V_476 ?
7 : 14 ;
break;
default:
F_40 ( L_139
L_140 , ( int ) ( V_344 & V_674 ) ) ;
return 0 ;
}
F_27 ( V_2 , 96000 , & clock ) ;
} else {
bool V_490 = ( V_105 == 1 ) && ( F_3 ( V_48 ) & V_168 ) ;
if ( V_490 ) {
clock . V_69 = F_356 ( ( V_344 & V_675 ) >>
V_473 ) ;
clock . V_70 = 14 ;
if ( ( V_344 & V_676 ) ==
V_482 ) {
F_27 ( V_2 , 66000 , & clock ) ;
} else
F_27 ( V_2 , 48000 , & clock ) ;
} else {
if ( V_344 & V_484 )
clock . V_69 = 2 ;
else {
clock . V_69 = ( ( V_344 & V_677 ) >>
V_473 ) + 2 ;
}
if ( V_344 & V_485 )
clock . V_70 = 4 ;
else
clock . V_70 = 2 ;
F_27 ( V_2 , 48000 , & clock ) ;
}
}
return clock . V_73 ;
}
struct V_384 * F_357 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
struct V_384 * V_315 ;
int V_678 = F_3 ( F_178 ( V_105 ) ) ;
int V_679 = F_3 ( F_182 ( V_105 ) ) ;
int V_680 = F_3 ( F_184 ( V_105 ) ) ;
int V_681 = F_3 ( F_188 ( V_105 ) ) ;
V_315 = F_339 ( sizeof( * V_315 ) , V_646 ) ;
if ( ! V_315 )
return NULL ;
V_315 -> clock = F_355 ( V_2 , V_35 ) ;
V_315 -> V_366 = ( V_678 & 0xffff ) + 1 ;
V_315 -> V_682 = ( ( V_678 & 0xffff0000 ) >> 16 ) + 1 ;
V_315 -> V_389 = ( V_679 & 0xffff ) + 1 ;
V_315 -> V_683 = ( ( V_679 & 0xffff0000 ) >> 16 ) + 1 ;
V_315 -> V_368 = ( V_680 & 0xffff ) + 1 ;
V_315 -> V_684 = ( ( V_680 & 0xffff0000 ) >> 16 ) + 1 ;
V_315 -> V_685 = ( V_681 & 0xffff ) + 1 ;
V_315 -> V_686 = ( ( V_681 & 0xffff0000 ) >> 16 ) + 1 ;
F_358 ( V_315 ) ;
return V_315 ;
}
static void F_138 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
int V_105 = V_124 -> V_105 ;
int V_687 = F_53 ( V_105 ) ;
int V_344 ;
if ( F_21 ( V_2 ) )
return;
if ( ! V_4 -> V_495 )
return;
V_344 = F_3 ( V_687 ) ;
if ( ! F_269 ( V_2 ) && ( V_344 & V_663 ) ) {
F_56 ( L_141 ) ;
F_66 ( V_4 , V_105 ) ;
V_344 &= ~ V_663 ;
F_8 ( V_687 , V_344 ) ;
F_41 ( V_2 , V_105 ) ;
V_344 = F_3 ( V_687 ) ;
if ( V_344 & V_663 )
F_56 ( L_142 ) ;
}
}
static void F_359 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
if ( F_21 ( V_2 ) )
return;
if ( ! V_4 -> V_495 )
return;
if ( ! F_269 ( V_2 ) && V_124 -> V_432 ) {
int V_105 = V_124 -> V_105 ;
int V_687 = F_53 ( V_105 ) ;
int V_344 ;
F_56 ( L_143 ) ;
F_66 ( V_4 , V_105 ) ;
V_344 = F_3 ( V_687 ) ;
V_344 |= V_663 ;
F_8 ( V_687 , V_344 ) ;
F_41 ( V_2 , V_105 ) ;
V_344 = F_3 ( V_687 ) ;
if ( ! ( V_344 & V_663 ) )
F_56 ( L_144 ) ;
}
}
void F_360 ( struct V_1 * V_2 )
{
F_361 ( V_2 -> V_5 ) ;
}
void F_362 ( struct V_1 * V_2 )
{
}
void F_363 ( struct V_207 * V_208 )
{
struct V_1 * V_2 = V_208 -> V_191 . V_2 ;
struct V_34 * V_35 ;
if ( ! V_433 )
return;
F_217 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_35 -> V_229 )
continue;
if ( F_131 ( V_35 -> V_229 ) -> V_208 == V_208 )
F_138 ( V_35 ) ;
}
}
void F_364 ( struct V_207 * V_208 )
{
struct V_1 * V_2 = V_208 -> V_191 . V_2 ;
struct V_34 * V_35 ;
if ( ! V_433 )
return;
F_217 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_35 -> V_229 )
continue;
if ( F_131 ( V_35 -> V_229 ) -> V_208 == V_208 )
F_359 ( V_35 ) ;
}
}
static void F_365 ( struct V_34 * V_35 )
{
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_688 * V_689 ;
unsigned long V_9 ;
F_5 ( & V_2 -> V_304 , V_9 ) ;
V_689 = V_124 -> V_305 ;
V_124 -> V_305 = NULL ;
F_9 ( & V_2 -> V_304 , V_9 ) ;
if ( V_689 ) {
F_366 ( & V_689 -> V_689 ) ;
F_223 ( V_689 ) ;
}
F_367 ( V_35 ) ;
F_223 ( V_124 ) ;
}
static void F_368 ( struct V_690 * V_691 )
{
struct V_688 * V_689 =
F_369 ( V_691 , struct V_688 , V_689 ) ;
F_144 ( & V_689 -> V_2 -> V_259 ) ;
F_127 ( V_689 -> V_692 ) ;
F_332 ( & V_689 -> V_693 -> V_191 ) ;
F_332 ( & V_689 -> V_692 -> V_191 ) ;
F_146 ( V_689 -> V_2 ) ;
F_145 ( & V_689 -> V_2 -> V_259 ) ;
F_223 ( V_689 ) ;
}
static void F_370 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_688 * V_689 ;
struct V_207 * V_208 ;
struct V_694 * V_695 ;
struct V_696 V_697 ;
unsigned long V_9 ;
if ( V_124 == NULL )
return;
F_5 ( & V_2 -> V_304 , V_9 ) ;
V_689 = V_124 -> V_305 ;
if ( V_689 == NULL || ! V_689 -> V_303 ) {
F_9 ( & V_2 -> V_304 , V_9 ) ;
return;
}
V_124 -> V_305 = NULL ;
if ( V_689 -> V_698 ) {
V_695 = V_689 -> V_698 ;
V_695 -> V_698 . V_699 = F_371 ( V_2 , V_124 -> V_105 , & V_697 ) ;
V_695 -> V_698 . V_700 = V_697 . V_700 ;
V_695 -> V_698 . V_701 = V_697 . V_701 ;
F_372 ( & V_695 -> V_191 . V_702 ,
& V_695 -> V_191 . V_703 -> V_704 ) ;
F_373 ( & V_695 -> V_191 . V_703 -> V_705 ) ;
}
F_374 ( V_2 , V_124 -> V_105 ) ;
F_9 ( & V_2 -> V_304 , V_9 ) ;
V_208 = V_689 -> V_692 ;
F_375 ( 1 << V_124 -> V_148 ,
& V_208 -> V_255 . V_706 ) ;
F_376 ( & V_4 -> V_253 ) ;
F_377 ( & V_689 -> V_689 ) ;
F_378 ( V_124 -> V_148 , V_689 -> V_693 ) ;
}
void F_379 ( struct V_1 * V_2 , int V_105 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_34 * V_35 = V_4 -> V_197 [ V_105 ] ;
F_370 ( V_2 , V_35 ) ;
}
void F_380 ( struct V_1 * V_2 , int V_148 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_34 * V_35 = V_4 -> V_707 [ V_148 ] ;
F_370 ( V_2 , V_35 ) ;
}
void F_381 ( struct V_1 * V_2 , int V_148 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 =
F_104 ( V_4 -> V_707 [ V_148 ] ) ;
unsigned long V_9 ;
F_5 ( & V_2 -> V_304 , V_9 ) ;
if ( V_124 -> V_305 ) {
if ( ( ++ V_124 -> V_305 -> V_303 ) > 1 )
F_7 ( L_145 ) ;
} else {
F_56 ( L_146 ) ;
}
F_9 ( & V_2 -> V_304 , V_9 ) ;
}
static int F_382 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_228 * V_229 ,
struct V_207 * V_208 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
T_1 V_708 ;
struct V_209 * V_709 = & V_4 -> V_709 [ V_710 ] ;
int V_212 ;
V_212 = F_119 ( V_2 , V_208 , V_709 ) ;
if ( V_212 )
goto V_82;
V_212 = F_383 ( V_709 , 6 ) ;
if ( V_212 )
goto V_221;
if ( V_124 -> V_148 )
V_708 = V_711 ;
else
V_708 = V_712 ;
F_384 ( V_709 , V_713 | V_708 ) ;
F_384 ( V_709 , V_714 ) ;
F_384 ( V_709 , V_715 |
F_385 ( V_124 -> V_148 ) ) ;
F_384 ( V_709 , V_229 -> V_242 [ 0 ] ) ;
F_384 ( V_709 , V_208 -> V_244 + V_124 -> V_243 ) ;
F_384 ( V_709 , 0 ) ;
F_386 ( V_709 ) ;
return 0 ;
V_221:
F_127 ( V_208 ) ;
V_82:
return V_212 ;
}
static int F_387 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_228 * V_229 ,
struct V_207 * V_208 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
T_1 V_708 ;
struct V_209 * V_709 = & V_4 -> V_709 [ V_710 ] ;
int V_212 ;
V_212 = F_119 ( V_2 , V_208 , V_709 ) ;
if ( V_212 )
goto V_82;
V_212 = F_383 ( V_709 , 6 ) ;
if ( V_212 )
goto V_221;
if ( V_124 -> V_148 )
V_708 = V_711 ;
else
V_708 = V_712 ;
F_384 ( V_709 , V_713 | V_708 ) ;
F_384 ( V_709 , V_714 ) ;
F_384 ( V_709 , V_716 |
F_385 ( V_124 -> V_148 ) ) ;
F_384 ( V_709 , V_229 -> V_242 [ 0 ] ) ;
F_384 ( V_709 , V_208 -> V_244 + V_124 -> V_243 ) ;
F_384 ( V_709 , V_714 ) ;
F_386 ( V_709 ) ;
return 0 ;
V_221:
F_127 ( V_208 ) ;
V_82:
return V_212 ;
}
static int F_388 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_228 * V_229 ,
struct V_207 * V_208 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
T_5 V_717 , V_718 ;
struct V_209 * V_709 = & V_4 -> V_709 [ V_710 ] ;
int V_212 ;
V_212 = F_119 ( V_2 , V_208 , V_709 ) ;
if ( V_212 )
goto V_82;
V_212 = F_383 ( V_709 , 4 ) ;
if ( V_212 )
goto V_221;
F_384 ( V_709 , V_715 |
F_385 ( V_124 -> V_148 ) ) ;
F_384 ( V_709 , V_229 -> V_242 [ 0 ] ) ;
F_384 ( V_709 ,
( V_208 -> V_244 + V_124 -> V_243 ) |
V_208 -> V_213 ) ;
V_717 = 0 ;
V_718 = F_3 ( F_273 ( V_124 -> V_105 ) ) & 0x0fff0fff ;
F_384 ( V_709 , V_717 | V_718 ) ;
F_386 ( V_709 ) ;
return 0 ;
V_221:
F_127 ( V_208 ) ;
V_82:
return V_212 ;
}
static int F_389 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_228 * V_229 ,
struct V_207 * V_208 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_209 * V_709 = & V_4 -> V_709 [ V_710 ] ;
T_5 V_717 , V_718 ;
int V_212 ;
V_212 = F_119 ( V_2 , V_208 , V_709 ) ;
if ( V_212 )
goto V_82;
V_212 = F_383 ( V_709 , 4 ) ;
if ( V_212 )
goto V_221;
F_384 ( V_709 , V_715 |
F_385 ( V_124 -> V_148 ) ) ;
F_384 ( V_709 , V_229 -> V_242 [ 0 ] | V_208 -> V_213 ) ;
F_384 ( V_709 , V_208 -> V_244 + V_124 -> V_243 ) ;
V_717 = 0 ;
V_718 = F_3 ( F_273 ( V_124 -> V_105 ) ) & 0x0fff0fff ;
F_384 ( V_709 , V_717 | V_718 ) ;
F_386 ( V_709 ) ;
return 0 ;
V_221:
F_127 ( V_208 ) ;
V_82:
return V_212 ;
}
static int F_390 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_228 * V_229 ,
struct V_207 * V_208 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_209 * V_709 = & V_4 -> V_709 [ V_719 ] ;
T_5 V_720 = 0 ;
int V_212 ;
V_212 = F_119 ( V_2 , V_208 , V_709 ) ;
if ( V_212 )
goto V_82;
switch( V_124 -> V_148 ) {
case V_721 :
V_720 = V_722 ;
break;
case V_723 :
V_720 = V_724 ;
break;
case V_725 :
V_720 = V_726 ;
break;
default:
F_391 ( 1 , L_147 ) ;
V_212 = - V_727 ;
goto V_221;
}
V_212 = F_383 ( V_709 , 4 ) ;
if ( V_212 )
goto V_221;
F_384 ( V_709 , V_716 | V_720 ) ;
F_384 ( V_709 , ( V_229 -> V_242 [ 0 ] | V_208 -> V_213 ) ) ;
F_384 ( V_709 , V_208 -> V_244 + V_124 -> V_243 ) ;
F_384 ( V_709 , ( V_714 ) ) ;
F_386 ( V_709 ) ;
return 0 ;
V_221:
F_127 ( V_208 ) ;
V_82:
return V_212 ;
}
static int F_392 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_228 * V_229 ,
struct V_207 * V_208 )
{
return - V_727 ;
}
static int F_393 ( struct V_34 * V_35 ,
struct V_228 * V_229 ,
struct V_694 * V_698 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_230 * V_231 ;
struct V_207 * V_208 ;
struct V_124 * V_124 = F_104 ( V_35 ) ;
struct V_688 * V_689 ;
unsigned long V_9 ;
int V_212 ;
if ( V_229 -> V_648 != V_35 -> V_229 -> V_648 )
return - V_217 ;
if ( F_43 ( V_2 ) -> V_109 > 3 &&
( V_229 -> V_728 [ 0 ] != V_35 -> V_229 -> V_728 [ 0 ] ||
V_229 -> V_242 [ 0 ] != V_35 -> V_229 -> V_242 [ 0 ] ) )
return - V_217 ;
V_689 = F_339 ( sizeof *V_689 , V_646 ) ;
if ( V_689 == NULL )
return - V_626 ;
V_689 -> V_698 = V_698 ;
V_689 -> V_2 = V_35 -> V_2 ;
V_231 = F_131 ( V_35 -> V_229 ) ;
V_689 -> V_692 = V_231 -> V_208 ;
F_394 ( & V_689 -> V_689 , F_368 ) ;
V_212 = F_395 ( V_2 , V_124 -> V_105 ) ;
if ( V_212 )
goto V_729;
F_5 ( & V_2 -> V_304 , V_9 ) ;
if ( V_124 -> V_305 ) {
F_9 ( & V_2 -> V_304 , V_9 ) ;
F_223 ( V_689 ) ;
F_374 ( V_2 , V_124 -> V_105 ) ;
F_56 ( L_148 ) ;
return - V_730 ;
}
V_124 -> V_305 = V_689 ;
F_9 ( & V_2 -> V_304 , V_9 ) ;
V_231 = F_131 ( V_229 ) ;
V_208 = V_231 -> V_208 ;
V_212 = F_396 ( V_2 ) ;
if ( V_212 )
goto V_731;
F_397 ( & V_689 -> V_692 -> V_191 ) ;
F_397 ( & V_208 -> V_191 ) ;
V_35 -> V_229 = V_229 ;
V_689 -> V_693 = V_208 ;
V_689 -> V_732 = true ;
F_398 ( 1 << V_124 -> V_148 , & V_689 -> V_692 -> V_255 ) ;
V_212 = V_4 -> V_248 . V_733 ( V_2 , V_35 , V_229 , V_208 ) ;
if ( V_212 )
goto V_734;
F_205 ( V_2 ) ;
F_363 ( V_208 ) ;
F_145 ( & V_2 -> V_259 ) ;
F_399 ( V_124 -> V_148 , V_208 ) ;
return 0 ;
V_734:
F_400 ( 1 << V_124 -> V_148 , & V_689 -> V_692 -> V_255 ) ;
F_332 ( & V_689 -> V_692 -> V_191 ) ;
F_332 ( & V_208 -> V_191 ) ;
F_145 ( & V_2 -> V_259 ) ;
V_731:
F_5 ( & V_2 -> V_304 , V_9 ) ;
V_124 -> V_305 = NULL ;
F_9 ( & V_2 -> V_304 , V_9 ) ;
F_374 ( V_2 , V_124 -> V_105 ) ;
V_729:
F_223 ( V_689 ) ;
return V_212 ;
}
bool F_401 ( struct V_75 * V_76 )
{
struct V_75 * V_735 ;
struct V_34 * V_35 = & V_76 -> V_658 -> V_191 ;
if ( F_99 ( ! V_35 ) )
return false ;
F_217 (other_encoder,
&crtc->dev->mode_config.encoder_list,
base.head) {
if ( & V_735 -> V_658 -> V_191 != V_35 ||
V_76 == V_735 )
continue;
else
return true ;
}
return false ;
}
static bool F_402 ( struct V_379 * V_76 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_34 * V_574 ;
int V_736 = 1 ;
F_46 ( ! V_35 , L_149 ) ;
V_2 = V_35 -> V_2 ;
F_217 (tmp, &dev->mode_config.crtc_list, head) {
if ( V_574 == V_35 )
break;
V_736 <<= 1 ;
}
if ( V_76 -> V_657 & V_736 )
return true ;
return false ;
}
static void F_403 ( struct V_1 * V_2 )
{
struct V_75 * V_76 ;
struct V_381 * V_375 ;
F_217 (connector, &dev->mode_config.connector_list,
base.head) {
V_375 -> V_659 =
F_218 ( V_375 -> V_191 . V_76 ) ;
}
F_217 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_76 -> V_658 =
F_104 ( V_76 -> V_191 . V_35 ) ;
}
}
static void F_404 ( struct V_1 * V_2 )
{
struct V_75 * V_76 ;
struct V_381 * V_375 ;
F_217 (connector, &dev->mode_config.connector_list,
base.head) {
V_375 -> V_191 . V_76 = & V_375 -> V_659 -> V_191 ;
}
F_217 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_76 -> V_191 . V_35 = & V_76 -> V_658 -> V_191 ;
}
}
static struct V_384 *
F_405 ( struct V_34 * V_35 ,
struct V_384 * V_315 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_384 * V_385 ;
struct V_737 * V_738 ;
struct V_75 * V_76 ;
V_385 = F_406 ( V_2 , V_315 ) ;
if ( ! V_385 )
return F_340 ( - V_626 ) ;
F_217 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( & V_76 -> V_658 -> V_191 != V_35 )
continue;
V_738 = V_76 -> V_191 . V_739 ;
if ( ! ( V_738 -> V_740 ( & V_76 -> V_191 , V_315 ,
V_385 ) ) ) {
F_40 ( L_150 ) ;
goto V_627;
}
}
if ( ! ( F_231 ( V_35 , V_315 , V_385 ) ) ) {
F_40 ( L_151 ) ;
goto V_627;
}
F_40 ( L_152 , V_35 -> V_191 . V_24 ) ;
return V_385 ;
V_627:
F_407 ( V_2 , V_385 ) ;
return F_340 ( - V_217 ) ;
}
static void
F_408 ( struct V_34 * V_35 , unsigned * V_741 ,
unsigned * V_742 , unsigned * V_743 )
{
struct V_124 * V_124 ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_75 * V_76 ;
struct V_381 * V_375 ;
struct V_34 * V_744 ;
* V_743 = * V_741 = * V_742 = 0 ;
F_217 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_375 -> V_191 . V_76 == & V_375 -> V_659 -> V_191 )
continue;
if ( V_375 -> V_191 . V_76 ) {
V_744 = V_375 -> V_191 . V_76 -> V_35 ;
* V_742 |= 1 << F_104 ( V_744 ) -> V_105 ;
}
if ( V_375 -> V_659 )
* V_742 |=
1 << V_375 -> V_659 -> V_658 -> V_105 ;
}
F_217 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_76 -> V_191 . V_35 == & V_76 -> V_658 -> V_191 )
continue;
if ( V_76 -> V_191 . V_35 ) {
V_744 = V_76 -> V_191 . V_35 ;
* V_742 |= 1 << F_104 ( V_744 ) -> V_105 ;
}
if ( V_76 -> V_658 )
* V_742 |= 1 << V_76 -> V_658 -> V_105 ;
}
F_217 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
bool V_745 = false ;
if ( ! V_124 -> V_191 . V_118 )
continue;
F_217 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_76 -> V_658 == V_124 )
V_745 = true ;
}
if ( ! V_745 )
* V_743 |= 1 << V_124 -> V_105 ;
}
V_124 = F_104 ( V_35 ) ;
if ( V_35 -> V_118 )
* V_742 |= 1 << V_124 -> V_105 ;
if ( * V_742 )
* V_741 = * V_742 ;
* V_741 &= ~ ( * V_743 ) ;
* V_742 &= ~ ( * V_743 ) ;
}
static bool F_409 ( struct V_34 * V_35 )
{
struct V_379 * V_76 ;
struct V_1 * V_2 = V_35 -> V_2 ;
F_217 (encoder, &dev->mode_config.encoder_list, head)
if ( V_76 -> V_35 == V_35 )
return true ;
return false ;
}
static void
F_410 ( struct V_1 * V_2 , unsigned V_742 )
{
struct V_75 * V_75 ;
struct V_124 * V_124 ;
struct V_374 * V_375 ;
F_217 (intel_encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_75 -> V_191 . V_35 )
continue;
V_124 = F_104 ( V_75 -> V_191 . V_35 ) ;
if ( V_742 & ( 1 << V_124 -> V_105 ) )
V_75 -> V_371 = false ;
}
F_404 ( V_2 ) ;
F_217 (intel_crtc, &dev->mode_config.crtc_list,
base.head) {
V_124 -> V_191 . V_118 = F_409 ( & V_124 -> V_191 ) ;
}
F_217 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_375 -> V_76 || ! V_375 -> V_76 -> V_35 )
continue;
V_124 = F_104 ( V_375 -> V_76 -> V_35 ) ;
if ( V_742 & ( 1 << V_124 -> V_105 ) ) {
struct V_746 * V_747 =
V_2 -> V_522 . V_747 ;
V_375 -> V_377 = V_380 ;
F_411 ( V_375 ,
V_747 ,
V_380 ) ;
V_75 = F_218 ( V_375 -> V_76 ) ;
V_75 -> V_371 = true ;
}
}
}
bool F_353 ( struct V_34 * V_35 ,
struct V_384 * V_315 ,
int V_222 , int V_223 , struct V_228 * V_229 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_384 * V_385 , V_748 , V_749 ;
struct V_737 * V_738 ;
struct V_379 * V_76 ;
struct V_124 * V_124 ;
unsigned V_743 , V_742 , V_741 ;
bool V_212 = true ;
F_408 ( V_35 , & V_741 ,
& V_742 , & V_743 ) ;
F_40 ( L_153 ,
V_741 , V_742 , V_743 ) ;
F_412 (dev, disable_pipes, intel_crtc)
F_215 ( & V_124 -> V_191 ) ;
V_749 = V_35 -> V_750 ;
V_748 = V_35 -> V_315 ;
V_385 = NULL ;
if ( V_741 ) {
V_385 = F_405 ( V_35 , V_315 ) ;
if ( F_352 ( V_385 ) ) {
return false ;
}
}
F_412 (dev, prepare_pipes, intel_crtc) {
if ( V_124 -> V_191 . V_118 )
V_4 -> V_248 . V_373 ( & V_124 -> V_191 ) ;
}
if ( V_741 )
V_35 -> V_315 = * V_315 ;
F_410 ( V_2 , V_742 ) ;
F_412 (dev, modeset_pipes, intel_crtc) {
V_212 = ! F_292 ( & V_124 -> V_191 ,
V_315 , V_385 ,
V_222 , V_223 , V_229 ) ;
if ( ! V_212 )
goto V_751;
F_217 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_76 -> V_35 != & V_124 -> V_191 )
continue;
F_40 ( L_154 ,
V_76 -> V_191 . V_24 , F_311 ( V_76 ) ,
V_315 -> V_191 . V_24 , V_315 -> V_752 ) ;
V_738 = V_76 -> V_739 ;
V_738 -> V_753 ( V_76 , V_315 , V_385 ) ;
}
}
F_412 (dev, prepare_pipes, intel_crtc)
V_4 -> V_248 . V_372 ( & V_124 -> V_191 ) ;
if ( V_741 ) {
V_35 -> V_750 = * V_385 ;
F_413 ( V_35 ) ;
}
V_751:
F_407 ( V_2 , V_385 ) ;
if ( ! V_212 && V_35 -> V_118 ) {
V_35 -> V_750 = V_749 ;
V_35 -> V_315 = V_748 ;
} else {
F_229 ( V_2 ) ;
}
return V_212 ;
}
static void F_414 ( struct V_754 * V_755 )
{
if ( ! V_755 )
return;
F_223 ( V_755 -> V_756 ) ;
F_223 ( V_755 -> V_757 ) ;
F_223 ( V_755 ) ;
}
static int F_415 ( struct V_1 * V_2 ,
struct V_754 * V_755 )
{
struct V_379 * V_76 ;
struct V_374 * V_375 ;
int V_758 ;
V_755 -> V_757 =
F_416 ( V_2 -> V_522 . V_759 ,
sizeof( struct V_34 * ) , V_646 ) ;
if ( ! V_755 -> V_757 )
return - V_626 ;
V_755 -> V_756 =
F_416 ( V_2 -> V_522 . V_760 ,
sizeof( struct V_379 * ) , V_646 ) ;
if ( ! V_755 -> V_756 )
return - V_626 ;
V_758 = 0 ;
F_217 (encoder, &dev->mode_config.encoder_list, head) {
V_755 -> V_757 [ V_758 ++ ] = V_76 -> V_35 ;
}
V_758 = 0 ;
F_217 (connector, &dev->mode_config.connector_list, head) {
V_755 -> V_756 [ V_758 ++ ] = V_375 -> V_76 ;
}
return 0 ;
}
static void F_417 ( struct V_1 * V_2 ,
struct V_754 * V_755 )
{
struct V_75 * V_76 ;
struct V_381 * V_375 ;
int V_758 ;
V_758 = 0 ;
F_217 (encoder, &dev->mode_config.encoder_list, base.head) {
V_76 -> V_658 =
F_104 ( V_755 -> V_757 [ V_758 ++ ] ) ;
}
V_758 = 0 ;
F_217 (connector, &dev->mode_config.connector_list, base.head) {
V_375 -> V_659 =
F_218 ( V_755 -> V_756 [ V_758 ++ ] ) ;
}
}
static void
F_418 ( struct V_761 * V_762 ,
struct V_754 * V_755 )
{
if ( V_762 -> V_35 -> V_229 != V_762 -> V_229 ) {
if ( V_762 -> V_35 -> V_229 == NULL ) {
F_40 ( L_155 ) ;
V_755 -> V_763 = true ;
} else if ( V_762 -> V_229 == NULL ) {
V_755 -> V_763 = true ;
} else if ( V_762 -> V_229 -> V_237 != V_762 -> V_35 -> V_229 -> V_237 ) {
V_755 -> V_763 = true ;
} else if ( V_762 -> V_229 -> V_235 !=
V_762 -> V_35 -> V_229 -> V_235 ) {
V_755 -> V_763 = true ;
} else
V_755 -> V_764 = true ;
}
if ( V_762 -> V_229 && ( V_762 -> V_222 != V_762 -> V_35 -> V_222 || V_762 -> V_223 != V_762 -> V_35 -> V_223 ) )
V_755 -> V_764 = true ;
if ( V_762 -> V_315 && ! F_419 ( V_762 -> V_315 , & V_762 -> V_35 -> V_315 ) ) {
F_40 ( L_156 ) ;
F_268 ( & V_762 -> V_35 -> V_315 ) ;
F_268 ( V_762 -> V_315 ) ;
V_755 -> V_763 = true ;
}
}
static int
F_420 ( struct V_1 * V_2 ,
struct V_761 * V_762 ,
struct V_754 * V_755 )
{
struct V_34 * V_658 ;
struct V_381 * V_375 ;
struct V_75 * V_76 ;
int V_758 , V_765 ;
F_99 ( ! V_762 -> V_229 && ( V_762 -> V_428 != 0 ) ) ;
F_99 ( V_762 -> V_229 && ( V_762 -> V_428 == 0 ) ) ;
V_758 = 0 ;
F_217 (connector, &dev->mode_config.connector_list,
base.head) {
for ( V_765 = 0 ; V_765 < V_762 -> V_428 ; V_765 ++ ) {
if ( V_762 -> V_766 [ V_765 ] == & V_375 -> V_191 ) {
V_375 -> V_659 = V_375 -> V_76 ;
break;
}
}
if ( ( ! V_762 -> V_229 || V_765 == V_762 -> V_428 ) &&
V_375 -> V_191 . V_76 &&
V_375 -> V_191 . V_76 -> V_35 == V_762 -> V_35 ) {
V_375 -> V_659 = NULL ;
F_40 ( L_157 ,
V_375 -> V_191 . V_191 . V_24 ,
F_226 ( & V_375 -> V_191 ) ) ;
}
if ( & V_375 -> V_659 -> V_191 != V_375 -> V_191 . V_76 ) {
F_40 ( L_158 ) ;
V_755 -> V_763 = true ;
}
if ( V_375 -> V_191 . V_767 == V_768 )
V_375 -> V_659 = NULL ;
}
V_758 = 0 ;
F_217 (connector, &dev->mode_config.connector_list,
base.head) {
if ( ! V_375 -> V_659 )
continue;
V_658 = V_375 -> V_659 -> V_191 . V_35 ;
for ( V_765 = 0 ; V_765 < V_762 -> V_428 ; V_765 ++ ) {
if ( V_762 -> V_766 [ V_765 ] == & V_375 -> V_191 )
V_658 = V_762 -> V_35 ;
}
if ( ! F_402 ( & V_375 -> V_659 -> V_191 ,
V_658 ) ) {
return - V_217 ;
}
V_375 -> V_76 -> V_658 = F_104 ( V_658 ) ;
F_40 ( L_159 ,
V_375 -> V_191 . V_191 . V_24 ,
F_226 ( & V_375 -> V_191 ) ,
V_658 -> V_191 . V_24 ) ;
}
F_217 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_217 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_375 -> V_659 == V_76 ) {
F_99 ( ! V_375 -> V_659 -> V_658 ) ;
goto V_769;
}
}
V_76 -> V_658 = NULL ;
V_769:
if ( & V_76 -> V_658 -> V_191 != V_76 -> V_191 . V_35 ) {
F_40 ( L_160 ) ;
V_755 -> V_763 = true ;
}
}
return 0 ;
}
static int F_421 ( struct V_761 * V_762 )
{
struct V_1 * V_2 ;
struct V_761 V_770 ;
struct V_754 * V_755 ;
int V_212 ;
F_90 ( ! V_762 ) ;
F_90 ( ! V_762 -> V_35 ) ;
F_90 ( ! V_762 -> V_35 -> V_739 ) ;
if ( ! V_762 -> V_315 )
V_762 -> V_229 = NULL ;
if ( V_762 -> V_229 && V_762 -> V_428 == 0 )
return 0 ;
if ( V_762 -> V_229 ) {
F_40 ( L_161 ,
V_762 -> V_35 -> V_191 . V_24 , V_762 -> V_229 -> V_191 . V_24 ,
( int ) V_762 -> V_428 , V_762 -> V_222 , V_762 -> V_223 ) ;
} else {
F_40 ( L_162 , V_762 -> V_35 -> V_191 . V_24 ) ;
}
V_2 = V_762 -> V_35 -> V_2 ;
V_212 = - V_626 ;
V_755 = F_339 ( sizeof( * V_755 ) , V_646 ) ;
if ( ! V_755 )
goto V_771;
V_212 = F_415 ( V_2 , V_755 ) ;
if ( V_212 )
goto V_771;
V_770 . V_35 = V_762 -> V_35 ;
V_770 . V_315 = & V_762 -> V_35 -> V_315 ;
V_770 . V_222 = V_762 -> V_35 -> V_222 ;
V_770 . V_223 = V_762 -> V_35 -> V_223 ;
V_770 . V_229 = V_762 -> V_35 -> V_229 ;
F_418 ( V_762 , V_755 ) ;
V_212 = F_420 ( V_2 , V_762 , V_755 ) ;
if ( V_212 )
goto V_627;
if ( V_755 -> V_763 ) {
if ( V_762 -> V_315 ) {
F_40 ( L_163
L_164 ) ;
F_268 ( V_762 -> V_315 ) ;
}
if ( ! F_353 ( V_762 -> V_35 , V_762 -> V_315 ,
V_762 -> V_222 , V_762 -> V_223 , V_762 -> V_229 ) ) {
F_7 ( L_165 ,
V_762 -> V_35 -> V_191 . V_24 ) ;
V_212 = - V_217 ;
goto V_627;
}
} else if ( V_755 -> V_764 ) {
V_212 = F_143 ( V_762 -> V_35 ,
V_762 -> V_222 , V_762 -> V_223 , V_762 -> V_229 ) ;
}
F_414 ( V_755 ) ;
return 0 ;
V_627:
F_417 ( V_2 , V_755 ) ;
if ( V_755 -> V_763 &&
! F_353 ( V_770 . V_35 , V_770 . V_315 ,
V_770 . V_222 , V_770 . V_223 , V_770 . V_229 ) )
F_7 ( L_166 ) ;
V_771:
F_414 ( V_755 ) ;
return V_212 ;
}
static void F_422 ( struct V_1 * V_2 )
{
T_7 * V_4 = V_2 -> V_5 ;
int V_150 ;
if ( V_4 -> V_348 == 0 ) {
F_40 ( L_167 ) ;
return;
}
for ( V_150 = 0 ; V_150 < V_4 -> V_348 ; V_150 ++ ) {
V_4 -> V_347 [ V_150 ] . V_125 = F_423 ( V_150 ) ;
V_4 -> V_347 [ V_150 ] . V_349 = F_424 ( V_150 ) ;
V_4 -> V_347 [ V_150 ] . V_556 = F_425 ( V_150 ) ;
}
}
static void F_426 ( struct V_1 * V_2 , int V_105 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_124 * V_124 ;
int V_150 ;
V_124 = F_339 ( sizeof( struct V_124 ) + ( V_772 * sizeof( struct V_374 * ) ) , V_646 ) ;
if ( V_124 == NULL )
return;
F_427 ( V_2 , & V_124 -> V_191 , & V_773 ) ;
F_428 ( & V_124 -> V_191 , 256 ) ;
for ( V_150 = 0 ; V_150 < 256 ; V_150 ++ ) {
V_124 -> V_591 [ V_150 ] = V_150 ;
V_124 -> V_592 [ V_150 ] = V_150 ;
V_124 -> V_593 [ V_150 ] = V_150 ;
}
V_124 -> V_105 = V_105 ;
V_124 -> V_148 = V_105 ;
if ( F_91 ( V_2 ) && F_270 ( V_2 ) ) {
F_40 ( L_168 ) ;
V_124 -> V_148 = ! V_105 ;
}
F_90 ( V_105 >= F_429 ( V_4 -> V_707 ) ||
V_4 -> V_707 [ V_124 -> V_148 ] != NULL ) ;
V_4 -> V_707 [ V_124 -> V_148 ] = & V_124 -> V_191 ;
V_4 -> V_197 [ V_124 -> V_105 ] = & V_124 -> V_191 ;
V_124 -> V_224 = 24 ;
F_430 ( & V_124 -> V_191 , & V_774 ) ;
}
int F_431 ( struct V_1 * V_2 , void * V_775 ,
struct V_619 * V_620 )
{
struct V_776 * V_777 = V_775 ;
struct V_778 * V_779 ;
struct V_124 * V_35 ;
if ( ! F_432 ( V_2 , V_780 ) )
return - V_727 ;
V_779 = F_433 ( V_2 , V_777 -> V_781 ,
V_782 ) ;
if ( ! V_779 ) {
F_7 ( L_169 ) ;
return - V_217 ;
}
V_35 = F_104 ( F_434 ( V_779 ) ) ;
V_777 -> V_105 = V_35 -> V_105 ;
return 0 ;
}
static int F_435 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = V_76 -> V_191 . V_2 ;
struct V_75 * V_783 ;
int V_784 = 0 ;
int V_785 = 0 ;
F_217 (source_encoder,
&dev->mode_config.encoder_list, base.head) {
if ( V_76 == V_783 )
V_784 |= ( 1 << V_785 ) ;
if ( V_76 -> V_786 && V_783 -> V_786 )
V_784 |= ( 1 << V_785 ) ;
V_785 ++ ;
}
return V_784 ;
}
static bool F_436 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_91 ( V_2 ) )
return false ;
if ( ( F_3 ( V_269 ) & V_787 ) == 0 )
return false ;
if ( F_2 ( V_2 ) &&
( F_3 ( V_788 ) & V_789 ) )
return false ;
return true ;
}
static void F_437 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_75 * V_76 ;
bool V_790 = false ;
bool V_523 ;
V_523 = F_438 ( V_2 ) ;
if ( ! V_523 && ! F_21 ( V_2 ) ) {
F_8 ( V_791 , 0 ) ;
}
if ( F_21 ( V_2 ) ) {
V_790 = F_439 ( V_2 ) ;
if ( F_436 ( V_2 ) )
F_440 ( V_2 , V_269 , V_792 ) ;
if ( V_790 && ( F_3 ( V_177 ) & V_787 ) )
F_440 ( V_2 , V_177 , V_793 ) ;
}
F_441 ( V_2 ) ;
if ( F_59 ( V_2 ) ) {
int V_88 ;
V_88 = F_3 ( V_794 ) & V_795 ;
if ( V_88 )
F_442 ( V_2 , V_792 ) ;
V_88 = F_3 ( V_796 ) ;
if ( V_88 & V_797 )
F_442 ( V_2 , V_798 ) ;
if ( V_88 & V_799 )
F_442 ( V_2 , V_800 ) ;
if ( V_88 & V_801 )
F_442 ( V_2 , V_793 ) ;
} else if ( F_21 ( V_2 ) ) {
int V_88 ;
if ( F_3 ( V_180 ) & V_802 ) {
V_88 = F_443 ( V_2 , V_803 , true ) ;
if ( ! V_88 )
F_444 ( V_2 , V_180 , V_798 ) ;
if ( ! V_88 && ( F_3 ( V_173 ) & V_787 ) )
F_440 ( V_2 , V_173 , V_798 ) ;
}
if ( F_3 ( V_181 ) & V_802 )
F_444 ( V_2 , V_181 , V_800 ) ;
if ( ! V_790 && F_3 ( V_182 ) & V_802 )
F_444 ( V_2 , V_182 , V_793 ) ;
if ( F_3 ( V_175 ) & V_787 )
F_440 ( V_2 , V_175 , V_800 ) ;
if ( ! V_790 && ( F_3 ( V_177 ) & V_787 ) )
F_440 ( V_2 , V_177 , V_793 ) ;
} else if ( F_24 ( V_2 ) ) {
int V_88 ;
if ( F_3 ( V_804 ) & V_802 ) {
V_88 = F_443 ( V_2 , V_804 , true ) ;
if ( ! V_88 )
F_444 ( V_2 , V_804 , V_798 ) ;
if ( ! V_88 && ( F_3 ( V_805 ) & V_787 ) )
F_440 ( V_2 , V_805 , V_798 ) ;
}
if ( F_3 ( V_806 ) & V_802 )
F_444 ( V_2 , V_806 , V_800 ) ;
if ( F_3 ( V_807 ) & V_787 )
F_440 ( V_2 , V_807 , V_800 ) ;
} else if ( F_445 ( V_2 ) ) {
bool V_88 = false ;
if ( F_3 ( V_804 ) & V_808 ) {
F_40 ( L_170 ) ;
V_88 = F_443 ( V_2 , V_804 , true ) ;
if ( ! V_88 && F_446 ( V_2 ) ) {
F_40 ( L_171 ) ;
F_444 ( V_2 , V_804 , V_798 ) ;
}
if ( ! V_88 && F_447 ( V_2 ) ) {
F_40 ( L_172 ) ;
F_440 ( V_2 , V_805 , V_798 ) ;
}
}
if ( F_3 ( V_804 ) & V_808 ) {
F_40 ( L_173 ) ;
V_88 = F_443 ( V_2 , V_806 , false ) ;
}
if ( ! V_88 && ( F_3 ( V_806 ) & V_808 ) ) {
if ( F_446 ( V_2 ) ) {
F_40 ( L_174 ) ;
F_444 ( V_2 , V_806 , V_800 ) ;
}
if ( F_447 ( V_2 ) ) {
F_40 ( L_175 ) ;
F_440 ( V_2 , V_807 , V_800 ) ;
}
}
if ( F_447 ( V_2 ) &&
( F_3 ( V_809 ) & V_787 ) ) {
F_40 ( L_176 ) ;
F_440 ( V_2 , V_809 , V_793 ) ;
}
} else if ( F_25 ( V_2 ) )
F_448 ( V_2 ) ;
if ( F_449 ( V_2 ) )
F_450 ( V_2 ) ;
F_217 (encoder, &dev->mode_config.encoder_list, base.head) {
V_76 -> V_191 . V_657 = V_76 -> V_736 ;
V_76 -> V_191 . V_810 =
F_435 ( V_76 ) ;
}
if ( F_86 ( V_2 ) || F_57 ( V_2 ) )
F_274 ( V_2 ) ;
}
static void F_451 ( struct V_228 * V_229 )
{
struct V_230 * V_231 = F_131 ( V_229 ) ;
F_452 ( V_229 ) ;
F_333 ( & V_231 -> V_208 -> V_191 ) ;
F_223 ( V_231 ) ;
}
static int F_453 ( struct V_228 * V_229 ,
struct V_619 * V_620 ,
unsigned int * V_621 )
{
struct V_230 * V_231 = F_131 ( V_229 ) ;
struct V_207 * V_208 = V_231 -> V_208 ;
return F_454 ( V_620 , & V_208 -> V_191 , V_621 ) ;
}
int F_341 ( struct V_1 * V_2 ,
struct V_230 * V_231 ,
struct V_644 * V_645 ,
struct V_207 * V_208 )
{
int V_212 ;
if ( V_208 -> V_213 == V_216 )
return - V_217 ;
if ( V_645 -> V_242 [ 0 ] & 63 )
return - V_217 ;
switch ( V_645 -> V_648 ) {
case V_811 :
case V_812 :
case V_813 :
case V_814 :
case V_815 :
case V_816 :
case V_817 :
break;
case V_818 :
case V_819 :
case V_820 :
case V_821 :
break;
default:
F_40 ( L_177 ,
V_645 -> V_648 ) ;
return - V_217 ;
}
V_212 = F_455 ( V_2 , & V_231 -> V_191 , & V_822 ) ;
if ( V_212 ) {
F_7 ( L_178 , V_212 ) ;
return V_212 ;
}
F_456 ( & V_231 -> V_191 , V_645 ) ;
V_231 -> V_208 = V_208 ;
return 0 ;
}
static struct V_228 *
F_457 ( struct V_1 * V_2 ,
struct V_619 * V_823 ,
struct V_644 * V_645 )
{
struct V_207 * V_208 ;
V_208 = F_327 ( F_328 ( V_2 , V_823 ,
V_645 -> V_824 [ 0 ] ) ) ;
if ( & V_208 -> V_191 == NULL )
return F_340 ( - V_624 ) ;
return F_338 ( V_2 , V_645 , V_208 ) ;
}
static void F_458 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_21 ( V_2 ) ) {
V_4 -> V_248 . V_557 = F_278 ;
V_4 -> V_248 . V_372 = F_196 ;
V_4 -> V_248 . V_373 = F_203 ;
V_4 -> V_248 . V_376 = F_206 ;
V_4 -> V_248 . V_250 = F_136 ;
} else {
V_4 -> V_248 . V_557 = F_267 ;
V_4 -> V_248 . V_372 = F_209 ;
V_4 -> V_248 . V_373 = F_210 ;
V_4 -> V_248 . V_376 = F_211 ;
V_4 -> V_248 . V_250 = F_130 ;
}
if ( F_24 ( V_2 ) )
V_4 -> V_248 . V_499 =
F_233 ;
else if ( F_262 ( V_2 ) || ( F_264 ( V_2 ) && ! F_459 ( V_2 ) ) )
V_4 -> V_248 . V_499 =
F_234 ;
else if ( F_460 ( V_2 ) )
V_4 -> V_248 . V_499 =
F_235 ;
else if ( F_263 ( V_2 ) || F_324 ( V_2 ) || F_459 ( V_2 ) )
V_4 -> V_248 . V_499 =
F_236 ;
else if ( F_461 ( V_2 ) )
V_4 -> V_248 . V_499 =
F_237 ;
else if ( F_325 ( V_2 ) )
V_4 -> V_248 . V_499 =
F_239 ;
else if ( F_462 ( V_2 ) )
V_4 -> V_248 . V_499 =
F_240 ;
else
V_4 -> V_248 . V_499 =
F_241 ;
if ( F_21 ( V_2 ) ) {
if ( F_2 ( V_2 ) ) {
V_4 -> V_248 . V_327 = F_153 ;
V_4 -> V_248 . V_589 = F_302 ;
} else if ( F_159 ( V_2 ) ) {
V_4 -> V_248 . V_327 = F_158 ;
V_4 -> V_248 . V_589 = F_302 ;
} else if ( F_149 ( V_2 ) ) {
V_4 -> V_248 . V_327 = F_160 ;
V_4 -> V_248 . V_589 = F_302 ;
} else if ( F_59 ( V_2 ) ) {
V_4 -> V_248 . V_327 = V_825 ;
V_4 -> V_248 . V_589 = F_298 ;
} else
V_4 -> V_248 . V_826 = NULL ;
} else if ( F_22 ( V_2 ) ) {
V_4 -> V_248 . V_589 = F_296 ;
}
V_4 -> V_248 . V_733 = F_392 ;
switch ( F_43 ( V_2 ) -> V_109 ) {
case 2 :
V_4 -> V_248 . V_733 = F_382 ;
break;
case 3 :
V_4 -> V_248 . V_733 = F_387 ;
break;
case 4 :
case 5 :
V_4 -> V_248 . V_733 = F_388 ;
break;
case 6 :
V_4 -> V_248 . V_733 = F_389 ;
break;
case 7 :
V_4 -> V_248 . V_733 = F_390 ;
break;
}
}
static void F_463 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_145 |= V_146 ;
F_14 ( L_179 ) ;
}
static void F_464 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_145 |= V_417 ;
F_14 ( L_180 ) ;
}
static void F_465 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_145 |= V_827 ;
F_14 ( L_181 ) ;
}
static int F_466 ( const struct V_23 * V_24 )
{
F_14 ( L_182 , V_24 -> V_25 ) ;
return 1 ;
}
static void F_467 ( struct V_1 * V_2 )
{
struct V_828 * V_829 = V_2 -> V_391 ;
int V_150 ;
for ( V_150 = 0 ; V_150 < F_429 ( V_830 ) ; V_150 ++ ) {
struct V_831 * V_832 = & V_830 [ V_150 ] ;
if ( V_829 -> V_833 == V_832 -> V_833 &&
( V_829 -> V_834 == V_832 -> V_834 ||
V_832 -> V_834 == V_835 ) &&
( V_829 -> V_836 == V_832 -> V_836 ||
V_832 -> V_836 == V_835 ) )
V_832 -> V_837 ( V_2 ) ;
}
for ( V_150 = 0 ; V_150 < F_429 ( V_838 ) ; V_150 ++ ) {
if ( F_16 ( * V_838 [ V_150 ] . V_839 ) != 0 )
V_838 [ V_150 ] . V_837 ( V_2 ) ;
}
}
static void F_468 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_8 V_840 ;
T_1 V_841 ;
if ( F_21 ( V_2 ) )
V_841 = V_842 ;
else
V_841 = V_843 ;
F_469 ( V_2 -> V_391 , V_844 ) ;
F_470 ( V_845 , V_846 ) ;
V_840 = F_471 ( V_847 ) ;
F_470 ( V_840 | 1 << 5 , V_847 ) ;
F_472 ( V_2 -> V_391 , V_844 ) ;
F_93 ( 300 ) ;
F_8 ( V_841 , V_848 ) ;
F_12 ( V_841 ) ;
}
void F_473 ( struct V_1 * V_2 )
{
F_474 ( V_2 ) ;
F_475 ( V_2 ) ;
F_476 ( V_2 ) ;
F_144 ( & V_2 -> V_259 ) ;
F_477 ( V_2 ) ;
F_145 ( & V_2 -> V_259 ) ;
}
void F_478 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_150 , V_212 ;
F_479 ( V_2 ) ;
V_2 -> V_522 . V_849 = 0 ;
V_2 -> V_522 . V_850 = 0 ;
V_2 -> V_522 . V_851 = 24 ;
V_2 -> V_522 . V_852 = 1 ;
V_2 -> V_522 . V_656 = & V_853 ;
F_467 ( V_2 ) ;
F_480 ( V_2 ) ;
F_458 ( V_2 ) ;
if ( F_25 ( V_2 ) ) {
V_2 -> V_522 . V_854 = 2048 ;
V_2 -> V_522 . V_855 = 2048 ;
} else if ( F_270 ( V_2 ) ) {
V_2 -> V_522 . V_854 = 4096 ;
V_2 -> V_522 . V_855 = 4096 ;
} else {
V_2 -> V_522 . V_854 = 8192 ;
V_2 -> V_522 . V_855 = 8192 ;
}
V_2 -> V_522 . V_856 = V_4 -> V_218 . V_857 ;
F_40 ( L_183 ,
V_4 -> V_258 , V_4 -> V_258 > 1 ? L_184 : L_185 ) ;
for ( V_150 = 0 ; V_150 < V_4 -> V_258 ; V_150 ++ ) {
F_426 ( V_2 , V_150 ) ;
V_212 = F_481 ( V_2 , V_150 ) ;
if ( V_212 )
F_40 ( L_186 , V_150 , V_212 ) ;
}
F_422 ( V_2 ) ;
F_468 ( V_2 ) ;
F_437 ( V_2 ) ;
}
static void
F_482 ( struct V_381 * V_375 )
{
V_375 -> V_191 . V_377 = V_378 ;
V_375 -> V_191 . V_76 = NULL ;
V_375 -> V_76 -> V_371 = false ;
V_375 -> V_76 -> V_191 . V_35 = NULL ;
}
static void F_483 ( struct V_1 * V_2 )
{
struct V_381 * V_375 ;
struct V_374 * V_858 = NULL ;
struct V_651 V_655 ;
F_217 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_375 -> V_76 -> type == V_52 ) {
V_858 = & V_375 -> V_191 ;
break;
}
}
if ( ! V_858 )
return;
if ( F_350 ( V_858 , NULL , & V_655 ) )
F_354 ( V_858 , & V_655 ) ;
}
static bool
F_484 ( struct V_124 * V_35 )
{
struct V_3 * V_4 = V_35 -> V_191 . V_2 -> V_5 ;
T_1 V_8 , V_10 ;
if ( V_4 -> V_258 == 1 )
return true ;
V_8 = F_70 ( ! V_35 -> V_148 ) ;
V_10 = F_3 ( V_8 ) ;
if ( ( V_10 & V_149 ) &&
( ! ! ( V_10 & V_152 ) == V_35 -> V_105 ) )
return false ;
return true ;
}
static void F_485 ( struct V_124 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_191 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_8 ;
V_8 = F_45 ( V_35 -> V_105 ) ;
F_8 ( V_8 , F_3 ( V_8 ) & ~ V_859 ) ;
if ( F_43 ( V_2 ) -> V_109 < 4 && ! F_484 ( V_35 ) ) {
struct V_381 * V_375 ;
bool V_148 ;
F_40 ( L_187 ,
V_35 -> V_191 . V_191 . V_24 ) ;
V_148 = V_35 -> V_148 ;
V_35 -> V_148 = ! V_148 ;
V_4 -> V_248 . V_373 ( & V_35 -> V_191 ) ;
V_35 -> V_148 = V_148 ;
F_217 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_375 -> V_76 -> V_191 . V_35 != & V_35 -> V_191 )
continue;
F_482 ( V_375 ) ;
}
F_99 ( V_35 -> V_194 ) ;
V_35 -> V_191 . V_118 = false ;
}
if ( V_4 -> V_145 & V_146 &&
V_35 -> V_105 == V_137 && ! V_35 -> V_194 ) {
F_483 ( V_2 ) ;
}
F_213 ( & V_35 -> V_191 ) ;
if ( V_35 -> V_194 != V_35 -> V_191 . V_118 ) {
struct V_75 * V_76 ;
F_40 ( L_188 ,
V_35 -> V_191 . V_191 . V_24 ,
V_35 -> V_191 . V_118 ? L_189 : L_190 ,
V_35 -> V_194 ? L_189 : L_190 ) ;
V_35 -> V_191 . V_118 = V_35 -> V_194 ;
F_99 ( V_35 -> V_194 ) ;
F_28 (dev, &crtc->base, encoder) {
F_99 ( V_76 -> V_371 ) ;
V_76 -> V_191 . V_35 = NULL ;
}
}
}
static void F_486 ( struct V_75 * V_76 )
{
struct V_381 * V_375 ;
struct V_1 * V_2 = V_76 -> V_191 . V_2 ;
bool V_860 = V_76 -> V_191 . V_35 &&
F_104 ( V_76 -> V_191 . V_35 ) -> V_194 ;
if ( V_76 -> V_371 && ! V_860 ) {
F_40 ( L_191 ,
V_76 -> V_191 . V_191 . V_24 ,
F_311 ( & V_76 -> V_191 ) ) ;
if ( V_76 -> V_191 . V_35 ) {
F_40 ( L_192 ,
V_76 -> V_191 . V_191 . V_24 ,
F_311 ( & V_76 -> V_191 ) ) ;
V_76 -> V_360 ( V_76 ) ;
}
F_217 (connector,
&dev->mode_config.connector_list,
base.head) {
if ( V_375 -> V_76 != V_76 )
continue;
F_482 ( V_375 ) ;
}
}
}
void F_487 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
enum V_105 V_105 ;
T_1 V_574 ;
struct V_124 * V_35 ;
struct V_75 * V_76 ;
struct V_381 * V_375 ;
F_488 (pipe) {
V_35 = F_104 ( V_4 -> V_197 [ V_105 ] ) ;
V_574 = F_3 ( F_45 ( V_105 ) ) ;
if ( V_574 & V_147 )
V_35 -> V_194 = true ;
else
V_35 -> V_194 = false ;
V_35 -> V_191 . V_118 = V_35 -> V_194 ;
F_40 ( L_193 ,
V_35 -> V_191 . V_191 . V_24 ,
V_35 -> V_194 ? L_189 : L_190 ) ;
}
F_217 (encoder, &dev->mode_config.encoder_list,
base.head) {
V_105 = 0 ;
if ( V_76 -> V_382 ( V_76 , & V_105 ) ) {
V_76 -> V_191 . V_35 =
V_4 -> V_197 [ V_105 ] ;
} else {
V_76 -> V_191 . V_35 = NULL ;
}
V_76 -> V_371 = false ;
F_40 ( L_194 ,
V_76 -> V_191 . V_191 . V_24 ,
F_311 ( & V_76 -> V_191 ) ,
V_76 -> V_191 . V_35 ? L_189 : L_190 ,
V_105 ) ;
}
F_217 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_375 -> V_382 ( V_375 ) ) {
V_375 -> V_191 . V_377 = V_380 ;
V_375 -> V_76 -> V_371 = true ;
V_375 -> V_191 . V_76 = & V_375 -> V_76 -> V_191 ;
} else {
V_375 -> V_191 . V_377 = V_378 ;
V_375 -> V_191 . V_76 = NULL ;
}
F_40 ( L_195 ,
V_375 -> V_191 . V_191 . V_24 ,
F_226 ( & V_375 -> V_191 ) ,
V_375 -> V_191 . V_76 ? L_189 : L_190 ) ;
}
F_217 (encoder, &dev->mode_config.encoder_list,
base.head) {
F_486 ( V_76 ) ;
}
F_488 (pipe) {
V_35 = F_104 ( V_4 -> V_197 [ V_105 ] ) ;
F_485 ( V_35 ) ;
}
F_403 ( V_2 ) ;
F_229 ( V_2 ) ;
}
void F_489 ( struct V_1 * V_2 )
{
F_473 ( V_2 ) ;
F_490 ( V_2 ) ;
F_487 ( V_2 ) ;
}
void F_491 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_34 * V_35 ;
struct V_124 * V_124 ;
F_492 ( V_2 ) ;
F_144 ( & V_2 -> V_259 ) ;
F_493 () ;
F_217 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_35 -> V_229 )
continue;
V_124 = F_104 ( V_35 ) ;
F_138 ( V_35 ) ;
}
F_205 ( V_2 ) ;
F_494 ( V_2 ) ;
F_495 ( V_2 ) ;
if ( F_24 ( V_2 ) )
F_11 ( V_2 ) ;
F_145 ( & V_2 -> V_259 ) ;
F_496 ( V_2 ) ;
F_366 ( & V_4 -> V_861 ) ;
F_366 ( & V_4 -> V_862 . V_689 ) ;
F_497 () ;
F_498 ( V_2 ) ;
}
struct V_379 * F_499 ( struct V_374 * V_375 )
{
return & F_228 ( V_375 ) -> V_191 ;
}
void F_500 ( struct V_381 * V_375 ,
struct V_75 * V_76 )
{
V_375 -> V_76 = V_76 ;
F_501 ( & V_375 -> V_191 ,
& V_76 -> V_191 ) ;
}
int F_502 ( struct V_1 * V_2 , bool V_119 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_863 ;
F_238 ( V_4 -> V_864 , V_865 , & V_863 ) ;
if ( V_119 )
V_863 &= ~ V_866 ;
else
V_863 |= V_866 ;
F_503 ( V_4 -> V_864 , V_865 , V_863 ) ;
return 0 ;
}
struct V_867 *
F_504 ( struct V_1 * V_2 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_867 * error ;
int V_150 ;
error = F_505 ( sizeof( * error ) , V_868 ) ;
if ( error == NULL )
return NULL ;
F_488 (i) {
error -> V_869 [ V_150 ] . V_870 = F_3 ( F_317 ( V_150 ) ) ;
error -> V_869 [ V_150 ] . V_871 = F_3 ( F_323 ( V_150 ) ) ;
error -> V_869 [ V_150 ] . V_191 = F_3 ( F_318 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_870 = F_3 ( F_70 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_872 = F_3 ( F_132 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_625 = F_3 ( F_271 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_610 = F_3 ( F_272 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_622 = F_3 ( F_114 ( V_150 ) ) ;
if ( F_43 ( V_2 ) -> V_109 >= 4 ) {
error -> V_148 [ V_150 ] . V_873 = F_3 ( F_115 ( V_150 ) ) ;
error -> V_148 [ V_150 ] . V_874 = F_3 ( F_134 ( V_150 ) ) ;
}
error -> V_105 [ V_150 ] . V_875 = F_3 ( F_45 ( V_150 ) ) ;
error -> V_105 [ V_150 ] . V_876 = F_3 ( F_273 ( V_150 ) ) ;
error -> V_105 [ V_150 ] . V_682 = F_3 ( F_178 ( V_150 ) ) ;
error -> V_105 [ V_150 ] . V_877 = F_3 ( F_180 ( V_150 ) ) ;
error -> V_105 [ V_150 ] . V_679 = F_3 ( F_182 ( V_150 ) ) ;
error -> V_105 [ V_150 ] . V_684 = F_3 ( F_184 ( V_150 ) ) ;
error -> V_105 [ V_150 ] . V_878 = F_3 ( F_186 ( V_150 ) ) ;
error -> V_105 [ V_150 ] . V_681 = F_3 ( F_188 ( V_150 ) ) ;
}
return error ;
}
void
F_506 ( struct V_879 * V_66 ,
struct V_1 * V_2 ,
struct V_867 * error )
{
T_7 * V_4 = V_2 -> V_5 ;
int V_150 ;
F_507 ( V_66 , L_196 , V_4 -> V_258 ) ;
F_488 (i) {
F_507 ( V_66 , L_197 , V_150 ) ;
F_507 ( V_66 , L_198 , error -> V_105 [ V_150 ] . V_875 ) ;
F_507 ( V_66 , L_199 , error -> V_105 [ V_150 ] . V_876 ) ;
F_507 ( V_66 , L_200 , error -> V_105 [ V_150 ] . V_682 ) ;
F_507 ( V_66 , L_201 , error -> V_105 [ V_150 ] . V_877 ) ;
F_507 ( V_66 , L_202 , error -> V_105 [ V_150 ] . V_679 ) ;
F_507 ( V_66 , L_203 , error -> V_105 [ V_150 ] . V_684 ) ;
F_507 ( V_66 , L_204 , error -> V_105 [ V_150 ] . V_878 ) ;
F_507 ( V_66 , L_205 , error -> V_105 [ V_150 ] . V_681 ) ;
F_507 ( V_66 , L_206 , V_150 ) ;
F_507 ( V_66 , L_207 , error -> V_148 [ V_150 ] . V_870 ) ;
F_507 ( V_66 , L_208 , error -> V_148 [ V_150 ] . V_872 ) ;
F_507 ( V_66 , L_209 , error -> V_148 [ V_150 ] . V_625 ) ;
F_507 ( V_66 , L_210 , error -> V_148 [ V_150 ] . V_610 ) ;
F_507 ( V_66 , L_211 , error -> V_148 [ V_150 ] . V_622 ) ;
if ( F_43 ( V_2 ) -> V_109 >= 4 ) {
F_507 ( V_66 , L_212 , error -> V_148 [ V_150 ] . V_873 ) ;
F_507 ( V_66 , L_213 , error -> V_148 [ V_150 ] . V_874 ) ;
}
F_507 ( V_66 , L_214 , V_150 ) ;
F_507 ( V_66 , L_207 , error -> V_869 [ V_150 ] . V_870 ) ;
F_507 ( V_66 , L_210 , error -> V_869 [ V_150 ] . V_871 ) ;
F_507 ( V_66 , L_215 , error -> V_869 [ V_150 ] . V_191 ) ;
}
}
