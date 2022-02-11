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
memset ( V_56 , 0 , sizeof ( * V_56 ) ) ;
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
V_70 = F_38 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_79 = ! ! ( V_78 & V_80 ) ;
F_36 ( V_79 != V_77 ,
L_15 ,
F_33 ( V_77 ) , F_33 ( V_79 ) ) ;
}
static void F_39 ( struct V_3 * V_4 ,
enum V_66 V_66 , bool V_77 )
{
int V_70 ;
T_1 V_78 ;
bool V_79 ;
V_70 = F_40 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_79 = ! ! ( V_78 & V_81 ) ;
F_36 ( V_79 != V_77 ,
L_16 ,
F_33 ( V_77 ) , F_33 ( V_79 ) ) ;
}
static void F_41 ( struct V_3 * V_4 ,
enum V_66 V_66 , bool V_77 )
{
int V_70 ;
T_1 V_78 ;
bool V_79 ;
V_70 = F_42 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_79 = ! ! ( V_78 & V_82 ) ;
F_36 ( V_79 != V_77 ,
L_17 ,
F_33 ( V_77 ) , F_33 ( V_79 ) ) ;
}
static void F_43 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
if ( V_4 -> V_83 -> V_69 == 5 )
return;
V_70 = F_40 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
F_36 ( ! ( V_78 & V_84 ) , L_18 ) ;
}
static void F_44 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
V_70 = F_42 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
F_36 ( ! ( V_78 & V_85 ) , L_19 ) ;
}
static void F_45 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_86 , V_65 ;
T_1 V_78 ;
enum V_66 V_87 = V_88 ;
bool V_89 = true ;
if ( F_8 ( V_4 -> V_2 ) ) {
V_86 = V_90 ;
V_65 = V_13 ;
} else {
V_86 = V_91 ;
V_65 = V_24 ;
}
V_78 = F_3 ( V_86 ) ;
if ( ! ( V_78 & V_92 ) ||
( ( V_78 & V_93 ) == V_93 ) )
V_89 = false ;
if ( F_3 ( V_65 ) & V_94 )
V_87 = V_95 ;
F_36 ( V_87 == V_66 && V_89 ,
L_20 ,
F_46 ( V_66 ) ) ;
}
static void F_47 ( struct V_3 * V_4 ,
enum V_66 V_66 , bool V_77 )
{
int V_70 ;
T_1 V_78 ;
bool V_79 ;
V_70 = F_28 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_79 = ! ! ( V_78 & V_96 ) ;
F_36 ( V_79 != V_77 ,
L_21 ,
F_46 ( V_66 ) , F_33 ( V_77 ) , F_33 ( V_79 ) ) ;
}
static void F_48 ( struct V_3 * V_4 ,
enum V_97 V_97 )
{
int V_70 ;
T_1 V_78 ;
V_70 = F_49 ( V_97 ) ;
V_78 = F_3 ( V_70 ) ;
F_36 ( ! ( V_78 & V_98 ) ,
L_22 ,
F_50 ( V_97 ) ) ;
}
static void F_51 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 , V_99 ;
T_1 V_78 ;
int V_100 ;
if ( F_8 ( V_4 -> V_2 ) )
return;
for ( V_99 = 0 ; V_99 < 2 ; V_99 ++ ) {
V_70 = F_49 ( V_99 ) ;
V_78 = F_3 ( V_70 ) ;
V_100 = ( V_78 & V_101 ) >>
V_102 ;
F_36 ( ( V_78 & V_98 ) && V_66 == V_100 ,
L_23 ,
F_50 ( V_99 ) , F_46 ( V_66 ) ) ;
}
}
static void F_52 ( struct V_3 * V_4 )
{
T_1 V_78 ;
bool V_76 ;
V_78 = F_3 ( V_103 ) ;
V_76 = ! ! ( V_78 & ( V_104 | V_105 |
V_106 ) ) ;
F_36 ( ! V_76 , L_24 ) ;
}
static void F_53 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
bool V_76 ;
V_70 = F_54 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_76 = ! ! ( V_78 & V_107 ) ;
F_36 ( V_76 ,
L_25 ,
F_46 ( V_66 ) ) ;
}
static bool F_55 ( struct V_3 * V_4 ,
enum V_66 V_66 , T_1 V_108 , T_1 V_78 )
{
if ( ( V_78 & V_109 ) == 0 )
return false ;
if ( F_56 ( V_4 -> V_2 ) ) {
T_1 V_110 = F_57 ( V_66 ) ;
T_1 V_111 = F_3 ( V_110 ) ;
if ( ( V_111 & V_112 ) != V_108 )
return false ;
} else {
if ( ( V_78 & V_113 ) != ( V_66 << 30 ) )
return false ;
}
return true ;
}
static bool F_58 ( struct V_3 * V_4 ,
enum V_66 V_66 , T_1 V_78 )
{
if ( ( V_78 & V_114 ) == 0 )
return false ;
if ( F_56 ( V_4 -> V_2 ) ) {
if ( ( V_78 & V_115 ) != F_59 ( V_66 ) )
return false ;
} else {
if ( ( V_78 & V_116 ) != F_60 ( V_66 ) )
return false ;
}
return true ;
}
static bool F_61 ( struct V_3 * V_4 ,
enum V_66 V_66 , T_1 V_78 )
{
if ( ( V_78 & V_117 ) == 0 )
return false ;
if ( F_56 ( V_4 -> V_2 ) ) {
if ( ( V_78 & V_115 ) != F_59 ( V_66 ) )
return false ;
} else {
if ( ( V_78 & V_118 ) != F_62 ( V_66 ) )
return false ;
}
return true ;
}
static bool F_63 ( struct V_3 * V_4 ,
enum V_66 V_66 , T_1 V_78 )
{
if ( ( V_78 & V_119 ) == 0 )
return false ;
if ( F_56 ( V_4 -> V_2 ) ) {
if ( ( V_78 & V_115 ) != F_59 ( V_66 ) )
return false ;
} else {
if ( ( V_78 & V_120 ) != F_64 ( V_66 ) )
return false ;
}
return true ;
}
static void F_65 ( struct V_3 * V_4 ,
enum V_66 V_66 , int V_70 , T_1 V_108 )
{
T_1 V_78 = F_3 ( V_70 ) ;
F_36 ( F_55 ( V_4 , V_66 , V_108 , V_78 ) ,
L_26 ,
V_70 , F_46 ( V_66 ) ) ;
}
static void F_66 ( struct V_3 * V_4 ,
enum V_66 V_66 , int V_70 )
{
T_1 V_78 = F_3 ( V_70 ) ;
F_36 ( F_58 ( V_4 , V_78 , V_66 ) ,
L_26 ,
V_70 , F_46 ( V_66 ) ) ;
}
static void F_67 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_65 ( V_4 , V_66 , V_121 , V_122 ) ;
F_65 ( V_4 , V_66 , V_123 , V_124 ) ;
F_65 ( V_4 , V_66 , V_125 , V_126 ) ;
V_70 = V_127 ;
V_78 = F_3 ( V_70 ) ;
F_36 ( F_63 ( V_4 , V_78 , V_66 ) ,
L_27 ,
F_46 ( V_66 ) ) ;
V_70 = V_13 ;
V_78 = F_3 ( V_70 ) ;
F_36 ( F_61 ( V_4 , V_78 , V_66 ) ,
L_28 ,
F_46 ( V_66 ) ) ;
F_66 ( V_4 , V_66 , V_128 ) ;
F_66 ( V_4 , V_66 , V_129 ) ;
F_66 ( V_4 , V_66 , V_130 ) ;
}
static void F_68 ( struct V_3 * V_4 , enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_69 ( V_4 -> V_83 -> V_69 >= 5 ) ;
if ( F_70 ( V_4 -> V_2 ) && ! F_71 ( V_4 -> V_2 ) )
F_45 ( V_4 , V_66 ) ;
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
if ( V_66 == V_88 && ( V_4 -> V_131 & V_132 ) )
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
F_69 ( V_4 -> V_83 -> V_69 < 5 ) ;
F_52 ( V_4 ) ;
V_70 = F_38 ( V_66 ) ;
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
F_69 ( V_4 -> V_83 -> V_69 < 5 ) ;
F_53 ( V_4 , V_66 ) ;
V_70 = F_38 ( V_66 ) ;
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
F_69 ( V_4 -> V_83 -> V_69 < 5 ) ;
F_79 ( V_4 , V_66 ) ;
F_80 ( V_4 , V_66 ) ;
F_81 ( V_4 , V_66 ) ;
V_70 = F_54 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
if ( F_82 ( V_4 -> V_2 ) ) {
V_78 &= ~ V_133 ;
V_78 |= F_3 ( F_28 ( V_66 ) ) & V_133 ;
}
F_23 ( V_70 , V_78 | V_107 ) ;
if ( F_24 ( F_3 ( V_70 ) & V_134 , 100 ) )
F_83 ( L_29 , V_66 ) ;
}
static void F_84 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_85 ( V_4 , V_66 ) ;
F_86 ( V_4 , V_66 ) ;
F_67 ( V_4 , V_66 ) ;
V_70 = F_54 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_78 &= ~ V_107 ;
F_23 ( V_70 , V_78 ) ;
if ( F_24 ( ( F_3 ( V_70 ) & V_134 ) == 0 , 50 ) )
F_83 ( L_30 ) ;
}
static void F_87 ( struct V_3 * V_4 , enum V_66 V_66 ,
bool V_135 )
{
int V_70 ;
T_1 V_78 ;
if ( ! F_8 ( V_4 -> V_2 ) )
F_88 ( V_4 , V_66 ) ;
else {
if ( V_135 ) {
F_44 ( V_4 , V_66 ) ;
F_43 ( V_4 , V_66 ) ;
}
}
V_70 = F_28 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
if ( V_78 & V_96 )
return;
F_23 ( V_70 , V_78 | V_96 ) ;
F_21 ( V_4 -> V_2 , V_66 ) ;
}
static void F_89 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_51 ( V_4 , V_66 ) ;
if ( V_66 == V_88 && ( V_4 -> V_131 & V_132 ) )
return;
V_70 = F_28 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
if ( ( V_78 & V_96 ) == 0 )
return;
F_23 ( V_70 , V_78 & ~ V_96 ) ;
F_26 ( V_4 -> V_2 , V_66 ) ;
}
static void F_90 ( struct V_3 * V_4 ,
enum V_97 V_97 )
{
F_23 ( F_91 ( V_97 ) , F_3 ( F_91 ( V_97 ) ) ) ;
F_23 ( F_92 ( V_97 ) , F_3 ( F_92 ( V_97 ) ) ) ;
}
static void F_93 ( struct V_3 * V_4 ,
enum V_97 V_97 , enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_94 ( V_4 , V_66 ) ;
V_70 = F_49 ( V_97 ) ;
V_78 = F_3 ( V_70 ) ;
if ( V_78 & V_98 )
return;
F_23 ( V_70 , V_78 | V_98 ) ;
F_90 ( V_4 , V_97 ) ;
F_21 ( V_4 -> V_2 , V_66 ) ;
}
static void F_95 ( struct V_3 * V_4 ,
enum V_97 V_97 , enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
V_70 = F_49 ( V_97 ) ;
V_78 = F_3 ( V_70 ) ;
if ( ( V_78 & V_98 ) == 0 )
return;
F_23 ( V_70 , V_78 & ~ V_98 ) ;
F_90 ( V_4 , V_97 ) ;
F_21 ( V_4 -> V_2 , V_66 ) ;
}
static void F_96 ( struct V_3 * V_4 ,
enum V_66 V_66 , int V_70 , T_1 V_108 )
{
T_1 V_78 = F_3 ( V_70 ) ;
if ( F_55 ( V_4 , V_66 , V_108 , V_78 ) ) {
F_25 ( L_31 , V_70 , V_66 ) ;
F_23 ( V_70 , V_78 & ~ V_109 ) ;
}
}
static void F_97 ( struct V_3 * V_4 ,
enum V_66 V_66 , int V_70 )
{
T_1 V_78 = F_3 ( V_70 ) ;
if ( F_58 ( V_4 , V_78 , V_66 ) ) {
F_25 ( L_32 ,
V_70 , V_66 ) ;
F_23 ( V_70 , V_78 & ~ V_114 ) ;
}
}
static void F_98 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
T_1 V_70 , V_78 ;
V_78 = F_3 ( V_90 ) ;
F_23 ( V_90 , V_78 | V_93 ) ;
F_96 ( V_4 , V_66 , V_121 , V_122 ) ;
F_96 ( V_4 , V_66 , V_123 , V_124 ) ;
F_96 ( V_4 , V_66 , V_125 , V_126 ) ;
V_70 = V_127 ;
V_78 = F_3 ( V_70 ) ;
if ( F_63 ( V_4 , V_78 , V_66 ) )
F_23 ( V_70 , V_78 & ~ V_119 ) ;
V_70 = V_13 ;
V_78 = F_3 ( V_70 ) ;
if ( F_61 ( V_4 , V_78 , V_66 ) ) {
F_25 ( L_33 , V_66 , V_78 ) ;
F_23 ( V_70 , V_78 & ~ V_117 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
}
F_97 ( V_4 , V_66 , V_128 ) ;
F_97 ( V_4 , V_66 , V_129 ) ;
F_97 ( V_4 , V_66 , V_130 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_136 ;
V_136 = F_3 ( V_137 ) ;
if ( ( V_136 & V_138 ) == 0 )
return;
V_136 &= ~ V_138 ;
F_23 ( V_137 , V_136 ) ;
if ( F_24 ( ( F_3 ( V_139 ) & V_140 ) == 0 , 10 ) ) {
F_25 ( L_34 ) ;
return;
}
F_25 ( L_35 ) ;
}
static void F_100 ( struct V_8 * V_9 , unsigned long V_141 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_142 * V_143 = V_9 -> V_143 ;
struct V_144 * V_145 = F_101 ( V_143 ) ;
struct V_146 * V_147 = V_145 -> V_147 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_149 ;
int V_97 , V_99 ;
T_1 V_136 , V_150 ;
V_149 = V_4 -> V_151 / V_152 ;
if ( V_143 -> V_153 < V_149 )
V_149 = V_143 -> V_153 ;
V_149 = ( V_149 / 64 ) - 1 ;
V_97 = V_148 -> V_97 == 0 ? V_154 : V_155 ;
for ( V_99 = 0 ; V_99 < ( V_152 / 32 ) + 1 ; V_99 ++ )
F_23 ( V_156 + ( V_99 * 4 ) , 0 ) ;
V_150 = V_157 | V_158 | V_159 ;
V_150 |= V_97 ;
F_23 ( V_160 , V_150 ) ;
F_23 ( V_161 , V_9 -> V_162 ) ;
V_136 = V_138 | V_163 ;
if ( F_103 ( V_2 ) )
V_136 |= V_164 ;
V_136 |= ( V_149 & 0xff ) << V_165 ;
V_136 |= ( V_141 & 0x2fff ) << V_166 ;
V_136 |= V_147 -> V_167 ;
F_23 ( V_137 , V_136 ) ;
F_25 ( L_36 ,
V_149 , V_9 -> V_162 , V_148 -> V_97 ) ;
}
static bool F_104 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_137 ) & V_138 ;
}
static void F_105 ( struct V_8 * V_9 , unsigned long V_141 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_142 * V_143 = V_9 -> V_143 ;
struct V_144 * V_145 = F_101 ( V_143 ) ;
struct V_146 * V_147 = V_145 -> V_147 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_97 = V_148 -> V_97 == 0 ? V_168 : V_169 ;
unsigned long V_170 = 200 ;
T_1 V_171 ;
V_171 = V_97 | V_172 | V_173 ;
V_171 |= V_174 | V_147 -> V_167 ;
F_23 ( V_175 , V_176 ) ;
F_23 ( V_177 , V_178 |
( V_170 << V_179 ) |
( V_141 << V_180 ) ) ;
F_23 ( V_181 , V_9 -> V_162 ) ;
F_23 ( V_182 , F_3 ( V_182 ) | V_183 ) ;
F_25 ( L_37 , V_148 -> V_97 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_171 ;
V_171 = F_3 ( V_182 ) ;
if ( V_171 & V_183 ) {
V_171 &= ~ V_183 ;
F_23 ( V_182 , V_171 ) ;
F_25 ( L_35 ) ;
}
}
static bool F_107 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_182 ) & V_183 ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_184 ;
F_109 ( V_4 ) ;
V_184 = F_3 ( V_185 ) ;
V_184 |= V_186 <<
V_187 ;
F_23 ( V_185 , V_184 ) ;
V_184 |= V_186 ;
F_23 ( V_185 , V_184 ) ;
V_184 &= ~ ( V_186 <<
V_187 ) ;
F_23 ( V_185 , V_184 ) ;
F_72 ( V_185 ) ;
F_110 ( V_4 ) ;
}
static void F_111 ( struct V_8 * V_9 , unsigned long V_141 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_142 * V_143 = V_9 -> V_143 ;
struct V_144 * V_145 = F_101 ( V_143 ) ;
struct V_146 * V_147 = V_145 -> V_147 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_97 = V_148 -> V_97 == 0 ? V_168 : V_169 ;
unsigned long V_170 = 200 ;
T_1 V_171 ;
V_171 = F_3 ( V_188 ) ;
V_171 &= V_189 ;
V_171 |= ( V_97 | V_173 ) ;
V_171 |= V_190 ;
V_171 |= ( V_174 | V_147 -> V_167 ) ;
F_23 ( V_191 , V_176 ) ;
F_23 ( V_192 , V_178 |
( V_170 << V_179 ) |
( V_141 << V_180 ) ) ;
F_23 ( V_193 , V_9 -> V_162 ) ;
F_23 ( V_194 , V_147 -> V_195 | V_196 ) ;
F_23 ( V_188 , V_171 | V_183 ) ;
if ( F_112 ( V_2 ) ) {
F_23 ( V_197 ,
V_198 | V_147 -> V_167 ) ;
F_23 ( V_199 , V_9 -> V_162 ) ;
F_108 ( V_2 ) ;
}
F_25 ( L_37 , V_148 -> V_97 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_171 ;
V_171 = F_3 ( V_188 ) ;
if ( V_171 & V_183 ) {
V_171 &= ~ V_183 ;
F_23 ( V_188 , V_171 ) ;
F_25 ( L_35 ) ;
}
}
static bool F_114 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_188 ) & V_183 ;
}
bool F_115 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_200 . V_201 )
return false ;
return V_4 -> V_200 . V_201 ( V_2 ) ;
}
static void F_116 ( struct V_202 * V_203 )
{
struct V_204 * V_205 =
F_117 ( F_118 ( V_203 ) ,
struct V_204 , V_205 ) ;
struct V_1 * V_2 = V_205 -> V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_119 ( & V_2 -> V_206 ) ;
if ( V_205 == V_4 -> V_207 ) {
if ( V_205 -> V_9 -> V_143 == V_205 -> V_143 ) {
V_4 -> V_200 . V_208 ( V_205 -> V_9 ,
V_205 -> V_141 ) ;
V_4 -> V_209 = F_102 ( V_205 -> V_9 ) -> V_97 ;
V_4 -> V_210 = V_205 -> V_9 -> V_143 -> V_52 . V_211 ;
V_4 -> V_212 = V_205 -> V_9 -> V_162 ;
}
V_4 -> V_207 = NULL ;
}
F_120 ( & V_2 -> V_206 ) ;
F_121 ( V_205 ) ;
}
static void F_122 ( struct V_3 * V_4 )
{
if ( V_4 -> V_207 == NULL )
return;
F_25 ( L_38 ) ;
if ( F_123 ( & V_4 -> V_207 -> V_205 ) )
F_121 ( V_4 -> V_207 ) ;
V_4 -> V_207 = NULL ;
}
static void F_124 ( struct V_8 * V_9 , unsigned long V_141 )
{
struct V_204 * V_205 ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_200 . V_208 )
return;
F_122 ( V_4 ) ;
V_205 = F_125 ( sizeof *V_205 , V_213 ) ;
if ( V_205 == NULL ) {
V_4 -> V_200 . V_208 ( V_9 , V_141 ) ;
return;
}
V_205 -> V_9 = V_9 ;
V_205 -> V_143 = V_9 -> V_143 ;
V_205 -> V_141 = V_141 ;
F_126 ( & V_205 -> V_205 , F_116 ) ;
V_4 -> V_207 = V_205 ;
F_25 ( L_39 ) ;
F_127 ( & V_205 -> V_205 , F_30 ( 50 ) ) ;
}
void F_128 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_122 ( V_4 ) ;
if ( ! V_4 -> V_200 . V_214 )
return;
V_4 -> V_200 . V_214 ( V_2 ) ;
V_4 -> V_209 = - 1 ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = NULL , * V_215 ;
struct V_148 * V_148 ;
struct V_142 * V_143 ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
int V_208 ;
F_25 ( L_40 ) ;
if ( ! V_216 )
return;
if ( ! F_130 ( V_2 ) )
return;
F_14 (tmp_crtc, &dev->mode_config.crtc_list, head) {
if ( V_215 -> V_76 && V_215 -> V_143 ) {
if ( V_9 ) {
F_25 ( L_41 ) ;
V_4 -> V_217 = V_218 ;
goto V_219;
}
V_9 = V_215 ;
}
}
if ( ! V_9 || V_9 -> V_143 == NULL ) {
F_25 ( L_42 ) ;
V_4 -> V_217 = V_220 ;
goto V_219;
}
V_148 = F_102 ( V_9 ) ;
V_143 = V_9 -> V_143 ;
V_145 = F_101 ( V_143 ) ;
V_147 = V_145 -> V_147 ;
V_208 = V_221 ;
if ( V_208 < 0 ) {
F_25 ( L_43 ) ;
V_208 = 1 ;
if ( F_27 ( V_2 ) -> V_69 <= 5 )
V_208 = 0 ;
}
if ( ! V_208 ) {
F_25 ( L_44 ) ;
V_4 -> V_217 = V_222 ;
goto V_219;
}
if ( V_145 -> V_147 -> V_52 . V_223 > V_4 -> V_151 ) {
F_25 ( L_45
L_46 ) ;
V_4 -> V_217 = V_224 ;
goto V_219;
}
if ( ( V_9 -> V_225 . V_226 & V_227 ) ||
( V_9 -> V_225 . V_226 & V_228 ) ) {
F_25 ( L_47
L_48 ) ;
V_4 -> V_217 = V_229 ;
goto V_219;
}
if ( ( V_9 -> V_225 . V_230 > 2048 ) ||
( V_9 -> V_225 . V_231 > 1536 ) ) {
F_25 ( L_49 ) ;
V_4 -> V_217 = V_232 ;
goto V_219;
}
if ( ( F_131 ( V_2 ) || F_103 ( V_2 ) ) && V_148 -> V_97 != 0 ) {
F_25 ( L_50 ) ;
V_4 -> V_217 = V_233 ;
goto V_219;
}
if ( V_147 -> V_234 != V_235 ||
V_147 -> V_167 == V_236 ) {
F_25 ( L_51 ) ;
V_4 -> V_217 = V_237 ;
goto V_219;
}
if ( F_132 () )
goto V_219;
if ( V_4 -> V_209 == V_148 -> V_97 &&
V_4 -> V_210 == V_143 -> V_52 . V_211 &&
V_4 -> V_212 == V_9 -> V_162 )
return;
if ( F_115 ( V_2 ) ) {
F_25 ( L_52 ) ;
F_128 ( V_2 ) ;
}
F_124 ( V_9 , 500 ) ;
return;
V_219:
if ( F_115 ( V_2 ) ) {
F_25 ( L_53 ) ;
F_128 ( V_2 ) ;
}
}
int
F_133 ( struct V_1 * V_2 ,
struct V_146 * V_147 ,
struct V_238 * V_239 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_240 ;
int V_241 ;
switch ( V_147 -> V_234 ) {
case V_242 :
if ( F_134 ( V_2 ) || F_135 ( V_2 ) )
V_240 = 128 * 1024 ;
else if ( F_27 ( V_2 ) -> V_69 >= 4 )
V_240 = 4 * 1024 ;
else
V_240 = 64 * 1024 ;
break;
case V_235 :
V_240 = 0 ;
break;
case V_243 :
F_83 ( L_54 ) ;
return - V_244 ;
default:
F_136 () ;
}
V_4 -> V_245 . V_246 = false ;
V_241 = F_137 ( V_147 , V_240 , V_239 ) ;
if ( V_241 )
goto V_247;
if ( V_147 -> V_234 != V_242 ) {
V_241 = F_138 ( V_147 , V_239 ) ;
if ( V_241 )
goto V_248;
}
V_4 -> V_245 . V_246 = true ;
return 0 ;
V_248:
F_139 ( V_147 ) ;
V_247:
V_4 -> V_245 . V_246 = true ;
return V_241 ;
}
static int F_140 ( struct V_8 * V_9 , struct V_142 * V_143 ,
int V_249 , int V_162 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
int V_97 = V_148 -> V_97 ;
unsigned long V_250 , V_251 ;
T_1 V_252 ;
T_1 V_70 ;
switch ( V_97 ) {
case 0 :
case 1 :
break;
default:
F_83 ( L_55 , V_97 ) ;
return - V_244 ;
}
V_145 = F_101 ( V_143 ) ;
V_147 = V_145 -> V_147 ;
V_70 = F_49 ( V_97 ) ;
V_252 = F_3 ( V_70 ) ;
V_252 &= ~ V_253 ;
switch ( V_143 -> V_254 ) {
case 8 :
V_252 |= V_255 ;
break;
case 16 :
if ( V_143 -> V_256 == 15 )
V_252 |= V_257 ;
else
V_252 |= V_258 ;
break;
case 24 :
case 32 :
V_252 |= V_259 ;
break;
default:
F_83 ( L_56 , V_143 -> V_254 ) ;
return - V_244 ;
}
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
if ( V_147 -> V_234 != V_242 )
V_252 |= V_260 ;
else
V_252 &= ~ V_260 ;
}
F_23 ( V_70 , V_252 ) ;
V_250 = V_147 -> V_195 ;
V_251 = V_162 * V_143 -> V_153 + V_249 * ( V_143 -> V_254 / 8 ) ;
F_25 ( L_57 ,
V_250 , V_251 , V_249 , V_162 , V_143 -> V_153 ) ;
F_23 ( F_141 ( V_97 ) , V_143 -> V_153 ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
F_23 ( F_92 ( V_97 ) , V_250 ) ;
F_23 ( F_142 ( V_97 ) , ( V_162 << 16 ) | V_249 ) ;
F_23 ( F_91 ( V_97 ) , V_251 ) ;
} else
F_23 ( F_91 ( V_97 ) , V_250 + V_251 ) ;
F_72 ( V_70 ) ;
return 0 ;
}
static int F_143 ( struct V_8 * V_9 ,
struct V_142 * V_143 , int V_249 , int V_162 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
int V_97 = V_148 -> V_97 ;
unsigned long V_250 , V_251 ;
T_1 V_252 ;
T_1 V_70 ;
switch ( V_97 ) {
case 0 :
case 1 :
break;
default:
F_83 ( L_55 , V_97 ) ;
return - V_244 ;
}
V_145 = F_101 ( V_143 ) ;
V_147 = V_145 -> V_147 ;
V_70 = F_49 ( V_97 ) ;
V_252 = F_3 ( V_70 ) ;
V_252 &= ~ V_253 ;
switch ( V_143 -> V_254 ) {
case 8 :
V_252 |= V_255 ;
break;
case 16 :
if ( V_143 -> V_256 != 16 )
return - V_244 ;
V_252 |= V_258 ;
break;
case 24 :
case 32 :
if ( V_143 -> V_256 == 24 )
V_252 |= V_259 ;
else if ( V_143 -> V_256 == 30 )
V_252 |= V_261 ;
else
return - V_244 ;
break;
default:
F_83 ( L_56 , V_143 -> V_254 ) ;
return - V_244 ;
}
if ( V_147 -> V_234 != V_242 )
V_252 |= V_260 ;
else
V_252 &= ~ V_260 ;
V_252 |= V_262 ;
F_23 ( V_70 , V_252 ) ;
V_250 = V_147 -> V_195 ;
V_251 = V_162 * V_143 -> V_153 + V_249 * ( V_143 -> V_254 / 8 ) ;
F_25 ( L_57 ,
V_250 , V_251 , V_249 , V_162 , V_143 -> V_153 ) ;
F_23 ( F_141 ( V_97 ) , V_143 -> V_153 ) ;
F_23 ( F_92 ( V_97 ) , V_250 ) ;
F_23 ( F_142 ( V_97 ) , ( V_162 << 16 ) | V_249 ) ;
F_23 ( F_91 ( V_97 ) , V_251 ) ;
F_72 ( V_70 ) ;
return 0 ;
}
static int
F_144 ( struct V_8 * V_9 , struct V_142 * V_143 ,
int V_249 , int V_162 , enum V_263 V_77 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_241 ;
V_241 = V_4 -> V_200 . V_264 ( V_9 , V_143 , V_249 , V_162 ) ;
if ( V_241 )
return V_241 ;
F_129 ( V_2 ) ;
F_145 ( V_9 ) ;
return 0 ;
}
static int
F_146 ( struct V_8 * V_9 , int V_249 , int V_162 ,
struct V_142 * V_265 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_266 * V_267 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_241 ;
if ( ! V_9 -> V_143 ) {
F_83 ( L_58 ) ;
return 0 ;
}
switch ( V_148 -> V_97 ) {
case 0 :
case 1 :
break;
default:
F_83 ( L_59 ) ;
return - V_244 ;
}
F_119 ( & V_2 -> V_206 ) ;
V_241 = F_133 ( V_2 ,
F_101 ( V_9 -> V_143 ) -> V_147 ,
NULL ) ;
if ( V_241 != 0 ) {
F_120 ( & V_2 -> V_206 ) ;
F_83 ( L_60 ) ;
return V_241 ;
}
if ( V_265 ) {
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_146 * V_147 = F_101 ( V_265 ) -> V_147 ;
F_147 ( V_4 -> V_268 ,
F_148 ( & V_4 -> V_245 . V_269 ) ||
F_148 ( & V_147 -> V_270 ) == 0 ) ;
V_241 = F_149 ( V_147 ) ;
( void ) V_241 ;
}
V_241 = F_144 ( V_9 , V_9 -> V_143 , V_249 , V_162 ,
V_271 ) ;
if ( V_241 ) {
F_139 ( F_101 ( V_9 -> V_143 ) -> V_147 ) ;
F_120 ( & V_2 -> V_206 ) ;
F_83 ( L_61 ) ;
return V_241 ;
}
if ( V_265 ) {
F_21 ( V_2 , V_148 -> V_66 ) ;
F_139 ( F_101 ( V_265 ) -> V_147 ) ;
}
F_120 ( & V_2 -> V_206 ) ;
if ( ! V_2 -> V_272 -> V_273 )
return 0 ;
V_267 = V_2 -> V_272 -> V_273 -> V_274 ;
if ( ! V_267 -> V_275 )
return 0 ;
if ( V_148 -> V_66 ) {
V_267 -> V_275 -> V_276 = V_249 ;
V_267 -> V_275 -> V_277 = V_162 ;
} else {
V_267 -> V_275 -> V_278 = V_249 ;
V_267 -> V_275 -> V_279 = V_162 ;
}
return 0 ;
}
static void F_150 ( struct V_8 * V_9 , int clock )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_280 ;
F_25 ( L_62 , clock ) ;
V_280 = F_3 ( V_281 ) ;
V_280 &= ~ V_282 ;
if ( clock < 200000 ) {
T_1 V_283 ;
V_280 |= V_284 ;
V_283 = F_3 ( 0x4600c ) ;
V_283 &= 0xffff0000 ;
F_23 ( 0x4600c , V_283 | 0x8124 ) ;
V_283 = F_3 ( 0x46010 ) ;
F_23 ( 0x46010 , V_283 | 1 ) ;
V_283 = F_3 ( 0x46034 ) ;
F_23 ( 0x46034 , V_283 | ( 1 << 24 ) ) ;
} else {
V_280 |= V_285 ;
}
F_23 ( V_281 , V_280 ) ;
F_72 ( V_281 ) ;
F_73 ( 500 ) ;
}
static void F_151 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
T_1 V_70 , V_283 ;
V_70 = F_40 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
if ( F_152 ( V_2 ) ) {
V_283 &= ~ V_286 ;
V_283 |= V_286 | V_287 ;
} else {
V_283 &= ~ V_288 ;
V_283 |= V_288 | V_287 ;
}
F_23 ( V_70 , V_283 ) ;
V_70 = F_42 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
if ( F_56 ( V_2 ) ) {
V_283 &= ~ V_289 ;
V_283 |= V_290 ;
} else {
V_283 &= ~ V_288 ;
V_283 |= V_288 ;
}
F_23 ( V_70 , V_283 | V_291 ) ;
F_72 ( V_70 ) ;
F_73 ( 1000 ) ;
if ( F_152 ( V_2 ) )
F_23 ( V_70 , F_3 ( V_70 ) | V_292 |
V_293 ) ;
}
static void F_153 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_226 = F_3 ( V_294 ) ;
V_226 |= F_154 ( V_66 ) ;
F_23 ( V_294 , V_226 ) ;
V_226 |= F_155 ( V_66 ) ;
F_23 ( V_294 , V_226 ) ;
F_72 ( V_294 ) ;
}
static void F_156 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
int V_97 = V_148 -> V_97 ;
T_1 V_70 , V_283 , V_295 ;
F_94 ( V_4 , V_66 ) ;
F_48 ( V_4 , V_97 ) ;
V_70 = F_157 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ V_296 ;
V_283 &= ~ V_297 ;
F_23 ( V_70 , V_283 ) ;
F_3 ( V_70 ) ;
F_73 ( 150 ) ;
V_70 = F_40 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ ( 7 << 19 ) ;
V_283 |= ( V_148 -> V_298 - 1 ) << 19 ;
V_283 &= ~ V_288 ;
V_283 |= V_299 ;
F_23 ( V_70 , V_283 | V_81 ) ;
V_70 = F_42 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ V_288 ;
V_283 |= V_299 ;
F_23 ( V_70 , V_283 | V_82 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
if ( F_82 ( V_2 ) ) {
F_23 ( F_158 ( V_66 ) , V_300 ) ;
F_23 ( F_158 ( V_66 ) , V_300 |
V_301 ) ;
}
V_70 = F_159 ( V_66 ) ;
for ( V_295 = 0 ; V_295 < 5 ; V_295 ++ ) {
V_283 = F_3 ( V_70 ) ;
F_25 ( L_63 , V_283 ) ;
if ( ( V_283 & V_297 ) ) {
F_25 ( L_64 ) ;
F_23 ( V_70 , V_283 | V_297 ) ;
break;
}
}
if ( V_295 == 5 )
F_83 ( L_65 ) ;
V_70 = F_40 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ V_288 ;
V_283 |= V_302 ;
F_23 ( V_70 , V_283 ) ;
V_70 = F_42 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ V_288 ;
V_283 |= V_302 ;
F_23 ( V_70 , V_283 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
V_70 = F_159 ( V_66 ) ;
for ( V_295 = 0 ; V_295 < 5 ; V_295 ++ ) {
V_283 = F_3 ( V_70 ) ;
F_25 ( L_63 , V_283 ) ;
if ( V_283 & V_296 ) {
F_23 ( V_70 , V_283 | V_296 ) ;
F_25 ( L_66 ) ;
break;
}
}
if ( V_295 == 5 )
F_83 ( L_67 ) ;
F_25 ( L_68 ) ;
}
static void F_160 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
T_1 V_70 , V_283 , V_99 ;
V_70 = F_157 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ V_296 ;
V_283 &= ~ V_297 ;
F_23 ( V_70 , V_283 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
V_70 = F_40 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ ( 7 << 19 ) ;
V_283 |= ( V_148 -> V_298 - 1 ) << 19 ;
V_283 &= ~ V_288 ;
V_283 |= V_299 ;
V_283 &= ~ V_303 ;
V_283 |= V_304 ;
F_23 ( V_70 , V_283 | V_81 ) ;
V_70 = F_42 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
if ( F_56 ( V_2 ) ) {
V_283 &= ~ V_289 ;
V_283 |= V_305 ;
} else {
V_283 &= ~ V_288 ;
V_283 |= V_299 ;
}
F_23 ( V_70 , V_283 | V_82 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
if ( F_56 ( V_2 ) )
F_153 ( V_2 , V_66 ) ;
for ( V_99 = 0 ; V_99 < 4 ; V_99 ++ ) {
V_70 = F_40 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ V_303 ;
V_283 |= V_306 [ V_99 ] ;
F_23 ( V_70 , V_283 ) ;
F_72 ( V_70 ) ;
F_73 ( 500 ) ;
V_70 = F_159 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
F_25 ( L_63 , V_283 ) ;
if ( V_283 & V_297 ) {
F_23 ( V_70 , V_283 | V_297 ) ;
F_25 ( L_64 ) ;
break;
}
}
if ( V_99 == 4 )
F_83 ( L_65 ) ;
V_70 = F_40 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ V_288 ;
V_283 |= V_302 ;
if ( F_112 ( V_2 ) ) {
V_283 &= ~ V_303 ;
V_283 |= V_304 ;
}
F_23 ( V_70 , V_283 ) ;
V_70 = F_42 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
if ( F_56 ( V_2 ) ) {
V_283 &= ~ V_289 ;
V_283 |= V_307 ;
} else {
V_283 &= ~ V_288 ;
V_283 |= V_302 ;
}
F_23 ( V_70 , V_283 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
for ( V_99 = 0 ; V_99 < 4 ; V_99 ++ ) {
V_70 = F_40 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ V_303 ;
V_283 |= V_306 [ V_99 ] ;
F_23 ( V_70 , V_283 ) ;
F_72 ( V_70 ) ;
F_73 ( 500 ) ;
V_70 = F_159 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
F_25 ( L_63 , V_283 ) ;
if ( V_283 & V_296 ) {
F_23 ( V_70 , V_283 | V_296 ) ;
F_25 ( L_66 ) ;
break;
}
}
if ( V_99 == 4 )
F_83 ( L_67 ) ;
F_25 ( L_69 ) ;
}
static void F_161 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
T_1 V_70 , V_283 , V_99 ;
V_70 = F_157 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ V_296 ;
V_283 &= ~ V_297 ;
F_23 ( V_70 , V_283 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
V_70 = F_40 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ ( 7 << 19 ) ;
V_283 |= ( V_148 -> V_298 - 1 ) << 19 ;
V_283 &= ~ ( V_308 | V_286 ) ;
V_283 |= V_309 ;
V_283 &= ~ V_303 ;
V_283 |= V_304 ;
F_23 ( V_70 , V_283 | V_81 ) ;
V_70 = F_42 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ V_308 ;
V_283 &= ~ V_289 ;
V_283 |= V_305 ;
F_23 ( V_70 , V_283 | V_82 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
if ( F_56 ( V_2 ) )
F_153 ( V_2 , V_66 ) ;
for ( V_99 = 0 ; V_99 < 4 ; V_99 ++ ) {
V_70 = F_40 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ V_303 ;
V_283 |= V_306 [ V_99 ] ;
F_23 ( V_70 , V_283 ) ;
F_72 ( V_70 ) ;
F_73 ( 500 ) ;
V_70 = F_159 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
F_25 ( L_63 , V_283 ) ;
if ( V_283 & V_297 ||
( F_3 ( V_70 ) & V_297 ) ) {
F_23 ( V_70 , V_283 | V_297 ) ;
F_25 ( L_64 ) ;
break;
}
}
if ( V_99 == 4 )
F_83 ( L_65 ) ;
V_70 = F_40 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ V_286 ;
V_283 |= V_310 ;
V_283 &= ~ V_303 ;
V_283 |= V_304 ;
F_23 ( V_70 , V_283 ) ;
V_70 = F_42 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ V_289 ;
V_283 |= V_307 ;
F_23 ( V_70 , V_283 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
for ( V_99 = 0 ; V_99 < 4 ; V_99 ++ ) {
V_70 = F_40 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ V_303 ;
V_283 |= V_306 [ V_99 ] ;
F_23 ( V_70 , V_283 ) ;
F_72 ( V_70 ) ;
F_73 ( 500 ) ;
V_70 = F_159 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
F_25 ( L_63 , V_283 ) ;
if ( V_283 & V_296 ) {
F_23 ( V_70 , V_283 | V_296 ) ;
F_25 ( L_66 ) ;
break;
}
}
if ( V_99 == 4 )
F_83 ( L_67 ) ;
F_25 ( L_69 ) ;
}
static void F_162 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
T_1 V_70 , V_283 ;
F_23 ( F_163 ( V_66 ) ,
F_3 ( F_164 ( V_66 ) ) & V_311 ) ;
V_70 = F_42 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ ( ( 0x7 << 19 ) | ( 0x7 << 16 ) ) ;
V_283 |= ( V_148 -> V_298 - 1 ) << 19 ;
V_283 |= ( F_3 ( F_28 ( V_66 ) ) & V_133 ) << 11 ;
F_23 ( V_70 , V_283 | V_85 ) ;
F_72 ( V_70 ) ;
F_73 ( 200 ) ;
V_283 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_283 | V_312 ) ;
F_72 ( V_70 ) ;
F_73 ( 200 ) ;
V_70 = F_40 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
if ( ( V_283 & V_84 ) == 0 ) {
F_23 ( V_70 , V_283 | V_84 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
}
}
static void F_165 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_226 = F_3 ( V_294 ) ;
V_226 &= ~ ( F_155 ( V_66 ) ) ;
F_23 ( V_294 , V_226 ) ;
V_226 &= ~ ( F_154 ( V_66 ) ) ;
F_23 ( V_294 , V_226 ) ;
F_72 ( V_294 ) ;
}
static void F_166 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
T_1 V_70 , V_283 ;
V_70 = F_40 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_283 & ~ V_81 ) ;
F_72 ( V_70 ) ;
V_70 = F_42 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ ( 0x7 << 16 ) ;
V_283 |= ( F_3 ( F_28 ( V_66 ) ) & V_133 ) << 11 ;
F_23 ( V_70 , V_283 & ~ V_82 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
if ( F_82 ( V_2 ) ) {
F_23 ( F_158 ( V_66 ) , V_300 ) ;
F_23 ( F_158 ( V_66 ) ,
F_3 ( F_158 ( V_66 ) &
~ V_301 ) ) ;
} else if ( F_56 ( V_2 ) ) {
F_165 ( V_2 , V_66 ) ;
}
V_70 = F_40 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ V_288 ;
V_283 |= V_299 ;
F_23 ( V_70 , V_283 ) ;
V_70 = F_42 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
if ( F_56 ( V_2 ) ) {
V_283 &= ~ V_289 ;
V_283 |= V_305 ;
} else {
V_283 &= ~ V_288 ;
V_283 |= V_299 ;
}
V_283 &= ~ ( 0x07 << 16 ) ;
V_283 |= ( F_3 ( F_28 ( V_66 ) ) & V_133 ) << 11 ;
F_23 ( V_70 , V_283 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_238 * V_313 ;
T_1 V_314 ;
if ( F_11 ( V_2 ) )
return;
V_313 = F_168 ( V_4 ) ;
V_314 = F_169 ( V_313 ) ;
if ( V_314 & V_315 )
F_170 ( V_313 , V_314 ) ;
}
static void F_171 ( struct V_8 * V_9 )
{
struct V_146 * V_147 ;
struct V_3 * V_4 ;
if ( V_9 -> V_143 == NULL )
return;
V_147 = F_101 ( V_9 -> V_143 ) -> V_147 ;
V_4 = V_9 -> V_2 -> V_5 ;
F_147 ( V_4 -> V_268 ,
F_148 ( & V_147 -> V_270 ) == 0 ) ;
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
case V_316 :
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
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
T_1 V_70 , V_283 ;
V_4 -> V_200 . V_317 ( V_9 ) ;
F_76 ( V_4 , V_66 ) ;
if ( F_56 ( V_2 ) ) {
V_283 = F_3 ( V_318 ) ;
if ( V_66 == 0 && ( V_283 & V_319 ) == 0 )
V_283 |= ( V_319 | V_320 ) ;
else if ( V_66 == 1 && ( V_283 & V_321 ) == 0 )
V_283 |= ( V_321 | V_322 ) ;
F_23 ( V_318 , V_283 ) ;
}
F_45 ( V_4 , V_66 ) ;
F_23 ( F_175 ( V_66 ) , F_3 ( F_176 ( V_66 ) ) ) ;
F_23 ( F_177 ( V_66 ) , F_3 ( F_178 ( V_66 ) ) ) ;
F_23 ( F_179 ( V_66 ) , F_3 ( F_180 ( V_66 ) ) ) ;
F_23 ( F_181 ( V_66 ) , F_3 ( F_182 ( V_66 ) ) ) ;
F_23 ( F_183 ( V_66 ) , F_3 ( F_184 ( V_66 ) ) ) ;
F_23 ( F_185 ( V_66 ) , F_3 ( F_186 ( V_66 ) ) ) ;
F_151 ( V_9 ) ;
if ( F_56 ( V_2 ) &&
F_5 ( V_9 , V_20 ) ) {
T_1 V_323 = ( F_3 ( F_28 ( V_66 ) ) & V_133 ) >> 5 ;
V_70 = F_57 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ ( V_112 |
V_324 |
V_325 ) ;
V_283 |= ( V_326 |
V_327 ) ;
V_283 |= V_323 << 9 ;
if ( V_9 -> V_225 . V_226 & V_328 )
V_283 |= V_329 ;
if ( V_9 -> V_225 . V_226 & V_330 )
V_283 |= V_331 ;
switch ( F_187 ( V_9 ) ) {
case V_121 :
V_283 |= V_122 ;
break;
case V_123 :
V_283 |= V_124 ;
break;
case V_125 :
V_283 |= V_126 ;
break;
default:
F_25 ( L_70 ) ;
V_283 |= V_122 ;
break;
}
F_23 ( V_70 , V_283 ) ;
}
F_78 ( V_4 , V_66 ) ;
}
static void F_188 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
int V_97 = V_148 -> V_97 ;
T_1 V_283 ;
bool V_332 ;
if ( V_148 -> V_333 )
return;
V_148 -> V_333 = true ;
F_189 ( V_2 ) ;
if ( F_5 ( V_9 , V_12 ) ) {
V_283 = F_3 ( V_13 ) ;
if ( ( V_283 & V_117 ) == 0 )
F_23 ( V_13 , V_283 | V_117 ) ;
}
V_332 = F_172 ( V_9 ) ;
if ( V_332 )
F_162 ( V_9 ) ;
else
F_166 ( V_9 ) ;
if ( V_4 -> V_334 &&
( F_5 ( V_9 , V_12 ) || V_21 ) ) {
F_23 ( F_190 ( V_66 ) , V_335 | V_336 ) ;
F_23 ( F_191 ( V_66 ) , V_4 -> V_337 ) ;
F_23 ( F_192 ( V_66 ) , V_4 -> V_334 ) ;
}
F_193 ( V_9 ) ;
F_87 ( V_4 , V_66 , V_332 ) ;
F_93 ( V_4 , V_97 , V_66 ) ;
if ( V_332 )
F_174 ( V_9 ) ;
F_119 ( & V_2 -> V_206 ) ;
F_129 ( V_2 ) ;
F_120 ( & V_2 -> V_206 ) ;
F_194 ( V_9 , true ) ;
}
static void F_195 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
int V_97 = V_148 -> V_97 ;
T_1 V_70 , V_283 ;
if ( ! V_148 -> V_333 )
return;
F_171 ( V_9 ) ;
F_196 ( V_2 , V_66 ) ;
F_194 ( V_9 , false ) ;
F_95 ( V_4 , V_97 , V_66 ) ;
if ( V_4 -> V_209 == V_97 )
F_128 ( V_2 ) ;
F_89 ( V_4 , V_66 ) ;
F_23 ( F_190 ( V_66 ) , 0 ) ;
F_23 ( F_192 ( V_66 ) , 0 ) ;
F_166 ( V_9 ) ;
F_98 ( V_4 , V_66 ) ;
F_84 ( V_4 , V_66 ) ;
if ( F_56 ( V_2 ) ) {
V_70 = F_57 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
V_283 &= ~ ( V_326 | V_112 ) ;
V_283 |= V_338 ;
F_23 ( V_70 , V_283 ) ;
V_283 = F_3 ( V_318 ) ;
switch ( V_66 ) {
case 0 :
V_283 &= ~ ( V_319 | V_320 ) ;
break;
case 1 :
V_283 &= ~ ( V_321 | V_322 ) ;
break;
case 2 :
V_283 &= ~ ( V_339 | V_340 ) ;
break;
default:
F_136 () ;
}
F_23 ( V_318 , V_283 ) ;
}
F_77 ( V_4 , V_66 ) ;
V_70 = F_42 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_283 & ~ V_312 ) ;
V_70 = F_40 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_283 & ~ V_84 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
V_70 = F_42 ( V_66 ) ;
V_283 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_283 & ~ V_85 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
V_148 -> V_333 = false ;
F_189 ( V_2 ) ;
F_119 ( & V_2 -> V_206 ) ;
F_129 ( V_2 ) ;
F_167 ( V_2 ) ;
F_120 ( & V_2 -> V_206 ) ;
}
static void F_197 ( struct V_8 * V_9 , int V_225 )
{
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
int V_97 = V_148 -> V_97 ;
switch ( V_225 ) {
case V_341 :
case V_342 :
case V_343 :
F_25 ( L_71 , V_66 , V_97 ) ;
F_188 ( V_9 ) ;
break;
case V_344 :
F_25 ( L_72 , V_66 , V_97 ) ;
F_195 ( V_9 ) ;
break;
}
}
static void F_198 ( struct V_148 * V_148 , bool V_345 )
{
if ( ! V_345 && V_148 -> V_346 ) {
struct V_1 * V_2 = V_148 -> V_52 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_119 ( & V_2 -> V_206 ) ;
V_4 -> V_245 . V_246 = false ;
( void ) F_199 ( V_148 -> V_346 ) ;
V_4 -> V_245 . V_246 = true ;
F_120 ( & V_2 -> V_206 ) ;
}
}
static void F_200 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
int V_97 = V_148 -> V_97 ;
if ( V_148 -> V_333 )
return;
V_148 -> V_333 = true ;
F_189 ( V_2 ) ;
F_68 ( V_4 , V_66 ) ;
F_87 ( V_4 , V_66 , false ) ;
F_93 ( V_4 , V_97 , V_66 ) ;
F_193 ( V_9 ) ;
F_129 ( V_2 ) ;
F_198 ( V_148 , true ) ;
F_194 ( V_9 , true ) ;
}
static void F_201 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
int V_97 = V_148 -> V_97 ;
if ( ! V_148 -> V_333 )
return;
F_171 ( V_9 ) ;
F_196 ( V_2 , V_66 ) ;
F_198 ( V_148 , false ) ;
F_194 ( V_9 , false ) ;
if ( V_4 -> V_209 == V_97 )
F_128 ( V_2 ) ;
F_95 ( V_4 , V_97 , V_66 ) ;
F_89 ( V_4 , V_66 ) ;
F_74 ( V_4 , V_66 ) ;
V_148 -> V_333 = false ;
F_129 ( V_2 ) ;
F_189 ( V_2 ) ;
F_167 ( V_2 ) ;
}
static void F_202 ( struct V_8 * V_9 , int V_225 )
{
switch ( V_225 ) {
case V_341 :
case V_342 :
case V_343 :
F_200 ( V_9 ) ;
break;
case V_344 :
F_201 ( V_9 ) ;
break;
}
}
static void F_203 ( struct V_8 * V_9 , int V_225 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_266 * V_267 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
bool V_76 ;
if ( V_148 -> V_347 == V_225 )
return;
V_148 -> V_347 = V_225 ;
V_4 -> V_200 . V_348 ( V_9 , V_225 ) ;
if ( ! V_2 -> V_272 -> V_273 )
return;
V_267 = V_2 -> V_272 -> V_273 -> V_274 ;
if ( ! V_267 -> V_275 )
return;
V_76 = V_9 -> V_76 && V_225 != V_344 ;
switch ( V_66 ) {
case 0 :
V_267 -> V_275 -> V_349 = V_76 ? V_9 -> V_225 . V_230 : 0 ;
V_267 -> V_275 -> V_350 = V_76 ? V_9 -> V_225 . V_231 : 0 ;
break;
case 1 :
V_267 -> V_275 -> V_351 = V_76 ? V_9 -> V_225 . V_230 : 0 ;
V_267 -> V_275 -> V_352 = V_76 ? V_9 -> V_225 . V_231 : 0 ;
break;
default:
F_83 ( L_73 , F_46 ( V_66 ) ) ;
break;
}
}
static void F_204 ( struct V_8 * V_9 )
{
struct V_353 * V_354 = V_9 -> V_355 ;
struct V_1 * V_2 = V_9 -> V_2 ;
V_354 -> V_348 ( V_9 , V_344 ) ;
if ( V_9 -> V_143 ) {
F_119 ( & V_2 -> V_206 ) ;
F_139 ( F_101 ( V_9 -> V_143 ) -> V_147 ) ;
F_120 ( & V_2 -> V_206 ) ;
}
}
static void F_205 ( struct V_8 * V_9 )
{
F_201 ( V_9 ) ;
}
static void F_206 ( struct V_8 * V_9 )
{
F_200 ( V_9 ) ;
}
static void F_207 ( struct V_8 * V_9 )
{
F_195 ( V_9 ) ;
}
static void F_208 ( struct V_8 * V_9 )
{
F_188 ( V_9 ) ;
}
void F_209 ( struct V_356 * V_51 )
{
struct V_357 * V_358 = V_51 -> V_355 ;
V_358 -> V_348 ( V_51 , V_344 ) ;
}
void F_210 ( struct V_356 * V_51 )
{
struct V_357 * V_358 = V_51 -> V_355 ;
V_358 -> V_348 ( V_51 , V_341 ) ;
}
void F_211 ( struct V_356 * V_51 )
{
struct V_50 * V_50 = F_212 ( V_51 ) ;
F_213 ( V_51 ) ;
F_121 ( V_50 ) ;
}
static bool F_214 ( struct V_8 * V_9 ,
struct V_359 * V_225 ,
struct V_359 * V_360 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
if ( F_8 ( V_2 ) ) {
if ( V_225 -> clock * 3 > V_361 * 4 )
return false ;
}
if ( V_360 -> V_362 == 0 )
F_215 ( V_360 , 0 ) ;
return true ;
}
static int F_216 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_217 ( struct V_1 * V_2 )
{
return 333000 ;
}
static int F_218 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_219 ( struct V_1 * V_2 )
{
T_4 V_363 = 0 ;
F_220 ( V_2 -> V_364 , V_365 , & V_363 ) ;
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
static int F_221 ( struct V_1 * V_2 )
{
return 266000 ;
}
static int F_222 ( struct V_1 * V_2 )
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
static int F_223 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_224 ( T_1 * V_376 , T_1 * V_377 )
{
while ( * V_376 > 0xffffff || * V_377 > 0xffffff ) {
* V_376 >>= 1 ;
* V_377 >>= 1 ;
}
}
static void
F_225 ( int V_254 , int V_378 , int V_379 ,
int V_380 , struct V_381 * V_382 )
{
V_382 -> V_383 = 64 ;
V_382 -> V_384 = V_254 * V_379 ;
V_382 -> V_385 = V_380 * V_378 * 8 ;
F_224 ( & V_382 -> V_384 , & V_382 -> V_385 ) ;
V_382 -> V_386 = V_379 ;
V_382 -> V_387 = V_380 ;
F_224 ( & V_382 -> V_386 , & V_382 -> V_387 ) ;
}
static unsigned long F_226 ( unsigned long V_388 ,
const struct V_389 * V_390 ,
int V_391 ,
int V_392 ,
unsigned long V_393 )
{
long V_394 , V_395 ;
V_394 = ( ( V_388 / 1000 ) * V_392 * V_393 ) /
1000 ;
V_394 = F_227 ( V_394 , V_390 -> V_396 ) ;
F_25 ( L_74 , V_394 ) ;
V_395 = V_391 - ( V_394 + V_390 -> V_397 ) ;
F_25 ( L_75 , V_395 ) ;
if ( V_395 > ( long ) V_390 -> V_398 )
V_395 = V_390 -> V_398 ;
if ( V_395 <= 0 )
V_395 = V_390 -> V_399 ;
return V_395 ;
}
static const struct V_400 * F_228 ( int V_401 ,
int V_402 ,
int V_403 ,
int V_404 )
{
const struct V_400 * V_405 ;
int V_99 ;
if ( V_403 == 0 || V_404 == 0 )
return NULL ;
for ( V_99 = 0 ; V_99 < F_229 ( V_406 ) ; V_99 ++ ) {
V_405 = & V_406 [ V_99 ] ;
if ( V_401 == V_405 -> V_401 &&
V_402 == V_405 -> V_402 &&
V_403 == V_405 -> V_407 && V_404 == V_405 -> V_408 )
return V_405 ;
}
F_25 ( L_76 ) ;
return NULL ;
}
static void F_230 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_409 , F_3 ( V_409 ) & ~ V_410 ) ;
}
static int F_231 ( struct V_1 * V_2 , int V_97 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_411 = F_3 ( V_412 ) ;
int V_223 ;
V_223 = V_411 & 0x7f ;
if ( V_97 )
V_223 = ( ( V_411 >> V_413 ) & 0x7f ) - V_223 ;
F_25 ( L_77 , V_411 ,
V_97 ? L_78 : L_79 , V_223 ) ;
return V_223 ;
}
static int F_232 ( struct V_1 * V_2 , int V_97 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_411 = F_3 ( V_412 ) ;
int V_223 ;
V_223 = V_411 & 0x1ff ;
if ( V_97 )
V_223 = ( ( V_411 >> V_414 ) & 0x1ff ) - V_223 ;
V_223 >>= 1 ;
F_25 ( L_77 , V_411 ,
V_97 ? L_78 : L_79 , V_223 ) ;
return V_223 ;
}
static int F_233 ( struct V_1 * V_2 , int V_97 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_411 = F_3 ( V_412 ) ;
int V_223 ;
V_223 = V_411 & 0x7f ;
V_223 >>= 2 ;
F_25 ( L_77 , V_411 ,
V_97 ? L_78 : L_79 ,
V_223 ) ;
return V_223 ;
}
static int F_234 ( struct V_1 * V_2 , int V_97 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_411 = F_3 ( V_412 ) ;
int V_223 ;
V_223 = V_411 & 0x7f ;
V_223 >>= 1 ;
F_25 ( L_77 , V_411 ,
V_97 ? L_78 : L_79 , V_223 ) ;
return V_223 ;
}
static struct V_8 * F_235 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_76 = NULL ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_9 -> V_76 && V_9 -> V_143 ) {
if ( V_76 )
return NULL ;
V_76 = V_9 ;
}
}
return V_76 ;
}
static void F_236 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
const struct V_400 * V_405 ;
T_1 V_70 ;
unsigned long V_390 ;
V_405 = F_228 ( F_237 ( V_2 ) , V_4 -> V_402 ,
V_4 -> V_407 , V_4 -> V_408 ) ;
if ( ! V_405 ) {
F_25 ( L_76 ) ;
F_230 ( V_2 ) ;
return;
}
V_9 = F_235 ( V_2 ) ;
if ( V_9 ) {
int clock = V_9 -> V_225 . clock ;
int V_392 = V_9 -> V_143 -> V_254 / 8 ;
V_390 = F_226 ( clock , & V_415 ,
V_415 . V_391 ,
V_392 , V_405 -> V_416 ) ;
V_70 = F_3 ( V_417 ) ;
V_70 &= ~ V_418 ;
V_70 |= V_390 << V_419 ;
F_23 ( V_417 , V_70 ) ;
F_25 ( L_80 , V_70 ) ;
V_390 = F_226 ( clock , & V_420 ,
V_415 . V_391 ,
V_392 , V_405 -> V_421 ) ;
V_70 = F_3 ( V_409 ) ;
V_70 &= ~ V_422 ;
V_70 |= ( V_390 & 0x3f ) << V_423 ;
F_23 ( V_409 , V_70 ) ;
V_390 = F_226 ( clock , & V_424 ,
V_424 . V_391 ,
V_392 , V_405 -> V_425 ) ;
V_70 = F_3 ( V_409 ) ;
V_70 &= ~ V_426 ;
V_70 |= V_390 & V_426 ;
F_23 ( V_409 , V_70 ) ;
V_390 = F_226 ( clock , & V_427 ,
V_424 . V_391 ,
V_392 , V_405 -> V_428 ) ;
V_70 = F_3 ( V_409 ) ;
V_70 &= ~ V_429 ;
V_70 |= ( V_390 & 0x3f ) << V_430 ;
F_23 ( V_409 , V_70 ) ;
F_25 ( L_81 , V_70 ) ;
F_23 ( V_409 ,
F_3 ( V_409 ) | V_410 ) ;
F_25 ( L_82 ) ;
} else {
F_230 ( V_2 ) ;
F_25 ( L_83 ) ;
}
}
static bool F_238 ( struct V_1 * V_2 ,
int V_97 ,
const struct V_389 * V_200 ,
int V_431 ,
const struct V_389 * V_432 ,
int V_433 ,
int * V_434 ,
int * V_435 )
{
struct V_8 * V_9 ;
int V_436 , V_230 , clock , V_392 ;
int V_437 , V_438 ;
int V_439 , V_440 ;
V_9 = F_239 ( V_2 , V_97 ) ;
if ( V_9 -> V_143 == NULL || ! V_9 -> V_76 ) {
* V_435 = V_432 -> V_397 ;
* V_434 = V_200 -> V_397 ;
return false ;
}
V_436 = V_9 -> V_225 . V_436 ;
V_230 = V_9 -> V_225 . V_230 ;
clock = V_9 -> V_225 . clock ;
V_392 = V_9 -> V_143 -> V_254 / 8 ;
V_439 = ( ( clock * V_392 / 1000 ) * V_431 ) / 1000 ;
V_440 = V_200 -> V_391 * V_200 -> V_396 - V_230 * 8 ;
if ( V_440 > 0 )
V_439 += V_440 ;
V_439 = F_227 ( V_439 , V_200 -> V_396 ) ;
* V_434 = V_439 + V_200 -> V_397 ;
if ( * V_434 > ( int ) V_200 -> V_398 )
* V_434 = V_200 -> V_398 ;
V_437 = ( ( V_436 * 1000 ) / clock ) ;
V_438 = ( V_433 / V_437 + 1000 ) / 1000 ;
V_439 = V_438 * 64 * V_392 ;
V_440 = V_432 -> V_391 * V_432 -> V_396 - V_230 * 8 ;
if ( V_440 > 0 )
V_439 += V_440 ;
V_439 = F_227 ( V_439 , V_432 -> V_396 ) ;
* V_435 = V_439 + V_432 -> V_397 ;
if ( * V_435 > ( int ) V_432 -> V_398 )
* V_435 = ( int ) V_432 -> V_398 ;
return true ;
}
static bool F_240 ( struct V_1 * V_2 ,
int V_441 , int V_435 ,
const struct V_389 * V_200 ,
const struct V_389 * V_432 )
{
F_25 ( L_84 ,
V_441 , V_435 ) ;
if ( V_441 > V_200 -> V_398 ) {
F_25 ( L_85 ,
V_441 , V_200 -> V_398 ) ;
return false ;
}
if ( V_435 > V_432 -> V_398 ) {
F_25 ( L_86 ,
V_435 , V_432 -> V_398 ) ;
return false ;
}
if ( ! ( V_441 || V_435 ) ) {
F_25 ( L_87 ) ;
return false ;
}
return true ;
}
static bool F_241 ( struct V_1 * V_2 ,
int V_97 ,
int V_393 ,
const struct V_389 * V_200 ,
const struct V_389 * V_432 ,
int * V_441 , int * V_435 )
{
struct V_8 * V_9 ;
int V_230 , V_436 , V_392 , clock ;
unsigned long V_437 ;
int V_438 , V_442 ;
int V_443 , V_444 ;
int V_439 ;
if ( ! V_393 ) {
* V_441 = * V_435 = 0 ;
return false ;
}
V_9 = F_239 ( V_2 , V_97 ) ;
V_230 = V_9 -> V_225 . V_230 ;
V_436 = V_9 -> V_225 . V_436 ;
clock = V_9 -> V_225 . clock ;
V_392 = V_9 -> V_143 -> V_254 / 8 ;
V_437 = ( V_436 * 1000 ) / clock ;
V_438 = ( V_393 / V_437 + 1000 ) / 1000 ;
V_442 = V_230 * V_392 ;
V_443 = ( ( clock * V_392 / 1000 ) * V_393 ) / 1000 ;
V_444 = V_438 * V_442 ;
V_439 = F_227 ( V_53 ( V_443 , V_444 ) , V_200 -> V_396 ) ;
* V_441 = V_439 + V_200 -> V_397 ;
V_439 = V_438 * V_392 * 64 ;
V_439 = F_227 ( V_439 , V_432 -> V_396 ) ;
* V_435 = V_439 + V_432 -> V_397 ;
return F_240 ( V_2 ,
* V_441 , * V_435 ,
V_200 , V_432 ) ;
}
static void F_242 ( struct V_1 * V_2 )
{
static const int V_445 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_446 , V_447 , V_448 , V_449 ;
int V_450 , V_421 ;
unsigned int V_76 = 0 ;
if ( F_238 ( V_2 , 0 ,
& V_451 , V_393 ,
& V_452 , V_393 ,
& V_446 , & V_448 ) )
V_76 |= 1 ;
if ( F_238 ( V_2 , 1 ,
& V_451 , V_393 ,
& V_452 , V_393 ,
& V_447 , & V_449 ) )
V_76 |= 2 ;
V_450 = V_421 = 0 ;
if ( F_243 ( V_76 ) &&
F_241 ( V_2 , F_244 ( V_76 ) - 1 ,
V_445 ,
& V_451 ,
& V_452 ,
& V_450 , & V_421 ) )
F_23 ( V_453 , V_454 ) ;
else
F_23 ( V_453 ,
F_3 ( V_453 ) & ~ V_454 ) ;
F_25 ( L_88 ,
V_446 , V_448 ,
V_447 , V_449 ,
V_450 , V_421 ) ;
F_23 ( V_417 ,
( V_450 << V_419 ) |
( V_449 << V_455 ) |
( V_447 << V_456 ) |
V_446 ) ;
F_23 ( V_457 ,
( F_3 ( V_457 ) & V_458 ) |
( V_448 << V_459 ) ) ;
F_23 ( V_409 ,
( F_3 ( V_409 ) & ~ V_460 ) |
( V_421 << V_423 ) ) ;
}
static void F_245 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
int V_461 = 1 ;
int V_421 = 16 ;
V_9 = F_235 ( V_2 ) ;
if ( V_9 ) {
static const int V_445 = 12000 ;
int clock = V_9 -> V_225 . clock ;
int V_436 = V_9 -> V_225 . V_436 ;
int V_230 = V_9 -> V_225 . V_230 ;
int V_392 = V_9 -> V_143 -> V_254 / 8 ;
unsigned long V_437 ;
int V_439 ;
V_437 = ( ( V_436 * 1000 ) / clock ) ;
V_439 = ( ( ( V_445 / V_437 ) + 1000 ) / 1000 ) *
V_392 * V_230 ;
V_439 = F_227 ( V_439 , V_462 ) ;
V_461 = V_463 - V_439 ;
if ( V_461 < 0 )
V_461 = 1 ;
V_461 &= 0x1ff ;
F_25 ( L_89 ,
V_439 , V_461 ) ;
V_439 = ( ( ( V_445 / V_437 ) + 1000 ) / 1000 ) *
V_392 * 64 ;
V_439 = F_227 ( V_439 ,
V_464 . V_396 ) ;
V_421 = V_464 . V_391 -
( V_439 + V_464 . V_397 ) ;
if ( V_421 > V_464 . V_398 )
V_421 = V_464 . V_398 ;
F_25 ( L_90
L_91 , V_461 , V_421 ) ;
if ( F_135 ( V_2 ) )
F_23 ( V_453 , V_454 ) ;
} else {
if ( F_135 ( V_2 ) )
F_23 ( V_453 , F_3 ( V_453 )
& ~ V_454 ) ;
}
F_25 ( L_92 ,
V_461 ) ;
F_23 ( V_417 , ( V_461 << V_419 ) |
( 8 << 16 ) | ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_23 ( V_457 , ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_23 ( V_409 , ( V_421 << V_423 ) ) ;
}
static void F_246 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_389 * V_465 ;
T_5 V_466 ;
T_5 V_467 ;
int V_468 , V_461 = 1 ;
int V_391 ;
int V_446 , V_447 ;
struct V_8 * V_9 , * V_76 = NULL ;
if ( F_103 ( V_2 ) )
V_465 = & V_469 ;
else if ( ! F_11 ( V_2 ) )
V_465 = & V_470 ;
else
V_465 = & V_471 ;
V_391 = V_4 -> V_200 . V_472 ( V_2 , 0 ) ;
V_9 = F_239 ( V_2 , 0 ) ;
if ( V_9 -> V_76 && V_9 -> V_143 ) {
V_446 = F_226 ( V_9 -> V_225 . clock ,
V_465 , V_391 ,
V_9 -> V_143 -> V_254 / 8 ,
V_393 ) ;
V_76 = V_9 ;
} else
V_446 = V_391 - V_465 -> V_397 ;
V_391 = V_4 -> V_200 . V_472 ( V_2 , 1 ) ;
V_9 = F_239 ( V_2 , 1 ) ;
if ( V_9 -> V_76 && V_9 -> V_143 ) {
V_447 = F_226 ( V_9 -> V_225 . clock ,
V_465 , V_391 ,
V_9 -> V_143 -> V_254 / 8 ,
V_393 ) ;
if ( V_76 == NULL )
V_76 = V_9 ;
else
V_76 = NULL ;
} else
V_447 = V_391 - V_465 -> V_397 ;
F_25 ( L_93 , V_446 , V_447 ) ;
V_468 = 2 ;
if ( F_247 ( V_2 ) || F_103 ( V_2 ) )
F_23 ( V_453 , V_473 | 0 ) ;
else if ( F_131 ( V_2 ) )
F_23 ( V_474 , F_3 ( V_474 ) & ~ V_475 ) ;
if ( F_248 ( V_2 ) && V_76 ) {
static const int V_445 = 6000 ;
int clock = V_76 -> V_225 . clock ;
int V_436 = V_76 -> V_225 . V_436 ;
int V_230 = V_76 -> V_225 . V_230 ;
int V_392 = V_76 -> V_143 -> V_254 / 8 ;
unsigned long V_437 ;
int V_439 ;
V_437 = ( V_436 * 1000 ) / clock ;
V_439 = ( ( ( V_445 / V_437 ) + 1000 ) / 1000 ) *
V_392 * V_230 ;
V_439 = F_227 ( V_439 , V_465 -> V_396 ) ;
F_25 ( L_94 , V_439 ) ;
V_461 = V_465 -> V_391 - V_439 ;
if ( V_461 < 0 )
V_461 = 1 ;
if ( F_247 ( V_2 ) || F_103 ( V_2 ) )
F_23 ( V_453 ,
V_476 | ( V_461 & 0xff ) ) ;
else if ( F_131 ( V_2 ) )
F_23 ( V_453 , V_461 & 0x3f ) ;
}
F_25 ( L_95 ,
V_446 , V_447 , V_468 , V_461 ) ;
V_466 = ( ( V_447 & 0x3f ) << 16 ) | ( V_446 & 0x3f ) ;
V_467 = ( V_468 & 0x1f ) ;
V_466 = V_466 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_467 = V_467 | ( 1 << 8 ) ;
F_23 ( V_477 , V_466 ) ;
F_23 ( V_478 , V_467 ) ;
if ( F_248 ( V_2 ) ) {
if ( V_76 ) {
if ( F_247 ( V_2 ) || F_103 ( V_2 ) )
F_23 ( V_453 ,
V_473 | V_454 ) ;
else if ( F_131 ( V_2 ) )
F_23 ( V_474 , F_3 ( V_474 ) | V_475 ) ;
F_25 ( L_96 ) ;
} else
F_25 ( L_97 ) ;
}
}
static void F_249 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
T_5 V_466 ;
int V_446 ;
V_9 = F_235 ( V_2 ) ;
if ( V_9 == NULL )
return;
V_446 = F_226 ( V_9 -> V_225 . clock , & V_479 ,
V_4 -> V_200 . V_472 ( V_2 , 0 ) ,
V_9 -> V_143 -> V_254 / 8 ,
V_393 ) ;
V_466 = F_3 ( V_477 ) & ~ 0xfff ;
V_466 |= ( 3 << 8 ) | V_446 ;
F_25 ( L_98 , V_446 ) ;
F_23 ( V_477 , V_466 ) ;
}
static bool F_250 ( struct V_1 * V_2 , int V_480 ,
int V_481 , int V_441 , int V_435 ,
const struct V_389 * V_200 ,
const struct V_389 * V_432 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_25 ( L_99
L_100 , V_480 , V_441 , V_481 , V_435 ) ;
if ( V_481 > V_482 ) {
F_25 ( L_101 ,
V_481 , V_482 , V_480 ) ;
F_23 ( V_483 ,
F_3 ( V_483 ) | V_484 ) ;
return false ;
}
if ( V_441 > V_200 -> V_398 ) {
F_25 ( L_102 ,
V_441 , V_485 , V_480 ) ;
return false ;
}
if ( V_435 > V_432 -> V_398 ) {
F_25 ( L_103 ,
V_435 , V_486 , V_480 ) ;
return false ;
}
if ( ! ( V_481 || V_441 || V_435 ) ) {
F_25 ( L_104 , V_480 , V_480 ) ;
return false ;
}
return true ;
}
static bool F_251 ( struct V_1 * V_2 , int V_480 , int V_97 ,
int V_393 ,
const struct V_389 * V_200 ,
const struct V_389 * V_432 ,
int * V_481 , int * V_441 , int * V_435 )
{
struct V_8 * V_9 ;
unsigned long V_437 ;
int V_230 , V_436 , V_392 , clock ;
int V_438 , V_442 ;
int V_443 , V_444 ;
int V_439 ;
if ( ! V_393 ) {
* V_481 = * V_441 = * V_435 = 0 ;
return false ;
}
V_9 = F_239 ( V_2 , V_97 ) ;
V_230 = V_9 -> V_225 . V_230 ;
V_436 = V_9 -> V_225 . V_436 ;
clock = V_9 -> V_225 . clock ;
V_392 = V_9 -> V_143 -> V_254 / 8 ;
V_437 = ( V_436 * 1000 ) / clock ;
V_438 = ( V_393 / V_437 + 1000 ) / 1000 ;
V_442 = V_230 * V_392 ;
V_443 = ( ( clock * V_392 / 1000 ) * V_393 ) / 1000 ;
V_444 = V_438 * V_442 ;
V_439 = F_227 ( V_53 ( V_443 , V_444 ) , V_200 -> V_396 ) ;
* V_441 = V_439 + V_200 -> V_397 ;
* V_481 = F_227 ( * V_441 * 64 , V_442 ) + 2 ;
V_439 = V_438 * V_392 * 64 ;
V_439 = F_227 ( V_439 , V_432 -> V_396 ) ;
* V_435 = V_439 + V_432 -> V_397 ;
return F_250 ( V_2 , V_480 ,
* V_481 , * V_441 , * V_435 ,
V_200 , V_432 ) ;
}
static void F_252 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_481 , V_434 , V_435 ;
unsigned int V_76 ;
V_76 = 0 ;
if ( F_238 ( V_2 , 0 ,
& V_487 ,
V_488 ,
& V_489 ,
V_490 ,
& V_434 , & V_435 ) ) {
F_23 ( V_491 ,
( V_434 << V_492 ) | V_435 ) ;
F_25 ( L_105
L_106 L_107 ,
V_434 , V_435 ) ;
V_76 |= 1 ;
}
if ( F_238 ( V_2 , 1 ,
& V_487 ,
V_488 ,
& V_489 ,
V_490 ,
& V_434 , & V_435 ) ) {
F_23 ( V_493 ,
( V_434 << V_492 ) | V_435 ) ;
F_25 ( L_108
L_109 ,
V_434 , V_435 ) ;
V_76 |= 2 ;
}
F_23 ( V_494 , 0 ) ;
F_23 ( V_495 , 0 ) ;
F_23 ( V_496 , 0 ) ;
if ( ! F_243 ( V_76 ) )
return;
V_76 = F_244 ( V_76 ) - 1 ;
if ( ! F_251 ( V_2 , 1 , V_76 ,
F_253 () * 500 ,
& V_497 ,
& V_498 ,
& V_481 , & V_434 , & V_435 ) )
return;
F_23 ( V_496 ,
V_499 |
( F_253 () << V_500 ) |
( V_481 << V_501 ) |
( V_434 << V_502 ) |
V_435 ) ;
if ( ! F_251 ( V_2 , 2 , V_76 ,
F_254 () * 500 ,
& V_497 ,
& V_498 ,
& V_481 , & V_434 , & V_435 ) )
return;
F_23 ( V_495 ,
V_503 |
( F_254 () << V_500 ) |
( V_481 << V_501 ) |
( V_434 << V_502 ) |
V_435 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_405 = F_256 () * 100 ;
int V_481 , V_434 , V_435 ;
unsigned int V_76 ;
V_76 = 0 ;
if ( F_238 ( V_2 , 0 ,
& V_504 , V_405 ,
& V_505 , V_405 ,
& V_434 , & V_435 ) ) {
F_23 ( V_491 ,
( V_434 << V_492 ) | V_435 ) ;
F_25 ( L_105
L_106 L_107 ,
V_434 , V_435 ) ;
V_76 |= 1 ;
}
if ( F_238 ( V_2 , 1 ,
& V_504 , V_405 ,
& V_505 , V_405 ,
& V_434 , & V_435 ) ) {
F_23 ( V_493 ,
( V_434 << V_492 ) | V_435 ) ;
F_25 ( L_108
L_109 ,
V_434 , V_435 ) ;
V_76 |= 2 ;
}
F_23 ( V_494 , 0 ) ;
F_23 ( V_495 , 0 ) ;
F_23 ( V_496 , 0 ) ;
if ( ! F_243 ( V_76 ) )
return;
V_76 = F_244 ( V_76 ) - 1 ;
if ( ! F_251 ( V_2 , 1 , V_76 ,
F_257 () * 500 ,
& V_506 ,
& V_507 ,
& V_481 , & V_434 , & V_435 ) )
return;
F_23 ( V_496 ,
V_499 |
( F_257 () << V_500 ) |
( V_481 << V_501 ) |
( V_434 << V_502 ) |
V_435 ) ;
if ( ! F_251 ( V_2 , 2 , V_76 ,
F_258 () * 500 ,
& V_506 ,
& V_507 ,
& V_481 , & V_434 , & V_435 ) )
return;
F_23 ( V_495 ,
V_503 |
( F_258 () << V_500 ) |
( V_481 << V_501 ) |
( V_434 << V_502 ) |
V_435 ) ;
if ( ! F_251 ( V_2 , 3 , V_76 ,
F_259 () * 500 ,
& V_506 ,
& V_507 ,
& V_481 , & V_434 , & V_435 ) )
return;
F_23 ( V_494 ,
V_508 |
( F_259 () << V_500 ) |
( V_481 << V_501 ) |
( V_434 << V_502 ) |
V_435 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_200 . V_509 )
V_4 -> V_200 . V_509 ( V_2 ) ;
}
static inline bool F_260 ( struct V_3 * V_4 )
{
return V_4 -> V_510 && V_511
&& ! ( V_4 -> V_131 & V_512 ) ;
}
static bool F_261 ( struct V_8 * V_9 ,
unsigned int * V_513 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_356 * V_51 ;
struct V_514 * V_515 ;
unsigned int V_516 = V_517 , V_323 ;
F_14 (encoder, &dev->mode_config.encoder_list, head) {
struct V_50 * V_50 = F_212 ( V_51 ) ;
if ( V_51 -> V_9 != V_9 )
continue;
if ( V_50 -> type == V_12 ) {
unsigned int V_518 ;
if ( ( F_3 ( V_13 ) & V_519 ) ==
V_520 )
V_518 = 8 ;
else
V_518 = 6 ;
if ( V_518 < V_516 ) {
F_262 ( L_110 , V_516 , V_518 ) ;
V_516 = V_518 ;
}
continue;
}
if ( V_50 -> type == V_316 ) {
unsigned int V_521 = V_4 -> V_522 . V_523 / 3 ;
if ( V_521 < V_516 ) {
F_262 ( L_111 , V_516 , V_521 ) ;
V_516 = V_521 ;
}
continue;
}
F_14 (connector, &dev->mode_config.connector_list,
head) {
if ( V_515 -> V_51 != V_51 )
continue;
if ( V_515 -> V_524 . V_323 &&
V_515 -> V_524 . V_323 < V_516 ) {
F_262 ( L_112 , V_516 , V_515 -> V_524 . V_323 ) ;
V_516 = V_515 -> V_524 . V_323 ;
}
}
if ( V_50 -> type == V_27 ) {
if ( V_516 > 8 && V_516 < 12 ) {
F_262 ( L_113 ) ;
V_516 = 12 ;
} else {
F_262 ( L_114 ) ;
V_516 = 8 ;
}
}
}
switch ( V_9 -> V_143 -> V_256 ) {
case 8 :
V_323 = 8 ;
break;
case 15 :
case 16 :
V_323 = 6 ;
break;
case 24 :
V_323 = 8 ;
break;
case 30 :
V_323 = 10 ;
break;
case 48 :
V_323 = 12 ;
break;
default:
F_263 ( L_115 ) ;
V_323 = V_53 ( ( unsigned int ) 8 , V_516 ) ;
break;
}
V_516 = V_53 ( V_516 , V_323 ) ;
F_262 ( L_116 ,
V_323 , V_516 ) ;
* V_513 = V_516 * 3 ;
return V_516 != V_323 ;
}
static int F_264 ( struct V_8 * V_9 ,
struct V_359 * V_225 ,
struct V_359 * V_360 ,
int V_249 , int V_162 ,
struct V_142 * V_265 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
int V_97 = V_148 -> V_97 ;
int V_10 , V_525 = 0 ;
T_3 clock , V_526 ;
T_1 V_527 , V_528 = 0 , V_529 = 0 , V_252 , V_530 ;
bool V_531 , V_532 = false , V_533 = false , V_534 = false ;
bool V_535 = false , V_536 = false , V_537 = false , V_538 = false ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
const T_2 * V_11 ;
int V_241 ;
T_1 V_283 ;
T_1 V_539 = 0 ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_12 :
V_536 = true ;
break;
case V_30 :
case V_27 :
V_533 = true ;
if ( V_51 -> V_540 )
V_537 = true ;
break;
case V_541 :
V_534 = true ;
break;
case V_542 :
V_537 = true ;
break;
case V_28 :
V_535 = true ;
break;
case V_20 :
V_538 = true ;
break;
}
V_525 ++ ;
}
if ( V_536 && F_260 ( V_4 ) && V_525 < 2 ) {
V_10 = V_4 -> V_543 * 1000 ;
F_25 ( L_117 ,
V_10 / 1000 ) ;
} else if ( ! F_11 ( V_2 ) ) {
V_10 = 96000 ;
} else {
V_10 = 48000 ;
}
V_11 = F_7 ( V_9 , V_10 ) ;
V_531 = V_11 -> V_544 ( V_11 , V_9 , V_360 -> clock , V_10 , & clock ) ;
if ( ! V_531 ) {
F_83 ( L_118 ) ;
return - V_244 ;
}
F_194 ( V_9 , true ) ;
if ( V_536 && V_4 -> V_545 ) {
V_532 = V_11 -> V_544 ( V_11 , V_9 ,
V_4 -> V_546 ,
V_10 ,
& V_526 ) ;
if ( V_532 && ( clock . V_41 != V_526 . V_41 ) ) {
F_25 ( L_119
L_120 ) ;
V_532 = 0 ;
}
}
if ( V_533 && V_537 ) {
if ( V_360 -> clock >= 100000
&& V_360 -> clock < 140500 ) {
clock . V_42 = 2 ;
clock . V_43 = 10 ;
clock . V_45 = 3 ;
clock . V_47 = 16 ;
clock . V_40 = 8 ;
} else if ( V_360 -> clock >= 140500
&& V_360 -> clock <= 200000 ) {
clock . V_42 = 1 ;
clock . V_43 = 10 ;
clock . V_45 = 6 ;
clock . V_47 = 12 ;
clock . V_40 = 8 ;
}
}
if ( F_10 ( V_2 ) ) {
V_528 = ( 1 << clock . V_45 ) << 16 | clock . V_47 << 8 | clock . V_40 ;
if ( V_532 )
V_529 = ( 1 << V_526 . V_45 ) << 16 |
V_526 . V_47 << 8 | V_526 . V_40 ;
} else {
V_528 = clock . V_45 << 16 | clock . V_47 << 8 | clock . V_40 ;
if ( V_532 )
V_529 = V_526 . V_45 << 16 | V_526 . V_47 << 8 |
V_526 . V_40 ;
}
V_527 = V_547 ;
if ( ! F_11 ( V_2 ) ) {
if ( V_536 )
V_527 |= V_548 ;
else
V_527 |= V_549 ;
if ( V_533 ) {
int V_550 = F_265 ( V_360 ) ;
if ( V_550 > 1 ) {
if ( F_247 ( V_2 ) || F_103 ( V_2 ) || F_266 ( V_2 ) )
V_527 |= ( V_550 - 1 ) << V_551 ;
}
V_527 |= V_552 ;
}
if ( V_538 )
V_527 |= V_552 ;
if ( F_10 ( V_2 ) )
V_527 |= ( 1 << ( clock . V_42 - 1 ) ) << V_553 ;
else {
V_527 |= ( 1 << ( clock . V_42 - 1 ) ) << V_554 ;
if ( F_9 ( V_2 ) && V_532 )
V_527 |= ( 1 << ( V_526 . V_42 - 1 ) ) << V_555 ;
}
switch ( clock . V_43 ) {
case 5 :
V_527 |= V_556 ;
break;
case 7 :
V_527 |= V_557 ;
break;
case 10 :
V_527 |= V_558 ;
break;
case 14 :
V_527 |= V_559 ;
break;
}
if ( F_27 ( V_2 ) -> V_69 >= 4 )
V_527 |= ( 6 << V_560 ) ;
} else {
if ( V_536 ) {
V_527 |= ( 1 << ( clock . V_42 - 1 ) ) << V_554 ;
} else {
if ( clock . V_42 == 2 )
V_527 |= V_561 ;
else
V_527 |= ( clock . V_42 - 2 ) << V_554 ;
if ( clock . V_43 == 4 )
V_527 |= V_562 ;
}
}
if ( V_533 && V_537 )
V_527 |= V_563 ;
else if ( V_537 )
V_527 |= 3 ;
else if ( V_536 && F_260 ( V_4 ) && V_525 < 2 )
V_527 |= V_564 ;
else
V_527 |= V_565 ;
V_530 = F_3 ( F_28 ( V_66 ) ) ;
V_252 = V_566 ;
if ( V_66 == 0 )
V_252 &= ~ V_101 ;
else
V_252 |= V_567 ;
if ( V_66 == 0 && F_27 ( V_2 ) -> V_69 < 4 ) {
if ( V_225 -> clock >
V_4 -> V_200 . V_568 ( V_2 ) * 9 / 10 )
V_530 |= V_569 ;
else
V_530 &= ~ V_569 ;
}
V_527 |= V_80 ;
F_25 ( L_121 , V_66 == 0 ? 'A' : 'B' ) ;
F_267 ( V_225 ) ;
F_23 ( F_268 ( V_66 ) , V_528 ) ;
F_23 ( F_35 ( V_66 ) , V_527 & ~ V_80 ) ;
F_72 ( F_35 ( V_66 ) ) ;
F_73 ( 150 ) ;
if ( V_536 ) {
V_283 = F_3 ( V_24 ) ;
V_283 |= V_117 | V_570 ;
if ( V_66 == 1 ) {
V_283 |= V_94 ;
} else {
V_283 &= ~ V_94 ;
}
V_283 |= V_4 -> V_571 ;
if ( clock . V_43 == 7 )
V_283 |= V_572 | V_15 ;
else
V_283 &= ~ ( V_572 | V_15 ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
if ( V_4 -> V_573 )
V_283 |= V_574 ;
else
V_283 &= ~ V_574 ;
}
if ( V_360 -> V_226 & V_575 )
V_539 |= V_576 ;
if ( V_360 -> V_226 & V_577 )
V_539 |= V_578 ;
if ( ( V_283 & ( V_576 | V_578 ) )
!= V_539 ) {
char V_226 [ 2 ] = L_122 ;
F_269 ( L_123
L_124 ,
V_226 [ ! ( V_283 & V_576 ) ] ,
V_226 [ ! ( V_283 & V_578 ) ] ,
V_226 [ ! ( V_539 & V_576 ) ] ,
V_226 [ ! ( V_539 & V_578 ) ] ) ;
V_283 &= ~ ( V_576 | V_578 ) ;
V_283 |= V_539 ;
}
F_23 ( V_24 , V_283 ) ;
}
if ( V_538 ) {
F_270 ( V_9 , V_225 , V_360 ) ;
}
F_23 ( F_35 ( V_66 ) , V_527 ) ;
F_72 ( F_35 ( V_66 ) ) ;
F_73 ( 150 ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
V_283 = 0 ;
if ( V_533 ) {
V_283 = F_265 ( V_360 ) ;
if ( V_283 > 1 )
V_283 = ( V_283 - 1 ) << V_579 ;
else
V_283 = 0 ;
}
F_23 ( F_271 ( V_66 ) , V_283 ) ;
} else {
F_23 ( F_35 ( V_66 ) , V_527 ) ;
}
V_148 -> V_580 = false ;
if ( V_536 && V_532 && V_216 ) {
F_23 ( F_272 ( V_66 ) , V_529 ) ;
V_148 -> V_580 = true ;
if ( F_273 ( V_2 ) ) {
F_25 ( L_125 ) ;
V_530 |= V_581 ;
}
} else {
F_23 ( F_272 ( V_66 ) , V_528 ) ;
if ( F_273 ( V_2 ) ) {
F_25 ( L_126 ) ;
V_530 &= ~ V_581 ;
}
}
if ( V_360 -> V_226 & V_227 ) {
V_530 |= V_582 ;
V_360 -> V_583 -= 1 ;
V_360 -> V_584 -= 1 ;
V_360 -> V_585 -= 1 ;
V_360 -> V_586 -= 1 ;
V_360 -> V_587 -= 1 ;
V_360 -> V_588 -= 1 ;
} else
V_530 &= ~ V_582 ;
F_23 ( F_176 ( V_66 ) ,
( V_360 -> V_589 - 1 ) |
( ( V_360 -> V_362 - 1 ) << 16 ) ) ;
F_23 ( F_178 ( V_66 ) ,
( V_360 -> V_590 - 1 ) |
( ( V_360 -> V_591 - 1 ) << 16 ) ) ;
F_23 ( F_180 ( V_66 ) ,
( V_360 -> V_592 - 1 ) |
( ( V_360 -> V_593 - 1 ) << 16 ) ) ;
F_23 ( F_182 ( V_66 ) ,
( V_360 -> V_583 - 1 ) |
( ( V_360 -> V_584 - 1 ) << 16 ) ) ;
F_23 ( F_184 ( V_66 ) ,
( V_360 -> V_585 - 1 ) |
( ( V_360 -> V_586 - 1 ) << 16 ) ) ;
F_23 ( F_186 ( V_66 ) ,
( V_360 -> V_588 - 1 ) |
( ( V_360 -> V_587 - 1 ) << 16 ) ) ;
F_23 ( F_274 ( V_97 ) ,
( ( V_225 -> V_231 - 1 ) << 16 ) |
( V_225 -> V_230 - 1 ) ) ;
F_23 ( F_275 ( V_97 ) , 0 ) ;
F_23 ( F_276 ( V_66 ) ,
( ( V_225 -> V_230 - 1 ) << 16 ) | ( V_225 -> V_231 - 1 ) ) ;
F_23 ( F_28 ( V_66 ) , V_530 ) ;
F_72 ( F_28 ( V_66 ) ) ;
F_87 ( V_4 , V_66 , false ) ;
F_21 ( V_2 , V_66 ) ;
F_23 ( F_49 ( V_97 ) , V_252 ) ;
F_72 ( F_49 ( V_97 ) ) ;
F_93 ( V_4 , V_97 , V_66 ) ;
V_241 = F_146 ( V_9 , V_249 , V_162 , V_265 ) ;
F_189 ( V_2 ) ;
return V_241 ;
}
static void F_277 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_8 * V_9 ;
struct V_50 * V_51 ;
struct V_50 * V_594 = NULL ;
T_1 V_283 ;
bool V_595 = false ;
F_14 (crtc, &mode_config->crtc_list, head) {
if ( ! V_9 -> V_76 )
continue;
F_14 (encoder, &mode_config->encoder_list,
base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_12 :
V_595 = true ;
case V_316 :
V_594 = V_51 ;
break;
}
}
}
V_283 = F_3 ( V_103 ) ;
V_283 &= ~ V_105 ;
V_283 |= V_596 ;
V_283 &= ~ V_104 ;
V_283 |= V_597 ;
F_23 ( V_103 , V_283 ) ;
F_72 ( V_103 ) ;
F_73 ( 200 ) ;
if ( V_594 ) {
if ( F_260 ( V_4 ) ) {
V_283 |= V_598 ;
F_23 ( V_103 , V_283 ) ;
F_72 ( V_103 ) ;
F_73 ( 200 ) ;
}
V_283 &= ~ V_599 ;
if ( ! F_173 ( & V_594 -> V_52 ) ) {
if ( F_260 ( V_4 ) )
V_283 |= V_600 ;
else
V_283 |= V_601 ;
} else {
if ( F_260 ( V_4 ) ) {
F_83 ( L_127 ) ;
V_283 |= V_602 ;
}
}
F_23 ( V_103 , V_283 ) ;
F_72 ( V_103 ) ;
F_73 ( 200 ) ;
}
}
static int F_278 ( struct V_8 * V_9 ,
struct V_359 * V_225 ,
struct V_359 * V_360 ,
int V_249 , int V_162 ,
struct V_142 * V_265 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
int V_97 = V_148 -> V_97 ;
int V_10 , V_525 = 0 ;
T_3 clock , V_526 ;
T_1 V_527 , V_528 = 0 , V_529 = 0 , V_252 , V_530 ;
bool V_531 , V_532 = false , V_533 = false ;
bool V_535 = false , V_536 = false , V_537 = false , V_538 = false ;
struct V_50 * V_594 = NULL ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
const T_2 * V_11 ;
int V_241 ;
struct V_381 V_382 = { 0 } ;
T_1 V_283 ;
T_1 V_539 = 0 ;
int V_603 , V_550 , V_604 , V_605 , V_606 ;
unsigned int V_513 ;
bool V_607 ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_12 :
V_536 = true ;
break;
case V_30 :
case V_27 :
V_533 = true ;
if ( V_51 -> V_540 )
V_537 = true ;
break;
case V_542 :
V_537 = true ;
break;
case V_28 :
V_535 = true ;
break;
case V_20 :
V_538 = true ;
break;
case V_316 :
V_594 = V_51 ;
break;
}
V_525 ++ ;
}
if ( V_536 && F_260 ( V_4 ) && V_525 < 2 ) {
V_10 = V_4 -> V_543 * 1000 ;
F_25 ( L_117 ,
V_10 / 1000 ) ;
} else {
V_10 = 96000 ;
if ( ! V_594 ||
F_173 ( & V_594 -> V_52 ) )
V_10 = 120000 ;
}
V_11 = F_7 ( V_9 , V_10 ) ;
V_531 = V_11 -> V_544 ( V_11 , V_9 , V_360 -> clock , V_10 , & clock ) ;
if ( ! V_531 ) {
F_83 ( L_118 ) ;
return - V_244 ;
}
F_194 ( V_9 , true ) ;
if ( V_536 && V_4 -> V_545 ) {
V_532 = V_11 -> V_544 ( V_11 , V_9 ,
V_4 -> V_546 ,
V_10 ,
& V_526 ) ;
if ( V_532 && ( clock . V_41 != V_526 . V_41 ) ) {
F_25 ( L_119
L_120 ) ;
V_532 = 0 ;
}
}
if ( V_533 && V_537 ) {
if ( V_360 -> clock >= 100000
&& V_360 -> clock < 140500 ) {
clock . V_42 = 2 ;
clock . V_43 = 10 ;
clock . V_45 = 3 ;
clock . V_47 = 16 ;
clock . V_40 = 8 ;
} else if ( V_360 -> clock >= 140500
&& V_360 -> clock <= 200000 ) {
clock . V_42 = 1 ;
clock . V_43 = 10 ;
clock . V_45 = 6 ;
clock . V_47 = 12 ;
clock . V_40 = 8 ;
}
}
V_550 = F_265 ( V_360 ) ;
V_604 = 0 ;
if ( V_594 &&
! F_173 ( & V_594 -> V_52 ) ) {
V_603 = V_225 -> clock ;
F_279 ( V_594 ,
& V_604 , & V_605 ) ;
} else {
if ( V_538 || F_173 ( & V_594 -> V_52 ) )
V_603 = V_225 -> clock ;
else
V_603 = V_360 -> clock ;
V_605 = F_1 ( V_2 ) * F_280 ( 100 ) / F_281 ( 1 ) / 10 ;
}
V_283 = F_3 ( F_28 ( V_66 ) ) ;
V_283 &= ~ V_133 ;
V_607 = F_261 ( V_9 , & V_513 ) ;
switch ( V_513 ) {
case 18 :
V_283 |= V_608 ;
break;
case 24 :
V_283 |= V_609 ;
break;
case 30 :
V_283 |= V_610 ;
break;
case 36 :
V_283 |= V_611 ;
break;
default:
F_36 ( 1 , L_128 ,
V_513 ) ;
V_283 |= V_609 ;
V_513 = 24 ;
break;
}
V_148 -> V_523 = V_513 ;
F_23 ( F_28 ( V_66 ) , V_283 ) ;
if ( ! V_604 ) {
T_1 V_612 = V_603 * V_148 -> V_523 * 21 / 20 ;
V_604 = V_612 / ( V_605 * 8 ) + 1 ;
}
V_148 -> V_298 = V_604 ;
if ( V_550 > 1 )
V_605 *= V_550 ;
F_225 ( V_148 -> V_523 , V_604 , V_603 , V_605 ,
& V_382 ) ;
F_277 ( V_2 ) ;
V_528 = clock . V_45 << 16 | clock . V_47 << 8 | clock . V_40 ;
if ( V_532 )
V_529 = V_526 . V_45 << 16 | V_526 . V_47 << 8 |
V_526 . V_40 ;
V_606 = 21 ;
if ( V_536 ) {
if ( ( F_260 ( V_4 ) &&
V_4 -> V_543 == 100 ) ||
( F_3 ( V_13 ) & V_14 ) == V_15 )
V_606 = 25 ;
} else if ( V_533 && V_537 )
V_606 = 20 ;
if ( clock . V_39 < V_606 * clock . V_45 )
V_528 |= V_613 ;
V_527 = 0 ;
if ( V_536 )
V_527 |= V_548 ;
else
V_527 |= V_549 ;
if ( V_533 ) {
int V_550 = F_265 ( V_360 ) ;
if ( V_550 > 1 ) {
V_527 |= ( V_550 - 1 ) << V_614 ;
}
V_527 |= V_552 ;
}
if ( V_538 || F_173 ( & V_594 -> V_52 ) )
V_527 |= V_552 ;
V_527 |= ( 1 << ( clock . V_42 - 1 ) ) << V_554 ;
V_527 |= ( 1 << ( clock . V_42 - 1 ) ) << V_555 ;
switch ( clock . V_43 ) {
case 5 :
V_527 |= V_556 ;
break;
case 7 :
V_527 |= V_557 ;
break;
case 10 :
V_527 |= V_558 ;
break;
case 14 :
V_527 |= V_559 ;
break;
}
if ( V_533 && V_537 )
V_527 |= V_563 ;
else if ( V_537 )
V_527 |= 3 ;
else if ( V_536 && F_260 ( V_4 ) && V_525 < 2 )
V_527 |= V_564 ;
else
V_527 |= V_565 ;
V_530 = F_3 ( F_28 ( V_66 ) ) ;
V_252 = V_566 ;
F_25 ( L_121 , V_66 == 0 ? 'A' : 'B' ) ;
F_267 ( V_225 ) ;
if ( ! V_594 || F_173 ( & V_594 -> V_52 ) ) {
F_23 ( F_282 ( V_66 ) , V_528 ) ;
F_23 ( F_38 ( V_66 ) , V_527 & ~ V_80 ) ;
F_72 ( F_38 ( V_66 ) ) ;
F_73 ( 150 ) ;
}
if ( F_56 ( V_2 ) ) {
V_283 = F_3 ( V_318 ) ;
switch ( V_66 ) {
case 0 :
V_283 |= V_319 | V_320 ;
break;
case 1 :
V_283 |= V_321 | V_322 ;
break;
case 2 :
V_283 |= V_339 | V_340 ;
break;
default:
F_136 () ;
}
F_23 ( V_318 , V_283 ) ;
F_72 ( V_318 ) ;
F_73 ( 150 ) ;
}
if ( V_536 ) {
V_283 = F_3 ( V_13 ) ;
V_283 |= V_117 | V_570 ;
if ( V_66 == 1 ) {
if ( F_56 ( V_2 ) )
V_283 |= V_615 ;
else
V_283 |= V_94 ;
} else {
if ( F_56 ( V_2 ) )
V_283 &= ~ V_115 ;
else
V_283 &= ~ V_94 ;
}
V_283 |= V_4 -> V_571 ;
if ( clock . V_43 == 7 )
V_283 |= V_572 | V_15 ;
else
V_283 &= ~ ( V_572 | V_15 ) ;
if ( V_360 -> V_226 & V_575 )
V_539 |= V_576 ;
if ( V_360 -> V_226 & V_577 )
V_539 |= V_578 ;
if ( ( V_283 & ( V_576 | V_578 ) )
!= V_539 ) {
char V_226 [ 2 ] = L_122 ;
F_269 ( L_123
L_124 ,
V_226 [ ! ( V_283 & V_576 ) ] ,
V_226 [ ! ( V_283 & V_578 ) ] ,
V_226 [ ! ( V_539 & V_576 ) ] ,
V_226 [ ! ( V_539 & V_578 ) ] ) ;
V_283 &= ~ ( V_576 | V_578 ) ;
V_283 |= V_539 ;
}
F_23 ( V_13 , V_283 ) ;
}
V_530 &= ~ V_616 ;
V_530 &= ~ V_617 ;
if ( ( V_536 && V_4 -> V_573 ) || V_607 ) {
V_530 |= V_616 ;
V_530 |= V_618 ;
}
if ( V_538 || F_173 ( & V_594 -> V_52 ) ) {
F_270 ( V_9 , V_225 , V_360 ) ;
} else {
F_23 ( F_283 ( V_66 ) , 0 ) ;
F_23 ( F_284 ( V_66 ) , 0 ) ;
F_23 ( F_285 ( V_66 ) , 0 ) ;
F_23 ( F_286 ( V_66 ) , 0 ) ;
}
if ( ! V_594 ||
F_173 ( & V_594 -> V_52 ) ) {
F_23 ( F_38 ( V_66 ) , V_527 ) ;
F_72 ( F_38 ( V_66 ) ) ;
F_73 ( 150 ) ;
F_23 ( F_38 ( V_66 ) , V_527 ) ;
}
V_148 -> V_580 = false ;
if ( V_536 && V_532 && V_216 ) {
F_23 ( F_287 ( V_66 ) , V_529 ) ;
V_148 -> V_580 = true ;
if ( F_273 ( V_2 ) ) {
F_25 ( L_125 ) ;
V_530 |= V_581 ;
}
} else {
F_23 ( F_287 ( V_66 ) , V_528 ) ;
if ( F_273 ( V_2 ) ) {
F_25 ( L_126 ) ;
V_530 &= ~ V_581 ;
}
}
if ( V_360 -> V_226 & V_227 ) {
V_530 |= V_582 ;
V_360 -> V_583 -= 1 ;
V_360 -> V_584 -= 1 ;
V_360 -> V_585 -= 1 ;
V_360 -> V_586 -= 1 ;
V_360 -> V_587 -= 1 ;
V_360 -> V_588 -= 1 ;
} else
V_530 &= ~ V_582 ;
F_23 ( F_176 ( V_66 ) ,
( V_360 -> V_589 - 1 ) |
( ( V_360 -> V_362 - 1 ) << 16 ) ) ;
F_23 ( F_178 ( V_66 ) ,
( V_360 -> V_590 - 1 ) |
( ( V_360 -> V_591 - 1 ) << 16 ) ) ;
F_23 ( F_180 ( V_66 ) ,
( V_360 -> V_592 - 1 ) |
( ( V_360 -> V_593 - 1 ) << 16 ) ) ;
F_23 ( F_182 ( V_66 ) ,
( V_360 -> V_583 - 1 ) |
( ( V_360 -> V_584 - 1 ) << 16 ) ) ;
F_23 ( F_184 ( V_66 ) ,
( V_360 -> V_585 - 1 ) |
( ( V_360 -> V_586 - 1 ) << 16 ) ) ;
F_23 ( F_186 ( V_66 ) ,
( V_360 -> V_588 - 1 ) |
( ( V_360 -> V_587 - 1 ) << 16 ) ) ;
F_23 ( F_276 ( V_66 ) ,
( ( V_225 -> V_230 - 1 ) << 16 ) | ( V_225 -> V_231 - 1 ) ) ;
F_23 ( F_164 ( V_66 ) , F_288 ( V_382 . V_383 ) | V_382 . V_384 ) ;
F_23 ( F_289 ( V_66 ) , V_382 . V_385 ) ;
F_23 ( F_290 ( V_66 ) , V_382 . V_386 ) ;
F_23 ( F_291 ( V_66 ) , V_382 . V_387 ) ;
if ( V_594 &&
! F_173 ( & V_594 -> V_52 ) ) {
F_150 ( V_9 , V_360 -> clock ) ;
}
F_23 ( F_28 ( V_66 ) , V_530 ) ;
F_72 ( F_28 ( V_66 ) ) ;
F_21 ( V_2 , V_66 ) ;
if ( F_2 ( V_2 ) ) {
V_283 = F_3 ( V_483 ) ;
F_23 ( V_483 , V_283 | V_619 ) ;
}
F_23 ( F_49 ( V_97 ) , V_252 ) ;
F_72 ( F_49 ( V_97 ) ) ;
V_241 = F_146 ( V_9 , V_249 , V_162 , V_265 ) ;
F_189 ( V_2 ) ;
return V_241 ;
}
static int F_292 ( struct V_8 * V_9 ,
struct V_359 * V_225 ,
struct V_359 * V_360 ,
int V_249 , int V_162 ,
struct V_142 * V_265 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
int V_241 ;
F_293 ( V_2 , V_66 ) ;
V_241 = V_4 -> V_200 . V_620 ( V_9 , V_225 , V_360 ,
V_249 , V_162 , V_265 ) ;
F_294 ( V_2 , V_66 ) ;
V_148 -> V_347 = V_341 ;
return V_241 ;
}
void F_193 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_621 = F_295 ( V_148 -> V_66 ) ;
int V_99 ;
if ( ! V_9 -> V_76 )
return;
if ( F_8 ( V_2 ) )
V_621 = F_296 ( V_148 -> V_66 ) ;
for ( V_99 = 0 ; V_99 < 256 ; V_99 ++ ) {
F_23 ( V_621 + 4 * V_99 ,
( V_148 -> V_622 [ V_99 ] << 16 ) |
( V_148 -> V_623 [ V_99 ] << 8 ) |
V_148 -> V_624 [ V_99 ] ) ;
}
}
static void F_297 ( struct V_8 * V_9 , T_1 V_52 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
bool V_625 = V_52 != 0 ;
T_1 V_626 ;
if ( V_148 -> V_627 == V_625 )
return;
V_626 = F_3 ( V_628 ) ;
if ( V_625 ) {
F_23 ( V_629 , V_52 ) ;
V_626 &= ~ ( V_630 ) ;
V_626 |= V_631 |
V_632 |
V_633 ;
} else
V_626 &= ~ ( V_631 | V_632 ) ;
F_23 ( V_628 , V_626 ) ;
V_148 -> V_627 = V_625 ;
}
static void F_298 ( struct V_8 * V_9 , T_1 V_52 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
bool V_625 = V_52 != 0 ;
if ( V_148 -> V_627 != V_625 ) {
T_5 V_626 = F_3 ( F_299 ( V_66 ) ) ;
if ( V_52 ) {
V_626 &= ~ ( V_634 | V_635 ) ;
V_626 |= V_636 | V_637 ;
V_626 |= V_66 << 28 ;
} else {
V_626 &= ~ ( V_634 | V_637 ) ;
V_626 |= V_638 ;
}
F_23 ( F_299 ( V_66 ) , V_626 ) ;
V_148 -> V_627 = V_625 ;
}
F_23 ( F_300 ( V_66 ) , V_52 ) ;
}
static void F_194 ( struct V_8 * V_9 ,
bool V_639 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
int V_249 = V_148 -> V_640 ;
int V_162 = V_148 -> V_641 ;
T_1 V_52 , V_642 ;
bool V_625 ;
V_642 = 0 ;
if ( V_639 && V_9 -> V_76 && V_9 -> V_143 ) {
V_52 = V_148 -> V_643 ;
if ( V_249 > ( int ) V_9 -> V_143 -> V_644 )
V_52 = 0 ;
if ( V_162 > ( int ) V_9 -> V_143 -> V_645 )
V_52 = 0 ;
} else
V_52 = 0 ;
if ( V_249 < 0 ) {
if ( V_249 + V_148 -> V_646 < 0 )
V_52 = 0 ;
V_642 |= V_647 << V_648 ;
V_249 = - V_249 ;
}
V_642 |= V_249 << V_648 ;
if ( V_162 < 0 ) {
if ( V_162 + V_148 -> V_649 < 0 )
V_52 = 0 ;
V_642 |= V_647 << V_650 ;
V_162 = - V_162 ;
}
V_642 |= V_162 << V_650 ;
V_625 = V_52 != 0 ;
if ( ! V_625 && ! V_148 -> V_627 )
return;
F_23 ( F_301 ( V_66 ) , V_642 ) ;
if ( F_302 ( V_2 ) || F_303 ( V_2 ) )
F_297 ( V_9 , V_52 ) ;
else
F_298 ( V_9 , V_52 ) ;
if ( V_625 )
F_304 ( V_2 , F_101 ( V_9 -> V_143 ) -> V_147 ) ;
}
static int F_305 ( struct V_8 * V_9 ,
struct V_651 * V_652 ,
T_5 V_653 ,
T_5 V_644 , T_5 V_645 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
struct V_146 * V_147 ;
T_5 V_654 ;
int V_241 ;
F_25 ( L_40 ) ;
if ( ! V_653 ) {
F_25 ( L_129 ) ;
V_654 = 0 ;
V_147 = NULL ;
F_119 ( & V_2 -> V_206 ) ;
goto V_655;
}
if ( V_644 != 64 || V_645 != 64 ) {
F_83 ( L_130 ) ;
return - V_244 ;
}
V_147 = F_306 ( F_307 ( V_2 , V_652 , V_653 ) ) ;
if ( & V_147 -> V_52 == NULL )
return - V_656 ;
if ( V_147 -> V_52 . V_223 < V_644 * V_645 * 4 ) {
F_83 ( L_131 ) ;
V_241 = - V_657 ;
goto V_658;
}
F_119 ( & V_2 -> V_206 ) ;
if ( ! V_4 -> V_83 -> V_659 ) {
if ( V_147 -> V_234 ) {
F_83 ( L_132 ) ;
V_241 = - V_244 ;
goto V_660;
}
V_241 = F_137 ( V_147 , 0 , NULL ) ;
if ( V_241 ) {
F_83 ( L_133 ) ;
goto V_660;
}
V_241 = F_308 ( V_147 ) ;
if ( V_241 ) {
F_83 ( L_134 ) ;
goto V_661;
}
V_654 = V_147 -> V_195 ;
} else {
int V_662 = F_71 ( V_2 ) ? 16 * 1024 : 256 ;
V_241 = F_309 ( V_2 , V_147 ,
( V_148 -> V_66 == 0 ) ? V_663 : V_664 ,
V_662 ) ;
if ( V_241 ) {
F_83 ( L_135 ) ;
goto V_660;
}
V_654 = V_147 -> V_665 -> V_653 -> V_666 ;
}
if ( F_11 ( V_2 ) )
F_23 ( V_667 , ( V_645 << 12 ) | V_644 ) ;
V_655:
if ( V_148 -> V_668 ) {
if ( V_4 -> V_83 -> V_659 ) {
if ( V_148 -> V_668 != V_147 )
F_310 ( V_2 , V_148 -> V_668 ) ;
} else
F_139 ( V_148 -> V_668 ) ;
F_311 ( & V_148 -> V_668 -> V_52 ) ;
}
F_120 ( & V_2 -> V_206 ) ;
V_148 -> V_643 = V_654 ;
V_148 -> V_668 = V_147 ;
V_148 -> V_646 = V_644 ;
V_148 -> V_649 = V_645 ;
F_194 ( V_9 , true ) ;
return 0 ;
V_661:
F_139 ( V_147 ) ;
V_660:
F_120 ( & V_2 -> V_206 ) ;
V_658:
F_312 ( & V_147 -> V_52 ) ;
return V_241 ;
}
static int F_313 ( struct V_8 * V_9 , int V_249 , int V_162 )
{
struct V_148 * V_148 = F_102 ( V_9 ) ;
V_148 -> V_640 = V_249 ;
V_148 -> V_641 = V_162 ;
F_194 ( V_9 , true ) ;
return 0 ;
}
void F_314 ( struct V_8 * V_9 , T_4 V_669 , T_4 V_670 ,
T_4 V_671 , int V_672 )
{
struct V_148 * V_148 = F_102 ( V_9 ) ;
V_148 -> V_622 [ V_672 ] = V_669 >> 8 ;
V_148 -> V_623 [ V_672 ] = V_670 >> 8 ;
V_148 -> V_624 [ V_672 ] = V_671 >> 8 ;
}
void F_315 ( struct V_8 * V_9 , T_4 * V_669 , T_4 * V_670 ,
T_4 * V_671 , int V_672 )
{
struct V_148 * V_148 = F_102 ( V_9 ) ;
* V_669 = V_148 -> V_622 [ V_672 ] << 8 ;
* V_670 = V_148 -> V_623 [ V_672 ] << 8 ;
* V_671 = V_148 -> V_624 [ V_672 ] << 8 ;
}
static void F_316 ( struct V_8 * V_9 , T_4 * V_669 , T_4 * V_670 ,
T_4 * V_671 , T_5 V_673 , T_5 V_223 )
{
int V_674 = ( V_673 + V_223 > 256 ) ? 256 : V_673 + V_223 , V_99 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
for ( V_99 = V_673 ; V_99 < V_674 ; V_99 ++ ) {
V_148 -> V_622 [ V_99 ] = V_669 [ V_99 ] >> 8 ;
V_148 -> V_623 [ V_99 ] = V_670 [ V_99 ] >> 8 ;
V_148 -> V_624 [ V_99 ] = V_671 [ V_99 ] >> 8 ;
}
F_193 ( V_9 ) ;
}
static struct V_142 *
F_317 ( struct V_1 * V_2 ,
struct V_675 * V_676 ,
struct V_146 * V_147 )
{
struct V_144 * V_145 ;
int V_241 ;
V_145 = F_125 ( sizeof( * V_145 ) , V_213 ) ;
if ( ! V_145 ) {
F_312 ( & V_147 -> V_52 ) ;
return F_318 ( - V_657 ) ;
}
V_241 = F_319 ( V_2 , V_145 , V_676 , V_147 ) ;
if ( V_241 ) {
F_312 ( & V_147 -> V_52 ) ;
F_121 ( V_145 ) ;
return F_318 ( V_241 ) ;
}
return & V_145 -> V_52 ;
}
static T_1
F_320 ( int V_644 , int V_523 )
{
T_1 V_153 = F_227 ( V_644 * V_523 , 8 ) ;
return F_321 ( V_153 , 64 ) ;
}
static T_1
F_322 ( struct V_359 * V_225 , int V_523 )
{
T_1 V_153 = F_320 ( V_225 -> V_230 , V_523 ) ;
return F_321 ( V_153 * V_225 -> V_231 , V_677 ) ;
}
static struct V_142 *
F_323 ( struct V_1 * V_2 ,
struct V_359 * V_225 ,
int V_256 , int V_523 )
{
struct V_146 * V_147 ;
struct V_675 V_676 ;
V_147 = F_324 ( V_2 ,
F_322 ( V_225 , V_523 ) ) ;
if ( V_147 == NULL )
return F_318 ( - V_657 ) ;
V_676 . V_644 = V_225 -> V_230 ;
V_676 . V_645 = V_225 -> V_231 ;
V_676 . V_256 = V_256 ;
V_676 . V_523 = V_523 ;
V_676 . V_153 = F_320 ( V_676 . V_644 , V_523 ) ;
return F_317 ( V_2 , & V_676 , V_147 ) ;
}
static struct V_142 *
F_325 ( struct V_1 * V_2 ,
struct V_359 * V_225 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_146 * V_147 ;
struct V_142 * V_143 ;
if ( V_4 -> V_678 == NULL )
return NULL ;
V_147 = V_4 -> V_678 -> V_679 . V_147 ;
if ( V_147 == NULL )
return NULL ;
V_143 = & V_4 -> V_678 -> V_679 . V_52 ;
if ( V_143 -> V_153 < F_320 ( V_225 -> V_230 ,
V_143 -> V_254 ) )
return NULL ;
if ( V_147 -> V_52 . V_223 < V_225 -> V_231 * V_143 -> V_153 )
return NULL ;
return V_143 ;
}
bool F_326 ( struct V_50 * V_50 ,
struct V_514 * V_515 ,
struct V_359 * V_225 ,
struct V_680 * V_681 )
{
struct V_148 * V_148 ;
struct V_8 * V_682 ;
struct V_356 * V_51 = & V_50 -> V_52 ;
struct V_8 * V_9 = NULL ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_142 * V_265 ;
int V_99 = - 1 ;
F_25 ( L_136 ,
V_515 -> V_52 . V_211 , F_327 ( V_515 ) ,
V_51 -> V_52 . V_211 , F_328 ( V_51 ) ) ;
if ( V_51 -> V_9 ) {
V_9 = V_51 -> V_9 ;
V_148 = F_102 ( V_9 ) ;
V_681 -> V_347 = V_148 -> V_347 ;
V_681 -> V_683 = false ;
if ( V_148 -> V_347 != V_341 ) {
struct V_357 * V_358 ;
struct V_353 * V_354 ;
V_354 = V_9 -> V_355 ;
V_354 -> V_348 ( V_9 , V_341 ) ;
V_358 = V_51 -> V_355 ;
V_358 -> V_348 ( V_51 , V_341 ) ;
}
return true ;
}
F_14 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_99 ++ ;
if ( ! ( V_51 -> V_684 & ( 1 << V_99 ) ) )
continue;
if ( ! V_682 -> V_76 ) {
V_9 = V_682 ;
break;
}
}
if ( ! V_9 ) {
F_25 ( L_137 ) ;
return false ;
}
V_51 -> V_9 = V_9 ;
V_515 -> V_51 = V_51 ;
V_148 = F_102 ( V_9 ) ;
V_681 -> V_347 = V_148 -> V_347 ;
V_681 -> V_683 = true ;
V_681 -> V_685 = NULL ;
if ( ! V_225 )
V_225 = & V_686 ;
V_265 = V_9 -> V_143 ;
V_9 -> V_143 = F_325 ( V_2 , V_225 ) ;
if ( V_9 -> V_143 == NULL ) {
F_25 ( L_138 ) ;
V_9 -> V_143 = F_323 ( V_2 , V_225 , 24 , 32 ) ;
V_681 -> V_685 = V_9 -> V_143 ;
} else
F_25 ( L_139 ) ;
if ( F_329 ( V_9 -> V_143 ) ) {
F_25 ( L_140 ) ;
V_9 -> V_143 = V_265 ;
return false ;
}
if ( ! F_330 ( V_9 , V_225 , 0 , 0 , V_265 ) ) {
F_25 ( L_141 ) ;
if ( V_681 -> V_685 )
V_681 -> V_685 -> V_687 -> V_688 ( V_681 -> V_685 ) ;
V_9 -> V_143 = V_265 ;
return false ;
}
F_21 ( V_2 , V_148 -> V_66 ) ;
return true ;
}
void F_331 ( struct V_50 * V_50 ,
struct V_514 * V_515 ,
struct V_680 * V_681 )
{
struct V_356 * V_51 = & V_50 -> V_52 ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_8 * V_9 = V_51 -> V_9 ;
struct V_357 * V_358 = V_51 -> V_355 ;
struct V_353 * V_354 = V_9 -> V_355 ;
F_25 ( L_136 ,
V_515 -> V_52 . V_211 , F_327 ( V_515 ) ,
V_51 -> V_52 . V_211 , F_328 ( V_51 ) ) ;
if ( V_681 -> V_683 ) {
V_515 -> V_51 = NULL ;
F_332 ( V_2 ) ;
if ( V_681 -> V_685 )
V_681 -> V_685 -> V_687 -> V_688 ( V_681 -> V_685 ) ;
return;
}
if ( V_681 -> V_347 != V_341 ) {
V_358 -> V_348 ( V_51 , V_681 -> V_347 ) ;
V_354 -> V_348 ( V_9 , V_681 -> V_347 ) ;
}
}
static int F_333 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
T_1 V_527 = F_3 ( F_35 ( V_66 ) ) ;
T_1 V_528 ;
T_3 clock ;
if ( ( V_527 & V_689 ) == 0 )
V_528 = F_3 ( F_268 ( V_66 ) ) ;
else
V_528 = F_3 ( F_272 ( V_66 ) ) ;
clock . V_47 = ( V_528 & V_690 ) >> V_691 ;
if ( F_10 ( V_2 ) ) {
clock . V_45 = F_244 ( ( V_528 & V_692 ) >> V_693 ) - 1 ;
clock . V_40 = ( V_528 & V_694 ) >> V_695 ;
} else {
clock . V_45 = ( V_528 & V_696 ) >> V_693 ;
clock . V_40 = ( V_528 & V_697 ) >> V_695 ;
}
if ( ! F_11 ( V_2 ) ) {
if ( F_10 ( V_2 ) )
clock . V_42 = F_244 ( ( V_527 & V_698 ) >>
V_553 ) ;
else
clock . V_42 = F_244 ( ( V_527 & V_699 ) >>
V_554 ) ;
switch ( V_527 & V_700 ) {
case V_549 :
clock . V_43 = V_527 & V_556 ?
5 : 10 ;
break;
case V_548 :
clock . V_43 = V_527 & V_557 ?
7 : 14 ;
break;
default:
F_25 ( L_142
L_143 , ( int ) ( V_527 & V_700 ) ) ;
return 0 ;
}
F_13 ( V_2 , 96000 , & clock ) ;
} else {
bool V_536 = ( V_66 == 1 ) && ( F_3 ( V_24 ) & V_117 ) ;
if ( V_536 ) {
clock . V_42 = F_244 ( ( V_527 & V_701 ) >>
V_554 ) ;
clock . V_43 = 14 ;
if ( ( V_527 & V_702 ) ==
V_564 ) {
F_13 ( V_2 , 66000 , & clock ) ;
} else
F_13 ( V_2 , 48000 , & clock ) ;
} else {
if ( V_527 & V_561 )
clock . V_42 = 2 ;
else {
clock . V_42 = ( ( V_527 & V_703 ) >>
V_554 ) + 2 ;
}
if ( V_527 & V_562 )
clock . V_43 = 4 ;
else
clock . V_43 = 2 ;
F_13 ( V_2 , 48000 , & clock ) ;
}
}
return clock . V_46 ;
}
struct V_359 * F_334 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
struct V_359 * V_225 ;
int V_704 = F_3 ( F_176 ( V_66 ) ) ;
int V_705 = F_3 ( F_180 ( V_66 ) ) ;
int V_706 = F_3 ( F_182 ( V_66 ) ) ;
int V_707 = F_3 ( F_186 ( V_66 ) ) ;
V_225 = F_125 ( sizeof( * V_225 ) , V_213 ) ;
if ( ! V_225 )
return NULL ;
V_225 -> clock = F_333 ( V_2 , V_9 ) ;
V_225 -> V_230 = ( V_704 & 0xffff ) + 1 ;
V_225 -> V_436 = ( ( V_704 & 0xffff0000 ) >> 16 ) + 1 ;
V_225 -> V_708 = ( V_705 & 0xffff ) + 1 ;
V_225 -> V_709 = ( ( V_705 & 0xffff0000 ) >> 16 ) + 1 ;
V_225 -> V_231 = ( V_706 & 0xffff ) + 1 ;
V_225 -> V_710 = ( ( V_706 & 0xffff0000 ) >> 16 ) + 1 ;
V_225 -> V_711 = ( V_707 & 0xffff ) + 1 ;
V_225 -> V_712 = ( ( V_707 & 0xffff0000 ) >> 16 ) + 1 ;
F_335 ( V_225 ) ;
F_215 ( V_225 , 0 ) ;
return V_225 ;
}
static void F_336 ( unsigned long V_713 )
{
struct V_1 * V_2 = (struct V_1 * ) V_713 ;
T_6 * V_4 = V_2 -> V_5 ;
if ( ! F_337 ( & V_4 -> V_245 . V_714 ) ) {
F_338 ( & V_4 -> V_715 , V_74 +
F_30 ( V_716 ) ) ;
return;
}
V_4 -> V_717 = false ;
F_339 ( V_4 -> V_718 , & V_4 -> V_719 ) ;
}
static void F_340 ( unsigned long V_713 )
{
struct V_148 * V_148 = (struct V_148 * ) V_713 ;
struct V_8 * V_9 = & V_148 -> V_52 ;
T_6 * V_4 = V_9 -> V_2 -> V_5 ;
struct V_144 * V_145 ;
V_145 = F_101 ( V_9 -> V_143 ) ;
if ( V_145 && V_145 -> V_147 -> V_333 ) {
F_338 ( & V_148 -> V_715 , V_74 +
F_30 ( V_720 ) ) ;
return;
}
V_148 -> V_717 = false ;
F_339 ( V_4 -> V_718 , & V_4 -> V_719 ) ;
}
static void F_145 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_6 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
int V_721 = F_35 ( V_66 ) ;
int V_527 ;
if ( F_8 ( V_2 ) )
return;
if ( ! V_4 -> V_545 )
return;
V_527 = F_3 ( V_721 ) ;
if ( ! F_273 ( V_2 ) && ( V_527 & V_689 ) ) {
F_262 ( L_144 ) ;
F_23 ( V_91 ,
F_3 ( V_91 ) | V_93 ) ;
V_527 &= ~ V_689 ;
F_23 ( V_721 , V_527 ) ;
F_21 ( V_2 , V_66 ) ;
V_527 = F_3 ( V_721 ) ;
if ( V_527 & V_689 )
F_262 ( L_145 ) ;
F_23 ( V_91 , F_3 ( V_91 ) & 0x3 ) ;
}
F_338 ( & V_148 -> V_715 , V_74 +
F_30 ( V_720 ) ) ;
}
static void F_341 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_6 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
int V_66 = V_148 -> V_66 ;
int V_721 = F_35 ( V_66 ) ;
int V_527 = F_3 ( V_721 ) ;
if ( F_8 ( V_2 ) )
return;
if ( ! V_4 -> V_545 )
return;
if ( ! F_273 ( V_2 ) && V_148 -> V_580 ) {
F_262 ( L_146 ) ;
F_23 ( V_91 , F_3 ( V_91 ) |
V_93 ) ;
V_527 |= V_689 ;
F_23 ( V_721 , V_527 ) ;
F_21 ( V_2 , V_66 ) ;
V_527 = F_3 ( V_721 ) ;
if ( ! ( V_527 & V_689 ) )
F_262 ( L_147 ) ;
F_23 ( V_91 , F_3 ( V_91 ) & 0x3 ) ;
}
}
static void F_342 ( struct V_202 * V_205 )
{
T_6 * V_4 = F_117 ( V_205 , T_6 ,
V_719 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_8 * V_9 ;
struct V_148 * V_148 ;
if ( ! V_216 )
return;
F_119 ( & V_2 -> V_206 ) ;
F_343 ( V_4 ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_9 -> V_143 )
continue;
V_148 = F_102 ( V_9 ) ;
if ( ! V_148 -> V_717 )
F_341 ( V_9 ) ;
}
F_120 ( & V_2 -> V_206 ) ;
}
void F_304 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = NULL ;
struct V_144 * V_145 ;
struct V_148 * V_148 ;
if ( ! F_344 ( V_2 , V_722 ) )
return;
if ( ! V_4 -> V_717 )
V_4 -> V_717 = true ;
else
F_338 ( & V_4 -> V_715 , V_74 +
F_30 ( V_716 ) ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_9 -> V_143 )
continue;
V_148 = F_102 ( V_9 ) ;
V_145 = F_101 ( V_9 -> V_143 ) ;
if ( V_145 -> V_147 == V_147 ) {
if ( ! V_148 -> V_717 ) {
F_145 ( V_9 ) ;
V_148 -> V_717 = true ;
} else {
F_338 ( & V_148 -> V_715 , V_74 +
F_30 ( V_720 ) ) ;
}
}
}
}
static void F_345 ( struct V_8 * V_9 )
{
struct V_148 * V_148 = F_102 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_723 * V_205 ;
unsigned long V_226 ;
F_346 ( & V_2 -> V_724 , V_226 ) ;
V_205 = V_148 -> V_725 ;
V_148 -> V_725 = NULL ;
F_347 ( & V_2 -> V_724 , V_226 ) ;
if ( V_205 ) {
F_348 ( & V_205 -> V_205 ) ;
F_121 ( V_205 ) ;
}
F_349 ( V_9 ) ;
F_121 ( V_148 ) ;
}
static void F_350 ( struct V_202 * V_203 )
{
struct V_723 * V_205 =
F_117 ( V_203 , struct V_723 , V_205 ) ;
F_119 ( & V_205 -> V_2 -> V_206 ) ;
F_139 ( V_205 -> V_726 ) ;
F_311 ( & V_205 -> V_727 -> V_52 ) ;
F_311 ( & V_205 -> V_726 -> V_52 ) ;
F_129 ( V_205 -> V_2 ) ;
F_120 ( & V_205 -> V_2 -> V_206 ) ;
F_121 ( V_205 ) ;
}
static void F_351 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
struct V_723 * V_205 ;
struct V_146 * V_147 ;
struct V_728 * V_729 ;
struct V_730 V_731 , V_732 ;
unsigned long V_226 ;
if ( V_148 == NULL )
return;
F_352 ( & V_731 ) ;
F_346 ( & V_2 -> V_724 , V_226 ) ;
V_205 = V_148 -> V_725 ;
if ( V_205 == NULL || ! V_205 -> V_733 ) {
F_347 ( & V_2 -> V_724 , V_226 ) ;
return;
}
V_148 -> V_725 = NULL ;
if ( V_205 -> V_734 ) {
V_729 = V_205 -> V_734 ;
V_729 -> V_734 . V_735 = F_353 ( V_2 , V_148 -> V_66 , & V_732 ) ;
if ( 10 * ( F_354 ( & V_731 ) - F_354 ( & V_732 ) ) >
9 * V_9 -> V_736 ) {
V_729 -> V_734 . V_735 ++ ;
V_732 = F_355 ( F_354 ( & V_732 ) +
V_9 -> V_736 ) ;
}
V_729 -> V_734 . V_737 = V_732 . V_737 ;
V_729 -> V_734 . V_738 = V_732 . V_738 ;
F_356 ( & V_729 -> V_52 . V_739 ,
& V_729 -> V_52 . V_740 -> V_741 ) ;
F_357 ( & V_729 -> V_52 . V_740 -> V_742 ) ;
}
F_358 ( V_2 , V_148 -> V_66 ) ;
F_347 ( & V_2 -> V_724 , V_226 ) ;
V_147 = V_205 -> V_726 ;
F_359 ( 1 << V_148 -> V_97 ,
& V_147 -> V_270 . V_743 ) ;
if ( F_148 ( & V_147 -> V_270 ) == 0 )
F_360 ( & V_4 -> V_268 ) ;
F_361 ( & V_205 -> V_205 ) ;
F_362 ( V_148 -> V_97 , V_205 -> V_727 ) ;
}
void F_363 ( struct V_1 * V_2 , int V_66 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = V_4 -> V_744 [ V_66 ] ;
F_351 ( V_2 , V_9 ) ;
}
void F_364 ( struct V_1 * V_2 , int V_97 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = V_4 -> V_745 [ V_97 ] ;
F_351 ( V_2 , V_9 ) ;
}
void F_365 ( struct V_1 * V_2 , int V_97 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 =
F_102 ( V_4 -> V_745 [ V_97 ] ) ;
unsigned long V_226 ;
F_346 ( & V_2 -> V_724 , V_226 ) ;
if ( V_148 -> V_725 ) {
if ( ( ++ V_148 -> V_725 -> V_733 ) > 1 )
F_83 ( L_148 ) ;
} else {
F_262 ( L_149 ) ;
}
F_347 ( & V_2 -> V_724 , V_226 ) ;
}
static int F_366 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_142 * V_143 ,
struct V_146 * V_147 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
unsigned long V_746 ;
T_1 V_747 ;
int V_241 ;
V_241 = F_133 ( V_2 , V_147 , F_168 ( V_4 ) ) ;
if ( V_241 )
goto V_748;
V_746 = V_9 -> V_162 * V_143 -> V_153 + V_9 -> V_249 * V_143 -> V_254 / 8 ;
V_241 = F_367 ( 6 ) ;
if ( V_241 )
goto V_748;
if ( V_148 -> V_97 )
V_747 = V_749 ;
else
V_747 = V_750 ;
F_368 ( V_751 | V_747 ) ;
F_368 ( V_752 ) ;
F_368 ( V_753 |
F_369 ( V_148 -> V_97 ) ) ;
F_368 ( V_143 -> V_153 ) ;
F_368 ( V_147 -> V_195 + V_746 ) ;
F_368 ( V_752 ) ;
F_370 () ;
V_748:
return V_241 ;
}
static int F_371 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_142 * V_143 ,
struct V_146 * V_147 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
unsigned long V_746 ;
T_1 V_747 ;
int V_241 ;
V_241 = F_133 ( V_2 , V_147 , F_168 ( V_4 ) ) ;
if ( V_241 )
goto V_748;
V_746 = V_9 -> V_162 * V_143 -> V_153 + V_9 -> V_249 * V_143 -> V_254 / 8 ;
V_241 = F_367 ( 6 ) ;
if ( V_241 )
goto V_748;
if ( V_148 -> V_97 )
V_747 = V_749 ;
else
V_747 = V_750 ;
F_368 ( V_751 | V_747 ) ;
F_368 ( V_752 ) ;
F_368 ( V_754 |
F_369 ( V_148 -> V_97 ) ) ;
F_368 ( V_143 -> V_153 ) ;
F_368 ( V_147 -> V_195 + V_746 ) ;
F_368 ( V_752 ) ;
F_370 () ;
V_748:
return V_241 ;
}
static int F_372 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_142 * V_143 ,
struct V_146 * V_147 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
T_5 V_755 , V_756 ;
int V_241 ;
V_241 = F_133 ( V_2 , V_147 , F_168 ( V_4 ) ) ;
if ( V_241 )
goto V_748;
V_241 = F_367 ( 4 ) ;
if ( V_241 )
goto V_748;
F_368 ( V_753 |
F_369 ( V_148 -> V_97 ) ) ;
F_368 ( V_143 -> V_153 ) ;
F_368 ( V_147 -> V_195 | V_147 -> V_234 ) ;
V_755 = 0 ;
V_756 = F_3 ( F_276 ( V_148 -> V_66 ) ) & 0x0fff0fff ;
F_368 ( V_755 | V_756 ) ;
F_370 () ;
V_748:
return V_241 ;
}
static int F_373 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_142 * V_143 ,
struct V_146 * V_147 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
T_5 V_755 , V_756 ;
int V_241 ;
V_241 = F_133 ( V_2 , V_147 , F_168 ( V_4 ) ) ;
if ( V_241 )
goto V_748;
V_241 = F_367 ( 4 ) ;
if ( V_241 )
goto V_748;
F_368 ( V_753 |
F_369 ( V_148 -> V_97 ) ) ;
F_368 ( V_143 -> V_153 | V_147 -> V_234 ) ;
F_368 ( V_147 -> V_195 ) ;
V_755 = F_3 ( F_190 ( V_148 -> V_66 ) ) & V_335 ;
V_756 = F_3 ( F_276 ( V_148 -> V_66 ) ) & 0x0fff0fff ;
F_368 ( V_755 | V_756 ) ;
F_370 () ;
V_748:
return V_241 ;
}
static int F_374 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_142 * V_143 ,
struct V_146 * V_147 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
struct V_238 * V_313 = & V_4 -> V_313 [ V_757 ] ;
int V_241 ;
V_241 = F_133 ( V_2 , V_147 , V_313 ) ;
if ( V_241 )
goto V_748;
V_241 = F_375 ( V_313 , 4 ) ;
if ( V_241 )
goto V_748;
F_376 ( V_313 , V_754 | ( V_148 -> V_97 << 19 ) ) ;
F_376 ( V_313 , ( V_143 -> V_153 | V_147 -> V_234 ) ) ;
F_376 ( V_313 , ( V_147 -> V_195 ) ) ;
F_376 ( V_313 , ( V_752 ) ) ;
F_377 ( V_313 ) ;
V_748:
return V_241 ;
}
static int F_378 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_142 * V_143 ,
struct V_146 * V_147 )
{
return - V_758 ;
}
static int F_379 ( struct V_8 * V_9 ,
struct V_142 * V_143 ,
struct V_728 * V_734 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
struct V_723 * V_205 ;
unsigned long V_226 ;
int V_241 ;
V_205 = F_125 ( sizeof *V_205 , V_213 ) ;
if ( V_205 == NULL )
return - V_657 ;
V_205 -> V_734 = V_734 ;
V_205 -> V_2 = V_9 -> V_2 ;
V_145 = F_101 ( V_9 -> V_143 ) ;
V_205 -> V_726 = V_145 -> V_147 ;
F_380 ( & V_205 -> V_205 , F_350 ) ;
F_346 ( & V_2 -> V_724 , V_226 ) ;
if ( V_148 -> V_725 ) {
F_347 ( & V_2 -> V_724 , V_226 ) ;
F_121 ( V_205 ) ;
F_262 ( L_150 ) ;
return - V_759 ;
}
V_148 -> V_725 = V_205 ;
F_347 ( & V_2 -> V_724 , V_226 ) ;
V_145 = F_101 ( V_143 ) ;
V_147 = V_145 -> V_147 ;
F_119 ( & V_2 -> V_206 ) ;
F_381 ( & V_205 -> V_726 -> V_52 ) ;
F_381 ( & V_147 -> V_52 ) ;
V_9 -> V_143 = V_143 ;
V_241 = F_382 ( V_2 , V_148 -> V_66 ) ;
if ( V_241 )
goto V_760;
V_205 -> V_727 = V_147 ;
V_205 -> V_761 = true ;
F_383 ( 1 << V_148 -> V_97 , & V_205 -> V_726 -> V_270 ) ;
V_241 = V_4 -> V_200 . V_762 ( V_2 , V_9 , V_143 , V_147 ) ;
if ( V_241 )
goto V_763;
F_128 ( V_2 ) ;
F_120 ( & V_2 -> V_206 ) ;
F_384 ( V_148 -> V_97 , V_147 ) ;
return 0 ;
V_763:
F_385 ( 1 << V_148 -> V_97 , & V_205 -> V_726 -> V_270 ) ;
V_760:
F_311 ( & V_205 -> V_726 -> V_52 ) ;
F_311 ( & V_147 -> V_52 ) ;
F_120 ( & V_2 -> V_206 ) ;
F_346 ( & V_2 -> V_724 , V_226 ) ;
V_148 -> V_725 = NULL ;
F_347 ( & V_2 -> V_724 , V_226 ) ;
F_121 ( V_205 ) ;
return V_241 ;
}
static void F_386 ( struct V_1 * V_2 ,
int V_66 , int V_97 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_70 , V_78 ;
if ( F_8 ( V_2 ) )
return;
V_70 = F_49 ( V_97 ) ;
V_78 = F_3 ( V_70 ) ;
if ( ( V_78 & V_98 ) == 0 )
return;
if ( ! ! ( V_78 & V_101 ) == V_66 )
return;
V_66 = ! V_66 ;
F_95 ( V_4 , V_97 , V_66 ) ;
F_89 ( V_4 , V_66 ) ;
}
static void F_387 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_148 * V_148 = F_102 ( V_9 ) ;
V_148 -> V_347 = - 1 ;
F_386 ( V_2 , V_148 -> V_66 , V_148 -> V_97 ) ;
}
static void F_388 ( struct V_1 * V_2 , int V_66 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_148 * V_148 ;
int V_99 ;
V_148 = F_125 ( sizeof( struct V_148 ) + ( V_764 * sizeof( struct V_514 * ) ) , V_213 ) ;
if ( V_148 == NULL )
return;
F_389 ( V_2 , & V_148 -> V_52 , & V_765 ) ;
F_390 ( & V_148 -> V_52 , 256 ) ;
for ( V_99 = 0 ; V_99 < 256 ; V_99 ++ ) {
V_148 -> V_622 [ V_99 ] = V_99 ;
V_148 -> V_623 [ V_99 ] = V_99 ;
V_148 -> V_624 [ V_99 ] = V_99 ;
}
V_148 -> V_66 = V_66 ;
V_148 -> V_97 = V_66 ;
if ( F_70 ( V_2 ) && F_391 ( V_2 ) ) {
F_25 ( L_151 ) ;
V_148 -> V_97 = ! V_66 ;
}
F_69 ( V_66 >= F_229 ( V_4 -> V_745 ) ||
V_4 -> V_745 [ V_148 -> V_97 ] != NULL ) ;
V_4 -> V_745 [ V_148 -> V_97 ] = & V_148 -> V_52 ;
V_4 -> V_744 [ V_148 -> V_66 ] = & V_148 -> V_52 ;
F_387 ( & V_148 -> V_52 ) ;
V_148 -> V_333 = true ;
V_148 -> V_523 = 24 ;
if ( F_8 ( V_2 ) ) {
V_766 . V_767 = F_207 ;
V_766 . V_768 = F_208 ;
} else {
V_766 . V_767 = F_205 ;
V_766 . V_768 = F_206 ;
}
F_392 ( & V_148 -> V_52 , & V_766 ) ;
V_148 -> V_717 = false ;
F_393 ( & V_148 -> V_715 , F_340 ,
( unsigned long ) V_148 ) ;
}
int F_394 ( struct V_1 * V_2 , void * V_769 ,
struct V_651 * V_652 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_770 * V_771 = V_769 ;
struct V_772 * V_773 ;
struct V_148 * V_9 ;
if ( ! V_4 ) {
F_83 ( L_152 ) ;
return - V_244 ;
}
V_773 = F_395 ( V_2 , V_771 -> V_774 ,
V_775 ) ;
if ( ! V_773 ) {
F_83 ( L_153 ) ;
return - V_244 ;
}
V_9 = F_102 ( F_396 ( V_773 ) ) ;
V_771 -> V_66 = V_9 -> V_66 ;
return 0 ;
}
static int F_397 ( struct V_1 * V_2 , int V_776 )
{
struct V_50 * V_51 ;
int V_777 = 0 ;
int V_778 = 0 ;
F_14 (encoder, &dev->mode_config.encoder_list, base.head) {
if ( V_776 & V_51 -> V_779 )
V_777 |= ( 1 << V_778 ) ;
V_778 ++ ;
}
return V_777 ;
}
static bool F_398 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_70 ( V_2 ) )
return false ;
if ( ( F_3 ( V_281 ) & V_780 ) == 0 )
return false ;
if ( F_2 ( V_2 ) &&
( F_3 ( V_781 ) & V_782 ) )
return false ;
return true ;
}
static void F_399 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_50 * V_51 ;
bool V_783 = false ;
bool V_595 = false ;
if ( F_70 ( V_2 ) && ! F_71 ( V_2 ) )
V_595 = F_400 ( V_2 ) ;
if ( ! V_595 && ! F_8 ( V_2 ) ) {
F_23 ( V_784 , 0 ) ;
}
if ( F_8 ( V_2 ) ) {
V_783 = F_401 ( V_2 ) ;
if ( F_398 ( V_2 ) )
F_402 ( V_2 , V_281 ) ;
if ( V_783 && ( F_3 ( V_125 ) & V_780 ) )
F_402 ( V_2 , V_125 ) ;
}
F_403 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
int V_63 ;
if ( F_3 ( V_128 ) & V_785 ) {
V_63 = F_404 ( V_2 , V_786 ) ;
if ( ! V_63 )
F_405 ( V_2 , V_128 ) ;
if ( ! V_63 && ( F_3 ( V_121 ) & V_780 ) )
F_402 ( V_2 , V_121 ) ;
}
if ( F_3 ( V_129 ) & V_785 )
F_405 ( V_2 , V_129 ) ;
if ( F_3 ( V_130 ) & V_785 )
F_405 ( V_2 , V_130 ) ;
if ( F_3 ( V_123 ) & V_780 )
F_402 ( V_2 , V_123 ) ;
if ( ! V_783 && ( F_3 ( V_125 ) & V_780 ) )
F_402 ( V_2 , V_125 ) ;
} else if ( F_406 ( V_2 ) ) {
bool V_63 = false ;
if ( F_3 ( V_787 ) & V_788 ) {
F_25 ( L_154 ) ;
V_63 = F_404 ( V_2 , V_787 ) ;
if ( ! V_63 && F_407 ( V_2 ) ) {
F_25 ( L_155 ) ;
F_405 ( V_2 , V_787 ) ;
}
if ( ! V_63 && F_408 ( V_2 ) ) {
F_25 ( L_156 ) ;
F_402 ( V_2 , V_789 ) ;
}
}
if ( F_3 ( V_787 ) & V_788 ) {
F_25 ( L_157 ) ;
V_63 = F_404 ( V_2 , V_790 ) ;
}
if ( ! V_63 && ( F_3 ( V_790 ) & V_788 ) ) {
if ( F_407 ( V_2 ) ) {
F_25 ( L_158 ) ;
F_405 ( V_2 , V_790 ) ;
}
if ( F_408 ( V_2 ) ) {
F_25 ( L_159 ) ;
F_402 ( V_2 , V_791 ) ;
}
}
if ( F_408 ( V_2 ) &&
( F_3 ( V_792 ) & V_780 ) ) {
F_25 ( L_160 ) ;
F_402 ( V_2 , V_792 ) ;
}
} else if ( F_11 ( V_2 ) )
F_409 ( V_2 ) ;
if ( F_410 ( V_2 ) )
F_411 ( V_2 ) ;
F_14 (encoder, &dev->mode_config.encoder_list, base.head) {
V_51 -> V_52 . V_684 = V_51 -> V_793 ;
V_51 -> V_52 . V_794 =
F_397 ( V_2 , V_51 -> V_779 ) ;
}
F_332 ( V_2 ) ;
}
static void F_412 ( struct V_142 * V_143 )
{
struct V_144 * V_145 = F_101 ( V_143 ) ;
F_413 ( V_143 ) ;
F_312 ( & V_145 -> V_147 -> V_52 ) ;
F_121 ( V_145 ) ;
}
static int F_414 ( struct V_142 * V_143 ,
struct V_651 * V_652 ,
unsigned int * V_653 )
{
struct V_144 * V_145 = F_101 ( V_143 ) ;
struct V_146 * V_147 = V_145 -> V_147 ;
return F_415 ( V_652 , & V_147 -> V_52 , V_653 ) ;
}
int F_319 ( struct V_1 * V_2 ,
struct V_144 * V_145 ,
struct V_675 * V_676 ,
struct V_146 * V_147 )
{
int V_241 ;
if ( V_147 -> V_234 == V_243 )
return - V_244 ;
if ( V_676 -> V_153 & 63 )
return - V_244 ;
switch ( V_676 -> V_523 ) {
case 8 :
case 16 :
if ( V_676 -> V_256 == 15 && ! F_8 ( V_2 ) )
return - V_244 ;
break;
case 24 :
case 32 :
break;
default:
return - V_244 ;
}
V_241 = F_416 ( V_2 , & V_145 -> V_52 , & V_795 ) ;
if ( V_241 ) {
F_83 ( L_161 , V_241 ) ;
return V_241 ;
}
F_417 ( & V_145 -> V_52 , V_676 ) ;
V_145 -> V_147 = V_147 ;
return 0 ;
}
static struct V_142 *
F_418 ( struct V_1 * V_2 ,
struct V_651 * V_796 ,
struct V_675 * V_676 )
{
struct V_146 * V_147 ;
V_147 = F_306 ( F_307 ( V_2 , V_796 , V_676 -> V_653 ) ) ;
if ( & V_147 -> V_52 == NULL )
return F_318 ( - V_656 ) ;
return F_317 ( V_2 , V_676 , V_147 ) ;
}
static struct V_146 *
F_419 ( struct V_1 * V_2 )
{
struct V_146 * V_797 ;
int V_241 ;
F_420 ( ! F_421 ( & V_2 -> V_206 ) ) ;
V_797 = F_324 ( V_2 , 4096 ) ;
if ( ! V_797 ) {
F_263 ( L_162 ) ;
return NULL ;
}
V_241 = F_422 ( V_797 , 4096 , true ) ;
if ( V_241 ) {
F_83 ( L_163 , V_241 ) ;
goto V_798;
}
V_241 = F_423 ( V_797 , 1 ) ;
if ( V_241 ) {
F_83 ( L_164 , V_241 ) ;
goto V_248;
}
return V_797 ;
V_248:
F_139 ( V_797 ) ;
V_798:
F_311 ( & V_797 -> V_52 ) ;
F_120 ( & V_2 -> V_206 ) ;
return NULL ;
}
bool F_424 ( struct V_1 * V_2 , T_7 V_78 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_799 ;
V_799 = F_425 ( V_800 ) ;
if ( V_799 & V_801 ) {
F_263 ( L_165 ) ;
return false ;
}
V_799 = ( V_802 << V_803 ) |
( V_78 << V_804 ) | V_805 ;
F_426 ( V_800 , V_799 ) ;
F_427 ( V_800 ) ;
V_799 |= V_801 ;
F_426 ( V_800 , V_799 ) ;
return true ;
}
void F_428 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_806 = F_3 ( V_807 ) ;
T_7 V_808 , V_809 , V_810 , V_811 ;
F_426 ( V_812 , F_3 ( V_812 ) | V_813 ) ;
F_426 ( V_814 , F_3 ( V_814 ) | V_815 ) ;
F_23 ( V_816 , 100000 ) ;
F_23 ( V_817 , 100000 ) ;
F_23 ( V_818 , 90000 ) ;
F_23 ( V_819 , 80000 ) ;
F_23 ( V_820 , 1 ) ;
V_808 = ( V_806 & V_821 ) >> V_822 ;
V_809 = ( V_806 & V_823 ) ;
V_810 = ( V_806 & V_824 ) >>
V_825 ;
V_811 = ( F_3 ( V_826 + ( V_810 * 4 ) ) & V_827 ) >>
V_828 ;
V_4 -> V_808 = V_808 ;
V_4 -> V_810 = V_810 ;
V_4 -> V_829 = V_810 ;
V_4 -> V_830 = V_809 ;
V_4 -> V_831 = V_810 ;
F_262 ( L_166 ,
V_808 , V_809 , V_810 ) ;
F_23 ( V_832 , V_833 | V_834 ) ;
F_23 ( V_835 , V_811 ) ;
F_72 ( V_835 ) ;
V_806 |= V_836 ;
F_23 ( V_807 , V_806 ) ;
if ( F_24 ( ( F_3 ( V_800 ) & V_801 ) == 0 , 10 ) )
F_83 ( L_167 ) ;
F_429 ( 1 ) ;
F_424 ( V_2 , V_810 ) ;
V_4 -> V_837 = F_3 ( 0x112e4 ) + F_3 ( 0x112e8 ) +
F_3 ( 0x112e0 ) ;
V_4 -> V_838 = F_430 ( V_74 ) ;
V_4 -> V_839 = F_3 ( 0x112f4 ) ;
F_431 ( & V_4 -> V_840 ) ;
}
void F_432 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_799 = F_425 ( V_800 ) ;
F_23 ( V_832 , F_3 ( V_832 ) & ~ V_834 ) ;
F_23 ( V_841 , V_842 ) ;
F_23 ( V_843 , F_3 ( V_843 ) & ~ V_844 ) ;
F_23 ( V_845 , V_844 ) ;
F_23 ( V_846 , F_3 ( V_846 ) | V_844 ) ;
F_424 ( V_2 , V_4 -> V_810 ) ;
F_429 ( 1 ) ;
V_799 |= V_801 ;
F_23 ( V_800 , V_799 ) ;
F_429 ( 1 ) ;
}
void F_433 ( struct V_1 * V_2 , T_7 V_78 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_847 ;
V_847 = ( V_78 & 0x3ff ) << 25 ;
F_23 ( V_848 , V_847 ) ;
}
void F_434 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_848 , 1 << 31 ) ;
F_23 ( V_849 , 0xffffffff ) ;
F_23 ( V_850 , 0 ) ;
F_435 ( & V_4 -> V_851 ) ;
V_4 -> V_852 = 0 ;
F_436 ( & V_4 -> V_851 ) ;
F_23 ( V_853 , F_3 ( V_853 ) ) ;
}
static unsigned long F_437 ( T_1 V_854 )
{
unsigned long V_855 ;
int div = ( V_854 & 0x3f0000 ) >> 16 ;
int V_856 = ( V_854 & 0x3000 ) >> 12 ;
int V_857 = ( V_854 & 0x7 ) ;
if ( ! V_857 )
return 0 ;
V_855 = ( ( div * 133333 ) / ( ( 1 << V_856 ) * V_857 ) ) ;
return V_855 ;
}
void F_438 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_858 ;
T_7 V_859 [ 16 ] ;
int V_99 ;
F_23 ( V_860 , 0 ) ;
F_72 ( V_860 ) ;
F_23 ( V_861 , 0x15040d00 ) ;
F_23 ( V_862 , 0x007f0000 ) ;
F_23 ( V_863 , 0x1e220004 ) ;
F_23 ( V_864 , 0x04000004 ) ;
for ( V_99 = 0 ; V_99 < 5 ; V_99 ++ )
F_23 ( V_865 + ( V_99 * 4 ) , 0 ) ;
for ( V_99 = 0 ; V_99 < 3 ; V_99 ++ )
F_23 ( V_866 + ( V_99 * 4 ) , 0 ) ;
for ( V_99 = 0 ; V_99 < 16 ; V_99 ++ ) {
T_1 V_867 = F_3 ( V_826 + ( V_99 * 4 ) ) ;
unsigned long V_855 = F_437 ( V_867 ) ;
unsigned long V_868 = ( V_867 & V_827 ) >>
V_828 ;
unsigned long V_78 ;
V_78 = V_868 * V_868 ;
V_78 *= ( V_855 / 1000 ) ;
V_78 *= 255 ;
V_78 /= ( 127 * 127 * 900 ) ;
if ( V_78 > 0xff )
F_83 ( L_168 , V_78 ) ;
V_859 [ V_99 ] = V_78 ;
}
V_859 [ 14 ] = 0 ;
V_859 [ 15 ] = 0 ;
for ( V_99 = 0 ; V_99 < 4 ; V_99 ++ ) {
T_1 V_78 = ( V_859 [ V_99 * 4 ] << 24 ) | ( V_859 [ ( V_99 * 4 ) + 1 ] << 16 ) |
( V_859 [ ( V_99 * 4 ) + 2 ] << 8 ) | ( V_859 [ ( V_99 * 4 ) + 3 ] ) ;
F_23 ( V_869 + ( V_99 * 4 ) , V_78 ) ;
}
F_23 ( V_870 , 0 ) ;
F_23 ( V_871 , 0 ) ;
F_23 ( V_872 , 0x00007f00 ) ;
F_23 ( V_873 , 0x0000000e ) ;
F_23 ( V_874 , 0x000e0000 ) ;
F_23 ( V_875 , 0x68000300 ) ;
F_23 ( V_876 , 0x42000000 ) ;
F_23 ( V_877 , 0x00140031 ) ;
F_23 ( V_878 , 0 ) ;
F_23 ( V_879 , 0 ) ;
for ( V_99 = 0 ; V_99 < 8 ; V_99 ++ )
F_23 ( V_880 + ( V_99 * 4 ) , 0 ) ;
F_23 ( V_860 , 0x80000019 ) ;
V_858 = F_3 ( V_881 ) ;
V_4 -> V_882 = ( V_858 & V_883 ) ;
}
void F_439 ( struct V_3 * V_4 )
{
T_1 V_884 = F_3 ( V_885 ) ;
T_1 V_886 = F_3 ( V_887 ) ;
T_1 V_888 , V_889 = 0 ;
int V_890 , V_891 , V_892 ;
int V_99 ;
F_23 ( V_893 , 0 ) ;
F_119 ( & V_4 -> V_2 -> V_206 ) ;
F_109 ( V_4 ) ;
F_23 ( V_894 , 0 ) ;
F_23 ( V_895 , 1000 << 16 ) ;
F_23 ( V_896 , 40 << 16 | 30 ) ;
F_23 ( V_897 , 30 ) ;
F_23 ( V_898 , 125000 ) ;
F_23 ( V_899 , 25 ) ;
for ( V_99 = 0 ; V_99 < V_900 ; V_99 ++ )
F_23 ( F_440 ( V_4 -> V_313 [ V_99 ] . V_901 ) , 10 ) ;
F_23 ( V_902 , 0 ) ;
F_23 ( V_903 , 1000 ) ;
F_23 ( V_904 , 50000 ) ;
F_23 ( V_905 , 100000 ) ;
F_23 ( V_906 , 64000 ) ;
if ( V_907 )
V_889 = V_908 |
V_909 ;
F_23 ( V_894 ,
V_889 |
F_441 ( 1 ) |
V_910 ) ;
F_23 ( V_848 ,
F_442 ( 10 ) |
F_443 ( 0 ) |
V_911 ) ;
F_23 ( V_912 ,
F_442 ( 12 ) ) ;
F_23 ( V_913 , 1000000 ) ;
F_23 ( V_914 ,
18 << 24 |
6 << 16 ) ;
F_23 ( V_915 , 10000 ) ;
F_23 ( V_916 , 1000000 ) ;
F_23 ( V_917 , 100000 ) ;
F_23 ( V_918 , 5000000 ) ;
F_23 ( V_919 , 10 ) ;
F_23 ( V_920 ,
V_921 |
V_922 |
V_923 |
V_924 |
V_925 |
V_926 ) ;
if ( F_24 ( ( F_3 ( V_927 ) & V_928 ) == 0 ,
500 ) )
F_83 ( L_169 ) ;
F_23 ( V_929 , 0 ) ;
F_23 ( V_927 ,
V_928 |
V_930 ) ;
if ( F_24 ( ( F_3 ( V_927 ) & V_928 ) == 0 ,
500 ) )
F_83 ( L_170 ) ;
V_891 = ( V_884 & 0xff0000 ) >> 16 ;
V_892 = V_884 & 0xff ;
V_890 = ( V_886 & 0xff00 ) >> 8 ;
if ( F_24 ( ( F_3 ( V_927 ) & V_928 ) == 0 ,
500 ) )
F_83 ( L_169 ) ;
F_23 ( V_927 , V_931 ) ;
V_888 = F_3 ( V_929 ) ;
if ( F_24 ( ( F_3 ( V_927 ) & V_928 ) == 0 ,
500 ) )
F_83 ( L_170 ) ;
if ( V_888 & ( 1 << 31 ) ) {
V_892 = V_888 & 0xff ;
F_262 ( L_171 , V_888 * 50 ) ;
}
V_4 -> V_829 = V_892 ;
V_4 -> V_830 = V_891 ;
V_4 -> V_831 = V_890 ;
F_23 ( V_850 ,
V_932 |
V_933 |
V_934 |
V_935 |
V_936 |
V_937 |
V_938 ) ;
F_435 ( & V_4 -> V_851 ) ;
F_420 ( V_4 -> V_852 != 0 ) ;
F_23 ( V_939 , 0 ) ;
F_436 ( & V_4 -> V_851 ) ;
F_23 ( V_849 , 0 ) ;
F_110 ( V_4 ) ;
F_120 ( & V_4 -> V_2 -> V_206 ) ;
}
void F_444 ( struct V_3 * V_4 )
{
int V_891 = 15 ;
int V_940 , V_941 , V_942 ;
int V_943 = 180 ;
V_942 = F_445 ( 0 ) ;
if ( ! V_942 )
V_942 = V_944 ;
V_942 /= 1000 ;
F_119 ( & V_4 -> V_2 -> V_206 ) ;
for ( V_940 = V_4 -> V_829 ; V_940 >= V_4 -> V_830 ;
V_940 -- ) {
int V_945 = V_4 -> V_829 - V_940 ;
if ( V_940 < V_891 )
V_941 = 800 ;
else
V_941 = V_942 - ( ( V_945 * V_943 ) / 2 ) ;
V_941 = F_446 ( V_941 , 100 ) ;
F_23 ( V_929 ,
( V_941 << V_946 ) |
V_940 ) ;
F_23 ( V_927 , V_928 |
V_930 ) ;
if ( F_24 ( ( F_3 ( V_927 ) &
V_928 ) == 0 , 10 ) ) {
F_83 ( L_172 ) ;
continue;
}
}
F_120 ( & V_4 -> V_2 -> V_206 ) ;
}
static void F_447 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_947 = V_948 ;
V_947 |= V_949 |
V_950 |
V_951 ;
V_947 |= V_952 ;
F_23 ( V_953 ,
V_954 |
V_955 ) ;
F_23 ( V_956 ,
V_957 ) ;
F_23 ( V_958 , V_947 ) ;
F_23 ( V_959 ,
( F_3 ( V_959 ) |
V_960 | V_961 ) ) ;
F_23 ( V_962 ,
( F_3 ( V_962 ) |
V_963 ) ) ;
F_23 ( V_483 ,
( F_3 ( V_483 ) |
V_484 ) ) ;
F_23 ( V_494 , 0 ) ;
F_23 ( V_495 , 0 ) ;
F_23 ( V_496 , 0 ) ;
if ( F_448 ( V_2 ) ) {
F_23 ( V_964 ,
F_3 ( V_964 ) |
V_965 ) ;
F_23 ( V_959 ,
F_3 ( V_959 ) |
V_960 ) ;
F_23 ( V_962 ,
F_3 ( V_962 ) |
V_966 |
V_967 |
V_968 ) ;
}
F_23 ( V_959 ,
F_3 ( V_959 ) |
V_969 ) ;
F_23 ( V_970 ,
V_971 << 16 |
V_971 ) ;
}
static void F_449 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
T_5 V_947 = V_948 ;
F_23 ( V_958 , V_947 ) ;
F_23 ( V_959 ,
F_3 ( V_959 ) |
V_969 ) ;
F_23 ( V_494 , 0 ) ;
F_23 ( V_495 , 0 ) ;
F_23 ( V_496 , 0 ) ;
F_23 ( V_964 ,
F_3 ( V_964 ) |
V_965 | V_972 ) ;
F_23 ( V_959 ,
F_3 ( V_959 ) |
V_960 | V_961 ) ;
F_23 ( V_962 ,
F_3 ( V_962 ) |
V_963 |
V_973 ) ;
F_450 (pipe) {
F_23 ( F_49 ( V_66 ) ,
F_3 ( F_49 ( V_66 ) ) |
V_262 ) ;
F_90 ( V_4 , V_66 ) ;
}
}
static void F_451 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
T_5 V_947 = V_948 ;
F_23 ( V_958 , V_947 ) ;
F_23 ( V_494 , 0 ) ;
F_23 ( V_495 , 0 ) ;
F_23 ( V_496 , 0 ) ;
F_23 ( V_962 , V_974 ) ;
F_450 (pipe) {
F_23 ( F_49 ( V_66 ) ,
F_3 ( F_49 ( V_66 ) ) |
V_262 ) ;
F_90 ( V_4 , V_66 ) ;
}
}
static void F_452 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_947 ;
F_23 ( V_975 , 0 ) ;
F_23 ( V_976 , V_977 |
V_978 |
V_979 ) ;
F_23 ( V_980 , 0 ) ;
V_947 = V_948 |
V_981 |
V_982 ;
if ( F_453 ( V_2 ) )
V_947 |= V_983 ;
F_23 ( V_984 , V_947 ) ;
}
static void F_454 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_975 , V_985 ) ;
F_23 ( V_976 , 0 ) ;
F_23 ( V_984 , 0 ) ;
F_23 ( V_980 , 0 ) ;
F_426 ( V_986 , 0 ) ;
}
static void F_455 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_975 , V_987 |
V_985 |
V_988 |
V_989 |
V_990 ) ;
F_23 ( V_976 , 0 ) ;
}
static void F_456 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_991 = F_3 ( V_992 ) ;
V_991 |= V_993 | V_994 |
V_995 ;
F_23 ( V_992 , V_991 ) ;
}
static void F_457 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_975 , V_996 ) ;
}
static void F_458 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_984 , V_981 ) ;
}
static void F_459 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_997 , V_998 ) ;
}
static void F_460 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
F_23 ( V_997 , V_998 ) ;
F_23 ( V_999 , F_3 ( V_999 ) |
V_1000 ) ;
F_450 (pipe)
F_23 ( F_461 ( V_66 ) , V_1001 ) ;
}
static void F_462 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_1002 ) {
F_139 ( V_4 -> V_1002 ) ;
F_311 ( & V_4 -> V_1002 -> V_52 ) ;
V_4 -> V_1002 = NULL ;
}
if ( V_4 -> V_1003 ) {
F_139 ( V_4 -> V_1003 ) ;
F_311 ( & V_4 -> V_1003 -> V_52 ) ;
V_4 -> V_1003 = NULL ;
}
}
static void F_463 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_3 ( V_1004 ) ) {
F_23 ( V_1005 , F_3 ( V_1005 ) | V_1006 ) ;
F_24 ( ( ( F_3 ( V_1005 ) & V_1007 ) == V_1008 ) ,
50 ) ;
F_23 ( V_1004 , 0 ) ;
F_72 ( V_1004 ) ;
F_23 ( V_1005 , F_3 ( V_1005 ) & ~ V_1006 ) ;
F_72 ( V_1005 ) ;
}
F_462 ( V_2 ) ;
}
static int F_464 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_1002 == NULL )
V_4 -> V_1002 = F_419 ( V_2 ) ;
if ( ! V_4 -> V_1002 )
return - V_657 ;
if ( V_4 -> V_1003 == NULL )
V_4 -> V_1003 = F_419 ( V_2 ) ;
if ( ! V_4 -> V_1003 ) {
F_462 ( V_2 ) ;
return - V_657 ;
}
return 0 ;
}
void F_465 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_241 ;
if ( ! V_907 )
return;
F_119 ( & V_2 -> V_206 ) ;
V_241 = F_464 ( V_2 ) ;
if ( V_241 ) {
F_120 ( & V_2 -> V_206 ) ;
return;
}
V_241 = F_367 ( 6 ) ;
if ( V_241 ) {
F_462 ( V_2 ) ;
F_120 ( & V_2 -> V_206 ) ;
return;
}
F_368 ( V_1009 | V_1010 ) ;
F_368 ( V_1011 ) ;
F_368 ( V_4 -> V_1002 -> V_195 |
V_1012 |
V_1013 |
V_1014 |
V_1015 ) ;
F_368 ( V_1009 ) ;
F_368 ( V_752 ) ;
F_368 ( V_1016 ) ;
F_370 () ;
V_241 = F_466 ( F_168 ( V_4 ) ) ;
if ( V_241 ) {
F_83 ( L_173 ) ;
F_462 ( V_2 ) ;
F_120 ( & V_2 -> V_206 ) ;
return;
}
F_23 ( V_1004 , V_4 -> V_1003 -> V_195 | V_1017 ) ;
F_23 ( V_1005 , F_3 ( V_1005 ) & ~ V_1006 ) ;
F_120 ( & V_2 -> V_206 ) ;
}
void F_467 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_200 . V_1018 ( V_2 ) ;
if ( V_4 -> V_200 . V_1019 )
V_4 -> V_200 . V_1019 ( V_2 ) ;
}
static void F_468 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_8 ( V_2 ) ) {
V_4 -> V_200 . V_348 = F_197 ;
V_4 -> V_200 . V_620 = F_278 ;
V_4 -> V_200 . V_264 = F_143 ;
} else {
V_4 -> V_200 . V_348 = F_202 ;
V_4 -> V_200 . V_620 = F_264 ;
V_4 -> V_200 . V_264 = F_140 ;
}
if ( F_130 ( V_2 ) ) {
if ( F_8 ( V_2 ) ) {
V_4 -> V_200 . V_201 = F_114 ;
V_4 -> V_200 . V_208 = F_111 ;
V_4 -> V_200 . V_214 = F_113 ;
} else if ( F_453 ( V_2 ) ) {
V_4 -> V_200 . V_201 = F_107 ;
V_4 -> V_200 . V_208 = F_105 ;
V_4 -> V_200 . V_214 = F_106 ;
} else if ( F_135 ( V_2 ) ) {
V_4 -> V_200 . V_201 = F_104 ;
V_4 -> V_200 . V_208 = F_100 ;
V_4 -> V_200 . V_214 = F_99 ;
}
}
if ( F_247 ( V_2 ) || ( F_266 ( V_2 ) && ! F_469 ( V_2 ) ) )
V_4 -> V_200 . V_568 =
F_216 ;
else if ( F_470 ( V_2 ) )
V_4 -> V_200 . V_568 =
F_217 ;
else if ( F_103 ( V_2 ) || F_302 ( V_2 ) || F_469 ( V_2 ) )
V_4 -> V_200 . V_568 =
F_218 ;
else if ( F_131 ( V_2 ) )
V_4 -> V_200 . V_568 =
F_219 ;
else if ( F_303 ( V_2 ) )
V_4 -> V_200 . V_568 =
F_221 ;
else if ( F_471 ( V_2 ) )
V_4 -> V_200 . V_568 =
F_222 ;
else
V_4 -> V_200 . V_568 =
F_223 ;
if ( F_8 ( V_2 ) ) {
if ( F_82 ( V_2 ) )
V_4 -> V_200 . V_1019 = F_459 ;
else if ( F_56 ( V_2 ) )
V_4 -> V_200 . V_1019 = F_460 ;
if ( F_2 ( V_2 ) ) {
if ( F_3 ( V_1020 ) & V_1021 )
V_4 -> V_200 . V_509 = F_252 ;
else {
F_25 ( L_174
L_175 ) ;
V_4 -> V_200 . V_509 = NULL ;
}
V_4 -> V_200 . V_317 = F_156 ;
V_4 -> V_200 . V_1018 = F_447 ;
} else if ( F_112 ( V_2 ) ) {
if ( F_256 () ) {
V_4 -> V_200 . V_509 = F_255 ;
} else {
F_25 ( L_176
L_175 ) ;
V_4 -> V_200 . V_509 = NULL ;
}
V_4 -> V_200 . V_317 = F_160 ;
V_4 -> V_200 . V_1018 = F_449 ;
} else if ( F_152 ( V_2 ) ) {
V_4 -> V_200 . V_317 = F_161 ;
if ( F_256 () ) {
V_4 -> V_200 . V_509 = F_255 ;
} else {
F_25 ( L_176
L_175 ) ;
V_4 -> V_200 . V_509 = NULL ;
}
V_4 -> V_200 . V_1018 = F_451 ;
} else
V_4 -> V_200 . V_509 = NULL ;
} else if ( F_10 ( V_2 ) ) {
if ( ! F_228 ( F_237 ( V_2 ) ,
V_4 -> V_402 ,
V_4 -> V_407 ,
V_4 -> V_408 ) ) {
F_269 ( L_177
L_178
L_179 ,
( V_4 -> V_402 == 1 ) ? L_180 : L_181 ,
V_4 -> V_407 , V_4 -> V_408 ) ;
F_230 ( V_2 ) ;
V_4 -> V_200 . V_509 = NULL ;
} else
V_4 -> V_200 . V_509 = F_236 ;
V_4 -> V_200 . V_1018 = F_456 ;
} else if ( F_9 ( V_2 ) ) {
V_4 -> V_200 . V_509 = F_242 ;
V_4 -> V_200 . V_1018 = F_452 ;
} else if ( F_472 ( V_2 ) ) {
V_4 -> V_200 . V_509 = F_245 ;
if ( F_135 ( V_2 ) )
V_4 -> V_200 . V_1018 = F_454 ;
else if ( F_134 ( V_2 ) )
V_4 -> V_200 . V_1018 = F_455 ;
} else if ( F_391 ( V_2 ) ) {
V_4 -> V_200 . V_509 = F_246 ;
V_4 -> V_200 . V_472 = F_231 ;
V_4 -> V_200 . V_1018 = F_456 ;
} else if ( F_303 ( V_2 ) ) {
V_4 -> V_200 . V_509 = F_249 ;
V_4 -> V_200 . V_1018 = F_457 ;
V_4 -> V_200 . V_472 = F_234 ;
} else if ( F_471 ( V_2 ) ) {
V_4 -> V_200 . V_509 = F_246 ;
V_4 -> V_200 . V_472 = F_232 ;
V_4 -> V_200 . V_1018 = F_457 ;
} else {
V_4 -> V_200 . V_509 = F_249 ;
V_4 -> V_200 . V_1018 = F_458 ;
if ( F_302 ( V_2 ) )
V_4 -> V_200 . V_472 = F_233 ;
else
V_4 -> V_200 . V_472 = F_234 ;
}
V_4 -> V_200 . V_762 = F_378 ;
switch ( F_27 ( V_2 ) -> V_69 ) {
case 2 :
V_4 -> V_200 . V_762 = F_366 ;
break;
case 3 :
V_4 -> V_200 . V_762 = F_371 ;
break;
case 4 :
case 5 :
V_4 -> V_200 . V_762 = F_372 ;
break;
case 6 :
V_4 -> V_200 . V_762 = F_373 ;
break;
case 7 :
V_4 -> V_200 . V_762 = F_374 ;
break;
}
}
static void F_473 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_131 |= V_132 ;
F_262 ( L_182 ) ;
}
static void F_474 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_131 |= V_512 ;
}
static void F_475 ( struct V_1 * V_2 )
{
struct V_1022 * V_1023 = V_2 -> V_364 ;
int V_99 ;
for ( V_99 = 0 ; V_99 < F_229 ( V_1024 ) ; V_99 ++ ) {
struct V_1025 * V_1026 = & V_1024 [ V_99 ] ;
if ( V_1023 -> V_1027 == V_1026 -> V_1027 &&
( V_1023 -> V_1028 == V_1026 -> V_1028 ||
V_1026 -> V_1028 == V_1029 ) &&
( V_1023 -> V_1030 == V_1026 -> V_1030 ||
V_1026 -> V_1030 == V_1029 ) )
V_1026 -> V_1031 ( V_2 ) ;
}
}
static void F_476 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_7 V_1032 ;
T_1 V_1033 ;
if ( F_8 ( V_2 ) )
V_1033 = V_1034 ;
else
V_1033 = V_1035 ;
F_477 ( V_2 -> V_364 , V_1036 ) ;
F_478 ( 1 , V_1037 ) ;
V_1032 = F_479 ( V_1038 ) ;
F_478 ( V_1032 | 1 << 5 , V_1038 ) ;
F_480 ( V_2 -> V_364 , V_1036 ) ;
F_73 ( 300 ) ;
F_23 ( V_1033 , V_1039 ) ;
F_72 ( V_1033 ) ;
}
void F_481 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_99 ;
F_482 ( V_2 ) ;
V_2 -> V_49 . V_1040 = 0 ;
V_2 -> V_49 . V_1041 = 0 ;
V_2 -> V_49 . V_687 = ( void * ) & V_1042 ;
F_475 ( V_2 ) ;
F_468 ( V_2 ) ;
if ( F_11 ( V_2 ) ) {
V_2 -> V_49 . V_1043 = 2048 ;
V_2 -> V_49 . V_1044 = 2048 ;
} else if ( F_391 ( V_2 ) ) {
V_2 -> V_49 . V_1043 = 4096 ;
V_2 -> V_49 . V_1044 = 4096 ;
} else {
V_2 -> V_49 . V_1043 = 8192 ;
V_2 -> V_49 . V_1044 = 8192 ;
}
V_2 -> V_49 . V_1045 = V_2 -> V_1046 -> V_52 ;
F_25 ( L_183 ,
V_4 -> V_1047 , V_4 -> V_1047 > 1 ? L_184 : L_185 ) ;
for ( V_99 = 0 ; V_99 < V_4 -> V_1047 ; V_99 ++ ) {
F_388 ( V_2 , V_99 ) ;
}
F_476 ( V_2 ) ;
F_399 ( V_2 ) ;
F_467 ( V_2 ) ;
if ( F_448 ( V_2 ) ) {
F_428 ( V_2 ) ;
F_438 ( V_2 ) ;
}
if ( F_112 ( V_2 ) || F_483 ( V_2 ) ) {
F_439 ( V_4 ) ;
F_444 ( V_4 ) ;
}
F_380 ( & V_4 -> V_719 , F_342 ) ;
F_393 ( & V_4 -> V_715 , F_336 ,
( unsigned long ) V_2 ) ;
}
void F_484 ( struct V_1 * V_2 )
{
if ( F_448 ( V_2 ) )
F_465 ( V_2 ) ;
F_485 ( V_2 ) ;
}
void F_486 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
struct V_148 * V_148 ;
F_487 ( V_2 ) ;
F_119 ( & V_2 -> V_206 ) ;
F_488 () ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_9 -> V_143 )
continue;
V_148 = F_102 ( V_9 ) ;
F_145 ( V_9 ) ;
}
F_128 ( V_2 ) ;
if ( F_448 ( V_2 ) )
F_432 ( V_2 ) ;
if ( F_112 ( V_2 ) || F_483 ( V_2 ) )
F_434 ( V_2 ) ;
if ( F_448 ( V_2 ) )
F_463 ( V_2 ) ;
F_120 ( & V_2 -> V_206 ) ;
F_489 ( V_2 ) ;
F_348 ( & V_4 -> V_1048 ) ;
F_490 () ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
V_148 = F_102 ( V_9 ) ;
F_491 ( & V_148 -> V_715 ) ;
}
F_491 ( & V_4 -> V_715 ) ;
F_348 ( & V_4 -> V_719 ) ;
F_492 ( V_2 ) ;
}
struct V_356 * F_493 ( struct V_514 * V_515 )
{
return & F_494 ( V_515 ) -> V_52 ;
}
void F_495 ( struct V_1049 * V_515 ,
struct V_50 * V_51 )
{
V_515 -> V_51 = V_51 ;
F_496 ( & V_515 -> V_52 ,
& V_51 -> V_52 ) ;
}
int F_497 ( struct V_1 * V_2 , bool V_77 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_1050 ;
F_220 ( V_4 -> V_1051 , V_1052 , & V_1050 ) ;
if ( V_77 )
V_1050 &= ~ V_1053 ;
else
V_1050 |= V_1053 ;
F_498 ( V_4 -> V_1051 , V_1052 , V_1050 ) ;
return 0 ;
}
struct V_1054 *
F_499 ( struct V_1 * V_2 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_1054 * error ;
int V_99 ;
error = F_500 ( sizeof( * error ) , V_1055 ) ;
if ( error == NULL )
return NULL ;
for ( V_99 = 0 ; V_99 < 2 ; V_99 ++ ) {
error -> V_432 [ V_99 ] . V_1056 = F_3 ( F_299 ( V_99 ) ) ;
error -> V_432 [ V_99 ] . V_1057 = F_3 ( F_301 ( V_99 ) ) ;
error -> V_432 [ V_99 ] . V_52 = F_3 ( F_300 ( V_99 ) ) ;
error -> V_97 [ V_99 ] . V_1056 = F_3 ( F_49 ( V_99 ) ) ;
error -> V_97 [ V_99 ] . V_1058 = F_3 ( F_141 ( V_99 ) ) ;
error -> V_97 [ V_99 ] . V_223 = F_3 ( F_274 ( V_99 ) ) ;
error -> V_97 [ V_99 ] . V_642 = F_3 ( F_275 ( V_99 ) ) ;
error -> V_97 [ V_99 ] . V_654 = F_3 ( F_91 ( V_99 ) ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
error -> V_97 [ V_99 ] . V_1059 = F_3 ( F_92 ( V_99 ) ) ;
error -> V_97 [ V_99 ] . V_1060 = F_3 ( F_142 ( V_99 ) ) ;
}
error -> V_66 [ V_99 ] . V_1061 = F_3 ( F_28 ( V_99 ) ) ;
error -> V_66 [ V_99 ] . V_1062 = F_3 ( F_276 ( V_99 ) ) ;
error -> V_66 [ V_99 ] . V_436 = F_3 ( F_176 ( V_99 ) ) ;
error -> V_66 [ V_99 ] . V_1063 = F_3 ( F_178 ( V_99 ) ) ;
error -> V_66 [ V_99 ] . V_705 = F_3 ( F_180 ( V_99 ) ) ;
error -> V_66 [ V_99 ] . V_710 = F_3 ( F_182 ( V_99 ) ) ;
error -> V_66 [ V_99 ] . V_1064 = F_3 ( F_184 ( V_99 ) ) ;
error -> V_66 [ V_99 ] . V_707 = F_3 ( F_186 ( V_99 ) ) ;
}
return error ;
}
void
F_501 ( struct V_1065 * V_39 ,
struct V_1 * V_2 ,
struct V_1054 * error )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < 2 ; V_99 ++ ) {
F_502 ( V_39 , L_186 , V_99 ) ;
F_502 ( V_39 , L_187 , error -> V_66 [ V_99 ] . V_1061 ) ;
F_502 ( V_39 , L_188 , error -> V_66 [ V_99 ] . V_1062 ) ;
F_502 ( V_39 , L_189 , error -> V_66 [ V_99 ] . V_436 ) ;
F_502 ( V_39 , L_190 , error -> V_66 [ V_99 ] . V_1063 ) ;
F_502 ( V_39 , L_191 , error -> V_66 [ V_99 ] . V_705 ) ;
F_502 ( V_39 , L_192 , error -> V_66 [ V_99 ] . V_710 ) ;
F_502 ( V_39 , L_193 , error -> V_66 [ V_99 ] . V_1064 ) ;
F_502 ( V_39 , L_194 , error -> V_66 [ V_99 ] . V_707 ) ;
F_502 ( V_39 , L_195 , V_99 ) ;
F_502 ( V_39 , L_196 , error -> V_97 [ V_99 ] . V_1056 ) ;
F_502 ( V_39 , L_197 , error -> V_97 [ V_99 ] . V_1058 ) ;
F_502 ( V_39 , L_198 , error -> V_97 [ V_99 ] . V_223 ) ;
F_502 ( V_39 , L_199 , error -> V_97 [ V_99 ] . V_642 ) ;
F_502 ( V_39 , L_200 , error -> V_97 [ V_99 ] . V_654 ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
F_502 ( V_39 , L_201 , error -> V_97 [ V_99 ] . V_1059 ) ;
F_502 ( V_39 , L_202 , error -> V_97 [ V_99 ] . V_1060 ) ;
}
F_502 ( V_39 , L_203 , V_99 ) ;
F_502 ( V_39 , L_196 , error -> V_432 [ V_99 ] . V_1056 ) ;
F_502 ( V_39 , L_199 , error -> V_432 [ V_99 ] . V_1057 ) ;
F_502 ( V_39 , L_204 , error -> V_432 [ V_99 ] . V_52 ) ;
}
}
