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
bool V_89 = V_89 ;
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
static void F_55 ( struct V_3 * V_4 ,
enum V_66 V_66 , int V_70 )
{
T_1 V_78 = F_3 ( V_70 ) ;
F_36 ( F_56 ( V_78 , V_66 ) ,
L_26 ,
V_70 , F_46 ( V_66 ) ) ;
}
static void F_57 ( struct V_3 * V_4 ,
enum V_66 V_66 , int V_70 )
{
T_1 V_78 = F_3 ( V_70 ) ;
F_36 ( F_58 ( V_78 , V_66 ) ,
L_26 ,
V_70 , F_46 ( V_66 ) ) ;
}
static void F_59 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_55 ( V_4 , V_66 , V_108 ) ;
F_55 ( V_4 , V_66 , V_109 ) ;
F_55 ( V_4 , V_66 , V_110 ) ;
V_70 = V_111 ;
V_78 = F_3 ( V_70 ) ;
F_36 ( F_60 ( V_78 , V_66 ) ,
L_27 ,
F_46 ( V_66 ) ) ;
V_70 = V_13 ;
V_78 = F_3 ( V_70 ) ;
F_36 ( F_61 ( V_78 , V_66 ) ,
L_28 ,
F_46 ( V_66 ) ) ;
F_57 ( V_4 , V_66 , V_112 ) ;
F_57 ( V_4 , V_66 , V_113 ) ;
F_57 ( V_4 , V_66 , V_114 ) ;
}
static void F_62 ( struct V_3 * V_4 , enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_63 ( V_4 -> V_83 -> V_69 >= 5 ) ;
if ( F_64 ( V_4 -> V_2 ) && ! F_65 ( V_4 -> V_2 ) )
F_45 ( V_4 , V_66 ) ;
V_70 = F_35 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_78 |= V_80 ;
F_23 ( V_70 , V_78 ) ;
F_66 ( V_70 ) ;
F_67 ( 150 ) ;
F_23 ( V_70 , V_78 ) ;
F_66 ( V_70 ) ;
F_67 ( 150 ) ;
F_23 ( V_70 , V_78 ) ;
F_66 ( V_70 ) ;
F_67 ( 150 ) ;
}
static void F_68 ( struct V_3 * V_4 , enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
if ( V_66 == V_88 && ( V_4 -> V_115 & V_116 ) )
return;
F_69 ( V_4 , V_66 ) ;
V_70 = F_35 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_78 &= ~ V_80 ;
F_23 ( V_70 , V_78 ) ;
F_66 ( V_70 ) ;
}
static void F_70 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_63 ( V_4 -> V_83 -> V_69 < 5 ) ;
F_52 ( V_4 ) ;
V_70 = F_38 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_78 |= V_80 ;
F_23 ( V_70 , V_78 ) ;
F_66 ( V_70 ) ;
F_67 ( 200 ) ;
}
static void F_71 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_63 ( V_4 -> V_83 -> V_69 < 5 ) ;
F_53 ( V_4 , V_66 ) ;
V_70 = F_38 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_78 &= ~ V_80 ;
F_23 ( V_70 , V_78 ) ;
F_66 ( V_70 ) ;
F_67 ( 200 ) ;
}
static void F_72 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_63 ( V_4 -> V_83 -> V_69 < 5 ) ;
F_73 ( V_4 , V_66 ) ;
F_74 ( V_4 , V_66 ) ;
F_75 ( V_4 , V_66 ) ;
V_70 = F_54 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_78 &= ~ V_117 ;
V_78 |= F_3 ( F_28 ( V_66 ) ) & V_117 ;
F_23 ( V_70 , V_78 | V_107 ) ;
if ( F_24 ( F_3 ( V_70 ) & V_118 , 100 ) )
F_76 ( L_29 , V_66 ) ;
}
static void F_77 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_78 ( V_4 , V_66 ) ;
F_79 ( V_4 , V_66 ) ;
F_59 ( V_4 , V_66 ) ;
V_70 = F_54 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
V_78 &= ~ V_107 ;
F_23 ( V_70 , V_78 ) ;
if ( F_24 ( ( F_3 ( V_70 ) & V_118 ) == 0 , 50 ) )
F_76 ( L_30 ) ;
}
static void F_80 ( struct V_3 * V_4 , enum V_66 V_66 ,
bool V_119 )
{
int V_70 ;
T_1 V_78 ;
if ( ! F_8 ( V_4 -> V_2 ) )
F_81 ( V_4 , V_66 ) ;
else {
if ( V_119 ) {
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
static void F_82 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_51 ( V_4 , V_66 ) ;
if ( V_66 == V_88 && ( V_4 -> V_115 & V_116 ) )
return;
V_70 = F_28 ( V_66 ) ;
V_78 = F_3 ( V_70 ) ;
if ( ( V_78 & V_96 ) == 0 )
return;
F_23 ( V_70 , V_78 & ~ V_96 ) ;
F_26 ( V_4 -> V_2 , V_66 ) ;
}
static void F_83 ( struct V_3 * V_4 ,
enum V_97 V_97 , enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
F_84 ( V_4 , V_66 ) ;
V_70 = F_49 ( V_97 ) ;
V_78 = F_3 ( V_70 ) ;
if ( V_78 & V_98 )
return;
F_23 ( V_70 , V_78 | V_98 ) ;
F_21 ( V_4 -> V_2 , V_66 ) ;
}
static void F_85 ( struct V_3 * V_4 ,
enum V_97 V_97 )
{
T_1 V_70 = F_86 ( V_97 ) ;
F_23 ( V_70 , F_3 ( V_70 ) ) ;
}
static void F_87 ( struct V_3 * V_4 ,
enum V_97 V_97 , enum V_66 V_66 )
{
int V_70 ;
T_1 V_78 ;
V_70 = F_49 ( V_97 ) ;
V_78 = F_3 ( V_70 ) ;
if ( ( V_78 & V_98 ) == 0 )
return;
F_23 ( V_70 , V_78 & ~ V_98 ) ;
F_85 ( V_4 , V_97 ) ;
F_21 ( V_4 -> V_2 , V_66 ) ;
}
static void F_88 ( struct V_3 * V_4 ,
enum V_66 V_66 , int V_70 )
{
T_1 V_78 = F_3 ( V_70 ) ;
if ( F_56 ( V_78 , V_66 ) )
F_23 ( V_70 , V_78 & ~ V_120 ) ;
}
static void F_89 ( struct V_3 * V_4 ,
enum V_66 V_66 , int V_70 )
{
T_1 V_78 = F_3 ( V_70 ) ;
if ( F_58 ( V_78 , V_66 ) )
F_23 ( V_70 , V_78 & ~ V_121 ) ;
}
static void F_90 ( struct V_3 * V_4 ,
enum V_66 V_66 )
{
T_1 V_70 , V_78 ;
V_78 = F_3 ( V_90 ) ;
F_23 ( V_90 , V_78 | V_93 ) ;
F_88 ( V_4 , V_66 , V_108 ) ;
F_88 ( V_4 , V_66 , V_109 ) ;
F_88 ( V_4 , V_66 , V_110 ) ;
V_70 = V_111 ;
V_78 = F_3 ( V_70 ) ;
if ( F_60 ( V_78 , V_66 ) )
F_23 ( V_70 , V_78 & ~ V_122 ) ;
V_70 = V_13 ;
V_78 = F_3 ( V_70 ) ;
if ( F_61 ( V_78 , V_66 ) ) {
F_23 ( V_70 , V_78 & ~ V_123 ) ;
F_66 ( V_70 ) ;
F_67 ( 100 ) ;
}
F_89 ( V_4 , V_66 , V_112 ) ;
F_89 ( V_4 , V_66 , V_113 ) ;
F_89 ( V_4 , V_66 , V_114 ) ;
}
static void F_91 ( struct V_8 * V_9 , unsigned long V_124 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_125 * V_126 = V_9 -> V_126 ;
struct V_127 * V_128 = F_92 ( V_126 ) ;
struct V_129 * V_130 = V_128 -> V_130 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_97 , V_99 ;
T_1 V_132 , V_133 ;
if ( V_126 -> V_134 == V_4 -> V_135 &&
V_130 -> V_136 == V_4 -> V_137 &&
V_131 -> V_97 == V_4 -> V_138 &&
F_3 ( V_139 ) & V_140 )
return;
F_94 ( V_2 ) ;
V_4 -> V_135 = V_4 -> V_141 / V_142 ;
if ( V_126 -> V_134 < V_4 -> V_135 )
V_4 -> V_135 = V_126 -> V_134 ;
V_4 -> V_135 = ( V_4 -> V_135 / 64 ) - 1 ;
V_4 -> V_137 = V_130 -> V_136 ;
V_4 -> V_138 = V_131 -> V_97 ;
V_97 = V_4 -> V_138 == 0 ? V_143 : V_144 ;
for ( V_99 = 0 ; V_99 < ( V_142 / 32 ) + 1 ; V_99 ++ )
F_23 ( V_145 + ( V_99 * 4 ) , 0 ) ;
V_133 = V_146 | V_147 | V_97 ;
if ( V_130 -> V_148 != V_149 )
V_133 |= V_150 ;
F_23 ( V_151 , V_133 ) ;
F_23 ( V_152 , V_9 -> V_153 ) ;
V_132 = V_140 | V_154 ;
if ( F_95 ( V_2 ) )
V_132 |= V_155 ;
V_132 |= ( V_4 -> V_135 & 0xff ) << V_156 ;
V_132 |= ( V_124 & 0x2fff ) << V_157 ;
if ( V_130 -> V_148 != V_149 )
V_132 |= V_4 -> V_137 ;
F_23 ( V_139 , V_132 ) ;
F_25 ( L_31 ,
V_4 -> V_135 , V_9 -> V_153 , V_4 -> V_138 ) ;
}
void F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_132 ;
V_132 = F_3 ( V_139 ) ;
if ( ( V_132 & V_140 ) == 0 )
return;
V_132 &= ~ V_140 ;
F_23 ( V_139 , V_132 ) ;
if ( F_24 ( ( F_3 ( V_158 ) & V_159 ) == 0 , 10 ) ) {
F_25 ( L_32 ) ;
return;
}
F_25 ( L_33 ) ;
}
static bool F_96 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_139 ) & V_140 ;
}
static void F_97 ( struct V_8 * V_9 , unsigned long V_124 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_125 * V_126 = V_9 -> V_126 ;
struct V_127 * V_128 = F_92 ( V_126 ) ;
struct V_129 * V_130 = V_128 -> V_130 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_97 = V_131 -> V_97 == 0 ? V_160 : V_161 ;
unsigned long V_162 = 200 ;
T_1 V_163 ;
V_163 = F_3 ( V_164 ) ;
if ( V_163 & V_165 ) {
if ( V_4 -> V_135 == V_4 -> V_135 / 64 - 1 &&
V_4 -> V_137 == V_130 -> V_136 &&
V_4 -> V_138 == V_131 -> V_97 &&
V_4 -> V_166 == V_9 -> V_153 )
return;
F_23 ( V_164 , V_163 & ~ V_165 ) ;
F_21 ( V_2 , V_131 -> V_66 ) ;
}
V_4 -> V_135 = ( V_4 -> V_135 / 64 ) - 1 ;
V_4 -> V_137 = V_130 -> V_136 ;
V_4 -> V_138 = V_131 -> V_97 ;
V_4 -> V_166 = V_9 -> V_153 ;
V_163 = V_97 | V_167 | V_168 ;
if ( V_130 -> V_148 != V_149 ) {
V_163 |= V_169 | V_4 -> V_137 ;
F_23 ( V_170 , V_171 ) ;
} else {
F_23 ( V_170 , ~ V_171 ) ;
}
F_23 ( V_172 , V_173 |
( V_162 << V_174 ) |
( V_124 << V_175 ) ) ;
F_23 ( V_176 , V_9 -> V_153 ) ;
F_23 ( V_164 , F_3 ( V_164 ) | V_165 ) ;
F_25 ( L_34 , V_131 -> V_97 ) ;
}
void F_98 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_163 ;
V_163 = F_3 ( V_164 ) ;
if ( V_163 & V_165 ) {
V_163 &= ~ V_165 ;
F_23 ( V_164 , V_163 ) ;
F_25 ( L_33 ) ;
}
}
static bool F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_164 ) & V_165 ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_177 ;
F_101 ( V_4 ) ;
V_177 = F_3 ( V_178 ) ;
V_177 |= V_179 <<
V_180 ;
F_23 ( V_178 , V_177 ) ;
V_177 |= V_179 ;
F_23 ( V_178 , V_177 ) ;
V_177 &= ~ ( V_179 <<
V_180 ) ;
F_23 ( V_178 , V_177 ) ;
F_66 ( V_178 ) ;
F_102 ( V_4 ) ;
}
static void F_103 ( struct V_8 * V_9 , unsigned long V_124 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_125 * V_126 = V_9 -> V_126 ;
struct V_127 * V_128 = F_92 ( V_126 ) ;
struct V_129 * V_130 = V_128 -> V_130 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_97 = V_131 -> V_97 == 0 ? V_160 : V_161 ;
unsigned long V_162 = 200 ;
T_1 V_163 ;
V_163 = F_3 ( V_181 ) ;
if ( V_163 & V_165 ) {
if ( V_4 -> V_135 == V_4 -> V_135 / 64 - 1 &&
V_4 -> V_137 == V_130 -> V_136 &&
V_4 -> V_138 == V_131 -> V_97 &&
V_4 -> V_182 == V_130 -> V_183 &&
V_4 -> V_166 == V_9 -> V_153 )
return;
F_23 ( V_181 , V_163 & ~ V_165 ) ;
F_21 ( V_2 , V_131 -> V_66 ) ;
}
V_4 -> V_135 = ( V_4 -> V_135 / 64 ) - 1 ;
V_4 -> V_137 = V_130 -> V_136 ;
V_4 -> V_138 = V_131 -> V_97 ;
V_4 -> V_182 = V_130 -> V_183 ;
V_4 -> V_166 = V_9 -> V_153 ;
V_163 &= V_184 ;
V_163 |= ( V_97 | V_168 ) ;
if ( V_130 -> V_148 != V_149 ) {
V_163 |= ( V_169 | V_4 -> V_137 ) ;
F_23 ( V_185 , V_171 ) ;
} else {
F_23 ( V_185 , ~ V_171 ) ;
}
F_23 ( V_186 , V_173 |
( V_162 << V_174 ) |
( V_124 << V_175 ) ) ;
F_23 ( V_187 , V_9 -> V_153 ) ;
F_23 ( V_188 , V_130 -> V_183 | V_189 ) ;
F_23 ( V_181 , V_163 | V_165 ) ;
if ( F_104 ( V_2 ) ) {
F_23 ( V_190 ,
V_191 | V_4 -> V_137 ) ;
F_23 ( V_192 , V_9 -> V_153 ) ;
F_100 ( V_2 ) ;
}
F_25 ( L_34 , V_131 -> V_97 ) ;
}
void F_105 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_163 ;
V_163 = F_3 ( V_181 ) ;
if ( V_163 & V_165 ) {
V_163 &= ~ V_165 ;
F_23 ( V_181 , V_163 ) ;
F_25 ( L_33 ) ;
}
}
static bool F_106 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_3 ( V_181 ) & V_165 ;
}
bool F_107 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_193 . V_194 )
return false ;
return V_4 -> V_193 . V_194 ( V_2 ) ;
}
void F_108 ( struct V_8 * V_9 , unsigned long V_124 )
{
struct V_3 * V_4 = V_9 -> V_2 -> V_5 ;
if ( ! V_4 -> V_193 . V_195 )
return;
V_4 -> V_193 . V_195 ( V_9 , V_124 ) ;
}
void F_109 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_193 . V_196 )
return;
V_4 -> V_193 . V_196 ( V_2 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = NULL , * V_197 ;
struct V_131 * V_131 ;
struct V_125 * V_126 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
F_25 ( L_35 ) ;
if ( ! V_198 )
return;
if ( ! F_111 ( V_2 ) )
return;
F_14 (tmp_crtc, &dev->mode_config.crtc_list, head) {
if ( V_197 -> V_76 && V_197 -> V_126 ) {
if ( V_9 ) {
F_25 ( L_36 ) ;
V_4 -> V_199 = V_200 ;
goto V_201;
}
V_9 = V_197 ;
}
}
if ( ! V_9 || V_9 -> V_126 == NULL ) {
F_25 ( L_37 ) ;
V_4 -> V_199 = V_202 ;
goto V_201;
}
V_131 = F_93 ( V_9 ) ;
V_126 = V_9 -> V_126 ;
V_128 = F_92 ( V_126 ) ;
V_130 = V_128 -> V_130 ;
if ( ! V_203 ) {
F_25 ( L_38 ) ;
V_4 -> V_199 = V_204 ;
goto V_201;
}
if ( V_128 -> V_130 -> V_52 . V_205 > V_4 -> V_141 ) {
F_25 ( L_39
L_40 ) ;
V_4 -> V_199 = V_206 ;
goto V_201;
}
if ( ( V_9 -> V_207 . V_208 & V_209 ) ||
( V_9 -> V_207 . V_208 & V_210 ) ) {
F_25 ( L_41
L_42 ) ;
V_4 -> V_199 = V_211 ;
goto V_201;
}
if ( ( V_9 -> V_207 . V_212 > 2048 ) ||
( V_9 -> V_207 . V_213 > 1536 ) ) {
F_25 ( L_43 ) ;
V_4 -> V_199 = V_214 ;
goto V_201;
}
if ( ( F_112 ( V_2 ) || F_95 ( V_2 ) ) && V_131 -> V_97 != 0 ) {
F_25 ( L_44 ) ;
V_4 -> V_199 = V_215 ;
goto V_201;
}
if ( V_130 -> V_148 != V_216 ) {
F_25 ( L_45 ) ;
V_4 -> V_199 = V_217 ;
goto V_201;
}
if ( F_113 () )
goto V_201;
F_108 ( V_9 , 500 ) ;
return;
V_201:
if ( F_107 ( V_2 ) ) {
F_25 ( L_46 ) ;
F_109 ( V_2 ) ;
}
}
int
F_114 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
struct V_218 * V_219 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_220 ;
int V_221 ;
switch ( V_130 -> V_148 ) {
case V_149 :
if ( F_115 ( V_2 ) || F_116 ( V_2 ) )
V_220 = 128 * 1024 ;
else if ( F_27 ( V_2 ) -> V_69 >= 4 )
V_220 = 4 * 1024 ;
else
V_220 = 64 * 1024 ;
break;
case V_216 :
V_220 = 0 ;
break;
case V_222 :
F_76 ( L_47 ) ;
return - V_223 ;
default:
F_117 () ;
}
V_4 -> V_224 . V_225 = false ;
V_221 = F_118 ( V_130 , V_220 , true ) ;
if ( V_221 )
goto V_226;
V_221 = F_119 ( V_130 , V_219 ) ;
if ( V_221 )
goto V_227;
if ( V_130 -> V_148 != V_149 ) {
V_221 = F_120 ( V_130 , V_219 ) ;
if ( V_221 )
goto V_227;
}
V_4 -> V_224 . V_225 = true ;
return 0 ;
V_227:
F_121 ( V_130 ) ;
V_226:
V_4 -> V_224 . V_225 = true ;
return V_221 ;
}
static int
F_122 ( struct V_8 * V_9 , struct V_125 * V_126 ,
int V_228 , int V_153 , enum V_229 V_77 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
int V_97 = V_131 -> V_97 ;
unsigned long V_230 , V_231 ;
T_1 V_232 ;
T_1 V_70 ;
switch ( V_97 ) {
case 0 :
case 1 :
break;
default:
F_76 ( L_48 , V_97 ) ;
return - V_223 ;
}
V_128 = F_92 ( V_126 ) ;
V_130 = V_128 -> V_130 ;
V_70 = F_49 ( V_97 ) ;
V_232 = F_3 ( V_70 ) ;
V_232 &= ~ V_233 ;
switch ( V_126 -> V_234 ) {
case 8 :
V_232 |= V_235 ;
break;
case 16 :
if ( V_126 -> V_236 == 15 )
V_232 |= V_237 ;
else
V_232 |= V_238 ;
break;
case 24 :
case 32 :
V_232 |= V_239 ;
break;
default:
F_76 ( L_49 ) ;
return - V_223 ;
}
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
if ( V_130 -> V_148 != V_149 )
V_232 |= V_240 ;
else
V_232 &= ~ V_240 ;
}
if ( F_8 ( V_2 ) )
V_232 |= V_241 ;
F_23 ( V_70 , V_232 ) ;
V_230 = V_130 -> V_183 ;
V_231 = V_153 * V_126 -> V_134 + V_228 * ( V_126 -> V_234 / 8 ) ;
F_25 ( L_50 ,
V_230 , V_231 , V_228 , V_153 , V_126 -> V_134 ) ;
F_23 ( F_123 ( V_97 ) , V_126 -> V_134 ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
F_23 ( F_124 ( V_97 ) , V_230 ) ;
F_23 ( F_125 ( V_97 ) , ( V_153 << 16 ) | V_228 ) ;
F_23 ( F_86 ( V_97 ) , V_231 ) ;
} else
F_23 ( F_86 ( V_97 ) , V_230 + V_231 ) ;
F_66 ( V_70 ) ;
F_110 ( V_2 ) ;
F_126 ( V_9 ) ;
return 0 ;
}
static int
F_127 ( struct V_8 * V_9 , int V_228 , int V_153 ,
struct V_125 * V_242 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_243 * V_244 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_221 ;
if ( ! V_9 -> V_126 ) {
F_25 ( L_51 ) ;
return 0 ;
}
switch ( V_131 -> V_97 ) {
case 0 :
case 1 :
break;
default:
return - V_223 ;
}
F_128 ( & V_2 -> V_245 ) ;
V_221 = F_114 ( V_2 ,
F_92 ( V_9 -> V_126 ) -> V_130 ,
NULL ) ;
if ( V_221 != 0 ) {
F_129 ( & V_2 -> V_245 ) ;
return V_221 ;
}
if ( V_242 ) {
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_129 * V_130 = F_92 ( V_242 ) -> V_130 ;
F_130 ( V_4 -> V_246 ,
F_131 ( & V_4 -> V_224 . V_247 ) ||
F_131 ( & V_130 -> V_248 ) == 0 ) ;
V_221 = F_132 ( V_130 ) ;
( void ) V_221 ;
}
V_221 = F_122 ( V_9 , V_9 -> V_126 , V_228 , V_153 ,
V_249 ) ;
if ( V_221 ) {
F_121 ( F_92 ( V_9 -> V_126 ) -> V_130 ) ;
F_129 ( & V_2 -> V_245 ) ;
return V_221 ;
}
if ( V_242 ) {
F_21 ( V_2 , V_131 -> V_66 ) ;
F_121 ( F_92 ( V_242 ) -> V_130 ) ;
}
F_129 ( & V_2 -> V_245 ) ;
if ( ! V_2 -> V_250 -> V_251 )
return 0 ;
V_244 = V_2 -> V_250 -> V_251 -> V_252 ;
if ( ! V_244 -> V_253 )
return 0 ;
if ( V_131 -> V_66 ) {
V_244 -> V_253 -> V_254 = V_228 ;
V_244 -> V_253 -> V_255 = V_153 ;
} else {
V_244 -> V_253 -> V_256 = V_228 ;
V_244 -> V_253 -> V_257 = V_153 ;
}
return 0 ;
}
static void F_133 ( struct V_8 * V_9 , int clock )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_258 ;
F_25 ( L_52 , clock ) ;
V_258 = F_3 ( V_259 ) ;
V_258 &= ~ V_260 ;
if ( clock < 200000 ) {
T_1 V_261 ;
V_258 |= V_262 ;
V_261 = F_3 ( 0x4600c ) ;
V_261 &= 0xffff0000 ;
F_23 ( 0x4600c , V_261 | 0x8124 ) ;
V_261 = F_3 ( 0x46010 ) ;
F_23 ( 0x46010 , V_261 | 1 ) ;
V_261 = F_3 ( 0x46034 ) ;
F_23 ( 0x46034 , V_261 | ( 1 << 24 ) ) ;
} else {
V_258 |= V_263 ;
}
F_23 ( V_259 , V_258 ) ;
F_66 ( V_259 ) ;
F_67 ( 500 ) ;
}
static void F_134 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
T_1 V_70 , V_261 ;
V_70 = F_40 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
if ( F_135 ( V_2 ) ) {
V_261 &= ~ V_264 ;
V_261 |= V_264 | V_265 ;
} else {
V_261 &= ~ V_266 ;
V_261 |= V_266 | V_265 ;
}
F_23 ( V_70 , V_261 ) ;
V_70 = F_42 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
if ( F_136 ( V_2 ) ) {
V_261 &= ~ V_267 ;
V_261 |= V_268 ;
} else {
V_261 &= ~ V_266 ;
V_261 |= V_266 ;
}
F_23 ( V_70 , V_261 | V_269 ) ;
F_66 ( V_70 ) ;
F_67 ( 1000 ) ;
if ( F_135 ( V_2 ) )
F_23 ( V_70 , F_3 ( V_70 ) | V_270 |
V_271 ) ;
}
static void F_137 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
int V_97 = V_131 -> V_97 ;
T_1 V_70 , V_261 , V_272 ;
F_84 ( V_4 , V_66 ) ;
F_48 ( V_4 , V_97 ) ;
V_70 = F_138 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ V_273 ;
V_261 &= ~ V_274 ;
F_23 ( V_70 , V_261 ) ;
F_3 ( V_70 ) ;
F_67 ( 150 ) ;
V_70 = F_40 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ ( 7 << 19 ) ;
V_261 |= ( V_131 -> V_275 - 1 ) << 19 ;
V_261 &= ~ V_266 ;
V_261 |= V_276 ;
F_23 ( V_70 , V_261 | V_81 ) ;
V_70 = F_42 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ V_266 ;
V_261 |= V_276 ;
F_23 ( V_70 , V_261 | V_82 ) ;
F_66 ( V_70 ) ;
F_67 ( 150 ) ;
if ( F_139 ( V_2 ) ) {
F_23 ( F_140 ( V_66 ) , V_277 ) ;
F_23 ( F_140 ( V_66 ) , V_277 |
V_278 ) ;
}
V_70 = F_141 ( V_66 ) ;
for ( V_272 = 0 ; V_272 < 5 ; V_272 ++ ) {
V_261 = F_3 ( V_70 ) ;
F_25 ( L_53 , V_261 ) ;
if ( ( V_261 & V_274 ) ) {
F_25 ( L_54 ) ;
F_23 ( V_70 , V_261 | V_274 ) ;
break;
}
}
if ( V_272 == 5 )
F_76 ( L_55 ) ;
V_70 = F_40 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ V_266 ;
V_261 |= V_279 ;
F_23 ( V_70 , V_261 ) ;
V_70 = F_42 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ V_266 ;
V_261 |= V_279 ;
F_23 ( V_70 , V_261 ) ;
F_66 ( V_70 ) ;
F_67 ( 150 ) ;
V_70 = F_141 ( V_66 ) ;
for ( V_272 = 0 ; V_272 < 5 ; V_272 ++ ) {
V_261 = F_3 ( V_70 ) ;
F_25 ( L_53 , V_261 ) ;
if ( V_261 & V_273 ) {
F_23 ( V_70 , V_261 | V_273 ) ;
F_25 ( L_56 ) ;
break;
}
}
if ( V_272 == 5 )
F_76 ( L_57 ) ;
F_25 ( L_58 ) ;
}
static void F_142 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
T_1 V_70 , V_261 , V_99 ;
V_70 = F_138 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ V_273 ;
V_261 &= ~ V_274 ;
F_23 ( V_70 , V_261 ) ;
F_66 ( V_70 ) ;
F_67 ( 150 ) ;
V_70 = F_40 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ ( 7 << 19 ) ;
V_261 |= ( V_131 -> V_275 - 1 ) << 19 ;
V_261 &= ~ V_266 ;
V_261 |= V_276 ;
V_261 &= ~ V_280 ;
V_261 |= V_281 ;
F_23 ( V_70 , V_261 | V_81 ) ;
V_70 = F_42 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
if ( F_136 ( V_2 ) ) {
V_261 &= ~ V_267 ;
V_261 |= V_282 ;
} else {
V_261 &= ~ V_266 ;
V_261 |= V_276 ;
}
F_23 ( V_70 , V_261 | V_82 ) ;
F_66 ( V_70 ) ;
F_67 ( 150 ) ;
for ( V_99 = 0 ; V_99 < 4 ; V_99 ++ ) {
V_70 = F_40 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ V_280 ;
V_261 |= V_283 [ V_99 ] ;
F_23 ( V_70 , V_261 ) ;
F_66 ( V_70 ) ;
F_67 ( 500 ) ;
V_70 = F_141 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
F_25 ( L_53 , V_261 ) ;
if ( V_261 & V_274 ) {
F_23 ( V_70 , V_261 | V_274 ) ;
F_25 ( L_54 ) ;
break;
}
}
if ( V_99 == 4 )
F_76 ( L_55 ) ;
V_70 = F_40 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ V_266 ;
V_261 |= V_279 ;
if ( F_104 ( V_2 ) ) {
V_261 &= ~ V_280 ;
V_261 |= V_281 ;
}
F_23 ( V_70 , V_261 ) ;
V_70 = F_42 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
if ( F_136 ( V_2 ) ) {
V_261 &= ~ V_267 ;
V_261 |= V_284 ;
} else {
V_261 &= ~ V_266 ;
V_261 |= V_279 ;
}
F_23 ( V_70 , V_261 ) ;
F_66 ( V_70 ) ;
F_67 ( 150 ) ;
for ( V_99 = 0 ; V_99 < 4 ; V_99 ++ ) {
V_70 = F_40 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ V_280 ;
V_261 |= V_283 [ V_99 ] ;
F_23 ( V_70 , V_261 ) ;
F_66 ( V_70 ) ;
F_67 ( 500 ) ;
V_70 = F_141 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
F_25 ( L_53 , V_261 ) ;
if ( V_261 & V_273 ) {
F_23 ( V_70 , V_261 | V_273 ) ;
F_25 ( L_56 ) ;
break;
}
}
if ( V_99 == 4 )
F_76 ( L_57 ) ;
F_25 ( L_59 ) ;
}
static void F_143 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
T_1 V_70 , V_261 , V_99 ;
V_70 = F_138 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ V_273 ;
V_261 &= ~ V_274 ;
F_23 ( V_70 , V_261 ) ;
F_66 ( V_70 ) ;
F_67 ( 150 ) ;
V_70 = F_40 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ ( 7 << 19 ) ;
V_261 |= ( V_131 -> V_275 - 1 ) << 19 ;
V_261 &= ~ ( V_285 | V_264 ) ;
V_261 |= V_286 ;
V_261 &= ~ V_280 ;
V_261 |= V_281 ;
F_23 ( V_70 , V_261 | V_81 ) ;
V_70 = F_42 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ V_285 ;
V_261 &= ~ V_267 ;
V_261 |= V_282 ;
F_23 ( V_70 , V_261 | V_82 ) ;
F_66 ( V_70 ) ;
F_67 ( 150 ) ;
for ( V_99 = 0 ; V_99 < 4 ; V_99 ++ ) {
V_70 = F_40 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ V_280 ;
V_261 |= V_283 [ V_99 ] ;
F_23 ( V_70 , V_261 ) ;
F_66 ( V_70 ) ;
F_67 ( 500 ) ;
V_70 = F_141 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
F_25 ( L_53 , V_261 ) ;
if ( V_261 & V_274 ||
( F_3 ( V_70 ) & V_274 ) ) {
F_23 ( V_70 , V_261 | V_274 ) ;
F_25 ( L_54 ) ;
break;
}
}
if ( V_99 == 4 )
F_76 ( L_55 ) ;
V_70 = F_40 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ V_264 ;
V_261 |= V_287 ;
V_261 &= ~ V_280 ;
V_261 |= V_281 ;
F_23 ( V_70 , V_261 ) ;
V_70 = F_42 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ V_267 ;
V_261 |= V_284 ;
F_23 ( V_70 , V_261 ) ;
F_66 ( V_70 ) ;
F_67 ( 150 ) ;
for ( V_99 = 0 ; V_99 < 4 ; V_99 ++ ) {
V_70 = F_40 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ V_280 ;
V_261 |= V_283 [ V_99 ] ;
F_23 ( V_70 , V_261 ) ;
F_66 ( V_70 ) ;
F_67 ( 500 ) ;
V_70 = F_141 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
F_25 ( L_53 , V_261 ) ;
if ( V_261 & V_273 ) {
F_23 ( V_70 , V_261 | V_273 ) ;
F_25 ( L_56 ) ;
break;
}
}
if ( V_99 == 4 )
F_76 ( L_57 ) ;
F_25 ( L_59 ) ;
}
static void F_144 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
T_1 V_70 , V_261 ;
F_23 ( F_145 ( V_66 ) ,
F_3 ( F_146 ( V_66 ) ) & V_288 ) ;
V_70 = F_42 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ ( ( 0x7 << 19 ) | ( 0x7 << 16 ) ) ;
V_261 |= ( V_131 -> V_275 - 1 ) << 19 ;
V_261 |= ( F_3 ( F_28 ( V_66 ) ) & V_117 ) << 11 ;
F_23 ( V_70 , V_261 | V_85 ) ;
F_66 ( V_70 ) ;
F_67 ( 200 ) ;
V_261 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_261 | V_289 ) ;
F_66 ( V_70 ) ;
F_67 ( 200 ) ;
V_70 = F_40 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
if ( ( V_261 & V_84 ) == 0 ) {
F_23 ( V_70 , V_261 | V_84 ) ;
F_66 ( V_70 ) ;
F_67 ( 100 ) ;
}
}
static void F_147 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
T_1 V_70 , V_261 ;
V_70 = F_40 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_261 & ~ V_81 ) ;
F_66 ( V_70 ) ;
V_70 = F_42 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ ( 0x7 << 16 ) ;
V_261 |= ( F_3 ( F_28 ( V_66 ) ) & V_117 ) << 11 ;
F_23 ( V_70 , V_261 & ~ V_82 ) ;
F_66 ( V_70 ) ;
F_67 ( 100 ) ;
if ( F_139 ( V_2 ) ) {
F_23 ( F_140 ( V_66 ) , V_277 ) ;
F_23 ( F_140 ( V_66 ) ,
F_3 ( F_140 ( V_66 ) &
~ V_278 ) ) ;
}
V_70 = F_40 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ V_266 ;
V_261 |= V_276 ;
F_23 ( V_70 , V_261 ) ;
V_70 = F_42 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
if ( F_136 ( V_2 ) ) {
V_261 &= ~ V_267 ;
V_261 |= V_282 ;
} else {
V_261 &= ~ V_266 ;
V_261 |= V_276 ;
}
V_261 &= ~ ( 0x07 << 16 ) ;
V_261 |= ( F_3 ( F_28 ( V_66 ) ) & V_117 ) << 11 ;
F_23 ( V_70 , V_261 ) ;
F_66 ( V_70 ) ;
F_67 ( 100 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_218 * V_290 ;
T_1 V_291 ;
if ( F_11 ( V_2 ) )
return;
V_290 = F_149 ( V_4 ) ;
V_291 = F_150 ( V_290 ) ;
if ( V_291 & V_292 )
F_151 ( V_290 , V_291 ) ;
}
static void F_152 ( struct V_8 * V_9 )
{
struct V_129 * V_130 ;
struct V_3 * V_4 ;
if ( V_9 -> V_126 == NULL )
return;
V_130 = F_92 ( V_9 -> V_126 ) -> V_130 ;
V_4 = V_9 -> V_2 -> V_5 ;
F_130 ( V_4 -> V_246 ,
F_131 ( & V_130 -> V_248 ) == 0 ) ;
}
static bool F_153 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_293 :
if ( ! F_154 ( & V_51 -> V_52 ) )
return false ;
continue;
}
}
return true ;
}
static void F_155 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
T_1 V_70 , V_261 ;
V_4 -> V_193 . V_294 ( V_9 ) ;
F_70 ( V_4 , V_66 ) ;
if ( F_136 ( V_2 ) ) {
V_261 = F_3 ( V_295 ) ;
if ( V_66 == 0 && ( V_261 & V_296 ) == 0 )
V_261 |= ( V_296 | V_297 ) ;
else if ( V_66 == 1 && ( V_261 & V_298 ) == 0 )
V_261 |= ( V_298 | V_299 ) ;
F_23 ( V_295 , V_261 ) ;
}
F_45 ( V_4 , V_66 ) ;
F_23 ( F_156 ( V_66 ) , F_3 ( F_157 ( V_66 ) ) ) ;
F_23 ( F_158 ( V_66 ) , F_3 ( F_159 ( V_66 ) ) ) ;
F_23 ( F_160 ( V_66 ) , F_3 ( F_161 ( V_66 ) ) ) ;
F_23 ( F_162 ( V_66 ) , F_3 ( F_163 ( V_66 ) ) ) ;
F_23 ( F_164 ( V_66 ) , F_3 ( F_165 ( V_66 ) ) ) ;
F_23 ( F_166 ( V_66 ) , F_3 ( F_167 ( V_66 ) ) ) ;
F_134 ( V_9 ) ;
if ( F_136 ( V_2 ) &&
F_5 ( V_9 , V_20 ) ) {
V_70 = F_168 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ ( V_300 |
V_301 |
V_302 ) ;
V_261 |= ( V_303 |
V_304 ) ;
V_261 |= V_305 ;
if ( V_9 -> V_207 . V_208 & V_306 )
V_261 |= V_307 ;
if ( V_9 -> V_207 . V_208 & V_308 )
V_261 |= V_309 ;
switch ( F_169 ( V_9 ) ) {
case V_108 :
V_261 |= V_310 ;
break;
case V_109 :
V_261 |= V_311 ;
break;
case V_110 :
V_261 |= V_312 ;
break;
default:
F_25 ( L_60 ) ;
V_261 |= V_310 ;
break;
}
F_23 ( V_70 , V_261 ) ;
}
F_72 ( V_4 , V_66 ) ;
}
static void F_170 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
int V_97 = V_131 -> V_97 ;
T_1 V_261 ;
bool V_313 ;
if ( V_131 -> V_314 )
return;
V_131 -> V_314 = true ;
F_171 ( V_2 ) ;
if ( F_5 ( V_9 , V_12 ) ) {
V_261 = F_3 ( V_13 ) ;
if ( ( V_261 & V_123 ) == 0 )
F_23 ( V_13 , V_261 | V_123 ) ;
}
V_313 = F_153 ( V_9 ) ;
if ( V_313 )
F_144 ( V_9 ) ;
else
F_147 ( V_9 ) ;
if ( V_4 -> V_315 &&
( F_5 ( V_9 , V_12 ) || V_21 ) ) {
F_23 ( F_172 ( V_66 ) , V_316 | V_317 ) ;
F_23 ( F_173 ( V_66 ) , V_4 -> V_318 ) ;
F_23 ( F_174 ( V_66 ) , V_4 -> V_315 ) ;
}
F_80 ( V_4 , V_66 , V_313 ) ;
F_83 ( V_4 , V_97 , V_66 ) ;
if ( V_313 )
F_155 ( V_9 ) ;
F_175 ( V_9 ) ;
F_128 ( & V_2 -> V_245 ) ;
F_110 ( V_2 ) ;
F_129 ( & V_2 -> V_245 ) ;
F_176 ( V_9 , true ) ;
}
static void F_177 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
int V_97 = V_131 -> V_97 ;
T_1 V_70 , V_261 ;
if ( ! V_131 -> V_314 )
return;
F_152 ( V_9 ) ;
F_178 ( V_2 , V_66 ) ;
F_176 ( V_9 , false ) ;
F_87 ( V_4 , V_97 , V_66 ) ;
if ( V_4 -> V_138 == V_97 &&
V_4 -> V_193 . V_196 )
V_4 -> V_193 . V_196 ( V_2 ) ;
F_82 ( V_4 , V_66 ) ;
F_23 ( F_172 ( V_66 ) , 0 ) ;
F_23 ( F_174 ( V_66 ) , 0 ) ;
F_147 ( V_9 ) ;
F_90 ( V_4 , V_66 ) ;
F_77 ( V_4 , V_66 ) ;
if ( F_136 ( V_2 ) ) {
V_70 = F_168 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
V_261 &= ~ ( V_303 | V_300 ) ;
V_261 |= V_319 ;
F_23 ( V_70 , V_261 ) ;
V_261 = F_3 ( V_295 ) ;
switch ( V_66 ) {
case 0 :
V_261 &= ~ ( V_296 | V_297 ) ;
break;
case 1 :
V_261 &= ~ ( V_298 | V_299 ) ;
break;
case 2 :
V_261 &= ~ ( V_320 | V_321 ) ;
break;
default:
F_117 () ;
}
F_23 ( V_295 , V_261 ) ;
}
F_71 ( V_4 , V_66 ) ;
V_70 = F_42 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_261 & ~ V_289 ) ;
V_70 = F_40 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_261 & ~ V_84 ) ;
F_66 ( V_70 ) ;
F_67 ( 100 ) ;
V_70 = F_42 ( V_66 ) ;
V_261 = F_3 ( V_70 ) ;
F_23 ( V_70 , V_261 & ~ V_85 ) ;
F_66 ( V_70 ) ;
F_67 ( 100 ) ;
V_131 -> V_314 = false ;
F_171 ( V_2 ) ;
F_128 ( & V_2 -> V_245 ) ;
F_110 ( V_2 ) ;
F_148 ( V_2 ) ;
F_129 ( & V_2 -> V_245 ) ;
}
static void F_179 ( struct V_8 * V_9 , int V_207 )
{
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
int V_97 = V_131 -> V_97 ;
switch ( V_207 ) {
case V_322 :
case V_323 :
case V_324 :
F_25 ( L_61 , V_66 , V_97 ) ;
F_170 ( V_9 ) ;
break;
case V_325 :
F_25 ( L_62 , V_66 , V_97 ) ;
F_177 ( V_9 ) ;
break;
}
}
static void F_180 ( struct V_131 * V_131 , bool V_326 )
{
if ( ! V_326 && V_131 -> V_327 ) {
struct V_1 * V_2 = V_131 -> V_52 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_128 ( & V_2 -> V_245 ) ;
V_4 -> V_224 . V_225 = false ;
( void ) F_181 ( V_131 -> V_327 ) ;
V_4 -> V_224 . V_225 = true ;
F_129 ( & V_2 -> V_245 ) ;
}
}
static void F_182 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
int V_97 = V_131 -> V_97 ;
if ( V_131 -> V_314 )
return;
V_131 -> V_314 = true ;
F_171 ( V_2 ) ;
F_62 ( V_4 , V_66 ) ;
F_80 ( V_4 , V_66 , false ) ;
F_83 ( V_4 , V_97 , V_66 ) ;
F_175 ( V_9 ) ;
F_110 ( V_2 ) ;
F_180 ( V_131 , true ) ;
F_176 ( V_9 , true ) ;
}
static void F_183 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
int V_97 = V_131 -> V_97 ;
if ( ! V_131 -> V_314 )
return;
F_152 ( V_9 ) ;
F_178 ( V_2 , V_66 ) ;
F_180 ( V_131 , false ) ;
F_176 ( V_9 , false ) ;
if ( V_4 -> V_138 == V_97 &&
V_4 -> V_193 . V_196 )
V_4 -> V_193 . V_196 ( V_2 ) ;
F_87 ( V_4 , V_97 , V_66 ) ;
F_82 ( V_4 , V_66 ) ;
F_68 ( V_4 , V_66 ) ;
V_131 -> V_314 = false ;
F_110 ( V_2 ) ;
F_171 ( V_2 ) ;
F_148 ( V_2 ) ;
}
static void F_184 ( struct V_8 * V_9 , int V_207 )
{
switch ( V_207 ) {
case V_322 :
case V_323 :
case V_324 :
F_182 ( V_9 ) ;
break;
case V_325 :
F_183 ( V_9 ) ;
break;
}
}
static void F_185 ( struct V_8 * V_9 , int V_207 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_243 * V_244 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
bool V_76 ;
if ( V_131 -> V_328 == V_207 )
return;
V_131 -> V_328 = V_207 ;
V_4 -> V_193 . V_329 ( V_9 , V_207 ) ;
if ( ! V_2 -> V_250 -> V_251 )
return;
V_244 = V_2 -> V_250 -> V_251 -> V_252 ;
if ( ! V_244 -> V_253 )
return;
V_76 = V_9 -> V_76 && V_207 != V_325 ;
switch ( V_66 ) {
case 0 :
V_244 -> V_253 -> V_330 = V_76 ? V_9 -> V_207 . V_212 : 0 ;
V_244 -> V_253 -> V_331 = V_76 ? V_9 -> V_207 . V_213 : 0 ;
break;
case 1 :
V_244 -> V_253 -> V_332 = V_76 ? V_9 -> V_207 . V_212 : 0 ;
V_244 -> V_253 -> V_333 = V_76 ? V_9 -> V_207 . V_213 : 0 ;
break;
default:
F_76 ( L_63 , F_46 ( V_66 ) ) ;
break;
}
}
static void F_186 ( struct V_8 * V_9 )
{
struct V_334 * V_335 = V_9 -> V_336 ;
struct V_1 * V_2 = V_9 -> V_2 ;
V_335 -> V_329 ( V_9 , V_325 ) ;
if ( V_9 -> V_126 ) {
F_128 ( & V_2 -> V_245 ) ;
F_121 ( F_92 ( V_9 -> V_126 ) -> V_130 ) ;
F_129 ( & V_2 -> V_245 ) ;
}
}
static void F_187 ( struct V_8 * V_9 )
{
F_183 ( V_9 ) ;
}
static void F_188 ( struct V_8 * V_9 )
{
F_182 ( V_9 ) ;
}
static void F_189 ( struct V_8 * V_9 )
{
F_177 ( V_9 ) ;
}
static void F_190 ( struct V_8 * V_9 )
{
F_170 ( V_9 ) ;
}
void F_191 ( struct V_337 * V_51 )
{
struct V_338 * V_339 = V_51 -> V_336 ;
V_339 -> V_329 ( V_51 , V_325 ) ;
}
void F_192 ( struct V_337 * V_51 )
{
struct V_338 * V_339 = V_51 -> V_336 ;
V_339 -> V_329 ( V_51 , V_322 ) ;
}
void F_193 ( struct V_337 * V_51 )
{
struct V_50 * V_50 = F_194 ( V_51 ) ;
F_195 ( V_51 ) ;
F_196 ( V_50 ) ;
}
static bool F_197 ( struct V_8 * V_9 ,
struct V_340 * V_207 ,
struct V_340 * V_341 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
if ( F_8 ( V_2 ) ) {
if ( V_207 -> clock * 3 > V_342 * 4 )
return false ;
}
if ( V_341 -> V_343 == 0 )
F_198 ( V_341 , 0 ) ;
return true ;
}
static int F_199 ( struct V_1 * V_2 )
{
return 400000 ;
}
static int F_200 ( struct V_1 * V_2 )
{
return 333000 ;
}
static int F_201 ( struct V_1 * V_2 )
{
return 200000 ;
}
static int F_202 ( struct V_1 * V_2 )
{
T_4 V_344 = 0 ;
F_203 ( V_2 -> V_345 , V_346 , & V_344 ) ;
if ( V_344 & V_347 )
return 133000 ;
else {
switch ( V_344 & V_348 ) {
case V_349 :
return 333000 ;
default:
case V_350 :
return 190000 ;
}
}
}
static int F_204 ( struct V_1 * V_2 )
{
return 266000 ;
}
static int F_205 ( struct V_1 * V_2 )
{
T_4 V_351 = 0 ;
switch ( V_351 & V_352 ) {
case V_353 :
case V_354 :
return 200000 ;
case V_355 :
return 250000 ;
case V_356 :
return 133000 ;
}
return 0 ;
}
static int F_206 ( struct V_1 * V_2 )
{
return 133000 ;
}
static void
F_207 ( T_1 * V_357 , T_1 * V_358 )
{
while ( * V_357 > 0xffffff || * V_358 > 0xffffff ) {
* V_357 >>= 1 ;
* V_358 >>= 1 ;
}
}
static void
F_208 ( int V_234 , int V_359 , int V_360 ,
int V_361 , struct V_362 * V_363 )
{
V_363 -> V_364 = 64 ;
V_363 -> V_365 = V_234 * V_360 ;
V_363 -> V_366 = V_361 * V_359 * 8 ;
F_207 ( & V_363 -> V_365 , & V_363 -> V_366 ) ;
V_363 -> V_367 = V_360 ;
V_363 -> V_368 = V_361 ;
F_207 ( & V_363 -> V_367 , & V_363 -> V_368 ) ;
}
static unsigned long F_209 ( unsigned long V_369 ,
const struct V_370 * V_371 ,
int V_372 ,
int V_373 ,
unsigned long V_374 )
{
long V_375 , V_376 ;
V_375 = ( ( V_369 / 1000 ) * V_373 * V_374 ) /
1000 ;
V_375 = F_210 ( V_375 , V_371 -> V_377 ) ;
F_25 ( L_64 , V_375 ) ;
V_376 = V_372 - ( V_375 + V_371 -> V_378 ) ;
F_25 ( L_65 , V_376 ) ;
if ( V_376 > ( long ) V_371 -> V_379 )
V_376 = V_371 -> V_379 ;
if ( V_376 <= 0 )
V_376 = V_371 -> V_380 ;
return V_376 ;
}
static const struct V_381 * F_211 ( int V_382 ,
int V_383 ,
int V_384 ,
int V_385 )
{
const struct V_381 * V_386 ;
int V_99 ;
if ( V_384 == 0 || V_385 == 0 )
return NULL ;
for ( V_99 = 0 ; V_99 < F_212 ( V_387 ) ; V_99 ++ ) {
V_386 = & V_387 [ V_99 ] ;
if ( V_382 == V_386 -> V_382 &&
V_383 == V_386 -> V_383 &&
V_384 == V_386 -> V_388 && V_385 == V_386 -> V_389 )
return V_386 ;
}
F_25 ( L_66 ) ;
return NULL ;
}
static void F_213 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_390 , F_3 ( V_390 ) & ~ V_391 ) ;
}
static int F_214 ( struct V_1 * V_2 , int V_97 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_392 = F_3 ( V_393 ) ;
int V_205 ;
V_205 = V_392 & 0x7f ;
if ( V_97 )
V_205 = ( ( V_392 >> V_394 ) & 0x7f ) - V_205 ;
F_25 ( L_67 , V_392 ,
V_97 ? L_68 : L_69 , V_205 ) ;
return V_205 ;
}
static int F_215 ( struct V_1 * V_2 , int V_97 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_392 = F_3 ( V_393 ) ;
int V_205 ;
V_205 = V_392 & 0x1ff ;
if ( V_97 )
V_205 = ( ( V_392 >> V_395 ) & 0x1ff ) - V_205 ;
V_205 >>= 1 ;
F_25 ( L_67 , V_392 ,
V_97 ? L_68 : L_69 , V_205 ) ;
return V_205 ;
}
static int F_216 ( struct V_1 * V_2 , int V_97 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_392 = F_3 ( V_393 ) ;
int V_205 ;
V_205 = V_392 & 0x7f ;
V_205 >>= 2 ;
F_25 ( L_67 , V_392 ,
V_97 ? L_68 : L_69 ,
V_205 ) ;
return V_205 ;
}
static int F_217 ( struct V_1 * V_2 , int V_97 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_392 = F_3 ( V_393 ) ;
int V_205 ;
V_205 = V_392 & 0x7f ;
V_205 >>= 1 ;
F_25 ( L_67 , V_392 ,
V_97 ? L_68 : L_69 , V_205 ) ;
return V_205 ;
}
static struct V_8 * F_218 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_76 = NULL ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_9 -> V_76 && V_9 -> V_126 ) {
if ( V_76 )
return NULL ;
V_76 = V_9 ;
}
}
return V_76 ;
}
static void F_219 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
const struct V_381 * V_386 ;
T_1 V_70 ;
unsigned long V_371 ;
V_386 = F_211 ( F_220 ( V_2 ) , V_4 -> V_383 ,
V_4 -> V_388 , V_4 -> V_389 ) ;
if ( ! V_386 ) {
F_25 ( L_66 ) ;
F_213 ( V_2 ) ;
return;
}
V_9 = F_218 ( V_2 ) ;
if ( V_9 ) {
int clock = V_9 -> V_207 . clock ;
int V_373 = V_9 -> V_126 -> V_234 / 8 ;
V_371 = F_209 ( clock , & V_396 ,
V_396 . V_372 ,
V_373 , V_386 -> V_397 ) ;
V_70 = F_3 ( V_398 ) ;
V_70 &= ~ V_399 ;
V_70 |= V_371 << V_400 ;
F_23 ( V_398 , V_70 ) ;
F_25 ( L_70 , V_70 ) ;
V_371 = F_209 ( clock , & V_401 ,
V_396 . V_372 ,
V_373 , V_386 -> V_402 ) ;
V_70 = F_3 ( V_390 ) ;
V_70 &= ~ V_403 ;
V_70 |= ( V_371 & 0x3f ) << V_404 ;
F_23 ( V_390 , V_70 ) ;
V_371 = F_209 ( clock , & V_405 ,
V_405 . V_372 ,
V_373 , V_386 -> V_406 ) ;
V_70 = F_3 ( V_390 ) ;
V_70 &= ~ V_407 ;
V_70 |= V_371 & V_407 ;
F_23 ( V_390 , V_70 ) ;
V_371 = F_209 ( clock , & V_408 ,
V_405 . V_372 ,
V_373 , V_386 -> V_409 ) ;
V_70 = F_3 ( V_390 ) ;
V_70 &= ~ V_410 ;
V_70 |= ( V_371 & 0x3f ) << V_411 ;
F_23 ( V_390 , V_70 ) ;
F_25 ( L_71 , V_70 ) ;
F_23 ( V_390 ,
F_3 ( V_390 ) | V_391 ) ;
F_25 ( L_72 ) ;
} else {
F_213 ( V_2 ) ;
F_25 ( L_73 ) ;
}
}
static bool F_221 ( struct V_1 * V_2 ,
int V_97 ,
const struct V_370 * V_193 ,
int V_412 ,
const struct V_370 * V_413 ,
int V_414 ,
int * V_415 ,
int * V_416 )
{
struct V_8 * V_9 ;
int V_417 , V_212 , clock , V_373 ;
int V_418 , V_419 ;
int V_420 , V_421 ;
V_9 = F_222 ( V_2 , V_97 ) ;
if ( V_9 -> V_126 == NULL || ! V_9 -> V_76 ) {
* V_416 = V_413 -> V_378 ;
* V_415 = V_193 -> V_378 ;
return false ;
}
V_417 = V_9 -> V_207 . V_417 ;
V_212 = V_9 -> V_207 . V_212 ;
clock = V_9 -> V_207 . clock ;
V_373 = V_9 -> V_126 -> V_234 / 8 ;
V_420 = ( ( clock * V_373 / 1000 ) * V_412 ) / 1000 ;
V_421 = V_193 -> V_372 * V_193 -> V_377 - V_212 * 8 ;
if ( V_421 > 0 )
V_420 += V_421 ;
V_420 = F_210 ( V_420 , V_193 -> V_377 ) ;
* V_415 = V_420 + V_193 -> V_378 ;
if ( * V_415 > ( int ) V_193 -> V_379 )
* V_415 = V_193 -> V_379 ;
V_418 = ( ( V_417 * 1000 ) / clock ) ;
V_419 = ( V_414 / V_418 + 1000 ) / 1000 ;
V_420 = V_419 * 64 * V_373 ;
V_421 = V_413 -> V_372 * V_413 -> V_377 - V_212 * 8 ;
if ( V_421 > 0 )
V_420 += V_421 ;
V_420 = F_210 ( V_420 , V_413 -> V_377 ) ;
* V_416 = V_420 + V_413 -> V_378 ;
if ( * V_416 > ( int ) V_413 -> V_379 )
* V_416 = ( int ) V_413 -> V_379 ;
return true ;
}
static bool F_223 ( struct V_1 * V_2 ,
int V_422 , int V_416 ,
const struct V_370 * V_193 ,
const struct V_370 * V_413 )
{
F_25 ( L_74 ,
V_422 , V_416 ) ;
if ( V_422 > V_193 -> V_379 ) {
F_25 ( L_75 ,
V_422 , V_193 -> V_379 ) ;
return false ;
}
if ( V_416 > V_413 -> V_379 ) {
F_25 ( L_76 ,
V_416 , V_413 -> V_379 ) ;
return false ;
}
if ( ! ( V_422 || V_416 ) ) {
F_25 ( L_77 ) ;
return false ;
}
return true ;
}
static bool F_224 ( struct V_1 * V_2 ,
int V_97 ,
int V_374 ,
const struct V_370 * V_193 ,
const struct V_370 * V_413 ,
int * V_422 , int * V_416 )
{
struct V_8 * V_9 ;
int V_212 , V_417 , V_373 , clock ;
unsigned long V_418 ;
int V_419 , V_423 ;
int V_424 , V_425 ;
int V_420 ;
if ( ! V_374 ) {
* V_422 = * V_416 = 0 ;
return false ;
}
V_9 = F_222 ( V_2 , V_97 ) ;
V_212 = V_9 -> V_207 . V_212 ;
V_417 = V_9 -> V_207 . V_417 ;
clock = V_9 -> V_207 . clock ;
V_373 = V_9 -> V_126 -> V_234 / 8 ;
V_418 = ( V_417 * 1000 ) / clock ;
V_419 = ( V_374 / V_418 + 1000 ) / 1000 ;
V_423 = V_212 * V_373 ;
V_424 = ( ( clock * V_373 / 1000 ) * V_374 ) / 1000 ;
V_425 = V_419 * V_423 ;
V_420 = F_210 ( V_53 ( V_424 , V_425 ) , V_193 -> V_377 ) ;
* V_422 = V_420 + V_193 -> V_378 ;
V_420 = V_419 * V_373 * 64 ;
V_420 = F_210 ( V_420 , V_413 -> V_377 ) ;
* V_416 = V_420 + V_413 -> V_378 ;
return F_223 ( V_2 ,
* V_422 , * V_416 ,
V_193 , V_413 ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
static const int V_426 = 12000 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_427 , V_428 , V_429 , V_430 ;
int V_431 , V_402 ;
unsigned int V_76 = 0 ;
if ( F_221 ( V_2 , 0 ,
& V_432 , V_374 ,
& V_433 , V_374 ,
& V_427 , & V_429 ) )
V_76 |= 1 ;
if ( F_221 ( V_2 , 1 ,
& V_432 , V_374 ,
& V_433 , V_374 ,
& V_428 , & V_430 ) )
V_76 |= 2 ;
V_431 = V_402 = 0 ;
if ( F_226 ( V_76 ) &&
F_224 ( V_2 , F_227 ( V_76 ) - 1 ,
V_426 ,
& V_432 ,
& V_433 ,
& V_431 , & V_402 ) )
F_23 ( V_434 , V_435 ) ;
else
F_23 ( V_434 ,
F_3 ( V_434 ) & ~ V_435 ) ;
F_25 ( L_78 ,
V_427 , V_429 ,
V_428 , V_430 ,
V_431 , V_402 ) ;
F_23 ( V_398 ,
( V_431 << V_400 ) |
( V_430 << V_436 ) |
( V_428 << V_437 ) |
V_427 ) ;
F_23 ( V_438 ,
( F_3 ( V_438 ) & V_439 ) |
( V_429 << V_440 ) ) ;
F_23 ( V_390 ,
( F_3 ( V_390 ) & ~ V_441 ) |
( V_402 << V_404 ) ) ;
}
static void F_228 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
int V_442 = 1 ;
int V_402 = 16 ;
V_9 = F_218 ( V_2 ) ;
if ( V_9 ) {
static const int V_426 = 12000 ;
int clock = V_9 -> V_207 . clock ;
int V_417 = V_9 -> V_207 . V_417 ;
int V_212 = V_9 -> V_207 . V_212 ;
int V_373 = V_9 -> V_126 -> V_234 / 8 ;
unsigned long V_418 ;
int V_420 ;
V_418 = ( ( V_417 * 1000 ) / clock ) ;
V_420 = ( ( ( V_426 / V_418 ) + 1000 ) / 1000 ) *
V_373 * V_212 ;
V_420 = F_210 ( V_420 , V_443 ) ;
V_442 = V_444 - V_420 ;
if ( V_442 < 0 )
V_442 = 1 ;
V_442 &= 0x1ff ;
F_25 ( L_79 ,
V_420 , V_442 ) ;
V_420 = ( ( ( V_426 / V_418 ) + 1000 ) / 1000 ) *
V_373 * 64 ;
V_420 = F_210 ( V_420 ,
V_445 . V_377 ) ;
V_402 = V_445 . V_372 -
( V_420 + V_445 . V_378 ) ;
if ( V_402 > V_445 . V_379 )
V_402 = V_445 . V_379 ;
F_25 ( L_80
L_81 , V_442 , V_402 ) ;
if ( F_116 ( V_2 ) )
F_23 ( V_434 , V_435 ) ;
} else {
if ( F_116 ( V_2 ) )
F_23 ( V_434 , F_3 ( V_434 )
& ~ V_435 ) ;
}
F_25 ( L_82 ,
V_442 ) ;
F_23 ( V_398 , ( V_442 << V_400 ) |
( 8 << 16 ) | ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_23 ( V_438 , ( 8 << 8 ) | ( 8 << 0 ) ) ;
F_23 ( V_390 , ( V_402 << V_404 ) ) ;
}
static void F_229 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_370 * V_446 ;
T_5 V_447 ;
T_5 V_448 ;
int V_449 , V_442 = 1 ;
int V_372 ;
int V_427 , V_428 ;
struct V_8 * V_9 , * V_76 = NULL ;
if ( F_95 ( V_2 ) )
V_446 = & V_450 ;
else if ( ! F_11 ( V_2 ) )
V_446 = & V_451 ;
else
V_446 = & V_452 ;
V_372 = V_4 -> V_193 . V_453 ( V_2 , 0 ) ;
V_9 = F_222 ( V_2 , 0 ) ;
if ( V_9 -> V_76 && V_9 -> V_126 ) {
V_427 = F_209 ( V_9 -> V_207 . clock ,
V_446 , V_372 ,
V_9 -> V_126 -> V_234 / 8 ,
V_374 ) ;
V_76 = V_9 ;
} else
V_427 = V_372 - V_446 -> V_378 ;
V_372 = V_4 -> V_193 . V_453 ( V_2 , 1 ) ;
V_9 = F_222 ( V_2 , 1 ) ;
if ( V_9 -> V_76 && V_9 -> V_126 ) {
V_428 = F_209 ( V_9 -> V_207 . clock ,
V_446 , V_372 ,
V_9 -> V_126 -> V_234 / 8 ,
V_374 ) ;
if ( V_76 == NULL )
V_76 = V_9 ;
else
V_76 = NULL ;
} else
V_428 = V_372 - V_446 -> V_378 ;
F_25 ( L_83 , V_427 , V_428 ) ;
V_449 = 2 ;
if ( F_230 ( V_2 ) || F_95 ( V_2 ) )
F_23 ( V_434 , V_454 | 0 ) ;
else if ( F_112 ( V_2 ) )
F_23 ( V_455 , F_3 ( V_455 ) & ~ V_456 ) ;
if ( F_231 ( V_2 ) && V_76 ) {
static const int V_426 = 6000 ;
int clock = V_76 -> V_207 . clock ;
int V_417 = V_76 -> V_207 . V_417 ;
int V_212 = V_76 -> V_207 . V_212 ;
int V_373 = V_76 -> V_126 -> V_234 / 8 ;
unsigned long V_418 ;
int V_420 ;
V_418 = ( V_417 * 1000 ) / clock ;
V_420 = ( ( ( V_426 / V_418 ) + 1000 ) / 1000 ) *
V_373 * V_212 ;
V_420 = F_210 ( V_420 , V_446 -> V_377 ) ;
F_25 ( L_84 , V_420 ) ;
V_442 = V_446 -> V_372 - V_420 ;
if ( V_442 < 0 )
V_442 = 1 ;
if ( F_230 ( V_2 ) || F_95 ( V_2 ) )
F_23 ( V_434 ,
V_457 | ( V_442 & 0xff ) ) ;
else if ( F_112 ( V_2 ) )
F_23 ( V_434 , V_442 & 0x3f ) ;
}
F_25 ( L_85 ,
V_427 , V_428 , V_449 , V_442 ) ;
V_447 = ( ( V_428 & 0x3f ) << 16 ) | ( V_427 & 0x3f ) ;
V_448 = ( V_449 & 0x1f ) ;
V_447 = V_447 | ( 1 << 24 ) | ( 1 << 8 ) ;
V_448 = V_448 | ( 1 << 8 ) ;
F_23 ( V_458 , V_447 ) ;
F_23 ( V_459 , V_448 ) ;
if ( F_231 ( V_2 ) ) {
if ( V_76 ) {
if ( F_230 ( V_2 ) || F_95 ( V_2 ) )
F_23 ( V_434 ,
V_454 | V_435 ) ;
else if ( F_112 ( V_2 ) )
F_23 ( V_455 , F_3 ( V_455 ) | V_456 ) ;
F_25 ( L_86 ) ;
} else
F_25 ( L_87 ) ;
}
}
static void F_232 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
T_5 V_447 ;
int V_427 ;
V_9 = F_218 ( V_2 ) ;
if ( V_9 == NULL )
return;
V_427 = F_209 ( V_9 -> V_207 . clock , & V_460 ,
V_4 -> V_193 . V_453 ( V_2 , 0 ) ,
V_9 -> V_126 -> V_234 / 8 ,
V_374 ) ;
V_447 = F_3 ( V_458 ) & ~ 0xfff ;
V_447 |= ( 3 << 8 ) | V_427 ;
F_25 ( L_88 , V_427 ) ;
F_23 ( V_458 , V_447 ) ;
}
static bool F_233 ( struct V_1 * V_2 , int V_461 ,
int V_462 , int V_422 , int V_416 ,
const struct V_370 * V_193 ,
const struct V_370 * V_413 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_25 ( L_89
L_90 , V_461 , V_422 , V_462 , V_416 ) ;
if ( V_462 > V_463 ) {
F_25 ( L_91 ,
V_462 , V_463 , V_461 ) ;
F_23 ( V_464 ,
F_3 ( V_464 ) | V_465 ) ;
return false ;
}
if ( V_422 > V_193 -> V_379 ) {
F_25 ( L_92 ,
V_422 , V_466 , V_461 ) ;
return false ;
}
if ( V_416 > V_413 -> V_379 ) {
F_25 ( L_93 ,
V_416 , V_467 , V_461 ) ;
return false ;
}
if ( ! ( V_462 || V_422 || V_416 ) ) {
F_25 ( L_94 , V_461 , V_461 ) ;
return false ;
}
return true ;
}
static bool F_234 ( struct V_1 * V_2 , int V_461 , int V_97 ,
int V_374 ,
const struct V_370 * V_193 ,
const struct V_370 * V_413 ,
int * V_462 , int * V_422 , int * V_416 )
{
struct V_8 * V_9 ;
unsigned long V_418 ;
int V_212 , V_417 , V_373 , clock ;
int V_419 , V_423 ;
int V_424 , V_425 ;
int V_420 ;
if ( ! V_374 ) {
* V_462 = * V_422 = * V_416 = 0 ;
return false ;
}
V_9 = F_222 ( V_2 , V_97 ) ;
V_212 = V_9 -> V_207 . V_212 ;
V_417 = V_9 -> V_207 . V_417 ;
clock = V_9 -> V_207 . clock ;
V_373 = V_9 -> V_126 -> V_234 / 8 ;
V_418 = ( V_417 * 1000 ) / clock ;
V_419 = ( V_374 / V_418 + 1000 ) / 1000 ;
V_423 = V_212 * V_373 ;
V_424 = ( ( clock * V_373 / 1000 ) * V_374 ) / 1000 ;
V_425 = V_419 * V_423 ;
V_420 = F_210 ( V_53 ( V_424 , V_425 ) , V_193 -> V_377 ) ;
* V_422 = V_420 + V_193 -> V_378 ;
* V_462 = F_210 ( * V_422 * 64 , V_423 ) + 2 ;
V_420 = V_419 * V_373 * 64 ;
V_420 = F_210 ( V_420 , V_413 -> V_377 ) ;
* V_416 = V_420 + V_413 -> V_378 ;
return F_233 ( V_2 , V_461 ,
* V_462 , * V_422 , * V_416 ,
V_193 , V_413 ) ;
}
static void F_235 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_462 , V_415 , V_416 ;
unsigned int V_76 ;
V_76 = 0 ;
if ( F_221 ( V_2 , 0 ,
& V_468 ,
V_469 ,
& V_470 ,
V_471 ,
& V_415 , & V_416 ) ) {
F_23 ( V_472 ,
( V_415 << V_473 ) | V_416 ) ;
F_25 ( L_95
L_96 L_97 ,
V_415 , V_416 ) ;
V_76 |= 1 ;
}
if ( F_221 ( V_2 , 1 ,
& V_468 ,
V_469 ,
& V_470 ,
V_471 ,
& V_415 , & V_416 ) ) {
F_23 ( V_474 ,
( V_415 << V_473 ) | V_416 ) ;
F_25 ( L_98
L_99 ,
V_415 , V_416 ) ;
V_76 |= 2 ;
}
F_23 ( V_475 , 0 ) ;
F_23 ( V_476 , 0 ) ;
F_23 ( V_477 , 0 ) ;
if ( ! F_226 ( V_76 ) )
return;
V_76 = F_227 ( V_76 ) - 1 ;
if ( ! F_234 ( V_2 , 1 , V_76 ,
F_236 () * 500 ,
& V_478 ,
& V_479 ,
& V_462 , & V_415 , & V_416 ) )
return;
F_23 ( V_477 ,
V_480 |
( F_236 () << V_481 ) |
( V_462 << V_482 ) |
( V_415 << V_483 ) |
V_416 ) ;
if ( ! F_234 ( V_2 , 2 , V_76 ,
F_237 () * 500 ,
& V_478 ,
& V_479 ,
& V_462 , & V_415 , & V_416 ) )
return;
F_23 ( V_476 ,
V_484 |
( F_237 () << V_481 ) |
( V_462 << V_482 ) |
( V_415 << V_483 ) |
V_416 ) ;
}
static void F_238 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_386 = F_239 () * 100 ;
int V_462 , V_415 , V_416 ;
unsigned int V_76 ;
V_76 = 0 ;
if ( F_221 ( V_2 , 0 ,
& V_485 , V_386 ,
& V_486 , V_386 ,
& V_415 , & V_416 ) ) {
F_23 ( V_472 ,
( V_415 << V_473 ) | V_416 ) ;
F_25 ( L_95
L_96 L_97 ,
V_415 , V_416 ) ;
V_76 |= 1 ;
}
if ( F_221 ( V_2 , 1 ,
& V_485 , V_386 ,
& V_486 , V_386 ,
& V_415 , & V_416 ) ) {
F_23 ( V_474 ,
( V_415 << V_473 ) | V_416 ) ;
F_25 ( L_98
L_99 ,
V_415 , V_416 ) ;
V_76 |= 2 ;
}
F_23 ( V_475 , 0 ) ;
F_23 ( V_476 , 0 ) ;
F_23 ( V_477 , 0 ) ;
if ( ! F_226 ( V_76 ) )
return;
V_76 = F_227 ( V_76 ) - 1 ;
if ( ! F_234 ( V_2 , 1 , V_76 ,
F_240 () * 500 ,
& V_487 ,
& V_488 ,
& V_462 , & V_415 , & V_416 ) )
return;
F_23 ( V_477 ,
V_480 |
( F_240 () << V_481 ) |
( V_462 << V_482 ) |
( V_415 << V_483 ) |
V_416 ) ;
if ( ! F_234 ( V_2 , 2 , V_76 ,
F_241 () * 500 ,
& V_487 ,
& V_488 ,
& V_462 , & V_415 , & V_416 ) )
return;
F_23 ( V_476 ,
V_484 |
( F_241 () << V_481 ) |
( V_462 << V_482 ) |
( V_415 << V_483 ) |
V_416 ) ;
if ( ! F_234 ( V_2 , 3 , V_76 ,
F_242 () * 500 ,
& V_487 ,
& V_488 ,
& V_462 , & V_415 , & V_416 ) )
return;
F_23 ( V_475 ,
V_489 |
( F_242 () << V_481 ) |
( V_462 << V_482 ) |
( V_415 << V_483 ) |
V_416 ) ;
}
static void F_171 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_193 . V_490 )
V_4 -> V_193 . V_490 ( V_2 ) ;
}
static inline bool F_243 ( struct V_3 * V_4 )
{
return V_4 -> V_491 && V_492
&& ! ( V_4 -> V_115 & V_493 ) ;
}
static int F_244 ( struct V_8 * V_9 ,
struct V_340 * V_207 ,
struct V_340 * V_341 ,
int V_228 , int V_153 ,
struct V_125 * V_242 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
int V_97 = V_131 -> V_97 ;
int V_10 , V_494 = 0 ;
T_3 clock , V_495 ;
T_1 V_496 , V_497 = 0 , V_498 = 0 , V_232 , V_499 ;
bool V_500 , V_501 = false , V_502 = false , V_503 = false ;
bool V_504 = false , V_505 = false , V_506 = false , V_507 = false ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
const T_2 * V_11 ;
int V_221 ;
T_1 V_261 ;
T_1 V_508 = 0 ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_12 :
V_505 = true ;
break;
case V_30 :
case V_27 :
V_502 = true ;
if ( V_51 -> V_509 )
V_506 = true ;
break;
case V_510 :
V_503 = true ;
break;
case V_511 :
V_506 = true ;
break;
case V_28 :
V_504 = true ;
break;
case V_20 :
V_507 = true ;
break;
}
V_494 ++ ;
}
if ( V_505 && F_243 ( V_4 ) && V_494 < 2 ) {
V_10 = V_4 -> V_512 * 1000 ;
F_25 ( L_100 ,
V_10 / 1000 ) ;
} else if ( ! F_11 ( V_2 ) ) {
V_10 = 96000 ;
} else {
V_10 = 48000 ;
}
V_11 = F_7 ( V_9 , V_10 ) ;
V_500 = V_11 -> V_513 ( V_11 , V_9 , V_341 -> clock , V_10 , & clock ) ;
if ( ! V_500 ) {
F_76 ( L_101 ) ;
return - V_223 ;
}
F_176 ( V_9 , true ) ;
if ( V_505 && V_4 -> V_514 ) {
V_501 = V_11 -> V_513 ( V_11 , V_9 ,
V_4 -> V_515 ,
V_10 ,
& V_495 ) ;
if ( V_501 && ( clock . V_41 != V_495 . V_41 ) ) {
F_25 ( L_102
L_103 ) ;
V_501 = 0 ;
}
}
if ( V_502 && V_506 ) {
if ( V_341 -> clock >= 100000
&& V_341 -> clock < 140500 ) {
clock . V_42 = 2 ;
clock . V_43 = 10 ;
clock . V_45 = 3 ;
clock . V_47 = 16 ;
clock . V_40 = 8 ;
} else if ( V_341 -> clock >= 140500
&& V_341 -> clock <= 200000 ) {
clock . V_42 = 1 ;
clock . V_43 = 10 ;
clock . V_45 = 6 ;
clock . V_47 = 12 ;
clock . V_40 = 8 ;
}
}
if ( F_10 ( V_2 ) ) {
V_497 = ( 1 << clock . V_45 ) << 16 | clock . V_47 << 8 | clock . V_40 ;
if ( V_501 )
V_498 = ( 1 << V_495 . V_45 ) << 16 |
V_495 . V_47 << 8 | V_495 . V_40 ;
} else {
V_497 = clock . V_45 << 16 | clock . V_47 << 8 | clock . V_40 ;
if ( V_501 )
V_498 = V_495 . V_45 << 16 | V_495 . V_47 << 8 |
V_495 . V_40 ;
}
V_496 = V_516 ;
if ( ! F_11 ( V_2 ) ) {
if ( V_505 )
V_496 |= V_517 ;
else
V_496 |= V_518 ;
if ( V_502 ) {
int V_519 = F_245 ( V_341 ) ;
if ( V_519 > 1 ) {
if ( F_230 ( V_2 ) || F_95 ( V_2 ) || F_246 ( V_2 ) )
V_496 |= ( V_519 - 1 ) << V_520 ;
}
V_496 |= V_521 ;
}
if ( V_507 )
V_496 |= V_521 ;
if ( F_10 ( V_2 ) )
V_496 |= ( 1 << ( clock . V_42 - 1 ) ) << V_522 ;
else {
V_496 |= ( 1 << ( clock . V_42 - 1 ) ) << V_523 ;
if ( F_9 ( V_2 ) && V_501 )
V_496 |= ( 1 << ( V_495 . V_42 - 1 ) ) << V_524 ;
}
switch ( clock . V_43 ) {
case 5 :
V_496 |= V_525 ;
break;
case 7 :
V_496 |= V_526 ;
break;
case 10 :
V_496 |= V_527 ;
break;
case 14 :
V_496 |= V_528 ;
break;
}
if ( F_27 ( V_2 ) -> V_69 >= 4 )
V_496 |= ( 6 << V_529 ) ;
} else {
if ( V_505 ) {
V_496 |= ( 1 << ( clock . V_42 - 1 ) ) << V_523 ;
} else {
if ( clock . V_42 == 2 )
V_496 |= V_530 ;
else
V_496 |= ( clock . V_42 - 2 ) << V_523 ;
if ( clock . V_43 == 4 )
V_496 |= V_531 ;
}
}
if ( V_502 && V_506 )
V_496 |= V_532 ;
else if ( V_506 )
V_496 |= 3 ;
else if ( V_505 && F_243 ( V_4 ) && V_494 < 2 )
V_496 |= V_533 ;
else
V_496 |= V_534 ;
V_499 = F_3 ( F_28 ( V_66 ) ) ;
V_232 = V_535 ;
if ( V_66 == 0 )
V_232 &= ~ V_101 ;
else
V_232 |= V_536 ;
if ( V_66 == 0 && F_27 ( V_2 ) -> V_69 < 4 ) {
if ( V_207 -> clock >
V_4 -> V_193 . V_537 ( V_2 ) * 9 / 10 )
V_499 |= V_538 ;
else
V_499 &= ~ V_538 ;
}
V_496 |= V_80 ;
F_25 ( L_104 , V_66 == 0 ? 'A' : 'B' ) ;
F_247 ( V_207 ) ;
F_23 ( F_248 ( V_66 ) , V_497 ) ;
F_23 ( F_35 ( V_66 ) , V_496 & ~ V_80 ) ;
F_66 ( F_35 ( V_66 ) ) ;
F_67 ( 150 ) ;
if ( V_505 ) {
V_261 = F_3 ( V_24 ) ;
V_261 |= V_123 | V_539 ;
if ( V_66 == 1 ) {
V_261 |= V_94 ;
} else {
V_261 &= ~ V_94 ;
}
V_261 |= V_4 -> V_540 ;
if ( clock . V_43 == 7 )
V_261 |= V_541 | V_15 ;
else
V_261 &= ~ ( V_541 | V_15 ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
if ( V_4 -> V_542 )
V_261 |= V_543 ;
else
V_261 &= ~ V_543 ;
}
if ( V_341 -> V_208 & V_544 )
V_508 |= V_545 ;
if ( V_341 -> V_208 & V_546 )
V_508 |= V_547 ;
if ( ( V_261 & ( V_545 | V_547 ) )
!= V_508 ) {
char V_208 [ 2 ] = L_105 ;
F_249 ( L_106
L_107 ,
V_208 [ ! ( V_261 & V_545 ) ] ,
V_208 [ ! ( V_261 & V_547 ) ] ,
V_208 [ ! ( V_508 & V_545 ) ] ,
V_208 [ ! ( V_508 & V_547 ) ] ) ;
V_261 &= ~ ( V_545 | V_547 ) ;
V_261 |= V_508 ;
}
F_23 ( V_24 , V_261 ) ;
}
if ( V_507 ) {
F_250 ( V_9 , V_207 , V_341 ) ;
}
F_23 ( F_35 ( V_66 ) , V_496 ) ;
F_66 ( F_35 ( V_66 ) ) ;
F_67 ( 150 ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
V_261 = 0 ;
if ( V_502 ) {
V_261 = F_245 ( V_341 ) ;
if ( V_261 > 1 )
V_261 = ( V_261 - 1 ) << V_548 ;
else
V_261 = 0 ;
}
F_23 ( F_251 ( V_66 ) , V_261 ) ;
} else {
F_23 ( F_35 ( V_66 ) , V_496 ) ;
}
V_131 -> V_549 = false ;
if ( V_505 && V_501 && V_198 ) {
F_23 ( F_252 ( V_66 ) , V_498 ) ;
V_131 -> V_549 = true ;
if ( F_253 ( V_2 ) ) {
F_25 ( L_108 ) ;
V_499 |= V_550 ;
}
} else {
F_23 ( F_252 ( V_66 ) , V_497 ) ;
if ( F_253 ( V_2 ) ) {
F_25 ( L_109 ) ;
V_499 &= ~ V_550 ;
}
}
if ( V_341 -> V_208 & V_209 ) {
V_499 |= V_551 ;
V_341 -> V_552 -= 1 ;
V_341 -> V_553 -= 1 ;
V_341 -> V_554 -= 1 ;
V_341 -> V_555 -= 1 ;
V_341 -> V_556 -= 1 ;
V_341 -> V_557 -= 1 ;
} else
V_499 &= ~ V_551 ;
F_23 ( F_157 ( V_66 ) ,
( V_341 -> V_558 - 1 ) |
( ( V_341 -> V_343 - 1 ) << 16 ) ) ;
F_23 ( F_159 ( V_66 ) ,
( V_341 -> V_559 - 1 ) |
( ( V_341 -> V_560 - 1 ) << 16 ) ) ;
F_23 ( F_161 ( V_66 ) ,
( V_341 -> V_561 - 1 ) |
( ( V_341 -> V_562 - 1 ) << 16 ) ) ;
F_23 ( F_163 ( V_66 ) ,
( V_341 -> V_552 - 1 ) |
( ( V_341 -> V_553 - 1 ) << 16 ) ) ;
F_23 ( F_165 ( V_66 ) ,
( V_341 -> V_554 - 1 ) |
( ( V_341 -> V_555 - 1 ) << 16 ) ) ;
F_23 ( F_167 ( V_66 ) ,
( V_341 -> V_557 - 1 ) |
( ( V_341 -> V_556 - 1 ) << 16 ) ) ;
F_23 ( F_254 ( V_97 ) ,
( ( V_207 -> V_213 - 1 ) << 16 ) |
( V_207 -> V_212 - 1 ) ) ;
F_23 ( F_255 ( V_97 ) , 0 ) ;
F_23 ( F_256 ( V_66 ) ,
( ( V_207 -> V_212 - 1 ) << 16 ) | ( V_207 -> V_213 - 1 ) ) ;
F_23 ( F_28 ( V_66 ) , V_499 ) ;
F_66 ( F_28 ( V_66 ) ) ;
F_80 ( V_4 , V_66 , false ) ;
F_21 ( V_2 , V_66 ) ;
F_23 ( F_49 ( V_97 ) , V_232 ) ;
F_66 ( F_49 ( V_97 ) ) ;
F_83 ( V_4 , V_97 , V_66 ) ;
V_221 = F_127 ( V_9 , V_228 , V_153 , V_242 ) ;
F_171 ( V_2 ) ;
return V_221 ;
}
static int F_257 ( struct V_8 * V_9 ,
struct V_340 * V_207 ,
struct V_340 * V_341 ,
int V_228 , int V_153 ,
struct V_125 * V_242 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
int V_97 = V_131 -> V_97 ;
int V_10 , V_494 = 0 ;
T_3 clock , V_495 ;
T_1 V_496 , V_497 = 0 , V_498 = 0 , V_232 , V_499 ;
bool V_500 , V_501 = false , V_502 = false ;
bool V_504 = false , V_505 = false , V_506 = false , V_507 = false ;
struct V_50 * V_563 = NULL ;
struct V_48 * V_49 = & V_2 -> V_49 ;
struct V_50 * V_51 ;
const T_2 * V_11 ;
int V_221 ;
struct V_362 V_363 = { 0 } ;
T_1 V_261 ;
T_1 V_508 = 0 ;
int V_564 , V_519 , V_565 , V_566 , V_567 , V_568 ;
F_14 (encoder, &mode_config->encoder_list, base.head) {
if ( V_51 -> V_52 . V_9 != V_9 )
continue;
switch ( V_51 -> type ) {
case V_12 :
V_505 = true ;
break;
case V_30 :
case V_27 :
V_502 = true ;
if ( V_51 -> V_509 )
V_506 = true ;
break;
case V_511 :
V_506 = true ;
break;
case V_28 :
V_504 = true ;
break;
case V_20 :
V_507 = true ;
break;
case V_293 :
V_563 = V_51 ;
break;
}
V_494 ++ ;
}
if ( V_505 && F_243 ( V_4 ) && V_494 < 2 ) {
V_10 = V_4 -> V_512 * 1000 ;
F_25 ( L_100 ,
V_10 / 1000 ) ;
} else {
V_10 = 96000 ;
if ( ! V_563 ||
F_154 ( & V_563 -> V_52 ) )
V_10 = 120000 ;
}
V_11 = F_7 ( V_9 , V_10 ) ;
V_500 = V_11 -> V_513 ( V_11 , V_9 , V_341 -> clock , V_10 , & clock ) ;
if ( ! V_500 ) {
F_76 ( L_101 ) ;
return - V_223 ;
}
F_176 ( V_9 , true ) ;
if ( V_505 && V_4 -> V_514 ) {
V_501 = V_11 -> V_513 ( V_11 , V_9 ,
V_4 -> V_515 ,
V_10 ,
& V_495 ) ;
if ( V_501 && ( clock . V_41 != V_495 . V_41 ) ) {
F_25 ( L_102
L_103 ) ;
V_501 = 0 ;
}
}
if ( V_502 && V_506 ) {
if ( V_341 -> clock >= 100000
&& V_341 -> clock < 140500 ) {
clock . V_42 = 2 ;
clock . V_43 = 10 ;
clock . V_45 = 3 ;
clock . V_47 = 16 ;
clock . V_40 = 8 ;
} else if ( V_341 -> clock >= 140500
&& V_341 -> clock <= 200000 ) {
clock . V_42 = 1 ;
clock . V_43 = 10 ;
clock . V_45 = 6 ;
clock . V_47 = 12 ;
clock . V_40 = 8 ;
}
}
V_519 = F_245 ( V_341 ) ;
V_565 = 0 ;
if ( V_563 &&
! F_154 ( & V_563 -> V_52 ) ) {
V_564 = V_207 -> clock ;
F_258 ( V_563 ,
& V_565 , & V_566 ) ;
} else {
if ( V_507 || F_154 ( & V_563 -> V_52 ) )
V_564 = V_207 -> clock ;
else
V_564 = V_341 -> clock ;
V_566 = F_1 ( V_2 ) * F_259 ( 100 ) / F_260 ( 1 ) / 10 ;
}
V_261 = F_3 ( F_28 ( V_66 ) ) ;
V_261 &= ~ V_117 ;
if ( V_505 ) {
if ( ( F_3 ( V_13 ) & V_569 ) == V_570 )
V_261 |= V_571 ;
else
V_261 |= V_572 ;
} else if ( V_563 ) {
switch ( V_4 -> V_573 . V_567 / 3 ) {
case 8 :
V_261 |= V_571 ;
break;
case 10 :
V_261 |= V_574 ;
break;
case 6 :
V_261 |= V_572 ;
break;
case 12 :
V_261 |= V_575 ;
break;
}
} else
V_261 |= V_571 ;
F_23 ( F_28 ( V_66 ) , V_261 ) ;
switch ( V_261 & V_117 ) {
case V_571 :
V_567 = 24 ;
break;
case V_574 :
V_567 = 30 ;
break;
case V_572 :
V_567 = 18 ;
break;
case V_575 :
V_567 = 36 ;
break;
default:
F_76 ( L_110 ) ;
V_567 = 24 ;
}
if ( ! V_565 ) {
T_1 V_576 = V_564 * V_567 * 21 / 20 ;
V_565 = V_576 / ( V_566 * 8 ) + 1 ;
}
V_131 -> V_275 = V_565 ;
if ( V_519 > 1 )
V_566 *= V_519 ;
F_208 ( V_567 , V_565 , V_564 , V_566 , & V_363 ) ;
V_261 = F_3 ( V_103 ) ;
V_261 &= ~ V_105 ;
V_261 |= V_577 ;
V_261 &= ~ V_104 ;
V_261 |= V_578 ;
F_23 ( V_103 , V_261 ) ;
F_66 ( V_103 ) ;
F_67 ( 200 ) ;
if ( V_563 ) {
if ( F_243 ( V_4 ) ) {
V_261 |= V_579 ;
F_23 ( V_103 , V_261 ) ;
F_66 ( V_103 ) ;
F_67 ( 200 ) ;
}
V_261 &= ~ V_580 ;
if ( ! F_154 ( & V_563 -> V_52 ) ) {
if ( F_243 ( V_4 ) )
V_261 |= V_581 ;
else
V_261 |= V_582 ;
} else {
if ( F_243 ( V_4 ) ) {
F_76 ( L_111 ) ;
V_261 |= V_583 ;
}
}
F_23 ( V_103 , V_261 ) ;
F_66 ( V_103 ) ;
F_67 ( 200 ) ;
}
V_497 = clock . V_45 << 16 | clock . V_47 << 8 | clock . V_40 ;
if ( V_501 )
V_498 = V_495 . V_45 << 16 | V_495 . V_47 << 8 |
V_495 . V_40 ;
V_568 = 21 ;
if ( V_505 ) {
if ( ( F_243 ( V_4 ) &&
V_4 -> V_512 == 100 ) ||
( F_3 ( V_13 ) & V_14 ) == V_15 )
V_568 = 25 ;
} else if ( V_502 && V_506 )
V_568 = 20 ;
if ( clock . V_47 < V_568 * clock . V_45 )
V_497 |= V_584 ;
V_496 = 0 ;
if ( V_505 )
V_496 |= V_517 ;
else
V_496 |= V_518 ;
if ( V_502 ) {
int V_519 = F_245 ( V_341 ) ;
if ( V_519 > 1 ) {
V_496 |= ( V_519 - 1 ) << V_585 ;
}
V_496 |= V_521 ;
}
if ( V_507 || F_154 ( & V_563 -> V_52 ) )
V_496 |= V_521 ;
V_496 |= ( 1 << ( clock . V_42 - 1 ) ) << V_523 ;
V_496 |= ( 1 << ( clock . V_42 - 1 ) ) << V_524 ;
switch ( clock . V_43 ) {
case 5 :
V_496 |= V_525 ;
break;
case 7 :
V_496 |= V_526 ;
break;
case 10 :
V_496 |= V_527 ;
break;
case 14 :
V_496 |= V_528 ;
break;
}
if ( V_502 && V_506 )
V_496 |= V_532 ;
else if ( V_506 )
V_496 |= 3 ;
else if ( V_505 && F_243 ( V_4 ) && V_494 < 2 )
V_496 |= V_533 ;
else
V_496 |= V_534 ;
V_499 = F_3 ( F_28 ( V_66 ) ) ;
V_232 = V_535 ;
F_25 ( L_104 , V_66 == 0 ? 'A' : 'B' ) ;
F_247 ( V_207 ) ;
if ( ! V_563 || F_154 ( & V_563 -> V_52 ) ) {
F_23 ( F_261 ( V_66 ) , V_497 ) ;
F_23 ( F_38 ( V_66 ) , V_496 & ~ V_80 ) ;
F_66 ( F_38 ( V_66 ) ) ;
F_67 ( 150 ) ;
}
if ( F_136 ( V_2 ) ) {
V_261 = F_3 ( V_295 ) ;
switch ( V_66 ) {
case 0 :
V_261 |= V_296 | V_297 ;
break;
case 1 :
V_261 |= V_298 | V_299 ;
break;
case 2 :
V_261 |= V_320 | V_321 ;
break;
default:
F_117 () ;
}
F_23 ( V_295 , V_261 ) ;
F_66 ( V_295 ) ;
F_67 ( 150 ) ;
}
if ( V_505 ) {
V_261 = F_3 ( V_13 ) ;
V_261 |= V_123 | V_539 ;
if ( V_66 == 1 ) {
if ( F_136 ( V_2 ) )
V_261 |= V_586 ;
else
V_261 |= V_94 ;
} else {
if ( F_136 ( V_2 ) )
V_261 &= ~ V_587 ;
else
V_261 &= ~ V_94 ;
}
V_261 |= V_4 -> V_540 ;
if ( clock . V_43 == 7 )
V_261 |= V_541 | V_15 ;
else
V_261 &= ~ ( V_541 | V_15 ) ;
if ( V_341 -> V_208 & V_544 )
V_508 |= V_545 ;
if ( V_341 -> V_208 & V_546 )
V_508 |= V_547 ;
if ( ( V_261 & ( V_545 | V_547 ) )
!= V_508 ) {
char V_208 [ 2 ] = L_105 ;
F_249 ( L_106
L_107 ,
V_208 [ ! ( V_261 & V_545 ) ] ,
V_208 [ ! ( V_261 & V_547 ) ] ,
V_208 [ ! ( V_508 & V_545 ) ] ,
V_208 [ ! ( V_508 & V_547 ) ] ) ;
V_261 &= ~ ( V_545 | V_547 ) ;
V_261 |= V_508 ;
}
F_23 ( V_13 , V_261 ) ;
}
V_499 &= ~ V_588 ;
V_499 &= ~ V_589 ;
if ( V_4 -> V_542 && ( V_505 || V_563 ) ) {
V_499 |= V_588 ;
V_499 |= V_590 ;
}
if ( V_507 || F_154 ( & V_563 -> V_52 ) ) {
F_250 ( V_9 , V_207 , V_341 ) ;
} else {
F_23 ( F_262 ( V_66 ) , 0 ) ;
F_23 ( F_263 ( V_66 ) , 0 ) ;
F_23 ( F_264 ( V_66 ) , 0 ) ;
F_23 ( F_265 ( V_66 ) , 0 ) ;
}
if ( ! V_563 ||
F_154 ( & V_563 -> V_52 ) ) {
F_23 ( F_38 ( V_66 ) , V_496 ) ;
F_66 ( F_38 ( V_66 ) ) ;
F_67 ( 150 ) ;
F_23 ( F_38 ( V_66 ) , V_496 ) ;
}
V_131 -> V_549 = false ;
if ( V_505 && V_501 && V_198 ) {
F_23 ( F_266 ( V_66 ) , V_498 ) ;
V_131 -> V_549 = true ;
if ( F_253 ( V_2 ) ) {
F_25 ( L_108 ) ;
V_499 |= V_550 ;
}
} else {
F_23 ( F_266 ( V_66 ) , V_497 ) ;
if ( F_253 ( V_2 ) ) {
F_25 ( L_109 ) ;
V_499 &= ~ V_550 ;
}
}
if ( V_341 -> V_208 & V_209 ) {
V_499 |= V_551 ;
V_341 -> V_552 -= 1 ;
V_341 -> V_553 -= 1 ;
V_341 -> V_554 -= 1 ;
V_341 -> V_555 -= 1 ;
V_341 -> V_556 -= 1 ;
V_341 -> V_557 -= 1 ;
} else
V_499 &= ~ V_551 ;
F_23 ( F_157 ( V_66 ) ,
( V_341 -> V_558 - 1 ) |
( ( V_341 -> V_343 - 1 ) << 16 ) ) ;
F_23 ( F_159 ( V_66 ) ,
( V_341 -> V_559 - 1 ) |
( ( V_341 -> V_560 - 1 ) << 16 ) ) ;
F_23 ( F_161 ( V_66 ) ,
( V_341 -> V_561 - 1 ) |
( ( V_341 -> V_562 - 1 ) << 16 ) ) ;
F_23 ( F_163 ( V_66 ) ,
( V_341 -> V_552 - 1 ) |
( ( V_341 -> V_553 - 1 ) << 16 ) ) ;
F_23 ( F_165 ( V_66 ) ,
( V_341 -> V_554 - 1 ) |
( ( V_341 -> V_555 - 1 ) << 16 ) ) ;
F_23 ( F_167 ( V_66 ) ,
( V_341 -> V_557 - 1 ) |
( ( V_341 -> V_556 - 1 ) << 16 ) ) ;
F_23 ( F_256 ( V_66 ) ,
( ( V_207 -> V_212 - 1 ) << 16 ) | ( V_207 -> V_213 - 1 ) ) ;
F_23 ( F_146 ( V_66 ) , F_267 ( V_363 . V_364 ) | V_363 . V_365 ) ;
F_23 ( F_268 ( V_66 ) , V_363 . V_366 ) ;
F_23 ( F_269 ( V_66 ) , V_363 . V_367 ) ;
F_23 ( F_270 ( V_66 ) , V_363 . V_368 ) ;
if ( V_563 &&
! F_154 ( & V_563 -> V_52 ) ) {
F_133 ( V_9 , V_341 -> clock ) ;
}
F_23 ( F_28 ( V_66 ) , V_499 ) ;
F_66 ( F_28 ( V_66 ) ) ;
F_21 ( V_2 , V_66 ) ;
if ( F_2 ( V_2 ) ) {
V_261 = F_3 ( V_464 ) ;
F_23 ( V_464 , V_261 | V_591 ) ;
}
F_23 ( F_49 ( V_97 ) , V_232 ) ;
F_66 ( F_49 ( V_97 ) ) ;
V_221 = F_127 ( V_9 , V_228 , V_153 , V_242 ) ;
F_171 ( V_2 ) ;
return V_221 ;
}
static int F_271 ( struct V_8 * V_9 ,
struct V_340 * V_207 ,
struct V_340 * V_341 ,
int V_228 , int V_153 ,
struct V_125 * V_242 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
int V_221 ;
F_272 ( V_2 , V_66 ) ;
V_221 = V_4 -> V_193 . V_592 ( V_9 , V_207 , V_341 ,
V_228 , V_153 , V_242 ) ;
F_273 ( V_2 , V_66 ) ;
return V_221 ;
}
void F_175 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_593 = F_274 ( V_131 -> V_66 ) ;
int V_99 ;
if ( ! V_9 -> V_76 )
return;
if ( F_8 ( V_2 ) )
V_593 = F_275 ( V_131 -> V_66 ) ;
for ( V_99 = 0 ; V_99 < 256 ; V_99 ++ ) {
F_23 ( V_593 + 4 * V_99 ,
( V_131 -> V_594 [ V_99 ] << 16 ) |
( V_131 -> V_595 [ V_99 ] << 8 ) |
V_131 -> V_596 [ V_99 ] ) ;
}
}
static void F_276 ( struct V_8 * V_9 , T_1 V_52 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
bool V_597 = V_52 != 0 ;
T_1 V_598 ;
if ( V_131 -> V_599 == V_597 )
return;
V_598 = F_3 ( V_600 ) ;
if ( V_597 ) {
F_23 ( V_601 , V_52 ) ;
V_598 &= ~ ( V_602 ) ;
V_598 |= V_603 |
V_604 |
V_605 ;
} else
V_598 &= ~ ( V_603 | V_604 ) ;
F_23 ( V_600 , V_598 ) ;
V_131 -> V_599 = V_597 ;
}
static void F_277 ( struct V_8 * V_9 , T_1 V_52 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
bool V_597 = V_52 != 0 ;
if ( V_131 -> V_599 != V_597 ) {
T_5 V_598 = F_3 ( F_278 ( V_66 ) ) ;
if ( V_52 ) {
V_598 &= ~ ( V_606 | V_607 ) ;
V_598 |= V_608 | V_609 ;
V_598 |= V_66 << 28 ;
} else {
V_598 &= ~ ( V_606 | V_609 ) ;
V_598 |= V_610 ;
}
F_23 ( F_278 ( V_66 ) , V_598 ) ;
V_131 -> V_599 = V_597 ;
}
F_23 ( F_279 ( V_66 ) , V_52 ) ;
}
static void F_176 ( struct V_8 * V_9 ,
bool V_611 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
int V_228 = V_131 -> V_612 ;
int V_153 = V_131 -> V_613 ;
T_1 V_52 , V_614 ;
bool V_597 ;
V_614 = 0 ;
if ( V_611 && V_9 -> V_76 && V_9 -> V_126 ) {
V_52 = V_131 -> V_615 ;
if ( V_228 > ( int ) V_9 -> V_126 -> V_616 )
V_52 = 0 ;
if ( V_153 > ( int ) V_9 -> V_126 -> V_617 )
V_52 = 0 ;
} else
V_52 = 0 ;
if ( V_228 < 0 ) {
if ( V_228 + V_131 -> V_618 < 0 )
V_52 = 0 ;
V_614 |= V_619 << V_620 ;
V_228 = - V_228 ;
}
V_614 |= V_228 << V_620 ;
if ( V_153 < 0 ) {
if ( V_153 + V_131 -> V_621 < 0 )
V_52 = 0 ;
V_614 |= V_619 << V_622 ;
V_153 = - V_153 ;
}
V_614 |= V_153 << V_622 ;
V_597 = V_52 != 0 ;
if ( ! V_597 && ! V_131 -> V_599 )
return;
F_23 ( F_280 ( V_66 ) , V_614 ) ;
if ( F_281 ( V_2 ) || F_282 ( V_2 ) )
F_276 ( V_9 , V_52 ) ;
else
F_277 ( V_9 , V_52 ) ;
if ( V_597 )
F_283 ( V_2 , F_92 ( V_9 -> V_126 ) -> V_130 ) ;
}
static int F_284 ( struct V_8 * V_9 ,
struct V_623 * V_624 ,
T_5 V_625 ,
T_5 V_616 , T_5 V_617 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
struct V_129 * V_130 ;
T_5 V_626 ;
int V_221 ;
F_25 ( L_35 ) ;
if ( ! V_625 ) {
F_25 ( L_112 ) ;
V_626 = 0 ;
V_130 = NULL ;
F_128 ( & V_2 -> V_245 ) ;
goto V_627;
}
if ( V_616 != 64 || V_617 != 64 ) {
F_76 ( L_113 ) ;
return - V_223 ;
}
V_130 = F_285 ( F_286 ( V_2 , V_624 , V_625 ) ) ;
if ( & V_130 -> V_52 == NULL )
return - V_628 ;
if ( V_130 -> V_52 . V_205 < V_616 * V_617 * 4 ) {
F_76 ( L_114 ) ;
V_221 = - V_629 ;
goto V_630;
}
F_128 ( & V_2 -> V_245 ) ;
if ( ! V_4 -> V_83 -> V_631 ) {
if ( V_130 -> V_148 ) {
F_76 ( L_115 ) ;
V_221 = - V_223 ;
goto V_632;
}
V_221 = F_118 ( V_130 , V_633 , true ) ;
if ( V_221 ) {
F_76 ( L_116 ) ;
goto V_632;
}
V_221 = F_287 ( V_130 , 0 ) ;
if ( V_221 ) {
F_76 ( L_117 ) ;
goto V_634;
}
V_221 = F_288 ( V_130 ) ;
if ( V_221 ) {
F_76 ( L_117 ) ;
goto V_634;
}
V_626 = V_130 -> V_183 ;
} else {
int V_635 = F_65 ( V_2 ) ? 16 * 1024 : 256 ;
V_221 = F_289 ( V_2 , V_130 ,
( V_131 -> V_66 == 0 ) ? V_636 : V_637 ,
V_635 ) ;
if ( V_221 ) {
F_76 ( L_118 ) ;
goto V_632;
}
V_626 = V_130 -> V_638 -> V_625 -> V_639 ;
}
if ( F_11 ( V_2 ) )
F_23 ( V_640 , ( V_617 << 12 ) | V_616 ) ;
V_627:
if ( V_131 -> V_641 ) {
if ( V_4 -> V_83 -> V_631 ) {
if ( V_131 -> V_641 != V_130 )
F_290 ( V_2 , V_131 -> V_641 ) ;
} else
F_121 ( V_131 -> V_641 ) ;
F_291 ( & V_131 -> V_641 -> V_52 ) ;
}
F_129 ( & V_2 -> V_245 ) ;
V_131 -> V_615 = V_626 ;
V_131 -> V_641 = V_130 ;
V_131 -> V_618 = V_616 ;
V_131 -> V_621 = V_617 ;
F_176 ( V_9 , true ) ;
return 0 ;
V_634:
F_121 ( V_130 ) ;
V_632:
F_129 ( & V_2 -> V_245 ) ;
V_630:
F_292 ( & V_130 -> V_52 ) ;
return V_221 ;
}
static int F_293 ( struct V_8 * V_9 , int V_228 , int V_153 )
{
struct V_131 * V_131 = F_93 ( V_9 ) ;
V_131 -> V_612 = V_228 ;
V_131 -> V_613 = V_153 ;
F_176 ( V_9 , true ) ;
return 0 ;
}
void F_294 ( struct V_8 * V_9 , T_4 V_642 , T_4 V_643 ,
T_4 V_644 , int V_645 )
{
struct V_131 * V_131 = F_93 ( V_9 ) ;
V_131 -> V_594 [ V_645 ] = V_642 >> 8 ;
V_131 -> V_595 [ V_645 ] = V_643 >> 8 ;
V_131 -> V_596 [ V_645 ] = V_644 >> 8 ;
}
void F_295 ( struct V_8 * V_9 , T_4 * V_642 , T_4 * V_643 ,
T_4 * V_644 , int V_645 )
{
struct V_131 * V_131 = F_93 ( V_9 ) ;
* V_642 = V_131 -> V_594 [ V_645 ] << 8 ;
* V_643 = V_131 -> V_595 [ V_645 ] << 8 ;
* V_644 = V_131 -> V_596 [ V_645 ] << 8 ;
}
static void F_296 ( struct V_8 * V_9 , T_4 * V_642 , T_4 * V_643 ,
T_4 * V_644 , T_5 V_646 , T_5 V_205 )
{
int V_647 = ( V_646 + V_205 > 256 ) ? 256 : V_646 + V_205 , V_99 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
for ( V_99 = V_646 ; V_99 < V_647 ; V_99 ++ ) {
V_131 -> V_594 [ V_99 ] = V_642 [ V_99 ] >> 8 ;
V_131 -> V_595 [ V_99 ] = V_643 [ V_99 ] >> 8 ;
V_131 -> V_596 [ V_99 ] = V_644 [ V_99 ] >> 8 ;
}
F_175 ( V_9 ) ;
}
static struct V_125 *
F_297 ( struct V_1 * V_2 ,
struct V_648 * V_649 ,
struct V_129 * V_130 )
{
struct V_127 * V_128 ;
int V_221 ;
V_128 = F_298 ( sizeof( * V_128 ) , V_650 ) ;
if ( ! V_128 ) {
F_292 ( & V_130 -> V_52 ) ;
return F_299 ( - V_629 ) ;
}
V_221 = F_300 ( V_2 , V_128 , V_649 , V_130 ) ;
if ( V_221 ) {
F_292 ( & V_130 -> V_52 ) ;
F_196 ( V_128 ) ;
return F_299 ( V_221 ) ;
}
return & V_128 -> V_52 ;
}
static T_1
F_301 ( int V_616 , int V_567 )
{
T_1 V_134 = F_210 ( V_616 * V_567 , 8 ) ;
return F_302 ( V_134 , 64 ) ;
}
static T_1
F_303 ( struct V_340 * V_207 , int V_567 )
{
T_1 V_134 = F_301 ( V_207 -> V_212 , V_567 ) ;
return F_302 ( V_134 * V_207 -> V_213 , V_633 ) ;
}
static struct V_125 *
F_304 ( struct V_1 * V_2 ,
struct V_340 * V_207 ,
int V_236 , int V_567 )
{
struct V_129 * V_130 ;
struct V_648 V_649 ;
V_130 = F_305 ( V_2 ,
F_303 ( V_207 , V_567 ) ) ;
if ( V_130 == NULL )
return F_299 ( - V_629 ) ;
V_649 . V_616 = V_207 -> V_212 ;
V_649 . V_617 = V_207 -> V_213 ;
V_649 . V_236 = V_236 ;
V_649 . V_567 = V_567 ;
V_649 . V_134 = F_301 ( V_649 . V_616 , V_567 ) ;
return F_297 ( V_2 , & V_649 , V_130 ) ;
}
static struct V_125 *
F_306 ( struct V_1 * V_2 ,
struct V_340 * V_207 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_129 * V_130 ;
struct V_125 * V_126 ;
if ( V_4 -> V_651 == NULL )
return NULL ;
V_130 = V_4 -> V_651 -> V_652 . V_130 ;
if ( V_130 == NULL )
return NULL ;
V_126 = & V_4 -> V_651 -> V_652 . V_52 ;
if ( V_126 -> V_134 < F_301 ( V_207 -> V_212 ,
V_126 -> V_234 ) )
return NULL ;
if ( V_130 -> V_52 . V_205 < V_207 -> V_213 * V_126 -> V_134 )
return NULL ;
return V_126 ;
}
bool F_307 ( struct V_50 * V_50 ,
struct V_653 * V_654 ,
struct V_340 * V_207 ,
struct V_655 * V_656 )
{
struct V_131 * V_131 ;
struct V_8 * V_657 ;
struct V_337 * V_51 = & V_50 -> V_52 ;
struct V_8 * V_9 = NULL ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_125 * V_242 ;
int V_99 = - 1 ;
F_25 ( L_119 ,
V_654 -> V_52 . V_658 , F_308 ( V_654 ) ,
V_51 -> V_52 . V_658 , F_309 ( V_51 ) ) ;
if ( V_51 -> V_9 ) {
V_9 = V_51 -> V_9 ;
V_131 = F_93 ( V_9 ) ;
V_656 -> V_328 = V_131 -> V_328 ;
V_656 -> V_659 = false ;
if ( V_131 -> V_328 != V_322 ) {
struct V_338 * V_339 ;
struct V_334 * V_335 ;
V_335 = V_9 -> V_336 ;
V_335 -> V_329 ( V_9 , V_322 ) ;
V_339 = V_51 -> V_336 ;
V_339 -> V_329 ( V_51 , V_322 ) ;
}
return true ;
}
F_14 (possible_crtc, &dev->mode_config.crtc_list, head) {
V_99 ++ ;
if ( ! ( V_51 -> V_660 & ( 1 << V_99 ) ) )
continue;
if ( ! V_657 -> V_76 ) {
V_9 = V_657 ;
break;
}
}
if ( ! V_9 ) {
F_25 ( L_120 ) ;
return false ;
}
V_51 -> V_9 = V_9 ;
V_654 -> V_51 = V_51 ;
V_131 = F_93 ( V_9 ) ;
V_656 -> V_328 = V_131 -> V_328 ;
V_656 -> V_659 = true ;
V_656 -> V_661 = NULL ;
if ( ! V_207 )
V_207 = & V_662 ;
V_242 = V_9 -> V_126 ;
V_9 -> V_126 = F_306 ( V_2 , V_207 ) ;
if ( V_9 -> V_126 == NULL ) {
F_25 ( L_121 ) ;
V_9 -> V_126 = F_304 ( V_2 , V_207 , 24 , 32 ) ;
V_656 -> V_661 = V_9 -> V_126 ;
} else
F_25 ( L_122 ) ;
if ( F_310 ( V_9 -> V_126 ) ) {
F_25 ( L_123 ) ;
V_9 -> V_126 = V_242 ;
return false ;
}
if ( ! F_311 ( V_9 , V_207 , 0 , 0 , V_242 ) ) {
F_25 ( L_124 ) ;
if ( V_656 -> V_661 )
V_656 -> V_661 -> V_663 -> V_664 ( V_656 -> V_661 ) ;
V_9 -> V_126 = V_242 ;
return false ;
}
F_21 ( V_2 , V_131 -> V_66 ) ;
return true ;
}
void F_312 ( struct V_50 * V_50 ,
struct V_653 * V_654 ,
struct V_655 * V_656 )
{
struct V_337 * V_51 = & V_50 -> V_52 ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_8 * V_9 = V_51 -> V_9 ;
struct V_338 * V_339 = V_51 -> V_336 ;
struct V_334 * V_335 = V_9 -> V_336 ;
F_25 ( L_119 ,
V_654 -> V_52 . V_658 , F_308 ( V_654 ) ,
V_51 -> V_52 . V_658 , F_309 ( V_51 ) ) ;
if ( V_656 -> V_659 ) {
V_654 -> V_51 = NULL ;
F_313 ( V_2 ) ;
if ( V_656 -> V_661 )
V_656 -> V_661 -> V_663 -> V_664 ( V_656 -> V_661 ) ;
return;
}
if ( V_656 -> V_328 != V_322 ) {
V_339 -> V_329 ( V_51 , V_656 -> V_328 ) ;
V_335 -> V_329 ( V_9 , V_656 -> V_328 ) ;
}
}
static int F_314 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
T_1 V_496 = F_3 ( F_35 ( V_66 ) ) ;
T_1 V_497 ;
T_3 clock ;
if ( ( V_496 & V_665 ) == 0 )
V_497 = F_3 ( F_248 ( V_66 ) ) ;
else
V_497 = F_3 ( F_252 ( V_66 ) ) ;
clock . V_47 = ( V_497 & V_666 ) >> V_667 ;
if ( F_10 ( V_2 ) ) {
clock . V_45 = F_227 ( ( V_497 & V_668 ) >> V_669 ) - 1 ;
clock . V_40 = ( V_497 & V_670 ) >> V_671 ;
} else {
clock . V_45 = ( V_497 & V_672 ) >> V_669 ;
clock . V_40 = ( V_497 & V_673 ) >> V_671 ;
}
if ( ! F_11 ( V_2 ) ) {
if ( F_10 ( V_2 ) )
clock . V_42 = F_227 ( ( V_496 & V_674 ) >>
V_522 ) ;
else
clock . V_42 = F_227 ( ( V_496 & V_675 ) >>
V_523 ) ;
switch ( V_496 & V_676 ) {
case V_518 :
clock . V_43 = V_496 & V_525 ?
5 : 10 ;
break;
case V_517 :
clock . V_43 = V_496 & V_526 ?
7 : 14 ;
break;
default:
F_25 ( L_125
L_126 , ( int ) ( V_496 & V_676 ) ) ;
return 0 ;
}
F_13 ( V_2 , 96000 , & clock ) ;
} else {
bool V_505 = ( V_66 == 1 ) && ( F_3 ( V_24 ) & V_123 ) ;
if ( V_505 ) {
clock . V_42 = F_227 ( ( V_496 & V_677 ) >>
V_523 ) ;
clock . V_43 = 14 ;
if ( ( V_496 & V_678 ) ==
V_533 ) {
F_13 ( V_2 , 66000 , & clock ) ;
} else
F_13 ( V_2 , 48000 , & clock ) ;
} else {
if ( V_496 & V_530 )
clock . V_42 = 2 ;
else {
clock . V_42 = ( ( V_496 & V_679 ) >>
V_523 ) + 2 ;
}
if ( V_496 & V_531 )
clock . V_43 = 4 ;
else
clock . V_43 = 2 ;
F_13 ( V_2 , 48000 , & clock ) ;
}
}
return clock . V_46 ;
}
struct V_340 * F_315 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
struct V_340 * V_207 ;
int V_680 = F_3 ( F_157 ( V_66 ) ) ;
int V_681 = F_3 ( F_161 ( V_66 ) ) ;
int V_682 = F_3 ( F_163 ( V_66 ) ) ;
int V_683 = F_3 ( F_167 ( V_66 ) ) ;
V_207 = F_298 ( sizeof( * V_207 ) , V_650 ) ;
if ( ! V_207 )
return NULL ;
V_207 -> clock = F_314 ( V_2 , V_9 ) ;
V_207 -> V_212 = ( V_680 & 0xffff ) + 1 ;
V_207 -> V_417 = ( ( V_680 & 0xffff0000 ) >> 16 ) + 1 ;
V_207 -> V_684 = ( V_681 & 0xffff ) + 1 ;
V_207 -> V_685 = ( ( V_681 & 0xffff0000 ) >> 16 ) + 1 ;
V_207 -> V_213 = ( V_682 & 0xffff ) + 1 ;
V_207 -> V_686 = ( ( V_682 & 0xffff0000 ) >> 16 ) + 1 ;
V_207 -> V_687 = ( V_683 & 0xffff ) + 1 ;
V_207 -> V_688 = ( ( V_683 & 0xffff0000 ) >> 16 ) + 1 ;
F_316 ( V_207 ) ;
F_198 ( V_207 , 0 ) ;
return V_207 ;
}
static void F_317 ( unsigned long V_689 )
{
struct V_1 * V_2 = (struct V_1 * ) V_689 ;
T_6 * V_4 = V_2 -> V_5 ;
if ( ! F_318 ( & V_4 -> V_224 . V_690 ) ) {
F_319 ( & V_4 -> V_691 , V_74 +
F_30 ( V_692 ) ) ;
return;
}
V_4 -> V_693 = false ;
F_320 ( V_4 -> V_694 , & V_4 -> V_695 ) ;
}
static void F_321 ( unsigned long V_689 )
{
struct V_131 * V_131 = (struct V_131 * ) V_689 ;
struct V_8 * V_9 = & V_131 -> V_52 ;
T_6 * V_4 = V_9 -> V_2 -> V_5 ;
struct V_127 * V_128 ;
V_128 = F_92 ( V_9 -> V_126 ) ;
if ( V_128 && V_128 -> V_130 -> V_314 ) {
F_319 ( & V_131 -> V_691 , V_74 +
F_30 ( V_696 ) ) ;
return;
}
V_131 -> V_693 = false ;
F_320 ( V_4 -> V_694 , & V_4 -> V_695 ) ;
}
static void F_126 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_6 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
int V_697 = F_35 ( V_66 ) ;
int V_496 ;
if ( F_8 ( V_2 ) )
return;
if ( ! V_4 -> V_514 )
return;
V_496 = F_3 ( V_697 ) ;
if ( ! F_253 ( V_2 ) && ( V_496 & V_665 ) ) {
F_322 ( L_127 ) ;
F_23 ( V_91 ,
F_3 ( V_91 ) | V_93 ) ;
V_496 &= ~ V_665 ;
F_23 ( V_697 , V_496 ) ;
F_21 ( V_2 , V_66 ) ;
V_496 = F_3 ( V_697 ) ;
if ( V_496 & V_665 )
F_322 ( L_128 ) ;
F_23 ( V_91 , F_3 ( V_91 ) & 0x3 ) ;
}
F_319 ( & V_131 -> V_691 , V_74 +
F_30 ( V_696 ) ) ;
}
static void F_323 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_6 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
int V_66 = V_131 -> V_66 ;
int V_697 = F_35 ( V_66 ) ;
int V_496 = F_3 ( V_697 ) ;
if ( F_8 ( V_2 ) )
return;
if ( ! V_4 -> V_514 )
return;
if ( ! F_253 ( V_2 ) && V_131 -> V_549 ) {
F_322 ( L_129 ) ;
F_23 ( V_91 , F_3 ( V_91 ) |
V_93 ) ;
V_496 |= V_665 ;
F_23 ( V_697 , V_496 ) ;
F_21 ( V_2 , V_66 ) ;
V_496 = F_3 ( V_697 ) ;
if ( ! ( V_496 & V_665 ) )
F_322 ( L_130 ) ;
F_23 ( V_91 , F_3 ( V_91 ) & 0x3 ) ;
}
}
static void F_324 ( struct V_698 * V_699 )
{
T_6 * V_4 = F_325 ( V_699 , T_6 ,
V_695 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_8 * V_9 ;
struct V_131 * V_131 ;
if ( ! V_198 )
return;
F_128 ( & V_2 -> V_245 ) ;
F_326 ( V_4 ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_9 -> V_126 )
continue;
V_131 = F_93 ( V_9 ) ;
if ( ! V_131 -> V_693 )
F_323 ( V_9 ) ;
}
F_129 ( & V_2 -> V_245 ) ;
}
void F_283 ( struct V_1 * V_2 , struct V_129 * V_130 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = NULL ;
struct V_127 * V_128 ;
struct V_131 * V_131 ;
if ( ! F_327 ( V_2 , V_700 ) )
return;
if ( ! V_4 -> V_693 )
V_4 -> V_693 = true ;
else
F_319 ( & V_4 -> V_691 , V_74 +
F_30 ( V_692 ) ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_9 -> V_126 )
continue;
V_131 = F_93 ( V_9 ) ;
V_128 = F_92 ( V_9 -> V_126 ) ;
if ( V_128 -> V_130 == V_130 ) {
if ( ! V_131 -> V_693 ) {
F_126 ( V_9 ) ;
V_131 -> V_693 = true ;
} else {
F_319 ( & V_131 -> V_691 , V_74 +
F_30 ( V_696 ) ) ;
}
}
}
}
static void F_328 ( struct V_8 * V_9 )
{
struct V_131 * V_131 = F_93 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_701 * V_699 ;
unsigned long V_208 ;
F_329 ( & V_2 -> V_702 , V_208 ) ;
V_699 = V_131 -> V_703 ;
V_131 -> V_703 = NULL ;
F_330 ( & V_2 -> V_702 , V_208 ) ;
if ( V_699 ) {
F_331 ( & V_699 -> V_699 ) ;
F_196 ( V_699 ) ;
}
F_332 ( V_9 ) ;
F_196 ( V_131 ) ;
}
static void F_333 ( struct V_698 * V_704 )
{
struct V_701 * V_699 =
F_325 ( V_704 , struct V_701 , V_699 ) ;
F_128 ( & V_699 -> V_2 -> V_245 ) ;
F_121 ( V_699 -> V_705 ) ;
F_291 ( & V_699 -> V_706 -> V_52 ) ;
F_291 ( & V_699 -> V_705 -> V_52 ) ;
F_129 ( & V_699 -> V_2 -> V_245 ) ;
F_196 ( V_699 ) ;
}
static void F_334 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
struct V_701 * V_699 ;
struct V_129 * V_130 ;
struct V_707 * V_708 ;
struct V_709 V_710 , V_711 ;
unsigned long V_208 ;
if ( V_131 == NULL )
return;
F_335 ( & V_710 ) ;
F_329 ( & V_2 -> V_702 , V_208 ) ;
V_699 = V_131 -> V_703 ;
if ( V_699 == NULL || ! V_699 -> V_712 ) {
F_330 ( & V_2 -> V_702 , V_208 ) ;
return;
}
V_131 -> V_703 = NULL ;
if ( V_699 -> V_713 ) {
V_708 = V_699 -> V_713 ;
V_708 -> V_713 . V_714 = F_336 ( V_2 , V_131 -> V_66 , & V_711 ) ;
if ( 10 * ( F_337 ( & V_710 ) - F_337 ( & V_711 ) ) >
9 * V_9 -> V_715 ) {
V_708 -> V_713 . V_714 ++ ;
V_711 = F_338 ( F_337 ( & V_711 ) +
V_9 -> V_715 ) ;
}
V_708 -> V_713 . V_716 = V_711 . V_716 ;
V_708 -> V_713 . V_717 = V_711 . V_717 ;
F_339 ( & V_708 -> V_52 . V_718 ,
& V_708 -> V_52 . V_719 -> V_720 ) ;
F_340 ( & V_708 -> V_52 . V_719 -> V_721 ) ;
}
F_341 ( V_2 , V_131 -> V_66 ) ;
F_330 ( & V_2 -> V_702 , V_208 ) ;
V_130 = V_699 -> V_705 ;
F_342 ( 1 << V_131 -> V_97 ,
& V_130 -> V_248 . V_722 ) ;
if ( F_131 ( & V_130 -> V_248 ) == 0 )
F_343 ( & V_4 -> V_246 ) ;
F_344 ( & V_699 -> V_699 ) ;
F_345 ( V_131 -> V_97 , V_699 -> V_706 ) ;
}
void F_346 ( struct V_1 * V_2 , int V_66 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = V_4 -> V_723 [ V_66 ] ;
F_334 ( V_2 , V_9 ) ;
}
void F_347 ( struct V_1 * V_2 , int V_97 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = V_4 -> V_724 [ V_97 ] ;
F_334 ( V_2 , V_9 ) ;
}
void F_348 ( struct V_1 * V_2 , int V_97 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 =
F_93 ( V_4 -> V_724 [ V_97 ] ) ;
unsigned long V_208 ;
F_329 ( & V_2 -> V_702 , V_208 ) ;
if ( V_131 -> V_703 ) {
if ( ( ++ V_131 -> V_703 -> V_712 ) > 1 )
F_76 ( L_131 ) ;
} else {
F_322 ( L_132 ) ;
}
F_330 ( & V_2 -> V_702 , V_208 ) ;
}
static int F_349 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_125 * V_126 ,
struct V_129 * V_130 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
unsigned long V_725 ;
T_1 V_726 ;
int V_221 ;
V_221 = F_114 ( V_2 , V_130 , F_149 ( V_4 ) ) ;
if ( V_221 )
goto V_727;
V_725 = V_9 -> V_153 * V_126 -> V_134 + V_9 -> V_228 * V_126 -> V_234 / 8 ;
V_221 = F_350 ( 6 ) ;
if ( V_221 )
goto V_727;
if ( V_131 -> V_97 )
V_726 = V_728 ;
else
V_726 = V_729 ;
F_351 ( V_730 | V_726 ) ;
F_351 ( V_731 ) ;
F_351 ( V_732 |
F_352 ( V_131 -> V_97 ) ) ;
F_351 ( V_126 -> V_134 ) ;
F_351 ( V_130 -> V_183 + V_725 ) ;
F_351 ( V_731 ) ;
F_353 () ;
V_727:
return V_221 ;
}
static int F_354 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_125 * V_126 ,
struct V_129 * V_130 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
unsigned long V_725 ;
T_1 V_726 ;
int V_221 ;
V_221 = F_114 ( V_2 , V_130 , F_149 ( V_4 ) ) ;
if ( V_221 )
goto V_727;
V_725 = V_9 -> V_153 * V_126 -> V_134 + V_9 -> V_228 * V_126 -> V_234 / 8 ;
V_221 = F_350 ( 6 ) ;
if ( V_221 )
goto V_727;
if ( V_131 -> V_97 )
V_726 = V_728 ;
else
V_726 = V_729 ;
F_351 ( V_730 | V_726 ) ;
F_351 ( V_731 ) ;
F_351 ( V_733 |
F_352 ( V_131 -> V_97 ) ) ;
F_351 ( V_126 -> V_134 ) ;
F_351 ( V_130 -> V_183 + V_725 ) ;
F_351 ( V_731 ) ;
F_353 () ;
V_727:
return V_221 ;
}
static int F_355 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_125 * V_126 ,
struct V_129 * V_130 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
T_5 V_734 , V_735 ;
int V_221 ;
V_221 = F_114 ( V_2 , V_130 , F_149 ( V_4 ) ) ;
if ( V_221 )
goto V_727;
V_221 = F_350 ( 4 ) ;
if ( V_221 )
goto V_727;
F_351 ( V_732 |
F_352 ( V_131 -> V_97 ) ) ;
F_351 ( V_126 -> V_134 ) ;
F_351 ( V_130 -> V_183 | V_130 -> V_148 ) ;
V_734 = 0 ;
V_735 = F_3 ( F_256 ( V_131 -> V_66 ) ) & 0x0fff0fff ;
F_351 ( V_734 | V_735 ) ;
F_353 () ;
V_727:
return V_221 ;
}
static int F_356 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_125 * V_126 ,
struct V_129 * V_130 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
T_5 V_734 , V_735 ;
int V_221 ;
V_221 = F_114 ( V_2 , V_130 , F_149 ( V_4 ) ) ;
if ( V_221 )
goto V_727;
V_221 = F_350 ( 4 ) ;
if ( V_221 )
goto V_727;
F_351 ( V_732 |
F_352 ( V_131 -> V_97 ) ) ;
F_351 ( V_126 -> V_134 | V_130 -> V_148 ) ;
F_351 ( V_130 -> V_183 ) ;
V_734 = F_3 ( F_172 ( V_131 -> V_66 ) ) & V_316 ;
V_735 = F_3 ( F_256 ( V_131 -> V_66 ) ) & 0x0fff0fff ;
F_351 ( V_734 | V_735 ) ;
F_353 () ;
V_727:
return V_221 ;
}
static int F_357 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_125 * V_126 ,
struct V_129 * V_130 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
struct V_218 * V_290 = & V_4 -> V_290 [ V_736 ] ;
int V_221 ;
V_221 = F_114 ( V_2 , V_130 , V_290 ) ;
if ( V_221 )
goto V_727;
V_221 = F_358 ( V_290 , 4 ) ;
if ( V_221 )
goto V_727;
F_359 ( V_290 , V_733 | ( V_131 -> V_97 << 19 ) ) ;
F_359 ( V_290 , ( V_126 -> V_134 | V_130 -> V_148 ) ) ;
F_359 ( V_290 , ( V_130 -> V_183 ) ) ;
F_359 ( V_290 , ( V_731 ) ) ;
F_360 ( V_290 ) ;
V_727:
return V_221 ;
}
static int F_361 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_125 * V_126 ,
struct V_129 * V_130 )
{
return - V_737 ;
}
static int F_362 ( struct V_8 * V_9 ,
struct V_125 * V_126 ,
struct V_707 * V_713 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
struct V_701 * V_699 ;
unsigned long V_208 ;
int V_221 ;
V_699 = F_298 ( sizeof *V_699 , V_650 ) ;
if ( V_699 == NULL )
return - V_629 ;
V_699 -> V_713 = V_713 ;
V_699 -> V_2 = V_9 -> V_2 ;
V_128 = F_92 ( V_9 -> V_126 ) ;
V_699 -> V_705 = V_128 -> V_130 ;
F_363 ( & V_699 -> V_699 , F_333 ) ;
F_329 ( & V_2 -> V_702 , V_208 ) ;
if ( V_131 -> V_703 ) {
F_330 ( & V_2 -> V_702 , V_208 ) ;
F_196 ( V_699 ) ;
F_322 ( L_133 ) ;
return - V_738 ;
}
V_131 -> V_703 = V_699 ;
F_330 ( & V_2 -> V_702 , V_208 ) ;
V_128 = F_92 ( V_126 ) ;
V_130 = V_128 -> V_130 ;
F_128 ( & V_2 -> V_245 ) ;
F_364 ( & V_699 -> V_705 -> V_52 ) ;
F_364 ( & V_130 -> V_52 ) ;
V_9 -> V_126 = V_126 ;
V_221 = F_365 ( V_2 , V_131 -> V_66 ) ;
if ( V_221 )
goto V_739;
V_699 -> V_706 = V_130 ;
V_699 -> V_740 = true ;
F_366 ( 1 << V_131 -> V_97 , & V_699 -> V_705 -> V_248 ) ;
V_221 = V_4 -> V_193 . V_741 ( V_2 , V_9 , V_126 , V_130 ) ;
if ( V_221 )
goto V_742;
F_129 ( & V_2 -> V_245 ) ;
F_367 ( V_131 -> V_97 , V_130 ) ;
return 0 ;
V_742:
F_368 ( 1 << V_131 -> V_97 , & V_699 -> V_705 -> V_248 ) ;
V_739:
F_291 ( & V_699 -> V_705 -> V_52 ) ;
F_291 ( & V_130 -> V_52 ) ;
F_129 ( & V_2 -> V_245 ) ;
F_329 ( & V_2 -> V_702 , V_208 ) ;
V_131 -> V_703 = NULL ;
F_330 ( & V_2 -> V_702 , V_208 ) ;
F_196 ( V_699 ) ;
return V_221 ;
}
static void F_369 ( struct V_1 * V_2 ,
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
F_87 ( V_4 , V_97 , V_66 ) ;
F_82 ( V_4 , V_66 ) ;
}
static void F_370 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_131 * V_131 = F_93 ( V_9 ) ;
V_131 -> V_328 = - 1 ;
F_369 ( V_2 , V_131 -> V_66 , V_131 -> V_97 ) ;
}
static void F_371 ( struct V_1 * V_2 , int V_66 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_131 * V_131 ;
int V_99 ;
V_131 = F_298 ( sizeof( struct V_131 ) + ( V_743 * sizeof( struct V_653 * ) ) , V_650 ) ;
if ( V_131 == NULL )
return;
F_372 ( V_2 , & V_131 -> V_52 , & V_744 ) ;
F_373 ( & V_131 -> V_52 , 256 ) ;
for ( V_99 = 0 ; V_99 < 256 ; V_99 ++ ) {
V_131 -> V_594 [ V_99 ] = V_99 ;
V_131 -> V_595 [ V_99 ] = V_99 ;
V_131 -> V_596 [ V_99 ] = V_99 ;
}
V_131 -> V_66 = V_66 ;
V_131 -> V_97 = V_66 ;
if ( F_64 ( V_2 ) && F_374 ( V_2 ) ) {
F_25 ( L_134 ) ;
V_131 -> V_97 = ! V_66 ;
}
F_63 ( V_66 >= F_212 ( V_4 -> V_724 ) ||
V_4 -> V_724 [ V_131 -> V_97 ] != NULL ) ;
V_4 -> V_724 [ V_131 -> V_97 ] = & V_131 -> V_52 ;
V_4 -> V_723 [ V_131 -> V_66 ] = & V_131 -> V_52 ;
F_370 ( & V_131 -> V_52 ) ;
V_131 -> V_314 = true ;
if ( F_8 ( V_2 ) ) {
V_745 . V_746 = F_189 ;
V_745 . V_747 = F_190 ;
} else {
V_745 . V_746 = F_187 ;
V_745 . V_747 = F_188 ;
}
F_375 ( & V_131 -> V_52 , & V_745 ) ;
V_131 -> V_693 = false ;
F_376 ( & V_131 -> V_691 , F_321 ,
( unsigned long ) V_131 ) ;
}
int F_377 ( struct V_1 * V_2 , void * V_748 ,
struct V_623 * V_624 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_749 * V_750 = V_748 ;
struct V_751 * V_752 ;
struct V_131 * V_9 ;
if ( ! V_4 ) {
F_76 ( L_135 ) ;
return - V_223 ;
}
V_752 = F_378 ( V_2 , V_750 -> V_753 ,
V_754 ) ;
if ( ! V_752 ) {
F_76 ( L_136 ) ;
return - V_223 ;
}
V_9 = F_93 ( F_379 ( V_752 ) ) ;
V_750 -> V_66 = V_9 -> V_66 ;
return 0 ;
}
static int F_380 ( struct V_1 * V_2 , int V_755 )
{
struct V_50 * V_51 ;
int V_756 = 0 ;
int V_757 = 0 ;
F_14 (encoder, &dev->mode_config.encoder_list, base.head) {
if ( V_755 & V_51 -> V_758 )
V_756 |= ( 1 << V_757 ) ;
V_757 ++ ;
}
return V_756 ;
}
static bool F_381 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! F_64 ( V_2 ) )
return false ;
if ( ( F_3 ( V_259 ) & V_759 ) == 0 )
return false ;
if ( F_2 ( V_2 ) &&
( F_3 ( V_760 ) & V_761 ) )
return false ;
return true ;
}
static void F_382 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_50 * V_51 ;
bool V_762 = false ;
bool V_763 = false ;
if ( F_64 ( V_2 ) && ! F_65 ( V_2 ) )
V_763 = F_383 ( V_2 ) ;
if ( ! V_763 && ! F_8 ( V_2 ) ) {
F_23 ( V_764 , 0 ) ;
}
if ( F_8 ( V_2 ) ) {
V_762 = F_384 ( V_2 ) ;
if ( F_381 ( V_2 ) )
F_385 ( V_2 , V_259 ) ;
if ( V_762 && ( F_3 ( V_110 ) & V_759 ) )
F_385 ( V_2 , V_110 ) ;
}
F_386 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
int V_63 ;
if ( F_3 ( V_112 ) & V_765 ) {
V_63 = F_387 ( V_2 , V_766 ) ;
if ( ! V_63 )
F_388 ( V_2 , V_112 ) ;
if ( ! V_63 && ( F_3 ( V_108 ) & V_759 ) )
F_385 ( V_2 , V_108 ) ;
}
if ( F_3 ( V_113 ) & V_765 )
F_388 ( V_2 , V_113 ) ;
if ( F_3 ( V_114 ) & V_765 )
F_388 ( V_2 , V_114 ) ;
if ( F_3 ( V_109 ) & V_759 )
F_385 ( V_2 , V_109 ) ;
if ( ! V_762 && ( F_3 ( V_110 ) & V_759 ) )
F_385 ( V_2 , V_110 ) ;
} else if ( F_389 ( V_2 ) ) {
bool V_63 = false ;
if ( F_3 ( V_767 ) & V_768 ) {
F_25 ( L_137 ) ;
V_63 = F_387 ( V_2 , V_767 ) ;
if ( ! V_63 && F_390 ( V_2 ) ) {
F_25 ( L_138 ) ;
F_388 ( V_2 , V_767 ) ;
}
if ( ! V_63 && F_391 ( V_2 ) ) {
F_25 ( L_139 ) ;
F_385 ( V_2 , V_769 ) ;
}
}
if ( F_3 ( V_767 ) & V_768 ) {
F_25 ( L_140 ) ;
V_63 = F_387 ( V_2 , V_770 ) ;
}
if ( ! V_63 && ( F_3 ( V_770 ) & V_768 ) ) {
if ( F_390 ( V_2 ) ) {
F_25 ( L_141 ) ;
F_388 ( V_2 , V_770 ) ;
}
if ( F_391 ( V_2 ) ) {
F_25 ( L_142 ) ;
F_385 ( V_2 , V_771 ) ;
}
}
if ( F_391 ( V_2 ) &&
( F_3 ( V_772 ) & V_759 ) ) {
F_25 ( L_143 ) ;
F_385 ( V_2 , V_772 ) ;
}
} else if ( F_11 ( V_2 ) )
F_392 ( V_2 ) ;
if ( F_393 ( V_2 ) )
F_394 ( V_2 ) ;
F_14 (encoder, &dev->mode_config.encoder_list, base.head) {
V_51 -> V_52 . V_660 = V_51 -> V_773 ;
V_51 -> V_52 . V_774 =
F_380 ( V_2 , V_51 -> V_758 ) ;
}
F_395 ( V_2 ) ;
F_313 ( V_2 ) ;
}
static void F_396 ( struct V_125 * V_126 )
{
struct V_127 * V_128 = F_92 ( V_126 ) ;
F_397 ( V_126 ) ;
F_292 ( & V_128 -> V_130 -> V_52 ) ;
F_196 ( V_128 ) ;
}
static int F_398 ( struct V_125 * V_126 ,
struct V_623 * V_624 ,
unsigned int * V_625 )
{
struct V_127 * V_128 = F_92 ( V_126 ) ;
struct V_129 * V_130 = V_128 -> V_130 ;
return F_399 ( V_624 , & V_130 -> V_52 , V_625 ) ;
}
int F_300 ( struct V_1 * V_2 ,
struct V_127 * V_128 ,
struct V_648 * V_649 ,
struct V_129 * V_130 )
{
int V_221 ;
if ( V_130 -> V_148 == V_222 )
return - V_223 ;
if ( V_649 -> V_134 & 63 )
return - V_223 ;
switch ( V_649 -> V_567 ) {
case 8 :
case 16 :
case 24 :
case 32 :
break;
default:
return - V_223 ;
}
V_221 = F_400 ( V_2 , & V_128 -> V_52 , & V_775 ) ;
if ( V_221 ) {
F_76 ( L_144 , V_221 ) ;
return V_221 ;
}
F_401 ( & V_128 -> V_52 , V_649 ) ;
V_128 -> V_130 = V_130 ;
return 0 ;
}
static struct V_125 *
F_402 ( struct V_1 * V_2 ,
struct V_623 * V_776 ,
struct V_648 * V_649 )
{
struct V_129 * V_130 ;
V_130 = F_285 ( F_286 ( V_2 , V_776 , V_649 -> V_625 ) ) ;
if ( & V_130 -> V_52 == NULL )
return F_299 ( - V_628 ) ;
return F_297 ( V_2 , V_649 , V_130 ) ;
}
static struct V_129 *
F_403 ( struct V_1 * V_2 )
{
struct V_129 * V_777 ;
int V_221 ;
F_404 ( ! F_405 ( & V_2 -> V_245 ) ) ;
V_777 = F_305 ( V_2 , 4096 ) ;
if ( ! V_777 ) {
F_406 ( L_145 ) ;
return NULL ;
}
V_221 = F_118 ( V_777 , 4096 , true ) ;
if ( V_221 ) {
F_76 ( L_146 , V_221 ) ;
goto V_778;
}
V_221 = F_287 ( V_777 , 1 ) ;
if ( V_221 ) {
F_76 ( L_147 , V_221 ) ;
goto V_227;
}
return V_777 ;
V_227:
F_121 ( V_777 ) ;
V_778:
F_291 ( & V_777 -> V_52 ) ;
F_129 ( & V_2 -> V_245 ) ;
return NULL ;
}
bool F_407 ( struct V_1 * V_2 , T_7 V_78 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_779 ;
V_779 = F_408 ( V_780 ) ;
if ( V_779 & V_781 ) {
F_406 ( L_148 ) ;
return false ;
}
V_779 = ( V_782 << V_783 ) |
( V_78 << V_784 ) | V_785 ;
F_409 ( V_780 , V_779 ) ;
F_410 ( V_780 ) ;
V_779 |= V_781 ;
F_409 ( V_780 , V_779 ) ;
return true ;
}
void F_411 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_786 = F_3 ( V_787 ) ;
T_7 V_788 , V_789 , V_790 , V_791 ;
F_409 ( V_792 , F_3 ( V_792 ) | V_793 ) ;
F_409 ( V_794 , F_3 ( V_794 ) | V_795 ) ;
F_23 ( V_796 , 100000 ) ;
F_23 ( V_797 , 100000 ) ;
F_23 ( V_798 , 90000 ) ;
F_23 ( V_799 , 80000 ) ;
F_23 ( V_800 , 1 ) ;
V_788 = ( V_786 & V_801 ) >> V_802 ;
V_789 = ( V_786 & V_803 ) ;
V_790 = ( V_786 & V_804 ) >>
V_805 ;
V_791 = ( F_3 ( V_806 + ( V_790 * 4 ) ) & V_807 ) >>
V_808 ;
V_4 -> V_788 = V_788 ;
V_4 -> V_790 = V_790 ;
V_4 -> V_809 = V_790 ;
V_4 -> V_810 = V_789 ;
V_4 -> V_811 = V_790 ;
F_322 ( L_149 ,
V_788 , V_789 , V_790 ) ;
F_23 ( V_812 , V_813 | V_814 ) ;
F_23 ( V_815 , V_791 ) ;
F_66 ( V_815 ) ;
V_786 |= V_816 ;
F_23 ( V_787 , V_786 ) ;
if ( F_24 ( ( F_3 ( V_780 ) & V_781 ) == 0 , 10 ) )
F_76 ( L_150 ) ;
F_412 ( 1 ) ;
F_407 ( V_2 , V_790 ) ;
V_4 -> V_817 = F_3 ( 0x112e4 ) + F_3 ( 0x112e8 ) +
F_3 ( 0x112e0 ) ;
V_4 -> V_818 = F_413 ( V_74 ) ;
V_4 -> V_819 = F_3 ( 0x112f4 ) ;
F_414 ( & V_4 -> V_820 ) ;
}
void F_415 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_779 = F_408 ( V_780 ) ;
F_23 ( V_812 , F_3 ( V_812 ) & ~ V_814 ) ;
F_23 ( V_821 , V_822 ) ;
F_23 ( V_823 , F_3 ( V_823 ) & ~ V_824 ) ;
F_23 ( V_825 , V_824 ) ;
F_23 ( V_826 , F_3 ( V_826 ) | V_824 ) ;
F_407 ( V_2 , V_4 -> V_790 ) ;
F_412 ( 1 ) ;
V_779 |= V_781 ;
F_23 ( V_780 , V_779 ) ;
F_412 ( 1 ) ;
}
void F_416 ( struct V_1 * V_2 , T_7 V_78 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_827 ;
V_827 = ( V_78 & 0x3ff ) << 25 ;
F_23 ( V_828 , V_827 ) ;
}
void F_417 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_828 , 1 << 31 ) ;
F_23 ( V_829 , 0xffffffff ) ;
F_23 ( V_830 , 0 ) ;
F_418 ( & V_4 -> V_831 ) ;
V_4 -> V_832 = 0 ;
F_419 ( & V_4 -> V_831 ) ;
F_23 ( V_833 , F_3 ( V_833 ) ) ;
}
static unsigned long F_420 ( T_1 V_834 )
{
unsigned long V_835 ;
int div = ( V_834 & 0x3f0000 ) >> 16 ;
int V_836 = ( V_834 & 0x3000 ) >> 12 ;
int V_837 = ( V_834 & 0x7 ) ;
if ( ! V_837 )
return 0 ;
V_835 = ( ( div * 133333 ) / ( ( 1 << V_836 ) * V_837 ) ) ;
return V_835 ;
}
void F_421 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_838 ;
T_7 V_839 [ 16 ] ;
int V_99 ;
F_23 ( V_840 , 0 ) ;
F_66 ( V_840 ) ;
F_23 ( V_841 , 0x15040d00 ) ;
F_23 ( V_842 , 0x007f0000 ) ;
F_23 ( V_843 , 0x1e220004 ) ;
F_23 ( V_844 , 0x04000004 ) ;
for ( V_99 = 0 ; V_99 < 5 ; V_99 ++ )
F_23 ( V_845 + ( V_99 * 4 ) , 0 ) ;
for ( V_99 = 0 ; V_99 < 3 ; V_99 ++ )
F_23 ( V_846 + ( V_99 * 4 ) , 0 ) ;
for ( V_99 = 0 ; V_99 < 16 ; V_99 ++ ) {
T_1 V_847 = F_3 ( V_806 + ( V_99 * 4 ) ) ;
unsigned long V_835 = F_420 ( V_847 ) ;
unsigned long V_848 = ( V_847 & V_807 ) >>
V_808 ;
unsigned long V_78 ;
V_78 = V_848 * V_848 ;
V_78 *= ( V_835 / 1000 ) ;
V_78 *= 255 ;
V_78 /= ( 127 * 127 * 900 ) ;
if ( V_78 > 0xff )
F_76 ( L_151 , V_78 ) ;
V_839 [ V_99 ] = V_78 ;
}
V_839 [ 14 ] = 0 ;
V_839 [ 15 ] = 0 ;
for ( V_99 = 0 ; V_99 < 4 ; V_99 ++ ) {
T_1 V_78 = ( V_839 [ V_99 * 4 ] << 24 ) | ( V_839 [ ( V_99 * 4 ) + 1 ] << 16 ) |
( V_839 [ ( V_99 * 4 ) + 2 ] << 8 ) | ( V_839 [ ( V_99 * 4 ) + 3 ] ) ;
F_23 ( V_849 + ( V_99 * 4 ) , V_78 ) ;
}
F_23 ( V_850 , 0 ) ;
F_23 ( V_851 , 0 ) ;
F_23 ( V_852 , 0x00007f00 ) ;
F_23 ( V_853 , 0x0000000e ) ;
F_23 ( V_854 , 0x000e0000 ) ;
F_23 ( V_855 , 0x68000300 ) ;
F_23 ( V_856 , 0x42000000 ) ;
F_23 ( V_857 , 0x00140031 ) ;
F_23 ( V_858 , 0 ) ;
F_23 ( V_859 , 0 ) ;
for ( V_99 = 0 ; V_99 < 8 ; V_99 ++ )
F_23 ( V_860 + ( V_99 * 4 ) , 0 ) ;
F_23 ( V_840 , 0x80000019 ) ;
V_838 = F_3 ( V_861 ) ;
V_4 -> V_862 = ( V_838 & V_863 ) ;
}
void F_422 ( struct V_3 * V_4 )
{
T_1 V_864 = F_3 ( V_865 ) ;
T_1 V_866 = F_3 ( V_867 ) ;
T_1 V_868 , V_869 = 0 ;
int V_870 , V_871 , V_872 ;
int V_99 ;
F_23 ( V_873 , 0 ) ;
F_128 ( & V_4 -> V_2 -> V_245 ) ;
F_101 ( V_4 ) ;
F_23 ( V_874 , 0 ) ;
F_23 ( V_875 , 1000 << 16 ) ;
F_23 ( V_876 , 40 << 16 | 30 ) ;
F_23 ( V_877 , 30 ) ;
F_23 ( V_878 , 125000 ) ;
F_23 ( V_879 , 25 ) ;
for ( V_99 = 0 ; V_99 < V_880 ; V_99 ++ )
F_23 ( F_423 ( V_4 -> V_290 [ V_99 ] . V_881 ) , 10 ) ;
F_23 ( V_882 , 0 ) ;
F_23 ( V_883 , 1000 ) ;
F_23 ( V_884 , 50000 ) ;
F_23 ( V_885 , 100000 ) ;
F_23 ( V_886 , 64000 ) ;
if ( V_887 )
V_869 = V_888 |
V_889 ;
F_23 ( V_874 ,
V_869 |
F_424 ( 1 ) |
V_890 ) ;
F_23 ( V_828 ,
F_425 ( 10 ) |
F_426 ( 0 ) |
V_891 ) ;
F_23 ( V_892 ,
F_425 ( 12 ) ) ;
F_23 ( V_893 , 1000000 ) ;
F_23 ( V_894 ,
18 << 24 |
6 << 16 ) ;
F_23 ( V_895 , 10000 ) ;
F_23 ( V_896 , 1000000 ) ;
F_23 ( V_897 , 100000 ) ;
F_23 ( V_898 , 5000000 ) ;
F_23 ( V_899 , 10 ) ;
F_23 ( V_900 ,
V_901 |
V_902 |
V_903 |
V_904 |
V_905 |
V_906 ) ;
if ( F_24 ( ( F_3 ( V_907 ) & V_908 ) == 0 ,
500 ) )
F_76 ( L_152 ) ;
F_23 ( V_909 , 0 ) ;
F_23 ( V_907 ,
V_908 |
V_910 ) ;
if ( F_24 ( ( F_3 ( V_907 ) & V_908 ) == 0 ,
500 ) )
F_76 ( L_153 ) ;
V_871 = ( V_864 & 0xff0000 ) >> 16 ;
V_872 = V_864 & 0xff ;
V_870 = ( V_866 & 0xff00 ) >> 8 ;
if ( F_24 ( ( F_3 ( V_907 ) & V_908 ) == 0 ,
500 ) )
F_76 ( L_152 ) ;
F_23 ( V_907 , V_911 ) ;
V_868 = F_3 ( V_909 ) ;
if ( F_24 ( ( F_3 ( V_907 ) & V_908 ) == 0 ,
500 ) )
F_76 ( L_153 ) ;
if ( V_868 & ( 1 << 31 ) ) {
V_872 = V_868 & 0xff ;
F_322 ( L_154 , V_868 * 50 ) ;
}
V_4 -> V_809 = V_872 ;
V_4 -> V_810 = V_871 ;
V_4 -> V_811 = V_870 ;
F_23 ( V_830 ,
V_912 |
V_913 |
V_914 |
V_915 |
V_916 |
V_917 |
V_918 ) ;
F_418 ( & V_4 -> V_831 ) ;
F_404 ( V_4 -> V_832 != 0 ) ;
F_23 ( V_919 , 0 ) ;
F_419 ( & V_4 -> V_831 ) ;
F_23 ( V_829 , 0 ) ;
F_102 ( V_4 ) ;
F_129 ( & V_4 -> V_2 -> V_245 ) ;
}
static void F_427 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_920 = V_921 ;
V_920 |= V_922 |
V_923 |
V_924 ;
V_920 |= V_925 ;
F_23 ( V_926 ,
V_927 |
V_928 ) ;
F_23 ( V_929 ,
V_930 ) ;
F_23 ( V_931 , V_920 ) ;
F_23 ( V_932 ,
( F_3 ( V_932 ) |
V_933 | V_934 ) ) ;
F_23 ( V_935 ,
( F_3 ( V_935 ) |
V_936 ) ) ;
F_23 ( V_464 ,
( F_3 ( V_464 ) |
V_465 ) ) ;
F_23 ( V_475 , 0 ) ;
F_23 ( V_476 , 0 ) ;
F_23 ( V_477 , 0 ) ;
if ( F_428 ( V_2 ) ) {
F_23 ( V_937 ,
F_3 ( V_937 ) |
V_938 ) ;
F_23 ( V_932 ,
F_3 ( V_932 ) |
V_933 ) ;
F_23 ( V_935 ,
F_3 ( V_935 ) |
V_939 |
V_940 |
V_941 ) ;
}
F_23 ( V_932 ,
F_3 ( V_932 ) |
V_942 ) ;
F_23 ( V_943 ,
V_944 << 16 |
V_944 ) ;
}
static void F_429 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
T_5 V_920 = V_921 ;
F_23 ( V_931 , V_920 ) ;
F_23 ( V_932 ,
F_3 ( V_932 ) |
V_942 ) ;
F_23 ( V_475 , 0 ) ;
F_23 ( V_476 , 0 ) ;
F_23 ( V_477 , 0 ) ;
F_23 ( V_937 ,
F_3 ( V_937 ) |
V_938 | V_945 ) ;
F_23 ( V_932 ,
F_3 ( V_932 ) |
V_933 | V_934 ) ;
F_23 ( V_935 ,
F_3 ( V_935 ) |
V_936 |
V_946 ) ;
F_430 (pipe)
F_23 ( F_49 ( V_66 ) ,
F_3 ( F_49 ( V_66 ) ) |
V_241 ) ;
}
static void F_431 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
T_5 V_920 = V_921 ;
F_23 ( V_931 , V_920 ) ;
F_23 ( V_475 , 0 ) ;
F_23 ( V_476 , 0 ) ;
F_23 ( V_477 , 0 ) ;
F_23 ( V_935 , V_947 ) ;
F_430 (pipe)
F_23 ( F_49 ( V_66 ) ,
F_3 ( F_49 ( V_66 ) ) |
V_241 ) ;
}
static void F_432 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_920 ;
F_23 ( V_948 , 0 ) ;
F_23 ( V_949 , V_950 |
V_951 |
V_952 ) ;
F_23 ( V_953 , 0 ) ;
V_920 = V_921 |
V_954 |
V_955 ;
if ( F_433 ( V_2 ) )
V_920 |= V_956 ;
F_23 ( V_957 , V_920 ) ;
}
static void F_434 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_948 , V_958 ) ;
F_23 ( V_949 , 0 ) ;
F_23 ( V_957 , 0 ) ;
F_23 ( V_953 , 0 ) ;
F_409 ( V_959 , 0 ) ;
}
static void F_435 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_948 , V_960 |
V_958 |
V_961 |
V_962 |
V_963 ) ;
F_23 ( V_949 , 0 ) ;
}
static void F_436 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_964 = F_3 ( V_965 ) ;
V_964 |= V_966 | V_967 |
V_968 ;
F_23 ( V_965 , V_964 ) ;
}
static void F_437 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_948 , V_969 ) ;
}
static void F_438 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_957 , V_954 ) ;
}
static void F_439 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_970 , V_971 ) ;
}
static void F_440 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( V_970 , V_971 ) ;
F_23 ( V_972 , F_3 ( V_972 ) |
V_973 ) ;
}
static void F_441 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_974 ) {
F_121 ( V_4 -> V_974 ) ;
F_291 ( & V_4 -> V_974 -> V_52 ) ;
V_4 -> V_974 = NULL ;
}
if ( V_4 -> V_975 ) {
F_121 ( V_4 -> V_975 ) ;
F_291 ( & V_4 -> V_975 -> V_52 ) ;
V_4 -> V_975 = NULL ;
}
}
static void F_442 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_3 ( V_976 ) ) {
F_23 ( V_977 , F_3 ( V_977 ) | V_978 ) ;
F_24 ( ( ( F_3 ( V_977 ) & V_979 ) == V_980 ) ,
50 ) ;
F_23 ( V_976 , 0 ) ;
F_66 ( V_976 ) ;
F_23 ( V_977 , F_3 ( V_977 ) & ~ V_978 ) ;
F_66 ( V_977 ) ;
}
F_441 ( V_2 ) ;
}
static int F_443 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_974 == NULL )
V_4 -> V_974 = F_403 ( V_2 ) ;
if ( ! V_4 -> V_974 )
return - V_629 ;
if ( V_4 -> V_975 == NULL )
V_4 -> V_975 = F_403 ( V_2 ) ;
if ( ! V_4 -> V_975 ) {
F_441 ( V_2 ) ;
return - V_629 ;
}
return 0 ;
}
void F_444 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_221 ;
if ( ! V_887 )
return;
F_128 ( & V_2 -> V_245 ) ;
V_221 = F_443 ( V_2 ) ;
if ( V_221 ) {
F_129 ( & V_2 -> V_245 ) ;
return;
}
V_221 = F_350 ( 6 ) ;
if ( V_221 ) {
F_441 ( V_2 ) ;
F_129 ( & V_2 -> V_245 ) ;
return;
}
F_351 ( V_981 | V_982 ) ;
F_351 ( V_983 ) ;
F_351 ( V_4 -> V_974 -> V_183 |
V_984 |
V_985 |
V_986 |
V_987 ) ;
F_351 ( V_981 ) ;
F_351 ( V_731 ) ;
F_351 ( V_988 ) ;
F_353 () ;
V_221 = F_445 ( F_149 ( V_4 ) ) ;
if ( V_221 ) {
F_76 ( L_155 ) ;
F_441 ( V_2 ) ;
F_129 ( & V_2 -> V_245 ) ;
return;
}
F_23 ( V_976 , V_4 -> V_975 -> V_183 | V_989 ) ;
F_23 ( V_977 , F_3 ( V_977 ) & ~ V_978 ) ;
F_129 ( & V_2 -> V_245 ) ;
}
void F_446 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_193 . V_990 ( V_2 ) ;
if ( V_4 -> V_193 . V_991 )
V_4 -> V_193 . V_991 ( V_2 ) ;
}
static void F_447 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_8 ( V_2 ) ) {
V_4 -> V_193 . V_329 = F_179 ;
V_4 -> V_193 . V_592 = F_257 ;
} else {
V_4 -> V_193 . V_329 = F_184 ;
V_4 -> V_193 . V_592 = F_244 ;
}
if ( F_111 ( V_2 ) ) {
if ( F_8 ( V_2 ) ) {
V_4 -> V_193 . V_194 = F_106 ;
V_4 -> V_193 . V_195 = F_103 ;
V_4 -> V_193 . V_196 = F_105 ;
} else if ( F_433 ( V_2 ) ) {
V_4 -> V_193 . V_194 = F_99 ;
V_4 -> V_193 . V_195 = F_97 ;
V_4 -> V_193 . V_196 = F_98 ;
} else if ( F_116 ( V_2 ) ) {
V_4 -> V_193 . V_194 = F_96 ;
V_4 -> V_193 . V_195 = F_91 ;
V_4 -> V_193 . V_196 = F_94 ;
}
}
if ( F_230 ( V_2 ) || ( F_246 ( V_2 ) && ! F_448 ( V_2 ) ) )
V_4 -> V_193 . V_537 =
F_199 ;
else if ( F_449 ( V_2 ) )
V_4 -> V_193 . V_537 =
F_200 ;
else if ( F_95 ( V_2 ) || F_281 ( V_2 ) || F_448 ( V_2 ) )
V_4 -> V_193 . V_537 =
F_201 ;
else if ( F_112 ( V_2 ) )
V_4 -> V_193 . V_537 =
F_202 ;
else if ( F_282 ( V_2 ) )
V_4 -> V_193 . V_537 =
F_204 ;
else if ( F_450 ( V_2 ) )
V_4 -> V_193 . V_537 =
F_205 ;
else
V_4 -> V_193 . V_537 =
F_206 ;
if ( F_8 ( V_2 ) ) {
if ( F_139 ( V_2 ) )
V_4 -> V_193 . V_991 = F_439 ;
else if ( F_136 ( V_2 ) )
V_4 -> V_193 . V_991 = F_440 ;
if ( F_2 ( V_2 ) ) {
if ( F_3 ( V_992 ) & V_993 )
V_4 -> V_193 . V_490 = F_235 ;
else {
F_25 ( L_156
L_157 ) ;
V_4 -> V_193 . V_490 = NULL ;
}
V_4 -> V_193 . V_294 = F_137 ;
V_4 -> V_193 . V_990 = F_427 ;
} else if ( F_104 ( V_2 ) ) {
if ( F_239 () ) {
V_4 -> V_193 . V_490 = F_238 ;
} else {
F_25 ( L_158
L_157 ) ;
V_4 -> V_193 . V_490 = NULL ;
}
V_4 -> V_193 . V_294 = F_142 ;
V_4 -> V_193 . V_990 = F_429 ;
} else if ( F_135 ( V_2 ) ) {
V_4 -> V_193 . V_294 = F_143 ;
if ( F_239 () ) {
V_4 -> V_193 . V_490 = F_238 ;
} else {
F_25 ( L_158
L_157 ) ;
V_4 -> V_193 . V_490 = NULL ;
}
V_4 -> V_193 . V_990 = F_431 ;
} else
V_4 -> V_193 . V_490 = NULL ;
} else if ( F_10 ( V_2 ) ) {
if ( ! F_211 ( F_220 ( V_2 ) ,
V_4 -> V_383 ,
V_4 -> V_388 ,
V_4 -> V_389 ) ) {
F_249 ( L_159
L_160
L_161 ,
( V_4 -> V_383 == 1 ) ? L_162 : L_163 ,
V_4 -> V_388 , V_4 -> V_389 ) ;
F_213 ( V_2 ) ;
V_4 -> V_193 . V_490 = NULL ;
} else
V_4 -> V_193 . V_490 = F_219 ;
V_4 -> V_193 . V_990 = F_436 ;
} else if ( F_9 ( V_2 ) ) {
V_4 -> V_193 . V_490 = F_225 ;
V_4 -> V_193 . V_990 = F_432 ;
} else if ( F_451 ( V_2 ) ) {
V_4 -> V_193 . V_490 = F_228 ;
if ( F_116 ( V_2 ) )
V_4 -> V_193 . V_990 = F_434 ;
else if ( F_115 ( V_2 ) )
V_4 -> V_193 . V_990 = F_435 ;
} else if ( F_374 ( V_2 ) ) {
V_4 -> V_193 . V_490 = F_229 ;
V_4 -> V_193 . V_453 = F_214 ;
V_4 -> V_193 . V_990 = F_436 ;
} else if ( F_282 ( V_2 ) ) {
V_4 -> V_193 . V_490 = F_232 ;
V_4 -> V_193 . V_990 = F_437 ;
V_4 -> V_193 . V_453 = F_217 ;
} else if ( F_450 ( V_2 ) ) {
V_4 -> V_193 . V_490 = F_229 ;
V_4 -> V_193 . V_453 = F_215 ;
V_4 -> V_193 . V_990 = F_437 ;
} else {
V_4 -> V_193 . V_490 = F_232 ;
V_4 -> V_193 . V_990 = F_438 ;
if ( F_281 ( V_2 ) )
V_4 -> V_193 . V_453 = F_216 ;
else
V_4 -> V_193 . V_453 = F_217 ;
}
V_4 -> V_193 . V_741 = F_361 ;
switch ( F_27 ( V_2 ) -> V_69 ) {
case 2 :
V_4 -> V_193 . V_741 = F_349 ;
break;
case 3 :
V_4 -> V_193 . V_741 = F_354 ;
break;
case 4 :
case 5 :
V_4 -> V_193 . V_741 = F_355 ;
break;
case 6 :
V_4 -> V_193 . V_741 = F_356 ;
break;
case 7 :
V_4 -> V_193 . V_741 = F_357 ;
break;
}
}
static void F_452 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_115 |= V_116 ;
F_322 ( L_164 ) ;
}
static void F_453 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_115 |= V_493 ;
}
static void F_454 ( struct V_1 * V_2 )
{
struct V_994 * V_995 = V_2 -> V_345 ;
int V_99 ;
for ( V_99 = 0 ; V_99 < F_212 ( V_996 ) ; V_99 ++ ) {
struct V_997 * V_998 = & V_996 [ V_99 ] ;
if ( V_995 -> V_999 == V_998 -> V_999 &&
( V_995 -> V_1000 == V_998 -> V_1000 ||
V_998 -> V_1000 == V_1001 ) &&
( V_995 -> V_1002 == V_998 -> V_1002 ||
V_998 -> V_1002 == V_1001 ) )
V_998 -> V_1003 ( V_2 ) ;
}
}
static void F_455 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_7 V_1004 ;
T_1 V_1005 ;
if ( F_8 ( V_2 ) )
V_1005 = V_1006 ;
else
V_1005 = V_1007 ;
F_456 ( V_2 -> V_345 , V_1008 ) ;
F_457 ( 1 , V_1009 ) ;
V_1004 = F_458 ( V_1010 ) ;
F_457 ( V_1004 | 1 << 5 , V_1010 ) ;
F_459 ( V_2 -> V_345 , V_1008 ) ;
F_67 ( 300 ) ;
F_23 ( V_1005 , V_1011 ) ;
F_66 ( V_1005 ) ;
}
void F_460 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_99 ;
F_461 ( V_2 ) ;
V_2 -> V_49 . V_1012 = 0 ;
V_2 -> V_49 . V_1013 = 0 ;
V_2 -> V_49 . V_663 = ( void * ) & V_1014 ;
F_454 ( V_2 ) ;
F_447 ( V_2 ) ;
if ( F_11 ( V_2 ) ) {
V_2 -> V_49 . V_1015 = 2048 ;
V_2 -> V_49 . V_1016 = 2048 ;
} else if ( F_374 ( V_2 ) ) {
V_2 -> V_49 . V_1015 = 4096 ;
V_2 -> V_49 . V_1016 = 4096 ;
} else {
V_2 -> V_49 . V_1015 = 8192 ;
V_2 -> V_49 . V_1016 = 8192 ;
}
V_2 -> V_49 . V_1017 = V_2 -> V_1018 -> V_52 ;
F_25 ( L_165 ,
V_4 -> V_1019 , V_4 -> V_1019 > 1 ? L_166 : L_167 ) ;
for ( V_99 = 0 ; V_99 < V_4 -> V_1019 ; V_99 ++ ) {
F_371 ( V_2 , V_99 ) ;
}
F_455 ( V_2 ) ;
F_382 ( V_2 ) ;
F_446 ( V_2 ) ;
if ( F_428 ( V_2 ) ) {
F_411 ( V_2 ) ;
F_421 ( V_2 ) ;
}
if ( F_104 ( V_2 ) )
F_422 ( V_4 ) ;
F_363 ( & V_4 -> V_695 , F_324 ) ;
F_376 ( & V_4 -> V_691 , F_317 ,
( unsigned long ) V_2 ) ;
}
void F_462 ( struct V_1 * V_2 )
{
if ( F_428 ( V_2 ) )
F_444 ( V_2 ) ;
F_463 ( V_2 ) ;
}
void F_464 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 ;
struct V_131 * V_131 ;
F_465 ( V_2 ) ;
F_128 ( & V_2 -> V_245 ) ;
F_466 () ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_9 -> V_126 )
continue;
V_131 = F_93 ( V_9 ) ;
F_126 ( V_9 ) ;
}
if ( V_4 -> V_193 . V_196 )
V_4 -> V_193 . V_196 ( V_2 ) ;
if ( F_428 ( V_2 ) )
F_415 ( V_2 ) ;
if ( F_104 ( V_2 ) )
F_417 ( V_2 ) ;
if ( F_428 ( V_2 ) )
F_442 ( V_2 ) ;
F_129 ( & V_2 -> V_245 ) ;
F_467 ( V_2 ) ;
F_331 ( & V_4 -> V_1020 ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
V_131 = F_93 ( V_9 ) ;
F_468 ( & V_131 -> V_691 ) ;
}
F_468 ( & V_4 -> V_691 ) ;
F_331 ( & V_4 -> V_695 ) ;
F_469 ( V_2 ) ;
}
struct V_337 * F_470 ( struct V_653 * V_654 )
{
return & F_471 ( V_654 ) -> V_52 ;
}
void F_472 ( struct V_1021 * V_654 ,
struct V_50 * V_51 )
{
V_654 -> V_51 = V_51 ;
F_473 ( & V_654 -> V_52 ,
& V_51 -> V_52 ) ;
}
int F_474 ( struct V_1 * V_2 , bool V_77 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_1022 ;
F_203 ( V_4 -> V_1023 , V_1024 , & V_1022 ) ;
if ( V_77 )
V_1022 &= ~ V_1025 ;
else
V_1022 |= V_1025 ;
F_475 ( V_4 -> V_1023 , V_1024 , V_1022 ) ;
return 0 ;
}
struct V_1026 *
F_476 ( struct V_1 * V_2 )
{
T_6 * V_4 = V_2 -> V_5 ;
struct V_1026 * error ;
int V_99 ;
error = F_477 ( sizeof( * error ) , V_1027 ) ;
if ( error == NULL )
return NULL ;
for ( V_99 = 0 ; V_99 < 2 ; V_99 ++ ) {
error -> V_413 [ V_99 ] . V_1028 = F_3 ( F_278 ( V_99 ) ) ;
error -> V_413 [ V_99 ] . V_1029 = F_3 ( F_280 ( V_99 ) ) ;
error -> V_413 [ V_99 ] . V_52 = F_3 ( F_279 ( V_99 ) ) ;
error -> V_97 [ V_99 ] . V_1028 = F_3 ( F_49 ( V_99 ) ) ;
error -> V_97 [ V_99 ] . V_1030 = F_3 ( F_123 ( V_99 ) ) ;
error -> V_97 [ V_99 ] . V_205 = F_3 ( F_254 ( V_99 ) ) ;
error -> V_97 [ V_99 ] . V_614 = F_3 ( F_255 ( V_99 ) ) ;
error -> V_97 [ V_99 ] . V_626 = F_3 ( F_86 ( V_99 ) ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
error -> V_97 [ V_99 ] . V_1031 = F_3 ( F_124 ( V_99 ) ) ;
error -> V_97 [ V_99 ] . V_1032 = F_3 ( F_125 ( V_99 ) ) ;
}
error -> V_66 [ V_99 ] . V_1033 = F_3 ( F_28 ( V_99 ) ) ;
error -> V_66 [ V_99 ] . V_1034 = F_3 ( F_256 ( V_99 ) ) ;
error -> V_66 [ V_99 ] . V_417 = F_3 ( F_157 ( V_99 ) ) ;
error -> V_66 [ V_99 ] . V_1035 = F_3 ( F_159 ( V_99 ) ) ;
error -> V_66 [ V_99 ] . V_681 = F_3 ( F_161 ( V_99 ) ) ;
error -> V_66 [ V_99 ] . V_686 = F_3 ( F_163 ( V_99 ) ) ;
error -> V_66 [ V_99 ] . V_1036 = F_3 ( F_165 ( V_99 ) ) ;
error -> V_66 [ V_99 ] . V_683 = F_3 ( F_167 ( V_99 ) ) ;
}
return error ;
}
void
F_478 ( struct V_1037 * V_39 ,
struct V_1 * V_2 ,
struct V_1026 * error )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < 2 ; V_99 ++ ) {
F_479 ( V_39 , L_168 , V_99 ) ;
F_479 ( V_39 , L_169 , error -> V_66 [ V_99 ] . V_1033 ) ;
F_479 ( V_39 , L_170 , error -> V_66 [ V_99 ] . V_1034 ) ;
F_479 ( V_39 , L_171 , error -> V_66 [ V_99 ] . V_417 ) ;
F_479 ( V_39 , L_172 , error -> V_66 [ V_99 ] . V_1035 ) ;
F_479 ( V_39 , L_173 , error -> V_66 [ V_99 ] . V_681 ) ;
F_479 ( V_39 , L_174 , error -> V_66 [ V_99 ] . V_686 ) ;
F_479 ( V_39 , L_175 , error -> V_66 [ V_99 ] . V_1036 ) ;
F_479 ( V_39 , L_176 , error -> V_66 [ V_99 ] . V_683 ) ;
F_479 ( V_39 , L_177 , V_99 ) ;
F_479 ( V_39 , L_178 , error -> V_97 [ V_99 ] . V_1028 ) ;
F_479 ( V_39 , L_179 , error -> V_97 [ V_99 ] . V_1030 ) ;
F_479 ( V_39 , L_180 , error -> V_97 [ V_99 ] . V_205 ) ;
F_479 ( V_39 , L_181 , error -> V_97 [ V_99 ] . V_614 ) ;
F_479 ( V_39 , L_182 , error -> V_97 [ V_99 ] . V_626 ) ;
if ( F_27 ( V_2 ) -> V_69 >= 4 ) {
F_479 ( V_39 , L_183 , error -> V_97 [ V_99 ] . V_1031 ) ;
F_479 ( V_39 , L_184 , error -> V_97 [ V_99 ] . V_1032 ) ;
}
F_479 ( V_39 , L_185 , V_99 ) ;
F_479 ( V_39 , L_178 , error -> V_413 [ V_99 ] . V_1028 ) ;
F_479 ( V_39 , L_181 , error -> V_413 [ V_99 ] . V_1029 ) ;
F_479 ( V_39 , L_186 , error -> V_413 [ V_99 ] . V_52 ) ;
}
}
