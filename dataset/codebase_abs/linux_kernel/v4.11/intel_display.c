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
T_1 V_15 = F_11 ( F_95 ( V_94 , V_141 + V_139 ) ) ;
F_65 ( V_15 & V_142 ,
L_29 ,
F_96 ( V_94 , V_139 ) , F_78 ( V_94 ) ) ;
}
} else if ( F_59 ( V_6 ) >= 7 ) {
T_1 V_15 = F_11 ( F_97 ( V_94 ) ) ;
F_65 ( V_15 & V_143 ,
L_29 ,
F_89 ( V_94 ) , F_78 ( V_94 ) ) ;
} else if ( F_59 ( V_6 ) >= 5 ) {
T_1 V_15 = F_11 ( F_98 ( V_94 ) ) ;
F_65 ( V_15 & V_144 ,
L_29 ,
F_89 ( V_94 ) , F_78 ( V_94 ) ) ;
}
}
static void F_99 ( struct V_145 * V_65 )
{
if ( F_100 ( F_101 ( V_65 ) == 0 ) )
F_102 ( V_65 ) ;
}
void F_103 ( struct V_5 * V_6 ,
enum V_94 V_94 )
{
T_1 V_15 ;
bool V_146 ;
V_15 = F_11 ( F_104 ( V_94 ) ) ;
V_146 = ! ! ( V_15 & V_147 ) ;
F_65 ( V_146 ,
L_30 ,
F_78 ( V_94 ) ) ;
}
static bool F_105 ( struct V_5 * V_6 ,
enum V_94 V_94 , T_1 V_115 , T_1 V_15 )
{
if ( ( V_15 & V_148 ) == 0 )
return false ;
if ( F_106 ( V_6 ) ) {
T_1 V_149 = F_11 ( F_107 ( V_94 ) ) ;
if ( ( V_149 & V_150 ) != V_115 )
return false ;
} else if ( F_17 ( V_6 ) ) {
if ( ( V_15 & V_151 ) != F_108 ( V_94 ) )
return false ;
} else {
if ( ( V_15 & V_152 ) != ( V_94 << 30 ) )
return false ;
}
return true ;
}
static bool F_109 ( struct V_5 * V_6 ,
enum V_94 V_94 , T_1 V_15 )
{
if ( ( V_15 & V_153 ) == 0 )
return false ;
if ( F_106 ( V_6 ) ) {
if ( ( V_15 & V_154 ) != F_110 ( V_94 ) )
return false ;
} else if ( F_17 ( V_6 ) ) {
if ( ( V_15 & V_155 ) != F_111 ( V_94 ) )
return false ;
} else {
if ( ( V_15 & V_156 ) != F_112 ( V_94 ) )
return false ;
}
return true ;
}
static bool F_113 ( struct V_5 * V_6 ,
enum V_94 V_94 , T_1 V_15 )
{
if ( ( V_15 & V_157 ) == 0 )
return false ;
if ( F_106 ( V_6 ) ) {
if ( ( V_15 & V_158 ) != F_114 ( V_94 ) )
return false ;
} else {
if ( ( V_15 & V_159 ) != F_115 ( V_94 ) )
return false ;
}
return true ;
}
static bool F_116 ( struct V_5 * V_6 ,
enum V_94 V_94 , T_1 V_15 )
{
if ( ( V_15 & V_160 ) == 0 )
return false ;
if ( F_106 ( V_6 ) ) {
if ( ( V_15 & V_158 ) != F_114 ( V_94 ) )
return false ;
} else {
if ( ( V_15 & V_161 ) != F_117 ( V_94 ) )
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
F_65 ( F_120 ( V_6 ) && ( V_15 & V_148 ) == 0
&& ( V_15 & V_162 ) ,
L_32 ) ;
}
static void F_121 ( struct V_5 * V_6 ,
enum V_94 V_94 , T_3 V_13 )
{
T_1 V_15 = F_11 ( V_13 ) ;
F_65 ( F_109 ( V_6 , V_94 , V_15 ) ,
L_33 ,
F_119 ( V_13 ) , F_78 ( V_94 ) ) ;
F_65 ( F_120 ( V_6 ) && ( V_15 & V_153 ) == 0
&& ( V_15 & V_163 ) ,
L_34 ) ;
}
static void F_122 ( struct V_5 * V_6 ,
enum V_94 V_94 )
{
T_1 V_15 ;
F_118 ( V_6 , V_94 , V_164 , V_165 ) ;
F_118 ( V_6 , V_94 , V_166 , V_167 ) ;
F_118 ( V_6 , V_94 , V_168 , V_169 ) ;
V_15 = F_11 ( V_170 ) ;
F_65 ( F_116 ( V_6 , V_94 , V_15 ) ,
L_35 ,
F_78 ( V_94 ) ) ;
V_15 = F_11 ( V_118 ) ;
F_65 ( F_113 ( V_6 , V_94 , V_15 ) ,
L_36 ,
F_78 ( V_94 ) ) ;
F_121 ( V_6 , V_94 , V_171 ) ;
F_121 ( V_6 , V_94 , V_172 ) ;
F_121 ( V_6 , V_94 , V_173 ) ;
}
static void F_123 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
F_124 ( F_64 ( V_94 ) , V_38 -> V_174 . V_45 ) ;
F_125 ( F_64 ( V_94 ) ) ;
F_126 ( 150 ) ;
if ( F_61 ( V_6 ,
F_64 ( V_94 ) ,
V_175 ,
V_175 ,
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
if ( V_38 -> V_174 . V_45 & V_103 )
F_123 ( V_65 , V_38 ) ;
F_124 ( F_130 ( V_94 ) , V_38 -> V_174 . V_176 ) ;
F_125 ( F_130 ( V_94 ) ) ;
}
static void F_131 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
enum V_177 V_178 = F_132 ( V_94 ) ;
T_1 V_179 ;
F_3 ( & V_6 -> V_9 ) ;
V_179 = F_133 ( V_6 , V_94 , F_134 ( V_178 ) ) ;
V_179 |= V_180 ;
F_135 ( V_6 , V_94 , F_134 ( V_178 ) , V_179 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_126 ( 1 ) ;
F_124 ( F_64 ( V_94 ) , V_38 -> V_174 . V_45 ) ;
if ( F_61 ( V_6 ,
F_64 ( V_94 ) , V_175 , V_175 ,
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
if ( V_38 -> V_174 . V_45 & V_103 )
F_131 ( V_65 , V_38 ) ;
if ( V_94 != V_113 ) {
F_124 ( V_181 , V_94 == V_120 ? V_182 : V_183 ) ;
F_124 ( F_130 ( V_120 ) , V_38 -> V_174 . V_176 ) ;
F_124 ( V_181 , 0 ) ;
V_6 -> V_184 [ V_94 ] = V_38 -> V_174 . V_176 ;
F_28 ( ( F_11 ( F_64 ( V_120 ) ) & V_185 ) == 0 ) ;
} else {
F_124 ( F_130 ( V_94 ) , V_38 -> V_174 . V_176 ) ;
F_125 ( F_130 ( V_94 ) ) ;
}
}
static int F_137 ( struct V_5 * V_6 )
{
struct V_81 * V_65 ;
int V_186 = 0 ;
F_138 (&dev_priv->drm, crtc) {
V_186 += V_65 -> V_64 . V_43 -> V_87 &&
F_38 ( V_65 -> V_90 , V_187 ) ;
}
return V_186 ;
}
static void F_139 ( struct V_81 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
T_3 V_13 = F_64 ( V_65 -> V_94 ) ;
T_1 V_45 = V_65 -> V_90 -> V_174 . V_45 ;
F_129 ( V_6 , V_65 -> V_94 ) ;
if ( F_140 ( V_6 ) && ! F_141 ( V_6 ) )
F_75 ( V_6 , V_65 -> V_94 ) ;
if ( F_141 ( V_6 ) && F_137 ( V_6 ) > 0 ) {
V_45 |= V_188 ;
F_124 ( F_64 ( ! V_65 -> V_94 ) ,
F_11 ( F_64 ( ! V_65 -> V_94 ) ) | V_188 ) ;
}
F_124 ( V_13 , 0 ) ;
F_124 ( V_13 , V_45 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
if ( F_59 ( V_6 ) >= 4 ) {
F_124 ( F_130 ( V_65 -> V_94 ) ,
V_65 -> V_90 -> V_174 . V_176 ) ;
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
F_38 ( V_65 -> V_90 , V_187 ) &&
! F_137 ( V_6 ) ) {
F_124 ( F_64 ( V_120 ) ,
F_11 ( F_64 ( V_120 ) ) & ~ V_188 ) ;
F_124 ( F_64 ( V_113 ) ,
F_11 ( F_64 ( V_113 ) ) & ~ V_188 ) ;
}
if ( ( V_94 == V_113 && V_6 -> V_129 & V_130 ) ||
( V_94 == V_120 && V_6 -> V_129 & V_131 ) )
return;
F_129 ( V_6 , V_94 ) ;
F_124 ( F_64 ( V_94 ) , V_185 ) ;
F_125 ( F_64 ( V_94 ) ) ;
}
static void F_143 ( struct V_5 * V_6 , enum V_94 V_94 )
{
T_1 V_15 ;
F_129 ( V_6 , V_94 ) ;
V_15 = V_189 |
V_190 | V_185 ;
if ( V_94 != V_113 )
V_15 |= V_191 ;
F_124 ( F_64 ( V_94 ) , V_15 ) ;
F_125 ( F_64 ( V_94 ) ) ;
}
static void F_144 ( struct V_5 * V_6 , enum V_94 V_94 )
{
enum V_177 V_178 = F_132 ( V_94 ) ;
T_1 V_15 ;
F_129 ( V_6 , V_94 ) ;
V_15 = V_192 |
V_190 | V_185 ;
if ( V_94 != V_113 )
V_15 |= V_191 ;
F_124 ( F_64 ( V_94 ) , V_15 ) ;
F_125 ( F_64 ( V_94 ) ) ;
F_3 ( & V_6 -> V_9 ) ;
V_15 = F_133 ( V_6 , V_94 , F_134 ( V_178 ) ) ;
V_15 &= ~ V_180 ;
F_135 ( V_6 , V_94 , F_134 ( V_178 ) , V_15 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
void F_145 ( struct V_5 * V_6 ,
struct V_193 * V_194 ,
unsigned int V_195 )
{
T_1 V_196 ;
T_3 V_197 ;
switch ( V_194 -> V_178 ) {
case V_198 :
V_196 = V_199 ;
V_197 = F_64 ( 0 ) ;
break;
case V_200 :
V_196 = V_201 ;
V_197 = F_64 ( 0 ) ;
V_195 <<= 4 ;
break;
case V_202 :
V_196 = V_203 ;
V_197 = V_204 ;
break;
default:
F_146 () ;
}
if ( F_61 ( V_6 ,
V_197 , V_196 , V_195 ,
1000 ) )
F_7 ( 1 , L_39 ,
F_147 ( V_194 -> V_178 ) , F_11 ( V_197 ) & V_196 , V_195 ) ;
}
static void F_148 ( struct V_5 * V_6 ,
enum V_94 V_94 )
{
struct V_81 * V_81 = F_53 ( V_6 ,
V_94 ) ;
T_3 V_13 ;
T_2 V_15 , V_205 ;
F_149 ( V_6 , V_81 -> V_90 -> V_206 ) ;
F_150 ( V_6 , V_94 ) ;
F_151 ( V_6 , V_94 ) ;
if ( F_106 ( V_6 ) ) {
V_13 = F_152 ( V_94 ) ;
V_15 = F_11 ( V_13 ) ;
V_15 |= V_207 ;
F_124 ( V_13 , V_15 ) ;
}
V_13 = F_104 ( V_94 ) ;
V_15 = F_11 ( V_13 ) ;
V_205 = F_11 ( F_60 ( V_94 ) ) ;
if ( F_120 ( V_6 ) ) {
V_15 &= ~ V_208 ;
if ( F_38 ( V_81 -> V_90 , V_209 ) )
V_15 |= V_210 ;
else
V_15 |= V_205 & V_208 ;
}
V_15 &= ~ V_211 ;
if ( ( V_205 & V_212 ) == V_213 )
if ( F_120 ( V_6 ) &&
F_38 ( V_81 -> V_90 , V_214 ) )
V_15 |= V_215 ;
else
V_15 |= V_216 ;
else
V_15 |= V_217 ;
F_124 ( V_13 , V_15 | V_147 ) ;
if ( F_61 ( V_6 ,
V_13 , V_218 , V_218 ,
100 ) )
F_127 ( L_40 , F_78 ( V_94 ) ) ;
}
static void F_153 ( struct V_5 * V_6 ,
enum V_93 V_95 )
{
T_1 V_15 , V_205 ;
F_150 ( V_6 , (enum V_94 ) V_95 ) ;
F_151 ( V_6 , V_219 ) ;
V_15 = F_11 ( F_152 ( V_113 ) ) ;
V_15 |= V_207 ;
F_124 ( F_152 ( V_113 ) , V_15 ) ;
V_15 = V_147 ;
V_205 = F_11 ( F_60 ( V_95 ) ) ;
if ( ( V_205 & V_220 ) ==
V_213 )
V_15 |= V_216 ;
else
V_15 |= V_217 ;
F_124 ( V_221 , V_15 ) ;
if ( F_61 ( V_6 ,
V_221 ,
V_218 ,
V_218 ,
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
V_15 &= ~ V_147 ;
F_124 ( V_13 , V_15 ) ;
if ( F_61 ( V_6 ,
V_13 , V_218 , 0 ,
50 ) )
F_127 ( L_42 , F_78 ( V_94 ) ) ;
if ( F_106 ( V_6 ) ) {
V_13 = F_152 ( V_94 ) ;
V_15 = F_11 ( V_13 ) ;
V_15 &= ~ V_207 ;
F_124 ( V_13 , V_15 ) ;
}
}
void F_157 ( struct V_5 * V_6 )
{
T_1 V_15 ;
V_15 = F_11 ( V_221 ) ;
V_15 &= ~ V_147 ;
F_124 ( V_221 , V_15 ) ;
if ( F_61 ( V_6 ,
V_221 , V_218 , 0 ,
50 ) )
F_127 ( L_43 ) ;
V_15 = F_11 ( F_152 ( V_113 ) ) ;
V_15 &= ~ V_207 ;
F_124 ( F_152 ( V_113 ) , V_15 ) ;
}
enum V_93 F_158 ( struct V_81 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
F_28 ( ! V_65 -> V_90 -> V_222 ) ;
if ( F_159 ( V_6 ) )
return V_219 ;
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
if ( F_38 ( V_65 -> V_90 , V_223 ) )
F_164 ( V_6 ) ;
else
F_165 ( V_6 , V_94 ) ;
} else {
if ( V_65 -> V_90 -> V_222 ) {
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
if ( V_63 -> V_224 == 0 &&
F_62 ( F_167 ( V_65 ) != V_65 -> V_225 , 50 ) )
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
if ( V_65 -> V_90 -> V_226 )
V_15 &= ~ V_227 ;
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
V_55 V_228 , unsigned int V_229 )
{
switch ( V_228 ) {
case V_230 :
return V_229 ;
case V_231 :
if ( F_56 ( V_6 ) )
return 128 ;
else
return 512 ;
case V_232 :
if ( F_56 ( V_6 ) || F_171 ( V_6 ) )
return 128 ;
else
return 512 ;
case V_233 :
switch ( V_229 ) {
case 1 :
return 64 ;
case 2 :
case 4 :
return 128 ;
case 8 :
case 16 :
return 256 ;
default:
F_172 ( V_229 ) ;
return V_229 ;
}
break;
default:
F_172 ( V_228 ) ;
return V_229 ;
}
}
unsigned int F_173 ( const struct V_5 * V_6 ,
V_55 V_228 , unsigned int V_229 )
{
if ( V_228 == V_230 )
return 1 ;
else
return F_169 ( V_6 ) /
F_170 ( V_6 , V_228 , V_229 ) ;
}
static void F_174 ( const struct V_5 * V_6 ,
unsigned int * V_234 ,
unsigned int * V_235 ,
V_55 V_228 ,
unsigned int V_229 )
{
unsigned int V_236 =
F_170 ( V_6 , V_228 , V_229 ) ;
* V_234 = V_236 / V_229 ;
* V_235 = F_169 ( V_6 ) / V_236 ;
}
unsigned int
F_175 ( struct V_62 * V_63 , unsigned int V_237 ,
T_2 V_238 , V_55 V_228 )
{
unsigned int V_229 = F_176 ( V_238 , 0 ) ;
unsigned int V_235 = F_173 ( F_41 ( V_63 ) , V_228 , V_229 ) ;
return F_177 ( V_237 , V_235 ) ;
}
unsigned int F_178 ( const struct V_239 * V_240 )
{
unsigned int V_241 = 0 ;
int V_135 ;
for ( V_135 = 0 ; V_135 < F_179 ( V_240 -> V_133 ) ; V_135 ++ )
V_241 += V_240 -> V_133 [ V_135 ] . V_242 * V_240 -> V_133 [ V_135 ] . V_237 ;
return V_241 ;
}
static void
F_180 ( struct V_243 * V_244 ,
const struct V_245 * V_89 ,
unsigned int V_246 )
{
V_244 -> type = V_247 ;
if ( F_181 ( V_246 ) ) {
V_244 -> type = V_248 ;
V_244 -> V_249 = F_182 ( V_89 ) -> V_240 ;
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
V_55 V_228 )
{
switch ( V_228 ) {
case V_230 :
return F_183 ( V_6 ) ;
case V_231 :
if ( F_184 ( V_6 ) -> V_250 >= 9 )
return 256 * 1024 ;
return 0 ;
case V_232 :
case V_233 :
return 1 * 1024 * 1024 ;
default:
F_172 ( V_228 ) ;
return 0 ;
}
}
struct V_251 *
F_188 ( struct V_245 * V_89 , unsigned int V_246 )
{
struct V_62 * V_63 = V_89 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_252 * V_253 = F_189 ( V_89 ) ;
struct V_243 V_244 ;
struct V_251 * V_254 ;
T_1 V_255 ;
F_28 ( ! F_190 ( & V_63 -> V_256 ) ) ;
V_255 = F_187 ( V_6 , V_89 -> V_257 ) ;
F_180 ( & V_244 , V_89 , V_246 ) ;
if ( F_191 ( V_6 ) && V_255 < 256 * 1024 )
V_255 = 256 * 1024 ;
F_192 ( V_6 ) ;
V_254 = F_193 ( V_253 , V_255 , & V_244 ) ;
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
F_201 ( & V_254 -> V_258 -> V_259 -> V_260 . V_256 ) ;
F_202 ( V_254 ) ;
F_203 ( V_254 ) ;
F_204 ( V_254 ) ;
}
static int F_205 ( const struct V_245 * V_89 , int V_133 ,
unsigned int V_246 )
{
if ( F_181 ( V_246 ) )
return F_182 ( V_89 ) -> V_249 [ V_133 ] . V_261 ;
else
return V_89 -> V_262 [ V_133 ] ;
}
T_1 F_206 ( int V_263 , int V_264 ,
const struct V_265 * V_43 ,
int V_133 )
{
const struct V_245 * V_89 = V_43 -> V_64 . V_89 ;
unsigned int V_229 = V_89 -> V_266 -> V_229 [ V_133 ] ;
unsigned int V_261 = V_89 -> V_262 [ V_133 ] ;
return V_264 * V_261 + V_263 * V_229 ;
}
void F_207 ( int * V_263 , int * V_264 ,
const struct V_265 * V_43 ,
int V_133 )
{
const struct V_267 * V_268 = F_182 ( V_43 -> V_64 . V_89 ) ;
unsigned int V_246 = V_43 -> V_64 . V_246 ;
if ( F_181 ( V_246 ) ) {
* V_263 += V_268 -> V_249 [ V_133 ] . V_263 ;
* V_264 += V_268 -> V_249 [ V_133 ] . V_264 ;
} else {
* V_263 += V_268 -> V_269 [ V_133 ] . V_263 ;
* V_264 += V_268 -> V_269 [ V_133 ] . V_264 ;
}
}
static T_1 F_208 ( int * V_263 , int * V_264 ,
unsigned int V_234 ,
unsigned int V_235 ,
unsigned int V_270 ,
unsigned int V_271 ,
T_1 V_272 ,
T_1 V_273 )
{
unsigned int V_274 = V_271 * V_234 ;
unsigned int V_275 ;
F_28 ( V_272 & ( V_270 - 1 ) ) ;
F_28 ( V_273 & ( V_270 - 1 ) ) ;
F_28 ( V_273 > V_272 ) ;
V_275 = ( V_272 - V_273 ) / V_270 ;
* V_264 += V_275 / V_271 * V_235 ;
* V_263 += V_275 % V_271 * V_234 ;
* V_264 += * V_263 / V_274 * V_235 ;
* V_263 %= V_274 ;
return V_273 ;
}
static T_1 F_209 ( int * V_263 , int * V_264 ,
const struct V_265 * V_43 , int V_133 ,
T_1 V_272 , T_1 V_273 )
{
const struct V_5 * V_6 = F_41 ( V_43 -> V_64 . V_133 -> V_63 ) ;
const struct V_245 * V_89 = V_43 -> V_64 . V_89 ;
unsigned int V_229 = V_89 -> V_266 -> V_229 [ V_133 ] ;
unsigned int V_246 = V_43 -> V_64 . V_246 ;
unsigned int V_261 = F_205 ( V_89 , V_133 , V_246 ) ;
F_28 ( V_273 > V_272 ) ;
if ( V_89 -> V_257 != V_230 ) {
unsigned int V_270 , V_234 , V_235 ;
unsigned int V_271 ;
V_270 = F_169 ( V_6 ) ;
F_174 ( V_6 , & V_234 , & V_235 ,
V_89 -> V_257 , V_229 ) ;
if ( F_181 ( V_246 ) ) {
V_271 = V_261 / V_235 ;
F_210 ( V_234 , V_235 ) ;
} else {
V_271 = V_261 / ( V_234 * V_229 ) ;
}
F_208 ( V_263 , V_264 , V_234 , V_235 ,
V_270 , V_271 ,
V_272 , V_273 ) ;
} else {
V_272 += * V_264 * V_261 + * V_263 * V_229 ;
* V_264 = ( V_272 - V_273 ) / V_261 ;
* V_263 = ( ( V_272 - V_273 ) - * V_264 * V_261 ) / V_229 ;
}
return V_273 ;
}
static T_1 F_211 ( const struct V_5 * V_6 ,
int * V_263 , int * V_264 ,
const struct V_245 * V_89 , int V_133 ,
unsigned int V_261 ,
unsigned int V_246 ,
T_1 V_255 )
{
V_55 V_228 = V_89 -> V_257 ;
unsigned int V_229 = V_89 -> V_266 -> V_229 [ V_133 ] ;
T_1 V_276 , V_277 ;
if ( V_255 )
V_255 -- ;
if ( V_228 != V_230 ) {
unsigned int V_270 , V_234 , V_235 ;
unsigned int V_278 , V_275 , V_271 ;
V_270 = F_169 ( V_6 ) ;
F_174 ( V_6 , & V_234 , & V_235 ,
V_228 , V_229 ) ;
if ( F_181 ( V_246 ) ) {
V_271 = V_261 / V_235 ;
F_210 ( V_234 , V_235 ) ;
} else {
V_271 = V_261 / ( V_234 * V_229 ) ;
}
V_278 = * V_264 / V_235 ;
* V_264 %= V_235 ;
V_275 = * V_263 / V_234 ;
* V_263 %= V_234 ;
V_276 = ( V_278 * V_271 + V_275 ) * V_270 ;
V_277 = V_276 & ~ V_255 ;
F_208 ( V_263 , V_264 , V_234 , V_235 ,
V_270 , V_271 ,
V_276 , V_277 ) ;
} else {
V_276 = * V_264 * V_261 + * V_263 * V_229 ;
V_277 = V_276 & ~ V_255 ;
* V_264 = ( V_276 & V_255 ) / V_261 ;
* V_263 = ( ( V_276 & V_255 ) - * V_264 * V_261 ) / V_229 ;
}
return V_277 ;
}
T_1 F_212 ( int * V_263 , int * V_264 ,
const struct V_265 * V_43 ,
int V_133 )
{
const struct V_5 * V_6 = F_41 ( V_43 -> V_64 . V_133 -> V_63 ) ;
const struct V_245 * V_89 = V_43 -> V_64 . V_89 ;
unsigned int V_246 = V_43 -> V_64 . V_246 ;
int V_261 = F_205 ( V_89 , V_133 , V_246 ) ;
T_1 V_255 ;
if ( V_89 -> V_266 -> V_266 == V_279 && V_133 == 1 )
V_255 = 4096 ;
else
V_255 = F_187 ( V_6 , V_89 -> V_257 ) ;
return F_211 ( V_6 , V_263 , V_264 , V_89 , V_133 , V_261 ,
V_246 , V_255 ) ;
}
static void F_213 ( int * V_263 , int * V_264 ,
const struct V_245 * V_89 , int V_133 )
{
unsigned int V_229 = V_89 -> V_266 -> V_229 [ V_133 ] ;
unsigned int V_261 = V_89 -> V_262 [ V_133 ] ;
T_1 V_280 = V_89 -> V_281 [ V_133 ] ;
* V_264 = V_280 / V_261 ;
* V_263 = V_280 % V_261 / V_229 ;
}
static unsigned int F_214 ( V_55 V_228 )
{
switch ( V_228 ) {
case V_231 :
return V_282 ;
case V_232 :
return V_283 ;
default:
return V_284 ;
}
}
static int
F_215 ( struct V_5 * V_6 ,
struct V_245 * V_89 )
{
struct V_267 * V_268 = F_182 ( V_89 ) ;
struct V_239 * V_240 = & V_268 -> V_240 ;
T_1 V_285 = 0 ;
unsigned int V_286 = 0 ;
int V_135 , V_287 = V_89 -> V_266 -> V_287 ;
unsigned int V_270 = F_169 ( V_6 ) ;
for ( V_135 = 0 ; V_135 < V_287 ; V_135 ++ ) {
unsigned int V_242 , V_237 ;
unsigned int V_229 , V_241 ;
T_1 V_276 ;
int V_263 , V_264 ;
V_229 = V_89 -> V_266 -> V_229 [ V_135 ] ;
V_242 = F_216 ( V_89 -> V_242 , V_89 , V_135 ) ;
V_237 = F_217 ( V_89 -> V_237 , V_89 , V_135 ) ;
F_213 ( & V_263 , & V_264 , V_89 , V_135 ) ;
if ( F_218 ( V_268 -> V_253 ) &&
( V_263 + V_242 ) * V_229 > V_89 -> V_262 [ V_135 ] ) {
F_219 ( L_47 ,
V_135 , V_89 -> V_281 [ V_135 ] ) ;
return - V_288 ;
}
V_268 -> V_269 [ V_135 ] . V_263 = V_263 ;
V_268 -> V_269 [ V_135 ] . V_264 = V_264 ;
V_276 = F_211 ( V_6 , & V_263 , & V_264 ,
V_89 , 0 , V_89 -> V_262 [ V_135 ] ,
V_289 , V_270 ) ;
V_276 /= V_270 ;
if ( V_89 -> V_257 != V_230 ) {
unsigned int V_234 , V_235 ;
unsigned int V_271 ;
struct V_290 V_291 ;
F_174 ( V_6 , & V_234 , & V_235 ,
V_89 -> V_257 , V_229 ) ;
V_240 -> V_133 [ V_135 ] . V_276 = V_276 ;
V_240 -> V_133 [ V_135 ] . V_292 = F_220 ( V_89 -> V_262 [ V_135 ] , V_234 * V_229 ) ;
V_240 -> V_133 [ V_135 ] . V_242 = F_220 ( V_263 + V_242 , V_234 ) ;
V_240 -> V_133 [ V_135 ] . V_237 = F_220 ( V_264 + V_237 , V_235 ) ;
V_268 -> V_249 [ V_135 ] . V_261 =
V_240 -> V_133 [ V_135 ] . V_237 * V_235 ;
V_241 = V_240 -> V_133 [ V_135 ] . V_292 * V_240 -> V_133 [ V_135 ] . V_237 ;
if ( V_263 != 0 )
V_241 ++ ;
V_291 . V_293 = V_263 ;
V_291 . y1 = V_264 ;
V_291 . V_294 = V_263 + V_242 ;
V_291 . V_295 = V_264 + V_237 ;
F_221 ( & V_291 ,
V_240 -> V_133 [ V_135 ] . V_242 * V_234 ,
V_240 -> V_133 [ V_135 ] . V_237 * V_235 ,
V_296 ) ;
V_263 = V_291 . V_293 ;
V_264 = V_291 . y1 ;
V_271 = V_268 -> V_249 [ V_135 ] . V_261 / V_235 ;
F_210 ( V_234 , V_235 ) ;
F_208 ( & V_263 , & V_264 ,
V_234 , V_235 ,
V_270 , V_271 ,
V_285 * V_270 , 0 ) ;
V_285 += V_240 -> V_133 [ V_135 ] . V_242 * V_240 -> V_133 [ V_135 ] . V_237 ;
V_268 -> V_249 [ V_135 ] . V_263 = V_263 ;
V_268 -> V_249 [ V_135 ] . V_264 = V_264 ;
} else {
V_241 = F_220 ( ( V_264 + V_237 ) * V_89 -> V_262 [ V_135 ] +
V_263 * V_229 , V_270 ) ;
}
V_286 = V_59 ( V_286 , V_276 + V_241 ) ;
}
if ( V_286 * V_270 > F_182 ( V_89 ) -> V_253 -> V_64 . V_241 ) {
F_219 ( L_48 ,
V_286 * V_270 , F_182 ( V_89 ) -> V_253 -> V_64 . V_241 ) ;
return - V_288 ;
}
return 0 ;
}
static int F_222 ( int V_266 )
{
switch ( V_266 ) {
case V_297 :
return V_298 ;
case V_299 :
return V_300 ;
case V_301 :
return V_302 ;
default:
case V_303 :
return V_304 ;
case V_305 :
return V_306 ;
case V_307 :
return V_308 ;
case V_309 :
return V_310 ;
}
}
static int F_223 ( int V_266 , bool V_311 , bool V_312 )
{
switch ( V_266 ) {
case V_313 :
return V_302 ;
default:
case V_314 :
if ( V_311 ) {
if ( V_312 )
return V_315 ;
else
return V_306 ;
} else {
if ( V_312 )
return V_316 ;
else
return V_304 ;
}
case V_317 :
if ( V_311 )
return V_310 ;
else
return V_308 ;
}
}
static bool
F_224 ( struct V_81 * V_65 ,
struct V_318 * V_319 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_320 * V_321 = & V_6 -> V_321 ;
struct V_252 * V_253 = NULL ;
struct V_322 V_323 = { 0 } ;
struct V_245 * V_89 = & V_319 -> V_89 -> V_64 ;
T_1 V_324 = F_225 ( V_319 -> V_64 , V_325 ) ;
T_1 V_326 = F_226 ( V_319 -> V_64 + V_319 -> V_241 ,
V_325 ) ;
V_326 -= V_324 ;
if ( V_319 -> V_241 == 0 )
return false ;
if ( V_326 * 2 > V_321 -> V_327 )
return false ;
F_3 ( & V_63 -> V_256 ) ;
V_253 = F_227 ( V_6 ,
V_324 ,
V_324 ,
V_326 ) ;
if ( ! V_253 ) {
F_5 ( & V_63 -> V_256 ) ;
return false ;
}
if ( V_319 -> V_328 == V_282 )
V_253 -> V_329 = V_89 -> V_262 [ 0 ] | V_282 ;
V_323 . V_238 = V_89 -> V_266 -> V_266 ;
V_323 . V_242 = V_89 -> V_242 ;
V_323 . V_237 = V_89 -> V_237 ;
V_323 . V_262 [ 0 ] = V_89 -> V_262 [ 0 ] ;
V_323 . V_257 [ 0 ] = V_89 -> V_257 ;
V_323 . V_330 = V_331 ;
if ( F_228 ( V_63 , F_182 ( V_89 ) ,
& V_323 , V_253 ) ) {
F_161 ( L_49 ) ;
goto V_332;
}
F_5 ( & V_63 -> V_256 ) ;
F_161 ( L_50 , V_253 ) ;
return true ;
V_332:
F_229 ( V_253 ) ;
F_5 ( & V_63 -> V_256 ) ;
return false ;
}
static void
F_230 ( struct V_333 * V_133 )
{
if ( V_133 -> V_89 == V_133 -> V_43 -> V_89 )
return;
if ( V_133 -> V_43 -> V_89 )
F_231 ( V_133 -> V_43 -> V_89 ) ;
V_133 -> V_43 -> V_89 = V_133 -> V_89 ;
if ( V_133 -> V_43 -> V_89 )
F_232 ( V_133 -> V_43 -> V_89 ) ;
}
static void
F_233 ( struct V_81 * V_81 ,
struct V_318 * V_319 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_145 * V_334 ;
struct V_252 * V_253 ;
struct V_333 * V_88 = V_81 -> V_64 . V_88 ;
struct V_335 * V_336 = V_88 -> V_43 ;
struct V_42 * V_60 = V_81 -> V_64 . V_43 ;
struct V_337 * V_337 = F_234 ( V_88 ) ;
struct V_265 * V_338 =
F_235 ( V_336 ) ;
struct V_245 * V_89 ;
if ( ! V_319 -> V_89 )
return;
if ( F_224 ( V_81 , V_319 ) ) {
V_89 = & V_319 -> V_89 -> V_64 ;
goto V_339;
}
F_236 ( V_319 -> V_89 ) ;
F_237 (dev, c) {
struct V_265 * V_43 ;
if ( V_334 == & V_81 -> V_64 )
continue;
if ( ! F_48 ( V_334 ) -> V_87 )
continue;
V_43 = F_235 ( V_334 -> V_88 -> V_43 ) ;
if ( ! V_43 -> V_254 )
continue;
if ( F_238 ( V_43 ) == V_319 -> V_64 ) {
V_89 = V_334 -> V_88 -> V_89 ;
F_232 ( V_89 ) ;
goto V_339;
}
}
V_336 -> V_340 = false ;
V_60 -> V_341 &= ~ ( 1 << F_239 ( V_88 ) ) ;
F_240 ( & V_81 -> V_64 ) ;
V_337 -> V_342 ( V_88 , & V_81 -> V_64 ) ;
return;
V_339:
F_3 ( & V_63 -> V_256 ) ;
V_338 -> V_254 =
F_188 ( V_89 , V_88 -> V_43 -> V_246 ) ;
F_5 ( & V_63 -> V_256 ) ;
if ( F_194 ( V_338 -> V_254 ) ) {
F_127 ( L_51 ,
V_81 -> V_94 , F_241 ( V_338 -> V_254 ) ) ;
V_338 -> V_254 = NULL ;
F_231 ( V_89 ) ;
return;
}
V_336 -> V_343 = 0 ;
V_336 -> V_344 = 0 ;
V_336 -> V_345 = V_89 -> V_242 << 16 ;
V_336 -> V_346 = V_89 -> V_237 << 16 ;
V_336 -> V_347 = 0 ;
V_336 -> V_348 = 0 ;
V_336 -> V_349 = V_89 -> V_242 ;
V_336 -> V_350 = V_89 -> V_237 ;
V_338 -> V_64 . V_351 = F_242 ( V_336 ) ;
V_338 -> V_64 . V_352 = F_243 ( V_336 ) ;
V_253 = F_189 ( V_89 ) ;
if ( F_218 ( V_253 ) )
V_6 -> V_353 = true ;
F_232 ( V_89 ) ;
V_88 -> V_89 = V_88 -> V_43 -> V_89 = V_89 ;
V_88 -> V_65 = V_88 -> V_43 -> V_65 = & V_81 -> V_64 ;
V_81 -> V_64 . V_43 -> V_341 |= ( 1 << F_239 ( V_88 ) ) ;
F_244 ( F_234 ( V_88 ) -> V_354 ,
& V_253 -> V_355 ) ;
}
static int F_245 ( const struct V_245 * V_89 , int V_133 ,
unsigned int V_246 )
{
int V_229 = V_89 -> V_266 -> V_229 [ V_133 ] ;
switch ( V_89 -> V_257 ) {
case V_230 :
case V_231 :
switch ( V_229 ) {
case 8 :
return 4096 ;
case 4 :
case 2 :
case 1 :
return 8192 ;
default:
F_172 ( V_229 ) ;
break;
}
break;
case V_232 :
case V_233 :
switch ( V_229 ) {
case 8 :
return 2048 ;
case 4 :
return 4096 ;
case 2 :
case 1 :
return 8192 ;
default:
F_172 ( V_229 ) ;
break;
}
break;
default:
F_172 ( V_89 -> V_257 ) ;
}
return 2048 ;
}
static int F_246 ( struct V_265 * V_336 )
{
const struct V_5 * V_6 = F_41 ( V_336 -> V_64 . V_133 -> V_63 ) ;
const struct V_245 * V_89 = V_336 -> V_64 . V_89 ;
unsigned int V_246 = V_336 -> V_64 . V_246 ;
int V_263 = V_336 -> V_64 . V_351 . V_293 >> 16 ;
int V_264 = V_336 -> V_64 . V_351 . y1 >> 16 ;
int V_356 = F_247 ( & V_336 -> V_64 . V_351 ) >> 16 ;
int V_357 = F_248 ( & V_336 -> V_64 . V_351 ) >> 16 ;
int V_358 = F_245 ( V_89 , 0 , V_246 ) ;
int V_359 = 4096 ;
T_1 V_255 , V_276 , V_360 = V_336 -> V_361 . V_276 ;
if ( V_356 > V_358 || V_357 > V_359 ) {
F_161 ( L_52 ,
V_356 , V_357 , V_358 , V_359 ) ;
return - V_288 ;
}
F_207 ( & V_263 , & V_264 , V_336 , 0 ) ;
V_276 = F_212 ( & V_263 , & V_264 , V_336 , 0 ) ;
V_255 = F_187 ( V_6 , V_89 -> V_257 ) ;
if ( V_276 > V_360 )
V_276 = F_209 ( & V_263 , & V_264 , V_336 , 0 ,
V_276 , V_360 & ~ ( V_255 - 1 ) ) ;
if ( V_89 -> V_257 == V_231 ) {
int V_229 = V_89 -> V_266 -> V_229 [ 0 ] ;
while ( ( V_263 + V_356 ) * V_229 > V_89 -> V_262 [ 0 ] ) {
if ( V_276 == 0 ) {
F_161 ( L_53 ) ;
return - V_288 ;
}
V_276 = F_209 ( & V_263 , & V_264 , V_336 , 0 ,
V_276 , V_276 - V_255 ) ;
}
}
V_336 -> main. V_276 = V_276 ;
V_336 -> main. V_263 = V_263 ;
V_336 -> main. V_264 = V_264 ;
return 0 ;
}
static int F_249 ( struct V_265 * V_336 )
{
const struct V_245 * V_89 = V_336 -> V_64 . V_89 ;
unsigned int V_246 = V_336 -> V_64 . V_246 ;
int V_358 = F_245 ( V_89 , 1 , V_246 ) ;
int V_359 = 4096 ;
int V_263 = V_336 -> V_64 . V_351 . V_293 >> 17 ;
int V_264 = V_336 -> V_64 . V_351 . y1 >> 17 ;
int V_356 = F_247 ( & V_336 -> V_64 . V_351 ) >> 17 ;
int V_357 = F_248 ( & V_336 -> V_64 . V_351 ) >> 17 ;
T_1 V_276 ;
F_207 ( & V_263 , & V_264 , V_336 , 1 ) ;
V_276 = F_212 ( & V_263 , & V_264 , V_336 , 1 ) ;
if ( V_356 > V_358 || V_357 > V_359 ) {
F_161 ( L_54 ,
V_356 , V_357 , V_358 , V_359 ) ;
return - V_288 ;
}
V_336 -> V_361 . V_276 = V_276 ;
V_336 -> V_361 . V_263 = V_263 ;
V_336 -> V_361 . V_264 = V_264 ;
return 0 ;
}
int F_250 ( struct V_265 * V_336 )
{
const struct V_245 * V_89 = V_336 -> V_64 . V_89 ;
unsigned int V_246 = V_336 -> V_64 . V_246 ;
int V_362 ;
if ( ! V_336 -> V_64 . V_340 )
return 0 ;
if ( F_181 ( V_246 ) )
F_221 ( & V_336 -> V_64 . V_351 ,
V_89 -> V_242 << 16 , V_89 -> V_237 << 16 ,
V_296 ) ;
if ( V_89 -> V_266 -> V_266 == V_279 ) {
V_362 = F_249 ( V_336 ) ;
if ( V_362 )
return V_362 ;
} else {
V_336 -> V_361 . V_276 = ~ 0xfff ;
V_336 -> V_361 . V_263 = 0 ;
V_336 -> V_361 . V_264 = 0 ;
}
V_362 = F_246 ( V_336 ) ;
if ( V_362 )
return V_362 ;
return 0 ;
}
static void F_251 ( struct V_333 * V_88 ,
const struct V_37 * V_60 ,
const struct V_265 * V_336 )
{
struct V_5 * V_6 = F_41 ( V_88 -> V_63 ) ;
struct V_81 * V_81 = F_48 ( V_60 -> V_64 . V_65 ) ;
struct V_245 * V_89 = V_336 -> V_64 . V_89 ;
int V_133 = V_81 -> V_133 ;
T_1 V_280 ;
T_1 V_363 ;
T_3 V_13 = F_88 ( V_133 ) ;
unsigned int V_246 = V_336 -> V_64 . V_246 ;
int V_263 = V_336 -> V_64 . V_351 . V_293 >> 16 ;
int V_264 = V_336 -> V_64 . V_351 . y1 >> 16 ;
V_363 = V_364 ;
V_363 |= V_134 ;
if ( F_59 ( V_6 ) < 4 ) {
if ( V_81 -> V_94 == V_120 )
V_363 |= V_365 ;
F_124 ( F_252 ( V_133 ) ,
( ( V_60 -> V_366 - 1 ) << 16 ) |
( V_60 -> V_367 - 1 ) ) ;
F_124 ( F_253 ( V_133 ) , 0 ) ;
} else if ( F_17 ( V_6 ) && V_133 == V_368 ) {
F_124 ( F_254 ( V_133 ) ,
( ( V_60 -> V_366 - 1 ) << 16 ) |
( V_60 -> V_367 - 1 ) ) ;
F_124 ( F_255 ( V_133 ) , 0 ) ;
F_124 ( F_256 ( V_133 ) , 0 ) ;
}
switch ( V_89 -> V_266 -> V_266 ) {
case V_298 :
V_363 |= V_297 ;
break;
case V_300 :
V_363 |= V_299 ;
break;
case V_302 :
V_363 |= V_301 ;
break;
case V_304 :
V_363 |= V_303 ;
break;
case V_306 :
V_363 |= V_305 ;
break;
case V_308 :
V_363 |= V_307 ;
break;
case V_310 :
V_363 |= V_309 ;
break;
default:
F_146 () ;
}
if ( F_59 ( V_6 ) >= 4 &&
V_89 -> V_257 == V_231 )
V_363 |= V_369 ;
if ( V_246 & V_370 )
V_363 |= V_371 ;
if ( V_246 & V_372 )
V_363 |= V_373 ;
if ( F_18 ( V_6 ) )
V_363 |= V_374 ;
F_207 ( & V_263 , & V_264 , V_336 , 0 ) ;
if ( F_59 ( V_6 ) >= 4 )
V_81 -> V_375 =
F_212 ( & V_263 , & V_264 , V_336 , 0 ) ;
if ( V_246 & V_370 ) {
V_263 += V_60 -> V_367 - 1 ;
V_264 += V_60 -> V_366 - 1 ;
} else if ( V_246 & V_372 ) {
V_263 += V_60 -> V_367 - 1 ;
}
V_280 = F_206 ( V_263 , V_264 , V_336 , 0 ) ;
if ( F_59 ( V_6 ) < 4 )
V_81 -> V_375 = V_280 ;
V_81 -> V_376 = V_263 ;
V_81 -> V_377 = V_264 ;
F_124 ( V_13 , V_363 ) ;
F_124 ( F_257 ( V_133 ) , V_89 -> V_262 [ 0 ] ) ;
if ( F_59 ( V_6 ) >= 4 ) {
F_124 ( F_258 ( V_133 ) ,
F_238 ( V_336 ) +
V_81 -> V_375 ) ;
F_124 ( F_259 ( V_133 ) , ( V_264 << 16 ) | V_263 ) ;
F_124 ( F_260 ( V_133 ) , V_280 ) ;
} else {
F_124 ( F_261 ( V_133 ) ,
F_238 ( V_336 ) +
V_81 -> V_375 ) ;
}
F_125 ( V_13 ) ;
}
static void F_262 ( struct V_333 * V_88 ,
struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_133 = V_81 -> V_133 ;
F_124 ( F_88 ( V_133 ) , 0 ) ;
if ( F_184 ( V_6 ) -> V_250 >= 4 )
F_124 ( F_258 ( V_133 ) , 0 ) ;
else
F_124 ( F_261 ( V_133 ) , 0 ) ;
F_125 ( F_88 ( V_133 ) ) ;
}
static void F_263 ( struct V_333 * V_88 ,
const struct V_37 * V_60 ,
const struct V_265 * V_336 )
{
struct V_62 * V_63 = V_88 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_60 -> V_64 . V_65 ) ;
struct V_245 * V_89 = V_336 -> V_64 . V_89 ;
int V_133 = V_81 -> V_133 ;
T_1 V_280 ;
T_1 V_363 ;
T_3 V_13 = F_88 ( V_133 ) ;
unsigned int V_246 = V_336 -> V_64 . V_246 ;
int V_263 = V_336 -> V_64 . V_351 . V_293 >> 16 ;
int V_264 = V_336 -> V_64 . V_351 . y1 >> 16 ;
V_363 = V_364 ;
V_363 |= V_134 ;
if ( F_264 ( V_6 ) || F_265 ( V_6 ) )
V_363 |= V_378 ;
switch ( V_89 -> V_266 -> V_266 ) {
case V_298 :
V_363 |= V_297 ;
break;
case V_302 :
V_363 |= V_301 ;
break;
case V_304 :
V_363 |= V_303 ;
break;
case V_306 :
V_363 |= V_305 ;
break;
case V_308 :
V_363 |= V_307 ;
break;
case V_310 :
V_363 |= V_309 ;
break;
default:
F_146 () ;
}
if ( V_89 -> V_257 == V_231 )
V_363 |= V_369 ;
if ( V_246 & V_370 )
V_363 |= V_371 ;
if ( ! F_264 ( V_6 ) && ! F_265 ( V_6 ) )
V_363 |= V_374 ;
F_207 ( & V_263 , & V_264 , V_336 , 0 ) ;
V_81 -> V_375 =
F_212 ( & V_263 , & V_264 , V_336 , 0 ) ;
if ( ! F_264 ( V_6 ) && ! F_265 ( V_6 ) &&
V_246 & V_370 ) {
V_263 += V_60 -> V_367 - 1 ;
V_264 += V_60 -> V_366 - 1 ;
}
V_280 = F_206 ( V_263 , V_264 , V_336 , 0 ) ;
V_81 -> V_376 = V_263 ;
V_81 -> V_377 = V_264 ;
F_124 ( V_13 , V_363 ) ;
F_124 ( F_257 ( V_133 ) , V_89 -> V_262 [ 0 ] ) ;
F_124 ( F_258 ( V_133 ) ,
F_238 ( V_336 ) +
V_81 -> V_375 ) ;
if ( F_264 ( V_6 ) || F_265 ( V_6 ) ) {
F_124 ( F_266 ( V_133 ) , ( V_264 << 16 ) | V_263 ) ;
} else {
F_124 ( F_259 ( V_133 ) , ( V_264 << 16 ) | V_263 ) ;
F_124 ( F_260 ( V_133 ) , V_280 ) ;
}
F_125 ( V_13 ) ;
}
T_1 F_267 ( const struct V_5 * V_6 ,
V_55 V_228 , T_2 V_238 )
{
if ( V_228 == V_230 ) {
return 64 ;
} else {
int V_229 = F_176 ( V_238 , 0 ) ;
return F_170 ( V_6 , V_228 , V_229 ) ;
}
}
static void F_268 ( struct V_81 * V_81 , int V_379 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
F_124 ( F_269 ( V_81 -> V_94 , V_379 ) , 0 ) ;
F_124 ( F_270 ( V_81 -> V_94 , V_379 ) , 0 ) ;
F_124 ( F_271 ( V_81 -> V_94 , V_379 ) , 0 ) ;
}
static void F_272 ( struct V_81 * V_81 )
{
struct V_380 * V_381 ;
int V_135 ;
V_381 = & V_81 -> V_90 -> V_381 ;
for ( V_135 = 0 ; V_135 < V_81 -> V_382 ; V_135 ++ ) {
if ( ! V_381 -> V_383 [ V_135 ] . V_384 )
F_268 ( V_81 , V_135 ) ;
}
}
T_1 F_273 ( const struct V_245 * V_89 , int V_133 ,
unsigned int V_246 )
{
const struct V_5 * V_6 = F_41 ( V_89 -> V_63 ) ;
T_1 V_292 = F_205 ( V_89 , V_133 , V_246 ) ;
if ( F_181 ( V_246 ) ) {
int V_229 = V_89 -> V_266 -> V_229 [ V_133 ] ;
V_292 /= F_173 ( V_6 , V_89 -> V_257 , V_229 ) ;
} else {
V_292 /= F_267 ( V_6 , V_89 -> V_257 ,
V_89 -> V_266 -> V_266 ) ;
}
return V_292 ;
}
T_1 F_274 ( T_2 V_238 )
{
switch ( V_238 ) {
case V_298 :
return V_385 ;
case V_302 :
return V_313 ;
case V_306 :
return V_314 | V_386 ;
case V_304 :
return V_314 ;
case V_315 :
return V_314 | V_386 |
V_387 ;
case V_316 :
return V_314 |
V_387 ;
case V_308 :
return V_317 ;
case V_310 :
return V_386 | V_317 ;
case V_388 :
return V_389 | V_390 ;
case V_391 :
return V_389 | V_392 ;
case V_393 :
return V_389 | V_394 ;
case V_395 :
return V_389 | V_396 ;
default:
F_172 ( V_238 ) ;
}
return 0 ;
}
T_1 F_275 ( V_55 V_228 )
{
switch ( V_228 ) {
case V_230 :
break;
case V_231 :
return V_397 ;
case V_232 :
return V_398 ;
case V_233 :
return V_399 ;
default:
F_172 ( V_228 ) ;
}
return 0 ;
}
T_1 F_276 ( unsigned int V_246 )
{
switch ( V_246 ) {
case V_289 :
break;
case V_400 :
return V_401 ;
case V_370 :
return V_402 ;
case V_296 :
return V_403 ;
default:
F_172 ( V_246 ) ;
}
return 0 ;
}
static void F_277 ( struct V_333 * V_133 ,
const struct V_37 * V_60 ,
const struct V_265 * V_336 )
{
struct V_62 * V_63 = V_133 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_60 -> V_64 . V_65 ) ;
struct V_245 * V_89 = V_336 -> V_64 . V_89 ;
enum V_404 V_404 = F_234 ( V_133 ) -> V_379 ;
enum V_94 V_94 = F_234 ( V_133 ) -> V_94 ;
T_1 V_405 ;
unsigned int V_246 = V_336 -> V_64 . V_246 ;
T_1 V_292 = F_273 ( V_89 , 0 , V_246 ) ;
T_1 V_406 = V_336 -> main. V_276 ;
int V_407 = V_336 -> V_407 ;
int V_343 = V_336 -> main. V_263 ;
int V_344 = V_336 -> main. V_264 ;
int V_345 = F_247 ( & V_336 -> V_64 . V_351 ) >> 16 ;
int V_346 = F_248 ( & V_336 -> V_64 . V_351 ) >> 16 ;
int V_408 = V_336 -> V_64 . V_352 . V_293 ;
int V_409 = V_336 -> V_64 . V_352 . y1 ;
int V_410 = F_247 ( & V_336 -> V_64 . V_352 ) ;
int V_411 = F_248 ( & V_336 -> V_64 . V_352 ) ;
V_405 = V_140 |
V_412 |
V_413 ;
V_405 |= F_274 ( V_89 -> V_266 -> V_266 ) ;
V_405 |= F_275 ( V_89 -> V_257 ) ;
V_405 |= V_414 ;
V_405 |= F_276 ( V_246 ) ;
V_345 -- ;
V_346 -- ;
V_410 -- ;
V_411 -- ;
V_81 -> V_375 = V_406 ;
V_81 -> V_376 = V_343 ;
V_81 -> V_377 = V_344 ;
F_124 ( F_94 ( V_94 , V_404 ) , V_405 ) ;
F_124 ( F_278 ( V_94 , V_404 ) , ( V_344 << 16 ) | V_343 ) ;
F_124 ( F_279 ( V_94 , V_404 ) , V_292 ) ;
F_124 ( F_280 ( V_94 , V_404 ) , ( V_346 << 16 ) | V_345 ) ;
if ( V_407 >= 0 ) {
T_2 V_415 = 0 ;
F_28 ( ! V_410 || ! V_411 ) ;
V_415 = V_416 | F_281 ( V_404 ) |
V_60 -> V_381 . V_383 [ V_407 ] . V_417 ;
F_124 ( F_269 ( V_94 , V_407 ) , V_415 ) ;
F_124 ( F_282 ( V_94 , V_407 ) , 0 ) ;
F_124 ( F_270 ( V_94 , V_407 ) , ( V_408 << 16 ) | V_409 ) ;
F_124 ( F_271 ( V_94 , V_407 ) , ( V_410 << 16 ) | V_411 ) ;
F_124 ( F_283 ( V_94 , V_404 ) , 0 ) ;
} else {
F_124 ( F_283 ( V_94 , V_404 ) , ( V_409 << 16 ) | V_408 ) ;
}
F_124 ( F_284 ( V_94 , V_404 ) ,
F_238 ( V_336 ) + V_406 ) ;
F_125 ( F_284 ( V_94 , V_404 ) ) ;
}
static void F_285 ( struct V_333 * V_88 ,
struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_404 V_404 = F_234 ( V_88 ) -> V_379 ;
enum V_94 V_94 = F_234 ( V_88 ) -> V_94 ;
F_124 ( F_94 ( V_94 , V_404 ) , 0 ) ;
F_124 ( F_284 ( V_94 , V_404 ) , 0 ) ;
F_125 ( F_284 ( V_94 , V_404 ) ) ;
}
static int
F_286 ( struct V_145 * V_65 , struct V_245 * V_89 ,
int V_263 , int V_264 , enum V_418 V_43 )
{
F_127 ( L_55 ) ;
return - V_419 ;
}
static void F_287 ( struct V_5 * V_6 )
{
struct V_81 * V_65 ;
F_138 (&dev_priv->drm, crtc)
F_288 ( V_6 , V_65 -> V_94 ) ;
}
static void F_289 ( struct V_62 * V_63 )
{
struct V_145 * V_65 ;
F_237 (dev, crtc) {
struct V_337 * V_133 = F_234 ( V_65 -> V_88 ) ;
struct V_265 * V_336 =
F_235 ( V_133 -> V_64 . V_43 ) ;
if ( V_336 -> V_64 . V_340 )
V_133 -> V_420 ( & V_133 -> V_64 ,
F_290 ( V_65 -> V_43 ) ,
V_336 ) ;
}
}
static int
F_291 ( struct V_62 * V_63 ,
struct V_421 * V_43 )
{
struct V_42 * V_60 ;
struct V_145 * V_65 ;
int V_135 , V_362 ;
F_292 ( V_63 ) ;
F_293 ( F_41 ( V_63 ) ) ;
if ( ! V_43 )
return 0 ;
F_294 (state, crtc, crtc_state, i) {
V_60 -> V_422 = true ;
}
F_295 ( V_43 ) -> V_423 = true ;
V_362 = F_296 ( V_43 ) ;
F_28 ( V_362 == - V_424 ) ;
return V_362 ;
}
static bool F_297 ( struct V_5 * V_6 )
{
return F_298 ( V_6 ) &&
F_59 ( V_6 ) < 5 && ! F_18 ( V_6 ) ;
}
void F_299 ( struct V_5 * V_6 )
{
struct V_62 * V_63 = & V_6 -> V_260 ;
struct V_425 * V_426 = & V_6 -> V_427 ;
struct V_421 * V_43 ;
int V_362 ;
F_3 ( & V_63 -> V_428 . V_429 ) ;
F_300 ( V_426 , 0 ) ;
while ( 1 ) {
V_362 = F_301 ( V_63 , V_426 ) ;
if ( V_362 != - V_424 )
break;
F_302 ( V_426 ) ;
}
if ( ! V_259 . V_430 &&
! F_297 ( V_6 ) )
return;
V_43 = F_303 ( V_63 , V_426 ) ;
if ( F_194 ( V_43 ) ) {
V_362 = F_241 ( V_43 ) ;
F_127 ( L_56 , V_362 ) ;
return;
}
V_362 = F_304 ( V_63 , V_426 ) ;
if ( V_362 ) {
F_127 ( L_57 , V_362 ) ;
F_305 ( V_43 ) ;
return;
}
V_6 -> V_431 = V_43 ;
V_43 -> V_432 = V_426 ;
}
void F_306 ( struct V_5 * V_6 )
{
struct V_62 * V_63 = & V_6 -> V_260 ;
struct V_425 * V_426 = & V_6 -> V_427 ;
struct V_421 * V_43 = V_6 -> V_431 ;
int V_362 ;
F_287 ( V_6 ) ;
V_6 -> V_431 = NULL ;
if ( ! F_297 ( V_6 ) ) {
if ( ! V_43 ) {
F_289 ( V_63 ) ;
} else {
V_362 = F_291 ( V_63 , V_43 ) ;
if ( V_362 )
F_127 ( L_58 , V_362 ) ;
}
} else {
F_307 ( V_6 ) ;
F_308 ( V_6 ) ;
F_309 ( V_6 ) ;
F_310 ( V_63 ) ;
F_311 ( & V_6 -> V_433 ) ;
if ( V_6 -> V_434 . V_435 )
V_6 -> V_434 . V_435 ( V_6 ) ;
F_312 ( & V_6 -> V_433 ) ;
V_362 = F_291 ( V_63 , V_43 ) ;
if ( V_362 )
F_127 ( L_58 , V_362 ) ;
F_313 ( V_6 ) ;
}
if ( V_43 )
F_305 ( V_43 ) ;
F_314 ( V_426 ) ;
F_315 ( V_426 ) ;
F_5 ( & V_63 -> V_428 . V_429 ) ;
}
static bool F_316 ( struct V_81 * V_65 )
{
struct V_436 * error = & F_41 ( V_65 -> V_64 . V_63 ) -> V_437 ;
if ( F_317 ( error ) )
return true ;
if ( V_65 -> V_438 != F_318 ( error ) )
return true ;
return false ;
}
static bool F_319 ( struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
bool V_439 ;
if ( F_316 ( V_81 ) )
return false ;
F_311 ( & V_63 -> V_440 ) ;
V_439 = F_48 ( V_65 ) -> V_441 != NULL ;
F_312 ( & V_63 -> V_440 ) ;
return V_439 ;
}
static void F_320 ( struct V_81 * V_65 ,
struct V_37 * V_442 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
struct V_37 * V_38 =
F_290 ( V_65 -> V_64 . V_43 ) ;
V_65 -> V_64 . V_417 = V_65 -> V_64 . V_43 -> V_417 ;
F_124 ( F_321 ( V_65 -> V_94 ) ,
( ( V_38 -> V_367 - 1 ) << 16 ) |
( V_38 -> V_366 - 1 ) ) ;
if ( F_59 ( V_6 ) >= 9 ) {
F_272 ( V_65 ) ;
if ( V_38 -> V_443 . V_146 )
F_322 ( V_65 ) ;
} else if ( F_15 ( V_6 ) ) {
if ( V_38 -> V_443 . V_146 )
F_323 ( V_65 ) ;
else if ( V_442 -> V_443 . V_146 )
F_324 ( V_65 , true ) ;
}
}
static void F_325 ( struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_3 V_13 ;
T_1 V_444 ;
V_13 = F_70 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
if ( F_326 ( V_6 ) ) {
V_444 &= ~ V_445 ;
V_444 |= V_445 | V_446 ;
} else {
V_444 &= ~ V_447 ;
V_444 |= V_447 | V_446 ;
}
F_124 ( V_13 , V_444 ) ;
V_13 = F_72 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
if ( F_106 ( V_6 ) ) {
V_444 &= ~ V_448 ;
V_444 |= V_449 ;
} else {
V_444 &= ~ V_447 ;
V_444 |= V_447 ;
}
F_124 ( V_13 , V_444 | V_450 ) ;
F_125 ( V_13 ) ;
F_126 ( 1000 ) ;
if ( F_326 ( V_6 ) )
F_124 ( V_13 , F_11 ( V_13 ) | V_451 |
V_452 ) ;
}
static void F_327 ( struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_3 V_13 ;
T_1 V_444 , V_453 ;
F_328 ( V_6 , V_94 ) ;
V_13 = F_329 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_454 ;
V_444 &= ~ V_455 ;
F_124 ( V_13 , V_444 ) ;
F_11 ( V_13 ) ;
F_126 ( 150 ) ;
V_13 = F_70 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_456 ;
V_444 |= F_330 ( V_81 -> V_90 -> V_457 ) ;
V_444 &= ~ V_447 ;
V_444 |= V_458 ;
F_124 ( V_13 , V_444 | V_107 ) ;
V_13 = F_72 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_447 ;
V_444 |= V_458 ;
F_124 ( V_13 , V_444 | V_108 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
F_124 ( F_331 ( V_94 ) , V_459 ) ;
F_124 ( F_331 ( V_94 ) , V_459 |
V_460 ) ;
V_13 = F_332 ( V_94 ) ;
for ( V_453 = 0 ; V_453 < 5 ; V_453 ++ ) {
V_444 = F_11 ( V_13 ) ;
F_161 ( L_59 , V_444 ) ;
if ( ( V_444 & V_455 ) ) {
F_161 ( L_60 ) ;
F_124 ( V_13 , V_444 | V_455 ) ;
break;
}
}
if ( V_453 == 5 )
F_127 ( L_61 ) ;
V_13 = F_70 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_447 ;
V_444 |= V_461 ;
F_124 ( V_13 , V_444 ) ;
V_13 = F_72 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_447 ;
V_444 |= V_461 ;
F_124 ( V_13 , V_444 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
V_13 = F_332 ( V_94 ) ;
for ( V_453 = 0 ; V_453 < 5 ; V_453 ++ ) {
V_444 = F_11 ( V_13 ) ;
F_161 ( L_59 , V_444 ) ;
if ( V_444 & V_454 ) {
F_124 ( V_13 , V_444 | V_454 ) ;
F_161 ( L_62 ) ;
break;
}
}
if ( V_453 == 5 )
F_127 ( L_63 ) ;
F_161 ( L_64 ) ;
}
static void F_333 ( struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_3 V_13 ;
T_1 V_444 , V_135 , V_462 ;
V_13 = F_329 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_454 ;
V_444 &= ~ V_455 ;
F_124 ( V_13 , V_444 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
V_13 = F_70 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_456 ;
V_444 |= F_330 ( V_81 -> V_90 -> V_457 ) ;
V_444 &= ~ V_447 ;
V_444 |= V_458 ;
V_444 &= ~ V_463 ;
V_444 |= V_464 ;
F_124 ( V_13 , V_444 | V_107 ) ;
F_124 ( F_334 ( V_94 ) ,
V_465 | V_466 ) ;
V_13 = F_72 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
if ( F_106 ( V_6 ) ) {
V_444 &= ~ V_448 ;
V_444 |= V_467 ;
} else {
V_444 &= ~ V_447 ;
V_444 |= V_458 ;
}
F_124 ( V_13 , V_444 | V_108 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
for ( V_135 = 0 ; V_135 < 4 ; V_135 ++ ) {
V_13 = F_70 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_463 ;
V_444 |= V_468 [ V_135 ] ;
F_124 ( V_13 , V_444 ) ;
F_125 ( V_13 ) ;
F_126 ( 500 ) ;
for ( V_462 = 0 ; V_462 < 5 ; V_462 ++ ) {
V_13 = F_332 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
F_161 ( L_59 , V_444 ) ;
if ( V_444 & V_455 ) {
F_124 ( V_13 , V_444 | V_455 ) ;
F_161 ( L_60 ) ;
break;
}
F_126 ( 50 ) ;
}
if ( V_462 < 5 )
break;
}
if ( V_135 == 4 )
F_127 ( L_61 ) ;
V_13 = F_70 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_447 ;
V_444 |= V_461 ;
if ( F_335 ( V_6 ) ) {
V_444 &= ~ V_463 ;
V_444 |= V_464 ;
}
F_124 ( V_13 , V_444 ) ;
V_13 = F_72 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
if ( F_106 ( V_6 ) ) {
V_444 &= ~ V_448 ;
V_444 |= V_469 ;
} else {
V_444 &= ~ V_447 ;
V_444 |= V_461 ;
}
F_124 ( V_13 , V_444 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
for ( V_135 = 0 ; V_135 < 4 ; V_135 ++ ) {
V_13 = F_70 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_463 ;
V_444 |= V_468 [ V_135 ] ;
F_124 ( V_13 , V_444 ) ;
F_125 ( V_13 ) ;
F_126 ( 500 ) ;
for ( V_462 = 0 ; V_462 < 5 ; V_462 ++ ) {
V_13 = F_332 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
F_161 ( L_59 , V_444 ) ;
if ( V_444 & V_454 ) {
F_124 ( V_13 , V_444 | V_454 ) ;
F_161 ( L_62 ) ;
break;
}
F_126 ( 50 ) ;
}
if ( V_462 < 5 )
break;
}
if ( V_135 == 4 )
F_127 ( L_63 ) ;
F_161 ( L_65 ) ;
}
static void F_336 ( struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_3 V_13 ;
T_1 V_444 , V_135 , V_470 ;
V_13 = F_329 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_454 ;
V_444 &= ~ V_455 ;
F_124 ( V_13 , V_444 ) ;
F_125 ( V_13 ) ;
F_126 ( 150 ) ;
F_161 ( L_66 ,
F_11 ( F_332 ( V_94 ) ) ) ;
for ( V_470 = 0 ; V_470 < F_179 ( V_468 ) * 2 ; V_470 ++ ) {
V_13 = F_70 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ ( V_471 | V_445 ) ;
V_444 &= ~ V_107 ;
F_124 ( V_13 , V_444 ) ;
V_13 = F_72 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_471 ;
V_444 &= ~ V_448 ;
V_444 &= ~ V_108 ;
F_124 ( V_13 , V_444 ) ;
V_13 = F_70 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_456 ;
V_444 |= F_330 ( V_81 -> V_90 -> V_457 ) ;
V_444 |= V_472 ;
V_444 &= ~ V_463 ;
V_444 |= V_468 [ V_470 / 2 ] ;
V_444 |= V_473 ;
F_124 ( V_13 , V_444 | V_107 ) ;
F_124 ( F_334 ( V_94 ) ,
V_465 | V_466 ) ;
V_13 = F_72 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 |= V_467 ;
V_444 |= V_473 ;
F_124 ( V_13 , V_444 | V_108 ) ;
F_125 ( V_13 ) ;
F_126 ( 1 ) ;
for ( V_135 = 0 ; V_135 < 4 ; V_135 ++ ) {
V_13 = F_332 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
F_161 ( L_59 , V_444 ) ;
if ( V_444 & V_455 ||
( F_11 ( V_13 ) & V_455 ) ) {
F_124 ( V_13 , V_444 | V_455 ) ;
F_161 ( L_67 ,
V_135 ) ;
break;
}
F_126 ( 1 ) ;
}
if ( V_135 == 4 ) {
F_161 ( L_68 , V_470 / 2 ) ;
continue;
}
V_13 = F_70 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_445 ;
V_444 |= V_474 ;
F_124 ( V_13 , V_444 ) ;
V_13 = F_72 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_448 ;
V_444 |= V_469 ;
F_124 ( V_13 , V_444 ) ;
F_125 ( V_13 ) ;
F_126 ( 2 ) ;
for ( V_135 = 0 ; V_135 < 4 ; V_135 ++ ) {
V_13 = F_332 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
F_161 ( L_59 , V_444 ) ;
if ( V_444 & V_454 ||
( F_11 ( V_13 ) & V_454 ) ) {
F_124 ( V_13 , V_444 | V_454 ) ;
F_161 ( L_69 ,
V_135 ) ;
goto V_475;
}
F_126 ( 2 ) ;
}
if ( V_135 == 4 )
F_161 ( L_70 , V_470 / 2 ) ;
}
V_475:
F_161 ( L_65 ) ;
}
static void F_337 ( struct V_81 * V_81 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_81 -> V_94 ;
T_3 V_13 ;
T_1 V_444 ;
V_13 = F_72 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ ( V_456 | ( 0x7 << 16 ) ) ;
V_444 |= F_330 ( V_81 -> V_90 -> V_457 ) ;
V_444 |= ( F_11 ( F_60 ( V_94 ) ) & V_208 ) << 11 ;
F_124 ( V_13 , V_444 | V_110 ) ;
F_125 ( V_13 ) ;
F_126 ( 200 ) ;
V_444 = F_11 ( V_13 ) ;
F_124 ( V_13 , V_444 | V_476 ) ;
F_125 ( V_13 ) ;
F_126 ( 200 ) ;
V_13 = F_70 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
if ( ( V_444 & V_109 ) == 0 ) {
F_124 ( V_13 , V_444 | V_109 ) ;
F_125 ( V_13 ) ;
F_126 ( 100 ) ;
}
}
static void F_338 ( struct V_81 * V_81 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_81 -> V_94 ;
T_3 V_13 ;
T_1 V_444 ;
V_13 = F_72 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
F_124 ( V_13 , V_444 & ~ V_476 ) ;
V_13 = F_70 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
F_124 ( V_13 , V_444 & ~ V_109 ) ;
F_125 ( V_13 ) ;
F_126 ( 100 ) ;
V_13 = F_72 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
F_124 ( V_13 , V_444 & ~ V_110 ) ;
F_125 ( V_13 ) ;
F_126 ( 100 ) ;
}
static void F_339 ( struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_3 V_13 ;
T_1 V_444 ;
V_13 = F_70 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
F_124 ( V_13 , V_444 & ~ V_107 ) ;
F_125 ( V_13 ) ;
V_13 = F_72 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ ( 0x7 << 16 ) ;
V_444 |= ( F_11 ( F_60 ( V_94 ) ) & V_208 ) << 11 ;
F_124 ( V_13 , V_444 & ~ V_108 ) ;
F_125 ( V_13 ) ;
F_126 ( 100 ) ;
if ( F_120 ( V_6 ) )
F_124 ( F_331 ( V_94 ) , V_459 ) ;
V_13 = F_70 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ V_447 ;
V_444 |= V_458 ;
F_124 ( V_13 , V_444 ) ;
V_13 = F_72 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
if ( F_106 ( V_6 ) ) {
V_444 &= ~ V_448 ;
V_444 |= V_467 ;
} else {
V_444 &= ~ V_447 ;
V_444 |= V_458 ;
}
V_444 &= ~ ( 0x07 << 16 ) ;
V_444 |= ( F_11 ( F_60 ( V_94 ) ) & V_208 ) << 11 ;
F_124 ( V_13 , V_444 ) ;
F_125 ( V_13 ) ;
F_126 ( 100 ) ;
}
bool F_340 ( struct V_5 * V_6 )
{
struct V_81 * V_65 ;
F_138 (&dev_priv->drm, crtc) {
if ( F_341 ( & V_65 -> V_477 ) == 0 )
continue;
if ( V_65 -> V_441 )
F_342 ( V_6 , V_65 -> V_94 ) ;
return true ;
}
return false ;
}
static void F_343 ( struct V_81 * V_81 )
{
struct V_5 * V_6 = F_41 ( V_81 -> V_64 . V_63 ) ;
struct V_1 * V_2 = V_81 -> V_441 ;
V_81 -> V_441 = NULL ;
if ( V_2 -> V_478 )
F_344 ( & V_81 -> V_64 , V_2 -> V_478 ) ;
F_102 ( & V_81 -> V_64 ) ;
F_345 ( & V_6 -> V_479 ) ;
F_346 ( V_81 -> V_133 ,
V_2 -> V_480 ) ;
F_347 ( V_6 -> V_481 , & V_2 -> V_482 ) ;
}
static int F_348 ( struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
long V_362 ;
F_28 ( F_349 ( & V_6 -> V_479 ) ) ;
V_362 = F_350 (
V_6 -> V_479 ,
! F_319 ( V_65 ) ,
60 * V_483 ) ;
if ( V_362 < 0 )
return V_362 ;
if ( V_362 == 0 ) {
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_1 * V_2 ;
F_311 ( & V_63 -> V_440 ) ;
V_2 = V_81 -> V_441 ;
if ( V_2 && ! F_1 ( V_2 ) ) {
F_351 ( 1 , L_71 ) ;
F_343 ( V_81 ) ;
}
F_312 ( & V_63 -> V_440 ) ;
}
return 0 ;
}
void F_352 ( struct V_5 * V_6 )
{
T_1 V_444 ;
F_124 ( V_484 , V_485 ) ;
F_3 ( & V_6 -> V_9 ) ;
V_444 = F_353 ( V_6 , V_486 , V_487 ) ;
V_444 |= V_488 ;
F_354 ( V_6 , V_486 , V_444 , V_487 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_355 ( struct V_145 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
int clock = F_48 ( V_65 ) -> V_90 -> V_64 . V_91 . V_92 ;
T_1 V_489 , V_490 , V_491 , V_492 = 0 ;
T_1 V_444 ;
F_352 ( V_6 ) ;
for ( V_491 = 0 ; V_491 < 2 ; V_491 ++ ) {
T_1 V_493 = 172800 * 1000 ;
T_1 V_494 = 64 ;
T_1 V_495 ;
V_495 = F_8 ( V_493 ,
clock << V_491 ) ;
V_489 = ( V_495 / V_494 ) - 2 ;
V_490 = V_495 % V_494 ;
if ( V_489 <= 0x7f )
break;
}
F_28 ( F_356 ( V_489 ) &
~ V_496 ) ;
F_28 ( F_357 ( V_492 ) &
~ V_497 ) ;
F_161 ( L_72 ,
clock ,
V_491 ,
V_489 ,
V_492 ,
V_490 ) ;
F_3 ( & V_6 -> V_9 ) ;
V_444 = F_353 ( V_6 , V_498 , V_487 ) ;
V_444 &= ~ V_496 ;
V_444 |= F_356 ( V_489 ) ;
V_444 &= ~ V_497 ;
V_444 |= F_358 ( V_490 ) ;
V_444 |= F_357 ( V_492 ) ;
V_444 |= V_499 ;
F_354 ( V_6 , V_498 , V_444 , V_487 ) ;
V_444 = F_353 ( V_6 , V_500 , V_487 ) ;
V_444 &= ~ F_359 ( 1 ) ;
V_444 |= F_359 ( V_491 ) ;
F_354 ( V_6 , V_500 , V_444 , V_487 ) ;
V_444 = F_353 ( V_6 , V_486 , V_487 ) ;
V_444 &= ~ V_488 ;
F_354 ( V_6 , V_486 , V_444 , V_487 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_126 ( 24 ) ;
F_124 ( V_484 , V_501 ) ;
}
int F_360 ( struct V_5 * V_6 )
{
T_1 V_489 , V_490 , V_491 ;
T_1 V_493 = 172800 * 1000 ;
T_1 V_494 = 64 ;
T_1 V_495 ;
T_1 V_444 ;
if ( ( F_11 ( V_484 ) & V_501 ) == 0 )
return 0 ;
F_3 ( & V_6 -> V_9 ) ;
V_444 = F_353 ( V_6 , V_486 , V_487 ) ;
if ( V_444 & V_488 ) {
F_5 ( & V_6 -> V_9 ) ;
return 0 ;
}
V_444 = F_353 ( V_6 , V_498 , V_487 ) ;
V_489 = ( V_444 & V_496 ) >>
V_502 ;
V_490 = ( V_444 & V_497 ) >>
V_503 ;
V_444 = F_353 ( V_6 , V_500 , V_487 ) ;
V_491 = ( V_444 & V_504 ) >>
V_505 ;
F_5 ( & V_6 -> V_9 ) ;
V_495 = ( V_489 + 2 ) * V_494 + V_490 ;
return F_8 ( V_493 ,
V_495 << V_491 ) ;
}
static void F_361 ( struct V_81 * V_65 ,
enum V_94 V_506 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_93 V_95 = V_65 -> V_90 -> V_95 ;
F_124 ( F_362 ( V_506 ) ,
F_11 ( F_363 ( V_95 ) ) ) ;
F_124 ( F_364 ( V_506 ) ,
F_11 ( F_365 ( V_95 ) ) ) ;
F_124 ( F_366 ( V_506 ) ,
F_11 ( F_367 ( V_95 ) ) ) ;
F_124 ( F_368 ( V_506 ) ,
F_11 ( F_369 ( V_95 ) ) ) ;
F_124 ( F_370 ( V_506 ) ,
F_11 ( F_371 ( V_95 ) ) ) ;
F_124 ( F_372 ( V_506 ) ,
F_11 ( F_373 ( V_95 ) ) ) ;
F_124 ( F_374 ( V_506 ) ,
F_11 ( F_375 ( V_95 ) ) ) ;
}
static void F_376 ( struct V_62 * V_63 , bool V_507 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_2 V_444 ;
V_444 = F_11 ( V_508 ) ;
if ( ! ! ( V_444 & V_509 ) == V_507 )
return;
F_28 ( F_11 ( F_72 ( V_120 ) ) & V_108 ) ;
F_28 ( F_11 ( F_72 ( V_510 ) ) & V_108 ) ;
V_444 &= ~ V_509 ;
if ( V_507 )
V_444 |= V_509 ;
F_161 ( L_73 , V_507 ? L_74 : L_75 ) ;
F_124 ( V_508 , V_444 ) ;
F_125 ( V_508 ) ;
}
static void F_377 ( struct V_81 * V_81 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
switch ( V_81 -> V_94 ) {
case V_113 :
break;
case V_120 :
if ( V_81 -> V_90 -> V_457 > 2 )
F_376 ( V_63 , false ) ;
else
F_376 ( V_63 , true ) ;
break;
case V_510 :
F_376 ( V_63 , true ) ;
break;
default:
F_146 () ;
}
}
static enum V_178
F_378 ( struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_511 * V_512 ;
F_379 (dev, crtc, encoder) {
if ( V_512 -> type == V_513 ||
V_512 -> type == V_514 )
return F_380 ( & V_512 -> V_64 ) -> V_178 ;
}
return - 1 ;
}
static void F_381 ( struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_1 V_444 ;
F_103 ( V_6 , V_94 ) ;
if ( F_326 ( V_6 ) )
F_377 ( V_81 ) ;
F_124 ( F_382 ( V_94 ) ,
F_11 ( F_383 ( V_94 ) ) & V_515 ) ;
V_6 -> V_434 . V_516 ( V_65 ) ;
if ( F_106 ( V_6 ) ) {
T_1 V_517 ;
V_444 = F_11 ( V_518 ) ;
V_444 |= F_384 ( V_94 ) ;
V_517 = F_385 ( V_94 ) ;
if ( V_81 -> V_90 -> V_206 ==
F_386 ( V_6 , V_519 ) )
V_444 |= V_517 ;
else
V_444 &= ~ V_517 ;
F_124 ( V_518 , V_444 ) ;
}
F_387 ( V_81 ) ;
F_75 ( V_6 , V_94 ) ;
F_361 ( V_81 , V_94 ) ;
F_325 ( V_65 ) ;
if ( F_106 ( V_6 ) &&
F_388 ( V_81 -> V_90 ) ) {
const struct V_520 * V_91 =
& V_81 -> V_90 -> V_64 . V_91 ;
T_1 V_521 = ( F_11 ( F_60 ( V_94 ) ) & V_208 ) >> 5 ;
T_3 V_13 = F_107 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ ( V_150 |
V_522 |
V_523 ) ;
V_444 |= V_524 ;
V_444 |= V_521 << 9 ;
if ( V_91 -> V_330 & V_525 )
V_444 |= V_526 ;
if ( V_91 -> V_330 & V_527 )
V_444 |= V_528 ;
switch ( F_378 ( V_65 ) ) {
case V_198 :
V_444 |= V_165 ;
break;
case V_200 :
V_444 |= V_167 ;
break;
case V_202 :
V_444 |= V_169 ;
break;
default:
F_146 () ;
}
F_124 ( V_13 , V_444 ) ;
}
F_148 ( V_6 , V_94 ) ;
}
static void F_389 ( struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
enum V_93 V_95 = V_81 -> V_90 -> V_95 ;
F_103 ( V_6 , V_219 ) ;
F_355 ( V_65 ) ;
F_361 ( V_81 , V_113 ) ;
F_153 ( V_6 , V_95 ) ;
}
static void F_390 ( struct V_62 * V_63 , int V_94 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_3 V_529 = F_55 ( V_94 ) ;
T_1 V_444 ;
V_444 = F_11 ( V_529 ) ;
F_126 ( 500 ) ;
if ( F_62 ( F_11 ( V_529 ) != V_444 , 5 ) ) {
if ( F_62 ( F_11 ( V_529 ) != V_444 , 5 ) )
F_127 ( L_76 , F_78 ( V_94 ) ) ;
}
}
static int
F_391 ( struct V_37 * V_60 , bool V_530 ,
unsigned V_531 , int * V_407 , unsigned int V_246 ,
int V_345 , int V_346 , int V_410 , int V_411 )
{
struct V_380 * V_381 =
& V_60 -> V_381 ;
struct V_81 * V_81 =
F_48 ( V_60 -> V_64 . V_65 ) ;
int V_532 ;
V_532 = F_181 ( V_246 ) ?
( V_346 != V_410 || V_345 != V_411 ) :
( V_345 != V_410 || V_346 != V_411 ) ;
if ( V_530 || ! V_532 ) {
if ( * V_407 >= 0 ) {
V_381 -> V_533 &= ~ ( 1 << V_531 ) ;
V_381 -> V_383 [ * V_407 ] . V_384 = 0 ;
F_161 ( L_77
L_78 ,
V_81 -> V_94 , V_531 , * V_407 ,
V_381 -> V_533 ) ;
* V_407 = - 1 ;
}
return 0 ;
}
if ( V_345 < V_534 || V_346 < V_535 ||
V_410 < V_536 || V_411 < V_537 ||
V_345 > V_538 || V_346 > V_539 ||
V_410 > V_540 || V_411 > V_541 ) {
F_161 ( L_79
L_80 ,
V_81 -> V_94 , V_531 , V_345 , V_346 , V_410 , V_411 ) ;
return - V_288 ;
}
V_381 -> V_533 |= ( 1 << V_531 ) ;
F_161 ( L_77
L_81 ,
V_81 -> V_94 , V_531 , V_345 , V_346 , V_410 , V_411 ,
V_381 -> V_533 ) ;
return 0 ;
}
int F_392 ( struct V_37 * V_43 )
{
const struct V_520 * V_91 = & V_43 -> V_64 . V_91 ;
return F_391 ( V_43 , ! V_43 -> V_64 . V_87 , V_542 ,
& V_43 -> V_381 . V_407 , V_289 ,
V_43 -> V_367 , V_43 -> V_366 ,
V_91 -> V_543 , V_91 -> V_544 ) ;
}
static int F_393 ( struct V_37 * V_60 ,
struct V_265 * V_336 )
{
struct V_337 * V_337 =
F_234 ( V_336 -> V_64 . V_133 ) ;
struct V_245 * V_89 = V_336 -> V_64 . V_89 ;
int V_362 ;
bool V_530 = ! V_89 || ! V_336 -> V_64 . V_340 ;
V_362 = F_391 ( V_60 , V_530 ,
F_239 ( & V_337 -> V_64 ) ,
& V_336 -> V_407 ,
V_336 -> V_64 . V_246 ,
F_247 ( & V_336 -> V_64 . V_351 ) >> 16 ,
F_248 ( & V_336 -> V_64 . V_351 ) >> 16 ,
F_247 ( & V_336 -> V_64 . V_352 ) ,
F_248 ( & V_336 -> V_64 . V_352 ) ) ;
if ( V_362 || V_336 -> V_407 < 0 )
return V_362 ;
if ( V_336 -> V_545 . V_330 != V_546 ) {
F_161 ( L_82 ,
V_337 -> V_64 . V_64 . V_379 ,
V_337 -> V_64 . V_12 ) ;
return - V_288 ;
}
switch ( V_89 -> V_266 -> V_266 ) {
case V_302 :
case V_306 :
case V_304 :
case V_315 :
case V_316 :
case V_308 :
case V_310 :
case V_388 :
case V_391 :
case V_393 :
case V_395 :
break;
default:
F_161 ( L_83 ,
V_337 -> V_64 . V_64 . V_379 , V_337 -> V_64 . V_12 ,
V_89 -> V_64 . V_379 , V_89 -> V_266 -> V_266 ) ;
return - V_288 ;
}
return 0 ;
}
static void F_394 ( struct V_81 * V_65 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < V_65 -> V_382 ; V_135 ++ )
F_268 ( V_65 , V_135 ) ;
}
static void F_322 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_65 -> V_94 ;
struct V_380 * V_381 =
& V_65 -> V_90 -> V_381 ;
if ( V_65 -> V_90 -> V_443 . V_146 ) {
int V_379 ;
if ( F_28 ( V_65 -> V_90 -> V_381 . V_407 < 0 ) )
return;
V_379 = V_381 -> V_407 ;
F_124 ( F_269 ( V_94 , V_379 ) , V_416 |
V_547 | V_381 -> V_383 [ V_379 ] . V_417 ) ;
F_124 ( F_270 ( V_94 , V_379 ) , V_65 -> V_90 -> V_443 . V_548 ) ;
F_124 ( F_271 ( V_94 , V_379 ) , V_65 -> V_90 -> V_443 . V_241 ) ;
}
}
static void F_323 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_65 -> V_94 ;
if ( V_65 -> V_90 -> V_443 . V_146 ) {
if ( F_326 ( V_6 ) || F_264 ( V_6 ) )
F_124 ( F_395 ( V_94 ) , V_549 | V_550 |
F_396 ( V_94 ) ) ;
else
F_124 ( F_395 ( V_94 ) , V_549 | V_550 ) ;
F_124 ( F_397 ( V_94 ) , V_65 -> V_90 -> V_443 . V_548 ) ;
F_124 ( F_398 ( V_94 ) , V_65 -> V_90 -> V_443 . V_241 ) ;
}
}
void F_399 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
if ( ! V_65 -> V_90 -> V_551 )
return;
F_400 ( V_6 , V_65 -> V_133 ) ;
if ( F_265 ( V_6 ) ) {
F_3 ( & V_6 -> V_552 . V_553 ) ;
F_28 ( F_401 ( V_6 , V_554 , 0xc0000000 ) ) ;
F_5 ( & V_6 -> V_552 . V_553 ) ;
} else {
F_124 ( V_555 , V_556 ) ;
if ( F_61 ( V_6 ,
V_555 , V_556 , V_556 ,
50 ) )
F_127 ( L_84 ) ;
}
}
void F_402 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
if ( ! V_65 -> V_90 -> V_551 )
return;
F_400 ( V_6 , V_65 -> V_133 ) ;
if ( F_265 ( V_6 ) ) {
F_3 ( & V_6 -> V_552 . V_553 ) ;
F_28 ( F_401 ( V_6 , V_554 , 0 ) ) ;
F_5 ( & V_6 -> V_552 . V_553 ) ;
if ( F_61 ( V_6 ,
V_555 , V_556 , 0 ,
42 ) )
F_127 ( L_85 ) ;
} else {
F_124 ( V_555 , 0 ) ;
F_125 ( V_555 ) ;
}
F_342 ( V_6 , V_65 -> V_94 ) ;
}
static void F_403 ( struct V_81 * V_81 )
{
if ( V_81 -> V_557 ) {
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
F_3 ( & V_63 -> V_256 ) ;
V_6 -> V_558 . V_559 = false ;
( void ) F_404 ( V_81 -> V_557 ) ;
V_6 -> V_558 . V_559 = true ;
F_5 ( & V_63 -> V_256 ) ;
}
}
static void
F_405 ( struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
F_399 ( V_81 ) ;
if ( F_56 ( V_6 ) )
F_406 ( V_6 , V_94 , true ) ;
F_407 ( V_6 ) ;
F_408 ( V_6 ) ;
}
static void
F_409 ( struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
if ( F_56 ( V_6 ) )
F_406 ( V_6 , V_94 , false ) ;
F_402 ( V_81 ) ;
}
static void
F_240 ( struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
F_409 ( V_65 ) ;
if ( F_163 ( V_6 ) &&
F_410 ( V_6 , false ) )
F_342 ( V_6 , V_94 ) ;
}
static void F_411 ( struct V_37 * V_442 )
{
struct V_81 * V_65 = F_48 ( V_442 -> V_64 . V_65 ) ;
struct V_421 * V_560 = V_442 -> V_64 . V_43 ;
struct V_37 * V_38 =
F_290 ( V_65 -> V_64 . V_43 ) ;
struct V_333 * V_88 = V_65 -> V_64 . V_88 ;
struct V_335 * V_561 =
F_412 ( V_560 , V_88 ) ;
F_413 ( F_41 ( V_65 -> V_64 . V_63 ) , V_38 -> V_562 ) ;
V_65 -> V_563 . V_564 = true ;
if ( V_38 -> V_565 && V_38 -> V_64 . V_87 )
F_414 ( V_65 ) ;
if ( V_561 ) {
struct V_265 * V_566 =
F_235 ( V_88 -> V_43 ) ;
struct V_265 * V_567 =
F_235 ( V_561 ) ;
F_415 ( V_65 ) ;
if ( V_566 -> V_64 . V_340 &&
( F_25 ( & V_38 -> V_64 ) ||
! V_567 -> V_64 . V_340 ) )
F_405 ( & V_65 -> V_64 ) ;
}
}
static void F_416 ( struct V_37 * V_442 )
{
struct V_81 * V_65 = F_48 ( V_442 -> V_64 . V_65 ) ;
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_37 * V_38 =
F_290 ( V_65 -> V_64 . V_43 ) ;
struct V_421 * V_560 = V_442 -> V_64 . V_43 ;
struct V_333 * V_88 = V_65 -> V_64 . V_88 ;
struct V_335 * V_561 =
F_412 ( V_560 , V_88 ) ;
bool V_568 = F_25 ( & V_38 -> V_64 ) ;
struct V_569 * V_570 =
F_295 ( V_560 ) ;
if ( V_561 ) {
struct V_265 * V_566 =
F_235 ( V_88 -> V_43 ) ;
struct V_265 * V_567 =
F_235 ( V_561 ) ;
F_417 ( V_65 , V_38 , V_566 ) ;
if ( V_567 -> V_64 . V_340 &&
( V_568 || ! V_566 -> V_64 . V_340 ) )
F_409 ( & V_65 -> V_64 ) ;
}
if ( V_38 -> V_571 && F_163 ( V_6 ) ) {
V_65 -> V_563 . V_564 = false ;
if ( V_442 -> V_64 . V_87 &&
F_410 ( V_6 , false ) )
F_342 ( V_6 , V_65 -> V_94 ) ;
}
if ( V_38 -> V_572 && F_418 ( V_63 ) )
F_342 ( V_6 , V_65 -> V_94 ) ;
if ( F_25 ( & V_38 -> V_64 ) )
return;
if ( V_6 -> V_434 . V_573 != NULL )
V_6 -> V_434 . V_573 ( V_570 ,
V_38 ) ;
else if ( V_38 -> V_574 )
F_414 ( V_65 ) ;
}
static void F_419 ( struct V_145 * V_65 , unsigned V_341 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_333 * V_48 ;
int V_94 = V_81 -> V_94 ;
F_403 ( V_81 ) ;
F_420 (p, dev, plane_mask)
F_234 ( V_48 ) -> V_342 ( V_48 , V_65 ) ;
F_413 ( F_41 ( V_63 ) , F_421 ( V_94 ) ) ;
}
static void F_422 ( struct V_145 * V_65 ,
struct V_37 * V_60 ,
struct V_421 * V_560 )
{
struct V_575 * V_576 ;
struct V_577 * V_578 ;
int V_135 ;
F_423 (old_state, conn, old_conn_state, i) {
struct V_575 * V_579 = V_578 -> V_43 ;
struct V_511 * V_512 =
F_424 ( V_579 -> V_580 ) ;
if ( V_579 -> V_65 != V_65 )
continue;
if ( V_512 -> V_581 )
V_512 -> V_581 ( V_512 , V_60 , V_579 ) ;
}
}
static void F_425 ( struct V_145 * V_65 ,
struct V_37 * V_60 ,
struct V_421 * V_560 )
{
struct V_575 * V_576 ;
struct V_577 * V_578 ;
int V_135 ;
F_423 (old_state, conn, old_conn_state, i) {
struct V_575 * V_579 = V_578 -> V_43 ;
struct V_511 * V_512 =
F_424 ( V_579 -> V_580 ) ;
if ( V_579 -> V_65 != V_65 )
continue;
if ( V_512 -> V_582 )
V_512 -> V_582 ( V_512 , V_60 , V_579 ) ;
}
}
static void F_426 ( struct V_145 * V_65 ,
struct V_37 * V_60 ,
struct V_421 * V_560 )
{
struct V_575 * V_576 ;
struct V_577 * V_578 ;
int V_135 ;
F_423 (old_state, conn, old_conn_state, i) {
struct V_575 * V_579 = V_578 -> V_43 ;
struct V_511 * V_512 =
F_424 ( V_579 -> V_580 ) ;
if ( V_579 -> V_65 != V_65 )
continue;
V_512 -> V_507 ( V_512 , V_60 , V_579 ) ;
F_427 ( V_512 , true ) ;
}
}
static void F_428 ( struct V_145 * V_65 ,
struct V_37 * V_442 ,
struct V_421 * V_560 )
{
struct V_575 * V_576 ;
struct V_577 * V_578 ;
int V_135 ;
F_423 (old_state, conn, old_conn_state, i) {
struct V_511 * V_512 =
F_424 ( V_576 -> V_580 ) ;
if ( V_576 -> V_65 != V_65 )
continue;
F_427 ( V_512 , false ) ;
V_512 -> V_583 ( V_512 , V_442 , V_576 ) ;
}
}
static void F_429 ( struct V_145 * V_65 ,
struct V_37 * V_442 ,
struct V_421 * V_560 )
{
struct V_575 * V_576 ;
struct V_577 * V_578 ;
int V_135 ;
F_423 (old_state, conn, old_conn_state, i) {
struct V_511 * V_512 =
F_424 ( V_576 -> V_580 ) ;
if ( V_576 -> V_65 != V_65 )
continue;
if ( V_512 -> V_584 )
V_512 -> V_584 ( V_512 , V_442 , V_576 ) ;
}
}
static void F_430 ( struct V_145 * V_65 ,
struct V_37 * V_442 ,
struct V_421 * V_560 )
{
struct V_575 * V_576 ;
struct V_577 * V_578 ;
int V_135 ;
F_423 (old_state, conn, old_conn_state, i) {
struct V_511 * V_512 =
F_424 ( V_576 -> V_580 ) ;
if ( V_576 -> V_65 != V_65 )
continue;
if ( V_512 -> V_585 )
V_512 -> V_585 ( V_512 , V_442 , V_576 ) ;
}
}
static void F_431 ( struct V_37 * V_38 ,
struct V_421 * V_560 )
{
struct V_145 * V_65 = V_38 -> V_64 . V_65 ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
struct V_569 * V_570 =
F_295 ( V_560 ) ;
if ( F_28 ( V_81 -> V_87 ) )
return;
if ( V_81 -> V_90 -> V_222 || F_24 ( V_6 ) )
F_406 ( V_6 , V_94 , false ) ;
if ( V_81 -> V_90 -> V_222 )
F_432 ( V_6 , V_94 , false ) ;
if ( V_81 -> V_90 -> V_222 )
F_433 ( V_81 ) ;
if ( F_388 ( V_81 -> V_90 ) )
F_434 ( V_81 , V_586 ) ;
F_435 ( V_81 ) ;
F_436 ( V_81 ) ;
if ( V_81 -> V_90 -> V_222 ) {
F_437 ( V_81 ,
& V_81 -> V_90 -> V_587 , NULL ) ;
}
F_438 ( V_65 ) ;
V_81 -> V_87 = true ;
F_425 ( V_65 , V_38 , V_560 ) ;
if ( V_81 -> V_90 -> V_222 ) {
F_337 ( V_81 ) ;
} else {
F_155 ( V_6 , V_94 ) ;
F_156 ( V_6 , V_94 ) ;
}
F_323 ( V_81 ) ;
F_439 ( & V_38 -> V_64 ) ;
if ( V_6 -> V_434 . V_573 != NULL )
V_6 -> V_434 . V_573 ( V_570 , V_81 -> V_90 ) ;
F_160 ( V_81 ) ;
if ( V_81 -> V_90 -> V_222 )
F_381 ( V_65 ) ;
F_99 ( V_65 ) ;
F_440 ( V_65 ) ;
F_426 ( V_65 , V_38 , V_560 ) ;
if ( F_106 ( V_6 ) )
F_390 ( V_63 , V_81 -> V_94 ) ;
if ( V_81 -> V_90 -> V_222 )
F_342 ( V_6 , V_94 ) ;
F_406 ( V_6 , V_94 , true ) ;
F_432 ( V_6 , V_94 , true ) ;
}
static bool F_441 ( struct V_81 * V_65 )
{
return F_442 ( F_41 ( V_65 -> V_64 . V_63 ) ) && V_65 -> V_94 == V_113 ;
}
static void F_443 ( struct V_37 * V_38 ,
struct V_421 * V_560 )
{
struct V_145 * V_65 = V_38 -> V_64 . V_65 ;
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 , V_588 ;
enum V_93 V_95 = V_81 -> V_90 -> V_95 ;
struct V_569 * V_570 =
F_295 ( V_560 ) ;
if ( F_28 ( V_81 -> V_87 ) )
return;
if ( V_81 -> V_90 -> V_222 )
F_432 ( V_6 , V_219 ,
false ) ;
F_422 ( V_65 , V_38 , V_560 ) ;
if ( V_81 -> V_90 -> V_206 )
F_387 ( V_81 ) ;
if ( F_388 ( V_81 -> V_90 ) )
F_434 ( V_81 , V_586 ) ;
if ( ! F_444 ( V_95 ) )
F_435 ( V_81 ) ;
F_436 ( V_81 ) ;
if ( V_95 != V_589 &&
! F_444 ( V_95 ) ) {
F_124 ( F_445 ( V_95 ) ,
V_81 -> V_90 -> V_590 - 1 ) ;
}
if ( V_81 -> V_90 -> V_222 ) {
F_437 ( V_81 ,
& V_81 -> V_90 -> V_587 , NULL ) ;
}
if ( ! F_444 ( V_95 ) )
F_446 ( V_65 ) ;
F_447 ( V_65 ) ;
F_448 ( & V_38 -> V_64 ) ;
V_81 -> V_87 = true ;
if ( V_81 -> V_90 -> V_222 )
F_406 ( V_6 , V_94 , false ) ;
else
F_406 ( V_6 , V_94 , true ) ;
F_425 ( V_65 , V_38 , V_560 ) ;
if ( V_81 -> V_90 -> V_222 )
V_6 -> V_434 . V_516 ( V_65 ) ;
if ( ! F_444 ( V_95 ) )
F_449 ( V_81 ) ;
if ( F_59 ( V_6 ) >= 9 )
F_322 ( V_81 ) ;
else
F_323 ( V_81 ) ;
F_439 ( & V_38 -> V_64 ) ;
F_450 ( V_65 ) ;
if ( ! F_444 ( V_95 ) )
F_451 ( V_65 ) ;
if ( V_6 -> V_434 . V_573 != NULL )
V_6 -> V_434 . V_573 ( V_570 , V_38 ) ;
if ( ! F_444 ( V_95 ) )
F_160 ( V_81 ) ;
if ( V_81 -> V_90 -> V_222 )
F_389 ( V_65 ) ;
if ( F_38 ( V_81 -> V_90 , V_591 ) )
F_452 ( V_65 , true ) ;
F_99 ( V_65 ) ;
F_440 ( V_65 ) ;
F_426 ( V_65 , V_38 , V_560 ) ;
if ( V_81 -> V_90 -> V_222 ) {
F_342 ( V_6 , V_94 ) ;
F_342 ( V_6 , V_94 ) ;
F_406 ( V_6 , V_94 , true ) ;
F_432 ( V_6 , V_219 ,
true ) ;
}
V_588 = V_38 -> V_588 ;
if ( F_264 ( V_6 ) && V_588 != V_592 ) {
F_342 ( V_6 , V_588 ) ;
F_342 ( V_6 , V_588 ) ;
}
}
static void F_324 ( struct V_81 * V_65 , bool V_593 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_65 -> V_94 ;
if ( V_593 || V_65 -> V_90 -> V_443 . V_146 ) {
F_124 ( F_395 ( V_94 ) , 0 ) ;
F_124 ( F_397 ( V_94 ) , 0 ) ;
F_124 ( F_398 ( V_94 ) , 0 ) ;
}
}
static void F_453 ( struct V_37 * V_442 ,
struct V_421 * V_560 )
{
struct V_145 * V_65 = V_442 -> V_64 . V_65 ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
if ( V_81 -> V_90 -> V_222 ) {
F_406 ( V_6 , V_94 , false ) ;
F_432 ( V_6 , V_94 , false ) ;
}
F_428 ( V_65 , V_442 , V_560 ) ;
F_454 ( V_65 ) ;
F_99 ( V_65 ) ;
F_168 ( V_81 ) ;
F_324 ( V_81 , false ) ;
if ( V_81 -> V_90 -> V_222 )
F_339 ( V_65 ) ;
F_429 ( V_65 , V_442 , V_560 ) ;
if ( V_81 -> V_90 -> V_222 ) {
F_154 ( V_6 , V_94 ) ;
if ( F_106 ( V_6 ) ) {
T_3 V_13 ;
T_1 V_444 ;
V_13 = F_107 ( V_94 ) ;
V_444 = F_11 ( V_13 ) ;
V_444 &= ~ ( V_524 |
V_150 ) ;
V_444 |= V_594 ;
F_124 ( V_13 , V_444 ) ;
V_444 = F_11 ( V_518 ) ;
V_444 &= ~ ( F_384 ( V_94 ) | F_385 ( V_94 ) ) ;
F_124 ( V_518 , V_444 ) ;
}
F_338 ( V_81 ) ;
}
F_406 ( V_6 , V_94 , true ) ;
F_432 ( V_6 , V_94 , true ) ;
}
static void F_455 ( struct V_37 * V_442 ,
struct V_421 * V_560 )
{
struct V_145 * V_65 = V_442 -> V_64 . V_65 ;
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
enum V_93 V_95 = V_81 -> V_90 -> V_95 ;
if ( V_81 -> V_90 -> V_222 )
F_432 ( V_6 , V_219 ,
false ) ;
F_428 ( V_65 , V_442 , V_560 ) ;
F_454 ( V_65 ) ;
F_99 ( V_65 ) ;
if ( ! F_444 ( V_95 ) )
F_168 ( V_81 ) ;
if ( F_38 ( V_81 -> V_90 , V_591 ) )
F_452 ( V_65 , false ) ;
if ( ! F_444 ( V_95 ) )
F_456 ( V_6 , V_95 ) ;
if ( F_59 ( V_6 ) >= 9 )
F_394 ( V_81 ) ;
else
F_324 ( V_81 , false ) ;
if ( ! F_444 ( V_95 ) )
F_457 ( V_81 ) ;
F_429 ( V_65 , V_442 , V_560 ) ;
if ( V_442 -> V_222 )
F_432 ( V_6 , V_219 ,
true ) ;
}
static void F_458 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_37 * V_38 = V_65 -> V_90 ;
if ( ! V_38 -> V_595 . V_596 )
return;
F_28 ( F_11 ( V_597 ) & V_598 ) ;
F_129 ( V_6 , V_65 -> V_94 ) ;
F_124 ( V_599 , V_38 -> V_595 . V_600 ) ;
F_124 ( V_597 , V_38 -> V_595 . V_596 ) ;
F_124 ( F_459 ( V_65 -> V_94 ) , 0 ) ;
}
static enum V_127 F_460 ( enum V_178 V_178 )
{
switch ( V_178 ) {
case V_601 :
return V_602 ;
case V_198 :
return V_603 ;
case V_200 :
return V_604 ;
case V_202 :
return V_605 ;
case V_606 :
return V_607 ;
default:
F_172 ( V_178 ) ;
return V_608 ;
}
}
static enum V_127 F_461 ( enum V_178 V_178 )
{
switch ( V_178 ) {
case V_601 :
return V_609 ;
case V_198 :
return V_610 ;
case V_200 :
return V_611 ;
case V_202 :
return V_612 ;
case V_606 :
return V_612 ;
default:
F_172 ( V_178 ) ;
return V_609 ;
}
}
enum V_127
F_462 ( struct V_511 * V_511 )
{
struct V_5 * V_6 = F_41 ( V_511 -> V_64 . V_63 ) ;
struct V_193 * V_613 ;
switch ( V_511 -> type ) {
case V_614 :
F_45 ( ! F_23 ( V_6 ) ) ;
case V_513 :
case V_209 :
case V_514 :
V_613 = F_380 ( & V_511 -> V_64 ) ;
return F_460 ( V_613 -> V_178 ) ;
case V_591 :
V_613 = F_463 ( & V_511 -> V_64 ) -> V_88 ;
return F_460 ( V_613 -> V_178 ) ;
case V_615 :
return V_616 ;
case V_223 :
return V_617 ;
default:
return V_608 ;
}
}
enum V_127
F_464 ( struct V_511 * V_511 )
{
struct V_5 * V_6 = F_41 ( V_511 -> V_64 . V_63 ) ;
struct V_193 * V_613 ;
switch ( V_511 -> type ) {
case V_614 :
case V_209 :
F_45 ( ! F_23 ( V_6 ) ) ;
case V_513 :
case V_514 :
V_613 = F_380 ( & V_511 -> V_64 ) ;
return F_461 ( V_613 -> V_178 ) ;
case V_591 :
V_613 = F_463 ( & V_511 -> V_64 ) -> V_88 ;
return F_461 ( V_613 -> V_178 ) ;
default:
F_172 ( V_511 -> type ) ;
return V_609 ;
}
}
static unsigned long F_465 ( struct V_145 * V_65 ,
struct V_37 * V_60 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_618 * V_512 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
enum V_94 V_94 = V_81 -> V_94 ;
unsigned long V_619 ;
enum V_93 V_93 = V_60 -> V_95 ;
if ( ! V_60 -> V_64 . V_87 )
return 0 ;
V_619 = F_466 ( F_467 ( V_94 ) ) ;
V_619 |= F_466 ( F_84 ( V_93 ) ) ;
if ( V_60 -> V_443 . V_146 ||
V_60 -> V_443 . V_620 )
V_619 |= F_466 ( F_468 ( V_94 ) ) ;
F_469 (encoder, dev, crtc_state->base.encoder_mask) {
struct V_511 * V_511 = F_424 ( V_512 ) ;
V_619 |= F_466 ( F_462 ( V_511 ) ) ;
}
if ( V_60 -> V_206 )
V_619 |= F_466 ( V_621 ) ;
return V_619 ;
}
static unsigned long
F_470 ( struct V_145 * V_65 ,
struct V_37 * V_60 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
enum V_127 V_622 ;
unsigned long V_623 , V_624 , V_625 ;
V_625 = V_81 -> V_626 ;
V_81 -> V_626 = V_624 =
F_465 ( V_65 , V_60 ) ;
V_623 = V_624 & ~ V_625 ;
F_471 (domain, domains)
F_472 ( V_6 , V_622 ) ;
return V_625 & ~ V_624 ;
}
static void F_473 ( struct V_5 * V_6 ,
unsigned long V_623 )
{
enum V_127 V_622 ;
F_471 (domain, domains)
F_86 ( V_6 , V_622 ) ;
}
static int F_474 ( struct V_5 * V_6 )
{
int V_627 = V_6 -> V_627 ;
if ( F_475 ( V_6 ) )
return 2 * V_627 ;
else if ( F_184 ( V_6 ) -> V_250 >= 9 ||
F_264 ( V_6 ) || F_265 ( V_6 ) )
return V_627 ;
else if ( F_17 ( V_6 ) )
return V_627 * 95 / 100 ;
else if ( F_184 ( V_6 ) -> V_250 < 4 )
return 2 * V_627 * 90 / 100 ;
else
return V_627 * 90 / 100 ;
}
static void F_476 ( struct V_5 * V_6 )
{
if ( F_477 ( V_6 ) || F_478 ( V_6 ) ) {
T_1 V_57 = F_11 ( V_628 ) & V_629 ;
int V_630 , V_52 ;
V_52 = V_6 -> V_631 ;
F_28 ( V_52 != 8100000 && V_52 != 8640000 ) ;
if ( V_57 == V_632 )
V_630 = 617143 ;
else if ( V_57 == V_633 )
V_630 = 540000 ;
else if ( V_57 == V_634 )
V_630 = 432000 ;
else
V_630 = 308571 ;
V_6 -> V_627 = F_479 ( V_630 , V_52 ) ;
} else if ( F_475 ( V_6 ) ) {
V_6 -> V_627 = 316800 ;
} else if ( F_480 ( V_6 ) ) {
V_6 -> V_627 = 624000 ;
} else if ( F_265 ( V_6 ) ) {
if ( F_11 ( V_635 ) & V_636 )
V_6 -> V_627 = 450000 ;
else if ( F_481 ( V_6 ) )
V_6 -> V_627 = 450000 ;
else if ( F_482 ( V_6 ) )
V_6 -> V_627 = 540000 ;
else
V_6 -> V_627 = 675000 ;
} else if ( F_17 ( V_6 ) ) {
V_6 -> V_627 = 320000 ;
} else if ( F_16 ( V_6 ) ) {
V_6 -> V_627 = 400000 ;
} else {
V_6 -> V_627 = V_6 -> V_637 ;
}
V_6 -> V_638 = F_474 ( V_6 ) ;
F_20 ( L_86 ,
V_6 -> V_627 ) ;
F_20 ( L_87 ,
V_6 -> V_638 ) ;
}
static void F_483 ( struct V_5 * V_6 )
{
V_6 -> V_637 = V_6 -> V_434 . V_639 ( V_6 ) ;
if ( F_59 ( V_6 ) >= 9 )
F_20 ( L_88 ,
V_6 -> V_637 , V_6 -> V_640 . V_52 ,
V_6 -> V_640 . V_641 ) ;
else
F_20 ( L_89 ,
V_6 -> V_637 ) ;
if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
F_124 ( V_642 , F_220 ( V_6 -> V_637 , 1000 ) ) ;
}
static int F_484 ( int V_643 )
{
return F_8 ( V_643 - 1000 , 500 ) ;
}
static int F_485 ( struct V_5 * V_6 , int V_643 )
{
int V_644 ;
if ( V_643 == V_6 -> V_640 . V_641 )
return 0 ;
switch ( V_643 ) {
default:
F_172 ( V_643 ) ;
case 144000 :
case 288000 :
case 384000 :
case 576000 :
V_644 = 60 ;
break;
case 624000 :
V_644 = 65 ;
break;
}
return V_6 -> V_640 . V_641 * V_644 ;
}
static int F_486 ( struct V_5 * V_6 , int V_643 )
{
int V_644 ;
if ( V_643 == V_6 -> V_640 . V_641 )
return 0 ;
switch ( V_643 ) {
default:
F_172 ( V_643 ) ;
case 79200 :
case 158400 :
case 316800 :
V_644 = 33 ;
break;
}
return V_6 -> V_640 . V_641 * V_644 ;
}
static void F_487 ( struct V_5 * V_6 )
{
F_124 ( V_645 , 0 ) ;
if ( F_61 ( V_6 ,
V_645 , V_646 , 0 ,
1 ) )
F_127 ( L_90 ) ;
V_6 -> V_640 . V_52 = 0 ;
}
static void F_488 ( struct V_5 * V_6 , int V_52 )
{
int V_644 = F_8 ( V_52 , V_6 -> V_640 . V_641 ) ;
T_1 V_15 ;
V_15 = F_11 ( V_647 ) ;
V_15 &= ~ V_648 ;
V_15 |= F_489 ( V_644 ) ;
F_124 ( V_647 , V_15 ) ;
F_124 ( V_645 , V_649 ) ;
if ( F_61 ( V_6 ,
V_645 ,
V_646 ,
V_646 ,
1 ) )
F_127 ( L_91 ) ;
V_6 -> V_640 . V_52 = V_52 ;
}
static void F_490 ( struct V_5 * V_6 , int V_643 )
{
T_1 V_15 , V_16 ;
int V_52 , V_362 ;
if ( F_475 ( V_6 ) )
V_52 = F_486 ( V_6 , V_643 ) ;
else
V_52 = F_485 ( V_6 , V_643 ) ;
F_20 ( L_92 , V_643 , V_52 ) ;
switch ( F_8 ( V_52 , V_643 ) ) {
case 8 :
V_16 = V_650 ;
break;
case 4 :
V_16 = V_651 ;
break;
case 3 :
F_7 ( F_475 ( V_6 ) , L_93 ) ;
V_16 = V_652 ;
break;
case 2 :
V_16 = V_653 ;
break;
default:
F_28 ( V_643 != V_6 -> V_640 . V_641 ) ;
F_28 ( V_52 != 0 ) ;
V_16 = V_653 ;
break;
}
F_3 ( & V_6 -> V_552 . V_553 ) ;
V_362 = F_401 ( V_6 , V_654 ,
0x80000000 ) ;
F_5 ( & V_6 -> V_552 . V_553 ) ;
if ( V_362 ) {
F_127 ( L_94 ,
V_362 , V_643 ) ;
return;
}
if ( V_6 -> V_640 . V_52 != 0 &&
V_6 -> V_640 . V_52 != V_52 )
F_487 ( V_6 ) ;
if ( V_6 -> V_640 . V_52 != V_52 )
F_488 ( V_6 , V_52 ) ;
V_15 = V_16 | F_484 ( V_643 ) ;
V_15 |= V_655 ;
if ( V_643 >= 500000 )
V_15 |= V_656 ;
F_124 ( V_657 , V_15 ) ;
F_3 ( & V_6 -> V_552 . V_553 ) ;
V_362 = F_401 ( V_6 , V_654 ,
F_220 ( V_643 , 25000 ) ) ;
F_5 ( & V_6 -> V_552 . V_553 ) ;
if ( V_362 ) {
F_127 ( L_95 ,
V_362 , V_643 ) ;
return;
}
F_483 ( V_6 ) ;
}
static void F_491 ( struct V_5 * V_6 )
{
T_1 V_658 , V_659 ;
F_483 ( V_6 ) ;
if ( V_6 -> V_640 . V_52 == 0 ||
V_6 -> V_637 == V_6 -> V_640 . V_641 )
goto V_660;
V_658 = F_11 ( V_657 ) ;
V_658 &= ~ V_655 ;
V_659 = ( V_658 & V_661 ) |
F_484 ( V_6 -> V_637 ) ;
if ( V_6 -> V_637 >= 500000 )
V_659 |= V_656 ;
if ( V_658 == V_659 )
return;
V_660:
F_161 ( L_96 ) ;
V_6 -> V_637 = 0 ;
V_6 -> V_640 . V_52 = - 1 ;
}
void F_492 ( struct V_5 * V_6 )
{
int V_643 ;
F_491 ( V_6 ) ;
if ( V_6 -> V_637 != 0 && V_6 -> V_640 . V_52 != 0 )
return;
if ( F_475 ( V_6 ) )
V_643 = F_493 ( 0 ) ;
else
V_643 = F_494 ( 0 ) ;
F_490 ( V_6 , V_643 ) ;
}
void F_495 ( struct V_5 * V_6 )
{
F_490 ( V_6 , V_6 -> V_640 . V_641 ) ;
}
static int F_479 ( int V_662 , int V_52 )
{
if ( V_52 == 8640000 ) {
if ( V_662 > 540000 )
return 617143 ;
else if ( V_662 > 432000 )
return 540000 ;
else if ( V_662 > 308571 )
return 432000 ;
else
return 308571 ;
} else {
if ( V_662 > 540000 )
return 675000 ;
else if ( V_662 > 450000 )
return 540000 ;
else if ( V_662 > 337500 )
return 450000 ;
else
return 337500 ;
}
}
static void
F_496 ( struct V_5 * V_6 )
{
T_1 V_15 ;
V_6 -> V_640 . V_641 = 24000 ;
V_6 -> V_640 . V_52 = 0 ;
V_15 = F_11 ( V_663 ) ;
if ( ( V_15 & V_664 ) == 0 )
return;
if ( F_28 ( ( V_15 & V_665 ) == 0 ) )
return;
V_15 = F_11 ( V_666 ) ;
if ( F_28 ( ( V_15 & ( F_497 ( V_667 ) |
F_498 ( V_667 ) |
F_499 ( V_667 ) ) ) !=
F_499 ( V_667 ) ) )
return;
switch ( V_15 & F_500 ( V_667 ) ) {
case F_501 ( V_668 , V_667 ) :
case F_501 ( V_669 , V_667 ) :
case F_501 ( V_670 , V_667 ) :
case F_501 ( V_671 , V_667 ) :
V_6 -> V_640 . V_52 = 8100000 ;
break;
case F_501 ( V_672 , V_667 ) :
case F_501 ( V_673 , V_667 ) :
V_6 -> V_640 . V_52 = 8640000 ;
break;
default:
F_172 ( V_15 & F_500 ( V_667 ) ) ;
break;
}
}
void F_502 ( struct V_5 * V_6 , int V_52 )
{
bool V_674 = V_6 -> V_631 != V_52 ;
V_6 -> V_631 = V_52 ;
if ( V_674 )
F_476 ( V_6 ) ;
}
static void
F_503 ( struct V_5 * V_6 , int V_52 )
{
int V_675 = F_479 ( 0 , V_52 ) ;
T_1 V_15 ;
F_28 ( V_52 != 8100000 && V_52 != 8640000 ) ;
V_15 = V_676 | F_484 ( V_675 ) ;
F_124 ( V_657 , V_15 ) ;
F_125 ( V_657 ) ;
V_15 = F_11 ( V_666 ) ;
V_15 &= ~ ( F_497 ( V_667 ) | F_498 ( V_667 ) |
F_500 ( V_667 ) ) ;
V_15 |= F_499 ( V_667 ) ;
if ( V_52 == 8640000 )
V_15 |= F_501 ( V_672 ,
V_667 ) ;
else
V_15 |= F_501 ( V_668 ,
V_667 ) ;
F_124 ( V_666 , V_15 ) ;
F_125 ( V_666 ) ;
F_124 ( V_663 , F_11 ( V_663 ) | V_664 ) ;
if ( F_61 ( V_6 ,
V_663 , V_665 , V_665 ,
5 ) )
F_127 ( L_97 ) ;
V_6 -> V_640 . V_52 = V_52 ;
F_502 ( V_6 , V_52 ) ;
}
static void
F_504 ( struct V_5 * V_6 )
{
F_124 ( V_663 , F_11 ( V_663 ) & ~ V_664 ) ;
if ( F_61 ( V_6 ,
V_663 , V_665 , 0 ,
1 ) )
F_127 ( L_98 ) ;
V_6 -> V_640 . V_52 = 0 ;
}
static void F_505 ( struct V_5 * V_6 , int V_643 , int V_52 )
{
T_1 V_677 , V_678 ;
int V_362 ;
F_28 ( ( V_643 == 24000 ) != ( V_52 == 0 ) ) ;
F_20 ( L_92 , V_643 , V_52 ) ;
F_3 ( & V_6 -> V_552 . V_553 ) ;
V_362 = F_506 ( V_6 , V_679 ,
V_680 ,
V_681 ,
V_681 , 3 ) ;
F_5 ( & V_6 -> V_552 . V_553 ) ;
if ( V_362 ) {
F_127 ( L_99 ,
V_362 ) ;
return;
}
switch ( V_643 ) {
case 450000 :
case 432000 :
V_677 = V_682 ;
V_678 = 1 ;
break;
case 540000 :
V_677 = V_683 ;
V_678 = 2 ;
break;
case 308571 :
case 337500 :
default:
V_677 = V_676 ;
V_678 = 0 ;
break;
case 617143 :
case 675000 :
V_677 = V_684 ;
V_678 = 3 ;
break;
}
if ( V_6 -> V_640 . V_52 != 0 &&
V_6 -> V_640 . V_52 != V_52 )
F_504 ( V_6 ) ;
if ( V_6 -> V_640 . V_52 != V_52 )
F_503 ( V_6 , V_52 ) ;
F_124 ( V_657 , V_677 | F_484 ( V_643 ) ) ;
F_125 ( V_657 ) ;
F_3 ( & V_6 -> V_552 . V_553 ) ;
F_401 ( V_6 , V_679 , V_678 ) ;
F_5 ( & V_6 -> V_552 . V_553 ) ;
F_483 ( V_6 ) ;
}
void F_507 ( struct V_5 * V_6 )
{
F_505 ( V_6 , V_6 -> V_640 . V_641 , 0 ) ;
}
void F_508 ( struct V_5 * V_6 )
{
int V_643 , V_52 ;
F_509 ( V_6 ) ;
if ( V_6 -> V_637 != 0 && V_6 -> V_640 . V_52 != 0 ) {
if ( V_6 -> V_631 == 0 )
F_502 ( V_6 ,
V_6 -> V_640 . V_52 ) ;
return;
}
V_52 = V_6 -> V_631 ;
if ( V_52 == 0 )
V_52 = 8100000 ;
V_643 = F_479 ( 0 , V_52 ) ;
F_505 ( V_6 , V_643 , V_52 ) ;
}
static void F_509 ( struct V_5 * V_6 )
{
T_2 V_658 , V_659 ;
if ( ( F_11 ( F_510 ( 0x18 ) ) & 0x00FFFFFF ) == 0 )
goto V_660;
F_483 ( V_6 ) ;
if ( V_6 -> V_640 . V_52 == 0 ||
V_6 -> V_637 == V_6 -> V_640 . V_641 )
goto V_660;
V_658 = F_11 ( V_657 ) ;
V_659 = ( V_658 & V_685 ) |
F_484 ( V_6 -> V_637 ) ;
if ( V_658 == V_659 )
return;
V_660:
F_161 ( L_96 ) ;
V_6 -> V_637 = 0 ;
V_6 -> V_640 . V_52 = - 1 ;
}
static void F_511 ( struct V_62 * V_63 , int V_643 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_15 , V_686 ;
F_28 ( V_6 -> V_434 . V_639 ( V_6 )
!= V_6 -> V_637 ) ;
if ( V_643 >= 320000 )
V_686 = 2 ;
else if ( V_643 == 266667 )
V_686 = 1 ;
else
V_686 = 0 ;
F_3 ( & V_6 -> V_552 . V_553 ) ;
V_15 = F_512 ( V_6 , V_687 ) ;
V_15 &= ~ V_688 ;
V_15 |= ( V_686 << V_689 ) ;
F_513 ( V_6 , V_687 , V_15 ) ;
if ( F_62 ( ( F_512 ( V_6 , V_687 ) &
V_690 ) == ( V_686 << V_691 ) ,
50 ) ) {
F_127 ( L_100 ) ;
}
F_5 ( & V_6 -> V_552 . V_553 ) ;
F_3 ( & V_6 -> V_9 ) ;
if ( V_643 == 400000 ) {
T_1 V_16 ;
V_16 = F_8 ( V_6 -> V_7 << 1 , V_643 ) - 1 ;
V_15 = F_4 ( V_6 , V_692 ) ;
V_15 &= ~ V_17 ;
V_15 |= V_16 ;
F_514 ( V_6 , V_692 , V_15 ) ;
if ( F_62 ( ( F_4 ( V_6 , V_692 ) &
V_18 ) == ( V_16 << V_19 ) ,
50 ) )
F_127 ( L_100 ) ;
}
V_15 = F_515 ( V_6 , V_693 ) ;
V_15 &= ~ 0x7f ;
if ( V_643 == 400000 )
V_15 |= 4500 / 250 ;
else
V_15 |= 3000 / 250 ;
F_516 ( V_6 , V_693 , V_15 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_483 ( V_6 ) ;
}
static void F_517 ( struct V_62 * V_63 , int V_643 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_15 , V_686 ;
F_28 ( V_6 -> V_434 . V_639 ( V_6 )
!= V_6 -> V_637 ) ;
switch ( V_643 ) {
case 333333 :
case 320000 :
case 266667 :
case 200000 :
break;
default:
F_172 ( V_643 ) ;
return;
}
V_686 = F_8 ( V_6 -> V_7 << 1 , V_643 ) - 1 ;
F_3 ( & V_6 -> V_552 . V_553 ) ;
V_15 = F_512 ( V_6 , V_687 ) ;
V_15 &= ~ V_694 ;
V_15 |= ( V_686 << V_695 ) ;
F_513 ( V_6 , V_687 , V_15 ) ;
if ( F_62 ( ( F_512 ( V_6 , V_687 ) &
V_696 ) == ( V_686 << V_697 ) ,
50 ) ) {
F_127 ( L_100 ) ;
}
F_5 ( & V_6 -> V_552 . V_553 ) ;
F_483 ( V_6 ) ;
}
static int F_518 ( struct V_5 * V_6 ,
int V_662 )
{
int V_698 = ( V_6 -> V_7 << 1 ) % 320000 != 0 ? 333333 : 320000 ;
int V_57 = F_17 ( V_6 ) ? 95 : 90 ;
if ( ! F_17 ( V_6 ) &&
V_662 > V_698 * V_57 / 100 )
return 400000 ;
else if ( V_662 > 266667 * V_57 / 100 )
return V_698 ;
else if ( V_662 > 0 )
return 266667 ;
else
return 200000 ;
}
static int F_493 ( int V_662 )
{
if ( V_662 > 2 * 158400 )
return 316800 ;
else if ( V_662 > 2 * 79200 )
return 158400 ;
else
return 79200 ;
}
static int F_494 ( int V_662 )
{
if ( V_662 > 576000 )
return 624000 ;
else if ( V_662 > 384000 )
return 576000 ;
else if ( V_662 > 288000 )
return 384000 ;
else if ( V_662 > 144000 )
return 288000 ;
else
return 144000 ;
}
static int F_519 ( struct V_62 * V_63 ,
struct V_421 * V_43 )
{
struct V_569 * V_338 = F_295 ( V_43 ) ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_145 * V_65 ;
struct V_42 * V_60 ;
unsigned V_662 = 0 , V_135 ;
enum V_94 V_94 ;
memcpy ( V_338 -> V_699 , V_6 -> V_699 ,
sizeof( V_338 -> V_699 ) ) ;
F_294 (state, crtc, crtc_state, i) {
int V_700 = 0 ;
if ( V_60 -> V_507 )
V_700 = V_60 -> V_91 . V_92 ;
V_338 -> V_699 [ V_135 ] = V_700 ;
}
F_91 (dev_priv, pipe)
V_662 = V_59 ( V_338 -> V_699 [ V_94 ] , V_662 ) ;
return V_662 ;
}
static int F_520 ( struct V_421 * V_43 )
{
struct V_62 * V_63 = V_43 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_662 = F_519 ( V_63 , V_43 ) ;
struct V_569 * V_338 =
F_295 ( V_43 ) ;
V_338 -> V_643 = V_338 -> V_701 =
F_518 ( V_6 , V_662 ) ;
if ( ! V_338 -> V_702 )
V_338 -> V_701 = F_518 ( V_6 , 0 ) ;
return 0 ;
}
static int F_521 ( struct V_421 * V_43 )
{
struct V_5 * V_6 = F_41 ( V_43 -> V_63 ) ;
int V_662 = F_522 ( V_43 ) ;
struct V_569 * V_338 =
F_295 ( V_43 ) ;
int V_643 ;
if ( F_475 ( V_6 ) )
V_643 = F_493 ( V_662 ) ;
else
V_643 = F_494 ( V_662 ) ;
V_338 -> V_643 = V_338 -> V_701 = V_643 ;
if ( ! V_338 -> V_702 ) {
if ( F_475 ( V_6 ) )
V_643 = F_493 ( 0 ) ;
else
V_643 = F_494 ( 0 ) ;
V_338 -> V_701 = V_643 ;
}
return 0 ;
}
static void F_523 ( struct V_5 * V_6 )
{
unsigned int V_703 , V_704 ;
if ( F_17 ( V_6 ) )
V_704 = F_524 ( 12 ) ;
else
V_704 = F_524 ( 8 ) ;
if ( V_6 -> V_637 >= V_6 -> V_35 ) {
if ( F_17 ( V_6 ) )
V_703 = V_705 ;
else
V_703 = F_524 ( 15 ) ;
} else {
V_703 = V_704 ;
}
F_124 ( V_706 , V_707 |
V_704 ) ;
F_124 ( V_706 , V_707 |
V_703 | V_708 ) ;
F_28 ( F_11 ( V_706 ) & V_708 ) ;
}
static void F_525 ( struct V_421 * V_560 )
{
struct V_62 * V_63 = V_560 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_569 * V_570 =
F_295 ( V_560 ) ;
unsigned V_709 = V_570 -> V_701 ;
F_472 ( V_6 , V_710 ) ;
if ( F_17 ( V_6 ) )
F_517 ( V_63 , V_709 ) ;
else
F_511 ( V_63 , V_709 ) ;
F_523 ( V_6 ) ;
F_86 ( V_6 , V_710 ) ;
}
static void F_526 ( struct V_37 * V_38 ,
struct V_421 * V_560 )
{
struct V_145 * V_65 = V_38 -> V_64 . V_65 ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
if ( F_28 ( V_81 -> V_87 ) )
return;
if ( F_388 ( V_81 -> V_90 ) )
F_434 ( V_81 , V_586 ) ;
F_435 ( V_81 ) ;
F_436 ( V_81 ) ;
if ( F_17 ( V_6 ) && V_94 == V_120 ) {
struct V_5 * V_6 = F_41 ( V_63 ) ;
F_124 ( F_527 ( V_94 ) , V_711 ) ;
F_124 ( F_528 ( V_94 ) , 0 ) ;
}
F_529 ( V_81 ) ;
V_81 -> V_87 = true ;
F_406 ( V_6 , V_94 , true ) ;
F_422 ( V_65 , V_38 , V_560 ) ;
if ( F_17 ( V_6 ) ) {
F_530 ( V_81 , V_81 -> V_90 ) ;
F_136 ( V_81 , V_81 -> V_90 ) ;
} else {
F_531 ( V_81 , V_81 -> V_90 ) ;
F_128 ( V_81 , V_81 -> V_90 ) ;
}
F_425 ( V_65 , V_38 , V_560 ) ;
F_458 ( V_81 ) ;
F_439 ( & V_38 -> V_64 ) ;
F_414 ( V_81 ) ;
F_160 ( V_81 ) ;
F_99 ( V_65 ) ;
F_440 ( V_65 ) ;
F_426 ( V_65 , V_38 , V_560 ) ;
}
static void F_532 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
F_124 ( F_533 ( V_65 -> V_94 ) , V_65 -> V_90 -> V_174 . V_712 ) ;
F_124 ( F_534 ( V_65 -> V_94 ) , V_65 -> V_90 -> V_174 . V_713 ) ;
}
static void F_535 ( struct V_37 * V_38 ,
struct V_421 * V_560 )
{
struct V_145 * V_65 = V_38 -> V_64 . V_65 ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
enum V_94 V_94 = V_81 -> V_94 ;
if ( F_28 ( V_81 -> V_87 ) )
return;
F_532 ( V_81 ) ;
if ( F_388 ( V_81 -> V_90 ) )
F_434 ( V_81 , V_586 ) ;
F_435 ( V_81 ) ;
F_436 ( V_81 ) ;
F_529 ( V_81 ) ;
V_81 -> V_87 = true ;
if ( ! F_56 ( V_6 ) )
F_406 ( V_6 , V_94 , true ) ;
F_425 ( V_65 , V_38 , V_560 ) ;
F_139 ( V_81 ) ;
F_458 ( V_81 ) ;
F_439 ( & V_38 -> V_64 ) ;
F_414 ( V_81 ) ;
F_160 ( V_81 ) ;
F_99 ( V_65 ) ;
F_440 ( V_65 ) ;
F_426 ( V_65 , V_38 , V_560 ) ;
}
static void F_536 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
if ( ! V_65 -> V_90 -> V_595 . V_596 )
return;
F_129 ( V_6 , V_65 -> V_94 ) ;
F_20 ( L_101 ,
F_11 ( V_597 ) ) ;
F_124 ( V_597 , 0 ) ;
}
static void F_537 ( struct V_37 * V_442 ,
struct V_421 * V_560 )
{
struct V_145 * V_65 = V_442 -> V_64 . V_65 ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
if ( F_56 ( V_6 ) )
F_342 ( V_6 , V_94 ) ;
F_428 ( V_65 , V_442 , V_560 ) ;
F_454 ( V_65 ) ;
F_99 ( V_65 ) ;
F_168 ( V_81 ) ;
F_536 ( V_81 ) ;
F_429 ( V_65 , V_442 , V_560 ) ;
if ( ! F_38 ( V_81 -> V_90 , V_223 ) ) {
if ( F_17 ( V_6 ) )
F_144 ( V_6 , V_94 ) ;
else if ( F_16 ( V_6 ) )
F_143 ( V_6 , V_94 ) ;
else
F_142 ( V_81 ) ;
}
F_430 ( V_65 , V_442 , V_560 ) ;
if ( ! F_56 ( V_6 ) )
F_406 ( V_6 , V_94 , false ) ;
}
static void F_538 ( struct V_145 * V_65 )
{
struct V_511 * V_512 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
enum V_127 V_622 ;
unsigned long V_623 ;
struct V_421 * V_43 ;
struct V_37 * V_60 ;
int V_362 ;
if ( ! V_81 -> V_87 )
return;
if ( V_65 -> V_88 -> V_43 -> V_340 ) {
F_28 ( V_81 -> V_441 ) ;
F_240 ( V_65 ) ;
F_419 ( V_65 , 1 << F_239 ( V_65 -> V_88 ) ) ;
V_65 -> V_88 -> V_43 -> V_340 = false ;
}
V_43 = F_539 ( V_65 -> V_63 ) ;
if ( ! V_43 ) {
F_161 ( L_102 ,
V_65 -> V_64 . V_379 , V_65 -> V_12 ) ;
return;
}
V_43 -> V_432 = V_65 -> V_63 -> V_428 . V_432 ;
V_60 = F_540 ( V_43 , V_81 ) ;
V_362 = F_541 ( V_43 , V_65 ) ;
F_28 ( F_194 ( V_60 ) || V_362 ) ;
V_6 -> V_434 . V_714 ( V_60 , V_43 ) ;
F_305 ( V_43 ) ;
F_161 ( L_103 ,
V_65 -> V_64 . V_379 , V_65 -> V_12 ) ;
F_28 ( F_542 ( V_65 -> V_43 , NULL ) < 0 ) ;
V_65 -> V_43 -> V_87 = false ;
V_81 -> V_87 = false ;
V_65 -> V_146 = false ;
V_65 -> V_43 -> V_715 = 0 ;
V_65 -> V_43 -> V_716 = 0 ;
F_379 (crtc->dev, crtc, encoder)
V_512 -> V_64 . V_65 = NULL ;
F_543 ( V_81 ) ;
F_414 ( V_81 ) ;
F_544 ( V_81 ) ;
V_623 = V_81 -> V_626 ;
F_471 (domain, domains)
F_86 ( V_6 , V_622 ) ;
V_81 -> V_626 = 0 ;
V_6 -> V_702 &= ~ ( 1 << V_81 -> V_94 ) ;
V_6 -> V_699 [ V_81 -> V_94 ] = 0 ;
}
int F_545 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_421 * V_43 ;
int V_362 ;
V_43 = F_546 ( V_63 ) ;
V_362 = F_547 ( V_43 ) ;
if ( V_362 )
F_127 ( L_57 , V_362 ) ;
else
V_6 -> V_431 = V_43 ;
return V_362 ;
}
void F_548 ( struct V_618 * V_512 )
{
struct V_511 * V_511 = F_424 ( V_512 ) ;
F_549 ( V_512 ) ;
F_236 ( V_511 ) ;
}
static void F_550 ( struct V_717 * V_718 )
{
struct V_145 * V_65 = V_718 -> V_64 . V_43 -> V_65 ;
F_161 ( L_104 ,
V_718 -> V_64 . V_64 . V_379 ,
V_718 -> V_64 . V_12 ) ;
if ( V_718 -> V_719 ( V_718 ) ) {
struct V_511 * V_512 = V_718 -> V_512 ;
struct V_575 * V_579 = V_718 -> V_64 . V_43 ;
F_65 ( ! V_65 ,
L_105 ) ;
if ( ! V_65 )
return;
F_65 ( ! V_65 -> V_43 -> V_87 ,
L_106 ) ;
if ( ! V_512 || V_512 -> type == V_591 )
return;
F_65 ( V_579 -> V_580 != & V_512 -> V_64 ,
L_107 ) ;
F_65 ( V_579 -> V_65 != V_512 -> V_64 . V_65 ,
L_108 ) ;
} else {
F_65 ( V_65 && V_65 -> V_43 -> V_87 ,
L_109 ) ;
F_65 ( ! V_65 && V_718 -> V_64 . V_43 -> V_580 ,
L_110 ) ;
}
}
int F_551 ( struct V_717 * V_718 )
{
F_552 ( & V_718 -> V_64 ) ;
if ( ! V_718 -> V_64 . V_43 )
return - V_720 ;
return 0 ;
}
struct V_717 * F_553 ( void )
{
struct V_717 * V_718 ;
V_718 = F_554 ( sizeof *V_718 , V_721 ) ;
if ( ! V_718 )
return NULL ;
if ( F_551 ( V_718 ) < 0 ) {
F_236 ( V_718 ) ;
return NULL ;
}
return V_718 ;
}
bool F_555 ( struct V_717 * V_718 )
{
enum V_94 V_94 = 0 ;
struct V_511 * V_512 = V_718 -> V_512 ;
return V_512 -> V_719 ( V_512 , & V_94 ) ;
}
static int F_556 ( struct V_37 * V_60 )
{
if ( V_60 -> V_64 . V_507 && V_60 -> V_222 )
return V_60 -> V_457 ;
return 0 ;
}
static int F_557 ( struct V_62 * V_63 , enum V_94 V_94 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_421 * V_43 = V_38 -> V_64 . V_43 ;
struct V_81 * V_722 ;
struct V_37 * V_723 ;
F_161 ( L_111 ,
F_78 ( V_94 ) , V_38 -> V_457 ) ;
if ( V_38 -> V_457 > 4 ) {
F_161 ( L_112 ,
F_78 ( V_94 ) , V_38 -> V_457 ) ;
return - V_288 ;
}
if ( F_264 ( V_6 ) || F_265 ( V_6 ) ) {
if ( V_38 -> V_457 > 2 ) {
F_161 ( L_113 ,
V_38 -> V_457 ) ;
return - V_288 ;
} else {
return 0 ;
}
}
if ( F_184 ( V_6 ) -> V_724 == 2 )
return 0 ;
switch ( V_94 ) {
case V_113 :
return 0 ;
case V_120 :
if ( V_38 -> V_457 <= 2 )
return 0 ;
V_722 = F_53 ( V_6 , V_510 ) ;
V_723 =
F_540 ( V_43 , V_722 ) ;
if ( F_194 ( V_723 ) )
return F_241 ( V_723 ) ;
if ( F_556 ( V_723 ) > 0 ) {
F_161 ( L_114 ,
F_78 ( V_94 ) , V_38 -> V_457 ) ;
return - V_288 ;
}
return 0 ;
case V_510 :
if ( V_38 -> V_457 > 2 ) {
F_161 ( L_115 ,
F_78 ( V_94 ) , V_38 -> V_457 ) ;
return - V_288 ;
}
V_722 = F_53 ( V_6 , V_120 ) ;
V_723 =
F_540 ( V_43 , V_722 ) ;
if ( F_194 ( V_723 ) )
return F_241 ( V_723 ) ;
if ( F_556 ( V_723 ) > 2 ) {
F_161 ( L_116 ) ;
return - V_288 ;
}
return 0 ;
default:
F_146 () ;
}
}
static int F_558 ( struct V_81 * V_81 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
const struct V_520 * V_91 = & V_38 -> V_64 . V_91 ;
int V_725 , V_726 , V_727 , V_362 ;
bool V_728 = false ;
V_462:
V_726 = F_22 ( F_41 ( V_63 ) , V_38 ) ;
V_727 = V_91 -> V_92 ;
V_725 = F_559 ( V_727 , V_726 ,
V_38 -> V_729 ) ;
V_38 -> V_457 = V_725 ;
F_560 ( V_38 -> V_729 , V_725 , V_727 ,
V_726 , & V_38 -> V_587 ) ;
V_362 = F_557 ( V_63 , V_81 -> V_94 , V_38 ) ;
if ( V_362 == - V_288 && V_38 -> V_729 > 6 * 3 ) {
V_38 -> V_729 -= 2 * 3 ;
F_161 ( L_117 ,
V_38 -> V_729 ) ;
V_728 = true ;
V_38 -> V_730 = true ;
goto V_462;
}
if ( V_728 )
return V_731 ;
return V_362 ;
}
static bool F_561 ( struct V_5 * V_6 ,
struct V_37 * V_38 )
{
if ( V_38 -> V_729 > 24 )
return false ;
if ( F_264 ( V_6 ) )
return true ;
return F_562 ( V_38 ) <=
V_6 -> V_627 * 95 / 100 ;
}
static void F_563 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
V_38 -> V_551 = V_259 . V_732 &&
F_441 ( V_65 ) &&
F_561 ( V_6 , V_38 ) ;
}
static bool F_564 ( const struct V_81 * V_65 )
{
const struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
return F_184 ( V_6 ) -> V_250 < 4 &&
( V_65 -> V_94 == V_113 || F_565 ( V_6 ) ) ;
}
static int F_566 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
const struct V_520 * V_91 = & V_38 -> V_64 . V_91 ;
int V_733 = V_6 -> V_638 ;
if ( F_59 ( V_6 ) < 4 ) {
V_733 = V_6 -> V_627 * 9 / 10 ;
if ( F_564 ( V_65 ) &&
V_91 -> V_92 > V_733 ) {
V_733 = V_6 -> V_638 ;
V_38 -> V_226 = true ;
}
}
if ( V_91 -> V_92 > V_733 ) {
F_161 ( L_118 ,
V_91 -> V_92 , V_733 ,
F_567 ( V_38 -> V_226 ) ) ;
return - V_288 ;
}
if ( ( F_38 ( V_38 , V_66 ) &&
F_39 ( V_63 ) ) || V_38 -> V_226 )
V_38 -> V_367 &= ~ 1 ;
if ( ( F_59 ( V_6 ) > 4 || F_18 ( V_6 ) ) &&
V_91 -> V_734 == V_91 -> V_543 )
return - V_288 ;
if ( F_442 ( V_6 ) )
F_563 ( V_65 , V_38 ) ;
if ( V_38 -> V_222 )
return F_558 ( V_65 , V_38 ) ;
return 0 ;
}
static int F_568 ( struct V_5 * V_6 )
{
T_1 V_658 ;
F_496 ( V_6 ) ;
if ( V_6 -> V_640 . V_52 == 0 )
return V_6 -> V_640 . V_641 ;
V_658 = F_11 ( V_657 ) ;
if ( V_6 -> V_640 . V_52 == 8640000 ) {
switch ( V_658 & V_685 ) {
case V_682 :
return 432000 ;
case V_676 :
return 308571 ;
case V_683 :
return 540000 ;
case V_684 :
return 617143 ;
default:
F_172 ( V_658 & V_685 ) ;
}
} else {
switch ( V_658 & V_685 ) {
case V_682 :
return 450000 ;
case V_676 :
return 337500 ;
case V_683 :
return 540000 ;
case V_684 :
return 675000 ;
default:
F_172 ( V_658 & V_685 ) ;
}
}
return V_6 -> V_640 . V_641 ;
}
static void F_569 ( struct V_5 * V_6 )
{
T_1 V_15 ;
V_6 -> V_640 . V_641 = 19200 ;
V_6 -> V_640 . V_52 = 0 ;
V_15 = F_11 ( V_645 ) ;
if ( ( V_15 & V_649 ) == 0 )
return;
if ( F_28 ( ( V_15 & V_646 ) == 0 ) )
return;
V_15 = F_11 ( V_647 ) ;
V_6 -> V_640 . V_52 = ( V_15 & V_648 ) *
V_6 -> V_640 . V_641 ;
}
static int F_570 ( struct V_5 * V_6 )
{
T_1 V_16 ;
int div , V_52 ;
F_569 ( V_6 ) ;
V_52 = V_6 -> V_640 . V_52 ;
if ( V_52 == 0 )
return V_6 -> V_640 . V_641 ;
V_16 = F_11 ( V_657 ) & V_661 ;
switch ( V_16 ) {
case V_653 :
div = 2 ;
break;
case V_652 :
F_7 ( F_475 ( V_6 ) , L_93 ) ;
div = 3 ;
break;
case V_651 :
div = 4 ;
break;
case V_650 :
div = 8 ;
break;
default:
F_172 ( V_16 ) ;
return V_6 -> V_640 . V_641 ;
}
return F_8 ( V_52 , div ) ;
}
static int F_571 ( struct V_5 * V_6 )
{
T_2 V_735 = F_11 ( V_736 ) ;
T_2 V_737 = V_735 & V_738 ;
if ( V_735 & V_739 )
return 800000 ;
else if ( F_11 ( V_635 ) & V_636 )
return 450000 ;
else if ( V_737 == V_740 )
return 450000 ;
else if ( V_737 == V_741 )
return 540000 ;
else if ( V_737 == V_742 )
return 337500 ;
else
return 675000 ;
}
static int F_572 ( struct V_5 * V_6 )
{
T_2 V_735 = F_11 ( V_736 ) ;
T_2 V_737 = V_735 & V_738 ;
if ( V_735 & V_739 )
return 800000 ;
else if ( F_11 ( V_635 ) & V_636 )
return 450000 ;
else if ( V_737 == V_740 )
return 450000 ;
else if ( F_573 ( V_6 ) )
return 337500 ;
else
return 540000 ;
}
static int F_574 ( struct V_5 * V_6 )
{
return F_9 ( V_6 , L_119 ,
V_692 ) ;
}
static int F_575 ( struct V_5 * V_6 )
{
return 450000 ;
}
static int F_576 ( struct V_5 * V_6 )
{
return 400000 ;
}
static int F_577 ( struct V_5 * V_6 )
{
return 333333 ;
}
static int F_578 ( struct V_5 * V_6 )
{
return 200000 ;
}
static int F_579 ( struct V_5 * V_6 )
{
struct V_743 * V_744 = V_6 -> V_260 . V_744 ;
T_4 V_745 = 0 ;
F_580 ( V_744 , V_746 , & V_745 ) ;
switch ( V_745 & V_747 ) {
case V_748 :
return 266667 ;
case V_749 :
return 333333 ;
case V_750 :
return 444444 ;
case V_751 :
return 200000 ;
default:
F_127 ( L_120 , V_745 ) ;
case V_752 :
return 133333 ;
case V_753 :
return 166667 ;
}
}
static int F_581 ( struct V_5 * V_6 )
{
struct V_743 * V_744 = V_6 -> V_260 . V_744 ;
T_4 V_745 = 0 ;
F_580 ( V_744 , V_746 , & V_745 ) ;
if ( V_745 & V_754 )
return 133333 ;
else {
switch ( V_745 & V_747 ) {
case V_755 :
return 333333 ;
default:
case V_756 :
return 190000 ;
}
}
}
static int F_582 ( struct V_5 * V_6 )
{
return 266667 ;
}
static int F_583 ( struct V_5 * V_6 )
{
struct V_743 * V_744 = V_6 -> V_260 . V_744 ;
T_4 V_757 = 0 ;
if ( V_744 -> V_758 == 0x1 )
return 133333 ;
F_584 ( V_744 -> V_759 ,
F_585 ( 0 , 3 ) , V_760 , & V_757 ) ;
switch ( V_757 & V_761 ) {
case V_762 :
case V_763 :
case V_764 :
return 200000 ;
case V_765 :
return 250000 ;
case V_766 :
return 133333 ;
case V_767 :
case V_768 :
case V_769 :
return 266667 ;
}
return 0 ;
}
static int F_586 ( struct V_5 * V_6 )
{
return 133333 ;
}
static unsigned int F_587 ( struct V_5 * V_6 )
{
static const unsigned int V_770 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 6400000 ,
} ;
static const unsigned int V_771 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 2666667 ,
} ;
static const unsigned int V_772 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 3333333 ,
[ 5 ] = 3566667 ,
[ 6 ] = 4266667 ,
} ;
static const unsigned int V_773 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
} ;
static const unsigned int V_774 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 2666667 ,
[ 5 ] = 4266667 ,
} ;
const unsigned int * V_775 ;
unsigned int V_52 ;
T_5 V_179 = 0 ;
if ( F_588 ( V_6 ) )
V_775 = V_774 ;
else if ( F_18 ( V_6 ) )
V_775 = V_773 ;
else if ( F_186 ( V_6 ) )
V_775 = V_772 ;
else if ( F_19 ( V_6 ) )
V_775 = V_771 ;
else if ( F_589 ( V_6 ) )
V_775 = V_770 ;
else
return 0 ;
V_179 = F_11 ( F_140 ( V_6 ) ? V_776 : V_777 ) ;
V_52 = V_775 [ V_179 & 0x7 ] ;
if ( V_52 == 0 )
F_127 ( L_121 , V_179 ) ;
else
F_161 ( L_122 , V_52 ) ;
return V_52 ;
}
static int F_590 ( struct V_5 * V_6 )
{
struct V_743 * V_744 = V_6 -> V_260 . V_744 ;
unsigned int V_778 , V_52 = F_587 ( V_6 ) ;
T_6 V_179 = 0 ;
F_580 ( V_744 , V_746 , & V_179 ) ;
V_778 = ( V_179 >> 12 ) & 0x1 ;
switch ( V_52 ) {
case 2666667 :
case 4000000 :
case 5333333 :
return V_778 ? 333333 : 222222 ;
case 3200000 :
return V_778 ? 320000 : 228571 ;
default:
F_127 ( L_123 , V_52 , V_179 ) ;
return 222222 ;
}
}
static int F_591 ( struct V_5 * V_6 )
{
struct V_743 * V_744 = V_6 -> V_260 . V_744 ;
static const T_5 V_779 [] = { 16 , 10 , 8 } ;
static const T_5 V_780 [] = { 20 , 12 , 10 } ;
static const T_5 V_781 [] = { 24 , 16 , 14 } ;
const T_5 * V_782 ;
unsigned int V_778 , V_52 = F_587 ( V_6 ) ;
T_6 V_179 = 0 ;
F_580 ( V_744 , V_746 , & V_179 ) ;
V_778 = ( ( V_179 >> 8 ) & 0x1f ) - 1 ;
if ( V_778 >= F_179 ( V_779 ) )
goto V_783;
switch ( V_52 ) {
case 3200000 :
V_782 = V_779 ;
break;
case 4000000 :
V_782 = V_780 ;
break;
case 5333333 :
V_782 = V_781 ;
break;
default:
goto V_783;
}
return F_8 ( V_52 , V_782 [ V_778 ] ) ;
V_783:
F_127 ( L_124 , V_52 , V_179 ) ;
return 200000 ;
}
static int F_592 ( struct V_5 * V_6 )
{
struct V_743 * V_744 = V_6 -> V_260 . V_744 ;
static const T_5 V_779 [] = { 12 , 10 , 8 , 7 , 5 , 16 } ;
static const T_5 V_780 [] = { 14 , 12 , 10 , 8 , 6 , 20 } ;
static const T_5 V_784 [] = { 20 , 14 , 12 , 10 , 8 , 24 } ;
static const T_5 V_781 [] = { 20 , 16 , 12 , 12 , 8 , 28 } ;
const T_5 * V_782 ;
unsigned int V_778 , V_52 = F_587 ( V_6 ) ;
T_6 V_179 = 0 ;
F_580 ( V_744 , V_746 , & V_179 ) ;
V_778 = ( V_179 >> 4 ) & 0x7 ;
if ( V_778 >= F_179 ( V_779 ) )
goto V_783;
switch ( V_52 ) {
case 3200000 :
V_782 = V_779 ;
break;
case 4000000 :
V_782 = V_780 ;
break;
case 4800000 :
V_782 = V_784 ;
break;
case 5333333 :
V_782 = V_781 ;
break;
default:
goto V_783;
}
return F_8 ( V_52 , V_782 [ V_778 ] ) ;
V_783:
F_127 ( L_125 , V_52 , V_179 ) ;
return 190476 ;
}
static void
F_593 ( T_2 * V_785 , T_2 * V_786 )
{
while ( * V_785 > V_787 ||
* V_786 > V_787 ) {
* V_785 >>= 1 ;
* V_786 >>= 1 ;
}
}
static void F_594 ( unsigned int V_46 , unsigned int V_51 ,
T_2 * V_788 , T_2 * V_789 )
{
* V_789 = F_595 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_788 = F_46 ( ( V_55 ) V_46 * * V_789 , V_51 ) ;
F_593 ( V_788 , V_789 ) ;
}
void
F_560 ( int V_790 , int V_791 ,
int V_792 , int V_793 ,
struct V_794 * V_795 )
{
V_795 -> V_796 = 64 ;
F_594 ( V_790 * V_792 ,
V_793 * V_791 * 8 ,
& V_795 -> V_797 , & V_795 -> V_798 ) ;
F_594 ( V_792 , V_793 ,
& V_795 -> V_799 , & V_795 -> V_800 ) ;
}
static inline bool F_596 ( struct V_5 * V_6 )
{
if ( V_259 . V_801 >= 0 )
return V_259 . V_801 != 0 ;
return V_6 -> V_802 . V_803
&& ! ( V_6 -> V_129 & V_804 ) ;
}
static T_2 F_597 ( struct V_45 * V_45 )
{
return ( 1 << V_45 -> V_51 ) << 16 | V_45 -> V_47 ;
}
static T_2 F_598 ( struct V_45 * V_45 )
{
return V_45 -> V_51 << 16 | V_45 -> V_54 << 8 | V_45 -> V_47 ;
}
static void F_599 ( struct V_81 * V_65 ,
struct V_37 * V_60 ,
struct V_45 * V_805 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
T_1 V_806 , V_807 = 0 ;
if ( F_19 ( V_6 ) ) {
V_806 = F_597 ( & V_60 -> V_45 ) ;
if ( V_805 )
V_807 = F_597 ( V_805 ) ;
} else {
V_806 = F_598 ( & V_60 -> V_45 ) ;
if ( V_805 )
V_807 = F_598 ( V_805 ) ;
}
V_60 -> V_174 . V_712 = V_806 ;
V_65 -> V_808 = false ;
if ( F_38 ( V_60 , V_66 ) &&
V_805 ) {
V_60 -> V_174 . V_713 = V_807 ;
V_65 -> V_808 = true ;
} else {
V_60 -> V_174 . V_713 = V_806 ;
}
}
static void F_600 ( struct V_5 * V_6 , enum V_94
V_94 )
{
T_1 V_809 ;
V_809 = F_133 ( V_6 , V_94 , F_601 ( 1 ) ) ;
V_809 &= 0xffffff00 ;
V_809 |= 0x00000030 ;
F_135 ( V_6 , V_94 , F_601 ( 1 ) , V_809 ) ;
V_809 = F_133 ( V_6 , V_94 , V_810 ) ;
V_809 &= 0x8cffffff ;
V_809 = 0x8c000000 ;
F_135 ( V_6 , V_94 , V_810 , V_809 ) ;
V_809 = F_133 ( V_6 , V_94 , F_601 ( 1 ) ) ;
V_809 &= 0xffffff00 ;
F_135 ( V_6 , V_94 , F_601 ( 1 ) , V_809 ) ;
V_809 = F_133 ( V_6 , V_94 , V_810 ) ;
V_809 &= 0x00ffffff ;
V_809 |= 0xb0000000 ;
F_135 ( V_6 , V_94 , V_810 , V_809 ) ;
}
static void F_602 ( struct V_81 * V_65 ,
struct V_794 * V_795 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_65 -> V_94 ;
F_124 ( F_603 ( V_94 ) , F_604 ( V_795 -> V_796 ) | V_795 -> V_797 ) ;
F_124 ( F_605 ( V_94 ) , V_795 -> V_798 ) ;
F_124 ( F_606 ( V_94 ) , V_795 -> V_799 ) ;
F_124 ( F_607 ( V_94 ) , V_795 -> V_800 ) ;
}
static void F_437 ( struct V_81 * V_65 ,
struct V_794 * V_795 ,
struct V_794 * V_811 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
int V_94 = V_65 -> V_94 ;
enum V_93 V_93 = V_65 -> V_90 -> V_95 ;
if ( F_59 ( V_6 ) >= 5 ) {
F_124 ( F_383 ( V_93 ) , F_604 ( V_795 -> V_796 ) | V_795 -> V_797 ) ;
F_124 ( F_608 ( V_93 ) , V_795 -> V_798 ) ;
F_124 ( F_609 ( V_93 ) , V_795 -> V_799 ) ;
F_124 ( F_610 ( V_93 ) , V_795 -> V_800 ) ;
if ( V_811 && ( F_17 ( V_6 ) ||
F_59 ( V_6 ) < 8 ) && V_65 -> V_90 -> V_812 ) {
F_124 ( F_611 ( V_93 ) ,
F_604 ( V_811 -> V_796 ) | V_811 -> V_797 ) ;
F_124 ( F_612 ( V_93 ) , V_811 -> V_798 ) ;
F_124 ( F_613 ( V_93 ) , V_811 -> V_799 ) ;
F_124 ( F_614 ( V_93 ) , V_811 -> V_800 ) ;
}
} else {
F_124 ( F_615 ( V_94 ) , F_604 ( V_795 -> V_796 ) | V_795 -> V_797 ) ;
F_124 ( F_616 ( V_94 ) , V_795 -> V_798 ) ;
F_124 ( F_617 ( V_94 ) , V_795 -> V_799 ) ;
F_124 ( F_618 ( V_94 ) , V_795 -> V_800 ) ;
}
}
void F_434 ( struct V_81 * V_65 , enum V_813 V_795 )
{
struct V_794 * V_814 , * V_815 = NULL ;
if ( V_795 == V_586 ) {
V_814 = & V_65 -> V_90 -> V_814 ;
V_815 = & V_65 -> V_90 -> V_815 ;
} else if ( V_795 == V_816 ) {
V_814 = & V_65 -> V_90 -> V_815 ;
} else {
F_127 ( L_126 ) ;
return;
}
if ( V_65 -> V_90 -> V_222 )
F_602 ( V_65 , & V_65 -> V_90 -> V_814 ) ;
else
F_437 ( V_65 , V_814 , V_815 ) ;
}
static void F_619 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
V_38 -> V_174 . V_45 = V_189 |
V_190 | V_185 ;
if ( V_65 -> V_94 != V_113 )
V_38 -> V_174 . V_45 |= V_191 ;
if ( ! F_38 ( V_38 , V_223 ) )
V_38 -> V_174 . V_45 |= V_103 |
V_817 ;
V_38 -> V_174 . V_176 =
( V_38 -> V_590 - 1 ) << V_818 ;
}
static void F_620 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
V_38 -> V_174 . V_45 = V_192 |
V_190 | V_185 ;
if ( V_65 -> V_94 != V_113 )
V_38 -> V_174 . V_45 |= V_191 ;
if ( ! F_38 ( V_38 , V_223 ) )
V_38 -> V_174 . V_45 |= V_103 ;
V_38 -> V_174 . V_176 =
( V_38 -> V_590 - 1 ) << V_818 ;
}
static void F_531 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
T_1 V_819 ;
T_1 V_820 , V_821 , V_822 , V_823 , V_824 ;
T_1 V_825 , V_809 ;
F_124 ( F_64 ( V_94 ) ,
V_38 -> V_174 . V_45 &
~ ( V_103 | V_817 ) ) ;
if ( ( V_38 -> V_174 . V_45 & V_103 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_820 = V_38 -> V_45 . V_51 ;
V_821 = V_38 -> V_45 . V_54 ;
V_822 = V_38 -> V_45 . V_47 ;
V_823 = V_38 -> V_45 . V_49 ;
V_824 = V_38 -> V_45 . V_50 ;
if ( V_94 == V_120 )
F_600 ( V_6 , V_94 ) ;
F_135 ( V_6 , V_94 , V_826 , 0x0100000f ) ;
V_809 = F_133 ( V_6 , V_94 , F_621 ( V_94 ) ) ;
V_809 &= 0x00ffffff ;
F_135 ( V_6 , V_94 , F_621 ( V_94 ) , V_809 ) ;
F_135 ( V_6 , V_94 , V_827 , 0x610 ) ;
V_819 = ( ( V_821 << V_828 ) | ( V_822 & V_829 ) ) ;
V_819 |= ( ( V_823 << V_830 ) | ( V_824 << V_831 ) ) ;
V_819 |= ( ( V_820 << V_832 ) ) ;
V_819 |= ( 1 << V_833 ) ;
V_819 |= ( V_834 << V_835 ) ;
F_135 ( V_6 , V_94 , F_622 ( V_94 ) , V_819 ) ;
V_819 |= V_836 ;
F_135 ( V_6 , V_94 , F_622 ( V_94 ) , V_819 ) ;
if ( V_38 -> V_39 == 162000 ||
F_38 ( V_65 -> V_90 , V_615 ) ||
F_38 ( V_65 -> V_90 , V_209 ) )
F_135 ( V_6 , V_94 , F_623 ( V_94 ) ,
0x009f0003 ) ;
else
F_135 ( V_6 , V_94 , F_623 ( V_94 ) ,
0x00d0000f ) ;
if ( F_388 ( V_38 ) ) {
if ( V_94 == V_113 )
F_135 ( V_6 , V_94 , F_624 ( V_94 ) ,
0x0df40000 ) ;
else
F_135 ( V_6 , V_94 , F_624 ( V_94 ) ,
0x0df70000 ) ;
} else {
if ( V_94 == V_113 )
F_135 ( V_6 , V_94 , F_624 ( V_94 ) ,
0x0df70000 ) ;
else
F_135 ( V_6 , V_94 , F_624 ( V_94 ) ,
0x0df40000 ) ;
}
V_825 = F_133 ( V_6 , V_94 , F_625 ( V_94 ) ) ;
V_825 = ( V_825 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_388 ( V_65 -> V_90 ) )
V_825 |= 0x01000000 ;
F_135 ( V_6 , V_94 , F_625 ( V_94 ) , V_825 ) ;
F_135 ( V_6 , V_94 , F_626 ( V_94 ) , 0x87871000 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_530 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
enum V_177 V_178 = F_132 ( V_94 ) ;
T_1 V_837 , V_838 ;
T_1 V_820 , V_821 , V_822 , V_823 , V_824 , V_839 ;
T_1 V_840 ;
int V_52 ;
F_124 ( F_64 ( V_94 ) ,
V_38 -> V_174 . V_45 & ~ V_103 ) ;
if ( ( V_38 -> V_174 . V_45 & V_103 ) == 0 )
return;
V_820 = V_38 -> V_45 . V_51 ;
V_839 = V_38 -> V_45 . V_47 & 0x3fffff ;
V_821 = V_38 -> V_45 . V_54 ;
V_822 = V_38 -> V_45 . V_47 >> 22 ;
V_823 = V_38 -> V_45 . V_49 ;
V_824 = V_38 -> V_45 . V_50 ;
V_52 = V_38 -> V_45 . V_52 ;
V_840 = 0 ;
V_837 = 0 ;
F_3 ( & V_6 -> V_9 ) ;
F_135 ( V_6 , V_94 , F_627 ( V_178 ) ,
5 << V_841 |
V_823 << V_842 |
V_824 << V_843 |
1 << V_844 ) ;
F_135 ( V_6 , V_94 , F_628 ( V_178 ) , V_822 ) ;
F_135 ( V_6 , V_94 , F_629 ( V_178 ) ,
V_845 |
1 << V_846 ) ;
F_135 ( V_6 , V_94 , F_630 ( V_178 ) , V_839 ) ;
V_840 = F_133 ( V_6 , V_94 , F_631 ( V_178 ) ) ;
V_840 &= ~ ( V_847 | V_848 ) ;
V_840 |= ( 2 << V_849 ) ;
if ( V_839 )
V_840 |= V_848 ;
F_135 ( V_6 , V_94 , F_631 ( V_178 ) , V_840 ) ;
V_840 = F_133 ( V_6 , V_94 , F_632 ( V_178 ) ) ;
V_840 &= ~ ( V_850 |
V_851 ) ;
V_840 |= ( 0x5 << V_852 ) ;
if ( ! V_839 )
V_840 |= V_851 ;
F_135 ( V_6 , V_94 , F_632 ( V_178 ) , V_840 ) ;
if ( V_52 == 5400000 ) {
V_837 |= ( 0x3 << V_853 ) ;
V_837 |= ( 0x8 << V_854 ) ;
V_837 |= ( 0x1 << V_855 ) ;
V_838 = 0x9 ;
} else if ( V_52 <= 6200000 ) {
V_837 |= ( 0x5 << V_853 ) ;
V_837 |= ( 0xB << V_854 ) ;
V_837 |= ( 0x3 << V_855 ) ;
V_838 = 0x9 ;
} else if ( V_52 <= 6480000 ) {
V_837 |= ( 0x4 << V_853 ) ;
V_837 |= ( 0x9 << V_854 ) ;
V_837 |= ( 0x3 << V_855 ) ;
V_838 = 0x8 ;
} else {
V_837 |= ( 0x4 << V_853 ) ;
V_837 |= ( 0x9 << V_854 ) ;
V_837 |= ( 0x3 << V_855 ) ;
V_838 = 0 ;
}
F_135 ( V_6 , V_94 , F_633 ( V_178 ) , V_837 ) ;
V_840 = F_133 ( V_6 , V_94 , F_634 ( V_178 ) ) ;
V_840 &= ~ V_856 ;
V_840 |= ( V_838 << V_857 ) ;
F_135 ( V_6 , V_94 , F_634 ( V_178 ) , V_840 ) ;
F_135 ( V_6 , V_94 , F_134 ( V_178 ) ,
F_133 ( V_6 , V_94 , F_134 ( V_178 ) ) |
V_858 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
int F_635 ( struct V_5 * V_6 , enum V_94 V_94 ,
const struct V_45 * V_45 )
{
struct V_81 * V_65 = F_53 ( V_6 , V_94 ) ;
struct V_37 * V_38 ;
V_38 = F_554 ( sizeof( * V_38 ) , V_721 ) ;
if ( ! V_38 )
return - V_720 ;
V_38 -> V_64 . V_65 = & V_65 -> V_64 ;
V_38 -> V_590 = 1 ;
V_38 -> V_45 = * V_45 ;
if ( F_17 ( V_6 ) ) {
F_620 ( V_65 , V_38 ) ;
F_530 ( V_65 , V_38 ) ;
F_136 ( V_65 , V_38 ) ;
} else {
F_619 ( V_65 , V_38 ) ;
F_531 ( V_65 , V_38 ) ;
F_128 ( V_65 , V_38 ) ;
}
F_236 ( V_38 ) ;
return 0 ;
}
void F_636 ( struct V_5 * V_6 , enum V_94 V_94 )
{
if ( F_17 ( V_6 ) )
F_144 ( V_6 , V_94 ) ;
else
F_143 ( V_6 , V_94 ) ;
}
static void F_637 ( struct V_81 * V_65 ,
struct V_37 * V_60 ,
struct V_45 * V_805 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
T_1 V_45 ;
struct V_45 * clock = & V_60 -> V_45 ;
F_599 ( V_65 , V_60 , V_805 ) ;
V_45 = V_185 ;
if ( F_38 ( V_60 , V_66 ) )
V_45 |= V_859 ;
else
V_45 |= V_860 ;
if ( F_638 ( V_6 ) || F_639 ( V_6 ) ||
F_589 ( V_6 ) || F_19 ( V_6 ) ) {
V_45 |= ( V_60 -> V_590 - 1 )
<< V_861 ;
}
if ( F_38 ( V_60 , V_214 ) ||
F_38 ( V_60 , V_209 ) )
V_45 |= V_862 ;
if ( F_388 ( V_60 ) )
V_45 |= V_862 ;
if ( F_19 ( V_6 ) )
V_45 |= ( 1 << ( clock -> V_49 - 1 ) ) << V_863 ;
else {
V_45 |= ( 1 << ( clock -> V_49 - 1 ) ) << V_864 ;
if ( F_18 ( V_6 ) && V_805 )
V_45 |= ( 1 << ( V_805 -> V_49 - 1 ) ) << V_865 ;
}
switch ( clock -> V_50 ) {
case 5 :
V_45 |= V_866 ;
break;
case 7 :
V_45 |= V_867 ;
break;
case 10 :
V_45 |= V_868 ;
break;
case 14 :
V_45 |= V_869 ;
break;
}
if ( F_59 ( V_6 ) >= 4 )
V_45 |= ( 6 << V_870 ) ;
if ( V_60 -> V_871 )
V_45 |= V_872 ;
else if ( F_38 ( V_60 , V_66 ) &&
F_596 ( V_6 ) )
V_45 |= V_873 ;
else
V_45 |= V_874 ;
V_45 |= V_103 ;
V_60 -> V_174 . V_45 = V_45 ;
if ( F_59 ( V_6 ) >= 4 ) {
T_1 V_176 = ( V_60 -> V_590 - 1 )
<< V_818 ;
V_60 -> V_174 . V_176 = V_176 ;
}
}
static void F_640 ( struct V_81 * V_65 ,
struct V_37 * V_60 ,
struct V_45 * V_805 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_45 ;
struct V_45 * clock = & V_60 -> V_45 ;
F_599 ( V_65 , V_60 , V_805 ) ;
V_45 = V_185 ;
if ( F_38 ( V_60 , V_66 ) ) {
V_45 |= ( 1 << ( clock -> V_49 - 1 ) ) << V_864 ;
} else {
if ( clock -> V_49 == 2 )
V_45 |= V_875 ;
else
V_45 |= ( clock -> V_49 - 2 ) << V_864 ;
if ( clock -> V_50 == 4 )
V_45 |= V_876 ;
}
if ( ! F_141 ( V_6 ) &&
F_38 ( V_60 , V_187 ) )
V_45 |= V_188 ;
if ( F_38 ( V_60 , V_66 ) &&
F_596 ( V_6 ) )
V_45 |= V_873 ;
else
V_45 |= V_874 ;
V_45 |= V_103 ;
V_60 -> V_174 . V_45 = V_45 ;
}
static void F_435 ( struct V_81 * V_81 )
{
struct V_5 * V_6 = F_41 ( V_81 -> V_64 . V_63 ) ;
enum V_94 V_94 = V_81 -> V_94 ;
enum V_93 V_95 = V_81 -> V_90 -> V_95 ;
const struct V_520 * V_91 = & V_81 -> V_90 -> V_64 . V_91 ;
T_2 V_877 , V_878 ;
int V_879 = 0 ;
V_877 = V_91 -> V_877 ;
V_878 = V_91 -> V_878 ;
if ( V_91 -> V_330 & V_880 ) {
V_877 -= 1 ;
V_878 -= 1 ;
if ( F_38 ( V_81 -> V_90 , V_214 ) )
V_879 = ( V_91 -> V_881 - 1 ) / 2 ;
else
V_879 = V_91 -> V_734 -
V_91 -> V_881 / 2 ;
if ( V_879 < 0 )
V_879 += V_91 -> V_881 ;
}
if ( F_59 ( V_6 ) > 3 )
F_124 ( F_375 ( V_95 ) , V_879 ) ;
F_124 ( F_363 ( V_95 ) ,
( V_91 -> V_543 - 1 ) |
( ( V_91 -> V_881 - 1 ) << 16 ) ) ;
F_124 ( F_365 ( V_95 ) ,
( V_91 -> V_882 - 1 ) |
( ( V_91 -> V_883 - 1 ) << 16 ) ) ;
F_124 ( F_367 ( V_95 ) ,
( V_91 -> V_734 - 1 ) |
( ( V_91 -> V_884 - 1 ) << 16 ) ) ;
F_124 ( F_369 ( V_95 ) ,
( V_91 -> V_544 - 1 ) |
( ( V_877 - 1 ) << 16 ) ) ;
F_124 ( F_371 ( V_95 ) ,
( V_91 -> V_885 - 1 ) |
( ( V_878 - 1 ) << 16 ) ) ;
F_124 ( F_373 ( V_95 ) ,
( V_91 -> V_886 - 1 ) |
( ( V_91 -> V_887 - 1 ) << 16 ) ) ;
if ( F_264 ( V_6 ) && V_95 == V_589 &&
( V_94 == V_120 || V_94 == V_510 ) )
F_124 ( F_369 ( V_94 ) , F_11 ( F_369 ( V_95 ) ) ) ;
}
static void F_436 ( struct V_81 * V_81 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_94 V_94 = V_81 -> V_94 ;
F_124 ( F_321 ( V_94 ) ,
( ( V_81 -> V_90 -> V_367 - 1 ) << 16 ) |
( V_81 -> V_90 -> V_366 - 1 ) ) ;
}
static void F_641 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_93 V_95 = V_38 -> V_95 ;
T_2 V_179 ;
V_179 = F_11 ( F_363 ( V_95 ) ) ;
V_38 -> V_64 . V_91 . V_543 = ( V_179 & 0xffff ) + 1 ;
V_38 -> V_64 . V_91 . V_881 = ( ( V_179 >> 16 ) & 0xffff ) + 1 ;
V_179 = F_11 ( F_365 ( V_95 ) ) ;
V_38 -> V_64 . V_91 . V_882 = ( V_179 & 0xffff ) + 1 ;
V_38 -> V_64 . V_91 . V_883 = ( ( V_179 >> 16 ) & 0xffff ) + 1 ;
V_179 = F_11 ( F_367 ( V_95 ) ) ;
V_38 -> V_64 . V_91 . V_734 = ( V_179 & 0xffff ) + 1 ;
V_38 -> V_64 . V_91 . V_884 = ( ( V_179 >> 16 ) & 0xffff ) + 1 ;
V_179 = F_11 ( F_369 ( V_95 ) ) ;
V_38 -> V_64 . V_91 . V_544 = ( V_179 & 0xffff ) + 1 ;
V_38 -> V_64 . V_91 . V_877 = ( ( V_179 >> 16 ) & 0xffff ) + 1 ;
V_179 = F_11 ( F_371 ( V_95 ) ) ;
V_38 -> V_64 . V_91 . V_885 = ( V_179 & 0xffff ) + 1 ;
V_38 -> V_64 . V_91 . V_878 = ( ( V_179 >> 16 ) & 0xffff ) + 1 ;
V_179 = F_11 ( F_373 ( V_95 ) ) ;
V_38 -> V_64 . V_91 . V_886 = ( V_179 & 0xffff ) + 1 ;
V_38 -> V_64 . V_91 . V_887 = ( ( V_179 >> 16 ) & 0xffff ) + 1 ;
if ( F_11 ( F_60 ( V_95 ) ) & V_212 ) {
V_38 -> V_64 . V_91 . V_330 |= V_880 ;
V_38 -> V_64 . V_91 . V_877 += 1 ;
V_38 -> V_64 . V_91 . V_878 += 1 ;
}
}
static void F_642 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_179 ;
V_179 = F_11 ( F_321 ( V_65 -> V_94 ) ) ;
V_38 -> V_366 = ( V_179 & 0xffff ) + 1 ;
V_38 -> V_367 = ( ( V_179 >> 16 ) & 0xffff ) + 1 ;
V_38 -> V_64 . V_417 . V_888 = V_38 -> V_366 ;
V_38 -> V_64 . V_417 . V_889 = V_38 -> V_367 ;
}
void F_643 ( struct V_520 * V_417 ,
struct V_37 * V_38 )
{
V_417 -> V_889 = V_38 -> V_64 . V_91 . V_543 ;
V_417 -> V_890 = V_38 -> V_64 . V_91 . V_881 ;
V_417 -> V_891 = V_38 -> V_64 . V_91 . V_734 ;
V_417 -> V_892 = V_38 -> V_64 . V_91 . V_884 ;
V_417 -> V_888 = V_38 -> V_64 . V_91 . V_544 ;
V_417 -> V_893 = V_38 -> V_64 . V_91 . V_877 ;
V_417 -> V_894 = V_38 -> V_64 . V_91 . V_886 ;
V_417 -> V_895 = V_38 -> V_64 . V_91 . V_887 ;
V_417 -> V_330 = V_38 -> V_64 . V_91 . V_330 ;
V_417 -> type = V_896 ;
V_417 -> clock = V_38 -> V_64 . V_91 . V_92 ;
V_417 -> V_897 = F_644 ( V_417 ) ;
V_417 -> V_898 = F_645 ( V_417 ) ;
F_646 ( V_417 ) ;
}
static void F_529 ( struct V_81 * V_81 )
{
struct V_5 * V_6 = F_41 ( V_81 -> V_64 . V_63 ) ;
T_2 V_899 ;
V_899 = 0 ;
if ( ( V_81 -> V_94 == V_113 && V_6 -> V_129 & V_130 ) ||
( V_81 -> V_94 == V_120 && V_6 -> V_129 & V_131 ) )
V_899 |= F_11 ( F_60 ( V_81 -> V_94 ) ) & V_132 ;
if ( V_81 -> V_90 -> V_226 )
V_899 |= V_227 ;
if ( F_18 ( V_6 ) || F_16 ( V_6 ) ||
F_17 ( V_6 ) ) {
if ( V_81 -> V_90 -> V_900 && V_81 -> V_90 -> V_729 != 30 )
V_899 |= V_901 |
V_902 ;
switch ( V_81 -> V_90 -> V_729 ) {
case 18 :
V_899 |= V_903 ;
break;
case 24 :
V_899 |= V_210 ;
break;
case 30 :
V_899 |= V_904 ;
break;
default:
F_146 () ;
}
}
if ( F_647 ( V_6 ) ) {
if ( V_81 -> V_808 ) {
F_161 ( L_127 ) ;
V_899 |= V_905 ;
} else {
F_161 ( L_128 ) ;
}
}
if ( V_81 -> V_90 -> V_64 . V_91 . V_330 & V_880 ) {
if ( F_59 ( V_6 ) < 4 ||
F_38 ( V_81 -> V_90 , V_214 ) )
V_899 |= V_906 ;
else
V_899 |= V_907 ;
} else
V_899 |= V_908 ;
if ( ( F_16 ( V_6 ) || F_17 ( V_6 ) ) &&
V_81 -> V_90 -> V_909 )
V_899 |= V_910 ;
F_124 ( F_60 ( V_81 -> V_94 ) , V_899 ) ;
F_125 ( F_60 ( V_81 -> V_94 ) ) ;
}
static int F_648 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
const struct V_56 * V_57 ;
int V_44 = 48000 ;
memset ( & V_60 -> V_174 , 0 ,
sizeof( V_60 -> V_174 ) ) ;
if ( F_38 ( V_60 , V_66 ) ) {
if ( F_596 ( V_6 ) ) {
V_44 = V_6 -> V_802 . V_911 ;
F_161 ( L_129 , V_44 ) ;
}
V_57 = & V_912 ;
} else if ( F_38 ( V_60 , V_187 ) ) {
V_57 = & V_913 ;
} else {
V_57 = & V_914 ;
}
if ( ! V_60 -> V_915 &&
! F_40 ( V_57 , V_60 , V_60 -> V_39 ,
V_44 , NULL , & V_60 -> V_45 ) ) {
F_127 ( L_130 ) ;
return - V_288 ;
}
F_640 ( V_65 , V_60 , NULL ) ;
return 0 ;
}
static int F_649 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
const struct V_56 * V_57 ;
int V_44 = 96000 ;
memset ( & V_60 -> V_174 , 0 ,
sizeof( V_60 -> V_174 ) ) ;
if ( F_38 ( V_60 , V_66 ) ) {
if ( F_596 ( V_6 ) ) {
V_44 = V_6 -> V_802 . V_911 ;
F_161 ( L_129 , V_44 ) ;
}
if ( F_39 ( V_63 ) )
V_57 = & V_916 ;
else
V_57 = & V_917 ;
} else if ( F_38 ( V_60 , V_209 ) ||
F_38 ( V_60 , V_615 ) ) {
V_57 = & V_918 ;
} else if ( F_38 ( V_60 , V_214 ) ) {
V_57 = & V_919 ;
} else {
V_57 = & V_920 ;
}
if ( ! V_60 -> V_915 &&
! F_43 ( V_57 , V_60 , V_60 -> V_39 ,
V_44 , NULL , & V_60 -> V_45 ) ) {
F_127 ( L_130 ) ;
return - V_288 ;
}
F_637 ( V_65 , V_60 , NULL ) ;
return 0 ;
}
static int F_650 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
const struct V_56 * V_57 ;
int V_44 = 96000 ;
memset ( & V_60 -> V_174 , 0 ,
sizeof( V_60 -> V_174 ) ) ;
if ( F_38 ( V_60 , V_66 ) ) {
if ( F_596 ( V_6 ) ) {
V_44 = V_6 -> V_802 . V_911 ;
F_161 ( L_129 , V_44 ) ;
}
V_57 = & V_921 ;
} else {
V_57 = & V_922 ;
}
if ( ! V_60 -> V_915 &&
! F_42 ( V_57 , V_60 , V_60 -> V_39 ,
V_44 , NULL , & V_60 -> V_45 ) ) {
F_127 ( L_130 ) ;
return - V_288 ;
}
F_637 ( V_65 , V_60 , NULL ) ;
return 0 ;
}
static int F_651 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
const struct V_56 * V_57 ;
int V_44 = 96000 ;
memset ( & V_60 -> V_174 , 0 ,
sizeof( V_60 -> V_174 ) ) ;
if ( F_38 ( V_60 , V_66 ) ) {
if ( F_596 ( V_6 ) ) {
V_44 = V_6 -> V_802 . V_911 ;
F_161 ( L_129 , V_44 ) ;
}
V_57 = & V_923 ;
} else {
V_57 = & V_920 ;
}
if ( ! V_60 -> V_915 &&
! F_40 ( V_57 , V_60 , V_60 -> V_39 ,
V_44 , NULL , & V_60 -> V_45 ) ) {
F_127 ( L_130 ) ;
return - V_288 ;
}
F_637 ( V_65 , V_60 , NULL ) ;
return 0 ;
}
static int F_652 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
int V_44 = 100000 ;
const struct V_56 * V_57 = & V_924 ;
memset ( & V_60 -> V_174 , 0 ,
sizeof( V_60 -> V_174 ) ) ;
if ( ! V_60 -> V_915 &&
! F_49 ( V_57 , V_60 , V_60 -> V_39 ,
V_44 , NULL , & V_60 -> V_45 ) ) {
F_127 ( L_130 ) ;
return - V_288 ;
}
F_620 ( V_65 , V_60 ) ;
return 0 ;
}
static int F_653 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
int V_44 = 100000 ;
const struct V_56 * V_57 = & V_925 ;
memset ( & V_60 -> V_174 , 0 ,
sizeof( V_60 -> V_174 ) ) ;
if ( ! V_60 -> V_915 &&
! F_47 ( V_57 , V_60 , V_60 -> V_39 ,
V_44 , NULL , & V_60 -> V_45 ) ) {
F_127 ( L_130 ) ;
return - V_288 ;
}
F_619 ( V_65 , V_60 ) ;
return 0 ;
}
static void F_654 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
T_2 V_179 ;
if ( F_59 ( V_6 ) <= 3 &&
( F_141 ( V_6 ) || ! F_140 ( V_6 ) ) )
return;
V_179 = F_11 ( V_597 ) ;
if ( ! ( V_179 & V_598 ) )
return;
if ( F_59 ( V_6 ) < 4 ) {
if ( V_65 -> V_94 != V_120 )
return;
} else {
if ( ( V_179 & V_926 ) != ( V_65 -> V_94 << V_927 ) )
return;
}
V_38 -> V_595 . V_596 = V_179 ;
V_38 -> V_595 . V_600 = F_11 ( V_599 ) ;
}
static void F_655 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_38 -> V_95 ;
struct V_45 clock ;
T_1 V_819 ;
int V_44 = 100000 ;
if ( ( V_38 -> V_174 . V_45 & V_103 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_819 = F_133 ( V_6 , V_94 , F_622 ( V_94 ) ) ;
F_5 ( & V_6 -> V_9 ) ;
clock . V_54 = ( V_819 >> V_828 ) & 7 ;
clock . V_47 = V_819 & V_829 ;
clock . V_51 = ( V_819 >> V_832 ) & 0xf ;
clock . V_49 = ( V_819 >> V_830 ) & 7 ;
clock . V_50 = ( V_819 >> V_831 ) & 0x1f ;
V_38 -> V_39 = F_31 ( V_44 , & clock ) ;
}
static void
F_656 ( struct V_81 * V_65 ,
struct V_318 * V_319 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_15 , V_64 , V_276 ;
int V_94 = V_65 -> V_94 , V_133 = V_65 -> V_133 ;
int V_928 , V_238 ;
unsigned int V_929 ;
struct V_245 * V_89 ;
struct V_267 * V_268 ;
V_15 = F_11 ( F_88 ( V_133 ) ) ;
if ( ! ( V_15 & V_134 ) )
return;
V_268 = F_554 ( sizeof( * V_268 ) , V_721 ) ;
if ( ! V_268 ) {
F_161 ( L_131 ) ;
return;
}
V_89 = & V_268 -> V_64 ;
V_89 -> V_63 = V_63 ;
if ( F_59 ( V_6 ) >= 4 ) {
if ( V_15 & V_369 ) {
V_319 -> V_328 = V_282 ;
V_89 -> V_257 = V_231 ;
}
}
V_238 = V_15 & V_930 ;
V_928 = F_222 ( V_238 ) ;
V_89 -> V_266 = F_657 ( V_928 ) ;
if ( F_59 ( V_6 ) >= 4 ) {
if ( V_319 -> V_328 )
V_276 = F_11 ( F_259 ( V_133 ) ) ;
else
V_276 = F_11 ( F_260 ( V_133 ) ) ;
V_64 = F_11 ( F_258 ( V_133 ) ) & 0xfffff000 ;
} else {
V_64 = F_11 ( F_261 ( V_133 ) ) ;
}
V_319 -> V_64 = V_64 ;
V_15 = F_11 ( F_321 ( V_94 ) ) ;
V_89 -> V_242 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_89 -> V_237 = ( ( V_15 >> 0 ) & 0xfff ) + 1 ;
V_15 = F_11 ( F_257 ( V_94 ) ) ;
V_89 -> V_262 [ 0 ] = V_15 & 0xffffffc0 ;
V_929 = F_175 ( V_63 , V_89 -> V_237 ,
V_89 -> V_266 -> V_266 ,
V_89 -> V_257 ) ;
V_319 -> V_241 = V_89 -> V_262 [ 0 ] * V_929 ;
F_161 ( L_132 ,
F_78 ( V_94 ) , V_133 , V_89 -> V_242 , V_89 -> V_237 ,
V_89 -> V_266 -> V_229 [ 0 ] * 8 , V_64 , V_89 -> V_262 [ 0 ] ,
V_319 -> V_241 ) ;
V_319 -> V_89 = V_268 ;
}
static void F_658 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_38 -> V_95 ;
enum V_177 V_178 = F_132 ( V_94 ) ;
struct V_45 clock ;
T_1 V_931 , V_932 , V_933 , V_934 , V_935 ;
int V_44 = 100000 ;
if ( ( V_38 -> V_174 . V_45 & V_103 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_931 = F_133 ( V_6 , V_94 , F_627 ( V_178 ) ) ;
V_932 = F_133 ( V_6 , V_94 , F_628 ( V_178 ) ) ;
V_933 = F_133 ( V_6 , V_94 , F_629 ( V_178 ) ) ;
V_934 = F_133 ( V_6 , V_94 , F_630 ( V_178 ) ) ;
V_935 = F_133 ( V_6 , V_94 , F_631 ( V_178 ) ) ;
F_5 ( & V_6 -> V_9 ) ;
clock . V_54 = ( V_933 & 0x7 ) == V_845 ? 2 : 0 ;
clock . V_47 = ( V_932 & 0xff ) << 22 ;
if ( V_935 & V_848 )
clock . V_47 |= V_934 & 0x3fffff ;
clock . V_51 = ( V_933 >> V_846 ) & 0xf ;
clock . V_49 = ( V_931 >> V_842 ) & 0x7 ;
clock . V_50 = ( V_931 >> V_843 ) & 0x1f ;
V_38 -> V_39 = F_32 ( V_44 , & clock ) ;
}
static bool F_659 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
enum V_127 V_128 ;
T_2 V_179 ;
bool V_362 ;
V_128 = F_467 ( V_65 -> V_94 ) ;
if ( ! F_85 ( V_6 , V_128 ) )
return false ;
V_38 -> V_95 = (enum V_93 ) V_65 -> V_94 ;
V_38 -> V_206 = NULL ;
V_362 = false ;
V_179 = F_11 ( F_60 ( V_65 -> V_94 ) ) ;
if ( ! ( V_179 & V_132 ) )
goto V_936;
if ( F_18 ( V_6 ) || F_16 ( V_6 ) ||
F_17 ( V_6 ) ) {
switch ( V_179 & V_208 ) {
case V_903 :
V_38 -> V_729 = 18 ;
break;
case V_210 :
V_38 -> V_729 = 24 ;
break;
case V_904 :
V_38 -> V_729 = 30 ;
break;
default:
break;
}
}
if ( ( F_16 ( V_6 ) || F_17 ( V_6 ) ) &&
( V_179 & V_910 ) )
V_38 -> V_909 = true ;
if ( F_59 ( V_6 ) < 4 )
V_38 -> V_226 = V_179 & V_227 ;
F_641 ( V_65 , V_38 ) ;
F_642 ( V_65 , V_38 ) ;
F_654 ( V_65 , V_38 ) ;
if ( F_59 ( V_6 ) >= 4 ) {
if ( F_17 ( V_6 ) && V_65 -> V_94 != V_113 )
V_179 = V_6 -> V_184 [ V_65 -> V_94 ] ;
else
V_179 = F_11 ( F_130 ( V_65 -> V_94 ) ) ;
V_38 -> V_590 =
( ( V_179 & V_937 )
>> V_818 ) + 1 ;
V_38 -> V_174 . V_176 = V_179 ;
} else if ( F_638 ( V_6 ) || F_639 ( V_6 ) ||
F_589 ( V_6 ) || F_19 ( V_6 ) ) {
V_179 = F_11 ( F_64 ( V_65 -> V_94 ) ) ;
V_38 -> V_590 =
( ( V_179 & V_938 )
>> V_861 ) + 1 ;
} else {
V_38 -> V_590 = 1 ;
}
V_38 -> V_174 . V_45 = F_11 ( F_64 ( V_65 -> V_94 ) ) ;
if ( ! F_16 ( V_6 ) && ! F_17 ( V_6 ) ) {
if ( F_141 ( V_6 ) )
V_38 -> V_174 . V_45 &= ~ V_188 ;
V_38 -> V_174 . V_712 = F_11 ( F_533 ( V_65 -> V_94 ) ) ;
V_38 -> V_174 . V_713 = F_11 ( F_534 ( V_65 -> V_94 ) ) ;
} else {
V_38 -> V_174 . V_45 &= ~ ( V_175 |
V_201 |
V_199 ) ;
}
if ( F_17 ( V_6 ) )
F_658 ( V_65 , V_38 ) ;
else if ( F_16 ( V_6 ) )
F_655 ( V_65 , V_38 ) ;
else
F_660 ( V_65 , V_38 ) ;
V_38 -> V_64 . V_91 . V_92 =
V_38 -> V_39 / V_38 -> V_590 ;
V_362 = true ;
V_936:
F_86 ( V_6 , V_128 ) ;
return V_362 ;
}
static void F_661 ( struct V_5 * V_6 )
{
struct V_511 * V_512 ;
int V_135 ;
T_1 V_15 , V_939 ;
bool V_940 = false ;
bool V_941 = false ;
bool V_942 = false ;
bool V_943 = false ;
bool V_944 = false ;
bool V_945 = false ;
F_662 (&dev_priv->drm, encoder) {
switch ( V_512 -> type ) {
case V_66 :
V_942 = true ;
V_940 = true ;
break;
case V_514 :
V_942 = true ;
if ( F_380 ( & V_512 -> V_64 ) -> V_178 == V_601 )
V_941 = true ;
break;
default:
break;
}
}
if ( F_120 ( V_6 ) ) {
V_943 = V_6 -> V_802 . V_946 ;
V_944 = V_943 ;
} else {
V_943 = false ;
V_944 = true ;
}
for ( V_135 = 0 ; V_135 < V_6 -> V_947 ; V_135 ++ ) {
T_1 V_444 = F_11 ( F_663 ( V_135 ) ) ;
if ( ! ( V_444 & V_103 ) )
continue;
if ( ( V_444 & V_948 ) ==
V_873 ) {
V_945 = true ;
break;
}
}
F_161 ( L_133 ,
V_942 , V_940 , V_943 , V_945 ) ;
V_15 = F_11 ( V_949 ) ;
V_939 = V_15 ;
V_939 &= ~ V_950 ;
if ( V_943 )
V_939 |= V_951 ;
else
V_939 |= V_952 ;
V_939 &= ~ V_953 ;
V_939 &= ~ V_954 ;
V_939 &= ~ V_955 ;
if ( V_942 ) {
V_939 |= V_956 ;
if ( F_596 ( V_6 ) && V_944 )
V_939 |= V_955 ;
if ( V_941 ) {
if ( F_596 ( V_6 ) && V_944 )
V_939 |= V_957 ;
else
V_939 |= V_958 ;
} else
V_939 |= V_959 ;
} else if ( V_945 ) {
V_939 |= V_956 ;
V_939 |= V_955 ;
}
if ( V_939 == V_15 )
return;
V_15 &= ~ V_950 ;
if ( V_943 )
V_15 |= V_951 ;
else
V_15 |= V_952 ;
if ( V_942 ) {
V_15 &= ~ V_953 ;
V_15 |= V_956 ;
if ( F_596 ( V_6 ) && V_944 ) {
F_161 ( L_134 ) ;
V_15 |= V_955 ;
} else
V_15 &= ~ V_955 ;
F_124 ( V_949 , V_15 ) ;
F_125 ( V_949 ) ;
F_126 ( 200 ) ;
V_15 &= ~ V_954 ;
if ( V_941 ) {
if ( F_596 ( V_6 ) && V_944 ) {
F_161 ( L_135 ) ;
V_15 |= V_957 ;
} else
V_15 |= V_958 ;
} else
V_15 |= V_959 ;
F_124 ( V_949 , V_15 ) ;
F_125 ( V_949 ) ;
F_126 ( 200 ) ;
} else {
F_161 ( L_136 ) ;
V_15 &= ~ V_954 ;
V_15 |= V_959 ;
F_124 ( V_949 , V_15 ) ;
F_125 ( V_949 ) ;
F_126 ( 200 ) ;
if ( ! V_945 ) {
F_161 ( L_137 ) ;
V_15 &= ~ V_953 ;
V_15 |= V_960 ;
V_15 &= ~ V_955 ;
F_124 ( V_949 , V_15 ) ;
F_125 ( V_949 ) ;
F_126 ( 200 ) ;
}
}
F_664 ( V_15 != V_939 ) ;
}
static void F_665 ( struct V_5 * V_6 )
{
T_2 V_179 ;
V_179 = F_11 ( V_961 ) ;
V_179 |= V_962 ;
F_124 ( V_961 , V_179 ) ;
if ( F_666 ( F_11 ( V_961 ) &
V_963 , 100 ) )
F_127 ( L_138 ) ;
V_179 = F_11 ( V_961 ) ;
V_179 &= ~ V_962 ;
F_124 ( V_961 , V_179 ) ;
if ( F_666 ( ( F_11 ( V_961 ) &
V_963 ) == 0 , 100 ) )
F_127 ( L_139 ) ;
}
static void F_667 ( struct V_5 * V_6 )
{
T_2 V_179 ;
V_179 = F_353 ( V_6 , 0x8008 , V_964 ) ;
V_179 &= ~ ( 0xFF << 24 ) ;
V_179 |= ( 0x12 << 24 ) ;
F_354 ( V_6 , 0x8008 , V_179 , V_964 ) ;
V_179 = F_353 ( V_6 , 0x2008 , V_964 ) ;
V_179 |= ( 1 << 11 ) ;
F_354 ( V_6 , 0x2008 , V_179 , V_964 ) ;
V_179 = F_353 ( V_6 , 0x2108 , V_964 ) ;
V_179 |= ( 1 << 11 ) ;
F_354 ( V_6 , 0x2108 , V_179 , V_964 ) ;
V_179 = F_353 ( V_6 , 0x206C , V_964 ) ;
V_179 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_354 ( V_6 , 0x206C , V_179 , V_964 ) ;
V_179 = F_353 ( V_6 , 0x216C , V_964 ) ;
V_179 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_354 ( V_6 , 0x216C , V_179 , V_964 ) ;
V_179 = F_353 ( V_6 , 0x2080 , V_964 ) ;
V_179 &= ~ ( 7 << 13 ) ;
V_179 |= ( 5 << 13 ) ;
F_354 ( V_6 , 0x2080 , V_179 , V_964 ) ;
V_179 = F_353 ( V_6 , 0x2180 , V_964 ) ;
V_179 &= ~ ( 7 << 13 ) ;
V_179 |= ( 5 << 13 ) ;
F_354 ( V_6 , 0x2180 , V_179 , V_964 ) ;
V_179 = F_353 ( V_6 , 0x208C , V_964 ) ;
V_179 &= ~ 0xFF ;
V_179 |= 0x1C ;
F_354 ( V_6 , 0x208C , V_179 , V_964 ) ;
V_179 = F_353 ( V_6 , 0x218C , V_964 ) ;
V_179 &= ~ 0xFF ;
V_179 |= 0x1C ;
F_354 ( V_6 , 0x218C , V_179 , V_964 ) ;
V_179 = F_353 ( V_6 , 0x2098 , V_964 ) ;
V_179 &= ~ ( 0xFF << 16 ) ;
V_179 |= ( 0x1C << 16 ) ;
F_354 ( V_6 , 0x2098 , V_179 , V_964 ) ;
V_179 = F_353 ( V_6 , 0x2198 , V_964 ) ;
V_179 &= ~ ( 0xFF << 16 ) ;
V_179 |= ( 0x1C << 16 ) ;
F_354 ( V_6 , 0x2198 , V_179 , V_964 ) ;
V_179 = F_353 ( V_6 , 0x20C4 , V_964 ) ;
V_179 |= ( 1 << 27 ) ;
F_354 ( V_6 , 0x20C4 , V_179 , V_964 ) ;
V_179 = F_353 ( V_6 , 0x21C4 , V_964 ) ;
V_179 |= ( 1 << 27 ) ;
F_354 ( V_6 , 0x21C4 , V_179 , V_964 ) ;
V_179 = F_353 ( V_6 , 0x20EC , V_964 ) ;
V_179 &= ~ ( 0xF << 28 ) ;
V_179 |= ( 4 << 28 ) ;
F_354 ( V_6 , 0x20EC , V_179 , V_964 ) ;
V_179 = F_353 ( V_6 , 0x21EC , V_964 ) ;
V_179 &= ~ ( 0xF << 28 ) ;
V_179 |= ( 4 << 28 ) ;
F_354 ( V_6 , 0x21EC , V_179 , V_964 ) ;
}
static void F_668 ( struct V_5 * V_6 ,
bool V_965 , bool V_966 )
{
T_2 V_13 , V_179 ;
if ( F_7 ( V_966 && ! V_965 , L_140 ) )
V_965 = true ;
if ( F_7 ( F_669 ( V_6 ) &&
V_966 , L_141 ) )
V_966 = false ;
F_3 ( & V_6 -> V_9 ) ;
V_179 = F_353 ( V_6 , V_967 , V_487 ) ;
V_179 &= ~ V_488 ;
V_179 |= V_968 ;
F_354 ( V_6 , V_967 , V_179 , V_487 ) ;
F_126 ( 24 ) ;
if ( V_965 ) {
V_179 = F_353 ( V_6 , V_967 , V_487 ) ;
V_179 &= ~ V_968 ;
F_354 ( V_6 , V_967 , V_179 , V_487 ) ;
if ( V_966 ) {
F_665 ( V_6 ) ;
F_667 ( V_6 ) ;
}
}
V_13 = F_669 ( V_6 ) ? V_969 : V_970 ;
V_179 = F_353 ( V_6 , V_13 , V_487 ) ;
V_179 |= V_971 ;
F_354 ( V_6 , V_13 , V_179 , V_487 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_670 ( struct V_5 * V_6 )
{
T_2 V_13 , V_179 ;
F_3 ( & V_6 -> V_9 ) ;
V_13 = F_669 ( V_6 ) ? V_969 : V_970 ;
V_179 = F_353 ( V_6 , V_13 , V_487 ) ;
V_179 &= ~ V_971 ;
F_354 ( V_6 , V_13 , V_179 , V_487 ) ;
V_179 = F_353 ( V_6 , V_967 , V_487 ) ;
if ( ! ( V_179 & V_488 ) ) {
if ( ! ( V_179 & V_968 ) ) {
V_179 |= V_968 ;
F_354 ( V_6 , V_967 , V_179 , V_487 ) ;
F_126 ( 32 ) ;
}
V_179 |= V_488 ;
F_354 ( V_6 , V_967 , V_179 , V_487 ) ;
}
F_5 ( & V_6 -> V_9 ) ;
}
static void F_671 ( struct V_5 * V_6 , int V_972 )
{
T_2 V_179 ;
int V_973 = F_672 ( V_972 ) ;
if ( F_28 ( V_972 % 5 != 0 ) )
return;
if ( F_28 ( V_973 >= F_179 ( V_974 ) ) )
return;
F_3 ( & V_6 -> V_9 ) ;
if ( V_972 % 10 != 0 )
V_179 = 0xAAAAAAAB ;
else
V_179 = 0x00000000 ;
F_354 ( V_6 , V_975 , V_179 , V_487 ) ;
V_179 = F_353 ( V_6 , V_976 , V_487 ) ;
V_179 &= 0xffff0000 ;
V_179 |= V_974 [ V_973 ] ;
F_354 ( V_6 , V_976 , V_179 , V_487 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_673 ( struct V_5 * V_6 )
{
struct V_511 * V_512 ;
bool V_977 = false ;
F_662 (&dev_priv->drm, encoder) {
switch ( V_512 -> type ) {
case V_615 :
V_977 = true ;
break;
default:
break;
}
}
if ( V_977 ) {
F_671 ( V_6 , 0 ) ;
F_668 ( V_6 , true , true ) ;
} else {
F_670 ( V_6 ) ;
}
}
void F_674 ( struct V_5 * V_6 )
{
if ( F_120 ( V_6 ) || F_106 ( V_6 ) )
F_661 ( V_6 ) ;
else if ( F_159 ( V_6 ) )
F_673 ( V_6 ) ;
}
static void F_438 ( struct V_145 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_2 V_15 ;
V_15 = 0 ;
switch ( V_81 -> V_90 -> V_729 ) {
case 18 :
V_15 |= V_903 ;
break;
case 24 :
V_15 |= V_210 ;
break;
case 30 :
V_15 |= V_904 ;
break;
case 36 :
V_15 |= V_978 ;
break;
default:
F_146 () ;
}
if ( V_81 -> V_90 -> V_900 )
V_15 |= ( V_901 | V_902 ) ;
if ( V_81 -> V_90 -> V_64 . V_91 . V_330 & V_880 )
V_15 |= V_213 ;
else
V_15 |= V_908 ;
if ( V_81 -> V_90 -> V_909 )
V_15 |= V_910 ;
F_124 ( F_60 ( V_94 ) , V_15 ) ;
F_125 ( F_60 ( V_94 ) ) ;
}
static void F_446 ( struct V_145 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
enum V_93 V_95 = V_81 -> V_90 -> V_95 ;
T_1 V_15 = 0 ;
if ( F_264 ( V_6 ) && V_81 -> V_90 -> V_900 )
V_15 |= ( V_901 | V_902 ) ;
if ( V_81 -> V_90 -> V_64 . V_91 . V_330 & V_880 )
V_15 |= V_213 ;
else
V_15 |= V_908 ;
F_124 ( F_60 ( V_95 ) , V_15 ) ;
F_125 ( F_60 ( V_95 ) ) ;
}
static void F_447 ( struct V_145 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
if ( F_265 ( V_6 ) || F_184 ( V_6 ) -> V_250 >= 9 ) {
T_1 V_15 = 0 ;
switch ( V_81 -> V_90 -> V_729 ) {
case 18 :
V_15 |= V_979 ;
break;
case 24 :
V_15 |= V_980 ;
break;
case 30 :
V_15 |= V_981 ;
break;
case 36 :
V_15 |= V_982 ;
break;
default:
F_146 () ;
}
if ( V_81 -> V_90 -> V_900 )
V_15 |= V_983 | V_984 ;
F_124 ( F_675 ( V_81 -> V_94 ) , V_15 ) ;
}
}
int F_559 ( int V_85 , int V_726 , int V_985 )
{
T_1 V_986 = V_85 * V_985 * 21 / 20 ;
return F_220 ( V_986 , V_726 * 8 ) ;
}
static bool F_676 ( struct V_45 * V_45 , int V_987 )
{
return F_29 ( V_45 ) < V_987 * V_45 -> V_51 ;
}
static void F_677 ( struct V_81 * V_81 ,
struct V_37 * V_60 ,
struct V_45 * V_805 )
{
struct V_145 * V_65 = & V_81 -> V_64 ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_45 , V_806 , V_807 ;
int V_987 ;
V_987 = 21 ;
if ( F_38 ( V_60 , V_66 ) ) {
if ( ( F_596 ( V_6 ) &&
V_6 -> V_802 . V_911 == 100000 ) ||
( F_120 ( V_6 ) && F_39 ( V_63 ) ) )
V_987 = 25 ;
} else if ( V_60 -> V_871 )
V_987 = 20 ;
V_806 = F_598 ( & V_60 -> V_45 ) ;
if ( F_676 ( & V_60 -> V_45 , V_987 ) )
V_806 |= V_988 ;
if ( V_805 ) {
V_807 = F_598 ( V_805 ) ;
if ( V_805 -> V_46 < V_987 * V_805 -> V_51 )
V_807 |= V_988 ;
} else {
V_807 = V_806 ;
}
V_45 = 0 ;
if ( F_38 ( V_60 , V_66 ) )
V_45 |= V_859 ;
else
V_45 |= V_860 ;
V_45 |= ( V_60 -> V_590 - 1 )
<< V_989 ;
if ( F_38 ( V_60 , V_214 ) ||
F_38 ( V_60 , V_209 ) )
V_45 |= V_862 ;
if ( F_388 ( V_60 ) )
V_45 |= V_862 ;
if ( F_184 ( V_6 ) -> V_724 == 3 &&
F_38 ( V_60 , V_615 ) )
V_45 |= V_862 ;
V_45 |= ( 1 << ( V_60 -> V_45 . V_49 - 1 ) ) << V_864 ;
V_45 |= ( 1 << ( V_60 -> V_45 . V_49 - 1 ) ) << V_865 ;
switch ( V_60 -> V_45 . V_50 ) {
case 5 :
V_45 |= V_866 ;
break;
case 7 :
V_45 |= V_867 ;
break;
case 10 :
V_45 |= V_868 ;
break;
case 14 :
V_45 |= V_869 ;
break;
}
if ( F_38 ( V_60 , V_66 ) &&
F_596 ( V_6 ) )
V_45 |= V_873 ;
else
V_45 |= V_874 ;
V_45 |= V_103 ;
V_60 -> V_174 . V_45 = V_45 ;
V_60 -> V_174 . V_712 = V_806 ;
V_60 -> V_174 . V_713 = V_807 ;
}
static int F_678 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_45 V_805 ;
bool V_990 = false ;
struct V_991 * V_992 ;
const struct V_56 * V_57 ;
int V_44 = 120000 ;
memset ( & V_60 -> V_174 , 0 ,
sizeof( V_60 -> V_174 ) ) ;
V_65 -> V_808 = false ;
if ( ! V_60 -> V_222 )
return 0 ;
if ( F_38 ( V_60 , V_66 ) ) {
if ( F_596 ( V_6 ) ) {
F_161 ( L_129 ,
V_6 -> V_802 . V_911 ) ;
V_44 = V_6 -> V_802 . V_911 ;
}
if ( F_39 ( V_63 ) ) {
if ( V_44 == 100000 )
V_57 = & V_993 ;
else
V_57 = & V_994 ;
} else {
if ( V_44 == 100000 )
V_57 = & V_995 ;
else
V_57 = & V_996 ;
}
} else {
V_57 = & V_997 ;
}
if ( ! V_60 -> V_915 &&
! F_43 ( V_57 , V_60 , V_60 -> V_39 ,
V_44 , NULL , & V_60 -> V_45 ) ) {
F_127 ( L_130 ) ;
return - V_288 ;
}
F_677 ( V_65 , V_60 ,
V_990 ? & V_805 : NULL ) ;
V_992 = F_679 ( V_65 , V_60 , NULL ) ;
if ( V_992 == NULL ) {
F_20 ( L_142 ,
F_78 ( V_65 -> V_94 ) ) ;
return - V_288 ;
}
if ( F_38 ( V_60 , V_66 ) &&
V_990 )
V_65 -> V_808 = true ;
return 0 ;
}
static void F_680 ( struct V_81 * V_65 ,
struct V_794 * V_795 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
V_795 -> V_799 = F_11 ( F_606 ( V_94 ) ) ;
V_795 -> V_800 = F_11 ( F_607 ( V_94 ) ) ;
V_795 -> V_797 = F_11 ( F_603 ( V_94 ) )
& ~ V_515 ;
V_795 -> V_798 = F_11 ( F_605 ( V_94 ) ) ;
V_795 -> V_796 = ( ( F_11 ( F_603 ( V_94 ) )
& V_515 ) >> V_998 ) + 1 ;
}
static void F_681 ( struct V_81 * V_65 ,
enum V_93 V_93 ,
struct V_794 * V_795 ,
struct V_794 * V_811 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
enum V_94 V_94 = V_65 -> V_94 ;
if ( F_59 ( V_6 ) >= 5 ) {
V_795 -> V_799 = F_11 ( F_609 ( V_93 ) ) ;
V_795 -> V_800 = F_11 ( F_610 ( V_93 ) ) ;
V_795 -> V_797 = F_11 ( F_383 ( V_93 ) )
& ~ V_515 ;
V_795 -> V_798 = F_11 ( F_608 ( V_93 ) ) ;
V_795 -> V_796 = ( ( F_11 ( F_383 ( V_93 ) )
& V_515 ) >> V_998 ) + 1 ;
if ( V_811 && F_59 ( V_6 ) < 8 &&
V_65 -> V_90 -> V_812 ) {
V_811 -> V_799 = F_11 ( F_613 ( V_93 ) ) ;
V_811 -> V_800 = F_11 ( F_614 ( V_93 ) ) ;
V_811 -> V_797 = F_11 ( F_611 ( V_93 ) )
& ~ V_515 ;
V_811 -> V_798 = F_11 ( F_612 ( V_93 ) ) ;
V_811 -> V_796 = ( ( F_11 ( F_611 ( V_93 ) )
& V_515 ) >> V_998 ) + 1 ;
}
} else {
V_795 -> V_799 = F_11 ( F_617 ( V_94 ) ) ;
V_795 -> V_800 = F_11 ( F_618 ( V_94 ) ) ;
V_795 -> V_797 = F_11 ( F_615 ( V_94 ) )
& ~ V_515 ;
V_795 -> V_798 = F_11 ( F_616 ( V_94 ) ) ;
V_795 -> V_796 = ( ( F_11 ( F_615 ( V_94 ) )
& V_515 ) >> V_998 ) + 1 ;
}
}
void F_682 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
if ( V_38 -> V_222 )
F_680 ( V_65 , & V_38 -> V_814 ) ;
else
F_681 ( V_65 , V_38 -> V_95 ,
& V_38 -> V_814 ,
& V_38 -> V_815 ) ;
}
static void F_683 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
F_681 ( V_65 , V_38 -> V_95 ,
& V_38 -> V_587 , NULL ) ;
}
static void F_684 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_380 * V_381 = & V_38 -> V_381 ;
T_2 V_415 = 0 ;
int V_379 = - 1 ;
int V_135 ;
for ( V_135 = 0 ; V_135 < V_65 -> V_382 ; V_135 ++ ) {
V_415 = F_11 ( F_269 ( V_65 -> V_94 , V_135 ) ) ;
if ( V_415 & V_416 && ! ( V_415 & V_999 ) ) {
V_379 = V_135 ;
V_38 -> V_443 . V_146 = true ;
V_38 -> V_443 . V_548 = F_11 ( F_270 ( V_65 -> V_94 , V_135 ) ) ;
V_38 -> V_443 . V_241 = F_11 ( F_271 ( V_65 -> V_94 , V_135 ) ) ;
break;
}
}
V_381 -> V_407 = V_379 ;
if ( V_379 >= 0 ) {
V_381 -> V_533 |= ( 1 << V_542 ) ;
} else {
V_381 -> V_533 &= ~ ( 1 << V_542 ) ;
}
}
static void
F_685 ( struct V_81 * V_65 ,
struct V_318 * V_319 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_15 , V_64 , V_276 , V_1000 , V_328 ;
int V_94 = V_65 -> V_94 ;
int V_928 , V_238 ;
unsigned int V_929 ;
struct V_245 * V_89 ;
struct V_267 * V_268 ;
V_268 = F_554 ( sizeof( * V_268 ) , V_721 ) ;
if ( ! V_268 ) {
F_161 ( L_131 ) ;
return;
}
V_89 = & V_268 -> V_64 ;
V_89 -> V_63 = V_63 ;
V_15 = F_11 ( F_94 ( V_94 , 0 ) ) ;
if ( ! ( V_15 & V_140 ) )
goto error;
V_238 = V_15 & V_1001 ;
V_928 = F_223 ( V_238 ,
V_15 & V_386 ,
V_15 & V_1002 ) ;
V_89 -> V_266 = F_657 ( V_928 ) ;
V_328 = V_15 & V_1003 ;
switch ( V_328 ) {
case V_1004 :
V_89 -> V_257 = V_230 ;
break;
case V_397 :
V_319 -> V_328 = V_282 ;
V_89 -> V_257 = V_231 ;
break;
case V_398 :
V_89 -> V_257 = V_232 ;
break;
case V_399 :
V_89 -> V_257 = V_233 ;
break;
default:
F_172 ( V_328 ) ;
goto error;
}
V_64 = F_11 ( F_284 ( V_94 , 0 ) ) & 0xfffff000 ;
V_319 -> V_64 = V_64 ;
V_276 = F_11 ( F_278 ( V_94 , 0 ) ) ;
V_15 = F_11 ( F_280 ( V_94 , 0 ) ) ;
V_89 -> V_237 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_89 -> V_242 = ( ( V_15 >> 0 ) & 0x1fff ) + 1 ;
V_15 = F_11 ( F_279 ( V_94 , 0 ) ) ;
V_1000 = F_267 ( V_6 , V_89 -> V_257 ,
V_89 -> V_266 -> V_266 ) ;
V_89 -> V_262 [ 0 ] = ( V_15 & 0x3ff ) * V_1000 ;
V_929 = F_175 ( V_63 , V_89 -> V_237 ,
V_89 -> V_266 -> V_266 ,
V_89 -> V_257 ) ;
V_319 -> V_241 = V_89 -> V_262 [ 0 ] * V_929 ;
F_161 ( L_143 ,
F_78 ( V_94 ) , V_89 -> V_242 , V_89 -> V_237 ,
V_89 -> V_266 -> V_229 [ 0 ] * 8 , V_64 , V_89 -> V_262 [ 0 ] ,
V_319 -> V_241 ) ;
V_319 -> V_89 = V_268 ;
return;
error:
F_236 ( V_268 ) ;
}
static void F_686 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_2 V_179 ;
V_179 = F_11 ( F_395 ( V_65 -> V_94 ) ) ;
if ( V_179 & V_549 ) {
V_38 -> V_443 . V_146 = true ;
V_38 -> V_443 . V_548 = F_11 ( F_397 ( V_65 -> V_94 ) ) ;
V_38 -> V_443 . V_241 = F_11 ( F_398 ( V_65 -> V_94 ) ) ;
if ( F_687 ( V_6 ) ) {
F_28 ( ( V_179 & V_1005 ) !=
F_396 ( V_65 -> V_94 ) ) ;
}
}
}
static void
F_688 ( struct V_81 * V_65 ,
struct V_318 * V_319 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_15 , V_64 , V_276 ;
int V_94 = V_65 -> V_94 ;
int V_928 , V_238 ;
unsigned int V_929 ;
struct V_245 * V_89 ;
struct V_267 * V_268 ;
V_15 = F_11 ( F_88 ( V_94 ) ) ;
if ( ! ( V_15 & V_134 ) )
return;
V_268 = F_554 ( sizeof( * V_268 ) , V_721 ) ;
if ( ! V_268 ) {
F_161 ( L_131 ) ;
return;
}
V_89 = & V_268 -> V_64 ;
V_89 -> V_63 = V_63 ;
if ( F_59 ( V_6 ) >= 4 ) {
if ( V_15 & V_369 ) {
V_319 -> V_328 = V_282 ;
V_89 -> V_257 = V_231 ;
}
}
V_238 = V_15 & V_930 ;
V_928 = F_222 ( V_238 ) ;
V_89 -> V_266 = F_657 ( V_928 ) ;
V_64 = F_11 ( F_258 ( V_94 ) ) & 0xfffff000 ;
if ( F_264 ( V_6 ) || F_265 ( V_6 ) ) {
V_276 = F_11 ( F_266 ( V_94 ) ) ;
} else {
if ( V_319 -> V_328 )
V_276 = F_11 ( F_259 ( V_94 ) ) ;
else
V_276 = F_11 ( F_260 ( V_94 ) ) ;
}
V_319 -> V_64 = V_64 ;
V_15 = F_11 ( F_321 ( V_94 ) ) ;
V_89 -> V_242 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_89 -> V_237 = ( ( V_15 >> 0 ) & 0xfff ) + 1 ;
V_15 = F_11 ( F_257 ( V_94 ) ) ;
V_89 -> V_262 [ 0 ] = V_15 & 0xffffffc0 ;
V_929 = F_175 ( V_63 , V_89 -> V_237 ,
V_89 -> V_266 -> V_266 ,
V_89 -> V_257 ) ;
V_319 -> V_241 = V_89 -> V_262 [ 0 ] * V_929 ;
F_161 ( L_143 ,
F_78 ( V_94 ) , V_89 -> V_242 , V_89 -> V_237 ,
V_89 -> V_266 -> V_229 [ 0 ] * 8 , V_64 , V_89 -> V_262 [ 0 ] ,
V_319 -> V_241 ) ;
V_319 -> V_89 = V_268 ;
}
static bool F_689 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_127 V_128 ;
T_2 V_179 ;
bool V_362 ;
V_128 = F_467 ( V_65 -> V_94 ) ;
if ( ! F_85 ( V_6 , V_128 ) )
return false ;
V_38 -> V_95 = (enum V_93 ) V_65 -> V_94 ;
V_38 -> V_206 = NULL ;
V_362 = false ;
V_179 = F_11 ( F_60 ( V_65 -> V_94 ) ) ;
if ( ! ( V_179 & V_132 ) )
goto V_936;
switch ( V_179 & V_208 ) {
case V_903 :
V_38 -> V_729 = 18 ;
break;
case V_210 :
V_38 -> V_729 = 24 ;
break;
case V_904 :
V_38 -> V_729 = 30 ;
break;
case V_978 :
V_38 -> V_729 = 36 ;
break;
default:
break;
}
if ( V_179 & V_910 )
V_38 -> V_909 = true ;
if ( F_11 ( F_104 ( V_65 -> V_94 ) ) & V_147 ) {
struct V_991 * V_992 ;
enum V_1006 V_1007 ;
V_38 -> V_222 = true ;
V_179 = F_11 ( F_72 ( V_65 -> V_94 ) ) ;
V_38 -> V_457 = ( ( V_456 & V_179 ) >>
V_1008 ) + 1 ;
F_683 ( V_65 , V_38 ) ;
if ( F_120 ( V_6 ) ) {
V_1007 = (enum V_1006 ) V_65 -> V_94 ;
} else {
V_179 = F_11 ( V_518 ) ;
if ( V_179 & F_385 ( V_65 -> V_94 ) )
V_1007 = V_519 ;
else
V_1007 = V_1009 ;
}
V_38 -> V_206 =
F_386 ( V_6 , V_1007 ) ;
V_992 = V_38 -> V_206 ;
F_28 ( ! V_992 -> V_1010 . V_719 ( V_6 , V_992 ,
& V_38 -> V_174 ) ) ;
V_179 = V_38 -> V_174 . V_45 ;
V_38 -> V_590 =
( ( V_179 & V_1011 )
>> V_989 ) + 1 ;
F_690 ( V_65 , V_38 ) ;
} else {
V_38 -> V_590 = 1 ;
}
F_641 ( V_65 , V_38 ) ;
F_642 ( V_65 , V_38 ) ;
F_686 ( V_65 , V_38 ) ;
V_362 = true ;
V_936:
F_86 ( V_6 , V_128 ) ;
return V_362 ;
}
static void F_691 ( struct V_5 * V_6 )
{
struct V_62 * V_63 = & V_6 -> V_260 ;
struct V_81 * V_65 ;
F_138 (dev, crtc)
F_65 ( V_65 -> V_87 , L_144 ,
F_78 ( V_65 -> V_94 ) ) ;
F_65 ( F_11 ( V_1012 ) , L_145 ) ;
F_65 ( F_11 ( V_1013 ) & V_1014 , L_146 ) ;
F_65 ( F_11 ( F_692 ( 0 ) ) & V_1015 , L_147 ) ;
F_65 ( F_11 ( F_692 ( 1 ) ) & V_1015 , L_148 ) ;
F_65 ( F_11 ( F_693 ( 0 ) ) & V_1016 , L_149 ) ;
F_65 ( F_11 ( V_1017 ) & V_1018 ,
L_150 ) ;
if ( F_264 ( V_6 ) )
F_65 ( F_11 ( V_1019 ) & V_1018 ,
L_151 ) ;
F_65 ( F_11 ( V_1020 ) & V_1021 ,
L_152 ) ;
F_65 ( F_11 ( V_1022 ) & V_1023 ,
L_153 ) ;
F_65 ( F_11 ( V_1024 ) & V_1025 , L_154 ) ;
F_65 ( F_694 ( V_6 ) , L_155 ) ;
}
static T_2 F_695 ( struct V_5 * V_6 )
{
if ( F_264 ( V_6 ) )
return F_11 ( V_1026 ) ;
else
return F_11 ( V_1027 ) ;
}
static void F_696 ( struct V_5 * V_6 , T_2 V_15 )
{
if ( F_264 ( V_6 ) ) {
F_3 ( & V_6 -> V_552 . V_553 ) ;
if ( F_401 ( V_6 , V_1028 ,
V_15 ) )
F_161 ( L_156 ) ;
F_5 ( & V_6 -> V_552 . V_553 ) ;
} else {
F_124 ( V_1027 , V_15 ) ;
F_125 ( V_1027 ) ;
}
}
static void F_697 ( struct V_5 * V_6 ,
bool V_1029 , bool V_1030 )
{
T_2 V_15 ;
F_691 ( V_6 ) ;
V_15 = F_11 ( V_736 ) ;
if ( V_1029 ) {
V_15 |= V_739 ;
F_124 ( V_736 , V_15 ) ;
if ( F_666 ( F_11 ( V_736 ) &
V_1031 , 1 ) )
F_127 ( L_157 ) ;
V_15 = F_11 ( V_736 ) ;
}
V_15 |= V_1032 ;
F_124 ( V_736 , V_15 ) ;
F_125 ( V_736 ) ;
if ( F_61 ( V_6 , V_736 , V_665 , 0 , 1 ) )
F_127 ( L_158 ) ;
V_15 = F_695 ( V_6 ) ;
V_15 |= V_1033 ;
F_696 ( V_6 , V_15 ) ;
F_698 ( 100 ) ;
if ( F_62 ( ( F_695 ( V_6 ) & V_1034 ) == 0 ,
1 ) )
F_127 ( L_159 ) ;
if ( V_1030 ) {
V_15 = F_11 ( V_736 ) ;
V_15 |= V_1035 ;
F_124 ( V_736 , V_15 ) ;
F_125 ( V_736 ) ;
}
}
static void F_699 ( struct V_5 * V_6 )
{
T_2 V_15 ;
V_15 = F_11 ( V_736 ) ;
if ( ( V_15 & ( V_665 | V_1032 | V_739 |
V_1035 ) ) == V_665 )
return;
F_700 ( V_6 , V_1036 ) ;
if ( V_15 & V_1035 ) {
V_15 &= ~ V_1035 ;
F_124 ( V_736 , V_15 ) ;
F_125 ( V_736 ) ;
}
V_15 = F_695 ( V_6 ) ;
V_15 |= V_1037 ;
V_15 &= ~ V_1033 ;
F_696 ( V_6 , V_15 ) ;
V_15 = F_11 ( V_736 ) ;
V_15 &= ~ V_1032 ;
F_124 ( V_736 , V_15 ) ;
if ( F_61 ( V_6 ,
V_736 , V_665 , V_665 ,
5 ) )
F_127 ( L_160 ) ;
if ( V_15 & V_739 ) {
V_15 = F_11 ( V_736 ) ;
V_15 &= ~ V_739 ;
F_124 ( V_736 , V_15 ) ;
if ( F_666 ( ( F_11 ( V_736 ) &
V_1031 ) == 0 , 1 ) )
F_127 ( L_161 ) ;
}
F_701 ( V_6 , V_1036 ) ;
F_483 ( V_6 ) ;
}
void F_702 ( struct V_5 * V_6 )
{
T_2 V_15 ;
F_161 ( L_162 ) ;
if ( F_669 ( V_6 ) ) {
V_15 = F_11 ( V_1038 ) ;
V_15 &= ~ V_1039 ;
F_124 ( V_1038 , V_15 ) ;
}
F_670 ( V_6 ) ;
F_697 ( V_6 , true , true ) ;
}
void F_703 ( struct V_5 * V_6 )
{
T_2 V_15 ;
F_161 ( L_163 ) ;
F_699 ( V_6 ) ;
F_673 ( V_6 ) ;
if ( F_669 ( V_6 ) ) {
V_15 = F_11 ( V_1038 ) ;
V_15 |= V_1039 ;
F_124 ( V_1038 , V_15 ) ;
}
}
static void F_704 ( struct V_421 * V_560 )
{
struct V_62 * V_63 = V_560 -> V_63 ;
struct V_569 * V_570 =
F_295 ( V_560 ) ;
unsigned int V_709 = V_570 -> V_701 ;
F_490 ( F_41 ( V_63 ) , V_709 ) ;
}
static int F_705 ( struct V_37 * V_60 ,
int V_1040 )
{
struct V_5 * V_6 = F_41 ( V_60 -> V_64 . V_65 -> V_63 ) ;
if ( F_265 ( V_6 ) && V_60 -> V_551 )
V_1040 = F_220 ( V_1040 * 100 , 95 ) ;
if ( F_388 ( V_60 ) &&
V_60 -> V_1041 &&
V_60 -> V_39 >= 540000 &&
V_60 -> V_1042 == 4 )
V_1040 = V_59 ( 432000 , V_1040 ) ;
return V_1040 ;
}
static int F_522 ( struct V_421 * V_43 )
{
struct V_569 * V_338 = F_295 ( V_43 ) ;
struct V_5 * V_6 = F_41 ( V_43 -> V_63 ) ;
struct V_145 * V_65 ;
struct V_42 * V_1043 ;
struct V_37 * V_60 ;
unsigned V_1044 = 0 , V_135 ;
enum V_94 V_94 ;
memcpy ( V_338 -> V_699 , V_6 -> V_699 ,
sizeof( V_338 -> V_699 ) ) ;
F_294 (state, crtc, cstate, i) {
int V_1040 ;
V_60 = F_290 ( V_1043 ) ;
if ( ! V_60 -> V_64 . V_507 ) {
V_338 -> V_699 [ V_135 ] = 0 ;
continue;
}
V_1040 = F_562 ( V_60 ) ;
if ( F_265 ( V_6 ) || F_706 ( V_6 ) )
V_1040 = F_705 ( V_60 ,
V_1040 ) ;
V_338 -> V_699 [ V_135 ] = V_1040 ;
}
F_91 (dev_priv, pipe)
V_1044 = V_59 ( V_338 -> V_699 [ V_94 ] , V_1044 ) ;
return V_1044 ;
}
static void F_707 ( struct V_62 * V_63 , int V_643 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_2 V_15 , V_1045 ;
int V_362 ;
if ( F_7 ( ( F_11 ( V_736 ) &
( V_1032 | V_665 |
V_1046 | V_1047 |
V_1048 | V_1035 |
V_739 ) ) != V_665 ,
L_164 ) )
return;
F_3 ( & V_6 -> V_552 . V_553 ) ;
V_362 = F_401 ( V_6 ,
V_1049 , 0x0 ) ;
F_5 ( & V_6 -> V_552 . V_553 ) ;
if ( V_362 ) {
F_127 ( L_165 ) ;
return;
}
V_15 = F_11 ( V_736 ) ;
V_15 |= V_739 ;
F_124 ( V_736 , V_15 ) ;
if ( F_666 ( F_11 ( V_736 ) &
V_1031 , 1 ) )
F_127 ( L_157 ) ;
V_15 = F_11 ( V_736 ) ;
V_15 &= ~ V_738 ;
switch ( V_643 ) {
case 450000 :
V_15 |= V_740 ;
V_1045 = 0 ;
break;
case 540000 :
V_15 |= V_741 ;
V_1045 = 1 ;
break;
case 337500 :
V_15 |= V_742 ;
V_1045 = 2 ;
break;
case 675000 :
V_15 |= V_1050 ;
V_1045 = 3 ;
break;
default:
F_7 ( 1 , L_166 ) ;
return;
}
F_124 ( V_736 , V_15 ) ;
V_15 = F_11 ( V_736 ) ;
V_15 &= ~ V_739 ;
F_124 ( V_736 , V_15 ) ;
if ( F_666 ( ( F_11 ( V_736 ) &
V_1031 ) == 0 , 1 ) )
F_127 ( L_161 ) ;
F_3 ( & V_6 -> V_552 . V_553 ) ;
F_401 ( V_6 , V_654 , V_1045 ) ;
F_5 ( & V_6 -> V_552 . V_553 ) ;
F_124 ( V_1051 , F_8 ( V_643 , 1000 ) - 1 ) ;
F_483 ( V_6 ) ;
F_7 ( V_643 != V_6 -> V_637 ,
L_167 ,
V_643 , V_6 -> V_637 ) ;
}
static int F_708 ( int V_662 )
{
if ( V_662 > 540000 )
return 675000 ;
else if ( V_662 > 450000 )
return 540000 ;
else if ( V_662 > 337500 )
return 450000 ;
else
return 337500 ;
}
static int F_709 ( struct V_421 * V_43 )
{
struct V_5 * V_6 = F_41 ( V_43 -> V_63 ) ;
struct V_569 * V_338 = F_295 ( V_43 ) ;
int V_662 = F_522 ( V_43 ) ;
int V_643 ;
V_643 = F_708 ( V_662 ) ;
if ( V_643 > V_6 -> V_627 ) {
F_161 ( L_168 ,
V_643 , V_6 -> V_627 ) ;
return - V_288 ;
}
V_338 -> V_643 = V_338 -> V_701 = V_643 ;
if ( ! V_338 -> V_702 )
V_338 -> V_701 = F_708 ( 0 ) ;
return 0 ;
}
static void F_710 ( struct V_421 * V_560 )
{
struct V_62 * V_63 = V_560 -> V_63 ;
struct V_569 * V_570 =
F_295 ( V_560 ) ;
unsigned V_709 = V_570 -> V_701 ;
F_707 ( V_63 , V_709 ) ;
}
static int F_711 ( struct V_421 * V_43 )
{
struct V_569 * V_338 = F_295 ( V_43 ) ;
struct V_5 * V_6 = F_41 ( V_43 -> V_63 ) ;
const int V_662 = F_522 ( V_43 ) ;
int V_52 = V_338 -> V_1052 ;
int V_643 ;
V_643 = F_479 ( V_662 , V_52 ) ;
if ( V_643 > V_6 -> V_627 ) {
F_127 ( L_168 ,
V_643 , V_6 -> V_627 ) ;
V_643 = V_6 -> V_627 ;
}
V_338 -> V_643 = V_338 -> V_701 = V_643 ;
if ( ! V_338 -> V_702 )
V_338 -> V_701 = F_479 ( 0 , V_52 ) ;
return 0 ;
}
static void F_712 ( struct V_421 * V_560 )
{
struct V_5 * V_6 = F_41 ( V_560 -> V_63 ) ;
struct V_569 * V_338 = F_295 ( V_560 ) ;
unsigned int V_709 = V_338 -> V_701 ;
unsigned int V_1053 = V_338 -> V_1052 ;
F_505 ( V_6 , V_709 , V_1053 ) ;
}
static int F_713 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
if ( ! F_38 ( V_60 , V_223 ) ) {
if ( ! F_714 ( V_65 , V_60 ) )
return - V_288 ;
}
V_65 -> V_808 = false ;
return 0 ;
}
static void F_715 ( struct V_5 * V_6 ,
enum V_178 V_178 ,
struct V_37 * V_38 )
{
enum V_1006 V_379 ;
switch ( V_178 ) {
case V_601 :
V_379 = V_1054 ;
break;
case V_198 :
V_379 = V_1055 ;
break;
case V_200 :
V_379 = V_1056 ;
break;
default:
F_127 ( L_169 ) ;
return;
}
V_38 -> V_206 = F_386 ( V_6 , V_379 ) ;
}
static void F_716 ( struct V_5 * V_6 ,
enum V_178 V_178 ,
struct V_37 * V_38 )
{
enum V_1006 V_379 ;
T_1 V_444 ;
V_444 = F_11 ( V_1057 ) & F_717 ( V_178 ) ;
V_379 = V_444 >> ( V_178 * 3 + 1 ) ;
if ( F_28 ( V_379 < V_667 || V_379 > V_1058 ) )
return;
V_38 -> V_206 = F_386 ( V_6 , V_379 ) ;
}
static void F_718 ( struct V_5 * V_6 ,
enum V_178 V_178 ,
struct V_37 * V_38 )
{
enum V_1006 V_379 ;
T_2 V_1059 = F_11 ( F_719 ( V_178 ) ) ;
switch ( V_1059 ) {
case V_1060 :
V_379 = V_1061 ;
break;
case V_1062 :
V_379 = V_1063 ;
break;
case V_1064 :
V_379 = V_1065 ;
break;
case V_1066 :
V_379 = V_1067 ;
break;
case V_1068 :
V_379 = V_1069 ;
break;
case V_1070 :
V_379 = V_1071 ;
break;
default:
F_172 ( V_1059 ) ;
case V_1072 :
return;
}
V_38 -> V_206 = F_386 ( V_6 , V_379 ) ;
}
static bool F_720 ( struct V_81 * V_65 ,
struct V_37 * V_38 ,
unsigned long * V_1073 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_127 V_128 ;
T_1 V_179 ;
V_38 -> V_95 = (enum V_93 ) V_65 -> V_94 ;
V_179 = F_11 ( F_69 ( V_589 ) ) ;
if ( V_179 & V_106 ) {
enum V_94 V_1074 ;
switch ( V_179 & V_1075 ) {
default:
F_7 ( 1 , L_170 ) ;
case V_1076 :
case V_1077 :
V_1074 = V_113 ;
break;
case V_1078 :
V_1074 = V_120 ;
break;
case V_1079 :
V_1074 = V_510 ;
break;
}
if ( V_1074 == V_65 -> V_94 )
V_38 -> V_95 = V_589 ;
}
V_128 = F_84 ( V_38 -> V_95 ) ;
if ( ! F_85 ( V_6 , V_128 ) )
return false ;
* V_1073 |= F_466 ( V_128 ) ;
V_179 = F_11 ( F_60 ( V_38 -> V_95 ) ) ;
return V_179 & V_132 ;
}
static bool F_721 ( struct V_81 * V_65 ,
struct V_37 * V_38 ,
unsigned long * V_1073 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_127 V_128 ;
enum V_178 V_178 ;
enum V_93 V_95 ;
T_1 V_179 ;
F_722 (port, BIT(PORT_A) | BIT(PORT_C)) {
if ( V_178 == V_601 )
V_95 = V_1080 ;
else
V_95 = V_1081 ;
V_128 = F_84 ( V_95 ) ;
if ( ! F_85 ( V_6 , V_128 ) )
continue;
* V_1073 |= F_466 ( V_128 ) ;
if ( ! F_723 ( V_6 ) )
break;
V_179 = F_11 ( F_724 ( V_178 ) ) ;
if ( ! ( V_179 & V_1082 ) )
continue;
V_179 = F_11 ( F_725 ( V_178 ) ) ;
if ( ( V_179 & V_1083 ) != F_726 ( V_65 -> V_94 ) )
continue;
V_38 -> V_95 = V_95 ;
break;
}
return F_444 ( V_38 -> V_95 ) ;
}
static void F_727 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
struct V_991 * V_992 ;
enum V_178 V_178 ;
T_2 V_179 ;
V_179 = F_11 ( F_69 ( V_38 -> V_95 ) ) ;
V_178 = ( V_179 & V_1084 ) >> V_1085 ;
if ( F_477 ( V_6 ) || F_478 ( V_6 ) )
F_716 ( V_6 , V_178 , V_38 ) ;
else if ( F_36 ( V_6 ) )
F_715 ( V_6 , V_178 , V_38 ) ;
else
F_718 ( V_6 , V_178 , V_38 ) ;
V_992 = V_38 -> V_206 ;
if ( V_992 ) {
F_28 ( ! V_992 -> V_1010 . V_719 ( V_6 , V_992 ,
& V_38 -> V_174 ) ) ;
}
if ( F_59 ( V_6 ) < 9 &&
( V_178 == V_606 ) && F_11 ( V_221 ) & V_147 ) {
V_38 -> V_222 = true ;
V_179 = F_11 ( F_72 ( V_113 ) ) ;
V_38 -> V_457 = ( ( V_456 & V_179 ) >>
V_1008 ) + 1 ;
F_683 ( V_65 , V_38 ) ;
}
}
static bool F_728 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
enum V_127 V_128 ;
unsigned long V_1073 ;
bool V_87 ;
V_128 = F_467 ( V_65 -> V_94 ) ;
if ( ! F_85 ( V_6 , V_128 ) )
return false ;
V_1073 = F_466 ( V_128 ) ;
V_38 -> V_206 = NULL ;
V_87 = F_720 ( V_65 , V_38 , & V_1073 ) ;
if ( F_36 ( V_6 ) &&
F_721 ( V_65 , V_38 , & V_1073 ) ) {
F_28 ( V_87 ) ;
V_87 = true ;
}
if ( ! V_87 )
goto V_936;
if ( ! F_444 ( V_38 -> V_95 ) ) {
F_727 ( V_65 , V_38 ) ;
F_641 ( V_65 , V_38 ) ;
}
F_642 ( V_65 , V_38 ) ;
V_38 -> V_1086 =
F_11 ( F_729 ( V_65 -> V_94 ) ) & V_1087 ;
if ( F_59 ( V_6 ) >= 9 ) {
F_730 ( V_65 , V_38 ) ;
V_38 -> V_381 . V_407 = - 1 ;
V_38 -> V_381 . V_533 &= ~ ( 1 << V_542 ) ;
}
V_128 = F_468 ( V_65 -> V_94 ) ;
if ( F_85 ( V_6 , V_128 ) ) {
V_1073 |= F_466 ( V_128 ) ;
if ( F_59 ( V_6 ) >= 9 )
F_684 ( V_65 , V_38 ) ;
else
F_686 ( V_65 , V_38 ) ;
}
if ( F_264 ( V_6 ) )
V_38 -> V_551 = F_441 ( V_65 ) &&
( F_11 ( V_555 ) & V_556 ) ;
if ( V_38 -> V_95 != V_589 &&
! F_444 ( V_38 -> V_95 ) ) {
V_38 -> V_590 =
F_11 ( F_445 ( V_38 -> V_95 ) ) + 1 ;
} else {
V_38 -> V_590 = 1 ;
}
V_936:
F_471 (power_domain, power_domain_mask)
F_86 ( V_6 , V_128 ) ;
return V_87 ;
}
static void F_731 ( struct V_145 * V_65 , T_1 V_64 ,
const struct V_265 * V_336 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
T_2 V_1088 = 0 , V_241 = 0 ;
if ( V_336 && V_336 -> V_64 . V_340 ) {
unsigned int V_242 = V_336 -> V_64 . V_349 ;
unsigned int V_237 = V_336 -> V_64 . V_350 ;
unsigned int V_292 = F_732 ( V_242 ) * 4 ;
switch ( V_292 ) {
default:
F_351 ( 1 , L_171 ,
V_242 , V_292 ) ;
V_292 = 256 ;
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
}
V_1088 |= V_125 |
V_1089 |
V_1090 |
F_733 ( V_292 ) ;
V_241 = ( V_237 << 12 ) | V_242 ;
}
if ( V_81 -> V_1091 != 0 &&
( V_81 -> V_1092 != V_64 ||
V_81 -> V_1093 != V_241 ||
V_81 -> V_1091 != V_1088 ) ) {
F_124 ( F_82 ( V_113 ) , 0 ) ;
F_125 ( F_82 ( V_113 ) ) ;
V_81 -> V_1091 = 0 ;
}
if ( V_81 -> V_1092 != V_64 ) {
F_124 ( F_734 ( V_113 ) , V_64 ) ;
V_81 -> V_1092 = V_64 ;
}
if ( V_81 -> V_1093 != V_241 ) {
F_124 ( V_1094 , V_241 ) ;
V_81 -> V_1093 = V_241 ;
}
if ( V_81 -> V_1091 != V_1088 ) {
F_124 ( F_82 ( V_113 ) , V_1088 ) ;
F_125 ( F_82 ( V_113 ) ) ;
V_81 -> V_1091 = V_1088 ;
}
}
static void F_735 ( struct V_145 * V_65 , T_1 V_64 ,
const struct V_265 * V_336 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_2 V_1088 = 0 ;
if ( V_336 && V_336 -> V_64 . V_340 ) {
V_1088 = V_1095 ;
switch ( V_336 -> V_64 . V_349 ) {
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
F_172 ( V_336 -> V_64 . V_349 ) ;
return;
}
V_1088 |= V_94 << 28 ;
if ( F_23 ( V_6 ) )
V_1088 |= V_1099 ;
if ( V_336 -> V_64 . V_246 & V_370 )
V_1088 |= V_1100 ;
}
if ( V_81 -> V_1091 != V_1088 ) {
F_124 ( F_82 ( V_94 ) , V_1088 ) ;
F_125 ( F_82 ( V_94 ) ) ;
V_81 -> V_1091 = V_1088 ;
}
F_124 ( F_734 ( V_94 ) , V_64 ) ;
F_125 ( F_734 ( V_94 ) ) ;
V_81 -> V_1092 = V_64 ;
}
static void F_736 ( struct V_145 * V_65 ,
const struct V_265 * V_336 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
int V_94 = V_81 -> V_94 ;
T_1 V_64 = V_81 -> V_1101 ;
T_1 V_548 = 0 ;
if ( V_336 ) {
int V_263 = V_336 -> V_64 . V_347 ;
int V_264 = V_336 -> V_64 . V_348 ;
if ( V_263 < 0 ) {
V_548 |= V_1102 << V_1103 ;
V_263 = - V_263 ;
}
V_548 |= V_263 << V_1103 ;
if ( V_264 < 0 ) {
V_548 |= V_1102 << V_1104 ;
V_264 = - V_264 ;
}
V_548 |= V_264 << V_1104 ;
if ( F_163 ( V_6 ) &&
V_336 -> V_64 . V_246 & V_370 ) {
V_64 += ( V_336 -> V_64 . V_350 *
V_336 -> V_64 . V_349 - 1 ) * 4 ;
}
}
F_124 ( F_737 ( V_94 ) , V_548 ) ;
if ( F_80 ( V_6 ) || F_81 ( V_6 ) )
F_731 ( V_65 , V_64 , V_336 ) ;
else
F_735 ( V_65 , V_64 , V_336 ) ;
}
static bool F_738 ( struct V_5 * V_6 ,
T_2 V_242 , T_2 V_237 )
{
if ( V_242 == 0 || V_237 == 0 )
return false ;
if ( F_80 ( V_6 ) || F_81 ( V_6 ) ) {
if ( ( V_242 & 63 ) != 0 )
return false ;
if ( V_242 > ( F_80 ( V_6 ) ? 64 : 512 ) )
return false ;
if ( V_237 > 1023 )
return false ;
} else {
switch ( V_242 | V_237 ) {
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
struct V_245 *
F_739 ( struct V_62 * V_63 ,
struct V_322 * V_323 ,
struct V_252 * V_253 )
{
struct V_267 * V_268 ;
int V_362 ;
V_268 = F_554 ( sizeof( * V_268 ) , V_721 ) ;
if ( ! V_268 )
return F_740 ( - V_720 ) ;
V_362 = F_228 ( V_63 , V_268 , V_323 , V_253 ) ;
if ( V_362 )
goto V_72;
return & V_268 -> V_64 ;
V_72:
F_236 ( V_268 ) ;
return F_740 ( V_362 ) ;
}
static struct V_245 *
F_741 ( struct V_62 * V_63 ,
struct V_322 * V_323 ,
struct V_252 * V_253 )
{
struct V_245 * V_89 ;
int V_362 ;
V_362 = F_742 ( V_63 ) ;
if ( V_362 )
return F_740 ( V_362 ) ;
V_89 = F_739 ( V_63 , V_323 , V_253 ) ;
F_5 ( & V_63 -> V_256 ) ;
return V_89 ;
}
static T_1
F_743 ( int V_242 , int V_985 )
{
T_1 V_261 = F_220 ( V_242 * V_985 , 8 ) ;
return F_177 ( V_261 , 64 ) ;
}
static T_1
F_744 ( struct V_520 * V_417 , int V_985 )
{
T_1 V_261 = F_743 ( V_417 -> V_889 , V_985 ) ;
return F_745 ( V_261 * V_417 -> V_888 ) ;
}
static struct V_245 *
F_746 ( struct V_62 * V_63 ,
struct V_520 * V_417 ,
int V_1105 , int V_985 )
{
struct V_245 * V_89 ;
struct V_252 * V_253 ;
struct V_322 V_323 = { 0 } ;
V_253 = F_747 ( F_41 ( V_63 ) ,
F_744 ( V_417 , V_985 ) ) ;
if ( F_194 ( V_253 ) )
return F_748 ( V_253 ) ;
V_323 . V_242 = V_417 -> V_889 ;
V_323 . V_237 = V_417 -> V_888 ;
V_323 . V_262 [ 0 ] = F_743 ( V_323 . V_242 ,
V_985 ) ;
V_323 . V_238 = F_749 ( V_985 , V_1105 ) ;
V_89 = F_741 ( V_63 , & V_323 , V_253 ) ;
if ( F_194 ( V_89 ) )
F_229 ( V_253 ) ;
return V_89 ;
}
static struct V_245 *
F_750 ( struct V_62 * V_63 ,
struct V_520 * V_417 )
{
#ifdef F_751
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_252 * V_253 ;
struct V_245 * V_89 ;
if ( ! V_6 -> V_1106 )
return NULL ;
if ( ! V_6 -> V_1106 -> V_89 )
return NULL ;
V_253 = V_6 -> V_1106 -> V_89 -> V_253 ;
F_664 ( ! V_253 ) ;
V_89 = & V_6 -> V_1106 -> V_89 -> V_64 ;
if ( V_89 -> V_262 [ 0 ] < F_743 ( V_417 -> V_889 ,
V_89 -> V_266 -> V_229 [ 0 ] * 8 ) )
return NULL ;
if ( V_253 -> V_64 . V_241 < V_417 -> V_888 * V_89 -> V_262 [ 0 ] )
return NULL ;
F_232 ( V_89 ) ;
return V_89 ;
#else
return NULL ;
#endif
}
static int F_752 ( struct V_421 * V_43 ,
struct V_145 * V_65 ,
struct V_520 * V_417 ,
struct V_245 * V_89 ,
int V_263 , int V_264 )
{
struct V_335 * V_336 ;
int V_889 , V_888 ;
int V_362 ;
V_336 = F_753 ( V_43 , V_65 -> V_88 ) ;
if ( F_194 ( V_336 ) )
return F_241 ( V_336 ) ;
if ( V_417 )
F_754 ( V_417 , & V_889 , & V_888 ) ;
else
V_889 = V_888 = 0 ;
V_362 = F_755 ( V_336 , V_89 ? V_65 : NULL ) ;
if ( V_362 )
return V_362 ;
F_756 ( V_336 , V_89 ) ;
V_336 -> V_347 = 0 ;
V_336 -> V_348 = 0 ;
V_336 -> V_349 = V_889 ;
V_336 -> V_350 = V_888 ;
V_336 -> V_343 = V_263 << 16 ;
V_336 -> V_344 = V_264 << 16 ;
V_336 -> V_345 = V_889 << 16 ;
V_336 -> V_346 = V_888 << 16 ;
return 0 ;
}
bool F_757 ( struct V_577 * V_718 ,
struct V_520 * V_417 ,
struct V_1107 * V_1108 ,
struct V_425 * V_426 )
{
struct V_81 * V_81 ;
struct V_511 * V_511 =
F_758 ( V_718 ) ;
struct V_145 * V_1109 ;
struct V_618 * V_512 = & V_511 -> V_64 ;
struct V_145 * V_65 = NULL ;
struct V_62 * V_63 = V_512 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_245 * V_89 ;
struct V_1110 * V_90 = & V_63 -> V_428 ;
struct V_421 * V_43 = NULL , * V_1111 = NULL ;
struct V_575 * V_1112 ;
struct V_37 * V_60 ;
int V_362 , V_135 = - 1 ;
F_161 ( L_172 ,
V_718 -> V_64 . V_379 , V_718 -> V_12 ,
V_512 -> V_64 . V_379 , V_512 -> V_12 ) ;
V_1108 -> V_1111 = NULL ;
V_462:
V_362 = F_759 ( & V_90 -> V_1113 , V_426 ) ;
if ( V_362 )
goto V_783;
if ( V_718 -> V_43 -> V_65 ) {
V_65 = V_718 -> V_43 -> V_65 ;
V_362 = F_759 ( & V_65 -> V_429 , V_426 ) ;
if ( V_362 )
goto V_783;
goto V_75;
}
F_237 (dev, possible_crtc) {
V_135 ++ ;
if ( ! ( V_512 -> V_1114 & ( 1 << V_135 ) ) )
continue;
V_362 = F_759 ( & V_1109 -> V_429 , V_426 ) ;
if ( V_362 )
goto V_783;
if ( V_1109 -> V_43 -> V_507 ) {
F_760 ( & V_1109 -> V_429 ) ;
continue;
}
V_65 = V_1109 ;
break;
}
if ( ! V_65 ) {
F_161 ( L_173 ) ;
goto V_783;
}
V_75:
V_81 = F_48 ( V_65 ) ;
V_362 = F_759 ( & V_65 -> V_88 -> V_429 , V_426 ) ;
if ( V_362 )
goto V_783;
V_43 = F_539 ( V_63 ) ;
V_1111 = F_539 ( V_63 ) ;
if ( ! V_43 || ! V_1111 ) {
V_362 = - V_720 ;
goto V_783;
}
V_43 -> V_432 = V_426 ;
V_1111 -> V_432 = V_426 ;
V_1112 = F_761 ( V_43 , V_718 ) ;
if ( F_194 ( V_1112 ) ) {
V_362 = F_241 ( V_1112 ) ;
goto V_783;
}
V_362 = F_762 ( V_1112 , V_65 ) ;
if ( V_362 )
goto V_783;
V_60 = F_540 ( V_43 , V_81 ) ;
if ( F_194 ( V_60 ) ) {
V_362 = F_241 ( V_60 ) ;
goto V_783;
}
V_60 -> V_64 . V_87 = V_60 -> V_64 . V_507 = true ;
if ( ! V_417 )
V_417 = & V_1115 ;
V_89 = F_750 ( V_63 , V_417 ) ;
if ( V_89 == NULL ) {
F_161 ( L_174 ) ;
V_89 = F_746 ( V_63 , V_417 , 24 , 32 ) ;
} else
F_161 ( L_175 ) ;
if ( F_194 ( V_89 ) ) {
F_161 ( L_176 ) ;
goto V_783;
}
V_362 = F_752 ( V_43 , V_65 , V_417 , V_89 , 0 , 0 ) ;
if ( V_362 )
goto V_783;
F_231 ( V_89 ) ;
V_362 = F_542 ( & V_60 -> V_64 , V_417 ) ;
if ( V_362 )
goto V_783;
V_362 = F_547 ( F_761 ( V_1111 , V_718 ) ) ;
if ( ! V_362 )
V_362 = F_547 ( F_763 ( V_1111 , V_65 ) ) ;
if ( ! V_362 )
V_362 = F_547 ( F_753 ( V_1111 , V_65 -> V_88 ) ) ;
if ( V_362 ) {
F_161 ( L_177 , V_362 ) ;
goto V_783;
}
V_362 = F_296 ( V_43 ) ;
if ( V_362 ) {
F_161 ( L_178 ) ;
goto V_783;
}
V_1108 -> V_1111 = V_1111 ;
F_305 ( V_43 ) ;
F_342 ( V_6 , V_81 -> V_94 ) ;
return true ;
V_783:
if ( V_43 ) {
F_305 ( V_43 ) ;
V_43 = NULL ;
}
if ( V_1111 ) {
F_305 ( V_1111 ) ;
V_1111 = NULL ;
}
if ( V_362 == - V_424 ) {
F_302 ( V_426 ) ;
goto V_462;
}
return false ;
}
void F_764 ( struct V_577 * V_718 ,
struct V_1107 * V_1108 ,
struct V_425 * V_426 )
{
struct V_511 * V_511 =
F_758 ( V_718 ) ;
struct V_618 * V_512 = & V_511 -> V_64 ;
struct V_421 * V_43 = V_1108 -> V_1111 ;
int V_362 ;
F_161 ( L_172 ,
V_718 -> V_64 . V_379 , V_718 -> V_12 ,
V_512 -> V_64 . V_379 , V_512 -> V_12 ) ;
if ( ! V_43 )
return;
V_362 = F_296 ( V_43 ) ;
if ( V_362 )
F_161 ( L_179 , V_362 ) ;
F_305 ( V_43 ) ;
}
static int F_765 ( struct V_62 * V_63 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
T_1 V_45 = V_38 -> V_174 . V_45 ;
if ( ( V_45 & V_948 ) == V_873 )
return V_6 -> V_802 . V_911 ;
else if ( F_15 ( V_6 ) )
return 120000 ;
else if ( ! F_56 ( V_6 ) )
return 96000 ;
else
return 48000 ;
}
static void F_660 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_94 = V_38 -> V_95 ;
T_1 V_45 = V_38 -> V_174 . V_45 ;
T_1 V_806 ;
struct V_45 clock ;
int V_39 ;
int V_44 = F_765 ( V_63 , V_38 ) ;
if ( ( V_45 & V_1116 ) == 0 )
V_806 = V_38 -> V_174 . V_712 ;
else
V_806 = V_38 -> V_174 . V_713 ;
clock . V_54 = ( V_806 & V_1117 ) >> V_1118 ;
if ( F_19 ( V_6 ) ) {
clock . V_51 = F_766 ( ( V_806 & V_1119 ) >> V_1120 ) - 1 ;
clock . V_47 = ( V_806 & V_1121 ) >> V_1122 ;
} else {
clock . V_51 = ( V_806 & V_1123 ) >> V_1120 ;
clock . V_47 = ( V_806 & V_1124 ) >> V_1122 ;
}
if ( ! F_56 ( V_6 ) ) {
if ( F_19 ( V_6 ) )
clock . V_49 = F_766 ( ( V_45 & V_1125 ) >>
V_863 ) ;
else
clock . V_49 = F_766 ( ( V_45 & V_1126 ) >>
V_864 ) ;
switch ( V_45 & V_1127 ) {
case V_860 :
clock . V_50 = V_45 & V_866 ?
5 : 10 ;
break;
case V_859 :
clock . V_50 = V_45 & V_867 ?
7 : 14 ;
break;
default:
F_161 ( L_180
L_181 , ( int ) ( V_45 & V_1127 ) ) ;
return;
}
if ( F_19 ( V_6 ) )
V_39 = F_27 ( V_44 , & clock ) ;
else
V_39 = F_30 ( V_44 , & clock ) ;
} else {
T_1 V_1128 = F_141 ( V_6 ) ? 0 : F_11 ( V_121 ) ;
bool V_1129 = ( V_94 == 1 ) && ( V_1128 & V_157 ) ;
if ( V_1129 ) {
clock . V_49 = F_766 ( ( V_45 & V_1130 ) >>
V_864 ) ;
if ( V_1128 & V_1131 )
clock . V_50 = 7 ;
else
clock . V_50 = 14 ;
} else {
if ( V_45 & V_875 )
clock . V_49 = 2 ;
else {
clock . V_49 = ( ( V_45 & V_1132 ) >>
V_864 ) + 2 ;
}
if ( V_45 & V_876 )
clock . V_50 = 4 ;
else
clock . V_50 = 2 ;
}
V_39 = F_30 ( V_44 , & clock ) ;
}
V_38 -> V_39 = V_39 ;
}
int F_767 ( int V_1133 ,
const struct V_794 * V_795 )
{
if ( ! V_795 -> V_800 )
return 0 ;
return F_46 ( ( V_1134 ) V_795 -> V_799 * V_1133 , V_795 -> V_800 ) ;
}
static void F_690 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
F_660 ( V_65 , V_38 ) ;
V_38 -> V_64 . V_91 . V_92 =
F_767 ( F_22 ( V_6 , V_38 ) ,
& V_38 -> V_587 ) ;
}
struct V_520 * F_768 ( struct V_62 * V_63 ,
struct V_145 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
enum V_93 V_95 = V_81 -> V_90 -> V_95 ;
struct V_520 * V_417 ;
struct V_37 * V_38 ;
int V_1135 = F_11 ( F_363 ( V_95 ) ) ;
int V_897 = F_11 ( F_367 ( V_95 ) ) ;
int V_1136 = F_11 ( F_369 ( V_95 ) ) ;
int V_1137 = F_11 ( F_373 ( V_95 ) ) ;
enum V_94 V_94 = V_81 -> V_94 ;
V_417 = F_554 ( sizeof( * V_417 ) , V_721 ) ;
if ( ! V_417 )
return NULL ;
V_38 = F_554 ( sizeof( * V_38 ) , V_721 ) ;
if ( ! V_38 ) {
F_236 ( V_417 ) ;
return NULL ;
}
V_38 -> V_95 = (enum V_93 ) V_94 ;
V_38 -> V_590 = 1 ;
V_38 -> V_174 . V_45 = F_11 ( F_64 ( V_94 ) ) ;
V_38 -> V_174 . V_712 = F_11 ( F_533 ( V_94 ) ) ;
V_38 -> V_174 . V_713 = F_11 ( F_534 ( V_94 ) ) ;
F_660 ( V_81 , V_38 ) ;
V_417 -> clock = V_38 -> V_39 / V_38 -> V_590 ;
V_417 -> V_889 = ( V_1135 & 0xffff ) + 1 ;
V_417 -> V_890 = ( ( V_1135 & 0xffff0000 ) >> 16 ) + 1 ;
V_417 -> V_891 = ( V_897 & 0xffff ) + 1 ;
V_417 -> V_892 = ( ( V_897 & 0xffff0000 ) >> 16 ) + 1 ;
V_417 -> V_888 = ( V_1136 & 0xffff ) + 1 ;
V_417 -> V_893 = ( ( V_1136 & 0xffff0000 ) >> 16 ) + 1 ;
V_417 -> V_894 = ( V_1137 & 0xffff ) + 1 ;
V_417 -> V_895 = ( ( V_1137 & 0xffff0000 ) >> 16 ) + 1 ;
F_646 ( V_417 ) ;
F_236 ( V_38 ) ;
return V_417 ;
}
static void F_769 ( struct V_145 * V_65 )
{
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_1 * V_2 ;
F_311 ( & V_63 -> V_440 ) ;
V_2 = V_81 -> V_441 ;
V_81 -> V_441 = NULL ;
F_312 ( & V_63 -> V_440 ) ;
if ( V_2 ) {
F_770 ( & V_2 -> V_3 ) ;
F_770 ( & V_2 -> V_482 ) ;
F_236 ( V_2 ) ;
}
F_771 ( V_65 ) ;
F_236 ( V_81 ) ;
}
static void F_772 ( struct V_1138 * V_1139 )
{
struct V_1 * V_2 =
F_773 ( V_1139 , struct V_1 , V_482 ) ;
struct V_81 * V_65 = F_48 ( V_2 -> V_65 ) ;
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_333 * V_88 = V_65 -> V_64 . V_88 ;
if ( F_1 ( V_2 ) )
F_774 ( & V_2 -> V_3 ) ;
F_3 ( & V_63 -> V_256 ) ;
F_200 ( V_2 -> V_1140 ) ;
F_229 ( V_2 -> V_480 ) ;
F_5 ( & V_63 -> V_256 ) ;
F_775 ( V_2 -> V_1141 ) ;
F_776 ( F_41 ( V_63 ) ,
F_234 ( V_88 ) -> V_354 ) ;
F_415 ( V_65 ) ;
F_231 ( V_2 -> V_1142 ) ;
F_664 ( F_341 ( & V_65 -> V_477 ) == 0 ) ;
F_777 ( & V_65 -> V_477 ) ;
F_236 ( V_2 ) ;
}
static bool F_778 ( T_1 V_1143 , T_1 V_1144 )
{
return ! ( ( V_1143 - V_1144 ) & 0x80000000 ) ;
}
static bool F_779 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
if ( F_316 ( V_65 ) )
return true ;
if ( F_59 ( V_6 ) < 5 && ! F_18 ( V_6 ) )
return true ;
return ( F_11 ( F_780 ( V_65 -> V_133 ) ) & ~ 0xfff ) ==
V_65 -> V_441 -> V_1145 &&
F_778 ( F_11 ( F_781 ( V_65 -> V_94 ) ) ,
V_65 -> V_441 -> V_1146 ) ;
}
static bool
F_782 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
return F_783 ( V_65 ) != V_2 -> V_1147 ;
}
static bool F_784 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
if ( ! F_341 ( & V_2 -> V_439 ) )
return false ;
F_785 () ;
if ( F_1 ( V_2 ) )
return F_782 ( V_65 , V_2 ) ;
else
return F_779 ( V_65 , V_2 ) ;
}
void F_288 ( struct V_5 * V_6 , int V_94 )
{
struct V_62 * V_63 = & V_6 -> V_260 ;
struct V_81 * V_65 = F_53 ( V_6 , V_94 ) ;
struct V_1 * V_2 ;
unsigned long V_330 ;
if ( ! V_65 )
return;
F_786 ( & V_63 -> V_440 , V_330 ) ;
V_2 = V_65 -> V_441 ;
if ( V_2 != NULL &&
! F_1 ( V_2 ) &&
F_784 ( V_65 , V_2 ) )
F_343 ( V_65 ) ;
F_787 ( & V_63 -> V_440 , V_330 ) ;
}
void F_788 ( struct V_5 * V_6 , int V_94 )
{
struct V_62 * V_63 = & V_6 -> V_260 ;
struct V_81 * V_65 = F_53 ( V_6 , V_94 ) ;
struct V_1 * V_2 ;
unsigned long V_330 ;
if ( ! V_65 )
return;
F_786 ( & V_63 -> V_440 , V_330 ) ;
V_2 = V_65 -> V_441 ;
if ( V_2 != NULL &&
F_1 ( V_2 ) &&
F_784 ( V_65 , V_2 ) )
F_343 ( V_65 ) ;
F_787 ( & V_63 -> V_440 , V_330 ) ;
}
static inline void F_789 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
V_2 -> V_1147 = F_783 ( V_65 ) ;
F_790 () ;
F_791 ( & V_2 -> V_439 , 1 ) ;
}
static int F_792 ( struct V_62 * V_63 ,
struct V_145 * V_65 ,
struct V_245 * V_89 ,
struct V_252 * V_253 ,
struct V_1148 * V_1149 ,
T_2 V_330 )
{
struct V_1150 * V_1151 = V_1149 -> V_1151 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
T_1 V_1152 ;
int V_362 ;
V_362 = F_793 ( V_1149 , 6 ) ;
if ( V_362 )
return V_362 ;
if ( V_81 -> V_133 )
V_1152 = V_1153 ;
else
V_1152 = V_1154 ;
F_794 ( V_1151 , V_1155 | V_1152 ) ;
F_794 ( V_1151 , V_1156 ) ;
F_794 ( V_1151 , V_1157 |
F_795 ( V_81 -> V_133 ) ) ;
F_794 ( V_1151 , V_89 -> V_262 [ 0 ] ) ;
F_794 ( V_1151 , V_81 -> V_441 -> V_1145 ) ;
F_794 ( V_1151 , 0 ) ;
return 0 ;
}
static int F_796 ( struct V_62 * V_63 ,
struct V_145 * V_65 ,
struct V_245 * V_89 ,
struct V_252 * V_253 ,
struct V_1148 * V_1149 ,
T_2 V_330 )
{
struct V_1150 * V_1151 = V_1149 -> V_1151 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
T_1 V_1152 ;
int V_362 ;
V_362 = F_793 ( V_1149 , 6 ) ;
if ( V_362 )
return V_362 ;
if ( V_81 -> V_133 )
V_1152 = V_1153 ;
else
V_1152 = V_1154 ;
F_794 ( V_1151 , V_1155 | V_1152 ) ;
F_794 ( V_1151 , V_1156 ) ;
F_794 ( V_1151 , V_1158 |
F_795 ( V_81 -> V_133 ) ) ;
F_794 ( V_1151 , V_89 -> V_262 [ 0 ] ) ;
F_794 ( V_1151 , V_81 -> V_441 -> V_1145 ) ;
F_794 ( V_1151 , V_1156 ) ;
return 0 ;
}
static int F_797 ( struct V_62 * V_63 ,
struct V_145 * V_65 ,
struct V_245 * V_89 ,
struct V_252 * V_253 ,
struct V_1148 * V_1149 ,
T_2 V_330 )
{
struct V_1150 * V_1151 = V_1149 -> V_1151 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
T_2 V_1159 , V_1160 ;
int V_362 ;
V_362 = F_793 ( V_1149 , 4 ) ;
if ( V_362 )
return V_362 ;
F_794 ( V_1151 , V_1157 |
F_795 ( V_81 -> V_133 ) ) ;
F_794 ( V_1151 , V_89 -> V_262 [ 0 ] ) ;
F_794 ( V_1151 , V_81 -> V_441 -> V_1145 |
F_214 ( V_89 -> V_257 ) ) ;
V_1159 = 0 ;
V_1160 = F_11 ( F_321 ( V_81 -> V_94 ) ) & 0x0fff0fff ;
F_794 ( V_1151 , V_1159 | V_1160 ) ;
return 0 ;
}
static int F_798 ( struct V_62 * V_63 ,
struct V_145 * V_65 ,
struct V_245 * V_89 ,
struct V_252 * V_253 ,
struct V_1148 * V_1149 ,
T_2 V_330 )
{
struct V_1150 * V_1151 = V_1149 -> V_1151 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
T_2 V_1159 , V_1160 ;
int V_362 ;
V_362 = F_793 ( V_1149 , 4 ) ;
if ( V_362 )
return V_362 ;
F_794 ( V_1151 , V_1157 |
F_795 ( V_81 -> V_133 ) ) ;
F_794 ( V_1151 , V_89 -> V_262 [ 0 ] |
F_214 ( V_89 -> V_257 ) ) ;
F_794 ( V_1151 , V_81 -> V_441 -> V_1145 ) ;
V_1159 = 0 ;
V_1160 = F_11 ( F_321 ( V_81 -> V_94 ) ) & 0x0fff0fff ;
F_794 ( V_1151 , V_1159 | V_1160 ) ;
return 0 ;
}
static int F_799 ( struct V_62 * V_63 ,
struct V_145 * V_65 ,
struct V_245 * V_89 ,
struct V_252 * V_253 ,
struct V_1148 * V_1149 ,
T_2 V_330 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_1150 * V_1151 = V_1149 -> V_1151 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
T_2 V_1161 = 0 ;
int V_1162 , V_362 ;
switch ( V_81 -> V_133 ) {
case V_1163 :
V_1161 = V_1164 ;
break;
case V_368 :
V_1161 = V_1165 ;
break;
case V_1166 :
V_1161 = V_1167 ;
break;
default:
F_351 ( 1 , L_182 ) ;
return - V_419 ;
}
V_1162 = 4 ;
if ( V_1149 -> V_1168 -> V_379 == V_1169 ) {
V_1162 += 6 ;
if ( F_800 ( V_6 ) )
V_1162 += 2 ;
}
V_362 = F_801 ( V_1149 ) ;
if ( V_362 )
return V_362 ;
V_362 = F_793 ( V_1149 , V_1162 ) ;
if ( V_362 )
return V_362 ;
if ( V_1149 -> V_1168 -> V_379 == V_1169 ) {
F_794 ( V_1151 , F_802 ( 1 ) ) ;
F_803 ( V_1151 , V_1170 ) ;
F_794 ( V_1151 , ~ ( V_1171 |
V_1172 |
V_1173 ) ) ;
if ( F_800 ( V_6 ) )
F_794 ( V_1151 , V_1174 |
V_1175 ) ;
else
F_794 ( V_1151 , V_1176 |
V_1175 ) ;
F_803 ( V_1151 , V_1170 ) ;
F_794 ( V_1151 ,
F_804 ( V_1149 -> V_1168 -> V_1177 ) + 256 ) ;
if ( F_800 ( V_6 ) ) {
F_794 ( V_1151 , 0 ) ;
F_794 ( V_1151 , V_1156 ) ;
}
}
F_794 ( V_1151 , V_1158 | V_1161 ) ;
F_794 ( V_1151 , V_89 -> V_262 [ 0 ] |
F_214 ( V_89 -> V_257 ) ) ;
F_794 ( V_1151 , V_81 -> V_441 -> V_1145 ) ;
F_794 ( V_1151 , ( V_1156 ) ) ;
return 0 ;
}
static bool F_805 ( struct V_1178 * V_1168 ,
struct V_252 * V_253 )
{
if ( V_1168 == NULL )
return true ;
if ( F_59 ( V_1168 -> V_259 ) < 5 )
return false ;
if ( V_259 . F_805 < 0 )
return false ;
else if ( V_259 . F_805 > 0 )
return true ;
else if ( V_259 . V_1179 )
return true ;
return V_1168 != F_806 ( V_253 ) ;
}
static void F_807 ( struct V_81 * V_81 ,
unsigned int V_246 ,
struct V_1 * V_2 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_245 * V_89 = V_81 -> V_64 . V_88 -> V_89 ;
const enum V_94 V_94 = V_81 -> V_94 ;
T_1 V_1180 , V_292 = F_273 ( V_89 , 0 , V_246 ) ;
V_1180 = F_11 ( F_94 ( V_94 , 0 ) ) ;
V_1180 &= ~ V_1003 ;
switch ( V_89 -> V_257 ) {
case V_230 :
break;
case V_231 :
V_1180 |= V_397 ;
break;
case V_232 :
V_1180 |= V_398 ;
break;
case V_233 :
V_1180 |= V_399 ;
break;
default:
F_172 ( V_89 -> V_257 ) ;
}
F_124 ( F_94 ( V_94 , 0 ) , V_1180 ) ;
F_124 ( F_279 ( V_94 , 0 ) , V_292 ) ;
F_124 ( F_284 ( V_94 , 0 ) , V_2 -> V_1145 ) ;
F_125 ( F_284 ( V_94 , 0 ) ) ;
}
static void F_808 ( struct V_81 * V_81 ,
struct V_1 * V_2 )
{
struct V_62 * V_63 = V_81 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_245 * V_89 = V_81 -> V_64 . V_88 -> V_89 ;
T_3 V_13 = F_88 ( V_81 -> V_133 ) ;
T_1 V_363 ;
V_363 = F_11 ( V_13 ) ;
if ( V_89 -> V_257 == V_231 )
V_363 |= V_369 ;
else
V_363 &= ~ V_369 ;
F_124 ( V_13 , V_363 ) ;
F_124 ( F_258 ( V_81 -> V_133 ) , V_2 -> V_1145 ) ;
F_125 ( F_258 ( V_81 -> V_133 ) ) ;
}
static void F_809 ( struct V_1138 * V_356 )
{
struct V_1 * V_2 =
F_773 ( V_356 , struct V_1 , V_3 ) ;
struct V_81 * V_65 = F_48 ( V_2 -> V_65 ) ;
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
struct V_267 * V_268 =
F_182 ( V_65 -> V_64 . V_88 -> V_89 ) ;
struct V_252 * V_253 = V_268 -> V_253 ;
F_28 ( F_810 ( V_253 , 0 , V_1181 , NULL ) < 0 ) ;
F_811 ( V_65 ) ;
if ( F_59 ( V_6 ) >= 9 )
F_807 ( V_65 , V_2 -> V_246 , V_2 ) ;
else
F_808 ( V_65 , V_2 ) ;
F_812 ( V_65 , V_2 ) ;
}
static int F_813 ( struct V_62 * V_63 ,
struct V_145 * V_65 ,
struct V_245 * V_89 ,
struct V_252 * V_253 ,
struct V_1148 * V_1149 ,
T_2 V_330 )
{
return - V_419 ;
}
static bool F_814 ( struct V_5 * V_6 ,
struct V_81 * V_81 ,
struct V_1 * V_2 )
{
T_1 V_1182 , V_1183 ;
if ( ! F_341 ( & V_2 -> V_439 ) )
return false ;
F_785 () ;
V_1183 = F_783 ( V_81 ) ;
if ( V_2 -> V_1184 == 0 ) {
if ( V_2 -> V_1141 &&
! F_815 ( V_2 -> V_1141 ) )
return false ;
V_2 -> V_1184 = V_1183 ;
}
if ( V_1183 - V_2 -> V_1184 < 3 )
return false ;
if ( F_59 ( V_6 ) >= 4 )
V_1182 = F_816 ( F_11 ( F_258 ( V_81 -> V_133 ) ) ) ;
else
V_1182 = F_11 ( F_261 ( V_81 -> V_133 ) ) ;
return V_1182 == V_2 -> V_1145 ;
}
void F_817 ( struct V_5 * V_6 , int V_94 )
{
struct V_62 * V_63 = & V_6 -> V_260 ;
struct V_81 * V_65 = F_53 ( V_6 , V_94 ) ;
struct V_1 * V_2 ;
F_28 ( ! F_818 () ) ;
if ( V_65 == NULL )
return;
F_819 ( & V_63 -> V_440 ) ;
V_2 = V_65 -> V_441 ;
if ( V_2 != NULL && ! F_1 ( V_2 ) &&
F_814 ( V_6 , V_65 , V_2 ) ) {
F_351 ( 1 ,
L_183 ,
V_2 -> V_1147 , F_783 ( V_65 ) ) ;
F_343 ( V_65 ) ;
V_2 = NULL ;
}
if ( V_2 != NULL && ! F_1 ( V_2 ) &&
F_783 ( V_65 ) - V_2 -> V_1147 > 1 )
F_820 ( V_2 -> V_1141 ) ;
F_821 ( & V_63 -> V_440 ) ;
}
static int F_822 ( struct V_145 * V_65 ,
struct V_245 * V_89 ,
struct V_1185 * V_478 ,
T_2 V_1186 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_245 * V_1142 = V_65 -> V_88 -> V_89 ;
struct V_252 * V_253 = F_189 ( V_89 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_333 * V_88 = V_65 -> V_88 ;
enum V_94 V_94 = V_81 -> V_94 ;
struct V_1 * V_2 ;
struct V_1178 * V_1168 ;
bool V_1187 ;
struct V_1148 * V_1188 ;
struct V_251 * V_254 ;
int V_362 ;
if ( F_28 ( F_189 ( V_1142 ) == NULL ) )
return - V_1189 ;
if ( V_89 -> V_266 != V_65 -> V_88 -> V_89 -> V_266 )
return - V_288 ;
if ( F_59 ( V_6 ) > 3 &&
( V_89 -> V_281 [ 0 ] != V_65 -> V_88 -> V_89 -> V_281 [ 0 ] ||
V_89 -> V_262 [ 0 ] != V_65 -> V_88 -> V_89 -> V_262 [ 0 ] ) )
return - V_288 ;
if ( F_823 ( & V_6 -> V_437 ) )
goto V_1190;
V_2 = F_554 ( sizeof( * V_2 ) , V_721 ) ;
if ( V_2 == NULL )
return - V_720 ;
V_2 -> V_478 = V_478 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_1142 = V_1142 ;
F_824 ( & V_2 -> V_482 , F_772 ) ;
V_362 = F_101 ( V_65 ) ;
if ( V_362 )
goto V_1191;
F_311 ( & V_63 -> V_440 ) ;
if ( V_81 -> V_441 ) {
if ( F_784 ( V_81 , V_81 -> V_441 ) ) {
F_20 ( L_184 ) ;
F_343 ( V_81 ) ;
} else {
F_20 ( L_185 ) ;
F_312 ( & V_63 -> V_440 ) ;
F_102 ( V_65 ) ;
F_236 ( V_2 ) ;
return - V_1189 ;
}
}
V_81 -> V_441 = V_2 ;
F_312 ( & V_63 -> V_440 ) ;
if ( F_341 ( & V_81 -> V_477 ) >= 2 )
F_825 ( V_6 -> V_481 ) ;
F_232 ( V_2 -> V_1142 ) ;
V_65 -> V_88 -> V_89 = V_89 ;
F_230 ( V_65 -> V_88 ) ;
V_2 -> V_480 = F_826 ( V_253 ) ;
V_362 = F_742 ( V_63 ) ;
if ( V_362 )
goto V_1192;
V_81 -> V_438 = F_318 ( & V_6 -> V_437 ) ;
if ( F_827 ( & V_6 -> V_437 ) ) {
V_362 = - V_1193 ;
goto V_1194;
}
F_828 ( & V_81 -> V_477 ) ;
if ( F_59 ( V_6 ) >= 5 || F_18 ( V_6 ) )
V_2 -> V_1146 = F_11 ( F_781 ( V_94 ) ) + 1 ;
if ( F_16 ( V_6 ) || F_17 ( V_6 ) ) {
V_1168 = V_6 -> V_1168 [ V_1195 ] ;
if ( V_89 -> V_257 != V_1142 -> V_257 )
V_1168 = NULL ;
} else if ( F_326 ( V_6 ) || F_264 ( V_6 ) ) {
V_1168 = V_6 -> V_1168 [ V_1195 ] ;
} else if ( F_59 ( V_6 ) >= 7 ) {
V_1168 = F_806 ( V_253 ) ;
if ( V_1168 == NULL || V_1168 -> V_379 != V_1169 )
V_1168 = V_6 -> V_1168 [ V_1195 ] ;
} else {
V_1168 = V_6 -> V_1168 [ V_1169 ] ;
}
V_1187 = F_805 ( V_1168 , V_253 ) ;
V_254 = F_188 ( V_89 , V_88 -> V_43 -> V_246 ) ;
if ( F_194 ( V_254 ) ) {
V_362 = F_241 ( V_254 ) ;
goto V_1196;
}
V_2 -> V_1140 = F_235 ( V_88 -> V_43 ) -> V_254 ;
F_235 ( V_88 -> V_43 ) -> V_254 = V_254 ;
V_2 -> V_1145 = F_804 ( V_254 ) + V_81 -> V_375 ;
V_2 -> V_246 = V_65 -> V_88 -> V_43 -> V_246 ;
F_417 ( V_81 , V_81 -> V_90 ,
F_235 ( V_88 -> V_43 ) ) ;
if ( V_1187 ) {
F_824 ( & V_2 -> V_3 , F_809 ) ;
F_347 ( V_1197 , & V_2 -> V_3 ) ;
} else {
V_1188 = F_829 ( V_1168 ,
V_6 -> V_1198 ) ;
if ( F_194 ( V_1188 ) ) {
V_362 = F_241 ( V_1188 ) ;
goto V_1199;
}
V_362 = F_830 ( V_1188 , V_253 , false ) ;
if ( V_362 )
goto V_1200;
V_362 = V_6 -> V_434 . V_1201 ( V_63 , V_65 , V_89 , V_253 , V_1188 ,
V_1186 ) ;
if ( V_362 )
goto V_1200;
F_789 ( V_81 , V_2 ) ;
V_2 -> V_1141 = F_831 ( V_1188 ) ;
F_832 ( V_1188 ) ;
}
F_833 ( V_253 , 0 , V_1202 ) ;
F_834 ( F_189 ( V_1142 ) , V_253 ,
F_234 ( V_88 ) -> V_354 ) ;
F_5 ( & V_63 -> V_256 ) ;
F_835 ( F_41 ( V_63 ) ,
F_234 ( V_88 ) -> V_354 ) ;
F_836 ( V_81 -> V_133 , V_253 ) ;
return 0 ;
V_1200:
F_832 ( V_1188 ) ;
V_1199:
F_235 ( V_88 -> V_43 ) -> V_254 = V_2 -> V_1140 ;
F_200 ( V_254 ) ;
V_1196:
F_777 ( & V_81 -> V_477 ) ;
V_1194:
F_5 ( & V_63 -> V_256 ) ;
V_1192:
V_65 -> V_88 -> V_89 = V_1142 ;
F_230 ( V_65 -> V_88 ) ;
F_229 ( V_253 ) ;
F_231 ( V_2 -> V_1142 ) ;
F_311 ( & V_63 -> V_440 ) ;
V_81 -> V_441 = NULL ;
F_312 ( & V_63 -> V_440 ) ;
F_102 ( V_65 ) ;
V_1191:
F_236 ( V_2 ) ;
if ( V_362 == - V_1193 ) {
struct V_421 * V_43 ;
struct V_335 * V_336 ;
V_1190:
V_43 = F_539 ( V_63 ) ;
if ( ! V_43 )
return - V_720 ;
V_43 -> V_432 = F_837 ( V_65 ) ;
V_462:
V_336 = F_753 ( V_43 , V_88 ) ;
V_362 = F_547 ( V_336 ) ;
if ( ! V_362 ) {
F_756 ( V_336 , V_89 ) ;
V_362 = F_755 ( V_336 , V_65 ) ;
if ( ! V_362 )
V_362 = F_296 ( V_43 ) ;
}
if ( V_362 == - V_424 ) {
F_302 ( V_43 -> V_432 ) ;
F_838 ( V_43 ) ;
goto V_462;
}
F_305 ( V_43 ) ;
if ( V_362 == 0 && V_478 ) {
F_311 ( & V_63 -> V_440 ) ;
F_344 ( V_65 , V_478 ) ;
F_312 ( & V_63 -> V_440 ) ;
}
}
return V_362 ;
}
static bool F_839 ( struct V_333 * V_133 ,
struct V_335 * V_43 )
{
struct V_265 * V_1203 = F_235 ( V_43 ) ;
struct V_265 * V_1204 = F_235 ( V_133 -> V_43 ) ;
if ( V_1203 -> V_64 . V_340 != V_1204 -> V_64 . V_340 )
return true ;
if ( ! V_1204 -> V_64 . V_89 || ! V_1203 -> V_64 . V_89 )
return false ;
if ( V_1204 -> V_64 . V_89 -> V_257 != V_1203 -> V_64 . V_89 -> V_257 ||
V_1204 -> V_64 . V_246 != V_1203 -> V_64 . V_246 ||
F_247 ( & V_1203 -> V_64 . V_351 ) != F_247 ( & V_1204 -> V_64 . V_351 ) ||
F_248 ( & V_1203 -> V_64 . V_351 ) != F_248 ( & V_1204 -> V_64 . V_351 ) ||
F_247 ( & V_1203 -> V_64 . V_352 ) != F_247 ( & V_1204 -> V_64 . V_352 ) ||
F_248 ( & V_1203 -> V_64 . V_352 ) != F_248 ( & V_1204 -> V_64 . V_352 ) )
return true ;
return false ;
}
static bool F_840 ( struct V_265 * V_43 )
{
int V_345 = F_247 ( & V_43 -> V_64 . V_351 ) >> 16 ;
int V_346 = F_248 ( & V_43 -> V_64 . V_351 ) >> 16 ;
int V_410 = F_247 ( & V_43 -> V_64 . V_352 ) ;
int V_411 = F_248 ( & V_43 -> V_64 . V_352 ) ;
return ( V_345 != V_410 || V_346 != V_411 ) ;
}
int F_841 ( struct V_42 * V_60 ,
struct V_335 * V_336 )
{
struct V_37 * V_38 = F_290 ( V_60 ) ;
struct V_145 * V_65 = V_60 -> V_65 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_333 * V_133 = V_336 -> V_133 ;
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_265 * V_1205 =
F_235 ( V_133 -> V_43 ) ;
bool V_422 = F_25 ( V_60 ) ;
bool V_1206 = V_65 -> V_43 -> V_87 ;
bool V_1207 = V_60 -> V_87 ;
bool V_1208 , V_1209 , V_340 , V_1210 ;
struct V_245 * V_89 = V_336 -> V_89 ;
int V_362 ;
if ( F_59 ( V_6 ) >= 9 && V_133 -> type != V_1211 ) {
V_362 = F_393 (
F_290 ( V_60 ) ,
F_235 ( V_336 ) ) ;
if ( V_362 )
return V_362 ;
}
V_1210 = V_1205 -> V_64 . V_340 ;
V_340 = V_336 -> V_340 ;
if ( ! V_1206 && F_28 ( V_1210 ) )
V_1210 = false ;
if ( ! V_1207 )
V_336 -> V_340 = V_340 = false ;
if ( ! V_1210 && ! V_340 )
return 0 ;
if ( V_89 != V_1205 -> V_64 . V_89 )
V_38 -> V_1212 = true ;
V_1208 = V_1210 && ( ! V_340 || V_422 ) ;
V_1209 = V_340 && ( ! V_1210 || V_422 ) ;
F_842 ( L_186 ,
V_81 -> V_64 . V_64 . V_379 ,
V_81 -> V_64 . V_12 ,
V_133 -> V_64 . V_379 , V_133 -> V_12 ,
V_89 ? V_89 -> V_64 . V_379 : - 1 ) ;
F_842 ( L_187 ,
V_133 -> V_64 . V_379 , V_133 -> V_12 ,
V_1210 , V_340 ,
V_1208 , V_1209 , V_422 ) ;
if ( V_1209 ) {
V_38 -> V_574 = true ;
if ( V_133 -> type != V_1211 )
V_38 -> V_571 = true ;
} else if ( V_1208 ) {
V_38 -> V_565 = true ;
if ( V_133 -> type != V_1211 )
V_38 -> V_571 = true ;
} else if ( F_839 ( V_133 , V_336 ) ) {
V_38 -> V_574 = true ;
V_38 -> V_565 = true ;
}
if ( ( V_38 -> V_574 || V_38 -> V_565 ) &&
F_59 ( V_6 ) < 9 && V_6 -> V_434 . V_1213 )
F_290 ( V_60 ) -> V_563 . V_1214 = true ;
if ( V_340 || V_1210 )
V_38 -> V_562 |= F_234 ( V_133 ) -> V_354 ;
if ( V_133 -> type == V_1215 && F_326 ( V_6 ) &&
F_840 ( F_235 ( V_336 ) ) &&
! F_840 ( V_1205 ) )
V_38 -> V_572 = true ;
return 0 ;
}
static bool F_843 ( const struct V_511 * V_1143 ,
const struct V_511 * V_1144 )
{
return V_1143 == V_1144 || ( V_1143 -> V_1216 & ( 1 << V_1144 -> type ) &&
V_1144 -> V_1216 & ( 1 << V_1143 -> type ) ) ;
}
static bool F_844 ( struct V_421 * V_43 ,
struct V_81 * V_65 ,
struct V_511 * V_512 )
{
struct V_511 * V_1217 ;
struct V_577 * V_718 ;
struct V_575 * V_1112 ;
int V_135 ;
F_423 (state, connector, connector_state, i) {
if ( V_1112 -> V_65 != & V_65 -> V_64 )
continue;
V_1217 =
F_424 ( V_1112 -> V_580 ) ;
if ( ! F_843 ( V_512 , V_1217 ) )
return false ;
}
return true ;
}
static int F_845 ( struct V_145 * V_65 ,
struct V_42 * V_60 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_37 * V_38 =
F_290 ( V_60 ) ;
struct V_421 * V_43 = V_60 -> V_43 ;
int V_362 ;
bool V_422 = F_25 ( V_60 ) ;
if ( V_422 && ! V_60 -> V_87 )
V_38 -> V_565 = true ;
if ( V_422 && V_60 -> V_507 &&
V_6 -> V_434 . V_1218 &&
! F_28 ( V_38 -> V_206 ) ) {
V_362 = V_6 -> V_434 . V_1218 ( V_81 ,
V_38 ) ;
if ( V_362 )
return V_362 ;
}
if ( V_60 -> V_1219 ) {
V_362 = F_846 ( V_65 , V_60 ) ;
if ( V_362 )
return V_362 ;
V_60 -> V_1220 = true ;
}
V_362 = 0 ;
if ( V_6 -> V_434 . V_1221 ) {
V_362 = V_6 -> V_434 . V_1221 ( V_38 ) ;
if ( V_362 ) {
F_161 ( L_188 ) ;
return V_362 ;
}
}
if ( V_6 -> V_434 . V_1222 &&
! F_295 ( V_43 ) -> V_423 ) {
if ( F_28 ( ! V_6 -> V_434 . V_1221 ) )
return 0 ;
V_362 = V_6 -> V_434 . V_1222 ( V_63 ,
V_81 ,
V_38 ) ;
if ( V_362 ) {
F_161 ( L_189 ) ;
return V_362 ;
}
} else if ( V_6 -> V_434 . V_1222 ) {
if ( F_15 ( V_6 ) && F_59 ( V_6 ) < 9 )
V_38 -> V_563 . V_1223 . V_1224 = V_38 -> V_563 . V_1223 . V_1225 ;
}
if ( F_59 ( V_6 ) >= 9 ) {
if ( V_422 )
V_362 = F_392 ( V_38 ) ;
if ( ! V_362 )
V_362 = F_847 ( V_63 , V_81 ,
V_38 ) ;
}
return V_362 ;
}
static void F_848 ( struct V_62 * V_63 )
{
struct V_717 * V_718 ;
F_849 (dev, connector) {
if ( V_718 -> V_64 . V_43 -> V_65 )
F_850 ( & V_718 -> V_64 ) ;
if ( V_718 -> V_64 . V_512 ) {
V_718 -> V_64 . V_43 -> V_580 =
V_718 -> V_64 . V_512 ;
V_718 -> V_64 . V_43 -> V_65 =
V_718 -> V_64 . V_512 -> V_65 ;
F_851 ( & V_718 -> V_64 ) ;
} else {
V_718 -> V_64 . V_43 -> V_580 = NULL ;
V_718 -> V_64 . V_43 -> V_65 = NULL ;
}
}
}
static void
F_852 ( struct V_717 * V_718 ,
struct V_37 * V_38 )
{
const struct V_1226 * V_1227 = & V_718 -> V_64 . V_1228 ;
int V_985 = V_38 -> V_729 ;
F_161 ( L_190 ,
V_718 -> V_64 . V_64 . V_379 ,
V_718 -> V_64 . V_12 ) ;
if ( V_1227 -> V_521 != 0 && V_1227 -> V_521 * 3 < V_985 ) {
F_161 ( L_191 ,
V_985 , V_1227 -> V_521 * 3 ) ;
V_38 -> V_729 = V_1227 -> V_521 * 3 ;
}
if ( V_1227 -> V_521 == 0 && V_985 > 24 ) {
F_161 ( L_192 ,
V_985 ) ;
V_38 -> V_729 = 24 ;
}
}
static int
F_853 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
struct V_421 * V_43 ;
struct V_577 * V_718 ;
struct V_575 * V_1112 ;
int V_985 , V_135 ;
if ( ( F_18 ( V_6 ) || F_16 ( V_6 ) ||
F_17 ( V_6 ) ) )
V_985 = 10 * 3 ;
else if ( F_59 ( V_6 ) >= 5 )
V_985 = 12 * 3 ;
else
V_985 = 8 * 3 ;
V_38 -> V_729 = V_985 ;
V_43 = V_38 -> V_64 . V_43 ;
F_423 (state, connector, connector_state, i) {
if ( V_1112 -> V_65 != & V_65 -> V_64 )
continue;
F_852 ( F_854 ( V_718 ) ,
V_38 ) ;
}
return V_985 ;
}
static void F_855 ( const struct V_520 * V_417 )
{
F_161 ( L_193
L_194 ,
V_417 -> V_92 ,
V_417 -> V_543 , V_417 -> V_734 ,
V_417 -> V_884 , V_417 -> V_881 ,
V_417 -> V_544 , V_417 -> V_886 ,
V_417 -> V_887 , V_417 -> V_877 , V_417 -> type , V_417 -> V_330 ) ;
}
static inline void
F_856 ( struct V_37 * V_38 , char * V_379 ,
unsigned int V_1042 , struct V_794 * V_795 )
{
F_161 ( L_195 ,
V_379 , V_1042 ,
V_795 -> V_797 , V_795 -> V_798 ,
V_795 -> V_799 , V_795 -> V_800 , V_795 -> V_796 ) ;
}
static void F_857 ( struct V_81 * V_65 ,
struct V_37 * V_38 ,
const char * V_1229 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_333 * V_133 ;
struct V_337 * V_337 ;
struct V_265 * V_43 ;
struct V_245 * V_89 ;
F_161 ( L_196 ,
V_65 -> V_64 . V_64 . V_379 , V_65 -> V_64 . V_12 , V_1229 ) ;
F_161 ( L_197 ,
F_858 ( V_38 -> V_95 ) ,
V_38 -> V_729 , V_38 -> V_900 ) ;
if ( V_38 -> V_222 )
F_856 ( V_38 , L_198 ,
V_38 -> V_457 ,
& V_38 -> V_587 ) ;
if ( F_388 ( V_38 ) ) {
F_856 ( V_38 , L_199 ,
V_38 -> V_1042 , & V_38 -> V_814 ) ;
if ( V_38 -> V_812 )
F_856 ( V_38 , L_200 ,
V_38 -> V_1042 ,
& V_38 -> V_815 ) ;
}
F_161 ( L_201 ,
V_38 -> V_1041 , V_38 -> V_1230 ) ;
F_161 ( L_202 ) ;
F_859 ( & V_38 -> V_64 . V_417 ) ;
F_161 ( L_203 ) ;
F_859 ( & V_38 -> V_64 . V_91 ) ;
F_855 ( & V_38 -> V_64 . V_91 ) ;
F_161 ( L_204 ,
V_38 -> V_39 ,
V_38 -> V_367 , V_38 -> V_366 ) ;
if ( F_59 ( V_6 ) >= 9 )
F_161 ( L_205 ,
V_65 -> V_382 ,
V_38 -> V_381 . V_533 ,
V_38 -> V_381 . V_407 ) ;
if ( F_163 ( V_6 ) )
F_161 ( L_206 ,
V_38 -> V_595 . V_596 ,
V_38 -> V_595 . V_600 ,
V_38 -> V_595 . V_1231 ) ;
else
F_161 ( L_207 ,
V_38 -> V_443 . V_548 ,
V_38 -> V_443 . V_241 ,
F_860 ( V_38 -> V_443 . V_146 ) ) ;
F_161 ( L_208 ,
V_38 -> V_551 , V_38 -> V_226 ) ;
F_861 ( V_6 , & V_38 -> V_174 ) ;
F_161 ( L_209 ) ;
F_862 (plane, &dev->mode_config.plane_list, head) {
struct V_1232 V_1233 ;
V_337 = F_234 ( V_133 ) ;
if ( V_337 -> V_94 != V_65 -> V_94 )
continue;
V_43 = F_235 ( V_133 -> V_43 ) ;
V_89 = V_43 -> V_64 . V_89 ;
if ( ! V_89 ) {
F_161 ( L_210 ,
V_133 -> V_64 . V_379 , V_133 -> V_12 , V_43 -> V_407 ) ;
continue;
}
F_161 ( L_211 ,
V_133 -> V_64 . V_379 , V_133 -> V_12 ,
V_89 -> V_64 . V_379 , V_89 -> V_242 , V_89 -> V_237 ,
F_863 ( V_89 -> V_266 -> V_266 , & V_1233 ) ) ;
if ( F_59 ( V_6 ) >= 9 )
F_161 ( L_212 ,
V_43 -> V_407 ,
V_43 -> V_64 . V_351 . V_293 >> 16 ,
V_43 -> V_64 . V_351 . y1 >> 16 ,
F_247 ( & V_43 -> V_64 . V_351 ) >> 16 ,
F_248 ( & V_43 -> V_64 . V_351 ) >> 16 ,
V_43 -> V_64 . V_352 . V_293 , V_43 -> V_64 . V_352 . y1 ,
F_247 ( & V_43 -> V_64 . V_352 ) ,
F_248 ( & V_43 -> V_64 . V_352 ) ) ;
}
}
static bool F_864 ( struct V_421 * V_43 )
{
struct V_62 * V_63 = V_43 -> V_63 ;
struct V_577 * V_718 ;
unsigned int V_1234 = 0 ;
unsigned int V_1235 = 0 ;
F_865 (connector, dev) {
struct V_575 * V_1112 ;
struct V_511 * V_512 ;
V_1112 = F_866 ( V_43 , V_718 ) ;
if ( ! V_1112 )
V_1112 = V_718 -> V_43 ;
if ( ! V_1112 -> V_580 )
continue;
V_512 = F_424 ( V_1112 -> V_580 ) ;
F_28 ( ! V_1112 -> V_65 ) ;
switch ( V_512 -> type ) {
unsigned int V_196 ;
case V_614 :
if ( F_28 ( ! F_23 ( F_41 ( V_63 ) ) ) )
break;
case V_513 :
case V_209 :
case V_514 :
V_196 = 1 << F_380 ( & V_512 -> V_64 ) -> V_178 ;
if ( V_1234 & V_196 )
return false ;
V_1234 |= V_196 ;
break;
case V_591 :
V_1235 |=
1 << F_463 ( & V_512 -> V_64 ) -> V_88 -> V_178 ;
break;
default:
break;
}
}
if ( V_1234 & V_1235 )
return false ;
return true ;
}
static void
F_867 ( struct V_37 * V_60 )
{
struct V_42 V_1236 ;
struct V_380 V_381 ;
struct V_1237 V_174 ;
struct V_991 * V_206 ;
bool V_620 ;
V_1236 = V_60 -> V_64 ;
V_381 = V_60 -> V_381 ;
V_206 = V_60 -> V_206 ;
V_174 = V_60 -> V_174 ;
V_620 = V_60 -> V_443 . V_620 ;
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_60 -> V_64 = V_1236 ;
V_60 -> V_381 = V_381 ;
V_60 -> V_206 = V_206 ;
V_60 -> V_174 = V_174 ;
V_60 -> V_443 . V_620 = V_620 ;
}
static int
F_868 ( struct V_145 * V_65 ,
struct V_37 * V_38 )
{
struct V_421 * V_43 = V_38 -> V_64 . V_43 ;
struct V_511 * V_512 ;
struct V_577 * V_718 ;
struct V_575 * V_1112 ;
int V_1238 , V_362 = - V_288 ;
int V_135 ;
bool V_462 = true ;
F_867 ( V_38 ) ;
V_38 -> V_95 =
(enum V_93 ) F_48 ( V_65 ) -> V_94 ;
if ( ! ( V_38 -> V_64 . V_91 . V_330 &
( V_525 | V_1239 ) ) )
V_38 -> V_64 . V_91 . V_330 |= V_1239 ;
if ( ! ( V_38 -> V_64 . V_91 . V_330 &
( V_527 | V_1240 ) ) )
V_38 -> V_64 . V_91 . V_330 |= V_1240 ;
V_1238 = F_853 ( F_48 ( V_65 ) ,
V_38 ) ;
if ( V_1238 < 0 )
goto V_783;
F_754 ( & V_38 -> V_64 . V_417 ,
& V_38 -> V_367 ,
& V_38 -> V_366 ) ;
F_423 (state, connector, connector_state, i) {
if ( V_1112 -> V_65 != V_65 )
continue;
V_512 = F_424 ( V_1112 -> V_580 ) ;
if ( ! F_844 ( V_43 , F_48 ( V_65 ) , V_512 ) ) {
F_161 ( L_213 ) ;
goto V_783;
}
V_38 -> V_1241 |= 1 << V_512 -> type ;
}
V_1242:
V_38 -> V_39 = 0 ;
V_38 -> V_590 = 1 ;
F_869 ( & V_38 -> V_64 . V_91 ,
V_1243 ) ;
F_423 (state, connector, connector_state, i) {
if ( V_1112 -> V_65 != V_65 )
continue;
V_512 = F_424 ( V_1112 -> V_580 ) ;
if ( ! ( V_512 -> V_1244 ( V_512 , V_38 , V_1112 ) ) ) {
F_161 ( L_214 ) ;
goto V_783;
}
}
if ( ! V_38 -> V_39 )
V_38 -> V_39 = V_38 -> V_64 . V_91 . V_92
* V_38 -> V_590 ;
V_362 = F_566 ( F_48 ( V_65 ) , V_38 ) ;
if ( V_362 < 0 ) {
F_161 ( L_215 ) ;
goto V_783;
}
if ( V_362 == V_731 ) {
if ( F_7 ( ! V_462 , L_216 ) ) {
V_362 = - V_288 ;
goto V_783;
}
F_161 ( L_217 ) ;
V_462 = false ;
goto V_1242;
}
V_38 -> V_900 = V_38 -> V_729 == 6 * 3 ;
F_161 ( L_218 ,
V_1238 , V_38 -> V_729 , V_38 -> V_900 ) ;
V_783:
return V_362 ;
}
static void
F_870 ( struct V_421 * V_43 )
{
struct V_145 * V_65 ;
struct V_42 * V_60 ;
int V_135 ;
F_294 (state, crtc, crtc_state, i) {
F_48 ( V_65 ) -> V_90 = F_290 ( V_65 -> V_43 ) ;
if ( V_65 -> V_43 -> V_87 )
V_65 -> V_1245 = V_65 -> V_43 -> V_91 ;
else
V_65 -> V_1245 . V_92 = 0 ;
if ( F_412 ( V_43 , V_65 -> V_88 ) ) {
struct V_335 * V_336 = V_65 -> V_88 -> V_43 ;
V_65 -> V_88 -> V_89 = V_336 -> V_89 ;
V_65 -> V_263 = V_336 -> V_343 >> 16 ;
V_65 -> V_264 = V_336 -> V_344 >> 16 ;
}
}
}
static bool F_871 ( int V_1246 , int V_1247 )
{
int V_1248 ;
if ( V_1246 == V_1247 )
return true ;
if ( ! V_1246 || ! V_1247 )
return false ;
V_1248 = abs ( V_1246 - V_1247 ) ;
if ( ( ( ( ( V_1248 + V_1246 + V_1247 ) * 100 ) ) / ( V_1246 + V_1247 ) ) < 105 )
return true ;
return false ;
}
static bool
F_872 ( unsigned int V_46 , unsigned int V_51 ,
unsigned int V_47 , unsigned int V_1249 ,
bool V_1250 )
{
if ( V_46 == V_47 && V_51 == V_1249 )
return true ;
if ( V_1250 || ! V_46 || ! V_51 || ! V_47 || ! V_1249 )
return false ;
F_873 ( V_787 > V_84 ) ;
if ( V_51 > V_1249 ) {
while ( V_51 > V_1249 ) {
V_47 <<= 1 ;
V_1249 <<= 1 ;
}
} else if ( V_51 < V_1249 ) {
while ( V_51 < V_1249 ) {
V_46 <<= 1 ;
V_51 <<= 1 ;
}
}
if ( V_51 != V_1249 )
return false ;
return F_871 ( V_46 , V_47 ) ;
}
static bool
F_874 ( const struct V_794 * V_795 ,
struct V_794 * V_811 ,
bool V_1251 )
{
if ( V_795 -> V_796 == V_811 -> V_796 &&
F_872 ( V_795 -> V_797 , V_795 -> V_798 ,
V_811 -> V_797 , V_811 -> V_798 , ! V_1251 ) &&
F_872 ( V_795 -> V_799 , V_795 -> V_800 ,
V_811 -> V_799 , V_811 -> V_800 , ! V_1251 ) ) {
if ( V_1251 )
* V_811 = * V_795 ;
return true ;
}
return false ;
}
static bool
F_875 ( struct V_5 * V_6 ,
struct V_37 * V_1252 ,
struct V_37 * V_38 ,
bool V_1251 )
{
bool V_362 = true ;
#define F_876 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
pipe_config_err(adjust, __stringify(name), \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_877 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
pipe_config_err(adjust, __stringify(name), \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_878 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
pipe_config_err(adjust, __stringify(name), \
"(expected %p, found %p)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_879 ( V_12 ) \
if (!intel_compare_link_m_n(&current_config->name, \
&pipe_config->name,\
adjust)) { \
pipe_config_err(adjust, __stringify(name), \
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
#define F_880 ( V_12 , T_7 ) \
if (!intel_compare_link_m_n(&current_config->name, \
&pipe_config->name, adjust) && \
!intel_compare_link_m_n(&current_config->alt_name, \
&pipe_config->name, adjust)) { \
pipe_config_err(adjust, __stringify(name), \
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
#define F_881 ( V_12 , V_619 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
pipe_config_err(adjust, __stringify(name), \
"(%x) (expected %i, found %i)\n", \
(mask), \
current_config->name & (mask), \
pipe_config->name & (mask)); \
ret = false; \
}
#define F_882 ( V_12 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
pipe_config_err(adjust, __stringify(name), \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_883 ( T_8 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_877 ( V_95 ) ;
F_877 ( V_222 ) ;
F_877 ( V_457 ) ;
F_879 ( V_587 ) ;
F_877 ( V_1042 ) ;
F_876 ( V_1253 ) ;
if ( F_59 ( V_6 ) < 8 ) {
F_879 ( V_814 ) ;
if ( V_1252 -> V_812 )
F_879 ( V_815 ) ;
} else
F_880 ( V_814 , V_815 ) ;
F_876 ( V_1241 ) ;
F_877 ( V_64 . V_91 . V_543 ) ;
F_877 ( V_64 . V_91 . V_881 ) ;
F_877 ( V_64 . V_91 . V_882 ) ;
F_877 ( V_64 . V_91 . V_883 ) ;
F_877 ( V_64 . V_91 . V_734 ) ;
F_877 ( V_64 . V_91 . V_884 ) ;
F_877 ( V_64 . V_91 . V_544 ) ;
F_877 ( V_64 . V_91 . V_877 ) ;
F_877 ( V_64 . V_91 . V_885 ) ;
F_877 ( V_64 . V_91 . V_878 ) ;
F_877 ( V_64 . V_91 . V_886 ) ;
F_877 ( V_64 . V_91 . V_887 ) ;
F_877 ( V_590 ) ;
F_877 ( V_1254 ) ;
if ( ( F_59 ( V_6 ) < 8 && ! F_264 ( V_6 ) ) ||
F_16 ( V_6 ) || F_17 ( V_6 ) )
F_877 ( V_909 ) ;
F_877 ( V_1230 ) ;
F_877 ( V_1041 ) ;
F_881 ( V_64 . V_91 . V_330 ,
V_880 ) ;
if ( ! F_883 ( V_1255 ) ) {
F_881 ( V_64 . V_91 . V_330 ,
V_525 ) ;
F_881 ( V_64 . V_91 . V_330 ,
V_1239 ) ;
F_881 ( V_64 . V_91 . V_330 ,
V_527 ) ;
F_881 ( V_64 . V_91 . V_330 ,
V_1240 ) ;
}
F_876 ( V_595 . V_596 ) ;
if ( F_59 ( V_6 ) < 4 )
F_876 ( V_595 . V_600 ) ;
F_876 ( V_595 . V_1231 ) ;
if ( ! V_1251 ) {
F_877 ( V_367 ) ;
F_877 ( V_366 ) ;
F_877 ( V_443 . V_146 ) ;
if ( V_1252 -> V_443 . V_146 ) {
F_876 ( V_443 . V_548 ) ;
F_876 ( V_443 . V_241 ) ;
}
F_877 ( V_381 . V_407 ) ;
}
if ( F_264 ( V_6 ) )
F_877 ( V_551 ) ;
F_877 ( V_226 ) ;
F_878 ( V_206 ) ;
F_876 ( V_174 . V_45 ) ;
F_876 ( V_174 . V_176 ) ;
F_876 ( V_174 . V_712 ) ;
F_876 ( V_174 . V_713 ) ;
F_876 ( V_174 . V_1256 ) ;
F_876 ( V_174 . V_1257 ) ;
F_876 ( V_174 . V_1258 ) ;
F_876 ( V_174 . V_1259 ) ;
F_876 ( V_174 . V_1260 ) ;
F_876 ( V_1261 . V_1262 ) ;
F_876 ( V_1261 . div ) ;
if ( F_18 ( V_6 ) || F_59 ( V_6 ) >= 5 )
F_877 ( V_729 ) ;
F_882 ( V_64 . V_91 . V_92 ) ;
F_882 ( V_39 ) ;
#undef F_876
#undef F_877
#undef F_878
#undef F_881
#undef F_882
#undef F_883
return V_362 ;
}
static void F_884 ( struct V_5 * V_6 ,
const struct V_37 * V_38 )
{
if ( V_38 -> V_222 ) {
int V_727 = F_767 ( F_22 ( V_6 , V_38 ) ,
& V_38 -> V_587 ) ;
int V_1263 = V_38 -> V_64 . V_91 . V_92 ;
F_7 ( ! F_871 ( V_727 , V_1263 ) ,
L_219 ,
V_727 , V_1263 ) ;
}
}
static void F_885 ( struct V_145 * V_65 ,
struct V_42 * V_1264 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
struct V_1265 V_1266 , * V_1267 ;
struct V_1268 V_1269 , * V_1270 ;
struct V_1271 * V_1272 , * V_1273 ;
struct V_1274 * V_1275 , * V_1276 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
const enum V_94 V_94 = V_81 -> V_94 ;
int V_133 , V_1277 , V_1278 = F_886 ( V_6 ) ;
if ( F_59 ( V_6 ) < 9 || ! V_1264 -> V_87 )
return;
F_887 ( V_65 , & V_1269 ) ;
V_1270 = & F_290 ( V_1264 ) -> V_563 . V_1279 . V_1225 ;
F_888 ( V_6 , & V_1266 ) ;
V_1267 = & V_6 -> V_563 . V_1280 . V_1281 ;
F_889 (dev_priv, pipe, plane) {
V_1272 = & V_1269 . V_1282 [ V_133 ] ;
V_1273 = & V_1270 -> V_1282 [ V_133 ] ;
for ( V_1277 = 0 ; V_1277 <= V_1278 ; V_1277 ++ ) {
if ( F_890 ( & V_1272 -> V_563 [ V_1277 ] ,
& V_1273 -> V_563 [ V_1277 ] ) )
continue;
F_127 ( L_220 ,
F_78 ( V_94 ) , V_133 + 1 , V_1277 ,
V_1273 -> V_563 [ V_1277 ] . V_1283 ,
V_1273 -> V_563 [ V_1277 ] . V_1284 ,
V_1273 -> V_563 [ V_1277 ] . V_1285 ,
V_1272 -> V_563 [ V_1277 ] . V_1283 ,
V_1272 -> V_563 [ V_1277 ] . V_1284 ,
V_1272 -> V_563 [ V_1277 ] . V_1285 ) ;
}
if ( ! F_890 ( & V_1272 -> V_1286 ,
& V_1273 -> V_1286 ) ) {
F_127 ( L_221 ,
F_78 ( V_94 ) , V_133 + 1 ,
V_1273 -> V_1286 . V_1283 ,
V_1273 -> V_1286 . V_1284 ,
V_1273 -> V_1286 . V_1285 ,
V_1272 -> V_1286 . V_1283 ,
V_1272 -> V_1286 . V_1284 ,
V_1272 -> V_1286 . V_1285 ) ;
}
V_1275 = & V_1266 . V_133 [ V_94 ] [ V_133 ] ;
V_1276 = & V_1267 -> V_133 [ V_94 ] [ V_133 ] ;
if ( ! F_891 ( V_1275 , V_1276 ) ) {
F_127 ( L_222 ,
F_78 ( V_94 ) , V_133 + 1 ,
V_1276 -> V_1287 , V_1276 -> V_1288 ,
V_1275 -> V_1287 , V_1275 -> V_1288 ) ;
}
}
if ( V_81 -> V_1101 ) {
V_1272 = & V_1269 . V_1282 [ V_1289 ] ;
V_1273 = & V_1270 -> V_1282 [ V_1289 ] ;
for ( V_1277 = 0 ; V_1277 <= V_1278 ; V_1277 ++ ) {
if ( F_890 ( & V_1272 -> V_563 [ V_1277 ] ,
& V_1273 -> V_563 [ V_1277 ] ) )
continue;
F_127 ( L_223 ,
F_78 ( V_94 ) , V_1277 ,
V_1273 -> V_563 [ V_1277 ] . V_1283 ,
V_1273 -> V_563 [ V_1277 ] . V_1284 ,
V_1273 -> V_563 [ V_1277 ] . V_1285 ,
V_1272 -> V_563 [ V_1277 ] . V_1283 ,
V_1272 -> V_563 [ V_1277 ] . V_1284 ,
V_1272 -> V_563 [ V_1277 ] . V_1285 ) ;
}
if ( ! F_890 ( & V_1272 -> V_1286 ,
& V_1273 -> V_1286 ) ) {
F_127 ( L_224 ,
F_78 ( V_94 ) ,
V_1273 -> V_1286 . V_1283 ,
V_1273 -> V_1286 . V_1284 ,
V_1273 -> V_1286 . V_1285 ,
V_1272 -> V_1286 . V_1283 ,
V_1272 -> V_1286 . V_1284 ,
V_1272 -> V_1286 . V_1285 ) ;
}
V_1275 = & V_1266 . V_133 [ V_94 ] [ V_1289 ] ;
V_1276 = & V_1267 -> V_133 [ V_94 ] [ V_1289 ] ;
if ( ! F_891 ( V_1275 , V_1276 ) ) {
F_127 ( L_225 ,
F_78 ( V_94 ) ,
V_1276 -> V_1287 , V_1276 -> V_1288 ,
V_1275 -> V_1287 , V_1275 -> V_1288 ) ;
}
}
}
static void
F_892 ( struct V_62 * V_63 ,
struct V_421 * V_43 ,
struct V_145 * V_65 )
{
struct V_577 * V_718 ;
struct V_575 * V_576 ;
int V_135 ;
F_423 (state, connector, old_conn_state, i) {
struct V_618 * V_512 = V_718 -> V_512 ;
struct V_575 * V_43 = V_718 -> V_43 ;
if ( V_43 -> V_65 != V_65 )
continue;
F_550 ( F_854 ( V_718 ) ) ;
F_65 ( V_43 -> V_580 != V_512 ,
L_226 ) ;
}
}
static void
F_893 ( struct V_62 * V_63 )
{
struct V_511 * V_512 ;
struct V_717 * V_718 ;
F_662 (dev, encoder) {
bool V_146 = false ;
enum V_94 V_94 ;
F_161 ( L_227 ,
V_512 -> V_64 . V_64 . V_379 ,
V_512 -> V_64 . V_12 ) ;
F_849 (dev, connector) {
if ( V_718 -> V_64 . V_43 -> V_580 != & V_512 -> V_64 )
continue;
V_146 = true ;
F_65 ( V_718 -> V_64 . V_43 -> V_65 !=
V_512 -> V_64 . V_65 ,
L_228 ) ;
}
F_65 ( ! ! V_512 -> V_64 . V_65 != V_146 ,
L_229
L_230 ,
! ! V_512 -> V_64 . V_65 , V_146 ) ;
if ( ! V_512 -> V_64 . V_65 ) {
bool V_87 ;
V_87 = V_512 -> V_719 ( V_512 , & V_94 ) ;
F_65 ( V_87 ,
L_231 ,
F_78 ( V_94 ) ) ;
}
}
}
static void
F_894 ( struct V_145 * V_65 ,
struct V_42 * V_442 ,
struct V_42 * V_1290 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_511 * V_512 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_37 * V_38 , * V_1291 ;
struct V_421 * V_560 ;
bool V_87 ;
V_560 = V_442 -> V_43 ;
F_895 ( V_442 ) ;
V_38 = F_290 ( V_442 ) ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_38 -> V_64 . V_65 = V_65 ;
V_38 -> V_64 . V_43 = V_560 ;
F_161 ( L_232 , V_65 -> V_64 . V_379 , V_65 -> V_12 ) ;
V_87 = V_6 -> V_434 . V_1292 ( V_81 , V_38 ) ;
if ( ( V_81 -> V_94 == V_113 && V_6 -> V_129 & V_130 ) ||
( V_81 -> V_94 == V_120 && V_6 -> V_129 & V_131 ) )
V_87 = V_1290 -> V_87 ;
F_65 ( V_1290 -> V_87 != V_87 ,
L_233
L_230 , V_1290 -> V_87 , V_87 ) ;
F_65 ( V_81 -> V_87 != V_1290 -> V_87 ,
L_234
L_230 , V_1290 -> V_87 , V_81 -> V_87 ) ;
F_379 (dev, crtc, encoder) {
enum V_94 V_94 ;
V_87 = V_512 -> V_719 ( V_512 , & V_94 ) ;
F_65 ( V_87 != V_1290 -> V_87 ,
L_235 ,
V_512 -> V_64 . V_64 . V_379 , V_87 , V_1290 -> V_87 ) ;
F_65 ( V_87 && V_81 -> V_94 != V_94 ,
L_236 ,
F_78 ( V_94 ) ) ;
if ( V_87 ) {
V_38 -> V_1241 |= 1 << V_512 -> type ;
V_512 -> V_1293 ( V_512 , V_38 ) ;
}
}
if ( ! V_1290 -> V_87 )
return;
F_884 ( V_6 , V_38 ) ;
V_1291 = F_290 ( V_65 -> V_43 ) ;
if ( ! F_875 ( V_6 , V_1291 ,
V_38 , false ) ) {
F_65 ( 1 , L_237 ) ;
F_857 ( V_81 , V_38 ,
L_238 ) ;
F_857 ( V_81 , V_1291 ,
L_239 ) ;
}
}
static void
F_896 ( struct V_5 * V_6 ,
struct V_991 * V_992 ,
struct V_145 * V_65 ,
struct V_42 * V_1264 )
{
struct V_1237 V_174 ;
unsigned V_1294 ;
bool V_87 ;
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
F_161 ( L_240 , V_992 -> V_12 ) ;
V_87 = V_992 -> V_1010 . V_719 ( V_6 , V_992 , & V_174 ) ;
if ( ! ( V_992 -> V_330 & V_1295 ) ) {
F_65 ( ! V_992 -> V_1296 && V_992 -> V_1297 ,
L_241 ) ;
F_65 ( V_992 -> V_1296 && ! V_992 -> V_1297 ,
L_242 ) ;
F_65 ( V_992 -> V_1296 != V_87 ,
L_243 ,
V_992 -> V_1296 , V_87 ) ;
}
if ( ! V_65 ) {
F_65 ( V_992 -> V_1297 & ~ V_992 -> V_43 . V_1294 ,
L_244 ,
V_992 -> V_1297 , V_992 -> V_43 . V_1294 ) ;
return;
}
V_1294 = 1 << F_897 ( V_65 ) ;
if ( V_1264 -> V_87 )
F_65 ( ! ( V_992 -> V_1297 & V_1294 ) ,
L_245 ,
F_78 ( F_897 ( V_65 ) ) , V_992 -> V_1297 ) ;
else
F_65 ( V_992 -> V_1297 & V_1294 ,
L_246 ,
F_78 ( F_897 ( V_65 ) ) , V_992 -> V_1297 ) ;
F_65 ( ! ( V_992 -> V_43 . V_1294 & V_1294 ) ,
L_247 ,
V_1294 , V_992 -> V_43 . V_1294 ) ;
F_65 ( V_992 -> V_1296 && memcmp ( & V_992 -> V_43 . V_1298 ,
& V_174 ,
sizeof( V_174 ) ) ,
L_248 ) ;
}
static void
F_898 ( struct V_62 * V_63 , struct V_145 * V_65 ,
struct V_42 * V_442 ,
struct V_42 * V_1290 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_37 * V_560 = F_290 ( V_442 ) ;
struct V_37 * V_1264 = F_290 ( V_1290 ) ;
if ( V_1264 -> V_206 )
F_896 ( V_6 , V_1264 -> V_206 , V_65 , V_1290 ) ;
if ( V_560 -> V_206 &&
V_560 -> V_206 != V_1264 -> V_206 ) {
unsigned V_1294 = 1 << F_897 ( V_65 ) ;
struct V_991 * V_992 = V_560 -> V_206 ;
F_65 ( V_992 -> V_1297 & V_1294 ,
L_249 ,
F_78 ( F_897 ( V_65 ) ) ) ;
F_65 ( V_992 -> V_43 . V_1294 & V_1294 ,
L_250 ,
F_78 ( F_897 ( V_65 ) ) ) ;
}
}
static void
F_899 ( struct V_145 * V_65 ,
struct V_421 * V_43 ,
struct V_42 * V_560 ,
struct V_42 * V_1264 )
{
if ( ! F_25 ( V_1264 ) &&
! F_290 ( V_1264 ) -> V_1299 )
return;
F_885 ( V_65 , V_1264 ) ;
F_892 ( V_65 -> V_63 , V_43 , V_65 ) ;
F_894 ( V_65 , V_560 , V_1264 ) ;
F_898 ( V_65 -> V_63 , V_65 , V_560 , V_1264 ) ;
}
static void
F_900 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_135 ;
for ( V_135 = 0 ; V_135 < V_6 -> V_947 ; V_135 ++ )
F_896 ( V_6 , & V_6 -> V_1300 [ V_135 ] , NULL , NULL ) ;
}
static void
F_901 ( struct V_62 * V_63 ,
struct V_421 * V_43 )
{
F_893 ( V_63 ) ;
F_892 ( V_63 , V_43 , NULL ) ;
F_900 ( V_63 ) ;
}
static void F_902 ( struct V_81 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
if ( F_56 ( V_6 ) ) {
const struct V_520 * V_91 = & V_65 -> V_90 -> V_64 . V_91 ;
int V_893 ;
V_893 = V_91 -> V_877 ;
if ( V_91 -> V_330 & V_880 )
V_893 /= 2 ;
V_65 -> V_225 = V_893 - 1 ;
} else if ( F_23 ( V_6 ) &&
F_38 ( V_65 -> V_90 , V_209 ) ) {
V_65 -> V_225 = 2 ;
} else
V_65 -> V_225 = 1 ;
}
static void F_903 ( struct V_421 * V_43 )
{
struct V_62 * V_63 = V_43 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_145 * V_65 ;
struct V_42 * V_60 ;
int V_135 ;
if ( ! V_6 -> V_434 . V_1218 )
return;
F_294 (state, crtc, crtc_state, i) {
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_991 * V_1301 =
F_290 ( V_65 -> V_43 ) -> V_206 ;
if ( ! F_25 ( V_60 ) )
continue;
F_290 ( V_60 ) -> V_206 = NULL ;
if ( ! V_1301 )
continue;
F_904 ( V_1301 , V_81 , V_43 ) ;
}
}
static int F_905 ( struct V_421 * V_43 )
{
struct V_42 * V_60 ;
struct V_81 * V_81 ;
struct V_145 * V_65 ;
struct V_37 * V_1302 = NULL ;
struct V_37 * V_723 = NULL ;
enum V_94 V_1303 = V_592 , V_1304 = V_592 ;
int V_135 ;
F_294 (state, crtc, crtc_state, i) {
V_81 = F_48 ( V_65 ) ;
if ( ! V_60 -> V_87 || ! F_25 ( V_60 ) )
continue;
if ( V_1302 ) {
V_723 = F_290 ( V_60 ) ;
break;
} else {
V_1302 = F_290 ( V_60 ) ;
V_1303 = V_81 -> V_94 ;
}
}
if ( ! V_1302 )
return 0 ;
F_138 (state->dev, intel_crtc) {
struct V_37 * V_38 ;
V_38 = F_540 ( V_43 , V_81 ) ;
if ( F_194 ( V_38 ) )
return F_241 ( V_38 ) ;
V_38 -> V_588 = V_592 ;
if ( ! V_38 -> V_64 . V_87 ||
F_25 ( & V_38 -> V_64 ) )
continue;
if ( V_1304 != V_592 )
return 0 ;
V_1304 = V_81 -> V_94 ;
}
if ( V_1304 != V_592 )
V_1302 -> V_588 = V_1304 ;
else if ( V_723 )
V_723 -> V_588 = V_1303 ;
return 0 ;
}
static int F_906 ( struct V_421 * V_43 )
{
struct V_145 * V_65 ;
F_237 (state->dev, crtc) {
struct V_42 * V_60 ;
V_60 = F_763 ( V_43 , V_65 ) ;
if ( F_194 ( V_60 ) )
return F_241 ( V_60 ) ;
}
return 0 ;
}
static int F_907 ( struct V_421 * V_43 )
{
struct V_145 * V_65 ;
F_237 (state->dev, crtc) {
struct V_42 * V_60 ;
int V_362 ;
V_60 = F_763 ( V_43 , V_65 ) ;
if ( F_194 ( V_60 ) )
return F_241 ( V_60 ) ;
if ( ! V_60 -> V_87 || F_25 ( V_60 ) )
continue;
V_60 -> V_422 = true ;
V_362 = F_541 ( V_43 , V_65 ) ;
if ( V_362 )
return V_362 ;
V_362 = F_908 ( V_43 , V_65 ) ;
if ( V_362 )
return V_362 ;
}
return 0 ;
}
static int F_909 ( struct V_421 * V_43 )
{
struct V_569 * V_338 = F_295 ( V_43 ) ;
struct V_5 * V_6 = F_41 ( V_43 -> V_63 ) ;
struct V_145 * V_65 ;
struct V_42 * V_60 ;
int V_362 = 0 , V_135 ;
if ( ! F_864 ( V_43 ) ) {
F_161 ( L_251 ) ;
return - V_288 ;
}
V_338 -> V_568 = true ;
V_338 -> V_702 = V_6 -> V_702 ;
F_294 (state, crtc, crtc_state, i) {
if ( V_60 -> V_87 )
V_338 -> V_702 |= 1 << V_135 ;
else
V_338 -> V_702 &= ~ ( 1 << V_135 ) ;
if ( V_60 -> V_87 != V_65 -> V_43 -> V_87 )
V_338 -> V_1305 |= F_910 ( V_65 ) ;
}
if ( V_6 -> V_434 . V_1306 ) {
if ( ! V_338 -> V_1052 )
V_338 -> V_1052 = V_6 -> V_640 . V_52 ;
if ( ! V_338 -> V_1052 )
V_338 -> V_1052 = V_6 -> V_631 ;
V_362 = V_6 -> V_434 . V_1306 ( V_43 ) ;
if ( V_362 < 0 )
return V_362 ;
if ( V_338 -> V_643 != V_6 -> V_1307 ) {
V_362 = F_906 ( V_43 ) ;
if ( V_362 < 0 )
return V_362 ;
}
if ( V_338 -> V_701 != V_6 -> V_637 ||
V_338 -> V_1052 != V_6 -> V_640 . V_52 ) {
V_362 = F_907 ( V_43 ) ;
if ( V_362 < 0 )
return V_362 ;
}
F_161 ( L_252 ,
V_338 -> V_643 , V_338 -> V_701 ) ;
} else {
F_295 ( V_43 ) -> V_643 = V_6 -> V_1307 ;
}
F_903 ( V_43 ) ;
if ( F_264 ( V_6 ) )
return F_905 ( V_43 ) ;
return 0 ;
}
static int F_911 ( struct V_421 * V_43 )
{
struct V_62 * V_63 = V_43 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
if ( V_6 -> V_434 . V_1308 )
return V_6 -> V_434 . V_1308 ( V_43 ) ;
return 0 ;
}
static int F_912 ( struct V_62 * V_63 ,
struct V_421 * V_43 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_569 * V_338 = F_295 ( V_43 ) ;
struct V_145 * V_65 ;
struct V_42 * V_60 ;
int V_362 , V_135 ;
bool V_1309 = false ;
V_362 = F_913 ( V_63 , V_43 ) ;
if ( V_362 )
return V_362 ;
F_294 (state, crtc, crtc_state, i) {
struct V_37 * V_38 =
F_290 ( V_60 ) ;
if ( V_60 -> V_417 . V_1310 != V_65 -> V_43 -> V_417 . V_1310 )
V_60 -> V_422 = true ;
if ( ! F_25 ( V_60 ) )
continue;
if ( ! V_60 -> V_507 ) {
V_1309 = true ;
continue;
}
V_362 = F_541 ( V_43 , V_65 ) ;
if ( V_362 )
return V_362 ;
V_362 = F_868 ( V_65 , V_38 ) ;
if ( V_362 ) {
F_857 ( F_48 ( V_65 ) ,
V_38 , L_253 ) ;
return V_362 ;
}
if ( V_259 . V_1311 &&
F_875 ( V_6 ,
F_290 ( V_65 -> V_43 ) ,
V_38 , true ) ) {
V_60 -> V_422 = false ;
F_290 ( V_60 ) -> V_1299 = true ;
}
if ( F_25 ( V_60 ) )
V_1309 = true ;
V_362 = F_908 ( V_43 , V_65 ) ;
if ( V_362 )
return V_362 ;
F_857 ( F_48 ( V_65 ) , V_38 ,
F_25 ( V_60 ) ?
L_254 : L_255 ) ;
}
if ( V_1309 ) {
V_362 = F_909 ( V_43 ) ;
if ( V_362 )
return V_362 ;
} else {
V_338 -> V_643 = V_6 -> V_1307 ;
}
V_362 = F_914 ( V_63 , V_43 ) ;
if ( V_362 )
return V_362 ;
F_915 ( V_6 , V_43 ) ;
return F_911 ( V_43 ) ;
}
static int F_916 ( struct V_62 * V_63 ,
struct V_421 * V_43 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_42 * V_60 ;
struct V_145 * V_65 ;
int V_135 , V_362 ;
F_294 (state, crtc, crtc_state, i) {
if ( V_43 -> V_1312 )
continue;
V_362 = F_348 ( V_65 ) ;
if ( V_362 )
return V_362 ;
if ( F_341 ( & F_48 ( V_65 ) -> V_477 ) >= 2 )
F_825 ( V_6 -> V_481 ) ;
}
V_362 = F_917 ( & V_63 -> V_256 ) ;
if ( V_362 )
return V_362 ;
V_362 = F_918 ( V_63 , V_43 ) ;
F_5 ( & V_63 -> V_256 ) ;
return V_362 ;
}
T_1 F_783 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
if ( ! V_63 -> V_224 )
return F_919 ( & V_65 -> V_64 ) ;
return V_63 -> V_1313 -> V_1314 ( V_63 , V_65 -> V_94 ) ;
}
static void F_920 ( struct V_62 * V_63 ,
struct V_5 * V_6 ,
unsigned V_1294 )
{
unsigned V_1315 [ V_1316 ] ;
enum V_94 V_94 ;
int V_362 ;
if ( ! V_1294 )
return;
F_91 (dev_priv, pipe) {
struct V_81 * V_65 = F_53 ( V_6 ,
V_94 ) ;
if ( ! ( ( 1 << V_94 ) & V_1294 ) )
continue;
V_362 = F_101 ( & V_65 -> V_64 ) ;
if ( F_28 ( V_362 != 0 ) ) {
V_1294 &= ~ ( 1 << V_94 ) ;
continue;
}
V_1315 [ V_94 ] = F_921 ( & V_65 -> V_64 ) ;
}
F_91 (dev_priv, pipe) {
struct V_81 * V_65 = F_53 ( V_6 ,
V_94 ) ;
long V_1317 ;
if ( ! ( ( 1 << V_94 ) & V_1294 ) )
continue;
V_1317 = F_922 ( V_63 -> V_1183 [ V_94 ] . V_1318 ,
V_1315 [ V_94 ] !=
F_921 ( & V_65 -> V_64 ) ,
F_923 ( 50 ) ) ;
F_7 ( ! V_1317 , L_256 , F_78 ( V_94 ) ) ;
F_102 ( & V_65 -> V_64 ) ;
}
}
static bool F_924 ( struct V_37 * V_60 )
{
if ( V_60 -> V_1212 )
return true ;
if ( V_60 -> V_565 )
return true ;
if ( V_60 -> V_571 )
return true ;
return false ;
}
static void F_925 ( struct V_145 * V_65 ,
struct V_421 * V_43 ,
struct V_42 * V_442 ,
unsigned int * V_1319 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_37 * V_38 = F_290 ( V_65 -> V_43 ) ;
bool V_568 = F_25 ( V_65 -> V_43 ) ;
if ( V_568 ) {
F_902 ( V_81 ) ;
V_6 -> V_434 . V_1320 ( V_38 , V_43 ) ;
} else {
F_416 ( F_290 ( V_442 ) ) ;
}
if ( F_412 ( V_43 , V_65 -> V_88 ) ) {
F_926 (
V_81 , V_38 ,
F_235 ( V_65 -> V_88 -> V_43 ) ) ;
}
F_927 ( V_442 ) ;
if ( F_924 ( V_38 ) )
* V_1319 |= F_910 ( V_65 ) ;
}
static void F_928 ( struct V_421 * V_43 ,
unsigned int * V_1319 )
{
struct V_145 * V_65 ;
struct V_42 * V_442 ;
int V_135 ;
F_294 (state, crtc, old_crtc_state, i) {
if ( ! V_65 -> V_43 -> V_87 )
continue;
F_925 ( V_65 , V_43 , V_442 ,
V_1319 ) ;
}
}
static void F_929 ( struct V_421 * V_43 ,
unsigned int * V_1319 )
{
struct V_5 * V_6 = F_41 ( V_43 -> V_63 ) ;
struct V_569 * V_338 = F_295 ( V_43 ) ;
struct V_145 * V_65 ;
struct V_81 * V_81 ;
struct V_42 * V_442 ;
struct V_37 * V_1043 ;
unsigned int V_1321 = 0 ;
bool V_1322 ;
enum V_94 V_94 ;
int V_135 ;
const struct V_1274 * V_1323 [ V_1316 ] = {} ;
F_294 (state, crtc, old_crtc_state, i)
if ( V_65 -> V_43 -> V_87 )
V_1323 [ V_135 ] = & F_290 ( V_442 ) -> V_563 . V_1279 . V_1281 ;
do {
V_1322 = false ;
F_294 (state, crtc, old_crtc_state, i) {
bool V_1324 = false ;
unsigned int V_1325 = F_910 ( V_65 ) ;
V_81 = F_48 ( V_65 ) ;
V_1043 = F_290 ( V_65 -> V_43 ) ;
V_94 = V_81 -> V_94 ;
if ( V_1321 & V_1325 || ! V_1043 -> V_64 . V_87 )
continue;
if ( F_930 ( V_1323 , & V_1043 -> V_563 . V_1279 . V_1281 , V_135 ) )
continue;
V_1321 |= V_1325 ;
V_1323 [ V_135 ] = & V_1043 -> V_563 . V_1279 . V_1281 ;
if ( ! F_891 ( & V_1043 -> V_563 . V_1279 . V_1281 ,
& F_290 ( V_442 ) -> V_563 . V_1279 . V_1281 ) &&
! V_65 -> V_43 -> V_1326 &&
V_338 -> V_1327 . V_1328 != V_1321 )
V_1324 = true ;
F_925 ( V_65 , V_43 , V_442 ,
V_1319 ) ;
if ( V_1324 )
F_342 ( V_6 , V_94 ) ;
V_1322 = true ;
}
} while ( V_1322 );
}
static void F_931 ( struct V_5 * V_6 )
{
struct V_569 * V_43 , * V_1329 ;
struct V_1330 * V_1331 ;
V_1331 = F_932 ( & V_6 -> V_1332 . V_1333 ) ;
F_933 (state, next, freed, freed)
F_305 ( & V_43 -> V_64 ) ;
}
static void F_934 ( struct V_1138 * V_2 )
{
struct V_5 * V_6 =
F_773 ( V_2 , F_935 ( * V_6 ) , V_1332 . V_1191 ) ;
F_931 ( V_6 ) ;
}
static void F_936 ( struct V_421 * V_43 )
{
struct V_62 * V_63 = V_43 -> V_63 ;
struct V_569 * V_338 = F_295 ( V_43 ) ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_42 * V_442 ;
struct V_145 * V_65 ;
struct V_37 * V_1334 ;
bool V_1335 = V_338 -> V_568 ;
unsigned long V_1336 [ V_1316 ] = {} ;
unsigned V_1319 = 0 ;
int V_135 ;
F_937 ( V_43 ) ;
if ( V_338 -> V_568 )
F_472 ( V_6 , V_1337 ) ;
F_294 (state, crtc, old_crtc_state, i) {
struct V_81 * V_81 = F_48 ( V_65 ) ;
if ( F_25 ( V_65 -> V_43 ) ||
F_290 ( V_65 -> V_43 ) -> V_1299 ) {
V_1335 = true ;
V_1336 [ F_48 ( V_65 ) -> V_94 ] =
F_470 ( V_65 ,
F_290 ( V_65 -> V_43 ) ) ;
}
if ( ! F_25 ( V_65 -> V_43 ) )
continue;
F_416 ( F_290 ( V_442 ) ) ;
if ( V_442 -> V_87 ) {
F_419 ( V_65 , V_442 -> V_341 ) ;
V_6 -> V_434 . V_714 ( F_290 ( V_442 ) , V_43 ) ;
V_81 -> V_87 = false ;
F_543 ( V_81 ) ;
F_544 ( V_81 ) ;
F_407 ( V_6 ) ;
F_408 ( V_6 ) ;
if ( ! V_65 -> V_43 -> V_87 ) {
if ( V_6 -> V_434 . V_1338 )
V_6 -> V_434 . V_573 ( V_338 ,
F_290 ( V_65 -> V_43 ) ) ;
else
F_414 ( V_81 ) ;
}
}
}
F_870 ( V_43 ) ;
if ( V_338 -> V_568 ) {
F_938 ( V_43 -> V_63 , V_43 ) ;
if ( V_6 -> V_434 . V_1339 &&
( V_338 -> V_701 != V_6 -> V_637 ||
V_338 -> V_1052 != V_6 -> V_640 . V_52 ) )
V_6 -> V_434 . V_1339 ( V_43 ) ;
if ( ! F_939 ( V_43 ) )
F_940 ( V_6 ) ;
F_901 ( V_63 , V_43 ) ;
}
F_294 (state, crtc, old_crtc_state, i) {
bool V_568 = F_25 ( V_65 -> V_43 ) ;
if ( V_568 && ! V_65 -> V_43 -> V_87 && V_65 -> V_43 -> V_478 ) {
F_311 ( & V_63 -> V_440 ) ;
F_344 ( V_65 , V_65 -> V_43 -> V_478 ) ;
F_312 ( & V_63 -> V_440 ) ;
V_65 -> V_43 -> V_478 = NULL ;
}
}
V_6 -> V_434 . V_1340 ( V_43 , & V_1319 ) ;
if ( ! V_43 -> V_1312 )
F_920 ( V_63 , V_6 , V_1319 ) ;
F_294 (state, crtc, old_crtc_state, i) {
V_1334 = F_290 ( V_65 -> V_43 ) ;
if ( V_6 -> V_434 . V_1213 )
V_6 -> V_434 . V_1213 ( V_338 ,
V_1334 ) ;
}
F_294 (state, crtc, old_crtc_state, i) {
F_411 ( F_290 ( V_442 ) ) ;
if ( V_1336 [ V_135 ] )
F_473 ( V_6 , V_1336 [ V_135 ] ) ;
F_899 ( V_65 , V_43 , V_442 , V_65 -> V_43 ) ;
}
if ( V_338 -> V_568 && F_939 ( V_43 ) )
F_941 ( V_6 ) ;
F_942 ( V_43 ) ;
if ( V_338 -> V_568 )
F_86 ( V_6 , V_1337 ) ;
F_3 ( & V_63 -> V_256 ) ;
F_943 ( V_63 , V_43 ) ;
F_5 ( & V_63 -> V_256 ) ;
F_944 ( V_43 ) ;
F_305 ( V_43 ) ;
F_945 ( V_6 ) ;
F_931 ( V_6 ) ;
}
static void F_946 ( struct V_1138 * V_2 )
{
struct V_421 * V_43 =
F_773 ( V_2 , struct V_421 , V_1341 ) ;
F_936 ( V_43 ) ;
}
static int T_9
F_947 ( struct V_1342 * V_1343 ,
enum V_1344 V_1345 )
{
struct V_569 * V_43 =
F_773 ( V_1343 , struct V_569 , V_1346 ) ;
switch ( V_1345 ) {
case V_1347 :
if ( V_43 -> V_64 . V_1341 . V_4 )
F_347 ( V_1197 , & V_43 -> V_64 . V_1341 ) ;
break;
case V_1348 :
{
struct V_1349 * V_1350 =
& F_41 ( V_43 -> V_64 . V_63 ) -> V_1332 ;
if ( F_948 ( & V_43 -> V_1331 , & V_1350 -> V_1333 ) )
F_949 ( & V_1350 -> V_1191 ) ;
break;
}
}
return V_1351 ;
}
static void F_950 ( struct V_421 * V_43 )
{
struct V_335 * V_1205 ;
struct V_333 * V_133 ;
int V_135 ;
F_951 (state, plane, old_plane_state, i)
F_834 ( F_189 ( V_1205 -> V_89 ) ,
F_189 ( V_133 -> V_43 -> V_89 ) ,
F_234 ( V_133 ) -> V_354 ) ;
}
static int F_952 ( struct V_62 * V_63 ,
struct V_421 * V_43 ,
bool V_1352 )
{
struct V_569 * V_338 = F_295 ( V_43 ) ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
int V_362 = 0 ;
V_362 = F_953 ( V_43 , V_1352 ) ;
if ( V_362 )
return V_362 ;
F_954 ( V_43 ) ;
F_955 ( & V_338 -> V_1346 ,
F_947 ) ;
V_362 = F_916 ( V_63 , V_43 ) ;
if ( V_362 ) {
F_842 ( L_257 , V_362 ) ;
F_956 ( & V_338 -> V_1346 ) ;
return V_362 ;
}
F_957 ( V_43 , true ) ;
V_6 -> V_563 . V_1353 = false ;
F_958 ( V_43 ) ;
F_950 ( V_43 ) ;
if ( V_338 -> V_568 ) {
memcpy ( V_6 -> V_699 , V_338 -> V_699 ,
sizeof( V_338 -> V_699 ) ) ;
V_6 -> V_702 = V_338 -> V_702 ;
V_6 -> V_1307 = V_338 -> V_643 ;
}
F_954 ( V_43 ) ;
F_824 ( & V_43 -> V_1341 ,
V_1352 ? F_946 : NULL ) ;
F_956 ( & V_338 -> V_1346 ) ;
if ( ! V_1352 ) {
F_959 ( & V_338 -> V_1346 ) ;
F_936 ( V_43 ) ;
}
return 0 ;
}
void F_960 ( struct V_145 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_421 * V_43 ;
struct V_42 * V_60 ;
int V_362 ;
V_43 = F_539 ( V_63 ) ;
if ( ! V_43 ) {
F_161 ( L_258 ,
V_65 -> V_64 . V_379 , V_65 -> V_12 ) ;
return;
}
V_43 -> V_432 = F_837 ( V_65 ) ;
V_462:
V_60 = F_763 ( V_43 , V_65 ) ;
V_362 = F_547 ( V_60 ) ;
if ( ! V_362 ) {
if ( ! V_60 -> V_87 )
goto V_936;
V_60 -> V_422 = true ;
V_362 = F_296 ( V_43 ) ;
}
if ( V_362 == - V_424 ) {
F_838 ( V_43 ) ;
F_302 ( V_43 -> V_432 ) ;
goto V_462;
}
V_936:
F_305 ( V_43 ) ;
}
static int F_961 ( struct V_145 * V_65 ,
T_4 * V_1354 , T_4 * V_1355 , T_4 * V_1356 ,
T_2 V_241 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_1110 * V_90 = & V_63 -> V_428 ;
struct V_42 * V_43 ;
int V_362 ;
V_362 = F_962 ( V_65 , V_1354 , V_1355 , V_1356 , V_241 ) ;
if ( V_362 )
return V_362 ;
V_43 = V_65 -> V_43 ;
F_963 ( & V_65 -> V_64 ,
V_90 -> V_1357 ,
( V_43 -> V_1358 ) ?
V_43 -> V_1358 -> V_64 . V_379 : 0 ) ;
F_963 ( & V_65 -> V_64 ,
V_90 -> V_1359 ,
( V_43 -> V_1360 ) ?
V_43 -> V_1360 -> V_64 . V_379 : 0 ) ;
F_963 ( & V_65 -> V_64 ,
V_90 -> V_1361 ,
( V_43 -> V_1362 ) ?
V_43 -> V_1362 -> V_64 . V_379 : 0 ) ;
return 0 ;
}
int
F_964 ( struct V_333 * V_133 ,
struct V_335 * V_1264 )
{
struct V_569 * V_338 =
F_295 ( V_1264 -> V_43 ) ;
struct V_5 * V_6 = F_41 ( V_133 -> V_63 ) ;
struct V_245 * V_89 = V_1264 -> V_89 ;
struct V_252 * V_253 = F_189 ( V_89 ) ;
struct V_252 * V_1363 = F_189 ( V_133 -> V_43 -> V_89 ) ;
int V_362 ;
if ( ! V_253 && ! V_1363 )
return 0 ;
if ( V_1363 ) {
struct V_42 * V_60 =
F_965 ( V_1264 -> V_43 ,
V_133 -> V_43 -> V_65 ) ;
if ( F_25 ( V_60 ) ) {
V_362 = F_966 ( & V_338 -> V_1346 ,
V_1363 -> V_1364 , NULL ,
false , 0 ,
V_721 ) ;
if ( V_362 < 0 )
return V_362 ;
}
}
if ( V_1264 -> V_1343 ) {
V_362 = F_967 ( & V_338 -> V_1346 ,
V_1264 -> V_1343 ,
V_1365 ,
V_721 ) ;
if ( V_362 < 0 )
return V_362 ;
}
if ( ! V_253 )
return 0 ;
if ( ! V_1264 -> V_1343 ) {
V_362 = F_966 ( & V_338 -> V_1346 ,
V_253 -> V_1364 , NULL ,
false , V_1365 ,
V_721 ) ;
if ( V_362 < 0 )
return V_362 ;
F_833 ( V_253 , 0 , V_1202 ) ;
}
if ( V_133 -> type == V_1211 &&
F_184 ( V_6 ) -> V_1366 ) {
int V_1367 = F_141 ( V_6 ) ? 16 * 1024 : 256 ;
V_362 = F_968 ( V_253 , V_1367 ) ;
if ( V_362 ) {
F_161 ( L_259 ) ;
return V_362 ;
}
} else {
struct V_251 * V_254 ;
V_254 = F_188 ( V_89 , V_1264 -> V_246 ) ;
if ( F_194 ( V_254 ) ) {
F_161 ( L_260 ) ;
return F_241 ( V_254 ) ;
}
F_235 ( V_1264 ) -> V_254 = V_254 ;
}
return 0 ;
}
void
F_969 ( struct V_333 * V_133 ,
struct V_335 * V_560 )
{
struct V_251 * V_254 ;
V_254 = F_970 ( & F_235 ( V_560 ) -> V_254 ) ;
if ( V_254 )
F_200 ( V_254 ) ;
}
int
F_971 ( struct V_81 * V_81 , struct V_37 * V_60 )
{
int V_1368 ;
int V_92 , V_643 ;
if ( ! V_81 || ! V_60 -> V_64 . V_507 )
return V_1369 ;
V_92 = V_60 -> V_64 . V_91 . V_92 ;
V_643 = F_295 ( V_60 -> V_64 . V_43 ) -> V_643 ;
if ( F_45 ( ! V_92 || V_643 < V_92 ) )
return V_1369 ;
V_1368 = V_58 ( ( 1 << 16 ) * 3 - 1 , ( 1 << 8 ) * ( ( V_643 << 8 ) / V_92 ) ) ;
return V_1368 ;
}
static int
F_972 ( struct V_333 * V_133 ,
struct V_37 * V_60 ,
struct V_265 * V_43 )
{
struct V_5 * V_6 = F_41 ( V_133 -> V_63 ) ;
struct V_145 * V_65 = V_43 -> V_64 . V_65 ;
int V_1370 = V_1369 ;
int V_1368 = V_1369 ;
bool V_1371 = false ;
int V_362 ;
if ( F_59 ( V_6 ) >= 9 ) {
if ( V_43 -> V_545 . V_330 == V_546 ) {
V_1370 = 1 ;
V_1368 = F_971 ( F_48 ( V_65 ) , V_60 ) ;
}
V_1371 = true ;
}
V_362 = F_973 ( & V_43 -> V_64 ,
& V_43 -> V_1372 ,
V_1370 , V_1368 ,
V_1371 , true ) ;
if ( V_362 )
return V_362 ;
if ( ! V_43 -> V_64 . V_89 )
return 0 ;
if ( F_59 ( V_6 ) >= 9 ) {
V_362 = F_250 ( V_43 ) ;
if ( V_362 )
return V_362 ;
}
return 0 ;
}
static void F_974 ( struct V_145 * V_65 ,
struct V_42 * V_442 )
{
struct V_62 * V_63 = V_65 -> V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_37 * V_1334 =
F_290 ( V_65 -> V_43 ) ;
struct V_37 * V_1373 =
F_290 ( V_442 ) ;
struct V_569 * V_570 =
F_295 ( V_442 -> V_43 ) ;
bool V_568 = F_25 ( V_65 -> V_43 ) ;
if ( ! V_568 &&
( V_1334 -> V_64 . V_1219 ||
V_1334 -> V_1299 ) ) {
F_448 ( V_65 -> V_43 ) ;
F_439 ( V_65 -> V_43 ) ;
}
F_811 ( V_81 ) ;
if ( V_568 )
goto V_936;
if ( V_1334 -> V_1299 )
F_320 ( V_81 , V_1373 ) ;
else if ( F_59 ( V_6 ) >= 9 )
F_272 ( V_81 ) ;
V_936:
if ( V_6 -> V_434 . V_1338 )
V_6 -> V_434 . V_1338 ( V_570 ,
V_1334 ) ;
}
static void F_975 ( struct V_145 * V_65 ,
struct V_42 * V_442 )
{
struct V_81 * V_81 = F_48 ( V_65 ) ;
F_812 ( V_81 , NULL ) ;
}
void F_976 ( struct V_333 * V_133 )
{
F_977 ( V_133 ) ;
F_236 ( F_234 ( V_133 ) ) ;
}
static int
F_978 ( struct V_333 * V_133 ,
struct V_145 * V_65 ,
struct V_245 * V_89 ,
int V_347 , int V_348 ,
unsigned int V_349 , unsigned int V_350 ,
T_2 V_343 , T_2 V_344 ,
T_2 V_345 , T_2 V_346 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_63 ) ;
int V_362 ;
struct V_335 * V_1205 , * V_1374 ;
struct V_337 * V_337 = F_234 ( V_133 ) ;
struct V_245 * V_1142 ;
struct V_42 * V_60 = V_65 -> V_43 ;
struct V_251 * V_1140 ;
if ( ! V_60 -> V_87 || F_25 ( V_60 ) ||
F_290 ( V_60 ) -> V_1299 )
goto V_1375;
V_1205 = V_133 -> V_43 ;
if ( V_1205 -> V_65 != V_65 ||
V_1205 -> V_345 != V_345 ||
V_1205 -> V_346 != V_346 ||
V_1205 -> V_349 != V_349 ||
V_1205 -> V_350 != V_350 ||
! V_1205 -> V_340 ||
V_1205 -> V_89 -> V_257 != V_89 -> V_257 )
goto V_1375;
V_1374 = F_979 ( V_133 ) ;
if ( ! V_1374 )
return - V_720 ;
F_756 ( V_1374 , V_89 ) ;
V_1374 -> V_343 = V_343 ;
V_1374 -> V_344 = V_344 ;
V_1374 -> V_345 = V_345 ;
V_1374 -> V_346 = V_346 ;
V_1374 -> V_347 = V_347 ;
V_1374 -> V_348 = V_348 ;
V_1374 -> V_349 = V_349 ;
V_1374 -> V_350 = V_350 ;
V_362 = F_980 ( F_290 ( V_65 -> V_43 ) ,
F_235 ( V_1374 ) ) ;
if ( V_362 )
goto V_1376;
if ( ! V_1374 -> V_340 )
goto V_1377;
V_362 = F_917 ( & V_6 -> V_260 . V_256 ) ;
if ( V_362 )
goto V_1376;
if ( F_184 ( V_6 ) -> V_1366 ) {
int V_1367 = F_141 ( V_6 ) ? 16 * 1024 : 256 ;
V_362 = F_968 ( F_189 ( V_89 ) , V_1367 ) ;
if ( V_362 ) {
F_161 ( L_259 ) ;
goto V_1378;
}
} else {
struct V_251 * V_254 ;
V_254 = F_188 ( V_89 , V_1374 -> V_246 ) ;
if ( F_194 ( V_254 ) ) {
F_161 ( L_260 ) ;
V_362 = F_241 ( V_254 ) ;
goto V_1378;
}
F_235 ( V_1374 ) -> V_254 = V_254 ;
}
V_1142 = V_1205 -> V_89 ;
V_1140 = F_235 ( V_1205 ) -> V_254 ;
F_834 ( F_189 ( V_1142 ) , F_189 ( V_89 ) ,
V_337 -> V_354 ) ;
V_1374 -> V_1343 = V_1205 -> V_1343 ;
* F_235 ( V_1205 ) = * F_235 ( V_1374 ) ;
V_1374 -> V_1343 = NULL ;
V_1374 -> V_89 = V_1142 ;
F_235 ( V_1374 ) -> V_254 = V_1140 ;
V_337 -> V_420 ( V_133 ,
F_290 ( V_65 -> V_43 ) ,
F_235 ( V_133 -> V_43 ) ) ;
F_969 ( V_133 , V_1374 ) ;
V_1378:
F_5 ( & V_6 -> V_260 . V_256 ) ;
V_1376:
F_981 ( V_133 , V_1374 ) ;
return V_362 ;
V_1377:
F_981 ( V_133 , V_1374 ) ;
V_1375:
return F_982 ( V_133 , V_65 , V_89 ,
V_347 , V_348 , V_349 , V_350 ,
V_343 , V_344 , V_345 , V_346 ) ;
}
static struct V_337 *
F_983 ( struct V_5 * V_6 , enum V_94 V_94 )
{
struct V_337 * V_88 = NULL ;
struct V_265 * V_43 = NULL ;
const T_2 * V_1379 ;
unsigned int V_1380 ;
unsigned int V_1381 ;
int V_362 ;
V_88 = F_554 ( sizeof( * V_88 ) , V_721 ) ;
if ( ! V_88 ) {
V_362 = - V_720 ;
goto V_783;
}
V_43 = F_984 ( & V_88 -> V_64 ) ;
if ( ! V_43 ) {
V_362 = - V_720 ;
goto V_783;
}
V_88 -> V_64 . V_43 = & V_43 -> V_64 ;
V_88 -> V_1382 = false ;
V_88 -> V_1383 = 1 ;
if ( F_59 ( V_6 ) >= 9 ) {
V_88 -> V_1382 = true ;
V_43 -> V_407 = - 1 ;
}
V_88 -> V_94 = V_94 ;
if ( F_985 ( V_6 ) && F_59 ( V_6 ) < 4 )
V_88 -> V_133 = (enum V_133 ) ! V_94 ;
else
V_88 -> V_133 = (enum V_133 ) V_94 ;
V_88 -> V_379 = V_1384 ;
V_88 -> V_354 = F_986 ( V_94 ) ;
V_88 -> V_1385 = F_972 ;
if ( F_59 ( V_6 ) >= 9 ) {
V_1379 = V_1386 ;
V_1381 = F_179 ( V_1386 ) ;
V_88 -> V_420 = F_277 ;
V_88 -> V_342 = F_285 ;
} else if ( F_15 ( V_6 ) ) {
V_1379 = V_1387 ;
V_1381 = F_179 ( V_1387 ) ;
V_88 -> V_420 = F_263 ;
V_88 -> V_342 = F_262 ;
} else if ( F_59 ( V_6 ) >= 4 ) {
V_1379 = V_1387 ;
V_1381 = F_179 ( V_1387 ) ;
V_88 -> V_420 = F_251 ;
V_88 -> V_342 = F_262 ;
} else {
V_1379 = V_1388 ;
V_1381 = F_179 ( V_1388 ) ;
V_88 -> V_420 = F_251 ;
V_88 -> V_342 = F_262 ;
}
if ( F_59 ( V_6 ) >= 9 )
V_362 = F_987 ( & V_6 -> V_260 , & V_88 -> V_64 ,
0 , & V_1389 ,
V_1379 , V_1381 ,
V_1390 ,
L_261 , F_78 ( V_94 ) ) ;
else if ( F_59 ( V_6 ) >= 5 || F_18 ( V_6 ) )
V_362 = F_987 ( & V_6 -> V_260 , & V_88 -> V_64 ,
0 , & V_1389 ,
V_1379 , V_1381 ,
V_1390 ,
L_262 , F_78 ( V_94 ) ) ;
else
V_362 = F_987 ( & V_6 -> V_260 , & V_88 -> V_64 ,
0 , & V_1389 ,
V_1379 , V_1381 ,
V_1390 ,
L_263 , F_89 ( V_88 -> V_133 ) ) ;
if ( V_362 )
goto V_783;
if ( F_59 ( V_6 ) >= 9 ) {
V_1380 =
V_289 | V_400 |
V_370 | V_296 ;
} else if ( F_17 ( V_6 ) && V_94 == V_120 ) {
V_1380 =
V_289 | V_370 |
V_372 ;
} else if ( F_59 ( V_6 ) >= 4 ) {
V_1380 =
V_289 | V_370 ;
} else {
V_1380 = V_289 ;
}
if ( F_59 ( V_6 ) >= 4 )
F_988 ( & V_88 -> V_64 ,
V_289 ,
V_1380 ) ;
F_989 ( & V_88 -> V_64 , & V_1391 ) ;
return V_88 ;
V_783:
F_236 ( V_43 ) ;
F_236 ( V_88 ) ;
return F_740 ( V_362 ) ;
}
static int
F_990 ( struct V_333 * V_133 ,
struct V_37 * V_60 ,
struct V_265 * V_43 )
{
struct V_245 * V_89 = V_43 -> V_64 . V_89 ;
struct V_252 * V_253 = F_189 ( V_89 ) ;
enum V_94 V_94 = F_234 ( V_133 ) -> V_94 ;
unsigned V_292 ;
int V_362 ;
V_362 = F_973 ( & V_43 -> V_64 ,
& V_43 -> V_1372 ,
V_1369 ,
V_1369 ,
true , true ) ;
if ( V_362 )
return V_362 ;
if ( ! V_253 )
return 0 ;
if ( ! F_738 ( F_41 ( V_133 -> V_63 ) , V_43 -> V_64 . V_349 ,
V_43 -> V_64 . V_350 ) ) {
F_219 ( L_264 ,
V_43 -> V_64 . V_349 , V_43 -> V_64 . V_350 ) ;
return - V_288 ;
}
V_292 = F_732 ( V_43 -> V_64 . V_349 ) * 4 ;
if ( V_253 -> V_64 . V_241 < V_292 * V_43 -> V_64 . V_350 ) {
F_161 ( L_265 ) ;
return - V_720 ;
}
if ( V_89 -> V_257 != V_230 ) {
F_161 ( L_266 ) ;
return - V_288 ;
}
if ( F_17 ( F_41 ( V_133 -> V_63 ) ) && V_94 == V_510 &&
V_43 -> V_64 . V_340 && V_43 -> V_64 . V_347 < 0 ) {
F_161 ( L_267 ) ;
return - V_288 ;
}
return 0 ;
}
static void
F_991 ( struct V_333 * V_133 ,
struct V_145 * V_65 )
{
struct V_81 * V_81 = F_48 ( V_65 ) ;
V_81 -> V_1101 = 0 ;
F_736 ( V_65 , NULL ) ;
}
static void
F_992 ( struct V_333 * V_133 ,
const struct V_37 * V_60 ,
const struct V_265 * V_43 )
{
struct V_145 * V_65 = V_60 -> V_64 . V_65 ;
struct V_81 * V_81 = F_48 ( V_65 ) ;
struct V_5 * V_6 = F_41 ( V_133 -> V_63 ) ;
struct V_252 * V_253 = F_189 ( V_43 -> V_64 . V_89 ) ;
T_2 V_1182 ;
if ( ! V_253 )
V_1182 = 0 ;
else if ( ! F_184 ( V_6 ) -> V_1366 )
V_1182 = F_238 ( V_43 ) ;
else
V_1182 = V_253 -> V_1392 -> V_1393 ;
V_81 -> V_1101 = V_1182 ;
F_736 ( V_65 , V_43 ) ;
}
static struct V_337 *
F_993 ( struct V_5 * V_6 , enum V_94 V_94 )
{
struct V_337 * V_1394 = NULL ;
struct V_265 * V_43 = NULL ;
int V_362 ;
V_1394 = F_554 ( sizeof( * V_1394 ) , V_721 ) ;
if ( ! V_1394 ) {
V_362 = - V_720 ;
goto V_783;
}
V_43 = F_984 ( & V_1394 -> V_64 ) ;
if ( ! V_43 ) {
V_362 = - V_720 ;
goto V_783;
}
V_1394 -> V_64 . V_43 = & V_43 -> V_64 ;
V_1394 -> V_1382 = false ;
V_1394 -> V_1383 = 1 ;
V_1394 -> V_94 = V_94 ;
V_1394 -> V_133 = V_94 ;
V_1394 -> V_379 = V_1289 ;
V_1394 -> V_354 = F_994 ( V_94 ) ;
V_1394 -> V_1385 = F_990 ;
V_1394 -> V_420 = F_992 ;
V_1394 -> V_342 = F_991 ;
V_362 = F_987 ( & V_6 -> V_260 , & V_1394 -> V_64 ,
0 , & V_1395 ,
V_1396 ,
F_179 ( V_1396 ) ,
V_1211 ,
L_268 , F_78 ( V_94 ) ) ;
if ( V_362 )
goto V_783;
if ( F_59 ( V_6 ) >= 4 )
F_988 ( & V_1394 -> V_64 ,
V_289 ,
V_289 |
V_370 ) ;
if ( F_59 ( V_6 ) >= 9 )
V_43 -> V_407 = - 1 ;
F_989 ( & V_1394 -> V_64 , & V_1391 ) ;
return V_1394 ;
V_783:
F_236 ( V_43 ) ;
F_236 ( V_1394 ) ;
return F_740 ( V_362 ) ;
}
static void F_730 ( struct V_81 * V_65 ,
struct V_37 * V_60 )
{
struct V_380 * V_381 =
& V_60 -> V_381 ;
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
int V_135 ;
V_65 -> V_382 = V_6 -> V_1227 . V_382 [ V_65 -> V_94 ] ;
if ( ! V_65 -> V_382 )
return;
for ( V_135 = 0 ; V_135 < V_65 -> V_382 ; V_135 ++ ) {
struct V_1397 * V_1398 = & V_381 -> V_383 [ V_135 ] ;
V_1398 -> V_384 = 0 ;
V_1398 -> V_417 = V_1399 ;
}
V_381 -> V_407 = - 1 ;
}
static int F_995 ( struct V_5 * V_6 , enum V_94 V_94 )
{
struct V_81 * V_81 ;
struct V_37 * V_60 = NULL ;
struct V_337 * V_88 = NULL ;
struct V_337 * V_1394 = NULL ;
int V_139 , V_362 ;
V_81 = F_554 ( sizeof( * V_81 ) , V_721 ) ;
if ( ! V_81 )
return - V_720 ;
V_60 = F_554 ( sizeof( * V_60 ) , V_721 ) ;
if ( ! V_60 ) {
V_362 = - V_720 ;
goto V_783;
}
V_81 -> V_90 = V_60 ;
V_81 -> V_64 . V_43 = & V_60 -> V_64 ;
V_60 -> V_64 . V_65 = & V_81 -> V_64 ;
V_88 = F_983 ( V_6 , V_94 ) ;
if ( F_194 ( V_88 ) ) {
V_362 = F_241 ( V_88 ) ;
goto V_783;
}
V_81 -> V_1400 |= F_466 ( V_88 -> V_379 ) ;
F_93 (dev_priv, pipe, sprite) {
struct V_337 * V_133 ;
V_133 = F_996 ( V_6 , V_94 , V_139 ) ;
if ( F_194 ( V_133 ) ) {
V_362 = F_241 ( V_133 ) ;
goto V_783;
}
V_81 -> V_1400 |= F_466 ( V_133 -> V_379 ) ;
}
V_1394 = F_993 ( V_6 , V_94 ) ;
if ( F_194 ( V_1394 ) ) {
V_362 = F_241 ( V_1394 ) ;
goto V_783;
}
V_81 -> V_1400 |= F_466 ( V_1394 -> V_379 ) ;
V_362 = F_997 ( & V_6 -> V_260 , & V_81 -> V_64 ,
& V_88 -> V_64 , & V_1394 -> V_64 ,
& V_1401 ,
L_269 , F_78 ( V_94 ) ) ;
if ( V_362 )
goto V_783;
V_81 -> V_94 = V_94 ;
V_81 -> V_133 = V_88 -> V_133 ;
V_81 -> V_1092 = ~ 0 ;
V_81 -> V_1091 = ~ 0 ;
V_81 -> V_1093 = ~ 0 ;
V_81 -> V_563 . V_564 = true ;
F_730 ( V_81 , V_60 ) ;
F_664 ( V_94 >= F_179 ( V_6 -> V_1402 ) ||
V_6 -> V_1402 [ V_81 -> V_133 ] != NULL ) ;
V_6 -> V_1402 [ V_81 -> V_133 ] = V_81 ;
V_6 -> V_1403 [ V_81 -> V_94 ] = V_81 ;
F_998 ( & V_81 -> V_64 , & V_1404 ) ;
F_999 ( & V_81 -> V_64 ) ;
F_28 ( F_897 ( & V_81 -> V_64 ) != V_81 -> V_94 ) ;
return 0 ;
V_783:
F_236 ( V_60 ) ;
F_236 ( V_81 ) ;
return V_362 ;
}
enum V_94 F_1000 ( struct V_717 * V_718 )
{
struct V_618 * V_512 = V_718 -> V_64 . V_512 ;
struct V_62 * V_63 = V_718 -> V_64 . V_63 ;
F_28 ( ! F_1001 ( & V_63 -> V_428 . V_1113 ) ) ;
if ( ! V_512 || F_28 ( ! V_512 -> V_65 ) )
return V_592 ;
return F_48 ( V_512 -> V_65 ) -> V_94 ;
}
int F_1002 ( struct V_62 * V_63 , void * V_1045 ,
struct V_1405 * V_1406 )
{
struct V_1407 * V_1408 = V_1045 ;
struct V_145 * V_1409 ;
struct V_81 * V_65 ;
V_1409 = F_1003 ( V_63 , V_1408 -> V_1410 ) ;
if ( ! V_1409 )
return - V_1411 ;
V_65 = F_48 ( V_1409 ) ;
V_1408 -> V_94 = V_65 -> V_94 ;
return 0 ;
}
static int F_1004 ( struct V_511 * V_512 )
{
struct V_62 * V_63 = V_512 -> V_64 . V_63 ;
struct V_511 * V_1217 ;
int V_1412 = 0 ;
int V_1413 = 0 ;
F_662 (dev, source_encoder) {
if ( F_843 ( V_512 , V_1217 ) )
V_1412 |= ( 1 << V_1413 ) ;
V_1413 ++ ;
}
return V_1412 ;
}
static bool F_1005 ( struct V_5 * V_6 )
{
if ( ! F_140 ( V_6 ) )
return false ;
if ( ( F_11 ( V_1414 ) & V_1415 ) == 0 )
return false ;
if ( F_24 ( V_6 ) && ( F_11 ( V_635 ) & V_1416 ) )
return false ;
return true ;
}
static bool F_1006 ( struct V_5 * V_6 )
{
if ( F_59 ( V_6 ) >= 9 )
return false ;
if ( F_573 ( V_6 ) || F_482 ( V_6 ) )
return false ;
if ( F_17 ( V_6 ) )
return false ;
if ( F_1007 ( V_6 ) &&
F_11 ( V_1417 ) & V_1418 )
return false ;
if ( F_23 ( V_6 ) && F_11 ( F_1008 ( V_601 ) ) & V_1419 )
return false ;
if ( ! V_6 -> V_802 . V_1420 )
return false ;
return true ;
}
void F_309 ( struct V_5 * V_6 )
{
int V_1421 ;
int V_1422 ;
if ( F_23 ( V_6 ) )
return;
if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
V_1421 = 2 ;
else
V_1421 = 1 ;
for ( V_1422 = 0 ; V_1422 < V_1421 ; V_1422 ++ ) {
T_1 V_15 = F_11 ( F_76 ( V_1422 ) ) ;
V_15 = ( V_15 & ~ V_123 ) | V_124 ;
F_124 ( F_76 ( V_1422 ) , V_15 ) ;
}
}
static void F_1009 ( struct V_5 * V_6 )
{
if ( F_15 ( V_6 ) || F_36 ( V_6 ) )
V_6 -> V_1423 = V_1424 ;
else if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
V_6 -> V_1423 = V_1425 ;
else
V_6 -> V_1423 = V_1426 ;
F_309 ( V_6 ) ;
}
static void F_1010 ( struct V_5 * V_6 )
{
struct V_511 * V_512 ;
bool V_1427 = false ;
F_1009 ( V_6 ) ;
F_1011 ( V_6 ) ;
if ( F_1006 ( V_6 ) )
F_1012 ( V_6 ) ;
if ( F_36 ( V_6 ) ) {
F_1013 ( V_6 , V_601 ) ;
F_1013 ( V_6 , V_198 ) ;
F_1013 ( V_6 , V_200 ) ;
F_1014 ( V_6 ) ;
} else if ( F_23 ( V_6 ) ) {
int V_75 ;
V_75 = F_11 ( F_1008 ( V_601 ) ) & V_1428 ;
if ( V_75 || F_477 ( V_6 ) || F_478 ( V_6 ) )
F_1013 ( V_6 , V_601 ) ;
V_75 = F_11 ( V_1417 ) ;
if ( V_75 & V_1429 )
F_1013 ( V_6 , V_198 ) ;
if ( V_75 & V_1430 )
F_1013 ( V_6 , V_200 ) ;
if ( V_75 & V_1431 )
F_1013 ( V_6 , V_202 ) ;
if ( ( F_477 ( V_6 ) || F_478 ( V_6 ) ) &&
( V_6 -> V_802 . V_1432 [ V_606 ] . V_1433 ||
V_6 -> V_802 . V_1432 [ V_606 ] . V_1434 ||
V_6 -> V_802 . V_1432 [ V_606 ] . V_1435 ) )
F_1013 ( V_6 , V_606 ) ;
} else if ( F_15 ( V_6 ) ) {
int V_75 ;
V_1427 = F_1015 ( V_6 , V_202 ) ;
if ( F_1005 ( V_6 ) )
F_1016 ( V_6 , V_1414 , V_601 ) ;
if ( F_11 ( V_171 ) & V_1436 ) {
V_75 = F_1017 ( V_6 , V_1437 , V_198 ) ;
if ( ! V_75 )
F_1018 ( V_6 , V_171 , V_198 ) ;
if ( ! V_75 && ( F_11 ( V_164 ) & V_1415 ) )
F_1016 ( V_6 , V_164 , V_198 ) ;
}
if ( F_11 ( V_172 ) & V_1436 )
F_1018 ( V_6 , V_172 , V_200 ) ;
if ( ! V_1427 && F_11 ( V_173 ) & V_1436 )
F_1018 ( V_6 , V_173 , V_202 ) ;
if ( F_11 ( V_166 ) & V_1415 )
F_1016 ( V_6 , V_166 , V_200 ) ;
if ( F_11 ( V_168 ) & V_1415 )
F_1016 ( V_6 , V_168 , V_202 ) ;
} else if ( F_16 ( V_6 ) || F_17 ( V_6 ) ) {
bool V_1438 , V_1439 ;
V_1438 = F_1015 ( V_6 , V_198 ) ;
V_1439 = F_1019 ( V_6 , V_198 ) ;
if ( F_11 ( V_1440 ) & V_1415 || V_1439 )
V_1438 &= F_1016 ( V_6 , V_1440 , V_198 ) ;
if ( ( F_11 ( V_1441 ) & V_1436 || V_1439 ) && ! V_1438 )
F_1018 ( V_6 , V_1441 , V_198 ) ;
V_1438 = F_1015 ( V_6 , V_200 ) ;
V_1439 = F_1019 ( V_6 , V_200 ) ;
if ( F_11 ( V_1442 ) & V_1415 || V_1439 )
V_1438 &= F_1016 ( V_6 , V_1442 , V_200 ) ;
if ( ( F_11 ( V_1443 ) & V_1436 || V_1439 ) && ! V_1438 )
F_1018 ( V_6 , V_1443 , V_200 ) ;
if ( F_17 ( V_6 ) ) {
V_1439 = F_1019 ( V_6 , V_202 ) ;
if ( F_11 ( V_1444 ) & V_1415 || V_1439 )
F_1016 ( V_6 , V_1444 , V_202 ) ;
if ( F_11 ( V_1445 ) & V_1436 || V_1439 )
F_1018 ( V_6 , V_1445 , V_202 ) ;
}
F_1014 ( V_6 ) ;
} else if ( ! F_56 ( V_6 ) && ! F_19 ( V_6 ) ) {
bool V_75 = false ;
if ( F_11 ( V_1446 ) & V_1436 ) {
F_161 ( L_270 ) ;
V_75 = F_1017 ( V_6 , V_1446 , V_198 ) ;
if ( ! V_75 && F_18 ( V_6 ) ) {
F_161 ( L_271 ) ;
F_1018 ( V_6 , V_1447 , V_198 ) ;
}
if ( ! V_75 && F_18 ( V_6 ) )
F_1016 ( V_6 , V_1448 , V_198 ) ;
}
if ( F_11 ( V_1446 ) & V_1436 ) {
F_161 ( L_272 ) ;
V_75 = F_1017 ( V_6 , V_1449 , V_200 ) ;
}
if ( ! V_75 && ( F_11 ( V_1449 ) & V_1436 ) ) {
if ( F_18 ( V_6 ) ) {
F_161 ( L_273 ) ;
F_1018 ( V_6 , V_1450 , V_200 ) ;
}
if ( F_18 ( V_6 ) )
F_1016 ( V_6 , V_1451 , V_200 ) ;
}
if ( F_18 ( V_6 ) && ( F_11 ( V_1452 ) & V_1415 ) )
F_1016 ( V_6 , V_1452 , V_202 ) ;
} else if ( F_56 ( V_6 ) )
F_1020 ( V_6 ) ;
if ( F_1021 ( V_6 ) )
F_1022 ( V_6 ) ;
F_1023 ( V_6 ) ;
F_662 (&dev_priv->drm, encoder) {
V_512 -> V_64 . V_1114 = V_512 -> V_1294 ;
V_512 -> V_64 . V_1453 =
F_1004 ( V_512 ) ;
}
F_674 ( V_6 ) ;
F_1024 ( & V_6 -> V_260 ) ;
}
static void F_1025 ( struct V_245 * V_89 )
{
struct V_62 * V_63 = V_89 -> V_63 ;
struct V_267 * V_268 = F_182 ( V_89 ) ;
F_1026 ( V_89 ) ;
F_3 ( & V_63 -> V_256 ) ;
F_28 ( ! V_268 -> V_253 -> V_1454 -- ) ;
F_229 ( V_268 -> V_253 ) ;
F_5 ( & V_63 -> V_256 ) ;
F_236 ( V_268 ) ;
}
static int F_1027 ( struct V_245 * V_89 ,
struct V_1405 * V_1406 ,
unsigned int * V_1455 )
{
struct V_267 * V_268 = F_182 ( V_89 ) ;
struct V_252 * V_253 = V_268 -> V_253 ;
if ( V_253 -> V_1456 . V_558 ) {
F_219 ( L_274 ) ;
return - V_288 ;
}
return F_1028 ( V_1406 , & V_253 -> V_64 , V_1455 ) ;
}
static int F_1029 ( struct V_245 * V_89 ,
struct V_1405 * V_1406 ,
unsigned V_330 , unsigned V_1457 ,
struct V_1458 * V_1459 ,
unsigned V_1460 )
{
struct V_62 * V_63 = V_89 -> V_63 ;
struct V_267 * V_268 = F_182 ( V_89 ) ;
struct V_252 * V_253 = V_268 -> V_253 ;
F_3 ( & V_63 -> V_256 ) ;
if ( V_253 -> V_1461 && V_253 -> V_1462 )
F_1030 ( V_253 , true ) ;
F_1031 ( V_253 , false , V_1463 ) ;
F_5 ( & V_63 -> V_256 ) ;
return 0 ;
}
static
T_1 F_1032 ( struct V_5 * V_6 ,
V_55 V_228 , T_2 V_238 )
{
T_1 V_250 = F_184 ( V_6 ) -> V_250 ;
if ( V_250 >= 9 ) {
int V_229 = F_176 ( V_238 , 0 ) ;
return V_58 ( 8192 * V_229 , 32768 ) ;
} else if ( V_250 >= 5 && ! F_16 ( V_6 ) &&
! F_17 ( V_6 ) ) {
return 32 * 1024 ;
} else if ( V_250 >= 4 ) {
if ( V_228 == V_231 )
return 16 * 1024 ;
else
return 32 * 1024 ;
} else if ( V_250 >= 3 ) {
if ( V_228 == V_231 )
return 8 * 1024 ;
else
return 16 * 1024 ;
} else {
return 8 * 1024 ;
}
}
static int F_228 ( struct V_62 * V_63 ,
struct V_267 * V_268 ,
struct V_322 * V_323 ,
struct V_252 * V_253 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
unsigned int V_328 = F_1033 ( V_253 ) ;
int V_362 ;
T_1 V_1464 , V_1465 ;
struct V_1232 V_1233 ;
F_28 ( ! F_190 ( & V_63 -> V_256 ) ) ;
if ( V_323 -> V_330 & V_331 ) {
if ( V_328 != V_284 &&
V_328 != F_214 ( V_323 -> V_257 [ 0 ] ) ) {
F_219 ( L_275 ) ;
return - V_288 ;
}
} else {
if ( V_328 == V_282 ) {
V_323 -> V_257 [ 0 ] = V_231 ;
} else if ( V_328 == V_283 ) {
F_219 ( L_276 ) ;
return - V_288 ;
}
}
switch ( V_323 -> V_257 [ 0 ] ) {
case V_232 :
case V_233 :
if ( F_59 ( V_6 ) < 9 ) {
F_219 ( L_277 ,
V_323 -> V_257 [ 0 ] ) ;
return - V_288 ;
}
case V_230 :
case V_231 :
break;
default:
F_219 ( L_278 ,
V_323 -> V_257 [ 0 ] ) ;
return - V_288 ;
}
if ( F_184 ( V_6 ) -> V_250 < 4 &&
V_328 != F_214 ( V_323 -> V_257 [ 0 ] ) ) {
F_219 ( L_279 ) ;
return - V_288 ;
}
V_1465 = F_267 ( V_6 ,
V_323 -> V_257 [ 0 ] ,
V_323 -> V_238 ) ;
if ( V_323 -> V_262 [ 0 ] & ( V_1465 - 1 ) ) {
F_219 ( L_280 ,
V_323 -> V_262 [ 0 ] , V_1465 ) ;
return - V_288 ;
}
V_1464 = F_1032 ( V_6 , V_323 -> V_257 [ 0 ] ,
V_323 -> V_238 ) ;
if ( V_323 -> V_262 [ 0 ] > V_1464 ) {
F_219 ( L_281 ,
V_323 -> V_257 [ 0 ] != V_230 ?
L_282 : L_283 ,
V_323 -> V_262 [ 0 ] , V_1464 ) ;
return - V_288 ;
}
if ( V_328 != V_284 &&
V_323 -> V_262 [ 0 ] != F_1034 ( V_253 ) ) {
F_219 ( L_284 ,
V_323 -> V_262 [ 0 ] ,
F_1034 ( V_253 ) ) ;
return - V_288 ;
}
switch ( V_323 -> V_238 ) {
case V_298 :
case V_302 :
case V_304 :
case V_316 :
break;
case V_300 :
if ( F_59 ( V_6 ) > 3 ) {
F_219 ( L_285 ,
F_863 ( V_323 -> V_238 , & V_1233 ) ) ;
return - V_288 ;
}
break;
case V_315 :
if ( ! F_16 ( V_6 ) && ! F_17 ( V_6 ) &&
F_59 ( V_6 ) < 9 ) {
F_219 ( L_285 ,
F_863 ( V_323 -> V_238 , & V_1233 ) ) ;
return - V_288 ;
}
break;
case V_306 :
case V_308 :
case V_310 :
if ( F_59 ( V_6 ) < 4 ) {
F_219 ( L_285 ,
F_863 ( V_323 -> V_238 , & V_1233 ) ) ;
return - V_288 ;
}
break;
case V_1466 :
if ( ! F_16 ( V_6 ) && ! F_17 ( V_6 ) ) {
F_219 ( L_285 ,
F_863 ( V_323 -> V_238 , & V_1233 ) ) ;
return - V_288 ;
}
break;
case V_388 :
case V_393 :
case V_391 :
case V_395 :
if ( F_59 ( V_6 ) < 5 ) {
F_219 ( L_285 ,
F_863 ( V_323 -> V_238 , & V_1233 ) ) ;
return - V_288 ;
}
break;
default:
F_219 ( L_285 ,
F_863 ( V_323 -> V_238 , & V_1233 ) ) ;
return - V_288 ;
}
if ( V_323 -> V_281 [ 0 ] != 0 )
return - V_288 ;
F_1035 ( V_63 , & V_268 -> V_64 , V_323 ) ;
V_268 -> V_253 = V_253 ;
V_362 = F_215 ( V_6 , & V_268 -> V_64 ) ;
if ( V_362 )
return V_362 ;
V_362 = F_1036 ( V_63 , & V_268 -> V_64 , & V_1467 ) ;
if ( V_362 ) {
F_127 ( L_286 , V_362 ) ;
return V_362 ;
}
V_268 -> V_253 -> V_1454 ++ ;
return 0 ;
}
static struct V_245 *
F_1037 ( struct V_62 * V_63 ,
struct V_1405 * V_1468 ,
const struct V_322 * V_1469 )
{
struct V_245 * V_89 ;
struct V_252 * V_253 ;
struct V_322 V_323 = * V_1469 ;
V_253 = F_1038 ( V_1468 , V_323 . V_1470 [ 0 ] ) ;
if ( ! V_253 )
return F_740 ( - V_1411 ) ;
V_89 = F_741 ( V_63 , & V_323 , V_253 ) ;
if ( F_194 ( V_89 ) )
F_229 ( V_253 ) ;
return V_89 ;
}
static void F_1039 ( struct V_421 * V_43 )
{
struct V_569 * V_338 = F_295 ( V_43 ) ;
F_1040 ( V_43 ) ;
F_1041 ( & V_338 -> V_1346 ) ;
F_236 ( V_43 ) ;
}
void F_1042 ( struct V_5 * V_6 )
{
if ( F_184 ( V_6 ) -> V_250 >= 9 ) {
V_6 -> V_434 . V_1292 = F_728 ;
V_6 -> V_434 . V_1471 =
F_685 ;
V_6 -> V_434 . V_1218 =
F_713 ;
V_6 -> V_434 . V_1320 = F_443 ;
V_6 -> V_434 . V_714 = F_455 ;
} else if ( F_23 ( V_6 ) ) {
V_6 -> V_434 . V_1292 = F_728 ;
V_6 -> V_434 . V_1471 =
F_688 ;
V_6 -> V_434 . V_1218 =
F_713 ;
V_6 -> V_434 . V_1320 = F_443 ;
V_6 -> V_434 . V_714 = F_455 ;
} else if ( F_15 ( V_6 ) ) {
V_6 -> V_434 . V_1292 = F_689 ;
V_6 -> V_434 . V_1471 =
F_688 ;
V_6 -> V_434 . V_1218 =
F_678 ;
V_6 -> V_434 . V_1320 = F_431 ;
V_6 -> V_434 . V_714 = F_453 ;
} else if ( F_17 ( V_6 ) ) {
V_6 -> V_434 . V_1292 = F_659 ;
V_6 -> V_434 . V_1471 =
F_656 ;
V_6 -> V_434 . V_1218 = F_652 ;
V_6 -> V_434 . V_1320 = F_526 ;
V_6 -> V_434 . V_714 = F_537 ;
} else if ( F_16 ( V_6 ) ) {
V_6 -> V_434 . V_1292 = F_659 ;
V_6 -> V_434 . V_1471 =
F_656 ;
V_6 -> V_434 . V_1218 = F_653 ;
V_6 -> V_434 . V_1320 = F_526 ;
V_6 -> V_434 . V_714 = F_537 ;
} else if ( F_18 ( V_6 ) ) {
V_6 -> V_434 . V_1292 = F_659 ;
V_6 -> V_434 . V_1471 =
F_656 ;
V_6 -> V_434 . V_1218 = F_649 ;
V_6 -> V_434 . V_1320 = F_535 ;
V_6 -> V_434 . V_714 = F_537 ;
} else if ( F_19 ( V_6 ) ) {
V_6 -> V_434 . V_1292 = F_659 ;
V_6 -> V_434 . V_1471 =
F_656 ;
V_6 -> V_434 . V_1218 = F_650 ;
V_6 -> V_434 . V_1320 = F_535 ;
V_6 -> V_434 . V_714 = F_537 ;
} else if ( ! F_56 ( V_6 ) ) {
V_6 -> V_434 . V_1292 = F_659 ;
V_6 -> V_434 . V_1471 =
F_656 ;
V_6 -> V_434 . V_1218 = F_651 ;
V_6 -> V_434 . V_1320 = F_535 ;
V_6 -> V_434 . V_714 = F_537 ;
} else {
V_6 -> V_434 . V_1292 = F_659 ;
V_6 -> V_434 . V_1471 =
F_656 ;
V_6 -> V_434 . V_1218 = F_648 ;
V_6 -> V_434 . V_1320 = F_535 ;
V_6 -> V_434 . V_714 = F_537 ;
}
if ( F_477 ( V_6 ) || F_478 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_568 ;
else if ( F_36 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_570 ;
else if ( F_265 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_571 ;
else if ( F_264 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_572 ;
else if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_574 ;
else if ( F_24 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_575 ;
else if ( F_638 ( V_6 ) || F_185 ( V_6 ) ||
F_335 ( V_6 ) || F_326 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_576 ;
else if ( F_588 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_590 ;
else if ( F_186 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_591 ;
else if ( F_19 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_579 ;
else if ( F_589 ( V_6 ) || F_18 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_592 ;
else if ( F_565 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_577 ;
else if ( F_639 ( V_6 ) || F_80 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_578 ;
else if ( F_1043 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_581 ;
else if ( F_81 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_582 ;
else if ( F_1044 ( V_6 ) )
V_6 -> V_434 . V_639 =
F_583 ;
else {
F_7 ( ! F_141 ( V_6 ) , L_287 ) ;
V_6 -> V_434 . V_639 =
F_586 ;
}
if ( F_24 ( V_6 ) ) {
V_6 -> V_434 . V_516 = F_327 ;
} else if ( F_335 ( V_6 ) ) {
V_6 -> V_434 . V_516 = F_333 ;
} else if ( F_326 ( V_6 ) ) {
V_6 -> V_434 . V_516 = F_336 ;
} else if ( F_264 ( V_6 ) || F_265 ( V_6 ) ) {
V_6 -> V_434 . V_516 = V_1472 ;
}
if ( F_265 ( V_6 ) ) {
V_6 -> V_434 . V_1339 =
F_710 ;
V_6 -> V_434 . V_1306 =
F_709 ;
} else if ( F_16 ( V_6 ) || F_17 ( V_6 ) ) {
V_6 -> V_434 . V_1339 =
F_525 ;
V_6 -> V_434 . V_1306 =
F_520 ;
} else if ( F_36 ( V_6 ) ) {
V_6 -> V_434 . V_1339 =
F_704 ;
V_6 -> V_434 . V_1306 =
F_521 ;
} else if ( F_477 ( V_6 ) || F_478 ( V_6 ) ) {
V_6 -> V_434 . V_1339 =
F_712 ;
V_6 -> V_434 . V_1306 =
F_711 ;
}
if ( V_6 -> V_1227 . V_250 >= 9 )
V_6 -> V_434 . V_1340 = F_929 ;
else
V_6 -> V_434 . V_1340 = F_928 ;
switch ( F_184 ( V_6 ) -> V_250 ) {
case 2 :
V_6 -> V_434 . V_1201 = F_792 ;
break;
case 3 :
V_6 -> V_434 . V_1201 = F_796 ;
break;
case 4 :
case 5 :
V_6 -> V_434 . V_1201 = F_797 ;
break;
case 6 :
V_6 -> V_434 . V_1201 = F_798 ;
break;
case 7 :
case 8 :
V_6 -> V_434 . V_1201 = F_799 ;
break;
case 9 :
default:
V_6 -> V_434 . V_1201 = F_813 ;
}
}
static void F_1045 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
V_6 -> V_129 |= V_130 ;
F_1046 ( L_288 ) ;
}
static void F_1047 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
V_6 -> V_129 |= V_131 ;
F_1046 ( L_289 ) ;
}
static void F_1048 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
V_6 -> V_129 |= V_804 ;
F_1046 ( L_290 ) ;
}
static void F_1049 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
V_6 -> V_129 |= V_1473 ;
F_1046 ( L_291 ) ;
}
static void F_1050 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
V_6 -> V_129 |= V_1474 ;
F_1046 ( L_292 ) ;
}
static int F_1051 ( const struct V_1475 * V_379 )
{
F_1046 ( L_293 , V_379 -> V_1476 ) ;
return 1 ;
}
static void F_1052 ( struct V_62 * V_63 )
{
struct V_743 * V_1477 = V_63 -> V_744 ;
int V_135 ;
for ( V_135 = 0 ; V_135 < F_179 ( V_1478 ) ; V_135 ++ ) {
struct V_1479 * V_1480 = & V_1478 [ V_135 ] ;
if ( V_1477 -> V_1481 == V_1480 -> V_1481 &&
( V_1477 -> V_1482 == V_1480 -> V_1482 ||
V_1480 -> V_1482 == V_1483 ) &&
( V_1477 -> V_1484 == V_1480 -> V_1484 ||
V_1480 -> V_1484 == V_1483 ) )
V_1480 -> V_1485 ( V_63 ) ;
}
for ( V_135 = 0 ; V_135 < F_179 ( V_1486 ) ; V_135 ++ ) {
if ( F_1053 ( * V_1486 [ V_135 ] . V_1487 ) != 0 )
V_1486 [ V_135 ] . V_1485 ( V_63 ) ;
}
}
static void F_1054 ( struct V_5 * V_6 )
{
struct V_743 * V_744 = V_6 -> V_260 . V_744 ;
T_10 V_1488 ;
T_3 V_1489 = F_1055 ( V_6 ) ;
F_1056 ( V_744 , V_1490 ) ;
F_1057 ( V_1491 , V_1492 ) ;
V_1488 = F_1058 ( V_1493 ) ;
F_1057 ( V_1488 | 1 << 5 , V_1493 ) ;
F_1059 ( V_744 , V_1490 ) ;
F_126 ( 300 ) ;
F_124 ( V_1489 , V_1494 ) ;
F_125 ( V_1489 ) ;
}
void F_310 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
F_483 ( V_6 ) ;
V_6 -> V_1307 = V_6 -> V_637 ;
F_1060 ( V_6 ) ;
}
static void F_1061 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_421 * V_43 ;
struct V_569 * V_338 ;
struct V_145 * V_65 ;
struct V_42 * V_1043 ;
struct V_425 V_426 ;
int V_362 ;
int V_135 ;
if ( ! V_6 -> V_434 . V_1213 )
return;
F_300 ( & V_426 , 0 ) ;
V_462:
V_362 = F_301 ( V_63 , & V_426 ) ;
if ( V_362 == - V_424 ) {
F_302 ( & V_426 ) ;
goto V_462;
} else if ( F_28 ( V_362 ) ) {
goto V_783;
}
V_43 = F_303 ( V_63 , & V_426 ) ;
if ( F_28 ( F_194 ( V_43 ) ) )
goto V_783;
V_338 = F_295 ( V_43 ) ;
V_338 -> V_423 = true ;
V_362 = F_912 ( V_63 , V_43 ) ;
if ( V_362 ) {
F_7 ( true , L_294 ) ;
goto V_1495;
}
F_294 (state, crtc, cstate, i) {
struct V_37 * V_1496 = F_290 ( V_1043 ) ;
V_1496 -> V_563 . V_1214 = true ;
V_6 -> V_434 . V_1213 ( V_338 , V_1496 ) ;
}
V_1495:
F_305 ( V_43 ) ;
V_783:
F_314 ( & V_426 ) ;
F_315 ( & V_426 ) ;
}
int F_1062 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_320 * V_321 = & V_6 -> V_321 ;
enum V_94 V_94 ;
struct V_81 * V_65 ;
F_1063 ( V_63 ) ;
V_63 -> V_428 . V_1497 = 0 ;
V_63 -> V_428 . V_1498 = 0 ;
V_63 -> V_428 . V_1499 = 24 ;
V_63 -> V_428 . V_1500 = 1 ;
V_63 -> V_428 . V_1501 = true ;
V_63 -> V_428 . V_1010 = & V_1502 ;
F_824 ( & V_6 -> V_1332 . V_1191 ,
F_934 ) ;
F_1052 ( V_63 ) ;
F_1064 ( V_6 ) ;
if ( F_184 ( V_6 ) -> V_724 == 0 )
return 0 ;
if ( F_120 ( V_6 ) || F_106 ( V_6 ) ) {
bool V_1503 = ! ! ( F_11 ( V_949 ) &
V_955 ) ;
if ( V_6 -> V_802 . V_803 != V_1503 ) {
F_161 ( L_295 ,
V_1503 ? L_74 : L_75 ,
V_6 -> V_802 . V_803 ? L_74 : L_75 ) ;
V_6 -> V_802 . V_803 = V_1503 ;
}
}
if ( F_56 ( V_6 ) ) {
V_63 -> V_428 . V_358 = 2048 ;
V_63 -> V_428 . V_359 = 2048 ;
} else if ( F_1065 ( V_6 ) ) {
V_63 -> V_428 . V_358 = 4096 ;
V_63 -> V_428 . V_359 = 4096 ;
} else {
V_63 -> V_428 . V_358 = 8192 ;
V_63 -> V_428 . V_359 = 8192 ;
}
if ( F_80 ( V_6 ) || F_81 ( V_6 ) ) {
V_63 -> V_428 . V_1504 = F_80 ( V_6 ) ? 64 : 512 ;
V_63 -> V_428 . V_1505 = 1023 ;
} else if ( F_56 ( V_6 ) ) {
V_63 -> V_428 . V_1504 = V_1506 ;
V_63 -> V_428 . V_1505 = V_1507 ;
} else {
V_63 -> V_428 . V_1504 = V_1508 ;
V_63 -> V_428 . V_1505 = V_1509 ;
}
V_63 -> V_428 . V_1510 = V_321 -> V_1511 ;
F_161 ( L_296 ,
F_184 ( V_6 ) -> V_724 ,
F_184 ( V_6 ) -> V_724 > 1 ? L_297 : L_298 ) ;
F_91 (dev_priv, pipe) {
int V_362 ;
V_362 = F_995 ( V_6 , V_94 ) ;
if ( V_362 ) {
F_1066 ( V_63 ) ;
return V_362 ;
}
}
F_1067 ( V_63 ) ;
F_21 ( V_6 ) ;
F_310 ( V_63 ) ;
if ( V_6 -> V_627 == 0 )
F_476 ( V_6 ) ;
F_1054 ( V_6 ) ;
F_1010 ( V_6 ) ;
F_1068 ( V_63 ) ;
F_292 ( V_63 ) ;
F_1069 ( V_63 ) ;
F_138 (dev, crtc) {
struct V_318 V_319 = {} ;
if ( ! V_65 -> V_87 )
continue;
V_6 -> V_434 . V_1471 ( V_65 ,
& V_319 ) ;
F_233 ( V_65 , & V_319 ) ;
}
F_1061 ( V_63 ) ;
return 0 ;
}
static void F_1070 ( struct V_62 * V_63 )
{
struct V_717 * V_718 ;
struct V_577 * V_1512 = NULL ;
struct V_1107 V_1513 ;
struct V_425 * V_426 = V_63 -> V_428 . V_432 ;
F_849 (dev, connector) {
if ( V_718 -> V_512 -> type == V_615 ) {
V_1512 = & V_718 -> V_64 ;
break;
}
}
if ( ! V_1512 )
return;
if ( F_757 ( V_1512 , NULL , & V_1513 , V_426 ) )
F_764 ( V_1512 , & V_1513 , V_426 ) ;
}
static bool
F_1071 ( struct V_81 * V_65 )
{
struct V_5 * V_6 = F_41 ( V_65 -> V_64 . V_63 ) ;
T_1 V_15 ;
if ( F_184 ( V_6 ) -> V_724 == 1 )
return true ;
V_15 = F_11 ( F_88 ( ! V_65 -> V_133 ) ) ;
if ( ( V_15 & V_134 ) &&
( ! ! ( V_15 & V_137 ) == V_65 -> V_94 ) )
return false ;
return true ;
}
static bool F_1072 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_511 * V_512 ;
F_379 (dev, &crtc->base, encoder)
return true ;
return false ;
}
static struct V_717 * F_1073 ( struct V_511 * V_512 )
{
struct V_62 * V_63 = V_512 -> V_64 . V_63 ;
struct V_717 * V_718 ;
F_1074 (dev, &encoder->base, connector)
return V_718 ;
return NULL ;
}
static bool F_1075 ( struct V_5 * V_6 ,
enum V_93 V_506 )
{
return F_120 ( V_6 ) || F_106 ( V_6 ) ||
( F_1007 ( V_6 ) && V_506 == V_219 ) ;
}
static void F_1076 ( struct V_81 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_64 . V_63 ;
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_93 V_95 = V_65 -> V_90 -> V_95 ;
if ( ! F_444 ( V_95 ) ) {
T_3 V_13 = F_60 ( V_95 ) ;
F_124 ( V_13 ,
F_11 ( V_13 ) & ~ V_1514 ) ;
}
F_1077 ( & V_65 -> V_64 ) ;
if ( V_65 -> V_87 ) {
struct V_337 * V_133 ;
F_440 ( & V_65 -> V_64 ) ;
F_1078 (dev, crtc, plane) {
if ( V_133 -> V_64 . type == V_1390 )
continue;
V_133 -> V_342 ( & V_133 -> V_64 , & V_65 -> V_64 ) ;
}
}
if ( F_59 ( V_6 ) < 4 && ! F_1071 ( V_65 ) ) {
bool V_133 ;
F_161 ( L_299 ,
V_65 -> V_64 . V_64 . V_379 , V_65 -> V_64 . V_12 ) ;
V_133 = V_65 -> V_133 ;
V_65 -> V_64 . V_88 -> V_43 -> V_340 = true ;
V_65 -> V_133 = ! V_133 ;
F_538 ( & V_65 -> V_64 ) ;
V_65 -> V_133 = V_133 ;
}
if ( V_6 -> V_129 & V_130 &&
V_65 -> V_94 == V_113 && ! V_65 -> V_87 ) {
F_1070 ( V_63 ) ;
}
if ( V_65 -> V_87 && ! F_1072 ( V_65 ) )
F_538 ( & V_65 -> V_64 ) ;
if ( V_65 -> V_87 || F_163 ( V_6 ) ) {
V_65 -> V_1515 = true ;
if ( F_1075 ( V_6 , (enum V_93 ) V_65 -> V_94 ) )
V_65 -> V_1516 = true ;
}
}
static void F_1079 ( struct V_511 * V_512 )
{
struct V_717 * V_718 ;
bool V_1517 = V_512 -> V_64 . V_65 &&
F_48 ( V_512 -> V_64 . V_65 ) -> V_87 ;
V_718 = F_1073 ( V_512 ) ;
if ( V_718 && ! V_1517 ) {
F_161 ( L_300 ,
V_512 -> V_64 . V_64 . V_379 ,
V_512 -> V_64 . V_12 ) ;
if ( V_512 -> V_64 . V_65 ) {
struct V_42 * V_60 = V_512 -> V_64 . V_65 -> V_43 ;
F_161 ( L_301 ,
V_512 -> V_64 . V_64 . V_379 ,
V_512 -> V_64 . V_12 ) ;
V_512 -> V_583 ( V_512 , F_290 ( V_60 ) , V_718 -> V_64 . V_43 ) ;
if ( V_512 -> V_584 )
V_512 -> V_584 ( V_512 , F_290 ( V_60 ) , V_718 -> V_64 . V_43 ) ;
}
V_512 -> V_64 . V_65 = NULL ;
V_718 -> V_64 . V_1518 = V_1519 ;
V_718 -> V_64 . V_512 = NULL ;
}
}
void F_1080 ( struct V_5 * V_6 )
{
T_3 V_1489 = F_1055 ( V_6 ) ;
if ( ! ( F_11 ( V_1489 ) & V_1494 ) ) {
F_161 ( L_302 ) ;
F_1054 ( V_6 ) ;
}
}
void F_293 ( struct V_5 * V_6 )
{
if ( ! F_85 ( V_6 , V_1520 ) )
return;
F_1080 ( V_6 ) ;
F_86 ( V_6 , V_1520 ) ;
}
static bool F_1081 ( struct V_337 * V_133 )
{
struct V_5 * V_6 = F_41 ( V_133 -> V_64 . V_63 ) ;
return F_11 ( F_88 ( V_133 -> V_133 ) ) & V_134 ;
}
static void F_1082 ( struct V_81 * V_65 )
{
struct V_333 * V_88 = V_65 -> V_64 . V_88 ;
struct V_265 * V_336 =
F_235 ( V_88 -> V_43 ) ;
V_336 -> V_64 . V_340 = V_65 -> V_87 &&
F_1081 ( F_234 ( V_88 ) ) ;
if ( V_336 -> V_64 . V_340 )
V_65 -> V_64 . V_43 -> V_341 |= 1 << F_239 ( V_88 ) ;
}
static void F_1083 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_94 V_94 ;
struct V_81 * V_65 ;
struct V_511 * V_512 ;
struct V_717 * V_718 ;
int V_135 ;
V_6 -> V_702 = 0 ;
F_138 (dev, crtc) {
struct V_37 * V_60 =
F_290 ( V_65 -> V_64 . V_43 ) ;
F_895 ( & V_60 -> V_64 ) ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_64 . V_65 = & V_65 -> V_64 ;
V_60 -> V_64 . V_87 = V_60 -> V_64 . V_507 =
V_6 -> V_434 . V_1292 ( V_65 , V_60 ) ;
V_65 -> V_64 . V_146 = V_60 -> V_64 . V_507 ;
V_65 -> V_87 = V_60 -> V_64 . V_87 ;
if ( V_60 -> V_64 . V_87 )
V_6 -> V_702 |= 1 << V_65 -> V_94 ;
F_1082 ( V_65 ) ;
F_161 ( L_303 ,
V_65 -> V_64 . V_64 . V_379 , V_65 -> V_64 . V_12 ,
F_860 ( V_60 -> V_64 . V_87 ) ) ;
}
for ( V_135 = 0 ; V_135 < V_6 -> V_947 ; V_135 ++ ) {
struct V_991 * V_992 = & V_6 -> V_1300 [ V_135 ] ;
V_992 -> V_1296 = V_992 -> V_1010 . V_719 ( V_6 , V_992 ,
& V_992 -> V_43 . V_1298 ) ;
V_992 -> V_43 . V_1294 = 0 ;
F_138 (dev, crtc) {
struct V_37 * V_60 =
F_290 ( V_65 -> V_64 . V_43 ) ;
if ( V_60 -> V_64 . V_87 &&
V_60 -> V_206 == V_992 )
V_992 -> V_43 . V_1294 |= 1 << V_65 -> V_94 ;
}
V_992 -> V_1297 = V_992 -> V_43 . V_1294 ;
F_161 ( L_304 ,
V_992 -> V_12 , V_992 -> V_43 . V_1294 , V_992 -> V_1296 ) ;
}
F_662 (dev, encoder) {
V_94 = 0 ;
if ( V_512 -> V_719 ( V_512 , & V_94 ) ) {
struct V_37 * V_60 ;
V_65 = F_53 ( V_6 , V_94 ) ;
V_60 = F_290 ( V_65 -> V_64 . V_43 ) ;
V_512 -> V_64 . V_65 = & V_65 -> V_64 ;
V_60 -> V_1241 |= 1 << V_512 -> type ;
V_512 -> V_1293 ( V_512 , V_60 ) ;
} else {
V_512 -> V_64 . V_65 = NULL ;
}
F_161 ( L_305 ,
V_512 -> V_64 . V_64 . V_379 , V_512 -> V_64 . V_12 ,
F_860 ( V_512 -> V_64 . V_65 ) ,
F_78 ( V_94 ) ) ;
}
F_849 (dev, connector) {
if ( V_718 -> V_719 ( V_718 ) ) {
V_718 -> V_64 . V_1518 = V_1521 ;
V_512 = V_718 -> V_512 ;
V_718 -> V_64 . V_512 = & V_512 -> V_64 ;
if ( V_512 -> V_64 . V_65 &&
V_512 -> V_64 . V_65 -> V_43 -> V_87 ) {
V_512 -> V_64 . V_65 -> V_43 -> V_715 |=
1 << F_1084 ( & V_718 -> V_64 ) ;
V_512 -> V_64 . V_65 -> V_43 -> V_716 |=
1 << F_1085 ( & V_512 -> V_64 ) ;
}
} else {
V_718 -> V_64 . V_1518 = V_1519 ;
V_718 -> V_64 . V_512 = NULL ;
}
F_161 ( L_306 ,
V_718 -> V_64 . V_64 . V_379 , V_718 -> V_64 . V_12 ,
F_860 ( V_718 -> V_64 . V_512 ) ) ;
}
F_138 (dev, crtc) {
struct V_37 * V_60 =
F_290 ( V_65 -> V_64 . V_43 ) ;
int V_700 = 0 ;
V_65 -> V_64 . V_1245 = V_60 -> V_64 . V_91 ;
memset ( & V_65 -> V_64 . V_417 , 0 , sizeof( V_65 -> V_64 . V_417 ) ) ;
if ( V_60 -> V_64 . V_87 ) {
F_643 ( & V_65 -> V_64 . V_417 , V_60 ) ;
F_643 ( & V_60 -> V_64 . V_91 , V_60 ) ;
F_28 ( F_542 ( V_65 -> V_64 . V_43 , & V_65 -> V_64 . V_417 ) ) ;
V_60 -> V_64 . V_417 . V_1310 = V_1522 ;
if ( F_59 ( V_6 ) >= 9 || F_265 ( V_6 ) )
V_700 = F_562 ( V_60 ) ;
else if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
V_700 = V_60 -> V_64 . V_91 . V_92 ;
else
F_28 ( V_6 -> V_434 . V_1306 ) ;
if ( F_265 ( V_6 ) && V_60 -> V_551 )
V_700 = F_220 ( V_700 * 100 , 95 ) ;
F_1086 ( & V_65 -> V_64 , & V_65 -> V_64 . V_1245 ) ;
F_902 ( V_65 ) ;
}
V_6 -> V_699 [ V_65 -> V_94 ] = V_700 ;
F_884 ( V_6 , V_60 ) ;
}
}
static void
F_292 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
enum V_94 V_94 ;
struct V_81 * V_65 ;
struct V_511 * V_512 ;
int V_135 ;
F_1083 ( V_63 ) ;
F_662 (dev, encoder) {
F_1079 ( V_512 ) ;
}
F_91 (dev_priv, pipe) {
V_65 = F_53 ( V_6 , V_94 ) ;
F_1076 ( V_65 ) ;
F_857 ( V_65 , V_65 -> V_90 ,
L_307 ) ;
}
F_848 ( V_63 ) ;
for ( V_135 = 0 ; V_135 < V_6 -> V_947 ; V_135 ++ ) {
struct V_991 * V_992 = & V_6 -> V_1300 [ V_135 ] ;
if ( ! V_992 -> V_1296 || V_992 -> V_1297 )
continue;
F_161 ( L_308 , V_992 -> V_12 ) ;
V_992 -> V_1010 . V_583 ( V_6 , V_992 ) ;
V_992 -> V_1296 = false ;
}
if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
F_1087 ( V_63 ) ;
else if ( F_706 ( V_6 ) )
F_1088 ( V_63 ) ;
else if ( F_15 ( V_6 ) )
F_1089 ( V_63 ) ;
F_138 (dev, crtc) {
unsigned long V_1336 ;
V_1336 = F_470 ( & V_65 -> V_64 , V_65 -> V_90 ) ;
if ( F_28 ( V_1336 ) )
F_473 ( V_6 , V_1336 ) ;
}
F_1090 ( V_6 , false ) ;
F_1091 ( V_6 ) ;
}
void F_1092 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
struct V_421 * V_43 = V_6 -> V_431 ;
struct V_425 V_426 ;
int V_362 ;
V_6 -> V_431 = NULL ;
if ( V_43 )
V_43 -> V_432 = & V_426 ;
F_3 ( & V_63 -> V_428 . V_429 ) ;
F_300 ( & V_426 , 0 ) ;
while ( 1 ) {
V_362 = F_301 ( V_63 , & V_426 ) ;
if ( V_362 != - V_424 )
break;
F_302 ( & V_426 ) ;
}
if ( ! V_362 )
V_362 = F_291 ( V_63 , V_43 ) ;
F_314 ( & V_426 ) ;
F_315 ( & V_426 ) ;
F_5 ( & V_63 -> V_428 . V_429 ) ;
if ( V_362 )
F_127 ( L_58 , V_362 ) ;
if ( V_43 )
F_305 ( V_43 ) ;
}
void F_1093 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
F_1094 ( V_6 ) ;
F_1095 ( V_6 ) ;
}
int F_1096 ( struct V_577 * V_718 )
{
struct V_717 * V_717 = F_854 ( V_718 ) ;
int V_362 ;
V_362 = F_1097 ( V_717 ) ;
if ( V_362 )
goto V_72;
return 0 ;
V_72:
return V_362 ;
}
void F_1098 ( struct V_577 * V_718 )
{
struct V_717 * V_717 = F_854 ( V_718 ) ;
F_1099 ( V_717 ) ;
F_1100 ( V_718 ) ;
}
void F_1101 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_41 ( V_63 ) ;
F_774 ( & V_6 -> V_1332 . V_1191 ) ;
F_28 ( ! F_1102 ( & V_6 -> V_1332 . V_1333 ) ) ;
F_1103 ( V_6 ) ;
F_1104 ( V_6 ) ;
F_1105 ( V_63 ) ;
F_1106 () ;
F_1107 ( V_6 ) ;
F_1108 () ;
F_1066 ( V_63 ) ;
F_1109 ( V_6 ) ;
F_1110 ( V_6 ) ;
F_1111 ( V_6 ) ;
}
void F_1112 ( struct V_717 * V_718 ,
struct V_511 * V_512 )
{
V_718 -> V_512 = V_512 ;
F_1113 ( & V_718 -> V_64 ,
& V_512 -> V_64 ) ;
}
int F_1114 ( struct V_5 * V_6 , bool V_43 )
{
unsigned V_13 = F_59 ( V_6 ) >= 6 ? V_1523 : V_1524 ;
T_4 V_1525 ;
if ( F_580 ( V_6 -> V_1526 , V_13 , & V_1525 ) ) {
F_127 ( L_309 ) ;
return - V_1193 ;
}
if ( ! ! ( V_1525 & V_1527 ) == ! V_43 )
return 0 ;
if ( V_43 )
V_1525 &= ~ V_1527 ;
else
V_1525 |= V_1527 ;
if ( F_1115 ( V_6 -> V_1526 , V_13 , V_1525 ) ) {
F_127 ( L_310 ) ;
return - V_1193 ;
}
return 0 ;
}
struct V_1528 *
F_1116 ( struct V_5 * V_6 )
{
struct V_1528 * error ;
int V_1529 [] = {
V_219 ,
V_1530 ,
V_1531 ,
V_589 ,
} ;
int V_135 ;
if ( F_184 ( V_6 ) -> V_724 == 0 )
return NULL ;
error = F_554 ( sizeof( * error ) , V_1532 ) ;
if ( error == NULL )
return NULL ;
if ( F_264 ( V_6 ) || F_265 ( V_6 ) )
error -> V_1533 = F_11 ( V_1012 ) ;
F_91 (dev_priv, i) {
error -> V_94 [ V_135 ] . V_1534 =
F_1117 ( V_6 ,
F_467 ( V_135 ) ) ;
if ( ! error -> V_94 [ V_135 ] . V_1534 )
continue;
error -> V_1394 [ V_135 ] . V_596 = F_11 ( F_82 ( V_135 ) ) ;
error -> V_1394 [ V_135 ] . V_1535 = F_11 ( F_737 ( V_135 ) ) ;
error -> V_1394 [ V_135 ] . V_64 = F_11 ( F_734 ( V_135 ) ) ;
error -> V_133 [ V_135 ] . V_596 = F_11 ( F_88 ( V_135 ) ) ;
error -> V_133 [ V_135 ] . V_292 = F_11 ( F_257 ( V_135 ) ) ;
if ( F_59 ( V_6 ) <= 3 ) {
error -> V_133 [ V_135 ] . V_241 = F_11 ( F_252 ( V_135 ) ) ;
error -> V_133 [ V_135 ] . V_548 = F_11 ( F_253 ( V_135 ) ) ;
}
if ( F_59 ( V_6 ) <= 7 && ! F_264 ( V_6 ) )
error -> V_133 [ V_135 ] . V_1182 = F_11 ( F_261 ( V_135 ) ) ;
if ( F_59 ( V_6 ) >= 4 ) {
error -> V_133 [ V_135 ] . V_1536 = F_11 ( F_258 ( V_135 ) ) ;
error -> V_133 [ V_135 ] . V_1537 = F_11 ( F_259 ( V_135 ) ) ;
}
error -> V_94 [ V_135 ] . V_1538 = F_11 ( F_321 ( V_135 ) ) ;
if ( F_163 ( V_6 ) )
error -> V_94 [ V_135 ] . V_1539 = F_11 ( F_1118 ( V_135 ) ) ;
}
error -> V_1540 = F_184 ( V_6 ) -> V_724 ;
if ( F_23 ( V_6 ) )
error -> V_1540 ++ ;
for ( V_135 = 0 ; V_135 < error -> V_1540 ; V_135 ++ ) {
enum V_93 V_95 = V_1529 [ V_135 ] ;
error -> V_93 [ V_135 ] . V_1534 =
F_1117 ( V_6 ,
F_84 ( V_95 ) ) ;
if ( ! error -> V_93 [ V_135 ] . V_1534 )
continue;
error -> V_93 [ V_135 ] . V_95 = V_95 ;
error -> V_93 [ V_135 ] . V_1541 = F_11 ( F_60 ( V_95 ) ) ;
error -> V_93 [ V_135 ] . V_890 = F_11 ( F_363 ( V_95 ) ) ;
error -> V_93 [ V_135 ] . V_1542 = F_11 ( F_365 ( V_95 ) ) ;
error -> V_93 [ V_135 ] . V_897 = F_11 ( F_367 ( V_95 ) ) ;
error -> V_93 [ V_135 ] . V_893 = F_11 ( F_369 ( V_95 ) ) ;
error -> V_93 [ V_135 ] . V_1183 = F_11 ( F_371 ( V_95 ) ) ;
error -> V_93 [ V_135 ] . V_1137 = F_11 ( F_373 ( V_95 ) ) ;
}
return error ;
}
void
F_1119 ( struct V_1543 * V_46 ,
struct V_5 * V_6 ,
struct V_1528 * error )
{
int V_135 ;
if ( ! error )
return;
F_1120 ( V_46 , L_311 , F_184 ( V_6 ) -> V_724 ) ;
if ( F_264 ( V_6 ) || F_265 ( V_6 ) )
F_1120 ( V_46 , L_312 ,
error -> V_1533 ) ;
F_91 (dev_priv, i) {
F_1120 ( V_46 , L_313 , V_135 ) ;
F_1120 ( V_46 , L_314 ,
F_66 ( error -> V_94 [ V_135 ] . V_1534 ) ) ;
F_1120 ( V_46 , L_315 , error -> V_94 [ V_135 ] . V_1538 ) ;
F_1120 ( V_46 , L_316 , error -> V_94 [ V_135 ] . V_1539 ) ;
F_1120 ( V_46 , L_317 , V_135 ) ;
F_1120 ( V_46 , L_318 , error -> V_133 [ V_135 ] . V_596 ) ;
F_1120 ( V_46 , L_319 , error -> V_133 [ V_135 ] . V_292 ) ;
if ( F_59 ( V_6 ) <= 3 ) {
F_1120 ( V_46 , L_320 , error -> V_133 [ V_135 ] . V_241 ) ;
F_1120 ( V_46 , L_321 , error -> V_133 [ V_135 ] . V_548 ) ;
}
if ( F_59 ( V_6 ) <= 7 && ! F_264 ( V_6 ) )
F_1120 ( V_46 , L_322 , error -> V_133 [ V_135 ] . V_1182 ) ;
if ( F_59 ( V_6 ) >= 4 ) {
F_1120 ( V_46 , L_323 , error -> V_133 [ V_135 ] . V_1536 ) ;
F_1120 ( V_46 , L_324 , error -> V_133 [ V_135 ] . V_1537 ) ;
}
F_1120 ( V_46 , L_325 , V_135 ) ;
F_1120 ( V_46 , L_318 , error -> V_1394 [ V_135 ] . V_596 ) ;
F_1120 ( V_46 , L_321 , error -> V_1394 [ V_135 ] . V_1535 ) ;
F_1120 ( V_46 , L_326 , error -> V_1394 [ V_135 ] . V_64 ) ;
}
for ( V_135 = 0 ; V_135 < error -> V_1540 ; V_135 ++ ) {
F_1120 ( V_46 , L_327 ,
F_858 ( error -> V_93 [ V_135 ] . V_95 ) ) ;
F_1120 ( V_46 , L_314 ,
F_66 ( error -> V_93 [ V_135 ] . V_1534 ) ) ;
F_1120 ( V_46 , L_328 , error -> V_93 [ V_135 ] . V_1541 ) ;
F_1120 ( V_46 , L_329 , error -> V_93 [ V_135 ] . V_890 ) ;
F_1120 ( V_46 , L_330 , error -> V_93 [ V_135 ] . V_1542 ) ;
F_1120 ( V_46 , L_331 , error -> V_93 [ V_135 ] . V_897 ) ;
F_1120 ( V_46 , L_332 , error -> V_93 [ V_135 ] . V_893 ) ;
F_1120 ( V_46 , L_333 , error -> V_93 [ V_135 ] . V_1183 ) ;
F_1120 ( V_46 , L_334 , error -> V_93 [ V_135 ] . V_1137 ) ;
}
}
