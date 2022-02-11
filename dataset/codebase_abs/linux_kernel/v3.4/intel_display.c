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
int V_55 , int V_10 , T_3 * V_56 ,
T_3 * V_57 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 clock ;
int V_58 = V_55 ;
if ( F_5 ( V_9 , V_12 ) &&
( F_3 ( V_24 ) ) != 0 ) {
if ( ( F_3 ( V_24 ) & V_14 ) ==
V_15 )
clock . V_43 = V_11 -> V_43 . V_59 ;
else
clock . V_43 = V_11 -> V_43 . V_60 ;
} else {
if ( V_55 < V_11 -> V_43 . V_61 )
clock . V_43 = V_11 -> V_43 . V_60 ;
else
clock . V_43 = V_11 -> V_43 . V_59 ;
}
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
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
int V_62 ;
F_13 ( V_2 , V_10 , & clock ) ;
if ( ! F_15 ( V_2 , V_11 ,
& clock ) )
continue;
if ( V_56 &&
clock . V_41 != V_56 -> V_41 )
continue;
V_62 = abs ( clock . V_46 - V_55 ) ;
if ( V_62 < V_58 ) {
* V_57 = clock ;
V_58 = V_62 ;
}
}
}
}
}
return ( V_58 != V_55 ) ;
}
static bool
F_18 ( const T_2 * V_11 , struct V_8 * V_9 ,
int V_55 , int V_10 , T_3 * V_56 ,
T_3 * V_57 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 clock ;
int V_63 ;
bool V_64 ;
int V_65 = ( V_55 >> 8 ) + ( V_55 >> 9 ) ;
V_64 = false ;
if ( F_5 ( V_9 , V_12 ) ) {
int V_66 ;
if ( F_8 ( V_2 ) )
V_66 = V_13 ;
else
V_66 = V_24 ;
if ( ( F_3 ( V_66 ) & V_14 ) ==
V_15 )
clock . V_43 = V_11 -> V_43 . V_59 ;
else
clock . V_43 = V_11 -> V_43 . V_60 ;
} else {
if ( V_55 < V_11 -> V_43 . V_61 )
clock . V_43 = V_11 -> V_43 . V_60 ;
else
clock . V_43 = V_11 -> V_43 . V_59 ;
}
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_63 = V_11 -> V_45 . V_54 ;
for ( clock . V_45 = V_11 -> V_45 . V_53 ; clock . V_45 <= V_63 ; clock . V_45 ++ ) {
for ( clock . V_47 = V_11 -> V_47 . V_54 ;
clock . V_47 >= V_11 -> V_47 . V_53 ; clock . V_47 -- ) {
for ( clock . V_40 = V_11 -> V_40 . V_54 ;
clock . V_40 >= V_11 -> V_40 . V_53 ; clock . V_40 -- ) {
for ( clock . V_42 = V_11 -> V_42 . V_54 ;
clock . V_42 >= V_11 -> V_42 . V_53 ; clock . V_42 -- ) {
int V_62 ;
F_13 ( V_2 , V_10 , & clock ) ;
if ( ! F_15 ( V_2 , V_11 ,
& clock ) )
continue;
if ( V_56 &&
clock . V_41 != V_56 -> V_41 )
continue;
V_62 = abs ( clock . V_46 - V_55 ) ;
if ( V_62 < V_65 ) {
* V_57 = clock ;
V_65 = V_62 ;
V_63 = clock . V_45 ;
V_64 = true ;
}
}
}
}
}
return V_64 ;
}
static bool
F_19 ( const T_2 * V_11 , struct V_8 * V_9 ,
int V_55 , int V_10 , T_3 * V_56 ,
T_3 * V_57 )
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
memcpy ( V_57 , & clock , sizeof( T_3 ) ) ;
return true ;
}
static bool
F_20 ( const T_2 * V_11 , struct V_8 * V_9 ,
int V_55 , int V_10 , T_3 * V_56 ,
T_3 * V_57 )
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
memcpy ( V_57 , & clock , sizeof( T_3 ) ) ;
return true ;
}
void F_21 ( struct V_1 * V_2 , int V_67 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_68 = F_22 ( V_67 ) ;
F_23 ( V_68 ,
F_3 ( V_68 ) | V_69 ) ;
if ( F_24 ( F_3 ( V_68 ) &
V_69 ,
50 ) )
F_25 ( L_10 ) ;
}
void F_26 ( struct V_1 * V_2 , int V_67 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_27 ( V_2 ) -> V_70 >= 4 ) {
int V_71 = F_28 ( V_67 ) ;
if ( F_24 ( ( F_3 ( V_71 ) & V_72 ) == 0 ,
100 ) )
F_25 ( L_11 ) ;
} else {
T_1 V_73 ;
int V_71 = F_29 ( V_67 ) ;
unsigned long V_74 = V_75 + F_30 ( 100 ) ;
do {
V_73 = F_3 ( V_71 ) & V_76 ;
F_31 ( 5 ) ;
} while ( ( ( F_3 ( V_71 ) & V_76 ) != V_73 ) &&
F_32 ( V_74 , V_75 ) );
if ( F_32 ( V_75 , V_74 ) )
F_25 ( L_11 ) ;
}
}
static const char * F_33 ( bool V_77 )
{
return V_77 ? L_12 : L_13 ;
}
static void F_34 ( struct V_3 * V_4 ,
enum V_67 V_67 , bool V_78 )
{
int V_71 ;
T_1 V_79 ;
bool V_80 ;
V_71 = F_35 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
V_80 = ! ! ( V_79 & V_81 ) ;
F_36 ( V_80 != V_78 ,
L_14 ,
F_33 ( V_78 ) , F_33 ( V_80 ) ) ;
}
static void F_37 ( struct V_3 * V_4 ,
enum V_67 V_67 , bool V_78 )
{
int V_71 ;
T_1 V_79 ;
bool V_80 ;
if ( F_38 ( V_4 -> V_2 ) ) {
T_1 V_82 ;
V_82 = F_3 ( V_83 ) ;
F_36 ( ! ( ( V_82 >> ( 4 * V_67 ) ) & 8 ) ,
L_15 , V_67 ) ;
V_67 = ( V_82 >> ( 4 * V_67 ) ) & 1 ;
}
V_71 = F_39 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
V_80 = ! ! ( V_79 & V_81 ) ;
F_36 ( V_80 != V_78 ,
L_16 ,
F_33 ( V_78 ) , F_33 ( V_80 ) ) ;
}
static void F_40 ( struct V_3 * V_4 ,
enum V_67 V_67 , bool V_78 )
{
int V_71 ;
T_1 V_79 ;
bool V_80 ;
V_71 = F_41 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
V_80 = ! ! ( V_79 & V_84 ) ;
F_36 ( V_80 != V_78 ,
L_17 ,
F_33 ( V_78 ) , F_33 ( V_80 ) ) ;
}
static void F_42 ( struct V_3 * V_4 ,
enum V_67 V_67 , bool V_78 )
{
int V_71 ;
T_1 V_79 ;
bool V_80 ;
V_71 = F_43 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
V_80 = ! ! ( V_79 & V_85 ) ;
F_36 ( V_80 != V_78 ,
L_18 ,
F_33 ( V_78 ) , F_33 ( V_80 ) ) ;
}
static void F_44 ( struct V_3 * V_4 ,
enum V_67 V_67 )
{
int V_71 ;
T_1 V_79 ;
if ( V_4 -> V_86 -> V_70 == 5 )
return;
V_71 = F_41 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
F_36 ( ! ( V_79 & V_87 ) , L_19 ) ;
}
static void F_45 ( struct V_3 * V_4 ,
enum V_67 V_67 )
{
int V_71 ;
T_1 V_79 ;
V_71 = F_43 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
F_36 ( ! ( V_79 & V_88 ) , L_20 ) ;
}
static void F_46 ( struct V_3 * V_4 ,
enum V_67 V_67 )
{
int V_89 , V_66 ;
T_1 V_79 ;
enum V_67 V_90 = V_91 ;
bool V_92 = true ;
if ( F_8 ( V_4 -> V_2 ) ) {
V_89 = V_93 ;
V_66 = V_13 ;
} else {
V_89 = V_94 ;
V_66 = V_24 ;
}
V_79 = F_3 ( V_89 ) ;
if ( ! ( V_79 & V_95 ) ||
( ( V_79 & V_96 ) == V_96 ) )
V_92 = false ;
if ( F_3 ( V_66 ) & V_97 )
V_90 = V_98 ;
F_36 ( V_90 == V_67 && V_92 ,
L_21 ,
F_47 ( V_67 ) ) ;
}
void F_48 ( struct V_3 * V_4 ,
enum V_67 V_67 , bool V_78 )
{
int V_71 ;
T_1 V_79 ;
bool V_80 ;
if ( V_67 == V_91 && V_4 -> V_99 & V_100 )
V_78 = true ;
V_71 = F_28 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
V_80 = ! ! ( V_79 & V_101 ) ;
F_36 ( V_80 != V_78 ,
L_22 ,
F_47 ( V_67 ) , F_33 ( V_78 ) , F_33 ( V_80 ) ) ;
}
static void F_49 ( struct V_3 * V_4 ,
enum V_102 V_102 , bool V_78 )
{
int V_71 ;
T_1 V_79 ;
bool V_80 ;
V_71 = F_50 ( V_102 ) ;
V_79 = F_3 ( V_71 ) ;
V_80 = ! ! ( V_79 & V_103 ) ;
F_36 ( V_80 != V_78 ,
L_23 ,
F_51 ( V_102 ) , F_33 ( V_78 ) , F_33 ( V_80 ) ) ;
}
static void F_52 ( struct V_3 * V_4 ,
enum V_67 V_67 )
{
int V_71 , V_104 ;
T_1 V_79 ;
int V_105 ;
if ( F_8 ( V_4 -> V_2 ) ) {
V_71 = F_50 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
F_36 ( ( V_79 & V_103 ) ,
L_24 ,
F_51 ( V_67 ) ) ;
return;
}
for ( V_104 = 0 ; V_104 < 2 ; V_104 ++ ) {
V_71 = F_50 ( V_104 ) ;
V_79 = F_3 ( V_71 ) ;
V_105 = ( V_79 & V_106 ) >>
V_107 ;
F_36 ( ( V_79 & V_103 ) && V_67 == V_105 ,
L_25 ,
F_51 ( V_104 ) , F_47 ( V_67 ) ) ;
}
}
static void F_53 ( struct V_3 * V_4 )
{
T_1 V_79 ;
bool V_77 ;
V_79 = F_3 ( V_108 ) ;
V_77 = ! ! ( V_79 & ( V_109 | V_110 |
V_111 ) ) ;
F_36 ( ! V_77 , L_26 ) ;
}
static void F_54 ( struct V_3 * V_4 ,
enum V_67 V_67 )
{
int V_71 ;
T_1 V_79 ;
bool V_77 ;
V_71 = F_55 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
V_77 = ! ! ( V_79 & V_112 ) ;
F_36 ( V_77 ,
L_27 ,
F_47 ( V_67 ) ) ;
}
static bool F_56 ( struct V_3 * V_4 ,
enum V_67 V_67 , T_1 V_113 , T_1 V_79 )
{
if ( ( V_79 & V_114 ) == 0 )
return false ;
if ( F_38 ( V_4 -> V_2 ) ) {
T_1 V_115 = F_57 ( V_67 ) ;
T_1 V_116 = F_3 ( V_115 ) ;
if ( ( V_116 & V_117 ) != V_113 )
return false ;
} else {
if ( ( V_79 & V_118 ) != ( V_67 << 30 ) )
return false ;
}
return true ;
}
static bool F_58 ( struct V_3 * V_4 ,
enum V_67 V_67 , T_1 V_79 )
{
if ( ( V_79 & V_119 ) == 0 )
return false ;
if ( F_38 ( V_4 -> V_2 ) ) {
if ( ( V_79 & V_120 ) != F_59 ( V_67 ) )
return false ;
} else {
if ( ( V_79 & V_121 ) != F_60 ( V_67 ) )
return false ;
}
return true ;
}
static bool F_61 ( struct V_3 * V_4 ,
enum V_67 V_67 , T_1 V_79 )
{
if ( ( V_79 & V_122 ) == 0 )
return false ;
if ( F_38 ( V_4 -> V_2 ) ) {
if ( ( V_79 & V_120 ) != F_59 ( V_67 ) )
return false ;
} else {
if ( ( V_79 & V_123 ) != F_62 ( V_67 ) )
return false ;
}
return true ;
}
static bool F_63 ( struct V_3 * V_4 ,
enum V_67 V_67 , T_1 V_79 )
{
if ( ( V_79 & V_124 ) == 0 )
return false ;
if ( F_38 ( V_4 -> V_2 ) ) {
if ( ( V_79 & V_120 ) != F_59 ( V_67 ) )
return false ;
} else {
if ( ( V_79 & V_125 ) != F_64 ( V_67 ) )
return false ;
}
return true ;
}
static void F_65 ( struct V_3 * V_4 ,
enum V_67 V_67 , int V_71 , T_1 V_113 )
{
T_1 V_79 = F_3 ( V_71 ) ;
F_36 ( F_56 ( V_4 , V_67 , V_113 , V_79 ) ,
L_28 ,
V_71 , F_47 ( V_67 ) ) ;
}
static void F_66 ( struct V_3 * V_4 ,
enum V_67 V_67 , int V_71 )
{
T_1 V_79 = F_3 ( V_71 ) ;
F_36 ( F_58 ( V_4 , V_79 , V_67 ) ,
L_29 ,
V_71 , F_47 ( V_67 ) ) ;
}
static void F_67 ( struct V_3 * V_4 ,
enum V_67 V_67 )
{
int V_71 ;
T_1 V_79 ;
F_65 ( V_4 , V_67 , V_126 , V_127 ) ;
F_65 ( V_4 , V_67 , V_128 , V_129 ) ;
F_65 ( V_4 , V_67 , V_130 , V_131 ) ;
V_71 = V_132 ;
V_79 = F_3 ( V_71 ) ;
F_36 ( F_63 ( V_4 , V_79 , V_67 ) ,
L_30 ,
F_47 ( V_67 ) ) ;
V_71 = V_13 ;
V_79 = F_3 ( V_71 ) ;
F_36 ( F_61 ( V_4 , V_79 , V_67 ) ,
L_31 ,
F_47 ( V_67 ) ) ;
F_66 ( V_4 , V_67 , V_133 ) ;
F_66 ( V_4 , V_67 , V_134 ) ;
F_66 ( V_4 , V_67 , V_135 ) ;
}
static void F_68 ( struct V_3 * V_4 , enum V_67 V_67 )
{
int V_71 ;
T_1 V_79 ;
F_69 ( V_4 -> V_86 -> V_70 >= 5 ) ;
if ( F_70 ( V_4 -> V_2 ) && ! F_71 ( V_4 -> V_2 ) )
F_46 ( V_4 , V_67 ) ;
V_71 = F_35 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
V_79 |= V_81 ;
F_23 ( V_71 , V_79 ) ;
F_72 ( V_71 ) ;
F_73 ( 150 ) ;
F_23 ( V_71 , V_79 ) ;
F_72 ( V_71 ) ;
F_73 ( 150 ) ;
F_23 ( V_71 , V_79 ) ;
F_72 ( V_71 ) ;
F_73 ( 150 ) ;
}
static void F_74 ( struct V_3 * V_4 , enum V_67 V_67 )
{
int V_71 ;
T_1 V_79 ;
if ( V_67 == V_91 && ( V_4 -> V_99 & V_100 ) )
return;
F_75 ( V_4 , V_67 ) ;
V_71 = F_35 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
V_79 &= ~ V_81 ;
F_23 ( V_71 , V_79 ) ;
F_72 ( V_71 ) ;
}
static void F_76 ( struct V_3 * V_4 ,
enum V_67 V_67 )
{
int V_71 ;
T_1 V_79 ;
if ( V_67 > 1 )
return;
F_69 ( V_4 -> V_86 -> V_70 < 5 ) ;
F_53 ( V_4 ) ;
V_71 = F_39 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
V_79 |= V_81 ;
F_23 ( V_71 , V_79 ) ;
F_72 ( V_71 ) ;
F_73 ( 200 ) ;
}
static void F_77 ( struct V_3 * V_4 ,
enum V_67 V_67 )
{
int V_71 ;
T_1 V_79 , V_136 = V_137 | V_138 ,
V_139 = V_137 ;
if ( V_67 > 1 )
return;
F_69 ( V_4 -> V_86 -> V_70 < 5 ) ;
F_54 ( V_4 , V_67 ) ;
if ( V_67 == 0 )
V_139 |= V_140 ;
else if ( V_67 == 1 )
V_139 |= V_138 ;
if ( ( F_3 ( V_83 ) & V_136 ) == V_139 )
return;
V_71 = F_39 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
V_79 &= ~ V_81 ;
F_23 ( V_71 , V_79 ) ;
F_72 ( V_71 ) ;
F_73 ( 200 ) ;
}
static void F_78 ( struct V_3 * V_4 ,
enum V_67 V_67 )
{
int V_71 ;
T_1 V_79 , V_141 ;
struct V_8 * V_9 = V_4 -> V_142 [ V_67 ] ;
F_69 ( V_4 -> V_86 -> V_70 < 5 ) ;
F_79 ( V_4 , V_67 ) ;
F_80 ( V_4 , V_67 ) ;
F_81 ( V_4 , V_67 ) ;
V_71 = F_55 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
V_141 = F_3 ( F_28 ( V_67 ) ) ;
if ( F_82 ( V_4 -> V_2 ) ) {
V_79 &= ~ V_143 ;
V_79 |= V_141 & V_143 ;
}
V_79 &= ~ V_144 ;
if ( ( V_141 & V_145 ) == V_146 )
if ( F_82 ( V_4 -> V_2 ) &&
F_5 ( V_9 , V_30 ) )
V_79 |= V_147 ;
else
V_79 |= V_148 ;
else
V_79 |= V_149 ;
F_23 ( V_71 , V_79 | V_112 ) ;
if ( F_24 ( F_3 ( V_71 ) & V_150 , 100 ) )
F_83 ( L_32 , V_67 ) ;
}
static void F_84 ( struct V_3 * V_4 ,
enum V_67 V_67 )
{
int V_71 ;
T_1 V_79 ;
F_85 ( V_4 , V_67 ) ;
F_86 ( V_4 , V_67 ) ;
F_67 ( V_4 , V_67 ) ;
V_71 = F_55 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
V_79 &= ~ V_112 ;
F_23 ( V_71 , V_79 ) ;
if ( F_24 ( ( F_3 ( V_71 ) & V_150 ) == 0 , 50 ) )
F_83 ( L_33 , V_67 ) ;
}
static void F_87 ( struct V_3 * V_4 , enum V_67 V_67 ,
bool V_151 )
{
int V_71 ;
T_1 V_79 ;
if ( ! F_8 ( V_4 -> V_2 ) )
F_88 ( V_4 , V_67 ) ;
else {
if ( V_151 ) {
F_45 ( V_4 , V_67 ) ;
F_44 ( V_4 , V_67 ) ;
}
}
V_71 = F_28 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
if ( V_79 & V_101 )
return;
F_23 ( V_71 , V_79 | V_101 ) ;
F_21 ( V_4 -> V_2 , V_67 ) ;
}
static void F_89 ( struct V_3 * V_4 ,
enum V_67 V_67 )
{
int V_71 ;
T_1 V_79 ;
F_52 ( V_4 , V_67 ) ;
if ( V_67 == V_91 && ( V_4 -> V_99 & V_100 ) )
return;
V_71 = F_28 ( V_67 ) ;
V_79 = F_3 ( V_71 ) ;
if ( ( V_79 & V_101 ) == 0 )
return;
F_23 ( V_71 , V_79 & ~ V_101 ) ;
F_26 ( V_4 -> V_2 , V_67 ) ;
}
static void F_90 ( struct V_3 * V_4 ,
enum V_102 V_102 )
{
F_23 ( F_91 ( V_102 ) , F_3 ( F_91 ( V_102 ) ) ) ;
F_23 ( F_92 ( V_102 ) , F_3 ( F_92 ( V_102 ) ) ) ;
}
static void F_93 ( struct V_3 * V_4 ,
enum V_102 V_102 , enum V_67 V_67 )
{
int V_71 ;
T_1 V_79 ;
F_94 ( V_4 , V_67 ) ;
V_71 = F_50 ( V_102 ) ;
V_79 = F_3 ( V_71 ) ;
if ( V_79 & V_103 )
return;
F_23 ( V_71 , V_79 | V_103 ) ;
F_90 ( V_4 , V_102 ) ;
F_21 ( V_4 -> V_2 , V_67 ) ;
}
static void F_95 ( struct V_3 * V_4 ,
enum V_102 V_102 , enum V_67 V_67 )
{
int V_71 ;
T_1 V_79 ;
V_71 = F_50 ( V_102 ) ;
V_79 = F_3 ( V_71 ) ;
if ( ( V_79 & V_103 ) == 0 )
return;
F_23 ( V_71 , V_79 & ~ V_103 ) ;
F_90 ( V_4 , V_102 ) ;
F_21 ( V_4 -> V_2 , V_67 ) ;
}
static void F_96 ( struct V_3 * V_4 ,
enum V_67 V_67 , int V_71 , T_1 V_113 )
{
T_1 V_79 = F_3 ( V_71 ) ;
if ( F_56 ( V_4 , V_67 , V_113 , V_79 ) ) {
F_25 ( L_34 , V_71 , V_67 ) ;
F_23 ( V_71 , V_79 & ~ V_114 ) ;
}
}
static void F_97 ( struct V_3 * V_4 ,
enum V_67 V_67 , int V_71 )
{
T_1 V_79 = F_3 ( V_71 ) ;
if ( F_58 ( V_4 , V_79 , V_67 ) ) {
F_25 ( L_35 ,
V_71 , V_67 ) ;
F_23 ( V_71 , V_79 & ~ V_119 ) ;
}
}
static void F_98 ( struct V_3 * V_4 ,
enum V_67 V_67 )
{
T_1 V_71 , V_79 ;
V_79 = F_3 ( V_93 ) ;
F_23 ( V_93 , V_79 | V_96 ) ;
F_96 ( V_4 , V_67 , V_126 , V_127 ) ;
F_96 ( V_4 , V_67 , V_128 , V_129 ) ;
F_96 ( V_4 , V_67 , V_130 , V_131 ) ;
V_71 = V_132 ;
V_79 = F_3 ( V_71 ) ;
if ( F_63 ( V_4 , V_79 , V_67 ) )
F_23 ( V_71 , V_79 & ~ V_124 ) ;
V_71 = V_13 ;
V_79 = F_3 ( V_71 ) ;
if ( F_61 ( V_4 , V_79 , V_67 ) ) {
F_25 ( L_36 , V_67 , V_79 ) ;
F_23 ( V_71 , V_79 & ~ V_122 ) ;
F_72 ( V_71 ) ;
F_73 ( 100 ) ;
}
F_97 ( V_4 , V_67 , V_133 ) ;
F_97 ( V_4 , V_67 , V_134 ) ;
F_97 ( V_4 , V_67 , V_135 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_152 ;
V_152 = F_3 ( V_153 ) ;
if ( ( V_152 & V_154 ) == 0 )
return;
V_152 &= ~ V_154 ;
F_23 ( V_153 , V_152 ) ;
if ( F_24 ( ( F_3 ( V_155 ) & V_156 ) == 0 , 10 ) ) {
F_25 ( L_37 ) ;
return;
}
F_25 ( L_38 ) ;
}
static void F_100 ( struct V_8 * V_9 , unsigned long V_157 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_158 * V_159 = V_9 -> V_159 ;
struct V_160 * V_161 = F_101 ( V_159 ) ;
struct V_162 * V_163 = V_161 -> V_163 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_165 ;
int V_102 , V_104 ;
T_1 V_152 , V_166 ;
V_165 = V_4 -> V_167 / V_168 ;
if ( V_159 -> V_169 [ 0 ] < V_165 )
V_165 = V_159 -> V_169 [ 0 ] ;
V_165 = ( V_165 / 64 ) - 1 ;
V_102 = V_164 -> V_102 == 0 ? V_170 : V_171 ;
for ( V_104 = 0 ; V_104 < ( V_168 / 32 ) + 1 ; V_104 ++ )
F_23 ( V_172 + ( V_104 * 4 ) , 0 ) ;
V_166 = V_173 | V_174 | V_175 ;
V_166 |= V_102 ;
F_23 ( V_176 , V_166 ) ;
F_23 ( V_177 , V_9 -> V_178 ) ;
V_152 = V_154 | V_179 ;
if ( F_103 ( V_2 ) )
V_152 |= V_180 ;
V_152 |= ( V_165 & 0xff ) << V_181 ;
V_152 |= ( V_157 & 0x2fff ) << V_182 ;
V_152 |= V_163 -> V_183 ;
F_23 ( V_153 , V_152 ) ;
F_25 ( L_39 ,
V_165 , V_9 -> V_178 , V_164 -> V_102 ) ;
}
static bool F_104 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_153 ) & V_154 ;
}
static void F_105 ( struct V_8 * V_9 , unsigned long V_157 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_158 * V_159 = V_9 -> V_159 ;
struct V_160 * V_161 = F_101 ( V_159 ) ;
struct V_162 * V_163 = V_161 -> V_163 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_102 = V_164 -> V_102 == 0 ? V_184 : V_185 ;
unsigned long V_186 = 200 ;
T_1 V_187 ;
V_187 = V_102 | V_188 | V_189 ;
V_187 |= V_190 | V_163 -> V_183 ;
F_23 ( V_191 , V_192 ) ;
F_23 ( V_193 , V_194 |
( V_186 << V_195 ) |
( V_157 << V_196 ) ) ;
F_23 ( V_197 , V_9 -> V_178 ) ;
F_23 ( V_198 , F_3 ( V_198 ) | V_199 ) ;
F_25 ( L_40 , V_164 -> V_102 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_187 ;
V_187 = F_3 ( V_198 ) ;
if ( V_187 & V_199 ) {
V_187 &= ~ V_199 ;
F_23 ( V_198 , V_187 ) ;
F_25 ( L_38 ) ;
}
}
static bool F_107 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_198 ) & V_199 ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_200 ;
F_109 ( V_4 ) ;
V_200 = F_3 ( V_201 ) ;
V_200 |= V_202 <<
V_203 ;
F_23 ( V_201 , V_200 ) ;
V_200 |= V_202 ;
F_23 ( V_201 , V_200 ) ;
V_200 &= ~ ( V_202 <<
V_203 ) ;
F_23 ( V_201 , V_200 ) ;
F_72 ( V_201 ) ;
F_110 ( V_4 ) ;
}
static void F_111 ( struct V_8 * V_9 , unsigned long V_157 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_158 * V_159 = V_9 -> V_159 ;
struct V_160 * V_161 = F_101 ( V_159 ) ;
struct V_162 * V_163 = V_161 -> V_163 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_102 = V_164 -> V_102 == 0 ? V_184 : V_185 ;
unsigned long V_186 = 200 ;
T_1 V_187 ;
V_187 = F_3 ( V_204 ) ;
V_187 &= V_205 ;
V_187 |= ( V_102 | V_189 ) ;
V_187 |= V_206 ;
V_187 |= ( V_190 | V_163 -> V_183 ) ;
F_23 ( V_207 , V_192 ) ;
F_23 ( V_208 , V_194 |
( V_186 << V_195 ) |
( V_157 << V_196 ) ) ;
F_23 ( V_209 , V_9 -> V_178 ) ;
F_23 ( V_210 , V_163 -> V_211 | V_212 ) ;
F_23 ( V_204 , V_187 | V_199 ) ;
if ( F_112 ( V_2 ) ) {
F_23 ( V_213 ,
V_214 | V_163 -> V_183 ) ;
F_23 ( V_215 , V_9 -> V_178 ) ;
F_108 ( V_2 ) ;
}
F_25 ( L_40 , V_164 -> V_102 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_187 ;
V_187 = F_3 ( V_204 ) ;
if ( V_187 & V_199 ) {
V_187 &= ~ V_199 ;
F_23 ( V_204 , V_187 ) ;
F_25 ( L_38 ) ;
}
}
static bool F_114 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_204 ) & V_199 ;
}
bool F_115 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_216 . V_217 )
return false ;
return V_4 -> V_216 . V_217 ( V_2 ) ;
}
static void F_116 ( struct V_218 * V_219 )
{
struct V_220 * V_221 =
F_117 ( F_118 ( V_219 ) ,
struct V_220 , V_221 ) ;
struct V_1 * V_2 = V_221 -> V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_119 ( & V_2 -> V_222 ) ;
if ( V_221 == V_4 -> V_223 ) {
if ( V_221 -> V_9 -> V_159 == V_221 -> V_159 ) {
V_4 -> V_216 . V_224 ( V_221 -> V_9 ,
V_221 -> V_157 ) ;
V_4 -> V_225 = F_102 ( V_221 -> V_9 ) -> V_102 ;
V_4 -> V_226 = V_221 -> V_9 -> V_159 -> V_52 . V_227 ;
V_4 -> V_228 = V_221 -> V_9 -> V_178 ;
}
V_4 -> V_223 = NULL ;
}
F_120 ( & V_2 -> V_222 ) ;
F_121 ( V_221 ) ;
}
static void F_122 ( struct V_3 * V_4 )
{
if ( V_4 -> V_223 == NULL )
return;
F_25 ( L_41 ) ;
if ( F_123 ( & V_4 -> V_223 -> V_221 ) )
F_121 ( V_4 -> V_223 ) ;
V_4 -> V_223 = NULL ;
}
static void F_124 ( struct V_8 * V_9 , unsigned long V_157 )
{
struct V_220 * V_221 ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_216 . V_224 )
return;
F_122 ( V_4 ) ;
V_221 = F_125 ( sizeof *V_221 , V_229 ) ;
if ( V_221 == NULL ) {
V_4 -> V_216 . V_224 ( V_9 , V_157 ) ;
return;
}
V_221 -> V_9 = V_9 ;
V_221 -> V_159 = V_9 -> V_159 ;
V_221 -> V_157 = V_157 ;
F_126 ( & V_221 -> V_221 , F_116 ) ;
V_4 -> V_223 = V_221 ;
F_25 ( L_42 ) ;
F_127 ( & V_221 -> V_221 , F_30 ( 50 ) ) ;
}
void F_128 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_122 ( V_4 ) ;
if ( ! V_4 -> V_216 . V_230 )
return;
V_4 -> V_216 . V_230 ( V_2 ) ;
V_4 -> V_225 = - 1 ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = NULL , * V_231 ;
struct V_164 * V_164 ;
struct V_158 * V_159 ;
struct V_160 * V_161 ;
struct V_162 * V_163 ;
int V_224 ;
F_25 ( L_43 ) ;
if ( ! V_232 )
return;
if ( ! F_130 ( V_2 ) )
return;
F_14 (tmp_crtc, &dev->mode_config.crtc_list, head) {
if ( V_231 -> V_77 && V_231 -> V_159 ) {
if ( V_9 ) {
F_25 ( L_44 ) ;
V_4 -> V_233 = V_234 ;
goto V_235;
}
V_9 = V_231 ;
}
}
if ( ! V_9 || V_9 -> V_159 == NULL ) {
F_25 ( L_45 ) ;
V_4 -> V_233 = V_236 ;
goto V_235;
}
V_164 = F_102 ( V_9 ) ;
V_159 = V_9 -> V_159 ;
V_161 = F_101 ( V_159 ) ;
V_163 = V_161 -> V_163 ;
V_224 = V_237 ;
if ( V_224 < 0 ) {
F_25 ( L_46 ) ;
V_224 = 1 ;
if ( F_27 ( V_2 ) -> V_70 <= 6 )
V_224 = 0 ;
}
if ( ! V_224 ) {
F_25 ( L_47 ) ;
V_4 -> V_233 = V_238 ;
goto V_235;
}
if ( V_161 -> V_163 -> V_52 . V_239 > V_4 -> V_167 ) {
F_25 ( L_48
L_49 ) ;
V_4 -> V_233 = V_240 ;
goto V_235;
}
if ( ( V_9 -> V_241 . V_242 & V_243 ) ||
( V_9 -> V_241 . V_242 & V_244 ) ) {
F_25 ( L_50
L_51 ) ;
V_4 -> V_233 = V_245 ;
goto V_235;
}
if ( ( V_9 -> V_241 . V_246 > 2048 ) ||
( V_9 -> V_241 . V_247 > 1536 ) ) {
F_25 ( L_52 ) ;
V_4 -> V_233 = V_248 ;
goto V_235;
}
if ( ( F_131 ( V_2 ) || F_103 ( V_2 ) ) && V_164 -> V_102 != 0 ) {
F_25 ( L_53 ) ;
V_4 -> V_233 = V_249 ;
goto V_235;
}
if ( V_163 -> V_250 != V_251 ||
V_163 -> V_183 == V_252 ) {
F_25 ( L_54 ) ;
V_4 -> V_233 = V_253 ;
goto V_235;
}
if ( F_132 () )
goto V_235;
if ( V_4 -> V_225 == V_164 -> V_102 &&
V_4 -> V_226 == V_159 -> V_52 . V_227 &&
V_4 -> V_228 == V_9 -> V_178 )
return;
if ( F_115 ( V_2 ) ) {
F_25 ( L_55 ) ;
F_128 ( V_2 ) ;
}
F_124 ( V_9 , 500 ) ;
return;
V_235:
if ( F_115 ( V_2 ) ) {
F_25 ( L_56 ) ;
F_128 ( V_2 ) ;
}
}
int
F_133 ( struct V_1 * V_2 ,
struct V_162 * V_163 ,
struct V_254 * V_255 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_256 ;
int V_257 ;
switch ( V_163 -> V_250 ) {
case V_258 :
if ( F_134 ( V_2 ) || F_135 ( V_2 ) )
V_256 = 128 * 1024 ;
else if ( F_27 ( V_2 ) -> V_70 >= 4 )
V_256 = 4 * 1024 ;
else
V_256 = 64 * 1024 ;
break;
case V_251 :
V_256 = 0 ;
break;
case V_259 :
F_83 ( L_57 ) ;
return - V_260 ;
default:
F_136 () ;
}
V_4 -> V_261 . V_262 = false ;
V_257 = F_137 ( V_163 , V_256 , V_255 ) ;
if ( V_257 )
goto V_263;
if ( V_163 -> V_250 != V_258 ) {
V_257 = F_138 ( V_163 , V_255 ) ;
if ( V_257 )
goto V_264;
F_139 ( V_163 ) ;
}
V_4 -> V_261 . V_262 = true ;
return 0 ;
V_264:
F_140 ( V_163 ) ;
V_263:
V_4 -> V_261 . V_262 = true ;
return V_257 ;
}
void F_141 ( struct V_162 * V_163 )
{
F_142 ( V_163 ) ;
F_140 ( V_163 ) ;
}
static int F_143 ( struct V_8 * V_9 , struct V_158 * V_159 ,
int V_265 , int V_178 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
struct V_160 * V_161 ;
struct V_162 * V_163 ;
int V_102 = V_164 -> V_102 ;
unsigned long V_266 , V_267 ;
T_1 V_268 ;
T_1 V_71 ;
switch ( V_102 ) {
case 0 :
case 1 :
break;
default:
F_83 ( L_58 , V_102 ) ;
return - V_260 ;
}
V_161 = F_101 ( V_159 ) ;
V_163 = V_161 -> V_163 ;
V_71 = F_50 ( V_102 ) ;
V_268 = F_3 ( V_71 ) ;
V_268 &= ~ V_269 ;
switch ( V_159 -> V_270 ) {
case 8 :
V_268 |= V_271 ;
break;
case 16 :
if ( V_159 -> V_272 == 15 )
V_268 |= V_273 ;
else
V_268 |= V_274 ;
break;
case 24 :
case 32 :
V_268 |= V_275 ;
break;
default:
F_83 ( L_59 , V_159 -> V_270 ) ;
return - V_260 ;
}
if ( F_27 ( V_2 ) -> V_70 >= 4 ) {
if ( V_163 -> V_250 != V_258 )
V_268 |= V_276 ;
else
V_268 &= ~ V_276 ;
}
F_23 ( V_71 , V_268 ) ;
V_266 = V_163 -> V_211 ;
V_267 = V_178 * V_159 -> V_169 [ 0 ] + V_265 * ( V_159 -> V_270 / 8 ) ;
F_25 ( L_60 ,
V_266 , V_267 , V_265 , V_178 , V_159 -> V_169 [ 0 ] ) ;
F_23 ( F_144 ( V_102 ) , V_159 -> V_169 [ 0 ] ) ;
if ( F_27 ( V_2 ) -> V_70 >= 4 ) {
F_23 ( F_92 ( V_102 ) , V_266 ) ;
F_23 ( F_145 ( V_102 ) , ( V_178 << 16 ) | V_265 ) ;
F_23 ( F_91 ( V_102 ) , V_267 ) ;
} else
F_23 ( F_91 ( V_102 ) , V_266 + V_267 ) ;
F_72 ( V_71 ) ;
return 0 ;
}
static int F_146 ( struct V_8 * V_9 ,
struct V_158 * V_159 , int V_265 , int V_178 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
struct V_160 * V_161 ;
struct V_162 * V_163 ;
int V_102 = V_164 -> V_102 ;
unsigned long V_266 , V_267 ;
T_1 V_268 ;
T_1 V_71 ;
switch ( V_102 ) {
case 0 :
case 1 :
case 2 :
break;
default:
F_83 ( L_58 , V_102 ) ;
return - V_260 ;
}
V_161 = F_101 ( V_159 ) ;
V_163 = V_161 -> V_163 ;
V_71 = F_50 ( V_102 ) ;
V_268 = F_3 ( V_71 ) ;
V_268 &= ~ V_269 ;
switch ( V_159 -> V_270 ) {
case 8 :
V_268 |= V_271 ;
break;
case 16 :
if ( V_159 -> V_272 != 16 )
return - V_260 ;
V_268 |= V_274 ;
break;
case 24 :
case 32 :
if ( V_159 -> V_272 == 24 )
V_268 |= V_275 ;
else if ( V_159 -> V_272 == 30 )
V_268 |= V_277 ;
else
return - V_260 ;
break;
default:
F_83 ( L_59 , V_159 -> V_270 ) ;
return - V_260 ;
}
if ( V_163 -> V_250 != V_258 )
V_268 |= V_276 ;
else
V_268 &= ~ V_276 ;
V_268 |= V_278 ;
F_23 ( V_71 , V_268 ) ;
V_266 = V_163 -> V_211 ;
V_267 = V_178 * V_159 -> V_169 [ 0 ] + V_265 * ( V_159 -> V_270 / 8 ) ;
F_25 ( L_60 ,
V_266 , V_267 , V_265 , V_178 , V_159 -> V_169 [ 0 ] ) ;
F_23 ( F_144 ( V_102 ) , V_159 -> V_169 [ 0 ] ) ;
F_23 ( F_92 ( V_102 ) , V_266 ) ;
F_23 ( F_145 ( V_102 ) , ( V_178 << 16 ) | V_265 ) ;
F_23 ( F_91 ( V_102 ) , V_267 ) ;
F_72 ( V_71 ) ;
return 0 ;
}
static int
F_147 ( struct V_8 * V_9 , struct V_158 * V_159 ,
int V_265 , int V_178 , enum V_279 V_78 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_257 ;
V_257 = V_4 -> V_216 . V_280 ( V_9 , V_159 , V_265 , V_178 ) ;
if ( V_257 )
return V_257 ;
F_129 ( V_2 ) ;
F_148 ( V_9 ) ;
return 0 ;
}
static int
F_149 ( struct V_158 * V_281 )
{
struct V_162 * V_163 = F_101 ( V_281 ) -> V_163 ;
struct V_3 * V_4 = V_163 -> V_52 . V_2 -> V_5 ;
bool V_282 = V_4 -> V_261 . V_262 ;
int V_257 ;
F_150 ( V_4 -> V_283 ,
F_151 ( & V_4 -> V_261 . V_284 ) ||
F_151 ( & V_163 -> V_285 ) == 0 ) ;
V_4 -> V_261 . V_262 = false ;
V_257 = F_152 ( V_163 ) ;
V_4 -> V_261 . V_262 = V_282 ;
return V_257 ;
}
static int
F_153 ( struct V_8 * V_9 , int V_265 , int V_178 ,
struct V_158 * V_281 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_286 * V_287 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_257 ;
if ( ! V_9 -> V_159 ) {
F_83 ( L_61 ) ;
return 0 ;
}
switch ( V_164 -> V_102 ) {
case 0 :
case 1 :
break;
case 2 :
if ( F_154 ( V_2 ) )
break;
default:
F_83 ( L_62 ) ;
return - V_260 ;
}
F_119 ( & V_2 -> V_222 ) ;
V_257 = F_133 ( V_2 ,
F_101 ( V_9 -> V_159 ) -> V_163 ,
NULL ) ;
if ( V_257 != 0 ) {
F_120 ( & V_2 -> V_222 ) ;
F_83 ( L_63 ) ;
return V_257 ;
}
if ( V_281 )
F_149 ( V_281 ) ;
V_257 = F_147 ( V_9 , V_9 -> V_159 , V_265 , V_178 ,
V_288 ) ;
if ( V_257 ) {
F_141 ( F_101 ( V_9 -> V_159 ) -> V_163 ) ;
F_120 ( & V_2 -> V_222 ) ;
F_83 ( L_64 ) ;
return V_257 ;
}
if ( V_281 ) {
F_21 ( V_2 , V_164 -> V_67 ) ;
F_141 ( F_101 ( V_281 ) -> V_163 ) ;
}
F_120 ( & V_2 -> V_222 ) ;
if ( ! V_2 -> V_289 -> V_290 )
return 0 ;
V_287 = V_2 -> V_289 -> V_290 -> V_291 ;
if ( ! V_287 -> V_292 )
return 0 ;
if ( V_164 -> V_67 ) {
V_287 -> V_292 -> V_293 = V_265 ;
V_287 -> V_292 -> V_294 = V_178 ;
} else {
V_287 -> V_292 -> V_295 = V_265 ;
V_287 -> V_292 -> V_296 = V_178 ;
}
return 0 ;
}
static void F_155 ( struct V_8 * V_9 , int clock )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_297 ;
F_25 ( L_65 , clock ) ;
V_297 = F_3 ( V_298 ) ;
V_297 &= ~ V_299 ;
if ( clock < 200000 ) {
T_1 V_300 ;
V_297 |= V_301 ;
V_300 = F_3 ( 0x4600c ) ;
V_300 &= 0xffff0000 ;
F_23 ( 0x4600c , V_300 | 0x8124 ) ;
V_300 = F_3 ( 0x46010 ) ;
F_23 ( 0x46010 , V_300 | 1 ) ;
V_300 = F_3 ( 0x46034 ) ;
F_23 ( 0x46034 , V_300 | ( 1 << 24 ) ) ;
} else {
V_297 |= V_302 ;
}
F_23 ( V_298 , V_297 ) ;
F_72 ( V_298 ) ;
F_73 ( 500 ) ;
}
static void F_156 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
T_1 V_71 , V_300 ;
V_71 = F_41 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
if ( F_154 ( V_2 ) ) {
V_300 &= ~ V_303 ;
V_300 |= V_303 | V_304 ;
} else {
V_300 &= ~ V_305 ;
V_300 |= V_305 | V_304 ;
}
F_23 ( V_71 , V_300 ) ;
V_71 = F_43 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
if ( F_38 ( V_2 ) ) {
V_300 &= ~ V_306 ;
V_300 |= V_307 ;
} else {
V_300 &= ~ V_305 ;
V_300 |= V_305 ;
}
F_23 ( V_71 , V_300 | V_308 ) ;
F_72 ( V_71 ) ;
F_73 ( 1000 ) ;
if ( F_154 ( V_2 ) )
F_23 ( V_71 , F_3 ( V_71 ) | V_309 |
V_310 ) ;
}
static void F_157 ( struct V_1 * V_2 , int V_67 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_242 = F_3 ( V_311 ) ;
V_242 |= F_158 ( V_67 ) ;
F_23 ( V_311 , V_242 ) ;
V_242 |= F_159 ( V_67 ) ;
F_23 ( V_311 , V_242 ) ;
F_72 ( V_311 ) ;
}
static void F_160 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
int V_102 = V_164 -> V_102 ;
T_1 V_71 , V_300 , V_312 ;
F_94 ( V_4 , V_67 ) ;
F_161 ( V_4 , V_102 ) ;
V_71 = F_162 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ V_313 ;
V_300 &= ~ V_314 ;
F_23 ( V_71 , V_300 ) ;
F_3 ( V_71 ) ;
F_73 ( 150 ) ;
V_71 = F_41 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ ( 7 << 19 ) ;
V_300 |= ( V_164 -> V_315 - 1 ) << 19 ;
V_300 &= ~ V_305 ;
V_300 |= V_316 ;
F_23 ( V_71 , V_300 | V_84 ) ;
V_71 = F_43 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ V_305 ;
V_300 |= V_316 ;
F_23 ( V_71 , V_300 | V_85 ) ;
F_72 ( V_71 ) ;
F_73 ( 150 ) ;
if ( F_82 ( V_2 ) ) {
F_23 ( F_163 ( V_67 ) , V_317 ) ;
F_23 ( F_163 ( V_67 ) , V_317 |
V_318 ) ;
}
V_71 = F_164 ( V_67 ) ;
for ( V_312 = 0 ; V_312 < 5 ; V_312 ++ ) {
V_300 = F_3 ( V_71 ) ;
F_25 ( L_66 , V_300 ) ;
if ( ( V_300 & V_314 ) ) {
F_25 ( L_67 ) ;
F_23 ( V_71 , V_300 | V_314 ) ;
break;
}
}
if ( V_312 == 5 )
F_83 ( L_68 ) ;
V_71 = F_41 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ V_305 ;
V_300 |= V_319 ;
F_23 ( V_71 , V_300 ) ;
V_71 = F_43 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ V_305 ;
V_300 |= V_319 ;
F_23 ( V_71 , V_300 ) ;
F_72 ( V_71 ) ;
F_73 ( 150 ) ;
V_71 = F_164 ( V_67 ) ;
for ( V_312 = 0 ; V_312 < 5 ; V_312 ++ ) {
V_300 = F_3 ( V_71 ) ;
F_25 ( L_66 , V_300 ) ;
if ( V_300 & V_313 ) {
F_23 ( V_71 , V_300 | V_313 ) ;
F_25 ( L_69 ) ;
break;
}
}
if ( V_312 == 5 )
F_83 ( L_70 ) ;
F_25 ( L_71 ) ;
}
static void F_165 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
T_1 V_71 , V_300 , V_104 ;
V_71 = F_162 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ V_313 ;
V_300 &= ~ V_314 ;
F_23 ( V_71 , V_300 ) ;
F_72 ( V_71 ) ;
F_73 ( 150 ) ;
V_71 = F_41 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ ( 7 << 19 ) ;
V_300 |= ( V_164 -> V_315 - 1 ) << 19 ;
V_300 &= ~ V_305 ;
V_300 |= V_316 ;
V_300 &= ~ V_320 ;
V_300 |= V_321 ;
F_23 ( V_71 , V_300 | V_84 ) ;
V_71 = F_43 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
if ( F_38 ( V_2 ) ) {
V_300 &= ~ V_306 ;
V_300 |= V_322 ;
} else {
V_300 &= ~ V_305 ;
V_300 |= V_316 ;
}
F_23 ( V_71 , V_300 | V_85 ) ;
F_72 ( V_71 ) ;
F_73 ( 150 ) ;
if ( F_38 ( V_2 ) )
F_157 ( V_2 , V_67 ) ;
for ( V_104 = 0 ; V_104 < 4 ; V_104 ++ ) {
V_71 = F_41 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ V_320 ;
V_300 |= V_323 [ V_104 ] ;
F_23 ( V_71 , V_300 ) ;
F_72 ( V_71 ) ;
F_73 ( 500 ) ;
V_71 = F_164 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
F_25 ( L_66 , V_300 ) ;
if ( V_300 & V_314 ) {
F_23 ( V_71 , V_300 | V_314 ) ;
F_25 ( L_67 ) ;
break;
}
}
if ( V_104 == 4 )
F_83 ( L_68 ) ;
V_71 = F_41 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ V_305 ;
V_300 |= V_319 ;
if ( F_112 ( V_2 ) ) {
V_300 &= ~ V_320 ;
V_300 |= V_321 ;
}
F_23 ( V_71 , V_300 ) ;
V_71 = F_43 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
if ( F_38 ( V_2 ) ) {
V_300 &= ~ V_306 ;
V_300 |= V_324 ;
} else {
V_300 &= ~ V_305 ;
V_300 |= V_319 ;
}
F_23 ( V_71 , V_300 ) ;
F_72 ( V_71 ) ;
F_73 ( 150 ) ;
for ( V_104 = 0 ; V_104 < 4 ; V_104 ++ ) {
V_71 = F_41 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ V_320 ;
V_300 |= V_323 [ V_104 ] ;
F_23 ( V_71 , V_300 ) ;
F_72 ( V_71 ) ;
F_73 ( 500 ) ;
V_71 = F_164 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
F_25 ( L_66 , V_300 ) ;
if ( V_300 & V_313 ) {
F_23 ( V_71 , V_300 | V_313 ) ;
F_25 ( L_69 ) ;
break;
}
}
if ( V_104 == 4 )
F_83 ( L_70 ) ;
F_25 ( L_72 ) ;
}
static void F_166 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
T_1 V_71 , V_300 , V_104 ;
V_71 = F_162 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ V_313 ;
V_300 &= ~ V_314 ;
F_23 ( V_71 , V_300 ) ;
F_72 ( V_71 ) ;
F_73 ( 150 ) ;
V_71 = F_41 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ ( 7 << 19 ) ;
V_300 |= ( V_164 -> V_315 - 1 ) << 19 ;
V_300 &= ~ ( V_325 | V_303 ) ;
V_300 |= V_326 ;
V_300 &= ~ V_320 ;
V_300 |= V_321 ;
V_300 |= V_327 ;
F_23 ( V_71 , V_300 | V_84 ) ;
V_71 = F_43 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ V_325 ;
V_300 &= ~ V_306 ;
V_300 |= V_322 ;
V_300 |= V_327 ;
F_23 ( V_71 , V_300 | V_85 ) ;
F_72 ( V_71 ) ;
F_73 ( 150 ) ;
if ( F_38 ( V_2 ) )
F_157 ( V_2 , V_67 ) ;
for ( V_104 = 0 ; V_104 < 4 ; V_104 ++ ) {
V_71 = F_41 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ V_320 ;
V_300 |= V_323 [ V_104 ] ;
F_23 ( V_71 , V_300 ) ;
F_72 ( V_71 ) ;
F_73 ( 500 ) ;
V_71 = F_164 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
F_25 ( L_66 , V_300 ) ;
if ( V_300 & V_314 ||
( F_3 ( V_71 ) & V_314 ) ) {
F_23 ( V_71 , V_300 | V_314 ) ;
F_25 ( L_67 ) ;
break;
}
}
if ( V_104 == 4 )
F_83 ( L_68 ) ;
V_71 = F_41 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ V_303 ;
V_300 |= V_328 ;
V_300 &= ~ V_320 ;
V_300 |= V_321 ;
F_23 ( V_71 , V_300 ) ;
V_71 = F_43 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ V_306 ;
V_300 |= V_324 ;
F_23 ( V_71 , V_300 ) ;
F_72 ( V_71 ) ;
F_73 ( 150 ) ;
for ( V_104 = 0 ; V_104 < 4 ; V_104 ++ ) {
V_71 = F_41 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ V_320 ;
V_300 |= V_323 [ V_104 ] ;
F_23 ( V_71 , V_300 ) ;
F_72 ( V_71 ) ;
F_73 ( 500 ) ;
V_71 = F_164 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
F_25 ( L_66 , V_300 ) ;
if ( V_300 & V_313 ) {
F_23 ( V_71 , V_300 | V_313 ) ;
F_25 ( L_69 ) ;
break;
}
}
if ( V_104 == 4 )
F_83 ( L_70 ) ;
F_25 ( L_72 ) ;
}
static void F_167 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
T_1 V_71 , V_300 ;
F_23 ( F_168 ( V_67 ) ,
F_3 ( F_169 ( V_67 ) ) & V_329 ) ;
V_71 = F_43 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ ( ( 0x7 << 19 ) | ( 0x7 << 16 ) ) ;
V_300 |= ( V_164 -> V_315 - 1 ) << 19 ;
V_300 |= ( F_3 ( F_28 ( V_67 ) ) & V_143 ) << 11 ;
F_23 ( V_71 , V_300 | V_88 ) ;
F_72 ( V_71 ) ;
F_73 ( 200 ) ;
V_300 = F_3 ( V_71 ) ;
F_23 ( V_71 , V_300 | V_330 ) ;
F_72 ( V_71 ) ;
F_73 ( 200 ) ;
V_71 = F_41 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
if ( ( V_300 & V_87 ) == 0 ) {
F_23 ( V_71 , V_300 | V_87 ) ;
F_72 ( V_71 ) ;
F_73 ( 100 ) ;
}
}
static void F_170 ( struct V_1 * V_2 , int V_67 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_242 = F_3 ( V_311 ) ;
V_242 &= ~ ( F_159 ( V_67 ) ) ;
F_23 ( V_311 , V_242 ) ;
V_242 &= ~ ( F_158 ( V_67 ) ) ;
F_23 ( V_311 , V_242 ) ;
F_72 ( V_311 ) ;
}
static void F_171 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
T_1 V_71 , V_300 ;
V_71 = F_41 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
F_23 ( V_71 , V_300 & ~ V_84 ) ;
F_72 ( V_71 ) ;
V_71 = F_43 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ ( 0x7 << 16 ) ;
V_300 |= ( F_3 ( F_28 ( V_67 ) ) & V_143 ) << 11 ;
F_23 ( V_71 , V_300 & ~ V_85 ) ;
F_72 ( V_71 ) ;
F_73 ( 100 ) ;
if ( F_82 ( V_2 ) ) {
F_23 ( F_163 ( V_67 ) , V_317 ) ;
F_23 ( F_163 ( V_67 ) ,
F_3 ( F_163 ( V_67 ) &
~ V_318 ) ) ;
} else if ( F_38 ( V_2 ) ) {
F_170 ( V_2 , V_67 ) ;
}
V_71 = F_41 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ V_305 ;
V_300 |= V_316 ;
F_23 ( V_71 , V_300 ) ;
V_71 = F_43 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
if ( F_38 ( V_2 ) ) {
V_300 &= ~ V_306 ;
V_300 |= V_322 ;
} else {
V_300 &= ~ V_305 ;
V_300 |= V_316 ;
}
V_300 &= ~ ( 0x07 << 16 ) ;
V_300 |= ( F_3 ( F_28 ( V_67 ) ) & V_143 ) << 11 ;
F_23 ( V_71 , V_300 ) ;
F_72 ( V_71 ) ;
F_73 ( 100 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_254 * V_331 ;
T_1 V_332 ;
if ( F_11 ( V_2 ) )
return;
V_331 = F_173 ( V_4 ) ;
V_332 = F_174 ( V_331 ) ;
if ( V_332 & V_333 )
F_175 ( V_331 , V_332 ) ;
}
static void F_176 ( struct V_8 * V_9 )
{
struct V_162 * V_163 ;
struct V_3 * V_4 ;
if ( V_9 -> V_159 == NULL )
return;
V_163 = F_101 ( V_9 -> V_159 ) -> V_163 ;
V_4 = V_9 -> V_2 -> V_5 ;
F_150 ( V_4 -> V_283 ,
F_151 ( & V_163 -> V_285 ) == 0 ) ;
}
static bool F_177 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_334 :
if ( ! F_178 ( & V_51 -> V_52 ) )
return false ;
continue;
}
}
return true ;
}
static void F_179 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
T_1 V_71 , V_300 , V_335 ;
V_4 -> V_216 . V_336 ( V_9 ) ;
F_76 ( V_4 , V_67 ) ;
if ( F_38 ( V_2 ) ) {
V_335 = V_164 -> V_337 ? V_140 :
V_138 ;
V_300 = F_3 ( V_83 ) ;
if ( V_67 == 0 ) {
V_300 &= ~ ( V_338 ) ;
V_300 |= ( V_339 | V_340 ) ;
} else if ( V_67 == 1 ) {
V_300 &= ~ ( V_341 ) ;
V_300 |= ( V_342 | V_341 ) ;
} else if ( V_67 == 2 ) {
V_300 &= ~ ( V_138 ) ;
V_300 |= ( V_137 | V_335 ) ;
}
F_23 ( V_83 , V_300 ) ;
}
F_46 ( V_4 , V_67 ) ;
F_23 ( F_180 ( V_67 ) , F_3 ( F_181 ( V_67 ) ) ) ;
F_23 ( F_182 ( V_67 ) , F_3 ( F_183 ( V_67 ) ) ) ;
F_23 ( F_184 ( V_67 ) , F_3 ( F_185 ( V_67 ) ) ) ;
F_23 ( F_186 ( V_67 ) , F_3 ( F_187 ( V_67 ) ) ) ;
F_23 ( F_188 ( V_67 ) , F_3 ( F_189 ( V_67 ) ) ) ;
F_23 ( F_190 ( V_67 ) , F_3 ( F_191 ( V_67 ) ) ) ;
F_23 ( F_192 ( V_67 ) , F_3 ( F_193 ( V_67 ) ) ) ;
F_156 ( V_9 ) ;
if ( F_38 ( V_2 ) &&
( F_5 ( V_9 , V_20 ) ||
F_5 ( V_9 , V_334 ) ) ) {
T_1 V_343 = ( F_3 ( F_28 ( V_67 ) ) & V_143 ) >> 5 ;
V_71 = F_57 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ ( V_117 |
V_344 |
V_345 ) ;
V_300 |= ( V_346 |
V_347 ) ;
V_300 |= V_343 << 9 ;
if ( V_9 -> V_241 . V_242 & V_348 )
V_300 |= V_349 ;
if ( V_9 -> V_241 . V_242 & V_350 )
V_300 |= V_351 ;
switch ( F_194 ( V_9 ) ) {
case V_126 :
V_300 |= V_127 ;
break;
case V_128 :
V_300 |= V_129 ;
break;
case V_130 :
V_300 |= V_131 ;
break;
default:
F_25 ( L_73 ) ;
V_300 |= V_127 ;
break;
}
F_23 ( V_71 , V_300 ) ;
}
F_78 ( V_4 , V_67 ) ;
}
void F_195 ( struct V_1 * V_2 , int V_67 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_352 = F_29 ( V_67 ) , V_353 = F_196 ( V_67 ) ;
T_1 V_300 ;
V_300 = F_3 ( V_352 ) ;
F_73 ( 500 ) ;
if ( F_24 ( F_3 ( V_352 ) != V_300 , 5 ) ) {
F_23 ( V_353 , V_354 ) ;
F_73 ( 250 ) ;
F_23 ( V_353 , 0 ) ;
if ( F_24 ( F_3 ( V_352 ) != V_300 , 5 ) )
F_83 ( L_74 , V_67 ) ;
}
}
static void F_197 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
int V_102 = V_164 -> V_102 ;
T_1 V_300 ;
bool V_355 ;
if ( V_164 -> V_356 )
return;
V_164 -> V_356 = true ;
F_198 ( V_2 ) ;
if ( F_5 ( V_9 , V_12 ) ) {
V_300 = F_3 ( V_13 ) ;
if ( ( V_300 & V_122 ) == 0 )
F_23 ( V_13 , V_300 | V_122 ) ;
}
V_355 = F_177 ( V_9 ) ;
if ( V_355 )
F_167 ( V_9 ) ;
else
F_171 ( V_9 ) ;
if ( V_4 -> V_357 &&
( F_5 ( V_9 , V_12 ) || V_21 ) ) {
F_23 ( F_199 ( V_67 ) , V_358 | V_359 ) ;
F_23 ( F_200 ( V_67 ) , V_4 -> V_360 ) ;
F_23 ( F_201 ( V_67 ) , V_4 -> V_357 ) ;
}
F_202 ( V_9 ) ;
F_87 ( V_4 , V_67 , V_355 ) ;
F_93 ( V_4 , V_102 , V_67 ) ;
if ( V_355 )
F_179 ( V_9 ) ;
F_119 ( & V_2 -> V_222 ) ;
F_129 ( V_2 ) ;
F_120 ( & V_2 -> V_222 ) ;
F_203 ( V_9 , true ) ;
}
static void F_204 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
int V_102 = V_164 -> V_102 ;
T_1 V_71 , V_300 ;
if ( ! V_164 -> V_356 )
return;
F_176 ( V_9 ) ;
F_205 ( V_2 , V_67 ) ;
F_203 ( V_9 , false ) ;
F_95 ( V_4 , V_102 , V_67 ) ;
if ( V_4 -> V_225 == V_102 )
F_128 ( V_2 ) ;
F_89 ( V_4 , V_67 ) ;
F_23 ( F_199 ( V_67 ) , 0 ) ;
F_23 ( F_201 ( V_67 ) , 0 ) ;
F_171 ( V_9 ) ;
F_98 ( V_4 , V_67 ) ;
F_84 ( V_4 , V_67 ) ;
if ( F_38 ( V_2 ) ) {
V_71 = F_57 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
V_300 &= ~ ( V_346 | V_117 ) ;
V_300 |= V_361 ;
F_23 ( V_71 , V_300 ) ;
V_300 = F_3 ( V_83 ) ;
switch ( V_67 ) {
case 0 :
V_300 &= ~ ( V_339 | V_338 ) ;
break;
case 1 :
V_300 &= ~ ( V_342 | V_341 ) ;
break;
case 2 :
V_300 &= ~ ( V_137 | V_138 ) ;
break;
default:
F_136 () ;
}
F_23 ( V_83 , V_300 ) ;
}
if ( ! V_164 -> V_362 )
F_77 ( V_4 , V_67 ) ;
V_71 = F_43 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
F_23 ( V_71 , V_300 & ~ V_330 ) ;
V_71 = F_41 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
F_23 ( V_71 , V_300 & ~ V_87 ) ;
F_72 ( V_71 ) ;
F_73 ( 100 ) ;
V_71 = F_43 ( V_67 ) ;
V_300 = F_3 ( V_71 ) ;
F_23 ( V_71 , V_300 & ~ V_88 ) ;
F_72 ( V_71 ) ;
F_73 ( 100 ) ;
V_164 -> V_356 = false ;
F_198 ( V_2 ) ;
F_119 ( & V_2 -> V_222 ) ;
F_129 ( V_2 ) ;
F_172 ( V_2 ) ;
F_120 ( & V_2 -> V_222 ) ;
}
static void F_206 ( struct V_8 * V_9 , int V_241 )
{
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
int V_102 = V_164 -> V_102 ;
switch ( V_241 ) {
case V_363 :
case V_364 :
case V_365 :
F_25 ( L_75 , V_67 , V_102 ) ;
F_197 ( V_9 ) ;
break;
case V_366 :
F_25 ( L_76 , V_67 , V_102 ) ;
F_204 ( V_9 ) ;
break;
}
}
static void F_207 ( struct V_164 * V_164 , bool V_367 )
{
if ( ! V_367 && V_164 -> V_368 ) {
struct V_1 * V_2 = V_164 -> V_52 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_119 ( & V_2 -> V_222 ) ;
V_4 -> V_261 . V_262 = false ;
( void ) F_208 ( V_164 -> V_368 ) ;
V_4 -> V_261 . V_262 = true ;
F_120 ( & V_2 -> V_222 ) ;
}
}
static void F_209 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
int V_102 = V_164 -> V_102 ;
if ( V_164 -> V_356 )
return;
V_164 -> V_356 = true ;
F_198 ( V_2 ) ;
F_68 ( V_4 , V_67 ) ;
F_87 ( V_4 , V_67 , false ) ;
F_93 ( V_4 , V_102 , V_67 ) ;
F_202 ( V_9 ) ;
F_129 ( V_2 ) ;
F_207 ( V_164 , true ) ;
F_203 ( V_9 , true ) ;
}
static void F_210 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
int V_102 = V_164 -> V_102 ;
if ( ! V_164 -> V_356 )
return;
F_176 ( V_9 ) ;
F_205 ( V_2 , V_67 ) ;
F_207 ( V_164 , false ) ;
F_203 ( V_9 , false ) ;
if ( V_4 -> V_225 == V_102 )
F_128 ( V_2 ) ;
F_95 ( V_4 , V_102 , V_67 ) ;
F_89 ( V_4 , V_67 ) ;
F_74 ( V_4 , V_67 ) ;
V_164 -> V_356 = false ;
F_129 ( V_2 ) ;
F_198 ( V_2 ) ;
F_172 ( V_2 ) ;
}
static void F_211 ( struct V_8 * V_9 , int V_241 )
{
switch ( V_241 ) {
case V_363 :
case V_364 :
case V_365 :
F_209 ( V_9 ) ;
break;
case V_366 :
F_210 ( V_9 ) ;
break;
}
}
static void F_212 ( struct V_8 * V_9 , int V_241 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_286 * V_287 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
bool V_77 ;
if ( V_164 -> V_369 == V_241 )
return;
V_164 -> V_369 = V_241 ;
V_4 -> V_216 . V_370 ( V_9 , V_241 ) ;
if ( ! V_2 -> V_289 -> V_290 )
return;
V_287 = V_2 -> V_289 -> V_290 -> V_291 ;
if ( ! V_287 -> V_292 )
return;
V_77 = V_9 -> V_77 && V_241 != V_366 ;
switch ( V_67 ) {
case 0 :
V_287 -> V_292 -> V_371 = V_77 ? V_9 -> V_241 . V_246 : 0 ;
V_287 -> V_292 -> V_372 = V_77 ? V_9 -> V_241 . V_247 : 0 ;
break;
case 1 :
V_287 -> V_292 -> V_373 = V_77 ? V_9 -> V_241 . V_246 : 0 ;
V_287 -> V_292 -> V_374 = V_77 ? V_9 -> V_241 . V_247 : 0 ;
break;
default:
F_83 ( L_77 , F_47 ( V_67 ) ) ;
break;
}
}
static void F_213 ( struct V_8 * V_9 )
{
struct V_375 * V_376 = V_9 -> V_377 ;
struct V_1 * V_2 = V_9 -> V_2 ;
if ( V_9 -> V_159 ) {
F_119 ( & V_2 -> V_222 ) ;
F_149 ( V_9 -> V_159 ) ;
F_120 ( & V_2 -> V_222 ) ;
}
V_376 -> V_370 ( V_9 , V_366 ) ;
F_214 ( V_2 -> V_5 , F_102 ( V_9 ) -> V_102 ) ;
F_75 ( V_2 -> V_5 , F_102 ( V_9 ) -> V_67 ) ;
if ( V_9 -> V_159 ) {
F_119 ( & V_2 -> V_222 ) ;
F_141 ( F_101 ( V_9 -> V_159 ) -> V_163 ) ;
F_120 ( & V_2 -> V_222 ) ;
}
}
static void F_215 ( struct V_8 * V_9 )
{
F_210 ( V_9 ) ;
}
static void F_216 ( struct V_8 * V_9 )
{
F_209 ( V_9 ) ;
}
static void F_217 ( struct V_8 * V_9 )
{
F_204 ( V_9 ) ;
}
static void F_218 ( struct V_8 * V_9 )
{
F_197 ( V_9 ) ;
}
void F_219 ( struct V_378 * V_51 )
{
struct V_379 * V_380 = V_51 -> V_377 ;
V_380 -> V_370 ( V_51 , V_366 ) ;
}
void F_220 ( struct V_378 * V_51 )
{
struct V_379 * V_380 = V_51 -> V_377 ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_50 * V_50 = F_221 ( V_51 ) ;
struct V_164 * V_164 = F_102 ( V_50 -> V_52 . V_9 ) ;
V_380 -> V_370 ( V_51 , V_363 ) ;
if ( F_38 ( V_2 ) )
F_195 ( V_2 , V_164 -> V_67 ) ;
}
void F_222 ( struct V_378 * V_51 )
{
struct V_50 * V_50 = F_221 ( V_51 ) ;
F_223 ( V_51 ) ;
F_121 ( V_50 ) ;
}
static bool F_224 ( struct V_8 * V_9 ,
struct V_381 * V_241 ,
struct V_381 * V_382 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
if ( F_8 ( V_2 ) ) {
if ( V_241 -> clock * 3 > V_383 * 4 )
return false ;
}
if ( ! ( V_382 -> V_384 & V_385 ) )
F_225 ( V_382 , 0 ) ;
return true ;
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
T_4 V_386 = 0 ;
F_230 ( V_2 -> V_387 , V_388 , & V_386 ) ;
if ( V_386 & V_389 )
return 133000 ;
else {
switch ( V_386 & V_390 ) {
case V_391 :
return 333000 ;
default:
case V_392 :
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
T_4 V_393 = 0 ;
switch ( V_393 & V_394 ) {
case V_395 :
case V_396 :
return 200000 ;
case V_397 :
return 250000 ;
case V_398 :
return 133000 ;
}
return 0 ;
}
static int F_233 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_234 ( T_1 * V_399 , T_1 * V_400 )
{
while ( * V_399 > 0xffffff || * V_400 > 0xffffff ) {
* V_399 >>= 1 ;
* V_400 >>= 1 ;
}
}
static void
F_235 ( int V_270 , int V_401 , int V_402 ,
int V_403 , struct V_404 * V_405 )
{
V_405 -> V_406 = 64 ;
V_405 -> V_407 = V_270 * V_402 ;
V_405 -> V_408 = V_403 * V_401 * 8 ;
F_234 ( & V_405 -> V_407 , & V_405 -> V_408 ) ;
V_405 -> V_409 = V_402 ;
V_405 -> V_410 = V_403 ;
F_234 ( & V_405 -> V_409 , & V_405 -> V_410 ) ;
}
static unsigned long F_236 ( unsigned long V_411 ,
const struct V_412 * V_413 ,
int V_414 ,
int V_415 ,
unsigned long V_416 )
{
long V_417 , V_418 ;
V_417 = ( ( V_411 / 1000 ) * V_415 * V_416 ) /
1000 ;
V_417 = F_237 ( V_417 , V_413 -> V_419 ) ;
F_25 ( L_78 , V_417 ) ;
V_418 = V_414 - ( V_417 + V_413 -> V_420 ) ;
F_25 ( L_79 , V_418 ) ;
if ( V_418 > ( long ) V_413 -> V_421 )
V_418 = V_413 -> V_421 ;
if ( V_418 <= 0 )
V_418 = V_413 -> V_422 ;
return V_418 ;
}
static const struct V_423 * F_238 ( int V_424 ,
int V_425 ,
int V_426 ,
int V_427 )
{
const struct V_423 * V_428 ;
int V_104 ;
if ( V_426 == 0 || V_427 == 0 )
return NULL ;
for ( V_104 = 0 ; V_104 < F_239 ( V_429 ) ; V_104 ++ ) {
V_428 = & V_429 [ V_104 ] ;
if ( V_424 == V_428 -> V_424 &&
V_425 == V_428 -> V_425 &&
V_426 == V_428 -> V_430 && V_427 == V_428 -> V_431 )
return V_428 ;
}
F_25 ( L_80 ) ;
return NULL ;
}
static void F_240 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_432 , F_3 ( V_432 ) & ~ V_433 ) ;
}
static int F_241 ( struct V_1 * V_2 , int V_102 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_434 = F_3 ( V_435 ) ;
int V_239 ;
V_239 = V_434 & 0x7f ;
if ( V_102 )
V_239 = ( ( V_434 >> V_436 ) & 0x7f ) - V_239 ;
F_25 ( L_81 , V_434 ,
V_102 ? L_82 : L_83 , V_239 ) ;
return V_239 ;
}
static int F_242 ( struct V_1 * V_2 , int V_102 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_434 = F_3 ( V_435 ) ;
int V_239 ;
V_239 = V_434 & 0x1ff ;
if ( V_102 )
V_239 = ( ( V_434 >> V_437 ) & 0x1ff ) - V_239 ;
V_239 >>= 1 ;
F_25 ( L_81 , V_434 ,
V_102 ? L_82 : L_83 , V_239 ) ;
return V_239 ;
}
static int F_243 ( struct V_1 * V_2 , int V_102 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_434 = F_3 ( V_435 ) ;
int V_239 ;
V_239 = V_434 & 0x7f ;
V_239 >>= 2 ;
F_25 ( L_81 , V_434 ,
V_102 ? L_82 : L_83 ,
V_239 ) ;
return V_239 ;
}
static int F_244 ( struct V_1 * V_2 , int V_102 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_434 = F_3 ( V_435 ) ;
int V_239 ;
V_239 = V_434 & 0x7f ;
V_239 >>= 1 ;
F_25 ( L_81 , V_434 ,
V_102 ? L_82 : L_83 , V_239 ) ;
return V_239 ;
}
static struct V_8 * F_245 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_77 = NULL ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_9 -> V_77 && V_9 -> V_159 ) {
if ( V_77 )
return NULL ;
V_77 = V_9 ;
}
}
return V_77 ;
}
static void F_246 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
const struct V_423 * V_428 ;
T_1 V_71 ;
unsigned long V_413 ;
V_428 = F_238 ( F_247 ( V_2 ) , V_4 -> V_425 ,
V_4 -> V_430 , V_4 -> V_431 ) ;
if ( ! V_428 ) {
F_25 ( L_80 ) ;
F_240 ( V_2 ) ;
return;
}
V_9 = F_245 ( V_2 ) ;
if ( V_9 ) {
int clock = V_9 -> V_241 . clock ;
int V_415 = V_9 -> V_159 -> V_270 / 8 ;
V_413 = F_236 ( clock , & V_438 ,
V_438 . V_414 ,
V_415 , V_428 -> V_439 ) ;
V_71 = F_3 ( V_440 ) ;
V_71 &= ~ V_441 ;
V_71 |= V_413 << V_442 ;
F_23 ( V_440 , V_71 ) ;
F_25 ( L_84 , V_71 ) ;
V_413 = F_236 ( clock , & V_443 ,
V_438 . V_414 ,
V_415 , V_428 -> V_444 ) ;
V_71 = F_3 ( V_432 ) ;
V_71 &= ~ V_445 ;
V_71 |= ( V_413 & 0x3f ) << V_446 ;
F_23 ( V_432 , V_71 ) ;
V_413 = F_236 ( clock , & V_447 ,
V_447 . V_414 ,
V_415 , V_428 -> V_448 ) ;
V_71 = F_3 ( V_432 ) ;
V_71 &= ~ V_449 ;
V_71 |= V_413 & V_449 ;
F_23 ( V_432 , V_71 ) ;
V_413 = F_236 ( clock , & V_450 ,
V_447 . V_414 ,
V_415 , V_428 -> V_451 ) ;
V_71 = F_3 ( V_432 ) ;
V_71 &= ~ V_452 ;
V_71 |= ( V_413 & 0x3f ) << V_453 ;
F_23 ( V_432 , V_71 ) ;
F_25 ( L_85 , V_71 ) ;
F_23 ( V_432 ,
F_3 ( V_432 ) | V_433 ) ;
F_25 ( L_86 ) ;
} else {
F_240 ( V_2 ) ;
F_25 ( L_87 ) ;
}
}
static bool F_248 ( struct V_1 * V_2 ,
int V_102 ,
const struct V_412 * V_216 ,
int V_454 ,
const struct V_412 * V_455 ,
int V_456 ,
int * V_457 ,
int * V_458 )
{
struct V_8 * V_9 ;
int V_459 , V_246 , clock , V_415 ;
int V_460 , V_461 ;
int V_462 , V_463 ;
V_9 = F_249 ( V_2 , V_102 ) ;
if ( V_9 -> V_159 == NULL || ! V_9 -> V_77 ) {
* V_458 = V_455 -> V_420 ;
* V_457 = V_216 -> V_420 ;
return false ;
}
V_459 = V_9 -> V_241 . V_459 ;
V_246 = V_9 -> V_241 . V_246 ;
clock = V_9 -> V_241 . clock ;
V_415 = V_9 -> V_159 -> V_270 / 8 ;
V_462 = ( ( clock * V_415 / 1000 ) * V_454 ) / 1000 ;
V_463 = V_216 -> V_414 * V_216 -> V_419 - V_246 * 8 ;
if ( V_463 > 0 )
V_462 += V_463 ;
V_462 = F_237 ( V_462 , V_216 -> V_419 ) ;
* V_457 = V_462 + V_216 -> V_420 ;
if ( * V_457 > ( int ) V_216 -> V_421 )
* V_457 = V_216 -> V_421 ;
V_460 = ( ( V_459 * 1000 ) / clock ) ;
V_461 = ( V_456 / V_460 + 1000 ) / 1000 ;
V_462 = V_461 * 64 * V_415 ;
V_463 = V_455 -> V_414 * V_455 -> V_419 - V_246 * 8 ;
if ( V_463 > 0 )
V_462 += V_463 ;
V_462 = F_237 ( V_462 , V_455 -> V_419 ) ;
* V_458 = V_462 + V_455 -> V_420 ;
if ( * V_458 > ( int ) V_455 -> V_421 )
* V_458 = ( int ) V_455 -> V_421 ;
return true ;
}
static bool F_250 ( struct V_1 * V_2 ,
int V_464 , int V_458 ,
const struct V_412 * V_216 ,
const struct V_412 * V_455 )
{
F_25 ( L_88 ,
V_464 , V_458 ) ;
if ( V_464 > V_216 -> V_421 ) {
F_25 ( L_89 ,
V_464 , V_216 -> V_421 ) ;
return false ;
}
if ( V_458 > V_455 -> V_421 ) {
F_25 ( L_90 ,
V_458 , V_455 -> V_421 ) ;
return false ;
}
if ( ! ( V_464 || V_458 ) ) {
F_25 ( L_91 ) ;
return false ;
}
return true ;
}
static bool F_251 ( struct V_1 * V_2 ,
int V_102 ,
int V_416 ,
const struct V_412 * V_216 ,
const struct V_412 * V_455 ,
int * V_464 , int * V_458 )
{
struct V_8 * V_9 ;
int V_246 , V_459 , V_415 , clock ;
unsigned long V_460 ;
int V_461 , V_465 ;
int V_466 , V_467 ;
int V_462 ;
if ( ! V_416 ) {
* V_464 = * V_458 = 0 ;
return false ;
}
V_9 = F_249 ( V_2 , V_102 ) ;
V_246 = V_9 -> V_241 . V_246 ;
V_459 = V_9 -> V_241 . V_459 ;
clock = V_9 -> V_241 . clock ;
V_415 = V_9 -> V_159 -> V_270 / 8 ;
V_460 = ( V_459 * 1000 ) / clock ;
V_461 = ( V_416 / V_460 + 1000 ) / 1000 ;
V_465 = V_246 * V_415 ;
V_466 = ( ( clock * V_415 / 1000 ) * V_416 ) / 1000 ;
V_467 = V_461 * V_465 ;
V_462 = F_237 ( V_53 ( V_466 , V_467 ) , V_216 -> V_419 ) ;
* V_464 = V_462 + V_216 -> V_420 ;
V_462 = V_461 * V_415 * 64 ;
V_462 = F_237 ( V_462 , V_455 -> V_419 ) ;
* V_458 = V_462 + V_455 -> V_420 ;
return F_250 ( V_2 ,
* V_464 , * V_458 ,
V_216 , V_455 ) ;
}
static void F_252 ( struct V_1 * V_2 )
{
static const int V_468 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_469 , V_470 , V_471 , V_472 ;
int V_473 , V_444 ;
unsigned int V_77 = 0 ;
if ( F_248 ( V_2 , 0 ,
& V_474 , V_416 ,
& V_475 , V_416 ,
& V_469 , & V_471 ) )
V_77 |= 1 ;
if ( F_248 ( V_2 , 1 ,
& V_474 , V_416 ,
& V_475 , V_416 ,
& V_470 , & V_472 ) )
V_77 |= 2 ;
V_473 = V_444 = 0 ;
if ( F_253 ( V_77 ) &&
F_251 ( V_2 , F_254 ( V_77 ) - 1 ,
V_468 ,
& V_474 ,
& V_475 ,
& V_473 , & V_444 ) )
F_23 ( V_476 , V_477 ) ;
else
F_23 ( V_476 ,
F_3 ( V_476 ) & ~ V_477 ) ;
F_25 ( L_92 ,
V_469 , V_471 ,
V_470 , V_472 ,
V_473 , V_444 ) ;
F_23 ( V_440 ,
( V_473 << V_442 ) |
( V_472 << V_478 ) |
( V_470 << V_479 ) |
V_469 ) ;
F_23 ( V_480 ,
( F_3 ( V_480 ) & V_481 ) |
( V_471 << V_482 ) ) ;
F_23 ( V_432 ,
( F_3 ( V_432 ) & ~ V_483 ) |
( V_444 << V_446 ) ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
int V_484 = 1 ;
int V_444 = 16 ;
V_9 = F_245 ( V_2 ) ;
if ( V_9 ) {
static const int V_468 = 12000 ;
int clock = V_9 -> V_241 . clock ;
int V_459 = V_9 -> V_241 . V_459 ;
int V_246 = V_9 -> V_241 . V_246 ;
int V_415 = V_9 -> V_159 -> V_270 / 8 ;
unsigned long V_460 ;
int V_462 ;
V_460 = ( ( V_459 * 1000 ) / clock ) ;
V_462 = ( ( ( V_468 / V_460 ) + 1000 ) / 1000 ) *
V_415 * V_246 ;
V_462 = F_237 ( V_462 , V_485 ) ;
V_484 = V_486 - V_462 ;
if ( V_484 < 0 )
V_484 = 1 ;
V_484 &= 0x1ff ;
F_25 ( L_93 ,
V_462 , V_484 ) ;
V_462 = ( ( ( V_468 / V_460 ) + 1000 ) / 1000 ) *
V_415 * 64 ;
V_462 = F_237 ( V_462 ,
V_487 . V_419 ) ;
V_444 = V_487 . V_414 -
( V_462 + V_487 . V_420 ) ;
if ( V_444 > V_487 . V_421 )
V_444 = V_487 . V_421 ;
F_25 ( L_94
L_95 , V_484 , V_444 ) ;
if ( F_135 ( V_2 ) )
F_23 ( V_476 , V_477 ) ;
} else {
if ( F_135 ( V_2 ) )
F_23 ( V_476 , F_3 ( V_476 )
& ~ V_477 ) ;
}
F_25 ( L_96 ,
V_484 ) ;
F_23 ( V_440 , ( V_484 << V_442 ) |
( 8 << 16 ) | ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_23 ( V_480 , ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_23 ( V_432 , ( V_444 << V_446 ) ) ;
}
static void F_256 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_412 * V_488 ;
T_5 V_489 ;
T_5 V_490 ;
int V_491 , V_484 = 1 ;
int V_414 ;
int V_469 , V_470 ;
struct V_8 * V_9 , * V_77 = NULL ;
if ( F_103 ( V_2 ) )
V_488 = & V_492 ;
else if ( ! F_11 ( V_2 ) )
V_488 = & V_493 ;
else
V_488 = & V_494 ;
V_414 = V_4 -> V_216 . V_495 ( V_2 , 0 ) ;
V_9 = F_249 ( V_2 , 0 ) ;
if ( V_9 -> V_77 && V_9 -> V_159 ) {
V_469 = F_236 ( V_9 -> V_241 . clock ,
V_488 , V_414 ,
V_9 -> V_159 -> V_270 / 8 ,
V_416 ) ;
V_77 = V_9 ;
} else
V_469 = V_414 - V_488 -> V_420 ;
V_414 = V_4 -> V_216 . V_495 ( V_2 , 1 ) ;
V_9 = F_249 ( V_2 , 1 ) ;
if ( V_9 -> V_77 && V_9 -> V_159 ) {
V_470 = F_236 ( V_9 -> V_241 . clock ,
V_488 , V_414 ,
V_9 -> V_159 -> V_270 / 8 ,
V_416 ) ;
if ( V_77 == NULL )
V_77 = V_9 ;
else
V_77 = NULL ;
} else
V_470 = V_414 - V_488 -> V_420 ;
F_25 ( L_97 , V_469 , V_470 ) ;
V_491 = 2 ;
if ( F_257 ( V_2 ) || F_103 ( V_2 ) )
F_23 ( V_476 , V_496 | 0 ) ;
else if ( F_131 ( V_2 ) )
F_23 ( V_497 , F_3 ( V_497 ) & ~ V_498 ) ;
if ( F_258 ( V_2 ) && V_77 ) {
static const int V_468 = 6000 ;
int clock = V_77 -> V_241 . clock ;
int V_459 = V_77 -> V_241 . V_459 ;
int V_246 = V_77 -> V_241 . V_246 ;
int V_415 = V_77 -> V_159 -> V_270 / 8 ;
unsigned long V_460 ;
int V_462 ;
V_460 = ( V_459 * 1000 ) / clock ;
V_462 = ( ( ( V_468 / V_460 ) + 1000 ) / 1000 ) *
V_415 * V_246 ;
V_462 = F_237 ( V_462 , V_488 -> V_419 ) ;
F_25 ( L_98 , V_462 ) ;
V_484 = V_488 -> V_414 - V_462 ;
if ( V_484 < 0 )
V_484 = 1 ;
if ( F_257 ( V_2 ) || F_103 ( V_2 ) )
F_23 ( V_476 ,
V_499 | ( V_484 & 0xff ) ) ;
else if ( F_131 ( V_2 ) )
F_23 ( V_476 , V_484 & 0x3f ) ;
}
F_25 ( L_99 ,
V_469 , V_470 , V_491 , V_484 ) ;
V_489 = ( ( V_470 & 0x3f ) << 16 ) | ( V_469 & 0x3f ) ;
V_490 = ( V_491 & 0x1f ) ;
V_489 = V_489 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_490 = V_490 | ( 1 << 8 ) ;
F_23 ( V_500 , V_489 ) ;
F_23 ( V_501 , V_490 ) ;
if ( F_258 ( V_2 ) ) {
if ( V_77 ) {
if ( F_257 ( V_2 ) || F_103 ( V_2 ) )
F_23 ( V_476 ,
V_496 | V_477 ) ;
else if ( F_131 ( V_2 ) )
F_23 ( V_497 , F_3 ( V_497 ) | V_498 ) ;
F_25 ( L_100 ) ;
} else
F_25 ( L_101 ) ;
}
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
T_5 V_489 ;
int V_469 ;
V_9 = F_245 ( V_2 ) ;
if ( V_9 == NULL )
return;
V_469 = F_236 ( V_9 -> V_241 . clock , & V_502 ,
V_4 -> V_216 . V_495 ( V_2 , 0 ) ,
V_9 -> V_159 -> V_270 / 8 ,
V_416 ) ;
V_489 = F_3 ( V_500 ) & ~ 0xfff ;
V_489 |= ( 3 << 8 ) | V_469 ;
F_25 ( L_102 , V_469 ) ;
F_23 ( V_500 , V_489 ) ;
}
static bool F_260 ( struct V_1 * V_2 , int V_503 ,
int V_504 , int V_464 , int V_458 ,
const struct V_412 * V_216 ,
const struct V_412 * V_455 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_25 ( L_103
L_104 , V_503 , V_464 , V_504 , V_458 ) ;
if ( V_504 > V_505 ) {
F_25 ( L_105 ,
V_504 , V_505 , V_503 ) ;
F_23 ( V_506 ,
F_3 ( V_506 ) | V_507 ) ;
return false ;
}
if ( V_464 > V_216 -> V_421 ) {
F_25 ( L_106 ,
V_464 , V_508 , V_503 ) ;
return false ;
}
if ( V_458 > V_455 -> V_421 ) {
F_25 ( L_107 ,
V_458 , V_509 , V_503 ) ;
return false ;
}
if ( ! ( V_504 || V_464 || V_458 ) ) {
F_25 ( L_108 , V_503 , V_503 ) ;
return false ;
}
return true ;
}
static bool F_261 ( struct V_1 * V_2 , int V_503 , int V_102 ,
int V_416 ,
const struct V_412 * V_216 ,
const struct V_412 * V_455 ,
int * V_504 , int * V_464 , int * V_458 )
{
struct V_8 * V_9 ;
unsigned long V_460 ;
int V_246 , V_459 , V_415 , clock ;
int V_461 , V_465 ;
int V_466 , V_467 ;
int V_462 ;
if ( ! V_416 ) {
* V_504 = * V_464 = * V_458 = 0 ;
return false ;
}
V_9 = F_249 ( V_2 , V_102 ) ;
V_246 = V_9 -> V_241 . V_246 ;
V_459 = V_9 -> V_241 . V_459 ;
clock = V_9 -> V_241 . clock ;
V_415 = V_9 -> V_159 -> V_270 / 8 ;
V_460 = ( V_459 * 1000 ) / clock ;
V_461 = ( V_416 / V_460 + 1000 ) / 1000 ;
V_465 = V_246 * V_415 ;
V_466 = ( ( clock * V_415 / 1000 ) * V_416 ) / 1000 ;
V_467 = V_461 * V_465 ;
V_462 = F_237 ( V_53 ( V_466 , V_467 ) , V_216 -> V_419 ) ;
* V_464 = V_462 + V_216 -> V_420 ;
* V_504 = F_237 ( * V_464 * 64 , V_465 ) + 2 ;
V_462 = V_461 * V_415 * 64 ;
V_462 = F_237 ( V_462 , V_455 -> V_419 ) ;
* V_458 = V_462 + V_455 -> V_420 ;
return F_260 ( V_2 , V_503 ,
* V_504 , * V_464 , * V_458 ,
V_216 , V_455 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_504 , V_457 , V_458 ;
unsigned int V_77 ;
V_77 = 0 ;
if ( F_248 ( V_2 , 0 ,
& V_510 ,
V_511 ,
& V_512 ,
V_513 ,
& V_457 , & V_458 ) ) {
F_23 ( V_514 ,
( V_457 << V_515 ) | V_458 ) ;
F_25 ( L_109
L_110 L_111 ,
V_457 , V_458 ) ;
V_77 |= 1 ;
}
if ( F_248 ( V_2 , 1 ,
& V_510 ,
V_511 ,
& V_512 ,
V_513 ,
& V_457 , & V_458 ) ) {
F_23 ( V_516 ,
( V_457 << V_515 ) | V_458 ) ;
F_25 ( L_112
L_113 ,
V_457 , V_458 ) ;
V_77 |= 2 ;
}
F_23 ( V_517 , 0 ) ;
F_23 ( V_518 , 0 ) ;
F_23 ( V_519 , 0 ) ;
if ( ! F_253 ( V_77 ) )
return;
V_77 = F_254 ( V_77 ) - 1 ;
if ( ! F_261 ( V_2 , 1 , V_77 ,
F_263 () * 500 ,
& V_520 ,
& V_521 ,
& V_504 , & V_457 , & V_458 ) )
return;
F_23 ( V_519 ,
V_522 |
( F_263 () << V_523 ) |
( V_504 << V_524 ) |
( V_457 << V_525 ) |
V_458 ) ;
if ( ! F_261 ( V_2 , 2 , V_77 ,
F_264 () * 500 ,
& V_520 ,
& V_521 ,
& V_504 , & V_457 , & V_458 ) )
return;
F_23 ( V_518 ,
V_526 |
( F_264 () << V_523 ) |
( V_504 << V_524 ) |
( V_457 << V_525 ) |
V_458 ) ;
}
void F_265 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_428 = F_266 () * 100 ;
T_1 V_79 ;
int V_504 , V_457 , V_458 ;
unsigned int V_77 ;
V_77 = 0 ;
if ( F_248 ( V_2 , 0 ,
& V_527 , V_428 ,
& V_528 , V_428 ,
& V_457 , & V_458 ) ) {
V_79 = F_3 ( V_514 ) ;
V_79 &= ~ ( V_529 | V_530 ) ;
F_23 ( V_514 , V_79 |
( ( V_457 << V_515 ) | V_458 ) ) ;
F_25 ( L_109
L_110 L_111 ,
V_457 , V_458 ) ;
V_77 |= 1 ;
}
if ( F_248 ( V_2 , 1 ,
& V_527 , V_428 ,
& V_528 , V_428 ,
& V_457 , & V_458 ) ) {
V_79 = F_3 ( V_516 ) ;
V_79 &= ~ ( V_529 | V_530 ) ;
F_23 ( V_516 , V_79 |
( ( V_457 << V_515 ) | V_458 ) ) ;
F_25 ( L_112
L_113 ,
V_457 , V_458 ) ;
V_77 |= 2 ;
}
if ( F_154 ( V_2 ) &&
F_248 ( V_2 , 2 ,
& V_527 , V_428 ,
& V_528 , V_428 ,
& V_457 , & V_458 ) ) {
V_79 = F_3 ( V_531 ) ;
V_79 &= ~ ( V_529 | V_530 ) ;
F_23 ( V_531 , V_79 |
( ( V_457 << V_515 ) | V_458 ) ) ;
F_25 ( L_114
L_113 ,
V_457 , V_458 ) ;
V_77 |= 3 ;
}
F_23 ( V_517 , 0 ) ;
F_23 ( V_518 , 0 ) ;
F_23 ( V_519 , 0 ) ;
if ( ! F_253 ( V_77 ) ||
V_4 -> V_532 )
return;
V_77 = F_254 ( V_77 ) - 1 ;
if ( ! F_261 ( V_2 , 1 , V_77 ,
F_267 () * 500 ,
& V_533 ,
& V_534 ,
& V_504 , & V_457 , & V_458 ) )
return;
F_23 ( V_519 ,
V_522 |
( F_267 () << V_523 ) |
( V_504 << V_524 ) |
( V_457 << V_525 ) |
V_458 ) ;
if ( ! F_261 ( V_2 , 2 , V_77 ,
F_268 () * 500 ,
& V_533 ,
& V_534 ,
& V_504 , & V_457 , & V_458 ) )
return;
F_23 ( V_518 ,
V_526 |
( F_268 () << V_523 ) |
( V_504 << V_524 ) |
( V_457 << V_525 ) |
V_458 ) ;
if ( ! F_261 ( V_2 , 3 , V_77 ,
F_269 () * 500 ,
& V_533 ,
& V_534 ,
& V_504 , & V_457 , & V_458 ) )
return;
F_23 ( V_517 ,
V_535 |
( F_269 () << V_523 ) |
( V_504 << V_524 ) |
( V_457 << V_525 ) |
V_458 ) ;
}
static bool
F_270 ( struct V_1 * V_2 , int V_102 ,
T_5 V_536 , int V_415 ,
const struct V_412 * V_216 ,
int V_454 , int * V_537 )
{
struct V_8 * V_9 ;
int clock ;
int V_462 , V_463 ;
V_9 = F_249 ( V_2 , V_102 ) ;
if ( V_9 -> V_159 == NULL || ! V_9 -> V_77 ) {
* V_537 = V_216 -> V_420 ;
return false ;
}
clock = V_9 -> V_241 . clock ;
V_462 = ( ( clock * V_415 / 1000 ) * V_454 ) / 1000 ;
V_463 = V_216 -> V_414 * V_216 -> V_419 -
V_536 * 8 ;
if ( V_463 > 0 )
V_462 += V_463 ;
V_462 = F_237 ( V_462 , V_216 -> V_419 ) ;
* V_537 = V_462 + V_216 -> V_420 ;
if ( * V_537 > ( int ) V_216 -> V_421 )
* V_537 = V_216 -> V_421 ;
return true ;
}
static bool
F_271 ( struct V_1 * V_2 , int V_102 ,
T_5 V_536 , int V_415 ,
const struct V_412 * V_216 ,
int V_416 , int * V_537 )
{
struct V_8 * V_9 ;
unsigned long V_460 ;
int clock ;
int V_461 , V_465 ;
int V_466 , V_467 ;
int V_462 ;
if ( ! V_416 ) {
* V_537 = 0 ;
return false ;
}
V_9 = F_249 ( V_2 , V_102 ) ;
clock = V_9 -> V_241 . clock ;
if ( ! clock ) {
* V_537 = 0 ;
return false ;
}
V_460 = ( V_536 * 1000 ) / clock ;
if ( ! V_460 ) {
* V_537 = 0 ;
return false ;
}
V_461 = ( V_416 / V_460 + 1000 ) / 1000 ;
V_465 = V_536 * V_415 ;
V_466 = ( ( clock * V_415 / 1000 ) * V_416 ) / 1000 ;
V_467 = V_461 * V_465 ;
V_462 = F_237 ( V_53 ( V_466 , V_467 ) , V_216 -> V_419 ) ;
* V_537 = V_462 + V_216 -> V_420 ;
return * V_537 > 0x3ff ? false : true ;
}
static void F_272 ( struct V_1 * V_2 , int V_67 ,
T_5 V_536 , int V_415 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_428 = F_266 () * 100 ;
T_1 V_79 ;
int V_537 , V_71 ;
int V_257 ;
switch ( V_67 ) {
case 0 :
V_71 = V_514 ;
break;
case 1 :
V_71 = V_516 ;
break;
case 2 :
V_71 = V_531 ;
break;
default:
return;
}
V_257 = F_270 ( V_2 , V_67 , V_536 , V_415 ,
& V_527 ,
V_428 , & V_537 ) ;
if ( ! V_257 ) {
F_25 ( L_115 ,
V_67 ) ;
return;
}
V_79 = F_3 ( V_71 ) ;
V_79 &= ~ V_538 ;
F_23 ( V_71 , V_79 | ( V_537 << V_539 ) ) ;
F_25 ( L_116 , V_67 , V_537 ) ;
V_257 = F_271 ( V_2 , V_67 , V_536 ,
V_415 ,
& V_533 ,
F_267 () * 500 ,
& V_537 ) ;
if ( ! V_257 ) {
F_25 ( L_117 ,
V_67 ) ;
return;
}
F_23 ( V_540 , V_537 ) ;
if ( ! F_154 ( V_2 ) )
return;
V_257 = F_271 ( V_2 , V_67 , V_536 ,
V_415 ,
& V_533 ,
F_268 () * 500 ,
& V_537 ) ;
if ( ! V_257 ) {
F_25 ( L_118 ,
V_67 ) ;
return;
}
F_23 ( V_541 , V_537 ) ;
V_257 = F_271 ( V_2 , V_67 , V_536 ,
V_415 ,
& V_533 ,
F_269 () * 500 ,
& V_537 ) ;
if ( ! V_257 ) {
F_25 ( L_119 ,
V_67 ) ;
return;
}
F_23 ( V_542 , V_537 ) ;
}
static void F_198 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_216 . V_543 )
V_4 -> V_216 . V_543 ( V_2 ) ;
}
void F_273 ( struct V_1 * V_2 , int V_67 ,
T_5 V_536 , int V_415 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_216 . V_544 )
V_4 -> V_216 . V_544 ( V_2 , V_67 , V_536 ,
V_415 ) ;
}
static inline bool F_274 ( struct V_3 * V_4 )
{
if ( V_545 >= 0 )
return V_545 != 0 ;
return V_4 -> V_546
&& ! ( V_4 -> V_99 & V_547 ) ;
}
static bool F_275 ( struct V_8 * V_9 ,
unsigned int * V_548 ,
struct V_381 * V_241 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_378 * V_51 ;
struct V_549 * V_550 ;
unsigned int V_551 = V_552 , V_343 ;
F_14 (encoder, &dev->mode_config.encoder_list, head) {
struct V_50 * V_50 = F_221 ( V_51 ) ;
if ( V_51 -> V_9 != V_9 )
continue;
if ( V_50 -> type == V_12 ) {
unsigned int V_553 ;
if ( ( F_3 ( V_13 ) & V_554 ) ==
V_555 )
V_553 = 8 ;
else
V_553 = 6 ;
if ( V_553 < V_551 ) {
F_25 ( L_120 , V_551 , V_553 ) ;
V_551 = V_553 ;
}
continue;
}
if ( V_50 -> type == V_334 ) {
unsigned int V_556 = V_4 -> V_557 . V_558 / 3 ;
if ( V_556 < V_551 ) {
F_25 ( L_121 , V_551 , V_556 ) ;
V_551 = V_556 ;
}
continue;
}
F_14 (connector, &dev->mode_config.connector_list,
head) {
if ( V_550 -> V_51 != V_51 )
continue;
if ( V_550 -> V_559 . V_343 &&
V_550 -> V_559 . V_343 < V_551 ) {
F_25 ( L_122 , V_551 , V_550 -> V_559 . V_343 ) ;
V_551 = V_550 -> V_559 . V_343 ;
}
}
if ( V_50 -> type == V_27 ) {
if ( V_551 > 8 && V_551 < 12 ) {
F_25 ( L_123 ) ;
V_551 = 12 ;
} else {
F_25 ( L_124 ) ;
V_551 = 8 ;
}
}
}
if ( V_241 -> V_384 & V_560 ) {
F_25 ( L_125 ) ;
V_551 = 6 ;
}
switch ( V_9 -> V_159 -> V_272 ) {
case 8 :
V_343 = 8 ;
break;
case 15 :
case 16 :
V_343 = 6 ;
break;
case 24 :
V_343 = 8 ;
break;
case 30 :
V_343 = 10 ;
break;
case 48 :
V_343 = 12 ;
break;
default:
F_276 ( L_126 ) ;
V_343 = V_53 ( ( unsigned int ) 8 , V_551 ) ;
break;
}
V_551 = V_53 ( V_551 , V_343 ) ;
F_25 ( L_127 ,
V_343 , V_551 ) ;
* V_548 = V_551 * 3 ;
return V_551 != V_343 ;
}
static int F_277 ( struct V_8 * V_9 , int V_561 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_10 ;
if ( F_5 ( V_9 , V_12 ) &&
F_274 ( V_4 ) && V_561 < 2 ) {
V_10 = V_4 -> V_562 * 1000 ;
F_25 ( L_128 ,
V_10 / 1000 ) ;
} else if ( ! F_11 ( V_2 ) ) {
V_10 = 96000 ;
} else {
V_10 = 48000 ;
}
return V_10 ;
}
static void F_278 ( struct V_381 * V_382 ,
T_3 * clock )
{
if ( V_382 -> clock >= 100000
&& V_382 -> clock < 140500 ) {
clock -> V_42 = 2 ;
clock -> V_43 = 10 ;
clock -> V_45 = 3 ;
clock -> V_47 = 16 ;
clock -> V_40 = 8 ;
} else if ( V_382 -> clock >= 140500
&& V_382 -> clock <= 200000 ) {
clock -> V_42 = 1 ;
clock -> V_43 = 10 ;
clock -> V_45 = 6 ;
clock -> V_47 = 12 ;
clock -> V_40 = 8 ;
}
}
static void F_279 ( struct V_8 * V_9 ,
T_3 * clock ,
T_3 * V_563 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
T_1 V_564 , V_565 = 0 ;
if ( F_10 ( V_2 ) ) {
V_564 = ( 1 << clock -> V_45 ) << 16 | clock -> V_47 << 8 | clock -> V_40 ;
if ( V_563 )
V_565 = ( 1 << V_563 -> V_45 ) << 16 |
V_563 -> V_47 << 8 | V_563 -> V_40 ;
} else {
V_564 = clock -> V_45 << 16 | clock -> V_47 << 8 | clock -> V_40 ;
if ( V_563 )
V_565 = V_563 -> V_45 << 16 | V_563 -> V_47 << 8 |
V_563 -> V_40 ;
}
F_23 ( F_280 ( V_67 ) , V_564 ) ;
V_164 -> V_566 = false ;
if ( F_5 ( V_9 , V_12 ) &&
V_563 && V_232 ) {
F_23 ( F_281 ( V_67 ) , V_565 ) ;
V_164 -> V_566 = true ;
} else {
F_23 ( F_281 ( V_67 ) , V_564 ) ;
}
}
static int F_282 ( struct V_8 * V_9 ,
struct V_381 * V_241 ,
struct V_381 * V_382 ,
int V_265 , int V_178 ,
struct V_158 * V_281 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
int V_102 = V_164 -> V_102 ;
int V_10 , V_561 = 0 ;
T_3 clock , V_563 ;
T_1 V_567 , V_268 , V_568 , V_569 ;
bool V_570 , V_571 = false , V_572 = false , V_573 = false ;
bool V_574 = false , V_575 = false , V_576 = false , V_577 = false ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
const T_2 * V_11 ;
int V_257 ;
T_1 V_300 ;
T_1 V_578 = 0 ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_12 :
V_575 = true ;
break;
case V_30 :
case V_27 :
V_572 = true ;
if ( V_51 -> V_579 )
V_576 = true ;
break;
case V_580 :
V_573 = true ;
break;
case V_581 :
V_576 = true ;
break;
case V_28 :
V_574 = true ;
break;
case V_20 :
V_577 = true ;
break;
}
V_561 ++ ;
}
V_10 = F_277 ( V_9 , V_561 ) ;
V_11 = F_7 ( V_9 , V_10 ) ;
V_570 = V_11 -> V_582 ( V_11 , V_9 , V_382 -> clock , V_10 , NULL ,
& clock ) ;
if ( ! V_570 ) {
F_83 ( L_129 ) ;
return - V_260 ;
}
F_203 ( V_9 , true ) ;
if ( V_575 && V_4 -> V_583 ) {
V_571 = V_11 -> V_582 ( V_11 , V_9 ,
V_4 -> V_584 ,
V_10 ,
& clock ,
& V_563 ) ;
}
if ( V_572 && V_576 )
F_278 ( V_382 , & clock ) ;
F_279 ( V_9 , & clock , V_571 ?
& V_563 : NULL ) ;
V_567 = V_585 ;
if ( ! F_11 ( V_2 ) ) {
if ( V_575 )
V_567 |= V_586 ;
else
V_567 |= V_587 ;
if ( V_572 ) {
int V_588 = F_283 ( V_382 ) ;
if ( V_588 > 1 ) {
if ( F_257 ( V_2 ) || F_103 ( V_2 ) || F_284 ( V_2 ) )
V_567 |= ( V_588 - 1 ) << V_589 ;
}
V_567 |= V_590 ;
}
if ( V_577 )
V_567 |= V_590 ;
if ( F_10 ( V_2 ) )
V_567 |= ( 1 << ( clock . V_42 - 1 ) ) << V_591 ;
else {
V_567 |= ( 1 << ( clock . V_42 - 1 ) ) << V_592 ;
if ( F_9 ( V_2 ) && V_571 )
V_567 |= ( 1 << ( V_563 . V_42 - 1 ) ) << V_593 ;
}
switch ( clock . V_43 ) {
case 5 :
V_567 |= V_594 ;
break;
case 7 :
V_567 |= V_595 ;
break;
case 10 :
V_567 |= V_596 ;
break;
case 14 :
V_567 |= V_597 ;
break;
}
if ( F_27 ( V_2 ) -> V_70 >= 4 )
V_567 |= ( 6 << V_598 ) ;
} else {
if ( V_575 ) {
V_567 |= ( 1 << ( clock . V_42 - 1 ) ) << V_592 ;
} else {
if ( clock . V_42 == 2 )
V_567 |= V_599 ;
else
V_567 |= ( clock . V_42 - 2 ) << V_592 ;
if ( clock . V_43 == 4 )
V_567 |= V_600 ;
}
}
if ( V_572 && V_576 )
V_567 |= V_601 ;
else if ( V_576 )
V_567 |= 3 ;
else if ( V_575 && F_274 ( V_4 ) && V_561 < 2 )
V_567 |= V_602 ;
else
V_567 |= V_603 ;
V_568 = F_3 ( F_28 ( V_67 ) ) ;
V_268 = V_604 ;
if ( V_67 == 0 )
V_268 &= ~ V_106 ;
else
V_268 |= V_605 ;
if ( V_67 == 0 && F_27 ( V_2 ) -> V_70 < 4 ) {
if ( V_241 -> clock >
V_4 -> V_216 . V_606 ( V_2 ) * 9 / 10 )
V_568 |= V_607 ;
else
V_568 &= ~ V_607 ;
}
V_568 &= ~ ( V_608 | V_609 ) ;
if ( V_577 ) {
if ( V_241 -> V_384 & V_560 ) {
V_568 |= V_610 |
V_609 |
V_611 ;
}
}
V_567 |= V_81 ;
F_25 ( L_130 , V_67 == 0 ? 'A' : 'B' ) ;
F_285 ( V_241 ) ;
F_23 ( F_35 ( V_67 ) , V_567 & ~ V_81 ) ;
F_72 ( F_35 ( V_67 ) ) ;
F_73 ( 150 ) ;
if ( V_575 ) {
V_300 = F_3 ( V_24 ) ;
V_300 |= V_122 | V_612 ;
if ( V_67 == 1 ) {
V_300 |= V_97 ;
} else {
V_300 &= ~ V_97 ;
}
V_300 |= V_4 -> V_613 ;
if ( clock . V_43 == 7 )
V_300 |= V_614 | V_15 ;
else
V_300 &= ~ ( V_614 | V_15 ) ;
if ( F_27 ( V_2 ) -> V_70 >= 4 ) {
if ( V_4 -> V_615 )
V_300 |= V_616 ;
else
V_300 &= ~ V_616 ;
}
if ( V_382 -> V_242 & V_617 )
V_578 |= V_618 ;
if ( V_382 -> V_242 & V_619 )
V_578 |= V_620 ;
if ( ( V_300 & ( V_618 | V_620 ) )
!= V_578 ) {
char V_242 [ 2 ] = L_131 ;
F_286 ( L_132
L_133 ,
V_242 [ ! ( V_300 & V_618 ) ] ,
V_242 [ ! ( V_300 & V_620 ) ] ,
V_242 [ ! ( V_578 & V_618 ) ] ,
V_242 [ ! ( V_578 & V_620 ) ] ) ;
V_300 &= ~ ( V_618 | V_620 ) ;
V_300 |= V_578 ;
}
F_23 ( V_24 , V_300 ) ;
}
if ( V_577 ) {
F_287 ( V_9 , V_241 , V_382 ) ;
}
F_23 ( F_35 ( V_67 ) , V_567 ) ;
F_72 ( F_35 ( V_67 ) ) ;
F_73 ( 150 ) ;
if ( F_27 ( V_2 ) -> V_70 >= 4 ) {
V_300 = 0 ;
if ( V_572 ) {
V_300 = F_283 ( V_382 ) ;
if ( V_300 > 1 )
V_300 = ( V_300 - 1 ) << V_621 ;
else
V_300 = 0 ;
}
F_23 ( F_288 ( V_67 ) , V_300 ) ;
} else {
F_23 ( F_35 ( V_67 ) , V_567 ) ;
}
if ( F_289 ( V_2 ) ) {
if ( V_164 -> V_566 ) {
F_25 ( L_134 ) ;
V_568 |= V_622 ;
} else {
F_25 ( L_135 ) ;
V_568 &= ~ V_622 ;
}
}
V_568 &= ~ V_145 ;
if ( ! F_11 ( V_2 ) &&
V_382 -> V_242 & V_243 ) {
V_568 |= V_623 ;
V_382 -> V_624 -= 1 ;
V_382 -> V_625 -= 1 ;
V_569 = V_382 -> V_626
- V_382 -> V_627 / 2 ;
} else {
V_568 |= V_628 ;
V_569 = 0 ;
}
if ( ! F_290 ( V_2 ) )
F_23 ( F_193 ( V_67 ) , V_569 ) ;
F_23 ( F_181 ( V_67 ) ,
( V_382 -> V_629 - 1 ) |
( ( V_382 -> V_627 - 1 ) << 16 ) ) ;
F_23 ( F_183 ( V_67 ) ,
( V_382 -> V_630 - 1 ) |
( ( V_382 -> V_631 - 1 ) << 16 ) ) ;
F_23 ( F_185 ( V_67 ) ,
( V_382 -> V_626 - 1 ) |
( ( V_382 -> V_632 - 1 ) << 16 ) ) ;
F_23 ( F_187 ( V_67 ) ,
( V_382 -> V_633 - 1 ) |
( ( V_382 -> V_624 - 1 ) << 16 ) ) ;
F_23 ( F_189 ( V_67 ) ,
( V_382 -> V_634 - 1 ) |
( ( V_382 -> V_625 - 1 ) << 16 ) ) ;
F_23 ( F_191 ( V_67 ) ,
( V_382 -> V_635 - 1 ) |
( ( V_382 -> V_636 - 1 ) << 16 ) ) ;
F_23 ( F_291 ( V_102 ) ,
( ( V_241 -> V_247 - 1 ) << 16 ) |
( V_241 -> V_246 - 1 ) ) ;
F_23 ( F_292 ( V_102 ) , 0 ) ;
F_23 ( F_293 ( V_67 ) ,
( ( V_241 -> V_246 - 1 ) << 16 ) | ( V_241 -> V_247 - 1 ) ) ;
F_23 ( F_28 ( V_67 ) , V_568 ) ;
F_72 ( F_28 ( V_67 ) ) ;
F_87 ( V_4 , V_67 , false ) ;
F_21 ( V_2 , V_67 ) ;
F_23 ( F_50 ( V_102 ) , V_268 ) ;
F_72 ( F_50 ( V_102 ) ) ;
F_93 ( V_4 , V_102 , V_67 ) ;
V_257 = F_153 ( V_9 , V_265 , V_178 , V_281 ) ;
F_198 ( V_2 ) ;
return V_257 ;
}
void F_294 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
T_1 V_300 ;
bool V_637 = false ;
bool V_638 = false ;
bool V_639 = false ;
bool V_640 = false ;
bool V_641 = false ;
bool V_642 = false ;
F_14 (encoder, &mode_config->encoder_list,
base.head) {
switch ( V_51 -> type ) {
case V_12 :
V_640 = true ;
V_637 = true ;
break;
case V_334 :
V_640 = true ;
if ( F_178 ( & V_51 -> V_52 ) )
V_639 = true ;
else
V_638 = true ;
break;
}
}
if ( F_82 ( V_2 ) ) {
V_641 = V_4 -> V_643 ;
V_642 = V_641 ;
} else {
V_641 = false ;
V_642 = true ;
}
F_25 ( L_136 ,
V_640 , V_637 , V_639 , V_638 ,
V_641 ) ;
V_300 = F_3 ( V_108 ) ;
V_300 &= ~ V_110 ;
if ( V_641 )
V_300 |= V_644 ;
else
V_300 |= V_645 ;
if ( V_640 ) {
V_300 &= ~ V_109 ;
V_300 |= V_646 ;
if ( F_274 ( V_4 ) && V_642 ) {
F_25 ( L_137 ) ;
V_300 |= V_647 ;
} else
V_300 &= ~ V_647 ;
F_23 ( V_108 , V_300 ) ;
F_72 ( V_108 ) ;
F_73 ( 200 ) ;
V_300 &= ~ V_648 ;
if ( V_638 ) {
if ( F_274 ( V_4 ) && V_642 ) {
F_25 ( L_138 ) ;
V_300 |= V_649 ;
}
else
V_300 |= V_650 ;
} else
V_300 |= V_651 ;
F_23 ( V_108 , V_300 ) ;
F_72 ( V_108 ) ;
F_73 ( 200 ) ;
} else {
F_25 ( L_139 ) ;
V_300 &= ~ V_648 ;
V_300 |= V_651 ;
F_23 ( V_108 , V_300 ) ;
F_72 ( V_108 ) ;
F_73 ( 200 ) ;
V_300 &= ~ V_109 ;
V_300 |= V_652 ;
V_300 &= ~ V_647 ;
F_23 ( V_108 , V_300 ) ;
F_72 ( V_108 ) ;
F_73 ( 200 ) ;
}
}
static int F_295 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_50 * V_51 ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_653 = NULL ;
int V_561 = 0 ;
bool V_575 = false ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_12 :
V_575 = true ;
break;
case V_334 :
V_653 = V_51 ;
break;
}
V_561 ++ ;
}
if ( V_575 && F_274 ( V_4 ) && V_561 < 2 ) {
F_25 ( L_128 ,
V_4 -> V_562 ) ;
return V_4 -> V_562 * 1000 ;
}
return 120000 ;
}
static int F_296 ( struct V_8 * V_9 ,
struct V_381 * V_241 ,
struct V_381 * V_382 ,
int V_265 , int V_178 ,
struct V_158 * V_281 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
int V_102 = V_164 -> V_102 ;
int V_10 , V_561 = 0 ;
T_3 clock , V_563 ;
T_1 V_567 , V_564 = 0 , V_565 = 0 , V_268 , V_568 ;
bool V_570 , V_571 = false , V_572 = false ;
bool V_574 = false , V_575 = false , V_576 = false , V_577 = false ;
struct V_50 * V_654 = NULL ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
const T_2 * V_11 ;
int V_257 ;
struct V_404 V_405 = { 0 } ;
T_1 V_300 ;
T_1 V_578 = 0 ;
int V_655 , V_588 , V_656 , V_657 , V_658 ;
unsigned int V_548 ;
bool V_659 ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_12 :
V_575 = true ;
break;
case V_30 :
case V_27 :
V_572 = true ;
if ( V_51 -> V_579 )
V_576 = true ;
break;
case V_581 :
V_576 = true ;
break;
case V_28 :
V_574 = true ;
break;
case V_20 :
V_577 = true ;
break;
case V_334 :
V_654 = V_51 ;
break;
}
V_561 ++ ;
}
V_10 = F_295 ( V_9 ) ;
V_11 = F_7 ( V_9 , V_10 ) ;
V_570 = V_11 -> V_582 ( V_11 , V_9 , V_382 -> clock , V_10 , NULL ,
& clock ) ;
if ( ! V_570 ) {
F_83 ( L_129 ) ;
return - V_260 ;
}
F_203 ( V_9 , true ) ;
if ( V_575 && V_4 -> V_583 ) {
V_571 = V_11 -> V_582 ( V_11 , V_9 ,
V_4 -> V_584 ,
V_10 ,
& clock ,
& V_563 ) ;
}
if ( V_572 && V_576 ) {
if ( V_382 -> clock >= 100000
&& V_382 -> clock < 140500 ) {
clock . V_42 = 2 ;
clock . V_43 = 10 ;
clock . V_45 = 3 ;
clock . V_47 = 16 ;
clock . V_40 = 8 ;
} else if ( V_382 -> clock >= 140500
&& V_382 -> clock <= 200000 ) {
clock . V_42 = 1 ;
clock . V_43 = 10 ;
clock . V_45 = 6 ;
clock . V_47 = 12 ;
clock . V_40 = 8 ;
}
}
V_588 = F_283 ( V_382 ) ;
V_656 = 0 ;
if ( V_654 &&
! F_178 ( & V_654 -> V_52 ) ) {
V_655 = V_241 -> clock ;
F_297 ( V_654 ,
& V_656 , & V_657 ) ;
} else {
if ( V_577 || F_178 ( & V_654 -> V_52 ) )
V_655 = V_241 -> clock ;
else
V_655 = V_382 -> clock ;
V_657 = F_1 ( V_2 ) * F_298 ( 100 ) / F_299 ( 1 ) / 10 ;
}
V_300 = F_3 ( F_28 ( V_67 ) ) ;
V_300 &= ~ V_143 ;
V_659 = F_275 ( V_9 , & V_548 , V_241 ) ;
switch ( V_548 ) {
case 18 :
V_300 |= V_660 ;
break;
case 24 :
V_300 |= V_661 ;
break;
case 30 :
V_300 |= V_662 ;
break;
case 36 :
V_300 |= V_663 ;
break;
default:
F_36 ( 1 , L_140 ,
V_548 ) ;
V_300 |= V_661 ;
V_548 = 24 ;
break;
}
V_164 -> V_558 = V_548 ;
F_23 ( F_28 ( V_67 ) , V_300 ) ;
if ( ! V_656 ) {
T_1 V_664 = V_655 * V_164 -> V_558 * 21 / 20 ;
V_656 = V_664 / ( V_657 * 8 ) + 1 ;
}
V_164 -> V_315 = V_656 ;
if ( V_588 > 1 )
V_657 *= V_588 ;
F_235 ( V_164 -> V_558 , V_656 , V_655 , V_657 ,
& V_405 ) ;
V_564 = clock . V_45 << 16 | clock . V_47 << 8 | clock . V_40 ;
if ( V_571 )
V_565 = V_563 . V_45 << 16 | V_563 . V_47 << 8 |
V_563 . V_40 ;
V_658 = 21 ;
if ( V_575 ) {
if ( ( F_274 ( V_4 ) &&
V_4 -> V_562 == 100 ) ||
( F_3 ( V_13 ) & V_14 ) == V_15 )
V_658 = 25 ;
} else if ( V_572 && V_576 )
V_658 = 20 ;
if ( clock . V_39 < V_658 * clock . V_45 )
V_564 |= V_665 ;
V_567 = 0 ;
if ( V_575 )
V_567 |= V_586 ;
else
V_567 |= V_587 ;
if ( V_572 ) {
int V_588 = F_283 ( V_382 ) ;
if ( V_588 > 1 ) {
V_567 |= ( V_588 - 1 ) << V_666 ;
}
V_567 |= V_590 ;
}
if ( V_577 || F_178 ( & V_654 -> V_52 ) )
V_567 |= V_590 ;
V_567 |= ( 1 << ( clock . V_42 - 1 ) ) << V_592 ;
V_567 |= ( 1 << ( clock . V_42 - 1 ) ) << V_593 ;
switch ( clock . V_43 ) {
case 5 :
V_567 |= V_594 ;
break;
case 7 :
V_567 |= V_595 ;
break;
case 10 :
V_567 |= V_596 ;
break;
case 14 :
V_567 |= V_597 ;
break;
}
if ( V_572 && V_576 )
V_567 |= V_601 ;
else if ( V_576 )
V_567 |= 3 ;
else if ( V_575 && F_274 ( V_4 ) && V_561 < 2 )
V_567 |= V_602 ;
else
V_567 |= V_603 ;
V_568 = F_3 ( F_28 ( V_67 ) ) ;
V_268 = V_604 ;
F_25 ( L_141 , V_67 ) ;
F_285 ( V_241 ) ;
if ( ! V_164 -> V_362 ) {
if ( ! V_654 ||
F_178 ( & V_654 -> V_52 ) ) {
F_23 ( F_300 ( V_67 ) , V_564 ) ;
F_23 ( F_39 ( V_67 ) , V_567 & ~ V_81 ) ;
F_72 ( F_39 ( V_67 ) ) ;
F_73 ( 150 ) ;
}
} else {
if ( V_567 == ( F_3 ( F_39 ( 0 ) ) & 0x7fffffff ) &&
V_564 == F_3 ( F_300 ( 0 ) ) ) {
V_164 -> V_337 = true ;
F_25 ( L_142 ) ;
} else if ( V_567 == ( F_3 ( F_39 ( 1 ) ) & 0x7fffffff ) &&
V_564 == F_3 ( F_300 ( 1 ) ) ) {
V_164 -> V_337 = false ;
F_25 ( L_143 ) ;
} else {
F_25 ( L_144 ) ;
return - V_260 ;
}
}
if ( V_575 ) {
V_300 = F_3 ( V_13 ) ;
V_300 |= V_122 | V_612 ;
if ( F_38 ( V_2 ) ) {
V_300 &= ~ V_120 ;
V_300 |= F_59 ( V_67 ) ;
} else {
if ( V_67 == 1 )
V_300 |= V_97 ;
else
V_300 &= ~ V_97 ;
}
V_300 |= V_4 -> V_613 ;
if ( clock . V_43 == 7 )
V_300 |= V_614 | V_15 ;
else
V_300 &= ~ ( V_614 | V_15 ) ;
if ( V_382 -> V_242 & V_617 )
V_578 |= V_618 ;
if ( V_382 -> V_242 & V_619 )
V_578 |= V_620 ;
if ( ( V_300 & ( V_618 | V_620 ) )
!= V_578 ) {
char V_242 [ 2 ] = L_131 ;
F_286 ( L_132
L_133 ,
V_242 [ ! ( V_300 & V_618 ) ] ,
V_242 [ ! ( V_300 & V_620 ) ] ,
V_242 [ ! ( V_578 & V_618 ) ] ,
V_242 [ ! ( V_578 & V_620 ) ] ) ;
V_300 &= ~ ( V_618 | V_620 ) ;
V_300 |= V_578 ;
}
F_23 ( V_13 , V_300 ) ;
}
V_568 &= ~ V_609 ;
V_568 &= ~ V_667 ;
if ( ( V_575 && V_4 -> V_615 ) || V_659 ) {
V_568 |= V_609 ;
V_568 |= V_611 ;
}
if ( V_577 || F_178 ( & V_654 -> V_52 ) ) {
F_287 ( V_9 , V_241 , V_382 ) ;
} else {
F_23 ( F_301 ( V_67 ) , 0 ) ;
F_23 ( F_302 ( V_67 ) , 0 ) ;
F_23 ( F_303 ( V_67 ) , 0 ) ;
F_23 ( F_304 ( V_67 ) , 0 ) ;
}
if ( ! V_164 -> V_362 &&
( ! V_654 ||
F_178 ( & V_654 -> V_52 ) ) ) {
F_23 ( F_39 ( V_67 ) , V_567 ) ;
F_72 ( F_39 ( V_67 ) ) ;
F_73 ( 150 ) ;
F_23 ( F_39 ( V_67 ) , V_567 ) ;
}
V_164 -> V_566 = false ;
if ( ! V_164 -> V_362 ) {
if ( V_575 && V_571 && V_232 ) {
F_23 ( F_305 ( V_67 ) , V_565 ) ;
V_164 -> V_566 = true ;
if ( F_289 ( V_2 ) ) {
F_25 ( L_134 ) ;
V_568 |= V_622 ;
}
} else {
F_23 ( F_305 ( V_67 ) , V_564 ) ;
if ( F_289 ( V_2 ) ) {
F_25 ( L_135 ) ;
V_568 &= ~ V_622 ;
}
}
}
V_568 &= ~ V_145 ;
if ( V_382 -> V_242 & V_243 ) {
V_568 |= V_146 ;
V_382 -> V_624 -= 1 ;
V_382 -> V_625 -= 1 ;
F_23 ( F_193 ( V_67 ) ,
V_382 -> V_626
- V_382 -> V_627 / 2 ) ;
} else {
V_568 |= V_628 ;
F_23 ( F_193 ( V_67 ) , 0 ) ;
}
F_23 ( F_181 ( V_67 ) ,
( V_382 -> V_629 - 1 ) |
( ( V_382 -> V_627 - 1 ) << 16 ) ) ;
F_23 ( F_183 ( V_67 ) ,
( V_382 -> V_630 - 1 ) |
( ( V_382 -> V_631 - 1 ) << 16 ) ) ;
F_23 ( F_185 ( V_67 ) ,
( V_382 -> V_626 - 1 ) |
( ( V_382 -> V_632 - 1 ) << 16 ) ) ;
F_23 ( F_187 ( V_67 ) ,
( V_382 -> V_633 - 1 ) |
( ( V_382 -> V_624 - 1 ) << 16 ) ) ;
F_23 ( F_189 ( V_67 ) ,
( V_382 -> V_634 - 1 ) |
( ( V_382 -> V_625 - 1 ) << 16 ) ) ;
F_23 ( F_191 ( V_67 ) ,
( V_382 -> V_635 - 1 ) |
( ( V_382 -> V_636 - 1 ) << 16 ) ) ;
F_23 ( F_293 ( V_67 ) ,
( ( V_241 -> V_246 - 1 ) << 16 ) | ( V_241 -> V_247 - 1 ) ) ;
F_23 ( F_169 ( V_67 ) , F_306 ( V_405 . V_406 ) | V_405 . V_407 ) ;
F_23 ( F_307 ( V_67 ) , V_405 . V_408 ) ;
F_23 ( F_308 ( V_67 ) , V_405 . V_409 ) ;
F_23 ( F_309 ( V_67 ) , V_405 . V_410 ) ;
if ( V_654 &&
! F_178 ( & V_654 -> V_52 ) ) {
F_155 ( V_9 , V_382 -> clock ) ;
}
F_23 ( F_28 ( V_67 ) , V_568 ) ;
F_72 ( F_28 ( V_67 ) ) ;
F_21 ( V_2 , V_67 ) ;
F_23 ( F_50 ( V_102 ) , V_268 ) ;
F_72 ( F_50 ( V_102 ) ) ;
V_257 = F_153 ( V_9 , V_265 , V_178 , V_281 ) ;
F_198 ( V_2 ) ;
return V_257 ;
}
static int F_310 ( struct V_8 * V_9 ,
struct V_381 * V_241 ,
struct V_381 * V_382 ,
int V_265 , int V_178 ,
struct V_158 * V_281 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
int V_257 ;
F_311 ( V_2 , V_67 ) ;
V_257 = V_4 -> V_216 . V_668 ( V_9 , V_241 , V_382 ,
V_265 , V_178 , V_281 ) ;
F_312 ( V_2 , V_67 ) ;
if ( V_257 )
V_164 -> V_369 = V_366 ;
else
V_164 -> V_369 = V_363 ;
return V_257 ;
}
static bool F_313 ( struct V_549 * V_550 ,
int V_669 , T_5 V_670 ,
int V_671 , T_5 V_672 ,
int V_673 )
{
struct V_3 * V_4 = V_550 -> V_2 -> V_5 ;
T_6 * V_674 = V_550 -> V_674 ;
T_5 V_104 ;
V_104 = F_3 ( V_669 ) ;
V_104 &= V_670 ;
if ( ! V_674 [ 0 ] )
return ! V_104 ;
if ( ! V_104 )
return false ;
V_104 = F_3 ( V_671 ) ;
V_104 &= ~ V_672 ;
F_23 ( V_671 , V_104 ) ;
for ( V_104 = 0 ; V_104 < V_674 [ 2 ] ; V_104 ++ )
if ( F_3 ( V_673 ) != * ( ( T_5 * ) V_674 + V_104 ) )
return false ;
return true ;
}
static void F_314 ( struct V_549 * V_550 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_550 -> V_2 -> V_5 ;
T_6 * V_674 = V_550 -> V_674 ;
T_5 V_675 ;
T_5 V_676 ;
T_5 V_104 ;
V_104 = F_3 ( V_677 ) ;
if ( V_104 == V_678 || V_104 == V_679 )
V_675 = V_680 ;
else
V_675 = V_681 ;
if ( F_313 ( V_550 ,
V_682 , V_675 ,
V_682 , V_683 ,
V_684 ) )
return;
V_104 = F_3 ( V_682 ) ;
V_104 &= ~ ( V_675 | V_683 ) ;
V_676 = ( V_104 >> 9 ) & 0x1f ;
F_23 ( V_682 , V_104 ) ;
if ( ! V_674 [ 0 ] )
return;
V_676 = F_315 ( T_6 , V_674 [ 2 ] , V_676 ) ;
F_316 ( L_145 , V_676 ) ;
for ( V_104 = 0 ; V_104 < V_676 ; V_104 ++ )
F_23 ( V_684 , * ( ( T_5 * ) V_674 + V_104 ) ) ;
V_104 = F_3 ( V_682 ) ;
V_104 |= V_675 ;
F_23 ( V_682 , V_104 ) ;
}
static void F_317 ( struct V_549 * V_550 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_550 -> V_2 -> V_5 ;
T_6 * V_674 = V_550 -> V_674 ;
T_5 V_675 ;
T_5 V_104 ;
int V_676 ;
int V_685 ;
int V_686 ;
int V_687 ;
int V_688 ;
if ( F_82 ( V_550 -> V_2 ) ) {
V_685 = V_689 ;
V_686 = V_690 ;
V_687 = V_691 ;
V_688 = V_692 ;
} else {
V_685 = V_693 ;
V_686 = V_694 ;
V_687 = V_695 ;
V_688 = V_696 ;
}
V_104 = F_102 ( V_9 ) -> V_67 ;
V_685 += V_104 * 0x100 ;
V_687 += V_104 * 0x100 ;
V_686 += V_104 * 0x100 ;
F_316 ( L_146 , F_47 ( V_104 ) ) ;
V_104 = F_3 ( V_687 ) ;
V_104 = ( V_104 >> 29 ) & 0x3 ;
if ( ! V_104 ) {
F_316 ( L_147 ) ;
V_675 = V_697 ;
V_675 |= V_697 << 4 ;
V_675 |= V_697 << 8 ;
} else {
F_316 ( L_148 , 'A' + V_104 ) ;
V_675 = V_697 << ( ( V_104 - 1 ) * 4 ) ;
}
if ( F_5 ( V_9 , V_20 ) ) {
F_316 ( L_149 ) ;
V_674 [ 5 ] |= ( 1 << 2 ) ;
F_23 ( V_686 , V_698 ) ;
} else
F_23 ( V_686 , 0 ) ;
if ( F_313 ( V_550 ,
V_688 , V_675 ,
V_687 , V_699 ,
V_685 ) )
return;
V_104 = F_3 ( V_688 ) ;
V_104 &= ~ V_675 ;
F_23 ( V_688 , V_104 ) ;
if ( ! V_674 [ 0 ] )
return;
V_104 = F_3 ( V_687 ) ;
V_104 &= ~ V_699 ;
F_23 ( V_687 , V_104 ) ;
V_676 = F_315 ( T_6 , V_674 [ 2 ] , 21 ) ;
F_316 ( L_145 , V_676 ) ;
for ( V_104 = 0 ; V_104 < V_676 ; V_104 ++ )
F_23 ( V_685 , * ( ( T_5 * ) V_674 + V_104 ) ) ;
V_104 = F_3 ( V_688 ) ;
V_104 |= V_675 ;
F_23 ( V_688 , V_104 ) ;
}
void F_318 ( struct V_378 * V_51 ,
struct V_381 * V_241 )
{
struct V_8 * V_9 = V_51 -> V_9 ;
struct V_549 * V_550 ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_550 = F_319 ( V_51 , V_241 ) ;
if ( ! V_550 )
return;
F_316 ( L_150 ,
V_550 -> V_52 . V_227 ,
F_320 ( V_550 ) ,
V_550 -> V_51 -> V_52 . V_227 ,
F_321 ( V_550 -> V_51 ) ) ;
V_550 -> V_674 [ 6 ] = F_322 ( V_550 , V_241 ) / 2 ;
if ( V_4 -> V_216 . V_700 )
V_4 -> V_216 . V_700 ( V_550 , V_9 ) ;
}
void F_202 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_701 = F_323 ( V_164 -> V_67 ) ;
int V_104 ;
if ( ! V_9 -> V_77 || ! V_164 -> V_356 )
return;
if ( F_8 ( V_2 ) )
V_701 = F_324 ( V_164 -> V_67 ) ;
for ( V_104 = 0 ; V_104 < 256 ; V_104 ++ ) {
F_23 ( V_701 + 4 * V_104 ,
( V_164 -> V_702 [ V_104 ] << 16 ) |
( V_164 -> V_703 [ V_104 ] << 8 ) |
V_164 -> V_704 [ V_104 ] ) ;
}
}
static void F_325 ( struct V_8 * V_9 , T_1 V_52 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
bool V_705 = V_52 != 0 ;
T_1 V_706 ;
if ( V_164 -> V_707 == V_705 )
return;
V_706 = F_3 ( V_708 ) ;
if ( V_705 ) {
F_23 ( V_709 , V_52 ) ;
V_706 &= ~ ( V_710 ) ;
V_706 |= V_711 |
V_712 |
V_713 ;
} else
V_706 &= ~ ( V_711 | V_712 ) ;
F_23 ( V_708 , V_706 ) ;
V_164 -> V_707 = V_705 ;
}
static void F_326 ( struct V_8 * V_9 , T_1 V_52 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
bool V_705 = V_52 != 0 ;
if ( V_164 -> V_707 != V_705 ) {
T_5 V_706 = F_3 ( F_327 ( V_67 ) ) ;
if ( V_52 ) {
V_706 &= ~ ( V_714 | V_715 ) ;
V_706 |= V_716 | V_717 ;
V_706 |= V_67 << 28 ;
} else {
V_706 &= ~ ( V_714 | V_717 ) ;
V_706 |= V_718 ;
}
F_23 ( F_327 ( V_67 ) , V_706 ) ;
V_164 -> V_707 = V_705 ;
}
F_23 ( F_328 ( V_67 ) , V_52 ) ;
}
static void F_329 ( struct V_8 * V_9 , T_1 V_52 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
bool V_705 = V_52 != 0 ;
if ( V_164 -> V_707 != V_705 ) {
T_5 V_706 = F_3 ( F_330 ( V_67 ) ) ;
if ( V_52 ) {
V_706 &= ~ V_714 ;
V_706 |= V_716 | V_717 ;
} else {
V_706 &= ~ ( V_714 | V_717 ) ;
V_706 |= V_718 ;
}
F_23 ( F_330 ( V_67 ) , V_706 ) ;
V_164 -> V_707 = V_705 ;
}
F_23 ( F_331 ( V_67 ) , V_52 ) ;
}
static void F_203 ( struct V_8 * V_9 ,
bool V_719 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
int V_265 = V_164 -> V_720 ;
int V_178 = V_164 -> V_721 ;
T_1 V_52 , V_722 ;
bool V_705 ;
V_722 = 0 ;
if ( V_719 && V_9 -> V_77 && V_9 -> V_159 ) {
V_52 = V_164 -> V_723 ;
if ( V_265 > ( int ) V_9 -> V_159 -> V_724 )
V_52 = 0 ;
if ( V_178 > ( int ) V_9 -> V_159 -> V_725 )
V_52 = 0 ;
} else
V_52 = 0 ;
if ( V_265 < 0 ) {
if ( V_265 + V_164 -> V_726 < 0 )
V_52 = 0 ;
V_722 |= V_727 << V_728 ;
V_265 = - V_265 ;
}
V_722 |= V_265 << V_728 ;
if ( V_178 < 0 ) {
if ( V_178 + V_164 -> V_729 < 0 )
V_52 = 0 ;
V_722 |= V_727 << V_730 ;
V_178 = - V_178 ;
}
V_722 |= V_178 << V_730 ;
V_705 = V_52 != 0 ;
if ( ! V_705 && ! V_164 -> V_707 )
return;
if ( F_154 ( V_2 ) ) {
F_23 ( F_332 ( V_67 ) , V_722 ) ;
F_329 ( V_9 , V_52 ) ;
} else {
F_23 ( F_333 ( V_67 ) , V_722 ) ;
if ( F_334 ( V_2 ) || F_335 ( V_2 ) )
F_325 ( V_9 , V_52 ) ;
else
F_326 ( V_9 , V_52 ) ;
}
if ( V_705 )
F_336 ( V_2 , F_101 ( V_9 -> V_159 ) -> V_163 ) ;
}
static int F_337 ( struct V_8 * V_9 ,
struct V_731 * V_732 ,
T_5 V_733 ,
T_5 V_724 , T_5 V_725 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
struct V_162 * V_163 ;
T_5 V_734 ;
int V_257 ;
F_25 ( L_43 ) ;
if ( ! V_733 ) {
F_25 ( L_151 ) ;
V_734 = 0 ;
V_163 = NULL ;
F_119 ( & V_2 -> V_222 ) ;
goto V_735;
}
if ( V_724 != 64 || V_725 != 64 ) {
F_83 ( L_152 ) ;
return - V_260 ;
}
V_163 = F_338 ( F_339 ( V_2 , V_732 , V_733 ) ) ;
if ( & V_163 -> V_52 == NULL )
return - V_736 ;
if ( V_163 -> V_52 . V_239 < V_724 * V_725 * 4 ) {
F_83 ( L_153 ) ;
V_257 = - V_737 ;
goto V_738;
}
F_119 ( & V_2 -> V_222 ) ;
if ( ! V_4 -> V_86 -> V_739 ) {
if ( V_163 -> V_250 ) {
F_83 ( L_154 ) ;
V_257 = - V_260 ;
goto V_740;
}
V_257 = F_137 ( V_163 , 0 , NULL ) ;
if ( V_257 ) {
F_83 ( L_155 ) ;
goto V_740;
}
V_257 = F_340 ( V_163 ) ;
if ( V_257 ) {
F_83 ( L_156 ) ;
goto V_741;
}
V_734 = V_163 -> V_211 ;
} else {
int V_742 = F_71 ( V_2 ) ? 16 * 1024 : 256 ;
V_257 = F_341 ( V_2 , V_163 ,
( V_164 -> V_67 == 0 ) ? V_743 : V_744 ,
V_742 ) ;
if ( V_257 ) {
F_83 ( L_157 ) ;
goto V_740;
}
V_734 = V_163 -> V_745 -> V_733 -> V_746 ;
}
if ( F_11 ( V_2 ) )
F_23 ( V_747 , ( V_725 << 12 ) | V_724 ) ;
V_735:
if ( V_164 -> V_748 ) {
if ( V_4 -> V_86 -> V_739 ) {
if ( V_164 -> V_748 != V_163 )
F_342 ( V_2 , V_164 -> V_748 ) ;
} else
F_140 ( V_164 -> V_748 ) ;
F_343 ( & V_164 -> V_748 -> V_52 ) ;
}
F_120 ( & V_2 -> V_222 ) ;
V_164 -> V_723 = V_734 ;
V_164 -> V_748 = V_163 ;
V_164 -> V_726 = V_724 ;
V_164 -> V_729 = V_725 ;
F_203 ( V_9 , true ) ;
return 0 ;
V_741:
F_140 ( V_163 ) ;
V_740:
F_120 ( & V_2 -> V_222 ) ;
V_738:
F_344 ( & V_163 -> V_52 ) ;
return V_257 ;
}
static int F_345 ( struct V_8 * V_9 , int V_265 , int V_178 )
{
struct V_164 * V_164 = F_102 ( V_9 ) ;
V_164 -> V_720 = V_265 ;
V_164 -> V_721 = V_178 ;
F_203 ( V_9 , true ) ;
return 0 ;
}
void F_346 ( struct V_8 * V_9 , T_4 V_749 , T_4 V_750 ,
T_4 V_751 , int V_752 )
{
struct V_164 * V_164 = F_102 ( V_9 ) ;
V_164 -> V_702 [ V_752 ] = V_749 >> 8 ;
V_164 -> V_703 [ V_752 ] = V_750 >> 8 ;
V_164 -> V_704 [ V_752 ] = V_751 >> 8 ;
}
void F_347 ( struct V_8 * V_9 , T_4 * V_749 , T_4 * V_750 ,
T_4 * V_751 , int V_752 )
{
struct V_164 * V_164 = F_102 ( V_9 ) ;
* V_749 = V_164 -> V_702 [ V_752 ] << 8 ;
* V_750 = V_164 -> V_703 [ V_752 ] << 8 ;
* V_751 = V_164 -> V_704 [ V_752 ] << 8 ;
}
static void F_348 ( struct V_8 * V_9 , T_4 * V_749 , T_4 * V_750 ,
T_4 * V_751 , T_5 V_753 , T_5 V_239 )
{
int V_754 = ( V_753 + V_239 > 256 ) ? 256 : V_753 + V_239 , V_104 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
for ( V_104 = V_753 ; V_104 < V_754 ; V_104 ++ ) {
V_164 -> V_702 [ V_104 ] = V_749 [ V_104 ] >> 8 ;
V_164 -> V_703 [ V_104 ] = V_750 [ V_104 ] >> 8 ;
V_164 -> V_704 [ V_104 ] = V_751 [ V_104 ] >> 8 ;
}
F_202 ( V_9 ) ;
}
static struct V_158 *
F_349 ( struct V_1 * V_2 ,
struct V_755 * V_756 ,
struct V_162 * V_163 )
{
struct V_160 * V_161 ;
int V_257 ;
V_161 = F_125 ( sizeof( * V_161 ) , V_229 ) ;
if ( ! V_161 ) {
F_344 ( & V_163 -> V_52 ) ;
return F_350 ( - V_737 ) ;
}
V_257 = F_351 ( V_2 , V_161 , V_756 , V_163 ) ;
if ( V_257 ) {
F_344 ( & V_163 -> V_52 ) ;
F_121 ( V_161 ) ;
return F_350 ( V_257 ) ;
}
return & V_161 -> V_52 ;
}
static T_1
F_352 ( int V_724 , int V_558 )
{
T_1 V_757 = F_237 ( V_724 * V_558 , 8 ) ;
return F_353 ( V_757 , 64 ) ;
}
static T_1
F_354 ( struct V_381 * V_241 , int V_558 )
{
T_1 V_757 = F_352 ( V_241 -> V_246 , V_558 ) ;
return F_353 ( V_757 * V_241 -> V_247 , V_758 ) ;
}
static struct V_158 *
F_355 ( struct V_1 * V_2 ,
struct V_381 * V_241 ,
int V_272 , int V_558 )
{
struct V_162 * V_163 ;
struct V_755 V_756 ;
V_163 = F_356 ( V_2 ,
F_354 ( V_241 , V_558 ) ) ;
if ( V_163 == NULL )
return F_350 ( - V_737 ) ;
V_756 . V_724 = V_241 -> V_246 ;
V_756 . V_725 = V_241 -> V_247 ;
V_756 . V_169 [ 0 ] = F_352 ( V_756 . V_724 ,
V_558 ) ;
V_756 . V_759 = F_357 ( V_558 , V_272 ) ;
return F_349 ( V_2 , & V_756 , V_163 ) ;
}
static struct V_158 *
F_358 ( struct V_1 * V_2 ,
struct V_381 * V_241 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_162 * V_163 ;
struct V_158 * V_159 ;
if ( V_4 -> V_760 == NULL )
return NULL ;
V_163 = V_4 -> V_760 -> V_761 . V_163 ;
if ( V_163 == NULL )
return NULL ;
V_159 = & V_4 -> V_760 -> V_761 . V_52 ;
if ( V_159 -> V_169 [ 0 ] < F_352 ( V_241 -> V_246 ,
V_159 -> V_270 ) )
return NULL ;
if ( V_163 -> V_52 . V_239 < V_241 -> V_247 * V_159 -> V_169 [ 0 ] )
return NULL ;
return V_159 ;
}
bool F_359 ( struct V_50 * V_50 ,
struct V_549 * V_550 ,
struct V_381 * V_241 ,
struct V_762 * V_763 )
{
struct V_164 * V_164 ;
struct V_8 * V_764 ;
struct V_378 * V_51 = & V_50 -> V_52 ;
struct V_8 * V_9 = NULL ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_158 * V_281 ;
int V_104 = - 1 ;
F_25 ( L_158 ,
V_550 -> V_52 . V_227 , F_320 ( V_550 ) ,
V_51 -> V_52 . V_227 , F_321 ( V_51 ) ) ;
if ( V_51 -> V_9 ) {
V_9 = V_51 -> V_9 ;
V_164 = F_102 ( V_9 ) ;
V_763 -> V_369 = V_164 -> V_369 ;
V_763 -> V_765 = false ;
if ( V_164 -> V_369 != V_363 ) {
struct V_379 * V_380 ;
struct V_375 * V_376 ;
V_376 = V_9 -> V_377 ;
V_376 -> V_370 ( V_9 , V_363 ) ;
V_380 = V_51 -> V_377 ;
V_380 -> V_370 ( V_51 , V_363 ) ;
}
return true ;
}
F_14 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_104 ++ ;
if ( ! ( V_51 -> V_766 & ( 1 << V_104 ) ) )
continue;
if ( ! V_764 -> V_77 ) {
V_9 = V_764 ;
break;
}
}
if ( ! V_9 ) {
F_25 ( L_159 ) ;
return false ;
}
V_51 -> V_9 = V_9 ;
V_550 -> V_51 = V_51 ;
V_164 = F_102 ( V_9 ) ;
V_763 -> V_369 = V_164 -> V_369 ;
V_763 -> V_765 = true ;
V_763 -> V_767 = NULL ;
if ( ! V_241 )
V_241 = & V_768 ;
V_281 = V_9 -> V_159 ;
V_9 -> V_159 = F_358 ( V_2 , V_241 ) ;
if ( V_9 -> V_159 == NULL ) {
F_25 ( L_160 ) ;
V_9 -> V_159 = F_355 ( V_2 , V_241 , 24 , 32 ) ;
V_763 -> V_767 = V_9 -> V_159 ;
} else
F_25 ( L_161 ) ;
if ( F_360 ( V_9 -> V_159 ) ) {
F_25 ( L_162 ) ;
V_9 -> V_159 = V_281 ;
return false ;
}
if ( ! F_361 ( V_9 , V_241 , 0 , 0 , V_281 ) ) {
F_25 ( L_163 ) ;
if ( V_763 -> V_767 )
V_763 -> V_767 -> V_769 -> V_770 ( V_763 -> V_767 ) ;
V_9 -> V_159 = V_281 ;
return false ;
}
F_21 ( V_2 , V_164 -> V_67 ) ;
return true ;
}
void F_362 ( struct V_50 * V_50 ,
struct V_549 * V_550 ,
struct V_762 * V_763 )
{
struct V_378 * V_51 = & V_50 -> V_52 ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_8 * V_9 = V_51 -> V_9 ;
struct V_379 * V_380 = V_51 -> V_377 ;
struct V_375 * V_376 = V_9 -> V_377 ;
F_25 ( L_158 ,
V_550 -> V_52 . V_227 , F_320 ( V_550 ) ,
V_51 -> V_52 . V_227 , F_321 ( V_51 ) ) ;
if ( V_763 -> V_765 ) {
V_550 -> V_51 = NULL ;
F_363 ( V_2 ) ;
if ( V_763 -> V_767 )
V_763 -> V_767 -> V_769 -> V_770 ( V_763 -> V_767 ) ;
return;
}
if ( V_763 -> V_369 != V_363 ) {
V_380 -> V_370 ( V_51 , V_763 -> V_369 ) ;
V_376 -> V_370 ( V_9 , V_763 -> V_369 ) ;
}
}
static int F_364 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
T_1 V_567 = F_3 ( F_35 ( V_67 ) ) ;
T_1 V_564 ;
T_3 clock ;
if ( ( V_567 & V_771 ) == 0 )
V_564 = F_3 ( F_280 ( V_67 ) ) ;
else
V_564 = F_3 ( F_281 ( V_67 ) ) ;
clock . V_47 = ( V_564 & V_772 ) >> V_773 ;
if ( F_10 ( V_2 ) ) {
clock . V_45 = F_254 ( ( V_564 & V_774 ) >> V_775 ) - 1 ;
clock . V_40 = ( V_564 & V_776 ) >> V_777 ;
} else {
clock . V_45 = ( V_564 & V_778 ) >> V_775 ;
clock . V_40 = ( V_564 & V_779 ) >> V_777 ;
}
if ( ! F_11 ( V_2 ) ) {
if ( F_10 ( V_2 ) )
clock . V_42 = F_254 ( ( V_567 & V_780 ) >>
V_591 ) ;
else
clock . V_42 = F_254 ( ( V_567 & V_781 ) >>
V_592 ) ;
switch ( V_567 & V_782 ) {
case V_587 :
clock . V_43 = V_567 & V_594 ?
5 : 10 ;
break;
case V_586 :
clock . V_43 = V_567 & V_595 ?
7 : 14 ;
break;
default:
F_25 ( L_164
L_165 , ( int ) ( V_567 & V_782 ) ) ;
return 0 ;
}
F_13 ( V_2 , 96000 , & clock ) ;
} else {
bool V_575 = ( V_67 == 1 ) && ( F_3 ( V_24 ) & V_122 ) ;
if ( V_575 ) {
clock . V_42 = F_254 ( ( V_567 & V_783 ) >>
V_592 ) ;
clock . V_43 = 14 ;
if ( ( V_567 & V_784 ) ==
V_602 ) {
F_13 ( V_2 , 66000 , & clock ) ;
} else
F_13 ( V_2 , 48000 , & clock ) ;
} else {
if ( V_567 & V_599 )
clock . V_42 = 2 ;
else {
clock . V_42 = ( ( V_567 & V_785 ) >>
V_592 ) + 2 ;
}
if ( V_567 & V_600 )
clock . V_43 = 4 ;
else
clock . V_43 = 2 ;
F_13 ( V_2 , 48000 , & clock ) ;
}
}
return clock . V_46 ;
}
struct V_381 * F_365 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
struct V_381 * V_241 ;
int V_786 = F_3 ( F_181 ( V_67 ) ) ;
int V_787 = F_3 ( F_185 ( V_67 ) ) ;
int V_788 = F_3 ( F_187 ( V_67 ) ) ;
int V_789 = F_3 ( F_191 ( V_67 ) ) ;
V_241 = F_125 ( sizeof( * V_241 ) , V_229 ) ;
if ( ! V_241 )
return NULL ;
V_241 -> clock = F_364 ( V_2 , V_9 ) ;
V_241 -> V_246 = ( V_786 & 0xffff ) + 1 ;
V_241 -> V_459 = ( ( V_786 & 0xffff0000 ) >> 16 ) + 1 ;
V_241 -> V_790 = ( V_787 & 0xffff ) + 1 ;
V_241 -> V_791 = ( ( V_787 & 0xffff0000 ) >> 16 ) + 1 ;
V_241 -> V_247 = ( V_788 & 0xffff ) + 1 ;
V_241 -> V_792 = ( ( V_788 & 0xffff0000 ) >> 16 ) + 1 ;
V_241 -> V_793 = ( V_789 & 0xffff ) + 1 ;
V_241 -> V_794 = ( ( V_789 & 0xffff0000 ) >> 16 ) + 1 ;
F_366 ( V_241 ) ;
F_225 ( V_241 , 0 ) ;
return V_241 ;
}
static void F_367 ( unsigned long V_795 )
{
struct V_1 * V_2 = (struct V_1 * ) V_795 ;
T_7 * V_4 = V_2 -> V_5 ;
if ( ! F_368 ( & V_4 -> V_261 . V_796 ) ) {
F_369 ( & V_4 -> V_797 , V_75 +
F_30 ( V_798 ) ) ;
return;
}
V_4 -> V_799 = false ;
F_370 ( V_4 -> V_800 , & V_4 -> V_801 ) ;
}
static void F_371 ( unsigned long V_795 )
{
struct V_164 * V_164 = (struct V_164 * ) V_795 ;
struct V_8 * V_9 = & V_164 -> V_52 ;
T_7 * V_4 = V_9 -> V_2 -> V_5 ;
struct V_160 * V_161 ;
V_161 = F_101 ( V_9 -> V_159 ) ;
if ( V_161 && V_161 -> V_163 -> V_356 ) {
F_369 ( & V_164 -> V_797 , V_75 +
F_30 ( V_802 ) ) ;
return;
}
V_164 -> V_799 = false ;
F_370 ( V_4 -> V_800 , & V_4 -> V_801 ) ;
}
static void F_148 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
int V_67 = V_164 -> V_67 ;
int V_803 = F_35 ( V_67 ) ;
int V_567 ;
if ( F_8 ( V_2 ) )
return;
if ( ! V_4 -> V_583 )
return;
V_567 = F_3 ( V_803 ) ;
if ( ! F_289 ( V_2 ) && ( V_567 & V_771 ) ) {
F_316 ( L_166 ) ;
F_46 ( V_4 , V_67 ) ;
V_567 &= ~ V_771 ;
F_23 ( V_803 , V_567 ) ;
F_21 ( V_2 , V_67 ) ;
V_567 = F_3 ( V_803 ) ;
if ( V_567 & V_771 )
F_316 ( L_167 ) ;
}
F_369 ( & V_164 -> V_797 , V_75 +
F_30 ( V_802 ) ) ;
}
static void F_372 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_7 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
if ( F_8 ( V_2 ) )
return;
if ( ! V_4 -> V_583 )
return;
if ( ! F_289 ( V_2 ) && V_164 -> V_566 ) {
int V_67 = V_164 -> V_67 ;
int V_803 = F_35 ( V_67 ) ;
T_1 V_567 ;
F_316 ( L_168 ) ;
F_46 ( V_4 , V_67 ) ;
V_567 = F_3 ( V_803 ) ;
V_567 |= V_771 ;
F_23 ( V_803 , V_567 ) ;
F_21 ( V_2 , V_67 ) ;
V_567 = F_3 ( V_803 ) ;
if ( ! ( V_567 & V_771 ) )
F_316 ( L_169 ) ;
}
}
static void F_373 ( struct V_218 * V_221 )
{
T_7 * V_4 = F_117 ( V_221 , T_7 ,
V_801 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_8 * V_9 ;
struct V_164 * V_164 ;
if ( ! V_232 )
return;
F_119 ( & V_2 -> V_222 ) ;
F_374 ( V_4 ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_9 -> V_159 )
continue;
V_164 = F_102 ( V_9 ) ;
if ( ! V_164 -> V_799 )
F_372 ( V_9 ) ;
}
F_120 ( & V_2 -> V_222 ) ;
}
void F_336 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = NULL ;
struct V_160 * V_161 ;
struct V_164 * V_164 ;
if ( ! F_375 ( V_2 , V_804 ) )
return;
if ( ! V_4 -> V_799 )
V_4 -> V_799 = true ;
else
F_369 ( & V_4 -> V_797 , V_75 +
F_30 ( V_798 ) ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_9 -> V_159 )
continue;
V_164 = F_102 ( V_9 ) ;
V_161 = F_101 ( V_9 -> V_159 ) ;
if ( V_161 -> V_163 == V_163 ) {
if ( ! V_164 -> V_799 ) {
F_148 ( V_9 ) ;
V_164 -> V_799 = true ;
} else {
F_369 ( & V_164 -> V_797 , V_75 +
F_30 ( V_802 ) ) ;
}
}
}
}
static void F_376 ( struct V_8 * V_9 )
{
struct V_164 * V_164 = F_102 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_805 * V_221 ;
unsigned long V_242 ;
F_377 ( & V_2 -> V_806 , V_242 ) ;
V_221 = V_164 -> V_807 ;
V_164 -> V_807 = NULL ;
F_378 ( & V_2 -> V_806 , V_242 ) ;
if ( V_221 ) {
F_379 ( & V_221 -> V_221 ) ;
F_121 ( V_221 ) ;
}
F_380 ( V_9 ) ;
F_121 ( V_164 ) ;
}
static void F_381 ( struct V_218 * V_219 )
{
struct V_805 * V_221 =
F_117 ( V_219 , struct V_805 , V_221 ) ;
F_119 ( & V_221 -> V_2 -> V_222 ) ;
F_141 ( V_221 -> V_808 ) ;
F_343 ( & V_221 -> V_809 -> V_52 ) ;
F_343 ( & V_221 -> V_808 -> V_52 ) ;
F_129 ( V_221 -> V_2 ) ;
F_120 ( & V_221 -> V_2 -> V_222 ) ;
F_121 ( V_221 ) ;
}
static void F_382 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
struct V_805 * V_221 ;
struct V_162 * V_163 ;
struct V_810 * V_811 ;
struct V_812 V_813 , V_814 ;
unsigned long V_242 ;
if ( V_164 == NULL )
return;
F_383 ( & V_813 ) ;
F_377 ( & V_2 -> V_806 , V_242 ) ;
V_221 = V_164 -> V_807 ;
if ( V_221 == NULL || ! V_221 -> V_815 ) {
F_378 ( & V_2 -> V_806 , V_242 ) ;
return;
}
V_164 -> V_807 = NULL ;
if ( V_221 -> V_816 ) {
V_811 = V_221 -> V_816 ;
V_811 -> V_816 . V_817 = F_384 ( V_2 , V_164 -> V_67 , & V_814 ) ;
if ( 10 * ( F_385 ( & V_813 ) - F_385 ( & V_814 ) ) >
9 * V_9 -> V_818 ) {
V_811 -> V_816 . V_817 ++ ;
V_814 = F_386 ( F_385 ( & V_814 ) +
V_9 -> V_818 ) ;
}
V_811 -> V_816 . V_819 = V_814 . V_819 ;
V_811 -> V_816 . V_820 = V_814 . V_820 ;
F_387 ( & V_811 -> V_52 . V_821 ,
& V_811 -> V_52 . V_822 -> V_823 ) ;
F_388 ( & V_811 -> V_52 . V_822 -> V_824 ) ;
}
F_389 ( V_2 , V_164 -> V_67 ) ;
F_378 ( & V_2 -> V_806 , V_242 ) ;
V_163 = V_221 -> V_808 ;
F_390 ( 1 << V_164 -> V_102 ,
& V_163 -> V_285 . V_825 ) ;
if ( F_151 ( & V_163 -> V_285 ) == 0 )
F_391 ( & V_4 -> V_283 ) ;
F_392 ( & V_221 -> V_221 ) ;
F_393 ( V_164 -> V_102 , V_221 -> V_809 ) ;
}
void F_394 ( struct V_1 * V_2 , int V_67 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = V_4 -> V_142 [ V_67 ] ;
F_382 ( V_2 , V_9 ) ;
}
void F_395 ( struct V_1 * V_2 , int V_102 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = V_4 -> V_826 [ V_102 ] ;
F_382 ( V_2 , V_9 ) ;
}
void F_396 ( struct V_1 * V_2 , int V_102 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 =
F_102 ( V_4 -> V_826 [ V_102 ] ) ;
unsigned long V_242 ;
F_377 ( & V_2 -> V_806 , V_242 ) ;
if ( V_164 -> V_807 ) {
if ( ( ++ V_164 -> V_807 -> V_815 ) > 1 )
F_83 ( L_170 ) ;
} else {
F_316 ( L_171 ) ;
}
F_378 ( & V_2 -> V_806 , V_242 ) ;
}
static int F_397 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_158 * V_159 ,
struct V_162 * V_163 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
unsigned long V_827 ;
T_1 V_828 ;
int V_257 ;
V_257 = F_133 ( V_2 , V_163 , F_173 ( V_4 ) ) ;
if ( V_257 )
goto V_829;
V_827 = V_9 -> V_178 * V_159 -> V_169 [ 0 ] + V_9 -> V_265 * V_159 -> V_270 / 8 ;
V_257 = F_398 ( 6 ) ;
if ( V_257 )
goto V_829;
if ( V_164 -> V_102 )
V_828 = V_830 ;
else
V_828 = V_831 ;
F_399 ( V_832 | V_828 ) ;
F_399 ( V_833 ) ;
F_399 ( V_834 |
F_400 ( V_164 -> V_102 ) ) ;
F_399 ( V_159 -> V_169 [ 0 ] ) ;
F_399 ( V_163 -> V_211 + V_827 ) ;
F_399 ( 0 ) ;
F_401 () ;
V_829:
return V_257 ;
}
static int F_402 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_158 * V_159 ,
struct V_162 * V_163 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
unsigned long V_827 ;
T_1 V_828 ;
int V_257 ;
V_257 = F_133 ( V_2 , V_163 , F_173 ( V_4 ) ) ;
if ( V_257 )
goto V_829;
V_827 = V_9 -> V_178 * V_159 -> V_169 [ 0 ] + V_9 -> V_265 * V_159 -> V_270 / 8 ;
V_257 = F_398 ( 6 ) ;
if ( V_257 )
goto V_829;
if ( V_164 -> V_102 )
V_828 = V_830 ;
else
V_828 = V_831 ;
F_399 ( V_832 | V_828 ) ;
F_399 ( V_833 ) ;
F_399 ( V_835 |
F_400 ( V_164 -> V_102 ) ) ;
F_399 ( V_159 -> V_169 [ 0 ] ) ;
F_399 ( V_163 -> V_211 + V_827 ) ;
F_399 ( V_833 ) ;
F_401 () ;
V_829:
return V_257 ;
}
static int F_403 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_158 * V_159 ,
struct V_162 * V_163 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
T_5 V_836 , V_837 ;
int V_257 ;
V_257 = F_133 ( V_2 , V_163 , F_173 ( V_4 ) ) ;
if ( V_257 )
goto V_829;
V_257 = F_398 ( 4 ) ;
if ( V_257 )
goto V_829;
F_399 ( V_834 |
F_400 ( V_164 -> V_102 ) ) ;
F_399 ( V_159 -> V_169 [ 0 ] ) ;
F_399 ( V_163 -> V_211 | V_163 -> V_250 ) ;
V_836 = 0 ;
V_837 = F_3 ( F_293 ( V_164 -> V_67 ) ) & 0x0fff0fff ;
F_399 ( V_836 | V_837 ) ;
F_401 () ;
V_829:
return V_257 ;
}
static int F_404 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_158 * V_159 ,
struct V_162 * V_163 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
T_5 V_836 , V_837 ;
int V_257 ;
V_257 = F_133 ( V_2 , V_163 , F_173 ( V_4 ) ) ;
if ( V_257 )
goto V_829;
V_257 = F_398 ( 4 ) ;
if ( V_257 )
goto V_829;
F_399 ( V_834 |
F_400 ( V_164 -> V_102 ) ) ;
F_399 ( V_159 -> V_169 [ 0 ] | V_163 -> V_250 ) ;
F_399 ( V_163 -> V_211 ) ;
V_836 = 0 ;
V_837 = F_3 ( F_293 ( V_164 -> V_67 ) ) & 0x0fff0fff ;
F_399 ( V_836 | V_837 ) ;
F_401 () ;
V_829:
return V_257 ;
}
static int F_405 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_158 * V_159 ,
struct V_162 * V_163 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
struct V_254 * V_331 = & V_4 -> V_331 [ V_838 ] ;
int V_257 ;
V_257 = F_133 ( V_2 , V_163 , V_331 ) ;
if ( V_257 )
goto V_829;
V_257 = F_406 ( V_331 , 4 ) ;
if ( V_257 )
goto V_829;
F_407 ( V_331 , V_835 | ( V_164 -> V_102 << 19 ) ) ;
F_407 ( V_331 , ( V_159 -> V_169 [ 0 ] | V_163 -> V_250 ) ) ;
F_407 ( V_331 , ( V_163 -> V_211 ) ) ;
F_407 ( V_331 , ( V_833 ) ) ;
F_408 ( V_331 ) ;
V_829:
return V_257 ;
}
static int F_409 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_158 * V_159 ,
struct V_162 * V_163 )
{
return - V_839 ;
}
static int F_410 ( struct V_8 * V_9 ,
struct V_158 * V_159 ,
struct V_810 * V_816 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_160 * V_161 ;
struct V_162 * V_163 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
struct V_805 * V_221 ;
unsigned long V_242 ;
int V_257 ;
V_221 = F_125 ( sizeof *V_221 , V_229 ) ;
if ( V_221 == NULL )
return - V_737 ;
V_221 -> V_816 = V_816 ;
V_221 -> V_2 = V_9 -> V_2 ;
V_161 = F_101 ( V_9 -> V_159 ) ;
V_221 -> V_808 = V_161 -> V_163 ;
F_411 ( & V_221 -> V_221 , F_381 ) ;
V_257 = F_412 ( V_2 , V_164 -> V_67 ) ;
if ( V_257 )
goto V_840;
F_377 ( & V_2 -> V_806 , V_242 ) ;
if ( V_164 -> V_807 ) {
F_378 ( & V_2 -> V_806 , V_242 ) ;
F_121 ( V_221 ) ;
F_389 ( V_2 , V_164 -> V_67 ) ;
F_316 ( L_172 ) ;
return - V_841 ;
}
V_164 -> V_807 = V_221 ;
F_378 ( & V_2 -> V_806 , V_242 ) ;
V_161 = F_101 ( V_159 ) ;
V_163 = V_161 -> V_163 ;
F_119 ( & V_2 -> V_222 ) ;
F_413 ( & V_221 -> V_808 -> V_52 ) ;
F_413 ( & V_163 -> V_52 ) ;
V_9 -> V_159 = V_159 ;
V_221 -> V_809 = V_163 ;
V_221 -> V_842 = true ;
F_414 ( 1 << V_164 -> V_102 , & V_221 -> V_808 -> V_285 ) ;
V_257 = V_4 -> V_216 . V_843 ( V_2 , V_9 , V_159 , V_163 ) ;
if ( V_257 )
goto V_844;
F_128 ( V_2 ) ;
F_120 ( & V_2 -> V_222 ) ;
F_415 ( V_164 -> V_102 , V_163 ) ;
return 0 ;
V_844:
F_416 ( 1 << V_164 -> V_102 , & V_221 -> V_808 -> V_285 ) ;
F_343 ( & V_221 -> V_808 -> V_52 ) ;
F_343 ( & V_163 -> V_52 ) ;
F_120 ( & V_2 -> V_222 ) ;
F_377 ( & V_2 -> V_806 , V_242 ) ;
V_164 -> V_807 = NULL ;
F_378 ( & V_2 -> V_806 , V_242 ) ;
F_389 ( V_2 , V_164 -> V_67 ) ;
V_840:
F_121 ( V_221 ) ;
return V_257 ;
}
static void F_417 ( struct V_1 * V_2 ,
int V_67 , int V_102 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_71 , V_79 ;
F_418 (pipe) {
V_71 = F_28 ( V_67 ) ;
F_23 ( V_71 , F_3 ( V_71 ) & ~ V_845 ) ;
}
if ( F_8 ( V_2 ) )
return;
V_71 = F_50 ( V_102 ) ;
V_79 = F_3 ( V_71 ) ;
if ( ( V_79 & V_103 ) == 0 )
return;
if ( ! ! ( V_79 & V_106 ) == V_67 )
return;
V_67 = ! V_67 ;
F_95 ( V_4 , V_102 , V_67 ) ;
F_89 ( V_4 , V_67 ) ;
}
static void F_419 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_164 * V_164 = F_102 ( V_9 ) ;
V_164 -> V_369 = - 1 ;
F_417 ( V_2 , V_164 -> V_67 , V_164 -> V_102 ) ;
}
static void F_420 ( struct V_1 * V_2 , int V_67 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_164 * V_164 ;
int V_104 ;
V_164 = F_125 ( sizeof( struct V_164 ) + ( V_846 * sizeof( struct V_549 * ) ) , V_229 ) ;
if ( V_164 == NULL )
return;
F_421 ( V_2 , & V_164 -> V_52 , & V_847 ) ;
F_422 ( & V_164 -> V_52 , 256 ) ;
for ( V_104 = 0 ; V_104 < 256 ; V_104 ++ ) {
V_164 -> V_702 [ V_104 ] = V_104 ;
V_164 -> V_703 [ V_104 ] = V_104 ;
V_164 -> V_704 [ V_104 ] = V_104 ;
}
V_164 -> V_67 = V_67 ;
V_164 -> V_102 = V_67 ;
if ( F_70 ( V_2 ) && F_290 ( V_2 ) ) {
F_25 ( L_173 ) ;
V_164 -> V_102 = ! V_67 ;
}
F_69 ( V_67 >= F_239 ( V_4 -> V_826 ) ||
V_4 -> V_826 [ V_164 -> V_102 ] != NULL ) ;
V_4 -> V_826 [ V_164 -> V_102 ] = & V_164 -> V_52 ;
V_4 -> V_142 [ V_164 -> V_67 ] = & V_164 -> V_52 ;
F_419 ( & V_164 -> V_52 ) ;
V_164 -> V_356 = true ;
V_164 -> V_558 = 24 ;
if ( F_8 ( V_2 ) ) {
if ( V_67 == 2 && F_154 ( V_2 ) )
V_164 -> V_362 = true ;
V_848 . V_849 = F_217 ;
V_848 . V_850 = F_218 ;
} else {
V_848 . V_849 = F_215 ;
V_848 . V_850 = F_216 ;
}
F_423 ( & V_164 -> V_52 , & V_848 ) ;
V_164 -> V_799 = false ;
F_424 ( & V_164 -> V_797 , F_371 ,
( unsigned long ) V_164 ) ;
}
int F_425 ( struct V_1 * V_2 , void * V_851 ,
struct V_731 * V_732 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_852 * V_853 = V_851 ;
struct V_854 * V_855 ;
struct V_164 * V_9 ;
if ( ! V_4 ) {
F_83 ( L_174 ) ;
return - V_260 ;
}
V_855 = F_426 ( V_2 , V_853 -> V_856 ,
V_857 ) ;
if ( ! V_855 ) {
F_83 ( L_175 ) ;
return - V_260 ;
}
V_9 = F_102 ( F_427 ( V_855 ) ) ;
V_853 -> V_67 = V_9 -> V_67 ;
return 0 ;
}
static int F_428 ( struct V_1 * V_2 , int V_858 )
{
struct V_50 * V_51 ;
int V_859 = 0 ;
int V_860 = 0 ;
F_14 (encoder, &dev->mode_config.encoder_list, base.head) {
if ( V_858 & V_51 -> V_861 )
V_859 |= ( 1 << V_860 ) ;
V_860 ++ ;
}
return V_859 ;
}
static bool F_429 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_70 ( V_2 ) )
return false ;
if ( ( F_3 ( V_298 ) & V_862 ) == 0 )
return false ;
if ( F_2 ( V_2 ) &&
( F_3 ( V_863 ) & V_864 ) )
return false ;
return true ;
}
static void F_430 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_50 * V_51 ;
bool V_865 = false ;
bool V_637 ;
V_637 = F_431 ( V_2 ) ;
if ( ! V_637 && ! F_8 ( V_2 ) ) {
F_23 ( V_866 , 0 ) ;
}
if ( F_8 ( V_2 ) ) {
V_865 = F_432 ( V_2 ) ;
if ( F_429 ( V_2 ) )
F_433 ( V_2 , V_298 ) ;
if ( V_865 && ( F_3 ( V_130 ) & V_862 ) )
F_433 ( V_2 , V_130 ) ;
}
F_434 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
int V_64 ;
if ( F_3 ( V_133 ) & V_867 ) {
V_64 = F_435 ( V_2 , V_868 ) ;
if ( ! V_64 )
F_436 ( V_2 , V_133 ) ;
if ( ! V_64 && ( F_3 ( V_126 ) & V_862 ) )
F_433 ( V_2 , V_126 ) ;
}
if ( F_3 ( V_134 ) & V_867 )
F_436 ( V_2 , V_134 ) ;
if ( F_3 ( V_135 ) & V_867 )
F_436 ( V_2 , V_135 ) ;
if ( F_3 ( V_128 ) & V_862 )
F_433 ( V_2 , V_128 ) ;
if ( ! V_865 && ( F_3 ( V_130 ) & V_862 ) )
F_433 ( V_2 , V_130 ) ;
} else if ( F_437 ( V_2 ) ) {
bool V_64 = false ;
if ( F_3 ( V_869 ) & V_870 ) {
F_25 ( L_176 ) ;
V_64 = F_435 ( V_2 , V_869 ) ;
if ( ! V_64 && F_438 ( V_2 ) ) {
F_25 ( L_177 ) ;
F_436 ( V_2 , V_869 ) ;
}
if ( ! V_64 && F_439 ( V_2 ) ) {
F_25 ( L_178 ) ;
F_433 ( V_2 , V_871 ) ;
}
}
if ( F_3 ( V_869 ) & V_870 ) {
F_25 ( L_179 ) ;
V_64 = F_435 ( V_2 , V_872 ) ;
}
if ( ! V_64 && ( F_3 ( V_872 ) & V_870 ) ) {
if ( F_438 ( V_2 ) ) {
F_25 ( L_180 ) ;
F_436 ( V_2 , V_872 ) ;
}
if ( F_439 ( V_2 ) ) {
F_25 ( L_181 ) ;
F_433 ( V_2 , V_873 ) ;
}
}
if ( F_439 ( V_2 ) &&
( F_3 ( V_874 ) & V_862 ) ) {
F_25 ( L_182 ) ;
F_433 ( V_2 , V_874 ) ;
}
} else if ( F_11 ( V_2 ) )
F_440 ( V_2 ) ;
if ( F_441 ( V_2 ) )
F_442 ( V_2 ) ;
F_14 (encoder, &dev->mode_config.encoder_list, base.head) {
V_51 -> V_52 . V_766 = V_51 -> V_875 ;
V_51 -> V_52 . V_876 =
F_428 ( V_2 , V_51 -> V_861 ) ;
}
F_363 ( V_2 ) ;
if ( F_8 ( V_2 ) )
F_294 ( V_2 ) ;
}
static void F_443 ( struct V_158 * V_159 )
{
struct V_160 * V_161 = F_101 ( V_159 ) ;
F_444 ( V_159 ) ;
F_344 ( & V_161 -> V_163 -> V_52 ) ;
F_121 ( V_161 ) ;
}
static int F_445 ( struct V_158 * V_159 ,
struct V_731 * V_732 ,
unsigned int * V_733 )
{
struct V_160 * V_161 = F_101 ( V_159 ) ;
struct V_162 * V_163 = V_161 -> V_163 ;
return F_446 ( V_732 , & V_163 -> V_52 , V_733 ) ;
}
int F_351 ( struct V_1 * V_2 ,
struct V_160 * V_161 ,
struct V_755 * V_756 ,
struct V_162 * V_163 )
{
int V_257 ;
if ( V_163 -> V_250 == V_259 )
return - V_260 ;
if ( V_756 -> V_169 [ 0 ] & 63 )
return - V_260 ;
switch ( V_756 -> V_759 ) {
case V_877 :
case V_878 :
case V_879 :
case V_880 :
case V_881 :
case V_882 :
case V_883 :
break;
case V_884 :
case V_885 :
case V_886 :
case V_887 :
break;
default:
F_25 ( L_183 ,
V_756 -> V_759 ) ;
return - V_260 ;
}
V_257 = F_447 ( V_2 , & V_161 -> V_52 , & V_888 ) ;
if ( V_257 ) {
F_83 ( L_184 , V_257 ) ;
return V_257 ;
}
F_448 ( & V_161 -> V_52 , V_756 ) ;
V_161 -> V_163 = V_163 ;
return 0 ;
}
static struct V_158 *
F_449 ( struct V_1 * V_2 ,
struct V_731 * V_889 ,
struct V_755 * V_756 )
{
struct V_162 * V_163 ;
V_163 = F_338 ( F_339 ( V_2 , V_889 ,
V_756 -> V_890 [ 0 ] ) ) ;
if ( & V_163 -> V_52 == NULL )
return F_350 ( - V_736 ) ;
return F_349 ( V_2 , V_756 , V_163 ) ;
}
static struct V_162 *
F_450 ( struct V_1 * V_2 )
{
struct V_162 * V_891 ;
int V_257 ;
F_451 ( ! F_452 ( & V_2 -> V_222 ) ) ;
V_891 = F_356 ( V_2 , 4096 ) ;
if ( ! V_891 ) {
F_276 ( L_185 ) ;
return NULL ;
}
V_257 = F_453 ( V_891 , 4096 , true ) ;
if ( V_257 ) {
F_83 ( L_186 , V_257 ) ;
goto V_892;
}
V_257 = F_454 ( V_891 , 1 ) ;
if ( V_257 ) {
F_83 ( L_187 , V_257 ) ;
goto V_264;
}
return V_891 ;
V_264:
F_140 ( V_891 ) ;
V_892:
F_343 ( & V_891 -> V_52 ) ;
F_120 ( & V_2 -> V_222 ) ;
return NULL ;
}
bool F_455 ( struct V_1 * V_2 , T_8 V_79 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_893 ;
V_893 = F_456 ( V_894 ) ;
if ( V_893 & V_895 ) {
F_276 ( L_188 ) ;
return false ;
}
V_893 = ( V_896 << V_897 ) |
( V_79 << V_898 ) | V_899 ;
F_457 ( V_894 , V_893 ) ;
F_458 ( V_894 ) ;
V_893 |= V_895 ;
F_457 ( V_894 , V_893 ) ;
return true ;
}
void F_459 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_900 = F_3 ( V_901 ) ;
T_8 V_902 , V_903 , V_904 , V_905 ;
F_457 ( V_906 , F_3 ( V_906 ) | V_907 ) ;
F_457 ( V_908 , F_3 ( V_908 ) | V_909 ) ;
F_23 ( V_910 , 100000 ) ;
F_23 ( V_911 , 100000 ) ;
F_23 ( V_912 , 90000 ) ;
F_23 ( V_913 , 80000 ) ;
F_23 ( V_914 , 1 ) ;
V_902 = ( V_900 & V_915 ) >> V_916 ;
V_903 = ( V_900 & V_917 ) ;
V_904 = ( V_900 & V_918 ) >>
V_919 ;
V_905 = ( F_3 ( V_920 + ( V_904 * 4 ) ) & V_921 ) >>
V_922 ;
V_4 -> V_902 = V_902 ;
V_4 -> V_904 = V_904 ;
V_4 -> V_923 = V_904 ;
V_4 -> V_924 = V_903 ;
V_4 -> V_925 = V_904 ;
F_316 ( L_189 ,
V_902 , V_903 , V_904 ) ;
F_23 ( V_926 , V_927 | V_928 ) ;
F_23 ( V_929 , V_905 ) ;
F_72 ( V_929 ) ;
V_900 |= V_930 ;
F_23 ( V_901 , V_900 ) ;
if ( F_24 ( ( F_3 ( V_894 ) & V_895 ) == 0 , 10 ) )
F_83 ( L_190 ) ;
F_460 ( 1 ) ;
F_455 ( V_2 , V_904 ) ;
V_4 -> V_931 = F_3 ( 0x112e4 ) + F_3 ( 0x112e8 ) +
F_3 ( 0x112e0 ) ;
V_4 -> V_932 = F_461 ( V_75 ) ;
V_4 -> V_933 = F_3 ( 0x112f4 ) ;
F_462 ( & V_4 -> V_934 ) ;
}
void F_463 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_893 = F_456 ( V_894 ) ;
F_23 ( V_926 , F_3 ( V_926 ) & ~ V_928 ) ;
F_23 ( V_935 , V_936 ) ;
F_23 ( V_937 , F_3 ( V_937 ) & ~ V_938 ) ;
F_23 ( V_939 , V_938 ) ;
F_23 ( V_940 , F_3 ( V_940 ) | V_938 ) ;
F_455 ( V_2 , V_4 -> V_904 ) ;
F_460 ( 1 ) ;
V_893 |= V_895 ;
F_23 ( V_894 , V_893 ) ;
F_460 ( 1 ) ;
}
void F_464 ( struct V_1 * V_2 , T_8 V_79 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_941 ;
V_941 = ( V_79 & 0x3ff ) << 25 ;
F_23 ( V_942 , V_941 ) ;
}
void F_465 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_942 , 1 << 31 ) ;
F_23 ( V_943 , 0xffffffff ) ;
F_23 ( V_944 , 0 ) ;
F_466 ( & V_4 -> V_945 ) ;
V_4 -> V_946 = 0 ;
F_467 ( & V_4 -> V_945 ) ;
F_23 ( V_947 , F_3 ( V_947 ) ) ;
}
static unsigned long F_468 ( T_1 V_948 )
{
unsigned long V_949 ;
int div = ( V_948 & 0x3f0000 ) >> 16 ;
int V_950 = ( V_948 & 0x3000 ) >> 12 ;
int V_951 = ( V_948 & 0x7 ) ;
if ( ! V_951 )
return 0 ;
V_949 = ( ( div * 133333 ) / ( ( 1 << V_950 ) * V_951 ) ) ;
return V_949 ;
}
void F_469 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_952 ;
T_8 V_953 [ 16 ] ;
int V_104 ;
F_23 ( V_954 , 0 ) ;
F_72 ( V_954 ) ;
F_23 ( V_955 , 0x15040d00 ) ;
F_23 ( V_956 , 0x007f0000 ) ;
F_23 ( V_957 , 0x1e220004 ) ;
F_23 ( V_958 , 0x04000004 ) ;
for ( V_104 = 0 ; V_104 < 5 ; V_104 ++ )
F_23 ( V_959 + ( V_104 * 4 ) , 0 ) ;
for ( V_104 = 0 ; V_104 < 3 ; V_104 ++ )
F_23 ( V_960 + ( V_104 * 4 ) , 0 ) ;
for ( V_104 = 0 ; V_104 < 16 ; V_104 ++ ) {
T_1 V_961 = F_3 ( V_920 + ( V_104 * 4 ) ) ;
unsigned long V_949 = F_468 ( V_961 ) ;
unsigned long V_962 = ( V_961 & V_921 ) >>
V_922 ;
unsigned long V_79 ;
V_79 = V_962 * V_962 ;
V_79 *= ( V_949 / 1000 ) ;
V_79 *= 255 ;
V_79 /= ( 127 * 127 * 900 ) ;
if ( V_79 > 0xff )
F_83 ( L_191 , V_79 ) ;
V_953 [ V_104 ] = V_79 ;
}
V_953 [ 14 ] = 0 ;
V_953 [ 15 ] = 0 ;
for ( V_104 = 0 ; V_104 < 4 ; V_104 ++ ) {
T_1 V_79 = ( V_953 [ V_104 * 4 ] << 24 ) | ( V_953 [ ( V_104 * 4 ) + 1 ] << 16 ) |
( V_953 [ ( V_104 * 4 ) + 2 ] << 8 ) | ( V_953 [ ( V_104 * 4 ) + 3 ] ) ;
F_23 ( V_963 + ( V_104 * 4 ) , V_79 ) ;
}
F_23 ( V_964 , 0 ) ;
F_23 ( V_965 , 0 ) ;
F_23 ( V_966 , 0x00007f00 ) ;
F_23 ( V_967 , 0x0000000e ) ;
F_23 ( V_968 , 0x000e0000 ) ;
F_23 ( V_969 , 0x68000300 ) ;
F_23 ( V_970 , 0x42000000 ) ;
F_23 ( V_971 , 0x00140031 ) ;
F_23 ( V_972 , 0 ) ;
F_23 ( V_973 , 0 ) ;
for ( V_104 = 0 ; V_104 < 8 ; V_104 ++ )
F_23 ( V_974 + ( V_104 * 4 ) , 0 ) ;
F_23 ( V_954 , 0x80000019 ) ;
V_952 = F_3 ( V_975 ) ;
V_4 -> V_976 = ( V_952 & V_977 ) ;
}
static int F_470 ( struct V_1 * V_2 )
{
if ( V_978 >= 0 )
return V_978 ;
if ( F_27 ( V_2 ) -> V_70 == 5 )
return 0 ;
if ( F_27 ( V_2 ) -> V_70 == 6 ) {
F_316 ( L_192 ) ;
return V_979 ;
}
F_316 ( L_193 ) ;
return ( V_979 | V_980 ) ;
}
void F_471 ( struct V_3 * V_4 )
{
T_1 V_981 = F_3 ( V_982 ) ;
T_1 V_983 = F_3 ( V_984 ) ;
T_1 V_985 , V_986 = 0 ;
T_1 V_987 ;
int V_988 , V_989 , V_990 ;
int V_991 ;
int V_104 ;
F_23 ( V_992 , 0 ) ;
F_119 ( & V_4 -> V_2 -> V_222 ) ;
if ( ( V_987 = F_3 ( V_993 ) ) ) {
F_83 ( L_194 , V_987 ) ;
F_23 ( V_993 , V_987 ) ;
}
F_109 ( V_4 ) ;
F_23 ( V_994 , 0 ) ;
F_23 ( V_995 , 1000 << 16 ) ;
F_23 ( V_996 , 40 << 16 | 30 ) ;
F_23 ( V_997 , 30 ) ;
F_23 ( V_998 , 125000 ) ;
F_23 ( V_999 , 25 ) ;
for ( V_104 = 0 ; V_104 < V_1000 ; V_104 ++ )
F_23 ( F_472 ( V_4 -> V_331 [ V_104 ] . V_1001 ) , 10 ) ;
F_23 ( V_1002 , 0 ) ;
F_23 ( V_1003 , 1000 ) ;
F_23 ( V_1004 , 50000 ) ;
F_23 ( V_1005 , 100000 ) ;
F_23 ( V_1006 , 64000 ) ;
V_991 = F_470 ( V_4 -> V_2 ) ;
if ( V_991 & V_979 )
V_986 |= V_1007 ;
if ( V_991 & V_980 )
V_986 |= V_1008 ;
if ( V_991 & V_1009 )
V_986 |= V_1010 ;
F_286 ( L_195 ,
( V_991 & V_979 ) ? L_12 : L_13 ,
( V_991 & V_980 ) ? L_12 : L_13 ,
( V_991 & V_1009 ) ? L_12 : L_13 ) ;
F_23 ( V_994 ,
V_986 |
F_473 ( 1 ) |
V_1011 ) ;
F_23 ( V_942 ,
F_474 ( 10 ) |
F_475 ( 0 ) |
V_1012 ) ;
F_23 ( V_1013 ,
F_474 ( 12 ) ) ;
F_23 ( V_1014 , 1000000 ) ;
F_23 ( V_1015 ,
18 << 24 |
6 << 16 ) ;
F_23 ( V_1016 , 10000 ) ;
F_23 ( V_1017 , 1000000 ) ;
F_23 ( V_1018 , 100000 ) ;
F_23 ( V_1019 , 5000000 ) ;
F_23 ( V_1020 , 10 ) ;
F_23 ( V_1021 ,
V_1022 |
V_1023 |
V_1024 |
V_1025 |
V_1026 |
V_1027 ) ;
if ( F_24 ( ( F_3 ( V_1028 ) & V_1029 ) == 0 ,
500 ) )
F_83 ( L_196 ) ;
F_23 ( V_1030 , 0 ) ;
F_23 ( V_1028 ,
V_1029 |
V_1031 ) ;
if ( F_24 ( ( F_3 ( V_1028 ) & V_1029 ) == 0 ,
500 ) )
F_83 ( L_197 ) ;
V_989 = ( V_981 & 0xff0000 ) >> 16 ;
V_990 = V_981 & 0xff ;
V_988 = ( V_983 & 0xff00 ) >> 8 ;
if ( F_24 ( ( F_3 ( V_1028 ) & V_1029 ) == 0 ,
500 ) )
F_83 ( L_196 ) ;
F_23 ( V_1028 , V_1032 ) ;
V_985 = F_3 ( V_1030 ) ;
if ( F_24 ( ( F_3 ( V_1028 ) & V_1029 ) == 0 ,
500 ) )
F_83 ( L_197 ) ;
if ( V_985 & ( 1 << 31 ) ) {
V_990 = V_985 & 0xff ;
F_316 ( L_198 , V_985 * 50 ) ;
}
V_4 -> V_923 = V_990 ;
V_4 -> V_924 = V_989 ;
V_4 -> V_925 = V_988 ;
F_23 ( V_944 ,
V_1033 |
V_1034 |
V_1035 |
V_1036 |
V_1037 |
V_1038 |
V_1039 ) ;
F_466 ( & V_4 -> V_945 ) ;
F_451 ( V_4 -> V_946 != 0 ) ;
F_23 ( V_1040 , 0 ) ;
F_467 ( & V_4 -> V_945 ) ;
F_23 ( V_943 , 0 ) ;
F_110 ( V_4 ) ;
F_120 ( & V_4 -> V_2 -> V_222 ) ;
}
void F_476 ( struct V_3 * V_4 )
{
int V_989 = 15 ;
int V_1041 , V_1042 , V_1043 ;
int V_1044 = 180 ;
V_1043 = F_477 ( 0 ) ;
if ( ! V_1043 )
V_1043 = V_1045 ;
V_1043 /= 1000 ;
F_119 ( & V_4 -> V_2 -> V_222 ) ;
for ( V_1041 = V_4 -> V_923 ; V_1041 >= V_4 -> V_924 ;
V_1041 -- ) {
int V_1046 = V_4 -> V_923 - V_1041 ;
if ( V_1041 < V_989 )
V_1042 = 800 ;
else
V_1042 = V_1043 - ( ( V_1046 * V_1044 ) / 2 ) ;
V_1042 = F_478 ( V_1042 , 100 ) ;
F_23 ( V_1030 ,
( V_1042 << V_1047 ) |
V_1041 ) ;
F_23 ( V_1028 , V_1029 |
V_1031 ) ;
if ( F_24 ( ( F_3 ( V_1028 ) &
V_1029 ) == 0 , 10 ) ) {
F_83 ( L_199 ) ;
continue;
}
}
F_120 ( & V_4 -> V_2 -> V_222 ) ;
}
static void F_479 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_1048 = V_1049 ;
V_1048 |= V_1050 |
V_1051 |
V_1052 ;
V_1048 |= V_1053 ;
F_23 ( V_1054 ,
V_1055 |
V_1056 ) ;
F_23 ( V_1057 ,
V_1058 ) ;
F_23 ( V_1059 , V_1048 ) ;
F_23 ( V_1060 ,
( F_3 ( V_1060 ) |
V_1061 | V_1062 ) ) ;
F_23 ( V_1063 ,
( F_3 ( V_1063 ) |
V_1064 ) ) ;
F_23 ( V_506 ,
( F_3 ( V_506 ) |
V_507 ) ) ;
F_23 ( V_517 , 0 ) ;
F_23 ( V_518 , 0 ) ;
F_23 ( V_519 , 0 ) ;
if ( F_480 ( V_2 ) ) {
F_23 ( V_1065 ,
F_3 ( V_1065 ) |
V_1066 ) ;
F_23 ( V_1060 ,
F_3 ( V_1060 ) |
V_1061 ) ;
F_23 ( V_1063 ,
F_3 ( V_1063 ) |
V_1067 |
V_1068 |
V_1069 ) ;
}
F_23 ( V_1060 ,
F_3 ( V_1060 ) |
V_1070 ) ;
F_23 ( V_1071 ,
V_1072 << 16 |
V_1072 ) ;
}
static void F_481 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_67 ;
T_5 V_1048 = V_1049 ;
F_23 ( V_1059 , V_1048 ) ;
F_23 ( V_1060 ,
F_3 ( V_1060 ) |
V_1070 ) ;
F_23 ( V_517 , 0 ) ;
F_23 ( V_518 , 0 ) ;
F_23 ( V_519 , 0 ) ;
F_23 ( V_1073 ,
F_3 ( V_1073 ) |
V_1074 ) ;
F_23 ( V_1075 ,
V_1076 |
V_1077 ) ;
F_23 ( V_1065 ,
F_3 ( V_1065 ) |
V_1066 | V_1078 ) ;
F_23 ( V_1060 ,
F_3 ( V_1060 ) |
V_1061 | V_1062 ) ;
F_23 ( V_1063 ,
F_3 ( V_1063 ) |
V_1064 |
V_1079 ) ;
F_418 (pipe) {
F_23 ( F_50 ( V_67 ) ,
F_3 ( F_50 ( V_67 ) ) |
V_278 ) ;
F_90 ( V_4 , V_67 ) ;
}
}
static void F_482 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_67 ;
T_5 V_1048 = V_1049 ;
F_23 ( V_1059 , V_1048 ) ;
F_23 ( V_517 , 0 ) ;
F_23 ( V_518 , 0 ) ;
F_23 ( V_519 , 0 ) ;
F_23 ( V_1075 , V_1080 ) ;
F_23 ( V_1063 , V_1081 ) ;
F_23 ( V_1082 ,
V_1083 |
V_1084 ) ;
F_23 ( V_1085 ,
V_1086 ) ;
F_23 ( V_1087 ,
V_1088 ) ;
F_23 ( V_1089 ,
V_1090 ) ;
F_23 ( V_1091 ,
F_3 ( V_1091 ) |
V_1092 ) ;
F_418 (pipe) {
F_23 ( F_50 ( V_67 ) ,
F_3 ( F_50 ( V_67 ) ) |
V_278 ) ;
F_90 ( V_4 , V_67 ) ;
}
}
static void F_483 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_1048 ;
F_23 ( V_1093 , 0 ) ;
F_23 ( V_1094 , V_1095 |
V_1096 |
V_1097 ) ;
F_23 ( V_1098 , 0 ) ;
V_1048 = V_1049 |
V_1099 |
V_1100 ;
if ( F_484 ( V_2 ) )
V_1048 |= V_1101 ;
F_23 ( V_1102 , V_1048 ) ;
}
static void F_485 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_1093 , V_1103 ) ;
F_23 ( V_1094 , 0 ) ;
F_23 ( V_1102 , 0 ) ;
F_23 ( V_1098 , 0 ) ;
F_457 ( V_1104 , 0 ) ;
}
static void F_486 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_1093 , V_1105 |
V_1103 |
V_1106 |
V_1107 |
V_1108 ) ;
F_23 ( V_1094 , 0 ) ;
}
static void F_487 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_1109 = F_3 ( V_1110 ) ;
V_1109 |= V_1111 | V_1112 |
V_1113 ;
F_23 ( V_1110 , V_1109 ) ;
}
static void F_488 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_1093 , V_1114 ) ;
}
static void F_489 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_1102 , V_1099 ) ;
}
static void F_490 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_1115 , V_1116 ) ;
}
static void F_491 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_67 ;
F_23 ( V_1115 , V_1116 ) ;
F_23 ( V_1117 , F_3 ( V_1117 ) |
V_1118 ) ;
F_418 (pipe)
F_23 ( F_196 ( V_67 ) , V_354 ) ;
}
static void F_492 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_1119 ) {
F_140 ( V_4 -> V_1119 ) ;
F_343 ( & V_4 -> V_1119 -> V_52 ) ;
V_4 -> V_1119 = NULL ;
}
if ( V_4 -> V_1120 ) {
F_140 ( V_4 -> V_1120 ) ;
F_343 ( & V_4 -> V_1120 -> V_52 ) ;
V_4 -> V_1120 = NULL ;
}
}
static void F_493 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_3 ( V_1121 ) ) {
F_23 ( V_1122 , F_3 ( V_1122 ) | V_1123 ) ;
F_24 ( ( ( F_3 ( V_1122 ) & V_1124 ) == V_1125 ) ,
50 ) ;
F_23 ( V_1121 , 0 ) ;
F_72 ( V_1121 ) ;
F_23 ( V_1122 , F_3 ( V_1122 ) & ~ V_1123 ) ;
F_72 ( V_1122 ) ;
}
F_492 ( V_2 ) ;
}
static int F_494 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_1119 == NULL )
V_4 -> V_1119 = F_450 ( V_2 ) ;
if ( ! V_4 -> V_1119 )
return - V_737 ;
if ( V_4 -> V_1120 == NULL )
V_4 -> V_1120 = F_450 ( V_2 ) ;
if ( ! V_4 -> V_1120 ) {
F_492 ( V_2 ) ;
return - V_737 ;
}
return 0 ;
}
void F_495 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_257 ;
if ( ! F_470 ( V_2 ) )
return;
F_119 ( & V_2 -> V_222 ) ;
V_257 = F_494 ( V_2 ) ;
if ( V_257 ) {
F_120 ( & V_2 -> V_222 ) ;
return;
}
V_257 = F_398 ( 6 ) ;
if ( V_257 ) {
F_492 ( V_2 ) ;
F_120 ( & V_2 -> V_222 ) ;
return;
}
F_399 ( V_1126 | V_1127 ) ;
F_399 ( V_1128 ) ;
F_399 ( V_4 -> V_1119 -> V_211 |
V_1129 |
V_1130 |
V_1131 |
V_1132 ) ;
F_399 ( V_1126 ) ;
F_399 ( V_833 ) ;
F_399 ( V_1133 ) ;
F_401 () ;
V_257 = F_496 ( F_173 ( V_4 ) ) ;
if ( V_257 ) {
F_83 ( L_200 ) ;
F_492 ( V_2 ) ;
F_120 ( & V_2 -> V_222 ) ;
return;
}
F_23 ( V_1121 , V_4 -> V_1120 -> V_211 | V_1134 ) ;
F_23 ( V_1122 , F_3 ( V_1122 ) & ~ V_1123 ) ;
F_120 ( & V_2 -> V_222 ) ;
}
void F_497 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_216 . V_1135 ( V_2 ) ;
if ( V_4 -> V_216 . V_1136 )
V_4 -> V_216 . V_1136 ( V_2 ) ;
}
static void F_498 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_8 ( V_2 ) ) {
V_4 -> V_216 . V_370 = F_206 ;
V_4 -> V_216 . V_668 = F_296 ;
V_4 -> V_216 . V_280 = F_146 ;
} else {
V_4 -> V_216 . V_370 = F_211 ;
V_4 -> V_216 . V_668 = F_282 ;
V_4 -> V_216 . V_280 = F_143 ;
}
if ( F_130 ( V_2 ) ) {
if ( F_8 ( V_2 ) ) {
V_4 -> V_216 . V_217 = F_114 ;
V_4 -> V_216 . V_224 = F_111 ;
V_4 -> V_216 . V_230 = F_113 ;
} else if ( F_484 ( V_2 ) ) {
V_4 -> V_216 . V_217 = F_107 ;
V_4 -> V_216 . V_224 = F_105 ;
V_4 -> V_216 . V_230 = F_106 ;
} else if ( F_135 ( V_2 ) ) {
V_4 -> V_216 . V_217 = F_104 ;
V_4 -> V_216 . V_224 = F_100 ;
V_4 -> V_216 . V_230 = F_99 ;
}
}
if ( F_257 ( V_2 ) || ( F_284 ( V_2 ) && ! F_499 ( V_2 ) ) )
V_4 -> V_216 . V_606 =
F_226 ;
else if ( F_500 ( V_2 ) )
V_4 -> V_216 . V_606 =
F_227 ;
else if ( F_103 ( V_2 ) || F_334 ( V_2 ) || F_499 ( V_2 ) )
V_4 -> V_216 . V_606 =
F_228 ;
else if ( F_131 ( V_2 ) )
V_4 -> V_216 . V_606 =
F_229 ;
else if ( F_335 ( V_2 ) )
V_4 -> V_216 . V_606 =
F_231 ;
else if ( F_501 ( V_2 ) )
V_4 -> V_216 . V_606 =
F_232 ;
else
V_4 -> V_216 . V_606 =
F_233 ;
if ( F_8 ( V_2 ) ) {
V_4 -> V_216 . V_1137 = V_1138 ;
V_4 -> V_216 . V_1139 = V_1140 ;
if ( F_154 ( V_2 ) ) {
T_1 V_1141 ;
F_119 ( & V_2 -> V_222 ) ;
F_502 ( V_4 ) ;
V_1141 = F_503 ( V_1142 ) ;
F_504 ( V_4 ) ;
F_120 ( & V_2 -> V_222 ) ;
if ( V_1141 & V_1143 ) {
F_25 ( L_201 ) ;
V_4 -> V_216 . V_1137 =
F_502 ;
V_4 -> V_216 . V_1139 =
F_504 ;
}
}
if ( F_82 ( V_2 ) )
V_4 -> V_216 . V_1136 = F_490 ;
else if ( F_38 ( V_2 ) )
V_4 -> V_216 . V_1136 = F_491 ;
if ( F_2 ( V_2 ) ) {
if ( F_3 ( V_1144 ) & V_1145 )
V_4 -> V_216 . V_543 = F_262 ;
else {
F_25 ( L_202
L_203 ) ;
V_4 -> V_216 . V_543 = NULL ;
}
V_4 -> V_216 . V_336 = F_160 ;
V_4 -> V_216 . V_1135 = F_479 ;
V_4 -> V_216 . V_700 = F_317 ;
} else if ( F_112 ( V_2 ) ) {
if ( F_266 () ) {
V_4 -> V_216 . V_543 = F_265 ;
V_4 -> V_216 . V_544 = F_272 ;
} else {
F_25 ( L_204
L_203 ) ;
V_4 -> V_216 . V_543 = NULL ;
}
V_4 -> V_216 . V_336 = F_165 ;
V_4 -> V_216 . V_1135 = F_481 ;
V_4 -> V_216 . V_700 = F_317 ;
} else if ( F_154 ( V_2 ) ) {
V_4 -> V_216 . V_336 = F_166 ;
if ( F_266 () ) {
V_4 -> V_216 . V_543 = F_265 ;
V_4 -> V_216 . V_544 = F_272 ;
} else {
F_25 ( L_204
L_203 ) ;
V_4 -> V_216 . V_543 = NULL ;
}
V_4 -> V_216 . V_1135 = F_482 ;
V_4 -> V_216 . V_700 = F_317 ;
} else
V_4 -> V_216 . V_543 = NULL ;
} else if ( F_10 ( V_2 ) ) {
if ( ! F_238 ( F_247 ( V_2 ) ,
V_4 -> V_425 ,
V_4 -> V_430 ,
V_4 -> V_431 ) ) {
F_286 ( L_205
L_206
L_207 ,
( V_4 -> V_425 == 1 ) ? L_208 : L_209 ,
V_4 -> V_430 , V_4 -> V_431 ) ;
F_240 ( V_2 ) ;
V_4 -> V_216 . V_543 = NULL ;
} else
V_4 -> V_216 . V_543 = F_246 ;
V_4 -> V_216 . V_1135 = F_487 ;
} else if ( F_9 ( V_2 ) ) {
V_4 -> V_216 . V_700 = F_314 ;
V_4 -> V_216 . V_543 = F_252 ;
V_4 -> V_216 . V_1135 = F_483 ;
} else if ( F_505 ( V_2 ) ) {
V_4 -> V_216 . V_543 = F_255 ;
if ( F_135 ( V_2 ) )
V_4 -> V_216 . V_1135 = F_485 ;
else if ( F_134 ( V_2 ) )
V_4 -> V_216 . V_1135 = F_486 ;
} else if ( F_290 ( V_2 ) ) {
V_4 -> V_216 . V_543 = F_256 ;
V_4 -> V_216 . V_495 = F_241 ;
V_4 -> V_216 . V_1135 = F_487 ;
} else if ( F_335 ( V_2 ) ) {
V_4 -> V_216 . V_543 = F_259 ;
V_4 -> V_216 . V_1135 = F_488 ;
V_4 -> V_216 . V_495 = F_244 ;
} else if ( F_501 ( V_2 ) ) {
V_4 -> V_216 . V_543 = F_256 ;
V_4 -> V_216 . V_495 = F_242 ;
V_4 -> V_216 . V_1135 = F_488 ;
} else {
V_4 -> V_216 . V_543 = F_259 ;
V_4 -> V_216 . V_1135 = F_489 ;
if ( F_334 ( V_2 ) )
V_4 -> V_216 . V_495 = F_243 ;
else
V_4 -> V_216 . V_495 = F_244 ;
}
V_4 -> V_216 . V_843 = F_409 ;
switch ( F_27 ( V_2 ) -> V_70 ) {
case 2 :
V_4 -> V_216 . V_843 = F_397 ;
break;
case 3 :
V_4 -> V_216 . V_843 = F_402 ;
break;
case 4 :
case 5 :
V_4 -> V_216 . V_843 = F_403 ;
break;
case 6 :
V_4 -> V_216 . V_843 = F_404 ;
break;
case 7 :
V_4 -> V_216 . V_843 = F_405 ;
break;
}
}
static void F_506 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_99 |= V_100 ;
F_316 ( L_210 ) ;
}
static void F_507 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_99 |= V_547 ;
}
static void F_508 ( struct V_1 * V_2 )
{
struct V_1146 * V_1147 = V_2 -> V_387 ;
int V_104 ;
for ( V_104 = 0 ; V_104 < F_239 ( V_1148 ) ; V_104 ++ ) {
struct V_1149 * V_1150 = & V_1148 [ V_104 ] ;
if ( V_1147 -> V_1151 == V_1150 -> V_1151 &&
( V_1147 -> V_1152 == V_1150 -> V_1152 ||
V_1150 -> V_1152 == V_1153 ) &&
( V_1147 -> V_1154 == V_1150 -> V_1154 ||
V_1150 -> V_1154 == V_1153 ) )
V_1150 -> V_1155 ( V_2 ) ;
}
}
static void F_509 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_8 V_1156 ;
T_1 V_1157 ;
if ( F_8 ( V_2 ) )
V_1157 = V_1158 ;
else
V_1157 = V_1159 ;
F_510 ( V_2 -> V_387 , V_1160 ) ;
F_511 ( 1 , V_1161 ) ;
V_1156 = F_512 ( V_1162 ) ;
F_511 ( V_1156 | 1 << 5 , V_1162 ) ;
F_513 ( V_2 -> V_387 , V_1160 ) ;
F_73 ( 300 ) ;
F_23 ( V_1157 , V_1163 ) ;
F_72 ( V_1157 ) ;
}
void F_514 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_104 , V_257 ;
F_515 ( V_2 ) ;
V_2 -> V_49 . V_1164 = 0 ;
V_2 -> V_49 . V_1165 = 0 ;
V_2 -> V_49 . V_1166 = 24 ;
V_2 -> V_49 . V_1167 = 1 ;
V_2 -> V_49 . V_769 = ( void * ) & V_1168 ;
F_508 ( V_2 ) ;
F_498 ( V_2 ) ;
if ( F_11 ( V_2 ) ) {
V_2 -> V_49 . V_1169 = 2048 ;
V_2 -> V_49 . V_1170 = 2048 ;
} else if ( F_290 ( V_2 ) ) {
V_2 -> V_49 . V_1169 = 4096 ;
V_2 -> V_49 . V_1170 = 4096 ;
} else {
V_2 -> V_49 . V_1169 = 8192 ;
V_2 -> V_49 . V_1170 = 8192 ;
}
V_2 -> V_49 . V_1171 = V_2 -> V_1172 -> V_52 ;
F_25 ( L_211 ,
V_4 -> V_1173 , V_4 -> V_1173 > 1 ? L_212 : L_213 ) ;
for ( V_104 = 0 ; V_104 < V_4 -> V_1173 ; V_104 ++ ) {
F_420 ( V_2 , V_104 ) ;
V_257 = F_516 ( V_2 , V_104 ) ;
if ( V_257 )
F_25 ( L_214 , V_104 , V_257 ) ;
}
F_509 ( V_2 ) ;
F_430 ( V_2 ) ;
F_497 ( V_2 ) ;
if ( F_480 ( V_2 ) ) {
F_459 ( V_2 ) ;
F_469 ( V_2 ) ;
}
if ( F_112 ( V_2 ) || F_517 ( V_2 ) ) {
F_471 ( V_4 ) ;
F_476 ( V_4 ) ;
}
F_411 ( & V_4 -> V_801 , F_373 ) ;
F_424 ( & V_4 -> V_797 , F_367 ,
( unsigned long ) V_2 ) ;
}
void F_518 ( struct V_1 * V_2 )
{
if ( F_480 ( V_2 ) )
F_495 ( V_2 ) ;
F_519 ( V_2 ) ;
}
void F_520 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
struct V_164 * V_164 ;
F_521 ( V_2 ) ;
F_119 ( & V_2 -> V_222 ) ;
F_522 () ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_9 -> V_159 )
continue;
V_164 = F_102 ( V_9 ) ;
F_148 ( V_9 ) ;
}
F_128 ( V_2 ) ;
if ( F_480 ( V_2 ) )
F_463 ( V_2 ) ;
if ( F_112 ( V_2 ) || F_517 ( V_2 ) )
F_465 ( V_2 ) ;
if ( F_480 ( V_2 ) )
F_493 ( V_2 ) ;
F_120 ( & V_2 -> V_222 ) ;
F_523 ( V_2 ) ;
F_379 ( & V_4 -> V_1174 ) ;
F_379 ( & V_4 -> V_1175 ) ;
F_524 () ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
V_164 = F_102 ( V_9 ) ;
F_525 ( & V_164 -> V_797 ) ;
}
F_525 ( & V_4 -> V_797 ) ;
F_379 ( & V_4 -> V_801 ) ;
F_526 ( V_2 ) ;
}
struct V_378 * F_527 ( struct V_549 * V_550 )
{
return & F_528 ( V_550 ) -> V_52 ;
}
void F_529 ( struct V_1176 * V_550 ,
struct V_50 * V_51 )
{
V_550 -> V_51 = V_51 ;
F_530 ( & V_550 -> V_52 ,
& V_51 -> V_52 ) ;
}
int F_531 ( struct V_1 * V_2 , bool V_78 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_1177 ;
F_230 ( V_4 -> V_1178 , V_1179 , & V_1177 ) ;
if ( V_78 )
V_1177 &= ~ V_1180 ;
else
V_1177 |= V_1180 ;
F_532 ( V_4 -> V_1178 , V_1179 , V_1177 ) ;
return 0 ;
}
struct V_1181 *
F_533 ( struct V_1 * V_2 )
{
T_7 * V_4 = V_2 -> V_5 ;
struct V_1181 * error ;
int V_104 ;
error = F_534 ( sizeof( * error ) , V_1182 ) ;
if ( error == NULL )
return NULL ;
for ( V_104 = 0 ; V_104 < 2 ; V_104 ++ ) {
error -> V_455 [ V_104 ] . V_1183 = F_3 ( F_327 ( V_104 ) ) ;
error -> V_455 [ V_104 ] . V_1184 = F_3 ( F_333 ( V_104 ) ) ;
error -> V_455 [ V_104 ] . V_52 = F_3 ( F_328 ( V_104 ) ) ;
error -> V_102 [ V_104 ] . V_1183 = F_3 ( F_50 ( V_104 ) ) ;
error -> V_102 [ V_104 ] . V_1185 = F_3 ( F_144 ( V_104 ) ) ;
error -> V_102 [ V_104 ] . V_239 = F_3 ( F_291 ( V_104 ) ) ;
error -> V_102 [ V_104 ] . V_722 = F_3 ( F_292 ( V_104 ) ) ;
error -> V_102 [ V_104 ] . V_734 = F_3 ( F_91 ( V_104 ) ) ;
if ( F_27 ( V_2 ) -> V_70 >= 4 ) {
error -> V_102 [ V_104 ] . V_1186 = F_3 ( F_92 ( V_104 ) ) ;
error -> V_102 [ V_104 ] . V_1187 = F_3 ( F_145 ( V_104 ) ) ;
}
error -> V_67 [ V_104 ] . V_1188 = F_3 ( F_28 ( V_104 ) ) ;
error -> V_67 [ V_104 ] . V_1189 = F_3 ( F_293 ( V_104 ) ) ;
error -> V_67 [ V_104 ] . V_459 = F_3 ( F_181 ( V_104 ) ) ;
error -> V_67 [ V_104 ] . V_1190 = F_3 ( F_183 ( V_104 ) ) ;
error -> V_67 [ V_104 ] . V_787 = F_3 ( F_185 ( V_104 ) ) ;
error -> V_67 [ V_104 ] . V_792 = F_3 ( F_187 ( V_104 ) ) ;
error -> V_67 [ V_104 ] . V_1191 = F_3 ( F_189 ( V_104 ) ) ;
error -> V_67 [ V_104 ] . V_789 = F_3 ( F_191 ( V_104 ) ) ;
}
return error ;
}
void
F_535 ( struct V_1192 * V_39 ,
struct V_1 * V_2 ,
struct V_1181 * error )
{
int V_104 ;
for ( V_104 = 0 ; V_104 < 2 ; V_104 ++ ) {
F_536 ( V_39 , L_215 , V_104 ) ;
F_536 ( V_39 , L_216 , error -> V_67 [ V_104 ] . V_1188 ) ;
F_536 ( V_39 , L_217 , error -> V_67 [ V_104 ] . V_1189 ) ;
F_536 ( V_39 , L_218 , error -> V_67 [ V_104 ] . V_459 ) ;
F_536 ( V_39 , L_219 , error -> V_67 [ V_104 ] . V_1190 ) ;
F_536 ( V_39 , L_220 , error -> V_67 [ V_104 ] . V_787 ) ;
F_536 ( V_39 , L_221 , error -> V_67 [ V_104 ] . V_792 ) ;
F_536 ( V_39 , L_222 , error -> V_67 [ V_104 ] . V_1191 ) ;
F_536 ( V_39 , L_223 , error -> V_67 [ V_104 ] . V_789 ) ;
F_536 ( V_39 , L_224 , V_104 ) ;
F_536 ( V_39 , L_225 , error -> V_102 [ V_104 ] . V_1183 ) ;
F_536 ( V_39 , L_226 , error -> V_102 [ V_104 ] . V_1185 ) ;
F_536 ( V_39 , L_227 , error -> V_102 [ V_104 ] . V_239 ) ;
F_536 ( V_39 , L_228 , error -> V_102 [ V_104 ] . V_722 ) ;
F_536 ( V_39 , L_229 , error -> V_102 [ V_104 ] . V_734 ) ;
if ( F_27 ( V_2 ) -> V_70 >= 4 ) {
F_536 ( V_39 , L_230 , error -> V_102 [ V_104 ] . V_1186 ) ;
F_536 ( V_39 , L_231 , error -> V_102 [ V_104 ] . V_1187 ) ;
}
F_536 ( V_39 , L_232 , V_104 ) ;
F_536 ( V_39 , L_225 , error -> V_455 [ V_104 ] . V_1183 ) ;
F_536 ( V_39 , L_228 , error -> V_455 [ V_104 ] . V_1184 ) ;
F_536 ( V_39 , L_233 , error -> V_455 [ V_104 ] . V_52 ) ;
}
}
