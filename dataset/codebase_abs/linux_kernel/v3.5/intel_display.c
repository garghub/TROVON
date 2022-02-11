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
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_8 ( V_21 , 0 ) ;
F_11 ( V_21 ) ;
F_8 ( V_21 , 1 ) ;
F_11 ( V_21 ) ;
}
static int F_12 ( const struct V_22 * V_23 )
{
F_13 ( L_3 , V_23 -> V_24 ) ;
return 1 ;
}
static bool F_14 ( struct V_3 * V_4 ,
unsigned int V_8 )
{
unsigned int V_10 ;
if ( V_25 > 0 )
return V_25 == 2 ;
if ( F_15 ( V_26 ) )
return true ;
if ( V_4 -> V_27 )
V_10 = V_4 -> V_27 ;
else {
V_10 = F_3 ( V_8 ) ;
if ( ! ( V_10 & ~ V_28 ) )
V_10 = V_4 -> V_29 ;
V_4 -> V_27 = V_10 ;
}
return ( V_10 & V_30 ) == V_31 ;
}
static const T_2 * F_16 ( struct V_32 * V_33 ,
int V_34 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const T_2 * V_35 ;
if ( F_17 ( V_33 , V_36 ) ) {
if ( F_14 ( V_4 , V_37 ) ) {
if ( V_34 == 100000 )
V_35 = & V_38 ;
else
V_35 = & V_39 ;
} else {
if ( V_34 == 100000 )
V_35 = & V_40 ;
else
V_35 = & V_41 ;
}
} else if ( F_17 ( V_33 , V_42 ) ||
V_43 )
V_35 = & V_44 ;
else
V_35 = & V_45 ;
return V_35 ;
}
static const T_2 * F_18 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const T_2 * V_35 ;
if ( F_17 ( V_33 , V_36 ) ) {
if ( F_14 ( V_4 , V_46 ) )
V_35 = & V_47 ;
else
V_35 = & V_48 ;
} else if ( F_17 ( V_33 , V_49 ) ||
F_17 ( V_33 , V_50 ) ) {
V_35 = & V_51 ;
} else if ( F_17 ( V_33 , V_52 ) ) {
V_35 = & V_53 ;
} else if ( F_17 ( V_33 , V_42 ) ) {
V_35 = & V_54 ;
} else
V_35 = & V_55 ;
return V_35 ;
}
static const T_2 * F_19 ( struct V_32 * V_33 , int V_34 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
const T_2 * V_35 ;
if ( F_20 ( V_2 ) )
V_35 = F_16 ( V_33 , V_34 ) ;
else if ( F_21 ( V_2 ) ) {
V_35 = F_18 ( V_33 ) ;
} else if ( F_22 ( V_2 ) ) {
if ( F_17 ( V_33 , V_36 ) )
V_35 = & V_56 ;
else
V_35 = & V_57 ;
} else if ( ! F_23 ( V_2 ) ) {
if ( F_17 ( V_33 , V_36 ) )
V_35 = & V_58 ;
else
V_35 = & V_55 ;
} else {
if ( F_17 ( V_33 , V_36 ) )
V_35 = & V_59 ;
else
V_35 = & V_60 ;
}
return V_35 ;
}
static void F_24 ( int V_34 , T_3 * clock )
{
clock -> V_61 = clock -> V_62 + 2 ;
clock -> V_63 = clock -> V_64 * clock -> V_65 ;
clock -> V_66 = V_34 * clock -> V_61 / clock -> V_67 ;
clock -> V_68 = clock -> V_66 / clock -> V_63 ;
}
static void F_25 ( struct V_1 * V_2 , int V_34 , T_3 * clock )
{
if ( F_22 ( V_2 ) ) {
F_24 ( V_34 , clock ) ;
return;
}
clock -> V_61 = 5 * ( clock -> V_69 + 2 ) + ( clock -> V_62 + 2 ) ;
clock -> V_63 = clock -> V_64 * clock -> V_65 ;
clock -> V_66 = V_34 * clock -> V_61 / ( clock -> V_67 + 2 ) ;
clock -> V_68 = clock -> V_66 / clock -> V_63 ;
}
bool F_17 ( struct V_32 * V_33 , int type )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_70 * V_71 = & V_2 -> V_71 ;
struct V_72 * V_73 ;
F_26 (encoder, &mode_config->encoder_list, base.head)
if ( V_73 -> V_74 . V_33 == V_33 && V_73 -> type == type )
return true ;
return false ;
}
static bool F_27 ( struct V_1 * V_2 ,
const T_2 * V_35 ,
const T_3 * clock )
{
if ( clock -> V_64 < V_35 -> V_64 . V_75 || V_35 -> V_64 . V_76 < clock -> V_64 )
F_28 ( L_4 ) ;
if ( clock -> V_63 < V_35 -> V_63 . V_75 || V_35 -> V_63 . V_76 < clock -> V_63 )
F_28 ( L_5 ) ;
if ( clock -> V_62 < V_35 -> V_62 . V_75 || V_35 -> V_62 . V_76 < clock -> V_62 )
F_28 ( L_6 ) ;
if ( clock -> V_69 < V_35 -> V_69 . V_75 || V_35 -> V_69 . V_76 < clock -> V_69 )
F_28 ( L_7 ) ;
if ( clock -> V_69 <= clock -> V_62 && ! F_22 ( V_2 ) )
F_28 ( L_8 ) ;
if ( clock -> V_61 < V_35 -> V_61 . V_75 || V_35 -> V_61 . V_76 < clock -> V_61 )
F_28 ( L_9 ) ;
if ( clock -> V_67 < V_35 -> V_67 . V_75 || V_35 -> V_67 . V_76 < clock -> V_67 )
F_28 ( L_10 ) ;
if ( clock -> V_66 < V_35 -> V_66 . V_75 || V_35 -> V_66 . V_76 < clock -> V_66 )
F_28 ( L_11 ) ;
if ( clock -> V_68 < V_35 -> V_68 . V_75 || V_35 -> V_68 . V_76 < clock -> V_68 )
F_28 ( L_12 ) ;
return true ;
}
static bool
F_29 ( const T_2 * V_35 , struct V_32 * V_33 ,
int V_77 , int V_34 , T_3 * V_78 ,
T_3 * V_79 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 clock ;
int V_80 = V_77 ;
if ( F_17 ( V_33 , V_36 ) &&
( F_3 ( V_46 ) ) != 0 ) {
if ( F_14 ( V_4 , V_46 ) )
clock . V_65 = V_35 -> V_65 . V_81 ;
else
clock . V_65 = V_35 -> V_65 . V_82 ;
} else {
if ( V_77 < V_35 -> V_65 . V_83 )
clock . V_65 = V_35 -> V_65 . V_82 ;
else
clock . V_65 = V_35 -> V_65 . V_81 ;
}
memset ( V_79 , 0 , sizeof( * V_79 ) ) ;
for ( clock . V_69 = V_35 -> V_69 . V_75 ; clock . V_69 <= V_35 -> V_69 . V_76 ;
clock . V_69 ++ ) {
for ( clock . V_62 = V_35 -> V_62 . V_75 ;
clock . V_62 <= V_35 -> V_62 . V_76 ; clock . V_62 ++ ) {
if ( clock . V_62 >= clock . V_69 && ! F_22 ( V_2 ) )
break;
for ( clock . V_67 = V_35 -> V_67 . V_75 ;
clock . V_67 <= V_35 -> V_67 . V_76 ; clock . V_67 ++ ) {
for ( clock . V_64 = V_35 -> V_64 . V_75 ;
clock . V_64 <= V_35 -> V_64 . V_76 ; clock . V_64 ++ ) {
int V_84 ;
F_25 ( V_2 , V_34 , & clock ) ;
if ( ! F_27 ( V_2 , V_35 ,
& clock ) )
continue;
if ( V_78 &&
clock . V_63 != V_78 -> V_63 )
continue;
V_84 = abs ( clock . V_68 - V_77 ) ;
if ( V_84 < V_80 ) {
* V_79 = clock ;
V_80 = V_84 ;
}
}
}
}
}
return ( V_80 != V_77 ) ;
}
static bool
F_30 ( const T_2 * V_35 , struct V_32 * V_33 ,
int V_77 , int V_34 , T_3 * V_78 ,
T_3 * V_79 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 clock ;
int V_85 ;
bool V_86 ;
int V_87 = ( V_77 >> 8 ) + ( V_77 >> 9 ) ;
V_86 = false ;
if ( F_17 ( V_33 , V_36 ) ) {
int V_88 ;
if ( F_20 ( V_2 ) )
V_88 = V_37 ;
else
V_88 = V_46 ;
if ( ( F_3 ( V_88 ) & V_30 ) ==
V_31 )
clock . V_65 = V_35 -> V_65 . V_81 ;
else
clock . V_65 = V_35 -> V_65 . V_82 ;
} else {
if ( V_77 < V_35 -> V_65 . V_83 )
clock . V_65 = V_35 -> V_65 . V_82 ;
else
clock . V_65 = V_35 -> V_65 . V_81 ;
}
memset ( V_79 , 0 , sizeof( * V_79 ) ) ;
V_85 = V_35 -> V_67 . V_76 ;
for ( clock . V_67 = V_35 -> V_67 . V_75 ; clock . V_67 <= V_85 ; clock . V_67 ++ ) {
for ( clock . V_69 = V_35 -> V_69 . V_76 ;
clock . V_69 >= V_35 -> V_69 . V_75 ; clock . V_69 -- ) {
for ( clock . V_62 = V_35 -> V_62 . V_76 ;
clock . V_62 >= V_35 -> V_62 . V_75 ; clock . V_62 -- ) {
for ( clock . V_64 = V_35 -> V_64 . V_76 ;
clock . V_64 >= V_35 -> V_64 . V_75 ; clock . V_64 -- ) {
int V_84 ;
F_25 ( V_2 , V_34 , & clock ) ;
if ( ! F_27 ( V_2 , V_35 ,
& clock ) )
continue;
if ( V_78 &&
clock . V_63 != V_78 -> V_63 )
continue;
V_84 = abs ( clock . V_68 - V_77 ) ;
if ( V_84 < V_87 ) {
* V_79 = clock ;
V_87 = V_84 ;
V_85 = clock . V_67 ;
V_86 = true ;
}
}
}
}
}
return V_86 ;
}
static bool
F_31 ( const T_2 * V_35 , struct V_32 * V_33 ,
int V_77 , int V_34 , T_3 * V_78 ,
T_3 * V_79 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
T_3 clock ;
if ( V_77 < 200000 ) {
clock . V_67 = 1 ;
clock . V_64 = 2 ;
clock . V_65 = 10 ;
clock . V_69 = 12 ;
clock . V_62 = 9 ;
} else {
clock . V_67 = 2 ;
clock . V_64 = 1 ;
clock . V_65 = 10 ;
clock . V_69 = 14 ;
clock . V_62 = 8 ;
}
F_25 ( V_2 , V_34 , & clock ) ;
memcpy ( V_79 , & clock , sizeof( T_3 ) ) ;
return true ;
}
static bool
F_32 ( const T_2 * V_35 , struct V_32 * V_33 ,
int V_77 , int V_34 , T_3 * V_78 ,
T_3 * V_79 )
{
T_3 clock ;
if ( V_77 < 200000 ) {
clock . V_64 = 2 ;
clock . V_65 = 10 ;
clock . V_67 = 2 ;
clock . V_69 = 23 ;
clock . V_62 = 8 ;
} else {
clock . V_64 = 1 ;
clock . V_65 = 10 ;
clock . V_67 = 1 ;
clock . V_69 = 14 ;
clock . V_62 = 2 ;
}
clock . V_61 = 5 * ( clock . V_69 + 2 ) + ( clock . V_62 + 2 ) ;
clock . V_63 = ( clock . V_64 * clock . V_65 ) ;
clock . V_68 = 96000 * clock . V_61 / ( clock . V_67 + 2 ) / clock . V_63 ;
clock . V_66 = 0 ;
memcpy ( V_79 , & clock , sizeof( T_3 ) ) ;
return true ;
}
static void F_33 ( struct V_1 * V_2 , int V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_90 , V_91 = F_34 ( V_89 ) ;
V_90 = F_3 ( V_91 ) ;
if ( F_35 ( F_36 ( V_91 ) != V_90 , 50 ) )
F_37 ( L_13 ) ;
}
void F_38 ( struct V_1 * V_2 , int V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_92 = F_39 ( V_89 ) ;
if ( F_40 ( V_2 ) -> V_93 >= 5 ) {
F_33 ( V_2 , V_89 ) ;
return;
}
F_8 ( V_92 ,
F_3 ( V_92 ) | V_94 ) ;
if ( F_35 ( F_3 ( V_92 ) &
V_94 ,
50 ) )
F_37 ( L_13 ) ;
}
void F_41 ( struct V_1 * V_2 , int V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_40 ( V_2 ) -> V_93 >= 4 ) {
int V_8 = F_42 ( V_89 ) ;
if ( F_35 ( ( F_3 ( V_8 ) & V_95 ) == 0 ,
100 ) )
F_37 ( L_14 ) ;
} else {
T_1 V_96 , V_97 ;
int V_8 = F_43 ( V_89 ) ;
unsigned long V_98 = V_99 + F_44 ( 100 ) ;
if ( F_23 ( V_2 ) )
V_97 = V_100 ;
else
V_97 = V_101 ;
do {
V_96 = F_3 ( V_8 ) & V_97 ;
F_45 ( 5 ) ;
} while ( ( ( F_3 ( V_8 ) & V_97 ) != V_96 ) &&
F_46 ( V_98 , V_99 ) );
if ( F_46 ( V_99 , V_98 ) )
F_37 ( L_14 ) ;
}
}
static const char * F_47 ( bool V_102 )
{
return V_102 ? L_15 : L_16 ;
}
static void F_48 ( struct V_3 * V_4 ,
enum V_89 V_89 , bool V_103 )
{
int V_8 ;
T_1 V_10 ;
bool V_104 ;
V_8 = F_49 ( V_89 ) ;
V_10 = F_3 ( V_8 ) ;
V_104 = ! ! ( V_10 & V_105 ) ;
F_50 ( V_104 != V_103 ,
L_17 ,
F_47 ( V_103 ) , F_47 ( V_104 ) ) ;
}
static void F_51 ( struct V_3 * V_4 ,
struct V_106 * V_107 ,
struct V_108 * V_33 ,
bool V_103 )
{
T_1 V_10 ;
bool V_104 ;
if ( F_52 ( V_4 -> V_2 ) ) {
F_53 ( L_18 ) ;
return;
}
if ( F_50 ( ! V_107 ,
L_19 , F_47 ( V_103 ) ) )
return;
V_10 = F_3 ( V_107 -> V_109 ) ;
V_104 = ! ! ( V_10 & V_105 ) ;
F_50 ( V_104 != V_103 ,
L_20 ,
V_107 -> V_109 , F_47 ( V_103 ) , F_47 ( V_104 ) , V_10 ) ;
if ( V_33 && F_54 ( V_4 -> V_2 ) ) {
T_1 V_110 ;
V_110 = F_3 ( V_111 ) ;
V_104 = V_107 -> V_109 == V_112 ;
if ( ! F_50 ( ( ( V_110 >> ( 4 * V_33 -> V_89 ) ) & 1 ) != V_104 ,
L_21 ,
V_104 , V_33 -> V_89 , V_110 ) ) {
V_104 = ! ! ( V_10 >> ( 4 * V_33 -> V_89 + 3 ) ) ;
F_50 ( V_104 != V_103 ,
L_22 ,
V_107 -> V_109 == V_112 ,
F_47 ( V_103 ) ,
V_33 -> V_89 ,
V_10 ) ;
}
}
}
static void F_55 ( struct V_3 * V_4 ,
enum V_89 V_89 , bool V_103 )
{
int V_8 ;
T_1 V_10 ;
bool V_104 ;
if ( F_56 ( V_4 -> V_2 ) ) {
V_8 = F_57 ( V_89 ) ;
V_10 = F_3 ( V_8 ) ;
V_104 = ! ! ( V_10 & V_113 ) ;
} else {
V_8 = F_58 ( V_89 ) ;
V_10 = F_3 ( V_8 ) ;
V_104 = ! ! ( V_10 & V_114 ) ;
}
F_50 ( V_104 != V_103 ,
L_23 ,
F_47 ( V_103 ) , F_47 ( V_104 ) ) ;
}
static void F_59 ( struct V_3 * V_4 ,
enum V_89 V_89 , bool V_103 )
{
int V_8 ;
T_1 V_10 ;
bool V_104 ;
if ( F_56 ( V_4 -> V_2 ) && V_89 > 0 ) {
F_7 ( L_24 ) ;
return;
} else {
V_8 = F_60 ( V_89 ) ;
V_10 = F_3 ( V_8 ) ;
V_104 = ! ! ( V_10 & V_115 ) ;
}
F_50 ( V_104 != V_103 ,
L_25 ,
F_47 ( V_103 ) , F_47 ( V_104 ) ) ;
}
static void F_61 ( struct V_3 * V_4 ,
enum V_89 V_89 )
{
int V_8 ;
T_1 V_10 ;
if ( V_4 -> V_116 -> V_93 == 5 )
return;
if ( F_56 ( V_4 -> V_2 ) )
return;
V_8 = F_58 ( V_89 ) ;
V_10 = F_3 ( V_8 ) ;
F_50 ( ! ( V_10 & V_117 ) , L_26 ) ;
}
static void F_62 ( struct V_3 * V_4 ,
enum V_89 V_89 )
{
int V_8 ;
T_1 V_10 ;
if ( F_56 ( V_4 -> V_2 ) && V_89 > 0 ) {
F_7 ( L_27 ) ;
return;
}
V_8 = F_60 ( V_89 ) ;
V_10 = F_3 ( V_8 ) ;
F_50 ( ! ( V_10 & V_118 ) , L_28 ) ;
}
static void F_63 ( struct V_3 * V_4 ,
enum V_89 V_89 )
{
int V_119 , V_88 ;
T_1 V_10 ;
enum V_89 V_120 = V_121 ;
bool V_122 = true ;
if ( F_20 ( V_4 -> V_2 ) ) {
V_119 = V_123 ;
V_88 = V_37 ;
} else {
V_119 = V_124 ;
V_88 = V_46 ;
}
V_10 = F_3 ( V_119 ) ;
if ( ! ( V_10 & V_125 ) ||
( ( V_10 & V_126 ) == V_126 ) )
V_122 = false ;
if ( F_3 ( V_88 ) & V_127 )
V_120 = V_128 ;
F_50 ( V_120 == V_89 && V_122 ,
L_29 ,
F_64 ( V_89 ) ) ;
}
void F_65 ( struct V_3 * V_4 ,
enum V_89 V_89 , bool V_103 )
{
int V_8 ;
T_1 V_10 ;
bool V_104 ;
if ( V_89 == V_121 && V_4 -> V_129 & V_130 )
V_103 = true ;
V_8 = F_42 ( V_89 ) ;
V_10 = F_3 ( V_8 ) ;
V_104 = ! ! ( V_10 & V_131 ) ;
F_50 ( V_104 != V_103 ,
L_30 ,
F_64 ( V_89 ) , F_47 ( V_103 ) , F_47 ( V_104 ) ) ;
}
static void F_66 ( struct V_3 * V_4 ,
enum V_132 V_132 , bool V_103 )
{
int V_8 ;
T_1 V_10 ;
bool V_104 ;
V_8 = F_67 ( V_132 ) ;
V_10 = F_3 ( V_8 ) ;
V_104 = ! ! ( V_10 & V_133 ) ;
F_50 ( V_104 != V_103 ,
L_31 ,
F_68 ( V_132 ) , F_47 ( V_103 ) , F_47 ( V_104 ) ) ;
}
static void F_69 ( struct V_3 * V_4 ,
enum V_89 V_89 )
{
int V_8 , V_134 ;
T_1 V_10 ;
int V_135 ;
if ( F_20 ( V_4 -> V_2 ) ) {
V_8 = F_67 ( V_89 ) ;
V_10 = F_3 ( V_8 ) ;
F_50 ( ( V_10 & V_133 ) ,
L_32 ,
F_68 ( V_89 ) ) ;
return;
}
for ( V_134 = 0 ; V_134 < 2 ; V_134 ++ ) {
V_8 = F_67 ( V_134 ) ;
V_10 = F_3 ( V_8 ) ;
V_135 = ( V_10 & V_136 ) >>
V_137 ;
F_50 ( ( V_10 & V_133 ) && V_89 == V_135 ,
L_33 ,
F_68 ( V_134 ) , F_64 ( V_89 ) ) ;
}
}
static void F_70 ( struct V_3 * V_4 )
{
T_1 V_10 ;
bool V_102 ;
if ( F_52 ( V_4 -> V_2 ) ) {
F_53 ( L_34 ) ;
return;
}
V_10 = F_3 ( V_138 ) ;
V_102 = ! ! ( V_10 & ( V_139 | V_140 |
V_141 ) ) ;
F_50 ( ! V_102 , L_35 ) ;
}
static void F_71 ( struct V_3 * V_4 ,
enum V_89 V_89 )
{
int V_8 ;
T_1 V_10 ;
bool V_102 ;
V_8 = F_72 ( V_89 ) ;
V_10 = F_3 ( V_8 ) ;
V_102 = ! ! ( V_10 & V_142 ) ;
F_50 ( V_102 ,
L_36 ,
F_64 ( V_89 ) ) ;
}
static bool F_73 ( struct V_3 * V_4 ,
enum V_89 V_89 , T_1 V_143 , T_1 V_10 )
{
if ( ( V_10 & V_144 ) == 0 )
return false ;
if ( F_54 ( V_4 -> V_2 ) ) {
T_1 V_145 = F_74 ( V_89 ) ;
T_1 V_146 = F_3 ( V_145 ) ;
if ( ( V_146 & V_147 ) != V_143 )
return false ;
} else {
if ( ( V_10 & V_148 ) != ( V_89 << 30 ) )
return false ;
}
return true ;
}
static bool F_75 ( struct V_3 * V_4 ,
enum V_89 V_89 , T_1 V_10 )
{
if ( ( V_10 & V_149 ) == 0 )
return false ;
if ( F_54 ( V_4 -> V_2 ) ) {
if ( ( V_10 & V_150 ) != F_76 ( V_89 ) )
return false ;
} else {
if ( ( V_10 & V_151 ) != F_77 ( V_89 ) )
return false ;
}
return true ;
}
static bool F_78 ( struct V_3 * V_4 ,
enum V_89 V_89 , T_1 V_10 )
{
if ( ( V_10 & V_152 ) == 0 )
return false ;
if ( F_54 ( V_4 -> V_2 ) ) {
if ( ( V_10 & V_150 ) != F_76 ( V_89 ) )
return false ;
} else {
if ( ( V_10 & V_153 ) != F_79 ( V_89 ) )
return false ;
}
return true ;
}
static bool F_80 ( struct V_3 * V_4 ,
enum V_89 V_89 , T_1 V_10 )
{
if ( ( V_10 & V_154 ) == 0 )
return false ;
if ( F_54 ( V_4 -> V_2 ) ) {
if ( ( V_10 & V_150 ) != F_76 ( V_89 ) )
return false ;
} else {
if ( ( V_10 & V_155 ) != F_81 ( V_89 ) )
return false ;
}
return true ;
}
static void F_82 ( struct V_3 * V_4 ,
enum V_89 V_89 , int V_8 , T_1 V_143 )
{
T_1 V_10 = F_3 ( V_8 ) ;
F_50 ( F_73 ( V_4 , V_89 , V_143 , V_10 ) ,
L_37 ,
V_8 , F_64 ( V_89 ) ) ;
}
static void F_83 ( struct V_3 * V_4 ,
enum V_89 V_89 , int V_8 )
{
T_1 V_10 = F_3 ( V_8 ) ;
F_50 ( F_75 ( V_4 , V_10 , V_89 ) ,
L_38 ,
V_8 , F_64 ( V_89 ) ) ;
}
static void F_84 ( struct V_3 * V_4 ,
enum V_89 V_89 )
{
int V_8 ;
T_1 V_10 ;
F_82 ( V_4 , V_89 , V_156 , V_157 ) ;
F_82 ( V_4 , V_89 , V_158 , V_159 ) ;
F_82 ( V_4 , V_89 , V_160 , V_161 ) ;
V_8 = V_162 ;
V_10 = F_3 ( V_8 ) ;
F_50 ( F_80 ( V_4 , V_10 , V_89 ) ,
L_39 ,
F_64 ( V_89 ) ) ;
V_8 = V_37 ;
V_10 = F_3 ( V_8 ) ;
F_50 ( F_78 ( V_4 , V_10 , V_89 ) ,
L_40 ,
F_64 ( V_89 ) ) ;
F_83 ( V_4 , V_89 , V_163 ) ;
F_83 ( V_4 , V_89 , V_164 ) ;
F_83 ( V_4 , V_89 , V_165 ) ;
}
static void F_85 ( struct V_3 * V_4 , enum V_89 V_89 )
{
int V_8 ;
T_1 V_10 ;
F_86 ( V_4 -> V_116 -> V_93 >= 5 ) ;
if ( F_87 ( V_4 -> V_2 ) && ! F_88 ( V_4 -> V_2 ) )
F_63 ( V_4 , V_89 ) ;
V_8 = F_49 ( V_89 ) ;
V_10 = F_3 ( V_8 ) ;
V_10 |= V_105 ;
F_8 ( V_8 , V_10 ) ;
F_11 ( V_8 ) ;
F_89 ( 150 ) ;
F_8 ( V_8 , V_10 ) ;
F_11 ( V_8 ) ;
F_89 ( 150 ) ;
F_8 ( V_8 , V_10 ) ;
F_11 ( V_8 ) ;
F_89 ( 150 ) ;
}
static void F_90 ( struct V_3 * V_4 , enum V_89 V_89 )
{
int V_8 ;
T_1 V_10 ;
if ( V_89 == V_121 && ( V_4 -> V_129 & V_130 ) )
return;
F_91 ( V_4 , V_89 ) ;
V_8 = F_49 ( V_89 ) ;
V_10 = F_3 ( V_8 ) ;
V_10 &= ~ V_105 ;
F_8 ( V_8 , V_10 ) ;
F_11 ( V_8 ) ;
}
static void
F_92 ( struct V_3 * V_4 , T_4 V_8 , T_1 V_166 )
{
unsigned long V_9 ;
F_5 ( & V_4 -> V_11 , V_9 ) ;
if ( F_35 ( ( F_3 ( V_167 ) & V_168 ) == 0 ,
100 ) ) {
F_7 ( L_41 ) ;
goto V_14;
}
F_8 ( V_169 ,
( V_8 << 16 ) ) ;
F_8 ( V_170 ,
V_166 ) ;
F_8 ( V_167 ,
V_171 |
V_172 ) ;
if ( F_35 ( ( F_3 ( V_167 ) & ( V_168 | V_173 ) ) == 0 ,
100 ) ) {
F_7 ( L_42 ) ;
goto V_14;
}
V_14:
F_9 ( & V_4 -> V_11 , V_9 ) ;
}
static T_1
F_93 ( struct V_3 * V_4 , T_4 V_8 )
{
unsigned long V_9 ;
T_1 V_166 ;
F_5 ( & V_4 -> V_11 , V_9 ) ;
if ( F_35 ( ( F_3 ( V_167 ) & V_168 ) == 0 ,
100 ) ) {
F_7 ( L_41 ) ;
goto V_14;
}
F_8 ( V_169 ,
( V_8 << 16 ) ) ;
F_8 ( V_167 ,
V_171 |
V_174 ) ;
if ( F_35 ( ( F_3 ( V_167 ) & ( V_168 | V_173 ) ) == 0 ,
100 ) ) {
F_7 ( L_43 ) ;
goto V_14;
}
V_166 = F_3 ( V_170 ) ;
V_14:
F_9 ( & V_4 -> V_11 , V_9 ) ;
return V_166 ;
}
static void F_94 ( struct V_108 * V_108 )
{
struct V_3 * V_4 = V_108 -> V_74 . V_2 -> V_5 ;
struct V_106 * V_107 ;
int V_8 ;
T_1 V_10 ;
F_86 ( V_4 -> V_116 -> V_93 < 5 ) ;
V_107 = V_108 -> V_175 ;
if ( V_107 == NULL )
return;
if ( F_95 ( V_107 -> V_176 == 0 ) )
return;
F_37 ( L_44 ,
V_107 -> V_109 , V_107 -> V_177 , V_107 -> V_178 ,
V_108 -> V_74 . V_74 . V_23 ) ;
F_70 ( V_4 ) ;
if ( V_107 -> V_177 ++ && V_107 -> V_178 ) {
F_96 ( V_4 , V_107 , NULL ) ;
return;
}
F_37 ( L_45 , V_107 -> V_109 ) ;
V_8 = V_107 -> V_109 ;
V_10 = F_3 ( V_8 ) ;
V_10 |= V_105 ;
F_8 ( V_8 , V_10 ) ;
F_11 ( V_8 ) ;
F_89 ( 200 ) ;
V_107 -> V_178 = true ;
}
static void F_97 ( struct V_108 * V_108 )
{
struct V_3 * V_4 = V_108 -> V_74 . V_2 -> V_5 ;
struct V_106 * V_107 = V_108 -> V_175 ;
int V_8 ;
T_1 V_10 ;
F_86 ( V_4 -> V_116 -> V_93 < 5 ) ;
if ( V_107 == NULL )
return;
if ( F_95 ( V_107 -> V_176 == 0 ) )
return;
F_37 ( L_46 ,
V_107 -> V_109 , V_107 -> V_177 , V_107 -> V_178 ,
V_108 -> V_74 . V_74 . V_23 ) ;
if ( F_95 ( V_107 -> V_177 == 0 ) ) {
F_98 ( V_4 , V_107 , NULL ) ;
return;
}
if ( -- V_107 -> V_177 ) {
F_96 ( V_4 , V_107 , NULL ) ;
return;
}
F_37 ( L_47 , V_107 -> V_109 ) ;
F_71 ( V_4 , V_108 -> V_89 ) ;
V_8 = V_107 -> V_109 ;
V_10 = F_3 ( V_8 ) ;
V_10 &= ~ V_105 ;
F_8 ( V_8 , V_10 ) ;
F_11 ( V_8 ) ;
F_89 ( 200 ) ;
V_107 -> V_178 = false ;
}
static void F_99 ( struct V_3 * V_4 ,
enum V_89 V_89 )
{
int V_8 ;
T_1 V_10 , V_179 ;
struct V_32 * V_33 = V_4 -> V_180 [ V_89 ] ;
F_86 ( V_4 -> V_116 -> V_93 < 5 ) ;
F_96 ( V_4 ,
F_100 ( V_33 ) -> V_175 ,
F_100 ( V_33 ) ) ;
F_101 ( V_4 , V_89 ) ;
F_102 ( V_4 , V_89 ) ;
if ( F_56 ( V_4 -> V_2 ) && V_89 > 0 ) {
F_7 ( L_48 ) ;
return;
}
V_8 = F_72 ( V_89 ) ;
V_10 = F_3 ( V_8 ) ;
V_179 = F_3 ( F_42 ( V_89 ) ) ;
if ( F_103 ( V_4 -> V_2 ) ) {
V_10 &= ~ V_181 ;
V_10 |= V_179 & V_181 ;
}
V_10 &= ~ V_182 ;
if ( ( V_179 & V_183 ) == V_184 )
if ( F_103 ( V_4 -> V_2 ) &&
F_17 ( V_33 , V_52 ) )
V_10 |= V_185 ;
else
V_10 |= V_186 ;
else
V_10 |= V_187 ;
F_8 ( V_8 , V_10 | V_142 ) ;
if ( F_35 ( F_3 ( V_8 ) & V_188 , 100 ) )
F_7 ( L_49 , V_89 ) ;
}
static void F_104 ( struct V_3 * V_4 ,
enum V_89 V_89 )
{
int V_8 ;
T_1 V_10 ;
F_105 ( V_4 , V_89 ) ;
F_106 ( V_4 , V_89 ) ;
F_84 ( V_4 , V_89 ) ;
V_8 = F_72 ( V_89 ) ;
V_10 = F_3 ( V_8 ) ;
V_10 &= ~ V_142 ;
F_8 ( V_8 , V_10 ) ;
if ( F_35 ( ( F_3 ( V_8 ) & V_188 ) == 0 , 50 ) )
F_7 ( L_50 , V_89 ) ;
}
static void F_107 ( struct V_3 * V_4 , enum V_89 V_89 ,
bool V_189 )
{
int V_8 ;
T_1 V_10 ;
if ( ! F_20 ( V_4 -> V_2 ) )
F_108 ( V_4 , V_89 ) ;
else {
if ( V_189 ) {
F_62 ( V_4 , V_89 ) ;
F_61 ( V_4 , V_89 ) ;
}
}
V_8 = F_42 ( V_89 ) ;
V_10 = F_3 ( V_8 ) ;
if ( V_10 & V_131 )
return;
F_8 ( V_8 , V_10 | V_131 ) ;
F_38 ( V_4 -> V_2 , V_89 ) ;
}
static void F_109 ( struct V_3 * V_4 ,
enum V_89 V_89 )
{
int V_8 ;
T_1 V_10 ;
F_69 ( V_4 , V_89 ) ;
if ( V_89 == V_121 && ( V_4 -> V_129 & V_130 ) )
return;
V_8 = F_42 ( V_89 ) ;
V_10 = F_3 ( V_8 ) ;
if ( ( V_10 & V_131 ) == 0 )
return;
F_8 ( V_8 , V_10 & ~ V_131 ) ;
F_41 ( V_4 -> V_2 , V_89 ) ;
}
void F_110 ( struct V_3 * V_4 ,
enum V_132 V_132 )
{
F_8 ( F_111 ( V_132 ) , F_3 ( F_111 ( V_132 ) ) ) ;
F_8 ( F_112 ( V_132 ) , F_3 ( F_112 ( V_132 ) ) ) ;
}
static void F_113 ( struct V_3 * V_4 ,
enum V_132 V_132 , enum V_89 V_89 )
{
int V_8 ;
T_1 V_10 ;
F_114 ( V_4 , V_89 ) ;
V_8 = F_67 ( V_132 ) ;
V_10 = F_3 ( V_8 ) ;
if ( V_10 & V_133 )
return;
F_8 ( V_8 , V_10 | V_133 ) ;
F_110 ( V_4 , V_132 ) ;
F_38 ( V_4 -> V_2 , V_89 ) ;
}
static void F_115 ( struct V_3 * V_4 ,
enum V_132 V_132 , enum V_89 V_89 )
{
int V_8 ;
T_1 V_10 ;
V_8 = F_67 ( V_132 ) ;
V_10 = F_3 ( V_8 ) ;
if ( ( V_10 & V_133 ) == 0 )
return;
F_8 ( V_8 , V_10 & ~ V_133 ) ;
F_110 ( V_4 , V_132 ) ;
F_38 ( V_4 -> V_2 , V_89 ) ;
}
static void F_116 ( struct V_3 * V_4 ,
enum V_89 V_89 , int V_8 , T_1 V_143 )
{
T_1 V_10 = F_3 ( V_8 ) ;
if ( F_73 ( V_4 , V_89 , V_143 , V_10 ) ) {
F_37 ( L_51 , V_8 , V_89 ) ;
F_8 ( V_8 , V_10 & ~ V_144 ) ;
}
}
static void F_117 ( struct V_3 * V_4 ,
enum V_89 V_89 , int V_8 )
{
T_1 V_10 = F_3 ( V_8 ) ;
if ( F_75 ( V_4 , V_10 , V_89 ) ) {
F_37 ( L_52 ,
V_8 , V_89 ) ;
F_8 ( V_8 , V_10 & ~ V_149 ) ;
}
}
static void F_118 ( struct V_3 * V_4 ,
enum V_89 V_89 )
{
T_1 V_8 , V_10 ;
V_10 = F_3 ( V_123 ) ;
F_8 ( V_123 , V_10 | V_126 ) ;
F_116 ( V_4 , V_89 , V_156 , V_157 ) ;
F_116 ( V_4 , V_89 , V_158 , V_159 ) ;
F_116 ( V_4 , V_89 , V_160 , V_161 ) ;
V_8 = V_162 ;
V_10 = F_3 ( V_8 ) ;
if ( F_80 ( V_4 , V_10 , V_89 ) )
F_8 ( V_8 , V_10 & ~ V_154 ) ;
V_8 = V_37 ;
V_10 = F_3 ( V_8 ) ;
if ( F_78 ( V_4 , V_10 , V_89 ) ) {
F_37 ( L_53 , V_89 , V_10 ) ;
F_8 ( V_8 , V_10 & ~ V_152 ) ;
F_11 ( V_8 ) ;
F_89 ( 100 ) ;
}
F_117 ( V_4 , V_89 , V_163 ) ;
F_117 ( V_4 , V_89 , V_164 ) ;
F_117 ( V_4 , V_89 , V_165 ) ;
}
int
F_119 ( struct V_1 * V_2 ,
struct V_190 * V_191 ,
struct V_192 * V_193 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_194 ;
int V_195 ;
switch ( V_191 -> V_196 ) {
case V_197 :
if ( F_120 ( V_2 ) || F_121 ( V_2 ) )
V_194 = 128 * 1024 ;
else if ( F_40 ( V_2 ) -> V_93 >= 4 )
V_194 = 4 * 1024 ;
else
V_194 = 64 * 1024 ;
break;
case V_198 :
V_194 = 0 ;
break;
case V_199 :
F_7 ( L_54 ) ;
return - V_200 ;
default:
F_122 () ;
}
V_4 -> V_201 . V_202 = false ;
V_195 = F_123 ( V_191 , V_194 , V_193 ) ;
if ( V_195 )
goto V_203;
V_195 = F_124 ( V_191 ) ;
if ( V_195 )
goto V_204;
F_125 ( V_191 ) ;
V_4 -> V_201 . V_202 = true ;
return 0 ;
V_204:
F_126 ( V_191 ) ;
V_203:
V_4 -> V_201 . V_202 = true ;
return V_195 ;
}
void F_127 ( struct V_190 * V_191 )
{
F_128 ( V_191 ) ;
F_126 ( V_191 ) ;
}
static int F_129 ( struct V_32 * V_33 , struct V_205 * V_206 ,
int V_207 , int V_208 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
struct V_209 * V_210 ;
struct V_190 * V_191 ;
int V_132 = V_108 -> V_132 ;
unsigned long V_211 , V_212 ;
T_1 V_213 ;
T_1 V_8 ;
switch ( V_132 ) {
case 0 :
case 1 :
break;
default:
F_7 ( L_55 , V_132 ) ;
return - V_200 ;
}
V_210 = F_130 ( V_206 ) ;
V_191 = V_210 -> V_191 ;
V_8 = F_67 ( V_132 ) ;
V_213 = F_3 ( V_8 ) ;
V_213 &= ~ V_214 ;
switch ( V_206 -> V_215 ) {
case 8 :
V_213 |= V_216 ;
break;
case 16 :
if ( V_206 -> V_217 == 15 )
V_213 |= V_218 ;
else
V_213 |= V_219 ;
break;
case 24 :
case 32 :
V_213 |= V_220 ;
break;
default:
F_7 ( L_56 , V_206 -> V_215 ) ;
return - V_200 ;
}
if ( F_40 ( V_2 ) -> V_93 >= 4 ) {
if ( V_191 -> V_196 != V_197 )
V_213 |= V_221 ;
else
V_213 &= ~ V_221 ;
}
F_8 ( V_8 , V_213 ) ;
V_211 = V_191 -> V_222 ;
V_212 = V_208 * V_206 -> V_223 [ 0 ] + V_207 * ( V_206 -> V_215 / 8 ) ;
F_37 ( L_57 ,
V_211 , V_212 , V_207 , V_208 , V_206 -> V_223 [ 0 ] ) ;
F_8 ( F_131 ( V_132 ) , V_206 -> V_223 [ 0 ] ) ;
if ( F_40 ( V_2 ) -> V_93 >= 4 ) {
F_132 ( F_112 ( V_132 ) , V_211 ) ;
F_8 ( F_133 ( V_132 ) , ( V_208 << 16 ) | V_207 ) ;
F_8 ( F_111 ( V_132 ) , V_212 ) ;
} else
F_8 ( F_111 ( V_132 ) , V_211 + V_212 ) ;
F_11 ( V_8 ) ;
return 0 ;
}
static int F_134 ( struct V_32 * V_33 ,
struct V_205 * V_206 , int V_207 , int V_208 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
struct V_209 * V_210 ;
struct V_190 * V_191 ;
int V_132 = V_108 -> V_132 ;
unsigned long V_211 , V_212 ;
T_1 V_213 ;
T_1 V_8 ;
switch ( V_132 ) {
case 0 :
case 1 :
case 2 :
break;
default:
F_7 ( L_55 , V_132 ) ;
return - V_200 ;
}
V_210 = F_130 ( V_206 ) ;
V_191 = V_210 -> V_191 ;
V_8 = F_67 ( V_132 ) ;
V_213 = F_3 ( V_8 ) ;
V_213 &= ~ V_214 ;
switch ( V_206 -> V_215 ) {
case 8 :
V_213 |= V_216 ;
break;
case 16 :
if ( V_206 -> V_217 != 16 )
return - V_200 ;
V_213 |= V_219 ;
break;
case 24 :
case 32 :
if ( V_206 -> V_217 == 24 )
V_213 |= V_220 ;
else if ( V_206 -> V_217 == 30 )
V_213 |= V_224 ;
else
return - V_200 ;
break;
default:
F_7 ( L_56 , V_206 -> V_215 ) ;
return - V_200 ;
}
if ( V_191 -> V_196 != V_197 )
V_213 |= V_221 ;
else
V_213 &= ~ V_221 ;
V_213 |= V_225 ;
F_8 ( V_8 , V_213 ) ;
V_211 = V_191 -> V_222 ;
V_212 = V_208 * V_206 -> V_223 [ 0 ] + V_207 * ( V_206 -> V_215 / 8 ) ;
F_37 ( L_57 ,
V_211 , V_212 , V_207 , V_208 , V_206 -> V_223 [ 0 ] ) ;
F_8 ( F_131 ( V_132 ) , V_206 -> V_223 [ 0 ] ) ;
F_132 ( F_112 ( V_132 ) , V_211 ) ;
F_8 ( F_133 ( V_132 ) , ( V_208 << 16 ) | V_207 ) ;
F_8 ( F_111 ( V_132 ) , V_212 ) ;
F_11 ( V_8 ) ;
return 0 ;
}
static int
F_135 ( struct V_32 * V_33 , struct V_205 * V_206 ,
int V_207 , int V_208 , enum V_226 V_103 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_227 . V_228 )
V_4 -> V_227 . V_228 ( V_2 ) ;
F_136 ( V_33 ) ;
return V_4 -> V_227 . V_229 ( V_33 , V_206 , V_207 , V_208 ) ;
}
static int
F_137 ( struct V_205 * V_230 )
{
struct V_190 * V_191 = F_130 ( V_230 ) -> V_191 ;
struct V_3 * V_4 = V_191 -> V_74 . V_2 -> V_5 ;
bool V_231 = V_4 -> V_201 . V_202 ;
int V_195 ;
F_138 ( V_4 -> V_232 ,
F_139 ( & V_4 -> V_201 . V_233 ) ||
F_139 ( & V_191 -> V_234 ) == 0 ) ;
V_4 -> V_201 . V_202 = false ;
V_195 = F_140 ( V_191 ) ;
V_4 -> V_201 . V_202 = V_231 ;
return V_195 ;
}
static int
F_141 ( struct V_32 * V_33 , int V_207 , int V_208 ,
struct V_205 * V_230 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_235 * V_236 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_195 ;
if ( ! V_33 -> V_206 ) {
F_7 ( L_58 ) ;
return 0 ;
}
if( V_108 -> V_132 > V_4 -> V_237 ) {
F_7 ( L_59 ,
V_108 -> V_132 ,
V_4 -> V_237 ) ;
return - V_200 ;
}
F_142 ( & V_2 -> V_238 ) ;
V_195 = F_119 ( V_2 ,
F_130 ( V_33 -> V_206 ) -> V_191 ,
NULL ) ;
if ( V_195 != 0 ) {
F_143 ( & V_2 -> V_238 ) ;
F_7 ( L_60 ) ;
return V_195 ;
}
if ( V_230 )
F_137 ( V_230 ) ;
V_195 = V_4 -> V_227 . V_229 ( V_33 , V_33 -> V_206 , V_207 , V_208 ) ;
if ( V_195 ) {
F_127 ( F_130 ( V_33 -> V_206 ) -> V_191 ) ;
F_143 ( & V_2 -> V_238 ) ;
F_7 ( L_61 ) ;
return V_195 ;
}
if ( V_230 ) {
F_38 ( V_2 , V_108 -> V_89 ) ;
F_127 ( F_130 ( V_230 ) -> V_191 ) ;
}
F_144 ( V_2 ) ;
F_143 ( & V_2 -> V_238 ) ;
if ( ! V_2 -> V_239 -> V_240 )
return 0 ;
V_236 = V_2 -> V_239 -> V_240 -> V_241 ;
if ( ! V_236 -> V_242 )
return 0 ;
if ( V_108 -> V_89 ) {
V_236 -> V_242 -> V_243 = V_207 ;
V_236 -> V_242 -> V_244 = V_208 ;
} else {
V_236 -> V_242 -> V_245 = V_207 ;
V_236 -> V_242 -> V_246 = V_208 ;
}
return 0 ;
}
static void F_145 ( struct V_32 * V_33 , int clock )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_247 ;
F_37 ( L_62 , clock ) ;
V_247 = F_3 ( V_248 ) ;
V_247 &= ~ V_249 ;
if ( clock < 200000 ) {
T_1 V_250 ;
V_247 |= V_251 ;
V_250 = F_3 ( 0x4600c ) ;
V_250 &= 0xffff0000 ;
F_8 ( 0x4600c , V_250 | 0x8124 ) ;
V_250 = F_3 ( 0x46010 ) ;
F_8 ( 0x46010 , V_250 | 1 ) ;
V_250 = F_3 ( 0x46034 ) ;
F_8 ( 0x46034 , V_250 | ( 1 << 24 ) ) ;
} else {
V_247 |= V_252 ;
}
F_8 ( V_248 , V_247 ) ;
F_11 ( V_248 ) ;
F_89 ( 500 ) ;
}
static void F_146 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
T_1 V_8 , V_250 ;
V_8 = F_58 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
if ( F_147 ( V_2 ) ) {
V_250 &= ~ V_253 ;
V_250 |= V_253 | V_254 ;
} else {
V_250 &= ~ V_255 ;
V_250 |= V_255 | V_254 ;
}
F_8 ( V_8 , V_250 ) ;
V_8 = F_60 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
if ( F_54 ( V_2 ) ) {
V_250 &= ~ V_256 ;
V_250 |= V_257 ;
} else {
V_250 &= ~ V_255 ;
V_250 |= V_255 ;
}
F_8 ( V_8 , V_250 | V_258 ) ;
F_11 ( V_8 ) ;
F_89 ( 1000 ) ;
if ( F_147 ( V_2 ) )
F_8 ( V_8 , F_3 ( V_8 ) | V_259 |
V_260 ) ;
}
static void F_148 ( struct V_1 * V_2 , int V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_9 = F_3 ( V_261 ) ;
V_9 |= F_149 ( V_89 ) ;
F_8 ( V_261 , V_9 ) ;
V_9 |= F_150 ( V_89 ) ;
F_8 ( V_261 , V_9 ) ;
F_11 ( V_261 ) ;
}
static void F_151 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
int V_132 = V_108 -> V_132 ;
T_1 V_8 , V_250 , V_262 ;
F_114 ( V_4 , V_89 ) ;
F_152 ( V_4 , V_132 ) ;
V_8 = F_153 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ V_263 ;
V_250 &= ~ V_264 ;
F_8 ( V_8 , V_250 ) ;
F_3 ( V_8 ) ;
F_89 ( 150 ) ;
V_8 = F_58 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ ( 7 << 19 ) ;
V_250 |= ( V_108 -> V_265 - 1 ) << 19 ;
V_250 &= ~ V_255 ;
V_250 |= V_266 ;
F_8 ( V_8 , V_250 | V_114 ) ;
V_8 = F_60 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ V_255 ;
V_250 |= V_266 ;
F_8 ( V_8 , V_250 | V_115 ) ;
F_11 ( V_8 ) ;
F_89 ( 150 ) ;
if ( F_103 ( V_2 ) ) {
F_8 ( F_154 ( V_89 ) , V_267 ) ;
F_8 ( F_154 ( V_89 ) , V_267 |
V_268 ) ;
}
V_8 = F_155 ( V_89 ) ;
for ( V_262 = 0 ; V_262 < 5 ; V_262 ++ ) {
V_250 = F_3 ( V_8 ) ;
F_37 ( L_63 , V_250 ) ;
if ( ( V_250 & V_264 ) ) {
F_37 ( L_64 ) ;
F_8 ( V_8 , V_250 | V_264 ) ;
break;
}
}
if ( V_262 == 5 )
F_7 ( L_65 ) ;
V_8 = F_58 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ V_255 ;
V_250 |= V_269 ;
F_8 ( V_8 , V_250 ) ;
V_8 = F_60 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ V_255 ;
V_250 |= V_269 ;
F_8 ( V_8 , V_250 ) ;
F_11 ( V_8 ) ;
F_89 ( 150 ) ;
V_8 = F_155 ( V_89 ) ;
for ( V_262 = 0 ; V_262 < 5 ; V_262 ++ ) {
V_250 = F_3 ( V_8 ) ;
F_37 ( L_63 , V_250 ) ;
if ( V_250 & V_263 ) {
F_8 ( V_8 , V_250 | V_263 ) ;
F_37 ( L_66 ) ;
break;
}
}
if ( V_262 == 5 )
F_7 ( L_67 ) ;
F_37 ( L_68 ) ;
}
static void F_156 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
T_1 V_8 , V_250 , V_134 , V_270 ;
V_8 = F_153 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ V_263 ;
V_250 &= ~ V_264 ;
F_8 ( V_8 , V_250 ) ;
F_11 ( V_8 ) ;
F_89 ( 150 ) ;
V_8 = F_58 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ ( 7 << 19 ) ;
V_250 |= ( V_108 -> V_265 - 1 ) << 19 ;
V_250 &= ~ V_255 ;
V_250 |= V_266 ;
V_250 &= ~ V_271 ;
V_250 |= V_272 ;
F_8 ( V_8 , V_250 | V_114 ) ;
V_8 = F_60 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
if ( F_54 ( V_2 ) ) {
V_250 &= ~ V_256 ;
V_250 |= V_273 ;
} else {
V_250 &= ~ V_255 ;
V_250 |= V_266 ;
}
F_8 ( V_8 , V_250 | V_115 ) ;
F_11 ( V_8 ) ;
F_89 ( 150 ) ;
if ( F_54 ( V_2 ) )
F_148 ( V_2 , V_89 ) ;
for ( V_134 = 0 ; V_134 < 4 ; V_134 ++ ) {
V_8 = F_58 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ V_271 ;
V_250 |= V_274 [ V_134 ] ;
F_8 ( V_8 , V_250 ) ;
F_11 ( V_8 ) ;
F_89 ( 500 ) ;
for ( V_270 = 0 ; V_270 < 5 ; V_270 ++ ) {
V_8 = F_155 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
F_37 ( L_63 , V_250 ) ;
if ( V_250 & V_264 ) {
F_8 ( V_8 , V_250 | V_264 ) ;
F_37 ( L_64 ) ;
break;
}
F_89 ( 50 ) ;
}
if ( V_270 < 5 )
break;
}
if ( V_134 == 4 )
F_7 ( L_65 ) ;
V_8 = F_58 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ V_255 ;
V_250 |= V_269 ;
if ( F_157 ( V_2 ) ) {
V_250 &= ~ V_271 ;
V_250 |= V_272 ;
}
F_8 ( V_8 , V_250 ) ;
V_8 = F_60 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
if ( F_54 ( V_2 ) ) {
V_250 &= ~ V_256 ;
V_250 |= V_275 ;
} else {
V_250 &= ~ V_255 ;
V_250 |= V_269 ;
}
F_8 ( V_8 , V_250 ) ;
F_11 ( V_8 ) ;
F_89 ( 150 ) ;
for ( V_134 = 0 ; V_134 < 4 ; V_134 ++ ) {
V_8 = F_58 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ V_271 ;
V_250 |= V_274 [ V_134 ] ;
F_8 ( V_8 , V_250 ) ;
F_11 ( V_8 ) ;
F_89 ( 500 ) ;
for ( V_270 = 0 ; V_270 < 5 ; V_270 ++ ) {
V_8 = F_155 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
F_37 ( L_63 , V_250 ) ;
if ( V_250 & V_263 ) {
F_8 ( V_8 , V_250 | V_263 ) ;
F_37 ( L_66 ) ;
break;
}
F_89 ( 50 ) ;
}
if ( V_270 < 5 )
break;
}
if ( V_134 == 4 )
F_7 ( L_67 ) ;
F_37 ( L_69 ) ;
}
static void F_158 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
T_1 V_8 , V_250 , V_134 ;
V_8 = F_153 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ V_263 ;
V_250 &= ~ V_264 ;
F_8 ( V_8 , V_250 ) ;
F_11 ( V_8 ) ;
F_89 ( 150 ) ;
V_8 = F_58 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ ( 7 << 19 ) ;
V_250 |= ( V_108 -> V_265 - 1 ) << 19 ;
V_250 &= ~ ( V_276 | V_253 ) ;
V_250 |= V_277 ;
V_250 &= ~ V_271 ;
V_250 |= V_272 ;
V_250 |= V_278 ;
F_8 ( V_8 , V_250 | V_114 ) ;
V_8 = F_60 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ V_276 ;
V_250 &= ~ V_256 ;
V_250 |= V_273 ;
V_250 |= V_278 ;
F_8 ( V_8 , V_250 | V_115 ) ;
F_11 ( V_8 ) ;
F_89 ( 150 ) ;
if ( F_54 ( V_2 ) )
F_148 ( V_2 , V_89 ) ;
for ( V_134 = 0 ; V_134 < 4 ; V_134 ++ ) {
V_8 = F_58 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ V_271 ;
V_250 |= V_274 [ V_134 ] ;
F_8 ( V_8 , V_250 ) ;
F_11 ( V_8 ) ;
F_89 ( 500 ) ;
V_8 = F_155 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
F_37 ( L_63 , V_250 ) ;
if ( V_250 & V_264 ||
( F_3 ( V_8 ) & V_264 ) ) {
F_8 ( V_8 , V_250 | V_264 ) ;
F_37 ( L_64 ) ;
break;
}
}
if ( V_134 == 4 )
F_7 ( L_65 ) ;
V_8 = F_58 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ V_253 ;
V_250 |= V_279 ;
V_250 &= ~ V_271 ;
V_250 |= V_272 ;
F_8 ( V_8 , V_250 ) ;
V_8 = F_60 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ V_256 ;
V_250 |= V_275 ;
F_8 ( V_8 , V_250 ) ;
F_11 ( V_8 ) ;
F_89 ( 150 ) ;
for ( V_134 = 0 ; V_134 < 4 ; V_134 ++ ) {
V_8 = F_58 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ V_271 ;
V_250 |= V_274 [ V_134 ] ;
F_8 ( V_8 , V_250 ) ;
F_11 ( V_8 ) ;
F_89 ( 500 ) ;
V_8 = F_155 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
F_37 ( L_63 , V_250 ) ;
if ( V_250 & V_263 ) {
F_8 ( V_8 , V_250 | V_263 ) ;
F_37 ( L_66 ) ;
break;
}
}
if ( V_134 == 4 )
F_7 ( L_67 ) ;
F_37 ( L_69 ) ;
}
static void F_159 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
T_1 V_8 , V_250 ;
F_8 ( F_160 ( V_89 ) ,
F_3 ( F_161 ( V_89 ) ) & V_280 ) ;
V_8 = F_60 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ ( ( 0x7 << 19 ) | ( 0x7 << 16 ) ) ;
V_250 |= ( V_108 -> V_265 - 1 ) << 19 ;
V_250 |= ( F_3 ( F_42 ( V_89 ) ) & V_181 ) << 11 ;
F_8 ( V_8 , V_250 | V_118 ) ;
F_11 ( V_8 ) ;
F_89 ( 200 ) ;
V_250 = F_3 ( V_8 ) ;
F_8 ( V_8 , V_250 | V_281 ) ;
F_11 ( V_8 ) ;
F_89 ( 200 ) ;
if ( ! F_56 ( V_2 ) ) {
V_8 = F_58 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
if ( ( V_250 & V_117 ) == 0 ) {
F_8 ( V_8 , V_250 | V_117 ) ;
F_11 ( V_8 ) ;
F_89 ( 100 ) ;
}
}
}
static void F_162 ( struct V_1 * V_2 , int V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_9 = F_3 ( V_261 ) ;
V_9 &= ~ ( F_150 ( V_89 ) ) ;
F_8 ( V_261 , V_9 ) ;
V_9 &= ~ ( F_149 ( V_89 ) ) ;
F_8 ( V_261 , V_9 ) ;
F_11 ( V_261 ) ;
}
static void F_163 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
T_1 V_8 , V_250 ;
V_8 = F_58 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
F_8 ( V_8 , V_250 & ~ V_114 ) ;
F_11 ( V_8 ) ;
V_8 = F_60 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ ( 0x7 << 16 ) ;
V_250 |= ( F_3 ( F_42 ( V_89 ) ) & V_181 ) << 11 ;
F_8 ( V_8 , V_250 & ~ V_115 ) ;
F_11 ( V_8 ) ;
F_89 ( 100 ) ;
if ( F_103 ( V_2 ) ) {
F_8 ( F_154 ( V_89 ) , V_267 ) ;
F_8 ( F_154 ( V_89 ) ,
F_3 ( F_154 ( V_89 ) &
~ V_268 ) ) ;
} else if ( F_54 ( V_2 ) ) {
F_162 ( V_2 , V_89 ) ;
}
V_8 = F_58 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ V_255 ;
V_250 |= V_266 ;
F_8 ( V_8 , V_250 ) ;
V_8 = F_60 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
if ( F_54 ( V_2 ) ) {
V_250 &= ~ V_256 ;
V_250 |= V_273 ;
} else {
V_250 &= ~ V_255 ;
V_250 |= V_266 ;
}
V_250 &= ~ ( 0x07 << 16 ) ;
V_250 |= ( F_3 ( F_42 ( V_89 ) ) & V_181 ) << 11 ;
F_8 ( V_8 , V_250 ) ;
F_11 ( V_8 ) ;
F_89 ( 100 ) ;
}
static void F_164 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
if ( V_33 -> V_206 == NULL )
return;
F_142 ( & V_2 -> V_238 ) ;
F_137 ( V_33 -> V_206 ) ;
F_143 ( & V_2 -> V_238 ) ;
}
static bool F_165 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_70 * V_71 = & V_2 -> V_71 ;
struct V_72 * V_73 ;
F_26 (encoder, &mode_config->encoder_list, base.head) {
if ( V_73 -> V_74 . V_33 != V_33 )
continue;
if ( F_56 ( V_2 ) ) {
F_95 ( ! F_52 ( V_2 ) ) ;
if ( V_73 -> type == V_282 ) {
F_37 ( L_70 ) ;
return true ;
} else {
F_37 ( L_71 ,
V_73 -> type ) ;
return false ;
}
}
switch ( V_73 -> type ) {
case V_283 :
if ( ! F_166 ( & V_73 -> V_74 ) )
return false ;
continue;
}
}
return true ;
}
static void F_167 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_284 , V_285 , V_286 , V_287 = 0 ;
T_1 V_250 ;
F_8 ( V_288 , V_289 ) ;
F_92 ( V_4 , V_290 ,
F_93 ( V_4 , V_290 ) |
V_291 ) ;
if ( V_33 -> V_292 . clock == 20000 ) {
V_286 = 1 ;
V_284 = 0x41 ;
V_285 = 0x20 ;
} else {
T_1 V_293 = 172800 * 1000 ;
T_1 V_294 = 64 ;
T_1 V_295 , V_296 , V_297 ;
V_295 = ( V_293 / V_33 -> V_292 . clock ) ;
V_296 = V_295 / V_294 ;
V_297 = V_295 % V_294 ;
V_286 = 0 ;
V_284 = V_296 - 2 ;
V_285 = V_297 ;
}
F_95 ( F_168 ( V_284 ) &
~ V_298 ) ;
F_95 ( F_169 ( V_287 ) &
~ V_299 ) ;
F_37 ( L_72 ,
V_33 -> V_292 . clock ,
V_286 ,
V_284 ,
V_287 ,
V_285 ) ;
V_250 = F_93 ( V_4 , V_300 ) ;
V_250 &= ~ V_298 ;
V_250 |= F_168 ( V_284 ) ;
V_250 &= ~ V_299 ;
V_250 |= F_170 ( V_285 ) ;
V_250 |= F_169 ( V_287 ) ;
V_250 |= V_301 ;
F_92 ( V_4 ,
V_300 ,
V_250 ) ;
V_250 = F_93 ( V_4 , V_302 ) ;
V_250 &= ~ F_171 ( 1 ) ;
V_250 |= F_171 ( V_286 ) ;
F_92 ( V_4 ,
V_302 ,
V_250 ) ;
V_250 = F_93 ( V_4 , V_290 ) ;
V_250 &= ~ V_291 ;
F_92 ( V_4 ,
V_290 ,
V_250 ) ;
F_89 ( 24 ) ;
F_8 ( V_288 , V_303 ) ;
}
static void F_172 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
T_1 V_8 , V_250 ;
F_71 ( V_4 , V_89 ) ;
V_4 -> V_227 . V_304 ( V_33 ) ;
F_94 ( V_108 ) ;
if ( F_52 ( V_2 ) ) {
F_37 ( L_73 ) ;
F_167 ( V_33 ) ;
} else if ( F_54 ( V_2 ) ) {
T_1 V_305 ;
V_250 = F_3 ( V_111 ) ;
switch ( V_89 ) {
default:
case 0 :
V_250 |= V_306 ;
V_305 = V_307 ;
break;
case 1 :
V_250 |= V_308 ;
V_305 = V_309 ;
break;
case 2 :
V_250 |= V_310 ;
V_305 = V_311 ;
break;
}
if ( V_108 -> V_175 -> V_109 == V_112 )
V_250 |= V_305 ;
else
V_250 &= ~ V_305 ;
F_8 ( V_111 , V_250 ) ;
}
F_63 ( V_4 , V_89 ) ;
F_8 ( F_173 ( V_89 ) , F_3 ( F_174 ( V_89 ) ) ) ;
F_8 ( F_175 ( V_89 ) , F_3 ( F_176 ( V_89 ) ) ) ;
F_8 ( F_177 ( V_89 ) , F_3 ( F_178 ( V_89 ) ) ) ;
F_8 ( F_179 ( V_89 ) , F_3 ( F_180 ( V_89 ) ) ) ;
F_8 ( F_181 ( V_89 ) , F_3 ( F_182 ( V_89 ) ) ) ;
F_8 ( F_183 ( V_89 ) , F_3 ( F_184 ( V_89 ) ) ) ;
F_8 ( F_185 ( V_89 ) , F_3 ( F_186 ( V_89 ) ) ) ;
if ( ! F_56 ( V_2 ) )
F_146 ( V_33 ) ;
if ( F_54 ( V_2 ) &&
( F_17 ( V_33 , V_42 ) ||
F_17 ( V_33 , V_283 ) ) ) {
T_1 V_312 = ( F_3 ( F_42 ( V_89 ) ) & V_181 ) >> 5 ;
V_8 = F_74 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ ( V_147 |
V_313 |
V_314 ) ;
V_250 |= ( V_315 |
V_316 ) ;
V_250 |= V_312 << 9 ;
if ( V_33 -> V_292 . V_9 & V_317 )
V_250 |= V_318 ;
if ( V_33 -> V_292 . V_9 & V_319 )
V_250 |= V_320 ;
switch ( F_187 ( V_33 ) ) {
case V_156 :
V_250 |= V_157 ;
break;
case V_158 :
V_250 |= V_159 ;
break;
case V_160 :
V_250 |= V_161 ;
break;
default:
F_37 ( L_74 ) ;
V_250 |= V_157 ;
break;
}
F_8 ( V_8 , V_250 ) ;
}
F_99 ( V_4 , V_89 ) ;
}
static void F_188 ( struct V_108 * V_108 )
{
struct V_106 * V_107 = V_108 -> V_175 ;
if ( V_107 == NULL )
return;
if ( V_107 -> V_176 == 0 ) {
F_50 ( 1 , L_75 ) ;
return;
}
-- V_107 -> V_176 ;
V_108 -> V_175 = NULL ;
}
static struct V_106 * F_189 ( struct V_108 * V_108 , T_1 V_321 , T_1 V_322 )
{
struct V_3 * V_4 = V_108 -> V_74 . V_2 -> V_5 ;
struct V_106 * V_107 ;
int V_134 ;
V_107 = V_108 -> V_175 ;
if ( V_107 ) {
F_37 ( L_76 ,
V_108 -> V_74 . V_74 . V_23 , V_107 -> V_109 ) ;
goto V_323;
}
if ( F_103 ( V_4 -> V_2 ) ) {
V_134 = V_108 -> V_89 ;
V_107 = & V_4 -> V_324 [ V_134 ] ;
F_37 ( L_77 ,
V_108 -> V_74 . V_74 . V_23 , V_107 -> V_109 ) ;
goto V_86;
}
for ( V_134 = 0 ; V_134 < V_4 -> V_325 ; V_134 ++ ) {
V_107 = & V_4 -> V_324 [ V_134 ] ;
if ( V_107 -> V_176 == 0 )
continue;
if ( V_321 == ( F_3 ( V_107 -> V_109 ) & 0x7fffffff ) &&
V_322 == F_3 ( V_107 -> V_326 ) ) {
F_37 ( L_78 ,
V_108 -> V_74 . V_74 . V_23 ,
V_107 -> V_109 , V_107 -> V_176 , V_107 -> V_177 ) ;
goto V_86;
}
}
for ( V_134 = 0 ; V_134 < V_4 -> V_325 ; V_134 ++ ) {
V_107 = & V_4 -> V_324 [ V_134 ] ;
if ( V_107 -> V_176 == 0 ) {
F_37 ( L_79 ,
V_108 -> V_74 . V_74 . V_23 , V_107 -> V_109 ) ;
goto V_86;
}
}
return NULL ;
V_86:
V_108 -> V_175 = V_107 ;
V_107 -> V_176 ++ ;
F_53 ( L_80 , V_134 , V_108 -> V_89 ) ;
V_323:
F_53 ( L_81 , V_107 -> V_109 ) ;
F_8 ( V_107 -> V_109 , V_321 & ~ V_105 ) ;
F_11 ( V_107 -> V_109 ) ;
F_89 ( 150 ) ;
F_8 ( V_107 -> V_326 , V_322 ) ;
F_8 ( V_107 -> V_109 , V_321 & ~ V_105 ) ;
V_107 -> V_178 = false ;
return V_107 ;
}
void F_190 ( struct V_1 * V_2 , int V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_327 = F_43 ( V_89 ) , V_328 = F_191 ( V_89 ) ;
T_1 V_250 ;
V_250 = F_3 ( V_327 ) ;
F_89 ( 500 ) ;
if ( F_35 ( F_3 ( V_327 ) != V_250 , 5 ) ) {
F_8 ( V_328 , V_329 ) ;
F_89 ( 250 ) ;
F_8 ( V_328 , 0 ) ;
if ( F_35 ( F_3 ( V_327 ) != V_250 , 5 ) )
F_7 ( L_82 , V_89 ) ;
}
}
static void F_192 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
int V_132 = V_108 -> V_132 ;
T_1 V_250 ;
bool V_330 ;
if ( V_108 -> V_177 )
return;
V_108 -> V_177 = true ;
F_193 ( V_2 ) ;
if ( F_17 ( V_33 , V_36 ) ) {
V_250 = F_3 ( V_37 ) ;
if ( ( V_250 & V_152 ) == 0 )
F_8 ( V_37 , V_250 | V_152 ) ;
}
V_330 = F_165 ( V_33 ) ;
if ( V_330 )
F_159 ( V_33 ) ;
else
F_163 ( V_33 ) ;
if ( V_4 -> V_331 &&
( F_17 ( V_33 , V_36 ) || V_43 ) ) {
F_8 ( F_194 ( V_89 ) , V_332 | V_333 ) ;
F_8 ( F_195 ( V_89 ) , V_4 -> V_334 ) ;
F_8 ( F_196 ( V_89 ) , V_4 -> V_331 ) ;
}
F_197 ( V_33 ) ;
F_107 ( V_4 , V_89 , V_330 ) ;
F_113 ( V_4 , V_132 , V_89 ) ;
if ( V_330 )
F_172 ( V_33 ) ;
F_142 ( & V_2 -> V_238 ) ;
F_144 ( V_2 ) ;
F_143 ( & V_2 -> V_238 ) ;
F_198 ( V_33 , true ) ;
}
static void F_199 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
int V_132 = V_108 -> V_132 ;
T_1 V_8 , V_250 ;
if ( ! V_108 -> V_177 )
return;
F_164 ( V_33 ) ;
F_200 ( V_2 , V_89 ) ;
F_198 ( V_33 , false ) ;
F_115 ( V_4 , V_132 , V_89 ) ;
if ( V_4 -> V_335 == V_132 )
F_201 ( V_2 ) ;
F_109 ( V_4 , V_89 ) ;
F_8 ( F_194 ( V_89 ) , 0 ) ;
F_8 ( F_196 ( V_89 ) , 0 ) ;
F_163 ( V_33 ) ;
F_118 ( V_4 , V_89 ) ;
F_104 ( V_4 , V_89 ) ;
if ( F_54 ( V_2 ) ) {
V_8 = F_74 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
V_250 &= ~ ( V_315 | V_147 ) ;
V_250 |= V_336 ;
F_8 ( V_8 , V_250 ) ;
V_250 = F_3 ( V_111 ) ;
switch ( V_89 ) {
case 0 :
V_250 &= ~ ( V_306 | V_307 ) ;
break;
case 1 :
V_250 &= ~ ( V_308 | V_309 ) ;
break;
case 2 :
V_250 &= ~ ( V_310 | V_311 ) ;
break;
default:
F_122 () ;
}
F_8 ( V_111 , V_250 ) ;
}
F_97 ( V_108 ) ;
V_8 = F_60 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
F_8 ( V_8 , V_250 & ~ V_281 ) ;
V_8 = F_58 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
F_8 ( V_8 , V_250 & ~ V_117 ) ;
F_11 ( V_8 ) ;
F_89 ( 100 ) ;
V_8 = F_60 ( V_89 ) ;
V_250 = F_3 ( V_8 ) ;
F_8 ( V_8 , V_250 & ~ V_118 ) ;
F_11 ( V_8 ) ;
F_89 ( 100 ) ;
V_108 -> V_177 = false ;
F_193 ( V_2 ) ;
F_142 ( & V_2 -> V_238 ) ;
F_144 ( V_2 ) ;
F_143 ( & V_2 -> V_238 ) ;
}
static void F_202 ( struct V_32 * V_33 , int V_292 )
{
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
int V_132 = V_108 -> V_132 ;
switch ( V_292 ) {
case V_337 :
case V_338 :
case V_339 :
F_37 ( L_83 , V_89 , V_132 ) ;
F_192 ( V_33 ) ;
break;
case V_340 :
F_37 ( L_84 , V_89 , V_132 ) ;
F_199 ( V_33 ) ;
break;
}
}
static void F_203 ( struct V_32 * V_33 )
{
struct V_108 * V_108 = F_100 ( V_33 ) ;
F_188 ( V_108 ) ;
}
static void F_204 ( struct V_108 * V_108 , bool V_341 )
{
if ( ! V_341 && V_108 -> V_342 ) {
struct V_1 * V_2 = V_108 -> V_74 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_142 ( & V_2 -> V_238 ) ;
V_4 -> V_201 . V_202 = false ;
( void ) F_205 ( V_108 -> V_342 ) ;
V_4 -> V_201 . V_202 = true ;
F_143 ( & V_2 -> V_238 ) ;
}
}
static void F_206 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
int V_132 = V_108 -> V_132 ;
if ( V_108 -> V_177 )
return;
V_108 -> V_177 = true ;
F_193 ( V_2 ) ;
F_85 ( V_4 , V_89 ) ;
F_107 ( V_4 , V_89 , false ) ;
F_113 ( V_4 , V_132 , V_89 ) ;
F_197 ( V_33 ) ;
F_144 ( V_2 ) ;
F_204 ( V_108 , true ) ;
F_198 ( V_33 , true ) ;
}
static void F_207 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
int V_132 = V_108 -> V_132 ;
if ( ! V_108 -> V_177 )
return;
F_164 ( V_33 ) ;
F_200 ( V_2 , V_89 ) ;
F_204 ( V_108 , false ) ;
F_198 ( V_33 , false ) ;
if ( V_4 -> V_335 == V_132 )
F_201 ( V_2 ) ;
F_115 ( V_4 , V_132 , V_89 ) ;
F_109 ( V_4 , V_89 ) ;
F_90 ( V_4 , V_89 ) ;
V_108 -> V_177 = false ;
F_144 ( V_2 ) ;
F_193 ( V_2 ) ;
}
static void F_208 ( struct V_32 * V_33 , int V_292 )
{
switch ( V_292 ) {
case V_337 :
case V_338 :
case V_339 :
F_206 ( V_33 ) ;
break;
case V_340 :
F_207 ( V_33 ) ;
break;
}
}
static void F_209 ( struct V_32 * V_33 )
{
}
static void F_210 ( struct V_32 * V_33 , int V_292 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_235 * V_236 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
bool V_102 ;
if ( V_108 -> V_343 == V_292 )
return;
V_108 -> V_343 = V_292 ;
V_4 -> V_227 . V_344 ( V_33 , V_292 ) ;
if ( ! V_2 -> V_239 -> V_240 )
return;
V_236 = V_2 -> V_239 -> V_240 -> V_241 ;
if ( ! V_236 -> V_242 )
return;
V_102 = V_33 -> V_102 && V_292 != V_340 ;
switch ( V_89 ) {
case 0 :
V_236 -> V_242 -> V_345 = V_102 ? V_33 -> V_292 . V_346 : 0 ;
V_236 -> V_242 -> V_347 = V_102 ? V_33 -> V_292 . V_348 : 0 ;
break;
case 1 :
V_236 -> V_242 -> V_349 = V_102 ? V_33 -> V_292 . V_346 : 0 ;
V_236 -> V_242 -> V_350 = V_102 ? V_33 -> V_292 . V_348 : 0 ;
break;
default:
F_7 ( L_85 , F_64 ( V_89 ) ) ;
break;
}
}
static void F_211 ( struct V_32 * V_33 )
{
struct V_351 * V_352 = V_33 -> V_353 ;
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_352 -> V_344 ( V_33 , V_340 ) ;
V_4 -> V_227 . V_354 ( V_33 ) ;
F_212 ( V_2 -> V_5 , F_100 ( V_33 ) -> V_132 ) ;
F_91 ( V_2 -> V_5 , F_100 ( V_33 ) -> V_89 ) ;
if ( V_33 -> V_206 ) {
F_142 ( & V_2 -> V_238 ) ;
F_127 ( F_130 ( V_33 -> V_206 ) -> V_191 ) ;
F_143 ( & V_2 -> V_238 ) ;
}
}
static void F_213 ( struct V_32 * V_33 )
{
F_207 ( V_33 ) ;
}
static void F_214 ( struct V_32 * V_33 )
{
F_206 ( V_33 ) ;
}
static void F_215 ( struct V_32 * V_33 )
{
F_199 ( V_33 ) ;
}
static void F_216 ( struct V_32 * V_33 )
{
F_192 ( V_33 ) ;
}
void F_217 ( struct V_355 * V_73 )
{
struct V_356 * V_357 = V_73 -> V_353 ;
V_357 -> V_344 ( V_73 , V_340 ) ;
}
void F_218 ( struct V_355 * V_73 )
{
struct V_356 * V_357 = V_73 -> V_353 ;
struct V_1 * V_2 = V_73 -> V_2 ;
struct V_108 * V_108 = F_100 ( V_73 -> V_33 ) ;
V_357 -> V_344 ( V_73 , V_337 ) ;
if ( F_54 ( V_2 ) )
F_190 ( V_2 , V_108 -> V_89 ) ;
}
void F_219 ( struct V_355 * V_73 )
{
struct V_72 * V_72 = F_220 ( V_73 ) ;
F_221 ( V_73 ) ;
F_222 ( V_72 ) ;
}
static bool F_223 ( struct V_32 * V_33 ,
struct V_358 * V_292 ,
struct V_358 * V_359 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
if ( F_20 ( V_2 ) ) {
if ( V_292 -> clock * 3 > V_360 * 4 )
return false ;
}
if ( ! ( V_359 -> V_361 & V_362 ) )
F_224 ( V_359 , 0 ) ;
return true ;
}
static int F_225 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_226 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_227 ( struct V_1 * V_2 )
{
return 333000 ;
}
static int F_228 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_229 ( struct V_1 * V_2 )
{
T_4 V_363 = 0 ;
F_230 ( V_2 -> V_364 , V_365 , & V_363 ) ;
if ( V_363 & V_366 )
return 133000 ;
else {
switch ( V_363 & V_367 ) {
case V_368 :
return 333000 ;
default:
case V_369 :
return 190000 ;
}
}
}
static int F_231 ( struct V_1 * V_2 )
{
return 266000 ;
}
static int F_232 ( struct V_1 * V_2 )
{
T_4 V_370 = 0 ;
switch ( V_370 & V_371 ) {
case V_372 :
case V_373 :
return 200000 ;
case V_374 :
return 250000 ;
case V_375 :
return 133000 ;
}
return 0 ;
}
static int F_233 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_234 ( T_1 * V_376 , T_1 * V_377 )
{
while ( * V_376 > 0xffffff || * V_377 > 0xffffff ) {
* V_376 >>= 1 ;
* V_377 >>= 1 ;
}
}
static void
F_235 ( int V_215 , int V_378 , int V_379 ,
int V_380 , struct V_381 * V_382 )
{
V_382 -> V_383 = 64 ;
V_382 -> V_384 = V_215 * V_379 ;
V_382 -> V_385 = V_380 * V_378 * 8 ;
F_234 ( & V_382 -> V_384 , & V_382 -> V_385 ) ;
V_382 -> V_386 = V_379 ;
V_382 -> V_387 = V_380 ;
F_234 ( & V_382 -> V_386 , & V_382 -> V_387 ) ;
}
static inline bool F_236 ( struct V_3 * V_4 )
{
if ( V_388 >= 0 )
return V_388 != 0 ;
return V_4 -> V_389
&& ! ( V_4 -> V_129 & V_390 ) ;
}
static bool F_237 ( struct V_32 * V_33 ,
unsigned int * V_391 ,
struct V_358 * V_292 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_355 * V_73 ;
struct V_392 * V_393 ;
unsigned int V_394 = V_395 , V_312 ;
F_26 (encoder, &dev->mode_config.encoder_list, head) {
struct V_72 * V_72 = F_220 ( V_73 ) ;
if ( V_73 -> V_33 != V_33 )
continue;
if ( V_72 -> type == V_36 ) {
unsigned int V_396 ;
if ( ( F_3 ( V_37 ) & V_397 ) ==
V_398 )
V_396 = 8 ;
else
V_396 = 6 ;
if ( V_396 < V_394 ) {
F_37 ( L_86 , V_394 , V_396 ) ;
V_394 = V_396 ;
}
continue;
}
if ( V_72 -> type == V_283 ) {
unsigned int V_399 = V_4 -> V_400 . V_401 / 3 ;
if ( V_399 < V_394 ) {
F_37 ( L_87 , V_394 , V_399 ) ;
V_394 = V_399 ;
}
continue;
}
F_26 (connector, &dev->mode_config.connector_list,
head) {
if ( V_393 -> V_73 != V_73 )
continue;
if ( V_393 -> V_402 . V_312 &&
V_393 -> V_402 . V_312 < V_394 ) {
F_37 ( L_88 , V_394 , V_393 -> V_402 . V_312 ) ;
V_394 = V_393 -> V_402 . V_312 ;
}
}
if ( V_72 -> type == V_49 ) {
if ( V_394 > 8 && V_394 < 12 ) {
F_37 ( L_89 ) ;
V_394 = 12 ;
} else {
F_37 ( L_90 ) ;
V_394 = 8 ;
}
}
}
if ( V_292 -> V_361 & V_403 ) {
F_37 ( L_91 ) ;
V_394 = 6 ;
}
switch ( V_33 -> V_206 -> V_217 ) {
case 8 :
V_312 = 8 ;
break;
case 15 :
case 16 :
V_312 = 6 ;
break;
case 24 :
V_312 = 8 ;
break;
case 30 :
V_312 = 10 ;
break;
case 48 :
V_312 = 12 ;
break;
default:
F_238 ( L_92 ) ;
V_312 = V_75 ( ( unsigned int ) 8 , V_394 ) ;
break;
}
V_394 = V_75 ( V_394 , V_312 ) ;
F_37 ( L_93 ,
V_312 , V_394 ) ;
* V_391 = V_394 * 3 ;
return V_394 != V_312 ;
}
static int F_239 ( struct V_32 * V_33 , int V_404 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_34 ;
if ( F_17 ( V_33 , V_36 ) &&
F_236 ( V_4 ) && V_404 < 2 ) {
V_34 = V_4 -> V_405 * 1000 ;
F_37 ( L_94 ,
V_34 / 1000 ) ;
} else if ( ! F_23 ( V_2 ) ) {
V_34 = 96000 ;
} else {
V_34 = 48000 ;
}
return V_34 ;
}
static void F_240 ( struct V_358 * V_359 ,
T_3 * clock )
{
if ( V_359 -> clock >= 100000
&& V_359 -> clock < 140500 ) {
clock -> V_64 = 2 ;
clock -> V_65 = 10 ;
clock -> V_67 = 3 ;
clock -> V_69 = 16 ;
clock -> V_62 = 8 ;
} else if ( V_359 -> clock >= 140500
&& V_359 -> clock <= 200000 ) {
clock -> V_64 = 1 ;
clock -> V_65 = 10 ;
clock -> V_67 = 6 ;
clock -> V_69 = 12 ;
clock -> V_62 = 8 ;
}
}
static void F_241 ( struct V_32 * V_33 ,
T_3 * clock ,
T_3 * V_406 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
T_1 V_322 , V_407 = 0 ;
if ( F_22 ( V_2 ) ) {
V_322 = ( 1 << clock -> V_67 ) << 16 | clock -> V_69 << 8 | clock -> V_62 ;
if ( V_406 )
V_407 = ( 1 << V_406 -> V_67 ) << 16 |
V_406 -> V_69 << 8 | V_406 -> V_62 ;
} else {
V_322 = clock -> V_67 << 16 | clock -> V_69 << 8 | clock -> V_62 ;
if ( V_406 )
V_407 = V_406 -> V_67 << 16 | V_406 -> V_69 << 8 |
V_406 -> V_62 ;
}
F_8 ( F_242 ( V_89 ) , V_322 ) ;
V_108 -> V_408 = false ;
if ( F_17 ( V_33 , V_36 ) &&
V_406 && V_409 ) {
F_8 ( F_243 ( V_89 ) , V_407 ) ;
V_108 -> V_408 = true ;
} else {
F_8 ( F_243 ( V_89 ) , V_322 ) ;
}
}
static void F_244 ( struct V_32 * V_33 , T_3 * clock ,
struct V_358 * V_359 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
T_1 V_250 ;
V_250 = F_3 ( V_46 ) ;
V_250 |= V_152 | V_410 ;
if ( V_89 == 1 ) {
V_250 |= V_127 ;
} else {
V_250 &= ~ V_127 ;
}
V_250 |= V_4 -> V_411 ;
if ( clock -> V_65 == 7 )
V_250 |= V_412 | V_31 ;
else
V_250 &= ~ ( V_412 | V_31 ) ;
if ( F_40 ( V_2 ) -> V_93 >= 4 ) {
if ( V_4 -> V_413 )
V_250 |= V_414 ;
else
V_250 &= ~ V_414 ;
}
V_250 &= ~ ( V_415 | V_416 ) ;
if ( V_359 -> V_9 & V_417 )
V_250 |= V_415 ;
if ( V_359 -> V_9 & V_418 )
V_250 |= V_416 ;
F_8 ( V_46 , V_250 ) ;
}
static void F_245 ( struct V_32 * V_33 ,
struct V_358 * V_292 ,
struct V_358 * V_359 ,
T_3 * clock , T_3 * V_406 ,
int V_404 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
T_1 V_321 ;
bool V_419 ;
V_419 = F_17 ( V_33 , V_52 ) ||
F_17 ( V_33 , V_49 ) ;
V_321 = V_420 ;
if ( F_17 ( V_33 , V_36 ) )
V_321 |= V_421 ;
else
V_321 |= V_422 ;
if ( V_419 ) {
int V_423 = F_246 ( V_359 ) ;
if ( V_423 > 1 ) {
if ( F_247 ( V_2 ) || F_248 ( V_2 ) || F_249 ( V_2 ) )
V_321 |= ( V_423 - 1 ) << V_424 ;
}
V_321 |= V_425 ;
}
if ( F_17 ( V_33 , V_42 ) )
V_321 |= V_425 ;
if ( F_22 ( V_2 ) )
V_321 |= ( 1 << ( clock -> V_64 - 1 ) ) << V_426 ;
else {
V_321 |= ( 1 << ( clock -> V_64 - 1 ) ) << V_427 ;
if ( F_21 ( V_2 ) && V_406 )
V_321 |= ( 1 << ( V_406 -> V_64 - 1 ) ) << V_428 ;
}
switch ( clock -> V_65 ) {
case 5 :
V_321 |= V_429 ;
break;
case 7 :
V_321 |= V_430 ;
break;
case 10 :
V_321 |= V_431 ;
break;
case 14 :
V_321 |= V_432 ;
break;
}
if ( F_40 ( V_2 ) -> V_93 >= 4 )
V_321 |= ( 6 << V_433 ) ;
if ( V_419 && F_17 ( V_33 , V_434 ) )
V_321 |= V_435 ;
else if ( F_17 ( V_33 , V_434 ) )
V_321 |= 3 ;
else if ( F_17 ( V_33 , V_36 ) &&
F_236 ( V_4 ) && V_404 < 2 )
V_321 |= V_436 ;
else
V_321 |= V_437 ;
V_321 |= V_105 ;
F_8 ( F_49 ( V_89 ) , V_321 & ~ V_105 ) ;
F_11 ( F_49 ( V_89 ) ) ;
F_89 ( 150 ) ;
if ( F_17 ( V_33 , V_36 ) )
F_244 ( V_33 , clock , V_359 ) ;
if ( F_17 ( V_33 , V_42 ) )
F_250 ( V_33 , V_292 , V_359 ) ;
F_8 ( F_49 ( V_89 ) , V_321 ) ;
F_11 ( F_49 ( V_89 ) ) ;
F_89 ( 150 ) ;
if ( F_40 ( V_2 ) -> V_93 >= 4 ) {
T_1 V_250 = 0 ;
if ( V_419 ) {
V_250 = F_246 ( V_359 ) ;
if ( V_250 > 1 )
V_250 = ( V_250 - 1 ) << V_438 ;
else
V_250 = 0 ;
}
F_8 ( F_251 ( V_89 ) , V_250 ) ;
} else {
F_8 ( F_49 ( V_89 ) , V_321 ) ;
}
}
static void F_252 ( struct V_32 * V_33 ,
struct V_358 * V_359 ,
T_3 * clock ,
int V_404 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
T_1 V_321 ;
V_321 = V_420 ;
if ( F_17 ( V_33 , V_36 ) ) {
V_321 |= ( 1 << ( clock -> V_64 - 1 ) ) << V_427 ;
} else {
if ( clock -> V_64 == 2 )
V_321 |= V_439 ;
else
V_321 |= ( clock -> V_64 - 2 ) << V_427 ;
if ( clock -> V_65 == 4 )
V_321 |= V_440 ;
}
if ( F_17 ( V_33 , V_434 ) )
V_321 |= 3 ;
else if ( F_17 ( V_33 , V_36 ) &&
F_236 ( V_4 ) && V_404 < 2 )
V_321 |= V_436 ;
else
V_321 |= V_437 ;
V_321 |= V_105 ;
F_8 ( F_49 ( V_89 ) , V_321 & ~ V_105 ) ;
F_11 ( F_49 ( V_89 ) ) ;
F_89 ( 150 ) ;
F_8 ( F_49 ( V_89 ) , V_321 ) ;
F_11 ( F_49 ( V_89 ) ) ;
F_89 ( 150 ) ;
if ( F_17 ( V_33 , V_36 ) )
F_244 ( V_33 , clock , V_359 ) ;
F_8 ( F_49 ( V_89 ) , V_321 ) ;
}
static int F_253 ( struct V_32 * V_33 ,
struct V_358 * V_292 ,
struct V_358 * V_359 ,
int V_207 , int V_208 ,
struct V_205 * V_230 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
int V_132 = V_108 -> V_132 ;
int V_34 , V_404 = 0 ;
T_3 clock , V_406 ;
T_1 V_213 , V_441 , V_442 ;
bool V_443 , V_444 = false , V_419 = false ;
bool V_445 = false , V_446 = false , V_447 = false ;
struct V_70 * V_71 = & V_2 -> V_71 ;
struct V_72 * V_73 ;
const T_2 * V_35 ;
int V_195 ;
F_26 (encoder, &mode_config->encoder_list, base.head) {
if ( V_73 -> V_74 . V_33 != V_33 )
continue;
switch ( V_73 -> type ) {
case V_36 :
V_445 = true ;
break;
case V_52 :
case V_49 :
V_419 = true ;
if ( V_73 -> V_448 )
V_446 = true ;
break;
case V_434 :
V_446 = true ;
break;
case V_42 :
V_447 = true ;
break;
}
V_404 ++ ;
}
V_34 = F_239 ( V_33 , V_404 ) ;
V_35 = F_19 ( V_33 , V_34 ) ;
V_443 = V_35 -> V_449 ( V_35 , V_33 , V_359 -> clock , V_34 , NULL ,
& clock ) ;
if ( ! V_443 ) {
F_7 ( L_95 ) ;
return - V_200 ;
}
F_198 ( V_33 , true ) ;
if ( V_445 && V_4 -> V_450 ) {
V_444 = V_35 -> V_449 ( V_35 , V_33 ,
V_4 -> V_451 ,
V_34 ,
& clock ,
& V_406 ) ;
}
if ( V_419 && V_446 )
F_240 ( V_359 , & clock ) ;
F_241 ( V_33 , & clock , V_444 ?
& V_406 : NULL ) ;
if ( F_23 ( V_2 ) )
F_252 ( V_33 , V_359 , & clock , V_404 ) ;
else
F_245 ( V_33 , V_292 , V_359 , & clock ,
V_444 ? & V_406 : NULL ,
V_404 ) ;
V_441 = F_3 ( F_42 ( V_89 ) ) ;
V_213 = V_452 ;
if ( V_89 == 0 )
V_213 &= ~ V_136 ;
else
V_213 |= V_453 ;
if ( V_89 == 0 && F_40 ( V_2 ) -> V_93 < 4 ) {
if ( V_292 -> clock >
V_4 -> V_227 . V_454 ( V_2 ) * 9 / 10 )
V_441 |= V_455 ;
else
V_441 &= ~ V_455 ;
}
V_441 &= ~ ( V_456 | V_457 ) ;
if ( V_447 ) {
if ( V_292 -> V_361 & V_403 ) {
V_441 |= V_458 |
V_457 |
V_459 ;
}
}
F_37 ( L_96 , V_89 == 0 ? 'A' : 'B' ) ;
F_254 ( V_292 ) ;
if ( F_255 ( V_2 ) ) {
if ( V_108 -> V_408 ) {
F_37 ( L_97 ) ;
V_441 |= V_460 ;
} else {
F_37 ( L_98 ) ;
V_441 &= ~ V_460 ;
}
}
V_441 &= ~ V_183 ;
if ( ! F_23 ( V_2 ) &&
V_359 -> V_9 & V_461 ) {
V_441 |= V_462 ;
V_359 -> V_463 -= 1 ;
V_359 -> V_464 -= 1 ;
V_442 = V_359 -> V_465
- V_359 -> V_466 / 2 ;
} else {
V_441 |= V_467 ;
V_442 = 0 ;
}
if ( ! F_256 ( V_2 ) )
F_8 ( F_186 ( V_89 ) , V_442 ) ;
F_8 ( F_174 ( V_89 ) ,
( V_359 -> V_468 - 1 ) |
( ( V_359 -> V_466 - 1 ) << 16 ) ) ;
F_8 ( F_176 ( V_89 ) ,
( V_359 -> V_469 - 1 ) |
( ( V_359 -> V_470 - 1 ) << 16 ) ) ;
F_8 ( F_178 ( V_89 ) ,
( V_359 -> V_465 - 1 ) |
( ( V_359 -> V_471 - 1 ) << 16 ) ) ;
F_8 ( F_180 ( V_89 ) ,
( V_359 -> V_472 - 1 ) |
( ( V_359 -> V_463 - 1 ) << 16 ) ) ;
F_8 ( F_182 ( V_89 ) ,
( V_359 -> V_473 - 1 ) |
( ( V_359 -> V_464 - 1 ) << 16 ) ) ;
F_8 ( F_184 ( V_89 ) ,
( V_359 -> V_474 - 1 ) |
( ( V_359 -> V_475 - 1 ) << 16 ) ) ;
F_8 ( F_257 ( V_132 ) ,
( ( V_292 -> V_348 - 1 ) << 16 ) |
( V_292 -> V_346 - 1 ) ) ;
F_8 ( F_258 ( V_132 ) , 0 ) ;
F_8 ( F_259 ( V_89 ) ,
( ( V_292 -> V_346 - 1 ) << 16 ) | ( V_292 -> V_348 - 1 ) ) ;
F_8 ( F_42 ( V_89 ) , V_441 ) ;
F_11 ( F_42 ( V_89 ) ) ;
F_107 ( V_4 , V_89 , false ) ;
F_38 ( V_2 , V_89 ) ;
F_8 ( F_67 ( V_132 ) , V_213 ) ;
F_11 ( F_67 ( V_132 ) ) ;
V_195 = F_141 ( V_33 , V_207 , V_208 , V_230 ) ;
F_193 ( V_2 ) ;
return V_195 ;
}
void F_260 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_70 * V_71 = & V_2 -> V_71 ;
struct V_72 * V_73 ;
T_1 V_250 ;
bool V_476 = false ;
bool V_477 = false ;
bool V_478 = false ;
bool V_479 = false ;
bool V_480 = false ;
bool V_481 = false ;
F_26 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_73 -> type ) {
case V_36 :
V_479 = true ;
V_476 = true ;
break;
case V_283 :
V_479 = true ;
if ( F_166 ( & V_73 -> V_74 ) )
V_478 = true ;
else
V_477 = true ;
break;
}
}
if ( F_103 ( V_2 ) ) {
V_480 = V_4 -> V_482 ;
V_481 = V_480 ;
} else {
V_480 = false ;
V_481 = true ;
}
F_37 ( L_99 ,
V_479 , V_476 , V_478 , V_477 ,
V_480 ) ;
V_250 = F_3 ( V_138 ) ;
V_250 &= ~ V_140 ;
if ( V_480 )
V_250 |= V_483 ;
else
V_250 |= V_484 ;
if ( V_479 ) {
V_250 &= ~ V_139 ;
V_250 |= V_485 ;
if ( F_236 ( V_4 ) && V_481 ) {
F_37 ( L_100 ) ;
V_250 |= V_486 ;
} else
V_250 &= ~ V_486 ;
F_8 ( V_138 , V_250 ) ;
F_11 ( V_138 ) ;
F_89 ( 200 ) ;
V_250 &= ~ V_487 ;
if ( V_477 ) {
if ( F_236 ( V_4 ) && V_481 ) {
F_37 ( L_101 ) ;
V_250 |= V_488 ;
}
else
V_250 |= V_489 ;
} else
V_250 |= V_490 ;
F_8 ( V_138 , V_250 ) ;
F_11 ( V_138 ) ;
F_89 ( 200 ) ;
} else {
F_37 ( L_102 ) ;
V_250 &= ~ V_487 ;
V_250 |= V_490 ;
F_8 ( V_138 , V_250 ) ;
F_11 ( V_138 ) ;
F_89 ( 200 ) ;
V_250 &= ~ V_139 ;
V_250 |= V_491 ;
V_250 &= ~ V_486 ;
F_8 ( V_138 , V_250 ) ;
F_11 ( V_138 ) ;
F_89 ( 200 ) ;
}
}
static int F_261 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_72 * V_73 ;
struct V_70 * V_71 = & V_2 -> V_71 ;
struct V_72 * V_492 = NULL ;
int V_404 = 0 ;
bool V_445 = false ;
F_26 (encoder, &mode_config->encoder_list, base.head) {
if ( V_73 -> V_74 . V_33 != V_33 )
continue;
switch ( V_73 -> type ) {
case V_36 :
V_445 = true ;
break;
case V_283 :
V_492 = V_73 ;
break;
}
V_404 ++ ;
}
if ( V_445 && F_236 ( V_4 ) && V_404 < 2 ) {
F_37 ( L_94 ,
V_4 -> V_405 ) ;
return V_4 -> V_405 * 1000 ;
}
return 120000 ;
}
static int F_262 ( struct V_32 * V_33 ,
struct V_358 * V_292 ,
struct V_358 * V_359 ,
int V_207 , int V_208 ,
struct V_205 * V_230 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
int V_132 = V_108 -> V_132 ;
int V_34 , V_404 = 0 ;
T_3 clock , V_406 ;
T_1 V_321 , V_322 = 0 , V_407 = 0 , V_213 , V_441 ;
bool V_443 , V_444 = false , V_419 = false ;
bool V_493 = false , V_445 = false , V_446 = false , V_447 = false ;
struct V_70 * V_71 = & V_2 -> V_71 ;
struct V_72 * V_73 , * V_492 = NULL ;
const T_2 * V_35 ;
int V_195 ;
struct V_381 V_382 = { 0 } ;
T_1 V_250 ;
int V_494 , V_423 , V_495 , V_496 , V_497 ;
unsigned int V_391 ;
bool V_498 ;
bool V_499 = false , V_500 = false ;
F_26 (encoder, &mode_config->encoder_list, base.head) {
if ( V_73 -> V_74 . V_33 != V_33 )
continue;
switch ( V_73 -> type ) {
case V_36 :
V_445 = true ;
break;
case V_52 :
case V_49 :
V_419 = true ;
if ( V_73 -> V_448 )
V_446 = true ;
break;
case V_434 :
V_446 = true ;
break;
case V_50 :
V_493 = true ;
break;
case V_42 :
V_447 = true ;
break;
case V_283 :
V_447 = true ;
if ( F_166 ( & V_73 -> V_74 ) )
V_500 = true ;
else
V_499 = true ;
V_492 = V_73 ;
break;
}
V_404 ++ ;
}
V_34 = F_261 ( V_33 ) ;
V_35 = F_19 ( V_33 , V_34 ) ;
V_443 = V_35 -> V_449 ( V_35 , V_33 , V_359 -> clock , V_34 , NULL ,
& clock ) ;
if ( ! V_443 ) {
F_7 ( L_95 ) ;
return - V_200 ;
}
F_198 ( V_33 , true ) ;
if ( V_445 && V_4 -> V_450 ) {
V_444 = V_35 -> V_449 ( V_35 , V_33 ,
V_4 -> V_451 ,
V_34 ,
& clock ,
& V_406 ) ;
}
if ( V_419 && V_446 ) {
if ( V_359 -> clock >= 100000
&& V_359 -> clock < 140500 ) {
clock . V_64 = 2 ;
clock . V_65 = 10 ;
clock . V_67 = 3 ;
clock . V_69 = 16 ;
clock . V_62 = 8 ;
} else if ( V_359 -> clock >= 140500
&& V_359 -> clock <= 200000 ) {
clock . V_64 = 1 ;
clock . V_65 = 10 ;
clock . V_67 = 6 ;
clock . V_69 = 12 ;
clock . V_62 = 8 ;
}
}
V_423 = F_246 ( V_359 ) ;
V_495 = 0 ;
if ( V_499 ) {
V_494 = V_292 -> clock ;
F_263 ( V_492 , & V_495 , & V_496 ) ;
} else {
if ( V_447 )
V_494 = V_292 -> clock ;
else
V_494 = V_359 -> clock ;
V_496 = F_1 ( V_2 ) * F_264 ( 100 ) / F_265 ( 1 ) / 10 ;
}
V_250 = F_3 ( F_42 ( V_89 ) ) ;
V_250 &= ~ V_181 ;
V_498 = F_237 ( V_33 , & V_391 , V_292 ) ;
switch ( V_391 ) {
case 18 :
V_250 |= V_501 ;
break;
case 24 :
V_250 |= V_502 ;
break;
case 30 :
V_250 |= V_503 ;
break;
case 36 :
V_250 |= V_504 ;
break;
default:
F_50 ( 1 , L_103 ,
V_391 ) ;
V_250 |= V_502 ;
V_391 = 24 ;
break;
}
V_108 -> V_401 = V_391 ;
F_8 ( F_42 ( V_89 ) , V_250 ) ;
if ( ! V_495 ) {
T_1 V_505 = V_494 * V_108 -> V_401 * 21 / 20 ;
V_495 = V_505 / ( V_496 * 8 ) + 1 ;
}
V_108 -> V_265 = V_495 ;
if ( V_423 > 1 )
V_496 *= V_423 ;
F_235 ( V_108 -> V_401 , V_495 , V_494 , V_496 ,
& V_382 ) ;
V_322 = clock . V_67 << 16 | clock . V_69 << 8 | clock . V_62 ;
if ( V_444 )
V_407 = V_406 . V_67 << 16 | V_406 . V_69 << 8 |
V_406 . V_62 ;
V_497 = 21 ;
if ( V_445 ) {
if ( ( F_236 ( V_4 ) &&
V_4 -> V_405 == 100 ) ||
( F_3 ( V_37 ) & V_30 ) == V_31 )
V_497 = 25 ;
} else if ( V_419 && V_446 )
V_497 = 20 ;
if ( clock . V_61 < V_497 * clock . V_67 )
V_322 |= V_506 ;
V_321 = 0 ;
if ( V_445 )
V_321 |= V_421 ;
else
V_321 |= V_422 ;
if ( V_419 ) {
int V_423 = F_246 ( V_359 ) ;
if ( V_423 > 1 ) {
V_321 |= ( V_423 - 1 ) << V_507 ;
}
V_321 |= V_425 ;
}
if ( V_447 && ! V_499 )
V_321 |= V_425 ;
V_321 |= ( 1 << ( clock . V_64 - 1 ) ) << V_427 ;
V_321 |= ( 1 << ( clock . V_64 - 1 ) ) << V_428 ;
switch ( clock . V_65 ) {
case 5 :
V_321 |= V_429 ;
break;
case 7 :
V_321 |= V_430 ;
break;
case 10 :
V_321 |= V_431 ;
break;
case 14 :
V_321 |= V_432 ;
break;
}
if ( V_419 && V_446 )
V_321 |= V_435 ;
else if ( V_446 )
V_321 |= 3 ;
else if ( V_445 && F_236 ( V_4 ) && V_404 < 2 )
V_321 |= V_436 ;
else
V_321 |= V_437 ;
V_441 = F_3 ( F_42 ( V_89 ) ) ;
V_213 = V_452 ;
F_37 ( L_104 , V_89 ) ;
F_254 ( V_292 ) ;
if ( F_52 ( V_2 ) ) {
F_37 ( L_105 ,
V_89 ) ;
} else if ( ! V_499 ) {
struct V_106 * V_107 ;
V_107 = F_189 ( V_108 , V_321 , V_322 ) ;
if ( V_107 == NULL ) {
F_53 ( L_106 ,
V_89 ) ;
return - V_200 ;
}
} else
F_188 ( V_108 ) ;
if ( V_445 ) {
V_250 = F_3 ( V_37 ) ;
V_250 |= V_152 | V_410 ;
if ( F_54 ( V_2 ) ) {
V_250 &= ~ V_150 ;
V_250 |= F_76 ( V_89 ) ;
} else {
if ( V_89 == 1 )
V_250 |= V_127 ;
else
V_250 &= ~ V_127 ;
}
V_250 |= V_4 -> V_411 ;
if ( clock . V_65 == 7 )
V_250 |= V_412 | V_31 ;
else
V_250 &= ~ ( V_412 | V_31 ) ;
V_250 &= ~ ( V_415 | V_416 ) ;
if ( V_359 -> V_9 & V_417 )
V_250 |= V_415 ;
if ( V_359 -> V_9 & V_418 )
V_250 |= V_416 ;
F_8 ( V_37 , V_250 ) ;
}
V_441 &= ~ V_457 ;
V_441 &= ~ V_508 ;
if ( ( V_445 && V_4 -> V_413 ) || V_498 ) {
V_441 |= V_457 ;
V_441 |= V_459 ;
}
if ( V_447 && ! V_499 ) {
F_250 ( V_33 , V_292 , V_359 ) ;
} else {
F_8 ( F_266 ( V_89 ) , 0 ) ;
F_8 ( F_267 ( V_89 ) , 0 ) ;
F_8 ( F_268 ( V_89 ) , 0 ) ;
F_8 ( F_269 ( V_89 ) , 0 ) ;
}
if ( V_108 -> V_175 ) {
F_8 ( V_108 -> V_175 -> V_109 , V_321 ) ;
F_11 ( V_108 -> V_175 -> V_109 ) ;
F_89 ( 150 ) ;
F_8 ( V_108 -> V_175 -> V_109 , V_321 ) ;
}
V_108 -> V_408 = false ;
if ( V_108 -> V_175 ) {
if ( V_445 && V_444 && V_409 ) {
F_8 ( V_108 -> V_175 -> V_509 , V_407 ) ;
V_108 -> V_408 = true ;
if ( F_255 ( V_2 ) ) {
F_37 ( L_97 ) ;
V_441 |= V_460 ;
}
} else {
F_8 ( V_108 -> V_175 -> V_509 , V_322 ) ;
if ( F_255 ( V_2 ) ) {
F_37 ( L_98 ) ;
V_441 &= ~ V_460 ;
}
}
}
V_441 &= ~ V_183 ;
if ( V_359 -> V_9 & V_461 ) {
V_441 |= V_184 ;
V_359 -> V_463 -= 1 ;
V_359 -> V_464 -= 1 ;
F_8 ( F_186 ( V_89 ) ,
V_359 -> V_465
- V_359 -> V_466 / 2 ) ;
} else {
V_441 |= V_467 ;
F_8 ( F_186 ( V_89 ) , 0 ) ;
}
F_8 ( F_174 ( V_89 ) ,
( V_359 -> V_468 - 1 ) |
( ( V_359 -> V_466 - 1 ) << 16 ) ) ;
F_8 ( F_176 ( V_89 ) ,
( V_359 -> V_469 - 1 ) |
( ( V_359 -> V_470 - 1 ) << 16 ) ) ;
F_8 ( F_178 ( V_89 ) ,
( V_359 -> V_465 - 1 ) |
( ( V_359 -> V_471 - 1 ) << 16 ) ) ;
F_8 ( F_180 ( V_89 ) ,
( V_359 -> V_472 - 1 ) |
( ( V_359 -> V_463 - 1 ) << 16 ) ) ;
F_8 ( F_182 ( V_89 ) ,
( V_359 -> V_473 - 1 ) |
( ( V_359 -> V_464 - 1 ) << 16 ) ) ;
F_8 ( F_184 ( V_89 ) ,
( V_359 -> V_474 - 1 ) |
( ( V_359 -> V_475 - 1 ) << 16 ) ) ;
F_8 ( F_259 ( V_89 ) ,
( ( V_292 -> V_346 - 1 ) << 16 ) | ( V_292 -> V_348 - 1 ) ) ;
F_8 ( F_161 ( V_89 ) , F_270 ( V_382 . V_383 ) | V_382 . V_384 ) ;
F_8 ( F_271 ( V_89 ) , V_382 . V_385 ) ;
F_8 ( F_272 ( V_89 ) , V_382 . V_386 ) ;
F_8 ( F_273 ( V_89 ) , V_382 . V_387 ) ;
if ( V_499 )
F_145 ( V_33 , V_359 -> clock ) ;
F_8 ( F_42 ( V_89 ) , V_441 ) ;
F_11 ( F_42 ( V_89 ) ) ;
F_38 ( V_2 , V_89 ) ;
F_8 ( F_67 ( V_132 ) , V_213 ) ;
F_11 ( F_67 ( V_132 ) ) ;
V_195 = F_141 ( V_33 , V_207 , V_208 , V_230 ) ;
F_193 ( V_2 ) ;
F_274 ( V_2 , V_89 , V_359 ) ;
return V_195 ;
}
static int F_275 ( struct V_32 * V_33 ,
struct V_358 * V_292 ,
struct V_358 * V_359 ,
int V_207 , int V_208 ,
struct V_205 * V_230 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
int V_195 ;
F_276 ( V_2 , V_89 ) ;
V_195 = V_4 -> V_227 . V_510 ( V_33 , V_292 , V_359 ,
V_207 , V_208 , V_230 ) ;
F_277 ( V_2 , V_89 ) ;
if ( V_195 )
V_108 -> V_343 = V_340 ;
else
V_108 -> V_343 = V_337 ;
return V_195 ;
}
static bool F_278 ( struct V_392 * V_393 ,
int V_511 , T_5 V_512 ,
int V_513 , T_5 V_514 ,
int V_515 )
{
struct V_3 * V_4 = V_393 -> V_2 -> V_5 ;
T_6 * V_516 = V_393 -> V_516 ;
T_5 V_134 ;
V_134 = F_3 ( V_511 ) ;
V_134 &= V_512 ;
if ( ! V_516 [ 0 ] )
return ! V_134 ;
if ( ! V_134 )
return false ;
V_134 = F_3 ( V_513 ) ;
V_134 &= ~ V_514 ;
F_8 ( V_513 , V_134 ) ;
for ( V_134 = 0 ; V_134 < V_516 [ 2 ] ; V_134 ++ )
if ( F_3 ( V_515 ) != * ( ( T_5 * ) V_516 + V_134 ) )
return false ;
return true ;
}
static void F_279 ( struct V_392 * V_393 ,
struct V_32 * V_33 )
{
struct V_3 * V_4 = V_393 -> V_2 -> V_5 ;
T_6 * V_516 = V_393 -> V_516 ;
T_5 V_517 ;
T_5 V_518 ;
T_5 V_134 ;
V_134 = F_3 ( V_519 ) ;
if ( V_134 == V_520 || V_134 == V_521 )
V_517 = V_522 ;
else
V_517 = V_523 ;
if ( F_278 ( V_393 ,
V_524 , V_517 ,
V_524 , V_525 ,
V_526 ) )
return;
V_134 = F_3 ( V_524 ) ;
V_134 &= ~ ( V_517 | V_525 ) ;
V_518 = ( V_134 >> 9 ) & 0x1f ;
F_8 ( V_524 , V_134 ) ;
if ( ! V_516 [ 0 ] )
return;
V_518 = F_280 ( T_6 , V_516 [ 2 ] , V_518 ) ;
F_53 ( L_107 , V_518 ) ;
for ( V_134 = 0 ; V_134 < V_518 ; V_134 ++ )
F_8 ( V_526 , * ( ( T_5 * ) V_516 + V_134 ) ) ;
V_134 = F_3 ( V_524 ) ;
V_134 |= V_517 ;
F_8 ( V_524 , V_134 ) ;
}
static void F_281 ( struct V_392 * V_393 ,
struct V_32 * V_33 )
{
struct V_3 * V_4 = V_393 -> V_2 -> V_5 ;
T_6 * V_516 = V_393 -> V_516 ;
T_5 V_517 ;
T_5 V_134 ;
int V_518 ;
int V_527 ;
int V_528 ;
int V_529 ;
int V_530 ;
if ( F_103 ( V_393 -> V_2 ) ) {
V_527 = V_531 ;
V_528 = V_532 ;
V_529 = V_533 ;
V_530 = V_534 ;
} else {
V_527 = V_535 ;
V_528 = V_536 ;
V_529 = V_537 ;
V_530 = V_538 ;
}
V_134 = F_100 ( V_33 ) -> V_89 ;
V_527 += V_134 * 0x100 ;
V_529 += V_134 * 0x100 ;
V_528 += V_134 * 0x100 ;
F_53 ( L_108 , F_64 ( V_134 ) ) ;
V_134 = F_3 ( V_529 ) ;
V_134 = ( V_134 >> 29 ) & 0x3 ;
if ( ! V_134 ) {
F_53 ( L_109 ) ;
V_517 = V_539 ;
V_517 |= V_539 << 4 ;
V_517 |= V_539 << 8 ;
} else {
F_53 ( L_110 , 'A' + V_134 ) ;
V_517 = V_539 << ( ( V_134 - 1 ) * 4 ) ;
}
if ( F_17 ( V_33 , V_42 ) ) {
F_53 ( L_111 ) ;
V_516 [ 5 ] |= ( 1 << 2 ) ;
F_8 ( V_528 , V_540 ) ;
} else
F_8 ( V_528 , 0 ) ;
if ( F_278 ( V_393 ,
V_530 , V_517 ,
V_529 , V_541 ,
V_527 ) )
return;
V_134 = F_3 ( V_530 ) ;
V_134 &= ~ V_517 ;
F_8 ( V_530 , V_134 ) ;
if ( ! V_516 [ 0 ] )
return;
V_134 = F_3 ( V_529 ) ;
V_134 &= ~ V_541 ;
F_8 ( V_529 , V_134 ) ;
V_518 = F_280 ( T_6 , V_516 [ 2 ] , 21 ) ;
F_53 ( L_107 , V_518 ) ;
for ( V_134 = 0 ; V_134 < V_518 ; V_134 ++ )
F_8 ( V_527 , * ( ( T_5 * ) V_516 + V_134 ) ) ;
V_134 = F_3 ( V_530 ) ;
V_134 |= V_517 ;
F_8 ( V_530 , V_134 ) ;
}
void F_282 ( struct V_355 * V_73 ,
struct V_358 * V_292 )
{
struct V_32 * V_33 = V_73 -> V_33 ;
struct V_392 * V_393 ;
struct V_1 * V_2 = V_73 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_393 = F_283 ( V_73 , V_292 ) ;
if ( ! V_393 )
return;
F_53 ( L_112 ,
V_393 -> V_74 . V_23 ,
F_284 ( V_393 ) ,
V_393 -> V_73 -> V_74 . V_23 ,
F_285 ( V_393 -> V_73 ) ) ;
V_393 -> V_516 [ 6 ] = F_286 ( V_393 , V_292 ) / 2 ;
if ( V_4 -> V_227 . V_542 )
V_4 -> V_227 . V_542 ( V_393 , V_33 ) ;
}
void F_197 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_543 = F_287 ( V_108 -> V_89 ) ;
int V_134 ;
if ( ! V_33 -> V_102 || ! V_108 -> V_177 )
return;
if ( F_20 ( V_2 ) )
V_543 = F_288 ( V_108 -> V_89 ) ;
for ( V_134 = 0 ; V_134 < 256 ; V_134 ++ ) {
F_8 ( V_543 + 4 * V_134 ,
( V_108 -> V_544 [ V_134 ] << 16 ) |
( V_108 -> V_545 [ V_134 ] << 8 ) |
V_108 -> V_546 [ V_134 ] ) ;
}
}
static void F_289 ( struct V_32 * V_33 , T_1 V_74 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
bool V_547 = V_74 != 0 ;
T_1 V_548 ;
if ( V_108 -> V_549 == V_547 )
return;
V_548 = F_3 ( V_550 ) ;
if ( V_547 ) {
F_8 ( V_551 , V_74 ) ;
V_548 &= ~ ( V_552 ) ;
V_548 |= V_553 |
V_554 |
V_555 ;
} else
V_548 &= ~ ( V_553 | V_554 ) ;
F_8 ( V_550 , V_548 ) ;
V_108 -> V_549 = V_547 ;
}
static void F_290 ( struct V_32 * V_33 , T_1 V_74 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
bool V_547 = V_74 != 0 ;
if ( V_108 -> V_549 != V_547 ) {
T_5 V_548 = F_3 ( F_291 ( V_89 ) ) ;
if ( V_74 ) {
V_548 &= ~ ( V_556 | V_557 ) ;
V_548 |= V_558 | V_559 ;
V_548 |= V_89 << 28 ;
} else {
V_548 &= ~ ( V_556 | V_559 ) ;
V_548 |= V_560 ;
}
F_8 ( F_291 ( V_89 ) , V_548 ) ;
V_108 -> V_549 = V_547 ;
}
F_8 ( F_292 ( V_89 ) , V_74 ) ;
}
static void F_293 ( struct V_32 * V_33 , T_1 V_74 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
bool V_547 = V_74 != 0 ;
if ( V_108 -> V_549 != V_547 ) {
T_5 V_548 = F_3 ( F_294 ( V_89 ) ) ;
if ( V_74 ) {
V_548 &= ~ V_556 ;
V_548 |= V_558 | V_559 ;
} else {
V_548 &= ~ ( V_556 | V_559 ) ;
V_548 |= V_560 ;
}
F_8 ( F_294 ( V_89 ) , V_548 ) ;
V_108 -> V_549 = V_547 ;
}
F_8 ( F_295 ( V_89 ) , V_74 ) ;
}
static void F_198 ( struct V_32 * V_33 ,
bool V_178 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
int V_207 = V_108 -> V_561 ;
int V_208 = V_108 -> V_562 ;
T_1 V_74 , V_563 ;
bool V_547 ;
V_563 = 0 ;
if ( V_178 && V_33 -> V_102 && V_33 -> V_206 ) {
V_74 = V_108 -> V_564 ;
if ( V_207 > ( int ) V_33 -> V_206 -> V_565 )
V_74 = 0 ;
if ( V_208 > ( int ) V_33 -> V_206 -> V_566 )
V_74 = 0 ;
} else
V_74 = 0 ;
if ( V_207 < 0 ) {
if ( V_207 + V_108 -> V_567 < 0 )
V_74 = 0 ;
V_563 |= V_568 << V_569 ;
V_207 = - V_207 ;
}
V_563 |= V_207 << V_569 ;
if ( V_208 < 0 ) {
if ( V_208 + V_108 -> V_570 < 0 )
V_74 = 0 ;
V_563 |= V_568 << V_571 ;
V_208 = - V_208 ;
}
V_563 |= V_208 << V_571 ;
V_547 = V_74 != 0 ;
if ( ! V_547 && ! V_108 -> V_549 )
return;
if ( F_147 ( V_2 ) || F_56 ( V_2 ) ) {
F_8 ( F_296 ( V_89 ) , V_563 ) ;
F_293 ( V_33 , V_74 ) ;
} else {
F_8 ( F_297 ( V_89 ) , V_563 ) ;
if ( F_298 ( V_2 ) || F_299 ( V_2 ) )
F_289 ( V_33 , V_74 ) ;
else
F_290 ( V_33 , V_74 ) ;
}
}
static int F_300 ( struct V_32 * V_33 ,
struct V_572 * V_573 ,
T_5 V_574 ,
T_5 V_565 , T_5 V_566 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
struct V_190 * V_191 ;
T_5 V_575 ;
int V_195 ;
F_37 ( L_113 ) ;
if ( ! V_574 ) {
F_37 ( L_114 ) ;
V_575 = 0 ;
V_191 = NULL ;
F_142 ( & V_2 -> V_238 ) ;
goto V_576;
}
if ( V_565 != 64 || V_566 != 64 ) {
F_7 ( L_115 ) ;
return - V_200 ;
}
V_191 = F_301 ( F_302 ( V_2 , V_573 , V_574 ) ) ;
if ( & V_191 -> V_74 == NULL )
return - V_577 ;
if ( V_191 -> V_74 . V_578 < V_565 * V_566 * 4 ) {
F_7 ( L_116 ) ;
V_195 = - V_579 ;
goto V_580;
}
F_142 ( & V_2 -> V_238 ) ;
if ( ! V_4 -> V_116 -> V_581 ) {
if ( V_191 -> V_196 ) {
F_7 ( L_117 ) ;
V_195 = - V_200 ;
goto V_582;
}
V_195 = F_123 ( V_191 , 0 , NULL ) ;
if ( V_195 ) {
F_7 ( L_118 ) ;
goto V_582;
}
V_195 = F_303 ( V_191 ) ;
if ( V_195 ) {
F_7 ( L_119 ) ;
goto V_583;
}
V_575 = V_191 -> V_222 ;
} else {
int V_584 = F_88 ( V_2 ) ? 16 * 1024 : 256 ;
V_195 = F_304 ( V_2 , V_191 ,
( V_108 -> V_89 == 0 ) ? V_585 : V_586 ,
V_584 ) ;
if ( V_195 ) {
F_7 ( L_120 ) ;
goto V_582;
}
V_575 = V_191 -> V_587 -> V_574 -> V_588 ;
}
if ( F_23 ( V_2 ) )
F_8 ( V_589 , ( V_566 << 12 ) | V_565 ) ;
V_576:
if ( V_108 -> V_590 ) {
if ( V_4 -> V_116 -> V_581 ) {
if ( V_108 -> V_590 != V_191 )
F_305 ( V_2 , V_108 -> V_590 ) ;
} else
F_126 ( V_108 -> V_590 ) ;
F_306 ( & V_108 -> V_590 -> V_74 ) ;
}
F_143 ( & V_2 -> V_238 ) ;
V_108 -> V_564 = V_575 ;
V_108 -> V_590 = V_191 ;
V_108 -> V_567 = V_565 ;
V_108 -> V_570 = V_566 ;
F_198 ( V_33 , true ) ;
return 0 ;
V_583:
F_126 ( V_191 ) ;
V_582:
F_143 ( & V_2 -> V_238 ) ;
V_580:
F_307 ( & V_191 -> V_74 ) ;
return V_195 ;
}
static int F_308 ( struct V_32 * V_33 , int V_207 , int V_208 )
{
struct V_108 * V_108 = F_100 ( V_33 ) ;
V_108 -> V_561 = V_207 ;
V_108 -> V_562 = V_208 ;
F_198 ( V_33 , true ) ;
return 0 ;
}
void F_309 ( struct V_32 * V_33 , T_4 V_591 , T_4 V_592 ,
T_4 V_593 , int V_594 )
{
struct V_108 * V_108 = F_100 ( V_33 ) ;
V_108 -> V_544 [ V_594 ] = V_591 >> 8 ;
V_108 -> V_545 [ V_594 ] = V_592 >> 8 ;
V_108 -> V_546 [ V_594 ] = V_593 >> 8 ;
}
void F_310 ( struct V_32 * V_33 , T_4 * V_591 , T_4 * V_592 ,
T_4 * V_593 , int V_594 )
{
struct V_108 * V_108 = F_100 ( V_33 ) ;
* V_591 = V_108 -> V_544 [ V_594 ] << 8 ;
* V_592 = V_108 -> V_545 [ V_594 ] << 8 ;
* V_593 = V_108 -> V_546 [ V_594 ] << 8 ;
}
static void F_311 ( struct V_32 * V_33 , T_4 * V_591 , T_4 * V_592 ,
T_4 * V_593 , T_5 V_595 , T_5 V_578 )
{
int V_596 = ( V_595 + V_578 > 256 ) ? 256 : V_595 + V_578 , V_134 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
for ( V_134 = V_595 ; V_134 < V_596 ; V_134 ++ ) {
V_108 -> V_544 [ V_134 ] = V_591 [ V_134 ] >> 8 ;
V_108 -> V_545 [ V_134 ] = V_592 [ V_134 ] >> 8 ;
V_108 -> V_546 [ V_134 ] = V_593 [ V_134 ] >> 8 ;
}
F_197 ( V_33 ) ;
}
static struct V_205 *
F_312 ( struct V_1 * V_2 ,
struct V_597 * V_598 ,
struct V_190 * V_191 )
{
struct V_209 * V_210 ;
int V_195 ;
V_210 = F_313 ( sizeof( * V_210 ) , V_599 ) ;
if ( ! V_210 ) {
F_307 ( & V_191 -> V_74 ) ;
return F_314 ( - V_579 ) ;
}
V_195 = F_315 ( V_2 , V_210 , V_598 , V_191 ) ;
if ( V_195 ) {
F_307 ( & V_191 -> V_74 ) ;
F_222 ( V_210 ) ;
return F_314 ( V_195 ) ;
}
return & V_210 -> V_74 ;
}
static T_1
F_316 ( int V_565 , int V_401 )
{
T_1 V_600 = F_317 ( V_565 * V_401 , 8 ) ;
return F_318 ( V_600 , 64 ) ;
}
static T_1
F_319 ( struct V_358 * V_292 , int V_401 )
{
T_1 V_600 = F_316 ( V_292 -> V_346 , V_401 ) ;
return F_318 ( V_600 * V_292 -> V_348 , V_601 ) ;
}
static struct V_205 *
F_320 ( struct V_1 * V_2 ,
struct V_358 * V_292 ,
int V_217 , int V_401 )
{
struct V_190 * V_191 ;
struct V_597 V_598 ;
V_191 = F_321 ( V_2 ,
F_319 ( V_292 , V_401 ) ) ;
if ( V_191 == NULL )
return F_314 ( - V_579 ) ;
V_598 . V_565 = V_292 -> V_346 ;
V_598 . V_566 = V_292 -> V_348 ;
V_598 . V_223 [ 0 ] = F_316 ( V_598 . V_565 ,
V_401 ) ;
V_598 . V_602 = F_322 ( V_401 , V_217 ) ;
return F_312 ( V_2 , & V_598 , V_191 ) ;
}
static struct V_205 *
F_323 ( struct V_1 * V_2 ,
struct V_358 * V_292 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_190 * V_191 ;
struct V_205 * V_206 ;
if ( V_4 -> V_603 == NULL )
return NULL ;
V_191 = V_4 -> V_603 -> V_604 . V_191 ;
if ( V_191 == NULL )
return NULL ;
V_206 = & V_4 -> V_603 -> V_604 . V_74 ;
if ( V_206 -> V_223 [ 0 ] < F_316 ( V_292 -> V_346 ,
V_206 -> V_215 ) )
return NULL ;
if ( V_191 -> V_74 . V_578 < V_292 -> V_348 * V_206 -> V_223 [ 0 ] )
return NULL ;
return V_206 ;
}
bool F_324 ( struct V_72 * V_72 ,
struct V_392 * V_393 ,
struct V_358 * V_292 ,
struct V_605 * V_606 )
{
struct V_108 * V_108 ;
struct V_32 * V_607 ;
struct V_355 * V_73 = & V_72 -> V_74 ;
struct V_32 * V_33 = NULL ;
struct V_1 * V_2 = V_73 -> V_2 ;
struct V_205 * V_230 ;
int V_134 = - 1 ;
F_37 ( L_121 ,
V_393 -> V_74 . V_23 , F_284 ( V_393 ) ,
V_73 -> V_74 . V_23 , F_285 ( V_73 ) ) ;
if ( V_73 -> V_33 ) {
V_33 = V_73 -> V_33 ;
V_108 = F_100 ( V_33 ) ;
V_606 -> V_343 = V_108 -> V_343 ;
V_606 -> V_608 = false ;
if ( V_108 -> V_343 != V_337 ) {
struct V_356 * V_357 ;
struct V_351 * V_352 ;
V_352 = V_33 -> V_353 ;
V_352 -> V_344 ( V_33 , V_337 ) ;
V_357 = V_73 -> V_353 ;
V_357 -> V_344 ( V_73 , V_337 ) ;
}
return true ;
}
F_26 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_134 ++ ;
if ( ! ( V_73 -> V_609 & ( 1 << V_134 ) ) )
continue;
if ( ! V_607 -> V_102 ) {
V_33 = V_607 ;
break;
}
}
if ( ! V_33 ) {
F_37 ( L_122 ) ;
return false ;
}
V_73 -> V_33 = V_33 ;
V_393 -> V_73 = V_73 ;
V_108 = F_100 ( V_33 ) ;
V_606 -> V_343 = V_108 -> V_343 ;
V_606 -> V_608 = true ;
V_606 -> V_610 = NULL ;
if ( ! V_292 )
V_292 = & V_611 ;
V_230 = V_33 -> V_206 ;
V_33 -> V_206 = F_323 ( V_2 , V_292 ) ;
if ( V_33 -> V_206 == NULL ) {
F_37 ( L_123 ) ;
V_33 -> V_206 = F_320 ( V_2 , V_292 , 24 , 32 ) ;
V_606 -> V_610 = V_33 -> V_206 ;
} else
F_37 ( L_124 ) ;
if ( F_325 ( V_33 -> V_206 ) ) {
F_37 ( L_125 ) ;
V_33 -> V_206 = V_230 ;
return false ;
}
if ( ! F_326 ( V_33 , V_292 , 0 , 0 , V_230 ) ) {
F_37 ( L_126 ) ;
if ( V_606 -> V_610 )
V_606 -> V_610 -> V_612 -> V_613 ( V_606 -> V_610 ) ;
V_33 -> V_206 = V_230 ;
return false ;
}
F_38 ( V_2 , V_108 -> V_89 ) ;
return true ;
}
void F_327 ( struct V_72 * V_72 ,
struct V_392 * V_393 ,
struct V_605 * V_606 )
{
struct V_355 * V_73 = & V_72 -> V_74 ;
struct V_1 * V_2 = V_73 -> V_2 ;
struct V_32 * V_33 = V_73 -> V_33 ;
struct V_356 * V_357 = V_73 -> V_353 ;
struct V_351 * V_352 = V_33 -> V_353 ;
F_37 ( L_121 ,
V_393 -> V_74 . V_23 , F_284 ( V_393 ) ,
V_73 -> V_74 . V_23 , F_285 ( V_73 ) ) ;
if ( V_606 -> V_608 ) {
V_393 -> V_73 = NULL ;
F_328 ( V_2 ) ;
if ( V_606 -> V_610 )
V_606 -> V_610 -> V_612 -> V_613 ( V_606 -> V_610 ) ;
return;
}
if ( V_606 -> V_343 != V_337 ) {
V_357 -> V_344 ( V_73 , V_606 -> V_343 ) ;
V_352 -> V_344 ( V_33 , V_606 -> V_343 ) ;
}
}
static int F_329 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
T_1 V_321 = F_3 ( F_49 ( V_89 ) ) ;
T_1 V_322 ;
T_3 clock ;
if ( ( V_321 & V_614 ) == 0 )
V_322 = F_3 ( F_242 ( V_89 ) ) ;
else
V_322 = F_3 ( F_243 ( V_89 ) ) ;
clock . V_69 = ( V_322 & V_615 ) >> V_616 ;
if ( F_22 ( V_2 ) ) {
clock . V_67 = F_330 ( ( V_322 & V_617 ) >> V_618 ) - 1 ;
clock . V_62 = ( V_322 & V_619 ) >> V_620 ;
} else {
clock . V_67 = ( V_322 & V_621 ) >> V_618 ;
clock . V_62 = ( V_322 & V_622 ) >> V_620 ;
}
if ( ! F_23 ( V_2 ) ) {
if ( F_22 ( V_2 ) )
clock . V_64 = F_330 ( ( V_321 & V_623 ) >>
V_426 ) ;
else
clock . V_64 = F_330 ( ( V_321 & V_624 ) >>
V_427 ) ;
switch ( V_321 & V_625 ) {
case V_422 :
clock . V_65 = V_321 & V_429 ?
5 : 10 ;
break;
case V_421 :
clock . V_65 = V_321 & V_430 ?
7 : 14 ;
break;
default:
F_37 ( L_127
L_128 , ( int ) ( V_321 & V_625 ) ) ;
return 0 ;
}
F_25 ( V_2 , 96000 , & clock ) ;
} else {
bool V_445 = ( V_89 == 1 ) && ( F_3 ( V_46 ) & V_152 ) ;
if ( V_445 ) {
clock . V_64 = F_330 ( ( V_321 & V_626 ) >>
V_427 ) ;
clock . V_65 = 14 ;
if ( ( V_321 & V_627 ) ==
V_436 ) {
F_25 ( V_2 , 66000 , & clock ) ;
} else
F_25 ( V_2 , 48000 , & clock ) ;
} else {
if ( V_321 & V_439 )
clock . V_64 = 2 ;
else {
clock . V_64 = ( ( V_321 & V_628 ) >>
V_427 ) + 2 ;
}
if ( V_321 & V_440 )
clock . V_65 = 4 ;
else
clock . V_65 = 2 ;
F_25 ( V_2 , 48000 , & clock ) ;
}
}
return clock . V_68 ;
}
struct V_358 * F_331 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
struct V_358 * V_292 ;
int V_629 = F_3 ( F_174 ( V_89 ) ) ;
int V_630 = F_3 ( F_178 ( V_89 ) ) ;
int V_631 = F_3 ( F_180 ( V_89 ) ) ;
int V_632 = F_3 ( F_184 ( V_89 ) ) ;
V_292 = F_313 ( sizeof( * V_292 ) , V_599 ) ;
if ( ! V_292 )
return NULL ;
V_292 -> clock = F_329 ( V_2 , V_33 ) ;
V_292 -> V_346 = ( V_629 & 0xffff ) + 1 ;
V_292 -> V_633 = ( ( V_629 & 0xffff0000 ) >> 16 ) + 1 ;
V_292 -> V_634 = ( V_630 & 0xffff ) + 1 ;
V_292 -> V_635 = ( ( V_630 & 0xffff0000 ) >> 16 ) + 1 ;
V_292 -> V_348 = ( V_631 & 0xffff ) + 1 ;
V_292 -> V_636 = ( ( V_631 & 0xffff0000 ) >> 16 ) + 1 ;
V_292 -> V_637 = ( V_632 & 0xffff ) + 1 ;
V_292 -> V_638 = ( ( V_632 & 0xffff0000 ) >> 16 ) + 1 ;
F_332 ( V_292 ) ;
return V_292 ;
}
static void F_333 ( unsigned long V_639 )
{
struct V_1 * V_2 = (struct V_1 * ) V_639 ;
T_7 * V_4 = V_2 -> V_5 ;
if ( ! F_334 ( & V_4 -> V_201 . V_640 ) ) {
F_335 ( & V_4 -> V_641 , V_99 +
F_44 ( V_642 ) ) ;
return;
}
V_4 -> V_643 = false ;
F_336 ( V_4 -> V_644 , & V_4 -> V_645 ) ;
}
static void F_337 ( unsigned long V_639 )
{
struct V_108 * V_108 = (struct V_108 * ) V_639 ;
struct V_32 * V_33 = & V_108 -> V_74 ;
T_7 * V_4 = V_33 -> V_2 -> V_5 ;
struct V_209 * V_210 ;
V_210 = F_130 ( V_33 -> V_206 ) ;
if ( V_210 && V_210 -> V_191 -> V_177 ) {
F_335 ( & V_108 -> V_641 , V_99 +
F_44 ( V_646 ) ) ;
return;
}
V_108 -> V_643 = false ;
F_336 ( V_4 -> V_644 , & V_4 -> V_645 ) ;
}
static void F_136 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
int V_89 = V_108 -> V_89 ;
int V_647 = F_49 ( V_89 ) ;
int V_321 ;
if ( F_20 ( V_2 ) )
return;
if ( ! V_4 -> V_450 )
return;
V_321 = F_3 ( V_647 ) ;
if ( ! F_255 ( V_2 ) && ( V_321 & V_614 ) ) {
F_53 ( L_129 ) ;
F_63 ( V_4 , V_89 ) ;
V_321 &= ~ V_614 ;
F_8 ( V_647 , V_321 ) ;
F_38 ( V_2 , V_89 ) ;
V_321 = F_3 ( V_647 ) ;
if ( V_321 & V_614 )
F_53 ( L_130 ) ;
}
F_335 ( & V_108 -> V_641 , V_99 +
F_44 ( V_646 ) ) ;
}
static void F_338 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
if ( F_20 ( V_2 ) )
return;
if ( ! V_4 -> V_450 )
return;
if ( ! F_255 ( V_2 ) && V_108 -> V_408 ) {
int V_89 = V_108 -> V_89 ;
int V_647 = F_49 ( V_89 ) ;
int V_321 ;
F_53 ( L_131 ) ;
F_63 ( V_4 , V_89 ) ;
V_321 = F_3 ( V_647 ) ;
V_321 |= V_614 ;
F_8 ( V_647 , V_321 ) ;
F_38 ( V_2 , V_89 ) ;
V_321 = F_3 ( V_647 ) ;
if ( ! ( V_321 & V_614 ) )
F_53 ( L_132 ) ;
}
}
static void F_339 ( struct V_648 * V_649 )
{
T_7 * V_4 = F_340 ( V_649 , T_7 ,
V_645 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_32 * V_33 ;
struct V_108 * V_108 ;
if ( ! V_409 )
return;
F_142 ( & V_2 -> V_238 ) ;
F_341 ( V_4 ) ;
F_26 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_33 -> V_206 )
continue;
V_108 = F_100 ( V_33 ) ;
if ( ! V_108 -> V_643 )
F_338 ( V_33 ) ;
}
F_143 ( & V_2 -> V_238 ) ;
}
void F_342 ( struct V_1 * V_2 , struct V_190 * V_191 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_32 * V_33 = NULL ;
struct V_209 * V_210 ;
struct V_108 * V_108 ;
if ( ! F_343 ( V_2 , V_650 ) )
return;
if ( ! V_4 -> V_643 ) {
F_344 ( V_2 ) ;
V_4 -> V_643 = true ;
} else
F_335 ( & V_4 -> V_641 , V_99 +
F_44 ( V_642 ) ) ;
if ( V_191 == NULL )
return;
F_26 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_33 -> V_206 )
continue;
V_108 = F_100 ( V_33 ) ;
V_210 = F_130 ( V_33 -> V_206 ) ;
if ( V_210 -> V_191 == V_191 ) {
if ( ! V_108 -> V_643 ) {
F_136 ( V_33 ) ;
V_108 -> V_643 = true ;
} else {
F_335 ( & V_108 -> V_641 , V_99 +
F_44 ( V_646 ) ) ;
}
}
}
}
static void F_345 ( struct V_32 * V_33 )
{
struct V_108 * V_108 = F_100 ( V_33 ) ;
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_651 * V_649 ;
unsigned long V_9 ;
F_5 ( & V_2 -> V_652 , V_9 ) ;
V_649 = V_108 -> V_653 ;
V_108 -> V_653 = NULL ;
F_9 ( & V_2 -> V_652 , V_9 ) ;
if ( V_649 ) {
F_346 ( & V_649 -> V_649 ) ;
F_222 ( V_649 ) ;
}
F_347 ( V_33 ) ;
F_222 ( V_108 ) ;
}
static void F_348 ( struct V_648 * V_654 )
{
struct V_651 * V_649 =
F_340 ( V_654 , struct V_651 , V_649 ) ;
F_142 ( & V_649 -> V_2 -> V_238 ) ;
F_127 ( V_649 -> V_655 ) ;
F_306 ( & V_649 -> V_656 -> V_74 ) ;
F_306 ( & V_649 -> V_655 -> V_74 ) ;
F_144 ( V_649 -> V_2 ) ;
F_143 ( & V_649 -> V_2 -> V_238 ) ;
F_222 ( V_649 ) ;
}
static void F_349 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
struct V_651 * V_649 ;
struct V_190 * V_191 ;
struct V_657 * V_658 ;
struct V_659 V_660 , V_661 ;
unsigned long V_9 ;
if ( V_108 == NULL )
return;
F_350 ( & V_660 ) ;
F_5 ( & V_2 -> V_652 , V_9 ) ;
V_649 = V_108 -> V_653 ;
if ( V_649 == NULL || ! V_649 -> V_662 ) {
F_9 ( & V_2 -> V_652 , V_9 ) ;
return;
}
V_108 -> V_653 = NULL ;
if ( V_649 -> V_663 ) {
V_658 = V_649 -> V_663 ;
V_658 -> V_663 . V_664 = F_351 ( V_2 , V_108 -> V_89 , & V_661 ) ;
if ( 10 * ( F_352 ( & V_660 ) - F_352 ( & V_661 ) ) >
9 * V_33 -> V_665 ) {
V_658 -> V_663 . V_664 ++ ;
V_661 = F_353 ( F_352 ( & V_661 ) +
V_33 -> V_665 ) ;
}
V_658 -> V_663 . V_666 = V_661 . V_666 ;
V_658 -> V_663 . V_667 = V_661 . V_667 ;
F_354 ( & V_658 -> V_74 . V_668 ,
& V_658 -> V_74 . V_669 -> V_670 ) ;
F_355 ( & V_658 -> V_74 . V_669 -> V_671 ) ;
}
F_356 ( V_2 , V_108 -> V_89 ) ;
F_9 ( & V_2 -> V_652 , V_9 ) ;
V_191 = V_649 -> V_655 ;
F_357 ( 1 << V_108 -> V_132 ,
& V_191 -> V_234 . V_672 ) ;
if ( F_139 ( & V_191 -> V_234 ) == 0 )
F_358 ( & V_4 -> V_232 ) ;
F_359 ( & V_649 -> V_649 ) ;
F_360 ( V_108 -> V_132 , V_649 -> V_656 ) ;
}
void F_361 ( struct V_1 * V_2 , int V_89 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_32 * V_33 = V_4 -> V_180 [ V_89 ] ;
F_349 ( V_2 , V_33 ) ;
}
void F_362 ( struct V_1 * V_2 , int V_132 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_32 * V_33 = V_4 -> V_673 [ V_132 ] ;
F_349 ( V_2 , V_33 ) ;
}
void F_363 ( struct V_1 * V_2 , int V_132 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 =
F_100 ( V_4 -> V_673 [ V_132 ] ) ;
unsigned long V_9 ;
F_5 ( & V_2 -> V_652 , V_9 ) ;
if ( V_108 -> V_653 ) {
if ( ( ++ V_108 -> V_653 -> V_662 ) > 1 )
F_7 ( L_133 ) ;
} else {
F_53 ( L_134 ) ;
}
F_9 ( & V_2 -> V_652 , V_9 ) ;
}
static int F_364 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_205 * V_206 ,
struct V_190 * V_191 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
unsigned long V_674 ;
T_1 V_675 ;
struct V_192 * V_676 = & V_4 -> V_676 [ V_677 ] ;
int V_195 ;
V_195 = F_119 ( V_2 , V_191 , V_676 ) ;
if ( V_195 )
goto V_80;
V_674 = V_33 -> V_208 * V_206 -> V_223 [ 0 ] + V_33 -> V_207 * V_206 -> V_215 / 8 ;
V_195 = F_365 ( V_676 , 6 ) ;
if ( V_195 )
goto V_204;
if ( V_108 -> V_132 )
V_675 = V_678 ;
else
V_675 = V_679 ;
F_366 ( V_676 , V_680 | V_675 ) ;
F_366 ( V_676 , V_681 ) ;
F_366 ( V_676 , V_682 |
F_367 ( V_108 -> V_132 ) ) ;
F_366 ( V_676 , V_206 -> V_223 [ 0 ] ) ;
F_366 ( V_676 , V_191 -> V_222 + V_674 ) ;
F_366 ( V_676 , 0 ) ;
F_368 ( V_676 ) ;
return 0 ;
V_204:
F_127 ( V_191 ) ;
V_80:
return V_195 ;
}
static int F_369 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_205 * V_206 ,
struct V_190 * V_191 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
unsigned long V_674 ;
T_1 V_675 ;
struct V_192 * V_676 = & V_4 -> V_676 [ V_677 ] ;
int V_195 ;
V_195 = F_119 ( V_2 , V_191 , V_676 ) ;
if ( V_195 )
goto V_80;
V_674 = V_33 -> V_208 * V_206 -> V_223 [ 0 ] + V_33 -> V_207 * V_206 -> V_215 / 8 ;
V_195 = F_365 ( V_676 , 6 ) ;
if ( V_195 )
goto V_204;
if ( V_108 -> V_132 )
V_675 = V_678 ;
else
V_675 = V_679 ;
F_366 ( V_676 , V_680 | V_675 ) ;
F_366 ( V_676 , V_681 ) ;
F_366 ( V_676 , V_683 |
F_367 ( V_108 -> V_132 ) ) ;
F_366 ( V_676 , V_206 -> V_223 [ 0 ] ) ;
F_366 ( V_676 , V_191 -> V_222 + V_674 ) ;
F_366 ( V_676 , V_681 ) ;
F_368 ( V_676 ) ;
return 0 ;
V_204:
F_127 ( V_191 ) ;
V_80:
return V_195 ;
}
static int F_370 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_205 * V_206 ,
struct V_190 * V_191 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
T_5 V_684 , V_685 ;
struct V_192 * V_676 = & V_4 -> V_676 [ V_677 ] ;
int V_195 ;
V_195 = F_119 ( V_2 , V_191 , V_676 ) ;
if ( V_195 )
goto V_80;
V_195 = F_365 ( V_676 , 4 ) ;
if ( V_195 )
goto V_204;
F_366 ( V_676 , V_682 |
F_367 ( V_108 -> V_132 ) ) ;
F_366 ( V_676 , V_206 -> V_223 [ 0 ] ) ;
F_366 ( V_676 , V_191 -> V_222 | V_191 -> V_196 ) ;
V_684 = 0 ;
V_685 = F_3 ( F_259 ( V_108 -> V_89 ) ) & 0x0fff0fff ;
F_366 ( V_676 , V_684 | V_685 ) ;
F_368 ( V_676 ) ;
return 0 ;
V_204:
F_127 ( V_191 ) ;
V_80:
return V_195 ;
}
static int F_371 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_205 * V_206 ,
struct V_190 * V_191 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
struct V_192 * V_676 = & V_4 -> V_676 [ V_677 ] ;
T_5 V_684 , V_685 ;
int V_195 ;
V_195 = F_119 ( V_2 , V_191 , V_676 ) ;
if ( V_195 )
goto V_80;
V_195 = F_365 ( V_676 , 4 ) ;
if ( V_195 )
goto V_204;
F_366 ( V_676 , V_682 |
F_367 ( V_108 -> V_132 ) ) ;
F_366 ( V_676 , V_206 -> V_223 [ 0 ] | V_191 -> V_196 ) ;
F_366 ( V_676 , V_191 -> V_222 ) ;
V_684 = 0 ;
V_685 = F_3 ( F_259 ( V_108 -> V_89 ) ) & 0x0fff0fff ;
F_366 ( V_676 , V_684 | V_685 ) ;
F_368 ( V_676 ) ;
return 0 ;
V_204:
F_127 ( V_191 ) ;
V_80:
return V_195 ;
}
static int F_372 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_205 * V_206 ,
struct V_190 * V_191 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
struct V_192 * V_676 = & V_4 -> V_676 [ V_686 ] ;
T_5 V_687 = 0 ;
int V_195 ;
V_195 = F_119 ( V_2 , V_191 , V_676 ) ;
if ( V_195 )
goto V_80;
switch( V_108 -> V_132 ) {
case V_688 :
V_687 = V_689 ;
break;
case V_690 :
V_687 = V_691 ;
break;
case V_692 :
V_687 = V_693 ;
break;
default:
F_373 ( 1 , L_135 ) ;
V_195 = - V_694 ;
goto V_80;
}
V_195 = F_365 ( V_676 , 4 ) ;
if ( V_195 )
goto V_204;
F_366 ( V_676 , V_683 | V_687 ) ;
F_366 ( V_676 , ( V_206 -> V_223 [ 0 ] | V_191 -> V_196 ) ) ;
F_366 ( V_676 , ( V_191 -> V_222 ) ) ;
F_366 ( V_676 , ( V_681 ) ) ;
F_368 ( V_676 ) ;
return 0 ;
V_204:
F_127 ( V_191 ) ;
V_80:
return V_195 ;
}
static int F_374 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_205 * V_206 ,
struct V_190 * V_191 )
{
return - V_694 ;
}
static int F_375 ( struct V_32 * V_33 ,
struct V_205 * V_206 ,
struct V_657 * V_663 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_209 * V_210 ;
struct V_190 * V_191 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
struct V_651 * V_649 ;
unsigned long V_9 ;
int V_195 ;
V_649 = F_313 ( sizeof *V_649 , V_599 ) ;
if ( V_649 == NULL )
return - V_579 ;
V_649 -> V_663 = V_663 ;
V_649 -> V_2 = V_33 -> V_2 ;
V_210 = F_130 ( V_33 -> V_206 ) ;
V_649 -> V_655 = V_210 -> V_191 ;
F_376 ( & V_649 -> V_649 , F_348 ) ;
V_195 = F_377 ( V_2 , V_108 -> V_89 ) ;
if ( V_195 )
goto V_695;
F_5 ( & V_2 -> V_652 , V_9 ) ;
if ( V_108 -> V_653 ) {
F_9 ( & V_2 -> V_652 , V_9 ) ;
F_222 ( V_649 ) ;
F_356 ( V_2 , V_108 -> V_89 ) ;
F_53 ( L_136 ) ;
return - V_696 ;
}
V_108 -> V_653 = V_649 ;
F_9 ( & V_2 -> V_652 , V_9 ) ;
V_210 = F_130 ( V_206 ) ;
V_191 = V_210 -> V_191 ;
F_142 ( & V_2 -> V_238 ) ;
F_378 ( & V_649 -> V_655 -> V_74 ) ;
F_378 ( & V_191 -> V_74 ) ;
V_33 -> V_206 = V_206 ;
V_649 -> V_656 = V_191 ;
V_649 -> V_697 = true ;
F_379 ( 1 << V_108 -> V_132 , & V_649 -> V_655 -> V_234 ) ;
V_195 = V_4 -> V_227 . V_698 ( V_2 , V_33 , V_206 , V_191 ) ;
if ( V_195 )
goto V_699;
F_201 ( V_2 ) ;
F_342 ( V_2 , V_191 ) ;
F_143 ( & V_2 -> V_238 ) ;
F_380 ( V_108 -> V_132 , V_191 ) ;
return 0 ;
V_699:
F_381 ( 1 << V_108 -> V_132 , & V_649 -> V_655 -> V_234 ) ;
F_306 ( & V_649 -> V_655 -> V_74 ) ;
F_306 ( & V_191 -> V_74 ) ;
F_143 ( & V_2 -> V_238 ) ;
F_5 ( & V_2 -> V_652 , V_9 ) ;
V_108 -> V_653 = NULL ;
F_9 ( & V_2 -> V_652 , V_9 ) ;
F_356 ( V_2 , V_108 -> V_89 ) ;
V_695:
F_222 ( V_649 ) ;
return V_195 ;
}
static void F_382 ( struct V_1 * V_2 ,
int V_89 , int V_132 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_8 , V_10 ;
int V_134 ;
F_383 (i) {
V_8 = F_42 ( V_134 ) ;
F_8 ( V_8 , F_3 ( V_8 ) & ~ V_700 ) ;
}
if ( F_20 ( V_2 ) )
return;
V_8 = F_67 ( V_132 ) ;
V_10 = F_3 ( V_8 ) ;
if ( ( V_10 & V_133 ) == 0 )
return;
if ( ! ! ( V_10 & V_136 ) == V_89 )
return;
V_89 = ! V_89 ;
F_115 ( V_4 , V_132 , V_89 ) ;
F_109 ( V_4 , V_89 ) ;
}
static void F_384 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_108 * V_108 = F_100 ( V_33 ) ;
V_108 -> V_343 = - 1 ;
F_382 ( V_2 , V_108 -> V_89 , V_108 -> V_132 ) ;
}
static void F_385 ( struct V_1 * V_2 )
{
T_7 * V_4 = V_2 -> V_5 ;
int V_134 ;
if ( V_4 -> V_325 == 0 ) {
F_37 ( L_137 ) ;
return;
}
for ( V_134 = 0 ; V_134 < V_4 -> V_325 ; V_134 ++ ) {
V_4 -> V_324 [ V_134 ] . V_109 = F_386 ( V_134 ) ;
V_4 -> V_324 [ V_134 ] . V_326 = F_387 ( V_134 ) ;
V_4 -> V_324 [ V_134 ] . V_509 = F_388 ( V_134 ) ;
}
}
static void F_389 ( struct V_1 * V_2 , int V_89 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_108 * V_108 ;
int V_134 ;
V_108 = F_313 ( sizeof( struct V_108 ) + ( V_701 * sizeof( struct V_392 * ) ) , V_599 ) ;
if ( V_108 == NULL )
return;
F_390 ( V_2 , & V_108 -> V_74 , & V_702 ) ;
F_391 ( & V_108 -> V_74 , 256 ) ;
for ( V_134 = 0 ; V_134 < 256 ; V_134 ++ ) {
V_108 -> V_544 [ V_134 ] = V_134 ;
V_108 -> V_545 [ V_134 ] = V_134 ;
V_108 -> V_546 [ V_134 ] = V_134 ;
}
V_108 -> V_89 = V_89 ;
V_108 -> V_132 = V_89 ;
if ( F_87 ( V_2 ) && F_256 ( V_2 ) ) {
F_37 ( L_138 ) ;
V_108 -> V_132 = ! V_89 ;
}
F_86 ( V_89 >= F_392 ( V_4 -> V_673 ) ||
V_4 -> V_673 [ V_108 -> V_132 ] != NULL ) ;
V_4 -> V_673 [ V_108 -> V_132 ] = & V_108 -> V_74 ;
V_4 -> V_180 [ V_108 -> V_89 ] = & V_108 -> V_74 ;
F_384 ( & V_108 -> V_74 ) ;
V_108 -> V_177 = true ;
V_108 -> V_401 = 24 ;
if ( F_20 ( V_2 ) ) {
V_703 . V_323 = F_215 ;
V_703 . V_704 = F_216 ;
} else {
V_703 . V_323 = F_213 ;
V_703 . V_704 = F_214 ;
}
F_393 ( & V_108 -> V_74 , & V_703 ) ;
V_108 -> V_643 = false ;
F_394 ( & V_108 -> V_641 , F_337 ,
( unsigned long ) V_108 ) ;
}
int F_395 ( struct V_1 * V_2 , void * V_705 ,
struct V_572 * V_573 )
{
struct V_706 * V_707 = V_705 ;
struct V_708 * V_709 ;
struct V_108 * V_33 ;
if ( ! F_343 ( V_2 , V_650 ) )
return - V_694 ;
V_709 = F_396 ( V_2 , V_707 -> V_710 ,
V_711 ) ;
if ( ! V_709 ) {
F_7 ( L_139 ) ;
return - V_200 ;
}
V_33 = F_100 ( F_397 ( V_709 ) ) ;
V_707 -> V_89 = V_33 -> V_89 ;
return 0 ;
}
static int F_398 ( struct V_1 * V_2 , int V_712 )
{
struct V_72 * V_73 ;
int V_713 = 0 ;
int V_714 = 0 ;
F_26 (encoder, &dev->mode_config.encoder_list, base.head) {
if ( V_712 & V_73 -> V_715 )
V_713 |= ( 1 << V_714 ) ;
V_714 ++ ;
}
return V_713 ;
}
static bool F_399 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_87 ( V_2 ) )
return false ;
if ( ( F_3 ( V_248 ) & V_716 ) == 0 )
return false ;
if ( F_2 ( V_2 ) &&
( F_3 ( V_717 ) & V_718 ) )
return false ;
return true ;
}
static void F_400 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_72 * V_73 ;
bool V_719 = false ;
bool V_476 ;
V_476 = F_401 ( V_2 ) ;
if ( ! V_476 && ! F_20 ( V_2 ) ) {
F_8 ( V_720 , 0 ) ;
}
if ( F_20 ( V_2 ) ) {
V_719 = F_402 ( V_2 ) ;
if ( F_399 ( V_2 ) )
F_403 ( V_2 , V_248 ) ;
if ( V_719 && ( F_3 ( V_160 ) & V_716 ) )
F_403 ( V_2 , V_160 ) ;
}
F_404 ( V_2 ) ;
if ( F_56 ( V_2 ) ) {
int V_86 ;
V_86 = F_3 ( V_721 ) & V_722 ;
if ( V_86 )
F_405 ( V_2 , V_723 ) ;
V_86 = F_3 ( V_724 ) ;
if ( V_86 & V_725 )
F_405 ( V_2 , V_726 ) ;
if ( V_86 & V_727 )
F_405 ( V_2 , V_728 ) ;
if ( V_86 & V_729 )
F_405 ( V_2 , V_730 ) ;
} else if ( F_20 ( V_2 ) ) {
int V_86 ;
if ( F_3 ( V_163 ) & V_731 ) {
V_86 = F_406 ( V_2 , V_732 , true ) ;
if ( ! V_86 )
F_407 ( V_2 , V_163 ) ;
if ( ! V_86 && ( F_3 ( V_156 ) & V_716 ) )
F_403 ( V_2 , V_156 ) ;
}
if ( F_3 ( V_164 ) & V_731 )
F_407 ( V_2 , V_164 ) ;
if ( ! V_719 && F_3 ( V_165 ) & V_731 )
F_407 ( V_2 , V_165 ) ;
if ( F_3 ( V_158 ) & V_716 )
F_403 ( V_2 , V_158 ) ;
if ( ! V_719 && ( F_3 ( V_160 ) & V_716 ) )
F_403 ( V_2 , V_160 ) ;
} else if ( F_408 ( V_2 ) ) {
bool V_86 = false ;
if ( F_3 ( V_733 ) & V_734 ) {
F_37 ( L_140 ) ;
V_86 = F_406 ( V_2 , V_733 , true ) ;
if ( ! V_86 && F_409 ( V_2 ) ) {
F_37 ( L_141 ) ;
F_407 ( V_2 , V_733 ) ;
}
if ( ! V_86 && F_410 ( V_2 ) ) {
F_37 ( L_142 ) ;
F_403 ( V_2 , V_735 ) ;
}
}
if ( F_3 ( V_733 ) & V_734 ) {
F_37 ( L_143 ) ;
V_86 = F_406 ( V_2 , V_736 , false ) ;
}
if ( ! V_86 && ( F_3 ( V_736 ) & V_734 ) ) {
if ( F_409 ( V_2 ) ) {
F_37 ( L_144 ) ;
F_407 ( V_2 , V_736 ) ;
}
if ( F_410 ( V_2 ) ) {
F_37 ( L_145 ) ;
F_403 ( V_2 , V_737 ) ;
}
}
if ( F_410 ( V_2 ) &&
( F_3 ( V_738 ) & V_716 ) ) {
F_37 ( L_146 ) ;
F_403 ( V_2 , V_738 ) ;
}
} else if ( F_23 ( V_2 ) )
F_411 ( V_2 ) ;
if ( F_412 ( V_2 ) )
F_413 ( V_2 ) ;
F_26 (encoder, &dev->mode_config.encoder_list, base.head) {
V_73 -> V_74 . V_609 = V_73 -> V_739 ;
V_73 -> V_74 . V_740 =
F_398 ( V_2 , V_73 -> V_715 ) ;
}
F_328 ( V_2 ) ;
if ( F_20 ( V_2 ) )
F_260 ( V_2 ) ;
}
static void F_414 ( struct V_205 * V_206 )
{
struct V_209 * V_210 = F_130 ( V_206 ) ;
F_415 ( V_206 ) ;
F_307 ( & V_210 -> V_191 -> V_74 ) ;
F_222 ( V_210 ) ;
}
static int F_416 ( struct V_205 * V_206 ,
struct V_572 * V_573 ,
unsigned int * V_574 )
{
struct V_209 * V_210 = F_130 ( V_206 ) ;
struct V_190 * V_191 = V_210 -> V_191 ;
return F_417 ( V_573 , & V_191 -> V_74 , V_574 ) ;
}
int F_315 ( struct V_1 * V_2 ,
struct V_209 * V_210 ,
struct V_597 * V_598 ,
struct V_190 * V_191 )
{
int V_195 ;
if ( V_191 -> V_196 == V_199 )
return - V_200 ;
if ( V_598 -> V_223 [ 0 ] & 63 )
return - V_200 ;
switch ( V_598 -> V_602 ) {
case V_741 :
case V_742 :
case V_743 :
case V_744 :
case V_745 :
case V_746 :
case V_747 :
break;
case V_748 :
case V_749 :
case V_750 :
case V_751 :
break;
default:
F_37 ( L_147 ,
V_598 -> V_602 ) ;
return - V_200 ;
}
V_195 = F_418 ( V_2 , & V_210 -> V_74 , & V_752 ) ;
if ( V_195 ) {
F_7 ( L_148 , V_195 ) ;
return V_195 ;
}
F_419 ( & V_210 -> V_74 , V_598 ) ;
V_210 -> V_191 = V_191 ;
return 0 ;
}
static struct V_205 *
F_420 ( struct V_1 * V_2 ,
struct V_572 * V_753 ,
struct V_597 * V_598 )
{
struct V_190 * V_191 ;
V_191 = F_301 ( F_302 ( V_2 , V_753 ,
V_598 -> V_754 [ 0 ] ) ) ;
if ( & V_191 -> V_74 == NULL )
return F_314 ( - V_577 ) ;
return F_312 ( V_2 , V_598 , V_191 ) ;
}
static void F_421 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_20 ( V_2 ) ) {
V_4 -> V_227 . V_344 = F_202 ;
V_4 -> V_227 . V_510 = F_262 ;
V_4 -> V_227 . V_354 = F_203 ;
V_4 -> V_227 . V_229 = F_134 ;
} else {
V_4 -> V_227 . V_344 = F_208 ;
V_4 -> V_227 . V_510 = F_253 ;
V_4 -> V_227 . V_354 = F_209 ;
V_4 -> V_227 . V_229 = F_129 ;
}
if ( F_422 ( V_2 ) )
V_4 -> V_227 . V_454 =
F_225 ;
else if ( F_247 ( V_2 ) || ( F_249 ( V_2 ) && ! F_423 ( V_2 ) ) )
V_4 -> V_227 . V_454 =
F_226 ;
else if ( F_424 ( V_2 ) )
V_4 -> V_227 . V_454 =
F_227 ;
else if ( F_248 ( V_2 ) || F_298 ( V_2 ) || F_423 ( V_2 ) )
V_4 -> V_227 . V_454 =
F_228 ;
else if ( F_425 ( V_2 ) )
V_4 -> V_227 . V_454 =
F_229 ;
else if ( F_299 ( V_2 ) )
V_4 -> V_227 . V_454 =
F_231 ;
else if ( F_426 ( V_2 ) )
V_4 -> V_227 . V_454 =
F_232 ;
else
V_4 -> V_227 . V_454 =
F_233 ;
if ( F_20 ( V_2 ) ) {
if ( F_2 ( V_2 ) ) {
V_4 -> V_227 . V_304 = F_151 ;
V_4 -> V_227 . V_542 = F_281 ;
} else if ( F_157 ( V_2 ) ) {
V_4 -> V_227 . V_304 = F_156 ;
V_4 -> V_227 . V_542 = F_281 ;
} else if ( F_147 ( V_2 ) ) {
V_4 -> V_227 . V_304 = F_158 ;
V_4 -> V_227 . V_542 = F_281 ;
} else if ( F_56 ( V_2 ) ) {
V_4 -> V_227 . V_304 = V_755 ;
V_4 -> V_227 . V_542 = F_281 ;
} else
V_4 -> V_227 . V_756 = NULL ;
} else if ( F_422 ( V_2 ) ) {
V_4 -> V_227 . V_757 = V_758 ;
V_4 -> V_227 . V_759 = V_760 ;
} else if ( F_21 ( V_2 ) ) {
V_4 -> V_227 . V_542 = F_279 ;
}
V_4 -> V_227 . V_698 = F_374 ;
switch ( F_40 ( V_2 ) -> V_93 ) {
case 2 :
V_4 -> V_227 . V_698 = F_364 ;
break;
case 3 :
V_4 -> V_227 . V_698 = F_369 ;
break;
case 4 :
case 5 :
V_4 -> V_227 . V_698 = F_370 ;
break;
case 6 :
V_4 -> V_227 . V_698 = F_371 ;
break;
case 7 :
V_4 -> V_227 . V_698 = F_372 ;
break;
}
}
static void F_427 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_129 |= V_130 ;
F_13 ( L_149 ) ;
}
static void F_428 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_129 |= V_390 ;
F_13 ( L_150 ) ;
}
static void F_429 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_129 |= V_761 ;
F_13 ( L_151 ) ;
}
static void F_430 ( struct V_1 * V_2 )
{
struct V_762 * V_763 = V_2 -> V_364 ;
int V_134 ;
for ( V_134 = 0 ; V_134 < F_392 ( V_764 ) ; V_134 ++ ) {
struct V_765 * V_766 = & V_764 [ V_134 ] ;
if ( V_763 -> V_767 == V_766 -> V_767 &&
( V_763 -> V_768 == V_766 -> V_768 ||
V_766 -> V_768 == V_769 ) &&
( V_763 -> V_770 == V_766 -> V_770 ||
V_766 -> V_770 == V_769 ) )
V_766 -> V_771 ( V_2 ) ;
}
}
static void F_431 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_8 V_772 ;
T_1 V_773 ;
if ( F_20 ( V_2 ) )
V_773 = V_774 ;
else
V_773 = V_775 ;
F_432 ( V_2 -> V_364 , V_776 ) ;
F_433 ( V_777 , V_778 ) ;
V_772 = F_434 ( V_779 ) ;
F_433 ( V_772 | 1 << 5 , V_779 ) ;
F_435 ( V_2 -> V_364 , V_776 ) ;
F_89 ( 300 ) ;
F_8 ( V_773 , V_780 ) ;
F_11 ( V_773 ) ;
}
void F_436 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_437 ( V_2 ) ;
if ( F_438 ( V_2 ) ) {
F_439 ( V_2 ) ;
F_440 ( V_2 ) ;
F_441 ( V_2 ) ;
}
if ( ( F_157 ( V_2 ) || F_442 ( V_2 ) ) && ! F_422 ( V_2 ) ) {
F_443 ( V_4 ) ;
F_444 ( V_4 ) ;
}
}
void F_445 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_134 , V_195 ;
F_446 ( V_2 ) ;
V_2 -> V_71 . V_781 = 0 ;
V_2 -> V_71 . V_782 = 0 ;
V_2 -> V_71 . V_783 = 24 ;
V_2 -> V_71 . V_784 = 1 ;
V_2 -> V_71 . V_612 = & V_785 ;
F_430 ( V_2 ) ;
F_447 ( V_2 ) ;
F_448 ( V_2 ) ;
F_421 ( V_2 ) ;
if ( F_23 ( V_2 ) ) {
V_2 -> V_71 . V_786 = 2048 ;
V_2 -> V_71 . V_787 = 2048 ;
} else if ( F_256 ( V_2 ) ) {
V_2 -> V_71 . V_786 = 4096 ;
V_2 -> V_71 . V_787 = 4096 ;
} else {
V_2 -> V_71 . V_786 = 8192 ;
V_2 -> V_71 . V_787 = 8192 ;
}
V_2 -> V_71 . V_788 = V_2 -> V_789 -> V_74 ;
F_37 ( L_152 ,
V_4 -> V_237 , V_4 -> V_237 > 1 ? L_153 : L_154 ) ;
for ( V_134 = 0 ; V_134 < V_4 -> V_237 ; V_134 ++ ) {
F_389 ( V_2 , V_134 ) ;
V_195 = F_449 ( V_2 , V_134 ) ;
if ( V_195 )
F_37 ( L_155 , V_134 , V_195 ) ;
}
F_385 ( V_2 ) ;
F_431 ( V_2 ) ;
F_400 ( V_2 ) ;
F_376 ( & V_4 -> V_645 , F_339 ) ;
F_394 ( & V_4 -> V_641 , F_333 ,
( unsigned long ) V_2 ) ;
}
void F_450 ( struct V_1 * V_2 )
{
F_436 ( V_2 ) ;
F_451 ( V_2 ) ;
}
void F_452 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_32 * V_33 ;
struct V_108 * V_108 ;
F_453 ( V_2 ) ;
F_142 ( & V_2 -> V_238 ) ;
F_454 () ;
F_26 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_33 -> V_206 )
continue;
V_108 = F_100 ( V_33 ) ;
F_136 ( V_33 ) ;
}
F_201 ( V_2 ) ;
if ( F_438 ( V_2 ) )
F_455 ( V_2 ) ;
if ( ( F_157 ( V_2 ) || F_442 ( V_2 ) ) && ! F_422 ( V_2 ) )
F_456 ( V_2 ) ;
if ( F_438 ( V_2 ) )
F_457 ( V_2 ) ;
if ( F_422 ( V_2 ) )
F_10 ( V_2 ) ;
F_143 ( & V_2 -> V_238 ) ;
F_458 ( V_2 ) ;
F_346 ( & V_4 -> V_790 ) ;
F_346 ( & V_4 -> V_791 ) ;
F_459 () ;
F_26 (crtc, &dev->mode_config.crtc_list, head) {
V_108 = F_100 ( V_33 ) ;
F_460 ( & V_108 -> V_641 ) ;
}
F_460 ( & V_4 -> V_641 ) ;
F_346 ( & V_4 -> V_645 ) ;
F_461 ( V_2 ) ;
}
struct V_355 * F_462 ( struct V_392 * V_393 )
{
return & F_463 ( V_393 ) -> V_74 ;
}
void F_464 ( struct V_792 * V_393 ,
struct V_72 * V_73 )
{
V_393 -> V_73 = V_73 ;
F_465 ( & V_393 -> V_74 ,
& V_73 -> V_74 ) ;
}
int F_466 ( struct V_1 * V_2 , bool V_103 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_793 ;
F_230 ( V_4 -> V_794 , V_795 , & V_793 ) ;
if ( V_103 )
V_793 &= ~ V_796 ;
else
V_793 |= V_796 ;
F_467 ( V_4 -> V_794 , V_795 , V_793 ) ;
return 0 ;
}
struct V_797 *
F_468 ( struct V_1 * V_2 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_797 * error ;
int V_134 ;
error = F_469 ( sizeof( * error ) , V_798 ) ;
if ( error == NULL )
return NULL ;
for ( V_134 = 0 ; V_134 < 2 ; V_134 ++ ) {
error -> V_799 [ V_134 ] . V_800 = F_3 ( F_291 ( V_134 ) ) ;
error -> V_799 [ V_134 ] . V_801 = F_3 ( F_297 ( V_134 ) ) ;
error -> V_799 [ V_134 ] . V_74 = F_3 ( F_292 ( V_134 ) ) ;
error -> V_132 [ V_134 ] . V_800 = F_3 ( F_67 ( V_134 ) ) ;
error -> V_132 [ V_134 ] . V_802 = F_3 ( F_131 ( V_134 ) ) ;
error -> V_132 [ V_134 ] . V_578 = F_3 ( F_257 ( V_134 ) ) ;
error -> V_132 [ V_134 ] . V_563 = F_3 ( F_258 ( V_134 ) ) ;
error -> V_132 [ V_134 ] . V_575 = F_3 ( F_111 ( V_134 ) ) ;
if ( F_40 ( V_2 ) -> V_93 >= 4 ) {
error -> V_132 [ V_134 ] . V_803 = F_3 ( F_112 ( V_134 ) ) ;
error -> V_132 [ V_134 ] . V_804 = F_3 ( F_133 ( V_134 ) ) ;
}
error -> V_89 [ V_134 ] . V_805 = F_3 ( F_42 ( V_134 ) ) ;
error -> V_89 [ V_134 ] . V_806 = F_3 ( F_259 ( V_134 ) ) ;
error -> V_89 [ V_134 ] . V_633 = F_3 ( F_174 ( V_134 ) ) ;
error -> V_89 [ V_134 ] . V_807 = F_3 ( F_176 ( V_134 ) ) ;
error -> V_89 [ V_134 ] . V_630 = F_3 ( F_178 ( V_134 ) ) ;
error -> V_89 [ V_134 ] . V_636 = F_3 ( F_180 ( V_134 ) ) ;
error -> V_89 [ V_134 ] . V_808 = F_3 ( F_182 ( V_134 ) ) ;
error -> V_89 [ V_134 ] . V_632 = F_3 ( F_184 ( V_134 ) ) ;
}
return error ;
}
void
F_470 ( struct V_809 * V_61 ,
struct V_1 * V_2 ,
struct V_797 * error )
{
int V_134 ;
for ( V_134 = 0 ; V_134 < 2 ; V_134 ++ ) {
F_471 ( V_61 , L_156 , V_134 ) ;
F_471 ( V_61 , L_157 , error -> V_89 [ V_134 ] . V_805 ) ;
F_471 ( V_61 , L_158 , error -> V_89 [ V_134 ] . V_806 ) ;
F_471 ( V_61 , L_159 , error -> V_89 [ V_134 ] . V_633 ) ;
F_471 ( V_61 , L_160 , error -> V_89 [ V_134 ] . V_807 ) ;
F_471 ( V_61 , L_161 , error -> V_89 [ V_134 ] . V_630 ) ;
F_471 ( V_61 , L_162 , error -> V_89 [ V_134 ] . V_636 ) ;
F_471 ( V_61 , L_163 , error -> V_89 [ V_134 ] . V_808 ) ;
F_471 ( V_61 , L_164 , error -> V_89 [ V_134 ] . V_632 ) ;
F_471 ( V_61 , L_165 , V_134 ) ;
F_471 ( V_61 , L_166 , error -> V_132 [ V_134 ] . V_800 ) ;
F_471 ( V_61 , L_167 , error -> V_132 [ V_134 ] . V_802 ) ;
F_471 ( V_61 , L_168 , error -> V_132 [ V_134 ] . V_578 ) ;
F_471 ( V_61 , L_169 , error -> V_132 [ V_134 ] . V_563 ) ;
F_471 ( V_61 , L_170 , error -> V_132 [ V_134 ] . V_575 ) ;
if ( F_40 ( V_2 ) -> V_93 >= 4 ) {
F_471 ( V_61 , L_171 , error -> V_132 [ V_134 ] . V_803 ) ;
F_471 ( V_61 , L_172 , error -> V_132 [ V_134 ] . V_804 ) ;
}
F_471 ( V_61 , L_173 , V_134 ) ;
F_471 ( V_61 , L_166 , error -> V_799 [ V_134 ] . V_800 ) ;
F_471 ( V_61 , L_169 , error -> V_799 [ V_134 ] . V_801 ) ;
F_471 ( V_61 , L_174 , error -> V_799 [ V_134 ] . V_74 ) ;
}
}
