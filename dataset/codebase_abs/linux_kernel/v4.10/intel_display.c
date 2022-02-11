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
static bool F_34 ( struct V_5 * V_6 ,
const struct V_56 * V_57 ,
const struct V_45 * clock )
{
if ( clock -> V_51 < V_57 -> V_51 . V_58 || V_57 -> V_51 . V_59 < clock -> V_51 )
F_35 ( L_6 ) ;
if ( clock -> V_49 < V_57 -> V_49 . V_58 || V_57 -> V_49 . V_59 < clock -> V_49 )
F_35 ( L_7 ) ;
if ( clock -> V_47 < V_57 -> V_47 . V_58 || V_57 -> V_47 . V_59 < clock -> V_47 )
F_35 ( L_8 ) ;
if ( clock -> V_54 < V_57 -> V_54 . V_58 || V_57 -> V_54 . V_59 < clock -> V_54 )
F_35 ( L_9 ) ;
if ( ! F_19 ( V_6 ) && ! F_16 ( V_6 ) &&
! F_17 ( V_6 ) && ! F_36 ( V_6 ) )
if ( clock -> V_54 <= clock -> V_47 )
F_35 ( L_10 ) ;
if ( ! F_16 ( V_6 ) && ! F_17 ( V_6 ) &&
! F_36 ( V_6 ) ) {
if ( clock -> V_48 < V_57 -> V_48 . V_58 || V_57 -> V_48 . V_59 < clock -> V_48 )
F_35 ( L_11 ) ;
if ( clock -> V_46 < V_57 -> V_46 . V_58 || V_57 -> V_46 . V_59 < clock -> V_46 )
F_35 ( L_12 ) ;
}
if ( clock -> V_52 < V_57 -> V_52 . V_58 || V_57 -> V_52 . V_59 < clock -> V_52 )
F_35 ( L_13 ) ;
if ( clock -> V_53 < V_57 -> V_53 . V_58 || V_57 -> V_53 . V_59 < clock -> V_53 )
F_35 ( L_14 ) ;
return true ;
}
static int
F_37 ( const struct V_56 * V_57 ,
const struct V_37 * V_60 ,
int V_61 )
{
struct V_62 * V_63 = V_60 -> V_64 . V_65 -> V_63 ;
if ( F_38 ( V_60 , V_66 ) ) {
if ( F_39 ( V_63 ) )
return V_57 -> V_50 . V_67 ;
else
return V_57 -> V_50 . V_68 ;
} else {
if ( V_61 < V_57 -> V_50 . V_69 )
return V_57 -> V_50 . V_68 ;
else
return V_57 -> V_50 . V_67 ;
}
}
static bool
F_40 ( const struct V_56 * V_57 ,
struct V_37 * V_60 ,
int V_61 , int V_44 , struct V_45 * V_70 ,
struct V_45 * V_71 )
{
struct V_62 * V_63 = V_60 -> V_64 . V_65 -> V_63 ;
struct V_45 clock ;
int V_72 = V_61 ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
clock . V_50 = F_37 ( V_57 , V_60 , V_61 ) ;
for ( clock . V_54 = V_57 -> V_54 . V_58 ; clock . V_54 <= V_57 -> V_54 . V_59 ;
clock . V_54 ++ ) {
for ( clock . V_47 = V_57 -> V_47 . V_58 ;
clock . V_47 <= V_57 -> V_47 . V_59 ; clock . V_47 ++ ) {
if ( clock . V_47 >= clock . V_54 )
break;
for ( clock . V_51 = V_57 -> V_51 . V_58 ;
clock . V_51 <= V_57 -> V_51 . V_59 ; clock . V_51 ++ ) {
for ( clock . V_49 = V_57 -> V_49 . V_58 ;
clock . V_49 <= V_57 -> V_49 . V_59 ; clock . V_49 ++ ) {
int V_73 ;
F_30 ( V_44 , & clock ) ;
if ( ! F_34 ( F_41 ( V_63 ) ,
V_57 ,
& clock ) )
continue;
if ( V_70 &&
clock . V_48 != V_70 -> V_48 )
continue;
V_73 = abs ( clock . V_53 - V_61 ) ;
if ( V_73 < V_72 ) {
* V_71 = clock ;
V_72 = V_73 ;
}
}
}
}
}
return ( V_72 != V_61 ) ;
}
static bool
F_42 ( const struct V_56 * V_57 ,
struct V_37 * V_60 ,
int V_61 , int V_44 , struct V_45 * V_70 ,
struct V_45 * V_71 )
{
struct V_62 * V_63 = V_60 -> V_64 . V_65 -> V_63 ;
struct V_45 clock ;
int V_72 = V_61 ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
clock . V_50 = F_37 ( V_57 , V_60 , V_61 ) ;
for ( clock . V_54 = V_57 -> V_54 . V_58 ; clock . V_54 <= V_57 -> V_54 . V_59 ;
clock . V_54 ++ ) {
for ( clock . V_47 = V_57 -> V_47 . V_58 ;
clock . V_47 <= V_57 -> V_47 . V_59 ; clock . V_47 ++ ) {
for ( clock . V_51 = V_57 -> V_51 . V_58 ;
clock . V_51 <= V_57 -> V_51 . V_59 ; clock . V_51 ++ ) {
for ( clock . V_49 = V_57 -> V_49 . V_58 ;
clock . V_49 <= V_57 -> V_49 . V_59 ; clock . V_49 ++ ) {
int V_73 ;
F_27 ( V_44 , & clock ) ;
if ( ! F_34 ( F_41 ( V_63 ) ,
V_57 ,
& clock ) )
continue;
if ( V_70 &&
clock . V_48 != V_70 -> V_48 )
continue;
V_73 = abs ( clock . V_53 - V_61 ) ;
if ( V_73 < V_72 ) {
* V_71 = clock ;
V_72 = V_73 ;
}
}
}
}
}
return ( V_72 != V_61 ) ;
}
static bool
F_43 ( const struct V_56 * V_57 ,
struct V_37 * V_60 ,
int V_61 , int V_44 , struct V_45 * V_70 ,
struct V_45 * V_71 )
{
struct V_62 * V_63 = V_60 -> V_64 . V_65 -> V_63 ;
struct V_45 clock ;
int V_74 ;
bool V_75 = false ;
int V_76 = ( V_61 >> 8 ) + ( V_61 >> 9 ) ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
clock . V_50 = F_37 ( V_57 , V_60 , V_61 ) ;
V_74 = V_57 -> V_51 . V_59 ;
for ( clock . V_51 = V_57 -> V_51 . V_58 ; clock . V_51 <= V_74 ; clock . V_51 ++ ) {
for ( clock . V_54 = V_57 -> V_54 . V_59 ;
clock . V_54 >= V_57 -> V_54 . V_58 ; clock . V_54 -- ) {
for ( clock . V_47 = V_57 -> V_47 . V_59 ;
clock . V_47 >= V_57 -> V_47 . V_58 ; clock . V_47 -- ) {
for ( clock . V_49 = V_57 -> V_49 . V_59 ;
clock . V_49 >= V_57 -> V_49 . V_58 ; clock . V_49 -- ) {
int V_73 ;
F_30 ( V_44 , & clock ) ;
if ( ! F_34 ( F_41 ( V_63 ) ,
V_57 ,
& clock ) )
continue;
V_73 = abs ( clock . V_53 - V_61 ) ;
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
static bool F_44 ( struct V_62 * V_63 , int V_77 ,
const struct V_45 * V_78 ,
const struct V_45 * V_71 ,
unsigned int V_79 ,
unsigned int * V_80 )
{
if ( F_17 ( F_41 ( V_63 ) ) ) {
* V_80 = 0 ;
return V_78 -> V_48 > V_71 -> V_48 ;
}
if ( F_45 ( ! V_77 ) )
return false ;
* V_80 = F_46 ( 1000000ULL *
abs ( V_77 - V_78 -> V_53 ) ,
V_77 ) ;
if ( * V_80 < 100 && V_78 -> V_48 > V_71 -> V_48 ) {
* V_80 = 0 ;
return true ;
}
return * V_80 + 10 < V_79 ;
}
static bool
F_47 ( const struct V_56 * V_57 ,
struct V_37 * V_60 ,
int V_61 , int V_44 , struct V_45 * V_70 ,
struct V_45 * V_71 )
{
struct V_81 * V_65 = F_48 ( V_60 -> V_64 . V_65 ) ;
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_45 clock ;
unsigned int V_82 = 1000000 ;
int V_74 = V_58 ( V_57 -> V_51 . V_59 , V_44 / 19200 ) ;
bool V_75 = false ;
V_61 *= 5 ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
for ( clock . V_51 = V_57 -> V_51 . V_58 ; clock . V_51 <= V_74 ; clock . V_51 ++ ) {
for ( clock . V_49 = V_57 -> V_49 . V_59 ; clock . V_49 >= V_57 -> V_49 . V_58 ; clock . V_49 -- ) {
for ( clock . V_50 = V_57 -> V_50 . V_67 ; clock . V_50 >= V_57 -> V_50 . V_68 ;
clock . V_50 -= clock . V_50 > 10 ? 2 : 1 ) {
clock . V_48 = clock . V_49 * clock . V_50 ;
for ( clock . V_54 = V_57 -> V_54 . V_58 ; clock . V_54 <= V_57 -> V_54 . V_59 ; clock . V_54 ++ ) {
unsigned int V_83 ;
clock . V_47 = F_8 ( V_61 * clock . V_48 * clock . V_51 ,
V_44 * clock . V_54 ) ;
F_31 ( V_44 , & clock ) ;
if ( ! F_34 ( F_41 ( V_63 ) ,
V_57 ,
& clock ) )
continue;
if ( ! F_44 ( V_63 , V_61 ,
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
F_49 ( const struct V_56 * V_57 ,
struct V_37 * V_60 ,
int V_61 , int V_44 , struct V_45 * V_70 ,
struct V_45 * V_71 )
{
struct V_81 * V_65 = F_48 ( V_60 -> V_64 . V_65 ) ;
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
unsigned int V_79 ;
struct V_45 clock ;
V_55 V_47 ;
int V_75 = false ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
V_79 = 1000000 ;
clock . V_51 = 1 , clock . V_54 = 2 ;
V_61 *= 5 ;
for ( clock . V_49 = V_57 -> V_49 . V_59 ; clock . V_49 >= V_57 -> V_49 . V_58 ; clock . V_49 -- ) {
for ( clock . V_50 = V_57 -> V_50 . V_67 ;
clock . V_50 >= V_57 -> V_50 . V_68 ;
clock . V_50 -= clock . V_50 > 10 ? 2 : 1 ) {
unsigned int V_80 ;
clock . V_48 = clock . V_49 * clock . V_50 ;
V_47 = F_33 ( ( ( V_55 ) V_61 * clock . V_48 *
clock . V_51 ) << 22 , V_44 * clock . V_54 ) ;
if ( V_47 > V_84 / clock . V_54 )
continue;
clock . V_47 = V_47 ;
F_32 ( V_44 , & clock ) ;
if ( ! F_34 ( F_41 ( V_63 ) , V_57 , & clock ) )
continue;
if ( ! F_44 ( V_63 , V_61 , & clock , V_71 ,
V_79 , & V_80 ) )
continue;
* V_71 = clock ;
V_79 = V_80 ;
V_75 = true ;
}
}
return V_75 ;
}
bool F_50 ( struct V_37 * V_60 , int V_85 ,
struct V_45 * V_71 )
{
int V_44 = 100000 ;
const struct V_56 * V_57 = & V_86 ;
return F_49 ( V_57 , V_60 ,
V_85 , V_44 , NULL , V_71 ) ;
}
bool F_51 ( struct V_81 * V_65 )
{
return V_65 -> V_87 && V_65 -> V_64 . V_88 -> V_43 -> V_89 &&
V_65 -> V_90 -> V_64 . V_91 . V_92 ;
}
enum V_93 F_52 ( struct V_5 * V_6 ,
enum V_94 V_94 )
{
struct V_81 * V_65 = F_53 ( V_6 , V_94 ) ;
return V_65 -> V_90 -> V_95 ;
}
static bool F_54 ( struct V_5 * V_6 , enum V_94 V_94 )
{
T_3 V_13 = F_55 ( V_94 ) ;
T_1 V_96 , V_97 ;
T_1 V_98 ;
if ( F_56 ( V_6 ) )
V_98 = V_99 ;
else
V_98 = V_100 ;
V_96 = F_11 ( V_13 ) & V_98 ;
F_57 ( 5 ) ;
V_97 = F_11 ( V_13 ) & V_98 ;
return V_96 == V_97 ;
}
static void F_58 ( struct V_81 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
enum V_93 V_95 = V_65 -> V_90 -> V_95 ;
enum V_94 V_94 = V_65 -> V_94 ;
if ( F_59 ( V_6 ) >= 4 ) {
T_3 V_13 = F_60 ( V_95 ) ;
if ( F_61 ( V_6 ,
V_13 , V_101 , 0 ,
100 ) )
F_7 ( 1 , L_15 ) ;
} else {
if ( F_62 ( F_54 ( V_6 , V_94 ) , 100 ) )
F_7 ( 1 , L_15 ) ;
}
}
void F_63 ( struct V_5 * V_6 ,
enum V_94 V_94 , bool V_43 )
{
T_1 V_15 ;
bool V_102 ;
V_15 = F_11 ( F_64 ( V_94 ) ) ;
V_102 = ! ! ( V_15 & V_103 ) ;
F_65 ( V_102 != V_43 ,
L_16 ,
F_66 ( V_43 ) , F_66 ( V_102 ) ) ;
}
void F_67 ( struct V_5 * V_6 , bool V_43 )
{
T_1 V_15 ;
bool V_102 ;
F_3 ( & V_6 -> V_9 ) ;
V_15 = F_4 ( V_6 , V_104 ) ;
F_5 ( & V_6 -> V_9 ) ;
V_102 = V_15 & V_105 ;
F_65 ( V_102 != V_43 ,
L_17 ,
F_66 ( V_43 ) , F_66 ( V_102 ) ) ;
}
static void F_68 ( struct V_5 * V_6 ,
enum V_94 V_94 , bool V_43 )
{
bool V_102 ;
enum V_93 V_95 = F_52 ( V_6 ,
V_94 ) ;
if ( F_23 ( V_6 ) ) {
T_1 V_15 = F_11 ( F_69 ( V_95 ) ) ;
V_102 = ! ! ( V_15 & V_106 ) ;
} else {
T_1 V_15 = F_11 ( F_70 ( V_94 ) ) ;
V_102 = ! ! ( V_15 & V_107 ) ;
}
F_65 ( V_102 != V_43 ,
L_18 ,
F_66 ( V_43 ) , F_66 ( V_102 ) ) ;
}
static void F_71 ( struct V_5 * V_6 ,
enum V_94 V_94 , bool V_43 )
{
T_1 V_15 ;
bool V_102 ;
V_15 = F_11 ( F_72 ( V_94 ) ) ;
V_102 = ! ! ( V_15 & V_108 ) ;
F_65 ( V_102 != V_43 ,
L_19 ,
F_66 ( V_43 ) , F_66 ( V_102 ) ) ;
}
static void F_73 ( struct V_5 * V_6 ,
enum V_94 V_94 )
{
T_1 V_15 ;
if ( F_24 ( V_6 ) )
return;
if ( F_23 ( V_6 ) )
return;
V_15 = F_11 ( F_70 ( V_94 ) ) ;
F_65 ( ! ( V_15 & V_109 ) , L_20 ) ;
}
void F_74 ( struct V_5 * V_6 ,
enum V_94 V_94 , bool V_43 )
{
T_1 V_15 ;
bool V_102 ;
V_15 = F_11 ( F_72 ( V_94 ) ) ;
V_102 = ! ! ( V_15 & V_110 ) ;
F_65 ( V_102 != V_43 ,
L_21 ,
F_66 ( V_43 ) , F_66 ( V_102 ) ) ;
}
void F_75 ( struct V_5 * V_6 , enum V_94 V_94 )
{
T_3 V_111 ;
T_1 V_15 ;
enum V_94 V_112 = V_113 ;
bool V_114 = true ;
if ( F_28 ( F_23 ( V_6 ) ) )
return;
if ( F_15 ( V_6 ) ) {
T_1 V_115 ;
V_111 = F_76 ( 0 ) ;
V_115 = F_11 ( F_77 ( 0 ) ) & V_116 ;
if ( V_115 == V_117 &&
F_11 ( V_118 ) & V_119 )
V_112 = V_120 ;
} else if ( F_16 ( V_6 ) || F_17 ( V_6 ) ) {
V_111 = F_76 ( V_94 ) ;
V_112 = V_94 ;
} else {
V_111 = F_76 ( 0 ) ;
if ( F_11 ( V_121 ) & V_119 )
V_112 = V_120 ;
}
V_15 = F_11 ( V_111 ) ;
if ( ! ( V_15 & V_122 ) ||
( ( V_15 & V_123 ) == V_124 ) )
V_114 = false ;
F_65 ( V_112 == V_94 && V_114 ,
L_22 ,
F_78 ( V_94 ) ) ;
}
static void F_79 ( struct V_5 * V_6 ,
enum V_94 V_94 , bool V_43 )
{
bool V_102 ;
if ( F_80 ( V_6 ) || F_81 ( V_6 ) )
V_102 = F_11 ( F_82 ( V_113 ) ) & V_125 ;
else
V_102 = F_11 ( F_82 ( V_94 ) ) & V_126 ;
F_65 ( V_102 != V_43 ,
L_23 ,
F_78 ( V_94 ) , F_66 ( V_43 ) , F_66 ( V_102 ) ) ;
}
void F_83 ( struct V_5 * V_6 ,
enum V_94 V_94 , bool V_43 )
{
bool V_102 ;
enum V_93 V_95 = F_52 ( V_6 ,
V_94 ) ;
enum V_127 V_128 ;
if ( ( V_94 == V_113 && V_6 -> V_129 & V_130 ) ||
( V_94 == V_120 && V_6 -> V_129 & V_131 ) )
V_43 = true ;
V_128 = F_84 ( V_95 ) ;
if ( F_85 ( V_6 , V_128 ) ) {
T_1 V_15 = F_11 ( F_60 ( V_95 ) ) ;
V_102 = ! ! ( V_15 & V_132 ) ;
F_86 ( V_6 , V_128 ) ;
} else {
V_102 = false ;
}
F_65 ( V_102 != V_43 ,
L_24 ,
F_78 ( V_94 ) , F_66 ( V_43 ) , F_66 ( V_102 ) ) ;
}
static void F_87 ( struct V_5 * V_6 ,
enum V_133 V_133 , bool V_43 )
{
T_1 V_15 ;
bool V_102 ;
V_15 = F_11 ( F_88 ( V_133 ) ) ;
V_102 = ! ! ( V_15 & V_134 ) ;
F_65 ( V_102 != V_43 ,
L_25 ,
F_89 ( V_133 ) , F_66 ( V_43 ) , F_66 ( V_102 ) ) ;
}
static void F_90 ( struct V_5 * V_6 ,
enum V_94 V_94 )
{
int V_135 ;
if ( F_59 ( V_6 ) >= 4 ) {
T_1 V_15 = F_11 ( F_88 ( V_94 ) ) ;
F_65 ( V_15 & V_134 ,
L_26 ,
F_89 ( V_94 ) ) ;
return;
}
F_91 (dev_priv, i) {
T_1 V_15 = F_11 ( F_88 ( V_135 ) ) ;
enum V_94 V_136 = ( V_15 & V_137 ) >>
V_138 ;
F_65 ( ( V_15 & V_134 ) && V_94 == V_136 ,
L_27 ,
F_89 ( V_135 ) , F_78 ( V_94 ) ) ;
}
}
static void F_92 ( struct V_5 * V_6 ,
enum V_94 V_94 )
{
int V_139 ;
if ( F_59 ( V_6 ) >= 9 ) {
F_93 (dev_priv, pipe, sprite) {
T_1 V_15 = F_11 ( F_94 ( V_94 , V_139 ) ) ;
F_65 ( V_15 & V_140 ,
L_28 ,
V_139 , F_78 ( V_94 ) ) ;
}
} else if ( F_16 ( V_6 ) || F_17 ( V_6 ) ) {
F_93 (dev_priv, pipe, sprite) {
T_1 V_15 = F_11 ( F_95 ( V_94 , V_139 ) ) ;
F_65 ( V_15 & V_141 ,
L_29 ,
F_96 ( V_94 , V_139 ) , F_78 ( V_94 ) ) ;
}
} else if ( F_59 ( V_6 ) >= 7 ) {
T_1 V_15 = F_11 ( F_97 ( V_94 ) ) ;
F_65 ( V_15 & V_142 ,
L_29 ,
F_89 ( V_94 ) , F_78 ( V_94 ) ) ;
} else if ( F_59 ( V_6 ) >= 5 ) {
T_1 V_15 = F_11 ( F_98 ( V_94 ) ) ;
F_65 ( V_15 & V_143 ,
L_29 ,
F_89 ( V_94 ) , F_78 ( V_94 ) ) ;
}
}
static void F_99 ( struct V_144 * V_65 )
{
if ( F_100 ( F_101 ( V_65 ) == 0 ) )
F_102 ( V_65 ) ;
}
void F_103 ( struct V_5 * V_6 ,
enum V_94 V_94 )
{
T_1 V_15 ;
bool V_145 ;
V_15 = F_11 ( F_104 ( V_94 ) ) ;
V_145 = ! ! ( V_15 & V_146 ) ;
F_65 ( V_145 ,
L_30 ,
F_78 ( V_94 ) ) ;
}
static bool F_105 ( struct V_5 * V_6 ,
enum V_94 V_94 , T_1 V_115 , T_1 V_15 )
{
if ( ( V_15 & V_147 ) == 0 )
return false ;
if ( F_106 ( V_6 ) ) {
T_1 V_148 = F_11 ( F_107 ( V_94 ) ) ;
if ( ( V_148 & V_149 ) != V_115 )
return false ;
} else if ( F_17 ( V_6 ) ) {
if ( ( V_15 & V_150 ) != F_108 ( V_94 ) )
return false ;
} else {
if ( ( V_15 & V_151 ) != ( V_94 << 30 ) )
return false ;
}
return true ;
}
static bool F_109 ( struct V_5 * V_6 ,
enum V_94 V_94 , T_1 V_15 )
{
if ( ( V_15 & V_152 ) == 0 )
return false ;
if ( F_106 ( V_6 ) ) {
if ( ( V_15 & V_153 ) != F_110 ( V_94 ) )
return false ;
} else if ( F_17 ( V_6 ) ) {
if ( ( V_15 & V_154 ) != F_111 ( V_94 ) )
return false ;
} else {
if ( ( V_15 & V_155 ) != F_112 ( V_94 ) )
return false ;
}
return true ;
}
static bool F_113 ( struct V_5 * V_6 ,
enum V_94 V_94 , T_1 V_15 )
{
if ( ( V_15 & V_156 ) == 0 )
return false ;
if ( F_106 ( V_6 ) ) {
if ( ( V_15 & V_157 ) != F_114 ( V_94 ) )
return false ;
} else {
if ( ( V_15 & V_158 ) != F_115 ( V_94 ) )
return false ;
}
return true ;
}
static bool F_116 ( struct V_5 * V_6 ,
enum V_94 V_94 , T_1 V_15 )
{
if ( ( V_15 & V_159 ) == 0 )
return false ;
if ( F_106 ( V_6 ) ) {
if ( ( V_15 & V_157 ) != F_114 ( V_94 ) )
return false ;
} else {
if ( ( V_15 & V_160 ) != F_117 ( V_94 ) )
return false ;
}
return true ;
}
static void F_118 ( struct V_5 * V_6 ,
enum V_94 V_94 , T_3 V_13 ,
T_1 V_115 )
{
T_1 V_15 = F_11 ( V_13 ) ;
F_65 ( F_105 ( V_6 , V_94 , V_115 , V_15 ) ,
L_31 ,
F_119 ( V_13 ) , F_78 ( V_94 ) ) ;
F_65 ( F_120 ( V_6 ) && ( V_15 & V_147 ) == 0
&& ( V_15 & V_161 ) ,
L_32 ) ;
}
static void F_121 ( struct V_5 * V_6 ,
enum V_94 V_94 , T_3 V_13 )
{
T_1 V_15 = F_11 ( V_13 ) ;
F_65 ( F_109 ( V_6 , V_94 , V_15 ) ,
L_33 ,
F_119 ( V_13 ) , F_78 ( V_94 ) ) ;
F_65 ( F_120 ( V_6 ) && ( V_15 & V_152 ) == 0
&& ( V_15 & V_162 ) ,
L_34 ) ;
}
static void F_122 ( struct V_5 * V_6 ,
enum V_94 V_94 )
{
T_1 V_15 ;
F_118 ( V_6 , V_94 , V_163 , V_164 ) ;
F_118 ( V_6 , V_94 , V_165 , V_166 ) ;
F_118 ( V_6 , V_94 , V_167 , V_168 ) ;
V_15 = F_11 ( V_169 ) ;
F_65 ( F_116 ( V_6 , V_94 , V_15 ) ,
L_35 ,
F_78 ( V_94 ) ) ;
V_15 = F_11 ( V_118 ) ;
F_65 ( F_113 ( V_6 , V_94 , V_15 ) ,
L_36 ,
F_78 ( V_94 ) ) ;
F_121 ( V_6 , V_94 , V_170 ) ;
F_121 ( V_6 , V_94 , V_171 ) ;
F_121 ( V_6 , V_94 , V_172 ) ;
}
static void F_123 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
F_124 ( F_64 ( V_94 ) , V_38 -> V_173 . V_45 ) ;
F_125 ( F_64 ( V_94 ) ) ;
F_126 ( 150 ) ;
if ( F_61 ( V_6 ,
F_64 ( V_94 ) ,
V_174 ,
V_174 ,
1 ) )
F_127 ( L_37 , V_94 ) ;
}
static void F_128 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
F_129 ( V_6 , V_94 ) ;
F_75 ( V_6 , V_94 ) ;
if ( V_38 -> V_173 . V_45 & V_103 )
F_123 ( V_65 , V_38 ) ;
F_124 ( F_130 ( V_94 ) , V_38 -> V_173 . V_175 ) ;
F_125 ( F_130 ( V_94 ) ) ;
}
static void F_131 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
enum V_176 V_177 = F_132 ( V_94 ) ;
T_1 V_178 ;
F_3 ( & V_6 -> V_9 ) ;
V_178 = F_133 ( V_6 , V_94 , F_134 ( V_177 ) ) ;
V_178 |= V_179 ;
F_135 ( V_6 , V_94 , F_134 ( V_177 ) , V_178 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_126 ( 1 ) ;
F_124 ( F_64 ( V_94 ) , V_38 -> V_173 . V_45 ) ;
if ( F_61 ( V_6 ,
F_64 ( V_94 ) , V_174 , V_174 ,
1 ) )
F_127 ( L_38 , V_94 ) ;
}
static void F_136 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
F_129 ( V_6 , V_94 ) ;
F_75 ( V_6 , V_94 ) ;
if ( V_38 -> V_173 . V_45 & V_103 )
F_131 ( V_65 , V_38 ) ;
if ( V_94 != V_113 ) {
F_124 ( V_180 , V_94 == V_120 ? V_181 : V_182 ) ;
F_124 ( F_130 ( V_120 ) , V_38 -> V_173 . V_175 ) ;
F_124 ( V_180 , 0 ) ;
V_6 -> V_183 [ V_94 ] = V_38 -> V_173 . V_175 ;
F_28 ( ( F_11 ( F_64 ( V_120 ) ) & V_184 ) == 0 ) ;
} else {
F_124 ( F_130 ( V_94 ) , V_38 -> V_173 . V_175 ) ;
F_125 ( F_130 ( V_94 ) ) ;
}
}
static int F_137 ( struct V_5 * V_6 )
{
struct V_81 * V_65 ;
int V_185 = 0 ;
F_138 (&dev_priv->drm, crtc) {
V_185 += V_65 -> V_64 . V_43 -> V_87 &&
F_38 ( V_65 -> V_90 , V_186 ) ;
}
return V_185 ;
}
static void F_139 ( struct V_81 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
T_3 V_13 = F_64 ( V_65 -> V_94 ) ;
T_1 V_45 = V_65 -> V_90 -> V_173 . V_45 ;
F_129 ( V_6 , V_65 -> V_94 ) ;
if ( F_140 ( V_6 ) && ! F_141 ( V_6 ) )
F_75 ( V_6 , V_65 -> V_94 ) ;
if ( F_141 ( V_6 ) && F_137 ( V_6 ) > 0 ) {
V_45 |= V_187 ;
F_124 ( F_64 ( ! V_65 -> V_94 ) ,
F_11 ( F_64 ( ! V_65 -> V_94 ) ) | V_187 ) ;
}
F_124 ( V_13 , 0 ) ;
F_124 ( V_13 , V_45 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
if ( F_59 ( V_6 ) >= 4 ) {
F_124 ( F_130 ( V_65 -> V_94 ) ,
V_65 -> V_90 -> V_173 . V_175 ) ;
} else {
F_124 ( V_13 , V_45 ) ;
}
F_124 ( V_13 , V_45 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
F_124 ( V_13 , V_45 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
F_124 ( V_13 , V_45 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
}
static void F_142 ( struct V_81 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
if ( F_141 ( V_6 ) &&
F_38 ( V_65 -> V_90 , V_186 ) &&
! F_137 ( V_6 ) ) {
F_124 ( F_64 ( V_120 ) ,
F_11 ( F_64 ( V_120 ) ) & ~ V_187 ) ;
F_124 ( F_64 ( V_113 ) ,
F_11 ( F_64 ( V_113 ) ) & ~ V_187 ) ;
}
if ( ( V_94 == V_113 && V_6 -> V_129 & V_130 ) ||
( V_94 == V_120 && V_6 -> V_129 & V_131 ) )
return;
F_129 ( V_6 , V_94 ) ;
F_124 ( F_64 ( V_94 ) , V_184 ) ;
F_125 ( F_64 ( V_94 ) ) ;
}
static void F_143 ( struct V_5 * V_6 , enum V_94 V_94 )
{
T_1 V_15 ;
F_129 ( V_6 , V_94 ) ;
V_15 = V_188 |
V_189 | V_184 ;
if ( V_94 != V_113 )
V_15 |= V_190 ;
F_124 ( F_64 ( V_94 ) , V_15 ) ;
F_125 ( F_64 ( V_94 ) ) ;
}
static void F_144 ( struct V_5 * V_6 , enum V_94 V_94 )
{
enum V_176 V_177 = F_132 ( V_94 ) ;
T_1 V_15 ;
F_129 ( V_6 , V_94 ) ;
V_15 = V_191 |
V_189 | V_184 ;
if ( V_94 != V_113 )
V_15 |= V_190 ;
F_124 ( F_64 ( V_94 ) , V_15 ) ;
F_125 ( F_64 ( V_94 ) ) ;
F_3 ( & V_6 -> V_9 ) ;
V_15 = F_133 ( V_6 , V_94 , F_134 ( V_177 ) ) ;
V_15 &= ~ V_179 ;
F_135 ( V_6 , V_94 , F_134 ( V_177 ) , V_15 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
void F_145 ( struct V_5 * V_6 ,
struct V_192 * V_193 ,
unsigned int V_194 )
{
T_1 V_195 ;
T_3 V_196 ;
switch ( V_193 -> V_177 ) {
case V_197 :
V_195 = V_198 ;
V_196 = F_64 ( 0 ) ;
break;
case V_199 :
V_195 = V_200 ;
V_196 = F_64 ( 0 ) ;
V_194 <<= 4 ;
break;
case V_201 :
V_195 = V_202 ;
V_196 = V_203 ;
break;
default:
F_146 () ;
}
if ( F_61 ( V_6 ,
V_196 , V_195 , V_194 ,
1000 ) )
F_7 ( 1 , L_39 ,
F_147 ( V_193 -> V_177 ) , F_11 ( V_196 ) & V_195 , V_194 ) ;
}
static void F_148 ( struct V_5 * V_6 ,
enum V_94 V_94 )
{
struct V_81 * V_81 = F_53 ( V_6 ,
V_94 ) ;
T_3 V_13 ;
T_2 V_15 , V_204 ;
F_149 ( V_6 , V_81 -> V_90 -> V_205 ) ;
F_150 ( V_6 , V_94 ) ;
F_151 ( V_6 , V_94 ) ;
if ( F_106 ( V_6 ) ) {
V_13 = F_152 ( V_94 ) ;
V_15 = F_11 ( V_13 ) ;
V_15 |= V_206 ;
F_124 ( V_13 , V_15 ) ;
}
V_13 = F_104 ( V_94 ) ;
V_15 = F_11 ( V_13 ) ;
V_204 = F_11 ( F_60 ( V_94 ) ) ;
if ( F_120 ( V_6 ) ) {
V_15 &= ~ V_207 ;
if ( F_38 ( V_81 -> V_90 , V_208 ) )
V_15 |= V_209 ;
else
V_15 |= V_204 & V_207 ;
}
V_15 &= ~ V_210 ;
if ( ( V_204 & V_211 ) == V_212 )
if ( F_120 ( V_6 ) &&
F_38 ( V_81 -> V_90 , V_213 ) )
V_15 |= V_214 ;
else
V_15 |= V_215 ;
else
V_15 |= V_216 ;
F_124 ( V_13 , V_15 | V_146 ) ;
if ( F_61 ( V_6 ,
V_13 , V_217 , V_217 ,
100 ) )
F_127 ( L_40 , F_78 ( V_94 ) ) ;
}
static void F_153 ( struct V_5 * V_6 ,
enum V_93 V_95 )
{
T_1 V_15 , V_204 ;
F_150 ( V_6 , (enum V_94 ) V_95 ) ;
F_151 ( V_6 , V_218 ) ;
V_15 = F_11 ( F_152 ( V_113 ) ) ;
V_15 |= V_206 ;
F_124 ( F_152 ( V_113 ) , V_15 ) ;
V_15 = V_146 ;
V_204 = F_11 ( F_60 ( V_95 ) ) ;
if ( ( V_204 & V_219 ) ==
V_212 )
V_15 |= V_215 ;
else
V_15 |= V_216 ;
F_124 ( V_220 , V_15 ) ;
if ( F_61 ( V_6 ,
V_220 ,
V_217 ,
V_217 ,
100 ) )
F_127 ( L_41 ) ;
}
static void F_154 ( struct V_5 * V_6 ,
enum V_94 V_94 )
{
T_3 V_13 ;
T_2 V_15 ;
F_155 ( V_6 , V_94 ) ;
F_156 ( V_6 , V_94 ) ;
F_122 ( V_6 , V_94 ) ;
V_13 = F_104 ( V_94 ) ;
V_15 = F_11 ( V_13 ) ;
V_15 &= ~ V_146 ;
F_124 ( V_13 , V_15 ) ;
if ( F_61 ( V_6 ,
V_13 , V_217 , 0 ,
50 ) )
F_127 ( L_42 , F_78 ( V_94 ) ) ;
if ( F_106 ( V_6 ) ) {
V_13 = F_152 ( V_94 ) ;
V_15 = F_11 ( V_13 ) ;
V_15 &= ~ V_206 ;
F_124 ( V_13 , V_15 ) ;
}
}
void F_157 ( struct V_5 * V_6 )
{
T_1 V_15 ;
V_15 = F_11 ( V_220 ) ;
V_15 &= ~ V_146 ;
F_124 ( V_220 , V_15 ) ;
if ( F_61 ( V_6 ,
V_220 , V_217 , 0 ,
50 ) )
F_127 ( L_43 ) ;
V_15 = F_11 ( F_152 ( V_113 ) ) ;
V_15 &= ~ V_206 ;
F_124 ( F_152 ( V_113 ) , V_15 ) ;
}
enum V_93 F_158 ( struct V_81 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
F_28 ( ! V_65 -> V_90 -> V_221 ) ;
if ( F_159 ( V_6 ) )
return V_218 ;
else
return (enum V_93 ) V_65 -> V_94 ;
}
static void F_160 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
enum V_93 V_95 = V_65 -> V_90 -> V_95 ;
T_3 V_13 ;
T_1 V_15 ;
F_161 ( L_44 , F_78 ( V_94 ) ) ;
F_90 ( V_6 , V_94 ) ;
F_162 ( V_6 , V_94 ) ;
F_92 ( V_6 , V_94 ) ;
if ( F_163 ( V_6 ) ) {
if ( F_38 ( V_65 -> V_90 , V_222 ) )
F_164 ( V_6 ) ;
else
F_165 ( V_6 , V_94 ) ;
} else {
if ( V_65 -> V_90 -> V_221 ) {
F_166 ( V_6 ,
(enum V_94 ) F_158 ( V_65 ) ) ;
F_73 ( V_6 ,
(enum V_94 ) V_95 ) ;
}
}
V_13 = F_60 ( V_95 ) ;
V_15 = F_11 ( V_13 ) ;
if ( V_15 & V_132 ) {
F_28 ( ! ( ( V_94 == V_113 && V_6 -> V_129 & V_130 ) ||
( V_94 == V_120 && V_6 -> V_129 & V_131 ) ) ) ;
return;
}
F_124 ( V_13 , V_15 | V_132 ) ;
F_125 ( V_13 ) ;
if ( V_63 -> V_223 == 0 &&
F_62 ( F_167 ( V_65 ) != V_65 -> V_224 , 50 ) )
F_127 ( L_45 , F_78 ( V_94 ) ) ;
}
static void F_168 ( struct V_81 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
enum V_93 V_95 = V_65 -> V_90 -> V_95 ;
enum V_94 V_94 = V_65 -> V_94 ;
T_3 V_13 ;
T_1 V_15 ;
F_161 ( L_46 , F_78 ( V_94 ) ) ;
F_90 ( V_6 , V_94 ) ;
F_162 ( V_6 , V_94 ) ;
F_92 ( V_6 , V_94 ) ;
V_13 = F_60 ( V_95 ) ;
V_15 = F_11 ( V_13 ) ;
if ( ( V_15 & V_132 ) == 0 )
return;
if ( V_65 -> V_90 -> V_225 )
V_15 &= ~ V_226 ;
if ( ! ( V_94 == V_113 && V_6 -> V_129 & V_130 ) &&
! ( V_94 == V_120 && V_6 -> V_129 & V_131 ) )
V_15 &= ~ V_132 ;
F_124 ( V_13 , V_15 ) ;
if ( ( V_15 & V_132 ) == 0 )
F_58 ( V_65 ) ;
}
static unsigned int F_169 ( const struct V_5 * V_6 )
{
return F_56 ( V_6 ) ? 2048 : 4096 ;
}
static unsigned int F_170 ( const struct V_5 * V_6 ,
V_55 V_227 , unsigned int V_228 )
{
switch ( V_227 ) {
case V_229 :
return V_228 ;
case V_230 :
if ( F_56 ( V_6 ) )
return 128 ;
else
return 512 ;
case V_231 :
if ( F_56 ( V_6 ) || F_171 ( V_6 ) )
return 128 ;
else
return 512 ;
case V_232 :
switch ( V_228 ) {
case 1 :
return 64 ;
case 2 :
case 4 :
return 128 ;
case 8 :
case 16 :
return 256 ;
default:
F_172 ( V_228 ) ;
return V_228 ;
}
break;
default:
F_172 ( V_227 ) ;
return V_228 ;
}
}
unsigned int F_173 ( const struct V_5 * V_6 ,
V_55 V_227 , unsigned int V_228 )
{
if ( V_227 == V_229 )
return 1 ;
else
return F_169 ( V_6 ) /
F_170 ( V_6 , V_227 , V_228 ) ;
}
static void F_174 ( const struct V_5 * V_6 ,
unsigned int * V_233 ,
unsigned int * V_234 ,
V_55 V_227 ,
unsigned int V_228 )
{
unsigned int V_235 =
F_170 ( V_6 , V_227 , V_228 ) ;
* V_233 = V_235 / V_228 ;
* V_234 = F_169 ( V_6 ) / V_235 ;
}
unsigned int
F_175 ( struct V_62 * V_63 , unsigned int V_236 ,
T_2 V_237 , V_55 V_227 )
{
unsigned int V_228 = F_176 ( V_237 , 0 ) ;
unsigned int V_234 = F_173 ( F_41 ( V_63 ) , V_227 , V_228 ) ;
return F_177 ( V_236 , V_234 ) ;
}
unsigned int F_178 ( const struct V_238 * V_239 )
{
unsigned int V_240 = 0 ;
int V_135 ;
for ( V_135 = 0 ; V_135 < F_179 ( V_239 -> V_133 ) ; V_135 ++ )
V_240 += V_239 -> V_133 [ V_135 ] . V_241 * V_239 -> V_133 [ V_135 ] . V_236 ;
return V_240 ;
}
static void
F_180 ( struct V_242 * V_243 ,
const struct V_244 * V_89 ,
unsigned int V_245 )
{
if ( F_181 ( V_245 ) ) {
* V_243 = V_246 ;
V_243 -> V_247 . V_248 = F_182 ( V_89 ) -> V_239 ;
} else {
* V_243 = V_249 ;
}
}
static unsigned int F_183 ( const struct V_5 * V_6 )
{
if ( F_184 ( V_6 ) -> V_250 >= 9 )
return 256 * 1024 ;
else if ( F_185 ( V_6 ) || F_186 ( V_6 ) ||
F_16 ( V_6 ) || F_17 ( V_6 ) )
return 128 * 1024 ;
else if ( F_184 ( V_6 ) -> V_250 >= 4 )
return 4 * 1024 ;
else
return 0 ;
}
static unsigned int F_187 ( const struct V_5 * V_6 ,
V_55 V_227 )
{
switch ( V_227 ) {
case V_229 :
return F_183 ( V_6 ) ;
case V_230 :
if ( F_184 ( V_6 ) -> V_250 >= 9 )
return 256 * 1024 ;
return 0 ;
case V_231 :
case V_232 :
return 1 * 1024 * 1024 ;
default:
F_172 ( V_227 ) ;
return 0 ;
}
}
struct V_251 *
F_188 ( struct V_244 * V_89 , unsigned int V_245 )
{
struct V_62 * V_63 = V_89 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_252 * V_253 = F_189 ( V_89 ) ;
struct V_242 V_243 ;
struct V_251 * V_254 ;
T_1 V_255 ;
F_28 ( ! F_190 ( & V_63 -> V_256 ) ) ;
V_255 = F_187 ( V_6 , V_89 -> V_257 ) ;
F_180 ( & V_243 , V_89 , V_245 ) ;
if ( F_191 ( V_6 ) && V_255 < 256 * 1024 )
V_255 = 256 * 1024 ;
F_192 ( V_6 ) ;
V_254 = F_193 ( V_253 , V_255 , & V_243 ) ;
if ( F_194 ( V_254 ) )
goto V_72;
if ( F_195 ( V_254 ) ) {
if ( F_196 ( V_254 ) == 0 )
F_197 ( V_254 ) ;
}
F_198 ( V_254 ) ;
V_72:
F_199 ( V_6 ) ;
return V_254 ;
}
void F_200 ( struct V_251 * V_254 )
{
F_201 ( & V_254 -> V_258 -> V_63 -> V_256 ) ;
if ( F_45 ( ! V_254 ) )
return;
F_202 ( V_254 ) ;
F_203 ( V_254 ) ;
F_204 ( V_254 ) ;
}
static int F_205 ( const struct V_244 * V_89 , int V_133 ,
unsigned int V_245 )
{
if ( F_181 ( V_245 ) )
return F_182 ( V_89 ) -> V_248 [ V_133 ] . V_259 ;
else
return V_89 -> V_260 [ V_133 ] ;
}
T_1 F_206 ( int V_261 , int V_262 ,
const struct V_263 * V_43 ,
int V_133 )
{
const struct V_244 * V_89 = V_43 -> V_64 . V_89 ;
unsigned int V_228 = F_176 ( V_89 -> V_237 , V_133 ) ;
unsigned int V_259 = V_89 -> V_260 [ V_133 ] ;
return V_262 * V_259 + V_261 * V_228 ;
}
void F_207 ( int * V_261 , int * V_262 ,
const struct V_263 * V_43 ,
int V_133 )
{
const struct V_264 * V_265 = F_182 ( V_43 -> V_64 . V_89 ) ;
unsigned int V_245 = V_43 -> V_64 . V_245 ;
if ( F_181 ( V_245 ) ) {
* V_261 += V_265 -> V_248 [ V_133 ] . V_261 ;
* V_262 += V_265 -> V_248 [ V_133 ] . V_262 ;
} else {
* V_261 += V_265 -> V_266 [ V_133 ] . V_261 ;
* V_262 += V_265 -> V_266 [ V_133 ] . V_262 ;
}
}
static T_1 F_208 ( int * V_261 , int * V_262 ,
unsigned int V_233 ,
unsigned int V_234 ,
unsigned int V_267 ,
unsigned int V_268 ,
T_1 V_269 ,
T_1 V_270 )
{
unsigned int V_271 = V_268 * V_233 ;
unsigned int V_272 ;
F_28 ( V_269 & ( V_267 - 1 ) ) ;
F_28 ( V_270 & ( V_267 - 1 ) ) ;
F_28 ( V_270 > V_269 ) ;
V_272 = ( V_269 - V_270 ) / V_267 ;
* V_262 += V_272 / V_268 * V_234 ;
* V_261 += V_272 % V_268 * V_233 ;
* V_262 += * V_261 / V_271 * V_234 ;
* V_261 %= V_271 ;
return V_270 ;
}
static T_1 F_209 ( int * V_261 , int * V_262 ,
const struct V_263 * V_43 , int V_133 ,
T_1 V_269 , T_1 V_270 )
{
const struct V_5 * V_6 = F_41 ( V_43 -> V_64 . V_133 -> V_63 ) ;
const struct V_244 * V_89 = V_43 -> V_64 . V_89 ;
unsigned int V_228 = F_176 ( V_89 -> V_237 , V_133 ) ;
unsigned int V_245 = V_43 -> V_64 . V_245 ;
unsigned int V_259 = F_205 ( V_89 , V_133 , V_245 ) ;
F_28 ( V_270 > V_269 ) ;
if ( V_89 -> V_257 != V_229 ) {
unsigned int V_267 , V_233 , V_234 ;
unsigned int V_268 ;
V_267 = F_169 ( V_6 ) ;
F_174 ( V_6 , & V_233 , & V_234 ,
V_89 -> V_257 , V_228 ) ;
if ( F_181 ( V_245 ) ) {
V_268 = V_259 / V_234 ;
F_210 ( V_233 , V_234 ) ;
} else {
V_268 = V_259 / ( V_233 * V_228 ) ;
}
F_208 ( V_261 , V_262 , V_233 , V_234 ,
V_267 , V_268 ,
V_269 , V_270 ) ;
} else {
V_269 += * V_262 * V_259 + * V_261 * V_228 ;
* V_262 = ( V_269 - V_270 ) / V_259 ;
* V_261 = ( ( V_269 - V_270 ) - * V_262 * V_259 ) / V_228 ;
}
return V_270 ;
}
static T_1 F_211 ( const struct V_5 * V_6 ,
int * V_261 , int * V_262 ,
const struct V_244 * V_89 , int V_133 ,
unsigned int V_259 ,
unsigned int V_245 ,
T_1 V_255 )
{
V_55 V_227 = V_89 -> V_257 ;
unsigned int V_228 = F_176 ( V_89 -> V_237 , V_133 ) ;
T_1 V_273 , V_274 ;
if ( V_255 )
V_255 -- ;
if ( V_227 != V_229 ) {
unsigned int V_267 , V_233 , V_234 ;
unsigned int V_275 , V_272 , V_268 ;
V_267 = F_169 ( V_6 ) ;
F_174 ( V_6 , & V_233 , & V_234 ,
V_227 , V_228 ) ;
if ( F_181 ( V_245 ) ) {
V_268 = V_259 / V_234 ;
F_210 ( V_233 , V_234 ) ;
} else {
V_268 = V_259 / ( V_233 * V_228 ) ;
}
V_275 = * V_262 / V_234 ;
* V_262 %= V_234 ;
V_272 = * V_261 / V_233 ;
* V_261 %= V_233 ;
V_273 = ( V_275 * V_268 + V_272 ) * V_267 ;
V_274 = V_273 & ~ V_255 ;
F_208 ( V_261 , V_262 , V_233 , V_234 ,
V_267 , V_268 ,
V_273 , V_274 ) ;
} else {
V_273 = * V_262 * V_259 + * V_261 * V_228 ;
V_274 = V_273 & ~ V_255 ;
* V_262 = ( V_273 & V_255 ) / V_259 ;
* V_261 = ( ( V_273 & V_255 ) - * V_262 * V_259 ) / V_228 ;
}
return V_274 ;
}
T_1 F_212 ( int * V_261 , int * V_262 ,
const struct V_263 * V_43 ,
int V_133 )
{
const struct V_5 * V_6 = F_41 ( V_43 -> V_64 . V_133 -> V_63 ) ;
const struct V_244 * V_89 = V_43 -> V_64 . V_89 ;
unsigned int V_245 = V_43 -> V_64 . V_245 ;
int V_259 = F_205 ( V_89 , V_133 , V_245 ) ;
T_1 V_255 ;
if ( V_89 -> V_237 == V_276 && V_133 == 1 )
V_255 = 4096 ;
else
V_255 = F_187 ( V_6 , V_89 -> V_257 ) ;
return F_211 ( V_6 , V_261 , V_262 , V_89 , V_133 , V_259 ,
V_245 , V_255 ) ;
}
static void F_213 ( int * V_261 , int * V_262 ,
const struct V_244 * V_89 , int V_133 )
{
unsigned int V_228 = F_176 ( V_89 -> V_237 , V_133 ) ;
unsigned int V_259 = V_89 -> V_260 [ V_133 ] ;
T_1 V_277 = V_89 -> V_278 [ V_133 ] ;
* V_262 = V_277 / V_259 ;
* V_261 = V_277 % V_259 / V_228 ;
}
static unsigned int F_214 ( V_55 V_227 )
{
switch ( V_227 ) {
case V_230 :
return V_279 ;
case V_231 :
return V_280 ;
default:
return V_281 ;
}
}
static int
F_215 ( struct V_5 * V_6 ,
struct V_244 * V_89 )
{
struct V_264 * V_265 = F_182 ( V_89 ) ;
struct V_238 * V_239 = & V_265 -> V_239 ;
T_1 V_282 = 0 ;
unsigned int V_283 = 0 ;
T_2 V_284 = V_89 -> V_237 ;
int V_135 , V_285 = F_216 ( V_284 ) ;
unsigned int V_267 = F_169 ( V_6 ) ;
for ( V_135 = 0 ; V_135 < V_285 ; V_135 ++ ) {
unsigned int V_241 , V_236 ;
unsigned int V_228 , V_240 ;
T_1 V_273 ;
int V_261 , V_262 ;
V_228 = F_176 ( V_284 , V_135 ) ;
V_241 = F_217 ( V_89 -> V_241 , V_284 , V_135 ) ;
V_236 = F_218 ( V_89 -> V_236 , V_284 , V_135 ) ;
F_213 ( & V_261 , & V_262 , V_89 , V_135 ) ;
if ( F_219 ( V_265 -> V_253 ) &&
( V_261 + V_241 ) * V_228 > V_89 -> V_260 [ V_135 ] ) {
F_220 ( L_47 ,
V_135 , V_89 -> V_278 [ V_135 ] ) ;
return - V_286 ;
}
V_265 -> V_266 [ V_135 ] . V_261 = V_261 ;
V_265 -> V_266 [ V_135 ] . V_262 = V_262 ;
V_273 = F_211 ( V_6 , & V_261 , & V_262 ,
V_89 , 0 , V_89 -> V_260 [ V_135 ] ,
V_287 , V_267 ) ;
V_273 /= V_267 ;
if ( V_89 -> V_257 != V_229 ) {
unsigned int V_233 , V_234 ;
unsigned int V_268 ;
struct V_288 V_289 ;
F_174 ( V_6 , & V_233 , & V_234 ,
V_89 -> V_257 , V_228 ) ;
V_239 -> V_133 [ V_135 ] . V_273 = V_273 ;
V_239 -> V_133 [ V_135 ] . V_290 = F_221 ( V_89 -> V_260 [ V_135 ] , V_233 * V_228 ) ;
V_239 -> V_133 [ V_135 ] . V_241 = F_221 ( V_261 + V_241 , V_233 ) ;
V_239 -> V_133 [ V_135 ] . V_236 = F_221 ( V_262 + V_236 , V_234 ) ;
V_265 -> V_248 [ V_135 ] . V_259 =
V_239 -> V_133 [ V_135 ] . V_236 * V_234 ;
V_240 = V_239 -> V_133 [ V_135 ] . V_290 * V_239 -> V_133 [ V_135 ] . V_236 ;
if ( V_261 != 0 )
V_240 ++ ;
V_289 . V_291 = V_261 ;
V_289 . y1 = V_262 ;
V_289 . V_292 = V_261 + V_241 ;
V_289 . V_293 = V_262 + V_236 ;
F_222 ( & V_289 ,
V_239 -> V_133 [ V_135 ] . V_241 * V_233 ,
V_239 -> V_133 [ V_135 ] . V_236 * V_234 ,
V_294 ) ;
V_261 = V_289 . V_291 ;
V_262 = V_289 . y1 ;
V_268 = V_265 -> V_248 [ V_135 ] . V_259 / V_234 ;
F_210 ( V_233 , V_234 ) ;
F_208 ( & V_261 , & V_262 ,
V_233 , V_234 ,
V_267 , V_268 ,
V_282 * V_267 , 0 ) ;
V_282 += V_239 -> V_133 [ V_135 ] . V_241 * V_239 -> V_133 [ V_135 ] . V_236 ;
V_265 -> V_248 [ V_135 ] . V_261 = V_261 ;
V_265 -> V_248 [ V_135 ] . V_262 = V_262 ;
} else {
V_240 = F_221 ( ( V_262 + V_236 ) * V_89 -> V_260 [ V_135 ] +
V_261 * V_228 , V_267 ) ;
}
V_283 = V_59 ( V_283 , V_273 + V_240 ) ;
}
if ( V_283 * V_267 > F_182 ( V_89 ) -> V_253 -> V_64 . V_240 ) {
F_220 ( L_48 ,
V_283 * V_267 , F_182 ( V_89 ) -> V_253 -> V_64 . V_240 ) ;
return - V_286 ;
}
return 0 ;
}
static int F_223 ( int V_284 )
{
switch ( V_284 ) {
case V_295 :
return V_296 ;
case V_297 :
return V_298 ;
case V_299 :
return V_300 ;
default:
case V_301 :
return V_302 ;
case V_303 :
return V_304 ;
case V_305 :
return V_306 ;
case V_307 :
return V_308 ;
}
}
static int F_224 ( int V_284 , bool V_309 , bool V_310 )
{
switch ( V_284 ) {
case V_311 :
return V_300 ;
default:
case V_312 :
if ( V_309 ) {
if ( V_310 )
return V_313 ;
else
return V_304 ;
} else {
if ( V_310 )
return V_314 ;
else
return V_302 ;
}
case V_315 :
if ( V_309 )
return V_308 ;
else
return V_306 ;
}
}
static bool
F_225 ( struct V_81 * V_65 ,
struct V_316 * V_317 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_318 * V_319 = & V_6 -> V_319 ;
struct V_252 * V_253 = NULL ;
struct V_320 V_321 = { 0 } ;
struct V_244 * V_89 = & V_317 -> V_89 -> V_64 ;
T_1 V_322 = F_226 ( V_317 -> V_64 , V_323 ) ;
T_1 V_324 = F_227 ( V_317 -> V_64 + V_317 -> V_240 ,
V_323 ) ;
V_324 -= V_322 ;
if ( V_317 -> V_240 == 0 )
return false ;
if ( V_324 * 2 > V_319 -> V_325 )
return false ;
F_3 ( & V_63 -> V_256 ) ;
V_253 = F_228 ( V_63 ,
V_322 ,
V_322 ,
V_324 ) ;
if ( ! V_253 ) {
F_5 ( & V_63 -> V_256 ) ;
return false ;
}
if ( V_317 -> V_326 == V_279 )
V_253 -> V_327 = V_89 -> V_260 [ 0 ] | V_279 ;
V_321 . V_237 = V_89 -> V_237 ;
V_321 . V_241 = V_89 -> V_241 ;
V_321 . V_236 = V_89 -> V_236 ;
V_321 . V_260 [ 0 ] = V_89 -> V_260 [ 0 ] ;
V_321 . V_257 [ 0 ] = V_89 -> V_257 ;
V_321 . V_328 = V_329 ;
if ( F_229 ( V_63 , F_182 ( V_89 ) ,
& V_321 , V_253 ) ) {
F_161 ( L_49 ) ;
goto V_330;
}
F_5 ( & V_63 -> V_256 ) ;
F_161 ( L_50 , V_253 ) ;
return true ;
V_330:
F_230 ( V_253 ) ;
F_5 ( & V_63 -> V_256 ) ;
return false ;
}
static void
F_231 ( struct V_331 * V_133 )
{
if ( V_133 -> V_89 == V_133 -> V_43 -> V_89 )
return;
if ( V_133 -> V_43 -> V_89 )
F_232 ( V_133 -> V_43 -> V_89 ) ;
V_133 -> V_43 -> V_89 = V_133 -> V_89 ;
if ( V_133 -> V_43 -> V_89 )
F_233 ( V_133 -> V_43 -> V_89 ) ;
}
static void
F_234 ( struct V_81 * V_81 ,
struct V_316 * V_317 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_144 * V_332 ;
struct V_252 * V_253 ;
struct V_331 * V_88 = V_81 -> V_64 . V_88 ;
struct V_333 * V_334 = V_88 -> V_43 ;
struct V_42 * V_60 = V_81 -> V_64 . V_43 ;
struct V_335 * V_335 = F_235 ( V_88 ) ;
struct V_263 * V_336 =
F_236 ( V_334 ) ;
struct V_244 * V_89 ;
if ( ! V_317 -> V_89 )
return;
if ( F_225 ( V_81 , V_317 ) ) {
V_89 = & V_317 -> V_89 -> V_64 ;
goto V_337;
}
F_237 ( V_317 -> V_89 ) ;
F_238 (dev, c) {
struct V_263 * V_43 ;
if ( V_332 == & V_81 -> V_64 )
continue;
if ( ! F_48 ( V_332 ) -> V_87 )
continue;
V_43 = F_236 ( V_332 -> V_88 -> V_43 ) ;
if ( ! V_43 -> V_254 )
continue;
if ( F_239 ( V_43 ) == V_317 -> V_64 ) {
V_89 = V_332 -> V_88 -> V_89 ;
F_233 ( V_89 ) ;
goto V_337;
}
}
F_236 ( V_334 ) -> V_64 . V_338 = false ;
V_60 -> V_339 &= ~ ( 1 << F_240 ( V_88 ) ) ;
F_241 ( & V_81 -> V_64 ) ;
V_335 -> V_340 ( V_88 , & V_81 -> V_64 ) ;
return;
V_337:
F_3 ( & V_63 -> V_256 ) ;
V_336 -> V_254 =
F_188 ( V_89 , V_88 -> V_43 -> V_245 ) ;
F_5 ( & V_63 -> V_256 ) ;
if ( F_194 ( V_336 -> V_254 ) ) {
F_127 ( L_51 ,
V_81 -> V_94 , F_242 ( V_336 -> V_254 ) ) ;
V_336 -> V_254 = NULL ;
F_232 ( V_89 ) ;
return;
}
V_334 -> V_341 = 0 ;
V_334 -> V_342 = 0 ;
V_334 -> V_343 = V_89 -> V_241 << 16 ;
V_334 -> V_344 = V_89 -> V_236 << 16 ;
V_334 -> V_345 = 0 ;
V_334 -> V_346 = 0 ;
V_334 -> V_347 = V_89 -> V_241 ;
V_334 -> V_348 = V_89 -> V_236 ;
V_336 -> V_64 . V_349 = F_243 ( V_334 ) ;
V_336 -> V_64 . V_350 = F_244 ( V_334 ) ;
V_253 = F_189 ( V_89 ) ;
if ( F_219 ( V_253 ) )
V_6 -> V_351 = true ;
F_233 ( V_89 ) ;
V_88 -> V_89 = V_88 -> V_43 -> V_89 = V_89 ;
V_88 -> V_65 = V_88 -> V_43 -> V_65 = & V_81 -> V_64 ;
V_81 -> V_64 . V_43 -> V_339 |= ( 1 << F_240 ( V_88 ) ) ;
F_245 ( F_235 ( V_88 ) -> V_352 ,
& V_253 -> V_353 ) ;
}
static int F_246 ( const struct V_244 * V_89 , int V_133 ,
unsigned int V_245 )
{
int V_228 = F_176 ( V_89 -> V_237 , V_133 ) ;
switch ( V_89 -> V_257 ) {
case V_229 :
case V_230 :
switch ( V_228 ) {
case 8 :
return 4096 ;
case 4 :
case 2 :
case 1 :
return 8192 ;
default:
F_172 ( V_228 ) ;
break;
}
break;
case V_231 :
case V_232 :
switch ( V_228 ) {
case 8 :
return 2048 ;
case 4 :
return 4096 ;
case 2 :
case 1 :
return 8192 ;
default:
F_172 ( V_228 ) ;
break;
}
break;
default:
F_172 ( V_89 -> V_257 ) ;
}
return 2048 ;
}
static int F_247 ( struct V_263 * V_334 )
{
const struct V_5 * V_6 = F_41 ( V_334 -> V_64 . V_133 -> V_63 ) ;
const struct V_244 * V_89 = V_334 -> V_64 . V_89 ;
unsigned int V_245 = V_334 -> V_64 . V_245 ;
int V_261 = V_334 -> V_64 . V_349 . V_291 >> 16 ;
int V_262 = V_334 -> V_64 . V_349 . y1 >> 16 ;
int V_354 = F_248 ( & V_334 -> V_64 . V_349 ) >> 16 ;
int V_355 = F_249 ( & V_334 -> V_64 . V_349 ) >> 16 ;
int V_356 = F_246 ( V_89 , 0 , V_245 ) ;
int V_357 = 4096 ;
T_1 V_255 , V_273 , V_358 = V_334 -> V_359 . V_273 ;
if ( V_354 > V_356 || V_355 > V_357 ) {
F_161 ( L_52 ,
V_354 , V_355 , V_356 , V_357 ) ;
return - V_286 ;
}
F_207 ( & V_261 , & V_262 , V_334 , 0 ) ;
V_273 = F_212 ( & V_261 , & V_262 , V_334 , 0 ) ;
V_255 = F_187 ( V_6 , V_89 -> V_257 ) ;
if ( V_273 > V_358 )
V_273 = F_209 ( & V_261 , & V_262 , V_334 , 0 ,
V_273 , V_358 & ~ ( V_255 - 1 ) ) ;
if ( V_89 -> V_257 == V_230 ) {
int V_228 = F_176 ( V_89 -> V_237 , 0 ) ;
while ( ( V_261 + V_354 ) * V_228 > V_89 -> V_260 [ 0 ] ) {
if ( V_273 == 0 ) {
F_161 ( L_53 ) ;
return - V_286 ;
}
V_273 = F_209 ( & V_261 , & V_262 , V_334 , 0 ,
V_273 , V_273 - V_255 ) ;
}
}
V_334 -> main. V_273 = V_273 ;
V_334 -> main. V_261 = V_261 ;
V_334 -> main. V_262 = V_262 ;
return 0 ;
}
static int F_250 ( struct V_263 * V_334 )
{
const struct V_244 * V_89 = V_334 -> V_64 . V_89 ;
unsigned int V_245 = V_334 -> V_64 . V_245 ;
int V_356 = F_246 ( V_89 , 1 , V_245 ) ;
int V_357 = 4096 ;
int V_261 = V_334 -> V_64 . V_349 . V_291 >> 17 ;
int V_262 = V_334 -> V_64 . V_349 . y1 >> 17 ;
int V_354 = F_248 ( & V_334 -> V_64 . V_349 ) >> 17 ;
int V_355 = F_249 ( & V_334 -> V_64 . V_349 ) >> 17 ;
T_1 V_273 ;
F_207 ( & V_261 , & V_262 , V_334 , 1 ) ;
V_273 = F_212 ( & V_261 , & V_262 , V_334 , 1 ) ;
if ( V_354 > V_356 || V_355 > V_357 ) {
F_161 ( L_54 ,
V_354 , V_355 , V_356 , V_357 ) ;
return - V_286 ;
}
V_334 -> V_359 . V_273 = V_273 ;
V_334 -> V_359 . V_261 = V_261 ;
V_334 -> V_359 . V_262 = V_262 ;
return 0 ;
}
int F_251 ( struct V_263 * V_334 )
{
const struct V_244 * V_89 = V_334 -> V_64 . V_89 ;
unsigned int V_245 = V_334 -> V_64 . V_245 ;
int V_360 ;
if ( ! V_334 -> V_64 . V_338 )
return 0 ;
if ( F_181 ( V_245 ) )
F_222 ( & V_334 -> V_64 . V_349 ,
V_89 -> V_241 << 16 , V_89 -> V_236 << 16 ,
V_294 ) ;
if ( V_89 -> V_237 == V_276 ) {
V_360 = F_250 ( V_334 ) ;
if ( V_360 )
return V_360 ;
} else {
V_334 -> V_359 . V_273 = ~ 0xfff ;
V_334 -> V_359 . V_261 = 0 ;
V_334 -> V_359 . V_262 = 0 ;
}
V_360 = F_247 ( V_334 ) ;
if ( V_360 )
return V_360 ;
return 0 ;
}
static void F_252 ( struct V_331 * V_88 ,
const struct V_37 * V_60 ,
const struct V_263 * V_334 )
{
struct V_5 * V_6 = F_41 ( V_88 -> V_63 ) ;
struct V_81 * V_81 = F_48 ( V_60 -> V_64 . V_65 ) ;
struct V_244 * V_89 = V_334 -> V_64 . V_89 ;
int V_133 = V_81 -> V_133 ;
T_1 V_277 ;
T_1 V_361 ;
T_3 V_13 = F_88 ( V_133 ) ;
unsigned int V_245 = V_334 -> V_64 . V_245 ;
int V_261 = V_334 -> V_64 . V_349 . V_291 >> 16 ;
int V_262 = V_334 -> V_64 . V_349 . y1 >> 16 ;
V_361 = V_362 ;
V_361 |= V_134 ;
if ( F_59 ( V_6 ) < 4 ) {
if ( V_81 -> V_94 == V_120 )
V_361 |= V_363 ;
F_124 ( F_253 ( V_133 ) ,
( ( V_60 -> V_364 - 1 ) << 16 ) |
( V_60 -> V_365 - 1 ) ) ;
F_124 ( F_254 ( V_133 ) , 0 ) ;
} else if ( F_17 ( V_6 ) && V_133 == V_366 ) {
F_124 ( F_255 ( V_133 ) ,
( ( V_60 -> V_364 - 1 ) << 16 ) |
( V_60 -> V_365 - 1 ) ) ;
F_124 ( F_256 ( V_133 ) , 0 ) ;
F_124 ( F_257 ( V_133 ) , 0 ) ;
}
switch ( V_89 -> V_237 ) {
case V_296 :
V_361 |= V_295 ;
break;
case V_298 :
V_361 |= V_297 ;
break;
case V_300 :
V_361 |= V_299 ;
break;
case V_302 :
V_361 |= V_301 ;
break;
case V_304 :
V_361 |= V_303 ;
break;
case V_306 :
V_361 |= V_305 ;
break;
case V_308 :
V_361 |= V_307 ;
break;
default:
F_146 () ;
}
if ( F_59 ( V_6 ) >= 4 &&
V_89 -> V_257 == V_230 )
V_361 |= V_367 ;
if ( V_245 & V_368 )
V_361 |= V_369 ;
if ( V_245 & V_370 )
V_361 |= V_371 ;
if ( F_18 ( V_6 ) )
V_361 |= V_372 ;
F_207 ( & V_261 , & V_262 , V_334 , 0 ) ;
if ( F_59 ( V_6 ) >= 4 )
V_81 -> V_373 =
F_212 ( & V_261 , & V_262 , V_334 , 0 ) ;
if ( V_245 & V_368 ) {
V_261 += V_60 -> V_365 - 1 ;
V_262 += V_60 -> V_364 - 1 ;
} else if ( V_245 & V_370 ) {
V_261 += V_60 -> V_365 - 1 ;
}
V_277 = F_206 ( V_261 , V_262 , V_334 , 0 ) ;
if ( F_59 ( V_6 ) < 4 )
V_81 -> V_373 = V_277 ;
V_81 -> V_374 = V_261 ;
V_81 -> V_375 = V_262 ;
F_124 ( V_13 , V_361 ) ;
F_124 ( F_258 ( V_133 ) , V_89 -> V_260 [ 0 ] ) ;
if ( F_59 ( V_6 ) >= 4 ) {
F_124 ( F_259 ( V_133 ) ,
F_239 ( V_334 ) +
V_81 -> V_373 ) ;
F_124 ( F_260 ( V_133 ) , ( V_262 << 16 ) | V_261 ) ;
F_124 ( F_261 ( V_133 ) , V_277 ) ;
} else {
F_124 ( F_262 ( V_133 ) ,
F_239 ( V_334 ) +
V_81 -> V_373 ) ;
}
F_125 ( V_13 ) ;
}
static void F_263 ( struct V_331 * V_88 ,
struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_133 = V_81 -> V_133 ;
F_124 ( F_88 ( V_133 ) , 0 ) ;
if ( F_184 ( V_6 ) -> V_250 >= 4 )
F_124 ( F_259 ( V_133 ) , 0 ) ;
else
F_124 ( F_262 ( V_133 ) , 0 ) ;
F_125 ( F_88 ( V_133 ) ) ;
}
static void F_264 ( struct V_331 * V_88 ,
const struct V_37 * V_60 ,
const struct V_263 * V_334 )
{
struct V_62 * V_63 = V_88 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_60 -> V_64 . V_65 ) ;
struct V_244 * V_89 = V_334 -> V_64 . V_89 ;
int V_133 = V_81 -> V_133 ;
T_1 V_277 ;
T_1 V_361 ;
T_3 V_13 = F_88 ( V_133 ) ;
unsigned int V_245 = V_334 -> V_64 . V_245 ;
int V_261 = V_334 -> V_64 . V_349 . V_291 >> 16 ;
int V_262 = V_334 -> V_64 . V_349 . y1 >> 16 ;
V_361 = V_362 ;
V_361 |= V_134 ;
if ( F_265 ( V_6 ) || F_266 ( V_6 ) )
V_361 |= V_376 ;
switch ( V_89 -> V_237 ) {
case V_296 :
V_361 |= V_295 ;
break;
case V_300 :
V_361 |= V_299 ;
break;
case V_302 :
V_361 |= V_301 ;
break;
case V_304 :
V_361 |= V_303 ;
break;
case V_306 :
V_361 |= V_305 ;
break;
case V_308 :
V_361 |= V_307 ;
break;
default:
F_146 () ;
}
if ( V_89 -> V_257 == V_230 )
V_361 |= V_367 ;
if ( V_245 & V_368 )
V_361 |= V_369 ;
if ( ! F_265 ( V_6 ) && ! F_266 ( V_6 ) )
V_361 |= V_372 ;
F_207 ( & V_261 , & V_262 , V_334 , 0 ) ;
V_81 -> V_373 =
F_212 ( & V_261 , & V_262 , V_334 , 0 ) ;
if ( ! F_265 ( V_6 ) && ! F_266 ( V_6 ) &&
V_245 & V_368 ) {
V_261 += V_60 -> V_365 - 1 ;
V_262 += V_60 -> V_364 - 1 ;
}
V_277 = F_206 ( V_261 , V_262 , V_334 , 0 ) ;
V_81 -> V_374 = V_261 ;
V_81 -> V_375 = V_262 ;
F_124 ( V_13 , V_361 ) ;
F_124 ( F_258 ( V_133 ) , V_89 -> V_260 [ 0 ] ) ;
F_124 ( F_259 ( V_133 ) ,
F_239 ( V_334 ) +
V_81 -> V_373 ) ;
if ( F_265 ( V_6 ) || F_266 ( V_6 ) ) {
F_124 ( F_267 ( V_133 ) , ( V_262 << 16 ) | V_261 ) ;
} else {
F_124 ( F_260 ( V_133 ) , ( V_262 << 16 ) | V_261 ) ;
F_124 ( F_261 ( V_133 ) , V_277 ) ;
}
F_125 ( V_13 ) ;
}
T_1 F_268 ( const struct V_5 * V_6 ,
V_55 V_227 , T_2 V_237 )
{
if ( V_227 == V_229 ) {
return 64 ;
} else {
int V_228 = F_176 ( V_237 , 0 ) ;
return F_170 ( V_6 , V_227 , V_228 ) ;
}
}
static void F_269 ( struct V_81 * V_81 , int V_377 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
F_124 ( F_270 ( V_81 -> V_94 , V_377 ) , 0 ) ;
F_124 ( F_271 ( V_81 -> V_94 , V_377 ) , 0 ) ;
F_124 ( F_272 ( V_81 -> V_94 , V_377 ) , 0 ) ;
}
static void F_273 ( struct V_81 * V_81 )
{
struct V_378 * V_379 ;
int V_135 ;
V_379 = & V_81 -> V_90 -> V_379 ;
for ( V_135 = 0 ; V_135 < V_81 -> V_380 ; V_135 ++ ) {
if ( ! V_379 -> V_381 [ V_135 ] . V_382 )
F_269 ( V_81 , V_135 ) ;
}
}
T_1 F_274 ( const struct V_244 * V_89 , int V_133 ,
unsigned int V_245 )
{
const struct V_5 * V_6 = F_41 ( V_89 -> V_63 ) ;
T_1 V_290 = F_205 ( V_89 , V_133 , V_245 ) ;
if ( F_181 ( V_245 ) ) {
int V_228 = F_176 ( V_89 -> V_237 , V_133 ) ;
V_290 /= F_173 ( V_6 , V_89 -> V_257 , V_228 ) ;
} else {
V_290 /= F_268 ( V_6 , V_89 -> V_257 ,
V_89 -> V_237 ) ;
}
return V_290 ;
}
T_1 F_275 ( T_2 V_237 )
{
switch ( V_237 ) {
case V_296 :
return V_383 ;
case V_300 :
return V_311 ;
case V_304 :
return V_312 | V_384 ;
case V_302 :
return V_312 ;
case V_313 :
return V_312 | V_384 |
V_385 ;
case V_314 :
return V_312 |
V_385 ;
case V_306 :
return V_315 ;
case V_308 :
return V_384 | V_315 ;
case V_386 :
return V_387 | V_388 ;
case V_389 :
return V_387 | V_390 ;
case V_391 :
return V_387 | V_392 ;
case V_393 :
return V_387 | V_394 ;
default:
F_172 ( V_237 ) ;
}
return 0 ;
}
T_1 F_276 ( V_55 V_227 )
{
switch ( V_227 ) {
case V_229 :
break;
case V_230 :
return V_395 ;
case V_231 :
return V_396 ;
case V_232 :
return V_397 ;
default:
F_172 ( V_227 ) ;
}
return 0 ;
}
T_1 F_277 ( unsigned int V_245 )
{
switch ( V_245 ) {
case V_287 :
break;
case V_398 :
return V_399 ;
case V_368 :
return V_400 ;
case V_294 :
return V_401 ;
default:
F_172 ( V_245 ) ;
}
return 0 ;
}
static void F_278 ( struct V_331 * V_133 ,
const struct V_37 * V_60 ,
const struct V_263 * V_334 )
{
struct V_62 * V_63 = V_133 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_60 -> V_64 . V_65 ) ;
struct V_244 * V_89 = V_334 -> V_64 . V_89 ;
int V_94 = V_81 -> V_94 ;
T_1 V_402 ;
unsigned int V_245 = V_334 -> V_64 . V_245 ;
T_1 V_290 = F_274 ( V_89 , 0 , V_245 ) ;
T_1 V_403 = V_334 -> main. V_273 ;
int V_404 = V_334 -> V_404 ;
int V_341 = V_334 -> main. V_261 ;
int V_342 = V_334 -> main. V_262 ;
int V_343 = F_248 ( & V_334 -> V_64 . V_349 ) >> 16 ;
int V_344 = F_249 ( & V_334 -> V_64 . V_349 ) >> 16 ;
int V_405 = V_334 -> V_64 . V_350 . V_291 ;
int V_406 = V_334 -> V_64 . V_350 . y1 ;
int V_407 = F_248 ( & V_334 -> V_64 . V_350 ) ;
int V_408 = F_249 ( & V_334 -> V_64 . V_350 ) ;
V_402 = V_140 |
V_409 |
V_410 ;
V_402 |= F_275 ( V_89 -> V_237 ) ;
V_402 |= F_276 ( V_89 -> V_257 ) ;
V_402 |= V_411 ;
V_402 |= F_277 ( V_245 ) ;
V_343 -- ;
V_344 -- ;
V_407 -- ;
V_408 -- ;
V_81 -> V_373 = V_403 ;
V_81 -> V_374 = V_341 ;
V_81 -> V_375 = V_342 ;
F_124 ( F_94 ( V_94 , 0 ) , V_402 ) ;
F_124 ( F_279 ( V_94 , 0 ) , ( V_342 << 16 ) | V_341 ) ;
F_124 ( F_280 ( V_94 , 0 ) , V_290 ) ;
F_124 ( F_281 ( V_94 , 0 ) , ( V_344 << 16 ) | V_343 ) ;
if ( V_404 >= 0 ) {
T_2 V_412 = 0 ;
F_28 ( ! V_407 || ! V_408 ) ;
V_412 = V_413 | F_282 ( 0 ) |
V_60 -> V_379 . V_381 [ V_404 ] . V_414 ;
F_124 ( F_270 ( V_94 , V_404 ) , V_412 ) ;
F_124 ( F_283 ( V_94 , V_404 ) , 0 ) ;
F_124 ( F_271 ( V_94 , V_404 ) , ( V_405 << 16 ) | V_406 ) ;
F_124 ( F_272 ( V_94 , V_404 ) , ( V_407 << 16 ) | V_408 ) ;
F_124 ( F_284 ( V_94 , 0 ) , 0 ) ;
} else {
F_124 ( F_284 ( V_94 , 0 ) , ( V_406 << 16 ) | V_405 ) ;
}
F_124 ( F_285 ( V_94 , 0 ) ,
F_239 ( V_334 ) + V_403 ) ;
F_125 ( F_285 ( V_94 , 0 ) ) ;
}
static void F_286 ( struct V_331 * V_88 ,
struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
F_124 ( F_94 ( V_94 , 0 ) , 0 ) ;
F_124 ( F_285 ( V_94 , 0 ) , 0 ) ;
F_125 ( F_285 ( V_94 , 0 ) ) ;
}
static int
F_287 ( struct V_144 * V_65 , struct V_244 * V_89 ,
int V_261 , int V_262 , enum V_415 V_43 )
{
F_127 ( L_55 ) ;
return - V_416 ;
}
static void F_288 ( struct V_5 * V_6 )
{
struct V_81 * V_65 ;
F_138 (&dev_priv->drm, crtc)
F_289 ( V_6 , V_65 -> V_94 ) ;
}
static void F_290 ( struct V_62 * V_63 )
{
struct V_144 * V_65 ;
F_238 (dev, crtc) {
struct V_335 * V_133 = F_235 ( V_65 -> V_88 ) ;
struct V_263 * V_334 =
F_236 ( V_133 -> V_64 . V_43 ) ;
if ( V_334 -> V_64 . V_338 )
V_133 -> V_417 ( & V_133 -> V_64 ,
F_291 ( V_65 -> V_43 ) ,
V_334 ) ;
}
}
static int
F_292 ( struct V_62 * V_63 ,
struct V_418 * V_43 )
{
struct V_42 * V_60 ;
struct V_144 * V_65 ;
int V_135 , V_360 ;
F_293 ( V_63 ) ;
F_294 ( F_41 ( V_63 ) ) ;
if ( ! V_43 )
return 0 ;
F_295 (state, crtc, crtc_state, i) {
V_60 -> V_419 = true ;
}
F_296 ( V_43 ) -> V_420 = true ;
V_360 = F_297 ( V_43 ) ;
F_28 ( V_360 == - V_421 ) ;
return V_360 ;
}
static bool F_298 ( struct V_5 * V_6 )
{
return F_299 ( V_6 ) &&
F_59 ( V_6 ) < 5 && ! F_18 ( V_6 ) ;
}
void F_300 ( struct V_5 * V_6 )
{
struct V_62 * V_63 = & V_6 -> V_422 ;
struct V_423 * V_424 = & V_6 -> V_425 ;
struct V_418 * V_43 ;
int V_360 ;
F_3 ( & V_63 -> V_426 . V_427 ) ;
F_301 ( V_424 , 0 ) ;
while ( 1 ) {
V_360 = F_302 ( V_63 , V_424 ) ;
if ( V_360 != - V_421 )
break;
F_303 ( V_424 ) ;
}
if ( ! V_428 . V_429 &&
! F_298 ( V_6 ) )
return;
V_43 = F_304 ( V_63 , V_424 ) ;
if ( F_194 ( V_43 ) ) {
V_360 = F_242 ( V_43 ) ;
V_43 = NULL ;
F_127 ( L_56 , V_360 ) ;
goto V_72;
}
V_360 = F_305 ( V_63 , V_424 ) ;
if ( V_360 ) {
F_127 ( L_57 , V_360 ) ;
goto V_72;
}
V_6 -> V_430 = V_43 ;
V_43 -> V_431 = V_424 ;
return;
V_72:
F_306 ( V_43 ) ;
}
void F_307 ( struct V_5 * V_6 )
{
struct V_62 * V_63 = & V_6 -> V_422 ;
struct V_423 * V_424 = & V_6 -> V_425 ;
struct V_418 * V_43 = V_6 -> V_430 ;
int V_360 ;
F_288 ( V_6 ) ;
V_6 -> V_430 = NULL ;
if ( ! F_298 ( V_6 ) ) {
if ( ! V_43 ) {
F_290 ( V_63 ) ;
} else {
V_360 = F_292 ( V_63 , V_43 ) ;
if ( V_360 )
F_127 ( L_58 , V_360 ) ;
}
} else {
F_308 ( V_6 ) ;
F_309 ( V_6 ) ;
F_310 ( V_6 ) ;
F_311 ( V_63 ) ;
F_312 ( & V_6 -> V_432 ) ;
if ( V_6 -> V_433 . V_434 )
V_6 -> V_433 . V_434 ( V_6 ) ;
F_313 ( & V_6 -> V_432 ) ;
V_360 = F_292 ( V_63 , V_43 ) ;
if ( V_360 )
F_127 ( L_58 , V_360 ) ;
F_314 ( V_6 ) ;
}
if ( V_43 )
F_306 ( V_43 ) ;
F_315 ( V_424 ) ;
F_316 ( V_424 ) ;
F_5 ( & V_63 -> V_426 . V_427 ) ;
}
static bool F_317 ( struct V_81 * V_65 )
{
struct V_435 * error = & F_41 ( V_65 -> V_64 . V_63 ) -> V_436 ;
if ( F_318 ( error ) )
return true ;
if ( V_65 -> V_437 != F_319 ( error ) )
return true ;
return false ;
}
static bool F_320 ( struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
bool V_438 ;
if ( F_317 ( V_81 ) )
return false ;
F_312 ( & V_63 -> V_439 ) ;
V_438 = F_48 ( V_65 ) -> V_440 != NULL ;
F_313 ( & V_63 -> V_439 ) ;
return V_438 ;
}
static void F_321 ( struct V_81 * V_65 ,
struct V_37 * V_441 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
struct V_37 * V_38 =
F_291 ( V_65 -> V_64 . V_43 ) ;
V_65 -> V_64 . V_414 = V_65 -> V_64 . V_43 -> V_414 ;
F_161 ( L_59 ,
V_441 -> V_365 , V_441 -> V_364 ,
V_38 -> V_365 , V_38 -> V_364 ) ;
F_124 ( F_322 ( V_65 -> V_94 ) ,
( ( V_38 -> V_365 - 1 ) << 16 ) |
( V_38 -> V_364 - 1 ) ) ;
if ( F_59 ( V_6 ) >= 9 ) {
F_273 ( V_65 ) ;
if ( V_38 -> V_442 . V_145 )
F_323 ( V_65 ) ;
} else if ( F_15 ( V_6 ) ) {
if ( V_38 -> V_442 . V_145 )
F_324 ( V_65 ) ;
else if ( V_441 -> V_442 . V_145 )
F_325 ( V_65 , true ) ;
}
}
static void F_326 ( struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_3 V_13 ;
T_1 V_443 ;
V_13 = F_70 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
if ( F_327 ( V_6 ) ) {
V_443 &= ~ V_444 ;
V_443 |= V_444 | V_445 ;
} else {
V_443 &= ~ V_446 ;
V_443 |= V_446 | V_445 ;
}
F_124 ( V_13 , V_443 ) ;
V_13 = F_72 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
if ( F_106 ( V_6 ) ) {
V_443 &= ~ V_447 ;
V_443 |= V_448 ;
} else {
V_443 &= ~ V_446 ;
V_443 |= V_446 ;
}
F_124 ( V_13 , V_443 | V_449 ) ;
F_125 ( V_13 ) ;
F_126 ( 1000 ) ;
if ( F_327 ( V_6 ) )
F_124 ( V_13 , F_11 ( V_13 ) | V_450 |
V_451 ) ;
}
static void F_328 ( struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_3 V_13 ;
T_1 V_443 , V_452 ;
F_329 ( V_6 , V_94 ) ;
V_13 = F_330 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_453 ;
V_443 &= ~ V_454 ;
F_124 ( V_13 , V_443 ) ;
F_11 ( V_13 ) ;
F_126 ( 150 ) ;
V_13 = F_70 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_455 ;
V_443 |= F_331 ( V_81 -> V_90 -> V_456 ) ;
V_443 &= ~ V_446 ;
V_443 |= V_457 ;
F_124 ( V_13 , V_443 | V_107 ) ;
V_13 = F_72 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_446 ;
V_443 |= V_457 ;
F_124 ( V_13 , V_443 | V_108 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
F_124 ( F_332 ( V_94 ) , V_458 ) ;
F_124 ( F_332 ( V_94 ) , V_458 |
V_459 ) ;
V_13 = F_333 ( V_94 ) ;
for ( V_452 = 0 ; V_452 < 5 ; V_452 ++ ) {
V_443 = F_11 ( V_13 ) ;
F_161 ( L_60 , V_443 ) ;
if ( ( V_443 & V_454 ) ) {
F_161 ( L_61 ) ;
F_124 ( V_13 , V_443 | V_454 ) ;
break;
}
}
if ( V_452 == 5 )
F_127 ( L_62 ) ;
V_13 = F_70 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_446 ;
V_443 |= V_460 ;
F_124 ( V_13 , V_443 ) ;
V_13 = F_72 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_446 ;
V_443 |= V_460 ;
F_124 ( V_13 , V_443 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
V_13 = F_333 ( V_94 ) ;
for ( V_452 = 0 ; V_452 < 5 ; V_452 ++ ) {
V_443 = F_11 ( V_13 ) ;
F_161 ( L_60 , V_443 ) ;
if ( V_443 & V_453 ) {
F_124 ( V_13 , V_443 | V_453 ) ;
F_161 ( L_63 ) ;
break;
}
}
if ( V_452 == 5 )
F_127 ( L_64 ) ;
F_161 ( L_65 ) ;
}
static void F_334 ( struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_3 V_13 ;
T_1 V_443 , V_135 , V_461 ;
V_13 = F_330 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_453 ;
V_443 &= ~ V_454 ;
F_124 ( V_13 , V_443 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
V_13 = F_70 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_455 ;
V_443 |= F_331 ( V_81 -> V_90 -> V_456 ) ;
V_443 &= ~ V_446 ;
V_443 |= V_457 ;
V_443 &= ~ V_462 ;
V_443 |= V_463 ;
F_124 ( V_13 , V_443 | V_107 ) ;
F_124 ( F_335 ( V_94 ) ,
V_464 | V_465 ) ;
V_13 = F_72 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
if ( F_106 ( V_6 ) ) {
V_443 &= ~ V_447 ;
V_443 |= V_466 ;
} else {
V_443 &= ~ V_446 ;
V_443 |= V_457 ;
}
F_124 ( V_13 , V_443 | V_108 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
for ( V_135 = 0 ; V_135 < 4 ; V_135 ++ ) {
V_13 = F_70 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_462 ;
V_443 |= V_467 [ V_135 ] ;
F_124 ( V_13 , V_443 ) ;
F_125 ( V_13 ) ;
F_126 ( 500 ) ;
for ( V_461 = 0 ; V_461 < 5 ; V_461 ++ ) {
V_13 = F_333 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
F_161 ( L_60 , V_443 ) ;
if ( V_443 & V_454 ) {
F_124 ( V_13 , V_443 | V_454 ) ;
F_161 ( L_61 ) ;
break;
}
F_126 ( 50 ) ;
}
if ( V_461 < 5 )
break;
}
if ( V_135 == 4 )
F_127 ( L_62 ) ;
V_13 = F_70 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_446 ;
V_443 |= V_460 ;
if ( F_336 ( V_6 ) ) {
V_443 &= ~ V_462 ;
V_443 |= V_463 ;
}
F_124 ( V_13 , V_443 ) ;
V_13 = F_72 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
if ( F_106 ( V_6 ) ) {
V_443 &= ~ V_447 ;
V_443 |= V_468 ;
} else {
V_443 &= ~ V_446 ;
V_443 |= V_460 ;
}
F_124 ( V_13 , V_443 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
for ( V_135 = 0 ; V_135 < 4 ; V_135 ++ ) {
V_13 = F_70 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_462 ;
V_443 |= V_467 [ V_135 ] ;
F_124 ( V_13 , V_443 ) ;
F_125 ( V_13 ) ;
F_126 ( 500 ) ;
for ( V_461 = 0 ; V_461 < 5 ; V_461 ++ ) {
V_13 = F_333 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
F_161 ( L_60 , V_443 ) ;
if ( V_443 & V_453 ) {
F_124 ( V_13 , V_443 | V_453 ) ;
F_161 ( L_63 ) ;
break;
}
F_126 ( 50 ) ;
}
if ( V_461 < 5 )
break;
}
if ( V_135 == 4 )
F_127 ( L_64 ) ;
F_161 ( L_66 ) ;
}
static void F_337 ( struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_3 V_13 ;
T_1 V_443 , V_135 , V_469 ;
V_13 = F_330 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_453 ;
V_443 &= ~ V_454 ;
F_124 ( V_13 , V_443 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
F_161 ( L_67 ,
F_11 ( F_333 ( V_94 ) ) ) ;
for ( V_469 = 0 ; V_469 < F_179 ( V_467 ) * 2 ; V_469 ++ ) {
V_13 = F_70 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ ( V_470 | V_444 ) ;
V_443 &= ~ V_107 ;
F_124 ( V_13 , V_443 ) ;
V_13 = F_72 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_470 ;
V_443 &= ~ V_447 ;
V_443 &= ~ V_108 ;
F_124 ( V_13 , V_443 ) ;
V_13 = F_70 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_455 ;
V_443 |= F_331 ( V_81 -> V_90 -> V_456 ) ;
V_443 |= V_471 ;
V_443 &= ~ V_462 ;
V_443 |= V_467 [ V_469 / 2 ] ;
V_443 |= V_472 ;
F_124 ( V_13 , V_443 | V_107 ) ;
F_124 ( F_335 ( V_94 ) ,
V_464 | V_465 ) ;
V_13 = F_72 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 |= V_466 ;
V_443 |= V_472 ;
F_124 ( V_13 , V_443 | V_108 ) ;
F_125 ( V_13 ) ;
F_126 ( 1 ) ;
for ( V_135 = 0 ; V_135 < 4 ; V_135 ++ ) {
V_13 = F_333 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
F_161 ( L_60 , V_443 ) ;
if ( V_443 & V_454 ||
( F_11 ( V_13 ) & V_454 ) ) {
F_124 ( V_13 , V_443 | V_454 ) ;
F_161 ( L_68 ,
V_135 ) ;
break;
}
F_126 ( 1 ) ;
}
if ( V_135 == 4 ) {
F_161 ( L_69 , V_469 / 2 ) ;
continue;
}
V_13 = F_70 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_444 ;
V_443 |= V_473 ;
F_124 ( V_13 , V_443 ) ;
V_13 = F_72 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_447 ;
V_443 |= V_468 ;
F_124 ( V_13 , V_443 ) ;
F_125 ( V_13 ) ;
F_126 ( 2 ) ;
for ( V_135 = 0 ; V_135 < 4 ; V_135 ++ ) {
V_13 = F_333 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
F_161 ( L_60 , V_443 ) ;
if ( V_443 & V_453 ||
( F_11 ( V_13 ) & V_453 ) ) {
F_124 ( V_13 , V_443 | V_453 ) ;
F_161 ( L_70 ,
V_135 ) ;
goto V_474;
}
F_126 ( 2 ) ;
}
if ( V_135 == 4 )
F_161 ( L_71 , V_469 / 2 ) ;
}
V_474:
F_161 ( L_66 ) ;
}
static void F_338 ( struct V_81 * V_81 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_81 -> V_94 ;
T_3 V_13 ;
T_1 V_443 ;
V_13 = F_72 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ ( V_455 | ( 0x7 << 16 ) ) ;
V_443 |= F_331 ( V_81 -> V_90 -> V_456 ) ;
V_443 |= ( F_11 ( F_60 ( V_94 ) ) & V_207 ) << 11 ;
F_124 ( V_13 , V_443 | V_110 ) ;
F_125 ( V_13 ) ;
F_126 ( 200 ) ;
V_443 = F_11 ( V_13 ) ;
F_124 ( V_13 , V_443 | V_475 ) ;
F_125 ( V_13 ) ;
F_126 ( 200 ) ;
V_13 = F_70 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
if ( ( V_443 & V_109 ) == 0 ) {
F_124 ( V_13 , V_443 | V_109 ) ;
F_125 ( V_13 ) ;
F_126 ( 100 ) ;
}
}
static void F_339 ( struct V_81 * V_81 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_81 -> V_94 ;
T_3 V_13 ;
T_1 V_443 ;
V_13 = F_72 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
F_124 ( V_13 , V_443 & ~ V_475 ) ;
V_13 = F_70 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
F_124 ( V_13 , V_443 & ~ V_109 ) ;
F_125 ( V_13 ) ;
F_126 ( 100 ) ;
V_13 = F_72 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
F_124 ( V_13 , V_443 & ~ V_110 ) ;
F_125 ( V_13 ) ;
F_126 ( 100 ) ;
}
static void F_340 ( struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_3 V_13 ;
T_1 V_443 ;
V_13 = F_70 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
F_124 ( V_13 , V_443 & ~ V_107 ) ;
F_125 ( V_13 ) ;
V_13 = F_72 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ ( 0x7 << 16 ) ;
V_443 |= ( F_11 ( F_60 ( V_94 ) ) & V_207 ) << 11 ;
F_124 ( V_13 , V_443 & ~ V_108 ) ;
F_125 ( V_13 ) ;
F_126 ( 100 ) ;
if ( F_120 ( V_6 ) )
F_124 ( F_332 ( V_94 ) , V_458 ) ;
V_13 = F_70 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ V_446 ;
V_443 |= V_457 ;
F_124 ( V_13 , V_443 ) ;
V_13 = F_72 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
if ( F_106 ( V_6 ) ) {
V_443 &= ~ V_447 ;
V_443 |= V_466 ;
} else {
V_443 &= ~ V_446 ;
V_443 |= V_457 ;
}
V_443 &= ~ ( 0x07 << 16 ) ;
V_443 |= ( F_11 ( F_60 ( V_94 ) ) & V_207 ) << 11 ;
F_124 ( V_13 , V_443 ) ;
F_125 ( V_13 ) ;
F_126 ( 100 ) ;
}
bool F_341 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_65 ;
F_138 (dev, crtc) {
if ( F_342 ( & V_65 -> V_476 ) == 0 )
continue;
if ( V_65 -> V_440 )
F_343 ( V_6 , V_65 -> V_94 ) ;
return true ;
}
return false ;
}
static void F_344 ( struct V_81 * V_81 )
{
struct V_5 * V_6 = F_41 ( V_81 -> V_64 . V_63 ) ;
struct V_1 * V_2 = V_81 -> V_440 ;
V_81 -> V_440 = NULL ;
if ( V_2 -> V_477 )
F_345 ( & V_81 -> V_64 , V_2 -> V_477 ) ;
F_102 ( & V_81 -> V_64 ) ;
F_346 ( & V_6 -> V_478 ) ;
F_347 ( V_81 -> V_133 ,
V_2 -> V_479 ) ;
F_348 ( V_6 -> V_480 , & V_2 -> V_481 ) ;
}
static int F_349 ( struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
long V_360 ;
F_28 ( F_350 ( & V_6 -> V_478 ) ) ;
V_360 = F_351 (
V_6 -> V_478 ,
! F_320 ( V_65 ) ,
60 * V_482 ) ;
if ( V_360 < 0 )
return V_360 ;
if ( V_360 == 0 ) {
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_1 * V_2 ;
F_312 ( & V_63 -> V_439 ) ;
V_2 = V_81 -> V_440 ;
if ( V_2 && ! F_1 ( V_2 ) ) {
F_352 ( 1 , L_72 ) ;
F_344 ( V_81 ) ;
}
F_313 ( & V_63 -> V_439 ) ;
}
return 0 ;
}
void F_353 ( struct V_5 * V_6 )
{
T_1 V_443 ;
F_124 ( V_483 , V_484 ) ;
F_3 ( & V_6 -> V_9 ) ;
V_443 = F_354 ( V_6 , V_485 , V_486 ) ;
V_443 |= V_487 ;
F_355 ( V_6 , V_485 , V_443 , V_486 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_356 ( struct V_144 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
int clock = F_48 ( V_65 ) -> V_90 -> V_64 . V_91 . V_92 ;
T_1 V_488 , V_489 , V_490 , V_491 = 0 ;
T_1 V_443 ;
F_353 ( V_6 ) ;
for ( V_490 = 0 ; V_490 < 2 ; V_490 ++ ) {
T_1 V_492 = 172800 * 1000 ;
T_1 V_493 = 64 ;
T_1 V_494 ;
V_494 = F_8 ( V_492 ,
clock << V_490 ) ;
V_488 = ( V_494 / V_493 ) - 2 ;
V_489 = V_494 % V_493 ;
if ( V_488 <= 0x7f )
break;
}
F_28 ( F_357 ( V_488 ) &
~ V_495 ) ;
F_28 ( F_358 ( V_491 ) &
~ V_496 ) ;
F_161 ( L_73 ,
clock ,
V_490 ,
V_488 ,
V_491 ,
V_489 ) ;
F_3 ( & V_6 -> V_9 ) ;
V_443 = F_354 ( V_6 , V_497 , V_486 ) ;
V_443 &= ~ V_495 ;
V_443 |= F_357 ( V_488 ) ;
V_443 &= ~ V_496 ;
V_443 |= F_359 ( V_489 ) ;
V_443 |= F_358 ( V_491 ) ;
V_443 |= V_498 ;
F_355 ( V_6 , V_497 , V_443 , V_486 ) ;
V_443 = F_354 ( V_6 , V_499 , V_486 ) ;
V_443 &= ~ F_360 ( 1 ) ;
V_443 |= F_360 ( V_490 ) ;
F_355 ( V_6 , V_499 , V_443 , V_486 ) ;
V_443 = F_354 ( V_6 , V_485 , V_486 ) ;
V_443 &= ~ V_487 ;
F_355 ( V_6 , V_485 , V_443 , V_486 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_126 ( 24 ) ;
F_124 ( V_483 , V_500 ) ;
}
int F_361 ( struct V_5 * V_6 )
{
T_1 V_488 , V_489 , V_490 ;
T_1 V_492 = 172800 * 1000 ;
T_1 V_493 = 64 ;
T_1 V_494 ;
T_1 V_443 ;
if ( ( F_11 ( V_483 ) & V_500 ) == 0 )
return 0 ;
F_3 ( & V_6 -> V_9 ) ;
V_443 = F_354 ( V_6 , V_485 , V_486 ) ;
if ( V_443 & V_487 ) {
F_5 ( & V_6 -> V_9 ) ;
return 0 ;
}
V_443 = F_354 ( V_6 , V_497 , V_486 ) ;
V_488 = ( V_443 & V_495 ) >>
V_501 ;
V_489 = ( V_443 & V_496 ) >>
V_502 ;
V_443 = F_354 ( V_6 , V_499 , V_486 ) ;
V_490 = ( V_443 & V_503 ) >>
V_504 ;
F_5 ( & V_6 -> V_9 ) ;
V_494 = ( V_488 + 2 ) * V_493 + V_489 ;
return F_8 ( V_492 ,
V_494 << V_490 ) ;
}
static void F_362 ( struct V_81 * V_65 ,
enum V_94 V_505 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_93 V_95 = V_65 -> V_90 -> V_95 ;
F_124 ( F_363 ( V_505 ) ,
F_11 ( F_364 ( V_95 ) ) ) ;
F_124 ( F_365 ( V_505 ) ,
F_11 ( F_366 ( V_95 ) ) ) ;
F_124 ( F_367 ( V_505 ) ,
F_11 ( F_368 ( V_95 ) ) ) ;
F_124 ( F_369 ( V_505 ) ,
F_11 ( F_370 ( V_95 ) ) ) ;
F_124 ( F_371 ( V_505 ) ,
F_11 ( F_372 ( V_95 ) ) ) ;
F_124 ( F_373 ( V_505 ) ,
F_11 ( F_374 ( V_95 ) ) ) ;
F_124 ( F_375 ( V_505 ) ,
F_11 ( F_376 ( V_95 ) ) ) ;
}
static void F_377 ( struct V_62 * V_63 , bool V_506 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_2 V_443 ;
V_443 = F_11 ( V_507 ) ;
if ( ! ! ( V_443 & V_508 ) == V_506 )
return;
F_28 ( F_11 ( F_72 ( V_120 ) ) & V_108 ) ;
F_28 ( F_11 ( F_72 ( V_509 ) ) & V_108 ) ;
V_443 &= ~ V_508 ;
if ( V_506 )
V_443 |= V_508 ;
F_161 ( L_74 , V_506 ? L_75 : L_76 ) ;
F_124 ( V_507 , V_443 ) ;
F_125 ( V_507 ) ;
}
static void F_378 ( struct V_81 * V_81 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
switch ( V_81 -> V_94 ) {
case V_113 :
break;
case V_120 :
if ( V_81 -> V_90 -> V_456 > 2 )
F_377 ( V_63 , false ) ;
else
F_377 ( V_63 , true ) ;
break;
case V_509 :
F_377 ( V_63 , true ) ;
break;
default:
F_146 () ;
}
}
static enum V_177
F_379 ( struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_510 * V_511 ;
F_380 (dev, crtc, encoder) {
if ( V_511 -> type == V_512 ||
V_511 -> type == V_513 )
return F_381 ( & V_511 -> V_64 ) -> V_177 ;
}
return - 1 ;
}
static void F_382 ( struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_1 V_443 ;
F_103 ( V_6 , V_94 ) ;
if ( F_327 ( V_6 ) )
F_378 ( V_81 ) ;
F_124 ( F_383 ( V_94 ) ,
F_11 ( F_384 ( V_94 ) ) & V_514 ) ;
V_6 -> V_433 . V_515 ( V_65 ) ;
if ( F_106 ( V_6 ) ) {
T_1 V_516 ;
V_443 = F_11 ( V_517 ) ;
V_443 |= F_385 ( V_94 ) ;
V_516 = F_386 ( V_94 ) ;
if ( V_81 -> V_90 -> V_205 ==
F_387 ( V_6 , V_518 ) )
V_443 |= V_516 ;
else
V_443 &= ~ V_516 ;
F_124 ( V_517 , V_443 ) ;
}
F_388 ( V_81 ) ;
F_75 ( V_6 , V_94 ) ;
F_362 ( V_81 , V_94 ) ;
F_326 ( V_65 ) ;
if ( F_106 ( V_6 ) &&
F_389 ( V_81 -> V_90 ) ) {
const struct V_519 * V_91 =
& V_81 -> V_90 -> V_64 . V_91 ;
T_1 V_520 = ( F_11 ( F_60 ( V_94 ) ) & V_207 ) >> 5 ;
T_3 V_13 = F_107 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ ( V_149 |
V_521 |
V_522 ) ;
V_443 |= V_523 ;
V_443 |= V_520 << 9 ;
if ( V_91 -> V_328 & V_524 )
V_443 |= V_525 ;
if ( V_91 -> V_328 & V_526 )
V_443 |= V_527 ;
switch ( F_379 ( V_65 ) ) {
case V_197 :
V_443 |= V_164 ;
break;
case V_199 :
V_443 |= V_166 ;
break;
case V_201 :
V_443 |= V_168 ;
break;
default:
F_146 () ;
}
F_124 ( V_13 , V_443 ) ;
}
F_148 ( V_6 , V_94 ) ;
}
static void F_390 ( struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
enum V_93 V_95 = V_81 -> V_90 -> V_95 ;
F_103 ( V_6 , V_218 ) ;
F_356 ( V_65 ) ;
F_362 ( V_81 , V_113 ) ;
F_153 ( V_6 , V_95 ) ;
}
static void F_391 ( struct V_62 * V_63 , int V_94 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_3 V_528 = F_55 ( V_94 ) ;
T_1 V_443 ;
V_443 = F_11 ( V_528 ) ;
F_126 ( 500 ) ;
if ( F_62 ( F_11 ( V_528 ) != V_443 , 5 ) ) {
if ( F_62 ( F_11 ( V_528 ) != V_443 , 5 ) )
F_127 ( L_77 , F_78 ( V_94 ) ) ;
}
}
static int
F_392 ( struct V_37 * V_60 , bool V_529 ,
unsigned V_530 , int * V_404 , unsigned int V_245 ,
int V_343 , int V_344 , int V_407 , int V_408 )
{
struct V_378 * V_379 =
& V_60 -> V_379 ;
struct V_81 * V_81 =
F_48 ( V_60 -> V_64 . V_65 ) ;
int V_531 ;
V_531 = F_181 ( V_245 ) ?
( V_344 != V_407 || V_343 != V_408 ) :
( V_343 != V_407 || V_344 != V_408 ) ;
if ( V_529 || ! V_531 ) {
if ( * V_404 >= 0 ) {
V_379 -> V_532 &= ~ ( 1 << V_530 ) ;
V_379 -> V_381 [ * V_404 ] . V_382 = 0 ;
F_161 ( L_78
L_79 ,
V_81 -> V_94 , V_530 , * V_404 ,
V_379 -> V_532 ) ;
* V_404 = - 1 ;
}
return 0 ;
}
if ( V_343 < V_533 || V_344 < V_534 ||
V_407 < V_535 || V_408 < V_536 ||
V_343 > V_537 || V_344 > V_538 ||
V_407 > V_539 || V_408 > V_540 ) {
F_161 ( L_80
L_81 ,
V_81 -> V_94 , V_530 , V_343 , V_344 , V_407 , V_408 ) ;
return - V_286 ;
}
V_379 -> V_532 |= ( 1 << V_530 ) ;
F_161 ( L_78
L_82 ,
V_81 -> V_94 , V_530 , V_343 , V_344 , V_407 , V_408 ,
V_379 -> V_532 ) ;
return 0 ;
}
int F_393 ( struct V_37 * V_43 )
{
const struct V_519 * V_91 = & V_43 -> V_64 . V_91 ;
return F_392 ( V_43 , ! V_43 -> V_64 . V_87 , V_541 ,
& V_43 -> V_379 . V_404 , V_287 ,
V_43 -> V_365 , V_43 -> V_364 ,
V_91 -> V_542 , V_91 -> V_543 ) ;
}
static int F_394 ( struct V_37 * V_60 ,
struct V_263 * V_334 )
{
struct V_335 * V_335 =
F_235 ( V_334 -> V_64 . V_133 ) ;
struct V_244 * V_89 = V_334 -> V_64 . V_89 ;
int V_360 ;
bool V_529 = ! V_89 || ! V_334 -> V_64 . V_338 ;
V_360 = F_392 ( V_60 , V_529 ,
F_240 ( & V_335 -> V_64 ) ,
& V_334 -> V_404 ,
V_334 -> V_64 . V_245 ,
F_248 ( & V_334 -> V_64 . V_349 ) >> 16 ,
F_249 ( & V_334 -> V_64 . V_349 ) >> 16 ,
F_248 ( & V_334 -> V_64 . V_350 ) ,
F_249 ( & V_334 -> V_64 . V_350 ) ) ;
if ( V_360 || V_334 -> V_404 < 0 )
return V_360 ;
if ( V_334 -> V_544 . V_328 != V_545 ) {
F_161 ( L_83 ,
V_335 -> V_64 . V_64 . V_377 ,
V_335 -> V_64 . V_12 ) ;
return - V_286 ;
}
switch ( V_89 -> V_237 ) {
case V_300 :
case V_304 :
case V_302 :
case V_313 :
case V_314 :
case V_306 :
case V_308 :
case V_386 :
case V_389 :
case V_391 :
case V_393 :
break;
default:
F_161 ( L_84 ,
V_335 -> V_64 . V_64 . V_377 , V_335 -> V_64 . V_12 ,
V_89 -> V_64 . V_377 , V_89 -> V_237 ) ;
return - V_286 ;
}
return 0 ;
}
static void F_395 ( struct V_81 * V_65 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < V_65 -> V_380 ; V_135 ++ )
F_269 ( V_65 , V_135 ) ;
}
static void F_323 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_65 -> V_94 ;
struct V_378 * V_379 =
& V_65 -> V_90 -> V_379 ;
F_161 ( L_85 , V_65 -> V_90 ) ;
if ( V_65 -> V_90 -> V_442 . V_145 ) {
int V_377 ;
if ( F_28 ( V_65 -> V_90 -> V_379 . V_404 < 0 ) ) {
F_127 ( L_86 ) ;
return;
}
V_377 = V_379 -> V_404 ;
F_124 ( F_270 ( V_94 , V_377 ) , V_413 |
V_546 | V_379 -> V_381 [ V_377 ] . V_414 ) ;
F_124 ( F_271 ( V_94 , V_377 ) , V_65 -> V_90 -> V_442 . V_547 ) ;
F_124 ( F_272 ( V_94 , V_377 ) , V_65 -> V_90 -> V_442 . V_240 ) ;
F_161 ( L_87 , V_65 -> V_90 , V_377 ) ;
}
}
static void F_324 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_65 -> V_94 ;
if ( V_65 -> V_90 -> V_442 . V_145 ) {
if ( F_327 ( V_6 ) || F_265 ( V_6 ) )
F_124 ( F_396 ( V_94 ) , V_548 | V_549 |
F_397 ( V_94 ) ) ;
else
F_124 ( F_396 ( V_94 ) , V_548 | V_549 ) ;
F_124 ( F_398 ( V_94 ) , V_65 -> V_90 -> V_442 . V_547 ) ;
F_124 ( F_399 ( V_94 ) , V_65 -> V_90 -> V_442 . V_240 ) ;
}
}
void F_400 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
if ( ! V_65 -> V_90 -> V_550 )
return;
F_401 ( V_6 , V_65 -> V_133 ) ;
if ( F_266 ( V_6 ) ) {
F_3 ( & V_6 -> V_551 . V_552 ) ;
F_28 ( F_402 ( V_6 , V_553 , 0xc0000000 ) ) ;
F_5 ( & V_6 -> V_551 . V_552 ) ;
} else {
F_124 ( V_554 , V_555 ) ;
if ( F_61 ( V_6 ,
V_554 , V_555 , V_555 ,
50 ) )
F_127 ( L_88 ) ;
}
}
void F_403 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
if ( ! V_65 -> V_90 -> V_550 )
return;
F_401 ( V_6 , V_65 -> V_133 ) ;
if ( F_266 ( V_6 ) ) {
F_3 ( & V_6 -> V_551 . V_552 ) ;
F_28 ( F_402 ( V_6 , V_553 , 0 ) ) ;
F_5 ( & V_6 -> V_551 . V_552 ) ;
if ( F_61 ( V_6 ,
V_554 , V_555 , 0 ,
42 ) )
F_127 ( L_89 ) ;
} else {
F_124 ( V_554 , 0 ) ;
F_125 ( V_554 ) ;
}
F_343 ( V_6 , V_65 -> V_94 ) ;
}
static void F_404 ( struct V_81 * V_81 )
{
if ( V_81 -> V_556 ) {
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
F_3 ( & V_63 -> V_256 ) ;
V_6 -> V_557 . V_558 = false ;
( void ) F_405 ( V_81 -> V_556 ) ;
V_6 -> V_557 . V_558 = true ;
F_5 ( & V_63 -> V_256 ) ;
}
}
static void
F_406 ( struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
F_400 ( V_81 ) ;
if ( F_56 ( V_6 ) )
F_407 ( V_6 , V_94 , true ) ;
F_408 ( V_6 ) ;
F_409 ( V_6 ) ;
}
static void
F_410 ( struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
if ( F_56 ( V_6 ) )
F_407 ( V_6 , V_94 , false ) ;
F_403 ( V_81 ) ;
}
static void
F_241 ( struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
F_410 ( V_65 ) ;
if ( F_163 ( V_6 ) ) {
F_411 ( V_6 , false ) ;
V_6 -> V_559 . V_560 . V_561 = false ;
F_343 ( V_6 , V_94 ) ;
}
}
static void F_412 ( struct V_37 * V_441 )
{
struct V_81 * V_65 = F_48 ( V_441 -> V_64 . V_65 ) ;
struct V_418 * V_562 = V_441 -> V_64 . V_43 ;
struct V_37 * V_38 =
F_291 ( V_65 -> V_64 . V_43 ) ;
struct V_331 * V_88 = V_65 -> V_64 . V_88 ;
struct V_333 * V_563 =
F_413 ( V_562 , V_88 ) ;
F_414 ( F_41 ( V_65 -> V_64 . V_63 ) , V_38 -> V_564 ) ;
V_65 -> V_559 . V_565 = true ;
if ( V_38 -> V_566 && V_38 -> V_64 . V_87 )
F_415 ( V_65 ) ;
if ( V_563 ) {
struct V_263 * V_567 =
F_236 ( V_88 -> V_43 ) ;
struct V_263 * V_568 =
F_236 ( V_563 ) ;
F_416 ( V_65 ) ;
if ( V_567 -> V_64 . V_338 &&
( F_25 ( & V_38 -> V_64 ) ||
! V_568 -> V_64 . V_338 ) )
F_406 ( & V_65 -> V_64 ) ;
}
}
static void F_417 ( struct V_37 * V_441 )
{
struct V_81 * V_65 = F_48 ( V_441 -> V_64 . V_65 ) ;
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_37 * V_38 =
F_291 ( V_65 -> V_64 . V_43 ) ;
struct V_418 * V_562 = V_441 -> V_64 . V_43 ;
struct V_331 * V_88 = V_65 -> V_64 . V_88 ;
struct V_333 * V_563 =
F_413 ( V_562 , V_88 ) ;
bool V_569 = F_25 ( & V_38 -> V_64 ) ;
struct V_570 * V_571 =
F_296 ( V_562 ) ;
if ( V_563 ) {
struct V_263 * V_567 =
F_236 ( V_88 -> V_43 ) ;
struct V_263 * V_568 =
F_236 ( V_563 ) ;
F_418 ( V_65 , V_38 , V_567 ) ;
if ( V_568 -> V_64 . V_338 &&
( V_569 || ! V_567 -> V_64 . V_338 ) )
F_410 ( & V_65 -> V_64 ) ;
}
if ( V_38 -> V_572 && F_163 ( V_6 ) ) {
V_65 -> V_559 . V_565 = false ;
if ( V_441 -> V_64 . V_87 ) {
F_411 ( V_6 , false ) ;
V_6 -> V_559 . V_560 . V_561 = false ;
F_343 ( V_6 , V_65 -> V_94 ) ;
}
}
if ( V_38 -> V_573 ) {
F_419 ( V_63 ) ;
F_343 ( V_6 , V_65 -> V_94 ) ;
}
if ( F_25 ( & V_38 -> V_64 ) )
return;
if ( V_6 -> V_433 . V_574 != NULL )
V_6 -> V_433 . V_574 ( V_571 ,
V_38 ) ;
else if ( V_38 -> V_575 )
F_415 ( V_65 ) ;
}
static void F_420 ( struct V_144 * V_65 , unsigned V_339 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_331 * V_48 ;
int V_94 = V_81 -> V_94 ;
F_404 ( V_81 ) ;
F_421 (p, dev, plane_mask)
F_235 ( V_48 ) -> V_340 ( V_48 , V_65 ) ;
F_414 ( F_41 ( V_63 ) , F_422 ( V_94 ) ) ;
}
static void F_423 ( struct V_144 * V_65 ,
struct V_37 * V_60 ,
struct V_418 * V_562 )
{
struct V_576 * V_577 ;
struct V_578 * V_579 ;
int V_135 ;
F_424 (old_state, conn, old_conn_state, i) {
struct V_576 * V_580 = V_579 -> V_43 ;
struct V_510 * V_511 =
F_425 ( V_580 -> V_581 ) ;
if ( V_580 -> V_65 != V_65 )
continue;
if ( V_511 -> V_582 )
V_511 -> V_582 ( V_511 , V_60 , V_580 ) ;
}
}
static void F_426 ( struct V_144 * V_65 ,
struct V_37 * V_60 ,
struct V_418 * V_562 )
{
struct V_576 * V_577 ;
struct V_578 * V_579 ;
int V_135 ;
F_424 (old_state, conn, old_conn_state, i) {
struct V_576 * V_580 = V_579 -> V_43 ;
struct V_510 * V_511 =
F_425 ( V_580 -> V_581 ) ;
if ( V_580 -> V_65 != V_65 )
continue;
if ( V_511 -> V_583 )
V_511 -> V_583 ( V_511 , V_60 , V_580 ) ;
}
}
static void F_427 ( struct V_144 * V_65 ,
struct V_37 * V_60 ,
struct V_418 * V_562 )
{
struct V_576 * V_577 ;
struct V_578 * V_579 ;
int V_135 ;
F_424 (old_state, conn, old_conn_state, i) {
struct V_576 * V_580 = V_579 -> V_43 ;
struct V_510 * V_511 =
F_425 ( V_580 -> V_581 ) ;
if ( V_580 -> V_65 != V_65 )
continue;
V_511 -> V_506 ( V_511 , V_60 , V_580 ) ;
F_428 ( V_511 , true ) ;
}
}
static void F_429 ( struct V_144 * V_65 ,
struct V_37 * V_441 ,
struct V_418 * V_562 )
{
struct V_576 * V_577 ;
struct V_578 * V_579 ;
int V_135 ;
F_424 (old_state, conn, old_conn_state, i) {
struct V_510 * V_511 =
F_425 ( V_577 -> V_581 ) ;
if ( V_577 -> V_65 != V_65 )
continue;
F_428 ( V_511 , false ) ;
V_511 -> V_584 ( V_511 , V_441 , V_577 ) ;
}
}
static void F_430 ( struct V_144 * V_65 ,
struct V_37 * V_441 ,
struct V_418 * V_562 )
{
struct V_576 * V_577 ;
struct V_578 * V_579 ;
int V_135 ;
F_424 (old_state, conn, old_conn_state, i) {
struct V_510 * V_511 =
F_425 ( V_577 -> V_581 ) ;
if ( V_577 -> V_65 != V_65 )
continue;
if ( V_511 -> V_585 )
V_511 -> V_585 ( V_511 , V_441 , V_577 ) ;
}
}
static void F_431 ( struct V_144 * V_65 ,
struct V_37 * V_441 ,
struct V_418 * V_562 )
{
struct V_576 * V_577 ;
struct V_578 * V_579 ;
int V_135 ;
F_424 (old_state, conn, old_conn_state, i) {
struct V_510 * V_511 =
F_425 ( V_577 -> V_581 ) ;
if ( V_577 -> V_65 != V_65 )
continue;
if ( V_511 -> V_586 )
V_511 -> V_586 ( V_511 , V_441 , V_577 ) ;
}
}
static void F_432 ( struct V_37 * V_38 ,
struct V_418 * V_562 )
{
struct V_144 * V_65 = V_38 -> V_64 . V_65 ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
struct V_570 * V_571 =
F_296 ( V_562 ) ;
if ( F_28 ( V_81 -> V_87 ) )
return;
if ( V_81 -> V_90 -> V_221 || F_24 ( V_6 ) )
F_407 ( V_6 , V_94 , false ) ;
if ( V_81 -> V_90 -> V_221 )
F_433 ( V_6 , V_94 , false ) ;
if ( V_81 -> V_90 -> V_221 )
F_434 ( V_81 ) ;
if ( F_389 ( V_81 -> V_90 ) )
F_435 ( V_81 , V_587 ) ;
F_436 ( V_81 ) ;
F_437 ( V_81 ) ;
if ( V_81 -> V_90 -> V_221 ) {
F_438 ( V_81 ,
& V_81 -> V_90 -> V_588 , NULL ) ;
}
F_439 ( V_65 ) ;
V_81 -> V_87 = true ;
F_426 ( V_65 , V_38 , V_562 ) ;
if ( V_81 -> V_90 -> V_221 ) {
F_338 ( V_81 ) ;
} else {
F_155 ( V_6 , V_94 ) ;
F_156 ( V_6 , V_94 ) ;
}
F_324 ( V_81 ) ;
F_440 ( & V_38 -> V_64 ) ;
if ( V_6 -> V_433 . V_574 != NULL )
V_6 -> V_433 . V_574 ( V_571 , V_81 -> V_90 ) ;
F_160 ( V_81 ) ;
if ( V_81 -> V_90 -> V_221 )
F_382 ( V_65 ) ;
F_99 ( V_65 ) ;
F_441 ( V_65 ) ;
F_427 ( V_65 , V_38 , V_562 ) ;
if ( F_106 ( V_6 ) )
F_391 ( V_63 , V_81 -> V_94 ) ;
if ( V_81 -> V_90 -> V_221 )
F_343 ( V_6 , V_94 ) ;
F_407 ( V_6 , V_94 , true ) ;
F_433 ( V_6 , V_94 , true ) ;
}
static bool F_442 ( struct V_81 * V_65 )
{
return F_443 ( F_41 ( V_65 -> V_64 . V_63 ) ) && V_65 -> V_94 == V_113 ;
}
static void F_444 ( struct V_37 * V_38 ,
struct V_418 * V_562 )
{
struct V_144 * V_65 = V_38 -> V_64 . V_65 ;
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 , V_589 ;
enum V_93 V_95 = V_81 -> V_90 -> V_95 ;
struct V_570 * V_571 =
F_296 ( V_562 ) ;
if ( F_28 ( V_81 -> V_87 ) )
return;
if ( V_81 -> V_90 -> V_221 )
F_433 ( V_6 , V_218 ,
false ) ;
F_423 ( V_65 , V_38 , V_562 ) ;
if ( V_81 -> V_90 -> V_205 )
F_388 ( V_81 ) ;
if ( F_389 ( V_81 -> V_90 ) )
F_435 ( V_81 , V_587 ) ;
if ( ! F_445 ( V_95 ) )
F_436 ( V_81 ) ;
F_437 ( V_81 ) ;
if ( V_95 != V_590 &&
! F_445 ( V_95 ) ) {
F_124 ( F_446 ( V_95 ) ,
V_81 -> V_90 -> V_591 - 1 ) ;
}
if ( V_81 -> V_90 -> V_221 ) {
F_438 ( V_81 ,
& V_81 -> V_90 -> V_588 , NULL ) ;
}
if ( ! F_445 ( V_95 ) )
F_447 ( V_65 ) ;
F_448 ( V_65 ) ;
F_449 ( & V_38 -> V_64 ) ;
V_81 -> V_87 = true ;
if ( V_81 -> V_90 -> V_221 )
F_407 ( V_6 , V_94 , false ) ;
else
F_407 ( V_6 , V_94 , true ) ;
F_426 ( V_65 , V_38 , V_562 ) ;
if ( V_81 -> V_90 -> V_221 )
V_6 -> V_433 . V_515 ( V_65 ) ;
if ( ! F_445 ( V_95 ) )
F_450 ( V_81 ) ;
if ( F_59 ( V_6 ) >= 9 )
F_323 ( V_81 ) ;
else
F_324 ( V_81 ) ;
F_440 ( & V_38 -> V_64 ) ;
F_451 ( V_65 ) ;
if ( ! F_445 ( V_95 ) )
F_452 ( V_65 ) ;
if ( V_6 -> V_433 . V_574 != NULL )
V_6 -> V_433 . V_574 ( V_571 ,
V_38 ) ;
else
F_415 ( V_81 ) ;
if ( ! F_445 ( V_95 ) )
F_160 ( V_81 ) ;
if ( V_81 -> V_90 -> V_221 )
F_390 ( V_65 ) ;
if ( F_38 ( V_81 -> V_90 , V_592 ) )
F_453 ( V_65 , true ) ;
F_99 ( V_65 ) ;
F_441 ( V_65 ) ;
F_427 ( V_65 , V_38 , V_562 ) ;
if ( V_81 -> V_90 -> V_221 ) {
F_343 ( V_6 , V_94 ) ;
F_343 ( V_6 , V_94 ) ;
F_407 ( V_6 , V_94 , true ) ;
F_433 ( V_6 , V_218 ,
true ) ;
}
V_589 = V_38 -> V_589 ;
if ( F_265 ( V_6 ) && V_589 != V_593 ) {
F_343 ( V_6 , V_589 ) ;
F_343 ( V_6 , V_589 ) ;
}
}
static void F_325 ( struct V_81 * V_65 , bool V_594 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_65 -> V_94 ;
if ( V_594 || V_65 -> V_90 -> V_442 . V_145 ) {
F_124 ( F_396 ( V_94 ) , 0 ) ;
F_124 ( F_398 ( V_94 ) , 0 ) ;
F_124 ( F_399 ( V_94 ) , 0 ) ;
}
}
static void F_454 ( struct V_37 * V_441 ,
struct V_418 * V_562 )
{
struct V_144 * V_65 = V_441 -> V_64 . V_65 ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
if ( V_81 -> V_90 -> V_221 ) {
F_407 ( V_6 , V_94 , false ) ;
F_433 ( V_6 , V_94 , false ) ;
}
F_429 ( V_65 , V_441 , V_562 ) ;
F_455 ( V_65 ) ;
F_99 ( V_65 ) ;
F_168 ( V_81 ) ;
F_325 ( V_81 , false ) ;
if ( V_81 -> V_90 -> V_221 )
F_340 ( V_65 ) ;
F_430 ( V_65 , V_441 , V_562 ) ;
if ( V_81 -> V_90 -> V_221 ) {
F_154 ( V_6 , V_94 ) ;
if ( F_106 ( V_6 ) ) {
T_3 V_13 ;
T_1 V_443 ;
V_13 = F_107 ( V_94 ) ;
V_443 = F_11 ( V_13 ) ;
V_443 &= ~ ( V_523 |
V_149 ) ;
V_443 |= V_595 ;
F_124 ( V_13 , V_443 ) ;
V_443 = F_11 ( V_517 ) ;
V_443 &= ~ ( F_385 ( V_94 ) | F_386 ( V_94 ) ) ;
F_124 ( V_517 , V_443 ) ;
}
F_339 ( V_81 ) ;
}
F_407 ( V_6 , V_94 , true ) ;
F_433 ( V_6 , V_94 , true ) ;
}
static void F_456 ( struct V_37 * V_441 ,
struct V_418 * V_562 )
{
struct V_144 * V_65 = V_441 -> V_64 . V_65 ;
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
enum V_93 V_95 = V_81 -> V_90 -> V_95 ;
if ( V_81 -> V_90 -> V_221 )
F_433 ( V_6 , V_218 ,
false ) ;
F_429 ( V_65 , V_441 , V_562 ) ;
F_455 ( V_65 ) ;
F_99 ( V_65 ) ;
if ( ! F_445 ( V_95 ) )
F_168 ( V_81 ) ;
if ( F_38 ( V_81 -> V_90 , V_592 ) )
F_453 ( V_65 , false ) ;
if ( ! F_445 ( V_95 ) )
F_457 ( V_6 , V_95 ) ;
if ( F_59 ( V_6 ) >= 9 )
F_395 ( V_81 ) ;
else
F_325 ( V_81 , false ) ;
if ( ! F_445 ( V_95 ) )
F_458 ( V_81 ) ;
F_430 ( V_65 , V_441 , V_562 ) ;
if ( V_441 -> V_221 )
F_433 ( V_6 , V_218 ,
true ) ;
}
static void F_459 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_37 * V_38 = V_65 -> V_90 ;
if ( ! V_38 -> V_596 . V_597 )
return;
F_28 ( F_11 ( V_598 ) & V_599 ) ;
F_129 ( V_6 , V_65 -> V_94 ) ;
F_124 ( V_600 , V_38 -> V_596 . V_601 ) ;
F_124 ( V_598 , V_38 -> V_596 . V_597 ) ;
F_124 ( F_460 ( V_65 -> V_94 ) , 0 ) ;
}
static enum V_127 F_461 ( enum V_177 V_177 )
{
switch ( V_177 ) {
case V_602 :
return V_603 ;
case V_197 :
return V_604 ;
case V_199 :
return V_605 ;
case V_201 :
return V_606 ;
case V_607 :
return V_608 ;
default:
F_172 ( V_177 ) ;
return V_609 ;
}
}
static enum V_127 F_462 ( enum V_177 V_177 )
{
switch ( V_177 ) {
case V_602 :
return V_610 ;
case V_197 :
return V_611 ;
case V_199 :
return V_612 ;
case V_201 :
return V_613 ;
case V_607 :
return V_613 ;
default:
F_172 ( V_177 ) ;
return V_610 ;
}
}
enum V_127
F_463 ( struct V_510 * V_510 )
{
struct V_5 * V_6 = F_41 ( V_510 -> V_64 . V_63 ) ;
struct V_192 * V_614 ;
switch ( V_510 -> type ) {
case V_615 :
F_45 ( ! F_23 ( V_6 ) ) ;
case V_512 :
case V_208 :
case V_513 :
V_614 = F_381 ( & V_510 -> V_64 ) ;
return F_461 ( V_614 -> V_177 ) ;
case V_592 :
V_614 = F_464 ( & V_510 -> V_64 ) -> V_88 ;
return F_461 ( V_614 -> V_177 ) ;
case V_616 :
return V_617 ;
case V_222 :
return V_618 ;
default:
return V_609 ;
}
}
enum V_127
F_465 ( struct V_510 * V_510 )
{
struct V_5 * V_6 = F_41 ( V_510 -> V_64 . V_63 ) ;
struct V_192 * V_614 ;
switch ( V_510 -> type ) {
case V_615 :
case V_208 :
F_45 ( ! F_23 ( V_6 ) ) ;
case V_512 :
case V_513 :
V_614 = F_381 ( & V_510 -> V_64 ) ;
return F_462 ( V_614 -> V_177 ) ;
case V_592 :
V_614 = F_464 ( & V_510 -> V_64 ) -> V_88 ;
return F_462 ( V_614 -> V_177 ) ;
default:
F_172 ( V_510 -> type ) ;
return V_610 ;
}
}
static unsigned long F_466 ( struct V_144 * V_65 ,
struct V_37 * V_60 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_619 * V_511 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
enum V_94 V_94 = V_81 -> V_94 ;
unsigned long V_620 ;
enum V_93 V_93 = V_60 -> V_95 ;
if ( ! V_60 -> V_64 . V_87 )
return 0 ;
V_620 = F_467 ( F_468 ( V_94 ) ) ;
V_620 |= F_467 ( F_84 ( V_93 ) ) ;
if ( V_60 -> V_442 . V_145 ||
V_60 -> V_442 . V_621 )
V_620 |= F_467 ( F_469 ( V_94 ) ) ;
F_470 (encoder, dev, crtc_state->base.encoder_mask) {
struct V_510 * V_510 = F_425 ( V_511 ) ;
V_620 |= F_467 ( F_463 ( V_510 ) ) ;
}
if ( V_60 -> V_205 )
V_620 |= F_467 ( V_622 ) ;
return V_620 ;
}
static unsigned long
F_471 ( struct V_144 * V_65 ,
struct V_37 * V_60 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
enum V_127 V_623 ;
unsigned long V_624 , V_625 , V_626 ;
V_626 = V_81 -> V_627 ;
V_81 -> V_627 = V_625 =
F_466 ( V_65 , V_60 ) ;
V_624 = V_625 & ~ V_626 ;
F_472 (domain, domains)
F_473 ( V_6 , V_623 ) ;
return V_626 & ~ V_625 ;
}
static void F_474 ( struct V_5 * V_6 ,
unsigned long V_624 )
{
enum V_127 V_623 ;
F_472 (domain, domains)
F_86 ( V_6 , V_623 ) ;
}
static int F_475 ( struct V_5 * V_6 )
{
int V_628 = V_6 -> V_628 ;
if ( F_184 ( V_6 ) -> V_250 >= 9 ||
F_265 ( V_6 ) || F_266 ( V_6 ) )
return V_628 ;
else if ( F_17 ( V_6 ) )
return V_628 * 95 / 100 ;
else if ( F_184 ( V_6 ) -> V_250 < 4 )
return 2 * V_628 * 90 / 100 ;
else
return V_628 * 90 / 100 ;
}
static void F_476 ( struct V_5 * V_6 )
{
if ( F_477 ( V_6 ) || F_478 ( V_6 ) ) {
T_1 V_57 = F_11 ( V_629 ) & V_630 ;
int V_631 , V_52 ;
V_52 = V_6 -> V_632 ;
F_28 ( V_52 != 8100000 && V_52 != 8640000 ) ;
if ( V_57 == V_633 )
V_631 = 617143 ;
else if ( V_57 == V_634 )
V_631 = 540000 ;
else if ( V_57 == V_635 )
V_631 = 432000 ;
else
V_631 = 308571 ;
V_6 -> V_628 = F_479 ( V_631 , V_52 ) ;
} else if ( F_36 ( V_6 ) ) {
V_6 -> V_628 = 624000 ;
} else if ( F_266 ( V_6 ) ) {
if ( F_11 ( V_636 ) & V_637 )
V_6 -> V_628 = 450000 ;
else if ( F_480 ( V_6 ) )
V_6 -> V_628 = 450000 ;
else if ( F_481 ( V_6 ) )
V_6 -> V_628 = 540000 ;
else
V_6 -> V_628 = 675000 ;
} else if ( F_17 ( V_6 ) ) {
V_6 -> V_628 = 320000 ;
} else if ( F_16 ( V_6 ) ) {
V_6 -> V_628 = 400000 ;
} else {
V_6 -> V_628 = V_6 -> V_638 ;
}
V_6 -> V_639 = F_475 ( V_6 ) ;
F_20 ( L_90 ,
V_6 -> V_628 ) ;
F_20 ( L_91 ,
V_6 -> V_639 ) ;
}
static void F_482 ( struct V_5 * V_6 )
{
V_6 -> V_638 = V_6 -> V_433 . V_640 ( V_6 ) ;
if ( F_59 ( V_6 ) >= 9 )
F_20 ( L_92 ,
V_6 -> V_638 , V_6 -> V_641 . V_52 ,
V_6 -> V_641 . V_642 ) ;
else
F_20 ( L_93 ,
V_6 -> V_638 ) ;
if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
F_124 ( V_643 , F_221 ( V_6 -> V_638 , 1000 ) ) ;
}
static int F_483 ( int V_644 )
{
return F_8 ( V_644 - 1000 , 500 ) ;
}
static int F_484 ( struct V_5 * V_6 , int V_644 )
{
int V_645 ;
if ( V_644 == V_6 -> V_641 . V_642 )
return 0 ;
switch ( V_644 ) {
default:
F_172 ( V_644 ) ;
case 144000 :
case 288000 :
case 384000 :
case 576000 :
V_645 = 60 ;
break;
case 624000 :
V_645 = 65 ;
break;
}
return V_6 -> V_641 . V_642 * V_645 ;
}
static void F_485 ( struct V_5 * V_6 )
{
F_124 ( V_646 , 0 ) ;
if ( F_61 ( V_6 ,
V_646 , V_647 , 0 ,
1 ) )
F_127 ( L_94 ) ;
V_6 -> V_641 . V_52 = 0 ;
}
static void F_486 ( struct V_5 * V_6 , int V_52 )
{
int V_645 = F_8 ( V_52 , V_6 -> V_641 . V_642 ) ;
T_1 V_15 ;
V_15 = F_11 ( V_648 ) ;
V_15 &= ~ V_649 ;
V_15 |= F_487 ( V_645 ) ;
F_124 ( V_648 , V_15 ) ;
F_124 ( V_646 , V_650 ) ;
if ( F_61 ( V_6 ,
V_646 ,
V_647 ,
V_647 ,
1 ) )
F_127 ( L_95 ) ;
V_6 -> V_641 . V_52 = V_52 ;
}
static void F_488 ( struct V_5 * V_6 , int V_644 )
{
T_1 V_15 , V_16 ;
int V_52 , V_360 ;
V_52 = F_484 ( V_6 , V_644 ) ;
F_20 ( L_96 , V_644 , V_52 ) ;
switch ( F_8 ( V_52 , V_644 ) ) {
case 8 :
V_16 = V_651 ;
break;
case 4 :
V_16 = V_652 ;
break;
case 3 :
V_16 = V_653 ;
break;
case 2 :
V_16 = V_654 ;
break;
default:
F_28 ( V_644 != V_6 -> V_641 . V_642 ) ;
F_28 ( V_52 != 0 ) ;
V_16 = V_654 ;
break;
}
F_3 ( & V_6 -> V_551 . V_552 ) ;
V_360 = F_402 ( V_6 , V_655 ,
0x80000000 ) ;
F_5 ( & V_6 -> V_551 . V_552 ) ;
if ( V_360 ) {
F_127 ( L_97 ,
V_360 , V_644 ) ;
return;
}
if ( V_6 -> V_641 . V_52 != 0 &&
V_6 -> V_641 . V_52 != V_52 )
F_485 ( V_6 ) ;
if ( V_6 -> V_641 . V_52 != V_52 )
F_486 ( V_6 , V_52 ) ;
V_15 = V_16 | F_483 ( V_644 ) ;
V_15 |= V_656 ;
if ( V_644 >= 500000 )
V_15 |= V_657 ;
F_124 ( V_658 , V_15 ) ;
F_3 ( & V_6 -> V_551 . V_552 ) ;
V_360 = F_402 ( V_6 , V_655 ,
F_221 ( V_644 , 25000 ) ) ;
F_5 ( & V_6 -> V_551 . V_552 ) ;
if ( V_360 ) {
F_127 ( L_98 ,
V_360 , V_644 ) ;
return;
}
F_482 ( V_6 ) ;
}
static void F_489 ( struct V_5 * V_6 )
{
T_1 V_659 , V_660 ;
F_482 ( V_6 ) ;
if ( V_6 -> V_641 . V_52 == 0 ||
V_6 -> V_638 == V_6 -> V_641 . V_642 )
goto V_661;
V_659 = F_11 ( V_658 ) ;
V_659 &= ~ V_656 ;
V_660 = ( V_659 & V_662 ) |
F_483 ( V_6 -> V_638 ) ;
if ( V_6 -> V_638 >= 500000 )
V_660 |= V_657 ;
if ( V_659 == V_660 )
return;
V_661:
F_161 ( L_99 ) ;
V_6 -> V_638 = 0 ;
V_6 -> V_641 . V_52 = - 1 ;
}
void F_490 ( struct V_5 * V_6 )
{
F_489 ( V_6 ) ;
if ( V_6 -> V_638 != 0 && V_6 -> V_641 . V_52 != 0 )
return;
F_488 ( V_6 , F_491 ( 0 ) ) ;
}
void F_492 ( struct V_5 * V_6 )
{
F_488 ( V_6 , V_6 -> V_641 . V_642 ) ;
}
static int F_479 ( int V_663 , int V_52 )
{
if ( V_52 == 8640000 ) {
if ( V_663 > 540000 )
return 617143 ;
else if ( V_663 > 432000 )
return 540000 ;
else if ( V_663 > 308571 )
return 432000 ;
else
return 308571 ;
} else {
if ( V_663 > 540000 )
return 675000 ;
else if ( V_663 > 450000 )
return 540000 ;
else if ( V_663 > 337500 )
return 450000 ;
else
return 337500 ;
}
}
static void
F_493 ( struct V_5 * V_6 )
{
T_1 V_15 ;
V_6 -> V_641 . V_642 = 24000 ;
V_6 -> V_641 . V_52 = 0 ;
V_15 = F_11 ( V_664 ) ;
if ( ( V_15 & V_665 ) == 0 )
return;
if ( F_28 ( ( V_15 & V_666 ) == 0 ) )
return;
V_15 = F_11 ( V_667 ) ;
if ( F_28 ( ( V_15 & ( F_494 ( V_668 ) |
F_495 ( V_668 ) |
F_496 ( V_668 ) ) ) !=
F_496 ( V_668 ) ) )
return;
switch ( V_15 & F_497 ( V_668 ) ) {
case F_498 ( V_669 , V_668 ) :
case F_498 ( V_670 , V_668 ) :
case F_498 ( V_671 , V_668 ) :
case F_498 ( V_672 , V_668 ) :
V_6 -> V_641 . V_52 = 8100000 ;
break;
case F_498 ( V_673 , V_668 ) :
case F_498 ( V_674 , V_668 ) :
V_6 -> V_641 . V_52 = 8640000 ;
break;
default:
F_172 ( V_15 & F_497 ( V_668 ) ) ;
break;
}
}
void F_499 ( struct V_5 * V_6 , int V_52 )
{
bool V_675 = V_6 -> V_632 != V_52 ;
V_6 -> V_632 = V_52 ;
if ( V_675 )
F_476 ( V_6 ) ;
}
static void
F_500 ( struct V_5 * V_6 , int V_52 )
{
int V_676 = F_479 ( 0 , V_52 ) ;
T_1 V_15 ;
F_28 ( V_52 != 8100000 && V_52 != 8640000 ) ;
V_15 = V_677 | F_483 ( V_676 ) ;
F_124 ( V_658 , V_15 ) ;
F_125 ( V_658 ) ;
V_15 = F_11 ( V_667 ) ;
V_15 &= ~ ( F_494 ( V_668 ) | F_495 ( V_668 ) |
F_497 ( V_668 ) ) ;
V_15 |= F_496 ( V_668 ) ;
if ( V_52 == 8640000 )
V_15 |= F_498 ( V_673 ,
V_668 ) ;
else
V_15 |= F_498 ( V_669 ,
V_668 ) ;
F_124 ( V_667 , V_15 ) ;
F_125 ( V_667 ) ;
F_124 ( V_664 , F_11 ( V_664 ) | V_665 ) ;
if ( F_61 ( V_6 ,
V_664 , V_666 , V_666 ,
5 ) )
F_127 ( L_100 ) ;
V_6 -> V_641 . V_52 = V_52 ;
F_499 ( V_6 , V_52 ) ;
}
static void
F_501 ( struct V_5 * V_6 )
{
F_124 ( V_664 , F_11 ( V_664 ) & ~ V_665 ) ;
if ( F_61 ( V_6 ,
V_664 , V_666 , 0 ,
1 ) )
F_127 ( L_101 ) ;
V_6 -> V_641 . V_52 = 0 ;
}
static void F_502 ( struct V_5 * V_6 , int V_644 , int V_52 )
{
T_1 V_678 , V_679 ;
int V_360 ;
F_28 ( ( V_644 == 24000 ) != ( V_52 == 0 ) ) ;
F_20 ( L_96 , V_644 , V_52 ) ;
F_3 ( & V_6 -> V_551 . V_552 ) ;
V_360 = F_503 ( V_6 , V_680 ,
V_681 ,
V_682 ,
V_682 , 3 ) ;
F_5 ( & V_6 -> V_551 . V_552 ) ;
if ( V_360 ) {
F_127 ( L_102 ,
V_360 ) ;
return;
}
switch ( V_644 ) {
case 450000 :
case 432000 :
V_678 = V_683 ;
V_679 = 1 ;
break;
case 540000 :
V_678 = V_684 ;
V_679 = 2 ;
break;
case 308571 :
case 337500 :
default:
V_678 = V_677 ;
V_679 = 0 ;
break;
case 617143 :
case 675000 :
V_678 = V_685 ;
V_679 = 3 ;
break;
}
if ( V_6 -> V_641 . V_52 != 0 &&
V_6 -> V_641 . V_52 != V_52 )
F_501 ( V_6 ) ;
if ( V_6 -> V_641 . V_52 != V_52 )
F_500 ( V_6 , V_52 ) ;
F_124 ( V_658 , V_678 | F_483 ( V_644 ) ) ;
F_125 ( V_658 ) ;
F_3 ( & V_6 -> V_551 . V_552 ) ;
F_402 ( V_6 , V_680 , V_679 ) ;
F_5 ( & V_6 -> V_551 . V_552 ) ;
F_482 ( V_6 ) ;
}
void F_504 ( struct V_5 * V_6 )
{
F_502 ( V_6 , V_6 -> V_641 . V_642 , 0 ) ;
}
void F_505 ( struct V_5 * V_6 )
{
int V_644 , V_52 ;
F_506 ( V_6 ) ;
if ( V_6 -> V_638 != 0 && V_6 -> V_641 . V_52 != 0 ) {
if ( V_6 -> V_632 == 0 )
F_499 ( V_6 ,
V_6 -> V_641 . V_52 ) ;
return;
}
V_52 = V_6 -> V_632 ;
if ( V_52 == 0 )
V_52 = 8100000 ;
V_644 = F_479 ( 0 , V_52 ) ;
F_502 ( V_6 , V_644 , V_52 ) ;
}
static void F_506 ( struct V_5 * V_6 )
{
T_2 V_659 , V_660 ;
if ( ( F_11 ( F_507 ( 0x18 ) ) & 0x00FFFFFF ) == 0 )
goto V_661;
F_482 ( V_6 ) ;
if ( V_6 -> V_641 . V_52 == 0 ||
V_6 -> V_638 == V_6 -> V_641 . V_642 )
goto V_661;
V_659 = F_11 ( V_658 ) ;
V_660 = ( V_659 & V_686 ) |
F_483 ( V_6 -> V_638 ) ;
if ( V_659 == V_660 )
return;
V_661:
F_161 ( L_99 ) ;
V_6 -> V_638 = 0 ;
V_6 -> V_641 . V_52 = - 1 ;
}
static void F_508 ( struct V_62 * V_63 , int V_644 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_15 , V_687 ;
F_28 ( V_6 -> V_433 . V_640 ( V_6 )
!= V_6 -> V_638 ) ;
if ( V_644 >= 320000 )
V_687 = 2 ;
else if ( V_644 == 266667 )
V_687 = 1 ;
else
V_687 = 0 ;
F_3 ( & V_6 -> V_551 . V_552 ) ;
V_15 = F_509 ( V_6 , V_688 ) ;
V_15 &= ~ V_689 ;
V_15 |= ( V_687 << V_690 ) ;
F_510 ( V_6 , V_688 , V_15 ) ;
if ( F_62 ( ( F_509 ( V_6 , V_688 ) &
V_691 ) == ( V_687 << V_692 ) ,
50 ) ) {
F_127 ( L_103 ) ;
}
F_5 ( & V_6 -> V_551 . V_552 ) ;
F_3 ( & V_6 -> V_9 ) ;
if ( V_644 == 400000 ) {
T_1 V_16 ;
V_16 = F_8 ( V_6 -> V_7 << 1 , V_644 ) - 1 ;
V_15 = F_4 ( V_6 , V_693 ) ;
V_15 &= ~ V_17 ;
V_15 |= V_16 ;
F_511 ( V_6 , V_693 , V_15 ) ;
if ( F_62 ( ( F_4 ( V_6 , V_693 ) &
V_18 ) == ( V_16 << V_19 ) ,
50 ) )
F_127 ( L_103 ) ;
}
V_15 = F_512 ( V_6 , V_694 ) ;
V_15 &= ~ 0x7f ;
if ( V_644 == 400000 )
V_15 |= 4500 / 250 ;
else
V_15 |= 3000 / 250 ;
F_513 ( V_6 , V_694 , V_15 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_482 ( V_6 ) ;
}
static void F_514 ( struct V_62 * V_63 , int V_644 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_15 , V_687 ;
F_28 ( V_6 -> V_433 . V_640 ( V_6 )
!= V_6 -> V_638 ) ;
switch ( V_644 ) {
case 333333 :
case 320000 :
case 266667 :
case 200000 :
break;
default:
F_172 ( V_644 ) ;
return;
}
V_687 = F_8 ( V_6 -> V_7 << 1 , V_644 ) - 1 ;
F_3 ( & V_6 -> V_551 . V_552 ) ;
V_15 = F_509 ( V_6 , V_688 ) ;
V_15 &= ~ V_695 ;
V_15 |= ( V_687 << V_696 ) ;
F_510 ( V_6 , V_688 , V_15 ) ;
if ( F_62 ( ( F_509 ( V_6 , V_688 ) &
V_697 ) == ( V_687 << V_698 ) ,
50 ) ) {
F_127 ( L_103 ) ;
}
F_5 ( & V_6 -> V_551 . V_552 ) ;
F_482 ( V_6 ) ;
}
static int F_515 ( struct V_5 * V_6 ,
int V_663 )
{
int V_699 = ( V_6 -> V_7 << 1 ) % 320000 != 0 ? 333333 : 320000 ;
int V_57 = F_17 ( V_6 ) ? 95 : 90 ;
if ( ! F_17 ( V_6 ) &&
V_663 > V_699 * V_57 / 100 )
return 400000 ;
else if ( V_663 > 266667 * V_57 / 100 )
return V_699 ;
else if ( V_663 > 0 )
return 266667 ;
else
return 200000 ;
}
static int F_491 ( int V_663 )
{
if ( V_663 > 576000 )
return 624000 ;
else if ( V_663 > 384000 )
return 576000 ;
else if ( V_663 > 288000 )
return 384000 ;
else if ( V_663 > 144000 )
return 288000 ;
else
return 144000 ;
}
static int F_516 ( struct V_62 * V_63 ,
struct V_418 * V_43 )
{
struct V_570 * V_336 = F_296 ( V_43 ) ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_144 * V_65 ;
struct V_42 * V_60 ;
unsigned V_663 = 0 , V_135 ;
enum V_94 V_94 ;
memcpy ( V_336 -> V_700 , V_6 -> V_700 ,
sizeof( V_336 -> V_700 ) ) ;
F_295 (state, crtc, crtc_state, i) {
int V_701 = 0 ;
if ( V_60 -> V_506 )
V_701 = V_60 -> V_91 . V_92 ;
V_336 -> V_700 [ V_135 ] = V_701 ;
}
F_91 (dev_priv, pipe)
V_663 = V_59 ( V_336 -> V_700 [ V_94 ] , V_663 ) ;
return V_663 ;
}
static int F_517 ( struct V_418 * V_43 )
{
struct V_62 * V_63 = V_43 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_663 = F_516 ( V_63 , V_43 ) ;
struct V_570 * V_336 =
F_296 ( V_43 ) ;
V_336 -> V_644 = V_336 -> V_702 =
F_515 ( V_6 , V_663 ) ;
if ( ! V_336 -> V_703 )
V_336 -> V_702 = F_515 ( V_6 , 0 ) ;
return 0 ;
}
static int F_518 ( struct V_418 * V_43 )
{
int V_663 = F_519 ( V_43 ) ;
struct V_570 * V_336 =
F_296 ( V_43 ) ;
V_336 -> V_644 = V_336 -> V_702 =
F_491 ( V_663 ) ;
if ( ! V_336 -> V_703 )
V_336 -> V_702 = F_491 ( 0 ) ;
return 0 ;
}
static void F_520 ( struct V_5 * V_6 )
{
unsigned int V_704 , V_705 ;
if ( F_17 ( V_6 ) )
V_705 = F_521 ( 12 ) ;
else
V_705 = F_521 ( 8 ) ;
if ( V_6 -> V_638 >= V_6 -> V_35 ) {
if ( F_17 ( V_6 ) )
V_704 = V_706 ;
else
V_704 = F_521 ( 15 ) ;
} else {
V_704 = V_705 ;
}
F_124 ( V_707 , V_708 |
V_705 ) ;
F_124 ( V_707 , V_708 |
V_704 | V_709 ) ;
F_28 ( F_11 ( V_707 ) & V_709 ) ;
}
static void F_522 ( struct V_418 * V_562 )
{
struct V_62 * V_63 = V_562 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_570 * V_571 =
F_296 ( V_562 ) ;
unsigned V_710 = V_571 -> V_702 ;
F_473 ( V_6 , V_711 ) ;
if ( F_17 ( V_6 ) )
F_514 ( V_63 , V_710 ) ;
else
F_508 ( V_63 , V_710 ) ;
F_520 ( V_6 ) ;
F_86 ( V_6 , V_711 ) ;
}
static void F_523 ( struct V_37 * V_38 ,
struct V_418 * V_562 )
{
struct V_144 * V_65 = V_38 -> V_64 . V_65 ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
if ( F_28 ( V_81 -> V_87 ) )
return;
if ( F_389 ( V_81 -> V_90 ) )
F_435 ( V_81 , V_587 ) ;
F_436 ( V_81 ) ;
F_437 ( V_81 ) ;
if ( F_17 ( V_6 ) && V_94 == V_120 ) {
struct V_5 * V_6 = F_41 ( V_63 ) ;
F_124 ( F_524 ( V_94 ) , V_712 ) ;
F_124 ( F_525 ( V_94 ) , 0 ) ;
}
F_526 ( V_81 ) ;
V_81 -> V_87 = true ;
F_407 ( V_6 , V_94 , true ) ;
F_423 ( V_65 , V_38 , V_562 ) ;
if ( F_17 ( V_6 ) ) {
F_527 ( V_81 , V_81 -> V_90 ) ;
F_136 ( V_81 , V_81 -> V_90 ) ;
} else {
F_528 ( V_81 , V_81 -> V_90 ) ;
F_128 ( V_81 , V_81 -> V_90 ) ;
}
F_426 ( V_65 , V_38 , V_562 ) ;
F_459 ( V_81 ) ;
F_440 ( & V_38 -> V_64 ) ;
F_415 ( V_81 ) ;
F_160 ( V_81 ) ;
F_99 ( V_65 ) ;
F_441 ( V_65 ) ;
F_427 ( V_65 , V_38 , V_562 ) ;
}
static void F_529 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
F_124 ( F_530 ( V_65 -> V_94 ) , V_65 -> V_90 -> V_173 . V_713 ) ;
F_124 ( F_531 ( V_65 -> V_94 ) , V_65 -> V_90 -> V_173 . V_714 ) ;
}
static void F_532 ( struct V_37 * V_38 ,
struct V_418 * V_562 )
{
struct V_144 * V_65 = V_38 -> V_64 . V_65 ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
enum V_94 V_94 = V_81 -> V_94 ;
if ( F_28 ( V_81 -> V_87 ) )
return;
F_529 ( V_81 ) ;
if ( F_389 ( V_81 -> V_90 ) )
F_435 ( V_81 , V_587 ) ;
F_436 ( V_81 ) ;
F_437 ( V_81 ) ;
F_526 ( V_81 ) ;
V_81 -> V_87 = true ;
if ( ! F_56 ( V_6 ) )
F_407 ( V_6 , V_94 , true ) ;
F_426 ( V_65 , V_38 , V_562 ) ;
F_139 ( V_81 ) ;
F_459 ( V_81 ) ;
F_440 ( & V_38 -> V_64 ) ;
F_415 ( V_81 ) ;
F_160 ( V_81 ) ;
F_99 ( V_65 ) ;
F_441 ( V_65 ) ;
F_427 ( V_65 , V_38 , V_562 ) ;
}
static void F_533 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
if ( ! V_65 -> V_90 -> V_596 . V_597 )
return;
F_129 ( V_6 , V_65 -> V_94 ) ;
F_20 ( L_104 ,
F_11 ( V_598 ) ) ;
F_124 ( V_598 , 0 ) ;
}
static void F_534 ( struct V_37 * V_441 ,
struct V_418 * V_562 )
{
struct V_144 * V_65 = V_441 -> V_64 . V_65 ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
if ( F_56 ( V_6 ) )
F_343 ( V_6 , V_94 ) ;
F_429 ( V_65 , V_441 , V_562 ) ;
F_455 ( V_65 ) ;
F_99 ( V_65 ) ;
F_168 ( V_81 ) ;
F_533 ( V_81 ) ;
F_430 ( V_65 , V_441 , V_562 ) ;
if ( ! F_38 ( V_81 -> V_90 , V_222 ) ) {
if ( F_17 ( V_6 ) )
F_144 ( V_6 , V_94 ) ;
else if ( F_16 ( V_6 ) )
F_143 ( V_6 , V_94 ) ;
else
F_142 ( V_81 ) ;
}
F_431 ( V_65 , V_441 , V_562 ) ;
if ( ! F_56 ( V_6 ) )
F_407 ( V_6 , V_94 , false ) ;
}
static void F_535 ( struct V_144 * V_65 )
{
struct V_510 * V_511 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
enum V_127 V_623 ;
unsigned long V_624 ;
struct V_418 * V_43 ;
struct V_37 * V_60 ;
int V_360 ;
if ( ! V_81 -> V_87 )
return;
if ( F_236 ( V_65 -> V_88 -> V_43 ) -> V_64 . V_338 ) {
F_28 ( V_81 -> V_440 ) ;
F_241 ( V_65 ) ;
F_420 ( V_65 , 1 << F_240 ( V_65 -> V_88 ) ) ;
F_236 ( V_65 -> V_88 -> V_43 ) -> V_64 . V_338 = false ;
}
V_43 = F_536 ( V_65 -> V_63 ) ;
if ( ! V_43 ) {
F_161 ( L_105 ,
V_65 -> V_64 . V_377 , V_65 -> V_12 ) ;
return;
}
V_43 -> V_431 = V_65 -> V_63 -> V_426 . V_431 ;
V_60 = F_537 ( V_43 , V_81 ) ;
V_360 = F_538 ( V_43 , V_65 ) ;
F_28 ( F_194 ( V_60 ) || V_360 ) ;
V_6 -> V_433 . V_715 ( V_60 , V_43 ) ;
F_306 ( V_43 ) ;
F_161 ( L_106 ,
V_65 -> V_64 . V_377 , V_65 -> V_12 ) ;
F_28 ( F_539 ( V_65 -> V_43 , NULL ) < 0 ) ;
V_65 -> V_43 -> V_87 = false ;
V_81 -> V_87 = false ;
V_65 -> V_145 = false ;
V_65 -> V_43 -> V_716 = 0 ;
V_65 -> V_43 -> V_717 = 0 ;
F_380 (crtc->dev, crtc, encoder)
V_511 -> V_64 . V_65 = NULL ;
F_540 ( V_81 ) ;
F_415 ( V_81 ) ;
F_541 ( V_81 ) ;
V_624 = V_81 -> V_627 ;
F_472 (domain, domains)
F_86 ( V_6 , V_623 ) ;
V_81 -> V_627 = 0 ;
V_6 -> V_703 &= ~ ( 1 << V_81 -> V_94 ) ;
V_6 -> V_700 [ V_81 -> V_94 ] = 0 ;
}
int F_542 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_418 * V_43 ;
int V_360 ;
V_43 = F_543 ( V_63 ) ;
V_360 = F_544 ( V_43 ) ;
if ( V_360 )
F_127 ( L_57 , V_360 ) ;
else
V_6 -> V_430 = V_43 ;
return V_360 ;
}
void F_545 ( struct V_619 * V_511 )
{
struct V_510 * V_510 = F_425 ( V_511 ) ;
F_546 ( V_511 ) ;
F_237 ( V_510 ) ;
}
static void F_547 ( struct V_718 * V_719 )
{
struct V_144 * V_65 = V_719 -> V_64 . V_43 -> V_65 ;
F_161 ( L_107 ,
V_719 -> V_64 . V_64 . V_377 ,
V_719 -> V_64 . V_12 ) ;
if ( V_719 -> V_720 ( V_719 ) ) {
struct V_510 * V_511 = V_719 -> V_511 ;
struct V_576 * V_580 = V_719 -> V_64 . V_43 ;
F_65 ( ! V_65 ,
L_108 ) ;
if ( ! V_65 )
return;
F_65 ( ! V_65 -> V_43 -> V_87 ,
L_109 ) ;
if ( ! V_511 || V_511 -> type == V_592 )
return;
F_65 ( V_580 -> V_581 != & V_511 -> V_64 ,
L_110 ) ;
F_65 ( V_580 -> V_65 != V_511 -> V_64 . V_65 ,
L_111 ) ;
} else {
F_65 ( V_65 && V_65 -> V_43 -> V_87 ,
L_112 ) ;
F_65 ( ! V_65 && V_719 -> V_64 . V_43 -> V_581 ,
L_113 ) ;
}
}
int F_548 ( struct V_718 * V_719 )
{
F_549 ( & V_719 -> V_64 ) ;
if ( ! V_719 -> V_64 . V_43 )
return - V_721 ;
return 0 ;
}
struct V_718 * F_550 ( void )
{
struct V_718 * V_719 ;
V_719 = F_551 ( sizeof *V_719 , V_722 ) ;
if ( ! V_719 )
return NULL ;
if ( F_548 ( V_719 ) < 0 ) {
F_237 ( V_719 ) ;
return NULL ;
}
return V_719 ;
}
bool F_552 ( struct V_718 * V_719 )
{
enum V_94 V_94 = 0 ;
struct V_510 * V_511 = V_719 -> V_511 ;
return V_511 -> V_720 ( V_511 , & V_94 ) ;
}
static int F_553 ( struct V_37 * V_60 )
{
if ( V_60 -> V_64 . V_506 && V_60 -> V_221 )
return V_60 -> V_456 ;
return 0 ;
}
static int F_554 ( struct V_62 * V_63 , enum V_94 V_94 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_418 * V_43 = V_38 -> V_64 . V_43 ;
struct V_81 * V_723 ;
struct V_37 * V_724 ;
F_161 ( L_114 ,
F_78 ( V_94 ) , V_38 -> V_456 ) ;
if ( V_38 -> V_456 > 4 ) {
F_161 ( L_115 ,
F_78 ( V_94 ) , V_38 -> V_456 ) ;
return - V_286 ;
}
if ( F_265 ( V_6 ) || F_266 ( V_6 ) ) {
if ( V_38 -> V_456 > 2 ) {
F_161 ( L_116 ,
V_38 -> V_456 ) ;
return - V_286 ;
} else {
return 0 ;
}
}
if ( F_184 ( V_6 ) -> V_725 == 2 )
return 0 ;
switch ( V_94 ) {
case V_113 :
return 0 ;
case V_120 :
if ( V_38 -> V_456 <= 2 )
return 0 ;
V_723 = F_53 ( V_6 , V_509 ) ;
V_724 =
F_537 ( V_43 , V_723 ) ;
if ( F_194 ( V_724 ) )
return F_242 ( V_724 ) ;
if ( F_553 ( V_724 ) > 0 ) {
F_161 ( L_117 ,
F_78 ( V_94 ) , V_38 -> V_456 ) ;
return - V_286 ;
}
return 0 ;
case V_509 :
if ( V_38 -> V_456 > 2 ) {
F_161 ( L_118 ,
F_78 ( V_94 ) , V_38 -> V_456 ) ;
return - V_286 ;
}
V_723 = F_53 ( V_6 , V_120 ) ;
V_724 =
F_537 ( V_43 , V_723 ) ;
if ( F_194 ( V_724 ) )
return F_242 ( V_724 ) ;
if ( F_553 ( V_724 ) > 2 ) {
F_161 ( L_119 ) ;
return - V_286 ;
}
return 0 ;
default:
F_146 () ;
}
}
static int F_555 ( struct V_81 * V_81 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
const struct V_519 * V_91 = & V_38 -> V_64 . V_91 ;
int V_726 , V_727 , V_728 , V_360 ;
bool V_729 = false ;
V_461:
V_727 = F_22 ( F_41 ( V_63 ) , V_38 ) ;
V_728 = V_91 -> V_92 ;
V_726 = F_556 ( V_728 , V_727 ,
V_38 -> V_730 ) ;
V_38 -> V_456 = V_726 ;
F_557 ( V_38 -> V_730 , V_726 , V_728 ,
V_727 , & V_38 -> V_588 ) ;
V_360 = F_554 ( V_63 , V_81 -> V_94 , V_38 ) ;
if ( V_360 == - V_286 && V_38 -> V_730 > 6 * 3 ) {
V_38 -> V_730 -= 2 * 3 ;
F_161 ( L_120 ,
V_38 -> V_730 ) ;
V_729 = true ;
V_38 -> V_731 = true ;
goto V_461;
}
if ( V_729 )
return V_732 ;
return V_360 ;
}
static bool F_558 ( struct V_5 * V_6 ,
struct V_37 * V_38 )
{
if ( V_38 -> V_730 > 24 )
return false ;
if ( F_265 ( V_6 ) )
return true ;
return F_559 ( V_38 ) <=
V_6 -> V_628 * 95 / 100 ;
}
static void F_560 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
V_38 -> V_550 = V_428 . V_733 &&
F_442 ( V_65 ) &&
F_558 ( V_6 , V_38 ) ;
}
static bool F_561 ( const struct V_81 * V_65 )
{
const struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
return F_184 ( V_6 ) -> V_250 < 4 &&
( V_65 -> V_94 == V_113 || F_562 ( V_6 ) ) ;
}
static int F_563 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
const struct V_519 * V_91 = & V_38 -> V_64 . V_91 ;
int V_734 = V_6 -> V_639 ;
if ( F_59 ( V_6 ) < 4 ) {
V_734 = V_6 -> V_628 * 9 / 10 ;
if ( F_561 ( V_65 ) &&
V_91 -> V_92 > V_734 ) {
V_734 = V_6 -> V_639 ;
V_38 -> V_225 = true ;
}
}
if ( V_91 -> V_92 > V_734 ) {
F_161 ( L_121 ,
V_91 -> V_92 , V_734 ,
F_564 ( V_38 -> V_225 ) ) ;
return - V_286 ;
}
if ( ( F_38 ( V_38 , V_66 ) &&
F_39 ( V_63 ) ) || V_38 -> V_225 )
V_38 -> V_365 &= ~ 1 ;
if ( ( F_59 ( V_6 ) > 4 || F_18 ( V_6 ) ) &&
V_91 -> V_735 == V_91 -> V_542 )
return - V_286 ;
if ( F_443 ( V_6 ) )
F_560 ( V_65 , V_38 ) ;
if ( V_38 -> V_221 )
return F_555 ( V_65 , V_38 ) ;
return 0 ;
}
static int F_565 ( struct V_5 * V_6 )
{
T_1 V_659 ;
F_493 ( V_6 ) ;
if ( V_6 -> V_641 . V_52 == 0 )
return V_6 -> V_641 . V_642 ;
V_659 = F_11 ( V_658 ) ;
if ( V_6 -> V_641 . V_52 == 8640000 ) {
switch ( V_659 & V_686 ) {
case V_683 :
return 432000 ;
case V_677 :
return 308571 ;
case V_684 :
return 540000 ;
case V_685 :
return 617143 ;
default:
F_172 ( V_659 & V_686 ) ;
}
} else {
switch ( V_659 & V_686 ) {
case V_683 :
return 450000 ;
case V_677 :
return 337500 ;
case V_684 :
return 540000 ;
case V_685 :
return 675000 ;
default:
F_172 ( V_659 & V_686 ) ;
}
}
return V_6 -> V_641 . V_642 ;
}
static void F_566 ( struct V_5 * V_6 )
{
T_1 V_15 ;
V_6 -> V_641 . V_642 = 19200 ;
V_6 -> V_641 . V_52 = 0 ;
V_15 = F_11 ( V_646 ) ;
if ( ( V_15 & V_650 ) == 0 )
return;
if ( F_28 ( ( V_15 & V_647 ) == 0 ) )
return;
V_15 = F_11 ( V_648 ) ;
V_6 -> V_641 . V_52 = ( V_15 & V_649 ) *
V_6 -> V_641 . V_642 ;
}
static int F_567 ( struct V_5 * V_6 )
{
T_1 V_16 ;
int div , V_52 ;
F_566 ( V_6 ) ;
V_52 = V_6 -> V_641 . V_52 ;
if ( V_52 == 0 )
return V_6 -> V_641 . V_642 ;
V_16 = F_11 ( V_658 ) & V_662 ;
switch ( V_16 ) {
case V_654 :
div = 2 ;
break;
case V_653 :
div = 3 ;
break;
case V_652 :
div = 4 ;
break;
case V_651 :
div = 8 ;
break;
default:
F_172 ( V_16 ) ;
return V_6 -> V_641 . V_642 ;
}
return F_8 ( V_52 , div ) ;
}
static int F_568 ( struct V_5 * V_6 )
{
T_2 V_736 = F_11 ( V_737 ) ;
T_2 V_738 = V_736 & V_739 ;
if ( V_736 & V_740 )
return 800000 ;
else if ( F_11 ( V_636 ) & V_637 )
return 450000 ;
else if ( V_738 == V_741 )
return 450000 ;
else if ( V_738 == V_742 )
return 540000 ;
else if ( V_738 == V_743 )
return 337500 ;
else
return 675000 ;
}
static int F_569 ( struct V_5 * V_6 )
{
T_2 V_736 = F_11 ( V_737 ) ;
T_2 V_738 = V_736 & V_739 ;
if ( V_736 & V_740 )
return 800000 ;
else if ( F_11 ( V_636 ) & V_637 )
return 450000 ;
else if ( V_738 == V_741 )
return 450000 ;
else if ( F_570 ( V_6 ) )
return 337500 ;
else
return 540000 ;
}
static int F_571 ( struct V_5 * V_6 )
{
return F_9 ( V_6 , L_122 ,
V_693 ) ;
}
static int F_572 ( struct V_5 * V_6 )
{
return 450000 ;
}
static int F_573 ( struct V_5 * V_6 )
{
return 400000 ;
}
static int F_574 ( struct V_5 * V_6 )
{
return 333333 ;
}
static int F_575 ( struct V_5 * V_6 )
{
return 200000 ;
}
static int F_576 ( struct V_5 * V_6 )
{
struct V_744 * V_745 = V_6 -> V_422 . V_745 ;
T_4 V_746 = 0 ;
F_577 ( V_745 , V_747 , & V_746 ) ;
switch ( V_746 & V_748 ) {
case V_749 :
return 266667 ;
case V_750 :
return 333333 ;
case V_751 :
return 444444 ;
case V_752 :
return 200000 ;
default:
F_127 ( L_123 , V_746 ) ;
case V_753 :
return 133333 ;
case V_754 :
return 166667 ;
}
}
static int F_578 ( struct V_5 * V_6 )
{
struct V_744 * V_745 = V_6 -> V_422 . V_745 ;
T_4 V_746 = 0 ;
F_577 ( V_745 , V_747 , & V_746 ) ;
if ( V_746 & V_755 )
return 133333 ;
else {
switch ( V_746 & V_748 ) {
case V_756 :
return 333333 ;
default:
case V_757 :
return 190000 ;
}
}
}
static int F_579 ( struct V_5 * V_6 )
{
return 266667 ;
}
static int F_580 ( struct V_5 * V_6 )
{
struct V_744 * V_745 = V_6 -> V_422 . V_745 ;
T_4 V_758 = 0 ;
if ( V_745 -> V_759 == 0x1 )
return 133333 ;
F_581 ( V_745 -> V_760 ,
F_582 ( 0 , 3 ) , V_761 , & V_758 ) ;
switch ( V_758 & V_762 ) {
case V_763 :
case V_764 :
case V_765 :
return 200000 ;
case V_766 :
return 250000 ;
case V_767 :
return 133333 ;
case V_768 :
case V_769 :
case V_770 :
return 266667 ;
}
return 0 ;
}
static int F_583 ( struct V_5 * V_6 )
{
return 133333 ;
}
static unsigned int F_584 ( struct V_5 * V_6 )
{
static const unsigned int V_771 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 6400000 ,
} ;
static const unsigned int V_772 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 2666667 ,
} ;
static const unsigned int V_773 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 3333333 ,
[ 5 ] = 3566667 ,
[ 6 ] = 4266667 ,
} ;
static const unsigned int V_774 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
} ;
static const unsigned int V_775 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 2666667 ,
[ 5 ] = 4266667 ,
} ;
const unsigned int * V_776 ;
unsigned int V_52 ;
T_5 V_178 = 0 ;
if ( F_585 ( V_6 ) )
V_776 = V_775 ;
else if ( F_18 ( V_6 ) )
V_776 = V_774 ;
else if ( F_186 ( V_6 ) )
V_776 = V_773 ;
else if ( F_19 ( V_6 ) )
V_776 = V_772 ;
else if ( F_586 ( V_6 ) )
V_776 = V_771 ;
else
return 0 ;
V_178 = F_11 ( F_140 ( V_6 ) ? V_777 : V_778 ) ;
V_52 = V_776 [ V_178 & 0x7 ] ;
if ( V_52 == 0 )
F_127 ( L_124 , V_178 ) ;
else
F_161 ( L_125 , V_52 ) ;
return V_52 ;
}
static int F_587 ( struct V_5 * V_6 )
{
struct V_744 * V_745 = V_6 -> V_422 . V_745 ;
unsigned int V_779 , V_52 = F_584 ( V_6 ) ;
T_6 V_178 = 0 ;
F_577 ( V_745 , V_747 , & V_178 ) ;
V_779 = ( V_178 >> 12 ) & 0x1 ;
switch ( V_52 ) {
case 2666667 :
case 4000000 :
case 5333333 :
return V_779 ? 333333 : 222222 ;
case 3200000 :
return V_779 ? 320000 : 228571 ;
default:
F_127 ( L_126 , V_52 , V_178 ) ;
return 222222 ;
}
}
static int F_588 ( struct V_5 * V_6 )
{
struct V_744 * V_745 = V_6 -> V_422 . V_745 ;
static const T_5 V_780 [] = { 16 , 10 , 8 } ;
static const T_5 V_781 [] = { 20 , 12 , 10 } ;
static const T_5 V_782 [] = { 24 , 16 , 14 } ;
const T_5 * V_783 ;
unsigned int V_779 , V_52 = F_584 ( V_6 ) ;
T_6 V_178 = 0 ;
F_577 ( V_745 , V_747 , & V_178 ) ;
V_779 = ( ( V_178 >> 8 ) & 0x1f ) - 1 ;
if ( V_779 >= F_179 ( V_780 ) )
goto V_784;
switch ( V_52 ) {
case 3200000 :
V_783 = V_780 ;
break;
case 4000000 :
V_783 = V_781 ;
break;
case 5333333 :
V_783 = V_782 ;
break;
default:
goto V_784;
}
return F_8 ( V_52 , V_783 [ V_779 ] ) ;
V_784:
F_127 ( L_127 , V_52 , V_178 ) ;
return 200000 ;
}
static int F_589 ( struct V_5 * V_6 )
{
struct V_744 * V_745 = V_6 -> V_422 . V_745 ;
static const T_5 V_780 [] = { 12 , 10 , 8 , 7 , 5 , 16 } ;
static const T_5 V_781 [] = { 14 , 12 , 10 , 8 , 6 , 20 } ;
static const T_5 V_785 [] = { 20 , 14 , 12 , 10 , 8 , 24 } ;
static const T_5 V_782 [] = { 20 , 16 , 12 , 12 , 8 , 28 } ;
const T_5 * V_783 ;
unsigned int V_779 , V_52 = F_584 ( V_6 ) ;
T_6 V_178 = 0 ;
F_577 ( V_745 , V_747 , & V_178 ) ;
V_779 = ( V_178 >> 4 ) & 0x7 ;
if ( V_779 >= F_179 ( V_780 ) )
goto V_784;
switch ( V_52 ) {
case 3200000 :
V_783 = V_780 ;
break;
case 4000000 :
V_783 = V_781 ;
break;
case 4800000 :
V_783 = V_785 ;
break;
case 5333333 :
V_783 = V_782 ;
break;
default:
goto V_784;
}
return F_8 ( V_52 , V_783 [ V_779 ] ) ;
V_784:
F_127 ( L_128 , V_52 , V_178 ) ;
return 190476 ;
}
static void
F_590 ( T_2 * V_786 , T_2 * V_787 )
{
while ( * V_786 > V_788 ||
* V_787 > V_788 ) {
* V_786 >>= 1 ;
* V_787 >>= 1 ;
}
}
static void F_591 ( unsigned int V_46 , unsigned int V_51 ,
T_2 * V_789 , T_2 * V_790 )
{
* V_790 = F_592 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_789 = F_46 ( ( V_55 ) V_46 * * V_790 , V_51 ) ;
F_590 ( V_789 , V_790 ) ;
}
void
F_557 ( int V_791 , int V_792 ,
int V_793 , int V_794 ,
struct V_795 * V_796 )
{
V_796 -> V_797 = 64 ;
F_591 ( V_791 * V_793 ,
V_794 * V_792 * 8 ,
& V_796 -> V_798 , & V_796 -> V_799 ) ;
F_591 ( V_793 , V_794 ,
& V_796 -> V_800 , & V_796 -> V_801 ) ;
}
static inline bool F_593 ( struct V_5 * V_6 )
{
if ( V_428 . V_802 >= 0 )
return V_428 . V_802 != 0 ;
return V_6 -> V_803 . V_804
&& ! ( V_6 -> V_129 & V_805 ) ;
}
static T_2 F_594 ( struct V_45 * V_45 )
{
return ( 1 << V_45 -> V_51 ) << 16 | V_45 -> V_47 ;
}
static T_2 F_595 ( struct V_45 * V_45 )
{
return V_45 -> V_51 << 16 | V_45 -> V_54 << 8 | V_45 -> V_47 ;
}
static void F_596 ( struct V_81 * V_65 ,
struct V_37 * V_60 ,
struct V_45 * V_806 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
T_1 V_807 , V_808 = 0 ;
if ( F_19 ( V_6 ) ) {
V_807 = F_594 ( & V_60 -> V_45 ) ;
if ( V_806 )
V_808 = F_594 ( V_806 ) ;
} else {
V_807 = F_595 ( & V_60 -> V_45 ) ;
if ( V_806 )
V_808 = F_595 ( V_806 ) ;
}
V_60 -> V_173 . V_713 = V_807 ;
V_65 -> V_809 = false ;
if ( F_38 ( V_60 , V_66 ) &&
V_806 ) {
V_60 -> V_173 . V_714 = V_808 ;
V_65 -> V_809 = true ;
} else {
V_60 -> V_173 . V_714 = V_807 ;
}
}
static void F_597 ( struct V_5 * V_6 , enum V_94
V_94 )
{
T_1 V_810 ;
V_810 = F_133 ( V_6 , V_94 , F_598 ( 1 ) ) ;
V_810 &= 0xffffff00 ;
V_810 |= 0x00000030 ;
F_135 ( V_6 , V_94 , F_598 ( 1 ) , V_810 ) ;
V_810 = F_133 ( V_6 , V_94 , V_811 ) ;
V_810 &= 0x8cffffff ;
V_810 = 0x8c000000 ;
F_135 ( V_6 , V_94 , V_811 , V_810 ) ;
V_810 = F_133 ( V_6 , V_94 , F_598 ( 1 ) ) ;
V_810 &= 0xffffff00 ;
F_135 ( V_6 , V_94 , F_598 ( 1 ) , V_810 ) ;
V_810 = F_133 ( V_6 , V_94 , V_811 ) ;
V_810 &= 0x00ffffff ;
V_810 |= 0xb0000000 ;
F_135 ( V_6 , V_94 , V_811 , V_810 ) ;
}
static void F_599 ( struct V_81 * V_65 ,
struct V_795 * V_796 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_65 -> V_94 ;
F_124 ( F_600 ( V_94 ) , F_601 ( V_796 -> V_797 ) | V_796 -> V_798 ) ;
F_124 ( F_602 ( V_94 ) , V_796 -> V_799 ) ;
F_124 ( F_603 ( V_94 ) , V_796 -> V_800 ) ;
F_124 ( F_604 ( V_94 ) , V_796 -> V_801 ) ;
}
static void F_438 ( struct V_81 * V_65 ,
struct V_795 * V_796 ,
struct V_795 * V_812 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
int V_94 = V_65 -> V_94 ;
enum V_93 V_93 = V_65 -> V_90 -> V_95 ;
if ( F_59 ( V_6 ) >= 5 ) {
F_124 ( F_384 ( V_93 ) , F_601 ( V_796 -> V_797 ) | V_796 -> V_798 ) ;
F_124 ( F_605 ( V_93 ) , V_796 -> V_799 ) ;
F_124 ( F_606 ( V_93 ) , V_796 -> V_800 ) ;
F_124 ( F_607 ( V_93 ) , V_796 -> V_801 ) ;
if ( V_812 && ( F_17 ( V_6 ) ||
F_59 ( V_6 ) < 8 ) && V_65 -> V_90 -> V_813 ) {
F_124 ( F_608 ( V_93 ) ,
F_601 ( V_812 -> V_797 ) | V_812 -> V_798 ) ;
F_124 ( F_609 ( V_93 ) , V_812 -> V_799 ) ;
F_124 ( F_610 ( V_93 ) , V_812 -> V_800 ) ;
F_124 ( F_611 ( V_93 ) , V_812 -> V_801 ) ;
}
} else {
F_124 ( F_612 ( V_94 ) , F_601 ( V_796 -> V_797 ) | V_796 -> V_798 ) ;
F_124 ( F_613 ( V_94 ) , V_796 -> V_799 ) ;
F_124 ( F_614 ( V_94 ) , V_796 -> V_800 ) ;
F_124 ( F_615 ( V_94 ) , V_796 -> V_801 ) ;
}
}
void F_435 ( struct V_81 * V_65 , enum V_814 V_796 )
{
struct V_795 * V_815 , * V_816 = NULL ;
if ( V_796 == V_587 ) {
V_815 = & V_65 -> V_90 -> V_815 ;
V_816 = & V_65 -> V_90 -> V_816 ;
} else if ( V_796 == V_817 ) {
V_815 = & V_65 -> V_90 -> V_816 ;
} else {
F_127 ( L_129 ) ;
return;
}
if ( V_65 -> V_90 -> V_221 )
F_599 ( V_65 , & V_65 -> V_90 -> V_815 ) ;
else
F_438 ( V_65 , V_815 , V_816 ) ;
}
static void F_616 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
V_38 -> V_173 . V_45 = V_188 |
V_189 | V_184 ;
if ( V_65 -> V_94 != V_113 )
V_38 -> V_173 . V_45 |= V_190 ;
if ( ! F_38 ( V_38 , V_222 ) )
V_38 -> V_173 . V_45 |= V_103 |
V_818 ;
V_38 -> V_173 . V_175 =
( V_38 -> V_591 - 1 ) << V_819 ;
}
static void F_617 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
V_38 -> V_173 . V_45 = V_191 |
V_189 | V_184 ;
if ( V_65 -> V_94 != V_113 )
V_38 -> V_173 . V_45 |= V_190 ;
if ( ! F_38 ( V_38 , V_222 ) )
V_38 -> V_173 . V_45 |= V_103 ;
V_38 -> V_173 . V_175 =
( V_38 -> V_591 - 1 ) << V_819 ;
}
static void F_528 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
T_1 V_820 ;
T_1 V_821 , V_822 , V_823 , V_824 , V_825 ;
T_1 V_826 , V_810 ;
F_124 ( F_64 ( V_94 ) ,
V_38 -> V_173 . V_45 &
~ ( V_103 | V_818 ) ) ;
if ( ( V_38 -> V_173 . V_45 & V_103 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_821 = V_38 -> V_45 . V_51 ;
V_822 = V_38 -> V_45 . V_54 ;
V_823 = V_38 -> V_45 . V_47 ;
V_824 = V_38 -> V_45 . V_49 ;
V_825 = V_38 -> V_45 . V_50 ;
if ( V_94 == V_120 )
F_597 ( V_6 , V_94 ) ;
F_135 ( V_6 , V_94 , V_827 , 0x0100000f ) ;
V_810 = F_133 ( V_6 , V_94 , F_618 ( V_94 ) ) ;
V_810 &= 0x00ffffff ;
F_135 ( V_6 , V_94 , F_618 ( V_94 ) , V_810 ) ;
F_135 ( V_6 , V_94 , V_828 , 0x610 ) ;
V_820 = ( ( V_822 << V_829 ) | ( V_823 & V_830 ) ) ;
V_820 |= ( ( V_824 << V_831 ) | ( V_825 << V_832 ) ) ;
V_820 |= ( ( V_821 << V_833 ) ) ;
V_820 |= ( 1 << V_834 ) ;
V_820 |= ( V_835 << V_836 ) ;
F_135 ( V_6 , V_94 , F_619 ( V_94 ) , V_820 ) ;
V_820 |= V_837 ;
F_135 ( V_6 , V_94 , F_619 ( V_94 ) , V_820 ) ;
if ( V_38 -> V_39 == 162000 ||
F_38 ( V_65 -> V_90 , V_616 ) ||
F_38 ( V_65 -> V_90 , V_208 ) )
F_135 ( V_6 , V_94 , F_620 ( V_94 ) ,
0x009f0003 ) ;
else
F_135 ( V_6 , V_94 , F_620 ( V_94 ) ,
0x00d0000f ) ;
if ( F_389 ( V_38 ) ) {
if ( V_94 == V_113 )
F_135 ( V_6 , V_94 , F_621 ( V_94 ) ,
0x0df40000 ) ;
else
F_135 ( V_6 , V_94 , F_621 ( V_94 ) ,
0x0df70000 ) ;
} else {
if ( V_94 == V_113 )
F_135 ( V_6 , V_94 , F_621 ( V_94 ) ,
0x0df70000 ) ;
else
F_135 ( V_6 , V_94 , F_621 ( V_94 ) ,
0x0df40000 ) ;
}
V_826 = F_133 ( V_6 , V_94 , F_622 ( V_94 ) ) ;
V_826 = ( V_826 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_389 ( V_65 -> V_90 ) )
V_826 |= 0x01000000 ;
F_135 ( V_6 , V_94 , F_622 ( V_94 ) , V_826 ) ;
F_135 ( V_6 , V_94 , F_623 ( V_94 ) , 0x87871000 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_527 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
enum V_176 V_177 = F_132 ( V_94 ) ;
T_1 V_838 , V_839 ;
T_1 V_821 , V_822 , V_823 , V_824 , V_825 , V_840 ;
T_1 V_841 ;
int V_52 ;
F_124 ( F_64 ( V_94 ) ,
V_38 -> V_173 . V_45 & ~ V_103 ) ;
if ( ( V_38 -> V_173 . V_45 & V_103 ) == 0 )
return;
V_821 = V_38 -> V_45 . V_51 ;
V_840 = V_38 -> V_45 . V_47 & 0x3fffff ;
V_822 = V_38 -> V_45 . V_54 ;
V_823 = V_38 -> V_45 . V_47 >> 22 ;
V_824 = V_38 -> V_45 . V_49 ;
V_825 = V_38 -> V_45 . V_50 ;
V_52 = V_38 -> V_45 . V_52 ;
V_841 = 0 ;
V_838 = 0 ;
F_3 ( & V_6 -> V_9 ) ;
F_135 ( V_6 , V_94 , F_624 ( V_177 ) ,
5 << V_842 |
V_824 << V_843 |
V_825 << V_844 |
1 << V_845 ) ;
F_135 ( V_6 , V_94 , F_625 ( V_177 ) , V_823 ) ;
F_135 ( V_6 , V_94 , F_626 ( V_177 ) ,
V_846 |
1 << V_847 ) ;
F_135 ( V_6 , V_94 , F_627 ( V_177 ) , V_840 ) ;
V_841 = F_133 ( V_6 , V_94 , F_628 ( V_177 ) ) ;
V_841 &= ~ ( V_848 | V_849 ) ;
V_841 |= ( 2 << V_850 ) ;
if ( V_840 )
V_841 |= V_849 ;
F_135 ( V_6 , V_94 , F_628 ( V_177 ) , V_841 ) ;
V_841 = F_133 ( V_6 , V_94 , F_629 ( V_177 ) ) ;
V_841 &= ~ ( V_851 |
V_852 ) ;
V_841 |= ( 0x5 << V_853 ) ;
if ( ! V_840 )
V_841 |= V_852 ;
F_135 ( V_6 , V_94 , F_629 ( V_177 ) , V_841 ) ;
if ( V_52 == 5400000 ) {
V_838 |= ( 0x3 << V_854 ) ;
V_838 |= ( 0x8 << V_855 ) ;
V_838 |= ( 0x1 << V_856 ) ;
V_839 = 0x9 ;
} else if ( V_52 <= 6200000 ) {
V_838 |= ( 0x5 << V_854 ) ;
V_838 |= ( 0xB << V_855 ) ;
V_838 |= ( 0x3 << V_856 ) ;
V_839 = 0x9 ;
} else if ( V_52 <= 6480000 ) {
V_838 |= ( 0x4 << V_854 ) ;
V_838 |= ( 0x9 << V_855 ) ;
V_838 |= ( 0x3 << V_856 ) ;
V_839 = 0x8 ;
} else {
V_838 |= ( 0x4 << V_854 ) ;
V_838 |= ( 0x9 << V_855 ) ;
V_838 |= ( 0x3 << V_856 ) ;
V_839 = 0 ;
}
F_135 ( V_6 , V_94 , F_630 ( V_177 ) , V_838 ) ;
V_841 = F_133 ( V_6 , V_94 , F_631 ( V_177 ) ) ;
V_841 &= ~ V_857 ;
V_841 |= ( V_839 << V_858 ) ;
F_135 ( V_6 , V_94 , F_631 ( V_177 ) , V_841 ) ;
F_135 ( V_6 , V_94 , F_134 ( V_177 ) ,
F_133 ( V_6 , V_94 , F_134 ( V_177 ) ) |
V_859 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
int F_632 ( struct V_5 * V_6 , enum V_94 V_94 ,
const struct V_45 * V_45 )
{
struct V_81 * V_65 = F_53 ( V_6 , V_94 ) ;
struct V_37 * V_38 ;
V_38 = F_551 ( sizeof( * V_38 ) , V_722 ) ;
if ( ! V_38 )
return - V_721 ;
V_38 -> V_64 . V_65 = & V_65 -> V_64 ;
V_38 -> V_591 = 1 ;
V_38 -> V_45 = * V_45 ;
if ( F_17 ( V_6 ) ) {
F_617 ( V_65 , V_38 ) ;
F_527 ( V_65 , V_38 ) ;
F_136 ( V_65 , V_38 ) ;
} else {
F_616 ( V_65 , V_38 ) ;
F_528 ( V_65 , V_38 ) ;
F_128 ( V_65 , V_38 ) ;
}
F_237 ( V_38 ) ;
return 0 ;
}
void F_633 ( struct V_5 * V_6 , enum V_94 V_94 )
{
if ( F_17 ( V_6 ) )
F_144 ( V_6 , V_94 ) ;
else
F_143 ( V_6 , V_94 ) ;
}
static void F_634 ( struct V_81 * V_65 ,
struct V_37 * V_60 ,
struct V_45 * V_806 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
T_1 V_45 ;
struct V_45 * clock = & V_60 -> V_45 ;
F_596 ( V_65 , V_60 , V_806 ) ;
V_45 = V_184 ;
if ( F_38 ( V_60 , V_66 ) )
V_45 |= V_860 ;
else
V_45 |= V_861 ;
if ( F_635 ( V_6 ) || F_636 ( V_6 ) || F_586 ( V_6 ) ) {
V_45 |= ( V_60 -> V_591 - 1 )
<< V_862 ;
}
if ( F_38 ( V_60 , V_213 ) ||
F_38 ( V_60 , V_208 ) )
V_45 |= V_863 ;
if ( F_389 ( V_60 ) )
V_45 |= V_863 ;
if ( F_19 ( V_6 ) )
V_45 |= ( 1 << ( clock -> V_49 - 1 ) ) << V_864 ;
else {
V_45 |= ( 1 << ( clock -> V_49 - 1 ) ) << V_865 ;
if ( F_18 ( V_6 ) && V_806 )
V_45 |= ( 1 << ( V_806 -> V_49 - 1 ) ) << V_866 ;
}
switch ( clock -> V_50 ) {
case 5 :
V_45 |= V_867 ;
break;
case 7 :
V_45 |= V_868 ;
break;
case 10 :
V_45 |= V_869 ;
break;
case 14 :
V_45 |= V_870 ;
break;
}
if ( F_59 ( V_6 ) >= 4 )
V_45 |= ( 6 << V_871 ) ;
if ( V_60 -> V_872 )
V_45 |= V_873 ;
else if ( F_38 ( V_60 , V_66 ) &&
F_593 ( V_6 ) )
V_45 |= V_874 ;
else
V_45 |= V_875 ;
V_45 |= V_103 ;
V_60 -> V_173 . V_45 = V_45 ;
if ( F_59 ( V_6 ) >= 4 ) {
T_1 V_175 = ( V_60 -> V_591 - 1 )
<< V_819 ;
V_60 -> V_173 . V_175 = V_175 ;
}
}
static void F_637 ( struct V_81 * V_65 ,
struct V_37 * V_60 ,
struct V_45 * V_806 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_45 ;
struct V_45 * clock = & V_60 -> V_45 ;
F_596 ( V_65 , V_60 , V_806 ) ;
V_45 = V_184 ;
if ( F_38 ( V_60 , V_66 ) ) {
V_45 |= ( 1 << ( clock -> V_49 - 1 ) ) << V_865 ;
} else {
if ( clock -> V_49 == 2 )
V_45 |= V_876 ;
else
V_45 |= ( clock -> V_49 - 2 ) << V_865 ;
if ( clock -> V_50 == 4 )
V_45 |= V_877 ;
}
if ( ! F_141 ( V_6 ) &&
F_38 ( V_60 , V_186 ) )
V_45 |= V_187 ;
if ( F_38 ( V_60 , V_66 ) &&
F_593 ( V_6 ) )
V_45 |= V_874 ;
else
V_45 |= V_875 ;
V_45 |= V_103 ;
V_60 -> V_173 . V_45 = V_45 ;
}
static void F_436 ( struct V_81 * V_81 )
{
struct V_5 * V_6 = F_41 ( V_81 -> V_64 . V_63 ) ;
enum V_94 V_94 = V_81 -> V_94 ;
enum V_93 V_95 = V_81 -> V_90 -> V_95 ;
const struct V_519 * V_91 = & V_81 -> V_90 -> V_64 . V_91 ;
T_2 V_878 , V_879 ;
int V_880 = 0 ;
V_878 = V_91 -> V_878 ;
V_879 = V_91 -> V_879 ;
if ( V_91 -> V_328 & V_881 ) {
V_878 -= 1 ;
V_879 -= 1 ;
if ( F_38 ( V_81 -> V_90 , V_213 ) )
V_880 = ( V_91 -> V_882 - 1 ) / 2 ;
else
V_880 = V_91 -> V_735 -
V_91 -> V_882 / 2 ;
if ( V_880 < 0 )
V_880 += V_91 -> V_882 ;
}
if ( F_59 ( V_6 ) > 3 )
F_124 ( F_376 ( V_95 ) , V_880 ) ;
F_124 ( F_364 ( V_95 ) ,
( V_91 -> V_542 - 1 ) |
( ( V_91 -> V_882 - 1 ) << 16 ) ) ;
F_124 ( F_366 ( V_95 ) ,
( V_91 -> V_883 - 1 ) |
( ( V_91 -> V_884 - 1 ) << 16 ) ) ;
F_124 ( F_368 ( V_95 ) ,
( V_91 -> V_735 - 1 ) |
( ( V_91 -> V_885 - 1 ) << 16 ) ) ;
F_124 ( F_370 ( V_95 ) ,
( V_91 -> V_543 - 1 ) |
( ( V_878 - 1 ) << 16 ) ) ;
F_124 ( F_372 ( V_95 ) ,
( V_91 -> V_886 - 1 ) |
( ( V_879 - 1 ) << 16 ) ) ;
F_124 ( F_374 ( V_95 ) ,
( V_91 -> V_887 - 1 ) |
( ( V_91 -> V_888 - 1 ) << 16 ) ) ;
if ( F_265 ( V_6 ) && V_95 == V_590 &&
( V_94 == V_120 || V_94 == V_509 ) )
F_124 ( F_370 ( V_94 ) , F_11 ( F_370 ( V_95 ) ) ) ;
}
static void F_437 ( struct V_81 * V_81 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_94 V_94 = V_81 -> V_94 ;
F_124 ( F_322 ( V_94 ) ,
( ( V_81 -> V_90 -> V_365 - 1 ) << 16 ) |
( V_81 -> V_90 -> V_364 - 1 ) ) ;
}
static void F_638 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_93 V_95 = V_38 -> V_95 ;
T_2 V_178 ;
V_178 = F_11 ( F_364 ( V_95 ) ) ;
V_38 -> V_64 . V_91 . V_542 = ( V_178 & 0xffff ) + 1 ;
V_38 -> V_64 . V_91 . V_882 = ( ( V_178 >> 16 ) & 0xffff ) + 1 ;
V_178 = F_11 ( F_366 ( V_95 ) ) ;
V_38 -> V_64 . V_91 . V_883 = ( V_178 & 0xffff ) + 1 ;
V_38 -> V_64 . V_91 . V_884 = ( ( V_178 >> 16 ) & 0xffff ) + 1 ;
V_178 = F_11 ( F_368 ( V_95 ) ) ;
V_38 -> V_64 . V_91 . V_735 = ( V_178 & 0xffff ) + 1 ;
V_38 -> V_64 . V_91 . V_885 = ( ( V_178 >> 16 ) & 0xffff ) + 1 ;
V_178 = F_11 ( F_370 ( V_95 ) ) ;
V_38 -> V_64 . V_91 . V_543 = ( V_178 & 0xffff ) + 1 ;
V_38 -> V_64 . V_91 . V_878 = ( ( V_178 >> 16 ) & 0xffff ) + 1 ;
V_178 = F_11 ( F_372 ( V_95 ) ) ;
V_38 -> V_64 . V_91 . V_886 = ( V_178 & 0xffff ) + 1 ;
V_38 -> V_64 . V_91 . V_879 = ( ( V_178 >> 16 ) & 0xffff ) + 1 ;
V_178 = F_11 ( F_374 ( V_95 ) ) ;
V_38 -> V_64 . V_91 . V_887 = ( V_178 & 0xffff ) + 1 ;
V_38 -> V_64 . V_91 . V_888 = ( ( V_178 >> 16 ) & 0xffff ) + 1 ;
if ( F_11 ( F_60 ( V_95 ) ) & V_211 ) {
V_38 -> V_64 . V_91 . V_328 |= V_881 ;
V_38 -> V_64 . V_91 . V_878 += 1 ;
V_38 -> V_64 . V_91 . V_879 += 1 ;
}
}
static void F_639 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_178 ;
V_178 = F_11 ( F_322 ( V_65 -> V_94 ) ) ;
V_38 -> V_364 = ( V_178 & 0xffff ) + 1 ;
V_38 -> V_365 = ( ( V_178 >> 16 ) & 0xffff ) + 1 ;
V_38 -> V_64 . V_414 . V_889 = V_38 -> V_364 ;
V_38 -> V_64 . V_414 . V_890 = V_38 -> V_365 ;
}
void F_640 ( struct V_519 * V_414 ,
struct V_37 * V_38 )
{
V_414 -> V_890 = V_38 -> V_64 . V_91 . V_542 ;
V_414 -> V_891 = V_38 -> V_64 . V_91 . V_882 ;
V_414 -> V_892 = V_38 -> V_64 . V_91 . V_735 ;
V_414 -> V_893 = V_38 -> V_64 . V_91 . V_885 ;
V_414 -> V_889 = V_38 -> V_64 . V_91 . V_543 ;
V_414 -> V_894 = V_38 -> V_64 . V_91 . V_878 ;
V_414 -> V_895 = V_38 -> V_64 . V_91 . V_887 ;
V_414 -> V_896 = V_38 -> V_64 . V_91 . V_888 ;
V_414 -> V_328 = V_38 -> V_64 . V_91 . V_328 ;
V_414 -> type = V_897 ;
V_414 -> clock = V_38 -> V_64 . V_91 . V_92 ;
V_414 -> V_328 |= V_38 -> V_64 . V_91 . V_328 ;
V_414 -> V_898 = F_641 ( V_414 ) ;
V_414 -> V_899 = F_642 ( V_414 ) ;
F_643 ( V_414 ) ;
}
static void F_526 ( struct V_81 * V_81 )
{
struct V_5 * V_6 = F_41 ( V_81 -> V_64 . V_63 ) ;
T_2 V_900 ;
V_900 = 0 ;
if ( ( V_81 -> V_94 == V_113 && V_6 -> V_129 & V_130 ) ||
( V_81 -> V_94 == V_120 && V_6 -> V_129 & V_131 ) )
V_900 |= F_11 ( F_60 ( V_81 -> V_94 ) ) & V_132 ;
if ( V_81 -> V_90 -> V_225 )
V_900 |= V_226 ;
if ( F_18 ( V_6 ) || F_16 ( V_6 ) ||
F_17 ( V_6 ) ) {
if ( V_81 -> V_90 -> V_901 && V_81 -> V_90 -> V_730 != 30 )
V_900 |= V_902 |
V_903 ;
switch ( V_81 -> V_90 -> V_730 ) {
case 18 :
V_900 |= V_904 ;
break;
case 24 :
V_900 |= V_209 ;
break;
case 30 :
V_900 |= V_905 ;
break;
default:
F_146 () ;
}
}
if ( F_644 ( V_6 ) ) {
if ( V_81 -> V_809 ) {
F_161 ( L_130 ) ;
V_900 |= V_906 ;
} else {
F_161 ( L_131 ) ;
}
}
if ( V_81 -> V_90 -> V_64 . V_91 . V_328 & V_881 ) {
if ( F_59 ( V_6 ) < 4 ||
F_38 ( V_81 -> V_90 , V_213 ) )
V_900 |= V_907 ;
else
V_900 |= V_908 ;
} else
V_900 |= V_909 ;
if ( ( F_16 ( V_6 ) || F_17 ( V_6 ) ) &&
V_81 -> V_90 -> V_910 )
V_900 |= V_911 ;
F_124 ( F_60 ( V_81 -> V_94 ) , V_900 ) ;
F_125 ( F_60 ( V_81 -> V_94 ) ) ;
}
static int F_645 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
const struct V_56 * V_57 ;
int V_44 = 48000 ;
memset ( & V_60 -> V_173 , 0 ,
sizeof( V_60 -> V_173 ) ) ;
if ( F_38 ( V_60 , V_66 ) ) {
if ( F_593 ( V_6 ) ) {
V_44 = V_6 -> V_803 . V_912 ;
F_161 ( L_132 , V_44 ) ;
}
V_57 = & V_913 ;
} else if ( F_38 ( V_60 , V_186 ) ) {
V_57 = & V_914 ;
} else {
V_57 = & V_915 ;
}
if ( ! V_60 -> V_916 &&
! F_40 ( V_57 , V_60 , V_60 -> V_39 ,
V_44 , NULL , & V_60 -> V_45 ) ) {
F_127 ( L_133 ) ;
return - V_286 ;
}
F_637 ( V_65 , V_60 , NULL ) ;
return 0 ;
}
static int F_646 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
const struct V_56 * V_57 ;
int V_44 = 96000 ;
memset ( & V_60 -> V_173 , 0 ,
sizeof( V_60 -> V_173 ) ) ;
if ( F_38 ( V_60 , V_66 ) ) {
if ( F_593 ( V_6 ) ) {
V_44 = V_6 -> V_803 . V_912 ;
F_161 ( L_132 , V_44 ) ;
}
if ( F_39 ( V_63 ) )
V_57 = & V_917 ;
else
V_57 = & V_918 ;
} else if ( F_38 ( V_60 , V_208 ) ||
F_38 ( V_60 , V_616 ) ) {
V_57 = & V_919 ;
} else if ( F_38 ( V_60 , V_213 ) ) {
V_57 = & V_920 ;
} else {
V_57 = & V_921 ;
}
if ( ! V_60 -> V_916 &&
! F_43 ( V_57 , V_60 , V_60 -> V_39 ,
V_44 , NULL , & V_60 -> V_45 ) ) {
F_127 ( L_133 ) ;
return - V_286 ;
}
F_634 ( V_65 , V_60 , NULL ) ;
return 0 ;
}
static int F_647 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
const struct V_56 * V_57 ;
int V_44 = 96000 ;
memset ( & V_60 -> V_173 , 0 ,
sizeof( V_60 -> V_173 ) ) ;
if ( F_38 ( V_60 , V_66 ) ) {
if ( F_593 ( V_6 ) ) {
V_44 = V_6 -> V_803 . V_912 ;
F_161 ( L_132 , V_44 ) ;
}
V_57 = & V_922 ;
} else {
V_57 = & V_923 ;
}
if ( ! V_60 -> V_916 &&
! F_42 ( V_57 , V_60 , V_60 -> V_39 ,
V_44 , NULL , & V_60 -> V_45 ) ) {
F_127 ( L_133 ) ;
return - V_286 ;
}
F_634 ( V_65 , V_60 , NULL ) ;
return 0 ;
}
static int F_648 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
const struct V_56 * V_57 ;
int V_44 = 96000 ;
memset ( & V_60 -> V_173 , 0 ,
sizeof( V_60 -> V_173 ) ) ;
if ( F_38 ( V_60 , V_66 ) ) {
if ( F_593 ( V_6 ) ) {
V_44 = V_6 -> V_803 . V_912 ;
F_161 ( L_132 , V_44 ) ;
}
V_57 = & V_924 ;
} else {
V_57 = & V_921 ;
}
if ( ! V_60 -> V_916 &&
! F_40 ( V_57 , V_60 , V_60 -> V_39 ,
V_44 , NULL , & V_60 -> V_45 ) ) {
F_127 ( L_133 ) ;
return - V_286 ;
}
F_634 ( V_65 , V_60 , NULL ) ;
return 0 ;
}
static int F_649 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
int V_44 = 100000 ;
const struct V_56 * V_57 = & V_925 ;
memset ( & V_60 -> V_173 , 0 ,
sizeof( V_60 -> V_173 ) ) ;
if ( ! V_60 -> V_916 &&
! F_49 ( V_57 , V_60 , V_60 -> V_39 ,
V_44 , NULL , & V_60 -> V_45 ) ) {
F_127 ( L_133 ) ;
return - V_286 ;
}
F_617 ( V_65 , V_60 ) ;
return 0 ;
}
static int F_650 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
int V_44 = 100000 ;
const struct V_56 * V_57 = & V_926 ;
memset ( & V_60 -> V_173 , 0 ,
sizeof( V_60 -> V_173 ) ) ;
if ( ! V_60 -> V_916 &&
! F_47 ( V_57 , V_60 , V_60 -> V_39 ,
V_44 , NULL , & V_60 -> V_45 ) ) {
F_127 ( L_133 ) ;
return - V_286 ;
}
F_616 ( V_65 , V_60 ) ;
return 0 ;
}
static void F_651 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
T_2 V_178 ;
if ( F_59 ( V_6 ) <= 3 &&
( F_141 ( V_6 ) || ! F_140 ( V_6 ) ) )
return;
V_178 = F_11 ( V_598 ) ;
if ( ! ( V_178 & V_599 ) )
return;
if ( F_59 ( V_6 ) < 4 ) {
if ( V_65 -> V_94 != V_120 )
return;
} else {
if ( ( V_178 & V_927 ) != ( V_65 -> V_94 << V_928 ) )
return;
}
V_38 -> V_596 . V_597 = V_178 ;
V_38 -> V_596 . V_601 = F_11 ( V_600 ) ;
}
static void F_652 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_38 -> V_95 ;
struct V_45 clock ;
T_1 V_820 ;
int V_44 = 100000 ;
if ( ( V_38 -> V_173 . V_45 & V_103 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_820 = F_133 ( V_6 , V_94 , F_619 ( V_94 ) ) ;
F_5 ( & V_6 -> V_9 ) ;
clock . V_54 = ( V_820 >> V_829 ) & 7 ;
clock . V_47 = V_820 & V_830 ;
clock . V_51 = ( V_820 >> V_833 ) & 0xf ;
clock . V_49 = ( V_820 >> V_831 ) & 7 ;
clock . V_50 = ( V_820 >> V_832 ) & 0x1f ;
V_38 -> V_39 = F_31 ( V_44 , & clock ) ;
}
static void
F_653 ( struct V_81 * V_65 ,
struct V_316 * V_317 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_15 , V_64 , V_273 ;
int V_94 = V_65 -> V_94 , V_133 = V_65 -> V_133 ;
int V_929 , V_237 ;
unsigned int V_930 ;
struct V_244 * V_89 ;
struct V_264 * V_265 ;
V_15 = F_11 ( F_88 ( V_133 ) ) ;
if ( ! ( V_15 & V_134 ) )
return;
V_265 = F_551 ( sizeof( * V_265 ) , V_722 ) ;
if ( ! V_265 ) {
F_161 ( L_134 ) ;
return;
}
V_89 = & V_265 -> V_64 ;
if ( F_59 ( V_6 ) >= 4 ) {
if ( V_15 & V_367 ) {
V_317 -> V_326 = V_279 ;
V_89 -> V_257 = V_230 ;
}
}
V_237 = V_15 & V_931 ;
V_929 = F_223 ( V_237 ) ;
V_89 -> V_237 = V_929 ;
V_89 -> V_791 = F_176 ( V_929 , 0 ) * 8 ;
if ( F_59 ( V_6 ) >= 4 ) {
if ( V_317 -> V_326 )
V_273 = F_11 ( F_260 ( V_133 ) ) ;
else
V_273 = F_11 ( F_261 ( V_133 ) ) ;
V_64 = F_11 ( F_259 ( V_133 ) ) & 0xfffff000 ;
} else {
V_64 = F_11 ( F_262 ( V_133 ) ) ;
}
V_317 -> V_64 = V_64 ;
V_15 = F_11 ( F_322 ( V_94 ) ) ;
V_89 -> V_241 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_89 -> V_236 = ( ( V_15 >> 0 ) & 0xfff ) + 1 ;
V_15 = F_11 ( F_258 ( V_94 ) ) ;
V_89 -> V_260 [ 0 ] = V_15 & 0xffffffc0 ;
V_930 = F_175 ( V_63 , V_89 -> V_236 ,
V_89 -> V_237 ,
V_89 -> V_257 ) ;
V_317 -> V_240 = V_89 -> V_260 [ 0 ] * V_930 ;
F_161 ( L_135 ,
F_78 ( V_94 ) , V_133 , V_89 -> V_241 , V_89 -> V_236 ,
V_89 -> V_791 , V_64 , V_89 -> V_260 [ 0 ] ,
V_317 -> V_240 ) ;
V_317 -> V_89 = V_265 ;
}
static void F_654 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_38 -> V_95 ;
enum V_176 V_177 = F_132 ( V_94 ) ;
struct V_45 clock ;
T_1 V_932 , V_933 , V_934 , V_935 , V_936 ;
int V_44 = 100000 ;
if ( ( V_38 -> V_173 . V_45 & V_103 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_932 = F_133 ( V_6 , V_94 , F_624 ( V_177 ) ) ;
V_933 = F_133 ( V_6 , V_94 , F_625 ( V_177 ) ) ;
V_934 = F_133 ( V_6 , V_94 , F_626 ( V_177 ) ) ;
V_935 = F_133 ( V_6 , V_94 , F_627 ( V_177 ) ) ;
V_936 = F_133 ( V_6 , V_94 , F_628 ( V_177 ) ) ;
F_5 ( & V_6 -> V_9 ) ;
clock . V_54 = ( V_934 & 0x7 ) == V_846 ? 2 : 0 ;
clock . V_47 = ( V_933 & 0xff ) << 22 ;
if ( V_936 & V_849 )
clock . V_47 |= V_935 & 0x3fffff ;
clock . V_51 = ( V_934 >> V_847 ) & 0xf ;
clock . V_49 = ( V_932 >> V_843 ) & 0x7 ;
clock . V_50 = ( V_932 >> V_844 ) & 0x1f ;
V_38 -> V_39 = F_32 ( V_44 , & clock ) ;
}
static bool F_655 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
enum V_127 V_128 ;
T_2 V_178 ;
bool V_360 ;
V_128 = F_468 ( V_65 -> V_94 ) ;
if ( ! F_85 ( V_6 , V_128 ) )
return false ;
V_38 -> V_95 = (enum V_93 ) V_65 -> V_94 ;
V_38 -> V_205 = NULL ;
V_360 = false ;
V_178 = F_11 ( F_60 ( V_65 -> V_94 ) ) ;
if ( ! ( V_178 & V_132 ) )
goto V_937;
if ( F_18 ( V_6 ) || F_16 ( V_6 ) ||
F_17 ( V_6 ) ) {
switch ( V_178 & V_207 ) {
case V_904 :
V_38 -> V_730 = 18 ;
break;
case V_209 :
V_38 -> V_730 = 24 ;
break;
case V_905 :
V_38 -> V_730 = 30 ;
break;
default:
break;
}
}
if ( ( F_16 ( V_6 ) || F_17 ( V_6 ) ) &&
( V_178 & V_911 ) )
V_38 -> V_910 = true ;
if ( F_59 ( V_6 ) < 4 )
V_38 -> V_225 = V_178 & V_226 ;
F_638 ( V_65 , V_38 ) ;
F_639 ( V_65 , V_38 ) ;
F_651 ( V_65 , V_38 ) ;
if ( F_59 ( V_6 ) >= 4 ) {
if ( F_17 ( V_6 ) && V_65 -> V_94 != V_113 )
V_178 = V_6 -> V_183 [ V_65 -> V_94 ] ;
else
V_178 = F_11 ( F_130 ( V_65 -> V_94 ) ) ;
V_38 -> V_591 =
( ( V_178 & V_938 )
>> V_819 ) + 1 ;
V_38 -> V_173 . V_175 = V_178 ;
} else if ( F_635 ( V_6 ) || F_636 ( V_6 ) ||
F_586 ( V_6 ) ) {
V_178 = F_11 ( F_64 ( V_65 -> V_94 ) ) ;
V_38 -> V_591 =
( ( V_178 & V_939 )
>> V_862 ) + 1 ;
} else {
V_38 -> V_591 = 1 ;
}
V_38 -> V_173 . V_45 = F_11 ( F_64 ( V_65 -> V_94 ) ) ;
if ( ! F_16 ( V_6 ) && ! F_17 ( V_6 ) ) {
if ( F_141 ( V_6 ) )
V_38 -> V_173 . V_45 &= ~ V_187 ;
V_38 -> V_173 . V_713 = F_11 ( F_530 ( V_65 -> V_94 ) ) ;
V_38 -> V_173 . V_714 = F_11 ( F_531 ( V_65 -> V_94 ) ) ;
} else {
V_38 -> V_173 . V_45 &= ~ ( V_174 |
V_200 |
V_198 ) ;
}
if ( F_17 ( V_6 ) )
F_654 ( V_65 , V_38 ) ;
else if ( F_16 ( V_6 ) )
F_652 ( V_65 , V_38 ) ;
else
F_656 ( V_65 , V_38 ) ;
V_38 -> V_64 . V_91 . V_92 =
V_38 -> V_39 / V_38 -> V_591 ;
V_360 = true ;
V_937:
F_86 ( V_6 , V_128 ) ;
return V_360 ;
}
static void F_657 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_510 * V_511 ;
int V_135 ;
T_1 V_15 , V_940 ;
bool V_941 = false ;
bool V_942 = false ;
bool V_943 = false ;
bool V_944 = false ;
bool V_945 = false ;
bool V_946 = false ;
F_658 (dev, encoder) {
switch ( V_511 -> type ) {
case V_66 :
V_943 = true ;
V_941 = true ;
break;
case V_513 :
V_943 = true ;
if ( F_381 ( & V_511 -> V_64 ) -> V_177 == V_602 )
V_942 = true ;
break;
default:
break;
}
}
if ( F_120 ( V_6 ) ) {
V_944 = V_6 -> V_803 . V_947 ;
V_945 = V_944 ;
} else {
V_944 = false ;
V_945 = true ;
}
for ( V_135 = 0 ; V_135 < V_6 -> V_948 ; V_135 ++ ) {
T_1 V_443 = F_11 ( F_659 ( V_135 ) ) ;
if ( ! ( V_443 & V_103 ) )
continue;
if ( ( V_443 & V_949 ) ==
V_874 ) {
V_946 = true ;
break;
}
}
F_161 ( L_136 ,
V_943 , V_941 , V_944 , V_946 ) ;
V_15 = F_11 ( V_950 ) ;
V_940 = V_15 ;
V_940 &= ~ V_951 ;
if ( V_944 )
V_940 |= V_952 ;
else
V_940 |= V_953 ;
V_940 &= ~ V_954 ;
V_940 &= ~ V_955 ;
V_940 &= ~ V_956 ;
if ( V_943 ) {
V_940 |= V_957 ;
if ( F_593 ( V_6 ) && V_945 )
V_940 |= V_956 ;
if ( V_942 ) {
if ( F_593 ( V_6 ) && V_945 )
V_940 |= V_958 ;
else
V_940 |= V_959 ;
} else
V_940 |= V_960 ;
} else if ( V_946 ) {
V_940 |= V_957 ;
V_940 |= V_956 ;
}
if ( V_940 == V_15 )
return;
V_15 &= ~ V_951 ;
if ( V_944 )
V_15 |= V_952 ;
else
V_15 |= V_953 ;
if ( V_943 ) {
V_15 &= ~ V_954 ;
V_15 |= V_957 ;
if ( F_593 ( V_6 ) && V_945 ) {
F_161 ( L_137 ) ;
V_15 |= V_956 ;
} else
V_15 &= ~ V_956 ;
F_124 ( V_950 , V_15 ) ;
F_125 ( V_950 ) ;
F_126 ( 200 ) ;
V_15 &= ~ V_955 ;
if ( V_942 ) {
if ( F_593 ( V_6 ) && V_945 ) {
F_161 ( L_138 ) ;
V_15 |= V_958 ;
} else
V_15 |= V_959 ;
} else
V_15 |= V_960 ;
F_124 ( V_950 , V_15 ) ;
F_125 ( V_950 ) ;
F_126 ( 200 ) ;
} else {
F_161 ( L_139 ) ;
V_15 &= ~ V_955 ;
V_15 |= V_960 ;
F_124 ( V_950 , V_15 ) ;
F_125 ( V_950 ) ;
F_126 ( 200 ) ;
if ( ! V_946 ) {
F_161 ( L_140 ) ;
V_15 &= ~ V_954 ;
V_15 |= V_961 ;
V_15 &= ~ V_956 ;
F_124 ( V_950 , V_15 ) ;
F_125 ( V_950 ) ;
F_126 ( 200 ) ;
}
}
F_660 ( V_15 != V_940 ) ;
}
static void F_661 ( struct V_5 * V_6 )
{
T_2 V_178 ;
V_178 = F_11 ( V_962 ) ;
V_178 |= V_963 ;
F_124 ( V_962 , V_178 ) ;
if ( F_662 ( F_11 ( V_962 ) &
V_964 , 100 ) )
F_127 ( L_141 ) ;
V_178 = F_11 ( V_962 ) ;
V_178 &= ~ V_963 ;
F_124 ( V_962 , V_178 ) ;
if ( F_662 ( ( F_11 ( V_962 ) &
V_964 ) == 0 , 100 ) )
F_127 ( L_142 ) ;
}
static void F_663 ( struct V_5 * V_6 )
{
T_2 V_178 ;
V_178 = F_354 ( V_6 , 0x8008 , V_965 ) ;
V_178 &= ~ ( 0xFF << 24 ) ;
V_178 |= ( 0x12 << 24 ) ;
F_355 ( V_6 , 0x8008 , V_178 , V_965 ) ;
V_178 = F_354 ( V_6 , 0x2008 , V_965 ) ;
V_178 |= ( 1 << 11 ) ;
F_355 ( V_6 , 0x2008 , V_178 , V_965 ) ;
V_178 = F_354 ( V_6 , 0x2108 , V_965 ) ;
V_178 |= ( 1 << 11 ) ;
F_355 ( V_6 , 0x2108 , V_178 , V_965 ) ;
V_178 = F_354 ( V_6 , 0x206C , V_965 ) ;
V_178 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_355 ( V_6 , 0x206C , V_178 , V_965 ) ;
V_178 = F_354 ( V_6 , 0x216C , V_965 ) ;
V_178 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_355 ( V_6 , 0x216C , V_178 , V_965 ) ;
V_178 = F_354 ( V_6 , 0x2080 , V_965 ) ;
V_178 &= ~ ( 7 << 13 ) ;
V_178 |= ( 5 << 13 ) ;
F_355 ( V_6 , 0x2080 , V_178 , V_965 ) ;
V_178 = F_354 ( V_6 , 0x2180 , V_965 ) ;
V_178 &= ~ ( 7 << 13 ) ;
V_178 |= ( 5 << 13 ) ;
F_355 ( V_6 , 0x2180 , V_178 , V_965 ) ;
V_178 = F_354 ( V_6 , 0x208C , V_965 ) ;
V_178 &= ~ 0xFF ;
V_178 |= 0x1C ;
F_355 ( V_6 , 0x208C , V_178 , V_965 ) ;
V_178 = F_354 ( V_6 , 0x218C , V_965 ) ;
V_178 &= ~ 0xFF ;
V_178 |= 0x1C ;
F_355 ( V_6 , 0x218C , V_178 , V_965 ) ;
V_178 = F_354 ( V_6 , 0x2098 , V_965 ) ;
V_178 &= ~ ( 0xFF << 16 ) ;
V_178 |= ( 0x1C << 16 ) ;
F_355 ( V_6 , 0x2098 , V_178 , V_965 ) ;
V_178 = F_354 ( V_6 , 0x2198 , V_965 ) ;
V_178 &= ~ ( 0xFF << 16 ) ;
V_178 |= ( 0x1C << 16 ) ;
F_355 ( V_6 , 0x2198 , V_178 , V_965 ) ;
V_178 = F_354 ( V_6 , 0x20C4 , V_965 ) ;
V_178 |= ( 1 << 27 ) ;
F_355 ( V_6 , 0x20C4 , V_178 , V_965 ) ;
V_178 = F_354 ( V_6 , 0x21C4 , V_965 ) ;
V_178 |= ( 1 << 27 ) ;
F_355 ( V_6 , 0x21C4 , V_178 , V_965 ) ;
V_178 = F_354 ( V_6 , 0x20EC , V_965 ) ;
V_178 &= ~ ( 0xF << 28 ) ;
V_178 |= ( 4 << 28 ) ;
F_355 ( V_6 , 0x20EC , V_178 , V_965 ) ;
V_178 = F_354 ( V_6 , 0x21EC , V_965 ) ;
V_178 &= ~ ( 0xF << 28 ) ;
V_178 |= ( 4 << 28 ) ;
F_355 ( V_6 , 0x21EC , V_178 , V_965 ) ;
}
static void F_664 ( struct V_62 * V_63 , bool V_966 ,
bool V_967 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_2 V_13 , V_178 ;
if ( F_7 ( V_967 && ! V_966 , L_143 ) )
V_966 = true ;
if ( F_7 ( F_665 ( V_6 ) &&
V_967 , L_144 ) )
V_967 = false ;
F_3 ( & V_6 -> V_9 ) ;
V_178 = F_354 ( V_6 , V_968 , V_486 ) ;
V_178 &= ~ V_487 ;
V_178 |= V_969 ;
F_355 ( V_6 , V_968 , V_178 , V_486 ) ;
F_126 ( 24 ) ;
if ( V_966 ) {
V_178 = F_354 ( V_6 , V_968 , V_486 ) ;
V_178 &= ~ V_969 ;
F_355 ( V_6 , V_968 , V_178 , V_486 ) ;
if ( V_967 ) {
F_661 ( V_6 ) ;
F_663 ( V_6 ) ;
}
}
V_13 = F_665 ( V_6 ) ? V_970 : V_971 ;
V_178 = F_354 ( V_6 , V_13 , V_486 ) ;
V_178 |= V_972 ;
F_355 ( V_6 , V_13 , V_178 , V_486 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_666 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_2 V_13 , V_178 ;
F_3 ( & V_6 -> V_9 ) ;
V_13 = F_665 ( V_6 ) ? V_970 : V_971 ;
V_178 = F_354 ( V_6 , V_13 , V_486 ) ;
V_178 &= ~ V_972 ;
F_355 ( V_6 , V_13 , V_178 , V_486 ) ;
V_178 = F_354 ( V_6 , V_968 , V_486 ) ;
if ( ! ( V_178 & V_487 ) ) {
if ( ! ( V_178 & V_969 ) ) {
V_178 |= V_969 ;
F_355 ( V_6 , V_968 , V_178 , V_486 ) ;
F_126 ( 32 ) ;
}
V_178 |= V_487 ;
F_355 ( V_6 , V_968 , V_178 , V_486 ) ;
}
F_5 ( & V_6 -> V_9 ) ;
}
static void F_667 ( struct V_5 * V_6 , int V_973 )
{
T_2 V_178 ;
int V_974 = F_668 ( V_973 ) ;
if ( F_28 ( V_973 % 5 != 0 ) )
return;
if ( F_28 ( V_974 >= F_179 ( V_975 ) ) )
return;
F_3 ( & V_6 -> V_9 ) ;
if ( V_973 % 10 != 0 )
V_178 = 0xAAAAAAAB ;
else
V_178 = 0x00000000 ;
F_355 ( V_6 , V_976 , V_178 , V_486 ) ;
V_178 = F_354 ( V_6 , V_977 , V_486 ) ;
V_178 &= 0xffff0000 ;
V_178 |= V_975 [ V_974 ] ;
F_355 ( V_6 , V_977 , V_178 , V_486 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_669 ( struct V_62 * V_63 )
{
struct V_510 * V_511 ;
bool V_978 = false ;
F_658 (dev, encoder) {
switch ( V_511 -> type ) {
case V_616 :
V_978 = true ;
break;
default:
break;
}
}
if ( V_978 ) {
F_667 ( F_41 ( V_63 ) , 0 ) ;
F_664 ( V_63 , true , true ) ;
} else {
F_666 ( V_63 ) ;
}
}
void F_670 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
if ( F_120 ( V_6 ) || F_106 ( V_6 ) )
F_657 ( V_63 ) ;
else if ( F_159 ( V_6 ) )
F_669 ( V_63 ) ;
}
static void F_439 ( struct V_144 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_2 V_15 ;
V_15 = 0 ;
switch ( V_81 -> V_90 -> V_730 ) {
case 18 :
V_15 |= V_904 ;
break;
case 24 :
V_15 |= V_209 ;
break;
case 30 :
V_15 |= V_905 ;
break;
case 36 :
V_15 |= V_979 ;
break;
default:
F_146 () ;
}
if ( V_81 -> V_90 -> V_901 )
V_15 |= ( V_902 | V_903 ) ;
if ( V_81 -> V_90 -> V_64 . V_91 . V_328 & V_881 )
V_15 |= V_212 ;
else
V_15 |= V_909 ;
if ( V_81 -> V_90 -> V_910 )
V_15 |= V_911 ;
F_124 ( F_60 ( V_94 ) , V_15 ) ;
F_125 ( F_60 ( V_94 ) ) ;
}
static void F_447 ( struct V_144 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
enum V_93 V_95 = V_81 -> V_90 -> V_95 ;
T_1 V_15 = 0 ;
if ( F_265 ( V_6 ) && V_81 -> V_90 -> V_901 )
V_15 |= ( V_902 | V_903 ) ;
if ( V_81 -> V_90 -> V_64 . V_91 . V_328 & V_881 )
V_15 |= V_212 ;
else
V_15 |= V_909 ;
F_124 ( F_60 ( V_95 ) , V_15 ) ;
F_125 ( F_60 ( V_95 ) ) ;
}
static void F_448 ( struct V_144 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
if ( F_266 ( V_6 ) || F_184 ( V_6 ) -> V_250 >= 9 ) {
T_1 V_15 = 0 ;
switch ( V_81 -> V_90 -> V_730 ) {
case 18 :
V_15 |= V_980 ;
break;
case 24 :
V_15 |= V_981 ;
break;
case 30 :
V_15 |= V_982 ;
break;
case 36 :
V_15 |= V_983 ;
break;
default:
F_146 () ;
}
if ( V_81 -> V_90 -> V_901 )
V_15 |= V_984 | V_985 ;
F_124 ( F_671 ( V_81 -> V_94 ) , V_15 ) ;
}
}
int F_556 ( int V_85 , int V_727 , int V_986 )
{
T_1 V_987 = V_85 * V_986 * 21 / 20 ;
return F_221 ( V_987 , V_727 * 8 ) ;
}
static bool F_672 ( struct V_45 * V_45 , int V_988 )
{
return F_29 ( V_45 ) < V_988 * V_45 -> V_51 ;
}
static void F_673 ( struct V_81 * V_81 ,
struct V_37 * V_60 ,
struct V_45 * V_806 )
{
struct V_144 * V_65 = & V_81 -> V_64 ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_45 , V_807 , V_808 ;
int V_988 ;
V_988 = 21 ;
if ( F_38 ( V_60 , V_66 ) ) {
if ( ( F_593 ( V_6 ) &&
V_6 -> V_803 . V_912 == 100000 ) ||
( F_120 ( V_6 ) && F_39 ( V_63 ) ) )
V_988 = 25 ;
} else if ( V_60 -> V_872 )
V_988 = 20 ;
V_807 = F_595 ( & V_60 -> V_45 ) ;
if ( F_672 ( & V_60 -> V_45 , V_988 ) )
V_807 |= V_989 ;
if ( V_806 ) {
V_808 = F_595 ( V_806 ) ;
if ( V_806 -> V_46 < V_988 * V_806 -> V_51 )
V_808 |= V_989 ;
} else {
V_808 = V_807 ;
}
V_45 = 0 ;
if ( F_38 ( V_60 , V_66 ) )
V_45 |= V_860 ;
else
V_45 |= V_861 ;
V_45 |= ( V_60 -> V_591 - 1 )
<< V_990 ;
if ( F_38 ( V_60 , V_213 ) ||
F_38 ( V_60 , V_208 ) )
V_45 |= V_863 ;
if ( F_389 ( V_60 ) )
V_45 |= V_863 ;
if ( F_184 ( V_6 ) -> V_725 == 3 &&
F_38 ( V_60 , V_616 ) )
V_45 |= V_863 ;
V_45 |= ( 1 << ( V_60 -> V_45 . V_49 - 1 ) ) << V_865 ;
V_45 |= ( 1 << ( V_60 -> V_45 . V_49 - 1 ) ) << V_866 ;
switch ( V_60 -> V_45 . V_50 ) {
case 5 :
V_45 |= V_867 ;
break;
case 7 :
V_45 |= V_868 ;
break;
case 10 :
V_45 |= V_869 ;
break;
case 14 :
V_45 |= V_870 ;
break;
}
if ( F_38 ( V_60 , V_66 ) &&
F_593 ( V_6 ) )
V_45 |= V_874 ;
else
V_45 |= V_875 ;
V_45 |= V_103 ;
V_60 -> V_173 . V_45 = V_45 ;
V_60 -> V_173 . V_713 = V_807 ;
V_60 -> V_173 . V_714 = V_808 ;
}
static int F_674 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_45 V_806 ;
bool V_991 = false ;
struct V_992 * V_993 ;
const struct V_56 * V_57 ;
int V_44 = 120000 ;
memset ( & V_60 -> V_173 , 0 ,
sizeof( V_60 -> V_173 ) ) ;
V_65 -> V_809 = false ;
if ( ! V_60 -> V_221 )
return 0 ;
if ( F_38 ( V_60 , V_66 ) ) {
if ( F_593 ( V_6 ) ) {
F_161 ( L_132 ,
V_6 -> V_803 . V_912 ) ;
V_44 = V_6 -> V_803 . V_912 ;
}
if ( F_39 ( V_63 ) ) {
if ( V_44 == 100000 )
V_57 = & V_994 ;
else
V_57 = & V_995 ;
} else {
if ( V_44 == 100000 )
V_57 = & V_996 ;
else
V_57 = & V_997 ;
}
} else {
V_57 = & V_998 ;
}
if ( ! V_60 -> V_916 &&
! F_43 ( V_57 , V_60 , V_60 -> V_39 ,
V_44 , NULL , & V_60 -> V_45 ) ) {
F_127 ( L_133 ) ;
return - V_286 ;
}
F_673 ( V_65 , V_60 ,
V_991 ? & V_806 : NULL ) ;
V_993 = F_675 ( V_65 , V_60 , NULL ) ;
if ( V_993 == NULL ) {
F_20 ( L_145 ,
F_78 ( V_65 -> V_94 ) ) ;
return - V_286 ;
}
if ( F_38 ( V_60 , V_66 ) &&
V_991 )
V_65 -> V_809 = true ;
return 0 ;
}
static void F_676 ( struct V_81 * V_65 ,
struct V_795 * V_796 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
V_796 -> V_800 = F_11 ( F_603 ( V_94 ) ) ;
V_796 -> V_801 = F_11 ( F_604 ( V_94 ) ) ;
V_796 -> V_798 = F_11 ( F_600 ( V_94 ) )
& ~ V_514 ;
V_796 -> V_799 = F_11 ( F_602 ( V_94 ) ) ;
V_796 -> V_797 = ( ( F_11 ( F_600 ( V_94 ) )
& V_514 ) >> V_999 ) + 1 ;
}
static void F_677 ( struct V_81 * V_65 ,
enum V_93 V_93 ,
struct V_795 * V_796 ,
struct V_795 * V_812 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
if ( F_59 ( V_6 ) >= 5 ) {
V_796 -> V_800 = F_11 ( F_606 ( V_93 ) ) ;
V_796 -> V_801 = F_11 ( F_607 ( V_93 ) ) ;
V_796 -> V_798 = F_11 ( F_384 ( V_93 ) )
& ~ V_514 ;
V_796 -> V_799 = F_11 ( F_605 ( V_93 ) ) ;
V_796 -> V_797 = ( ( F_11 ( F_384 ( V_93 ) )
& V_514 ) >> V_999 ) + 1 ;
if ( V_812 && F_59 ( V_6 ) < 8 &&
V_65 -> V_90 -> V_813 ) {
V_812 -> V_800 = F_11 ( F_610 ( V_93 ) ) ;
V_812 -> V_801 = F_11 ( F_611 ( V_93 ) ) ;
V_812 -> V_798 = F_11 ( F_608 ( V_93 ) )
& ~ V_514 ;
V_812 -> V_799 = F_11 ( F_609 ( V_93 ) ) ;
V_812 -> V_797 = ( ( F_11 ( F_608 ( V_93 ) )
& V_514 ) >> V_999 ) + 1 ;
}
} else {
V_796 -> V_800 = F_11 ( F_614 ( V_94 ) ) ;
V_796 -> V_801 = F_11 ( F_615 ( V_94 ) ) ;
V_796 -> V_798 = F_11 ( F_612 ( V_94 ) )
& ~ V_514 ;
V_796 -> V_799 = F_11 ( F_613 ( V_94 ) ) ;
V_796 -> V_797 = ( ( F_11 ( F_612 ( V_94 ) )
& V_514 ) >> V_999 ) + 1 ;
}
}
void F_678 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
if ( V_38 -> V_221 )
F_676 ( V_65 , & V_38 -> V_815 ) ;
else
F_677 ( V_65 , V_38 -> V_95 ,
& V_38 -> V_815 ,
& V_38 -> V_816 ) ;
}
static void F_679 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
F_677 ( V_65 , V_38 -> V_95 ,
& V_38 -> V_588 , NULL ) ;
}
static void F_680 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_378 * V_379 = & V_38 -> V_379 ;
T_2 V_412 = 0 ;
int V_377 = - 1 ;
int V_135 ;
for ( V_135 = 0 ; V_135 < V_65 -> V_380 ; V_135 ++ ) {
V_412 = F_11 ( F_270 ( V_65 -> V_94 , V_135 ) ) ;
if ( V_412 & V_413 && ! ( V_412 & V_1000 ) ) {
V_377 = V_135 ;
V_38 -> V_442 . V_145 = true ;
V_38 -> V_442 . V_547 = F_11 ( F_271 ( V_65 -> V_94 , V_135 ) ) ;
V_38 -> V_442 . V_240 = F_11 ( F_272 ( V_65 -> V_94 , V_135 ) ) ;
break;
}
}
V_379 -> V_404 = V_377 ;
if ( V_377 >= 0 ) {
V_379 -> V_532 |= ( 1 << V_541 ) ;
} else {
V_379 -> V_532 &= ~ ( 1 << V_541 ) ;
}
}
static void
F_681 ( struct V_81 * V_65 ,
struct V_316 * V_317 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_15 , V_64 , V_273 , V_1001 , V_326 ;
int V_94 = V_65 -> V_94 ;
int V_929 , V_237 ;
unsigned int V_930 ;
struct V_244 * V_89 ;
struct V_264 * V_265 ;
V_265 = F_551 ( sizeof( * V_265 ) , V_722 ) ;
if ( ! V_265 ) {
F_161 ( L_134 ) ;
return;
}
V_89 = & V_265 -> V_64 ;
V_15 = F_11 ( F_94 ( V_94 , 0 ) ) ;
if ( ! ( V_15 & V_140 ) )
goto error;
V_237 = V_15 & V_1002 ;
V_929 = F_224 ( V_237 ,
V_15 & V_384 ,
V_15 & V_1003 ) ;
V_89 -> V_237 = V_929 ;
V_89 -> V_791 = F_176 ( V_929 , 0 ) * 8 ;
V_326 = V_15 & V_1004 ;
switch ( V_326 ) {
case V_1005 :
V_89 -> V_257 = V_229 ;
break;
case V_395 :
V_317 -> V_326 = V_279 ;
V_89 -> V_257 = V_230 ;
break;
case V_396 :
V_89 -> V_257 = V_231 ;
break;
case V_397 :
V_89 -> V_257 = V_232 ;
break;
default:
F_172 ( V_326 ) ;
goto error;
}
V_64 = F_11 ( F_285 ( V_94 , 0 ) ) & 0xfffff000 ;
V_317 -> V_64 = V_64 ;
V_273 = F_11 ( F_279 ( V_94 , 0 ) ) ;
V_15 = F_11 ( F_281 ( V_94 , 0 ) ) ;
V_89 -> V_236 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_89 -> V_241 = ( ( V_15 >> 0 ) & 0x1fff ) + 1 ;
V_15 = F_11 ( F_280 ( V_94 , 0 ) ) ;
V_1001 = F_268 ( V_6 , V_89 -> V_257 ,
V_89 -> V_237 ) ;
V_89 -> V_260 [ 0 ] = ( V_15 & 0x3ff ) * V_1001 ;
V_930 = F_175 ( V_63 , V_89 -> V_236 ,
V_89 -> V_237 ,
V_89 -> V_257 ) ;
V_317 -> V_240 = V_89 -> V_260 [ 0 ] * V_930 ;
F_161 ( L_146 ,
F_78 ( V_94 ) , V_89 -> V_241 , V_89 -> V_236 ,
V_89 -> V_791 , V_64 , V_89 -> V_260 [ 0 ] ,
V_317 -> V_240 ) ;
V_317 -> V_89 = V_265 ;
return;
error:
F_237 ( V_265 ) ;
}
static void F_682 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_2 V_178 ;
V_178 = F_11 ( F_396 ( V_65 -> V_94 ) ) ;
if ( V_178 & V_548 ) {
V_38 -> V_442 . V_145 = true ;
V_38 -> V_442 . V_547 = F_11 ( F_398 ( V_65 -> V_94 ) ) ;
V_38 -> V_442 . V_240 = F_11 ( F_399 ( V_65 -> V_94 ) ) ;
if ( F_683 ( V_6 ) ) {
F_28 ( ( V_178 & V_1006 ) !=
F_397 ( V_65 -> V_94 ) ) ;
}
}
}
static void
F_684 ( struct V_81 * V_65 ,
struct V_316 * V_317 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_15 , V_64 , V_273 ;
int V_94 = V_65 -> V_94 ;
int V_929 , V_237 ;
unsigned int V_930 ;
struct V_244 * V_89 ;
struct V_264 * V_265 ;
V_15 = F_11 ( F_88 ( V_94 ) ) ;
if ( ! ( V_15 & V_134 ) )
return;
V_265 = F_551 ( sizeof( * V_265 ) , V_722 ) ;
if ( ! V_265 ) {
F_161 ( L_134 ) ;
return;
}
V_89 = & V_265 -> V_64 ;
if ( F_59 ( V_6 ) >= 4 ) {
if ( V_15 & V_367 ) {
V_317 -> V_326 = V_279 ;
V_89 -> V_257 = V_230 ;
}
}
V_237 = V_15 & V_931 ;
V_929 = F_223 ( V_237 ) ;
V_89 -> V_237 = V_929 ;
V_89 -> V_791 = F_176 ( V_929 , 0 ) * 8 ;
V_64 = F_11 ( F_259 ( V_94 ) ) & 0xfffff000 ;
if ( F_265 ( V_6 ) || F_266 ( V_6 ) ) {
V_273 = F_11 ( F_267 ( V_94 ) ) ;
} else {
if ( V_317 -> V_326 )
V_273 = F_11 ( F_260 ( V_94 ) ) ;
else
V_273 = F_11 ( F_261 ( V_94 ) ) ;
}
V_317 -> V_64 = V_64 ;
V_15 = F_11 ( F_322 ( V_94 ) ) ;
V_89 -> V_241 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_89 -> V_236 = ( ( V_15 >> 0 ) & 0xfff ) + 1 ;
V_15 = F_11 ( F_258 ( V_94 ) ) ;
V_89 -> V_260 [ 0 ] = V_15 & 0xffffffc0 ;
V_930 = F_175 ( V_63 , V_89 -> V_236 ,
V_89 -> V_237 ,
V_89 -> V_257 ) ;
V_317 -> V_240 = V_89 -> V_260 [ 0 ] * V_930 ;
F_161 ( L_146 ,
F_78 ( V_94 ) , V_89 -> V_241 , V_89 -> V_236 ,
V_89 -> V_791 , V_64 , V_89 -> V_260 [ 0 ] ,
V_317 -> V_240 ) ;
V_317 -> V_89 = V_265 ;
}
static bool F_685 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_127 V_128 ;
T_2 V_178 ;
bool V_360 ;
V_128 = F_468 ( V_65 -> V_94 ) ;
if ( ! F_85 ( V_6 , V_128 ) )
return false ;
V_38 -> V_95 = (enum V_93 ) V_65 -> V_94 ;
V_38 -> V_205 = NULL ;
V_360 = false ;
V_178 = F_11 ( F_60 ( V_65 -> V_94 ) ) ;
if ( ! ( V_178 & V_132 ) )
goto V_937;
switch ( V_178 & V_207 ) {
case V_904 :
V_38 -> V_730 = 18 ;
break;
case V_209 :
V_38 -> V_730 = 24 ;
break;
case V_905 :
V_38 -> V_730 = 30 ;
break;
case V_979 :
V_38 -> V_730 = 36 ;
break;
default:
break;
}
if ( V_178 & V_911 )
V_38 -> V_910 = true ;
if ( F_11 ( F_104 ( V_65 -> V_94 ) ) & V_146 ) {
struct V_992 * V_993 ;
enum V_1007 V_1008 ;
V_38 -> V_221 = true ;
V_178 = F_11 ( F_72 ( V_65 -> V_94 ) ) ;
V_38 -> V_456 = ( ( V_455 & V_178 ) >>
V_1009 ) + 1 ;
F_679 ( V_65 , V_38 ) ;
if ( F_120 ( V_6 ) ) {
V_1008 = (enum V_1007 ) V_65 -> V_94 ;
} else {
V_178 = F_11 ( V_517 ) ;
if ( V_178 & F_386 ( V_65 -> V_94 ) )
V_1008 = V_518 ;
else
V_1008 = V_1010 ;
}
V_38 -> V_205 =
F_387 ( V_6 , V_1008 ) ;
V_993 = V_38 -> V_205 ;
F_28 ( ! V_993 -> V_1011 . V_720 ( V_6 , V_993 ,
& V_38 -> V_173 ) ) ;
V_178 = V_38 -> V_173 . V_45 ;
V_38 -> V_591 =
( ( V_178 & V_1012 )
>> V_990 ) + 1 ;
F_686 ( V_65 , V_38 ) ;
} else {
V_38 -> V_591 = 1 ;
}
F_638 ( V_65 , V_38 ) ;
F_639 ( V_65 , V_38 ) ;
F_682 ( V_65 , V_38 ) ;
V_360 = true ;
V_937:
F_86 ( V_6 , V_128 ) ;
return V_360 ;
}
static void F_687 ( struct V_5 * V_6 )
{
struct V_62 * V_63 = & V_6 -> V_422 ;
struct V_81 * V_65 ;
F_138 (dev, crtc)
F_65 ( V_65 -> V_87 , L_147 ,
F_78 ( V_65 -> V_94 ) ) ;
F_65 ( F_11 ( V_1013 ) , L_148 ) ;
F_65 ( F_11 ( V_1014 ) & V_1015 , L_149 ) ;
F_65 ( F_11 ( F_688 ( 0 ) ) & V_1016 , L_150 ) ;
F_65 ( F_11 ( F_688 ( 1 ) ) & V_1016 , L_151 ) ;
F_65 ( F_11 ( F_689 ( 0 ) ) & V_1017 , L_152 ) ;
F_65 ( F_11 ( V_1018 ) & V_1019 ,
L_153 ) ;
if ( F_265 ( V_6 ) )
F_65 ( F_11 ( V_1020 ) & V_1019 ,
L_154 ) ;
F_65 ( F_11 ( V_1021 ) & V_1022 ,
L_155 ) ;
F_65 ( F_11 ( V_1023 ) & V_1024 ,
L_156 ) ;
F_65 ( F_11 ( V_1025 ) & V_1026 , L_157 ) ;
F_65 ( F_690 ( V_6 ) , L_158 ) ;
}
static T_2 F_691 ( struct V_5 * V_6 )
{
if ( F_265 ( V_6 ) )
return F_11 ( V_1027 ) ;
else
return F_11 ( V_1028 ) ;
}
static void F_692 ( struct V_5 * V_6 , T_2 V_15 )
{
if ( F_265 ( V_6 ) ) {
F_3 ( & V_6 -> V_551 . V_552 ) ;
if ( F_402 ( V_6 , V_1029 ,
V_15 ) )
F_161 ( L_159 ) ;
F_5 ( & V_6 -> V_551 . V_552 ) ;
} else {
F_124 ( V_1028 , V_15 ) ;
F_125 ( V_1028 ) ;
}
}
static void F_693 ( struct V_5 * V_6 ,
bool V_1030 , bool V_1031 )
{
T_2 V_15 ;
F_687 ( V_6 ) ;
V_15 = F_11 ( V_737 ) ;
if ( V_1030 ) {
V_15 |= V_740 ;
F_124 ( V_737 , V_15 ) ;
if ( F_662 ( F_11 ( V_737 ) &
V_1032 , 1 ) )
F_127 ( L_160 ) ;
V_15 = F_11 ( V_737 ) ;
}
V_15 |= V_1033 ;
F_124 ( V_737 , V_15 ) ;
F_125 ( V_737 ) ;
if ( F_61 ( V_6 , V_737 , V_666 , 0 , 1 ) )
F_127 ( L_161 ) ;
V_15 = F_691 ( V_6 ) ;
V_15 |= V_1034 ;
F_692 ( V_6 , V_15 ) ;
F_694 ( 100 ) ;
if ( F_62 ( ( F_691 ( V_6 ) & V_1035 ) == 0 ,
1 ) )
F_127 ( L_162 ) ;
if ( V_1031 ) {
V_15 = F_11 ( V_737 ) ;
V_15 |= V_1036 ;
F_124 ( V_737 , V_15 ) ;
F_125 ( V_737 ) ;
}
}
static void F_695 ( struct V_5 * V_6 )
{
T_2 V_15 ;
V_15 = F_11 ( V_737 ) ;
if ( ( V_15 & ( V_666 | V_1033 | V_740 |
V_1036 ) ) == V_666 )
return;
F_696 ( V_6 , V_1037 ) ;
if ( V_15 & V_1036 ) {
V_15 &= ~ V_1036 ;
F_124 ( V_737 , V_15 ) ;
F_125 ( V_737 ) ;
}
V_15 = F_691 ( V_6 ) ;
V_15 |= V_1038 ;
V_15 &= ~ V_1034 ;
F_692 ( V_6 , V_15 ) ;
V_15 = F_11 ( V_737 ) ;
V_15 &= ~ V_1033 ;
F_124 ( V_737 , V_15 ) ;
if ( F_61 ( V_6 ,
V_737 , V_666 , V_666 ,
5 ) )
F_127 ( L_163 ) ;
if ( V_15 & V_740 ) {
V_15 = F_11 ( V_737 ) ;
V_15 &= ~ V_740 ;
F_124 ( V_737 , V_15 ) ;
if ( F_662 ( ( F_11 ( V_737 ) &
V_1032 ) == 0 , 1 ) )
F_127 ( L_164 ) ;
}
F_697 ( V_6 , V_1037 ) ;
F_482 ( V_6 ) ;
}
void F_698 ( struct V_5 * V_6 )
{
struct V_62 * V_63 = & V_6 -> V_422 ;
T_2 V_15 ;
F_161 ( L_165 ) ;
if ( F_665 ( V_6 ) ) {
V_15 = F_11 ( V_1039 ) ;
V_15 &= ~ V_1040 ;
F_124 ( V_1039 , V_15 ) ;
}
F_666 ( V_63 ) ;
F_693 ( V_6 , true , true ) ;
}
void F_699 ( struct V_5 * V_6 )
{
struct V_62 * V_63 = & V_6 -> V_422 ;
T_2 V_15 ;
F_161 ( L_166 ) ;
F_695 ( V_6 ) ;
F_669 ( V_63 ) ;
if ( F_665 ( V_6 ) ) {
V_15 = F_11 ( V_1039 ) ;
V_15 |= V_1040 ;
F_124 ( V_1039 , V_15 ) ;
}
}
static void F_700 ( struct V_418 * V_562 )
{
struct V_62 * V_63 = V_562 -> V_63 ;
struct V_570 * V_571 =
F_296 ( V_562 ) ;
unsigned int V_710 = V_571 -> V_702 ;
F_488 ( F_41 ( V_63 ) , V_710 ) ;
}
static int F_701 ( struct V_37 * V_60 ,
int V_1041 )
{
struct V_5 * V_6 = F_41 ( V_60 -> V_64 . V_65 -> V_63 ) ;
if ( F_266 ( V_6 ) && V_60 -> V_550 )
V_1041 = F_221 ( V_1041 * 100 , 95 ) ;
if ( F_389 ( V_60 ) &&
V_60 -> V_1042 &&
V_60 -> V_39 >= 540000 &&
V_60 -> V_1043 == 4 )
V_1041 = V_59 ( 432000 , V_1041 ) ;
return V_1041 ;
}
static int F_519 ( struct V_418 * V_43 )
{
struct V_570 * V_336 = F_296 ( V_43 ) ;
struct V_5 * V_6 = F_41 ( V_43 -> V_63 ) ;
struct V_144 * V_65 ;
struct V_42 * V_1044 ;
struct V_37 * V_60 ;
unsigned V_1045 = 0 , V_135 ;
enum V_94 V_94 ;
memcpy ( V_336 -> V_700 , V_6 -> V_700 ,
sizeof( V_336 -> V_700 ) ) ;
F_295 (state, crtc, cstate, i) {
int V_1041 ;
V_60 = F_291 ( V_1044 ) ;
if ( ! V_60 -> V_64 . V_506 ) {
V_336 -> V_700 [ V_135 ] = 0 ;
continue;
}
V_1041 = F_559 ( V_60 ) ;
if ( F_266 ( V_6 ) || F_702 ( V_6 ) )
V_1041 = F_701 ( V_60 ,
V_1041 ) ;
V_336 -> V_700 [ V_135 ] = V_1041 ;
}
F_91 (dev_priv, pipe)
V_1045 = V_59 ( V_336 -> V_700 [ V_94 ] , V_1045 ) ;
return V_1045 ;
}
static void F_703 ( struct V_62 * V_63 , int V_644 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_2 V_15 , V_1046 ;
int V_360 ;
if ( F_7 ( ( F_11 ( V_737 ) &
( V_1033 | V_666 |
V_1047 | V_1048 |
V_1049 | V_1036 |
V_740 ) ) != V_666 ,
L_167 ) )
return;
F_3 ( & V_6 -> V_551 . V_552 ) ;
V_360 = F_402 ( V_6 ,
V_1050 , 0x0 ) ;
F_5 ( & V_6 -> V_551 . V_552 ) ;
if ( V_360 ) {
F_127 ( L_168 ) ;
return;
}
V_15 = F_11 ( V_737 ) ;
V_15 |= V_740 ;
F_124 ( V_737 , V_15 ) ;
if ( F_662 ( F_11 ( V_737 ) &
V_1032 , 1 ) )
F_127 ( L_160 ) ;
V_15 = F_11 ( V_737 ) ;
V_15 &= ~ V_739 ;
switch ( V_644 ) {
case 450000 :
V_15 |= V_741 ;
V_1046 = 0 ;
break;
case 540000 :
V_15 |= V_742 ;
V_1046 = 1 ;
break;
case 337500 :
V_15 |= V_743 ;
V_1046 = 2 ;
break;
case 675000 :
V_15 |= V_1051 ;
V_1046 = 3 ;
break;
default:
F_7 ( 1 , L_169 ) ;
return;
}
F_124 ( V_737 , V_15 ) ;
V_15 = F_11 ( V_737 ) ;
V_15 &= ~ V_740 ;
F_124 ( V_737 , V_15 ) ;
if ( F_662 ( ( F_11 ( V_737 ) &
V_1032 ) == 0 , 1 ) )
F_127 ( L_164 ) ;
F_3 ( & V_6 -> V_551 . V_552 ) ;
F_402 ( V_6 , V_655 , V_1046 ) ;
F_5 ( & V_6 -> V_551 . V_552 ) ;
F_124 ( V_1052 , F_8 ( V_644 , 1000 ) - 1 ) ;
F_482 ( V_6 ) ;
F_7 ( V_644 != V_6 -> V_638 ,
L_170 ,
V_644 , V_6 -> V_638 ) ;
}
static int F_704 ( int V_663 )
{
if ( V_663 > 540000 )
return 675000 ;
else if ( V_663 > 450000 )
return 540000 ;
else if ( V_663 > 337500 )
return 450000 ;
else
return 337500 ;
}
static int F_705 ( struct V_418 * V_43 )
{
struct V_5 * V_6 = F_41 ( V_43 -> V_63 ) ;
struct V_570 * V_336 = F_296 ( V_43 ) ;
int V_663 = F_519 ( V_43 ) ;
int V_644 ;
V_644 = F_704 ( V_663 ) ;
if ( V_644 > V_6 -> V_628 ) {
F_161 ( L_171 ,
V_644 , V_6 -> V_628 ) ;
return - V_286 ;
}
V_336 -> V_644 = V_336 -> V_702 = V_644 ;
if ( ! V_336 -> V_703 )
V_336 -> V_702 = F_704 ( 0 ) ;
return 0 ;
}
static void F_706 ( struct V_418 * V_562 )
{
struct V_62 * V_63 = V_562 -> V_63 ;
struct V_570 * V_571 =
F_296 ( V_562 ) ;
unsigned V_710 = V_571 -> V_702 ;
F_703 ( V_63 , V_710 ) ;
}
static int F_707 ( struct V_418 * V_43 )
{
struct V_570 * V_336 = F_296 ( V_43 ) ;
struct V_5 * V_6 = F_41 ( V_43 -> V_63 ) ;
const int V_663 = F_519 ( V_43 ) ;
int V_52 = V_336 -> V_1053 ;
int V_644 ;
V_644 = F_479 ( V_663 , V_52 ) ;
if ( V_644 > V_6 -> V_628 ) {
F_127 ( L_171 ,
V_644 , V_6 -> V_628 ) ;
V_644 = V_6 -> V_628 ;
}
V_336 -> V_644 = V_336 -> V_702 = V_644 ;
if ( ! V_336 -> V_703 )
V_336 -> V_702 = F_479 ( 0 , V_52 ) ;
return 0 ;
}
static void F_708 ( struct V_418 * V_562 )
{
struct V_5 * V_6 = F_41 ( V_562 -> V_63 ) ;
struct V_570 * V_336 = F_296 ( V_562 ) ;
unsigned int V_710 = V_336 -> V_702 ;
unsigned int V_1054 = V_336 -> V_1053 ;
F_502 ( V_6 , V_710 , V_1054 ) ;
}
static int F_709 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
if ( ! F_38 ( V_60 , V_222 ) ) {
if ( ! F_710 ( V_65 , V_60 ) )
return - V_286 ;
}
V_65 -> V_809 = false ;
return 0 ;
}
static void F_711 ( struct V_5 * V_6 ,
enum V_177 V_177 ,
struct V_37 * V_38 )
{
enum V_1007 V_377 ;
switch ( V_177 ) {
case V_602 :
V_377 = V_1055 ;
break;
case V_197 :
V_377 = V_1056 ;
break;
case V_199 :
V_377 = V_1057 ;
break;
default:
F_127 ( L_172 ) ;
return;
}
V_38 -> V_205 = F_387 ( V_6 , V_377 ) ;
}
static void F_712 ( struct V_5 * V_6 ,
enum V_177 V_177 ,
struct V_37 * V_38 )
{
enum V_1007 V_377 ;
T_1 V_443 ;
V_443 = F_11 ( V_1058 ) & F_713 ( V_177 ) ;
V_377 = V_443 >> ( V_177 * 3 + 1 ) ;
if ( F_28 ( V_377 < V_668 || V_377 > V_1059 ) )
return;
V_38 -> V_205 = F_387 ( V_6 , V_377 ) ;
}
static void F_714 ( struct V_5 * V_6 ,
enum V_177 V_177 ,
struct V_37 * V_38 )
{
enum V_1007 V_377 ;
T_2 V_1060 = F_11 ( F_715 ( V_177 ) ) ;
switch ( V_1060 ) {
case V_1061 :
V_377 = V_1062 ;
break;
case V_1063 :
V_377 = V_1064 ;
break;
case V_1065 :
V_377 = V_1066 ;
break;
case V_1067 :
V_377 = V_1068 ;
break;
case V_1069 :
V_377 = V_1070 ;
break;
case V_1071 :
V_377 = V_1072 ;
break;
default:
F_172 ( V_1060 ) ;
case V_1073 :
return;
}
V_38 -> V_205 = F_387 ( V_6 , V_377 ) ;
}
static bool F_716 ( struct V_81 * V_65 ,
struct V_37 * V_38 ,
unsigned long * V_1074 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_127 V_128 ;
T_1 V_178 ;
V_38 -> V_95 = (enum V_93 ) V_65 -> V_94 ;
V_178 = F_11 ( F_69 ( V_590 ) ) ;
if ( V_178 & V_106 ) {
enum V_94 V_1075 ;
switch ( V_178 & V_1076 ) {
default:
F_7 ( 1 , L_173 ) ;
case V_1077 :
case V_1078 :
V_1075 = V_113 ;
break;
case V_1079 :
V_1075 = V_120 ;
break;
case V_1080 :
V_1075 = V_509 ;
break;
}
if ( V_1075 == V_65 -> V_94 )
V_38 -> V_95 = V_590 ;
}
V_128 = F_84 ( V_38 -> V_95 ) ;
if ( ! F_85 ( V_6 , V_128 ) )
return false ;
* V_1074 |= F_467 ( V_128 ) ;
V_178 = F_11 ( F_60 ( V_38 -> V_95 ) ) ;
return V_178 & V_132 ;
}
static bool F_717 ( struct V_81 * V_65 ,
struct V_37 * V_38 ,
unsigned long * V_1074 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_127 V_128 ;
enum V_177 V_177 ;
enum V_93 V_95 ;
T_1 V_178 ;
F_718 (port, BIT(PORT_A) | BIT(PORT_C)) {
if ( V_177 == V_602 )
V_95 = V_1081 ;
else
V_95 = V_1082 ;
V_128 = F_84 ( V_95 ) ;
if ( ! F_85 ( V_6 , V_128 ) )
continue;
* V_1074 |= F_467 ( V_128 ) ;
if ( ! F_719 ( V_6 ) )
break;
V_178 = F_11 ( F_720 ( V_177 ) ) ;
if ( ! ( V_178 & V_1083 ) )
continue;
V_178 = F_11 ( F_721 ( V_177 ) ) ;
if ( ( V_178 & V_1084 ) != F_722 ( V_65 -> V_94 ) )
continue;
V_38 -> V_95 = V_95 ;
break;
}
return F_445 ( V_38 -> V_95 ) ;
}
static void F_723 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
struct V_992 * V_993 ;
enum V_177 V_177 ;
T_2 V_178 ;
V_178 = F_11 ( F_69 ( V_38 -> V_95 ) ) ;
V_177 = ( V_178 & V_1085 ) >> V_1086 ;
if ( F_477 ( V_6 ) || F_478 ( V_6 ) )
F_712 ( V_6 , V_177 , V_38 ) ;
else if ( F_36 ( V_6 ) )
F_711 ( V_6 , V_177 , V_38 ) ;
else
F_714 ( V_6 , V_177 , V_38 ) ;
V_993 = V_38 -> V_205 ;
if ( V_993 ) {
F_28 ( ! V_993 -> V_1011 . V_720 ( V_6 , V_993 ,
& V_38 -> V_173 ) ) ;
}
if ( F_59 ( V_6 ) < 9 &&
( V_177 == V_607 ) && F_11 ( V_220 ) & V_146 ) {
V_38 -> V_221 = true ;
V_178 = F_11 ( F_72 ( V_113 ) ) ;
V_38 -> V_456 = ( ( V_455 & V_178 ) >>
V_1009 ) + 1 ;
F_679 ( V_65 , V_38 ) ;
}
}
static bool F_724 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
enum V_127 V_128 ;
unsigned long V_1074 ;
bool V_87 ;
V_128 = F_468 ( V_65 -> V_94 ) ;
if ( ! F_85 ( V_6 , V_128 ) )
return false ;
V_1074 = F_467 ( V_128 ) ;
V_38 -> V_205 = NULL ;
V_87 = F_716 ( V_65 , V_38 , & V_1074 ) ;
if ( F_36 ( V_6 ) &&
F_717 ( V_65 , V_38 , & V_1074 ) ) {
F_28 ( V_87 ) ;
V_87 = true ;
}
if ( ! V_87 )
goto V_937;
if ( ! F_445 ( V_38 -> V_95 ) ) {
F_723 ( V_65 , V_38 ) ;
F_638 ( V_65 , V_38 ) ;
}
F_639 ( V_65 , V_38 ) ;
V_38 -> V_1087 =
F_11 ( F_725 ( V_65 -> V_94 ) ) & V_1088 ;
if ( F_59 ( V_6 ) >= 9 ) {
F_726 ( V_6 , V_65 , V_38 ) ;
V_38 -> V_379 . V_404 = - 1 ;
V_38 -> V_379 . V_532 &= ~ ( 1 << V_541 ) ;
}
V_128 = F_469 ( V_65 -> V_94 ) ;
if ( F_85 ( V_6 , V_128 ) ) {
V_1074 |= F_467 ( V_128 ) ;
if ( F_59 ( V_6 ) >= 9 )
F_680 ( V_65 , V_38 ) ;
else
F_682 ( V_65 , V_38 ) ;
}
if ( F_265 ( V_6 ) )
V_38 -> V_550 = F_442 ( V_65 ) &&
( F_11 ( V_554 ) & V_555 ) ;
if ( V_38 -> V_95 != V_590 &&
! F_445 ( V_38 -> V_95 ) ) {
V_38 -> V_591 =
F_11 ( F_446 ( V_38 -> V_95 ) ) + 1 ;
} else {
V_38 -> V_591 = 1 ;
}
V_937:
F_472 (power_domain, power_domain_mask)
F_86 ( V_6 , V_128 ) ;
return V_87 ;
}
static void F_727 ( struct V_144 * V_65 , T_1 V_64 ,
const struct V_263 * V_334 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
T_2 V_1089 = 0 , V_240 = 0 ;
if ( V_334 && V_334 -> V_64 . V_338 ) {
unsigned int V_241 = V_334 -> V_64 . V_347 ;
unsigned int V_236 = V_334 -> V_64 . V_348 ;
unsigned int V_290 = F_728 ( V_241 ) * 4 ;
switch ( V_290 ) {
default:
F_352 ( 1 , L_174 ,
V_241 , V_290 ) ;
V_290 = 256 ;
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
}
V_1089 |= V_125 |
V_1090 |
V_1091 |
F_729 ( V_290 ) ;
V_240 = ( V_236 << 12 ) | V_241 ;
}
if ( V_81 -> V_1092 != 0 &&
( V_81 -> V_1093 != V_64 ||
V_81 -> V_1094 != V_240 ||
V_81 -> V_1092 != V_1089 ) ) {
F_124 ( F_82 ( V_113 ) , 0 ) ;
F_125 ( F_82 ( V_113 ) ) ;
V_81 -> V_1092 = 0 ;
}
if ( V_81 -> V_1093 != V_64 ) {
F_124 ( F_730 ( V_113 ) , V_64 ) ;
V_81 -> V_1093 = V_64 ;
}
if ( V_81 -> V_1094 != V_240 ) {
F_124 ( V_1095 , V_240 ) ;
V_81 -> V_1094 = V_240 ;
}
if ( V_81 -> V_1092 != V_1089 ) {
F_124 ( F_82 ( V_113 ) , V_1089 ) ;
F_125 ( F_82 ( V_113 ) ) ;
V_81 -> V_1092 = V_1089 ;
}
}
static void F_731 ( struct V_144 * V_65 , T_1 V_64 ,
const struct V_263 * V_334 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_2 V_1089 = 0 ;
if ( V_334 && V_334 -> V_64 . V_338 ) {
V_1089 = V_1096 ;
switch ( V_334 -> V_64 . V_347 ) {
case 64 :
V_1089 |= V_1097 ;
break;
case 128 :
V_1089 |= V_1098 ;
break;
case 256 :
V_1089 |= V_1099 ;
break;
default:
F_172 ( V_334 -> V_64 . V_347 ) ;
return;
}
V_1089 |= V_94 << 28 ;
if ( F_23 ( V_6 ) )
V_1089 |= V_1100 ;
if ( V_334 -> V_64 . V_245 & V_368 )
V_1089 |= V_1101 ;
}
if ( V_81 -> V_1092 != V_1089 ) {
F_124 ( F_82 ( V_94 ) , V_1089 ) ;
F_125 ( F_82 ( V_94 ) ) ;
V_81 -> V_1092 = V_1089 ;
}
F_124 ( F_730 ( V_94 ) , V_64 ) ;
F_125 ( F_730 ( V_94 ) ) ;
V_81 -> V_1093 = V_64 ;
}
static void F_732 ( struct V_144 * V_65 ,
const struct V_263 * V_334 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_1 V_64 = V_81 -> V_1102 ;
T_1 V_547 = 0 ;
if ( V_334 ) {
int V_261 = V_334 -> V_64 . V_345 ;
int V_262 = V_334 -> V_64 . V_346 ;
if ( V_261 < 0 ) {
V_547 |= V_1103 << V_1104 ;
V_261 = - V_261 ;
}
V_547 |= V_261 << V_1104 ;
if ( V_262 < 0 ) {
V_547 |= V_1103 << V_1105 ;
V_262 = - V_262 ;
}
V_547 |= V_262 << V_1105 ;
if ( F_163 ( V_6 ) &&
V_334 -> V_64 . V_245 & V_368 ) {
V_64 += ( V_334 -> V_64 . V_348 *
V_334 -> V_64 . V_347 - 1 ) * 4 ;
}
}
F_124 ( F_733 ( V_94 ) , V_547 ) ;
if ( F_80 ( V_6 ) || F_81 ( V_6 ) )
F_727 ( V_65 , V_64 , V_334 ) ;
else
F_731 ( V_65 , V_64 , V_334 ) ;
}
static bool F_734 ( struct V_5 * V_6 ,
T_2 V_241 , T_2 V_236 )
{
if ( V_241 == 0 || V_236 == 0 )
return false ;
if ( F_80 ( V_6 ) || F_81 ( V_6 ) ) {
if ( ( V_241 & 63 ) != 0 )
return false ;
if ( V_241 > ( F_80 ( V_6 ) ? 64 : 512 ) )
return false ;
if ( V_236 > 1023 )
return false ;
} else {
switch ( V_241 | V_236 ) {
case 256 :
case 128 :
if ( F_56 ( V_6 ) )
return false ;
case 64 :
break;
default:
return false ;
}
}
return true ;
}
struct V_244 *
F_735 ( struct V_62 * V_63 ,
struct V_320 * V_321 ,
struct V_252 * V_253 )
{
struct V_264 * V_265 ;
int V_360 ;
V_265 = F_551 ( sizeof( * V_265 ) , V_722 ) ;
if ( ! V_265 )
return F_736 ( - V_721 ) ;
V_360 = F_229 ( V_63 , V_265 , V_321 , V_253 ) ;
if ( V_360 )
goto V_72;
return & V_265 -> V_64 ;
V_72:
F_237 ( V_265 ) ;
return F_736 ( V_360 ) ;
}
static struct V_244 *
F_737 ( struct V_62 * V_63 ,
struct V_320 * V_321 ,
struct V_252 * V_253 )
{
struct V_244 * V_89 ;
int V_360 ;
V_360 = F_738 ( V_63 ) ;
if ( V_360 )
return F_736 ( V_360 ) ;
V_89 = F_735 ( V_63 , V_321 , V_253 ) ;
F_5 ( & V_63 -> V_256 ) ;
return V_89 ;
}
static T_1
F_739 ( int V_241 , int V_986 )
{
T_1 V_259 = F_221 ( V_241 * V_986 , 8 ) ;
return F_177 ( V_259 , 64 ) ;
}
static T_1
F_740 ( struct V_519 * V_414 , int V_986 )
{
T_1 V_259 = F_739 ( V_414 -> V_890 , V_986 ) ;
return F_741 ( V_259 * V_414 -> V_889 ) ;
}
static struct V_244 *
F_742 ( struct V_62 * V_63 ,
struct V_519 * V_414 ,
int V_1106 , int V_986 )
{
struct V_244 * V_89 ;
struct V_252 * V_253 ;
struct V_320 V_321 = { 0 } ;
V_253 = F_743 ( V_63 ,
F_740 ( V_414 , V_986 ) ) ;
if ( F_194 ( V_253 ) )
return F_744 ( V_253 ) ;
V_321 . V_241 = V_414 -> V_890 ;
V_321 . V_236 = V_414 -> V_889 ;
V_321 . V_260 [ 0 ] = F_739 ( V_321 . V_241 ,
V_986 ) ;
V_321 . V_237 = F_745 ( V_986 , V_1106 ) ;
V_89 = F_737 ( V_63 , & V_321 , V_253 ) ;
if ( F_194 ( V_89 ) )
F_230 ( V_253 ) ;
return V_89 ;
}
static struct V_244 *
F_746 ( struct V_62 * V_63 ,
struct V_519 * V_414 )
{
#ifdef F_747
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_252 * V_253 ;
struct V_244 * V_89 ;
if ( ! V_6 -> V_1107 )
return NULL ;
if ( ! V_6 -> V_1107 -> V_89 )
return NULL ;
V_253 = V_6 -> V_1107 -> V_89 -> V_253 ;
F_660 ( ! V_253 ) ;
V_89 = & V_6 -> V_1107 -> V_89 -> V_64 ;
if ( V_89 -> V_260 [ 0 ] < F_739 ( V_414 -> V_890 ,
V_89 -> V_791 ) )
return NULL ;
if ( V_253 -> V_64 . V_240 < V_414 -> V_889 * V_89 -> V_260 [ 0 ] )
return NULL ;
F_233 ( V_89 ) ;
return V_89 ;
#else
return NULL ;
#endif
}
static int F_748 ( struct V_418 * V_43 ,
struct V_144 * V_65 ,
struct V_519 * V_414 ,
struct V_244 * V_89 ,
int V_261 , int V_262 )
{
struct V_333 * V_334 ;
int V_890 , V_889 ;
int V_360 ;
V_334 = F_749 ( V_43 , V_65 -> V_88 ) ;
if ( F_194 ( V_334 ) )
return F_242 ( V_334 ) ;
if ( V_414 )
F_750 ( V_414 , & V_890 , & V_889 ) ;
else
V_890 = V_889 = 0 ;
V_360 = F_751 ( V_334 , V_89 ? V_65 : NULL ) ;
if ( V_360 )
return V_360 ;
F_752 ( V_334 , V_89 ) ;
V_334 -> V_345 = 0 ;
V_334 -> V_346 = 0 ;
V_334 -> V_347 = V_890 ;
V_334 -> V_348 = V_889 ;
V_334 -> V_341 = V_261 << 16 ;
V_334 -> V_342 = V_262 << 16 ;
V_334 -> V_343 = V_890 << 16 ;
V_334 -> V_344 = V_889 << 16 ;
return 0 ;
}
bool F_753 ( struct V_578 * V_719 ,
struct V_519 * V_414 ,
struct V_1108 * V_1109 ,
struct V_423 * V_424 )
{
struct V_81 * V_81 ;
struct V_510 * V_510 =
F_754 ( V_719 ) ;
struct V_144 * V_1110 ;
struct V_619 * V_511 = & V_510 -> V_64 ;
struct V_144 * V_65 = NULL ;
struct V_62 * V_63 = V_511 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_244 * V_89 ;
struct V_1111 * V_90 = & V_63 -> V_426 ;
struct V_418 * V_43 = NULL , * V_1112 = NULL ;
struct V_576 * V_1113 ;
struct V_37 * V_60 ;
int V_360 , V_135 = - 1 ;
F_161 ( L_175 ,
V_719 -> V_64 . V_377 , V_719 -> V_12 ,
V_511 -> V_64 . V_377 , V_511 -> V_12 ) ;
V_1109 -> V_1112 = NULL ;
V_461:
V_360 = F_755 ( & V_90 -> V_1114 , V_424 ) ;
if ( V_360 )
goto V_784;
if ( V_719 -> V_43 -> V_65 ) {
V_65 = V_719 -> V_43 -> V_65 ;
V_360 = F_755 ( & V_65 -> V_427 , V_424 ) ;
if ( V_360 )
goto V_784;
goto V_75;
}
F_238 (dev, possible_crtc) {
V_135 ++ ;
if ( ! ( V_511 -> V_1115 & ( 1 << V_135 ) ) )
continue;
V_360 = F_755 ( & V_1110 -> V_427 , V_424 ) ;
if ( V_360 )
goto V_784;
if ( V_1110 -> V_43 -> V_506 ) {
F_756 ( & V_1110 -> V_427 ) ;
continue;
}
V_65 = V_1110 ;
break;
}
if ( ! V_65 ) {
F_161 ( L_176 ) ;
goto V_784;
}
V_75:
V_81 = F_48 ( V_65 ) ;
V_360 = F_755 ( & V_65 -> V_88 -> V_427 , V_424 ) ;
if ( V_360 )
goto V_784;
V_43 = F_536 ( V_63 ) ;
V_1112 = F_536 ( V_63 ) ;
if ( ! V_43 || ! V_1112 ) {
V_360 = - V_721 ;
goto V_784;
}
V_43 -> V_431 = V_424 ;
V_1112 -> V_431 = V_424 ;
V_1113 = F_757 ( V_43 , V_719 ) ;
if ( F_194 ( V_1113 ) ) {
V_360 = F_242 ( V_1113 ) ;
goto V_784;
}
V_360 = F_758 ( V_1113 , V_65 ) ;
if ( V_360 )
goto V_784;
V_60 = F_537 ( V_43 , V_81 ) ;
if ( F_194 ( V_60 ) ) {
V_360 = F_242 ( V_60 ) ;
goto V_784;
}
V_60 -> V_64 . V_87 = V_60 -> V_64 . V_506 = true ;
if ( ! V_414 )
V_414 = & V_1116 ;
V_89 = F_746 ( V_63 , V_414 ) ;
if ( V_89 == NULL ) {
F_161 ( L_177 ) ;
V_89 = F_742 ( V_63 , V_414 , 24 , 32 ) ;
} else
F_161 ( L_178 ) ;
if ( F_194 ( V_89 ) ) {
F_161 ( L_179 ) ;
goto V_784;
}
V_360 = F_748 ( V_43 , V_65 , V_414 , V_89 , 0 , 0 ) ;
if ( V_360 )
goto V_784;
F_232 ( V_89 ) ;
V_360 = F_539 ( & V_60 -> V_64 , V_414 ) ;
if ( V_360 )
goto V_784;
V_360 = F_544 ( F_757 ( V_1112 , V_719 ) ) ;
if ( ! V_360 )
V_360 = F_544 ( F_759 ( V_1112 , V_65 ) ) ;
if ( ! V_360 )
V_360 = F_544 ( F_749 ( V_1112 , V_65 -> V_88 ) ) ;
if ( V_360 ) {
F_161 ( L_180 , V_360 ) ;
goto V_784;
}
V_360 = F_297 ( V_43 ) ;
if ( V_360 ) {
F_161 ( L_181 ) ;
goto V_784;
}
V_1109 -> V_1112 = V_1112 ;
F_306 ( V_43 ) ;
F_343 ( V_6 , V_81 -> V_94 ) ;
return true ;
V_784:
if ( V_43 ) {
F_306 ( V_43 ) ;
V_43 = NULL ;
}
if ( V_1112 ) {
F_306 ( V_1112 ) ;
V_1112 = NULL ;
}
if ( V_360 == - V_421 ) {
F_303 ( V_424 ) ;
goto V_461;
}
return false ;
}
void F_760 ( struct V_578 * V_719 ,
struct V_1108 * V_1109 ,
struct V_423 * V_424 )
{
struct V_510 * V_510 =
F_754 ( V_719 ) ;
struct V_619 * V_511 = & V_510 -> V_64 ;
struct V_418 * V_43 = V_1109 -> V_1112 ;
int V_360 ;
F_161 ( L_175 ,
V_719 -> V_64 . V_377 , V_719 -> V_12 ,
V_511 -> V_64 . V_377 , V_511 -> V_12 ) ;
if ( ! V_43 )
return;
V_360 = F_297 ( V_43 ) ;
if ( V_360 )
F_161 ( L_182 , V_360 ) ;
F_306 ( V_43 ) ;
}
static int F_761 ( struct V_62 * V_63 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_45 = V_38 -> V_173 . V_45 ;
if ( ( V_45 & V_949 ) == V_874 )
return V_6 -> V_803 . V_912 ;
else if ( F_15 ( V_6 ) )
return 120000 ;
else if ( ! F_56 ( V_6 ) )
return 96000 ;
else
return 48000 ;
}
static void F_656 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_38 -> V_95 ;
T_1 V_45 = V_38 -> V_173 . V_45 ;
T_1 V_807 ;
struct V_45 clock ;
int V_39 ;
int V_44 = F_761 ( V_63 , V_38 ) ;
if ( ( V_45 & V_1117 ) == 0 )
V_807 = V_38 -> V_173 . V_713 ;
else
V_807 = V_38 -> V_173 . V_714 ;
clock . V_54 = ( V_807 & V_1118 ) >> V_1119 ;
if ( F_19 ( V_6 ) ) {
clock . V_51 = F_762 ( ( V_807 & V_1120 ) >> V_1121 ) - 1 ;
clock . V_47 = ( V_807 & V_1122 ) >> V_1123 ;
} else {
clock . V_51 = ( V_807 & V_1124 ) >> V_1121 ;
clock . V_47 = ( V_807 & V_1125 ) >> V_1123 ;
}
if ( ! F_56 ( V_6 ) ) {
if ( F_19 ( V_6 ) )
clock . V_49 = F_762 ( ( V_45 & V_1126 ) >>
V_864 ) ;
else
clock . V_49 = F_762 ( ( V_45 & V_1127 ) >>
V_865 ) ;
switch ( V_45 & V_1128 ) {
case V_861 :
clock . V_50 = V_45 & V_867 ?
5 : 10 ;
break;
case V_860 :
clock . V_50 = V_45 & V_868 ?
7 : 14 ;
break;
default:
F_161 ( L_183
L_184 , ( int ) ( V_45 & V_1128 ) ) ;
return;
}
if ( F_19 ( V_6 ) )
V_39 = F_27 ( V_44 , & clock ) ;
else
V_39 = F_30 ( V_44 , & clock ) ;
} else {
T_1 V_1129 = F_141 ( V_6 ) ? 0 : F_11 ( V_121 ) ;
bool V_1130 = ( V_94 == 1 ) && ( V_1129 & V_156 ) ;
if ( V_1130 ) {
clock . V_49 = F_762 ( ( V_45 & V_1131 ) >>
V_865 ) ;
if ( V_1129 & V_1132 )
clock . V_50 = 7 ;
else
clock . V_50 = 14 ;
} else {
if ( V_45 & V_876 )
clock . V_49 = 2 ;
else {
clock . V_49 = ( ( V_45 & V_1133 ) >>
V_865 ) + 2 ;
}
if ( V_45 & V_877 )
clock . V_50 = 4 ;
else
clock . V_50 = 2 ;
}
V_39 = F_30 ( V_44 , & clock ) ;
}
V_38 -> V_39 = V_39 ;
}
int F_763 ( int V_1134 ,
const struct V_795 * V_796 )
{
if ( ! V_796 -> V_801 )
return 0 ;
return F_46 ( ( V_1135 ) V_796 -> V_800 * V_1134 , V_796 -> V_801 ) ;
}
static void F_686 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
F_656 ( V_65 , V_38 ) ;
V_38 -> V_64 . V_91 . V_92 =
F_763 ( F_22 ( V_6 , V_38 ) ,
& V_38 -> V_588 ) ;
}
struct V_519 * F_764 ( struct V_62 * V_63 ,
struct V_144 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
enum V_93 V_95 = V_81 -> V_90 -> V_95 ;
struct V_519 * V_414 ;
struct V_37 * V_38 ;
int V_1136 = F_11 ( F_364 ( V_95 ) ) ;
int V_898 = F_11 ( F_368 ( V_95 ) ) ;
int V_1137 = F_11 ( F_370 ( V_95 ) ) ;
int V_1138 = F_11 ( F_374 ( V_95 ) ) ;
enum V_94 V_94 = V_81 -> V_94 ;
V_414 = F_551 ( sizeof( * V_414 ) , V_722 ) ;
if ( ! V_414 )
return NULL ;
V_38 = F_551 ( sizeof( * V_38 ) , V_722 ) ;
if ( ! V_38 ) {
F_237 ( V_414 ) ;
return NULL ;
}
V_38 -> V_95 = (enum V_93 ) V_94 ;
V_38 -> V_591 = 1 ;
V_38 -> V_173 . V_45 = F_11 ( F_64 ( V_94 ) ) ;
V_38 -> V_173 . V_713 = F_11 ( F_530 ( V_94 ) ) ;
V_38 -> V_173 . V_714 = F_11 ( F_531 ( V_94 ) ) ;
F_656 ( V_81 , V_38 ) ;
V_414 -> clock = V_38 -> V_39 / V_38 -> V_591 ;
V_414 -> V_890 = ( V_1136 & 0xffff ) + 1 ;
V_414 -> V_891 = ( ( V_1136 & 0xffff0000 ) >> 16 ) + 1 ;
V_414 -> V_892 = ( V_898 & 0xffff ) + 1 ;
V_414 -> V_893 = ( ( V_898 & 0xffff0000 ) >> 16 ) + 1 ;
V_414 -> V_889 = ( V_1137 & 0xffff ) + 1 ;
V_414 -> V_894 = ( ( V_1137 & 0xffff0000 ) >> 16 ) + 1 ;
V_414 -> V_895 = ( V_1138 & 0xffff ) + 1 ;
V_414 -> V_896 = ( ( V_1138 & 0xffff0000 ) >> 16 ) + 1 ;
F_643 ( V_414 ) ;
F_237 ( V_38 ) ;
return V_414 ;
}
static void F_765 ( struct V_144 * V_65 )
{
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_1 * V_2 ;
F_312 ( & V_63 -> V_439 ) ;
V_2 = V_81 -> V_440 ;
V_81 -> V_440 = NULL ;
F_313 ( & V_63 -> V_439 ) ;
if ( V_2 ) {
F_766 ( & V_2 -> V_3 ) ;
F_766 ( & V_2 -> V_481 ) ;
F_237 ( V_2 ) ;
}
F_767 ( V_65 ) ;
F_237 ( V_81 ) ;
}
static void F_768 ( struct V_1139 * V_1140 )
{
struct V_1 * V_2 =
F_769 ( V_1140 , struct V_1 , V_481 ) ;
struct V_81 * V_65 = F_48 ( V_2 -> V_65 ) ;
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_331 * V_88 = V_65 -> V_64 . V_88 ;
if ( F_1 ( V_2 ) )
F_770 ( & V_2 -> V_3 ) ;
F_3 ( & V_63 -> V_256 ) ;
F_200 ( V_2 -> V_1141 ) ;
F_230 ( V_2 -> V_479 ) ;
F_5 ( & V_63 -> V_256 ) ;
F_771 ( V_2 -> V_1142 ) ;
F_772 ( F_41 ( V_63 ) ,
F_235 ( V_88 ) -> V_352 ) ;
F_416 ( V_65 ) ;
F_232 ( V_2 -> V_1143 ) ;
F_660 ( F_342 ( & V_65 -> V_476 ) == 0 ) ;
F_773 ( & V_65 -> V_476 ) ;
F_237 ( V_2 ) ;
}
static bool F_774 ( T_1 V_1144 , T_1 V_1145 )
{
return ! ( ( V_1144 - V_1145 ) & 0x80000000 ) ;
}
static bool F_775 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
if ( F_317 ( V_65 ) )
return true ;
if ( F_59 ( V_6 ) < 5 && ! F_18 ( V_6 ) )
return true ;
return ( F_11 ( F_776 ( V_65 -> V_133 ) ) & ~ 0xfff ) ==
V_65 -> V_440 -> V_1146 &&
F_774 ( F_11 ( F_777 ( V_65 -> V_94 ) ) ,
V_65 -> V_440 -> V_1147 ) ;
}
static bool
F_778 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
return F_779 ( V_65 ) != V_2 -> V_1148 ;
}
static bool F_780 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
if ( ! F_342 ( & V_2 -> V_438 ) )
return false ;
F_781 () ;
if ( F_1 ( V_2 ) )
return F_778 ( V_65 , V_2 ) ;
else
return F_775 ( V_65 , V_2 ) ;
}
void F_289 ( struct V_5 * V_6 , int V_94 )
{
struct V_62 * V_63 = & V_6 -> V_422 ;
struct V_81 * V_65 = F_53 ( V_6 , V_94 ) ;
struct V_1 * V_2 ;
unsigned long V_328 ;
if ( ! V_65 )
return;
F_782 ( & V_63 -> V_439 , V_328 ) ;
V_2 = V_65 -> V_440 ;
if ( V_2 != NULL &&
! F_1 ( V_2 ) &&
F_780 ( V_65 , V_2 ) )
F_344 ( V_65 ) ;
F_783 ( & V_63 -> V_439 , V_328 ) ;
}
void F_784 ( struct V_5 * V_6 , int V_94 )
{
struct V_62 * V_63 = & V_6 -> V_422 ;
struct V_81 * V_65 = F_53 ( V_6 , V_94 ) ;
struct V_1 * V_2 ;
unsigned long V_328 ;
if ( ! V_65 )
return;
F_782 ( & V_63 -> V_439 , V_328 ) ;
V_2 = V_65 -> V_440 ;
if ( V_2 != NULL &&
F_1 ( V_2 ) &&
F_780 ( V_65 , V_2 ) )
F_344 ( V_65 ) ;
F_783 ( & V_63 -> V_439 , V_328 ) ;
}
static inline void F_785 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
V_2 -> V_1148 = F_779 ( V_65 ) ;
F_786 () ;
F_787 ( & V_2 -> V_438 , 1 ) ;
}
static int F_788 ( struct V_62 * V_63 ,
struct V_144 * V_65 ,
struct V_244 * V_89 ,
struct V_252 * V_253 ,
struct V_1149 * V_1150 ,
T_2 V_328 )
{
struct V_1151 * V_1152 = V_1150 -> V_1152 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
T_1 V_1153 ;
int V_360 ;
V_360 = F_789 ( V_1150 , 6 ) ;
if ( V_360 )
return V_360 ;
if ( V_81 -> V_133 )
V_1153 = V_1154 ;
else
V_1153 = V_1155 ;
F_790 ( V_1152 , V_1156 | V_1153 ) ;
F_790 ( V_1152 , V_1157 ) ;
F_790 ( V_1152 , V_1158 |
F_791 ( V_81 -> V_133 ) ) ;
F_790 ( V_1152 , V_89 -> V_260 [ 0 ] ) ;
F_790 ( V_1152 , V_81 -> V_440 -> V_1146 ) ;
F_790 ( V_1152 , 0 ) ;
return 0 ;
}
static int F_792 ( struct V_62 * V_63 ,
struct V_144 * V_65 ,
struct V_244 * V_89 ,
struct V_252 * V_253 ,
struct V_1149 * V_1150 ,
T_2 V_328 )
{
struct V_1151 * V_1152 = V_1150 -> V_1152 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
T_1 V_1153 ;
int V_360 ;
V_360 = F_789 ( V_1150 , 6 ) ;
if ( V_360 )
return V_360 ;
if ( V_81 -> V_133 )
V_1153 = V_1154 ;
else
V_1153 = V_1155 ;
F_790 ( V_1152 , V_1156 | V_1153 ) ;
F_790 ( V_1152 , V_1157 ) ;
F_790 ( V_1152 , V_1159 |
F_791 ( V_81 -> V_133 ) ) ;
F_790 ( V_1152 , V_89 -> V_260 [ 0 ] ) ;
F_790 ( V_1152 , V_81 -> V_440 -> V_1146 ) ;
F_790 ( V_1152 , V_1157 ) ;
return 0 ;
}
static int F_793 ( struct V_62 * V_63 ,
struct V_144 * V_65 ,
struct V_244 * V_89 ,
struct V_252 * V_253 ,
struct V_1149 * V_1150 ,
T_2 V_328 )
{
struct V_1151 * V_1152 = V_1150 -> V_1152 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
T_2 V_1160 , V_1161 ;
int V_360 ;
V_360 = F_789 ( V_1150 , 4 ) ;
if ( V_360 )
return V_360 ;
F_790 ( V_1152 , V_1158 |
F_791 ( V_81 -> V_133 ) ) ;
F_790 ( V_1152 , V_89 -> V_260 [ 0 ] ) ;
F_790 ( V_1152 , V_81 -> V_440 -> V_1146 |
F_214 ( V_89 -> V_257 ) ) ;
V_1160 = 0 ;
V_1161 = F_11 ( F_322 ( V_81 -> V_94 ) ) & 0x0fff0fff ;
F_790 ( V_1152 , V_1160 | V_1161 ) ;
return 0 ;
}
static int F_794 ( struct V_62 * V_63 ,
struct V_144 * V_65 ,
struct V_244 * V_89 ,
struct V_252 * V_253 ,
struct V_1149 * V_1150 ,
T_2 V_328 )
{
struct V_1151 * V_1152 = V_1150 -> V_1152 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
T_2 V_1160 , V_1161 ;
int V_360 ;
V_360 = F_789 ( V_1150 , 4 ) ;
if ( V_360 )
return V_360 ;
F_790 ( V_1152 , V_1158 |
F_791 ( V_81 -> V_133 ) ) ;
F_790 ( V_1152 , V_89 -> V_260 [ 0 ] |
F_214 ( V_89 -> V_257 ) ) ;
F_790 ( V_1152 , V_81 -> V_440 -> V_1146 ) ;
V_1160 = 0 ;
V_1161 = F_11 ( F_322 ( V_81 -> V_94 ) ) & 0x0fff0fff ;
F_790 ( V_1152 , V_1160 | V_1161 ) ;
return 0 ;
}
static int F_795 ( struct V_62 * V_63 ,
struct V_144 * V_65 ,
struct V_244 * V_89 ,
struct V_252 * V_253 ,
struct V_1149 * V_1150 ,
T_2 V_328 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_1151 * V_1152 = V_1150 -> V_1152 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
T_2 V_1162 = 0 ;
int V_1163 , V_360 ;
switch ( V_81 -> V_133 ) {
case V_1164 :
V_1162 = V_1165 ;
break;
case V_366 :
V_1162 = V_1166 ;
break;
case V_1167 :
V_1162 = V_1168 ;
break;
default:
F_352 ( 1 , L_185 ) ;
return - V_416 ;
}
V_1163 = 4 ;
if ( V_1150 -> V_1169 -> V_377 == V_1170 ) {
V_1163 += 6 ;
if ( F_796 ( V_6 ) )
V_1163 += 2 ;
}
V_360 = F_797 ( V_1150 ) ;
if ( V_360 )
return V_360 ;
V_360 = F_789 ( V_1150 , V_1163 ) ;
if ( V_360 )
return V_360 ;
if ( V_1150 -> V_1169 -> V_377 == V_1170 ) {
F_790 ( V_1152 , F_798 ( 1 ) ) ;
F_799 ( V_1152 , V_1171 ) ;
F_790 ( V_1152 , ~ ( V_1172 |
V_1173 |
V_1174 ) ) ;
if ( F_796 ( V_6 ) )
F_790 ( V_1152 , V_1175 |
V_1176 ) ;
else
F_790 ( V_1152 , V_1177 |
V_1176 ) ;
F_799 ( V_1152 , V_1171 ) ;
F_790 ( V_1152 ,
F_800 ( V_1150 -> V_1169 -> V_1178 ) + 256 ) ;
if ( F_796 ( V_6 ) ) {
F_790 ( V_1152 , 0 ) ;
F_790 ( V_1152 , V_1157 ) ;
}
}
F_790 ( V_1152 , V_1159 | V_1162 ) ;
F_790 ( V_1152 , V_89 -> V_260 [ 0 ] |
F_214 ( V_89 -> V_257 ) ) ;
F_790 ( V_1152 , V_81 -> V_440 -> V_1146 ) ;
F_790 ( V_1152 , ( V_1157 ) ) ;
return 0 ;
}
static bool F_801 ( struct V_1179 * V_1169 ,
struct V_252 * V_253 )
{
if ( V_1169 == NULL )
return true ;
if ( F_59 ( V_1169 -> V_428 ) < 5 )
return false ;
if ( V_428 . F_801 < 0 )
return false ;
else if ( V_428 . F_801 > 0 )
return true ;
else if ( V_428 . V_1180 )
return true ;
return V_1169 != F_802 ( V_253 ) ;
}
static void F_803 ( struct V_81 * V_81 ,
unsigned int V_245 ,
struct V_1 * V_2 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_244 * V_89 = V_81 -> V_64 . V_88 -> V_89 ;
const enum V_94 V_94 = V_81 -> V_94 ;
T_1 V_1181 , V_290 = F_274 ( V_89 , 0 , V_245 ) ;
V_1181 = F_11 ( F_94 ( V_94 , 0 ) ) ;
V_1181 &= ~ V_1004 ;
switch ( V_89 -> V_257 ) {
case V_229 :
break;
case V_230 :
V_1181 |= V_395 ;
break;
case V_231 :
V_1181 |= V_396 ;
break;
case V_232 :
V_1181 |= V_397 ;
break;
default:
F_172 ( V_89 -> V_257 ) ;
}
F_124 ( F_94 ( V_94 , 0 ) , V_1181 ) ;
F_124 ( F_280 ( V_94 , 0 ) , V_290 ) ;
F_124 ( F_285 ( V_94 , 0 ) , V_2 -> V_1146 ) ;
F_125 ( F_285 ( V_94 , 0 ) ) ;
}
static void F_804 ( struct V_81 * V_81 ,
struct V_1 * V_2 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_244 * V_89 = V_81 -> V_64 . V_88 -> V_89 ;
T_3 V_13 = F_88 ( V_81 -> V_133 ) ;
T_1 V_361 ;
V_361 = F_11 ( V_13 ) ;
if ( V_89 -> V_257 == V_230 )
V_361 |= V_367 ;
else
V_361 &= ~ V_367 ;
F_124 ( V_13 , V_361 ) ;
F_124 ( F_259 ( V_81 -> V_133 ) , V_2 -> V_1146 ) ;
F_125 ( F_259 ( V_81 -> V_133 ) ) ;
}
static void F_805 ( struct V_1139 * V_354 )
{
struct V_1 * V_2 =
F_769 ( V_354 , struct V_1 , V_3 ) ;
struct V_81 * V_65 = F_48 ( V_2 -> V_65 ) ;
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
struct V_264 * V_265 =
F_182 ( V_65 -> V_64 . V_88 -> V_89 ) ;
struct V_252 * V_253 = V_265 -> V_253 ;
F_28 ( F_806 ( V_253 , 0 , V_1182 , NULL ) < 0 ) ;
F_807 ( V_65 ) ;
if ( F_59 ( V_6 ) >= 9 )
F_803 ( V_65 , V_2 -> V_245 , V_2 ) ;
else
F_804 ( V_65 , V_2 ) ;
F_808 ( V_65 , V_2 ) ;
}
static int F_809 ( struct V_62 * V_63 ,
struct V_144 * V_65 ,
struct V_244 * V_89 ,
struct V_252 * V_253 ,
struct V_1149 * V_1150 ,
T_2 V_328 )
{
return - V_416 ;
}
static bool F_810 ( struct V_5 * V_6 ,
struct V_81 * V_81 ,
struct V_1 * V_2 )
{
T_1 V_1183 , V_1184 ;
if ( ! F_342 ( & V_2 -> V_438 ) )
return false ;
F_781 () ;
V_1184 = F_779 ( V_81 ) ;
if ( V_2 -> V_1185 == 0 ) {
if ( V_2 -> V_1142 &&
! F_811 ( V_2 -> V_1142 ) )
return false ;
V_2 -> V_1185 = V_1184 ;
}
if ( V_1184 - V_2 -> V_1185 < 3 )
return false ;
if ( F_59 ( V_6 ) >= 4 )
V_1183 = F_812 ( F_11 ( F_259 ( V_81 -> V_133 ) ) ) ;
else
V_1183 = F_11 ( F_262 ( V_81 -> V_133 ) ) ;
return V_1183 == V_2 -> V_1146 ;
}
void F_813 ( struct V_5 * V_6 , int V_94 )
{
struct V_62 * V_63 = & V_6 -> V_422 ;
struct V_81 * V_65 = F_53 ( V_6 , V_94 ) ;
struct V_1 * V_2 ;
F_28 ( ! F_814 () ) ;
if ( V_65 == NULL )
return;
F_815 ( & V_63 -> V_439 ) ;
V_2 = V_65 -> V_440 ;
if ( V_2 != NULL && ! F_1 ( V_2 ) &&
F_810 ( V_6 , V_65 , V_2 ) ) {
F_352 ( 1 ,
L_186 ,
V_2 -> V_1148 , F_779 ( V_65 ) ) ;
F_344 ( V_65 ) ;
V_2 = NULL ;
}
if ( V_2 != NULL && ! F_1 ( V_2 ) &&
F_779 ( V_65 ) - V_2 -> V_1148 > 1 )
F_816 ( V_2 -> V_1142 ) ;
F_817 ( & V_63 -> V_439 ) ;
}
static int F_818 ( struct V_144 * V_65 ,
struct V_244 * V_89 ,
struct V_1186 * V_477 ,
T_2 V_1187 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_244 * V_1143 = V_65 -> V_88 -> V_89 ;
struct V_252 * V_253 = F_189 ( V_89 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_331 * V_88 = V_65 -> V_88 ;
enum V_94 V_94 = V_81 -> V_94 ;
struct V_1 * V_2 ;
struct V_1179 * V_1169 ;
bool V_1188 ;
struct V_1149 * V_1189 ;
struct V_251 * V_254 ;
int V_360 ;
if ( F_28 ( F_189 ( V_1143 ) == NULL ) )
return - V_1190 ;
if ( V_89 -> V_237 != V_65 -> V_88 -> V_89 -> V_237 )
return - V_286 ;
if ( F_59 ( V_6 ) > 3 &&
( V_89 -> V_278 [ 0 ] != V_65 -> V_88 -> V_89 -> V_278 [ 0 ] ||
V_89 -> V_260 [ 0 ] != V_65 -> V_88 -> V_89 -> V_260 [ 0 ] ) )
return - V_286 ;
if ( F_819 ( & V_6 -> V_436 ) )
goto V_1191;
V_2 = F_551 ( sizeof( * V_2 ) , V_722 ) ;
if ( V_2 == NULL )
return - V_721 ;
V_2 -> V_477 = V_477 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_1143 = V_1143 ;
F_820 ( & V_2 -> V_481 , F_768 ) ;
V_360 = F_101 ( V_65 ) ;
if ( V_360 )
goto V_1192;
F_312 ( & V_63 -> V_439 ) ;
if ( V_81 -> V_440 ) {
if ( F_780 ( V_81 , V_81 -> V_440 ) ) {
F_20 ( L_187 ) ;
F_344 ( V_81 ) ;
} else {
F_20 ( L_188 ) ;
F_313 ( & V_63 -> V_439 ) ;
F_102 ( V_65 ) ;
F_237 ( V_2 ) ;
return - V_1190 ;
}
}
V_81 -> V_440 = V_2 ;
F_313 ( & V_63 -> V_439 ) ;
if ( F_342 ( & V_81 -> V_476 ) >= 2 )
F_821 ( V_6 -> V_480 ) ;
F_233 ( V_2 -> V_1143 ) ;
V_65 -> V_88 -> V_89 = V_89 ;
F_231 ( V_65 -> V_88 ) ;
V_2 -> V_479 = F_822 ( V_253 ) ;
V_360 = F_738 ( V_63 ) ;
if ( V_360 )
goto V_1193;
V_81 -> V_437 = F_319 ( & V_6 -> V_436 ) ;
if ( F_823 ( & V_6 -> V_436 ) ) {
V_360 = - V_1194 ;
goto V_1195;
}
F_824 ( & V_81 -> V_476 ) ;
if ( F_59 ( V_6 ) >= 5 || F_18 ( V_6 ) )
V_2 -> V_1147 = F_11 ( F_777 ( V_94 ) ) + 1 ;
if ( F_16 ( V_6 ) || F_17 ( V_6 ) ) {
V_1169 = V_6 -> V_1169 [ V_1196 ] ;
if ( V_89 -> V_257 != V_1143 -> V_257 )
V_1169 = NULL ;
} else if ( F_327 ( V_6 ) || F_265 ( V_6 ) ) {
V_1169 = V_6 -> V_1169 [ V_1196 ] ;
} else if ( F_59 ( V_6 ) >= 7 ) {
V_1169 = F_802 ( V_253 ) ;
if ( V_1169 == NULL || V_1169 -> V_377 != V_1170 )
V_1169 = V_6 -> V_1169 [ V_1196 ] ;
} else {
V_1169 = V_6 -> V_1169 [ V_1170 ] ;
}
V_1188 = F_801 ( V_1169 , V_253 ) ;
V_254 = F_188 ( V_89 , V_88 -> V_43 -> V_245 ) ;
if ( F_194 ( V_254 ) ) {
V_360 = F_242 ( V_254 ) ;
goto V_1197;
}
V_2 -> V_1141 = F_236 ( V_88 -> V_43 ) -> V_254 ;
F_236 ( V_88 -> V_43 ) -> V_254 = V_254 ;
V_2 -> V_1146 = F_800 ( V_254 ) + V_81 -> V_373 ;
V_2 -> V_245 = V_65 -> V_88 -> V_43 -> V_245 ;
F_418 ( V_81 , V_81 -> V_90 ,
F_236 ( V_88 -> V_43 ) ) ;
if ( V_1188 ) {
F_820 ( & V_2 -> V_3 , F_805 ) ;
F_348 ( V_1198 , & V_2 -> V_3 ) ;
} else {
V_1189 = F_825 ( V_1169 , V_1169 -> V_1199 ) ;
if ( F_194 ( V_1189 ) ) {
V_360 = F_242 ( V_1189 ) ;
goto V_1200;
}
V_360 = F_826 ( V_1189 , V_253 , false ) ;
if ( V_360 )
goto V_1201;
V_360 = V_6 -> V_433 . V_1202 ( V_63 , V_65 , V_89 , V_253 , V_1189 ,
V_1187 ) ;
if ( V_360 )
goto V_1201;
F_785 ( V_81 , V_2 ) ;
V_2 -> V_1142 = F_827 ( V_1189 ) ;
F_828 ( V_1189 ) ;
}
F_829 ( V_253 , 0 , V_1203 ) ;
F_830 ( F_189 ( V_1143 ) , V_253 ,
F_235 ( V_88 ) -> V_352 ) ;
F_5 ( & V_63 -> V_256 ) ;
F_831 ( F_41 ( V_63 ) ,
F_235 ( V_88 ) -> V_352 ) ;
F_832 ( V_81 -> V_133 , V_253 ) ;
return 0 ;
V_1201:
F_828 ( V_1189 ) ;
V_1200:
F_236 ( V_88 -> V_43 ) -> V_254 = V_2 -> V_1141 ;
F_200 ( V_254 ) ;
V_1197:
F_773 ( & V_81 -> V_476 ) ;
V_1195:
F_5 ( & V_63 -> V_256 ) ;
V_1193:
V_65 -> V_88 -> V_89 = V_1143 ;
F_231 ( V_65 -> V_88 ) ;
F_230 ( V_253 ) ;
F_232 ( V_2 -> V_1143 ) ;
F_312 ( & V_63 -> V_439 ) ;
V_81 -> V_440 = NULL ;
F_313 ( & V_63 -> V_439 ) ;
F_102 ( V_65 ) ;
V_1192:
F_237 ( V_2 ) ;
if ( V_360 == - V_1194 ) {
struct V_418 * V_43 ;
struct V_333 * V_334 ;
V_1191:
V_43 = F_536 ( V_63 ) ;
if ( ! V_43 )
return - V_721 ;
V_43 -> V_431 = F_833 ( V_65 ) ;
V_461:
V_334 = F_749 ( V_43 , V_88 ) ;
V_360 = F_544 ( V_334 ) ;
if ( ! V_360 ) {
F_752 ( V_334 , V_89 ) ;
V_360 = F_751 ( V_334 , V_65 ) ;
if ( ! V_360 )
V_360 = F_297 ( V_43 ) ;
}
if ( V_360 == - V_421 ) {
F_303 ( V_43 -> V_431 ) ;
F_834 ( V_43 ) ;
goto V_461;
}
F_306 ( V_43 ) ;
if ( V_360 == 0 && V_477 ) {
F_312 ( & V_63 -> V_439 ) ;
F_345 ( V_65 , V_477 ) ;
F_313 ( & V_63 -> V_439 ) ;
}
}
return V_360 ;
}
static bool F_835 ( struct V_331 * V_133 ,
struct V_333 * V_43 )
{
struct V_263 * V_1204 = F_236 ( V_43 ) ;
struct V_263 * V_1205 = F_236 ( V_133 -> V_43 ) ;
if ( V_1204 -> V_64 . V_338 != V_1205 -> V_64 . V_338 )
return true ;
if ( ! V_1205 -> V_64 . V_89 || ! V_1204 -> V_64 . V_89 )
return false ;
if ( V_1205 -> V_64 . V_89 -> V_257 != V_1204 -> V_64 . V_89 -> V_257 ||
V_1205 -> V_64 . V_245 != V_1204 -> V_64 . V_245 ||
F_248 ( & V_1204 -> V_64 . V_349 ) != F_248 ( & V_1205 -> V_64 . V_349 ) ||
F_249 ( & V_1204 -> V_64 . V_349 ) != F_249 ( & V_1205 -> V_64 . V_349 ) ||
F_248 ( & V_1204 -> V_64 . V_350 ) != F_248 ( & V_1205 -> V_64 . V_350 ) ||
F_249 ( & V_1204 -> V_64 . V_350 ) != F_249 ( & V_1205 -> V_64 . V_350 ) )
return true ;
return false ;
}
static bool F_836 ( struct V_263 * V_43 )
{
int V_343 = F_248 ( & V_43 -> V_64 . V_349 ) >> 16 ;
int V_344 = F_249 ( & V_43 -> V_64 . V_349 ) >> 16 ;
int V_407 = F_248 ( & V_43 -> V_64 . V_350 ) ;
int V_408 = F_249 ( & V_43 -> V_64 . V_350 ) ;
return ( V_343 != V_407 || V_344 != V_408 ) ;
}
int F_837 ( struct V_42 * V_60 ,
struct V_333 * V_334 )
{
struct V_37 * V_38 = F_291 ( V_60 ) ;
struct V_144 * V_65 = V_60 -> V_65 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_331 * V_133 = V_334 -> V_133 ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_263 * V_1206 =
F_236 ( V_133 -> V_43 ) ;
bool V_419 = F_25 ( V_60 ) ;
bool V_1207 = V_65 -> V_43 -> V_87 ;
bool V_1208 = V_60 -> V_87 ;
bool V_1209 , V_1210 , V_338 , V_1211 ;
struct V_244 * V_89 = V_334 -> V_89 ;
int V_360 ;
if ( F_59 ( V_6 ) >= 9 && V_133 -> type != V_1212 ) {
V_360 = F_394 (
F_291 ( V_60 ) ,
F_236 ( V_334 ) ) ;
if ( V_360 )
return V_360 ;
}
V_1211 = V_1206 -> V_64 . V_338 ;
V_338 = F_236 ( V_334 ) -> V_64 . V_338 ;
if ( ! V_1207 && F_28 ( V_1211 ) )
V_1211 = false ;
if ( ! V_1208 )
F_236 ( V_334 ) -> V_64 . V_338 = V_338 = false ;
if ( ! V_1211 && ! V_338 )
return 0 ;
if ( V_89 != V_1206 -> V_64 . V_89 )
V_38 -> V_1213 = true ;
V_1209 = V_1211 && ( ! V_338 || V_419 ) ;
V_1210 = V_338 && ( ! V_1211 || V_419 ) ;
F_838 ( L_189 ,
V_81 -> V_64 . V_64 . V_377 ,
V_81 -> V_64 . V_12 ,
V_133 -> V_64 . V_377 , V_133 -> V_12 ,
V_89 ? V_89 -> V_64 . V_377 : - 1 ) ;
F_838 ( L_190 ,
V_133 -> V_64 . V_377 , V_133 -> V_12 ,
V_1211 , V_338 ,
V_1209 , V_1210 , V_419 ) ;
if ( V_1210 ) {
V_38 -> V_575 = true ;
if ( V_133 -> type != V_1212 )
V_38 -> V_572 = true ;
} else if ( V_1209 ) {
V_38 -> V_566 = true ;
if ( V_133 -> type != V_1212 )
V_38 -> V_572 = true ;
} else if ( F_835 ( V_133 , V_334 ) ) {
V_38 -> V_575 = true ;
V_38 -> V_566 = true ;
}
if ( ( V_38 -> V_575 || V_38 -> V_566 ) &&
F_59 ( V_6 ) < 9 && V_6 -> V_433 . V_1214 )
F_291 ( V_60 ) -> V_559 . V_1215 = true ;
if ( V_338 || V_1211 )
V_38 -> V_564 |= F_235 ( V_133 ) -> V_352 ;
if ( V_133 -> type == V_1216 && F_327 ( V_6 ) &&
F_836 ( F_236 ( V_334 ) ) &&
! F_836 ( V_1206 ) )
V_38 -> V_573 = true ;
return 0 ;
}
static bool F_839 ( const struct V_510 * V_1144 ,
const struct V_510 * V_1145 )
{
return V_1144 == V_1145 || ( V_1144 -> V_1217 & ( 1 << V_1145 -> type ) &&
V_1145 -> V_1217 & ( 1 << V_1144 -> type ) ) ;
}
static bool F_840 ( struct V_418 * V_43 ,
struct V_81 * V_65 ,
struct V_510 * V_511 )
{
struct V_510 * V_1218 ;
struct V_578 * V_719 ;
struct V_576 * V_1113 ;
int V_135 ;
F_424 (state, connector, connector_state, i) {
if ( V_1113 -> V_65 != & V_65 -> V_64 )
continue;
V_1218 =
F_425 ( V_1113 -> V_581 ) ;
if ( ! F_839 ( V_511 , V_1218 ) )
return false ;
}
return true ;
}
static int F_841 ( struct V_144 * V_65 ,
struct V_42 * V_60 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_37 * V_38 =
F_291 ( V_60 ) ;
struct V_418 * V_43 = V_60 -> V_43 ;
int V_360 ;
bool V_419 = F_25 ( V_60 ) ;
if ( V_419 && ! V_60 -> V_87 )
V_38 -> V_566 = true ;
if ( V_419 && V_60 -> V_506 &&
V_6 -> V_433 . V_1219 &&
! F_28 ( V_38 -> V_205 ) ) {
V_360 = V_6 -> V_433 . V_1219 ( V_81 ,
V_38 ) ;
if ( V_360 )
return V_360 ;
}
if ( V_60 -> V_1220 ) {
V_360 = F_842 ( V_65 , V_60 ) ;
if ( V_360 )
return V_360 ;
V_60 -> V_1221 = true ;
}
V_360 = 0 ;
if ( V_6 -> V_433 . V_1222 ) {
V_360 = V_6 -> V_433 . V_1222 ( V_38 ) ;
if ( V_360 ) {
F_161 ( L_191 ) ;
return V_360 ;
}
}
if ( V_6 -> V_433 . V_1223 &&
! F_296 ( V_43 ) -> V_420 ) {
if ( F_28 ( ! V_6 -> V_433 . V_1222 ) )
return 0 ;
V_360 = V_6 -> V_433 . V_1223 ( V_63 ,
V_81 ,
V_38 ) ;
if ( V_360 ) {
F_161 ( L_192 ) ;
return V_360 ;
}
} else if ( V_6 -> V_433 . V_1223 ) {
if ( F_15 ( V_6 ) && F_59 ( V_6 ) < 9 )
V_38 -> V_559 . V_1224 . V_1225 = V_38 -> V_559 . V_1224 . V_1226 ;
}
if ( F_59 ( V_6 ) >= 9 ) {
if ( V_419 )
V_360 = F_393 ( V_38 ) ;
if ( ! V_360 )
V_360 = F_843 ( V_63 , V_81 ,
V_38 ) ;
}
return V_360 ;
}
static void F_844 ( struct V_62 * V_63 )
{
struct V_718 * V_719 ;
F_845 (dev, connector) {
if ( V_719 -> V_64 . V_43 -> V_65 )
F_846 ( & V_719 -> V_64 ) ;
if ( V_719 -> V_64 . V_511 ) {
V_719 -> V_64 . V_43 -> V_581 =
V_719 -> V_64 . V_511 ;
V_719 -> V_64 . V_43 -> V_65 =
V_719 -> V_64 . V_511 -> V_65 ;
F_847 ( & V_719 -> V_64 ) ;
} else {
V_719 -> V_64 . V_43 -> V_581 = NULL ;
V_719 -> V_64 . V_43 -> V_65 = NULL ;
}
}
}
static void
F_848 ( struct V_718 * V_719 ,
struct V_37 * V_38 )
{
const struct V_1227 * V_1228 = & V_719 -> V_64 . V_1229 ;
int V_986 = V_38 -> V_730 ;
F_161 ( L_193 ,
V_719 -> V_64 . V_64 . V_377 ,
V_719 -> V_64 . V_12 ) ;
if ( V_1228 -> V_520 != 0 && V_1228 -> V_520 * 3 < V_986 ) {
F_161 ( L_194 ,
V_986 , V_1228 -> V_520 * 3 ) ;
V_38 -> V_730 = V_1228 -> V_520 * 3 ;
}
if ( V_1228 -> V_520 == 0 && V_986 > 24 ) {
F_161 ( L_195 ,
V_986 ) ;
V_38 -> V_730 = 24 ;
}
}
static int
F_849 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
struct V_418 * V_43 ;
struct V_578 * V_719 ;
struct V_576 * V_1113 ;
int V_986 , V_135 ;
if ( ( F_18 ( V_6 ) || F_16 ( V_6 ) ||
F_17 ( V_6 ) ) )
V_986 = 10 * 3 ;
else if ( F_59 ( V_6 ) >= 5 )
V_986 = 12 * 3 ;
else
V_986 = 8 * 3 ;
V_38 -> V_730 = V_986 ;
V_43 = V_38 -> V_64 . V_43 ;
F_424 (state, connector, connector_state, i) {
if ( V_1113 -> V_65 != & V_65 -> V_64 )
continue;
F_848 ( F_850 ( V_719 ) ,
V_38 ) ;
}
return V_986 ;
}
static void F_851 ( const struct V_519 * V_414 )
{
F_161 ( L_196
L_197 ,
V_414 -> V_92 ,
V_414 -> V_542 , V_414 -> V_735 ,
V_414 -> V_885 , V_414 -> V_882 ,
V_414 -> V_543 , V_414 -> V_887 ,
V_414 -> V_888 , V_414 -> V_878 , V_414 -> type , V_414 -> V_328 ) ;
}
static inline void
F_852 ( struct V_37 * V_38 , char * V_377 ,
unsigned int V_1043 , struct V_795 * V_796 )
{
F_161 ( L_198 ,
V_377 , V_1043 ,
V_796 -> V_798 , V_796 -> V_799 ,
V_796 -> V_800 , V_796 -> V_801 , V_796 -> V_797 ) ;
}
static void F_853 ( struct V_81 * V_65 ,
struct V_37 * V_38 ,
const char * V_1230 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_331 * V_133 ;
struct V_335 * V_335 ;
struct V_263 * V_43 ;
struct V_244 * V_89 ;
F_161 ( L_199 ,
V_65 -> V_64 . V_64 . V_377 , V_65 -> V_64 . V_12 , V_1230 ) ;
F_161 ( L_200 ,
F_854 ( V_38 -> V_95 ) ,
V_38 -> V_730 , V_38 -> V_901 ) ;
if ( V_38 -> V_221 )
F_852 ( V_38 , L_201 ,
V_38 -> V_456 ,
& V_38 -> V_588 ) ;
if ( F_389 ( V_38 ) ) {
F_852 ( V_38 , L_202 ,
V_38 -> V_1043 , & V_38 -> V_815 ) ;
if ( V_38 -> V_813 )
F_852 ( V_38 , L_203 ,
V_38 -> V_1043 ,
& V_38 -> V_816 ) ;
}
F_161 ( L_204 ,
V_38 -> V_1042 , V_38 -> V_1231 ) ;
F_161 ( L_205 ) ;
F_855 ( & V_38 -> V_64 . V_414 ) ;
F_161 ( L_206 ) ;
F_855 ( & V_38 -> V_64 . V_91 ) ;
F_851 ( & V_38 -> V_64 . V_91 ) ;
F_161 ( L_207 ,
V_38 -> V_39 ,
V_38 -> V_365 , V_38 -> V_364 ) ;
if ( F_59 ( V_6 ) >= 9 )
F_161 ( L_208 ,
V_65 -> V_380 ,
V_38 -> V_379 . V_532 ,
V_38 -> V_379 . V_404 ) ;
if ( F_163 ( V_6 ) )
F_161 ( L_209 ,
V_38 -> V_596 . V_597 ,
V_38 -> V_596 . V_601 ,
V_38 -> V_596 . V_1232 ) ;
else
F_161 ( L_210 ,
V_38 -> V_442 . V_547 ,
V_38 -> V_442 . V_240 ,
F_856 ( V_38 -> V_442 . V_145 ) ) ;
F_161 ( L_211 ,
V_38 -> V_550 , V_38 -> V_225 ) ;
if ( F_36 ( V_6 ) ) {
F_161 ( L_212
L_213
L_214 ,
V_38 -> V_173 . V_1233 ,
V_38 -> V_173 . V_1234 ,
V_38 -> V_173 . V_1235 ,
V_38 -> V_173 . V_1236 ,
V_38 -> V_173 . V_1237 ,
V_38 -> V_173 . V_1238 ,
V_38 -> V_173 . V_1239 ,
V_38 -> V_173 . V_1240 ,
V_38 -> V_173 . V_1241 ,
V_38 -> V_173 . V_1242 ,
V_38 -> V_173 . V_1243 ) ;
} else if ( F_477 ( V_6 ) || F_478 ( V_6 ) ) {
F_161 ( L_215
L_216 ,
V_38 -> V_173 . V_1244 ,
V_38 -> V_173 . V_1245 ,
V_38 -> V_173 . V_1246 ) ;
} else if ( F_23 ( V_6 ) ) {
F_161 ( L_217 ,
V_38 -> V_173 . V_1247 ,
V_38 -> V_173 . V_1248 ) ;
} else {
F_161 ( L_218
L_219 ,
V_38 -> V_173 . V_45 ,
V_38 -> V_173 . V_175 ,
V_38 -> V_173 . V_713 ,
V_38 -> V_173 . V_714 ) ;
}
F_161 ( L_220 ) ;
F_857 (plane, &dev->mode_config.plane_list, head) {
struct V_1249 V_1250 ;
V_335 = F_235 ( V_133 ) ;
if ( V_335 -> V_94 != V_65 -> V_94 )
continue;
V_43 = F_236 ( V_133 -> V_43 ) ;
V_89 = V_43 -> V_64 . V_89 ;
if ( ! V_89 ) {
F_161 ( L_221 ,
V_133 -> V_64 . V_377 , V_133 -> V_12 , V_43 -> V_404 ) ;
continue;
}
F_161 ( L_222 ,
V_133 -> V_64 . V_377 , V_133 -> V_12 ,
V_89 -> V_64 . V_377 , V_89 -> V_241 , V_89 -> V_236 ,
F_858 ( V_89 -> V_237 , & V_1250 ) ) ;
if ( F_59 ( V_6 ) >= 9 )
F_161 ( L_223 ,
V_43 -> V_404 ,
V_43 -> V_64 . V_349 . V_291 >> 16 ,
V_43 -> V_64 . V_349 . y1 >> 16 ,
F_248 ( & V_43 -> V_64 . V_349 ) >> 16 ,
F_249 ( & V_43 -> V_64 . V_349 ) >> 16 ,
V_43 -> V_64 . V_350 . V_291 , V_43 -> V_64 . V_350 . y1 ,
F_248 ( & V_43 -> V_64 . V_350 ) ,
F_249 ( & V_43 -> V_64 . V_350 ) ) ;
}
}
static bool F_859 ( struct V_418 * V_43 )
{
struct V_62 * V_63 = V_43 -> V_63 ;
struct V_578 * V_719 ;
unsigned int V_1251 = 0 ;
unsigned int V_1252 = 0 ;
F_860 (connector, dev) {
struct V_576 * V_1113 ;
struct V_510 * V_511 ;
V_1113 = F_861 ( V_43 , V_719 ) ;
if ( ! V_1113 )
V_1113 = V_719 -> V_43 ;
if ( ! V_1113 -> V_581 )
continue;
V_511 = F_425 ( V_1113 -> V_581 ) ;
F_28 ( ! V_1113 -> V_65 ) ;
switch ( V_511 -> type ) {
unsigned int V_195 ;
case V_615 :
if ( F_28 ( ! F_23 ( F_41 ( V_63 ) ) ) )
break;
case V_512 :
case V_208 :
case V_513 :
V_195 = 1 << F_381 ( & V_511 -> V_64 ) -> V_177 ;
if ( V_1251 & V_195 )
return false ;
V_1251 |= V_195 ;
break;
case V_592 :
V_1252 |=
1 << F_464 ( & V_511 -> V_64 ) -> V_88 -> V_177 ;
break;
default:
break;
}
}
if ( V_1251 & V_1252 )
return false ;
return true ;
}
static void
F_862 ( struct V_37 * V_60 )
{
struct V_42 V_1253 ;
struct V_378 V_379 ;
struct V_1254 V_173 ;
struct V_992 * V_205 ;
bool V_621 ;
V_1253 = V_60 -> V_64 ;
V_379 = V_60 -> V_379 ;
V_205 = V_60 -> V_205 ;
V_173 = V_60 -> V_173 ;
V_621 = V_60 -> V_442 . V_621 ;
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_60 -> V_64 = V_1253 ;
V_60 -> V_379 = V_379 ;
V_60 -> V_205 = V_205 ;
V_60 -> V_173 = V_173 ;
V_60 -> V_442 . V_621 = V_621 ;
}
static int
F_863 ( struct V_144 * V_65 ,
struct V_37 * V_38 )
{
struct V_418 * V_43 = V_38 -> V_64 . V_43 ;
struct V_510 * V_511 ;
struct V_578 * V_719 ;
struct V_576 * V_1113 ;
int V_1255 , V_360 = - V_286 ;
int V_135 ;
bool V_461 = true ;
F_862 ( V_38 ) ;
V_38 -> V_95 =
(enum V_93 ) F_48 ( V_65 ) -> V_94 ;
if ( ! ( V_38 -> V_64 . V_91 . V_328 &
( V_524 | V_1256 ) ) )
V_38 -> V_64 . V_91 . V_328 |= V_1256 ;
if ( ! ( V_38 -> V_64 . V_91 . V_328 &
( V_526 | V_1257 ) ) )
V_38 -> V_64 . V_91 . V_328 |= V_1257 ;
V_1255 = F_849 ( F_48 ( V_65 ) ,
V_38 ) ;
if ( V_1255 < 0 )
goto V_784;
F_750 ( & V_38 -> V_64 . V_414 ,
& V_38 -> V_365 ,
& V_38 -> V_364 ) ;
F_424 (state, connector, connector_state, i) {
if ( V_1113 -> V_65 != V_65 )
continue;
V_511 = F_425 ( V_1113 -> V_581 ) ;
if ( ! F_840 ( V_43 , F_48 ( V_65 ) , V_511 ) ) {
F_161 ( L_224 ) ;
goto V_784;
}
V_38 -> V_1258 |= 1 << V_511 -> type ;
}
V_1259:
V_38 -> V_39 = 0 ;
V_38 -> V_591 = 1 ;
F_864 ( & V_38 -> V_64 . V_91 ,
V_1260 ) ;
F_424 (state, connector, connector_state, i) {
if ( V_1113 -> V_65 != V_65 )
continue;
V_511 = F_425 ( V_1113 -> V_581 ) ;
if ( ! ( V_511 -> V_1261 ( V_511 , V_38 , V_1113 ) ) ) {
F_161 ( L_225 ) ;
goto V_784;
}
}
if ( ! V_38 -> V_39 )
V_38 -> V_39 = V_38 -> V_64 . V_91 . V_92
* V_38 -> V_591 ;
V_360 = F_563 ( F_48 ( V_65 ) , V_38 ) ;
if ( V_360 < 0 ) {
F_161 ( L_226 ) ;
goto V_784;
}
if ( V_360 == V_732 ) {
if ( F_7 ( ! V_461 , L_227 ) ) {
V_360 = - V_286 ;
goto V_784;
}
F_161 ( L_228 ) ;
V_461 = false ;
goto V_1259;
}
V_38 -> V_901 = V_38 -> V_730 == 6 * 3 ;
F_161 ( L_229 ,
V_1255 , V_38 -> V_730 , V_38 -> V_901 ) ;
V_784:
return V_360 ;
}
static void
F_865 ( struct V_418 * V_43 )
{
struct V_144 * V_65 ;
struct V_42 * V_60 ;
int V_135 ;
F_295 (state, crtc, crtc_state, i) {
F_48 ( V_65 ) -> V_90 = F_291 ( V_65 -> V_43 ) ;
if ( V_65 -> V_43 -> V_87 )
V_65 -> V_1262 = V_65 -> V_43 -> V_91 ;
else
V_65 -> V_1262 . V_92 = 0 ;
if ( F_413 ( V_43 , V_65 -> V_88 ) ) {
struct V_333 * V_334 = V_65 -> V_88 -> V_43 ;
V_65 -> V_88 -> V_89 = V_334 -> V_89 ;
V_65 -> V_261 = V_334 -> V_341 >> 16 ;
V_65 -> V_262 = V_334 -> V_342 >> 16 ;
}
}
}
static bool F_866 ( int V_1263 , int V_1264 )
{
int V_1265 ;
if ( V_1263 == V_1264 )
return true ;
if ( ! V_1263 || ! V_1264 )
return false ;
V_1265 = abs ( V_1263 - V_1264 ) ;
if ( ( ( ( ( V_1265 + V_1263 + V_1264 ) * 100 ) ) / ( V_1263 + V_1264 ) ) < 105 )
return true ;
return false ;
}
static bool
F_867 ( unsigned int V_46 , unsigned int V_51 ,
unsigned int V_47 , unsigned int V_1266 ,
bool V_1267 )
{
if ( V_46 == V_47 && V_51 == V_1266 )
return true ;
if ( V_1267 || ! V_46 || ! V_51 || ! V_47 || ! V_1266 )
return false ;
F_868 ( V_788 > V_84 ) ;
if ( V_51 > V_1266 ) {
while ( V_51 > V_1266 ) {
V_47 <<= 1 ;
V_1266 <<= 1 ;
}
} else if ( V_51 < V_1266 ) {
while ( V_51 < V_1266 ) {
V_46 <<= 1 ;
V_51 <<= 1 ;
}
}
if ( V_51 != V_1266 )
return false ;
return F_866 ( V_46 , V_47 ) ;
}
static bool
F_869 ( const struct V_795 * V_796 ,
struct V_795 * V_812 ,
bool V_1268 )
{
if ( V_796 -> V_797 == V_812 -> V_797 &&
F_867 ( V_796 -> V_798 , V_796 -> V_799 ,
V_812 -> V_798 , V_812 -> V_799 , ! V_1268 ) &&
F_867 ( V_796 -> V_800 , V_796 -> V_801 ,
V_812 -> V_800 , V_812 -> V_801 , ! V_1268 ) ) {
if ( V_1268 )
* V_812 = * V_796 ;
return true ;
}
return false ;
}
static bool
F_870 ( struct V_5 * V_6 ,
struct V_37 * V_1269 ,
struct V_37 * V_38 ,
bool V_1268 )
{
bool V_360 = true ;
#define F_871 ( T_7 , ... ) \
do { \
if (!adjust) \
DRM_ERROR(fmt, ##__VA_ARGS__); \
else \
DRM_DEBUG_KMS(fmt, ##__VA_ARGS__); \
} while (0)
#define F_872 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_873 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_874 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %p, found %p)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_875 ( V_12 ) \
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
#define F_876 ( V_12 , T_8 ) \
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
#define F_877 ( V_12 , V_620 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
ret = false; \
}
#define F_878 ( V_12 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_879 ( T_9 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_873 ( V_95 ) ;
F_873 ( V_221 ) ;
F_873 ( V_456 ) ;
F_875 ( V_588 ) ;
F_873 ( V_1043 ) ;
F_872 ( V_1270 ) ;
if ( F_59 ( V_6 ) < 8 ) {
F_875 ( V_815 ) ;
if ( V_1269 -> V_813 )
F_875 ( V_816 ) ;
} else
F_876 ( V_815 , V_816 ) ;
F_872 ( V_1258 ) ;
F_873 ( V_64 . V_91 . V_542 ) ;
F_873 ( V_64 . V_91 . V_882 ) ;
F_873 ( V_64 . V_91 . V_883 ) ;
F_873 ( V_64 . V_91 . V_884 ) ;
F_873 ( V_64 . V_91 . V_735 ) ;
F_873 ( V_64 . V_91 . V_885 ) ;
F_873 ( V_64 . V_91 . V_543 ) ;
F_873 ( V_64 . V_91 . V_878 ) ;
F_873 ( V_64 . V_91 . V_886 ) ;
F_873 ( V_64 . V_91 . V_879 ) ;
F_873 ( V_64 . V_91 . V_887 ) ;
F_873 ( V_64 . V_91 . V_888 ) ;
F_873 ( V_591 ) ;
F_873 ( V_1271 ) ;
if ( ( F_59 ( V_6 ) < 8 && ! F_265 ( V_6 ) ) ||
F_16 ( V_6 ) || F_17 ( V_6 ) )
F_873 ( V_910 ) ;
F_873 ( V_1231 ) ;
F_873 ( V_1042 ) ;
F_877 ( V_64 . V_91 . V_328 ,
V_881 ) ;
if ( ! F_879 ( V_1272 ) ) {
F_877 ( V_64 . V_91 . V_328 ,
V_524 ) ;
F_877 ( V_64 . V_91 . V_328 ,
V_1256 ) ;
F_877 ( V_64 . V_91 . V_328 ,
V_526 ) ;
F_877 ( V_64 . V_91 . V_328 ,
V_1257 ) ;
}
F_872 ( V_596 . V_597 ) ;
if ( F_59 ( V_6 ) < 4 )
F_872 ( V_596 . V_601 ) ;
F_872 ( V_596 . V_1232 ) ;
if ( ! V_1268 ) {
F_873 ( V_365 ) ;
F_873 ( V_364 ) ;
F_873 ( V_442 . V_145 ) ;
if ( V_1269 -> V_442 . V_145 ) {
F_872 ( V_442 . V_547 ) ;
F_872 ( V_442 . V_240 ) ;
}
F_873 ( V_379 . V_404 ) ;
}
if ( F_265 ( V_6 ) )
F_873 ( V_550 ) ;
F_873 ( V_225 ) ;
F_874 ( V_205 ) ;
F_872 ( V_173 . V_45 ) ;
F_872 ( V_173 . V_175 ) ;
F_872 ( V_173 . V_713 ) ;
F_872 ( V_173 . V_714 ) ;
F_872 ( V_173 . V_1247 ) ;
F_872 ( V_173 . V_1248 ) ;
F_872 ( V_173 . V_1244 ) ;
F_872 ( V_173 . V_1245 ) ;
F_872 ( V_173 . V_1246 ) ;
F_872 ( V_1273 . V_1274 ) ;
F_872 ( V_1273 . div ) ;
if ( F_18 ( V_6 ) || F_59 ( V_6 ) >= 5 )
F_873 ( V_730 ) ;
F_878 ( V_64 . V_91 . V_92 ) ;
F_878 ( V_39 ) ;
#undef F_872
#undef F_873
#undef F_874
#undef F_877
#undef F_878
#undef F_879
#undef F_871
return V_360 ;
}
static void F_880 ( struct V_5 * V_6 ,
const struct V_37 * V_38 )
{
if ( V_38 -> V_221 ) {
int V_728 = F_763 ( F_22 ( V_6 , V_38 ) ,
& V_38 -> V_588 ) ;
int V_1275 = V_38 -> V_64 . V_91 . V_92 ;
F_7 ( ! F_866 ( V_728 , V_1275 ) ,
L_230 ,
V_728 , V_1275 ) ;
}
}
static void F_881 ( struct V_144 * V_65 ,
struct V_42 * V_1276 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
struct V_1277 V_1278 , * V_1279 ;
struct V_1280 V_1281 , * V_1282 ;
struct V_1283 * V_1284 , * V_1285 ;
struct V_1286 * V_1287 , * V_1288 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
const enum V_94 V_94 = V_81 -> V_94 ;
int V_133 , V_1289 , V_1290 = F_882 ( V_6 ) ;
if ( F_59 ( V_6 ) < 9 || ! V_1276 -> V_87 )
return;
F_883 ( V_65 , & V_1281 ) ;
V_1282 = & F_291 ( V_1276 ) -> V_559 . V_1291 . V_1226 ;
F_884 ( V_6 , & V_1278 ) ;
V_1279 = & V_6 -> V_559 . V_1292 . V_1293 ;
F_885 (dev_priv, pipe, plane) {
V_1284 = & V_1281 . V_1294 [ V_133 ] ;
V_1285 = & V_1282 -> V_1294 [ V_133 ] ;
for ( V_1289 = 0 ; V_1289 <= V_1290 ; V_1289 ++ ) {
if ( F_886 ( & V_1284 -> V_559 [ V_1289 ] ,
& V_1285 -> V_559 [ V_1289 ] ) )
continue;
F_127 ( L_231 ,
F_78 ( V_94 ) , V_133 + 1 , V_1289 ,
V_1285 -> V_559 [ V_1289 ] . V_1295 ,
V_1285 -> V_559 [ V_1289 ] . V_1296 ,
V_1285 -> V_559 [ V_1289 ] . V_1297 ,
V_1284 -> V_559 [ V_1289 ] . V_1295 ,
V_1284 -> V_559 [ V_1289 ] . V_1296 ,
V_1284 -> V_559 [ V_1289 ] . V_1297 ) ;
}
if ( ! F_886 ( & V_1284 -> V_1298 ,
& V_1285 -> V_1298 ) ) {
F_127 ( L_232 ,
F_78 ( V_94 ) , V_133 + 1 ,
V_1285 -> V_1298 . V_1295 ,
V_1285 -> V_1298 . V_1296 ,
V_1285 -> V_1298 . V_1297 ,
V_1284 -> V_1298 . V_1295 ,
V_1284 -> V_1298 . V_1296 ,
V_1284 -> V_1298 . V_1297 ) ;
}
V_1287 = & V_1278 . V_133 [ V_94 ] [ V_133 ] ;
V_1288 = & V_1279 -> V_133 [ V_94 ] [ V_133 ] ;
if ( ! F_887 ( V_1287 , V_1288 ) ) {
F_127 ( L_233 ,
F_78 ( V_94 ) , V_133 + 1 ,
V_1288 -> V_1299 , V_1288 -> V_1300 ,
V_1287 -> V_1299 , V_1287 -> V_1300 ) ;
}
}
if ( V_81 -> V_1102 ) {
V_1284 = & V_1281 . V_1294 [ V_1301 ] ;
V_1285 = & V_1282 -> V_1294 [ V_1301 ] ;
for ( V_1289 = 0 ; V_1289 <= V_1290 ; V_1289 ++ ) {
if ( F_886 ( & V_1284 -> V_559 [ V_1289 ] ,
& V_1285 -> V_559 [ V_1289 ] ) )
continue;
F_127 ( L_234 ,
F_78 ( V_94 ) , V_1289 ,
V_1285 -> V_559 [ V_1289 ] . V_1295 ,
V_1285 -> V_559 [ V_1289 ] . V_1296 ,
V_1285 -> V_559 [ V_1289 ] . V_1297 ,
V_1284 -> V_559 [ V_1289 ] . V_1295 ,
V_1284 -> V_559 [ V_1289 ] . V_1296 ,
V_1284 -> V_559 [ V_1289 ] . V_1297 ) ;
}
if ( ! F_886 ( & V_1284 -> V_1298 ,
& V_1285 -> V_1298 ) ) {
F_127 ( L_235 ,
F_78 ( V_94 ) ,
V_1285 -> V_1298 . V_1295 ,
V_1285 -> V_1298 . V_1296 ,
V_1285 -> V_1298 . V_1297 ,
V_1284 -> V_1298 . V_1295 ,
V_1284 -> V_1298 . V_1296 ,
V_1284 -> V_1298 . V_1297 ) ;
}
V_1287 = & V_1278 . V_133 [ V_94 ] [ V_1301 ] ;
V_1288 = & V_1279 -> V_133 [ V_94 ] [ V_1301 ] ;
if ( ! F_887 ( V_1287 , V_1288 ) ) {
F_127 ( L_236 ,
F_78 ( V_94 ) ,
V_1288 -> V_1299 , V_1288 -> V_1300 ,
V_1287 -> V_1299 , V_1287 -> V_1300 ) ;
}
}
}
static void
F_888 ( struct V_62 * V_63 ,
struct V_418 * V_43 ,
struct V_144 * V_65 )
{
struct V_578 * V_719 ;
struct V_576 * V_577 ;
int V_135 ;
F_424 (state, connector, old_conn_state, i) {
struct V_619 * V_511 = V_719 -> V_511 ;
struct V_576 * V_43 = V_719 -> V_43 ;
if ( V_43 -> V_65 != V_65 )
continue;
F_547 ( F_850 ( V_719 ) ) ;
F_65 ( V_43 -> V_581 != V_511 ,
L_237 ) ;
}
}
static void
F_889 ( struct V_62 * V_63 )
{
struct V_510 * V_511 ;
struct V_718 * V_719 ;
F_658 (dev, encoder) {
bool V_145 = false ;
enum V_94 V_94 ;
F_161 ( L_238 ,
V_511 -> V_64 . V_64 . V_377 ,
V_511 -> V_64 . V_12 ) ;
F_845 (dev, connector) {
if ( V_719 -> V_64 . V_43 -> V_581 != & V_511 -> V_64 )
continue;
V_145 = true ;
F_65 ( V_719 -> V_64 . V_43 -> V_65 !=
V_511 -> V_64 . V_65 ,
L_239 ) ;
}
F_65 ( ! ! V_511 -> V_64 . V_65 != V_145 ,
L_240
L_241 ,
! ! V_511 -> V_64 . V_65 , V_145 ) ;
if ( ! V_511 -> V_64 . V_65 ) {
bool V_87 ;
V_87 = V_511 -> V_720 ( V_511 , & V_94 ) ;
F_65 ( V_87 ,
L_242 ,
F_78 ( V_94 ) ) ;
}
}
}
static void
F_890 ( struct V_144 * V_65 ,
struct V_42 * V_441 ,
struct V_42 * V_1302 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_510 * V_511 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_37 * V_38 , * V_1303 ;
struct V_418 * V_562 ;
bool V_87 ;
V_562 = V_441 -> V_43 ;
F_891 ( V_441 ) ;
V_38 = F_291 ( V_441 ) ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_38 -> V_64 . V_65 = V_65 ;
V_38 -> V_64 . V_43 = V_562 ;
F_161 ( L_243 , V_65 -> V_64 . V_377 , V_65 -> V_12 ) ;
V_87 = V_6 -> V_433 . V_1304 ( V_81 , V_38 ) ;
if ( ( V_81 -> V_94 == V_113 && V_6 -> V_129 & V_130 ) ||
( V_81 -> V_94 == V_120 && V_6 -> V_129 & V_131 ) )
V_87 = V_1302 -> V_87 ;
F_65 ( V_1302 -> V_87 != V_87 ,
L_244
L_241 , V_1302 -> V_87 , V_87 ) ;
F_65 ( V_81 -> V_87 != V_1302 -> V_87 ,
L_245
L_241 , V_1302 -> V_87 , V_81 -> V_87 ) ;
F_380 (dev, crtc, encoder) {
enum V_94 V_94 ;
V_87 = V_511 -> V_720 ( V_511 , & V_94 ) ;
F_65 ( V_87 != V_1302 -> V_87 ,
L_246 ,
V_511 -> V_64 . V_64 . V_377 , V_87 , V_1302 -> V_87 ) ;
F_65 ( V_87 && V_81 -> V_94 != V_94 ,
L_247 ,
F_78 ( V_94 ) ) ;
if ( V_87 ) {
V_38 -> V_1258 |= 1 << V_511 -> type ;
V_511 -> V_1305 ( V_511 , V_38 ) ;
}
}
if ( ! V_1302 -> V_87 )
return;
F_880 ( V_6 , V_38 ) ;
V_1303 = F_291 ( V_65 -> V_43 ) ;
if ( ! F_870 ( V_6 , V_1303 ,
V_38 , false ) ) {
F_65 ( 1 , L_248 ) ;
F_853 ( V_81 , V_38 ,
L_249 ) ;
F_853 ( V_81 , V_1303 ,
L_250 ) ;
}
}
static void
F_892 ( struct V_5 * V_6 ,
struct V_992 * V_993 ,
struct V_144 * V_65 ,
struct V_42 * V_1276 )
{
struct V_1254 V_173 ;
unsigned V_1306 ;
bool V_87 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
F_161 ( L_251 , V_993 -> V_12 ) ;
V_87 = V_993 -> V_1011 . V_720 ( V_6 , V_993 , & V_173 ) ;
if ( ! ( V_993 -> V_328 & V_1307 ) ) {
F_65 ( ! V_993 -> V_1308 && V_993 -> V_1309 ,
L_252 ) ;
F_65 ( V_993 -> V_1308 && ! V_993 -> V_1309 ,
L_253 ) ;
F_65 ( V_993 -> V_1308 != V_87 ,
L_254 ,
V_993 -> V_1308 , V_87 ) ;
}
if ( ! V_65 ) {
F_65 ( V_993 -> V_1309 & ~ V_993 -> V_90 . V_1306 ,
L_255 ,
V_993 -> V_1309 , V_993 -> V_90 . V_1306 ) ;
return;
}
V_1306 = 1 << F_893 ( V_65 ) ;
if ( V_1276 -> V_87 )
F_65 ( ! ( V_993 -> V_1309 & V_1306 ) ,
L_256 ,
F_78 ( F_893 ( V_65 ) ) , V_993 -> V_1309 ) ;
else
F_65 ( V_993 -> V_1309 & V_1306 ,
L_257 ,
F_78 ( F_893 ( V_65 ) ) , V_993 -> V_1309 ) ;
F_65 ( ! ( V_993 -> V_90 . V_1306 & V_1306 ) ,
L_258 ,
V_1306 , V_993 -> V_90 . V_1306 ) ;
F_65 ( V_993 -> V_1308 && memcmp ( & V_993 -> V_90 . V_1310 ,
& V_173 ,
sizeof( V_173 ) ) ,
L_259 ) ;
}
static void
F_894 ( struct V_62 * V_63 , struct V_144 * V_65 ,
struct V_42 * V_441 ,
struct V_42 * V_1302 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_37 * V_562 = F_291 ( V_441 ) ;
struct V_37 * V_1276 = F_291 ( V_1302 ) ;
if ( V_1276 -> V_205 )
F_892 ( V_6 , V_1276 -> V_205 , V_65 , V_1302 ) ;
if ( V_562 -> V_205 &&
V_562 -> V_205 != V_1276 -> V_205 ) {
unsigned V_1306 = 1 << F_893 ( V_65 ) ;
struct V_992 * V_993 = V_562 -> V_205 ;
F_65 ( V_993 -> V_1309 & V_1306 ,
L_260 ,
F_78 ( F_893 ( V_65 ) ) ) ;
F_65 ( V_993 -> V_90 . V_1306 & V_1306 ,
L_261 ,
F_78 ( F_893 ( V_65 ) ) ) ;
}
}
static void
F_895 ( struct V_144 * V_65 ,
struct V_418 * V_43 ,
struct V_42 * V_562 ,
struct V_42 * V_1276 )
{
if ( ! F_25 ( V_1276 ) &&
! F_291 ( V_1276 ) -> V_1311 )
return;
F_881 ( V_65 , V_1276 ) ;
F_888 ( V_65 -> V_63 , V_43 , V_65 ) ;
F_890 ( V_65 , V_562 , V_1276 ) ;
F_894 ( V_65 -> V_63 , V_65 , V_562 , V_1276 ) ;
}
static void
F_896 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_135 ;
for ( V_135 = 0 ; V_135 < V_6 -> V_948 ; V_135 ++ )
F_892 ( V_6 , & V_6 -> V_1312 [ V_135 ] , NULL , NULL ) ;
}
static void
F_897 ( struct V_62 * V_63 ,
struct V_418 * V_43 )
{
F_889 ( V_63 ) ;
F_888 ( V_63 , V_43 , NULL ) ;
F_896 ( V_63 ) ;
}
static void F_898 ( struct V_81 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
if ( F_56 ( V_6 ) ) {
const struct V_519 * V_91 = & V_65 -> V_90 -> V_64 . V_91 ;
int V_894 ;
V_894 = V_91 -> V_878 ;
if ( V_91 -> V_328 & V_881 )
V_894 /= 2 ;
V_65 -> V_224 = V_894 - 1 ;
} else if ( F_23 ( V_6 ) &&
F_38 ( V_65 -> V_90 , V_208 ) ) {
V_65 -> V_224 = 2 ;
} else
V_65 -> V_224 = 1 ;
}
static void F_899 ( struct V_418 * V_43 )
{
struct V_62 * V_63 = V_43 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_1313 * V_205 = NULL ;
struct V_144 * V_65 ;
struct V_42 * V_60 ;
int V_135 ;
if ( ! V_6 -> V_433 . V_1219 )
return;
F_295 (state, crtc, crtc_state, i) {
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_992 * V_1314 =
F_291 ( V_65 -> V_43 ) -> V_205 ;
if ( ! F_25 ( V_60 ) )
continue;
F_291 ( V_60 ) -> V_205 = NULL ;
if ( ! V_1314 )
continue;
if ( ! V_205 )
V_205 = F_900 ( V_43 ) ;
F_901 ( V_205 , V_1314 , V_81 ) ;
}
}
static int F_902 ( struct V_418 * V_43 )
{
struct V_42 * V_60 ;
struct V_81 * V_81 ;
struct V_144 * V_65 ;
struct V_37 * V_1315 = NULL ;
struct V_37 * V_724 = NULL ;
enum V_94 V_1316 = V_593 , V_1317 = V_593 ;
int V_135 ;
F_295 (state, crtc, crtc_state, i) {
V_81 = F_48 ( V_65 ) ;
if ( ! V_60 -> V_87 || ! F_25 ( V_60 ) )
continue;
if ( V_1315 ) {
V_724 = F_291 ( V_60 ) ;
break;
} else {
V_1315 = F_291 ( V_60 ) ;
V_1316 = V_81 -> V_94 ;
}
}
if ( ! V_1315 )
return 0 ;
F_138 (state->dev, intel_crtc) {
struct V_37 * V_38 ;
V_38 = F_537 ( V_43 , V_81 ) ;
if ( F_194 ( V_38 ) )
return F_242 ( V_38 ) ;
V_38 -> V_589 = V_593 ;
if ( ! V_38 -> V_64 . V_87 ||
F_25 ( & V_38 -> V_64 ) )
continue;
if ( V_1317 != V_593 )
return 0 ;
V_1317 = V_81 -> V_94 ;
}
if ( V_1317 != V_593 )
V_1315 -> V_589 = V_1317 ;
else if ( V_724 )
V_724 -> V_589 = V_1316 ;
return 0 ;
}
static int F_903 ( struct V_418 * V_43 )
{
struct V_144 * V_65 ;
struct V_42 * V_60 ;
int V_360 = 0 ;
F_238 (state->dev, crtc) {
V_60 = F_759 ( V_43 , V_65 ) ;
if ( F_194 ( V_60 ) )
return F_242 ( V_60 ) ;
if ( ! V_60 -> V_87 || F_25 ( V_60 ) )
continue;
V_60 -> V_419 = true ;
V_360 = F_538 ( V_43 , V_65 ) ;
if ( V_360 )
break;
V_360 = F_904 ( V_43 , V_65 ) ;
if ( V_360 )
break;
}
return V_360 ;
}
static int F_905 ( struct V_418 * V_43 )
{
struct V_570 * V_336 = F_296 ( V_43 ) ;
struct V_5 * V_6 = F_41 ( V_43 -> V_63 ) ;
struct V_144 * V_65 ;
struct V_42 * V_60 ;
int V_360 = 0 , V_135 ;
if ( ! F_859 ( V_43 ) ) {
F_161 ( L_262 ) ;
return - V_286 ;
}
V_336 -> V_569 = true ;
V_336 -> V_703 = V_6 -> V_703 ;
F_295 (state, crtc, crtc_state, i) {
if ( V_60 -> V_87 )
V_336 -> V_703 |= 1 << V_135 ;
else
V_336 -> V_703 &= ~ ( 1 << V_135 ) ;
if ( V_60 -> V_87 != V_65 -> V_43 -> V_87 )
V_336 -> V_1318 |= F_906 ( V_65 ) ;
}
if ( V_6 -> V_433 . V_1319 ) {
if ( ! V_336 -> V_1053 )
V_336 -> V_1053 = V_6 -> V_641 . V_52 ;
if ( ! V_336 -> V_1053 )
V_336 -> V_1053 = V_6 -> V_632 ;
V_360 = V_6 -> V_433 . V_1319 ( V_43 ) ;
if ( V_360 < 0 )
return V_360 ;
if ( V_336 -> V_702 != V_6 -> V_638 ||
V_336 -> V_1053 != V_6 -> V_641 . V_52 )
V_360 = F_903 ( V_43 ) ;
if ( V_360 < 0 )
return V_360 ;
F_161 ( L_263 ,
V_336 -> V_644 , V_336 -> V_702 ) ;
} else {
F_296 ( V_43 ) -> V_644 = V_6 -> V_1320 ;
}
F_899 ( V_43 ) ;
if ( F_265 ( V_6 ) )
return F_902 ( V_43 ) ;
return 0 ;
}
static int F_907 ( struct V_418 * V_43 )
{
struct V_62 * V_63 = V_43 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
if ( V_6 -> V_433 . V_1321 )
return V_6 -> V_433 . V_1321 ( V_43 ) ;
return 0 ;
}
static int F_908 ( struct V_62 * V_63 ,
struct V_418 * V_43 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_570 * V_336 = F_296 ( V_43 ) ;
struct V_144 * V_65 ;
struct V_42 * V_60 ;
int V_360 , V_135 ;
bool V_1322 = false ;
V_360 = F_909 ( V_63 , V_43 ) ;
if ( V_360 )
return V_360 ;
F_295 (state, crtc, crtc_state, i) {
struct V_37 * V_38 =
F_291 ( V_60 ) ;
if ( V_60 -> V_414 . V_1323 != V_65 -> V_43 -> V_414 . V_1323 )
V_60 -> V_419 = true ;
if ( ! F_25 ( V_60 ) )
continue;
if ( ! V_60 -> V_506 ) {
V_1322 = true ;
continue;
}
V_360 = F_538 ( V_43 , V_65 ) ;
if ( V_360 )
return V_360 ;
V_360 = F_863 ( V_65 , V_38 ) ;
if ( V_360 ) {
F_853 ( F_48 ( V_65 ) ,
V_38 , L_264 ) ;
return V_360 ;
}
if ( V_428 . V_1324 &&
F_870 ( V_6 ,
F_291 ( V_65 -> V_43 ) ,
V_38 , true ) ) {
V_60 -> V_419 = false ;
F_291 ( V_60 ) -> V_1311 = true ;
}
if ( F_25 ( V_60 ) )
V_1322 = true ;
V_360 = F_904 ( V_43 , V_65 ) ;
if ( V_360 )
return V_360 ;
F_853 ( F_48 ( V_65 ) , V_38 ,
F_25 ( V_60 ) ?
L_265 : L_266 ) ;
}
if ( V_1322 ) {
V_360 = F_905 ( V_43 ) ;
if ( V_360 )
return V_360 ;
} else {
V_336 -> V_644 = V_6 -> V_1320 ;
}
V_360 = F_910 ( V_63 , V_43 ) ;
if ( V_360 )
return V_360 ;
F_911 ( V_6 , V_43 ) ;
return F_907 ( V_43 ) ;
}
static int F_912 ( struct V_62 * V_63 ,
struct V_418 * V_43 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_42 * V_60 ;
struct V_144 * V_65 ;
int V_135 , V_360 ;
F_295 (state, crtc, crtc_state, i) {
if ( V_43 -> V_1325 )
continue;
V_360 = F_349 ( V_65 ) ;
if ( V_360 )
return V_360 ;
if ( F_342 ( & F_48 ( V_65 ) -> V_476 ) >= 2 )
F_821 ( V_6 -> V_480 ) ;
}
V_360 = F_913 ( & V_63 -> V_256 ) ;
if ( V_360 )
return V_360 ;
V_360 = F_914 ( V_63 , V_43 ) ;
F_5 ( & V_63 -> V_256 ) ;
return V_360 ;
}
T_1 F_779 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
if ( ! V_63 -> V_223 )
return F_915 ( & V_65 -> V_64 ) ;
return V_63 -> V_1326 -> V_1327 ( V_63 , V_65 -> V_94 ) ;
}
static void F_916 ( struct V_62 * V_63 ,
struct V_5 * V_6 ,
unsigned V_1306 )
{
unsigned V_1328 [ V_1329 ] ;
enum V_94 V_94 ;
int V_360 ;
if ( ! V_1306 )
return;
F_91 (dev_priv, pipe) {
struct V_81 * V_65 = F_53 ( V_6 ,
V_94 ) ;
if ( ! ( ( 1 << V_94 ) & V_1306 ) )
continue;
V_360 = F_101 ( & V_65 -> V_64 ) ;
if ( F_28 ( V_360 != 0 ) ) {
V_1306 &= ~ ( 1 << V_94 ) ;
continue;
}
V_1328 [ V_94 ] = F_917 ( & V_65 -> V_64 ) ;
}
F_91 (dev_priv, pipe) {
struct V_81 * V_65 = F_53 ( V_6 ,
V_94 ) ;
long V_1330 ;
if ( ! ( ( 1 << V_94 ) & V_1306 ) )
continue;
V_1330 = F_918 ( V_63 -> V_1184 [ V_94 ] . V_1331 ,
V_1328 [ V_94 ] !=
F_917 ( & V_65 -> V_64 ) ,
F_919 ( 50 ) ) ;
F_7 ( ! V_1330 , L_267 , F_78 ( V_94 ) ) ;
F_102 ( & V_65 -> V_64 ) ;
}
}
static bool F_920 ( struct V_37 * V_60 )
{
if ( V_60 -> V_1213 )
return true ;
if ( V_60 -> V_566 )
return true ;
if ( V_60 -> V_572 )
return true ;
return false ;
}
static void F_921 ( struct V_144 * V_65 ,
struct V_418 * V_43 ,
struct V_42 * V_441 ,
unsigned int * V_1332 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_37 * V_38 = F_291 ( V_65 -> V_43 ) ;
bool V_569 = F_25 ( V_65 -> V_43 ) ;
if ( V_569 ) {
F_898 ( V_81 ) ;
V_6 -> V_433 . V_1333 ( V_38 , V_43 ) ;
} else {
F_417 ( F_291 ( V_441 ) ) ;
}
if ( F_413 ( V_43 , V_65 -> V_88 ) ) {
F_922 (
V_81 , V_38 ,
F_236 ( V_65 -> V_88 -> V_43 ) ) ;
}
F_923 ( V_441 ) ;
if ( F_920 ( V_38 ) )
* V_1332 |= F_906 ( V_65 ) ;
}
static void F_924 ( struct V_418 * V_43 ,
unsigned int * V_1332 )
{
struct V_144 * V_65 ;
struct V_42 * V_441 ;
int V_135 ;
F_295 (state, crtc, old_crtc_state, i) {
if ( ! V_65 -> V_43 -> V_87 )
continue;
F_921 ( V_65 , V_43 , V_441 ,
V_1332 ) ;
}
}
static void F_925 ( struct V_418 * V_43 ,
unsigned int * V_1332 )
{
struct V_5 * V_6 = F_41 ( V_43 -> V_63 ) ;
struct V_570 * V_336 = F_296 ( V_43 ) ;
struct V_144 * V_65 ;
struct V_81 * V_81 ;
struct V_42 * V_441 ;
struct V_37 * V_1044 ;
unsigned int V_1334 = 0 ;
bool V_1335 ;
enum V_94 V_94 ;
int V_135 ;
const struct V_1286 * V_1336 [ V_1329 ] = {} ;
F_295 (state, crtc, old_crtc_state, i)
if ( V_65 -> V_43 -> V_87 )
V_1336 [ V_135 ] = & F_291 ( V_441 ) -> V_559 . V_1291 . V_1293 ;
do {
V_1335 = false ;
F_295 (state, crtc, old_crtc_state, i) {
bool V_1337 = false ;
unsigned int V_1338 = F_906 ( V_65 ) ;
V_81 = F_48 ( V_65 ) ;
V_1044 = F_291 ( V_65 -> V_43 ) ;
V_94 = V_81 -> V_94 ;
if ( V_1334 & V_1338 || ! V_1044 -> V_64 . V_87 )
continue;
if ( F_926 ( V_1336 , & V_1044 -> V_559 . V_1291 . V_1293 , V_135 ) )
continue;
V_1334 |= V_1338 ;
V_1336 [ V_135 ] = & V_1044 -> V_559 . V_1291 . V_1293 ;
if ( ! F_887 ( & V_1044 -> V_559 . V_1291 . V_1293 ,
& F_291 ( V_441 ) -> V_559 . V_1291 . V_1293 ) &&
! V_65 -> V_43 -> V_1339 &&
V_336 -> V_1340 . V_1341 != V_1334 )
V_1337 = true ;
F_921 ( V_65 , V_43 , V_441 ,
V_1332 ) ;
if ( V_1337 )
F_343 ( V_6 , V_94 ) ;
V_1335 = true ;
}
} while ( V_1335 );
}
static void F_927 ( struct V_418 * V_43 )
{
struct V_62 * V_63 = V_43 -> V_63 ;
struct V_570 * V_336 = F_296 ( V_43 ) ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_42 * V_441 ;
struct V_144 * V_65 ;
struct V_37 * V_1342 ;
bool V_1343 = V_336 -> V_569 ;
unsigned long V_1344 [ V_1329 ] = {} ;
unsigned V_1332 = 0 ;
int V_135 ;
F_928 ( V_43 ) ;
if ( V_336 -> V_569 )
F_473 ( V_6 , V_1345 ) ;
F_295 (state, crtc, old_crtc_state, i) {
struct V_81 * V_81 = F_48 ( V_65 ) ;
if ( F_25 ( V_65 -> V_43 ) ||
F_291 ( V_65 -> V_43 ) -> V_1311 ) {
V_1343 = true ;
V_1344 [ F_48 ( V_65 ) -> V_94 ] =
F_471 ( V_65 ,
F_291 ( V_65 -> V_43 ) ) ;
}
if ( ! F_25 ( V_65 -> V_43 ) )
continue;
F_417 ( F_291 ( V_441 ) ) ;
if ( V_441 -> V_87 ) {
F_420 ( V_65 , V_441 -> V_339 ) ;
V_6 -> V_433 . V_715 ( F_291 ( V_441 ) , V_43 ) ;
V_81 -> V_87 = false ;
F_540 ( V_81 ) ;
F_541 ( V_81 ) ;
F_408 ( V_6 ) ;
F_409 ( V_6 ) ;
if ( ! V_65 -> V_43 -> V_87 ) {
if ( V_6 -> V_433 . V_1346 )
V_6 -> V_433 . V_574 ( V_336 ,
F_291 ( V_65 -> V_43 ) ) ;
else
F_415 ( V_81 ) ;
}
}
}
F_865 ( V_43 ) ;
if ( V_336 -> V_569 ) {
F_929 ( V_43 -> V_63 , V_43 ) ;
if ( V_6 -> V_433 . V_1347 &&
( V_336 -> V_702 != V_6 -> V_638 ||
V_336 -> V_1053 != V_6 -> V_641 . V_52 ) )
V_6 -> V_433 . V_1347 ( V_43 ) ;
if ( ! F_930 ( V_43 ) )
F_931 ( V_6 ) ;
F_897 ( V_63 , V_43 ) ;
}
F_295 (state, crtc, old_crtc_state, i) {
bool V_569 = F_25 ( V_65 -> V_43 ) ;
if ( V_569 && ! V_65 -> V_43 -> V_87 && V_65 -> V_43 -> V_477 ) {
F_312 ( & V_63 -> V_439 ) ;
F_345 ( V_65 , V_65 -> V_43 -> V_477 ) ;
F_313 ( & V_63 -> V_439 ) ;
V_65 -> V_43 -> V_477 = NULL ;
}
}
V_6 -> V_433 . V_1348 ( V_43 , & V_1332 ) ;
if ( ! V_43 -> V_1325 )
F_916 ( V_63 , V_6 , V_1332 ) ;
F_295 (state, crtc, old_crtc_state, i) {
V_1342 = F_291 ( V_65 -> V_43 ) ;
if ( V_6 -> V_433 . V_1214 )
V_6 -> V_433 . V_1214 ( V_336 ,
V_1342 ) ;
}
F_295 (state, crtc, old_crtc_state, i) {
F_412 ( F_291 ( V_441 ) ) ;
if ( V_1344 [ V_135 ] )
F_474 ( V_6 , V_1344 [ V_135 ] ) ;
F_895 ( V_65 , V_43 , V_441 , V_65 -> V_43 ) ;
}
if ( V_336 -> V_569 && F_930 ( V_43 ) )
F_932 ( V_6 ) ;
F_933 ( V_43 ) ;
if ( V_336 -> V_569 )
F_86 ( V_6 , V_1345 ) ;
F_3 ( & V_63 -> V_256 ) ;
F_934 ( V_63 , V_43 ) ;
F_5 ( & V_63 -> V_256 ) ;
F_935 ( V_43 ) ;
F_306 ( V_43 ) ;
F_936 ( V_6 ) ;
}
static void F_937 ( struct V_1139 * V_2 )
{
struct V_418 * V_43 =
F_769 ( V_2 , struct V_418 , V_1349 ) ;
F_927 ( V_43 ) ;
}
static int T_10
F_938 ( struct V_1350 * V_1351 ,
enum V_1352 V_1353 )
{
struct V_570 * V_43 =
F_769 ( V_1351 , struct V_570 , V_1354 ) ;
switch ( V_1353 ) {
case V_1355 :
if ( V_43 -> V_64 . V_1349 . V_4 )
F_348 ( V_1198 , & V_43 -> V_64 . V_1349 ) ;
break;
case V_1356 :
{
struct V_1357 * V_1358 =
& F_41 ( V_43 -> V_64 . V_63 ) -> V_1359 ;
if ( F_939 ( & V_43 -> V_1360 , & V_1358 -> V_1361 ) )
F_940 ( & V_1358 -> V_1192 ) ;
break;
}
}
return V_1362 ;
}
static void F_941 ( struct V_418 * V_43 )
{
struct V_333 * V_1206 ;
struct V_331 * V_133 ;
int V_135 ;
F_942 (state, plane, old_plane_state, i)
F_830 ( F_189 ( V_1206 -> V_89 ) ,
F_189 ( V_133 -> V_43 -> V_89 ) ,
F_235 ( V_133 ) -> V_352 ) ;
}
static int F_943 ( struct V_62 * V_63 ,
struct V_418 * V_43 ,
bool V_1363 )
{
struct V_570 * V_336 = F_296 ( V_43 ) ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_360 = 0 ;
V_360 = F_944 ( V_43 , V_1363 ) ;
if ( V_360 )
return V_360 ;
F_945 ( V_43 ) ;
F_946 ( & V_336 -> V_1354 ,
F_938 ) ;
V_360 = F_912 ( V_63 , V_43 ) ;
if ( V_360 ) {
F_838 ( L_268 , V_360 ) ;
F_947 ( & V_336 -> V_1354 ) ;
return V_360 ;
}
F_948 ( V_43 , true ) ;
V_6 -> V_559 . V_1364 = false ;
F_949 ( V_43 ) ;
F_941 ( V_43 ) ;
if ( V_336 -> V_569 ) {
memcpy ( V_6 -> V_700 , V_336 -> V_700 ,
sizeof( V_336 -> V_700 ) ) ;
V_6 -> V_703 = V_336 -> V_703 ;
V_6 -> V_1320 = V_336 -> V_644 ;
}
F_945 ( V_43 ) ;
F_820 ( & V_43 -> V_1349 ,
V_1363 ? F_937 : NULL ) ;
F_947 ( & V_336 -> V_1354 ) ;
if ( ! V_1363 ) {
F_950 ( & V_336 -> V_1354 ) ;
F_927 ( V_43 ) ;
}
return 0 ;
}
void F_951 ( struct V_144 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_418 * V_43 ;
struct V_42 * V_60 ;
int V_360 ;
V_43 = F_536 ( V_63 ) ;
if ( ! V_43 ) {
F_161 ( L_269 ,
V_65 -> V_64 . V_377 , V_65 -> V_12 ) ;
return;
}
V_43 -> V_431 = F_833 ( V_65 ) ;
V_461:
V_60 = F_759 ( V_43 , V_65 ) ;
V_360 = F_544 ( V_60 ) ;
if ( ! V_360 ) {
if ( ! V_60 -> V_87 )
goto V_937;
V_60 -> V_419 = true ;
V_360 = F_297 ( V_43 ) ;
}
if ( V_360 == - V_421 ) {
F_834 ( V_43 ) ;
F_303 ( V_43 -> V_431 ) ;
goto V_461;
}
V_937:
F_306 ( V_43 ) ;
}
static int F_952 ( struct V_144 * V_65 ,
T_4 * V_1365 , T_4 * V_1366 , T_4 * V_1367 ,
T_2 V_240 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_1111 * V_90 = & V_63 -> V_426 ;
struct V_42 * V_43 ;
int V_360 ;
V_360 = F_953 ( V_65 , V_1365 , V_1366 , V_1367 , V_240 ) ;
if ( V_360 )
return V_360 ;
V_43 = V_65 -> V_43 ;
F_954 ( & V_65 -> V_64 ,
V_90 -> V_1368 ,
( V_43 -> V_1369 ) ?
V_43 -> V_1369 -> V_64 . V_377 : 0 ) ;
F_954 ( & V_65 -> V_64 ,
V_90 -> V_1370 ,
( V_43 -> V_1371 ) ?
V_43 -> V_1371 -> V_64 . V_377 : 0 ) ;
F_954 ( & V_65 -> V_64 ,
V_90 -> V_1372 ,
( V_43 -> V_1373 ) ?
V_43 -> V_1373 -> V_64 . V_377 : 0 ) ;
return 0 ;
}
int
F_955 ( struct V_331 * V_133 ,
struct V_333 * V_1276 )
{
struct V_570 * V_336 =
F_296 ( V_1276 -> V_43 ) ;
struct V_5 * V_6 = F_41 ( V_133 -> V_63 ) ;
struct V_244 * V_89 = V_1276 -> V_89 ;
struct V_252 * V_253 = F_189 ( V_89 ) ;
struct V_252 * V_1374 = F_189 ( V_133 -> V_43 -> V_89 ) ;
int V_360 ;
if ( ! V_253 && ! V_1374 )
return 0 ;
if ( V_1374 ) {
struct V_42 * V_60 =
F_956 ( V_1276 -> V_43 ,
V_133 -> V_43 -> V_65 ) ;
if ( F_25 ( V_60 ) ) {
V_360 = F_957 ( & V_336 -> V_1354 ,
V_1374 -> V_1375 , NULL ,
false , 0 ,
V_722 ) ;
if ( V_360 < 0 )
return V_360 ;
}
}
if ( V_1276 -> V_1351 ) {
V_360 = F_958 ( & V_336 -> V_1354 ,
V_1276 -> V_1351 ,
V_1376 ,
V_722 ) ;
if ( V_360 < 0 )
return V_360 ;
}
if ( ! V_253 )
return 0 ;
if ( ! V_1276 -> V_1351 ) {
V_360 = F_957 ( & V_336 -> V_1354 ,
V_253 -> V_1375 , NULL ,
false , V_1376 ,
V_722 ) ;
if ( V_360 < 0 )
return V_360 ;
F_829 ( V_253 , 0 , V_1203 ) ;
}
if ( V_133 -> type == V_1212 &&
F_184 ( V_6 ) -> V_1377 ) {
int V_1378 = F_141 ( V_6 ) ? 16 * 1024 : 256 ;
V_360 = F_959 ( V_253 , V_1378 ) ;
if ( V_360 ) {
F_161 ( L_270 ) ;
return V_360 ;
}
} else {
struct V_251 * V_254 ;
V_254 = F_188 ( V_89 , V_1276 -> V_245 ) ;
if ( F_194 ( V_254 ) ) {
F_161 ( L_271 ) ;
return F_242 ( V_254 ) ;
}
F_236 ( V_1276 ) -> V_254 = V_254 ;
}
return 0 ;
}
void
F_960 ( struct V_331 * V_133 ,
struct V_333 * V_562 )
{
struct V_251 * V_254 ;
V_254 = F_961 ( & F_236 ( V_562 ) -> V_254 ) ;
if ( V_254 )
F_200 ( V_254 ) ;
}
int
F_962 ( struct V_81 * V_81 , struct V_37 * V_60 )
{
int V_1379 ;
int V_92 , V_644 ;
if ( ! V_81 || ! V_60 -> V_64 . V_506 )
return V_1380 ;
V_92 = V_60 -> V_64 . V_91 . V_92 ;
V_644 = F_296 ( V_60 -> V_64 . V_43 ) -> V_644 ;
if ( F_45 ( ! V_92 || V_644 < V_92 ) )
return V_1380 ;
V_1379 = V_58 ( ( 1 << 16 ) * 3 - 1 , ( 1 << 8 ) * ( ( V_644 << 8 ) / V_92 ) ) ;
return V_1379 ;
}
static int
F_963 ( struct V_331 * V_133 ,
struct V_37 * V_60 ,
struct V_263 * V_43 )
{
struct V_5 * V_6 = F_41 ( V_133 -> V_63 ) ;
struct V_144 * V_65 = V_43 -> V_64 . V_65 ;
int V_1381 = V_1380 ;
int V_1379 = V_1380 ;
bool V_1382 = false ;
int V_360 ;
if ( F_59 ( V_6 ) >= 9 ) {
if ( V_43 -> V_544 . V_328 == V_545 ) {
V_1381 = 1 ;
V_1379 = F_962 ( F_48 ( V_65 ) , V_60 ) ;
}
V_1382 = true ;
}
V_360 = F_964 ( & V_43 -> V_64 ,
& V_43 -> V_1383 ,
V_1381 , V_1379 ,
V_1382 , true ) ;
if ( V_360 )
return V_360 ;
if ( ! V_43 -> V_64 . V_89 )
return 0 ;
if ( F_59 ( V_6 ) >= 9 ) {
V_360 = F_251 ( V_43 ) ;
if ( V_360 )
return V_360 ;
}
return 0 ;
}
static void F_965 ( struct V_144 * V_65 ,
struct V_42 * V_441 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_37 * V_1342 =
F_291 ( V_65 -> V_43 ) ;
struct V_37 * V_1384 =
F_291 ( V_441 ) ;
struct V_570 * V_571 =
F_296 ( V_441 -> V_43 ) ;
bool V_569 = F_25 ( V_65 -> V_43 ) ;
F_807 ( V_81 ) ;
if ( V_569 )
goto V_937;
if ( V_65 -> V_43 -> V_1220 || F_291 ( V_65 -> V_43 ) -> V_1311 ) {
F_449 ( V_65 -> V_43 ) ;
F_440 ( V_65 -> V_43 ) ;
}
if ( V_1342 -> V_1311 )
F_321 ( V_81 , V_1384 ) ;
else if ( F_59 ( V_6 ) >= 9 )
F_273 ( V_81 ) ;
V_937:
if ( V_6 -> V_433 . V_1346 )
V_6 -> V_433 . V_1346 ( V_571 ,
V_1342 ) ;
}
static void F_966 ( struct V_144 * V_65 ,
struct V_42 * V_441 )
{
struct V_81 * V_81 = F_48 ( V_65 ) ;
F_808 ( V_81 , NULL ) ;
}
void F_967 ( struct V_331 * V_133 )
{
F_968 ( V_133 ) ;
F_237 ( F_235 ( V_133 ) ) ;
}
static struct V_335 *
F_969 ( struct V_5 * V_6 , enum V_94 V_94 )
{
struct V_335 * V_88 = NULL ;
struct V_263 * V_43 = NULL ;
const T_2 * V_1385 ;
unsigned int V_1386 ;
unsigned int V_1387 ;
int V_360 ;
V_88 = F_551 ( sizeof( * V_88 ) , V_722 ) ;
if ( ! V_88 ) {
V_360 = - V_721 ;
goto V_784;
}
V_43 = F_970 ( & V_88 -> V_64 ) ;
if ( ! V_43 ) {
V_360 = - V_721 ;
goto V_784;
}
V_88 -> V_64 . V_43 = & V_43 -> V_64 ;
V_88 -> V_1388 = false ;
V_88 -> V_1389 = 1 ;
if ( F_59 ( V_6 ) >= 9 ) {
V_88 -> V_1388 = true ;
V_43 -> V_404 = - 1 ;
}
V_88 -> V_94 = V_94 ;
if ( F_971 ( V_6 ) && F_59 ( V_6 ) < 4 )
V_88 -> V_133 = (enum V_133 ) ! V_94 ;
else
V_88 -> V_133 = (enum V_133 ) V_94 ;
V_88 -> V_352 = F_972 ( V_94 ) ;
V_88 -> V_1390 = F_963 ;
if ( F_59 ( V_6 ) >= 9 ) {
V_1385 = V_1391 ;
V_1387 = F_179 ( V_1391 ) ;
V_88 -> V_417 = F_278 ;
V_88 -> V_340 = F_286 ;
} else if ( F_15 ( V_6 ) ) {
V_1385 = V_1392 ;
V_1387 = F_179 ( V_1392 ) ;
V_88 -> V_417 = F_264 ;
V_88 -> V_340 = F_263 ;
} else if ( F_59 ( V_6 ) >= 4 ) {
V_1385 = V_1392 ;
V_1387 = F_179 ( V_1392 ) ;
V_88 -> V_417 = F_252 ;
V_88 -> V_340 = F_263 ;
} else {
V_1385 = V_1393 ;
V_1387 = F_179 ( V_1393 ) ;
V_88 -> V_417 = F_252 ;
V_88 -> V_340 = F_263 ;
}
if ( F_59 ( V_6 ) >= 9 )
V_360 = F_973 ( & V_6 -> V_422 , & V_88 -> V_64 ,
0 , & V_1394 ,
V_1385 , V_1387 ,
V_1395 ,
L_272 , F_78 ( V_94 ) ) ;
else if ( F_59 ( V_6 ) >= 5 || F_18 ( V_6 ) )
V_360 = F_973 ( & V_6 -> V_422 , & V_88 -> V_64 ,
0 , & V_1394 ,
V_1385 , V_1387 ,
V_1395 ,
L_273 , F_78 ( V_94 ) ) ;
else
V_360 = F_973 ( & V_6 -> V_422 , & V_88 -> V_64 ,
0 , & V_1394 ,
V_1385 , V_1387 ,
V_1395 ,
L_274 , F_89 ( V_88 -> V_133 ) ) ;
if ( V_360 )
goto V_784;
if ( F_59 ( V_6 ) >= 9 ) {
V_1386 =
V_287 | V_398 |
V_368 | V_294 ;
} else if ( F_17 ( V_6 ) && V_94 == V_120 ) {
V_1386 =
V_287 | V_368 |
V_370 ;
} else if ( F_59 ( V_6 ) >= 4 ) {
V_1386 =
V_287 | V_368 ;
} else {
V_1386 = V_287 ;
}
if ( F_59 ( V_6 ) >= 4 )
F_974 ( & V_88 -> V_64 ,
V_287 ,
V_1386 ) ;
F_975 ( & V_88 -> V_64 , & V_1396 ) ;
return V_88 ;
V_784:
F_237 ( V_43 ) ;
F_237 ( V_88 ) ;
return F_736 ( V_360 ) ;
}
static int
F_976 ( struct V_331 * V_133 ,
struct V_37 * V_60 ,
struct V_263 * V_43 )
{
struct V_244 * V_89 = V_43 -> V_64 . V_89 ;
struct V_252 * V_253 = F_189 ( V_89 ) ;
enum V_94 V_94 = F_235 ( V_133 ) -> V_94 ;
unsigned V_290 ;
int V_360 ;
V_360 = F_964 ( & V_43 -> V_64 ,
& V_43 -> V_1383 ,
V_1380 ,
V_1380 ,
true , true ) ;
if ( V_360 )
return V_360 ;
if ( ! V_253 )
return 0 ;
if ( ! F_734 ( F_41 ( V_133 -> V_63 ) , V_43 -> V_64 . V_347 ,
V_43 -> V_64 . V_348 ) ) {
F_220 ( L_275 ,
V_43 -> V_64 . V_347 , V_43 -> V_64 . V_348 ) ;
return - V_286 ;
}
V_290 = F_728 ( V_43 -> V_64 . V_347 ) * 4 ;
if ( V_253 -> V_64 . V_240 < V_290 * V_43 -> V_64 . V_348 ) {
F_161 ( L_276 ) ;
return - V_721 ;
}
if ( V_89 -> V_257 != V_229 ) {
F_161 ( L_277 ) ;
return - V_286 ;
}
if ( F_17 ( F_41 ( V_133 -> V_63 ) ) && V_94 == V_509 &&
V_43 -> V_64 . V_338 && V_43 -> V_64 . V_345 < 0 ) {
F_161 ( L_278 ) ;
return - V_286 ;
}
return 0 ;
}
static void
F_977 ( struct V_331 * V_133 ,
struct V_144 * V_65 )
{
struct V_81 * V_81 = F_48 ( V_65 ) ;
V_81 -> V_1102 = 0 ;
F_732 ( V_65 , NULL ) ;
}
static void
F_978 ( struct V_331 * V_133 ,
const struct V_37 * V_60 ,
const struct V_263 * V_43 )
{
struct V_144 * V_65 = V_60 -> V_64 . V_65 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_5 * V_6 = F_41 ( V_133 -> V_63 ) ;
struct V_252 * V_253 = F_189 ( V_43 -> V_64 . V_89 ) ;
T_2 V_1183 ;
if ( ! V_253 )
V_1183 = 0 ;
else if ( ! F_184 ( V_6 ) -> V_1377 )
V_1183 = F_239 ( V_43 ) ;
else
V_1183 = V_253 -> V_1397 -> V_1398 ;
V_81 -> V_1102 = V_1183 ;
F_732 ( V_65 , V_43 ) ;
}
static struct V_335 *
F_979 ( struct V_5 * V_6 , enum V_94 V_94 )
{
struct V_335 * V_1399 = NULL ;
struct V_263 * V_43 = NULL ;
int V_360 ;
V_1399 = F_551 ( sizeof( * V_1399 ) , V_722 ) ;
if ( ! V_1399 ) {
V_360 = - V_721 ;
goto V_784;
}
V_43 = F_970 ( & V_1399 -> V_64 ) ;
if ( ! V_43 ) {
V_360 = - V_721 ;
goto V_784;
}
V_1399 -> V_64 . V_43 = & V_43 -> V_64 ;
V_1399 -> V_1388 = false ;
V_1399 -> V_1389 = 1 ;
V_1399 -> V_94 = V_94 ;
V_1399 -> V_133 = V_94 ;
V_1399 -> V_352 = F_980 ( V_94 ) ;
V_1399 -> V_1390 = F_976 ;
V_1399 -> V_417 = F_978 ;
V_1399 -> V_340 = F_977 ;
V_360 = F_973 ( & V_6 -> V_422 , & V_1399 -> V_64 ,
0 , & V_1394 ,
V_1400 ,
F_179 ( V_1400 ) ,
V_1212 ,
L_279 , F_78 ( V_94 ) ) ;
if ( V_360 )
goto V_784;
if ( F_59 ( V_6 ) >= 4 )
F_974 ( & V_1399 -> V_64 ,
V_287 ,
V_287 |
V_368 ) ;
if ( F_59 ( V_6 ) >= 9 )
V_43 -> V_404 = - 1 ;
F_975 ( & V_1399 -> V_64 , & V_1396 ) ;
return V_1399 ;
V_784:
F_237 ( V_43 ) ;
F_237 ( V_1399 ) ;
return F_736 ( V_360 ) ;
}
static void F_726 ( struct V_5 * V_6 ,
struct V_81 * V_65 ,
struct V_37 * V_60 )
{
struct V_378 * V_379 =
& V_60 -> V_379 ;
int V_135 ;
for ( V_135 = 0 ; V_135 < V_65 -> V_380 ; V_135 ++ ) {
struct V_1401 * V_1402 = & V_379 -> V_381 [ V_135 ] ;
V_1402 -> V_382 = 0 ;
V_1402 -> V_414 = V_1403 ;
}
V_379 -> V_404 = - 1 ;
}
static int F_981 ( struct V_5 * V_6 , enum V_94 V_94 )
{
struct V_81 * V_81 ;
struct V_37 * V_60 = NULL ;
struct V_335 * V_88 = NULL ;
struct V_335 * V_1399 = NULL ;
int V_139 , V_360 ;
V_81 = F_551 ( sizeof( * V_81 ) , V_722 ) ;
if ( ! V_81 )
return - V_721 ;
V_60 = F_551 ( sizeof( * V_60 ) , V_722 ) ;
if ( ! V_60 ) {
V_360 = - V_721 ;
goto V_784;
}
V_81 -> V_90 = V_60 ;
V_81 -> V_64 . V_43 = & V_60 -> V_64 ;
V_60 -> V_64 . V_65 = & V_81 -> V_64 ;
if ( F_59 ( V_6 ) >= 9 ) {
if ( V_94 == V_509 )
V_81 -> V_380 = 1 ;
else
V_81 -> V_380 = V_1404 ;
F_726 ( V_6 , V_81 , V_60 ) ;
}
V_88 = F_969 ( V_6 , V_94 ) ;
if ( F_194 ( V_88 ) ) {
V_360 = F_242 ( V_88 ) ;
goto V_784;
}
F_93 (dev_priv, pipe, sprite) {
struct V_335 * V_133 ;
V_133 = F_982 ( V_6 , V_94 , V_139 ) ;
if ( F_194 ( V_133 ) ) {
V_360 = F_242 ( V_133 ) ;
goto V_784;
}
}
V_1399 = F_979 ( V_6 , V_94 ) ;
if ( F_194 ( V_1399 ) ) {
V_360 = F_242 ( V_1399 ) ;
goto V_784;
}
V_360 = F_983 ( & V_6 -> V_422 , & V_81 -> V_64 ,
& V_88 -> V_64 , & V_1399 -> V_64 ,
& V_1405 ,
L_280 , F_78 ( V_94 ) ) ;
if ( V_360 )
goto V_784;
V_81 -> V_94 = V_94 ;
V_81 -> V_133 = V_88 -> V_133 ;
V_81 -> V_1093 = ~ 0 ;
V_81 -> V_1092 = ~ 0 ;
V_81 -> V_1094 = ~ 0 ;
V_81 -> V_559 . V_565 = true ;
F_660 ( V_94 >= F_179 ( V_6 -> V_1406 ) ||
V_6 -> V_1406 [ V_81 -> V_133 ] != NULL ) ;
V_6 -> V_1406 [ V_81 -> V_133 ] = V_81 ;
V_6 -> V_1407 [ V_81 -> V_94 ] = V_81 ;
F_984 ( & V_81 -> V_64 , & V_1408 ) ;
F_985 ( & V_81 -> V_64 ) ;
F_28 ( F_893 ( & V_81 -> V_64 ) != V_81 -> V_94 ) ;
return 0 ;
V_784:
F_237 ( V_60 ) ;
F_237 ( V_81 ) ;
return V_360 ;
}
enum V_94 F_986 ( struct V_718 * V_719 )
{
struct V_619 * V_511 = V_719 -> V_64 . V_511 ;
struct V_62 * V_63 = V_719 -> V_64 . V_63 ;
F_28 ( ! F_987 ( & V_63 -> V_426 . V_1114 ) ) ;
if ( ! V_511 || F_28 ( ! V_511 -> V_65 ) )
return V_593 ;
return F_48 ( V_511 -> V_65 ) -> V_94 ;
}
int F_988 ( struct V_62 * V_63 , void * V_1046 ,
struct V_1409 * V_1410 )
{
struct V_1411 * V_1412 = V_1046 ;
struct V_144 * V_1413 ;
struct V_81 * V_65 ;
V_1413 = F_989 ( V_63 , V_1412 -> V_1414 ) ;
if ( ! V_1413 )
return - V_1415 ;
V_65 = F_48 ( V_1413 ) ;
V_1412 -> V_94 = V_65 -> V_94 ;
return 0 ;
}
static int F_990 ( struct V_510 * V_511 )
{
struct V_62 * V_63 = V_511 -> V_64 . V_63 ;
struct V_510 * V_1218 ;
int V_1416 = 0 ;
int V_1417 = 0 ;
F_658 (dev, source_encoder) {
if ( F_839 ( V_511 , V_1218 ) )
V_1416 |= ( 1 << V_1417 ) ;
V_1417 ++ ;
}
return V_1416 ;
}
static bool F_991 ( struct V_5 * V_6 )
{
if ( ! F_140 ( V_6 ) )
return false ;
if ( ( F_11 ( V_1418 ) & V_1419 ) == 0 )
return false ;
if ( F_24 ( V_6 ) && ( F_11 ( V_636 ) & V_1420 ) )
return false ;
return true ;
}
static bool F_992 ( struct V_5 * V_6 )
{
if ( F_59 ( V_6 ) >= 9 )
return false ;
if ( F_570 ( V_6 ) || F_481 ( V_6 ) )
return false ;
if ( F_17 ( V_6 ) )
return false ;
if ( F_993 ( V_6 ) &&
F_11 ( V_1421 ) & V_1422 )
return false ;
if ( F_23 ( V_6 ) && F_11 ( F_994 ( V_602 ) ) & V_1423 )
return false ;
if ( ! V_6 -> V_803 . V_1424 )
return false ;
return true ;
}
void F_310 ( struct V_5 * V_6 )
{
int V_1425 ;
int V_1426 ;
if ( F_23 ( V_6 ) )
return;
if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
V_1425 = 2 ;
else
V_1425 = 1 ;
for ( V_1426 = 0 ; V_1426 < V_1425 ; V_1426 ++ ) {
T_1 V_15 = F_11 ( F_76 ( V_1426 ) ) ;
V_15 = ( V_15 & ~ V_123 ) | V_124 ;
F_124 ( F_76 ( V_1426 ) , V_15 ) ;
}
}
static void F_995 ( struct V_5 * V_6 )
{
if ( F_15 ( V_6 ) || F_36 ( V_6 ) )
V_6 -> V_1427 = V_1428 ;
else if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
V_6 -> V_1427 = V_1429 ;
else
V_6 -> V_1427 = V_1430 ;
F_310 ( V_6 ) ;
}
static void F_996 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_510 * V_511 ;
bool V_1431 = false ;
F_995 ( V_6 ) ;
F_997 ( V_63 ) ;
if ( F_992 ( V_6 ) )
F_998 ( V_63 ) ;
if ( F_36 ( V_6 ) ) {
F_999 ( V_63 , V_602 ) ;
F_999 ( V_63 , V_197 ) ;
F_999 ( V_63 , V_199 ) ;
F_1000 ( V_63 ) ;
} else if ( F_23 ( V_6 ) ) {
int V_75 ;
V_75 = F_11 ( F_994 ( V_602 ) ) & V_1432 ;
if ( V_75 || F_477 ( V_6 ) || F_478 ( V_6 ) )
F_999 ( V_63 , V_602 ) ;
V_75 = F_11 ( V_1421 ) ;
if ( V_75 & V_1433 )
F_999 ( V_63 , V_197 ) ;
if ( V_75 & V_1434 )
F_999 ( V_63 , V_199 ) ;
if ( V_75 & V_1435 )
F_999 ( V_63 , V_201 ) ;
if ( ( F_477 ( V_6 ) || F_478 ( V_6 ) ) &&
( V_6 -> V_803 . V_1436 [ V_607 ] . V_1437 ||
V_6 -> V_803 . V_1436 [ V_607 ] . V_1438 ||
V_6 -> V_803 . V_1436 [ V_607 ] . V_1439 ) )
F_999 ( V_63 , V_607 ) ;
} else if ( F_15 ( V_6 ) ) {
int V_75 ;
V_1431 = F_1001 ( V_6 , V_201 ) ;
if ( F_991 ( V_6 ) )
F_1002 ( V_63 , V_1418 , V_602 ) ;
if ( F_11 ( V_170 ) & V_1440 ) {
V_75 = F_1003 ( V_63 , V_1441 , V_197 ) ;
if ( ! V_75 )
F_1004 ( V_63 , V_170 , V_197 ) ;
if ( ! V_75 && ( F_11 ( V_163 ) & V_1419 ) )
F_1002 ( V_63 , V_163 , V_197 ) ;
}
if ( F_11 ( V_171 ) & V_1440 )
F_1004 ( V_63 , V_171 , V_199 ) ;
if ( ! V_1431 && F_11 ( V_172 ) & V_1440 )
F_1004 ( V_63 , V_172 , V_201 ) ;
if ( F_11 ( V_165 ) & V_1419 )
F_1002 ( V_63 , V_165 , V_199 ) ;
if ( F_11 ( V_167 ) & V_1419 )
F_1002 ( V_63 , V_167 , V_201 ) ;
} else if ( F_16 ( V_6 ) || F_17 ( V_6 ) ) {
bool V_1442 , V_1443 ;
V_1442 = F_1001 ( V_6 , V_197 ) ;
V_1443 = F_1005 ( V_6 , V_197 ) ;
if ( F_11 ( V_1444 ) & V_1419 || V_1443 )
V_1442 &= F_1002 ( V_63 , V_1444 , V_197 ) ;
if ( ( F_11 ( V_1445 ) & V_1440 || V_1443 ) && ! V_1442 )
F_1004 ( V_63 , V_1445 , V_197 ) ;
V_1442 = F_1001 ( V_6 , V_199 ) ;
V_1443 = F_1005 ( V_6 , V_199 ) ;
if ( F_11 ( V_1446 ) & V_1419 || V_1443 )
V_1442 &= F_1002 ( V_63 , V_1446 , V_199 ) ;
if ( ( F_11 ( V_1447 ) & V_1440 || V_1443 ) && ! V_1442 )
F_1004 ( V_63 , V_1447 , V_199 ) ;
if ( F_17 ( V_6 ) ) {
V_1443 = F_1005 ( V_6 , V_201 ) ;
if ( F_11 ( V_1448 ) & V_1419 || V_1443 )
F_1002 ( V_63 , V_1448 , V_201 ) ;
if ( F_11 ( V_1449 ) & V_1440 || V_1443 )
F_1004 ( V_63 , V_1449 , V_201 ) ;
}
F_1000 ( V_63 ) ;
} else if ( ! F_56 ( V_6 ) && ! F_19 ( V_6 ) ) {
bool V_75 = false ;
if ( F_11 ( V_1450 ) & V_1440 ) {
F_161 ( L_281 ) ;
V_75 = F_1003 ( V_63 , V_1450 , V_197 ) ;
if ( ! V_75 && F_18 ( V_6 ) ) {
F_161 ( L_282 ) ;
F_1004 ( V_63 , V_1451 , V_197 ) ;
}
if ( ! V_75 && F_18 ( V_6 ) )
F_1002 ( V_63 , V_1452 , V_197 ) ;
}
if ( F_11 ( V_1450 ) & V_1440 ) {
F_161 ( L_283 ) ;
V_75 = F_1003 ( V_63 , V_1453 , V_199 ) ;
}
if ( ! V_75 && ( F_11 ( V_1453 ) & V_1440 ) ) {
if ( F_18 ( V_6 ) ) {
F_161 ( L_284 ) ;
F_1004 ( V_63 , V_1454 , V_199 ) ;
}
if ( F_18 ( V_6 ) )
F_1002 ( V_63 , V_1455 , V_199 ) ;
}
if ( F_18 ( V_6 ) && ( F_11 ( V_1456 ) & V_1419 ) )
F_1002 ( V_63 , V_1456 , V_201 ) ;
} else if ( F_56 ( V_6 ) )
F_1006 ( V_63 ) ;
if ( F_1007 ( V_6 ) )
F_1008 ( V_63 ) ;
F_1009 ( V_63 ) ;
F_658 (dev, encoder) {
V_511 -> V_64 . V_1115 = V_511 -> V_1306 ;
V_511 -> V_64 . V_1457 =
F_990 ( V_511 ) ;
}
F_670 ( V_63 ) ;
F_1010 ( V_63 ) ;
}
static void F_1011 ( struct V_244 * V_89 )
{
struct V_62 * V_63 = V_89 -> V_63 ;
struct V_264 * V_265 = F_182 ( V_89 ) ;
F_1012 ( V_89 ) ;
F_3 ( & V_63 -> V_256 ) ;
F_28 ( ! V_265 -> V_253 -> V_1458 -- ) ;
F_230 ( V_265 -> V_253 ) ;
F_5 ( & V_63 -> V_256 ) ;
F_237 ( V_265 ) ;
}
static int F_1013 ( struct V_244 * V_89 ,
struct V_1409 * V_1410 ,
unsigned int * V_1459 )
{
struct V_264 * V_265 = F_182 ( V_89 ) ;
struct V_252 * V_253 = V_265 -> V_253 ;
if ( V_253 -> V_1460 . V_557 ) {
F_220 ( L_285 ) ;
return - V_286 ;
}
return F_1014 ( V_1410 , & V_253 -> V_64 , V_1459 ) ;
}
static int F_1015 ( struct V_244 * V_89 ,
struct V_1409 * V_1410 ,
unsigned V_328 , unsigned V_1461 ,
struct V_1462 * V_1463 ,
unsigned V_1464 )
{
struct V_62 * V_63 = V_89 -> V_63 ;
struct V_264 * V_265 = F_182 ( V_89 ) ;
struct V_252 * V_253 = V_265 -> V_253 ;
F_3 ( & V_63 -> V_256 ) ;
if ( V_253 -> V_1465 && V_253 -> V_1466 )
F_1016 ( V_253 , true ) ;
F_1017 ( V_253 , false , V_1467 ) ;
F_5 ( & V_63 -> V_256 ) ;
return 0 ;
}
static
T_1 F_1018 ( struct V_5 * V_6 ,
V_55 V_227 , T_2 V_237 )
{
T_1 V_250 = F_184 ( V_6 ) -> V_250 ;
if ( V_250 >= 9 ) {
int V_228 = F_176 ( V_237 , 0 ) ;
return V_58 ( 8192 * V_228 , 32768 ) ;
} else if ( V_250 >= 5 && ! F_16 ( V_6 ) &&
! F_17 ( V_6 ) ) {
return 32 * 1024 ;
} else if ( V_250 >= 4 ) {
if ( V_227 == V_230 )
return 16 * 1024 ;
else
return 32 * 1024 ;
} else if ( V_250 >= 3 ) {
if ( V_227 == V_230 )
return 8 * 1024 ;
else
return 16 * 1024 ;
} else {
return 8 * 1024 ;
}
}
static int F_229 ( struct V_62 * V_63 ,
struct V_264 * V_265 ,
struct V_320 * V_321 ,
struct V_252 * V_253 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
unsigned int V_326 = F_1019 ( V_253 ) ;
int V_360 ;
T_1 V_1468 , V_1469 ;
struct V_1249 V_1250 ;
F_28 ( ! F_190 ( & V_63 -> V_256 ) ) ;
if ( V_321 -> V_328 & V_329 ) {
if ( V_326 != V_281 &&
V_326 != F_214 ( V_321 -> V_257 [ 0 ] ) ) {
F_220 ( L_286 ) ;
return - V_286 ;
}
} else {
if ( V_326 == V_279 ) {
V_321 -> V_257 [ 0 ] = V_230 ;
} else if ( V_326 == V_280 ) {
F_220 ( L_287 ) ;
return - V_286 ;
}
}
switch ( V_321 -> V_257 [ 0 ] ) {
case V_231 :
case V_232 :
if ( F_59 ( V_6 ) < 9 ) {
F_220 ( L_288 ,
V_321 -> V_257 [ 0 ] ) ;
return - V_286 ;
}
case V_229 :
case V_230 :
break;
default:
F_220 ( L_289 ,
V_321 -> V_257 [ 0 ] ) ;
return - V_286 ;
}
if ( F_184 ( V_6 ) -> V_250 < 4 &&
V_326 != F_214 ( V_321 -> V_257 [ 0 ] ) ) {
F_220 ( L_290 ) ;
return - V_286 ;
}
V_1469 = F_268 ( V_6 ,
V_321 -> V_257 [ 0 ] ,
V_321 -> V_237 ) ;
if ( V_321 -> V_260 [ 0 ] & ( V_1469 - 1 ) ) {
F_220 ( L_291 ,
V_321 -> V_260 [ 0 ] , V_1469 ) ;
return - V_286 ;
}
V_1468 = F_1018 ( V_6 , V_321 -> V_257 [ 0 ] ,
V_321 -> V_237 ) ;
if ( V_321 -> V_260 [ 0 ] > V_1468 ) {
F_220 ( L_292 ,
V_321 -> V_257 [ 0 ] != V_229 ?
L_293 : L_294 ,
V_321 -> V_260 [ 0 ] , V_1468 ) ;
return - V_286 ;
}
if ( V_326 != V_281 &&
V_321 -> V_260 [ 0 ] != F_1020 ( V_253 ) ) {
F_220 ( L_295 ,
V_321 -> V_260 [ 0 ] ,
F_1020 ( V_253 ) ) ;
return - V_286 ;
}
switch ( V_321 -> V_237 ) {
case V_296 :
case V_300 :
case V_302 :
case V_314 :
break;
case V_298 :
if ( F_59 ( V_6 ) > 3 ) {
F_220 ( L_296 ,
F_858 ( V_321 -> V_237 , & V_1250 ) ) ;
return - V_286 ;
}
break;
case V_313 :
if ( ! F_16 ( V_6 ) && ! F_17 ( V_6 ) &&
F_59 ( V_6 ) < 9 ) {
F_220 ( L_296 ,
F_858 ( V_321 -> V_237 , & V_1250 ) ) ;
return - V_286 ;
}
break;
case V_304 :
case V_306 :
case V_308 :
if ( F_59 ( V_6 ) < 4 ) {
F_220 ( L_296 ,
F_858 ( V_321 -> V_237 , & V_1250 ) ) ;
return - V_286 ;
}
break;
case V_1470 :
if ( ! F_16 ( V_6 ) && ! F_17 ( V_6 ) ) {
F_220 ( L_296 ,
F_858 ( V_321 -> V_237 , & V_1250 ) ) ;
return - V_286 ;
}
break;
case V_386 :
case V_391 :
case V_389 :
case V_393 :
if ( F_59 ( V_6 ) < 5 ) {
F_220 ( L_296 ,
F_858 ( V_321 -> V_237 , & V_1250 ) ) ;
return - V_286 ;
}
break;
default:
F_220 ( L_296 ,
F_858 ( V_321 -> V_237 , & V_1250 ) ) ;
return - V_286 ;
}
if ( V_321 -> V_278 [ 0 ] != 0 )
return - V_286 ;
F_1021 ( & V_265 -> V_64 , V_321 ) ;
V_265 -> V_253 = V_253 ;
V_360 = F_215 ( V_6 , & V_265 -> V_64 ) ;
if ( V_360 )
return V_360 ;
V_360 = F_1022 ( V_63 , & V_265 -> V_64 , & V_1471 ) ;
if ( V_360 ) {
F_127 ( L_297 , V_360 ) ;
return V_360 ;
}
V_265 -> V_253 -> V_1458 ++ ;
return 0 ;
}
static struct V_244 *
F_1023 ( struct V_62 * V_63 ,
struct V_1409 * V_1472 ,
const struct V_320 * V_1473 )
{
struct V_244 * V_89 ;
struct V_252 * V_253 ;
struct V_320 V_321 = * V_1473 ;
V_253 = F_1024 ( V_1472 , V_321 . V_1474 [ 0 ] ) ;
if ( ! V_253 )
return F_736 ( - V_1415 ) ;
V_89 = F_737 ( V_63 , & V_321 , V_253 ) ;
if ( F_194 ( V_89 ) )
F_230 ( V_253 ) ;
return V_89 ;
}
void F_1025 ( struct V_5 * V_6 )
{
if ( F_184 ( V_6 ) -> V_250 >= 9 ) {
V_6 -> V_433 . V_1304 = F_724 ;
V_6 -> V_433 . V_1475 =
F_681 ;
V_6 -> V_433 . V_1219 =
F_709 ;
V_6 -> V_433 . V_1333 = F_444 ;
V_6 -> V_433 . V_715 = F_456 ;
} else if ( F_23 ( V_6 ) ) {
V_6 -> V_433 . V_1304 = F_724 ;
V_6 -> V_433 . V_1475 =
F_684 ;
V_6 -> V_433 . V_1219 =
F_709 ;
V_6 -> V_433 . V_1333 = F_444 ;
V_6 -> V_433 . V_715 = F_456 ;
} else if ( F_15 ( V_6 ) ) {
V_6 -> V_433 . V_1304 = F_685 ;
V_6 -> V_433 . V_1475 =
F_684 ;
V_6 -> V_433 . V_1219 =
F_674 ;
V_6 -> V_433 . V_1333 = F_432 ;
V_6 -> V_433 . V_715 = F_454 ;
} else if ( F_17 ( V_6 ) ) {
V_6 -> V_433 . V_1304 = F_655 ;
V_6 -> V_433 . V_1475 =
F_653 ;
V_6 -> V_433 . V_1219 = F_649 ;
V_6 -> V_433 . V_1333 = F_523 ;
V_6 -> V_433 . V_715 = F_534 ;
} else if ( F_16 ( V_6 ) ) {
V_6 -> V_433 . V_1304 = F_655 ;
V_6 -> V_433 . V_1475 =
F_653 ;
V_6 -> V_433 . V_1219 = F_650 ;
V_6 -> V_433 . V_1333 = F_523 ;
V_6 -> V_433 . V_715 = F_534 ;
} else if ( F_18 ( V_6 ) ) {
V_6 -> V_433 . V_1304 = F_655 ;
V_6 -> V_433 . V_1475 =
F_653 ;
V_6 -> V_433 . V_1219 = F_646 ;
V_6 -> V_433 . V_1333 = F_532 ;
V_6 -> V_433 . V_715 = F_534 ;
} else if ( F_19 ( V_6 ) ) {
V_6 -> V_433 . V_1304 = F_655 ;
V_6 -> V_433 . V_1475 =
F_653 ;
V_6 -> V_433 . V_1219 = F_647 ;
V_6 -> V_433 . V_1333 = F_532 ;
V_6 -> V_433 . V_715 = F_534 ;
} else if ( ! F_56 ( V_6 ) ) {
V_6 -> V_433 . V_1304 = F_655 ;
V_6 -> V_433 . V_1475 =
F_653 ;
V_6 -> V_433 . V_1219 = F_648 ;
V_6 -> V_433 . V_1333 = F_532 ;
V_6 -> V_433 . V_715 = F_534 ;
} else {
V_6 -> V_433 . V_1304 = F_655 ;
V_6 -> V_433 . V_1475 =
F_653 ;
V_6 -> V_433 . V_1219 = F_645 ;
V_6 -> V_433 . V_1333 = F_532 ;
V_6 -> V_433 . V_715 = F_534 ;
}
if ( F_477 ( V_6 ) || F_478 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_565 ;
else if ( F_36 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_567 ;
else if ( F_266 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_568 ;
else if ( F_265 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_569 ;
else if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_571 ;
else if ( F_24 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_572 ;
else if ( F_635 ( V_6 ) || F_185 ( V_6 ) ||
F_336 ( V_6 ) || F_327 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_573 ;
else if ( F_585 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_587 ;
else if ( F_186 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_588 ;
else if ( F_19 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_576 ;
else if ( F_586 ( V_6 ) || F_18 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_589 ;
else if ( F_562 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_574 ;
else if ( F_636 ( V_6 ) || F_80 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_575 ;
else if ( F_1026 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_578 ;
else if ( F_81 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_579 ;
else if ( F_1027 ( V_6 ) )
V_6 -> V_433 . V_640 =
F_580 ;
else {
F_7 ( ! F_141 ( V_6 ) , L_298 ) ;
V_6 -> V_433 . V_640 =
F_583 ;
}
if ( F_24 ( V_6 ) ) {
V_6 -> V_433 . V_515 = F_328 ;
} else if ( F_336 ( V_6 ) ) {
V_6 -> V_433 . V_515 = F_334 ;
} else if ( F_327 ( V_6 ) ) {
V_6 -> V_433 . V_515 = F_337 ;
} else if ( F_265 ( V_6 ) || F_266 ( V_6 ) ) {
V_6 -> V_433 . V_515 = V_1476 ;
}
if ( F_266 ( V_6 ) ) {
V_6 -> V_433 . V_1347 =
F_706 ;
V_6 -> V_433 . V_1319 =
F_705 ;
} else if ( F_16 ( V_6 ) || F_17 ( V_6 ) ) {
V_6 -> V_433 . V_1347 =
F_522 ;
V_6 -> V_433 . V_1319 =
F_517 ;
} else if ( F_36 ( V_6 ) ) {
V_6 -> V_433 . V_1347 =
F_700 ;
V_6 -> V_433 . V_1319 =
F_518 ;
} else if ( F_477 ( V_6 ) || F_478 ( V_6 ) ) {
V_6 -> V_433 . V_1347 =
F_708 ;
V_6 -> V_433 . V_1319 =
F_707 ;
}
if ( V_6 -> V_1228 . V_250 >= 9 )
V_6 -> V_433 . V_1348 = F_925 ;
else
V_6 -> V_433 . V_1348 = F_924 ;
switch ( F_184 ( V_6 ) -> V_250 ) {
case 2 :
V_6 -> V_433 . V_1202 = F_788 ;
break;
case 3 :
V_6 -> V_433 . V_1202 = F_792 ;
break;
case 4 :
case 5 :
V_6 -> V_433 . V_1202 = F_793 ;
break;
case 6 :
V_6 -> V_433 . V_1202 = F_794 ;
break;
case 7 :
case 8 :
V_6 -> V_433 . V_1202 = F_795 ;
break;
case 9 :
default:
V_6 -> V_433 . V_1202 = F_809 ;
}
}
static void F_1028 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
V_6 -> V_129 |= V_130 ;
F_1029 ( L_299 ) ;
}
static void F_1030 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
V_6 -> V_129 |= V_131 ;
F_1029 ( L_300 ) ;
}
static void F_1031 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
V_6 -> V_129 |= V_805 ;
F_1029 ( L_301 ) ;
}
static void F_1032 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
V_6 -> V_129 |= V_1477 ;
F_1029 ( L_302 ) ;
}
static void F_1033 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
V_6 -> V_129 |= V_1478 ;
F_1029 ( L_303 ) ;
}
static int F_1034 ( const struct V_1479 * V_377 )
{
F_1029 ( L_304 , V_377 -> V_1480 ) ;
return 1 ;
}
static void F_1035 ( struct V_62 * V_63 )
{
struct V_744 * V_1481 = V_63 -> V_745 ;
int V_135 ;
for ( V_135 = 0 ; V_135 < F_179 ( V_1482 ) ; V_135 ++ ) {
struct V_1483 * V_1484 = & V_1482 [ V_135 ] ;
if ( V_1481 -> V_1485 == V_1484 -> V_1485 &&
( V_1481 -> V_1486 == V_1484 -> V_1486 ||
V_1484 -> V_1486 == V_1487 ) &&
( V_1481 -> V_1488 == V_1484 -> V_1488 ||
V_1484 -> V_1488 == V_1487 ) )
V_1484 -> V_1489 ( V_63 ) ;
}
for ( V_135 = 0 ; V_135 < F_179 ( V_1490 ) ; V_135 ++ ) {
if ( F_1036 ( * V_1490 [ V_135 ] . V_1491 ) != 0 )
V_1490 [ V_135 ] . V_1489 ( V_63 ) ;
}
}
static void F_1037 ( struct V_5 * V_6 )
{
struct V_744 * V_745 = V_6 -> V_422 . V_745 ;
T_11 V_1492 ;
T_3 V_1493 = F_1038 ( V_6 ) ;
F_1039 ( V_745 , V_1494 ) ;
F_1040 ( V_1495 , V_1496 ) ;
V_1492 = F_1041 ( V_1497 ) ;
F_1040 ( V_1492 | 1 << 5 , V_1497 ) ;
F_1042 ( V_745 , V_1494 ) ;
F_126 ( 300 ) ;
F_124 ( V_1493 , V_1498 ) ;
F_125 ( V_1493 ) ;
}
void F_311 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
F_482 ( V_6 ) ;
V_6 -> V_1320 = V_6 -> V_638 ;
F_1043 ( V_6 ) ;
}
static void F_1044 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_418 * V_43 ;
struct V_570 * V_336 ;
struct V_144 * V_65 ;
struct V_42 * V_1044 ;
struct V_423 V_424 ;
int V_360 ;
int V_135 ;
if ( ! V_6 -> V_433 . V_1214 )
return;
F_301 ( & V_424 , 0 ) ;
V_461:
V_360 = F_302 ( V_63 , & V_424 ) ;
if ( V_360 == - V_421 ) {
F_303 ( & V_424 ) ;
goto V_461;
} else if ( F_28 ( V_360 ) ) {
goto V_784;
}
V_43 = F_304 ( V_63 , & V_424 ) ;
if ( F_28 ( F_194 ( V_43 ) ) )
goto V_784;
V_336 = F_296 ( V_43 ) ;
V_336 -> V_420 = true ;
V_360 = F_908 ( V_63 , V_43 ) ;
if ( V_360 ) {
F_7 ( true , L_305 ) ;
goto V_1499;
}
F_295 (state, crtc, cstate, i) {
struct V_37 * V_1500 = F_291 ( V_1044 ) ;
V_1500 -> V_559 . V_1215 = true ;
V_6 -> V_433 . V_1214 ( V_336 , V_1500 ) ;
}
V_1499:
F_306 ( V_43 ) ;
V_784:
F_315 ( & V_424 ) ;
F_316 ( & V_424 ) ;
}
static void F_1045 ( struct V_1139 * V_2 )
{
struct V_5 * V_6 =
F_769 ( V_2 , F_1046 ( * V_6 ) , V_1359 . V_1192 ) ;
struct V_570 * V_43 , * V_1501 ;
struct V_1502 * V_1360 ;
V_1360 = F_1047 ( & V_6 -> V_1359 . V_1361 ) ;
F_1048 (state, next, freed, freed)
F_306 ( & V_43 -> V_64 ) ;
}
int F_1049 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_318 * V_319 = & V_6 -> V_319 ;
enum V_94 V_94 ;
struct V_81 * V_65 ;
F_1050 ( V_63 ) ;
V_63 -> V_426 . V_1503 = 0 ;
V_63 -> V_426 . V_1504 = 0 ;
V_63 -> V_426 . V_1505 = 24 ;
V_63 -> V_426 . V_1506 = 1 ;
V_63 -> V_426 . V_1507 = true ;
V_63 -> V_426 . V_1011 = & V_1508 ;
F_820 ( & V_6 -> V_1359 . V_1192 ,
F_1045 ) ;
F_1035 ( V_63 ) ;
F_1051 ( V_6 ) ;
if ( F_184 ( V_6 ) -> V_725 == 0 )
return 0 ;
if ( F_120 ( V_6 ) || F_106 ( V_6 ) ) {
bool V_1509 = ! ! ( F_11 ( V_950 ) &
V_956 ) ;
if ( V_6 -> V_803 . V_804 != V_1509 ) {
F_161 ( L_306 ,
V_1509 ? L_75 : L_76 ,
V_6 -> V_803 . V_804 ? L_75 : L_76 ) ;
V_6 -> V_803 . V_804 = V_1509 ;
}
}
if ( F_56 ( V_6 ) ) {
V_63 -> V_426 . V_356 = 2048 ;
V_63 -> V_426 . V_357 = 2048 ;
} else if ( F_1052 ( V_6 ) ) {
V_63 -> V_426 . V_356 = 4096 ;
V_63 -> V_426 . V_357 = 4096 ;
} else {
V_63 -> V_426 . V_356 = 8192 ;
V_63 -> V_426 . V_357 = 8192 ;
}
if ( F_80 ( V_6 ) || F_81 ( V_6 ) ) {
V_63 -> V_426 . V_1510 = F_80 ( V_6 ) ? 64 : 512 ;
V_63 -> V_426 . V_1511 = 1023 ;
} else if ( F_56 ( V_6 ) ) {
V_63 -> V_426 . V_1510 = V_1512 ;
V_63 -> V_426 . V_1511 = V_1513 ;
} else {
V_63 -> V_426 . V_1510 = V_1514 ;
V_63 -> V_426 . V_1511 = V_1515 ;
}
V_63 -> V_426 . V_1516 = V_319 -> V_1517 ;
F_161 ( L_307 ,
F_184 ( V_6 ) -> V_725 ,
F_184 ( V_6 ) -> V_725 > 1 ? L_308 : L_309 ) ;
F_91 (dev_priv, pipe) {
int V_360 ;
V_360 = F_981 ( V_6 , V_94 ) ;
if ( V_360 ) {
F_1053 ( V_63 ) ;
return V_360 ;
}
}
F_21 ( V_6 ) ;
F_482 ( V_6 ) ;
V_6 -> V_1320 = V_6 -> V_638 ;
F_1054 ( V_63 ) ;
if ( V_6 -> V_628 == 0 )
F_476 ( V_6 ) ;
F_1037 ( V_6 ) ;
F_996 ( V_63 ) ;
F_1055 ( V_63 ) ;
F_293 ( V_63 ) ;
F_1056 ( V_63 ) ;
F_138 (dev, crtc) {
struct V_316 V_317 = {} ;
if ( ! V_65 -> V_87 )
continue;
V_6 -> V_433 . V_1475 ( V_65 ,
& V_317 ) ;
F_234 ( V_65 , & V_317 ) ;
}
F_1044 ( V_63 ) ;
return 0 ;
}
static void F_1057 ( struct V_62 * V_63 )
{
struct V_718 * V_719 ;
struct V_578 * V_1518 = NULL ;
struct V_1108 V_1519 ;
struct V_423 * V_424 = V_63 -> V_426 . V_431 ;
F_845 (dev, connector) {
if ( V_719 -> V_511 -> type == V_616 ) {
V_1518 = & V_719 -> V_64 ;
break;
}
}
if ( ! V_1518 )
return;
if ( F_753 ( V_1518 , NULL , & V_1519 , V_424 ) )
F_760 ( V_1518 , & V_1519 , V_424 ) ;
}
static bool
F_1058 ( struct V_81 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
T_1 V_15 ;
if ( F_184 ( V_6 ) -> V_725 == 1 )
return true ;
V_15 = F_11 ( F_88 ( ! V_65 -> V_133 ) ) ;
if ( ( V_15 & V_134 ) &&
( ! ! ( V_15 & V_137 ) == V_65 -> V_94 ) )
return false ;
return true ;
}
static bool F_1059 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_510 * V_511 ;
F_380 (dev, &crtc->base, encoder)
return true ;
return false ;
}
static struct V_718 * F_1060 ( struct V_510 * V_511 )
{
struct V_62 * V_63 = V_511 -> V_64 . V_63 ;
struct V_718 * V_719 ;
F_1061 (dev, &encoder->base, connector)
return V_719 ;
return NULL ;
}
static bool F_1062 ( struct V_5 * V_6 ,
enum V_93 V_505 )
{
return F_120 ( V_6 ) || F_106 ( V_6 ) ||
( F_993 ( V_6 ) && V_505 == V_218 ) ;
}
static void F_1063 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_93 V_95 = V_65 -> V_90 -> V_95 ;
if ( ! F_445 ( V_95 ) ) {
T_3 V_13 = F_60 ( V_95 ) ;
F_124 ( V_13 ,
F_11 ( V_13 ) & ~ V_1520 ) ;
}
F_1064 ( & V_65 -> V_64 ) ;
if ( V_65 -> V_87 ) {
struct V_335 * V_133 ;
F_441 ( & V_65 -> V_64 ) ;
F_1065 (dev, crtc, plane) {
if ( V_133 -> V_64 . type == V_1395 )
continue;
V_133 -> V_340 ( & V_133 -> V_64 , & V_65 -> V_64 ) ;
}
}
if ( F_59 ( V_6 ) < 4 && ! F_1058 ( V_65 ) ) {
bool V_133 ;
F_161 ( L_310 ,
V_65 -> V_64 . V_64 . V_377 , V_65 -> V_64 . V_12 ) ;
V_133 = V_65 -> V_133 ;
F_236 ( V_65 -> V_64 . V_88 -> V_43 ) -> V_64 . V_338 = true ;
V_65 -> V_133 = ! V_133 ;
F_535 ( & V_65 -> V_64 ) ;
V_65 -> V_133 = V_133 ;
}
if ( V_6 -> V_129 & V_130 &&
V_65 -> V_94 == V_113 && ! V_65 -> V_87 ) {
F_1057 ( V_63 ) ;
}
if ( V_65 -> V_87 && ! F_1059 ( V_65 ) )
F_535 ( & V_65 -> V_64 ) ;
if ( V_65 -> V_87 || F_163 ( V_6 ) ) {
V_65 -> V_1521 = true ;
if ( F_1062 ( V_6 , (enum V_93 ) V_65 -> V_94 ) )
V_65 -> V_1522 = true ;
}
}
static void F_1066 ( struct V_510 * V_511 )
{
struct V_718 * V_719 ;
bool V_1523 = V_511 -> V_64 . V_65 &&
F_48 ( V_511 -> V_64 . V_65 ) -> V_87 ;
V_719 = F_1060 ( V_511 ) ;
if ( V_719 && ! V_1523 ) {
F_161 ( L_311 ,
V_511 -> V_64 . V_64 . V_377 ,
V_511 -> V_64 . V_12 ) ;
if ( V_511 -> V_64 . V_65 ) {
struct V_42 * V_60 = V_511 -> V_64 . V_65 -> V_43 ;
F_161 ( L_312 ,
V_511 -> V_64 . V_64 . V_377 ,
V_511 -> V_64 . V_12 ) ;
V_511 -> V_584 ( V_511 , F_291 ( V_60 ) , V_719 -> V_64 . V_43 ) ;
if ( V_511 -> V_585 )
V_511 -> V_585 ( V_511 , F_291 ( V_60 ) , V_719 -> V_64 . V_43 ) ;
}
V_511 -> V_64 . V_65 = NULL ;
V_719 -> V_64 . V_1524 = V_1525 ;
V_719 -> V_64 . V_511 = NULL ;
}
}
void F_1067 ( struct V_5 * V_6 )
{
T_3 V_1493 = F_1038 ( V_6 ) ;
if ( ! ( F_11 ( V_1493 ) & V_1498 ) ) {
F_161 ( L_313 ) ;
F_1037 ( V_6 ) ;
}
}
void F_294 ( struct V_5 * V_6 )
{
if ( ! F_85 ( V_6 , V_1526 ) )
return;
F_1067 ( V_6 ) ;
F_86 ( V_6 , V_1526 ) ;
}
static bool F_1068 ( struct V_335 * V_133 )
{
struct V_5 * V_6 = F_41 ( V_133 -> V_64 . V_63 ) ;
return F_11 ( F_88 ( V_133 -> V_133 ) ) & V_134 ;
}
static void F_1069 ( struct V_81 * V_65 )
{
struct V_331 * V_88 = V_65 -> V_64 . V_88 ;
struct V_263 * V_334 =
F_236 ( V_88 -> V_43 ) ;
V_334 -> V_64 . V_338 = V_65 -> V_87 &&
F_1068 ( F_235 ( V_88 ) ) ;
if ( V_334 -> V_64 . V_338 )
V_65 -> V_64 . V_43 -> V_339 |= 1 << F_240 ( V_88 ) ;
}
static void F_1070 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_94 V_94 ;
struct V_81 * V_65 ;
struct V_510 * V_511 ;
struct V_718 * V_719 ;
int V_135 ;
V_6 -> V_703 = 0 ;
F_138 (dev, crtc) {
struct V_37 * V_60 = V_65 -> V_90 ;
F_891 ( & V_60 -> V_64 ) ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_64 . V_65 = & V_65 -> V_64 ;
V_60 -> V_64 . V_87 = V_60 -> V_64 . V_506 =
V_6 -> V_433 . V_1304 ( V_65 , V_60 ) ;
V_65 -> V_64 . V_145 = V_60 -> V_64 . V_506 ;
V_65 -> V_87 = V_60 -> V_64 . V_87 ;
if ( V_60 -> V_64 . V_87 )
V_6 -> V_703 |= 1 << V_65 -> V_94 ;
F_1069 ( V_65 ) ;
F_161 ( L_314 ,
V_65 -> V_64 . V_64 . V_377 , V_65 -> V_64 . V_12 ,
F_856 ( V_65 -> V_87 ) ) ;
}
for ( V_135 = 0 ; V_135 < V_6 -> V_948 ; V_135 ++ ) {
struct V_992 * V_993 = & V_6 -> V_1312 [ V_135 ] ;
V_993 -> V_1308 = V_993 -> V_1011 . V_720 ( V_6 , V_993 ,
& V_993 -> V_90 . V_1310 ) ;
V_993 -> V_90 . V_1306 = 0 ;
F_138 (dev, crtc) {
if ( V_65 -> V_87 && V_65 -> V_90 -> V_205 == V_993 )
V_993 -> V_90 . V_1306 |= 1 << V_65 -> V_94 ;
}
V_993 -> V_1309 = V_993 -> V_90 . V_1306 ;
F_161 ( L_315 ,
V_993 -> V_12 , V_993 -> V_90 . V_1306 , V_993 -> V_1308 ) ;
}
F_658 (dev, encoder) {
V_94 = 0 ;
if ( V_511 -> V_720 ( V_511 , & V_94 ) ) {
V_65 = F_53 ( V_6 , V_94 ) ;
V_511 -> V_64 . V_65 = & V_65 -> V_64 ;
V_65 -> V_90 -> V_1258 |= 1 << V_511 -> type ;
V_511 -> V_1305 ( V_511 , V_65 -> V_90 ) ;
} else {
V_511 -> V_64 . V_65 = NULL ;
}
F_161 ( L_316 ,
V_511 -> V_64 . V_64 . V_377 , V_511 -> V_64 . V_12 ,
F_856 ( V_511 -> V_64 . V_65 ) ,
F_78 ( V_94 ) ) ;
}
F_845 (dev, connector) {
if ( V_719 -> V_720 ( V_719 ) ) {
V_719 -> V_64 . V_1524 = V_1527 ;
V_511 = V_719 -> V_511 ;
V_719 -> V_64 . V_511 = & V_511 -> V_64 ;
if ( V_511 -> V_64 . V_65 &&
V_511 -> V_64 . V_65 -> V_43 -> V_87 ) {
V_511 -> V_64 . V_65 -> V_43 -> V_716 |=
1 << F_1071 ( & V_719 -> V_64 ) ;
V_511 -> V_64 . V_65 -> V_43 -> V_717 |=
1 << F_1072 ( & V_511 -> V_64 ) ;
}
} else {
V_719 -> V_64 . V_1524 = V_1525 ;
V_719 -> V_64 . V_511 = NULL ;
}
F_161 ( L_317 ,
V_719 -> V_64 . V_64 . V_377 , V_719 -> V_64 . V_12 ,
F_856 ( V_719 -> V_64 . V_511 ) ) ;
}
F_138 (dev, crtc) {
int V_701 = 0 ;
V_65 -> V_64 . V_1262 = V_65 -> V_90 -> V_64 . V_91 ;
memset ( & V_65 -> V_64 . V_414 , 0 , sizeof( V_65 -> V_64 . V_414 ) ) ;
if ( V_65 -> V_64 . V_43 -> V_87 ) {
F_640 ( & V_65 -> V_64 . V_414 , V_65 -> V_90 ) ;
F_640 ( & V_65 -> V_64 . V_43 -> V_91 , V_65 -> V_90 ) ;
F_28 ( F_539 ( V_65 -> V_64 . V_43 , & V_65 -> V_64 . V_414 ) ) ;
V_65 -> V_64 . V_43 -> V_414 . V_1323 = V_1528 ;
if ( F_59 ( V_6 ) >= 9 || F_266 ( V_6 ) )
V_701 = F_559 ( V_65 -> V_90 ) ;
else if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
V_701 = V_65 -> V_90 -> V_64 . V_91 . V_92 ;
else
F_28 ( V_6 -> V_433 . V_1319 ) ;
if ( F_266 ( V_6 ) && V_65 -> V_90 -> V_550 )
V_701 = F_221 ( V_701 * 100 , 95 ) ;
F_1073 ( & V_65 -> V_64 , & V_65 -> V_64 . V_1262 ) ;
F_898 ( V_65 ) ;
}
V_6 -> V_700 [ V_65 -> V_94 ] = V_701 ;
F_880 ( V_6 , V_65 -> V_90 ) ;
}
}
static void
F_293 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_94 V_94 ;
struct V_81 * V_65 ;
struct V_510 * V_511 ;
int V_135 ;
F_1070 ( V_63 ) ;
F_658 (dev, encoder) {
F_1066 ( V_511 ) ;
}
F_91 (dev_priv, pipe) {
V_65 = F_53 ( V_6 , V_94 ) ;
F_1063 ( V_65 ) ;
F_853 ( V_65 , V_65 -> V_90 ,
L_318 ) ;
}
F_844 ( V_63 ) ;
for ( V_135 = 0 ; V_135 < V_6 -> V_948 ; V_135 ++ ) {
struct V_992 * V_993 = & V_6 -> V_1312 [ V_135 ] ;
if ( ! V_993 -> V_1308 || V_993 -> V_1309 )
continue;
F_161 ( L_319 , V_993 -> V_12 ) ;
V_993 -> V_1011 . V_584 ( V_6 , V_993 ) ;
V_993 -> V_1308 = false ;
}
if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
F_1074 ( V_63 ) ;
else if ( F_702 ( V_6 ) )
F_1075 ( V_63 ) ;
else if ( F_15 ( V_6 ) )
F_1076 ( V_63 ) ;
F_138 (dev, crtc) {
unsigned long V_1344 ;
V_1344 = F_471 ( & V_65 -> V_64 , V_65 -> V_90 ) ;
if ( F_28 ( V_1344 ) )
F_474 ( V_6 , V_1344 ) ;
}
F_1077 ( V_6 , false ) ;
F_1078 ( V_6 ) ;
}
void F_1079 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_418 * V_43 = V_6 -> V_430 ;
struct V_423 V_424 ;
int V_360 ;
V_6 -> V_430 = NULL ;
if ( V_43 )
V_43 -> V_431 = & V_424 ;
F_3 ( & V_63 -> V_426 . V_427 ) ;
F_301 ( & V_424 , 0 ) ;
while ( 1 ) {
V_360 = F_302 ( V_63 , & V_424 ) ;
if ( V_360 != - V_421 )
break;
F_303 ( & V_424 ) ;
}
if ( ! V_360 )
V_360 = F_292 ( V_63 , V_43 ) ;
F_315 ( & V_424 ) ;
F_316 ( & V_424 ) ;
F_5 ( & V_63 -> V_426 . V_427 ) ;
if ( V_360 )
F_127 ( L_58 , V_360 ) ;
if ( V_43 )
F_306 ( V_43 ) ;
}
void F_1080 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
F_1081 ( V_6 ) ;
F_311 ( V_63 ) ;
F_1082 ( V_6 ) ;
}
int F_1083 ( struct V_578 * V_719 )
{
struct V_718 * V_718 = F_850 ( V_719 ) ;
int V_360 ;
V_360 = F_1084 ( V_718 ) ;
if ( V_360 )
goto V_72;
return 0 ;
V_72:
return V_360 ;
}
void F_1085 ( struct V_578 * V_719 )
{
struct V_718 * V_718 = F_850 ( V_719 ) ;
F_1086 ( V_718 ) ;
F_1087 ( V_719 ) ;
}
void F_1088 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
F_770 ( & V_6 -> V_1359 . V_1192 ) ;
F_28 ( ! F_1089 ( & V_6 -> V_1359 . V_1361 ) ) ;
F_1090 ( V_6 ) ;
F_1091 ( V_6 ) ;
F_1092 ( V_63 ) ;
F_1093 () ;
F_1094 ( V_6 ) ;
F_1095 () ;
F_1053 ( V_63 ) ;
F_1096 ( V_6 ) ;
F_1097 ( V_6 ) ;
F_1098 ( V_63 ) ;
}
void F_1099 ( struct V_718 * V_719 ,
struct V_510 * V_511 )
{
V_719 -> V_511 = V_511 ;
F_1100 ( & V_719 -> V_64 ,
& V_511 -> V_64 ) ;
}
int F_1101 ( struct V_5 * V_6 , bool V_43 )
{
unsigned V_13 = F_59 ( V_6 ) >= 6 ? V_1529 : V_1530 ;
T_4 V_1531 ;
if ( F_577 ( V_6 -> V_1532 , V_13 , & V_1531 ) ) {
F_127 ( L_320 ) ;
return - V_1194 ;
}
if ( ! ! ( V_1531 & V_1533 ) == ! V_43 )
return 0 ;
if ( V_43 )
V_1531 &= ~ V_1533 ;
else
V_1531 |= V_1533 ;
if ( F_1102 ( V_6 -> V_1532 , V_13 , V_1531 ) ) {
F_127 ( L_321 ) ;
return - V_1194 ;
}
return 0 ;
}
struct V_1534 *
F_1103 ( struct V_5 * V_6 )
{
struct V_1534 * error ;
int V_1535 [] = {
V_218 ,
V_1536 ,
V_1537 ,
V_590 ,
} ;
int V_135 ;
if ( F_184 ( V_6 ) -> V_725 == 0 )
return NULL ;
error = F_551 ( sizeof( * error ) , V_1538 ) ;
if ( error == NULL )
return NULL ;
if ( F_265 ( V_6 ) || F_266 ( V_6 ) )
error -> V_1539 = F_11 ( V_1013 ) ;
F_91 (dev_priv, i) {
error -> V_94 [ V_135 ] . V_1540 =
F_1104 ( V_6 ,
F_468 ( V_135 ) ) ;
if ( ! error -> V_94 [ V_135 ] . V_1540 )
continue;
error -> V_1399 [ V_135 ] . V_597 = F_11 ( F_82 ( V_135 ) ) ;
error -> V_1399 [ V_135 ] . V_1541 = F_11 ( F_733 ( V_135 ) ) ;
error -> V_1399 [ V_135 ] . V_64 = F_11 ( F_730 ( V_135 ) ) ;
error -> V_133 [ V_135 ] . V_597 = F_11 ( F_88 ( V_135 ) ) ;
error -> V_133 [ V_135 ] . V_290 = F_11 ( F_258 ( V_135 ) ) ;
if ( F_59 ( V_6 ) <= 3 ) {
error -> V_133 [ V_135 ] . V_240 = F_11 ( F_253 ( V_135 ) ) ;
error -> V_133 [ V_135 ] . V_547 = F_11 ( F_254 ( V_135 ) ) ;
}
if ( F_59 ( V_6 ) <= 7 && ! F_265 ( V_6 ) )
error -> V_133 [ V_135 ] . V_1183 = F_11 ( F_262 ( V_135 ) ) ;
if ( F_59 ( V_6 ) >= 4 ) {
error -> V_133 [ V_135 ] . V_1542 = F_11 ( F_259 ( V_135 ) ) ;
error -> V_133 [ V_135 ] . V_1543 = F_11 ( F_260 ( V_135 ) ) ;
}
error -> V_94 [ V_135 ] . V_1544 = F_11 ( F_322 ( V_135 ) ) ;
if ( F_163 ( V_6 ) )
error -> V_94 [ V_135 ] . V_1545 = F_11 ( F_1105 ( V_135 ) ) ;
}
error -> V_1546 = F_184 ( V_6 ) -> V_725 ;
if ( F_23 ( V_6 ) )
error -> V_1546 ++ ;
for ( V_135 = 0 ; V_135 < error -> V_1546 ; V_135 ++ ) {
enum V_93 V_95 = V_1535 [ V_135 ] ;
error -> V_93 [ V_135 ] . V_1540 =
F_1104 ( V_6 ,
F_84 ( V_95 ) ) ;
if ( ! error -> V_93 [ V_135 ] . V_1540 )
continue;
error -> V_93 [ V_135 ] . V_95 = V_95 ;
error -> V_93 [ V_135 ] . V_1547 = F_11 ( F_60 ( V_95 ) ) ;
error -> V_93 [ V_135 ] . V_891 = F_11 ( F_364 ( V_95 ) ) ;
error -> V_93 [ V_135 ] . V_1548 = F_11 ( F_366 ( V_95 ) ) ;
error -> V_93 [ V_135 ] . V_898 = F_11 ( F_368 ( V_95 ) ) ;
error -> V_93 [ V_135 ] . V_894 = F_11 ( F_370 ( V_95 ) ) ;
error -> V_93 [ V_135 ] . V_1184 = F_11 ( F_372 ( V_95 ) ) ;
error -> V_93 [ V_135 ] . V_1138 = F_11 ( F_374 ( V_95 ) ) ;
}
return error ;
}
void
F_1106 ( struct V_1549 * V_46 ,
struct V_5 * V_6 ,
struct V_1534 * error )
{
int V_135 ;
if ( ! error )
return;
F_1107 ( V_46 , L_322 , F_184 ( V_6 ) -> V_725 ) ;
if ( F_265 ( V_6 ) || F_266 ( V_6 ) )
F_1107 ( V_46 , L_323 ,
error -> V_1539 ) ;
F_91 (dev_priv, i) {
F_1107 ( V_46 , L_324 , V_135 ) ;
F_1107 ( V_46 , L_325 ,
F_66 ( error -> V_94 [ V_135 ] . V_1540 ) ) ;
F_1107 ( V_46 , L_326 , error -> V_94 [ V_135 ] . V_1544 ) ;
F_1107 ( V_46 , L_327 , error -> V_94 [ V_135 ] . V_1545 ) ;
F_1107 ( V_46 , L_328 , V_135 ) ;
F_1107 ( V_46 , L_329 , error -> V_133 [ V_135 ] . V_597 ) ;
F_1107 ( V_46 , L_330 , error -> V_133 [ V_135 ] . V_290 ) ;
if ( F_59 ( V_6 ) <= 3 ) {
F_1107 ( V_46 , L_331 , error -> V_133 [ V_135 ] . V_240 ) ;
F_1107 ( V_46 , L_332 , error -> V_133 [ V_135 ] . V_547 ) ;
}
if ( F_59 ( V_6 ) <= 7 && ! F_265 ( V_6 ) )
F_1107 ( V_46 , L_333 , error -> V_133 [ V_135 ] . V_1183 ) ;
if ( F_59 ( V_6 ) >= 4 ) {
F_1107 ( V_46 , L_334 , error -> V_133 [ V_135 ] . V_1542 ) ;
F_1107 ( V_46 , L_335 , error -> V_133 [ V_135 ] . V_1543 ) ;
}
F_1107 ( V_46 , L_336 , V_135 ) ;
F_1107 ( V_46 , L_329 , error -> V_1399 [ V_135 ] . V_597 ) ;
F_1107 ( V_46 , L_332 , error -> V_1399 [ V_135 ] . V_1541 ) ;
F_1107 ( V_46 , L_337 , error -> V_1399 [ V_135 ] . V_64 ) ;
}
for ( V_135 = 0 ; V_135 < error -> V_1546 ; V_135 ++ ) {
F_1107 ( V_46 , L_338 ,
F_854 ( error -> V_93 [ V_135 ] . V_95 ) ) ;
F_1107 ( V_46 , L_325 ,
F_66 ( error -> V_93 [ V_135 ] . V_1540 ) ) ;
F_1107 ( V_46 , L_339 , error -> V_93 [ V_135 ] . V_1547 ) ;
F_1107 ( V_46 , L_340 , error -> V_93 [ V_135 ] . V_891 ) ;
F_1107 ( V_46 , L_341 , error -> V_93 [ V_135 ] . V_1548 ) ;
F_1107 ( V_46 , L_342 , error -> V_93 [ V_135 ] . V_898 ) ;
F_1107 ( V_46 , L_343 , error -> V_93 [ V_135 ] . V_894 ) ;
F_1107 ( V_46 , L_344 , error -> V_93 [ V_135 ] . V_1184 ) ;
F_1107 ( V_46 , L_345 , error -> V_93 [ V_135 ] . V_1138 ) ;
}
}
