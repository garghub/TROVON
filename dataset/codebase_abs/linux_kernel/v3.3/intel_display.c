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
void F_48 ( struct V_3 * V_4 ,
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
T_1 V_78 , V_135 = V_136 | V_137 ,
V_138 = V_136 ;
if ( V_66 > 1 )
return;
F_69 ( V_4 -> V_85 -> V_69 < 5 ) ;
F_54 ( V_4 , V_66 ) ;
if ( V_66 == 0 )
V_138 |= V_139 ;
else if ( V_66 == 1 )
V_138 |= V_137 ;
if ( ( F_3 ( V_82 ) & V_135 ) == V_138 )
return;
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
V_78 &= ~ V_140 ;
V_78 |= F_3 ( F_28 ( V_66 ) ) & V_140 ;
}
F_23 ( V_70 , V_78 | V_109 ) ;
if ( F_24 ( F_3 ( V_70 ) & V_141 , 100 ) )
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
if ( F_24 ( ( F_3 ( V_70 ) & V_141 ) == 0 , 50 ) )
F_83 ( L_31 , V_66 ) ;
}
static void F_87 ( struct V_3 * V_4 , enum V_66 V_66 ,
bool V_142 )
{
int V_70 ;
T_1 V_78 ;
if ( ! F_8 ( V_4 -> V_2 ) )
F_88 ( V_4 , V_66 ) ;
else {
if ( V_142 ) {
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
T_1 V_143 ;
V_143 = F_3 ( V_144 ) ;
if ( ( V_143 & V_145 ) == 0 )
return;
V_143 &= ~ V_145 ;
F_23 ( V_144 , V_143 ) ;
if ( F_24 ( ( F_3 ( V_146 ) & V_147 ) == 0 , 10 ) ) {
F_25 ( L_35 ) ;
return;
}
F_25 ( L_36 ) ;
}
static void F_100 ( struct V_8 * V_9 , unsigned long V_148 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_149 * V_150 = V_9 -> V_150 ;
struct V_151 * V_152 = F_101 ( V_150 ) ;
struct V_153 * V_154 = V_152 -> V_154 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_156 ;
int V_99 , V_101 ;
T_1 V_143 , V_157 ;
V_156 = V_4 -> V_158 / V_159 ;
if ( V_150 -> V_160 [ 0 ] < V_156 )
V_156 = V_150 -> V_160 [ 0 ] ;
V_156 = ( V_156 / 64 ) - 1 ;
V_99 = V_155 -> V_99 == 0 ? V_161 : V_162 ;
for ( V_101 = 0 ; V_101 < ( V_159 / 32 ) + 1 ; V_101 ++ )
F_23 ( V_163 + ( V_101 * 4 ) , 0 ) ;
V_157 = V_164 | V_165 | V_166 ;
V_157 |= V_99 ;
F_23 ( V_167 , V_157 ) ;
F_23 ( V_168 , V_9 -> V_169 ) ;
V_143 = V_145 | V_170 ;
if ( F_103 ( V_2 ) )
V_143 |= V_171 ;
V_143 |= ( V_156 & 0xff ) << V_172 ;
V_143 |= ( V_148 & 0x2fff ) << V_173 ;
V_143 |= V_154 -> V_174 ;
F_23 ( V_144 , V_143 ) ;
F_25 ( L_37 ,
V_156 , V_9 -> V_169 , V_155 -> V_99 ) ;
}
static bool F_104 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_144 ) & V_145 ;
}
static void F_105 ( struct V_8 * V_9 , unsigned long V_148 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_149 * V_150 = V_9 -> V_150 ;
struct V_151 * V_152 = F_101 ( V_150 ) ;
struct V_153 * V_154 = V_152 -> V_154 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_99 = V_155 -> V_99 == 0 ? V_175 : V_176 ;
unsigned long V_177 = 200 ;
T_1 V_178 ;
V_178 = V_99 | V_179 | V_180 ;
V_178 |= V_181 | V_154 -> V_174 ;
F_23 ( V_182 , V_183 ) ;
F_23 ( V_184 , V_185 |
( V_177 << V_186 ) |
( V_148 << V_187 ) ) ;
F_23 ( V_188 , V_9 -> V_169 ) ;
F_23 ( V_189 , F_3 ( V_189 ) | V_190 ) ;
F_25 ( L_38 , V_155 -> V_99 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_178 ;
V_178 = F_3 ( V_189 ) ;
if ( V_178 & V_190 ) {
V_178 &= ~ V_190 ;
F_23 ( V_189 , V_178 ) ;
F_25 ( L_36 ) ;
}
}
static bool F_107 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_189 ) & V_190 ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_191 ;
F_109 ( V_4 ) ;
V_191 = F_3 ( V_192 ) ;
V_191 |= V_193 <<
V_194 ;
F_23 ( V_192 , V_191 ) ;
V_191 |= V_193 ;
F_23 ( V_192 , V_191 ) ;
V_191 &= ~ ( V_193 <<
V_194 ) ;
F_23 ( V_192 , V_191 ) ;
F_72 ( V_192 ) ;
F_110 ( V_4 ) ;
}
static void F_111 ( struct V_8 * V_9 , unsigned long V_148 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_149 * V_150 = V_9 -> V_150 ;
struct V_151 * V_152 = F_101 ( V_150 ) ;
struct V_153 * V_154 = V_152 -> V_154 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_99 = V_155 -> V_99 == 0 ? V_175 : V_176 ;
unsigned long V_177 = 200 ;
T_1 V_178 ;
V_178 = F_3 ( V_195 ) ;
V_178 &= V_196 ;
V_178 |= ( V_99 | V_180 ) ;
V_178 |= V_197 ;
V_178 |= ( V_181 | V_154 -> V_174 ) ;
F_23 ( V_198 , V_183 ) ;
F_23 ( V_199 , V_185 |
( V_177 << V_186 ) |
( V_148 << V_187 ) ) ;
F_23 ( V_200 , V_9 -> V_169 ) ;
F_23 ( V_201 , V_154 -> V_202 | V_203 ) ;
F_23 ( V_195 , V_178 | V_190 ) ;
if ( F_112 ( V_2 ) ) {
F_23 ( V_204 ,
V_205 | V_154 -> V_174 ) ;
F_23 ( V_206 , V_9 -> V_169 ) ;
F_108 ( V_2 ) ;
}
F_25 ( L_38 , V_155 -> V_99 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_178 ;
V_178 = F_3 ( V_195 ) ;
if ( V_178 & V_190 ) {
V_178 &= ~ V_190 ;
F_23 ( V_195 , V_178 ) ;
F_25 ( L_36 ) ;
}
}
static bool F_114 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_195 ) & V_190 ;
}
bool F_115 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_207 . V_208 )
return false ;
return V_4 -> V_207 . V_208 ( V_2 ) ;
}
static void F_116 ( struct V_209 * V_210 )
{
struct V_211 * V_212 =
F_117 ( F_118 ( V_210 ) ,
struct V_211 , V_212 ) ;
struct V_1 * V_2 = V_212 -> V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_119 ( & V_2 -> V_213 ) ;
if ( V_212 == V_4 -> V_214 ) {
if ( V_212 -> V_9 -> V_150 == V_212 -> V_150 ) {
V_4 -> V_207 . V_215 ( V_212 -> V_9 ,
V_212 -> V_148 ) ;
V_4 -> V_216 = F_102 ( V_212 -> V_9 ) -> V_99 ;
V_4 -> V_217 = V_212 -> V_9 -> V_150 -> V_52 . V_218 ;
V_4 -> V_219 = V_212 -> V_9 -> V_169 ;
}
V_4 -> V_214 = NULL ;
}
F_120 ( & V_2 -> V_213 ) ;
F_121 ( V_212 ) ;
}
static void F_122 ( struct V_3 * V_4 )
{
if ( V_4 -> V_214 == NULL )
return;
F_25 ( L_39 ) ;
if ( F_123 ( & V_4 -> V_214 -> V_212 ) )
F_121 ( V_4 -> V_214 ) ;
V_4 -> V_214 = NULL ;
}
static void F_124 ( struct V_8 * V_9 , unsigned long V_148 )
{
struct V_211 * V_212 ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_207 . V_215 )
return;
F_122 ( V_4 ) ;
V_212 = F_125 ( sizeof *V_212 , V_220 ) ;
if ( V_212 == NULL ) {
V_4 -> V_207 . V_215 ( V_9 , V_148 ) ;
return;
}
V_212 -> V_9 = V_9 ;
V_212 -> V_150 = V_9 -> V_150 ;
V_212 -> V_148 = V_148 ;
F_126 ( & V_212 -> V_212 , F_116 ) ;
V_4 -> V_214 = V_212 ;
F_25 ( L_40 ) ;
F_127 ( & V_212 -> V_212 , F_30 ( 50 ) ) ;
}
void F_128 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_122 ( V_4 ) ;
if ( ! V_4 -> V_207 . V_221 )
return;
V_4 -> V_207 . V_221 ( V_2 ) ;
V_4 -> V_216 = - 1 ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = NULL , * V_222 ;
struct V_155 * V_155 ;
struct V_149 * V_150 ;
struct V_151 * V_152 ;
struct V_153 * V_154 ;
int V_215 ;
F_25 ( L_41 ) ;
if ( ! V_223 )
return;
if ( ! F_130 ( V_2 ) )
return;
F_14 (tmp_crtc, &dev->mode_config.crtc_list, head) {
if ( V_222 -> V_76 && V_222 -> V_150 ) {
if ( V_9 ) {
F_25 ( L_42 ) ;
V_4 -> V_224 = V_225 ;
goto V_226;
}
V_9 = V_222 ;
}
}
if ( ! V_9 || V_9 -> V_150 == NULL ) {
F_25 ( L_43 ) ;
V_4 -> V_224 = V_227 ;
goto V_226;
}
V_155 = F_102 ( V_9 ) ;
V_150 = V_9 -> V_150 ;
V_152 = F_101 ( V_150 ) ;
V_154 = V_152 -> V_154 ;
V_215 = V_228 ;
if ( V_215 < 0 ) {
F_25 ( L_44 ) ;
V_215 = 1 ;
if ( F_27 ( V_2 ) -> V_69 <= 6 )
V_215 = 0 ;
}
if ( ! V_215 ) {
F_25 ( L_45 ) ;
V_4 -> V_224 = V_229 ;
goto V_226;
}
if ( V_152 -> V_154 -> V_52 . V_230 > V_4 -> V_158 ) {
F_25 ( L_46
L_47 ) ;
V_4 -> V_224 = V_231 ;
goto V_226;
}
if ( ( V_9 -> V_232 . V_233 & V_234 ) ||
( V_9 -> V_232 . V_233 & V_235 ) ) {
F_25 ( L_48
L_49 ) ;
V_4 -> V_224 = V_236 ;
goto V_226;
}
if ( ( V_9 -> V_232 . V_237 > 2048 ) ||
( V_9 -> V_232 . V_238 > 1536 ) ) {
F_25 ( L_50 ) ;
V_4 -> V_224 = V_239 ;
goto V_226;
}
if ( ( F_131 ( V_2 ) || F_103 ( V_2 ) ) && V_155 -> V_99 != 0 ) {
F_25 ( L_51 ) ;
V_4 -> V_224 = V_240 ;
goto V_226;
}
if ( V_154 -> V_241 != V_242 ||
V_154 -> V_174 == V_243 ) {
F_25 ( L_52 ) ;
V_4 -> V_224 = V_244 ;
goto V_226;
}
if ( F_132 () )
goto V_226;
if ( V_4 -> V_216 == V_155 -> V_99 &&
V_4 -> V_217 == V_150 -> V_52 . V_218 &&
V_4 -> V_219 == V_9 -> V_169 )
return;
if ( F_115 ( V_2 ) ) {
F_25 ( L_53 ) ;
F_128 ( V_2 ) ;
}
F_124 ( V_9 , 500 ) ;
return;
V_226:
if ( F_115 ( V_2 ) ) {
F_25 ( L_54 ) ;
F_128 ( V_2 ) ;
}
}
int
F_133 ( struct V_1 * V_2 ,
struct V_153 * V_154 ,
struct V_245 * V_246 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_247 ;
int V_248 ;
switch ( V_154 -> V_241 ) {
case V_249 :
if ( F_134 ( V_2 ) || F_135 ( V_2 ) )
V_247 = 128 * 1024 ;
else if ( F_27 ( V_2 ) -> V_69 >= 4 )
V_247 = 4 * 1024 ;
else
V_247 = 64 * 1024 ;
break;
case V_242 :
V_247 = 0 ;
break;
case V_250 :
F_83 ( L_55 ) ;
return - V_251 ;
default:
F_136 () ;
}
V_4 -> V_252 . V_253 = false ;
V_248 = F_137 ( V_154 , V_247 , V_246 ) ;
if ( V_248 )
goto V_254;
if ( V_154 -> V_241 != V_249 ) {
V_248 = F_138 ( V_154 , V_246 ) ;
if ( V_248 )
goto V_255;
}
V_4 -> V_252 . V_253 = true ;
return 0 ;
V_255:
F_139 ( V_154 ) ;
V_254:
V_4 -> V_252 . V_253 = true ;
return V_248 ;
}
static int F_140 ( struct V_8 * V_9 , struct V_149 * V_150 ,
int V_256 , int V_169 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
struct V_151 * V_152 ;
struct V_153 * V_154 ;
int V_99 = V_155 -> V_99 ;
unsigned long V_257 , V_258 ;
T_1 V_259 ;
T_1 V_70 ;
switch ( V_99 ) {
case 0 :
case 1 :
break;
default:
F_83 ( L_56 , V_99 ) ;
return - V_251 ;
}
V_152 = F_101 ( V_150 ) ;
V_154 = V_152 -> V_154 ;
V_70 = F_50 ( V_99 ) ;
V_259 = F_3 ( V_70 ) ;
V_259 &= ~ V_260 ;
switch ( V_150 -> V_261 ) {
case 8 :
V_259 |= V_262 ;
break;
case 16 :
if ( V_150 -> V_263 == 15 )
V_259 |= V_264 ;
else
V_259 |= V_265 ;
break;
case 24 :
case 32 :
V_259 |= V_266 ;
break;
default:
F_83 ( L_57 , V_150 -> V_261 ) ;
return - V_251 ;
}
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
if ( V_154 -> V_241 != V_249 )
V_259 |= V_267 ;
else
V_259 &= ~ V_267 ;
}
F_23 ( V_70 , V_259 ) ;
V_257 = V_154 -> V_202 ;
V_258 = V_169 * V_150 -> V_160 [ 0 ] + V_256 * ( V_150 -> V_261 / 8 ) ;
F_25 ( L_58 ,
V_257 , V_258 , V_256 , V_169 , V_150 -> V_160 [ 0 ] ) ;
F_23 ( F_141 ( V_99 ) , V_150 -> V_160 [ 0 ] ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
F_23 ( F_92 ( V_99 ) , V_257 ) ;
F_23 ( F_142 ( V_99 ) , ( V_169 << 16 ) | V_256 ) ;
F_23 ( F_91 ( V_99 ) , V_258 ) ;
} else
F_23 ( F_91 ( V_99 ) , V_257 + V_258 ) ;
F_72 ( V_70 ) ;
return 0 ;
}
static int F_143 ( struct V_8 * V_9 ,
struct V_149 * V_150 , int V_256 , int V_169 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
struct V_151 * V_152 ;
struct V_153 * V_154 ;
int V_99 = V_155 -> V_99 ;
unsigned long V_257 , V_258 ;
T_1 V_259 ;
T_1 V_70 ;
switch ( V_99 ) {
case 0 :
case 1 :
case 2 :
break;
default:
F_83 ( L_56 , V_99 ) ;
return - V_251 ;
}
V_152 = F_101 ( V_150 ) ;
V_154 = V_152 -> V_154 ;
V_70 = F_50 ( V_99 ) ;
V_259 = F_3 ( V_70 ) ;
V_259 &= ~ V_260 ;
switch ( V_150 -> V_261 ) {
case 8 :
V_259 |= V_262 ;
break;
case 16 :
if ( V_150 -> V_263 != 16 )
return - V_251 ;
V_259 |= V_265 ;
break;
case 24 :
case 32 :
if ( V_150 -> V_263 == 24 )
V_259 |= V_266 ;
else if ( V_150 -> V_263 == 30 )
V_259 |= V_268 ;
else
return - V_251 ;
break;
default:
F_83 ( L_57 , V_150 -> V_261 ) ;
return - V_251 ;
}
if ( V_154 -> V_241 != V_249 )
V_259 |= V_267 ;
else
V_259 &= ~ V_267 ;
V_259 |= V_269 ;
F_23 ( V_70 , V_259 ) ;
V_257 = V_154 -> V_202 ;
V_258 = V_169 * V_150 -> V_160 [ 0 ] + V_256 * ( V_150 -> V_261 / 8 ) ;
F_25 ( L_58 ,
V_257 , V_258 , V_256 , V_169 , V_150 -> V_160 [ 0 ] ) ;
F_23 ( F_141 ( V_99 ) , V_150 -> V_160 [ 0 ] ) ;
F_23 ( F_92 ( V_99 ) , V_257 ) ;
F_23 ( F_142 ( V_99 ) , ( V_169 << 16 ) | V_256 ) ;
F_23 ( F_91 ( V_99 ) , V_258 ) ;
F_72 ( V_70 ) ;
return 0 ;
}
static int
F_144 ( struct V_8 * V_9 , struct V_149 * V_150 ,
int V_256 , int V_169 , enum V_270 V_77 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_248 ;
V_248 = V_4 -> V_207 . V_271 ( V_9 , V_150 , V_256 , V_169 ) ;
if ( V_248 )
return V_248 ;
F_129 ( V_2 ) ;
F_145 ( V_9 ) ;
return 0 ;
}
static int
F_146 ( struct V_8 * V_9 , int V_256 , int V_169 ,
struct V_149 * V_272 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_273 * V_274 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_248 ;
if ( ! V_9 -> V_150 ) {
F_83 ( L_59 ) ;
return 0 ;
}
switch ( V_155 -> V_99 ) {
case 0 :
case 1 :
break;
case 2 :
if ( F_147 ( V_2 ) )
break;
default:
F_83 ( L_60 ) ;
return - V_251 ;
}
F_119 ( & V_2 -> V_213 ) ;
V_248 = F_133 ( V_2 ,
F_101 ( V_9 -> V_150 ) -> V_154 ,
NULL ) ;
if ( V_248 != 0 ) {
F_120 ( & V_2 -> V_213 ) ;
F_83 ( L_61 ) ;
return V_248 ;
}
if ( V_272 ) {
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_153 * V_154 = F_101 ( V_272 ) -> V_154 ;
F_148 ( V_4 -> V_275 ,
F_149 ( & V_4 -> V_252 . V_276 ) ||
F_149 ( & V_154 -> V_277 ) == 0 ) ;
V_248 = F_150 ( V_154 ) ;
( void ) V_248 ;
}
V_248 = F_144 ( V_9 , V_9 -> V_150 , V_256 , V_169 ,
V_278 ) ;
if ( V_248 ) {
F_139 ( F_101 ( V_9 -> V_150 ) -> V_154 ) ;
F_120 ( & V_2 -> V_213 ) ;
F_83 ( L_62 ) ;
return V_248 ;
}
if ( V_272 ) {
F_21 ( V_2 , V_155 -> V_66 ) ;
F_139 ( F_101 ( V_272 ) -> V_154 ) ;
}
F_120 ( & V_2 -> V_213 ) ;
if ( ! V_2 -> V_279 -> V_280 )
return 0 ;
V_274 = V_2 -> V_279 -> V_280 -> V_281 ;
if ( ! V_274 -> V_282 )
return 0 ;
if ( V_155 -> V_66 ) {
V_274 -> V_282 -> V_283 = V_256 ;
V_274 -> V_282 -> V_284 = V_169 ;
} else {
V_274 -> V_282 -> V_285 = V_256 ;
V_274 -> V_282 -> V_286 = V_169 ;
}
return 0 ;
}
static void F_151 ( struct V_8 * V_9 , int clock )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_287 ;
F_25 ( L_63 , clock ) ;
V_287 = F_3 ( V_288 ) ;
V_287 &= ~ V_289 ;
if ( clock < 200000 ) {
T_1 V_290 ;
V_287 |= V_291 ;
V_290 = F_3 ( 0x4600c ) ;
V_290 &= 0xffff0000 ;
F_23 ( 0x4600c , V_290 | 0x8124 ) ;
V_290 = F_3 ( 0x46010 ) ;
F_23 ( 0x46010 , V_290 | 1 ) ;
V_290 = F_3 ( 0x46034 ) ;
F_23 ( 0x46034 , V_290 | ( 1 << 24 ) ) ;
} else {
V_287 |= V_292 ;
}
F_23 ( V_288 , V_287 ) ;
F_72 ( V_288 ) ;
F_73 ( 500 ) ;
}
static void F_152 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
T_1 V_70 , V_290 ;
V_70 = F_41 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
if ( F_147 ( V_2 ) ) {
V_290 &= ~ V_293 ;
V_290 |= V_293 | V_294 ;
} else {
V_290 &= ~ V_295 ;
V_290 |= V_295 | V_294 ;
}
F_23 ( V_70 , V_290 ) ;
V_70 = F_43 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
if ( F_38 ( V_2 ) ) {
V_290 &= ~ V_296 ;
V_290 |= V_297 ;
} else {
V_290 &= ~ V_295 ;
V_290 |= V_295 ;
}
F_23 ( V_70 , V_290 | V_298 ) ;
F_72 ( V_70 ) ;
F_73 ( 1000 ) ;
if ( F_147 ( V_2 ) )
F_23 ( V_70 , F_3 ( V_70 ) | V_299 |
V_300 ) ;
}
static void F_153 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_233 = F_3 ( V_301 ) ;
V_233 |= F_154 ( V_66 ) ;
F_23 ( V_301 , V_233 ) ;
V_233 |= F_155 ( V_66 ) ;
F_23 ( V_301 , V_233 ) ;
F_72 ( V_301 ) ;
}
static void F_156 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
int V_99 = V_155 -> V_99 ;
T_1 V_70 , V_290 , V_302 ;
F_94 ( V_4 , V_66 ) ;
F_49 ( V_4 , V_99 ) ;
V_70 = F_157 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ V_303 ;
V_290 &= ~ V_304 ;
F_23 ( V_70 , V_290 ) ;
F_3 ( V_70 ) ;
F_73 ( 150 ) ;
V_70 = F_41 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ ( 7 << 19 ) ;
V_290 |= ( V_155 -> V_305 - 1 ) << 19 ;
V_290 &= ~ V_295 ;
V_290 |= V_306 ;
F_23 ( V_70 , V_290 | V_83 ) ;
V_70 = F_43 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ V_295 ;
V_290 |= V_306 ;
F_23 ( V_70 , V_290 | V_84 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
if ( F_82 ( V_2 ) ) {
F_23 ( F_158 ( V_66 ) , V_307 ) ;
F_23 ( F_158 ( V_66 ) , V_307 |
V_308 ) ;
}
V_70 = F_159 ( V_66 ) ;
for ( V_302 = 0 ; V_302 < 5 ; V_302 ++ ) {
V_290 = F_3 ( V_70 ) ;
F_25 ( L_64 , V_290 ) ;
if ( ( V_290 & V_304 ) ) {
F_25 ( L_65 ) ;
F_23 ( V_70 , V_290 | V_304 ) ;
break;
}
}
if ( V_302 == 5 )
F_83 ( L_66 ) ;
V_70 = F_41 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ V_295 ;
V_290 |= V_309 ;
F_23 ( V_70 , V_290 ) ;
V_70 = F_43 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ V_295 ;
V_290 |= V_309 ;
F_23 ( V_70 , V_290 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
V_70 = F_159 ( V_66 ) ;
for ( V_302 = 0 ; V_302 < 5 ; V_302 ++ ) {
V_290 = F_3 ( V_70 ) ;
F_25 ( L_64 , V_290 ) ;
if ( V_290 & V_303 ) {
F_23 ( V_70 , V_290 | V_303 ) ;
F_25 ( L_67 ) ;
break;
}
}
if ( V_302 == 5 )
F_83 ( L_68 ) ;
F_25 ( L_69 ) ;
}
static void F_160 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
T_1 V_70 , V_290 , V_101 ;
V_70 = F_157 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ V_303 ;
V_290 &= ~ V_304 ;
F_23 ( V_70 , V_290 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
V_70 = F_41 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ ( 7 << 19 ) ;
V_290 |= ( V_155 -> V_305 - 1 ) << 19 ;
V_290 &= ~ V_295 ;
V_290 |= V_306 ;
V_290 &= ~ V_310 ;
V_290 |= V_311 ;
F_23 ( V_70 , V_290 | V_83 ) ;
V_70 = F_43 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
if ( F_38 ( V_2 ) ) {
V_290 &= ~ V_296 ;
V_290 |= V_312 ;
} else {
V_290 &= ~ V_295 ;
V_290 |= V_306 ;
}
F_23 ( V_70 , V_290 | V_84 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
if ( F_38 ( V_2 ) )
F_153 ( V_2 , V_66 ) ;
for ( V_101 = 0 ; V_101 < 4 ; V_101 ++ ) {
V_70 = F_41 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ V_310 ;
V_290 |= V_313 [ V_101 ] ;
F_23 ( V_70 , V_290 ) ;
F_72 ( V_70 ) ;
F_73 ( 500 ) ;
V_70 = F_159 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
F_25 ( L_64 , V_290 ) ;
if ( V_290 & V_304 ) {
F_23 ( V_70 , V_290 | V_304 ) ;
F_25 ( L_65 ) ;
break;
}
}
if ( V_101 == 4 )
F_83 ( L_66 ) ;
V_70 = F_41 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ V_295 ;
V_290 |= V_309 ;
if ( F_112 ( V_2 ) ) {
V_290 &= ~ V_310 ;
V_290 |= V_311 ;
}
F_23 ( V_70 , V_290 ) ;
V_70 = F_43 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
if ( F_38 ( V_2 ) ) {
V_290 &= ~ V_296 ;
V_290 |= V_314 ;
} else {
V_290 &= ~ V_295 ;
V_290 |= V_309 ;
}
F_23 ( V_70 , V_290 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
for ( V_101 = 0 ; V_101 < 4 ; V_101 ++ ) {
V_70 = F_41 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ V_310 ;
V_290 |= V_313 [ V_101 ] ;
F_23 ( V_70 , V_290 ) ;
F_72 ( V_70 ) ;
F_73 ( 500 ) ;
V_70 = F_159 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
F_25 ( L_64 , V_290 ) ;
if ( V_290 & V_303 ) {
F_23 ( V_70 , V_290 | V_303 ) ;
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
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
T_1 V_70 , V_290 , V_101 ;
V_70 = F_157 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ V_303 ;
V_290 &= ~ V_304 ;
F_23 ( V_70 , V_290 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
V_70 = F_41 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ ( 7 << 19 ) ;
V_290 |= ( V_155 -> V_305 - 1 ) << 19 ;
V_290 &= ~ ( V_315 | V_293 ) ;
V_290 |= V_316 ;
V_290 &= ~ V_310 ;
V_290 |= V_311 ;
V_290 |= V_317 ;
F_23 ( V_70 , V_290 | V_83 ) ;
V_70 = F_43 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ V_315 ;
V_290 &= ~ V_296 ;
V_290 |= V_312 ;
V_290 |= V_317 ;
F_23 ( V_70 , V_290 | V_84 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
if ( F_38 ( V_2 ) )
F_153 ( V_2 , V_66 ) ;
for ( V_101 = 0 ; V_101 < 4 ; V_101 ++ ) {
V_70 = F_41 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ V_310 ;
V_290 |= V_313 [ V_101 ] ;
F_23 ( V_70 , V_290 ) ;
F_72 ( V_70 ) ;
F_73 ( 500 ) ;
V_70 = F_159 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
F_25 ( L_64 , V_290 ) ;
if ( V_290 & V_304 ||
( F_3 ( V_70 ) & V_304 ) ) {
F_23 ( V_70 , V_290 | V_304 ) ;
F_25 ( L_65 ) ;
break;
}
}
if ( V_101 == 4 )
F_83 ( L_66 ) ;
V_70 = F_41 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ V_293 ;
V_290 |= V_318 ;
V_290 &= ~ V_310 ;
V_290 |= V_311 ;
F_23 ( V_70 , V_290 ) ;
V_70 = F_43 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ V_296 ;
V_290 |= V_314 ;
F_23 ( V_70 , V_290 ) ;
F_72 ( V_70 ) ;
F_73 ( 150 ) ;
for ( V_101 = 0 ; V_101 < 4 ; V_101 ++ ) {
V_70 = F_41 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ V_310 ;
V_290 |= V_313 [ V_101 ] ;
F_23 ( V_70 , V_290 ) ;
F_72 ( V_70 ) ;
F_73 ( 500 ) ;
V_70 = F_159 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
F_25 ( L_64 , V_290 ) ;
if ( V_290 & V_303 ) {
F_23 ( V_70 , V_290 | V_303 ) ;
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
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
T_1 V_70 , V_290 ;
F_23 ( F_163 ( V_66 ) ,
F_3 ( F_164 ( V_66 ) ) & V_319 ) ;
V_70 = F_43 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ ( ( 0x7 << 19 ) | ( 0x7 << 16 ) ) ;
V_290 |= ( V_155 -> V_305 - 1 ) << 19 ;
V_290 |= ( F_3 ( F_28 ( V_66 ) ) & V_140 ) << 11 ;
F_23 ( V_70 , V_290 | V_87 ) ;
F_72 ( V_70 ) ;
F_73 ( 200 ) ;
V_290 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_290 | V_320 ) ;
F_72 ( V_70 ) ;
F_73 ( 200 ) ;
V_70 = F_41 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
if ( ( V_290 & V_86 ) == 0 ) {
F_23 ( V_70 , V_290 | V_86 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
}
}
static void F_165 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_233 = F_3 ( V_301 ) ;
V_233 &= ~ ( F_155 ( V_66 ) ) ;
F_23 ( V_301 , V_233 ) ;
V_233 &= ~ ( F_154 ( V_66 ) ) ;
F_23 ( V_301 , V_233 ) ;
F_72 ( V_301 ) ;
}
static void F_166 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
T_1 V_70 , V_290 ;
V_70 = F_41 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_290 & ~ V_83 ) ;
F_72 ( V_70 ) ;
V_70 = F_43 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ ( 0x7 << 16 ) ;
V_290 |= ( F_3 ( F_28 ( V_66 ) ) & V_140 ) << 11 ;
F_23 ( V_70 , V_290 & ~ V_84 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
if ( F_82 ( V_2 ) ) {
F_23 ( F_158 ( V_66 ) , V_307 ) ;
F_23 ( F_158 ( V_66 ) ,
F_3 ( F_158 ( V_66 ) &
~ V_308 ) ) ;
} else if ( F_38 ( V_2 ) ) {
F_165 ( V_2 , V_66 ) ;
}
V_70 = F_41 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ V_295 ;
V_290 |= V_306 ;
F_23 ( V_70 , V_290 ) ;
V_70 = F_43 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
if ( F_38 ( V_2 ) ) {
V_290 &= ~ V_296 ;
V_290 |= V_312 ;
} else {
V_290 &= ~ V_295 ;
V_290 |= V_306 ;
}
V_290 &= ~ ( 0x07 << 16 ) ;
V_290 |= ( F_3 ( F_28 ( V_66 ) ) & V_140 ) << 11 ;
F_23 ( V_70 , V_290 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_245 * V_321 ;
T_1 V_322 ;
if ( F_11 ( V_2 ) )
return;
V_321 = F_168 ( V_4 ) ;
V_322 = F_169 ( V_321 ) ;
if ( V_322 & V_323 )
F_170 ( V_321 , V_322 ) ;
}
static void F_171 ( struct V_8 * V_9 )
{
struct V_153 * V_154 ;
struct V_3 * V_4 ;
if ( V_9 -> V_150 == NULL )
return;
V_154 = F_101 ( V_9 -> V_150 ) -> V_154 ;
V_4 = V_9 -> V_2 -> V_5 ;
F_148 ( V_4 -> V_275 ,
F_149 ( & V_154 -> V_277 ) == 0 ) ;
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
case V_324 :
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
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
T_1 V_70 , V_290 , V_325 ;
V_4 -> V_207 . V_326 ( V_9 ) ;
F_76 ( V_4 , V_66 ) ;
if ( F_38 ( V_2 ) ) {
V_325 = V_155 -> V_327 ? V_139 :
V_137 ;
V_290 = F_3 ( V_82 ) ;
if ( V_66 == 0 ) {
V_290 &= ~ ( V_328 ) ;
V_290 |= ( V_329 | V_330 ) ;
} else if ( V_66 == 1 ) {
V_290 &= ~ ( V_331 ) ;
V_290 |= ( V_332 | V_331 ) ;
} else if ( V_66 == 2 ) {
V_290 &= ~ ( V_137 ) ;
V_290 |= ( V_136 | V_325 ) ;
}
F_23 ( V_82 , V_290 ) ;
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
F_5 ( V_9 , V_324 ) ) ) {
T_1 V_333 = ( F_3 ( F_28 ( V_66 ) ) & V_140 ) >> 5 ;
V_70 = F_57 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ ( V_114 |
V_334 |
V_335 ) ;
V_290 |= ( V_336 |
V_337 ) ;
V_290 |= V_333 << 9 ;
if ( V_9 -> V_232 . V_233 & V_338 )
V_290 |= V_339 ;
if ( V_9 -> V_232 . V_233 & V_340 )
V_290 |= V_341 ;
switch ( F_187 ( V_9 ) ) {
case V_123 :
V_290 |= V_124 ;
break;
case V_125 :
V_290 |= V_126 ;
break;
case V_127 :
V_290 |= V_128 ;
break;
default:
F_25 ( L_71 ) ;
V_290 |= V_124 ;
break;
}
F_23 ( V_70 , V_290 ) ;
}
F_78 ( V_4 , V_66 ) ;
}
void F_188 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_342 = F_29 ( V_66 ) , V_343 = F_189 ( V_66 ) ;
T_1 V_290 ;
V_290 = F_3 ( V_342 ) ;
F_73 ( 500 ) ;
if ( F_24 ( F_3 ( V_342 ) != V_290 , 5 ) ) {
F_23 ( V_343 , V_344 ) ;
F_73 ( 250 ) ;
F_23 ( V_343 , 0 ) ;
if ( F_24 ( F_3 ( V_342 ) != V_290 , 5 ) )
F_83 ( L_72 , V_66 ) ;
}
}
static void F_190 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
int V_99 = V_155 -> V_99 ;
T_1 V_290 ;
bool V_345 ;
if ( V_155 -> V_346 )
return;
V_155 -> V_346 = true ;
F_191 ( V_2 ) ;
if ( F_5 ( V_9 , V_12 ) ) {
V_290 = F_3 ( V_13 ) ;
if ( ( V_290 & V_119 ) == 0 )
F_23 ( V_13 , V_290 | V_119 ) ;
}
V_345 = F_172 ( V_9 ) ;
if ( V_345 )
F_162 ( V_9 ) ;
else
F_166 ( V_9 ) ;
if ( V_4 -> V_347 &&
( F_5 ( V_9 , V_12 ) || V_21 ) ) {
F_23 ( F_192 ( V_66 ) , V_348 | V_349 ) ;
F_23 ( F_193 ( V_66 ) , V_4 -> V_350 ) ;
F_23 ( F_194 ( V_66 ) , V_4 -> V_347 ) ;
}
F_195 ( V_9 ) ;
F_87 ( V_4 , V_66 , V_345 ) ;
F_93 ( V_4 , V_99 , V_66 ) ;
if ( V_345 )
F_174 ( V_9 ) ;
F_119 ( & V_2 -> V_213 ) ;
F_129 ( V_2 ) ;
F_120 ( & V_2 -> V_213 ) ;
F_196 ( V_9 , true ) ;
}
static void F_197 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
int V_99 = V_155 -> V_99 ;
T_1 V_70 , V_290 ;
if ( ! V_155 -> V_346 )
return;
F_171 ( V_9 ) ;
F_198 ( V_2 , V_66 ) ;
F_196 ( V_9 , false ) ;
F_95 ( V_4 , V_99 , V_66 ) ;
if ( V_4 -> V_216 == V_99 )
F_128 ( V_2 ) ;
F_89 ( V_4 , V_66 ) ;
F_23 ( F_192 ( V_66 ) , 0 ) ;
F_23 ( F_194 ( V_66 ) , 0 ) ;
F_166 ( V_9 ) ;
F_98 ( V_4 , V_66 ) ;
F_84 ( V_4 , V_66 ) ;
if ( F_38 ( V_2 ) ) {
V_70 = F_57 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
V_290 &= ~ ( V_336 | V_114 ) ;
V_290 |= V_351 ;
F_23 ( V_70 , V_290 ) ;
V_290 = F_3 ( V_82 ) ;
switch ( V_66 ) {
case 0 :
V_290 &= ~ ( V_329 | V_328 ) ;
break;
case 1 :
V_290 &= ~ ( V_332 | V_331 ) ;
break;
case 2 :
V_290 &= ~ ( V_136 | V_137 ) ;
break;
default:
F_136 () ;
}
F_23 ( V_82 , V_290 ) ;
}
if ( ! V_155 -> V_352 )
F_77 ( V_4 , V_66 ) ;
V_70 = F_43 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_290 & ~ V_320 ) ;
V_70 = F_41 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_290 & ~ V_86 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
V_70 = F_43 ( V_66 ) ;
V_290 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_290 & ~ V_87 ) ;
F_72 ( V_70 ) ;
F_73 ( 100 ) ;
V_155 -> V_346 = false ;
F_191 ( V_2 ) ;
F_119 ( & V_2 -> V_213 ) ;
F_129 ( V_2 ) ;
F_167 ( V_2 ) ;
F_120 ( & V_2 -> V_213 ) ;
}
static void F_199 ( struct V_8 * V_9 , int V_232 )
{
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
int V_99 = V_155 -> V_99 ;
switch ( V_232 ) {
case V_353 :
case V_354 :
case V_355 :
F_25 ( L_73 , V_66 , V_99 ) ;
F_190 ( V_9 ) ;
break;
case V_356 :
F_25 ( L_74 , V_66 , V_99 ) ;
F_197 ( V_9 ) ;
break;
}
}
static void F_200 ( struct V_155 * V_155 , bool V_357 )
{
if ( ! V_357 && V_155 -> V_358 ) {
struct V_1 * V_2 = V_155 -> V_52 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_119 ( & V_2 -> V_213 ) ;
V_4 -> V_252 . V_253 = false ;
( void ) F_201 ( V_155 -> V_358 ) ;
V_4 -> V_252 . V_253 = true ;
F_120 ( & V_2 -> V_213 ) ;
}
}
static void F_202 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
int V_99 = V_155 -> V_99 ;
if ( V_155 -> V_346 )
return;
V_155 -> V_346 = true ;
F_191 ( V_2 ) ;
F_68 ( V_4 , V_66 ) ;
F_87 ( V_4 , V_66 , false ) ;
F_93 ( V_4 , V_99 , V_66 ) ;
F_195 ( V_9 ) ;
F_129 ( V_2 ) ;
F_200 ( V_155 , true ) ;
F_196 ( V_9 , true ) ;
}
static void F_203 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
int V_99 = V_155 -> V_99 ;
if ( ! V_155 -> V_346 )
return;
F_171 ( V_9 ) ;
F_198 ( V_2 , V_66 ) ;
F_200 ( V_155 , false ) ;
F_196 ( V_9 , false ) ;
if ( V_4 -> V_216 == V_99 )
F_128 ( V_2 ) ;
F_95 ( V_4 , V_99 , V_66 ) ;
F_89 ( V_4 , V_66 ) ;
F_74 ( V_4 , V_66 ) ;
V_155 -> V_346 = false ;
F_129 ( V_2 ) ;
F_191 ( V_2 ) ;
F_167 ( V_2 ) ;
}
static void F_204 ( struct V_8 * V_9 , int V_232 )
{
switch ( V_232 ) {
case V_353 :
case V_354 :
case V_355 :
F_202 ( V_9 ) ;
break;
case V_356 :
F_203 ( V_9 ) ;
break;
}
}
static void F_205 ( struct V_8 * V_9 , int V_232 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_273 * V_274 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
bool V_76 ;
if ( V_155 -> V_359 == V_232 )
return;
V_155 -> V_359 = V_232 ;
V_4 -> V_207 . V_360 ( V_9 , V_232 ) ;
if ( ! V_2 -> V_279 -> V_280 )
return;
V_274 = V_2 -> V_279 -> V_280 -> V_281 ;
if ( ! V_274 -> V_282 )
return;
V_76 = V_9 -> V_76 && V_232 != V_356 ;
switch ( V_66 ) {
case 0 :
V_274 -> V_282 -> V_361 = V_76 ? V_9 -> V_232 . V_237 : 0 ;
V_274 -> V_282 -> V_362 = V_76 ? V_9 -> V_232 . V_238 : 0 ;
break;
case 1 :
V_274 -> V_282 -> V_363 = V_76 ? V_9 -> V_232 . V_237 : 0 ;
V_274 -> V_282 -> V_364 = V_76 ? V_9 -> V_232 . V_238 : 0 ;
break;
default:
F_83 ( L_75 , F_47 ( V_66 ) ) ;
break;
}
}
static void F_206 ( struct V_8 * V_9 )
{
struct V_365 * V_366 = V_9 -> V_367 ;
struct V_1 * V_2 = V_9 -> V_2 ;
V_366 -> V_360 ( V_9 , V_356 ) ;
if ( V_9 -> V_150 ) {
F_119 ( & V_2 -> V_213 ) ;
F_139 ( F_101 ( V_9 -> V_150 ) -> V_154 ) ;
F_120 ( & V_2 -> V_213 ) ;
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
void F_211 ( struct V_368 * V_51 )
{
struct V_369 * V_370 = V_51 -> V_367 ;
V_370 -> V_360 ( V_51 , V_356 ) ;
}
void F_212 ( struct V_368 * V_51 )
{
struct V_369 * V_370 = V_51 -> V_367 ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_50 * V_50 = F_213 ( V_51 ) ;
struct V_155 * V_155 = F_102 ( V_50 -> V_52 . V_9 ) ;
V_370 -> V_360 ( V_51 , V_353 ) ;
if ( F_38 ( V_2 ) )
F_188 ( V_2 , V_155 -> V_66 ) ;
}
void F_214 ( struct V_368 * V_51 )
{
struct V_50 * V_50 = F_213 ( V_51 ) ;
F_215 ( V_51 ) ;
F_121 ( V_50 ) ;
}
static bool F_216 ( struct V_8 * V_9 ,
struct V_371 * V_232 ,
struct V_371 * V_372 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
if ( F_8 ( V_2 ) ) {
if ( V_232 -> clock * 3 > V_373 * 4 )
return false ;
}
if ( V_372 -> V_374 == 0 )
F_217 ( V_372 , 0 ) ;
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
T_4 V_375 = 0 ;
F_222 ( V_2 -> V_376 , V_377 , & V_375 ) ;
if ( V_375 & V_378 )
return 133000 ;
else {
switch ( V_375 & V_379 ) {
case V_380 :
return 333000 ;
default:
case V_381 :
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
T_4 V_382 = 0 ;
switch ( V_382 & V_383 ) {
case V_384 :
case V_385 :
return 200000 ;
case V_386 :
return 250000 ;
case V_387 :
return 133000 ;
}
return 0 ;
}
static int F_225 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_226 ( T_1 * V_388 , T_1 * V_389 )
{
while ( * V_388 > 0xffffff || * V_389 > 0xffffff ) {
* V_388 >>= 1 ;
* V_389 >>= 1 ;
}
}
static void
F_227 ( int V_261 , int V_390 , int V_391 ,
int V_392 , struct V_393 * V_394 )
{
V_394 -> V_395 = 64 ;
V_394 -> V_396 = V_261 * V_391 ;
V_394 -> V_397 = V_392 * V_390 * 8 ;
F_226 ( & V_394 -> V_396 , & V_394 -> V_397 ) ;
V_394 -> V_398 = V_391 ;
V_394 -> V_399 = V_392 ;
F_226 ( & V_394 -> V_398 , & V_394 -> V_399 ) ;
}
static unsigned long F_228 ( unsigned long V_400 ,
const struct V_401 * V_402 ,
int V_403 ,
int V_404 ,
unsigned long V_405 )
{
long V_406 , V_407 ;
V_406 = ( ( V_400 / 1000 ) * V_404 * V_405 ) /
1000 ;
V_406 = F_229 ( V_406 , V_402 -> V_408 ) ;
F_25 ( L_76 , V_406 ) ;
V_407 = V_403 - ( V_406 + V_402 -> V_409 ) ;
F_25 ( L_77 , V_407 ) ;
if ( V_407 > ( long ) V_402 -> V_410 )
V_407 = V_402 -> V_410 ;
if ( V_407 <= 0 )
V_407 = V_402 -> V_411 ;
return V_407 ;
}
static const struct V_412 * F_230 ( int V_413 ,
int V_414 ,
int V_415 ,
int V_416 )
{
const struct V_412 * V_417 ;
int V_101 ;
if ( V_415 == 0 || V_416 == 0 )
return NULL ;
for ( V_101 = 0 ; V_101 < F_231 ( V_418 ) ; V_101 ++ ) {
V_417 = & V_418 [ V_101 ] ;
if ( V_413 == V_417 -> V_413 &&
V_414 == V_417 -> V_414 &&
V_415 == V_417 -> V_419 && V_416 == V_417 -> V_420 )
return V_417 ;
}
F_25 ( L_78 ) ;
return NULL ;
}
static void F_232 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_421 , F_3 ( V_421 ) & ~ V_422 ) ;
}
static int F_233 ( struct V_1 * V_2 , int V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_423 = F_3 ( V_424 ) ;
int V_230 ;
V_230 = V_423 & 0x7f ;
if ( V_99 )
V_230 = ( ( V_423 >> V_425 ) & 0x7f ) - V_230 ;
F_25 ( L_79 , V_423 ,
V_99 ? L_80 : L_81 , V_230 ) ;
return V_230 ;
}
static int F_234 ( struct V_1 * V_2 , int V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_423 = F_3 ( V_424 ) ;
int V_230 ;
V_230 = V_423 & 0x1ff ;
if ( V_99 )
V_230 = ( ( V_423 >> V_426 ) & 0x1ff ) - V_230 ;
V_230 >>= 1 ;
F_25 ( L_79 , V_423 ,
V_99 ? L_80 : L_81 , V_230 ) ;
return V_230 ;
}
static int F_235 ( struct V_1 * V_2 , int V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_423 = F_3 ( V_424 ) ;
int V_230 ;
V_230 = V_423 & 0x7f ;
V_230 >>= 2 ;
F_25 ( L_79 , V_423 ,
V_99 ? L_80 : L_81 ,
V_230 ) ;
return V_230 ;
}
static int F_236 ( struct V_1 * V_2 , int V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_423 = F_3 ( V_424 ) ;
int V_230 ;
V_230 = V_423 & 0x7f ;
V_230 >>= 1 ;
F_25 ( L_79 , V_423 ,
V_99 ? L_80 : L_81 , V_230 ) ;
return V_230 ;
}
static struct V_8 * F_237 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_76 = NULL ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_9 -> V_76 && V_9 -> V_150 ) {
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
const struct V_412 * V_417 ;
T_1 V_70 ;
unsigned long V_402 ;
V_417 = F_230 ( F_239 ( V_2 ) , V_4 -> V_414 ,
V_4 -> V_419 , V_4 -> V_420 ) ;
if ( ! V_417 ) {
F_25 ( L_78 ) ;
F_232 ( V_2 ) ;
return;
}
V_9 = F_237 ( V_2 ) ;
if ( V_9 ) {
int clock = V_9 -> V_232 . clock ;
int V_404 = V_9 -> V_150 -> V_261 / 8 ;
V_402 = F_228 ( clock , & V_427 ,
V_427 . V_403 ,
V_404 , V_417 -> V_428 ) ;
V_70 = F_3 ( V_429 ) ;
V_70 &= ~ V_430 ;
V_70 |= V_402 << V_431 ;
F_23 ( V_429 , V_70 ) ;
F_25 ( L_82 , V_70 ) ;
V_402 = F_228 ( clock , & V_432 ,
V_427 . V_403 ,
V_404 , V_417 -> V_433 ) ;
V_70 = F_3 ( V_421 ) ;
V_70 &= ~ V_434 ;
V_70 |= ( V_402 & 0x3f ) << V_435 ;
F_23 ( V_421 , V_70 ) ;
V_402 = F_228 ( clock , & V_436 ,
V_436 . V_403 ,
V_404 , V_417 -> V_437 ) ;
V_70 = F_3 ( V_421 ) ;
V_70 &= ~ V_438 ;
V_70 |= V_402 & V_438 ;
F_23 ( V_421 , V_70 ) ;
V_402 = F_228 ( clock , & V_439 ,
V_436 . V_403 ,
V_404 , V_417 -> V_440 ) ;
V_70 = F_3 ( V_421 ) ;
V_70 &= ~ V_441 ;
V_70 |= ( V_402 & 0x3f ) << V_442 ;
F_23 ( V_421 , V_70 ) ;
F_25 ( L_83 , V_70 ) ;
F_23 ( V_421 ,
F_3 ( V_421 ) | V_422 ) ;
F_25 ( L_84 ) ;
} else {
F_232 ( V_2 ) ;
F_25 ( L_85 ) ;
}
}
static bool F_240 ( struct V_1 * V_2 ,
int V_99 ,
const struct V_401 * V_207 ,
int V_443 ,
const struct V_401 * V_444 ,
int V_445 ,
int * V_446 ,
int * V_447 )
{
struct V_8 * V_9 ;
int V_448 , V_237 , clock , V_404 ;
int V_449 , V_450 ;
int V_451 , V_452 ;
V_9 = F_241 ( V_2 , V_99 ) ;
if ( V_9 -> V_150 == NULL || ! V_9 -> V_76 ) {
* V_447 = V_444 -> V_409 ;
* V_446 = V_207 -> V_409 ;
return false ;
}
V_448 = V_9 -> V_232 . V_448 ;
V_237 = V_9 -> V_232 . V_237 ;
clock = V_9 -> V_232 . clock ;
V_404 = V_9 -> V_150 -> V_261 / 8 ;
V_451 = ( ( clock * V_404 / 1000 ) * V_443 ) / 1000 ;
V_452 = V_207 -> V_403 * V_207 -> V_408 - V_237 * 8 ;
if ( V_452 > 0 )
V_451 += V_452 ;
V_451 = F_229 ( V_451 , V_207 -> V_408 ) ;
* V_446 = V_451 + V_207 -> V_409 ;
if ( * V_446 > ( int ) V_207 -> V_410 )
* V_446 = V_207 -> V_410 ;
V_449 = ( ( V_448 * 1000 ) / clock ) ;
V_450 = ( V_445 / V_449 + 1000 ) / 1000 ;
V_451 = V_450 * 64 * V_404 ;
V_452 = V_444 -> V_403 * V_444 -> V_408 - V_237 * 8 ;
if ( V_452 > 0 )
V_451 += V_452 ;
V_451 = F_229 ( V_451 , V_444 -> V_408 ) ;
* V_447 = V_451 + V_444 -> V_409 ;
if ( * V_447 > ( int ) V_444 -> V_410 )
* V_447 = ( int ) V_444 -> V_410 ;
return true ;
}
static bool F_242 ( struct V_1 * V_2 ,
int V_453 , int V_447 ,
const struct V_401 * V_207 ,
const struct V_401 * V_444 )
{
F_25 ( L_86 ,
V_453 , V_447 ) ;
if ( V_453 > V_207 -> V_410 ) {
F_25 ( L_87 ,
V_453 , V_207 -> V_410 ) ;
return false ;
}
if ( V_447 > V_444 -> V_410 ) {
F_25 ( L_88 ,
V_447 , V_444 -> V_410 ) ;
return false ;
}
if ( ! ( V_453 || V_447 ) ) {
F_25 ( L_89 ) ;
return false ;
}
return true ;
}
static bool F_243 ( struct V_1 * V_2 ,
int V_99 ,
int V_405 ,
const struct V_401 * V_207 ,
const struct V_401 * V_444 ,
int * V_453 , int * V_447 )
{
struct V_8 * V_9 ;
int V_237 , V_448 , V_404 , clock ;
unsigned long V_449 ;
int V_450 , V_454 ;
int V_455 , V_456 ;
int V_451 ;
if ( ! V_405 ) {
* V_453 = * V_447 = 0 ;
return false ;
}
V_9 = F_241 ( V_2 , V_99 ) ;
V_237 = V_9 -> V_232 . V_237 ;
V_448 = V_9 -> V_232 . V_448 ;
clock = V_9 -> V_232 . clock ;
V_404 = V_9 -> V_150 -> V_261 / 8 ;
V_449 = ( V_448 * 1000 ) / clock ;
V_450 = ( V_405 / V_449 + 1000 ) / 1000 ;
V_454 = V_237 * V_404 ;
V_455 = ( ( clock * V_404 / 1000 ) * V_405 ) / 1000 ;
V_456 = V_450 * V_454 ;
V_451 = F_229 ( V_53 ( V_455 , V_456 ) , V_207 -> V_408 ) ;
* V_453 = V_451 + V_207 -> V_409 ;
V_451 = V_450 * V_404 * 64 ;
V_451 = F_229 ( V_451 , V_444 -> V_408 ) ;
* V_447 = V_451 + V_444 -> V_409 ;
return F_242 ( V_2 ,
* V_453 , * V_447 ,
V_207 , V_444 ) ;
}
static void F_244 ( struct V_1 * V_2 )
{
static const int V_457 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_458 , V_459 , V_460 , V_461 ;
int V_462 , V_433 ;
unsigned int V_76 = 0 ;
if ( F_240 ( V_2 , 0 ,
& V_463 , V_405 ,
& V_464 , V_405 ,
& V_458 , & V_460 ) )
V_76 |= 1 ;
if ( F_240 ( V_2 , 1 ,
& V_463 , V_405 ,
& V_464 , V_405 ,
& V_459 , & V_461 ) )
V_76 |= 2 ;
V_462 = V_433 = 0 ;
if ( F_245 ( V_76 ) &&
F_243 ( V_2 , F_246 ( V_76 ) - 1 ,
V_457 ,
& V_463 ,
& V_464 ,
& V_462 , & V_433 ) )
F_23 ( V_465 , V_466 ) ;
else
F_23 ( V_465 ,
F_3 ( V_465 ) & ~ V_466 ) ;
F_25 ( L_90 ,
V_458 , V_460 ,
V_459 , V_461 ,
V_462 , V_433 ) ;
F_23 ( V_429 ,
( V_462 << V_431 ) |
( V_461 << V_467 ) |
( V_459 << V_468 ) |
V_458 ) ;
F_23 ( V_469 ,
( F_3 ( V_469 ) & V_470 ) |
( V_460 << V_471 ) ) ;
F_23 ( V_421 ,
( F_3 ( V_421 ) & ~ V_472 ) |
( V_433 << V_435 ) ) ;
}
static void F_247 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
int V_473 = 1 ;
int V_433 = 16 ;
V_9 = F_237 ( V_2 ) ;
if ( V_9 ) {
static const int V_457 = 12000 ;
int clock = V_9 -> V_232 . clock ;
int V_448 = V_9 -> V_232 . V_448 ;
int V_237 = V_9 -> V_232 . V_237 ;
int V_404 = V_9 -> V_150 -> V_261 / 8 ;
unsigned long V_449 ;
int V_451 ;
V_449 = ( ( V_448 * 1000 ) / clock ) ;
V_451 = ( ( ( V_457 / V_449 ) + 1000 ) / 1000 ) *
V_404 * V_237 ;
V_451 = F_229 ( V_451 , V_474 ) ;
V_473 = V_475 - V_451 ;
if ( V_473 < 0 )
V_473 = 1 ;
V_473 &= 0x1ff ;
F_25 ( L_91 ,
V_451 , V_473 ) ;
V_451 = ( ( ( V_457 / V_449 ) + 1000 ) / 1000 ) *
V_404 * 64 ;
V_451 = F_229 ( V_451 ,
V_476 . V_408 ) ;
V_433 = V_476 . V_403 -
( V_451 + V_476 . V_409 ) ;
if ( V_433 > V_476 . V_410 )
V_433 = V_476 . V_410 ;
F_25 ( L_92
L_93 , V_473 , V_433 ) ;
if ( F_135 ( V_2 ) )
F_23 ( V_465 , V_466 ) ;
} else {
if ( F_135 ( V_2 ) )
F_23 ( V_465 , F_3 ( V_465 )
& ~ V_466 ) ;
}
F_25 ( L_94 ,
V_473 ) ;
F_23 ( V_429 , ( V_473 << V_431 ) |
( 8 << 16 ) | ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_23 ( V_469 , ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_23 ( V_421 , ( V_433 << V_435 ) ) ;
}
static void F_248 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_401 * V_477 ;
T_5 V_478 ;
T_5 V_479 ;
int V_480 , V_473 = 1 ;
int V_403 ;
int V_458 , V_459 ;
struct V_8 * V_9 , * V_76 = NULL ;
if ( F_103 ( V_2 ) )
V_477 = & V_481 ;
else if ( ! F_11 ( V_2 ) )
V_477 = & V_482 ;
else
V_477 = & V_483 ;
V_403 = V_4 -> V_207 . V_484 ( V_2 , 0 ) ;
V_9 = F_241 ( V_2 , 0 ) ;
if ( V_9 -> V_76 && V_9 -> V_150 ) {
V_458 = F_228 ( V_9 -> V_232 . clock ,
V_477 , V_403 ,
V_9 -> V_150 -> V_261 / 8 ,
V_405 ) ;
V_76 = V_9 ;
} else
V_458 = V_403 - V_477 -> V_409 ;
V_403 = V_4 -> V_207 . V_484 ( V_2 , 1 ) ;
V_9 = F_241 ( V_2 , 1 ) ;
if ( V_9 -> V_76 && V_9 -> V_150 ) {
V_459 = F_228 ( V_9 -> V_232 . clock ,
V_477 , V_403 ,
V_9 -> V_150 -> V_261 / 8 ,
V_405 ) ;
if ( V_76 == NULL )
V_76 = V_9 ;
else
V_76 = NULL ;
} else
V_459 = V_403 - V_477 -> V_409 ;
F_25 ( L_95 , V_458 , V_459 ) ;
V_480 = 2 ;
if ( F_249 ( V_2 ) || F_103 ( V_2 ) )
F_23 ( V_465 , V_485 | 0 ) ;
else if ( F_131 ( V_2 ) )
F_23 ( V_486 , F_3 ( V_486 ) & ~ V_487 ) ;
if ( F_250 ( V_2 ) && V_76 ) {
static const int V_457 = 6000 ;
int clock = V_76 -> V_232 . clock ;
int V_448 = V_76 -> V_232 . V_448 ;
int V_237 = V_76 -> V_232 . V_237 ;
int V_404 = V_76 -> V_150 -> V_261 / 8 ;
unsigned long V_449 ;
int V_451 ;
V_449 = ( V_448 * 1000 ) / clock ;
V_451 = ( ( ( V_457 / V_449 ) + 1000 ) / 1000 ) *
V_404 * V_237 ;
V_451 = F_229 ( V_451 , V_477 -> V_408 ) ;
F_25 ( L_96 , V_451 ) ;
V_473 = V_477 -> V_403 - V_451 ;
if ( V_473 < 0 )
V_473 = 1 ;
if ( F_249 ( V_2 ) || F_103 ( V_2 ) )
F_23 ( V_465 ,
V_488 | ( V_473 & 0xff ) ) ;
else if ( F_131 ( V_2 ) )
F_23 ( V_465 , V_473 & 0x3f ) ;
}
F_25 ( L_97 ,
V_458 , V_459 , V_480 , V_473 ) ;
V_478 = ( ( V_459 & 0x3f ) << 16 ) | ( V_458 & 0x3f ) ;
V_479 = ( V_480 & 0x1f ) ;
V_478 = V_478 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_479 = V_479 | ( 1 << 8 ) ;
F_23 ( V_489 , V_478 ) ;
F_23 ( V_490 , V_479 ) ;
if ( F_250 ( V_2 ) ) {
if ( V_76 ) {
if ( F_249 ( V_2 ) || F_103 ( V_2 ) )
F_23 ( V_465 ,
V_485 | V_466 ) ;
else if ( F_131 ( V_2 ) )
F_23 ( V_486 , F_3 ( V_486 ) | V_487 ) ;
F_25 ( L_98 ) ;
} else
F_25 ( L_99 ) ;
}
}
static void F_251 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
T_5 V_478 ;
int V_458 ;
V_9 = F_237 ( V_2 ) ;
if ( V_9 == NULL )
return;
V_458 = F_228 ( V_9 -> V_232 . clock , & V_491 ,
V_4 -> V_207 . V_484 ( V_2 , 0 ) ,
V_9 -> V_150 -> V_261 / 8 ,
V_405 ) ;
V_478 = F_3 ( V_489 ) & ~ 0xfff ;
V_478 |= ( 3 << 8 ) | V_458 ;
F_25 ( L_100 , V_458 ) ;
F_23 ( V_489 , V_478 ) ;
}
static bool F_252 ( struct V_1 * V_2 , int V_492 ,
int V_493 , int V_453 , int V_447 ,
const struct V_401 * V_207 ,
const struct V_401 * V_444 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_25 ( L_101
L_102 , V_492 , V_453 , V_493 , V_447 ) ;
if ( V_493 > V_494 ) {
F_25 ( L_103 ,
V_493 , V_494 , V_492 ) ;
F_23 ( V_495 ,
F_3 ( V_495 ) | V_496 ) ;
return false ;
}
if ( V_453 > V_207 -> V_410 ) {
F_25 ( L_104 ,
V_453 , V_497 , V_492 ) ;
return false ;
}
if ( V_447 > V_444 -> V_410 ) {
F_25 ( L_105 ,
V_447 , V_498 , V_492 ) ;
return false ;
}
if ( ! ( V_493 || V_453 || V_447 ) ) {
F_25 ( L_106 , V_492 , V_492 ) ;
return false ;
}
return true ;
}
static bool F_253 ( struct V_1 * V_2 , int V_492 , int V_99 ,
int V_405 ,
const struct V_401 * V_207 ,
const struct V_401 * V_444 ,
int * V_493 , int * V_453 , int * V_447 )
{
struct V_8 * V_9 ;
unsigned long V_449 ;
int V_237 , V_448 , V_404 , clock ;
int V_450 , V_454 ;
int V_455 , V_456 ;
int V_451 ;
if ( ! V_405 ) {
* V_493 = * V_453 = * V_447 = 0 ;
return false ;
}
V_9 = F_241 ( V_2 , V_99 ) ;
V_237 = V_9 -> V_232 . V_237 ;
V_448 = V_9 -> V_232 . V_448 ;
clock = V_9 -> V_232 . clock ;
V_404 = V_9 -> V_150 -> V_261 / 8 ;
V_449 = ( V_448 * 1000 ) / clock ;
V_450 = ( V_405 / V_449 + 1000 ) / 1000 ;
V_454 = V_237 * V_404 ;
V_455 = ( ( clock * V_404 / 1000 ) * V_405 ) / 1000 ;
V_456 = V_450 * V_454 ;
V_451 = F_229 ( V_53 ( V_455 , V_456 ) , V_207 -> V_408 ) ;
* V_453 = V_451 + V_207 -> V_409 ;
* V_493 = F_229 ( * V_453 * 64 , V_454 ) + 2 ;
V_451 = V_450 * V_404 * 64 ;
V_451 = F_229 ( V_451 , V_444 -> V_408 ) ;
* V_447 = V_451 + V_444 -> V_409 ;
return F_252 ( V_2 , V_492 ,
* V_493 , * V_453 , * V_447 ,
V_207 , V_444 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_493 , V_446 , V_447 ;
unsigned int V_76 ;
V_76 = 0 ;
if ( F_240 ( V_2 , 0 ,
& V_499 ,
V_500 ,
& V_501 ,
V_502 ,
& V_446 , & V_447 ) ) {
F_23 ( V_503 ,
( V_446 << V_504 ) | V_447 ) ;
F_25 ( L_107
L_108 L_109 ,
V_446 , V_447 ) ;
V_76 |= 1 ;
}
if ( F_240 ( V_2 , 1 ,
& V_499 ,
V_500 ,
& V_501 ,
V_502 ,
& V_446 , & V_447 ) ) {
F_23 ( V_505 ,
( V_446 << V_504 ) | V_447 ) ;
F_25 ( L_110
L_111 ,
V_446 , V_447 ) ;
V_76 |= 2 ;
}
F_23 ( V_506 , 0 ) ;
F_23 ( V_507 , 0 ) ;
F_23 ( V_508 , 0 ) ;
if ( ! F_245 ( V_76 ) )
return;
V_76 = F_246 ( V_76 ) - 1 ;
if ( ! F_253 ( V_2 , 1 , V_76 ,
F_255 () * 500 ,
& V_509 ,
& V_510 ,
& V_493 , & V_446 , & V_447 ) )
return;
F_23 ( V_508 ,
V_511 |
( F_255 () << V_512 ) |
( V_493 << V_513 ) |
( V_446 << V_514 ) |
V_447 ) ;
if ( ! F_253 ( V_2 , 2 , V_76 ,
F_256 () * 500 ,
& V_509 ,
& V_510 ,
& V_493 , & V_446 , & V_447 ) )
return;
F_23 ( V_507 ,
V_515 |
( F_256 () << V_512 ) |
( V_493 << V_513 ) |
( V_446 << V_514 ) |
V_447 ) ;
}
void F_257 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_417 = F_258 () * 100 ;
int V_493 , V_446 , V_447 ;
unsigned int V_76 ;
V_76 = 0 ;
if ( F_240 ( V_2 , 0 ,
& V_516 , V_417 ,
& V_517 , V_417 ,
& V_446 , & V_447 ) ) {
F_23 ( V_503 ,
( V_446 << V_504 ) | V_447 ) ;
F_25 ( L_107
L_108 L_109 ,
V_446 , V_447 ) ;
V_76 |= 1 ;
}
if ( F_240 ( V_2 , 1 ,
& V_516 , V_417 ,
& V_517 , V_417 ,
& V_446 , & V_447 ) ) {
F_23 ( V_505 ,
( V_446 << V_504 ) | V_447 ) ;
F_25 ( L_110
L_111 ,
V_446 , V_447 ) ;
V_76 |= 2 ;
}
if ( F_147 ( V_2 ) &&
F_240 ( V_2 , 2 ,
& V_516 , V_417 ,
& V_517 , V_417 ,
& V_446 , & V_447 ) ) {
F_23 ( V_518 ,
( V_446 << V_504 ) | V_447 ) ;
F_25 ( L_112
L_111 ,
V_446 , V_447 ) ;
V_76 |= 3 ;
}
F_23 ( V_506 , 0 ) ;
F_23 ( V_507 , 0 ) ;
F_23 ( V_508 , 0 ) ;
if ( ! F_245 ( V_76 ) ||
V_4 -> V_519 )
return;
V_76 = F_246 ( V_76 ) - 1 ;
if ( ! F_253 ( V_2 , 1 , V_76 ,
F_259 () * 500 ,
& V_520 ,
& V_521 ,
& V_493 , & V_446 , & V_447 ) )
return;
F_23 ( V_508 ,
V_511 |
( F_259 () << V_512 ) |
( V_493 << V_513 ) |
( V_446 << V_514 ) |
V_447 ) ;
if ( ! F_253 ( V_2 , 2 , V_76 ,
F_260 () * 500 ,
& V_520 ,
& V_521 ,
& V_493 , & V_446 , & V_447 ) )
return;
F_23 ( V_507 ,
V_515 |
( F_260 () << V_512 ) |
( V_493 << V_513 ) |
( V_446 << V_514 ) |
V_447 ) ;
if ( ! F_253 ( V_2 , 3 , V_76 ,
F_261 () * 500 ,
& V_520 ,
& V_521 ,
& V_493 , & V_446 , & V_447 ) )
return;
F_23 ( V_506 ,
V_522 |
( F_261 () << V_512 ) |
( V_493 << V_513 ) |
( V_446 << V_514 ) |
V_447 ) ;
}
static bool
F_262 ( struct V_1 * V_2 , int V_99 ,
T_5 V_523 , int V_404 ,
const struct V_401 * V_207 ,
int V_443 , int * V_524 )
{
struct V_8 * V_9 ;
int clock ;
int V_451 , V_452 ;
V_9 = F_241 ( V_2 , V_99 ) ;
if ( V_9 -> V_150 == NULL || ! V_9 -> V_76 ) {
* V_524 = V_207 -> V_409 ;
return false ;
}
clock = V_9 -> V_232 . clock ;
V_451 = ( ( clock * V_404 / 1000 ) * V_443 ) / 1000 ;
V_452 = V_207 -> V_403 * V_207 -> V_408 -
V_523 * 8 ;
if ( V_452 > 0 )
V_451 += V_452 ;
V_451 = F_229 ( V_451 , V_207 -> V_408 ) ;
* V_524 = V_451 + V_207 -> V_409 ;
if ( * V_524 > ( int ) V_207 -> V_410 )
* V_524 = V_207 -> V_410 ;
return true ;
}
static bool
F_263 ( struct V_1 * V_2 , int V_99 ,
T_5 V_523 , int V_404 ,
const struct V_401 * V_207 ,
int V_405 , int * V_524 )
{
struct V_8 * V_9 ;
unsigned long V_449 ;
int clock ;
int V_450 , V_454 ;
int V_455 , V_456 ;
int V_451 ;
if ( ! V_405 ) {
* V_524 = 0 ;
return false ;
}
V_9 = F_241 ( V_2 , V_99 ) ;
clock = V_9 -> V_232 . clock ;
if ( ! clock ) {
* V_524 = 0 ;
return false ;
}
V_449 = ( V_523 * 1000 ) / clock ;
if ( ! V_449 ) {
* V_524 = 0 ;
return false ;
}
V_450 = ( V_405 / V_449 + 1000 ) / 1000 ;
V_454 = V_523 * V_404 ;
V_455 = ( ( clock * V_404 / 1000 ) * V_405 ) / 1000 ;
V_456 = V_450 * V_454 ;
V_451 = F_229 ( V_53 ( V_455 , V_456 ) , V_207 -> V_408 ) ;
* V_524 = V_451 + V_207 -> V_409 ;
return * V_524 > 0x3ff ? false : true ;
}
static void F_264 ( struct V_1 * V_2 , int V_66 ,
T_5 V_523 , int V_404 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_417 = F_258 () * 100 ;
int V_524 , V_70 ;
int V_248 ;
switch ( V_66 ) {
case 0 :
V_70 = V_503 ;
break;
case 1 :
V_70 = V_505 ;
break;
case 2 :
V_70 = V_518 ;
break;
default:
return;
}
V_248 = F_262 ( V_2 , V_66 , V_523 , V_404 ,
& V_516 ,
V_417 , & V_524 ) ;
if ( ! V_248 ) {
F_25 ( L_113 ,
V_66 ) ;
return;
}
F_23 ( V_70 , F_3 ( V_70 ) | ( V_524 << V_525 ) ) ;
F_25 ( L_114 , V_66 , V_524 ) ;
V_248 = F_263 ( V_2 , V_66 , V_523 ,
V_404 ,
& V_520 ,
F_259 () * 500 ,
& V_524 ) ;
if ( ! V_248 ) {
F_25 ( L_115 ,
V_66 ) ;
return;
}
F_23 ( V_526 , V_524 ) ;
if ( ! F_147 ( V_2 ) )
return;
V_248 = F_263 ( V_2 , V_66 , V_523 ,
V_404 ,
& V_520 ,
F_260 () * 500 ,
& V_524 ) ;
if ( ! V_248 ) {
F_25 ( L_116 ,
V_66 ) ;
return;
}
F_23 ( V_527 , V_524 ) ;
V_248 = F_263 ( V_2 , V_66 , V_523 ,
V_404 ,
& V_520 ,
F_261 () * 500 ,
& V_524 ) ;
if ( ! V_248 ) {
F_25 ( L_117 ,
V_66 ) ;
return;
}
F_23 ( V_528 , V_524 ) ;
}
static void F_191 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_207 . V_529 )
V_4 -> V_207 . V_529 ( V_2 ) ;
}
void F_265 ( struct V_1 * V_2 , int V_66 ,
T_5 V_523 , int V_404 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_207 . V_530 )
V_4 -> V_207 . V_530 ( V_2 , V_66 , V_523 ,
V_404 ) ;
}
static inline bool F_266 ( struct V_3 * V_4 )
{
if ( V_531 >= 0 )
return V_531 != 0 ;
return V_4 -> V_532
&& ! ( V_4 -> V_133 & V_533 ) ;
}
static bool F_267 ( struct V_8 * V_9 ,
unsigned int * V_534 ,
struct V_371 * V_232 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_368 * V_51 ;
struct V_535 * V_536 ;
unsigned int V_537 = V_538 , V_333 ;
F_14 (encoder, &dev->mode_config.encoder_list, head) {
struct V_50 * V_50 = F_213 ( V_51 ) ;
if ( V_51 -> V_9 != V_9 )
continue;
if ( V_50 -> type == V_12 ) {
unsigned int V_539 ;
if ( ( F_3 ( V_13 ) & V_540 ) ==
V_541 )
V_539 = 8 ;
else
V_539 = 6 ;
if ( V_539 < V_537 ) {
F_25 ( L_118 , V_537 , V_539 ) ;
V_537 = V_539 ;
}
continue;
}
if ( V_50 -> type == V_324 ) {
unsigned int V_542 = V_4 -> V_543 . V_544 / 3 ;
if ( V_542 < V_537 ) {
F_25 ( L_119 , V_537 , V_542 ) ;
V_537 = V_542 ;
}
continue;
}
F_14 (connector, &dev->mode_config.connector_list,
head) {
if ( V_536 -> V_51 != V_51 )
continue;
if ( V_536 -> V_545 . V_333 &&
V_536 -> V_545 . V_333 < V_537 ) {
F_25 ( L_120 , V_537 , V_536 -> V_545 . V_333 ) ;
V_537 = V_536 -> V_545 . V_333 ;
}
}
if ( V_50 -> type == V_27 ) {
if ( V_537 > 8 && V_537 < 12 ) {
F_25 ( L_121 ) ;
V_537 = 12 ;
} else {
F_25 ( L_122 ) ;
V_537 = 8 ;
}
}
}
if ( V_232 -> V_546 & V_547 ) {
F_25 ( L_123 ) ;
V_537 = 6 ;
}
switch ( V_9 -> V_150 -> V_263 ) {
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
F_268 ( L_124 ) ;
V_333 = V_53 ( ( unsigned int ) 8 , V_537 ) ;
break;
}
V_537 = V_53 ( V_537 , V_333 ) ;
F_25 ( L_125 ,
V_333 , V_537 ) ;
* V_534 = V_537 * 3 ;
return V_537 != V_333 ;
}
static int F_269 ( struct V_8 * V_9 ,
struct V_371 * V_232 ,
struct V_371 * V_372 ,
int V_256 , int V_169 ,
struct V_149 * V_272 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
int V_99 = V_155 -> V_99 ;
int V_10 , V_548 = 0 ;
T_3 clock , V_549 ;
T_1 V_550 , V_551 = 0 , V_552 = 0 , V_259 , V_553 ;
bool V_554 , V_555 = false , V_556 = false , V_557 = false ;
bool V_558 = false , V_559 = false , V_560 = false , V_561 = false ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
const T_2 * V_11 ;
int V_248 ;
T_1 V_290 ;
T_1 V_562 = 0 ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_12 :
V_559 = true ;
break;
case V_30 :
case V_27 :
V_556 = true ;
if ( V_51 -> V_563 )
V_560 = true ;
break;
case V_564 :
V_557 = true ;
break;
case V_565 :
V_560 = true ;
break;
case V_28 :
V_558 = true ;
break;
case V_20 :
V_561 = true ;
break;
}
V_548 ++ ;
}
if ( V_559 && F_266 ( V_4 ) && V_548 < 2 ) {
V_10 = V_4 -> V_566 * 1000 ;
F_25 ( L_126 ,
V_10 / 1000 ) ;
} else if ( ! F_11 ( V_2 ) ) {
V_10 = 96000 ;
} else {
V_10 = 48000 ;
}
V_11 = F_7 ( V_9 , V_10 ) ;
V_554 = V_11 -> V_567 ( V_11 , V_9 , V_372 -> clock , V_10 , & clock ) ;
if ( ! V_554 ) {
F_83 ( L_127 ) ;
return - V_251 ;
}
F_196 ( V_9 , true ) ;
if ( V_559 && V_4 -> V_568 ) {
V_555 = V_11 -> V_567 ( V_11 , V_9 ,
V_4 -> V_569 ,
V_10 ,
& V_549 ) ;
if ( V_555 && ( clock . V_41 != V_549 . V_41 ) ) {
F_25 ( L_128
L_129 ) ;
V_555 = 0 ;
}
}
if ( V_556 && V_560 ) {
if ( V_372 -> clock >= 100000
&& V_372 -> clock < 140500 ) {
clock . V_42 = 2 ;
clock . V_43 = 10 ;
clock . V_45 = 3 ;
clock . V_47 = 16 ;
clock . V_40 = 8 ;
} else if ( V_372 -> clock >= 140500
&& V_372 -> clock <= 200000 ) {
clock . V_42 = 1 ;
clock . V_43 = 10 ;
clock . V_45 = 6 ;
clock . V_47 = 12 ;
clock . V_40 = 8 ;
}
}
if ( F_10 ( V_2 ) ) {
V_551 = ( 1 << clock . V_45 ) << 16 | clock . V_47 << 8 | clock . V_40 ;
if ( V_555 )
V_552 = ( 1 << V_549 . V_45 ) << 16 |
V_549 . V_47 << 8 | V_549 . V_40 ;
} else {
V_551 = clock . V_45 << 16 | clock . V_47 << 8 | clock . V_40 ;
if ( V_555 )
V_552 = V_549 . V_45 << 16 | V_549 . V_47 << 8 |
V_549 . V_40 ;
}
V_550 = V_570 ;
if ( ! F_11 ( V_2 ) ) {
if ( V_559 )
V_550 |= V_571 ;
else
V_550 |= V_572 ;
if ( V_556 ) {
int V_573 = F_270 ( V_372 ) ;
if ( V_573 > 1 ) {
if ( F_249 ( V_2 ) || F_103 ( V_2 ) || F_271 ( V_2 ) )
V_550 |= ( V_573 - 1 ) << V_574 ;
}
V_550 |= V_575 ;
}
if ( V_561 )
V_550 |= V_575 ;
if ( F_10 ( V_2 ) )
V_550 |= ( 1 << ( clock . V_42 - 1 ) ) << V_576 ;
else {
V_550 |= ( 1 << ( clock . V_42 - 1 ) ) << V_577 ;
if ( F_9 ( V_2 ) && V_555 )
V_550 |= ( 1 << ( V_549 . V_42 - 1 ) ) << V_578 ;
}
switch ( clock . V_43 ) {
case 5 :
V_550 |= V_579 ;
break;
case 7 :
V_550 |= V_580 ;
break;
case 10 :
V_550 |= V_581 ;
break;
case 14 :
V_550 |= V_582 ;
break;
}
if ( F_27 ( V_2 ) -> V_69 >= 4 )
V_550 |= ( 6 << V_583 ) ;
} else {
if ( V_559 ) {
V_550 |= ( 1 << ( clock . V_42 - 1 ) ) << V_577 ;
} else {
if ( clock . V_42 == 2 )
V_550 |= V_584 ;
else
V_550 |= ( clock . V_42 - 2 ) << V_577 ;
if ( clock . V_43 == 4 )
V_550 |= V_585 ;
}
}
if ( V_556 && V_560 )
V_550 |= V_586 ;
else if ( V_560 )
V_550 |= 3 ;
else if ( V_559 && F_266 ( V_4 ) && V_548 < 2 )
V_550 |= V_587 ;
else
V_550 |= V_588 ;
V_553 = F_3 ( F_28 ( V_66 ) ) ;
V_259 = V_589 ;
if ( V_66 == 0 )
V_259 &= ~ V_103 ;
else
V_259 |= V_590 ;
if ( V_66 == 0 && F_27 ( V_2 ) -> V_69 < 4 ) {
if ( V_232 -> clock >
V_4 -> V_207 . V_591 ( V_2 ) * 9 / 10 )
V_553 |= V_592 ;
else
V_553 &= ~ V_592 ;
}
V_553 &= ~ ( V_593 | V_594 ) ;
if ( V_561 ) {
if ( V_232 -> V_546 & V_547 ) {
V_553 |= V_595 |
V_594 |
V_596 ;
}
}
V_550 |= V_80 ;
F_25 ( L_130 , V_66 == 0 ? 'A' : 'B' ) ;
F_272 ( V_232 ) ;
F_23 ( F_273 ( V_66 ) , V_551 ) ;
F_23 ( F_35 ( V_66 ) , V_550 & ~ V_80 ) ;
F_72 ( F_35 ( V_66 ) ) ;
F_73 ( 150 ) ;
if ( V_559 ) {
V_290 = F_3 ( V_24 ) ;
V_290 |= V_119 | V_597 ;
if ( V_66 == 1 ) {
V_290 |= V_96 ;
} else {
V_290 &= ~ V_96 ;
}
V_290 |= V_4 -> V_598 ;
if ( clock . V_43 == 7 )
V_290 |= V_599 | V_15 ;
else
V_290 &= ~ ( V_599 | V_15 ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
if ( V_4 -> V_600 )
V_290 |= V_601 ;
else
V_290 &= ~ V_601 ;
}
if ( V_372 -> V_233 & V_602 )
V_562 |= V_603 ;
if ( V_372 -> V_233 & V_604 )
V_562 |= V_605 ;
if ( ( V_290 & ( V_603 | V_605 ) )
!= V_562 ) {
char V_233 [ 2 ] = L_131 ;
F_274 ( L_132
L_133 ,
V_233 [ ! ( V_290 & V_603 ) ] ,
V_233 [ ! ( V_290 & V_605 ) ] ,
V_233 [ ! ( V_562 & V_603 ) ] ,
V_233 [ ! ( V_562 & V_605 ) ] ) ;
V_290 &= ~ ( V_603 | V_605 ) ;
V_290 |= V_562 ;
}
F_23 ( V_24 , V_290 ) ;
}
if ( V_561 ) {
F_275 ( V_9 , V_232 , V_372 ) ;
}
F_23 ( F_35 ( V_66 ) , V_550 ) ;
F_72 ( F_35 ( V_66 ) ) ;
F_73 ( 150 ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
V_290 = 0 ;
if ( V_556 ) {
V_290 = F_270 ( V_372 ) ;
if ( V_290 > 1 )
V_290 = ( V_290 - 1 ) << V_606 ;
else
V_290 = 0 ;
}
F_23 ( F_276 ( V_66 ) , V_290 ) ;
} else {
F_23 ( F_35 ( V_66 ) , V_550 ) ;
}
V_155 -> V_607 = false ;
if ( V_559 && V_555 && V_223 ) {
F_23 ( F_277 ( V_66 ) , V_552 ) ;
V_155 -> V_607 = true ;
if ( F_278 ( V_2 ) ) {
F_25 ( L_134 ) ;
V_553 |= V_608 ;
}
} else {
F_23 ( F_277 ( V_66 ) , V_551 ) ;
if ( F_278 ( V_2 ) ) {
F_25 ( L_135 ) ;
V_553 &= ~ V_608 ;
}
}
V_553 &= ~ V_609 ;
if ( V_372 -> V_233 & V_234 ) {
V_553 |= V_610 ;
V_372 -> V_611 -= 1 ;
V_372 -> V_612 -= 1 ;
V_372 -> V_613 -= 1 ;
V_372 -> V_614 -= 1 ;
V_372 -> V_615 -= 1 ;
V_372 -> V_616 -= 1 ;
} else
V_553 |= V_617 ;
F_23 ( F_176 ( V_66 ) ,
( V_372 -> V_618 - 1 ) |
( ( V_372 -> V_374 - 1 ) << 16 ) ) ;
F_23 ( F_178 ( V_66 ) ,
( V_372 -> V_619 - 1 ) |
( ( V_372 -> V_620 - 1 ) << 16 ) ) ;
F_23 ( F_180 ( V_66 ) ,
( V_372 -> V_621 - 1 ) |
( ( V_372 -> V_622 - 1 ) << 16 ) ) ;
F_23 ( F_182 ( V_66 ) ,
( V_372 -> V_611 - 1 ) |
( ( V_372 -> V_612 - 1 ) << 16 ) ) ;
F_23 ( F_184 ( V_66 ) ,
( V_372 -> V_613 - 1 ) |
( ( V_372 -> V_614 - 1 ) << 16 ) ) ;
F_23 ( F_186 ( V_66 ) ,
( V_372 -> V_616 - 1 ) |
( ( V_372 -> V_615 - 1 ) << 16 ) ) ;
F_23 ( F_279 ( V_99 ) ,
( ( V_232 -> V_238 - 1 ) << 16 ) |
( V_232 -> V_237 - 1 ) ) ;
F_23 ( F_280 ( V_99 ) , 0 ) ;
F_23 ( F_281 ( V_66 ) ,
( ( V_232 -> V_237 - 1 ) << 16 ) | ( V_232 -> V_238 - 1 ) ) ;
F_23 ( F_28 ( V_66 ) , V_553 ) ;
F_72 ( F_28 ( V_66 ) ) ;
F_87 ( V_4 , V_66 , false ) ;
F_21 ( V_2 , V_66 ) ;
F_23 ( F_50 ( V_99 ) , V_259 ) ;
F_72 ( F_50 ( V_99 ) ) ;
F_93 ( V_4 , V_99 , V_66 ) ;
V_248 = F_146 ( V_9 , V_256 , V_169 , V_272 ) ;
F_191 ( V_2 ) ;
return V_248 ;
}
void F_282 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
T_1 V_290 ;
bool V_623 = false ;
bool V_624 = false ;
bool V_625 = false ;
bool V_626 = false ;
bool V_627 = false ;
bool V_628 = false ;
F_14 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_51 -> type ) {
case V_12 :
V_626 = true ;
V_623 = true ;
break;
case V_324 :
V_626 = true ;
if ( F_173 ( & V_51 -> V_52 ) )
V_625 = true ;
else
V_624 = true ;
break;
}
}
if ( F_82 ( V_2 ) ) {
V_627 = V_4 -> V_629 ;
V_628 = V_627 ;
} else {
V_627 = false ;
V_628 = true ;
}
F_25 ( L_136 ,
V_626 , V_623 , V_625 , V_624 ,
V_627 ) ;
V_290 = F_3 ( V_105 ) ;
V_290 &= ~ V_107 ;
if ( V_627 )
V_290 |= V_630 ;
else
V_290 |= V_631 ;
if ( V_626 ) {
V_290 &= ~ V_106 ;
V_290 |= V_632 ;
if ( F_266 ( V_4 ) && V_628 ) {
F_25 ( L_137 ) ;
V_290 |= V_633 ;
}
F_23 ( V_105 , V_290 ) ;
F_72 ( V_105 ) ;
F_73 ( 200 ) ;
V_290 &= ~ V_634 ;
if ( V_624 ) {
if ( F_266 ( V_4 ) && V_628 ) {
F_25 ( L_138 ) ;
V_290 |= V_635 ;
}
else
V_290 |= V_636 ;
} else
V_290 |= V_637 ;
F_23 ( V_105 , V_290 ) ;
F_72 ( V_105 ) ;
F_73 ( 200 ) ;
} else {
F_25 ( L_139 ) ;
V_290 &= ~ V_634 ;
V_290 |= V_637 ;
F_23 ( V_105 , V_290 ) ;
F_72 ( V_105 ) ;
F_73 ( 200 ) ;
V_290 &= ~ V_106 ;
V_290 |= V_638 ;
V_290 &= ~ V_633 ;
F_23 ( V_105 , V_290 ) ;
F_72 ( V_105 ) ;
F_73 ( 200 ) ;
}
}
static int F_283 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_50 * V_51 ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_639 = NULL ;
int V_548 = 0 ;
bool V_559 = false ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_12 :
V_559 = true ;
break;
case V_324 :
V_639 = V_51 ;
break;
}
V_548 ++ ;
}
if ( V_559 && F_266 ( V_4 ) && V_548 < 2 ) {
F_25 ( L_126 ,
V_4 -> V_566 ) ;
return V_4 -> V_566 * 1000 ;
}
return 120000 ;
}
static int F_284 ( struct V_8 * V_9 ,
struct V_371 * V_232 ,
struct V_371 * V_372 ,
int V_256 , int V_169 ,
struct V_149 * V_272 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
int V_99 = V_155 -> V_99 ;
int V_10 , V_548 = 0 ;
T_3 clock , V_549 ;
T_1 V_550 , V_551 = 0 , V_552 = 0 , V_259 , V_553 ;
bool V_554 , V_555 = false , V_556 = false ;
bool V_558 = false , V_559 = false , V_560 = false , V_561 = false ;
struct V_50 * V_640 = NULL ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
const T_2 * V_11 ;
int V_248 ;
struct V_393 V_394 = { 0 } ;
T_1 V_290 ;
T_1 V_562 = 0 ;
int V_641 , V_573 , V_642 , V_643 , V_644 ;
unsigned int V_534 ;
bool V_645 ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_12 :
V_559 = true ;
break;
case V_30 :
case V_27 :
V_556 = true ;
if ( V_51 -> V_563 )
V_560 = true ;
break;
case V_565 :
V_560 = true ;
break;
case V_28 :
V_558 = true ;
break;
case V_20 :
V_561 = true ;
break;
case V_324 :
V_640 = V_51 ;
break;
}
V_548 ++ ;
}
V_10 = F_283 ( V_9 ) ;
V_11 = F_7 ( V_9 , V_10 ) ;
V_554 = V_11 -> V_567 ( V_11 , V_9 , V_372 -> clock , V_10 , & clock ) ;
if ( ! V_554 ) {
F_83 ( L_127 ) ;
return - V_251 ;
}
F_196 ( V_9 , true ) ;
if ( V_559 && V_4 -> V_568 ) {
V_555 = V_11 -> V_567 ( V_11 , V_9 ,
V_4 -> V_569 ,
V_10 ,
& V_549 ) ;
if ( V_555 && ( clock . V_41 != V_549 . V_41 ) ) {
F_25 ( L_128
L_129 ) ;
V_555 = 0 ;
}
}
if ( V_556 && V_560 ) {
if ( V_372 -> clock >= 100000
&& V_372 -> clock < 140500 ) {
clock . V_42 = 2 ;
clock . V_43 = 10 ;
clock . V_45 = 3 ;
clock . V_47 = 16 ;
clock . V_40 = 8 ;
} else if ( V_372 -> clock >= 140500
&& V_372 -> clock <= 200000 ) {
clock . V_42 = 1 ;
clock . V_43 = 10 ;
clock . V_45 = 6 ;
clock . V_47 = 12 ;
clock . V_40 = 8 ;
}
}
V_573 = F_270 ( V_372 ) ;
V_642 = 0 ;
if ( V_640 &&
! F_173 ( & V_640 -> V_52 ) ) {
V_641 = V_232 -> clock ;
F_285 ( V_640 ,
& V_642 , & V_643 ) ;
} else {
if ( V_561 || F_173 ( & V_640 -> V_52 ) )
V_641 = V_232 -> clock ;
else
V_641 = V_372 -> clock ;
V_643 = F_1 ( V_2 ) * F_286 ( 100 ) / F_287 ( 1 ) / 10 ;
}
V_290 = F_3 ( F_28 ( V_66 ) ) ;
V_290 &= ~ V_140 ;
V_645 = F_267 ( V_9 , & V_534 , V_232 ) ;
switch ( V_534 ) {
case 18 :
V_290 |= V_646 ;
break;
case 24 :
V_290 |= V_647 ;
break;
case 30 :
V_290 |= V_648 ;
break;
case 36 :
V_290 |= V_649 ;
break;
default:
F_36 ( 1 , L_140 ,
V_534 ) ;
V_290 |= V_647 ;
V_534 = 24 ;
break;
}
V_155 -> V_544 = V_534 ;
F_23 ( F_28 ( V_66 ) , V_290 ) ;
if ( ! V_642 ) {
T_1 V_650 = V_641 * V_155 -> V_544 * 21 / 20 ;
V_642 = V_650 / ( V_643 * 8 ) + 1 ;
}
V_155 -> V_305 = V_642 ;
if ( V_573 > 1 )
V_643 *= V_573 ;
F_227 ( V_155 -> V_544 , V_642 , V_641 , V_643 ,
& V_394 ) ;
V_551 = clock . V_45 << 16 | clock . V_47 << 8 | clock . V_40 ;
if ( V_555 )
V_552 = V_549 . V_45 << 16 | V_549 . V_47 << 8 |
V_549 . V_40 ;
V_644 = 21 ;
if ( V_559 ) {
if ( ( F_266 ( V_4 ) &&
V_4 -> V_566 == 100 ) ||
( F_3 ( V_13 ) & V_14 ) == V_15 )
V_644 = 25 ;
} else if ( V_556 && V_560 )
V_644 = 20 ;
if ( clock . V_39 < V_644 * clock . V_45 )
V_551 |= V_651 ;
V_550 = 0 ;
if ( V_559 )
V_550 |= V_571 ;
else
V_550 |= V_572 ;
if ( V_556 ) {
int V_573 = F_270 ( V_372 ) ;
if ( V_573 > 1 ) {
V_550 |= ( V_573 - 1 ) << V_652 ;
}
V_550 |= V_575 ;
}
if ( V_561 || F_173 ( & V_640 -> V_52 ) )
V_550 |= V_575 ;
V_550 |= ( 1 << ( clock . V_42 - 1 ) ) << V_577 ;
V_550 |= ( 1 << ( clock . V_42 - 1 ) ) << V_578 ;
switch ( clock . V_43 ) {
case 5 :
V_550 |= V_579 ;
break;
case 7 :
V_550 |= V_580 ;
break;
case 10 :
V_550 |= V_581 ;
break;
case 14 :
V_550 |= V_582 ;
break;
}
if ( V_556 && V_560 )
V_550 |= V_586 ;
else if ( V_560 )
V_550 |= 3 ;
else if ( V_559 && F_266 ( V_4 ) && V_548 < 2 )
V_550 |= V_587 ;
else
V_550 |= V_588 ;
V_553 = F_3 ( F_28 ( V_66 ) ) ;
V_259 = V_589 ;
F_25 ( L_141 , V_66 ) ;
F_272 ( V_232 ) ;
if ( ! V_155 -> V_352 ) {
if ( ! V_640 ||
F_173 ( & V_640 -> V_52 ) ) {
F_23 ( F_288 ( V_66 ) , V_551 ) ;
F_23 ( F_39 ( V_66 ) , V_550 & ~ V_80 ) ;
F_72 ( F_39 ( V_66 ) ) ;
F_73 ( 150 ) ;
}
} else {
if ( V_550 == ( F_3 ( F_39 ( 0 ) ) & 0x7fffffff ) &&
V_551 == F_3 ( F_288 ( 0 ) ) ) {
V_155 -> V_327 = true ;
F_25 ( L_142 ) ;
} else if ( V_550 == ( F_3 ( F_39 ( 1 ) ) & 0x7fffffff ) &&
V_551 == F_3 ( F_288 ( 1 ) ) ) {
V_155 -> V_327 = false ;
F_25 ( L_143 ) ;
} else {
F_25 ( L_144 ) ;
return - V_251 ;
}
}
if ( V_559 ) {
V_290 = F_3 ( V_13 ) ;
V_290 |= V_119 | V_597 ;
if ( F_38 ( V_2 ) ) {
V_290 &= ~ V_117 ;
V_290 |= F_59 ( V_66 ) ;
} else {
if ( V_66 == 1 )
V_290 |= V_96 ;
else
V_290 &= ~ V_96 ;
}
V_290 |= V_4 -> V_598 ;
if ( clock . V_43 == 7 )
V_290 |= V_599 | V_15 ;
else
V_290 &= ~ ( V_599 | V_15 ) ;
if ( V_372 -> V_233 & V_602 )
V_562 |= V_603 ;
if ( V_372 -> V_233 & V_604 )
V_562 |= V_605 ;
if ( ( V_290 & ( V_603 | V_605 ) )
!= V_562 ) {
char V_233 [ 2 ] = L_131 ;
F_274 ( L_132
L_133 ,
V_233 [ ! ( V_290 & V_603 ) ] ,
V_233 [ ! ( V_290 & V_605 ) ] ,
V_233 [ ! ( V_562 & V_603 ) ] ,
V_233 [ ! ( V_562 & V_605 ) ] ) ;
V_290 &= ~ ( V_603 | V_605 ) ;
V_290 |= V_562 ;
}
F_23 ( V_13 , V_290 ) ;
}
V_553 &= ~ V_594 ;
V_553 &= ~ V_653 ;
if ( ( V_559 && V_4 -> V_600 ) || V_645 ) {
V_553 |= V_594 ;
V_553 |= V_596 ;
}
if ( V_561 || F_173 ( & V_640 -> V_52 ) ) {
F_275 ( V_9 , V_232 , V_372 ) ;
} else {
F_23 ( F_289 ( V_66 ) , 0 ) ;
F_23 ( F_290 ( V_66 ) , 0 ) ;
F_23 ( F_291 ( V_66 ) , 0 ) ;
F_23 ( F_292 ( V_66 ) , 0 ) ;
}
if ( ! V_155 -> V_352 &&
( ! V_640 ||
F_173 ( & V_640 -> V_52 ) ) ) {
F_23 ( F_39 ( V_66 ) , V_550 ) ;
F_72 ( F_39 ( V_66 ) ) ;
F_73 ( 150 ) ;
F_23 ( F_39 ( V_66 ) , V_550 ) ;
}
V_155 -> V_607 = false ;
if ( ! V_155 -> V_352 ) {
if ( V_559 && V_555 && V_223 ) {
F_23 ( F_293 ( V_66 ) , V_552 ) ;
V_155 -> V_607 = true ;
if ( F_278 ( V_2 ) ) {
F_25 ( L_134 ) ;
V_553 |= V_608 ;
}
} else {
F_23 ( F_293 ( V_66 ) , V_551 ) ;
if ( F_278 ( V_2 ) ) {
F_25 ( L_135 ) ;
V_553 &= ~ V_608 ;
}
}
}
V_553 &= ~ V_609 ;
if ( V_372 -> V_233 & V_234 ) {
V_553 |= V_610 ;
V_372 -> V_611 -= 1 ;
V_372 -> V_612 -= 1 ;
V_372 -> V_613 -= 1 ;
V_372 -> V_614 -= 1 ;
V_372 -> V_615 -= 1 ;
V_372 -> V_616 -= 1 ;
} else
V_553 |= V_617 ;
F_23 ( F_176 ( V_66 ) ,
( V_372 -> V_618 - 1 ) |
( ( V_372 -> V_374 - 1 ) << 16 ) ) ;
F_23 ( F_178 ( V_66 ) ,
( V_372 -> V_619 - 1 ) |
( ( V_372 -> V_620 - 1 ) << 16 ) ) ;
F_23 ( F_180 ( V_66 ) ,
( V_372 -> V_621 - 1 ) |
( ( V_372 -> V_622 - 1 ) << 16 ) ) ;
F_23 ( F_182 ( V_66 ) ,
( V_372 -> V_611 - 1 ) |
( ( V_372 -> V_612 - 1 ) << 16 ) ) ;
F_23 ( F_184 ( V_66 ) ,
( V_372 -> V_613 - 1 ) |
( ( V_372 -> V_614 - 1 ) << 16 ) ) ;
F_23 ( F_186 ( V_66 ) ,
( V_372 -> V_616 - 1 ) |
( ( V_372 -> V_615 - 1 ) << 16 ) ) ;
F_23 ( F_281 ( V_66 ) ,
( ( V_232 -> V_237 - 1 ) << 16 ) | ( V_232 -> V_238 - 1 ) ) ;
F_23 ( F_164 ( V_66 ) , F_294 ( V_394 . V_395 ) | V_394 . V_396 ) ;
F_23 ( F_295 ( V_66 ) , V_394 . V_397 ) ;
F_23 ( F_296 ( V_66 ) , V_394 . V_398 ) ;
F_23 ( F_297 ( V_66 ) , V_394 . V_399 ) ;
if ( V_640 &&
! F_173 ( & V_640 -> V_52 ) ) {
F_151 ( V_9 , V_372 -> clock ) ;
}
F_23 ( F_28 ( V_66 ) , V_553 ) ;
F_72 ( F_28 ( V_66 ) ) ;
F_21 ( V_2 , V_66 ) ;
if ( F_2 ( V_2 ) ) {
V_290 = F_3 ( V_495 ) ;
F_23 ( V_495 , V_290 | V_654 ) ;
}
F_23 ( F_50 ( V_99 ) , V_259 ) ;
F_72 ( F_50 ( V_99 ) ) ;
V_248 = F_146 ( V_9 , V_256 , V_169 , V_272 ) ;
F_191 ( V_2 ) ;
return V_248 ;
}
static int F_298 ( struct V_8 * V_9 ,
struct V_371 * V_232 ,
struct V_371 * V_372 ,
int V_256 , int V_169 ,
struct V_149 * V_272 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
int V_248 ;
F_299 ( V_2 , V_66 ) ;
V_248 = V_4 -> V_207 . V_655 ( V_9 , V_232 , V_372 ,
V_256 , V_169 , V_272 ) ;
F_300 ( V_2 , V_66 ) ;
if ( V_248 )
V_155 -> V_359 = V_356 ;
else
V_155 -> V_359 = V_353 ;
return V_248 ;
}
static bool F_301 ( struct V_535 * V_536 ,
int V_656 , T_5 V_657 ,
int V_658 , T_5 V_659 ,
int V_660 )
{
struct V_3 * V_4 = V_536 -> V_2 -> V_5 ;
T_6 * V_661 = V_536 -> V_661 ;
T_5 V_101 ;
V_101 = F_3 ( V_656 ) ;
V_101 &= V_657 ;
if ( ! V_661 [ 0 ] )
return ! V_101 ;
if ( ! V_101 )
return false ;
V_101 = F_3 ( V_658 ) ;
V_101 &= ~ V_659 ;
F_23 ( V_658 , V_101 ) ;
for ( V_101 = 0 ; V_101 < V_661 [ 2 ] ; V_101 ++ )
if ( F_3 ( V_660 ) != * ( ( T_5 * ) V_661 + V_101 ) )
return false ;
return true ;
}
static void F_302 ( struct V_535 * V_536 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_536 -> V_2 -> V_5 ;
T_6 * V_661 = V_536 -> V_661 ;
T_5 V_662 ;
T_5 V_663 ;
T_5 V_101 ;
V_101 = F_3 ( V_664 ) ;
if ( V_101 == V_665 || V_101 == V_666 )
V_662 = V_667 ;
else
V_662 = V_668 ;
if ( F_301 ( V_536 ,
V_669 , V_662 ,
V_669 , V_670 ,
V_671 ) )
return;
V_101 = F_3 ( V_669 ) ;
V_101 &= ~ ( V_662 | V_670 ) ;
V_663 = ( V_101 >> 9 ) & 0x1f ;
F_23 ( V_669 , V_101 ) ;
if ( ! V_661 [ 0 ] )
return;
V_663 = F_303 ( T_6 , V_661 [ 2 ] , V_663 ) ;
F_304 ( L_145 , V_663 ) ;
for ( V_101 = 0 ; V_101 < V_663 ; V_101 ++ )
F_23 ( V_671 , * ( ( T_5 * ) V_661 + V_101 ) ) ;
V_101 = F_3 ( V_669 ) ;
V_101 |= V_662 ;
F_23 ( V_669 , V_101 ) ;
}
static void F_305 ( struct V_535 * V_536 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_536 -> V_2 -> V_5 ;
T_6 * V_661 = V_536 -> V_661 ;
T_5 V_662 ;
T_5 V_101 ;
int V_663 ;
int V_672 ;
int V_673 ;
int V_674 ;
if ( F_82 ( V_536 -> V_2 ) ) {
V_672 = V_675 ;
V_673 = V_676 ;
V_674 = V_677 ;
} else {
V_672 = V_678 ;
V_673 = V_679 ;
V_674 = V_680 ;
}
V_101 = F_102 ( V_9 ) -> V_66 ;
V_672 += V_101 * 0x100 ;
V_673 += V_101 * 0x100 ;
F_304 ( L_146 , F_47 ( V_101 ) ) ;
V_101 = F_3 ( V_673 ) ;
V_101 = ( V_101 >> 29 ) & 0x3 ;
if ( ! V_101 ) {
F_304 ( L_147 ) ;
V_662 = V_681 ;
V_662 |= V_681 << 4 ;
V_662 |= V_681 << 8 ;
} else {
F_304 ( L_148 , 'A' + V_101 ) ;
V_662 = V_681 << ( ( V_101 - 1 ) * 4 ) ;
}
if ( F_5 ( V_9 , V_20 ) ) {
F_304 ( L_149 ) ;
V_661 [ 5 ] |= ( 1 << 2 ) ;
}
if ( F_301 ( V_536 ,
V_674 , V_662 ,
V_673 , V_682 ,
V_672 ) )
return;
V_101 = F_3 ( V_674 ) ;
V_101 &= ~ V_662 ;
F_23 ( V_674 , V_101 ) ;
if ( ! V_661 [ 0 ] )
return;
V_101 = F_3 ( V_673 ) ;
V_101 &= ~ V_682 ;
F_23 ( V_673 , V_101 ) ;
V_663 = F_303 ( T_6 , V_661 [ 2 ] , 21 ) ;
F_304 ( L_145 , V_663 ) ;
for ( V_101 = 0 ; V_101 < V_663 ; V_101 ++ )
F_23 ( V_672 , * ( ( T_5 * ) V_661 + V_101 ) ) ;
V_101 = F_3 ( V_674 ) ;
V_101 |= V_662 ;
F_23 ( V_674 , V_101 ) ;
}
void F_306 ( struct V_368 * V_51 ,
struct V_371 * V_232 )
{
struct V_8 * V_9 = V_51 -> V_9 ;
struct V_535 * V_536 ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_536 = F_307 ( V_51 , V_232 ) ;
if ( ! V_536 )
return;
F_304 ( L_150 ,
V_536 -> V_52 . V_218 ,
F_308 ( V_536 ) ,
V_536 -> V_51 -> V_52 . V_218 ,
F_309 ( V_536 -> V_51 ) ) ;
V_536 -> V_661 [ 6 ] = F_310 ( V_536 , V_232 ) / 2 ;
if ( V_4 -> V_207 . V_683 )
V_4 -> V_207 . V_683 ( V_536 , V_9 ) ;
}
void F_195 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_684 = F_311 ( V_155 -> V_66 ) ;
int V_101 ;
if ( ! V_9 -> V_76 || ! V_155 -> V_346 )
return;
if ( F_8 ( V_2 ) )
V_684 = F_312 ( V_155 -> V_66 ) ;
for ( V_101 = 0 ; V_101 < 256 ; V_101 ++ ) {
F_23 ( V_684 + 4 * V_101 ,
( V_155 -> V_685 [ V_101 ] << 16 ) |
( V_155 -> V_686 [ V_101 ] << 8 ) |
V_155 -> V_687 [ V_101 ] ) ;
}
}
static void F_313 ( struct V_8 * V_9 , T_1 V_52 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
bool V_688 = V_52 != 0 ;
T_1 V_689 ;
if ( V_155 -> V_690 == V_688 )
return;
V_689 = F_3 ( V_691 ) ;
if ( V_688 ) {
F_23 ( V_692 , V_52 ) ;
V_689 &= ~ ( V_693 ) ;
V_689 |= V_694 |
V_695 |
V_696 ;
} else
V_689 &= ~ ( V_694 | V_695 ) ;
F_23 ( V_691 , V_689 ) ;
V_155 -> V_690 = V_688 ;
}
static void F_314 ( struct V_8 * V_9 , T_1 V_52 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
bool V_688 = V_52 != 0 ;
if ( V_155 -> V_690 != V_688 ) {
T_5 V_689 = F_3 ( F_315 ( V_66 ) ) ;
if ( V_52 ) {
V_689 &= ~ ( V_697 | V_698 ) ;
V_689 |= V_699 | V_700 ;
V_689 |= V_66 << 28 ;
} else {
V_689 &= ~ ( V_697 | V_700 ) ;
V_689 |= V_701 ;
}
F_23 ( F_315 ( V_66 ) , V_689 ) ;
V_155 -> V_690 = V_688 ;
}
F_23 ( F_316 ( V_66 ) , V_52 ) ;
}
static void F_317 ( struct V_8 * V_9 , T_1 V_52 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
bool V_688 = V_52 != 0 ;
if ( V_155 -> V_690 != V_688 ) {
T_5 V_689 = F_3 ( F_318 ( V_66 ) ) ;
if ( V_52 ) {
V_689 &= ~ V_697 ;
V_689 |= V_699 | V_700 ;
} else {
V_689 &= ~ ( V_697 | V_700 ) ;
V_689 |= V_701 ;
}
F_23 ( F_318 ( V_66 ) , V_689 ) ;
V_155 -> V_690 = V_688 ;
}
F_23 ( F_319 ( V_66 ) , V_52 ) ;
}
static void F_196 ( struct V_8 * V_9 ,
bool V_702 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
int V_256 = V_155 -> V_703 ;
int V_169 = V_155 -> V_704 ;
T_1 V_52 , V_705 ;
bool V_688 ;
V_705 = 0 ;
if ( V_702 && V_9 -> V_76 && V_9 -> V_150 ) {
V_52 = V_155 -> V_706 ;
if ( V_256 > ( int ) V_9 -> V_150 -> V_707 )
V_52 = 0 ;
if ( V_169 > ( int ) V_9 -> V_150 -> V_708 )
V_52 = 0 ;
} else
V_52 = 0 ;
if ( V_256 < 0 ) {
if ( V_256 + V_155 -> V_709 < 0 )
V_52 = 0 ;
V_705 |= V_710 << V_711 ;
V_256 = - V_256 ;
}
V_705 |= V_256 << V_711 ;
if ( V_169 < 0 ) {
if ( V_169 + V_155 -> V_712 < 0 )
V_52 = 0 ;
V_705 |= V_710 << V_713 ;
V_169 = - V_169 ;
}
V_705 |= V_169 << V_713 ;
V_688 = V_52 != 0 ;
if ( ! V_688 && ! V_155 -> V_690 )
return;
if ( F_147 ( V_2 ) ) {
F_23 ( F_320 ( V_66 ) , V_705 ) ;
F_317 ( V_9 , V_52 ) ;
} else {
F_23 ( F_321 ( V_66 ) , V_705 ) ;
if ( F_322 ( V_2 ) || F_323 ( V_2 ) )
F_313 ( V_9 , V_52 ) ;
else
F_314 ( V_9 , V_52 ) ;
}
if ( V_688 )
F_324 ( V_2 , F_101 ( V_9 -> V_150 ) -> V_154 ) ;
}
static int F_325 ( struct V_8 * V_9 ,
struct V_714 * V_715 ,
T_5 V_716 ,
T_5 V_707 , T_5 V_708 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
struct V_153 * V_154 ;
T_5 V_717 ;
int V_248 ;
F_25 ( L_41 ) ;
if ( ! V_716 ) {
F_25 ( L_151 ) ;
V_717 = 0 ;
V_154 = NULL ;
F_119 ( & V_2 -> V_213 ) ;
goto V_718;
}
if ( V_707 != 64 || V_708 != 64 ) {
F_83 ( L_152 ) ;
return - V_251 ;
}
V_154 = F_326 ( F_327 ( V_2 , V_715 , V_716 ) ) ;
if ( & V_154 -> V_52 == NULL )
return - V_719 ;
if ( V_154 -> V_52 . V_230 < V_707 * V_708 * 4 ) {
F_83 ( L_153 ) ;
V_248 = - V_720 ;
goto V_721;
}
F_119 ( & V_2 -> V_213 ) ;
if ( ! V_4 -> V_85 -> V_722 ) {
if ( V_154 -> V_241 ) {
F_83 ( L_154 ) ;
V_248 = - V_251 ;
goto V_723;
}
V_248 = F_137 ( V_154 , 0 , NULL ) ;
if ( V_248 ) {
F_83 ( L_155 ) ;
goto V_723;
}
V_248 = F_328 ( V_154 ) ;
if ( V_248 ) {
F_83 ( L_156 ) ;
goto V_724;
}
V_717 = V_154 -> V_202 ;
} else {
int V_725 = F_71 ( V_2 ) ? 16 * 1024 : 256 ;
V_248 = F_329 ( V_2 , V_154 ,
( V_155 -> V_66 == 0 ) ? V_726 : V_727 ,
V_725 ) ;
if ( V_248 ) {
F_83 ( L_157 ) ;
goto V_723;
}
V_717 = V_154 -> V_728 -> V_716 -> V_729 ;
}
if ( F_11 ( V_2 ) )
F_23 ( V_730 , ( V_708 << 12 ) | V_707 ) ;
V_718:
if ( V_155 -> V_731 ) {
if ( V_4 -> V_85 -> V_722 ) {
if ( V_155 -> V_731 != V_154 )
F_330 ( V_2 , V_155 -> V_731 ) ;
} else
F_139 ( V_155 -> V_731 ) ;
F_331 ( & V_155 -> V_731 -> V_52 ) ;
}
F_120 ( & V_2 -> V_213 ) ;
V_155 -> V_706 = V_717 ;
V_155 -> V_731 = V_154 ;
V_155 -> V_709 = V_707 ;
V_155 -> V_712 = V_708 ;
F_196 ( V_9 , true ) ;
return 0 ;
V_724:
F_139 ( V_154 ) ;
V_723:
F_120 ( & V_2 -> V_213 ) ;
V_721:
F_332 ( & V_154 -> V_52 ) ;
return V_248 ;
}
static int F_333 ( struct V_8 * V_9 , int V_256 , int V_169 )
{
struct V_155 * V_155 = F_102 ( V_9 ) ;
V_155 -> V_703 = V_256 ;
V_155 -> V_704 = V_169 ;
F_196 ( V_9 , true ) ;
return 0 ;
}
void F_334 ( struct V_8 * V_9 , T_4 V_732 , T_4 V_733 ,
T_4 V_734 , int V_735 )
{
struct V_155 * V_155 = F_102 ( V_9 ) ;
V_155 -> V_685 [ V_735 ] = V_732 >> 8 ;
V_155 -> V_686 [ V_735 ] = V_733 >> 8 ;
V_155 -> V_687 [ V_735 ] = V_734 >> 8 ;
}
void F_335 ( struct V_8 * V_9 , T_4 * V_732 , T_4 * V_733 ,
T_4 * V_734 , int V_735 )
{
struct V_155 * V_155 = F_102 ( V_9 ) ;
* V_732 = V_155 -> V_685 [ V_735 ] << 8 ;
* V_733 = V_155 -> V_686 [ V_735 ] << 8 ;
* V_734 = V_155 -> V_687 [ V_735 ] << 8 ;
}
static void F_336 ( struct V_8 * V_9 , T_4 * V_732 , T_4 * V_733 ,
T_4 * V_734 , T_5 V_736 , T_5 V_230 )
{
int V_737 = ( V_736 + V_230 > 256 ) ? 256 : V_736 + V_230 , V_101 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
for ( V_101 = V_736 ; V_101 < V_737 ; V_101 ++ ) {
V_155 -> V_685 [ V_101 ] = V_732 [ V_101 ] >> 8 ;
V_155 -> V_686 [ V_101 ] = V_733 [ V_101 ] >> 8 ;
V_155 -> V_687 [ V_101 ] = V_734 [ V_101 ] >> 8 ;
}
F_195 ( V_9 ) ;
}
static struct V_149 *
F_337 ( struct V_1 * V_2 ,
struct V_738 * V_739 ,
struct V_153 * V_154 )
{
struct V_151 * V_152 ;
int V_248 ;
V_152 = F_125 ( sizeof( * V_152 ) , V_220 ) ;
if ( ! V_152 ) {
F_332 ( & V_154 -> V_52 ) ;
return F_338 ( - V_720 ) ;
}
V_248 = F_339 ( V_2 , V_152 , V_739 , V_154 ) ;
if ( V_248 ) {
F_332 ( & V_154 -> V_52 ) ;
F_121 ( V_152 ) ;
return F_338 ( V_248 ) ;
}
return & V_152 -> V_52 ;
}
static T_1
F_340 ( int V_707 , int V_544 )
{
T_1 V_740 = F_229 ( V_707 * V_544 , 8 ) ;
return F_341 ( V_740 , 64 ) ;
}
static T_1
F_342 ( struct V_371 * V_232 , int V_544 )
{
T_1 V_740 = F_340 ( V_232 -> V_237 , V_544 ) ;
return F_341 ( V_740 * V_232 -> V_238 , V_741 ) ;
}
static struct V_149 *
F_343 ( struct V_1 * V_2 ,
struct V_371 * V_232 ,
int V_263 , int V_544 )
{
struct V_153 * V_154 ;
struct V_738 V_739 ;
V_154 = F_344 ( V_2 ,
F_342 ( V_232 , V_544 ) ) ;
if ( V_154 == NULL )
return F_338 ( - V_720 ) ;
V_739 . V_707 = V_232 -> V_237 ;
V_739 . V_708 = V_232 -> V_238 ;
V_739 . V_160 [ 0 ] = F_340 ( V_739 . V_707 ,
V_544 ) ;
V_739 . V_742 = F_345 ( V_544 , V_263 ) ;
return F_337 ( V_2 , & V_739 , V_154 ) ;
}
static struct V_149 *
F_346 ( struct V_1 * V_2 ,
struct V_371 * V_232 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_153 * V_154 ;
struct V_149 * V_150 ;
if ( V_4 -> V_743 == NULL )
return NULL ;
V_154 = V_4 -> V_743 -> V_744 . V_154 ;
if ( V_154 == NULL )
return NULL ;
V_150 = & V_4 -> V_743 -> V_744 . V_52 ;
if ( V_150 -> V_160 [ 0 ] < F_340 ( V_232 -> V_237 ,
V_150 -> V_261 ) )
return NULL ;
if ( V_154 -> V_52 . V_230 < V_232 -> V_238 * V_150 -> V_160 [ 0 ] )
return NULL ;
return V_150 ;
}
bool F_347 ( struct V_50 * V_50 ,
struct V_535 * V_536 ,
struct V_371 * V_232 ,
struct V_745 * V_746 )
{
struct V_155 * V_155 ;
struct V_8 * V_747 ;
struct V_368 * V_51 = & V_50 -> V_52 ;
struct V_8 * V_9 = NULL ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_149 * V_272 ;
int V_101 = - 1 ;
F_25 ( L_158 ,
V_536 -> V_52 . V_218 , F_308 ( V_536 ) ,
V_51 -> V_52 . V_218 , F_309 ( V_51 ) ) ;
if ( V_51 -> V_9 ) {
V_9 = V_51 -> V_9 ;
V_155 = F_102 ( V_9 ) ;
V_746 -> V_359 = V_155 -> V_359 ;
V_746 -> V_748 = false ;
if ( V_155 -> V_359 != V_353 ) {
struct V_369 * V_370 ;
struct V_365 * V_366 ;
V_366 = V_9 -> V_367 ;
V_366 -> V_360 ( V_9 , V_353 ) ;
V_370 = V_51 -> V_367 ;
V_370 -> V_360 ( V_51 , V_353 ) ;
}
return true ;
}
F_14 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_101 ++ ;
if ( ! ( V_51 -> V_749 & ( 1 << V_101 ) ) )
continue;
if ( ! V_747 -> V_76 ) {
V_9 = V_747 ;
break;
}
}
if ( ! V_9 ) {
F_25 ( L_159 ) ;
return false ;
}
V_51 -> V_9 = V_9 ;
V_536 -> V_51 = V_51 ;
V_155 = F_102 ( V_9 ) ;
V_746 -> V_359 = V_155 -> V_359 ;
V_746 -> V_748 = true ;
V_746 -> V_750 = NULL ;
if ( ! V_232 )
V_232 = & V_751 ;
V_272 = V_9 -> V_150 ;
V_9 -> V_150 = F_346 ( V_2 , V_232 ) ;
if ( V_9 -> V_150 == NULL ) {
F_25 ( L_160 ) ;
V_9 -> V_150 = F_343 ( V_2 , V_232 , 24 , 32 ) ;
V_746 -> V_750 = V_9 -> V_150 ;
} else
F_25 ( L_161 ) ;
if ( F_348 ( V_9 -> V_150 ) ) {
F_25 ( L_162 ) ;
V_9 -> V_150 = V_272 ;
return false ;
}
if ( ! F_349 ( V_9 , V_232 , 0 , 0 , V_272 ) ) {
F_25 ( L_163 ) ;
if ( V_746 -> V_750 )
V_746 -> V_750 -> V_752 -> V_753 ( V_746 -> V_750 ) ;
V_9 -> V_150 = V_272 ;
return false ;
}
F_21 ( V_2 , V_155 -> V_66 ) ;
return true ;
}
void F_350 ( struct V_50 * V_50 ,
struct V_535 * V_536 ,
struct V_745 * V_746 )
{
struct V_368 * V_51 = & V_50 -> V_52 ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_8 * V_9 = V_51 -> V_9 ;
struct V_369 * V_370 = V_51 -> V_367 ;
struct V_365 * V_366 = V_9 -> V_367 ;
F_25 ( L_158 ,
V_536 -> V_52 . V_218 , F_308 ( V_536 ) ,
V_51 -> V_52 . V_218 , F_309 ( V_51 ) ) ;
if ( V_746 -> V_748 ) {
V_536 -> V_51 = NULL ;
F_351 ( V_2 ) ;
if ( V_746 -> V_750 )
V_746 -> V_750 -> V_752 -> V_753 ( V_746 -> V_750 ) ;
return;
}
if ( V_746 -> V_359 != V_353 ) {
V_370 -> V_360 ( V_51 , V_746 -> V_359 ) ;
V_366 -> V_360 ( V_9 , V_746 -> V_359 ) ;
}
}
static int F_352 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
T_1 V_550 = F_3 ( F_35 ( V_66 ) ) ;
T_1 V_551 ;
T_3 clock ;
if ( ( V_550 & V_754 ) == 0 )
V_551 = F_3 ( F_273 ( V_66 ) ) ;
else
V_551 = F_3 ( F_277 ( V_66 ) ) ;
clock . V_47 = ( V_551 & V_755 ) >> V_756 ;
if ( F_10 ( V_2 ) ) {
clock . V_45 = F_246 ( ( V_551 & V_757 ) >> V_758 ) - 1 ;
clock . V_40 = ( V_551 & V_759 ) >> V_760 ;
} else {
clock . V_45 = ( V_551 & V_761 ) >> V_758 ;
clock . V_40 = ( V_551 & V_762 ) >> V_760 ;
}
if ( ! F_11 ( V_2 ) ) {
if ( F_10 ( V_2 ) )
clock . V_42 = F_246 ( ( V_550 & V_763 ) >>
V_576 ) ;
else
clock . V_42 = F_246 ( ( V_550 & V_764 ) >>
V_577 ) ;
switch ( V_550 & V_765 ) {
case V_572 :
clock . V_43 = V_550 & V_579 ?
5 : 10 ;
break;
case V_571 :
clock . V_43 = V_550 & V_580 ?
7 : 14 ;
break;
default:
F_25 ( L_164
L_165 , ( int ) ( V_550 & V_765 ) ) ;
return 0 ;
}
F_13 ( V_2 , 96000 , & clock ) ;
} else {
bool V_559 = ( V_66 == 1 ) && ( F_3 ( V_24 ) & V_119 ) ;
if ( V_559 ) {
clock . V_42 = F_246 ( ( V_550 & V_766 ) >>
V_577 ) ;
clock . V_43 = 14 ;
if ( ( V_550 & V_767 ) ==
V_587 ) {
F_13 ( V_2 , 66000 , & clock ) ;
} else
F_13 ( V_2 , 48000 , & clock ) ;
} else {
if ( V_550 & V_584 )
clock . V_42 = 2 ;
else {
clock . V_42 = ( ( V_550 & V_768 ) >>
V_577 ) + 2 ;
}
if ( V_550 & V_585 )
clock . V_43 = 4 ;
else
clock . V_43 = 2 ;
F_13 ( V_2 , 48000 , & clock ) ;
}
}
return clock . V_46 ;
}
struct V_371 * F_353 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
struct V_371 * V_232 ;
int V_769 = F_3 ( F_176 ( V_66 ) ) ;
int V_770 = F_3 ( F_180 ( V_66 ) ) ;
int V_771 = F_3 ( F_182 ( V_66 ) ) ;
int V_772 = F_3 ( F_186 ( V_66 ) ) ;
V_232 = F_125 ( sizeof( * V_232 ) , V_220 ) ;
if ( ! V_232 )
return NULL ;
V_232 -> clock = F_352 ( V_2 , V_9 ) ;
V_232 -> V_237 = ( V_769 & 0xffff ) + 1 ;
V_232 -> V_448 = ( ( V_769 & 0xffff0000 ) >> 16 ) + 1 ;
V_232 -> V_773 = ( V_770 & 0xffff ) + 1 ;
V_232 -> V_774 = ( ( V_770 & 0xffff0000 ) >> 16 ) + 1 ;
V_232 -> V_238 = ( V_771 & 0xffff ) + 1 ;
V_232 -> V_775 = ( ( V_771 & 0xffff0000 ) >> 16 ) + 1 ;
V_232 -> V_776 = ( V_772 & 0xffff ) + 1 ;
V_232 -> V_777 = ( ( V_772 & 0xffff0000 ) >> 16 ) + 1 ;
F_354 ( V_232 ) ;
F_217 ( V_232 , 0 ) ;
return V_232 ;
}
static void F_355 ( unsigned long V_778 )
{
struct V_1 * V_2 = (struct V_1 * ) V_778 ;
T_7 * V_4 = V_2 -> V_5 ;
if ( ! F_356 ( & V_4 -> V_252 . V_779 ) ) {
F_357 ( & V_4 -> V_780 , V_74 +
F_30 ( V_781 ) ) ;
return;
}
V_4 -> V_782 = false ;
F_358 ( V_4 -> V_783 , & V_4 -> V_784 ) ;
}
static void F_359 ( unsigned long V_778 )
{
struct V_155 * V_155 = (struct V_155 * ) V_778 ;
struct V_8 * V_9 = & V_155 -> V_52 ;
T_7 * V_4 = V_9 -> V_2 -> V_5 ;
struct V_151 * V_152 ;
V_152 = F_101 ( V_9 -> V_150 ) ;
if ( V_152 && V_152 -> V_154 -> V_346 ) {
F_357 ( & V_155 -> V_780 , V_74 +
F_30 ( V_785 ) ) ;
return;
}
V_155 -> V_782 = false ;
F_358 ( V_4 -> V_783 , & V_4 -> V_784 ) ;
}
static void F_145 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
int V_786 = F_35 ( V_66 ) ;
int V_550 ;
if ( F_8 ( V_2 ) )
return;
if ( ! V_4 -> V_568 )
return;
V_550 = F_3 ( V_786 ) ;
if ( ! F_278 ( V_2 ) && ( V_550 & V_754 ) ) {
F_304 ( L_166 ) ;
F_23 ( V_93 ,
F_3 ( V_93 ) | V_95 ) ;
V_550 &= ~ V_754 ;
F_23 ( V_786 , V_550 ) ;
F_21 ( V_2 , V_66 ) ;
V_550 = F_3 ( V_786 ) ;
if ( V_550 & V_754 )
F_304 ( L_167 ) ;
F_23 ( V_93 , F_3 ( V_93 ) & 0x3 ) ;
}
F_357 ( & V_155 -> V_780 , V_74 +
F_30 ( V_785 ) ) ;
}
static void F_360 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
int V_66 = V_155 -> V_66 ;
int V_786 = F_35 ( V_66 ) ;
int V_550 = F_3 ( V_786 ) ;
if ( F_8 ( V_2 ) )
return;
if ( ! V_4 -> V_568 )
return;
if ( ! F_278 ( V_2 ) && V_155 -> V_607 ) {
F_304 ( L_168 ) ;
F_23 ( V_93 , F_3 ( V_93 ) |
V_95 ) ;
V_550 |= V_754 ;
F_23 ( V_786 , V_550 ) ;
F_21 ( V_2 , V_66 ) ;
V_550 = F_3 ( V_786 ) ;
if ( ! ( V_550 & V_754 ) )
F_304 ( L_169 ) ;
F_23 ( V_93 , F_3 ( V_93 ) & 0x3 ) ;
}
}
static void F_361 ( struct V_209 * V_212 )
{
T_7 * V_4 = F_117 ( V_212 , T_7 ,
V_784 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_8 * V_9 ;
struct V_155 * V_155 ;
if ( ! V_223 )
return;
F_119 ( & V_2 -> V_213 ) ;
F_362 ( V_4 ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_9 -> V_150 )
continue;
V_155 = F_102 ( V_9 ) ;
if ( ! V_155 -> V_782 )
F_360 ( V_9 ) ;
}
F_120 ( & V_2 -> V_213 ) ;
}
void F_324 ( struct V_1 * V_2 , struct V_153 * V_154 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = NULL ;
struct V_151 * V_152 ;
struct V_155 * V_155 ;
if ( ! F_363 ( V_2 , V_787 ) )
return;
if ( ! V_4 -> V_782 )
V_4 -> V_782 = true ;
else
F_357 ( & V_4 -> V_780 , V_74 +
F_30 ( V_781 ) ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_9 -> V_150 )
continue;
V_155 = F_102 ( V_9 ) ;
V_152 = F_101 ( V_9 -> V_150 ) ;
if ( V_152 -> V_154 == V_154 ) {
if ( ! V_155 -> V_782 ) {
F_145 ( V_9 ) ;
V_155 -> V_782 = true ;
} else {
F_357 ( & V_155 -> V_780 , V_74 +
F_30 ( V_785 ) ) ;
}
}
}
}
static void F_364 ( struct V_8 * V_9 )
{
struct V_155 * V_155 = F_102 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_788 * V_212 ;
unsigned long V_233 ;
F_365 ( & V_2 -> V_789 , V_233 ) ;
V_212 = V_155 -> V_790 ;
V_155 -> V_790 = NULL ;
F_366 ( & V_2 -> V_789 , V_233 ) ;
if ( V_212 ) {
F_367 ( & V_212 -> V_212 ) ;
F_121 ( V_212 ) ;
}
F_368 ( V_9 ) ;
F_121 ( V_155 ) ;
}
static void F_369 ( struct V_209 * V_210 )
{
struct V_788 * V_212 =
F_117 ( V_210 , struct V_788 , V_212 ) ;
F_119 ( & V_212 -> V_2 -> V_213 ) ;
F_139 ( V_212 -> V_791 ) ;
F_331 ( & V_212 -> V_792 -> V_52 ) ;
F_331 ( & V_212 -> V_791 -> V_52 ) ;
F_129 ( V_212 -> V_2 ) ;
F_120 ( & V_212 -> V_2 -> V_213 ) ;
F_121 ( V_212 ) ;
}
static void F_370 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
struct V_788 * V_212 ;
struct V_153 * V_154 ;
struct V_793 * V_794 ;
struct V_795 V_796 , V_797 ;
unsigned long V_233 ;
if ( V_155 == NULL )
return;
F_371 ( & V_796 ) ;
F_365 ( & V_2 -> V_789 , V_233 ) ;
V_212 = V_155 -> V_790 ;
if ( V_212 == NULL || ! V_212 -> V_798 ) {
F_366 ( & V_2 -> V_789 , V_233 ) ;
return;
}
V_155 -> V_790 = NULL ;
if ( V_212 -> V_799 ) {
V_794 = V_212 -> V_799 ;
V_794 -> V_799 . V_800 = F_372 ( V_2 , V_155 -> V_66 , & V_797 ) ;
if ( 10 * ( F_373 ( & V_796 ) - F_373 ( & V_797 ) ) >
9 * V_9 -> V_801 ) {
V_794 -> V_799 . V_800 ++ ;
V_797 = F_374 ( F_373 ( & V_797 ) +
V_9 -> V_801 ) ;
}
V_794 -> V_799 . V_802 = V_797 . V_802 ;
V_794 -> V_799 . V_803 = V_797 . V_803 ;
F_375 ( & V_794 -> V_52 . V_804 ,
& V_794 -> V_52 . V_805 -> V_806 ) ;
F_376 ( & V_794 -> V_52 . V_805 -> V_807 ) ;
}
F_377 ( V_2 , V_155 -> V_66 ) ;
F_366 ( & V_2 -> V_789 , V_233 ) ;
V_154 = V_212 -> V_791 ;
F_378 ( 1 << V_155 -> V_99 ,
& V_154 -> V_277 . V_808 ) ;
if ( F_149 ( & V_154 -> V_277 ) == 0 )
F_379 ( & V_4 -> V_275 ) ;
F_380 ( & V_212 -> V_212 ) ;
F_381 ( V_155 -> V_99 , V_212 -> V_792 ) ;
}
void F_382 ( struct V_1 * V_2 , int V_66 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = V_4 -> V_809 [ V_66 ] ;
F_370 ( V_2 , V_9 ) ;
}
void F_383 ( struct V_1 * V_2 , int V_99 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = V_4 -> V_810 [ V_99 ] ;
F_370 ( V_2 , V_9 ) ;
}
void F_384 ( struct V_1 * V_2 , int V_99 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 =
F_102 ( V_4 -> V_810 [ V_99 ] ) ;
unsigned long V_233 ;
F_365 ( & V_2 -> V_789 , V_233 ) ;
if ( V_155 -> V_790 ) {
if ( ( ++ V_155 -> V_790 -> V_798 ) > 1 )
F_83 ( L_170 ) ;
} else {
F_304 ( L_171 ) ;
}
F_366 ( & V_2 -> V_789 , V_233 ) ;
}
static int F_385 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_149 * V_150 ,
struct V_153 * V_154 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
unsigned long V_811 ;
T_1 V_812 ;
int V_248 ;
V_248 = F_133 ( V_2 , V_154 , F_168 ( V_4 ) ) ;
if ( V_248 )
goto V_813;
V_811 = V_9 -> V_169 * V_150 -> V_160 [ 0 ] + V_9 -> V_256 * V_150 -> V_261 / 8 ;
V_248 = F_386 ( 6 ) ;
if ( V_248 )
goto V_813;
if ( V_155 -> V_99 )
V_812 = V_814 ;
else
V_812 = V_815 ;
F_387 ( V_816 | V_812 ) ;
F_387 ( V_817 ) ;
F_387 ( V_818 |
F_388 ( V_155 -> V_99 ) ) ;
F_387 ( V_150 -> V_160 [ 0 ] ) ;
F_387 ( V_154 -> V_202 + V_811 ) ;
F_387 ( V_817 ) ;
F_389 () ;
V_813:
return V_248 ;
}
static int F_390 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_149 * V_150 ,
struct V_153 * V_154 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
unsigned long V_811 ;
T_1 V_812 ;
int V_248 ;
V_248 = F_133 ( V_2 , V_154 , F_168 ( V_4 ) ) ;
if ( V_248 )
goto V_813;
V_811 = V_9 -> V_169 * V_150 -> V_160 [ 0 ] + V_9 -> V_256 * V_150 -> V_261 / 8 ;
V_248 = F_386 ( 6 ) ;
if ( V_248 )
goto V_813;
if ( V_155 -> V_99 )
V_812 = V_814 ;
else
V_812 = V_815 ;
F_387 ( V_816 | V_812 ) ;
F_387 ( V_817 ) ;
F_387 ( V_819 |
F_388 ( V_155 -> V_99 ) ) ;
F_387 ( V_150 -> V_160 [ 0 ] ) ;
F_387 ( V_154 -> V_202 + V_811 ) ;
F_387 ( V_817 ) ;
F_389 () ;
V_813:
return V_248 ;
}
static int F_391 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_149 * V_150 ,
struct V_153 * V_154 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
T_5 V_820 , V_821 ;
int V_248 ;
V_248 = F_133 ( V_2 , V_154 , F_168 ( V_4 ) ) ;
if ( V_248 )
goto V_813;
V_248 = F_386 ( 4 ) ;
if ( V_248 )
goto V_813;
F_387 ( V_818 |
F_388 ( V_155 -> V_99 ) ) ;
F_387 ( V_150 -> V_160 [ 0 ] ) ;
F_387 ( V_154 -> V_202 | V_154 -> V_241 ) ;
V_820 = 0 ;
V_821 = F_3 ( F_281 ( V_155 -> V_66 ) ) & 0x0fff0fff ;
F_387 ( V_820 | V_821 ) ;
F_389 () ;
V_813:
return V_248 ;
}
static int F_392 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_149 * V_150 ,
struct V_153 * V_154 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
T_5 V_820 , V_821 ;
int V_248 ;
V_248 = F_133 ( V_2 , V_154 , F_168 ( V_4 ) ) ;
if ( V_248 )
goto V_813;
V_248 = F_386 ( 4 ) ;
if ( V_248 )
goto V_813;
F_387 ( V_818 |
F_388 ( V_155 -> V_99 ) ) ;
F_387 ( V_150 -> V_160 [ 0 ] | V_154 -> V_241 ) ;
F_387 ( V_154 -> V_202 ) ;
V_820 = F_3 ( F_192 ( V_155 -> V_66 ) ) & V_348 ;
V_821 = F_3 ( F_281 ( V_155 -> V_66 ) ) & 0x0fff0fff ;
F_387 ( V_820 | V_821 ) ;
F_389 () ;
V_813:
return V_248 ;
}
static int F_393 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_149 * V_150 ,
struct V_153 * V_154 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
struct V_245 * V_321 = & V_4 -> V_321 [ V_822 ] ;
int V_248 ;
V_248 = F_133 ( V_2 , V_154 , V_321 ) ;
if ( V_248 )
goto V_813;
V_248 = F_394 ( V_321 , 4 ) ;
if ( V_248 )
goto V_813;
F_395 ( V_321 , V_819 | ( V_155 -> V_99 << 19 ) ) ;
F_395 ( V_321 , ( V_150 -> V_160 [ 0 ] | V_154 -> V_241 ) ) ;
F_395 ( V_321 , ( V_154 -> V_202 ) ) ;
F_395 ( V_321 , ( V_817 ) ) ;
F_396 ( V_321 ) ;
V_813:
return V_248 ;
}
static int F_397 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_149 * V_150 ,
struct V_153 * V_154 )
{
return - V_823 ;
}
static int F_398 ( struct V_8 * V_9 ,
struct V_149 * V_150 ,
struct V_793 * V_799 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_151 * V_152 ;
struct V_153 * V_154 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
struct V_788 * V_212 ;
unsigned long V_233 ;
int V_248 ;
V_212 = F_125 ( sizeof *V_212 , V_220 ) ;
if ( V_212 == NULL )
return - V_720 ;
V_212 -> V_799 = V_799 ;
V_212 -> V_2 = V_9 -> V_2 ;
V_152 = F_101 ( V_9 -> V_150 ) ;
V_212 -> V_791 = V_152 -> V_154 ;
F_399 ( & V_212 -> V_212 , F_369 ) ;
V_248 = F_400 ( V_2 , V_155 -> V_66 ) ;
if ( V_248 )
goto V_824;
F_365 ( & V_2 -> V_789 , V_233 ) ;
if ( V_155 -> V_790 ) {
F_366 ( & V_2 -> V_789 , V_233 ) ;
F_121 ( V_212 ) ;
F_377 ( V_2 , V_155 -> V_66 ) ;
F_304 ( L_172 ) ;
return - V_825 ;
}
V_155 -> V_790 = V_212 ;
F_366 ( & V_2 -> V_789 , V_233 ) ;
V_152 = F_101 ( V_150 ) ;
V_154 = V_152 -> V_154 ;
F_119 ( & V_2 -> V_213 ) ;
F_401 ( & V_212 -> V_791 -> V_52 ) ;
F_401 ( & V_154 -> V_52 ) ;
V_9 -> V_150 = V_150 ;
V_212 -> V_792 = V_154 ;
V_212 -> V_826 = true ;
F_402 ( 1 << V_155 -> V_99 , & V_212 -> V_791 -> V_277 ) ;
V_248 = V_4 -> V_207 . V_827 ( V_2 , V_9 , V_150 , V_154 ) ;
if ( V_248 )
goto V_828;
F_128 ( V_2 ) ;
F_120 ( & V_2 -> V_213 ) ;
F_403 ( V_155 -> V_99 , V_154 ) ;
return 0 ;
V_828:
F_404 ( 1 << V_155 -> V_99 , & V_212 -> V_791 -> V_277 ) ;
F_331 ( & V_212 -> V_791 -> V_52 ) ;
F_331 ( & V_154 -> V_52 ) ;
F_120 ( & V_2 -> V_213 ) ;
F_365 ( & V_2 -> V_789 , V_233 ) ;
V_155 -> V_790 = NULL ;
F_366 ( & V_2 -> V_789 , V_233 ) ;
F_377 ( V_2 , V_155 -> V_66 ) ;
V_824:
F_121 ( V_212 ) ;
return V_248 ;
}
static void F_405 ( struct V_1 * V_2 ,
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
static void F_406 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_155 * V_155 = F_102 ( V_9 ) ;
V_155 -> V_359 = - 1 ;
F_405 ( V_2 , V_155 -> V_66 , V_155 -> V_99 ) ;
}
static void F_407 ( struct V_1 * V_2 , int V_66 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_155 * V_155 ;
int V_101 ;
V_155 = F_125 ( sizeof( struct V_155 ) + ( V_829 * sizeof( struct V_535 * ) ) , V_220 ) ;
if ( V_155 == NULL )
return;
F_408 ( V_2 , & V_155 -> V_52 , & V_830 ) ;
F_409 ( & V_155 -> V_52 , 256 ) ;
for ( V_101 = 0 ; V_101 < 256 ; V_101 ++ ) {
V_155 -> V_685 [ V_101 ] = V_101 ;
V_155 -> V_686 [ V_101 ] = V_101 ;
V_155 -> V_687 [ V_101 ] = V_101 ;
}
V_155 -> V_66 = V_66 ;
V_155 -> V_99 = V_66 ;
if ( F_70 ( V_2 ) && F_410 ( V_2 ) ) {
F_25 ( L_173 ) ;
V_155 -> V_99 = ! V_66 ;
}
F_69 ( V_66 >= F_231 ( V_4 -> V_810 ) ||
V_4 -> V_810 [ V_155 -> V_99 ] != NULL ) ;
V_4 -> V_810 [ V_155 -> V_99 ] = & V_155 -> V_52 ;
V_4 -> V_809 [ V_155 -> V_66 ] = & V_155 -> V_52 ;
F_406 ( & V_155 -> V_52 ) ;
V_155 -> V_346 = true ;
V_155 -> V_544 = 24 ;
if ( F_8 ( V_2 ) ) {
if ( V_66 == 2 && F_147 ( V_2 ) )
V_155 -> V_352 = true ;
V_831 . V_832 = F_209 ;
V_831 . V_833 = F_210 ;
} else {
V_831 . V_832 = F_207 ;
V_831 . V_833 = F_208 ;
}
F_411 ( & V_155 -> V_52 , & V_831 ) ;
V_155 -> V_782 = false ;
F_412 ( & V_155 -> V_780 , F_359 ,
( unsigned long ) V_155 ) ;
}
int F_413 ( struct V_1 * V_2 , void * V_834 ,
struct V_714 * V_715 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_835 * V_836 = V_834 ;
struct V_837 * V_838 ;
struct V_155 * V_9 ;
if ( ! V_4 ) {
F_83 ( L_174 ) ;
return - V_251 ;
}
V_838 = F_414 ( V_2 , V_836 -> V_839 ,
V_840 ) ;
if ( ! V_838 ) {
F_83 ( L_175 ) ;
return - V_251 ;
}
V_9 = F_102 ( F_415 ( V_838 ) ) ;
V_836 -> V_66 = V_9 -> V_66 ;
return 0 ;
}
static int F_416 ( struct V_1 * V_2 , int V_841 )
{
struct V_50 * V_51 ;
int V_842 = 0 ;
int V_843 = 0 ;
F_14 (encoder, &dev->mode_config.encoder_list, base.head) {
if ( V_841 & V_51 -> V_844 )
V_842 |= ( 1 << V_843 ) ;
V_843 ++ ;
}
return V_842 ;
}
static bool F_417 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_70 ( V_2 ) )
return false ;
if ( ( F_3 ( V_288 ) & V_845 ) == 0 )
return false ;
if ( F_2 ( V_2 ) &&
( F_3 ( V_846 ) & V_847 ) )
return false ;
return true ;
}
static void F_418 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_50 * V_51 ;
bool V_848 = false ;
bool V_623 = false ;
if ( F_70 ( V_2 ) && ! F_71 ( V_2 ) )
V_623 = F_419 ( V_2 ) ;
if ( ! V_623 && ! F_8 ( V_2 ) ) {
F_23 ( V_849 , 0 ) ;
}
if ( F_8 ( V_2 ) ) {
V_848 = F_420 ( V_2 ) ;
if ( F_417 ( V_2 ) )
F_421 ( V_2 , V_288 ) ;
if ( V_848 && ( F_3 ( V_127 ) & V_845 ) )
F_421 ( V_2 , V_127 ) ;
}
F_422 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
int V_63 ;
if ( F_3 ( V_130 ) & V_850 ) {
V_63 = F_423 ( V_2 , V_851 ) ;
if ( ! V_63 )
F_424 ( V_2 , V_130 ) ;
if ( ! V_63 && ( F_3 ( V_123 ) & V_845 ) )
F_421 ( V_2 , V_123 ) ;
}
if ( F_3 ( V_131 ) & V_850 )
F_424 ( V_2 , V_131 ) ;
if ( F_3 ( V_132 ) & V_850 )
F_424 ( V_2 , V_132 ) ;
if ( F_3 ( V_125 ) & V_845 )
F_421 ( V_2 , V_125 ) ;
if ( ! V_848 && ( F_3 ( V_127 ) & V_845 ) )
F_421 ( V_2 , V_127 ) ;
} else if ( F_425 ( V_2 ) ) {
bool V_63 = false ;
if ( F_3 ( V_852 ) & V_853 ) {
F_25 ( L_176 ) ;
V_63 = F_423 ( V_2 , V_852 ) ;
if ( ! V_63 && F_426 ( V_2 ) ) {
F_25 ( L_177 ) ;
F_424 ( V_2 , V_852 ) ;
}
if ( ! V_63 && F_427 ( V_2 ) ) {
F_25 ( L_178 ) ;
F_421 ( V_2 , V_854 ) ;
}
}
if ( F_3 ( V_852 ) & V_853 ) {
F_25 ( L_179 ) ;
V_63 = F_423 ( V_2 , V_855 ) ;
}
if ( ! V_63 && ( F_3 ( V_855 ) & V_853 ) ) {
if ( F_426 ( V_2 ) ) {
F_25 ( L_180 ) ;
F_424 ( V_2 , V_855 ) ;
}
if ( F_427 ( V_2 ) ) {
F_25 ( L_181 ) ;
F_421 ( V_2 , V_856 ) ;
}
}
if ( F_427 ( V_2 ) &&
( F_3 ( V_857 ) & V_845 ) ) {
F_25 ( L_182 ) ;
F_421 ( V_2 , V_857 ) ;
}
} else if ( F_11 ( V_2 ) )
F_428 ( V_2 ) ;
if ( F_429 ( V_2 ) )
F_430 ( V_2 ) ;
F_14 (encoder, &dev->mode_config.encoder_list, base.head) {
V_51 -> V_52 . V_749 = V_51 -> V_858 ;
V_51 -> V_52 . V_859 =
F_416 ( V_2 , V_51 -> V_844 ) ;
}
F_351 ( V_2 ) ;
if ( F_8 ( V_2 ) )
F_282 ( V_2 ) ;
}
static void F_431 ( struct V_149 * V_150 )
{
struct V_151 * V_152 = F_101 ( V_150 ) ;
F_432 ( V_150 ) ;
F_332 ( & V_152 -> V_154 -> V_52 ) ;
F_121 ( V_152 ) ;
}
static int F_433 ( struct V_149 * V_150 ,
struct V_714 * V_715 ,
unsigned int * V_716 )
{
struct V_151 * V_152 = F_101 ( V_150 ) ;
struct V_153 * V_154 = V_152 -> V_154 ;
return F_434 ( V_715 , & V_154 -> V_52 , V_716 ) ;
}
int F_339 ( struct V_1 * V_2 ,
struct V_151 * V_152 ,
struct V_738 * V_739 ,
struct V_153 * V_154 )
{
int V_248 ;
if ( V_154 -> V_241 == V_250 )
return - V_251 ;
if ( V_739 -> V_160 [ 0 ] & 63 )
return - V_251 ;
switch ( V_739 -> V_742 ) {
case V_860 :
case V_861 :
case V_862 :
case V_863 :
case V_864 :
case V_865 :
case V_866 :
break;
case V_867 :
case V_868 :
case V_869 :
case V_870 :
break;
default:
F_83 ( L_183 ) ;
return - V_251 ;
}
V_248 = F_435 ( V_2 , & V_152 -> V_52 , & V_871 ) ;
if ( V_248 ) {
F_83 ( L_184 , V_248 ) ;
return V_248 ;
}
F_436 ( & V_152 -> V_52 , V_739 ) ;
V_152 -> V_154 = V_154 ;
return 0 ;
}
static struct V_149 *
F_437 ( struct V_1 * V_2 ,
struct V_714 * V_872 ,
struct V_738 * V_739 )
{
struct V_153 * V_154 ;
V_154 = F_326 ( F_327 ( V_2 , V_872 ,
V_739 -> V_873 [ 0 ] ) ) ;
if ( & V_154 -> V_52 == NULL )
return F_338 ( - V_719 ) ;
return F_337 ( V_2 , V_739 , V_154 ) ;
}
static struct V_153 *
F_438 ( struct V_1 * V_2 )
{
struct V_153 * V_874 ;
int V_248 ;
F_439 ( ! F_440 ( & V_2 -> V_213 ) ) ;
V_874 = F_344 ( V_2 , 4096 ) ;
if ( ! V_874 ) {
F_268 ( L_185 ) ;
return NULL ;
}
V_248 = F_441 ( V_874 , 4096 , true ) ;
if ( V_248 ) {
F_83 ( L_186 , V_248 ) ;
goto V_875;
}
V_248 = F_442 ( V_874 , 1 ) ;
if ( V_248 ) {
F_83 ( L_187 , V_248 ) ;
goto V_255;
}
return V_874 ;
V_255:
F_139 ( V_874 ) ;
V_875:
F_331 ( & V_874 -> V_52 ) ;
F_120 ( & V_2 -> V_213 ) ;
return NULL ;
}
bool F_443 ( struct V_1 * V_2 , T_8 V_78 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_876 ;
V_876 = F_444 ( V_877 ) ;
if ( V_876 & V_878 ) {
F_268 ( L_188 ) ;
return false ;
}
V_876 = ( V_879 << V_880 ) |
( V_78 << V_881 ) | V_882 ;
F_445 ( V_877 , V_876 ) ;
F_446 ( V_877 ) ;
V_876 |= V_878 ;
F_445 ( V_877 , V_876 ) ;
return true ;
}
void F_447 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_883 = F_3 ( V_884 ) ;
T_8 V_885 , V_886 , V_887 , V_888 ;
F_445 ( V_889 , F_3 ( V_889 ) | V_890 ) ;
F_445 ( V_891 , F_3 ( V_891 ) | V_892 ) ;
F_23 ( V_893 , 100000 ) ;
F_23 ( V_894 , 100000 ) ;
F_23 ( V_895 , 90000 ) ;
F_23 ( V_896 , 80000 ) ;
F_23 ( V_897 , 1 ) ;
V_885 = ( V_883 & V_898 ) >> V_899 ;
V_886 = ( V_883 & V_900 ) ;
V_887 = ( V_883 & V_901 ) >>
V_902 ;
V_888 = ( F_3 ( V_903 + ( V_887 * 4 ) ) & V_904 ) >>
V_905 ;
V_4 -> V_885 = V_885 ;
V_4 -> V_887 = V_887 ;
V_4 -> V_906 = V_887 ;
V_4 -> V_907 = V_886 ;
V_4 -> V_908 = V_887 ;
F_304 ( L_189 ,
V_885 , V_886 , V_887 ) ;
F_23 ( V_909 , V_910 | V_911 ) ;
F_23 ( V_912 , V_888 ) ;
F_72 ( V_912 ) ;
V_883 |= V_913 ;
F_23 ( V_884 , V_883 ) ;
if ( F_24 ( ( F_3 ( V_877 ) & V_878 ) == 0 , 10 ) )
F_83 ( L_190 ) ;
F_448 ( 1 ) ;
F_443 ( V_2 , V_887 ) ;
V_4 -> V_914 = F_3 ( 0x112e4 ) + F_3 ( 0x112e8 ) +
F_3 ( 0x112e0 ) ;
V_4 -> V_915 = F_449 ( V_74 ) ;
V_4 -> V_916 = F_3 ( 0x112f4 ) ;
F_450 ( & V_4 -> V_917 ) ;
}
void F_451 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_876 = F_444 ( V_877 ) ;
F_23 ( V_909 , F_3 ( V_909 ) & ~ V_911 ) ;
F_23 ( V_918 , V_919 ) ;
F_23 ( V_920 , F_3 ( V_920 ) & ~ V_921 ) ;
F_23 ( V_922 , V_921 ) ;
F_23 ( V_923 , F_3 ( V_923 ) | V_921 ) ;
F_443 ( V_2 , V_4 -> V_887 ) ;
F_448 ( 1 ) ;
V_876 |= V_878 ;
F_23 ( V_877 , V_876 ) ;
F_448 ( 1 ) ;
}
void F_452 ( struct V_1 * V_2 , T_8 V_78 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_924 ;
V_924 = ( V_78 & 0x3ff ) << 25 ;
F_23 ( V_925 , V_924 ) ;
}
void F_453 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_925 , 1 << 31 ) ;
F_23 ( V_926 , 0xffffffff ) ;
F_23 ( V_927 , 0 ) ;
F_454 ( & V_4 -> V_928 ) ;
V_4 -> V_929 = 0 ;
F_455 ( & V_4 -> V_928 ) ;
F_23 ( V_930 , F_3 ( V_930 ) ) ;
}
static unsigned long F_456 ( T_1 V_931 )
{
unsigned long V_932 ;
int div = ( V_931 & 0x3f0000 ) >> 16 ;
int V_933 = ( V_931 & 0x3000 ) >> 12 ;
int V_934 = ( V_931 & 0x7 ) ;
if ( ! V_934 )
return 0 ;
V_932 = ( ( div * 133333 ) / ( ( 1 << V_933 ) * V_934 ) ) ;
return V_932 ;
}
void F_457 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_935 ;
T_8 V_936 [ 16 ] ;
int V_101 ;
F_23 ( V_937 , 0 ) ;
F_72 ( V_937 ) ;
F_23 ( V_938 , 0x15040d00 ) ;
F_23 ( V_939 , 0x007f0000 ) ;
F_23 ( V_940 , 0x1e220004 ) ;
F_23 ( V_941 , 0x04000004 ) ;
for ( V_101 = 0 ; V_101 < 5 ; V_101 ++ )
F_23 ( V_942 + ( V_101 * 4 ) , 0 ) ;
for ( V_101 = 0 ; V_101 < 3 ; V_101 ++ )
F_23 ( V_943 + ( V_101 * 4 ) , 0 ) ;
for ( V_101 = 0 ; V_101 < 16 ; V_101 ++ ) {
T_1 V_944 = F_3 ( V_903 + ( V_101 * 4 ) ) ;
unsigned long V_932 = F_456 ( V_944 ) ;
unsigned long V_945 = ( V_944 & V_904 ) >>
V_905 ;
unsigned long V_78 ;
V_78 = V_945 * V_945 ;
V_78 *= ( V_932 / 1000 ) ;
V_78 *= 255 ;
V_78 /= ( 127 * 127 * 900 ) ;
if ( V_78 > 0xff )
F_83 ( L_191 , V_78 ) ;
V_936 [ V_101 ] = V_78 ;
}
V_936 [ 14 ] = 0 ;
V_936 [ 15 ] = 0 ;
for ( V_101 = 0 ; V_101 < 4 ; V_101 ++ ) {
T_1 V_78 = ( V_936 [ V_101 * 4 ] << 24 ) | ( V_936 [ ( V_101 * 4 ) + 1 ] << 16 ) |
( V_936 [ ( V_101 * 4 ) + 2 ] << 8 ) | ( V_936 [ ( V_101 * 4 ) + 3 ] ) ;
F_23 ( V_946 + ( V_101 * 4 ) , V_78 ) ;
}
F_23 ( V_947 , 0 ) ;
F_23 ( V_948 , 0 ) ;
F_23 ( V_949 , 0x00007f00 ) ;
F_23 ( V_950 , 0x0000000e ) ;
F_23 ( V_951 , 0x000e0000 ) ;
F_23 ( V_952 , 0x68000300 ) ;
F_23 ( V_953 , 0x42000000 ) ;
F_23 ( V_954 , 0x00140031 ) ;
F_23 ( V_955 , 0 ) ;
F_23 ( V_956 , 0 ) ;
for ( V_101 = 0 ; V_101 < 8 ; V_101 ++ )
F_23 ( V_957 + ( V_101 * 4 ) , 0 ) ;
F_23 ( V_937 , 0x80000019 ) ;
V_935 = F_3 ( V_958 ) ;
V_4 -> V_959 = ( V_935 & V_960 ) ;
}
static bool F_458 ( struct V_1 * V_2 )
{
if ( V_961 >= 0 )
return V_961 ;
if ( F_27 ( V_2 ) -> V_69 == 5 )
return 0 ;
if ( F_27 ( V_2 ) -> V_69 == 6 ) {
F_304 ( L_192 ) ;
return 0 ;
}
F_304 ( L_193 ) ;
return 1 ;
}
void F_459 ( struct V_3 * V_4 )
{
T_1 V_962 = F_3 ( V_963 ) ;
T_1 V_964 = F_3 ( V_965 ) ;
T_1 V_966 , V_967 = 0 ;
int V_968 , V_969 , V_970 ;
int V_101 ;
F_23 ( V_971 , 0 ) ;
F_119 ( & V_4 -> V_2 -> V_213 ) ;
F_109 ( V_4 ) ;
F_23 ( V_972 , 0 ) ;
F_23 ( V_973 , 1000 << 16 ) ;
F_23 ( V_974 , 40 << 16 | 30 ) ;
F_23 ( V_975 , 30 ) ;
F_23 ( V_976 , 125000 ) ;
F_23 ( V_977 , 25 ) ;
for ( V_101 = 0 ; V_101 < V_978 ; V_101 ++ )
F_23 ( F_460 ( V_4 -> V_321 [ V_101 ] . V_979 ) , 10 ) ;
F_23 ( V_980 , 0 ) ;
F_23 ( V_981 , 1000 ) ;
F_23 ( V_982 , 50000 ) ;
F_23 ( V_983 , 100000 ) ;
F_23 ( V_984 , 64000 ) ;
if ( F_458 ( V_4 -> V_2 ) )
V_967 = V_985 |
( ( F_461 ( V_4 -> V_2 ) ) ? V_986 : 0 ) ;
F_23 ( V_972 ,
V_967 |
F_462 ( 1 ) |
V_987 ) ;
F_23 ( V_925 ,
F_463 ( 10 ) |
F_464 ( 0 ) |
V_988 ) ;
F_23 ( V_989 ,
F_463 ( 12 ) ) ;
F_23 ( V_990 , 1000000 ) ;
F_23 ( V_991 ,
18 << 24 |
6 << 16 ) ;
F_23 ( V_992 , 10000 ) ;
F_23 ( V_993 , 1000000 ) ;
F_23 ( V_994 , 100000 ) ;
F_23 ( V_995 , 5000000 ) ;
F_23 ( V_996 , 10 ) ;
F_23 ( V_997 ,
V_998 |
V_999 |
V_1000 |
V_1001 |
V_1002 |
V_1003 ) ;
if ( F_24 ( ( F_3 ( V_1004 ) & V_1005 ) == 0 ,
500 ) )
F_83 ( L_194 ) ;
F_23 ( V_1006 , 0 ) ;
F_23 ( V_1004 ,
V_1005 |
V_1007 ) ;
if ( F_24 ( ( F_3 ( V_1004 ) & V_1005 ) == 0 ,
500 ) )
F_83 ( L_195 ) ;
V_969 = ( V_962 & 0xff0000 ) >> 16 ;
V_970 = V_962 & 0xff ;
V_968 = ( V_964 & 0xff00 ) >> 8 ;
if ( F_24 ( ( F_3 ( V_1004 ) & V_1005 ) == 0 ,
500 ) )
F_83 ( L_194 ) ;
F_23 ( V_1004 , V_1008 ) ;
V_966 = F_3 ( V_1006 ) ;
if ( F_24 ( ( F_3 ( V_1004 ) & V_1005 ) == 0 ,
500 ) )
F_83 ( L_195 ) ;
if ( V_966 & ( 1 << 31 ) ) {
V_970 = V_966 & 0xff ;
F_304 ( L_196 , V_966 * 50 ) ;
}
V_4 -> V_906 = V_970 ;
V_4 -> V_907 = V_969 ;
V_4 -> V_908 = V_968 ;
F_23 ( V_927 ,
V_1009 |
V_1010 |
V_1011 |
V_1012 |
V_1013 |
V_1014 |
V_1015 ) ;
F_454 ( & V_4 -> V_928 ) ;
F_439 ( V_4 -> V_929 != 0 ) ;
F_23 ( V_1016 , 0 ) ;
F_455 ( & V_4 -> V_928 ) ;
F_23 ( V_926 , 0 ) ;
F_110 ( V_4 ) ;
F_120 ( & V_4 -> V_2 -> V_213 ) ;
}
void F_465 ( struct V_3 * V_4 )
{
int V_969 = 15 ;
int V_1017 , V_1018 , V_1019 ;
int V_1020 = 180 ;
V_1019 = F_466 ( 0 ) ;
if ( ! V_1019 )
V_1019 = V_1021 ;
V_1019 /= 1000 ;
F_119 ( & V_4 -> V_2 -> V_213 ) ;
for ( V_1017 = V_4 -> V_906 ; V_1017 >= V_4 -> V_907 ;
V_1017 -- ) {
int V_1022 = V_4 -> V_906 - V_1017 ;
if ( V_1017 < V_969 )
V_1018 = 800 ;
else
V_1018 = V_1019 - ( ( V_1022 * V_1020 ) / 2 ) ;
V_1018 = F_467 ( V_1018 , 100 ) ;
F_23 ( V_1006 ,
( V_1018 << V_1023 ) |
V_1017 ) ;
F_23 ( V_1004 , V_1005 |
V_1007 ) ;
if ( F_24 ( ( F_3 ( V_1004 ) &
V_1005 ) == 0 , 10 ) ) {
F_83 ( L_197 ) ;
continue;
}
}
F_120 ( & V_4 -> V_2 -> V_213 ) ;
}
static void F_468 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_1024 = V_1025 ;
V_1024 |= V_1026 |
V_1027 |
V_1028 ;
V_1024 |= V_1029 ;
F_23 ( V_1030 ,
V_1031 |
V_1032 ) ;
F_23 ( V_1033 ,
V_1034 ) ;
F_23 ( V_1035 , V_1024 ) ;
F_23 ( V_1036 ,
( F_3 ( V_1036 ) |
V_1037 | V_1038 ) ) ;
F_23 ( V_1039 ,
( F_3 ( V_1039 ) |
V_1040 ) ) ;
F_23 ( V_495 ,
( F_3 ( V_495 ) |
V_496 ) ) ;
F_23 ( V_506 , 0 ) ;
F_23 ( V_507 , 0 ) ;
F_23 ( V_508 , 0 ) ;
if ( F_469 ( V_2 ) ) {
F_23 ( V_1041 ,
F_3 ( V_1041 ) |
V_1042 ) ;
F_23 ( V_1036 ,
F_3 ( V_1036 ) |
V_1037 ) ;
F_23 ( V_1039 ,
F_3 ( V_1039 ) |
V_1043 |
V_1044 |
V_1045 ) ;
}
F_23 ( V_1036 ,
F_3 ( V_1036 ) |
V_1046 ) ;
F_23 ( V_1047 ,
V_1048 << 16 |
V_1048 ) ;
}
static void F_470 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
T_5 V_1024 = V_1025 ;
F_23 ( V_1035 , V_1024 ) ;
F_23 ( V_1036 ,
F_3 ( V_1036 ) |
V_1046 ) ;
F_23 ( V_506 , 0 ) ;
F_23 ( V_507 , 0 ) ;
F_23 ( V_508 , 0 ) ;
F_23 ( V_1049 ,
V_1050 |
V_1051 ) ;
F_23 ( V_1041 ,
F_3 ( V_1041 ) |
V_1042 | V_1052 ) ;
F_23 ( V_1036 ,
F_3 ( V_1036 ) |
V_1037 | V_1038 ) ;
F_23 ( V_1039 ,
F_3 ( V_1039 ) |
V_1040 |
V_1053 ) ;
F_471 (pipe) {
F_23 ( F_50 ( V_66 ) ,
F_3 ( F_50 ( V_66 ) ) |
V_269 ) ;
F_90 ( V_4 , V_66 ) ;
}
}
static void F_472 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
T_5 V_1024 = V_1025 ;
F_23 ( V_1035 , V_1024 ) ;
F_23 ( V_506 , 0 ) ;
F_23 ( V_507 , 0 ) ;
F_23 ( V_508 , 0 ) ;
F_23 ( V_1049 , V_1054 ) ;
F_23 ( V_1039 , V_1055 ) ;
F_23 ( V_1056 ,
V_1057 |
V_1058 ) ;
F_23 ( V_1059 ,
V_1060 ) ;
F_23 ( V_1061 ,
V_1062 ) ;
F_23 ( V_1063 ,
V_1064 ) ;
F_23 ( V_1065 ,
F_3 ( V_1065 ) |
V_1066 ) ;
F_471 (pipe) {
F_23 ( F_50 ( V_66 ) ,
F_3 ( F_50 ( V_66 ) ) |
V_269 ) ;
F_90 ( V_4 , V_66 ) ;
}
}
static void F_473 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_1024 ;
F_23 ( V_1067 , 0 ) ;
F_23 ( V_1068 , V_1069 |
V_1070 |
V_1071 ) ;
F_23 ( V_1072 , 0 ) ;
V_1024 = V_1025 |
V_1073 |
V_1074 ;
if ( F_474 ( V_2 ) )
V_1024 |= V_1075 ;
F_23 ( V_1076 , V_1024 ) ;
}
static void F_475 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_1067 , V_1077 ) ;
F_23 ( V_1068 , 0 ) ;
F_23 ( V_1076 , 0 ) ;
F_23 ( V_1072 , 0 ) ;
F_445 ( V_1078 , 0 ) ;
}
static void F_476 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_1067 , V_1079 |
V_1077 |
V_1080 |
V_1081 |
V_1082 ) ;
F_23 ( V_1068 , 0 ) ;
}
static void F_477 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_1083 = F_3 ( V_1084 ) ;
V_1083 |= V_1085 | V_1086 |
V_1087 ;
F_23 ( V_1084 , V_1083 ) ;
}
static void F_478 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_1067 , V_1088 ) ;
}
static void F_479 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_1076 , V_1073 ) ;
}
static void F_480 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_1089 , V_1090 ) ;
}
static void F_481 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
F_23 ( V_1089 , V_1090 ) ;
F_23 ( V_1091 , F_3 ( V_1091 ) |
V_1092 ) ;
F_471 (pipe)
F_23 ( F_189 ( V_66 ) , V_344 ) ;
}
static void F_482 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_1093 ) {
F_139 ( V_4 -> V_1093 ) ;
F_331 ( & V_4 -> V_1093 -> V_52 ) ;
V_4 -> V_1093 = NULL ;
}
if ( V_4 -> V_1094 ) {
F_139 ( V_4 -> V_1094 ) ;
F_331 ( & V_4 -> V_1094 -> V_52 ) ;
V_4 -> V_1094 = NULL ;
}
}
static void F_483 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_3 ( V_1095 ) ) {
F_23 ( V_1096 , F_3 ( V_1096 ) | V_1097 ) ;
F_24 ( ( ( F_3 ( V_1096 ) & V_1098 ) == V_1099 ) ,
50 ) ;
F_23 ( V_1095 , 0 ) ;
F_72 ( V_1095 ) ;
F_23 ( V_1096 , F_3 ( V_1096 ) & ~ V_1097 ) ;
F_72 ( V_1096 ) ;
}
F_482 ( V_2 ) ;
}
static int F_484 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_1093 == NULL )
V_4 -> V_1093 = F_438 ( V_2 ) ;
if ( ! V_4 -> V_1093 )
return - V_720 ;
if ( V_4 -> V_1094 == NULL )
V_4 -> V_1094 = F_438 ( V_2 ) ;
if ( ! V_4 -> V_1094 ) {
F_482 ( V_2 ) ;
return - V_720 ;
}
return 0 ;
}
void F_485 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_248 ;
if ( ! F_458 ( V_2 ) )
return;
F_119 ( & V_2 -> V_213 ) ;
V_248 = F_484 ( V_2 ) ;
if ( V_248 ) {
F_120 ( & V_2 -> V_213 ) ;
return;
}
V_248 = F_386 ( 6 ) ;
if ( V_248 ) {
F_482 ( V_2 ) ;
F_120 ( & V_2 -> V_213 ) ;
return;
}
F_387 ( V_1100 | V_1101 ) ;
F_387 ( V_1102 ) ;
F_387 ( V_4 -> V_1093 -> V_202 |
V_1103 |
V_1104 |
V_1105 |
V_1106 ) ;
F_387 ( V_1100 ) ;
F_387 ( V_817 ) ;
F_387 ( V_1107 ) ;
F_389 () ;
V_248 = F_486 ( F_168 ( V_4 ) ) ;
if ( V_248 ) {
F_83 ( L_198 ) ;
F_482 ( V_2 ) ;
F_120 ( & V_2 -> V_213 ) ;
return;
}
F_23 ( V_1095 , V_4 -> V_1094 -> V_202 | V_1108 ) ;
F_23 ( V_1096 , F_3 ( V_1096 ) & ~ V_1097 ) ;
F_120 ( & V_2 -> V_213 ) ;
}
void F_487 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_207 . V_1109 ( V_2 ) ;
if ( V_4 -> V_207 . V_1110 )
V_4 -> V_207 . V_1110 ( V_2 ) ;
}
static void F_488 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_8 ( V_2 ) ) {
V_4 -> V_207 . V_360 = F_199 ;
V_4 -> V_207 . V_655 = F_284 ;
V_4 -> V_207 . V_271 = F_143 ;
} else {
V_4 -> V_207 . V_360 = F_204 ;
V_4 -> V_207 . V_655 = F_269 ;
V_4 -> V_207 . V_271 = F_140 ;
}
if ( F_130 ( V_2 ) ) {
if ( F_8 ( V_2 ) ) {
V_4 -> V_207 . V_208 = F_114 ;
V_4 -> V_207 . V_215 = F_111 ;
V_4 -> V_207 . V_221 = F_113 ;
} else if ( F_474 ( V_2 ) ) {
V_4 -> V_207 . V_208 = F_107 ;
V_4 -> V_207 . V_215 = F_105 ;
V_4 -> V_207 . V_221 = F_106 ;
} else if ( F_135 ( V_2 ) ) {
V_4 -> V_207 . V_208 = F_104 ;
V_4 -> V_207 . V_215 = F_100 ;
V_4 -> V_207 . V_221 = F_99 ;
}
}
if ( F_249 ( V_2 ) || ( F_271 ( V_2 ) && ! F_489 ( V_2 ) ) )
V_4 -> V_207 . V_591 =
F_218 ;
else if ( F_490 ( V_2 ) )
V_4 -> V_207 . V_591 =
F_219 ;
else if ( F_103 ( V_2 ) || F_322 ( V_2 ) || F_489 ( V_2 ) )
V_4 -> V_207 . V_591 =
F_220 ;
else if ( F_131 ( V_2 ) )
V_4 -> V_207 . V_591 =
F_221 ;
else if ( F_323 ( V_2 ) )
V_4 -> V_207 . V_591 =
F_223 ;
else if ( F_491 ( V_2 ) )
V_4 -> V_207 . V_591 =
F_224 ;
else
V_4 -> V_207 . V_591 =
F_225 ;
if ( F_8 ( V_2 ) ) {
V_4 -> V_207 . V_1111 = V_1112 ;
V_4 -> V_207 . V_1113 = V_1114 ;
if ( F_147 ( V_2 ) ) {
T_1 V_1115 ;
F_119 ( & V_2 -> V_213 ) ;
F_492 ( V_4 ) ;
V_1115 = F_493 ( V_1116 ) ;
F_494 ( V_4 ) ;
F_120 ( & V_2 -> V_213 ) ;
if ( V_1115 & V_1117 ) {
F_25 ( L_199 ) ;
V_4 -> V_207 . V_1111 =
F_492 ;
V_4 -> V_207 . V_1113 =
F_494 ;
}
}
if ( F_82 ( V_2 ) )
V_4 -> V_207 . V_1110 = F_480 ;
else if ( F_38 ( V_2 ) )
V_4 -> V_207 . V_1110 = F_481 ;
if ( F_2 ( V_2 ) ) {
if ( F_3 ( V_1118 ) & V_1119 )
V_4 -> V_207 . V_529 = F_254 ;
else {
F_25 ( L_200
L_201 ) ;
V_4 -> V_207 . V_529 = NULL ;
}
V_4 -> V_207 . V_326 = F_156 ;
V_4 -> V_207 . V_1109 = F_468 ;
V_4 -> V_207 . V_683 = F_305 ;
} else if ( F_112 ( V_2 ) ) {
if ( F_258 () ) {
V_4 -> V_207 . V_529 = F_257 ;
V_4 -> V_207 . V_530 = F_264 ;
} else {
F_25 ( L_202
L_201 ) ;
V_4 -> V_207 . V_529 = NULL ;
}
V_4 -> V_207 . V_326 = F_160 ;
V_4 -> V_207 . V_1109 = F_470 ;
V_4 -> V_207 . V_683 = F_305 ;
} else if ( F_147 ( V_2 ) ) {
V_4 -> V_207 . V_326 = F_161 ;
if ( F_258 () ) {
V_4 -> V_207 . V_529 = F_257 ;
V_4 -> V_207 . V_530 = F_264 ;
} else {
F_25 ( L_202
L_201 ) ;
V_4 -> V_207 . V_529 = NULL ;
}
V_4 -> V_207 . V_1109 = F_472 ;
V_4 -> V_207 . V_683 = F_305 ;
} else
V_4 -> V_207 . V_529 = NULL ;
} else if ( F_10 ( V_2 ) ) {
if ( ! F_230 ( F_239 ( V_2 ) ,
V_4 -> V_414 ,
V_4 -> V_419 ,
V_4 -> V_420 ) ) {
F_274 ( L_203
L_204
L_205 ,
( V_4 -> V_414 == 1 ) ? L_206 : L_207 ,
V_4 -> V_419 , V_4 -> V_420 ) ;
F_232 ( V_2 ) ;
V_4 -> V_207 . V_529 = NULL ;
} else
V_4 -> V_207 . V_529 = F_238 ;
V_4 -> V_207 . V_1109 = F_477 ;
} else if ( F_9 ( V_2 ) ) {
V_4 -> V_207 . V_683 = F_302 ;
V_4 -> V_207 . V_529 = F_244 ;
V_4 -> V_207 . V_1109 = F_473 ;
} else if ( F_495 ( V_2 ) ) {
V_4 -> V_207 . V_529 = F_247 ;
if ( F_135 ( V_2 ) )
V_4 -> V_207 . V_1109 = F_475 ;
else if ( F_134 ( V_2 ) )
V_4 -> V_207 . V_1109 = F_476 ;
} else if ( F_410 ( V_2 ) ) {
V_4 -> V_207 . V_529 = F_248 ;
V_4 -> V_207 . V_484 = F_233 ;
V_4 -> V_207 . V_1109 = F_477 ;
} else if ( F_323 ( V_2 ) ) {
V_4 -> V_207 . V_529 = F_251 ;
V_4 -> V_207 . V_1109 = F_478 ;
V_4 -> V_207 . V_484 = F_236 ;
} else if ( F_491 ( V_2 ) ) {
V_4 -> V_207 . V_529 = F_248 ;
V_4 -> V_207 . V_484 = F_234 ;
V_4 -> V_207 . V_1109 = F_478 ;
} else {
V_4 -> V_207 . V_529 = F_251 ;
V_4 -> V_207 . V_1109 = F_479 ;
if ( F_322 ( V_2 ) )
V_4 -> V_207 . V_484 = F_235 ;
else
V_4 -> V_207 . V_484 = F_236 ;
}
V_4 -> V_207 . V_827 = F_397 ;
switch ( F_27 ( V_2 ) -> V_69 ) {
case 2 :
V_4 -> V_207 . V_827 = F_385 ;
break;
case 3 :
V_4 -> V_207 . V_827 = F_390 ;
break;
case 4 :
case 5 :
V_4 -> V_207 . V_827 = F_391 ;
break;
case 6 :
V_4 -> V_207 . V_827 = F_392 ;
break;
case 7 :
V_4 -> V_207 . V_827 = F_393 ;
break;
}
}
static void F_496 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_133 |= V_134 ;
F_304 ( L_208 ) ;
}
static void F_497 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_133 |= V_533 ;
}
static void F_498 ( struct V_1 * V_2 )
{
struct V_1120 * V_1121 = V_2 -> V_376 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < F_231 ( V_1122 ) ; V_101 ++ ) {
struct V_1123 * V_1124 = & V_1122 [ V_101 ] ;
if ( V_1121 -> V_1125 == V_1124 -> V_1125 &&
( V_1121 -> V_1126 == V_1124 -> V_1126 ||
V_1124 -> V_1126 == V_1127 ) &&
( V_1121 -> V_1128 == V_1124 -> V_1128 ||
V_1124 -> V_1128 == V_1127 ) )
V_1124 -> V_1129 ( V_2 ) ;
}
}
static void F_499 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_8 V_1130 ;
T_1 V_1131 ;
if ( F_8 ( V_2 ) )
V_1131 = V_1132 ;
else
V_1131 = V_1133 ;
F_500 ( V_2 -> V_376 , V_1134 ) ;
F_501 ( 1 , V_1135 ) ;
V_1130 = F_502 ( V_1136 ) ;
F_501 ( V_1130 | 1 << 5 , V_1136 ) ;
F_503 ( V_2 -> V_376 , V_1134 ) ;
F_73 ( 300 ) ;
F_23 ( V_1131 , V_1137 ) ;
F_72 ( V_1131 ) ;
}
void F_504 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_101 , V_248 ;
F_505 ( V_2 ) ;
V_2 -> V_49 . V_1138 = 0 ;
V_2 -> V_49 . V_1139 = 0 ;
V_2 -> V_49 . V_752 = ( void * ) & V_1140 ;
F_498 ( V_2 ) ;
F_488 ( V_2 ) ;
if ( F_11 ( V_2 ) ) {
V_2 -> V_49 . V_1141 = 2048 ;
V_2 -> V_49 . V_1142 = 2048 ;
} else if ( F_410 ( V_2 ) ) {
V_2 -> V_49 . V_1141 = 4096 ;
V_2 -> V_49 . V_1142 = 4096 ;
} else {
V_2 -> V_49 . V_1141 = 8192 ;
V_2 -> V_49 . V_1142 = 8192 ;
}
V_2 -> V_49 . V_1143 = V_2 -> V_1144 -> V_52 ;
F_25 ( L_209 ,
V_4 -> V_1145 , V_4 -> V_1145 > 1 ? L_210 : L_211 ) ;
for ( V_101 = 0 ; V_101 < V_4 -> V_1145 ; V_101 ++ ) {
F_407 ( V_2 , V_101 ) ;
V_248 = F_506 ( V_2 , V_101 ) ;
if ( V_248 )
F_25 ( L_212 , V_101 , V_248 ) ;
}
F_499 ( V_2 ) ;
F_418 ( V_2 ) ;
F_487 ( V_2 ) ;
if ( F_469 ( V_2 ) ) {
F_447 ( V_2 ) ;
F_457 ( V_2 ) ;
}
if ( F_112 ( V_2 ) || F_461 ( V_2 ) ) {
F_459 ( V_4 ) ;
F_465 ( V_4 ) ;
}
F_399 ( & V_4 -> V_784 , F_361 ) ;
F_412 ( & V_4 -> V_780 , F_355 ,
( unsigned long ) V_2 ) ;
}
void F_507 ( struct V_1 * V_2 )
{
if ( F_469 ( V_2 ) )
F_485 ( V_2 ) ;
F_508 ( V_2 ) ;
}
void F_509 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
struct V_155 * V_155 ;
F_510 ( V_2 ) ;
F_119 ( & V_2 -> V_213 ) ;
F_511 () ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_9 -> V_150 )
continue;
V_155 = F_102 ( V_9 ) ;
F_145 ( V_9 ) ;
}
F_128 ( V_2 ) ;
if ( F_469 ( V_2 ) )
F_451 ( V_2 ) ;
if ( F_112 ( V_2 ) || F_461 ( V_2 ) )
F_453 ( V_2 ) ;
if ( F_469 ( V_2 ) )
F_483 ( V_2 ) ;
F_120 ( & V_2 -> V_213 ) ;
F_512 ( V_2 ) ;
F_367 ( & V_4 -> V_1146 ) ;
F_367 ( & V_4 -> V_1147 ) ;
F_513 () ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
V_155 = F_102 ( V_9 ) ;
F_514 ( & V_155 -> V_780 ) ;
}
F_514 ( & V_4 -> V_780 ) ;
F_367 ( & V_4 -> V_784 ) ;
F_515 ( V_2 ) ;
}
struct V_368 * F_516 ( struct V_535 * V_536 )
{
return & F_517 ( V_536 ) -> V_52 ;
}
void F_518 ( struct V_1148 * V_536 ,
struct V_50 * V_51 )
{
V_536 -> V_51 = V_51 ;
F_519 ( & V_536 -> V_52 ,
& V_51 -> V_52 ) ;
}
int F_520 ( struct V_1 * V_2 , bool V_77 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_1149 ;
F_222 ( V_4 -> V_1150 , V_1151 , & V_1149 ) ;
if ( V_77 )
V_1149 &= ~ V_1152 ;
else
V_1149 |= V_1152 ;
F_521 ( V_4 -> V_1150 , V_1151 , V_1149 ) ;
return 0 ;
}
struct V_1153 *
F_522 ( struct V_1 * V_2 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_1153 * error ;
int V_101 ;
error = F_523 ( sizeof( * error ) , V_1154 ) ;
if ( error == NULL )
return NULL ;
for ( V_101 = 0 ; V_101 < 2 ; V_101 ++ ) {
error -> V_444 [ V_101 ] . V_1155 = F_3 ( F_315 ( V_101 ) ) ;
error -> V_444 [ V_101 ] . V_1156 = F_3 ( F_321 ( V_101 ) ) ;
error -> V_444 [ V_101 ] . V_52 = F_3 ( F_316 ( V_101 ) ) ;
error -> V_99 [ V_101 ] . V_1155 = F_3 ( F_50 ( V_101 ) ) ;
error -> V_99 [ V_101 ] . V_1157 = F_3 ( F_141 ( V_101 ) ) ;
error -> V_99 [ V_101 ] . V_230 = F_3 ( F_279 ( V_101 ) ) ;
error -> V_99 [ V_101 ] . V_705 = F_3 ( F_280 ( V_101 ) ) ;
error -> V_99 [ V_101 ] . V_717 = F_3 ( F_91 ( V_101 ) ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
error -> V_99 [ V_101 ] . V_1158 = F_3 ( F_92 ( V_101 ) ) ;
error -> V_99 [ V_101 ] . V_1159 = F_3 ( F_142 ( V_101 ) ) ;
}
error -> V_66 [ V_101 ] . V_1160 = F_3 ( F_28 ( V_101 ) ) ;
error -> V_66 [ V_101 ] . V_1161 = F_3 ( F_281 ( V_101 ) ) ;
error -> V_66 [ V_101 ] . V_448 = F_3 ( F_176 ( V_101 ) ) ;
error -> V_66 [ V_101 ] . V_1162 = F_3 ( F_178 ( V_101 ) ) ;
error -> V_66 [ V_101 ] . V_770 = F_3 ( F_180 ( V_101 ) ) ;
error -> V_66 [ V_101 ] . V_775 = F_3 ( F_182 ( V_101 ) ) ;
error -> V_66 [ V_101 ] . V_1163 = F_3 ( F_184 ( V_101 ) ) ;
error -> V_66 [ V_101 ] . V_772 = F_3 ( F_186 ( V_101 ) ) ;
}
return error ;
}
void
F_524 ( struct V_1164 * V_39 ,
struct V_1 * V_2 ,
struct V_1153 * error )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < 2 ; V_101 ++ ) {
F_525 ( V_39 , L_213 , V_101 ) ;
F_525 ( V_39 , L_214 , error -> V_66 [ V_101 ] . V_1160 ) ;
F_525 ( V_39 , L_215 , error -> V_66 [ V_101 ] . V_1161 ) ;
F_525 ( V_39 , L_216 , error -> V_66 [ V_101 ] . V_448 ) ;
F_525 ( V_39 , L_217 , error -> V_66 [ V_101 ] . V_1162 ) ;
F_525 ( V_39 , L_218 , error -> V_66 [ V_101 ] . V_770 ) ;
F_525 ( V_39 , L_219 , error -> V_66 [ V_101 ] . V_775 ) ;
F_525 ( V_39 , L_220 , error -> V_66 [ V_101 ] . V_1163 ) ;
F_525 ( V_39 , L_221 , error -> V_66 [ V_101 ] . V_772 ) ;
F_525 ( V_39 , L_222 , V_101 ) ;
F_525 ( V_39 , L_223 , error -> V_99 [ V_101 ] . V_1155 ) ;
F_525 ( V_39 , L_224 , error -> V_99 [ V_101 ] . V_1157 ) ;
F_525 ( V_39 , L_225 , error -> V_99 [ V_101 ] . V_230 ) ;
F_525 ( V_39 , L_226 , error -> V_99 [ V_101 ] . V_705 ) ;
F_525 ( V_39 , L_227 , error -> V_99 [ V_101 ] . V_717 ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
F_525 ( V_39 , L_228 , error -> V_99 [ V_101 ] . V_1158 ) ;
F_525 ( V_39 , L_229 , error -> V_99 [ V_101 ] . V_1159 ) ;
}
F_525 ( V_39 , L_230 , V_101 ) ;
F_525 ( V_39 , L_223 , error -> V_444 [ V_101 ] . V_1155 ) ;
F_525 ( V_39 , L_226 , error -> V_444 [ V_101 ] . V_1156 ) ;
F_525 ( V_39 , L_231 , error -> V_444 [ V_101 ] . V_52 ) ;
}
}
