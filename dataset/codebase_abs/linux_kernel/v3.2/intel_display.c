static inline T_1
F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
struct V_3 * V_4 = V_2 -> V_5 ;
return ( F_3 ( V_6 ) & V_7 ) + 2 ;
} else
return 27 ;
}
static const T_2 * F_4 ( struct V_8 * V_9 ,
int V_10 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const T_2 * V_11 ;
if ( F_5 ( V_9 , V_12 ) ) {
if ( ( F_3 ( V_13 ) & V_14 ) ==
V_15 ) {
if ( V_10 == 100000 )
V_11 = & V_16 ;
else
V_11 = & V_17 ;
} else {
if ( V_10 == 100000 )
V_11 = & V_18 ;
else
V_11 = & V_19 ;
}
} else if ( F_5 ( V_9 , V_20 ) ||
V_21 )
V_11 = & V_22 ;
else
V_11 = & V_23 ;
return V_11 ;
}
static const T_2 * F_6 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
const T_2 * V_11 ;
if ( F_5 ( V_9 , V_12 ) ) {
if ( ( F_3 ( V_24 ) & V_14 ) ==
V_15 )
V_11 = & V_25 ;
else
V_11 = & V_26 ;
} else if ( F_5 ( V_9 , V_27 ) ||
F_5 ( V_9 , V_28 ) ) {
V_11 = & V_29 ;
} else if ( F_5 ( V_9 , V_30 ) ) {
V_11 = & V_31 ;
} else if ( F_5 ( V_9 , V_20 ) ) {
V_11 = & V_32 ;
} else
V_11 = & V_33 ;
return V_11 ;
}
static const T_2 * F_7 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
const T_2 * V_11 ;
if ( F_8 ( V_2 ) )
V_11 = F_4 ( V_9 , V_10 ) ;
else if ( F_9 ( V_2 ) ) {
V_11 = F_6 ( V_9 ) ;
} else if ( F_10 ( V_2 ) ) {
if ( F_5 ( V_9 , V_12 ) )
V_11 = & V_34 ;
else
V_11 = & V_35 ;
} else if ( ! F_11 ( V_2 ) ) {
if ( F_5 ( V_9 , V_12 ) )
V_11 = & V_36 ;
else
V_11 = & V_33 ;
} else {
if ( F_5 ( V_9 , V_12 ) )
V_11 = & V_37 ;
else
V_11 = & V_38 ;
}
return V_11 ;
}
static void F_12 ( int V_10 , T_3 * clock )
{
clock -> V_39 = clock -> V_40 + 2 ;
clock -> V_41 = clock -> V_42 * clock -> V_43 ;
clock -> V_44 = V_10 * clock -> V_39 / clock -> V_45 ;
clock -> V_46 = clock -> V_44 / clock -> V_41 ;
}
static void F_13 ( struct V_1 * V_2 , int V_10 , T_3 * clock )
{
if ( F_10 ( V_2 ) ) {
F_12 ( V_10 , clock ) ;
return;
}
clock -> V_39 = 5 * ( clock -> V_47 + 2 ) + ( clock -> V_40 + 2 ) ;
clock -> V_41 = clock -> V_42 * clock -> V_43 ;
clock -> V_44 = V_10 * clock -> V_39 / ( clock -> V_45 + 2 ) ;
clock -> V_46 = clock -> V_44 / clock -> V_41 ;
}
bool F_5 ( struct V_8 * V_9 , int type )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
F_14 (encoder, &mode_config->encoder_list, base.head)
if ( V_51 -> V_52 . V_9 == V_9 && V_51 -> type == type )
return true ;
return false ;
}
static bool F_15 ( struct V_1 * V_2 ,
const T_2 * V_11 ,
const T_3 * clock )
{
if ( clock -> V_42 < V_11 -> V_42 . V_53 || V_11 -> V_42 . V_54 < clock -> V_42 )
F_16 ( L_1 ) ;
if ( clock -> V_41 < V_11 -> V_41 . V_53 || V_11 -> V_41 . V_54 < clock -> V_41 )
F_16 ( L_2 ) ;
if ( clock -> V_40 < V_11 -> V_40 . V_53 || V_11 -> V_40 . V_54 < clock -> V_40 )
F_16 ( L_3 ) ;
if ( clock -> V_47 < V_11 -> V_47 . V_53 || V_11 -> V_47 . V_54 < clock -> V_47 )
F_16 ( L_4 ) ;
if ( clock -> V_47 <= clock -> V_40 && ! F_10 ( V_2 ) )
F_16 ( L_5 ) ;
if ( clock -> V_39 < V_11 -> V_39 . V_53 || V_11 -> V_39 . V_54 < clock -> V_39 )
F_16 ( L_6 ) ;
if ( clock -> V_45 < V_11 -> V_45 . V_53 || V_11 -> V_45 . V_54 < clock -> V_45 )
F_16 ( L_7 ) ;
if ( clock -> V_44 < V_11 -> V_44 . V_53 || V_11 -> V_44 . V_54 < clock -> V_44 )
F_16 ( L_8 ) ;
if ( clock -> V_46 < V_11 -> V_46 . V_53 || V_11 -> V_46 . V_54 < clock -> V_46 )
F_16 ( L_9 ) ;
return true ;
}
static bool
F_17 ( const T_2 * V_11 , struct V_8 * V_9 ,
int V_55 , int V_10 , T_3 * V_56 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 clock ;
int V_57 = V_55 ;
if ( F_5 ( V_9 , V_12 ) &&
( F_3 ( V_24 ) ) != 0 ) {
if ( ( F_3 ( V_24 ) & V_14 ) ==
V_15 )
clock . V_43 = V_11 -> V_43 . V_58 ;
else
clock . V_43 = V_11 -> V_43 . V_59 ;
} else {
if ( V_55 < V_11 -> V_43 . V_60 )
clock . V_43 = V_11 -> V_43 . V_59 ;
else
clock . V_43 = V_11 -> V_43 . V_58 ;
}
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
for ( clock . V_47 = V_11 -> V_47 . V_53 ; clock . V_47 <= V_11 -> V_47 . V_54 ;
clock . V_47 ++ ) {
for ( clock . V_40 = V_11 -> V_40 . V_53 ;
clock . V_40 <= V_11 -> V_40 . V_54 ; clock . V_40 ++ ) {
if ( clock . V_40 >= clock . V_47 && ! F_10 ( V_2 ) )
break;
for ( clock . V_45 = V_11 -> V_45 . V_53 ;
clock . V_45 <= V_11 -> V_45 . V_54 ; clock . V_45 ++ ) {
for ( clock . V_42 = V_11 -> V_42 . V_53 ;
clock . V_42 <= V_11 -> V_42 . V_54 ; clock . V_42 ++ ) {
int V_61 ;
F_13 ( V_2 , V_10 , & clock ) ;
if ( ! F_15 ( V_2 , V_11 ,
& clock ) )
continue;
V_61 = abs ( clock . V_46 - V_55 ) ;
if ( V_61 < V_57 ) {
* V_56 = clock ;
V_57 = V_61 ;
}
}
}
}
}
return ( V_57 != V_55 ) ;
}
static bool
F_18 ( const T_2 * V_11 , struct V_8 * V_9 ,
int V_55 , int V_10 , T_3 * V_56 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 clock ;
int V_62 ;
bool V_63 ;
int V_64 = ( V_55 >> 8 ) + ( V_55 >> 9 ) ;
V_63 = false ;
if ( F_5 ( V_9 , V_12 ) ) {
int V_65 ;
if ( F_8 ( V_2 ) )
V_65 = V_13 ;
else
V_65 = V_24 ;
if ( ( F_3 ( V_65 ) & V_14 ) ==
V_15 )
clock . V_43 = V_11 -> V_43 . V_58 ;
else
clock . V_43 = V_11 -> V_43 . V_59 ;
} else {
if ( V_55 < V_11 -> V_43 . V_60 )
clock . V_43 = V_11 -> V_43 . V_59 ;
else
clock . V_43 = V_11 -> V_43 . V_58 ;
}
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_62 = V_11 -> V_45 . V_54 ;
for ( clock . V_45 = V_11 -> V_45 . V_53 ; clock . V_45 <= V_62 ; clock . V_45 ++ ) {
for ( clock . V_47 = V_11 -> V_47 . V_54 ;
clock . V_47 >= V_11 -> V_47 . V_53 ; clock . V_47 -- ) {
for ( clock . V_40 = V_11 -> V_40 . V_54 ;
clock . V_40 >= V_11 -> V_40 . V_53 ; clock . V_40 -- ) {
for ( clock . V_42 = V_11 -> V_42 . V_54 ;
clock . V_42 >= V_11 -> V_42 . V_53 ; clock . V_42 -- ) {
int V_61 ;
F_13 ( V_2 , V_10 , & clock ) ;
if ( ! F_15 ( V_2 , V_11 ,
& clock ) )
continue;
V_61 = abs ( clock . V_46 - V_55 ) ;
if ( V_61 < V_64 ) {
* V_56 = clock ;
V_64 = V_61 ;
V_62 = clock . V_45 ;
V_63 = true ;
}
}
}
}
}
return V_63 ;
}
static bool
F_19 ( const T_2 * V_11 , struct V_8 * V_9 ,
int V_55 , int V_10 , T_3 * V_56 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_3 clock ;
if ( V_55 < 200000 ) {
clock . V_45 = 1 ;
clock . V_42 = 2 ;
clock . V_43 = 10 ;
clock . V_47 = 12 ;
clock . V_40 = 9 ;
} else {
clock . V_45 = 2 ;
clock . V_42 = 1 ;
clock . V_43 = 10 ;
clock . V_47 = 14 ;
clock . V_40 = 8 ;
}
F_13 ( V_2 , V_10 , & clock ) ;
memcpy ( V_56 , & clock , sizeof( T_3 ) ) ;
return true ;
}
static bool
F_20 ( const T_2 * V_11 , struct V_8 * V_9 ,
int V_55 , int V_10 , T_3 * V_56 )
{
T_3 clock ;
if ( V_55 < 200000 ) {
clock . V_42 = 2 ;
clock . V_43 = 10 ;
clock . V_45 = 2 ;
clock . V_47 = 23 ;
clock . V_40 = 8 ;
} else {
clock . V_42 = 1 ;
clock . V_43 = 10 ;
clock . V_45 = 1 ;
clock . V_47 = 14 ;
clock . V_40 = 2 ;
}
clock . V_39 = 5 * ( clock . V_47 + 2 ) + ( clock . V_40 + 2 ) ;
clock . V_41 = ( clock . V_42 * clock . V_43 ) ;
clock . V_46 = 96000 * clock . V_39 / ( clock . V_45 + 2 ) / clock . V_41 ;
clock . V_44 = 0 ;
memcpy ( V_56 , & clock , sizeof( T_3 ) ) ;
return true ;
}
void F_21 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_67 = F_22 ( V_66 ) ;
F_23 ( V_67 ,
F_3 ( V_67 ) | V_68 ) ;
if ( F_24 ( F_3 ( V_67 ) &
V_68 ,
50 ) )
F_25 ( L_10 ) ;
}
void F_26 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
int V_70 = F_28 ( V_66 ) ;
if ( F_24 ( ( F_3 ( V_70 ) & V_71 ) == 0 ,
100 ) )
F_25 ( L_11 ) ;
} else {
T_1 V_72 ;
int V_70 = F_29 ( V_66 ) ;
unsigned long V_73 = V_74 + F_30 ( 100 ) ;
do {
V_72 = F_3 ( V_70 ) & V_75 ;
F_31 ( 5 ) ;
} while ( ( ( F_3 ( V_70 ) & V_75 ) != V_72 ) &&
F_32 ( V_73 , V_74 ) );
if ( F_32 ( V_74 , V_73 ) )
F_25 ( L_11 ) ;
}
}
static const char * F_33 ( bool V_76 )
{
return V_76 ? L_12 : L_13 ;
}
static void F_34 ( struct V_3 * V_4 ,
enum V_66 V_66 , bool V_77 )
{
int V_70 ;
T_1 V_78 ;
bool V_79 ;
V_70 = F_35 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_79 = ! ! ( V_78 & V_80 ) ;
F_36 ( V_79 != V_77 ,
L_14 ,
F_33 ( V_77 ) , F_33 ( V_79 ) ) ;
}
static void F_37 ( struct V_3 * V_4 ,
enum V_66 V_66 , bool V_77 )
{
int V_70 ;
T_1 V_78 ;
bool V_79 ;
if ( F_38 ( V_4 -> V_2 ) ) {
T_1 V_81 ;
V_81 = F_3 ( V_82 ) ;
F_36 ( ! ( ( V_81 >> ( 4 * V_66 ) ) & 8 ) ,
L_15 , V_66 ) ;
V_66 = ( V_81 >> ( 4 * V_66 ) ) & 1 ;
}
V_70 = F_39 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_79 = ! ! ( V_78 & V_80 ) ;
F_36 ( V_79 != V_77 ,
L_16 ,
F_33 ( V_77 ) , F_33 ( V_79 ) ) ;
}
static void F_40 ( struct V_3 * V_4 ,
enum V_66 V_66 , bool V_77 )
{
int V_70 ;
T_1 V_78 ;
bool V_79 ;
V_70 = F_41 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_79 = ! ! ( V_78 & V_83 ) ;
F_36 ( V_79 != V_77 ,
L_17 ,
F_33 ( V_77 ) , F_33 ( V_79 ) ) ;
}
static void F_42 ( struct V_3 * V_4 ,
enum V_66 V_66 , bool V_77 )
{
int V_70 ;
T_1 V_78 ;
bool V_79 ;
V_70 = F_43 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_79 = ! ! ( V_78 & V_84 ) ;
F_36 ( V_79 != V_77 ,
L_18 ,
F_33 ( V_77 ) , F_33 ( V_79 ) ) ;
}
static void F_44 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
if ( V_4 -> V_85 -> V_69 == 5 )
return;
V_70 = F_41 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
F_36 ( ! ( V_78 & V_86 ) , L_19 ) ;
}
static void F_45 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
V_70 = F_43 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
F_36 ( ! ( V_78 & V_87 ) , L_20 ) ;
}
static void F_46 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_88 , V_65 ;
T_1 V_78 ;
enum V_66 V_89 = V_90 ;
bool V_91 = true ;
if ( F_8 ( V_4 -> V_2 ) ) {
V_88 = V_92 ;
V_65 = V_13 ;
} else {
V_88 = V_93 ;
V_65 = V_24 ;
}
V_78 = F_3 ( V_88 ) ;
if ( ! ( V_78 & V_94 ) ||
( ( V_78 & V_95 ) == V_95 ) )
V_91 = false ;
if ( F_3 ( V_65 ) & V_96 )
V_89 = V_97 ;
F_36 ( V_89 == V_66 && V_91 ,
L_21 ,
F_47 ( V_66 ) ) ;
}
static void F_48 ( struct V_3 * V_4 ,
enum V_66 V_66 , bool V_77 )
{
int V_70 ;
T_1 V_78 ;
bool V_79 ;
V_70 = F_28 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_79 = ! ! ( V_78 & V_98 ) ;
F_36 ( V_79 != V_77 ,
L_22 ,
F_47 ( V_66 ) , F_33 ( V_77 ) , F_33 ( V_79 ) ) ;
}
static void F_49 ( struct V_3 * V_4 ,
enum V_99 V_99 )
{
int V_70 ;
T_1 V_78 ;
V_70 = F_50 ( V_99 ) ;
V_78 = F_3 ( V_70 ) ;
F_36 ( ! ( V_78 & V_100 ) ,
L_23 ,
F_51 ( V_99 ) ) ;
}
static void F_52 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 , V_101 ;
T_1 V_78 ;
int V_102 ;
if ( F_8 ( V_4 -> V_2 ) )
return;
for ( V_101 = 0 ; V_101 < 2 ; V_101 ++ ) {
V_70 = F_50 ( V_101 ) ;
V_78 = F_3 ( V_70 ) ;
V_102 = ( V_78 & V_103 ) >>
V_104 ;
F_36 ( ( V_78 & V_100 ) && V_66 == V_102 ,
L_24 ,
F_51 ( V_101 ) , F_47 ( V_66 ) ) ;
}
}
static void F_53 ( struct V_3 * V_4 )
{
T_1 V_78 ;
bool V_76 ;
V_78 = F_3 ( V_105 ) ;
V_76 = ! ! ( V_78 & ( V_106 | V_107 |
V_108 ) ) ;
F_36 ( ! V_76 , L_25 ) ;
}
static void F_54 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
bool V_76 ;
V_70 = F_55 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_76 = ! ! ( V_78 & V_109 ) ;
F_36 ( V_76 ,
L_26 ,
F_47 ( V_66 ) ) ;
}
static bool F_56 ( struct V_3 * V_4 ,
enum V_66 V_66 , T_1 V_110 , T_1 V_78 )
{
if ( ( V_78 & V_111 ) == 0 )
return false ;
if ( F_38 ( V_4 -> V_2 ) ) {
T_1 V_112 = F_57 ( V_66 ) ;
T_1 V_113 = F_3 ( V_112 ) ;
if ( ( V_113 & V_114 ) != V_110 )
return false ;
} else {
if ( ( V_78 & V_115 ) != ( V_66 << 30 ) )
return false ;
}
return true ;
}
static bool F_58 ( struct V_3 * V_4 ,
enum V_66 V_66 , T_1 V_78 )
{
if ( ( V_78 & V_116 ) == 0 )
return false ;
if ( F_38 ( V_4 -> V_2 ) ) {
if ( ( V_78 & V_117 ) != F_59 ( V_66 ) )
return false ;
} else {
if ( ( V_78 & V_118 ) != F_60 ( V_66 ) )
return false ;
}
return true ;
}
static bool F_61 ( struct V_3 * V_4 ,
enum V_66 V_66 , T_1 V_78 )
{
if ( ( V_78 & V_119 ) == 0 )
return false ;
if ( F_38 ( V_4 -> V_2 ) ) {
if ( ( V_78 & V_117 ) != F_59 ( V_66 ) )
return false ;
} else {
if ( ( V_78 & V_120 ) != F_62 ( V_66 ) )
return false ;
}
return true ;
}
static bool F_63 ( struct V_3 * V_4 ,
enum V_66 V_66 , T_1 V_78 )
{
if ( ( V_78 & V_121 ) == 0 )
return false ;
if ( F_38 ( V_4 -> V_2 ) ) {
if ( ( V_78 & V_117 ) != F_59 ( V_66 ) )
return false ;
} else {
if ( ( V_78 & V_122 ) != F_64 ( V_66 ) )
return false ;
}
return true ;
}
static void F_65 ( struct V_3 * V_4 ,
enum V_66 V_66 , int V_70 , T_1 V_110 )
{
T_1 V_78 = F_3 ( V_70 ) ;
F_36 ( F_56 ( V_4 , V_66 , V_110 , V_78 ) ,
L_27 ,
V_70 , F_47 ( V_66 ) ) ;
}
static void F_66 ( struct V_3 * V_4 ,
enum V_66 V_66 , int V_70 )
{
T_1 V_78 = F_3 ( V_70 ) ;
F_36 ( F_58 ( V_4 , V_78 , V_66 ) ,
L_27 ,
V_70 , F_47 ( V_66 ) ) ;
}
static void F_67 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_65 ( V_4 , V_66 , V_123 , V_124 ) ;
F_65 ( V_4 , V_66 , V_125 , V_126 ) ;
F_65 ( V_4 , V_66 , V_127 , V_128 ) ;
V_70 = V_129 ;
V_78 = F_3 ( V_70 ) ;
F_36 ( F_63 ( V_4 , V_78 , V_66 ) ,
L_28 ,
F_47 ( V_66 ) ) ;
V_70 = V_13 ;
V_78 = F_3 ( V_70 ) ;
F_36 ( F_61 ( V_4 , V_78 , V_66 ) ,
L_29 ,
F_47 ( V_66 ) ) ;
F_66 ( V_4 , V_66 , V_130 ) ;
F_66 ( V_4 , V_66 , V_131 ) ;
F_66 ( V_4 , V_66 , V_132 ) ;
}
static void F_68 ( struct V_3 * V_4 , enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_69 ( V_4 -> V_85 -> V_69 >= 5 ) ;
if ( F_70 ( V_4 -> V_2 ) && ! F_71 ( V_4 -> V_2 ) )
F_46 ( V_4 , V_66 ) ;
V_70 = F_35 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_78 |= V_80 ;
F_23 ( V_70 , V_78 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
F_23 ( V_70 , V_78 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
F_23 ( V_70 , V_78 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
}
static void F_74 ( struct V_3 * V_4 , enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
if ( V_66 == V_90 && ( V_4 -> V_133 & V_134 ) )
return;
F_75 ( V_4 , V_66 ) ;
V_70 = F_35 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_78 &= ~ V_80 ;
F_23 ( V_70 , V_78 ) ;
F_72 ( V_70 ) ;
}
static void F_76 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
if ( V_66 > 1 )
return;
F_69 ( V_4 -> V_85 -> V_69 < 5 ) ;
F_53 ( V_4 ) ;
V_70 = F_39 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_78 |= V_80 ;
F_23 ( V_70 , V_78 ) ;
F_72 ( V_70 ) ;
F_73 ( 200 ) ;
}
static void F_77 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
if ( V_66 > 1 )
return;
F_69 ( V_4 -> V_85 -> V_69 < 5 ) ;
F_54 ( V_4 , V_66 ) ;
V_70 = F_39 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_78 &= ~ V_80 ;
F_23 ( V_70 , V_78 ) ;
F_72 ( V_70 ) ;
F_73 ( 200 ) ;
}
static void F_78 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_69 ( V_4 -> V_85 -> V_69 < 5 ) ;
F_79 ( V_4 , V_66 ) ;
F_80 ( V_4 , V_66 ) ;
F_81 ( V_4 , V_66 ) ;
V_70 = F_55 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
if ( F_82 ( V_4 -> V_2 ) ) {
V_78 &= ~ V_135 ;
V_78 |= F_3 ( F_28 ( V_66 ) ) & V_135 ;
}
F_23 ( V_70 , V_78 | V_109 ) ;
if ( F_24 ( F_3 ( V_70 ) & V_136 , 100 ) )
F_83 ( L_30 , V_66 ) ;
}
static void F_84 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_85 ( V_4 , V_66 ) ;
F_86 ( V_4 , V_66 ) ;
F_67 ( V_4 , V_66 ) ;
V_70 = F_55 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_78 &= ~ V_109 ;
F_23 ( V_70 , V_78 ) ;
if ( F_24 ( ( F_3 ( V_70 ) & V_136 ) == 0 , 50 ) )
F_83 ( L_31 , V_66 ) ;
}
static void F_87 ( struct V_3 * V_4 , enum V_66 V_66 ,
bool V_137 )
{
int V_70 ;
T_1 V_78 ;
if ( ! F_8 ( V_4 -> V_2 ) )
F_88 ( V_4 , V_66 ) ;
else {
if ( V_137 ) {
F_45 ( V_4 , V_66 ) ;
F_44 ( V_4 , V_66 ) ;
}
}
V_70 = F_28 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
if ( V_78 & V_98 )
return;
F_23 ( V_70 , V_78 | V_98 ) ;
F_21 ( V_4 -> V_2 , V_66 ) ;
}
static void F_89 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_52 ( V_4 , V_66 ) ;
if ( V_66 == V_90 && ( V_4 -> V_133 & V_134 ) )
return;
V_70 = F_28 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
if ( ( V_78 & V_98 ) == 0 )
return;
F_23 ( V_70 , V_78 & ~ V_98 ) ;
F_26 ( V_4 -> V_2 , V_66 ) ;
}
static void F_90 ( struct V_3 * V_4 ,
enum V_99 V_99 )
{
F_23 ( F_91 ( V_99 ) , F_3 ( F_91 ( V_99 ) ) ) ;
F_23 ( F_92 ( V_99 ) , F_3 ( F_92 ( V_99 ) ) ) ;
}
static void F_93 ( struct V_3 * V_4 ,
enum V_99 V_99 , enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_94 ( V_4 , V_66 ) ;
V_70 = F_50 ( V_99 ) ;
V_78 = F_3 ( V_70 ) ;
if ( V_78 & V_100 )
return;
F_23 ( V_70 , V_78 | V_100 ) ;
F_90 ( V_4 , V_99 ) ;
F_21 ( V_4 -> V_2 , V_66 ) ;
}
static void F_95 ( struct V_3 * V_4 ,
enum V_99 V_99 , enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
V_70 = F_50 ( V_99 ) ;
V_78 = F_3 ( V_70 ) ;
if ( ( V_78 & V_100 ) == 0 )
return;
F_23 ( V_70 , V_78 & ~ V_100 ) ;
F_90 ( V_4 , V_99 ) ;
F_21 ( V_4 -> V_2 , V_66 ) ;
}
static void F_96 ( struct V_3 * V_4 ,
enum V_66 V_66 , int V_70 , T_1 V_110 )
{
T_1 V_78 = F_3 ( V_70 ) ;
if ( F_56 ( V_4 , V_66 , V_110 , V_78 ) ) {
F_25 ( L_32 , V_70 , V_66 ) ;
F_23 ( V_70 , V_78 & ~ V_111 ) ;
}
}
static void F_97 ( struct V_3 * V_4 ,
enum V_66 V_66 , int V_70 )
{
T_1 V_78 = F_3 ( V_70 ) ;
if ( F_58 ( V_4 , V_78 , V_66 ) ) {
F_25 ( L_33 ,
V_70 , V_66 ) ;
F_23 ( V_70 , V_78 & ~ V_116 ) ;
}
}
static void F_98 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
T_1 V_70 , V_78 ;
V_78 = F_3 ( V_92 ) ;
F_23 ( V_92 , V_78 | V_95 ) ;
F_96 ( V_4 , V_66 , V_123 , V_124 ) ;
F_96 ( V_4 , V_66 , V_125 , V_126 ) ;
F_96 ( V_4 , V_66 , V_127 , V_128 ) ;
V_70 = V_129 ;
V_78 = F_3 ( V_70 ) ;
if ( F_63 ( V_4 , V_78 , V_66 ) )
F_23 ( V_70 , V_78 & ~ V_121 ) ;
V_70 = V_13 ;
V_78 = F_3 ( V_70 ) ;
if ( F_61 ( V_4 , V_78 , V_66 ) ) {
F_25 ( L_34 , V_66 , V_78 ) ;
F_23 ( V_70 , V_78 & ~ V_119 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
}
F_97 ( V_4 , V_66 , V_130 ) ;
F_97 ( V_4 , V_66 , V_131 ) ;
F_97 ( V_4 , V_66 , V_132 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_138 ;
V_138 = F_3 ( V_139 ) ;
if ( ( V_138 & V_140 ) == 0 )
return;
V_138 &= ~ V_140 ;
F_23 ( V_139 , V_138 ) ;
if ( F_24 ( ( F_3 ( V_141 ) & V_142 ) == 0 , 10 ) ) {
F_25 ( L_35 ) ;
return;
}
F_25 ( L_36 ) ;
}
static void F_100 ( struct V_8 * V_9 , unsigned long V_143 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_144 * V_145 = V_9 -> V_145 ;
struct V_146 * V_147 = F_101 ( V_145 ) ;
struct V_148 * V_149 = V_147 -> V_149 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_151 ;
int V_99 , V_101 ;
T_1 V_138 , V_152 ;
V_151 = V_4 -> V_153 / V_154 ;
if ( V_145 -> V_155 < V_151 )
V_151 = V_145 -> V_155 ;
V_151 = ( V_151 / 64 ) - 1 ;
V_99 = V_150 -> V_99 == 0 ? V_156 : V_157 ;
for ( V_101 = 0 ; V_101 < ( V_154 / 32 ) + 1 ; V_101 ++ )
F_23 ( V_158 + ( V_101 * 4 ) , 0 ) ;
V_152 = V_159 | V_160 | V_161 ;
V_152 |= V_99 ;
F_23 ( V_162 , V_152 ) ;
F_23 ( V_163 , V_9 -> V_164 ) ;
V_138 = V_140 | V_165 ;
if ( F_103 ( V_2 ) )
V_138 |= V_166 ;
V_138 |= ( V_151 & 0xff ) << V_167 ;
V_138 |= ( V_143 & 0x2fff ) << V_168 ;
V_138 |= V_149 -> V_169 ;
F_23 ( V_139 , V_138 ) ;
F_25 ( L_37 ,
V_151 , V_9 -> V_164 , V_150 -> V_99 ) ;
}
static bool F_104 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_139 ) & V_140 ;
}
static void F_105 ( struct V_8 * V_9 , unsigned long V_143 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_144 * V_145 = V_9 -> V_145 ;
struct V_146 * V_147 = F_101 ( V_145 ) ;
struct V_148 * V_149 = V_147 -> V_149 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_99 = V_150 -> V_99 == 0 ? V_170 : V_171 ;
unsigned long V_172 = 200 ;
T_1 V_173 ;
V_173 = V_99 | V_174 | V_175 ;
V_173 |= V_176 | V_149 -> V_169 ;
F_23 ( V_177 , V_178 ) ;
F_23 ( V_179 , V_180 |
( V_172 << V_181 ) |
( V_143 << V_182 ) ) ;
F_23 ( V_183 , V_9 -> V_164 ) ;
F_23 ( V_184 , F_3 ( V_184 ) | V_185 ) ;
F_25 ( L_38 , V_150 -> V_99 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_173 ;
V_173 = F_3 ( V_184 ) ;
if ( V_173 & V_185 ) {
V_173 &= ~ V_185 ;
F_23 ( V_184 , V_173 ) ;
F_25 ( L_36 ) ;
}
}
static bool F_107 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_184 ) & V_185 ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_186 ;
F_109 ( V_4 ) ;
V_186 = F_3 ( V_187 ) ;
V_186 |= V_188 <<
V_189 ;
F_23 ( V_187 , V_186 ) ;
V_186 |= V_188 ;
F_23 ( V_187 , V_186 ) ;
V_186 &= ~ ( V_188 <<
V_189 ) ;
F_23 ( V_187 , V_186 ) ;
F_72 ( V_187 ) ;
F_110 ( V_4 ) ;
}
static void F_111 ( struct V_8 * V_9 , unsigned long V_143 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_144 * V_145 = V_9 -> V_145 ;
struct V_146 * V_147 = F_101 ( V_145 ) ;
struct V_148 * V_149 = V_147 -> V_149 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_99 = V_150 -> V_99 == 0 ? V_170 : V_171 ;
unsigned long V_172 = 200 ;
T_1 V_173 ;
V_173 = F_3 ( V_190 ) ;
V_173 &= V_191 ;
V_173 |= ( V_99 | V_175 ) ;
V_173 |= V_192 ;
V_173 |= ( V_176 | V_149 -> V_169 ) ;
F_23 ( V_193 , V_178 ) ;
F_23 ( V_194 , V_180 |
( V_172 << V_181 ) |
( V_143 << V_182 ) ) ;
F_23 ( V_195 , V_9 -> V_164 ) ;
F_23 ( V_196 , V_149 -> V_197 | V_198 ) ;
F_23 ( V_190 , V_173 | V_185 ) ;
if ( F_112 ( V_2 ) ) {
F_23 ( V_199 ,
V_200 | V_149 -> V_169 ) ;
F_23 ( V_201 , V_9 -> V_164 ) ;
F_108 ( V_2 ) ;
}
F_25 ( L_38 , V_150 -> V_99 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_173 ;
V_173 = F_3 ( V_190 ) ;
if ( V_173 & V_185 ) {
V_173 &= ~ V_185 ;
F_23 ( V_190 , V_173 ) ;
F_25 ( L_36 ) ;
}
}
static bool F_114 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_190 ) & V_185 ;
}
bool F_115 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_202 . V_203 )
return false ;
return V_4 -> V_202 . V_203 ( V_2 ) ;
}
static void F_116 ( struct V_204 * V_205 )
{
struct V_206 * V_207 =
F_117 ( F_118 ( V_205 ) ,
struct V_206 , V_207 ) ;
struct V_1 * V_2 = V_207 -> V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_119 ( & V_2 -> V_208 ) ;
if ( V_207 == V_4 -> V_209 ) {
if ( V_207 -> V_9 -> V_145 == V_207 -> V_145 ) {
V_4 -> V_202 . V_210 ( V_207 -> V_9 ,
V_207 -> V_143 ) ;
V_4 -> V_211 = F_102 ( V_207 -> V_9 ) -> V_99 ;
V_4 -> V_212 = V_207 -> V_9 -> V_145 -> V_52 . V_213 ;
V_4 -> V_214 = V_207 -> V_9 -> V_164 ;
}
V_4 -> V_209 = NULL ;
}
F_120 ( & V_2 -> V_208 ) ;
F_121 ( V_207 ) ;
}
static void F_122 ( struct V_3 * V_4 )
{
if ( V_4 -> V_209 == NULL )
return;
F_25 ( L_39 ) ;
if ( F_123 ( & V_4 -> V_209 -> V_207 ) )
F_121 ( V_4 -> V_209 ) ;
V_4 -> V_209 = NULL ;
}
static void F_124 ( struct V_8 * V_9 , unsigned long V_143 )
{
struct V_206 * V_207 ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_202 . V_210 )
return;
F_122 ( V_4 ) ;
V_207 = F_125 ( sizeof *V_207 , V_215 ) ;
if ( V_207 == NULL ) {
V_4 -> V_202 . V_210 ( V_9 , V_143 ) ;
return;
}
V_207 -> V_9 = V_9 ;
V_207 -> V_145 = V_9 -> V_145 ;
V_207 -> V_143 = V_143 ;
F_126 ( & V_207 -> V_207 , F_116 ) ;
V_4 -> V_209 = V_207 ;
F_25 ( L_40 ) ;
F_127 ( & V_207 -> V_207 , F_30 ( 50 ) ) ;
}
void F_128 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_122 ( V_4 ) ;
if ( ! V_4 -> V_202 . V_216 )
return;
V_4 -> V_202 . V_216 ( V_2 ) ;
V_4 -> V_211 = - 1 ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = NULL , * V_217 ;
struct V_150 * V_150 ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
struct V_148 * V_149 ;
int V_210 ;
F_25 ( L_41 ) ;
if ( ! V_218 )
return;
if ( ! F_130 ( V_2 ) )
return;
F_14 (tmp_crtc, &dev->mode_config.crtc_list, head) {
if ( V_217 -> V_76 && V_217 -> V_145 ) {
if ( V_9 ) {
F_25 ( L_42 ) ;
V_4 -> V_219 = V_220 ;
goto V_221;
}
V_9 = V_217 ;
}
}
if ( ! V_9 || V_9 -> V_145 == NULL ) {
F_25 ( L_43 ) ;
V_4 -> V_219 = V_222 ;
goto V_221;
}
V_150 = F_102 ( V_9 ) ;
V_145 = V_9 -> V_145 ;
V_147 = F_101 ( V_145 ) ;
V_149 = V_147 -> V_149 ;
V_210 = V_223 ;
if ( V_210 < 0 ) {
F_25 ( L_44 ) ;
V_210 = 1 ;
if ( F_27 ( V_2 ) -> V_69 <= 5 )
V_210 = 0 ;
}
if ( ! V_210 ) {
F_25 ( L_45 ) ;
V_4 -> V_219 = V_224 ;
goto V_221;
}
if ( V_147 -> V_149 -> V_52 . V_225 > V_4 -> V_153 ) {
F_25 ( L_46
L_47 ) ;
V_4 -> V_219 = V_226 ;
goto V_221;
}
if ( ( V_9 -> V_227 . V_228 & V_229 ) ||
( V_9 -> V_227 . V_228 & V_230 ) ) {
F_25 ( L_48
L_49 ) ;
V_4 -> V_219 = V_231 ;
goto V_221;
}
if ( ( V_9 -> V_227 . V_232 > 2048 ) ||
( V_9 -> V_227 . V_233 > 1536 ) ) {
F_25 ( L_50 ) ;
V_4 -> V_219 = V_234 ;
goto V_221;
}
if ( ( F_131 ( V_2 ) || F_103 ( V_2 ) ) && V_150 -> V_99 != 0 ) {
F_25 ( L_51 ) ;
V_4 -> V_219 = V_235 ;
goto V_221;
}
if ( V_149 -> V_236 != V_237 ||
V_149 -> V_169 == V_238 ) {
F_25 ( L_52 ) ;
V_4 -> V_219 = V_239 ;
goto V_221;
}
if ( F_132 () )
goto V_221;
if ( V_4 -> V_211 == V_150 -> V_99 &&
V_4 -> V_212 == V_145 -> V_52 . V_213 &&
V_4 -> V_214 == V_9 -> V_164 )
return;
if ( F_115 ( V_2 ) ) {
F_25 ( L_53 ) ;
F_128 ( V_2 ) ;
}
F_124 ( V_9 , 500 ) ;
return;
V_221:
if ( F_115 ( V_2 ) ) {
F_25 ( L_54 ) ;
F_128 ( V_2 ) ;
}
}
int
F_133 ( struct V_1 * V_2 ,
struct V_148 * V_149 ,
struct V_240 * V_241 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_242 ;
int V_243 ;
switch ( V_149 -> V_236 ) {
case V_244 :
if ( F_134 ( V_2 ) || F_135 ( V_2 ) )
V_242 = 128 * 1024 ;
else if ( F_27 ( V_2 ) -> V_69 >= 4 )
V_242 = 4 * 1024 ;
else
V_242 = 64 * 1024 ;
break;
case V_237 :
V_242 = 0 ;
break;
case V_245 :
F_83 ( L_55 ) ;
return - V_246 ;
default:
F_136 () ;
}
V_4 -> V_247 . V_248 = false ;
V_243 = F_137 ( V_149 , V_242 , V_241 ) ;
if ( V_243 )
goto V_249;
if ( V_149 -> V_236 != V_244 ) {
V_243 = F_138 ( V_149 , V_241 ) ;
if ( V_243 )
goto V_250;
}
V_4 -> V_247 . V_248 = true ;
return 0 ;
V_250:
F_139 ( V_149 ) ;
V_249:
V_4 -> V_247 . V_248 = true ;
return V_243 ;
}
static int F_140 ( struct V_8 * V_9 , struct V_144 * V_145 ,
int V_251 , int V_164 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
struct V_146 * V_147 ;
struct V_148 * V_149 ;
int V_99 = V_150 -> V_99 ;
unsigned long V_252 , V_253 ;
T_1 V_254 ;
T_1 V_70 ;
switch ( V_99 ) {
case 0 :
case 1 :
break;
default:
F_83 ( L_56 , V_99 ) ;
return - V_246 ;
}
V_147 = F_101 ( V_145 ) ;
V_149 = V_147 -> V_149 ;
V_70 = F_50 ( V_99 ) ;
V_254 = F_3 ( V_70 ) ;
V_254 &= ~ V_255 ;
switch ( V_145 -> V_256 ) {
case 8 :
V_254 |= V_257 ;
break;
case 16 :
if ( V_145 -> V_258 == 15 )
V_254 |= V_259 ;
else
V_254 |= V_260 ;
break;
case 24 :
case 32 :
V_254 |= V_261 ;
break;
default:
F_83 ( L_57 , V_145 -> V_256 ) ;
return - V_246 ;
}
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
if ( V_149 -> V_236 != V_244 )
V_254 |= V_262 ;
else
V_254 &= ~ V_262 ;
}
F_23 ( V_70 , V_254 ) ;
V_252 = V_149 -> V_197 ;
V_253 = V_164 * V_145 -> V_155 + V_251 * ( V_145 -> V_256 / 8 ) ;
F_25 ( L_58 ,
V_252 , V_253 , V_251 , V_164 , V_145 -> V_155 ) ;
F_23 ( F_141 ( V_99 ) , V_145 -> V_155 ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
F_23 ( F_92 ( V_99 ) , V_252 ) ;
F_23 ( F_142 ( V_99 ) , ( V_164 << 16 ) | V_251 ) ;
F_23 ( F_91 ( V_99 ) , V_253 ) ;
} else
F_23 ( F_91 ( V_99 ) , V_252 + V_253 ) ;
F_72 ( V_70 ) ;
return 0 ;
}
static int F_143 ( struct V_8 * V_9 ,
struct V_144 * V_145 , int V_251 , int V_164 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
struct V_146 * V_147 ;
struct V_148 * V_149 ;
int V_99 = V_150 -> V_99 ;
unsigned long V_252 , V_253 ;
T_1 V_254 ;
T_1 V_70 ;
switch ( V_99 ) {
case 0 :
case 1 :
case 2 :
break;
default:
F_83 ( L_56 , V_99 ) ;
return - V_246 ;
}
V_147 = F_101 ( V_145 ) ;
V_149 = V_147 -> V_149 ;
V_70 = F_50 ( V_99 ) ;
V_254 = F_3 ( V_70 ) ;
V_254 &= ~ V_255 ;
switch ( V_145 -> V_256 ) {
case 8 :
V_254 |= V_257 ;
break;
case 16 :
if ( V_145 -> V_258 != 16 )
return - V_246 ;
V_254 |= V_260 ;
break;
case 24 :
case 32 :
if ( V_145 -> V_258 == 24 )
V_254 |= V_261 ;
else if ( V_145 -> V_258 == 30 )
V_254 |= V_263 ;
else
return - V_246 ;
break;
default:
F_83 ( L_57 , V_145 -> V_256 ) ;
return - V_246 ;
}
if ( V_149 -> V_236 != V_244 )
V_254 |= V_262 ;
else
V_254 &= ~ V_262 ;
V_254 |= V_264 ;
F_23 ( V_70 , V_254 ) ;
V_252 = V_149 -> V_197 ;
V_253 = V_164 * V_145 -> V_155 + V_251 * ( V_145 -> V_256 / 8 ) ;
F_25 ( L_58 ,
V_252 , V_253 , V_251 , V_164 , V_145 -> V_155 ) ;
F_23 ( F_141 ( V_99 ) , V_145 -> V_155 ) ;
F_23 ( F_92 ( V_99 ) , V_252 ) ;
F_23 ( F_142 ( V_99 ) , ( V_164 << 16 ) | V_251 ) ;
F_23 ( F_91 ( V_99 ) , V_253 ) ;
F_72 ( V_70 ) ;
return 0 ;
}
static int
F_144 ( struct V_8 * V_9 , struct V_144 * V_145 ,
int V_251 , int V_164 , enum V_265 V_77 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_243 ;
V_243 = V_4 -> V_202 . V_266 ( V_9 , V_145 , V_251 , V_164 ) ;
if ( V_243 )
return V_243 ;
F_129 ( V_2 ) ;
F_145 ( V_9 ) ;
return 0 ;
}
static int
F_146 ( struct V_8 * V_9 , int V_251 , int V_164 ,
struct V_144 * V_267 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_268 * V_269 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_243 ;
if ( ! V_9 -> V_145 ) {
F_83 ( L_59 ) ;
return 0 ;
}
switch ( V_150 -> V_99 ) {
case 0 :
case 1 :
break;
case 2 :
if ( F_147 ( V_2 ) )
break;
default:
F_83 ( L_60 ) ;
return - V_246 ;
}
F_119 ( & V_2 -> V_208 ) ;
V_243 = F_133 ( V_2 ,
F_101 ( V_9 -> V_145 ) -> V_149 ,
NULL ) ;
if ( V_243 != 0 ) {
F_120 ( & V_2 -> V_208 ) ;
F_83 ( L_61 ) ;
return V_243 ;
}
if ( V_267 ) {
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_149 = F_101 ( V_267 ) -> V_149 ;
F_148 ( V_4 -> V_270 ,
F_149 ( & V_4 -> V_247 . V_271 ) ||
F_149 ( & V_149 -> V_272 ) == 0 ) ;
V_243 = F_150 ( V_149 ) ;
( void ) V_243 ;
}
V_243 = F_144 ( V_9 , V_9 -> V_145 , V_251 , V_164 ,
V_273 ) ;
if ( V_243 ) {
F_139 ( F_101 ( V_9 -> V_145 ) -> V_149 ) ;
F_120 ( & V_2 -> V_208 ) ;
F_83 ( L_62 ) ;
return V_243 ;
}
if ( V_267 ) {
F_21 ( V_2 , V_150 -> V_66 ) ;
F_139 ( F_101 ( V_267 ) -> V_149 ) ;
}
F_120 ( & V_2 -> V_208 ) ;
if ( ! V_2 -> V_274 -> V_275 )
return 0 ;
V_269 = V_2 -> V_274 -> V_275 -> V_276 ;
if ( ! V_269 -> V_277 )
return 0 ;
if ( V_150 -> V_66 ) {
V_269 -> V_277 -> V_278 = V_251 ;
V_269 -> V_277 -> V_279 = V_164 ;
} else {
V_269 -> V_277 -> V_280 = V_251 ;
V_269 -> V_277 -> V_281 = V_164 ;
}
return 0 ;
}
static void F_151 ( struct V_8 * V_9 , int clock )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_282 ;
F_25 ( L_63 , clock ) ;
V_282 = F_3 ( V_283 ) ;
V_282 &= ~ V_284 ;
if ( clock < 200000 ) {
T_1 V_285 ;
V_282 |= V_286 ;
V_285 = F_3 ( 0x4600c ) ;
V_285 &= 0xffff0000 ;
F_23 ( 0x4600c , V_285 | 0x8124 ) ;
V_285 = F_3 ( 0x46010 ) ;
F_23 ( 0x46010 , V_285 | 1 ) ;
V_285 = F_3 ( 0x46034 ) ;
F_23 ( 0x46034 , V_285 | ( 1 << 24 ) ) ;
} else {
V_282 |= V_287 ;
}
F_23 ( V_283 , V_282 ) ;
F_72 ( V_283 ) ;
F_73 ( 500 ) ;
}
static void F_152 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
T_1 V_70 , V_285 ;
V_70 = F_41 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
if ( F_147 ( V_2 ) ) {
V_285 &= ~ V_288 ;
V_285 |= V_288 | V_289 ;
} else {
V_285 &= ~ V_290 ;
V_285 |= V_290 | V_289 ;
}
F_23 ( V_70 , V_285 ) ;
V_70 = F_43 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
if ( F_38 ( V_2 ) ) {
V_285 &= ~ V_291 ;
V_285 |= V_292 ;
} else {
V_285 &= ~ V_290 ;
V_285 |= V_290 ;
}
F_23 ( V_70 , V_285 | V_293 ) ;
F_72 ( V_70 ) ;
F_73 ( 1000 ) ;
if ( F_147 ( V_2 ) )
F_23 ( V_70 , F_3 ( V_70 ) | V_294 |
V_295 ) ;
}
static void F_153 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_228 = F_3 ( V_296 ) ;
V_228 |= F_154 ( V_66 ) ;
F_23 ( V_296 , V_228 ) ;
V_228 |= F_155 ( V_66 ) ;
F_23 ( V_296 , V_228 ) ;
F_72 ( V_296 ) ;
}
static void F_156 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
int V_99 = V_150 -> V_99 ;
T_1 V_70 , V_285 , V_297 ;
F_94 ( V_4 , V_66 ) ;
F_49 ( V_4 , V_99 ) ;
V_70 = F_157 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ V_298 ;
V_285 &= ~ V_299 ;
F_23 ( V_70 , V_285 ) ;
F_3 ( V_70 ) ;
F_73 ( 150 ) ;
V_70 = F_41 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ ( 7 << 19 ) ;
V_285 |= ( V_150 -> V_300 - 1 ) << 19 ;
V_285 &= ~ V_290 ;
V_285 |= V_301 ;
F_23 ( V_70 , V_285 | V_83 ) ;
V_70 = F_43 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ V_290 ;
V_285 |= V_301 ;
F_23 ( V_70 , V_285 | V_84 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
if ( F_82 ( V_2 ) ) {
F_23 ( F_158 ( V_66 ) , V_302 ) ;
F_23 ( F_158 ( V_66 ) , V_302 |
V_303 ) ;
}
V_70 = F_159 ( V_66 ) ;
for ( V_297 = 0 ; V_297 < 5 ; V_297 ++ ) {
V_285 = F_3 ( V_70 ) ;
F_25 ( L_64 , V_285 ) ;
if ( ( V_285 & V_299 ) ) {
F_25 ( L_65 ) ;
F_23 ( V_70 , V_285 | V_299 ) ;
break;
}
}
if ( V_297 == 5 )
F_83 ( L_66 ) ;
V_70 = F_41 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ V_290 ;
V_285 |= V_304 ;
F_23 ( V_70 , V_285 ) ;
V_70 = F_43 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ V_290 ;
V_285 |= V_304 ;
F_23 ( V_70 , V_285 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
V_70 = F_159 ( V_66 ) ;
for ( V_297 = 0 ; V_297 < 5 ; V_297 ++ ) {
V_285 = F_3 ( V_70 ) ;
F_25 ( L_64 , V_285 ) ;
if ( V_285 & V_298 ) {
F_23 ( V_70 , V_285 | V_298 ) ;
F_25 ( L_67 ) ;
break;
}
}
if ( V_297 == 5 )
F_83 ( L_68 ) ;
F_25 ( L_69 ) ;
}
static void F_160 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
T_1 V_70 , V_285 , V_101 ;
V_70 = F_157 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ V_298 ;
V_285 &= ~ V_299 ;
F_23 ( V_70 , V_285 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
V_70 = F_41 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ ( 7 << 19 ) ;
V_285 |= ( V_150 -> V_300 - 1 ) << 19 ;
V_285 &= ~ V_290 ;
V_285 |= V_301 ;
V_285 &= ~ V_305 ;
V_285 |= V_306 ;
F_23 ( V_70 , V_285 | V_83 ) ;
V_70 = F_43 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
if ( F_38 ( V_2 ) ) {
V_285 &= ~ V_291 ;
V_285 |= V_307 ;
} else {
V_285 &= ~ V_290 ;
V_285 |= V_301 ;
}
F_23 ( V_70 , V_285 | V_84 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
if ( F_38 ( V_2 ) )
F_153 ( V_2 , V_66 ) ;
for ( V_101 = 0 ; V_101 < 4 ; V_101 ++ ) {
V_70 = F_41 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ V_305 ;
V_285 |= V_308 [ V_101 ] ;
F_23 ( V_70 , V_285 ) ;
F_72 ( V_70 ) ;
F_73 ( 500 ) ;
V_70 = F_159 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
F_25 ( L_64 , V_285 ) ;
if ( V_285 & V_299 ) {
F_23 ( V_70 , V_285 | V_299 ) ;
F_25 ( L_65 ) ;
break;
}
}
if ( V_101 == 4 )
F_83 ( L_66 ) ;
V_70 = F_41 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ V_290 ;
V_285 |= V_304 ;
if ( F_112 ( V_2 ) ) {
V_285 &= ~ V_305 ;
V_285 |= V_306 ;
}
F_23 ( V_70 , V_285 ) ;
V_70 = F_43 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
if ( F_38 ( V_2 ) ) {
V_285 &= ~ V_291 ;
V_285 |= V_309 ;
} else {
V_285 &= ~ V_290 ;
V_285 |= V_304 ;
}
F_23 ( V_70 , V_285 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
for ( V_101 = 0 ; V_101 < 4 ; V_101 ++ ) {
V_70 = F_41 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ V_305 ;
V_285 |= V_308 [ V_101 ] ;
F_23 ( V_70 , V_285 ) ;
F_72 ( V_70 ) ;
F_73 ( 500 ) ;
V_70 = F_159 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
F_25 ( L_64 , V_285 ) ;
if ( V_285 & V_298 ) {
F_23 ( V_70 , V_285 | V_298 ) ;
F_25 ( L_67 ) ;
break;
}
}
if ( V_101 == 4 )
F_83 ( L_68 ) ;
F_25 ( L_70 ) ;
}
static void F_161 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
T_1 V_70 , V_285 , V_101 ;
V_70 = F_157 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ V_298 ;
V_285 &= ~ V_299 ;
F_23 ( V_70 , V_285 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
V_70 = F_41 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ ( 7 << 19 ) ;
V_285 |= ( V_150 -> V_300 - 1 ) << 19 ;
V_285 &= ~ ( V_310 | V_288 ) ;
V_285 |= V_311 ;
V_285 &= ~ V_305 ;
V_285 |= V_306 ;
V_285 |= V_312 ;
F_23 ( V_70 , V_285 | V_83 ) ;
V_70 = F_43 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ V_310 ;
V_285 &= ~ V_291 ;
V_285 |= V_307 ;
V_285 |= V_312 ;
F_23 ( V_70 , V_285 | V_84 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
if ( F_38 ( V_2 ) )
F_153 ( V_2 , V_66 ) ;
for ( V_101 = 0 ; V_101 < 4 ; V_101 ++ ) {
V_70 = F_41 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ V_305 ;
V_285 |= V_308 [ V_101 ] ;
F_23 ( V_70 , V_285 ) ;
F_72 ( V_70 ) ;
F_73 ( 500 ) ;
V_70 = F_159 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
F_25 ( L_64 , V_285 ) ;
if ( V_285 & V_299 ||
( F_3 ( V_70 ) & V_299 ) ) {
F_23 ( V_70 , V_285 | V_299 ) ;
F_25 ( L_65 ) ;
break;
}
}
if ( V_101 == 4 )
F_83 ( L_66 ) ;
V_70 = F_41 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ V_288 ;
V_285 |= V_313 ;
V_285 &= ~ V_305 ;
V_285 |= V_306 ;
F_23 ( V_70 , V_285 ) ;
V_70 = F_43 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ V_291 ;
V_285 |= V_309 ;
F_23 ( V_70 , V_285 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
for ( V_101 = 0 ; V_101 < 4 ; V_101 ++ ) {
V_70 = F_41 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ V_305 ;
V_285 |= V_308 [ V_101 ] ;
F_23 ( V_70 , V_285 ) ;
F_72 ( V_70 ) ;
F_73 ( 500 ) ;
V_70 = F_159 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
F_25 ( L_64 , V_285 ) ;
if ( V_285 & V_298 ) {
F_23 ( V_70 , V_285 | V_298 ) ;
F_25 ( L_67 ) ;
break;
}
}
if ( V_101 == 4 )
F_83 ( L_68 ) ;
F_25 ( L_70 ) ;
}
static void F_162 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
T_1 V_70 , V_285 ;
F_23 ( F_163 ( V_66 ) ,
F_3 ( F_164 ( V_66 ) ) & V_314 ) ;
V_70 = F_43 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ ( ( 0x7 << 19 ) | ( 0x7 << 16 ) ) ;
V_285 |= ( V_150 -> V_300 - 1 ) << 19 ;
V_285 |= ( F_3 ( F_28 ( V_66 ) ) & V_135 ) << 11 ;
F_23 ( V_70 , V_285 | V_87 ) ;
F_72 ( V_70 ) ;
F_73 ( 200 ) ;
V_285 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_285 | V_315 ) ;
F_72 ( V_70 ) ;
F_73 ( 200 ) ;
V_70 = F_41 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
if ( ( V_285 & V_86 ) == 0 ) {
F_23 ( V_70 , V_285 | V_86 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
}
}
static void F_165 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_228 = F_3 ( V_296 ) ;
V_228 &= ~ ( F_155 ( V_66 ) ) ;
F_23 ( V_296 , V_228 ) ;
V_228 &= ~ ( F_154 ( V_66 ) ) ;
F_23 ( V_296 , V_228 ) ;
F_72 ( V_296 ) ;
}
static void F_166 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
T_1 V_70 , V_285 ;
V_70 = F_41 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_285 & ~ V_83 ) ;
F_72 ( V_70 ) ;
V_70 = F_43 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ ( 0x7 << 16 ) ;
V_285 |= ( F_3 ( F_28 ( V_66 ) ) & V_135 ) << 11 ;
F_23 ( V_70 , V_285 & ~ V_84 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
if ( F_82 ( V_2 ) ) {
F_23 ( F_158 ( V_66 ) , V_302 ) ;
F_23 ( F_158 ( V_66 ) ,
F_3 ( F_158 ( V_66 ) &
~ V_303 ) ) ;
} else if ( F_38 ( V_2 ) ) {
F_165 ( V_2 , V_66 ) ;
}
V_70 = F_41 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ V_290 ;
V_285 |= V_301 ;
F_23 ( V_70 , V_285 ) ;
V_70 = F_43 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
if ( F_38 ( V_2 ) ) {
V_285 &= ~ V_291 ;
V_285 |= V_307 ;
} else {
V_285 &= ~ V_290 ;
V_285 |= V_301 ;
}
V_285 &= ~ ( 0x07 << 16 ) ;
V_285 |= ( F_3 ( F_28 ( V_66 ) ) & V_135 ) << 11 ;
F_23 ( V_70 , V_285 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_240 * V_316 ;
T_1 V_317 ;
if ( F_11 ( V_2 ) )
return;
V_316 = F_168 ( V_4 ) ;
V_317 = F_169 ( V_316 ) ;
if ( V_317 & V_318 )
F_170 ( V_316 , V_317 ) ;
}
static void F_171 ( struct V_8 * V_9 )
{
struct V_148 * V_149 ;
struct V_3 * V_4 ;
if ( V_9 -> V_145 == NULL )
return;
V_149 = F_101 ( V_9 -> V_145 ) -> V_149 ;
V_4 = V_9 -> V_2 -> V_5 ;
F_148 ( V_4 -> V_270 ,
F_149 ( & V_149 -> V_272 ) == 0 ) ;
}
static bool F_172 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_319 :
if ( ! F_173 ( & V_51 -> V_52 ) )
return false ;
continue;
}
}
return true ;
}
static void F_174 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
T_1 V_70 , V_285 , V_320 ;
V_4 -> V_202 . V_321 ( V_9 ) ;
F_76 ( V_4 , V_66 ) ;
if ( F_38 ( V_2 ) ) {
V_320 = V_150 -> V_322 ? V_323 :
V_324 ;
V_285 = F_3 ( V_82 ) ;
if ( V_66 == 0 ) {
V_285 &= ~ ( V_325 ) ;
V_285 |= ( V_326 | V_327 ) ;
} else if ( V_66 == 1 ) {
V_285 &= ~ ( V_328 ) ;
V_285 |= ( V_329 | V_328 ) ;
} else if ( V_66 == 2 ) {
V_285 &= ~ ( V_324 ) ;
V_285 |= ( V_330 | V_320 ) ;
}
F_23 ( V_82 , V_285 ) ;
}
F_46 ( V_4 , V_66 ) ;
F_23 ( F_175 ( V_66 ) , F_3 ( F_176 ( V_66 ) ) ) ;
F_23 ( F_177 ( V_66 ) , F_3 ( F_178 ( V_66 ) ) ) ;
F_23 ( F_179 ( V_66 ) , F_3 ( F_180 ( V_66 ) ) ) ;
F_23 ( F_181 ( V_66 ) , F_3 ( F_182 ( V_66 ) ) ) ;
F_23 ( F_183 ( V_66 ) , F_3 ( F_184 ( V_66 ) ) ) ;
F_23 ( F_185 ( V_66 ) , F_3 ( F_186 ( V_66 ) ) ) ;
F_152 ( V_9 ) ;
if ( F_38 ( V_2 ) &&
( F_5 ( V_9 , V_20 ) ||
F_5 ( V_9 , V_319 ) ) ) {
T_1 V_331 = ( F_3 ( F_28 ( V_66 ) ) & V_135 ) >> 5 ;
V_70 = F_57 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ ( V_114 |
V_332 |
V_333 ) ;
V_285 |= ( V_334 |
V_335 ) ;
V_285 |= V_331 << 9 ;
if ( V_9 -> V_227 . V_228 & V_336 )
V_285 |= V_337 ;
if ( V_9 -> V_227 . V_228 & V_338 )
V_285 |= V_339 ;
switch ( F_187 ( V_9 ) ) {
case V_123 :
V_285 |= V_124 ;
break;
case V_125 :
V_285 |= V_126 ;
break;
case V_127 :
V_285 |= V_128 ;
break;
default:
F_25 ( L_71 ) ;
V_285 |= V_124 ;
break;
}
F_23 ( V_70 , V_285 ) ;
}
F_78 ( V_4 , V_66 ) ;
}
void F_188 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_340 = F_29 ( V_66 ) , V_341 = F_189 ( V_66 ) ;
T_1 V_285 ;
V_285 = F_3 ( V_340 ) ;
F_73 ( 500 ) ;
if ( F_24 ( F_3 ( V_340 ) != V_285 , 5 ) ) {
F_23 ( V_341 , V_342 ) ;
F_73 ( 250 ) ;
F_23 ( V_341 , 0 ) ;
if ( F_24 ( F_3 ( V_340 ) != V_285 , 5 ) )
F_83 ( L_72 , V_66 ) ;
}
}
static void F_190 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
int V_99 = V_150 -> V_99 ;
T_1 V_285 ;
bool V_343 ;
if ( V_150 -> V_344 )
return;
V_150 -> V_344 = true ;
F_191 ( V_2 ) ;
if ( F_5 ( V_9 , V_12 ) ) {
V_285 = F_3 ( V_13 ) ;
if ( ( V_285 & V_119 ) == 0 )
F_23 ( V_13 , V_285 | V_119 ) ;
}
V_343 = F_172 ( V_9 ) ;
if ( V_343 )
F_162 ( V_9 ) ;
else
F_166 ( V_9 ) ;
if ( V_4 -> V_345 &&
( F_5 ( V_9 , V_12 ) || V_21 ) ) {
F_23 ( F_192 ( V_66 ) , V_346 | V_347 ) ;
F_23 ( F_193 ( V_66 ) , V_4 -> V_348 ) ;
F_23 ( F_194 ( V_66 ) , V_4 -> V_345 ) ;
}
F_195 ( V_9 ) ;
F_87 ( V_4 , V_66 , V_343 ) ;
F_93 ( V_4 , V_99 , V_66 ) ;
if ( V_343 )
F_174 ( V_9 ) ;
F_119 ( & V_2 -> V_208 ) ;
F_129 ( V_2 ) ;
F_120 ( & V_2 -> V_208 ) ;
F_196 ( V_9 , true ) ;
}
static void F_197 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
int V_99 = V_150 -> V_99 ;
T_1 V_70 , V_285 ;
if ( ! V_150 -> V_344 )
return;
F_171 ( V_9 ) ;
F_198 ( V_2 , V_66 ) ;
F_196 ( V_9 , false ) ;
F_95 ( V_4 , V_99 , V_66 ) ;
if ( V_4 -> V_211 == V_99 )
F_128 ( V_2 ) ;
F_89 ( V_4 , V_66 ) ;
F_23 ( F_192 ( V_66 ) , 0 ) ;
F_23 ( F_194 ( V_66 ) , 0 ) ;
F_166 ( V_9 ) ;
F_98 ( V_4 , V_66 ) ;
F_84 ( V_4 , V_66 ) ;
if ( F_38 ( V_2 ) ) {
V_70 = F_57 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
V_285 &= ~ ( V_334 | V_114 ) ;
V_285 |= V_349 ;
F_23 ( V_70 , V_285 ) ;
V_285 = F_3 ( V_82 ) ;
switch ( V_66 ) {
case 0 :
V_285 &= ~ ( V_326 | V_325 ) ;
break;
case 1 :
V_285 &= ~ ( V_329 | V_328 ) ;
break;
case 2 :
V_285 &= ~ ( V_330 | V_324 ) ;
break;
default:
F_136 () ;
}
F_23 ( V_82 , V_285 ) ;
}
if ( ! V_150 -> V_350 )
F_77 ( V_4 , V_66 ) ;
V_70 = F_43 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_285 & ~ V_315 ) ;
V_70 = F_41 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_285 & ~ V_86 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
V_70 = F_43 ( V_66 ) ;
V_285 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_285 & ~ V_87 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
V_150 -> V_344 = false ;
F_191 ( V_2 ) ;
F_119 ( & V_2 -> V_208 ) ;
F_129 ( V_2 ) ;
F_167 ( V_2 ) ;
F_120 ( & V_2 -> V_208 ) ;
}
static void F_199 ( struct V_8 * V_9 , int V_227 )
{
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
int V_99 = V_150 -> V_99 ;
switch ( V_227 ) {
case V_351 :
case V_352 :
case V_353 :
F_25 ( L_73 , V_66 , V_99 ) ;
F_190 ( V_9 ) ;
break;
case V_354 :
F_25 ( L_74 , V_66 , V_99 ) ;
F_197 ( V_9 ) ;
break;
}
}
static void F_200 ( struct V_150 * V_150 , bool V_355 )
{
if ( ! V_355 && V_150 -> V_356 ) {
struct V_1 * V_2 = V_150 -> V_52 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_119 ( & V_2 -> V_208 ) ;
V_4 -> V_247 . V_248 = false ;
( void ) F_201 ( V_150 -> V_356 ) ;
V_4 -> V_247 . V_248 = true ;
F_120 ( & V_2 -> V_208 ) ;
}
}
static void F_202 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
int V_99 = V_150 -> V_99 ;
if ( V_150 -> V_344 )
return;
V_150 -> V_344 = true ;
F_191 ( V_2 ) ;
F_68 ( V_4 , V_66 ) ;
F_87 ( V_4 , V_66 , false ) ;
F_93 ( V_4 , V_99 , V_66 ) ;
F_195 ( V_9 ) ;
F_129 ( V_2 ) ;
F_200 ( V_150 , true ) ;
F_196 ( V_9 , true ) ;
}
static void F_203 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
int V_99 = V_150 -> V_99 ;
if ( ! V_150 -> V_344 )
return;
F_171 ( V_9 ) ;
F_198 ( V_2 , V_66 ) ;
F_200 ( V_150 , false ) ;
F_196 ( V_9 , false ) ;
if ( V_4 -> V_211 == V_99 )
F_128 ( V_2 ) ;
F_95 ( V_4 , V_99 , V_66 ) ;
F_89 ( V_4 , V_66 ) ;
F_74 ( V_4 , V_66 ) ;
V_150 -> V_344 = false ;
F_129 ( V_2 ) ;
F_191 ( V_2 ) ;
F_167 ( V_2 ) ;
}
static void F_204 ( struct V_8 * V_9 , int V_227 )
{
switch ( V_227 ) {
case V_351 :
case V_352 :
case V_353 :
F_202 ( V_9 ) ;
break;
case V_354 :
F_203 ( V_9 ) ;
break;
}
}
static void F_205 ( struct V_8 * V_9 , int V_227 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_268 * V_269 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
bool V_76 ;
if ( V_150 -> V_357 == V_227 )
return;
V_150 -> V_357 = V_227 ;
V_4 -> V_202 . V_358 ( V_9 , V_227 ) ;
if ( ! V_2 -> V_274 -> V_275 )
return;
V_269 = V_2 -> V_274 -> V_275 -> V_276 ;
if ( ! V_269 -> V_277 )
return;
V_76 = V_9 -> V_76 && V_227 != V_354 ;
switch ( V_66 ) {
case 0 :
V_269 -> V_277 -> V_359 = V_76 ? V_9 -> V_227 . V_232 : 0 ;
V_269 -> V_277 -> V_360 = V_76 ? V_9 -> V_227 . V_233 : 0 ;
break;
case 1 :
V_269 -> V_277 -> V_361 = V_76 ? V_9 -> V_227 . V_232 : 0 ;
V_269 -> V_277 -> V_362 = V_76 ? V_9 -> V_227 . V_233 : 0 ;
break;
default:
F_83 ( L_75 , F_47 ( V_66 ) ) ;
break;
}
}
static void F_206 ( struct V_8 * V_9 )
{
struct V_363 * V_364 = V_9 -> V_365 ;
struct V_1 * V_2 = V_9 -> V_2 ;
V_364 -> V_358 ( V_9 , V_354 ) ;
if ( V_9 -> V_145 ) {
F_119 ( & V_2 -> V_208 ) ;
F_139 ( F_101 ( V_9 -> V_145 ) -> V_149 ) ;
F_120 ( & V_2 -> V_208 ) ;
}
}
static void F_207 ( struct V_8 * V_9 )
{
F_203 ( V_9 ) ;
}
static void F_208 ( struct V_8 * V_9 )
{
F_202 ( V_9 ) ;
}
static void F_209 ( struct V_8 * V_9 )
{
F_197 ( V_9 ) ;
}
static void F_210 ( struct V_8 * V_9 )
{
F_190 ( V_9 ) ;
}
void F_211 ( struct V_366 * V_51 )
{
struct V_367 * V_368 = V_51 -> V_365 ;
V_368 -> V_358 ( V_51 , V_354 ) ;
}
void F_212 ( struct V_366 * V_51 )
{
struct V_367 * V_368 = V_51 -> V_365 ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_50 * V_50 = F_213 ( V_51 ) ;
struct V_150 * V_150 = F_102 ( V_50 -> V_52 . V_9 ) ;
V_368 -> V_358 ( V_51 , V_351 ) ;
if ( F_38 ( V_2 ) )
F_188 ( V_2 , V_150 -> V_66 ) ;
}
void F_214 ( struct V_366 * V_51 )
{
struct V_50 * V_50 = F_213 ( V_51 ) ;
F_215 ( V_51 ) ;
F_121 ( V_50 ) ;
}
static bool F_216 ( struct V_8 * V_9 ,
struct V_369 * V_227 ,
struct V_369 * V_370 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
if ( F_8 ( V_2 ) ) {
if ( V_227 -> clock * 3 > V_371 * 4 )
return false ;
}
if ( V_370 -> V_372 == 0 )
F_217 ( V_370 , 0 ) ;
return true ;
}
static int F_218 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_219 ( struct V_1 * V_2 )
{
return 333000 ;
}
static int F_220 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_221 ( struct V_1 * V_2 )
{
T_4 V_373 = 0 ;
F_222 ( V_2 -> V_374 , V_375 , & V_373 ) ;
if ( V_373 & V_376 )
return 133000 ;
else {
switch ( V_373 & V_377 ) {
case V_378 :
return 333000 ;
default:
case V_379 :
return 190000 ;
}
}
}
static int F_223 ( struct V_1 * V_2 )
{
return 266000 ;
}
static int F_224 ( struct V_1 * V_2 )
{
T_4 V_380 = 0 ;
switch ( V_380 & V_381 ) {
case V_382 :
case V_383 :
return 200000 ;
case V_384 :
return 250000 ;
case V_385 :
return 133000 ;
}
return 0 ;
}
static int F_225 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_226 ( T_1 * V_386 , T_1 * V_387 )
{
while ( * V_386 > 0xffffff || * V_387 > 0xffffff ) {
* V_386 >>= 1 ;
* V_387 >>= 1 ;
}
}
static void
F_227 ( int V_256 , int V_388 , int V_389 ,
int V_390 , struct V_391 * V_392 )
{
V_392 -> V_393 = 64 ;
V_392 -> V_394 = V_256 * V_389 ;
V_392 -> V_395 = V_390 * V_388 * 8 ;
F_226 ( & V_392 -> V_394 , & V_392 -> V_395 ) ;
V_392 -> V_396 = V_389 ;
V_392 -> V_397 = V_390 ;
F_226 ( & V_392 -> V_396 , & V_392 -> V_397 ) ;
}
static unsigned long F_228 ( unsigned long V_398 ,
const struct V_399 * V_400 ,
int V_401 ,
int V_402 ,
unsigned long V_403 )
{
long V_404 , V_405 ;
V_404 = ( ( V_398 / 1000 ) * V_402 * V_403 ) /
1000 ;
V_404 = F_229 ( V_404 , V_400 -> V_406 ) ;
F_25 ( L_76 , V_404 ) ;
V_405 = V_401 - ( V_404 + V_400 -> V_407 ) ;
F_25 ( L_77 , V_405 ) ;
if ( V_405 > ( long ) V_400 -> V_408 )
V_405 = V_400 -> V_408 ;
if ( V_405 <= 0 )
V_405 = V_400 -> V_409 ;
return V_405 ;
}
static const struct V_410 * F_230 ( int V_411 ,
int V_412 ,
int V_413 ,
int V_414 )
{
const struct V_410 * V_415 ;
int V_101 ;
if ( V_413 == 0 || V_414 == 0 )
return NULL ;
for ( V_101 = 0 ; V_101 < F_231 ( V_416 ) ; V_101 ++ ) {
V_415 = & V_416 [ V_101 ] ;
if ( V_411 == V_415 -> V_411 &&
V_412 == V_415 -> V_412 &&
V_413 == V_415 -> V_417 && V_414 == V_415 -> V_418 )
return V_415 ;
}
F_25 ( L_78 ) ;
return NULL ;
}
static void F_232 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_419 , F_3 ( V_419 ) & ~ V_420 ) ;
}
static int F_233 ( struct V_1 * V_2 , int V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_421 = F_3 ( V_422 ) ;
int V_225 ;
V_225 = V_421 & 0x7f ;
if ( V_99 )
V_225 = ( ( V_421 >> V_423 ) & 0x7f ) - V_225 ;
F_25 ( L_79 , V_421 ,
V_99 ? L_80 : L_81 , V_225 ) ;
return V_225 ;
}
static int F_234 ( struct V_1 * V_2 , int V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_421 = F_3 ( V_422 ) ;
int V_225 ;
V_225 = V_421 & 0x1ff ;
if ( V_99 )
V_225 = ( ( V_421 >> V_424 ) & 0x1ff ) - V_225 ;
V_225 >>= 1 ;
F_25 ( L_79 , V_421 ,
V_99 ? L_80 : L_81 , V_225 ) ;
return V_225 ;
}
static int F_235 ( struct V_1 * V_2 , int V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_421 = F_3 ( V_422 ) ;
int V_225 ;
V_225 = V_421 & 0x7f ;
V_225 >>= 2 ;
F_25 ( L_79 , V_421 ,
V_99 ? L_80 : L_81 ,
V_225 ) ;
return V_225 ;
}
static int F_236 ( struct V_1 * V_2 , int V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_421 = F_3 ( V_422 ) ;
int V_225 ;
V_225 = V_421 & 0x7f ;
V_225 >>= 1 ;
F_25 ( L_79 , V_421 ,
V_99 ? L_80 : L_81 , V_225 ) ;
return V_225 ;
}
static struct V_8 * F_237 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_76 = NULL ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_9 -> V_76 && V_9 -> V_145 ) {
if ( V_76 )
return NULL ;
V_76 = V_9 ;
}
}
return V_76 ;
}
static void F_238 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
const struct V_410 * V_415 ;
T_1 V_70 ;
unsigned long V_400 ;
V_415 = F_230 ( F_239 ( V_2 ) , V_4 -> V_412 ,
V_4 -> V_417 , V_4 -> V_418 ) ;
if ( ! V_415 ) {
F_25 ( L_78 ) ;
F_232 ( V_2 ) ;
return;
}
V_9 = F_237 ( V_2 ) ;
if ( V_9 ) {
int clock = V_9 -> V_227 . clock ;
int V_402 = V_9 -> V_145 -> V_256 / 8 ;
V_400 = F_228 ( clock , & V_425 ,
V_425 . V_401 ,
V_402 , V_415 -> V_426 ) ;
V_70 = F_3 ( V_427 ) ;
V_70 &= ~ V_428 ;
V_70 |= V_400 << V_429 ;
F_23 ( V_427 , V_70 ) ;
F_25 ( L_82 , V_70 ) ;
V_400 = F_228 ( clock , & V_430 ,
V_425 . V_401 ,
V_402 , V_415 -> V_431 ) ;
V_70 = F_3 ( V_419 ) ;
V_70 &= ~ V_432 ;
V_70 |= ( V_400 & 0x3f ) << V_433 ;
F_23 ( V_419 , V_70 ) ;
V_400 = F_228 ( clock , & V_434 ,
V_434 . V_401 ,
V_402 , V_415 -> V_435 ) ;
V_70 = F_3 ( V_419 ) ;
V_70 &= ~ V_436 ;
V_70 |= V_400 & V_436 ;
F_23 ( V_419 , V_70 ) ;
V_400 = F_228 ( clock , & V_437 ,
V_434 . V_401 ,
V_402 , V_415 -> V_438 ) ;
V_70 = F_3 ( V_419 ) ;
V_70 &= ~ V_439 ;
V_70 |= ( V_400 & 0x3f ) << V_440 ;
F_23 ( V_419 , V_70 ) ;
F_25 ( L_83 , V_70 ) ;
F_23 ( V_419 ,
F_3 ( V_419 ) | V_420 ) ;
F_25 ( L_84 ) ;
} else {
F_232 ( V_2 ) ;
F_25 ( L_85 ) ;
}
}
static bool F_240 ( struct V_1 * V_2 ,
int V_99 ,
const struct V_399 * V_202 ,
int V_441 ,
const struct V_399 * V_442 ,
int V_443 ,
int * V_444 ,
int * V_445 )
{
struct V_8 * V_9 ;
int V_446 , V_232 , clock , V_402 ;
int V_447 , V_448 ;
int V_449 , V_450 ;
V_9 = F_241 ( V_2 , V_99 ) ;
if ( V_9 -> V_145 == NULL || ! V_9 -> V_76 ) {
* V_445 = V_442 -> V_407 ;
* V_444 = V_202 -> V_407 ;
return false ;
}
V_446 = V_9 -> V_227 . V_446 ;
V_232 = V_9 -> V_227 . V_232 ;
clock = V_9 -> V_227 . clock ;
V_402 = V_9 -> V_145 -> V_256 / 8 ;
V_449 = ( ( clock * V_402 / 1000 ) * V_441 ) / 1000 ;
V_450 = V_202 -> V_401 * V_202 -> V_406 - V_232 * 8 ;
if ( V_450 > 0 )
V_449 += V_450 ;
V_449 = F_229 ( V_449 , V_202 -> V_406 ) ;
* V_444 = V_449 + V_202 -> V_407 ;
if ( * V_444 > ( int ) V_202 -> V_408 )
* V_444 = V_202 -> V_408 ;
V_447 = ( ( V_446 * 1000 ) / clock ) ;
V_448 = ( V_443 / V_447 + 1000 ) / 1000 ;
V_449 = V_448 * 64 * V_402 ;
V_450 = V_442 -> V_401 * V_442 -> V_406 - V_232 * 8 ;
if ( V_450 > 0 )
V_449 += V_450 ;
V_449 = F_229 ( V_449 , V_442 -> V_406 ) ;
* V_445 = V_449 + V_442 -> V_407 ;
if ( * V_445 > ( int ) V_442 -> V_408 )
* V_445 = ( int ) V_442 -> V_408 ;
return true ;
}
static bool F_242 ( struct V_1 * V_2 ,
int V_451 , int V_445 ,
const struct V_399 * V_202 ,
const struct V_399 * V_442 )
{
F_25 ( L_86 ,
V_451 , V_445 ) ;
if ( V_451 > V_202 -> V_408 ) {
F_25 ( L_87 ,
V_451 , V_202 -> V_408 ) ;
return false ;
}
if ( V_445 > V_442 -> V_408 ) {
F_25 ( L_88 ,
V_445 , V_442 -> V_408 ) ;
return false ;
}
if ( ! ( V_451 || V_445 ) ) {
F_25 ( L_89 ) ;
return false ;
}
return true ;
}
static bool F_243 ( struct V_1 * V_2 ,
int V_99 ,
int V_403 ,
const struct V_399 * V_202 ,
const struct V_399 * V_442 ,
int * V_451 , int * V_445 )
{
struct V_8 * V_9 ;
int V_232 , V_446 , V_402 , clock ;
unsigned long V_447 ;
int V_448 , V_452 ;
int V_453 , V_454 ;
int V_449 ;
if ( ! V_403 ) {
* V_451 = * V_445 = 0 ;
return false ;
}
V_9 = F_241 ( V_2 , V_99 ) ;
V_232 = V_9 -> V_227 . V_232 ;
V_446 = V_9 -> V_227 . V_446 ;
clock = V_9 -> V_227 . clock ;
V_402 = V_9 -> V_145 -> V_256 / 8 ;
V_447 = ( V_446 * 1000 ) / clock ;
V_448 = ( V_403 / V_447 + 1000 ) / 1000 ;
V_452 = V_232 * V_402 ;
V_453 = ( ( clock * V_402 / 1000 ) * V_403 ) / 1000 ;
V_454 = V_448 * V_452 ;
V_449 = F_229 ( V_53 ( V_453 , V_454 ) , V_202 -> V_406 ) ;
* V_451 = V_449 + V_202 -> V_407 ;
V_449 = V_448 * V_402 * 64 ;
V_449 = F_229 ( V_449 , V_442 -> V_406 ) ;
* V_445 = V_449 + V_442 -> V_407 ;
return F_242 ( V_2 ,
* V_451 , * V_445 ,
V_202 , V_442 ) ;
}
static void F_244 ( struct V_1 * V_2 )
{
static const int V_455 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_456 , V_457 , V_458 , V_459 ;
int V_460 , V_431 ;
unsigned int V_76 = 0 ;
if ( F_240 ( V_2 , 0 ,
& V_461 , V_403 ,
& V_462 , V_403 ,
& V_456 , & V_458 ) )
V_76 |= 1 ;
if ( F_240 ( V_2 , 1 ,
& V_461 , V_403 ,
& V_462 , V_403 ,
& V_457 , & V_459 ) )
V_76 |= 2 ;
V_460 = V_431 = 0 ;
if ( F_245 ( V_76 ) &&
F_243 ( V_2 , F_246 ( V_76 ) - 1 ,
V_455 ,
& V_461 ,
& V_462 ,
& V_460 , & V_431 ) )
F_23 ( V_463 , V_464 ) ;
else
F_23 ( V_463 ,
F_3 ( V_463 ) & ~ V_464 ) ;
F_25 ( L_90 ,
V_456 , V_458 ,
V_457 , V_459 ,
V_460 , V_431 ) ;
F_23 ( V_427 ,
( V_460 << V_429 ) |
( V_459 << V_465 ) |
( V_457 << V_466 ) |
V_456 ) ;
F_23 ( V_467 ,
( F_3 ( V_467 ) & V_468 ) |
( V_458 << V_469 ) ) ;
F_23 ( V_419 ,
( F_3 ( V_419 ) & ~ V_470 ) |
( V_431 << V_433 ) ) ;
}
static void F_247 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
int V_471 = 1 ;
int V_431 = 16 ;
V_9 = F_237 ( V_2 ) ;
if ( V_9 ) {
static const int V_455 = 12000 ;
int clock = V_9 -> V_227 . clock ;
int V_446 = V_9 -> V_227 . V_446 ;
int V_232 = V_9 -> V_227 . V_232 ;
int V_402 = V_9 -> V_145 -> V_256 / 8 ;
unsigned long V_447 ;
int V_449 ;
V_447 = ( ( V_446 * 1000 ) / clock ) ;
V_449 = ( ( ( V_455 / V_447 ) + 1000 ) / 1000 ) *
V_402 * V_232 ;
V_449 = F_229 ( V_449 , V_472 ) ;
V_471 = V_473 - V_449 ;
if ( V_471 < 0 )
V_471 = 1 ;
V_471 &= 0x1ff ;
F_25 ( L_91 ,
V_449 , V_471 ) ;
V_449 = ( ( ( V_455 / V_447 ) + 1000 ) / 1000 ) *
V_402 * 64 ;
V_449 = F_229 ( V_449 ,
V_474 . V_406 ) ;
V_431 = V_474 . V_401 -
( V_449 + V_474 . V_407 ) ;
if ( V_431 > V_474 . V_408 )
V_431 = V_474 . V_408 ;
F_25 ( L_92
L_93 , V_471 , V_431 ) ;
if ( F_135 ( V_2 ) )
F_23 ( V_463 , V_464 ) ;
} else {
if ( F_135 ( V_2 ) )
F_23 ( V_463 , F_3 ( V_463 )
& ~ V_464 ) ;
}
F_25 ( L_94 ,
V_471 ) ;
F_23 ( V_427 , ( V_471 << V_429 ) |
( 8 << 16 ) | ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_23 ( V_467 , ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_23 ( V_419 , ( V_431 << V_433 ) ) ;
}
static void F_248 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_399 * V_475 ;
T_5 V_476 ;
T_5 V_477 ;
int V_478 , V_471 = 1 ;
int V_401 ;
int V_456 , V_457 ;
struct V_8 * V_9 , * V_76 = NULL ;
if ( F_103 ( V_2 ) )
V_475 = & V_479 ;
else if ( ! F_11 ( V_2 ) )
V_475 = & V_480 ;
else
V_475 = & V_481 ;
V_401 = V_4 -> V_202 . V_482 ( V_2 , 0 ) ;
V_9 = F_241 ( V_2 , 0 ) ;
if ( V_9 -> V_76 && V_9 -> V_145 ) {
V_456 = F_228 ( V_9 -> V_227 . clock ,
V_475 , V_401 ,
V_9 -> V_145 -> V_256 / 8 ,
V_403 ) ;
V_76 = V_9 ;
} else
V_456 = V_401 - V_475 -> V_407 ;
V_401 = V_4 -> V_202 . V_482 ( V_2 , 1 ) ;
V_9 = F_241 ( V_2 , 1 ) ;
if ( V_9 -> V_76 && V_9 -> V_145 ) {
V_457 = F_228 ( V_9 -> V_227 . clock ,
V_475 , V_401 ,
V_9 -> V_145 -> V_256 / 8 ,
V_403 ) ;
if ( V_76 == NULL )
V_76 = V_9 ;
else
V_76 = NULL ;
} else
V_457 = V_401 - V_475 -> V_407 ;
F_25 ( L_95 , V_456 , V_457 ) ;
V_478 = 2 ;
if ( F_249 ( V_2 ) || F_103 ( V_2 ) )
F_23 ( V_463 , V_483 | 0 ) ;
else if ( F_131 ( V_2 ) )
F_23 ( V_484 , F_3 ( V_484 ) & ~ V_485 ) ;
if ( F_250 ( V_2 ) && V_76 ) {
static const int V_455 = 6000 ;
int clock = V_76 -> V_227 . clock ;
int V_446 = V_76 -> V_227 . V_446 ;
int V_232 = V_76 -> V_227 . V_232 ;
int V_402 = V_76 -> V_145 -> V_256 / 8 ;
unsigned long V_447 ;
int V_449 ;
V_447 = ( V_446 * 1000 ) / clock ;
V_449 = ( ( ( V_455 / V_447 ) + 1000 ) / 1000 ) *
V_402 * V_232 ;
V_449 = F_229 ( V_449 , V_475 -> V_406 ) ;
F_25 ( L_96 , V_449 ) ;
V_471 = V_475 -> V_401 - V_449 ;
if ( V_471 < 0 )
V_471 = 1 ;
if ( F_249 ( V_2 ) || F_103 ( V_2 ) )
F_23 ( V_463 ,
V_486 | ( V_471 & 0xff ) ) ;
else if ( F_131 ( V_2 ) )
F_23 ( V_463 , V_471 & 0x3f ) ;
}
F_25 ( L_97 ,
V_456 , V_457 , V_478 , V_471 ) ;
V_476 = ( ( V_457 & 0x3f ) << 16 ) | ( V_456 & 0x3f ) ;
V_477 = ( V_478 & 0x1f ) ;
V_476 = V_476 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_477 = V_477 | ( 1 << 8 ) ;
F_23 ( V_487 , V_476 ) ;
F_23 ( V_488 , V_477 ) ;
if ( F_250 ( V_2 ) ) {
if ( V_76 ) {
if ( F_249 ( V_2 ) || F_103 ( V_2 ) )
F_23 ( V_463 ,
V_483 | V_464 ) ;
else if ( F_131 ( V_2 ) )
F_23 ( V_484 , F_3 ( V_484 ) | V_485 ) ;
F_25 ( L_98 ) ;
} else
F_25 ( L_99 ) ;
}
}
static void F_251 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
T_5 V_476 ;
int V_456 ;
V_9 = F_237 ( V_2 ) ;
if ( V_9 == NULL )
return;
V_456 = F_228 ( V_9 -> V_227 . clock , & V_489 ,
V_4 -> V_202 . V_482 ( V_2 , 0 ) ,
V_9 -> V_145 -> V_256 / 8 ,
V_403 ) ;
V_476 = F_3 ( V_487 ) & ~ 0xfff ;
V_476 |= ( 3 << 8 ) | V_456 ;
F_25 ( L_100 , V_456 ) ;
F_23 ( V_487 , V_476 ) ;
}
static bool F_252 ( struct V_1 * V_2 , int V_490 ,
int V_491 , int V_451 , int V_445 ,
const struct V_399 * V_202 ,
const struct V_399 * V_442 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_25 ( L_101
L_102 , V_490 , V_451 , V_491 , V_445 ) ;
if ( V_491 > V_492 ) {
F_25 ( L_103 ,
V_491 , V_492 , V_490 ) ;
F_23 ( V_493 ,
F_3 ( V_493 ) | V_494 ) ;
return false ;
}
if ( V_451 > V_202 -> V_408 ) {
F_25 ( L_104 ,
V_451 , V_495 , V_490 ) ;
return false ;
}
if ( V_445 > V_442 -> V_408 ) {
F_25 ( L_105 ,
V_445 , V_496 , V_490 ) ;
return false ;
}
if ( ! ( V_491 || V_451 || V_445 ) ) {
F_25 ( L_106 , V_490 , V_490 ) ;
return false ;
}
return true ;
}
static bool F_253 ( struct V_1 * V_2 , int V_490 , int V_99 ,
int V_403 ,
const struct V_399 * V_202 ,
const struct V_399 * V_442 ,
int * V_491 , int * V_451 , int * V_445 )
{
struct V_8 * V_9 ;
unsigned long V_447 ;
int V_232 , V_446 , V_402 , clock ;
int V_448 , V_452 ;
int V_453 , V_454 ;
int V_449 ;
if ( ! V_403 ) {
* V_491 = * V_451 = * V_445 = 0 ;
return false ;
}
V_9 = F_241 ( V_2 , V_99 ) ;
V_232 = V_9 -> V_227 . V_232 ;
V_446 = V_9 -> V_227 . V_446 ;
clock = V_9 -> V_227 . clock ;
V_402 = V_9 -> V_145 -> V_256 / 8 ;
V_447 = ( V_446 * 1000 ) / clock ;
V_448 = ( V_403 / V_447 + 1000 ) / 1000 ;
V_452 = V_232 * V_402 ;
V_453 = ( ( clock * V_402 / 1000 ) * V_403 ) / 1000 ;
V_454 = V_448 * V_452 ;
V_449 = F_229 ( V_53 ( V_453 , V_454 ) , V_202 -> V_406 ) ;
* V_451 = V_449 + V_202 -> V_407 ;
* V_491 = F_229 ( * V_451 * 64 , V_452 ) + 2 ;
V_449 = V_448 * V_402 * 64 ;
V_449 = F_229 ( V_449 , V_442 -> V_406 ) ;
* V_445 = V_449 + V_442 -> V_407 ;
return F_252 ( V_2 , V_490 ,
* V_491 , * V_451 , * V_445 ,
V_202 , V_442 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_491 , V_444 , V_445 ;
unsigned int V_76 ;
V_76 = 0 ;
if ( F_240 ( V_2 , 0 ,
& V_497 ,
V_498 ,
& V_499 ,
V_500 ,
& V_444 , & V_445 ) ) {
F_23 ( V_501 ,
( V_444 << V_502 ) | V_445 ) ;
F_25 ( L_107
L_108 L_109 ,
V_444 , V_445 ) ;
V_76 |= 1 ;
}
if ( F_240 ( V_2 , 1 ,
& V_497 ,
V_498 ,
& V_499 ,
V_500 ,
& V_444 , & V_445 ) ) {
F_23 ( V_503 ,
( V_444 << V_502 ) | V_445 ) ;
F_25 ( L_110
L_111 ,
V_444 , V_445 ) ;
V_76 |= 2 ;
}
F_23 ( V_504 , 0 ) ;
F_23 ( V_505 , 0 ) ;
F_23 ( V_506 , 0 ) ;
if ( ! F_245 ( V_76 ) )
return;
V_76 = F_246 ( V_76 ) - 1 ;
if ( ! F_253 ( V_2 , 1 , V_76 ,
F_255 () * 500 ,
& V_507 ,
& V_508 ,
& V_491 , & V_444 , & V_445 ) )
return;
F_23 ( V_506 ,
V_509 |
( F_255 () << V_510 ) |
( V_491 << V_511 ) |
( V_444 << V_512 ) |
V_445 ) ;
if ( ! F_253 ( V_2 , 2 , V_76 ,
F_256 () * 500 ,
& V_507 ,
& V_508 ,
& V_491 , & V_444 , & V_445 ) )
return;
F_23 ( V_505 ,
V_513 |
( F_256 () << V_510 ) |
( V_491 << V_511 ) |
( V_444 << V_512 ) |
V_445 ) ;
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_415 = F_258 () * 100 ;
int V_491 , V_444 , V_445 ;
unsigned int V_76 ;
V_76 = 0 ;
if ( F_240 ( V_2 , 0 ,
& V_514 , V_415 ,
& V_515 , V_415 ,
& V_444 , & V_445 ) ) {
F_23 ( V_501 ,
( V_444 << V_502 ) | V_445 ) ;
F_25 ( L_107
L_108 L_109 ,
V_444 , V_445 ) ;
V_76 |= 1 ;
}
if ( F_240 ( V_2 , 1 ,
& V_514 , V_415 ,
& V_515 , V_415 ,
& V_444 , & V_445 ) ) {
F_23 ( V_503 ,
( V_444 << V_502 ) | V_445 ) ;
F_25 ( L_110
L_111 ,
V_444 , V_445 ) ;
V_76 |= 2 ;
}
if ( F_147 ( V_2 ) &&
F_240 ( V_2 , 2 ,
& V_514 , V_415 ,
& V_515 , V_415 ,
& V_444 , & V_445 ) ) {
F_23 ( V_516 ,
( V_444 << V_502 ) | V_445 ) ;
F_25 ( L_112
L_111 ,
V_444 , V_445 ) ;
V_76 |= 3 ;
}
F_23 ( V_504 , 0 ) ;
F_23 ( V_505 , 0 ) ;
F_23 ( V_506 , 0 ) ;
if ( ! F_245 ( V_76 ) )
return;
V_76 = F_246 ( V_76 ) - 1 ;
if ( ! F_253 ( V_2 , 1 , V_76 ,
F_259 () * 500 ,
& V_517 ,
& V_518 ,
& V_491 , & V_444 , & V_445 ) )
return;
F_23 ( V_506 ,
V_509 |
( F_259 () << V_510 ) |
( V_491 << V_511 ) |
( V_444 << V_512 ) |
V_445 ) ;
if ( ! F_253 ( V_2 , 2 , V_76 ,
F_260 () * 500 ,
& V_517 ,
& V_518 ,
& V_491 , & V_444 , & V_445 ) )
return;
F_23 ( V_505 ,
V_513 |
( F_260 () << V_510 ) |
( V_491 << V_511 ) |
( V_444 << V_512 ) |
V_445 ) ;
if ( ! F_253 ( V_2 , 3 , V_76 ,
F_261 () * 500 ,
& V_517 ,
& V_518 ,
& V_491 , & V_444 , & V_445 ) )
return;
F_23 ( V_504 ,
V_519 |
( F_261 () << V_510 ) |
( V_491 << V_511 ) |
( V_444 << V_512 ) |
V_445 ) ;
}
static void F_191 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_202 . V_520 )
V_4 -> V_202 . V_520 ( V_2 ) ;
}
static inline bool F_262 ( struct V_3 * V_4 )
{
if ( V_521 >= 0 )
return V_521 != 0 ;
return V_4 -> V_522
&& ! ( V_4 -> V_133 & V_523 ) ;
}
static bool F_263 ( struct V_8 * V_9 ,
unsigned int * V_524 ,
struct V_369 * V_227 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_366 * V_51 ;
struct V_525 * V_526 ;
unsigned int V_527 = V_528 , V_331 ;
F_14 (encoder, &dev->mode_config.encoder_list, head) {
struct V_50 * V_50 = F_213 ( V_51 ) ;
if ( V_51 -> V_9 != V_9 )
continue;
if ( V_50 -> type == V_12 ) {
unsigned int V_529 ;
if ( ( F_3 ( V_13 ) & V_530 ) ==
V_531 )
V_529 = 8 ;
else
V_529 = 6 ;
if ( V_529 < V_527 ) {
F_25 ( L_113 , V_527 , V_529 ) ;
V_527 = V_529 ;
}
continue;
}
if ( V_50 -> type == V_319 ) {
unsigned int V_532 = V_4 -> V_533 . V_534 / 3 ;
if ( V_532 < V_527 ) {
F_25 ( L_114 , V_527 , V_532 ) ;
V_527 = V_532 ;
}
continue;
}
F_14 (connector, &dev->mode_config.connector_list,
head) {
if ( V_526 -> V_51 != V_51 )
continue;
if ( V_526 -> V_535 . V_331 &&
V_526 -> V_535 . V_331 < V_527 ) {
F_25 ( L_115 , V_527 , V_526 -> V_535 . V_331 ) ;
V_527 = V_526 -> V_535 . V_331 ;
}
}
if ( V_50 -> type == V_27 ) {
if ( V_527 > 8 && V_527 < 12 ) {
F_25 ( L_116 ) ;
V_527 = 12 ;
} else {
F_25 ( L_117 ) ;
V_527 = 8 ;
}
}
}
if ( V_227 -> V_536 & V_537 ) {
F_25 ( L_118 ) ;
V_527 = 6 ;
}
switch ( V_9 -> V_145 -> V_258 ) {
case 8 :
V_331 = 8 ;
break;
case 15 :
case 16 :
V_331 = 6 ;
break;
case 24 :
V_331 = 8 ;
break;
case 30 :
V_331 = 10 ;
break;
case 48 :
V_331 = 12 ;
break;
default:
F_264 ( L_119 ) ;
V_331 = V_53 ( ( unsigned int ) 8 , V_527 ) ;
break;
}
V_527 = V_53 ( V_527 , V_331 ) ;
F_25 ( L_120 ,
V_331 , V_527 ) ;
* V_524 = V_527 * 3 ;
return V_527 != V_331 ;
}
static int F_265 ( struct V_8 * V_9 ,
struct V_369 * V_227 ,
struct V_369 * V_370 ,
int V_251 , int V_164 ,
struct V_144 * V_267 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
int V_99 = V_150 -> V_99 ;
int V_10 , V_538 = 0 ;
T_3 clock , V_539 ;
T_1 V_540 , V_541 = 0 , V_542 = 0 , V_254 , V_543 ;
bool V_544 , V_545 = false , V_546 = false , V_547 = false ;
bool V_548 = false , V_549 = false , V_550 = false , V_551 = false ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
const T_2 * V_11 ;
int V_243 ;
T_1 V_285 ;
T_1 V_552 = 0 ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_12 :
V_549 = true ;
break;
case V_30 :
case V_27 :
V_546 = true ;
if ( V_51 -> V_553 )
V_550 = true ;
break;
case V_554 :
V_547 = true ;
break;
case V_555 :
V_550 = true ;
break;
case V_28 :
V_548 = true ;
break;
case V_20 :
V_551 = true ;
break;
}
V_538 ++ ;
}
if ( V_549 && F_262 ( V_4 ) && V_538 < 2 ) {
V_10 = V_4 -> V_556 * 1000 ;
F_25 ( L_121 ,
V_10 / 1000 ) ;
} else if ( ! F_11 ( V_2 ) ) {
V_10 = 96000 ;
} else {
V_10 = 48000 ;
}
V_11 = F_7 ( V_9 , V_10 ) ;
V_544 = V_11 -> V_557 ( V_11 , V_9 , V_370 -> clock , V_10 , & clock ) ;
if ( ! V_544 ) {
F_83 ( L_122 ) ;
return - V_246 ;
}
F_196 ( V_9 , true ) ;
if ( V_549 && V_4 -> V_558 ) {
V_545 = V_11 -> V_557 ( V_11 , V_9 ,
V_4 -> V_559 ,
V_10 ,
& V_539 ) ;
if ( V_545 && ( clock . V_41 != V_539 . V_41 ) ) {
F_25 ( L_123
L_124 ) ;
V_545 = 0 ;
}
}
if ( V_546 && V_550 ) {
if ( V_370 -> clock >= 100000
&& V_370 -> clock < 140500 ) {
clock . V_42 = 2 ;
clock . V_43 = 10 ;
clock . V_45 = 3 ;
clock . V_47 = 16 ;
clock . V_40 = 8 ;
} else if ( V_370 -> clock >= 140500
&& V_370 -> clock <= 200000 ) {
clock . V_42 = 1 ;
clock . V_43 = 10 ;
clock . V_45 = 6 ;
clock . V_47 = 12 ;
clock . V_40 = 8 ;
}
}
if ( F_10 ( V_2 ) ) {
V_541 = ( 1 << clock . V_45 ) << 16 | clock . V_47 << 8 | clock . V_40 ;
if ( V_545 )
V_542 = ( 1 << V_539 . V_45 ) << 16 |
V_539 . V_47 << 8 | V_539 . V_40 ;
} else {
V_541 = clock . V_45 << 16 | clock . V_47 << 8 | clock . V_40 ;
if ( V_545 )
V_542 = V_539 . V_45 << 16 | V_539 . V_47 << 8 |
V_539 . V_40 ;
}
V_540 = V_560 ;
if ( ! F_11 ( V_2 ) ) {
if ( V_549 )
V_540 |= V_561 ;
else
V_540 |= V_562 ;
if ( V_546 ) {
int V_563 = F_266 ( V_370 ) ;
if ( V_563 > 1 ) {
if ( F_249 ( V_2 ) || F_103 ( V_2 ) || F_267 ( V_2 ) )
V_540 |= ( V_563 - 1 ) << V_564 ;
}
V_540 |= V_565 ;
}
if ( V_551 )
V_540 |= V_565 ;
if ( F_10 ( V_2 ) )
V_540 |= ( 1 << ( clock . V_42 - 1 ) ) << V_566 ;
else {
V_540 |= ( 1 << ( clock . V_42 - 1 ) ) << V_567 ;
if ( F_9 ( V_2 ) && V_545 )
V_540 |= ( 1 << ( V_539 . V_42 - 1 ) ) << V_568 ;
}
switch ( clock . V_43 ) {
case 5 :
V_540 |= V_569 ;
break;
case 7 :
V_540 |= V_570 ;
break;
case 10 :
V_540 |= V_571 ;
break;
case 14 :
V_540 |= V_572 ;
break;
}
if ( F_27 ( V_2 ) -> V_69 >= 4 )
V_540 |= ( 6 << V_573 ) ;
} else {
if ( V_549 ) {
V_540 |= ( 1 << ( clock . V_42 - 1 ) ) << V_567 ;
} else {
if ( clock . V_42 == 2 )
V_540 |= V_574 ;
else
V_540 |= ( clock . V_42 - 2 ) << V_567 ;
if ( clock . V_43 == 4 )
V_540 |= V_575 ;
}
}
if ( V_546 && V_550 )
V_540 |= V_576 ;
else if ( V_550 )
V_540 |= 3 ;
else if ( V_549 && F_262 ( V_4 ) && V_538 < 2 )
V_540 |= V_577 ;
else
V_540 |= V_578 ;
V_543 = F_3 ( F_28 ( V_66 ) ) ;
V_254 = V_579 ;
if ( V_66 == 0 )
V_254 &= ~ V_103 ;
else
V_254 |= V_580 ;
if ( V_66 == 0 && F_27 ( V_2 ) -> V_69 < 4 ) {
if ( V_227 -> clock >
V_4 -> V_202 . V_581 ( V_2 ) * 9 / 10 )
V_543 |= V_582 ;
else
V_543 &= ~ V_582 ;
}
V_543 &= ~ ( V_583 | V_584 ) ;
if ( V_551 ) {
if ( V_227 -> V_536 & V_537 ) {
V_543 |= V_585 |
V_584 |
V_586 ;
}
}
V_540 |= V_80 ;
F_25 ( L_125 , V_66 == 0 ? 'A' : 'B' ) ;
F_268 ( V_227 ) ;
F_23 ( F_269 ( V_66 ) , V_541 ) ;
F_23 ( F_35 ( V_66 ) , V_540 & ~ V_80 ) ;
F_72 ( F_35 ( V_66 ) ) ;
F_73 ( 150 ) ;
if ( V_549 ) {
V_285 = F_3 ( V_24 ) ;
V_285 |= V_119 | V_587 ;
if ( V_66 == 1 ) {
V_285 |= V_96 ;
} else {
V_285 &= ~ V_96 ;
}
V_285 |= V_4 -> V_588 ;
if ( clock . V_43 == 7 )
V_285 |= V_589 | V_15 ;
else
V_285 &= ~ ( V_589 | V_15 ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
if ( V_4 -> V_590 )
V_285 |= V_591 ;
else
V_285 &= ~ V_591 ;
}
if ( V_370 -> V_228 & V_592 )
V_552 |= V_593 ;
if ( V_370 -> V_228 & V_594 )
V_552 |= V_595 ;
if ( ( V_285 & ( V_593 | V_595 ) )
!= V_552 ) {
char V_228 [ 2 ] = L_126 ;
F_270 ( L_127
L_128 ,
V_228 [ ! ( V_285 & V_593 ) ] ,
V_228 [ ! ( V_285 & V_595 ) ] ,
V_228 [ ! ( V_552 & V_593 ) ] ,
V_228 [ ! ( V_552 & V_595 ) ] ) ;
V_285 &= ~ ( V_593 | V_595 ) ;
V_285 |= V_552 ;
}
F_23 ( V_24 , V_285 ) ;
}
if ( V_551 ) {
F_271 ( V_9 , V_227 , V_370 ) ;
}
F_23 ( F_35 ( V_66 ) , V_540 ) ;
F_72 ( F_35 ( V_66 ) ) ;
F_73 ( 150 ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
V_285 = 0 ;
if ( V_546 ) {
V_285 = F_266 ( V_370 ) ;
if ( V_285 > 1 )
V_285 = ( V_285 - 1 ) << V_596 ;
else
V_285 = 0 ;
}
F_23 ( F_272 ( V_66 ) , V_285 ) ;
} else {
F_23 ( F_35 ( V_66 ) , V_540 ) ;
}
V_150 -> V_597 = false ;
if ( V_549 && V_545 && V_218 ) {
F_23 ( F_273 ( V_66 ) , V_542 ) ;
V_150 -> V_597 = true ;
if ( F_274 ( V_2 ) ) {
F_25 ( L_129 ) ;
V_543 |= V_598 ;
}
} else {
F_23 ( F_273 ( V_66 ) , V_541 ) ;
if ( F_274 ( V_2 ) ) {
F_25 ( L_130 ) ;
V_543 &= ~ V_598 ;
}
}
if ( V_370 -> V_228 & V_229 ) {
V_543 |= V_599 ;
V_370 -> V_600 -= 1 ;
V_370 -> V_601 -= 1 ;
V_370 -> V_602 -= 1 ;
V_370 -> V_603 -= 1 ;
V_370 -> V_604 -= 1 ;
V_370 -> V_605 -= 1 ;
} else
V_543 &= ~ V_599 ;
F_23 ( F_176 ( V_66 ) ,
( V_370 -> V_606 - 1 ) |
( ( V_370 -> V_372 - 1 ) << 16 ) ) ;
F_23 ( F_178 ( V_66 ) ,
( V_370 -> V_607 - 1 ) |
( ( V_370 -> V_608 - 1 ) << 16 ) ) ;
F_23 ( F_180 ( V_66 ) ,
( V_370 -> V_609 - 1 ) |
( ( V_370 -> V_610 - 1 ) << 16 ) ) ;
F_23 ( F_182 ( V_66 ) ,
( V_370 -> V_600 - 1 ) |
( ( V_370 -> V_601 - 1 ) << 16 ) ) ;
F_23 ( F_184 ( V_66 ) ,
( V_370 -> V_602 - 1 ) |
( ( V_370 -> V_603 - 1 ) << 16 ) ) ;
F_23 ( F_186 ( V_66 ) ,
( V_370 -> V_605 - 1 ) |
( ( V_370 -> V_604 - 1 ) << 16 ) ) ;
F_23 ( F_275 ( V_99 ) ,
( ( V_227 -> V_233 - 1 ) << 16 ) |
( V_227 -> V_232 - 1 ) ) ;
F_23 ( F_276 ( V_99 ) , 0 ) ;
F_23 ( F_277 ( V_66 ) ,
( ( V_227 -> V_232 - 1 ) << 16 ) | ( V_227 -> V_233 - 1 ) ) ;
F_23 ( F_28 ( V_66 ) , V_543 ) ;
F_72 ( F_28 ( V_66 ) ) ;
F_87 ( V_4 , V_66 , false ) ;
F_21 ( V_2 , V_66 ) ;
F_23 ( F_50 ( V_99 ) , V_254 ) ;
F_72 ( F_50 ( V_99 ) ) ;
F_93 ( V_4 , V_99 , V_66 ) ;
V_243 = F_146 ( V_9 , V_251 , V_164 , V_267 ) ;
F_191 ( V_2 ) ;
return V_243 ;
}
void F_278 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
T_1 V_285 ;
bool V_611 = false ;
bool V_612 = false ;
bool V_613 = false ;
bool V_614 = false ;
bool V_615 = false ;
bool V_616 = false ;
F_14 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_51 -> type ) {
case V_12 :
V_614 = true ;
V_611 = true ;
break;
case V_319 :
V_614 = true ;
if ( F_173 ( & V_51 -> V_52 ) )
V_613 = true ;
else
V_612 = true ;
break;
}
}
if ( F_82 ( V_2 ) ) {
V_615 = V_4 -> V_617 ;
V_616 = V_615 ;
} else {
V_615 = false ;
V_616 = true ;
}
F_25 ( L_131 ,
V_614 , V_611 , V_613 , V_612 ,
V_615 ) ;
V_285 = F_3 ( V_105 ) ;
V_285 &= ~ V_107 ;
if ( V_615 )
V_285 |= V_618 ;
else
V_285 |= V_619 ;
if ( V_614 ) {
V_285 &= ~ V_106 ;
V_285 |= V_620 ;
if ( F_262 ( V_4 ) && V_616 ) {
F_25 ( L_132 ) ;
V_285 |= V_621 ;
}
F_23 ( V_105 , V_285 ) ;
F_72 ( V_105 ) ;
F_73 ( 200 ) ;
V_285 &= ~ V_622 ;
if ( V_612 ) {
if ( F_262 ( V_4 ) && V_616 ) {
F_25 ( L_133 ) ;
V_285 |= V_623 ;
}
else
V_285 |= V_624 ;
} else
V_285 |= V_625 ;
F_23 ( V_105 , V_285 ) ;
F_72 ( V_105 ) ;
F_73 ( 200 ) ;
} else {
F_25 ( L_134 ) ;
V_285 &= ~ V_622 ;
V_285 |= V_625 ;
F_23 ( V_105 , V_285 ) ;
F_72 ( V_105 ) ;
F_73 ( 200 ) ;
V_285 &= ~ V_106 ;
V_285 |= V_626 ;
V_285 &= ~ V_621 ;
F_23 ( V_105 , V_285 ) ;
F_72 ( V_105 ) ;
F_73 ( 200 ) ;
}
}
static int F_279 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_50 * V_51 ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_627 = NULL ;
int V_538 = 0 ;
bool V_549 = false ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_12 :
V_549 = true ;
break;
case V_319 :
V_627 = V_51 ;
break;
}
V_538 ++ ;
}
if ( V_549 && F_262 ( V_4 ) && V_538 < 2 ) {
F_25 ( L_121 ,
V_4 -> V_556 ) ;
return V_4 -> V_556 * 1000 ;
}
return 120000 ;
}
static int F_280 ( struct V_8 * V_9 ,
struct V_369 * V_227 ,
struct V_369 * V_370 ,
int V_251 , int V_164 ,
struct V_144 * V_267 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
int V_99 = V_150 -> V_99 ;
int V_10 , V_538 = 0 ;
T_3 clock , V_539 ;
T_1 V_540 , V_541 = 0 , V_542 = 0 , V_254 , V_543 ;
bool V_544 , V_545 = false , V_546 = false ;
bool V_548 = false , V_549 = false , V_550 = false , V_551 = false ;
struct V_50 * V_628 = NULL ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
const T_2 * V_11 ;
int V_243 ;
struct V_391 V_392 = { 0 } ;
T_1 V_285 ;
T_1 V_552 = 0 ;
int V_629 , V_563 , V_630 , V_631 , V_632 ;
unsigned int V_524 ;
bool V_633 ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_12 :
V_549 = true ;
break;
case V_30 :
case V_27 :
V_546 = true ;
if ( V_51 -> V_553 )
V_550 = true ;
break;
case V_555 :
V_550 = true ;
break;
case V_28 :
V_548 = true ;
break;
case V_20 :
V_551 = true ;
break;
case V_319 :
V_628 = V_51 ;
break;
}
V_538 ++ ;
}
V_10 = F_279 ( V_9 ) ;
V_11 = F_7 ( V_9 , V_10 ) ;
V_544 = V_11 -> V_557 ( V_11 , V_9 , V_370 -> clock , V_10 , & clock ) ;
if ( ! V_544 ) {
F_83 ( L_122 ) ;
return - V_246 ;
}
F_196 ( V_9 , true ) ;
if ( V_549 && V_4 -> V_558 ) {
V_545 = V_11 -> V_557 ( V_11 , V_9 ,
V_4 -> V_559 ,
V_10 ,
& V_539 ) ;
if ( V_545 && ( clock . V_41 != V_539 . V_41 ) ) {
F_25 ( L_123
L_124 ) ;
V_545 = 0 ;
}
}
if ( V_546 && V_550 ) {
if ( V_370 -> clock >= 100000
&& V_370 -> clock < 140500 ) {
clock . V_42 = 2 ;
clock . V_43 = 10 ;
clock . V_45 = 3 ;
clock . V_47 = 16 ;
clock . V_40 = 8 ;
} else if ( V_370 -> clock >= 140500
&& V_370 -> clock <= 200000 ) {
clock . V_42 = 1 ;
clock . V_43 = 10 ;
clock . V_45 = 6 ;
clock . V_47 = 12 ;
clock . V_40 = 8 ;
}
}
V_563 = F_266 ( V_370 ) ;
V_630 = 0 ;
if ( V_628 &&
! F_173 ( & V_628 -> V_52 ) ) {
V_629 = V_227 -> clock ;
F_281 ( V_628 ,
& V_630 , & V_631 ) ;
} else {
if ( V_551 || F_173 ( & V_628 -> V_52 ) )
V_629 = V_227 -> clock ;
else
V_629 = V_370 -> clock ;
V_631 = F_1 ( V_2 ) * F_282 ( 100 ) / F_283 ( 1 ) / 10 ;
}
V_285 = F_3 ( F_28 ( V_66 ) ) ;
V_285 &= ~ V_135 ;
V_633 = F_263 ( V_9 , & V_524 , V_227 ) ;
switch ( V_524 ) {
case 18 :
V_285 |= V_634 ;
break;
case 24 :
V_285 |= V_635 ;
break;
case 30 :
V_285 |= V_636 ;
break;
case 36 :
V_285 |= V_637 ;
break;
default:
F_36 ( 1 , L_135 ,
V_524 ) ;
V_285 |= V_635 ;
V_524 = 24 ;
break;
}
V_150 -> V_534 = V_524 ;
F_23 ( F_28 ( V_66 ) , V_285 ) ;
if ( ! V_630 ) {
T_1 V_638 = V_629 * V_150 -> V_534 * 21 / 20 ;
V_630 = V_638 / ( V_631 * 8 ) + 1 ;
}
V_150 -> V_300 = V_630 ;
if ( V_563 > 1 )
V_631 *= V_563 ;
F_227 ( V_150 -> V_534 , V_630 , V_629 , V_631 ,
& V_392 ) ;
V_541 = clock . V_45 << 16 | clock . V_47 << 8 | clock . V_40 ;
if ( V_545 )
V_542 = V_539 . V_45 << 16 | V_539 . V_47 << 8 |
V_539 . V_40 ;
V_632 = 21 ;
if ( V_549 ) {
if ( ( F_262 ( V_4 ) &&
V_4 -> V_556 == 100 ) ||
( F_3 ( V_13 ) & V_14 ) == V_15 )
V_632 = 25 ;
} else if ( V_546 && V_550 )
V_632 = 20 ;
if ( clock . V_39 < V_632 * clock . V_45 )
V_541 |= V_639 ;
V_540 = 0 ;
if ( V_549 )
V_540 |= V_561 ;
else
V_540 |= V_562 ;
if ( V_546 ) {
int V_563 = F_266 ( V_370 ) ;
if ( V_563 > 1 ) {
V_540 |= ( V_563 - 1 ) << V_640 ;
}
V_540 |= V_565 ;
}
if ( V_551 || F_173 ( & V_628 -> V_52 ) )
V_540 |= V_565 ;
V_540 |= ( 1 << ( clock . V_42 - 1 ) ) << V_567 ;
V_540 |= ( 1 << ( clock . V_42 - 1 ) ) << V_568 ;
switch ( clock . V_43 ) {
case 5 :
V_540 |= V_569 ;
break;
case 7 :
V_540 |= V_570 ;
break;
case 10 :
V_540 |= V_571 ;
break;
case 14 :
V_540 |= V_572 ;
break;
}
if ( V_546 && V_550 )
V_540 |= V_576 ;
else if ( V_550 )
V_540 |= 3 ;
else if ( V_549 && F_262 ( V_4 ) && V_538 < 2 )
V_540 |= V_577 ;
else
V_540 |= V_578 ;
V_543 = F_3 ( F_28 ( V_66 ) ) ;
V_254 = V_579 ;
F_25 ( L_136 , V_66 ) ;
F_268 ( V_227 ) ;
if ( ! V_150 -> V_350 ) {
if ( ! V_628 ||
F_173 ( & V_628 -> V_52 ) ) {
F_23 ( F_284 ( V_66 ) , V_541 ) ;
F_23 ( F_39 ( V_66 ) , V_540 & ~ V_80 ) ;
F_72 ( F_39 ( V_66 ) ) ;
F_73 ( 150 ) ;
}
} else {
if ( V_540 == ( F_3 ( F_39 ( 0 ) ) & 0x7fffffff ) &&
V_541 == F_3 ( F_284 ( 0 ) ) ) {
V_150 -> V_322 = true ;
F_25 ( L_137 ) ;
} else if ( V_540 == ( F_3 ( F_39 ( 1 ) ) & 0x7fffffff ) &&
V_541 == F_3 ( F_284 ( 1 ) ) ) {
V_150 -> V_322 = false ;
F_25 ( L_138 ) ;
} else {
F_25 ( L_139 ) ;
return - V_246 ;
}
}
if ( V_549 ) {
V_285 = F_3 ( V_13 ) ;
V_285 |= V_119 | V_587 ;
if ( F_38 ( V_2 ) )
V_285 |= F_59 ( V_66 ) ;
else if ( V_66 == 1 )
V_285 |= V_96 ;
else
V_285 &= ~ V_96 ;
V_285 |= V_4 -> V_588 ;
if ( clock . V_43 == 7 )
V_285 |= V_589 | V_15 ;
else
V_285 &= ~ ( V_589 | V_15 ) ;
if ( V_370 -> V_228 & V_592 )
V_552 |= V_593 ;
if ( V_370 -> V_228 & V_594 )
V_552 |= V_595 ;
if ( ( V_285 & ( V_593 | V_595 ) )
!= V_552 ) {
char V_228 [ 2 ] = L_126 ;
F_270 ( L_127
L_128 ,
V_228 [ ! ( V_285 & V_593 ) ] ,
V_228 [ ! ( V_285 & V_595 ) ] ,
V_228 [ ! ( V_552 & V_593 ) ] ,
V_228 [ ! ( V_552 & V_595 ) ] ) ;
V_285 &= ~ ( V_593 | V_595 ) ;
V_285 |= V_552 ;
}
F_23 ( V_13 , V_285 ) ;
}
V_543 &= ~ V_584 ;
V_543 &= ~ V_641 ;
if ( ( V_549 && V_4 -> V_590 ) || V_633 ) {
V_543 |= V_584 ;
V_543 |= V_586 ;
}
if ( V_551 || F_173 ( & V_628 -> V_52 ) ) {
F_271 ( V_9 , V_227 , V_370 ) ;
} else {
F_23 ( F_285 ( V_66 ) , 0 ) ;
F_23 ( F_286 ( V_66 ) , 0 ) ;
F_23 ( F_287 ( V_66 ) , 0 ) ;
F_23 ( F_288 ( V_66 ) , 0 ) ;
}
if ( ! V_150 -> V_350 &&
( ! V_628 ||
F_173 ( & V_628 -> V_52 ) ) ) {
F_23 ( F_39 ( V_66 ) , V_540 ) ;
F_72 ( F_39 ( V_66 ) ) ;
F_73 ( 150 ) ;
F_23 ( F_39 ( V_66 ) , V_540 ) ;
}
V_150 -> V_597 = false ;
if ( ! V_150 -> V_350 ) {
if ( V_549 && V_545 && V_218 ) {
F_23 ( F_289 ( V_66 ) , V_542 ) ;
V_150 -> V_597 = true ;
if ( F_274 ( V_2 ) ) {
F_25 ( L_129 ) ;
V_543 |= V_598 ;
}
} else {
F_23 ( F_289 ( V_66 ) , V_541 ) ;
if ( F_274 ( V_2 ) ) {
F_25 ( L_130 ) ;
V_543 &= ~ V_598 ;
}
}
}
if ( V_370 -> V_228 & V_229 ) {
V_543 |= V_599 ;
V_370 -> V_600 -= 1 ;
V_370 -> V_601 -= 1 ;
V_370 -> V_602 -= 1 ;
V_370 -> V_603 -= 1 ;
V_370 -> V_604 -= 1 ;
V_370 -> V_605 -= 1 ;
} else
V_543 &= ~ V_599 ;
F_23 ( F_176 ( V_66 ) ,
( V_370 -> V_606 - 1 ) |
( ( V_370 -> V_372 - 1 ) << 16 ) ) ;
F_23 ( F_178 ( V_66 ) ,
( V_370 -> V_607 - 1 ) |
( ( V_370 -> V_608 - 1 ) << 16 ) ) ;
F_23 ( F_180 ( V_66 ) ,
( V_370 -> V_609 - 1 ) |
( ( V_370 -> V_610 - 1 ) << 16 ) ) ;
F_23 ( F_182 ( V_66 ) ,
( V_370 -> V_600 - 1 ) |
( ( V_370 -> V_601 - 1 ) << 16 ) ) ;
F_23 ( F_184 ( V_66 ) ,
( V_370 -> V_602 - 1 ) |
( ( V_370 -> V_603 - 1 ) << 16 ) ) ;
F_23 ( F_186 ( V_66 ) ,
( V_370 -> V_605 - 1 ) |
( ( V_370 -> V_604 - 1 ) << 16 ) ) ;
F_23 ( F_277 ( V_66 ) ,
( ( V_227 -> V_232 - 1 ) << 16 ) | ( V_227 -> V_233 - 1 ) ) ;
F_23 ( F_164 ( V_66 ) , F_290 ( V_392 . V_393 ) | V_392 . V_394 ) ;
F_23 ( F_291 ( V_66 ) , V_392 . V_395 ) ;
F_23 ( F_292 ( V_66 ) , V_392 . V_396 ) ;
F_23 ( F_293 ( V_66 ) , V_392 . V_397 ) ;
if ( V_628 &&
! F_173 ( & V_628 -> V_52 ) ) {
F_151 ( V_9 , V_370 -> clock ) ;
}
F_23 ( F_28 ( V_66 ) , V_543 ) ;
F_72 ( F_28 ( V_66 ) ) ;
F_21 ( V_2 , V_66 ) ;
if ( F_2 ( V_2 ) ) {
V_285 = F_3 ( V_493 ) ;
F_23 ( V_493 , V_285 | V_642 ) ;
}
F_23 ( F_50 ( V_99 ) , V_254 ) ;
F_72 ( F_50 ( V_99 ) ) ;
V_243 = F_146 ( V_9 , V_251 , V_164 , V_267 ) ;
F_191 ( V_2 ) ;
return V_243 ;
}
static int F_294 ( struct V_8 * V_9 ,
struct V_369 * V_227 ,
struct V_369 * V_370 ,
int V_251 , int V_164 ,
struct V_144 * V_267 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
int V_243 ;
F_295 ( V_2 , V_66 ) ;
V_243 = V_4 -> V_202 . V_643 ( V_9 , V_227 , V_370 ,
V_251 , V_164 , V_267 ) ;
F_296 ( V_2 , V_66 ) ;
V_150 -> V_357 = V_351 ;
return V_243 ;
}
static void F_297 ( struct V_525 * V_526 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_526 -> V_2 -> V_5 ;
T_6 * V_644 = V_526 -> V_644 ;
T_5 V_645 ;
T_5 V_646 ;
T_5 V_101 ;
V_101 = F_3 ( V_647 ) ;
if ( V_101 == V_648 || V_101 == V_649 )
V_645 = V_650 ;
else
V_645 = V_651 ;
V_101 = F_3 ( V_652 ) ;
V_101 &= ~ ( V_645 | V_653 ) ;
V_646 = ( V_101 >> 9 ) & 0x1f ;
F_23 ( V_652 , V_101 ) ;
if ( ! V_644 [ 0 ] )
return;
V_646 = F_298 ( T_6 , V_644 [ 2 ] , V_646 ) ;
F_299 ( L_140 , V_646 ) ;
for ( V_101 = 0 ; V_101 < V_646 ; V_101 ++ )
F_23 ( V_654 , * ( ( T_5 * ) V_644 + V_101 ) ) ;
V_101 = F_3 ( V_652 ) ;
V_101 |= V_645 ;
F_23 ( V_652 , V_101 ) ;
}
static void F_300 ( struct V_525 * V_526 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_526 -> V_2 -> V_5 ;
T_6 * V_644 = V_526 -> V_644 ;
T_5 V_645 ;
T_5 V_101 ;
int V_646 ;
int V_655 ;
int V_656 ;
int V_657 ;
if ( F_147 ( V_526 -> V_2 ) ) {
V_655 = V_658 ;
V_656 = V_659 ;
V_657 = V_660 ;
} else {
V_655 = V_661 ;
V_656 = V_662 ;
V_657 = V_663 ;
}
V_101 = F_102 ( V_9 ) -> V_66 ;
V_655 += V_101 * 0x100 ;
V_656 += V_101 * 0x100 ;
F_299 ( L_141 , F_47 ( V_101 ) ) ;
V_101 = F_3 ( V_656 ) ;
V_101 = ( V_101 >> 29 ) & 0x3 ;
if ( ! V_101 ) {
F_299 ( L_142 ) ;
V_645 = V_664 ;
V_645 |= V_664 << 4 ;
V_645 |= V_664 << 8 ;
} else {
F_299 ( L_143 , 'A' + V_101 ) ;
V_645 = V_664 << ( ( V_101 - 1 ) * 4 ) ;
}
V_101 = F_3 ( V_657 ) ;
V_101 &= ~ V_645 ;
F_23 ( V_657 , V_101 ) ;
if ( ! V_644 [ 0 ] )
return;
if ( F_5 ( V_9 , V_20 ) ) {
F_299 ( L_144 ) ;
V_644 [ 5 ] |= ( 1 << 2 ) ;
}
V_101 = F_3 ( V_656 ) ;
V_101 &= ~ V_665 ;
F_23 ( V_656 , V_101 ) ;
V_646 = F_298 ( T_6 , V_644 [ 2 ] , 21 ) ;
F_299 ( L_140 , V_646 ) ;
for ( V_101 = 0 ; V_101 < V_646 ; V_101 ++ )
F_23 ( V_655 , * ( ( T_5 * ) V_644 + V_101 ) ) ;
V_101 = F_3 ( V_657 ) ;
V_101 |= V_645 ;
F_23 ( V_657 , V_101 ) ;
}
void F_301 ( struct V_366 * V_51 ,
struct V_369 * V_227 )
{
struct V_8 * V_9 = V_51 -> V_9 ;
struct V_525 * V_526 ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_526 = F_302 ( V_51 , V_227 ) ;
if ( ! V_526 )
return;
F_299 ( L_145 ,
V_526 -> V_52 . V_213 ,
F_303 ( V_526 ) ,
V_526 -> V_51 -> V_52 . V_213 ,
F_304 ( V_526 -> V_51 ) ) ;
V_526 -> V_644 [ 6 ] = F_305 ( V_526 , V_227 ) / 2 ;
if ( V_4 -> V_202 . V_666 )
V_4 -> V_202 . V_666 ( V_526 , V_9 ) ;
}
void F_195 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_667 = F_306 ( V_150 -> V_66 ) ;
int V_101 ;
if ( ! V_9 -> V_76 )
return;
if ( F_8 ( V_2 ) )
V_667 = F_307 ( V_150 -> V_66 ) ;
for ( V_101 = 0 ; V_101 < 256 ; V_101 ++ ) {
F_23 ( V_667 + 4 * V_101 ,
( V_150 -> V_668 [ V_101 ] << 16 ) |
( V_150 -> V_669 [ V_101 ] << 8 ) |
V_150 -> V_670 [ V_101 ] ) ;
}
}
static void F_308 ( struct V_8 * V_9 , T_1 V_52 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
bool V_671 = V_52 != 0 ;
T_1 V_672 ;
if ( V_150 -> V_673 == V_671 )
return;
V_672 = F_3 ( V_674 ) ;
if ( V_671 ) {
F_23 ( V_675 , V_52 ) ;
V_672 &= ~ ( V_676 ) ;
V_672 |= V_677 |
V_678 |
V_679 ;
} else
V_672 &= ~ ( V_677 | V_678 ) ;
F_23 ( V_674 , V_672 ) ;
V_150 -> V_673 = V_671 ;
}
static void F_309 ( struct V_8 * V_9 , T_1 V_52 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
bool V_671 = V_52 != 0 ;
if ( V_150 -> V_673 != V_671 ) {
T_5 V_672 = F_3 ( F_310 ( V_66 ) ) ;
if ( V_52 ) {
V_672 &= ~ ( V_680 | V_681 ) ;
V_672 |= V_682 | V_683 ;
V_672 |= V_66 << 28 ;
} else {
V_672 &= ~ ( V_680 | V_683 ) ;
V_672 |= V_684 ;
}
F_23 ( F_310 ( V_66 ) , V_672 ) ;
V_150 -> V_673 = V_671 ;
}
F_23 ( F_311 ( V_66 ) , V_52 ) ;
}
static void F_312 ( struct V_8 * V_9 , T_1 V_52 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
bool V_671 = V_52 != 0 ;
if ( V_150 -> V_673 != V_671 ) {
T_5 V_672 = F_3 ( F_313 ( V_66 ) ) ;
if ( V_52 ) {
V_672 &= ~ V_680 ;
V_672 |= V_682 | V_683 ;
} else {
V_672 &= ~ ( V_680 | V_683 ) ;
V_672 |= V_684 ;
}
F_23 ( F_313 ( V_66 ) , V_672 ) ;
V_150 -> V_673 = V_671 ;
}
F_23 ( F_314 ( V_66 ) , V_52 ) ;
}
static void F_196 ( struct V_8 * V_9 ,
bool V_685 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
int V_251 = V_150 -> V_686 ;
int V_164 = V_150 -> V_687 ;
T_1 V_52 , V_688 ;
bool V_671 ;
V_688 = 0 ;
if ( V_685 && V_9 -> V_76 && V_9 -> V_145 ) {
V_52 = V_150 -> V_689 ;
if ( V_251 > ( int ) V_9 -> V_145 -> V_690 )
V_52 = 0 ;
if ( V_164 > ( int ) V_9 -> V_145 -> V_691 )
V_52 = 0 ;
} else
V_52 = 0 ;
if ( V_251 < 0 ) {
if ( V_251 + V_150 -> V_692 < 0 )
V_52 = 0 ;
V_688 |= V_693 << V_694 ;
V_251 = - V_251 ;
}
V_688 |= V_251 << V_694 ;
if ( V_164 < 0 ) {
if ( V_164 + V_150 -> V_695 < 0 )
V_52 = 0 ;
V_688 |= V_693 << V_696 ;
V_164 = - V_164 ;
}
V_688 |= V_164 << V_696 ;
V_671 = V_52 != 0 ;
if ( ! V_671 && ! V_150 -> V_673 )
return;
if ( F_147 ( V_2 ) ) {
F_23 ( F_315 ( V_66 ) , V_688 ) ;
F_312 ( V_9 , V_52 ) ;
} else {
F_23 ( F_316 ( V_66 ) , V_688 ) ;
if ( F_317 ( V_2 ) || F_318 ( V_2 ) )
F_308 ( V_9 , V_52 ) ;
else
F_309 ( V_9 , V_52 ) ;
}
if ( V_671 )
F_319 ( V_2 , F_101 ( V_9 -> V_145 ) -> V_149 ) ;
}
static int F_320 ( struct V_8 * V_9 ,
struct V_697 * V_698 ,
T_5 V_699 ,
T_5 V_690 , T_5 V_691 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
struct V_148 * V_149 ;
T_5 V_700 ;
int V_243 ;
F_25 ( L_41 ) ;
if ( ! V_699 ) {
F_25 ( L_146 ) ;
V_700 = 0 ;
V_149 = NULL ;
F_119 ( & V_2 -> V_208 ) ;
goto V_701;
}
if ( V_690 != 64 || V_691 != 64 ) {
F_83 ( L_147 ) ;
return - V_246 ;
}
V_149 = F_321 ( F_322 ( V_2 , V_698 , V_699 ) ) ;
if ( & V_149 -> V_52 == NULL )
return - V_702 ;
if ( V_149 -> V_52 . V_225 < V_690 * V_691 * 4 ) {
F_83 ( L_148 ) ;
V_243 = - V_703 ;
goto V_704;
}
F_119 ( & V_2 -> V_208 ) ;
if ( ! V_4 -> V_85 -> V_705 ) {
if ( V_149 -> V_236 ) {
F_83 ( L_149 ) ;
V_243 = - V_246 ;
goto V_706;
}
V_243 = F_137 ( V_149 , 0 , NULL ) ;
if ( V_243 ) {
F_83 ( L_150 ) ;
goto V_706;
}
V_243 = F_323 ( V_149 ) ;
if ( V_243 ) {
F_83 ( L_151 ) ;
goto V_707;
}
V_700 = V_149 -> V_197 ;
} else {
int V_708 = F_71 ( V_2 ) ? 16 * 1024 : 256 ;
V_243 = F_324 ( V_2 , V_149 ,
( V_150 -> V_66 == 0 ) ? V_709 : V_710 ,
V_708 ) ;
if ( V_243 ) {
F_83 ( L_152 ) ;
goto V_706;
}
V_700 = V_149 -> V_711 -> V_699 -> V_712 ;
}
if ( F_11 ( V_2 ) )
F_23 ( V_713 , ( V_691 << 12 ) | V_690 ) ;
V_701:
if ( V_150 -> V_714 ) {
if ( V_4 -> V_85 -> V_705 ) {
if ( V_150 -> V_714 != V_149 )
F_325 ( V_2 , V_150 -> V_714 ) ;
} else
F_139 ( V_150 -> V_714 ) ;
F_326 ( & V_150 -> V_714 -> V_52 ) ;
}
F_120 ( & V_2 -> V_208 ) ;
V_150 -> V_689 = V_700 ;
V_150 -> V_714 = V_149 ;
V_150 -> V_692 = V_690 ;
V_150 -> V_695 = V_691 ;
F_196 ( V_9 , true ) ;
return 0 ;
V_707:
F_139 ( V_149 ) ;
V_706:
F_120 ( & V_2 -> V_208 ) ;
V_704:
F_327 ( & V_149 -> V_52 ) ;
return V_243 ;
}
static int F_328 ( struct V_8 * V_9 , int V_251 , int V_164 )
{
struct V_150 * V_150 = F_102 ( V_9 ) ;
V_150 -> V_686 = V_251 ;
V_150 -> V_687 = V_164 ;
F_196 ( V_9 , true ) ;
return 0 ;
}
void F_329 ( struct V_8 * V_9 , T_4 V_715 , T_4 V_716 ,
T_4 V_717 , int V_718 )
{
struct V_150 * V_150 = F_102 ( V_9 ) ;
V_150 -> V_668 [ V_718 ] = V_715 >> 8 ;
V_150 -> V_669 [ V_718 ] = V_716 >> 8 ;
V_150 -> V_670 [ V_718 ] = V_717 >> 8 ;
}
void F_330 ( struct V_8 * V_9 , T_4 * V_715 , T_4 * V_716 ,
T_4 * V_717 , int V_718 )
{
struct V_150 * V_150 = F_102 ( V_9 ) ;
* V_715 = V_150 -> V_668 [ V_718 ] << 8 ;
* V_716 = V_150 -> V_669 [ V_718 ] << 8 ;
* V_717 = V_150 -> V_670 [ V_718 ] << 8 ;
}
static void F_331 ( struct V_8 * V_9 , T_4 * V_715 , T_4 * V_716 ,
T_4 * V_717 , T_5 V_719 , T_5 V_225 )
{
int V_720 = ( V_719 + V_225 > 256 ) ? 256 : V_719 + V_225 , V_101 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
for ( V_101 = V_719 ; V_101 < V_720 ; V_101 ++ ) {
V_150 -> V_668 [ V_101 ] = V_715 [ V_101 ] >> 8 ;
V_150 -> V_669 [ V_101 ] = V_716 [ V_101 ] >> 8 ;
V_150 -> V_670 [ V_101 ] = V_717 [ V_101 ] >> 8 ;
}
F_195 ( V_9 ) ;
}
static struct V_144 *
F_332 ( struct V_1 * V_2 ,
struct V_721 * V_722 ,
struct V_148 * V_149 )
{
struct V_146 * V_147 ;
int V_243 ;
V_147 = F_125 ( sizeof( * V_147 ) , V_215 ) ;
if ( ! V_147 ) {
F_327 ( & V_149 -> V_52 ) ;
return F_333 ( - V_703 ) ;
}
V_243 = F_334 ( V_2 , V_147 , V_722 , V_149 ) ;
if ( V_243 ) {
F_327 ( & V_149 -> V_52 ) ;
F_121 ( V_147 ) ;
return F_333 ( V_243 ) ;
}
return & V_147 -> V_52 ;
}
static T_1
F_335 ( int V_690 , int V_534 )
{
T_1 V_155 = F_229 ( V_690 * V_534 , 8 ) ;
return F_336 ( V_155 , 64 ) ;
}
static T_1
F_337 ( struct V_369 * V_227 , int V_534 )
{
T_1 V_155 = F_335 ( V_227 -> V_232 , V_534 ) ;
return F_336 ( V_155 * V_227 -> V_233 , V_723 ) ;
}
static struct V_144 *
F_338 ( struct V_1 * V_2 ,
struct V_369 * V_227 ,
int V_258 , int V_534 )
{
struct V_148 * V_149 ;
struct V_721 V_722 ;
V_149 = F_339 ( V_2 ,
F_337 ( V_227 , V_534 ) ) ;
if ( V_149 == NULL )
return F_333 ( - V_703 ) ;
V_722 . V_690 = V_227 -> V_232 ;
V_722 . V_691 = V_227 -> V_233 ;
V_722 . V_258 = V_258 ;
V_722 . V_534 = V_534 ;
V_722 . V_155 = F_335 ( V_722 . V_690 , V_534 ) ;
return F_332 ( V_2 , & V_722 , V_149 ) ;
}
static struct V_144 *
F_340 ( struct V_1 * V_2 ,
struct V_369 * V_227 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_149 ;
struct V_144 * V_145 ;
if ( V_4 -> V_724 == NULL )
return NULL ;
V_149 = V_4 -> V_724 -> V_725 . V_149 ;
if ( V_149 == NULL )
return NULL ;
V_145 = & V_4 -> V_724 -> V_725 . V_52 ;
if ( V_145 -> V_155 < F_335 ( V_227 -> V_232 ,
V_145 -> V_256 ) )
return NULL ;
if ( V_149 -> V_52 . V_225 < V_227 -> V_233 * V_145 -> V_155 )
return NULL ;
return V_145 ;
}
bool F_341 ( struct V_50 * V_50 ,
struct V_525 * V_526 ,
struct V_369 * V_227 ,
struct V_726 * V_727 )
{
struct V_150 * V_150 ;
struct V_8 * V_728 ;
struct V_366 * V_51 = & V_50 -> V_52 ;
struct V_8 * V_9 = NULL ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_144 * V_267 ;
int V_101 = - 1 ;
F_25 ( L_153 ,
V_526 -> V_52 . V_213 , F_303 ( V_526 ) ,
V_51 -> V_52 . V_213 , F_304 ( V_51 ) ) ;
if ( V_51 -> V_9 ) {
V_9 = V_51 -> V_9 ;
V_150 = F_102 ( V_9 ) ;
V_727 -> V_357 = V_150 -> V_357 ;
V_727 -> V_729 = false ;
if ( V_150 -> V_357 != V_351 ) {
struct V_367 * V_368 ;
struct V_363 * V_364 ;
V_364 = V_9 -> V_365 ;
V_364 -> V_358 ( V_9 , V_351 ) ;
V_368 = V_51 -> V_365 ;
V_368 -> V_358 ( V_51 , V_351 ) ;
}
return true ;
}
F_14 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_101 ++ ;
if ( ! ( V_51 -> V_730 & ( 1 << V_101 ) ) )
continue;
if ( ! V_728 -> V_76 ) {
V_9 = V_728 ;
break;
}
}
if ( ! V_9 ) {
F_25 ( L_154 ) ;
return false ;
}
V_51 -> V_9 = V_9 ;
V_526 -> V_51 = V_51 ;
V_150 = F_102 ( V_9 ) ;
V_727 -> V_357 = V_150 -> V_357 ;
V_727 -> V_729 = true ;
V_727 -> V_731 = NULL ;
if ( ! V_227 )
V_227 = & V_732 ;
V_267 = V_9 -> V_145 ;
V_9 -> V_145 = F_340 ( V_2 , V_227 ) ;
if ( V_9 -> V_145 == NULL ) {
F_25 ( L_155 ) ;
V_9 -> V_145 = F_338 ( V_2 , V_227 , 24 , 32 ) ;
V_727 -> V_731 = V_9 -> V_145 ;
} else
F_25 ( L_156 ) ;
if ( F_342 ( V_9 -> V_145 ) ) {
F_25 ( L_157 ) ;
V_9 -> V_145 = V_267 ;
return false ;
}
if ( ! F_343 ( V_9 , V_227 , 0 , 0 , V_267 ) ) {
F_25 ( L_158 ) ;
if ( V_727 -> V_731 )
V_727 -> V_731 -> V_733 -> V_734 ( V_727 -> V_731 ) ;
V_9 -> V_145 = V_267 ;
return false ;
}
F_21 ( V_2 , V_150 -> V_66 ) ;
return true ;
}
void F_344 ( struct V_50 * V_50 ,
struct V_525 * V_526 ,
struct V_726 * V_727 )
{
struct V_366 * V_51 = & V_50 -> V_52 ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_8 * V_9 = V_51 -> V_9 ;
struct V_367 * V_368 = V_51 -> V_365 ;
struct V_363 * V_364 = V_9 -> V_365 ;
F_25 ( L_153 ,
V_526 -> V_52 . V_213 , F_303 ( V_526 ) ,
V_51 -> V_52 . V_213 , F_304 ( V_51 ) ) ;
if ( V_727 -> V_729 ) {
V_526 -> V_51 = NULL ;
F_345 ( V_2 ) ;
if ( V_727 -> V_731 )
V_727 -> V_731 -> V_733 -> V_734 ( V_727 -> V_731 ) ;
return;
}
if ( V_727 -> V_357 != V_351 ) {
V_368 -> V_358 ( V_51 , V_727 -> V_357 ) ;
V_364 -> V_358 ( V_9 , V_727 -> V_357 ) ;
}
}
static int F_346 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
T_1 V_540 = F_3 ( F_35 ( V_66 ) ) ;
T_1 V_541 ;
T_3 clock ;
if ( ( V_540 & V_735 ) == 0 )
V_541 = F_3 ( F_269 ( V_66 ) ) ;
else
V_541 = F_3 ( F_273 ( V_66 ) ) ;
clock . V_47 = ( V_541 & V_736 ) >> V_737 ;
if ( F_10 ( V_2 ) ) {
clock . V_45 = F_246 ( ( V_541 & V_738 ) >> V_739 ) - 1 ;
clock . V_40 = ( V_541 & V_740 ) >> V_741 ;
} else {
clock . V_45 = ( V_541 & V_742 ) >> V_739 ;
clock . V_40 = ( V_541 & V_743 ) >> V_741 ;
}
if ( ! F_11 ( V_2 ) ) {
if ( F_10 ( V_2 ) )
clock . V_42 = F_246 ( ( V_540 & V_744 ) >>
V_566 ) ;
else
clock . V_42 = F_246 ( ( V_540 & V_745 ) >>
V_567 ) ;
switch ( V_540 & V_746 ) {
case V_562 :
clock . V_43 = V_540 & V_569 ?
5 : 10 ;
break;
case V_561 :
clock . V_43 = V_540 & V_570 ?
7 : 14 ;
break;
default:
F_25 ( L_159
L_160 , ( int ) ( V_540 & V_746 ) ) ;
return 0 ;
}
F_13 ( V_2 , 96000 , & clock ) ;
} else {
bool V_549 = ( V_66 == 1 ) && ( F_3 ( V_24 ) & V_119 ) ;
if ( V_549 ) {
clock . V_42 = F_246 ( ( V_540 & V_747 ) >>
V_567 ) ;
clock . V_43 = 14 ;
if ( ( V_540 & V_748 ) ==
V_577 ) {
F_13 ( V_2 , 66000 , & clock ) ;
} else
F_13 ( V_2 , 48000 , & clock ) ;
} else {
if ( V_540 & V_574 )
clock . V_42 = 2 ;
else {
clock . V_42 = ( ( V_540 & V_749 ) >>
V_567 ) + 2 ;
}
if ( V_540 & V_575 )
clock . V_43 = 4 ;
else
clock . V_43 = 2 ;
F_13 ( V_2 , 48000 , & clock ) ;
}
}
return clock . V_46 ;
}
struct V_369 * F_347 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
struct V_369 * V_227 ;
int V_750 = F_3 ( F_176 ( V_66 ) ) ;
int V_751 = F_3 ( F_180 ( V_66 ) ) ;
int V_752 = F_3 ( F_182 ( V_66 ) ) ;
int V_753 = F_3 ( F_186 ( V_66 ) ) ;
V_227 = F_125 ( sizeof( * V_227 ) , V_215 ) ;
if ( ! V_227 )
return NULL ;
V_227 -> clock = F_346 ( V_2 , V_9 ) ;
V_227 -> V_232 = ( V_750 & 0xffff ) + 1 ;
V_227 -> V_446 = ( ( V_750 & 0xffff0000 ) >> 16 ) + 1 ;
V_227 -> V_754 = ( V_751 & 0xffff ) + 1 ;
V_227 -> V_755 = ( ( V_751 & 0xffff0000 ) >> 16 ) + 1 ;
V_227 -> V_233 = ( V_752 & 0xffff ) + 1 ;
V_227 -> V_756 = ( ( V_752 & 0xffff0000 ) >> 16 ) + 1 ;
V_227 -> V_757 = ( V_753 & 0xffff ) + 1 ;
V_227 -> V_758 = ( ( V_753 & 0xffff0000 ) >> 16 ) + 1 ;
F_348 ( V_227 ) ;
F_217 ( V_227 , 0 ) ;
return V_227 ;
}
static void F_349 ( unsigned long V_759 )
{
struct V_1 * V_2 = (struct V_1 * ) V_759 ;
T_7 * V_4 = V_2 -> V_5 ;
if ( ! F_350 ( & V_4 -> V_247 . V_760 ) ) {
F_351 ( & V_4 -> V_761 , V_74 +
F_30 ( V_762 ) ) ;
return;
}
V_4 -> V_763 = false ;
F_352 ( V_4 -> V_764 , & V_4 -> V_765 ) ;
}
static void F_353 ( unsigned long V_759 )
{
struct V_150 * V_150 = (struct V_150 * ) V_759 ;
struct V_8 * V_9 = & V_150 -> V_52 ;
T_7 * V_4 = V_9 -> V_2 -> V_5 ;
struct V_146 * V_147 ;
V_147 = F_101 ( V_9 -> V_145 ) ;
if ( V_147 && V_147 -> V_149 -> V_344 ) {
F_351 ( & V_150 -> V_761 , V_74 +
F_30 ( V_766 ) ) ;
return;
}
V_150 -> V_763 = false ;
F_352 ( V_4 -> V_764 , & V_4 -> V_765 ) ;
}
static void F_145 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
int V_767 = F_35 ( V_66 ) ;
int V_540 ;
if ( F_8 ( V_2 ) )
return;
if ( ! V_4 -> V_558 )
return;
V_540 = F_3 ( V_767 ) ;
if ( ! F_274 ( V_2 ) && ( V_540 & V_735 ) ) {
F_299 ( L_161 ) ;
F_23 ( V_93 ,
F_3 ( V_93 ) | V_95 ) ;
V_540 &= ~ V_735 ;
F_23 ( V_767 , V_540 ) ;
F_21 ( V_2 , V_66 ) ;
V_540 = F_3 ( V_767 ) ;
if ( V_540 & V_735 )
F_299 ( L_162 ) ;
F_23 ( V_93 , F_3 ( V_93 ) & 0x3 ) ;
}
F_351 ( & V_150 -> V_761 , V_74 +
F_30 ( V_766 ) ) ;
}
static void F_354 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
int V_66 = V_150 -> V_66 ;
int V_767 = F_35 ( V_66 ) ;
int V_540 = F_3 ( V_767 ) ;
if ( F_8 ( V_2 ) )
return;
if ( ! V_4 -> V_558 )
return;
if ( ! F_274 ( V_2 ) && V_150 -> V_597 ) {
F_299 ( L_163 ) ;
F_23 ( V_93 , F_3 ( V_93 ) |
V_95 ) ;
V_540 |= V_735 ;
F_23 ( V_767 , V_540 ) ;
F_21 ( V_2 , V_66 ) ;
V_540 = F_3 ( V_767 ) ;
if ( ! ( V_540 & V_735 ) )
F_299 ( L_164 ) ;
F_23 ( V_93 , F_3 ( V_93 ) & 0x3 ) ;
}
}
static void F_355 ( struct V_204 * V_207 )
{
T_7 * V_4 = F_117 ( V_207 , T_7 ,
V_765 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_8 * V_9 ;
struct V_150 * V_150 ;
if ( ! V_218 )
return;
F_119 ( & V_2 -> V_208 ) ;
F_356 ( V_4 ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_9 -> V_145 )
continue;
V_150 = F_102 ( V_9 ) ;
if ( ! V_150 -> V_763 )
F_354 ( V_9 ) ;
}
F_120 ( & V_2 -> V_208 ) ;
}
void F_319 ( struct V_1 * V_2 , struct V_148 * V_149 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = NULL ;
struct V_146 * V_147 ;
struct V_150 * V_150 ;
if ( ! F_357 ( V_2 , V_768 ) )
return;
if ( ! V_4 -> V_763 )
V_4 -> V_763 = true ;
else
F_351 ( & V_4 -> V_761 , V_74 +
F_30 ( V_762 ) ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_9 -> V_145 )
continue;
V_150 = F_102 ( V_9 ) ;
V_147 = F_101 ( V_9 -> V_145 ) ;
if ( V_147 -> V_149 == V_149 ) {
if ( ! V_150 -> V_763 ) {
F_145 ( V_9 ) ;
V_150 -> V_763 = true ;
} else {
F_351 ( & V_150 -> V_761 , V_74 +
F_30 ( V_766 ) ) ;
}
}
}
}
static void F_358 ( struct V_8 * V_9 )
{
struct V_150 * V_150 = F_102 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_769 * V_207 ;
unsigned long V_228 ;
F_359 ( & V_2 -> V_770 , V_228 ) ;
V_207 = V_150 -> V_771 ;
V_150 -> V_771 = NULL ;
F_360 ( & V_2 -> V_770 , V_228 ) ;
if ( V_207 ) {
F_361 ( & V_207 -> V_207 ) ;
F_121 ( V_207 ) ;
}
F_362 ( V_9 ) ;
F_121 ( V_150 ) ;
}
static void F_363 ( struct V_204 * V_205 )
{
struct V_769 * V_207 =
F_117 ( V_205 , struct V_769 , V_207 ) ;
F_119 ( & V_207 -> V_2 -> V_208 ) ;
F_139 ( V_207 -> V_772 ) ;
F_326 ( & V_207 -> V_773 -> V_52 ) ;
F_326 ( & V_207 -> V_772 -> V_52 ) ;
F_129 ( V_207 -> V_2 ) ;
F_120 ( & V_207 -> V_2 -> V_208 ) ;
F_121 ( V_207 ) ;
}
static void F_364 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
struct V_769 * V_207 ;
struct V_148 * V_149 ;
struct V_774 * V_775 ;
struct V_776 V_777 , V_778 ;
unsigned long V_228 ;
if ( V_150 == NULL )
return;
F_365 ( & V_777 ) ;
F_359 ( & V_2 -> V_770 , V_228 ) ;
V_207 = V_150 -> V_771 ;
if ( V_207 == NULL || ! V_207 -> V_779 ) {
F_360 ( & V_2 -> V_770 , V_228 ) ;
return;
}
V_150 -> V_771 = NULL ;
if ( V_207 -> V_780 ) {
V_775 = V_207 -> V_780 ;
V_775 -> V_780 . V_781 = F_366 ( V_2 , V_150 -> V_66 , & V_778 ) ;
if ( 10 * ( F_367 ( & V_777 ) - F_367 ( & V_778 ) ) >
9 * V_9 -> V_782 ) {
V_775 -> V_780 . V_781 ++ ;
V_778 = F_368 ( F_367 ( & V_778 ) +
V_9 -> V_782 ) ;
}
V_775 -> V_780 . V_783 = V_778 . V_783 ;
V_775 -> V_780 . V_784 = V_778 . V_784 ;
F_369 ( & V_775 -> V_52 . V_785 ,
& V_775 -> V_52 . V_786 -> V_787 ) ;
F_370 ( & V_775 -> V_52 . V_786 -> V_788 ) ;
}
F_371 ( V_2 , V_150 -> V_66 ) ;
F_360 ( & V_2 -> V_770 , V_228 ) ;
V_149 = V_207 -> V_772 ;
F_372 ( 1 << V_150 -> V_99 ,
& V_149 -> V_272 . V_789 ) ;
if ( F_149 ( & V_149 -> V_272 ) == 0 )
F_373 ( & V_4 -> V_270 ) ;
F_374 ( & V_207 -> V_207 ) ;
F_375 ( V_150 -> V_99 , V_207 -> V_773 ) ;
}
void F_376 ( struct V_1 * V_2 , int V_66 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = V_4 -> V_790 [ V_66 ] ;
F_364 ( V_2 , V_9 ) ;
}
void F_377 ( struct V_1 * V_2 , int V_99 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = V_4 -> V_791 [ V_99 ] ;
F_364 ( V_2 , V_9 ) ;
}
void F_378 ( struct V_1 * V_2 , int V_99 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 =
F_102 ( V_4 -> V_791 [ V_99 ] ) ;
unsigned long V_228 ;
F_359 ( & V_2 -> V_770 , V_228 ) ;
if ( V_150 -> V_771 ) {
if ( ( ++ V_150 -> V_771 -> V_779 ) > 1 )
F_83 ( L_165 ) ;
} else {
F_299 ( L_166 ) ;
}
F_360 ( & V_2 -> V_770 , V_228 ) ;
}
static int F_379 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_144 * V_145 ,
struct V_148 * V_149 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
unsigned long V_792 ;
T_1 V_793 ;
int V_243 ;
V_243 = F_133 ( V_2 , V_149 , F_168 ( V_4 ) ) ;
if ( V_243 )
goto V_794;
V_792 = V_9 -> V_164 * V_145 -> V_155 + V_9 -> V_251 * V_145 -> V_256 / 8 ;
V_243 = F_380 ( 6 ) ;
if ( V_243 )
goto V_794;
if ( V_150 -> V_99 )
V_793 = V_795 ;
else
V_793 = V_796 ;
F_381 ( V_797 | V_793 ) ;
F_381 ( V_798 ) ;
F_381 ( V_799 |
F_382 ( V_150 -> V_99 ) ) ;
F_381 ( V_145 -> V_155 ) ;
F_381 ( V_149 -> V_197 + V_792 ) ;
F_381 ( V_798 ) ;
F_383 () ;
V_794:
return V_243 ;
}
static int F_384 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_144 * V_145 ,
struct V_148 * V_149 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
unsigned long V_792 ;
T_1 V_793 ;
int V_243 ;
V_243 = F_133 ( V_2 , V_149 , F_168 ( V_4 ) ) ;
if ( V_243 )
goto V_794;
V_792 = V_9 -> V_164 * V_145 -> V_155 + V_9 -> V_251 * V_145 -> V_256 / 8 ;
V_243 = F_380 ( 6 ) ;
if ( V_243 )
goto V_794;
if ( V_150 -> V_99 )
V_793 = V_795 ;
else
V_793 = V_796 ;
F_381 ( V_797 | V_793 ) ;
F_381 ( V_798 ) ;
F_381 ( V_800 |
F_382 ( V_150 -> V_99 ) ) ;
F_381 ( V_145 -> V_155 ) ;
F_381 ( V_149 -> V_197 + V_792 ) ;
F_381 ( V_798 ) ;
F_383 () ;
V_794:
return V_243 ;
}
static int F_385 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_144 * V_145 ,
struct V_148 * V_149 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
T_5 V_801 , V_802 ;
int V_243 ;
V_243 = F_133 ( V_2 , V_149 , F_168 ( V_4 ) ) ;
if ( V_243 )
goto V_794;
V_243 = F_380 ( 4 ) ;
if ( V_243 )
goto V_794;
F_381 ( V_799 |
F_382 ( V_150 -> V_99 ) ) ;
F_381 ( V_145 -> V_155 ) ;
F_381 ( V_149 -> V_197 | V_149 -> V_236 ) ;
V_801 = 0 ;
V_802 = F_3 ( F_277 ( V_150 -> V_66 ) ) & 0x0fff0fff ;
F_381 ( V_801 | V_802 ) ;
F_383 () ;
V_794:
return V_243 ;
}
static int F_386 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_144 * V_145 ,
struct V_148 * V_149 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
T_5 V_801 , V_802 ;
int V_243 ;
V_243 = F_133 ( V_2 , V_149 , F_168 ( V_4 ) ) ;
if ( V_243 )
goto V_794;
V_243 = F_380 ( 4 ) ;
if ( V_243 )
goto V_794;
F_381 ( V_799 |
F_382 ( V_150 -> V_99 ) ) ;
F_381 ( V_145 -> V_155 | V_149 -> V_236 ) ;
F_381 ( V_149 -> V_197 ) ;
V_801 = F_3 ( F_192 ( V_150 -> V_66 ) ) & V_346 ;
V_802 = F_3 ( F_277 ( V_150 -> V_66 ) ) & 0x0fff0fff ;
F_381 ( V_801 | V_802 ) ;
F_383 () ;
V_794:
return V_243 ;
}
static int F_387 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_144 * V_145 ,
struct V_148 * V_149 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
struct V_240 * V_316 = & V_4 -> V_316 [ V_803 ] ;
int V_243 ;
V_243 = F_133 ( V_2 , V_149 , V_316 ) ;
if ( V_243 )
goto V_794;
V_243 = F_388 ( V_316 , 4 ) ;
if ( V_243 )
goto V_794;
F_389 ( V_316 , V_800 | ( V_150 -> V_99 << 19 ) ) ;
F_389 ( V_316 , ( V_145 -> V_155 | V_149 -> V_236 ) ) ;
F_389 ( V_316 , ( V_149 -> V_197 ) ) ;
F_389 ( V_316 , ( V_798 ) ) ;
F_390 ( V_316 ) ;
V_794:
return V_243 ;
}
static int F_391 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_144 * V_145 ,
struct V_148 * V_149 )
{
return - V_804 ;
}
static int F_392 ( struct V_8 * V_9 ,
struct V_144 * V_145 ,
struct V_774 * V_780 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_146 * V_147 ;
struct V_148 * V_149 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
struct V_769 * V_207 ;
unsigned long V_228 ;
int V_243 ;
V_207 = F_125 ( sizeof *V_207 , V_215 ) ;
if ( V_207 == NULL )
return - V_703 ;
V_207 -> V_780 = V_780 ;
V_207 -> V_2 = V_9 -> V_2 ;
V_147 = F_101 ( V_9 -> V_145 ) ;
V_207 -> V_772 = V_147 -> V_149 ;
F_393 ( & V_207 -> V_207 , F_363 ) ;
V_243 = F_394 ( V_2 , V_150 -> V_66 ) ;
if ( V_243 )
goto V_805;
F_359 ( & V_2 -> V_770 , V_228 ) ;
if ( V_150 -> V_771 ) {
F_360 ( & V_2 -> V_770 , V_228 ) ;
F_121 ( V_207 ) ;
F_371 ( V_2 , V_150 -> V_66 ) ;
F_299 ( L_167 ) ;
return - V_806 ;
}
V_150 -> V_771 = V_207 ;
F_360 ( & V_2 -> V_770 , V_228 ) ;
V_147 = F_101 ( V_145 ) ;
V_149 = V_147 -> V_149 ;
F_119 ( & V_2 -> V_208 ) ;
F_395 ( & V_207 -> V_772 -> V_52 ) ;
F_395 ( & V_149 -> V_52 ) ;
V_9 -> V_145 = V_145 ;
V_207 -> V_773 = V_149 ;
V_207 -> V_807 = true ;
F_396 ( 1 << V_150 -> V_99 , & V_207 -> V_772 -> V_272 ) ;
V_243 = V_4 -> V_202 . V_808 ( V_2 , V_9 , V_145 , V_149 ) ;
if ( V_243 )
goto V_809;
F_128 ( V_2 ) ;
F_120 ( & V_2 -> V_208 ) ;
F_397 ( V_150 -> V_99 , V_149 ) ;
return 0 ;
V_809:
F_398 ( 1 << V_150 -> V_99 , & V_207 -> V_772 -> V_272 ) ;
F_326 ( & V_207 -> V_772 -> V_52 ) ;
F_326 ( & V_149 -> V_52 ) ;
F_120 ( & V_2 -> V_208 ) ;
F_359 ( & V_2 -> V_770 , V_228 ) ;
V_150 -> V_771 = NULL ;
F_360 ( & V_2 -> V_770 , V_228 ) ;
F_371 ( V_2 , V_150 -> V_66 ) ;
V_805:
F_121 ( V_207 ) ;
return V_243 ;
}
static void F_399 ( struct V_1 * V_2 ,
int V_66 , int V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_70 , V_78 ;
if ( F_8 ( V_2 ) )
return;
V_70 = F_50 ( V_99 ) ;
V_78 = F_3 ( V_70 ) ;
if ( ( V_78 & V_100 ) == 0 )
return;
if ( ! ! ( V_78 & V_103 ) == V_66 )
return;
V_66 = ! V_66 ;
F_95 ( V_4 , V_99 , V_66 ) ;
F_89 ( V_4 , V_66 ) ;
}
static void F_400 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_150 * V_150 = F_102 ( V_9 ) ;
V_150 -> V_357 = - 1 ;
F_399 ( V_2 , V_150 -> V_66 , V_150 -> V_99 ) ;
}
static void F_401 ( struct V_1 * V_2 , int V_66 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_150 * V_150 ;
int V_101 ;
V_150 = F_125 ( sizeof( struct V_150 ) + ( V_810 * sizeof( struct V_525 * ) ) , V_215 ) ;
if ( V_150 == NULL )
return;
F_402 ( V_2 , & V_150 -> V_52 , & V_811 ) ;
F_403 ( & V_150 -> V_52 , 256 ) ;
for ( V_101 = 0 ; V_101 < 256 ; V_101 ++ ) {
V_150 -> V_668 [ V_101 ] = V_101 ;
V_150 -> V_669 [ V_101 ] = V_101 ;
V_150 -> V_670 [ V_101 ] = V_101 ;
}
V_150 -> V_66 = V_66 ;
V_150 -> V_99 = V_66 ;
if ( F_70 ( V_2 ) && F_404 ( V_2 ) ) {
F_25 ( L_168 ) ;
V_150 -> V_99 = ! V_66 ;
}
F_69 ( V_66 >= F_231 ( V_4 -> V_791 ) ||
V_4 -> V_791 [ V_150 -> V_99 ] != NULL ) ;
V_4 -> V_791 [ V_150 -> V_99 ] = & V_150 -> V_52 ;
V_4 -> V_790 [ V_150 -> V_66 ] = & V_150 -> V_52 ;
F_400 ( & V_150 -> V_52 ) ;
V_150 -> V_344 = true ;
V_150 -> V_534 = 24 ;
if ( F_8 ( V_2 ) ) {
if ( V_66 == 2 && F_147 ( V_2 ) )
V_150 -> V_350 = true ;
V_812 . V_813 = F_209 ;
V_812 . V_814 = F_210 ;
} else {
V_812 . V_813 = F_207 ;
V_812 . V_814 = F_208 ;
}
F_405 ( & V_150 -> V_52 , & V_812 ) ;
V_150 -> V_763 = false ;
F_406 ( & V_150 -> V_761 , F_353 ,
( unsigned long ) V_150 ) ;
}
int F_407 ( struct V_1 * V_2 , void * V_815 ,
struct V_697 * V_698 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_816 * V_817 = V_815 ;
struct V_818 * V_819 ;
struct V_150 * V_9 ;
if ( ! V_4 ) {
F_83 ( L_169 ) ;
return - V_246 ;
}
V_819 = F_408 ( V_2 , V_817 -> V_820 ,
V_821 ) ;
if ( ! V_819 ) {
F_83 ( L_170 ) ;
return - V_246 ;
}
V_9 = F_102 ( F_409 ( V_819 ) ) ;
V_817 -> V_66 = V_9 -> V_66 ;
return 0 ;
}
static int F_410 ( struct V_1 * V_2 , int V_822 )
{
struct V_50 * V_51 ;
int V_823 = 0 ;
int V_824 = 0 ;
F_14 (encoder, &dev->mode_config.encoder_list, base.head) {
if ( V_822 & V_51 -> V_825 )
V_823 |= ( 1 << V_824 ) ;
V_824 ++ ;
}
return V_823 ;
}
static bool F_411 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_70 ( V_2 ) )
return false ;
if ( ( F_3 ( V_283 ) & V_826 ) == 0 )
return false ;
if ( F_2 ( V_2 ) &&
( F_3 ( V_827 ) & V_828 ) )
return false ;
return true ;
}
static void F_412 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_50 * V_51 ;
bool V_829 = false ;
bool V_611 = false ;
if ( F_70 ( V_2 ) && ! F_71 ( V_2 ) )
V_611 = F_413 ( V_2 ) ;
if ( ! V_611 && ! F_8 ( V_2 ) ) {
F_23 ( V_830 , 0 ) ;
}
if ( F_8 ( V_2 ) ) {
V_829 = F_414 ( V_2 ) ;
if ( F_411 ( V_2 ) )
F_415 ( V_2 , V_283 ) ;
if ( V_829 && ( F_3 ( V_127 ) & V_826 ) )
F_415 ( V_2 , V_127 ) ;
}
F_416 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
int V_63 ;
if ( F_3 ( V_130 ) & V_831 ) {
V_63 = F_417 ( V_2 , V_832 ) ;
if ( ! V_63 )
F_418 ( V_2 , V_130 ) ;
if ( ! V_63 && ( F_3 ( V_123 ) & V_826 ) )
F_415 ( V_2 , V_123 ) ;
}
if ( F_3 ( V_131 ) & V_831 )
F_418 ( V_2 , V_131 ) ;
if ( F_3 ( V_132 ) & V_831 )
F_418 ( V_2 , V_132 ) ;
if ( F_3 ( V_125 ) & V_826 )
F_415 ( V_2 , V_125 ) ;
if ( ! V_829 && ( F_3 ( V_127 ) & V_826 ) )
F_415 ( V_2 , V_127 ) ;
} else if ( F_419 ( V_2 ) ) {
bool V_63 = false ;
if ( F_3 ( V_833 ) & V_834 ) {
F_25 ( L_171 ) ;
V_63 = F_417 ( V_2 , V_833 ) ;
if ( ! V_63 && F_420 ( V_2 ) ) {
F_25 ( L_172 ) ;
F_418 ( V_2 , V_833 ) ;
}
if ( ! V_63 && F_421 ( V_2 ) ) {
F_25 ( L_173 ) ;
F_415 ( V_2 , V_835 ) ;
}
}
if ( F_3 ( V_833 ) & V_834 ) {
F_25 ( L_174 ) ;
V_63 = F_417 ( V_2 , V_836 ) ;
}
if ( ! V_63 && ( F_3 ( V_836 ) & V_834 ) ) {
if ( F_420 ( V_2 ) ) {
F_25 ( L_175 ) ;
F_418 ( V_2 , V_836 ) ;
}
if ( F_421 ( V_2 ) ) {
F_25 ( L_176 ) ;
F_415 ( V_2 , V_837 ) ;
}
}
if ( F_421 ( V_2 ) &&
( F_3 ( V_838 ) & V_826 ) ) {
F_25 ( L_177 ) ;
F_415 ( V_2 , V_838 ) ;
}
} else if ( F_11 ( V_2 ) )
F_422 ( V_2 ) ;
if ( F_423 ( V_2 ) )
F_424 ( V_2 ) ;
F_14 (encoder, &dev->mode_config.encoder_list, base.head) {
V_51 -> V_52 . V_730 = V_51 -> V_839 ;
V_51 -> V_52 . V_840 =
F_410 ( V_2 , V_51 -> V_825 ) ;
}
F_345 ( V_2 ) ;
if ( F_8 ( V_2 ) )
F_278 ( V_2 ) ;
}
static void F_425 ( struct V_144 * V_145 )
{
struct V_146 * V_147 = F_101 ( V_145 ) ;
F_426 ( V_145 ) ;
F_327 ( & V_147 -> V_149 -> V_52 ) ;
F_121 ( V_147 ) ;
}
static int F_427 ( struct V_144 * V_145 ,
struct V_697 * V_698 ,
unsigned int * V_699 )
{
struct V_146 * V_147 = F_101 ( V_145 ) ;
struct V_148 * V_149 = V_147 -> V_149 ;
return F_428 ( V_698 , & V_149 -> V_52 , V_699 ) ;
}
int F_334 ( struct V_1 * V_2 ,
struct V_146 * V_147 ,
struct V_721 * V_722 ,
struct V_148 * V_149 )
{
int V_243 ;
if ( V_149 -> V_236 == V_245 )
return - V_246 ;
if ( V_722 -> V_155 & 63 )
return - V_246 ;
switch ( V_722 -> V_534 ) {
case 8 :
case 16 :
if ( V_722 -> V_258 == 15 && ! F_8 ( V_2 ) )
return - V_246 ;
break;
case 24 :
case 32 :
break;
default:
return - V_246 ;
}
V_243 = F_429 ( V_2 , & V_147 -> V_52 , & V_841 ) ;
if ( V_243 ) {
F_83 ( L_178 , V_243 ) ;
return V_243 ;
}
F_430 ( & V_147 -> V_52 , V_722 ) ;
V_147 -> V_149 = V_149 ;
return 0 ;
}
static struct V_144 *
F_431 ( struct V_1 * V_2 ,
struct V_697 * V_842 ,
struct V_721 * V_722 )
{
struct V_148 * V_149 ;
V_149 = F_321 ( F_322 ( V_2 , V_842 , V_722 -> V_699 ) ) ;
if ( & V_149 -> V_52 == NULL )
return F_333 ( - V_702 ) ;
return F_332 ( V_2 , V_722 , V_149 ) ;
}
static struct V_148 *
F_432 ( struct V_1 * V_2 )
{
struct V_148 * V_843 ;
int V_243 ;
F_433 ( ! F_434 ( & V_2 -> V_208 ) ) ;
V_843 = F_339 ( V_2 , 4096 ) ;
if ( ! V_843 ) {
F_264 ( L_179 ) ;
return NULL ;
}
V_243 = F_435 ( V_843 , 4096 , true ) ;
if ( V_243 ) {
F_83 ( L_180 , V_243 ) ;
goto V_844;
}
V_243 = F_436 ( V_843 , 1 ) ;
if ( V_243 ) {
F_83 ( L_181 , V_243 ) ;
goto V_250;
}
return V_843 ;
V_250:
F_139 ( V_843 ) ;
V_844:
F_326 ( & V_843 -> V_52 ) ;
F_120 ( & V_2 -> V_208 ) ;
return NULL ;
}
bool F_437 ( struct V_1 * V_2 , T_8 V_78 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_845 ;
V_845 = F_438 ( V_846 ) ;
if ( V_845 & V_847 ) {
F_264 ( L_182 ) ;
return false ;
}
V_845 = ( V_848 << V_849 ) |
( V_78 << V_850 ) | V_851 ;
F_439 ( V_846 , V_845 ) ;
F_440 ( V_846 ) ;
V_845 |= V_847 ;
F_439 ( V_846 , V_845 ) ;
return true ;
}
void F_441 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_852 = F_3 ( V_853 ) ;
T_8 V_854 , V_855 , V_856 , V_857 ;
F_439 ( V_858 , F_3 ( V_858 ) | V_859 ) ;
F_439 ( V_860 , F_3 ( V_860 ) | V_861 ) ;
F_23 ( V_862 , 100000 ) ;
F_23 ( V_863 , 100000 ) ;
F_23 ( V_864 , 90000 ) ;
F_23 ( V_865 , 80000 ) ;
F_23 ( V_866 , 1 ) ;
V_854 = ( V_852 & V_867 ) >> V_868 ;
V_855 = ( V_852 & V_869 ) ;
V_856 = ( V_852 & V_870 ) >>
V_871 ;
V_857 = ( F_3 ( V_872 + ( V_856 * 4 ) ) & V_873 ) >>
V_874 ;
V_4 -> V_854 = V_854 ;
V_4 -> V_856 = V_856 ;
V_4 -> V_875 = V_856 ;
V_4 -> V_876 = V_855 ;
V_4 -> V_877 = V_856 ;
F_299 ( L_183 ,
V_854 , V_855 , V_856 ) ;
F_23 ( V_878 , V_879 | V_880 ) ;
F_23 ( V_881 , V_857 ) ;
F_72 ( V_881 ) ;
V_852 |= V_882 ;
F_23 ( V_853 , V_852 ) ;
if ( F_24 ( ( F_3 ( V_846 ) & V_847 ) == 0 , 10 ) )
F_83 ( L_184 ) ;
F_442 ( 1 ) ;
F_437 ( V_2 , V_856 ) ;
V_4 -> V_883 = F_3 ( 0x112e4 ) + F_3 ( 0x112e8 ) +
F_3 ( 0x112e0 ) ;
V_4 -> V_884 = F_443 ( V_74 ) ;
V_4 -> V_885 = F_3 ( 0x112f4 ) ;
F_444 ( & V_4 -> V_886 ) ;
}
void F_445 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_845 = F_438 ( V_846 ) ;
F_23 ( V_878 , F_3 ( V_878 ) & ~ V_880 ) ;
F_23 ( V_887 , V_888 ) ;
F_23 ( V_889 , F_3 ( V_889 ) & ~ V_890 ) ;
F_23 ( V_891 , V_890 ) ;
F_23 ( V_892 , F_3 ( V_892 ) | V_890 ) ;
F_437 ( V_2 , V_4 -> V_856 ) ;
F_442 ( 1 ) ;
V_845 |= V_847 ;
F_23 ( V_846 , V_845 ) ;
F_442 ( 1 ) ;
}
void F_446 ( struct V_1 * V_2 , T_8 V_78 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_893 ;
V_893 = ( V_78 & 0x3ff ) << 25 ;
F_23 ( V_894 , V_893 ) ;
}
void F_447 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_894 , 1 << 31 ) ;
F_23 ( V_895 , 0xffffffff ) ;
F_23 ( V_896 , 0 ) ;
F_448 ( & V_4 -> V_897 ) ;
V_4 -> V_898 = 0 ;
F_449 ( & V_4 -> V_897 ) ;
F_23 ( V_899 , F_3 ( V_899 ) ) ;
}
static unsigned long F_450 ( T_1 V_900 )
{
unsigned long V_901 ;
int div = ( V_900 & 0x3f0000 ) >> 16 ;
int V_902 = ( V_900 & 0x3000 ) >> 12 ;
int V_903 = ( V_900 & 0x7 ) ;
if ( ! V_903 )
return 0 ;
V_901 = ( ( div * 133333 ) / ( ( 1 << V_902 ) * V_903 ) ) ;
return V_901 ;
}
void F_451 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_904 ;
T_8 V_905 [ 16 ] ;
int V_101 ;
F_23 ( V_906 , 0 ) ;
F_72 ( V_906 ) ;
F_23 ( V_907 , 0x15040d00 ) ;
F_23 ( V_908 , 0x007f0000 ) ;
F_23 ( V_909 , 0x1e220004 ) ;
F_23 ( V_910 , 0x04000004 ) ;
for ( V_101 = 0 ; V_101 < 5 ; V_101 ++ )
F_23 ( V_911 + ( V_101 * 4 ) , 0 ) ;
for ( V_101 = 0 ; V_101 < 3 ; V_101 ++ )
F_23 ( V_912 + ( V_101 * 4 ) , 0 ) ;
for ( V_101 = 0 ; V_101 < 16 ; V_101 ++ ) {
T_1 V_913 = F_3 ( V_872 + ( V_101 * 4 ) ) ;
unsigned long V_901 = F_450 ( V_913 ) ;
unsigned long V_914 = ( V_913 & V_873 ) >>
V_874 ;
unsigned long V_78 ;
V_78 = V_914 * V_914 ;
V_78 *= ( V_901 / 1000 ) ;
V_78 *= 255 ;
V_78 /= ( 127 * 127 * 900 ) ;
if ( V_78 > 0xff )
F_83 ( L_185 , V_78 ) ;
V_905 [ V_101 ] = V_78 ;
}
V_905 [ 14 ] = 0 ;
V_905 [ 15 ] = 0 ;
for ( V_101 = 0 ; V_101 < 4 ; V_101 ++ ) {
T_1 V_78 = ( V_905 [ V_101 * 4 ] << 24 ) | ( V_905 [ ( V_101 * 4 ) + 1 ] << 16 ) |
( V_905 [ ( V_101 * 4 ) + 2 ] << 8 ) | ( V_905 [ ( V_101 * 4 ) + 3 ] ) ;
F_23 ( V_915 + ( V_101 * 4 ) , V_78 ) ;
}
F_23 ( V_916 , 0 ) ;
F_23 ( V_917 , 0 ) ;
F_23 ( V_918 , 0x00007f00 ) ;
F_23 ( V_919 , 0x0000000e ) ;
F_23 ( V_920 , 0x000e0000 ) ;
F_23 ( V_921 , 0x68000300 ) ;
F_23 ( V_922 , 0x42000000 ) ;
F_23 ( V_923 , 0x00140031 ) ;
F_23 ( V_924 , 0 ) ;
F_23 ( V_925 , 0 ) ;
for ( V_101 = 0 ; V_101 < 8 ; V_101 ++ )
F_23 ( V_926 + ( V_101 * 4 ) , 0 ) ;
F_23 ( V_906 , 0x80000019 ) ;
V_904 = F_3 ( V_927 ) ;
V_4 -> V_928 = ( V_904 & V_929 ) ;
}
static bool F_452 ( struct V_1 * V_2 )
{
if ( V_930 >= 0 )
return V_930 ;
if ( F_27 ( V_2 ) -> V_69 == 5 )
return 0 ;
if ( F_27 ( V_2 ) -> V_69 == 6 ) {
F_299 ( L_186 ) ;
return 0 ;
}
F_299 ( L_187 ) ;
return 1 ;
}
void F_453 ( struct V_3 * V_4 )
{
T_1 V_931 = F_3 ( V_932 ) ;
T_1 V_933 = F_3 ( V_934 ) ;
T_1 V_935 , V_936 = 0 ;
int V_937 , V_938 , V_939 ;
int V_101 ;
F_23 ( V_940 , 0 ) ;
F_119 ( & V_4 -> V_2 -> V_208 ) ;
F_109 ( V_4 ) ;
F_23 ( V_941 , 0 ) ;
F_23 ( V_942 , 1000 << 16 ) ;
F_23 ( V_943 , 40 << 16 | 30 ) ;
F_23 ( V_944 , 30 ) ;
F_23 ( V_945 , 125000 ) ;
F_23 ( V_946 , 25 ) ;
for ( V_101 = 0 ; V_101 < V_947 ; V_101 ++ )
F_23 ( F_454 ( V_4 -> V_316 [ V_101 ] . V_948 ) , 10 ) ;
F_23 ( V_949 , 0 ) ;
F_23 ( V_950 , 1000 ) ;
F_23 ( V_951 , 50000 ) ;
F_23 ( V_952 , 100000 ) ;
F_23 ( V_953 , 64000 ) ;
if ( F_452 ( V_4 -> V_2 ) )
V_936 = V_954 |
V_955 ;
F_23 ( V_941 ,
V_936 |
F_455 ( 1 ) |
V_956 ) ;
F_23 ( V_894 ,
F_456 ( 10 ) |
F_457 ( 0 ) |
V_957 ) ;
F_23 ( V_958 ,
F_456 ( 12 ) ) ;
F_23 ( V_959 , 1000000 ) ;
F_23 ( V_960 ,
18 << 24 |
6 << 16 ) ;
F_23 ( V_961 , 10000 ) ;
F_23 ( V_962 , 1000000 ) ;
F_23 ( V_963 , 100000 ) ;
F_23 ( V_964 , 5000000 ) ;
F_23 ( V_965 , 10 ) ;
F_23 ( V_966 ,
V_967 |
V_968 |
V_969 |
V_970 |
V_971 |
V_972 ) ;
if ( F_24 ( ( F_3 ( V_973 ) & V_974 ) == 0 ,
500 ) )
F_83 ( L_188 ) ;
F_23 ( V_975 , 0 ) ;
F_23 ( V_973 ,
V_974 |
V_976 ) ;
if ( F_24 ( ( F_3 ( V_973 ) & V_974 ) == 0 ,
500 ) )
F_83 ( L_189 ) ;
V_938 = ( V_931 & 0xff0000 ) >> 16 ;
V_939 = V_931 & 0xff ;
V_937 = ( V_933 & 0xff00 ) >> 8 ;
if ( F_24 ( ( F_3 ( V_973 ) & V_974 ) == 0 ,
500 ) )
F_83 ( L_188 ) ;
F_23 ( V_973 , V_977 ) ;
V_935 = F_3 ( V_975 ) ;
if ( F_24 ( ( F_3 ( V_973 ) & V_974 ) == 0 ,
500 ) )
F_83 ( L_189 ) ;
if ( V_935 & ( 1 << 31 ) ) {
V_939 = V_935 & 0xff ;
F_299 ( L_190 , V_935 * 50 ) ;
}
V_4 -> V_875 = V_939 ;
V_4 -> V_876 = V_938 ;
V_4 -> V_877 = V_937 ;
F_23 ( V_896 ,
V_978 |
V_979 |
V_980 |
V_981 |
V_982 |
V_983 |
V_984 ) ;
F_448 ( & V_4 -> V_897 ) ;
F_433 ( V_4 -> V_898 != 0 ) ;
F_23 ( V_985 , 0 ) ;
F_449 ( & V_4 -> V_897 ) ;
F_23 ( V_895 , 0 ) ;
F_110 ( V_4 ) ;
F_120 ( & V_4 -> V_2 -> V_208 ) ;
}
void F_458 ( struct V_3 * V_4 )
{
int V_938 = 15 ;
int V_986 , V_987 , V_988 ;
int V_989 = 180 ;
V_988 = F_459 ( 0 ) ;
if ( ! V_988 )
V_988 = V_990 ;
V_988 /= 1000 ;
F_119 ( & V_4 -> V_2 -> V_208 ) ;
for ( V_986 = V_4 -> V_875 ; V_986 >= V_4 -> V_876 ;
V_986 -- ) {
int V_991 = V_4 -> V_875 - V_986 ;
if ( V_986 < V_938 )
V_987 = 800 ;
else
V_987 = V_988 - ( ( V_991 * V_989 ) / 2 ) ;
V_987 = F_460 ( V_987 , 100 ) ;
F_23 ( V_975 ,
( V_987 << V_992 ) |
V_986 ) ;
F_23 ( V_973 , V_974 |
V_976 ) ;
if ( F_24 ( ( F_3 ( V_973 ) &
V_974 ) == 0 , 10 ) ) {
F_83 ( L_191 ) ;
continue;
}
}
F_120 ( & V_4 -> V_2 -> V_208 ) ;
}
static void F_461 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_993 = V_994 ;
V_993 |= V_995 |
V_996 |
V_997 ;
V_993 |= V_998 ;
F_23 ( V_999 ,
V_1000 |
V_1001 ) ;
F_23 ( V_1002 ,
V_1003 ) ;
F_23 ( V_1004 , V_993 ) ;
F_23 ( V_1005 ,
( F_3 ( V_1005 ) |
V_1006 | V_1007 ) ) ;
F_23 ( V_1008 ,
( F_3 ( V_1008 ) |
V_1009 ) ) ;
F_23 ( V_493 ,
( F_3 ( V_493 ) |
V_494 ) ) ;
F_23 ( V_504 , 0 ) ;
F_23 ( V_505 , 0 ) ;
F_23 ( V_506 , 0 ) ;
if ( F_462 ( V_2 ) ) {
F_23 ( V_1010 ,
F_3 ( V_1010 ) |
V_1011 ) ;
F_23 ( V_1005 ,
F_3 ( V_1005 ) |
V_1006 ) ;
F_23 ( V_1008 ,
F_3 ( V_1008 ) |
V_1012 |
V_1013 |
V_1014 ) ;
}
F_23 ( V_1005 ,
F_3 ( V_1005 ) |
V_1015 ) ;
F_23 ( V_1016 ,
V_1017 << 16 |
V_1017 ) ;
}
static void F_463 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
T_5 V_993 = V_994 ;
F_23 ( V_1004 , V_993 ) ;
F_23 ( V_1005 ,
F_3 ( V_1005 ) |
V_1015 ) ;
F_23 ( V_504 , 0 ) ;
F_23 ( V_505 , 0 ) ;
F_23 ( V_506 , 0 ) ;
F_23 ( V_1018 ,
V_1019 |
V_1020 ) ;
F_23 ( V_1010 ,
F_3 ( V_1010 ) |
V_1011 | V_1021 ) ;
F_23 ( V_1005 ,
F_3 ( V_1005 ) |
V_1006 | V_1007 ) ;
F_23 ( V_1008 ,
F_3 ( V_1008 ) |
V_1009 |
V_1022 ) ;
F_464 (pipe) {
F_23 ( F_50 ( V_66 ) ,
F_3 ( F_50 ( V_66 ) ) |
V_264 ) ;
F_90 ( V_4 , V_66 ) ;
}
}
static void F_465 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
T_5 V_993 = V_994 ;
F_23 ( V_1004 , V_993 ) ;
F_23 ( V_504 , 0 ) ;
F_23 ( V_505 , 0 ) ;
F_23 ( V_506 , 0 ) ;
F_23 ( V_1008 , V_1023 ) ;
F_464 (pipe) {
F_23 ( F_50 ( V_66 ) ,
F_3 ( F_50 ( V_66 ) ) |
V_264 ) ;
F_90 ( V_4 , V_66 ) ;
}
}
static void F_466 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_993 ;
F_23 ( V_1024 , 0 ) ;
F_23 ( V_1025 , V_1026 |
V_1027 |
V_1028 ) ;
F_23 ( V_1029 , 0 ) ;
V_993 = V_994 |
V_1030 |
V_1031 ;
if ( F_467 ( V_2 ) )
V_993 |= V_1032 ;
F_23 ( V_1033 , V_993 ) ;
}
static void F_468 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_1024 , V_1034 ) ;
F_23 ( V_1025 , 0 ) ;
F_23 ( V_1033 , 0 ) ;
F_23 ( V_1029 , 0 ) ;
F_439 ( V_1035 , 0 ) ;
}
static void F_469 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_1024 , V_1036 |
V_1034 |
V_1037 |
V_1038 |
V_1039 ) ;
F_23 ( V_1025 , 0 ) ;
}
static void F_470 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_1040 = F_3 ( V_1041 ) ;
V_1040 |= V_1042 | V_1043 |
V_1044 ;
F_23 ( V_1041 , V_1040 ) ;
}
static void F_471 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_1024 , V_1045 ) ;
}
static void F_472 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_1033 , V_1030 ) ;
}
static void F_473 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_1046 , V_1047 ) ;
}
static void F_474 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
F_23 ( V_1046 , V_1047 ) ;
F_23 ( V_1048 , F_3 ( V_1048 ) |
V_1049 ) ;
F_464 (pipe)
F_23 ( F_189 ( V_66 ) , V_342 ) ;
}
static void F_475 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_1050 ) {
F_139 ( V_4 -> V_1050 ) ;
F_326 ( & V_4 -> V_1050 -> V_52 ) ;
V_4 -> V_1050 = NULL ;
}
if ( V_4 -> V_1051 ) {
F_139 ( V_4 -> V_1051 ) ;
F_326 ( & V_4 -> V_1051 -> V_52 ) ;
V_4 -> V_1051 = NULL ;
}
}
static void F_476 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_3 ( V_1052 ) ) {
F_23 ( V_1053 , F_3 ( V_1053 ) | V_1054 ) ;
F_24 ( ( ( F_3 ( V_1053 ) & V_1055 ) == V_1056 ) ,
50 ) ;
F_23 ( V_1052 , 0 ) ;
F_72 ( V_1052 ) ;
F_23 ( V_1053 , F_3 ( V_1053 ) & ~ V_1054 ) ;
F_72 ( V_1053 ) ;
}
F_475 ( V_2 ) ;
}
static int F_477 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_1050 == NULL )
V_4 -> V_1050 = F_432 ( V_2 ) ;
if ( ! V_4 -> V_1050 )
return - V_703 ;
if ( V_4 -> V_1051 == NULL )
V_4 -> V_1051 = F_432 ( V_2 ) ;
if ( ! V_4 -> V_1051 ) {
F_475 ( V_2 ) ;
return - V_703 ;
}
return 0 ;
}
void F_478 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_243 ;
if ( ! F_452 ( V_2 ) )
return;
F_119 ( & V_2 -> V_208 ) ;
V_243 = F_477 ( V_2 ) ;
if ( V_243 ) {
F_120 ( & V_2 -> V_208 ) ;
return;
}
V_243 = F_380 ( 6 ) ;
if ( V_243 ) {
F_475 ( V_2 ) ;
F_120 ( & V_2 -> V_208 ) ;
return;
}
F_381 ( V_1057 | V_1058 ) ;
F_381 ( V_1059 ) ;
F_381 ( V_4 -> V_1050 -> V_197 |
V_1060 |
V_1061 |
V_1062 |
V_1063 ) ;
F_381 ( V_1057 ) ;
F_381 ( V_798 ) ;
F_381 ( V_1064 ) ;
F_383 () ;
V_243 = F_479 ( F_168 ( V_4 ) ) ;
if ( V_243 ) {
F_83 ( L_192 ) ;
F_475 ( V_2 ) ;
F_120 ( & V_2 -> V_208 ) ;
return;
}
F_23 ( V_1052 , V_4 -> V_1051 -> V_197 | V_1065 ) ;
F_23 ( V_1053 , F_3 ( V_1053 ) & ~ V_1054 ) ;
F_120 ( & V_2 -> V_208 ) ;
}
void F_480 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_202 . V_1066 ( V_2 ) ;
if ( V_4 -> V_202 . V_1067 )
V_4 -> V_202 . V_1067 ( V_2 ) ;
}
static void F_481 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_8 ( V_2 ) ) {
V_4 -> V_202 . V_358 = F_199 ;
V_4 -> V_202 . V_643 = F_280 ;
V_4 -> V_202 . V_266 = F_143 ;
} else {
V_4 -> V_202 . V_358 = F_204 ;
V_4 -> V_202 . V_643 = F_265 ;
V_4 -> V_202 . V_266 = F_140 ;
}
if ( F_130 ( V_2 ) ) {
if ( F_8 ( V_2 ) ) {
V_4 -> V_202 . V_203 = F_114 ;
V_4 -> V_202 . V_210 = F_111 ;
V_4 -> V_202 . V_216 = F_113 ;
} else if ( F_467 ( V_2 ) ) {
V_4 -> V_202 . V_203 = F_107 ;
V_4 -> V_202 . V_210 = F_105 ;
V_4 -> V_202 . V_216 = F_106 ;
} else if ( F_135 ( V_2 ) ) {
V_4 -> V_202 . V_203 = F_104 ;
V_4 -> V_202 . V_210 = F_100 ;
V_4 -> V_202 . V_216 = F_99 ;
}
}
if ( F_249 ( V_2 ) || ( F_267 ( V_2 ) && ! F_482 ( V_2 ) ) )
V_4 -> V_202 . V_581 =
F_218 ;
else if ( F_483 ( V_2 ) )
V_4 -> V_202 . V_581 =
F_219 ;
else if ( F_103 ( V_2 ) || F_317 ( V_2 ) || F_482 ( V_2 ) )
V_4 -> V_202 . V_581 =
F_220 ;
else if ( F_131 ( V_2 ) )
V_4 -> V_202 . V_581 =
F_221 ;
else if ( F_318 ( V_2 ) )
V_4 -> V_202 . V_581 =
F_223 ;
else if ( F_484 ( V_2 ) )
V_4 -> V_202 . V_581 =
F_224 ;
else
V_4 -> V_202 . V_581 =
F_225 ;
if ( F_8 ( V_2 ) ) {
V_4 -> V_202 . V_1068 = V_1069 ;
V_4 -> V_202 . V_1070 = V_1071 ;
if ( F_147 ( V_2 ) ) {
T_1 V_1072 ;
F_119 ( & V_2 -> V_208 ) ;
F_485 ( V_4 ) ;
V_1072 = F_3 ( V_1073 ) ;
F_486 ( V_4 ) ;
F_120 ( & V_2 -> V_208 ) ;
if ( V_1072 & V_1074 ) {
F_25 ( L_193 ) ;
V_4 -> V_202 . V_1068 =
F_485 ;
V_4 -> V_202 . V_1070 =
F_486 ;
}
}
if ( F_82 ( V_2 ) )
V_4 -> V_202 . V_1067 = F_473 ;
else if ( F_38 ( V_2 ) )
V_4 -> V_202 . V_1067 = F_474 ;
if ( F_2 ( V_2 ) ) {
if ( F_3 ( V_1075 ) & V_1076 )
V_4 -> V_202 . V_520 = F_254 ;
else {
F_25 ( L_194
L_195 ) ;
V_4 -> V_202 . V_520 = NULL ;
}
V_4 -> V_202 . V_321 = F_156 ;
V_4 -> V_202 . V_1066 = F_461 ;
V_4 -> V_202 . V_666 = F_300 ;
} else if ( F_112 ( V_2 ) ) {
if ( F_258 () ) {
V_4 -> V_202 . V_520 = F_257 ;
} else {
F_25 ( L_196
L_195 ) ;
V_4 -> V_202 . V_520 = NULL ;
}
V_4 -> V_202 . V_321 = F_160 ;
V_4 -> V_202 . V_1066 = F_463 ;
V_4 -> V_202 . V_666 = F_300 ;
} else if ( F_147 ( V_2 ) ) {
V_4 -> V_202 . V_321 = F_161 ;
if ( F_258 () ) {
V_4 -> V_202 . V_520 = F_257 ;
} else {
F_25 ( L_196
L_195 ) ;
V_4 -> V_202 . V_520 = NULL ;
}
V_4 -> V_202 . V_1066 = F_465 ;
V_4 -> V_202 . V_666 = F_300 ;
} else
V_4 -> V_202 . V_520 = NULL ;
} else if ( F_10 ( V_2 ) ) {
if ( ! F_230 ( F_239 ( V_2 ) ,
V_4 -> V_412 ,
V_4 -> V_417 ,
V_4 -> V_418 ) ) {
F_270 ( L_197
L_198
L_199 ,
( V_4 -> V_412 == 1 ) ? L_200 : L_201 ,
V_4 -> V_417 , V_4 -> V_418 ) ;
F_232 ( V_2 ) ;
V_4 -> V_202 . V_520 = NULL ;
} else
V_4 -> V_202 . V_520 = F_238 ;
V_4 -> V_202 . V_1066 = F_470 ;
} else if ( F_9 ( V_2 ) ) {
V_4 -> V_202 . V_666 = F_297 ;
V_4 -> V_202 . V_520 = F_244 ;
V_4 -> V_202 . V_1066 = F_466 ;
} else if ( F_487 ( V_2 ) ) {
V_4 -> V_202 . V_520 = F_247 ;
if ( F_135 ( V_2 ) )
V_4 -> V_202 . V_1066 = F_468 ;
else if ( F_134 ( V_2 ) )
V_4 -> V_202 . V_1066 = F_469 ;
} else if ( F_404 ( V_2 ) ) {
V_4 -> V_202 . V_520 = F_248 ;
V_4 -> V_202 . V_482 = F_233 ;
V_4 -> V_202 . V_1066 = F_470 ;
} else if ( F_318 ( V_2 ) ) {
V_4 -> V_202 . V_520 = F_251 ;
V_4 -> V_202 . V_1066 = F_471 ;
V_4 -> V_202 . V_482 = F_236 ;
} else if ( F_484 ( V_2 ) ) {
V_4 -> V_202 . V_520 = F_248 ;
V_4 -> V_202 . V_482 = F_234 ;
V_4 -> V_202 . V_1066 = F_471 ;
} else {
V_4 -> V_202 . V_520 = F_251 ;
V_4 -> V_202 . V_1066 = F_472 ;
if ( F_317 ( V_2 ) )
V_4 -> V_202 . V_482 = F_235 ;
else
V_4 -> V_202 . V_482 = F_236 ;
}
V_4 -> V_202 . V_808 = F_391 ;
switch ( F_27 ( V_2 ) -> V_69 ) {
case 2 :
V_4 -> V_202 . V_808 = F_379 ;
break;
case 3 :
V_4 -> V_202 . V_808 = F_384 ;
break;
case 4 :
case 5 :
V_4 -> V_202 . V_808 = F_385 ;
break;
case 6 :
V_4 -> V_202 . V_808 = F_386 ;
break;
case 7 :
V_4 -> V_202 . V_808 = F_387 ;
break;
}
}
static void F_488 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_133 |= V_134 ;
F_299 ( L_202 ) ;
}
static void F_489 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_133 |= V_523 ;
}
static void F_490 ( struct V_1 * V_2 )
{
struct V_1077 * V_1078 = V_2 -> V_374 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < F_231 ( V_1079 ) ; V_101 ++ ) {
struct V_1080 * V_1081 = & V_1079 [ V_101 ] ;
if ( V_1078 -> V_1082 == V_1081 -> V_1082 &&
( V_1078 -> V_1083 == V_1081 -> V_1083 ||
V_1081 -> V_1083 == V_1084 ) &&
( V_1078 -> V_1085 == V_1081 -> V_1085 ||
V_1081 -> V_1085 == V_1084 ) )
V_1081 -> V_1086 ( V_2 ) ;
}
}
static void F_491 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_8 V_1087 ;
T_1 V_1088 ;
if ( F_8 ( V_2 ) )
V_1088 = V_1089 ;
else
V_1088 = V_1090 ;
F_492 ( V_2 -> V_374 , V_1091 ) ;
F_493 ( 1 , V_1092 ) ;
V_1087 = F_494 ( V_1093 ) ;
F_493 ( V_1087 | 1 << 5 , V_1093 ) ;
F_495 ( V_2 -> V_374 , V_1091 ) ;
F_73 ( 300 ) ;
F_23 ( V_1088 , V_1094 ) ;
F_72 ( V_1088 ) ;
}
void F_496 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_101 ;
F_497 ( V_2 ) ;
V_2 -> V_49 . V_1095 = 0 ;
V_2 -> V_49 . V_1096 = 0 ;
V_2 -> V_49 . V_733 = ( void * ) & V_1097 ;
F_490 ( V_2 ) ;
F_481 ( V_2 ) ;
if ( F_11 ( V_2 ) ) {
V_2 -> V_49 . V_1098 = 2048 ;
V_2 -> V_49 . V_1099 = 2048 ;
} else if ( F_404 ( V_2 ) ) {
V_2 -> V_49 . V_1098 = 4096 ;
V_2 -> V_49 . V_1099 = 4096 ;
} else {
V_2 -> V_49 . V_1098 = 8192 ;
V_2 -> V_49 . V_1099 = 8192 ;
}
V_2 -> V_49 . V_1100 = V_2 -> V_1101 -> V_52 ;
F_25 ( L_203 ,
V_4 -> V_1102 , V_4 -> V_1102 > 1 ? L_204 : L_205 ) ;
for ( V_101 = 0 ; V_101 < V_4 -> V_1102 ; V_101 ++ ) {
F_401 ( V_2 , V_101 ) ;
}
F_491 ( V_2 ) ;
F_412 ( V_2 ) ;
F_480 ( V_2 ) ;
if ( F_462 ( V_2 ) ) {
F_441 ( V_2 ) ;
F_451 ( V_2 ) ;
}
if ( F_112 ( V_2 ) || F_498 ( V_2 ) ) {
F_453 ( V_4 ) ;
F_458 ( V_4 ) ;
}
F_393 ( & V_4 -> V_765 , F_355 ) ;
F_406 ( & V_4 -> V_761 , F_349 ,
( unsigned long ) V_2 ) ;
}
void F_499 ( struct V_1 * V_2 )
{
if ( F_462 ( V_2 ) )
F_478 ( V_2 ) ;
F_500 ( V_2 ) ;
}
void F_501 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
struct V_150 * V_150 ;
F_502 ( V_2 ) ;
F_119 ( & V_2 -> V_208 ) ;
F_503 () ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_9 -> V_145 )
continue;
V_150 = F_102 ( V_9 ) ;
F_145 ( V_9 ) ;
}
F_128 ( V_2 ) ;
if ( F_462 ( V_2 ) )
F_445 ( V_2 ) ;
if ( F_112 ( V_2 ) || F_498 ( V_2 ) )
F_447 ( V_2 ) ;
if ( F_462 ( V_2 ) )
F_476 ( V_2 ) ;
F_120 ( & V_2 -> V_208 ) ;
F_504 ( V_2 ) ;
F_361 ( & V_4 -> V_1103 ) ;
F_361 ( & V_4 -> V_1104 ) ;
F_505 () ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
V_150 = F_102 ( V_9 ) ;
F_506 ( & V_150 -> V_761 ) ;
}
F_506 ( & V_4 -> V_761 ) ;
F_361 ( & V_4 -> V_765 ) ;
F_507 ( V_2 ) ;
}
struct V_366 * F_508 ( struct V_525 * V_526 )
{
return & F_509 ( V_526 ) -> V_52 ;
}
void F_510 ( struct V_1105 * V_526 ,
struct V_50 * V_51 )
{
V_526 -> V_51 = V_51 ;
F_511 ( & V_526 -> V_52 ,
& V_51 -> V_52 ) ;
}
int F_512 ( struct V_1 * V_2 , bool V_77 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_1106 ;
F_222 ( V_4 -> V_1107 , V_1108 , & V_1106 ) ;
if ( V_77 )
V_1106 &= ~ V_1109 ;
else
V_1106 |= V_1109 ;
F_513 ( V_4 -> V_1107 , V_1108 , V_1106 ) ;
return 0 ;
}
struct V_1110 *
F_514 ( struct V_1 * V_2 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_1110 * error ;
int V_101 ;
error = F_515 ( sizeof( * error ) , V_1111 ) ;
if ( error == NULL )
return NULL ;
for ( V_101 = 0 ; V_101 < 2 ; V_101 ++ ) {
error -> V_442 [ V_101 ] . V_1112 = F_3 ( F_310 ( V_101 ) ) ;
error -> V_442 [ V_101 ] . V_1113 = F_3 ( F_316 ( V_101 ) ) ;
error -> V_442 [ V_101 ] . V_52 = F_3 ( F_311 ( V_101 ) ) ;
error -> V_99 [ V_101 ] . V_1112 = F_3 ( F_50 ( V_101 ) ) ;
error -> V_99 [ V_101 ] . V_1114 = F_3 ( F_141 ( V_101 ) ) ;
error -> V_99 [ V_101 ] . V_225 = F_3 ( F_275 ( V_101 ) ) ;
error -> V_99 [ V_101 ] . V_688 = F_3 ( F_276 ( V_101 ) ) ;
error -> V_99 [ V_101 ] . V_700 = F_3 ( F_91 ( V_101 ) ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
error -> V_99 [ V_101 ] . V_1115 = F_3 ( F_92 ( V_101 ) ) ;
error -> V_99 [ V_101 ] . V_1116 = F_3 ( F_142 ( V_101 ) ) ;
}
error -> V_66 [ V_101 ] . V_1117 = F_3 ( F_28 ( V_101 ) ) ;
error -> V_66 [ V_101 ] . V_1118 = F_3 ( F_277 ( V_101 ) ) ;
error -> V_66 [ V_101 ] . V_446 = F_3 ( F_176 ( V_101 ) ) ;
error -> V_66 [ V_101 ] . V_1119 = F_3 ( F_178 ( V_101 ) ) ;
error -> V_66 [ V_101 ] . V_751 = F_3 ( F_180 ( V_101 ) ) ;
error -> V_66 [ V_101 ] . V_756 = F_3 ( F_182 ( V_101 ) ) ;
error -> V_66 [ V_101 ] . V_1120 = F_3 ( F_184 ( V_101 ) ) ;
error -> V_66 [ V_101 ] . V_753 = F_3 ( F_186 ( V_101 ) ) ;
}
return error ;
}
void
F_516 ( struct V_1121 * V_39 ,
struct V_1 * V_2 ,
struct V_1110 * error )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < 2 ; V_101 ++ ) {
F_517 ( V_39 , L_206 , V_101 ) ;
F_517 ( V_39 , L_207 , error -> V_66 [ V_101 ] . V_1117 ) ;
F_517 ( V_39 , L_208 , error -> V_66 [ V_101 ] . V_1118 ) ;
F_517 ( V_39 , L_209 , error -> V_66 [ V_101 ] . V_446 ) ;
F_517 ( V_39 , L_210 , error -> V_66 [ V_101 ] . V_1119 ) ;
F_517 ( V_39 , L_211 , error -> V_66 [ V_101 ] . V_751 ) ;
F_517 ( V_39 , L_212 , error -> V_66 [ V_101 ] . V_756 ) ;
F_517 ( V_39 , L_213 , error -> V_66 [ V_101 ] . V_1120 ) ;
F_517 ( V_39 , L_214 , error -> V_66 [ V_101 ] . V_753 ) ;
F_517 ( V_39 , L_215 , V_101 ) ;
F_517 ( V_39 , L_216 , error -> V_99 [ V_101 ] . V_1112 ) ;
F_517 ( V_39 , L_217 , error -> V_99 [ V_101 ] . V_1114 ) ;
F_517 ( V_39 , L_218 , error -> V_99 [ V_101 ] . V_225 ) ;
F_517 ( V_39 , L_219 , error -> V_99 [ V_101 ] . V_688 ) ;
F_517 ( V_39 , L_220 , error -> V_99 [ V_101 ] . V_700 ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
F_517 ( V_39 , L_221 , error -> V_99 [ V_101 ] . V_1115 ) ;
F_517 ( V_39 , L_222 , error -> V_99 [ V_101 ] . V_1116 ) ;
}
F_517 ( V_39 , L_223 , V_101 ) ;
F_517 ( V_39 , L_216 , error -> V_442 [ V_101 ] . V_1112 ) ;
F_517 ( V_39 , L_219 , error -> V_442 [ V_101 ] . V_1113 ) ;
F_517 ( V_39 , L_224 , error -> V_442 [ V_101 ] . V_52 ) ;
}
}
