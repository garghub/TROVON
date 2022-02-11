static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 ;
}
static int F_2 ( struct V_5 * V_6 )
{
int V_7 , V_8 [] = { 800 , 1600 , 2000 , 2400 } ;
F_3 ( & V_6 -> V_9 ) ;
V_7 = F_4 ( V_6 , V_10 ) &
V_11 ;
F_5 ( & V_6 -> V_9 ) ;
return V_8 [ V_7 ] * 1000 ;
}
int F_6 ( struct V_5 * V_6 ,
const char * V_12 , T_1 V_13 , int V_14 )
{
T_1 V_15 ;
int V_16 ;
F_3 ( & V_6 -> V_9 ) ;
V_15 = F_4 ( V_6 , V_13 ) ;
F_5 ( & V_6 -> V_9 ) ;
V_16 = V_15 & V_17 ;
F_7 ( ( V_15 & V_18 ) !=
( V_16 << V_19 ) ,
L_1 , V_12 ) ;
return F_8 ( V_14 << 1 , V_16 + 1 ) ;
}
static int F_9 ( struct V_5 * V_6 ,
const char * V_12 , T_1 V_13 )
{
if ( V_6 -> V_7 == 0 )
V_6 -> V_7 = F_2 ( V_6 ) ;
return F_6 ( V_6 , V_12 , V_13 ,
V_6 -> V_7 ) ;
}
static int
F_10 ( struct V_5 * V_6 )
{
return ( F_11 ( V_20 ) & V_21 ) * 1000 ;
}
static int
F_12 ( struct V_5 * V_6 )
{
return F_9 ( V_6 , L_2 ,
V_22 ) ;
}
static int
F_13 ( struct V_5 * V_6 )
{
T_2 V_23 ;
V_23 = F_11 ( V_24 ) ;
switch ( V_23 & V_25 ) {
case V_26 :
return 100000 ;
case V_27 :
return 133333 ;
case V_28 :
return 166667 ;
case V_29 :
return 200000 ;
case V_30 :
return 266667 ;
case V_31 :
return 333333 ;
case V_32 :
case V_33 :
return 400000 ;
default:
return 133333 ;
}
}
void F_14 ( struct V_5 * V_6 )
{
if ( F_15 ( V_6 ) )
V_6 -> V_34 = F_10 ( V_6 ) ;
else if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
V_6 -> V_34 = F_12 ( V_6 ) ;
else if ( F_18 ( V_6 ) || F_19 ( V_6 ) )
V_6 -> V_34 = F_13 ( V_6 ) ;
else
return;
F_20 ( L_3 , V_6 -> V_34 ) ;
}
static void F_21 ( struct V_5 * V_6 )
{
if ( ! ( F_16 ( V_6 ) || F_17 ( V_6 ) ) )
return;
V_6 -> V_35 = F_9 ( V_6 , L_4 ,
V_36 ) ;
F_20 ( L_5 , V_6 -> V_35 ) ;
}
static inline T_1
F_22 ( struct V_5 * V_6 ,
const struct V_37 * V_38 )
{
if ( F_23 ( V_6 ) )
return V_38 -> V_39 ;
else if ( F_24 ( V_6 ) )
return ( ( F_11 ( V_40 ) & V_41 ) + 2 ) * 10000 ;
else
return 270000 ;
}
static bool
F_25 ( struct V_42 * V_43 )
{
return F_26 ( V_43 ) ;
}
static int F_27 ( int V_44 , struct V_45 * clock )
{
clock -> V_46 = clock -> V_47 + 2 ;
clock -> V_48 = clock -> V_49 * clock -> V_50 ;
if ( F_28 ( clock -> V_51 == 0 || clock -> V_48 == 0 ) )
return 0 ;
clock -> V_52 = F_8 ( V_44 * clock -> V_46 , clock -> V_51 ) ;
clock -> V_53 = F_8 ( clock -> V_52 , clock -> V_48 ) ;
return clock -> V_53 ;
}
static T_2 F_29 ( struct V_45 * V_45 )
{
return 5 * ( V_45 -> V_54 + 2 ) + ( V_45 -> V_47 + 2 ) ;
}
static int F_30 ( int V_44 , struct V_45 * clock )
{
clock -> V_46 = F_29 ( clock ) ;
clock -> V_48 = clock -> V_49 * clock -> V_50 ;
if ( F_28 ( clock -> V_51 + 2 == 0 || clock -> V_48 == 0 ) )
return 0 ;
clock -> V_52 = F_8 ( V_44 * clock -> V_46 , clock -> V_51 + 2 ) ;
clock -> V_53 = F_8 ( clock -> V_52 , clock -> V_48 ) ;
return clock -> V_53 ;
}
static int F_31 ( int V_44 , struct V_45 * clock )
{
clock -> V_46 = clock -> V_54 * clock -> V_47 ;
clock -> V_48 = clock -> V_49 * clock -> V_50 ;
if ( F_28 ( clock -> V_51 == 0 || clock -> V_48 == 0 ) )
return 0 ;
clock -> V_52 = F_8 ( V_44 * clock -> V_46 , clock -> V_51 ) ;
clock -> V_53 = F_8 ( clock -> V_52 , clock -> V_48 ) ;
return clock -> V_53 / 5 ;
}
int F_32 ( int V_44 , struct V_45 * clock )
{
clock -> V_46 = clock -> V_54 * clock -> V_47 ;
clock -> V_48 = clock -> V_49 * clock -> V_50 ;
if ( F_28 ( clock -> V_51 == 0 || clock -> V_48 == 0 ) )
return 0 ;
clock -> V_52 = F_33 ( ( V_55 ) V_44 * clock -> V_46 ,
clock -> V_51 << 22 ) ;
clock -> V_53 = F_8 ( clock -> V_52 , clock -> V_48 ) ;
return clock -> V_53 / 5 ;
}
static bool F_34 ( struct V_56 * V_57 ,
const struct V_58 * V_59 ,
const struct V_45 * clock )
{
if ( clock -> V_51 < V_59 -> V_51 . V_60 || V_59 -> V_51 . V_61 < clock -> V_51 )
F_35 ( L_6 ) ;
if ( clock -> V_49 < V_59 -> V_49 . V_60 || V_59 -> V_49 . V_61 < clock -> V_49 )
F_35 ( L_7 ) ;
if ( clock -> V_47 < V_59 -> V_47 . V_60 || V_59 -> V_47 . V_61 < clock -> V_47 )
F_35 ( L_8 ) ;
if ( clock -> V_54 < V_59 -> V_54 . V_60 || V_59 -> V_54 . V_61 < clock -> V_54 )
F_35 ( L_9 ) ;
if ( ! F_19 ( V_57 ) && ! F_16 ( V_57 ) &&
! F_17 ( V_57 ) && ! F_36 ( V_57 ) )
if ( clock -> V_54 <= clock -> V_47 )
F_35 ( L_10 ) ;
if ( ! F_16 ( V_57 ) && ! F_17 ( V_57 ) && ! F_36 ( V_57 ) ) {
if ( clock -> V_48 < V_59 -> V_48 . V_60 || V_59 -> V_48 . V_61 < clock -> V_48 )
F_35 ( L_11 ) ;
if ( clock -> V_46 < V_59 -> V_46 . V_60 || V_59 -> V_46 . V_61 < clock -> V_46 )
F_35 ( L_12 ) ;
}
if ( clock -> V_52 < V_59 -> V_52 . V_60 || V_59 -> V_52 . V_61 < clock -> V_52 )
F_35 ( L_13 ) ;
if ( clock -> V_53 < V_59 -> V_53 . V_60 || V_59 -> V_53 . V_61 < clock -> V_53 )
F_35 ( L_14 ) ;
return true ;
}
static int
F_37 ( const struct V_58 * V_59 ,
const struct V_37 * V_62 ,
int V_63 )
{
struct V_56 * V_57 = V_62 -> V_64 . V_65 -> V_57 ;
if ( F_38 ( V_62 , V_66 ) ) {
if ( F_39 ( V_57 ) )
return V_59 -> V_50 . V_67 ;
else
return V_59 -> V_50 . V_68 ;
} else {
if ( V_63 < V_59 -> V_50 . V_69 )
return V_59 -> V_50 . V_68 ;
else
return V_59 -> V_50 . V_67 ;
}
}
static bool
F_40 ( const struct V_58 * V_59 ,
struct V_37 * V_62 ,
int V_63 , int V_44 , struct V_45 * V_70 ,
struct V_45 * V_71 )
{
struct V_56 * V_57 = V_62 -> V_64 . V_65 -> V_57 ;
struct V_45 clock ;
int V_72 = V_63 ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
clock . V_50 = F_37 ( V_59 , V_62 , V_63 ) ;
for ( clock . V_54 = V_59 -> V_54 . V_60 ; clock . V_54 <= V_59 -> V_54 . V_61 ;
clock . V_54 ++ ) {
for ( clock . V_47 = V_59 -> V_47 . V_60 ;
clock . V_47 <= V_59 -> V_47 . V_61 ; clock . V_47 ++ ) {
if ( clock . V_47 >= clock . V_54 )
break;
for ( clock . V_51 = V_59 -> V_51 . V_60 ;
clock . V_51 <= V_59 -> V_51 . V_61 ; clock . V_51 ++ ) {
for ( clock . V_49 = V_59 -> V_49 . V_60 ;
clock . V_49 <= V_59 -> V_49 . V_61 ; clock . V_49 ++ ) {
int V_73 ;
F_30 ( V_44 , & clock ) ;
if ( ! F_34 ( V_57 , V_59 ,
& clock ) )
continue;
if ( V_70 &&
clock . V_48 != V_70 -> V_48 )
continue;
V_73 = abs ( clock . V_53 - V_63 ) ;
if ( V_73 < V_72 ) {
* V_71 = clock ;
V_72 = V_73 ;
}
}
}
}
}
return ( V_72 != V_63 ) ;
}
static bool
F_41 ( const struct V_58 * V_59 ,
struct V_37 * V_62 ,
int V_63 , int V_44 , struct V_45 * V_70 ,
struct V_45 * V_71 )
{
struct V_56 * V_57 = V_62 -> V_64 . V_65 -> V_57 ;
struct V_45 clock ;
int V_72 = V_63 ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
clock . V_50 = F_37 ( V_59 , V_62 , V_63 ) ;
for ( clock . V_54 = V_59 -> V_54 . V_60 ; clock . V_54 <= V_59 -> V_54 . V_61 ;
clock . V_54 ++ ) {
for ( clock . V_47 = V_59 -> V_47 . V_60 ;
clock . V_47 <= V_59 -> V_47 . V_61 ; clock . V_47 ++ ) {
for ( clock . V_51 = V_59 -> V_51 . V_60 ;
clock . V_51 <= V_59 -> V_51 . V_61 ; clock . V_51 ++ ) {
for ( clock . V_49 = V_59 -> V_49 . V_60 ;
clock . V_49 <= V_59 -> V_49 . V_61 ; clock . V_49 ++ ) {
int V_73 ;
F_27 ( V_44 , & clock ) ;
if ( ! F_34 ( V_57 , V_59 ,
& clock ) )
continue;
if ( V_70 &&
clock . V_48 != V_70 -> V_48 )
continue;
V_73 = abs ( clock . V_53 - V_63 ) ;
if ( V_73 < V_72 ) {
* V_71 = clock ;
V_72 = V_73 ;
}
}
}
}
}
return ( V_72 != V_63 ) ;
}
static bool
F_42 ( const struct V_58 * V_59 ,
struct V_37 * V_62 ,
int V_63 , int V_44 , struct V_45 * V_70 ,
struct V_45 * V_71 )
{
struct V_56 * V_57 = V_62 -> V_64 . V_65 -> V_57 ;
struct V_45 clock ;
int V_74 ;
bool V_75 = false ;
int V_76 = ( V_63 >> 8 ) + ( V_63 >> 9 ) ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
clock . V_50 = F_37 ( V_59 , V_62 , V_63 ) ;
V_74 = V_59 -> V_51 . V_61 ;
for ( clock . V_51 = V_59 -> V_51 . V_60 ; clock . V_51 <= V_74 ; clock . V_51 ++ ) {
for ( clock . V_54 = V_59 -> V_54 . V_61 ;
clock . V_54 >= V_59 -> V_54 . V_60 ; clock . V_54 -- ) {
for ( clock . V_47 = V_59 -> V_47 . V_61 ;
clock . V_47 >= V_59 -> V_47 . V_60 ; clock . V_47 -- ) {
for ( clock . V_49 = V_59 -> V_49 . V_61 ;
clock . V_49 >= V_59 -> V_49 . V_60 ; clock . V_49 -- ) {
int V_73 ;
F_30 ( V_44 , & clock ) ;
if ( ! F_34 ( V_57 , V_59 ,
& clock ) )
continue;
V_73 = abs ( clock . V_53 - V_63 ) ;
if ( V_73 < V_76 ) {
* V_71 = clock ;
V_76 = V_73 ;
V_74 = clock . V_51 ;
V_75 = true ;
}
}
}
}
}
return V_75 ;
}
static bool F_43 ( struct V_56 * V_57 , int V_77 ,
const struct V_45 * V_78 ,
const struct V_45 * V_71 ,
unsigned int V_79 ,
unsigned int * V_80 )
{
if ( F_17 ( V_57 ) ) {
* V_80 = 0 ;
return V_78 -> V_48 > V_71 -> V_48 ;
}
if ( F_44 ( ! V_77 ) )
return false ;
* V_80 = F_45 ( 1000000ULL *
abs ( V_77 - V_78 -> V_53 ) ,
V_77 ) ;
if ( * V_80 < 100 && V_78 -> V_48 > V_71 -> V_48 ) {
* V_80 = 0 ;
return true ;
}
return * V_80 + 10 < V_79 ;
}
static bool
F_46 ( const struct V_58 * V_59 ,
struct V_37 * V_62 ,
int V_63 , int V_44 , struct V_45 * V_70 ,
struct V_45 * V_71 )
{
struct V_81 * V_65 = F_47 ( V_62 -> V_64 . V_65 ) ;
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_45 clock ;
unsigned int V_82 = 1000000 ;
int V_74 = V_60 ( V_59 -> V_51 . V_61 , V_44 / 19200 ) ;
bool V_75 = false ;
V_63 *= 5 ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
for ( clock . V_51 = V_59 -> V_51 . V_60 ; clock . V_51 <= V_74 ; clock . V_51 ++ ) {
for ( clock . V_49 = V_59 -> V_49 . V_61 ; clock . V_49 >= V_59 -> V_49 . V_60 ; clock . V_49 -- ) {
for ( clock . V_50 = V_59 -> V_50 . V_67 ; clock . V_50 >= V_59 -> V_50 . V_68 ;
clock . V_50 -= clock . V_50 > 10 ? 2 : 1 ) {
clock . V_48 = clock . V_49 * clock . V_50 ;
for ( clock . V_54 = V_59 -> V_54 . V_60 ; clock . V_54 <= V_59 -> V_54 . V_61 ; clock . V_54 ++ ) {
unsigned int V_83 ;
clock . V_47 = F_8 ( V_63 * clock . V_48 * clock . V_51 ,
V_44 * clock . V_54 ) ;
F_31 ( V_44 , & clock ) ;
if ( ! F_34 ( V_57 , V_59 ,
& clock ) )
continue;
if ( ! F_43 ( V_57 , V_63 ,
& clock ,
V_71 ,
V_82 , & V_83 ) )
continue;
* V_71 = clock ;
V_82 = V_83 ;
V_75 = true ;
}
}
}
}
return V_75 ;
}
static bool
F_48 ( const struct V_58 * V_59 ,
struct V_37 * V_62 ,
int V_63 , int V_44 , struct V_45 * V_70 ,
struct V_45 * V_71 )
{
struct V_81 * V_65 = F_47 ( V_62 -> V_64 . V_65 ) ;
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
unsigned int V_79 ;
struct V_45 clock ;
V_55 V_47 ;
int V_75 = false ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
V_79 = 1000000 ;
clock . V_51 = 1 , clock . V_54 = 2 ;
V_63 *= 5 ;
for ( clock . V_49 = V_59 -> V_49 . V_61 ; clock . V_49 >= V_59 -> V_49 . V_60 ; clock . V_49 -- ) {
for ( clock . V_50 = V_59 -> V_50 . V_67 ;
clock . V_50 >= V_59 -> V_50 . V_68 ;
clock . V_50 -= clock . V_50 > 10 ? 2 : 1 ) {
unsigned int V_80 ;
clock . V_48 = clock . V_49 * clock . V_50 ;
V_47 = F_33 ( ( ( V_55 ) V_63 * clock . V_48 *
clock . V_51 ) << 22 , V_44 * clock . V_54 ) ;
if ( V_47 > V_84 / clock . V_54 )
continue;
clock . V_47 = V_47 ;
F_32 ( V_44 , & clock ) ;
if ( ! F_34 ( V_57 , V_59 , & clock ) )
continue;
if ( ! F_43 ( V_57 , V_63 , & clock , V_71 ,
V_79 , & V_80 ) )
continue;
* V_71 = clock ;
V_79 = V_80 ;
V_75 = true ;
}
}
return V_75 ;
}
bool F_49 ( struct V_37 * V_62 , int V_85 ,
struct V_45 * V_71 )
{
int V_44 = 100000 ;
const struct V_58 * V_59 = & V_86 ;
return F_48 ( V_59 , V_62 ,
V_85 , V_44 , NULL , V_71 ) ;
}
bool F_50 ( struct V_87 * V_65 )
{
struct V_81 * V_81 = F_47 ( V_65 ) ;
return V_81 -> V_88 && V_65 -> V_89 -> V_43 -> V_90 &&
V_81 -> V_91 -> V_64 . V_92 . V_93 ;
}
enum V_94 F_51 ( struct V_5 * V_6 ,
enum V_95 V_95 )
{
struct V_87 * V_65 = V_6 -> V_96 [ V_95 ] ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
return V_81 -> V_91 -> V_97 ;
}
static bool F_52 ( struct V_56 * V_57 , enum V_95 V_95 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_3 V_13 = F_54 ( V_95 ) ;
T_1 V_98 , V_99 ;
T_1 V_100 ;
if ( F_55 ( V_57 ) )
V_100 = V_101 ;
else
V_100 = V_102 ;
V_98 = F_11 ( V_13 ) & V_100 ;
F_56 ( 5 ) ;
V_99 = F_11 ( V_13 ) & V_100 ;
return V_98 == V_99 ;
}
static void F_57 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_94 V_97 = V_65 -> V_91 -> V_97 ;
enum V_95 V_95 = V_65 -> V_95 ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
T_3 V_13 = F_59 ( V_97 ) ;
if ( F_60 ( V_6 ,
V_13 , V_104 , 0 ,
100 ) )
F_7 ( 1 , L_15 ) ;
} else {
if ( F_61 ( F_52 ( V_57 , V_95 ) , 100 ) )
F_7 ( 1 , L_15 ) ;
}
}
void F_62 ( struct V_5 * V_6 ,
enum V_95 V_95 , bool V_43 )
{
T_1 V_15 ;
bool V_105 ;
V_15 = F_11 ( F_63 ( V_95 ) ) ;
V_105 = ! ! ( V_15 & V_106 ) ;
F_64 ( V_105 != V_43 ,
L_16 ,
F_65 ( V_43 ) , F_65 ( V_105 ) ) ;
}
void F_66 ( struct V_5 * V_6 , bool V_43 )
{
T_1 V_15 ;
bool V_105 ;
F_3 ( & V_6 -> V_9 ) ;
V_15 = F_4 ( V_6 , V_107 ) ;
F_5 ( & V_6 -> V_9 ) ;
V_105 = V_15 & V_108 ;
F_64 ( V_105 != V_43 ,
L_17 ,
F_65 ( V_43 ) , F_65 ( V_105 ) ) ;
}
static void F_67 ( struct V_5 * V_6 ,
enum V_95 V_95 , bool V_43 )
{
bool V_105 ;
enum V_94 V_97 = F_51 ( V_6 ,
V_95 ) ;
if ( F_23 ( V_6 ) ) {
T_1 V_15 = F_11 ( F_68 ( V_97 ) ) ;
V_105 = ! ! ( V_15 & V_109 ) ;
} else {
T_1 V_15 = F_11 ( F_69 ( V_95 ) ) ;
V_105 = ! ! ( V_15 & V_110 ) ;
}
F_64 ( V_105 != V_43 ,
L_18 ,
F_65 ( V_43 ) , F_65 ( V_105 ) ) ;
}
static void F_70 ( struct V_5 * V_6 ,
enum V_95 V_95 , bool V_43 )
{
T_1 V_15 ;
bool V_105 ;
V_15 = F_11 ( F_71 ( V_95 ) ) ;
V_105 = ! ! ( V_15 & V_111 ) ;
F_64 ( V_105 != V_43 ,
L_19 ,
F_65 ( V_43 ) , F_65 ( V_105 ) ) ;
}
static void F_72 ( struct V_5 * V_6 ,
enum V_95 V_95 )
{
T_1 V_15 ;
if ( F_24 ( V_6 ) )
return;
if ( F_23 ( V_6 ) )
return;
V_15 = F_11 ( F_69 ( V_95 ) ) ;
F_64 ( ! ( V_15 & V_112 ) , L_20 ) ;
}
void F_73 ( struct V_5 * V_6 ,
enum V_95 V_95 , bool V_43 )
{
T_1 V_15 ;
bool V_105 ;
V_15 = F_11 ( F_71 ( V_95 ) ) ;
V_105 = ! ! ( V_15 & V_113 ) ;
F_64 ( V_105 != V_43 ,
L_21 ,
F_65 ( V_43 ) , F_65 ( V_105 ) ) ;
}
void F_74 ( struct V_5 * V_6 ,
enum V_95 V_95 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
T_3 V_115 ;
T_1 V_15 ;
enum V_95 V_116 = V_117 ;
bool V_118 = true ;
if ( F_28 ( F_23 ( V_57 ) ) )
return;
if ( F_15 ( V_57 ) ) {
T_1 V_119 ;
V_115 = V_120 ;
V_119 = F_11 ( V_121 ) & V_122 ;
if ( V_119 == V_123 &&
F_11 ( V_124 ) & V_125 )
V_116 = V_126 ;
} else if ( F_16 ( V_57 ) || F_17 ( V_57 ) ) {
V_115 = F_75 ( V_95 ) ;
V_116 = V_95 ;
} else {
V_115 = V_127 ;
if ( F_11 ( V_128 ) & V_125 )
V_116 = V_126 ;
}
V_15 = F_11 ( V_115 ) ;
if ( ! ( V_15 & V_129 ) ||
( ( V_15 & V_130 ) == V_131 ) )
V_118 = false ;
F_64 ( V_116 == V_95 && V_118 ,
L_22 ,
F_76 ( V_95 ) ) ;
}
static void F_77 ( struct V_5 * V_6 ,
enum V_95 V_95 , bool V_43 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
bool V_105 ;
if ( F_78 ( V_57 ) || F_79 ( V_57 ) )
V_105 = F_11 ( F_80 ( V_117 ) ) & V_132 ;
else
V_105 = F_11 ( F_80 ( V_95 ) ) & V_133 ;
F_64 ( V_105 != V_43 ,
L_23 ,
F_76 ( V_95 ) , F_65 ( V_43 ) , F_65 ( V_105 ) ) ;
}
void F_81 ( struct V_5 * V_6 ,
enum V_95 V_95 , bool V_43 )
{
bool V_105 ;
enum V_94 V_97 = F_51 ( V_6 ,
V_95 ) ;
enum V_134 V_135 ;
if ( ( V_95 == V_117 && V_6 -> V_136 & V_137 ) ||
( V_95 == V_126 && V_6 -> V_136 & V_138 ) )
V_43 = true ;
V_135 = F_82 ( V_97 ) ;
if ( F_83 ( V_6 , V_135 ) ) {
T_1 V_15 = F_11 ( F_59 ( V_97 ) ) ;
V_105 = ! ! ( V_15 & V_139 ) ;
F_84 ( V_6 , V_135 ) ;
} else {
V_105 = false ;
}
F_64 ( V_105 != V_43 ,
L_24 ,
F_76 ( V_95 ) , F_65 ( V_43 ) , F_65 ( V_105 ) ) ;
}
static void F_85 ( struct V_5 * V_6 ,
enum V_140 V_140 , bool V_43 )
{
T_1 V_15 ;
bool V_105 ;
V_15 = F_11 ( F_86 ( V_140 ) ) ;
V_105 = ! ! ( V_15 & V_141 ) ;
F_64 ( V_105 != V_43 ,
L_25 ,
F_87 ( V_140 ) , F_65 ( V_43 ) , F_65 ( V_105 ) ) ;
}
static void F_88 ( struct V_5 * V_6 ,
enum V_95 V_95 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
int V_142 ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
T_1 V_15 = F_11 ( F_86 ( V_95 ) ) ;
F_64 ( V_15 & V_141 ,
L_26 ,
F_87 ( V_95 ) ) ;
return;
}
F_89 (dev_priv, i) {
T_1 V_15 = F_11 ( F_86 ( V_142 ) ) ;
enum V_95 V_143 = ( V_15 & V_144 ) >>
V_145 ;
F_64 ( ( V_15 & V_141 ) && V_95 == V_143 ,
L_27 ,
F_87 ( V_142 ) , F_76 ( V_95 ) ) ;
}
}
static void F_90 ( struct V_5 * V_6 ,
enum V_95 V_95 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
int V_146 ;
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
F_91 (dev_priv, pipe, sprite) {
T_1 V_15 = F_11 ( F_92 ( V_95 , V_146 ) ) ;
F_64 ( V_15 & V_147 ,
L_28 ,
V_146 , F_76 ( V_95 ) ) ;
}
} else if ( F_16 ( V_57 ) || F_17 ( V_57 ) ) {
F_91 (dev_priv, pipe, sprite) {
T_1 V_15 = F_11 ( F_93 ( V_95 , V_146 ) ) ;
F_64 ( V_15 & V_148 ,
L_29 ,
F_94 ( V_95 , V_146 ) , F_76 ( V_95 ) ) ;
}
} else if ( F_58 ( V_57 ) -> V_103 >= 7 ) {
T_1 V_15 = F_11 ( F_95 ( V_95 ) ) ;
F_64 ( V_15 & V_149 ,
L_29 ,
F_87 ( V_95 ) , F_76 ( V_95 ) ) ;
} else if ( F_58 ( V_57 ) -> V_103 >= 5 ) {
T_1 V_15 = F_11 ( F_96 ( V_95 ) ) ;
F_64 ( V_15 & V_150 ,
L_29 ,
F_87 ( V_95 ) , F_76 ( V_95 ) ) ;
}
}
static void F_97 ( struct V_87 * V_65 )
{
if ( F_98 ( F_99 ( V_65 ) == 0 ) )
F_100 ( V_65 ) ;
}
void F_101 ( struct V_5 * V_6 ,
enum V_95 V_95 )
{
T_1 V_15 ;
bool V_151 ;
V_15 = F_11 ( F_102 ( V_95 ) ) ;
V_151 = ! ! ( V_15 & V_152 ) ;
F_64 ( V_151 ,
L_30 ,
F_76 ( V_95 ) ) ;
}
static bool F_103 ( struct V_5 * V_6 ,
enum V_95 V_95 , T_1 V_119 , T_1 V_15 )
{
if ( ( V_15 & V_153 ) == 0 )
return false ;
if ( F_104 ( V_6 ) ) {
T_1 V_154 = F_11 ( F_105 ( V_95 ) ) ;
if ( ( V_154 & V_155 ) != V_119 )
return false ;
} else if ( F_17 ( V_6 ) ) {
if ( ( V_15 & V_156 ) != F_106 ( V_95 ) )
return false ;
} else {
if ( ( V_15 & V_157 ) != ( V_95 << 30 ) )
return false ;
}
return true ;
}
static bool F_107 ( struct V_5 * V_6 ,
enum V_95 V_95 , T_1 V_15 )
{
if ( ( V_15 & V_158 ) == 0 )
return false ;
if ( F_104 ( V_6 ) ) {
if ( ( V_15 & V_159 ) != F_108 ( V_95 ) )
return false ;
} else if ( F_17 ( V_6 ) ) {
if ( ( V_15 & V_160 ) != F_109 ( V_95 ) )
return false ;
} else {
if ( ( V_15 & V_161 ) != F_110 ( V_95 ) )
return false ;
}
return true ;
}
static bool F_111 ( struct V_5 * V_6 ,
enum V_95 V_95 , T_1 V_15 )
{
if ( ( V_15 & V_162 ) == 0 )
return false ;
if ( F_104 ( V_6 ) ) {
if ( ( V_15 & V_163 ) != F_112 ( V_95 ) )
return false ;
} else {
if ( ( V_15 & V_164 ) != F_113 ( V_95 ) )
return false ;
}
return true ;
}
static bool F_114 ( struct V_5 * V_6 ,
enum V_95 V_95 , T_1 V_15 )
{
if ( ( V_15 & V_165 ) == 0 )
return false ;
if ( F_104 ( V_6 ) ) {
if ( ( V_15 & V_163 ) != F_112 ( V_95 ) )
return false ;
} else {
if ( ( V_15 & V_166 ) != F_115 ( V_95 ) )
return false ;
}
return true ;
}
static void F_116 ( struct V_5 * V_6 ,
enum V_95 V_95 , T_3 V_13 ,
T_1 V_119 )
{
T_1 V_15 = F_11 ( V_13 ) ;
F_64 ( F_103 ( V_6 , V_95 , V_119 , V_15 ) ,
L_31 ,
F_117 ( V_13 ) , F_76 ( V_95 ) ) ;
F_64 ( F_118 ( V_6 ) && ( V_15 & V_153 ) == 0
&& ( V_15 & V_167 ) ,
L_32 ) ;
}
static void F_119 ( struct V_5 * V_6 ,
enum V_95 V_95 , T_3 V_13 )
{
T_1 V_15 = F_11 ( V_13 ) ;
F_64 ( F_107 ( V_6 , V_95 , V_15 ) ,
L_33 ,
F_117 ( V_13 ) , F_76 ( V_95 ) ) ;
F_64 ( F_118 ( V_6 ) && ( V_15 & V_158 ) == 0
&& ( V_15 & V_168 ) ,
L_34 ) ;
}
static void F_120 ( struct V_5 * V_6 ,
enum V_95 V_95 )
{
T_1 V_15 ;
F_116 ( V_6 , V_95 , V_169 , V_170 ) ;
F_116 ( V_6 , V_95 , V_171 , V_172 ) ;
F_116 ( V_6 , V_95 , V_173 , V_174 ) ;
V_15 = F_11 ( V_175 ) ;
F_64 ( F_114 ( V_6 , V_95 , V_15 ) ,
L_35 ,
F_76 ( V_95 ) ) ;
V_15 = F_11 ( V_124 ) ;
F_64 ( F_111 ( V_6 , V_95 , V_15 ) ,
L_36 ,
F_76 ( V_95 ) ) ;
F_119 ( V_6 , V_95 , V_176 ) ;
F_119 ( V_6 , V_95 , V_177 ) ;
F_119 ( V_6 , V_95 , V_178 ) ;
}
static void F_121 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
F_122 ( F_63 ( V_95 ) , V_38 -> V_179 . V_45 ) ;
F_123 ( F_63 ( V_95 ) ) ;
F_124 ( 150 ) ;
if ( F_60 ( V_6 ,
F_63 ( V_95 ) ,
V_180 ,
V_180 ,
1 ) )
F_125 ( L_37 , V_95 ) ;
}
static void F_126 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
F_127 ( V_6 , V_95 ) ;
F_74 ( V_6 , V_95 ) ;
if ( V_38 -> V_179 . V_45 & V_106 )
F_121 ( V_65 , V_38 ) ;
F_122 ( F_128 ( V_95 ) , V_38 -> V_179 . V_181 ) ;
F_123 ( F_128 ( V_95 ) ) ;
}
static void F_129 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
enum V_182 V_183 = F_130 ( V_95 ) ;
T_1 V_184 ;
F_3 ( & V_6 -> V_9 ) ;
V_184 = F_131 ( V_6 , V_95 , F_132 ( V_183 ) ) ;
V_184 |= V_185 ;
F_133 ( V_6 , V_95 , F_132 ( V_183 ) , V_184 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_124 ( 1 ) ;
F_122 ( F_63 ( V_95 ) , V_38 -> V_179 . V_45 ) ;
if ( F_60 ( V_6 ,
F_63 ( V_95 ) , V_180 , V_180 ,
1 ) )
F_125 ( L_38 , V_95 ) ;
}
static void F_134 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
F_127 ( V_6 , V_95 ) ;
F_74 ( V_6 , V_95 ) ;
if ( V_38 -> V_179 . V_45 & V_106 )
F_129 ( V_65 , V_38 ) ;
if ( V_95 != V_117 ) {
F_122 ( V_186 , V_95 == V_126 ? V_187 : V_188 ) ;
F_122 ( F_128 ( V_126 ) , V_38 -> V_179 . V_181 ) ;
F_122 ( V_186 , 0 ) ;
V_6 -> V_189 [ V_95 ] = V_38 -> V_179 . V_181 ;
F_28 ( ( F_11 ( F_63 ( V_126 ) ) & V_190 ) == 0 ) ;
} else {
F_122 ( F_128 ( V_95 ) , V_38 -> V_179 . V_181 ) ;
F_123 ( F_128 ( V_95 ) ) ;
}
}
static int F_135 ( struct V_56 * V_57 )
{
struct V_81 * V_65 ;
int V_191 = 0 ;
F_136 (dev, crtc) {
V_191 += V_65 -> V_64 . V_43 -> V_88 &&
F_38 ( V_65 -> V_91 , V_192 ) ;
}
return V_191 ;
}
static void F_137 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_3 V_13 = F_63 ( V_65 -> V_95 ) ;
T_1 V_45 = V_65 -> V_91 -> V_179 . V_45 ;
F_127 ( V_6 , V_65 -> V_95 ) ;
if ( F_138 ( V_57 ) && ! F_139 ( V_57 ) )
F_74 ( V_6 , V_65 -> V_95 ) ;
if ( F_139 ( V_57 ) && F_135 ( V_57 ) > 0 ) {
V_45 |= V_193 ;
F_122 ( F_63 ( ! V_65 -> V_95 ) ,
F_11 ( F_63 ( ! V_65 -> V_95 ) ) | V_193 ) ;
}
F_122 ( V_13 , 0 ) ;
F_122 ( V_13 , V_45 ) ;
F_123 ( V_13 ) ;
F_124 ( 150 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
F_122 ( F_128 ( V_65 -> V_95 ) ,
V_65 -> V_91 -> V_179 . V_181 ) ;
} else {
F_122 ( V_13 , V_45 ) ;
}
F_122 ( V_13 , V_45 ) ;
F_123 ( V_13 ) ;
F_124 ( 150 ) ;
F_122 ( V_13 , V_45 ) ;
F_123 ( V_13 ) ;
F_124 ( 150 ) ;
F_122 ( V_13 , V_45 ) ;
F_123 ( V_13 ) ;
F_124 ( 150 ) ;
}
static void F_140 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
if ( F_139 ( V_57 ) &&
F_38 ( V_65 -> V_91 , V_192 ) &&
! F_135 ( V_57 ) ) {
F_122 ( F_63 ( V_126 ) ,
F_11 ( F_63 ( V_126 ) ) & ~ V_193 ) ;
F_122 ( F_63 ( V_117 ) ,
F_11 ( F_63 ( V_117 ) ) & ~ V_193 ) ;
}
if ( ( V_95 == V_117 && V_6 -> V_136 & V_137 ) ||
( V_95 == V_126 && V_6 -> V_136 & V_138 ) )
return;
F_127 ( V_6 , V_95 ) ;
F_122 ( F_63 ( V_95 ) , V_190 ) ;
F_123 ( F_63 ( V_95 ) ) ;
}
static void F_141 ( struct V_5 * V_6 , enum V_95 V_95 )
{
T_1 V_15 ;
F_127 ( V_6 , V_95 ) ;
V_15 = V_194 |
V_195 | V_190 ;
if ( V_95 != V_117 )
V_15 |= V_196 ;
F_122 ( F_63 ( V_95 ) , V_15 ) ;
F_123 ( F_63 ( V_95 ) ) ;
}
static void F_142 ( struct V_5 * V_6 , enum V_95 V_95 )
{
enum V_182 V_183 = F_130 ( V_95 ) ;
T_1 V_15 ;
F_127 ( V_6 , V_95 ) ;
V_15 = V_197 |
V_195 | V_190 ;
if ( V_95 != V_117 )
V_15 |= V_196 ;
F_122 ( F_63 ( V_95 ) , V_15 ) ;
F_123 ( F_63 ( V_95 ) ) ;
F_3 ( & V_6 -> V_9 ) ;
V_15 = F_131 ( V_6 , V_95 , F_132 ( V_183 ) ) ;
V_15 &= ~ V_185 ;
F_133 ( V_6 , V_95 , F_132 ( V_183 ) , V_15 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
void F_143 ( struct V_5 * V_6 ,
struct V_198 * V_199 ,
unsigned int V_200 )
{
T_1 V_201 ;
T_3 V_202 ;
switch ( V_199 -> V_183 ) {
case V_203 :
V_201 = V_204 ;
V_202 = F_63 ( 0 ) ;
break;
case V_205 :
V_201 = V_206 ;
V_202 = F_63 ( 0 ) ;
V_200 <<= 4 ;
break;
case V_207 :
V_201 = V_208 ;
V_202 = V_209 ;
break;
default:
F_144 () ;
}
if ( F_60 ( V_6 ,
V_202 , V_201 , V_200 ,
1000 ) )
F_7 ( 1 , L_39 ,
F_145 ( V_199 -> V_183 ) , F_11 ( V_202 ) & V_201 , V_200 ) ;
}
static void F_146 ( struct V_5 * V_6 ,
enum V_95 V_95 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
struct V_87 * V_65 = V_6 -> V_96 [ V_95 ] ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
T_3 V_13 ;
T_2 V_15 , V_210 ;
F_147 ( V_6 , V_81 -> V_91 -> V_211 ) ;
F_148 ( V_6 , V_95 ) ;
F_149 ( V_6 , V_95 ) ;
if ( F_104 ( V_57 ) ) {
V_13 = F_150 ( V_95 ) ;
V_15 = F_11 ( V_13 ) ;
V_15 |= V_212 ;
F_122 ( V_13 , V_15 ) ;
}
V_13 = F_102 ( V_95 ) ;
V_15 = F_11 ( V_13 ) ;
V_210 = F_11 ( F_59 ( V_95 ) ) ;
if ( F_118 ( V_6 ) ) {
V_15 &= ~ V_213 ;
if ( F_38 ( V_81 -> V_91 , V_214 ) )
V_15 |= V_215 ;
else
V_15 |= V_210 & V_213 ;
}
V_15 &= ~ V_216 ;
if ( ( V_210 & V_217 ) == V_218 )
if ( F_118 ( V_6 ) &&
F_38 ( V_81 -> V_91 , V_219 ) )
V_15 |= V_220 ;
else
V_15 |= V_221 ;
else
V_15 |= V_222 ;
F_122 ( V_13 , V_15 | V_152 ) ;
if ( F_60 ( V_6 ,
V_13 , V_223 , V_223 ,
100 ) )
F_125 ( L_40 , F_76 ( V_95 ) ) ;
}
static void F_151 ( struct V_5 * V_6 ,
enum V_94 V_97 )
{
T_1 V_15 , V_210 ;
F_148 ( V_6 , (enum V_95 ) V_97 ) ;
F_149 ( V_6 , V_224 ) ;
V_15 = F_11 ( F_150 ( V_117 ) ) ;
V_15 |= V_212 ;
F_122 ( F_150 ( V_117 ) , V_15 ) ;
V_15 = V_152 ;
V_210 = F_11 ( F_59 ( V_97 ) ) ;
if ( ( V_210 & V_225 ) ==
V_218 )
V_15 |= V_221 ;
else
V_15 |= V_222 ;
F_122 ( V_226 , V_15 ) ;
if ( F_60 ( V_6 ,
V_226 ,
V_223 ,
V_223 ,
100 ) )
F_125 ( L_41 ) ;
}
static void F_152 ( struct V_5 * V_6 ,
enum V_95 V_95 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
T_3 V_13 ;
T_2 V_15 ;
F_153 ( V_6 , V_95 ) ;
F_154 ( V_6 , V_95 ) ;
F_120 ( V_6 , V_95 ) ;
V_13 = F_102 ( V_95 ) ;
V_15 = F_11 ( V_13 ) ;
V_15 &= ~ V_152 ;
F_122 ( V_13 , V_15 ) ;
if ( F_60 ( V_6 ,
V_13 , V_223 , 0 ,
50 ) )
F_125 ( L_42 , F_76 ( V_95 ) ) ;
if ( F_104 ( V_57 ) ) {
V_13 = F_150 ( V_95 ) ;
V_15 = F_11 ( V_13 ) ;
V_15 &= ~ V_212 ;
F_122 ( V_13 , V_15 ) ;
}
}
static void F_155 ( struct V_5 * V_6 )
{
T_1 V_15 ;
V_15 = F_11 ( V_226 ) ;
V_15 &= ~ V_152 ;
F_122 ( V_226 , V_15 ) ;
if ( F_60 ( V_6 ,
V_226 , V_223 , 0 ,
50 ) )
F_125 ( L_43 ) ;
V_15 = F_11 ( F_150 ( V_117 ) ) ;
V_15 &= ~ V_212 ;
F_122 ( F_150 ( V_117 ) , V_15 ) ;
}
static void F_156 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
enum V_94 V_97 = V_65 -> V_91 -> V_97 ;
enum V_95 V_227 ;
T_3 V_13 ;
T_1 V_15 ;
F_157 ( L_44 , F_76 ( V_95 ) ) ;
F_88 ( V_6 , V_95 ) ;
F_158 ( V_6 , V_95 ) ;
F_90 ( V_6 , V_95 ) ;
if ( F_159 ( V_6 ) )
V_227 = V_224 ;
else
V_227 = V_95 ;
if ( F_160 ( V_6 ) )
if ( F_38 ( V_65 -> V_91 , V_228 ) )
F_161 ( V_6 ) ;
else
F_162 ( V_6 , V_95 ) ;
else {
if ( V_65 -> V_91 -> V_229 ) {
F_163 ( V_6 , V_227 ) ;
F_72 ( V_6 ,
(enum V_95 ) V_97 ) ;
}
}
V_13 = F_59 ( V_97 ) ;
V_15 = F_11 ( V_13 ) ;
if ( V_15 & V_139 ) {
F_28 ( ! ( ( V_95 == V_117 && V_6 -> V_136 & V_137 ) ||
( V_95 == V_126 && V_6 -> V_136 & V_138 ) ) ) ;
return;
}
F_122 ( V_13 , V_15 | V_139 ) ;
F_123 ( V_13 ) ;
if ( V_57 -> V_230 == 0 &&
F_61 ( F_164 ( V_65 ) != V_65 -> V_231 , 50 ) )
F_125 ( L_45 , F_76 ( V_95 ) ) ;
}
static void F_165 ( struct V_81 * V_65 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
enum V_94 V_97 = V_65 -> V_91 -> V_97 ;
enum V_95 V_95 = V_65 -> V_95 ;
T_3 V_13 ;
T_1 V_15 ;
F_157 ( L_46 , F_76 ( V_95 ) ) ;
F_88 ( V_6 , V_95 ) ;
F_158 ( V_6 , V_95 ) ;
F_90 ( V_6 , V_95 ) ;
V_13 = F_59 ( V_97 ) ;
V_15 = F_11 ( V_13 ) ;
if ( ( V_15 & V_139 ) == 0 )
return;
if ( V_65 -> V_91 -> V_232 )
V_15 &= ~ V_233 ;
if ( ! ( V_95 == V_117 && V_6 -> V_136 & V_137 ) &&
! ( V_95 == V_126 && V_6 -> V_136 & V_138 ) )
V_15 &= ~ V_139 ;
F_122 ( V_13 , V_15 ) ;
if ( ( V_15 & V_139 ) == 0 )
F_57 ( V_65 ) ;
}
static unsigned int F_166 ( const struct V_5 * V_6 )
{
return F_55 ( V_6 ) ? 2048 : 4096 ;
}
static unsigned int F_167 ( const struct V_5 * V_6 ,
V_55 V_234 , unsigned int V_235 )
{
switch ( V_234 ) {
case V_236 :
return V_235 ;
case V_237 :
if ( F_55 ( V_6 ) )
return 128 ;
else
return 512 ;
case V_238 :
if ( F_55 ( V_6 ) || F_168 ( V_6 ) )
return 128 ;
else
return 512 ;
case V_239 :
switch ( V_235 ) {
case 1 :
return 64 ;
case 2 :
case 4 :
return 128 ;
case 8 :
case 16 :
return 256 ;
default:
F_169 ( V_235 ) ;
return V_235 ;
}
break;
default:
F_169 ( V_234 ) ;
return V_235 ;
}
}
unsigned int F_170 ( const struct V_5 * V_6 ,
V_55 V_234 , unsigned int V_235 )
{
if ( V_234 == V_236 )
return 1 ;
else
return F_166 ( V_6 ) /
F_167 ( V_6 , V_234 , V_235 ) ;
}
static void F_171 ( const struct V_5 * V_6 ,
unsigned int * V_240 ,
unsigned int * V_241 ,
V_55 V_234 ,
unsigned int V_235 )
{
unsigned int V_242 =
F_167 ( V_6 , V_234 , V_235 ) ;
* V_240 = V_242 / V_235 ;
* V_241 = F_166 ( V_6 ) / V_242 ;
}
unsigned int
F_172 ( struct V_56 * V_57 , unsigned int V_243 ,
T_2 V_244 , V_55 V_234 )
{
unsigned int V_235 = F_173 ( V_244 , 0 ) ;
unsigned int V_241 = F_170 ( F_53 ( V_57 ) , V_234 , V_235 ) ;
return F_174 ( V_243 , V_241 ) ;
}
unsigned int F_175 ( const struct V_245 * V_246 )
{
unsigned int V_247 = 0 ;
int V_142 ;
for ( V_142 = 0 ; V_142 < F_176 ( V_246 -> V_140 ) ; V_142 ++ )
V_247 += V_246 -> V_140 [ V_142 ] . V_248 * V_246 -> V_140 [ V_142 ] . V_243 ;
return V_247 ;
}
static void
F_177 ( struct V_249 * V_250 ,
const struct V_251 * V_90 ,
unsigned int V_252 )
{
if ( F_178 ( V_252 ) ) {
* V_250 = V_253 ;
V_250 -> V_254 . V_255 = F_179 ( V_90 ) -> V_246 ;
} else {
* V_250 = V_256 ;
}
}
static void
F_180 ( struct V_5 * V_6 ,
struct V_251 * V_90 )
{
struct V_245 * V_257 = & F_179 ( V_90 ) -> V_246 ;
unsigned int V_258 , V_240 , V_241 , V_235 ;
V_258 = F_166 ( V_6 ) ;
V_235 = F_173 ( V_90 -> V_244 , 0 ) ;
F_171 ( V_6 , & V_240 , & V_241 ,
V_90 -> V_259 [ 0 ] , V_235 ) ;
V_257 -> V_140 [ 0 ] . V_248 = F_181 ( V_90 -> V_260 [ 0 ] , V_240 * V_235 ) ;
V_257 -> V_140 [ 0 ] . V_243 = F_181 ( V_90 -> V_243 , V_241 ) ;
if ( V_257 -> V_244 == V_261 ) {
V_235 = F_173 ( V_90 -> V_244 , 1 ) ;
F_171 ( V_6 , & V_240 , & V_241 ,
V_90 -> V_259 [ 1 ] , V_235 ) ;
V_257 -> V_262 = V_90 -> V_263 [ 1 ] ;
V_257 -> V_140 [ 1 ] . V_248 = F_181 ( V_90 -> V_260 [ 1 ] , V_240 * V_235 ) ;
V_257 -> V_140 [ 1 ] . V_243 = F_181 ( V_90 -> V_243 / 2 , V_241 ) ;
}
}
static unsigned int F_182 ( const struct V_5 * V_6 )
{
if ( F_58 ( V_6 ) -> V_103 >= 9 )
return 256 * 1024 ;
else if ( F_183 ( V_6 ) || F_184 ( V_6 ) ||
F_16 ( V_6 ) || F_17 ( V_6 ) )
return 128 * 1024 ;
else if ( F_58 ( V_6 ) -> V_103 >= 4 )
return 4 * 1024 ;
else
return 0 ;
}
static unsigned int F_185 ( const struct V_5 * V_6 ,
V_55 V_234 )
{
switch ( V_234 ) {
case V_236 :
return F_182 ( V_6 ) ;
case V_237 :
if ( F_58 ( V_6 ) -> V_103 >= 9 )
return 256 * 1024 ;
return 0 ;
case V_238 :
case V_239 :
return 1 * 1024 * 1024 ;
default:
F_169 ( V_234 ) ;
return 0 ;
}
}
int
F_186 ( struct V_251 * V_90 ,
unsigned int V_252 )
{
struct V_56 * V_57 = V_90 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_264 * V_265 = F_187 ( V_90 ) ;
struct V_249 V_250 ;
T_1 V_266 ;
int V_267 ;
F_28 ( ! F_188 ( & V_57 -> V_268 ) ) ;
V_266 = F_185 ( V_6 , V_90 -> V_259 [ 0 ] ) ;
F_177 ( & V_250 , V_90 , V_252 ) ;
if ( F_189 ( V_6 ) && V_266 < 256 * 1024 )
V_266 = 256 * 1024 ;
F_190 ( V_6 ) ;
V_267 = F_191 ( V_265 , V_266 ,
& V_250 ) ;
if ( V_267 )
goto V_269;
if ( V_250 . type == V_270 ) {
V_267 = F_192 ( V_265 ) ;
if ( V_267 == - V_271 ) {
V_267 = - V_272 ;
goto V_273;
} else if ( V_267 )
goto V_273;
F_193 ( V_265 ) ;
}
F_194 ( V_6 ) ;
return 0 ;
V_273:
F_195 ( V_265 , & V_250 ) ;
V_269:
F_194 ( V_6 ) ;
return V_267 ;
}
void F_196 ( struct V_251 * V_90 , unsigned int V_252 )
{
struct V_264 * V_265 = F_187 ( V_90 ) ;
struct V_249 V_250 ;
F_28 ( ! F_188 ( & V_265 -> V_64 . V_57 -> V_268 ) ) ;
F_177 ( & V_250 , V_90 , V_252 ) ;
if ( V_250 . type == V_270 )
F_197 ( V_265 ) ;
F_195 ( V_265 , & V_250 ) ;
}
static T_1 F_198 ( int * V_274 , int * V_275 ,
unsigned int V_240 ,
unsigned int V_241 ,
unsigned int V_258 ,
unsigned int V_276 ,
T_1 V_277 ,
T_1 V_278 )
{
unsigned int V_279 ;
F_28 ( V_277 & ( V_258 - 1 ) ) ;
F_28 ( V_278 & ( V_258 - 1 ) ) ;
F_28 ( V_278 > V_277 ) ;
V_279 = ( V_277 - V_278 ) / V_258 ;
* V_275 += V_279 / V_276 * V_241 ;
* V_274 += V_279 % V_276 * V_240 ;
return V_278 ;
}
T_1 F_199 ( int * V_274 , int * V_275 ,
const struct V_251 * V_90 , int V_140 ,
unsigned int V_280 ,
unsigned int V_252 )
{
const struct V_5 * V_6 = F_53 ( V_90 -> V_57 ) ;
V_55 V_234 = V_90 -> V_259 [ V_140 ] ;
unsigned int V_235 = F_173 ( V_90 -> V_244 , V_140 ) ;
T_1 V_281 , V_282 , V_266 ;
V_266 = F_185 ( V_6 , V_234 ) ;
if ( V_266 )
V_266 -- ;
if ( V_234 != V_236 ) {
unsigned int V_258 , V_240 , V_241 ;
unsigned int V_283 , V_279 , V_276 ;
V_258 = F_166 ( V_6 ) ;
F_171 ( V_6 , & V_240 , & V_241 ,
V_234 , V_235 ) ;
if ( F_178 ( V_252 ) ) {
V_276 = V_280 / V_241 ;
F_200 ( V_240 , V_241 ) ;
} else {
V_276 = V_280 / ( V_240 * V_235 ) ;
}
V_283 = * V_275 / V_241 ;
* V_275 %= V_241 ;
V_279 = * V_274 / V_240 ;
* V_274 %= V_240 ;
V_281 = ( V_283 * V_276 + V_279 ) * V_258 ;
V_282 = V_281 & ~ V_266 ;
F_198 ( V_274 , V_275 , V_240 , V_241 ,
V_258 , V_276 ,
V_281 , V_282 ) ;
} else {
V_281 = * V_275 * V_280 + * V_274 * V_235 ;
V_282 = V_281 & ~ V_266 ;
* V_275 = ( V_281 & V_266 ) / V_280 ;
* V_274 = ( ( V_281 & V_266 ) - * V_275 * V_280 ) / V_235 ;
}
return V_282 ;
}
static int F_201 ( int V_284 )
{
switch ( V_284 ) {
case V_285 :
return V_286 ;
case V_287 :
return V_288 ;
case V_289 :
return V_290 ;
default:
case V_291 :
return V_292 ;
case V_293 :
return V_294 ;
case V_295 :
return V_296 ;
case V_297 :
return V_298 ;
}
}
static int F_202 ( int V_284 , bool V_299 , bool V_300 )
{
switch ( V_284 ) {
case V_301 :
return V_290 ;
default:
case V_302 :
if ( V_299 ) {
if ( V_300 )
return V_303 ;
else
return V_294 ;
} else {
if ( V_300 )
return V_304 ;
else
return V_292 ;
}
case V_305 :
if ( V_299 )
return V_298 ;
else
return V_296 ;
}
}
static bool
F_203 ( struct V_81 * V_65 ,
struct V_306 * V_307 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_308 * V_309 = & V_6 -> V_309 ;
struct V_264 * V_265 = NULL ;
struct V_310 V_311 = { 0 } ;
struct V_251 * V_90 = & V_307 -> V_90 -> V_64 ;
T_1 V_312 = F_204 ( V_307 -> V_64 , V_313 ) ;
T_1 V_314 = F_205 ( V_307 -> V_64 + V_307 -> V_247 ,
V_313 ) ;
V_314 -= V_312 ;
if ( V_307 -> V_247 == 0 )
return false ;
if ( V_314 * 2 > V_309 -> V_315 )
return false ;
F_3 ( & V_57 -> V_268 ) ;
V_265 = F_206 ( V_57 ,
V_312 ,
V_312 ,
V_314 ) ;
if ( ! V_265 ) {
F_5 ( & V_57 -> V_268 ) ;
return false ;
}
V_265 -> V_316 = V_307 -> V_317 ;
if ( V_265 -> V_316 == V_318 )
V_265 -> V_319 = V_90 -> V_260 [ 0 ] ;
V_311 . V_244 = V_90 -> V_244 ;
V_311 . V_248 = V_90 -> V_248 ;
V_311 . V_243 = V_90 -> V_243 ;
V_311 . V_260 [ 0 ] = V_90 -> V_260 [ 0 ] ;
V_311 . V_259 [ 0 ] = V_90 -> V_259 [ 0 ] ;
V_311 . V_320 = V_321 ;
if ( F_207 ( V_57 , F_179 ( V_90 ) ,
& V_311 , V_265 ) ) {
F_157 ( L_47 ) ;
goto V_322;
}
F_5 ( & V_57 -> V_268 ) ;
F_157 ( L_48 , V_265 ) ;
return true ;
V_322:
F_208 ( & V_265 -> V_64 ) ;
F_5 ( & V_57 -> V_268 ) ;
return false ;
}
static void
F_209 ( struct V_323 * V_140 )
{
if ( V_140 -> V_90 == V_140 -> V_43 -> V_90 )
return;
if ( V_140 -> V_43 -> V_90 )
F_210 ( V_140 -> V_43 -> V_90 ) ;
V_140 -> V_43 -> V_90 = V_140 -> V_90 ;
if ( V_140 -> V_43 -> V_90 )
F_211 ( V_140 -> V_43 -> V_90 ) ;
}
static void
F_212 ( struct V_81 * V_81 ,
struct V_306 * V_307 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_87 * V_324 ;
struct V_81 * V_142 ;
struct V_264 * V_265 ;
struct V_323 * V_89 = V_81 -> V_64 . V_89 ;
struct V_325 * V_326 = V_89 -> V_43 ;
struct V_42 * V_62 = V_81 -> V_64 . V_43 ;
struct V_327 * V_327 = F_213 ( V_89 ) ;
struct V_328 * V_329 =
F_214 ( V_326 ) ;
struct V_251 * V_90 ;
if ( ! V_307 -> V_90 )
return;
if ( F_203 ( V_81 , V_307 ) ) {
V_90 = & V_307 -> V_90 -> V_64 ;
goto V_330;
}
F_215 ( V_307 -> V_90 ) ;
F_216 (dev, c) {
V_142 = F_47 ( V_324 ) ;
if ( V_324 == & V_81 -> V_64 )
continue;
if ( ! V_142 -> V_88 )
continue;
V_90 = V_324 -> V_89 -> V_90 ;
if ( ! V_90 )
continue;
V_265 = F_187 ( V_90 ) ;
if ( F_217 ( V_265 ) == V_307 -> V_64 ) {
F_211 ( V_90 ) ;
goto V_330;
}
}
F_214 ( V_326 ) -> V_331 = false ;
V_62 -> V_332 &= ~ ( 1 << F_218 ( V_89 ) ) ;
F_219 ( & V_81 -> V_64 ) ;
V_327 -> V_333 ( V_89 , & V_81 -> V_64 ) ;
return;
V_330:
V_326 -> V_334 = 0 ;
V_326 -> V_335 = 0 ;
V_326 -> V_336 = V_90 -> V_248 << 16 ;
V_326 -> V_337 = V_90 -> V_243 << 16 ;
V_326 -> V_338 = 0 ;
V_326 -> V_339 = 0 ;
V_326 -> V_340 = V_90 -> V_248 ;
V_326 -> V_341 = V_90 -> V_243 ;
V_329 -> V_342 . V_343 = V_326 -> V_334 ;
V_329 -> V_342 . y1 = V_326 -> V_335 ;
V_329 -> V_342 . V_344 = V_326 -> V_334 + V_326 -> V_336 ;
V_329 -> V_342 . V_345 = V_326 -> V_335 + V_326 -> V_337 ;
V_329 -> V_346 . V_343 = V_326 -> V_338 ;
V_329 -> V_346 . y1 = V_326 -> V_339 ;
V_329 -> V_346 . V_344 = V_326 -> V_338 + V_326 -> V_340 ;
V_329 -> V_346 . V_345 = V_326 -> V_339 + V_326 -> V_341 ;
V_265 = F_187 ( V_90 ) ;
if ( V_265 -> V_316 != V_347 )
V_6 -> V_348 = true ;
F_211 ( V_90 ) ;
V_89 -> V_90 = V_89 -> V_43 -> V_90 = V_90 ;
V_89 -> V_65 = V_89 -> V_43 -> V_65 = & V_81 -> V_64 ;
V_81 -> V_64 . V_43 -> V_332 |= ( 1 << F_218 ( V_89 ) ) ;
V_265 -> V_349 |= F_213 ( V_89 ) -> V_350 ;
}
static void F_220 ( struct V_323 * V_89 ,
const struct V_37 * V_62 ,
const struct V_328 * V_326 )
{
struct V_56 * V_57 = V_89 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_62 -> V_64 . V_65 ) ;
struct V_251 * V_90 = V_326 -> V_64 . V_90 ;
struct V_264 * V_265 = F_187 ( V_90 ) ;
int V_140 = V_81 -> V_140 ;
T_1 V_351 ;
T_1 V_352 ;
T_3 V_13 = F_86 ( V_140 ) ;
unsigned int V_252 = V_326 -> V_64 . V_252 ;
int V_235 = F_173 ( V_90 -> V_244 , 0 ) ;
int V_274 = V_326 -> V_342 . V_343 >> 16 ;
int V_275 = V_326 -> V_342 . y1 >> 16 ;
V_352 = V_353 ;
V_352 |= V_141 ;
if ( F_58 ( V_57 ) -> V_103 < 4 ) {
if ( V_81 -> V_95 == V_126 )
V_352 |= V_354 ;
F_122 ( F_221 ( V_140 ) ,
( ( V_62 -> V_355 - 1 ) << 16 ) |
( V_62 -> V_356 - 1 ) ) ;
F_122 ( F_222 ( V_140 ) , 0 ) ;
} else if ( F_17 ( V_57 ) && V_140 == V_357 ) {
F_122 ( F_223 ( V_140 ) ,
( ( V_62 -> V_355 - 1 ) << 16 ) |
( V_62 -> V_356 - 1 ) ) ;
F_122 ( F_224 ( V_140 ) , 0 ) ;
F_122 ( F_225 ( V_140 ) , 0 ) ;
}
switch ( V_90 -> V_244 ) {
case V_286 :
V_352 |= V_285 ;
break;
case V_288 :
V_352 |= V_287 ;
break;
case V_290 :
V_352 |= V_289 ;
break;
case V_292 :
V_352 |= V_291 ;
break;
case V_294 :
V_352 |= V_293 ;
break;
case V_296 :
V_352 |= V_295 ;
break;
case V_298 :
V_352 |= V_297 ;
break;
default:
F_144 () ;
}
if ( F_58 ( V_57 ) -> V_103 >= 4 &&
V_265 -> V_316 != V_347 )
V_352 |= V_358 ;
if ( F_18 ( V_57 ) )
V_352 |= V_359 ;
V_351 = V_275 * V_90 -> V_260 [ 0 ] + V_274 * V_235 ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
V_81 -> V_360 =
F_199 ( & V_274 , & V_275 , V_90 , 0 ,
V_90 -> V_260 [ 0 ] , V_252 ) ;
V_351 -= V_81 -> V_360 ;
} else {
V_81 -> V_360 = V_351 ;
}
if ( V_252 == F_226 ( V_361 ) ) {
V_352 |= V_362 ;
V_274 += ( V_62 -> V_356 - 1 ) ;
V_275 += ( V_62 -> V_355 - 1 ) ;
V_351 +=
( V_62 -> V_355 - 1 ) * V_90 -> V_260 [ 0 ] +
( V_62 -> V_356 - 1 ) * V_235 ;
}
V_81 -> V_363 = V_274 ;
V_81 -> V_364 = V_275 ;
F_122 ( V_13 , V_352 ) ;
F_122 ( F_227 ( V_140 ) , V_90 -> V_260 [ 0 ] ) ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
F_122 ( F_228 ( V_140 ) ,
F_217 ( V_265 ) + V_81 -> V_360 ) ;
F_122 ( F_229 ( V_140 ) , ( V_275 << 16 ) | V_274 ) ;
F_122 ( F_230 ( V_140 ) , V_351 ) ;
} else
F_122 ( F_231 ( V_140 ) , F_217 ( V_265 ) + V_351 ) ;
F_123 ( V_13 ) ;
}
static void F_232 ( struct V_323 * V_89 ,
struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_140 = V_81 -> V_140 ;
F_122 ( F_86 ( V_140 ) , 0 ) ;
if ( F_58 ( V_6 ) -> V_103 >= 4 )
F_122 ( F_228 ( V_140 ) , 0 ) ;
else
F_122 ( F_231 ( V_140 ) , 0 ) ;
F_123 ( F_86 ( V_140 ) ) ;
}
static void F_233 ( struct V_323 * V_89 ,
const struct V_37 * V_62 ,
const struct V_328 * V_326 )
{
struct V_56 * V_57 = V_89 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_62 -> V_64 . V_65 ) ;
struct V_251 * V_90 = V_326 -> V_64 . V_90 ;
struct V_264 * V_265 = F_187 ( V_90 ) ;
int V_140 = V_81 -> V_140 ;
T_1 V_351 ;
T_1 V_352 ;
T_3 V_13 = F_86 ( V_140 ) ;
unsigned int V_252 = V_326 -> V_64 . V_252 ;
int V_235 = F_173 ( V_90 -> V_244 , 0 ) ;
int V_274 = V_326 -> V_342 . V_343 >> 16 ;
int V_275 = V_326 -> V_342 . y1 >> 16 ;
V_352 = V_353 ;
V_352 |= V_141 ;
if ( F_234 ( V_57 ) || F_235 ( V_57 ) )
V_352 |= V_365 ;
switch ( V_90 -> V_244 ) {
case V_286 :
V_352 |= V_285 ;
break;
case V_290 :
V_352 |= V_289 ;
break;
case V_292 :
V_352 |= V_291 ;
break;
case V_294 :
V_352 |= V_293 ;
break;
case V_296 :
V_352 |= V_295 ;
break;
case V_298 :
V_352 |= V_297 ;
break;
default:
F_144 () ;
}
if ( V_265 -> V_316 != V_347 )
V_352 |= V_358 ;
if ( ! F_234 ( V_57 ) && ! F_235 ( V_57 ) )
V_352 |= V_359 ;
V_351 = V_275 * V_90 -> V_260 [ 0 ] + V_274 * V_235 ;
V_81 -> V_360 =
F_199 ( & V_274 , & V_275 , V_90 , 0 ,
V_90 -> V_260 [ 0 ] , V_252 ) ;
V_351 -= V_81 -> V_360 ;
if ( V_252 == F_226 ( V_361 ) ) {
V_352 |= V_362 ;
if ( ! F_234 ( V_57 ) && ! F_235 ( V_57 ) ) {
V_274 += ( V_62 -> V_356 - 1 ) ;
V_275 += ( V_62 -> V_355 - 1 ) ;
V_351 +=
( V_62 -> V_355 - 1 ) * V_90 -> V_260 [ 0 ] +
( V_62 -> V_356 - 1 ) * V_235 ;
}
}
V_81 -> V_363 = V_274 ;
V_81 -> V_364 = V_275 ;
F_122 ( V_13 , V_352 ) ;
F_122 ( F_227 ( V_140 ) , V_90 -> V_260 [ 0 ] ) ;
F_122 ( F_228 ( V_140 ) ,
F_217 ( V_265 ) + V_81 -> V_360 ) ;
if ( F_234 ( V_57 ) || F_235 ( V_57 ) ) {
F_122 ( F_236 ( V_140 ) , ( V_275 << 16 ) | V_274 ) ;
} else {
F_122 ( F_229 ( V_140 ) , ( V_275 << 16 ) | V_274 ) ;
F_122 ( F_230 ( V_140 ) , V_351 ) ;
}
F_123 ( V_13 ) ;
}
T_1 F_237 ( const struct V_5 * V_6 ,
V_55 V_234 , T_2 V_244 )
{
if ( V_234 == V_236 ) {
return 64 ;
} else {
int V_235 = F_173 ( V_244 , 0 ) ;
return F_167 ( V_6 , V_234 , V_235 ) ;
}
}
T_1 F_238 ( struct V_327 * V_327 ,
struct V_264 * V_265 ,
unsigned int V_140 )
{
struct V_249 V_250 ;
struct V_366 * V_367 ;
T_4 V_281 ;
F_177 ( & V_250 , V_327 -> V_64 . V_43 -> V_90 ,
V_327 -> V_64 . V_43 -> V_252 ) ;
V_367 = F_239 ( V_265 , & V_250 ) ;
if ( F_7 ( ! V_367 , L_49 ,
V_250 . type ) )
return - 1 ;
V_281 = V_367 -> V_368 . V_369 ;
if ( V_140 == 1 ) {
V_281 += V_367 -> V_370 . V_254 . V_255 . V_371 *
V_313 ;
}
F_28 ( F_240 ( V_281 ) ) ;
return F_241 ( V_281 ) ;
}
static void F_242 ( struct V_81 * V_81 , int V_372 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
F_122 ( F_243 ( V_81 -> V_95 , V_372 ) , 0 ) ;
F_122 ( F_244 ( V_81 -> V_95 , V_372 ) , 0 ) ;
F_122 ( F_245 ( V_81 -> V_95 , V_372 ) , 0 ) ;
}
static void F_246 ( struct V_81 * V_81 )
{
struct V_373 * V_374 ;
int V_142 ;
V_374 = & V_81 -> V_91 -> V_374 ;
for ( V_142 = 0 ; V_142 < V_81 -> V_375 ; V_142 ++ ) {
if ( ! V_374 -> V_376 [ V_142 ] . V_377 )
F_242 ( V_81 , V_142 ) ;
}
}
T_1 F_247 ( T_2 V_244 )
{
switch ( V_244 ) {
case V_286 :
return V_378 ;
case V_290 :
return V_301 ;
case V_294 :
return V_302 | V_379 ;
case V_292 :
return V_302 ;
case V_303 :
return V_302 | V_379 |
V_380 ;
case V_304 :
return V_302 |
V_380 ;
case V_296 :
return V_305 ;
case V_298 :
return V_379 | V_305 ;
case V_381 :
return V_382 | V_383 ;
case V_384 :
return V_382 | V_385 ;
case V_386 :
return V_382 | V_387 ;
case V_388 :
return V_382 | V_389 ;
default:
F_169 ( V_244 ) ;
}
return 0 ;
}
T_1 F_248 ( V_55 V_234 )
{
switch ( V_234 ) {
case V_236 :
break;
case V_237 :
return V_390 ;
case V_238 :
return V_391 ;
case V_239 :
return V_392 ;
default:
F_169 ( V_234 ) ;
}
return 0 ;
}
T_1 F_249 ( unsigned int V_252 )
{
switch ( V_252 ) {
case F_226 ( V_393 ) :
break;
case F_226 ( V_394 ) :
return V_395 ;
case F_226 ( V_361 ) :
return V_396 ;
case F_226 ( V_397 ) :
return V_398 ;
default:
F_169 ( V_252 ) ;
}
return 0 ;
}
static void F_250 ( struct V_323 * V_140 ,
const struct V_37 * V_62 ,
const struct V_328 * V_326 )
{
struct V_56 * V_57 = V_140 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_62 -> V_64 . V_65 ) ;
struct V_251 * V_90 = V_326 -> V_64 . V_90 ;
struct V_264 * V_265 = F_187 ( V_90 ) ;
int V_95 = V_81 -> V_95 ;
T_1 V_399 , V_400 , V_319 ;
T_1 V_241 , V_401 , V_402 ;
unsigned int V_252 = V_326 -> V_64 . V_252 ;
int V_403 , V_404 ;
T_1 V_405 ;
int V_406 = V_326 -> V_406 ;
int V_334 = V_326 -> V_342 . V_343 >> 16 ;
int V_335 = V_326 -> V_342 . y1 >> 16 ;
int V_336 = F_251 ( & V_326 -> V_342 ) >> 16 ;
int V_337 = F_252 ( & V_326 -> V_342 ) >> 16 ;
int V_407 = V_326 -> V_346 . V_343 ;
int V_408 = V_326 -> V_346 . y1 ;
int V_409 = F_251 ( & V_326 -> V_346 ) ;
int V_410 = F_252 ( & V_326 -> V_346 ) ;
V_399 = V_147 |
V_411 |
V_412 ;
V_399 |= F_247 ( V_90 -> V_244 ) ;
V_399 |= F_248 ( V_90 -> V_259 [ 0 ] ) ;
V_399 |= V_413 ;
V_399 |= F_249 ( V_252 ) ;
V_400 = F_237 ( V_6 , V_90 -> V_259 [ 0 ] ,
V_90 -> V_244 ) ;
V_405 = F_238 ( F_213 ( V_140 ) , V_265 , 0 ) ;
F_28 ( F_251 ( & V_326 -> V_342 ) == 0 ) ;
if ( F_178 ( V_252 ) ) {
int V_235 = F_173 ( V_90 -> V_244 , 0 ) ;
V_241 = F_170 ( V_6 , V_90 -> V_259 [ 0 ] , V_235 ) ;
V_319 = F_181 ( V_90 -> V_243 , V_241 ) ;
V_403 = V_319 * V_241 - V_335 - V_337 ;
V_404 = V_334 ;
V_402 = ( V_336 - 1 ) << 16 | ( V_337 - 1 ) ;
} else {
V_319 = V_90 -> V_260 [ 0 ] / V_400 ;
V_403 = V_334 ;
V_404 = V_335 ;
V_402 = ( V_337 - 1 ) << 16 | ( V_336 - 1 ) ;
}
V_401 = V_404 << 16 | V_403 ;
V_81 -> V_363 = V_403 ;
V_81 -> V_364 = V_404 ;
F_122 ( F_92 ( V_95 , 0 ) , V_399 ) ;
F_122 ( F_253 ( V_95 , 0 ) , V_401 ) ;
F_122 ( F_254 ( V_95 , 0 ) , V_402 ) ;
F_122 ( F_255 ( V_95 , 0 ) , V_319 ) ;
if ( V_406 >= 0 ) {
T_2 V_414 = 0 ;
F_28 ( ! V_409 || ! V_410 ) ;
V_414 = V_415 | F_256 ( 0 ) |
V_62 -> V_374 . V_376 [ V_406 ] . V_416 ;
F_122 ( F_243 ( V_95 , V_406 ) , V_414 ) ;
F_122 ( F_257 ( V_95 , V_406 ) , 0 ) ;
F_122 ( F_244 ( V_95 , V_406 ) , ( V_407 << 16 ) | V_408 ) ;
F_122 ( F_245 ( V_95 , V_406 ) , ( V_409 << 16 ) | V_410 ) ;
F_122 ( F_258 ( V_95 , 0 ) , 0 ) ;
} else {
F_122 ( F_258 ( V_95 , 0 ) , ( V_408 << 16 ) | V_407 ) ;
}
F_122 ( F_259 ( V_95 , 0 ) , V_405 ) ;
F_123 ( F_259 ( V_95 , 0 ) ) ;
}
static void F_260 ( struct V_323 * V_89 ,
struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = F_47 ( V_65 ) -> V_95 ;
F_122 ( F_92 ( V_95 , 0 ) , 0 ) ;
F_122 ( F_259 ( V_95 , 0 ) , 0 ) ;
F_123 ( F_259 ( V_95 , 0 ) ) ;
}
static int
F_261 ( struct V_87 * V_65 , struct V_251 * V_90 ,
int V_274 , int V_275 , enum V_417 V_43 )
{
F_125 ( L_50 ) ;
return - V_418 ;
}
static void F_262 ( struct V_5 * V_6 )
{
struct V_81 * V_65 ;
F_136 (&dev_priv->drm, crtc)
F_263 ( V_6 , V_65 -> V_95 ) ;
}
static void F_264 ( struct V_56 * V_57 )
{
struct V_87 * V_65 ;
F_216 (dev, crtc) {
struct V_327 * V_140 = F_213 ( V_65 -> V_89 ) ;
struct V_328 * V_326 =
F_214 ( V_140 -> V_64 . V_43 ) ;
if ( V_326 -> V_331 )
V_140 -> V_419 ( & V_140 -> V_64 ,
F_265 ( V_65 -> V_43 ) ,
V_326 ) ;
}
}
static int
F_266 ( struct V_56 * V_57 ,
struct V_420 * V_43 )
{
struct V_42 * V_62 ;
struct V_87 * V_65 ;
int V_142 , V_267 ;
F_267 ( V_57 ) ;
F_268 ( V_57 ) ;
if ( ! V_43 )
return 0 ;
F_269 (state, crtc, crtc_state, i) {
V_62 -> V_421 = true ;
}
F_270 ( V_43 ) -> V_422 = true ;
V_267 = F_271 ( V_43 ) ;
F_28 ( V_267 == - V_271 ) ;
return V_267 ;
}
void F_272 ( struct V_5 * V_6 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
struct V_423 * V_424 = & V_6 -> V_425 ;
struct V_420 * V_43 ;
int V_267 ;
if ( F_55 ( V_6 ) )
return;
F_3 ( & V_57 -> V_426 . V_427 ) ;
F_273 ( V_424 , 0 ) ;
while ( 1 ) {
V_267 = F_274 ( V_57 , V_424 ) ;
if ( V_267 != - V_271 )
break;
F_275 ( V_424 ) ;
}
if ( F_276 ( V_6 ) >= 5 || F_18 ( V_6 ) )
return;
V_43 = F_277 ( V_57 , V_424 ) ;
if ( F_278 ( V_43 ) ) {
V_267 = F_279 ( V_43 ) ;
V_43 = NULL ;
F_125 ( L_51 , V_267 ) ;
goto V_72;
}
V_267 = F_280 ( V_57 , V_424 ) ;
if ( V_267 ) {
F_125 ( L_52 , V_267 ) ;
goto V_72;
}
V_6 -> V_428 = V_43 ;
V_43 -> V_429 = V_424 ;
return;
V_72:
F_281 ( V_43 ) ;
}
void F_282 ( struct V_5 * V_6 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
struct V_423 * V_424 = & V_6 -> V_425 ;
struct V_420 * V_43 = V_6 -> V_428 ;
int V_267 ;
F_262 ( V_6 ) ;
if ( F_55 ( V_6 ) )
return;
V_6 -> V_428 = NULL ;
if ( F_276 ( V_6 ) >= 5 || F_18 ( V_6 ) ) {
F_264 ( V_57 ) ;
} else {
F_283 ( V_6 ) ;
F_284 ( V_6 ) ;
F_285 ( V_57 ) ;
F_286 ( & V_6 -> V_430 ) ;
if ( V_6 -> V_431 . V_432 )
V_6 -> V_431 . V_432 ( V_6 ) ;
F_287 ( & V_6 -> V_430 ) ;
V_267 = F_266 ( V_57 , V_43 ) ;
if ( V_267 )
F_125 ( L_53 , V_267 ) ;
F_288 ( V_6 ) ;
}
F_289 ( V_424 ) ;
F_290 ( V_424 ) ;
F_5 ( & V_57 -> V_426 . V_427 ) ;
}
static bool F_291 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
unsigned V_433 ;
bool V_434 ;
V_433 = F_292 ( & F_53 ( V_57 ) -> V_435 ) ;
if ( V_81 -> V_433 != V_433 )
return false ;
F_286 ( & V_57 -> V_436 ) ;
V_434 = F_47 ( V_65 ) -> V_437 != NULL ;
F_287 ( & V_57 -> V_436 ) ;
return V_434 ;
}
static void F_293 ( struct V_81 * V_65 ,
struct V_37 * V_438 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_37 * V_38 =
F_265 ( V_65 -> V_64 . V_43 ) ;
V_65 -> V_64 . V_416 = V_65 -> V_64 . V_43 -> V_416 ;
F_157 ( L_54 ,
V_438 -> V_356 , V_438 -> V_355 ,
V_38 -> V_356 , V_38 -> V_355 ) ;
F_122 ( F_294 ( V_65 -> V_95 ) ,
( ( V_38 -> V_356 - 1 ) << 16 ) |
( V_38 -> V_355 - 1 ) ) ;
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
F_246 ( V_65 ) ;
if ( V_38 -> V_439 . V_151 )
F_295 ( V_65 ) ;
} else if ( F_15 ( V_57 ) ) {
if ( V_38 -> V_439 . V_151 )
F_296 ( V_65 ) ;
else if ( V_438 -> V_439 . V_151 )
F_297 ( V_65 , true ) ;
}
}
static void F_298 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_3 V_13 ;
T_1 V_440 ;
V_13 = F_69 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
if ( F_299 ( V_57 ) ) {
V_440 &= ~ V_441 ;
V_440 |= V_441 | V_442 ;
} else {
V_440 &= ~ V_443 ;
V_440 |= V_443 | V_442 ;
}
F_122 ( V_13 , V_440 ) ;
V_13 = F_71 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
if ( F_104 ( V_57 ) ) {
V_440 &= ~ V_444 ;
V_440 |= V_445 ;
} else {
V_440 &= ~ V_443 ;
V_440 |= V_443 ;
}
F_122 ( V_13 , V_440 | V_446 ) ;
F_123 ( V_13 ) ;
F_124 ( 1000 ) ;
if ( F_299 ( V_57 ) )
F_122 ( V_13 , F_11 ( V_13 ) | V_447 |
V_448 ) ;
}
static void F_300 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_3 V_13 ;
T_1 V_440 , V_449 ;
F_301 ( V_6 , V_95 ) ;
V_13 = F_302 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_450 ;
V_440 &= ~ V_451 ;
F_122 ( V_13 , V_440 ) ;
F_11 ( V_13 ) ;
F_124 ( 150 ) ;
V_13 = F_69 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_452 ;
V_440 |= F_303 ( V_81 -> V_91 -> V_453 ) ;
V_440 &= ~ V_443 ;
V_440 |= V_454 ;
F_122 ( V_13 , V_440 | V_110 ) ;
V_13 = F_71 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_443 ;
V_440 |= V_454 ;
F_122 ( V_13 , V_440 | V_111 ) ;
F_123 ( V_13 ) ;
F_124 ( 150 ) ;
F_122 ( F_304 ( V_95 ) , V_455 ) ;
F_122 ( F_304 ( V_95 ) , V_455 |
V_456 ) ;
V_13 = F_305 ( V_95 ) ;
for ( V_449 = 0 ; V_449 < 5 ; V_449 ++ ) {
V_440 = F_11 ( V_13 ) ;
F_157 ( L_55 , V_440 ) ;
if ( ( V_440 & V_451 ) ) {
F_157 ( L_56 ) ;
F_122 ( V_13 , V_440 | V_451 ) ;
break;
}
}
if ( V_449 == 5 )
F_125 ( L_57 ) ;
V_13 = F_69 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_443 ;
V_440 |= V_457 ;
F_122 ( V_13 , V_440 ) ;
V_13 = F_71 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_443 ;
V_440 |= V_457 ;
F_122 ( V_13 , V_440 ) ;
F_123 ( V_13 ) ;
F_124 ( 150 ) ;
V_13 = F_305 ( V_95 ) ;
for ( V_449 = 0 ; V_449 < 5 ; V_449 ++ ) {
V_440 = F_11 ( V_13 ) ;
F_157 ( L_55 , V_440 ) ;
if ( V_440 & V_450 ) {
F_122 ( V_13 , V_440 | V_450 ) ;
F_157 ( L_58 ) ;
break;
}
}
if ( V_449 == 5 )
F_125 ( L_59 ) ;
F_157 ( L_60 ) ;
}
static void F_306 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_3 V_13 ;
T_1 V_440 , V_142 , V_458 ;
V_13 = F_302 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_450 ;
V_440 &= ~ V_451 ;
F_122 ( V_13 , V_440 ) ;
F_123 ( V_13 ) ;
F_124 ( 150 ) ;
V_13 = F_69 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_452 ;
V_440 |= F_303 ( V_81 -> V_91 -> V_453 ) ;
V_440 &= ~ V_443 ;
V_440 |= V_454 ;
V_440 &= ~ V_459 ;
V_440 |= V_460 ;
F_122 ( V_13 , V_440 | V_110 ) ;
F_122 ( F_307 ( V_95 ) ,
V_461 | V_462 ) ;
V_13 = F_71 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
if ( F_104 ( V_57 ) ) {
V_440 &= ~ V_444 ;
V_440 |= V_463 ;
} else {
V_440 &= ~ V_443 ;
V_440 |= V_454 ;
}
F_122 ( V_13 , V_440 | V_111 ) ;
F_123 ( V_13 ) ;
F_124 ( 150 ) ;
for ( V_142 = 0 ; V_142 < 4 ; V_142 ++ ) {
V_13 = F_69 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_459 ;
V_440 |= V_464 [ V_142 ] ;
F_122 ( V_13 , V_440 ) ;
F_123 ( V_13 ) ;
F_124 ( 500 ) ;
for ( V_458 = 0 ; V_458 < 5 ; V_458 ++ ) {
V_13 = F_305 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
F_157 ( L_55 , V_440 ) ;
if ( V_440 & V_451 ) {
F_122 ( V_13 , V_440 | V_451 ) ;
F_157 ( L_56 ) ;
break;
}
F_124 ( 50 ) ;
}
if ( V_458 < 5 )
break;
}
if ( V_142 == 4 )
F_125 ( L_57 ) ;
V_13 = F_69 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_443 ;
V_440 |= V_457 ;
if ( F_308 ( V_57 ) ) {
V_440 &= ~ V_459 ;
V_440 |= V_460 ;
}
F_122 ( V_13 , V_440 ) ;
V_13 = F_71 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
if ( F_104 ( V_57 ) ) {
V_440 &= ~ V_444 ;
V_440 |= V_465 ;
} else {
V_440 &= ~ V_443 ;
V_440 |= V_457 ;
}
F_122 ( V_13 , V_440 ) ;
F_123 ( V_13 ) ;
F_124 ( 150 ) ;
for ( V_142 = 0 ; V_142 < 4 ; V_142 ++ ) {
V_13 = F_69 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_459 ;
V_440 |= V_464 [ V_142 ] ;
F_122 ( V_13 , V_440 ) ;
F_123 ( V_13 ) ;
F_124 ( 500 ) ;
for ( V_458 = 0 ; V_458 < 5 ; V_458 ++ ) {
V_13 = F_305 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
F_157 ( L_55 , V_440 ) ;
if ( V_440 & V_450 ) {
F_122 ( V_13 , V_440 | V_450 ) ;
F_157 ( L_58 ) ;
break;
}
F_124 ( 50 ) ;
}
if ( V_458 < 5 )
break;
}
if ( V_142 == 4 )
F_125 ( L_59 ) ;
F_157 ( L_61 ) ;
}
static void F_309 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_3 V_13 ;
T_1 V_440 , V_142 , V_466 ;
V_13 = F_302 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_450 ;
V_440 &= ~ V_451 ;
F_122 ( V_13 , V_440 ) ;
F_123 ( V_13 ) ;
F_124 ( 150 ) ;
F_157 ( L_62 ,
F_11 ( F_305 ( V_95 ) ) ) ;
for ( V_466 = 0 ; V_466 < F_176 ( V_464 ) * 2 ; V_466 ++ ) {
V_13 = F_69 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ ( V_467 | V_441 ) ;
V_440 &= ~ V_110 ;
F_122 ( V_13 , V_440 ) ;
V_13 = F_71 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_467 ;
V_440 &= ~ V_444 ;
V_440 &= ~ V_111 ;
F_122 ( V_13 , V_440 ) ;
V_13 = F_69 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_452 ;
V_440 |= F_303 ( V_81 -> V_91 -> V_453 ) ;
V_440 |= V_468 ;
V_440 &= ~ V_459 ;
V_440 |= V_464 [ V_466 / 2 ] ;
V_440 |= V_469 ;
F_122 ( V_13 , V_440 | V_110 ) ;
F_122 ( F_307 ( V_95 ) ,
V_461 | V_462 ) ;
V_13 = F_71 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 |= V_463 ;
V_440 |= V_469 ;
F_122 ( V_13 , V_440 | V_111 ) ;
F_123 ( V_13 ) ;
F_124 ( 1 ) ;
for ( V_142 = 0 ; V_142 < 4 ; V_142 ++ ) {
V_13 = F_305 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
F_157 ( L_55 , V_440 ) ;
if ( V_440 & V_451 ||
( F_11 ( V_13 ) & V_451 ) ) {
F_122 ( V_13 , V_440 | V_451 ) ;
F_157 ( L_63 ,
V_142 ) ;
break;
}
F_124 ( 1 ) ;
}
if ( V_142 == 4 ) {
F_157 ( L_64 , V_466 / 2 ) ;
continue;
}
V_13 = F_69 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_441 ;
V_440 |= V_470 ;
F_122 ( V_13 , V_440 ) ;
V_13 = F_71 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_444 ;
V_440 |= V_465 ;
F_122 ( V_13 , V_440 ) ;
F_123 ( V_13 ) ;
F_124 ( 2 ) ;
for ( V_142 = 0 ; V_142 < 4 ; V_142 ++ ) {
V_13 = F_305 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
F_157 ( L_55 , V_440 ) ;
if ( V_440 & V_450 ||
( F_11 ( V_13 ) & V_450 ) ) {
F_122 ( V_13 , V_440 | V_450 ) ;
F_157 ( L_65 ,
V_142 ) ;
goto V_471;
}
F_124 ( 2 ) ;
}
if ( V_142 == 4 )
F_157 ( L_66 , V_466 / 2 ) ;
}
V_471:
F_157 ( L_61 ) ;
}
static void F_310 ( struct V_81 * V_81 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_81 -> V_95 ;
T_3 V_13 ;
T_1 V_440 ;
V_13 = F_71 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ ( V_452 | ( 0x7 << 16 ) ) ;
V_440 |= F_303 ( V_81 -> V_91 -> V_453 ) ;
V_440 |= ( F_11 ( F_59 ( V_95 ) ) & V_213 ) << 11 ;
F_122 ( V_13 , V_440 | V_113 ) ;
F_123 ( V_13 ) ;
F_124 ( 200 ) ;
V_440 = F_11 ( V_13 ) ;
F_122 ( V_13 , V_440 | V_472 ) ;
F_123 ( V_13 ) ;
F_124 ( 200 ) ;
V_13 = F_69 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
if ( ( V_440 & V_112 ) == 0 ) {
F_122 ( V_13 , V_440 | V_112 ) ;
F_123 ( V_13 ) ;
F_124 ( 100 ) ;
}
}
static void F_311 ( struct V_81 * V_81 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_81 -> V_95 ;
T_3 V_13 ;
T_1 V_440 ;
V_13 = F_71 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
F_122 ( V_13 , V_440 & ~ V_472 ) ;
V_13 = F_69 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
F_122 ( V_13 , V_440 & ~ V_112 ) ;
F_123 ( V_13 ) ;
F_124 ( 100 ) ;
V_13 = F_71 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
F_122 ( V_13 , V_440 & ~ V_113 ) ;
F_123 ( V_13 ) ;
F_124 ( 100 ) ;
}
static void F_312 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_3 V_13 ;
T_1 V_440 ;
V_13 = F_69 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
F_122 ( V_13 , V_440 & ~ V_110 ) ;
F_123 ( V_13 ) ;
V_13 = F_71 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ ( 0x7 << 16 ) ;
V_440 |= ( F_11 ( F_59 ( V_95 ) ) & V_213 ) << 11 ;
F_122 ( V_13 , V_440 & ~ V_111 ) ;
F_123 ( V_13 ) ;
F_124 ( 100 ) ;
if ( F_118 ( V_57 ) )
F_122 ( F_304 ( V_95 ) , V_455 ) ;
V_13 = F_69 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ V_443 ;
V_440 |= V_454 ;
F_122 ( V_13 , V_440 ) ;
V_13 = F_71 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
if ( F_104 ( V_57 ) ) {
V_440 &= ~ V_444 ;
V_440 |= V_463 ;
} else {
V_440 &= ~ V_443 ;
V_440 |= V_454 ;
}
V_440 &= ~ ( 0x07 << 16 ) ;
V_440 |= ( F_11 ( F_59 ( V_95 ) ) & V_213 ) << 11 ;
F_122 ( V_13 , V_440 ) ;
F_123 ( V_13 ) ;
F_124 ( 100 ) ;
}
bool F_313 ( struct V_56 * V_57 )
{
struct V_81 * V_65 ;
F_136 (dev, crtc) {
if ( F_314 ( & V_65 -> V_473 ) == 0 )
continue;
if ( V_65 -> V_437 )
F_315 ( V_57 , V_65 -> V_95 ) ;
return true ;
}
return false ;
}
static void F_316 ( struct V_81 * V_81 )
{
struct V_5 * V_6 = F_53 ( V_81 -> V_64 . V_57 ) ;
struct V_1 * V_2 = V_81 -> V_437 ;
V_81 -> V_437 = NULL ;
if ( V_2 -> V_474 )
F_317 ( & V_81 -> V_64 , V_2 -> V_474 ) ;
F_100 ( & V_81 -> V_64 ) ;
F_318 ( & V_6 -> V_475 ) ;
F_319 ( V_6 -> V_476 , & V_2 -> V_477 ) ;
F_320 ( V_81 -> V_140 ,
V_2 -> V_478 ) ;
}
static int F_321 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
long V_267 ;
F_28 ( F_322 ( & V_6 -> V_475 ) ) ;
V_267 = F_323 (
V_6 -> V_475 ,
! F_291 ( V_65 ) ,
60 * V_479 ) ;
if ( V_267 < 0 )
return V_267 ;
if ( V_267 == 0 ) {
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_1 * V_2 ;
F_286 ( & V_57 -> V_436 ) ;
V_2 = V_81 -> V_437 ;
if ( V_2 && ! F_1 ( V_2 ) ) {
F_324 ( 1 , L_67 ) ;
F_316 ( V_81 ) ;
}
F_287 ( & V_57 -> V_436 ) ;
}
return 0 ;
}
static void F_325 ( struct V_5 * V_6 )
{
T_1 V_440 ;
F_122 ( V_480 , V_481 ) ;
F_3 ( & V_6 -> V_9 ) ;
V_440 = F_326 ( V_6 , V_482 , V_483 ) ;
V_440 |= V_484 ;
F_327 ( V_6 , V_482 , V_440 , V_483 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_328 ( struct V_87 * V_65 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_57 ) ;
int clock = F_47 ( V_65 ) -> V_91 -> V_64 . V_92 . V_93 ;
T_1 V_485 , V_486 , V_487 , V_488 = 0 ;
T_1 V_440 ;
F_325 ( V_6 ) ;
for ( V_487 = 0 ; V_487 < 2 ; V_487 ++ ) {
T_1 V_489 = 172800 * 1000 ;
T_1 V_490 = 64 ;
T_1 V_491 ;
V_491 = F_8 ( V_489 ,
clock << V_487 ) ;
V_485 = ( V_491 / V_490 ) - 2 ;
V_486 = V_491 % V_490 ;
if ( V_485 <= 0x7f )
break;
}
F_28 ( F_329 ( V_485 ) &
~ V_492 ) ;
F_28 ( F_330 ( V_488 ) &
~ V_493 ) ;
F_157 ( L_68 ,
clock ,
V_487 ,
V_485 ,
V_488 ,
V_486 ) ;
F_3 ( & V_6 -> V_9 ) ;
V_440 = F_326 ( V_6 , V_494 , V_483 ) ;
V_440 &= ~ V_492 ;
V_440 |= F_329 ( V_485 ) ;
V_440 &= ~ V_493 ;
V_440 |= F_331 ( V_486 ) ;
V_440 |= F_330 ( V_488 ) ;
V_440 |= V_495 ;
F_327 ( V_6 , V_494 , V_440 , V_483 ) ;
V_440 = F_326 ( V_6 , V_496 , V_483 ) ;
V_440 &= ~ F_332 ( 1 ) ;
V_440 |= F_332 ( V_487 ) ;
F_327 ( V_6 , V_496 , V_440 , V_483 ) ;
V_440 = F_326 ( V_6 , V_482 , V_483 ) ;
V_440 &= ~ V_484 ;
F_327 ( V_6 , V_482 , V_440 , V_483 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_124 ( 24 ) ;
F_122 ( V_480 , V_497 ) ;
}
int F_333 ( struct V_5 * V_6 )
{
T_1 V_485 , V_486 , V_487 ;
T_1 V_489 = 172800 * 1000 ;
T_1 V_490 = 64 ;
T_1 V_491 ;
T_1 V_440 ;
if ( ( F_11 ( V_480 ) & V_497 ) == 0 )
return 0 ;
F_3 ( & V_6 -> V_9 ) ;
V_440 = F_326 ( V_6 , V_482 , V_483 ) ;
if ( V_440 & V_484 ) {
F_5 ( & V_6 -> V_9 ) ;
return 0 ;
}
V_440 = F_326 ( V_6 , V_494 , V_483 ) ;
V_485 = ( V_440 & V_492 ) >>
V_498 ;
V_486 = ( V_440 & V_493 ) >>
V_499 ;
V_440 = F_326 ( V_6 , V_496 , V_483 ) ;
V_487 = ( V_440 & V_500 ) >>
V_501 ;
F_5 ( & V_6 -> V_9 ) ;
V_491 = ( V_485 + 2 ) * V_490 + V_486 ;
return F_8 ( V_489 ,
V_491 << V_487 ) ;
}
static void F_334 ( struct V_81 * V_65 ,
enum V_95 V_227 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_94 V_97 = V_65 -> V_91 -> V_97 ;
F_122 ( F_335 ( V_227 ) ,
F_11 ( F_336 ( V_97 ) ) ) ;
F_122 ( F_337 ( V_227 ) ,
F_11 ( F_338 ( V_97 ) ) ) ;
F_122 ( F_339 ( V_227 ) ,
F_11 ( F_340 ( V_97 ) ) ) ;
F_122 ( F_341 ( V_227 ) ,
F_11 ( F_342 ( V_97 ) ) ) ;
F_122 ( F_343 ( V_227 ) ,
F_11 ( F_344 ( V_97 ) ) ) ;
F_122 ( F_345 ( V_227 ) ,
F_11 ( F_346 ( V_97 ) ) ) ;
F_122 ( F_347 ( V_227 ) ,
F_11 ( F_348 ( V_97 ) ) ) ;
}
static void F_349 ( struct V_56 * V_57 , bool V_502 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_440 ;
V_440 = F_11 ( V_503 ) ;
if ( ! ! ( V_440 & V_504 ) == V_502 )
return;
F_28 ( F_11 ( F_71 ( V_126 ) ) & V_111 ) ;
F_28 ( F_11 ( F_71 ( V_505 ) ) & V_111 ) ;
V_440 &= ~ V_504 ;
if ( V_502 )
V_440 |= V_504 ;
F_157 ( L_69 , V_502 ? L_70 : L_71 ) ;
F_122 ( V_503 , V_440 ) ;
F_123 ( V_503 ) ;
}
static void F_350 ( struct V_81 * V_81 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
switch ( V_81 -> V_95 ) {
case V_117 :
break;
case V_126 :
if ( V_81 -> V_91 -> V_453 > 2 )
F_349 ( V_57 , false ) ;
else
F_349 ( V_57 , true ) ;
break;
case V_505 :
F_349 ( V_57 , true ) ;
break;
default:
F_144 () ;
}
}
static enum V_183
F_351 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_506 * V_507 ;
F_352 (dev, crtc, encoder) {
if ( V_507 -> type == V_508 ||
V_507 -> type == V_509 )
return F_353 ( & V_507 -> V_64 ) -> V_183 ;
}
return - 1 ;
}
static void F_354 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_1 V_440 ;
F_101 ( V_6 , V_95 ) ;
if ( F_299 ( V_57 ) )
F_350 ( V_81 ) ;
F_122 ( F_355 ( V_95 ) ,
F_11 ( F_356 ( V_95 ) ) & V_510 ) ;
V_6 -> V_431 . V_511 ( V_65 ) ;
if ( F_104 ( V_57 ) ) {
T_1 V_512 ;
V_440 = F_11 ( V_513 ) ;
V_440 |= F_357 ( V_95 ) ;
V_512 = F_358 ( V_95 ) ;
if ( V_81 -> V_91 -> V_211 ==
F_359 ( V_6 , V_514 ) )
V_440 |= V_512 ;
else
V_440 &= ~ V_512 ;
F_122 ( V_513 , V_440 ) ;
}
F_360 ( V_81 ) ;
F_74 ( V_6 , V_95 ) ;
F_334 ( V_81 , V_95 ) ;
F_298 ( V_65 ) ;
if ( F_104 ( V_57 ) && F_361 ( V_81 -> V_91 ) ) {
const struct V_515 * V_92 =
& V_81 -> V_91 -> V_64 . V_92 ;
T_1 V_516 = ( F_11 ( F_59 ( V_95 ) ) & V_213 ) >> 5 ;
T_3 V_13 = F_105 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ ( V_155 |
V_517 |
V_518 ) ;
V_440 |= V_519 ;
V_440 |= V_516 << 9 ;
if ( V_92 -> V_320 & V_520 )
V_440 |= V_521 ;
if ( V_92 -> V_320 & V_522 )
V_440 |= V_523 ;
switch ( F_351 ( V_65 ) ) {
case V_203 :
V_440 |= V_170 ;
break;
case V_205 :
V_440 |= V_172 ;
break;
case V_207 :
V_440 |= V_174 ;
break;
default:
F_144 () ;
}
F_122 ( V_13 , V_440 ) ;
}
F_146 ( V_6 , V_95 ) ;
}
static void F_362 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
enum V_94 V_97 = V_81 -> V_91 -> V_97 ;
F_101 ( V_6 , V_224 ) ;
F_328 ( V_65 ) ;
F_334 ( V_81 , V_117 ) ;
F_151 ( V_6 , V_97 ) ;
}
static void F_363 ( struct V_56 * V_57 , int V_95 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_3 V_524 = F_54 ( V_95 ) ;
T_1 V_440 ;
V_440 = F_11 ( V_524 ) ;
F_124 ( 500 ) ;
if ( F_61 ( F_11 ( V_524 ) != V_440 , 5 ) ) {
if ( F_61 ( F_11 ( V_524 ) != V_440 , 5 ) )
F_125 ( L_72 , F_76 ( V_95 ) ) ;
}
}
static int
F_364 ( struct V_37 * V_62 , bool V_525 ,
unsigned V_526 , int * V_406 , unsigned int V_252 ,
int V_336 , int V_337 , int V_409 , int V_410 )
{
struct V_373 * V_374 =
& V_62 -> V_374 ;
struct V_81 * V_81 =
F_47 ( V_62 -> V_64 . V_65 ) ;
int V_527 ;
V_527 = F_178 ( V_252 ) ?
( V_337 != V_409 || V_336 != V_410 ) :
( V_336 != V_409 || V_337 != V_410 ) ;
if ( V_525 || ! V_527 ) {
if ( * V_406 >= 0 ) {
V_374 -> V_528 &= ~ ( 1 << V_526 ) ;
V_374 -> V_376 [ * V_406 ] . V_377 = 0 ;
F_157 ( L_73
L_74 ,
V_81 -> V_95 , V_526 , * V_406 ,
V_374 -> V_528 ) ;
* V_406 = - 1 ;
}
return 0 ;
}
if ( V_336 < V_529 || V_337 < V_530 ||
V_409 < V_531 || V_410 < V_532 ||
V_336 > V_533 || V_337 > V_534 ||
V_409 > V_535 || V_410 > V_536 ) {
F_157 ( L_75
L_76 ,
V_81 -> V_95 , V_526 , V_336 , V_337 , V_409 , V_410 ) ;
return - V_537 ;
}
V_374 -> V_528 |= ( 1 << V_526 ) ;
F_157 ( L_73
L_77 ,
V_81 -> V_95 , V_526 , V_336 , V_337 , V_409 , V_410 ,
V_374 -> V_528 ) ;
return 0 ;
}
int F_365 ( struct V_37 * V_43 )
{
struct V_81 * V_81 = F_47 ( V_43 -> V_64 . V_65 ) ;
const struct V_515 * V_92 = & V_43 -> V_64 . V_92 ;
F_157 ( L_78 ,
V_81 -> V_64 . V_64 . V_372 , V_81 -> V_64 . V_12 ,
V_81 -> V_95 , V_538 ) ;
return F_364 ( V_43 , ! V_43 -> V_64 . V_88 , V_538 ,
& V_43 -> V_374 . V_406 , F_226 ( V_393 ) ,
V_43 -> V_356 , V_43 -> V_355 ,
V_92 -> V_539 , V_92 -> V_540 ) ;
}
static int F_366 ( struct V_37 * V_62 ,
struct V_328 * V_326 )
{
struct V_81 * V_81 = F_47 ( V_62 -> V_64 . V_65 ) ;
struct V_327 * V_327 =
F_213 ( V_326 -> V_64 . V_140 ) ;
struct V_251 * V_90 = V_326 -> V_64 . V_90 ;
int V_267 ;
bool V_525 = ! V_90 || ! V_326 -> V_331 ;
F_157 ( L_79 ,
V_327 -> V_64 . V_64 . V_372 , V_327 -> V_64 . V_12 ,
V_81 -> V_95 , F_218 ( & V_327 -> V_64 ) ) ;
V_267 = F_364 ( V_62 , V_525 ,
F_218 ( & V_327 -> V_64 ) ,
& V_326 -> V_406 ,
V_326 -> V_64 . V_252 ,
F_251 ( & V_326 -> V_342 ) >> 16 ,
F_252 ( & V_326 -> V_342 ) >> 16 ,
F_251 ( & V_326 -> V_346 ) ,
F_252 ( & V_326 -> V_346 ) ) ;
if ( V_267 || V_326 -> V_406 < 0 )
return V_267 ;
if ( V_326 -> V_541 . V_320 != V_542 ) {
F_157 ( L_80 ,
V_327 -> V_64 . V_64 . V_372 ,
V_327 -> V_64 . V_12 ) ;
return - V_537 ;
}
switch ( V_90 -> V_244 ) {
case V_290 :
case V_294 :
case V_292 :
case V_303 :
case V_304 :
case V_296 :
case V_298 :
case V_381 :
case V_384 :
case V_386 :
case V_388 :
break;
default:
F_157 ( L_81 ,
V_327 -> V_64 . V_64 . V_372 , V_327 -> V_64 . V_12 ,
V_90 -> V_64 . V_372 , V_90 -> V_244 ) ;
return - V_537 ;
}
return 0 ;
}
static void F_367 ( struct V_81 * V_65 )
{
int V_142 ;
for ( V_142 = 0 ; V_142 < V_65 -> V_375 ; V_142 ++ )
F_242 ( V_65 , V_142 ) ;
}
static void F_295 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_65 -> V_95 ;
struct V_373 * V_374 =
& V_65 -> V_91 -> V_374 ;
F_157 ( L_82 , V_65 -> V_91 ) ;
if ( V_65 -> V_91 -> V_439 . V_151 ) {
int V_372 ;
if ( F_28 ( V_65 -> V_91 -> V_374 . V_406 < 0 ) ) {
F_125 ( L_83 ) ;
return;
}
V_372 = V_374 -> V_406 ;
F_122 ( F_243 ( V_95 , V_372 ) , V_415 |
V_543 | V_374 -> V_376 [ V_372 ] . V_416 ) ;
F_122 ( F_244 ( V_95 , V_372 ) , V_65 -> V_91 -> V_439 . V_544 ) ;
F_122 ( F_245 ( V_95 , V_372 ) , V_65 -> V_91 -> V_439 . V_247 ) ;
F_157 ( L_84 , V_65 -> V_91 , V_372 ) ;
}
}
static void F_296 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_65 -> V_95 ;
if ( V_65 -> V_91 -> V_439 . V_151 ) {
if ( F_299 ( V_57 ) || F_234 ( V_57 ) )
F_122 ( F_368 ( V_95 ) , V_545 | V_546 |
F_369 ( V_95 ) ) ;
else
F_122 ( F_368 ( V_95 ) , V_545 | V_546 ) ;
F_122 ( F_370 ( V_95 ) , V_65 -> V_91 -> V_439 . V_544 ) ;
F_122 ( F_371 ( V_95 ) , V_65 -> V_91 -> V_439 . V_247 ) ;
}
}
void F_372 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( ! V_65 -> V_91 -> V_547 )
return;
F_373 ( V_6 , V_65 -> V_140 ) ;
if ( F_235 ( V_57 ) ) {
F_3 ( & V_6 -> V_548 . V_549 ) ;
F_28 ( F_374 ( V_6 , V_550 , 0xc0000000 ) ) ;
F_5 ( & V_6 -> V_548 . V_549 ) ;
} else {
F_122 ( V_551 , V_552 ) ;
if ( F_60 ( V_6 ,
V_551 , V_552 , V_552 ,
50 ) )
F_125 ( L_85 ) ;
}
}
void F_375 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( ! V_65 -> V_91 -> V_547 )
return;
F_373 ( V_6 , V_65 -> V_140 ) ;
if ( F_235 ( V_57 ) ) {
F_3 ( & V_6 -> V_548 . V_549 ) ;
F_28 ( F_374 ( V_6 , V_550 , 0 ) ) ;
F_5 ( & V_6 -> V_548 . V_549 ) ;
if ( F_60 ( V_6 ,
V_551 , V_552 , 0 ,
42 ) )
F_125 ( L_86 ) ;
} else {
F_122 ( V_551 , 0 ) ;
F_123 ( V_551 ) ;
}
F_315 ( V_57 , V_65 -> V_95 ) ;
}
static void F_376 ( struct V_81 * V_81 )
{
if ( V_81 -> V_553 ) {
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
F_3 ( & V_57 -> V_268 ) ;
V_6 -> V_554 . V_555 = false ;
( void ) F_377 ( V_81 -> V_553 ) ;
V_6 -> V_554 . V_555 = true ;
F_5 ( & V_57 -> V_268 ) ;
}
}
static void
F_378 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
F_372 ( V_81 ) ;
if ( F_55 ( V_57 ) )
F_379 ( V_6 , V_95 , true ) ;
F_380 ( V_6 ) ;
F_381 ( V_6 ) ;
}
static void
F_382 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
if ( F_55 ( V_57 ) )
F_379 ( V_6 , V_95 , false ) ;
F_375 ( V_81 ) ;
}
static void
F_219 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
F_382 ( V_65 ) ;
if ( F_160 ( V_57 ) ) {
F_383 ( V_6 , false ) ;
V_6 -> V_556 . V_557 . V_558 = false ;
F_315 ( V_57 , V_95 ) ;
}
}
static void F_384 ( struct V_37 * V_438 )
{
struct V_81 * V_65 = F_47 ( V_438 -> V_64 . V_65 ) ;
struct V_420 * V_559 = V_438 -> V_64 . V_43 ;
struct V_37 * V_38 =
F_265 ( V_65 -> V_64 . V_43 ) ;
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_323 * V_89 = V_65 -> V_64 . V_89 ;
struct V_325 * V_560 =
F_385 ( V_559 , V_89 ) ;
F_386 ( V_57 , V_38 -> V_561 ) ;
V_65 -> V_556 . V_562 = true ;
if ( V_38 -> V_563 && V_38 -> V_64 . V_88 )
F_387 ( & V_65 -> V_64 ) ;
if ( V_560 ) {
struct V_328 * V_564 =
F_214 ( V_89 -> V_43 ) ;
struct V_328 * V_565 =
F_214 ( V_560 ) ;
F_388 ( V_65 ) ;
if ( V_564 -> V_331 &&
( F_25 ( & V_38 -> V_64 ) ||
! V_565 -> V_331 ) )
F_378 ( & V_65 -> V_64 ) ;
}
}
static void F_389 ( struct V_37 * V_438 )
{
struct V_81 * V_65 = F_47 ( V_438 -> V_64 . V_65 ) ;
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_37 * V_38 =
F_265 ( V_65 -> V_64 . V_43 ) ;
struct V_420 * V_559 = V_438 -> V_64 . V_43 ;
struct V_323 * V_89 = V_65 -> V_64 . V_89 ;
struct V_325 * V_560 =
F_385 ( V_559 , V_89 ) ;
bool V_566 = F_25 ( & V_38 -> V_64 ) ;
if ( V_560 ) {
struct V_328 * V_564 =
F_214 ( V_89 -> V_43 ) ;
struct V_328 * V_565 =
F_214 ( V_560 ) ;
F_390 ( V_65 , V_38 , V_564 ) ;
if ( V_565 -> V_331 &&
( V_566 || ! V_564 -> V_331 ) )
F_382 ( & V_65 -> V_64 ) ;
}
if ( V_38 -> V_567 && F_160 ( V_57 ) ) {
V_65 -> V_556 . V_562 = false ;
if ( V_438 -> V_64 . V_88 ) {
F_383 ( V_6 , false ) ;
V_6 -> V_556 . V_557 . V_558 = false ;
F_315 ( V_57 , V_65 -> V_95 ) ;
}
}
if ( V_38 -> V_568 ) {
F_391 ( V_57 ) ;
F_315 ( V_57 , V_65 -> V_95 ) ;
}
if ( F_25 ( & V_38 -> V_64 ) )
return;
if ( V_6 -> V_431 . V_569 != NULL )
V_6 -> V_431 . V_569 ( V_38 ) ;
else if ( V_38 -> V_570 )
F_387 ( & V_65 -> V_64 ) ;
}
static void F_392 ( struct V_87 * V_65 , unsigned V_332 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_323 * V_48 ;
int V_95 = V_81 -> V_95 ;
F_376 ( V_81 ) ;
F_393 (p, dev, plane_mask)
F_213 ( V_48 ) -> V_333 ( V_48 , V_65 ) ;
F_386 ( V_57 , F_394 ( V_95 ) ) ;
}
static void F_395 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_506 * V_507 ;
int V_95 = V_81 -> V_95 ;
struct V_37 * V_38 =
F_265 ( V_65 -> V_43 ) ;
if ( F_28 ( V_81 -> V_88 ) )
return;
if ( V_81 -> V_91 -> V_229 || F_24 ( V_6 ) )
F_379 ( V_6 , V_95 , false ) ;
if ( V_81 -> V_91 -> V_229 )
F_396 ( V_6 , V_95 , false ) ;
if ( V_81 -> V_91 -> V_229 )
F_397 ( V_81 ) ;
if ( F_361 ( V_81 -> V_91 ) )
F_398 ( V_81 , V_571 ) ;
F_399 ( V_81 ) ;
F_400 ( V_81 ) ;
if ( V_81 -> V_91 -> V_229 ) {
F_401 ( V_81 ,
& V_81 -> V_91 -> V_572 , NULL ) ;
}
F_402 ( V_65 ) ;
V_81 -> V_88 = true ;
F_352 (dev, crtc, encoder)
if ( V_507 -> V_573 )
V_507 -> V_573 ( V_507 ) ;
if ( V_81 -> V_91 -> V_229 ) {
F_310 ( V_81 ) ;
} else {
F_153 ( V_6 , V_95 ) ;
F_154 ( V_6 , V_95 ) ;
}
F_296 ( V_81 ) ;
F_403 ( & V_38 -> V_64 ) ;
if ( V_6 -> V_431 . V_569 != NULL )
V_6 -> V_431 . V_569 ( V_81 -> V_91 ) ;
F_156 ( V_81 ) ;
if ( V_81 -> V_91 -> V_229 )
F_354 ( V_65 ) ;
F_97 ( V_65 ) ;
F_404 ( V_65 ) ;
F_352 (dev, crtc, encoder)
V_507 -> V_502 ( V_507 ) ;
if ( F_104 ( V_57 ) )
F_363 ( V_57 , V_81 -> V_95 ) ;
if ( V_81 -> V_91 -> V_229 )
F_315 ( V_57 , V_95 ) ;
F_379 ( V_6 , V_95 , true ) ;
F_396 ( V_6 , V_95 , true ) ;
}
static bool F_405 ( struct V_81 * V_65 )
{
return F_406 ( V_65 -> V_64 . V_57 ) && V_65 -> V_95 == V_117 ;
}
static void F_407 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_506 * V_507 ;
int V_95 = V_81 -> V_95 , V_574 ;
enum V_94 V_97 = V_81 -> V_91 -> V_97 ;
struct V_37 * V_38 =
F_265 ( V_65 -> V_43 ) ;
if ( F_28 ( V_81 -> V_88 ) )
return;
if ( V_81 -> V_91 -> V_229 )
F_396 ( V_6 , V_224 ,
false ) ;
F_352 (dev, crtc, encoder)
if ( V_507 -> V_575 )
V_507 -> V_575 ( V_507 ) ;
if ( V_81 -> V_91 -> V_211 )
F_360 ( V_81 ) ;
if ( F_361 ( V_81 -> V_91 ) )
F_398 ( V_81 , V_571 ) ;
if ( ! F_408 ( V_97 ) )
F_399 ( V_81 ) ;
F_400 ( V_81 ) ;
if ( V_97 != V_576 &&
! F_408 ( V_97 ) ) {
F_122 ( F_409 ( V_97 ) ,
V_81 -> V_91 -> V_577 - 1 ) ;
}
if ( V_81 -> V_91 -> V_229 ) {
F_401 ( V_81 ,
& V_81 -> V_91 -> V_572 , NULL ) ;
}
if ( ! F_408 ( V_97 ) )
F_410 ( V_65 ) ;
F_411 ( V_65 ) ;
F_412 ( & V_38 -> V_64 ) ;
V_81 -> V_88 = true ;
if ( V_81 -> V_91 -> V_229 )
F_379 ( V_6 , V_95 , false ) ;
else
F_379 ( V_6 , V_95 , true ) ;
F_352 (dev, crtc, encoder) {
if ( V_507 -> V_573 )
V_507 -> V_573 ( V_507 ) ;
}
if ( V_81 -> V_91 -> V_229 )
V_6 -> V_431 . V_511 ( V_65 ) ;
if ( ! F_408 ( V_97 ) )
F_413 ( V_81 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 9 )
F_295 ( V_81 ) ;
else
F_296 ( V_81 ) ;
F_403 ( & V_38 -> V_64 ) ;
F_414 ( V_65 ) ;
if ( ! F_408 ( V_97 ) )
F_415 ( V_65 ) ;
if ( V_6 -> V_431 . V_569 != NULL )
V_6 -> V_431 . V_569 ( V_38 ) ;
else
F_387 ( V_65 ) ;
if ( ! F_408 ( V_97 ) )
F_156 ( V_81 ) ;
if ( V_81 -> V_91 -> V_229 )
F_362 ( V_65 ) ;
if ( V_81 -> V_91 -> V_578 )
F_416 ( V_65 , true ) ;
F_97 ( V_65 ) ;
F_404 ( V_65 ) ;
F_352 (dev, crtc, encoder) {
V_507 -> V_502 ( V_507 ) ;
F_417 ( V_507 , true ) ;
}
if ( V_81 -> V_91 -> V_229 ) {
F_315 ( V_57 , V_95 ) ;
F_315 ( V_57 , V_95 ) ;
F_379 ( V_6 , V_95 , true ) ;
F_396 ( V_6 , V_224 ,
true ) ;
}
V_574 = V_38 -> V_574 ;
if ( F_234 ( V_57 ) && V_574 != V_579 ) {
F_315 ( V_57 , V_574 ) ;
F_315 ( V_57 , V_574 ) ;
}
}
static void F_297 ( struct V_81 * V_65 , bool V_580 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_65 -> V_95 ;
if ( V_580 || V_65 -> V_91 -> V_439 . V_151 ) {
F_122 ( F_368 ( V_95 ) , 0 ) ;
F_122 ( F_370 ( V_95 ) , 0 ) ;
F_122 ( F_371 ( V_95 ) , 0 ) ;
}
}
static void F_418 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_506 * V_507 ;
int V_95 = V_81 -> V_95 ;
if ( V_81 -> V_91 -> V_229 ) {
F_379 ( V_6 , V_95 , false ) ;
F_396 ( V_6 , V_95 , false ) ;
}
F_352 (dev, crtc, encoder)
V_507 -> V_581 ( V_507 ) ;
F_419 ( V_65 ) ;
F_97 ( V_65 ) ;
F_165 ( V_81 ) ;
F_297 ( V_81 , false ) ;
if ( V_81 -> V_91 -> V_229 )
F_312 ( V_65 ) ;
F_352 (dev, crtc, encoder)
if ( V_507 -> V_582 )
V_507 -> V_582 ( V_507 ) ;
if ( V_81 -> V_91 -> V_229 ) {
F_152 ( V_6 , V_95 ) ;
if ( F_104 ( V_57 ) ) {
T_3 V_13 ;
T_1 V_440 ;
V_13 = F_105 ( V_95 ) ;
V_440 = F_11 ( V_13 ) ;
V_440 &= ~ ( V_519 |
V_155 ) ;
V_440 |= V_583 ;
F_122 ( V_13 , V_440 ) ;
V_440 = F_11 ( V_513 ) ;
V_440 &= ~ ( F_357 ( V_95 ) | F_358 ( V_95 ) ) ;
F_122 ( V_513 , V_440 ) ;
}
F_311 ( V_81 ) ;
}
F_379 ( V_6 , V_95 , true ) ;
F_396 ( V_6 , V_95 , true ) ;
}
static void F_420 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_506 * V_507 ;
enum V_94 V_97 = V_81 -> V_91 -> V_97 ;
if ( V_81 -> V_91 -> V_229 )
F_396 ( V_6 , V_224 ,
false ) ;
F_352 (dev, crtc, encoder) {
F_417 ( V_507 , false ) ;
V_507 -> V_581 ( V_507 ) ;
}
F_419 ( V_65 ) ;
F_97 ( V_65 ) ;
if ( ! F_408 ( V_97 ) )
F_165 ( V_81 ) ;
if ( V_81 -> V_91 -> V_578 )
F_416 ( V_65 , false ) ;
if ( ! F_408 ( V_97 ) )
F_421 ( V_6 , V_97 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 9 )
F_367 ( V_81 ) ;
else
F_297 ( V_81 , false ) ;
if ( ! F_408 ( V_97 ) )
F_422 ( V_81 ) ;
F_352 (dev, crtc, encoder)
if ( V_507 -> V_582 )
V_507 -> V_582 ( V_507 ) ;
if ( V_81 -> V_91 -> V_229 ) {
F_155 ( V_6 ) ;
F_325 ( V_6 ) ;
F_423 ( V_65 ) ;
F_396 ( V_6 , V_224 ,
true ) ;
}
}
static void F_424 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_37 * V_38 = V_65 -> V_91 ;
if ( ! V_38 -> V_584 . V_585 )
return;
F_28 ( F_11 ( V_586 ) & V_587 ) ;
F_127 ( V_6 , V_65 -> V_95 ) ;
F_122 ( V_588 , V_38 -> V_584 . V_589 ) ;
F_122 ( V_586 , V_38 -> V_584 . V_585 ) ;
F_122 ( F_425 ( V_65 -> V_95 ) , 0 ) ;
}
static enum V_134 F_426 ( enum V_183 V_183 )
{
switch ( V_183 ) {
case V_590 :
return V_591 ;
case V_203 :
return V_592 ;
case V_205 :
return V_593 ;
case V_207 :
return V_594 ;
case V_595 :
return V_596 ;
default:
F_169 ( V_183 ) ;
return V_597 ;
}
}
static enum V_134 F_427 ( enum V_183 V_183 )
{
switch ( V_183 ) {
case V_590 :
return V_598 ;
case V_203 :
return V_599 ;
case V_205 :
return V_600 ;
case V_207 :
return V_601 ;
case V_595 :
return V_601 ;
default:
F_169 ( V_183 ) ;
return V_598 ;
}
}
enum V_134
F_428 ( struct V_506 * V_506 )
{
struct V_56 * V_57 = V_506 -> V_64 . V_57 ;
struct V_198 * V_602 ;
switch ( V_506 -> type ) {
case V_603 :
F_44 ( ! F_23 ( V_57 ) ) ;
case V_508 :
case V_214 :
case V_509 :
V_602 = F_353 ( & V_506 -> V_64 ) ;
return F_426 ( V_602 -> V_183 ) ;
case V_604 :
V_602 = F_429 ( & V_506 -> V_64 ) -> V_89 ;
return F_426 ( V_602 -> V_183 ) ;
case V_605 :
return V_606 ;
case V_228 :
return V_607 ;
default:
return V_597 ;
}
}
enum V_134
F_430 ( struct V_506 * V_506 )
{
struct V_56 * V_57 = V_506 -> V_64 . V_57 ;
struct V_198 * V_602 ;
switch ( V_506 -> type ) {
case V_603 :
case V_214 :
F_44 ( ! F_23 ( V_57 ) ) ;
case V_508 :
case V_509 :
V_602 = F_353 ( & V_506 -> V_64 ) ;
return F_427 ( V_602 -> V_183 ) ;
case V_604 :
V_602 = F_429 ( & V_506 -> V_64 ) -> V_89 ;
return F_427 ( V_602 -> V_183 ) ;
default:
F_169 ( V_506 -> type ) ;
return V_598 ;
}
}
static unsigned long F_431 ( struct V_87 * V_65 ,
struct V_37 * V_62 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_608 * V_507 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
enum V_95 V_95 = V_81 -> V_95 ;
unsigned long V_609 ;
enum V_94 V_94 = V_62 -> V_97 ;
if ( ! V_62 -> V_64 . V_88 )
return 0 ;
V_609 = F_226 ( F_432 ( V_95 ) ) ;
V_609 |= F_226 ( F_82 ( V_94 ) ) ;
if ( V_62 -> V_439 . V_151 ||
V_62 -> V_439 . V_610 )
V_609 |= F_226 ( F_433 ( V_95 ) ) ;
F_434 (encoder, dev, crtc_state->base.encoder_mask) {
struct V_506 * V_506 = F_435 ( V_507 ) ;
V_609 |= F_226 ( F_428 ( V_506 ) ) ;
}
if ( V_62 -> V_211 )
V_609 |= F_226 ( V_611 ) ;
return V_609 ;
}
static unsigned long
F_436 ( struct V_87 * V_65 ,
struct V_37 * V_62 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
enum V_134 V_612 ;
unsigned long V_613 , V_614 , V_615 ;
V_615 = V_81 -> V_616 ;
V_81 -> V_616 = V_614 =
F_431 ( V_65 , V_62 ) ;
V_613 = V_614 & ~ V_615 ;
F_437 (domain, domains)
F_438 ( V_6 , V_612 ) ;
return V_615 & ~ V_614 ;
}
static void F_439 ( struct V_5 * V_6 ,
unsigned long V_613 )
{
enum V_134 V_612 ;
F_437 (domain, domains)
F_84 ( V_6 , V_612 ) ;
}
static int F_440 ( struct V_5 * V_6 )
{
int V_617 = V_6 -> V_617 ;
if ( F_58 ( V_6 ) -> V_103 >= 9 ||
F_234 ( V_6 ) || F_235 ( V_6 ) )
return V_617 ;
else if ( F_17 ( V_6 ) )
return V_617 * 95 / 100 ;
else if ( F_58 ( V_6 ) -> V_103 < 4 )
return 2 * V_617 * 90 / 100 ;
else
return V_617 * 90 / 100 ;
}
static void F_441 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( F_442 ( V_57 ) || F_443 ( V_57 ) ) {
T_1 V_59 = F_11 ( V_618 ) & V_619 ;
int V_620 , V_52 ;
V_52 = V_6 -> V_621 ;
F_28 ( V_52 != 8100000 && V_52 != 8640000 ) ;
if ( V_59 == V_622 )
V_620 = 617143 ;
else if ( V_59 == V_623 )
V_620 = 540000 ;
else if ( V_59 == V_624 )
V_620 = 432000 ;
else
V_620 = 308571 ;
V_6 -> V_617 = F_444 ( V_620 , V_52 ) ;
} else if ( F_36 ( V_57 ) ) {
V_6 -> V_617 = 624000 ;
} else if ( F_235 ( V_57 ) ) {
if ( F_11 ( V_625 ) & V_626 )
V_6 -> V_617 = 450000 ;
else if ( F_445 ( V_57 ) )
V_6 -> V_617 = 450000 ;
else if ( F_446 ( V_57 ) )
V_6 -> V_617 = 540000 ;
else
V_6 -> V_617 = 675000 ;
} else if ( F_17 ( V_57 ) ) {
V_6 -> V_617 = 320000 ;
} else if ( F_16 ( V_57 ) ) {
V_6 -> V_617 = 400000 ;
} else {
V_6 -> V_617 = V_6 -> V_627 ;
}
V_6 -> V_628 = F_440 ( V_6 ) ;
F_20 ( L_87 ,
V_6 -> V_617 ) ;
F_20 ( L_88 ,
V_6 -> V_628 ) ;
}
static void F_447 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
V_6 -> V_627 = V_6 -> V_431 . V_629 ( V_57 ) ;
if ( F_276 ( V_6 ) >= 9 )
F_20 ( L_89 ,
V_6 -> V_627 , V_6 -> V_630 . V_52 ,
V_6 -> V_630 . V_631 ) ;
else
F_20 ( L_90 ,
V_6 -> V_627 ) ;
if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
F_122 ( V_632 , F_181 ( V_6 -> V_627 , 1000 ) ) ;
}
static int F_448 ( int V_633 )
{
return F_8 ( V_633 - 1000 , 500 ) ;
}
static int F_449 ( struct V_5 * V_6 , int V_633 )
{
int V_634 ;
if ( V_633 == V_6 -> V_630 . V_631 )
return 0 ;
switch ( V_633 ) {
default:
F_169 ( V_633 ) ;
case 144000 :
case 288000 :
case 384000 :
case 576000 :
V_634 = 60 ;
break;
case 624000 :
V_634 = 65 ;
break;
}
return V_6 -> V_630 . V_631 * V_634 ;
}
static void F_450 ( struct V_5 * V_6 )
{
F_122 ( V_635 , 0 ) ;
if ( F_60 ( V_6 ,
V_635 , V_636 , 0 ,
1 ) )
F_125 ( L_91 ) ;
V_6 -> V_630 . V_52 = 0 ;
}
static void F_451 ( struct V_5 * V_6 , int V_52 )
{
int V_634 = F_8 ( V_52 , V_6 -> V_630 . V_631 ) ;
T_1 V_15 ;
V_15 = F_11 ( V_637 ) ;
V_15 &= ~ V_638 ;
V_15 |= F_452 ( V_634 ) ;
F_122 ( V_637 , V_15 ) ;
F_122 ( V_635 , V_639 ) ;
if ( F_60 ( V_6 ,
V_635 ,
V_636 ,
V_636 ,
1 ) )
F_125 ( L_92 ) ;
V_6 -> V_630 . V_52 = V_52 ;
}
static void F_453 ( struct V_5 * V_6 , int V_633 )
{
T_1 V_15 , V_16 ;
int V_52 , V_267 ;
V_52 = F_449 ( V_6 , V_633 ) ;
F_20 ( L_93 , V_633 , V_52 ) ;
switch ( F_8 ( V_52 , V_633 ) ) {
case 8 :
V_16 = V_640 ;
break;
case 4 :
V_16 = V_641 ;
break;
case 3 :
V_16 = V_642 ;
break;
case 2 :
V_16 = V_643 ;
break;
default:
F_28 ( V_633 != V_6 -> V_630 . V_631 ) ;
F_28 ( V_52 != 0 ) ;
V_16 = V_643 ;
break;
}
F_3 ( & V_6 -> V_548 . V_549 ) ;
V_267 = F_374 ( V_6 , V_644 ,
0x80000000 ) ;
F_5 ( & V_6 -> V_548 . V_549 ) ;
if ( V_267 ) {
F_125 ( L_94 ,
V_267 , V_633 ) ;
return;
}
if ( V_6 -> V_630 . V_52 != 0 &&
V_6 -> V_630 . V_52 != V_52 )
F_450 ( V_6 ) ;
if ( V_6 -> V_630 . V_52 != V_52 )
F_451 ( V_6 , V_52 ) ;
V_15 = V_16 | F_448 ( V_633 ) ;
V_15 |= V_645 ;
if ( V_633 >= 500000 )
V_15 |= V_646 ;
F_122 ( V_647 , V_15 ) ;
F_3 ( & V_6 -> V_548 . V_549 ) ;
V_267 = F_374 ( V_6 , V_644 ,
F_181 ( V_633 , 25000 ) ) ;
F_5 ( & V_6 -> V_548 . V_549 ) ;
if ( V_267 ) {
F_125 ( L_95 ,
V_267 , V_633 ) ;
return;
}
F_447 ( & V_6 -> V_114 ) ;
}
static void F_454 ( struct V_5 * V_6 )
{
T_1 V_648 , V_649 ;
F_447 ( & V_6 -> V_114 ) ;
if ( V_6 -> V_630 . V_52 == 0 ||
V_6 -> V_627 == V_6 -> V_630 . V_631 )
goto V_650;
V_648 = F_11 ( V_647 ) ;
V_648 &= ~ V_645 ;
V_649 = ( V_648 & V_651 ) |
F_448 ( V_6 -> V_627 ) ;
if ( V_6 -> V_627 >= 500000 )
V_649 |= V_646 ;
if ( V_648 == V_649 )
return;
V_650:
F_157 ( L_96 ) ;
V_6 -> V_627 = 0 ;
V_6 -> V_630 . V_52 = - 1 ;
}
void F_455 ( struct V_5 * V_6 )
{
F_454 ( V_6 ) ;
if ( V_6 -> V_627 != 0 && V_6 -> V_630 . V_52 != 0 )
return;
F_453 ( V_6 , F_456 ( 0 ) ) ;
}
void F_457 ( struct V_5 * V_6 )
{
F_453 ( V_6 , V_6 -> V_630 . V_631 ) ;
}
static int F_444 ( int V_652 , int V_52 )
{
if ( V_52 == 8640000 ) {
if ( V_652 > 540000 )
return 617143 ;
else if ( V_652 > 432000 )
return 540000 ;
else if ( V_652 > 308571 )
return 432000 ;
else
return 308571 ;
} else {
if ( V_652 > 540000 )
return 675000 ;
else if ( V_652 > 450000 )
return 540000 ;
else if ( V_652 > 337500 )
return 450000 ;
else
return 337500 ;
}
}
static void
F_458 ( struct V_5 * V_6 )
{
T_1 V_15 ;
V_6 -> V_630 . V_631 = 24000 ;
V_6 -> V_630 . V_52 = 0 ;
V_15 = F_11 ( V_653 ) ;
if ( ( V_15 & V_654 ) == 0 )
return;
if ( F_28 ( ( V_15 & V_655 ) == 0 ) )
return;
V_15 = F_11 ( V_656 ) ;
if ( F_28 ( ( V_15 & ( F_459 ( V_657 ) |
F_460 ( V_657 ) |
F_461 ( V_657 ) ) ) !=
F_461 ( V_657 ) ) )
return;
switch ( V_15 & F_462 ( V_657 ) ) {
case F_463 ( V_658 , V_657 ) :
case F_463 ( V_659 , V_657 ) :
case F_463 ( V_660 , V_657 ) :
case F_463 ( V_661 , V_657 ) :
V_6 -> V_630 . V_52 = 8100000 ;
break;
case F_463 ( V_662 , V_657 ) :
case F_463 ( V_663 , V_657 ) :
V_6 -> V_630 . V_52 = 8640000 ;
break;
default:
F_169 ( V_15 & F_462 ( V_657 ) ) ;
break;
}
}
void F_464 ( struct V_5 * V_6 , int V_52 )
{
bool V_664 = V_6 -> V_621 != V_52 ;
V_6 -> V_621 = V_52 ;
if ( V_664 )
F_441 ( & V_6 -> V_114 ) ;
}
static void
F_465 ( struct V_5 * V_6 , int V_52 )
{
int V_665 = F_444 ( 0 , V_52 ) ;
T_1 V_15 ;
F_28 ( V_52 != 8100000 && V_52 != 8640000 ) ;
V_15 = V_666 | F_448 ( V_665 ) ;
F_122 ( V_647 , V_15 ) ;
F_123 ( V_647 ) ;
V_15 = F_11 ( V_656 ) ;
V_15 &= ~ ( F_459 ( V_657 ) | F_460 ( V_657 ) |
F_462 ( V_657 ) ) ;
V_15 |= F_461 ( V_657 ) ;
if ( V_52 == 8640000 )
V_15 |= F_463 ( V_662 ,
V_657 ) ;
else
V_15 |= F_463 ( V_658 ,
V_657 ) ;
F_122 ( V_656 , V_15 ) ;
F_123 ( V_656 ) ;
F_122 ( V_653 , F_11 ( V_653 ) | V_654 ) ;
if ( F_60 ( V_6 ,
V_653 , V_655 , V_655 ,
5 ) )
F_125 ( L_97 ) ;
V_6 -> V_630 . V_52 = V_52 ;
F_464 ( V_6 , V_52 ) ;
}
static void
F_466 ( struct V_5 * V_6 )
{
F_122 ( V_653 , F_11 ( V_653 ) & ~ V_654 ) ;
if ( F_60 ( V_6 ,
V_653 , V_655 , 0 ,
1 ) )
F_125 ( L_98 ) ;
V_6 -> V_630 . V_52 = 0 ;
}
static bool F_467 ( struct V_5 * V_6 )
{
int V_267 ;
T_1 V_15 ;
V_15 = V_667 ;
F_3 ( & V_6 -> V_548 . V_549 ) ;
V_267 = F_468 ( V_6 , V_668 , & V_15 ) ;
F_5 ( & V_6 -> V_548 . V_549 ) ;
return V_267 == 0 && ( V_15 & V_669 ) ;
}
static bool F_469 ( struct V_5 * V_6 )
{
return F_470 ( F_467 ( V_6 ) , 3000 , 10 ) == 0 ;
}
static void F_471 ( struct V_5 * V_6 , int V_633 , int V_52 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
T_1 V_670 , V_671 ;
F_28 ( ( V_633 == 24000 ) != ( V_52 == 0 ) ) ;
F_20 ( L_93 , V_633 , V_52 ) ;
if ( ! F_469 ( V_6 ) ) {
F_125 ( L_99 ) ;
return;
}
switch ( V_633 ) {
case 450000 :
case 432000 :
V_670 = V_672 ;
V_671 = 1 ;
break;
case 540000 :
V_670 = V_673 ;
V_671 = 2 ;
break;
case 308571 :
case 337500 :
default:
V_670 = V_666 ;
V_671 = 0 ;
break;
case 617143 :
case 675000 :
V_670 = V_674 ;
V_671 = 3 ;
break;
}
if ( V_6 -> V_630 . V_52 != 0 &&
V_6 -> V_630 . V_52 != V_52 )
F_466 ( V_6 ) ;
if ( V_6 -> V_630 . V_52 != V_52 )
F_465 ( V_6 , V_52 ) ;
F_122 ( V_647 , V_670 | F_448 ( V_633 ) ) ;
F_123 ( V_647 ) ;
F_3 ( & V_6 -> V_548 . V_549 ) ;
F_374 ( V_6 , V_668 , V_671 ) ;
F_5 ( & V_6 -> V_548 . V_549 ) ;
F_447 ( V_57 ) ;
}
void F_472 ( struct V_5 * V_6 )
{
F_471 ( V_6 , V_6 -> V_630 . V_631 , 0 ) ;
}
void F_473 ( struct V_5 * V_6 )
{
int V_633 , V_52 ;
F_474 ( V_6 ) ;
if ( V_6 -> V_627 != 0 && V_6 -> V_630 . V_52 != 0 ) {
if ( V_6 -> V_621 == 0 )
F_464 ( V_6 ,
V_6 -> V_630 . V_52 ) ;
return;
}
V_52 = V_6 -> V_621 ;
if ( V_52 == 0 )
V_52 = 8100000 ;
V_633 = F_444 ( 0 , V_52 ) ;
F_471 ( V_6 , V_633 , V_52 ) ;
}
static void F_474 ( struct V_5 * V_6 )
{
T_2 V_648 , V_649 ;
if ( ( F_11 ( F_475 ( 0x18 ) ) & 0x00FFFFFF ) == 0 )
goto V_650;
F_447 ( & V_6 -> V_114 ) ;
if ( V_6 -> V_630 . V_52 == 0 ||
V_6 -> V_627 == V_6 -> V_630 . V_631 )
goto V_650;
V_648 = F_11 ( V_647 ) ;
V_649 = ( V_648 & V_675 ) |
F_448 ( V_6 -> V_627 ) ;
if ( V_648 == V_649 )
return;
V_650:
F_157 ( L_96 ) ;
V_6 -> V_627 = 0 ;
V_6 -> V_630 . V_52 = - 1 ;
}
static void F_476 ( struct V_56 * V_57 , int V_633 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_15 , V_676 ;
F_28 ( V_6 -> V_431 . V_629 ( V_57 )
!= V_6 -> V_627 ) ;
if ( V_633 >= 320000 )
V_676 = 2 ;
else if ( V_633 == 266667 )
V_676 = 1 ;
else
V_676 = 0 ;
F_3 ( & V_6 -> V_548 . V_549 ) ;
V_15 = F_477 ( V_6 , V_677 ) ;
V_15 &= ~ V_678 ;
V_15 |= ( V_676 << V_679 ) ;
F_478 ( V_6 , V_677 , V_15 ) ;
if ( F_61 ( ( F_477 ( V_6 , V_677 ) &
V_680 ) == ( V_676 << V_681 ) ,
50 ) ) {
F_125 ( L_100 ) ;
}
F_5 ( & V_6 -> V_548 . V_549 ) ;
F_3 ( & V_6 -> V_9 ) ;
if ( V_633 == 400000 ) {
T_1 V_16 ;
V_16 = F_8 ( V_6 -> V_7 << 1 , V_633 ) - 1 ;
V_15 = F_4 ( V_6 , V_682 ) ;
V_15 &= ~ V_17 ;
V_15 |= V_16 ;
F_479 ( V_6 , V_682 , V_15 ) ;
if ( F_61 ( ( F_4 ( V_6 , V_682 ) &
V_18 ) == ( V_16 << V_19 ) ,
50 ) )
F_125 ( L_100 ) ;
}
V_15 = F_480 ( V_6 , V_683 ) ;
V_15 &= ~ 0x7f ;
if ( V_633 == 400000 )
V_15 |= 4500 / 250 ;
else
V_15 |= 3000 / 250 ;
F_481 ( V_6 , V_683 , V_15 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_447 ( V_57 ) ;
}
static void F_482 ( struct V_56 * V_57 , int V_633 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_15 , V_676 ;
F_28 ( V_6 -> V_431 . V_629 ( V_57 )
!= V_6 -> V_627 ) ;
switch ( V_633 ) {
case 333333 :
case 320000 :
case 266667 :
case 200000 :
break;
default:
F_169 ( V_633 ) ;
return;
}
V_676 = F_8 ( V_6 -> V_7 << 1 , V_633 ) - 1 ;
F_3 ( & V_6 -> V_548 . V_549 ) ;
V_15 = F_477 ( V_6 , V_677 ) ;
V_15 &= ~ V_684 ;
V_15 |= ( V_676 << V_685 ) ;
F_478 ( V_6 , V_677 , V_15 ) ;
if ( F_61 ( ( F_477 ( V_6 , V_677 ) &
V_686 ) == ( V_676 << V_687 ) ,
50 ) ) {
F_125 ( L_100 ) ;
}
F_5 ( & V_6 -> V_548 . V_549 ) ;
F_447 ( V_57 ) ;
}
static int F_483 ( struct V_5 * V_6 ,
int V_652 )
{
int V_688 = ( V_6 -> V_7 << 1 ) % 320000 != 0 ? 333333 : 320000 ;
int V_59 = F_17 ( V_6 ) ? 95 : 90 ;
if ( ! F_17 ( V_6 ) &&
V_652 > V_688 * V_59 / 100 )
return 400000 ;
else if ( V_652 > 266667 * V_59 / 100 )
return V_688 ;
else if ( V_652 > 0 )
return 266667 ;
else
return 200000 ;
}
static int F_456 ( int V_652 )
{
if ( V_652 > 576000 )
return 624000 ;
else if ( V_652 > 384000 )
return 576000 ;
else if ( V_652 > 288000 )
return 384000 ;
else if ( V_652 > 144000 )
return 288000 ;
else
return 144000 ;
}
static int F_484 ( struct V_56 * V_57 ,
struct V_420 * V_43 )
{
struct V_689 * V_329 = F_270 ( V_43 ) ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_87 * V_65 ;
struct V_42 * V_62 ;
unsigned V_652 = 0 , V_142 ;
enum V_95 V_95 ;
memcpy ( V_329 -> V_690 , V_6 -> V_690 ,
sizeof( V_329 -> V_690 ) ) ;
F_269 (state, crtc, crtc_state, i) {
int V_691 = 0 ;
if ( V_62 -> V_502 )
V_691 = V_62 -> V_92 . V_93 ;
V_329 -> V_690 [ V_142 ] = V_691 ;
}
F_89 (dev_priv, pipe)
V_652 = V_61 ( V_329 -> V_690 [ V_95 ] , V_652 ) ;
return V_652 ;
}
static int F_485 ( struct V_420 * V_43 )
{
struct V_56 * V_57 = V_43 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_652 = F_484 ( V_57 , V_43 ) ;
struct V_689 * V_329 =
F_270 ( V_43 ) ;
V_329 -> V_633 = V_329 -> V_692 =
F_483 ( V_6 , V_652 ) ;
if ( ! V_329 -> V_693 )
V_329 -> V_692 = F_483 ( V_6 , 0 ) ;
return 0 ;
}
static int F_486 ( struct V_420 * V_43 )
{
int V_652 = F_487 ( V_43 ) ;
struct V_689 * V_329 =
F_270 ( V_43 ) ;
V_329 -> V_633 = V_329 -> V_692 =
F_456 ( V_652 ) ;
if ( ! V_329 -> V_693 )
V_329 -> V_692 = F_456 ( 0 ) ;
return 0 ;
}
static void F_488 ( struct V_5 * V_6 )
{
unsigned int V_694 , V_695 ;
if ( F_17 ( V_6 ) )
V_695 = F_489 ( 12 ) ;
else
V_695 = F_489 ( 8 ) ;
if ( V_6 -> V_627 >= V_6 -> V_35 ) {
if ( F_17 ( V_6 ) )
V_694 = V_696 ;
else
V_694 = F_489 ( 15 ) ;
} else {
V_694 = V_695 ;
}
F_122 ( V_697 , V_698 |
V_695 ) ;
F_122 ( V_697 , V_698 |
V_694 | V_699 ) ;
F_28 ( F_11 ( V_697 ) & V_699 ) ;
}
static void F_490 ( struct V_420 * V_559 )
{
struct V_56 * V_57 = V_559 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_689 * V_700 =
F_270 ( V_559 ) ;
unsigned V_701 = V_700 -> V_692 ;
F_438 ( V_6 , V_702 ) ;
if ( F_17 ( V_57 ) )
F_482 ( V_57 , V_701 ) ;
else
F_476 ( V_57 , V_701 ) ;
F_488 ( V_6 ) ;
F_84 ( V_6 , V_702 ) ;
}
static void F_491 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_506 * V_507 ;
struct V_37 * V_38 =
F_265 ( V_65 -> V_43 ) ;
int V_95 = V_81 -> V_95 ;
if ( F_28 ( V_81 -> V_88 ) )
return;
if ( F_361 ( V_81 -> V_91 ) )
F_398 ( V_81 , V_571 ) ;
F_399 ( V_81 ) ;
F_400 ( V_81 ) ;
if ( F_17 ( V_57 ) && V_95 == V_126 ) {
struct V_5 * V_6 = F_53 ( V_57 ) ;
F_122 ( F_492 ( V_95 ) , V_703 ) ;
F_122 ( F_493 ( V_95 ) , 0 ) ;
}
F_494 ( V_81 ) ;
V_81 -> V_88 = true ;
F_379 ( V_6 , V_95 , true ) ;
F_352 (dev, crtc, encoder)
if ( V_507 -> V_575 )
V_507 -> V_575 ( V_507 ) ;
if ( F_17 ( V_57 ) ) {
F_495 ( V_81 , V_81 -> V_91 ) ;
F_134 ( V_81 , V_81 -> V_91 ) ;
} else {
F_496 ( V_81 , V_81 -> V_91 ) ;
F_126 ( V_81 , V_81 -> V_91 ) ;
}
F_352 (dev, crtc, encoder)
if ( V_507 -> V_573 )
V_507 -> V_573 ( V_507 ) ;
F_424 ( V_81 ) ;
F_403 ( & V_38 -> V_64 ) ;
F_387 ( V_65 ) ;
F_156 ( V_81 ) ;
F_97 ( V_65 ) ;
F_404 ( V_65 ) ;
F_352 (dev, crtc, encoder)
V_507 -> V_502 ( V_507 ) ;
}
static void F_497 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
F_122 ( F_498 ( V_65 -> V_95 ) , V_65 -> V_91 -> V_179 . V_704 ) ;
F_122 ( F_499 ( V_65 -> V_95 ) , V_65 -> V_91 -> V_179 . V_705 ) ;
}
static void F_500 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_506 * V_507 ;
struct V_37 * V_38 =
F_265 ( V_65 -> V_43 ) ;
enum V_95 V_95 = V_81 -> V_95 ;
if ( F_28 ( V_81 -> V_88 ) )
return;
F_497 ( V_81 ) ;
if ( F_361 ( V_81 -> V_91 ) )
F_398 ( V_81 , V_571 ) ;
F_399 ( V_81 ) ;
F_400 ( V_81 ) ;
F_494 ( V_81 ) ;
V_81 -> V_88 = true ;
if ( ! F_55 ( V_57 ) )
F_379 ( V_6 , V_95 , true ) ;
F_352 (dev, crtc, encoder)
if ( V_507 -> V_573 )
V_507 -> V_573 ( V_507 ) ;
F_137 ( V_81 ) ;
F_424 ( V_81 ) ;
F_403 ( & V_38 -> V_64 ) ;
F_387 ( V_65 ) ;
F_156 ( V_81 ) ;
F_97 ( V_65 ) ;
F_404 ( V_65 ) ;
F_352 (dev, crtc, encoder)
V_507 -> V_502 ( V_507 ) ;
}
static void F_501 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( ! V_65 -> V_91 -> V_584 . V_585 )
return;
F_127 ( V_6 , V_65 -> V_95 ) ;
F_20 ( L_101 ,
F_11 ( V_586 ) ) ;
F_122 ( V_586 , 0 ) ;
}
static void F_502 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_506 * V_507 ;
int V_95 = V_81 -> V_95 ;
if ( F_55 ( V_57 ) )
F_315 ( V_57 , V_95 ) ;
F_352 (dev, crtc, encoder)
V_507 -> V_581 ( V_507 ) ;
F_419 ( V_65 ) ;
F_97 ( V_65 ) ;
F_165 ( V_81 ) ;
F_501 ( V_81 ) ;
F_352 (dev, crtc, encoder)
if ( V_507 -> V_582 )
V_507 -> V_582 ( V_507 ) ;
if ( ! F_38 ( V_81 -> V_91 , V_228 ) ) {
if ( F_17 ( V_57 ) )
F_142 ( V_6 , V_95 ) ;
else if ( F_16 ( V_57 ) )
F_141 ( V_6 , V_95 ) ;
else
F_140 ( V_81 ) ;
}
F_352 (dev, crtc, encoder)
if ( V_507 -> V_706 )
V_507 -> V_706 ( V_507 ) ;
if ( ! F_55 ( V_57 ) )
F_379 ( V_6 , V_95 , false ) ;
}
static void F_503 ( struct V_87 * V_65 )
{
struct V_506 * V_507 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_5 * V_6 = F_53 ( V_65 -> V_57 ) ;
enum V_134 V_612 ;
unsigned long V_613 ;
if ( ! V_81 -> V_88 )
return;
if ( F_214 ( V_65 -> V_89 -> V_43 ) -> V_331 ) {
F_28 ( V_81 -> V_437 ) ;
F_219 ( V_65 ) ;
F_392 ( V_65 , 1 << F_218 ( V_65 -> V_89 ) ) ;
F_214 ( V_65 -> V_89 -> V_43 ) -> V_331 = false ;
}
V_6 -> V_431 . V_707 ( V_65 ) ;
F_157 ( L_102 ,
V_65 -> V_64 . V_372 , V_65 -> V_12 ) ;
F_28 ( F_504 ( V_65 -> V_43 , NULL ) < 0 ) ;
V_65 -> V_43 -> V_88 = false ;
V_81 -> V_88 = false ;
V_65 -> V_151 = false ;
V_65 -> V_43 -> V_708 = 0 ;
V_65 -> V_43 -> V_709 = 0 ;
F_352 (crtc->dev, crtc, encoder)
V_507 -> V_64 . V_65 = NULL ;
F_505 ( V_81 ) ;
F_387 ( V_65 ) ;
F_506 ( V_81 ) ;
V_613 = V_81 -> V_616 ;
F_437 (domain, domains)
F_84 ( V_6 , V_612 ) ;
V_81 -> V_616 = 0 ;
V_6 -> V_693 &= ~ ( 1 << V_81 -> V_95 ) ;
V_6 -> V_690 [ V_81 -> V_95 ] = 0 ;
}
int F_507 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_420 * V_43 ;
int V_267 ;
V_43 = F_508 ( V_57 ) ;
V_267 = F_509 ( V_43 ) ;
if ( V_267 )
F_125 ( L_52 , V_267 ) ;
else
V_6 -> V_428 = V_43 ;
return V_267 ;
}
void F_510 ( struct V_608 * V_507 )
{
struct V_506 * V_506 = F_435 ( V_507 ) ;
F_511 ( V_507 ) ;
F_215 ( V_506 ) ;
}
static void F_512 ( struct V_710 * V_711 )
{
struct V_87 * V_65 = V_711 -> V_64 . V_43 -> V_65 ;
F_157 ( L_103 ,
V_711 -> V_64 . V_64 . V_372 ,
V_711 -> V_64 . V_12 ) ;
if ( V_711 -> V_712 ( V_711 ) ) {
struct V_506 * V_507 = V_711 -> V_507 ;
struct V_713 * V_714 = V_711 -> V_64 . V_43 ;
F_64 ( ! V_65 ,
L_104 ) ;
if ( ! V_65 )
return;
F_64 ( ! V_65 -> V_43 -> V_88 ,
L_105 ) ;
if ( ! V_507 || V_507 -> type == V_604 )
return;
F_64 ( V_714 -> V_715 != & V_507 -> V_64 ,
L_106 ) ;
F_64 ( V_714 -> V_65 != V_507 -> V_64 . V_65 ,
L_107 ) ;
} else {
F_64 ( V_65 && V_65 -> V_43 -> V_88 ,
L_108 ) ;
F_64 ( ! V_65 && V_711 -> V_64 . V_43 -> V_715 ,
L_109 ) ;
}
}
int F_513 ( struct V_710 * V_711 )
{
F_514 ( & V_711 -> V_64 ) ;
if ( ! V_711 -> V_64 . V_43 )
return - V_716 ;
return 0 ;
}
struct V_710 * F_515 ( void )
{
struct V_710 * V_711 ;
V_711 = F_516 ( sizeof *V_711 , V_717 ) ;
if ( ! V_711 )
return NULL ;
if ( F_513 ( V_711 ) < 0 ) {
F_215 ( V_711 ) ;
return NULL ;
}
return V_711 ;
}
bool F_517 ( struct V_710 * V_711 )
{
enum V_95 V_95 = 0 ;
struct V_506 * V_507 = V_711 -> V_507 ;
return V_507 -> V_712 ( V_507 , & V_95 ) ;
}
static int F_518 ( struct V_37 * V_62 )
{
if ( V_62 -> V_64 . V_502 && V_62 -> V_229 )
return V_62 -> V_453 ;
return 0 ;
}
static int F_519 ( struct V_56 * V_57 , enum V_95 V_95 ,
struct V_37 * V_38 )
{
struct V_420 * V_43 = V_38 -> V_64 . V_43 ;
struct V_81 * V_718 ;
struct V_37 * V_719 ;
F_157 ( L_110 ,
F_76 ( V_95 ) , V_38 -> V_453 ) ;
if ( V_38 -> V_453 > 4 ) {
F_157 ( L_111 ,
F_76 ( V_95 ) , V_38 -> V_453 ) ;
return - V_537 ;
}
if ( F_234 ( V_57 ) || F_235 ( V_57 ) ) {
if ( V_38 -> V_453 > 2 ) {
F_157 ( L_112 ,
V_38 -> V_453 ) ;
return - V_537 ;
} else {
return 0 ;
}
}
if ( F_58 ( V_57 ) -> V_720 == 2 )
return 0 ;
switch ( V_95 ) {
case V_117 :
return 0 ;
case V_126 :
if ( V_38 -> V_453 <= 2 )
return 0 ;
V_718 = F_47 ( F_520 ( V_57 , V_505 ) ) ;
V_719 =
F_521 ( V_43 , V_718 ) ;
if ( F_278 ( V_719 ) )
return F_279 ( V_719 ) ;
if ( F_518 ( V_719 ) > 0 ) {
F_157 ( L_113 ,
F_76 ( V_95 ) , V_38 -> V_453 ) ;
return - V_537 ;
}
return 0 ;
case V_505 :
if ( V_38 -> V_453 > 2 ) {
F_157 ( L_114 ,
F_76 ( V_95 ) , V_38 -> V_453 ) ;
return - V_537 ;
}
V_718 = F_47 ( F_520 ( V_57 , V_126 ) ) ;
V_719 =
F_521 ( V_43 , V_718 ) ;
if ( F_278 ( V_719 ) )
return F_279 ( V_719 ) ;
if ( F_518 ( V_719 ) > 2 ) {
F_157 ( L_115 ) ;
return - V_537 ;
}
return 0 ;
default:
F_144 () ;
}
}
static int F_522 ( struct V_81 * V_81 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
const struct V_515 * V_92 = & V_38 -> V_64 . V_92 ;
int V_721 , V_722 , V_723 , V_267 ;
bool V_724 = false ;
V_458:
V_722 = F_22 ( F_53 ( V_57 ) , V_38 ) ;
V_723 = V_92 -> V_93 ;
V_721 = F_523 ( V_723 , V_722 ,
V_38 -> V_725 ) ;
V_38 -> V_453 = V_721 ;
F_524 ( V_38 -> V_725 , V_721 , V_723 ,
V_722 , & V_38 -> V_572 ) ;
V_267 = F_519 ( V_57 , V_81 -> V_95 , V_38 ) ;
if ( V_267 == - V_537 && V_38 -> V_725 > 6 * 3 ) {
V_38 -> V_725 -= 2 * 3 ;
F_157 ( L_116 ,
V_38 -> V_725 ) ;
V_724 = true ;
V_38 -> V_726 = true ;
goto V_458;
}
if ( V_724 )
return V_727 ;
return V_267 ;
}
static bool F_525 ( struct V_5 * V_6 ,
struct V_37 * V_38 )
{
if ( V_38 -> V_725 > 24 )
return false ;
if ( F_234 ( V_6 ) )
return true ;
return F_526 ( V_38 ) <=
V_6 -> V_617 * 95 / 100 ;
}
static void F_527 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
V_38 -> V_547 = V_728 . V_729 &&
F_405 ( V_65 ) &&
F_525 ( V_6 , V_38 ) ;
}
static bool F_528 ( const struct V_81 * V_65 )
{
const struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
return F_58 ( V_6 ) -> V_103 < 4 &&
( V_65 -> V_95 == V_117 || F_529 ( V_6 ) ) ;
}
static int F_530 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
const struct V_515 * V_92 = & V_38 -> V_64 . V_92 ;
int V_730 = V_6 -> V_628 ;
if ( F_58 ( V_57 ) -> V_103 < 4 ) {
V_730 = V_6 -> V_617 * 9 / 10 ;
if ( F_528 ( V_65 ) &&
V_92 -> V_93 > V_730 ) {
V_730 = V_6 -> V_628 ;
V_38 -> V_232 = true ;
}
}
if ( V_92 -> V_93 > V_730 ) {
F_157 ( L_117 ,
V_92 -> V_93 , V_730 ,
F_531 ( V_38 -> V_232 ) ) ;
return - V_537 ;
}
if ( ( F_38 ( V_38 , V_66 ) &&
F_39 ( V_57 ) ) || V_38 -> V_232 )
V_38 -> V_356 &= ~ 1 ;
if ( ( F_58 ( V_57 ) -> V_103 > 4 || F_18 ( V_57 ) ) &&
V_92 -> V_731 == V_92 -> V_539 )
return - V_537 ;
if ( F_406 ( V_57 ) )
F_527 ( V_65 , V_38 ) ;
if ( V_38 -> V_229 )
return F_522 ( V_65 , V_38 ) ;
return 0 ;
}
static int F_532 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_648 ;
F_458 ( V_6 ) ;
if ( V_6 -> V_630 . V_52 == 0 )
return V_6 -> V_630 . V_631 ;
V_648 = F_11 ( V_647 ) ;
if ( V_6 -> V_630 . V_52 == 8640000 ) {
switch ( V_648 & V_675 ) {
case V_672 :
return 432000 ;
case V_666 :
return 308571 ;
case V_673 :
return 540000 ;
case V_674 :
return 617143 ;
default:
F_169 ( V_648 & V_675 ) ;
}
} else {
switch ( V_648 & V_675 ) {
case V_672 :
return 450000 ;
case V_666 :
return 337500 ;
case V_673 :
return 540000 ;
case V_674 :
return 675000 ;
default:
F_169 ( V_648 & V_675 ) ;
}
}
return V_6 -> V_630 . V_631 ;
}
static void F_533 ( struct V_5 * V_6 )
{
T_1 V_15 ;
V_6 -> V_630 . V_631 = 19200 ;
V_6 -> V_630 . V_52 = 0 ;
V_15 = F_11 ( V_635 ) ;
if ( ( V_15 & V_639 ) == 0 )
return;
if ( F_28 ( ( V_15 & V_636 ) == 0 ) )
return;
V_15 = F_11 ( V_637 ) ;
V_6 -> V_630 . V_52 = ( V_15 & V_638 ) *
V_6 -> V_630 . V_631 ;
}
static int F_534 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_16 ;
int div , V_52 ;
F_533 ( V_6 ) ;
V_52 = V_6 -> V_630 . V_52 ;
if ( V_52 == 0 )
return V_6 -> V_630 . V_631 ;
V_16 = F_11 ( V_647 ) & V_651 ;
switch ( V_16 ) {
case V_643 :
div = 2 ;
break;
case V_642 :
div = 3 ;
break;
case V_641 :
div = 4 ;
break;
case V_640 :
div = 8 ;
break;
default:
F_169 ( V_16 ) ;
return V_6 -> V_630 . V_631 ;
}
return F_8 ( V_52 , div ) ;
}
static int F_535 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_732 = F_11 ( V_733 ) ;
T_2 V_734 = V_732 & V_735 ;
if ( V_732 & V_736 )
return 800000 ;
else if ( F_11 ( V_625 ) & V_626 )
return 450000 ;
else if ( V_734 == V_737 )
return 450000 ;
else if ( V_734 == V_738 )
return 540000 ;
else if ( V_734 == V_739 )
return 337500 ;
else
return 675000 ;
}
static int F_536 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_732 = F_11 ( V_733 ) ;
T_2 V_734 = V_732 & V_735 ;
if ( V_732 & V_736 )
return 800000 ;
else if ( F_11 ( V_625 ) & V_626 )
return 450000 ;
else if ( V_734 == V_737 )
return 450000 ;
else if ( F_537 ( V_57 ) )
return 337500 ;
else
return 540000 ;
}
static int F_538 ( struct V_56 * V_57 )
{
return F_9 ( F_53 ( V_57 ) , L_118 ,
V_682 ) ;
}
static int F_539 ( struct V_56 * V_57 )
{
return 450000 ;
}
static int F_540 ( struct V_56 * V_57 )
{
return 400000 ;
}
static int F_541 ( struct V_56 * V_57 )
{
return 333333 ;
}
static int F_542 ( struct V_56 * V_57 )
{
return 200000 ;
}
static int F_543 ( struct V_56 * V_57 )
{
T_5 V_740 = 0 ;
F_544 ( V_57 -> V_741 , V_742 , & V_740 ) ;
switch ( V_740 & V_743 ) {
case V_744 :
return 266667 ;
case V_745 :
return 333333 ;
case V_746 :
return 444444 ;
case V_747 :
return 200000 ;
default:
F_125 ( L_119 , V_740 ) ;
case V_748 :
return 133333 ;
case V_749 :
return 166667 ;
}
}
static int F_545 ( struct V_56 * V_57 )
{
T_5 V_740 = 0 ;
F_544 ( V_57 -> V_741 , V_742 , & V_740 ) ;
if ( V_740 & V_750 )
return 133333 ;
else {
switch ( V_740 & V_743 ) {
case V_751 :
return 333333 ;
default:
case V_752 :
return 190000 ;
}
}
}
static int F_546 ( struct V_56 * V_57 )
{
return 266667 ;
}
static int F_547 ( struct V_56 * V_57 )
{
T_5 V_753 = 0 ;
if ( V_57 -> V_741 -> V_754 == 0x1 )
return 133333 ;
F_548 ( V_57 -> V_741 -> V_755 ,
F_549 ( 0 , 3 ) , V_756 , & V_753 ) ;
switch ( V_753 & V_757 ) {
case V_758 :
case V_759 :
case V_760 :
return 200000 ;
case V_761 :
return 250000 ;
case V_762 :
return 133333 ;
case V_763 :
case V_764 :
case V_765 :
return 266667 ;
}
return 0 ;
}
static int F_550 ( struct V_56 * V_57 )
{
return 133333 ;
}
static unsigned int F_551 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
static const unsigned int V_766 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 6400000 ,
} ;
static const unsigned int V_767 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 2666667 ,
} ;
static const unsigned int V_768 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 3333333 ,
[ 5 ] = 3566667 ,
[ 6 ] = 4266667 ,
} ;
static const unsigned int V_769 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
} ;
static const unsigned int V_770 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 2666667 ,
[ 5 ] = 4266667 ,
} ;
const unsigned int * V_771 ;
unsigned int V_52 ;
T_6 V_184 = 0 ;
if ( F_552 ( V_57 ) )
V_771 = V_770 ;
else if ( F_18 ( V_57 ) )
V_771 = V_769 ;
else if ( F_184 ( V_57 ) )
V_771 = V_768 ;
else if ( F_19 ( V_57 ) )
V_771 = V_767 ;
else if ( F_553 ( V_57 ) )
V_771 = V_766 ;
else
return 0 ;
V_184 = F_11 ( F_138 ( V_57 ) ? V_772 : V_773 ) ;
V_52 = V_771 [ V_184 & 0x7 ] ;
if ( V_52 == 0 )
F_125 ( L_120 , V_184 ) ;
else
F_157 ( L_121 , V_52 ) ;
return V_52 ;
}
static int F_554 ( struct V_56 * V_57 )
{
unsigned int V_774 , V_52 = F_551 ( V_57 ) ;
T_7 V_184 = 0 ;
F_544 ( V_57 -> V_741 , V_742 , & V_184 ) ;
V_774 = ( V_184 >> 12 ) & 0x1 ;
switch ( V_52 ) {
case 2666667 :
case 4000000 :
case 5333333 :
return V_774 ? 333333 : 222222 ;
case 3200000 :
return V_774 ? 320000 : 228571 ;
default:
F_125 ( L_122 , V_52 , V_184 ) ;
return 222222 ;
}
}
static int F_555 ( struct V_56 * V_57 )
{
static const T_6 V_775 [] = { 16 , 10 , 8 } ;
static const T_6 V_776 [] = { 20 , 12 , 10 } ;
static const T_6 V_777 [] = { 24 , 16 , 14 } ;
const T_6 * V_778 ;
unsigned int V_774 , V_52 = F_551 ( V_57 ) ;
T_7 V_184 = 0 ;
F_544 ( V_57 -> V_741 , V_742 , & V_184 ) ;
V_774 = ( ( V_184 >> 8 ) & 0x1f ) - 1 ;
if ( V_774 >= F_176 ( V_775 ) )
goto V_779;
switch ( V_52 ) {
case 3200000 :
V_778 = V_775 ;
break;
case 4000000 :
V_778 = V_776 ;
break;
case 5333333 :
V_778 = V_777 ;
break;
default:
goto V_779;
}
return F_8 ( V_52 , V_778 [ V_774 ] ) ;
V_779:
F_125 ( L_123 , V_52 , V_184 ) ;
return 200000 ;
}
static int F_556 ( struct V_56 * V_57 )
{
static const T_6 V_775 [] = { 12 , 10 , 8 , 7 , 5 , 16 } ;
static const T_6 V_776 [] = { 14 , 12 , 10 , 8 , 6 , 20 } ;
static const T_6 V_780 [] = { 20 , 14 , 12 , 10 , 8 , 24 } ;
static const T_6 V_777 [] = { 20 , 16 , 12 , 12 , 8 , 28 } ;
const T_6 * V_778 ;
unsigned int V_774 , V_52 = F_551 ( V_57 ) ;
T_7 V_184 = 0 ;
F_544 ( V_57 -> V_741 , V_742 , & V_184 ) ;
V_774 = ( V_184 >> 4 ) & 0x7 ;
if ( V_774 >= F_176 ( V_775 ) )
goto V_779;
switch ( V_52 ) {
case 3200000 :
V_778 = V_775 ;
break;
case 4000000 :
V_778 = V_776 ;
break;
case 4800000 :
V_778 = V_780 ;
break;
case 5333333 :
V_778 = V_777 ;
break;
default:
goto V_779;
}
return F_8 ( V_52 , V_778 [ V_774 ] ) ;
V_779:
F_125 ( L_124 , V_52 , V_184 ) ;
return 190476 ;
}
static void
F_557 ( T_2 * V_781 , T_2 * V_782 )
{
while ( * V_781 > V_783 ||
* V_782 > V_783 ) {
* V_781 >>= 1 ;
* V_782 >>= 1 ;
}
}
static void F_558 ( unsigned int V_46 , unsigned int V_51 ,
T_2 * V_784 , T_2 * V_785 )
{
* V_785 = F_559 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_784 = F_45 ( ( V_55 ) V_46 * * V_785 , V_51 ) ;
F_557 ( V_784 , V_785 ) ;
}
void
F_524 ( int V_786 , int V_787 ,
int V_788 , int V_789 ,
struct V_790 * V_791 )
{
V_791 -> V_792 = 64 ;
F_558 ( V_786 * V_788 ,
V_789 * V_787 * 8 ,
& V_791 -> V_793 , & V_791 -> V_794 ) ;
F_558 ( V_788 , V_789 ,
& V_791 -> V_795 , & V_791 -> V_796 ) ;
}
static inline bool F_560 ( struct V_5 * V_6 )
{
if ( V_728 . V_797 >= 0 )
return V_728 . V_797 != 0 ;
return V_6 -> V_798 . V_799
&& ! ( V_6 -> V_136 & V_800 ) ;
}
static T_2 F_561 ( struct V_45 * V_45 )
{
return ( 1 << V_45 -> V_51 ) << 16 | V_45 -> V_47 ;
}
static T_2 F_562 ( struct V_45 * V_45 )
{
return V_45 -> V_51 << 16 | V_45 -> V_54 << 8 | V_45 -> V_47 ;
}
static void F_563 ( struct V_81 * V_65 ,
struct V_37 * V_62 ,
struct V_45 * V_801 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
T_1 V_802 , V_803 = 0 ;
if ( F_19 ( V_57 ) ) {
V_802 = F_561 ( & V_62 -> V_45 ) ;
if ( V_801 )
V_803 = F_561 ( V_801 ) ;
} else {
V_802 = F_562 ( & V_62 -> V_45 ) ;
if ( V_801 )
V_803 = F_562 ( V_801 ) ;
}
V_62 -> V_179 . V_704 = V_802 ;
V_65 -> V_804 = false ;
if ( F_38 ( V_62 , V_66 ) &&
V_801 ) {
V_62 -> V_179 . V_705 = V_803 ;
V_65 -> V_804 = true ;
} else {
V_62 -> V_179 . V_705 = V_802 ;
}
}
static void F_564 ( struct V_5 * V_6 , enum V_95
V_95 )
{
T_1 V_805 ;
V_805 = F_131 ( V_6 , V_95 , F_565 ( 1 ) ) ;
V_805 &= 0xffffff00 ;
V_805 |= 0x00000030 ;
F_133 ( V_6 , V_95 , F_565 ( 1 ) , V_805 ) ;
V_805 = F_131 ( V_6 , V_95 , V_806 ) ;
V_805 &= 0x8cffffff ;
V_805 = 0x8c000000 ;
F_133 ( V_6 , V_95 , V_806 , V_805 ) ;
V_805 = F_131 ( V_6 , V_95 , F_565 ( 1 ) ) ;
V_805 &= 0xffffff00 ;
F_133 ( V_6 , V_95 , F_565 ( 1 ) , V_805 ) ;
V_805 = F_131 ( V_6 , V_95 , V_806 ) ;
V_805 &= 0x00ffffff ;
V_805 |= 0xb0000000 ;
F_133 ( V_6 , V_95 , V_806 , V_805 ) ;
}
static void F_566 ( struct V_81 * V_65 ,
struct V_790 * V_791 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_65 -> V_95 ;
F_122 ( F_567 ( V_95 ) , F_568 ( V_791 -> V_792 ) | V_791 -> V_793 ) ;
F_122 ( F_569 ( V_95 ) , V_791 -> V_794 ) ;
F_122 ( F_570 ( V_95 ) , V_791 -> V_795 ) ;
F_122 ( F_571 ( V_95 ) , V_791 -> V_796 ) ;
}
static void F_401 ( struct V_81 * V_65 ,
struct V_790 * V_791 ,
struct V_790 * V_807 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_65 -> V_95 ;
enum V_94 V_94 = V_65 -> V_91 -> V_97 ;
if ( F_58 ( V_57 ) -> V_103 >= 5 ) {
F_122 ( F_356 ( V_94 ) , F_568 ( V_791 -> V_792 ) | V_791 -> V_793 ) ;
F_122 ( F_572 ( V_94 ) , V_791 -> V_794 ) ;
F_122 ( F_573 ( V_94 ) , V_791 -> V_795 ) ;
F_122 ( F_574 ( V_94 ) , V_791 -> V_796 ) ;
if ( V_807 && ( F_17 ( V_57 ) || F_58 ( V_57 ) -> V_103 < 8 ) &&
V_65 -> V_91 -> V_808 ) {
F_122 ( F_575 ( V_94 ) ,
F_568 ( V_807 -> V_792 ) | V_807 -> V_793 ) ;
F_122 ( F_576 ( V_94 ) , V_807 -> V_794 ) ;
F_122 ( F_577 ( V_94 ) , V_807 -> V_795 ) ;
F_122 ( F_578 ( V_94 ) , V_807 -> V_796 ) ;
}
} else {
F_122 ( F_579 ( V_95 ) , F_568 ( V_791 -> V_792 ) | V_791 -> V_793 ) ;
F_122 ( F_580 ( V_95 ) , V_791 -> V_794 ) ;
F_122 ( F_581 ( V_95 ) , V_791 -> V_795 ) ;
F_122 ( F_582 ( V_95 ) , V_791 -> V_796 ) ;
}
}
void F_398 ( struct V_81 * V_65 , enum V_809 V_791 )
{
struct V_790 * V_810 , * V_811 = NULL ;
if ( V_791 == V_571 ) {
V_810 = & V_65 -> V_91 -> V_810 ;
V_811 = & V_65 -> V_91 -> V_811 ;
} else if ( V_791 == V_812 ) {
V_810 = & V_65 -> V_91 -> V_811 ;
} else {
F_125 ( L_125 ) ;
return;
}
if ( V_65 -> V_91 -> V_229 )
F_566 ( V_65 , & V_65 -> V_91 -> V_810 ) ;
else
F_401 ( V_65 , V_810 , V_811 ) ;
}
static void F_583 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
V_38 -> V_179 . V_45 = V_194 |
V_195 | V_190 ;
if ( V_65 -> V_95 != V_117 )
V_38 -> V_179 . V_45 |= V_196 ;
if ( ! F_38 ( V_38 , V_228 ) )
V_38 -> V_179 . V_45 |= V_106 |
V_813 ;
V_38 -> V_179 . V_181 =
( V_38 -> V_577 - 1 ) << V_814 ;
}
static void F_584 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
V_38 -> V_179 . V_45 = V_197 |
V_195 | V_190 ;
if ( V_65 -> V_95 != V_117 )
V_38 -> V_179 . V_45 |= V_196 ;
if ( ! F_38 ( V_38 , V_228 ) )
V_38 -> V_179 . V_45 |= V_106 ;
V_38 -> V_179 . V_181 =
( V_38 -> V_577 - 1 ) << V_814 ;
}
static void F_496 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
T_1 V_815 ;
T_1 V_816 , V_817 , V_818 , V_819 , V_820 ;
T_1 V_821 , V_805 ;
F_122 ( F_63 ( V_95 ) ,
V_38 -> V_179 . V_45 &
~ ( V_106 | V_813 ) ) ;
if ( ( V_38 -> V_179 . V_45 & V_106 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_816 = V_38 -> V_45 . V_51 ;
V_817 = V_38 -> V_45 . V_54 ;
V_818 = V_38 -> V_45 . V_47 ;
V_819 = V_38 -> V_45 . V_49 ;
V_820 = V_38 -> V_45 . V_50 ;
if ( V_95 == V_126 )
F_564 ( V_6 , V_95 ) ;
F_133 ( V_6 , V_95 , V_822 , 0x0100000f ) ;
V_805 = F_131 ( V_6 , V_95 , F_585 ( V_95 ) ) ;
V_805 &= 0x00ffffff ;
F_133 ( V_6 , V_95 , F_585 ( V_95 ) , V_805 ) ;
F_133 ( V_6 , V_95 , V_823 , 0x610 ) ;
V_815 = ( ( V_817 << V_824 ) | ( V_818 & V_825 ) ) ;
V_815 |= ( ( V_819 << V_826 ) | ( V_820 << V_827 ) ) ;
V_815 |= ( ( V_816 << V_828 ) ) ;
V_815 |= ( 1 << V_829 ) ;
V_815 |= ( V_830 << V_831 ) ;
F_133 ( V_6 , V_95 , F_586 ( V_95 ) , V_815 ) ;
V_815 |= V_832 ;
F_133 ( V_6 , V_95 , F_586 ( V_95 ) , V_815 ) ;
if ( V_38 -> V_39 == 162000 ||
F_38 ( V_65 -> V_91 , V_605 ) ||
F_38 ( V_65 -> V_91 , V_214 ) )
F_133 ( V_6 , V_95 , F_587 ( V_95 ) ,
0x009f0003 ) ;
else
F_133 ( V_6 , V_95 , F_587 ( V_95 ) ,
0x00d0000f ) ;
if ( F_361 ( V_38 ) ) {
if ( V_95 == V_117 )
F_133 ( V_6 , V_95 , F_588 ( V_95 ) ,
0x0df40000 ) ;
else
F_133 ( V_6 , V_95 , F_588 ( V_95 ) ,
0x0df70000 ) ;
} else {
if ( V_95 == V_117 )
F_133 ( V_6 , V_95 , F_588 ( V_95 ) ,
0x0df70000 ) ;
else
F_133 ( V_6 , V_95 , F_588 ( V_95 ) ,
0x0df40000 ) ;
}
V_821 = F_131 ( V_6 , V_95 , F_589 ( V_95 ) ) ;
V_821 = ( V_821 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_361 ( V_65 -> V_91 ) )
V_821 |= 0x01000000 ;
F_133 ( V_6 , V_95 , F_589 ( V_95 ) , V_821 ) ;
F_133 ( V_6 , V_95 , F_590 ( V_95 ) , 0x87871000 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_495 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
enum V_182 V_183 = F_130 ( V_95 ) ;
T_1 V_833 , V_834 ;
T_1 V_816 , V_817 , V_818 , V_819 , V_820 , V_835 ;
T_1 V_836 ;
int V_52 ;
F_122 ( F_63 ( V_95 ) ,
V_38 -> V_179 . V_45 & ~ V_106 ) ;
if ( ( V_38 -> V_179 . V_45 & V_106 ) == 0 )
return;
V_816 = V_38 -> V_45 . V_51 ;
V_835 = V_38 -> V_45 . V_47 & 0x3fffff ;
V_817 = V_38 -> V_45 . V_54 ;
V_818 = V_38 -> V_45 . V_47 >> 22 ;
V_819 = V_38 -> V_45 . V_49 ;
V_820 = V_38 -> V_45 . V_50 ;
V_52 = V_38 -> V_45 . V_52 ;
V_836 = 0 ;
V_833 = 0 ;
F_3 ( & V_6 -> V_9 ) ;
F_133 ( V_6 , V_95 , F_591 ( V_183 ) ,
5 << V_837 |
V_819 << V_838 |
V_820 << V_839 |
1 << V_840 ) ;
F_133 ( V_6 , V_95 , F_592 ( V_183 ) , V_818 ) ;
F_133 ( V_6 , V_95 , F_593 ( V_183 ) ,
V_841 |
1 << V_842 ) ;
F_133 ( V_6 , V_95 , F_594 ( V_183 ) , V_835 ) ;
V_836 = F_131 ( V_6 , V_95 , F_595 ( V_183 ) ) ;
V_836 &= ~ ( V_843 | V_844 ) ;
V_836 |= ( 2 << V_845 ) ;
if ( V_835 )
V_836 |= V_844 ;
F_133 ( V_6 , V_95 , F_595 ( V_183 ) , V_836 ) ;
V_836 = F_131 ( V_6 , V_95 , F_596 ( V_183 ) ) ;
V_836 &= ~ ( V_846 |
V_847 ) ;
V_836 |= ( 0x5 << V_848 ) ;
if ( ! V_835 )
V_836 |= V_847 ;
F_133 ( V_6 , V_95 , F_596 ( V_183 ) , V_836 ) ;
if ( V_52 == 5400000 ) {
V_833 |= ( 0x3 << V_849 ) ;
V_833 |= ( 0x8 << V_850 ) ;
V_833 |= ( 0x1 << V_851 ) ;
V_834 = 0x9 ;
} else if ( V_52 <= 6200000 ) {
V_833 |= ( 0x5 << V_849 ) ;
V_833 |= ( 0xB << V_850 ) ;
V_833 |= ( 0x3 << V_851 ) ;
V_834 = 0x9 ;
} else if ( V_52 <= 6480000 ) {
V_833 |= ( 0x4 << V_849 ) ;
V_833 |= ( 0x9 << V_850 ) ;
V_833 |= ( 0x3 << V_851 ) ;
V_834 = 0x8 ;
} else {
V_833 |= ( 0x4 << V_849 ) ;
V_833 |= ( 0x9 << V_850 ) ;
V_833 |= ( 0x3 << V_851 ) ;
V_834 = 0 ;
}
F_133 ( V_6 , V_95 , F_597 ( V_183 ) , V_833 ) ;
V_836 = F_131 ( V_6 , V_95 , F_598 ( V_183 ) ) ;
V_836 &= ~ V_852 ;
V_836 |= ( V_834 << V_853 ) ;
F_133 ( V_6 , V_95 , F_598 ( V_183 ) , V_836 ) ;
F_133 ( V_6 , V_95 , F_132 ( V_183 ) ,
F_131 ( V_6 , V_95 , F_132 ( V_183 ) ) |
V_854 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
int F_599 ( struct V_56 * V_57 , enum V_95 V_95 ,
const struct V_45 * V_45 )
{
struct V_81 * V_65 =
F_47 ( F_520 ( V_57 , V_95 ) ) ;
struct V_37 * V_38 ;
V_38 = F_516 ( sizeof( * V_38 ) , V_717 ) ;
if ( ! V_38 )
return - V_716 ;
V_38 -> V_64 . V_65 = & V_65 -> V_64 ;
V_38 -> V_577 = 1 ;
V_38 -> V_45 = * V_45 ;
if ( F_17 ( V_57 ) ) {
F_584 ( V_65 , V_38 ) ;
F_495 ( V_65 , V_38 ) ;
F_134 ( V_65 , V_38 ) ;
} else {
F_583 ( V_65 , V_38 ) ;
F_496 ( V_65 , V_38 ) ;
F_126 ( V_65 , V_38 ) ;
}
F_215 ( V_38 ) ;
return 0 ;
}
void F_600 ( struct V_56 * V_57 , enum V_95 V_95 )
{
if ( F_17 ( V_57 ) )
F_142 ( F_53 ( V_57 ) , V_95 ) ;
else
F_141 ( F_53 ( V_57 ) , V_95 ) ;
}
static void F_601 ( struct V_81 * V_65 ,
struct V_37 * V_62 ,
struct V_45 * V_801 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_45 ;
struct V_45 * clock = & V_62 -> V_45 ;
F_563 ( V_65 , V_62 , V_801 ) ;
V_45 = V_190 ;
if ( F_38 ( V_62 , V_66 ) )
V_45 |= V_855 ;
else
V_45 |= V_856 ;
if ( F_602 ( V_57 ) || F_603 ( V_57 ) || F_553 ( V_57 ) ) {
V_45 |= ( V_62 -> V_577 - 1 )
<< V_857 ;
}
if ( F_38 ( V_62 , V_219 ) ||
F_38 ( V_62 , V_214 ) )
V_45 |= V_858 ;
if ( F_361 ( V_62 ) )
V_45 |= V_858 ;
if ( F_19 ( V_57 ) )
V_45 |= ( 1 << ( clock -> V_49 - 1 ) ) << V_859 ;
else {
V_45 |= ( 1 << ( clock -> V_49 - 1 ) ) << V_860 ;
if ( F_18 ( V_57 ) && V_801 )
V_45 |= ( 1 << ( V_801 -> V_49 - 1 ) ) << V_861 ;
}
switch ( clock -> V_50 ) {
case 5 :
V_45 |= V_862 ;
break;
case 7 :
V_45 |= V_863 ;
break;
case 10 :
V_45 |= V_864 ;
break;
case 14 :
V_45 |= V_865 ;
break;
}
if ( F_58 ( V_57 ) -> V_103 >= 4 )
V_45 |= ( 6 << V_866 ) ;
if ( V_62 -> V_867 )
V_45 |= V_868 ;
else if ( F_38 ( V_62 , V_66 ) &&
F_560 ( V_6 ) )
V_45 |= V_869 ;
else
V_45 |= V_870 ;
V_45 |= V_106 ;
V_62 -> V_179 . V_45 = V_45 ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
T_1 V_181 = ( V_62 -> V_577 - 1 )
<< V_814 ;
V_62 -> V_179 . V_181 = V_181 ;
}
}
static void F_604 ( struct V_81 * V_65 ,
struct V_37 * V_62 ,
struct V_45 * V_801 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_45 ;
struct V_45 * clock = & V_62 -> V_45 ;
F_563 ( V_65 , V_62 , V_801 ) ;
V_45 = V_190 ;
if ( F_38 ( V_62 , V_66 ) ) {
V_45 |= ( 1 << ( clock -> V_49 - 1 ) ) << V_860 ;
} else {
if ( clock -> V_49 == 2 )
V_45 |= V_871 ;
else
V_45 |= ( clock -> V_49 - 2 ) << V_860 ;
if ( clock -> V_50 == 4 )
V_45 |= V_872 ;
}
if ( ! F_139 ( V_57 ) && F_38 ( V_62 , V_192 ) )
V_45 |= V_193 ;
if ( F_38 ( V_62 , V_66 ) &&
F_560 ( V_6 ) )
V_45 |= V_869 ;
else
V_45 |= V_870 ;
V_45 |= V_106 ;
V_62 -> V_179 . V_45 = V_45 ;
}
static void F_399 ( struct V_81 * V_81 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_81 -> V_95 ;
enum V_94 V_97 = V_81 -> V_91 -> V_97 ;
const struct V_515 * V_92 = & V_81 -> V_91 -> V_64 . V_92 ;
T_2 V_873 , V_874 ;
int V_875 = 0 ;
V_873 = V_92 -> V_873 ;
V_874 = V_92 -> V_874 ;
if ( V_92 -> V_320 & V_876 ) {
V_873 -= 1 ;
V_874 -= 1 ;
if ( F_38 ( V_81 -> V_91 , V_219 ) )
V_875 = ( V_92 -> V_877 - 1 ) / 2 ;
else
V_875 = V_92 -> V_731 -
V_92 -> V_877 / 2 ;
if ( V_875 < 0 )
V_875 += V_92 -> V_877 ;
}
if ( F_58 ( V_57 ) -> V_103 > 3 )
F_122 ( F_348 ( V_97 ) , V_875 ) ;
F_122 ( F_336 ( V_97 ) ,
( V_92 -> V_539 - 1 ) |
( ( V_92 -> V_877 - 1 ) << 16 ) ) ;
F_122 ( F_338 ( V_97 ) ,
( V_92 -> V_878 - 1 ) |
( ( V_92 -> V_879 - 1 ) << 16 ) ) ;
F_122 ( F_340 ( V_97 ) ,
( V_92 -> V_731 - 1 ) |
( ( V_92 -> V_880 - 1 ) << 16 ) ) ;
F_122 ( F_342 ( V_97 ) ,
( V_92 -> V_540 - 1 ) |
( ( V_873 - 1 ) << 16 ) ) ;
F_122 ( F_344 ( V_97 ) ,
( V_92 -> V_881 - 1 ) |
( ( V_874 - 1 ) << 16 ) ) ;
F_122 ( F_346 ( V_97 ) ,
( V_92 -> V_882 - 1 ) |
( ( V_92 -> V_883 - 1 ) << 16 ) ) ;
if ( F_234 ( V_57 ) && V_97 == V_576 &&
( V_95 == V_126 || V_95 == V_505 ) )
F_122 ( F_342 ( V_95 ) , F_11 ( F_342 ( V_97 ) ) ) ;
}
static void F_400 ( struct V_81 * V_81 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_81 -> V_95 ;
F_122 ( F_294 ( V_95 ) ,
( ( V_81 -> V_91 -> V_356 - 1 ) << 16 ) |
( V_81 -> V_91 -> V_355 - 1 ) ) ;
}
static void F_605 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_94 V_97 = V_38 -> V_97 ;
T_2 V_184 ;
V_184 = F_11 ( F_336 ( V_97 ) ) ;
V_38 -> V_64 . V_92 . V_539 = ( V_184 & 0xffff ) + 1 ;
V_38 -> V_64 . V_92 . V_877 = ( ( V_184 >> 16 ) & 0xffff ) + 1 ;
V_184 = F_11 ( F_338 ( V_97 ) ) ;
V_38 -> V_64 . V_92 . V_878 = ( V_184 & 0xffff ) + 1 ;
V_38 -> V_64 . V_92 . V_879 = ( ( V_184 >> 16 ) & 0xffff ) + 1 ;
V_184 = F_11 ( F_340 ( V_97 ) ) ;
V_38 -> V_64 . V_92 . V_731 = ( V_184 & 0xffff ) + 1 ;
V_38 -> V_64 . V_92 . V_880 = ( ( V_184 >> 16 ) & 0xffff ) + 1 ;
V_184 = F_11 ( F_342 ( V_97 ) ) ;
V_38 -> V_64 . V_92 . V_540 = ( V_184 & 0xffff ) + 1 ;
V_38 -> V_64 . V_92 . V_873 = ( ( V_184 >> 16 ) & 0xffff ) + 1 ;
V_184 = F_11 ( F_344 ( V_97 ) ) ;
V_38 -> V_64 . V_92 . V_881 = ( V_184 & 0xffff ) + 1 ;
V_38 -> V_64 . V_92 . V_874 = ( ( V_184 >> 16 ) & 0xffff ) + 1 ;
V_184 = F_11 ( F_346 ( V_97 ) ) ;
V_38 -> V_64 . V_92 . V_882 = ( V_184 & 0xffff ) + 1 ;
V_38 -> V_64 . V_92 . V_883 = ( ( V_184 >> 16 ) & 0xffff ) + 1 ;
if ( F_11 ( F_59 ( V_97 ) ) & V_217 ) {
V_38 -> V_64 . V_92 . V_320 |= V_876 ;
V_38 -> V_64 . V_92 . V_873 += 1 ;
V_38 -> V_64 . V_92 . V_874 += 1 ;
}
}
static void F_606 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_184 ;
V_184 = F_11 ( F_294 ( V_65 -> V_95 ) ) ;
V_38 -> V_355 = ( V_184 & 0xffff ) + 1 ;
V_38 -> V_356 = ( ( V_184 >> 16 ) & 0xffff ) + 1 ;
V_38 -> V_64 . V_416 . V_884 = V_38 -> V_355 ;
V_38 -> V_64 . V_416 . V_885 = V_38 -> V_356 ;
}
void F_607 ( struct V_515 * V_416 ,
struct V_37 * V_38 )
{
V_416 -> V_885 = V_38 -> V_64 . V_92 . V_539 ;
V_416 -> V_886 = V_38 -> V_64 . V_92 . V_877 ;
V_416 -> V_887 = V_38 -> V_64 . V_92 . V_731 ;
V_416 -> V_888 = V_38 -> V_64 . V_92 . V_880 ;
V_416 -> V_884 = V_38 -> V_64 . V_92 . V_540 ;
V_416 -> V_889 = V_38 -> V_64 . V_92 . V_873 ;
V_416 -> V_890 = V_38 -> V_64 . V_92 . V_882 ;
V_416 -> V_891 = V_38 -> V_64 . V_92 . V_883 ;
V_416 -> V_320 = V_38 -> V_64 . V_92 . V_320 ;
V_416 -> type = V_892 ;
V_416 -> clock = V_38 -> V_64 . V_92 . V_93 ;
V_416 -> V_320 |= V_38 -> V_64 . V_92 . V_320 ;
V_416 -> V_893 = F_608 ( V_416 ) ;
V_416 -> V_894 = F_609 ( V_416 ) ;
F_610 ( V_416 ) ;
}
static void F_494 ( struct V_81 * V_81 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_895 ;
V_895 = 0 ;
if ( ( V_81 -> V_95 == V_117 && V_6 -> V_136 & V_137 ) ||
( V_81 -> V_95 == V_126 && V_6 -> V_136 & V_138 ) )
V_895 |= F_11 ( F_59 ( V_81 -> V_95 ) ) & V_139 ;
if ( V_81 -> V_91 -> V_232 )
V_895 |= V_233 ;
if ( F_18 ( V_57 ) || F_16 ( V_57 ) || F_17 ( V_57 ) ) {
if ( V_81 -> V_91 -> V_896 && V_81 -> V_91 -> V_725 != 30 )
V_895 |= V_897 |
V_898 ;
switch ( V_81 -> V_91 -> V_725 ) {
case 18 :
V_895 |= V_899 ;
break;
case 24 :
V_895 |= V_215 ;
break;
case 30 :
V_895 |= V_900 ;
break;
default:
F_144 () ;
}
}
if ( F_611 ( V_57 ) ) {
if ( V_81 -> V_804 ) {
F_157 ( L_126 ) ;
V_895 |= V_901 ;
} else {
F_157 ( L_127 ) ;
}
}
if ( V_81 -> V_91 -> V_64 . V_92 . V_320 & V_876 ) {
if ( F_58 ( V_57 ) -> V_103 < 4 ||
F_38 ( V_81 -> V_91 , V_219 ) )
V_895 |= V_902 ;
else
V_895 |= V_903 ;
} else
V_895 |= V_904 ;
if ( ( F_16 ( V_57 ) || F_17 ( V_57 ) ) &&
V_81 -> V_91 -> V_905 )
V_895 |= V_906 ;
F_122 ( F_59 ( V_81 -> V_95 ) , V_895 ) ;
F_123 ( F_59 ( V_81 -> V_95 ) ) ;
}
static int F_612 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
const struct V_58 * V_59 ;
int V_44 = 48000 ;
memset ( & V_62 -> V_179 , 0 ,
sizeof( V_62 -> V_179 ) ) ;
if ( F_38 ( V_62 , V_66 ) ) {
if ( F_560 ( V_6 ) ) {
V_44 = V_6 -> V_798 . V_907 ;
F_157 ( L_128 , V_44 ) ;
}
V_59 = & V_908 ;
} else if ( F_38 ( V_62 , V_192 ) ) {
V_59 = & V_909 ;
} else {
V_59 = & V_910 ;
}
if ( ! V_62 -> V_911 &&
! F_40 ( V_59 , V_62 , V_62 -> V_39 ,
V_44 , NULL , & V_62 -> V_45 ) ) {
F_125 ( L_129 ) ;
return - V_537 ;
}
F_604 ( V_65 , V_62 , NULL ) ;
return 0 ;
}
static int F_613 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
const struct V_58 * V_59 ;
int V_44 = 96000 ;
memset ( & V_62 -> V_179 , 0 ,
sizeof( V_62 -> V_179 ) ) ;
if ( F_38 ( V_62 , V_66 ) ) {
if ( F_560 ( V_6 ) ) {
V_44 = V_6 -> V_798 . V_907 ;
F_157 ( L_128 , V_44 ) ;
}
if ( F_39 ( V_57 ) )
V_59 = & V_912 ;
else
V_59 = & V_913 ;
} else if ( F_38 ( V_62 , V_214 ) ||
F_38 ( V_62 , V_605 ) ) {
V_59 = & V_914 ;
} else if ( F_38 ( V_62 , V_219 ) ) {
V_59 = & V_915 ;
} else {
V_59 = & V_916 ;
}
if ( ! V_62 -> V_911 &&
! F_42 ( V_59 , V_62 , V_62 -> V_39 ,
V_44 , NULL , & V_62 -> V_45 ) ) {
F_125 ( L_129 ) ;
return - V_537 ;
}
F_601 ( V_65 , V_62 , NULL ) ;
return 0 ;
}
static int F_614 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
const struct V_58 * V_59 ;
int V_44 = 96000 ;
memset ( & V_62 -> V_179 , 0 ,
sizeof( V_62 -> V_179 ) ) ;
if ( F_38 ( V_62 , V_66 ) ) {
if ( F_560 ( V_6 ) ) {
V_44 = V_6 -> V_798 . V_907 ;
F_157 ( L_128 , V_44 ) ;
}
V_59 = & V_917 ;
} else {
V_59 = & V_918 ;
}
if ( ! V_62 -> V_911 &&
! F_41 ( V_59 , V_62 , V_62 -> V_39 ,
V_44 , NULL , & V_62 -> V_45 ) ) {
F_125 ( L_129 ) ;
return - V_537 ;
}
F_601 ( V_65 , V_62 , NULL ) ;
return 0 ;
}
static int F_615 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
const struct V_58 * V_59 ;
int V_44 = 96000 ;
memset ( & V_62 -> V_179 , 0 ,
sizeof( V_62 -> V_179 ) ) ;
if ( F_38 ( V_62 , V_66 ) ) {
if ( F_560 ( V_6 ) ) {
V_44 = V_6 -> V_798 . V_907 ;
F_157 ( L_128 , V_44 ) ;
}
V_59 = & V_919 ;
} else {
V_59 = & V_916 ;
}
if ( ! V_62 -> V_911 &&
! F_40 ( V_59 , V_62 , V_62 -> V_39 ,
V_44 , NULL , & V_62 -> V_45 ) ) {
F_125 ( L_129 ) ;
return - V_537 ;
}
F_601 ( V_65 , V_62 , NULL ) ;
return 0 ;
}
static int F_616 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
int V_44 = 100000 ;
const struct V_58 * V_59 = & V_920 ;
memset ( & V_62 -> V_179 , 0 ,
sizeof( V_62 -> V_179 ) ) ;
if ( ! V_62 -> V_911 &&
! F_48 ( V_59 , V_62 , V_62 -> V_39 ,
V_44 , NULL , & V_62 -> V_45 ) ) {
F_125 ( L_129 ) ;
return - V_537 ;
}
F_584 ( V_65 , V_62 ) ;
return 0 ;
}
static int F_617 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
int V_44 = 100000 ;
const struct V_58 * V_59 = & V_921 ;
memset ( & V_62 -> V_179 , 0 ,
sizeof( V_62 -> V_179 ) ) ;
if ( ! V_62 -> V_911 &&
! F_46 ( V_59 , V_62 , V_62 -> V_39 ,
V_44 , NULL , & V_62 -> V_45 ) ) {
F_125 ( L_129 ) ;
return - V_537 ;
}
F_583 ( V_65 , V_62 ) ;
return 0 ;
}
static void F_618 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_184 ;
if ( F_58 ( V_57 ) -> V_103 <= 3 && ( F_139 ( V_57 ) || ! F_138 ( V_57 ) ) )
return;
V_184 = F_11 ( V_586 ) ;
if ( ! ( V_184 & V_587 ) )
return;
if ( F_58 ( V_57 ) -> V_103 < 4 ) {
if ( V_65 -> V_95 != V_126 )
return;
} else {
if ( ( V_184 & V_922 ) != ( V_65 -> V_95 << V_923 ) )
return;
}
V_38 -> V_584 . V_585 = V_184 ;
V_38 -> V_584 . V_589 = F_11 ( V_588 ) ;
}
static void F_619 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_38 -> V_97 ;
struct V_45 clock ;
T_1 V_815 ;
int V_44 = 100000 ;
if ( ( V_38 -> V_179 . V_45 & V_106 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_815 = F_131 ( V_6 , V_95 , F_586 ( V_95 ) ) ;
F_5 ( & V_6 -> V_9 ) ;
clock . V_54 = ( V_815 >> V_824 ) & 7 ;
clock . V_47 = V_815 & V_825 ;
clock . V_51 = ( V_815 >> V_828 ) & 0xf ;
clock . V_49 = ( V_815 >> V_826 ) & 7 ;
clock . V_50 = ( V_815 >> V_827 ) & 0x1f ;
V_38 -> V_39 = F_31 ( V_44 , & clock ) ;
}
static void
F_620 ( struct V_81 * V_65 ,
struct V_306 * V_307 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_15 , V_64 , V_281 ;
int V_95 = V_65 -> V_95 , V_140 = V_65 -> V_140 ;
int V_924 , V_244 ;
unsigned int V_925 ;
struct V_251 * V_90 ;
struct V_926 * V_927 ;
V_15 = F_11 ( F_86 ( V_140 ) ) ;
if ( ! ( V_15 & V_141 ) )
return;
V_927 = F_516 ( sizeof( * V_927 ) , V_717 ) ;
if ( ! V_927 ) {
F_157 ( L_130 ) ;
return;
}
V_90 = & V_927 -> V_64 ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
if ( V_15 & V_358 ) {
V_307 -> V_317 = V_318 ;
V_90 -> V_259 [ 0 ] = V_237 ;
}
}
V_244 = V_15 & V_928 ;
V_924 = F_201 ( V_244 ) ;
V_90 -> V_244 = V_924 ;
V_90 -> V_786 = F_173 ( V_924 , 0 ) * 8 ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
if ( V_307 -> V_317 )
V_281 = F_11 ( F_229 ( V_140 ) ) ;
else
V_281 = F_11 ( F_230 ( V_140 ) ) ;
V_64 = F_11 ( F_228 ( V_140 ) ) & 0xfffff000 ;
} else {
V_64 = F_11 ( F_231 ( V_140 ) ) ;
}
V_307 -> V_64 = V_64 ;
V_15 = F_11 ( F_294 ( V_95 ) ) ;
V_90 -> V_248 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_90 -> V_243 = ( ( V_15 >> 0 ) & 0xfff ) + 1 ;
V_15 = F_11 ( F_227 ( V_95 ) ) ;
V_90 -> V_260 [ 0 ] = V_15 & 0xffffffc0 ;
V_925 = F_172 ( V_57 , V_90 -> V_243 ,
V_90 -> V_244 ,
V_90 -> V_259 [ 0 ] ) ;
V_307 -> V_247 = V_90 -> V_260 [ 0 ] * V_925 ;
F_157 ( L_131 ,
F_76 ( V_95 ) , V_140 , V_90 -> V_248 , V_90 -> V_243 ,
V_90 -> V_786 , V_64 , V_90 -> V_260 [ 0 ] ,
V_307 -> V_247 ) ;
V_307 -> V_90 = V_927 ;
}
static void F_621 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_38 -> V_97 ;
enum V_182 V_183 = F_130 ( V_95 ) ;
struct V_45 clock ;
T_1 V_929 , V_930 , V_931 , V_932 , V_933 ;
int V_44 = 100000 ;
if ( ( V_38 -> V_179 . V_45 & V_106 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_929 = F_131 ( V_6 , V_95 , F_591 ( V_183 ) ) ;
V_930 = F_131 ( V_6 , V_95 , F_592 ( V_183 ) ) ;
V_931 = F_131 ( V_6 , V_95 , F_593 ( V_183 ) ) ;
V_932 = F_131 ( V_6 , V_95 , F_594 ( V_183 ) ) ;
V_933 = F_131 ( V_6 , V_95 , F_595 ( V_183 ) ) ;
F_5 ( & V_6 -> V_9 ) ;
clock . V_54 = ( V_931 & 0x7 ) == V_841 ? 2 : 0 ;
clock . V_47 = ( V_930 & 0xff ) << 22 ;
if ( V_933 & V_844 )
clock . V_47 |= V_932 & 0x3fffff ;
clock . V_51 = ( V_931 >> V_842 ) & 0xf ;
clock . V_49 = ( V_929 >> V_838 ) & 0x7 ;
clock . V_50 = ( V_929 >> V_839 ) & 0x1f ;
V_38 -> V_39 = F_32 ( V_44 , & clock ) ;
}
static bool F_622 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_134 V_135 ;
T_2 V_184 ;
bool V_267 ;
V_135 = F_432 ( V_65 -> V_95 ) ;
if ( ! F_83 ( V_6 , V_135 ) )
return false ;
V_38 -> V_97 = (enum V_94 ) V_65 -> V_95 ;
V_38 -> V_211 = NULL ;
V_267 = false ;
V_184 = F_11 ( F_59 ( V_65 -> V_95 ) ) ;
if ( ! ( V_184 & V_139 ) )
goto V_934;
if ( F_18 ( V_57 ) || F_16 ( V_57 ) || F_17 ( V_57 ) ) {
switch ( V_184 & V_213 ) {
case V_899 :
V_38 -> V_725 = 18 ;
break;
case V_215 :
V_38 -> V_725 = 24 ;
break;
case V_900 :
V_38 -> V_725 = 30 ;
break;
default:
break;
}
}
if ( ( F_16 ( V_57 ) || F_17 ( V_57 ) ) &&
( V_184 & V_906 ) )
V_38 -> V_905 = true ;
if ( F_58 ( V_57 ) -> V_103 < 4 )
V_38 -> V_232 = V_184 & V_233 ;
F_605 ( V_65 , V_38 ) ;
F_606 ( V_65 , V_38 ) ;
F_618 ( V_65 , V_38 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
if ( F_17 ( V_57 ) && V_65 -> V_95 != V_117 )
V_184 = V_6 -> V_189 [ V_65 -> V_95 ] ;
else
V_184 = F_11 ( F_128 ( V_65 -> V_95 ) ) ;
V_38 -> V_577 =
( ( V_184 & V_935 )
>> V_814 ) + 1 ;
V_38 -> V_179 . V_181 = V_184 ;
} else if ( F_602 ( V_57 ) || F_603 ( V_57 ) || F_553 ( V_57 ) ) {
V_184 = F_11 ( F_63 ( V_65 -> V_95 ) ) ;
V_38 -> V_577 =
( ( V_184 & V_936 )
>> V_857 ) + 1 ;
} else {
V_38 -> V_577 = 1 ;
}
V_38 -> V_179 . V_45 = F_11 ( F_63 ( V_65 -> V_95 ) ) ;
if ( ! F_16 ( V_57 ) && ! F_17 ( V_57 ) ) {
if ( F_139 ( V_57 ) )
V_38 -> V_179 . V_45 &= ~ V_193 ;
V_38 -> V_179 . V_704 = F_11 ( F_498 ( V_65 -> V_95 ) ) ;
V_38 -> V_179 . V_705 = F_11 ( F_499 ( V_65 -> V_95 ) ) ;
} else {
V_38 -> V_179 . V_45 &= ~ ( V_180 |
V_206 |
V_204 ) ;
}
if ( F_17 ( V_57 ) )
F_621 ( V_65 , V_38 ) ;
else if ( F_16 ( V_57 ) )
F_619 ( V_65 , V_38 ) ;
else
F_623 ( V_65 , V_38 ) ;
V_38 -> V_64 . V_92 . V_93 =
V_38 -> V_39 / V_38 -> V_577 ;
V_267 = true ;
V_934:
F_84 ( V_6 , V_135 ) ;
return V_267 ;
}
static void F_624 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_506 * V_507 ;
int V_142 ;
T_1 V_15 , V_937 ;
bool V_938 = false ;
bool V_939 = false ;
bool V_940 = false ;
bool V_941 = false ;
bool V_942 = false ;
bool V_943 = false ;
F_625 (dev, encoder) {
switch ( V_507 -> type ) {
case V_66 :
V_940 = true ;
V_938 = true ;
break;
case V_509 :
V_940 = true ;
if ( F_353 ( & V_507 -> V_64 ) -> V_183 == V_590 )
V_939 = true ;
break;
default:
break;
}
}
if ( F_118 ( V_57 ) ) {
V_941 = V_6 -> V_798 . V_944 ;
V_942 = V_941 ;
} else {
V_941 = false ;
V_942 = true ;
}
for ( V_142 = 0 ; V_142 < V_6 -> V_945 ; V_142 ++ ) {
T_1 V_440 = F_11 ( F_626 ( V_142 ) ) ;
if ( ! ( V_440 & V_106 ) )
continue;
if ( ( V_440 & V_946 ) ==
V_869 ) {
V_943 = true ;
break;
}
}
F_157 ( L_132 ,
V_940 , V_938 , V_941 , V_943 ) ;
V_15 = F_11 ( V_947 ) ;
V_937 = V_15 ;
V_937 &= ~ V_948 ;
if ( V_941 )
V_937 |= V_949 ;
else
V_937 |= V_950 ;
V_937 &= ~ V_951 ;
V_937 &= ~ V_952 ;
V_937 &= ~ V_953 ;
if ( V_940 ) {
V_937 |= V_954 ;
if ( F_560 ( V_6 ) && V_942 )
V_937 |= V_953 ;
if ( V_939 ) {
if ( F_560 ( V_6 ) && V_942 )
V_937 |= V_955 ;
else
V_937 |= V_956 ;
} else
V_937 |= V_957 ;
} else if ( V_943 ) {
V_937 |= V_954 ;
V_937 |= V_953 ;
}
if ( V_937 == V_15 )
return;
V_15 &= ~ V_948 ;
if ( V_941 )
V_15 |= V_949 ;
else
V_15 |= V_950 ;
if ( V_940 ) {
V_15 &= ~ V_951 ;
V_15 |= V_954 ;
if ( F_560 ( V_6 ) && V_942 ) {
F_157 ( L_133 ) ;
V_15 |= V_953 ;
} else
V_15 &= ~ V_953 ;
F_122 ( V_947 , V_15 ) ;
F_123 ( V_947 ) ;
F_124 ( 200 ) ;
V_15 &= ~ V_952 ;
if ( V_939 ) {
if ( F_560 ( V_6 ) && V_942 ) {
F_157 ( L_134 ) ;
V_15 |= V_955 ;
} else
V_15 |= V_956 ;
} else
V_15 |= V_957 ;
F_122 ( V_947 , V_15 ) ;
F_123 ( V_947 ) ;
F_124 ( 200 ) ;
} else {
F_157 ( L_135 ) ;
V_15 &= ~ V_952 ;
V_15 |= V_957 ;
F_122 ( V_947 , V_15 ) ;
F_123 ( V_947 ) ;
F_124 ( 200 ) ;
if ( ! V_943 ) {
F_157 ( L_136 ) ;
V_15 &= ~ V_951 ;
V_15 |= V_958 ;
V_15 &= ~ V_953 ;
F_122 ( V_947 , V_15 ) ;
F_123 ( V_947 ) ;
F_124 ( 200 ) ;
}
}
F_627 ( V_15 != V_937 ) ;
}
static void F_628 ( struct V_5 * V_6 )
{
T_2 V_184 ;
V_184 = F_11 ( V_959 ) ;
V_184 |= V_960 ;
F_122 ( V_959 , V_184 ) ;
if ( F_629 ( F_11 ( V_959 ) &
V_961 , 100 ) )
F_125 ( L_137 ) ;
V_184 = F_11 ( V_959 ) ;
V_184 &= ~ V_960 ;
F_122 ( V_959 , V_184 ) ;
if ( F_629 ( ( F_11 ( V_959 ) &
V_961 ) == 0 , 100 ) )
F_125 ( L_138 ) ;
}
static void F_630 ( struct V_5 * V_6 )
{
T_2 V_184 ;
V_184 = F_326 ( V_6 , 0x8008 , V_962 ) ;
V_184 &= ~ ( 0xFF << 24 ) ;
V_184 |= ( 0x12 << 24 ) ;
F_327 ( V_6 , 0x8008 , V_184 , V_962 ) ;
V_184 = F_326 ( V_6 , 0x2008 , V_962 ) ;
V_184 |= ( 1 << 11 ) ;
F_327 ( V_6 , 0x2008 , V_184 , V_962 ) ;
V_184 = F_326 ( V_6 , 0x2108 , V_962 ) ;
V_184 |= ( 1 << 11 ) ;
F_327 ( V_6 , 0x2108 , V_184 , V_962 ) ;
V_184 = F_326 ( V_6 , 0x206C , V_962 ) ;
V_184 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_327 ( V_6 , 0x206C , V_184 , V_962 ) ;
V_184 = F_326 ( V_6 , 0x216C , V_962 ) ;
V_184 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_327 ( V_6 , 0x216C , V_184 , V_962 ) ;
V_184 = F_326 ( V_6 , 0x2080 , V_962 ) ;
V_184 &= ~ ( 7 << 13 ) ;
V_184 |= ( 5 << 13 ) ;
F_327 ( V_6 , 0x2080 , V_184 , V_962 ) ;
V_184 = F_326 ( V_6 , 0x2180 , V_962 ) ;
V_184 &= ~ ( 7 << 13 ) ;
V_184 |= ( 5 << 13 ) ;
F_327 ( V_6 , 0x2180 , V_184 , V_962 ) ;
V_184 = F_326 ( V_6 , 0x208C , V_962 ) ;
V_184 &= ~ 0xFF ;
V_184 |= 0x1C ;
F_327 ( V_6 , 0x208C , V_184 , V_962 ) ;
V_184 = F_326 ( V_6 , 0x218C , V_962 ) ;
V_184 &= ~ 0xFF ;
V_184 |= 0x1C ;
F_327 ( V_6 , 0x218C , V_184 , V_962 ) ;
V_184 = F_326 ( V_6 , 0x2098 , V_962 ) ;
V_184 &= ~ ( 0xFF << 16 ) ;
V_184 |= ( 0x1C << 16 ) ;
F_327 ( V_6 , 0x2098 , V_184 , V_962 ) ;
V_184 = F_326 ( V_6 , 0x2198 , V_962 ) ;
V_184 &= ~ ( 0xFF << 16 ) ;
V_184 |= ( 0x1C << 16 ) ;
F_327 ( V_6 , 0x2198 , V_184 , V_962 ) ;
V_184 = F_326 ( V_6 , 0x20C4 , V_962 ) ;
V_184 |= ( 1 << 27 ) ;
F_327 ( V_6 , 0x20C4 , V_184 , V_962 ) ;
V_184 = F_326 ( V_6 , 0x21C4 , V_962 ) ;
V_184 |= ( 1 << 27 ) ;
F_327 ( V_6 , 0x21C4 , V_184 , V_962 ) ;
V_184 = F_326 ( V_6 , 0x20EC , V_962 ) ;
V_184 &= ~ ( 0xF << 28 ) ;
V_184 |= ( 4 << 28 ) ;
F_327 ( V_6 , 0x20EC , V_184 , V_962 ) ;
V_184 = F_326 ( V_6 , 0x21EC , V_962 ) ;
V_184 &= ~ ( 0xF << 28 ) ;
V_184 |= ( 4 << 28 ) ;
F_327 ( V_6 , 0x21EC , V_184 , V_962 ) ;
}
static void F_631 ( struct V_56 * V_57 , bool V_963 ,
bool V_964 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_13 , V_184 ;
if ( F_7 ( V_964 && ! V_963 , L_139 ) )
V_963 = true ;
if ( F_7 ( F_632 ( V_57 ) && V_964 , L_140 ) )
V_964 = false ;
F_3 ( & V_6 -> V_9 ) ;
V_184 = F_326 ( V_6 , V_965 , V_483 ) ;
V_184 &= ~ V_484 ;
V_184 |= V_966 ;
F_327 ( V_6 , V_965 , V_184 , V_483 ) ;
F_124 ( 24 ) ;
if ( V_963 ) {
V_184 = F_326 ( V_6 , V_965 , V_483 ) ;
V_184 &= ~ V_966 ;
F_327 ( V_6 , V_965 , V_184 , V_483 ) ;
if ( V_964 ) {
F_628 ( V_6 ) ;
F_630 ( V_6 ) ;
}
}
V_13 = F_632 ( V_57 ) ? V_967 : V_968 ;
V_184 = F_326 ( V_6 , V_13 , V_483 ) ;
V_184 |= V_969 ;
F_327 ( V_6 , V_13 , V_184 , V_483 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_633 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_13 , V_184 ;
F_3 ( & V_6 -> V_9 ) ;
V_13 = F_632 ( V_57 ) ? V_967 : V_968 ;
V_184 = F_326 ( V_6 , V_13 , V_483 ) ;
V_184 &= ~ V_969 ;
F_327 ( V_6 , V_13 , V_184 , V_483 ) ;
V_184 = F_326 ( V_6 , V_965 , V_483 ) ;
if ( ! ( V_184 & V_484 ) ) {
if ( ! ( V_184 & V_966 ) ) {
V_184 |= V_966 ;
F_327 ( V_6 , V_965 , V_184 , V_483 ) ;
F_124 ( 32 ) ;
}
V_184 |= V_484 ;
F_327 ( V_6 , V_965 , V_184 , V_483 ) ;
}
F_5 ( & V_6 -> V_9 ) ;
}
static void F_634 ( struct V_5 * V_6 , int V_970 )
{
T_2 V_184 ;
int V_971 = F_635 ( V_970 ) ;
if ( F_28 ( V_970 % 5 != 0 ) )
return;
if ( F_28 ( V_971 >= F_176 ( V_972 ) ) )
return;
F_3 ( & V_6 -> V_9 ) ;
if ( V_970 % 10 != 0 )
V_184 = 0xAAAAAAAB ;
else
V_184 = 0x00000000 ;
F_327 ( V_6 , V_973 , V_184 , V_483 ) ;
V_184 = F_326 ( V_6 , V_974 , V_483 ) ;
V_184 &= 0xffff0000 ;
V_184 |= V_972 [ V_971 ] ;
F_327 ( V_6 , V_974 , V_184 , V_483 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_636 ( struct V_56 * V_57 )
{
struct V_506 * V_507 ;
bool V_975 = false ;
F_625 (dev, encoder) {
switch ( V_507 -> type ) {
case V_605 :
V_975 = true ;
break;
default:
break;
}
}
if ( V_975 ) {
F_634 ( F_53 ( V_57 ) , 0 ) ;
F_631 ( V_57 , true , true ) ;
} else {
F_633 ( V_57 ) ;
}
}
void F_637 ( struct V_56 * V_57 )
{
if ( F_118 ( V_57 ) || F_104 ( V_57 ) )
F_624 ( V_57 ) ;
else if ( F_159 ( V_57 ) )
F_636 ( V_57 ) ;
}
static void F_402 ( struct V_87 * V_65 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_2 V_15 ;
V_15 = 0 ;
switch ( V_81 -> V_91 -> V_725 ) {
case 18 :
V_15 |= V_899 ;
break;
case 24 :
V_15 |= V_215 ;
break;
case 30 :
V_15 |= V_900 ;
break;
case 36 :
V_15 |= V_976 ;
break;
default:
F_144 () ;
}
if ( V_81 -> V_91 -> V_896 )
V_15 |= ( V_897 | V_898 ) ;
if ( V_81 -> V_91 -> V_64 . V_92 . V_320 & V_876 )
V_15 |= V_218 ;
else
V_15 |= V_904 ;
if ( V_81 -> V_91 -> V_905 )
V_15 |= V_906 ;
F_122 ( F_59 ( V_95 ) , V_15 ) ;
F_123 ( F_59 ( V_95 ) ) ;
}
static void F_410 ( struct V_87 * V_65 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
enum V_94 V_97 = V_81 -> V_91 -> V_97 ;
T_1 V_15 = 0 ;
if ( F_234 ( V_6 ) && V_81 -> V_91 -> V_896 )
V_15 |= ( V_897 | V_898 ) ;
if ( V_81 -> V_91 -> V_64 . V_92 . V_320 & V_876 )
V_15 |= V_218 ;
else
V_15 |= V_904 ;
F_122 ( F_59 ( V_97 ) , V_15 ) ;
F_123 ( F_59 ( V_97 ) ) ;
}
static void F_411 ( struct V_87 * V_65 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
if ( F_235 ( V_6 ) || F_58 ( V_6 ) -> V_103 >= 9 ) {
T_1 V_15 = 0 ;
switch ( V_81 -> V_91 -> V_725 ) {
case 18 :
V_15 |= V_977 ;
break;
case 24 :
V_15 |= V_978 ;
break;
case 30 :
V_15 |= V_979 ;
break;
case 36 :
V_15 |= V_980 ;
break;
default:
F_144 () ;
}
if ( V_81 -> V_91 -> V_896 )
V_15 |= V_981 | V_982 ;
F_122 ( F_638 ( V_81 -> V_95 ) , V_15 ) ;
}
}
int F_523 ( int V_85 , int V_722 , int V_983 )
{
T_1 V_984 = V_85 * V_983 * 21 / 20 ;
return F_181 ( V_984 , V_722 * 8 ) ;
}
static bool F_639 ( struct V_45 * V_45 , int V_985 )
{
return F_29 ( V_45 ) < V_985 * V_45 -> V_51 ;
}
static void F_640 ( struct V_81 * V_81 ,
struct V_37 * V_62 ,
struct V_45 * V_801 )
{
struct V_87 * V_65 = & V_81 -> V_64 ;
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_45 , V_802 , V_803 ;
int V_985 ;
V_985 = 21 ;
if ( F_38 ( V_62 , V_66 ) ) {
if ( ( F_560 ( V_6 ) &&
V_6 -> V_798 . V_907 == 100000 ) ||
( F_118 ( V_57 ) && F_39 ( V_57 ) ) )
V_985 = 25 ;
} else if ( V_62 -> V_867 )
V_985 = 20 ;
V_802 = F_562 ( & V_62 -> V_45 ) ;
if ( F_639 ( & V_62 -> V_45 , V_985 ) )
V_802 |= V_986 ;
if ( V_801 ) {
V_803 = F_562 ( V_801 ) ;
if ( V_801 -> V_46 < V_985 * V_801 -> V_51 )
V_803 |= V_986 ;
} else {
V_803 = V_802 ;
}
V_45 = 0 ;
if ( F_38 ( V_62 , V_66 ) )
V_45 |= V_855 ;
else
V_45 |= V_856 ;
V_45 |= ( V_62 -> V_577 - 1 )
<< V_987 ;
if ( F_38 ( V_62 , V_219 ) ||
F_38 ( V_62 , V_214 ) )
V_45 |= V_858 ;
if ( F_361 ( V_62 ) )
V_45 |= V_858 ;
V_45 |= ( 1 << ( V_62 -> V_45 . V_49 - 1 ) ) << V_860 ;
V_45 |= ( 1 << ( V_62 -> V_45 . V_49 - 1 ) ) << V_861 ;
switch ( V_62 -> V_45 . V_50 ) {
case 5 :
V_45 |= V_862 ;
break;
case 7 :
V_45 |= V_863 ;
break;
case 10 :
V_45 |= V_864 ;
break;
case 14 :
V_45 |= V_865 ;
break;
}
if ( F_38 ( V_62 , V_66 ) &&
F_560 ( V_6 ) )
V_45 |= V_869 ;
else
V_45 |= V_870 ;
V_45 |= V_106 ;
V_62 -> V_179 . V_45 = V_45 ;
V_62 -> V_179 . V_704 = V_802 ;
V_62 -> V_179 . V_705 = V_803 ;
}
static int F_641 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_45 V_801 ;
bool V_988 = false ;
struct V_989 * V_990 ;
const struct V_58 * V_59 ;
int V_44 = 120000 ;
memset ( & V_62 -> V_179 , 0 ,
sizeof( V_62 -> V_179 ) ) ;
V_65 -> V_804 = false ;
if ( ! V_62 -> V_229 )
return 0 ;
if ( F_38 ( V_62 , V_66 ) ) {
if ( F_560 ( V_6 ) ) {
F_157 ( L_128 ,
V_6 -> V_798 . V_907 ) ;
V_44 = V_6 -> V_798 . V_907 ;
}
if ( F_39 ( V_57 ) ) {
if ( V_44 == 100000 )
V_59 = & V_991 ;
else
V_59 = & V_992 ;
} else {
if ( V_44 == 100000 )
V_59 = & V_993 ;
else
V_59 = & V_994 ;
}
} else {
V_59 = & V_995 ;
}
if ( ! V_62 -> V_911 &&
! F_42 ( V_59 , V_62 , V_62 -> V_39 ,
V_44 , NULL , & V_62 -> V_45 ) ) {
F_125 ( L_129 ) ;
return - V_537 ;
}
F_640 ( V_65 , V_62 ,
V_988 ? & V_801 : NULL ) ;
V_990 = F_642 ( V_65 , V_62 , NULL ) ;
if ( V_990 == NULL ) {
F_20 ( L_141 ,
F_76 ( V_65 -> V_95 ) ) ;
return - V_537 ;
}
if ( F_38 ( V_62 , V_66 ) &&
V_988 )
V_65 -> V_804 = true ;
return 0 ;
}
static void F_643 ( struct V_81 * V_65 ,
struct V_790 * V_791 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
V_791 -> V_795 = F_11 ( F_570 ( V_95 ) ) ;
V_791 -> V_796 = F_11 ( F_571 ( V_95 ) ) ;
V_791 -> V_793 = F_11 ( F_567 ( V_95 ) )
& ~ V_510 ;
V_791 -> V_794 = F_11 ( F_569 ( V_95 ) ) ;
V_791 -> V_792 = ( ( F_11 ( F_567 ( V_95 ) )
& V_510 ) >> V_996 ) + 1 ;
}
static void F_644 ( struct V_81 * V_65 ,
enum V_94 V_94 ,
struct V_790 * V_791 ,
struct V_790 * V_807 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
if ( F_58 ( V_57 ) -> V_103 >= 5 ) {
V_791 -> V_795 = F_11 ( F_573 ( V_94 ) ) ;
V_791 -> V_796 = F_11 ( F_574 ( V_94 ) ) ;
V_791 -> V_793 = F_11 ( F_356 ( V_94 ) )
& ~ V_510 ;
V_791 -> V_794 = F_11 ( F_572 ( V_94 ) ) ;
V_791 -> V_792 = ( ( F_11 ( F_356 ( V_94 ) )
& V_510 ) >> V_996 ) + 1 ;
if ( V_807 && F_58 ( V_57 ) -> V_103 < 8 &&
V_65 -> V_91 -> V_808 ) {
V_807 -> V_795 = F_11 ( F_577 ( V_94 ) ) ;
V_807 -> V_796 = F_11 ( F_578 ( V_94 ) ) ;
V_807 -> V_793 = F_11 ( F_575 ( V_94 ) )
& ~ V_510 ;
V_807 -> V_794 = F_11 ( F_576 ( V_94 ) ) ;
V_807 -> V_792 = ( ( F_11 ( F_575 ( V_94 ) )
& V_510 ) >> V_996 ) + 1 ;
}
} else {
V_791 -> V_795 = F_11 ( F_581 ( V_95 ) ) ;
V_791 -> V_796 = F_11 ( F_582 ( V_95 ) ) ;
V_791 -> V_793 = F_11 ( F_579 ( V_95 ) )
& ~ V_510 ;
V_791 -> V_794 = F_11 ( F_580 ( V_95 ) ) ;
V_791 -> V_792 = ( ( F_11 ( F_579 ( V_95 ) )
& V_510 ) >> V_996 ) + 1 ;
}
}
void F_645 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
if ( V_38 -> V_229 )
F_643 ( V_65 , & V_38 -> V_810 ) ;
else
F_644 ( V_65 , V_38 -> V_97 ,
& V_38 -> V_810 ,
& V_38 -> V_811 ) ;
}
static void F_646 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
F_644 ( V_65 , V_38 -> V_97 ,
& V_38 -> V_572 , NULL ) ;
}
static void F_647 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_373 * V_374 = & V_38 -> V_374 ;
T_2 V_414 = 0 ;
int V_372 = - 1 ;
int V_142 ;
for ( V_142 = 0 ; V_142 < V_65 -> V_375 ; V_142 ++ ) {
V_414 = F_11 ( F_243 ( V_65 -> V_95 , V_142 ) ) ;
if ( V_414 & V_415 && ! ( V_414 & V_997 ) ) {
V_372 = V_142 ;
V_38 -> V_439 . V_151 = true ;
V_38 -> V_439 . V_544 = F_11 ( F_244 ( V_65 -> V_95 , V_142 ) ) ;
V_38 -> V_439 . V_247 = F_11 ( F_245 ( V_65 -> V_95 , V_142 ) ) ;
break;
}
}
V_374 -> V_406 = V_372 ;
if ( V_372 >= 0 ) {
V_374 -> V_528 |= ( 1 << V_538 ) ;
} else {
V_374 -> V_528 &= ~ ( 1 << V_538 ) ;
}
}
static void
F_648 ( struct V_81 * V_65 ,
struct V_306 * V_307 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_15 , V_64 , V_281 , V_998 , V_317 ;
int V_95 = V_65 -> V_95 ;
int V_924 , V_244 ;
unsigned int V_925 ;
struct V_251 * V_90 ;
struct V_926 * V_927 ;
V_927 = F_516 ( sizeof( * V_927 ) , V_717 ) ;
if ( ! V_927 ) {
F_157 ( L_130 ) ;
return;
}
V_90 = & V_927 -> V_64 ;
V_15 = F_11 ( F_92 ( V_95 , 0 ) ) ;
if ( ! ( V_15 & V_147 ) )
goto error;
V_244 = V_15 & V_999 ;
V_924 = F_202 ( V_244 ,
V_15 & V_379 ,
V_15 & V_1000 ) ;
V_90 -> V_244 = V_924 ;
V_90 -> V_786 = F_173 ( V_924 , 0 ) * 8 ;
V_317 = V_15 & V_1001 ;
switch ( V_317 ) {
case V_1002 :
V_90 -> V_259 [ 0 ] = V_236 ;
break;
case V_390 :
V_307 -> V_317 = V_318 ;
V_90 -> V_259 [ 0 ] = V_237 ;
break;
case V_391 :
V_90 -> V_259 [ 0 ] = V_238 ;
break;
case V_392 :
V_90 -> V_259 [ 0 ] = V_239 ;
break;
default:
F_169 ( V_317 ) ;
goto error;
}
V_64 = F_11 ( F_259 ( V_95 , 0 ) ) & 0xfffff000 ;
V_307 -> V_64 = V_64 ;
V_281 = F_11 ( F_253 ( V_95 , 0 ) ) ;
V_15 = F_11 ( F_254 ( V_95 , 0 ) ) ;
V_90 -> V_243 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_90 -> V_248 = ( ( V_15 >> 0 ) & 0x1fff ) + 1 ;
V_15 = F_11 ( F_255 ( V_95 , 0 ) ) ;
V_998 = F_237 ( V_6 , V_90 -> V_259 [ 0 ] ,
V_90 -> V_244 ) ;
V_90 -> V_260 [ 0 ] = ( V_15 & 0x3ff ) * V_998 ;
V_925 = F_172 ( V_57 , V_90 -> V_243 ,
V_90 -> V_244 ,
V_90 -> V_259 [ 0 ] ) ;
V_307 -> V_247 = V_90 -> V_260 [ 0 ] * V_925 ;
F_157 ( L_142 ,
F_76 ( V_95 ) , V_90 -> V_248 , V_90 -> V_243 ,
V_90 -> V_786 , V_64 , V_90 -> V_260 [ 0 ] ,
V_307 -> V_247 ) ;
V_307 -> V_90 = V_927 ;
return;
error:
F_215 ( V_90 ) ;
}
static void F_649 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_184 ;
V_184 = F_11 ( F_368 ( V_65 -> V_95 ) ) ;
if ( V_184 & V_545 ) {
V_38 -> V_439 . V_151 = true ;
V_38 -> V_439 . V_544 = F_11 ( F_370 ( V_65 -> V_95 ) ) ;
V_38 -> V_439 . V_247 = F_11 ( F_371 ( V_65 -> V_95 ) ) ;
if ( F_650 ( V_57 ) ) {
F_28 ( ( V_184 & V_1003 ) !=
F_369 ( V_65 -> V_95 ) ) ;
}
}
}
static void
F_651 ( struct V_81 * V_65 ,
struct V_306 * V_307 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_15 , V_64 , V_281 ;
int V_95 = V_65 -> V_95 ;
int V_924 , V_244 ;
unsigned int V_925 ;
struct V_251 * V_90 ;
struct V_926 * V_927 ;
V_15 = F_11 ( F_86 ( V_95 ) ) ;
if ( ! ( V_15 & V_141 ) )
return;
V_927 = F_516 ( sizeof( * V_927 ) , V_717 ) ;
if ( ! V_927 ) {
F_157 ( L_130 ) ;
return;
}
V_90 = & V_927 -> V_64 ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
if ( V_15 & V_358 ) {
V_307 -> V_317 = V_318 ;
V_90 -> V_259 [ 0 ] = V_237 ;
}
}
V_244 = V_15 & V_928 ;
V_924 = F_201 ( V_244 ) ;
V_90 -> V_244 = V_924 ;
V_90 -> V_786 = F_173 ( V_924 , 0 ) * 8 ;
V_64 = F_11 ( F_228 ( V_95 ) ) & 0xfffff000 ;
if ( F_234 ( V_57 ) || F_235 ( V_57 ) ) {
V_281 = F_11 ( F_236 ( V_95 ) ) ;
} else {
if ( V_307 -> V_317 )
V_281 = F_11 ( F_229 ( V_95 ) ) ;
else
V_281 = F_11 ( F_230 ( V_95 ) ) ;
}
V_307 -> V_64 = V_64 ;
V_15 = F_11 ( F_294 ( V_95 ) ) ;
V_90 -> V_248 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_90 -> V_243 = ( ( V_15 >> 0 ) & 0xfff ) + 1 ;
V_15 = F_11 ( F_227 ( V_95 ) ) ;
V_90 -> V_260 [ 0 ] = V_15 & 0xffffffc0 ;
V_925 = F_172 ( V_57 , V_90 -> V_243 ,
V_90 -> V_244 ,
V_90 -> V_259 [ 0 ] ) ;
V_307 -> V_247 = V_90 -> V_260 [ 0 ] * V_925 ;
F_157 ( L_142 ,
F_76 ( V_95 ) , V_90 -> V_248 , V_90 -> V_243 ,
V_90 -> V_786 , V_64 , V_90 -> V_260 [ 0 ] ,
V_307 -> V_247 ) ;
V_307 -> V_90 = V_927 ;
}
static bool F_652 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_134 V_135 ;
T_2 V_184 ;
bool V_267 ;
V_135 = F_432 ( V_65 -> V_95 ) ;
if ( ! F_83 ( V_6 , V_135 ) )
return false ;
V_38 -> V_97 = (enum V_94 ) V_65 -> V_95 ;
V_38 -> V_211 = NULL ;
V_267 = false ;
V_184 = F_11 ( F_59 ( V_65 -> V_95 ) ) ;
if ( ! ( V_184 & V_139 ) )
goto V_934;
switch ( V_184 & V_213 ) {
case V_899 :
V_38 -> V_725 = 18 ;
break;
case V_215 :
V_38 -> V_725 = 24 ;
break;
case V_900 :
V_38 -> V_725 = 30 ;
break;
case V_976 :
V_38 -> V_725 = 36 ;
break;
default:
break;
}
if ( V_184 & V_906 )
V_38 -> V_905 = true ;
if ( F_11 ( F_102 ( V_65 -> V_95 ) ) & V_152 ) {
struct V_989 * V_990 ;
enum V_1004 V_1005 ;
V_38 -> V_229 = true ;
V_184 = F_11 ( F_71 ( V_65 -> V_95 ) ) ;
V_38 -> V_453 = ( ( V_452 & V_184 ) >>
V_1006 ) + 1 ;
F_646 ( V_65 , V_38 ) ;
if ( F_118 ( V_6 ) ) {
V_1005 = (enum V_1004 ) V_65 -> V_95 ;
} else {
V_184 = F_11 ( V_513 ) ;
if ( V_184 & F_358 ( V_65 -> V_95 ) )
V_1005 = V_514 ;
else
V_1005 = V_1007 ;
}
V_38 -> V_211 =
F_359 ( V_6 , V_1005 ) ;
V_990 = V_38 -> V_211 ;
F_28 ( ! V_990 -> V_1008 . V_712 ( V_6 , V_990 ,
& V_38 -> V_179 ) ) ;
V_184 = V_38 -> V_179 . V_45 ;
V_38 -> V_577 =
( ( V_184 & V_1009 )
>> V_987 ) + 1 ;
F_653 ( V_65 , V_38 ) ;
} else {
V_38 -> V_577 = 1 ;
}
F_605 ( V_65 , V_38 ) ;
F_606 ( V_65 , V_38 ) ;
F_649 ( V_65 , V_38 ) ;
V_267 = true ;
V_934:
F_84 ( V_6 , V_135 ) ;
return V_267 ;
}
static void F_654 ( struct V_5 * V_6 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
struct V_81 * V_65 ;
F_136 (dev, crtc)
F_64 ( V_65 -> V_88 , L_143 ,
F_76 ( V_65 -> V_95 ) ) ;
F_64 ( F_11 ( V_1010 ) , L_144 ) ;
F_64 ( F_11 ( V_1011 ) & V_1012 , L_145 ) ;
F_64 ( F_11 ( F_655 ( 0 ) ) & V_1013 , L_146 ) ;
F_64 ( F_11 ( F_655 ( 1 ) ) & V_1013 , L_147 ) ;
F_64 ( F_11 ( V_1014 ) & V_1015 , L_148 ) ;
F_64 ( F_11 ( V_1016 ) & V_1017 ,
L_149 ) ;
if ( F_234 ( V_57 ) )
F_64 ( F_11 ( V_1018 ) & V_1017 ,
L_150 ) ;
F_64 ( F_11 ( V_1019 ) & V_1020 ,
L_151 ) ;
F_64 ( F_11 ( V_1021 ) & V_1022 ,
L_152 ) ;
F_64 ( F_11 ( V_1023 ) & V_1024 , L_153 ) ;
F_64 ( F_656 ( V_6 ) , L_154 ) ;
}
static T_2 F_657 ( struct V_5 * V_6 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
if ( F_234 ( V_57 ) )
return F_11 ( V_1025 ) ;
else
return F_11 ( V_1026 ) ;
}
static void F_658 ( struct V_5 * V_6 , T_2 V_15 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
if ( F_234 ( V_57 ) ) {
F_3 ( & V_6 -> V_548 . V_549 ) ;
if ( F_374 ( V_6 , V_1027 ,
V_15 ) )
F_125 ( L_155 ) ;
F_5 ( & V_6 -> V_548 . V_549 ) ;
} else {
F_122 ( V_1026 , V_15 ) ;
F_123 ( V_1026 ) ;
}
}
static void F_659 ( struct V_5 * V_6 ,
bool V_1028 , bool V_1029 )
{
T_2 V_15 ;
F_654 ( V_6 ) ;
V_15 = F_11 ( V_733 ) ;
if ( V_1028 ) {
V_15 |= V_736 ;
F_122 ( V_733 , V_15 ) ;
if ( F_629 ( F_11 ( V_733 ) &
V_1030 , 1 ) )
F_125 ( L_156 ) ;
V_15 = F_11 ( V_733 ) ;
}
V_15 |= V_1031 ;
F_122 ( V_733 , V_15 ) ;
F_123 ( V_733 ) ;
if ( F_60 ( V_6 , V_733 , V_655 , 0 , 1 ) )
F_125 ( L_157 ) ;
V_15 = F_657 ( V_6 ) ;
V_15 |= V_1032 ;
F_658 ( V_6 , V_15 ) ;
F_660 ( 100 ) ;
if ( F_61 ( ( F_657 ( V_6 ) & V_1033 ) == 0 ,
1 ) )
F_125 ( L_158 ) ;
if ( V_1029 ) {
V_15 = F_11 ( V_733 ) ;
V_15 |= V_1034 ;
F_122 ( V_733 , V_15 ) ;
F_123 ( V_733 ) ;
}
}
static void F_661 ( struct V_5 * V_6 )
{
T_2 V_15 ;
V_15 = F_11 ( V_733 ) ;
if ( ( V_15 & ( V_655 | V_1031 | V_736 |
V_1034 ) ) == V_655 )
return;
F_662 ( V_6 , V_1035 ) ;
if ( V_15 & V_1034 ) {
V_15 &= ~ V_1034 ;
F_122 ( V_733 , V_15 ) ;
F_123 ( V_733 ) ;
}
V_15 = F_657 ( V_6 ) ;
V_15 |= V_1036 ;
V_15 &= ~ V_1032 ;
F_658 ( V_6 , V_15 ) ;
V_15 = F_11 ( V_733 ) ;
V_15 &= ~ V_1031 ;
F_122 ( V_733 , V_15 ) ;
if ( F_60 ( V_6 ,
V_733 , V_655 , V_655 ,
5 ) )
F_125 ( L_159 ) ;
if ( V_15 & V_736 ) {
V_15 = F_11 ( V_733 ) ;
V_15 &= ~ V_736 ;
F_122 ( V_733 , V_15 ) ;
if ( F_629 ( ( F_11 ( V_733 ) &
V_1030 ) == 0 , 1 ) )
F_125 ( L_160 ) ;
}
F_663 ( V_6 , V_1035 ) ;
F_447 ( & V_6 -> V_114 ) ;
}
void F_664 ( struct V_5 * V_6 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
T_2 V_15 ;
F_157 ( L_161 ) ;
if ( F_632 ( V_57 ) ) {
V_15 = F_11 ( V_1037 ) ;
V_15 &= ~ V_1038 ;
F_122 ( V_1037 , V_15 ) ;
}
F_633 ( V_57 ) ;
F_659 ( V_6 , true , true ) ;
}
void F_665 ( struct V_5 * V_6 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
T_2 V_15 ;
F_157 ( L_162 ) ;
F_661 ( V_6 ) ;
F_636 ( V_57 ) ;
if ( F_632 ( V_57 ) ) {
V_15 = F_11 ( V_1037 ) ;
V_15 |= V_1038 ;
F_122 ( V_1037 , V_15 ) ;
}
}
static void F_666 ( struct V_420 * V_559 )
{
struct V_56 * V_57 = V_559 -> V_57 ;
struct V_689 * V_700 =
F_270 ( V_559 ) ;
unsigned int V_701 = V_700 -> V_692 ;
F_453 ( F_53 ( V_57 ) , V_701 ) ;
}
static int F_487 ( struct V_420 * V_43 )
{
struct V_689 * V_329 = F_270 ( V_43 ) ;
struct V_5 * V_6 = F_53 ( V_43 -> V_57 ) ;
struct V_87 * V_65 ;
struct V_42 * V_1039 ;
struct V_37 * V_62 ;
unsigned V_1040 = 0 , V_142 ;
enum V_95 V_95 ;
memcpy ( V_329 -> V_690 , V_6 -> V_690 ,
sizeof( V_329 -> V_690 ) ) ;
F_269 (state, crtc, cstate, i) {
int V_1041 ;
V_62 = F_265 ( V_1039 ) ;
if ( ! V_62 -> V_64 . V_502 ) {
V_329 -> V_690 [ V_142 ] = 0 ;
continue;
}
V_1041 = F_526 ( V_62 ) ;
if ( F_235 ( V_6 ) && V_62 -> V_547 )
V_1041 = F_181 ( V_1041 * 100 , 95 ) ;
V_329 -> V_690 [ V_142 ] = V_1041 ;
}
F_89 (dev_priv, pipe)
V_1040 = V_61 ( V_329 -> V_690 [ V_95 ] , V_1040 ) ;
return V_1040 ;
}
static void F_667 ( struct V_56 * V_57 , int V_633 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_15 , V_1042 ;
int V_267 ;
if ( F_7 ( ( F_11 ( V_733 ) &
( V_1031 | V_655 |
V_1043 | V_1044 |
V_1045 | V_1034 |
V_736 ) ) != V_655 ,
L_163 ) )
return;
F_3 ( & V_6 -> V_548 . V_549 ) ;
V_267 = F_374 ( V_6 ,
V_1046 , 0x0 ) ;
F_5 ( & V_6 -> V_548 . V_549 ) ;
if ( V_267 ) {
F_125 ( L_164 ) ;
return;
}
V_15 = F_11 ( V_733 ) ;
V_15 |= V_736 ;
F_122 ( V_733 , V_15 ) ;
if ( F_629 ( F_11 ( V_733 ) &
V_1030 , 1 ) )
F_125 ( L_156 ) ;
V_15 = F_11 ( V_733 ) ;
V_15 &= ~ V_735 ;
switch ( V_633 ) {
case 450000 :
V_15 |= V_737 ;
V_1042 = 0 ;
break;
case 540000 :
V_15 |= V_738 ;
V_1042 = 1 ;
break;
case 337500 :
V_15 |= V_739 ;
V_1042 = 2 ;
break;
case 675000 :
V_15 |= V_1047 ;
V_1042 = 3 ;
break;
default:
F_7 ( 1 , L_165 ) ;
return;
}
F_122 ( V_733 , V_15 ) ;
V_15 = F_11 ( V_733 ) ;
V_15 &= ~ V_736 ;
F_122 ( V_733 , V_15 ) ;
if ( F_629 ( ( F_11 ( V_733 ) &
V_1030 ) == 0 , 1 ) )
F_125 ( L_160 ) ;
F_3 ( & V_6 -> V_548 . V_549 ) ;
F_374 ( V_6 , V_644 , V_1042 ) ;
F_5 ( & V_6 -> V_548 . V_549 ) ;
F_122 ( V_1048 , F_8 ( V_633 , 1000 ) - 1 ) ;
F_447 ( V_57 ) ;
F_7 ( V_633 != V_6 -> V_627 ,
L_166 ,
V_633 , V_6 -> V_627 ) ;
}
static int F_668 ( int V_652 )
{
if ( V_652 > 540000 )
return 675000 ;
else if ( V_652 > 450000 )
return 540000 ;
else if ( V_652 > 337500 )
return 450000 ;
else
return 337500 ;
}
static int F_669 ( struct V_420 * V_43 )
{
struct V_5 * V_6 = F_53 ( V_43 -> V_57 ) ;
struct V_689 * V_329 = F_270 ( V_43 ) ;
int V_652 = F_487 ( V_43 ) ;
int V_633 ;
V_633 = F_668 ( V_652 ) ;
if ( V_633 > V_6 -> V_617 ) {
F_157 ( L_167 ,
V_633 , V_6 -> V_617 ) ;
return - V_537 ;
}
V_329 -> V_633 = V_329 -> V_692 = V_633 ;
if ( ! V_329 -> V_693 )
V_329 -> V_692 = F_668 ( 0 ) ;
return 0 ;
}
static void F_670 ( struct V_420 * V_559 )
{
struct V_56 * V_57 = V_559 -> V_57 ;
struct V_689 * V_700 =
F_270 ( V_559 ) ;
unsigned V_701 = V_700 -> V_692 ;
F_667 ( V_57 , V_701 ) ;
}
static int F_671 ( struct V_420 * V_43 )
{
struct V_689 * V_329 = F_270 ( V_43 ) ;
struct V_5 * V_6 = F_53 ( V_43 -> V_57 ) ;
const int V_652 = F_487 ( V_43 ) ;
int V_52 = V_329 -> V_1049 ;
int V_633 ;
V_633 = F_444 ( V_652 , V_52 ) ;
if ( V_633 > V_6 -> V_617 ) {
F_125 ( L_167 ,
V_633 , V_6 -> V_617 ) ;
V_633 = V_6 -> V_617 ;
}
V_329 -> V_633 = V_329 -> V_692 = V_633 ;
if ( ! V_329 -> V_693 )
V_329 -> V_692 = F_444 ( 0 , V_52 ) ;
return 0 ;
}
static void F_672 ( struct V_420 * V_559 )
{
struct V_5 * V_6 = F_53 ( V_559 -> V_57 ) ;
struct V_689 * V_329 = F_270 ( V_559 ) ;
unsigned int V_701 = V_329 -> V_692 ;
unsigned int V_1050 = V_329 -> V_1049 ;
F_471 ( V_6 , V_701 , V_1050 ) ;
}
static int F_673 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
if ( ! F_38 ( V_62 , V_228 ) ) {
if ( ! F_674 ( V_65 , V_62 ) )
return - V_537 ;
}
V_65 -> V_804 = false ;
return 0 ;
}
static void F_675 ( struct V_5 * V_6 ,
enum V_183 V_183 ,
struct V_37 * V_38 )
{
enum V_1004 V_372 ;
switch ( V_183 ) {
case V_590 :
V_38 -> V_1051 = V_657 ;
V_372 = V_1052 ;
break;
case V_203 :
V_38 -> V_1051 = V_1053 ;
V_372 = V_1054 ;
break;
case V_205 :
V_38 -> V_1051 = V_1055 ;
V_372 = V_1056 ;
break;
default:
F_125 ( L_168 ) ;
return;
}
V_38 -> V_211 = F_359 ( V_6 , V_372 ) ;
}
static void F_676 ( struct V_5 * V_6 ,
enum V_183 V_183 ,
struct V_37 * V_38 )
{
enum V_1004 V_372 ;
T_1 V_440 ;
V_440 = F_11 ( V_1057 ) & F_677 ( V_183 ) ;
V_38 -> V_1051 = V_440 >> ( V_183 * 3 + 1 ) ;
switch ( V_38 -> V_1051 ) {
case V_657 :
V_372 = V_1052 ;
break;
case V_1053 :
V_372 = V_1054 ;
break;
case V_1055 :
V_372 = V_1056 ;
break;
case V_1058 :
V_372 = V_1059 ;
break;
default:
F_169 ( V_38 -> V_1051 ) ;
return;
}
V_38 -> V_211 = F_359 ( V_6 , V_372 ) ;
}
static void F_678 ( struct V_5 * V_6 ,
enum V_183 V_183 ,
struct V_37 * V_38 )
{
enum V_1004 V_372 ;
V_38 -> V_1051 = F_11 ( F_679 ( V_183 ) ) ;
switch ( V_38 -> V_1051 ) {
case V_1060 :
V_372 = V_1061 ;
break;
case V_1062 :
V_372 = V_1063 ;
break;
case V_1064 :
V_372 = V_1065 ;
break;
case V_1066 :
V_372 = V_1067 ;
break;
case V_1068 :
V_372 = V_1069 ;
break;
case V_1070 :
V_372 = V_1071 ;
break;
default:
F_169 ( V_38 -> V_1051 ) ;
case V_1072 :
return;
}
V_38 -> V_211 = F_359 ( V_6 , V_372 ) ;
}
static bool F_680 ( struct V_81 * V_65 ,
struct V_37 * V_38 ,
unsigned long * V_1073 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_134 V_135 ;
T_1 V_184 ;
V_38 -> V_97 = (enum V_94 ) V_65 -> V_95 ;
V_184 = F_11 ( F_68 ( V_576 ) ) ;
if ( V_184 & V_109 ) {
enum V_95 V_1074 ;
switch ( V_184 & V_1075 ) {
default:
F_7 ( 1 , L_169 ) ;
case V_1076 :
case V_1077 :
V_1074 = V_117 ;
break;
case V_1078 :
V_1074 = V_126 ;
break;
case V_1079 :
V_1074 = V_505 ;
break;
}
if ( V_1074 == V_65 -> V_95 )
V_38 -> V_97 = V_576 ;
}
V_135 = F_82 ( V_38 -> V_97 ) ;
if ( ! F_83 ( V_6 , V_135 ) )
return false ;
* V_1073 |= F_226 ( V_135 ) ;
V_184 = F_11 ( F_59 ( V_38 -> V_97 ) ) ;
return V_184 & V_139 ;
}
static bool F_681 ( struct V_81 * V_65 ,
struct V_37 * V_38 ,
unsigned long * V_1073 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_134 V_135 ;
enum V_183 V_183 ;
enum V_94 V_97 ;
T_1 V_184 ;
F_682 (port, BIT(PORT_A) | BIT(PORT_C)) {
if ( V_183 == V_590 )
V_97 = V_1080 ;
else
V_97 = V_1081 ;
V_135 = F_82 ( V_97 ) ;
if ( ! F_83 ( V_6 , V_135 ) )
continue;
* V_1073 |= F_226 ( V_135 ) ;
if ( ! F_683 ( V_6 ) )
break;
V_184 = F_11 ( F_684 ( V_183 ) ) ;
if ( ! ( V_184 & V_1082 ) )
continue;
V_184 = F_11 ( F_685 ( V_183 ) ) ;
if ( ( V_184 & V_1083 ) != F_686 ( V_65 -> V_95 ) )
continue;
V_38 -> V_97 = V_97 ;
break;
}
return F_408 ( V_38 -> V_97 ) ;
}
static void F_687 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_989 * V_990 ;
enum V_183 V_183 ;
T_2 V_184 ;
V_184 = F_11 ( F_68 ( V_38 -> V_97 ) ) ;
V_183 = ( V_184 & V_1084 ) >> V_1085 ;
if ( F_442 ( V_57 ) || F_443 ( V_57 ) )
F_676 ( V_6 , V_183 , V_38 ) ;
else if ( F_36 ( V_57 ) )
F_675 ( V_6 , V_183 , V_38 ) ;
else
F_678 ( V_6 , V_183 , V_38 ) ;
V_990 = V_38 -> V_211 ;
if ( V_990 ) {
F_28 ( ! V_990 -> V_1008 . V_712 ( V_6 , V_990 ,
& V_38 -> V_179 ) ) ;
}
if ( F_58 ( V_57 ) -> V_103 < 9 &&
( V_183 == V_595 ) && F_11 ( V_226 ) & V_152 ) {
V_38 -> V_229 = true ;
V_184 = F_11 ( F_71 ( V_117 ) ) ;
V_38 -> V_453 = ( ( V_452 & V_184 ) >>
V_1006 ) + 1 ;
F_646 ( V_65 , V_38 ) ;
}
}
static bool F_688 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_134 V_135 ;
unsigned long V_1073 ;
bool V_88 ;
V_135 = F_432 ( V_65 -> V_95 ) ;
if ( ! F_83 ( V_6 , V_135 ) )
return false ;
V_1073 = F_226 ( V_135 ) ;
V_38 -> V_211 = NULL ;
V_88 = F_680 ( V_65 , V_38 , & V_1073 ) ;
if ( F_36 ( V_6 ) &&
F_681 ( V_65 , V_38 , & V_1073 ) ) {
F_28 ( V_88 ) ;
V_88 = true ;
}
if ( ! V_88 )
goto V_934;
if ( ! F_408 ( V_38 -> V_97 ) ) {
F_687 ( V_65 , V_38 ) ;
F_605 ( V_65 , V_38 ) ;
}
F_606 ( V_65 , V_38 ) ;
V_38 -> V_1086 =
F_11 ( F_689 ( V_65 -> V_95 ) ) & V_1087 ;
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
F_690 ( V_57 , V_65 , V_38 ) ;
}
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
V_38 -> V_374 . V_406 = - 1 ;
V_38 -> V_374 . V_528 &= ~ ( 1 << V_538 ) ;
}
V_135 = F_433 ( V_65 -> V_95 ) ;
if ( F_83 ( V_6 , V_135 ) ) {
V_1073 |= F_226 ( V_135 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 9 )
F_647 ( V_65 , V_38 ) ;
else
F_649 ( V_65 , V_38 ) ;
}
if ( F_234 ( V_57 ) )
V_38 -> V_547 = F_405 ( V_65 ) &&
( F_11 ( V_551 ) & V_552 ) ;
if ( V_38 -> V_97 != V_576 &&
! F_408 ( V_38 -> V_97 ) ) {
V_38 -> V_577 =
F_11 ( F_409 ( V_38 -> V_97 ) ) + 1 ;
} else {
V_38 -> V_577 = 1 ;
}
V_934:
F_437 (power_domain, power_domain_mask)
F_84 ( V_6 , V_135 ) ;
return V_88 ;
}
static void F_691 ( struct V_87 * V_65 , T_1 V_64 ,
const struct V_328 * V_326 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
T_2 V_1088 = 0 , V_247 = 0 ;
if ( V_326 && V_326 -> V_331 ) {
unsigned int V_248 = V_326 -> V_64 . V_340 ;
unsigned int V_243 = V_326 -> V_64 . V_341 ;
unsigned int V_319 = F_692 ( V_248 ) * 4 ;
switch ( V_319 ) {
default:
F_324 ( 1 , L_170 ,
V_248 , V_319 ) ;
V_319 = 256 ;
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
}
V_1088 |= V_132 |
V_1089 |
V_1090 |
F_693 ( V_319 ) ;
V_247 = ( V_243 << 12 ) | V_248 ;
}
if ( V_81 -> V_1091 != 0 &&
( V_81 -> V_1092 != V_64 ||
V_81 -> V_1093 != V_247 ||
V_81 -> V_1091 != V_1088 ) ) {
F_122 ( F_80 ( V_117 ) , 0 ) ;
F_123 ( F_80 ( V_117 ) ) ;
V_81 -> V_1091 = 0 ;
}
if ( V_81 -> V_1092 != V_64 ) {
F_122 ( F_694 ( V_117 ) , V_64 ) ;
V_81 -> V_1092 = V_64 ;
}
if ( V_81 -> V_1093 != V_247 ) {
F_122 ( V_1094 , V_247 ) ;
V_81 -> V_1093 = V_247 ;
}
if ( V_81 -> V_1091 != V_1088 ) {
F_122 ( F_80 ( V_117 ) , V_1088 ) ;
F_123 ( F_80 ( V_117 ) ) ;
V_81 -> V_1091 = V_1088 ;
}
}
static void F_695 ( struct V_87 * V_65 , T_1 V_64 ,
const struct V_328 * V_326 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_2 V_1088 = 0 ;
if ( V_326 && V_326 -> V_331 ) {
V_1088 = V_1095 ;
switch ( V_326 -> V_64 . V_340 ) {
case 64 :
V_1088 |= V_1096 ;
break;
case 128 :
V_1088 |= V_1097 ;
break;
case 256 :
V_1088 |= V_1098 ;
break;
default:
F_169 ( V_326 -> V_64 . V_340 ) ;
return;
}
V_1088 |= V_95 << 28 ;
if ( F_23 ( V_57 ) )
V_1088 |= V_1099 ;
if ( V_326 -> V_64 . V_252 == F_226 ( V_361 ) )
V_1088 |= V_1100 ;
}
if ( V_81 -> V_1091 != V_1088 ) {
F_122 ( F_80 ( V_95 ) , V_1088 ) ;
F_123 ( F_80 ( V_95 ) ) ;
V_81 -> V_1091 = V_1088 ;
}
F_122 ( F_694 ( V_95 ) , V_64 ) ;
F_123 ( F_694 ( V_95 ) ) ;
V_81 -> V_1092 = V_64 ;
}
static void F_696 ( struct V_87 * V_65 ,
const struct V_328 * V_326 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_1 V_64 = V_81 -> V_1101 ;
T_1 V_544 = 0 ;
if ( V_326 ) {
int V_274 = V_326 -> V_64 . V_338 ;
int V_275 = V_326 -> V_64 . V_339 ;
if ( V_274 < 0 ) {
V_544 |= V_1102 << V_1103 ;
V_274 = - V_274 ;
}
V_544 |= V_274 << V_1103 ;
if ( V_275 < 0 ) {
V_544 |= V_1102 << V_1104 ;
V_275 = - V_275 ;
}
V_544 |= V_275 << V_1104 ;
if ( F_160 ( V_57 ) &&
V_326 -> V_64 . V_252 == F_226 ( V_361 ) ) {
V_64 += ( V_326 -> V_64 . V_341 *
V_326 -> V_64 . V_340 - 1 ) * 4 ;
}
}
F_122 ( F_697 ( V_95 ) , V_544 ) ;
if ( F_78 ( V_57 ) || F_79 ( V_57 ) )
F_691 ( V_65 , V_64 , V_326 ) ;
else
F_695 ( V_65 , V_64 , V_326 ) ;
}
static bool F_698 ( struct V_56 * V_57 ,
T_2 V_248 , T_2 V_243 )
{
if ( V_248 == 0 || V_243 == 0 )
return false ;
if ( F_78 ( V_57 ) || F_79 ( V_57 ) ) {
if ( ( V_248 & 63 ) != 0 )
return false ;
if ( V_248 > ( F_78 ( V_57 ) ? 64 : 512 ) )
return false ;
if ( V_243 > 1023 )
return false ;
} else {
switch ( V_248 | V_243 ) {
case 256 :
case 128 :
if ( F_55 ( V_57 ) )
return false ;
case 64 :
break;
default:
return false ;
}
}
return true ;
}
struct V_251 *
F_699 ( struct V_56 * V_57 ,
struct V_310 * V_311 ,
struct V_264 * V_265 )
{
struct V_926 * V_927 ;
int V_267 ;
V_927 = F_516 ( sizeof( * V_927 ) , V_717 ) ;
if ( ! V_927 )
return F_700 ( - V_716 ) ;
V_267 = F_207 ( V_57 , V_927 , V_311 , V_265 ) ;
if ( V_267 )
goto V_72;
return & V_927 -> V_64 ;
V_72:
F_215 ( V_927 ) ;
return F_700 ( V_267 ) ;
}
static struct V_251 *
F_701 ( struct V_56 * V_57 ,
struct V_310 * V_311 ,
struct V_264 * V_265 )
{
struct V_251 * V_90 ;
int V_267 ;
V_267 = F_702 ( V_57 ) ;
if ( V_267 )
return F_700 ( V_267 ) ;
V_90 = F_699 ( V_57 , V_311 , V_265 ) ;
F_5 ( & V_57 -> V_268 ) ;
return V_90 ;
}
static T_1
F_703 ( int V_248 , int V_983 )
{
T_1 V_280 = F_181 ( V_248 * V_983 , 8 ) ;
return F_174 ( V_280 , 64 ) ;
}
static T_1
F_704 ( struct V_515 * V_416 , int V_983 )
{
T_1 V_280 = F_703 ( V_416 -> V_885 , V_983 ) ;
return F_705 ( V_280 * V_416 -> V_884 ) ;
}
static struct V_251 *
F_706 ( struct V_56 * V_57 ,
struct V_515 * V_416 ,
int V_1105 , int V_983 )
{
struct V_251 * V_90 ;
struct V_264 * V_265 ;
struct V_310 V_311 = { 0 } ;
V_265 = F_707 ( V_57 ,
F_704 ( V_416 , V_983 ) ) ;
if ( F_278 ( V_265 ) )
return F_708 ( V_265 ) ;
V_311 . V_248 = V_416 -> V_885 ;
V_311 . V_243 = V_416 -> V_884 ;
V_311 . V_260 [ 0 ] = F_703 ( V_311 . V_248 ,
V_983 ) ;
V_311 . V_244 = F_709 ( V_983 , V_1105 ) ;
V_90 = F_701 ( V_57 , & V_311 , V_265 ) ;
if ( F_278 ( V_90 ) )
F_710 ( & V_265 -> V_64 ) ;
return V_90 ;
}
static struct V_251 *
F_711 ( struct V_56 * V_57 ,
struct V_515 * V_416 )
{
#ifdef F_712
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_264 * V_265 ;
struct V_251 * V_90 ;
if ( ! V_6 -> V_1106 )
return NULL ;
if ( ! V_6 -> V_1106 -> V_90 )
return NULL ;
V_265 = V_6 -> V_1106 -> V_90 -> V_265 ;
F_627 ( ! V_265 ) ;
V_90 = & V_6 -> V_1106 -> V_90 -> V_64 ;
if ( V_90 -> V_260 [ 0 ] < F_703 ( V_416 -> V_885 ,
V_90 -> V_786 ) )
return NULL ;
if ( V_265 -> V_64 . V_247 < V_416 -> V_884 * V_90 -> V_260 [ 0 ] )
return NULL ;
F_211 ( V_90 ) ;
return V_90 ;
#else
return NULL ;
#endif
}
static int F_713 ( struct V_420 * V_43 ,
struct V_87 * V_65 ,
struct V_515 * V_416 ,
struct V_251 * V_90 ,
int V_274 , int V_275 )
{
struct V_325 * V_326 ;
int V_885 , V_884 ;
int V_267 ;
V_326 = F_714 ( V_43 , V_65 -> V_89 ) ;
if ( F_278 ( V_326 ) )
return F_279 ( V_326 ) ;
if ( V_416 )
F_715 ( V_416 , & V_885 , & V_884 ) ;
else
V_885 = V_884 = 0 ;
V_267 = F_716 ( V_326 , V_90 ? V_65 : NULL ) ;
if ( V_267 )
return V_267 ;
F_717 ( V_326 , V_90 ) ;
V_326 -> V_338 = 0 ;
V_326 -> V_339 = 0 ;
V_326 -> V_340 = V_885 ;
V_326 -> V_341 = V_884 ;
V_326 -> V_334 = V_274 << 16 ;
V_326 -> V_335 = V_275 << 16 ;
V_326 -> V_336 = V_885 << 16 ;
V_326 -> V_337 = V_884 << 16 ;
return 0 ;
}
bool F_718 ( struct V_1107 * V_711 ,
struct V_515 * V_416 ,
struct V_1108 * V_1109 ,
struct V_423 * V_424 )
{
struct V_81 * V_81 ;
struct V_506 * V_506 =
F_719 ( V_711 ) ;
struct V_87 * V_1110 ;
struct V_608 * V_507 = & V_506 -> V_64 ;
struct V_87 * V_65 = NULL ;
struct V_56 * V_57 = V_507 -> V_57 ;
struct V_251 * V_90 ;
struct V_1111 * V_91 = & V_57 -> V_426 ;
struct V_420 * V_43 = NULL , * V_1112 = NULL ;
struct V_713 * V_1113 ;
struct V_37 * V_62 ;
int V_267 , V_142 = - 1 ;
F_157 ( L_171 ,
V_711 -> V_64 . V_372 , V_711 -> V_12 ,
V_507 -> V_64 . V_372 , V_507 -> V_12 ) ;
V_1109 -> V_1112 = NULL ;
V_458:
V_267 = F_720 ( & V_91 -> V_1114 , V_424 ) ;
if ( V_267 )
goto V_779;
if ( V_711 -> V_43 -> V_65 ) {
V_65 = V_711 -> V_43 -> V_65 ;
V_267 = F_720 ( & V_65 -> V_427 , V_424 ) ;
if ( V_267 )
goto V_779;
goto V_75;
}
F_216 (dev, possible_crtc) {
V_142 ++ ;
if ( ! ( V_507 -> V_1115 & ( 1 << V_142 ) ) )
continue;
V_267 = F_720 ( & V_1110 -> V_427 , V_424 ) ;
if ( V_267 )
goto V_779;
if ( V_1110 -> V_43 -> V_502 ) {
F_721 ( & V_1110 -> V_427 ) ;
continue;
}
V_65 = V_1110 ;
break;
}
if ( ! V_65 ) {
F_157 ( L_172 ) ;
goto V_779;
}
V_75:
V_81 = F_47 ( V_65 ) ;
V_267 = F_720 ( & V_65 -> V_89 -> V_427 , V_424 ) ;
if ( V_267 )
goto V_779;
V_43 = F_722 ( V_57 ) ;
V_1112 = F_722 ( V_57 ) ;
if ( ! V_43 || ! V_1112 ) {
V_267 = - V_716 ;
goto V_779;
}
V_43 -> V_429 = V_424 ;
V_1112 -> V_429 = V_424 ;
V_1113 = F_723 ( V_43 , V_711 ) ;
if ( F_278 ( V_1113 ) ) {
V_267 = F_279 ( V_1113 ) ;
goto V_779;
}
V_267 = F_724 ( V_1113 , V_65 ) ;
if ( V_267 )
goto V_779;
V_62 = F_521 ( V_43 , V_81 ) ;
if ( F_278 ( V_62 ) ) {
V_267 = F_279 ( V_62 ) ;
goto V_779;
}
V_62 -> V_64 . V_88 = V_62 -> V_64 . V_502 = true ;
if ( ! V_416 )
V_416 = & V_1116 ;
V_90 = F_711 ( V_57 , V_416 ) ;
if ( V_90 == NULL ) {
F_157 ( L_173 ) ;
V_90 = F_706 ( V_57 , V_416 , 24 , 32 ) ;
} else
F_157 ( L_174 ) ;
if ( F_278 ( V_90 ) ) {
F_157 ( L_175 ) ;
goto V_779;
}
V_267 = F_713 ( V_43 , V_65 , V_416 , V_90 , 0 , 0 ) ;
if ( V_267 )
goto V_779;
F_210 ( V_90 ) ;
V_267 = F_504 ( & V_62 -> V_64 , V_416 ) ;
if ( V_267 )
goto V_779;
V_267 = F_509 ( F_723 ( V_1112 , V_711 ) ) ;
if ( ! V_267 )
V_267 = F_509 ( F_725 ( V_1112 , V_65 ) ) ;
if ( ! V_267 )
V_267 = F_509 ( F_714 ( V_1112 , V_65 -> V_89 ) ) ;
if ( V_267 ) {
F_157 ( L_176 , V_267 ) ;
goto V_779;
}
V_267 = F_271 ( V_43 ) ;
if ( V_267 ) {
F_157 ( L_177 ) ;
goto V_779;
}
V_1109 -> V_1112 = V_1112 ;
F_315 ( V_57 , V_81 -> V_95 ) ;
return true ;
V_779:
F_281 ( V_43 ) ;
F_281 ( V_1112 ) ;
V_1112 = V_43 = NULL ;
if ( V_267 == - V_271 ) {
F_275 ( V_424 ) ;
goto V_458;
}
return false ;
}
void F_726 ( struct V_1107 * V_711 ,
struct V_1108 * V_1109 ,
struct V_423 * V_424 )
{
struct V_506 * V_506 =
F_719 ( V_711 ) ;
struct V_608 * V_507 = & V_506 -> V_64 ;
struct V_420 * V_43 = V_1109 -> V_1112 ;
int V_267 ;
F_157 ( L_171 ,
V_711 -> V_64 . V_372 , V_711 -> V_12 ,
V_507 -> V_64 . V_372 , V_507 -> V_12 ) ;
if ( ! V_43 )
return;
V_267 = F_271 ( V_43 ) ;
if ( V_267 ) {
F_157 ( L_178 , V_267 ) ;
F_281 ( V_43 ) ;
}
}
static int F_727 ( struct V_56 * V_57 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_45 = V_38 -> V_179 . V_45 ;
if ( ( V_45 & V_946 ) == V_869 )
return V_6 -> V_798 . V_907 ;
else if ( F_15 ( V_57 ) )
return 120000 ;
else if ( ! F_55 ( V_57 ) )
return 96000 ;
else
return 48000 ;
}
static void F_623 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_38 -> V_97 ;
T_1 V_45 = V_38 -> V_179 . V_45 ;
T_1 V_802 ;
struct V_45 clock ;
int V_39 ;
int V_44 = F_727 ( V_57 , V_38 ) ;
if ( ( V_45 & V_1117 ) == 0 )
V_802 = V_38 -> V_179 . V_704 ;
else
V_802 = V_38 -> V_179 . V_705 ;
clock . V_54 = ( V_802 & V_1118 ) >> V_1119 ;
if ( F_19 ( V_57 ) ) {
clock . V_51 = F_728 ( ( V_802 & V_1120 ) >> V_1121 ) - 1 ;
clock . V_47 = ( V_802 & V_1122 ) >> V_1123 ;
} else {
clock . V_51 = ( V_802 & V_1124 ) >> V_1121 ;
clock . V_47 = ( V_802 & V_1125 ) >> V_1123 ;
}
if ( ! F_55 ( V_57 ) ) {
if ( F_19 ( V_57 ) )
clock . V_49 = F_728 ( ( V_45 & V_1126 ) >>
V_859 ) ;
else
clock . V_49 = F_728 ( ( V_45 & V_1127 ) >>
V_860 ) ;
switch ( V_45 & V_1128 ) {
case V_856 :
clock . V_50 = V_45 & V_862 ?
5 : 10 ;
break;
case V_855 :
clock . V_50 = V_45 & V_863 ?
7 : 14 ;
break;
default:
F_157 ( L_179
L_180 , ( int ) ( V_45 & V_1128 ) ) ;
return;
}
if ( F_19 ( V_57 ) )
V_39 = F_27 ( V_44 , & clock ) ;
else
V_39 = F_30 ( V_44 , & clock ) ;
} else {
T_1 V_1129 = F_139 ( V_57 ) ? 0 : F_11 ( V_128 ) ;
bool V_1130 = ( V_95 == 1 ) && ( V_1129 & V_162 ) ;
if ( V_1130 ) {
clock . V_49 = F_728 ( ( V_45 & V_1131 ) >>
V_860 ) ;
if ( V_1129 & V_1132 )
clock . V_50 = 7 ;
else
clock . V_50 = 14 ;
} else {
if ( V_45 & V_871 )
clock . V_49 = 2 ;
else {
clock . V_49 = ( ( V_45 & V_1133 ) >>
V_860 ) + 2 ;
}
if ( V_45 & V_872 )
clock . V_50 = 4 ;
else
clock . V_50 = 2 ;
}
V_39 = F_30 ( V_44 , & clock ) ;
}
V_38 -> V_39 = V_39 ;
}
int F_729 ( int V_1134 ,
const struct V_790 * V_791 )
{
if ( ! V_791 -> V_796 )
return 0 ;
return F_45 ( ( T_4 ) V_791 -> V_795 * V_1134 , V_791 -> V_796 ) ;
}
static void F_653 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
F_623 ( V_65 , V_38 ) ;
V_38 -> V_64 . V_92 . V_93 =
F_729 ( F_22 ( V_6 , V_38 ) ,
& V_38 -> V_572 ) ;
}
struct V_515 * F_730 ( struct V_56 * V_57 ,
struct V_87 * V_65 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
enum V_94 V_97 = V_81 -> V_91 -> V_97 ;
struct V_515 * V_416 ;
struct V_37 * V_38 ;
int V_1135 = F_11 ( F_336 ( V_97 ) ) ;
int V_893 = F_11 ( F_340 ( V_97 ) ) ;
int V_1136 = F_11 ( F_342 ( V_97 ) ) ;
int V_1137 = F_11 ( F_346 ( V_97 ) ) ;
enum V_95 V_95 = V_81 -> V_95 ;
V_416 = F_516 ( sizeof( * V_416 ) , V_717 ) ;
if ( ! V_416 )
return NULL ;
V_38 = F_516 ( sizeof( * V_38 ) , V_717 ) ;
if ( ! V_38 ) {
F_215 ( V_416 ) ;
return NULL ;
}
V_38 -> V_97 = (enum V_94 ) V_95 ;
V_38 -> V_577 = 1 ;
V_38 -> V_179 . V_45 = F_11 ( F_63 ( V_95 ) ) ;
V_38 -> V_179 . V_704 = F_11 ( F_498 ( V_95 ) ) ;
V_38 -> V_179 . V_705 = F_11 ( F_499 ( V_95 ) ) ;
F_623 ( V_81 , V_38 ) ;
V_416 -> clock = V_38 -> V_39 / V_38 -> V_577 ;
V_416 -> V_885 = ( V_1135 & 0xffff ) + 1 ;
V_416 -> V_886 = ( ( V_1135 & 0xffff0000 ) >> 16 ) + 1 ;
V_416 -> V_887 = ( V_893 & 0xffff ) + 1 ;
V_416 -> V_888 = ( ( V_893 & 0xffff0000 ) >> 16 ) + 1 ;
V_416 -> V_884 = ( V_1136 & 0xffff ) + 1 ;
V_416 -> V_889 = ( ( V_1136 & 0xffff0000 ) >> 16 ) + 1 ;
V_416 -> V_890 = ( V_1137 & 0xffff ) + 1 ;
V_416 -> V_891 = ( ( V_1137 & 0xffff0000 ) >> 16 ) + 1 ;
F_610 ( V_416 ) ;
F_215 ( V_38 ) ;
return V_416 ;
}
static void F_731 ( struct V_87 * V_65 )
{
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_1 * V_2 ;
F_286 ( & V_57 -> V_436 ) ;
V_2 = V_81 -> V_437 ;
V_81 -> V_437 = NULL ;
F_287 ( & V_57 -> V_436 ) ;
if ( V_2 ) {
F_732 ( & V_2 -> V_3 ) ;
F_732 ( & V_2 -> V_477 ) ;
F_215 ( V_2 ) ;
}
F_733 ( V_65 ) ;
F_215 ( V_81 ) ;
}
static void F_734 ( struct V_1138 * V_1139 )
{
struct V_1 * V_2 =
F_735 ( V_1139 , struct V_1 , V_477 ) ;
struct V_81 * V_65 = F_47 ( V_2 -> V_65 ) ;
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_323 * V_89 = V_65 -> V_64 . V_89 ;
if ( F_1 ( V_2 ) )
F_736 ( & V_2 -> V_3 ) ;
F_3 ( & V_57 -> V_268 ) ;
F_196 ( V_2 -> V_1140 , V_89 -> V_43 -> V_252 ) ;
F_208 ( & V_2 -> V_478 -> V_64 ) ;
if ( V_2 -> V_1141 )
F_737 ( & V_2 -> V_1141 , NULL ) ;
F_5 ( & V_57 -> V_268 ) ;
F_738 ( V_57 , F_213 ( V_89 ) -> V_350 ) ;
F_388 ( V_65 ) ;
F_210 ( V_2 -> V_1140 ) ;
F_627 ( F_314 ( & V_65 -> V_473 ) == 0 ) ;
F_739 ( & V_65 -> V_473 ) ;
F_215 ( V_2 ) ;
}
static bool F_740 ( T_1 V_1142 , T_1 V_1143 )
{
return ! ( ( V_1142 - V_1143 ) & 0x80000000 ) ;
}
static bool F_741 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
unsigned V_433 ;
V_433 = F_292 ( & V_6 -> V_435 ) ;
if ( V_65 -> V_433 != V_433 )
return true ;
if ( F_58 ( V_57 ) -> V_103 < 5 && ! F_18 ( V_57 ) )
return true ;
return ( F_11 ( F_742 ( V_65 -> V_140 ) ) & ~ 0xfff ) ==
V_65 -> V_437 -> V_1144 &&
F_740 ( F_11 ( F_743 ( V_65 -> V_95 ) ) ,
V_65 -> V_437 -> V_1145 ) ;
}
static bool
F_744 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
return F_745 ( V_65 ) != V_2 -> V_1146 ;
}
static bool F_746 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
if ( ! F_314 ( & V_2 -> V_434 ) )
return false ;
F_747 () ;
if ( F_1 ( V_2 ) )
return F_744 ( V_65 , V_2 ) ;
else
return F_741 ( V_65 , V_2 ) ;
}
void F_263 ( struct V_5 * V_6 , int V_95 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
struct V_87 * V_65 = V_6 -> V_96 [ V_95 ] ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_1 * V_2 ;
unsigned long V_320 ;
if ( ! V_65 )
return;
F_748 ( & V_57 -> V_436 , V_320 ) ;
V_2 = V_81 -> V_437 ;
if ( V_2 != NULL &&
! F_1 ( V_2 ) &&
F_746 ( V_81 , V_2 ) )
F_316 ( V_81 ) ;
F_749 ( & V_57 -> V_436 , V_320 ) ;
}
void F_750 ( struct V_5 * V_6 , int V_95 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
struct V_87 * V_65 = V_6 -> V_96 [ V_95 ] ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_1 * V_2 ;
unsigned long V_320 ;
if ( ! V_65 )
return;
F_748 ( & V_57 -> V_436 , V_320 ) ;
V_2 = V_81 -> V_437 ;
if ( V_2 != NULL &&
F_1 ( V_2 ) &&
F_746 ( V_81 , V_2 ) )
F_316 ( V_81 ) ;
F_749 ( & V_57 -> V_436 , V_320 ) ;
}
static inline void F_751 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
V_2 -> V_1146 = F_745 ( V_65 ) ;
F_752 () ;
F_753 ( & V_2 -> V_434 , 1 ) ;
}
static int F_754 ( struct V_56 * V_57 ,
struct V_87 * V_65 ,
struct V_251 * V_90 ,
struct V_264 * V_265 ,
struct V_1147 * V_1148 ,
T_2 V_320 )
{
struct V_1149 * V_1150 = V_1148 -> V_1150 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
T_1 V_1151 ;
int V_267 ;
V_267 = F_755 ( V_1148 , 6 ) ;
if ( V_267 )
return V_267 ;
if ( V_81 -> V_140 )
V_1151 = V_1152 ;
else
V_1151 = V_1153 ;
F_756 ( V_1150 , V_1154 | V_1151 ) ;
F_756 ( V_1150 , V_1155 ) ;
F_756 ( V_1150 , V_1156 |
F_757 ( V_81 -> V_140 ) ) ;
F_756 ( V_1150 , V_90 -> V_260 [ 0 ] ) ;
F_756 ( V_1150 , V_81 -> V_437 -> V_1144 ) ;
F_756 ( V_1150 , 0 ) ;
return 0 ;
}
static int F_758 ( struct V_56 * V_57 ,
struct V_87 * V_65 ,
struct V_251 * V_90 ,
struct V_264 * V_265 ,
struct V_1147 * V_1148 ,
T_2 V_320 )
{
struct V_1149 * V_1150 = V_1148 -> V_1150 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
T_1 V_1151 ;
int V_267 ;
V_267 = F_755 ( V_1148 , 6 ) ;
if ( V_267 )
return V_267 ;
if ( V_81 -> V_140 )
V_1151 = V_1152 ;
else
V_1151 = V_1153 ;
F_756 ( V_1150 , V_1154 | V_1151 ) ;
F_756 ( V_1150 , V_1155 ) ;
F_756 ( V_1150 , V_1157 |
F_757 ( V_81 -> V_140 ) ) ;
F_756 ( V_1150 , V_90 -> V_260 [ 0 ] ) ;
F_756 ( V_1150 , V_81 -> V_437 -> V_1144 ) ;
F_756 ( V_1150 , V_1155 ) ;
return 0 ;
}
static int F_759 ( struct V_56 * V_57 ,
struct V_87 * V_65 ,
struct V_251 * V_90 ,
struct V_264 * V_265 ,
struct V_1147 * V_1148 ,
T_2 V_320 )
{
struct V_1149 * V_1150 = V_1148 -> V_1150 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
T_2 V_1158 , V_1159 ;
int V_267 ;
V_267 = F_755 ( V_1148 , 4 ) ;
if ( V_267 )
return V_267 ;
F_756 ( V_1150 , V_1156 |
F_757 ( V_81 -> V_140 ) ) ;
F_756 ( V_1150 , V_90 -> V_260 [ 0 ] ) ;
F_756 ( V_1150 , V_81 -> V_437 -> V_1144 |
V_265 -> V_316 ) ;
V_1158 = 0 ;
V_1159 = F_11 ( F_294 ( V_81 -> V_95 ) ) & 0x0fff0fff ;
F_756 ( V_1150 , V_1158 | V_1159 ) ;
return 0 ;
}
static int F_760 ( struct V_56 * V_57 ,
struct V_87 * V_65 ,
struct V_251 * V_90 ,
struct V_264 * V_265 ,
struct V_1147 * V_1148 ,
T_2 V_320 )
{
struct V_1149 * V_1150 = V_1148 -> V_1150 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
T_2 V_1158 , V_1159 ;
int V_267 ;
V_267 = F_755 ( V_1148 , 4 ) ;
if ( V_267 )
return V_267 ;
F_756 ( V_1150 , V_1156 |
F_757 ( V_81 -> V_140 ) ) ;
F_756 ( V_1150 , V_90 -> V_260 [ 0 ] | V_265 -> V_316 ) ;
F_756 ( V_1150 , V_81 -> V_437 -> V_1144 ) ;
V_1158 = 0 ;
V_1159 = F_11 ( F_294 ( V_81 -> V_95 ) ) & 0x0fff0fff ;
F_756 ( V_1150 , V_1158 | V_1159 ) ;
return 0 ;
}
static int F_761 ( struct V_56 * V_57 ,
struct V_87 * V_65 ,
struct V_251 * V_90 ,
struct V_264 * V_265 ,
struct V_1147 * V_1148 ,
T_2 V_320 )
{
struct V_1149 * V_1150 = V_1148 -> V_1150 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
T_2 V_1160 = 0 ;
int V_1161 , V_267 ;
switch ( V_81 -> V_140 ) {
case V_1162 :
V_1160 = V_1163 ;
break;
case V_357 :
V_1160 = V_1164 ;
break;
case V_1165 :
V_1160 = V_1166 ;
break;
default:
F_324 ( 1 , L_181 ) ;
return - V_418 ;
}
V_1161 = 4 ;
if ( V_1150 -> V_372 == V_1167 ) {
V_1161 += 6 ;
if ( F_762 ( V_57 ) )
V_1161 += 2 ;
}
V_267 = F_763 ( V_1148 ) ;
if ( V_267 )
return V_267 ;
V_267 = F_755 ( V_1148 , V_1161 ) ;
if ( V_267 )
return V_267 ;
if ( V_1150 -> V_372 == V_1167 ) {
F_756 ( V_1150 , F_764 ( 1 ) ) ;
F_765 ( V_1150 , V_1168 ) ;
F_756 ( V_1150 , ~ ( V_1169 |
V_1170 |
V_1171 ) ) ;
if ( F_762 ( V_57 ) )
F_756 ( V_1150 , V_1172 |
V_1173 ) ;
else
F_756 ( V_1150 , V_1174 |
V_1173 ) ;
F_765 ( V_1150 , V_1168 ) ;
F_756 ( V_1150 , V_1150 -> V_1175 . V_1144 + 256 ) ;
if ( F_762 ( V_57 ) ) {
F_756 ( V_1150 , 0 ) ;
F_756 ( V_1150 , V_1155 ) ;
}
}
F_756 ( V_1150 , V_1157 | V_1160 ) ;
F_756 ( V_1150 , ( V_90 -> V_260 [ 0 ] | V_265 -> V_316 ) ) ;
F_756 ( V_1150 , V_81 -> V_437 -> V_1144 ) ;
F_756 ( V_1150 , ( V_1155 ) ) ;
return 0 ;
}
static bool F_766 ( struct V_1149 * V_1150 ,
struct V_264 * V_265 )
{
struct V_1176 * V_1177 ;
if ( V_1150 == NULL )
return true ;
if ( F_276 ( V_1150 -> V_728 ) < 5 )
return false ;
if ( V_728 . F_766 < 0 )
return false ;
else if ( V_728 . F_766 > 0 )
return true ;
else if ( V_728 . V_1178 )
return true ;
V_1177 = F_767 ( V_265 ) ;
if ( V_1177 && ! F_768 ( V_1177 , false ) )
return true ;
return V_1150 != F_769 ( V_265 -> V_1179 ) ;
}
static void F_770 ( struct V_81 * V_81 ,
unsigned int V_252 ,
struct V_1 * V_2 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_251 * V_90 = V_81 -> V_64 . V_89 -> V_90 ;
const enum V_95 V_95 = V_81 -> V_95 ;
T_1 V_1180 , V_319 , V_241 ;
V_1180 = F_11 ( F_92 ( V_95 , 0 ) ) ;
V_1180 &= ~ V_1001 ;
switch ( V_90 -> V_259 [ 0 ] ) {
case V_236 :
break;
case V_237 :
V_1180 |= V_390 ;
break;
case V_238 :
V_1180 |= V_391 ;
break;
case V_239 :
V_1180 |= V_392 ;
break;
default:
F_169 ( V_90 -> V_259 [ 0 ] ) ;
}
if ( F_178 ( V_252 ) ) {
V_241 = F_170 ( V_6 , V_90 -> V_259 [ 0 ] , 0 ) ;
V_319 = F_181 ( V_90 -> V_243 , V_241 ) ;
} else {
V_319 = V_90 -> V_260 [ 0 ] /
F_237 ( V_6 , V_90 -> V_259 [ 0 ] ,
V_90 -> V_244 ) ;
}
F_122 ( F_92 ( V_95 , 0 ) , V_1180 ) ;
F_122 ( F_255 ( V_95 , 0 ) , V_319 ) ;
F_122 ( F_259 ( V_95 , 0 ) , V_2 -> V_1144 ) ;
F_123 ( F_259 ( V_95 , 0 ) ) ;
}
static void F_771 ( struct V_81 * V_81 ,
struct V_1 * V_2 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_926 * V_927 =
F_179 ( V_81 -> V_64 . V_89 -> V_90 ) ;
struct V_264 * V_265 = V_927 -> V_265 ;
T_3 V_13 = F_86 ( V_81 -> V_140 ) ;
T_1 V_352 ;
V_352 = F_11 ( V_13 ) ;
if ( V_265 -> V_316 != V_347 )
V_352 |= V_358 ;
else
V_352 &= ~ V_358 ;
F_122 ( V_13 , V_352 ) ;
F_122 ( F_228 ( V_81 -> V_140 ) , V_2 -> V_1144 ) ;
F_123 ( F_228 ( V_81 -> V_140 ) ) ;
}
static void F_772 ( struct V_1138 * V_1181 )
{
struct V_1 * V_2 =
F_735 ( V_1181 , struct V_1 , V_3 ) ;
struct V_81 * V_65 = F_47 ( V_2 -> V_65 ) ;
struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
struct V_926 * V_927 =
F_179 ( V_65 -> V_64 . V_89 -> V_90 ) ;
struct V_264 * V_265 = V_927 -> V_265 ;
struct V_1176 * V_1177 ;
if ( V_2 -> V_1141 )
F_28 ( F_773 ( V_2 -> V_1141 ,
false , NULL ,
& V_6 -> V_548 . V_1182 ) ) ;
V_1177 = F_767 ( V_265 ) ;
if ( V_1177 )
F_28 ( F_774 ( V_1177 , false , false ,
V_1183 ) < 0 ) ;
F_775 ( V_65 ) ;
if ( F_276 ( V_6 ) >= 9 )
F_770 ( V_65 , V_2 -> V_252 , V_2 ) ;
else
F_771 ( V_65 , V_2 ) ;
F_776 ( V_65 , V_2 ) ;
}
static int F_777 ( struct V_56 * V_57 ,
struct V_87 * V_65 ,
struct V_251 * V_90 ,
struct V_264 * V_265 ,
struct V_1147 * V_1148 ,
T_2 V_320 )
{
return - V_418 ;
}
static bool F_778 ( struct V_5 * V_6 ,
struct V_81 * V_81 ,
struct V_1 * V_2 )
{
T_1 V_1184 , V_1185 ;
if ( ! F_314 ( & V_2 -> V_434 ) )
return false ;
F_747 () ;
V_1185 = F_745 ( V_81 ) ;
if ( V_2 -> V_1186 == 0 ) {
if ( V_2 -> V_1141 &&
! F_779 ( V_2 -> V_1141 ) )
return false ;
V_2 -> V_1186 = V_1185 ;
}
if ( V_1185 - V_2 -> V_1186 < 3 )
return false ;
if ( F_276 ( V_6 ) >= 4 )
V_1184 = F_780 ( F_11 ( F_228 ( V_81 -> V_140 ) ) ) ;
else
V_1184 = F_11 ( F_231 ( V_81 -> V_140 ) ) ;
return V_1184 == V_2 -> V_1144 ;
}
void F_781 ( struct V_5 * V_6 , int V_95 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
struct V_87 * V_65 = V_6 -> V_96 [ V_95 ] ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_1 * V_2 ;
F_28 ( ! F_782 () ) ;
if ( V_65 == NULL )
return;
F_783 ( & V_57 -> V_436 ) ;
V_2 = V_81 -> V_437 ;
if ( V_2 != NULL && ! F_1 ( V_2 ) &&
F_778 ( V_6 , V_81 , V_2 ) ) {
F_324 ( 1 ,
L_182 ,
V_2 -> V_1146 , F_745 ( V_81 ) ) ;
F_316 ( V_81 ) ;
V_2 = NULL ;
}
if ( V_2 != NULL && ! F_1 ( V_2 ) &&
F_745 ( V_81 ) - V_2 -> V_1146 > 1 )
F_784 ( V_2 -> V_1141 ) ;
F_785 ( & V_57 -> V_436 ) ;
}
static int F_786 ( struct V_87 * V_65 ,
struct V_251 * V_90 ,
struct V_1187 * V_474 ,
T_2 V_1188 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_251 * V_1140 = V_65 -> V_89 -> V_90 ;
struct V_264 * V_265 = F_187 ( V_90 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_323 * V_89 = V_65 -> V_89 ;
enum V_95 V_95 = V_81 -> V_95 ;
struct V_1 * V_2 ;
struct V_1149 * V_1150 ;
bool V_1189 ;
struct V_1147 * V_1190 = NULL ;
int V_267 ;
if ( F_28 ( F_187 ( V_1140 ) == NULL ) )
return - V_272 ;
if ( V_90 -> V_244 != V_65 -> V_89 -> V_90 -> V_244 )
return - V_537 ;
if ( F_58 ( V_57 ) -> V_103 > 3 &&
( V_90 -> V_263 [ 0 ] != V_65 -> V_89 -> V_90 -> V_263 [ 0 ] ||
V_90 -> V_260 [ 0 ] != V_65 -> V_89 -> V_90 -> V_260 [ 0 ] ) )
return - V_537 ;
if ( F_787 ( & V_6 -> V_435 ) )
goto V_1191;
V_2 = F_516 ( sizeof( * V_2 ) , V_717 ) ;
if ( V_2 == NULL )
return - V_716 ;
V_2 -> V_474 = V_474 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_1140 = V_1140 ;
F_788 ( & V_2 -> V_477 , F_734 ) ;
V_267 = F_99 ( V_65 ) ;
if ( V_267 )
goto V_1192;
F_286 ( & V_57 -> V_436 ) ;
if ( V_81 -> V_437 ) {
if ( F_746 ( V_81 , V_81 -> V_437 ) ) {
F_20 ( L_183 ) ;
F_316 ( V_81 ) ;
} else {
F_20 ( L_184 ) ;
F_287 ( & V_57 -> V_436 ) ;
F_100 ( V_65 ) ;
F_215 ( V_2 ) ;
return - V_272 ;
}
}
V_81 -> V_437 = V_2 ;
F_287 ( & V_57 -> V_436 ) ;
if ( F_314 ( & V_81 -> V_473 ) >= 2 )
F_789 ( V_6 -> V_476 ) ;
F_211 ( V_2 -> V_1140 ) ;
F_790 ( & V_265 -> V_64 ) ;
V_65 -> V_89 -> V_90 = V_90 ;
F_209 ( V_65 -> V_89 ) ;
F_390 ( V_81 , V_81 -> V_91 ,
F_214 ( V_89 -> V_43 ) ) ;
V_2 -> V_478 = V_265 ;
V_267 = F_702 ( V_57 ) ;
if ( V_267 )
goto V_1193;
V_81 -> V_433 = F_292 ( & V_6 -> V_435 ) ;
if ( F_791 ( V_81 -> V_433 ) ) {
V_267 = - V_1194 ;
goto V_1193;
}
F_792 ( & V_81 -> V_473 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 5 || F_18 ( V_57 ) )
V_2 -> V_1145 = F_11 ( F_743 ( V_95 ) ) + 1 ;
if ( F_16 ( V_57 ) || F_17 ( V_57 ) ) {
V_1150 = & V_6 -> V_1150 [ V_1195 ] ;
if ( V_265 -> V_316 != F_187 ( V_2 -> V_1140 ) -> V_316 )
V_1150 = NULL ;
} else if ( F_299 ( V_57 ) || F_234 ( V_57 ) ) {
V_1150 = & V_6 -> V_1150 [ V_1195 ] ;
} else if ( F_58 ( V_57 ) -> V_103 >= 7 ) {
V_1150 = F_769 ( V_265 -> V_1179 ) ;
if ( V_1150 == NULL || V_1150 -> V_372 != V_1167 )
V_1150 = & V_6 -> V_1150 [ V_1195 ] ;
} else {
V_1150 = & V_6 -> V_1150 [ V_1167 ] ;
}
V_1189 = F_766 ( V_1150 , V_265 ) ;
if ( ! V_1189 ) {
V_267 = F_793 ( V_265 , V_1150 , & V_1190 ) ;
if ( ! V_267 && ! V_1190 ) {
V_1190 = F_794 ( V_1150 , NULL ) ;
V_267 = F_509 ( V_1190 ) ;
}
if ( V_267 )
goto V_1196;
}
V_267 = F_186 ( V_90 , V_89 -> V_43 -> V_252 ) ;
if ( V_267 )
goto V_1196;
V_2 -> V_1144 = F_238 ( F_213 ( V_89 ) ,
V_265 , 0 ) ;
V_2 -> V_1144 += V_81 -> V_360 ;
V_2 -> V_252 = V_65 -> V_89 -> V_43 -> V_252 ;
if ( V_1189 ) {
F_788 ( & V_2 -> V_3 , F_772 ) ;
F_737 ( & V_2 -> V_1141 ,
V_265 -> V_1179 ) ;
F_795 ( & V_2 -> V_3 ) ;
} else {
F_737 ( & V_2 -> V_1141 , V_1190 ) ;
V_267 = V_6 -> V_431 . V_1197 ( V_57 , V_65 , V_90 , V_265 , V_1190 ,
V_1188 ) ;
if ( V_267 )
goto V_1198;
F_751 ( V_81 , V_2 ) ;
F_796 ( V_1190 ) ;
}
F_797 ( F_187 ( V_1140 ) , V_265 ,
F_213 ( V_89 ) -> V_350 ) ;
F_5 ( & V_57 -> V_268 ) ;
F_798 ( V_57 ,
F_213 ( V_89 ) -> V_350 ) ;
F_799 ( V_81 -> V_140 , V_265 ) ;
return 0 ;
V_1198:
F_196 ( V_90 , V_65 -> V_89 -> V_43 -> V_252 ) ;
V_1196:
if ( ! F_800 ( V_1190 ) )
F_796 ( V_1190 ) ;
F_739 ( & V_81 -> V_473 ) ;
F_5 ( & V_57 -> V_268 ) ;
V_1193:
V_65 -> V_89 -> V_90 = V_1140 ;
F_209 ( V_65 -> V_89 ) ;
F_710 ( & V_265 -> V_64 ) ;
F_210 ( V_2 -> V_1140 ) ;
F_286 ( & V_57 -> V_436 ) ;
V_81 -> V_437 = NULL ;
F_287 ( & V_57 -> V_436 ) ;
F_100 ( V_65 ) ;
V_1192:
F_215 ( V_2 ) ;
if ( V_267 == - V_1194 ) {
struct V_420 * V_43 ;
struct V_325 * V_326 ;
V_1191:
V_43 = F_722 ( V_57 ) ;
if ( ! V_43 )
return - V_716 ;
V_43 -> V_429 = F_801 ( V_65 ) ;
V_458:
V_326 = F_714 ( V_43 , V_89 ) ;
V_267 = F_509 ( V_326 ) ;
if ( ! V_267 ) {
F_717 ( V_326 , V_90 ) ;
V_267 = F_716 ( V_326 , V_65 ) ;
if ( ! V_267 )
V_267 = F_271 ( V_43 ) ;
}
if ( V_267 == - V_271 ) {
F_275 ( V_43 -> V_429 ) ;
F_802 ( V_43 ) ;
goto V_458;
}
if ( V_267 )
F_281 ( V_43 ) ;
if ( V_267 == 0 && V_474 ) {
F_286 ( & V_57 -> V_436 ) ;
F_317 ( V_65 , V_474 ) ;
F_287 ( & V_57 -> V_436 ) ;
}
}
return V_267 ;
}
static bool F_803 ( struct V_323 * V_140 ,
struct V_325 * V_43 )
{
struct V_328 * V_1199 = F_214 ( V_43 ) ;
struct V_328 * V_1200 = F_214 ( V_140 -> V_43 ) ;
if ( V_1199 -> V_331 != V_1200 -> V_331 )
return true ;
if ( ! V_1200 -> V_64 . V_90 || ! V_1199 -> V_64 . V_90 )
return false ;
if ( V_1200 -> V_64 . V_90 -> V_259 [ 0 ] != V_1199 -> V_64 . V_90 -> V_259 [ 0 ] ||
V_1200 -> V_64 . V_252 != V_1199 -> V_64 . V_252 ||
F_251 ( & V_1199 -> V_342 ) != F_251 ( & V_1200 -> V_342 ) ||
F_252 ( & V_1199 -> V_342 ) != F_252 ( & V_1200 -> V_342 ) ||
F_251 ( & V_1199 -> V_346 ) != F_251 ( & V_1200 -> V_346 ) ||
F_252 ( & V_1199 -> V_346 ) != F_252 ( & V_1200 -> V_346 ) )
return true ;
return false ;
}
static bool F_804 ( struct V_328 * V_43 )
{
int V_336 = F_251 ( & V_43 -> V_342 ) >> 16 ;
int V_337 = F_252 ( & V_43 -> V_342 ) >> 16 ;
int V_409 = F_251 ( & V_43 -> V_346 ) ;
int V_410 = F_252 ( & V_43 -> V_346 ) ;
return ( V_336 != V_409 || V_337 != V_410 ) ;
}
int F_805 ( struct V_42 * V_62 ,
struct V_325 * V_326 )
{
struct V_37 * V_38 = F_265 ( V_62 ) ;
struct V_87 * V_65 = V_62 -> V_65 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_323 * V_140 = V_326 -> V_140 ;
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_328 * V_1201 =
F_214 ( V_140 -> V_43 ) ;
bool V_421 = F_25 ( V_62 ) ;
bool V_1202 = V_65 -> V_43 -> V_88 ;
bool V_1203 = V_62 -> V_88 ;
bool V_1204 , V_1205 , V_331 , V_1206 ;
struct V_251 * V_90 = V_326 -> V_90 ;
int V_267 ;
if ( F_276 ( V_57 ) >= 9 && V_140 -> type != V_1207 ) {
V_267 = F_366 (
F_265 ( V_62 ) ,
F_214 ( V_326 ) ) ;
if ( V_267 )
return V_267 ;
}
V_1206 = V_1201 -> V_331 ;
V_331 = F_214 ( V_326 ) -> V_331 ;
if ( ! V_1202 && F_28 ( V_1206 ) )
V_1206 = false ;
if ( ! V_1203 )
F_214 ( V_326 ) -> V_331 = V_331 = false ;
if ( ! V_1206 && ! V_331 )
return 0 ;
if ( V_90 != V_1201 -> V_64 . V_90 )
V_38 -> V_1208 = true ;
V_1204 = V_1206 && ( ! V_331 || V_421 ) ;
V_1205 = V_331 && ( ! V_1206 || V_421 ) ;
F_806 ( L_185 ,
V_81 -> V_64 . V_64 . V_372 ,
V_81 -> V_64 . V_12 ,
V_140 -> V_64 . V_372 , V_140 -> V_12 ,
V_90 ? V_90 -> V_64 . V_372 : - 1 ) ;
F_806 ( L_186 ,
V_140 -> V_64 . V_372 , V_140 -> V_12 ,
V_1206 , V_331 ,
V_1204 , V_1205 , V_421 ) ;
if ( V_1205 ) {
V_38 -> V_570 = true ;
if ( V_140 -> type != V_1207 )
V_38 -> V_567 = true ;
} else if ( V_1204 ) {
V_38 -> V_563 = true ;
if ( V_140 -> type != V_1207 )
V_38 -> V_567 = true ;
} else if ( F_803 ( V_140 , V_326 ) ) {
V_38 -> V_570 = true ;
V_38 -> V_563 = true ;
}
if ( ( V_38 -> V_570 || V_38 -> V_563 ) &&
F_58 ( V_57 ) -> V_103 < 9 && V_6 -> V_431 . V_1209 )
F_265 ( V_62 ) -> V_556 . V_1210 = true ;
if ( V_331 || V_1206 )
V_38 -> V_561 |= F_213 ( V_140 ) -> V_350 ;
if ( V_140 -> type == V_1211 && F_299 ( V_57 ) &&
F_804 ( F_214 ( V_326 ) ) &&
! F_804 ( V_1201 ) )
V_38 -> V_568 = true ;
return 0 ;
}
static bool F_807 ( const struct V_506 * V_1142 ,
const struct V_506 * V_1143 )
{
return V_1142 == V_1143 || ( V_1142 -> V_1212 & ( 1 << V_1143 -> type ) &&
V_1143 -> V_1212 & ( 1 << V_1142 -> type ) ) ;
}
static bool F_808 ( struct V_420 * V_43 ,
struct V_81 * V_65 ,
struct V_506 * V_507 )
{
struct V_506 * V_1213 ;
struct V_1107 * V_711 ;
struct V_713 * V_1113 ;
int V_142 ;
F_809 (state, connector, connector_state, i) {
if ( V_1113 -> V_65 != & V_65 -> V_64 )
continue;
V_1213 =
F_435 ( V_1113 -> V_715 ) ;
if ( ! F_807 ( V_507 , V_1213 ) )
return false ;
}
return true ;
}
static int F_810 ( struct V_87 * V_65 ,
struct V_42 * V_62 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_37 * V_38 =
F_265 ( V_62 ) ;
struct V_420 * V_43 = V_62 -> V_43 ;
int V_267 ;
bool V_421 = F_25 ( V_62 ) ;
if ( V_421 && ! V_62 -> V_88 )
V_38 -> V_563 = true ;
if ( V_421 && V_62 -> V_502 &&
V_6 -> V_431 . V_1214 &&
! F_28 ( V_38 -> V_211 ) ) {
V_267 = V_6 -> V_431 . V_1214 ( V_81 ,
V_38 ) ;
if ( V_267 )
return V_267 ;
}
if ( V_62 -> V_1215 ) {
V_267 = F_811 ( V_65 , V_62 ) ;
if ( V_267 )
return V_267 ;
V_62 -> V_1216 = true ;
}
V_267 = 0 ;
if ( V_6 -> V_431 . V_1217 ) {
V_267 = V_6 -> V_431 . V_1217 ( V_38 ) ;
if ( V_267 ) {
F_157 ( L_187 ) ;
return V_267 ;
}
}
if ( V_6 -> V_431 . V_1218 &&
! F_270 ( V_43 ) -> V_422 ) {
if ( F_28 ( ! V_6 -> V_431 . V_1217 ) )
return 0 ;
V_267 = V_6 -> V_431 . V_1218 ( V_65 -> V_57 ,
V_81 ,
V_38 ) ;
if ( V_267 ) {
F_157 ( L_188 ) ;
return V_267 ;
}
} else if ( V_6 -> V_431 . V_1218 ) {
if ( F_15 ( V_6 ) && F_276 ( V_6 ) < 9 )
V_38 -> V_556 . V_1219 . V_1220 = V_38 -> V_556 . V_1219 . V_1221 ;
}
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
if ( V_421 )
V_267 = F_365 ( V_38 ) ;
if ( ! V_267 )
V_267 = F_812 ( V_57 , V_81 ,
V_38 ) ;
}
return V_267 ;
}
static void F_813 ( struct V_56 * V_57 )
{
struct V_710 * V_711 ;
F_814 (dev, connector) {
if ( V_711 -> V_64 . V_43 -> V_65 )
F_815 ( & V_711 -> V_64 ) ;
if ( V_711 -> V_64 . V_507 ) {
V_711 -> V_64 . V_43 -> V_715 =
V_711 -> V_64 . V_507 ;
V_711 -> V_64 . V_43 -> V_65 =
V_711 -> V_64 . V_507 -> V_65 ;
F_816 ( & V_711 -> V_64 ) ;
} else {
V_711 -> V_64 . V_43 -> V_715 = NULL ;
V_711 -> V_64 . V_43 -> V_65 = NULL ;
}
}
}
static void
F_817 ( struct V_710 * V_711 ,
struct V_37 * V_38 )
{
int V_983 = V_38 -> V_725 ;
F_157 ( L_189 ,
V_711 -> V_64 . V_64 . V_372 ,
V_711 -> V_64 . V_12 ) ;
if ( V_711 -> V_64 . V_1222 . V_516 &&
V_711 -> V_64 . V_1222 . V_516 * 3 < V_983 ) {
F_157 ( L_190 ,
V_983 , V_711 -> V_64 . V_1222 . V_516 * 3 ) ;
V_38 -> V_725 = V_711 -> V_64 . V_1222 . V_516 * 3 ;
}
if ( V_711 -> V_64 . V_1222 . V_516 == 0 && V_983 > 24 ) {
F_157 ( L_191 ,
V_983 ) ;
V_38 -> V_725 = 24 ;
}
}
static int
F_818 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_420 * V_43 ;
struct V_1107 * V_711 ;
struct V_713 * V_1113 ;
int V_983 , V_142 ;
if ( ( F_18 ( V_57 ) || F_16 ( V_57 ) || F_17 ( V_57 ) ) )
V_983 = 10 * 3 ;
else if ( F_58 ( V_57 ) -> V_103 >= 5 )
V_983 = 12 * 3 ;
else
V_983 = 8 * 3 ;
V_38 -> V_725 = V_983 ;
V_43 = V_38 -> V_64 . V_43 ;
F_809 (state, connector, connector_state, i) {
if ( V_1113 -> V_65 != & V_65 -> V_64 )
continue;
F_817 ( F_819 ( V_711 ) ,
V_38 ) ;
}
return V_983 ;
}
static void F_820 ( const struct V_515 * V_416 )
{
F_157 ( L_192
L_193 ,
V_416 -> V_93 ,
V_416 -> V_539 , V_416 -> V_731 ,
V_416 -> V_880 , V_416 -> V_877 ,
V_416 -> V_540 , V_416 -> V_882 ,
V_416 -> V_883 , V_416 -> V_873 , V_416 -> type , V_416 -> V_320 ) ;
}
static void F_821 ( struct V_81 * V_65 ,
struct V_37 * V_38 ,
const char * V_1223 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_323 * V_140 ;
struct V_327 * V_327 ;
struct V_328 * V_43 ;
struct V_251 * V_90 ;
F_157 ( L_194 ,
V_65 -> V_64 . V_64 . V_372 , V_65 -> V_64 . V_12 ,
V_1223 , V_38 , F_76 ( V_65 -> V_95 ) ) ;
F_157 ( L_195 , F_822 ( V_38 -> V_97 ) ) ;
F_157 ( L_196 ,
V_38 -> V_725 , V_38 -> V_896 ) ;
F_157 ( L_197 ,
V_38 -> V_229 ,
V_38 -> V_453 ,
V_38 -> V_572 . V_793 , V_38 -> V_572 . V_794 ,
V_38 -> V_572 . V_795 , V_38 -> V_572 . V_796 ,
V_38 -> V_572 . V_792 ) ;
F_157 ( L_198 ,
F_361 ( V_38 ) ,
V_38 -> V_1224 ,
V_38 -> V_810 . V_793 , V_38 -> V_810 . V_794 ,
V_38 -> V_810 . V_795 , V_38 -> V_810 . V_796 ,
V_38 -> V_810 . V_792 ) ;
F_157 ( L_199 ,
F_361 ( V_38 ) ,
V_38 -> V_1224 ,
V_38 -> V_811 . V_793 ,
V_38 -> V_811 . V_794 ,
V_38 -> V_811 . V_795 ,
V_38 -> V_811 . V_796 ,
V_38 -> V_811 . V_792 ) ;
F_157 ( L_200 ,
V_38 -> V_1225 ,
V_38 -> V_1226 ) ;
F_157 ( L_201 ) ;
F_823 ( & V_38 -> V_64 . V_416 ) ;
F_157 ( L_202 ) ;
F_823 ( & V_38 -> V_64 . V_92 ) ;
F_820 ( & V_38 -> V_64 . V_92 ) ;
F_157 ( L_203 , V_38 -> V_39 ) ;
F_157 ( L_204 ,
V_38 -> V_356 , V_38 -> V_355 ) ;
F_157 ( L_205 ,
V_65 -> V_375 ,
V_38 -> V_374 . V_528 ,
V_38 -> V_374 . V_406 ) ;
F_157 ( L_206 ,
V_38 -> V_584 . V_585 ,
V_38 -> V_584 . V_589 ,
V_38 -> V_584 . V_1227 ) ;
F_157 ( L_207 ,
V_38 -> V_439 . V_544 ,
V_38 -> V_439 . V_247 ,
V_38 -> V_439 . V_151 ? L_208 : L_209 ) ;
F_157 ( L_210 , V_38 -> V_547 ) ;
F_157 ( L_211 , V_38 -> V_232 ) ;
if ( F_36 ( V_57 ) ) {
F_157 ( L_212
L_213
L_214 ,
V_38 -> V_1051 ,
V_38 -> V_179 . V_1228 ,
V_38 -> V_179 . V_1229 ,
V_38 -> V_179 . V_1230 ,
V_38 -> V_179 . V_1231 ,
V_38 -> V_179 . V_1232 ,
V_38 -> V_179 . V_1233 ,
V_38 -> V_179 . V_1234 ,
V_38 -> V_179 . V_1235 ,
V_38 -> V_179 . V_1236 ,
V_38 -> V_179 . V_1237 ,
V_38 -> V_179 . V_1238 ) ;
} else if ( F_442 ( V_57 ) || F_443 ( V_57 ) ) {
F_157 ( L_215
L_216 ,
V_38 -> V_1051 ,
V_38 -> V_179 . V_1239 ,
V_38 -> V_179 . V_1240 ,
V_38 -> V_179 . V_1241 ) ;
} else if ( F_23 ( V_57 ) ) {
F_157 ( L_217 ,
V_38 -> V_1051 ,
V_38 -> V_179 . V_1242 ,
V_38 -> V_179 . V_1243 ) ;
} else {
F_157 ( L_218
L_219 ,
V_38 -> V_179 . V_45 ,
V_38 -> V_179 . V_181 ,
V_38 -> V_179 . V_704 ,
V_38 -> V_179 . V_705 ) ;
}
F_157 ( L_220 ) ;
F_824 (plane, &dev->mode_config.plane_list, head) {
V_327 = F_213 ( V_140 ) ;
if ( V_327 -> V_95 != V_65 -> V_95 )
continue;
V_43 = F_214 ( V_140 -> V_43 ) ;
V_90 = V_43 -> V_64 . V_90 ;
if ( ! V_90 ) {
F_157 ( L_221 ,
V_140 -> V_64 . V_372 , V_140 -> V_12 , V_43 -> V_406 ) ;
continue;
}
F_157 ( L_222 ,
V_140 -> V_64 . V_372 , V_140 -> V_12 ) ;
F_157 ( L_223 ,
V_90 -> V_64 . V_372 , V_90 -> V_248 , V_90 -> V_243 ,
F_825 ( V_90 -> V_244 ) ) ;
F_157 ( L_224 ,
V_43 -> V_406 ,
V_43 -> V_342 . V_343 >> 16 , V_43 -> V_342 . y1 >> 16 ,
F_251 ( & V_43 -> V_342 ) >> 16 ,
F_252 ( & V_43 -> V_342 ) >> 16 ,
V_43 -> V_346 . V_343 , V_43 -> V_346 . y1 ,
F_251 ( & V_43 -> V_346 ) ,
F_252 ( & V_43 -> V_346 ) ) ;
}
}
static bool F_826 ( struct V_420 * V_43 )
{
struct V_56 * V_57 = V_43 -> V_57 ;
struct V_1107 * V_711 ;
unsigned int V_1244 = 0 ;
F_827 (connector, dev) {
struct V_713 * V_1113 ;
struct V_506 * V_507 ;
V_1113 = F_828 ( V_43 , V_711 ) ;
if ( ! V_1113 )
V_1113 = V_711 -> V_43 ;
if ( ! V_1113 -> V_715 )
continue;
V_507 = F_435 ( V_1113 -> V_715 ) ;
F_28 ( ! V_1113 -> V_65 ) ;
switch ( V_507 -> type ) {
unsigned int V_201 ;
case V_603 :
if ( F_28 ( ! F_23 ( V_57 ) ) )
break;
case V_508 :
case V_214 :
case V_509 :
V_201 = 1 << F_353 ( & V_507 -> V_64 ) -> V_183 ;
if ( V_1244 & V_201 )
return false ;
V_1244 |= V_201 ;
default:
break;
}
}
return true ;
}
static void
F_829 ( struct V_37 * V_62 )
{
struct V_42 V_1245 ;
struct V_373 V_374 ;
struct V_1246 V_179 ;
struct V_989 * V_211 ;
T_2 V_1051 ;
bool V_610 ;
V_1245 = V_62 -> V_64 ;
V_374 = V_62 -> V_374 ;
V_211 = V_62 -> V_211 ;
V_179 = V_62 -> V_179 ;
V_1051 = V_62 -> V_1051 ;
V_610 = V_62 -> V_439 . V_610 ;
memset ( V_62 , 0 , sizeof *V_62 ) ;
V_62 -> V_64 = V_1245 ;
V_62 -> V_374 = V_374 ;
V_62 -> V_211 = V_211 ;
V_62 -> V_179 = V_179 ;
V_62 -> V_1051 = V_1051 ;
V_62 -> V_439 . V_610 = V_610 ;
}
static int
F_830 ( struct V_87 * V_65 ,
struct V_37 * V_38 )
{
struct V_420 * V_43 = V_38 -> V_64 . V_43 ;
struct V_506 * V_507 ;
struct V_1107 * V_711 ;
struct V_713 * V_1113 ;
int V_1247 , V_267 = - V_537 ;
int V_142 ;
bool V_458 = true ;
F_829 ( V_38 ) ;
V_38 -> V_97 =
(enum V_94 ) F_47 ( V_65 ) -> V_95 ;
if ( ! ( V_38 -> V_64 . V_92 . V_320 &
( V_520 | V_1248 ) ) )
V_38 -> V_64 . V_92 . V_320 |= V_1248 ;
if ( ! ( V_38 -> V_64 . V_92 . V_320 &
( V_522 | V_1249 ) ) )
V_38 -> V_64 . V_92 . V_320 |= V_1249 ;
V_1247 = F_818 ( F_47 ( V_65 ) ,
V_38 ) ;
if ( V_1247 < 0 )
goto V_779;
F_715 ( & V_38 -> V_64 . V_416 ,
& V_38 -> V_356 ,
& V_38 -> V_355 ) ;
F_809 (state, connector, connector_state, i) {
if ( V_1113 -> V_65 != V_65 )
continue;
V_507 = F_435 ( V_1113 -> V_715 ) ;
if ( ! F_808 ( V_43 , F_47 ( V_65 ) , V_507 ) ) {
F_157 ( L_225 ) ;
goto V_779;
}
V_38 -> V_1250 |= 1 << V_507 -> type ;
}
V_1251:
V_38 -> V_39 = 0 ;
V_38 -> V_577 = 1 ;
F_831 ( & V_38 -> V_64 . V_92 ,
V_1252 ) ;
F_809 (state, connector, connector_state, i) {
if ( V_1113 -> V_65 != V_65 )
continue;
V_507 = F_435 ( V_1113 -> V_715 ) ;
if ( ! ( V_507 -> V_1253 ( V_507 , V_38 ) ) ) {
F_157 ( L_226 ) ;
goto V_779;
}
}
if ( ! V_38 -> V_39 )
V_38 -> V_39 = V_38 -> V_64 . V_92 . V_93
* V_38 -> V_577 ;
V_267 = F_530 ( F_47 ( V_65 ) , V_38 ) ;
if ( V_267 < 0 ) {
F_157 ( L_227 ) ;
goto V_779;
}
if ( V_267 == V_727 ) {
if ( F_7 ( ! V_458 , L_228 ) ) {
V_267 = - V_537 ;
goto V_779;
}
F_157 ( L_229 ) ;
V_458 = false ;
goto V_1251;
}
V_38 -> V_896 = V_38 -> V_725 == 6 * 3 ;
F_157 ( L_230 ,
V_1247 , V_38 -> V_725 , V_38 -> V_896 ) ;
V_779:
return V_267 ;
}
static void
F_832 ( struct V_420 * V_43 )
{
struct V_87 * V_65 ;
struct V_42 * V_62 ;
int V_142 ;
F_269 (state, crtc, crtc_state, i) {
F_47 ( V_65 ) -> V_91 = F_265 ( V_65 -> V_43 ) ;
if ( V_65 -> V_43 -> V_88 )
V_65 -> V_1254 = V_65 -> V_43 -> V_92 ;
else
V_65 -> V_1254 . V_93 = 0 ;
if ( F_385 ( V_43 , V_65 -> V_89 ) ) {
struct V_325 * V_326 = V_65 -> V_89 -> V_43 ;
V_65 -> V_89 -> V_90 = V_326 -> V_90 ;
V_65 -> V_274 = V_326 -> V_334 >> 16 ;
V_65 -> V_275 = V_326 -> V_335 >> 16 ;
}
}
}
static bool F_833 ( int V_1255 , int V_1256 )
{
int V_1257 ;
if ( V_1255 == V_1256 )
return true ;
if ( ! V_1255 || ! V_1256 )
return false ;
V_1257 = abs ( V_1255 - V_1256 ) ;
if ( ( ( ( ( V_1257 + V_1255 + V_1256 ) * 100 ) ) / ( V_1255 + V_1256 ) ) < 105 )
return true ;
return false ;
}
static bool
F_834 ( unsigned int V_46 , unsigned int V_51 ,
unsigned int V_47 , unsigned int V_1258 ,
bool V_1259 )
{
if ( V_46 == V_47 && V_51 == V_1258 )
return true ;
if ( V_1259 || ! V_46 || ! V_51 || ! V_47 || ! V_1258 )
return false ;
F_835 ( V_783 > V_84 ) ;
if ( V_51 > V_1258 ) {
while ( V_51 > V_1258 ) {
V_47 <<= 1 ;
V_1258 <<= 1 ;
}
} else if ( V_51 < V_1258 ) {
while ( V_51 < V_1258 ) {
V_46 <<= 1 ;
V_51 <<= 1 ;
}
}
if ( V_51 != V_1258 )
return false ;
return F_833 ( V_46 , V_47 ) ;
}
static bool
F_836 ( const struct V_790 * V_791 ,
struct V_790 * V_807 ,
bool V_1260 )
{
if ( V_791 -> V_792 == V_807 -> V_792 &&
F_834 ( V_791 -> V_793 , V_791 -> V_794 ,
V_807 -> V_793 , V_807 -> V_794 , ! V_1260 ) &&
F_834 ( V_791 -> V_795 , V_791 -> V_796 ,
V_807 -> V_795 , V_807 -> V_796 , ! V_1260 ) ) {
if ( V_1260 )
* V_807 = * V_791 ;
return true ;
}
return false ;
}
static bool
F_837 ( struct V_56 * V_57 ,
struct V_37 * V_1261 ,
struct V_37 * V_38 ,
bool V_1260 )
{
bool V_267 = true ;
#define F_838 ( T_8 , ... ) \
do { \
if (!adjust) \
DRM_ERROR(fmt, ##__VA_ARGS__); \
else \
DRM_DEBUG_KMS(fmt, ##__VA_ARGS__); \
} while (0)
#define F_839 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_840 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_841 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %p, found %p)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_842 ( V_12 ) \
if (!intel_compare_link_m_n(&current_config->name, \
&pipe_config->name,\
adjust)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected tu %i gmch %i/%i link %i/%i, " \
"found tu %i, gmch %i/%i link %i/%i)\n", \
current_config->name.tu, \
current_config->name.gmch_m, \
current_config->name.gmch_n, \
current_config->name.link_m, \
current_config->name.link_n, \
pipe_config->name.tu, \
pipe_config->name.gmch_m, \
pipe_config->name.gmch_n, \
pipe_config->name.link_m, \
pipe_config->name.link_n); \
ret = false; \
}
#define F_843 ( V_12 , T_9 ) \
if (!intel_compare_link_m_n(&current_config->name, \
&pipe_config->name, adjust) && \
!intel_compare_link_m_n(&current_config->alt_name, \
&pipe_config->name, adjust)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected tu %i gmch %i/%i link %i/%i, " \
"or tu %i gmch %i/%i link %i/%i, " \
"found tu %i, gmch %i/%i link %i/%i)\n", \
current_config->name.tu, \
current_config->name.gmch_m, \
current_config->name.gmch_n, \
current_config->name.link_m, \
current_config->name.link_n, \
current_config->alt_name.tu, \
current_config->alt_name.gmch_m, \
current_config->alt_name.gmch_n, \
current_config->alt_name.link_m, \
current_config->alt_name.link_n, \
pipe_config->name.tu, \
pipe_config->name.gmch_m, \
pipe_config->name.gmch_n, \
pipe_config->name.link_m, \
pipe_config->name.link_n); \
ret = false; \
}
#define F_844 ( V_12 , V_609 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
ret = false; \
}
#define F_845 ( V_12 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_846 ( T_10 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_840 ( V_97 ) ;
F_840 ( V_229 ) ;
F_840 ( V_453 ) ;
F_842 ( V_572 ) ;
F_840 ( V_1224 ) ;
F_839 ( V_1262 ) ;
if ( F_58 ( V_57 ) -> V_103 < 8 ) {
F_842 ( V_810 ) ;
if ( V_1261 -> V_808 )
F_842 ( V_811 ) ;
} else
F_843 ( V_810 , V_811 ) ;
F_839 ( V_1250 ) ;
F_840 ( V_64 . V_92 . V_539 ) ;
F_840 ( V_64 . V_92 . V_877 ) ;
F_840 ( V_64 . V_92 . V_878 ) ;
F_840 ( V_64 . V_92 . V_879 ) ;
F_840 ( V_64 . V_92 . V_731 ) ;
F_840 ( V_64 . V_92 . V_880 ) ;
F_840 ( V_64 . V_92 . V_540 ) ;
F_840 ( V_64 . V_92 . V_873 ) ;
F_840 ( V_64 . V_92 . V_881 ) ;
F_840 ( V_64 . V_92 . V_874 ) ;
F_840 ( V_64 . V_92 . V_882 ) ;
F_840 ( V_64 . V_92 . V_883 ) ;
F_840 ( V_577 ) ;
F_840 ( V_1263 ) ;
if ( ( F_58 ( V_57 ) -> V_103 < 8 && ! F_234 ( V_57 ) ) ||
F_16 ( V_57 ) || F_17 ( V_57 ) )
F_840 ( V_905 ) ;
F_840 ( V_1226 ) ;
F_840 ( V_1225 ) ;
F_844 ( V_64 . V_92 . V_320 ,
V_876 ) ;
if ( ! F_846 ( V_1264 ) ) {
F_844 ( V_64 . V_92 . V_320 ,
V_520 ) ;
F_844 ( V_64 . V_92 . V_320 ,
V_1248 ) ;
F_844 ( V_64 . V_92 . V_320 ,
V_522 ) ;
F_844 ( V_64 . V_92 . V_320 ,
V_1249 ) ;
}
F_839 ( V_584 . V_585 ) ;
if ( F_58 ( V_57 ) -> V_103 < 4 )
F_839 ( V_584 . V_589 ) ;
F_839 ( V_584 . V_1227 ) ;
if ( ! V_1260 ) {
F_840 ( V_356 ) ;
F_840 ( V_355 ) ;
F_840 ( V_439 . V_151 ) ;
if ( V_1261 -> V_439 . V_151 ) {
F_839 ( V_439 . V_544 ) ;
F_839 ( V_439 . V_247 ) ;
}
F_840 ( V_374 . V_406 ) ;
}
if ( F_234 ( V_57 ) )
F_840 ( V_547 ) ;
F_840 ( V_232 ) ;
F_839 ( V_1051 ) ;
F_841 ( V_211 ) ;
F_839 ( V_179 . V_45 ) ;
F_839 ( V_179 . V_181 ) ;
F_839 ( V_179 . V_704 ) ;
F_839 ( V_179 . V_705 ) ;
F_839 ( V_179 . V_1242 ) ;
F_839 ( V_179 . V_1243 ) ;
F_839 ( V_179 . V_1239 ) ;
F_839 ( V_179 . V_1240 ) ;
F_839 ( V_179 . V_1241 ) ;
F_839 ( V_1265 . V_1266 ) ;
F_839 ( V_1265 . div ) ;
if ( F_18 ( V_57 ) || F_58 ( V_57 ) -> V_103 >= 5 )
F_840 ( V_725 ) ;
F_845 ( V_64 . V_92 . V_93 ) ;
F_845 ( V_39 ) ;
#undef F_839
#undef F_840
#undef F_841
#undef F_844
#undef F_845
#undef F_846
#undef F_838
return V_267 ;
}
static void F_847 ( struct V_5 * V_6 ,
const struct V_37 * V_38 )
{
if ( V_38 -> V_229 ) {
int V_723 = F_729 ( F_22 ( V_6 , V_38 ) ,
& V_38 -> V_572 ) ;
int V_1267 = V_38 -> V_64 . V_92 . V_93 ;
F_7 ( ! F_833 ( V_723 , V_1267 ) ,
L_231 ,
V_723 , V_1267 ) ;
}
}
static void F_848 ( struct V_87 * V_65 ,
struct V_42 * V_1268 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_1269 V_1270 , * V_1271 ;
struct V_1272 * V_1273 , * V_1274 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
const enum V_95 V_95 = V_81 -> V_95 ;
int V_140 ;
if ( F_58 ( V_57 ) -> V_103 < 9 || ! V_1268 -> V_88 )
return;
F_849 ( V_6 , & V_1270 ) ;
V_1271 = & V_6 -> V_556 . V_1275 . V_1276 ;
F_850 (dev_priv, pipe, plane) {
V_1273 = & V_1270 . V_140 [ V_95 ] [ V_140 ] ;
V_1274 = & V_1271 -> V_140 [ V_95 ] [ V_140 ] ;
if ( F_851 ( V_1273 , V_1274 ) )
continue;
F_125 ( L_232
L_233 ,
F_76 ( V_95 ) , V_140 + 1 ,
V_1274 -> V_369 , V_1274 -> V_1277 ,
V_1273 -> V_369 , V_1273 -> V_1277 ) ;
}
V_1273 = & V_1270 . V_140 [ V_95 ] [ V_1278 ] ;
V_1274 = & V_1271 -> V_140 [ V_95 ] [ V_1278 ] ;
if ( ! F_851 ( V_1273 , V_1274 ) ) {
F_125 ( L_234
L_233 ,
F_76 ( V_95 ) ,
V_1274 -> V_369 , V_1274 -> V_1277 ,
V_1273 -> V_369 , V_1273 -> V_1277 ) ;
}
}
static void
F_852 ( struct V_56 * V_57 , struct V_87 * V_65 )
{
struct V_1107 * V_711 ;
F_827 (connector, dev) {
struct V_608 * V_507 = V_711 -> V_507 ;
struct V_713 * V_43 = V_711 -> V_43 ;
if ( V_43 -> V_65 != V_65 )
continue;
F_512 ( F_819 ( V_711 ) ) ;
F_64 ( V_43 -> V_715 != V_507 ,
L_235 ) ;
}
}
static void
F_853 ( struct V_56 * V_57 )
{
struct V_506 * V_507 ;
struct V_710 * V_711 ;
F_625 (dev, encoder) {
bool V_151 = false ;
enum V_95 V_95 ;
F_157 ( L_236 ,
V_507 -> V_64 . V_64 . V_372 ,
V_507 -> V_64 . V_12 ) ;
F_814 (dev, connector) {
if ( V_711 -> V_64 . V_43 -> V_715 != & V_507 -> V_64 )
continue;
V_151 = true ;
F_64 ( V_711 -> V_64 . V_43 -> V_65 !=
V_507 -> V_64 . V_65 ,
L_237 ) ;
}
F_64 ( ! ! V_507 -> V_64 . V_65 != V_151 ,
L_238
L_239 ,
! ! V_507 -> V_64 . V_65 , V_151 ) ;
if ( ! V_507 -> V_64 . V_65 ) {
bool V_88 ;
V_88 = V_507 -> V_712 ( V_507 , & V_95 ) ;
F_64 ( V_88 ,
L_240 ,
F_76 ( V_95 ) ) ;
}
}
}
static void
F_854 ( struct V_87 * V_65 ,
struct V_42 * V_438 ,
struct V_42 * V_1279 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_506 * V_507 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_37 * V_38 , * V_1280 ;
struct V_420 * V_559 ;
bool V_88 ;
V_559 = V_438 -> V_43 ;
F_855 ( V_438 ) ;
V_38 = F_265 ( V_438 ) ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_38 -> V_64 . V_65 = V_65 ;
V_38 -> V_64 . V_43 = V_559 ;
F_157 ( L_241 , V_65 -> V_64 . V_372 , V_65 -> V_12 ) ;
V_88 = V_6 -> V_431 . V_1281 ( V_81 , V_38 ) ;
if ( ( V_81 -> V_95 == V_117 && V_6 -> V_136 & V_137 ) ||
( V_81 -> V_95 == V_126 && V_6 -> V_136 & V_138 ) )
V_88 = V_1279 -> V_88 ;
F_64 ( V_1279 -> V_88 != V_88 ,
L_242
L_239 , V_1279 -> V_88 , V_88 ) ;
F_64 ( V_81 -> V_88 != V_1279 -> V_88 ,
L_243
L_239 , V_1279 -> V_88 , V_81 -> V_88 ) ;
F_352 (dev, crtc, encoder) {
enum V_95 V_95 ;
V_88 = V_507 -> V_712 ( V_507 , & V_95 ) ;
F_64 ( V_88 != V_1279 -> V_88 ,
L_244 ,
V_507 -> V_64 . V_64 . V_372 , V_88 , V_1279 -> V_88 ) ;
F_64 ( V_88 && V_81 -> V_95 != V_95 ,
L_245 ,
F_76 ( V_95 ) ) ;
if ( V_88 ) {
V_38 -> V_1250 |= 1 << V_507 -> type ;
V_507 -> V_1282 ( V_507 , V_38 ) ;
}
}
if ( ! V_1279 -> V_88 )
return;
F_847 ( V_6 , V_38 ) ;
V_1280 = F_265 ( V_65 -> V_43 ) ;
if ( ! F_837 ( V_57 , V_1280 ,
V_38 , false ) ) {
F_64 ( 1 , L_246 ) ;
F_821 ( V_81 , V_38 ,
L_247 ) ;
F_821 ( V_81 , V_1280 ,
L_248 ) ;
}
}
static void
F_856 ( struct V_5 * V_6 ,
struct V_989 * V_990 ,
struct V_87 * V_65 ,
struct V_42 * V_1268 )
{
struct V_1246 V_179 ;
unsigned V_1283 ;
bool V_88 ;
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
F_157 ( L_249 , V_990 -> V_12 ) ;
V_88 = V_990 -> V_1008 . V_712 ( V_6 , V_990 , & V_179 ) ;
if ( ! ( V_990 -> V_320 & V_1284 ) ) {
F_64 ( ! V_990 -> V_1285 && V_990 -> V_1286 ,
L_250 ) ;
F_64 ( V_990 -> V_1285 && ! V_990 -> V_1286 ,
L_251 ) ;
F_64 ( V_990 -> V_1285 != V_88 ,
L_252 ,
V_990 -> V_1285 , V_88 ) ;
}
if ( ! V_65 ) {
F_64 ( V_990 -> V_1286 & ~ V_990 -> V_91 . V_1283 ,
L_253 ,
V_990 -> V_1286 , V_990 -> V_91 . V_1283 ) ;
return;
}
V_1283 = 1 << F_857 ( V_65 ) ;
if ( V_1268 -> V_88 )
F_64 ( ! ( V_990 -> V_1286 & V_1283 ) ,
L_254 ,
F_76 ( F_857 ( V_65 ) ) , V_990 -> V_1286 ) ;
else
F_64 ( V_990 -> V_1286 & V_1283 ,
L_255 ,
F_76 ( F_857 ( V_65 ) ) , V_990 -> V_1286 ) ;
F_64 ( ! ( V_990 -> V_91 . V_1283 & V_1283 ) ,
L_256 ,
V_1283 , V_990 -> V_91 . V_1283 ) ;
F_64 ( V_990 -> V_1285 && memcmp ( & V_990 -> V_91 . V_1287 ,
& V_179 ,
sizeof( V_179 ) ) ,
L_257 ) ;
}
static void
F_858 ( struct V_56 * V_57 , struct V_87 * V_65 ,
struct V_42 * V_438 ,
struct V_42 * V_1279 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_37 * V_559 = F_265 ( V_438 ) ;
struct V_37 * V_1268 = F_265 ( V_1279 ) ;
if ( V_1268 -> V_211 )
F_856 ( V_6 , V_1268 -> V_211 , V_65 , V_1279 ) ;
if ( V_559 -> V_211 &&
V_559 -> V_211 != V_1268 -> V_211 ) {
unsigned V_1283 = 1 << F_857 ( V_65 ) ;
struct V_989 * V_990 = V_559 -> V_211 ;
F_64 ( V_990 -> V_1286 & V_1283 ,
L_258 ,
F_76 ( F_857 ( V_65 ) ) ) ;
F_64 ( V_990 -> V_91 . V_1283 & V_1283 ,
L_259 ,
F_76 ( F_857 ( V_65 ) ) ) ;
}
}
static void
F_859 ( struct V_87 * V_65 ,
struct V_42 * V_559 ,
struct V_42 * V_1268 )
{
if ( ! F_25 ( V_1268 ) &&
! F_265 ( V_1268 ) -> V_1288 )
return;
F_848 ( V_65 , V_1268 ) ;
F_852 ( V_65 -> V_57 , V_65 ) ;
F_854 ( V_65 , V_559 , V_1268 ) ;
F_858 ( V_65 -> V_57 , V_65 , V_559 , V_1268 ) ;
}
static void
F_860 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_142 ;
for ( V_142 = 0 ; V_142 < V_6 -> V_945 ; V_142 ++ )
F_856 ( V_6 , & V_6 -> V_1289 [ V_142 ] , NULL , NULL ) ;
}
static void
F_861 ( struct V_56 * V_57 )
{
F_853 ( V_57 ) ;
F_852 ( V_57 , NULL ) ;
F_860 ( V_57 ) ;
}
static void F_862 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
if ( F_55 ( V_57 ) ) {
const struct V_515 * V_92 = & V_65 -> V_91 -> V_64 . V_92 ;
int V_889 ;
V_889 = V_92 -> V_873 ;
if ( V_92 -> V_320 & V_876 )
V_889 /= 2 ;
V_65 -> V_231 = V_889 - 1 ;
} else if ( F_23 ( V_57 ) &&
F_38 ( V_65 -> V_91 , V_214 ) ) {
V_65 -> V_231 = 2 ;
} else
V_65 -> V_231 = 1 ;
}
static void F_863 ( struct V_420 * V_43 )
{
struct V_56 * V_57 = V_43 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_1290 * V_211 = NULL ;
struct V_87 * V_65 ;
struct V_42 * V_62 ;
int V_142 ;
if ( ! V_6 -> V_431 . V_1214 )
return;
F_269 (state, crtc, crtc_state, i) {
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_989 * V_1291 =
F_265 ( V_65 -> V_43 ) -> V_211 ;
if ( ! F_25 ( V_62 ) )
continue;
F_265 ( V_62 ) -> V_211 = NULL ;
if ( ! V_1291 )
continue;
if ( ! V_211 )
V_211 = F_864 ( V_43 ) ;
F_865 ( V_211 , V_1291 , V_81 ) ;
}
}
static int F_866 ( struct V_420 * V_43 )
{
struct V_42 * V_62 ;
struct V_81 * V_81 ;
struct V_87 * V_65 ;
struct V_37 * V_1292 = NULL ;
struct V_37 * V_719 = NULL ;
enum V_95 V_1293 = V_579 , V_1294 = V_579 ;
int V_142 ;
F_269 (state, crtc, crtc_state, i) {
V_81 = F_47 ( V_65 ) ;
if ( ! V_62 -> V_88 || ! F_25 ( V_62 ) )
continue;
if ( V_1292 ) {
V_719 = F_265 ( V_62 ) ;
break;
} else {
V_1292 = F_265 ( V_62 ) ;
V_1293 = V_81 -> V_95 ;
}
}
if ( ! V_1292 )
return 0 ;
F_136 (state->dev, intel_crtc) {
struct V_37 * V_38 ;
V_38 = F_521 ( V_43 , V_81 ) ;
if ( F_278 ( V_38 ) )
return F_279 ( V_38 ) ;
V_38 -> V_574 = V_579 ;
if ( ! V_38 -> V_64 . V_88 ||
F_25 ( & V_38 -> V_64 ) )
continue;
if ( V_1294 != V_579 )
return 0 ;
V_1294 = V_81 -> V_95 ;
}
if ( V_1294 != V_579 )
V_1292 -> V_574 = V_1294 ;
else if ( V_719 )
V_719 -> V_574 = V_1293 ;
return 0 ;
}
static int F_867 ( struct V_420 * V_43 )
{
struct V_87 * V_65 ;
struct V_42 * V_62 ;
int V_267 = 0 ;
F_216 (state->dev, crtc) {
V_62 = F_725 ( V_43 , V_65 ) ;
if ( F_278 ( V_62 ) )
return F_279 ( V_62 ) ;
if ( ! V_62 -> V_88 || F_25 ( V_62 ) )
continue;
V_62 -> V_421 = true ;
V_267 = F_868 ( V_43 , V_65 ) ;
if ( V_267 )
break;
V_267 = F_869 ( V_43 , V_65 ) ;
if ( V_267 )
break;
}
return V_267 ;
}
static int F_870 ( struct V_420 * V_43 )
{
struct V_689 * V_329 = F_270 ( V_43 ) ;
struct V_5 * V_6 = F_53 ( V_43 -> V_57 ) ;
struct V_87 * V_65 ;
struct V_42 * V_62 ;
int V_267 = 0 , V_142 ;
if ( ! F_826 ( V_43 ) ) {
F_157 ( L_260 ) ;
return - V_537 ;
}
V_329 -> V_566 = true ;
V_329 -> V_693 = V_6 -> V_693 ;
F_269 (state, crtc, crtc_state, i) {
if ( V_62 -> V_88 )
V_329 -> V_693 |= 1 << V_142 ;
else
V_329 -> V_693 &= ~ ( 1 << V_142 ) ;
if ( V_62 -> V_88 != V_65 -> V_43 -> V_88 )
V_329 -> V_1295 |= F_871 ( V_65 ) ;
}
if ( V_6 -> V_431 . V_1296 ) {
if ( ! V_329 -> V_1049 )
V_329 -> V_1049 = V_6 -> V_630 . V_52 ;
if ( ! V_329 -> V_1049 )
V_329 -> V_1049 = V_6 -> V_621 ;
V_267 = V_6 -> V_431 . V_1296 ( V_43 ) ;
if ( V_267 < 0 )
return V_267 ;
if ( V_329 -> V_692 != V_6 -> V_627 ||
V_329 -> V_1049 != V_6 -> V_630 . V_52 )
V_267 = F_867 ( V_43 ) ;
if ( V_267 < 0 )
return V_267 ;
F_157 ( L_261 ,
V_329 -> V_633 , V_329 -> V_692 ) ;
} else
F_270 ( V_43 ) -> V_633 = V_6 -> V_1297 ;
F_863 ( V_43 ) ;
if ( F_234 ( V_6 ) )
return F_866 ( V_43 ) ;
return 0 ;
}
static int F_872 ( struct V_420 * V_43 )
{
struct V_56 * V_57 = V_43 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( V_6 -> V_431 . V_1298 )
return V_6 -> V_431 . V_1298 ( V_43 ) ;
return 0 ;
}
static int F_873 ( struct V_56 * V_57 ,
struct V_420 * V_43 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_689 * V_329 = F_270 ( V_43 ) ;
struct V_87 * V_65 ;
struct V_42 * V_62 ;
int V_267 , V_142 ;
bool V_1299 = false ;
V_267 = F_874 ( V_57 , V_43 ) ;
if ( V_267 )
return V_267 ;
F_269 (state, crtc, crtc_state, i) {
struct V_37 * V_38 =
F_265 ( V_62 ) ;
if ( V_62 -> V_416 . V_1300 != V_65 -> V_43 -> V_416 . V_1300 )
V_62 -> V_421 = true ;
if ( ! F_25 ( V_62 ) )
continue;
if ( ! V_62 -> V_502 ) {
V_1299 = true ;
continue;
}
V_267 = F_868 ( V_43 , V_65 ) ;
if ( V_267 )
return V_267 ;
V_267 = F_830 ( V_65 , V_38 ) ;
if ( V_267 ) {
F_821 ( F_47 ( V_65 ) ,
V_38 , L_262 ) ;
return V_267 ;
}
if ( V_728 . V_1301 &&
F_837 ( V_57 ,
F_265 ( V_65 -> V_43 ) ,
V_38 , true ) ) {
V_62 -> V_421 = false ;
F_265 ( V_62 ) -> V_1288 = true ;
}
if ( F_25 ( V_62 ) )
V_1299 = true ;
V_267 = F_869 ( V_43 , V_65 ) ;
if ( V_267 )
return V_267 ;
F_821 ( F_47 ( V_65 ) , V_38 ,
F_25 ( V_62 ) ?
L_263 : L_264 ) ;
}
if ( V_1299 ) {
V_267 = F_870 ( V_43 ) ;
if ( V_267 )
return V_267 ;
} else
V_329 -> V_633 = V_6 -> V_627 ;
V_267 = F_875 ( V_57 , V_43 ) ;
if ( V_267 )
return V_267 ;
F_876 ( V_6 , V_43 ) ;
return F_872 ( V_43 ) ;
}
static int F_877 ( struct V_56 * V_57 ,
struct V_420 * V_43 ,
bool V_1302 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_325 * V_326 ;
struct V_42 * V_62 ;
struct V_323 * V_140 ;
struct V_87 * V_65 ;
int V_142 , V_267 ;
F_269 (state, crtc, crtc_state, i) {
if ( V_43 -> V_1303 )
continue;
V_267 = F_321 ( V_65 ) ;
if ( V_267 )
return V_267 ;
if ( F_314 ( & F_47 ( V_65 ) -> V_473 ) >= 2 )
F_789 ( V_6 -> V_476 ) ;
}
V_267 = F_878 ( & V_57 -> V_268 ) ;
if ( V_267 )
return V_267 ;
V_267 = F_879 ( V_57 , V_43 ) ;
F_5 ( & V_57 -> V_268 ) ;
if ( ! V_267 && ! V_1302 ) {
F_880 (state, plane, plane_state, i) {
struct V_328 * V_328 =
F_214 ( V_326 ) ;
if ( ! V_328 -> V_1304 )
continue;
V_267 = F_773 ( V_328 -> V_1304 ,
true , NULL , NULL ) ;
if ( V_267 ) {
F_28 ( V_267 == - V_1194 ) ;
F_3 ( & V_57 -> V_268 ) ;
F_881 ( V_57 , V_43 ) ;
F_5 ( & V_57 -> V_268 ) ;
break;
}
}
}
return V_267 ;
}
T_1 F_745 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
if ( ! V_57 -> V_230 )
return F_882 ( & V_65 -> V_64 ) ;
return V_57 -> V_1305 -> V_1306 ( V_57 , V_65 -> V_95 ) ;
}
static void F_883 ( struct V_56 * V_57 ,
struct V_5 * V_6 ,
unsigned V_1283 )
{
unsigned V_1307 [ V_1308 ] ;
enum V_95 V_95 ;
int V_267 ;
if ( ! V_1283 )
return;
F_89 (dev_priv, pipe) {
struct V_87 * V_65 = V_6 -> V_96 [ V_95 ] ;
if ( ! ( ( 1 << V_95 ) & V_1283 ) )
continue;
V_267 = F_99 ( V_65 ) ;
if ( F_28 ( V_267 != 0 ) ) {
V_1283 &= ~ ( 1 << V_95 ) ;
continue;
}
V_1307 [ V_95 ] = F_884 ( V_65 ) ;
}
F_89 (dev_priv, pipe) {
struct V_87 * V_65 = V_6 -> V_96 [ V_95 ] ;
long V_1309 ;
if ( ! ( ( 1 << V_95 ) & V_1283 ) )
continue;
V_1309 = F_885 ( V_57 -> V_1185 [ V_95 ] . V_1310 ,
V_1307 [ V_95 ] !=
F_884 ( V_65 ) ,
F_886 ( 50 ) ) ;
F_7 ( ! V_1309 , L_265 , F_76 ( V_95 ) ) ;
F_100 ( V_65 ) ;
}
}
static bool F_887 ( struct V_37 * V_62 )
{
if ( V_62 -> V_1208 )
return true ;
if ( V_62 -> V_563 )
return true ;
if ( V_62 -> V_567 )
return true ;
return false ;
}
static void F_888 ( struct V_420 * V_43 )
{
struct V_56 * V_57 = V_43 -> V_57 ;
struct V_689 * V_329 = F_270 ( V_43 ) ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_42 * V_438 ;
struct V_87 * V_65 ;
struct V_37 * V_1311 ;
struct V_323 * V_140 ;
struct V_325 * V_326 ;
bool V_1312 = V_329 -> V_566 ;
unsigned long V_1313 [ V_1308 ] = {} ;
unsigned V_1314 = 0 ;
int V_142 , V_267 ;
F_880 (state, plane, plane_state, i) {
struct V_328 * V_328 =
F_214 ( V_326 ) ;
if ( ! V_328 -> V_1304 )
continue;
V_267 = F_773 ( V_328 -> V_1304 ,
true , NULL , NULL ) ;
F_28 ( V_267 ) ;
}
F_889 ( V_43 ) ;
if ( V_329 -> V_566 ) {
memcpy ( V_6 -> V_690 , V_329 -> V_690 ,
sizeof( V_329 -> V_690 ) ) ;
V_6 -> V_693 = V_329 -> V_693 ;
V_6 -> V_1297 = V_329 -> V_633 ;
F_438 ( V_6 , V_1315 ) ;
}
F_269 (state, crtc, old_crtc_state, i) {
struct V_81 * V_81 = F_47 ( V_65 ) ;
if ( F_25 ( V_65 -> V_43 ) ||
F_265 ( V_65 -> V_43 ) -> V_1288 ) {
V_1312 = true ;
V_1313 [ F_47 ( V_65 ) -> V_95 ] =
F_436 ( V_65 ,
F_265 ( V_65 -> V_43 ) ) ;
}
if ( ! F_25 ( V_65 -> V_43 ) )
continue;
F_389 ( F_265 ( V_438 ) ) ;
if ( V_438 -> V_88 ) {
F_392 ( V_65 , V_438 -> V_332 ) ;
V_6 -> V_431 . V_707 ( V_65 ) ;
V_81 -> V_88 = false ;
F_505 ( V_81 ) ;
F_506 ( V_81 ) ;
F_380 ( V_6 ) ;
F_381 ( V_6 ) ;
if ( ! V_65 -> V_43 -> V_88 )
F_387 ( V_65 ) ;
}
}
F_832 ( V_43 ) ;
if ( V_329 -> V_566 ) {
F_890 ( V_43 -> V_57 , V_43 ) ;
if ( V_6 -> V_431 . V_1316 &&
( V_329 -> V_692 != V_6 -> V_627 ||
V_329 -> V_1049 != V_6 -> V_630 . V_52 ) )
V_6 -> V_431 . V_1316 ( V_43 ) ;
if ( F_442 ( V_6 ) && ! F_891 ( V_43 ) )
F_892 ( V_6 ) ;
F_861 ( V_57 ) ;
}
F_269 (state, crtc, old_crtc_state, i) {
struct V_81 * V_81 = F_47 ( V_65 ) ;
bool V_566 = F_25 ( V_65 -> V_43 ) ;
struct V_37 * V_38 =
F_265 ( V_65 -> V_43 ) ;
if ( V_566 && V_65 -> V_43 -> V_88 ) {
F_862 ( F_47 ( V_65 ) ) ;
V_6 -> V_431 . V_1317 ( V_65 ) ;
}
if ( V_566 && ! V_65 -> V_43 -> V_88 && V_65 -> V_43 -> V_474 ) {
F_286 ( & V_57 -> V_436 ) ;
F_317 ( V_65 , V_65 -> V_43 -> V_474 ) ;
F_287 ( & V_57 -> V_436 ) ;
V_65 -> V_43 -> V_474 = NULL ;
}
if ( ! V_566 )
F_389 ( F_265 ( V_438 ) ) ;
if ( V_65 -> V_43 -> V_88 &&
F_385 ( V_43 , V_65 -> V_89 ) )
F_893 ( V_81 , V_38 , F_214 ( V_65 -> V_89 -> V_43 ) ) ;
if ( V_65 -> V_43 -> V_88 )
F_894 ( V_438 ) ;
if ( V_38 -> V_64 . V_88 && F_887 ( V_38 ) )
V_1314 |= 1 << V_142 ;
}
if ( ! V_43 -> V_1303 )
F_883 ( V_57 , V_6 , V_1314 ) ;
F_269 (state, crtc, old_crtc_state, i) {
V_1311 = F_265 ( V_65 -> V_43 ) ;
if ( V_6 -> V_431 . V_1209 )
V_6 -> V_431 . V_1209 ( V_1311 ) ;
}
F_269 (state, crtc, old_crtc_state, i) {
F_384 ( F_265 ( V_438 ) ) ;
if ( V_1313 [ V_142 ] )
F_439 ( V_6 , V_1313 [ V_142 ] ) ;
F_859 ( V_65 , V_438 , V_65 -> V_43 ) ;
}
if ( F_442 ( V_6 ) && V_329 -> V_566 &&
F_891 ( V_43 ) )
F_895 ( V_6 ) ;
F_896 ( V_43 ) ;
if ( V_329 -> V_566 )
F_84 ( V_6 , V_1315 ) ;
F_3 ( & V_57 -> V_268 ) ;
F_881 ( V_57 , V_43 ) ;
F_5 ( & V_57 -> V_268 ) ;
F_897 ( V_43 ) ;
F_281 ( V_43 ) ;
F_898 ( V_6 ) ;
}
static void F_899 ( struct V_1138 * V_2 )
{
struct V_420 * V_43 = F_735 ( V_2 ,
struct V_420 ,
V_1318 ) ;
F_888 ( V_43 ) ;
}
static void F_900 ( struct V_420 * V_43 )
{
struct V_325 * V_1201 ;
struct V_323 * V_140 ;
struct V_264 * V_265 , * V_1319 ;
struct V_327 * V_327 ;
int V_142 ;
F_3 ( & V_43 -> V_57 -> V_268 ) ;
F_880 (state, plane, old_plane_state, i) {
V_265 = F_187 ( V_140 -> V_43 -> V_90 ) ;
V_1319 = F_187 ( V_1201 -> V_90 ) ;
V_327 = F_213 ( V_140 ) ;
F_797 ( V_1319 , V_265 , V_327 -> V_350 ) ;
}
F_5 ( & V_43 -> V_57 -> V_268 ) ;
}
static int F_901 ( struct V_56 * V_57 ,
struct V_420 * V_43 ,
bool V_1302 )
{
struct V_689 * V_329 = F_270 ( V_43 ) ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_267 = 0 ;
if ( V_329 -> V_566 && V_1302 ) {
F_157 ( L_266 ) ;
return - V_537 ;
}
V_267 = F_902 ( V_43 , V_1302 ) ;
if ( V_267 )
return V_267 ;
F_788 ( & V_43 -> V_1318 , F_899 ) ;
V_267 = F_877 ( V_57 , V_43 , V_1302 ) ;
if ( V_267 ) {
F_806 ( L_267 , V_267 ) ;
return V_267 ;
}
F_903 ( V_43 , true ) ;
V_6 -> V_556 . V_1320 = false ;
V_6 -> V_556 . V_1321 = V_329 -> V_1322 ;
F_904 ( V_43 ) ;
F_900 ( V_43 ) ;
if ( V_1302 )
F_319 ( V_1323 , & V_43 -> V_1318 ) ;
else
F_888 ( V_43 ) ;
return 0 ;
}
void F_905 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_420 * V_43 ;
struct V_42 * V_62 ;
int V_267 ;
V_43 = F_722 ( V_57 ) ;
if ( ! V_43 ) {
F_157 ( L_268 ,
V_65 -> V_64 . V_372 , V_65 -> V_12 ) ;
return;
}
V_43 -> V_429 = F_801 ( V_65 ) ;
V_458:
V_62 = F_725 ( V_43 , V_65 ) ;
V_267 = F_509 ( V_62 ) ;
if ( ! V_267 ) {
if ( ! V_62 -> V_88 )
goto V_934;
V_62 -> V_421 = true ;
V_267 = F_271 ( V_43 ) ;
}
if ( V_267 == - V_271 ) {
F_802 ( V_43 ) ;
F_275 ( V_43 -> V_429 ) ;
goto V_458;
}
if ( V_267 )
V_934:
F_281 ( V_43 ) ;
}
static int F_906 ( struct V_87 * V_65 ,
T_5 * V_1324 , T_5 * V_1325 , T_5 * V_1326 ,
T_2 V_247 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_1111 * V_91 = & V_57 -> V_426 ;
struct V_42 * V_43 ;
int V_267 ;
V_267 = F_907 ( V_65 , V_1324 , V_1325 , V_1326 , V_247 ) ;
if ( V_267 )
return V_267 ;
V_43 = V_65 -> V_43 ;
F_908 ( & V_65 -> V_64 ,
V_91 -> V_1327 ,
( V_43 -> V_1328 ) ?
V_43 -> V_1328 -> V_64 . V_372 : 0 ) ;
F_908 ( & V_65 -> V_64 ,
V_91 -> V_1329 ,
( V_43 -> V_1330 ) ?
V_43 -> V_1330 -> V_64 . V_372 : 0 ) ;
F_908 ( & V_65 -> V_64 ,
V_91 -> V_1331 ,
( V_43 -> V_1332 ) ?
V_43 -> V_1332 -> V_64 . V_372 : 0 ) ;
return 0 ;
}
int
F_909 ( struct V_323 * V_140 ,
const struct V_325 * V_1268 )
{
struct V_56 * V_57 = V_140 -> V_57 ;
struct V_251 * V_90 = V_1268 -> V_90 ;
struct V_264 * V_265 = F_187 ( V_90 ) ;
struct V_264 * V_1319 = F_187 ( V_140 -> V_43 -> V_90 ) ;
struct V_1176 * V_1177 ;
int V_267 = 0 ;
if ( ! V_265 && ! V_1319 )
return 0 ;
if ( V_1319 ) {
struct V_42 * V_62 =
F_910 ( V_1268 -> V_43 , V_140 -> V_43 -> V_65 ) ;
if ( F_25 ( V_62 ) )
V_267 = F_911 ( V_1319 , true ) ;
if ( V_267 ) {
F_28 ( V_267 == - V_1194 ) ;
return V_267 ;
}
}
if ( ! V_265 )
return 0 ;
V_1177 = F_767 ( V_265 ) ;
if ( V_1177 ) {
long V_1309 ;
V_1309 = F_774 ( V_1177 , false , true ,
V_1183 ) ;
if ( V_1309 == - V_1333 )
return V_1309 ;
F_7 ( V_1309 < 0 , L_269 , V_1309 ) ;
}
if ( V_140 -> type == V_1207 &&
F_58 ( V_57 ) -> V_1334 ) {
int V_1335 = F_139 ( V_57 ) ? 16 * 1024 : 256 ;
V_267 = F_912 ( V_265 , V_1335 ) ;
if ( V_267 )
F_157 ( L_270 ) ;
} else {
V_267 = F_186 ( V_90 , V_1268 -> V_252 ) ;
}
if ( V_267 == 0 ) {
struct V_328 * V_326 =
F_214 ( V_1268 ) ;
F_737 ( & V_326 -> V_1304 ,
V_265 -> V_1179 ) ;
}
return V_267 ;
}
void
F_913 ( struct V_323 * V_140 ,
const struct V_325 * V_559 )
{
struct V_56 * V_57 = V_140 -> V_57 ;
struct V_328 * V_700 ;
struct V_264 * V_1319 = F_187 ( V_559 -> V_90 ) ;
struct V_264 * V_265 = F_187 ( V_140 -> V_43 -> V_90 ) ;
V_700 = F_214 ( V_559 ) ;
if ( ! V_265 && ! V_1319 )
return;
if ( V_1319 && ( V_140 -> type != V_1207 ||
! F_58 ( V_57 ) -> V_1334 ) )
F_196 ( V_559 -> V_90 , V_559 -> V_252 ) ;
F_737 ( & V_700 -> V_1304 , NULL ) ;
}
int
F_914 ( struct V_81 * V_81 , struct V_37 * V_62 )
{
int V_1336 ;
int V_93 , V_633 ;
if ( ! V_81 || ! V_62 -> V_64 . V_502 )
return V_1337 ;
V_93 = V_62 -> V_64 . V_92 . V_93 ;
V_633 = F_270 ( V_62 -> V_64 . V_43 ) -> V_633 ;
if ( F_44 ( ! V_93 || V_633 < V_93 ) )
return V_1337 ;
V_1336 = V_60 ( ( 1 << 16 ) * 3 - 1 , ( 1 << 8 ) * ( ( V_633 << 8 ) / V_93 ) ) ;
return V_1336 ;
}
static int
F_915 ( struct V_323 * V_140 ,
struct V_37 * V_62 ,
struct V_328 * V_43 )
{
struct V_87 * V_65 = V_43 -> V_64 . V_65 ;
struct V_251 * V_90 = V_43 -> V_64 . V_90 ;
int V_1338 = V_1337 ;
int V_1336 = V_1337 ;
bool V_1339 = false ;
if ( F_58 ( V_140 -> V_57 ) -> V_103 >= 9 ) {
if ( V_43 -> V_541 . V_320 == V_542 ) {
V_1338 = 1 ;
V_1336 = F_914 ( F_47 ( V_65 ) , V_62 ) ;
}
V_1339 = true ;
}
return F_916 ( V_140 , V_65 , V_90 , & V_43 -> V_342 ,
& V_43 -> V_346 , & V_43 -> V_1340 ,
V_43 -> V_64 . V_252 ,
V_1338 , V_1336 ,
V_1339 , true ,
& V_43 -> V_331 ) ;
}
static void F_917 ( struct V_87 * V_65 ,
struct V_42 * V_438 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_37 * V_700 =
F_265 ( V_438 ) ;
bool V_566 = F_25 ( V_65 -> V_43 ) ;
F_775 ( V_81 ) ;
if ( V_566 )
return;
if ( V_65 -> V_43 -> V_1215 || F_265 ( V_65 -> V_43 ) -> V_1288 ) {
F_412 ( V_65 -> V_43 ) ;
F_403 ( V_65 -> V_43 ) ;
}
if ( F_265 ( V_65 -> V_43 ) -> V_1288 )
F_293 ( V_81 , V_700 ) ;
else if ( F_58 ( V_57 ) -> V_103 >= 9 )
F_246 ( V_81 ) ;
}
static void F_918 ( struct V_87 * V_65 ,
struct V_42 * V_438 )
{
struct V_81 * V_81 = F_47 ( V_65 ) ;
F_776 ( V_81 , NULL ) ;
}
void F_919 ( struct V_323 * V_140 )
{
if ( ! V_140 )
return;
F_920 ( V_140 ) ;
F_215 ( F_213 ( V_140 ) ) ;
}
static struct V_323 * F_921 ( struct V_56 * V_57 ,
int V_95 )
{
struct V_327 * V_89 = NULL ;
struct V_328 * V_43 = NULL ;
const T_2 * V_1341 ;
unsigned int V_1342 ;
int V_267 ;
V_89 = F_516 ( sizeof( * V_89 ) , V_717 ) ;
if ( ! V_89 )
goto V_779;
V_43 = F_922 ( & V_89 -> V_64 ) ;
if ( ! V_43 )
goto V_779;
V_89 -> V_64 . V_43 = & V_43 -> V_64 ;
V_89 -> V_1343 = false ;
V_89 -> V_1344 = 1 ;
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
V_89 -> V_1343 = true ;
V_43 -> V_406 = - 1 ;
}
V_89 -> V_95 = V_95 ;
V_89 -> V_140 = V_95 ;
V_89 -> V_350 = F_923 ( V_95 ) ;
V_89 -> V_1345 = F_915 ;
if ( F_924 ( V_57 ) && F_58 ( V_57 ) -> V_103 < 4 )
V_89 -> V_140 = ! V_95 ;
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
V_1341 = V_1346 ;
V_1342 = F_176 ( V_1346 ) ;
V_89 -> V_419 = F_250 ;
V_89 -> V_333 = F_260 ;
} else if ( F_15 ( V_57 ) ) {
V_1341 = V_1347 ;
V_1342 = F_176 ( V_1347 ) ;
V_89 -> V_419 = F_233 ;
V_89 -> V_333 = F_232 ;
} else if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
V_1341 = V_1347 ;
V_1342 = F_176 ( V_1347 ) ;
V_89 -> V_419 = F_220 ;
V_89 -> V_333 = F_232 ;
} else {
V_1341 = V_1348 ;
V_1342 = F_176 ( V_1348 ) ;
V_89 -> V_419 = F_220 ;
V_89 -> V_333 = F_232 ;
}
if ( F_58 ( V_57 ) -> V_103 >= 9 )
V_267 = F_925 ( V_57 , & V_89 -> V_64 , 0 ,
& V_1349 ,
V_1341 , V_1342 ,
V_1350 ,
L_271 , F_76 ( V_95 ) ) ;
else if ( F_58 ( V_57 ) -> V_103 >= 5 || F_18 ( V_57 ) )
V_267 = F_925 ( V_57 , & V_89 -> V_64 , 0 ,
& V_1349 ,
V_1341 , V_1342 ,
V_1350 ,
L_272 , F_76 ( V_95 ) ) ;
else
V_267 = F_925 ( V_57 , & V_89 -> V_64 , 0 ,
& V_1349 ,
V_1341 , V_1342 ,
V_1350 ,
L_273 , F_87 ( V_89 -> V_140 ) ) ;
if ( V_267 )
goto V_779;
if ( F_58 ( V_57 ) -> V_103 >= 4 )
F_926 ( V_57 , V_89 ) ;
F_927 ( & V_89 -> V_64 , & V_1351 ) ;
return & V_89 -> V_64 ;
V_779:
F_215 ( V_43 ) ;
F_215 ( V_89 ) ;
return NULL ;
}
void F_926 ( struct V_56 * V_57 , struct V_327 * V_140 )
{
if ( ! V_57 -> V_426 . V_1352 ) {
unsigned long V_320 = F_226 ( V_393 ) |
F_226 ( V_361 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 9 )
V_320 |= F_226 ( V_394 ) | F_226 ( V_397 ) ;
V_57 -> V_426 . V_1352 =
F_928 ( V_57 , V_320 ) ;
}
if ( V_57 -> V_426 . V_1352 )
F_929 ( & V_140 -> V_64 . V_64 ,
V_57 -> V_426 . V_1352 ,
V_140 -> V_64 . V_43 -> V_252 ) ;
}
static int
F_930 ( struct V_323 * V_140 ,
struct V_37 * V_62 ,
struct V_328 * V_43 )
{
struct V_87 * V_65 = V_62 -> V_64 . V_65 ;
struct V_251 * V_90 = V_43 -> V_64 . V_90 ;
struct V_264 * V_265 = F_187 ( V_90 ) ;
enum V_95 V_95 = F_213 ( V_140 ) -> V_95 ;
unsigned V_319 ;
int V_267 ;
V_267 = F_916 ( V_140 , V_65 , V_90 , & V_43 -> V_342 ,
& V_43 -> V_346 , & V_43 -> V_1340 ,
V_43 -> V_64 . V_252 ,
V_1337 ,
V_1337 ,
true , true , & V_43 -> V_331 ) ;
if ( V_267 )
return V_267 ;
if ( ! V_265 )
return 0 ;
if ( ! F_698 ( V_140 -> V_57 , V_43 -> V_64 . V_340 , V_43 -> V_64 . V_341 ) ) {
F_931 ( L_274 ,
V_43 -> V_64 . V_340 , V_43 -> V_64 . V_341 ) ;
return - V_537 ;
}
V_319 = F_692 ( V_43 -> V_64 . V_340 ) * 4 ;
if ( V_265 -> V_64 . V_247 < V_319 * V_43 -> V_64 . V_341 ) {
F_157 ( L_275 ) ;
return - V_716 ;
}
if ( V_90 -> V_259 [ 0 ] != V_236 ) {
F_157 ( L_276 ) ;
return - V_537 ;
}
if ( F_17 ( V_140 -> V_57 ) && V_95 == V_505 &&
V_43 -> V_331 && V_43 -> V_64 . V_338 < 0 ) {
F_157 ( L_277 ) ;
return - V_537 ;
}
return 0 ;
}
static void
F_932 ( struct V_323 * V_140 ,
struct V_87 * V_65 )
{
struct V_81 * V_81 = F_47 ( V_65 ) ;
V_81 -> V_1101 = 0 ;
F_696 ( V_65 , NULL ) ;
}
static void
F_933 ( struct V_323 * V_140 ,
const struct V_37 * V_62 ,
const struct V_328 * V_43 )
{
struct V_87 * V_65 = V_62 -> V_64 . V_65 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_56 * V_57 = V_140 -> V_57 ;
struct V_264 * V_265 = F_187 ( V_43 -> V_64 . V_90 ) ;
T_2 V_1184 ;
if ( ! V_265 )
V_1184 = 0 ;
else if ( ! F_58 ( V_57 ) -> V_1334 )
V_1184 = F_217 ( V_265 ) ;
else
V_1184 = V_265 -> V_1353 -> V_1354 ;
V_81 -> V_1101 = V_1184 ;
F_696 ( V_65 , V_43 ) ;
}
static struct V_323 * F_934 ( struct V_56 * V_57 ,
int V_95 )
{
struct V_327 * V_1355 = NULL ;
struct V_328 * V_43 = NULL ;
int V_267 ;
V_1355 = F_516 ( sizeof( * V_1355 ) , V_717 ) ;
if ( ! V_1355 )
goto V_779;
V_43 = F_922 ( & V_1355 -> V_64 ) ;
if ( ! V_43 )
goto V_779;
V_1355 -> V_64 . V_43 = & V_43 -> V_64 ;
V_1355 -> V_1343 = false ;
V_1355 -> V_1344 = 1 ;
V_1355 -> V_95 = V_95 ;
V_1355 -> V_140 = V_95 ;
V_1355 -> V_350 = F_935 ( V_95 ) ;
V_1355 -> V_1345 = F_930 ;
V_1355 -> V_419 = F_933 ;
V_1355 -> V_333 = F_932 ;
V_267 = F_925 ( V_57 , & V_1355 -> V_64 , 0 ,
& V_1349 ,
V_1356 ,
F_176 ( V_1356 ) ,
V_1207 ,
L_278 , F_76 ( V_95 ) ) ;
if ( V_267 )
goto V_779;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
if ( ! V_57 -> V_426 . V_1352 )
V_57 -> V_426 . V_1352 =
F_928 ( V_57 ,
F_226 ( V_393 ) |
F_226 ( V_361 ) ) ;
if ( V_57 -> V_426 . V_1352 )
F_929 ( & V_1355 -> V_64 . V_64 ,
V_57 -> V_426 . V_1352 ,
V_43 -> V_64 . V_252 ) ;
}
if ( F_58 ( V_57 ) -> V_103 >= 9 )
V_43 -> V_406 = - 1 ;
F_927 ( & V_1355 -> V_64 , & V_1351 ) ;
return & V_1355 -> V_64 ;
V_779:
F_215 ( V_43 ) ;
F_215 ( V_1355 ) ;
return NULL ;
}
static void F_690 ( struct V_56 * V_57 , struct V_81 * V_81 ,
struct V_37 * V_62 )
{
int V_142 ;
struct V_1357 * V_1357 ;
struct V_373 * V_374 = & V_62 -> V_374 ;
for ( V_142 = 0 ; V_142 < V_81 -> V_375 ; V_142 ++ ) {
V_1357 = & V_374 -> V_376 [ V_142 ] ;
V_1357 -> V_377 = 0 ;
V_1357 -> V_416 = V_1358 ;
}
V_374 -> V_406 = - 1 ;
}
static void F_936 ( struct V_56 * V_57 , int V_95 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 ;
struct V_37 * V_62 = NULL ;
struct V_323 * V_89 = NULL ;
struct V_323 * V_1355 = NULL ;
int V_267 ;
V_81 = F_516 ( sizeof( * V_81 ) , V_717 ) ;
if ( V_81 == NULL )
return;
V_62 = F_516 ( sizeof( * V_62 ) , V_717 ) ;
if ( ! V_62 )
goto V_779;
V_81 -> V_91 = V_62 ;
V_81 -> V_64 . V_43 = & V_62 -> V_64 ;
V_62 -> V_64 . V_65 = & V_81 -> V_64 ;
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
if ( V_95 == V_505 )
V_81 -> V_375 = 1 ;
else
V_81 -> V_375 = V_1359 ;
F_690 ( V_57 , V_81 , V_62 ) ;
}
V_89 = F_921 ( V_57 , V_95 ) ;
if ( ! V_89 )
goto V_779;
V_1355 = F_934 ( V_57 , V_95 ) ;
if ( ! V_1355 )
goto V_779;
V_267 = F_937 ( V_57 , & V_81 -> V_64 , V_89 ,
V_1355 , & V_1360 ,
L_279 , F_76 ( V_95 ) ) ;
if ( V_267 )
goto V_779;
V_81 -> V_95 = V_95 ;
V_81 -> V_140 = V_95 ;
if ( F_924 ( V_57 ) && F_58 ( V_57 ) -> V_103 < 4 ) {
F_157 ( L_280 ) ;
V_81 -> V_140 = ! V_95 ;
}
V_81 -> V_1092 = ~ 0 ;
V_81 -> V_1091 = ~ 0 ;
V_81 -> V_1093 = ~ 0 ;
V_81 -> V_556 . V_562 = true ;
F_627 ( V_95 >= F_176 ( V_6 -> V_1361 ) ||
V_6 -> V_1361 [ V_81 -> V_140 ] != NULL ) ;
V_6 -> V_1361 [ V_81 -> V_140 ] = & V_81 -> V_64 ;
V_6 -> V_96 [ V_81 -> V_95 ] = & V_81 -> V_64 ;
F_938 ( & V_81 -> V_64 , & V_1362 ) ;
F_939 ( & V_81 -> V_64 ) ;
F_28 ( F_857 ( & V_81 -> V_64 ) != V_81 -> V_95 ) ;
return;
V_779:
F_919 ( V_89 ) ;
F_919 ( V_1355 ) ;
F_215 ( V_62 ) ;
F_215 ( V_81 ) ;
}
enum V_95 F_940 ( struct V_710 * V_711 )
{
struct V_608 * V_507 = V_711 -> V_64 . V_507 ;
struct V_56 * V_57 = V_711 -> V_64 . V_57 ;
F_28 ( ! F_941 ( & V_57 -> V_426 . V_1114 ) ) ;
if ( ! V_507 || F_28 ( ! V_507 -> V_65 ) )
return V_579 ;
return F_47 ( V_507 -> V_65 ) -> V_95 ;
}
int F_942 ( struct V_56 * V_57 , void * V_1042 ,
struct V_1363 * V_1364 )
{
struct V_1365 * V_1366 = V_1042 ;
struct V_87 * V_1367 ;
struct V_81 * V_65 ;
V_1367 = F_943 ( V_57 , V_1366 -> V_1368 ) ;
if ( ! V_1367 )
return - V_1369 ;
V_65 = F_47 ( V_1367 ) ;
V_1366 -> V_95 = V_65 -> V_95 ;
return 0 ;
}
static int F_944 ( struct V_506 * V_507 )
{
struct V_56 * V_57 = V_507 -> V_64 . V_57 ;
struct V_506 * V_1213 ;
int V_1370 = 0 ;
int V_1371 = 0 ;
F_625 (dev, source_encoder) {
if ( F_807 ( V_507 , V_1213 ) )
V_1370 |= ( 1 << V_1371 ) ;
V_1371 ++ ;
}
return V_1370 ;
}
static bool F_945 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( ! F_138 ( V_57 ) )
return false ;
if ( ( F_11 ( V_1372 ) & V_1373 ) == 0 )
return false ;
if ( F_24 ( V_57 ) && ( F_11 ( V_625 ) & V_1374 ) )
return false ;
return true ;
}
static bool F_946 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 9 )
return false ;
if ( F_537 ( V_57 ) || F_446 ( V_57 ) )
return false ;
if ( F_17 ( V_57 ) )
return false ;
if ( F_947 ( V_57 ) && F_11 ( V_1375 ) & V_1376 )
return false ;
if ( F_23 ( V_57 ) && F_11 ( F_948 ( V_590 ) ) & V_1377 )
return false ;
if ( ! V_6 -> V_798 . V_1378 )
return false ;
return true ;
}
static void F_949 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_506 * V_507 ;
bool V_1379 = false ;
F_950 ( V_57 ) ;
if ( F_946 ( V_57 ) )
F_951 ( V_57 ) ;
if ( F_36 ( V_57 ) ) {
F_952 ( V_57 , V_590 ) ;
F_952 ( V_57 , V_203 ) ;
F_952 ( V_57 , V_205 ) ;
F_953 ( V_57 ) ;
} else if ( F_23 ( V_57 ) ) {
int V_75 ;
V_75 = F_11 ( F_948 ( V_590 ) ) & V_1380 ;
if ( V_75 || F_442 ( V_57 ) || F_443 ( V_57 ) )
F_952 ( V_57 , V_590 ) ;
V_75 = F_11 ( V_1375 ) ;
if ( V_75 & V_1381 )
F_952 ( V_57 , V_203 ) ;
if ( V_75 & V_1382 )
F_952 ( V_57 , V_205 ) ;
if ( V_75 & V_1383 )
F_952 ( V_57 , V_207 ) ;
if ( ( F_442 ( V_57 ) || F_443 ( V_57 ) ) &&
( V_6 -> V_798 . V_1384 [ V_595 ] . V_1385 ||
V_6 -> V_798 . V_1384 [ V_595 ] . V_1386 ||
V_6 -> V_798 . V_1384 [ V_595 ] . V_1387 ) )
F_952 ( V_57 , V_595 ) ;
} else if ( F_15 ( V_57 ) ) {
int V_75 ;
V_1379 = F_954 ( V_57 , V_207 ) ;
if ( F_945 ( V_57 ) )
F_955 ( V_57 , V_1372 , V_590 ) ;
if ( F_11 ( V_176 ) & V_1388 ) {
V_75 = F_956 ( V_57 , V_1389 , V_203 ) ;
if ( ! V_75 )
F_957 ( V_57 , V_176 , V_203 ) ;
if ( ! V_75 && ( F_11 ( V_169 ) & V_1373 ) )
F_955 ( V_57 , V_169 , V_203 ) ;
}
if ( F_11 ( V_177 ) & V_1388 )
F_957 ( V_57 , V_177 , V_205 ) ;
if ( ! V_1379 && F_11 ( V_178 ) & V_1388 )
F_957 ( V_57 , V_178 , V_207 ) ;
if ( F_11 ( V_171 ) & V_1373 )
F_955 ( V_57 , V_171 , V_205 ) ;
if ( F_11 ( V_173 ) & V_1373 )
F_955 ( V_57 , V_173 , V_207 ) ;
} else if ( F_16 ( V_57 ) || F_17 ( V_57 ) ) {
bool V_1390 , V_1391 ;
V_1390 = F_954 ( V_57 , V_203 ) ;
V_1391 = F_958 ( V_6 , V_203 ) ;
if ( F_11 ( V_1392 ) & V_1373 || V_1391 )
V_1390 &= F_955 ( V_57 , V_1392 , V_203 ) ;
if ( ( F_11 ( V_1393 ) & V_1388 || V_1391 ) && ! V_1390 )
F_957 ( V_57 , V_1393 , V_203 ) ;
V_1390 = F_954 ( V_57 , V_205 ) ;
V_1391 = F_958 ( V_6 , V_205 ) ;
if ( F_11 ( V_1394 ) & V_1373 || V_1391 )
V_1390 &= F_955 ( V_57 , V_1394 , V_205 ) ;
if ( ( F_11 ( V_1395 ) & V_1388 || V_1391 ) && ! V_1390 )
F_957 ( V_57 , V_1395 , V_205 ) ;
if ( F_17 ( V_57 ) ) {
V_1391 = F_958 ( V_6 , V_207 ) ;
if ( F_11 ( V_1396 ) & V_1373 || V_1391 )
F_955 ( V_57 , V_1396 , V_207 ) ;
if ( F_11 ( V_1397 ) & V_1388 || V_1391 )
F_957 ( V_57 , V_1397 , V_207 ) ;
}
F_953 ( V_57 ) ;
} else if ( ! F_55 ( V_57 ) && ! F_19 ( V_57 ) ) {
bool V_75 = false ;
if ( F_11 ( V_1398 ) & V_1388 ) {
F_157 ( L_281 ) ;
V_75 = F_956 ( V_57 , V_1398 , V_203 ) ;
if ( ! V_75 && F_18 ( V_57 ) ) {
F_157 ( L_282 ) ;
F_957 ( V_57 , V_1399 , V_203 ) ;
}
if ( ! V_75 && F_18 ( V_57 ) )
F_955 ( V_57 , V_1400 , V_203 ) ;
}
if ( F_11 ( V_1398 ) & V_1388 ) {
F_157 ( L_283 ) ;
V_75 = F_956 ( V_57 , V_1401 , V_205 ) ;
}
if ( ! V_75 && ( F_11 ( V_1401 ) & V_1388 ) ) {
if ( F_18 ( V_57 ) ) {
F_157 ( L_284 ) ;
F_957 ( V_57 , V_1402 , V_205 ) ;
}
if ( F_18 ( V_57 ) )
F_955 ( V_57 , V_1403 , V_205 ) ;
}
if ( F_18 ( V_57 ) &&
( F_11 ( V_1404 ) & V_1373 ) )
F_955 ( V_57 , V_1404 , V_207 ) ;
} else if ( F_55 ( V_57 ) )
F_959 ( V_57 ) ;
if ( F_960 ( V_57 ) )
F_961 ( V_57 ) ;
F_962 ( V_57 ) ;
F_625 (dev, encoder) {
V_507 -> V_64 . V_1115 = V_507 -> V_1283 ;
V_507 -> V_64 . V_1405 =
F_944 ( V_507 ) ;
}
F_637 ( V_57 ) ;
F_963 ( V_57 ) ;
}
static void F_964 ( struct V_251 * V_90 )
{
struct V_56 * V_57 = V_90 -> V_57 ;
struct V_926 * V_927 = F_179 ( V_90 ) ;
F_965 ( V_90 ) ;
F_3 ( & V_57 -> V_268 ) ;
F_28 ( ! V_927 -> V_265 -> V_1406 -- ) ;
F_208 ( & V_927 -> V_265 -> V_64 ) ;
F_5 ( & V_57 -> V_268 ) ;
F_215 ( V_927 ) ;
}
static int F_966 ( struct V_251 * V_90 ,
struct V_1363 * V_1364 ,
unsigned int * V_1407 )
{
struct V_926 * V_927 = F_179 ( V_90 ) ;
struct V_264 * V_265 = V_927 -> V_265 ;
if ( V_265 -> V_1408 . V_554 ) {
F_931 ( L_285 ) ;
return - V_537 ;
}
return F_967 ( V_1364 , & V_265 -> V_64 , V_1407 ) ;
}
static int F_968 ( struct V_251 * V_90 ,
struct V_1363 * V_1364 ,
unsigned V_320 , unsigned V_1409 ,
struct V_1410 * V_1411 ,
unsigned V_1412 )
{
struct V_56 * V_57 = V_90 -> V_57 ;
struct V_926 * V_927 = F_179 ( V_90 ) ;
struct V_264 * V_265 = V_927 -> V_265 ;
F_3 ( & V_57 -> V_268 ) ;
F_969 ( V_265 , false , V_1413 ) ;
F_5 ( & V_57 -> V_268 ) ;
return 0 ;
}
static
T_1 F_970 ( struct V_56 * V_57 , V_55 V_234 ,
T_2 V_244 )
{
T_1 V_103 = F_58 ( V_57 ) -> V_103 ;
if ( V_103 >= 9 ) {
int V_235 = F_173 ( V_244 , 0 ) ;
return V_60 ( 8192 * V_235 , 32768 ) ;
} else if ( V_103 >= 5 && ! F_16 ( V_57 ) && ! F_17 ( V_57 ) ) {
return 32 * 1024 ;
} else if ( V_103 >= 4 ) {
if ( V_234 == V_237 )
return 16 * 1024 ;
else
return 32 * 1024 ;
} else if ( V_103 >= 3 ) {
if ( V_234 == V_237 )
return 8 * 1024 ;
else
return 16 * 1024 ;
} else {
return 8 * 1024 ;
}
}
static int F_207 ( struct V_56 * V_57 ,
struct V_926 * V_927 ,
struct V_310 * V_311 ,
struct V_264 * V_265 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
unsigned int V_925 ;
int V_267 ;
T_1 V_1414 , V_1415 ;
F_28 ( ! F_188 ( & V_57 -> V_268 ) ) ;
if ( V_311 -> V_320 & V_321 ) {
if ( ! ! ( V_265 -> V_316 == V_318 ) !=
! ! ( V_311 -> V_259 [ 0 ] == V_237 ) ) {
F_931 ( L_286 ) ;
return - V_537 ;
}
} else {
if ( V_265 -> V_316 == V_318 )
V_311 -> V_259 [ 0 ] = V_237 ;
else if ( V_265 -> V_316 == V_1416 ) {
F_931 ( L_287 ) ;
return - V_537 ;
}
}
switch ( V_311 -> V_259 [ 0 ] ) {
case V_238 :
case V_239 :
if ( F_58 ( V_57 ) -> V_103 < 9 ) {
F_931 ( L_288 ,
V_311 -> V_259 [ 0 ] ) ;
return - V_537 ;
}
case V_236 :
case V_237 :
break;
default:
F_931 ( L_289 ,
V_311 -> V_259 [ 0 ] ) ;
return - V_537 ;
}
V_1415 = F_237 ( V_6 ,
V_311 -> V_259 [ 0 ] ,
V_311 -> V_244 ) ;
if ( V_311 -> V_260 [ 0 ] & ( V_1415 - 1 ) ) {
F_931 ( L_290 ,
V_311 -> V_260 [ 0 ] , V_1415 ) ;
return - V_537 ;
}
V_1414 = F_970 ( V_57 , V_311 -> V_259 [ 0 ] ,
V_311 -> V_244 ) ;
if ( V_311 -> V_260 [ 0 ] > V_1414 ) {
F_931 ( L_291 ,
V_311 -> V_259 [ 0 ] != V_236 ?
L_292 : L_293 ,
V_311 -> V_260 [ 0 ] , V_1414 ) ;
return - V_537 ;
}
if ( V_311 -> V_259 [ 0 ] == V_237 &&
V_311 -> V_260 [ 0 ] != V_265 -> V_319 ) {
F_931 ( L_294 ,
V_311 -> V_260 [ 0 ] , V_265 -> V_319 ) ;
return - V_537 ;
}
switch ( V_311 -> V_244 ) {
case V_286 :
case V_290 :
case V_292 :
case V_304 :
break;
case V_288 :
if ( F_58 ( V_57 ) -> V_103 > 3 ) {
F_931 ( L_295 ,
F_825 ( V_311 -> V_244 ) ) ;
return - V_537 ;
}
break;
case V_303 :
if ( ! F_16 ( V_57 ) && ! F_17 ( V_57 ) &&
F_58 ( V_57 ) -> V_103 < 9 ) {
F_931 ( L_295 ,
F_825 ( V_311 -> V_244 ) ) ;
return - V_537 ;
}
break;
case V_294 :
case V_296 :
case V_298 :
if ( F_58 ( V_57 ) -> V_103 < 4 ) {
F_931 ( L_295 ,
F_825 ( V_311 -> V_244 ) ) ;
return - V_537 ;
}
break;
case V_1417 :
if ( ! F_16 ( V_57 ) && ! F_17 ( V_57 ) ) {
F_931 ( L_295 ,
F_825 ( V_311 -> V_244 ) ) ;
return - V_537 ;
}
break;
case V_381 :
case V_386 :
case V_384 :
case V_388 :
if ( F_58 ( V_57 ) -> V_103 < 5 ) {
F_931 ( L_295 ,
F_825 ( V_311 -> V_244 ) ) ;
return - V_537 ;
}
break;
default:
F_931 ( L_295 ,
F_825 ( V_311 -> V_244 ) ) ;
return - V_537 ;
}
if ( V_311 -> V_263 [ 0 ] != 0 )
return - V_537 ;
V_925 = F_172 ( V_57 , V_311 -> V_243 ,
V_311 -> V_244 ,
V_311 -> V_259 [ 0 ] ) ;
if ( V_265 -> V_64 . V_247 < V_925 * V_311 -> V_260 [ 0 ] )
return - V_537 ;
F_971 ( & V_927 -> V_64 , V_311 ) ;
V_927 -> V_265 = V_265 ;
F_180 ( V_6 , & V_927 -> V_64 ) ;
V_267 = F_972 ( V_57 , & V_927 -> V_64 , & V_1418 ) ;
if ( V_267 ) {
F_125 ( L_296 , V_267 ) ;
return V_267 ;
}
V_927 -> V_265 -> V_1406 ++ ;
return 0 ;
}
static struct V_251 *
F_973 ( struct V_56 * V_57 ,
struct V_1363 * V_1419 ,
const struct V_310 * V_1420 )
{
struct V_251 * V_90 ;
struct V_264 * V_265 ;
struct V_310 V_311 = * V_1420 ;
V_265 = F_974 ( F_975 ( V_1419 , V_311 . V_1421 [ 0 ] ) ) ;
if ( & V_265 -> V_64 == NULL )
return F_700 ( - V_1369 ) ;
V_90 = F_701 ( V_57 , & V_311 , V_265 ) ;
if ( F_278 ( V_90 ) )
F_710 ( & V_265 -> V_64 ) ;
return V_90 ;
}
static inline void F_976 ( struct V_56 * V_57 )
{
}
void F_977 ( struct V_5 * V_6 )
{
if ( F_58 ( V_6 ) -> V_103 >= 9 ) {
V_6 -> V_431 . V_1281 = F_688 ;
V_6 -> V_431 . V_1422 =
F_648 ;
V_6 -> V_431 . V_1214 =
F_673 ;
V_6 -> V_431 . V_1317 = F_407 ;
V_6 -> V_431 . V_707 = F_420 ;
} else if ( F_23 ( V_6 ) ) {
V_6 -> V_431 . V_1281 = F_688 ;
V_6 -> V_431 . V_1422 =
F_651 ;
V_6 -> V_431 . V_1214 =
F_673 ;
V_6 -> V_431 . V_1317 = F_407 ;
V_6 -> V_431 . V_707 = F_420 ;
} else if ( F_15 ( V_6 ) ) {
V_6 -> V_431 . V_1281 = F_652 ;
V_6 -> V_431 . V_1422 =
F_651 ;
V_6 -> V_431 . V_1214 =
F_641 ;
V_6 -> V_431 . V_1317 = F_395 ;
V_6 -> V_431 . V_707 = F_418 ;
} else if ( F_17 ( V_6 ) ) {
V_6 -> V_431 . V_1281 = F_622 ;
V_6 -> V_431 . V_1422 =
F_620 ;
V_6 -> V_431 . V_1214 = F_616 ;
V_6 -> V_431 . V_1317 = F_491 ;
V_6 -> V_431 . V_707 = F_502 ;
} else if ( F_16 ( V_6 ) ) {
V_6 -> V_431 . V_1281 = F_622 ;
V_6 -> V_431 . V_1422 =
F_620 ;
V_6 -> V_431 . V_1214 = F_617 ;
V_6 -> V_431 . V_1317 = F_491 ;
V_6 -> V_431 . V_707 = F_502 ;
} else if ( F_18 ( V_6 ) ) {
V_6 -> V_431 . V_1281 = F_622 ;
V_6 -> V_431 . V_1422 =
F_620 ;
V_6 -> V_431 . V_1214 = F_613 ;
V_6 -> V_431 . V_1317 = F_500 ;
V_6 -> V_431 . V_707 = F_502 ;
} else if ( F_19 ( V_6 ) ) {
V_6 -> V_431 . V_1281 = F_622 ;
V_6 -> V_431 . V_1422 =
F_620 ;
V_6 -> V_431 . V_1214 = F_614 ;
V_6 -> V_431 . V_1317 = F_500 ;
V_6 -> V_431 . V_707 = F_502 ;
} else if ( ! F_55 ( V_6 ) ) {
V_6 -> V_431 . V_1281 = F_622 ;
V_6 -> V_431 . V_1422 =
F_620 ;
V_6 -> V_431 . V_1214 = F_615 ;
V_6 -> V_431 . V_1317 = F_500 ;
V_6 -> V_431 . V_707 = F_502 ;
} else {
V_6 -> V_431 . V_1281 = F_622 ;
V_6 -> V_431 . V_1422 =
F_620 ;
V_6 -> V_431 . V_1214 = F_612 ;
V_6 -> V_431 . V_1317 = F_500 ;
V_6 -> V_431 . V_707 = F_502 ;
}
if ( F_442 ( V_6 ) || F_443 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_532 ;
else if ( F_36 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_534 ;
else if ( F_235 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_535 ;
else if ( F_234 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_536 ;
else if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_538 ;
else if ( F_24 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_539 ;
else if ( F_602 ( V_6 ) || F_183 ( V_6 ) ||
F_308 ( V_6 ) || F_299 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_540 ;
else if ( F_552 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_554 ;
else if ( F_184 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_555 ;
else if ( F_19 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_543 ;
else if ( F_553 ( V_6 ) || F_18 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_556 ;
else if ( F_529 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_541 ;
else if ( F_603 ( V_6 ) || F_78 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_542 ;
else if ( F_978 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_545 ;
else if ( F_79 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_546 ;
else if ( F_979 ( V_6 ) )
V_6 -> V_431 . V_629 =
F_547 ;
else {
F_7 ( ! F_139 ( V_6 ) , L_297 ) ;
V_6 -> V_431 . V_629 =
F_550 ;
}
if ( F_24 ( V_6 ) ) {
V_6 -> V_431 . V_511 = F_300 ;
} else if ( F_308 ( V_6 ) ) {
V_6 -> V_431 . V_511 = F_306 ;
} else if ( F_299 ( V_6 ) ) {
V_6 -> V_431 . V_511 = F_309 ;
} else if ( F_234 ( V_6 ) || F_235 ( V_6 ) ) {
V_6 -> V_431 . V_511 = V_1423 ;
}
if ( F_235 ( V_6 ) ) {
V_6 -> V_431 . V_1316 =
F_670 ;
V_6 -> V_431 . V_1296 =
F_669 ;
} else if ( F_16 ( V_6 ) || F_17 ( V_6 ) ) {
V_6 -> V_431 . V_1316 =
F_490 ;
V_6 -> V_431 . V_1296 =
F_485 ;
} else if ( F_36 ( V_6 ) ) {
V_6 -> V_431 . V_1316 =
F_666 ;
V_6 -> V_431 . V_1296 =
F_486 ;
} else if ( F_442 ( V_6 ) || F_443 ( V_6 ) ) {
V_6 -> V_431 . V_1316 =
F_672 ;
V_6 -> V_431 . V_1296 =
F_671 ;
}
switch ( F_58 ( V_6 ) -> V_103 ) {
case 2 :
V_6 -> V_431 . V_1197 = F_754 ;
break;
case 3 :
V_6 -> V_431 . V_1197 = F_758 ;
break;
case 4 :
case 5 :
V_6 -> V_431 . V_1197 = F_759 ;
break;
case 6 :
V_6 -> V_431 . V_1197 = F_760 ;
break;
case 7 :
case 8 :
V_6 -> V_431 . V_1197 = F_761 ;
break;
case 9 :
default:
V_6 -> V_431 . V_1197 = F_777 ;
}
}
static void F_980 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
V_6 -> V_136 |= V_137 ;
F_981 ( L_298 ) ;
}
static void F_982 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
V_6 -> V_136 |= V_138 ;
F_981 ( L_299 ) ;
}
static void F_983 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
V_6 -> V_136 |= V_800 ;
F_981 ( L_300 ) ;
}
static void F_984 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
V_6 -> V_136 |= V_1424 ;
F_981 ( L_301 ) ;
}
static void F_985 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
V_6 -> V_136 |= V_1425 ;
F_981 ( L_302 ) ;
}
static int F_986 ( const struct V_1426 * V_372 )
{
F_981 ( L_303 , V_372 -> V_1427 ) ;
return 1 ;
}
static void F_987 ( struct V_56 * V_57 )
{
struct V_1428 * V_1429 = V_57 -> V_741 ;
int V_142 ;
for ( V_142 = 0 ; V_142 < F_176 ( V_1430 ) ; V_142 ++ ) {
struct V_1431 * V_1432 = & V_1430 [ V_142 ] ;
if ( V_1429 -> V_1433 == V_1432 -> V_1433 &&
( V_1429 -> V_1434 == V_1432 -> V_1434 ||
V_1432 -> V_1434 == V_1435 ) &&
( V_1429 -> V_1436 == V_1432 -> V_1436 ||
V_1432 -> V_1436 == V_1435 ) )
V_1432 -> V_1437 ( V_57 ) ;
}
for ( V_142 = 0 ; V_142 < F_176 ( V_1438 ) ; V_142 ++ ) {
if ( F_988 ( * V_1438 [ V_142 ] . V_1439 ) != 0 )
V_1438 [ V_142 ] . V_1437 ( V_57 ) ;
}
}
static void F_989 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_11 V_1440 ;
T_3 V_1441 = F_990 ( V_57 ) ;
F_991 ( V_57 -> V_741 , V_1442 ) ;
F_992 ( V_1443 , V_1444 ) ;
V_1440 = F_993 ( V_1445 ) ;
F_992 ( V_1440 | 1 << 5 , V_1445 ) ;
F_994 ( V_57 -> V_741 , V_1442 ) ;
F_124 ( 300 ) ;
F_122 ( V_1441 , V_1446 ) ;
F_123 ( V_1441 ) ;
}
void F_285 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
F_447 ( V_57 ) ;
V_6 -> V_1297 = V_6 -> V_627 ;
F_995 ( V_57 ) ;
F_996 ( V_6 ) ;
}
static void F_997 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_420 * V_43 ;
struct V_87 * V_65 ;
struct V_42 * V_1039 ;
struct V_423 V_424 ;
int V_267 ;
int V_142 ;
if ( ! V_6 -> V_431 . V_1209 )
return;
F_273 ( & V_424 , 0 ) ;
V_458:
V_267 = F_274 ( V_57 , & V_424 ) ;
if ( V_267 == - V_271 ) {
F_275 ( & V_424 ) ;
goto V_458;
} else if ( F_28 ( V_267 ) ) {
goto V_779;
}
V_43 = F_277 ( V_57 , & V_424 ) ;
if ( F_28 ( F_278 ( V_43 ) ) )
goto V_779;
F_270 ( V_43 ) -> V_422 = true ;
V_267 = F_873 ( V_57 , V_43 ) ;
if ( V_267 ) {
F_7 ( true , L_304 ) ;
goto V_779;
}
F_269 (state, crtc, cstate, i) {
struct V_37 * V_1447 = F_265 ( V_1039 ) ;
V_1447 -> V_556 . V_1210 = true ;
V_6 -> V_431 . V_1209 ( V_1447 ) ;
}
F_281 ( V_43 ) ;
V_779:
F_289 ( & V_424 ) ;
F_290 ( & V_424 ) ;
}
void F_998 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_308 * V_309 = & V_6 -> V_309 ;
int V_146 , V_267 ;
enum V_95 V_95 ;
struct V_81 * V_65 ;
F_999 ( V_57 ) ;
V_57 -> V_426 . V_1448 = 0 ;
V_57 -> V_426 . V_1449 = 0 ;
V_57 -> V_426 . V_1450 = 24 ;
V_57 -> V_426 . V_1451 = 1 ;
V_57 -> V_426 . V_1452 = true ;
V_57 -> V_426 . V_1008 = & V_1453 ;
F_987 ( V_57 ) ;
F_1000 ( V_57 ) ;
if ( F_58 ( V_57 ) -> V_720 == 0 )
return;
if ( F_118 ( V_57 ) || F_104 ( V_57 ) ) {
bool V_1454 = ! ! ( F_11 ( V_947 ) &
V_953 ) ;
if ( V_6 -> V_798 . V_799 != V_1454 ) {
F_157 ( L_305 ,
V_1454 ? L_70 : L_71 ,
V_6 -> V_798 . V_799 ? L_70 : L_71 ) ;
V_6 -> V_798 . V_799 = V_1454 ;
}
}
if ( F_55 ( V_57 ) ) {
V_57 -> V_426 . V_1455 = 2048 ;
V_57 -> V_426 . V_1456 = 2048 ;
} else if ( F_1001 ( V_57 ) ) {
V_57 -> V_426 . V_1455 = 4096 ;
V_57 -> V_426 . V_1456 = 4096 ;
} else {
V_57 -> V_426 . V_1455 = 8192 ;
V_57 -> V_426 . V_1456 = 8192 ;
}
if ( F_78 ( V_57 ) || F_79 ( V_57 ) ) {
V_57 -> V_426 . V_1457 = F_78 ( V_57 ) ? 64 : 512 ;
V_57 -> V_426 . V_1458 = 1023 ;
} else if ( F_55 ( V_57 ) ) {
V_57 -> V_426 . V_1457 = V_1459 ;
V_57 -> V_426 . V_1458 = V_1460 ;
} else {
V_57 -> V_426 . V_1457 = V_1461 ;
V_57 -> V_426 . V_1458 = V_1462 ;
}
V_57 -> V_426 . V_1463 = V_309 -> V_1464 ;
F_157 ( L_306 ,
F_58 ( V_57 ) -> V_720 ,
F_58 ( V_57 ) -> V_720 > 1 ? L_307 : L_308 ) ;
F_89 (dev_priv, pipe) {
F_936 ( V_57 , V_95 ) ;
F_91 (dev_priv, pipe, sprite) {
V_267 = F_1002 ( V_57 , V_95 , V_146 ) ;
if ( V_267 )
F_157 ( L_309 ,
F_76 ( V_95 ) , F_94 ( V_95 , V_146 ) , V_267 ) ;
}
}
F_21 ( V_6 ) ;
F_447 ( V_57 ) ;
F_1003 ( V_57 ) ;
if ( V_6 -> V_617 == 0 )
F_441 ( V_57 ) ;
F_989 ( V_57 ) ;
F_949 ( V_57 ) ;
F_1004 ( V_57 ) ;
F_267 ( V_57 ) ;
F_1005 ( V_57 ) ;
F_136 (dev, crtc) {
struct V_306 V_307 = {} ;
if ( ! V_65 -> V_88 )
continue;
V_6 -> V_431 . V_1422 ( V_65 ,
& V_307 ) ;
F_212 ( V_65 , & V_307 ) ;
}
F_997 ( V_57 ) ;
}
static void F_1006 ( struct V_56 * V_57 )
{
struct V_710 * V_711 ;
struct V_1107 * V_1465 = NULL ;
struct V_1108 V_1466 ;
struct V_423 * V_424 = V_57 -> V_426 . V_429 ;
F_814 (dev, connector) {
if ( V_711 -> V_507 -> type == V_605 ) {
V_1465 = & V_711 -> V_64 ;
break;
}
}
if ( ! V_1465 )
return;
if ( F_718 ( V_1465 , NULL , & V_1466 , V_424 ) )
F_726 ( V_1465 , & V_1466 , V_424 ) ;
}
static bool
F_1007 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_15 ;
if ( F_58 ( V_57 ) -> V_720 == 1 )
return true ;
V_15 = F_11 ( F_86 ( ! V_65 -> V_140 ) ) ;
if ( ( V_15 & V_141 ) &&
( ! ! ( V_15 & V_144 ) == V_65 -> V_95 ) )
return false ;
return true ;
}
static bool F_1008 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_506 * V_507 ;
F_352 (dev, &crtc->base, encoder)
return true ;
return false ;
}
static bool F_1009 ( struct V_506 * V_507 )
{
struct V_56 * V_57 = V_507 -> V_64 . V_57 ;
struct V_710 * V_711 ;
F_1010 (dev, &encoder->base, connector)
return true ;
return false ;
}
static void F_1011 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_94 V_97 = V_65 -> V_91 -> V_97 ;
if ( ! F_408 ( V_97 ) ) {
T_3 V_13 = F_59 ( V_97 ) ;
F_122 ( V_13 ,
F_11 ( V_13 ) & ~ V_1467 ) ;
}
F_1012 ( & V_65 -> V_64 ) ;
if ( V_65 -> V_88 ) {
struct V_327 * V_140 ;
F_404 ( & V_65 -> V_64 ) ;
F_1013 (dev, crtc, plane) {
if ( V_140 -> V_64 . type == V_1350 )
continue;
V_140 -> V_333 ( & V_140 -> V_64 , & V_65 -> V_64 ) ;
}
}
if ( F_58 ( V_57 ) -> V_103 < 4 && ! F_1007 ( V_65 ) ) {
bool V_140 ;
F_157 ( L_310 ,
V_65 -> V_64 . V_64 . V_372 , V_65 -> V_64 . V_12 ) ;
V_140 = V_65 -> V_140 ;
F_214 ( V_65 -> V_64 . V_89 -> V_43 ) -> V_331 = true ;
V_65 -> V_140 = ! V_140 ;
F_503 ( & V_65 -> V_64 ) ;
V_65 -> V_140 = V_140 ;
}
if ( V_6 -> V_136 & V_137 &&
V_65 -> V_95 == V_117 && ! V_65 -> V_88 ) {
F_1006 ( V_57 ) ;
}
if ( V_65 -> V_88 && ! F_1008 ( V_65 ) )
F_503 ( & V_65 -> V_64 ) ;
if ( V_65 -> V_88 || F_160 ( V_57 ) ) {
V_65 -> V_1468 = true ;
V_65 -> V_1469 = true ;
}
}
static void F_1014 ( struct V_506 * V_507 )
{
struct V_710 * V_711 ;
struct V_56 * V_57 = V_507 -> V_64 . V_57 ;
bool V_1470 = V_507 -> V_64 . V_65 &&
F_47 ( V_507 -> V_64 . V_65 ) -> V_88 ;
if ( F_1009 ( V_507 ) && ! V_1470 ) {
F_157 ( L_311 ,
V_507 -> V_64 . V_64 . V_372 ,
V_507 -> V_64 . V_12 ) ;
if ( V_507 -> V_64 . V_65 ) {
F_157 ( L_312 ,
V_507 -> V_64 . V_64 . V_372 ,
V_507 -> V_64 . V_12 ) ;
V_507 -> V_581 ( V_507 ) ;
if ( V_507 -> V_582 )
V_507 -> V_582 ( V_507 ) ;
}
V_507 -> V_64 . V_65 = NULL ;
F_814 (dev, connector) {
if ( V_711 -> V_507 != V_507 )
continue;
V_711 -> V_64 . V_1471 = V_1472 ;
V_711 -> V_64 . V_507 = NULL ;
}
}
}
void F_1015 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_3 V_1441 = F_990 ( V_57 ) ;
if ( ! ( F_11 ( V_1441 ) & V_1446 ) ) {
F_157 ( L_313 ) ;
F_989 ( V_57 ) ;
}
}
void F_268 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( ! F_83 ( V_6 , V_1473 ) )
return;
F_1015 ( V_57 ) ;
F_84 ( V_6 , V_1473 ) ;
}
static bool F_1016 ( struct V_327 * V_140 )
{
struct V_5 * V_6 = F_53 ( V_140 -> V_64 . V_57 ) ;
return F_11 ( F_86 ( V_140 -> V_140 ) ) & V_141 ;
}
static void F_1017 ( struct V_81 * V_65 )
{
struct V_323 * V_89 = V_65 -> V_64 . V_89 ;
struct V_328 * V_326 =
F_214 ( V_89 -> V_43 ) ;
V_326 -> V_331 = V_65 -> V_88 &&
F_1016 ( F_213 ( V_89 ) ) ;
if ( V_326 -> V_331 )
V_65 -> V_64 . V_43 -> V_332 |= 1 << F_218 ( V_89 ) ;
}
static void F_1018 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 ;
struct V_81 * V_65 ;
struct V_506 * V_507 ;
struct V_710 * V_711 ;
int V_142 ;
V_6 -> V_693 = 0 ;
F_136 (dev, crtc) {
struct V_37 * V_62 = V_65 -> V_91 ;
int V_691 = 0 ;
F_855 ( & V_62 -> V_64 ) ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
V_62 -> V_64 . V_65 = & V_65 -> V_64 ;
V_62 -> V_64 . V_88 = V_62 -> V_64 . V_502 =
V_6 -> V_431 . V_1281 ( V_65 , V_62 ) ;
V_65 -> V_64 . V_151 = V_62 -> V_64 . V_502 ;
V_65 -> V_88 = V_62 -> V_64 . V_88 ;
if ( V_62 -> V_64 . V_88 ) {
V_6 -> V_693 |= 1 << V_65 -> V_95 ;
if ( F_276 ( V_6 ) >= 9 || F_235 ( V_6 ) )
V_691 = F_526 ( V_62 ) ;
else if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
V_691 = V_62 -> V_64 . V_92 . V_93 ;
else
F_28 ( V_6 -> V_431 . V_1296 ) ;
if ( F_235 ( V_6 ) && V_62 -> V_547 )
V_691 = F_181 ( V_691 * 100 , 95 ) ;
}
V_6 -> V_690 [ V_65 -> V_95 ] = V_691 ;
F_1017 ( V_65 ) ;
F_157 ( L_314 ,
V_65 -> V_64 . V_64 . V_372 , V_65 -> V_64 . V_12 ,
V_65 -> V_88 ? L_208 : L_209 ) ;
}
for ( V_142 = 0 ; V_142 < V_6 -> V_945 ; V_142 ++ ) {
struct V_989 * V_990 = & V_6 -> V_1289 [ V_142 ] ;
V_990 -> V_1285 = V_990 -> V_1008 . V_712 ( V_6 , V_990 ,
& V_990 -> V_91 . V_1287 ) ;
V_990 -> V_91 . V_1283 = 0 ;
F_136 (dev, crtc) {
if ( V_65 -> V_88 && V_65 -> V_91 -> V_211 == V_990 )
V_990 -> V_91 . V_1283 |= 1 << V_65 -> V_95 ;
}
V_990 -> V_1286 = V_990 -> V_91 . V_1283 ;
F_157 ( L_315 ,
V_990 -> V_12 , V_990 -> V_91 . V_1283 , V_990 -> V_1285 ) ;
}
F_625 (dev, encoder) {
V_95 = 0 ;
if ( V_507 -> V_712 ( V_507 , & V_95 ) ) {
V_65 = F_47 ( V_6 -> V_96 [ V_95 ] ) ;
V_507 -> V_64 . V_65 = & V_65 -> V_64 ;
V_65 -> V_91 -> V_1250 |= 1 << V_507 -> type ;
V_507 -> V_1282 ( V_507 , V_65 -> V_91 ) ;
} else {
V_507 -> V_64 . V_65 = NULL ;
}
F_157 ( L_316 ,
V_507 -> V_64 . V_64 . V_372 ,
V_507 -> V_64 . V_12 ,
V_507 -> V_64 . V_65 ? L_208 : L_209 ,
F_76 ( V_95 ) ) ;
}
F_814 (dev, connector) {
if ( V_711 -> V_712 ( V_711 ) ) {
V_711 -> V_64 . V_1471 = V_1474 ;
V_507 = V_711 -> V_507 ;
V_711 -> V_64 . V_507 = & V_507 -> V_64 ;
if ( V_507 -> V_64 . V_65 &&
V_507 -> V_64 . V_65 -> V_43 -> V_88 ) {
V_507 -> V_64 . V_65 -> V_43 -> V_708 |=
1 << F_1019 ( & V_711 -> V_64 ) ;
V_507 -> V_64 . V_65 -> V_43 -> V_709 |=
1 << F_1020 ( & V_507 -> V_64 ) ;
}
} else {
V_711 -> V_64 . V_1471 = V_1472 ;
V_711 -> V_64 . V_507 = NULL ;
}
F_157 ( L_317 ,
V_711 -> V_64 . V_64 . V_372 ,
V_711 -> V_64 . V_12 ,
V_711 -> V_64 . V_507 ? L_208 : L_209 ) ;
}
F_136 (dev, crtc) {
V_65 -> V_64 . V_1254 = V_65 -> V_91 -> V_64 . V_92 ;
memset ( & V_65 -> V_64 . V_416 , 0 , sizeof( V_65 -> V_64 . V_416 ) ) ;
if ( V_65 -> V_64 . V_43 -> V_88 ) {
F_607 ( & V_65 -> V_64 . V_416 , V_65 -> V_91 ) ;
F_607 ( & V_65 -> V_64 . V_43 -> V_92 , V_65 -> V_91 ) ;
F_28 ( F_504 ( V_65 -> V_64 . V_43 , & V_65 -> V_64 . V_416 ) ) ;
V_65 -> V_64 . V_43 -> V_416 . V_1300 = V_1475 ;
F_1021 ( & V_65 -> V_64 , & V_65 -> V_64 . V_1254 ) ;
F_862 ( V_65 ) ;
}
F_847 ( V_6 , V_65 -> V_91 ) ;
}
}
static void
F_267 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 ;
struct V_81 * V_65 ;
struct V_506 * V_507 ;
int V_142 ;
F_1018 ( V_57 ) ;
F_625 (dev, encoder) {
F_1014 ( V_507 ) ;
}
F_89 (dev_priv, pipe) {
V_65 = F_47 ( V_6 -> V_96 [ V_95 ] ) ;
F_1011 ( V_65 ) ;
F_821 ( V_65 , V_65 -> V_91 ,
L_318 ) ;
}
F_813 ( V_57 ) ;
for ( V_142 = 0 ; V_142 < V_6 -> V_945 ; V_142 ++ ) {
struct V_989 * V_990 = & V_6 -> V_1289 [ V_142 ] ;
if ( ! V_990 -> V_1285 || V_990 -> V_1286 )
continue;
F_157 ( L_319 , V_990 -> V_12 ) ;
V_990 -> V_1008 . V_581 ( V_6 , V_990 ) ;
V_990 -> V_1285 = false ;
}
if ( F_16 ( V_57 ) || F_17 ( V_57 ) )
F_1022 ( V_57 ) ;
else if ( F_1023 ( V_57 ) )
F_1024 ( V_57 ) ;
else if ( F_15 ( V_57 ) )
F_1025 ( V_57 ) ;
F_136 (dev, crtc) {
unsigned long V_1313 ;
V_1313 = F_436 ( & V_65 -> V_64 , V_65 -> V_91 ) ;
if ( F_28 ( V_1313 ) )
F_439 ( V_6 , V_1313 ) ;
}
F_1026 ( V_6 , false ) ;
F_1027 ( V_6 ) ;
}
void F_1028 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_420 * V_43 = V_6 -> V_428 ;
struct V_423 V_424 ;
int V_267 ;
V_6 -> V_428 = NULL ;
if ( V_43 )
V_43 -> V_429 = & V_424 ;
F_3 ( & V_57 -> V_426 . V_427 ) ;
F_273 ( & V_424 , 0 ) ;
while ( 1 ) {
V_267 = F_274 ( V_57 , & V_424 ) ;
if ( V_267 != - V_271 )
break;
F_275 ( & V_424 ) ;
}
if ( ! V_267 )
V_267 = F_266 ( V_57 , V_43 ) ;
F_289 ( & V_424 ) ;
F_290 ( & V_424 ) ;
F_5 ( & V_57 -> V_426 . V_427 ) ;
if ( V_267 ) {
F_125 ( L_53 , V_267 ) ;
F_281 ( V_43 ) ;
}
}
void F_1029 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_87 * V_324 ;
struct V_264 * V_265 ;
int V_267 ;
F_1030 ( V_6 ) ;
F_285 ( V_57 ) ;
F_1031 ( V_6 ) ;
F_216 (dev, c) {
V_265 = F_187 ( V_324 -> V_89 -> V_90 ) ;
if ( V_265 == NULL )
continue;
F_3 ( & V_57 -> V_268 ) ;
V_267 = F_186 ( V_324 -> V_89 -> V_90 ,
V_324 -> V_89 -> V_43 -> V_252 ) ;
F_5 ( & V_57 -> V_268 ) ;
if ( V_267 ) {
F_125 ( L_320 ,
F_47 ( V_324 ) -> V_95 ) ;
F_210 ( V_324 -> V_89 -> V_90 ) ;
V_324 -> V_89 -> V_90 = NULL ;
V_324 -> V_89 -> V_65 = V_324 -> V_89 -> V_43 -> V_65 = NULL ;
F_209 ( V_324 -> V_89 ) ;
V_324 -> V_43 -> V_332 &= ~ ( 1 << F_218 ( V_324 -> V_89 ) ) ;
}
}
}
int F_1032 ( struct V_1107 * V_711 )
{
struct V_710 * V_710 = F_819 ( V_711 ) ;
int V_267 ;
V_267 = F_1033 ( V_710 ) ;
if ( V_267 )
goto V_72;
return 0 ;
V_72:
return V_267 ;
}
void F_1034 ( struct V_1107 * V_711 )
{
struct V_710 * V_710 = F_819 ( V_711 ) ;
F_1035 ( V_710 ) ;
F_1036 ( V_711 ) ;
}
void F_1037 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
F_1038 ( V_6 ) ;
F_1039 ( V_6 ) ;
F_1040 ( V_57 ) ;
F_1041 () ;
F_1042 ( V_6 ) ;
F_1043 () ;
F_1044 ( V_57 ) ;
F_1045 ( V_6 ) ;
F_1046 ( V_6 ) ;
F_1047 ( V_57 ) ;
}
void F_1048 ( struct V_710 * V_711 ,
struct V_506 * V_507 )
{
V_711 -> V_507 = V_507 ;
F_1049 ( & V_711 -> V_64 ,
& V_507 -> V_64 ) ;
}
int F_1050 ( struct V_56 * V_57 , bool V_43 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
unsigned V_13 = F_58 ( V_57 ) -> V_103 >= 6 ? V_1476 : V_1477 ;
T_5 V_1478 ;
if ( F_544 ( V_6 -> V_1479 , V_13 , & V_1478 ) ) {
F_125 ( L_321 ) ;
return - V_1194 ;
}
if ( ! ! ( V_1478 & V_1480 ) == ! V_43 )
return 0 ;
if ( V_43 )
V_1478 &= ~ V_1480 ;
else
V_1478 |= V_1480 ;
if ( F_1051 ( V_6 -> V_1479 , V_13 , V_1478 ) ) {
F_125 ( L_322 ) ;
return - V_1194 ;
}
return 0 ;
}
struct V_1481 *
F_1052 ( struct V_5 * V_6 )
{
struct V_1481 * error ;
int V_1482 [] = {
V_224 ,
V_1483 ,
V_1484 ,
V_576 ,
} ;
int V_142 ;
if ( F_58 ( V_6 ) -> V_720 == 0 )
return NULL ;
error = F_516 ( sizeof( * error ) , V_1485 ) ;
if ( error == NULL )
return NULL ;
if ( F_234 ( V_6 ) || F_235 ( V_6 ) )
error -> V_1486 = F_11 ( V_1010 ) ;
F_89 (dev_priv, i) {
error -> V_95 [ V_142 ] . V_1487 =
F_1053 ( V_6 ,
F_432 ( V_142 ) ) ;
if ( ! error -> V_95 [ V_142 ] . V_1487 )
continue;
error -> V_1355 [ V_142 ] . V_585 = F_11 ( F_80 ( V_142 ) ) ;
error -> V_1355 [ V_142 ] . V_1488 = F_11 ( F_697 ( V_142 ) ) ;
error -> V_1355 [ V_142 ] . V_64 = F_11 ( F_694 ( V_142 ) ) ;
error -> V_140 [ V_142 ] . V_585 = F_11 ( F_86 ( V_142 ) ) ;
error -> V_140 [ V_142 ] . V_319 = F_11 ( F_227 ( V_142 ) ) ;
if ( F_276 ( V_6 ) <= 3 ) {
error -> V_140 [ V_142 ] . V_247 = F_11 ( F_221 ( V_142 ) ) ;
error -> V_140 [ V_142 ] . V_544 = F_11 ( F_222 ( V_142 ) ) ;
}
if ( F_276 ( V_6 ) <= 7 && ! F_234 ( V_6 ) )
error -> V_140 [ V_142 ] . V_1184 = F_11 ( F_231 ( V_142 ) ) ;
if ( F_276 ( V_6 ) >= 4 ) {
error -> V_140 [ V_142 ] . V_1489 = F_11 ( F_228 ( V_142 ) ) ;
error -> V_140 [ V_142 ] . V_1490 = F_11 ( F_229 ( V_142 ) ) ;
}
error -> V_95 [ V_142 ] . V_1491 = F_11 ( F_294 ( V_142 ) ) ;
if ( F_160 ( V_6 ) )
error -> V_95 [ V_142 ] . V_1492 = F_11 ( F_1054 ( V_142 ) ) ;
}
error -> V_1493 = F_58 ( V_6 ) -> V_720 ;
if ( F_23 ( V_6 ) )
error -> V_1493 ++ ;
for ( V_142 = 0 ; V_142 < error -> V_1493 ; V_142 ++ ) {
enum V_94 V_97 = V_1482 [ V_142 ] ;
error -> V_94 [ V_142 ] . V_1487 =
F_1053 ( V_6 ,
F_82 ( V_97 ) ) ;
if ( ! error -> V_94 [ V_142 ] . V_1487 )
continue;
error -> V_94 [ V_142 ] . V_97 = V_97 ;
error -> V_94 [ V_142 ] . V_1494 = F_11 ( F_59 ( V_97 ) ) ;
error -> V_94 [ V_142 ] . V_886 = F_11 ( F_336 ( V_97 ) ) ;
error -> V_94 [ V_142 ] . V_1495 = F_11 ( F_338 ( V_97 ) ) ;
error -> V_94 [ V_142 ] . V_893 = F_11 ( F_340 ( V_97 ) ) ;
error -> V_94 [ V_142 ] . V_889 = F_11 ( F_342 ( V_97 ) ) ;
error -> V_94 [ V_142 ] . V_1185 = F_11 ( F_344 ( V_97 ) ) ;
error -> V_94 [ V_142 ] . V_1137 = F_11 ( F_346 ( V_97 ) ) ;
}
return error ;
}
void
F_1055 ( struct V_1496 * V_46 ,
struct V_56 * V_57 ,
struct V_1481 * error )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_142 ;
if ( ! error )
return;
F_1056 ( V_46 , L_323 , F_58 ( V_57 ) -> V_720 ) ;
if ( F_234 ( V_57 ) || F_235 ( V_57 ) )
F_1056 ( V_46 , L_324 ,
error -> V_1486 ) ;
F_89 (dev_priv, i) {
F_1056 ( V_46 , L_325 , V_142 ) ;
F_1056 ( V_46 , L_326 ,
F_65 ( error -> V_95 [ V_142 ] . V_1487 ) ) ;
F_1056 ( V_46 , L_327 , error -> V_95 [ V_142 ] . V_1491 ) ;
F_1056 ( V_46 , L_328 , error -> V_95 [ V_142 ] . V_1492 ) ;
F_1056 ( V_46 , L_329 , V_142 ) ;
F_1056 ( V_46 , L_330 , error -> V_140 [ V_142 ] . V_585 ) ;
F_1056 ( V_46 , L_331 , error -> V_140 [ V_142 ] . V_319 ) ;
if ( F_58 ( V_57 ) -> V_103 <= 3 ) {
F_1056 ( V_46 , L_332 , error -> V_140 [ V_142 ] . V_247 ) ;
F_1056 ( V_46 , L_333 , error -> V_140 [ V_142 ] . V_544 ) ;
}
if ( F_58 ( V_57 ) -> V_103 <= 7 && ! F_234 ( V_57 ) )
F_1056 ( V_46 , L_334 , error -> V_140 [ V_142 ] . V_1184 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
F_1056 ( V_46 , L_335 , error -> V_140 [ V_142 ] . V_1489 ) ;
F_1056 ( V_46 , L_336 , error -> V_140 [ V_142 ] . V_1490 ) ;
}
F_1056 ( V_46 , L_337 , V_142 ) ;
F_1056 ( V_46 , L_330 , error -> V_1355 [ V_142 ] . V_585 ) ;
F_1056 ( V_46 , L_333 , error -> V_1355 [ V_142 ] . V_1488 ) ;
F_1056 ( V_46 , L_338 , error -> V_1355 [ V_142 ] . V_64 ) ;
}
for ( V_142 = 0 ; V_142 < error -> V_1493 ; V_142 ++ ) {
F_1056 ( V_46 , L_339 ,
F_822 ( error -> V_94 [ V_142 ] . V_97 ) ) ;
F_1056 ( V_46 , L_326 ,
F_65 ( error -> V_94 [ V_142 ] . V_1487 ) ) ;
F_1056 ( V_46 , L_340 , error -> V_94 [ V_142 ] . V_1494 ) ;
F_1056 ( V_46 , L_341 , error -> V_94 [ V_142 ] . V_886 ) ;
F_1056 ( V_46 , L_342 , error -> V_94 [ V_142 ] . V_1495 ) ;
F_1056 ( V_46 , L_343 , error -> V_94 [ V_142 ] . V_893 ) ;
F_1056 ( V_46 , L_344 , error -> V_94 [ V_142 ] . V_889 ) ;
F_1056 ( V_46 , L_345 , error -> V_94 [ V_142 ] . V_1185 ) ;
F_1056 ( V_46 , L_346 , error -> V_94 [ V_142 ] . V_1137 ) ;
}
}
